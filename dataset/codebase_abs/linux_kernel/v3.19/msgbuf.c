static struct V_1 *
F_1 ( T_1 V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
V_6 = F_2 ( V_2 , sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_7 = F_3 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_4 ( V_6 ) ;
return NULL ;
}
V_7 -> V_6 = V_6 ;
V_7 -> V_9 = V_2 ;
return V_7 ;
}
static int
F_5 ( struct V_10 * V_11 ,
struct V_1 * V_7 ,
struct V_12 * V_13 , T_2 V_14 ,
T_3 * V_15 , T_1 * V_16 )
{
struct V_5 * V_6 ;
T_1 V_17 ;
V_6 = V_7 -> V_6 ;
* V_15 = F_6 ( V_11 , V_13 -> V_18 + V_14 ,
V_13 -> V_19 - V_14 , V_7 -> V_4 ) ;
if ( F_7 ( V_11 , * V_15 ) ) {
F_8 ( L_1 ) ;
return - V_20 ;
}
* V_16 = V_7 -> V_21 ;
V_17 = 0 ;
do {
( * V_16 ) ++ ;
if ( * V_16 == V_7 -> V_9 )
* V_16 = 0 ;
if ( V_6 [ * V_16 ] . V_22 . V_23 == 0 )
if ( F_9 ( & V_6 [ * V_16 ] . V_22 , 0 , 1 ) == 0 )
break;
V_17 ++ ;
} while ( V_17 < V_7 -> V_9 );
if ( V_17 == V_7 -> V_9 )
return - V_20 ;
V_6 [ * V_16 ] . V_14 = V_14 ;
V_6 [ * V_16 ] . V_15 = * V_15 ;
V_6 [ * V_16 ] . V_13 = V_13 ;
V_7 -> V_21 = * V_16 ;
return 0 ;
}
static struct V_12 *
F_10 ( struct V_10 * V_11 , struct V_1 * V_7 ,
T_1 V_16 )
{
struct V_5 * V_24 ;
struct V_12 * V_13 ;
if ( V_16 >= V_7 -> V_9 ) {
F_8 ( L_2 , V_16 ,
V_7 -> V_9 ) ;
return NULL ;
}
if ( V_7 -> V_6 [ V_16 ] . V_22 . V_23 ) {
V_24 = & V_7 -> V_6 [ V_16 ] ;
F_11 ( V_11 , V_24 -> V_15 ,
V_24 -> V_13 -> V_19 - V_24 -> V_14 ,
V_7 -> V_4 ) ;
V_13 = V_24 -> V_13 ;
V_24 -> V_22 . V_23 = 0 ;
return V_13 ;
} else {
F_8 ( L_3 , V_16 ) ;
}
return NULL ;
}
static void
F_12 ( struct V_10 * V_11 ,
struct V_1 * V_7 )
{
struct V_5 * V_6 ;
struct V_5 * V_24 ;
T_1 V_17 ;
V_6 = V_7 -> V_6 ;
V_17 = 0 ;
do {
if ( V_6 [ V_17 ] . V_22 . V_23 ) {
V_24 = & V_6 [ V_17 ] ;
F_11 ( V_11 , V_24 -> V_15 ,
V_24 -> V_13 -> V_19 - V_24 -> V_14 ,
V_7 -> V_4 ) ;
F_13 ( V_24 -> V_13 ) ;
}
V_17 ++ ;
} while ( V_17 < V_7 -> V_9 );
F_4 ( V_6 ) ;
F_4 ( V_7 ) ;
}
static void F_14 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 )
F_12 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 ) ;
if ( V_26 -> V_30 )
F_12 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_30 ) ;
}
static int F_15 ( struct V_31 * V_28 , int V_32 ,
T_4 V_33 , void * V_34 , T_4 V_19 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
T_2 V_41 ;
void * V_42 ;
int V_43 ;
V_38 = V_26 -> V_44 [ V_45 ] ;
F_16 ( V_38 ) ;
V_42 = F_17 ( V_38 ) ;
if ( ! V_42 ) {
F_8 ( L_4 ) ;
F_18 ( V_38 ) ;
return - V_20 ;
}
V_26 -> V_46 ++ ;
V_40 = (struct V_39 * ) V_42 ;
V_40 -> V_47 . V_48 = V_49 ;
V_40 -> V_47 . V_32 = ( V_50 ) V_32 ;
V_40 -> V_47 . V_51 = 0 ;
V_40 -> V_47 . V_52 = F_19 ( V_53 ) ;
V_40 -> V_33 = F_19 ( V_33 ) ;
V_40 -> V_54 = F_20 ( V_19 ) ;
V_40 -> V_55 = F_20 ( V_26 -> V_46 ) ;
V_41 = F_21 ( T_2 , V_19 , V_56 ) ;
V_40 -> V_57 = F_20 ( V_41 ) ;
V_40 -> V_58 . V_59 = F_19 ( V_26 -> V_60 ) ;
V_40 -> V_58 . V_61 = F_19 ( V_26 -> V_62 ) ;
if ( V_34 )
memcpy ( V_26 -> V_63 , V_34 , V_41 ) ;
else
memset ( V_26 -> V_63 , 0 , V_41 ) ;
F_22 ( V_64 , V_41 ) ;
V_43 = F_23 ( V_38 ) ;
F_18 ( V_38 ) ;
return V_43 ;
}
static int F_24 ( struct V_25 * V_26 )
{
return F_25 ( V_26 -> V_65 ,
V_26 -> V_66 ,
F_26 ( V_67 ) ) ;
}
static void F_27 ( struct V_25 * V_26 )
{
if ( F_28 ( & V_26 -> V_65 ) ) {
V_26 -> V_66 = true ;
F_29 ( & V_26 -> V_65 ) ;
}
}
static int F_30 ( struct V_31 * V_28 , int V_32 ,
T_4 V_33 , void * V_34 , T_4 V_19 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
struct V_12 * V_13 = NULL ;
int V_68 ;
int V_43 ;
F_31 ( V_69 , L_5 , V_32 , V_33 , V_19 ) ;
V_26 -> V_66 = false ;
V_43 = F_15 ( V_28 , V_32 , V_33 , V_34 , V_19 ) ;
if ( V_43 )
return V_43 ;
V_68 = F_24 ( V_26 ) ;
if ( ! V_68 ) {
F_8 ( L_6 ) ;
return - V_70 ;
}
V_13 = F_10 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 ,
V_26 -> V_71 ) ;
if ( V_26 -> V_72 != 0 ) {
if ( ! V_13 ) {
F_8 ( L_7 ,
V_26 -> V_71 ) ;
return - V_73 ;
}
memcpy ( V_34 , V_13 -> V_18 , ( V_19 < V_26 -> V_72 ) ?
V_19 : V_26 -> V_72 ) ;
}
F_13 ( V_13 ) ;
return V_26 -> V_74 ;
}
static int F_32 ( struct V_31 * V_28 , int V_32 ,
T_4 V_33 , void * V_34 , T_4 V_19 )
{
return F_30 ( V_28 , V_32 , V_33 , V_34 , V_19 ) ;
}
static int F_33 ( struct V_31 * V_28 , bool V_75 ,
V_50 * V_32 , struct V_12 * V_13 )
{
return - V_76 ;
}
static void
F_34 ( struct V_25 * V_26 , T_2 V_77 )
{
T_1 V_78 ;
void * V_79 ;
F_31 ( V_69 , L_8 , V_77 ) ;
V_78 = V_80 * V_81 ;
V_79 = V_26 -> V_82 [ V_77 ] -> V_83 ;
F_35 ( V_26 -> V_28 -> V_29 -> V_11 , V_78 , V_79 ,
V_26 -> V_84 [ V_77 ] ) ;
F_36 ( V_26 -> V_85 , V_77 ) ;
}
static struct V_86 *
F_37 ( struct V_25 * V_26 )
{
struct V_86 * V_87 = NULL ;
T_5 V_51 ;
F_38 ( & V_26 -> V_88 , V_51 ) ;
if ( ! F_39 ( & V_26 -> V_89 ) ) {
V_87 = F_40 ( & V_26 -> V_89 ,
struct V_86 , V_90 ) ;
F_41 ( & V_87 -> V_90 ) ;
}
F_42 ( & V_26 -> V_88 , V_51 ) ;
return V_87 ;
}
static T_1
F_43 ( struct V_25 * V_26 ,
struct V_86 * V_87 )
{
struct V_91 * V_92 ;
struct V_37 * V_38 ;
void * V_42 ;
T_1 V_77 ;
void * V_79 ;
T_1 V_78 ;
long long V_93 ;
int V_43 ;
V_77 = V_87 -> V_77 ;
V_78 = V_80 * V_81 ;
V_79 = F_44 ( V_26 -> V_28 -> V_29 -> V_11 , V_78 ,
& V_26 -> V_84 [ V_77 ] ,
V_8 ) ;
if ( ! V_79 ) {
F_8 ( L_9 ) ;
F_36 ( V_26 -> V_85 , V_77 ) ;
return V_94 ;
}
F_45 ( V_26 -> V_82 [ V_77 ] ,
V_80 ,
V_81 , V_79 ) ;
V_38 = V_26 -> V_44 [ V_45 ] ;
F_16 ( V_38 ) ;
V_42 = F_17 ( V_38 ) ;
if ( ! V_42 ) {
F_8 ( L_4 ) ;
F_18 ( V_38 ) ;
F_34 ( V_26 , V_77 ) ;
return V_94 ;
}
V_92 = (struct V_91 * ) V_42 ;
V_92 -> V_47 . V_48 = V_95 ;
V_92 -> V_47 . V_32 = V_87 -> V_32 ;
V_92 -> V_47 . V_52 = 0 ;
V_92 -> V_96 = F_46 ( V_26 -> V_85 , V_77 ) ;
V_92 -> V_97 = F_20 ( V_77 +
V_98 ) ;
memcpy ( V_92 -> V_99 , V_87 -> V_99 , V_100 ) ;
memcpy ( V_92 -> V_101 , V_87 -> V_101 , V_100 ) ;
V_93 = ( long long ) ( long ) V_26 -> V_84 [ V_77 ] ;
V_92 -> V_102 . V_59 = F_19 ( V_93 >> 32 ) ;
V_92 -> V_102 . V_61 = F_19 ( V_93 & 0xffffffff ) ;
V_92 -> V_103 = F_20 ( V_80 ) ;
V_92 -> V_104 = F_20 ( V_81 ) ;
F_31 ( V_69 , L_10 ,
V_77 , V_87 -> V_101 , V_92 -> V_96 , V_87 -> V_32 ) ;
V_43 = F_23 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_43 ) {
F_8 ( L_11 ) ;
F_34 ( V_26 , V_77 ) ;
return V_94 ;
}
return V_77 ;
}
static void F_47 ( struct V_105 * V_87 )
{
struct V_25 * V_26 ;
struct V_86 * V_92 ;
V_26 = F_48 ( V_87 , struct V_25 , V_106 ) ;
while ( ( V_92 = F_37 ( V_26 ) ) ) {
F_43 ( V_26 , V_92 ) ;
F_4 ( V_92 ) ;
}
}
static T_1 F_49 ( struct V_25 * V_26 , int V_32 ,
struct V_12 * V_13 )
{
struct V_86 * V_92 ;
struct V_107 * V_108 = (struct V_107 * ) ( V_13 -> V_18 ) ;
T_1 V_77 ;
T_5 V_51 ;
V_92 = F_3 ( sizeof( * V_92 ) , V_109 ) ;
if ( V_92 == NULL )
return V_94 ;
V_77 = F_50 ( V_26 -> V_85 , V_108 -> V_110 ,
V_13 -> V_111 , V_32 ) ;
if ( V_77 == V_94 ) {
F_4 ( V_92 ) ;
return V_77 ;
}
V_92 -> V_77 = V_77 ;
V_92 -> V_32 = V_32 ;
memcpy ( V_92 -> V_99 , V_108 -> V_112 , V_100 ) ;
memcpy ( V_92 -> V_101 , V_108 -> V_110 , V_100 ) ;
F_38 ( & V_26 -> V_88 , V_51 ) ;
F_51 ( & V_92 -> V_90 , & V_26 -> V_89 ) ;
F_42 ( & V_26 -> V_88 , V_51 ) ;
F_52 ( & V_26 -> V_106 ) ;
return V_77 ;
}
static void F_53 ( struct V_25 * V_26 , V_50 V_77 )
{
struct V_113 * V_85 = V_26 -> V_85 ;
struct V_37 * V_38 ;
void * V_42 ;
T_1 V_17 ;
struct V_12 * V_13 ;
T_3 V_15 ;
T_1 V_24 ;
struct V_114 * V_115 ;
long long V_93 ;
V_38 = V_26 -> V_82 [ V_77 ] ;
if ( ! F_54 ( V_38 ) )
return;
F_16 ( V_38 ) ;
V_17 = V_116 - V_117 ;
while ( F_55 ( V_85 , V_77 ) ) {
V_13 = F_56 ( V_85 , V_77 ) ;
if ( V_13 == NULL ) {
F_8 ( L_12 ,
F_55 ( V_85 , V_77 ) ) ;
break;
}
F_57 ( V_13 ) ;
if ( F_5 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_30 , V_13 , V_118 ,
& V_15 , & V_24 ) ) {
F_58 ( V_85 , V_77 , V_13 ) ;
F_8 ( L_13 ) ;
break;
}
V_42 = F_17 ( V_38 ) ;
if ( ! V_42 ) {
F_10 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_30 , V_24 ) ;
F_58 ( V_85 , V_77 , V_13 ) ;
break;
}
V_17 ++ ;
V_115 = (struct V_114 * ) V_42 ;
V_115 -> V_47 . V_48 = V_119 ;
V_115 -> V_47 . V_52 = F_19 ( V_24 ) ;
V_115 -> V_47 . V_32 = F_59 ( V_85 , V_77 ) ;
V_115 -> V_51 = V_120 ;
V_115 -> V_51 |= ( V_13 -> V_111 & 0x07 ) <<
V_121 ;
V_115 -> V_122 = 1 ;
memcpy ( V_115 -> V_123 , V_13 -> V_18 , V_118 ) ;
V_115 -> V_124 = F_20 ( V_13 -> V_19 - V_118 ) ;
V_93 = ( long long ) ( long ) V_15 ;
V_115 -> V_125 . V_59 = F_19 ( V_93 >> 32 ) ;
V_115 -> V_125 . V_61 =
F_19 ( V_93 & 0xffffffff ) ;
V_115 -> V_126 = 0 ;
V_115 -> V_127 . V_59 = 0 ;
V_115 -> V_127 . V_61 = 0 ;
if ( V_17 >= V_116 ) {
F_23 ( V_38 ) ;
V_17 = 0 ;
}
}
if ( V_17 )
F_23 ( V_38 ) ;
F_18 ( V_38 ) ;
}
static void F_60 ( struct V_105 * V_128 )
{
struct V_25 * V_26 ;
T_1 V_77 ;
V_26 = F_48 ( V_128 , struct V_25 , V_129 ) ;
F_61 (flowid, msgbuf->flow_map, msgbuf->nrof_flowrings) {
F_62 ( V_77 , V_26 -> V_130 ) ;
F_53 ( V_26 , V_77 ) ;
}
}
static int F_63 ( struct V_25 * V_26 , T_1 V_77 )
{
F_64 ( V_77 , V_26 -> V_130 ) ;
F_65 ( V_26 -> V_131 , & V_26 -> V_129 ) ;
return 0 ;
}
static int F_66 ( struct V_31 * V_28 , int V_32 ,
V_50 V_132 , struct V_12 * V_13 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
struct V_113 * V_85 = V_26 -> V_85 ;
struct V_107 * V_108 = (struct V_107 * ) ( V_13 -> V_18 ) ;
T_1 V_77 ;
V_77 = F_67 ( V_85 , V_108 -> V_110 , V_13 -> V_111 , V_32 ) ;
if ( V_77 == V_94 ) {
V_77 = F_49 ( V_26 , V_32 , V_13 ) ;
if ( V_77 == V_94 )
return - V_20 ;
}
F_68 ( V_85 , V_77 , V_13 ) ;
F_63 ( V_26 , V_77 ) ;
return 0 ;
}
static void
F_69 ( struct V_31 * V_28 , int V_32 ,
enum V_133 V_134 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
F_70 ( V_26 -> V_85 , V_32 , V_134 ) ;
}
static void
F_71 ( struct V_31 * V_28 , int V_32 , V_50 V_135 [ V_100 ] )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
F_72 ( V_26 -> V_85 , V_32 , V_135 ) ;
}
static void
F_73 ( struct V_31 * V_28 , int V_32 , V_50 V_135 [ V_100 ] )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
F_74 ( V_26 -> V_85 , V_32 , V_135 ) ;
}
static void
F_75 ( struct V_25 * V_26 , void * V_34 )
{
struct V_136 * V_137 ;
V_137 = (struct V_136 * ) V_34 ;
V_26 -> V_74 =
( V_138 ) F_76 ( V_137 -> V_139 . V_140 ) ;
V_26 -> V_72 = F_76 ( V_137 -> V_141 ) ;
V_26 -> V_71 = F_77 ( V_137 -> V_47 . V_52 ) ;
F_27 ( V_26 ) ;
if ( V_26 -> V_142 )
V_26 -> V_142 -- ;
F_78 ( V_26 ) ;
}
static void
F_79 ( struct V_25 * V_26 , void * V_34 )
{
struct V_143 * V_144 ;
T_1 V_16 ;
struct V_12 * V_13 ;
T_2 V_77 ;
V_144 = (struct V_143 * ) V_34 ;
V_16 = F_77 ( V_144 -> V_47 . V_52 ) ;
V_77 = F_76 ( V_144 -> V_139 . V_97 ) ;
V_77 -= V_98 ;
V_13 = F_10 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_30 , V_16 ) ;
if ( ! V_13 ) {
F_8 ( L_7 , V_16 ) ;
return;
}
F_64 ( V_77 , V_26 -> V_145 ) ;
F_80 ( V_26 -> V_28 , V_13 , V_144 -> V_47 . V_32 , true ) ;
}
static T_1 F_81 ( struct V_25 * V_26 , T_1 V_17 )
{
struct V_37 * V_38 ;
void * V_42 ;
struct V_12 * V_13 ;
T_2 V_146 ;
T_1 V_147 ;
T_3 V_15 ;
struct V_148 * V_149 ;
long long V_93 ;
T_1 V_24 ;
T_1 V_150 ;
V_38 = V_26 -> V_44 [ V_151 ] ;
V_42 = F_82 ( V_38 ,
V_17 ,
& V_146 ) ;
if ( ! V_42 ) {
F_8 ( L_4 ) ;
return 0 ;
}
for ( V_150 = 0 ; V_150 < V_146 ; V_150 ++ ) {
V_149 = (struct V_148 * ) V_42 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_13 = F_83 ( V_152 ) ;
if ( V_13 == NULL ) {
F_8 ( L_14 ) ;
F_84 ( V_38 , V_146 - V_150 ) ;
break;
}
V_147 = V_13 -> V_19 ;
if ( F_5 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 , V_13 , 0 ,
& V_15 , & V_24 ) ) {
F_85 ( V_13 ) ;
F_8 ( L_13 ) ;
F_84 ( V_38 , V_146 - V_150 ) ;
break;
}
if ( V_26 -> V_153 ) {
V_93 = ( long long ) ( long ) V_15 ;
V_149 -> V_126 =
F_20 ( V_26 -> V_153 ) ;
V_149 -> V_127 . V_59 =
F_19 ( V_93 >> 32 ) ;
V_149 -> V_127 . V_61 =
F_19 ( V_93 & 0xffffffff ) ;
F_86 ( V_13 , V_26 -> V_153 ) ;
V_147 = V_13 -> V_19 ;
V_15 += V_26 -> V_153 ;
}
V_149 -> V_47 . V_48 = V_154 ;
V_149 -> V_47 . V_52 = F_19 ( V_24 ) ;
V_93 = ( long long ) ( long ) V_15 ;
V_149 -> V_155 = F_20 ( ( T_2 ) V_147 ) ;
V_149 -> V_125 . V_59 =
F_19 ( V_93 >> 32 ) ;
V_149 -> V_125 . V_61 =
F_19 ( V_93 & 0xffffffff ) ;
V_42 += F_87 ( V_38 ) ;
}
if ( V_150 )
F_23 ( V_38 ) ;
return V_150 ;
}
static void
F_88 ( struct V_25 * V_26 )
{
T_1 V_156 ;
T_1 V_157 ;
V_156 = V_26 -> V_158 - V_26 -> V_159 ;
while ( V_156 ) {
V_157 = F_81 ( V_26 , V_156 ) ;
if ( ! V_157 )
break;
V_26 -> V_159 += V_157 ;
V_156 -= V_157 ;
}
}
static void
F_89 ( struct V_25 * V_26 , T_2 V_160 )
{
V_26 -> V_159 -= V_160 ;
if ( V_26 -> V_159 <= ( V_26 -> V_158 -
V_161 ) )
F_88 ( V_26 ) ;
}
static T_1
F_90 ( struct V_25 * V_26 , bool V_162 ,
T_1 V_17 )
{
struct V_37 * V_38 ;
void * V_42 ;
struct V_12 * V_13 ;
T_2 V_146 ;
T_1 V_147 ;
T_3 V_15 ;
struct V_163 * V_149 ;
long long V_93 ;
T_1 V_24 ;
T_1 V_150 ;
V_38 = V_26 -> V_44 [ V_45 ] ;
F_16 ( V_38 ) ;
V_42 = F_82 ( V_38 ,
V_17 ,
& V_146 ) ;
if ( ! V_42 ) {
F_8 ( L_4 ) ;
F_18 ( V_38 ) ;
return 0 ;
}
for ( V_150 = 0 ; V_150 < V_146 ; V_150 ++ ) {
V_149 = (struct V_163 * ) V_42 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_13 = F_83 ( V_152 ) ;
if ( V_13 == NULL ) {
F_8 ( L_14 ) ;
F_84 ( V_38 , V_146 - V_150 ) ;
break;
}
V_147 = V_13 -> V_19 ;
if ( F_5 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 , V_13 , 0 ,
& V_15 , & V_24 ) ) {
F_85 ( V_13 ) ;
F_8 ( L_13 ) ;
F_84 ( V_38 , V_146 - V_150 ) ;
break;
}
if ( V_162 )
V_149 -> V_47 . V_48 = V_164 ;
else
V_149 -> V_47 . V_48 =
V_165 ;
V_149 -> V_47 . V_52 = F_19 ( V_24 ) ;
V_93 = ( long long ) ( long ) V_15 ;
V_149 -> V_166 = F_20 ( ( T_2 ) V_147 ) ;
V_149 -> V_167 . V_59 =
F_19 ( V_93 >> 32 ) ;
V_149 -> V_167 . V_61 =
F_19 ( V_93 & 0xffffffff ) ;
V_42 += F_87 ( V_38 ) ;
}
if ( V_150 )
F_23 ( V_38 ) ;
F_18 ( V_38 ) ;
return V_150 ;
}
static void F_78 ( struct V_25 * V_26 )
{
T_1 V_17 ;
V_17 = V_26 -> V_168 - V_26 -> V_142 ;
V_17 = F_90 ( V_26 , false , V_17 ) ;
V_26 -> V_142 += V_17 ;
}
static void F_91 ( struct V_25 * V_26 )
{
T_1 V_17 ;
V_17 = V_26 -> V_169 - V_26 -> V_170 ;
V_17 = F_90 ( V_26 , true , V_17 ) ;
V_26 -> V_170 += V_17 ;
}
static void
F_92 ( struct V_25 * V_26 , struct V_12 * V_13 ,
V_50 V_32 )
{
struct V_171 * V_172 ;
if ( V_32 )
( V_32 ) ++ ;
V_172 = V_26 -> V_28 -> V_173 [ V_32 ] ;
if ( ! V_172 || ! V_172 -> V_174 ) {
F_8 ( L_15 , V_32 ) ;
F_13 ( V_13 ) ;
return;
}
F_93 ( V_172 , V_13 ) ;
}
static void F_94 ( struct V_25 * V_26 , void * V_34 )
{
struct V_175 * V_176 ;
T_1 V_16 ;
T_2 V_177 ;
struct V_12 * V_13 ;
V_176 = (struct V_175 * ) V_34 ;
V_16 = F_77 ( V_176 -> V_47 . V_52 ) ;
V_177 = F_76 ( V_176 -> V_178 ) ;
if ( V_26 -> V_170 )
V_26 -> V_170 -- ;
F_91 ( V_26 ) ;
V_13 = F_10 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 , V_16 ) ;
if ( ! V_13 )
return;
if ( V_26 -> V_179 )
F_86 ( V_13 , V_26 -> V_179 ) ;
F_95 ( V_13 , V_177 ) ;
F_92 ( V_26 , V_13 , V_176 -> V_47 . V_32 ) ;
}
static void
F_96 ( struct V_25 * V_26 , void * V_34 )
{
struct V_180 * V_181 ;
struct V_12 * V_13 ;
T_2 V_14 ;
T_2 V_177 ;
T_1 V_16 ;
F_89 ( V_26 , 1 ) ;
V_181 = (struct V_180 * ) V_34 ;
V_14 = F_76 ( V_181 -> V_14 ) ;
V_177 = F_76 ( V_181 -> V_124 ) ;
V_16 = F_77 ( V_181 -> V_47 . V_52 ) ;
V_13 = F_10 ( V_26 -> V_28 -> V_29 -> V_11 ,
V_26 -> V_27 , V_16 ) ;
if ( V_14 )
F_86 ( V_13 , V_14 ) ;
else if ( V_26 -> V_179 )
F_86 ( V_13 , V_26 -> V_179 ) ;
F_95 ( V_13 , V_177 ) ;
F_92 ( V_26 , V_13 , V_181 -> V_47 . V_32 ) ;
}
static void
F_97 ( struct V_25 * V_26 ,
void * V_34 )
{
struct V_182 * V_183 ;
T_2 V_140 ;
T_2 V_77 ;
V_183 = (struct V_182 * ) V_34 ;
V_77 = F_76 ( V_183 -> V_139 . V_97 ) ;
V_77 -= V_98 ;
V_140 = F_76 ( V_183 -> V_139 . V_140 ) ;
if ( V_140 ) {
F_8 ( L_16 , V_140 ) ;
F_34 ( V_26 , V_77 ) ;
return;
}
F_31 ( V_69 , L_17 , V_77 ,
V_140 ) ;
F_98 ( V_26 -> V_85 , V_77 ) ;
F_63 ( V_26 , V_77 ) ;
}
static void
F_99 ( struct V_25 * V_26 ,
void * V_34 )
{
struct V_184 * V_185 ;
T_2 V_140 ;
T_2 V_77 ;
V_185 = (struct V_184 * ) V_34 ;
V_77 = F_76 ( V_185 -> V_139 . V_97 ) ;
V_77 -= V_98 ;
V_140 = F_76 ( V_185 -> V_139 . V_140 ) ;
if ( V_140 ) {
F_8 ( L_18 , V_140 ) ;
F_36 ( V_26 -> V_85 , V_77 ) ;
return;
}
F_31 ( V_69 , L_19 , V_77 ,
V_140 ) ;
F_34 ( V_26 , V_77 ) ;
}
static void F_100 ( struct V_25 * V_26 , void * V_34 )
{
struct V_186 * V_47 ;
V_47 = (struct V_186 * ) V_34 ;
switch ( V_47 -> V_48 ) {
case V_187 :
F_31 ( V_69 , L_20 ) ;
F_97 ( V_26 , V_34 ) ;
break;
case V_188 :
F_31 ( V_69 , L_21 ) ;
F_99 ( V_26 , V_34 ) ;
break;
case V_189 :
F_31 ( V_69 , L_22 ) ;
break;
case V_190 :
F_31 ( V_69 , L_23 ) ;
F_75 ( V_26 , V_34 ) ;
break;
case V_191 :
F_31 ( V_69 , L_24 ) ;
F_94 ( V_26 , V_34 ) ;
break;
case V_192 :
F_31 ( V_69 , L_25 ) ;
F_79 ( V_26 , V_34 ) ;
break;
case V_193 :
F_31 ( V_69 , L_26 ) ;
F_96 ( V_26 , V_34 ) ;
break;
default:
F_8 ( L_27 , V_47 -> V_48 ) ;
break;
}
}
static void F_101 ( struct V_25 * V_26 ,
struct V_37 * V_38 )
{
void * V_34 ;
T_2 V_17 ;
V_194:
V_34 = F_102 ( V_38 , & V_17 ) ;
if ( V_34 == NULL )
return;
while ( V_17 ) {
F_100 ( V_26 ,
V_34 + V_26 -> V_179 ) ;
V_34 += F_87 ( V_38 ) ;
V_17 -- ;
}
F_103 ( V_38 ) ;
if ( V_38 -> V_195 == 0 )
goto V_194;
}
int F_104 ( struct V_10 * V_11 )
{
struct V_196 * V_29 = F_105 ( V_11 ) ;
struct V_31 * V_28 = V_29 -> V_28 ;
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
void * V_34 ;
T_1 V_77 ;
V_34 = V_26 -> V_44 [ V_197 ] ;
F_101 ( V_26 , V_34 ) ;
V_34 = V_26 -> V_44 [ V_198 ] ;
F_101 ( V_26 , V_34 ) ;
V_34 = V_26 -> V_44 [ V_199 ] ;
F_101 ( V_26 , V_34 ) ;
F_61 (flowid, msgbuf->txstatus_done_map,
msgbuf->nrof_flowrings) {
F_62 ( V_77 , V_26 -> V_145 ) ;
if ( F_55 ( V_26 -> V_85 , V_77 ) )
F_63 ( V_26 , V_77 ) ;
}
return 0 ;
}
void F_106 ( struct V_31 * V_28 , V_50 V_77 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
struct V_200 * V_201 ;
struct V_37 * V_38 ;
void * V_42 ;
V_50 V_32 ;
int V_43 ;
V_38 = V_26 -> V_44 [ V_45 ] ;
F_16 ( V_38 ) ;
V_42 = F_17 ( V_38 ) ;
if ( ! V_42 ) {
F_8 ( L_28 ) ;
F_18 ( V_38 ) ;
F_34 ( V_26 , V_77 ) ;
return;
}
V_201 = (struct V_200 * ) V_42 ;
V_32 = F_59 ( V_26 -> V_85 , V_77 ) ;
V_201 -> V_47 . V_48 = V_202 ;
V_201 -> V_47 . V_32 = V_32 ;
V_201 -> V_47 . V_52 = 0 ;
V_201 -> V_97 = F_20 ( V_77 +
V_98 ) ;
V_201 -> V_203 = 0 ;
F_31 ( V_69 , L_29 ,
V_77 , V_32 ) ;
V_43 = F_23 ( V_38 ) ;
F_18 ( V_38 ) ;
if ( V_43 ) {
F_8 ( L_30 ) ;
F_34 ( V_26 , V_77 ) ;
}
}
int F_107 ( struct V_31 * V_28 )
{
struct V_204 * V_205 ;
struct V_25 * V_26 ;
long long V_93 ;
T_1 V_17 ;
V_205 = V_28 -> V_29 -> V_26 ;
V_26 = F_3 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
goto V_206;
V_26 -> V_131 = F_108 ( L_31 ) ;
if ( V_26 -> V_131 == NULL ) {
F_8 ( L_32 ) ;
goto V_206;
}
F_109 ( & V_26 -> V_129 , F_60 ) ;
V_17 = F_110 ( V_205 -> V_207 ) ;
V_17 = V_17 * sizeof( unsigned long ) ;
V_26 -> V_130 = F_3 ( V_17 , V_8 ) ;
if ( ! V_26 -> V_130 )
goto V_206;
V_26 -> V_145 = F_3 ( V_17 , V_8 ) ;
if ( ! V_26 -> V_145 )
goto V_206;
V_26 -> V_28 = V_28 ;
V_26 -> V_63 = F_44 ( V_28 -> V_29 -> V_11 ,
V_56 ,
& V_26 -> V_208 ,
V_8 ) ;
if ( ! V_26 -> V_63 )
goto V_206;
V_93 = ( long long ) ( long ) V_26 -> V_208 ;
V_26 -> V_60 = V_93 >> 32 ;
V_26 -> V_62 = V_93 & 0xffffffff ;
V_28 -> V_35 -> V_209 = F_33 ;
V_28 -> V_35 -> V_210 = F_30 ;
V_28 -> V_35 -> V_211 = F_32 ;
V_28 -> V_35 -> V_212 = F_66 ;
V_28 -> V_35 -> V_213 = F_69 ;
V_28 -> V_35 -> V_214 = F_71 ;
V_28 -> V_35 -> V_215 = F_73 ;
V_28 -> V_35 -> V_36 = V_26 ;
F_111 ( & V_26 -> V_65 ) ;
V_26 -> V_44 =
(struct V_37 * * ) V_205 -> V_44 ;
V_26 -> V_82 = (struct V_37 * * ) V_205 -> V_82 ;
V_26 -> V_207 = V_205 -> V_207 ;
V_26 -> V_84 = F_3 ( V_26 -> V_207 *
sizeof( * V_26 -> V_84 ) , V_8 ) ;
if ( ! V_26 -> V_84 )
goto V_206;
V_26 -> V_179 = V_205 -> V_179 ;
V_26 -> V_158 = V_205 -> V_158 ;
V_26 -> V_168 = V_216 ;
V_26 -> V_169 = V_217 ;
V_26 -> V_30 = F_1 ( V_218 ,
V_219 ) ;
if ( ! V_26 -> V_30 )
goto V_206;
V_26 -> V_27 = F_1 ( V_220 ,
V_221 ) ;
if ( ! V_26 -> V_27 )
goto V_206;
V_26 -> V_85 = F_112 ( V_28 -> V_29 -> V_11 ,
V_205 -> V_207 ) ;
if ( ! V_26 -> V_85 )
goto V_206;
F_31 ( V_69 , L_33 ,
V_26 -> V_158 , V_26 -> V_169 ,
V_26 -> V_168 ) ;
V_17 = 0 ;
do {
F_88 ( V_26 ) ;
if ( V_26 -> V_158 != V_26 -> V_159 )
F_113 ( 10 ) ;
else
break;
V_17 ++ ;
} while ( V_17 < 10 );
F_91 ( V_26 ) ;
F_78 ( V_26 ) ;
F_109 ( & V_26 -> V_106 , F_47 ) ;
F_114 ( & V_26 -> V_88 ) ;
F_115 ( & V_26 -> V_89 ) ;
return 0 ;
V_206:
if ( V_26 ) {
F_4 ( V_26 -> V_130 ) ;
F_4 ( V_26 -> V_145 ) ;
F_14 ( V_26 ) ;
F_4 ( V_26 -> V_84 ) ;
if ( V_26 -> V_63 )
F_35 ( V_28 -> V_29 -> V_11 ,
V_56 ,
V_26 -> V_63 ,
V_26 -> V_208 ) ;
F_4 ( V_26 ) ;
}
return - V_20 ;
}
void F_116 ( struct V_31 * V_28 )
{
struct V_25 * V_26 ;
struct V_86 * V_87 ;
F_31 ( V_222 , L_34 ) ;
if ( V_28 -> V_35 -> V_36 ) {
V_26 = (struct V_25 * ) V_28 -> V_35 -> V_36 ;
F_117 ( & V_26 -> V_106 ) ;
while ( ! F_39 ( & V_26 -> V_89 ) ) {
V_87 = F_40 ( & V_26 -> V_89 ,
struct V_86 ,
V_90 ) ;
F_41 ( & V_87 -> V_90 ) ;
F_4 ( V_87 ) ;
}
F_4 ( V_26 -> V_130 ) ;
F_4 ( V_26 -> V_145 ) ;
if ( V_26 -> V_131 )
F_118 ( V_26 -> V_131 ) ;
F_119 ( V_26 -> V_85 ) ;
F_35 ( V_28 -> V_29 -> V_11 ,
V_56 ,
V_26 -> V_63 , V_26 -> V_208 ) ;
F_14 ( V_26 ) ;
F_4 ( V_26 -> V_84 ) ;
F_4 ( V_26 ) ;
V_28 -> V_35 -> V_36 = NULL ;
}
}
