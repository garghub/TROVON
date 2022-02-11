static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_2 -> V_7 != V_8 )
return;
V_6 = F_2 ( sizeof *V_6 , V_9 ) ;
if ( ! V_6 )
return;
if ( F_3 ( V_2 , V_6 ) ) {
F_4 ( L_1 , V_2 -> V_10 ) ;
goto V_11;
}
V_4 = F_2 ( sizeof *V_4 , V_9 ) ;
if ( ! V_4 )
goto V_11;
F_5 ( & V_4 -> V_12 ) ;
V_4 -> V_13 = ! ! ( V_6 -> V_14 & V_15 ) ;
V_4 -> V_16 = V_6 -> V_17 ;
V_4 -> V_18 = F_6 ( V_6 -> V_18 , V_19 ) ;
V_4 -> V_20 = V_2 ;
V_4 -> V_21 = F_7 ( V_2 ) ;
if ( F_8 ( V_4 -> V_21 ) )
goto V_22;
if ( ! V_4 -> V_13 ) {
V_4 -> V_23 = F_9 ( V_4 -> V_21 ,
V_24 |
V_25 |
V_26 ) ;
if ( F_8 ( V_4 -> V_23 ) )
goto V_27;
} else
V_4 -> V_23 = NULL ;
V_4 -> V_28 = F_10 ( V_4 ) ;
if ( F_8 ( V_4 -> V_28 ) ) {
V_4 -> V_28 = NULL ;
goto V_29;
}
F_11 ( & V_4 -> V_30 ) ;
F_11 ( & V_4 -> V_31 ) ;
F_12 ( & V_4 -> V_32 , & V_33 ) ;
F_13 ( V_2 , & V_34 , V_4 ) ;
goto V_11;
V_29:
if ( V_4 -> V_23 )
F_14 ( V_4 -> V_23 ) ;
V_27:
F_15 ( V_4 -> V_21 ) ;
V_22:
F_16 ( V_4 ) ;
V_11:
F_16 ( V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_35 )
{
struct V_3 * V_4 = V_35 ;
struct V_36 * V_37 , * V_38 ;
if ( ! V_4 )
return;
F_18 ( & V_4 -> V_12 ) ;
F_19 (i_cm_id, next, &rds_iwdev->cm_id_list, list) {
F_20 ( & V_37 -> V_32 ) ;
F_16 ( V_37 ) ;
}
F_21 ( & V_4 -> V_12 ) ;
F_22 ( V_4 ) ;
if ( V_4 -> V_28 )
F_23 ( V_4 -> V_28 ) ;
if ( V_4 -> V_23 )
F_14 ( V_4 -> V_23 ) ;
F_15 ( V_4 -> V_21 ) ;
F_20 ( & V_4 -> V_32 ) ;
F_16 ( V_4 ) ;
}
static int F_24 ( struct V_39 * V_40 ,
void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_44 * V_45 ;
if ( V_40 -> V_46 != & V_47 )
return 0 ;
V_43 -> V_48 = V_40 -> V_49 ;
V_43 -> V_50 = V_40 -> V_51 ;
memset ( & V_43 -> V_52 , 0 , sizeof( V_43 -> V_52 ) ) ;
memset ( & V_43 -> V_53 , 0 , sizeof( V_43 -> V_53 ) ) ;
if ( F_25 ( V_40 ) == V_54 ) {
struct V_3 * V_4 ;
struct V_55 * V_56 ;
V_45 = V_40 -> V_57 ;
V_56 = & V_45 -> V_37 -> V_58 . V_59 . V_56 ;
F_26 ( V_56 , (union V_60 * ) & V_43 -> V_52 ) ;
F_27 ( V_56 , (union V_60 * ) & V_43 -> V_53 ) ;
V_4 = F_28 ( V_45 -> V_37 -> V_2 , & V_34 ) ;
V_43 -> V_61 = V_45 -> V_62 . V_63 ;
V_43 -> V_64 = V_45 -> V_65 . V_63 ;
V_43 -> V_66 = V_4 -> V_18 ;
F_29 ( V_4 , V_43 ) ;
}
return 1 ;
}
static void F_30 ( struct V_67 * V_68 , unsigned int V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
F_31 ( V_68 , V_69 , V_71 , V_73 ,
F_24 ,
sizeof( struct V_42 ) ) ;
}
static int F_32 ( struct V_74 * V_74 , T_1 V_59 )
{
int V_75 ;
struct V_76 * V_77 ;
struct V_78 sin ;
V_77 = F_33 ( & V_79 , NULL , NULL , V_80 , V_81 ) ;
if ( F_8 ( V_77 ) )
return F_34 ( V_77 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_82 = V_83 ;
sin . V_84 . V_85 = V_59 ;
V_75 = F_35 ( V_77 , (struct V_86 * ) & sin ) ;
if ( V_75 || ! V_77 -> V_2 ||
V_77 -> V_2 -> V_7 != V_8 )
V_75 = - V_87 ;
F_4 ( L_2 ,
& V_59 , V_75 ,
V_77 -> V_2 ? V_77 -> V_2 -> V_7 : - 1 ) ;
F_36 ( V_77 ) ;
return V_75 ;
}
void F_37 ( void )
{
F_38 ( V_88 , F_30 ) ;
F_39 () ;
F_40 ( & V_34 ) ;
F_41 () ;
F_42 () ;
F_43 ( & V_47 ) ;
}
int F_44 ( void )
{
int V_75 ;
F_11 ( & V_33 ) ;
V_75 = F_45 ( & V_34 ) ;
if ( V_75 )
goto V_89;
V_75 = F_46 () ;
if ( V_75 )
goto V_90;
V_75 = F_47 () ;
if ( V_75 )
goto V_91;
V_75 = F_48 ( & V_47 ) ;
if ( V_75 )
goto V_92;
F_49 ( V_88 , F_30 ) ;
goto V_89;
V_92:
F_42 () ;
V_91:
F_41 () ;
V_90:
F_40 ( & V_34 ) ;
V_89:
return V_75 ;
}
