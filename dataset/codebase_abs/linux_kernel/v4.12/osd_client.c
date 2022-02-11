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
F_45 ( & V_77 -> V_72 , & V_78 -> V_72 ) ;
F_45 ( & V_77 -> V_73 , & V_78 -> V_73 ) ;
V_77 -> V_74 = V_78 -> V_74 ;
V_77 -> V_75 = V_78 -> V_75 ;
V_77 -> V_82 = V_78 -> V_82 ;
V_77 -> V_83 = V_78 -> V_83 ;
V_77 -> V_84 = V_78 -> V_84 ;
V_77 -> V_8 = V_78 -> V_8 ;
}
static void F_46 ( struct V_66 * V_67 )
{
F_47 ( & V_67 -> V_68 ) ;
F_48 ( & V_67 -> V_69 ) ;
F_47 ( & V_67 -> V_70 ) ;
F_48 ( & V_67 -> V_71 ) ;
}
static void F_49 ( struct V_37 * V_85 )
{
F_6 ( ! F_50 ( & V_85 -> V_86 ) ) ;
F_6 ( ! F_50 ( & V_85 -> V_87 ) ) ;
F_6 ( ! F_51 ( & V_85 -> V_88 ) ) ;
F_6 ( V_85 -> V_89 ) ;
}
static void F_52 ( struct V_90 * V_90 )
{
struct V_37 * V_85 = F_53 ( V_90 ,
struct V_37 , V_91 ) ;
unsigned int V_39 ;
F_14 ( L_4 , V_92 , V_85 ,
V_85 -> V_93 , V_85 -> V_94 ) ;
F_49 ( V_85 ) ;
if ( V_85 -> V_93 )
F_54 ( V_85 -> V_93 ) ;
if ( V_85 -> V_94 )
F_54 ( V_85 -> V_94 ) ;
for ( V_39 = 0 ; V_39 < V_85 -> V_40 ; V_39 ++ )
F_37 ( V_85 , V_39 ) ;
F_46 ( & V_85 -> V_95 ) ;
F_55 ( V_85 -> V_96 ) ;
if ( V_85 -> V_97 )
F_56 ( V_85 , V_85 -> V_98 -> V_99 ) ;
else if ( V_85 -> V_40 <= V_100 )
F_57 ( V_101 , V_85 ) ;
else
F_58 ( V_85 ) ;
}
void F_59 ( struct V_37 * V_85 )
{
F_14 ( L_5 , V_92 , V_85 ,
F_60 ( & V_85 -> V_91 ) ) ;
F_61 ( & V_85 -> V_91 ) ;
}
void F_62 ( struct V_37 * V_85 )
{
if ( V_85 ) {
F_14 ( L_5 , V_92 , V_85 ,
F_60 ( & V_85 -> V_91 ) ) ;
F_63 ( & V_85 -> V_91 , F_52 ) ;
}
}
static void F_64 ( struct V_37 * V_85 )
{
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
F_65 ( & V_85 -> V_91 ) ;
F_66 ( & V_85 -> V_102 ) ;
F_67 ( & V_85 -> V_86 ) ;
F_67 ( & V_85 -> V_87 ) ;
F_68 ( & V_85 -> V_88 ) ;
F_38 ( & V_85 -> V_95 ) ;
}
static void F_69 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
bool V_103 = V_85 -> V_97 ;
unsigned int V_104 = V_85 -> V_40 ;
T_1 V_105 = V_85 -> V_106 ;
struct V_107 * V_108 = V_85 -> V_96 ;
bool V_109 = V_85 -> V_110 ;
struct V_111 * V_112 = V_85 -> V_93 ;
struct V_111 * V_113 = V_85 -> V_94 ;
F_14 ( L_6 , V_92 , V_85 ) ;
F_6 ( F_60 ( & V_85 -> V_91 ) != 1 ) ;
F_49 ( V_85 ) ;
F_6 ( F_60 ( & V_112 -> V_90 ) != 1 ) ;
F_6 ( F_60 ( & V_113 -> V_90 ) != 1 ) ;
F_46 ( & V_85 -> V_95 ) ;
F_64 ( V_85 ) ;
V_85 -> V_98 = V_5 ;
V_85 -> V_97 = V_103 ;
V_85 -> V_40 = V_104 ;
V_85 -> V_106 = V_105 ;
V_85 -> V_96 = V_108 ;
V_85 -> V_110 = V_109 ;
V_85 -> V_93 = V_112 ;
V_85 -> V_94 = V_113 ;
}
struct V_37 * F_70 ( struct V_4 * V_5 ,
struct V_107 * V_108 ,
unsigned int V_104 ,
bool V_114 ,
T_4 V_115 )
{
struct V_37 * V_85 ;
if ( V_114 ) {
F_20 ( V_104 > V_100 ) ;
V_85 = F_71 ( V_5 -> V_99 , V_115 ) ;
} else if ( V_104 <= V_100 ) {
V_85 = F_72 ( V_101 , V_115 ) ;
} else {
F_20 ( V_104 > V_116 ) ;
V_85 = F_73 ( sizeof( * V_85 ) + V_104 * sizeof( V_85 -> V_41 [ 0 ] ) ,
V_115 ) ;
}
if ( F_2 ( ! V_85 ) )
return NULL ;
F_64 ( V_85 ) ;
V_85 -> V_98 = V_5 ;
V_85 -> V_97 = V_114 ;
V_85 -> V_40 = V_104 ;
V_85 -> V_106 = V_117 ;
V_85 -> V_96 = F_74 ( V_108 ) ;
F_14 ( L_6 , V_92 , V_85 ) ;
return V_85 ;
}
static int F_75 ( struct V_118 * V_119 )
{
return 8 + 4 + 4 + 4 + ( V_119 -> V_120 ? V_119 -> V_120 -> V_121 : 0 ) ;
}
int F_76 ( struct V_37 * V_85 , T_4 V_122 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_111 * V_123 ;
int V_124 ;
F_6 ( F_77 ( & V_85 -> V_125 ) ) ;
F_6 ( F_78 ( & V_85 -> V_126 ) ) ;
V_124 = 4 + 4 + 4 ;
V_124 += 4 + 4 + 4 + 8 ;
V_124 += V_127 +
F_75 ( & V_85 -> V_126 ) ;
V_124 += 1 + 8 + 4 + 4 ;
V_124 += 4 + V_85 -> V_125 . V_128 ;
V_124 += 2 + V_85 -> V_40 * sizeof( struct V_129 ) ;
V_124 += 8 ;
V_124 += 8 ;
V_124 += 4 + 8 * ( V_85 -> V_96 ? V_85 -> V_96 -> V_130 : 0 ) ;
V_124 += 4 ;
if ( V_85 -> V_97 )
V_123 = F_79 ( & V_5 -> V_131 , 0 ) ;
else
V_123 = F_80 ( V_132 , V_124 , V_122 , true ) ;
if ( ! V_123 )
return - V_133 ;
memset ( V_123 -> V_134 . V_135 , 0 , V_123 -> V_134 . V_136 ) ;
V_85 -> V_93 = V_123 ;
V_124 = V_137 ;
V_124 += V_85 -> V_125 . V_128 ;
V_124 += V_85 -> V_40 * sizeof( struct V_129 ) ;
if ( V_85 -> V_97 )
V_123 = F_79 ( & V_5 -> V_138 , 0 ) ;
else
V_123 = F_80 ( V_139 , V_124 , V_122 , true ) ;
if ( ! V_123 )
return - V_133 ;
V_85 -> V_94 = V_123 ;
return 0 ;
}
static bool F_81 ( T_5 V_140 )
{
switch ( V_140 ) {
#define F_82 ( V_51 , V_140 , T_6 ) case CEPH_OSD_OP_##op: return true;
F_83 (GENERATE_CASE)
#undef F_82
default:
return false ;
}
}
static struct V_50 *
F_84 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_140 , T_2 V_83 )
{
struct V_50 * V_51 ;
F_20 ( V_39 >= V_38 -> V_40 ) ;
F_20 ( ! F_81 ( V_140 ) ) ;
V_51 = & V_38 -> V_41 [ V_39 ] ;
memset ( V_51 , 0 , sizeof ( * V_51 ) ) ;
V_51 -> V_51 = V_140 ;
V_51 -> V_83 = V_83 ;
return V_51 ;
}
void F_85 ( struct V_37 * V_38 ,
unsigned int V_39 , T_5 V_140 , T_2 V_83 )
{
( void ) F_84 ( V_38 , V_39 , V_140 , V_83 ) ;
}
void F_86 ( struct V_37 * V_38 ,
unsigned int V_39 , T_5 V_140 ,
T_1 V_141 , T_1 V_26 ,
T_1 V_142 , T_2 V_143 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_140 , 0 ) ;
T_3 V_144 = 0 ;
F_20 ( V_140 != V_52 && V_140 != V_53 &&
V_140 != V_54 && V_140 != V_145 &&
V_140 != V_146 ) ;
V_51 -> V_43 . V_141 = V_141 ;
V_51 -> V_43 . V_26 = V_26 ;
V_51 -> V_43 . V_142 = V_142 ;
V_51 -> V_43 . V_143 = V_143 ;
if ( V_140 == V_53 || V_140 == V_54 )
V_144 += V_26 ;
V_51 -> V_47 = V_144 ;
}
void F_87 ( struct V_37 * V_38 ,
unsigned int V_39 , T_1 V_26 )
{
struct V_50 * V_51 ;
T_1 V_147 ;
F_20 ( V_39 >= V_38 -> V_40 ) ;
V_51 = & V_38 -> V_41 [ V_39 ] ;
V_147 = V_51 -> V_43 . V_26 ;
if ( V_26 == V_147 )
return;
F_20 ( V_26 > V_147 ) ;
V_51 -> V_43 . V_26 = V_26 ;
if ( V_51 -> V_51 == V_53 || V_51 -> V_51 == V_54 )
V_51 -> V_47 -= V_147 - V_26 ;
}
void F_88 ( struct V_37 * V_38 ,
unsigned int V_39 , T_1 V_148 )
{
struct V_50 * V_51 , * V_149 ;
F_20 ( V_39 + 1 >= V_38 -> V_40 ) ;
V_149 = & V_38 -> V_41 [ V_39 ] ;
V_51 = F_84 ( V_38 , V_39 + 1 , V_149 -> V_51 , V_149 -> V_83 ) ;
V_51 -> V_47 = V_149 -> V_47 ;
V_51 -> V_150 = V_149 -> V_150 ;
V_51 -> V_43 = V_149 -> V_43 ;
V_51 -> V_43 . V_141 += V_148 ;
V_51 -> V_43 . V_26 -= V_148 ;
if ( V_51 -> V_51 == V_53 || V_51 -> V_51 == V_54 )
V_51 -> V_47 -= V_148 ;
}
void F_89 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_140 , const char * V_151 , const char * V_152 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_140 , 0 ) ;
struct V_31 * V_32 ;
T_3 V_144 = 0 ;
T_3 V_74 ;
F_20 ( V_140 != V_55 ) ;
V_32 = F_73 ( sizeof ( * V_32 ) , V_153 ) ;
F_20 ( ! V_32 ) ;
F_90 ( V_32 ) ;
V_51 -> V_44 . V_154 = V_151 ;
V_74 = strlen ( V_151 ) ;
F_20 ( V_74 > ( T_3 ) V_155 ) ;
V_51 -> V_44 . V_156 = V_74 ;
F_91 ( V_32 , V_151 , V_74 ) ;
V_144 += V_74 ;
V_51 -> V_44 . V_157 = V_152 ;
V_74 = strlen ( V_152 ) ;
F_20 ( V_74 > ( T_3 ) V_155 ) ;
V_51 -> V_44 . V_158 = V_74 ;
F_91 ( V_32 , V_152 , V_74 ) ;
V_144 += V_74 ;
F_27 ( V_38 , V_39 , V_32 ) ;
V_51 -> V_47 = V_144 ;
}
int F_92 ( struct V_37 * V_38 , unsigned int V_39 ,
T_5 V_140 , const char * V_159 , const void * V_160 ,
T_3 V_74 , T_7 V_161 , T_7 V_162 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_140 , 0 ) ;
struct V_31 * V_32 ;
T_3 V_144 ;
F_20 ( V_140 != V_56 && V_140 != V_57 ) ;
V_32 = F_73 ( sizeof( * V_32 ) , V_153 ) ;
if ( ! V_32 )
return - V_133 ;
F_90 ( V_32 ) ;
V_144 = strlen ( V_159 ) ;
V_51 -> V_58 . V_128 = V_144 ;
F_91 ( V_32 , V_159 , V_144 ) ;
V_51 -> V_58 . V_163 = V_74 ;
F_91 ( V_32 , V_160 , V_74 ) ;
V_144 += V_74 ;
V_51 -> V_58 . V_161 = V_161 ;
V_51 -> V_58 . V_162 = V_162 ;
F_17 ( & V_51 -> V_58 . V_22 , V_32 ) ;
V_51 -> V_47 = V_144 ;
return 0 ;
}
static void F_93 ( struct V_37 * V_85 , int V_39 ,
T_1 V_164 , T_7 V_165 )
{
struct V_50 * V_51 ;
V_51 = F_84 ( V_85 , V_39 , V_166 , 0 ) ;
V_51 -> V_167 . V_164 = V_164 ;
V_51 -> V_167 . V_51 = V_165 ;
V_51 -> V_167 . V_168 = 0 ;
}
void F_94 ( struct V_37 * V_38 ,
unsigned int V_39 ,
T_1 V_169 ,
T_1 V_170 )
{
struct V_50 * V_51 = F_84 ( V_38 , V_39 ,
V_171 ,
0 ) ;
V_51 -> V_172 . V_169 = V_169 ;
V_51 -> V_172 . V_170 = V_170 ;
V_51 -> V_83 |= V_173 ;
}
static void F_95 ( struct V_111 * V_123 ,
struct V_21 * V_22 )
{
T_1 V_26 = F_31 ( V_22 ) ;
if ( V_22 -> type == V_30 ) {
F_20 ( V_26 > ( T_1 ) V_174 ) ;
if ( V_26 )
F_96 ( V_123 , V_22 -> V_25 ,
V_26 , V_22 -> V_27 ) ;
} else if ( V_22 -> type == V_33 ) {
F_20 ( ! V_26 ) ;
F_97 ( V_123 , V_22 -> V_32 ) ;
#ifdef F_32
} else if ( V_22 -> type == V_36 ) {
F_98 ( V_123 , V_22 -> V_34 , V_26 ) ;
#endif
} else {
F_20 ( V_22 -> type != V_23 ) ;
}
}
static T_2 F_99 ( struct V_129 * V_175 ,
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
case V_145 :
case V_146 :
V_175 -> V_43 . V_141 = F_101 ( V_78 -> V_43 . V_141 ) ;
V_175 -> V_43 . V_26 = F_101 ( V_78 -> V_43 . V_26 ) ;
V_175 -> V_43 . V_142 =
F_101 ( V_78 -> V_43 . V_142 ) ;
V_175 -> V_43 . V_143 =
F_102 ( V_78 -> V_43 . V_143 ) ;
break;
case V_55 :
V_175 -> V_44 . V_156 = V_78 -> V_44 . V_156 ;
V_175 -> V_44 . V_158 = V_78 -> V_44 . V_158 ;
V_175 -> V_44 . V_47 = F_102 ( V_78 -> V_44 . V_47 ) ;
break;
case V_176 :
break;
case V_166 :
V_175 -> V_167 . V_164 = F_101 ( V_78 -> V_167 . V_164 ) ;
V_175 -> V_167 . V_177 = F_101 ( 0 ) ;
V_175 -> V_167 . V_51 = V_78 -> V_167 . V_51 ;
V_175 -> V_167 . V_168 = F_102 ( V_78 -> V_167 . V_168 ) ;
break;
case V_60 :
break;
case V_62 :
V_175 -> V_63 . V_164 = F_101 ( V_78 -> V_63 . V_164 ) ;
break;
case V_64 :
break;
case V_171 :
V_175 -> V_172 . V_169 =
F_101 ( V_78 -> V_172 . V_169 ) ;
V_175 -> V_172 . V_170 =
F_101 ( V_78 -> V_172 . V_170 ) ;
break;
case V_56 :
case V_57 :
V_175 -> V_58 . V_128 = F_102 ( V_78 -> V_58 . V_128 ) ;
V_175 -> V_58 . V_163 = F_102 ( V_78 -> V_58 . V_163 ) ;
V_175 -> V_58 . V_161 = V_78 -> V_58 . V_161 ;
V_175 -> V_58 . V_162 = V_78 -> V_58 . V_162 ;
break;
case V_178 :
case V_179 :
break;
default:
F_100 ( L_8 ,
F_103 ( V_78 -> V_51 ) ) ;
F_6 ( 1 ) ;
return 0 ;
}
V_175 -> V_51 = F_104 ( V_78 -> V_51 ) ;
V_175 -> V_83 = F_102 ( V_78 -> V_83 ) ;
V_175 -> V_144 = F_102 ( V_78 -> V_47 ) ;
return V_78 -> V_47 ;
}
struct V_37 * F_105 ( struct V_4 * V_5 ,
struct V_12 * V_13 ,
struct V_180 V_181 ,
T_1 V_14 , T_1 * V_15 ,
unsigned int V_39 , int V_104 ,
int V_140 , int V_83 ,
struct V_107 * V_108 ,
T_2 V_143 ,
T_1 V_142 ,
bool V_114 )
{
struct V_37 * V_85 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
int V_20 ;
F_20 ( V_140 != V_52 && V_140 != V_53 &&
V_140 != V_145 && V_140 != V_146 &&
V_140 != V_178 && V_140 != V_179 ) ;
V_85 = F_70 ( V_5 , V_108 , V_104 , V_114 ,
V_153 ) ;
if ( ! V_85 ) {
V_20 = - V_133 ;
goto V_182;
}
V_20 = F_12 ( V_13 , V_14 , V_15 , & V_16 , & V_17 , & V_18 ) ;
if ( V_20 )
goto V_182;
if ( V_140 == V_178 || V_140 == V_179 ) {
F_85 ( V_85 , V_39 , V_140 , 0 ) ;
} else {
T_2 V_183 = V_13 -> V_183 ;
T_2 V_184 = V_14 - V_17 ;
if ( ! ( V_143 == 1 && V_142 == - 1ULL ) ) {
if ( V_142 <= V_184 ) {
V_142 = 0 ;
} else {
V_142 -= V_184 ;
if ( V_142 > V_183 )
V_142 = V_183 ;
}
}
F_86 ( V_85 , V_39 , V_140 , V_17 , V_18 ,
V_142 , V_143 ) ;
}
V_85 -> V_185 = true ;
V_85 -> V_186 = V_83 ;
V_85 -> V_126 . V_187 = V_13 -> V_188 ;
V_85 -> V_126 . V_120 = F_106 ( V_13 -> V_120 ) ;
F_107 ( & V_85 -> V_125 , L_9 , V_181 . V_189 , V_16 ) ;
V_85 -> V_106 = V_181 . V_190 ;
if ( V_83 & V_191 )
V_85 -> V_192 = V_14 ;
V_20 = F_76 ( V_85 , V_153 ) ;
if ( V_20 )
goto V_182;
return V_85 ;
V_182:
F_62 ( V_85 ) ;
return F_108 ( V_20 ) ;
}
static bool F_109 ( struct V_7 * V_8 )
{
return V_8 -> V_193 == V_76 ;
}
static bool F_110 ( struct V_7 * V_8 )
{
F_5 ( V_8 -> V_9 ) ;
return ! F_50 ( & V_8 -> V_194 ) ;
}
static void F_111 ( struct V_7 * V_8 )
{
F_112 ( & V_8 -> V_195 , 1 ) ;
F_67 ( & V_8 -> V_194 ) ;
V_8 -> V_196 = V_197 ;
V_8 -> V_198 = V_197 ;
F_68 ( & V_8 -> V_199 ) ;
F_68 ( & V_8 -> V_200 ) ;
V_8 -> V_201 = 1 ;
F_113 ( & V_8 -> V_6 ) ;
}
static void F_114 ( struct V_7 * V_8 )
{
F_6 ( ! F_50 ( & V_8 -> V_194 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_196 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_198 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_199 ) ) ;
F_6 ( ! F_51 ( & V_8 -> V_200 ) ) ;
if ( V_8 -> V_202 . V_203 ) {
F_6 ( F_109 ( V_8 ) ) ;
F_116 ( V_8 -> V_202 . V_203 ) ;
}
}
static struct V_7 * F_117 ( struct V_4 * V_5 , int V_204 )
{
struct V_7 * V_8 ;
F_6 ( V_204 == V_76 ) ;
V_8 = F_118 ( sizeof( * V_8 ) , V_205 | V_206 ) ;
F_111 ( V_8 ) ;
V_8 -> V_9 = V_5 ;
V_8 -> V_193 = V_204 ;
F_119 ( & V_8 -> V_207 , V_8 , & V_208 , & V_5 -> V_209 -> V_210 ) ;
return V_8 ;
}
static struct V_7 * F_120 ( struct V_7 * V_8 )
{
if ( F_121 ( & V_8 -> V_195 ) ) {
F_14 ( L_10 , V_8 , F_122 ( & V_8 -> V_195 ) - 1 ,
F_122 ( & V_8 -> V_195 ) ) ;
return V_8 ;
} else {
F_14 ( L_11 , V_8 ) ;
return NULL ;
}
}
static void F_123 ( struct V_7 * V_8 )
{
F_14 ( L_12 , V_8 , F_122 ( & V_8 -> V_195 ) ,
F_122 ( & V_8 -> V_195 ) - 1 ) ;
if ( F_124 ( & V_8 -> V_195 ) ) {
F_114 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
static void F_125 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_92 , V_8 , V_8 -> V_193 ) ;
F_20 ( ! F_51 ( & V_8 -> V_199 ) ) ;
F_126 ( & V_5 -> V_211 ) ;
F_127 ( & V_8 -> V_199 , & V_5 -> V_212 ) ;
F_128 ( & V_5 -> V_211 ) ;
V_8 -> V_213 = V_214 + V_5 -> V_209 -> V_215 -> V_216 ;
}
static void F_129 ( struct V_7 * V_8 )
{
if ( F_115 ( & V_8 -> V_196 ) &&
F_115 ( & V_8 -> V_198 ) )
F_125 ( V_8 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_92 , V_8 , V_8 -> V_193 ) ;
F_126 ( & V_5 -> V_211 ) ;
if ( ! F_51 ( & V_8 -> V_199 ) )
F_131 ( & V_8 -> V_199 ) ;
F_128 ( & V_5 -> V_211 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_217 * V_218 ;
F_8 ( V_5 ) ;
F_14 ( L_13 , V_92 , V_8 , V_8 -> V_193 ) ;
F_133 ( & V_8 -> V_207 ) ;
for ( V_218 = F_134 ( & V_8 -> V_196 ) ; V_218 ; ) {
struct V_37 * V_85 =
F_135 ( V_218 , struct V_37 , V_86 ) ;
V_218 = F_136 ( V_218 ) ;
F_14 ( L_14 , V_85 , V_85 -> V_219 ) ;
F_137 ( V_8 , V_85 ) ;
F_138 ( & V_5 -> V_220 , V_85 ) ;
}
for ( V_218 = F_134 ( & V_8 -> V_198 ) ; V_218 ; ) {
struct V_10 * V_11 =
F_135 ( V_218 , struct V_10 , V_221 ) ;
V_218 = F_136 ( V_218 ) ;
F_14 ( L_15 , V_11 ,
V_11 -> V_222 ) ;
F_139 ( V_8 , V_11 ) ;
F_140 ( & V_5 -> V_220 , V_11 ) ;
}
F_130 ( V_8 ) ;
F_141 ( & V_5 -> V_223 , V_8 ) ;
F_123 ( V_8 ) ;
}
static int F_142 ( struct V_7 * V_8 )
{
struct V_224 * V_225 ;
F_14 ( L_13 , V_92 , V_8 , V_8 -> V_193 ) ;
if ( F_115 ( & V_8 -> V_196 ) &&
F_115 ( & V_8 -> V_198 ) ) {
F_132 ( V_8 ) ;
return - V_226 ;
}
V_225 = & V_8 -> V_9 -> V_227 -> V_228 [ V_8 -> V_193 ] ;
if ( ! memcmp ( V_225 , & V_8 -> V_207 . V_225 , sizeof ( * V_225 ) ) &&
! F_143 ( & V_8 -> V_207 ) ) {
struct V_217 * V_218 ;
F_14 ( L_16
L_17 ) ;
for ( V_218 = F_134 ( & V_8 -> V_196 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_37 * V_85 =
F_135 ( V_218 , struct V_37 , V_86 ) ;
V_85 -> V_229 = V_214 ;
}
return - V_230 ;
}
F_133 ( & V_8 -> V_207 ) ;
F_144 ( & V_8 -> V_207 , V_231 , V_8 -> V_193 , V_225 ) ;
V_8 -> V_201 ++ ;
return 0 ;
}
static struct V_7 * F_145 ( struct V_4 * V_5 , int V_232 ,
bool V_3 )
{
struct V_7 * V_8 ;
if ( V_3 )
F_8 ( V_5 ) ;
else
F_5 ( V_5 ) ;
if ( V_232 != V_76 )
V_8 = F_146 ( & V_5 -> V_223 , V_232 ) ;
else
V_8 = & V_5 -> V_220 ;
if ( ! V_8 ) {
if ( ! V_3 )
return F_108 ( - V_230 ) ;
V_8 = F_117 ( V_5 , V_232 ) ;
F_147 ( & V_5 -> V_223 , V_8 ) ;
F_144 ( & V_8 -> V_207 , V_231 , V_8 -> V_193 ,
& V_5 -> V_227 -> V_228 [ V_8 -> V_193 ] ) ;
}
F_14 ( L_18 , V_92 , V_5 , V_232 , V_8 ) ;
return V_8 ;
}
static void F_138 ( struct V_7 * V_8 , struct V_37 * V_85 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_85 -> V_219 || V_85 -> V_89 ) ;
F_14 ( L_19 , V_92 , V_8 , V_8 -> V_193 ,
V_85 , V_85 -> V_219 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_148 ( & V_8 -> V_9 -> V_233 ) ;
F_120 ( V_8 ) ;
F_149 ( & V_8 -> V_196 , V_85 ) ;
V_85 -> V_89 = V_8 ;
}
static void F_137 ( struct V_7 * V_8 , struct V_37 * V_85 )
{
F_9 ( V_8 ) ;
F_6 ( V_85 -> V_89 != V_8 ) ;
F_14 ( L_19 , V_92 , V_8 , V_8 -> V_193 ,
V_85 , V_85 -> V_219 ) ;
V_85 -> V_89 = NULL ;
F_150 ( & V_8 -> V_196 , V_85 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_151 ( & V_8 -> V_9 -> V_233 ) ;
}
static bool F_152 ( struct V_234 * V_235 )
{
return V_235 -> V_83 & V_236 ;
}
static bool F_153 ( struct V_4 * V_5 )
{
struct V_217 * V_218 ;
for ( V_218 = F_134 ( & V_5 -> V_227 -> V_237 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_234 * V_235 =
F_135 ( V_218 , struct V_234 , V_221 ) ;
if ( F_152 ( V_235 ) )
return true ;
}
return false ;
}
static bool F_154 ( struct V_4 * V_5 , T_8 V_188 )
{
struct V_234 * V_235 ;
V_235 = F_155 ( V_5 -> V_227 , V_188 ) ;
if ( ! V_235 )
return false ;
return F_152 ( V_235 ) ;
}
static bool F_156 ( struct V_4 * V_5 ,
const struct V_66 * V_67 ,
struct V_234 * V_235 )
{
bool V_238 = F_157 ( V_5 , V_239 ) ;
bool V_240 = F_157 ( V_5 , V_241 ) ||
F_157 ( V_5 , V_242 ) ||
F_152 ( V_235 ) ;
F_6 ( V_235 -> V_243 != V_67 -> V_69 . V_187 ) ;
return ( ( V_67 -> V_83 & V_244 ) && V_238 ) ||
( ( V_67 -> V_83 & V_191 ) && V_240 ) ||
( V_5 -> V_227 -> V_245 < V_5 -> V_246 ) ;
}
static enum V_247 F_158 ( struct V_4 * V_5 ,
struct V_66 * V_67 ,
T_2 * V_248 ,
bool V_249 )
{
struct V_234 * V_235 ;
struct V_250 V_79 , V_251 ;
struct V_252 V_73 , V_72 ;
bool V_253 = false ;
bool V_254 = false ;
bool V_255 = false ;
bool V_82 = F_157 ( V_5 , V_256 ) ;
enum V_247 V_257 ;
int V_258 ;
V_235 = F_155 ( V_5 -> V_227 , V_67 -> V_69 . V_187 ) ;
if ( ! V_235 ) {
V_67 -> V_8 = V_76 ;
V_257 = V_259 ;
goto V_260;
}
if ( V_5 -> V_227 -> V_245 == V_235 -> V_261 ) {
if ( V_248 &&
* V_248 < V_235 -> V_261 ) {
* V_248 = V_235 -> V_261 ;
V_253 = true ;
} else if ( ! V_248 ) {
V_253 = true ;
}
}
if ( F_77 ( & V_67 -> V_70 ) || V_253 ) {
F_43 ( & V_67 -> V_70 , & V_67 -> V_68 ) ;
V_254 = true ;
}
if ( F_78 ( & V_67 -> V_71 ) || V_253 ) {
F_44 ( & V_67 -> V_71 , & V_67 -> V_69 ) ;
V_254 = true ;
}
if ( V_254 &&
( V_67 -> V_83 & V_262 ) == 0 ) {
if ( V_67 -> V_83 & V_244 && V_235 -> V_263 >= 0 )
V_67 -> V_71 . V_187 = V_235 -> V_263 ;
if ( V_67 -> V_83 & V_191 && V_235 -> V_264 >= 0 )
V_67 -> V_71 . V_187 = V_235 -> V_264 ;
}
V_258 = F_159 ( V_5 -> V_227 , & V_67 -> V_70 ,
& V_67 -> V_71 , & V_79 ) ;
if ( V_258 ) {
F_6 ( V_258 != - V_265 ) ;
V_67 -> V_8 = V_76 ;
V_257 = V_259 ;
goto V_260;
}
V_251 . V_187 = V_79 . V_187 ;
V_251 . V_266 = F_160 ( V_79 . V_266 , V_67 -> V_80 , V_67 -> V_81 ) ;
F_161 ( V_5 -> V_227 , & V_79 , & V_73 , & V_72 ) ;
if ( V_249 &&
F_162 ( & V_67 -> V_72 ,
& V_72 ,
& V_67 -> V_73 ,
& V_73 ,
V_67 -> V_74 ,
V_235 -> V_74 ,
V_67 -> V_75 ,
V_235 -> V_75 ,
V_67 -> V_80 ,
V_235 -> V_80 ,
V_67 -> V_82 ,
V_82 ,
& V_251 ) )
V_253 = true ;
if ( V_67 -> V_84 && ! F_156 ( V_5 , V_67 , V_235 ) ) {
V_67 -> V_84 = false ;
V_255 = true ;
}
if ( F_163 ( & V_67 -> V_79 , & V_79 ) ||
F_164 ( & V_67 -> V_72 , & V_72 , V_249 ) ||
V_253 ) {
V_67 -> V_79 = V_79 ;
F_45 ( & V_67 -> V_72 , & V_72 ) ;
F_45 ( & V_67 -> V_73 , & V_73 ) ;
V_67 -> V_74 = V_235 -> V_74 ;
V_67 -> V_75 = V_235 -> V_75 ;
V_67 -> V_80 = V_235 -> V_80 ;
V_67 -> V_81 = V_235 -> V_81 ;
V_67 -> V_82 = V_82 ;
V_67 -> V_8 = V_72 . V_267 ;
V_255 = true ;
}
V_257 = V_255 ? V_268 : V_269 ;
V_260:
F_14 ( L_20 , V_92 , V_67 , V_257 , V_67 -> V_8 ) ;
return V_257 ;
}
static void F_165 ( struct V_37 * V_85 ,
struct V_111 * V_123 )
{
T_2 V_270 = 0 ;
int V_271 ;
if ( ! F_51 ( & V_123 -> V_272 ) )
return;
F_6 ( V_123 -> V_273 ) ;
for ( V_271 = 0 ; V_271 < V_85 -> V_40 ; V_271 ++ ) {
struct V_50 * V_51 = & V_85 -> V_41 [ V_271 ] ;
switch ( V_51 -> V_51 ) {
case V_53 :
case V_54 :
F_6 ( V_51 -> V_47 != V_51 -> V_43 . V_26 ) ;
F_95 ( V_123 , & V_51 -> V_43 . V_22 ) ;
break;
case V_56 :
case V_57 :
F_6 ( V_51 -> V_47 != V_51 -> V_58 . V_128 +
V_51 -> V_58 . V_163 ) ;
F_95 ( V_123 , & V_51 -> V_58 . V_22 ) ;
break;
case V_60 :
F_95 ( V_123 ,
& V_51 -> V_61 . V_46 ) ;
break;
case V_59 :
F_95 ( V_85 -> V_94 ,
& V_51 -> V_42 ) ;
break;
case V_52 :
F_95 ( V_85 -> V_94 ,
& V_51 -> V_43 . V_22 ) ;
break;
case V_64 :
F_95 ( V_85 -> V_94 ,
& V_51 -> V_65 . V_48 ) ;
break;
case V_55 :
F_6 ( V_51 -> V_47 != V_51 -> V_44 . V_156 +
V_51 -> V_44 . V_158 +
V_51 -> V_44 . V_47 ) ;
F_95 ( V_123 , & V_51 -> V_44 . V_45 ) ;
F_95 ( V_123 , & V_51 -> V_44 . V_46 ) ;
F_95 ( V_85 -> V_94 ,
& V_51 -> V_44 . V_48 ) ;
break;
case V_62 :
F_95 ( V_123 ,
& V_51 -> V_63 . V_46 ) ;
F_95 ( V_85 -> V_94 ,
& V_51 -> V_63 . V_48 ) ;
break;
}
V_270 += V_51 -> V_47 ;
}
F_6 ( V_270 != V_123 -> V_273 ) ;
}
static void F_166 ( struct V_37 * V_85 , struct V_111 * V_123 )
{
void * V_274 = V_123 -> V_134 . V_135 ;
void * const V_275 = V_274 + V_123 -> V_276 ;
T_2 V_270 = 0 ;
int V_271 ;
if ( V_85 -> V_186 & V_191 ) {
F_6 ( V_85 -> V_106 != V_117 ) ;
} else {
F_6 ( V_85 -> V_277 . V_278 || V_85 -> V_277 . V_279 ||
V_85 -> V_192 || V_85 -> V_96 ) ;
}
F_165 ( V_85 , V_123 ) ;
F_167 ( & V_274 , 1 ) ;
F_167 ( & V_274 , V_85 -> V_98 -> V_227 -> V_245 ) ;
F_167 ( & V_274 , V_85 -> V_186 ) ;
F_168 ( V_274 , & V_85 -> V_277 ) ;
V_274 += sizeof( struct V_280 ) ;
memset ( V_274 , 0 , sizeof( struct V_281 ) ) ;
V_274 += sizeof( struct V_281 ) ;
F_169 ( & V_274 , 5 , 4 ,
F_75 ( & V_85 -> V_95 . V_71 ) ) ;
F_170 ( & V_274 , V_85 -> V_95 . V_71 . V_187 ) ;
F_167 ( & V_274 , - 1 ) ;
F_167 ( & V_274 , 0 ) ;
if ( V_85 -> V_95 . V_71 . V_120 )
F_171 ( & V_274 , V_275 , V_85 -> V_95 . V_71 . V_120 -> T_6 ,
V_85 -> V_95 . V_71 . V_120 -> V_121 ) ;
else
F_167 ( & V_274 , 0 ) ;
F_172 ( & V_274 , 1 ) ;
F_170 ( & V_274 , V_85 -> V_95 . V_79 . V_187 ) ;
F_167 ( & V_274 , V_85 -> V_95 . V_79 . V_266 ) ;
F_167 ( & V_274 , - 1 ) ;
F_167 ( & V_274 , V_85 -> V_95 . V_70 . V_128 ) ;
memcpy ( V_274 , V_85 -> V_95 . V_70 . V_159 , V_85 -> V_95 . V_70 . V_128 ) ;
V_274 += V_85 -> V_95 . V_70 . V_128 ;
F_173 ( & V_274 , V_85 -> V_40 ) ;
for ( V_271 = 0 ; V_271 < V_85 -> V_40 ; V_271 ++ ) {
V_270 += F_99 ( V_274 , & V_85 -> V_41 [ V_271 ] ) ;
V_274 += sizeof( struct V_129 ) ;
}
F_170 ( & V_274 , V_85 -> V_106 ) ;
if ( V_85 -> V_96 ) {
F_170 ( & V_274 , V_85 -> V_96 -> V_282 ) ;
F_167 ( & V_274 , V_85 -> V_96 -> V_130 ) ;
for ( V_271 = 0 ; V_271 < V_85 -> V_96 -> V_130 ; V_271 ++ )
F_170 ( & V_274 , V_85 -> V_96 -> V_283 [ V_271 ] ) ;
} else {
F_170 ( & V_274 , 0 ) ;
F_167 ( & V_274 , 0 ) ;
}
F_167 ( & V_274 , V_85 -> V_284 ) ;
F_20 ( V_274 > V_275 ) ;
V_123 -> V_134 . V_136 = V_274 - V_123 -> V_134 . V_135 ;
V_123 -> V_285 . V_286 = F_104 ( 4 ) ;
V_123 -> V_285 . V_287 = F_102 ( V_123 -> V_134 . V_136 ) ;
V_123 -> V_285 . V_270 = F_102 ( V_270 ) ;
V_123 -> V_285 . V_288 = F_104 ( V_85 -> V_192 ) ;
F_14 ( L_21 , V_92 ,
V_85 , V_85 -> V_95 . V_70 . V_159 , V_85 -> V_95 . V_70 . V_128 ,
V_123 -> V_134 . V_136 , V_270 ) ;
}
static void F_174 ( struct V_37 * V_85 )
{
struct V_7 * V_8 = V_85 -> V_89 ;
F_9 ( V_8 ) ;
F_6 ( V_8 -> V_193 != V_85 -> V_95 . V_8 ) ;
if ( V_85 -> V_289 )
F_175 ( V_85 -> V_93 ) ;
V_85 -> V_186 |= V_290 ;
if ( V_85 -> V_284 )
V_85 -> V_186 |= V_291 ;
else
F_6 ( V_85 -> V_186 & V_291 ) ;
F_166 ( V_85 , V_85 -> V_93 ) ;
F_14 ( L_22 ,
V_92 , V_85 , V_85 -> V_219 , V_85 -> V_95 . V_79 . V_187 , V_85 -> V_95 . V_79 . V_266 ,
V_85 -> V_95 . V_8 , V_85 -> V_186 , V_85 -> V_284 ) ;
V_85 -> V_95 . V_84 = false ;
V_85 -> V_229 = V_214 ;
V_85 -> V_284 ++ ;
V_85 -> V_289 = V_8 -> V_201 ;
V_85 -> V_93 -> V_285 . V_292 = F_101 ( V_85 -> V_219 ) ;
F_176 ( & V_8 -> V_207 , F_177 ( V_85 -> V_93 ) ) ;
}
static void F_178 ( struct V_4 * V_5 )
{
bool V_293 = false ;
F_5 ( V_5 ) ;
F_6 ( ! V_5 -> V_227 -> V_245 ) ;
if ( F_157 ( V_5 , V_242 ) ||
F_157 ( V_5 , V_239 ) ||
F_157 ( V_5 , V_241 ) ) {
F_14 ( L_23 , V_92 , V_5 ) ;
V_293 = true ;
} else {
F_14 ( L_24 , V_92 , V_5 ) ;
}
if ( F_179 ( & V_5 -> V_209 -> V_294 , V_295 ,
V_5 -> V_227 -> V_245 + 1 , V_293 ) )
F_180 ( & V_5 -> V_209 -> V_294 ) ;
}
static void F_181 ( struct V_37 * V_85 , bool V_3 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_7 * V_8 ;
enum V_247 V_257 ;
bool V_296 = false ;
bool V_297 = false ;
bool V_298 = false ;
F_6 ( V_85 -> V_219 ) ;
F_14 ( L_25 , V_92 , V_85 , V_3 ) ;
V_299:
V_257 = F_158 ( V_5 , & V_85 -> V_95 , & V_85 -> V_300 , false ) ;
if ( V_257 == V_259 && ! V_3 )
goto V_301;
V_8 = F_145 ( V_5 , V_85 -> V_95 . V_8 , V_3 ) ;
if ( F_182 ( V_8 ) ) {
F_6 ( F_183 ( V_8 ) != - V_230 || V_3 ) ;
goto V_301;
}
if ( V_5 -> V_227 -> V_245 < V_5 -> V_246 ) {
F_14 ( L_26 , V_85 , V_5 -> V_227 -> V_245 ,
V_5 -> V_246 ) ;
V_85 -> V_95 . V_84 = true ;
F_178 ( V_5 ) ;
} else if ( ( V_85 -> V_186 & V_191 ) &&
F_157 ( V_5 , V_241 ) ) {
F_14 ( L_27 , V_85 ) ;
V_85 -> V_95 . V_84 = true ;
F_178 ( V_5 ) ;
} else if ( ( V_85 -> V_186 & V_244 ) &&
F_157 ( V_5 , V_239 ) ) {
F_14 ( L_28 , V_85 ) ;
V_85 -> V_95 . V_84 = true ;
F_178 ( V_5 ) ;
} else if ( ( V_85 -> V_186 & V_191 ) &&
! ( V_85 -> V_186 & ( V_302 |
V_303 ) ) &&
( F_157 ( V_5 , V_242 ) ||
F_154 ( V_5 , V_85 -> V_95 . V_69 . V_187 ) ) ) {
F_14 ( L_29 , V_85 ) ;
F_184 ( L_30 ) ;
V_85 -> V_95 . V_84 = true ;
F_178 ( V_5 ) ;
if ( V_85 -> V_185 )
V_298 = true ;
} else if ( ! F_109 ( V_8 ) ) {
V_296 = true ;
} else {
F_178 ( V_5 ) ;
}
F_185 ( & V_8 -> V_6 ) ;
V_85 -> V_219 = F_186 ( & V_5 -> V_304 ) ;
F_138 ( V_8 , V_85 ) ;
if ( V_296 )
F_174 ( V_85 ) ;
else if ( V_298 )
F_187 ( V_85 , - V_305 ) ;
F_188 ( & V_8 -> V_6 ) ;
if ( V_257 == V_259 )
F_189 ( V_85 ) ;
if ( V_297 )
F_190 ( & V_5 -> V_6 ) ;
return;
V_301:
F_4 ( & V_5 -> V_6 ) ;
F_191 ( & V_5 -> V_6 ) ;
V_3 = true ;
V_297 = true ;
goto V_299;
}
static void F_192 ( struct V_37 * V_85 )
{
F_6 ( V_85 -> V_186 & ( V_306 | V_307 ) ) ;
F_6 ( ! ( V_85 -> V_186 & ( V_244 | V_191 ) ) ) ;
V_85 -> V_186 |= V_307 ;
F_148 ( & V_85 -> V_98 -> V_308 ) ;
V_85 -> V_309 = V_214 ;
}
static void F_193 ( struct V_37 * V_85 , bool V_3 )
{
F_59 ( V_85 ) ;
F_192 ( V_85 ) ;
F_181 ( V_85 , V_3 ) ;
}
static void F_194 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_7 * V_8 = V_85 -> V_89 ;
F_9 ( V_8 ) ;
F_14 ( L_31 , V_92 , V_85 , V_85 -> V_219 ) ;
F_6 ( F_195 ( & V_5 -> V_310 , V_85 -> V_219 ) ) ;
F_137 ( V_8 , V_85 ) ;
F_151 ( & V_5 -> V_308 ) ;
F_175 ( V_85 -> V_93 ) ;
F_196 ( V_85 -> V_94 ) ;
}
static void F_197 ( struct V_37 * V_85 )
{
if ( V_85 -> V_311 ) {
F_14 ( L_32 , V_92 , V_85 ,
V_85 -> V_219 , V_85 -> V_311 , V_85 -> V_312 ) ;
V_85 -> V_311 ( V_85 ) ;
}
}
static void F_187 ( struct V_37 * V_85 , int V_313 )
{
F_14 ( L_33 , V_92 , V_85 , V_85 -> V_219 , V_313 ) ;
V_85 -> V_312 = V_313 ;
F_194 ( V_85 ) ;
F_197 ( V_85 ) ;
F_198 ( & V_85 -> V_102 ) ;
F_62 ( V_85 ) ;
}
static void F_199 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_37 * V_314 ;
F_8 ( V_5 ) ;
V_314 = F_195 ( & V_5 -> V_310 , V_85 -> V_219 ) ;
if ( ! V_314 )
return;
F_6 ( V_314 != V_85 ) ;
F_200 ( & V_5 -> V_310 , V_85 ) ;
F_62 ( V_85 ) ;
}
static void F_201 ( struct V_37 * V_85 )
{
F_14 ( L_31 , V_92 , V_85 , V_85 -> V_219 ) ;
F_199 ( V_85 ) ;
F_194 ( V_85 ) ;
F_198 ( & V_85 -> V_102 ) ;
F_62 ( V_85 ) ;
}
static void F_202 ( struct V_37 * V_85 , int V_313 )
{
F_14 ( L_33 , V_92 , V_85 , V_85 -> V_219 , V_313 ) ;
F_199 ( V_85 ) ;
F_187 ( V_85 , V_313 ) ;
}
static void F_203 ( struct V_4 * V_5 , T_2 V_315 )
{
if ( F_204 ( V_315 > V_5 -> V_246 ) ) {
F_14 ( L_34 ,
V_5 -> V_246 , V_315 ) ;
V_5 -> V_246 = V_315 ;
if ( V_315 > V_5 -> V_227 -> V_245 )
F_178 ( V_5 ) ;
}
}
void F_205 ( struct V_4 * V_5 , T_2 V_315 )
{
F_206 ( & V_5 -> V_6 ) ;
if ( F_2 ( V_315 > V_5 -> V_246 ) ) {
F_4 ( & V_5 -> V_6 ) ;
F_191 ( & V_5 -> V_6 ) ;
F_203 ( V_5 , V_315 ) ;
F_207 ( & V_5 -> V_6 ) ;
} else {
F_4 ( & V_5 -> V_6 ) ;
}
}
static void F_208 ( struct V_4 * V_5 )
{
struct V_217 * V_218 ;
bool V_316 = false ;
F_14 ( L_35 ) ;
if ( ! F_157 ( V_5 , V_242 ) && ! F_153 ( V_5 ) )
goto V_260;
for ( V_218 = F_134 ( & V_5 -> V_223 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_7 * V_8 = F_135 ( V_218 , struct V_7 , V_194 ) ;
struct V_217 * V_317 ;
V_317 = F_134 ( & V_8 -> V_196 ) ;
while ( V_317 ) {
struct V_37 * V_85 = F_135 ( V_317 ,
struct V_37 , V_86 ) ;
V_317 = F_136 ( V_317 ) ;
if ( V_85 -> V_185 ) {
V_316 = true ;
break;
}
}
if ( V_316 )
break;
}
if ( ! V_316 )
goto V_260;
F_203 ( V_5 , V_5 -> V_227 -> V_245 ) ;
for ( V_218 = F_134 ( & V_5 -> V_223 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_7 * V_8 = F_135 ( V_218 , struct V_7 , V_194 ) ;
struct V_217 * V_317 ;
V_317 = F_134 ( & V_8 -> V_196 ) ;
while ( V_317 ) {
struct V_37 * V_85 = F_135 ( V_317 ,
struct V_37 , V_86 ) ;
V_317 = F_136 ( V_317 ) ;
if ( V_85 -> V_185 &&
( F_157 ( V_5 , V_242 ) ||
F_154 ( V_5 , V_85 -> V_95 . V_71 . V_187 ) ) )
F_202 ( V_85 , - V_305 ) ;
}
}
V_260:
F_14 ( L_36 , V_5 -> V_246 ) ;
}
static void F_209 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_318 * V_319 = V_5 -> V_227 ;
F_8 ( V_5 ) ;
F_6 ( ! V_319 -> V_245 ) ;
if ( V_85 -> V_284 ) {
V_85 -> V_320 = V_319 -> V_245 ;
F_14 ( L_37 , V_92 , V_85 ,
V_85 -> V_219 ) ;
} else {
F_14 ( L_38 , V_92 ,
V_85 , V_85 -> V_219 , V_85 -> V_320 , V_319 -> V_245 ) ;
}
if ( V_85 -> V_320 ) {
if ( V_319 -> V_245 >= V_85 -> V_320 ) {
F_210 ( L_39 ,
V_85 -> V_219 ) ;
F_187 ( V_85 , - V_265 ) ;
}
} else {
F_189 ( V_85 ) ;
}
}
static void F_211 ( struct V_321 * V_322 )
{
struct V_4 * V_5 = & V_322 -> V_294 -> V_209 -> V_5 ;
struct V_37 * V_85 ;
T_1 V_292 = V_322 -> V_323 ;
F_6 ( V_322 -> V_324 || ! V_322 -> V_325 . V_326 ) ;
F_191 ( & V_5 -> V_6 ) ;
V_85 = F_195 ( & V_5 -> V_310 , V_292 ) ;
if ( ! V_85 ) {
F_14 ( L_40 , V_92 , V_292 ) ;
goto V_327;
}
F_14 ( L_41 , V_92 ,
V_85 , V_85 -> V_219 , V_85 -> V_320 , V_322 -> V_325 . V_326 ) ;
if ( ! V_85 -> V_320 )
V_85 -> V_320 = V_322 -> V_325 . V_326 ;
F_200 ( & V_5 -> V_310 , V_85 ) ;
F_209 ( V_85 ) ;
F_62 ( V_85 ) ;
V_327:
F_207 ( & V_5 -> V_6 ) ;
}
static void F_189 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
struct V_37 * V_314 ;
int V_258 ;
F_8 ( V_5 ) ;
V_314 = F_195 ( & V_5 -> V_310 , V_85 -> V_219 ) ;
if ( V_314 ) {
F_6 ( V_314 != V_85 ) ;
return;
}
F_59 ( V_85 ) ;
F_212 ( & V_5 -> V_310 , V_85 ) ;
V_258 = F_213 ( & V_5 -> V_209 -> V_294 , L_42 ,
F_211 , V_85 -> V_219 ) ;
F_6 ( V_258 ) ;
}
static void F_214 ( struct V_90 * V_90 )
{
struct V_10 * V_11 =
F_53 ( V_90 , struct V_10 , V_90 ) ;
F_14 ( L_43 , V_92 , V_11 ,
V_11 -> V_328 , V_11 -> V_329 ) ;
F_6 ( ! F_50 ( & V_11 -> V_221 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_330 ) ) ;
F_6 ( ! F_50 ( & V_11 -> V_331 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_332 ) ) ;
F_6 ( ! F_51 ( & V_11 -> V_333 ) ) ;
F_6 ( V_11 -> V_8 ) ;
if ( V_11 -> V_328 )
F_62 ( V_11 -> V_328 ) ;
if ( V_11 -> V_329 )
F_62 ( V_11 -> V_329 ) ;
F_46 ( & V_11 -> V_67 ) ;
F_58 ( V_11 ) ;
}
static void F_215 ( struct V_10 * V_11 )
{
if ( V_11 )
F_63 ( & V_11 -> V_90 , F_214 ) ;
}
static struct V_10 *
F_216 ( struct V_10 * V_11 )
{
F_61 ( & V_11 -> V_90 ) ;
return V_11 ;
}
static struct V_10 *
F_217 ( struct V_4 * V_5 )
{
struct V_10 * V_11 ;
V_11 = F_118 ( sizeof( * V_11 ) , V_205 ) ;
if ( ! V_11 )
return NULL ;
F_65 ( & V_11 -> V_90 ) ;
F_113 ( & V_11 -> V_6 ) ;
F_67 ( & V_11 -> V_221 ) ;
F_67 ( & V_11 -> V_330 ) ;
F_67 ( & V_11 -> V_331 ) ;
F_68 ( & V_11 -> V_332 ) ;
F_68 ( & V_11 -> V_333 ) ;
F_66 ( & V_11 -> V_334 ) ;
F_66 ( & V_11 -> V_335 ) ;
V_11 -> V_5 = V_5 ;
F_38 ( & V_11 -> V_67 ) ;
F_14 ( L_44 , V_92 , V_11 ) ;
return V_11 ;
}
static void F_140 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( ! V_11 -> V_222 || V_11 -> V_8 ) ;
F_14 ( L_45 , V_92 , V_8 ,
V_8 -> V_193 , V_11 , V_11 -> V_222 ) ;
if ( ! F_109 ( V_8 ) )
F_130 ( V_8 ) ;
else
F_148 ( & V_8 -> V_9 -> V_233 ) ;
F_120 ( V_8 ) ;
F_218 ( & V_8 -> V_198 , V_11 ) ;
V_11 -> V_8 = V_8 ;
}
static void F_139 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_9 ( V_8 ) ;
F_6 ( V_11 -> V_8 != V_8 ) ;
F_14 ( L_45 , V_92 , V_8 ,
V_8 -> V_193 , V_11 , V_11 -> V_222 ) ;
V_11 -> V_8 = NULL ;
F_219 ( & V_8 -> V_198 , V_11 ) ;
F_123 ( V_8 ) ;
if ( ! F_109 ( V_8 ) )
F_129 ( V_8 ) ;
else
F_151 ( & V_8 -> V_9 -> V_233 ) ;
}
static bool F_220 ( struct V_10 * V_11 )
{
F_5 ( V_11 -> V_5 ) ;
return ! F_50 ( & V_11 -> V_330 ) ;
}
static bool F_221 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
bool V_336 ;
F_206 ( & V_5 -> V_6 ) ;
V_336 = F_220 ( V_11 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_336 ;
}
static void F_222 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_6 ( V_11 -> V_222 ) ;
F_216 ( V_11 ) ;
V_11 -> V_222 = ++ V_5 -> V_337 ;
F_223 ( & V_5 -> V_338 , V_11 ) ;
}
static void F_224 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_8 ( V_5 ) ;
F_225 ( & V_5 -> V_338 , V_11 ) ;
F_215 ( V_11 ) ;
}
static void F_226 ( struct V_37 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_339 ;
F_6 ( ! V_85 -> V_110 ) ;
F_201 ( V_85 ) ;
F_215 ( V_11 ) ;
}
static struct V_340 * F_227 ( struct V_10 * V_11 ,
T_9 V_341 )
{
struct V_340 * V_342 ;
V_342 = F_118 ( sizeof( * V_342 ) , V_205 ) ;
if ( ! V_342 )
return NULL ;
F_228 ( & V_342 -> V_343 , V_341 ) ;
F_68 ( & V_342 -> V_344 ) ;
V_342 -> V_11 = F_216 ( V_11 ) ;
return V_342 ;
}
static void F_229 ( struct V_340 * V_342 )
{
struct V_10 * V_11 = V_342 -> V_11 ;
F_185 ( & V_11 -> V_6 ) ;
F_230 ( & V_342 -> V_344 ) ;
F_188 ( & V_11 -> V_6 ) ;
F_215 ( V_11 ) ;
F_58 ( V_342 ) ;
}
static void F_231 ( struct V_340 * V_342 )
{
struct V_10 * V_11 = V_342 -> V_11 ;
struct V_4 * V_5 = V_11 -> V_5 ;
F_11 ( V_11 ) ;
F_6 ( ! F_51 ( & V_342 -> V_344 ) ) ;
V_342 -> V_345 = V_214 ;
F_127 ( & V_342 -> V_344 , & V_11 -> V_333 ) ;
F_232 ( V_5 -> V_346 , & V_342 -> V_343 ) ;
}
static void F_233 ( struct V_347 * V_348 )
{
struct V_340 * V_342 = F_53 ( V_348 , struct V_340 , V_343 ) ;
struct V_10 * V_11 = V_342 -> V_11 ;
if ( ! F_221 ( V_11 ) ) {
F_14 ( L_46 , V_92 , V_11 ) ;
goto V_260;
}
F_6 ( ! V_11 -> V_349 ) ;
F_14 ( L_47 ,
V_92 , V_11 , V_342 -> V_63 . V_350 , V_342 -> V_63 . V_351 ,
V_342 -> V_63 . V_144 ) ;
V_11 -> V_352 ( V_11 -> V_272 , V_342 -> V_63 . V_350 , V_11 -> V_222 ,
V_342 -> V_63 . V_351 , V_342 -> V_63 . V_353 ,
V_342 -> V_63 . V_144 ) ;
V_260:
F_54 ( V_342 -> V_63 . V_123 ) ;
F_229 ( V_342 ) ;
}
static void F_234 ( struct V_347 * V_348 )
{
struct V_340 * V_342 = F_53 ( V_348 , struct V_340 , V_343 ) ;
struct V_10 * V_11 = V_342 -> V_11 ;
if ( ! F_221 ( V_11 ) ) {
F_14 ( L_46 , V_92 , V_11 ) ;
goto V_260;
}
F_14 ( L_48 , V_92 , V_11 , V_342 -> error . V_313 ) ;
V_11 -> V_354 ( V_11 -> V_272 , V_11 -> V_222 , V_342 -> error . V_313 ) ;
V_260:
F_229 ( V_342 ) ;
}
static void F_235 ( struct V_10 * V_11 )
{
struct V_340 * V_342 ;
V_342 = F_227 ( V_11 , F_234 ) ;
if ( ! V_342 ) {
F_100 ( L_49 ) ;
return;
}
V_342 -> error . V_313 = V_11 -> V_355 ;
F_231 ( V_342 ) ;
}
static void F_236 ( struct V_10 * V_11 ,
int V_324 )
{
if ( ! F_237 ( & V_11 -> V_334 ) ) {
V_11 -> V_356 = ( V_324 <= 0 ? V_324 : 0 ) ;
F_198 ( & V_11 -> V_334 ) ;
}
}
static void F_238 ( struct V_37 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_339 ;
F_185 ( & V_11 -> V_6 ) ;
F_14 ( L_50 , V_92 , V_11 ,
V_11 -> V_222 , V_85 -> V_312 ) ;
F_236 ( V_11 , V_85 -> V_312 ) ;
V_11 -> V_357 = true ;
if ( ! V_11 -> V_349 ) {
struct V_21 * V_22 =
F_22 ( V_85 , 0 , V_63 , V_48 ) ;
void * V_274 = F_239 ( V_22 -> V_25 [ 0 ] ) ;
F_6 ( V_85 -> V_41 [ 0 ] . V_51 != V_62 ||
V_22 -> type != V_30 ) ;
if ( V_85 -> V_41 [ 0 ] . V_150 >= sizeof( T_1 ) ) {
V_11 -> V_350 = F_240 ( & V_274 ) ;
F_14 ( L_51 , V_11 ,
V_11 -> V_350 ) ;
} else {
F_14 ( L_52 , V_11 ) ;
}
}
F_188 ( & V_11 -> V_6 ) ;
F_215 ( V_11 ) ;
}
static int F_241 ( int V_313 )
{
if ( V_313 == - V_265 )
V_313 = - V_358 ;
return V_313 ;
}
static void F_242 ( struct V_37 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_339 ;
F_185 ( & V_11 -> V_6 ) ;
F_14 ( L_53 , V_92 ,
V_11 , V_11 -> V_222 , V_85 -> V_312 , V_11 -> V_355 ) ;
if ( V_85 -> V_312 < 0 ) {
if ( ! V_11 -> V_355 ) {
V_11 -> V_355 = F_241 ( V_85 -> V_312 ) ;
F_235 ( V_11 ) ;
}
}
F_188 ( & V_11 -> V_6 ) ;
F_215 ( V_11 ) ;
}
static void F_243 ( struct V_10 * V_11 )
{
struct V_37 * V_85 = V_11 -> V_328 ;
struct V_50 * V_51 = & V_85 -> V_41 [ 0 ] ;
F_8 ( V_85 -> V_98 ) ;
F_14 ( L_54 , V_92 , V_11 , V_11 -> V_222 ) ;
if ( V_85 -> V_89 )
F_226 ( V_85 ) ;
F_69 ( V_85 ) ;
F_43 ( & V_85 -> V_125 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_85 -> V_126 , & V_11 -> V_67 . V_69 ) ;
V_85 -> V_186 = V_11 -> V_67 . V_83 ;
V_85 -> V_277 = V_11 -> V_359 ;
F_185 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_349 && V_11 -> V_357 ) {
F_6 ( V_51 -> V_51 != V_166 ||
V_51 -> V_167 . V_164 != V_11 -> V_222 ) ;
V_51 -> V_167 . V_51 = V_360 ;
V_51 -> V_167 . V_168 = ++ V_11 -> V_361 ;
F_14 ( L_55 , V_11 ,
V_51 -> V_167 . V_168 ) ;
V_85 -> V_311 = F_242 ;
} else {
if ( ! V_11 -> V_349 )
V_11 -> V_350 = 0 ;
else
F_6 ( V_51 -> V_167 . V_51 != V_362 ) ;
F_14 ( L_56 , V_11 ) ;
V_85 -> V_311 = F_238 ;
}
F_188 ( & V_11 -> V_6 ) ;
V_85 -> V_339 = F_216 ( V_11 ) ;
V_85 -> V_110 = true ;
F_193 ( V_85 , true ) ;
}
static void F_244 ( struct V_37 * V_85 )
{
struct V_10 * V_11 = V_85 -> V_339 ;
F_185 ( & V_11 -> V_6 ) ;
F_14 ( L_57 ,
V_92 , V_11 , V_11 -> V_222 , V_85 -> V_312 , V_11 -> V_363 ,
V_11 -> V_355 ) ;
if ( V_11 -> V_361 == V_85 -> V_41 [ 0 ] . V_167 . V_168 ) {
if ( ! V_85 -> V_312 ) {
V_11 -> V_364 = V_11 -> V_363 ;
} else if ( ! V_11 -> V_355 ) {
V_11 -> V_355 = F_241 ( V_85 -> V_312 ) ;
F_235 ( V_11 ) ;
}
} else {
F_14 ( L_58 , V_11 ,
V_11 -> V_361 , V_85 -> V_41 [ 0 ] . V_167 . V_168 ) ;
}
F_188 ( & V_11 -> V_6 ) ;
F_215 ( V_11 ) ;
}
static void F_245 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_37 * V_85 = V_11 -> V_329 ;
struct V_50 * V_51 = & V_85 -> V_41 [ 0 ] ;
if ( F_157 ( V_5 , V_239 ) ) {
F_14 ( L_59 , V_92 ) ;
return;
}
V_11 -> V_363 = V_214 ;
F_14 ( L_60 ,
V_92 , V_11 , V_11 -> V_222 , V_11 -> V_363 ,
V_11 -> V_361 ) ;
if ( V_85 -> V_89 )
F_226 ( V_85 ) ;
F_69 ( V_85 ) ;
F_42 ( & V_85 -> V_95 , & V_11 -> V_67 ) ;
F_6 ( V_51 -> V_51 != V_166 ||
V_51 -> V_167 . V_164 != V_11 -> V_222 ||
V_51 -> V_167 . V_51 != V_365 ) ;
V_51 -> V_167 . V_168 = V_11 -> V_361 ;
V_85 -> V_311 = F_244 ;
V_85 -> V_339 = F_216 ( V_11 ) ;
V_85 -> V_110 = true ;
F_59 ( V_85 ) ;
F_192 ( V_85 ) ;
V_85 -> V_219 = F_186 ( & V_5 -> V_304 ) ;
F_138 ( V_11 -> V_8 , V_85 ) ;
F_174 ( V_85 ) ;
}
static void F_246 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_7 * V_8 ;
F_158 ( V_5 , & V_11 -> V_67 , & V_11 -> V_248 , false ) ;
V_8 = F_145 ( V_5 , V_11 -> V_67 . V_8 , true ) ;
F_140 ( V_8 , V_11 ) ;
F_243 ( V_11 ) ;
}
static void F_247 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_10 * V_366 ;
F_8 ( V_5 ) ;
V_366 = F_248 ( & V_5 -> V_367 ,
V_11 -> V_222 ) ;
if ( ! V_366 )
return;
F_6 ( V_366 != V_11 ) ;
F_249 ( & V_5 -> V_367 , V_11 ) ;
F_215 ( V_11 ) ;
}
static void F_250 ( struct V_10 * V_11 )
{
if ( V_11 -> V_349 && V_11 -> V_329 -> V_89 )
F_226 ( V_11 -> V_329 ) ;
if ( V_11 -> V_328 -> V_89 )
F_226 ( V_11 -> V_328 ) ;
F_247 ( V_11 ) ;
F_139 ( V_11 -> V_8 , V_11 ) ;
F_224 ( V_11 ) ;
}
static void F_251 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
F_191 ( & V_5 -> V_6 ) ;
if ( F_220 ( V_11 ) )
F_250 ( V_11 ) ;
F_207 ( & V_5 -> V_6 ) ;
}
static void F_252 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_318 * V_319 = V_5 -> V_227 ;
F_8 ( V_5 ) ;
F_6 ( ! V_319 -> V_245 ) ;
if ( V_11 -> V_361 ) {
V_11 -> V_368 = V_319 -> V_245 ;
F_14 ( L_61 , V_92 ,
V_11 , V_11 -> V_222 ) ;
} else {
F_14 ( L_62 ,
V_92 , V_11 , V_11 -> V_222 , V_11 -> V_368 ,
V_319 -> V_245 ) ;
}
if ( V_11 -> V_368 ) {
if ( V_319 -> V_245 >= V_11 -> V_368 ) {
F_253 ( L_63 ,
V_11 -> V_222 ) ;
F_236 ( V_11 , - V_265 ) ;
F_250 ( V_11 ) ;
}
} else {
F_254 ( V_11 ) ;
}
}
static void F_255 ( struct V_321 * V_322 )
{
struct V_4 * V_5 = & V_322 -> V_294 -> V_209 -> V_5 ;
struct V_10 * V_11 ;
T_1 V_222 = V_322 -> V_323 ;
F_6 ( V_322 -> V_324 || ! V_322 -> V_325 . V_326 ) ;
F_191 ( & V_5 -> V_6 ) ;
V_11 = F_248 ( & V_5 -> V_367 , V_222 ) ;
if ( ! V_11 ) {
F_14 ( L_64 , V_92 , V_222 ) ;
goto V_327;
}
F_14 ( L_65 ,
V_92 , V_11 , V_11 -> V_222 , V_11 -> V_368 ,
V_322 -> V_325 . V_326 ) ;
if ( ! V_11 -> V_368 )
V_11 -> V_368 = V_322 -> V_325 . V_326 ;
F_249 ( & V_5 -> V_367 , V_11 ) ;
F_252 ( V_11 ) ;
F_215 ( V_11 ) ;
V_327:
F_207 ( & V_5 -> V_6 ) ;
}
static void F_254 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_10 * V_366 ;
int V_258 ;
F_8 ( V_5 ) ;
V_366 = F_248 ( & V_5 -> V_367 ,
V_11 -> V_222 ) ;
if ( V_366 ) {
F_6 ( V_366 != V_11 ) ;
return;
}
F_216 ( V_11 ) ;
F_256 ( & V_5 -> V_367 , V_11 ) ;
V_258 = F_213 ( & V_5 -> V_209 -> V_294 , L_42 ,
F_255 , V_11 -> V_222 ) ;
F_6 ( V_258 ) ;
}
static int F_257 ( struct V_10 * V_11 )
{
int V_258 ;
F_14 ( L_54 , V_92 , V_11 , V_11 -> V_222 ) ;
V_258 = F_258 ( & V_11 -> V_334 ) ;
return V_258 ? : V_11 -> V_356 ;
}
static int F_259 ( struct V_10 * V_11 )
{
int V_258 ;
F_14 ( L_54 , V_92 , V_11 , V_11 -> V_222 ) ;
V_258 = F_258 ( & V_11 -> V_335 ) ;
return V_258 ? : V_11 -> V_369 ;
}
static void F_260 ( struct V_347 * V_343 )
{
struct V_4 * V_5 =
F_53 ( V_343 , struct V_4 , V_370 . V_343 ) ;
struct V_371 * V_372 = V_5 -> V_209 -> V_215 ;
unsigned long V_373 = V_214 - V_372 -> V_374 ;
unsigned long V_375 = V_214 - V_372 -> V_376 ;
F_261 ( V_377 ) ;
struct V_217 * V_218 , * V_274 ;
F_14 ( L_66 , V_92 , V_5 ) ;
F_191 ( & V_5 -> V_6 ) ;
for ( V_218 = F_134 ( & V_5 -> V_223 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_7 * V_8 = F_135 ( V_218 , struct V_7 , V_194 ) ;
bool V_378 = false ;
for ( V_274 = F_134 ( & V_8 -> V_196 ) ; V_274 ; ) {
struct V_37 * V_85 =
F_135 ( V_274 , struct V_37 , V_86 ) ;
V_274 = F_136 ( V_274 ) ;
if ( F_262 ( V_85 -> V_229 , V_373 ) ) {
F_14 ( L_67 ,
V_85 , V_85 -> V_219 , V_8 -> V_193 ) ;
V_378 = true ;
}
if ( V_372 -> V_376 &&
F_262 ( V_85 -> V_309 , V_375 ) ) {
F_263 ( L_68 ,
V_85 -> V_219 , V_8 -> V_193 ) ;
F_202 ( V_85 , - V_379 ) ;
}
}
for ( V_274 = F_134 ( & V_8 -> V_198 ) ; V_274 ; V_274 = F_136 ( V_274 ) ) {
struct V_10 * V_11 =
F_135 ( V_274 , struct V_10 , V_221 ) ;
F_14 ( L_69 ,
V_11 , V_11 -> V_222 , V_8 -> V_193 ) ;
V_378 = true ;
F_185 ( & V_11 -> V_6 ) ;
if ( V_11 -> V_349 && V_11 -> V_357 && ! V_11 -> V_355 )
F_245 ( V_11 ) ;
F_188 ( & V_11 -> V_6 ) ;
}
if ( V_378 )
F_264 ( & V_8 -> V_200 , & V_377 ) ;
}
if ( V_372 -> V_376 ) {
for ( V_274 = F_134 ( & V_5 -> V_220 . V_196 ) ; V_274 ; ) {
struct V_37 * V_85 =
F_135 ( V_274 , struct V_37 , V_86 ) ;
V_274 = F_136 ( V_274 ) ;
if ( F_262 ( V_85 -> V_309 , V_375 ) ) {
F_263 ( L_68 ,
V_85 -> V_219 , V_5 -> V_220 . V_193 ) ;
F_202 ( V_85 , - V_379 ) ;
}
}
}
if ( F_265 ( & V_5 -> V_233 ) || ! F_51 ( & V_377 ) )
F_178 ( V_5 ) ;
while ( ! F_51 ( & V_377 ) ) {
struct V_7 * V_8 = F_266 ( & V_377 ,
struct V_7 ,
V_200 ) ;
F_131 ( & V_8 -> V_200 ) ;
F_267 ( & V_8 -> V_207 ) ;
}
F_207 ( & V_5 -> V_6 ) ;
F_268 ( & V_5 -> V_370 ,
V_5 -> V_209 -> V_215 -> V_374 ) ;
}
static void F_269 ( struct V_347 * V_343 )
{
struct V_4 * V_5 =
F_53 ( V_343 , struct V_4 ,
V_380 . V_343 ) ;
unsigned long V_381 = V_5 -> V_209 -> V_215 -> V_216 / 4 ;
struct V_7 * V_8 , * V_382 ;
F_14 ( L_66 , V_92 , V_5 ) ;
F_191 ( & V_5 -> V_6 ) ;
F_270 (osd, nosd, &osdc->osd_lru, o_osd_lru) {
if ( F_262 ( V_214 , V_8 -> V_213 ) )
break;
F_6 ( ! F_115 ( & V_8 -> V_196 ) ) ;
F_6 ( ! F_115 ( & V_8 -> V_198 ) ) ;
F_132 ( V_8 ) ;
}
F_207 ( & V_5 -> V_6 ) ;
F_268 ( & V_5 -> V_380 ,
F_271 ( V_381 ) ) ;
}
static int F_272 ( void * * V_274 , void * V_275 ,
struct V_118 * V_119 )
{
T_7 V_383 , V_384 ;
T_2 V_121 ;
void * V_385 ;
int V_258 = 0 ;
F_273 ( V_274 , V_275 , 1 + 1 + 4 , V_386 ) ;
V_383 = F_274 ( V_274 ) ;
V_384 = F_274 ( V_274 ) ;
if ( V_383 < 3 ) {
F_275 ( L_70 ,
V_383 , V_384 ) ;
goto V_386;
}
if ( V_384 > 6 ) {
F_275 ( L_71 ,
V_383 , V_384 ) ;
goto V_386;
}
V_121 = F_276 ( V_274 ) ;
F_273 ( V_274 , V_275 , V_121 , V_386 ) ;
V_385 = * V_274 + V_121 ;
V_119 -> V_187 = F_240 ( V_274 ) ;
* V_274 += 4 ;
V_121 = F_276 ( V_274 ) ;
if ( V_121 > 0 ) {
F_275 ( L_72 ) ;
goto V_386;
}
if ( V_383 >= 5 ) {
bool V_387 = false ;
V_121 = F_276 ( V_274 ) ;
if ( V_121 > 0 ) {
F_273 ( V_274 , V_275 , V_121 , V_386 ) ;
if ( ! V_119 -> V_120 ||
F_277 ( V_119 -> V_120 , * V_274 , V_121 ) )
V_387 = true ;
* V_274 += V_121 ;
} else {
if ( V_119 -> V_120 )
V_387 = true ;
}
if ( V_387 ) {
F_275 ( L_73 ) ;
goto V_386;
}
}
if ( V_383 >= 6 ) {
T_8 V_388 = F_240 ( V_274 ) ;
if ( V_388 != - 1 ) {
F_275 ( L_74 ) ;
goto V_386;
}
}
* V_274 = V_385 ;
V_260:
return V_258 ;
V_386:
V_258 = - V_389 ;
goto V_260;
}
static int F_278 ( void * * V_274 , void * V_275 ,
struct V_390 * V_391 )
{
T_7 V_383 , V_384 ;
T_2 V_121 ;
void * V_385 ;
int V_258 ;
F_273 ( V_274 , V_275 , 1 + 1 + 4 , V_386 ) ;
V_383 = F_274 ( V_274 ) ;
V_384 = F_274 ( V_274 ) ;
if ( V_384 > 1 ) {
F_275 ( L_75 ,
V_383 , V_384 ) ;
goto V_386;
}
V_121 = F_276 ( V_274 ) ;
F_273 ( V_274 , V_275 , V_121 , V_386 ) ;
V_385 = * V_274 + V_121 ;
V_258 = F_272 ( V_274 , V_275 , & V_391 -> V_119 ) ;
if ( V_258 )
goto V_260;
V_121 = F_276 ( V_274 ) ;
if ( V_121 > 0 ) {
F_275 ( L_76 ) ;
goto V_386;
}
V_121 = F_276 ( V_274 ) ;
* V_274 += V_121 ;
* V_274 = V_385 ;
V_260:
return V_258 ;
V_386:
V_258 = - V_389 ;
goto V_260;
}
static int F_279 ( const struct V_111 * V_123 , struct V_392 * V_317 )
{
void * V_274 = V_123 -> V_134 . V_135 ;
void * const V_275 = V_274 + V_123 -> V_134 . V_136 ;
T_5 V_286 = F_280 ( V_123 -> V_285 . V_286 ) ;
struct V_281 V_393 ;
T_7 V_394 ;
T_2 V_121 ;
int V_258 ;
int V_271 ;
F_281 ( & V_274 , V_275 , V_121 , V_386 ) ;
F_273 ( & V_274 , V_275 , V_121 , V_386 ) ;
V_274 += V_121 ;
V_258 = F_282 ( & V_274 , V_275 , & V_317 -> V_79 ) ;
if ( V_258 )
return V_258 ;
F_283 ( & V_274 , V_275 , V_317 -> V_83 , V_386 ) ;
F_281 ( & V_274 , V_275 , V_317 -> V_324 , V_386 ) ;
F_273 ( & V_274 , V_275 , sizeof( V_393 ) , V_386 ) ;
memcpy ( & V_393 , V_274 , sizeof( V_393 ) ) ;
V_274 += sizeof( V_393 ) ;
F_281 ( & V_274 , V_275 , V_317 -> V_245 , V_386 ) ;
F_281 ( & V_274 , V_275 , V_317 -> V_104 , V_386 ) ;
if ( V_317 -> V_104 > F_284 ( V_317 -> V_150 ) )
goto V_386;
F_273 ( & V_274 , V_275 , V_317 -> V_104 * sizeof( struct V_129 ) ,
V_386 ) ;
for ( V_271 = 0 ; V_271 < V_317 -> V_104 ; V_271 ++ ) {
struct V_129 * V_51 = V_274 ;
V_317 -> V_150 [ V_271 ] = F_285 ( V_51 -> V_144 ) ;
V_274 += sizeof( * V_51 ) ;
}
F_281 ( & V_274 , V_275 , V_317 -> V_395 , V_386 ) ;
for ( V_271 = 0 ; V_271 < V_317 -> V_104 ; V_271 ++ )
F_281 ( & V_274 , V_275 , V_317 -> V_396 [ V_271 ] , V_386 ) ;
if ( V_286 >= 5 ) {
F_273 ( & V_274 , V_275 , sizeof( V_317 -> V_397 ) , V_386 ) ;
memcpy ( & V_317 -> V_397 , V_274 , sizeof( V_317 -> V_397 ) ) ;
V_274 += sizeof( V_317 -> V_397 ) ;
F_283 ( & V_274 , V_275 , V_317 -> V_398 , V_386 ) ;
} else {
V_317 -> V_397 = V_393 ;
V_317 -> V_398 = F_286 ( V_317 -> V_397 . V_286 ) ;
}
if ( V_286 >= 6 ) {
if ( V_286 >= 7 )
F_287 ( & V_274 , V_275 , V_394 , V_386 ) ;
else
V_394 = 1 ;
} else {
V_394 = 0 ;
}
if ( V_394 ) {
V_258 = F_278 ( & V_274 , V_275 , & V_317 -> V_399 ) ;
if ( V_258 )
return V_258 ;
} else {
F_40 ( & V_317 -> V_399 . V_119 ) ;
}
return 0 ;
V_386:
return - V_389 ;
}
static void F_288 ( struct V_7 * V_8 , struct V_111 * V_123 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_37 * V_85 ;
struct V_392 V_317 ;
T_1 V_292 = F_286 ( V_123 -> V_285 . V_292 ) ;
T_2 V_270 = 0 ;
int V_258 ;
int V_271 ;
F_14 ( L_77 , V_92 , V_123 , V_292 ) ;
F_206 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_78 , V_92 , V_8 -> V_193 ) ;
goto V_400;
}
F_6 ( V_8 -> V_193 != F_286 ( V_123 -> V_285 . V_78 . V_401 ) ) ;
F_185 ( & V_8 -> V_6 ) ;
V_85 = F_289 ( & V_8 -> V_196 , V_292 ) ;
if ( ! V_85 ) {
F_14 ( L_79 , V_92 , V_8 -> V_193 , V_292 ) ;
goto V_402;
}
V_317 . V_399 . V_119 . V_120 = V_85 -> V_95 . V_71 . V_120 ;
V_258 = F_279 ( V_123 , & V_317 ) ;
V_317 . V_399 . V_119 . V_120 = NULL ;
if ( V_258 ) {
F_100 ( L_80 ,
V_85 -> V_219 , V_258 ) ;
F_290 ( V_123 ) ;
goto V_403;
}
F_14 ( L_81 ,
V_92 , V_85 , V_85 -> V_219 , V_317 . V_83 , V_317 . V_79 . V_187 , V_317 . V_79 . V_266 ,
V_317 . V_245 , V_317 . V_395 , F_285 ( V_317 . V_397 . V_245 ) ,
F_286 ( V_317 . V_397 . V_286 ) , V_317 . V_398 ) ;
if ( V_317 . V_395 >= 0 ) {
if ( V_317 . V_395 != V_85 -> V_284 - 1 ) {
F_14 ( L_82 ,
V_85 , V_85 -> V_219 , V_317 . V_395 ,
V_85 -> V_284 - 1 ) ;
goto V_402;
}
} else {
F_6 ( 1 ) ;
}
if ( ! F_78 ( & V_317 . V_399 . V_119 ) ) {
F_14 ( L_83 , V_85 , V_85 -> V_219 ,
V_317 . V_399 . V_119 . V_187 ) ;
F_137 ( V_8 , V_85 ) ;
F_188 ( & V_8 -> V_6 ) ;
V_85 -> V_95 . V_71 . V_187 = V_317 . V_399 . V_119 . V_187 ;
V_85 -> V_186 |= V_404 ;
V_85 -> V_219 = 0 ;
F_181 ( V_85 , false ) ;
goto V_400;
}
if ( V_317 . V_104 != V_85 -> V_40 ) {
F_100 ( L_84 , V_317 . V_104 ,
V_85 -> V_40 , V_85 -> V_219 ) ;
goto V_403;
}
for ( V_271 = 0 ; V_271 < V_85 -> V_40 ; V_271 ++ ) {
F_14 ( L_85 , V_85 ,
V_85 -> V_219 , V_271 , V_317 . V_396 [ V_271 ] , V_317 . V_150 [ V_271 ] ) ;
V_85 -> V_41 [ V_271 ] . V_396 = V_317 . V_396 [ V_271 ] ;
V_85 -> V_41 [ V_271 ] . V_150 = V_317 . V_150 [ V_271 ] ;
V_270 += V_317 . V_150 [ V_271 ] ;
}
if ( V_270 != F_285 ( V_123 -> V_285 . V_270 ) ) {
F_100 ( L_86 , V_270 ,
F_285 ( V_123 -> V_285 . V_270 ) , V_85 -> V_219 ) ;
goto V_403;
}
F_14 ( L_87 , V_92 ,
V_85 , V_85 -> V_219 , V_317 . V_324 , V_270 ) ;
F_6 ( ! ( V_317 . V_83 & V_307 ) ) ;
V_85 -> V_312 = V_317 . V_324 ? : V_270 ;
F_194 ( V_85 ) ;
F_188 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_197 ( V_85 ) ;
F_198 ( & V_85 -> V_102 ) ;
F_62 ( V_85 ) ;
return;
V_403:
F_187 ( V_85 , - V_405 ) ;
V_402:
F_188 ( & V_8 -> V_6 ) ;
V_400:
F_4 ( & V_5 -> V_6 ) ;
}
static void F_291 ( struct V_4 * V_5 )
{
struct V_217 * V_218 ;
for ( V_218 = F_134 ( & V_5 -> V_227 -> V_237 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_234 * V_235 =
F_135 ( V_218 , struct V_234 , V_221 ) ;
V_235 -> V_406 = F_152 ( V_235 ) ;
}
}
static bool F_292 ( struct V_4 * V_5 , T_8 V_188 )
{
struct V_234 * V_235 ;
V_235 = F_155 ( V_5 -> V_227 , V_188 ) ;
if ( ! V_235 )
return false ;
return V_235 -> V_406 && ! F_152 ( V_235 ) ;
}
static enum V_247
F_293 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
enum V_247 V_257 ;
V_257 = F_158 ( V_5 , & V_11 -> V_67 , & V_11 -> V_248 , true ) ;
if ( V_257 == V_268 ) {
struct V_7 * V_8 ;
V_8 = F_145 ( V_5 , V_11 -> V_67 . V_8 , true ) ;
if ( V_8 != V_11 -> V_8 ) {
F_139 ( V_11 -> V_8 , V_11 ) ;
F_140 ( V_8 , V_11 ) ;
}
}
return V_257 ;
}
static void F_294 ( struct V_7 * V_8 ,
bool V_253 ,
bool V_407 ,
bool V_408 ,
struct V_409 * V_255 ,
struct V_410 * V_411 )
{
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_217 * V_218 ;
bool V_412 ;
for ( V_218 = F_134 ( & V_8 -> V_198 ) ; V_218 ; ) {
struct V_10 * V_11 =
F_135 ( V_218 , struct V_10 , V_221 ) ;
enum V_247 V_257 ;
V_218 = F_136 ( V_218 ) ;
F_14 ( L_54 , V_92 , V_11 ,
V_11 -> V_222 ) ;
V_257 = F_293 ( V_11 ) ;
switch ( V_257 ) {
case V_269 :
V_412 = V_407 ||
( V_408 &&
F_292 ( V_5 , V_11 -> V_67 . V_69 . V_187 ) ) ;
if ( ! V_253 && ! V_412 )
break;
case V_268 :
F_247 ( V_11 ) ;
if ( F_51 ( & V_11 -> V_332 ) )
F_127 ( & V_11 -> V_332 , V_411 ) ;
break;
case V_259 :
F_252 ( V_11 ) ;
break;
}
}
for ( V_218 = F_134 ( & V_8 -> V_196 ) ; V_218 ; ) {
struct V_37 * V_85 =
F_135 ( V_218 , struct V_37 , V_86 ) ;
enum V_247 V_257 ;
V_218 = F_136 ( V_218 ) ;
F_14 ( L_31 , V_92 , V_85 , V_85 -> V_219 ) ;
V_257 = F_158 ( V_5 , & V_85 -> V_95 ,
& V_85 -> V_300 , false ) ;
switch ( V_257 ) {
case V_269 :
V_412 = V_407 ||
( V_408 &&
F_292 ( V_5 , V_85 -> V_95 . V_69 . V_187 ) ) ;
if ( ! V_253 &&
( ! ( V_85 -> V_186 & V_191 ) ||
! V_412 ) )
break;
case V_268 :
F_199 ( V_85 ) ;
F_137 ( V_8 , V_85 ) ;
F_149 ( V_255 , V_85 ) ;
break;
case V_259 :
F_209 ( V_85 ) ;
break;
}
}
}
static int F_295 ( struct V_4 * V_5 ,
void * V_274 , void * V_275 , bool V_413 ,
struct V_409 * V_255 ,
struct V_410 * V_411 )
{
struct V_318 * V_414 ;
struct V_217 * V_218 ;
bool V_415 = false ;
bool V_406 ;
V_406 = F_157 ( V_5 , V_242 ) ;
F_291 ( V_5 ) ;
if ( V_413 )
V_414 = F_296 ( & V_274 , V_275 , V_5 -> V_227 ) ;
else
V_414 = F_297 ( & V_274 , V_275 ) ;
if ( F_182 ( V_414 ) )
return F_183 ( V_414 ) ;
if ( V_414 != V_5 -> V_227 ) {
for ( V_218 = F_134 ( & V_414 -> V_237 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_234 * V_235 =
F_135 ( V_218 , struct V_234 , V_221 ) ;
struct V_234 * V_416 ;
V_416 = F_155 ( V_5 -> V_227 , V_235 -> V_243 ) ;
if ( V_416 )
V_235 -> V_406 = V_416 -> V_406 ;
else
F_6 ( V_235 -> V_406 ) ;
}
if ( V_5 -> V_227 -> V_245 &&
V_5 -> V_227 -> V_245 + 1 < V_414 -> V_245 ) {
F_6 ( V_413 ) ;
V_415 = true ;
}
F_298 ( V_5 -> V_227 ) ;
V_5 -> V_227 = V_414 ;
}
V_406 &= ! F_157 ( V_5 , V_242 ) ;
F_294 ( & V_5 -> V_220 , V_415 , V_406 , true ,
V_255 , V_411 ) ;
for ( V_218 = F_134 ( & V_5 -> V_223 ) ; V_218 ; ) {
struct V_7 * V_8 = F_135 ( V_218 , struct V_7 , V_194 ) ;
V_218 = F_136 ( V_218 ) ;
F_294 ( V_8 , V_415 , V_406 , true , V_255 ,
V_411 ) ;
if ( ! F_299 ( V_5 -> V_227 , V_8 -> V_193 ) ||
memcmp ( & V_8 -> V_207 . V_225 ,
F_300 ( V_5 -> V_227 , V_8 -> V_193 ) ,
sizeof( struct V_224 ) ) )
F_132 ( V_8 ) ;
}
return 0 ;
}
static void F_301 ( struct V_4 * V_5 ,
struct V_409 * V_255 ,
struct V_410 * V_411 )
{
struct V_10 * V_11 , * V_417 ;
struct V_217 * V_218 ;
for ( V_218 = F_134 ( V_255 ) ; V_218 ; ) {
struct V_37 * V_85 =
F_135 ( V_218 , struct V_37 , V_86 ) ;
struct V_7 * V_8 ;
V_218 = F_136 ( V_218 ) ;
F_150 ( V_255 , V_85 ) ;
F_6 ( V_85 -> V_89 ) ;
F_158 ( V_5 , & V_85 -> V_95 , NULL , false ) ;
V_8 = F_145 ( V_5 , V_85 -> V_95 . V_8 , true ) ;
F_138 ( V_8 , V_85 ) ;
if ( ! V_85 -> V_110 ) {
if ( ! F_109 ( V_8 ) && ! V_85 -> V_95 . V_84 )
F_174 ( V_85 ) ;
} else {
F_226 ( V_85 ) ;
}
}
F_270 (lreq, nlreq, need_resend_linger, scan_item) {
if ( ! F_109 ( V_11 -> V_8 ) )
F_243 ( V_11 ) ;
F_131 ( & V_11 -> V_332 ) ;
}
}
void F_302 ( struct V_4 * V_5 , struct V_111 * V_123 )
{
void * V_274 = V_123 -> V_134 . V_135 ;
void * const V_275 = V_274 + V_123 -> V_134 . V_136 ;
T_2 V_418 , V_419 ;
T_2 V_245 ;
struct V_420 V_421 ;
struct V_409 V_255 = V_197 ;
F_261 ( V_411 ) ;
bool V_422 = false ;
bool V_423 , V_424 ;
bool V_238 , V_240 ;
int V_313 ;
F_14 ( L_88 , V_92 , V_5 -> V_227 -> V_245 ) ;
F_191 ( & V_5 -> V_6 ) ;
F_273 ( & V_274 , V_275 , sizeof( V_421 ) , V_425 ) ;
F_303 ( & V_274 , & V_421 , sizeof( V_421 ) ) ;
if ( F_304 ( V_5 -> V_209 , & V_421 ) < 0 )
goto V_425;
V_423 = F_157 ( V_5 , V_239 ) ;
V_424 = F_157 ( V_5 , V_241 ) ||
F_157 ( V_5 , V_242 ) ||
F_153 ( V_5 ) ;
F_281 ( & V_274 , V_275 , V_418 , V_425 ) ;
F_14 ( L_89 , V_418 ) ;
while ( V_418 > 0 ) {
F_273 ( & V_274 , V_275 , 2 * sizeof( T_2 ) , V_425 ) ;
V_245 = F_276 ( & V_274 ) ;
V_419 = F_276 ( & V_274 ) ;
F_273 ( & V_274 , V_275 , V_419 , V_425 ) ;
if ( V_5 -> V_227 -> V_245 &&
V_5 -> V_227 -> V_245 + 1 == V_245 ) {
F_14 ( L_90 ,
V_245 , V_419 ) ;
V_313 = F_295 ( V_5 , V_274 , V_274 + V_419 , true ,
& V_255 , & V_411 ) ;
if ( V_313 )
goto V_425;
V_422 = true ;
} else {
F_14 ( L_91 ,
V_245 , V_419 ) ;
}
V_274 += V_419 ;
V_418 -- ;
}
if ( V_422 )
goto V_426;
F_281 ( & V_274 , V_275 , V_418 , V_425 ) ;
F_14 ( L_92 , V_418 ) ;
while ( V_418 ) {
F_273 ( & V_274 , V_275 , 2 * sizeof( T_2 ) , V_425 ) ;
V_245 = F_276 ( & V_274 ) ;
V_419 = F_276 ( & V_274 ) ;
F_273 ( & V_274 , V_275 , V_419 , V_425 ) ;
if ( V_418 > 1 ) {
F_14 ( L_93 ,
V_245 , V_419 ) ;
} else if ( V_5 -> V_227 -> V_245 >= V_245 ) {
F_14 ( L_94
L_95 , V_245 , V_419 ,
V_5 -> V_227 -> V_245 ) ;
} else {
F_14 ( L_96 , V_245 , V_419 ) ;
V_313 = F_295 ( V_5 , V_274 , V_274 + V_419 , false ,
& V_255 , & V_411 ) ;
if ( V_313 )
goto V_425;
}
V_274 += V_419 ;
V_418 -- ;
}
V_426:
V_238 = F_157 ( V_5 , V_239 ) ;
V_240 = F_157 ( V_5 , V_241 ) ||
F_157 ( V_5 , V_242 ) ||
F_153 ( V_5 ) ;
if ( V_423 || V_424 || V_238 || V_240 ||
V_5 -> V_227 -> V_245 < V_5 -> V_246 )
F_178 ( V_5 ) ;
F_301 ( V_5 , & V_255 , & V_411 ) ;
F_208 ( V_5 ) ;
F_305 ( & V_5 -> V_209 -> V_294 , V_295 ,
V_5 -> V_227 -> V_245 ) ;
F_207 ( & V_5 -> V_6 ) ;
F_306 ( & V_5 -> V_209 -> V_427 ) ;
return;
V_425:
F_100 ( L_97 ) ;
F_290 ( V_123 ) ;
F_207 ( & V_5 -> V_6 ) ;
}
static void F_307 ( struct V_7 * V_8 )
{
struct V_217 * V_218 ;
for ( V_218 = F_134 ( & V_8 -> V_196 ) ; V_218 ; ) {
struct V_37 * V_85 =
F_135 ( V_218 , struct V_37 , V_86 ) ;
V_218 = F_136 ( V_218 ) ;
if ( ! V_85 -> V_110 ) {
if ( ! V_85 -> V_95 . V_84 )
F_174 ( V_85 ) ;
} else {
F_226 ( V_85 ) ;
}
}
for ( V_218 = F_134 ( & V_8 -> V_198 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_10 * V_11 =
F_135 ( V_218 , struct V_10 , V_221 ) ;
F_243 ( V_11 ) ;
}
}
static void F_308 ( struct V_428 * V_429 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
struct V_4 * V_5 = V_8 -> V_9 ;
F_14 ( L_13 , V_92 , V_8 , V_8 -> V_193 ) ;
F_191 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_78 , V_92 , V_8 -> V_193 ) ;
goto V_327;
}
if ( ! F_142 ( V_8 ) )
F_307 ( V_8 ) ;
F_178 ( V_5 ) ;
V_327:
F_207 ( & V_5 -> V_6 ) ;
}
static void F_309 ( struct V_4 * V_5 ,
struct V_111 * V_123 )
{
void * V_274 = V_123 -> V_134 . V_135 ;
void * const V_275 = V_274 + V_123 -> V_134 . V_136 ;
struct V_10 * V_11 ;
struct V_340 * V_342 ;
T_7 V_431 , V_140 ;
T_1 V_164 , V_350 ;
T_1 V_351 = 0 ;
T_10 V_432 = 0 ;
void * V_353 = NULL ;
T_2 V_144 = 0 ;
F_287 ( & V_274 , V_275 , V_431 , V_425 ) ;
F_287 ( & V_274 , V_275 , V_140 , V_425 ) ;
F_283 ( & V_274 , V_275 , V_164 , V_425 ) ;
V_274 += 8 ;
F_283 ( & V_274 , V_275 , V_350 , V_425 ) ;
if ( V_431 >= 1 ) {
F_281 ( & V_274 , V_275 , V_144 , V_425 ) ;
F_273 ( & V_274 , V_275 , V_144 , V_425 ) ;
V_353 = V_274 ;
V_274 += V_144 ;
}
if ( F_280 ( V_123 -> V_285 . V_286 ) >= 2 )
F_281 ( & V_274 , V_275 , V_432 , V_425 ) ;
if ( F_280 ( V_123 -> V_285 . V_286 ) >= 3 )
F_283 ( & V_274 , V_275 , V_351 , V_425 ) ;
F_206 ( & V_5 -> V_6 ) ;
V_11 = F_310 ( & V_5 -> V_338 , V_164 ) ;
if ( ! V_11 ) {
F_14 ( L_98 , V_92 , V_140 ,
V_164 ) ;
goto V_400;
}
F_185 ( & V_11 -> V_6 ) ;
F_14 ( L_99 , V_92 ,
V_140 , V_164 , V_11 , V_11 -> V_349 ) ;
if ( V_140 == V_433 ) {
if ( ! V_11 -> V_355 ) {
V_11 -> V_355 = - V_358 ;
F_235 ( V_11 ) ;
}
} else if ( ! V_11 -> V_349 ) {
if ( V_11 -> V_350 && V_11 -> V_350 != V_350 ) {
F_14 ( L_100 , V_11 ,
V_11 -> V_350 , V_350 ) ;
} else if ( ! F_237 ( & V_11 -> V_335 ) ) {
struct V_434 * V_272 =
F_311 ( & V_123 -> V_272 ,
struct V_434 ,
V_435 ) ;
if ( V_272 ) {
if ( V_11 -> V_436 ) {
F_6 ( V_272 -> type !=
V_437 ) ;
* V_11 -> V_436 = V_272 -> V_25 ;
* V_11 -> V_438 = V_272 -> V_26 ;
} else {
F_36 ( V_272 -> V_25 ,
F_35 ( 0 , V_272 -> V_26 ) ) ;
}
}
V_11 -> V_369 = V_432 ;
F_198 ( & V_11 -> V_335 ) ;
}
} else {
V_342 = F_227 ( V_11 , F_233 ) ;
if ( ! V_342 ) {
F_100 ( L_101 ) ;
goto V_439;
}
V_342 -> V_63 . V_350 = V_350 ;
V_342 -> V_63 . V_351 = V_351 ;
V_342 -> V_63 . V_353 = V_353 ;
V_342 -> V_63 . V_144 = V_144 ;
V_342 -> V_63 . V_123 = F_177 ( V_123 ) ;
F_231 ( V_342 ) ;
}
V_439:
F_188 ( & V_11 -> V_6 ) ;
V_400:
F_4 ( & V_5 -> V_6 ) ;
return;
V_425:
F_100 ( L_102 ) ;
}
int F_312 ( struct V_4 * V_5 ,
struct V_37 * V_85 ,
bool V_440 )
{
F_206 ( & V_5 -> V_6 ) ;
F_193 ( V_85 , false ) ;
F_4 ( & V_5 -> V_6 ) ;
return 0 ;
}
void F_313 ( struct V_37 * V_85 )
{
struct V_4 * V_5 = V_85 -> V_98 ;
F_191 ( & V_5 -> V_6 ) ;
if ( V_85 -> V_89 )
F_201 ( V_85 ) ;
F_207 ( & V_5 -> V_6 ) ;
}
static int F_314 ( struct V_37 * V_85 ,
unsigned long V_441 )
{
long V_442 ;
F_14 ( L_31 , V_92 , V_85 , V_85 -> V_219 ) ;
V_442 = F_315 ( & V_85 -> V_102 ,
F_316 ( V_441 ) ) ;
if ( V_442 <= 0 ) {
V_442 = V_442 ? : - V_379 ;
F_313 ( V_85 ) ;
} else {
V_442 = V_85 -> V_312 ;
}
return V_442 ;
}
int F_317 ( struct V_4 * V_5 ,
struct V_37 * V_85 )
{
return F_314 ( V_85 , 0 ) ;
}
void F_318 ( struct V_4 * V_5 )
{
struct V_217 * V_218 , * V_274 ;
T_1 V_304 = F_319 ( & V_5 -> V_304 ) ;
V_299:
F_206 ( & V_5 -> V_6 ) ;
for ( V_218 = F_134 ( & V_5 -> V_223 ) ; V_218 ; V_218 = F_136 ( V_218 ) ) {
struct V_7 * V_8 = F_135 ( V_218 , struct V_7 , V_194 ) ;
F_185 ( & V_8 -> V_6 ) ;
for ( V_274 = F_134 ( & V_8 -> V_196 ) ; V_274 ; V_274 = F_136 ( V_274 ) ) {
struct V_37 * V_85 =
F_135 ( V_274 , struct V_37 , V_86 ) ;
if ( V_85 -> V_219 > V_304 )
break;
if ( ! ( V_85 -> V_186 & V_191 ) )
continue;
F_59 ( V_85 ) ;
F_188 ( & V_8 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_103 ,
V_92 , V_85 , V_85 -> V_219 , V_304 ) ;
F_320 ( & V_85 -> V_102 ) ;
F_62 ( V_85 ) ;
goto V_299;
}
F_188 ( & V_8 -> V_6 ) ;
}
F_4 ( & V_5 -> V_6 ) ;
F_14 ( L_104 , V_92 , V_304 ) ;
}
static struct V_37 *
F_321 ( struct V_10 * V_11 )
{
struct V_37 * V_85 ;
V_85 = F_70 ( V_11 -> V_5 , NULL , 1 , false , V_205 ) ;
if ( ! V_85 )
return NULL ;
F_43 ( & V_85 -> V_125 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_85 -> V_126 , & V_11 -> V_67 . V_69 ) ;
if ( F_76 ( V_85 , V_205 ) ) {
F_62 ( V_85 ) ;
return NULL ;
}
return V_85 ;
}
struct V_10 *
F_322 ( struct V_4 * V_5 ,
struct V_443 * V_444 ,
struct V_118 * V_119 ,
T_11 V_352 ,
T_12 V_354 ,
void * V_272 )
{
struct V_10 * V_11 ;
int V_258 ;
V_11 = F_217 ( V_5 ) ;
if ( ! V_11 )
return F_108 ( - V_133 ) ;
V_11 -> V_349 = true ;
V_11 -> V_352 = V_352 ;
V_11 -> V_354 = V_354 ;
V_11 -> V_272 = V_272 ;
V_11 -> V_364 = V_214 ;
F_43 ( & V_11 -> V_67 . V_68 , V_444 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_119 ) ;
V_11 -> V_67 . V_83 = V_191 ;
F_323 ( & V_11 -> V_359 ) ;
V_11 -> V_328 = F_321 ( V_11 ) ;
if ( ! V_11 -> V_328 ) {
V_258 = - V_133 ;
goto V_445;
}
V_11 -> V_329 = F_321 ( V_11 ) ;
if ( ! V_11 -> V_329 ) {
V_258 = - V_133 ;
goto V_445;
}
F_191 ( & V_5 -> V_6 ) ;
F_222 ( V_11 ) ;
F_93 ( V_11 -> V_328 , 0 , V_11 -> V_222 ,
V_362 ) ;
F_93 ( V_11 -> V_329 , 0 , V_11 -> V_222 ,
V_365 ) ;
F_246 ( V_11 ) ;
F_207 ( & V_5 -> V_6 ) ;
V_258 = F_257 ( V_11 ) ;
if ( V_258 ) {
F_251 ( V_11 ) ;
goto V_445;
}
return V_11 ;
V_445:
F_215 ( V_11 ) ;
return F_108 ( V_258 ) ;
}
int F_324 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
struct V_371 * V_372 = V_5 -> V_209 -> V_215 ;
struct V_37 * V_85 ;
int V_258 ;
V_85 = F_70 ( V_5 , NULL , 1 , false , V_205 ) ;
if ( ! V_85 )
return - V_133 ;
F_43 ( & V_85 -> V_125 , & V_11 -> V_67 . V_68 ) ;
F_44 ( & V_85 -> V_126 , & V_11 -> V_67 . V_69 ) ;
V_85 -> V_186 = V_191 ;
F_323 ( & V_85 -> V_277 ) ;
F_93 ( V_85 , 0 , V_11 -> V_222 ,
V_446 ) ;
V_258 = F_76 ( V_85 , V_205 ) ;
if ( V_258 )
goto V_447;
F_312 ( V_5 , V_85 , false ) ;
F_251 ( V_11 ) ;
F_215 ( V_11 ) ;
V_258 = F_314 ( V_85 , V_372 -> V_448 ) ;
V_447:
F_62 ( V_85 ) ;
return V_258 ;
}
static int F_325 ( struct V_37 * V_85 , int V_39 ,
T_1 V_350 , T_1 V_164 , void * V_353 ,
T_3 V_144 )
{
struct V_50 * V_51 ;
struct V_31 * V_449 ;
int V_258 ;
V_51 = F_84 ( V_85 , V_39 , V_60 , 0 ) ;
V_449 = F_73 ( sizeof( * V_449 ) , V_205 ) ;
if ( ! V_449 )
return - V_133 ;
F_90 ( V_449 ) ;
V_258 = F_326 ( V_449 , V_350 ) ;
V_258 |= F_326 ( V_449 , V_164 ) ;
if ( V_353 ) {
V_258 |= F_327 ( V_449 , V_144 ) ;
V_258 |= F_91 ( V_449 , V_353 , V_144 ) ;
} else {
V_258 |= F_327 ( V_449 , 0 ) ;
}
if ( V_258 ) {
F_328 ( V_449 ) ;
return - V_133 ;
}
F_17 ( & V_51 -> V_61 . V_46 , V_449 ) ;
V_51 -> V_47 = V_449 -> V_26 ;
return 0 ;
}
int F_329 ( struct V_4 * V_5 ,
struct V_443 * V_444 ,
struct V_118 * V_119 ,
T_1 V_350 ,
T_1 V_164 ,
void * V_353 ,
T_3 V_144 )
{
struct V_37 * V_85 ;
int V_258 ;
V_85 = F_70 ( V_5 , NULL , 1 , false , V_205 ) ;
if ( ! V_85 )
return - V_133 ;
F_43 ( & V_85 -> V_125 , V_444 ) ;
F_44 ( & V_85 -> V_126 , V_119 ) ;
V_85 -> V_186 = V_244 ;
V_258 = F_76 ( V_85 , V_205 ) ;
if ( V_258 )
goto V_447;
V_258 = F_325 ( V_85 , 0 , V_350 , V_164 , V_353 ,
V_144 ) ;
if ( V_258 )
goto V_447;
F_312 ( V_5 , V_85 , false ) ;
V_258 = F_317 ( V_5 , V_85 ) ;
V_447:
F_62 ( V_85 ) ;
return V_258 ;
}
static int F_330 ( struct V_37 * V_85 , int V_39 ,
T_1 V_164 , T_2 V_450 , T_2 V_441 ,
void * V_353 , T_3 V_144 )
{
struct V_50 * V_51 ;
struct V_31 * V_449 ;
int V_258 ;
V_51 = F_84 ( V_85 , V_39 , V_62 , 0 ) ;
V_51 -> V_63 . V_164 = V_164 ;
V_449 = F_73 ( sizeof( * V_449 ) , V_205 ) ;
if ( ! V_449 )
return - V_133 ;
F_90 ( V_449 ) ;
V_258 = F_327 ( V_449 , 1 ) ;
V_258 |= F_327 ( V_449 , V_441 ) ;
V_258 |= F_327 ( V_449 , V_144 ) ;
V_258 |= F_91 ( V_449 , V_353 , V_144 ) ;
if ( V_258 ) {
F_328 ( V_449 ) ;
return - V_133 ;
}
F_17 ( & V_51 -> V_63 . V_46 , V_449 ) ;
V_51 -> V_47 = V_449 -> V_26 ;
return 0 ;
}
int F_331 ( struct V_4 * V_5 ,
struct V_443 * V_444 ,
struct V_118 * V_119 ,
void * V_353 ,
T_3 V_144 ,
T_2 V_441 ,
struct V_24 * * * V_436 ,
T_3 * V_438 )
{
struct V_10 * V_11 ;
struct V_24 * * V_25 ;
int V_258 ;
F_6 ( ! V_441 ) ;
if ( V_436 ) {
* V_436 = NULL ;
* V_438 = 0 ;
}
V_11 = F_217 ( V_5 ) ;
if ( ! V_11 )
return - V_133 ;
V_11 -> V_436 = V_436 ;
V_11 -> V_438 = V_438 ;
F_43 ( & V_11 -> V_67 . V_68 , V_444 ) ;
F_44 ( & V_11 -> V_67 . V_69 , V_119 ) ;
V_11 -> V_67 . V_83 = V_244 ;
V_11 -> V_328 = F_321 ( V_11 ) ;
if ( ! V_11 -> V_328 ) {
V_258 = - V_133 ;
goto V_451;
}
V_25 = F_332 ( 1 , V_205 ) ;
if ( F_182 ( V_25 ) ) {
V_258 = F_183 ( V_25 ) ;
goto V_451;
}
F_191 ( & V_5 -> V_6 ) ;
F_222 ( V_11 ) ;
V_258 = F_330 ( V_11 -> V_328 , 0 , V_11 -> V_222 , 1 ,
V_441 , V_353 , V_144 ) ;
if ( V_258 ) {
F_224 ( V_11 ) ;
F_207 ( & V_5 -> V_6 ) ;
F_36 ( V_25 , 1 ) ;
goto V_451;
}
F_16 ( F_22 ( V_11 -> V_328 , 0 , V_63 ,
V_48 ) ,
V_25 , V_452 , 0 , false , true ) ;
F_246 ( V_11 ) ;
F_207 ( & V_5 -> V_6 ) ;
V_258 = F_257 ( V_11 ) ;
if ( ! V_258 )
V_258 = F_259 ( V_11 ) ;
else
F_14 ( L_105 , V_11 , V_258 ) ;
F_251 ( V_11 ) ;
V_451:
F_215 ( V_11 ) ;
return V_258 ;
}
int F_333 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
unsigned long V_453 , V_454 ;
int V_258 ;
F_206 ( & V_5 -> V_6 ) ;
F_185 ( & V_11 -> V_6 ) ;
V_453 = V_11 -> V_364 ;
if ( ! F_51 ( & V_11 -> V_333 ) ) {
struct V_340 * V_342 =
F_266 ( & V_11 -> V_333 ,
struct V_340 ,
V_344 ) ;
if ( F_262 ( V_342 -> V_345 , V_453 ) )
V_453 = V_342 -> V_345 ;
}
V_454 = V_214 - V_453 ;
F_14 ( L_106 , V_92 ,
V_11 , V_11 -> V_222 , V_454 , V_11 -> V_355 ) ;
V_258 = V_11 -> V_355 ? : 1 + F_334 ( V_454 ) ;
F_188 ( & V_11 -> V_6 ) ;
F_4 ( & V_5 -> V_6 ) ;
return V_258 ;
}
static int F_335 ( void * * V_274 , void * V_275 , struct V_455 * V_456 )
{
T_7 V_383 ;
T_2 V_457 ;
int V_258 ;
V_258 = F_336 ( V_274 , V_275 , 2 , L_107 ,
& V_383 , & V_457 ) ;
if ( V_258 )
return V_258 ;
F_303 ( V_274 , & V_456 -> V_159 , sizeof( V_456 -> V_159 ) ) ;
V_456 -> V_164 = F_240 ( V_274 ) ;
* V_274 += 4 ;
if ( V_383 >= 2 ) {
F_303 ( V_274 , & V_456 -> V_458 , sizeof( V_456 -> V_458 ) ) ;
F_337 ( & V_456 -> V_458 ) ;
}
F_14 ( L_108 , V_92 ,
F_338 ( V_456 -> V_159 ) , V_456 -> V_164 ,
F_339 ( & V_456 -> V_458 . V_459 ) ) ;
return 0 ;
}
static int F_340 ( void * * V_274 , void * V_275 ,
struct V_455 * * V_460 ,
T_2 * V_461 )
{
T_7 V_383 ;
T_2 V_457 ;
int V_271 ;
int V_258 ;
V_258 = F_336 ( V_274 , V_275 , 1 , L_109 ,
& V_383 , & V_457 ) ;
if ( V_258 )
return V_258 ;
* V_461 = F_276 ( V_274 ) ;
* V_460 = F_341 ( * V_461 , sizeof( * * V_460 ) , V_205 ) ;
if ( ! * V_460 )
return - V_133 ;
for ( V_271 = 0 ; V_271 < * V_461 ; V_271 ++ ) {
V_258 = F_335 ( V_274 , V_275 , * V_460 + V_271 ) ;
if ( V_258 ) {
F_58 ( * V_460 ) ;
return V_258 ;
}
}
return 0 ;
}
int F_342 ( struct V_4 * V_5 ,
struct V_443 * V_444 ,
struct V_118 * V_119 ,
struct V_455 * * V_460 ,
T_2 * V_461 )
{
struct V_37 * V_85 ;
struct V_24 * * V_25 ;
int V_258 ;
V_85 = F_70 ( V_5 , NULL , 1 , false , V_205 ) ;
if ( ! V_85 )
return - V_133 ;
F_43 ( & V_85 -> V_125 , V_444 ) ;
F_44 ( & V_85 -> V_126 , V_119 ) ;
V_85 -> V_186 = V_244 ;
V_258 = F_76 ( V_85 , V_205 ) ;
if ( V_258 )
goto V_447;
V_25 = F_332 ( 1 , V_205 ) ;
if ( F_182 ( V_25 ) ) {
V_258 = F_183 ( V_25 ) ;
goto V_447;
}
F_85 ( V_85 , 0 , V_64 , 0 ) ;
F_16 ( F_22 ( V_85 , 0 , V_65 ,
V_48 ) ,
V_25 , V_452 , 0 , false , true ) ;
F_312 ( V_5 , V_85 , false ) ;
V_258 = F_317 ( V_5 , V_85 ) ;
if ( V_258 >= 0 ) {
void * V_274 = F_239 ( V_25 [ 0 ] ) ;
void * const V_275 = V_274 + V_85 -> V_41 [ 0 ] . V_150 ;
V_258 = F_340 ( & V_274 , V_275 , V_460 , V_461 ) ;
}
V_447:
F_62 ( V_85 ) ;
return V_258 ;
}
void F_343 ( struct V_4 * V_5 )
{
F_14 ( L_66 , V_92 , V_5 ) ;
F_344 ( V_5 -> V_346 ) ;
}
void F_345 ( struct V_4 * V_5 )
{
F_206 ( & V_5 -> V_6 ) ;
F_178 ( V_5 ) ;
F_4 ( & V_5 -> V_6 ) ;
}
int F_346 ( struct V_4 * V_5 ,
struct V_443 * V_444 ,
struct V_118 * V_119 ,
const char * V_151 , const char * V_152 ,
unsigned int V_83 ,
struct V_24 * V_462 , T_3 V_463 ,
struct V_24 * V_464 , T_3 * V_465 )
{
struct V_37 * V_85 ;
int V_258 ;
if ( V_463 > V_452 || ( V_464 && * V_465 > V_452 ) )
return - V_466 ;
V_85 = F_70 ( V_5 , NULL , 1 , false , V_205 ) ;
if ( ! V_85 )
return - V_133 ;
F_43 ( & V_85 -> V_125 , V_444 ) ;
F_44 ( & V_85 -> V_126 , V_119 ) ;
V_85 -> V_186 = V_83 ;
V_258 = F_76 ( V_85 , V_205 ) ;
if ( V_258 )
goto V_447;
F_89 ( V_85 , 0 , V_55 , V_151 , V_152 ) ;
if ( V_462 )
F_29 ( V_85 , 0 , & V_462 , V_463 ,
0 , false , false ) ;
if ( V_464 )
F_30 ( V_85 , 0 , & V_464 ,
* V_465 , 0 , false , false ) ;
F_312 ( V_5 , V_85 , false ) ;
V_258 = F_317 ( V_5 , V_85 ) ;
if ( V_258 >= 0 ) {
V_258 = V_85 -> V_41 [ 0 ] . V_396 ;
if ( V_464 )
* V_465 = V_85 -> V_41 [ 0 ] . V_150 ;
}
V_447:
F_62 ( V_85 ) ;
return V_258 ;
}
int F_347 ( struct V_4 * V_5 , struct V_467 * V_209 )
{
int V_313 ;
F_14 ( L_110 ) ;
V_5 -> V_209 = V_209 ;
F_348 ( & V_5 -> V_6 ) ;
V_5 -> V_223 = V_197 ;
F_68 ( & V_5 -> V_212 ) ;
F_349 ( & V_5 -> V_211 ) ;
F_111 ( & V_5 -> V_220 ) ;
V_5 -> V_220 . V_9 = V_5 ;
V_5 -> V_220 . V_193 = V_76 ;
V_5 -> V_337 = V_468 ;
V_5 -> V_338 = V_197 ;
V_5 -> V_310 = V_197 ;
V_5 -> V_367 = V_197 ;
F_350 ( & V_5 -> V_370 , F_260 ) ;
F_350 ( & V_5 -> V_380 , F_269 ) ;
V_313 = - V_133 ;
V_5 -> V_227 = F_351 () ;
if ( ! V_5 -> V_227 )
goto V_260;
V_5 -> V_99 = F_352 ( 10 ,
V_101 ) ;
if ( ! V_5 -> V_99 )
goto V_469;
V_313 = F_353 ( & V_5 -> V_131 , V_132 ,
V_452 , 10 , true , L_111 ) ;
if ( V_313 < 0 )
goto V_470;
V_313 = F_353 ( & V_5 -> V_138 , V_139 ,
V_452 , 10 , true , L_112 ) ;
if ( V_313 < 0 )
goto V_471;
V_313 = - V_133 ;
V_5 -> V_346 = F_354 ( L_113 ) ;
if ( ! V_5 -> V_346 )
goto V_472;
F_268 ( & V_5 -> V_370 ,
V_5 -> V_209 -> V_215 -> V_374 ) ;
F_268 ( & V_5 -> V_380 ,
F_271 ( V_5 -> V_209 -> V_215 -> V_216 ) ) ;
return 0 ;
V_472:
F_355 ( & V_5 -> V_138 ) ;
V_471:
F_355 ( & V_5 -> V_131 ) ;
V_470:
F_356 ( V_5 -> V_99 ) ;
V_469:
F_298 ( V_5 -> V_227 ) ;
V_260:
return V_313 ;
}
void F_357 ( struct V_4 * V_5 )
{
F_344 ( V_5 -> V_346 ) ;
F_358 ( V_5 -> V_346 ) ;
F_359 ( & V_5 -> V_370 ) ;
F_359 ( & V_5 -> V_380 ) ;
F_191 ( & V_5 -> V_6 ) ;
while ( ! F_115 ( & V_5 -> V_223 ) ) {
struct V_7 * V_8 = F_135 ( F_134 ( & V_5 -> V_223 ) ,
struct V_7 , V_194 ) ;
F_132 ( V_8 ) ;
}
F_207 ( & V_5 -> V_6 ) ;
F_6 ( F_122 ( & V_5 -> V_220 . V_195 ) != 1 ) ;
F_114 ( & V_5 -> V_220 ) ;
F_6 ( ! F_51 ( & V_5 -> V_212 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_338 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_310 ) ) ;
F_6 ( ! F_115 ( & V_5 -> V_367 ) ) ;
F_6 ( F_265 ( & V_5 -> V_308 ) ) ;
F_6 ( F_265 ( & V_5 -> V_233 ) ) ;
F_298 ( V_5 -> V_227 ) ;
F_356 ( V_5 -> V_99 ) ;
F_355 ( & V_5 -> V_131 ) ;
F_355 ( & V_5 -> V_138 ) ;
}
int F_360 ( struct V_4 * V_5 ,
struct V_180 V_181 , struct V_12 * V_13 ,
T_1 V_14 , T_1 * V_15 ,
T_2 V_143 , T_1 V_142 ,
struct V_24 * * V_25 , int V_49 , int V_473 )
{
struct V_37 * V_85 ;
int V_474 = 0 ;
F_14 ( L_114 , V_181 . V_189 ,
V_181 . V_190 , V_14 , * V_15 ) ;
V_85 = F_105 ( V_5 , V_13 , V_181 , V_14 , V_15 , 0 , 1 ,
V_52 , V_244 ,
NULL , V_143 , V_142 ,
false ) ;
if ( F_182 ( V_85 ) )
return F_183 ( V_85 ) ;
F_24 ( V_85 , 0 ,
V_25 , * V_15 , V_473 , false , false ) ;
F_14 ( L_115 ,
V_14 , * V_15 , * V_15 , V_473 ) ;
V_474 = F_312 ( V_5 , V_85 , false ) ;
if ( ! V_474 )
V_474 = F_317 ( V_5 , V_85 ) ;
F_62 ( V_85 ) ;
F_14 ( L_116 , V_474 ) ;
return V_474 ;
}
int F_361 ( struct V_4 * V_5 , struct V_180 V_181 ,
struct V_12 * V_13 ,
struct V_107 * V_108 ,
T_1 V_14 , T_1 V_121 ,
T_2 V_143 , T_1 V_142 ,
struct V_475 * V_359 ,
struct V_24 * * V_25 , int V_49 )
{
struct V_37 * V_85 ;
int V_474 = 0 ;
int V_473 = V_14 & ~ V_476 ;
V_85 = F_105 ( V_5 , V_13 , V_181 , V_14 , & V_121 , 0 , 1 ,
V_53 , V_191 ,
V_108 , V_143 , V_142 ,
true ) ;
if ( F_182 ( V_85 ) )
return F_183 ( V_85 ) ;
F_24 ( V_85 , 0 , V_25 , V_121 , V_473 ,
false , false ) ;
F_14 ( L_117 , V_14 , V_121 , V_121 ) ;
V_85 -> V_277 = * V_359 ;
V_474 = F_312 ( V_5 , V_85 , true ) ;
if ( ! V_474 )
V_474 = F_317 ( V_5 , V_85 ) ;
F_62 ( V_85 ) ;
if ( V_474 == 0 )
V_474 = V_121 ;
F_14 ( L_118 , V_474 ) ;
return V_474 ;
}
int F_362 ( void )
{
T_3 V_74 = sizeof( struct V_37 ) +
V_100 * sizeof( struct V_50 ) ;
F_20 ( V_101 ) ;
V_101 = F_363 ( L_119 , V_74 ,
0 , 0 , NULL ) ;
return V_101 ? 0 : - V_133 ;
}
void F_364 ( void )
{
F_20 ( ! V_101 ) ;
F_365 ( V_101 ) ;
V_101 = NULL ;
}
static void F_366 ( struct V_428 * V_429 , struct V_111 * V_123 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
struct V_4 * V_5 = V_8 -> V_9 ;
int type = F_280 ( V_123 -> V_285 . type ) ;
switch ( type ) {
case V_477 :
F_302 ( V_5 , V_123 ) ;
break;
case V_139 :
F_288 ( V_8 , V_123 ) ;
break;
case V_478 :
F_309 ( V_5 , V_123 ) ;
break;
default:
F_100 ( L_120 , type ,
F_367 ( type ) ) ;
}
F_54 ( V_123 ) ;
}
static struct V_111 * F_368 ( struct V_428 * V_429 ,
struct V_479 * V_285 ,
int * V_480 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
struct V_4 * V_5 = V_8 -> V_9 ;
struct V_111 * V_317 = NULL ;
struct V_37 * V_85 ;
int V_287 = F_285 ( V_285 -> V_287 ) ;
int V_270 = F_285 ( V_285 -> V_270 ) ;
T_1 V_292 = F_286 ( V_285 -> V_292 ) ;
F_206 ( & V_5 -> V_6 ) ;
if ( ! F_110 ( V_8 ) ) {
F_14 ( L_121 , V_92 , V_8 -> V_193 ) ;
* V_480 = 1 ;
goto V_400;
}
F_6 ( V_8 -> V_193 != F_286 ( V_285 -> V_78 . V_401 ) ) ;
F_185 ( & V_8 -> V_6 ) ;
V_85 = F_289 ( & V_8 -> V_196 , V_292 ) ;
if ( ! V_85 ) {
F_14 ( L_122 , V_92 ,
V_8 -> V_193 , V_292 ) ;
* V_480 = 1 ;
goto V_402;
}
F_196 ( V_85 -> V_94 ) ;
if ( V_287 > V_85 -> V_94 -> V_276 ) {
F_275 ( L_123 ,
V_92 , V_8 -> V_193 , V_85 -> V_219 , V_287 ,
V_85 -> V_94 -> V_276 ) ;
V_317 = F_80 ( V_139 , V_287 , V_153 ,
false ) ;
if ( ! V_317 )
goto V_402;
F_54 ( V_85 -> V_94 ) ;
V_85 -> V_94 = V_317 ;
}
if ( V_270 > V_85 -> V_94 -> V_273 ) {
F_275 ( L_124 ,
V_92 , V_8 -> V_193 , V_85 -> V_219 , V_270 ,
V_85 -> V_94 -> V_273 ) ;
V_317 = NULL ;
* V_480 = 1 ;
goto V_402;
}
V_317 = F_177 ( V_85 -> V_94 ) ;
F_14 ( L_125 , V_292 , V_317 ) ;
V_402:
F_188 ( & V_8 -> V_6 ) ;
V_400:
F_4 ( & V_5 -> V_6 ) ;
return V_317 ;
}
static struct V_111 * F_369 ( struct V_479 * V_285 )
{
struct V_111 * V_317 ;
int type = F_280 ( V_285 -> type ) ;
T_2 V_287 = F_285 ( V_285 -> V_287 ) ;
T_2 V_270 = F_285 ( V_285 -> V_270 ) ;
V_317 = F_80 ( type , V_287 , V_205 , false ) ;
if ( ! V_317 )
return NULL ;
if ( V_270 ) {
struct V_24 * * V_25 ;
struct V_21 V_22 ;
V_25 = F_332 ( F_35 ( 0 , V_270 ) ,
V_205 ) ;
if ( F_182 ( V_25 ) ) {
F_54 ( V_317 ) ;
return NULL ;
}
F_16 ( & V_22 , V_25 , V_270 , 0 , false ,
false ) ;
F_95 ( V_317 , & V_22 ) ;
}
return V_317 ;
}
static struct V_111 * F_370 ( struct V_428 * V_429 ,
struct V_479 * V_285 ,
int * V_480 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
int type = F_280 ( V_285 -> type ) ;
* V_480 = 0 ;
switch ( type ) {
case V_477 :
case V_478 :
return F_369 ( V_285 ) ;
case V_139 :
return F_368 ( V_429 , V_285 , V_480 ) ;
default:
F_275 ( L_126 , V_92 ,
V_8 -> V_193 , type ) ;
* V_480 = 1 ;
return NULL ;
}
}
static struct V_428 * F_371 ( struct V_428 * V_429 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
if ( F_120 ( V_8 ) )
return V_429 ;
return NULL ;
}
static void F_372 ( struct V_428 * V_429 )
{
struct V_7 * V_8 = V_429 -> V_430 ;
F_123 ( V_8 ) ;
}
static struct V_481 * F_373 ( struct V_428 * V_429 ,
int * V_482 , int V_483 )
{
struct V_7 * V_232 = V_429 -> V_430 ;
struct V_4 * V_5 = V_232 -> V_9 ;
struct V_484 * V_485 = V_5 -> V_209 -> V_294 . V_486 ;
struct V_481 * V_486 = & V_232 -> V_202 ;
if ( V_483 && V_486 -> V_203 ) {
F_116 ( V_486 -> V_203 ) ;
V_486 -> V_203 = NULL ;
}
if ( ! V_486 -> V_203 ) {
int V_258 = F_374 ( V_485 , V_231 ,
V_486 ) ;
if ( V_258 )
return F_108 ( V_258 ) ;
} else {
int V_258 = F_375 ( V_485 , V_231 ,
V_486 ) ;
if ( V_258 )
return F_108 ( V_258 ) ;
}
* V_482 = V_485 -> V_487 ;
return V_486 ;
}
static int F_376 ( struct V_428 * V_429 )
{
struct V_7 * V_232 = V_429 -> V_430 ;
struct V_4 * V_5 = V_232 -> V_9 ;
struct V_484 * V_485 = V_5 -> V_209 -> V_294 . V_486 ;
return F_377 ( V_485 , V_232 -> V_202 . V_203 ) ;
}
static int F_378 ( struct V_428 * V_429 )
{
struct V_7 * V_232 = V_429 -> V_430 ;
struct V_4 * V_5 = V_232 -> V_9 ;
struct V_484 * V_485 = V_5 -> V_209 -> V_294 . V_486 ;
F_379 ( V_485 , V_231 ) ;
return F_380 ( & V_5 -> V_209 -> V_294 ) ;
}
static int F_381 ( struct V_111 * V_123 )
{
struct V_7 * V_232 = V_123 -> V_429 -> V_430 ;
struct V_481 * V_486 = & V_232 -> V_202 ;
return F_382 ( V_486 , V_123 ) ;
}
static int F_383 ( struct V_111 * V_123 )
{
struct V_7 * V_232 = V_123 -> V_429 -> V_430 ;
struct V_481 * V_486 = & V_232 -> V_202 ;
return F_384 ( V_486 , V_123 ) ;
}
