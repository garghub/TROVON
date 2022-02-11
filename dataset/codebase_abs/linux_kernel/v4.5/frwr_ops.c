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
V_30 -> V_33 = F_17 ( V_15 , sizeof( * V_30 -> V_33 ) , V_34 ) ;
if ( ! V_30 -> V_33 )
goto V_35;
F_18 ( V_30 -> V_33 , V_15 ) ;
return 0 ;
V_32:
V_31 = F_19 ( V_30 -> V_21 ) ;
F_10 ( L_4 ,
V_24 , V_31 ) ;
return V_31 ;
V_35:
V_31 = - V_3 ;
F_10 ( L_5 ,
V_24 ) ;
F_7 ( V_30 -> V_21 ) ;
return V_31 ;
}
static void
F_20 ( struct V_8 * V_9 )
{
int V_31 ;
V_31 = F_7 ( V_9 -> V_9 . V_10 . V_21 ) ;
if ( V_31 )
F_10 ( L_6 ,
V_24 , V_31 ) ;
F_21 ( V_9 -> V_9 . V_10 . V_33 ) ;
}
static int
F_22 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
int V_15 , V_42 ;
V_37 -> V_17 =
F_23 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len) ;
F_10 ( L_7 ,
V_24 , V_37 -> V_17 ) ;
V_15 = 7 ;
if ( V_37 -> V_17 < V_43 ) {
V_42 = V_43 - V_37 -> V_17 ;
do {
V_15 += 2 ;
V_42 -= V_37 -> V_17 ;
} while ( V_42 > 0 );
}
V_39 -> V_44 . V_45 . V_46 *= V_15 ;
if ( V_39 -> V_44 . V_45 . V_46 > V_37 -> V_47 -> V_48 . V_49 ) {
V_41 -> V_50 = V_37 -> V_47 -> V_48 . V_49 / V_15 ;
if ( ! V_41 -> V_50 )
return - V_51 ;
V_39 -> V_44 . V_45 . V_46 = V_41 -> V_50 *
V_15 ;
}
return 0 ;
}
static T_1
F_24 ( struct V_12 * V_13 )
{
struct V_36 * V_37 = & V_13 -> V_16 ;
return F_23 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * ia->ri_max_frmr_depth) ;
}
static void
F_25 ( struct V_52 * V_53 , struct V_8 * V_9 )
{
if ( F_26 ( V_53 -> V_54 == V_55 ) )
return;
V_9 = (struct V_8 * ) ( unsigned long ) V_53 -> V_56 ;
if ( V_53 -> V_54 == V_57 )
F_10 ( L_8 , V_24 , V_9 ) ;
else
F_12 ( L_9 ,
V_24 , V_9 , F_27 ( V_53 -> V_54 ) , V_53 -> V_54 ) ;
V_9 -> V_9 . V_10 . V_25 = V_58 ;
}
static void
F_28 ( struct V_52 * V_53 )
{
struct V_8 * V_9 = (struct V_8 * ) ( unsigned long ) V_53 -> V_56 ;
struct V_29 * V_30 = & V_9 -> V_9 . V_10 ;
if ( F_29 ( V_53 -> V_54 != V_55 ) )
F_25 ( V_53 , V_9 ) ;
if ( V_30 -> V_59 )
F_30 ( & V_30 -> V_60 ) ;
}
static int
F_31 ( struct V_12 * V_13 )
{
struct V_61 * V_62 = & V_13 -> V_63 ;
struct V_27 * V_28 = V_13 -> V_16 . V_47 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
int V_64 ;
F_32 ( & V_62 -> V_65 ) ;
F_33 ( & V_62 -> V_66 ) ;
F_33 ( & V_62 -> V_67 ) ;
V_64 = F_34 ( int , V_43 / V_15 , 1 ) ;
V_64 += 2 ;
V_64 *= V_62 -> V_68 ;
F_10 ( L_10 , V_24 , V_64 ) ;
while ( V_64 -- ) {
struct V_8 * V_9 ;
int V_31 ;
V_9 = F_35 ( sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
return - V_3 ;
V_31 = F_16 ( V_9 , V_19 , V_28 , V_15 ) ;
if ( V_31 ) {
F_21 ( V_9 ) ;
return V_31 ;
}
F_36 ( & V_9 -> V_69 , & V_62 -> V_66 ) ;
F_36 ( & V_9 -> V_70 , & V_62 -> V_67 ) ;
V_9 -> V_71 = F_28 ;
V_9 -> V_9 . V_10 . V_14 = V_13 ;
}
return 0 ;
}
static int
F_37 ( struct V_12 * V_13 , struct V_72 * V_73 ,
int V_74 , bool V_75 )
{
struct V_36 * V_37 = & V_13 -> V_16 ;
struct V_27 * V_28 = V_37 -> V_47 ;
enum V_76 V_77 = F_38 ( V_75 ) ;
struct V_72 * V_78 = V_73 ;
struct V_8 * V_79 ;
struct V_29 * V_10 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
int V_31 , V_64 , V_86 , V_87 ;
T_2 V_88 ;
V_79 = V_78 -> V_89 ;
V_78 -> V_89 = NULL ;
do {
if ( V_79 )
F_13 ( V_79 ) ;
V_79 = F_39 ( V_13 ) ;
if ( ! V_79 )
return - V_3 ;
} while ( V_79 -> V_9 . V_10 . V_25 != V_26 );
V_10 = & V_79 -> V_9 . V_10 ;
V_10 -> V_25 = V_90 ;
V_10 -> V_59 = false ;
V_81 = V_10 -> V_21 ;
V_83 = & V_10 -> V_91 ;
if ( V_74 > V_37 -> V_17 )
V_74 = V_37 -> V_17 ;
for ( V_64 = 0 ; V_64 < V_74 ; ) {
if ( V_73 -> V_92 )
F_40 ( & V_10 -> V_33 [ V_64 ] ,
V_73 -> V_92 ,
V_73 -> V_93 ,
F_41 ( V_73 -> V_94 ) ) ;
else
F_42 ( & V_10 -> V_33 [ V_64 ] , V_73 -> V_94 ,
V_73 -> V_93 ) ;
++ V_73 ;
++ V_64 ;
if ( ( V_64 < V_74 && F_41 ( V_73 -> V_94 ) ) ||
F_41 ( ( V_73 - 1 ) -> V_94 + ( V_73 - 1 ) -> V_93 ) )
break;
}
V_10 -> V_95 = V_64 ;
V_87 = F_43 ( V_28 , V_10 -> V_33 , V_10 -> V_95 , V_77 ) ;
if ( ! V_87 ) {
F_44 ( L_11 ,
V_24 , V_10 -> V_33 , V_10 -> V_95 ) ;
return - V_3 ;
}
V_86 = F_45 ( V_81 , V_10 -> V_33 , V_10 -> V_95 , V_96 ) ;
if ( F_29 ( V_86 != V_10 -> V_95 ) ) {
F_44 ( L_12 ,
V_24 , V_10 -> V_21 , V_86 , V_10 -> V_95 ) ;
V_31 = V_86 < 0 ? V_86 : - V_51 ;
goto V_97;
}
F_10 ( L_13 ,
V_24 , V_79 , V_10 -> V_95 , V_81 -> V_98 ) ;
V_88 = ( T_2 ) ( V_81 -> V_99 & 0x000000FF ) ;
F_46 ( V_81 , ++ V_88 ) ;
V_83 -> V_100 . V_101 = NULL ;
V_83 -> V_100 . V_102 = V_103 ;
V_83 -> V_100 . V_56 = ( V_104 ) V_79 ;
V_83 -> V_100 . V_105 = 0 ;
V_83 -> V_100 . V_106 = 0 ;
V_83 -> V_81 = V_81 ;
V_83 -> V_88 = V_81 -> V_99 ;
V_83 -> V_107 = V_75 ?
V_108 | V_109 :
V_110 ;
F_47 ( & V_13 -> V_111 ) ;
V_31 = F_48 ( V_37 -> V_112 -> V_113 , & V_83 -> V_100 , & V_85 ) ;
if ( V_31 )
goto V_97;
V_78 -> V_114 = V_77 ;
V_78 -> V_89 = V_79 ;
V_78 -> V_115 = V_81 -> V_99 ;
V_78 -> V_116 = V_81 -> V_117 ;
V_78 -> V_118 = V_10 -> V_95 ;
V_78 -> V_93 = V_81 -> V_98 ;
return V_10 -> V_95 ;
V_97:
F_10 ( L_14 , V_24 , V_31 ) ;
F_49 ( V_28 , V_10 -> V_33 , V_87 , V_77 ) ;
F_13 ( V_79 ) ;
return V_31 ;
}
static struct V_84 *
F_50 ( struct V_72 * V_73 )
{
struct V_8 * V_79 = V_73 -> V_89 ;
struct V_29 * V_30 = & V_79 -> V_9 . V_10 ;
struct V_84 * V_119 ;
V_30 -> V_59 = false ;
V_30 -> V_25 = V_26 ;
V_119 = & V_30 -> V_120 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_56 = ( unsigned long ) ( void * ) V_79 ;
V_119 -> V_102 = V_121 ;
V_119 -> V_122 . V_123 = V_30 -> V_21 -> V_99 ;
return V_119 ;
}
static void
F_51 ( struct V_12 * V_13 , struct V_72 * V_73 ,
int V_31 )
{
struct V_27 * V_28 = V_13 -> V_16 . V_47 ;
struct V_8 * V_79 = V_73 -> V_89 ;
struct V_29 * V_30 = & V_79 -> V_9 . V_10 ;
V_73 -> V_89 = NULL ;
F_49 ( V_28 , V_30 -> V_33 , V_30 -> V_95 , V_73 -> V_114 ) ;
if ( ! V_31 )
F_11 ( V_13 , V_79 ) ;
else
F_13 ( V_79 ) ;
}
static void
F_52 ( struct V_12 * V_13 , struct V_124 * V_125 )
{
struct V_84 * V_126 , * V_127 , * V_128 , * V_85 ;
struct V_36 * V_37 = & V_13 -> V_16 ;
struct V_72 * V_73 ;
unsigned int V_64 , V_129 ;
struct V_29 * V_30 ;
int V_31 ;
F_10 ( L_15 , V_24 , V_125 ) ;
V_126 = V_127 = V_128 = NULL ;
V_73 = NULL ;
for ( V_64 = 0 , V_129 = V_125 -> V_130 ; V_129 ; V_129 -- ) {
V_73 = & V_125 -> V_131 [ V_64 ] ;
V_127 = F_50 ( V_73 ) ;
if ( ! V_126 )
V_126 = V_127 ;
else
V_128 -> V_101 = V_127 ;
V_128 = V_127 ;
V_64 += V_73 -> V_118 ;
}
V_30 = & V_73 -> V_89 -> V_9 . V_10 ;
V_30 -> V_120 . V_106 = V_132 ;
V_30 -> V_59 = true ;
F_53 ( & V_30 -> V_60 ) ;
F_54 ( & V_13 -> V_111 ) ;
V_31 = F_48 ( V_37 -> V_112 -> V_113 , V_126 , & V_85 ) ;
if ( V_31 )
F_12 ( L_16 , V_24 , V_31 ) ;
F_55 ( & V_30 -> V_60 ) ;
for ( V_64 = 0 , V_129 = V_125 -> V_130 ; V_129 ; V_129 -- ) {
V_73 = & V_125 -> V_131 [ V_64 ] ;
F_51 ( V_13 , V_73 , V_31 ) ;
V_64 += V_73 -> V_118 ;
V_73 -> V_118 = 0 ;
}
V_125 -> V_130 = 0 ;
}
static int
F_56 ( struct V_12 * V_13 , struct V_72 * V_73 )
{
struct V_72 * V_78 = V_73 ;
struct V_36 * V_37 = & V_13 -> V_16 ;
struct V_8 * V_79 = V_78 -> V_89 ;
struct V_29 * V_10 = & V_79 -> V_9 . V_10 ;
struct V_84 * V_119 , * V_85 ;
int V_31 , V_74 = V_73 -> V_118 ;
F_10 ( L_17 , V_24 , V_79 ) ;
V_78 -> V_89 = NULL ;
V_10 -> V_25 = V_26 ;
V_119 = & V_79 -> V_9 . V_10 . V_120 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_56 = ( V_104 ) V_79 ;
V_119 -> V_102 = V_121 ;
V_119 -> V_122 . V_123 = V_10 -> V_21 -> V_99 ;
F_47 ( & V_13 -> V_111 ) ;
F_49 ( V_37 -> V_47 , V_10 -> V_33 , V_10 -> V_95 , V_78 -> V_114 ) ;
F_57 ( & V_37 -> V_133 ) ;
V_31 = F_48 ( V_37 -> V_112 -> V_113 , V_119 , & V_85 ) ;
F_58 ( & V_37 -> V_133 ) ;
if ( V_31 )
goto V_134;
F_11 ( V_13 , V_79 ) ;
return V_74 ;
V_134:
F_10 ( L_14 , V_24 , V_31 ) ;
F_13 ( V_79 ) ;
return V_74 ;
}
static void
F_59 ( struct V_61 * V_62 )
{
struct V_8 * V_9 ;
F_60 ( V_1 ) ;
while ( ! F_61 ( & V_62 -> V_67 ) ) {
V_9 = F_62 ( V_62 -> V_67 . V_101 , struct V_8 , V_70 ) ;
F_63 ( & V_9 -> V_70 ) ;
F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
}
}
