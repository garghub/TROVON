void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
unsigned long V_8 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
unsigned int V_12 ;
T_1 V_13 ;
V_13 = F_4 ( V_2 , V_14 ) ;
if ( V_13 != 0x00 ) {
F_5 ( L_1 , V_15 , V_13 ) ;
F_6 ( V_2 , V_14 , V_13 ) ;
F_1 ( V_2 ) ;
}
V_8 = V_16 ;
if ( 0 == V_10 -> V_17 ) {
V_12 = F_7 ( V_8 - V_6 -> V_18 ) ;
if ( V_12 > 2000 ) {
if ( V_6 -> V_19 == 0 ) {
V_6 -> V_19 = V_8 ;
} else {
V_12 = F_7 ( V_8 - V_6 -> V_19 ) ;
if ( V_12 > 4000 ) {
F_5 ( L_2 , V_15 ) ;
F_1 ( V_2 ) ;
}
}
}
}
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_20 = 0 ;
T_2 V_21 = 0 ;
V_20 = F_4 ( V_2 , V_22 ) ;
if ( V_20 != 0x00 ) {
F_5 ( L_3 , V_15 , V_20 ) ;
F_6 ( V_2 , V_22 , V_20 ) ;
}
V_21 = F_9 ( V_2 , V_23 ) ;
if ( V_21 != 0x00 ) {
if ( V_21 == 1 )
F_5 ( L_4 , V_15 , V_21 ) ;
else if ( V_21 == 2 )
F_5 ( L_5 , V_15 , V_21 ) ;
}
}
