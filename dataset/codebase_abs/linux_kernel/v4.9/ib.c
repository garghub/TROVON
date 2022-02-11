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
V_6 -> V_31 = ( V_22 -> V_27 . V_32 &
V_33 ) ;
V_6 -> V_34 = ( V_22 -> V_35 && V_22 -> V_36 &&
V_22 -> V_37 && V_22 -> V_38 ) ;
V_6 -> V_39 = ( V_6 -> V_31 && ! V_6 -> V_34 ) ;
V_6 -> V_40 = V_22 -> V_27 . V_41 ? : 32 ;
V_6 -> V_42 = V_22 -> V_27 . V_43 ?
F_29 (unsigned int, (device->attrs.max_mr / 2),
rds_ib_mr_1m_pool_size) : V_44 ;
V_6 -> V_45 = V_22 -> V_27 . V_43 ?
F_29 (unsigned int, ((device->attrs.max_mr / 2) * RDS_MR_8K_SCALE),
rds_ib_mr_8k_pool_size) : V_46 ;
V_6 -> V_47 = V_22 -> V_27 . V_48 ;
V_6 -> V_49 = V_22 -> V_27 . V_50 ;
V_6 -> V_51 = V_22 ;
V_6 -> V_17 = F_30 ( V_22 , 0 ) ;
if ( F_31 ( V_6 -> V_17 ) ) {
V_6 -> V_17 = NULL ;
goto V_52;
}
V_6 -> V_16 =
F_32 ( V_6 , V_53 ) ;
if ( F_31 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_52;
}
V_6 -> V_15 =
F_32 ( V_6 , V_54 ) ;
if ( F_31 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_52;
}
F_33 ( L_1 ,
V_22 -> V_27 . V_55 , V_6 -> V_26 , V_6 -> V_29 ,
V_6 -> V_40 , V_6 -> V_42 ,
V_6 -> V_45 ) ;
F_34 ( L_2 ,
V_22 -> V_56 ,
V_6 -> V_39 ? L_3 : L_4 ) ;
F_35 ( & V_6 -> V_57 ) ;
F_35 ( & V_6 -> V_58 ) ;
F_36 ( & V_59 ) ;
F_37 ( & V_6 -> V_18 , & V_60 ) ;
F_38 ( & V_59 ) ;
F_39 ( & V_6 -> V_19 ) ;
F_40 ( V_22 , & V_61 , V_6 ) ;
F_39 ( & V_6 -> V_19 ) ;
F_1 () ;
V_52:
F_17 ( V_6 ) ;
}
struct V_5 * F_41 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
F_42 () ;
V_6 = F_43 ( V_22 , & V_61 ) ;
if ( V_6 )
F_39 ( & V_6 -> V_19 ) ;
F_44 () ;
return V_6 ;
}
static void F_45 ( struct V_21 * V_22 , void * V_62 )
{
struct V_5 * V_6 = V_62 ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_40 ( V_22 , & V_61 , NULL ) ;
F_36 ( & V_59 ) ;
F_46 ( & V_6 -> V_18 ) ;
F_38 ( & V_59 ) ;
F_47 () ;
F_17 ( V_6 ) ;
F_17 ( V_6 ) ;
}
static int F_48 ( struct V_63 * V_4 ,
void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_1 * V_2 ;
if ( V_4 -> V_67 != & V_68 )
return 0 ;
V_66 -> V_69 = V_4 -> V_70 ;
V_66 -> V_71 = V_4 -> V_72 ;
memset ( & V_66 -> V_73 , 0 , sizeof( V_66 -> V_73 ) ) ;
memset ( & V_66 -> V_74 , 0 , sizeof( V_66 -> V_74 ) ) ;
if ( F_49 ( V_4 ) == V_75 ) {
struct V_5 * V_6 ;
struct V_76 * V_77 ;
V_2 = V_4 -> V_78 ;
V_77 = & V_2 -> V_79 -> V_80 . V_81 . V_77 ;
F_50 ( V_77 , (union V_82 * ) & V_66 -> V_73 ) ;
F_51 ( V_77 , (union V_82 * ) & V_66 -> V_74 ) ;
V_6 = V_2 -> V_6 ;
V_66 -> V_83 = V_2 -> V_84 . V_85 ;
V_66 -> V_86 = V_2 -> V_87 . V_85 ;
V_66 -> V_88 = V_6 -> V_29 ;
F_52 ( V_6 , V_66 ) ;
}
return 1 ;
}
static void F_53 ( struct V_89 * V_90 , unsigned int V_91 ,
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
F_54 ( V_90 , V_91 , V_93 , V_95 ,
F_48 ,
sizeof( struct V_65 ) ) ;
}
static int F_55 ( struct V_96 * V_96 , T_1 V_81 )
{
int V_97 ;
struct V_98 * V_99 ;
struct V_100 sin ;
V_99 = F_56 ( & V_101 , NULL , NULL , V_102 , V_103 ) ;
if ( F_31 ( V_99 ) )
return F_57 ( V_99 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_104 = V_105 ;
sin . V_106 . V_107 = V_81 ;
V_97 = F_58 ( V_99 , (struct V_108 * ) & sin ) ;
if ( V_97 || ! V_99 -> V_22 ||
V_99 -> V_22 -> V_23 != V_24 )
V_97 = - V_109 ;
F_33 ( L_5 ,
& V_81 , V_97 ,
V_99 -> V_22 ? V_99 -> V_22 -> V_23 : - 1 ) ;
F_59 ( V_99 ) ;
return V_97 ;
}
static void F_60 ( void )
{
F_61 ( & V_61 ) ;
F_62 ( V_20 ) ;
}
void F_63 ( void )
{
F_64 ( V_110 , F_53 ) ;
F_60 () ;
F_65 () ;
F_66 () ;
F_67 () ;
F_68 ( & V_68 ) ;
F_69 () ;
}
int F_70 ( void )
{
int V_97 ;
F_35 ( & V_60 ) ;
V_97 = F_71 () ;
if ( V_97 )
goto V_111;
V_97 = F_72 ( & V_61 ) ;
if ( V_97 )
goto V_112;
V_97 = F_73 () ;
if ( V_97 )
goto V_113;
V_97 = F_74 () ;
if ( V_97 )
goto V_114;
V_97 = F_75 ( & V_68 ) ;
if ( V_97 )
goto V_115;
F_76 ( V_110 , F_53 ) ;
goto V_111;
V_115:
F_67 () ;
V_114:
F_66 () ;
V_113:
F_60 () ;
V_112:
F_69 () ;
V_111:
return V_97 ;
}
