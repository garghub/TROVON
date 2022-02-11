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
struct V_23 * V_24 ;
if ( V_22 -> V_25 != V_26 )
return;
V_24 = F_23 ( sizeof *V_24 , V_27 ) ;
if ( ! V_24 )
return;
if ( F_24 ( V_22 , V_24 ) ) {
F_25 ( L_1 , V_22 -> V_28 ) ;
goto V_29;
}
V_6 = F_26 ( sizeof( struct V_5 ) , V_27 ,
F_27 ( V_22 ) ) ;
if ( ! V_6 )
goto V_29;
F_28 ( & V_6 -> V_8 ) ;
F_29 ( & V_6 -> V_19 , 1 ) ;
F_30 ( & V_6 -> V_14 , F_10 ) ;
V_6 -> V_30 = V_24 -> V_31 ;
V_6 -> V_32 = F_31 ( V_24 -> V_32 , V_33 ) ;
V_6 -> V_34 = V_24 -> V_35 ? : 32 ;
V_6 -> V_36 = V_24 -> V_37 ?
F_32 (unsigned int, (dev_attr->max_mr / 2),
rds_ib_fmr_1m_pool_size) : V_38 ;
V_6 -> V_39 = V_24 -> V_37 ?
F_32 (unsigned int, ((dev_attr->max_mr / 2) * RDS_MR_8K_SCALE),
rds_ib_fmr_8k_pool_size) : V_40 ;
V_6 -> V_41 = V_24 -> V_42 ;
V_6 -> V_43 = V_24 -> V_44 ;
V_6 -> V_45 = V_22 ;
V_6 -> V_17 = F_33 ( V_22 ) ;
if ( F_34 ( V_6 -> V_17 ) ) {
V_6 -> V_17 = NULL ;
goto V_46;
}
V_6 -> V_16 =
F_35 ( V_6 , V_47 ) ;
if ( F_34 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_46;
}
V_6 -> V_15 =
F_35 ( V_6 , V_48 ) ;
if ( F_34 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_46;
}
F_25 ( L_2 ,
V_24 -> V_49 , V_6 -> V_30 , V_6 -> V_32 ,
V_6 -> V_34 , V_6 -> V_36 ,
V_6 -> V_39 ) ;
F_36 ( & V_6 -> V_50 ) ;
F_36 ( & V_6 -> V_51 ) ;
F_37 ( & V_52 ) ;
F_38 ( & V_6 -> V_18 , & V_53 ) ;
F_39 ( & V_52 ) ;
F_40 ( & V_6 -> V_19 ) ;
F_41 ( V_22 , & V_54 , V_6 ) ;
F_40 ( & V_6 -> V_19 ) ;
F_1 () ;
V_46:
F_17 ( V_6 ) ;
V_29:
F_16 ( V_24 ) ;
}
struct V_5 * F_42 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
F_43 () ;
V_6 = F_44 ( V_22 , & V_54 ) ;
if ( V_6 )
F_40 ( & V_6 -> V_19 ) ;
F_45 () ;
return V_6 ;
}
static void F_46 ( struct V_21 * V_22 , void * V_55 )
{
struct V_5 * V_6 = V_55 ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_41 ( V_22 , & V_54 , NULL ) ;
F_37 ( & V_52 ) ;
F_47 ( & V_6 -> V_18 ) ;
F_39 ( & V_52 ) ;
F_48 () ;
F_17 ( V_6 ) ;
F_17 ( V_6 ) ;
}
static int F_49 ( struct V_56 * V_4 ,
void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_1 * V_2 ;
if ( V_4 -> V_60 != & V_61 )
return 0 ;
V_59 -> V_62 = V_4 -> V_63 ;
V_59 -> V_64 = V_4 -> V_65 ;
memset ( & V_59 -> V_66 , 0 , sizeof( V_59 -> V_66 ) ) ;
memset ( & V_59 -> V_67 , 0 , sizeof( V_59 -> V_67 ) ) ;
if ( F_50 ( V_4 ) == V_68 ) {
struct V_5 * V_6 ;
struct V_69 * V_70 ;
V_2 = V_4 -> V_71 ;
V_70 = & V_2 -> V_72 -> V_73 . V_74 . V_70 ;
F_51 ( V_70 , (union V_75 * ) & V_59 -> V_66 ) ;
F_52 ( V_70 , (union V_75 * ) & V_59 -> V_67 ) ;
V_6 = V_2 -> V_6 ;
V_59 -> V_76 = V_2 -> V_77 . V_78 ;
V_59 -> V_79 = V_2 -> V_80 . V_78 ;
V_59 -> V_81 = V_6 -> V_32 ;
F_53 ( V_6 , V_59 ) ;
}
return 1 ;
}
static void F_54 ( struct V_82 * V_83 , unsigned int V_84 ,
struct V_85 * V_86 ,
struct V_87 * V_88 )
{
F_55 ( V_83 , V_84 , V_86 , V_88 ,
F_49 ,
sizeof( struct V_58 ) ) ;
}
static int F_56 ( struct V_89 * V_89 , T_1 V_74 )
{
int V_90 ;
struct V_91 * V_92 ;
struct V_93 sin ;
V_92 = F_57 ( & V_94 , NULL , NULL , V_95 , V_96 ) ;
if ( F_34 ( V_92 ) )
return F_58 ( V_92 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_97 = V_98 ;
sin . V_99 . V_100 = V_74 ;
V_90 = F_59 ( V_92 , (struct V_101 * ) & sin ) ;
if ( V_90 || ! V_92 -> V_22 ||
V_92 -> V_22 -> V_25 != V_26 )
V_90 = - V_102 ;
F_25 ( L_3 ,
& V_74 , V_90 ,
V_92 -> V_22 ? V_92 -> V_22 -> V_25 : - 1 ) ;
F_60 ( V_92 ) ;
return V_90 ;
}
static void F_61 ( void )
{
F_62 ( & V_54 ) ;
F_63 ( V_20 ) ;
}
void F_64 ( void )
{
F_65 ( V_103 , F_54 ) ;
F_61 () ;
F_66 () ;
F_67 () ;
F_68 () ;
F_69 ( & V_61 ) ;
F_70 () ;
}
int F_71 ( void )
{
int V_90 ;
F_36 ( & V_53 ) ;
V_90 = F_72 () ;
if ( V_90 )
goto V_104;
V_90 = F_73 ( & V_54 ) ;
if ( V_90 )
goto V_105;
V_90 = F_74 () ;
if ( V_90 )
goto V_106;
V_90 = F_75 () ;
if ( V_90 )
goto V_107;
V_90 = F_76 ( & V_61 ) ;
if ( V_90 )
goto V_108;
F_77 ( V_103 , F_54 ) ;
goto V_104;
V_108:
F_68 () ;
V_107:
F_67 () ;
V_106:
F_61 () ;
V_105:
F_70 () ;
V_104:
return V_90 ;
}
