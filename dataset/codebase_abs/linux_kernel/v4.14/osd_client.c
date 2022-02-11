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
case V_173 :
V_182 -> V_174 . V_171 = F_101 ( V_78 -> V_174 . V_171 ) ;
V_182 -> V_174 . V_183 = F_101 ( 0 ) ;
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
case V_184 :
case V_185 :
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
struct V_186 V_187 ,
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
V_147 != V_184 && V_147 != V_185 ) ;
V_88 = F_70 ( V_5 , V_111 , V_107 , V_117 ,
V_160 ) ;
if ( ! V_88 ) {
V_20 = - V_140 ;
goto V_188;
}
V_20 = F_12 ( V_13 , V_14 , V_15 , & V_16 , & V_17 , & V_18 ) ;
if ( V_20 )
goto V_188;
if ( V_147 == V_184 || V_147 == V_185 ) {
F_85 ( V_88 , V_39 , V_147 , 0 ) ;
} else {
T_2 V_189 = V_13 -> V_189 ;
T_2 V_190 = V_14 - V_17 ;
if ( ! ( V_150 == 1 && V_149 == - 1ULL ) ) {
if ( V_149 <= V_190 ) {
V_149 = 0 ;
} else {
V_149 -= V_190 ;
if ( V_149 > V_189 )
V_149 = V_189 ;
}
}
F_86 ( V_88 , V_39 , V_147 , V_17 , V_18 ,
V_149 , V_150 ) ;
}
V_88 -> V_191 = true ;
V_88 -> V_192 = V_84 ;
V_88 -> V_129 . V_193 = V_13 -> V_194 ;
V_88 -> V_129 . V_123 = F_106 ( V_13 -> V_123 ) ;
F_107 ( & V_88 -> V_128 , L_9 , V_187 . V_195 , V_16 ) ;
V_88 -> V_109 = V_187 . V_196 ;
if ( V_84 & V_197 )
V_88 -> V_198 = V_14 ;
V_20 = F_76 ( V_88 , V_160 ) ;
if ( V_20 )
goto V_188;
return V_88 ;
V_188:
F_62 ( V_88 ) ;
return F_108 ( V_20 ) ;
}
static bool F_109 ( struct V_7 * V_8 )
{
return V_8 -> V_199 == V_76 ;
}
static bool F_110 ( struct V_7 * V_8 )
{
F_5 ( V_8 -> V_9 ) ;
return ! F_50 ( & V_8 -> V_200 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
F_112 ( & V_8 -> V_201 , 1 ) ;
F_67 ( & V_8 -> V_200 ) ;
V_8 -> V_202 = V_203 ;
V_8 -> V_204 = V_203 ;
V_8 -> V_205 = V_203 ;
V_8 -> V_206 = V_203 ;
F_68 ( & V_8 -> V_207 ) ;
F_68 ( & V_8 -> V_208 ) ;
V_8 -> V_209 = 1 ;
F_113 ( & V_8 -> V_6 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_6 ( ! F_50 ( & V_8 -> V_200 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_202 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_204 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_205 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_206 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_207 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_208 ) ) ;
if ( V_8 -> V_210 . V_211 ) {
F_6 ( F_109 ( V_8 ) ) ;
F_116 ( V_8 -> V_210 . V_211 ) ;
}
}
static struct V_7 * F_117 ( struct V_4 * V_5 , int V_212 )
{
struct V_7 * V_8 ;
F_6 ( V_212 == V_76 ) ;
V_8 = F_118 ( sizeof( * V_8 ) , V_213 | V_214 ) ;
F_111 ( V_8 ) ;
V_8 -> V_9 = V_5 ;
V_8 -> V_199 = V_212 ;
F_119 ( & V_8 -> V_215 , V_8 , & V_216 , & V_5 -> V_217 -> V_218 ) ;
return V_8 ;
}
static struct V_7 * F_120 ( struct V_7 * V_8 )
{
if ( F_121 ( & V_8 -> V_201 ) ) {
F_14 ( L_10 , V_8 , F_122 ( & V_8 -> V_201 ) - 1 ,
F_122 ( & V_8 -> V_201 ) ) ;
return V_8 ;
} else {
F_14 ( L_11 , V_8 ) ;
return NULL ;
}
}
static void F_123 ( struct V_7 * V_8 )
{
F_14 ( L_12 , V_8 , F_122 ( & V_8 -> V_201 ) ,
F_122 ( & V_8 -> V_201 ) - 1 ) ;
if ( F_124 ( & V_8 -> V_201 ) ) {
F_114 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_199 ) ;
F_20 ( ! F_51 ( & V_8 -> V_207 ) ) ;
F_126 ( & V_5 -> V_219 ) ;
F_127 ( & V_8 -> V_207 , & V_5 -> V_220 ) ;
F_128 ( & V_5 -> V_219 ) ;
V_8 -> V_221 = V_222 + V_5 -> V_217 -> V_223 -> V_224 ;
}
static void F_129 ( struct V_7 * V_8 )
{
if ( F_115 ( & V_8 -> V_202 ) &&
F_115 ( & V_8 -> V_204 ) )
F_125 ( V_8 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_199 ) ;
F_126 ( & V_5 -> V_219 ) ;
if ( ! F_51 ( & V_8 -> V_207 ) )
F_131 ( & V_8 -> V_207 ) ;
F_128 ( & V_5 -> V_219 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_225 * V_226 ;
F_8 ( V_5 ) ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_199 ) ;
F_133 ( & V_8 -> V_215 ) ;
for ( V_226 = F_134 ( & V_8 -> V_202 ) ; V_226 ; ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
V_226 = F_136 ( V_226 ) ;
F_14 ( L_14 , V_88 , V_88 -> V_227 ) ;
F_137 ( V_8 , V_88 ) ;
F_138 ( & V_5 -> V_228 , V_88 ) ;
}
for ( V_226 = F_134 ( & V_8 -> V_204 ) ; V_226 ; ) {
struct V_10 * V_11 =
F_135 ( V_226 , struct V_10 , V_229 ) ;
V_226 = F_136 ( V_226 ) ;
F_14 ( L_15 , V_11 ,
V_11 -> V_230 ) ;
F_139 ( V_8 , V_11 ) ;
F_140 ( & V_5 -> V_228 , V_11 ) ;
}
F_141 ( V_8 ) ;
F_130 ( V_8 ) ;
F_142 ( & V_5 -> V_231 , V_8 ) ;
F_123 ( V_8 ) ;
}
static int F_143 ( struct V_7 * V_8 )
{
struct V_232 * V_233 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_199 ) ;
if ( F_115 ( & V_8 -> V_202 ) &&
F_115 ( & V_8 -> V_204 ) ) {
F_132 ( V_8 ) ;
return - V_234 ;
}
V_233 = & V_8 -> V_9 -> V_235 -> V_236 [ V_8 -> V_199 ] ;
if ( ! memcmp ( V_233 , & V_8 -> V_215 . V_233 , sizeof ( * V_233 ) ) &&
! F_144 ( & V_8 -> V_215 ) ) {
struct V_225 * V_226 ;
F_14 ( L_16
L_17 ) ;
for ( V_226 = F_134 ( & V_8 -> V_202 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
V_88 -> V_237 = V_222 ;
}
return - V_238 ;
}
F_133 ( & V_8 -> V_215 ) ;
F_145 ( & V_8 -> V_215 , V_239 , V_8 -> V_199 , V_233 ) ;
V_8 -> V_209 ++ ;
return 0 ;
}
static struct V_7 * F_146 ( struct V_4 * V_5 , int V_240 ,
bool V_3 )
{
struct V_7 * V_8 ;
if ( V_3 )
F_8 ( V_5 ) ;
else
F_5 ( V_5 ) ;
if ( V_240 != V_76 )
V_8 = F_147 ( & V_5 -> V_231 , V_240 ) ;
else
V_8 = & V_5 -> V_228 ;
if ( ! V_8 ) {
if ( ! V_3 )
return F_108 ( - V_238 ) ;
V_8 = F_117 ( V_5 , V_240 ) ;
F_148 ( & V_5 -> V_231 , V_8 ) ;
F_145 ( & V_8 -> V_215 , V_239 , V_8 -> V_199 ,
& V_5 -> V_235 -> V_236 [ V_8 -> V_199 ] ) ;
}
F_14 ( L_18 , V_95 , V_5 , V_240 , V_8 ) ;
return V_8 ;
}
static void F_138 ( struct V_7 * V_8 , struct V_37 * V_88 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_88 -> V_227 || V_88 -> V_92 ) ;
F_14 ( L_19 , V_95 , V_8 , V_8 -> V_199 ,
V_88 , V_88 -> V_227 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_149 ( & V_8 -> V_9 -> V_241 ) ;
F_120 ( V_8 ) ;
F_150 ( & V_8 -> V_202 , V_88 ) ;
V_88 -> V_92 = V_8 ;
}
static void F_137 ( struct V_7 * V_8 , struct V_37 * V_88 )
{
F_9 ( V_8 ) ;
F_6 ( V_88 -> V_92 != V_8 ) ;
F_14 ( L_19 , V_95 , V_8 , V_8 -> V_199 ,
V_88 , V_88 -> V_227 ) ;
V_88 -> V_92 = NULL ;
F_151 ( & V_8 -> V_202 , V_88 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_152 ( & V_8 -> V_9 -> V_241 ) ;
}
static bool F_153 ( struct V_242 * V_243 )
{
return V_243 -> V_84 & V_244 ;
}
static bool F_154 ( struct V_4 * V_5 )
{
struct V_225 * V_226 ;
for ( V_226 = F_134 ( & V_5 -> V_235 -> V_245 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_242 * V_243 =
F_135 ( V_226 , struct V_242 , V_229 ) ;
if ( F_153 ( V_243 ) )
return true ;
}
return false ;
}
static bool F_155 ( struct V_4 * V_5 , T_8 V_194 )
{
struct V_242 * V_243 ;
V_243 = F_156 ( V_5 -> V_235 , V_194 ) ;
if ( ! V_243 )
return false ;
return F_153 ( V_243 ) ;
}
static bool F_157 ( struct V_4 * V_5 ,
const struct V_66 * V_67 ,
struct V_242 * V_243 )
{
bool V_246 = F_158 ( V_5 , V_247 ) ;
bool V_248 = F_158 ( V_5 , V_249 ) ||
F_158 ( V_5 , V_250 ) ||
F_153 ( V_243 ) ;
F_6 ( V_243 -> V_251 != V_67 -> V_71 . V_193 ) ;
return ( ( V_67 -> V_84 & V_252 ) && V_246 ) ||
( ( V_67 -> V_84 & V_197 ) && V_248 ) ||
( V_5 -> V_235 -> V_86 < V_5 -> V_253 ) ;
}
static enum V_254 F_159 ( struct V_4 * V_5 ,
struct V_66 * V_67 ,
struct V_255 * V_256 ,
bool V_257 )
{
struct V_242 * V_243 ;
struct V_258 V_79 , V_259 ;
struct V_260 V_73 , V_72 ;
bool V_261 = false ;
bool V_262 = false ;
bool V_263 ;
bool V_264 = false ;
bool V_83 = F_158 ( V_5 , V_265 ) ;
bool V_266 = F_158 ( V_5 ,
V_267 ) ;
enum V_254 V_268 ;
int V_269 ;
V_67 -> V_86 = V_5 -> V_235 -> V_86 ;
V_243 = F_156 ( V_5 -> V_235 , V_67 -> V_69 . V_193 ) ;
if ( ! V_243 ) {
V_67 -> V_8 = V_76 ;
V_268 = V_270 ;
goto V_271;
}
if ( V_5 -> V_235 -> V_86 == V_243 -> V_272 ) {
if ( V_67 -> V_87 < V_243 -> V_272 ) {
V_67 -> V_87 = V_243 -> V_272 ;
V_261 = true ;
} else if ( V_67 -> V_87 == 0 ) {
V_261 = true ;
}
}
F_43 ( & V_67 -> V_70 , & V_67 -> V_68 ) ;
F_44 ( & V_67 -> V_71 , & V_67 -> V_69 ) ;
if ( ( V_67 -> V_84 & V_273 ) == 0 ) {
if ( V_67 -> V_84 & V_252 && V_243 -> V_274 >= 0 )
V_67 -> V_71 . V_193 = V_243 -> V_274 ;
if ( V_67 -> V_84 & V_197 && V_243 -> V_275 >= 0 )
V_67 -> V_71 . V_193 = V_243 -> V_275 ;
V_243 = F_156 ( V_5 -> V_235 , V_67 -> V_71 . V_193 ) ;
if ( ! V_243 ) {
V_67 -> V_8 = V_76 ;
V_268 = V_270 ;
goto V_271;
}
}
V_269 = F_160 ( V_243 , & V_67 -> V_70 , & V_67 -> V_71 ,
& V_79 ) ;
if ( V_269 ) {
F_6 ( V_269 != - V_276 ) ;
V_67 -> V_8 = V_76 ;
V_268 = V_270 ;
goto V_271;
}
V_259 . V_193 = V_79 . V_193 ;
V_259 . V_277 = F_161 ( V_79 . V_277 , V_67 -> V_81 , V_67 -> V_82 ) ;
F_162 ( V_5 -> V_235 , V_243 , & V_79 , & V_73 , & V_72 ) ;
if ( V_257 &&
F_163 ( & V_67 -> V_72 ,
& V_72 ,
& V_67 -> V_73 ,
& V_73 ,
V_67 -> V_74 ,
V_243 -> V_74 ,
V_67 -> V_75 ,
V_243 -> V_75 ,
V_67 -> V_81 ,
V_243 -> V_81 ,
V_67 -> V_83 ,
V_83 ,
V_67 -> V_266 ,
V_266 ,
& V_259 ) )
V_261 = true ;
if ( V_67 -> V_85 && ! F_157 ( V_5 , V_67 , V_243 ) ) {
V_67 -> V_85 = false ;
V_262 = true ;
}
V_263 = F_164 ( & V_67 -> V_79 , & V_79 ) ||
F_165 ( & V_67 -> V_72 , & V_72 , V_257 ) ;
if ( V_67 -> V_81 )
V_264 = F_166 ( & V_259 , V_67 -> V_81 , V_243 -> V_81 ) ;
if ( V_263 || V_261 || V_264 ) {
V_67 -> V_79 = V_79 ;
F_167 ( V_5 -> V_235 , V_243 , & V_79 , & V_67 -> V_80 ) ;
F_45 ( & V_67 -> V_72 , & V_72 ) ;
F_45 ( & V_67 -> V_73 , & V_73 ) ;
V_67 -> V_74 = V_243 -> V_74 ;
V_67 -> V_75 = V_243 -> V_75 ;
V_67 -> V_81 = V_243 -> V_81 ;
V_67 -> V_82 = V_243 -> V_82 ;
V_67 -> V_83 = V_83 ;
V_67 -> V_266 = V_266 ;
V_67 -> V_8 = V_72 . V_278 ;
}
if ( V_262 || V_263 || V_261 ||
( V_264 && V_256 && F_168 ( V_256 -> V_279 ,
V_280 ) ) )
V_268 = V_281 ;
else
V_268 = V_282 ;
V_271:
F_14 ( L_20 , V_95 , V_67 , V_268 , V_67 -> V_8 ) ;
return V_268 ;
}
static struct V_283 * F_169 ( void )
{
struct V_283 * V_284 ;
V_284 = F_73 ( sizeof( * V_284 ) , V_213 ) ;
if ( ! V_284 )
return NULL ;
F_67 ( & V_284 -> V_229 ) ;
V_284 -> V_285 = V_203 ;
return V_284 ;
}
static void F_170 ( struct V_283 * V_284 )
{
F_6 ( ! F_50 ( & V_284 -> V_229 ) ) ;
F_6 ( ! F_115 ( & V_284 -> V_285 ) ) ;
F_58 ( V_284 ) ;
}
static T_1 F_171 ( const struct V_286 * V_287 )
{
return V_287 -> V_288 ? 0x100000000ull : V_287 -> V_289 ;
}
static void F_172 ( const struct V_286 * V_287 ,
void * * V_290 , T_3 * V_291 )
{
if ( V_287 -> V_292 ) {
* V_290 = V_287 -> V_293 ;
* V_291 = V_287 -> V_292 ;
} else {
* V_290 = V_287 -> V_294 ;
* V_291 = V_287 -> V_295 ;
}
}
static int F_173 ( const void * V_296 , T_3 V_297 ,
const void * V_298 , T_3 V_299 )
{
int V_269 ;
V_269 = memcmp ( V_296 , V_298 , F_174 ( V_297 , V_299 ) ) ;
if ( ! V_269 ) {
if ( V_297 < V_299 )
V_269 = - 1 ;
else if ( V_297 > V_299 )
V_269 = 1 ;
}
return V_269 ;
}
static int F_175 ( const struct V_286 * V_300 ,
const struct V_286 * V_301 )
{
void * V_302 , * V_303 ;
T_3 V_304 , V_305 ;
int V_269 ;
if ( V_300 -> V_288 < V_301 -> V_288 )
return - 1 ;
if ( V_300 -> V_288 > V_301 -> V_288 )
return 1 ;
if ( V_300 -> V_193 < V_301 -> V_193 )
return - 1 ;
if ( V_300 -> V_193 > V_301 -> V_193 )
return 1 ;
if ( F_171 ( V_300 ) < F_171 ( V_301 ) )
return - 1 ;
if ( F_171 ( V_300 ) > F_171 ( V_301 ) )
return 1 ;
V_269 = F_173 ( V_300 -> V_306 , V_300 -> V_307 ,
V_301 -> V_306 , V_301 -> V_307 ) ;
if ( V_269 )
return V_269 ;
F_172 ( V_300 , & V_302 , & V_304 ) ;
F_172 ( V_301 , & V_303 , & V_305 ) ;
V_269 = F_173 ( V_302 , V_304 ,
V_303 , V_305 ) ;
if ( V_269 )
return V_269 ;
V_269 = F_173 ( V_300 -> V_294 , V_300 -> V_295 , V_301 -> V_294 , V_301 -> V_295 ) ;
if ( V_269 )
return V_269 ;
if ( V_300 -> V_108 < V_301 -> V_108 )
return - 1 ;
if ( V_300 -> V_108 > V_301 -> V_108 )
return 1 ;
return 0 ;
}
static int F_176 ( void * * V_308 , void * V_309 , struct V_286 * V_287 )
{
T_7 V_310 ;
T_2 V_311 ;
int V_269 ;
V_269 = F_177 ( V_308 , V_309 , 4 , L_21 , & V_310 ,
& V_311 ) ;
if ( V_269 )
return V_269 ;
if ( V_310 < 4 ) {
F_100 ( L_22 , V_310 ) ;
goto V_312;
}
V_287 -> V_293 = F_178 ( V_308 , V_309 , & V_287 -> V_292 ,
V_213 ) ;
if ( F_179 ( V_287 -> V_293 ) ) {
V_269 = F_180 ( V_287 -> V_293 ) ;
V_287 -> V_293 = NULL ;
return V_269 ;
}
V_287 -> V_294 = F_178 ( V_308 , V_309 , & V_287 -> V_295 ,
V_213 ) ;
if ( F_179 ( V_287 -> V_294 ) ) {
V_269 = F_180 ( V_287 -> V_294 ) ;
V_287 -> V_294 = NULL ;
return V_269 ;
}
F_181 ( V_308 , V_309 , V_287 -> V_108 , V_312 ) ;
F_182 ( V_308 , V_309 , V_287 -> V_313 , V_312 ) ;
F_183 ( V_308 , V_309 , V_287 -> V_288 , V_312 ) ;
V_287 -> V_306 = F_178 ( V_308 , V_309 , & V_287 -> V_307 ,
V_213 ) ;
if ( F_179 ( V_287 -> V_306 ) ) {
V_269 = F_180 ( V_287 -> V_306 ) ;
V_287 -> V_306 = NULL ;
return V_269 ;
}
F_181 ( V_308 , V_309 , V_287 -> V_193 , V_312 ) ;
F_184 ( V_287 ) ;
return 0 ;
V_312:
return - V_314 ;
}
static int F_185 ( const struct V_286 * V_287 )
{
return 8 + 4 + 1 + 8 +
4 + V_287 -> V_292 + 4 + V_287 -> V_295 + 4 + V_287 -> V_307 ;
}
static void F_186 ( void * * V_308 , void * V_309 , const struct V_286 * V_287 )
{
F_187 ( V_308 , 4 , 3 , F_185 ( V_287 ) ) ;
F_188 ( V_308 , V_309 , V_287 -> V_293 , V_287 -> V_292 ) ;
F_188 ( V_308 , V_309 , V_287 -> V_294 , V_287 -> V_295 ) ;
F_189 ( V_308 , V_287 -> V_108 ) ;
F_190 ( V_308 , V_287 -> V_313 ) ;
F_191 ( V_308 , V_287 -> V_288 ) ;
F_188 ( V_308 , V_309 , V_287 -> V_306 , V_287 -> V_307 ) ;
F_189 ( V_308 , V_287 -> V_193 ) ;
}
static void F_192 ( struct V_286 * V_287 )
{
if ( V_287 ) {
F_58 ( V_287 -> V_293 ) ;
F_58 ( V_287 -> V_294 ) ;
F_58 ( V_287 -> V_306 ) ;
F_58 ( V_287 ) ;
}
}
static struct V_315 * F_193 ( void )
{
struct V_315 * V_316 ;
V_316 = F_118 ( sizeof( * V_316 ) , V_213 ) ;
if ( ! V_316 )
return NULL ;
F_67 ( & V_316 -> V_317 ) ;
F_67 ( & V_316 -> V_318 ) ;
return V_316 ;
}
static void F_194 ( struct V_315 * V_316 )
{
F_6 ( ! F_50 ( & V_316 -> V_317 ) ) ;
F_6 ( ! F_50 ( & V_316 -> V_318 ) ) ;
F_192 ( V_316 -> V_319 ) ;
F_192 ( V_316 -> V_309 ) ;
F_58 ( V_316 ) ;
}
static struct V_315 * F_195 ( struct V_320 * V_321 ,
const struct V_286 * V_287 )
{
struct V_225 * V_226 = V_321 -> V_225 ;
while ( V_226 ) {
struct V_315 * V_322 =
F_135 ( V_226 , struct V_315 , V_317 ) ;
int V_323 ;
V_323 = F_175 ( V_287 , V_322 -> V_319 ) ;
if ( V_323 < 0 ) {
V_226 = V_226 -> V_324 ;
} else if ( V_323 > 0 ) {
if ( F_175 ( V_287 , V_322 -> V_309 ) < 0 )
return V_322 ;
V_226 = V_226 -> V_325 ;
} else {
return V_322 ;
}
}
return NULL ;
}
static void F_141 ( struct V_7 * V_8 )
{
while ( ! F_115 ( & V_8 -> V_205 ) ) {
struct V_283 * V_284 =
F_135 ( F_134 ( & V_8 -> V_205 ) ,
struct V_283 , V_229 ) ;
while ( ! F_115 ( & V_284 -> V_285 ) ) {
struct V_315 * V_316 =
F_135 ( F_134 ( & V_284 -> V_285 ) ,
struct V_315 , V_317 ) ;
F_196 ( & V_284 -> V_285 , V_316 ) ;
F_197 ( & V_8 -> V_206 , V_316 ) ;
F_194 ( V_316 ) ;
}
F_198 ( & V_8 -> V_205 , V_284 ) ;
F_170 ( V_284 ) ;
}
}
static void F_199 ( struct V_286 * V_287 ,
const struct V_66 * V_67 )
{
V_287 -> V_293 = NULL ;
V_287 -> V_292 = 0 ;
V_287 -> V_294 = V_67 -> V_70 . V_166 ;
V_287 -> V_295 = V_67 -> V_70 . V_135 ;
V_287 -> V_108 = V_120 ;
V_287 -> V_313 = V_67 -> V_79 . V_277 ;
V_287 -> V_288 = false ;
if ( V_67 -> V_71 . V_123 ) {
V_287 -> V_306 = V_67 -> V_71 . V_123 -> T_6 ;
V_287 -> V_307 = V_67 -> V_71 . V_123 -> V_124 ;
} else {
V_287 -> V_306 = NULL ;
V_287 -> V_307 = 0 ;
}
V_287 -> V_193 = V_67 -> V_71 . V_193 ;
F_184 ( V_287 ) ;
}
static bool F_200 ( struct V_37 * V_88 )
{
struct V_7 * V_8 = V_88 -> V_92 ;
struct V_283 * V_284 ;
struct V_315 * V_316 ;
struct V_286 V_287 ;
V_284 = F_201 ( & V_8 -> V_205 , & V_88 -> V_98 . V_80 ) ;
if ( ! V_284 )
return false ;
F_199 ( & V_287 , & V_88 -> V_98 ) ;
V_316 = F_195 ( & V_284 -> V_285 , & V_287 ) ;
if ( ! V_316 )
return false ;
F_14 ( L_23 ,
V_95 , V_88 , V_88 -> V_227 , V_8 -> V_199 , V_316 -> V_80 . V_79 . V_193 ,
V_316 -> V_80 . V_79 . V_277 , V_316 -> V_80 . V_326 , V_316 -> V_251 ) ;
return true ;
}
static void F_202 ( struct V_37 * V_88 ,
struct V_114 * V_126 )
{
T_2 V_327 = 0 ;
int V_328 ;
if ( ! F_51 ( & V_126 -> V_329 ) )
return;
F_6 ( V_126 -> V_330 ) ;
for ( V_328 = 0 ; V_328 < V_88 -> V_40 ; V_328 ++ ) {
struct V_50 * V_51 = & V_88 -> V_41 [ V_328 ] ;
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
V_327 += V_51 -> V_47 ;
}
F_6 ( V_327 != V_126 -> V_330 ) ;
}
static void F_203 ( void * * V_308 , const struct V_258 * V_79 )
{
F_191 ( V_308 , 1 ) ;
F_189 ( V_308 , V_79 -> V_193 ) ;
F_190 ( V_308 , V_79 -> V_277 ) ;
F_190 ( V_308 , - 1 ) ;
}
static void F_204 ( void * * V_308 , const struct V_331 * V_80 )
{
F_187 ( V_308 , 1 , 1 , V_131 + 1 ) ;
F_203 ( V_308 , & V_80 -> V_79 ) ;
F_191 ( V_308 , V_80 -> V_326 ) ;
}
static void F_205 ( void * * V_308 , void * V_309 ,
const struct V_121 * V_122 )
{
F_187 ( V_308 , 5 , 4 , F_75 ( V_122 ) ) ;
F_189 ( V_308 , V_122 -> V_193 ) ;
F_190 ( V_308 , - 1 ) ;
F_190 ( V_308 , 0 ) ;
if ( V_122 -> V_123 )
F_188 ( V_308 , V_309 , V_122 -> V_123 -> T_6 ,
V_122 -> V_123 -> V_124 ) ;
else
F_190 ( V_308 , 0 ) ;
}
static void F_206 ( struct V_37 * V_88 ,
struct V_114 * V_126 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_309 = V_308 + V_126 -> V_332 ;
T_2 V_327 = 0 ;
int V_328 ;
if ( V_88 -> V_192 & V_197 ) {
F_6 ( V_88 -> V_109 != V_120 ) ;
} else {
F_6 ( V_88 -> V_333 . V_334 || V_88 -> V_333 . V_335 ||
V_88 -> V_198 || V_88 -> V_99 ) ;
}
F_202 ( V_88 , V_126 ) ;
F_204 ( & V_308 , & V_88 -> V_98 . V_80 ) ;
F_190 ( & V_308 , V_88 -> V_98 . V_79 . V_277 ) ;
F_190 ( & V_308 , V_88 -> V_101 -> V_235 -> V_86 ) ;
F_190 ( & V_308 , V_88 -> V_192 ) ;
F_187 ( & V_308 , 2 , 2 , sizeof( struct V_132 ) ) ;
memset ( V_308 , 0 , sizeof( struct V_132 ) ) ;
V_308 += sizeof( struct V_132 ) ;
memset ( V_308 , 0 , sizeof( struct V_133 ) ) ;
V_308 += sizeof( struct V_133 ) ;
F_190 ( & V_308 , 0 ) ;
F_207 ( V_308 , & V_88 -> V_333 ) ;
V_308 += sizeof( struct V_134 ) ;
F_205 ( & V_308 , V_309 , & V_88 -> V_98 . V_71 ) ;
F_188 ( & V_308 , V_309 , V_88 -> V_98 . V_70 . V_166 ,
V_88 -> V_98 . V_70 . V_135 ) ;
F_208 ( & V_308 , V_88 -> V_40 ) ;
for ( V_328 = 0 ; V_328 < V_88 -> V_40 ; V_328 ++ ) {
V_327 += F_99 ( V_308 , & V_88 -> V_41 [ V_328 ] ) ;
V_308 += sizeof( struct V_136 ) ;
}
F_189 ( & V_308 , V_88 -> V_109 ) ;
if ( V_88 -> V_99 ) {
F_189 ( & V_308 , V_88 -> V_99 -> V_336 ) ;
F_190 ( & V_308 , V_88 -> V_99 -> V_137 ) ;
for ( V_328 = 0 ; V_328 < V_88 -> V_99 -> V_137 ; V_328 ++ )
F_189 ( & V_308 , V_88 -> V_99 -> V_337 [ V_328 ] ) ;
} else {
F_189 ( & V_308 , 0 ) ;
F_190 ( & V_308 , 0 ) ;
}
F_190 ( & V_308 , V_88 -> V_338 ) ;
F_20 ( V_308 > V_309 - 8 ) ;
V_126 -> V_339 . V_340 = F_104 ( 8 ) ;
V_126 -> V_141 . V_143 = V_308 - V_126 -> V_141 . V_142 ;
V_126 -> V_339 . V_341 = F_102 ( V_126 -> V_141 . V_143 ) ;
V_126 -> V_339 . V_327 = F_102 ( V_327 ) ;
V_126 -> V_339 . V_342 = F_104 ( V_88 -> V_198 ) ;
F_14 ( L_24 , V_95 , V_88 , V_126 ,
V_88 -> V_98 . V_70 . V_166 , V_88 -> V_98 . V_70 . V_135 ) ;
}
static void F_209 ( struct V_114 * V_126 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_343 = V_308 + V_126 -> V_141 . V_143 ;
void * const V_309 = V_308 + V_126 -> V_332 ;
if ( F_168 ( V_126 -> V_256 -> V_279 , V_280 ) ) {
V_308 = V_343 ;
F_189 ( & V_308 , V_126 -> V_256 -> V_279 ) ;
} else {
struct {
char V_80 [ V_130 +
V_131 + 1 ] ;
T_9 V_313 ;
T_9 V_86 ;
T_9 V_84 ;
char V_344 [ V_130 +
sizeof( struct V_132 ) ] ;
char V_345 [ sizeof( struct V_133 ) ] ;
T_9 V_346 ;
struct V_134 V_347 ;
} V_348 V_349 ;
struct V_258 V_79 ;
void * V_122 , * V_294 , * V_350 ;
int V_351 , V_295 , V_352 ;
int V_124 ;
memcpy ( & V_349 , V_308 , sizeof( V_349 ) ) ;
V_308 += sizeof( V_349 ) ;
V_122 = V_308 ;
V_308 += V_130 ;
V_79 . V_193 = F_210 ( & V_308 ) ;
V_308 += 4 + 4 ;
V_124 = F_211 ( & V_308 ) ;
V_308 += V_124 ;
V_351 = V_308 - V_122 ;
V_294 = V_308 ;
V_124 = F_211 ( & V_308 ) ;
V_308 += V_124 ;
V_295 = V_308 - V_294 ;
V_350 = V_308 ;
V_352 = V_343 - V_308 ;
V_308 = V_126 -> V_141 . V_142 ;
F_212 ( & V_308 , & V_349 . V_346 , sizeof( V_349 . V_346 ) ) ;
F_212 ( & V_308 , & V_349 . V_86 , sizeof( V_349 . V_86 ) ) ;
F_212 ( & V_308 , & V_349 . V_84 , sizeof( V_349 . V_84 ) ) ;
F_212 ( & V_308 , & V_349 . V_347 , sizeof( V_349 . V_347 ) ) ;
memset ( V_308 , 0 , sizeof( struct V_353 ) ) ;
V_308 += sizeof( struct V_353 ) ;
F_20 ( V_308 >= V_122 ) ;
memmove ( V_308 , V_122 , V_351 ) ;
V_308 += V_351 ;
V_79 . V_277 = F_213 ( V_349 . V_313 ) ;
F_203 ( & V_308 , & V_79 ) ;
F_20 ( V_308 >= V_294 ) ;
memmove ( V_308 , V_294 , V_295 ) ;
V_308 += V_295 ;
F_20 ( V_308 >= V_350 ) ;
memmove ( V_308 , V_350 , V_352 ) ;
V_308 += V_352 ;
V_126 -> V_339 . V_340 = F_104 ( 4 ) ;
}
F_20 ( V_308 > V_309 ) ;
V_126 -> V_141 . V_143 = V_308 - V_126 -> V_141 . V_142 ;
V_126 -> V_339 . V_341 = F_102 ( V_126 -> V_141 . V_143 ) ;
F_14 ( L_25 , V_95 , V_126 ,
F_214 ( V_126 -> V_339 . V_354 ) , F_213 ( V_126 -> V_339 . V_341 ) ,
F_213 ( V_126 -> V_339 . V_355 ) , F_213 ( V_126 -> V_339 . V_327 ) ,
F_215 ( V_126 -> V_339 . V_340 ) ) ;
}
static void F_216 ( struct V_37 * V_88 )
{
struct V_7 * V_8 = V_88 -> V_92 ;
F_9 ( V_8 ) ;
F_6 ( V_8 -> V_199 != V_88 -> V_98 . V_8 ) ;
if ( F_200 ( V_88 ) )
return;
if ( V_88 -> V_356 )
F_217 ( V_88 -> V_96 ) ;
V_88 -> V_192 |= V_357 ;
if ( V_88 -> V_338 )
V_88 -> V_192 |= V_358 ;
else
F_6 ( V_88 -> V_192 & V_358 ) ;
F_206 ( V_88 , V_88 -> V_96 ) ;
F_14 ( L_26 ,
V_95 , V_88 , V_88 -> V_227 , V_88 -> V_98 . V_79 . V_193 , V_88 -> V_98 . V_79 . V_277 ,
V_88 -> V_98 . V_80 . V_79 . V_193 , V_88 -> V_98 . V_80 . V_79 . V_277 ,
V_88 -> V_98 . V_80 . V_326 , V_8 -> V_199 , V_88 -> V_98 . V_86 , V_88 -> V_192 ,
V_88 -> V_338 ) ;
V_88 -> V_98 . V_85 = false ;
V_88 -> V_237 = V_222 ;
V_88 -> V_338 ++ ;
V_88 -> V_356 = V_8 -> V_209 ;
V_88 -> V_96 -> V_339 . V_354 = F_101 ( V_88 -> V_227 ) ;
F_218 ( & V_8 -> V_215 , F_219 ( V_88 -> V_96 ) ) ;
}
static void F_220 ( struct V_4 * V_5 )
{
bool V_359 = false ;
F_5 ( V_5 ) ;
F_6 ( ! V_5 -> V_235 -> V_86 ) ;
if ( F_158 ( V_5 , V_250 ) ||
F_158 ( V_5 , V_247 ) ||
F_158 ( V_5 , V_249 ) ) {
F_14 ( L_27 , V_95 , V_5 ) ;
V_359 = true ;
} else {
F_14 ( L_28 , V_95 , V_5 ) ;
}
if ( F_221 ( & V_5 -> V_217 -> V_360 , V_361 ,
V_5 -> V_235 -> V_86 + 1 , V_359 ) )
F_222 ( & V_5 -> V_217 -> V_360 ) ;
}
static void F_223 ( struct V_37 * V_88 , bool V_3 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_7 * V_8 ;
enum V_254 V_268 ;
bool V_362 = false ;
bool V_363 = false ;
bool V_364 = false ;
F_6 ( V_88 -> V_227 ) ;
F_14 ( L_29 , V_95 , V_88 , V_3 ) ;
V_365:
V_268 = F_159 ( V_5 , & V_88 -> V_98 , NULL , false ) ;
if ( V_268 == V_270 && ! V_3 )
goto V_366;
V_8 = F_146 ( V_5 , V_88 -> V_98 . V_8 , V_3 ) ;
if ( F_179 ( V_8 ) ) {
F_6 ( F_180 ( V_8 ) != - V_238 || V_3 ) ;
goto V_366;
}
if ( V_5 -> V_235 -> V_86 < V_5 -> V_253 ) {
F_14 ( L_30 , V_88 , V_5 -> V_235 -> V_86 ,
V_5 -> V_253 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_192 & V_197 ) &&
F_158 ( V_5 , V_249 ) ) {
F_14 ( L_31 , V_88 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_192 & V_252 ) &&
F_158 ( V_5 , V_247 ) ) {
F_14 ( L_32 , V_88 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
} else if ( ( V_88 -> V_192 & V_197 ) &&
! ( V_88 -> V_192 & ( V_367 |
V_368 ) ) &&
( F_158 ( V_5 , V_250 ) ||
F_155 ( V_5 , V_88 -> V_98 . V_69 . V_193 ) ) ) {
F_14 ( L_33 , V_88 ) ;
F_224 ( L_34 ) ;
V_88 -> V_98 . V_85 = true ;
F_220 ( V_5 ) ;
if ( V_88 -> V_191 )
V_364 = true ;
} else if ( ! F_109 ( V_8 ) ) {
V_362 = true ;
} else {
F_220 ( V_5 ) ;
}
F_225 ( & V_8 -> V_6 ) ;
V_88 -> V_227 = F_226 ( & V_5 -> V_369 ) ;
F_138 ( V_8 , V_88 ) ;
if ( V_362 )
F_216 ( V_88 ) ;
else if ( V_364 )
F_227 ( V_88 , - V_370 ) ;
F_228 ( & V_8 -> V_6 ) ;
if ( V_268 == V_270 )
F_229 ( V_88 ) ;
if ( V_363 )
F_230 ( & V_5 -> V_6 ) ;
return;
V_366:
F_4 ( & V_5 -> V_6 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_3 = true ;
V_363 = true ;
goto V_365;
}
static void F_232 ( struct V_37 * V_88 )
{
F_6 ( V_88 -> V_192 & ( V_371 | V_372 ) ) ;
F_6 ( ! ( V_88 -> V_192 & ( V_252 | V_197 ) ) ) ;
V_88 -> V_192 |= V_372 ;
F_149 ( & V_88 -> V_101 -> V_373 ) ;
V_88 -> V_374 = V_222 ;
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
F_6 ( F_235 ( & V_5 -> V_375 , V_88 -> V_227 ) ) ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_227 ) ;
if ( V_88 -> V_92 )
F_137 ( V_88 -> V_92 , V_88 ) ;
F_152 ( & V_5 -> V_373 ) ;
F_217 ( V_88 -> V_96 ) ;
F_236 ( V_88 -> V_97 ) ;
}
static void F_237 ( struct V_37 * V_88 )
{
if ( V_88 -> V_376 ) {
F_14 ( L_36 , V_95 , V_88 ,
V_88 -> V_227 , V_88 -> V_376 , V_88 -> V_377 ) ;
V_88 -> V_376 ( V_88 ) ;
}
}
static void F_227 ( struct V_37 * V_88 , int V_378 )
{
F_14 ( L_37 , V_95 , V_88 , V_88 -> V_227 , V_378 ) ;
V_88 -> V_377 = V_378 ;
F_234 ( V_88 ) ;
F_237 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
}
static void F_239 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_37 * V_379 ;
F_8 ( V_5 ) ;
V_379 = F_235 ( & V_5 -> V_375 , V_88 -> V_227 ) ;
if ( ! V_379 )
return;
F_6 ( V_379 != V_88 ) ;
F_240 ( & V_5 -> V_375 , V_88 ) ;
F_62 ( V_88 ) ;
}
static void F_241 ( struct V_37 * V_88 )
{
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_227 ) ;
F_239 ( V_88 ) ;
F_234 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
}
static void F_242 ( struct V_37 * V_88 , int V_378 )
{
F_14 ( L_37 , V_95 , V_88 , V_88 -> V_227 , V_378 ) ;
F_239 ( V_88 ) ;
F_227 ( V_88 , V_378 ) ;
}
static void F_243 ( struct V_4 * V_5 , T_2 V_380 )
{
if ( F_244 ( V_380 > V_5 -> V_253 ) ) {
F_14 ( L_38 ,
V_5 -> V_253 , V_380 ) ;
V_5 -> V_253 = V_380 ;
if ( V_380 > V_5 -> V_235 -> V_86 )
F_220 ( V_5 ) ;
}
}
void F_245 ( struct V_4 * V_5 , T_2 V_380 )
{
F_246 ( & V_5 -> V_6 ) ;
if ( F_2 ( V_380 > V_5 -> V_253 ) ) {
F_4 ( & V_5 -> V_6 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_243 ( V_5 , V_380 ) ;
F_247 ( & V_5 -> V_6 ) ;
} else {
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_248 ( struct V_4 * V_5 )
{
struct V_225 * V_226 ;
bool V_381 = false ;
F_14 ( L_39 ) ;
if ( ! F_158 ( V_5 , V_250 ) && ! F_154 ( V_5 ) )
goto V_271;
for ( V_226 = F_134 ( & V_5 -> V_231 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_7 * V_8 = F_135 ( V_226 , struct V_7 , V_200 ) ;
struct V_225 * V_382 ;
V_382 = F_134 ( & V_8 -> V_202 ) ;
while ( V_382 ) {
struct V_37 * V_88 = F_135 ( V_382 ,
struct V_37 , V_89 ) ;
V_382 = F_136 ( V_382 ) ;
if ( V_88 -> V_191 ) {
V_381 = true ;
break;
}
}
if ( V_381 )
break;
}
if ( ! V_381 )
goto V_271;
F_243 ( V_5 , V_5 -> V_235 -> V_86 ) ;
for ( V_226 = F_134 ( & V_5 -> V_231 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_7 * V_8 = F_135 ( V_226 , struct V_7 , V_200 ) ;
struct V_225 * V_382 ;
V_382 = F_134 ( & V_8 -> V_202 ) ;
while ( V_382 ) {
struct V_37 * V_88 = F_135 ( V_382 ,
struct V_37 , V_89 ) ;
V_382 = F_136 ( V_382 ) ;
if ( V_88 -> V_191 &&
( F_158 ( V_5 , V_250 ) ||
F_155 ( V_5 , V_88 -> V_98 . V_71 . V_193 ) ) )
F_242 ( V_88 , - V_370 ) ;
}
}
V_271:
F_14 ( L_40 , V_5 -> V_253 ) ;
}
static void F_249 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_383 * V_384 = V_5 -> V_235 ;
F_8 ( V_5 ) ;
F_6 ( ! V_384 -> V_86 ) ;
if ( V_88 -> V_338 ) {
V_88 -> V_385 = V_384 -> V_86 ;
F_14 ( L_41 , V_95 , V_88 ,
V_88 -> V_227 ) ;
} else {
F_14 ( L_42 , V_95 ,
V_88 , V_88 -> V_227 , V_88 -> V_385 , V_384 -> V_86 ) ;
}
if ( V_88 -> V_385 ) {
if ( V_384 -> V_86 >= V_88 -> V_385 ) {
F_250 ( L_43 ,
V_88 -> V_227 ) ;
F_227 ( V_88 , - V_276 ) ;
}
} else {
F_229 ( V_88 ) ;
}
}
static void F_251 ( struct V_386 * V_387 )
{
struct V_4 * V_5 = & V_387 -> V_360 -> V_217 -> V_5 ;
struct V_37 * V_88 ;
T_1 V_354 = V_387 -> V_388 ;
F_6 ( V_387 -> V_389 || ! V_387 -> V_390 . V_391 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_88 = F_235 ( & V_5 -> V_375 , V_354 ) ;
if ( ! V_88 ) {
F_14 ( L_44 , V_95 , V_354 ) ;
goto V_392;
}
F_14 ( L_45 , V_95 ,
V_88 , V_88 -> V_227 , V_88 -> V_385 , V_387 -> V_390 . V_391 ) ;
if ( ! V_88 -> V_385 )
V_88 -> V_385 = V_387 -> V_390 . V_391 ;
F_240 ( & V_5 -> V_375 , V_88 ) ;
F_249 ( V_88 ) ;
F_62 ( V_88 ) ;
V_392:
F_247 ( & V_5 -> V_6 ) ;
}
static void F_229 ( struct V_37 * V_88 )
{
struct V_4 * V_5 = V_88 -> V_101 ;
struct V_37 * V_379 ;
int V_269 ;
F_8 ( V_5 ) ;
V_379 = F_235 ( & V_5 -> V_375 , V_88 -> V_227 ) ;
if ( V_379 ) {
F_6 ( V_379 != V_88 ) ;
return;
}
F_59 ( V_88 ) ;
F_252 ( & V_5 -> V_375 , V_88 ) ;
V_269 = F_253 ( & V_5 -> V_217 -> V_360 , L_46 ,
F_251 , V_88 -> V_227 ) ;
F_6 ( V_269 ) ;
}
static void F_254 ( struct V_93 * V_93 )
{
struct V_10 * V_11 =
F_53 ( V_93 , struct V_10 , V_93 ) ;
F_14 ( L_47 , V_95 , V_11 ,
V_11 -> V_393 , V_11 -> V_394 ) ;
F_6 ( ! F_50 ( & V_11 -> V_229 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_395 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_396 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_397 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_398 ) ) ;
F_6 ( V_11 -> V_8 ) ;
if ( V_11 -> V_393 )
F_62 ( V_11 -> V_393 ) ;
if ( V_11 -> V_394 )
F_62 ( V_11 -> V_394 ) ;
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
V_11 = F_118 ( sizeof( * V_11 ) , V_213 ) ;
if ( ! V_11 )
return NULL ;
F_65 ( & V_11 -> V_93 ) ;
F_113 ( & V_11 -> V_6 ) ;
F_67 ( & V_11 -> V_229 ) ;
F_67 ( & V_11 -> V_395 ) ;
F_67 ( & V_11 -> V_396 ) ;
F_68 ( & V_11 -> V_397 ) ;
F_68 ( & V_11 -> V_398 ) ;
F_66 ( & V_11 -> V_399 ) ;
F_66 ( & V_11 -> V_400 ) ;
V_11 -> V_5 = V_5 ;
F_38 ( & V_11 -> V_67 ) ;
F_14 ( L_48 , V_95 , V_11 ) ;
return V_11 ;
}
static void F_140 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_11 -> V_230 || V_11 -> V_8 ) ;
F_14 ( L_49 , V_95 , V_8 ,
V_8 -> V_199 , V_11 , V_11 -> V_230 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_149 ( & V_8 -> V_9 -> V_241 ) ;
F_120 ( V_8 ) ;
F_258 ( & V_8 -> V_204 , V_11 ) ;
V_11 -> V_8 = V_8 ;
}
static void F_139 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( V_11 -> V_8 != V_8 ) ;
F_14 ( L_49 , V_95 , V_8 ,
V_8 -> V_199 , V_11 , V_11 -> V_230 ) ;
V_11 -> V_8 = NULL ;
F_259 ( & V_8 -> V_204 , V_11 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_152 ( & V_8 -> V_9 -> V_241 ) ;
}
static bool F_260 ( struct V_10 * V_11 )
{
F_5 ( V_11 -> V_5 ) ;
return ! F_50 ( & V_11 -> V_395 ) ;
}
static bool F_261 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
bool V_401 ;
F_246 ( & V_5 -> V_6 ) ;
V_401 = F_260 ( V_11 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_401 ;
}
static void F_262 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_6 ( V_11 -> V_230 ) ;
F_256 ( V_11 ) ;
V_11 -> V_230 = ++ V_5 -> V_402 ;
F_263 ( & V_5 -> V_403 , V_11 ) ;
}
static void F_264 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_265 ( & V_5 -> V_403 , V_11 ) ;
F_255 ( V_11 ) ;
}
static void F_266 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_404 ;
F_6 ( ! V_88 -> V_113 ) ;
F_241 ( V_88 ) ;
F_255 ( V_11 ) ;
}
static struct V_405 * F_267 ( struct V_10 * V_11 ,
T_10 V_406 )
{
struct V_405 * V_407 ;
V_407 = F_118 ( sizeof( * V_407 ) , V_213 ) ;
if ( ! V_407 )
return NULL ;
F_268 ( & V_407 -> V_408 , V_406 ) ;
F_68 ( & V_407 -> V_409 ) ;
V_407 -> V_11 = F_256 ( V_11 ) ;
return V_407 ;
}
static void F_269 ( struct V_405 * V_407 )
{
struct V_10 * V_11 = V_407 -> V_11 ;
F_225 ( & V_11 -> V_6 ) ;
F_270 ( & V_407 -> V_409 ) ;
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
F_58 ( V_407 ) ;
}
static void F_271 ( struct V_405 * V_407 )
{
struct V_10 * V_11 = V_407 -> V_11 ;
struct V_4 * V_5 = V_11 -> V_5 ;
F_11 ( V_11 ) ;
F_6 ( ! F_51 ( & V_407 -> V_409 ) ) ;
V_407 -> V_410 = V_222 ;
F_127 ( & V_407 -> V_409 , & V_11 -> V_398 ) ;
F_272 ( V_5 -> V_411 , & V_407 -> V_408 ) ;
}
static void F_273 ( struct V_412 * V_413 )
{
struct V_405 * V_407 = F_53 ( V_413 , struct V_405 , V_408 ) ;
struct V_10 * V_11 = V_407 -> V_11 ;
if ( ! F_261 ( V_11 ) ) {
F_14 ( L_50 , V_95 , V_11 ) ;
goto V_271;
}
F_6 ( ! V_11 -> V_414 ) ;
F_14 ( L_51 ,
V_95 , V_11 , V_407 -> V_63 . V_415 , V_407 -> V_63 . V_416 ,
V_407 -> V_63 . V_151 ) ;
V_11 -> V_417 ( V_11 -> V_329 , V_407 -> V_63 . V_415 , V_11 -> V_230 ,
V_407 -> V_63 . V_416 , V_407 -> V_63 . V_418 ,
V_407 -> V_63 . V_151 ) ;
V_271:
F_54 ( V_407 -> V_63 . V_126 ) ;
F_269 ( V_407 ) ;
}
static void F_274 ( struct V_412 * V_413 )
{
struct V_405 * V_407 = F_53 ( V_413 , struct V_405 , V_408 ) ;
struct V_10 * V_11 = V_407 -> V_11 ;
if ( ! F_261 ( V_11 ) ) {
F_14 ( L_50 , V_95 , V_11 ) ;
goto V_271;
}
F_14 ( L_52 , V_95 , V_11 , V_407 -> error . V_378 ) ;
V_11 -> V_419 ( V_11 -> V_329 , V_11 -> V_230 , V_407 -> error . V_378 ) ;
V_271:
F_269 ( V_407 ) ;
}
static void F_275 ( struct V_10 * V_11 )
{
struct V_405 * V_407 ;
V_407 = F_267 ( V_11 , F_274 ) ;
if ( ! V_407 ) {
F_100 ( L_53 ) ;
return;
}
V_407 -> error . V_378 = V_11 -> V_420 ;
F_271 ( V_407 ) ;
}
static void F_276 ( struct V_10 * V_11 ,
int V_389 )
{
if ( ! F_277 ( & V_11 -> V_399 ) ) {
V_11 -> V_421 = ( V_389 <= 0 ? V_389 : 0 ) ;
F_238 ( & V_11 -> V_399 ) ;
}
}
static void F_278 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_404 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_54 , V_95 , V_11 ,
V_11 -> V_230 , V_88 -> V_377 ) ;
F_276 ( V_11 , V_88 -> V_377 ) ;
V_11 -> V_422 = true ;
if ( ! V_11 -> V_414 ) {
struct V_21 * V_22 =
F_22 ( V_88 , 0 , V_63 , V_48 ) ;
void * V_308 = F_279 ( V_22 -> V_25 [ 0 ] ) ;
F_6 ( V_88 -> V_41 [ 0 ] . V_51 != V_62 ||
V_22 -> type != V_30 ) ;
if ( V_88 -> V_41 [ 0 ] . V_157 >= sizeof( T_1 ) ) {
V_11 -> V_415 = F_210 ( & V_308 ) ;
F_14 ( L_55 , V_11 ,
V_11 -> V_415 ) ;
} else {
F_14 ( L_56 , V_11 ) ;
}
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static int F_280 ( int V_378 )
{
if ( V_378 == - V_276 )
V_378 = - V_423 ;
return V_378 ;
}
static void F_281 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_404 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_57 , V_95 ,
V_11 , V_11 -> V_230 , V_88 -> V_377 , V_11 -> V_420 ) ;
if ( V_88 -> V_377 < 0 ) {
if ( ! V_11 -> V_420 ) {
V_11 -> V_420 = F_280 ( V_88 -> V_377 ) ;
F_275 ( V_11 ) ;
}
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static void F_282 ( struct V_10 * V_11 )
{
struct V_37 * V_88 = V_11 -> V_393 ;
struct V_50 * V_51 = & V_88 -> V_41 [ 0 ] ;
F_8 ( V_88 -> V_101 ) ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_230 ) ;
if ( V_88 -> V_92 )
F_266 ( V_88 ) ;
F_69 ( V_88 ) ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
V_88 -> V_192 = V_11 -> V_67 . V_84 ;
V_88 -> V_333 = V_11 -> V_347 ;
F_225 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_414 && V_11 -> V_422 ) {
F_6 ( V_51 -> V_51 != V_173 ||
V_51 -> V_174 . V_171 != V_11 -> V_230 ) ;
V_51 -> V_174 . V_51 = V_424 ;
V_51 -> V_174 . V_175 = ++ V_11 -> V_425 ;
F_14 ( L_59 , V_11 ,
V_51 -> V_174 . V_175 ) ;
V_88 -> V_376 = F_281 ;
} else {
if ( ! V_11 -> V_414 )
V_11 -> V_415 = 0 ;
else
F_6 ( V_51 -> V_174 . V_51 != V_426 ) ;
F_14 ( L_60 , V_11 ) ;
V_88 -> V_376 = F_278 ;
}
F_228 ( & V_11 -> V_6 ) ;
V_88 -> V_404 = F_256 ( V_11 ) ;
V_88 -> V_113 = true ;
F_233 ( V_88 , true ) ;
}
static void F_283 ( struct V_37 * V_88 )
{
struct V_10 * V_11 = V_88 -> V_404 ;
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_61 ,
V_95 , V_11 , V_11 -> V_230 , V_88 -> V_377 , V_11 -> V_427 ,
V_11 -> V_420 ) ;
if ( V_11 -> V_425 == V_88 -> V_41 [ 0 ] . V_174 . V_175 ) {
if ( ! V_88 -> V_377 ) {
V_11 -> V_428 = V_11 -> V_427 ;
} else if ( ! V_11 -> V_420 ) {
V_11 -> V_420 = F_280 ( V_88 -> V_377 ) ;
F_275 ( V_11 ) ;
}
} else {
F_14 ( L_62 , V_11 ,
V_11 -> V_425 , V_88 -> V_41 [ 0 ] . V_174 . V_175 ) ;
}
F_228 ( & V_11 -> V_6 ) ;
F_255 ( V_11 ) ;
}
static void F_284 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_37 * V_88 = V_11 -> V_394 ;
struct V_50 * V_51 = & V_88 -> V_41 [ 0 ] ;
if ( F_158 ( V_5 , V_247 ) ) {
F_14 ( L_63 , V_95 ) ;
return;
}
V_11 -> V_427 = V_222 ;
F_14 ( L_64 ,
V_95 , V_11 , V_11 -> V_230 , V_11 -> V_427 ,
V_11 -> V_425 ) ;
if ( V_88 -> V_92 )
F_266 ( V_88 ) ;
F_69 ( V_88 ) ;
F_42 ( & V_88 -> V_98 , & V_11 -> V_67 ) ;
F_6 ( V_51 -> V_51 != V_173 ||
V_51 -> V_174 . V_171 != V_11 -> V_230 ||
V_51 -> V_174 . V_51 != V_429 ) ;
V_51 -> V_174 . V_175 = V_11 -> V_425 ;
V_88 -> V_376 = F_283 ;
V_88 -> V_404 = F_256 ( V_11 ) ;
V_88 -> V_113 = true ;
F_59 ( V_88 ) ;
F_232 ( V_88 ) ;
V_88 -> V_227 = F_226 ( & V_5 -> V_369 ) ;
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
struct V_10 * V_430 ;
F_8 ( V_5 ) ;
V_430 = F_287 ( & V_5 -> V_431 ,
V_11 -> V_230 ) ;
if ( ! V_430 )
return;
F_6 ( V_430 != V_11 ) ;
F_288 ( & V_5 -> V_431 , V_11 ) ;
F_255 ( V_11 ) ;
}
static void F_289 ( struct V_10 * V_11 )
{
if ( V_11 -> V_414 && V_11 -> V_394 -> V_92 )
F_266 ( V_11 -> V_394 ) ;
if ( V_11 -> V_393 -> V_92 )
F_266 ( V_11 -> V_393 ) ;
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
struct V_383 * V_384 = V_5 -> V_235 ;
F_8 ( V_5 ) ;
F_6 ( ! V_384 -> V_86 ) ;
if ( V_11 -> V_425 ) {
V_11 -> V_432 = V_384 -> V_86 ;
F_14 ( L_65 , V_95 ,
V_11 , V_11 -> V_230 ) ;
} else {
F_14 ( L_66 ,
V_95 , V_11 , V_11 -> V_230 , V_11 -> V_432 ,
V_384 -> V_86 ) ;
}
if ( V_11 -> V_432 ) {
if ( V_384 -> V_86 >= V_11 -> V_432 ) {
F_292 ( L_67 ,
V_11 -> V_230 ) ;
F_276 ( V_11 , - V_276 ) ;
F_289 ( V_11 ) ;
}
} else {
F_293 ( V_11 ) ;
}
}
static void F_294 ( struct V_386 * V_387 )
{
struct V_4 * V_5 = & V_387 -> V_360 -> V_217 -> V_5 ;
struct V_10 * V_11 ;
T_1 V_230 = V_387 -> V_388 ;
F_6 ( V_387 -> V_389 || ! V_387 -> V_390 . V_391 ) ;
F_231 ( & V_5 -> V_6 ) ;
V_11 = F_287 ( & V_5 -> V_431 , V_230 ) ;
if ( ! V_11 ) {
F_14 ( L_68 , V_95 , V_230 ) ;
goto V_392;
}
F_14 ( L_69 ,
V_95 , V_11 , V_11 -> V_230 , V_11 -> V_432 ,
V_387 -> V_390 . V_391 ) ;
if ( ! V_11 -> V_432 )
V_11 -> V_432 = V_387 -> V_390 . V_391 ;
F_288 ( & V_5 -> V_431 , V_11 ) ;
F_291 ( V_11 ) ;
F_255 ( V_11 ) ;
V_392:
F_247 ( & V_5 -> V_6 ) ;
}
static void F_293 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_10 * V_430 ;
int V_269 ;
F_8 ( V_5 ) ;
V_430 = F_287 ( & V_5 -> V_431 ,
V_11 -> V_230 ) ;
if ( V_430 ) {
F_6 ( V_430 != V_11 ) ;
return;
}
F_256 ( V_11 ) ;
F_295 ( & V_5 -> V_431 , V_11 ) ;
V_269 = F_253 ( & V_5 -> V_217 -> V_360 , L_46 ,
F_294 , V_11 -> V_230 ) ;
F_6 ( V_269 ) ;
}
static int F_296 ( struct V_10 * V_11 )
{
int V_269 ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_230 ) ;
V_269 = F_297 ( & V_11 -> V_399 ) ;
return V_269 ? : V_11 -> V_421 ;
}
static int F_298 ( struct V_10 * V_11 )
{
int V_269 ;
F_14 ( L_58 , V_95 , V_11 , V_11 -> V_230 ) ;
V_269 = F_297 ( & V_11 -> V_400 ) ;
return V_269 ? : V_11 -> V_433 ;
}
static void F_299 ( struct V_412 * V_408 )
{
struct V_4 * V_5 =
F_53 ( V_408 , struct V_4 , V_434 . V_408 ) ;
struct V_435 * V_436 = V_5 -> V_217 -> V_223 ;
unsigned long V_437 = V_222 - V_436 -> V_438 ;
unsigned long V_439 = V_222 - V_436 -> V_440 ;
F_300 ( V_441 ) ;
struct V_225 * V_226 , * V_308 ;
F_14 ( L_70 , V_95 , V_5 ) ;
F_231 ( & V_5 -> V_6 ) ;
for ( V_226 = F_134 ( & V_5 -> V_231 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_7 * V_8 = F_135 ( V_226 , struct V_7 , V_200 ) ;
bool V_442 = false ;
for ( V_308 = F_134 ( & V_8 -> V_202 ) ; V_308 ; ) {
struct V_37 * V_88 =
F_135 ( V_308 , struct V_37 , V_89 ) ;
V_308 = F_136 ( V_308 ) ;
if ( F_301 ( V_88 -> V_237 , V_437 ) ) {
F_14 ( L_71 ,
V_88 , V_88 -> V_227 , V_8 -> V_199 ) ;
V_442 = true ;
}
if ( V_436 -> V_440 &&
F_301 ( V_88 -> V_374 , V_439 ) ) {
F_302 ( L_72 ,
V_88 -> V_227 , V_8 -> V_199 ) ;
F_242 ( V_88 , - V_443 ) ;
}
}
for ( V_308 = F_134 ( & V_8 -> V_204 ) ; V_308 ; V_308 = F_136 ( V_308 ) ) {
struct V_10 * V_11 =
F_135 ( V_308 , struct V_10 , V_229 ) ;
F_14 ( L_73 ,
V_11 , V_11 -> V_230 , V_8 -> V_199 ) ;
V_442 = true ;
F_225 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_414 && V_11 -> V_422 && ! V_11 -> V_420 )
F_284 ( V_11 ) ;
F_228 ( & V_11 -> V_6 ) ;
}
if ( V_442 )
F_303 ( & V_8 -> V_208 , & V_441 ) ;
}
if ( V_436 -> V_440 ) {
for ( V_308 = F_134 ( & V_5 -> V_228 . V_202 ) ; V_308 ; ) {
struct V_37 * V_88 =
F_135 ( V_308 , struct V_37 , V_89 ) ;
V_308 = F_136 ( V_308 ) ;
if ( F_301 ( V_88 -> V_374 , V_439 ) ) {
F_302 ( L_72 ,
V_88 -> V_227 , V_5 -> V_228 . V_199 ) ;
F_242 ( V_88 , - V_443 ) ;
}
}
}
if ( F_304 ( & V_5 -> V_241 ) || ! F_51 ( & V_441 ) )
F_220 ( V_5 ) ;
while ( ! F_51 ( & V_441 ) ) {
struct V_7 * V_8 = F_305 ( & V_441 ,
struct V_7 ,
V_208 ) ;
F_131 ( & V_8 -> V_208 ) ;
F_306 ( & V_8 -> V_215 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_307 ( & V_5 -> V_434 ,
V_5 -> V_217 -> V_223 -> V_438 ) ;
}
static void F_308 ( struct V_412 * V_408 )
{
struct V_4 * V_5 =
F_53 ( V_408 , struct V_4 ,
V_444 . V_408 ) ;
unsigned long V_445 = V_5 -> V_217 -> V_223 -> V_224 / 4 ;
struct V_7 * V_8 , * V_446 ;
F_14 ( L_70 , V_95 , V_5 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_309 (osd, nosd, &osdc->osd_lru, o_osd_lru) {
if ( F_301 ( V_222 , V_8 -> V_221 ) )
break;
F_6 ( ! F_115 ( & V_8 -> V_202 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_204 ) ) ;
F_132 ( V_8 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_307 ( & V_5 -> V_444 ,
F_310 ( V_445 ) ) ;
}
static int F_311 ( void * * V_308 , void * V_309 ,
struct V_121 * V_122 )
{
T_7 V_310 , V_447 ;
T_2 V_124 ;
void * V_448 ;
int V_269 = 0 ;
F_312 ( V_308 , V_309 , 1 + 1 + 4 , V_312 ) ;
V_310 = F_313 ( V_308 ) ;
V_447 = F_313 ( V_308 ) ;
if ( V_310 < 3 ) {
F_314 ( L_74 ,
V_310 , V_447 ) ;
goto V_312;
}
if ( V_447 > 6 ) {
F_314 ( L_75 ,
V_310 , V_447 ) ;
goto V_312;
}
V_124 = F_211 ( V_308 ) ;
F_312 ( V_308 , V_309 , V_124 , V_312 ) ;
V_448 = * V_308 + V_124 ;
V_122 -> V_193 = F_210 ( V_308 ) ;
* V_308 += 4 ;
V_124 = F_211 ( V_308 ) ;
if ( V_124 > 0 ) {
F_314 ( L_76 ) ;
goto V_312;
}
if ( V_310 >= 5 ) {
bool V_449 = false ;
V_124 = F_211 ( V_308 ) ;
if ( V_124 > 0 ) {
F_312 ( V_308 , V_309 , V_124 , V_312 ) ;
if ( ! V_122 -> V_123 ||
F_315 ( V_122 -> V_123 , * V_308 , V_124 ) )
V_449 = true ;
* V_308 += V_124 ;
} else {
if ( V_122 -> V_123 )
V_449 = true ;
}
if ( V_449 ) {
F_314 ( L_77 ) ;
goto V_312;
}
}
if ( V_310 >= 6 ) {
T_8 V_313 = F_210 ( V_308 ) ;
if ( V_313 != - 1 ) {
F_314 ( L_78 ) ;
goto V_312;
}
}
* V_308 = V_448 ;
V_271:
return V_269 ;
V_312:
V_269 = - V_314 ;
goto V_271;
}
static int F_316 ( void * * V_308 , void * V_309 ,
struct V_450 * V_451 )
{
T_7 V_310 , V_447 ;
T_2 V_124 ;
void * V_448 ;
int V_269 ;
F_312 ( V_308 , V_309 , 1 + 1 + 4 , V_312 ) ;
V_310 = F_313 ( V_308 ) ;
V_447 = F_313 ( V_308 ) ;
if ( V_447 > 1 ) {
F_314 ( L_79 ,
V_310 , V_447 ) ;
goto V_312;
}
V_124 = F_211 ( V_308 ) ;
F_312 ( V_308 , V_309 , V_124 , V_312 ) ;
V_448 = * V_308 + V_124 ;
V_269 = F_311 ( V_308 , V_309 , & V_451 -> V_122 ) ;
if ( V_269 )
goto V_271;
V_124 = F_211 ( V_308 ) ;
if ( V_124 > 0 ) {
F_314 ( L_80 ) ;
goto V_312;
}
V_124 = F_211 ( V_308 ) ;
* V_308 += V_124 ;
* V_308 = V_448 ;
V_271:
return V_269 ;
V_312:
V_269 = - V_314 ;
goto V_271;
}
static int F_317 ( const struct V_114 * V_126 , struct V_452 * V_382 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_309 = V_308 + V_126 -> V_141 . V_143 ;
T_5 V_340 = F_215 ( V_126 -> V_339 . V_340 ) ;
struct V_353 V_453 ;
T_7 V_454 ;
T_2 V_124 ;
int V_269 ;
int V_328 ;
F_182 ( & V_308 , V_309 , V_124 , V_312 ) ;
F_312 ( & V_308 , V_309 , V_124 , V_312 ) ;
V_308 += V_124 ;
V_269 = F_318 ( & V_308 , V_309 , & V_382 -> V_79 ) ;
if ( V_269 )
return V_269 ;
F_181 ( & V_308 , V_309 , V_382 -> V_84 , V_312 ) ;
F_182 ( & V_308 , V_309 , V_382 -> V_389 , V_312 ) ;
F_312 ( & V_308 , V_309 , sizeof( V_453 ) , V_312 ) ;
memcpy ( & V_453 , V_308 , sizeof( V_453 ) ) ;
V_308 += sizeof( V_453 ) ;
F_182 ( & V_308 , V_309 , V_382 -> V_86 , V_312 ) ;
F_182 ( & V_308 , V_309 , V_382 -> V_107 , V_312 ) ;
if ( V_382 -> V_107 > F_319 ( V_382 -> V_157 ) )
goto V_312;
F_312 ( & V_308 , V_309 , V_382 -> V_107 * sizeof( struct V_136 ) ,
V_312 ) ;
for ( V_328 = 0 ; V_328 < V_382 -> V_107 ; V_328 ++ ) {
struct V_136 * V_51 = V_308 ;
V_382 -> V_157 [ V_328 ] = F_213 ( V_51 -> V_151 ) ;
V_308 += sizeof( * V_51 ) ;
}
F_182 ( & V_308 , V_309 , V_382 -> V_455 , V_312 ) ;
for ( V_328 = 0 ; V_328 < V_382 -> V_107 ; V_328 ++ )
F_182 ( & V_308 , V_309 , V_382 -> V_456 [ V_328 ] , V_312 ) ;
if ( V_340 >= 5 ) {
F_312 ( & V_308 , V_309 , sizeof( V_382 -> V_457 ) , V_312 ) ;
memcpy ( & V_382 -> V_457 , V_308 , sizeof( V_382 -> V_457 ) ) ;
V_308 += sizeof( V_382 -> V_457 ) ;
F_181 ( & V_308 , V_309 , V_382 -> V_458 , V_312 ) ;
} else {
V_382 -> V_457 = V_453 ;
V_382 -> V_458 = F_214 ( V_382 -> V_457 . V_340 ) ;
}
if ( V_340 >= 6 ) {
if ( V_340 >= 7 )
F_183 ( & V_308 , V_309 , V_454 , V_312 ) ;
else
V_454 = 1 ;
} else {
V_454 = 0 ;
}
if ( V_454 ) {
V_269 = F_316 ( & V_308 , V_309 , & V_382 -> V_459 ) ;
if ( V_269 )
return V_269 ;
} else {
F_40 ( & V_382 -> V_459 . V_122 ) ;
}
return 0 ;
V_312:
return - V_314 ;
}
static void F_320 ( struct V_7 * V_8 , struct V_114 * V_126 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_37 * V_88 ;
struct V_452 V_382 ;
T_1 V_354 = F_214 ( V_126 -> V_339 . V_354 ) ;
T_2 V_327 = 0 ;
int V_269 ;
int V_328 ;
F_14 ( L_81 , V_95 , V_126 , V_354 ) ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_199 ) ;
goto V_460;
}
F_6 ( V_8 -> V_199 != F_214 ( V_126 -> V_339 . V_78 . V_461 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_88 = F_321 ( & V_8 -> V_202 , V_354 ) ;
if ( ! V_88 ) {
F_14 ( L_83 , V_95 , V_8 -> V_199 , V_354 ) ;
goto V_462;
}
V_382 . V_459 . V_122 . V_123 = V_88 -> V_98 . V_71 . V_123 ;
V_269 = F_317 ( V_126 , & V_382 ) ;
V_382 . V_459 . V_122 . V_123 = NULL ;
if ( V_269 ) {
F_100 ( L_84 ,
V_88 -> V_227 , V_269 ) ;
F_322 ( V_126 ) ;
goto V_463;
}
F_14 ( L_85 ,
V_95 , V_88 , V_88 -> V_227 , V_382 . V_84 , V_382 . V_79 . V_193 , V_382 . V_79 . V_277 ,
V_382 . V_86 , V_382 . V_455 , F_213 ( V_382 . V_457 . V_86 ) ,
F_214 ( V_382 . V_457 . V_340 ) , V_382 . V_458 ) ;
if ( V_382 . V_455 >= 0 ) {
if ( V_382 . V_455 != V_88 -> V_338 - 1 ) {
F_14 ( L_86 ,
V_88 , V_88 -> V_227 , V_382 . V_455 ,
V_88 -> V_338 - 1 ) ;
goto V_462;
}
} else {
F_6 ( 1 ) ;
}
if ( ! F_78 ( & V_382 . V_459 . V_122 ) ) {
F_14 ( L_87 , V_88 , V_88 -> V_227 ,
V_382 . V_459 . V_122 . V_193 ) ;
F_137 ( V_8 , V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
V_88 -> V_98 . V_71 . V_193 = V_382 . V_459 . V_122 . V_193 ;
V_88 -> V_192 |= V_464 ;
V_88 -> V_227 = 0 ;
F_223 ( V_88 , false ) ;
goto V_460;
}
if ( V_382 . V_107 != V_88 -> V_40 ) {
F_100 ( L_88 , V_382 . V_107 ,
V_88 -> V_40 , V_88 -> V_227 ) ;
goto V_463;
}
for ( V_328 = 0 ; V_328 < V_88 -> V_40 ; V_328 ++ ) {
F_14 ( L_89 , V_88 ,
V_88 -> V_227 , V_328 , V_382 . V_456 [ V_328 ] , V_382 . V_157 [ V_328 ] ) ;
V_88 -> V_41 [ V_328 ] . V_456 = V_382 . V_456 [ V_328 ] ;
V_88 -> V_41 [ V_328 ] . V_157 = V_382 . V_157 [ V_328 ] ;
V_327 += V_382 . V_157 [ V_328 ] ;
}
if ( V_327 != F_213 ( V_126 -> V_339 . V_327 ) ) {
F_100 ( L_90 , V_327 ,
F_213 ( V_126 -> V_339 . V_327 ) , V_88 -> V_227 ) ;
goto V_463;
}
F_14 ( L_91 , V_95 ,
V_88 , V_88 -> V_227 , V_382 . V_389 , V_327 ) ;
F_6 ( ! ( V_382 . V_84 & V_372 ) ) ;
V_88 -> V_377 = V_382 . V_389 ? : V_327 ;
F_234 ( V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_237 ( V_88 ) ;
F_238 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
return;
V_463:
F_227 ( V_88 , - V_465 ) ;
V_462:
F_228 ( & V_8 -> V_6 ) ;
V_460:
F_4 ( & V_5 -> V_6 ) ;
}
static void F_323 ( struct V_4 * V_5 )
{
struct V_225 * V_226 ;
for ( V_226 = F_134 ( & V_5 -> V_235 -> V_245 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_242 * V_243 =
F_135 ( V_226 , struct V_242 , V_229 ) ;
V_243 -> V_466 = F_153 ( V_243 ) ;
}
}
static bool F_324 ( struct V_4 * V_5 , T_8 V_194 )
{
struct V_242 * V_243 ;
V_243 = F_156 ( V_5 -> V_235 , V_194 ) ;
if ( ! V_243 )
return false ;
return V_243 -> V_466 && ! F_153 ( V_243 ) ;
}
static enum V_254
F_325 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
enum V_254 V_268 ;
V_268 = F_159 ( V_5 , & V_11 -> V_67 , NULL , true ) ;
if ( V_268 == V_281 ) {
struct V_7 * V_8 ;
V_8 = F_146 ( V_5 , V_11 -> V_67 . V_8 , true ) ;
if ( V_8 != V_11 -> V_8 ) {
F_139 ( V_11 -> V_8 , V_11 ) ;
F_140 ( V_8 , V_11 ) ;
}
}
return V_268 ;
}
static void F_326 ( struct V_7 * V_8 ,
bool V_261 ,
bool V_467 ,
bool V_468 ,
struct V_320 * V_469 ,
struct V_470 * V_471 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_225 * V_226 ;
bool V_472 ;
for ( V_226 = F_134 ( & V_8 -> V_204 ) ; V_226 ; ) {
struct V_10 * V_11 =
F_135 ( V_226 , struct V_10 , V_229 ) ;
enum V_254 V_268 ;
V_226 = F_136 ( V_226 ) ;
F_14 ( L_58 , V_95 , V_11 ,
V_11 -> V_230 ) ;
V_268 = F_325 ( V_11 ) ;
switch ( V_268 ) {
case V_282 :
V_472 = V_467 ||
( V_468 &&
F_324 ( V_5 , V_11 -> V_67 . V_69 . V_193 ) ) ;
if ( ! V_261 && ! V_472 )
break;
case V_281 :
F_286 ( V_11 ) ;
if ( F_51 ( & V_11 -> V_397 ) )
F_127 ( & V_11 -> V_397 , V_471 ) ;
break;
case V_270 :
F_131 ( & V_11 -> V_397 ) ;
F_291 ( V_11 ) ;
break;
}
}
for ( V_226 = F_134 ( & V_8 -> V_202 ) ; V_226 ; ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
enum V_254 V_268 ;
V_226 = F_136 ( V_226 ) ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_227 ) ;
V_268 = F_159 ( V_5 , & V_88 -> V_98 , & V_88 -> V_92 -> V_215 ,
false ) ;
switch ( V_268 ) {
case V_282 :
V_472 = V_467 ||
( V_468 &&
F_324 ( V_5 , V_88 -> V_98 . V_69 . V_193 ) ) ;
if ( ! V_261 &&
( ! ( V_88 -> V_192 & V_197 ) ||
! V_472 ) )
break;
case V_281 :
F_239 ( V_88 ) ;
F_137 ( V_8 , V_88 ) ;
F_150 ( V_469 , V_88 ) ;
break;
case V_270 :
F_249 ( V_88 ) ;
break;
}
}
}
static int F_327 ( struct V_4 * V_5 ,
void * V_308 , void * V_309 , bool V_473 ,
struct V_320 * V_469 ,
struct V_470 * V_471 )
{
struct V_383 * V_474 ;
struct V_225 * V_226 ;
bool V_475 = false ;
bool V_466 ;
V_466 = F_158 ( V_5 , V_250 ) ;
F_323 ( V_5 ) ;
if ( V_473 )
V_474 = F_328 ( & V_308 , V_309 , V_5 -> V_235 ) ;
else
V_474 = F_329 ( & V_308 , V_309 ) ;
if ( F_179 ( V_474 ) )
return F_180 ( V_474 ) ;
if ( V_474 != V_5 -> V_235 ) {
for ( V_226 = F_134 ( & V_474 -> V_245 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_242 * V_243 =
F_135 ( V_226 , struct V_242 , V_229 ) ;
struct V_242 * V_476 ;
V_476 = F_156 ( V_5 -> V_235 , V_243 -> V_251 ) ;
if ( V_476 )
V_243 -> V_466 = V_476 -> V_466 ;
else
F_6 ( V_243 -> V_466 ) ;
}
if ( V_5 -> V_235 -> V_86 &&
V_5 -> V_235 -> V_86 + 1 < V_474 -> V_86 ) {
F_6 ( V_473 ) ;
V_475 = true ;
}
F_330 ( V_5 -> V_235 ) ;
V_5 -> V_235 = V_474 ;
}
V_466 &= ! F_158 ( V_5 , V_250 ) ;
F_326 ( & V_5 -> V_228 , V_475 , V_466 , true ,
V_469 , V_471 ) ;
for ( V_226 = F_134 ( & V_5 -> V_231 ) ; V_226 ; ) {
struct V_7 * V_8 = F_135 ( V_226 , struct V_7 , V_200 ) ;
V_226 = F_136 ( V_226 ) ;
F_326 ( V_8 , V_475 , V_466 , true , V_469 ,
V_471 ) ;
if ( ! F_331 ( V_5 -> V_235 , V_8 -> V_199 ) ||
memcmp ( & V_8 -> V_215 . V_233 ,
F_332 ( V_5 -> V_235 , V_8 -> V_199 ) ,
sizeof( struct V_232 ) ) )
F_132 ( V_8 ) ;
}
return 0 ;
}
static void F_333 ( struct V_4 * V_5 ,
struct V_320 * V_469 ,
struct V_470 * V_471 )
{
struct V_10 * V_11 , * V_477 ;
enum V_254 V_268 ;
struct V_225 * V_226 ;
for ( V_226 = F_134 ( V_469 ) ; V_226 ; ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
V_226 = F_136 ( V_226 ) ;
if ( V_88 -> V_98 . V_86 < V_5 -> V_235 -> V_86 ) {
V_268 = F_159 ( V_5 , & V_88 -> V_98 , NULL , false ) ;
if ( V_268 == V_270 ) {
F_151 ( V_469 , V_88 ) ;
F_249 ( V_88 ) ;
}
}
}
for ( V_226 = F_134 ( V_469 ) ; V_226 ; ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
struct V_7 * V_8 ;
V_226 = F_136 ( V_226 ) ;
F_151 ( V_469 , V_88 ) ;
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
F_131 ( & V_11 -> V_397 ) ;
}
}
void F_334 ( struct V_4 * V_5 , struct V_114 * V_126 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_309 = V_308 + V_126 -> V_141 . V_143 ;
T_2 V_478 , V_479 ;
T_2 V_86 ;
struct V_480 V_481 ;
struct V_320 V_469 = V_203 ;
F_300 ( V_471 ) ;
bool V_482 = false ;
bool V_483 , V_484 ;
bool V_246 , V_248 ;
int V_378 ;
F_14 ( L_92 , V_95 , V_5 -> V_235 -> V_86 ) ;
F_231 ( & V_5 -> V_6 ) ;
F_312 ( & V_308 , V_309 , sizeof( V_481 ) , V_485 ) ;
F_335 ( & V_308 , & V_481 , sizeof( V_481 ) ) ;
if ( F_336 ( V_5 -> V_217 , & V_481 ) < 0 )
goto V_485;
V_483 = F_158 ( V_5 , V_247 ) ;
V_484 = F_158 ( V_5 , V_249 ) ||
F_158 ( V_5 , V_250 ) ||
F_154 ( V_5 ) ;
F_182 ( & V_308 , V_309 , V_478 , V_485 ) ;
F_14 ( L_93 , V_478 ) ;
while ( V_478 > 0 ) {
F_312 ( & V_308 , V_309 , 2 * sizeof( T_2 ) , V_485 ) ;
V_86 = F_211 ( & V_308 ) ;
V_479 = F_211 ( & V_308 ) ;
F_312 ( & V_308 , V_309 , V_479 , V_485 ) ;
if ( V_5 -> V_235 -> V_86 &&
V_5 -> V_235 -> V_86 + 1 == V_86 ) {
F_14 ( L_94 ,
V_86 , V_479 ) ;
V_378 = F_327 ( V_5 , V_308 , V_308 + V_479 , true ,
& V_469 , & V_471 ) ;
if ( V_378 )
goto V_485;
V_482 = true ;
} else {
F_14 ( L_95 ,
V_86 , V_479 ) ;
}
V_308 += V_479 ;
V_478 -- ;
}
if ( V_482 )
goto V_486;
F_182 ( & V_308 , V_309 , V_478 , V_485 ) ;
F_14 ( L_96 , V_478 ) ;
while ( V_478 ) {
F_312 ( & V_308 , V_309 , 2 * sizeof( T_2 ) , V_485 ) ;
V_86 = F_211 ( & V_308 ) ;
V_479 = F_211 ( & V_308 ) ;
F_312 ( & V_308 , V_309 , V_479 , V_485 ) ;
if ( V_478 > 1 ) {
F_14 ( L_97 ,
V_86 , V_479 ) ;
} else if ( V_5 -> V_235 -> V_86 >= V_86 ) {
F_14 ( L_98
L_99 , V_86 , V_479 ,
V_5 -> V_235 -> V_86 ) ;
} else {
F_14 ( L_100 , V_86 , V_479 ) ;
V_378 = F_327 ( V_5 , V_308 , V_308 + V_479 , false ,
& V_469 , & V_471 ) ;
if ( V_378 )
goto V_485;
}
V_308 += V_479 ;
V_478 -- ;
}
V_486:
V_246 = F_158 ( V_5 , V_247 ) ;
V_248 = F_158 ( V_5 , V_249 ) ||
F_158 ( V_5 , V_250 ) ||
F_154 ( V_5 ) ;
if ( V_483 || V_484 || V_246 || V_248 ||
V_5 -> V_235 -> V_86 < V_5 -> V_253 )
F_220 ( V_5 ) ;
F_333 ( V_5 , & V_469 , & V_471 ) ;
F_248 ( V_5 ) ;
F_337 ( & V_5 -> V_217 -> V_360 , V_361 ,
V_5 -> V_235 -> V_86 ) ;
F_247 ( & V_5 -> V_6 ) ;
F_338 ( & V_5 -> V_217 -> V_487 ) ;
return;
V_485:
F_100 ( L_101 ) ;
F_322 ( V_126 ) ;
F_247 ( & V_5 -> V_6 ) ;
}
static void F_339 ( struct V_7 * V_8 )
{
struct V_225 * V_226 ;
F_141 ( V_8 ) ;
for ( V_226 = F_134 ( & V_8 -> V_202 ) ; V_226 ; ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
V_226 = F_136 ( V_226 ) ;
if ( ! V_88 -> V_113 ) {
if ( ! V_88 -> V_98 . V_85 )
F_216 ( V_88 ) ;
} else {
F_266 ( V_88 ) ;
}
}
for ( V_226 = F_134 ( & V_8 -> V_204 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_10 * V_11 =
F_135 ( V_226 , struct V_10 , V_229 ) ;
F_282 ( V_11 ) ;
}
}
static void F_340 ( struct V_255 * V_256 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_95 , V_8 , V_8 -> V_199 ) ;
F_231 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_199 ) ;
goto V_392;
}
if ( ! F_143 ( V_8 ) )
F_339 ( V_8 ) ;
F_220 ( V_5 ) ;
V_392:
F_247 ( & V_5 -> V_6 ) ;
}
static int F_341 ( const struct V_114 * V_126 , struct V_489 * V_382 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_309 = V_308 + V_126 -> V_141 . V_143 ;
T_7 V_310 ;
T_2 V_311 ;
int V_269 ;
V_269 = F_177 ( & V_308 , V_309 , 1 , L_102 , & V_310 , & V_311 ) ;
if ( V_269 )
return V_269 ;
V_269 = F_318 ( & V_308 , V_309 , & V_382 -> V_80 . V_79 ) ;
if ( V_269 )
return V_269 ;
F_183 ( & V_308 , V_309 , V_382 -> V_80 . V_326 , V_312 ) ;
F_182 ( & V_308 , V_309 , V_382 -> V_490 , V_312 ) ;
F_183 ( & V_308 , V_309 , V_382 -> V_51 , V_312 ) ;
F_181 ( & V_308 , V_309 , V_382 -> V_251 , V_312 ) ;
V_382 -> V_319 = F_118 ( sizeof( * V_382 -> V_319 ) , V_213 ) ;
if ( ! V_382 -> V_319 )
return - V_140 ;
V_269 = F_176 ( & V_308 , V_309 , V_382 -> V_319 ) ;
if ( V_269 ) {
F_192 ( V_382 -> V_319 ) ;
return V_269 ;
}
V_382 -> V_309 = F_118 ( sizeof( * V_382 -> V_309 ) , V_213 ) ;
if ( ! V_382 -> V_309 ) {
F_192 ( V_382 -> V_319 ) ;
return - V_140 ;
}
V_269 = F_176 ( & V_308 , V_309 , V_382 -> V_309 ) ;
if ( V_269 ) {
F_192 ( V_382 -> V_319 ) ;
F_192 ( V_382 -> V_309 ) ;
return V_269 ;
}
return 0 ;
V_312:
return - V_314 ;
}
static struct V_114 * F_342 (
const struct V_315 * V_316 ,
T_2 V_490 )
{
struct V_114 * V_126 ;
void * V_308 , * V_309 ;
int V_127 ;
V_127 = V_130 +
V_131 + 1 ;
V_127 += 4 + 1 + 8 ;
V_127 += V_130 +
F_185 ( V_316 -> V_319 ) ;
V_127 += V_130 +
F_185 ( V_316 -> V_309 ) ;
V_126 = F_80 ( V_491 , V_127 , V_213 , true ) ;
if ( ! V_126 )
return NULL ;
V_308 = V_126 -> V_141 . V_142 ;
V_309 = V_308 + V_126 -> V_332 ;
F_204 ( & V_308 , & V_316 -> V_80 ) ;
F_190 ( & V_308 , V_490 ) ;
F_191 ( & V_308 , V_492 ) ;
F_189 ( & V_308 , V_316 -> V_251 ) ;
F_186 ( & V_308 , V_309 , V_316 -> V_319 ) ;
F_186 ( & V_308 , V_309 , V_316 -> V_309 ) ;
F_20 ( V_308 != V_309 ) ;
V_126 -> V_141 . V_143 = V_308 - V_126 -> V_141 . V_142 ;
V_126 -> V_339 . V_340 = F_104 ( 1 ) ;
V_126 -> V_339 . V_341 = F_102 ( V_126 -> V_141 . V_143 ) ;
return V_126 ;
}
static void F_343 ( struct V_7 * V_8 , struct V_489 * V_382 )
{
struct V_283 * V_284 ;
struct V_315 * V_316 ;
struct V_114 * V_126 ;
F_14 ( L_103 , V_95 , V_8 -> V_199 ,
V_382 -> V_80 . V_79 . V_193 , V_382 -> V_80 . V_79 . V_277 , V_382 -> V_80 . V_326 , V_382 -> V_251 ) ;
V_284 = F_201 ( & V_8 -> V_205 , & V_382 -> V_80 ) ;
if ( ! V_284 ) {
V_284 = F_169 () ;
if ( ! V_284 ) {
F_100 ( L_104 , V_95 ) ;
return;
}
V_284 -> V_80 = V_382 -> V_80 ;
F_344 ( & V_8 -> V_205 , V_284 ) ;
}
V_316 = F_193 () ;
if ( ! V_316 ) {
F_100 ( L_105 , V_95 ) ;
return;
}
V_316 -> V_80 = V_382 -> V_80 ;
V_316 -> V_251 = V_382 -> V_251 ;
V_316 -> V_319 = V_382 -> V_319 ;
V_382 -> V_319 = NULL ;
V_316 -> V_309 = V_382 -> V_309 ;
V_382 -> V_309 = NULL ;
F_345 ( & V_284 -> V_285 , V_316 ) ;
F_346 ( & V_8 -> V_206 , V_316 ) ;
V_126 = F_342 ( V_316 , V_382 -> V_490 ) ;
if ( ! V_126 ) {
F_100 ( L_106 , V_95 ) ;
return;
}
F_218 ( & V_8 -> V_215 , V_126 ) ;
}
static bool F_347 ( const struct V_66 * V_67 ,
const struct V_286 * V_319 ,
const struct V_286 * V_309 )
{
struct V_286 V_287 ;
int V_323 ;
F_199 ( & V_287 , V_67 ) ;
V_323 = F_175 ( & V_287 , V_319 ) ;
return ! V_323 || ( V_323 > 0 && F_175 ( & V_287 , V_309 ) < 0 ) ;
}
static void F_348 ( struct V_7 * V_8 ,
const struct V_489 * V_382 )
{
struct V_283 * V_284 ;
struct V_315 * V_316 ;
struct V_225 * V_226 ;
F_14 ( L_103 , V_95 , V_8 -> V_199 ,
V_382 -> V_80 . V_79 . V_193 , V_382 -> V_80 . V_79 . V_277 , V_382 -> V_80 . V_326 , V_382 -> V_251 ) ;
V_316 = F_349 ( & V_8 -> V_206 , V_382 -> V_251 ) ;
if ( ! V_316 ) {
F_100 ( L_107 ,
V_95 , V_8 -> V_199 , V_382 -> V_80 . V_79 . V_193 ,
V_382 -> V_80 . V_79 . V_277 , V_382 -> V_80 . V_326 , V_382 -> V_251 ) ;
return;
}
if ( F_175 ( V_316 -> V_319 , V_382 -> V_319 ) &&
F_175 ( V_316 -> V_309 , V_382 -> V_309 ) ) {
F_100 ( L_108 ,
V_95 , V_8 -> V_199 , V_382 -> V_80 . V_79 . V_193 ,
V_382 -> V_80 . V_79 . V_277 , V_382 -> V_80 . V_326 , V_382 -> V_251 ) ;
}
V_284 = F_201 ( & V_8 -> V_205 , & V_316 -> V_80 ) ;
F_20 ( ! V_284 ) ;
F_196 ( & V_284 -> V_285 , V_316 ) ;
F_197 ( & V_8 -> V_206 , V_316 ) ;
F_194 ( V_316 ) ;
if ( F_115 ( & V_284 -> V_285 ) ) {
F_198 ( & V_8 -> V_205 , V_284 ) ;
F_170 ( V_284 ) ;
}
for ( V_226 = F_134 ( & V_8 -> V_202 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_37 * V_88 =
F_135 ( V_226 , struct V_37 , V_89 ) ;
if ( ! F_350 ( & V_88 -> V_98 . V_80 , & V_382 -> V_80 ) ) {
if ( F_347 ( & V_88 -> V_98 , V_382 -> V_319 , V_382 -> V_309 ) ) {
F_216 ( V_88 ) ;
}
}
}
}
static void F_351 ( struct V_7 * V_8 , struct V_114 * V_126 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_489 V_382 ;
int V_269 ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_82 , V_95 , V_8 -> V_199 ) ;
F_4 ( & V_5 -> V_6 ) ;
return;
}
F_6 ( V_8 -> V_199 != F_214 ( V_126 -> V_339 . V_78 . V_461 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_269 = F_341 ( V_126 , & V_382 ) ;
if ( V_269 ) {
F_100 ( L_109 , V_269 ) ;
F_322 ( V_126 ) ;
goto V_392;
}
switch ( V_382 . V_51 ) {
case V_493 :
F_343 ( V_8 , & V_382 ) ;
break;
case V_494 :
F_348 ( V_8 , & V_382 ) ;
break;
default:
F_100 ( L_110 , V_95 , V_8 -> V_199 , V_382 . V_51 ) ;
}
F_192 ( V_382 . V_319 ) ;
F_192 ( V_382 . V_309 ) ;
V_392:
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
static void F_352 ( struct V_4 * V_5 ,
struct V_114 * V_126 )
{
void * V_308 = V_126 -> V_141 . V_142 ;
void * const V_309 = V_308 + V_126 -> V_141 . V_143 ;
struct V_10 * V_11 ;
struct V_405 * V_407 ;
T_7 V_495 , V_147 ;
T_1 V_171 , V_415 ;
T_1 V_416 = 0 ;
T_11 V_496 = 0 ;
void * V_418 = NULL ;
T_2 V_151 = 0 ;
F_183 ( & V_308 , V_309 , V_495 , V_485 ) ;
F_183 ( & V_308 , V_309 , V_147 , V_485 ) ;
F_181 ( & V_308 , V_309 , V_171 , V_485 ) ;
V_308 += 8 ;
F_181 ( & V_308 , V_309 , V_415 , V_485 ) ;
if ( V_495 >= 1 ) {
F_182 ( & V_308 , V_309 , V_151 , V_485 ) ;
F_312 ( & V_308 , V_309 , V_151 , V_485 ) ;
V_418 = V_308 ;
V_308 += V_151 ;
}
if ( F_215 ( V_126 -> V_339 . V_340 ) >= 2 )
F_182 ( & V_308 , V_309 , V_496 , V_485 ) ;
if ( F_215 ( V_126 -> V_339 . V_340 ) >= 3 )
F_181 ( & V_308 , V_309 , V_416 , V_485 ) ;
F_246 ( & V_5 -> V_6 ) ;
V_11 = F_353 ( & V_5 -> V_403 , V_171 ) ;
if ( ! V_11 ) {
F_14 ( L_111 , V_95 , V_147 ,
V_171 ) ;
goto V_460;
}
F_225 ( & V_11 -> V_6 ) ;
F_14 ( L_112 , V_95 ,
V_147 , V_171 , V_11 , V_11 -> V_414 ) ;
if ( V_147 == V_497 ) {
if ( ! V_11 -> V_420 ) {
V_11 -> V_420 = - V_423 ;
F_275 ( V_11 ) ;
}
} else if ( ! V_11 -> V_414 ) {
if ( V_11 -> V_415 && V_11 -> V_415 != V_415 ) {
F_14 ( L_113 , V_11 ,
V_11 -> V_415 , V_415 ) ;
} else if ( ! F_277 ( & V_11 -> V_400 ) ) {
struct V_498 * V_329 =
F_354 ( & V_126 -> V_329 ,
struct V_498 ,
V_499 ) ;
if ( V_329 ) {
if ( V_11 -> V_500 ) {
F_6 ( V_329 -> type !=
V_501 ) ;
* V_11 -> V_500 = V_329 -> V_25 ;
* V_11 -> V_502 = V_329 -> V_26 ;
} else {
F_36 ( V_329 -> V_25 ,
F_35 ( 0 , V_329 -> V_26 ) ) ;
}
}
V_11 -> V_433 = V_496 ;
F_238 ( & V_11 -> V_400 ) ;
}
} else {
V_407 = F_267 ( V_11 , F_273 ) ;
if ( ! V_407 ) {
F_100 ( L_114 ) ;
goto V_503;
}
V_407 -> V_63 . V_415 = V_415 ;
V_407 -> V_63 . V_416 = V_416 ;
V_407 -> V_63 . V_418 = V_418 ;
V_407 -> V_63 . V_151 = V_151 ;
V_407 -> V_63 . V_126 = F_219 ( V_126 ) ;
F_271 ( V_407 ) ;
}
V_503:
F_228 ( & V_11 -> V_6 ) ;
V_460:
F_4 ( & V_5 -> V_6 ) ;
return;
V_485:
F_100 ( L_115 ) ;
}
int F_355 ( struct V_4 * V_5 ,
struct V_37 * V_88 ,
bool V_504 )
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
unsigned long V_505 )
{
long V_506 ;
F_14 ( L_35 , V_95 , V_88 , V_88 -> V_227 ) ;
V_506 = F_358 ( & V_88 -> V_105 ,
F_359 ( V_505 ) ) ;
if ( V_506 <= 0 ) {
V_506 = V_506 ? : - V_443 ;
F_356 ( V_88 ) ;
} else {
V_506 = V_88 -> V_377 ;
}
return V_506 ;
}
int F_360 ( struct V_4 * V_5 ,
struct V_37 * V_88 )
{
return F_357 ( V_88 , 0 ) ;
}
void F_361 ( struct V_4 * V_5 )
{
struct V_225 * V_226 , * V_308 ;
T_1 V_369 = F_362 ( & V_5 -> V_369 ) ;
V_365:
F_246 ( & V_5 -> V_6 ) ;
for ( V_226 = F_134 ( & V_5 -> V_231 ) ; V_226 ; V_226 = F_136 ( V_226 ) ) {
struct V_7 * V_8 = F_135 ( V_226 , struct V_7 , V_200 ) ;
F_225 ( & V_8 -> V_6 ) ;
for ( V_308 = F_134 ( & V_8 -> V_202 ) ; V_308 ; V_308 = F_136 ( V_308 ) ) {
struct V_37 * V_88 =
F_135 ( V_308 , struct V_37 , V_89 ) ;
if ( V_88 -> V_227 > V_369 )
break;
if ( ! ( V_88 -> V_192 & V_197 ) )
continue;
F_59 ( V_88 ) ;
F_228 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_116 ,
V_95 , V_88 , V_88 -> V_227 , V_369 ) ;
F_363 ( & V_88 -> V_105 ) ;
F_62 ( V_88 ) ;
goto V_365;
}
F_228 ( & V_8 -> V_6 ) ;
}
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_117 , V_95 , V_369 ) ;
}
static struct V_37 *
F_364 ( struct V_10 * V_11 )
{
struct V_37 * V_88 ;
V_88 = F_70 ( V_11 -> V_5 , NULL , 1 , false , V_213 ) ;
if ( ! V_88 )
return NULL ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
if ( F_76 ( V_88 , V_213 ) ) {
F_62 ( V_88 ) ;
return NULL ;
}
return V_88 ;
}
struct V_10 *
F_365 ( struct V_4 * V_5 ,
struct V_507 * V_294 ,
struct V_121 * V_122 ,
T_12 V_417 ,
T_13 V_419 ,
void * V_329 )
{
struct V_10 * V_11 ;
int V_269 ;
V_11 = F_257 ( V_5 ) ;
if ( ! V_11 )
return F_108 ( - V_140 ) ;
V_11 -> V_414 = true ;
V_11 -> V_417 = V_417 ;
V_11 -> V_419 = V_419 ;
V_11 -> V_329 = V_329 ;
V_11 -> V_428 = V_222 ;
F_43 ( & V_11 -> V_67 . V_68 , V_294 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_122 ) ;
V_11 -> V_67 . V_84 = V_197 ;
F_366 ( & V_11 -> V_347 ) ;
V_11 -> V_393 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_393 ) {
V_269 = - V_140 ;
goto V_508;
}
V_11 -> V_394 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_394 ) {
V_269 = - V_140 ;
goto V_508;
}
F_231 ( & V_5 -> V_6 ) ;
F_262 ( V_11 ) ;
F_93 ( V_11 -> V_393 , 0 , V_11 -> V_230 ,
V_426 ) ;
F_93 ( V_11 -> V_394 , 0 , V_11 -> V_230 ,
V_429 ) ;
F_285 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
V_269 = F_296 ( V_11 ) ;
if ( V_269 ) {
F_290 ( V_11 ) ;
goto V_508;
}
return V_11 ;
V_508:
F_255 ( V_11 ) ;
return F_108 ( V_269 ) ;
}
int F_367 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
struct V_435 * V_436 = V_5 -> V_217 -> V_223 ;
struct V_37 * V_88 ;
int V_269 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_213 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_88 -> V_129 , & V_11 -> V_67 . V_69 ) ;
V_88 -> V_192 = V_197 ;
F_366 ( & V_88 -> V_333 ) ;
F_93 ( V_88 , 0 , V_11 -> V_230 ,
V_509 ) ;
V_269 = F_76 ( V_88 , V_213 ) ;
if ( V_269 )
goto V_510;
F_355 ( V_5 , V_88 , false ) ;
F_290 ( V_11 ) ;
F_255 ( V_11 ) ;
V_269 = F_357 ( V_88 , V_436 -> V_511 ) ;
V_510:
F_62 ( V_88 ) ;
return V_269 ;
}
static int F_368 ( struct V_37 * V_88 , int V_39 ,
T_1 V_415 , T_1 V_171 , void * V_418 ,
T_3 V_151 )
{
struct V_50 * V_51 ;
struct V_31 * V_512 ;
int V_269 ;
V_51 = F_84 ( V_88 , V_39 , V_60 , 0 ) ;
V_512 = F_73 ( sizeof( * V_512 ) , V_213 ) ;
if ( ! V_512 )
return - V_140 ;
F_90 ( V_512 ) ;
V_269 = F_369 ( V_512 , V_415 ) ;
V_269 |= F_369 ( V_512 , V_171 ) ;
if ( V_418 ) {
V_269 |= F_370 ( V_512 , V_151 ) ;
V_269 |= F_91 ( V_512 , V_418 , V_151 ) ;
} else {
V_269 |= F_370 ( V_512 , 0 ) ;
}
if ( V_269 ) {
F_371 ( V_512 ) ;
return - V_140 ;
}
F_17 ( & V_51 -> V_61 . V_46 , V_512 ) ;
V_51 -> V_47 = V_512 -> V_26 ;
return 0 ;
}
int F_372 ( struct V_4 * V_5 ,
struct V_507 * V_294 ,
struct V_121 * V_122 ,
T_1 V_415 ,
T_1 V_171 ,
void * V_418 ,
T_3 V_151 )
{
struct V_37 * V_88 ;
int V_269 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_213 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_294 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_192 = V_252 ;
V_269 = F_76 ( V_88 , V_213 ) ;
if ( V_269 )
goto V_510;
V_269 = F_368 ( V_88 , 0 , V_415 , V_171 , V_418 ,
V_151 ) ;
if ( V_269 )
goto V_510;
F_355 ( V_5 , V_88 , false ) ;
V_269 = F_360 ( V_5 , V_88 ) ;
V_510:
F_62 ( V_88 ) ;
return V_269 ;
}
static int F_373 ( struct V_37 * V_88 , int V_39 ,
T_1 V_171 , T_2 V_513 , T_2 V_505 ,
void * V_418 , T_3 V_151 )
{
struct V_50 * V_51 ;
struct V_31 * V_512 ;
int V_269 ;
V_51 = F_84 ( V_88 , V_39 , V_62 , 0 ) ;
V_51 -> V_63 . V_171 = V_171 ;
V_512 = F_73 ( sizeof( * V_512 ) , V_213 ) ;
if ( ! V_512 )
return - V_140 ;
F_90 ( V_512 ) ;
V_269 = F_370 ( V_512 , 1 ) ;
V_269 |= F_370 ( V_512 , V_505 ) ;
V_269 |= F_370 ( V_512 , V_151 ) ;
V_269 |= F_91 ( V_512 , V_418 , V_151 ) ;
if ( V_269 ) {
F_371 ( V_512 ) ;
return - V_140 ;
}
F_17 ( & V_51 -> V_63 . V_46 , V_512 ) ;
V_51 -> V_47 = V_512 -> V_26 ;
return 0 ;
}
int F_374 ( struct V_4 * V_5 ,
struct V_507 * V_294 ,
struct V_121 * V_122 ,
void * V_418 ,
T_3 V_151 ,
T_2 V_505 ,
struct V_24 * * * V_500 ,
T_3 * V_502 )
{
struct V_10 * V_11 ;
struct V_24 * * V_25 ;
int V_269 ;
F_6 ( ! V_505 ) ;
if ( V_500 ) {
* V_500 = NULL ;
* V_502 = 0 ;
}
V_11 = F_257 ( V_5 ) ;
if ( ! V_11 )
return - V_140 ;
V_11 -> V_500 = V_500 ;
V_11 -> V_502 = V_502 ;
F_43 ( & V_11 -> V_67 . V_68 , V_294 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_122 ) ;
V_11 -> V_67 . V_84 = V_252 ;
V_11 -> V_393 = F_364 ( V_11 ) ;
if ( ! V_11 -> V_393 ) {
V_269 = - V_140 ;
goto V_514;
}
V_25 = F_375 ( 1 , V_213 ) ;
if ( F_179 ( V_25 ) ) {
V_269 = F_180 ( V_25 ) ;
goto V_514;
}
F_231 ( & V_5 -> V_6 ) ;
F_262 ( V_11 ) ;
V_269 = F_373 ( V_11 -> V_393 , 0 , V_11 -> V_230 , 1 ,
V_505 , V_418 , V_151 ) ;
if ( V_269 ) {
F_264 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
F_36 ( V_25 , 1 ) ;
goto V_514;
}
F_16 ( F_22 ( V_11 -> V_393 , 0 , V_63 ,
V_48 ) ,
V_25 , V_515 , 0 , false , true ) ;
F_285 ( V_11 ) ;
F_247 ( & V_5 -> V_6 ) ;
V_269 = F_296 ( V_11 ) ;
if ( ! V_269 )
V_269 = F_298 ( V_11 ) ;
else
F_14 ( L_118 , V_11 , V_269 ) ;
F_290 ( V_11 ) ;
V_514:
F_255 ( V_11 ) ;
return V_269 ;
}
int F_376 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
unsigned long V_516 , V_517 ;
int V_269 ;
F_246 ( & V_5 -> V_6 ) ;
F_225 ( & V_11 -> V_6 ) ;
V_516 = V_11 -> V_428 ;
if ( ! F_51 ( & V_11 -> V_398 ) ) {
struct V_405 * V_407 =
F_305 ( & V_11 -> V_398 ,
struct V_405 ,
V_409 ) ;
if ( F_301 ( V_407 -> V_410 , V_516 ) )
V_516 = V_407 -> V_410 ;
}
V_517 = V_222 - V_516 ;
F_14 ( L_119 , V_95 ,
V_11 , V_11 -> V_230 , V_517 , V_11 -> V_420 ) ;
V_269 = V_11 -> V_420 ? : 1 + F_377 ( V_517 ) ;
F_228 ( & V_11 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_269 ;
}
static int F_378 ( void * * V_308 , void * V_309 , struct V_518 * V_519 )
{
T_7 V_310 ;
T_2 V_311 ;
int V_269 ;
V_269 = F_177 ( V_308 , V_309 , 2 , L_120 ,
& V_310 , & V_311 ) ;
if ( V_269 )
return V_269 ;
F_335 ( V_308 , & V_519 -> V_166 , sizeof( V_519 -> V_166 ) ) ;
V_519 -> V_171 = F_210 ( V_308 ) ;
* V_308 += 4 ;
if ( V_310 >= 2 ) {
F_335 ( V_308 , & V_519 -> V_520 , sizeof( V_519 -> V_520 ) ) ;
F_379 ( & V_519 -> V_520 ) ;
}
F_14 ( L_121 , V_95 ,
F_380 ( V_519 -> V_166 ) , V_519 -> V_171 ,
F_381 ( & V_519 -> V_520 . V_521 ) ) ;
return 0 ;
}
static int F_382 ( void * * V_308 , void * V_309 ,
struct V_518 * * V_522 ,
T_2 * V_523 )
{
T_7 V_310 ;
T_2 V_311 ;
int V_328 ;
int V_269 ;
V_269 = F_177 ( V_308 , V_309 , 1 , L_122 ,
& V_310 , & V_311 ) ;
if ( V_269 )
return V_269 ;
* V_523 = F_211 ( V_308 ) ;
* V_522 = F_383 ( * V_523 , sizeof( * * V_522 ) , V_213 ) ;
if ( ! * V_522 )
return - V_140 ;
for ( V_328 = 0 ; V_328 < * V_523 ; V_328 ++ ) {
V_269 = F_378 ( V_308 , V_309 , * V_522 + V_328 ) ;
if ( V_269 ) {
F_58 ( * V_522 ) ;
return V_269 ;
}
}
return 0 ;
}
int F_384 ( struct V_4 * V_5 ,
struct V_507 * V_294 ,
struct V_121 * V_122 ,
struct V_518 * * V_522 ,
T_2 * V_523 )
{
struct V_37 * V_88 ;
struct V_24 * * V_25 ;
int V_269 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_213 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_294 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_192 = V_252 ;
V_269 = F_76 ( V_88 , V_213 ) ;
if ( V_269 )
goto V_510;
V_25 = F_375 ( 1 , V_213 ) ;
if ( F_179 ( V_25 ) ) {
V_269 = F_180 ( V_25 ) ;
goto V_510;
}
F_85 ( V_88 , 0 , V_64 , 0 ) ;
F_16 ( F_22 ( V_88 , 0 , V_65 ,
V_48 ) ,
V_25 , V_515 , 0 , false , true ) ;
F_355 ( V_5 , V_88 , false ) ;
V_269 = F_360 ( V_5 , V_88 ) ;
if ( V_269 >= 0 ) {
void * V_308 = F_279 ( V_25 [ 0 ] ) ;
void * const V_309 = V_308 + V_88 -> V_41 [ 0 ] . V_157 ;
V_269 = F_382 ( & V_308 , V_309 , V_522 , V_523 ) ;
}
V_510:
F_62 ( V_88 ) ;
return V_269 ;
}
void F_385 ( struct V_4 * V_5 )
{
F_14 ( L_70 , V_95 , V_5 ) ;
F_386 ( V_5 -> V_411 ) ;
}
void F_387 ( struct V_4 * V_5 )
{
F_246 ( & V_5 -> V_6 ) ;
F_220 ( V_5 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
int F_388 ( struct V_4 * V_5 ,
struct V_507 * V_294 ,
struct V_121 * V_122 ,
const char * V_158 , const char * V_159 ,
unsigned int V_84 ,
struct V_24 * V_524 , T_3 V_525 ,
struct V_24 * V_526 , T_3 * V_527 )
{
struct V_37 * V_88 ;
int V_269 ;
if ( V_525 > V_515 || ( V_526 && * V_527 > V_515 ) )
return - V_528 ;
V_88 = F_70 ( V_5 , NULL , 1 , false , V_213 ) ;
if ( ! V_88 )
return - V_140 ;
F_43 ( & V_88 -> V_128 , V_294 ) ;
F_44 ( & V_88 -> V_129 , V_122 ) ;
V_88 -> V_192 = V_84 ;
V_269 = F_76 ( V_88 , V_213 ) ;
if ( V_269 )
goto V_510;
F_89 ( V_88 , 0 , V_55 , V_158 , V_159 ) ;
if ( V_524 )
F_29 ( V_88 , 0 , & V_524 , V_525 ,
0 , false , false ) ;
if ( V_526 )
F_30 ( V_88 , 0 , & V_526 ,
* V_527 , 0 , false , false ) ;
F_355 ( V_5 , V_88 , false ) ;
V_269 = F_360 ( V_5 , V_88 ) ;
if ( V_269 >= 0 ) {
V_269 = V_88 -> V_41 [ 0 ] . V_456 ;
if ( V_526 )
* V_527 = V_88 -> V_41 [ 0 ] . V_157 ;
}
V_510:
F_62 ( V_88 ) ;
return V_269 ;
}
int F_389 ( struct V_4 * V_5 , struct V_529 * V_217 )
{
int V_378 ;
F_14 ( L_123 ) ;
V_5 -> V_217 = V_217 ;
F_390 ( & V_5 -> V_6 ) ;
V_5 -> V_231 = V_203 ;
F_68 ( & V_5 -> V_220 ) ;
F_391 ( & V_5 -> V_219 ) ;
F_111 ( & V_5 -> V_228 ) ;
V_5 -> V_228 . V_9 = V_5 ;
V_5 -> V_228 . V_199 = V_76 ;
V_5 -> V_402 = V_530 ;
V_5 -> V_403 = V_203 ;
V_5 -> V_375 = V_203 ;
V_5 -> V_431 = V_203 ;
F_392 ( & V_5 -> V_434 , F_299 ) ;
F_392 ( & V_5 -> V_444 , F_308 ) ;
V_378 = - V_140 ;
V_5 -> V_235 = F_393 () ;
if ( ! V_5 -> V_235 )
goto V_271;
V_5 -> V_102 = F_394 ( 10 ,
V_104 ) ;
if ( ! V_5 -> V_102 )
goto V_531;
V_378 = F_395 ( & V_5 -> V_138 , V_139 ,
V_515 , 10 , true , L_124 ) ;
if ( V_378 < 0 )
goto V_532;
V_378 = F_395 ( & V_5 -> V_145 , V_146 ,
V_515 , 10 , true , L_125 ) ;
if ( V_378 < 0 )
goto V_533;
V_378 = - V_140 ;
V_5 -> V_411 = F_396 ( L_126 ) ;
if ( ! V_5 -> V_411 )
goto V_534;
F_307 ( & V_5 -> V_434 ,
V_5 -> V_217 -> V_223 -> V_438 ) ;
F_307 ( & V_5 -> V_444 ,
F_310 ( V_5 -> V_217 -> V_223 -> V_224 ) ) ;
return 0 ;
V_534:
F_397 ( & V_5 -> V_145 ) ;
V_533:
F_397 ( & V_5 -> V_138 ) ;
V_532:
F_398 ( V_5 -> V_102 ) ;
V_531:
F_330 ( V_5 -> V_235 ) ;
V_271:
return V_378 ;
}
void F_399 ( struct V_4 * V_5 )
{
F_386 ( V_5 -> V_411 ) ;
F_400 ( V_5 -> V_411 ) ;
F_401 ( & V_5 -> V_434 ) ;
F_401 ( & V_5 -> V_444 ) ;
F_231 ( & V_5 -> V_6 ) ;
while ( ! F_115 ( & V_5 -> V_231 ) ) {
struct V_7 * V_8 = F_135 ( F_134 ( & V_5 -> V_231 ) ,
struct V_7 , V_200 ) ;
F_132 ( V_8 ) ;
}
F_247 ( & V_5 -> V_6 ) ;
F_6 ( F_122 ( & V_5 -> V_228 . V_201 ) != 1 ) ;
F_114 ( & V_5 -> V_228 ) ;
F_6 ( ! F_51 ( & V_5 -> V_220 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_403 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_375 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_431 ) ) ;
F_6 ( F_304 ( & V_5 -> V_373 ) ) ;
F_6 ( F_304 ( & V_5 -> V_241 ) ) ;
F_330 ( V_5 -> V_235 ) ;
F_398 ( V_5 -> V_102 ) ;
F_397 ( & V_5 -> V_138 ) ;
F_397 ( & V_5 -> V_145 ) ;
}
int F_402 ( struct V_4 * V_5 ,
struct V_186 V_187 , struct V_12 * V_13 ,
T_1 V_14 , T_1 * V_15 ,
T_2 V_150 , T_1 V_149 ,
struct V_24 * * V_25 , int V_49 , int V_535 )
{
struct V_37 * V_88 ;
int V_536 = 0 ;
F_14 ( L_127 , V_187 . V_195 ,
V_187 . V_196 , V_14 , * V_15 ) ;
V_88 = F_105 ( V_5 , V_13 , V_187 , V_14 , V_15 , 0 , 1 ,
V_52 , V_252 ,
NULL , V_150 , V_149 ,
false ) ;
if ( F_179 ( V_88 ) )
return F_180 ( V_88 ) ;
F_24 ( V_88 , 0 ,
V_25 , * V_15 , V_535 , false , false ) ;
F_14 ( L_128 ,
V_14 , * V_15 , * V_15 , V_535 ) ;
V_536 = F_355 ( V_5 , V_88 , false ) ;
if ( ! V_536 )
V_536 = F_360 ( V_5 , V_88 ) ;
F_62 ( V_88 ) ;
F_14 ( L_129 , V_536 ) ;
return V_536 ;
}
int F_403 ( struct V_4 * V_5 , struct V_186 V_187 ,
struct V_12 * V_13 ,
struct V_110 * V_111 ,
T_1 V_14 , T_1 V_124 ,
T_2 V_150 , T_1 V_149 ,
struct V_537 * V_347 ,
struct V_24 * * V_25 , int V_49 )
{
struct V_37 * V_88 ;
int V_536 = 0 ;
int V_535 = V_14 & ~ V_538 ;
V_88 = F_105 ( V_5 , V_13 , V_187 , V_14 , & V_124 , 0 , 1 ,
V_53 , V_197 ,
V_111 , V_150 , V_149 ,
true ) ;
if ( F_179 ( V_88 ) )
return F_180 ( V_88 ) ;
F_24 ( V_88 , 0 , V_25 , V_124 , V_535 ,
false , false ) ;
F_14 ( L_130 , V_14 , V_124 , V_124 ) ;
V_88 -> V_333 = * V_347 ;
V_536 = F_355 ( V_5 , V_88 , true ) ;
if ( ! V_536 )
V_536 = F_360 ( V_5 , V_88 ) ;
F_62 ( V_88 ) ;
if ( V_536 == 0 )
V_536 = V_124 ;
F_14 ( L_131 , V_536 ) ;
return V_536 ;
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
static void F_408 ( struct V_255 * V_256 , struct V_114 * V_126 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
struct V_4 * V_5 = V_8 -> V_9 ;
int type = F_215 ( V_126 -> V_339 . type ) ;
switch ( type ) {
case V_539 :
F_334 ( V_5 , V_126 ) ;
break;
case V_146 :
F_320 ( V_8 , V_126 ) ;
break;
case V_491 :
F_351 ( V_8 , V_126 ) ;
break;
case V_540 :
F_352 ( V_5 , V_126 ) ;
break;
default:
F_100 ( L_133 , type ,
F_409 ( type ) ) ;
}
F_54 ( V_126 ) ;
}
static struct V_114 * F_410 ( struct V_255 * V_256 ,
struct V_541 * V_339 ,
int * V_542 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_114 * V_382 = NULL ;
struct V_37 * V_88 ;
int V_341 = F_213 ( V_339 -> V_341 ) ;
int V_327 = F_213 ( V_339 -> V_327 ) ;
T_1 V_354 = F_214 ( V_339 -> V_354 ) ;
F_246 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_134 , V_95 , V_8 -> V_199 ) ;
* V_542 = 1 ;
goto V_460;
}
F_6 ( V_8 -> V_199 != F_214 ( V_339 -> V_78 . V_461 ) ) ;
F_225 ( & V_8 -> V_6 ) ;
V_88 = F_321 ( & V_8 -> V_202 , V_354 ) ;
if ( ! V_88 ) {
F_14 ( L_135 , V_95 ,
V_8 -> V_199 , V_354 ) ;
* V_542 = 1 ;
goto V_462;
}
F_236 ( V_88 -> V_97 ) ;
if ( V_341 > V_88 -> V_97 -> V_332 ) {
F_314 ( L_136 ,
V_95 , V_8 -> V_199 , V_88 -> V_227 , V_341 ,
V_88 -> V_97 -> V_332 ) ;
V_382 = F_80 ( V_146 , V_341 , V_160 ,
false ) ;
if ( ! V_382 )
goto V_462;
F_54 ( V_88 -> V_97 ) ;
V_88 -> V_97 = V_382 ;
}
if ( V_327 > V_88 -> V_97 -> V_330 ) {
F_314 ( L_137 ,
V_95 , V_8 -> V_199 , V_88 -> V_227 , V_327 ,
V_88 -> V_97 -> V_330 ) ;
V_382 = NULL ;
* V_542 = 1 ;
goto V_462;
}
V_382 = F_219 ( V_88 -> V_97 ) ;
F_14 ( L_138 , V_354 , V_382 ) ;
V_462:
F_228 ( & V_8 -> V_6 ) ;
V_460:
F_4 ( & V_5 -> V_6 ) ;
return V_382 ;
}
static struct V_114 * F_411 ( struct V_541 * V_339 )
{
struct V_114 * V_382 ;
int type = F_215 ( V_339 -> type ) ;
T_2 V_341 = F_213 ( V_339 -> V_341 ) ;
T_2 V_327 = F_213 ( V_339 -> V_327 ) ;
V_382 = F_80 ( type , V_341 , V_213 , false ) ;
if ( ! V_382 )
return NULL ;
if ( V_327 ) {
struct V_24 * * V_25 ;
struct V_21 V_22 ;
V_25 = F_375 ( F_35 ( 0 , V_327 ) ,
V_213 ) ;
if ( F_179 ( V_25 ) ) {
F_54 ( V_382 ) ;
return NULL ;
}
F_16 ( & V_22 , V_25 , V_327 , 0 , false ,
false ) ;
F_95 ( V_382 , & V_22 ) ;
}
return V_382 ;
}
static struct V_114 * F_412 ( struct V_255 * V_256 ,
struct V_541 * V_339 ,
int * V_542 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
int type = F_215 ( V_339 -> type ) ;
* V_542 = 0 ;
switch ( type ) {
case V_539 :
case V_491 :
case V_540 :
return F_411 ( V_339 ) ;
case V_146 :
return F_410 ( V_256 , V_339 , V_542 ) ;
default:
F_314 ( L_139 , V_95 ,
V_8 -> V_199 , type ) ;
* V_542 = 1 ;
return NULL ;
}
}
static struct V_255 * F_413 ( struct V_255 * V_256 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
if ( F_120 ( V_8 ) )
return V_256 ;
return NULL ;
}
static void F_414 ( struct V_255 * V_256 )
{
struct V_7 * V_8 = V_256 -> V_488 ;
F_123 ( V_8 ) ;
}
static struct V_543 * F_415 ( struct V_255 * V_256 ,
int * V_544 , int V_545 )
{
struct V_7 * V_240 = V_256 -> V_488 ;
struct V_4 * V_5 = V_240 -> V_9 ;
struct V_546 * V_547 = V_5 -> V_217 -> V_360 . V_548 ;
struct V_543 * V_548 = & V_240 -> V_210 ;
if ( V_545 && V_548 -> V_211 ) {
F_116 ( V_548 -> V_211 ) ;
V_548 -> V_211 = NULL ;
}
if ( ! V_548 -> V_211 ) {
int V_269 = F_416 ( V_547 , V_239 ,
V_548 ) ;
if ( V_269 )
return F_108 ( V_269 ) ;
} else {
int V_269 = F_417 ( V_547 , V_239 ,
V_548 ) ;
if ( V_269 )
return F_108 ( V_269 ) ;
}
* V_544 = V_547 -> V_549 ;
return V_548 ;
}
static int F_418 ( struct V_255 * V_256 )
{
struct V_7 * V_240 = V_256 -> V_488 ;
struct V_4 * V_5 = V_240 -> V_9 ;
struct V_546 * V_547 = V_5 -> V_217 -> V_360 . V_548 ;
return F_419 ( V_547 , V_240 -> V_210 . V_211 ) ;
}
static int F_420 ( struct V_255 * V_256 )
{
struct V_7 * V_240 = V_256 -> V_488 ;
struct V_4 * V_5 = V_240 -> V_9 ;
struct V_546 * V_547 = V_5 -> V_217 -> V_360 . V_548 ;
F_421 ( V_547 , V_239 ) ;
return F_422 ( & V_5 -> V_217 -> V_360 ) ;
}
static void F_423 ( struct V_114 * V_126 )
{
int type = F_215 ( V_126 -> V_339 . type ) ;
if ( type == V_139 )
F_209 ( V_126 ) ;
}
static int F_424 ( struct V_114 * V_126 )
{
struct V_7 * V_240 = V_126 -> V_256 -> V_488 ;
struct V_543 * V_548 = & V_240 -> V_210 ;
return F_425 ( V_548 , V_126 ) ;
}
static int F_426 ( struct V_114 * V_126 )
{
struct V_7 * V_240 = V_126 -> V_256 -> V_488 ;
struct V_543 * V_548 = & V_240 -> V_210 ;
return F_427 ( V_548 , V_126 ) ;
}
