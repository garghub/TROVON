void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0 ;
}
int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_9 ;
struct V_10 * V_11 ;
int V_12 ;
V_9 = V_6 -> V_13 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_14 /
V_8 -> V_15 . V_16 ; V_12 ++ ) {
V_11 = F_4 ( sizeof( * V_11 ) , V_17 ) ;
if ( ! V_11 )
goto V_18;
V_11 -> V_19 = V_8 -> V_15 . V_16 ;
V_11 -> V_20 = V_9 ;
F_5 ( V_11 , & V_6 -> V_21 ) ;
V_9 += V_8 -> V_15 . V_16 ;
}
return 0 ;
V_18:
F_6 ( V_6 ) ;
return - V_22 ;
}
void F_6 ( struct V_5 * V_6 )
{
struct V_10 * V_11 , * V_23 ;
F_7 ( ! F_8 ( V_6 -> V_24 ) ) ;
F_7 ( ! F_8 ( V_6 -> V_25 ) ) ;
F_9 (grp, gptr, &rcd->tid_group_list.list, list) {
F_10 ( V_11 , & V_6 -> V_21 ) ;
F_11 ( V_11 ) ;
}
F_12 ( V_6 ) ;
}
