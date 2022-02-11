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
#ifdef F_14
F_11 ( L_19 , V_20 , V_18 ) ;
F_10 ( V_18 ) ;
F_12 ( V_18 ) ;
#endif
if ( F_15 ( V_18 & V_21 ) ) {
if ( F_15 ( V_18 & V_22 ) ) {
V_17 = V_23 ;
V_16 -> V_24 ++ ;
}
if ( F_15 ( V_18 & V_25 ) )
V_16 -> V_26 ++ ;
if ( F_15 ( V_18 & V_27 ) )
V_16 -> V_28 ++ ;
if ( F_15 ( V_18 & V_29 ) )
V_16 -> V_30 ++ ;
if ( F_15 ( V_18 & V_31 ) )
V_16 -> V_32 ++ ;
if ( F_15 ( V_18 & V_33 ) )
V_16 -> V_34 ++ ;
if ( F_15 ( V_18 & V_35 ) )
V_16 -> V_36 ++ ;
if ( F_15 ( V_18 & V_37 ) ) {
V_16 -> V_38 ++ ;
V_17 = V_39 ;
}
if ( F_15 ( V_18 & V_40 ) ) {
V_16 -> V_41 ++ ;
V_17 = V_39 ;
}
}
if ( F_16 ( V_18 & V_42 ) ) {
V_16 -> V_43 ++ ;
if ( F_16 ( V_18 & V_44 ) ) {
T_2 V_5 = F_6 ( V_1 + V_4 ) ;
if ( F_16 ( V_5 & V_45 ) ) {
V_16 -> V_46 ++ ;
V_17 |= V_47 ;
}
}
if ( F_16 ( V_18 & V_48 ) ) {
V_16 -> V_49 ++ ;
V_17 |= V_50 ;
}
if ( F_15 ( V_18 & V_51 ) )
V_16 -> V_52 ++ ;
}
if ( F_15 ( V_18 &
( V_53 | V_54 | V_55 ) ) )
F_17 ( L_20 , V_20 , V_18 ) ;
F_2 ( ( V_18 & 0x1ffff ) , V_1 + V_19 ) ;
return V_17 ;
}
void F_18 ( void T_1 * V_1 )
{
T_2 V_56 = F_6 ( V_1 + V_6 ) ;
F_2 ( ( V_56 | V_57 ) , V_1 + V_6 ) ;
do {} while ( ( F_6 ( V_1 + V_6 ) & V_57 ) );
}
void F_19 ( void T_1 * V_1 , T_3 V_58 [ 6 ] ,
unsigned int V_59 , unsigned int V_60 )
{
unsigned long V_61 ;
V_61 = ( V_58 [ 5 ] << 8 ) | V_58 [ 4 ] ;
F_2 ( V_61 | V_62 , V_1 + V_59 ) ;
V_61 = ( V_58 [ 3 ] << 24 ) | ( V_58 [ 2 ] << 16 ) | ( V_58 [ 1 ] << 8 ) | V_58 [ 0 ] ;
F_2 ( V_61 , V_1 + V_60 ) ;
}
void F_20 ( void T_1 * V_1 , bool V_63 )
{
T_2 V_5 = F_6 ( V_1 + V_64 ) ;
if ( V_63 )
V_5 |= V_65 | V_66 ;
else
V_5 &= ~ ( V_66 | V_65 ) ;
F_2 ( V_5 , V_1 + V_64 ) ;
}
void F_21 ( void T_1 * V_1 , unsigned char * V_58 ,
unsigned int V_59 , unsigned int V_60 )
{
unsigned int V_67 , V_68 ;
V_67 = F_6 ( V_1 + V_59 ) ;
V_68 = F_6 ( V_1 + V_60 ) ;
V_58 [ 0 ] = V_68 & 0xff ;
V_58 [ 1 ] = ( V_68 >> 8 ) & 0xff ;
V_58 [ 2 ] = ( V_68 >> 16 ) & 0xff ;
V_58 [ 3 ] = ( V_68 >> 24 ) & 0xff ;
V_58 [ 4 ] = V_67 & 0xff ;
V_58 [ 5 ] = ( V_67 >> 8 ) & 0xff ;
}
