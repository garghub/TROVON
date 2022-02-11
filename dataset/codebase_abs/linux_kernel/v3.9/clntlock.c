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
if ( V_4 == NULL ) {
F_5 ( V_3 -> V_8 ) ;
return F_3 ( - V_14 ) ;
}
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
struct V_8 * V_8 = V_4 -> V_8 ;
F_7 ( V_4 ) ;
F_5 ( V_8 ) ;
}
struct V_15 * F_8 ( struct V_1 * V_4 , struct V_16 * V_17 )
{
struct V_15 * V_18 ;
V_18 = F_9 ( sizeof( * V_18 ) , V_19 ) ;
if ( V_18 != NULL ) {
V_18 -> V_20 = V_4 ;
V_18 -> V_21 = V_17 ;
F_10 ( & V_18 -> V_22 ) ;
V_18 -> V_23 = V_24 ;
F_11 ( & V_25 ) ;
F_12 ( & V_18 -> V_26 , & V_27 ) ;
F_13 ( & V_25 ) ;
}
return V_18 ;
}
void F_14 ( struct V_15 * V_18 )
{
if ( V_18 == NULL )
return;
F_11 ( & V_25 ) ;
F_15 ( & V_18 -> V_26 ) ;
F_13 ( & V_25 ) ;
F_16 ( V_18 ) ;
}
int F_17 ( struct V_15 * V_18 , struct V_28 * V_29 , long V_30 )
{
long V_31 ;
if ( V_18 == NULL )
return - V_32 ;
V_31 = F_18 ( V_18 -> V_22 ,
V_18 -> V_23 != V_24 ,
V_30 ) ;
if ( V_31 < 0 )
return - V_33 ;
V_29 -> V_34 . V_7 = V_18 -> V_23 ;
return 0 ;
}
T_2 F_19 ( const struct V_35 * V_36 , const struct V_37 * V_38 )
{
const struct V_16 * V_17 = & V_38 -> V_17 ;
const struct V_39 * V_40 = & V_38 -> V_40 ;
struct V_15 * V_18 ;
T_2 V_41 = V_42 ;
F_11 ( & V_25 ) ;
F_20 (block, &nlm_blocked, b_list) {
struct V_16 * V_43 = V_18 -> V_21 ;
if ( V_43 -> V_44 != V_17 -> V_44 )
continue;
if ( V_43 -> V_45 != V_17 -> V_45 )
continue;
if ( V_43 -> V_46 . V_47 . V_48 -> V_49 != V_38 -> V_50 )
continue;
if ( ! F_21 ( F_22 ( V_18 -> V_20 ) , V_36 ) )
continue;
if ( F_23 ( F_24 ( F_25 ( V_43 -> V_51 ) ) , V_40 ) != 0 )
continue;
V_18 -> V_23 = V_52 ;
F_26 ( & V_18 -> V_22 ) ;
V_41 = V_52 ;
}
F_13 ( & V_25 ) ;
return V_41 ;
}
void
F_27 ( struct V_1 * V_4 )
{
struct V_53 * V_54 ;
if ( ! V_4 -> V_55 ++ ) {
F_28 ( V_4 ) ;
V_54 = F_29 ( V_56 , V_4 , L_1 , V_4 -> V_57 ) ;
if ( F_30 ( V_54 ) )
F_31 ( V_58 L_2
L_3
L_4 , V_4 -> V_57 , F_32 ( V_54 ) ) ;
}
}
static int
V_56 ( void * V_59 )
{
struct V_1 * V_4 = (struct V_1 * ) V_59 ;
struct V_15 * V_18 ;
struct V_28 * V_29 ;
struct V_16 * V_17 , * V_60 ;
T_1 V_61 ;
struct V_8 * V_8 = V_4 -> V_8 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_19 ) ;
if ( ! V_29 ) {
F_31 ( V_58 L_5
L_6 ,
V_4 -> V_57 ) ;
return 0 ;
}
F_33 ( V_62 ) ;
F_34 ( & V_4 -> V_63 ) ;
F_2 ( V_8 ) ;
F_35 ( L_7 , V_4 -> V_57 ) ;
V_64:
V_61 = V_4 -> V_65 ;
V_4 -> V_66 = V_67 ;
F_36 ( V_4 ) ;
F_37 ( & V_4 -> V_68 , & V_4 -> V_69 ) ;
F_38 (fl, next, &host->h_reclaim, fl_u.nfs_fl.list) {
F_39 ( & V_17 -> V_46 . V_47 . V_70 ) ;
if ( F_40 () )
continue;
if ( F_41 ( V_4 , V_17 , V_29 ) != 0 )
continue;
F_42 ( & V_17 -> V_46 . V_47 . V_70 , & V_4 -> V_68 ) ;
if ( V_4 -> V_65 != V_61 ) {
goto V_64;
}
}
V_4 -> V_55 = 0 ;
F_43 ( & V_4 -> V_63 ) ;
F_35 ( L_8 , V_4 -> V_57 ) ;
F_11 ( & V_25 ) ;
F_20 (block, &nlm_blocked, b_list) {
if ( V_18 -> V_20 == V_4 ) {
V_18 -> V_23 = V_71 ;
F_26 ( & V_18 -> V_22 ) ;
}
}
F_13 ( & V_25 ) ;
F_7 ( V_4 ) ;
F_5 ( V_8 ) ;
F_16 ( V_29 ) ;
return 0 ;
}
