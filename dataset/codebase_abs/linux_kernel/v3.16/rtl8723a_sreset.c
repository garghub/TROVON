void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
unsigned long V_8 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
unsigned int V_12 ;
T_1 V_13 ;
V_13 = F_3 ( V_2 , V_14 ) ;
if ( V_13 != 0 ) {
F_4 ( L_1 , V_15 , V_13 ) ;
F_5 ( V_2 ) ;
}
V_8 = V_16 ;
if ( 0 == V_10 -> V_17 || 0 == V_10 -> V_18 ) {
V_12 = F_6 ( V_16 - V_6 -> V_19 ) ;
if ( V_12 > 2000 ) {
if ( V_6 -> V_20 == 0 ) {
V_6 -> V_20 = V_8 ;
} else {
V_12 = F_6 ( V_16 - V_6 -> V_20 ) ;
if ( V_12 > 4000 ) {
F_4 ( L_2 , V_15 ) ;
F_5 ( V_2 ) ;
}
}
}
}
if ( V_6 -> V_21 == V_22 ) {
V_6 -> V_21 = V_23 ;
F_5 ( V_2 ) ;
return;
}
}
void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_21 == V_24 ) {
V_6 -> V_21 = V_23 ;
F_5 ( V_2 ) ;
return;
}
}
