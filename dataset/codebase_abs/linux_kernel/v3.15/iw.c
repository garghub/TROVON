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
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_37 ;
V_4 = F_18 ( V_2 , & V_34 ) ;
if ( ! V_4 )
return;
F_19 ( & V_4 -> V_12 ) ;
F_20 (i_cm_id, next, &rds_iwdev->cm_id_list, list) {
F_21 ( & V_36 -> V_32 ) ;
F_16 ( V_36 ) ;
}
F_22 ( & V_4 -> V_12 ) ;
F_23 ( V_4 ) ;
if ( V_4 -> V_28 )
F_24 ( V_4 -> V_28 ) ;
if ( V_4 -> V_23 )
F_14 ( V_4 -> V_23 ) ;
while ( F_15 ( V_4 -> V_21 ) ) {
F_4 ( L_2 , V_4 -> V_21 ) ;
F_25 ( 1 ) ;
}
F_21 ( & V_4 -> V_32 ) ;
F_16 ( V_4 ) ;
}
static int F_26 ( struct V_38 * V_39 ,
void * V_40 )
{
struct V_41 * V_42 = V_40 ;
struct V_43 * V_44 ;
if ( V_39 -> V_45 != & V_46 )
return 0 ;
V_42 -> V_47 = V_39 -> V_48 ;
V_42 -> V_49 = V_39 -> V_50 ;
memset ( & V_42 -> V_51 , 0 , sizeof( V_42 -> V_51 ) ) ;
memset ( & V_42 -> V_52 , 0 , sizeof( V_42 -> V_52 ) ) ;
if ( F_27 ( V_39 ) == V_53 ) {
struct V_3 * V_4 ;
struct V_54 * V_55 ;
V_44 = V_39 -> V_56 ;
V_55 = & V_44 -> V_36 -> V_57 . V_58 . V_55 ;
F_28 ( V_55 , (union V_59 * ) & V_42 -> V_51 ) ;
F_29 ( V_55 , (union V_59 * ) & V_42 -> V_52 ) ;
V_4 = F_18 ( V_44 -> V_36 -> V_2 , & V_34 ) ;
V_42 -> V_60 = V_44 -> V_61 . V_62 ;
V_42 -> V_63 = V_44 -> V_64 . V_62 ;
V_42 -> V_65 = V_4 -> V_18 ;
F_30 ( V_4 , V_42 ) ;
}
return 1 ;
}
static void F_31 ( struct V_66 * V_67 , unsigned int V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
F_32 ( V_67 , V_68 , V_70 , V_72 ,
F_26 ,
sizeof( struct V_41 ) ) ;
}
static int F_33 ( T_1 V_58 )
{
int V_73 ;
struct V_74 * V_75 ;
struct V_76 sin ;
V_75 = F_34 ( NULL , NULL , V_77 , V_78 ) ;
if ( F_8 ( V_75 ) )
return F_35 ( V_75 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_79 = V_80 ;
sin . V_81 . V_82 = V_58 ;
V_73 = F_36 ( V_75 , (struct V_83 * ) & sin ) ;
if ( V_73 || ! V_75 -> V_2 ||
V_75 -> V_2 -> V_7 != V_8 )
V_73 = - V_84 ;
F_4 ( L_3 ,
& V_58 , V_73 ,
V_75 -> V_2 ? V_75 -> V_2 -> V_7 : - 1 ) ;
F_37 ( V_75 ) ;
return V_73 ;
}
void F_38 ( void )
{
F_39 ( V_85 , F_31 ) ;
F_40 () ;
F_41 ( & V_34 ) ;
F_42 () ;
F_43 () ;
F_44 ( & V_46 ) ;
}
int F_45 ( void )
{
int V_73 ;
F_11 ( & V_33 ) ;
V_73 = F_46 ( & V_34 ) ;
if ( V_73 )
goto V_86;
V_73 = F_47 () ;
if ( V_73 )
goto V_87;
V_73 = F_48 () ;
if ( V_73 )
goto V_88;
V_73 = F_49 ( & V_46 ) ;
if ( V_73 )
goto V_89;
F_50 ( V_85 , F_31 ) ;
goto V_86;
V_89:
F_43 () ;
V_88:
F_42 () ;
V_87:
F_41 ( & V_34 ) ;
V_86:
return V_73 ;
}
