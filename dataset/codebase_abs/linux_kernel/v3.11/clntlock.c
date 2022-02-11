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
return V_4 ;
V_16:
F_6 ( V_4 ) ;
V_14:
F_7 ( V_3 -> V_8 ) ;
return F_3 ( - V_17 ) ;
}
void F_8 ( struct V_1 * V_4 )
{
struct V_8 * V_8 = V_4 -> V_8 ;
F_6 ( V_4 ) ;
F_7 ( V_8 ) ;
}
struct V_18 * F_9 ( struct V_1 * V_4 , struct V_19 * V_20 )
{
struct V_18 * V_21 ;
V_21 = F_10 ( sizeof( * V_21 ) , V_22 ) ;
if ( V_21 != NULL ) {
V_21 -> V_23 = V_4 ;
V_21 -> V_24 = V_20 ;
F_11 ( & V_21 -> V_25 ) ;
V_21 -> V_26 = V_27 ;
F_12 ( & V_28 ) ;
F_13 ( & V_21 -> V_29 , & V_30 ) ;
F_14 ( & V_28 ) ;
}
return V_21 ;
}
void F_15 ( struct V_18 * V_21 )
{
if ( V_21 == NULL )
return;
F_12 ( & V_28 ) ;
F_16 ( & V_21 -> V_29 ) ;
F_14 ( & V_28 ) ;
F_17 ( V_21 ) ;
}
int F_18 ( struct V_18 * V_21 , struct V_31 * V_32 , long V_33 )
{
long V_34 ;
if ( V_21 == NULL )
return - V_35 ;
V_34 = F_19 ( V_21 -> V_25 ,
V_21 -> V_26 != V_27 ,
V_33 ) ;
if ( V_34 < 0 )
return - V_36 ;
if ( V_21 -> V_26 == V_37 )
V_21 -> V_26 = V_27 ;
V_32 -> V_38 . V_7 = V_21 -> V_26 ;
return 0 ;
}
T_2 F_20 ( const struct V_39 * V_40 , const struct V_41 * V_42 )
{
const struct V_19 * V_20 = & V_42 -> V_20 ;
const struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_18 * V_21 ;
T_2 V_45 = V_46 ;
F_12 ( & V_28 ) ;
F_21 (block, &nlm_blocked, b_list) {
struct V_19 * V_47 = V_21 -> V_24 ;
if ( V_47 -> V_48 != V_20 -> V_48 )
continue;
if ( V_47 -> V_49 != V_20 -> V_49 )
continue;
if ( V_47 -> V_50 . V_51 . V_52 -> V_53 != V_42 -> V_54 )
continue;
if ( ! F_22 ( F_23 ( V_21 -> V_23 ) , V_40 ) )
continue;
if ( F_24 ( F_25 ( F_26 ( V_47 -> V_55 ) ) , V_44 ) != 0 )
continue;
V_21 -> V_26 = V_56 ;
F_27 ( & V_21 -> V_25 ) ;
V_45 = V_56 ;
}
F_14 ( & V_28 ) ;
return V_45 ;
}
void
F_28 ( struct V_1 * V_4 )
{
struct V_57 * V_58 ;
if ( ! V_4 -> V_59 ++ ) {
F_29 ( V_4 ) ;
V_58 = F_30 ( V_60 , V_4 , L_1 , V_4 -> V_61 ) ;
if ( F_31 ( V_58 ) )
F_32 ( V_62 L_2
L_3
L_4 , V_4 -> V_61 , F_33 ( V_58 ) ) ;
}
}
static int
V_60 ( void * V_63 )
{
struct V_1 * V_4 = (struct V_1 * ) V_63 ;
struct V_18 * V_21 ;
struct V_31 * V_32 ;
struct V_19 * V_20 , * V_64 ;
T_1 V_65 ;
struct V_8 * V_8 = V_4 -> V_8 ;
V_32 = F_10 ( sizeof( * V_32 ) , V_22 ) ;
if ( ! V_32 ) {
F_32 ( V_62 L_5
L_6 ,
V_4 -> V_61 ) ;
return 0 ;
}
F_34 ( V_66 ) ;
F_35 ( & V_4 -> V_67 ) ;
F_2 ( V_8 ) ;
F_36 ( L_7 , V_4 -> V_61 ) ;
V_68:
V_65 = V_4 -> V_69 ;
V_4 -> V_70 = V_71 ;
F_37 ( V_4 ) ;
F_38 ( & V_4 -> V_72 , & V_4 -> V_73 ) ;
F_39 (fl, next, &host->h_reclaim, fl_u.nfs_fl.list) {
F_40 ( & V_20 -> V_50 . V_51 . V_74 ) ;
if ( F_41 () )
continue;
if ( F_42 ( V_4 , V_20 , V_32 ) != 0 )
continue;
F_43 ( & V_20 -> V_50 . V_51 . V_74 , & V_4 -> V_72 ) ;
if ( V_4 -> V_69 != V_65 ) {
goto V_68;
}
}
V_4 -> V_59 = 0 ;
F_44 ( & V_4 -> V_67 ) ;
F_36 ( L_8 , V_4 -> V_61 ) ;
F_12 ( & V_28 ) ;
F_21 (block, &nlm_blocked, b_list) {
if ( V_21 -> V_23 == V_4 ) {
V_21 -> V_26 = V_37 ;
F_27 ( & V_21 -> V_25 ) ;
}
}
F_14 ( & V_28 ) ;
F_6 ( V_4 ) ;
F_7 ( V_8 ) ;
F_17 ( V_32 ) ;
return 0 ;
}
