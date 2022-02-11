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
F_16 ( V_6 -> V_19 ) ;
F_16 ( V_6 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( F_19 ( & V_6 -> V_20 ) == 0 ) ;
if ( F_20 ( & V_6 -> V_20 ) )
F_21 ( V_21 , & V_6 -> V_14 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
if ( V_23 -> V_24 != V_25 )
return;
V_6 = F_23 ( sizeof( struct V_5 ) , V_26 ,
F_24 ( V_23 ) ) ;
if ( ! V_6 )
return;
F_25 ( & V_6 -> V_8 ) ;
F_26 ( & V_6 -> V_20 , 1 ) ;
F_27 ( & V_6 -> V_14 , F_10 ) ;
V_6 -> V_27 = V_23 -> V_28 . V_29 ;
V_6 -> V_30 = F_28 ( V_23 -> V_28 . V_30 , V_31 ) ;
V_6 -> V_32 = ( V_23 -> V_28 . V_33 &
V_34 ) ;
V_6 -> V_35 = ( V_23 -> V_36 && V_23 -> V_37 &&
V_23 -> V_38 && V_23 -> V_39 ) ;
V_6 -> V_40 = ( V_6 -> V_32 && ! V_6 -> V_35 ) ;
V_6 -> V_41 = V_23 -> V_28 . V_42 ? : 32 ;
V_6 -> V_43 = V_23 -> V_28 . V_44 ?
F_29 (unsigned int, (device->attrs.max_mr / 2),
rds_ib_mr_1m_pool_size) : V_45 ;
V_6 -> V_46 = V_23 -> V_28 . V_44 ?
F_29 (unsigned int, ((device->attrs.max_mr / 2) * RDS_MR_8K_SCALE),
rds_ib_mr_8k_pool_size) : V_47 ;
V_6 -> V_48 = V_23 -> V_28 . V_49 ;
V_6 -> V_50 = V_23 -> V_28 . V_51 ;
V_6 -> V_19 = F_30 ( sizeof( int ) * V_23 -> V_52 ,
V_26 ) ;
if ( ! V_6 -> V_19 ) {
F_31 ( L_1 ,
V_53 ) ;
goto V_54;
}
V_6 -> V_55 = V_23 ;
V_6 -> V_17 = F_32 ( V_23 , 0 ) ;
if ( F_33 ( V_6 -> V_17 ) ) {
V_6 -> V_17 = NULL ;
goto V_54;
}
V_6 -> V_16 =
F_34 ( V_6 , V_56 ) ;
if ( F_33 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_54;
}
V_6 -> V_15 =
F_34 ( V_6 , V_57 ) ;
if ( F_33 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_54;
}
F_35 ( L_2 ,
V_23 -> V_28 . V_58 , V_6 -> V_27 , V_6 -> V_30 ,
V_6 -> V_41 , V_6 -> V_43 ,
V_6 -> V_46 ) ;
F_36 ( L_3 ,
V_23 -> V_59 ,
V_6 -> V_40 ? L_4 : L_5 ) ;
F_37 ( & V_6 -> V_60 ) ;
F_37 ( & V_6 -> V_61 ) ;
F_38 ( & V_62 ) ;
F_39 ( & V_6 -> V_18 , & V_63 ) ;
F_40 ( & V_62 ) ;
F_41 ( & V_6 -> V_20 ) ;
F_42 ( V_23 , & V_64 , V_6 ) ;
F_41 ( & V_6 -> V_20 ) ;
F_1 () ;
V_54:
F_17 ( V_6 ) ;
}
struct V_5 * F_43 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
F_44 () ;
V_6 = F_45 ( V_23 , & V_64 ) ;
if ( V_6 )
F_41 ( & V_6 -> V_20 ) ;
F_46 () ;
return V_6 ;
}
static void F_47 ( struct V_22 * V_23 , void * V_65 )
{
struct V_5 * V_6 = V_65 ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_42 ( V_23 , & V_64 , NULL ) ;
F_38 ( & V_62 ) ;
F_48 ( & V_6 -> V_18 ) ;
F_40 ( & V_62 ) ;
F_49 () ;
F_17 ( V_6 ) ;
F_17 ( V_6 ) ;
}
static int F_50 ( struct V_66 * V_4 ,
void * V_67 )
{
struct V_68 * V_69 = V_67 ;
struct V_1 * V_2 ;
if ( V_4 -> V_70 != & V_71 )
return 0 ;
V_69 -> V_72 = V_4 -> V_73 ;
V_69 -> V_74 = V_4 -> V_75 ;
memset ( & V_69 -> V_76 , 0 , sizeof( V_69 -> V_76 ) ) ;
memset ( & V_69 -> V_77 , 0 , sizeof( V_69 -> V_77 ) ) ;
if ( F_51 ( V_4 ) == V_78 ) {
struct V_5 * V_6 ;
struct V_79 * V_80 ;
V_2 = V_4 -> V_81 ;
V_80 = & V_2 -> V_82 -> V_83 . V_84 . V_80 ;
F_52 ( V_80 , (union V_85 * ) & V_69 -> V_76 ) ;
F_53 ( V_80 , (union V_85 * ) & V_69 -> V_77 ) ;
V_6 = V_2 -> V_6 ;
V_69 -> V_86 = V_2 -> V_87 . V_88 ;
V_69 -> V_89 = V_2 -> V_90 . V_88 ;
V_69 -> V_91 = V_6 -> V_30 ;
F_54 ( V_6 , V_69 ) ;
}
return 1 ;
}
static void F_55 ( struct V_92 * V_93 , unsigned int V_94 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
F_56 ( V_93 , V_94 , V_96 , V_98 ,
F_50 ,
sizeof( struct V_68 ) ) ;
}
static int F_57 ( struct V_99 * V_99 , T_1 V_84 )
{
int V_100 ;
struct V_101 * V_102 ;
struct V_103 sin ;
V_102 = F_58 ( & V_104 , NULL , NULL , V_105 , V_106 ) ;
if ( F_33 ( V_102 ) )
return F_59 ( V_102 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_107 = V_108 ;
sin . V_109 . V_110 = V_84 ;
V_100 = F_60 ( V_102 , (struct V_111 * ) & sin ) ;
if ( V_100 || ! V_102 -> V_23 ||
V_102 -> V_23 -> V_24 != V_25 )
V_100 = - V_112 ;
F_35 ( L_6 ,
& V_84 , V_100 ,
V_102 -> V_23 ? V_102 -> V_23 -> V_24 : - 1 ) ;
F_61 ( V_102 ) ;
return V_100 ;
}
static void F_62 ( void )
{
F_63 ( & V_64 ) ;
F_64 ( V_21 ) ;
}
void F_65 ( void )
{
F_66 ( V_113 , F_55 ) ;
F_62 () ;
F_67 () ;
F_68 () ;
F_69 () ;
F_70 ( & V_71 ) ;
F_71 () ;
}
int F_72 ( void )
{
int V_100 ;
F_37 ( & V_63 ) ;
V_100 = F_73 () ;
if ( V_100 )
goto V_114;
V_100 = F_74 ( & V_64 ) ;
if ( V_100 )
goto V_115;
V_100 = F_75 () ;
if ( V_100 )
goto V_116;
V_100 = F_76 () ;
if ( V_100 )
goto V_117;
F_77 ( & V_71 ) ;
F_78 ( V_113 , F_55 ) ;
goto V_114;
V_117:
F_68 () ;
V_116:
F_62 () ;
V_115:
F_71 () ;
V_114:
return V_100 ;
}
