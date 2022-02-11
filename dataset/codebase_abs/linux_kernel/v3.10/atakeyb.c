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
F_4 ( & V_24 ) ;
V_17:
switch ( V_18 . V_19 ) {
case V_20 :
switch ( V_4 ) {
case 0xF7 :
V_18 . V_19 = V_25 ;
V_18 . V_22 = 0 ;
break;
case 0xF8 :
case 0xF9 :
case 0xFA :
case 0xFB :
V_18 . V_19 = V_26 ;
V_18 . V_22 = 1 ;
V_18 . V_27 [ 0 ] = V_4 ;
break;
case 0xFC :
V_18 . V_19 = CLOCK ;
V_18 . V_22 = 0 ;
break;
case 0xFE :
case 0xFF :
V_18 . V_19 = V_28 ;
V_18 . V_22 = 1 ;
V_18 . V_27 [ 0 ] = V_4 ;
break;
case 0xF1 :
if ( V_16 ) {
++ V_16 ;
V_29 = V_30 ;
break;
}
default:
V_5 = V_4 & V_31 ;
V_4 &= ~ V_31 ;
if ( V_16 ) {
int V_32 , V_33 ;
F_5 ( V_4 , V_34 ) ;
V_29 = V_30 ;
V_32 = V_4 ;
V_33 = F_6 ( V_32 ) - 0xf0 ;
V_32 = F_7 ( V_32 ) ;
F_2 ( V_35 L_2 , V_4 ) ;
if ( V_33 == V_36 || V_33 == V_37 ) {
if ( V_32 < ' ' )
F_2 ( L_3 , V_32 + '@' ) ;
else
F_2 ( L_4 , V_32 ) ;
}
F_2 ( L_5 ) ;
break;
} else if ( F_8 ( V_4 , V_34 ) )
break;
if ( V_38 )
V_38 ( ( unsigned char ) V_4 , ! V_5 ) ;
break;
}
break;
case V_25 :
V_18 . V_27 [ V_18 . V_22 ++ ] = V_4 ;
if ( V_18 . V_22 == 5 ) {
V_18 . V_19 = V_20 ;
}
break;
case V_26 :
V_18 . V_27 [ V_18 . V_22 ++ ] = V_4 ;
if ( V_18 . V_22 == 3 ) {
V_18 . V_19 = V_20 ;
if ( V_39 )
V_39 ( V_18 . V_27 ) ;
}
break;
case V_28 :
V_18 . V_27 [ 1 ] = V_4 ;
V_18 . V_19 = V_20 ;
#ifdef F_9
F_10 ( V_18 . V_27 ) ;
#endif
break;
case CLOCK :
V_18 . V_27 [ V_18 . V_22 ++ ] = V_4 ;
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
if ( V_3 & ( V_40 | V_41 ) ) {
F_2 ( L_6 ) ;
}
goto V_6;
}
void F_11 ( const char * V_42 , int V_22 )
{
T_2 V_3 ;
if ( ( V_22 < 1 ) || ( V_22 > 7 ) )
F_12 ( L_7 ) ;
while ( V_22 ) {
V_3 = V_7 . V_11 ;
if ( V_3 & V_43 ) {
V_7 . V_15 = * V_42 ++ ;
V_22 -- ;
}
}
}
void F_13 ( void )
{
static const char V_44 [ 2 ] = { 0x80 , 0x01 } ;
F_11 ( V_44 , 2 ) ;
}
void F_14 ( int V_45 )
{
char V_44 [ 2 ] = { 0x07 , V_45 } ;
F_11 ( V_44 , 2 ) ;
}
void F_15 ( void )
{
static const char V_44 [ 1 ] = { 0x08 } ;
F_11 ( V_44 , 1 ) ;
}
void F_16 ( int V_46 , int V_47 )
{
char V_44 [ 5 ] = { 0x09 , V_46 >> 8 , V_46 & 0xFF , V_47 >> 8 , V_47 & 0xFF } ;
F_11 ( V_44 , 5 ) ;
}
void F_17 ( int V_48 , int V_49 )
{
char V_44 [ 3 ] = { 0x0A , V_48 , V_49 } ;
F_11 ( V_44 , 3 ) ;
}
void F_18 ( int V_50 , int V_51 )
{
char V_44 [ 3 ] = { 0x0B , V_50 , V_51 } ;
F_11 ( V_44 , 3 ) ;
}
void F_19 ( int V_50 , int V_51 )
{
char V_44 [ 3 ] = { 0x0C , V_50 , V_51 } ;
F_11 ( V_44 , 3 ) ;
}
void F_20 ( int * V_50 , int * V_51 )
{
static const char V_44 [ 1 ] = { 0x0D } ;
F_11 ( V_44 , 1 ) ;
}
void F_21 ( int V_50 , int V_51 )
{
char V_44 [ 6 ] = { 0x0E , 0x00 , V_50 >> 8 , V_50 & 0xFF , V_51 >> 8 , V_51 & 0xFF } ;
F_11 ( V_44 , 6 ) ;
}
void F_22 ( void )
{
static const char V_44 [ 1 ] = { 0x0F } ;
F_11 ( V_44 , 1 ) ;
}
void F_23 ( void )
{
static const char V_44 [ 1 ] = { 0x10 } ;
F_11 ( V_44 , 1 ) ;
}
void F_24 ( void )
{
static const char V_44 [ 1 ] = { 0x11 } ;
F_11 ( V_44 , 1 ) ;
}
void F_25 ( void )
{
static const char V_44 [ 1 ] = { 0x12 } ;
F_11 ( V_44 , 1 ) ;
}
void F_26 ( void )
{
static const char V_44 [ 1 ] = { 0x13 } ;
F_11 ( V_44 , 1 ) ;
}
void F_27 ( void )
{
static const char V_44 [ 1 ] = { 0x14 } ;
F_11 ( V_44 , 1 ) ;
}
void F_28 ( void )
{
static const char V_44 [ 1 ] = { 0x15 } ;
F_11 ( V_44 , 1 ) ;
}
void F_29 ( void )
{
static const char V_44 [ 1 ] = { 0x16 } ;
F_11 ( V_44 , 1 ) ;
}
void F_30 ( void )
{
static const char V_44 [ 1 ] = { 0x1A } ;
F_11 ( V_44 , 1 ) ;
}
void F_31 ( int V_52 , int V_53 , int V_54 , int V_55 , int V_56 , int V_57 )
{
char V_44 [ 7 ] = { 0x1B , V_52 , V_53 , V_54 , V_55 , V_56 , V_57 } ;
F_11 ( V_44 , 7 ) ;
}
void F_32 ( int * V_52 , int * V_53 , int * V_54 , int * V_55 , int * V_56 , int V_57 )
{
static const char V_44 [ 1 ] = { 0x1C } ;
F_11 ( V_44 , 1 ) ;
}
void F_33 ( int V_58 , int V_59 , char * V_60 )
{
F_12 ( L_8 ) ;
}
void F_34 ( int V_58 , char V_60 [ 6 ] )
{
char V_44 [ 3 ] = { 0x21 , V_58 >> 8 , V_58 & 0xFF } ;
F_11 ( V_44 , 3 ) ;
}
void F_35 ( int V_58 )
{
char V_44 [ 3 ] = { 0x22 , V_58 >> 8 , V_58 & 0xFF } ;
F_11 ( V_44 , 3 ) ;
}
void F_36 ( unsigned int V_61 )
{
char V_44 [ 6 ] = { 32 , 0 , 4 , 1 , 254 + ( ( V_61 & 4 ) != 0 ) , 0 } ;
F_11 ( V_44 , 6 ) ;
}
int F_37 ( void )
{
int error ;
if ( V_62 )
return 0 ;
V_18 . V_19 = V_20 ;
V_18 . V_22 = 0 ;
error = F_38 ( V_63 , F_1 ,
V_64 , L_9 ,
F_1 ) ;
if ( error )
return error ;
F_39 ( V_63 ) ;
do {
V_7 . V_11 = V_65 |
( ( V_66 & V_67 ) ?
V_68 : 0 ) ;
( void ) V_7 . V_11 ;
( void ) V_7 . V_15 ;
V_7 . V_8 = V_65 |
( ( V_66 & V_69 ) ?
V_68 : 0 ) ;
( void ) V_7 . V_8 ;
( void ) V_7 . V_70 ;
V_7 . V_11 = ( V_71 | V_72 | V_73 ) |
( ( V_66 & V_67 ) ?
V_68 : V_74 ) ;
V_7 . V_8 = V_75 | V_72 |
( ( V_66 & V_69 ) ?
V_68 : 0 ) ;
} while ( ( V_76 . V_77 & 0x10 ) == 0 );
V_76 . V_78 &= ~ 0x10 ;
F_40 ( V_63 ) ;
V_16 = 1 ;
F_13 () ;
V_29 = V_30 ;
while ( F_41 ( V_30 , V_29 + V_79 / 4 ) )
F_42 () ;
if ( V_16 == 1 )
F_2 ( V_80 L_10 ) ;
V_16 = 0 ;
F_25 () ;
F_30 () ;
#ifdef F_9
F_43 () ;
#endif
V_62 = 1 ;
return 0 ;
}
