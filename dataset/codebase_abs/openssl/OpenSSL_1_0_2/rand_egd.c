int F_1 ( const char * V_1 , unsigned char * V_2 , int V_3 )
{
return ( - 1 ) ;
}
int F_2 ( const char * V_1 )
{
return ( - 1 ) ;
}
int F_3 ( const char * V_1 , int V_3 )
{
return ( - 1 ) ;
}
int F_1 ( const char * V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 V_6 ;
int V_7 , V_8 , V_9 ;
int V_10 = - 1 ;
int V_11 ;
unsigned char V_12 [ 2 ] , V_13 [ 255 ] , * V_14 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_15 = V_16 ;
if ( strlen ( V_1 ) >= sizeof( V_6 . V_17 ) )
return ( - 1 ) ;
F_4 ( V_6 . V_17 , V_1 , sizeof V_6 . V_17 ) ;
V_7 = F_5 ( struct V_5 , V_17 ) + strlen ( V_1 ) ;
V_10 = F_6 ( V_16 , V_18 , 0 ) ;
if ( V_10 == - 1 )
return ( - 1 ) ;
V_11 = 0 ;
while ( ! V_11 ) {
if ( F_7 ( V_10 , (struct V_19 * ) & V_6 , V_7 ) == 0 )
V_11 = 1 ;
else {
switch ( V_20 ) {
# ifdef F_8
case F_8 :
# endif
# ifdef F_9
case F_9 :
# endif
# ifdef F_10
case F_10 :
# endif
# ifdef F_11
case F_11 :
# endif
break;
# ifdef F_12
case F_12 :
V_11 = 1 ;
break;
# endif
default:
goto V_21;
}
}
}
while ( V_3 > 0 ) {
V_12 [ 0 ] = 1 ;
V_12 [ 1 ] = V_3 < 255 ? V_3 : 255 ;
V_9 = 0 ;
while ( V_9 != 2 ) {
V_8 = F_13 ( V_10 , V_12 + V_9 , 2 - V_9 ) ;
if ( V_8 >= 0 )
V_9 += V_8 ;
else {
switch ( V_20 ) {
# ifdef F_8
case F_8 :
# endif
# ifdef F_9
case F_9 :
# endif
break;
default:
V_4 = - 1 ;
goto V_21;
}
}
}
V_9 = 0 ;
while ( V_9 != 1 ) {
V_8 = F_14 ( V_10 , V_12 , 1 ) ;
if ( V_8 == 0 )
goto V_21;
else if ( V_8 > 0 )
V_9 += V_8 ;
else {
switch ( V_20 ) {
# ifdef F_8
case F_8 :
# endif
# ifdef F_9
case F_9 :
# endif
break;
default:
V_4 = - 1 ;
goto V_21;
}
}
}
if ( V_12 [ 0 ] == 0 )
goto V_21;
if ( V_2 )
V_14 = V_2 + V_4 ;
else
V_14 = V_13 ;
V_9 = 0 ;
while ( V_9 != V_12 [ 0 ] ) {
V_8 = F_14 ( V_10 , V_14 + V_9 , V_12 [ 0 ] - V_9 ) ;
if ( V_8 == 0 )
goto V_21;
else if ( V_8 > 0 )
V_9 += V_8 ;
else {
switch ( V_20 ) {
# ifdef F_8
case F_8 :
# endif
# ifdef F_9
case F_9 :
# endif
break;
default:
V_4 = - 1 ;
goto V_21;
}
}
}
V_4 += V_12 [ 0 ] ;
V_3 -= V_12 [ 0 ] ;
if ( ! V_2 )
F_15 ( V_13 , V_12 [ 0 ] ) ;
}
V_21:
if ( V_10 != - 1 )
F_16 ( V_10 ) ;
return ( V_4 ) ;
}
int F_3 ( const char * V_1 , int V_3 )
{
int V_8 , V_4 = 0 ;
V_8 = F_1 ( V_1 , NULL , V_3 ) ;
if ( V_8 < 1 )
goto V_21;
if ( F_17 () == 1 )
V_4 = V_8 ;
V_21:
return ( V_4 ) ;
}
int F_2 ( const char * V_1 )
{
return ( F_3 ( V_1 , 255 ) ) ;
}
