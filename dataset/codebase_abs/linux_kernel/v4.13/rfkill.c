bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_2 -> V_3 . V_4 >= 3 ) {
if ( ! ( F_2 ( V_2 , V_5 )
& V_6 ) )
return true ;
} else {
if ( F_3 ( V_2 ) < V_7 )
return true ;
if ( F_4 ( V_2 , V_8 )
& V_9 )
return true ;
}
return false ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_15 * V_16 = V_2 -> V_2 -> V_16 ;
bool V_17 ;
bool V_18 = false ;
F_7 ( & V_13 -> V_19 ) ;
if ( F_8 ( F_3 ( V_2 ) < V_20 ) ) {
if ( F_9 ( V_16 , 0 ) ) {
F_10 ( & V_13 -> V_19 ) ;
return;
}
F_11 ( V_2 -> V_2 , 0 ) ;
V_18 = true ;
}
V_17 = F_1 ( V_2 ) ;
if ( F_8 ( V_17 != V_2 -> V_21 ) ) {
V_2 -> V_21 = V_17 ;
F_12 ( V_13 , L_1 ,
V_17 ? L_2 : L_3 ) ;
F_13 ( V_11 -> V_22 , ! V_17 ) ;
if ( V_17 != V_2 -> V_23 . V_24 ) {
if ( V_17 )
F_14 ( V_2 ) ;
else
F_15 ( V_2 , 0 ) ;
}
}
if ( V_18 ) {
F_16 ( V_2 -> V_2 , 0 ) ;
F_17 ( V_16 ) ;
}
F_10 ( & V_13 -> V_19 ) ;
}
