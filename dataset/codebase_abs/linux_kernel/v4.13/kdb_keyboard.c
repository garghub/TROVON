int F_1 ( void )
{
int V_1 , V_2 ;
static int V_3 ;
static int V_4 ;
static int V_5 ;
T_1 V_6 ;
if ( F_2 ( V_7 ) || F_2 ( V_8 ) ||
( F_3 ( V_9 ) == 0xff && F_3 ( V_10 ) == 0xff ) ) {
V_11 = 0 ;
return - 1 ;
}
V_11 = 1 ;
if ( ( F_3 ( V_9 ) & V_12 ) == 0 )
return - 1 ;
V_1 = F_3 ( V_10 ) ;
V_2 = F_3 ( V_9 ) ;
if ( V_2 & V_13 )
return - 1 ;
if ( ( ( V_1 & 0x7f ) == 0x2a ) || ( ( V_1 & 0x7f ) == 0x36 ) ) {
if ( ( V_1 & 0x80 ) == 0 )
V_4 = 1 ;
else
V_4 = 0 ;
return - 1 ;
}
if ( ( V_1 & 0x7f ) == 0x1d ) {
if ( ( V_1 & 0x80 ) == 0 )
V_5 = 1 ;
else
V_5 = 0 ;
return - 1 ;
}
if ( ( V_1 & 0x80 ) != 0 ) {
if ( V_1 == 0x9c )
V_14 = 0 ;
return - 1 ;
}
V_1 &= 0x7f ;
if ( V_1 == 0x3a ) {
V_3 ^= 1 ;
#ifdef F_4
F_5 ( 0x4 ) ;
#endif
return - 1 ;
}
if ( V_1 == 0x0e ) {
return 8 ;
}
switch ( V_1 ) {
case 0xF :
return 9 ;
case 0x53 :
return 4 ;
case 0x47 :
return 1 ;
case 0x4F :
return 5 ;
case 0x4B :
return 2 ;
case 0x48 :
return 16 ;
case 0x50 :
return 14 ;
case 0x4D :
return 6 ;
}
if ( V_1 == 0xe0 )
return - 1 ;
if ( V_1 == 0x73 )
V_1 = 0x59 ;
else if ( V_1 == 0x7d )
V_1 = 0x7c ;
if ( ! V_3 && ! V_4 && ! V_5 ) {
V_6 = V_15 [ V_1 ] ;
} else if ( ( V_3 || V_4 ) && V_16 [ 1 ] ) {
V_6 = V_16 [ 1 ] [ V_1 ] ;
} else if ( V_5 && V_16 [ 4 ] ) {
V_6 = V_16 [ 4 ] [ V_1 ] ;
} else {
V_6 = 0x0020 ;
F_6 ( L_1 , V_1 ) ;
}
V_6 &= 0x0fff ;
if ( V_6 == '\t' )
V_6 = ' ' ;
switch ( F_7 ( V_6 ) ) {
case V_17 :
case V_18 :
if ( isprint ( V_6 ) )
break;
case V_19 :
if ( V_6 == V_20 )
break;
default:
return - 1 ;
}
if ( V_1 == 0x1c ) {
V_14 = 1 ;
return 13 ;
}
return V_6 & 0xff ;
}
void F_8 ( void )
{
int V_1 , V_2 ;
if ( ! V_14 )
return;
V_14 = 0 ;
while ( 1 ) {
while ( ( F_3 ( V_9 ) & V_12 ) == 0 )
F_9 () ;
V_1 = F_3 ( V_10 ) ;
V_2 = F_3 ( V_9 ) ;
if ( V_2 & V_13 )
continue;
if ( V_1 != 0x9c )
continue;
return;
}
}
