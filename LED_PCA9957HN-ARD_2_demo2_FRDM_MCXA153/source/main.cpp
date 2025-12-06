/*
 *  @author Tedd OKANO
 *
 *  Released under the MIT license
 */

#include	"r01lib.h"
#include	"led/PCA9957.h"
#include	"led/LED.h"
#include	<math.h>
#include	<stdlib.h>

#ifndef		M_PI
#define		M_PI	3.14159265358979323
#endif

SPI		spi( ARD_MOSI, ARD_MISO, ARD_SCK, ARD_CS );	//	MOSI, MISO, SCLK, CS
PCA9957	ledd( spi );

constexpr int	n_ch	= ledd.n_channel;


class LEDe : public LED {
public:
	using LED::operator=;

	LEDe( LEDDriver& leddp, int ch ) : LED( leddp, ch ){}

	float operator=( float v )
	{
		devp.pwm( channel, v * v );
		return v;
	}
};


LEDe	leds[]	= {
	LEDe( ledd,  0 ), LEDe( ledd,  1 ), LEDe( ledd,  2 ), LEDe( ledd,  3 ),
	LEDe( ledd,  4 ), LEDe( ledd,  5 ), LEDe( ledd,  6 ), LEDe( ledd,  7 ),
	LEDe( ledd,  8 ), LEDe( ledd,  9 ), LEDe( ledd, 10 ), LEDe( ledd, 11 ),
	LEDe( ledd, 12 ), LEDe( ledd, 13 ), LEDe( ledd, 14 ), LEDe( ledd, 15 ),
	LEDe( ledd, 16 ), LEDe( ledd, 17 ), LEDe( ledd, 18 ), LEDe( ledd, 19 ),
	LEDe( ledd, 20 ), LEDe( ledd, 21 ), LEDe( ledd, 22 ), LEDe( ledd, 23 )
};

void	all( double value );
void	indivisual( int repeats );
void	random( int repeats );
void	random2( int repeats );
void	blink( int repeats );
void	dim( void );
void	green_and_red( int repeats );
void	green_and_red2( int repeats );
void	colors_and_while( int repeats, double (funcp)(double) );
double	triangle_w_space( double ofst );


int main( void )
{
//	printf("***** Hello, PCA9957! *****\r\n");

	ledd.begin( 1.0, PCA9957::ARDUINO_SHIELD );
	
	while ( true )
	{
		random( 300 );
		random2( 100 );
		blink( 10 );
		dim();
		green_and_red2( 2 );
		colors_and_while( 2, triangle_w_space );
		colors_and_while( 2, sin );
	}
}


void indivisual( int repeats )
{
	constexpr int		steps	= 256;
	constexpr double	delay	= 0.005;

	for ( int n = 0; n < repeats * 3; n++ )
	{
		for ( int ch = 0; ch < n_ch; ch++ )
		{
			for ( int i = 0; i < steps; i++ )
			{
				leds[ ch ]	= (double)i / (double)steps;
				wait( delay );
			}
			for ( int i = 0; i < steps; i++ )
			{
				leds[ ch ]	= (double)(steps - i) / (double)steps;
				wait( delay );
			}
		}
	}
}


void random2( int repeats )
{
	double	lum[ n_ch ]	= { 0 };
	
	for ( int n = 0; n < repeats * 3; n++ )
	{
		for ( int i = 0; i < n_ch; i++ )
			lum[ i ]	= lum[ i ] * 0.9;
		
		lum[ rand() % n_ch ]	= 1.0;

		for ( int i = 0; i < n_ch; i++ )
			leds[ i ]	= lum[ i ];

		wait( 0.01 );
	}
	all( 0.0 );
}



void random( int repeats )
{
	int	ch;
	
	for ( int n = 0; n < repeats; n++ )
	{
		ch	= rand() % n_ch;
		leds[ ch ]	= 1.0;
		wait( 0.01 );
		leds[ ch ]	= 0.0;
	}	
}

void blink( int repeats )
{
	for ( int n = 0; n < repeats; n++ )
	{
		all( 1.0 );
		wait( 0.1 );
		all( 0.0 );
		wait( 0.1 );
	}
}

