struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_1 V_5 = ( V_3 -> V_6 == 2 ) ? 1 : 4 ;
int V_7 ;
V_7 = F_2 ( V_3 -> V_8 ) ;
if ( V_7 < 0 )
return F_3 ( V_7 ) ;
V_4 = F_4 ( V_3 -> V_9 , V_3 -> V_10 ,
V_3 -> V_11 , V_5 ,
V_3 -> V_12 , V_3 -> V_13 ,
V_3 -> V_8 ) ;
if ( V_4 == NULL )
goto V_14;
if ( V_4 -> V_15 == NULL && F_5 ( V_4 ) == NULL )
goto V_16;
V_4 -> V_17 = V_3 -> V_18 ;
return V_4 ;
V_16:
F_6 ( V_4 ) ;
V_14:
F_7 ( V_3 -> V_8 ) ;
return F_3 ( - V_19 ) ;
}
void F_8 ( struct V_1 * V_4 )
{
struct V_8 * V_8 = V_4 -> V_8 ;
F_6 ( V_4 ) ;
F_7 ( V_8 ) ;
}
struct V_20 * F_9 ( struct V_1 * V_4 , struct V_21 * V_22 )
{
struct V_20 * V_23 ;
V_23 = F_10 ( sizeof( * V_23 ) , V_24 ) ;
if ( V_23 != NULL ) {
V_23 -> V_25 = V_4 ;
V_23 -> V_26 = V_22 ;
F_11 ( & V_23 -> V_27 ) ;
V_23 -> V_28 = V_29 ;
F_12 ( & V_30 ) ;
F_13 ( & V_23 -> V_31 , & V_32 ) ;
F_14 ( & V_30 ) ;
}
return V_23 ;
}
void F_15 ( struct V_20 * V_23 )
{
if ( V_23 == NULL )
return;
F_12 ( & V_30 ) ;
F_16 ( & V_23 -> V_31 ) ;
F_14 ( & V_30 ) ;
F_17 ( V_23 ) ;
}
int F_18 ( struct V_20 * V_23 , struct V_33 * V_34 , long V_35 )
{
long V_36 ;
if ( V_23 == NULL )
return - V_37 ;
V_36 = F_19 ( V_23 -> V_27 ,
V_23 -> V_28 != V_29 ,
V_35 ) ;
if ( V_36 < 0 )
return - V_38 ;
if ( V_23 -> V_28 == V_39 )
V_23 -> V_28 = V_29 ;
V_34 -> V_40 . V_7 = V_23 -> V_28 ;
return 0 ;
}
T_2 F_20 ( const struct V_41 * V_42 , const struct V_43 * V_44 )
{
const struct V_21 * V_22 = & V_44 -> V_22 ;
const struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_20 * V_23 ;
T_2 V_47 = V_48 ;
F_12 ( & V_30 ) ;
F_21 (block, &nlm_blocked, b_list) {
struct V_21 * V_49 = V_23 -> V_26 ;
if ( V_49 -> V_50 != V_22 -> V_50 )
continue;
if ( V_49 -> V_51 != V_22 -> V_51 )
continue;
if ( V_49 -> V_52 . V_53 . V_54 -> V_55 != V_44 -> V_56 )
continue;
if ( ! F_22 ( F_23 ( V_23 -> V_25 ) , V_42 ) )
continue;
if ( F_24 ( F_25 ( F_26 ( V_49 -> V_57 ) ) , V_46 ) != 0 )
continue;
V_23 -> V_28 = V_58 ;
F_27 ( & V_23 -> V_27 ) ;
V_47 = V_58 ;
}
F_14 ( & V_30 ) ;
return V_47 ;
}
void
F_28 ( struct V_1 * V_4 )
{
struct V_59 * V_60 ;
if ( ! V_4 -> V_61 ++ ) {
F_29 ( V_4 ) ;
V_60 = F_30 ( V_62 , V_4 , L_1 , V_4 -> V_63 ) ;
if ( F_31 ( V_60 ) )
F_32 ( V_64 L_2
L_3
L_4 , V_4 -> V_63 , F_33 ( V_60 ) ) ;
}
}
static int
V_62 ( void * V_65 )
{
struct V_1 * V_4 = (struct V_1 * ) V_65 ;
struct V_20 * V_23 ;
struct V_33 * V_34 ;
struct V_21 * V_22 , * V_66 ;
T_1 V_67 ;
struct V_8 * V_8 = V_4 -> V_8 ;
V_34 = F_10 ( sizeof( * V_34 ) , V_24 ) ;
if ( ! V_34 )
return 0 ;
F_34 ( V_68 ) ;
F_35 ( & V_4 -> V_69 ) ;
F_2 ( V_8 ) ;
F_36 ( L_5 , V_4 -> V_63 ) ;
V_70:
V_67 = V_4 -> V_71 ;
V_4 -> V_72 = V_73 ;
F_37 ( V_4 ) ;
F_38 ( & V_4 -> V_74 , & V_4 -> V_75 ) ;
F_39 (fl, next, &host->h_reclaim, fl_u.nfs_fl.list) {
F_40 ( & V_22 -> V_52 . V_53 . V_76 ) ;
if ( F_41 () )
continue;
if ( F_42 ( V_4 , V_22 , V_34 ) != 0 )
continue;
F_43 ( & V_22 -> V_52 . V_53 . V_76 , & V_4 -> V_74 ) ;
if ( V_4 -> V_71 != V_67 ) {
goto V_70;
}
}
V_4 -> V_61 = 0 ;
F_44 ( & V_4 -> V_69 ) ;
F_36 ( L_6 , V_4 -> V_63 ) ;
F_12 ( & V_30 ) ;
F_21 (block, &nlm_blocked, b_list) {
if ( V_23 -> V_25 == V_4 ) {
V_23 -> V_28 = V_39 ;
F_27 ( & V_23 -> V_27 ) ;
}
}
F_14 ( & V_30 ) ;
F_6 ( V_4 ) ;
F_7 ( V_8 ) ;
F_17 ( V_34 ) ;
return 0 ;
}
