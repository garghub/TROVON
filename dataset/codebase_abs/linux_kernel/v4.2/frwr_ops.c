int
F_1 ( void )
{
V_1 = F_2 ( L_1 ,
V_2 , 0 ) ;
return ! V_1 ? - V_3 : 0 ;
}
void
F_3 ( void )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return;
V_5 = V_1 ;
V_1 = NULL ;
F_4 ( V_5 ) ;
}
static void
F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 , struct V_8 ,
V_9 . V_10 . V_11 ) ;
struct V_12 * V_13 = V_9 -> V_9 . V_10 . V_14 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
if ( F_7 ( V_9 -> V_9 . V_10 . V_21 ) )
goto V_22;
V_9 -> V_9 . V_10 . V_21 = F_8 ( V_19 , V_15 ) ;
if ( F_9 ( V_9 -> V_9 . V_10 . V_21 ) )
goto V_22;
F_10 ( L_2 , V_23 , V_9 ) ;
V_9 -> V_9 . V_10 . V_24 = V_25 ;
F_11 ( V_13 , V_9 ) ;
return;
V_22:
F_12 ( L_3 ,
V_23 , V_9 ) ;
}
static void
F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_9 -> V_9 . V_10 . V_11 , F_5 ) ;
F_15 ( V_1 , & V_9 -> V_9 . V_10 . V_11 ) ;
}
static int
F_16 ( struct V_8 * V_9 , struct V_18 * V_19 , struct V_26 * V_27 ,
unsigned int V_15 )
{
struct V_28 * V_29 = & V_9 -> V_9 . V_10 ;
int V_30 ;
V_29 -> V_21 = F_8 ( V_19 , V_15 ) ;
if ( F_9 ( V_29 -> V_21 ) )
goto V_31;
V_29 -> V_32 = F_17 ( V_27 , V_15 ) ;
if ( F_9 ( V_29 -> V_32 ) )
goto V_33;
return 0 ;
V_31:
V_30 = F_18 ( V_29 -> V_21 ) ;
F_10 ( L_4 ,
V_23 , V_30 ) ;
return V_30 ;
V_33:
V_30 = F_18 ( V_29 -> V_32 ) ;
F_10 ( L_5 ,
V_23 , V_30 ) ;
F_7 ( V_29 -> V_21 ) ;
return V_30 ;
}
static void
F_19 ( struct V_8 * V_9 )
{
int V_30 ;
V_30 = F_7 ( V_9 -> V_9 . V_10 . V_21 ) ;
if ( V_30 )
F_10 ( L_6 ,
V_23 , V_30 ) ;
F_20 ( V_9 -> V_9 . V_10 . V_32 ) ;
}
static int
F_21 ( struct V_34 * V_35 , struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = & V_35 -> V_42 ;
int V_15 , V_43 ;
V_35 -> V_17 =
F_22 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
devattr->max_fast_reg_page_list_len) ;
F_10 ( L_7 ,
V_23 , V_35 -> V_17 ) ;
V_15 = 7 ;
if ( V_35 -> V_17 < V_44 ) {
V_43 = V_44 - V_35 -> V_17 ;
do {
V_15 += 2 ;
V_43 -= V_35 -> V_17 ;
} while ( V_43 > 0 );
}
V_37 -> V_45 . V_46 . V_47 *= V_15 ;
if ( V_37 -> V_45 . V_46 . V_47 > V_41 -> V_48 ) {
V_39 -> V_49 = V_41 -> V_48 / V_15 ;
if ( ! V_39 -> V_49 )
return - V_50 ;
V_37 -> V_45 . V_46 . V_47 = V_39 -> V_49 *
V_15 ;
}
return 0 ;
}
static T_1
F_23 ( struct V_12 * V_13 )
{
struct V_34 * V_35 = & V_13 -> V_16 ;
return F_22 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * ia->ri_max_frmr_depth) ;
}
static void
F_24 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
if ( F_25 ( V_52 -> V_53 == V_54 ) )
return;
V_9 = (struct V_8 * ) ( unsigned long ) V_52 -> V_55 ;
F_12 ( L_8 ,
V_23 , V_9 , F_26 ( V_52 -> V_53 ) , V_52 -> V_53 ) ;
V_9 -> V_9 . V_10 . V_24 = V_56 ;
}
static int
F_27 ( struct V_12 * V_13 )
{
struct V_57 * V_58 = & V_13 -> V_59 ;
struct V_26 * V_27 = V_13 -> V_16 . V_60 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
int V_61 ;
F_28 ( & V_58 -> V_62 ) ;
F_29 ( & V_58 -> V_63 ) ;
F_29 ( & V_58 -> V_64 ) ;
V_61 = F_30 ( int , V_44 / V_15 , 1 ) ;
V_61 += 2 ;
V_61 *= V_58 -> V_65 ;
F_10 ( L_9 , V_23 , V_61 ) ;
while ( V_61 -- ) {
struct V_8 * V_9 ;
int V_30 ;
V_9 = F_31 ( sizeof( * V_9 ) , V_66 ) ;
if ( ! V_9 )
return - V_3 ;
V_30 = F_16 ( V_9 , V_19 , V_27 , V_15 ) ;
if ( V_30 ) {
F_32 ( V_9 ) ;
return V_30 ;
}
F_33 ( & V_9 -> V_67 , & V_58 -> V_63 ) ;
F_33 ( & V_9 -> V_68 , & V_58 -> V_64 ) ;
V_9 -> V_69 = F_24 ;
V_9 -> V_9 . V_10 . V_14 = V_13 ;
}
return 0 ;
}
static int
F_34 ( struct V_12 * V_13 , struct V_70 * V_71 ,
int V_72 , bool V_73 )
{
struct V_34 * V_35 = & V_13 -> V_16 ;
struct V_26 * V_27 = V_35 -> V_60 ;
enum V_74 V_75 = F_35 ( V_73 ) ;
struct V_70 * V_76 = V_71 ;
struct V_8 * V_77 ;
struct V_28 * V_10 ;
struct V_78 * V_79 ;
struct V_80 V_81 , * V_82 ;
T_2 V_83 ;
int V_84 , V_85 ;
int V_61 , V_30 ;
int V_86 ;
T_3 V_87 ;
int V_88 ;
V_77 = V_76 -> V_89 ;
V_76 -> V_89 = NULL ;
do {
if ( V_77 )
F_13 ( V_77 ) ;
V_77 = F_36 ( V_13 ) ;
if ( ! V_77 )
return - V_3 ;
} while ( V_77 -> V_9 . V_10 . V_24 != V_25 );
V_10 = & V_77 -> V_9 . V_10 ;
V_10 -> V_24 = V_90 ;
V_85 = F_37 ( V_76 -> V_91 ) ;
V_76 -> V_91 -= V_85 ;
V_76 -> V_92 += V_85 ;
V_84 = - V_85 ;
if ( V_72 > V_35 -> V_17 )
V_72 = V_35 -> V_17 ;
for ( V_88 = V_61 = 0 ; V_61 < V_72 ; ) {
F_38 ( V_27 , V_71 , V_75 ) ;
V_87 = V_71 -> V_93 ;
for ( V_86 = V_71 -> V_92 ; V_86 > 0 ; V_86 -= V_94 ) {
V_10 -> V_32 -> V_95 [ V_88 ++ ] = V_87 ;
V_87 += V_94 ;
}
V_84 += V_71 -> V_92 ;
++ V_71 ;
++ V_61 ;
if ( ( V_61 < V_72 && F_37 ( V_71 -> V_91 ) ) ||
F_37 ( ( V_71 - 1 ) -> V_91 + ( V_71 - 1 ) -> V_92 ) )
break;
}
F_10 ( L_10 ,
V_23 , V_77 , V_61 , V_84 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_55 = ( unsigned long ) ( void * ) V_77 ;
V_81 . V_96 = V_97 ;
V_81 . V_98 . V_99 . V_100 = V_76 -> V_93 + V_85 ;
V_81 . V_98 . V_99 . V_95 = V_10 -> V_32 ;
V_81 . V_98 . V_99 . V_101 = V_102 ;
V_81 . V_98 . V_99 . V_103 = V_88 ;
V_81 . V_98 . V_99 . V_104 = V_84 ;
V_81 . V_98 . V_99 . V_105 = V_73 ?
V_106 | V_107 :
V_108 ;
V_79 = V_10 -> V_21 ;
V_83 = ( T_2 ) ( V_79 -> V_109 & 0x000000FF ) ;
F_39 ( V_79 , ++ V_83 ) ;
V_81 . V_98 . V_99 . V_109 = V_79 -> V_109 ;
F_40 ( & V_13 -> V_110 ) ;
V_30 = F_41 ( V_35 -> V_111 -> V_112 , & V_81 , & V_82 ) ;
if ( V_30 )
goto V_113;
V_76 -> V_89 = V_77 ;
V_76 -> V_114 = V_79 -> V_109 ;
V_76 -> V_115 = V_76 -> V_93 + V_85 ;
V_76 -> V_116 = V_61 ;
V_76 -> V_92 = V_84 ;
return V_61 ;
V_113:
F_10 ( L_11 , V_23 , V_30 ) ;
while ( V_61 -- )
F_42 ( V_27 , -- V_71 ) ;
F_13 ( V_77 ) ;
return V_30 ;
}
static int
F_43 ( struct V_12 * V_13 , struct V_70 * V_71 )
{
struct V_70 * V_76 = V_71 ;
struct V_34 * V_35 = & V_13 -> V_16 ;
struct V_8 * V_77 = V_76 -> V_89 ;
struct V_80 V_117 , * V_82 ;
int V_30 , V_72 = V_71 -> V_116 ;
F_10 ( L_12 , V_23 , V_77 ) ;
V_76 -> V_89 = NULL ;
V_77 -> V_9 . V_10 . V_24 = V_25 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_55 = ( unsigned long ) ( void * ) V_77 ;
V_117 . V_96 = V_118 ;
V_117 . V_119 . V_120 = V_77 -> V_9 . V_10 . V_21 -> V_109 ;
F_40 ( & V_13 -> V_110 ) ;
while ( V_76 -> V_116 -- )
F_42 ( V_35 -> V_60 , V_71 ++ ) ;
F_44 ( & V_35 -> V_121 ) ;
V_30 = F_41 ( V_35 -> V_111 -> V_112 , & V_117 , & V_82 ) ;
F_45 ( & V_35 -> V_121 ) ;
if ( V_30 )
goto V_122;
F_11 ( V_13 , V_77 ) ;
return V_72 ;
V_122:
F_10 ( L_11 , V_23 , V_30 ) ;
F_13 ( V_77 ) ;
return V_72 ;
}
static void
F_46 ( struct V_57 * V_58 )
{
struct V_8 * V_9 ;
F_47 ( V_1 ) ;
while ( ! F_48 ( & V_58 -> V_64 ) ) {
V_9 = F_49 ( V_58 -> V_64 . V_123 , struct V_8 , V_68 ) ;
F_50 ( & V_9 -> V_68 ) ;
F_19 ( V_9 ) ;
F_32 ( V_9 ) ;
}
}
