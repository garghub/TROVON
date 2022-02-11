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
F_13 ( V_6 -> V_16 ) ;
F_14 (i_ipaddr, i_next, &rds_ibdev->ipaddr_list, list) {
F_15 ( & V_12 -> V_17 ) ;
F_16 ( V_12 ) ;
}
F_16 ( V_6 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( F_19 ( & V_6 -> V_18 ) <= 0 ) ;
if ( F_20 ( & V_6 -> V_18 ) )
F_21 ( V_19 , & V_6 -> V_14 ) ;
}
static void F_22 ( struct V_20 * V_21 )
{
struct V_5 * V_6 ;
struct V_22 * V_23 ;
if ( V_21 -> V_24 != V_25 )
return;
V_23 = F_23 ( sizeof *V_23 , V_26 ) ;
if ( ! V_23 )
return;
if ( F_24 ( V_21 , V_23 ) ) {
F_25 ( L_1 , V_21 -> V_27 ) ;
goto V_28;
}
V_6 = F_26 ( sizeof( struct V_5 ) , V_26 ,
F_27 ( V_21 ) ) ;
if ( ! V_6 )
goto V_28;
F_28 ( & V_6 -> V_8 ) ;
F_29 ( & V_6 -> V_18 , 1 ) ;
F_30 ( & V_6 -> V_14 , F_10 ) ;
V_6 -> V_29 = V_23 -> V_30 ;
V_6 -> V_31 = F_31 ( V_23 -> V_31 , V_32 ) ;
V_6 -> V_33 = V_23 -> V_34 ? : 32 ;
V_6 -> V_35 = V_23 -> V_36 ?
F_32 (unsigned int, dev_attr->max_fmr, fmr_pool_size) :
V_37 ;
V_6 -> V_38 = V_23 -> V_39 ;
V_6 -> V_40 = V_23 -> V_41 ;
V_6 -> V_42 = V_21 ;
V_6 -> V_16 = F_33 ( V_21 ) ;
if ( F_34 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_43;
}
V_6 -> V_15 = F_35 ( V_6 ) ;
if ( F_34 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_43;
}
F_36 ( & V_6 -> V_44 ) ;
F_36 ( & V_6 -> V_45 ) ;
F_37 ( & V_46 ) ;
F_38 ( & V_6 -> V_17 , & V_47 ) ;
F_39 ( & V_46 ) ;
F_40 ( & V_6 -> V_18 ) ;
F_41 ( V_21 , & V_48 , V_6 ) ;
F_40 ( & V_6 -> V_18 ) ;
F_1 () ;
V_43:
F_17 ( V_6 ) ;
V_28:
F_16 ( V_23 ) ;
}
struct V_5 * F_42 ( struct V_20 * V_21 )
{
struct V_5 * V_6 ;
F_43 () ;
V_6 = F_44 ( V_21 , & V_48 ) ;
if ( V_6 )
F_40 ( & V_6 -> V_18 ) ;
F_45 () ;
return V_6 ;
}
static void F_46 ( struct V_20 * V_21 , void * V_49 )
{
struct V_5 * V_6 = V_49 ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_41 ( V_21 , & V_48 , NULL ) ;
F_37 ( & V_46 ) ;
F_47 ( & V_6 -> V_17 ) ;
F_39 ( & V_46 ) ;
F_48 () ;
F_17 ( V_6 ) ;
F_17 ( V_6 ) ;
}
static int F_49 ( struct V_50 * V_4 ,
void * V_51 )
{
struct V_52 * V_53 = V_51 ;
struct V_1 * V_2 ;
if ( V_4 -> V_54 != & V_55 )
return 0 ;
V_53 -> V_56 = V_4 -> V_57 ;
V_53 -> V_58 = V_4 -> V_59 ;
memset ( & V_53 -> V_60 , 0 , sizeof( V_53 -> V_60 ) ) ;
memset ( & V_53 -> V_61 , 0 , sizeof( V_53 -> V_61 ) ) ;
if ( F_50 ( V_4 ) == V_62 ) {
struct V_5 * V_6 ;
struct V_63 * V_64 ;
V_2 = V_4 -> V_65 ;
V_64 = & V_2 -> V_66 -> V_67 . V_68 . V_64 ;
F_51 ( V_64 , (union V_69 * ) & V_53 -> V_60 ) ;
F_52 ( V_64 , (union V_69 * ) & V_53 -> V_61 ) ;
V_6 = V_2 -> V_6 ;
V_53 -> V_70 = V_2 -> V_71 . V_72 ;
V_53 -> V_73 = V_2 -> V_74 . V_72 ;
V_53 -> V_75 = V_6 -> V_31 ;
F_53 ( V_6 , V_53 ) ;
}
return 1 ;
}
static void F_54 ( struct V_76 * V_77 , unsigned int V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
F_55 ( V_77 , V_78 , V_80 , V_82 ,
F_49 ,
sizeof( struct V_52 ) ) ;
}
static int F_56 ( struct V_83 * V_83 , T_1 V_68 )
{
int V_84 ;
struct V_85 * V_86 ;
struct V_87 sin ;
V_86 = F_57 ( NULL , NULL , V_88 , V_89 ) ;
if ( F_34 ( V_86 ) )
return F_58 ( V_86 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_90 = V_91 ;
sin . V_92 . V_93 = V_68 ;
V_84 = F_59 ( V_86 , (struct V_94 * ) & sin ) ;
if ( V_84 || ! V_86 -> V_21 ||
V_86 -> V_21 -> V_24 != V_25 )
V_84 = - V_95 ;
F_25 ( L_2 ,
& V_68 , V_84 ,
V_86 -> V_21 ? V_86 -> V_21 -> V_24 : - 1 ) ;
F_60 ( V_86 ) ;
return V_84 ;
}
static void F_61 ( void )
{
F_62 ( & V_48 ) ;
F_63 ( V_19 ) ;
}
void F_64 ( void )
{
F_65 ( V_96 , F_54 ) ;
F_61 () ;
F_66 () ;
F_67 () ;
F_68 () ;
F_69 ( & V_55 ) ;
F_70 () ;
}
int F_71 ( void )
{
int V_84 ;
F_36 ( & V_47 ) ;
V_84 = F_72 () ;
if ( V_84 )
goto V_97;
V_84 = F_73 ( & V_48 ) ;
if ( V_84 )
goto V_98;
V_84 = F_74 () ;
if ( V_84 )
goto V_99;
V_84 = F_75 () ;
if ( V_84 )
goto V_100;
V_84 = F_76 ( & V_55 ) ;
if ( V_84 )
goto V_101;
F_77 ( V_96 , F_54 ) ;
goto V_97;
V_101:
F_68 () ;
V_100:
F_67 () ;
V_99:
F_61 () ;
V_98:
F_70 () ;
V_97:
return V_84 ;
}
