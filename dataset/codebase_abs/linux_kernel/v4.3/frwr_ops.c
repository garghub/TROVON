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
V_9 -> V_9 . V_10 . V_21 = F_8 ( V_19 , V_23 , V_15 ) ;
if ( F_9 ( V_9 -> V_9 . V_10 . V_21 ) )
goto V_22;
F_10 ( L_2 , V_24 , V_9 ) ;
V_9 -> V_9 . V_10 . V_25 = V_26 ;
F_11 ( V_13 , V_9 ) ;
return;
V_22:
F_12 ( L_3 ,
V_24 , V_9 ) ;
}
static void
F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_9 -> V_9 . V_10 . V_11 , F_5 ) ;
F_15 ( V_1 , & V_9 -> V_9 . V_10 . V_11 ) ;
}
static int
F_16 ( struct V_8 * V_9 , struct V_18 * V_19 , struct V_27 * V_28 ,
unsigned int V_15 )
{
struct V_29 * V_30 = & V_9 -> V_9 . V_10 ;
int V_31 ;
V_30 -> V_21 = F_8 ( V_19 , V_23 , V_15 ) ;
if ( F_9 ( V_30 -> V_21 ) )
goto V_32;
V_30 -> V_33 = F_17 ( V_28 , V_15 ) ;
if ( F_9 ( V_30 -> V_33 ) )
goto V_34;
return 0 ;
V_32:
V_31 = F_18 ( V_30 -> V_21 ) ;
F_10 ( L_4 ,
V_24 , V_31 ) ;
return V_31 ;
V_34:
V_31 = F_18 ( V_30 -> V_33 ) ;
F_10 ( L_5 ,
V_24 , V_31 ) ;
F_7 ( V_30 -> V_21 ) ;
return V_31 ;
}
static void
F_19 ( struct V_8 * V_9 )
{
int V_31 ;
V_31 = F_7 ( V_9 -> V_9 . V_10 . V_21 ) ;
if ( V_31 )
F_10 ( L_6 ,
V_24 , V_31 ) ;
F_20 ( V_9 -> V_9 . V_10 . V_33 ) ;
}
static int
F_21 ( struct V_35 * V_36 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_36 -> V_43 ;
int V_15 , V_44 ;
V_36 -> V_17 =
F_22 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
devattr->max_fast_reg_page_list_len) ;
F_10 ( L_7 ,
V_24 , V_36 -> V_17 ) ;
V_15 = 7 ;
if ( V_36 -> V_17 < V_45 ) {
V_44 = V_45 - V_36 -> V_17 ;
do {
V_15 += 2 ;
V_44 -= V_36 -> V_17 ;
} while ( V_44 > 0 );
}
V_38 -> V_46 . V_47 . V_48 *= V_15 ;
if ( V_38 -> V_46 . V_47 . V_48 > V_42 -> V_49 ) {
V_40 -> V_50 = V_42 -> V_49 / V_15 ;
if ( ! V_40 -> V_50 )
return - V_51 ;
V_38 -> V_46 . V_47 . V_48 = V_40 -> V_50 *
V_15 ;
}
return 0 ;
}
static T_1
F_23 ( struct V_12 * V_13 )
{
struct V_35 * V_36 = & V_13 -> V_16 ;
return F_22 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * ia->ri_max_frmr_depth) ;
}
static void
F_24 ( struct V_52 * V_53 )
{
struct V_8 * V_9 ;
if ( F_25 ( V_53 -> V_54 == V_55 ) )
return;
V_9 = (struct V_8 * ) ( unsigned long ) V_53 -> V_56 ;
F_12 ( L_8 ,
V_24 , V_9 , F_26 ( V_53 -> V_54 ) , V_53 -> V_54 ) ;
V_9 -> V_9 . V_10 . V_25 = V_57 ;
}
static int
F_27 ( struct V_12 * V_13 )
{
struct V_58 * V_59 = & V_13 -> V_60 ;
struct V_27 * V_28 = V_13 -> V_16 . V_61 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
int V_62 ;
F_28 ( & V_59 -> V_63 ) ;
F_29 ( & V_59 -> V_64 ) ;
F_29 ( & V_59 -> V_65 ) ;
V_62 = F_30 ( int , V_45 / V_15 , 1 ) ;
V_62 += 2 ;
V_62 *= V_59 -> V_66 ;
F_10 ( L_9 , V_24 , V_62 ) ;
while ( V_62 -- ) {
struct V_8 * V_9 ;
int V_31 ;
V_9 = F_31 ( sizeof( * V_9 ) , V_67 ) ;
if ( ! V_9 )
return - V_3 ;
V_31 = F_16 ( V_9 , V_19 , V_28 , V_15 ) ;
if ( V_31 ) {
F_32 ( V_9 ) ;
return V_31 ;
}
F_33 ( & V_9 -> V_68 , & V_59 -> V_64 ) ;
F_33 ( & V_9 -> V_69 , & V_59 -> V_65 ) ;
V_9 -> V_70 = F_24 ;
V_9 -> V_9 . V_10 . V_14 = V_13 ;
}
return 0 ;
}
static int
F_34 ( struct V_12 * V_13 , struct V_71 * V_72 ,
int V_73 , bool V_74 )
{
struct V_35 * V_36 = & V_13 -> V_16 ;
struct V_27 * V_28 = V_36 -> V_61 ;
enum V_75 V_76 = F_35 ( V_74 ) ;
struct V_71 * V_77 = V_72 ;
struct V_8 * V_78 ;
struct V_29 * V_10 ;
struct V_79 * V_80 ;
struct V_81 V_82 , * V_83 ;
T_2 V_84 ;
int V_85 , V_86 ;
int V_62 , V_31 ;
int V_87 ;
T_3 V_88 ;
int V_89 ;
V_78 = V_77 -> V_90 ;
V_77 -> V_90 = NULL ;
do {
if ( V_78 )
F_13 ( V_78 ) ;
V_78 = F_36 ( V_13 ) ;
if ( ! V_78 )
return - V_3 ;
} while ( V_78 -> V_9 . V_10 . V_25 != V_26 );
V_10 = & V_78 -> V_9 . V_10 ;
V_10 -> V_25 = V_91 ;
V_86 = F_37 ( V_77 -> V_92 ) ;
V_77 -> V_92 -= V_86 ;
V_77 -> V_93 += V_86 ;
V_85 = - V_86 ;
if ( V_73 > V_36 -> V_17 )
V_73 = V_36 -> V_17 ;
for ( V_89 = V_62 = 0 ; V_62 < V_73 ; ) {
F_38 ( V_28 , V_72 , V_76 ) ;
V_88 = V_72 -> V_94 ;
for ( V_87 = V_72 -> V_93 ; V_87 > 0 ; V_87 -= V_95 ) {
V_10 -> V_33 -> V_96 [ V_89 ++ ] = V_88 ;
V_88 += V_95 ;
}
V_85 += V_72 -> V_93 ;
++ V_72 ;
++ V_62 ;
if ( ( V_62 < V_73 && F_37 ( V_72 -> V_92 ) ) ||
F_37 ( ( V_72 - 1 ) -> V_92 + ( V_72 - 1 ) -> V_93 ) )
break;
}
F_10 ( L_10 ,
V_24 , V_78 , V_62 , V_85 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_56 = ( unsigned long ) ( void * ) V_78 ;
V_82 . V_97 = V_98 ;
V_82 . V_99 . V_100 . V_101 = V_77 -> V_94 + V_86 ;
V_82 . V_99 . V_100 . V_96 = V_10 -> V_33 ;
V_82 . V_99 . V_100 . V_102 = V_103 ;
V_82 . V_99 . V_100 . V_104 = V_89 ;
V_82 . V_99 . V_100 . V_105 = V_85 ;
V_82 . V_99 . V_100 . V_106 = V_74 ?
V_107 | V_108 :
V_109 ;
V_80 = V_10 -> V_21 ;
V_84 = ( T_2 ) ( V_80 -> V_110 & 0x000000FF ) ;
F_39 ( V_80 , ++ V_84 ) ;
V_82 . V_99 . V_100 . V_110 = V_80 -> V_110 ;
F_40 ( & V_13 -> V_111 ) ;
V_31 = F_41 ( V_36 -> V_112 -> V_113 , & V_82 , & V_83 ) ;
if ( V_31 )
goto V_114;
V_77 -> V_90 = V_78 ;
V_77 -> V_115 = V_80 -> V_110 ;
V_77 -> V_116 = V_77 -> V_94 + V_86 ;
V_77 -> V_117 = V_62 ;
V_77 -> V_93 = V_85 ;
return V_62 ;
V_114:
F_10 ( L_11 , V_24 , V_31 ) ;
while ( V_62 -- )
F_42 ( V_28 , -- V_72 ) ;
F_13 ( V_78 ) ;
return V_31 ;
}
static int
F_43 ( struct V_12 * V_13 , struct V_71 * V_72 )
{
struct V_71 * V_77 = V_72 ;
struct V_35 * V_36 = & V_13 -> V_16 ;
struct V_8 * V_78 = V_77 -> V_90 ;
struct V_81 V_118 , * V_83 ;
int V_31 , V_73 = V_72 -> V_117 ;
F_10 ( L_12 , V_24 , V_78 ) ;
V_77 -> V_90 = NULL ;
V_78 -> V_9 . V_10 . V_25 = V_26 ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_56 = ( unsigned long ) ( void * ) V_78 ;
V_118 . V_97 = V_119 ;
V_118 . V_120 . V_121 = V_78 -> V_9 . V_10 . V_21 -> V_110 ;
F_40 ( & V_13 -> V_111 ) ;
while ( V_77 -> V_117 -- )
F_42 ( V_36 -> V_61 , V_72 ++ ) ;
F_44 ( & V_36 -> V_122 ) ;
V_31 = F_41 ( V_36 -> V_112 -> V_113 , & V_118 , & V_83 ) ;
F_45 ( & V_36 -> V_122 ) ;
if ( V_31 )
goto V_123;
F_11 ( V_13 , V_78 ) ;
return V_73 ;
V_123:
F_10 ( L_11 , V_24 , V_31 ) ;
F_13 ( V_78 ) ;
return V_73 ;
}
static void
F_46 ( struct V_58 * V_59 )
{
struct V_8 * V_9 ;
F_47 ( V_1 ) ;
while ( ! F_48 ( & V_59 -> V_65 ) ) {
V_9 = F_49 ( V_59 -> V_65 . V_124 , struct V_8 , V_69 ) ;
F_50 ( & V_9 -> V_69 ) ;
F_19 ( V_9 ) ;
F_32 ( V_9 ) ;
}
}
