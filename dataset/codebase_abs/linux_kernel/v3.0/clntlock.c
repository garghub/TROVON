struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 ;
T_1 V_5 = ( V_3 -> V_6 == 2 ) ? 1 : 4 ;
int V_7 ;
V_7 = F_2 () ;
if ( V_7 < 0 )
return F_3 ( V_7 ) ;
V_4 = F_4 ( V_3 -> V_8 , V_3 -> V_9 ,
V_3 -> V_10 , V_5 ,
V_3 -> V_11 , V_3 -> V_12 ) ;
if ( V_4 == NULL ) {
F_5 () ;
return F_3 ( - V_13 ) ;
}
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 ) ;
F_5 () ;
}
struct V_14 * F_8 ( struct V_1 * V_4 , struct V_15 * V_16 )
{
struct V_14 * V_17 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_18 ) ;
if ( V_17 != NULL ) {
V_17 -> V_19 = V_4 ;
V_17 -> V_20 = V_16 ;
F_10 ( & V_17 -> V_21 ) ;
V_17 -> V_22 = V_23 ;
F_11 ( & V_24 ) ;
F_12 ( & V_17 -> V_25 , & V_26 ) ;
F_13 ( & V_24 ) ;
}
return V_17 ;
}
void F_14 ( struct V_14 * V_17 )
{
if ( V_17 == NULL )
return;
F_11 ( & V_24 ) ;
F_15 ( & V_17 -> V_25 ) ;
F_13 ( & V_24 ) ;
F_16 ( V_17 ) ;
}
int F_17 ( struct V_14 * V_17 , struct V_27 * V_28 , long V_29 )
{
long V_30 ;
if ( V_17 == NULL )
return - V_31 ;
V_30 = F_18 ( V_17 -> V_21 ,
V_17 -> V_22 != V_23 ,
V_29 ) ;
if ( V_30 < 0 )
return - V_32 ;
V_28 -> V_33 . V_7 = V_17 -> V_22 ;
return 0 ;
}
T_2 F_19 ( const struct V_34 * V_35 , const struct V_36 * V_37 )
{
const struct V_15 * V_16 = & V_37 -> V_16 ;
const struct V_38 * V_39 = & V_37 -> V_39 ;
struct V_14 * V_17 ;
T_2 V_40 = V_41 ;
F_11 ( & V_24 ) ;
F_20 (block, &nlm_blocked, b_list) {
struct V_15 * V_42 = V_17 -> V_20 ;
if ( V_42 -> V_43 != V_16 -> V_43 )
continue;
if ( V_42 -> V_44 != V_16 -> V_44 )
continue;
if ( V_42 -> V_45 . V_46 . V_47 -> V_48 != V_37 -> V_49 )
continue;
if ( ! F_21 ( F_22 ( V_17 -> V_19 ) , V_35 ) )
continue;
if ( F_23 ( F_24 ( V_42 -> V_50 -> V_51 . V_52 -> V_53 ) , V_39 ) != 0 )
continue;
V_17 -> V_22 = V_54 ;
F_25 ( & V_17 -> V_21 ) ;
V_40 = V_54 ;
}
F_13 ( & V_24 ) ;
return V_40 ;
}
void
F_26 ( struct V_1 * V_4 )
{
struct V_55 * V_56 ;
if ( ! V_4 -> V_57 ++ ) {
F_27 ( V_4 ) ;
V_56 = F_28 ( V_58 , V_4 , L_1 , V_4 -> V_59 ) ;
if ( F_29 ( V_56 ) )
F_30 ( V_60 L_2
L_3
L_4 , V_4 -> V_59 , F_31 ( V_56 ) ) ;
}
}
static int
V_58 ( void * V_61 )
{
struct V_1 * V_4 = (struct V_1 * ) V_61 ;
struct V_14 * V_17 ;
struct V_15 * V_16 , * V_62 ;
T_1 V_63 ;
F_32 ( V_64 ) ;
F_33 ( & V_4 -> V_65 ) ;
F_2 () ;
F_34 ( L_5 , V_4 -> V_59 ) ;
V_66:
V_63 = V_4 -> V_67 ;
V_4 -> V_68 = V_69 ;
F_35 ( V_4 ) ;
F_36 ( & V_4 -> V_70 , & V_4 -> V_71 ) ;
F_37 (fl, next, &host->h_reclaim, fl_u.nfs_fl.list) {
F_38 ( & V_16 -> V_45 . V_46 . V_72 ) ;
if ( F_39 () )
continue;
if ( F_40 ( V_4 , V_16 ) != 0 )
continue;
F_41 ( & V_16 -> V_45 . V_46 . V_72 , & V_4 -> V_70 ) ;
if ( V_4 -> V_67 != V_63 ) {
goto V_66;
}
}
V_4 -> V_57 = 0 ;
F_42 ( & V_4 -> V_65 ) ;
F_34 ( L_6 , V_4 -> V_59 ) ;
F_11 ( & V_24 ) ;
F_20 (block, &nlm_blocked, b_list) {
if ( V_17 -> V_19 == V_4 ) {
V_17 -> V_22 = V_73 ;
F_25 ( & V_17 -> V_21 ) ;
}
}
F_13 ( & V_24 ) ;
F_7 ( V_4 ) ;
F_5 () ;
return 0 ;
}
