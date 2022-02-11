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
F_4 ( V_2 , 0 ) ;
if ( V_3 )
F_5 ( V_2 , V_3 ) ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_12 = F_6 ( V_2 ) ;
if ( V_5 ) {
V_5 -> V_2 = V_2 ;
V_7 -> V_13 = V_5 ;
} else {
V_14 . V_2 = V_2 ;
}
F_7 ( & V_8 , 1 ) ;
}
void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
}
void T_1 F_8 ( int V_15 , struct V_16 * V_17 ,
int V_18 )
{
T_2 V_19 = 0 ;
T_2 V_20 = V_21 + 1 ;
while ( V_19 < V_21 ) {
T_3 V_22 = 0 ;
V_22 = F_9 ( V_19 , V_23 ) ;
if ( ( V_22 & 0xC00 ) == 0x800 ) {
F_10 ( V_24 L_3 , V_19 ) ;
if ( V_20 > V_21 )
V_20 = V_19 ;
}
V_19 ++ ;
}
if ( V_20 > V_21 ) {
F_10 ( V_24 L_4
L_5 ) ;
return;
}
if ( V_20 < V_21 ) {
V_25 . V_19 = V_20 ;
V_25 . V_17 = V_17 ;
V_25 . V_18 = V_18 ;
V_25 . V_26 = V_15 ;
F_10 ( V_24 L_6 , V_20 ) ;
if ( F_11 ( & V_25 ) < 0 )
F_10 ( V_27 L_7 ) ;
}
}
void T_1 F_8 ( int V_15 , struct V_16 * V_17 ,
int V_18 )
{
}
