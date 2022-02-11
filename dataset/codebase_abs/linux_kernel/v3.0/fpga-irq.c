static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << ( V_2 -> V_6 - V_4 -> V_7 ) ;
F_3 ( V_5 , V_4 -> V_8 + V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << ( V_2 -> V_6 - V_4 -> V_7 ) ;
F_3 ( V_5 , V_4 -> V_8 + V_10 ) ;
}
static void F_5 ( unsigned int V_6 , struct V_11 * V_12 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
T_1 V_13 = F_7 ( V_4 -> V_8 + V_14 ) ;
if ( V_13 == 0 ) {
F_8 ( V_6 , V_12 ) ;
return;
}
do {
V_6 = F_9 ( V_13 ) - 1 ;
V_13 &= ~ ( 1 << V_6 ) ;
F_10 ( V_6 + V_4 -> V_7 ) ;
} while ( V_13 );
}
void T_2 F_11 ( int V_15 , T_1 V_16 , struct V_3 * V_4 )
{
unsigned int V_17 ;
V_4 -> V_18 . V_19 = F_1 ;
V_4 -> V_18 . V_20 = F_1 ;
V_4 -> V_18 . V_21 = F_4 ;
if ( V_15 != - 1 ) {
F_12 ( V_15 , V_4 ) ;
F_13 ( V_15 , F_5 ) ;
}
for ( V_17 = 0 ; V_17 < 32 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
unsigned int V_6 = V_4 -> V_7 + V_17 ;
F_14 ( V_6 , V_4 ) ;
F_15 ( V_6 , & V_4 -> V_18 ,
V_22 ) ;
F_16 ( V_6 , V_23 | V_24 ) ;
}
}
}
