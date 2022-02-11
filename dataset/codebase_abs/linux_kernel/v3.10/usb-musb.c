void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = - 1 ;
const char * V_10 , * V_11 ;
struct V_1 * V_12 ;
if ( V_2 )
V_12 = V_2 ;
else
V_12 = & V_13 ;
V_14 . clock = L_1 ;
V_14 . V_12 = V_12 ;
V_14 . V_15 = V_12 -> V_15 >> 1 ;
V_14 . V_16 = V_12 -> V_16 ;
V_14 . V_17 = V_12 -> V_17 ;
if ( F_2 () )
V_14 . V_18 = true ;
if ( F_3 () ) {
V_10 = L_2 ;
V_11 = L_3 ;
} else if ( F_4 () ) {
V_10 = L_4 ;
V_11 = L_5 ;
} else {
V_10 = L_4 ;
V_11 = L_6 ;
}
V_4 = F_5 ( V_10 ) ;
if ( F_6 ( ! V_4 , L_7 ,
V_19 , V_10 ) )
return;
V_6 = F_7 ( V_11 , V_9 , V_4 , & V_14 ,
sizeof( V_14 ) ) ;
if ( F_8 ( V_6 ) ) {
F_9 ( L_8 ,
V_11 , V_10 ) ;
return;
}
V_8 = & V_6 -> V_8 ;
F_10 ( V_8 ) ;
V_8 -> V_20 = & V_21 ;
V_8 -> V_22 = V_21 ;
F_11 ( V_8 ) ;
}
