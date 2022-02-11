static T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 ;
int V_4 ;
int V_5 ;
V_6:
if ( V_7 . V_8 & V_9 )
if ( V_10 )
V_10 () ;
V_3 = V_7 . V_11 ;
if ( ! ( ( V_3 | V_7 . V_8 ) & V_9 ) )
return V_12 ;
if ( V_3 & V_13 ) {
F_2 ( L_1 ) ;
V_4 = V_7 . V_14 ;
if ( V_15 )
goto V_16;
else if ( F_3 ( V_4 ) ) {
V_17 . V_18 = V_19 ;
goto V_16;
} else {
V_17 . V_18 = V_20 ;
V_17 . V_21 = 1 ;
goto V_6;
}
}
if ( V_3 & V_22 ) {
V_4 = V_7 . V_14 ;
V_16:
switch ( V_17 . V_18 ) {
case V_19 :
switch ( V_4 ) {
case 0xF7 :
V_17 . V_18 = V_23 ;
V_17 . V_21 = 0 ;
break;
case 0xF8 :
case 0xF9 :
case 0xFA :
case 0xFB :
V_17 . V_18 = V_24 ;
V_17 . V_21 = 1 ;
V_17 . V_25 [ 0 ] = V_4 ;
break;
case 0xFC :
V_17 . V_18 = CLOCK ;
V_17 . V_21 = 0 ;
break;
case 0xFE :
case 0xFF :
V_17 . V_18 = V_26 ;
V_17 . V_21 = 1 ;
V_17 . V_25 [ 0 ] = V_4 ;
break;
case 0xF1 :
if ( V_15 ) {
++ V_15 ;
V_27 = V_28 ;
break;
}
default:
V_5 = V_4 & V_29 ;
V_4 &= ~ V_29 ;
if ( V_15 ) {
int V_30 , V_31 ;
F_4 ( V_4 , V_32 ) ;
V_27 = V_28 ;
V_30 = V_4 ;
V_31 = F_5 ( V_30 ) - 0xf0 ;
V_30 = F_6 ( V_30 ) ;
F_7 ( L_2 , V_4 ) ;
if ( V_31 == V_33 || V_31 == V_34 ) {
if ( V_30 < ' ' )
F_8 ( L_3 , V_30 + '@' ) ;
else
F_8 ( L_4 , V_30 ) ;
}
F_8 ( L_5 ) ;
break;
} else if ( F_9 ( V_4 , V_32 ) )
break;
if ( V_35 )
V_35 ( ( unsigned char ) V_4 , ! V_5 ) ;
break;
}
break;
case V_23 :
V_17 . V_25 [ V_17 . V_21 ++ ] = V_4 ;
if ( V_17 . V_21 == 5 ) {
V_17 . V_18 = V_19 ;
}
break;
case V_24 :
V_17 . V_25 [ V_17 . V_21 ++ ] = V_4 ;
if ( V_17 . V_21 == 3 ) {
V_17 . V_18 = V_19 ;
if ( V_36 )
V_36 ( V_17 . V_25 ) ;
}
break;
case V_26 :
V_17 . V_25 [ 1 ] = V_4 ;
V_17 . V_18 = V_19 ;
#ifdef F_10
F_11 ( V_17 . V_25 ) ;
#endif
break;
case CLOCK :
V_17 . V_25 [ V_17 . V_21 ++ ] = V_4 ;
if ( V_17 . V_21 == 6 ) {
V_17 . V_18 = V_19 ;
}
break;
case V_20 :
if ( V_17 . V_21 <= 0 || F_3 ( V_4 ) ) {
V_17 . V_18 = V_19 ;
goto V_16;
}
V_17 . V_21 -- ;
break;
}
}
#if 0
if (acia_stat & ACIA_CTS)
;
#endif
if ( V_3 & ( V_37 | V_38 ) ) {
F_12 ( L_6 ) ;
}
goto V_6;
}
void F_13 ( const char * V_39 , int V_21 )
{
T_2 V_3 ;
if ( ( V_21 < 1 ) || ( V_21 > 7 ) )
F_14 ( L_7 ) ;
while ( V_21 ) {
V_3 = V_7 . V_11 ;
if ( V_3 & V_40 ) {
V_7 . V_14 = * V_39 ++ ;
V_21 -- ;
}
}
}
void F_15 ( void )
{
static const char V_41 [ 2 ] = { 0x80 , 0x01 } ;
F_13 ( V_41 , 2 ) ;
}
void F_16 ( int V_42 )
{
char V_41 [ 2 ] = { 0x07 , V_42 } ;
F_13 ( V_41 , 2 ) ;
}
void F_17 ( void )
{
static const char V_41 [ 1 ] = { 0x08 } ;
F_13 ( V_41 , 1 ) ;
}
void F_18 ( int V_43 , int V_44 )
{
char V_41 [ 5 ] = { 0x09 , V_43 >> 8 , V_43 & 0xFF , V_44 >> 8 , V_44 & 0xFF } ;
F_13 ( V_41 , 5 ) ;
}
void F_19 ( int V_45 , int V_46 )
{
char V_41 [ 3 ] = { 0x0A , V_45 , V_46 } ;
F_13 ( V_41 , 3 ) ;
}
void F_20 ( int V_47 , int V_48 )
{
char V_41 [ 3 ] = { 0x0B , V_47 , V_48 } ;
F_13 ( V_41 , 3 ) ;
}
void F_21 ( int V_47 , int V_48 )
{
char V_41 [ 3 ] = { 0x0C , V_47 , V_48 } ;
F_13 ( V_41 , 3 ) ;
}
void F_22 ( int * V_47 , int * V_48 )
{
static const char V_41 [ 1 ] = { 0x0D } ;
F_13 ( V_41 , 1 ) ;
}
void F_23 ( int V_47 , int V_48 )
{
char V_41 [ 6 ] = { 0x0E , 0x00 , V_47 >> 8 , V_47 & 0xFF , V_48 >> 8 , V_48 & 0xFF } ;
F_13 ( V_41 , 6 ) ;
}
void F_24 ( void )
{
static const char V_41 [ 1 ] = { 0x0F } ;
F_13 ( V_41 , 1 ) ;
}
void F_25 ( void )
{
static const char V_41 [ 1 ] = { 0x10 } ;
F_13 ( V_41 , 1 ) ;
}
void F_26 ( void )
{
static const char V_41 [ 1 ] = { 0x12 } ;
F_13 ( V_41 , 1 ) ;
}
void F_27 ( void )
{
static const char V_41 [ 1 ] = { 0x14 } ;
F_13 ( V_41 , 1 ) ;
}
void F_28 ( void )
{
static const char V_41 [ 1 ] = { 0x15 } ;
F_13 ( V_41 , 1 ) ;
}
void F_29 ( void )
{
static const char V_41 [ 1 ] = { 0x16 } ;
F_13 ( V_41 , 1 ) ;
}
void F_30 ( void )
{
static const char V_41 [ 1 ] = { 0x1A } ;
F_13 ( V_41 , 1 ) ;
}
int F_31 ( void )
{
int error ;
if ( V_49 )
return 0 ;
V_17 . V_18 = V_19 ;
V_17 . V_21 = 0 ;
error = F_32 ( V_50 , F_1 , 0 ,
L_8 , F_1 ) ;
if ( error )
return error ;
F_33 ( V_50 ) ;
do {
V_7 . V_11 = V_51 |
( ( V_52 & V_53 ) ?
V_54 : 0 ) ;
( void ) V_7 . V_11 ;
( void ) V_7 . V_14 ;
V_7 . V_8 = V_51 |
( ( V_52 & V_55 ) ?
V_54 : 0 ) ;
( void ) V_7 . V_8 ;
( void ) V_7 . V_56 ;
V_7 . V_11 = ( V_57 | V_58 | V_59 ) |
( ( V_52 & V_53 ) ?
V_54 : V_60 ) ;
V_7 . V_8 = V_61 | V_58 |
( ( V_52 & V_55 ) ?
V_54 : 0 ) ;
} while ( ( V_62 . V_63 & 0x10 ) == 0 );
V_62 . V_64 &= ~ 0x10 ;
F_34 ( V_50 ) ;
V_15 = 1 ;
F_15 () ;
V_27 = V_28 ;
while ( F_35 ( V_28 , V_27 + V_65 / 4 ) )
F_36 () ;
if ( V_15 == 1 )
F_12 ( L_9 ) ;
V_15 = 0 ;
F_26 () ;
F_30 () ;
#ifdef F_10
F_37 () ;
#endif
V_49 = 1 ;
return 0 ;
}
