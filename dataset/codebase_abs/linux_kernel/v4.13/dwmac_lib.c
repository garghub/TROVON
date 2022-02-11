int F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
int V_4 ;
V_2 |= V_5 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_4 = F_4 ( V_1 + V_3 , V_2 ,
! ( V_2 & V_5 ) ,
100000 , 10000 ) ;
if ( V_4 )
return - V_6 ;
return 0 ;
}
void F_5 ( void T_1 * V_1 )
{
F_3 ( 1 , V_1 + V_7 ) ;
}
void F_6 ( void T_1 * V_1 , T_2 V_8 )
{
F_3 ( V_9 , V_1 + V_10 ) ;
}
void F_7 ( void T_1 * V_1 , T_2 V_8 )
{
F_3 ( 0 , V_1 + V_10 ) ;
}
void F_8 ( void T_1 * V_1 , T_2 V_8 )
{
T_2 V_2 = F_2 ( V_1 + V_11 ) ;
V_2 |= V_12 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_9 ( void T_1 * V_1 , T_2 V_8 )
{
T_2 V_2 = F_2 ( V_1 + V_11 ) ;
V_2 &= ~ V_12 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_10 ( void T_1 * V_1 , T_2 V_8 )
{
T_2 V_2 = F_2 ( V_1 + V_11 ) ;
V_2 |= V_13 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_11 ( void T_1 * V_1 , T_2 V_8 )
{
T_2 V_2 = F_2 ( V_1 + V_11 ) ;
V_2 &= ~ V_13 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
static void F_12 ( unsigned int V_14 )
{
unsigned int V_15 ;
V_15 = ( V_14 & V_16 ) >> V_17 ;
switch ( V_15 ) {
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
static void F_14 ( unsigned int V_14 )
{
unsigned int V_15 ;
V_15 = ( V_14 & V_18 ) >> V_19 ;
switch ( V_15 ) {
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
struct V_20 * V_21 , T_2 V_8 )
{
int V_22 = 0 ;
T_2 V_23 = F_2 ( V_1 + V_24 ) ;
#ifdef F_16
F_13 ( L_19 , V_25 , V_23 ) ;
F_12 ( V_23 ) ;
F_14 ( V_23 ) ;
#endif
if ( F_17 ( V_23 & V_26 ) ) {
if ( F_17 ( V_23 & V_27 ) ) {
V_22 = V_28 ;
V_21 -> V_29 ++ ;
}
if ( F_17 ( V_23 & V_30 ) )
V_21 -> V_31 ++ ;
if ( F_17 ( V_23 & V_32 ) )
V_21 -> V_33 ++ ;
if ( F_17 ( V_23 & V_34 ) )
V_21 -> V_35 ++ ;
if ( F_17 ( V_23 & V_36 ) )
V_21 -> V_37 ++ ;
if ( F_17 ( V_23 & V_38 ) )
V_21 -> V_39 ++ ;
if ( F_17 ( V_23 & V_40 ) )
V_21 -> V_41 ++ ;
if ( F_17 ( V_23 & V_42 ) ) {
V_21 -> V_43 ++ ;
V_22 = V_44 ;
}
if ( F_17 ( V_23 & V_45 ) ) {
V_21 -> V_46 ++ ;
V_22 = V_44 ;
}
}
if ( F_18 ( V_23 & V_47 ) ) {
V_21 -> V_48 ++ ;
if ( F_18 ( V_23 & V_49 ) ) {
T_2 V_2 = F_2 ( V_1 + V_10 ) ;
if ( F_18 ( V_2 & V_50 ) ) {
V_21 -> V_51 ++ ;
V_22 |= V_52 ;
}
}
if ( F_18 ( V_23 & V_53 ) ) {
V_21 -> V_54 ++ ;
V_22 |= V_55 ;
}
if ( F_17 ( V_23 & V_56 ) )
V_21 -> V_57 ++ ;
}
if ( F_17 ( V_23 &
( V_58 | V_59 | V_60 ) ) )
F_19 ( L_20 , V_25 , V_23 ) ;
F_3 ( ( V_23 & 0x1ffff ) , V_1 + V_24 ) ;
return V_22 ;
}
void F_20 ( void T_1 * V_1 )
{
T_2 V_61 = F_2 ( V_1 + V_11 ) ;
F_3 ( ( V_61 | V_62 ) , V_1 + V_11 ) ;
do {} while ( ( F_2 ( V_1 + V_11 ) & V_62 ) );
}
void F_21 ( void T_1 * V_1 , T_3 V_63 [ 6 ] ,
unsigned int V_64 , unsigned int V_65 )
{
unsigned long V_66 ;
V_66 = ( V_63 [ 5 ] << 8 ) | V_63 [ 4 ] ;
F_3 ( V_66 | V_67 , V_1 + V_64 ) ;
V_66 = ( V_63 [ 3 ] << 24 ) | ( V_63 [ 2 ] << 16 ) | ( V_63 [ 1 ] << 8 ) | V_63 [ 0 ] ;
F_3 ( V_66 , V_1 + V_65 ) ;
}
void F_22 ( void T_1 * V_1 , bool V_68 )
{
T_2 V_2 = F_2 ( V_1 + V_69 ) ;
if ( V_68 )
V_2 |= V_70 | V_71 ;
else
V_2 &= ~ ( V_71 | V_70 ) ;
F_3 ( V_2 , V_1 + V_69 ) ;
}
void F_23 ( void T_1 * V_1 , unsigned char * V_63 ,
unsigned int V_64 , unsigned int V_65 )
{
unsigned int V_72 , V_73 ;
V_72 = F_2 ( V_1 + V_64 ) ;
V_73 = F_2 ( V_1 + V_65 ) ;
V_63 [ 0 ] = V_73 & 0xff ;
V_63 [ 1 ] = ( V_73 >> 8 ) & 0xff ;
V_63 [ 2 ] = ( V_73 >> 16 ) & 0xff ;
V_63 [ 3 ] = ( V_73 >> 24 ) & 0xff ;
V_63 [ 4 ] = V_72 & 0xff ;
V_63 [ 5 ] = ( V_72 >> 8 ) & 0xff ;
}
