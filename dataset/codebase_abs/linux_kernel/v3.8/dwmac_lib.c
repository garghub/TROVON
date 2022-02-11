void F_1 ( void T_1 * V_1 )
{
F_2 ( 1 , V_1 + V_2 ) ;
}
void F_3 ( void T_1 * V_1 )
{
F_2 ( V_3 , V_1 + V_4 ) ;
}
void F_4 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_4 ) ;
}
void F_5 ( void T_1 * V_1 )
{
T_2 V_5 = F_6 ( V_1 + V_6 ) ;
V_5 |= V_7 ;
F_2 ( V_5 , V_1 + V_6 ) ;
}
void F_7 ( void T_1 * V_1 )
{
T_2 V_5 = F_6 ( V_1 + V_6 ) ;
V_5 &= ~ V_7 ;
F_2 ( V_5 , V_1 + V_6 ) ;
}
void F_8 ( void T_1 * V_1 )
{
T_2 V_5 = F_6 ( V_1 + V_6 ) ;
V_5 |= V_8 ;
F_2 ( V_5 , V_1 + V_6 ) ;
}
void F_9 ( void T_1 * V_1 )
{
T_2 V_5 = F_6 ( V_1 + V_6 ) ;
V_5 &= ~ V_8 ;
F_2 ( V_5 , V_1 + V_6 ) ;
}
static void F_10 ( unsigned int V_9 )
{
unsigned int V_10 ;
V_10 = ( V_9 & V_11 ) >> V_12 ;
switch ( V_10 ) {
case 0 :
F_11 ( L_1 ) ;
break;
case 1 :
F_11 ( L_2 ) ;
break;
case 2 :
F_11 ( L_3 ) ;
break;
case 3 :
F_11 ( L_4
L_5 ) ;
break;
case 6 :
F_11 ( L_6
L_7 ) ;
break;
case 7 :
F_11 ( L_8 ) ;
break;
default:
break;
}
}
static void F_12 ( unsigned int V_9 )
{
unsigned int V_10 ;
V_10 = ( V_9 & V_13 ) >> V_14 ;
switch ( V_10 ) {
case 0 :
F_11 ( L_9 ) ;
break;
case 1 :
F_11 ( L_10 ) ;
break;
case 2 :
F_11 ( L_11 ) ;
break;
case 3 :
F_11 ( L_12 ) ;
break;
case 4 :
F_11 ( L_13 ) ;
break;
case 5 :
F_11 ( L_14 ) ;
break;
case 6 :
F_11 ( L_15
L_16 ) ;
break;
case 7 :
F_11 ( L_17
L_18 ) ;
break;
default:
break;
}
}
int F_13 ( void T_1 * V_1 ,
struct V_15 * V_16 )
{
int V_17 = 0 ;
T_2 V_18 = F_6 ( V_1 + V_19 ) ;
F_14 ( V_20 L_19 , V_21 , V_18 ) ;
#ifdef F_15
F_10 ( V_18 ) ;
F_12 ( V_18 ) ;
#endif
if ( F_16 ( V_18 & V_22 ) ) {
F_14 ( V_20 L_20 ) ;
if ( F_16 ( V_18 & V_23 ) ) {
F_14 ( V_20 L_21 ) ;
V_17 = V_24 ;
V_16 -> V_25 ++ ;
}
if ( F_16 ( V_18 & V_26 ) ) {
F_14 ( V_20 L_22 ) ;
V_16 -> V_27 ++ ;
}
if ( F_16 ( V_18 & V_28 ) ) {
F_14 ( V_20 L_23 ) ;
V_16 -> V_29 ++ ;
}
if ( F_16 ( V_18 & V_30 ) ) {
F_14 ( V_20 L_24 ) ;
V_16 -> V_31 ++ ;
}
if ( F_16 ( V_18 & V_32 ) ) {
F_14 ( V_20 L_25 ) ;
V_16 -> V_33 ++ ;
}
if ( F_16 ( V_18 & V_34 ) ) {
F_14 ( V_20 L_26 ) ;
V_16 -> V_35 ++ ;
}
if ( F_16 ( V_18 & V_36 ) ) {
F_14 ( V_20 L_27 ) ;
V_16 -> V_37 ++ ;
}
if ( F_16 ( V_18 & V_38 ) ) {
F_14 ( V_20 L_28 ) ;
V_16 -> V_39 ++ ;
V_17 = V_40 ;
}
if ( F_16 ( V_18 & V_41 ) ) {
F_14 ( V_20 L_29 ) ;
V_16 -> V_42 ++ ;
V_17 = V_40 ;
}
}
if ( F_17 ( V_18 & V_43 ) ) {
V_16 -> V_44 ++ ;
if ( F_17 ( V_18 & V_45 ) ) {
T_2 V_5 = F_6 ( V_1 + V_4 ) ;
if ( F_17 ( V_5 & V_46 ) ) {
V_16 -> V_47 ++ ;
V_17 |= V_48 ;
}
}
if ( F_17 ( V_18 & V_49 ) ) {
V_16 -> V_50 ++ ;
V_17 |= V_51 ;
}
if ( F_16 ( V_18 & V_52 ) )
V_16 -> V_53 ++ ;
}
if ( F_16 ( V_18 &
( V_54 | V_55 | V_56 ) ) )
F_11 ( L_30 , V_21 , V_18 ) ;
F_2 ( ( V_18 & 0x1ffff ) , V_1 + V_19 ) ;
F_14 ( V_20 L_31 ) ;
return V_17 ;
}
void F_18 ( void T_1 * V_1 )
{
T_2 V_57 = F_6 ( V_1 + V_6 ) ;
F_2 ( ( V_57 | V_58 ) , V_1 + V_6 ) ;
do {} while ( ( F_6 ( V_1 + V_6 ) & V_58 ) );
}
void F_19 ( void T_1 * V_1 , T_3 V_59 [ 6 ] ,
unsigned int V_60 , unsigned int V_61 )
{
unsigned long V_62 ;
V_62 = ( V_59 [ 5 ] << 8 ) | V_59 [ 4 ] ;
F_2 ( V_62 | V_63 , V_1 + V_60 ) ;
V_62 = ( V_59 [ 3 ] << 24 ) | ( V_59 [ 2 ] << 16 ) | ( V_59 [ 1 ] << 8 ) | V_59 [ 0 ] ;
F_2 ( V_62 , V_1 + V_61 ) ;
}
void F_20 ( void T_1 * V_1 , bool V_64 )
{
T_2 V_5 = F_6 ( V_1 + V_65 ) ;
if ( V_64 )
V_5 |= V_66 | V_67 ;
else
V_5 &= ~ ( V_67 | V_66 ) ;
F_2 ( V_5 , V_1 + V_65 ) ;
}
void F_21 ( void T_1 * V_1 , unsigned char * V_59 ,
unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_68 , V_69 ;
V_68 = F_6 ( V_1 + V_60 ) ;
V_69 = F_6 ( V_1 + V_61 ) ;
V_59 [ 0 ] = V_69 & 0xff ;
V_59 [ 1 ] = ( V_69 >> 8 ) & 0xff ;
V_59 [ 2 ] = ( V_69 >> 16 ) & 0xff ;
V_59 [ 3 ] = ( V_69 >> 24 ) & 0xff ;
V_59 [ 4 ] = V_68 & 0xff ;
V_59 [ 5 ] = ( V_68 >> 8 ) & 0xff ;
}
