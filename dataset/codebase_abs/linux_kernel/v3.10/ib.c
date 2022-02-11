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
if ( V_6 -> V_17 )
F_14 ( V_6 -> V_17 ) ;
F_15 (i_ipaddr, i_next, &rds_ibdev->ipaddr_list, list) {
F_16 ( & V_12 -> V_18 ) ;
F_17 ( V_12 ) ;
}
F_17 ( V_6 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
F_19 ( F_20 ( & V_6 -> V_19 ) <= 0 ) ;
if ( F_21 ( & V_6 -> V_19 ) )
F_22 ( V_20 , & V_6 -> V_14 ) ;
}
static void F_23 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
struct V_23 * V_24 ;
if ( V_22 -> V_25 != V_26 )
return;
V_24 = F_24 ( sizeof *V_24 , V_27 ) ;
if ( ! V_24 )
return;
if ( F_25 ( V_22 , V_24 ) ) {
F_26 ( L_1 , V_22 -> V_28 ) ;
goto V_29;
}
V_6 = F_27 ( sizeof( struct V_5 ) , V_27 ,
F_28 ( V_22 ) ) ;
if ( ! V_6 )
goto V_29;
F_29 ( & V_6 -> V_8 ) ;
F_30 ( & V_6 -> V_19 , 1 ) ;
F_31 ( & V_6 -> V_14 , F_10 ) ;
V_6 -> V_30 = V_24 -> V_31 ;
V_6 -> V_32 = F_32 ( V_24 -> V_32 , V_33 ) ;
V_6 -> V_34 = V_24 -> V_35 ? : 32 ;
V_6 -> V_36 = V_24 -> V_37 ?
F_33 (unsigned int, dev_attr->max_fmr, fmr_pool_size) :
V_38 ;
V_6 -> V_39 = V_24 -> V_40 ;
V_6 -> V_41 = V_24 -> V_42 ;
V_6 -> V_43 = V_22 ;
V_6 -> V_17 = F_34 ( V_22 ) ;
if ( F_35 ( V_6 -> V_17 ) ) {
V_6 -> V_17 = NULL ;
goto V_44;
}
V_6 -> V_16 = F_36 ( V_6 -> V_17 , V_45 ) ;
if ( F_35 ( V_6 -> V_16 ) ) {
V_6 -> V_16 = NULL ;
goto V_44;
}
V_6 -> V_15 = F_37 ( V_6 ) ;
if ( F_35 ( V_6 -> V_15 ) ) {
V_6 -> V_15 = NULL ;
goto V_44;
}
F_38 ( & V_6 -> V_46 ) ;
F_38 ( & V_6 -> V_47 ) ;
F_39 ( & V_48 ) ;
F_40 ( & V_6 -> V_18 , & V_49 ) ;
F_41 ( & V_48 ) ;
F_42 ( & V_6 -> V_19 ) ;
F_43 ( V_22 , & V_50 , V_6 ) ;
F_42 ( & V_6 -> V_19 ) ;
F_1 () ;
V_44:
F_18 ( V_6 ) ;
V_29:
F_17 ( V_24 ) ;
}
struct V_5 * F_44 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
F_45 () ;
V_6 = F_46 ( V_22 , & V_50 ) ;
if ( V_6 )
F_42 ( & V_6 -> V_19 ) ;
F_47 () ;
return V_6 ;
}
static void F_48 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
V_6 = F_46 ( V_22 , & V_50 ) ;
if ( ! V_6 )
return;
F_6 ( V_6 ) ;
F_43 ( V_22 , & V_50 , NULL ) ;
F_39 ( & V_48 ) ;
F_49 ( & V_6 -> V_18 ) ;
F_41 ( & V_48 ) ;
F_50 () ;
F_18 ( V_6 ) ;
F_18 ( V_6 ) ;
}
static int F_51 ( struct V_51 * V_4 ,
void * V_52 )
{
struct V_53 * V_54 = V_52 ;
struct V_1 * V_2 ;
if ( V_4 -> V_55 != & V_56 )
return 0 ;
V_54 -> V_57 = V_4 -> V_58 ;
V_54 -> V_59 = V_4 -> V_60 ;
memset ( & V_54 -> V_61 , 0 , sizeof( V_54 -> V_61 ) ) ;
memset ( & V_54 -> V_62 , 0 , sizeof( V_54 -> V_62 ) ) ;
if ( F_52 ( V_4 ) == V_63 ) {
struct V_5 * V_6 ;
struct V_64 * V_65 ;
V_2 = V_4 -> V_66 ;
V_65 = & V_2 -> V_67 -> V_68 . V_69 . V_65 ;
F_53 ( V_65 , (union V_70 * ) & V_54 -> V_61 ) ;
F_54 ( V_65 , (union V_70 * ) & V_54 -> V_62 ) ;
V_6 = V_2 -> V_6 ;
V_54 -> V_71 = V_2 -> V_72 . V_73 ;
V_54 -> V_74 = V_2 -> V_75 . V_73 ;
V_54 -> V_76 = V_6 -> V_32 ;
F_55 ( V_6 , V_54 ) ;
}
return 1 ;
}
static void F_56 ( struct V_77 * V_78 , unsigned int V_79 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
F_57 ( V_78 , V_79 , V_81 , V_83 ,
F_51 ,
sizeof( struct V_53 ) ) ;
}
static int F_58 ( T_1 V_69 )
{
int V_84 ;
struct V_85 * V_86 ;
struct V_87 sin ;
V_86 = F_59 ( NULL , NULL , V_88 , V_89 ) ;
if ( F_35 ( V_86 ) )
return F_60 ( V_86 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_90 = V_91 ;
sin . V_92 . V_93 = V_69 ;
V_84 = F_61 ( V_86 , (struct V_94 * ) & sin ) ;
if ( V_84 || V_86 -> V_22 -> V_25 != V_26 )
V_84 = - V_95 ;
F_26 ( L_2 ,
& V_69 , V_84 ,
V_86 -> V_22 ? V_86 -> V_22 -> V_25 : - 1 ) ;
F_62 ( V_86 ) ;
return V_84 ;
}
static void F_63 ( void )
{
F_64 ( & V_50 ) ;
F_65 ( V_20 ) ;
}
void F_66 ( void )
{
F_67 ( V_96 , F_56 ) ;
F_63 () ;
F_68 () ;
F_69 () ;
F_70 () ;
F_71 ( & V_56 ) ;
}
int F_72 ( void )
{
int V_84 ;
F_38 ( & V_49 ) ;
V_84 = F_73 ( & V_50 ) ;
if ( V_84 )
goto V_97;
V_84 = F_74 () ;
if ( V_84 )
goto V_98;
V_84 = F_75 () ;
if ( V_84 )
goto V_99;
V_84 = F_76 ( & V_56 ) ;
if ( V_84 )
goto V_100;
F_77 ( V_96 , F_56 ) ;
goto V_97;
V_100:
F_70 () ;
V_99:
F_69 () ;
V_98:
F_63 () ;
V_97:
return V_84 ;
}
