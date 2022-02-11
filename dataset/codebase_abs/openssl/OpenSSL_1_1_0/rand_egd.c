T_1
#else
# include <openssl/crypto.h>
# include <openssl/e_os2.h>
# include <openssl/rand.h>
# if F_1 ( V_1 ) || F_1 ( V_2 ) || F_1 ( V_3 ) || F_1 ( V_4 ) || F_1 ( V_5 ) || F_1 ( V_6 )
int F_2 ( const char * V_7 , unsigned char * V_8 , int V_9 )
{
return ( - 1 ) ;
}
int F_3 ( const char * V_7 )
{
return ( - 1 ) ;
}
int F_4 ( const char * V_7 , int V_9 )
{
return ( - 1 ) ;
}
int F_2 ( const char * V_7 , unsigned char * V_8 , int V_9 )
{
int V_10 = 0 ;
struct V_11 V_12 ;
int V_13 , V_14 , V_15 ;
int V_16 = - 1 ;
int V_17 ;
unsigned char V_18 [ 2 ] , V_19 [ 255 ] , * V_20 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_21 = V_22 ;
if ( strlen ( V_7 ) >= sizeof( V_12 . V_23 ) )
return ( - 1 ) ;
F_5 ( V_12 . V_23 , V_7 , sizeof V_12 . V_23 ) ;
V_13 = F_6 ( struct V_11 , V_23 ) + strlen ( V_7 ) ;
V_16 = F_7 ( V_22 , V_24 , 0 ) ;
if ( V_16 == - 1 )
return ( - 1 ) ;
V_17 = 0 ;
while ( ! V_17 ) {
if ( F_8 ( V_16 , (struct V_25 * ) & V_12 , V_13 ) == 0 )
V_17 = 1 ;
else {
switch ( V_26 ) {
# ifdef F_9
case F_9 :
# endif
# ifdef F_10
case F_10 :
# endif
# ifdef F_11
case F_11 :
# endif
# ifdef F_12
case F_12 :
# endif
break;
# ifdef F_13
case F_13 :
V_17 = 1 ;
break;
# endif
default:
goto V_27;
}
}
}
while ( V_9 > 0 ) {
V_18 [ 0 ] = 1 ;
V_18 [ 1 ] = V_9 < 255 ? V_9 : 255 ;
V_15 = 0 ;
while ( V_15 != 2 ) {
V_14 = F_14 ( V_16 , V_18 + V_15 , 2 - V_15 ) ;
if ( V_14 >= 0 )
V_15 += V_14 ;
else {
switch ( V_26 ) {
# ifdef F_9
case F_9 :
# endif
# ifdef F_10
case F_10 :
# endif
break;
default:
V_10 = - 1 ;
goto V_27;
}
}
}
V_15 = 0 ;
while ( V_15 != 1 ) {
V_14 = F_15 ( V_16 , V_18 , 1 ) ;
if ( V_14 == 0 )
goto V_27;
else if ( V_14 > 0 )
V_15 += V_14 ;
else {
switch ( V_26 ) {
# ifdef F_9
case F_9 :
# endif
# ifdef F_10
case F_10 :
# endif
break;
default:
V_10 = - 1 ;
goto V_27;
}
}
}
if ( V_18 [ 0 ] == 0 )
goto V_27;
if ( V_8 )
V_20 = V_8 + V_10 ;
else
V_20 = V_19 ;
V_15 = 0 ;
while ( V_15 != V_18 [ 0 ] ) {
V_14 = F_15 ( V_16 , V_20 + V_15 , V_18 [ 0 ] - V_15 ) ;
if ( V_14 == 0 )
goto V_27;
else if ( V_14 > 0 )
V_15 += V_14 ;
else {
switch ( V_26 ) {
# ifdef F_9
case F_9 :
# endif
# ifdef F_10
case F_10 :
# endif
break;
default:
V_10 = - 1 ;
goto V_27;
}
}
}
V_10 += V_18 [ 0 ] ;
V_9 -= V_18 [ 0 ] ;
if ( ! V_8 )
F_16 ( V_19 , V_18 [ 0 ] ) ;
}
V_27:
if ( V_16 != - 1 )
F_17 ( V_16 ) ;
return ( V_10 ) ;
}
int F_4 ( const char * V_7 , int V_9 )
{
int V_14 , V_10 = 0 ;
V_14 = F_2 ( V_7 , NULL , V_9 ) ;
if ( V_14 < 1 )
goto V_27;
if ( F_18 () == 1 )
V_10 = V_14 ;
V_27:
return ( V_10 ) ;
}
int F_3 ( const char * V_7 )
{
return ( F_4 ( V_7 , 255 ) ) ;
}
