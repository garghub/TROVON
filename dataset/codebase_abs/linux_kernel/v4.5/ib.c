static void F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_3 (ic, &ib_nodev_conns, ib_node)
F_4 ( V_2 -> V_4 ) ;
F_5 ( & V_3 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned long V_7 ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_3 (ic, &rds_ibdev->conn_list, ib_node)
F_8 ( V_2 -> V_4 ) ;
F_9 ( & V_6 -> V_8 , V_7 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 , * V_13 ;
struct V_5 * V_6 = F_11 ( V_10 ,
struct V_5 , V_14 ) ;
if ( V_6 -> V_15 )
F_12 ( V_6 -> V_15 ) ;
if ( V_6 -> V_16 )
F_12 ( V_6 -> V_16 ) ;
if ( V_6 -> V_17 )
F_13 ( V_6 -> V_17 ) ;
F_14 (i_ipaddr, i_next, &rds_ibdev->ipaddr_list, list) {
F_15 ( & V_12 -> V_18 ) ;
F_16 ( V_12 ) ;
}
F_16 ( V_6 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( F_19 ( & V_6 -> V_19 ) <= 0 ) ;
if ( F_20 ( & V_6 -> V_19 ) )
F_21 ( V_20 , & V_6 -> V_14 ) ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
if ( V_22 -> V_23 != V_24 )
return;
V_6 = F_23 ( sizeof( struct V_5 ) , V_25 ,
F_24 ( V_22 ) ) ;
if ( ! V_6 )
return;
F_25 ( & V_6 -> V_8 ) ;
F_26 ( & V_6 -> V_19 , 1 ) ;
F_27 ( & V_6 -> V_14 , F_10 ) ;
V_6 -> V_26 = V_22 -> V_27 . V_28 ;
V_6 -> V_29 = F_28 ( V_22 -> V_27 . V_29 , V_30 ) ;
V_6 -> V_31 = V_22 -> V_27 . V_32 ? : 32 ;
V_6 -> V_33 = V_22 -> V_27 . V_34 ?
F_29 (unsigned int, (device->attrs.max_mr / 2),
rds_ib_fmr_1m_pool_size) : V_35 ;
V_6 -> V_36 = V_22 -> V_27 . V_34 ?
F_29 (unsigned int, ((device->attrs.max_mr / 2) * RDS_MR_8K_SCALE),
rds_ib_fmr_8k_pool_size) : V_37 ;
V_6 -> V_38 = V_22 -> V_27 . V_39 ;
V_6 -> V_40 = V_22 -> V_27 . V_41 ;
V_6 -> V_42 = V_22 ;
V_6 -> V_17 = F_30 ( V_22 ) ;
if ( F_31 ( V_6 -> V_17 ) ) {
V_6 -> V_17 = NULL ;
goto V_43;
}
V_6 -> V_16 =
F_32 ( V_6 , V_44 ) ;
if ( F_31 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_43;
}
V_6 -> V_15 =
F_32 ( V_6 , V_45 ) ;
if ( F_31 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_43;
}
F_33 ( L_1 ,
V_22 -> V_27 . V_46 , V_6 -> V_26 , V_6 -> V_29 ,
V_6 -> V_31 , V_6 -> V_33 ,
V_6 -> V_36 ) ;
F_34 ( & V_6 -> V_47 ) ;
F_34 ( & V_6 -> V_48 ) ;
F_35 ( & V_49 ) ;
F_36 ( & V_6 -> V_18 , & V_50 ) ;
F_37 ( & V_49 ) ;
F_38 ( & V_6 -> V_19 ) ;
F_39 ( V_22 , & V_51 , V_6 ) ;
F_38 ( & V_6 -> V_19 ) ;
F_1 () ;
V_43:
F_17 ( V_6 ) ;
}
struct V_5 * F_40 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
F_41 () ;
V_6 = F_42 ( V_22 , & V_51 ) ;
if ( V_6 )
F_38 ( & V_6 -> V_19 ) ;
F_43 () ;
return V_6 ;
}
static void F_44 ( struct V_21 * V_22 , void * V_52 )
{
struct V_5 * V_6 = V_52 ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_39 ( V_22 , & V_51 , NULL ) ;
F_35 ( & V_49 ) ;
F_45 ( & V_6 -> V_18 ) ;
F_37 ( & V_49 ) ;
F_46 () ;
F_17 ( V_6 ) ;
F_17 ( V_6 ) ;
}
static int F_47 ( struct V_53 * V_4 ,
void * V_54 )
{
struct V_55 * V_56 = V_54 ;
struct V_1 * V_2 ;
if ( V_4 -> V_57 != & V_58 )
return 0 ;
V_56 -> V_59 = V_4 -> V_60 ;
V_56 -> V_61 = V_4 -> V_62 ;
memset ( & V_56 -> V_63 , 0 , sizeof( V_56 -> V_63 ) ) ;
memset ( & V_56 -> V_64 , 0 , sizeof( V_56 -> V_64 ) ) ;
if ( F_48 ( V_4 ) == V_65 ) {
struct V_5 * V_6 ;
struct V_66 * V_67 ;
V_2 = V_4 -> V_68 ;
V_67 = & V_2 -> V_69 -> V_70 . V_71 . V_67 ;
F_49 ( V_67 , (union V_72 * ) & V_56 -> V_63 ) ;
F_50 ( V_67 , (union V_72 * ) & V_56 -> V_64 ) ;
V_6 = V_2 -> V_6 ;
V_56 -> V_73 = V_2 -> V_74 . V_75 ;
V_56 -> V_76 = V_2 -> V_77 . V_75 ;
V_56 -> V_78 = V_6 -> V_29 ;
F_51 ( V_6 , V_56 ) ;
}
return 1 ;
}
static void F_52 ( struct V_79 * V_80 , unsigned int V_81 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
F_53 ( V_80 , V_81 , V_83 , V_85 ,
F_47 ,
sizeof( struct V_55 ) ) ;
}
static int F_54 ( struct V_86 * V_86 , T_1 V_71 )
{
int V_87 ;
struct V_88 * V_89 ;
struct V_90 sin ;
V_89 = F_55 ( & V_91 , NULL , NULL , V_92 , V_93 ) ;
if ( F_31 ( V_89 ) )
return F_56 ( V_89 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_94 = V_95 ;
sin . V_96 . V_97 = V_71 ;
V_87 = F_57 ( V_89 , (struct V_98 * ) & sin ) ;
if ( V_87 || ! V_89 -> V_22 ||
V_89 -> V_22 -> V_23 != V_24 )
V_87 = - V_99 ;
F_33 ( L_2 ,
& V_71 , V_87 ,
V_89 -> V_22 ? V_89 -> V_22 -> V_23 : - 1 ) ;
F_58 ( V_89 ) ;
return V_87 ;
}
static void F_59 ( void )
{
F_60 ( & V_51 ) ;
F_61 ( V_20 ) ;
}
void F_62 ( void )
{
F_63 ( V_100 , F_52 ) ;
F_59 () ;
F_64 () ;
F_65 () ;
F_66 () ;
F_67 ( & V_58 ) ;
F_68 () ;
}
int F_69 ( void )
{
int V_87 ;
F_34 ( & V_50 ) ;
V_87 = F_70 () ;
if ( V_87 )
goto V_101;
V_87 = F_71 ( & V_51 ) ;
if ( V_87 )
goto V_102;
V_87 = F_72 () ;
if ( V_87 )
goto V_103;
V_87 = F_73 () ;
if ( V_87 )
goto V_104;
V_87 = F_74 ( & V_58 ) ;
if ( V_87 )
goto V_105;
F_75 ( V_100 , F_52 ) ;
goto V_101;
V_105:
F_66 () ;
V_104:
F_65 () ;
V_103:
F_59 () ;
V_102:
F_68 () ;
V_101:
return V_87 ;
}
