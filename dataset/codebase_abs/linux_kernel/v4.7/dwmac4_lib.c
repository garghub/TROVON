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
void F_5 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
F_3 ( V_7 , V_1 + F_6 ( 0 ) ) ;
}
void F_7 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
F_3 ( V_7 , V_1 + F_8 ( 0 ) ) ;
}
void F_9 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + F_10 ( V_9 ) ) ;
V_2 |= V_10 ;
F_3 ( V_2 , V_1 + F_10 ( V_9 ) ) ;
V_2 = F_2 ( V_1 + V_11 ) ;
V_2 |= V_12 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_11 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + F_10 ( V_9 ) ) ;
V_2 &= ~ V_10 ;
F_3 ( V_2 , V_1 + F_10 ( V_9 ) ) ;
V_2 = F_2 ( V_1 + V_11 ) ;
V_2 &= ~ V_12 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_12 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + F_13 ( V_9 ) ) ;
V_2 |= V_13 ;
F_3 ( V_2 , V_1 + F_13 ( V_9 ) ) ;
V_2 = F_2 ( V_1 + V_11 ) ;
V_2 |= V_14 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_14 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + F_13 ( V_9 ) ) ;
V_2 &= ~ V_13 ;
F_3 ( V_2 , V_1 + F_13 ( V_9 ) ) ;
V_2 = F_2 ( V_1 + V_11 ) ;
V_2 &= ~ V_14 ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_15 ( void T_1 * V_1 , T_2 V_15 )
{
F_3 ( V_15 , V_1 + F_16 ( V_9 ) ) ;
}
void F_17 ( void T_1 * V_1 , T_2 V_15 )
{
F_3 ( V_15 , V_1 + F_18 ( V_9 ) ) ;
}
void F_19 ( void T_1 * V_1 )
{
F_3 ( V_16 , V_1 +
F_20 ( V_9 ) ) ;
}
void F_21 ( void T_1 * V_1 )
{
F_3 ( V_17 ,
V_1 + F_20 ( V_9 ) ) ;
}
void F_22 ( void T_1 * V_1 )
{
F_3 ( 0 , V_1 + F_20 ( V_9 ) ) ;
}
int F_23 ( void T_1 * V_1 ,
struct V_18 * V_19 )
{
int V_20 = 0 ;
T_2 V_21 = F_2 ( V_1 + F_24 ( 0 ) ) ;
if ( F_25 ( V_21 & V_22 ) ) {
if ( F_25 ( V_21 & V_23 ) )
V_19 -> V_24 ++ ;
if ( F_25 ( V_21 & V_25 ) )
V_19 -> V_26 ++ ;
if ( F_25 ( V_21 & V_27 ) )
V_19 -> V_28 ++ ;
if ( F_25 ( V_21 & V_29 ) )
V_19 -> V_30 ++ ;
if ( F_25 ( V_21 & V_31 ) ) {
V_19 -> V_32 ++ ;
V_20 = V_33 ;
}
if ( F_25 ( V_21 & V_34 ) ) {
V_19 -> V_35 ++ ;
V_20 = V_33 ;
}
}
if ( F_26 ( V_21 & V_36 ) ) {
V_19 -> V_37 ++ ;
if ( F_26 ( V_21 & V_38 ) ) {
T_2 V_2 ;
V_2 = F_2 ( V_1 + F_20 ( V_9 ) ) ;
if ( F_26 ( V_2 & V_39 ) ) {
V_19 -> V_40 ++ ;
V_20 |= V_41 ;
}
}
if ( F_26 ( V_21 & V_42 ) ) {
V_19 -> V_43 ++ ;
V_20 |= V_44 ;
}
if ( F_25 ( V_21 & V_45 ) )
V_19 -> V_46 ++ ;
}
F_3 ( ( V_21 & 0x3fffc7 ) ,
V_1 + F_24 ( V_9 ) ) ;
return V_20 ;
}
void F_27 ( void T_1 * V_1 , T_3 V_47 [ 6 ] ,
unsigned int V_48 , unsigned int V_49 )
{
unsigned long V_50 ;
V_50 = ( V_47 [ 5 ] << 8 ) | V_47 [ 4 ] ;
V_50 |= ( V_9 << V_51 ) ;
F_3 ( V_50 | V_52 , V_1 + V_48 ) ;
V_50 = ( V_47 [ 3 ] << 24 ) | ( V_47 [ 2 ] << 16 ) | ( V_47 [ 1 ] << 8 ) | V_47 [ 0 ] ;
F_3 ( V_50 , V_1 + V_49 ) ;
}
void F_28 ( void T_1 * V_1 , bool V_53 )
{
T_2 V_2 = F_2 ( V_1 + V_11 ) ;
if ( V_53 )
V_2 |= V_14 | V_12 ;
else
V_2 &= ~ ( V_12 | V_14 ) ;
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_29 ( void T_1 * V_1 , unsigned char * V_47 ,
unsigned int V_48 , unsigned int V_49 )
{
unsigned int V_54 , V_55 ;
V_54 = F_2 ( V_1 + V_48 ) ;
V_55 = F_2 ( V_1 + V_49 ) ;
V_47 [ 0 ] = V_55 & 0xff ;
V_47 [ 1 ] = ( V_55 >> 8 ) & 0xff ;
V_47 [ 2 ] = ( V_55 >> 16 ) & 0xff ;
V_47 [ 3 ] = ( V_55 >> 24 ) & 0xff ;
V_47 [ 4 ] = V_54 & 0xff ;
V_47 [ 5 ] = ( V_54 >> 8 ) & 0xff ;
}
