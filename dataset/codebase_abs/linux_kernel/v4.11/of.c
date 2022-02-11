void F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_9 . V_8 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 ;
T_1 V_14 ;
T_1 V_15 ;
if ( ! V_11 || V_4 != V_16 ||
! F_2 ( V_11 , L_1 ) )
return;
if ( F_3 ( V_11 , L_2 , & V_15 ) == 0 )
V_8 -> V_17 = V_15 ;
if ( ! F_4 ( V_11 , L_3 , NULL ) )
return;
V_13 = F_5 ( V_11 , 0 ) ;
if ( ! V_13 ) {
F_6 ( L_4 ) ;
return;
}
V_14 = F_7 ( F_8 ( V_13 ) ) ;
V_8 -> V_18 = true ;
V_8 -> V_19 = V_13 ;
V_8 -> V_20 = V_14 ;
}
