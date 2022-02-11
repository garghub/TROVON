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
F_2 ( V_14 L_1 ) ;
V_4 = V_7 . V_15 ;
if ( V_16 )
goto V_17;
else if ( F_3 ( V_4 ) ) {
V_18 . V_19 = V_20 ;
goto V_17;
} else {
V_18 . V_19 = V_21 ;
V_18 . V_22 = 1 ;
goto V_6;
}
}
if ( V_3 & V_23 ) {
V_4 = V_7 . V_15 ;
V_17:
switch ( V_18 . V_19 ) {
case V_20 :
switch ( V_4 ) {
case 0xF7 :
V_18 . V_19 = V_24 ;
V_18 . V_22 = 0 ;
break;
case 0xF8 :
case 0xF9 :
case 0xFA :
case 0xFB :
V_18 . V_19 = V_25 ;
V_18 . V_22 = 1 ;
V_18 . V_26 [ 0 ] = V_4 ;
break;
case 0xFC :
V_18 . V_19 = CLOCK ;
V_18 . V_22 = 0 ;
break;
case 0xFE :
case 0xFF :
V_18 . V_19 = V_27 ;
V_18 . V_22 = 1 ;
V_18 . V_26 [ 0 ] = V_4 ;
break;
case 0xF1 :
if ( V_16 ) {
++ V_16 ;
V_28 = V_29 ;
break;
}
default:
V_5 = V_4 & V_30 ;
V_4 &= ~ V_30 ;
if ( V_16 ) {
int V_31 , V_32 ;
F_4 ( V_4 , V_33 ) ;
V_28 = V_29 ;
V_31 = V_4 ;
V_32 = F_5 ( V_31 ) - 0xf0 ;
V_31 = F_6 ( V_31 ) ;
F_2 ( V_34 L_2 , V_4 ) ;
if ( V_32 == V_35 || V_32 == V_36 ) {
if ( V_31 < ' ' )
F_2 ( L_3 , V_31 + '@' ) ;
else
F_2 ( L_4 , V_31 ) ;
}
F_2 ( L_5 ) ;
break;
} else if ( F_7 ( V_4 , V_33 ) )
break;
if ( V_37 )
V_37 ( ( unsigned char ) V_4 , ! V_5 ) ;
break;
}
break;
case V_24 :
V_18 . V_26 [ V_18 . V_22 ++ ] = V_4 ;
if ( V_18 . V_22 == 5 ) {
V_18 . V_19 = V_20 ;
}
break;
case V_25 :
V_18 . V_26 [ V_18 . V_22 ++ ] = V_4 ;
if ( V_18 . V_22 == 3 ) {
V_18 . V_19 = V_20 ;
if ( V_38 )
V_38 ( V_18 . V_26 ) ;
}
break;
case V_27 :
V_18 . V_26 [ 1 ] = V_4 ;
V_18 . V_19 = V_20 ;
#ifdef F_8
F_9 ( V_18 . V_26 ) ;
#endif
break;
case CLOCK :
V_18 . V_26 [ V_18 . V_22 ++ ] = V_4 ;
if ( V_18 . V_22 == 6 ) {
V_18 . V_19 = V_20 ;
}
break;
case V_21 :
if ( V_18 . V_22 <= 0 || F_3 ( V_4 ) ) {
V_18 . V_19 = V_20 ;
goto V_17;
}
V_18 . V_22 -- ;
break;
}
}
#if 0
if (acia_stat & ACIA_CTS)
;
#endif
if ( V_3 & ( V_39 | V_40 ) ) {
F_2 ( L_6 ) ;
}
goto V_6;
}
void F_10 ( const char * V_41 , int V_22 )
{
T_2 V_3 ;
if ( ( V_22 < 1 ) || ( V_22 > 7 ) )
F_11 ( L_7 ) ;
while ( V_22 ) {
V_3 = V_7 . V_11 ;
if ( V_3 & V_42 ) {
V_7 . V_15 = * V_41 ++ ;
V_22 -- ;
}
}
}
void F_12 ( void )
{
static const char V_43 [ 2 ] = { 0x80 , 0x01 } ;
F_10 ( V_43 , 2 ) ;
}
void F_13 ( int V_44 )
{
char V_43 [ 2 ] = { 0x07 , V_44 } ;
F_10 ( V_43 , 2 ) ;
}
void F_14 ( void )
{
static const char V_43 [ 1 ] = { 0x08 } ;
F_10 ( V_43 , 1 ) ;
}
void F_15 ( int V_45 , int V_46 )
{
char V_43 [ 5 ] = { 0x09 , V_45 >> 8 , V_45 & 0xFF , V_46 >> 8 , V_46 & 0xFF } ;
F_10 ( V_43 , 5 ) ;
}
void F_16 ( int V_47 , int V_48 )
{
char V_43 [ 3 ] = { 0x0A , V_47 , V_48 } ;
F_10 ( V_43 , 3 ) ;
}
void F_17 ( int V_49 , int V_50 )
{
char V_43 [ 3 ] = { 0x0B , V_49 , V_50 } ;
F_10 ( V_43 , 3 ) ;
}
void F_18 ( int V_49 , int V_50 )
{
char V_43 [ 3 ] = { 0x0C , V_49 , V_50 } ;
F_10 ( V_43 , 3 ) ;
}
void F_19 ( int * V_49 , int * V_50 )
{
static const char V_43 [ 1 ] = { 0x0D } ;
F_10 ( V_43 , 1 ) ;
}
void F_20 ( int V_49 , int V_50 )
{
char V_43 [ 6 ] = { 0x0E , 0x00 , V_49 >> 8 , V_49 & 0xFF , V_50 >> 8 , V_50 & 0xFF } ;
F_10 ( V_43 , 6 ) ;
}
void F_21 ( void )
{
static const char V_43 [ 1 ] = { 0x0F } ;
F_10 ( V_43 , 1 ) ;
}
void F_22 ( void )
{
static const char V_43 [ 1 ] = { 0x10 } ;
F_10 ( V_43 , 1 ) ;
}
void F_23 ( void )
{
static const char V_43 [ 1 ] = { 0x12 } ;
F_10 ( V_43 , 1 ) ;
}
void F_24 ( void )
{
static const char V_43 [ 1 ] = { 0x14 } ;
F_10 ( V_43 , 1 ) ;
}
void F_25 ( void )
{
static const char V_43 [ 1 ] = { 0x15 } ;
F_10 ( V_43 , 1 ) ;
}
void F_26 ( void )
{
static const char V_43 [ 1 ] = { 0x16 } ;
F_10 ( V_43 , 1 ) ;
}
void F_27 ( void )
{
static const char V_43 [ 1 ] = { 0x1A } ;
F_10 ( V_43 , 1 ) ;
}
int F_28 ( void )
{
int error ;
if ( V_51 )
return 0 ;
V_18 . V_19 = V_20 ;
V_18 . V_22 = 0 ;
error = F_29 ( V_52 , F_1 , 0 ,
L_8 , F_1 ) ;
if ( error )
return error ;
F_30 ( V_52 ) ;
do {
V_7 . V_11 = V_53 |
( ( V_54 & V_55 ) ?
V_56 : 0 ) ;
( void ) V_7 . V_11 ;
( void ) V_7 . V_15 ;
V_7 . V_8 = V_53 |
( ( V_54 & V_57 ) ?
V_56 : 0 ) ;
( void ) V_7 . V_8 ;
( void ) V_7 . V_58 ;
V_7 . V_11 = ( V_59 | V_60 | V_61 ) |
( ( V_54 & V_55 ) ?
V_56 : V_62 ) ;
V_7 . V_8 = V_63 | V_60 |
( ( V_54 & V_57 ) ?
V_56 : 0 ) ;
} while ( ( V_64 . V_65 & 0x10 ) == 0 );
V_64 . V_66 &= ~ 0x10 ;
F_31 ( V_52 ) ;
V_16 = 1 ;
F_12 () ;
V_28 = V_29 ;
while ( F_32 ( V_29 , V_28 + V_67 / 4 ) )
F_33 () ;
if ( V_16 == 1 )
F_2 ( V_68 L_9 ) ;
V_16 = 0 ;
F_23 () ;
F_27 () ;
#ifdef F_8
F_34 () ;
#endif
V_51 = 1 ;
return 0 ;
}
