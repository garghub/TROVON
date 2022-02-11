bool F_1 ( struct V_1 * V_2 )
{
return ! ( F_2 ( V_2 , V_3 )
& V_4 ) ;
}
void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_8 -> V_9 ;
bool V_10 ;
bool V_11 = false ;
F_5 ( & V_8 -> V_12 ) ;
if ( F_6 ( F_7 ( V_2 ) < V_13 ) ) {
if ( F_8 ( V_2 , 0 ) ) {
F_9 ( & V_8 -> V_12 ) ;
return;
}
F_10 ( V_2 , 0 ) ;
V_11 = true ;
}
V_10 = F_1 ( V_2 ) ;
if ( F_6 ( V_10 != V_2 -> V_14 ) ) {
V_2 -> V_14 = V_10 ;
F_11 ( V_8 , L_1 ,
V_10 ? L_2 : L_3 ) ;
F_12 ( V_6 -> V_15 , ! V_10 ) ;
if ( V_10 != V_2 -> V_16 . V_17 )
F_13 ( V_2 , ! V_10 ) ;
}
if ( V_11 ) {
F_14 ( V_2 , 0 ) ;
F_15 ( V_2 ) ;
}
F_9 ( & V_8 -> V_12 ) ;
}
