static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( ( V_5 & F_2 ( V_2 -> V_6 - 1 , 0 ) ) != V_5 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_4 -> V_8 = F_4 ( V_5 ) ;
V_4 -> V_9 = ( V_10 ) F_5 ( V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
V_10 V_15 = F_7 ( V_12 -> V_16 ) ;
V_14 -> V_17 = F_8 ( V_12 -> V_18 , V_15 , & V_14 -> V_19 ,
V_20 ) ;
if ( ! V_14 -> V_17 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
V_14 -> V_24 = 1 ;
V_14 -> V_25 = NULL ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_26 * V_27 = & V_12 -> V_27 ;
V_10 V_15 = F_10 ( V_12 -> V_16 ) ;
V_27 -> V_17 = F_8 ( V_12 -> V_18 , V_15 , & V_27 -> V_19 ,
V_20 ) ;
if ( ! V_27 -> V_17 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_27 -> V_22 = 0 ;
V_27 -> V_24 = 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_28 -> V_32 ;
T_2 V_33 , V_34 , V_35 ;
V_10 V_15 ;
V_28 -> V_32 . V_16 = V_36 ;
V_15 = F_12 ( V_36 ) ;
V_32 -> V_17 = F_8 ( V_28 -> V_37 , V_15 , & V_32 -> V_19 ,
V_20 ) ;
if ( ! V_32 -> V_17 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_32 -> V_22 = V_32 -> V_16 ;
V_32 -> V_24 = 1 ;
V_33 = F_13 ( V_32 -> V_19 ) ;
V_34 = F_14 ( V_32 -> V_19 ) ;
F_15 ( V_33 , V_28 -> V_38 + V_39 ) ;
F_15 ( V_34 , V_28 -> V_38 + V_40 ) ;
V_35 = 0 ;
V_35 |= V_28 -> V_32 . V_16 & V_41 ;
V_35 |= ( sizeof( struct V_42 )
<< V_43 ) &
V_44 ;
F_15 ( V_35 , V_28 -> V_38 + V_45 ) ;
if ( F_16 ( ! V_30 ) ) {
F_3 ( L_3 ) ;
return - V_7 ;
}
V_32 -> V_30 = V_30 ;
return 0 ;
}
static inline void F_17 ( struct V_11 * V_12 ,
struct V_46 * V_47 )
{
V_47 -> V_48 = false ;
F_18 ( & V_12 -> V_49 ) ;
}
static struct V_46 * F_19 ( struct V_11 * V_12 ,
V_10 V_50 , bool V_51 )
{
if ( F_16 ( V_50 >= V_12 -> V_16 ) ) {
F_3 ( L_4 ,
V_50 , V_12 -> V_16 ) ;
return NULL ;
}
if ( F_16 ( V_12 -> V_47 [ V_50 ] . V_48 && V_51 ) ) {
F_3 ( L_5 ) ;
return NULL ;
}
if ( V_51 ) {
F_20 ( & V_12 -> V_49 ) ;
V_12 -> V_47 [ V_50 ] . V_48 = true ;
}
return & V_12 -> V_47 [ V_50 ] ;
}
static struct V_46 * F_21 ( struct V_11 * V_52 ,
struct V_53 * V_54 ,
T_3 V_55 ,
struct V_56 * V_57 ,
T_3 V_58 )
{
struct V_46 * V_47 ;
V_10 V_59 , V_60 ;
V_10 V_61 ;
V_10 V_62 ;
V_61 = V_52 -> V_16 - 1 ;
V_59 = V_52 -> V_14 . V_23 & V_61 ;
V_62 = F_22 ( & V_52 -> V_49 ) ;
if ( V_62 >= V_52 -> V_16 ) {
F_23 ( L_6 ) ;
V_52 -> V_63 . V_64 ++ ;
return F_24 ( - V_65 ) ;
}
V_60 = V_52 -> V_66 ;
V_54 -> V_67 . V_68 |= V_52 -> V_14 . V_24 &
V_69 ;
V_54 -> V_67 . V_50 |= V_60 &
V_70 ;
V_47 = F_19 ( V_52 , V_60 , true ) ;
if ( F_16 ( ! V_47 ) )
return F_24 ( - V_7 ) ;
V_47 -> V_71 = V_72 ;
V_47 -> V_73 = ( T_2 ) V_58 ;
V_47 -> V_74 = V_57 ;
V_47 -> V_75 = V_54 -> V_67 . V_76 ;
F_25 ( & V_47 -> V_77 ) ;
memcpy ( & V_52 -> V_14 . V_17 [ V_59 ] , V_54 , V_55 ) ;
V_52 -> V_66 = ( V_52 -> V_66 + 1 ) &
V_61 ;
V_52 -> V_14 . V_23 ++ ;
V_52 -> V_63 . V_78 ++ ;
if ( F_16 ( ( V_52 -> V_14 . V_23 & V_61 ) == 0 ) )
V_52 -> V_14 . V_24 = ! V_52 -> V_14 . V_24 ;
F_15 ( V_52 -> V_14 . V_23 , V_52 -> V_14 . V_25 ) ;
return V_47 ;
}
static inline int F_26 ( struct V_11 * V_12 )
{
T_3 V_15 = V_12 -> V_16 * sizeof( struct V_46 ) ;
struct V_46 * V_47 ;
V_10 V_79 ;
V_12 -> V_47 = F_27 ( V_12 -> V_18 , V_15 , V_20 ) ;
if ( F_16 ( ! V_12 -> V_47 ) ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
for ( V_79 = 0 ; V_79 < V_12 -> V_16 ; V_79 ++ ) {
V_47 = F_19 ( V_12 , V_79 , false ) ;
if ( V_47 )
F_28 ( & V_47 -> V_77 ) ;
}
return 0 ;
}
static struct V_46 * F_29 ( struct V_11 * V_52 ,
struct V_53 * V_54 ,
T_3 V_55 ,
struct V_56 * V_57 ,
T_3 V_58 )
{
unsigned long V_68 ;
struct V_46 * V_47 ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
if ( F_16 ( ! V_52 -> V_81 ) ) {
F_31 ( & V_52 -> V_80 , V_68 ) ;
return F_24 ( - V_82 ) ;
}
V_47 = F_21 ( V_52 , V_54 ,
V_55 ,
V_57 ,
V_58 ) ;
if ( F_16 ( F_32 ( V_47 ) ) )
V_52 -> V_81 = false ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
return V_47 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
T_3 V_15 ;
int V_87 = 0 ;
memset ( & V_86 -> V_88 , 0x0 , sizeof( V_86 -> V_88 ) ) ;
V_86 -> V_89 =
( V_86 -> V_90 == V_91 ) ?
sizeof( struct V_92 ) :
sizeof( struct V_93 ) ;
V_15 = V_86 -> V_89 * V_86 -> V_16 ;
if ( V_86 -> V_94 == V_95 ) {
V_87 = F_34 ( V_2 -> V_37 ) ;
F_35 ( V_2 -> V_37 , V_84 -> V_96 ) ;
V_86 -> V_88 . V_97 =
F_8 ( V_2 -> V_37 , V_15 ,
& V_86 -> V_88 . V_98 ,
V_20 ) ;
F_35 ( V_2 -> V_37 , V_87 ) ;
if ( ! V_86 -> V_88 . V_97 ) {
V_86 -> V_88 . V_97 =
F_8 ( V_2 -> V_37 , V_15 ,
& V_86 -> V_88 . V_98 ,
V_20 ) ;
}
} else {
V_87 = F_34 ( V_2 -> V_37 ) ;
F_35 ( V_2 -> V_37 , V_84 -> V_96 ) ;
V_86 -> V_88 . V_97 =
F_27 ( V_2 -> V_37 , V_15 , V_20 ) ;
F_35 ( V_2 -> V_37 , V_87 ) ;
if ( ! V_86 -> V_88 . V_97 ) {
V_86 -> V_88 . V_97 =
F_27 ( V_2 -> V_37 , V_15 , V_20 ) ;
}
}
if ( ! V_86 -> V_88 . V_97 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_86 -> V_23 = 0 ;
V_86 -> V_99 = 0 ;
V_86 -> V_24 = 1 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
struct V_100 * V_101 )
{
T_3 V_15 ;
int V_102 = 0 ;
memset ( & V_101 -> V_103 , 0x0 , sizeof( V_101 -> V_103 ) ) ;
V_101 -> V_104 =
( V_101 -> V_90 == V_91 ) ?
sizeof( struct V_105 ) :
sizeof( struct V_106 ) ;
V_15 = V_101 -> V_104 * V_101 -> V_16 ;
V_102 = F_34 ( V_2 -> V_37 ) ;
F_35 ( V_2 -> V_37 , V_84 -> V_96 ) ;
V_101 -> V_103 . V_97 =
F_8 ( V_2 -> V_37 , V_15 ,
& V_101 -> V_103 . V_98 , V_20 ) ;
F_35 ( V_2 -> V_37 , V_102 ) ;
if ( ! V_101 -> V_103 . V_97 ) {
V_101 -> V_103 . V_97 =
F_8 ( V_2 -> V_37 , V_15 ,
& V_101 -> V_103 . V_98 ,
V_20 ) ;
}
if ( ! V_101 -> V_103 . V_97 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_101 -> V_24 = 1 ;
V_101 -> V_22 = 0 ;
return 0 ;
}
static void F_37 ( struct V_11 * V_52 ,
struct V_56 * V_107 )
{
struct V_46 * V_47 ;
V_10 V_60 ;
V_60 = V_107 -> V_108 . V_109 &
V_110 ;
V_47 = F_19 ( V_52 , V_60 , false ) ;
if ( F_16 ( ! V_47 ) ) {
F_3 ( L_7 ) ;
V_52 -> V_81 = false ;
return;
}
V_47 -> V_71 = V_111 ;
V_47 -> V_112 = V_107 -> V_108 . V_71 ;
if ( V_47 -> V_74 )
memcpy ( V_47 -> V_74 , ( void * ) V_107 , V_47 -> V_73 ) ;
if ( ! V_52 -> V_113 )
F_38 ( & V_47 -> V_77 ) ;
}
static void F_39 ( struct V_11 * V_52 )
{
struct V_56 * V_107 = NULL ;
V_10 V_114 = 0 ;
V_10 V_115 ;
T_4 V_24 ;
V_115 = V_52 -> V_27 . V_22 & ( V_52 -> V_16 - 1 ) ;
V_24 = V_52 -> V_27 . V_24 ;
V_107 = & V_52 -> V_27 . V_17 [ V_115 ] ;
while ( ( V_107 -> V_108 . V_68 &
V_116 ) == V_24 ) {
F_40 () ;
F_37 ( V_52 , V_107 ) ;
V_115 ++ ;
V_114 ++ ;
if ( F_16 ( V_115 == V_52 -> V_16 ) ) {
V_115 = 0 ;
V_24 = ! V_24 ;
}
V_107 = & V_52 -> V_27 . V_17 [ V_115 ] ;
}
V_52 -> V_27 . V_22 += V_114 ;
V_52 -> V_27 . V_24 = V_24 ;
V_52 -> V_14 . V_22 += V_114 ;
V_52 -> V_63 . V_117 += V_114 ;
}
static int F_41 ( T_4 V_112 )
{
if ( F_16 ( V_112 != 0 ) )
F_3 ( L_8 , V_112 ) ;
if ( F_16 ( V_112 > V_118 ) )
return - V_7 ;
switch ( V_112 ) {
case V_119 :
return 0 ;
case V_120 :
return - V_21 ;
case V_121 :
return - V_122 ;
case V_123 :
case V_124 :
case V_125 :
case V_118 :
return - V_7 ;
}
return 0 ;
}
static int F_42 ( struct V_46 * V_47 ,
struct V_11 * V_52 )
{
unsigned long V_68 , V_126 ;
int V_127 ;
V_126 = V_128 + F_43 ( V_52 -> V_129 ) ;
while ( 1 ) {
F_30 ( & V_52 -> V_80 , V_68 ) ;
F_39 ( V_52 ) ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
if ( V_47 -> V_71 != V_72 )
break;
if ( F_44 ( V_126 ) ) {
F_3 ( L_9 ) ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
V_52 -> V_63 . V_130 ++ ;
V_52 -> V_81 = false ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
V_127 = - V_131 ;
goto V_132;
}
F_45 ( 100 ) ;
}
if ( F_16 ( V_47 -> V_71 == V_133 ) ) {
F_3 ( L_10 ) ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
V_52 -> V_63 . V_134 ++ ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
V_127 = - V_82 ;
goto V_132;
}
F_46 ( V_47 -> V_71 != V_111 , L_11 ,
V_47 -> V_71 ) ;
V_127 = F_41 ( V_47 -> V_112 ) ;
V_132:
F_17 ( V_52 , V_47 ) ;
return V_127 ;
}
static int F_47 ( struct V_46 * V_47 ,
struct V_11 * V_52 )
{
unsigned long V_68 ;
int V_127 ;
F_48 ( & V_47 -> V_77 ,
F_43 (
V_52 -> V_129 ) ) ;
if ( F_16 ( V_47 -> V_71 == V_72 ) ) {
F_30 ( & V_52 -> V_80 , V_68 ) ;
F_39 ( V_52 ) ;
V_52 -> V_63 . V_130 ++ ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
if ( V_47 -> V_71 == V_111 )
F_3 ( L_12 ,
V_47 -> V_75 ) ;
else
F_3 ( L_13 ,
V_47 -> V_75 , V_47 -> V_71 ) ;
V_52 -> V_81 = false ;
V_127 = - V_131 ;
goto V_132;
}
V_127 = F_41 ( V_47 -> V_112 ) ;
V_132:
F_17 ( V_52 , V_47 ) ;
return V_127 ;
}
static T_2 F_49 ( struct V_1 * V_2 , V_10 V_135 )
{
struct V_136 * V_137 = & V_2 -> V_137 ;
volatile struct V_138 * V_139 =
V_137 -> V_139 ;
T_2 V_140 , V_127 , V_79 ;
unsigned long V_68 ;
T_2 V_126 = V_137 -> V_141 ;
F_50 () ;
if ( V_126 == 0 )
V_126 = V_142 ;
if ( ! V_137 -> V_143 )
return F_51 ( V_2 -> V_38 + V_135 ) ;
F_30 ( & V_137 -> V_144 , V_68 ) ;
V_137 -> V_145 ++ ;
V_139 -> V_146 = V_137 -> V_145 + 0xDEAD ;
V_140 = ( V_135 << V_147 ) &
V_148 ;
V_140 |= V_137 -> V_145 &
V_149 ;
F_52 () ;
F_15 ( V_140 , V_2 -> V_38 + V_150 ) ;
for ( V_79 = 0 ; V_79 < V_126 ; V_79 ++ ) {
if ( V_139 -> V_146 == V_137 -> V_145 )
break;
F_53 ( 1 ) ;
}
if ( F_16 ( V_79 == V_126 ) ) {
F_3 ( L_14 ,
V_137 -> V_145 , V_135 , V_139 -> V_146 ,
V_139 -> V_151 ) ;
V_127 = V_152 ;
goto V_132;
}
if ( V_139 -> V_151 != V_135 ) {
F_3 ( L_15 ) ;
V_127 = V_152 ;
} else {
V_127 = V_139 -> V_153 ;
}
V_132:
F_31 ( & V_137 -> V_144 , V_68 ) ;
return V_127 ;
}
static int F_54 ( struct V_46 * V_47 ,
struct V_11 * V_52 )
{
if ( V_52 -> V_113 )
return F_42 ( V_47 ,
V_52 ) ;
return F_47 ( V_47 ,
V_52 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_154 V_155 ;
struct V_156 V_157 ;
T_4 V_90 ;
int V_127 ;
memset ( & V_155 , 0x0 , sizeof( V_155 ) ) ;
if ( V_86 -> V_90 == V_91 )
V_90 = V_158 ;
else
V_90 = V_159 ;
V_155 . V_14 . V_160 |= ( V_90 <<
V_161 ) &
V_162 ;
V_155 . V_14 . V_163 = V_86 -> V_164 ;
V_155 . V_67 . V_76 = V_165 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_155 ,
sizeof( V_155 ) ,
(struct V_56 * ) & V_157 ,
sizeof( V_157 ) ) ;
if ( F_16 ( V_127 && ( V_127 != - V_82 ) ) )
F_3 ( L_16 , V_127 ) ;
return V_127 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
struct V_100 * V_101 )
{
T_3 V_15 ;
if ( V_101 -> V_103 . V_97 ) {
V_15 = V_101 -> V_104 * V_101 -> V_16 ;
F_58 ( V_2 -> V_37 , V_15 ,
V_101 -> V_103 . V_97 ,
V_101 -> V_103 . V_98 ) ;
V_101 -> V_103 . V_97 = NULL ;
}
if ( V_86 -> V_88 . V_97 ) {
V_15 = V_86 -> V_89 * V_86 -> V_16 ;
if ( V_86 -> V_94 == V_95 )
F_58 ( V_2 -> V_37 , V_15 ,
V_86 -> V_88 . V_97 ,
V_86 -> V_88 . V_98 ) ;
else
F_59 ( V_2 -> V_37 , V_86 -> V_88 . V_97 ) ;
V_86 -> V_88 . V_97 = NULL ;
}
}
static int F_60 ( struct V_1 * V_2 , T_2 V_126 ,
V_10 V_166 )
{
T_2 V_167 , V_79 ;
for ( V_79 = 0 ; V_79 < V_126 ; V_79 ++ ) {
V_167 = F_49 ( V_2 , V_168 ) ;
if ( F_16 ( V_167 == V_152 ) ) {
F_3 ( L_17 ) ;
return - V_131 ;
}
if ( ( V_167 & V_169 ) ==
V_166 )
return 0 ;
F_45 ( 100 ) ;
}
return - V_131 ;
}
static bool F_61 ( struct V_1 * V_2 ,
enum V_170 V_171 )
{
T_2 V_172 = 1 << V_171 ;
if ( ( V_171 != V_173 ) &&
! ( V_2 -> V_174 & V_172 ) )
return false ;
return true ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_175 * V_176 ,
enum V_170 V_171 ,
T_1 V_177 ,
T_2 V_178 )
{
struct V_11 * V_52 ;
struct V_179 V_180 ;
int V_127 ;
if ( ! F_61 ( V_2 , V_171 ) ) {
F_23 ( L_18 , V_171 ) ;
return - V_122 ;
}
memset ( & V_180 , 0x0 , sizeof( V_180 ) ) ;
V_52 = & V_2 -> V_52 ;
V_180 . V_67 . V_76 = V_181 ;
if ( V_178 )
V_180 . V_67 . V_68 =
V_182 ;
else
V_180 . V_67 . V_68 = 0 ;
V_127 = F_1 ( V_2 ,
& V_180 . V_183 . V_184 ,
V_177 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_180 . V_183 . V_185 = V_178 ;
V_180 . V_186 . V_171 = V_171 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * )
& V_180 ,
sizeof( V_180 ) ,
(struct V_56 * )
V_176 ,
sizeof( * V_176 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_20 ,
V_171 , V_127 ) ;
return V_127 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_175 * V_176 ,
enum V_170 V_171 )
{
return F_62 ( V_2 ,
V_176 ,
V_171 ,
0 ,
0 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
V_188 -> V_189 =
F_8 ( V_2 -> V_37 , sizeof( * V_188 -> V_189 ) ,
& V_188 -> V_190 , V_20 ) ;
if ( F_16 ( ! V_188 -> V_189 ) )
return - V_21 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
if ( V_188 -> V_189 )
F_58 ( V_2 -> V_37 , sizeof( * V_188 -> V_189 ) ,
V_188 -> V_189 , V_188 -> V_190 ) ;
V_188 -> V_189 = NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
V_188 -> V_191 =
F_8 ( V_2 -> V_37 , sizeof( * V_188 -> V_191 ) ,
& V_188 -> V_192 , V_20 ) ;
if ( F_16 ( ! V_188 -> V_191 ) )
return - V_21 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
if ( V_188 -> V_191 )
F_58 ( V_2 -> V_37 , sizeof( * V_188 -> V_191 ) ,
V_188 -> V_191 , V_188 -> V_192 ) ;
V_188 -> V_191 = NULL ;
}
static int F_68 ( struct V_1 * V_2 ,
V_10 V_193 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_175 V_176 ;
T_3 V_194 ;
int V_127 ;
V_127 = F_63 ( V_2 , & V_176 ,
V_195 ) ;
if ( F_16 ( V_127 ) )
return V_127 ;
if ( ( V_176 . V_196 . V_197 . V_198 > V_193 ) ||
( V_176 . V_196 . V_197 . V_199 < V_193 ) ) {
F_3 ( L_21 ,
1 << V_193 , 1 << V_176 . V_196 . V_197 . V_198 ,
1 << V_176 . V_196 . V_197 . V_199 ) ;
return - V_7 ;
}
V_194 = ( 1ULL << V_193 ) *
sizeof( struct V_200 ) ;
V_188 -> V_201 =
F_8 ( V_2 -> V_37 , V_194 ,
& V_188 -> V_202 , V_20 ) ;
if ( F_16 ( ! V_188 -> V_201 ) )
goto V_203;
V_194 = ( 1ULL << V_193 ) * sizeof( V_10 ) ;
V_188 -> V_204 =
F_27 ( V_2 -> V_37 , V_194 , V_20 ) ;
if ( F_16 ( ! V_188 -> V_204 ) )
goto V_205;
V_188 -> V_206 = V_193 ;
return 0 ;
V_205:
V_194 = ( 1ULL << V_193 ) *
sizeof( struct V_200 ) ;
F_58 ( V_2 -> V_37 , V_194 , V_188 -> V_201 ,
V_188 -> V_202 ) ;
V_188 -> V_201 = NULL ;
V_203:
V_188 -> V_206 = 0 ;
return - V_21 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
T_3 V_194 = ( 1ULL << V_188 -> V_206 ) *
sizeof( struct V_200 ) ;
if ( V_188 -> V_201 )
F_58 ( V_2 -> V_37 , V_194 , V_188 -> V_201 ,
V_188 -> V_202 ) ;
V_188 -> V_201 = NULL ;
if ( V_188 -> V_204 )
F_59 ( V_2 -> V_37 , V_188 -> V_204 ) ;
V_188 -> V_204 = NULL ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_85 * V_86 , V_10 V_207 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_208 V_209 ;
struct V_210 V_211 ;
T_4 V_90 ;
int V_127 ;
memset ( & V_209 , 0x0 , sizeof( V_209 ) ) ;
V_209 . V_67 . V_76 = V_212 ;
if ( V_86 -> V_90 == V_91 )
V_90 = V_158 ;
else
V_90 = V_159 ;
V_209 . V_160 |= ( V_90 <<
V_213 ) &
V_214 ;
V_209 . V_215 |= V_86 -> V_94 &
V_216 ;
V_209 . V_215 |= ( V_217 <<
V_218 ) &
V_219 ;
V_209 . V_220 |=
V_221 ;
V_209 . V_207 = V_207 ;
V_209 . V_222 = V_86 -> V_16 ;
if ( V_86 -> V_94 == V_95 ) {
V_127 = F_1 ( V_2 ,
& V_209 . V_223 ,
V_86 -> V_88 . V_98 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
}
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_209 ,
sizeof( V_209 ) ,
(struct V_56 * ) & V_211 ,
sizeof( V_211 ) ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_22 , V_127 ) ;
return V_127 ;
}
V_86 -> V_164 = V_211 . V_163 ;
V_86 -> V_25 = ( T_2 V_224 * ) ( ( V_225 ) V_2 -> V_38 +
( V_225 ) V_211 . V_226 ) ;
if ( V_86 -> V_94 == V_227 ) {
V_86 -> V_228 = ( T_4 V_224 * ) ( ( V_225 ) V_2 -> V_229
+ V_211 . V_230 ) ;
V_86 -> V_88 . V_231 =
( T_4 V_224 * ) ( ( V_225 ) V_2 -> V_229 +
V_211 . V_232 ) ;
}
F_23 ( L_23 , V_86 -> V_164 , V_86 -> V_16 ) ;
return V_127 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_85 * V_86 ;
V_10 V_233 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < 1 << V_188 -> V_206 ; V_79 ++ ) {
V_233 = V_188 -> V_204 [ V_79 ] ;
if ( V_233 >= V_234 )
return - V_7 ;
V_86 = & V_2 -> V_235 [ V_233 ] ;
if ( V_86 -> V_90 != V_236 )
return - V_7 ;
V_188 -> V_201 [ V_79 ] . V_207 = V_86 -> V_164 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
V_10 V_237 [ V_234 ] = { ( V_10 ) - 1 } ;
struct V_187 * V_188 = & V_2 -> V_188 ;
T_4 V_164 ;
V_10 V_79 ;
for ( V_79 = 0 ; V_79 < V_234 ; V_79 ++ )
V_237 [ V_2 -> V_235 [ V_79 ] . V_164 ] = V_79 ;
for ( V_79 = 0 ; V_79 < 1 << V_188 -> V_206 ; V_79 ++ ) {
if ( V_188 -> V_201 [ V_79 ] . V_207 > V_234 )
return - V_7 ;
V_164 = ( T_4 ) V_188 -> V_201 [ V_79 ] . V_207 ;
if ( V_237 [ V_164 ] > V_234 )
return - V_7 ;
V_188 -> V_204 [ V_79 ] = V_237 [ V_164 ] ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
T_3 V_15 ;
V_15 = sizeof( struct V_238 ) * V_239 ;
V_2 -> V_240 =
F_27 ( V_2 -> V_37 , V_15 , V_20 ) ;
if ( ! V_2 -> V_240 )
return - V_21 ;
F_74 ( V_2 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 ,
V_10 V_241 )
{
struct V_238 * V_240 = V_2 -> V_240 ;
unsigned int V_79 ;
if ( ! V_241 ) {
F_3 ( L_24 ) ;
V_241 = 1 ;
}
V_2 -> V_241 = V_241 ;
for ( V_79 = 0 ; V_79 < V_239 ; V_79 ++ )
V_240 [ V_79 ] . V_242 /= V_241 ;
V_2 -> V_243 /= V_241 ;
}
int F_56 ( struct V_11 * V_52 ,
struct V_53 * V_54 ,
T_3 V_244 ,
struct V_56 * V_57 ,
T_3 V_73 )
{
struct V_46 * V_47 ;
int V_127 ;
V_47 = F_29 ( V_52 , V_54 , V_244 ,
V_57 , V_73 ) ;
if ( F_16 ( F_32 ( V_47 ) ) ) {
if ( V_47 == F_24 ( - V_82 ) )
F_23 ( L_25 ,
F_76 ( V_47 ) ) ;
else
F_3 ( L_25 ,
F_76 ( V_47 ) ) ;
return F_76 ( V_47 ) ;
}
V_127 = F_54 ( V_47 , V_52 ) ;
if ( F_16 ( V_127 ) ) {
if ( V_52 -> V_81 )
F_3 ( L_26 , V_127 ) ;
else
F_23 ( L_26 , V_127 ) ;
}
return V_127 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_245 V_209 ;
struct V_246 V_211 ;
int V_127 ;
memset ( & V_209 , 0x0 , sizeof( V_209 ) ) ;
V_209 . V_67 . V_76 = V_247 ;
V_209 . V_248 |= ( V_101 -> V_104 / 4 ) &
V_249 ;
V_209 . V_250 |=
V_251 ;
V_209 . V_252 = V_101 -> V_252 ;
V_209 . V_253 = V_101 -> V_16 ;
V_127 = F_1 ( V_2 ,
& V_209 . V_254 ,
V_101 -> V_103 . V_98 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_209 ,
sizeof( V_209 ) ,
(struct V_56 * ) & V_211 ,
sizeof( V_211 ) ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_27 , V_127 ) ;
return V_127 ;
}
V_101 -> V_164 = V_211 . V_207 ;
V_101 -> V_255 = ( T_2 V_224 * ) ( ( V_225 ) V_2 -> V_38 +
V_211 . V_256 ) ;
if ( V_211 . V_257 )
V_101 -> V_258 =
( T_2 V_224 * ) ( ( V_225 ) V_2 -> V_38 +
V_211 . V_257 ) ;
if ( V_211 . V_259 )
V_101 -> V_260 =
( T_2 V_224 * ) ( ( V_225 ) V_2 -> V_38 +
V_211 . V_259 ) ;
F_23 ( L_28 , V_101 -> V_164 , V_101 -> V_16 ) ;
return V_127 ;
}
int F_78 ( struct V_1 * V_2 , V_10 V_233 ,
struct V_85 * * V_86 ,
struct V_100 * * V_101 )
{
if ( V_233 >= V_234 ) {
F_3 ( L_29 , V_233 ,
V_234 ) ;
return - V_7 ;
}
* V_86 = & V_2 -> V_235 [ V_233 ] ;
* V_101 = & V_2 -> V_261 [ V_233 ] ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_46 * V_47 ;
V_10 V_79 ;
if ( ! V_52 -> V_47 )
return;
for ( V_79 = 0 ; V_79 < V_52 -> V_16 ; V_79 ++ ) {
V_47 = F_19 ( V_52 , V_79 , false ) ;
if ( F_16 ( ! V_47 ) )
break;
V_47 -> V_71 = V_133 ;
F_38 ( & V_47 -> V_77 ) ;
}
}
void F_80 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
unsigned long V_68 ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
while ( F_22 ( & V_52 -> V_49 ) != 0 ) {
F_31 ( & V_52 -> V_80 , V_68 ) ;
F_45 ( 20 ) ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
}
F_31 ( & V_52 -> V_80 , V_68 ) ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_262 V_155 ;
struct V_263 V_157 ;
int V_127 ;
memset ( & V_155 , 0x0 , sizeof( V_155 ) ) ;
V_155 . V_207 = V_101 -> V_164 ;
V_155 . V_67 . V_76 = V_264 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_155 ,
sizeof( V_155 ) ,
(struct V_56 * ) & V_157 ,
sizeof( V_157 ) ) ;
if ( F_16 ( V_127 && ( V_127 != - V_82 ) ) )
F_3 ( L_30 , V_127 ) ;
return V_127 ;
}
bool F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_52 . V_81 ;
}
void F_83 ( struct V_1 * V_2 , bool V_265 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
unsigned long V_68 ;
F_30 ( & V_52 -> V_80 , V_68 ) ;
V_2 -> V_52 . V_81 = V_265 ;
F_31 ( & V_52 -> V_80 , V_68 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
V_10 V_266 = V_2 -> V_32 . V_16 ;
F_46 ( V_2 -> V_32 . V_22 != V_266 , L_31 ) ;
F_15 ( V_266 , V_2 -> V_38 + V_267 ) ;
}
int F_85 ( struct V_1 * V_2 , T_2 V_268 )
{
struct V_11 * V_52 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
struct V_175 V_176 ;
int V_127 ;
V_127 = F_63 ( V_2 , & V_176 , V_272 ) ;
if ( V_127 ) {
F_86 ( L_32 ) ;
return V_127 ;
}
if ( ( V_176 . V_196 . V_32 . V_273 & V_268 ) != V_268 ) {
F_87 ( L_33 ,
V_176 . V_196 . V_32 . V_273 , V_268 ) ;
return - V_122 ;
}
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_52 = & V_2 -> V_52 ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_67 . V_68 = 0 ;
V_54 . V_186 . V_171 = V_272 ;
V_54 . V_196 . V_32 . V_275 = V_268 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_34 , V_127 ) ;
return V_127 ;
}
int F_88 ( struct V_1 * V_2 )
{
T_2 V_276 = F_49 ( V_2 , V_277 ) ;
int V_278 ;
if ( F_16 ( V_276 == V_152 ) ) {
F_3 ( L_17 ) ;
return - V_131 ;
}
V_278 = ( V_276 & V_279 ) >>
V_280 ;
F_23 ( L_35 , V_278 ) ;
if ( ( V_278 < 32 ) || V_278 > V_281 ) {
F_3 ( L_36 , V_278 ) ;
return - V_7 ;
}
V_2 -> V_6 = V_278 ;
return V_278 ;
}
int F_89 ( struct V_1 * V_2 )
{
T_2 V_282 ;
T_2 V_283 ;
T_2 V_284 ;
V_282 = F_49 ( V_2 , V_285 ) ;
V_283 = F_49 ( V_2 ,
V_286 ) ;
if ( F_16 ( ( V_282 == V_152 ) ||
( V_283 == V_152 ) ) ) {
F_3 ( L_17 ) ;
return - V_131 ;
}
F_86 ( L_37 ,
( V_282 & V_287 ) >>
V_288 ,
V_282 & V_289 ) ;
if ( V_282 < V_290 ) {
F_3 ( L_38 ) ;
return - 1 ;
}
F_86 ( L_39 ,
( V_283 & V_291 ) >>
V_292 ,
( V_283 & V_293 ) >>
V_294 ,
( V_283 & V_295 ) ,
( V_283 & V_296 ) >>
V_297 ) ;
V_284 =
( V_283 & V_291 ) |
( V_283 & V_293 ) |
( V_283 & V_295 ) ;
if ( V_284 < V_298 ) {
F_3 ( L_40 ) ;
return - 1 ;
}
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_26 * V_27 = & V_52 -> V_27 ;
struct V_13 * V_14 = & V_52 -> V_14 ;
struct V_31 * V_32 = & V_2 -> V_32 ;
V_10 V_15 ;
if ( V_52 -> V_47 )
F_59 ( V_2 -> V_37 , V_52 -> V_47 ) ;
V_52 -> V_47 = NULL ;
V_15 = F_7 ( V_52 -> V_16 ) ;
if ( V_14 -> V_17 )
F_58 ( V_2 -> V_37 , V_15 , V_14 -> V_17 ,
V_14 -> V_19 ) ;
V_14 -> V_17 = NULL ;
V_15 = F_10 ( V_52 -> V_16 ) ;
if ( V_27 -> V_17 )
F_58 ( V_2 -> V_37 , V_15 , V_27 -> V_17 ,
V_27 -> V_19 ) ;
V_27 -> V_17 = NULL ;
V_15 = F_12 ( V_32 -> V_16 ) ;
if ( V_2 -> V_32 . V_17 )
F_58 ( V_2 -> V_37 , V_15 , V_32 -> V_17 ,
V_32 -> V_19 ) ;
V_32 -> V_17 = NULL ;
}
void F_91 ( struct V_1 * V_2 , bool V_113 )
{
T_2 V_299 = 0 ;
if ( V_113 )
V_299 = V_300 ;
F_15 ( V_299 , V_2 -> V_38 + V_301 ) ;
V_2 -> V_52 . V_113 = V_113 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = & V_2 -> V_137 ;
F_93 ( & V_137 -> V_144 ) ;
V_137 -> V_139 =
F_8 ( V_2 -> V_37 ,
sizeof( * V_137 -> V_139 ) ,
& V_137 -> V_302 , V_20 ) ;
if ( F_16 ( ! V_137 -> V_139 ) )
return - V_21 ;
F_94 ( V_2 ) ;
V_137 -> V_139 -> V_146 = 0x0 ;
V_137 -> V_145 = 0x0 ;
V_137 -> V_143 = true ;
return 0 ;
}
void F_95 ( struct V_1 * V_2 , bool V_143 )
{
struct V_136 * V_137 = & V_2 -> V_137 ;
V_137 -> V_143 = V_143 ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = & V_2 -> V_137 ;
F_15 ( 0x0 , V_2 -> V_38 + V_303 ) ;
F_15 ( 0x0 , V_2 -> V_38 + V_304 ) ;
F_58 ( V_2 -> V_37 , sizeof( * V_137 -> V_139 ) ,
V_137 -> V_139 , V_137 -> V_302 ) ;
V_137 -> V_139 = NULL ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = & V_2 -> V_137 ;
T_2 V_33 , V_34 ;
V_33 = F_13 ( V_137 -> V_302 ) ;
V_34 = F_14 ( V_137 -> V_302 ) ;
F_15 ( V_33 , V_2 -> V_38 + V_303 ) ;
F_15 ( V_34 , V_2 -> V_38 + V_304 ) ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
bool V_305 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
T_2 V_306 , V_307 , V_308 , V_33 , V_34 ;
int V_127 ;
V_308 = F_49 ( V_2 , V_168 ) ;
if ( F_16 ( V_308 == V_152 ) ) {
F_3 ( L_17 ) ;
return - V_131 ;
}
if ( ! ( V_308 & V_309 ) ) {
F_3 ( L_41 ) ;
return - V_82 ;
}
V_52 -> V_16 = V_310 ;
V_52 -> V_18 = V_2 -> V_37 ;
V_52 -> V_113 = false ;
V_52 -> V_66 = 0 ;
F_98 ( & V_52 -> V_49 , 0 ) ;
if ( V_305 )
F_93 ( & V_52 -> V_80 ) ;
V_127 = F_26 ( V_52 ) ;
if ( V_127 )
goto error;
V_127 = F_6 ( V_52 ) ;
if ( V_127 )
goto error;
V_127 = F_9 ( V_52 ) ;
if ( V_127 )
goto error;
V_52 -> V_14 . V_25 = ( T_2 V_224 * ) ( ( V_225 ) V_2 -> V_38 +
V_311 ) ;
V_33 = F_13 ( V_52 -> V_14 . V_19 ) ;
V_34 = F_14 ( V_52 -> V_14 . V_19 ) ;
F_15 ( V_33 , V_2 -> V_38 + V_312 ) ;
F_15 ( V_34 , V_2 -> V_38 + V_313 ) ;
V_33 = F_13 ( V_52 -> V_27 . V_19 ) ;
V_34 = F_14 ( V_52 -> V_27 . V_19 ) ;
F_15 ( V_33 , V_2 -> V_38 + V_314 ) ;
F_15 ( V_34 , V_2 -> V_38 + V_315 ) ;
V_306 = 0 ;
V_306 |= V_52 -> V_16 & V_316 ;
V_306 |= ( sizeof( struct V_53 ) <<
V_317 ) &
V_318 ;
V_307 = 0 ;
V_307 |= V_52 -> V_16 & V_319 ;
V_307 |= ( sizeof( struct V_56 ) <<
V_320 ) &
V_321 ;
F_15 ( V_306 , V_2 -> V_38 + V_322 ) ;
F_15 ( V_307 , V_2 -> V_38 + V_323 ) ;
V_127 = F_11 ( V_2 , V_30 ) ;
if ( V_127 )
goto error;
V_52 -> V_81 = true ;
return 0 ;
error:
F_90 ( V_2 ) ;
return V_127 ;
}
int F_99 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 ;
struct V_100 * V_101 ;
int V_127 ;
if ( V_84 -> V_233 >= V_234 ) {
F_3 ( L_42 ,
V_84 -> V_233 , V_234 ) ;
return - V_7 ;
}
V_86 = & V_2 -> V_235 [ V_84 -> V_233 ] ;
V_101 = & V_2 -> V_261 [ V_84 -> V_233 ] ;
memset ( V_86 , 0x0 , sizeof( * V_86 ) ) ;
memset ( V_101 , 0x0 , sizeof( * V_101 ) ) ;
V_101 -> V_16 = V_84 -> V_324 ;
V_101 -> V_90 = V_84 -> V_90 ;
V_101 -> V_233 = V_84 -> V_233 ;
V_101 -> V_252 = V_84 -> V_252 ;
V_86 -> V_16 = V_84 -> V_324 ;
V_86 -> V_90 = V_84 -> V_90 ;
V_86 -> V_233 = V_84 -> V_233 ;
V_86 -> V_94 = V_84 -> V_94 ;
if ( V_84 -> V_90 == V_91 )
V_86 -> V_325 =
F_100 ( T_2 , V_2 -> V_325 , V_326 ) ;
V_127 = F_33 ( V_2 , V_84 , V_86 ) ;
if ( V_127 )
goto error;
V_127 = F_36 ( V_2 , V_84 , V_101 ) ;
if ( V_127 )
goto error;
V_127 = F_77 ( V_2 , V_101 ) ;
if ( V_127 )
goto error;
V_127 = F_70 ( V_2 , V_86 , V_101 -> V_164 ) ;
if ( V_127 )
goto V_327;
return 0 ;
V_327:
F_81 ( V_2 , V_101 ) ;
error:
F_57 ( V_2 , V_86 , V_101 ) ;
return V_127 ;
}
void F_101 ( struct V_1 * V_2 , V_10 V_233 )
{
struct V_85 * V_86 ;
struct V_100 * V_101 ;
if ( V_233 >= V_234 ) {
F_3 ( L_42 , V_233 ,
V_234 ) ;
return;
}
V_86 = & V_2 -> V_235 [ V_233 ] ;
V_101 = & V_2 -> V_261 [ V_233 ] ;
F_55 ( V_2 , V_86 ) ;
F_81 ( V_2 , V_101 ) ;
F_57 ( V_2 , V_86 , V_101 ) ;
}
int F_102 ( struct V_1 * V_2 ,
struct V_175 * V_271 )
{
return F_63 ( V_2 , V_271 , V_328 ) ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_329 * V_330 )
{
struct V_175 V_176 ;
int V_331 ;
V_331 = F_63 ( V_2 , & V_176 ,
V_173 ) ;
if ( V_331 )
return V_331 ;
memcpy ( & V_330 -> V_332 , & V_176 . V_196 . V_332 ,
sizeof( V_176 . V_196 . V_332 ) ) ;
V_2 -> V_174 = V_176 . V_196 . V_332 . V_174 ;
V_331 = F_63 ( V_2 , & V_176 ,
V_333 ) ;
if ( V_331 )
return V_331 ;
memcpy ( & V_330 -> V_334 , & V_176 . V_196 . V_335 ,
sizeof( V_176 . V_196 . V_335 ) ) ;
V_2 -> V_325 = V_176 . V_196 . V_335 . V_336 ;
V_331 = F_63 ( V_2 , & V_176 ,
V_272 ) ;
if ( V_331 )
return V_331 ;
memcpy ( & V_330 -> V_32 , & V_176 . V_196 . V_32 ,
sizeof( V_176 . V_196 . V_32 ) ) ;
V_331 = F_63 ( V_2 , & V_176 ,
V_337 ) ;
if ( V_331 )
return V_331 ;
memcpy ( & V_330 -> V_338 , & V_176 . V_196 . V_338 ,
sizeof( V_176 . V_196 . V_338 ) ) ;
V_331 = F_63 ( V_2 , & V_176 , V_339 ) ;
if ( ! V_331 )
memcpy ( & V_330 -> V_340 , & V_176 . V_196 . V_340 ,
sizeof( V_176 . V_196 . V_340 ) ) ;
else if ( V_331 == - V_122 )
memset ( & V_330 -> V_340 , 0x0 ,
sizeof( V_330 -> V_340 ) ) ;
else
return V_331 ;
return 0 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_52 ) ;
}
static T_5 F_105 ( struct V_1 * V_28 ,
V_10 V_341 )
{
struct V_29 * V_30 = V_28 -> V_32 . V_30 ;
if ( ( V_341 < V_342 ) && V_30 -> V_343 [ V_341 ] )
return V_30 -> V_343 [ V_341 ] ;
return V_30 -> V_344 ;
}
void F_106 ( struct V_1 * V_28 , void * V_345 )
{
struct V_42 * V_346 ;
struct V_347 * V_348 ;
struct V_31 * V_32 = & V_28 -> V_32 ;
T_5 V_349 ;
V_10 V_350 , V_351 = 0 ;
T_4 V_24 ;
V_350 = V_32 -> V_22 & ( V_32 -> V_16 - 1 ) ;
V_24 = V_32 -> V_24 ;
V_346 = & V_32 -> V_17 [ V_350 ] ;
V_348 = & V_346 -> V_352 ;
while ( ( V_348 -> V_68 & V_353 ) ==
V_24 ) {
F_23 ( L_43 ,
V_348 -> V_341 , V_348 -> V_354 ,
( V_355 ) V_348 -> V_356 +
( ( V_355 ) V_348 -> V_357 << 32 ) ) ;
V_349 = F_105 ( V_28 ,
V_348 -> V_341 ) ;
V_349 ( V_345 , V_346 ) ;
V_350 ++ ;
V_351 ++ ;
if ( F_16 ( V_350 == V_32 -> V_16 ) ) {
V_350 = 0 ;
V_24 = ! V_24 ;
}
V_346 = & V_32 -> V_17 [ V_350 ] ;
V_348 = & V_346 -> V_352 ;
}
V_32 -> V_22 += V_351 ;
V_32 -> V_24 = V_24 ;
if ( ! V_351 )
return;
F_107 () ;
F_15 ( ( T_2 ) V_32 -> V_22 , V_28 -> V_38 + V_267 ) ;
}
int F_108 ( struct V_1 * V_2 ,
enum V_358 V_359 )
{
T_2 V_360 , V_126 , V_361 , V_362 ;
int V_331 ;
V_360 = F_49 ( V_2 , V_168 ) ;
V_361 = F_49 ( V_2 , V_277 ) ;
if ( F_16 ( ( V_360 == V_152 ) ||
( V_361 == V_152 ) ) ) {
F_3 ( L_44 ) ;
return - V_131 ;
}
if ( ( V_360 & V_309 ) == 0 ) {
F_3 ( L_45 ) ;
return - V_7 ;
}
V_126 = ( V_361 & V_363 ) >>
V_364 ;
if ( V_126 == 0 ) {
F_3 ( L_46 ) ;
return - V_7 ;
}
V_362 = V_365 ;
V_362 |= ( V_359 << V_366 ) &
V_367 ;
F_15 ( V_362 , V_2 -> V_38 + V_368 ) ;
F_94 ( V_2 ) ;
V_331 = F_60 ( V_2 , V_126 ,
V_169 ) ;
if ( V_331 != 0 ) {
F_3 ( L_47 ) ;
return V_331 ;
}
F_15 ( 0 , V_2 -> V_38 + V_368 ) ;
V_331 = F_60 ( V_2 , V_126 , 0 ) ;
if ( V_331 != 0 ) {
F_3 ( L_48 ) ;
return V_331 ;
}
V_126 = ( V_361 & V_369 ) >>
V_370 ;
if ( V_126 )
V_2 -> V_52 . V_129 = V_126 * 100000 ;
else
V_2 -> V_52 . V_129 = V_371 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_372 * V_84 ,
enum V_373 type )
{
struct V_374 * V_180 = & V_84 -> V_180 ;
struct V_375 * V_176 = & V_84 -> V_176 ;
struct V_11 * V_52 ;
int V_127 ;
V_52 = & V_2 -> V_52 ;
V_180 -> V_67 . V_76 = V_376 ;
V_180 -> V_67 . V_68 = 0 ;
V_180 -> type = type ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) V_180 ,
sizeof( * V_180 ) ,
(struct V_56 * ) V_176 ,
sizeof( * V_176 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_49 , V_127 ) ;
return V_127 ;
}
int F_110 ( struct V_1 * V_2 ,
struct V_377 * V_63 )
{
struct V_372 V_84 ;
int V_127 ;
memset ( & V_84 , 0x0 , sizeof( V_84 ) ) ;
V_127 = F_109 ( V_2 , & V_84 , V_378 ) ;
if ( F_111 ( V_127 == 0 ) )
memcpy ( V_63 , & V_84 . V_176 . V_379 ,
sizeof( V_84 . V_176 . V_379 ) ) ;
return V_127 ;
}
int F_112 ( struct V_1 * V_2 , int V_380 )
{
struct V_11 * V_52 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
int V_127 ;
if ( ! F_61 ( V_2 , V_381 ) ) {
F_23 ( L_18 , V_381 ) ;
return - V_122 ;
}
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_52 = & V_2 -> V_52 ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_67 . V_68 = 0 ;
V_54 . V_186 . V_171 = V_381 ;
V_54 . V_196 . V_380 . V_380 = V_380 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_50 , V_380 , V_127 ) ;
return V_127 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_382 * V_338 )
{
int V_127 ;
struct V_175 V_271 ;
V_127 = F_63 ( V_2 , & V_271 ,
V_337 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_51 , V_127 ) ;
return V_127 ;
}
memcpy ( V_338 , & V_271 . V_196 . V_338 , sizeof( V_271 . V_196 . V_338 ) ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
struct V_175 V_176 ;
int V_127 ;
if ( ! F_61 ( V_2 ,
V_383 ) ) {
F_23 ( L_18 ,
V_383 ) ;
return - V_122 ;
}
V_127 = F_63 ( V_2 , & V_176 ,
V_383 ) ;
if ( F_16 ( V_127 ) )
return V_127 ;
if ( V_176 . V_196 . V_384 . V_385 & ( 1 << V_188 -> V_386 ) ) {
F_3 ( L_52 ,
V_188 -> V_386 ) ;
return - V_122 ;
}
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_67 . V_68 =
V_182 ;
V_54 . V_186 . V_171 = V_383 ;
V_54 . V_196 . V_384 . V_387 = V_188 -> V_388 ;
V_54 . V_196 . V_384 . V_389 = 1 << V_188 -> V_386 ;
V_127 = F_1 ( V_2 ,
& V_54 . V_183 . V_184 ,
V_188 -> V_190 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_54 . V_183 . V_185 = sizeof( * V_188 -> V_189 ) ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_53 ,
V_188 -> V_386 , V_127 ) ;
return - V_7 ;
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 ,
enum V_390 V_391 ,
const T_4 * V_392 , V_10 V_393 , T_2 V_387 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_175 V_176 ;
struct V_394 * V_189 =
V_188 -> V_189 ;
int V_331 ;
if ( F_16 ( V_393 & 0x3 ) )
return - V_7 ;
V_331 = F_62 ( V_2 , & V_176 ,
V_383 ,
V_188 -> V_190 ,
sizeof( * V_188 -> V_189 ) ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
if ( ! ( ( 1 << V_391 ) & V_176 . V_196 . V_384 . V_385 ) ) {
F_3 ( L_54 , V_391 ) ;
return - V_122 ;
}
switch ( V_391 ) {
case V_395 :
if ( V_393 > sizeof( V_189 -> V_392 ) ) {
F_3 ( L_55 ,
V_393 , sizeof( V_189 -> V_392 ) ) ;
return - V_7 ;
}
memcpy ( V_189 -> V_392 , V_392 , V_393 ) ;
V_188 -> V_388 = V_387 ;
V_189 -> V_396 = V_393 >> 2 ;
break;
case V_397 :
V_188 -> V_388 = V_387 ;
break;
default:
F_3 ( L_56 , V_391 ) ;
return - V_7 ;
}
V_331 = F_114 ( V_2 ) ;
if ( F_16 ( V_331 ) )
F_116 ( V_2 , NULL , NULL ) ;
return V_331 ;
}
int F_116 ( struct V_1 * V_2 ,
enum V_390 * V_391 ,
T_4 * V_392 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_175 V_176 ;
struct V_394 * V_189 =
V_188 -> V_189 ;
int V_331 ;
V_331 = F_62 ( V_2 , & V_176 ,
V_383 ,
V_188 -> V_190 ,
sizeof( * V_188 -> V_189 ) ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
V_188 -> V_386 = V_176 . V_196 . V_384 . V_389 ;
if ( V_391 )
* V_391 = V_188 -> V_386 ;
if ( V_392 )
memcpy ( V_392 , V_189 -> V_392 , ( T_3 ) ( V_189 -> V_396 ) << 2 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 ,
enum V_398 V_399 ,
V_10 * V_400 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_175 V_176 ;
int V_331 ;
V_331 = F_62 ( V_2 , & V_176 ,
V_401 ,
V_188 -> V_192 ,
sizeof( * V_188 -> V_191 ) ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
if ( V_400 )
* V_400 = V_188 -> V_191 -> V_402 [ V_399 ] . V_400 ;
return 0 ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_403 * V_191 = V_188 -> V_191 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
int V_127 ;
if ( ! F_61 ( V_2 ,
V_401 ) ) {
F_23 ( L_18 ,
V_401 ) ;
return - V_122 ;
}
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_67 . V_68 =
V_182 ;
V_54 . V_186 . V_171 = V_401 ;
V_54 . V_196 . V_404 . V_405 =
V_406 |
V_407 ;
V_127 = F_1 ( V_2 ,
& V_54 . V_183 . V_184 ,
V_188 -> V_192 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_54 . V_183 . V_185 = sizeof( * V_191 ) ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_57 , V_127 ) ;
return V_127 ;
}
int F_119 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_403 * V_191 =
V_188 -> V_191 ;
V_10 V_408 = 0 ;
int V_331 , V_79 ;
V_331 = F_117 ( V_2 , 0 , NULL ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
V_191 -> V_402 [ V_409 ] . V_400 =
V_410 | V_411 |
V_412 | V_413 ;
V_191 -> V_402 [ V_414 ] . V_400 =
V_410 | V_411 |
V_412 | V_413 ;
V_191 -> V_402 [ V_415 ] . V_400 =
V_410 | V_411 |
V_412 | V_413 ;
V_191 -> V_402 [ V_416 ] . V_400 =
V_410 | V_411 |
V_412 | V_413 ;
V_191 -> V_402 [ V_417 ] . V_400 =
V_410 | V_411 ;
V_191 -> V_402 [ V_418 ] . V_400 =
V_410 | V_411 ;
V_191 -> V_402 [ V_419 ] . V_400 =
V_410 | V_411 ;
V_191 -> V_402 [ V_420 ] . V_400 =
V_421 | V_422 ;
for ( V_79 = 0 ; V_79 < V_423 ; V_79 ++ ) {
V_408 = V_191 -> V_402 [ V_79 ] . V_400 &
V_191 -> V_424 [ V_79 ] . V_400 ;
if ( V_408 != V_191 -> V_402 [ V_79 ] . V_400 ) {
F_3 ( L_58 ,
V_79 , V_191 -> V_424 [ V_79 ] . V_400 ,
V_191 -> V_402 [ V_79 ] . V_400 ) ;
return - V_122 ;
}
}
V_331 = F_118 ( V_2 ) ;
if ( F_16 ( V_331 ) )
F_117 ( V_2 , 0 , NULL ) ;
return V_331 ;
}
int F_120 ( struct V_1 * V_2 ,
enum V_398 V_399 ,
V_10 V_425 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_403 * V_191 = V_188 -> V_191 ;
V_10 V_424 ;
int V_331 ;
if ( V_399 >= V_423 ) {
F_3 ( L_59 , V_399 ) ;
return - V_7 ;
}
V_331 = F_117 ( V_2 , V_399 , NULL ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
V_424 = V_191 -> V_424 [ V_399 ] . V_400 ;
if ( ( V_425 & V_424 ) != V_425 ) {
F_3 ( L_60 ,
V_399 , V_425 , V_424 ) ;
}
V_191 -> V_402 [ V_399 ] . V_400 = V_425 ;
V_331 = F_118 ( V_2 ) ;
if ( F_16 ( V_331 ) )
F_117 ( V_2 , 0 , NULL ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 ,
V_10 V_426 , V_10 V_427 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
if ( F_16 ( V_426 >= ( 1 << V_188 -> V_206 ) ) )
return - V_7 ;
if ( F_16 ( ( V_427 > V_234 ) ) )
return - V_7 ;
V_188 -> V_204 [ V_426 ] = V_427 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_11 * V_52 = & V_2 -> V_52 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
int V_127 ;
if ( ! F_61 (
V_2 , V_195 ) ) {
F_23 ( L_18 ,
V_195 ) ;
return - V_122 ;
}
V_127 = F_71 ( V_2 ) ;
if ( V_127 ) {
F_3 ( L_61 ) ;
return V_127 ;
}
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_67 . V_68 =
V_182 ;
V_54 . V_186 . V_171 = V_195 ;
V_54 . V_196 . V_197 . V_15 = V_188 -> V_206 ;
V_54 . V_196 . V_197 . V_428 = 0xFFFFFFFF ;
V_127 = F_1 ( V_2 ,
& V_54 . V_183 . V_184 ,
V_188 -> V_202 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_54 . V_183 . V_185 = ( 1ULL << V_188 -> V_206 ) *
sizeof( struct V_200 ) ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_62 , V_127 ) ;
return V_127 ;
}
int F_123 ( struct V_1 * V_2 , T_2 * V_429 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_175 V_176 ;
T_2 V_194 ;
int V_79 , V_331 ;
V_194 = ( 1ULL << V_188 -> V_206 ) *
sizeof( struct V_200 ) ;
V_331 = F_62 ( V_2 , & V_176 ,
V_195 ,
V_188 -> V_202 ,
V_194 ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
if ( ! V_429 )
return 0 ;
V_331 = F_72 ( V_2 ) ;
if ( F_16 ( V_331 ) )
return V_331 ;
for ( V_79 = 0 ; V_79 < ( 1 << V_188 -> V_206 ) ; V_79 ++ )
V_429 [ V_79 ] = V_188 -> V_204 [ V_79 ] ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , V_10 V_430 )
{
int V_331 ;
memset ( & V_2 -> V_188 , 0x0 , sizeof( V_2 -> V_188 ) ) ;
V_331 = F_68 ( V_2 , V_430 ) ;
if ( F_16 ( V_331 ) )
goto V_431;
V_331 = F_64 ( V_2 ) ;
if ( F_16 ( V_331 ) )
goto V_432;
V_331 = F_66 ( V_2 ) ;
if ( F_16 ( V_331 ) )
goto V_433;
return 0 ;
V_433:
F_65 ( V_2 ) ;
V_432:
F_69 ( V_2 ) ;
V_431:
return V_331 ;
}
void F_125 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
F_65 ( V_2 ) ;
F_67 ( V_2 ) ;
memset ( & V_2 -> V_188 , 0x0 , sizeof( V_2 -> V_188 ) ) ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_434 * V_435 = & V_2 -> V_435 ;
V_435 -> V_436 =
F_8 ( V_2 -> V_37 , V_437 ,
& V_435 -> V_438 , V_20 ) ;
if ( F_16 ( ! V_435 -> V_436 ) )
return - V_21 ;
return 0 ;
}
int F_127 ( struct V_1 * V_2 ,
T_2 V_439 )
{
struct V_434 * V_435 = & V_2 -> V_435 ;
V_435 -> V_440 =
F_8 ( V_2 -> V_37 , V_439 ,
& V_435 -> V_441 , V_20 ) ;
if ( F_16 ( ! V_435 -> V_440 ) ) {
V_435 -> V_439 = 0 ;
return - V_21 ;
}
V_435 -> V_439 = V_439 ;
return 0 ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_434 * V_435 = & V_2 -> V_435 ;
if ( V_435 -> V_436 ) {
F_58 ( V_2 -> V_37 , V_437 , V_435 -> V_436 ,
V_435 -> V_438 ) ;
V_435 -> V_436 = NULL ;
}
}
void F_129 ( struct V_1 * V_2 )
{
struct V_434 * V_435 = & V_2 -> V_435 ;
if ( V_435 -> V_440 ) {
F_58 ( V_2 -> V_37 , V_435 -> V_439 ,
V_435 -> V_440 ,
V_435 -> V_441 ) ;
V_435 -> V_440 = NULL ;
}
}
int F_130 ( struct V_1 * V_2 )
{
struct V_434 * V_435 = & V_2 -> V_435 ;
struct V_11 * V_52 ;
struct V_269 V_54 ;
struct V_270 V_271 ;
int V_127 ;
memset ( & V_54 , 0x0 , sizeof( V_54 ) ) ;
V_52 = & V_2 -> V_52 ;
V_54 . V_67 . V_76 = V_274 ;
V_54 . V_186 . V_171 = V_442 ;
V_127 = F_1 ( V_2 ,
& V_54 . V_196 . V_435 . V_443 ,
V_435 -> V_441 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_127 = F_1 ( V_2 ,
& V_54 . V_196 . V_435 . V_444 ,
V_435 -> V_438 ) ;
if ( F_16 ( V_127 ) ) {
F_3 ( L_19 ) ;
return V_127 ;
}
V_54 . V_196 . V_435 . V_439 = V_435 -> V_439 ;
V_127 = F_56 ( V_52 ,
(struct V_53 * ) & V_54 ,
sizeof( V_54 ) ,
(struct V_56 * ) & V_271 ,
sizeof( V_271 ) ) ;
if ( F_16 ( V_127 ) )
F_3 ( L_63 , V_127 ) ;
return V_127 ;
}
bool F_131 ( struct V_1 * V_2 )
{
return F_61 ( V_2 ,
V_445 ) ;
}
int F_132 ( struct V_1 * V_2 ,
T_2 V_446 )
{
if ( ! V_2 -> V_241 ) {
F_3 ( L_64 ) ;
return - V_447 ;
}
V_2 -> V_243 = V_446 /
V_2 -> V_241 ;
return 0 ;
}
int F_133 ( struct V_1 * V_2 ,
T_2 V_448 )
{
if ( ! V_2 -> V_241 ) {
F_3 ( L_64 ) ;
return - V_447 ;
}
V_2 -> V_240 [ V_449 ] . V_242 =
V_448 / V_2 -> V_241 ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
if ( V_2 -> V_240 )
F_59 ( V_2 -> V_37 , V_2 -> V_240 ) ;
V_2 -> V_240 = NULL ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_175 V_176 ;
V_10 V_450 ;
int V_331 ;
V_331 = F_63 ( V_2 , & V_176 ,
V_445 ) ;
if ( V_331 ) {
if ( V_331 == - V_122 ) {
F_23 ( L_18 ,
V_445 ) ;
V_331 = 0 ;
} else {
F_3 ( L_65 ,
V_331 ) ;
}
F_136 ( V_2 ) ;
return V_331 ;
}
V_331 = F_73 ( V_2 ) ;
if ( V_331 )
goto V_132;
V_450 = V_176 . V_196 . V_451 . V_241 ;
F_75 ( V_2 , V_450 ) ;
F_137 ( V_2 ) ;
return 0 ;
V_132:
F_134 ( V_2 ) ;
return V_331 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_238 * V_240 = V_2 -> V_240 ;
if ( ! V_240 )
return;
V_240 [ V_449 ] . V_242 =
V_452 ;
V_240 [ V_449 ] . V_453 =
V_454 ;
V_240 [ V_449 ] . V_455 =
V_456 ;
V_240 [ V_457 ] . V_242 =
V_458 ;
V_240 [ V_457 ] . V_453 =
V_459 ;
V_240 [ V_457 ] . V_455 =
V_460 ;
V_240 [ V_461 ] . V_242 =
V_462 ;
V_240 [ V_461 ] . V_453 =
V_463 ;
V_240 [ V_461 ] . V_455 =
V_464 ;
V_240 [ V_465 ] . V_242 =
V_466 ;
V_240 [ V_465 ] . V_453 =
V_467 ;
V_240 [ V_465 ] . V_455 =
V_468 ;
V_240 [ V_469 ] . V_242 =
V_470 ;
V_240 [ V_469 ] . V_453 =
V_471 ;
V_240 [ V_469 ] . V_455 =
V_472 ;
}
unsigned int F_138 ( struct V_1 * V_2 )
{
return V_2 -> V_243 ;
}
unsigned int F_139 ( struct V_1 * V_2 )
{
struct V_238 * V_240 = V_2 -> V_240 ;
if ( V_240 )
return V_240 [ V_449 ] . V_242 ;
return 0 ;
}
void F_140 ( struct V_1 * V_2 ,
enum V_473 V_474 ,
struct V_238 * V_475 )
{
struct V_238 * V_240 = V_2 -> V_240 ;
if ( V_474 >= V_239 )
return;
V_240 [ V_474 ] . V_242 = V_475 -> V_242 ;
if ( V_2 -> V_241 )
V_240 [ V_474 ] . V_242 /=
V_2 -> V_241 ;
V_240 [ V_474 ] . V_453 = V_475 -> V_453 ;
if ( V_475 -> V_455 != V_476 )
V_240 [ V_474 ] . V_455 = V_475 -> V_455 ;
}
void F_141 ( struct V_1 * V_2 ,
enum V_473 V_474 ,
struct V_238 * V_475 )
{
struct V_238 * V_240 = V_2 -> V_240 ;
if ( V_474 >= V_239 )
return;
V_475 -> V_242 = V_240 [ V_474 ] . V_242 ;
if ( V_2 -> V_241 )
V_475 -> V_242 *= V_2 -> V_241 ;
V_475 -> V_453 =
V_240 [ V_474 ] . V_453 ;
V_475 -> V_455 = V_240 [ V_474 ] . V_455 ;
}
