int F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
int V_4 ;
V_2 |= V_5 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_4 = 10 ;
while ( V_4 -- ) {
if ( ! ( F_2 ( V_1 + V_3 ) & V_5 ) )
break;
F_4 ( 10 ) ;
}
if ( V_4 < 0 )
return - V_6 ;
return 0 ;
}
void F_5 ( void T_1 * V_1 )
{
F_3 ( 1 , V_1 + V_7 ) ;
}
void F_6 ( void T_1 * V_1 )
{
F_3 ( V_8 , V_1 + V_9 ) ;
}
void F_7 ( void T_1 * V_1 )
{
F_3 ( 0 , V_1 + V_9 ) ;
}
void F_8 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_10 ) ;
V_2 |= V_11 ;
F_3 ( V_2 , V_1 + V_10 ) ;
}
void F_9 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_10 ) ;
V_2 &= ~ V_11 ;
F_3 ( V_2 , V_1 + V_10 ) ;
}
void F_10 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_10 ) ;
V_2 |= V_12 ;
F_3 ( V_2 , V_1 + V_10 ) ;
}
void F_11 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_10 ) ;
V_2 &= ~ V_12 ;
F_3 ( V_2 , V_1 + V_10 ) ;
}
static void F_12 ( unsigned int V_13 )
{
unsigned int V_14 ;
V_14 = ( V_13 & V_15 ) >> V_16 ;
switch ( V_14 ) {
case 0 :
F_13 ( L_1 ) ;
break;
case 1 :
F_13 ( L_2 ) ;
break;
case 2 :
F_13 ( L_3 ) ;
break;
case 3 :
F_13 ( L_4
L_5 ) ;
break;
case 6 :
F_13 ( L_6
L_7 ) ;
break;
case 7 :
F_13 ( L_8 ) ;
break;
default:
break;
}
}
static void F_14 ( unsigned int V_13 )
{
unsigned int V_14 ;
V_14 = ( V_13 & V_17 ) >> V_18 ;
switch ( V_14 ) {
case 0 :
F_13 ( L_9 ) ;
break;
case 1 :
F_13 ( L_10 ) ;
break;
case 2 :
F_13 ( L_11 ) ;
break;
case 3 :
F_13 ( L_12 ) ;
break;
case 4 :
F_13 ( L_13 ) ;
break;
case 5 :
F_13 ( L_14 ) ;
break;
case 6 :
F_13 ( L_15
L_16 ) ;
break;
case 7 :
F_13 ( L_17
L_18 ) ;
break;
default:
break;
}
}
int F_15 ( void T_1 * V_1 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
T_2 V_22 = F_2 ( V_1 + V_23 ) ;
#ifdef F_16
F_13 ( L_19 , V_24 , V_22 ) ;
F_12 ( V_22 ) ;
F_14 ( V_22 ) ;
#endif
if ( F_17 ( V_22 & V_25 ) ) {
if ( F_17 ( V_22 & V_26 ) ) {
V_21 = V_27 ;
V_20 -> V_28 ++ ;
}
if ( F_17 ( V_22 & V_29 ) )
V_20 -> V_30 ++ ;
if ( F_17 ( V_22 & V_31 ) )
V_20 -> V_32 ++ ;
if ( F_17 ( V_22 & V_33 ) )
V_20 -> V_34 ++ ;
if ( F_17 ( V_22 & V_35 ) )
V_20 -> V_36 ++ ;
if ( F_17 ( V_22 & V_37 ) )
V_20 -> V_38 ++ ;
if ( F_17 ( V_22 & V_39 ) )
V_20 -> V_40 ++ ;
if ( F_17 ( V_22 & V_41 ) ) {
V_20 -> V_42 ++ ;
V_21 = V_43 ;
}
if ( F_17 ( V_22 & V_44 ) ) {
V_20 -> V_45 ++ ;
V_21 = V_43 ;
}
}
if ( F_18 ( V_22 & V_46 ) ) {
V_20 -> V_47 ++ ;
if ( F_18 ( V_22 & V_48 ) ) {
T_2 V_2 = F_2 ( V_1 + V_9 ) ;
if ( F_18 ( V_2 & V_49 ) ) {
V_20 -> V_50 ++ ;
V_21 |= V_51 ;
}
}
if ( F_18 ( V_22 & V_52 ) ) {
V_20 -> V_53 ++ ;
V_21 |= V_54 ;
}
if ( F_17 ( V_22 & V_55 ) )
V_20 -> V_56 ++ ;
}
if ( F_17 ( V_22 &
( V_57 | V_58 | V_59 ) ) )
F_19 ( L_20 , V_24 , V_22 ) ;
F_3 ( ( V_22 & 0x1ffff ) , V_1 + V_23 ) ;
return V_21 ;
}
void F_20 ( void T_1 * V_1 )
{
T_2 V_60 = F_2 ( V_1 + V_10 ) ;
F_3 ( ( V_60 | V_61 ) , V_1 + V_10 ) ;
do {} while ( ( F_2 ( V_1 + V_10 ) & V_61 ) );
}
void F_21 ( void T_1 * V_1 , T_3 V_62 [ 6 ] ,
unsigned int V_63 , unsigned int V_64 )
{
unsigned long V_65 ;
V_65 = ( V_62 [ 5 ] << 8 ) | V_62 [ 4 ] ;
F_3 ( V_65 | V_66 , V_1 + V_63 ) ;
V_65 = ( V_62 [ 3 ] << 24 ) | ( V_62 [ 2 ] << 16 ) | ( V_62 [ 1 ] << 8 ) | V_62 [ 0 ] ;
F_3 ( V_65 , V_1 + V_64 ) ;
}
void F_22 ( void T_1 * V_1 , bool V_67 )
{
T_2 V_2 = F_2 ( V_1 + V_68 ) ;
if ( V_67 )
V_2 |= V_69 | V_70 ;
else
V_2 &= ~ ( V_70 | V_69 ) ;
F_3 ( V_2 , V_1 + V_68 ) ;
}
void F_23 ( void T_1 * V_1 , unsigned char * V_62 ,
unsigned int V_63 , unsigned int V_64 )
{
unsigned int V_71 , V_72 ;
V_71 = F_2 ( V_1 + V_63 ) ;
V_72 = F_2 ( V_1 + V_64 ) ;
V_62 [ 0 ] = V_72 & 0xff ;
V_62 [ 1 ] = ( V_72 >> 8 ) & 0xff ;
V_62 [ 2 ] = ( V_72 >> 16 ) & 0xff ;
V_62 [ 3 ] = ( V_72 >> 24 ) & 0xff ;
V_62 [ 4 ] = V_71 & 0xff ;
V_62 [ 5 ] = ( V_71 >> 8 ) & 0xff ;
}
