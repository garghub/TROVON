static inline bool F_1 ( struct V_1 * V_2 )
{
bool V_3 = true ;
if ( F_2 ( F_3 ( V_2 ) ) ) {
V_3 = false ;
F_4 ( V_2 ) ;
}
return V_3 ;
}
static inline void F_5 ( struct V_4 * V_5 )
{
F_6 ( ! F_7 ( & V_5 -> V_6 ) ) ;
}
static inline void F_8 ( struct V_4 * V_5 )
{
F_6 ( ! F_1 ( & V_5 -> V_6 ) ) ;
}
static inline void F_9 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_6 ( ! ( F_10 ( & V_8 -> V_6 ) &&
F_7 ( & V_5 -> V_6 ) ) &&
! F_1 ( & V_5 -> V_6 ) ) ;
}
static inline void F_11 ( struct V_10 * V_11 )
{
F_6 ( ! F_10 ( & V_11 -> V_6 ) ) ;
}
static inline void F_5 ( struct V_4 * V_5 ) { }
static inline void F_8 ( struct V_4 * V_5 ) { }
static inline void F_9 ( struct V_7 * V_8 ) { }
static inline void F_11 ( struct V_10 * V_11 ) { }
static int F_12 ( struct V_12 * V_13 , T_1 V_14 , T_1 * V_15 ,
T_1 * V_16 , T_1 * V_17 , T_1 * V_18 )
{
T_1 V_19 = * V_15 ;
int V_20 ;
V_20 = F_13 ( V_13 , V_14 , V_19 , V_16 ,
V_17 , V_18 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( * V_18 < V_19 ) {
* V_15 = * V_18 ;
F_14 ( L_1 ,
V_19 - * V_15 , V_14 , * V_15 ) ;
}
F_14 ( L_2 , * V_16 , * V_17 , * V_18 ) ;
return 0 ;
}
static void F_15 ( struct V_21 * V_22 )
{
memset ( V_22 , 0 , sizeof ( * V_22 ) ) ;
V_22 -> type = V_23 ;
}
static void F_16 ( struct V_21 * V_22 ,
struct V_24 * * V_25 , T_1 V_26 , T_2 V_27 ,
bool V_28 , bool V_29 )
{
V_22 -> type = V_30 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_26 = V_26 ;
V_22 -> V_27 = V_27 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_29 = V_29 ;
}
static void F_17 ( struct V_21 * V_22 ,
struct V_31 * V_32 )
{
V_22 -> type = V_33 ;
V_22 -> V_32 = V_32 ;
}
static void F_18 ( struct V_21 * V_22 ,
struct V_34 * V_34 , T_3 V_35 )
{
V_22 -> type = V_36 ;
V_22 -> V_34 = V_34 ;
V_22 -> V_35 = V_35 ;
}
static struct V_21 *
F_19 ( struct V_37 * V_38 , unsigned int V_39 )
{
F_20 ( V_39 >= V_38 -> V_40 ) ;
return & V_38 -> V_41 [ V_39 ] . V_42 ;
}
struct V_21 *
F_21 ( struct V_37 * V_38 ,
unsigned int V_39 )
{
return F_22 ( V_38 , V_39 , V_43 , V_22 ) ;
}
void F_23 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_24 * * V_25 ,
T_1 V_26 , T_2 V_27 ,
bool V_28 , bool V_29 )
{
struct V_21 * V_22 ;
V_22 = F_19 ( V_38 , V_39 ) ;
F_16 ( V_22 , V_25 , V_26 , V_27 ,
V_28 , V_29 ) ;
}
void F_24 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_24 * * V_25 ,
T_1 V_26 , T_2 V_27 ,
bool V_28 , bool V_29 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_43 , V_22 ) ;
F_16 ( V_22 , V_25 , V_26 , V_27 ,
V_28 , V_29 ) ;
}
void F_25 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_31 * V_32 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_43 , V_22 ) ;
F_17 ( V_22 , V_32 ) ;
}
void F_26 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_34 * V_34 , T_3 V_35 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_43 , V_22 ) ;
F_18 ( V_22 , V_34 , V_35 ) ;
}
static void F_27 (
struct V_37 * V_38 ,
unsigned int V_39 , struct V_31 * V_32 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_44 , V_45 ) ;
F_17 ( V_22 , V_32 ) ;
}
void F_28 (
struct V_37 * V_38 ,
unsigned int V_39 , struct V_31 * V_32 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_44 , V_46 ) ;
F_17 ( V_22 , V_32 ) ;
V_38 -> V_41 [ V_39 ] . V_44 . V_47 += V_32 -> V_26 ;
V_38 -> V_41 [ V_39 ] . V_47 += V_32 -> V_26 ;
}
void F_29 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_24 * * V_25 , T_1 V_26 ,
T_2 V_27 , bool V_28 , bool V_29 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_44 , V_46 ) ;
F_16 ( V_22 , V_25 , V_26 , V_27 ,
V_28 , V_29 ) ;
V_38 -> V_41 [ V_39 ] . V_44 . V_47 += V_26 ;
V_38 -> V_41 [ V_39 ] . V_47 += V_26 ;
}
void F_30 ( struct V_37 * V_38 ,
unsigned int V_39 , struct V_24 * * V_25 , T_1 V_26 ,
T_2 V_27 , bool V_28 , bool V_29 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_38 , V_39 , V_44 , V_48 ) ;
F_16 ( V_22 , V_25 , V_26 , V_27 ,
V_28 , V_29 ) ;
}
static T_1 F_31 ( struct V_21 * V_22 )
{
switch ( V_22 -> type ) {
case V_23 :
return 0 ;
case V_30 :
return V_22 -> V_26 ;
case V_33 :
return ( T_1 ) V_22 -> V_32 -> V_26 ;
#ifdef F_32
case V_36 :
return ( T_1 ) V_22 -> V_35 ;
#endif
default:
F_33 ( true , L_3 , ( int ) V_22 -> type ) ;
return 0 ;
}
}
static void F_34 ( struct V_21 * V_22 )
{
if ( V_22 -> type == V_30 && V_22 -> V_29 ) {
int V_49 ;
V_49 = F_35 ( ( T_1 ) V_22 -> V_27 ,
( T_1 ) V_22 -> V_26 ) ;
F_36 ( V_22 -> V_25 , V_49 ) ;
}
F_15 ( V_22 ) ;
}
static void F_37 ( struct V_37 * V_38 ,
unsigned int V_39 )
{
struct V_50 * V_51 ;
F_20 ( V_39 >= V_38 -> V_40 ) ;
V_51 = & V_38 -> V_41 [ V_39 ] ;
switch ( V_51 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
F_34 ( & V_51 -> V_43 . V_22 ) ;
break;
case V_55 :
F_34 ( & V_51 -> V_44 . V_45 ) ;
F_34 ( & V_51 -> V_44 . V_46 ) ;
F_34 ( & V_51 -> V_44 . V_48 ) ;
break;
case V_56 :
case V_57 :
F_34 ( & V_51 -> V_58 . V_22 ) ;
break;
case V_59 :
F_34 ( & V_51 -> V_42 ) ;
break;
case V_60 :
F_34 ( & V_51 -> V_61 . V_46 ) ;
break;
case V_62 :
F_34 ( & V_51 -> V_63 . V_46 ) ;
F_34 ( & V_51 -> V_63 . V_48 ) ;
break;
case V_64 :
F_34 ( & V_51 -> V_65 . V_48 ) ;
break;
default:
break;
}
}
static void F_38 ( struct V_66 * V_67 )
{
F_39 ( & V_67 -> V_68 ) ;
F_40 ( & V_67 -> V_69 ) ;
F_39 ( & V_67 -> V_70 ) ;
F_40 ( & V_67 -> V_71 ) ;
F_41 ( & V_67 -> V_72 ) ;
F_41 ( & V_67 -> V_73 ) ;
V_67 -> V_74 = - 1 ;
V_67 -> V_75 = - 1 ;
V_67 -> V_8 = V_76 ;
}
static void F_42 ( struct V_66 * V_77 ,
const struct V_66 * V_78 )
{
F_43 ( & V_77 -> V_68 , & V_78 -> V_68 ) ;
F_44 ( & V_77 -> V_69 , & V_78 -> V_69 ) ;
F_43 ( & V_77 -> V_70 , & V_78 -> V_70 ) ;
F_44 ( & V_77 -> V_71 , & V_78 -> V_71 ) ;
V_77 -> V_79 = V_78 -> V_79 ;
V_77 -> V_80 = V_78 -> V_80 ;
V_77 -> V_81 = V_78 -> V_81 ;
V_77 -> V_82 = V_78 -> V_82 ;
F_45 ( & V_77 -> V_72 , & V_78 -> V_72 ) ;
F_45 ( & V_77 -> V_73 , & V_78 -> V_73 ) ;
V_77 -> V_74 = V_78 -> V_74 ;
V_77 -> V_75 = V_78 -> V_75 ;
V_77 -> V_83 = V_78 -> V_83 ;
V_77 -> V_84 = V_78 -> V_84 ;
V_77 -> V_85 = V_78 -> V_85 ;
V_77 -> V_86 = V_78 -> V_86 ;
V_77 -> V_87 = V_78 -> V_87 ;
V_77 -> V_8 = V_78 -> V_8 ;
}
static void F_46 ( struct V_66 * V_67 )
{
F_47 ( & V_67 -> V_68 ) ;
F_48 ( & V_67 -> V_69 ) ;
F_47 ( & V_67 -> V_70 ) ;
F_48 ( & V_67 -> V_71 ) ;
}
static void F_49 ( struct V_37 * V_88 )
{
F_6 ( ! F_50 ( & V_88 -> V_89 ) ) ;
F_6 ( ! F_50 ( & V_88 -> V_90 ) ) ;
F_6 ( ! F_51 ( & V_88 -> V_91 ) ) ;
F_6 ( V_88 -> V_92 ) ;
}
static void F_52 ( struct V_93 * V_93 )
{
struct V_37 * V_88 = F_53 ( V_93 ,
struct V_37 , V_94 ) ;
unsigned int V_39 ;
F_14 ( L_4 , V_95 , V_88 ,
V_88 -> V_96 , V_88 -> V_97 ) ;
F_49 ( V_88 ) ;
if ( V_88 -> V_96 )
F_54 ( V_88 -> V_96 ) ;
if ( V_88 -> V_97 )
F_54 ( V_88 -> V_97 ) ;
for ( V_39 = 0 ; V_39 < V_88 -> V_40 ; V_39 ++ )
F_37 ( V_88 , V_39 ) ;
F_46 ( & V_88 -> V_98 ) ;
F_55 ( V_88 -> V_99 ) ;
if ( V_88 -> V_100 )
F_56 ( V_88 , V_88 -> V_101 -> V_102 ) ;
else if ( V_88 -> V_40 <= V_103 )
F_57 ( V_104 , V_88 ) ;
else
F_58 ( V_88 ) ;
}
void F_59 ( struct V_37 * V_88 )
{
F_14 ( L_5 , V_95 , V_88 ,
F_60 ( & V_88 -> V_94 ) ) ;
F_61 ( & V_88 -> V_94 ) ;
}
void F_62 ( struct V_37 * V_88 )
{
if ( V_88 ) {
F_14 ( L_5 , V_95 , V_88 ,
F_60 ( & V_88 -> V_94 ) ) ;
F_63 ( & V_88 -> V_94 , F_52 ) ;
}
}
static void F_64 ( struct V_37 * V_88 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
F_65 ( & V_88 -> V_94 ) ;
F_66 ( & V_88 -> V_105 ) ;
F_67 ( & V_88 -> V_89 ) ;
F_67 ( & V_88 -> V_90 ) ;
F_68 ( & V_88 -> V_91 ) ;
F_38 ( & V_88 -> V_98 ) ;
}
static void F_69 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
bool V_106 = V_88 -> V_100 ;
unsigned int V_107 = V_88 -> V_40 ;
T_1 V_108 = V_88 -> V_109 ;
struct V_110 * V_111 = V_88 -> V_99 ;
bool V_112 = V_88 -> V_113 ;
struct V_114 * V_115 = V_88 -> V_96 ;
struct V_114 * V_116 = V_88 -> V_97 ;
F_14 ( L_6 , V_95 , V_88 ) ;
F_6 ( F_60 ( & V_88 -> V_94 ) != 1 ) ;
F_49 ( V_88 ) ;
F_6 ( F_60 ( & V_115 -> V_93 ) != 1 ) ;
F_6 ( F_60 ( & V_116 -> V_93 ) != 1 ) ;
F_46 ( & V_88 -> V_98 ) ;
F_64 ( V_88 ) ;
V_88 -> V_101 = V_5 ;
V_88 -> V_100 = V_106 ;
V_88 -> V_40 = V_107 ;
V_88 -> V_109 = V_108 ;
V_88 -> V_99 = V_111 ;
V_88 -> V_113 = V_112 ;
V_88 -> V_96 = V_115 ;
V_88 -> V_97 = V_116 ;
}
struct V_37 * F_70 ( struct V_4 * V_5 ,
struct V_110 * V_111 ,
unsigned int V_107 ,
bool V_117 ,
T_4 V_118 )
{
struct V_37 * V_88 ;
if ( V_117 ) {
F_20 ( V_107 > V_103 ) ;
V_88 = F_71 ( V_5 -> V_102 , V_118 ) ;
} else if ( V_107 <= V_103 ) {
V_88 = F_72 ( V_104 , V_118 ) ;
} else {
F_20 ( V_107 > V_119 ) ;
V_88 = F_73 ( sizeof( * V_88 ) + V_107 * sizeof( V_88 -> V_41 [ 0 ] ) ,
V_118 ) ;
}
if ( F_2 ( ! V_88 ) )
return NULL ;
F_64 ( V_88 ) ;
V_88 -> V_101 = V_5 ;
V_88 -> V_100 = V_117 ;
V_88 -> V_40 = V_107 ;
V_88 -> V_109 = V_120 ;
V_88 -> V_99 = F_74 ( V_111 ) ;
F_14 ( L_6 , V_95 , V_88 ) ;
return V_88 ;
}
static int F_75 ( const struct V_121 * V_122 )
{
return 8 + 4 + 4 + 4 + ( V_122 -> V_123 ? V_122 -> V_123 -> V_124 : 0 ) ;
}
int F_76 ( struct V_37 * V_88 , T_4 V_125 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_114 * V_126 ;
int V_127 ;
F_6 ( F_77 ( & V_88 -> V_128 ) ) ;
F_6 ( F_78 ( & V_88 -> V_129 ) ) ;
V_127 = V_130 +
V_131 + 1 ;
V_127 += 4 + 4 + 4 ;
V_127 += V_130 +
sizeof( struct V_132 ) ;
V_127 += sizeof( struct V_133 ) ;
V_127 += 4 + sizeof( struct V_134 ) ;
V_127 += V_130 +
F_75 ( & V_88 -> V_129 ) ;
V_127 += 4 + V_88 -> V_128 . V_135 ;
V_127 += 2 + V_88 -> V_40 * sizeof( struct V_136 ) ;
V_127 += 8 ;
V_127 += 8 ;
V_127 += 4 + 8 * ( V_88 -> V_99 ? V_88 -> V_99 -> V_137 : 0 ) ;
V_127 += 4 + 8 ;
if ( V_88 -> V_100 )
V_126 = F_79 ( & V_5 -> V_138 , 0 ) ;
else
V_126 = F_80 ( V_139 , V_127 , V_125 , true ) ;
if ( ! V_126 )
return - V_140 ;
memset ( V_126 -> V_141 . V_142 , 0 , V_126 -> V_141 . V_143 ) ;
V_88 -> V_96 = V_126 ;
V_127 = V_144 ;
V_127 += V_88 -> V_128 . V_135 ;
V_127 += V_88 -> V_40 * sizeof( struct V_136 ) ;
if ( V_88 -> V_100 )
V_126 = F_79 ( & V_5 -> V_145 , 0 ) ;
else
V_126 = F_80 ( V_146 , V_127 , V_125 , true ) ;
if ( ! V_126 )
return - V_140 ;
V_88 -> V_97 = V_126 ;
return 0 ;
}
static bool F_81 ( T_5 V_147 )
{
switch ( V_147 ) {
#define F_82 ( V_51 , V_147 , T_6 ) case CEPH_OSD_OP_##op: return true;
F_83 (GENERATE_CASE)
#undef F_82
default:
return false ;
}
}
static struct V_50 *
F_84 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_147 , T_2 V_84 )
{
struct V_50 * V_51 ;
F_20 ( V_39 >= V_38 -> V_40 ) ;
F_20 ( ! F_81 ( V_147 ) ) ;
V_51 = & V_38 -> V_41 [ V_39 ] ;
memset ( V_51 , 0 , sizeof ( * V_51 ) ) ;
V_51 -> V_51 = V_147 ;
V_51 -> V_84 = V_84 ;
return V_51 ;
}
void F_85 ( struct V_37 * V_38 ,
unsigned int V_39 , T_5 V_147 , T_2 V_84 )
{
( void ) F_84 ( V_38 , V_39 , V_147 , V_84 ) ;
}
void F_86 ( struct V_37 * V_38 ,
unsigned int V_39 , T_5 V_147 ,
T_1 V_148 , T_1 V_26 ,
T_1 V_149 , T_2 V_150 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_147 , 0 ) ;
T_3 V_151 = 0 ;
F_20 ( V_147 != V_52 && V_147 != V_53 &&
V_147 != V_54 && V_147 != V_152 &&
V_147 != V_153 ) ;
V_51 -> V_43 . V_148 = V_148 ;
V_51 -> V_43 . V_26 = V_26 ;
V_51 -> V_43 . V_149 = V_149 ;
V_51 -> V_43 . V_150 = V_150 ;
if ( V_147 == V_53 || V_147 == V_54 )
V_151 += V_26 ;
V_51 -> V_47 = V_151 ;
}
void F_87 ( struct V_37 * V_38 ,
unsigned int V_39 , T_1 V_26 )
{
struct V_50 * V_51 ;
T_1 V_154 ;
F_20 ( V_39 >= V_38 -> V_40 ) ;
V_51 = & V_38 -> V_41 [ V_39 ] ;
V_154 = V_51 -> V_43 . V_26 ;
if ( V_26 == V_154 )
return;
F_20 ( V_26 > V_154 ) ;
V_51 -> V_43 . V_26 = V_26 ;
if ( V_51 -> V_51 == V_53 || V_51 -> V_51 == V_54 )
V_51 -> V_47 -= V_154 - V_26 ;
}
void F_88 ( struct V_37 * V_38 ,
unsigned int V_39 , T_1 V_155 )
{
struct V_50 * V_51 , * V_156 ;
F_20 ( V_39 + 1 >= V_38 -> V_40 ) ;
V_156 = & V_38 -> V_41 [ V_39 ] ;
V_51 = F_84 ( V_38 , V_39 + 1 , V_156 -> V_51 , V_156 -> V_84 ) ;
V_51 -> V_47 = V_156 -> V_47 ;
V_51 -> V_157 = V_156 -> V_157 ;
V_51 -> V_43 = V_156 -> V_43 ;
V_51 -> V_43 . V_148 += V_155 ;
V_51 -> V_43 . V_26 -= V_155 ;
if ( V_51 -> V_51 == V_53 || V_51 -> V_51 == V_54 )
V_51 -> V_47 -= V_155 ;
}
void F_89 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_147 , const char * V_158 , const char * V_159 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_147 , 0 ) ;
struct V_31 * V_32 ;
T_3 V_151 = 0 ;
T_3 V_74 ;
F_20 ( V_147 != V_55 ) ;
V_32 = F_73 ( sizeof ( * V_32 ) , V_160 ) ;
F_20 ( ! V_32 ) ;
F_90 ( V_32 ) ;
V_51 -> V_44 . V_161 = V_158 ;
V_74 = strlen ( V_158 ) ;
F_20 ( V_74 > ( T_3 ) V_162 ) ;
V_51 -> V_44 . V_163 = V_74 ;
F_91 ( V_32 , V_158 , V_74 ) ;
V_151 += V_74 ;
V_51 -> V_44 . V_164 = V_159 ;
V_74 = strlen ( V_159 ) ;
F_20 ( V_74 > ( T_3 ) V_162 ) ;
V_51 -> V_44 . V_165 = V_74 ;
F_91 ( V_32 , V_159 , V_74 ) ;
V_151 += V_74 ;
F_27 ( V_38 , V_39 , V_32 ) ;
V_51 -> V_47 = V_151 ;
}
int F_92 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_147 , const char * V_166 , const void * V_167 ,
T_3 V_74 , T_7 V_168 , T_7 V_169 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_147 , 0 ) ;
struct V_31 * V_32 ;
T_3 V_151 ;
F_20 ( V_147 != V_56 && V_147 != V_57 ) ;
V_32 = F_73 ( sizeof( * V_32 ) , V_160 ) ;
if ( ! V_32 )
return - V_140 ;
F_90 ( V_32 ) ;
V_151 = strlen ( V_166 ) ;
V_51 -> V_58 . V_135 = V_151 ;
F_91 ( V_32 , V_166 , V_151 ) ;
V_51 -> V_58 . V_170 = V_74 ;
F_91 ( V_32 , V_167 , V_74 ) ;
V_151 += V_74 ;
V_51 -> V_58 . V_168 = V_168 ;
V_51 -> V_58 . V_169 = V_169 ;
F_17 ( & V_51 -> V_58 . V_22 , V_32 ) ;
V_51 -> V_47 = V_151 ;
return 0 ;
}
static void F_93 ( struct V_37 * V_88 , int V_39 ,
T_1 V_171 , T_7 V_172 )
{
struct V_50 * V_51 ;
V_51 = F_84 ( V_88 , V_39 , V_173 , 0 ) ;
V_51 -> V_174 . V_171 = V_171 ;
V_51 -> V_174 . V_51 = V_172 ;
V_51 -> V_174 . V_175 = 0 ;
}
void F_94 ( struct V_37 * V_38 ,
unsigned int V_39 ,
T_1 V_176 ,
T_1 V_177 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_178 ,
0 ) ;
V_51 -> V_179 . V_176 = V_176 ;
V_51 -> V_179 . V_177 = V_177 ;
V_51 -> V_84 |= V_180 ;
}
static void F_95 ( struct V_114 * V_126 ,
struct V_21 * V_22 )
{
T_1 V_26 = F_31 ( V_22 ) ;
if ( V_22 -> type == V_30 ) {
F_20 ( V_26 > ( T_1 ) V_181 ) ;
if ( V_26 )
F_96 ( V_126 , V_22 -> V_25 ,
V_26 , V_22 -> V_27 ) ;
} else if ( V_22 -> type == V_33 ) {
F_20 ( ! V_26 ) ;
F_97 ( V_126 , V_22 -> V_32 ) ;
#ifdef F_32
} else if ( V_22 -> type == V_36 ) {
F_98 ( V_126 , V_22 -> V_34 , V_26 ) ;
#endif
} else {
F_20 ( V_22 -> type != V_23 ) ;
}
}
static T_2 F_99 ( struct V_136 * V_182 ,
const struct V_50 * V_78 )
{
if ( F_6 ( ! F_81 ( V_78 -> V_51 ) ) ) {
F_100 ( L_7 , V_78 -> V_51 ) ;
return 0 ;
}
switch ( V_78 -> V_51 ) {
case V_59 :
break;
case V_52 :
case V_53 :
case V_54 :
case V_152 :
case V_153 :
V_182 -> V_43 . V_148 = F_101 ( V_78 -> V_43 . V_148 ) ;
V_182 -> V_43 . V_26 = F_101 ( V_78 -> V_43 . V_26 ) ;
V_182 -> V_43 . V_149 =
F_101 ( V_78 -> V_43 . V_149 ) ;
V_182 -> V_43 . V_150 =
F_102 ( V_78 -> V_43 . V_150 ) ;
break;
case V_55 :
V_182 -> V_44 . V_163 = V_78 -> V_44 . V_163 ;
V_182 -> V_44 . V_165 = V_78 -> V_44 . V_165 ;
V_182 -> V_44 . V_47 = F_102 ( V_78 -> V_44 . V_47 ) ;
break;
case V_183 :
break;
case V_173 :
V_182 -> V_174 . V_171 = F_101 ( V_78 -> V_174 . V_171 ) ;
V_182 -> V_174 . V_184 = F_101 ( 0 ) ;
V_182 -> V_174 . V_51 = V_78 -> V_174 . V_51 ;
V_182 -> V_174 . V_175 = F_102 ( V_78 -> V_174 . V_175 ) ;
break;
case V_60 :
break;
case V_62 :
V_182 -> V_63 . V_171 = F_101 ( V_78 -> V_63 . V_171 ) ;
break;
case V_64 :
break;
case V_178 :
V_182 -> V_179 . V_176 =
F_101 ( V_78 -> V_179 . V_176 ) ;
V_182 -> V_179 . V_177 =
F_101 ( V_78 -> V_179 . V_177 ) ;
break;
case V_56 :
case V_57 :
V_182 -> V_58 . V_135 = F_102 ( V_78 -> V_58 . V_135 ) ;
V_182 -> V_58 . V_170 = F_102 ( V_78 -> V_58 . V_170 ) ;
V_182 -> V_58 . V_168 = V_78 -> V_58 . V_168 ;
V_182 -> V_58 . V_169 = V_78 -> V_58 . V_169 ;
break;
case V_185 :
case V_186 :
break;
default:
F_100 ( L_8 ,
F_103 ( V_78 -> V_51 ) ) ;
F_6 ( 1 ) ;
return 0 ;
}
V_182 -> V_51 = F_104 ( V_78 -> V_51 ) ;
V_182 -> V_84 = F_102 ( V_78 -> V_84 ) ;
V_182 -> V_151 = F_102 ( V_78 -> V_47 ) ;
return V_78 -> V_47 ;
}
struct V_37 * F_105 ( struct V_4 * V_5 ,
struct V_12 * V_13 ,
struct V_187 V_188 ,
T_1 V_14 , T_1 * V_15 ,
unsigned int V_39 , int V_107 ,
int V_147 , int V_84 ,
struct V_110 * V_111 ,
T_2 V_150 ,
T_1 V_149 ,
bool V_117 )
{
struct V_37 * V_88 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
int V_20 ;
F_20 ( V_147 != V_52 && V_147 != V_53 &&
V_147 != V_152 && V_147 != V_153 &&
V_147 != V_185 && V_147 != V_186 ) ;
V_88 = F_70 ( V_5 , V_111 , V_107 , V_117 ,
V_160 ) ;
if ( ! V_88 ) {
V_20 = - V_140 ;
goto V_189;
}
V_20 = F_12 ( V_13 , V_14 , V_15 , & V_16 , & V_17 , & V_18 ) ;
if ( V_20 )
goto V_189;
if ( V_147 == V_185 || V_147 == V_186 ) {
F_85 ( V_88 , V_39 , V_147 , 0 ) ;
} else {
T_2 V_190 = V_13 -> V_190 ;
T_2 V_191 = V_14 - V_17 ;
if ( ! ( V_150 == 1 && V_149 == - 1ULL ) ) {
if ( V_149 <= V_191 ) {
V_149 = 0 ;
} else {
V_149 -= V_191 ;
if ( V_149 > V_190 )
V_149 = V_190 ;
}
}
F_86 ( V_88 , V_39 , V_147 , V_17 , V_18 ,
V_149 , V_150 ) ;
}
V_88 -> V_192 = true ;
V_88 -> V_193 = V_84 ;
V_88 -> V_129 . V_194 = V_13 -> V_195 ;
V_88 -> V_129 . V_123 = F_106 ( V_13 -> V_123 ) ;
F_107 ( & V_88 -> V_128 , L_9 , V_188 . V_196 , V_16 ) ;
V_88 -> V_109 = V_188 . V_197 ;
if ( V_84 & V_198 )
V_88 -> V_199 = V_14 ;
V_20 = F_76 ( V_88 , V_160 ) ;
if ( V_20 )
goto V_189;
return V_88 ;
V_189:
F_62 ( V_88 ) ;
return F_108 ( V_20 ) ;
}
static bool F_109 ( struct V_7 * V_8 )
{
return V_8 -> V_200 == V_76 ;
}
static bool F_110 ( struct V_7 * V_8 )
{
F_5 ( V_8 -> V_9 ) ;
return ! F_50 ( & V_8 -> V_201 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
F_112 ( & V_8 -> V_202 , 1 ) ;
F_67 ( & V_8 -> V_201 ) ;
V_8 -> V_203 = V_204 ;
V_8 -> V_205 = V_204 ;
V_8 -> V_206 = V_204 ;
V_8 -> V_207 = V_204 ;
F_68 ( & V_8 -> V_208 ) ;
F_68 ( & V_8 -> V_209 ) ;
V_8 -> V_210 = 1 ;
F_113 ( & V_8 -> V_6 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_6 ( ! F_50 ( & V_8 -> V_201 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_203 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_205 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_206 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_207 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_208 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_209 ) ) ;
if ( V_8 -> V_211 . V_212 ) {
F_6 ( F_109 ( V_8 ) ) ;
F_116 ( V_8 -> V_211 . V_212 ) ;
}
}
static struct V_7 * F_117 ( struct V_4 * V_5 , int V_213 )
{
struct V_7 * V_8 ;
F_6 ( V_213 == V_76 ) ;
V_8 = F_118 ( sizeof( * V_8 ) , V_214 | V_215 ) ;
F_111 ( V_8 ) ;
V_8 -> V_9 = V_5 ;
V_8 -> V_200 = V_213 ;
F_119 ( & V_8 -> V_216 , V_8 , & V_217 , & V_5 -> V_218 -> V_219 ) ;
return V_8 ;
}
static struct V_7 * F_120 ( struct V_7 * V_8 )
{
if ( F_121 ( & V_8 -> V_202 ) ) {
F_14 ( L_10 , V_8 , F_122 ( & V_8 -> V_202 ) - 1 ,
F_122 ( & V_8 -> V_202 ) ) ;
return V_8 ;
} else {
F_14 ( L_11 , V_8 ) ;
return NULL ;
}
}
static void F_123 ( struct V_7 * V_8 )
{
F_14 ( L_12 , V_8 , F_122 ( & V_8 -> V_202 ) ,
F_122 ( & V_8 -> V_202 ) - 1 ) ;
if ( F_124 ( & V_8 -> V_202 ) ) {
F_114 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_200 ) ;
F_20 ( ! F_51 ( & V_8 -> V_208 ) ) ;
F_126 ( & V_5 -> V_220 ) ;
F_127 ( & V_8 -> V_208 , & V_5 -> V_221 ) ;
F_128 ( & V_5 -> V_220 ) ;
V_8 -> V_222 = V_223 + V_5 -> V_218 -> V_224 -> V_225 ;
}
static void F_129 ( struct V_7 * V_8 )
{
if ( F_115 ( & V_8 -> V_203 ) &&
F_115 ( & V_8 -> V_205 ) )
F_125 ( V_8 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_200 ) ;
F_126 ( & V_5 -> V_220 ) ;
if ( ! F_51 ( & V_8 -> V_208 ) )
F_131 ( & V_8 -> V_208 ) ;
F_128 ( & V_5 -> V_220 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_226 * V_227 ;
F_8 ( V_5 ) ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_200 ) ;
F_133 ( & V_8 -> V_216 ) ;
for ( V_227 = F_134 ( & V_8 -> V_203 ) ; V_227 ; ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
V_227 = F_136 ( V_227 ) ;
F_14 ( L_14 , V_88 , V_88 -> V_228 ) ;
F_137 ( V_8 , V_88 ) ;
F_138 ( & V_5 -> V_229 , V_88 ) ;
}
for ( V_227 = F_134 ( & V_8 -> V_205 ) ; V_227 ; ) {
struct V_10 * V_11 =
F_135 ( V_227 , struct V_10 , V_230 ) ;
V_227 = F_136 ( V_227 ) ;
F_14 ( L_15 , V_11 ,
V_11 -> V_231 ) ;
F_139 ( V_8 , V_11 ) ;
F_140 ( & V_5 -> V_229 , V_11 ) ;
}
F_141 ( V_8 ) ;
F_130 ( V_8 ) ;
F_142 ( & V_5 -> V_232 , V_8 ) ;
F_123 ( V_8 ) ;
}
static int F_143 ( struct V_7 * V_8 )
{
struct V_233 * V_234 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_200 ) ;
if ( F_115 ( & V_8 -> V_203 ) &&
F_115 ( & V_8 -> V_205 ) ) {
F_132 ( V_8 ) ;
return - V_235 ;
}
V_234 = & V_8 -> V_9 -> V_236 -> V_237 [ V_8 -> V_200 ] ;
if ( ! memcmp ( V_234 , & V_8 -> V_216 . V_234 , sizeof ( * V_234 ) ) &&
! F_144 ( & V_8 -> V_216 ) ) {
struct V_226 * V_227 ;
F_14 ( L_16
L_17 ) ;
for ( V_227 = F_134 ( & V_8 -> V_203 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
V_88 -> V_238 = V_223 ;
}
return - V_239 ;
}
F_133 ( & V_8 -> V_216 ) ;
F_145 ( & V_8 -> V_216 , V_240 , V_8 -> V_200 , V_234 ) ;
V_8 -> V_210 ++ ;
return 0 ;
}
static struct V_7 * F_146 ( struct V_4 * V_5 , int V_241 ,
bool V_3 )
{
struct V_7 * V_8 ;
if ( V_3 )
F_8 ( V_5 ) ;
else
F_5 ( V_5 ) ;
if ( V_241 != V_76 )
V_8 = F_147 ( & V_5 -> V_232 , V_241 ) ;
else
V_8 = & V_5 -> V_229 ;
if ( ! V_8 ) {
if ( ! V_3 )
return F_108 ( - V_239 ) ;
V_8 = F_117 ( V_5 , V_241 ) ;
F_148 ( & V_5 -> V_232 , V_8 ) ;
F_145 ( & V_8 -> V_216 , V_240 , V_8 -> V_200 ,
& V_5 -> V_236 -> V_237 [ V_8 -> V_200 ] ) ;
}
F_14 ( L_18 , V_95 , V_5 , V_241 , V_8 ) ;
return V_8 ;
}
static void F_138 ( struct V_7 * V_8 , struct V_37 * V_88 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_88 -> V_228 || V_88 -> V_92 ) ;
F_14 ( L_19 , V_95 , V_8 , V_8 -> V_200 ,
V_88 , V_88 -> V_228 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_149 ( & V_8 -> V_9 -> V_242 ) ;
F_120 ( V_8 ) ;
F_150 ( & V_8 -> V_203 , V_88 ) ;
V_88 -> V_92 = V_8 ;
}
static void F_137 ( struct V_7 * V_8 , struct V_37 * V_88 )
{
F_9 ( V_8 ) ;
F_6 ( V_88 -> V_92 != V_8 ) ;
F_14 ( L_19 , V_95 , V_8 , V_8 -> V_200 ,
V_88 , V_88 -> V_228 ) ;
V_88 -> V_92 = NULL ;
F_151 ( & V_8 -> V_203 , V_88 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_152 ( & V_8 -> V_9 -> V_242 ) ;
}
static bool F_153 ( struct V_243 * V_244 )
{
return V_244 -> V_84 & V_245 ;
}
static bool F_154 ( struct V_4 * V_5 )
{
struct V_226 * V_227 ;
for ( V_227 = F_134 ( & V_5 -> V_236 -> V_246 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_243 * V_244 =
F_135 ( V_227 , struct V_243 , V_230 ) ;
if ( F_153 ( V_244 ) )
return true ;
}
return false ;
}
static bool F_155 ( struct V_4 * V_5 , T_8 V_195 )
{
struct V_243 * V_244 ;
V_244 = F_156 ( V_5 -> V_236 , V_195 ) ;
if ( ! V_244 )
return false ;
return F_153 ( V_244 ) ;
}
static bool F_157 ( struct V_4 * V_5 ,
const struct V_66 * V_67 ,
struct V_243 * V_244 )
{
bool V_247 = F_158 ( V_5 , V_248 ) ;
bool V_249 = F_158 ( V_5 , V_250 ) ||
F_158 ( V_5 , V_251 ) ||
F_153 ( V_244 ) ;
F_6 ( V_244 -> V_252 != V_67 -> V_71 . V_194 ) ;
return ( ( V_67 -> V_84 & V_253 ) && V_247 ) ||
( ( V_67 -> V_84 & V_198 ) && V_249 ) ||
( V_5 -> V_236 -> V_86 < V_5 -> V_254 ) ;
}
static enum V_255 F_159 ( struct V_4 * V_5 ,
struct V_66 * V_67 ,
struct V_256 * V_257 ,
bool V_258 )
{
struct V_243 * V_244 ;
struct V_259 V_79 , V_260 ;
struct V_261 V_73 , V_72 ;
bool V_262 = false ;
bool V_263 = false ;
bool V_264 ;
bool V_265 = false ;
bool V_83 = F_158 ( V_5 , V_266 ) ;
bool V_267 = F_158 ( V_5 ,
V_268 ) ;
enum V_255 V_269 ;
int V_270 ;
V_67 -> V_86 = V_5 -> V_236 -> V_86 ;
V_244 = F_156 ( V_5 -> V_236 , V_67 -> V_69 . V_194 ) ;
if ( ! V_244 ) {
V_67 -> V_8 = V_76 ;
V_269 = V_271 ;
goto V_272;
}
if ( V_5 -> V_236 -> V_86 == V_244 -> V_273 ) {
if ( V_67 -> V_87 < V_244 -> V_273 ) {
V_67 -> V_87 = V_244 -> V_273 ;
V_262 = true ;
} else if ( V_67 -> V_87 == 0 ) {
V_262 = true ;
}
}
F_43 ( & V_67 -> V_70 , & V_67 -> V_68 ) ;
F_44 ( & V_67 -> V_71 , & V_67 -> V_69 ) ;
if ( ( V_67 -> V_84 & V_274 ) == 0 ) {
if ( V_67 -> V_84 & V_253 && V_244 -> V_275 >= 0 )
V_67 -> V_71 . V_194 = V_244 -> V_275 ;
if ( V_67 -> V_84 & V_198 && V_244 -> V_276 >= 0 )
V_67 -> V_71 . V_194 = V_244 -> V_276 ;
V_244 = F_156 ( V_5 -> V_236 , V_67 -> V_71 . V_194 ) ;
if ( ! V_244 ) {
V_67 -> V_8 = V_76 ;
V_269 = V_271 ;
goto V_272;
}
}
V_270 = F_160 ( V_244 , & V_67 -> V_70 , & V_67 -> V_71 ,
& V_79 ) ;
if ( V_270 ) {
F_6 ( V_270 != - V_277 ) ;
V_67 -> V_8 = V_76 ;
V_269 = V_271 ;
goto V_272;
}
V_260 . V_194 = V_79 . V_194 ;
V_260 . V_278 = F_161 ( V_79 . V_278 , V_67 -> V_81 , V_67 -> V_82 ) ;
F_162 ( V_5 -> V_236 , V_244 , & V_79 , & V_73 , & V_72 ) ;
if ( V_258 &&
F_163 ( & V_67 -> V_72 ,
& V_72 ,
& V_67 -> V_73 ,
& V_73 ,
V_67 -> V_74 ,
V_244 -> V_74 ,
V_67 -> V_75 ,
V_244 -> V_75 ,
V_67 -> V_81 ,
V_244 -> V_81 ,
V_67 -> V_83 ,
V_83 ,
V_67 -> V_267 ,
V_267 ,
& V_260 ) )
V_262 = true ;
if ( V_67 -> V_85 && ! F_157 ( V_5 , V_67 , V_244 ) ) {
V_67 -> V_85 = false ;
V_263 = true ;
}
V_264 = F_164 ( & V_67 -> V_79 , & V_79 ) ||
F_165 ( & V_67 -> V_72 , & V_72 , V_258 ) ;
if ( V_67 -> V_81 )
V_265 = F_166 ( & V_260 , V_67 -> V_81 , V_244 -> V_81 ) ;
if ( V_264 || V_262 || V_265 ) {
V_67 -> V_79 = V_79 ;
F_167 ( V_5 -> V_236 , V_244 , & V_79 , & V_67 -> V_80 ) ;
F_45 ( & V_67 -> V_72 , & V_72 ) ;
F_45 ( & V_67 -> V_73 , & V_73 ) ;
V_67 -> V_74 = V_244 -> V_74 ;
V_67 -> V_75 = V_244 -> V_75 ;
V_67 -> V_81 = V_244 -> V_81 ;
V_67 -> V_82 = V_244 -> V_82 ;
V_67 -> V_83 = V_83 ;
V_67 -> V_267 = V_267 ;
V_67 -> V_8 = V_72 . V_279 ;
}
if ( V_263 || V_264 || V_262 ||
( V_265 && V_257 && F_168 ( V_257 -> V_280 ,
V_281 ) ) )
V_269 = V_282 ;
else
V_269 = V_283 ;
V_272:
F_14 ( L_20 , V_95 , V_67 , V_269 , V_67 -> V_8 ) ;
return V_269 ;
}
static struct V_284 * F_169 ( void )
{
struct V_284 * V_285 ;
V_285 = F_73 ( sizeof( * V_285 ) , V_214 ) ;
if ( ! V_285 )
return NULL ;
F_67 ( & V_285 -> V_230 ) ;
V_285 -> V_286 = V_204 ;
return V_285 ;
}
static void F_170 ( struct V_284 * V_285 )
{
F_6 ( ! F_50 ( & V_285 -> V_230 ) ) ;
F_6 ( ! F_115 ( & V_285 -> V_286 ) ) ;
F_58 ( V_285 ) ;
}
static T_1 F_171 ( const struct V_287 * V_288 )
{
return V_288 -> V_289 ? 0x100000000ull : V_288 -> V_290 ;
}
static void F_172 ( const struct V_287 * V_288 ,
void * * V_291 , T_3 * V_292 )
{
if ( V_288 -> V_293 ) {
* V_291 = V_288 -> V_294 ;
* V_292 = V_288 -> V_293 ;
} else {
* V_291 = V_288 -> V_295 ;
* V_292 = V_288 -> V_296 ;
}
}
static int F_173 ( const void * V_297 , T_3 V_298 ,
const void * V_299 , T_3 V_300 )
{
int V_270 ;
V_270 = memcmp ( V_297 , V_299 , F_174 ( V_298 , V_300 ) ) ;
if ( ! V_270 ) {
if ( V_298 < V_300 )
V_270 = - 1 ;
else if ( V_298 > V_300 )
V_270 = 1 ;
}
return V_270 ;
}
static int F_175 ( const struct V_287 * V_301 ,
const struct V_287 * V_302 )
{
void * V_303 , * V_304 ;
T_3 V_305 , V_306 ;
int V_270 ;
if ( V_301 -> V_289 < V_302 -> V_289 )
return - 1 ;
if ( V_301 -> V_289 > V_302 -> V_289 )
return 1 ;
if ( V_301 -> V_194 < V_302 -> V_194 )
return - 1 ;
if ( V_301 -> V_194 > V_302 -> V_194 )
return 1 ;
if ( F_171 ( V_301 ) < F_171 ( V_302 ) )
return - 1 ;
if ( F_171 ( V_301 ) > F_171 ( V_302 ) )
return 1 ;
V_270 = F_173 ( V_301 -> V_307 , V_301 -> V_308 ,
V_302 -> V_307 , V_302 -> V_308 ) ;
if ( V_270 )
return V_270 ;
F_172 ( V_301 , & V_303 , & V_305 ) ;
F_172 ( V_302 , & V_304 , & V_306 ) ;
V_270 = F_173 ( V_303 , V_305 ,
V_304 , V_306 ) ;
if ( V_270 )
return V_270 ;
V_270 = F_173 ( V_301 -> V_295 , V_301 -> V_296 , V_302 -> V_295 , V_302 -> V_296 ) ;
if ( V_270 )
return V_270 ;
if ( V_301 -> V_108 < V_302 -> V_108 )
return - 1 ;
if ( V_301 -> V_108 > V_302 -> V_108 )
return 1 ;
return 0 ;
}
static int F_176 ( void * * V_309 , void * V_310 , struct V_287 * V_288 )
{
T_7 V_311 ;
T_2 V_312 ;
int V_270 ;
V_270 = F_177 ( V_309 , V_310 , 4 , L_21 , & V_311 ,
& V_312 ) ;
if ( V_270 )
return V_270 ;
if ( V_311 < 4 ) {
F_100 ( L_22 , V_311 ) ;
goto V_313;
}
V_288 -> V_294 = F_178 ( V_309 , V_310 , & V_288 -> V_293 ,
V_214 ) ;
if ( F_179 ( V_288 -> V_294 ) ) {
V_270 = F_180 ( V_288 -> V_294 ) ;
V_288 -> V_294 = NULL ;
return V_270 ;
}
V_288 -> V_295 = F_178 ( V_309 , V_310 , & V_288 -> V_296 ,
V_214 ) ;
if ( F_179 ( V_288 -> V_295 ) ) {
V_270 = F_180 ( V_288 -> V_295 ) ;
V_288 -> V_295 = NULL ;
return V_270 ;
}
F_181 ( V_309 , V_310 , V_288 -> V_108 , V_313 ) ;
F_182 ( V_309 , V_310 , V_288 -> V_314 , V_313 ) ;
F_183 ( V_309 , V_310 , V_288 -> V_289 , V_313 ) ;
V_288 -> V_307 = F_178 ( V_309 , V_310 , & V_288 -> V_308 ,
V_214 ) ;
if ( F_179 ( V_288 -> V_307 ) ) {
V_270 = F_180 ( V_288 -> V_307 ) ;
V_288 -> V_307 = NULL ;
return V_270 ;
}
F_181 ( V_309 , V_310 , V_288 -> V_194 , V_313 ) ;
F_184 ( V_288 ) ;
return 0 ;
V_313:
return - V_315 ;
}
static int F_185 ( const struct V_287 * V_288 )
{
return 8 + 4 + 1 + 8 +
4 + V_288 -> V_293 + 4 + V_288 -> V_296 + 4 + V_288 -> V_308 ;
}
static void F_186 ( void * * V_309 , void * V_310 , const struct V_287 * V_288 )
{
F_187 ( V_309 , 4 , 3 , F_185 ( V_288 ) ) ;
F_188 ( V_309 , V_310 , V_288 -> V_294 , V_288 -> V_293 ) ;
F_188 ( V_309 , V_310 , V_288 -> V_295 , V_288 -> V_296 ) ;
F_189 ( V_309 , V_288 -> V_108 ) ;
F_190 ( V_309 , V_288 -> V_314 ) ;
F_191 ( V_309 , V_288 -> V_289 ) ;
F_188 ( V_309 , V_310 , V_288 -> V_307 , V_288 -> V_308 ) ;
F_189 ( V_309 , V_288 -> V_194 ) ;
}
static void F_192 ( struct V_287 * V_288 )
{
if ( V_288 ) {
F_58 ( V_288 -> V_294 ) ;
F_58 ( V_288 -> V_295 ) ;
F_58 ( V_288 -> V_307 ) ;
F_58 ( V_288 ) ;
}
}
static struct V_316 * F_193 ( void )
{
struct V_316 * V_317 ;
V_317 = F_118 ( sizeof( * V_317 ) , V_214 ) ;
if ( ! V_317 )
return NULL ;
F_67 ( & V_317 -> V_318 ) ;
F_67 ( & V_317 -> V_319 ) ;
return V_317 ;
}
static void F_194 ( struct V_316 * V_317 )
{
F_6 ( ! F_50 ( & V_317 -> V_318 ) ) ;
F_6 ( ! F_50 ( & V_317 -> V_319 ) ) ;
F_192 ( V_317 -> V_320 ) ;
F_192 ( V_317 -> V_310 ) ;
F_58 ( V_317 ) ;
}
static struct V_316 * F_195 ( struct V_321 * V_322 ,
const struct V_287 * V_288 )
{
struct V_226 * V_227 = V_322 -> V_226 ;
while ( V_227 ) {
struct V_316 * V_323 =
F_135 ( V_227 , struct V_316 , V_318 ) ;
int V_324 ;
V_324 = F_175 ( V_288 , V_323 -> V_320 ) ;
if ( V_324 < 0 ) {
V_227 = V_227 -> V_325 ;
} else if ( V_324 > 0 ) {
if ( F_175 ( V_288 , V_323 -> V_310 ) < 0 )
return V_323 ;
V_227 = V_227 -> V_326 ;
} else {
return V_323 ;
}
}
return NULL ;
}
static void F_141 ( struct V_7 * V_8 )
{
while ( ! F_115 ( & V_8 -> V_206 ) ) {
struct V_284 * V_285 =
F_135 ( F_134 ( & V_8 -> V_206 ) ,
struct V_284 , V_230 ) ;
while ( ! F_115 ( & V_285 -> V_286 ) ) {
struct V_316 * V_317 =
F_135 ( F_134 ( & V_285 -> V_286 ) ,
struct V_316 , V_318 ) ;
F_196 ( & V_285 -> V_286 , V_317 ) ;
F_197 ( & V_8 -> V_207 , V_317 ) ;
F_194 ( V_317 ) ;
}
F_198 ( & V_8 -> V_206 , V_285 ) ;
F_170 ( V_285 ) ;
}
}
static void F_199 ( struct V_287 * V_288 ,
const struct V_66 * V_67 )
{
V_288 -> V_294 = NULL ;
V_288 -> V_293 = 0 ;
V_288 -> V_295 = V_67 -> V_70 . V_166 ;
V_288 -> V_296 = V_67 -> V_70 . V_135 ;
V_288 -> V_108 = V_120 ;
V_288 -> V_314 = V_67 -> V_79 . V_278 ;
V_288 -> V_289 = false ;
if ( V_67 -> V_71 . V_123 ) {
V_288 -> V_307 = V_67 -> V_71 . V_123 -> T_6 ;
V_288 -> V_308 = V_67 -> V_71 . V_123 -> V_124 ;
} else {
V_288 -> V_307 = NULL ;
V_288 -> V_308 = 0 ;
}
V_288 -> V_194 = V_67 -> V_71 . V_194 ;
F_184 ( V_288 ) ;
}
static bool F_200 ( struct V_37 * V_88 )
{
struct V_7 * V_8 = V_88 -> V_92 ;
struct V_284 * V_285 ;
struct V_316 * V_317 ;
struct V_287 V_288 ;
V_285 = F_201 ( & V_8 -> V_206 , & V_88 -> V_98 . V_80 ) ;
if ( ! V_285 )
return false ;
F_199 ( & V_288 , & V_88 -> V_98 ) ;
V_317 = F_195 ( & V_285 -> V_286 , & V_288 ) ;
if ( ! V_317 )
return false ;
F_14 ( L_23 ,
V_95 , V_88 , V_88 -> V_228 , V_8 -> V_200 , V_317 -> V_80 . V_79 . V_194 ,
V_317 -> V_80 . V_79 . V_278 , V_317 -> V_80 . V_327 , V_317 -> V_252 ) ;
return true ;
}
static void F_202 ( struct V_37 * V_88 ,
struct V_114 * V_126 )
{
T_2 V_328 = 0 ;
int V_329 ;
if ( ! F_51 ( & V_126 -> V_330 ) )
return;
F_6 ( V_126 -> V_331 ) ;
for ( V_329 = 0 ; V_329 < V_88 -> V_40 ; V_329 ++ ) {
struct V_50 * V_51 = & V_88 -> V_41 [ V_329 ] ;
switch ( V_51 -> V_51 ) {
case V_53 :
case V_54 :
F_6 ( V_51 -> V_47 != V_51 -> V_43 . V_26 ) ;
F_95 ( V_126 , & V_51 -> V_43 . V_22 ) ;
break;
case V_56 :
case V_57 :
F_6 ( V_51 -> V_47 != V_51 -> V_58 . V_135 +
V_51 -> V_58 . V_170 ) ;
F_95 ( V_126 , & V_51 -> V_58 . V_22 ) ;
break;
case V_60 :
F_95 ( V_126 ,
& V_51 -> V_61 . V_46 ) ;
break;
case V_59 :
F_95 ( V_88 -> V_97 ,
& V_51 -> V_42 ) ;
break;
case V_52 :
F_95 ( V_88 -> V_97 ,
& V_51 -> V_43 . V_22 ) ;
break;
case V_64 :
F_95 ( V_88 -> V_97 ,
& V_51 -> V_65 . V_48 ) ;
break;
case V_55 :
F_6 ( V_51 -> V_47 != V_51 -> V_44 . V_163 +
V_51 -> V_44 . V_165 +
V_51 -> V_44 . V_47 ) ;
F_95 ( V_126 , & V_51 -> V_44 . V_45 ) ;
F_95 ( V_126 , & V_51 -> V_44 . V_46 ) ;
F_95 ( V_88 -> V_97 ,
& V_51 -> V_44 . V_48 ) ;
break;
case V_62 :
F_95 ( V_126 ,
& V_51 -> V_63 . V_46 ) ;
F_95 ( V_88 -> V_97 ,
& V_51 -> V_63 . V_48 ) ;
break;
}
V_328 += V_51 -> V_47 ;
}
F_6 ( V_328 != V_126 -> V_331 ) ;
}
static void F_203 ( void * * V_309 , const struct V_259 * V_79 )
{
F_191 ( V_309 , 1 ) ;
F_189 ( V_309 , V_79 -> V_194 ) ;
F_190 ( V_309 , V_79 -> V_278 ) ;
F_190 ( V_309 , - 1 ) ;
}
static void F_204 ( void * * V_309 , const struct V_332 * V_80 )
{
F_187 ( V_309 , 1 , 1 , V_131 + 1 ) ;
F_203 ( V_309 , & V_80 -> V_79 ) ;
F_191 ( V_309 , V_80 -> V_327 ) ;
}
static void F_205 ( void * * V_309 , void * V_310 ,
const struct V_121 * V_122 )
{
F_187 ( V_309 , 5 , 4 , F_75 ( V_122 ) ) ;
F_189 ( V_309 , V_122 -> V_194 ) ;
F_190 ( V_309 , - 1 ) ;
F_190 ( V_309 , 0 ) ;
if ( V_122 -> V_123 )
F_188 ( V_309 , V_310 , V_122 -> V_123 -> T_6 ,
V_122 -> V_123 -> V_124 ) ;
else
F_190 ( V_309 , 0 ) ;
}
static void F_206 ( struct V_37 * V_88 ,
struct V_114 * V_126 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_310 = V_309 + V_126 -> V_333 ;
T_2 V_328 = 0 ;
int V_329 ;
if ( V_88 -> V_193 & V_198 ) {
F_6 ( V_88 -> V_109 != V_120 ) ;
} else {
F_6 ( V_88 -> V_334 . V_335 || V_88 -> V_334 . V_336 ||
V_88 -> V_199 || V_88 -> V_99 ) ;
}
F_202 ( V_88 , V_126 ) ;
F_204 ( & V_309 , & V_88 -> V_98 . V_80 ) ;
F_190 ( & V_309 , V_88 -> V_98 . V_79 . V_278 ) ;
F_190 ( & V_309 , V_88 -> V_101 -> V_236 -> V_86 ) ;
F_190 ( & V_309 , V_88 -> V_193 ) ;
F_187 ( & V_309 , 2 , 2 , sizeof( struct V_132 ) ) ;
memset ( V_309 , 0 , sizeof( struct V_132 ) ) ;
V_309 += sizeof( struct V_132 ) ;
memset ( V_309 , 0 , sizeof( struct V_133 ) ) ;
V_309 += sizeof( struct V_133 ) ;
F_190 ( & V_309 , 0 ) ;
F_207 ( V_309 , & V_88 -> V_334 ) ;
V_309 += sizeof( struct V_134 ) ;
F_205 ( & V_309 , V_310 , & V_88 -> V_98 . V_71 ) ;
F_188 ( & V_309 , V_310 , V_88 -> V_98 . V_70 . V_166 ,
V_88 -> V_98 . V_70 . V_135 ) ;
F_208 ( & V_309 , V_88 -> V_40 ) ;
for ( V_329 = 0 ; V_329 < V_88 -> V_40 ; V_329 ++ ) {
V_328 += F_99 ( V_309 , & V_88 -> V_41 [ V_329 ] ) ;
V_309 += sizeof( struct V_136 ) ;
}
F_189 ( & V_309 , V_88 -> V_109 ) ;
if ( V_88 -> V_99 ) {
F_189 ( & V_309 , V_88 -> V_99 -> V_337 ) ;
F_190 ( & V_309 , V_88 -> V_99 -> V_137 ) ;
for ( V_329 = 0 ; V_329 < V_88 -> V_99 -> V_137 ; V_329 ++ )
F_189 ( & V_309 , V_88 -> V_99 -> V_338 [ V_329 ] ) ;
} else {
F_189 ( & V_309 , 0 ) ;
F_190 ( & V_309 , 0 ) ;
}
F_190 ( & V_309 , V_88 -> V_339 ) ;
F_20 ( V_309 > V_310 - 8 ) ;
V_126 -> V_340 . V_341 = F_104 ( 8 ) ;
V_126 -> V_141 . V_143 = V_309 - V_126 -> V_141 . V_142 ;
V_126 -> V_340 . V_342 = F_102 ( V_126 -> V_141 . V_143 ) ;
V_126 -> V_340 . V_328 = F_102 ( V_328 ) ;
V_126 -> V_340 . V_343 = F_104 ( V_88 -> V_199 ) ;
F_14 ( L_24 , V_95 , V_88 , V_126 ,
V_88 -> V_98 . V_70 . V_166 , V_88 -> V_98 . V_70 . V_135 ) ;
}
static void F_209 ( struct V_114 * V_126 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_344 = V_309 + V_126 -> V_141 . V_143 ;
void * const V_310 = V_309 + V_126 -> V_333 ;
if ( F_168 ( V_126 -> V_257 -> V_280 , V_281 ) ) {
V_309 = V_344 ;
F_189 ( & V_309 , V_126 -> V_257 -> V_280 ) ;
} else {
struct {
char V_80 [ V_130 +
V_131 + 1 ] ;
T_9 V_314 ;
T_9 V_86 ;
T_9 V_84 ;
char V_345 [ V_130 +
sizeof( struct V_132 ) ] ;
char V_346 [ sizeof( struct V_133 ) ] ;
T_9 V_347 ;
struct V_134 V_348 ;
} V_349 V_350 ;
struct V_259 V_79 ;
void * V_122 , * V_295 , * V_351 ;
int V_352 , V_296 , V_353 ;
int V_124 ;
memcpy ( & V_350 , V_309 , sizeof( V_350 ) ) ;
V_309 += sizeof( V_350 ) ;
V_122 = V_309 ;
V_309 += V_130 ;
V_79 . V_194 = F_210 ( & V_309 ) ;
V_309 += 4 + 4 ;
V_124 = F_211 ( & V_309 ) ;
V_309 += V_124 ;
V_352 = V_309 - V_122 ;
V_295 = V_309 ;
V_124 = F_211 ( & V_309 ) ;
V_309 += V_124 ;
V_296 = V_309 - V_295 ;
V_351 = V_309 ;
V_353 = V_344 - V_309 ;
V_309 = V_126 -> V_141 . V_142 ;
F_212 ( & V_309 , & V_350 . V_347 , sizeof( V_350 . V_347 ) ) ;
F_212 ( & V_309 , & V_350 . V_86 , sizeof( V_350 . V_86 ) ) ;
F_212 ( & V_309 , & V_350 . V_84 , sizeof( V_350 . V_84 ) ) ;
F_212 ( & V_309 , & V_350 . V_348 , sizeof( V_350 . V_348 ) ) ;
memset ( V_309 , 0 , sizeof( struct V_354 ) ) ;
V_309 += sizeof( struct V_354 ) ;
F_20 ( V_309 >= V_122 ) ;
memmove ( V_309 , V_122 , V_352 ) ;
V_309 += V_352 ;
V_79 . V_278 = F_213 ( V_350 . V_314 ) ;
F_203 ( & V_309 , & V_79 ) ;
F_20 ( V_309 >= V_295 ) ;
memmove ( V_309 , V_295 , V_296 ) ;
V_309 += V_296 ;
F_20 ( V_309 >= V_351 ) ;
memmove ( V_309 , V_351 , V_353 ) ;
V_309 += V_353 ;
V_126 -> V_340 . V_341 = F_104 ( 4 ) ;
}
F_20 ( V_309 > V_310 ) ;
V_126 -> V_141 . V_143 = V_309 - V_126 -> V_141 . V_142 ;
V_126 -> V_340 . V_342 = F_102 ( V_126 -> V_141 . V_143 ) ;
F_14 ( L_25 , V_95 , V_126 ,
F_214 ( V_126 -> V_340 . V_355 ) , F_213 ( V_126 -> V_340 . V_342 ) ,
F_213 ( V_126 -> V_340 . V_356 ) , F_213 ( V_126 -> V_340 . V_328 ) ,
F_215 ( V_126 -> V_340 . V_341 ) ) ;
}
static void F_216 ( struct V_37 * V_88 )
{
struct V_7 * V_8 = V_88 -> V_92 ;
F_9 ( V_8 ) ;
F_6 ( V_8 -> V_200 != V_88 -> V_98 . V_8 ) ;
if ( F_200 ( V_88 ) )
return;
if ( V_88 -> V_357 )
F_217 ( V_88 -> V_96 ) ;
V_88 -> V_193 |= V_358 ;
if ( V_88 -> V_339 )
V_88 -> V_193 |= V_359 ;
else
F_6 ( V_88 -> V_193 & V_359 ) ;
F_206 ( V_88 , V_88 -> V_96 ) ;
F_14 ( L_26 ,
V_95 , V_88 , V_88 -> V_228 , V_88 -> V_98 . V_79 . V_194 , V_88 -> V_98 . V_79 . V_278 ,
V_88 -> V_98 . V_80 . V_79 . V_194 , V_88 -> V_98 . V_80 . V_79 . V_278 ,
V_88 -> V_98 . V_80 . V_327 , V_8 -> V_200 , V_88 -> V_98 . V_86 , V_88 -> V_193 ,
V_88 -> V_339 ) ;
V_88 -> V_98 . V_85 = false ;
V_88 -> V_238 = V_223 ;
V_88 -> V_339 ++ ;
V_88 -> V_357 = V_8 -> V_210 ;
V_88 -> V_96 -> V_340 . V_355 = F_101 ( V_88 -> V_228 ) ;
F_218 ( & V_8 -> V_216 , F_219 ( V_88 -> V_96 ) ) ;
}
static void F_220 ( struct V_4 * V_5 )
{
bool V_360 = false ;
F_5 ( V_5 ) ;
F_6 ( ! V_5 -> V_236 -> V_86 ) ;
if ( F_158 ( V_5 , V_251 ) ||
F_158 ( V_5 , V_248 ) ||
F_158 ( V_5 , V_250 ) ) {
F_14 ( L_27 , V_95 , V_5 ) ;
V_360 = true ;
} else {
F_14 ( L_28 , V_95 , V_5 ) ;
}
if ( F_221 ( & V_5 -> V_218 -> V_361 , V_362 ,
V_5 -> V_236 -> V_86 + 1 , V_360 ) )
F_222 ( & V_5 -> V_218 -> V_361 ) ;
}
static void F_223 ( struct V_37 * V_88 , bool V_3 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_7 * V_8 ;
enum V_255 V_269 ;
bool V_363 = false ;
bool V_364 = false ;
bool V_365 = false ;
F_6 ( V_88 -> V_228 ) ;
F_14 ( L_29 , V_95 , V_88 , V_3 ) ;
V_366:
V_269 = F_159 ( V_5 , & V_88 -> V_98 , NULL , false ) ;
if ( V_269 == V_271 && ! V_3 )
goto V_367;
V_8 = F_146 ( V_5 , V_88 -> V_98 . V_8 , V_3 ) ;
if ( F_179 ( V_8 ) ) {
F_6 ( F_180 ( V_8 ) != - V_239 || V_3 ) ;
goto V_367;
}
if ( V_5 -> V_236 -> V_86 < V_5 -> V_254 ) {
F_14 ( L_30 , V_88 , V_5 -> V_236 -> V_86 ,
V_5 -> V_254 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_193 & V_198 ) &&
F_158 ( V_5 , V_250 ) ) {
F_14 ( L_31 , V_88 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_193 & V_253 ) &&
F_158 ( V_5 , V_248 ) ) {
F_14 ( L_32 , V_88 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_193 & V_198 ) &&
! ( V_88 -> V_193 & ( V_368 |
V_369 ) ) &&
( F_158 ( V_5 , V_251 ) ||
F_155 ( V_5 , V_88 -> V_98 . V_69 . V_194 ) ) ) {
F_14 ( L_33 , V_88 ) ;
F_224 ( L_34 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
if ( V_88 -> V_192 )
V_365 = true ;
} else if ( ! F_109 ( V_8 ) ) {
V_363 = true ;
} else {
F_220 ( V_5 ) ;
}
F_225 ( & V_8 -> V_6 ) ;
V_88 -> V_228 = F_226 ( & V_5 -> V_370 ) ;
F_138 ( V_8 , V_88 ) ;
if ( V_363 )
F_216 ( V_88 ) ;
else if ( V_365 )
F_227 ( V_88 , - V_371 ) ;
F_228 ( & V_8 -> V_6 ) ;
if ( V_269 == V_271 )
F_229 ( V_88 ) ;
if ( V_364 )
F_230 ( & V_5 -> V_6 ) ;
return;
V_367:
F_4 ( & V_5 -> V_6 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_3 = true ;
V_364 = true ;
goto V_366;
}
static void F_232 ( struct V_37 * V_88 )
{
F_6 ( V_88 -> V_193 & ( V_372 | V_373 ) ) ;
F_6 ( ! ( V_88 -> V_193 & ( V_253 | V_198 ) ) ) ;
V_88 -> V_193 |= V_373 ;
F_149 ( & V_88 -> V_101 -> V_374 ) ;
V_88 -> V_375 = V_223 ;
}
static void F_233 ( struct V_37 * V_88 , bool V_3 )
{
F_59 ( V_88 ) ;
F_232 ( V_88 ) ;
F_223 ( V_88 , V_3 ) ;
}
static void F_234 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
F_6 ( F_235 ( & V_5 -> V_376 , V_88 -> V_228 ) ) ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_228 ) ;
if ( V_88 -> V_92 )
F_137 ( V_88 -> V_92 , V_88 ) ;
F_152 ( & V_5 -> V_374 ) ;
F_217 ( V_88 -> V_96 ) ;
F_236 ( V_88 -> V_97 ) ;
}
static void F_237 ( struct V_37 * V_88 )
{
if ( V_88 -> V_377 ) {
F_14 ( L_36 , V_95 , V_88 ,
V_88 -> V_228 , V_88 -> V_377 , V_88 -> V_378 ) ;
V_88 -> V_377 ( V_88 ) ;
}
}
static void F_227 ( struct V_37 * V_88 , int V_379 )
{
F_14 ( L_37 , V_95 , V_88 , V_88 -> V_228 , V_379 ) ;
V_88 -> V_378 = V_379 ;
F_234 ( V_88 ) ;
F_237 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
}
static void F_239 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_37 * V_380 ;
F_8 ( V_5 ) ;
V_380 = F_235 ( & V_5 -> V_376 , V_88 -> V_228 ) ;
if ( ! V_380 )
return;
F_6 ( V_380 != V_88 ) ;
F_240 ( & V_5 -> V_376 , V_88 ) ;
F_62 ( V_88 ) ;
}
static void F_241 ( struct V_37 * V_88 )
{
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_228 ) ;
F_239 ( V_88 ) ;
F_234 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
}
static void F_242 ( struct V_37 * V_88 , int V_379 )
{
F_14 ( L_37 , V_95 , V_88 , V_88 -> V_228 , V_379 ) ;
F_239 ( V_88 ) ;
F_227 ( V_88 , V_379 ) ;
}
static void F_243 ( struct V_4 * V_5 , T_2 V_381 )
{
if ( F_244 ( V_381 > V_5 -> V_254 ) ) {
F_14 ( L_38 ,
V_5 -> V_254 , V_381 ) ;
V_5 -> V_254 = V_381 ;
if ( V_381 > V_5 -> V_236 -> V_86 )
F_220 ( V_5 ) ;
}
}
void F_245 ( struct V_4 * V_5 , T_2 V_381 )
{
F_246 ( & V_5 -> V_6 ) ;
if ( F_2 ( V_381 > V_5 -> V_254 ) ) {
F_4 ( & V_5 -> V_6 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_243 ( V_5 , V_381 ) ;
F_247 ( & V_5 -> V_6 ) ;
} else {
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_248 ( struct V_4 * V_5 )
{
struct V_226 * V_227 ;
bool V_382 = false ;
F_14 ( L_39 ) ;
if ( ! F_158 ( V_5 , V_251 ) && ! F_154 ( V_5 ) )
goto V_272;
for ( V_227 = F_134 ( & V_5 -> V_232 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_7 * V_8 = F_135 ( V_227 , struct V_7 , V_201 ) ;
struct V_226 * V_383 ;
V_383 = F_134 ( & V_8 -> V_203 ) ;
while ( V_383 ) {
struct V_37 * V_88 = F_135 ( V_383 ,
struct V_37 , V_89 ) ;
V_383 = F_136 ( V_383 ) ;
if ( V_88 -> V_192 ) {
V_382 = true ;
break;
}
}
if ( V_382 )
break;
}
if ( ! V_382 )
goto V_272;
F_243 ( V_5 , V_5 -> V_236 -> V_86 ) ;
for ( V_227 = F_134 ( & V_5 -> V_232 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_7 * V_8 = F_135 ( V_227 , struct V_7 , V_201 ) ;
struct V_226 * V_383 ;
V_383 = F_134 ( & V_8 -> V_203 ) ;
while ( V_383 ) {
struct V_37 * V_88 = F_135 ( V_383 ,
struct V_37 , V_89 ) ;
V_383 = F_136 ( V_383 ) ;
if ( V_88 -> V_192 &&
( F_158 ( V_5 , V_251 ) ||
F_155 ( V_5 , V_88 -> V_98 . V_71 . V_194 ) ) )
F_242 ( V_88 , - V_371 ) ;
}
}
V_272:
F_14 ( L_40 , V_5 -> V_254 ) ;
}
static void F_249 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_384 * V_385 = V_5 -> V_236 ;
F_8 ( V_5 ) ;
F_6 ( ! V_385 -> V_86 ) ;
if ( V_88 -> V_339 ) {
V_88 -> V_386 = V_385 -> V_86 ;
F_14 ( L_41 , V_95 , V_88 ,
V_88 -> V_228 ) ;
} else {
F_14 ( L_42 , V_95 ,
V_88 , V_88 -> V_228 , V_88 -> V_386 , V_385 -> V_86 ) ;
}
if ( V_88 -> V_386 ) {
if ( V_385 -> V_86 >= V_88 -> V_386 ) {
F_250 ( L_43 ,
V_88 -> V_228 ) ;
F_227 ( V_88 , - V_277 ) ;
}
} else {
F_229 ( V_88 ) ;
}
}
static void F_251 ( struct V_387 * V_388 )
{
struct V_4 * V_5 = & V_388 -> V_361 -> V_218 -> V_5 ;
struct V_37 * V_88 ;
T_1 V_355 = V_388 -> V_389 ;
F_6 ( V_388 -> V_390 || ! V_388 -> V_391 . V_392 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_88 = F_235 ( & V_5 -> V_376 , V_355 ) ;
if ( ! V_88 ) {
F_14 ( L_44 , V_95 , V_355 ) ;
goto V_393;
}
F_14 ( L_45 , V_95 ,
V_88 , V_88 -> V_228 , V_88 -> V_386 , V_388 -> V_391 . V_392 ) ;
if ( ! V_88 -> V_386 )
V_88 -> V_386 = V_388 -> V_391 . V_392 ;
F_240 ( & V_5 -> V_376 , V_88 ) ;
F_249 ( V_88 ) ;
F_62 ( V_88 ) ;
V_393:
F_247 ( & V_5 -> V_6 ) ;
}
static void F_229 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_37 * V_380 ;
int V_270 ;
F_8 ( V_5 ) ;
V_380 = F_235 ( & V_5 -> V_376 , V_88 -> V_228 ) ;
if ( V_380 ) {
F_6 ( V_380 != V_88 ) ;
return;
}
F_59 ( V_88 ) ;
F_252 ( & V_5 -> V_376 , V_88 ) ;
V_270 = F_253 ( & V_5 -> V_218 -> V_361 , L_46 ,
F_251 , V_88 -> V_228 ) ;
F_6 ( V_270 ) ;
}
static void F_254 ( struct V_93 * V_93 )
{
struct V_10 * V_11 =
F_53 ( V_93 , struct V_10 , V_93 ) ;
F_14 ( L_47 , V_95 , V_11 ,
V_11 -> V_394 , V_11 -> V_395 ) ;
F_6 ( ! F_50 ( & V_11 -> V_230 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_396 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_397 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_398 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_399 ) ) ;
F_6 ( V_11 -> V_8 ) ;
if ( V_11 -> V_394 )
F_62 ( V_11 -> V_394 ) ;
if ( V_11 -> V_395 )
F_62 ( V_11 -> V_395 ) ;
F_46 ( & V_11 -> V_67 ) ;
F_58 ( V_11 ) ;
}
static void F_255 ( struct V_10 * V_11 )
{
if ( V_11 )
F_63 ( & V_11 -> V_93 , F_254 ) ;
}
static struct V_10 *
F_256 ( struct V_10 * V_11 )
{
F_61 ( & V_11 -> V_93 ) ;
return V_11 ;
}
static struct V_10 *
F_257 ( struct V_4 * V_5 )
{
struct V_10 * V_11 ;
V_11 = F_118 ( sizeof( * V_11 ) , V_214 ) ;
if ( ! V_11 )
return NULL ;
F_65 ( & V_11 -> V_93 ) ;
F_113 ( & V_11 -> V_6 ) ;
F_67 ( & V_11 -> V_230 ) ;
F_67 ( & V_11 -> V_396 ) ;
F_67 ( & V_11 -> V_397 ) ;
F_68 ( & V_11 -> V_398 ) ;
F_68 ( & V_11 -> V_399 ) ;
F_66 ( & V_11 -> V_400 ) ;
F_66 ( & V_11 -> V_401 ) ;
V_11 -> V_5 = V_5 ;
F_38 ( & V_11 -> V_67 ) ;
F_14 ( L_48 , V_95 , V_11 ) ;
return V_11 ;
}
static void F_140 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_11 -> V_231 || V_11 -> V_8 ) ;
F_14 ( L_49 , V_95 , V_8 ,
V_8 -> V_200 , V_11 , V_11 -> V_231 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_149 ( & V_8 -> V_9 -> V_242 ) ;
F_120 ( V_8 ) ;
F_258 ( & V_8 -> V_205 , V_11 ) ;
V_11 -> V_8 = V_8 ;
}
static void F_139 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( V_11 -> V_8 != V_8 ) ;
F_14 ( L_49 , V_95 , V_8 ,
V_8 -> V_200 , V_11 , V_11 -> V_231 ) ;
V_11 -> V_8 = NULL ;
F_259 ( & V_8 -> V_205 , V_11 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_152 ( & V_8 -> V_9 -> V_242 ) ;
}
static bool F_260 ( struct V_10 * V_11 )
{
F_5 ( V_11 -> V_5 ) ;
return ! F_50 ( & V_11 -> V_396 ) ;
}
static bool F_261 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
bool V_402 ;
F_246 ( & V_5 -> V_6 ) ;
V_402 = F_260 ( V_11 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_402 ;
}
static void F_262 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_6 ( V_11 -> V_231 ) ;
F_256 ( V_11 ) ;
V_11 -> V_231 = ++ V_5 -> V_403 ;
F_263 ( & V_5 -> V_404 , V_11 ) ;
}
static void F_264 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_265 ( & V_5 -> V_404 , V_11 ) ;
F_255 ( V_11 ) ;
}
static void F_266 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_405 ;
F_6 ( ! V_88 -> V_113 ) ;
F_241 ( V_88 ) ;
F_255 ( V_11 ) ;
}
static struct V_406 * F_267 ( struct V_10 * V_11 ,
T_10 V_407 )
{
struct V_406 * V_408 ;
V_408 = F_118 ( sizeof( * V_408 ) , V_214 ) ;
if ( ! V_408 )
return NULL ;
F_268 ( & V_408 -> V_409 , V_407 ) ;
F_68 ( & V_408 -> V_410 ) ;
V_408 -> V_11 = F_256 ( V_11 ) ;
return V_408 ;
}
static void F_269 ( struct V_406 * V_408 )
{
struct V_10 * V_11 = V_408 -> V_11 ;
F_225 ( & V_11 -> V_6 ) ;
F_270 ( & V_408 -> V_410 ) ;
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
F_58 ( V_408 ) ;
}
static void F_271 ( struct V_406 * V_408 )
{
struct V_10 * V_11 = V_408 -> V_11 ;
struct V_4 * V_5 = V_11 -> V_5 ;
F_11 ( V_11 ) ;
F_6 ( ! F_51 ( & V_408 -> V_410 ) ) ;
V_408 -> V_411 = V_223 ;
F_127 ( & V_408 -> V_410 , & V_11 -> V_399 ) ;
F_272 ( V_5 -> V_412 , & V_408 -> V_409 ) ;
}
static void F_273 ( struct V_413 * V_414 )
{
struct V_406 * V_408 = F_53 ( V_414 , struct V_406 , V_409 ) ;
struct V_10 * V_11 = V_408 -> V_11 ;
if ( ! F_261 ( V_11 ) ) {
F_14 ( L_50 , V_95 , V_11 ) ;
goto V_272;
}
F_6 ( ! V_11 -> V_415 ) ;
F_14 ( L_51 ,
V_95 , V_11 , V_408 -> V_63 . V_416 , V_408 -> V_63 . V_417 ,
V_408 -> V_63 . V_151 ) ;
V_11 -> V_418 ( V_11 -> V_330 , V_408 -> V_63 . V_416 , V_11 -> V_231 ,
V_408 -> V_63 . V_417 , V_408 -> V_63 . V_419 ,
V_408 -> V_63 . V_151 ) ;
V_272:
F_54 ( V_408 -> V_63 . V_126 ) ;
F_269 ( V_408 ) ;
}
static void F_274 ( struct V_413 * V_414 )
{
struct V_406 * V_408 = F_53 ( V_414 , struct V_406 , V_409 ) ;
struct V_10 * V_11 = V_408 -> V_11 ;
if ( ! F_261 ( V_11 ) ) {
F_14 ( L_50 , V_95 , V_11 ) ;
goto V_272;
}
F_14 ( L_52 , V_95 , V_11 , V_408 -> error . V_379 ) ;
V_11 -> V_420 ( V_11 -> V_330 , V_11 -> V_231 , V_408 -> error . V_379 ) ;
V_272:
F_269 ( V_408 ) ;
}
static void F_275 ( struct V_10 * V_11 )
{
struct V_406 * V_408 ;
V_408 = F_267 ( V_11 , F_274 ) ;
if ( ! V_408 ) {
F_100 ( L_53 ) ;
return;
}
V_408 -> error . V_379 = V_11 -> V_421 ;
F_271 ( V_408 ) ;
}
static void F_276 ( struct V_10 * V_11 ,
int V_390 )
{
if ( ! F_277 ( & V_11 -> V_400 ) ) {
V_11 -> V_422 = ( V_390 <= 0 ? V_390 : 0 ) ;
F_238 ( & V_11 -> V_400 ) ;
}
}
static void F_278 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_405 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_54 , V_95 , V_11 ,
V_11 -> V_231 , V_88 -> V_378 ) ;
F_276 ( V_11 , V_88 -> V_378 ) ;
V_11 -> V_423 = true ;
if ( ! V_11 -> V_415 ) {
struct V_21 * V_22 =
F_22 ( V_88 , 0 , V_63 , V_48 ) ;
void * V_309 = F_279 ( V_22 -> V_25 [ 0 ] ) ;
F_6 ( V_88 -> V_41 [ 0 ] . V_51 != V_62 ||
V_22 -> type != V_30 ) ;
if ( V_88 -> V_41 [ 0 ] . V_157 >= sizeof( T_1 ) ) {
V_11 -> V_416 = F_210 ( & V_309 ) ;
F_14 ( L_55 , V_11 ,
V_11 -> V_416 ) ;
} else {
F_14 ( L_56 , V_11 ) ;
}
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static int F_280 ( int V_379 )
{
if ( V_379 == - V_277 )
V_379 = - V_424 ;
return V_379 ;
}
static void F_281 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_405 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_57 , V_95 ,
V_11 , V_11 -> V_231 , V_88 -> V_378 , V_11 -> V_421 ) ;
if ( V_88 -> V_378 < 0 ) {
if ( ! V_11 -> V_421 ) {
V_11 -> V_421 = F_280 ( V_88 -> V_378 ) ;
F_275 ( V_11 ) ;
}
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static void F_282 ( struct V_10 * V_11 )
{
struct V_37 * V_88 = V_11 -> V_394 ;
struct V_50 * V_51 = & V_88 -> V_41 [ 0 ] ;
F_8 ( V_88 -> V_101 ) ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_231 ) ;
if ( V_88 -> V_92 )
F_266 ( V_88 ) ;
F_69 ( V_88 ) ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
V_88 -> V_193 = V_11 -> V_67 . V_84 ;
V_88 -> V_334 = V_11 -> V_348 ;
F_225 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_415 && V_11 -> V_423 ) {
F_6 ( V_51 -> V_51 != V_173 ||
V_51 -> V_174 . V_171 != V_11 -> V_231 ) ;
V_51 -> V_174 . V_51 = V_425 ;
V_51 -> V_174 . V_175 = ++ V_11 -> V_426 ;
F_14 ( L_59 , V_11 ,
V_51 -> V_174 . V_175 ) ;
V_88 -> V_377 = F_281 ;
} else {
if ( ! V_11 -> V_415 )
V_11 -> V_416 = 0 ;
else
F_6 ( V_51 -> V_174 . V_51 != V_427 ) ;
F_14 ( L_60 , V_11 ) ;
V_88 -> V_377 = F_278 ;
}
F_228 ( & V_11 -> V_6 ) ;
V_88 -> V_405 = F_256 ( V_11 ) ;
V_88 -> V_113 = true ;
F_233 ( V_88 , true ) ;
}
static void F_283 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_405 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_61 ,
V_95 , V_11 , V_11 -> V_231 , V_88 -> V_378 , V_11 -> V_428 ,
V_11 -> V_421 ) ;
if ( V_11 -> V_426 == V_88 -> V_41 [ 0 ] . V_174 . V_175 ) {
if ( ! V_88 -> V_378 ) {
V_11 -> V_429 = V_11 -> V_428 ;
} else if ( ! V_11 -> V_421 ) {
V_11 -> V_421 = F_280 ( V_88 -> V_378 ) ;
F_275 ( V_11 ) ;
}
} else {
F_14 ( L_62 , V_11 ,
V_11 -> V_426 , V_88 -> V_41 [ 0 ] . V_174 . V_175 ) ;
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static void F_284 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_37 * V_88 = V_11 -> V_395 ;
struct V_50 * V_51 = & V_88 -> V_41 [ 0 ] ;
if ( F_158 ( V_5 , V_248 ) ) {
F_14 ( L_63 , V_95 ) ;
return;
}
V_11 -> V_428 = V_223 ;
F_14 ( L_64 ,
V_95 , V_11 , V_11 -> V_231 , V_11 -> V_428 ,
V_11 -> V_426 ) ;
if ( V_88 -> V_92 )
F_266 ( V_88 ) ;
F_69 ( V_88 ) ;
F_42 ( & V_88 -> V_98 , & V_11 -> V_67 ) ;
F_6 ( V_51 -> V_51 != V_173 ||
V_51 -> V_174 . V_171 != V_11 -> V_231 ||
V_51 -> V_174 . V_51 != V_430 ) ;
V_51 -> V_174 . V_175 = V_11 -> V_426 ;
V_88 -> V_377 = F_283 ;
V_88 -> V_405 = F_256 ( V_11 ) ;
V_88 -> V_113 = true ;
F_59 ( V_88 ) ;
F_232 ( V_88 ) ;
V_88 -> V_228 = F_226 ( & V_5 -> V_370 ) ;
F_138 ( V_11 -> V_8 , V_88 ) ;
F_216 ( V_88 ) ;
}
static void F_285 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_7 * V_8 ;
F_159 ( V_5 , & V_11 -> V_67 , NULL , false ) ;
V_8 = F_146 ( V_5 , V_11 -> V_67 . V_8 , true ) ;
F_140 ( V_8 , V_11 ) ;
F_282 ( V_11 ) ;
}
static void F_286 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_10 * V_431 ;
F_8 ( V_5 ) ;
V_431 = F_287 ( & V_5 -> V_432 ,
V_11 -> V_231 ) ;
if ( ! V_431 )
return;
F_6 ( V_431 != V_11 ) ;
F_288 ( & V_5 -> V_432 , V_11 ) ;
F_255 ( V_11 ) ;
}
static void F_289 ( struct V_10 * V_11 )
{
if ( V_11 -> V_415 && V_11 -> V_395 -> V_92 )
F_266 ( V_11 -> V_395 ) ;
if ( V_11 -> V_394 -> V_92 )
F_266 ( V_11 -> V_394 ) ;
F_286 ( V_11 ) ;
F_139 ( V_11 -> V_8 , V_11 ) ;
F_264 ( V_11 ) ;
}
static void F_290 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_231 ( & V_5 -> V_6 ) ;
if ( F_260 ( V_11 ) )
F_289 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
}
static void F_291 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_384 * V_385 = V_5 -> V_236 ;
F_8 ( V_5 ) ;
F_6 ( ! V_385 -> V_86 ) ;
if ( V_11 -> V_426 ) {
V_11 -> V_433 = V_385 -> V_86 ;
F_14 ( L_65 , V_95 ,
V_11 , V_11 -> V_231 ) ;
} else {
F_14 ( L_66 ,
V_95 , V_11 , V_11 -> V_231 , V_11 -> V_433 ,
V_385 -> V_86 ) ;
}
if ( V_11 -> V_433 ) {
if ( V_385 -> V_86 >= V_11 -> V_433 ) {
F_292 ( L_67 ,
V_11 -> V_231 ) ;
F_276 ( V_11 , - V_277 ) ;
F_289 ( V_11 ) ;
}
} else {
F_293 ( V_11 ) ;
}
}
static void F_294 ( struct V_387 * V_388 )
{
struct V_4 * V_5 = & V_388 -> V_361 -> V_218 -> V_5 ;
struct V_10 * V_11 ;
T_1 V_231 = V_388 -> V_389 ;
F_6 ( V_388 -> V_390 || ! V_388 -> V_391 . V_392 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_11 = F_287 ( & V_5 -> V_432 , V_231 ) ;
if ( ! V_11 ) {
F_14 ( L_68 , V_95 , V_231 ) ;
goto V_393;
}
F_14 ( L_69 ,
V_95 , V_11 , V_11 -> V_231 , V_11 -> V_433 ,
V_388 -> V_391 . V_392 ) ;
if ( ! V_11 -> V_433 )
V_11 -> V_433 = V_388 -> V_391 . V_392 ;
F_288 ( & V_5 -> V_432 , V_11 ) ;
F_291 ( V_11 ) ;
F_255 ( V_11 ) ;
V_393:
F_247 ( & V_5 -> V_6 ) ;
}
static void F_293 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_10 * V_431 ;
int V_270 ;
F_8 ( V_5 ) ;
V_431 = F_287 ( & V_5 -> V_432 ,
V_11 -> V_231 ) ;
if ( V_431 ) {
F_6 ( V_431 != V_11 ) ;
return;
}
F_256 ( V_11 ) ;
F_295 ( & V_5 -> V_432 , V_11 ) ;
V_270 = F_253 ( & V_5 -> V_218 -> V_361 , L_46 ,
F_294 , V_11 -> V_231 ) ;
F_6 ( V_270 ) ;
}
static int F_296 ( struct V_10 * V_11 )
{
int V_270 ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_231 ) ;
V_270 = F_297 ( & V_11 -> V_400 ) ;
return V_270 ? : V_11 -> V_422 ;
}
static int F_298 ( struct V_10 * V_11 )
{
int V_270 ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_231 ) ;
V_270 = F_297 ( & V_11 -> V_401 ) ;
return V_270 ? : V_11 -> V_434 ;
}
static void F_299 ( struct V_413 * V_409 )
{
struct V_4 * V_5 =
F_53 ( V_409 , struct V_4 , V_435 . V_409 ) ;
struct V_436 * V_437 = V_5 -> V_218 -> V_224 ;
unsigned long V_438 = V_223 - V_437 -> V_439 ;
unsigned long V_440 = V_223 - V_437 -> V_441 ;
F_300 ( V_442 ) ;
struct V_226 * V_227 , * V_309 ;
F_14 ( L_70 , V_95 , V_5 ) ;
F_231 ( & V_5 -> V_6 ) ;
for ( V_227 = F_134 ( & V_5 -> V_232 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_7 * V_8 = F_135 ( V_227 , struct V_7 , V_201 ) ;
bool V_443 = false ;
for ( V_309 = F_134 ( & V_8 -> V_203 ) ; V_309 ; ) {
struct V_37 * V_88 =
F_135 ( V_309 , struct V_37 , V_89 ) ;
V_309 = F_136 ( V_309 ) ;
if ( F_301 ( V_88 -> V_238 , V_438 ) ) {
F_14 ( L_71 ,
V_88 , V_88 -> V_228 , V_8 -> V_200 ) ;
V_443 = true ;
}
if ( V_437 -> V_441 &&
F_301 ( V_88 -> V_375 , V_440 ) ) {
F_302 ( L_72 ,
V_88 -> V_228 , V_8 -> V_200 ) ;
F_242 ( V_88 , - V_444 ) ;
}
}
for ( V_309 = F_134 ( & V_8 -> V_205 ) ; V_309 ; V_309 = F_136 ( V_309 ) ) {
struct V_10 * V_11 =
F_135 ( V_309 , struct V_10 , V_230 ) ;
F_14 ( L_73 ,
V_11 , V_11 -> V_231 , V_8 -> V_200 ) ;
V_443 = true ;
F_225 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_415 && V_11 -> V_423 && ! V_11 -> V_421 )
F_284 ( V_11 ) ;
F_228 ( & V_11 -> V_6 ) ;
}
if ( V_443 )
F_303 ( & V_8 -> V_209 , & V_442 ) ;
}
if ( V_437 -> V_441 ) {
for ( V_309 = F_134 ( & V_5 -> V_229 . V_203 ) ; V_309 ; ) {
struct V_37 * V_88 =
F_135 ( V_309 , struct V_37 , V_89 ) ;
V_309 = F_136 ( V_309 ) ;
if ( F_301 ( V_88 -> V_375 , V_440 ) ) {
F_302 ( L_72 ,
V_88 -> V_228 , V_5 -> V_229 . V_200 ) ;
F_242 ( V_88 , - V_444 ) ;
}
}
}
if ( F_304 ( & V_5 -> V_242 ) || ! F_51 ( & V_442 ) )
F_220 ( V_5 ) ;
while ( ! F_51 ( & V_442 ) ) {
struct V_7 * V_8 = F_305 ( & V_442 ,
struct V_7 ,
V_209 ) ;
F_131 ( & V_8 -> V_209 ) ;
F_306 ( & V_8 -> V_216 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_307 ( & V_5 -> V_435 ,
V_5 -> V_218 -> V_224 -> V_439 ) ;
}
static void F_308 ( struct V_413 * V_409 )
{
struct V_4 * V_5 =
F_53 ( V_409 , struct V_4 ,
V_445 . V_409 ) ;
unsigned long V_446 = V_5 -> V_218 -> V_224 -> V_225 / 4 ;
struct V_7 * V_8 , * V_447 ;
F_14 ( L_70 , V_95 , V_5 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_309 (osd, nosd, &osdc->osd_lru, o_osd_lru) {
if ( F_301 ( V_223 , V_8 -> V_222 ) )
break;
F_6 ( ! F_115 ( & V_8 -> V_203 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_205 ) ) ;
F_132 ( V_8 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_307 ( & V_5 -> V_445 ,
F_310 ( V_446 ) ) ;
}
static int F_311 ( void * * V_309 , void * V_310 ,
struct V_121 * V_122 )
{
T_7 V_311 , V_448 ;
T_2 V_124 ;
void * V_449 ;
int V_270 = 0 ;
F_312 ( V_309 , V_310 , 1 + 1 + 4 , V_313 ) ;
V_311 = F_313 ( V_309 ) ;
V_448 = F_313 ( V_309 ) ;
if ( V_311 < 3 ) {
F_314 ( L_74 ,
V_311 , V_448 ) ;
goto V_313;
}
if ( V_448 > 6 ) {
F_314 ( L_75 ,
V_311 , V_448 ) ;
goto V_313;
}
V_124 = F_211 ( V_309 ) ;
F_312 ( V_309 , V_310 , V_124 , V_313 ) ;
V_449 = * V_309 + V_124 ;
V_122 -> V_194 = F_210 ( V_309 ) ;
* V_309 += 4 ;
V_124 = F_211 ( V_309 ) ;
if ( V_124 > 0 ) {
F_314 ( L_76 ) ;
goto V_313;
}
if ( V_311 >= 5 ) {
bool V_450 = false ;
V_124 = F_211 ( V_309 ) ;
if ( V_124 > 0 ) {
F_312 ( V_309 , V_310 , V_124 , V_313 ) ;
if ( ! V_122 -> V_123 ||
F_315 ( V_122 -> V_123 , * V_309 , V_124 ) )
V_450 = true ;
* V_309 += V_124 ;
} else {
if ( V_122 -> V_123 )
V_450 = true ;
}
if ( V_450 ) {
F_314 ( L_77 ) ;
goto V_313;
}
}
if ( V_311 >= 6 ) {
T_8 V_314 = F_210 ( V_309 ) ;
if ( V_314 != - 1 ) {
F_314 ( L_78 ) ;
goto V_313;
}
}
* V_309 = V_449 ;
V_272:
return V_270 ;
V_313:
V_270 = - V_315 ;
goto V_272;
}
static int F_316 ( void * * V_309 , void * V_310 ,
struct V_451 * V_452 )
{
T_7 V_311 , V_448 ;
T_2 V_124 ;
void * V_449 ;
int V_270 ;
F_312 ( V_309 , V_310 , 1 + 1 + 4 , V_313 ) ;
V_311 = F_313 ( V_309 ) ;
V_448 = F_313 ( V_309 ) ;
if ( V_448 > 1 ) {
F_314 ( L_79 ,
V_311 , V_448 ) ;
goto V_313;
}
V_124 = F_211 ( V_309 ) ;
F_312 ( V_309 , V_310 , V_124 , V_313 ) ;
V_449 = * V_309 + V_124 ;
V_270 = F_311 ( V_309 , V_310 , & V_452 -> V_122 ) ;
if ( V_270 )
goto V_272;
V_124 = F_211 ( V_309 ) ;
if ( V_124 > 0 ) {
F_314 ( L_80 ) ;
goto V_313;
}
V_124 = F_211 ( V_309 ) ;
* V_309 += V_124 ;
* V_309 = V_449 ;
V_272:
return V_270 ;
V_313:
V_270 = - V_315 ;
goto V_272;
}
static int F_317 ( const struct V_114 * V_126 , struct V_453 * V_383 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_310 = V_309 + V_126 -> V_141 . V_143 ;
T_5 V_341 = F_215 ( V_126 -> V_340 . V_341 ) ;
struct V_354 V_454 ;
T_7 V_455 ;
T_2 V_124 ;
int V_270 ;
int V_329 ;
F_182 ( & V_309 , V_310 , V_124 , V_313 ) ;
F_312 ( & V_309 , V_310 , V_124 , V_313 ) ;
V_309 += V_124 ;
V_270 = F_318 ( & V_309 , V_310 , & V_383 -> V_79 ) ;
if ( V_270 )
return V_270 ;
F_181 ( & V_309 , V_310 , V_383 -> V_84 , V_313 ) ;
F_182 ( & V_309 , V_310 , V_383 -> V_390 , V_313 ) ;
F_312 ( & V_309 , V_310 , sizeof( V_454 ) , V_313 ) ;
memcpy ( & V_454 , V_309 , sizeof( V_454 ) ) ;
V_309 += sizeof( V_454 ) ;
F_182 ( & V_309 , V_310 , V_383 -> V_86 , V_313 ) ;
F_182 ( & V_309 , V_310 , V_383 -> V_107 , V_313 ) ;
if ( V_383 -> V_107 > F_319 ( V_383 -> V_157 ) )
goto V_313;
F_312 ( & V_309 , V_310 , V_383 -> V_107 * sizeof( struct V_136 ) ,
V_313 ) ;
for ( V_329 = 0 ; V_329 < V_383 -> V_107 ; V_329 ++ ) {
struct V_136 * V_51 = V_309 ;
V_383 -> V_157 [ V_329 ] = F_213 ( V_51 -> V_151 ) ;
V_309 += sizeof( * V_51 ) ;
}
F_182 ( & V_309 , V_310 , V_383 -> V_456 , V_313 ) ;
for ( V_329 = 0 ; V_329 < V_383 -> V_107 ; V_329 ++ )
F_182 ( & V_309 , V_310 , V_383 -> V_457 [ V_329 ] , V_313 ) ;
if ( V_341 >= 5 ) {
F_312 ( & V_309 , V_310 , sizeof( V_383 -> V_458 ) , V_313 ) ;
memcpy ( & V_383 -> V_458 , V_309 , sizeof( V_383 -> V_458 ) ) ;
V_309 += sizeof( V_383 -> V_458 ) ;
F_181 ( & V_309 , V_310 , V_383 -> V_459 , V_313 ) ;
} else {
V_383 -> V_458 = V_454 ;
V_383 -> V_459 = F_214 ( V_383 -> V_458 . V_341 ) ;
}
if ( V_341 >= 6 ) {
if ( V_341 >= 7 )
F_183 ( & V_309 , V_310 , V_455 , V_313 ) ;
else
V_455 = 1 ;
} else {
V_455 = 0 ;
}
if ( V_455 ) {
V_270 = F_316 ( & V_309 , V_310 , & V_383 -> V_460 ) ;
if ( V_270 )
return V_270 ;
} else {
F_40 ( & V_383 -> V_460 . V_122 ) ;
}
return 0 ;
V_313:
return - V_315 ;
}
static void F_320 ( struct V_7 * V_8 , struct V_114 * V_126 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_37 * V_88 ;
struct V_453 V_383 ;
T_1 V_355 = F_214 ( V_126 -> V_340 . V_355 ) ;
T_2 V_328 = 0 ;
int V_270 ;
int V_329 ;
F_14 ( L_81 , V_95 , V_126 , V_355 ) ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_200 ) ;
goto V_461;
}
F_6 ( V_8 -> V_200 != F_214 ( V_126 -> V_340 . V_78 . V_462 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_88 = F_321 ( & V_8 -> V_203 , V_355 ) ;
if ( ! V_88 ) {
F_14 ( L_83 , V_95 , V_8 -> V_200 , V_355 ) ;
goto V_463;
}
V_383 . V_460 . V_122 . V_123 = V_88 -> V_98 . V_71 . V_123 ;
V_270 = F_317 ( V_126 , & V_383 ) ;
V_383 . V_460 . V_122 . V_123 = NULL ;
if ( V_270 ) {
F_100 ( L_84 ,
V_88 -> V_228 , V_270 ) ;
F_322 ( V_126 ) ;
goto V_464;
}
F_14 ( L_85 ,
V_95 , V_88 , V_88 -> V_228 , V_383 . V_84 , V_383 . V_79 . V_194 , V_383 . V_79 . V_278 ,
V_383 . V_86 , V_383 . V_456 , F_213 ( V_383 . V_458 . V_86 ) ,
F_214 ( V_383 . V_458 . V_341 ) , V_383 . V_459 ) ;
if ( V_383 . V_456 >= 0 ) {
if ( V_383 . V_456 != V_88 -> V_339 - 1 ) {
F_14 ( L_86 ,
V_88 , V_88 -> V_228 , V_383 . V_456 ,
V_88 -> V_339 - 1 ) ;
goto V_463;
}
} else {
F_6 ( 1 ) ;
}
if ( ! F_78 ( & V_383 . V_460 . V_122 ) ) {
F_14 ( L_87 , V_88 , V_88 -> V_228 ,
V_383 . V_460 . V_122 . V_194 ) ;
F_137 ( V_8 , V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
V_88 -> V_98 . V_71 . V_194 = V_383 . V_460 . V_122 . V_194 ;
V_88 -> V_193 |= V_465 ;
V_88 -> V_228 = 0 ;
F_223 ( V_88 , false ) ;
goto V_461;
}
if ( V_383 . V_107 != V_88 -> V_40 ) {
F_100 ( L_88 , V_383 . V_107 ,
V_88 -> V_40 , V_88 -> V_228 ) ;
goto V_464;
}
for ( V_329 = 0 ; V_329 < V_88 -> V_40 ; V_329 ++ ) {
F_14 ( L_89 , V_88 ,
V_88 -> V_228 , V_329 , V_383 . V_457 [ V_329 ] , V_383 . V_157 [ V_329 ] ) ;
V_88 -> V_41 [ V_329 ] . V_457 = V_383 . V_457 [ V_329 ] ;
V_88 -> V_41 [ V_329 ] . V_157 = V_383 . V_157 [ V_329 ] ;
V_328 += V_383 . V_157 [ V_329 ] ;
}
if ( V_328 != F_213 ( V_126 -> V_340 . V_328 ) ) {
F_100 ( L_90 , V_328 ,
F_213 ( V_126 -> V_340 . V_328 ) , V_88 -> V_228 ) ;
goto V_464;
}
F_14 ( L_91 , V_95 ,
V_88 , V_88 -> V_228 , V_383 . V_390 , V_328 ) ;
F_6 ( ! ( V_383 . V_84 & V_373 ) ) ;
V_88 -> V_378 = V_383 . V_390 ? : V_328 ;
F_234 ( V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_237 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
return;
V_464:
F_227 ( V_88 , - V_466 ) ;
V_463:
F_228 ( & V_8 -> V_6 ) ;
V_461:
F_4 ( & V_5 -> V_6 ) ;
}
static void F_323 ( struct V_4 * V_5 )
{
struct V_226 * V_227 ;
for ( V_227 = F_134 ( & V_5 -> V_236 -> V_246 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_243 * V_244 =
F_135 ( V_227 , struct V_243 , V_230 ) ;
V_244 -> V_467 = F_153 ( V_244 ) ;
}
}
static bool F_324 ( struct V_4 * V_5 , T_8 V_195 )
{
struct V_243 * V_244 ;
V_244 = F_156 ( V_5 -> V_236 , V_195 ) ;
if ( ! V_244 )
return false ;
return V_244 -> V_467 && ! F_153 ( V_244 ) ;
}
static enum V_255
F_325 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
enum V_255 V_269 ;
V_269 = F_159 ( V_5 , & V_11 -> V_67 , NULL , true ) ;
if ( V_269 == V_282 ) {
struct V_7 * V_8 ;
V_8 = F_146 ( V_5 , V_11 -> V_67 . V_8 , true ) ;
if ( V_8 != V_11 -> V_8 ) {
F_139 ( V_11 -> V_8 , V_11 ) ;
F_140 ( V_8 , V_11 ) ;
}
}
return V_269 ;
}
static void F_326 ( struct V_7 * V_8 ,
bool V_262 ,
bool V_468 ,
bool V_469 ,
struct V_321 * V_470 ,
struct V_471 * V_472 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_226 * V_227 ;
bool V_473 ;
for ( V_227 = F_134 ( & V_8 -> V_205 ) ; V_227 ; ) {
struct V_10 * V_11 =
F_135 ( V_227 , struct V_10 , V_230 ) ;
enum V_255 V_269 ;
V_227 = F_136 ( V_227 ) ;
F_14 ( L_58 , V_95 , V_11 ,
V_11 -> V_231 ) ;
V_269 = F_325 ( V_11 ) ;
switch ( V_269 ) {
case V_283 :
V_473 = V_468 ||
( V_469 &&
F_324 ( V_5 , V_11 -> V_67 . V_69 . V_194 ) ) ;
if ( ! V_262 && ! V_473 )
break;
case V_282 :
F_286 ( V_11 ) ;
if ( F_51 ( & V_11 -> V_398 ) )
F_127 ( & V_11 -> V_398 , V_472 ) ;
break;
case V_271 :
F_131 ( & V_11 -> V_398 ) ;
F_291 ( V_11 ) ;
break;
}
}
for ( V_227 = F_134 ( & V_8 -> V_203 ) ; V_227 ; ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
enum V_255 V_269 ;
V_227 = F_136 ( V_227 ) ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_228 ) ;
V_269 = F_159 ( V_5 , & V_88 -> V_98 , & V_88 -> V_92 -> V_216 ,
false ) ;
switch ( V_269 ) {
case V_283 :
V_473 = V_468 ||
( V_469 &&
F_324 ( V_5 , V_88 -> V_98 . V_69 . V_194 ) ) ;
if ( ! V_262 &&
( ! ( V_88 -> V_193 & V_198 ) ||
! V_473 ) )
break;
case V_282 :
F_239 ( V_88 ) ;
F_137 ( V_8 , V_88 ) ;
F_150 ( V_470 , V_88 ) ;
break;
case V_271 :
F_249 ( V_88 ) ;
break;
}
}
}
static int F_327 ( struct V_4 * V_5 ,
void * V_309 , void * V_310 , bool V_474 ,
struct V_321 * V_470 ,
struct V_471 * V_472 )
{
struct V_384 * V_475 ;
struct V_226 * V_227 ;
bool V_476 = false ;
bool V_467 ;
V_467 = F_158 ( V_5 , V_251 ) ;
F_323 ( V_5 ) ;
if ( V_474 )
V_475 = F_328 ( & V_309 , V_310 , V_5 -> V_236 ) ;
else
V_475 = F_329 ( & V_309 , V_310 ) ;
if ( F_179 ( V_475 ) )
return F_180 ( V_475 ) ;
if ( V_475 != V_5 -> V_236 ) {
for ( V_227 = F_134 ( & V_475 -> V_246 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_243 * V_244 =
F_135 ( V_227 , struct V_243 , V_230 ) ;
struct V_243 * V_477 ;
V_477 = F_156 ( V_5 -> V_236 , V_244 -> V_252 ) ;
if ( V_477 )
V_244 -> V_467 = V_477 -> V_467 ;
else
F_6 ( V_244 -> V_467 ) ;
}
if ( V_5 -> V_236 -> V_86 &&
V_5 -> V_236 -> V_86 + 1 < V_475 -> V_86 ) {
F_6 ( V_474 ) ;
V_476 = true ;
}
F_330 ( V_5 -> V_236 ) ;
V_5 -> V_236 = V_475 ;
}
V_467 &= ! F_158 ( V_5 , V_251 ) ;
F_326 ( & V_5 -> V_229 , V_476 , V_467 , true ,
V_470 , V_472 ) ;
for ( V_227 = F_134 ( & V_5 -> V_232 ) ; V_227 ; ) {
struct V_7 * V_8 = F_135 ( V_227 , struct V_7 , V_201 ) ;
V_227 = F_136 ( V_227 ) ;
F_326 ( V_8 , V_476 , V_467 , true , V_470 ,
V_472 ) ;
if ( ! F_331 ( V_5 -> V_236 , V_8 -> V_200 ) ||
memcmp ( & V_8 -> V_216 . V_234 ,
F_332 ( V_5 -> V_236 , V_8 -> V_200 ) ,
sizeof( struct V_233 ) ) )
F_132 ( V_8 ) ;
}
return 0 ;
}
static void F_333 ( struct V_4 * V_5 ,
struct V_321 * V_470 ,
struct V_471 * V_472 )
{
struct V_10 * V_11 , * V_478 ;
enum V_255 V_269 ;
struct V_226 * V_227 ;
for ( V_227 = F_134 ( V_470 ) ; V_227 ; ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
V_227 = F_136 ( V_227 ) ;
if ( V_88 -> V_98 . V_86 < V_5 -> V_236 -> V_86 ) {
V_269 = F_159 ( V_5 , & V_88 -> V_98 , NULL , false ) ;
if ( V_269 == V_271 ) {
F_151 ( V_470 , V_88 ) ;
F_249 ( V_88 ) ;
}
}
}
for ( V_227 = F_134 ( V_470 ) ; V_227 ; ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
struct V_7 * V_8 ;
V_227 = F_136 ( V_227 ) ;
F_151 ( V_470 , V_88 ) ;
V_8 = F_146 ( V_5 , V_88 -> V_98 . V_8 , true ) ;
F_138 ( V_8 , V_88 ) ;
if ( ! V_88 -> V_113 ) {
if ( ! F_109 ( V_8 ) && ! V_88 -> V_98 . V_85 )
F_216 ( V_88 ) ;
} else {
F_266 ( V_88 ) ;
}
}
F_309 (lreq, nlreq, need_resend_linger, scan_item) {
if ( ! F_109 ( V_11 -> V_8 ) )
F_282 ( V_11 ) ;
F_131 ( & V_11 -> V_398 ) ;
}
}
void F_334 ( struct V_4 * V_5 , struct V_114 * V_126 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_310 = V_309 + V_126 -> V_141 . V_143 ;
T_2 V_479 , V_480 ;
T_2 V_86 ;
struct V_481 V_482 ;
struct V_321 V_470 = V_204 ;
F_300 ( V_472 ) ;
bool V_483 = false ;
bool V_484 , V_485 ;
bool V_247 , V_249 ;
int V_379 ;
F_14 ( L_92 , V_95 , V_5 -> V_236 -> V_86 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_312 ( & V_309 , V_310 , sizeof( V_482 ) , V_486 ) ;
F_335 ( & V_309 , & V_482 , sizeof( V_482 ) ) ;
if ( F_336 ( V_5 -> V_218 , & V_482 ) < 0 )
goto V_486;
V_484 = F_158 ( V_5 , V_248 ) ;
V_485 = F_158 ( V_5 , V_250 ) ||
F_158 ( V_5 , V_251 ) ||
F_154 ( V_5 ) ;
F_182 ( & V_309 , V_310 , V_479 , V_486 ) ;
F_14 ( L_93 , V_479 ) ;
while ( V_479 > 0 ) {
F_312 ( & V_309 , V_310 , 2 * sizeof( T_2 ) , V_486 ) ;
V_86 = F_211 ( & V_309 ) ;
V_480 = F_211 ( & V_309 ) ;
F_312 ( & V_309 , V_310 , V_480 , V_486 ) ;
if ( V_5 -> V_236 -> V_86 &&
V_5 -> V_236 -> V_86 + 1 == V_86 ) {
F_14 ( L_94 ,
V_86 , V_480 ) ;
V_379 = F_327 ( V_5 , V_309 , V_309 + V_480 , true ,
& V_470 , & V_472 ) ;
if ( V_379 )
goto V_486;
V_483 = true ;
} else {
F_14 ( L_95 ,
V_86 , V_480 ) ;
}
V_309 += V_480 ;
V_479 -- ;
}
if ( V_483 )
goto V_487;
F_182 ( & V_309 , V_310 , V_479 , V_486 ) ;
F_14 ( L_96 , V_479 ) ;
while ( V_479 ) {
F_312 ( & V_309 , V_310 , 2 * sizeof( T_2 ) , V_486 ) ;
V_86 = F_211 ( & V_309 ) ;
V_480 = F_211 ( & V_309 ) ;
F_312 ( & V_309 , V_310 , V_480 , V_486 ) ;
if ( V_479 > 1 ) {
F_14 ( L_97 ,
V_86 , V_480 ) ;
} else if ( V_5 -> V_236 -> V_86 >= V_86 ) {
F_14 ( L_98
L_99 , V_86 , V_480 ,
V_5 -> V_236 -> V_86 ) ;
} else {
F_14 ( L_100 , V_86 , V_480 ) ;
V_379 = F_327 ( V_5 , V_309 , V_309 + V_480 , false ,
& V_470 , & V_472 ) ;
if ( V_379 )
goto V_486;
}
V_309 += V_480 ;
V_479 -- ;
}
V_487:
V_247 = F_158 ( V_5 , V_248 ) ;
V_249 = F_158 ( V_5 , V_250 ) ||
F_158 ( V_5 , V_251 ) ||
F_154 ( V_5 ) ;
if ( V_484 || V_485 || V_247 || V_249 ||
V_5 -> V_236 -> V_86 < V_5 -> V_254 )
F_220 ( V_5 ) ;
F_333 ( V_5 , & V_470 , & V_472 ) ;
F_248 ( V_5 ) ;
F_337 ( & V_5 -> V_218 -> V_361 , V_362 ,
V_5 -> V_236 -> V_86 ) ;
F_247 ( & V_5 -> V_6 ) ;
F_338 ( & V_5 -> V_218 -> V_488 ) ;
return;
V_486:
F_100 ( L_101 ) ;
F_322 ( V_126 ) ;
F_247 ( & V_5 -> V_6 ) ;
}
static void F_339 ( struct V_7 * V_8 )
{
struct V_226 * V_227 ;
F_141 ( V_8 ) ;
for ( V_227 = F_134 ( & V_8 -> V_203 ) ; V_227 ; ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
V_227 = F_136 ( V_227 ) ;
if ( ! V_88 -> V_113 ) {
if ( ! V_88 -> V_98 . V_85 )
F_216 ( V_88 ) ;
} else {
F_266 ( V_88 ) ;
}
}
for ( V_227 = F_134 ( & V_8 -> V_205 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_10 * V_11 =
F_135 ( V_227 , struct V_10 , V_230 ) ;
F_282 ( V_11 ) ;
}
}
static void F_340 ( struct V_256 * V_257 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_200 ) ;
F_231 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_200 ) ;
goto V_393;
}
if ( ! F_143 ( V_8 ) )
F_339 ( V_8 ) ;
F_220 ( V_5 ) ;
V_393:
F_247 ( & V_5 -> V_6 ) ;
}
static int F_341 ( const struct V_114 * V_126 , struct V_490 * V_383 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_310 = V_309 + V_126 -> V_141 . V_143 ;
T_7 V_311 ;
T_2 V_312 ;
int V_270 ;
V_270 = F_177 ( & V_309 , V_310 , 1 , L_102 , & V_311 , & V_312 ) ;
if ( V_270 )
return V_270 ;
V_270 = F_318 ( & V_309 , V_310 , & V_383 -> V_80 . V_79 ) ;
if ( V_270 )
return V_270 ;
F_183 ( & V_309 , V_310 , V_383 -> V_80 . V_327 , V_313 ) ;
F_182 ( & V_309 , V_310 , V_383 -> V_491 , V_313 ) ;
F_183 ( & V_309 , V_310 , V_383 -> V_51 , V_313 ) ;
F_181 ( & V_309 , V_310 , V_383 -> V_252 , V_313 ) ;
V_383 -> V_320 = F_118 ( sizeof( * V_383 -> V_320 ) , V_214 ) ;
if ( ! V_383 -> V_320 )
return - V_140 ;
V_270 = F_176 ( & V_309 , V_310 , V_383 -> V_320 ) ;
if ( V_270 ) {
F_192 ( V_383 -> V_320 ) ;
return V_270 ;
}
V_383 -> V_310 = F_118 ( sizeof( * V_383 -> V_310 ) , V_214 ) ;
if ( ! V_383 -> V_310 ) {
F_192 ( V_383 -> V_320 ) ;
return - V_140 ;
}
V_270 = F_176 ( & V_309 , V_310 , V_383 -> V_310 ) ;
if ( V_270 ) {
F_192 ( V_383 -> V_320 ) ;
F_192 ( V_383 -> V_310 ) ;
return V_270 ;
}
return 0 ;
V_313:
return - V_315 ;
}
static struct V_114 * F_342 (
const struct V_316 * V_317 ,
T_2 V_491 )
{
struct V_114 * V_126 ;
void * V_309 , * V_310 ;
int V_127 ;
V_127 = V_130 +
V_131 + 1 ;
V_127 += 4 + 1 + 8 ;
V_127 += V_130 +
F_185 ( V_317 -> V_320 ) ;
V_127 += V_130 +
F_185 ( V_317 -> V_310 ) ;
V_126 = F_80 ( V_492 , V_127 , V_214 , true ) ;
if ( ! V_126 )
return NULL ;
V_309 = V_126 -> V_141 . V_142 ;
V_310 = V_309 + V_126 -> V_333 ;
F_204 ( & V_309 , & V_317 -> V_80 ) ;
F_190 ( & V_309 , V_491 ) ;
F_191 ( & V_309 , V_493 ) ;
F_189 ( & V_309 , V_317 -> V_252 ) ;
F_186 ( & V_309 , V_310 , V_317 -> V_320 ) ;
F_186 ( & V_309 , V_310 , V_317 -> V_310 ) ;
F_20 ( V_309 != V_310 ) ;
V_126 -> V_141 . V_143 = V_309 - V_126 -> V_141 . V_142 ;
V_126 -> V_340 . V_341 = F_104 ( 1 ) ;
V_126 -> V_340 . V_342 = F_102 ( V_126 -> V_141 . V_143 ) ;
return V_126 ;
}
static void F_343 ( struct V_7 * V_8 , struct V_490 * V_383 )
{
struct V_284 * V_285 ;
struct V_316 * V_317 ;
struct V_114 * V_126 ;
F_14 ( L_103 , V_95 , V_8 -> V_200 ,
V_383 -> V_80 . V_79 . V_194 , V_383 -> V_80 . V_79 . V_278 , V_383 -> V_80 . V_327 , V_383 -> V_252 ) ;
V_285 = F_201 ( & V_8 -> V_206 , & V_383 -> V_80 ) ;
if ( ! V_285 ) {
V_285 = F_169 () ;
if ( ! V_285 ) {
F_100 ( L_104 , V_95 ) ;
return;
}
V_285 -> V_80 = V_383 -> V_80 ;
F_344 ( & V_8 -> V_206 , V_285 ) ;
}
V_317 = F_193 () ;
if ( ! V_317 ) {
F_100 ( L_105 , V_95 ) ;
return;
}
V_317 -> V_80 = V_383 -> V_80 ;
V_317 -> V_252 = V_383 -> V_252 ;
V_317 -> V_320 = V_383 -> V_320 ;
V_383 -> V_320 = NULL ;
V_317 -> V_310 = V_383 -> V_310 ;
V_383 -> V_310 = NULL ;
F_345 ( & V_285 -> V_286 , V_317 ) ;
F_346 ( & V_8 -> V_207 , V_317 ) ;
V_126 = F_342 ( V_317 , V_383 -> V_491 ) ;
if ( ! V_126 ) {
F_100 ( L_106 , V_95 ) ;
return;
}
F_218 ( & V_8 -> V_216 , V_126 ) ;
}
static bool F_347 ( const struct V_66 * V_67 ,
const struct V_287 * V_320 ,
const struct V_287 * V_310 )
{
struct V_287 V_288 ;
int V_324 ;
F_199 ( & V_288 , V_67 ) ;
V_324 = F_175 ( & V_288 , V_320 ) ;
return ! V_324 || ( V_324 > 0 && F_175 ( & V_288 , V_310 ) < 0 ) ;
}
static void F_348 ( struct V_7 * V_8 ,
const struct V_490 * V_383 )
{
struct V_284 * V_285 ;
struct V_316 * V_317 ;
struct V_226 * V_227 ;
F_14 ( L_103 , V_95 , V_8 -> V_200 ,
V_383 -> V_80 . V_79 . V_194 , V_383 -> V_80 . V_79 . V_278 , V_383 -> V_80 . V_327 , V_383 -> V_252 ) ;
V_317 = F_349 ( & V_8 -> V_207 , V_383 -> V_252 ) ;
if ( ! V_317 ) {
F_100 ( L_107 ,
V_95 , V_8 -> V_200 , V_383 -> V_80 . V_79 . V_194 ,
V_383 -> V_80 . V_79 . V_278 , V_383 -> V_80 . V_327 , V_383 -> V_252 ) ;
return;
}
if ( F_175 ( V_317 -> V_320 , V_383 -> V_320 ) &&
F_175 ( V_317 -> V_310 , V_383 -> V_310 ) ) {
F_100 ( L_108 ,
V_95 , V_8 -> V_200 , V_383 -> V_80 . V_79 . V_194 ,
V_383 -> V_80 . V_79 . V_278 , V_383 -> V_80 . V_327 , V_383 -> V_252 ) ;
}
V_285 = F_201 ( & V_8 -> V_206 , & V_317 -> V_80 ) ;
F_20 ( ! V_285 ) ;
F_196 ( & V_285 -> V_286 , V_317 ) ;
F_197 ( & V_8 -> V_207 , V_317 ) ;
F_194 ( V_317 ) ;
if ( F_115 ( & V_285 -> V_286 ) ) {
F_198 ( & V_8 -> V_206 , V_285 ) ;
F_170 ( V_285 ) ;
}
for ( V_227 = F_134 ( & V_8 -> V_203 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_37 * V_88 =
F_135 ( V_227 , struct V_37 , V_89 ) ;
if ( ! F_350 ( & V_88 -> V_98 . V_80 , & V_383 -> V_80 ) ) {
if ( F_347 ( & V_88 -> V_98 , V_383 -> V_320 , V_383 -> V_310 ) ) {
F_216 ( V_88 ) ;
}
}
}
}
static void F_351 ( struct V_7 * V_8 , struct V_114 * V_126 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_490 V_383 ;
int V_270 ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_200 ) ;
F_4 ( & V_5 -> V_6 ) ;
return;
}
F_6 ( V_8 -> V_200 != F_214 ( V_126 -> V_340 . V_78 . V_462 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_270 = F_341 ( V_126 , & V_383 ) ;
if ( V_270 ) {
F_100 ( L_109 , V_270 ) ;
F_322 ( V_126 ) ;
goto V_393;
}
switch ( V_383 . V_51 ) {
case V_494 :
F_343 ( V_8 , & V_383 ) ;
break;
case V_495 :
F_348 ( V_8 , & V_383 ) ;
break;
default:
F_100 ( L_110 , V_95 , V_8 -> V_200 , V_383 . V_51 ) ;
}
F_192 ( V_383 . V_320 ) ;
F_192 ( V_383 . V_310 ) ;
V_393:
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
static void F_352 ( struct V_4 * V_5 ,
struct V_114 * V_126 )
{
void * V_309 = V_126 -> V_141 . V_142 ;
void * const V_310 = V_309 + V_126 -> V_141 . V_143 ;
struct V_10 * V_11 ;
struct V_406 * V_408 ;
T_7 V_496 , V_147 ;
T_1 V_171 , V_416 ;
T_1 V_417 = 0 ;
T_11 V_497 = 0 ;
void * V_419 = NULL ;
T_2 V_151 = 0 ;
F_183 ( & V_309 , V_310 , V_496 , V_486 ) ;
F_183 ( & V_309 , V_310 , V_147 , V_486 ) ;
F_181 ( & V_309 , V_310 , V_171 , V_486 ) ;
V_309 += 8 ;
F_181 ( & V_309 , V_310 , V_416 , V_486 ) ;
if ( V_496 >= 1 ) {
F_182 ( & V_309 , V_310 , V_151 , V_486 ) ;
F_312 ( & V_309 , V_310 , V_151 , V_486 ) ;
V_419 = V_309 ;
V_309 += V_151 ;
}
if ( F_215 ( V_126 -> V_340 . V_341 ) >= 2 )
F_182 ( & V_309 , V_310 , V_497 , V_486 ) ;
if ( F_215 ( V_126 -> V_340 . V_341 ) >= 3 )
F_181 ( & V_309 , V_310 , V_417 , V_486 ) ;
F_246 ( & V_5 -> V_6 ) ;
V_11 = F_353 ( & V_5 -> V_404 , V_171 ) ;
if ( ! V_11 ) {
F_14 ( L_111 , V_95 , V_147 ,
V_171 ) ;
goto V_461;
}
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_112 , V_95 ,
V_147 , V_171 , V_11 , V_11 -> V_415 ) ;
if ( V_147 == V_498 ) {
if ( ! V_11 -> V_421 ) {
V_11 -> V_421 = - V_424 ;
F_275 ( V_11 ) ;
}
} else if ( ! V_11 -> V_415 ) {
if ( V_11 -> V_416 && V_11 -> V_416 != V_416 ) {
F_14 ( L_113 , V_11 ,
V_11 -> V_416 , V_416 ) ;
} else if ( ! F_277 ( & V_11 -> V_401 ) ) {
struct V_499 * V_330 =
F_354 ( & V_126 -> V_330 ,
struct V_499 ,
V_500 ) ;
if ( V_330 ) {
if ( V_11 -> V_501 ) {
F_6 ( V_330 -> type !=
V_502 ) ;
* V_11 -> V_501 = V_330 -> V_25 ;
* V_11 -> V_503 = V_330 -> V_26 ;
} else {
F_36 ( V_330 -> V_25 ,
F_35 ( 0 , V_330 -> V_26 ) ) ;
}
}
V_11 -> V_434 = V_497 ;
F_238 ( & V_11 -> V_401 ) ;
}
} else {
V_408 = F_267 ( V_11 , F_273 ) ;
if ( ! V_408 ) {
F_100 ( L_114 ) ;
goto V_504;
}
V_408 -> V_63 . V_416 = V_416 ;
V_408 -> V_63 . V_417 = V_417 ;
V_408 -> V_63 . V_419 = V_419 ;
V_408 -> V_63 . V_151 = V_151 ;
V_408 -> V_63 . V_126 = F_219 ( V_126 ) ;
F_271 ( V_408 ) ;
}
V_504:
F_228 ( & V_11 -> V_6 ) ;
V_461:
F_4 ( & V_5 -> V_6 ) ;
return;
V_486:
F_100 ( L_115 ) ;
}
int F_355 ( struct V_4 * V_5 ,
struct V_37 * V_88 ,
bool V_505 )
{
F_246 ( & V_5 -> V_6 ) ;
F_233 ( V_88 , false ) ;
F_4 ( & V_5 -> V_6 ) ;
return 0 ;
}
void F_356 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
F_231 ( & V_5 -> V_6 ) ;
if ( V_88 -> V_92 )
F_241 ( V_88 ) ;
F_247 ( & V_5 -> V_6 ) ;
}
static int F_357 ( struct V_37 * V_88 ,
unsigned long V_506 )
{
long V_507 ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_228 ) ;
V_507 = F_358 ( & V_88 -> V_105 ,
F_359 ( V_506 ) ) ;
if ( V_507 <= 0 ) {
V_507 = V_507 ? : - V_444 ;
F_356 ( V_88 ) ;
} else {
V_507 = V_88 -> V_378 ;
}
return V_507 ;
}
int F_360 ( struct V_4 * V_5 ,
struct V_37 * V_88 )
{
return F_357 ( V_88 , 0 ) ;
}
void F_361 ( struct V_4 * V_5 )
{
struct V_226 * V_227 , * V_309 ;
T_1 V_370 = F_362 ( & V_5 -> V_370 ) ;
V_366:
F_246 ( & V_5 -> V_6 ) ;
for ( V_227 = F_134 ( & V_5 -> V_232 ) ; V_227 ; V_227 = F_136 ( V_227 ) ) {
struct V_7 * V_8 = F_135 ( V_227 , struct V_7 , V_201 ) ;
F_225 ( & V_8 -> V_6 ) ;
for ( V_309 = F_134 ( & V_8 -> V_203 ) ; V_309 ; V_309 = F_136 ( V_309 ) ) {
struct V_37 * V_88 =
F_135 ( V_309 , struct V_37 , V_89 ) ;
if ( V_88 -> V_228 > V_370 )
break;
if ( ! ( V_88 -> V_193 & V_198 ) )
continue;
F_59 ( V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_116 ,
V_95 , V_88 , V_88 -> V_228 , V_370 ) ;
F_363 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
goto V_366;
}
F_228 ( & V_8 -> V_6 ) ;
}
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_117 , V_95 , V_370 ) ;
}
static struct V_37 *
F_364 ( struct V_10 * V_11 )
{
struct V_37 * V_88 ;
V_88 = F_70 ( V_11 -> V_5 , NULL , 1 , false , V_214 ) ;
if ( ! V_88 )
return NULL ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
if ( F_76 ( V_88 , V_214 ) ) {
F_62 ( V_88 ) ;
return NULL ;
}
return V_88 ;
}
struct V_10 *
F_365 ( struct V_4 * V_5 ,
struct V_508 * V_295 ,
struct V_121 * V_122 ,
T_12 V_418 ,
T_13 V_420 ,
void * V_330 )
{
struct V_10 * V_11 ;
int V_270 ;
V_11 = F_257 ( V_5 ) ;
if ( ! V_11 )
return F_108 ( - V_140 ) ;
V_11 -> V_415 = true ;
V_11 -> V_418 = V_418 ;
V_11 -> V_420 = V_420 ;
V_11 -> V_330 = V_330 ;
V_11 -> V_429 = V_223 ;
F_43 ( & V_11 -> V_67 . V_68 , V_295 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_122 ) ;
V_11 -> V_67 . V_84 = V_198 ;
F_366 ( & V_11 -> V_348 ) ;
V_11 -> V_394 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_394 ) {
V_270 = - V_140 ;
goto V_509;
}
V_11 -> V_395 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_395 ) {
V_270 = - V_140 ;
goto V_509;
}
F_231 ( & V_5 -> V_6 ) ;
F_262 ( V_11 ) ;
F_93 ( V_11 -> V_394 , 0 , V_11 -> V_231 ,
V_427 ) ;
F_93 ( V_11 -> V_395 , 0 , V_11 -> V_231 ,
V_430 ) ;
F_285 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
V_270 = F_296 ( V_11 ) ;
if ( V_270 ) {
F_290 ( V_11 ) ;
goto V_509;
}
return V_11 ;
V_509:
F_255 ( V_11 ) ;
return F_108 ( V_270 ) ;
}
int F_367 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
struct V_436 * V_437 = V_5 -> V_218 -> V_224 ;
struct V_37 * V_88 ;
int V_270 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_214 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
V_88 -> V_193 = V_198 ;
F_366 ( & V_88 -> V_334 ) ;
F_93 ( V_88 , 0 , V_11 -> V_231 ,
V_510 ) ;
V_270 = F_76 ( V_88 , V_214 ) ;
if ( V_270 )
goto V_511;
F_355 ( V_5 , V_88 , false ) ;
F_290 ( V_11 ) ;
F_255 ( V_11 ) ;
V_270 = F_357 ( V_88 , V_437 -> V_512 ) ;
V_511:
F_62 ( V_88 ) ;
return V_270 ;
}
static int F_368 ( struct V_37 * V_88 , int V_39 ,
T_1 V_416 , T_1 V_171 , void * V_419 ,
T_3 V_151 )
{
struct V_50 * V_51 ;
struct V_31 * V_513 ;
int V_270 ;
V_51 = F_84 ( V_88 , V_39 , V_60 , 0 ) ;
V_513 = F_73 ( sizeof( * V_513 ) , V_214 ) ;
if ( ! V_513 )
return - V_140 ;
F_90 ( V_513 ) ;
V_270 = F_369 ( V_513 , V_416 ) ;
V_270 |= F_369 ( V_513 , V_171 ) ;
if ( V_419 ) {
V_270 |= F_370 ( V_513 , V_151 ) ;
V_270 |= F_91 ( V_513 , V_419 , V_151 ) ;
} else {
V_270 |= F_370 ( V_513 , 0 ) ;
}
if ( V_270 ) {
F_371 ( V_513 ) ;
return - V_140 ;
}
F_17 ( & V_51 -> V_61 . V_46 , V_513 ) ;
V_51 -> V_47 = V_513 -> V_26 ;
return 0 ;
}
int F_372 ( struct V_4 * V_5 ,
struct V_508 * V_295 ,
struct V_121 * V_122 ,
T_1 V_416 ,
T_1 V_171 ,
void * V_419 ,
T_3 V_151 )
{
struct V_37 * V_88 ;
int V_270 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_214 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_295 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_193 = V_253 ;
V_270 = F_76 ( V_88 , V_214 ) ;
if ( V_270 )
goto V_511;
V_270 = F_368 ( V_88 , 0 , V_416 , V_171 , V_419 ,
V_151 ) ;
if ( V_270 )
goto V_511;
F_355 ( V_5 , V_88 , false ) ;
V_270 = F_360 ( V_5 , V_88 ) ;
V_511:
F_62 ( V_88 ) ;
return V_270 ;
}
static int F_373 ( struct V_37 * V_88 , int V_39 ,
T_1 V_171 , T_2 V_514 , T_2 V_506 ,
void * V_419 , T_3 V_151 )
{
struct V_50 * V_51 ;
struct V_31 * V_513 ;
int V_270 ;
V_51 = F_84 ( V_88 , V_39 , V_62 , 0 ) ;
V_51 -> V_63 . V_171 = V_171 ;
V_513 = F_73 ( sizeof( * V_513 ) , V_214 ) ;
if ( ! V_513 )
return - V_140 ;
F_90 ( V_513 ) ;
V_270 = F_370 ( V_513 , 1 ) ;
V_270 |= F_370 ( V_513 , V_506 ) ;
V_270 |= F_370 ( V_513 , V_151 ) ;
V_270 |= F_91 ( V_513 , V_419 , V_151 ) ;
if ( V_270 ) {
F_371 ( V_513 ) ;
return - V_140 ;
}
F_17 ( & V_51 -> V_63 . V_46 , V_513 ) ;
V_51 -> V_47 = V_513 -> V_26 ;
return 0 ;
}
int F_374 ( struct V_4 * V_5 ,
struct V_508 * V_295 ,
struct V_121 * V_122 ,
void * V_419 ,
T_3 V_151 ,
T_2 V_506 ,
struct V_24 * * * V_501 ,
T_3 * V_503 )
{
struct V_10 * V_11 ;
struct V_24 * * V_25 ;
int V_270 ;
F_6 ( ! V_506 ) ;
if ( V_501 ) {
* V_501 = NULL ;
* V_503 = 0 ;
}
V_11 = F_257 ( V_5 ) ;
if ( ! V_11 )
return - V_140 ;
V_11 -> V_501 = V_501 ;
V_11 -> V_503 = V_503 ;
F_43 ( & V_11 -> V_67 . V_68 , V_295 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_122 ) ;
V_11 -> V_67 . V_84 = V_253 ;
V_11 -> V_394 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_394 ) {
V_270 = - V_140 ;
goto V_515;
}
V_25 = F_375 ( 1 , V_214 ) ;
if ( F_179 ( V_25 ) ) {
V_270 = F_180 ( V_25 ) ;
goto V_515;
}
F_231 ( & V_5 -> V_6 ) ;
F_262 ( V_11 ) ;
V_270 = F_373 ( V_11 -> V_394 , 0 , V_11 -> V_231 , 1 ,
V_506 , V_419 , V_151 ) ;
if ( V_270 ) {
F_264 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
F_36 ( V_25 , 1 ) ;
goto V_515;
}
F_16 ( F_22 ( V_11 -> V_394 , 0 , V_63 ,
V_48 ) ,
V_25 , V_516 , 0 , false , true ) ;
F_285 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
V_270 = F_296 ( V_11 ) ;
if ( ! V_270 )
V_270 = F_298 ( V_11 ) ;
else
F_14 ( L_118 , V_11 , V_270 ) ;
F_290 ( V_11 ) ;
V_515:
F_255 ( V_11 ) ;
return V_270 ;
}
int F_376 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
unsigned long V_517 , V_518 ;
int V_270 ;
F_246 ( & V_5 -> V_6 ) ;
F_225 ( & V_11 -> V_6 ) ;
V_517 = V_11 -> V_429 ;
if ( ! F_51 ( & V_11 -> V_399 ) ) {
struct V_406 * V_408 =
F_305 ( & V_11 -> V_399 ,
struct V_406 ,
V_410 ) ;
if ( F_301 ( V_408 -> V_411 , V_517 ) )
V_517 = V_408 -> V_411 ;
}
V_518 = V_223 - V_517 ;
F_14 ( L_119 , V_95 ,
V_11 , V_11 -> V_231 , V_518 , V_11 -> V_421 ) ;
V_270 = V_11 -> V_421 ? : 1 + F_377 ( V_518 ) ;
F_228 ( & V_11 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_270 ;
}
static int F_378 ( void * * V_309 , void * V_310 , struct V_519 * V_520 )
{
T_7 V_311 ;
T_2 V_312 ;
int V_270 ;
V_270 = F_177 ( V_309 , V_310 , 2 , L_120 ,
& V_311 , & V_312 ) ;
if ( V_270 )
return V_270 ;
F_335 ( V_309 , & V_520 -> V_166 , sizeof( V_520 -> V_166 ) ) ;
V_520 -> V_171 = F_210 ( V_309 ) ;
* V_309 += 4 ;
if ( V_311 >= 2 ) {
F_335 ( V_309 , & V_520 -> V_521 , sizeof( V_520 -> V_521 ) ) ;
F_379 ( & V_520 -> V_521 ) ;
}
F_14 ( L_121 , V_95 ,
F_380 ( V_520 -> V_166 ) , V_520 -> V_171 ,
F_381 ( & V_520 -> V_521 . V_522 ) ) ;
return 0 ;
}
static int F_382 ( void * * V_309 , void * V_310 ,
struct V_519 * * V_523 ,
T_2 * V_524 )
{
T_7 V_311 ;
T_2 V_312 ;
int V_329 ;
int V_270 ;
V_270 = F_177 ( V_309 , V_310 , 1 , L_122 ,
& V_311 , & V_312 ) ;
if ( V_270 )
return V_270 ;
* V_524 = F_211 ( V_309 ) ;
* V_523 = F_383 ( * V_524 , sizeof( * * V_523 ) , V_214 ) ;
if ( ! * V_523 )
return - V_140 ;
for ( V_329 = 0 ; V_329 < * V_524 ; V_329 ++ ) {
V_270 = F_378 ( V_309 , V_310 , * V_523 + V_329 ) ;
if ( V_270 ) {
F_58 ( * V_523 ) ;
return V_270 ;
}
}
return 0 ;
}
int F_384 ( struct V_4 * V_5 ,
struct V_508 * V_295 ,
struct V_121 * V_122 ,
struct V_519 * * V_523 ,
T_2 * V_524 )
{
struct V_37 * V_88 ;
struct V_24 * * V_25 ;
int V_270 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_214 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_295 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_193 = V_253 ;
V_270 = F_76 ( V_88 , V_214 ) ;
if ( V_270 )
goto V_511;
V_25 = F_375 ( 1 , V_214 ) ;
if ( F_179 ( V_25 ) ) {
V_270 = F_180 ( V_25 ) ;
goto V_511;
}
F_85 ( V_88 , 0 , V_64 , 0 ) ;
F_16 ( F_22 ( V_88 , 0 , V_65 ,
V_48 ) ,
V_25 , V_516 , 0 , false , true ) ;
F_355 ( V_5 , V_88 , false ) ;
V_270 = F_360 ( V_5 , V_88 ) ;
if ( V_270 >= 0 ) {
void * V_309 = F_279 ( V_25 [ 0 ] ) ;
void * const V_310 = V_309 + V_88 -> V_41 [ 0 ] . V_157 ;
V_270 = F_382 ( & V_309 , V_310 , V_523 , V_524 ) ;
}
V_511:
F_62 ( V_88 ) ;
return V_270 ;
}
void F_385 ( struct V_4 * V_5 )
{
F_14 ( L_70 , V_95 , V_5 ) ;
F_386 ( V_5 -> V_412 ) ;
}
void F_387 ( struct V_4 * V_5 )
{
F_246 ( & V_5 -> V_6 ) ;
F_220 ( V_5 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
int F_388 ( struct V_4 * V_5 ,
struct V_508 * V_295 ,
struct V_121 * V_122 ,
const char * V_158 , const char * V_159 ,
unsigned int V_84 ,
struct V_24 * V_525 , T_3 V_526 ,
struct V_24 * V_527 , T_3 * V_528 )
{
struct V_37 * V_88 ;
int V_270 ;
if ( V_526 > V_516 || ( V_527 && * V_528 > V_516 ) )
return - V_529 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_214 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_295 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_193 = V_84 ;
V_270 = F_76 ( V_88 , V_214 ) ;
if ( V_270 )
goto V_511;
F_89 ( V_88 , 0 , V_55 , V_158 , V_159 ) ;
if ( V_525 )
F_29 ( V_88 , 0 , & V_525 , V_526 ,
0 , false , false ) ;
if ( V_527 )
F_30 ( V_88 , 0 , & V_527 ,
* V_528 , 0 , false , false ) ;
F_355 ( V_5 , V_88 , false ) ;
V_270 = F_360 ( V_5 , V_88 ) ;
if ( V_270 >= 0 ) {
V_270 = V_88 -> V_41 [ 0 ] . V_457 ;
if ( V_527 )
* V_528 = V_88 -> V_41 [ 0 ] . V_157 ;
}
V_511:
F_62 ( V_88 ) ;
return V_270 ;
}
int F_389 ( struct V_4 * V_5 , struct V_530 * V_218 )
{
int V_379 ;
F_14 ( L_123 ) ;
V_5 -> V_218 = V_218 ;
F_390 ( & V_5 -> V_6 ) ;
V_5 -> V_232 = V_204 ;
F_68 ( & V_5 -> V_221 ) ;
F_391 ( & V_5 -> V_220 ) ;
F_111 ( & V_5 -> V_229 ) ;
V_5 -> V_229 . V_9 = V_5 ;
V_5 -> V_229 . V_200 = V_76 ;
V_5 -> V_403 = V_531 ;
V_5 -> V_404 = V_204 ;
V_5 -> V_376 = V_204 ;
V_5 -> V_432 = V_204 ;
F_392 ( & V_5 -> V_435 , F_299 ) ;
F_392 ( & V_5 -> V_445 , F_308 ) ;
V_379 = - V_140 ;
V_5 -> V_236 = F_393 () ;
if ( ! V_5 -> V_236 )
goto V_272;
V_5 -> V_102 = F_394 ( 10 ,
V_104 ) ;
if ( ! V_5 -> V_102 )
goto V_532;
V_379 = F_395 ( & V_5 -> V_138 , V_139 ,
V_516 , 10 , true , L_124 ) ;
if ( V_379 < 0 )
goto V_533;
V_379 = F_395 ( & V_5 -> V_145 , V_146 ,
V_516 , 10 , true , L_125 ) ;
if ( V_379 < 0 )
goto V_534;
V_379 = - V_140 ;
V_5 -> V_412 = F_396 ( L_126 ) ;
if ( ! V_5 -> V_412 )
goto V_535;
F_307 ( & V_5 -> V_435 ,
V_5 -> V_218 -> V_224 -> V_439 ) ;
F_307 ( & V_5 -> V_445 ,
F_310 ( V_5 -> V_218 -> V_224 -> V_225 ) ) ;
return 0 ;
V_535:
F_397 ( & V_5 -> V_145 ) ;
V_534:
F_397 ( & V_5 -> V_138 ) ;
V_533:
F_398 ( V_5 -> V_102 ) ;
V_532:
F_330 ( V_5 -> V_236 ) ;
V_272:
return V_379 ;
}
void F_399 ( struct V_4 * V_5 )
{
F_386 ( V_5 -> V_412 ) ;
F_400 ( V_5 -> V_412 ) ;
F_401 ( & V_5 -> V_435 ) ;
F_401 ( & V_5 -> V_445 ) ;
F_231 ( & V_5 -> V_6 ) ;
while ( ! F_115 ( & V_5 -> V_232 ) ) {
struct V_7 * V_8 = F_135 ( F_134 ( & V_5 -> V_232 ) ,
struct V_7 , V_201 ) ;
F_132 ( V_8 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_6 ( F_122 ( & V_5 -> V_229 . V_202 ) != 1 ) ;
F_114 ( & V_5 -> V_229 ) ;
F_6 ( ! F_51 ( & V_5 -> V_221 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_404 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_376 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_432 ) ) ;
F_6 ( F_304 ( & V_5 -> V_374 ) ) ;
F_6 ( F_304 ( & V_5 -> V_242 ) ) ;
F_330 ( V_5 -> V_236 ) ;
F_398 ( V_5 -> V_102 ) ;
F_397 ( & V_5 -> V_138 ) ;
F_397 ( & V_5 -> V_145 ) ;
}
int F_402 ( struct V_4 * V_5 ,
struct V_187 V_188 , struct V_12 * V_13 ,
T_1 V_14 , T_1 * V_15 ,
T_2 V_150 , T_1 V_149 ,
struct V_24 * * V_25 , int V_49 , int V_536 )
{
struct V_37 * V_88 ;
int V_537 = 0 ;
F_14 ( L_127 , V_188 . V_196 ,
V_188 . V_197 , V_14 , * V_15 ) ;
V_88 = F_105 ( V_5 , V_13 , V_188 , V_14 , V_15 , 0 , 1 ,
V_52 , V_253 ,
NULL , V_150 , V_149 ,
false ) ;
if ( F_179 ( V_88 ) )
return F_180 ( V_88 ) ;
F_24 ( V_88 , 0 ,
V_25 , * V_15 , V_536 , false , false ) ;
F_14 ( L_128 ,
V_14 , * V_15 , * V_15 , V_536 ) ;
V_537 = F_355 ( V_5 , V_88 , false ) ;
if ( ! V_537 )
V_537 = F_360 ( V_5 , V_88 ) ;
F_62 ( V_88 ) ;
F_14 ( L_129 , V_537 ) ;
return V_537 ;
}
int F_403 ( struct V_4 * V_5 , struct V_187 V_188 ,
struct V_12 * V_13 ,
struct V_110 * V_111 ,
T_1 V_14 , T_1 V_124 ,
T_2 V_150 , T_1 V_149 ,
struct V_538 * V_348 ,
struct V_24 * * V_25 , int V_49 )
{
struct V_37 * V_88 ;
int V_537 = 0 ;
int V_536 = V_14 & ~ V_539 ;
V_88 = F_105 ( V_5 , V_13 , V_188 , V_14 , & V_124 , 0 , 1 ,
V_53 , V_198 ,
V_111 , V_150 , V_149 ,
true ) ;
if ( F_179 ( V_88 ) )
return F_180 ( V_88 ) ;
F_24 ( V_88 , 0 , V_25 , V_124 , V_536 ,
false , false ) ;
F_14 ( L_130 , V_14 , V_124 , V_124 ) ;
V_88 -> V_334 = * V_348 ;
V_537 = F_355 ( V_5 , V_88 , true ) ;
if ( ! V_537 )
V_537 = F_360 ( V_5 , V_88 ) ;
F_62 ( V_88 ) ;
if ( V_537 == 0 )
V_537 = V_124 ;
F_14 ( L_131 , V_537 ) ;
return V_537 ;
}
int F_404 ( void )
{
T_3 V_74 = sizeof( struct V_37 ) +
V_103 * sizeof( struct V_50 ) ;
F_20 ( V_104 ) ;
V_104 = F_405 ( L_132 , V_74 ,
0 , 0 , NULL ) ;
return V_104 ? 0 : - V_140 ;
}
void F_406 ( void )
{
F_20 ( ! V_104 ) ;
F_407 ( V_104 ) ;
V_104 = NULL ;
}
static void F_408 ( struct V_256 * V_257 , struct V_114 * V_126 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
struct V_4 * V_5 = V_8 -> V_9 ;
int type = F_215 ( V_126 -> V_340 . type ) ;
switch ( type ) {
case V_540 :
F_334 ( V_5 , V_126 ) ;
break;
case V_146 :
F_320 ( V_8 , V_126 ) ;
break;
case V_492 :
F_351 ( V_8 , V_126 ) ;
break;
case V_541 :
F_352 ( V_5 , V_126 ) ;
break;
default:
F_100 ( L_133 , type ,
F_409 ( type ) ) ;
}
F_54 ( V_126 ) ;
}
static struct V_114 * F_410 ( struct V_256 * V_257 ,
struct V_542 * V_340 ,
int * V_543 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_114 * V_383 = NULL ;
struct V_37 * V_88 ;
int V_342 = F_213 ( V_340 -> V_342 ) ;
int V_328 = F_213 ( V_340 -> V_328 ) ;
T_1 V_355 = F_214 ( V_340 -> V_355 ) ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_134 , V_95 , V_8 -> V_200 ) ;
* V_543 = 1 ;
goto V_461;
}
F_6 ( V_8 -> V_200 != F_214 ( V_340 -> V_78 . V_462 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_88 = F_321 ( & V_8 -> V_203 , V_355 ) ;
if ( ! V_88 ) {
F_14 ( L_135 , V_95 ,
V_8 -> V_200 , V_355 ) ;
* V_543 = 1 ;
goto V_463;
}
F_236 ( V_88 -> V_97 ) ;
if ( V_342 > V_88 -> V_97 -> V_333 ) {
F_314 ( L_136 ,
V_95 , V_8 -> V_200 , V_88 -> V_228 , V_342 ,
V_88 -> V_97 -> V_333 ) ;
V_383 = F_80 ( V_146 , V_342 , V_160 ,
false ) ;
if ( ! V_383 )
goto V_463;
F_54 ( V_88 -> V_97 ) ;
V_88 -> V_97 = V_383 ;
}
if ( V_328 > V_88 -> V_97 -> V_331 ) {
F_314 ( L_137 ,
V_95 , V_8 -> V_200 , V_88 -> V_228 , V_328 ,
V_88 -> V_97 -> V_331 ) ;
V_383 = NULL ;
* V_543 = 1 ;
goto V_463;
}
V_383 = F_219 ( V_88 -> V_97 ) ;
F_14 ( L_138 , V_355 , V_383 ) ;
V_463:
F_228 ( & V_8 -> V_6 ) ;
V_461:
F_4 ( & V_5 -> V_6 ) ;
return V_383 ;
}
static struct V_114 * F_411 ( struct V_542 * V_340 )
{
struct V_114 * V_383 ;
int type = F_215 ( V_340 -> type ) ;
T_2 V_342 = F_213 ( V_340 -> V_342 ) ;
T_2 V_328 = F_213 ( V_340 -> V_328 ) ;
V_383 = F_80 ( type , V_342 , V_214 , false ) ;
if ( ! V_383 )
return NULL ;
if ( V_328 ) {
struct V_24 * * V_25 ;
struct V_21 V_22 ;
V_25 = F_375 ( F_35 ( 0 , V_328 ) ,
V_214 ) ;
if ( F_179 ( V_25 ) ) {
F_54 ( V_383 ) ;
return NULL ;
}
F_16 ( & V_22 , V_25 , V_328 , 0 , false ,
false ) ;
F_95 ( V_383 , & V_22 ) ;
}
return V_383 ;
}
static struct V_114 * F_412 ( struct V_256 * V_257 ,
struct V_542 * V_340 ,
int * V_543 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
int type = F_215 ( V_340 -> type ) ;
* V_543 = 0 ;
switch ( type ) {
case V_540 :
case V_492 :
case V_541 :
return F_411 ( V_340 ) ;
case V_146 :
return F_410 ( V_257 , V_340 , V_543 ) ;
default:
F_314 ( L_139 , V_95 ,
V_8 -> V_200 , type ) ;
* V_543 = 1 ;
return NULL ;
}
}
static struct V_256 * F_413 ( struct V_256 * V_257 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
if ( F_120 ( V_8 ) )
return V_257 ;
return NULL ;
}
static void F_414 ( struct V_256 * V_257 )
{
struct V_7 * V_8 = V_257 -> V_489 ;
F_123 ( V_8 ) ;
}
static struct V_544 * F_415 ( struct V_256 * V_257 ,
int * V_545 , int V_546 )
{
struct V_7 * V_241 = V_257 -> V_489 ;
struct V_4 * V_5 = V_241 -> V_9 ;
struct V_547 * V_548 = V_5 -> V_218 -> V_361 . V_549 ;
struct V_544 * V_549 = & V_241 -> V_211 ;
if ( V_546 && V_549 -> V_212 ) {
F_116 ( V_549 -> V_212 ) ;
V_549 -> V_212 = NULL ;
}
if ( ! V_549 -> V_212 ) {
int V_270 = F_416 ( V_548 , V_240 ,
V_549 ) ;
if ( V_270 )
return F_108 ( V_270 ) ;
} else {
int V_270 = F_417 ( V_548 , V_240 ,
V_549 ) ;
if ( V_270 )
return F_108 ( V_270 ) ;
}
* V_545 = V_548 -> V_550 ;
return V_549 ;
}
static int F_418 ( struct V_256 * V_257 )
{
struct V_7 * V_241 = V_257 -> V_489 ;
struct V_4 * V_5 = V_241 -> V_9 ;
struct V_547 * V_548 = V_5 -> V_218 -> V_361 . V_549 ;
return F_419 ( V_548 , V_241 -> V_211 . V_212 ) ;
}
static int F_420 ( struct V_256 * V_257 )
{
struct V_7 * V_241 = V_257 -> V_489 ;
struct V_4 * V_5 = V_241 -> V_9 ;
struct V_547 * V_548 = V_5 -> V_218 -> V_361 . V_549 ;
F_421 ( V_548 , V_240 ) ;
return F_422 ( & V_5 -> V_218 -> V_361 ) ;
}
static void F_423 ( struct V_114 * V_126 )
{
int type = F_215 ( V_126 -> V_340 . type ) ;
if ( type == V_139 )
F_209 ( V_126 ) ;
}
static int F_424 ( struct V_114 * V_126 )
{
struct V_7 * V_241 = V_126 -> V_257 -> V_489 ;
struct V_544 * V_549 = & V_241 -> V_211 ;
return F_425 ( V_549 , V_126 ) ;
}
static int F_426 ( struct V_114 * V_126 )
{
struct V_7 * V_241 = V_126 -> V_257 -> V_489 ;
struct V_544 * V_549 = & V_241 -> V_211 ;
return F_427 ( V_549 , V_126 ) ;
}
