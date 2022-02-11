static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( 1 << V_2 -> V_5 ) ;
F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( 1 << V_2 -> V_5 ) ;
F_3 ( V_3 , V_4 ) ;
switch ( V_2 -> V_5 ) {
case V_6 : F_3 ( 0 , V_7 ) ; break;
case V_8 : F_3 ( 0 , V_9 ) ; break;
case V_10 : F_3 ( 0 , V_11 ) ; break;
case V_12 : F_3 ( 0 , V_13 ) ; break;
case V_14 : F_3 ( 0 , V_15 ) ; break;
case V_16 : F_3 ( 0 , V_17 ) ; break;
}
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= 1 << V_2 -> V_5 ;
F_3 ( V_3 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_2 ( V_19 ) ;
V_18 &= ~ ( 1 << ( V_2 -> V_5 - 16 ) ) ;
F_3 ( V_18 , V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_2 ( V_19 ) ;
V_18 &= ~ ( 1 << ( V_2 -> V_5 - 16 ) ) ;
F_3 ( V_18 , V_19 ) ;
switch ( V_2 -> V_5 ) {
case V_20 : F_3 ( 0 , V_21 ) ; break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_2 ( V_19 ) ;
V_18 |= 1 << ( V_2 -> V_5 - 16 ) ;
F_3 ( V_18 , V_19 ) ;
}
void T_2 F_9 ( void )
{
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_24 & ( 1 << V_22 ) ) {
F_10 ( V_22 , & V_25 ,
V_26 ) ;
F_11 ( V_22 , V_27 | V_28 ) ;
}
if ( V_29 & ( 1 << V_22 ) ) {
F_10 ( V_22 , & V_30 ,
V_26 ) ;
F_11 ( V_22 , V_27 | V_28 ) ;
}
}
F_3 ( 0 , V_4 ) ;
F_3 ( 0 , V_19 ) ;
F_3 ( 0 , V_7 ) ;
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_11 ) ;
F_3 ( 0 , V_13 ) ;
F_3 ( 0 , V_15 ) ;
F_3 ( 0 , V_17 ) ;
F_3 ( 0 , V_31 ) ;
F_3 ( 0 , V_21 ) ;
}
