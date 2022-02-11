static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( V_8 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_2 ( V_9 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , const unsigned int V_10 ,
const int V_11 )
{
int * V_12 , V_13 = 0 ;
F_4 ( & V_2 -> V_14 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_11 ) ;
* V_12 += V_10 ;
V_2 -> V_17 -- ;
if ( V_2 -> V_17 == 0 && ( V_11 & V_18 ) != V_19 )
V_13 = F_1 ( V_2 ) ;
else if ( V_2 -> V_17 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_13 )
F_7 ( V_2 ) ;
}
static void
F_8 ( struct V_1 * V_2 , const int V_12 )
{
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 = V_12 ;
F_5 ( & V_2 -> V_14 ) ;
}
static int *
F_9 ( struct V_1 * V_2 , const int V_11 )
{
switch ( V_11 ) {
case V_21 :
return & V_2 -> V_4 ;
case V_22 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_10 ( struct V_23 * V_24 )
{
return F_11 ( ( (struct V_25 * ) V_24 -> V_26 ) -> V_27 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_4 ( & V_28 ) ;
V_24 = V_2 -> V_29 ++ ;
F_5 ( & V_28 ) ;
return V_24 ;
}
static struct V_23 *
F_13 ( struct V_1 * V_2 , char * V_30 )
{
struct V_23 * V_24 ;
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
F_4 ( & V_28 ) ;
F_14 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_31 -> V_32 ) &&
( V_24 -> V_33 == V_34 ) &&
( V_24 -> V_35 == V_31 -> V_36 ) ) {
F_5 ( & V_28 ) ;
return V_24 ;
}
}
F_5 ( & V_28 ) ;
return NULL ;
}
static void
F_15 ( void * V_30 )
{
#ifdef F_16
struct V_25 * V_37 = (struct V_25 * ) V_30 ;
F_2 ( V_8 , L_3 ,
V_37 -> V_36 , V_37 -> V_38 , V_37 -> V_39 , V_37 -> V_32 ,
V_37 -> V_40 ) ;
F_2 ( V_8 , L_4 , V_37 , F_17 ( V_37 ) ) ;
#endif
}
static bool
F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == 0 ;
}
static int
F_19 ( const unsigned int V_42 , struct V_43 * V_44 )
{
int V_13 ;
V_44 -> V_2 -> V_29 = 0 ;
V_13 = F_20 ( V_42 , V_44 ) ;
if ( V_13 == - V_45 )
V_13 = - V_46 ;
return V_13 ;
}
static unsigned int
F_21 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_51 ;
V_51 = V_50 -> V_51 ? V_50 -> V_51 : V_52 ;
V_51 = F_22 (unsigned int, wsize, server->max_write) ;
V_51 = F_22 (unsigned int, wsize, 2 << 15 ) ;
return V_51 ;
}
static unsigned int
F_23 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_53 ;
V_53 = V_50 -> V_53 ? V_50 -> V_53 : V_52 ;
V_53 = F_22 (unsigned int, rsize, server->max_read) ;
V_53 = F_22 (unsigned int, rsize, 2 << 15 ) ;
return V_53 ;
}
static int
F_24 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 )
{
int V_13 ;
T_2 * V_57 ;
T_3 V_58 = V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
V_57 = F_25 ( V_56 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = & V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , V_57 , & V_58 , NULL ) ;
if ( V_13 ) {
F_27 ( V_57 ) ;
return V_13 ;
}
V_13 = F_28 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ) ;
F_27 ( V_57 ) ;
return V_13 ;
}
static int
F_29 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 ,
T_4 * V_73 , T_5 * V_74 )
{
* V_73 = F_30 ( V_74 -> V_75 ) ;
return 0 ;
}
static int
F_31 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 , T_5 * V_74 )
{
int V_13 ;
struct V_76 * V_77 ;
V_77 = F_32 ( sizeof( struct V_76 ) + V_78 * 2 ,
V_79 ) ;
if ( V_77 == NULL )
return - V_64 ;
V_13 = F_33 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ,
V_77 ) ;
if ( ! V_13 )
F_34 ( V_74 , V_77 ) ;
F_27 ( V_77 ) ;
return V_13 ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_36 ( struct V_47 * V_48 )
{
#ifdef F_37
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
F_38 ( & V_48 -> V_82 . V_83 . V_84 [ V_80 ] , 0 ) ;
F_38 ( & V_48 -> V_82 . V_83 . V_85 [ V_80 ] , 0 ) ;
}
#endif
}
static void
F_39 ( struct V_86 * V_87 , struct V_47 * V_48 )
{
F_40 ( V_87 , L_5 ) ;
if ( V_48 -> V_88 & V_89 )
F_40 ( V_87 , L_6 ) ;
if ( V_48 -> V_88 & V_90 )
F_40 ( V_87 , L_7 ) ;
if ( V_48 -> V_88 & V_91 )
F_40 ( V_87 , L_8 ) ;
if ( V_48 -> V_88 & V_92 )
F_40 ( V_87 , L_9 ) ;
if ( V_48 -> V_88 & V_93 )
F_40 ( V_87 , L_10 ) ;
if ( V_48 -> V_88 == 0 )
F_40 ( V_87 , L_11 ) ;
F_41 ( V_87 , L_12 , V_48 -> V_94 ) ;
}
static void
F_42 ( struct V_86 * V_87 , struct V_47 * V_48 )
{
#ifdef F_37
T_6 * V_95 = V_48 -> V_82 . V_83 . V_84 ;
T_6 * V_96 = V_48 -> V_82 . V_83 . V_85 ;
F_41 ( V_87 , L_13 ,
F_43 ( & V_95 [ V_97 ] ) ,
F_43 ( & V_96 [ V_97 ] ) ) ;
F_41 ( V_87 , L_14 ,
F_43 ( & V_95 [ V_98 ] ) ,
F_43 ( & V_96 [ V_98 ] ) ) ;
F_41 ( V_87 , L_15 ,
F_43 ( & V_95 [ V_99 ] ) ,
F_43 ( & V_96 [ V_99 ] ) ) ;
F_41 ( V_87 , L_16 ,
F_43 ( & V_95 [ V_100 ] ) ,
F_43 ( & V_96 [ V_100 ] ) ) ;
F_41 ( V_87 , L_17 ,
F_43 ( & V_95 [ V_101 ] ) ,
F_43 ( & V_96 [ V_101 ] ) ) ;
F_41 ( V_87 , L_18 ,
F_43 ( & V_95 [ V_102 ] ) ,
F_43 ( & V_96 [ V_102 ] ) ) ;
F_41 ( V_87 , L_19 ,
F_43 ( & V_95 [ V_103 ] ) ,
F_43 ( & V_96 [ V_103 ] ) ) ;
F_41 ( V_87 , L_20 ,
F_43 ( & V_95 [ V_104 ] ) ,
F_43 ( & V_96 [ V_104 ] ) ) ;
F_41 ( V_87 , L_21 ,
F_43 ( & V_95 [ V_105 ] ) ,
F_43 ( & V_96 [ V_105 ] ) ) ;
F_41 ( V_87 , L_22 ,
F_43 ( & V_95 [ V_106 ] ) ,
F_43 ( & V_96 [ V_106 ] ) ) ;
F_41 ( V_87 , L_23 ,
F_43 ( & V_95 [ V_107 ] ) ,
F_43 ( & V_96 [ V_107 ] ) ) ;
F_41 ( V_87 , L_24 ,
F_43 ( & V_95 [ V_108 ] ) ,
F_43 ( & V_96 [ V_108 ] ) ) ;
F_41 ( V_87 , L_25 ,
F_43 ( & V_95 [ V_109 ] ) ,
F_43 ( & V_96 [ V_109 ] ) ) ;
F_41 ( V_87 , L_26 ,
F_43 ( & V_95 [ V_110 ] ) ,
F_43 ( & V_96 [ V_110 ] ) ) ;
F_41 ( V_87 , L_27 ,
F_43 ( & V_95 [ V_111 ] ) ,
F_43 ( & V_96 [ V_111 ] ) ) ;
F_41 ( V_87 , L_28 ,
F_43 ( & V_95 [ V_112 ] ) ,
F_43 ( & V_96 [ V_112 ] ) ) ;
F_41 ( V_87 , L_29 ,
F_43 ( & V_95 [ V_113 ] ) ,
F_43 ( & V_96 [ V_113 ] ) ) ;
F_41 ( V_87 , L_30 ,
F_43 ( & V_95 [ V_114 ] ) ,
F_43 ( & V_96 [ V_114 ] ) ) ;
F_41 ( V_87 , L_31 ,
F_43 ( & V_95 [ V_115 ] ) ,
F_43 ( & V_96 [ V_115 ] ) ) ;
#endif
}
static void
F_44 ( struct V_116 * V_117 , struct V_62 * V_63 , T_7 V_58 )
{
struct V_118 * V_119 = F_45 ( V_117 -> V_120 -> V_121 ) ;
V_117 -> V_63 . V_71 = V_63 -> V_71 ;
V_117 -> V_63 . V_72 = V_63 -> V_72 ;
F_46 ( V_119 , V_58 ) ;
V_119 -> V_122 = V_119 -> V_123 ;
}
static void
F_47 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static int
F_48 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
return F_49 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static unsigned int
F_50 ( char * V_30 )
{
struct V_124 * V_125 = (struct V_124 * ) V_30 ;
return V_125 -> V_126 ;
}
static unsigned int
F_51 ( char * V_30 )
{
struct V_124 * V_125 = (struct V_124 * ) V_30 ;
return F_52 ( V_125 -> V_127 ) ;
}
static int
F_53 ( const unsigned int V_42 , struct V_116 * V_117 ,
struct V_128 * V_129 , unsigned int * V_130 ,
char * * V_30 , int * V_131 )
{
V_129 -> V_71 = V_117 -> V_63 . V_71 ;
V_129 -> V_72 = V_117 -> V_63 . V_72 ;
return F_54 ( V_42 , V_129 , V_130 , V_30 , V_131 ) ;
}
static int
F_55 ( const unsigned int V_42 , struct V_116 * V_117 ,
struct V_128 * V_129 , unsigned int * V_132 ,
struct V_133 * V_134 , unsigned long V_135 )
{
V_129 -> V_71 = V_117 -> V_63 . V_71 ;
V_129 -> V_72 = V_117 -> V_63 . V_72 ;
return F_56 ( V_42 , V_129 , V_132 , V_134 , V_135 ) ;
}
static int
F_57 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_116 * V_117 , T_1 V_136 , bool V_137 )
{
T_8 V_138 = F_58 ( V_136 ) ;
return F_59 ( V_42 , V_48 , V_117 -> V_63 . V_71 ,
V_117 -> V_63 . V_72 , V_117 -> V_139 , & V_138 ) ;
}
static int
F_60 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_140 , struct V_54 * V_55 ,
struct V_62 * V_63 , T_9 V_141 ,
struct V_142 * V_143 )
{
T_2 * V_57 ;
int V_13 ;
T_3 V_58 = V_59 ;
struct V_60 V_61 ;
V_57 = F_25 ( V_140 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 | V_144 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , V_57 , & V_58 , NULL ) ;
F_27 ( V_57 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_32 ) ;
return V_13 ;
}
V_143 -> V_145 = 0 ;
V_143 -> V_146 = 0 ;
V_13 = F_61 ( V_42 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 , 0 , V_143 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_33 ) ;
F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
return V_13 ;
}
static int
F_62 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 , T_9 V_141 ,
struct V_142 * V_143 )
{
return F_61 ( V_42 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 , 0 , V_143 ) ;
}
static int
F_63 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
return F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static bool
F_64 ( char * V_30 , struct V_1 * V_2 , int V_147 )
{
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
if ( V_31 -> V_38 != V_148 )
return false ;
if ( ! V_147 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_31 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_65 ( struct V_47 * V_48 , struct V_62 * V_63 ,
struct V_118 * V_119 )
{
if ( V_48 -> V_44 -> V_2 -> V_88 & V_149 )
return F_66 ( 0 , V_48 , V_119 -> V_150 ,
F_67 ( V_119 ) ) ;
return F_68 ( 0 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 ,
V_119 -> V_151 ? 1 : 0 ) ;
}
static int
F_69 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_152 * V_30 )
{
int V_13 ;
T_2 V_153 = 0 ;
T_10 V_58 = V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = & V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , & V_153 , & V_58 , NULL ) ;
if ( V_13 )
return V_13 ;
V_30 -> V_154 = V_155 ;
V_13 = F_70 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ,
V_30 ) ;
F_28 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ) ;
return V_13 ;
}
static bool
F_71 ( struct V_116 * V_156 , struct V_116 * V_157 )
{
return V_156 -> V_63 . V_71 == V_157 -> V_63 . V_71 &&
V_156 -> V_63 . V_72 == V_157 -> V_63 . V_72 ;
}
static int
F_72 ( const unsigned int V_42 , struct V_116 * V_117 , T_1 V_158 ,
T_1 V_147 , T_7 type , int V_159 , int V_160 , bool V_161 )
{
if ( V_160 && ! V_159 )
type = V_162 ;
return F_73 ( V_42 , F_74 ( V_117 -> V_163 ) ,
V_117 -> V_63 . V_71 , V_117 -> V_63 . V_72 ,
V_164 -> V_165 , V_147 , V_158 , type , V_161 ) ;
}
static void
F_75 ( struct V_166 * V_166 , struct V_62 * V_63 )
{
memcpy ( V_63 -> V_150 , F_45 ( V_166 ) -> V_150 , V_167 ) ;
}
static void
F_76 ( struct V_166 * V_166 , struct V_62 * V_63 )
{
memcpy ( F_45 ( V_166 ) -> V_150 , V_63 -> V_150 , V_167 ) ;
}
static void
F_77 ( struct V_62 * V_63 )
{
F_78 ( V_63 -> V_150 , V_167 ) ;
}