void dim( void )
{
	constexpr double	delay	= 0.01;		

	for ( int i = 256; i >= 0; i-- )
	{
		all( i / 256.0 );
		wait( delay );
	}
}

void green_and_red2( int repeats )
{
	constexpr int		steps	= 256;
	constexpr double	delay	= 0.005;

	for ( int i = 0; i < steps; i++ )
	{
		leds[  7 ]	= leds[ 10 ]	= (double)i / (double)steps;
		wait( delay );
	}
	
	for ( int n = 0; n < repeats; n++ )
	{
		for ( int i = 0; i < steps; i++ )
		{
			leds[  0 ]	= leds[  3 ]	= (double)i / (double)steps;
			leds[  7 ]	= leds[ 10 ]	= (double)(steps - i) / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  0 ]	= leds[  3 ]	= (double)(steps - i) / (double)steps;
			leds[  6 ]	= leds[  9 ]	= (double)i / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  1 ]	= leds[  4 ]	= (double)i / (double)steps;
			leds[  6 ]	= leds[  9 ]	= (double)(steps - i) / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  1 ]	= leds[  4 ]	= (double)(steps - i) / (double)steps;
			leds[  7 ]	= leds[ 10 ]	= (double)i / (double)steps;
			wait( delay );
		}
	}

	for ( int i = 0; i < steps; i++ )
	{
		leds[  7 ]	= leds[ 10 ]	= (double)(steps - i) / (double)steps;
		wait( delay );
	}
}


void green_and_red( int repeats )
{
	constexpr int		steps	= 256;
	constexpr double	delay	= 0.005;
	
	for ( int n = 0; n < repeats; n++ )
	{
		for ( int i = 0; i < steps; i++ )
		{
			leds[  0 ]	= leds[  3 ]	= (double)i / (double)steps;
			leds[  7 ]	= leds[ 10 ]	= (double)i / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  0 ]	= leds[  3 ]	= (double)(steps - i) / (double)steps;
			leds[  7 ]	= leds[ 10 ]	= (double)(steps - i) / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  1 ]	= leds[  4 ]	= (double)i / (double)steps;
			leds[  6 ]	= leds[  9 ]	= (double)i / (double)steps;
			wait( delay );
		}
		for ( int i = 0; i < steps; i++ )
		{
			leds[  1 ]	= leds[  4 ]	= (double)(steps - i) / (double)steps;
			leds[  6 ]	= leds[  9 ]	= (double)(steps - i) / (double)steps;
			wait( delay );
		}
	}
}

void colors_and_while( int repeats, double (funcp)(double) )
{
	constexpr double	cycle	= 100;
	double				s[ 3 ], white = 0, v, cycle_pi;
	int					col[ 12 ]	= { 0, 1, 2, 1, 2, 0, 2, 0, 1, 2, 1, 0 };
	
	cycle_pi	= M_PI / cycle;

	int count	= 0;

	for ( int n = 0; n < repeats * 3; n++ )
	{
		if ( !(count++ % 3) )
			white	= 1.0;

		for ( int i = 0; i < cycle; i++ )
		{
			for ( int phase = 0; phase < 3; phase++ )
				s[ phase ]	= sin( (i + phase * cycle / 3.00) * cycle_pi );
			
			for ( int i = 0; i < 12; i++ )
			{
				v	= s[ col[ i ] ];
				leds[ i ]	= v * v;
			}
			
			for ( int i = 12; i < 24; i++ )
				leds[ i ]	= white;
			
			white	*= 0.9;

			wait( 1.0 / cycle );
		}
	}
	all( 0.0 );
}


void all( double value )
{
	for ( int i = 0; i < n_ch; i++ )
		leds[ i ]	= value;
}

double triangle_w_space( double ofst )
{
	constexpr int	steps		= 256;
	constexpr int	total_steps	= steps* 3;
	int				idx;
	int				val;
	
	idx	 = (ofst / M_PI) * total_steps;
	idx	%= total_steps;
	
	switch ( (idx / steps) % 3 )
	{
		case 0:
			val	= idx;
			break;
		case 1:
			val	= steps - idx % steps;
			break;
		default:
			val	= 0;
			break;
	}
	
	return (double)val / (double)steps;
}
