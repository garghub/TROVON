void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_8 ;
int V_9 ;
if ( V_5 && V_5 -> V_10 ) {
V_9 = F_2 ( V_2 , V_11 , L_1 ) ;
if ( V_9 ) {
F_3 ( L_2 , V_9 ) ;
return;
}
if ( V_3 )
F_4 ( V_2 , V_3 ) ;
F_5 ( V_2 , 0 ) ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_12 = F_6 ( V_2 ) ;
V_13 . V_2 = V_2 ;
if ( V_5 ) {
V_5 -> V_2 = V_2 ;
V_5 -> V_14 = V_3 ;
V_7 -> V_15 = V_5 ;
}
F_7 ( & V_8 , 1 ) ;
}
void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
}
void T_1 F_8 ( int V_16 , struct V_17 * V_18 ,
int V_19 )
{
T_2 V_20 = 0 ;
T_2 V_21 = V_22 + 1 ;
while ( V_20 < V_22 ) {
T_3 V_23 = 0 ;
V_23 = F_9 ( V_20 , V_24 ) ;
if ( ( V_23 & 0xC00 ) == 0x800 ) {
F_10 ( V_25 L_3 , V_20 ) ;
if ( V_21 > V_22 )
V_21 = V_20 ;
}
V_20 ++ ;
}
if ( V_21 > V_22 ) {
F_11 ( L_4 ) ;
return;
}
if ( V_21 < V_22 ) {
V_26 . V_20 = V_21 ;
V_26 . V_18 = V_18 ;
V_26 . V_19 = V_19 ;
V_26 . V_27 = V_16 ;
F_10 ( V_25 L_5 , V_21 ) ;
if ( F_12 ( & V_26 ) < 0 )
F_10 ( V_28 L_6 ) ;
}
}
void T_1 F_8 ( int V_16 , struct V_17 * V_18 ,
int V_19 )
{
}
