static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( ( V_5 & F_2 ( V_2 -> V_6 - 1 , 0 ) ) != V_5 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_4 -> V_8 = ( V_9 ) V_5 ;
V_4 -> V_10 = ( V_11 ) V_5 >> 32 ;
return 0 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
T_2 V_16 = F_5 ( V_13 -> V_17 ) ;
V_15 -> V_18 = F_6 ( V_13 -> V_19 , V_16 , & V_15 -> V_20 ,
V_21 ) ;
if ( ! V_15 -> V_18 ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
V_15 -> V_23 = 0 ;
V_15 -> V_24 = 0 ;
V_15 -> V_25 = 1 ;
V_15 -> V_26 = NULL ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_27 * V_28 = & V_13 -> V_28 ;
T_2 V_16 = F_8 ( V_13 -> V_17 ) ;
V_28 -> V_18 = F_6 ( V_13 -> V_19 , V_16 , & V_28 -> V_20 ,
V_21 ) ;
if ( ! V_28 -> V_18 ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
V_28 -> V_23 = 0 ;
V_28 -> V_25 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_29 -> V_33 ;
V_9 V_34 , V_35 , V_36 ;
T_2 V_16 ;
V_29 -> V_33 . V_17 = V_37 ;
V_16 = F_10 ( V_37 ) ;
V_33 -> V_18 = F_6 ( V_29 -> V_38 , V_16 , & V_33 -> V_20 ,
V_21 ) ;
if ( ! V_33 -> V_18 ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
V_33 -> V_23 = V_33 -> V_17 ;
V_33 -> V_25 = 1 ;
V_34 = F_11 ( V_33 -> V_20 ) ;
V_35 = F_12 ( V_33 -> V_20 ) ;
F_13 ( V_34 , V_29 -> V_39 + V_40 ) ;
F_13 ( V_35 , V_29 -> V_39 + V_41 ) ;
V_36 = 0 ;
V_36 |= V_29 -> V_33 . V_17 & V_42 ;
V_36 |= ( sizeof( struct V_43 )
<< V_44 ) &
V_45 ;
F_13 ( V_36 , V_29 -> V_39 + V_46 ) ;
if ( F_14 ( ! V_31 ) ) {
F_3 ( L_3 ) ;
return - V_7 ;
}
V_33 -> V_31 = V_31 ;
return 0 ;
}
static inline void F_15 ( struct V_12 * V_13 ,
struct V_47 * V_48 )
{
V_48 -> V_49 = false ;
F_16 ( & V_13 -> V_50 ) ;
}
static struct V_47 * F_17 ( struct V_12 * V_13 ,
T_2 V_51 , bool V_52 )
{
if ( F_14 ( V_51 >= V_13 -> V_17 ) ) {
F_3 ( L_4 ,
V_51 , V_13 -> V_17 ) ;
return NULL ;
}
if ( F_14 ( V_13 -> V_48 [ V_51 ] . V_49 && V_52 ) ) {
F_3 ( L_5 ) ;
return NULL ;
}
if ( V_52 ) {
F_18 ( & V_13 -> V_50 ) ;
V_13 -> V_48 [ V_51 ] . V_49 = true ;
}
return & V_13 -> V_48 [ V_51 ] ;
}
static struct V_47 * F_19 ( struct V_12 * V_53 ,
struct V_54 * V_55 ,
T_3 V_56 ,
struct V_57 * V_58 ,
T_3 V_59 )
{
struct V_47 * V_48 ;
T_2 V_60 , V_61 ;
T_2 V_62 ;
T_2 V_63 ;
V_62 = V_53 -> V_17 - 1 ;
V_60 = V_53 -> V_15 . V_24 & V_62 ;
V_63 = F_20 ( & V_53 -> V_50 ) ;
if ( V_63 >= V_53 -> V_17 ) {
F_21 ( L_6 ) ;
V_53 -> V_64 . V_65 ++ ;
return F_22 ( - V_66 ) ;
}
V_61 = V_53 -> V_67 ;
V_55 -> V_68 . V_69 |= V_53 -> V_15 . V_25 &
V_70 ;
V_55 -> V_68 . V_51 |= V_61 &
V_71 ;
V_48 = F_17 ( V_53 , V_61 , true ) ;
if ( F_14 ( ! V_48 ) )
return F_22 ( - V_7 ) ;
V_48 -> V_72 = V_73 ;
V_48 -> V_74 = ( V_9 ) V_59 ;
V_48 -> V_75 = V_58 ;
V_48 -> V_76 = V_55 -> V_68 . V_77 ;
F_23 ( & V_48 -> V_78 ) ;
memcpy ( & V_53 -> V_15 . V_18 [ V_60 ] , V_55 , V_56 ) ;
V_53 -> V_67 = ( V_53 -> V_67 + 1 ) &
V_62 ;
V_53 -> V_15 . V_24 ++ ;
V_53 -> V_64 . V_79 ++ ;
if ( F_14 ( ( V_53 -> V_15 . V_24 & V_62 ) == 0 ) )
V_53 -> V_15 . V_25 = ! V_53 -> V_15 . V_25 ;
F_13 ( V_53 -> V_15 . V_24 , V_53 -> V_15 . V_26 ) ;
return V_48 ;
}
static inline int F_24 ( struct V_12 * V_13 )
{
T_3 V_16 = V_13 -> V_17 * sizeof( struct V_47 ) ;
struct V_47 * V_48 ;
T_2 V_80 ;
V_13 -> V_48 = F_25 ( V_13 -> V_19 , V_16 , V_21 ) ;
if ( F_14 ( ! V_13 -> V_48 ) ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
for ( V_80 = 0 ; V_80 < V_13 -> V_17 ; V_80 ++ ) {
V_48 = F_17 ( V_13 , V_80 , false ) ;
if ( V_48 )
F_26 ( & V_48 -> V_78 ) ;
}
return 0 ;
}
static struct V_47 * F_27 ( struct V_12 * V_53 ,
struct V_54 * V_55 ,
T_3 V_56 ,
struct V_57 * V_58 ,
T_3 V_59 )
{
unsigned long V_69 ;
struct V_47 * V_48 ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
if ( F_14 ( ! V_53 -> V_82 ) ) {
F_29 ( & V_53 -> V_81 , V_69 ) ;
return F_22 ( - V_83 ) ;
}
V_48 = F_19 ( V_53 , V_55 ,
V_56 ,
V_58 ,
V_59 ) ;
if ( F_14 ( F_30 ( V_48 ) ) )
V_53 -> V_82 = false ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
return V_48 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_86 * V_87 )
{
T_3 V_16 ;
int V_88 = 0 ;
memset ( & V_87 -> V_89 , 0x0 , sizeof( struct V_90 ) ) ;
V_87 -> V_91 =
( V_87 -> V_92 == V_93 ) ?
sizeof( struct V_94 ) :
sizeof( struct V_95 ) ;
V_16 = V_87 -> V_91 * V_87 -> V_17 ;
if ( V_87 -> V_96 == V_97 ) {
V_88 = F_32 ( V_2 -> V_38 ) ;
F_33 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_87 -> V_89 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_87 -> V_89 . V_100 ,
V_21 ) ;
F_33 ( V_2 -> V_38 , V_88 ) ;
if ( ! V_87 -> V_89 . V_99 ) {
V_87 -> V_89 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_87 -> V_89 . V_100 ,
V_21 ) ;
}
} else {
V_88 = F_32 ( V_2 -> V_38 ) ;
F_33 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_87 -> V_89 . V_99 =
F_25 ( V_2 -> V_38 , V_16 , V_21 ) ;
F_33 ( V_2 -> V_38 , V_88 ) ;
if ( ! V_87 -> V_89 . V_99 ) {
V_87 -> V_89 . V_99 =
F_25 ( V_2 -> V_38 , V_16 , V_21 ) ;
}
}
if ( ! V_87 -> V_89 . V_99 ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
V_87 -> V_24 = 0 ;
V_87 -> V_101 = 0 ;
V_87 -> V_25 = 1 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_102 * V_103 )
{
T_3 V_16 ;
int V_104 = 0 ;
memset ( & V_103 -> V_105 , 0x0 , sizeof( struct V_90 ) ) ;
V_103 -> V_106 =
( V_103 -> V_92 == V_93 ) ?
sizeof( struct V_107 ) :
sizeof( struct V_108 ) ;
V_16 = V_103 -> V_106 * V_103 -> V_17 ;
V_104 = F_32 ( V_2 -> V_38 ) ;
F_33 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_103 -> V_105 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_103 -> V_105 . V_100 , V_21 ) ;
F_33 ( V_2 -> V_38 , V_104 ) ;
if ( ! V_103 -> V_105 . V_99 ) {
V_103 -> V_105 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_103 -> V_105 . V_100 ,
V_21 ) ;
}
if ( ! V_103 -> V_105 . V_99 ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
V_103 -> V_25 = 1 ;
V_103 -> V_23 = 0 ;
return 0 ;
}
static void F_35 ( struct V_12 * V_53 ,
struct V_57 * V_109 )
{
struct V_47 * V_48 ;
T_2 V_61 ;
V_61 = V_109 -> V_110 . V_111 &
V_112 ;
V_48 = F_17 ( V_53 , V_61 , false ) ;
if ( F_14 ( ! V_48 ) ) {
F_3 ( L_7 ) ;
V_53 -> V_82 = false ;
return;
}
V_48 -> V_72 = V_113 ;
V_48 -> V_114 = V_109 -> V_110 . V_72 ;
if ( V_48 -> V_75 )
memcpy ( V_48 -> V_75 , ( void * ) V_109 , V_48 -> V_74 ) ;
if ( ! V_53 -> V_115 )
F_36 ( & V_48 -> V_78 ) ;
}
static void F_37 ( struct V_12 * V_53 )
{
struct V_57 * V_109 = NULL ;
T_2 V_116 = 0 ;
T_2 V_117 ;
T_4 V_25 ;
V_117 = V_53 -> V_28 . V_23 & ( V_53 -> V_17 - 1 ) ;
V_25 = V_53 -> V_28 . V_25 ;
V_109 = & V_53 -> V_28 . V_18 [ V_117 ] ;
while ( ( V_109 -> V_110 . V_69 &
V_118 ) == V_25 ) {
F_38 () ;
F_35 ( V_53 , V_109 ) ;
V_117 ++ ;
V_116 ++ ;
if ( F_14 ( V_117 == V_53 -> V_17 ) ) {
V_117 = 0 ;
V_25 = ! V_25 ;
}
V_109 = & V_53 -> V_28 . V_18 [ V_117 ] ;
}
V_53 -> V_28 . V_23 += V_116 ;
V_53 -> V_28 . V_25 = V_25 ;
V_53 -> V_15 . V_23 += V_116 ;
V_53 -> V_64 . V_119 += V_116 ;
}
static int F_39 ( T_4 V_114 )
{
if ( F_14 ( V_114 != 0 ) )
F_3 ( L_8 , V_114 ) ;
if ( F_14 ( V_114 > V_120 ) )
return - V_7 ;
switch ( V_114 ) {
case V_121 :
return 0 ;
case V_122 :
return - V_22 ;
case V_123 :
return - V_124 ;
case V_125 :
case V_126 :
case V_127 :
case V_120 :
return - V_7 ;
}
return 0 ;
}
static int F_40 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
unsigned long V_69 , V_128 ;
int V_129 ;
V_128 = V_130 + V_131 ;
while ( 1 ) {
F_28 ( & V_53 -> V_81 , V_69 ) ;
F_37 ( V_53 ) ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
if ( V_48 -> V_72 != V_73 )
break;
if ( F_41 ( V_128 ) ) {
F_3 ( L_9 ) ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
V_53 -> V_64 . V_132 ++ ;
V_53 -> V_82 = false ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
V_129 = - V_133 ;
goto V_134;
}
F_42 ( 100 ) ;
}
if ( F_14 ( V_48 -> V_72 == V_135 ) ) {
F_3 ( L_10 ) ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
V_53 -> V_64 . V_136 ++ ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
V_129 = - V_83 ;
goto V_134;
}
F_43 ( V_48 -> V_72 != V_113 , L_11 ,
V_48 -> V_72 ) ;
V_129 = F_39 ( V_48 -> V_114 ) ;
V_134:
F_15 ( V_53 , V_48 ) ;
return V_129 ;
}
static int F_44 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
unsigned long V_69 ;
int V_129 ;
F_45 ( & V_48 -> V_78 ,
F_46 ( V_131 ) ) ;
if ( F_14 ( V_48 -> V_72 == V_73 ) ) {
F_28 ( & V_53 -> V_81 , V_69 ) ;
F_37 ( V_53 ) ;
V_53 -> V_64 . V_132 ++ ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
if ( V_48 -> V_72 == V_113 )
F_3 ( L_12 ,
V_48 -> V_76 ) ;
else
F_3 ( L_13 ,
V_48 -> V_76 , V_48 -> V_72 ) ;
V_53 -> V_82 = false ;
V_129 = - V_133 ;
goto V_134;
}
V_129 = F_39 ( V_48 -> V_114 ) ;
V_134:
F_15 ( V_53 , V_48 ) ;
return V_129 ;
}
static V_9 F_47 ( struct V_1 * V_2 , T_2 V_137 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
volatile struct V_140 * V_141 =
V_139 -> V_141 ;
V_9 V_142 , V_129 ;
unsigned long V_69 ;
int V_80 ;
F_48 () ;
if ( ! V_139 -> V_143 )
return F_49 ( V_2 -> V_39 + V_137 ) ;
F_28 ( & V_139 -> V_144 , V_69 ) ;
V_139 -> V_145 ++ ;
V_141 -> V_146 = V_139 -> V_145 + 0xDEAD ;
V_142 = ( V_137 << V_147 ) &
V_148 ;
V_142 |= V_139 -> V_145 &
V_149 ;
F_50 () ;
F_13 ( V_142 , V_2 -> V_39 + V_150 ) ;
for ( V_80 = 0 ; V_80 < V_151 ; V_80 ++ ) {
if ( V_141 -> V_146 == V_139 -> V_145 )
break;
F_51 ( 1 ) ;
}
if ( F_14 ( V_80 == V_151 ) ) {
F_3 ( L_14 ,
V_139 -> V_145 , V_137 , V_141 -> V_146 ,
V_141 -> V_152 ) ;
V_129 = V_153 ;
goto V_134;
}
if ( V_141 -> V_152 != V_137 ) {
F_3 ( L_15 ) ;
V_129 = V_153 ;
} else {
V_129 = V_141 -> V_154 ;
}
V_134:
F_29 ( & V_139 -> V_144 , V_69 ) ;
return V_129 ;
}
static int F_52 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
if ( V_53 -> V_115 )
return F_40 ( V_48 ,
V_53 ) ;
return F_44 ( V_48 ,
V_53 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_155 V_156 ;
struct V_157 V_158 ;
T_4 V_92 ;
int V_129 ;
memset ( & V_156 , 0x0 , sizeof( struct V_155 ) ) ;
if ( V_87 -> V_92 == V_93 )
V_92 = V_159 ;
else
V_92 = V_160 ;
V_156 . V_15 . V_161 |= ( V_92 <<
V_162 ) &
V_163 ;
V_156 . V_15 . V_164 = V_87 -> V_165 ;
V_156 . V_68 . V_77 = V_166 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_156 ,
sizeof( V_156 ) ,
(struct V_57 * ) & V_158 ,
sizeof( V_158 ) ) ;
if ( F_14 ( V_129 && ( V_129 != - V_83 ) ) )
F_3 ( L_16 , V_129 ) ;
return V_129 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_102 * V_103 )
{
T_3 V_16 ;
if ( V_103 -> V_105 . V_99 ) {
V_16 = V_103 -> V_106 * V_103 -> V_17 ;
F_56 ( V_2 -> V_38 , V_16 ,
V_103 -> V_105 . V_99 ,
V_103 -> V_105 . V_100 ) ;
V_103 -> V_105 . V_99 = NULL ;
}
if ( V_87 -> V_89 . V_99 ) {
V_16 = V_87 -> V_91 * V_87 -> V_17 ;
if ( V_87 -> V_96 == V_97 )
F_56 ( V_2 -> V_38 , V_16 ,
V_87 -> V_89 . V_99 ,
V_87 -> V_89 . V_100 ) ;
else
F_57 ( V_2 -> V_38 , V_87 -> V_89 . V_99 ) ;
V_87 -> V_89 . V_99 = NULL ;
}
}
static int F_58 ( struct V_1 * V_2 , V_9 V_128 ,
T_2 V_167 )
{
V_9 V_168 , V_80 ;
for ( V_80 = 0 ; V_80 < V_128 ; V_80 ++ ) {
V_168 = F_47 ( V_2 , V_169 ) ;
if ( F_14 ( V_168 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
if ( ( V_168 & V_170 ) ==
V_167 )
return 0 ;
F_42 ( 100 ) ;
}
return - V_133 ;
}
static bool F_59 ( struct V_1 * V_2 ,
enum V_171 V_172 )
{
V_9 V_173 = 1 << V_172 ;
if ( ( V_172 != V_174 ) &&
! ( V_2 -> V_175 & V_173 ) )
return false ;
return true ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
enum V_171 V_172 ,
T_1 V_178 ,
V_9 V_179 )
{
struct V_12 * V_53 ;
struct V_180 V_181 ;
int V_129 ;
if ( ! F_59 ( V_2 , V_172 ) ) {
F_21 ( L_18 , V_172 ) ;
return - V_124 ;
}
memset ( & V_181 , 0x0 , sizeof( V_181 ) ) ;
V_53 = & V_2 -> V_53 ;
V_181 . V_68 . V_77 = V_182 ;
if ( V_179 )
V_181 . V_68 . V_69 =
V_183 ;
else
V_181 . V_68 . V_69 = 0 ;
V_129 = F_1 ( V_2 ,
& V_181 . V_184 . V_185 ,
V_178 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_181 . V_184 . V_186 = V_179 ;
V_181 . V_187 . V_172 = V_172 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * )
& V_181 ,
sizeof( V_181 ) ,
(struct V_57 * )
V_177 ,
sizeof( * V_177 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_20 ,
V_172 , V_129 ) ;
return V_129 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
enum V_171 V_172 )
{
return F_60 ( V_2 ,
V_177 ,
V_172 ,
0 ,
0 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
V_189 -> V_190 =
F_6 ( V_2 -> V_38 , sizeof( * V_189 -> V_190 ) ,
& V_189 -> V_191 , V_21 ) ;
if ( F_14 ( ! V_189 -> V_190 ) )
return - V_22 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
if ( V_189 -> V_190 )
F_56 ( V_2 -> V_38 , sizeof( * V_189 -> V_190 ) ,
V_189 -> V_190 , V_189 -> V_191 ) ;
V_189 -> V_190 = NULL ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
V_189 -> V_192 =
F_6 ( V_2 -> V_38 , sizeof( * V_189 -> V_192 ) ,
& V_189 -> V_193 , V_21 ) ;
if ( F_14 ( ! V_189 -> V_192 ) )
return - V_22 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
if ( V_189 -> V_192 )
F_56 ( V_2 -> V_38 , sizeof( * V_189 -> V_192 ) ,
V_189 -> V_192 , V_189 -> V_193 ) ;
V_189 -> V_192 = NULL ;
}
static int F_66 ( struct V_1 * V_2 ,
T_2 V_194 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_176 V_177 ;
T_3 V_195 ;
int V_129 ;
V_129 = F_61 ( V_2 , & V_177 ,
V_196 ) ;
if ( F_14 ( V_129 ) )
return V_129 ;
if ( ( V_177 . V_197 . V_198 . V_199 > V_194 ) ||
( V_177 . V_197 . V_198 . V_200 < V_194 ) ) {
F_3 ( L_21 ,
1 << V_194 , 1 << V_177 . V_197 . V_198 . V_199 ,
1 << V_177 . V_197 . V_198 . V_200 ) ;
return - V_7 ;
}
V_195 = ( 1ULL << V_194 ) *
sizeof( struct V_201 ) ;
V_189 -> V_202 =
F_6 ( V_2 -> V_38 , V_195 ,
& V_189 -> V_203 , V_21 ) ;
if ( F_14 ( ! V_189 -> V_202 ) )
goto V_204;
V_195 = ( 1ULL << V_194 ) * sizeof( T_2 ) ;
V_189 -> V_205 =
F_25 ( V_2 -> V_38 , V_195 , V_21 ) ;
if ( F_14 ( ! V_189 -> V_205 ) )
goto V_206;
V_189 -> V_207 = V_194 ;
return 0 ;
V_206:
V_195 = ( 1ULL << V_194 ) *
sizeof( struct V_201 ) ;
F_56 ( V_2 -> V_38 , V_195 , V_189 -> V_202 ,
V_189 -> V_203 ) ;
V_189 -> V_202 = NULL ;
V_204:
V_189 -> V_207 = 0 ;
return - V_22 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
T_3 V_195 = ( 1ULL << V_189 -> V_207 ) *
sizeof( struct V_201 ) ;
if ( V_189 -> V_202 )
F_56 ( V_2 -> V_38 , V_195 , V_189 -> V_202 ,
V_189 -> V_203 ) ;
V_189 -> V_202 = NULL ;
if ( V_189 -> V_205 )
F_57 ( V_2 -> V_38 , V_189 -> V_205 ) ;
V_189 -> V_205 = NULL ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_86 * V_87 , T_2 V_208 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_209 V_210 ;
struct V_211 V_212 ;
T_4 V_92 ;
int V_129 ;
memset ( & V_210 , 0x0 , sizeof( struct V_209 ) ) ;
V_210 . V_68 . V_77 = V_213 ;
if ( V_87 -> V_92 == V_93 )
V_92 = V_159 ;
else
V_92 = V_160 ;
V_210 . V_161 |= ( V_92 <<
V_214 ) &
V_215 ;
V_210 . V_216 |= V_87 -> V_96 &
V_217 ;
V_210 . V_216 |= ( V_218 <<
V_219 ) &
V_220 ;
V_210 . V_221 |=
V_222 ;
V_210 . V_208 = V_208 ;
V_210 . V_223 = V_87 -> V_17 ;
if ( V_87 -> V_96 == V_97 ) {
V_129 = F_1 ( V_2 ,
& V_210 . V_224 ,
V_87 -> V_89 . V_100 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
}
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_210 ,
sizeof( V_210 ) ,
(struct V_57 * ) & V_212 ,
sizeof( V_212 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_22 , V_129 ) ;
return V_129 ;
}
V_87 -> V_165 = V_212 . V_164 ;
V_87 -> V_26 = ( V_9 V_225 * ) ( ( V_226 ) V_2 -> V_39 +
( V_226 ) V_212 . V_227 ) ;
if ( V_87 -> V_96 == V_228 ) {
V_87 -> V_229 = ( T_4 V_225 * ) ( ( V_226 ) V_2 -> V_230
+ V_212 . V_231 ) ;
V_87 -> V_89 . V_232 =
( T_4 V_225 * ) ( ( V_226 ) V_2 -> V_230 +
V_212 . V_233 ) ;
}
F_21 ( L_23 , V_87 -> V_165 , V_87 -> V_17 ) ;
return V_129 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_86 * V_87 ;
T_2 V_234 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < 1 << V_189 -> V_207 ; V_80 ++ ) {
V_234 = V_189 -> V_205 [ V_80 ] ;
if ( V_234 >= V_235 )
return - V_7 ;
V_87 = & V_2 -> V_236 [ V_234 ] ;
if ( V_87 -> V_92 != V_237 )
return - V_7 ;
V_189 -> V_202 [ V_80 ] . V_208 = V_87 -> V_165 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_2 V_238 [ V_235 ] = { ( T_2 ) - 1 } ;
struct V_188 * V_189 = & V_2 -> V_189 ;
T_4 V_165 ;
T_2 V_80 ;
for ( V_80 = 0 ; V_80 < V_235 ; V_80 ++ )
V_238 [ V_2 -> V_236 [ V_80 ] . V_165 ] = V_80 ;
for ( V_80 = 0 ; V_80 < 1 << V_189 -> V_207 ; V_80 ++ ) {
if ( V_189 -> V_202 [ V_80 ] . V_208 > V_235 )
return - V_7 ;
V_165 = ( T_4 ) V_189 -> V_202 [ V_80 ] . V_208 ;
if ( V_238 [ V_165 ] > V_235 )
return - V_7 ;
V_189 -> V_205 [ V_80 ] = V_238 [ V_165 ] ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
T_3 V_16 ;
V_16 = sizeof( struct V_239 ) * V_240 ;
V_2 -> V_241 =
F_25 ( V_2 -> V_38 , V_16 , V_21 ) ;
if ( ! V_2 -> V_241 )
return - V_22 ;
F_72 ( V_2 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
T_2 V_242 )
{
struct V_239 * V_241 = V_2 -> V_241 ;
unsigned int V_80 ;
if ( ! V_242 ) {
F_3 ( L_24 ) ;
V_242 = 1 ;
}
V_2 -> V_242 = V_242 ;
for ( V_80 = 0 ; V_80 < V_240 ; V_80 ++ )
V_241 [ V_80 ] . V_243 /= V_242 ;
V_2 -> V_244 /= V_242 ;
}
int F_54 ( struct V_12 * V_53 ,
struct V_54 * V_55 ,
T_3 V_245 ,
struct V_57 * V_58 ,
T_3 V_74 )
{
struct V_47 * V_48 ;
int V_129 ;
V_48 = F_27 ( V_53 , V_55 , V_245 ,
V_58 , V_74 ) ;
if ( F_14 ( F_30 ( V_48 ) ) ) {
if ( V_48 == F_22 ( - V_83 ) )
F_21 ( L_25 ,
F_74 ( V_48 ) ) ;
else
F_3 ( L_25 ,
F_74 ( V_48 ) ) ;
return F_74 ( V_48 ) ;
}
V_129 = F_52 ( V_48 , V_53 ) ;
if ( F_14 ( V_129 ) ) {
if ( V_53 -> V_82 )
F_3 ( L_26 , V_129 ) ;
else
F_21 ( L_26 , V_129 ) ;
}
return V_129 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_246 V_210 ;
struct V_247 V_212 ;
int V_129 ;
memset ( & V_210 , 0x0 , sizeof( struct V_246 ) ) ;
V_210 . V_68 . V_77 = V_248 ;
V_210 . V_249 |= ( V_103 -> V_106 / 4 ) &
V_250 ;
V_210 . V_251 |=
V_252 ;
V_210 . V_253 = V_103 -> V_253 ;
V_210 . V_254 = V_103 -> V_17 ;
V_129 = F_1 ( V_2 ,
& V_210 . V_255 ,
V_103 -> V_105 . V_100 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_210 ,
sizeof( V_210 ) ,
(struct V_57 * ) & V_212 ,
sizeof( V_212 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_27 , V_129 ) ;
return V_129 ;
}
V_103 -> V_165 = V_212 . V_208 ;
V_103 -> V_256 = ( V_9 V_225 * ) ( ( V_226 ) V_2 -> V_39 +
V_212 . V_257 ) ;
if ( V_212 . V_258 )
V_103 -> V_259 =
( V_9 V_225 * ) ( ( V_226 ) V_2 -> V_39 +
V_212 . V_258 ) ;
if ( V_212 . V_260 )
V_103 -> V_261 =
( V_9 V_225 * ) ( ( V_226 ) V_2 -> V_39 +
V_212 . V_260 ) ;
F_21 ( L_28 , V_103 -> V_165 , V_103 -> V_17 ) ;
return V_129 ;
}
int F_76 ( struct V_1 * V_2 , T_2 V_234 ,
struct V_86 * * V_87 ,
struct V_102 * * V_103 )
{
if ( V_234 >= V_235 ) {
F_3 ( L_29 , V_234 ,
V_235 ) ;
return - V_7 ;
}
* V_87 = & V_2 -> V_236 [ V_234 ] ;
* V_103 = & V_2 -> V_262 [ V_234 ] ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_47 * V_48 ;
T_2 V_80 ;
if ( ! V_53 -> V_48 )
return;
for ( V_80 = 0 ; V_80 < V_53 -> V_17 ; V_80 ++ ) {
V_48 = F_17 ( V_53 , V_80 , false ) ;
if ( F_14 ( ! V_48 ) )
break;
V_48 -> V_72 = V_135 ;
F_36 ( & V_48 -> V_78 ) ;
}
}
void F_78 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
unsigned long V_69 ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
while ( F_20 ( & V_53 -> V_50 ) != 0 ) {
F_29 ( & V_53 -> V_81 , V_69 ) ;
F_42 ( 20 ) ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
}
F_29 ( & V_53 -> V_81 , V_69 ) ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_263 V_156 ;
struct V_264 V_158 ;
int V_129 ;
memset ( & V_156 , 0x0 , sizeof( struct V_155 ) ) ;
V_156 . V_208 = V_103 -> V_165 ;
V_156 . V_68 . V_77 = V_265 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_156 ,
sizeof( V_156 ) ,
(struct V_57 * ) & V_158 ,
sizeof( V_158 ) ) ;
if ( F_14 ( V_129 && ( V_129 != - V_83 ) ) )
F_3 ( L_30 , V_129 ) ;
return V_129 ;
}
bool F_80 ( struct V_1 * V_2 )
{
return V_2 -> V_53 . V_82 ;
}
void F_81 ( struct V_1 * V_2 , bool V_266 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
unsigned long V_69 ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
V_2 -> V_53 . V_82 = V_266 ;
F_29 ( & V_53 -> V_81 , V_69 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
T_2 V_267 = V_2 -> V_33 . V_17 ;
F_43 ( V_2 -> V_33 . V_23 != V_267 , L_31 ) ;
F_13 ( V_267 , V_2 -> V_39 + V_268 ) ;
}
int F_83 ( struct V_1 * V_2 , V_9 V_269 )
{
struct V_12 * V_53 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
struct V_176 V_177 ;
int V_129 ;
V_129 = F_61 ( V_2 , & V_177 , V_273 ) ;
if ( V_129 ) {
F_84 ( L_32 ) ;
return V_129 ;
}
if ( ( V_177 . V_197 . V_33 . V_274 & V_269 ) != V_269 ) {
F_85 ( L_33 ,
V_177 . V_197 . V_33 . V_274 , V_269 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_68 . V_69 = 0 ;
V_55 . V_187 . V_172 = V_273 ;
V_55 . V_197 . V_33 . V_276 = V_269 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_34 , V_129 ) ;
return V_129 ;
}
int F_86 ( struct V_1 * V_2 )
{
V_9 V_277 = F_47 ( V_2 , V_278 ) ;
int V_279 ;
if ( F_14 ( V_277 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
V_279 = ( V_277 & V_280 ) >>
V_281 ;
F_21 ( L_35 , V_279 ) ;
if ( ( V_279 < 32 ) || V_279 > V_282 ) {
F_3 ( L_36 , V_279 ) ;
return - V_7 ;
}
V_2 -> V_6 = V_279 ;
return V_279 ;
}
int F_87 ( struct V_1 * V_2 )
{
V_9 V_283 ;
V_9 V_284 ;
V_9 V_285 ;
V_283 = F_47 ( V_2 , V_286 ) ;
V_284 = F_47 ( V_2 ,
V_287 ) ;
if ( F_14 ( ( V_283 == V_153 ) ||
( V_284 == V_153 ) ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
F_84 ( L_37 ,
( V_283 & V_288 ) >>
V_289 ,
V_283 & V_290 ) ;
if ( V_283 < V_291 ) {
F_3 ( L_38 ) ;
return - 1 ;
}
F_84 ( L_39 ,
( V_284 & V_292 ) >>
V_293 ,
( V_284 & V_294 ) >>
V_295 ,
( V_284 & V_296 ) ,
( V_284 & V_297 ) >>
V_298 ) ;
V_285 =
( V_284 & V_292 ) |
( V_284 & V_294 ) |
( V_284 & V_296 ) ;
if ( V_285 < V_299 ) {
F_3 ( L_40 ) ;
return - 1 ;
}
return 0 ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_27 * V_28 = & V_53 -> V_28 ;
struct V_14 * V_15 = & V_53 -> V_15 ;
struct V_32 * V_33 = & V_2 -> V_33 ;
T_2 V_16 ;
if ( V_53 -> V_48 )
F_57 ( V_2 -> V_38 , V_53 -> V_48 ) ;
V_53 -> V_48 = NULL ;
V_16 = F_5 ( V_53 -> V_17 ) ;
if ( V_15 -> V_18 )
F_56 ( V_2 -> V_38 , V_16 , V_15 -> V_18 ,
V_15 -> V_20 ) ;
V_15 -> V_18 = NULL ;
V_16 = F_8 ( V_53 -> V_17 ) ;
if ( V_28 -> V_18 )
F_56 ( V_2 -> V_38 , V_16 , V_28 -> V_18 ,
V_28 -> V_20 ) ;
V_28 -> V_18 = NULL ;
V_16 = F_10 ( V_33 -> V_17 ) ;
if ( V_2 -> V_33 . V_18 )
F_56 ( V_2 -> V_38 , V_16 , V_33 -> V_18 ,
V_33 -> V_20 ) ;
V_33 -> V_18 = NULL ;
}
void F_89 ( struct V_1 * V_2 , bool V_115 )
{
V_9 V_300 = 0 ;
if ( V_115 )
V_300 = V_301 ;
F_13 ( V_300 , V_2 -> V_39 + V_302 ) ;
V_2 -> V_53 . V_115 = V_115 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
F_91 ( & V_139 -> V_144 ) ;
V_139 -> V_141 =
F_6 ( V_2 -> V_38 ,
sizeof( * V_139 -> V_141 ) ,
& V_139 -> V_303 , V_21 ) ;
if ( F_14 ( ! V_139 -> V_141 ) )
return - V_22 ;
F_92 ( V_2 ) ;
V_139 -> V_141 -> V_146 = 0x0 ;
V_139 -> V_145 = 0x0 ;
V_139 -> V_143 = true ;
return 0 ;
}
void F_93 ( struct V_1 * V_2 , bool V_143 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
V_139 -> V_143 = V_143 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
F_13 ( 0x0 , V_2 -> V_39 + V_304 ) ;
F_13 ( 0x0 , V_2 -> V_39 + V_305 ) ;
F_56 ( V_2 -> V_38 , sizeof( * V_139 -> V_141 ) ,
V_139 -> V_141 , V_139 -> V_303 ) ;
V_139 -> V_141 = NULL ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
V_9 V_34 , V_35 ;
V_34 = F_11 ( V_139 -> V_303 ) ;
V_35 = F_12 ( V_139 -> V_303 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_304 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_305 ) ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
bool V_306 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
V_9 V_307 , V_308 , V_309 , V_34 , V_35 ;
int V_129 ;
V_309 = F_47 ( V_2 , V_169 ) ;
if ( F_14 ( V_309 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
if ( ! ( V_309 & V_310 ) ) {
F_3 ( L_41 ) ;
return - V_83 ;
}
V_53 -> V_17 = V_311 ;
V_53 -> V_19 = V_2 -> V_38 ;
V_53 -> V_115 = false ;
V_53 -> V_67 = 0 ;
F_96 ( & V_53 -> V_50 , 0 ) ;
if ( V_306 )
F_91 ( & V_53 -> V_81 ) ;
V_129 = F_24 ( V_53 ) ;
if ( V_129 )
goto error;
V_129 = F_4 ( V_53 ) ;
if ( V_129 )
goto error;
V_129 = F_7 ( V_53 ) ;
if ( V_129 )
goto error;
V_53 -> V_15 . V_26 = ( V_9 V_225 * ) ( ( V_226 ) V_2 -> V_39 +
V_312 ) ;
V_34 = F_11 ( V_53 -> V_15 . V_20 ) ;
V_35 = F_12 ( V_53 -> V_15 . V_20 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_313 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_314 ) ;
V_34 = F_11 ( V_53 -> V_28 . V_20 ) ;
V_35 = F_12 ( V_53 -> V_28 . V_20 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_315 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_316 ) ;
V_307 = 0 ;
V_307 |= V_53 -> V_17 & V_317 ;
V_307 |= ( sizeof( struct V_54 ) <<
V_318 ) &
V_319 ;
V_308 = 0 ;
V_308 |= V_53 -> V_17 & V_320 ;
V_308 |= ( sizeof( struct V_57 ) <<
V_321 ) &
V_322 ;
F_13 ( V_307 , V_2 -> V_39 + V_323 ) ;
F_13 ( V_308 , V_2 -> V_39 + V_324 ) ;
V_129 = F_9 ( V_2 , V_31 ) ;
if ( V_129 )
goto error;
V_53 -> V_82 = true ;
return 0 ;
error:
F_88 ( V_2 ) ;
return V_129 ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 ;
struct V_102 * V_103 ;
int V_129 ;
if ( V_85 -> V_234 >= V_235 ) {
F_3 ( L_42 ,
V_85 -> V_234 , V_235 ) ;
return - V_7 ;
}
V_87 = & V_2 -> V_236 [ V_85 -> V_234 ] ;
V_103 = & V_2 -> V_262 [ V_85 -> V_234 ] ;
memset ( V_87 , 0x0 , sizeof( struct V_86 ) ) ;
memset ( V_103 , 0x0 , sizeof( struct V_102 ) ) ;
V_103 -> V_17 = V_85 -> V_325 ;
V_103 -> V_92 = V_85 -> V_92 ;
V_103 -> V_234 = V_85 -> V_234 ;
V_103 -> V_253 = V_85 -> V_253 ;
V_87 -> V_17 = V_85 -> V_325 ;
V_87 -> V_92 = V_85 -> V_92 ;
V_87 -> V_234 = V_85 -> V_234 ;
V_87 -> V_96 = V_85 -> V_96 ;
if ( V_85 -> V_92 == V_93 )
V_87 -> V_326 =
F_98 ( V_9 , V_2 -> V_326 , V_327 ) ;
V_129 = F_31 ( V_2 , V_85 , V_87 ) ;
if ( V_129 )
goto error;
V_129 = F_34 ( V_2 , V_85 , V_103 ) ;
if ( V_129 )
goto error;
V_129 = F_75 ( V_2 , V_103 ) ;
if ( V_129 )
goto error;
V_129 = F_68 ( V_2 , V_87 , V_103 -> V_165 ) ;
if ( V_129 )
goto V_328;
return 0 ;
V_328:
F_79 ( V_2 , V_103 ) ;
error:
F_55 ( V_2 , V_87 , V_103 ) ;
return V_129 ;
}
void F_99 ( struct V_1 * V_2 , T_2 V_234 )
{
struct V_86 * V_87 ;
struct V_102 * V_103 ;
if ( V_234 >= V_235 ) {
F_3 ( L_42 , V_234 ,
V_235 ) ;
return;
}
V_87 = & V_2 -> V_236 [ V_234 ] ;
V_103 = & V_2 -> V_262 [ V_234 ] ;
F_53 ( V_2 , V_87 ) ;
F_79 ( V_2 , V_103 ) ;
F_55 ( V_2 , V_87 , V_103 ) ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_176 * V_272 )
{
return F_61 ( V_2 , V_272 , V_329 ) ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_330 * V_331 )
{
struct V_176 V_177 ;
int V_332 ;
V_332 = F_61 ( V_2 , & V_177 ,
V_174 ) ;
if ( V_332 )
return V_332 ;
memcpy ( & V_331 -> V_333 , & V_177 . V_197 . V_333 ,
sizeof( V_177 . V_197 . V_333 ) ) ;
V_2 -> V_175 = V_177 . V_197 . V_333 . V_175 ;
V_332 = F_61 ( V_2 , & V_177 ,
V_334 ) ;
if ( V_332 )
return V_332 ;
memcpy ( & V_331 -> V_335 , & V_177 . V_197 . V_336 ,
sizeof( V_177 . V_197 . V_336 ) ) ;
V_2 -> V_326 = V_177 . V_197 . V_336 . V_337 ;
V_332 = F_61 ( V_2 , & V_177 ,
V_273 ) ;
if ( V_332 )
return V_332 ;
memcpy ( & V_331 -> V_33 , & V_177 . V_197 . V_33 ,
sizeof( V_177 . V_197 . V_33 ) ) ;
V_332 = F_61 ( V_2 , & V_177 ,
V_338 ) ;
if ( V_332 )
return V_332 ;
memcpy ( & V_331 -> V_339 , & V_177 . V_197 . V_339 ,
sizeof( V_177 . V_197 . V_339 ) ) ;
return 0 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_53 ) ;
}
static T_5 F_103 ( struct V_1 * V_29 ,
T_2 V_340 )
{
struct V_30 * V_31 = V_29 -> V_33 . V_31 ;
if ( ( V_340 < V_341 ) && V_31 -> V_342 [ V_340 ] )
return V_31 -> V_342 [ V_340 ] ;
return V_31 -> V_343 ;
}
void F_104 ( struct V_1 * V_29 , void * V_344 )
{
struct V_43 * V_345 ;
struct V_346 * V_347 ;
struct V_32 * V_33 = & V_29 -> V_33 ;
T_5 V_348 ;
T_2 V_349 , V_350 = 0 ;
T_4 V_25 ;
V_349 = V_33 -> V_23 & ( V_33 -> V_17 - 1 ) ;
V_25 = V_33 -> V_25 ;
V_345 = & V_33 -> V_18 [ V_349 ] ;
V_347 = & V_345 -> V_351 ;
while ( ( V_347 -> V_69 & V_352 ) ==
V_25 ) {
F_21 ( L_43 ,
V_347 -> V_340 , V_347 -> V_353 ,
( V_11 ) V_347 -> V_354 +
( ( V_11 ) V_347 -> V_355 << 32 ) ) ;
V_348 = F_103 ( V_29 ,
V_347 -> V_340 ) ;
V_348 ( V_344 , V_345 ) ;
V_349 ++ ;
V_350 ++ ;
if ( F_14 ( V_349 == V_33 -> V_17 ) ) {
V_349 = 0 ;
V_25 = ! V_25 ;
}
V_345 = & V_33 -> V_18 [ V_349 ] ;
V_347 = & V_345 -> V_351 ;
}
V_33 -> V_23 += V_350 ;
V_33 -> V_25 = V_25 ;
if ( ! V_350 )
return;
F_105 () ;
F_13 ( ( V_9 ) V_33 -> V_23 , V_29 -> V_39 + V_268 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
V_9 V_356 , V_128 , V_357 , V_358 ;
int V_332 ;
V_356 = F_47 ( V_2 , V_169 ) ;
V_357 = F_47 ( V_2 , V_278 ) ;
if ( F_14 ( ( V_356 == V_153 ) ||
( V_357 == V_153 ) ) ) {
F_3 ( L_44 ) ;
return - V_133 ;
}
if ( ( V_356 & V_310 ) == 0 ) {
F_3 ( L_45 ) ;
return - V_7 ;
}
V_128 = ( V_357 & V_359 ) >>
V_360 ;
if ( V_128 == 0 ) {
F_3 ( L_46 ) ;
return - V_7 ;
}
V_358 = V_361 ;
F_13 ( V_358 , V_2 -> V_39 + V_362 ) ;
F_92 ( V_2 ) ;
V_332 = F_58 ( V_2 , V_128 ,
V_170 ) ;
if ( V_332 != 0 ) {
F_3 ( L_47 ) ;
return V_332 ;
}
F_13 ( 0 , V_2 -> V_39 + V_362 ) ;
V_332 = F_58 ( V_2 , V_128 , 0 ) ;
if ( V_332 != 0 ) {
F_3 ( L_48 ) ;
return V_332 ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_363 * V_85 ,
enum V_364 type )
{
struct V_365 * V_181 = & V_85 -> V_181 ;
struct V_366 * V_177 = & V_85 -> V_177 ;
struct V_12 * V_53 ;
int V_129 ;
V_53 = & V_2 -> V_53 ;
V_181 -> V_68 . V_77 = V_367 ;
V_181 -> V_68 . V_69 = 0 ;
V_181 -> type = type ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) V_181 ,
sizeof( * V_181 ) ,
(struct V_57 * ) V_177 ,
sizeof( * V_177 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_49 , V_129 ) ;
return V_129 ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_368 * V_64 )
{
struct V_363 V_85 ;
int V_129 ;
memset ( & V_85 , 0x0 , sizeof( V_85 ) ) ;
V_129 = F_107 ( V_2 , & V_85 , V_369 ) ;
if ( F_109 ( V_129 == 0 ) )
memcpy ( V_64 , & V_85 . V_177 . V_370 ,
sizeof( V_85 . V_177 . V_370 ) ) ;
return V_129 ;
}
int F_110 ( struct V_1 * V_2 , int V_371 )
{
struct V_12 * V_53 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
int V_129 ;
if ( ! F_59 ( V_2 , V_372 ) ) {
F_21 ( L_18 , V_372 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_68 . V_69 = 0 ;
V_55 . V_187 . V_172 = V_372 ;
V_55 . V_197 . V_371 . V_371 = V_371 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_50 , V_371 , V_129 ) ;
return V_129 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_373 * V_339 )
{
int V_129 ;
struct V_176 V_272 ;
V_129 = F_61 ( V_2 , & V_272 ,
V_338 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_51 , V_129 ) ;
return V_129 ;
}
memcpy ( V_339 , & V_272 . V_197 . V_339 , sizeof( V_272 . V_197 . V_339 ) ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
struct V_176 V_177 ;
int V_129 ;
if ( ! F_59 ( V_2 ,
V_374 ) ) {
F_21 ( L_18 ,
V_374 ) ;
return - V_124 ;
}
V_129 = F_61 ( V_2 , & V_177 ,
V_374 ) ;
if ( F_14 ( V_129 ) )
return V_129 ;
if ( V_177 . V_197 . V_375 . V_376 & ( 1 << V_189 -> V_377 ) ) {
F_3 ( L_52 ,
V_189 -> V_377 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_68 . V_69 =
V_183 ;
V_55 . V_187 . V_172 = V_374 ;
V_55 . V_197 . V_375 . V_378 = V_189 -> V_379 ;
V_55 . V_197 . V_375 . V_380 = 1 << V_189 -> V_377 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_184 . V_185 ,
V_189 -> V_191 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_184 . V_186 = sizeof( * V_189 -> V_190 ) ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_53 ,
V_189 -> V_377 , V_129 ) ;
return - V_7 ;
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 ,
enum V_381 V_382 ,
const T_4 * V_383 , T_2 V_384 , V_9 V_378 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_176 V_177 ;
struct V_385 * V_190 =
V_189 -> V_190 ;
int V_332 ;
if ( F_14 ( V_384 & 0x3 ) )
return - V_7 ;
V_332 = F_60 ( V_2 , & V_177 ,
V_374 ,
V_189 -> V_191 ,
sizeof( * V_189 -> V_190 ) ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
if ( ! ( ( 1 << V_382 ) & V_177 . V_197 . V_375 . V_376 ) ) {
F_3 ( L_54 , V_382 ) ;
return - V_124 ;
}
switch ( V_382 ) {
case V_386 :
if ( V_384 > sizeof( V_190 -> V_383 ) ) {
F_3 ( L_55 ,
V_384 , sizeof( V_190 -> V_383 ) ) ;
return - V_7 ;
}
memcpy ( V_190 -> V_383 , V_383 , V_384 ) ;
V_189 -> V_379 = V_378 ;
V_190 -> V_387 = V_384 >> 2 ;
break;
case V_388 :
V_189 -> V_379 = V_378 ;
break;
default:
F_3 ( L_56 , V_382 ) ;
return - V_7 ;
}
V_332 = F_112 ( V_2 ) ;
if ( F_14 ( V_332 ) )
F_114 ( V_2 , NULL , NULL ) ;
return V_332 ;
}
int F_114 ( struct V_1 * V_2 ,
enum V_381 * V_382 ,
T_4 * V_383 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_176 V_177 ;
struct V_385 * V_190 =
V_189 -> V_190 ;
int V_332 ;
V_332 = F_60 ( V_2 , & V_177 ,
V_374 ,
V_189 -> V_191 ,
sizeof( * V_189 -> V_190 ) ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
V_189 -> V_377 = V_177 . V_197 . V_375 . V_380 ;
if ( V_382 )
* V_382 = V_189 -> V_377 ;
if ( V_383 )
memcpy ( V_383 , V_190 -> V_383 , ( T_3 ) ( V_190 -> V_387 ) << 2 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 ,
enum V_389 V_390 ,
T_2 * V_391 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_176 V_177 ;
int V_332 ;
V_332 = F_60 ( V_2 , & V_177 ,
V_392 ,
V_189 -> V_193 ,
sizeof( * V_189 -> V_192 ) ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
if ( V_391 )
* V_391 = V_189 -> V_192 -> V_393 [ V_390 ] . V_391 ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_394 * V_192 = V_189 -> V_192 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
int V_129 ;
if ( ! F_59 ( V_2 ,
V_392 ) ) {
F_21 ( L_18 ,
V_392 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_68 . V_69 =
V_183 ;
V_55 . V_187 . V_172 = V_392 ;
V_55 . V_197 . V_395 . V_396 =
V_397 |
V_398 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_184 . V_185 ,
V_189 -> V_193 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_184 . V_186 = sizeof( * V_192 ) ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_57 , V_129 ) ;
return V_129 ;
}
int F_117 ( struct V_1 * V_2 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_394 * V_192 =
V_189 -> V_192 ;
T_2 V_399 = 0 ;
int V_332 , V_80 ;
V_332 = F_115 ( V_2 , 0 , NULL ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
V_192 -> V_393 [ V_400 ] . V_391 =
V_401 | V_402 |
V_403 | V_404 ;
V_192 -> V_393 [ V_405 ] . V_391 =
V_401 | V_402 |
V_403 | V_404 ;
V_192 -> V_393 [ V_406 ] . V_391 =
V_401 | V_402 |
V_403 | V_404 ;
V_192 -> V_393 [ V_407 ] . V_391 =
V_401 | V_402 |
V_403 | V_404 ;
V_192 -> V_393 [ V_408 ] . V_391 =
V_401 | V_402 ;
V_192 -> V_393 [ V_409 ] . V_391 =
V_401 | V_402 ;
V_192 -> V_393 [ V_410 ] . V_391 =
V_401 | V_402 ;
V_192 -> V_393 [ V_411 ] . V_391 =
V_412 | V_413 ;
for ( V_80 = 0 ; V_80 < V_414 ; V_80 ++ ) {
V_399 = V_192 -> V_393 [ V_80 ] . V_391 &
V_192 -> V_415 [ V_80 ] . V_391 ;
if ( V_399 != V_192 -> V_393 [ V_80 ] . V_391 ) {
F_3 ( L_58 ,
V_80 , V_192 -> V_415 [ V_80 ] . V_391 ,
V_192 -> V_393 [ V_80 ] . V_391 ) ;
return - V_124 ;
}
}
V_332 = F_116 ( V_2 ) ;
if ( F_14 ( V_332 ) )
F_115 ( V_2 , 0 , NULL ) ;
return V_332 ;
}
int F_118 ( struct V_1 * V_2 ,
enum V_389 V_390 ,
T_2 V_416 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_394 * V_192 = V_189 -> V_192 ;
T_2 V_415 ;
int V_332 ;
if ( V_390 >= V_414 ) {
F_3 ( L_59 , V_390 ) ;
return - V_7 ;
}
V_332 = F_115 ( V_2 , V_390 , NULL ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
V_415 = V_192 -> V_415 [ V_390 ] . V_391 ;
if ( ( V_416 & V_415 ) != V_416 ) {
F_3 ( L_60 ,
V_390 , V_416 , V_415 ) ;
}
V_192 -> V_393 [ V_390 ] . V_391 = V_416 ;
V_332 = F_116 ( V_2 ) ;
if ( F_14 ( V_332 ) )
F_115 ( V_2 , 0 , NULL ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 ,
T_2 V_417 , T_2 V_418 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
if ( F_14 ( V_417 >= ( 1 << V_189 -> V_207 ) ) )
return - V_7 ;
if ( F_14 ( ( V_418 > V_235 ) ) )
return - V_7 ;
V_189 -> V_205 [ V_417 ] = V_418 ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
int V_129 ;
if ( ! F_59 (
V_2 , V_196 ) ) {
F_21 ( L_18 ,
V_196 ) ;
return - V_124 ;
}
V_129 = F_69 ( V_2 ) ;
if ( V_129 ) {
F_3 ( L_61 ) ;
return V_129 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_68 . V_69 =
V_183 ;
V_55 . V_187 . V_172 = V_196 ;
V_55 . V_197 . V_198 . V_16 = V_189 -> V_207 ;
V_55 . V_197 . V_198 . V_419 = 0xFFFFFFFF ;
V_129 = F_1 ( V_2 ,
& V_55 . V_184 . V_185 ,
V_189 -> V_203 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_184 . V_186 = ( 1ULL << V_189 -> V_207 ) *
sizeof( struct V_201 ) ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_62 , V_129 ) ;
return V_129 ;
}
int F_121 ( struct V_1 * V_2 , V_9 * V_420 )
{
struct V_188 * V_189 = & V_2 -> V_189 ;
struct V_176 V_177 ;
V_9 V_195 ;
int V_80 , V_332 ;
V_195 = ( 1ULL << V_189 -> V_207 ) *
sizeof( struct V_201 ) ;
V_332 = F_60 ( V_2 , & V_177 ,
V_196 ,
V_189 -> V_203 ,
V_195 ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
if ( ! V_420 )
return 0 ;
V_332 = F_70 ( V_2 ) ;
if ( F_14 ( V_332 ) )
return V_332 ;
for ( V_80 = 0 ; V_80 < ( 1 << V_189 -> V_207 ) ; V_80 ++ )
V_420 [ V_80 ] = V_189 -> V_205 [ V_80 ] ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_2 V_421 )
{
int V_332 ;
memset ( & V_2 -> V_189 , 0x0 , sizeof( V_2 -> V_189 ) ) ;
V_332 = F_66 ( V_2 , V_421 ) ;
if ( F_14 ( V_332 ) )
goto V_422;
V_332 = F_62 ( V_2 ) ;
if ( F_14 ( V_332 ) )
goto V_423;
V_332 = F_64 ( V_2 ) ;
if ( F_14 ( V_332 ) )
goto V_424;
return 0 ;
V_424:
F_63 ( V_2 ) ;
V_423:
F_67 ( V_2 ) ;
V_422:
return V_332 ;
}
void F_123 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_63 ( V_2 ) ;
F_65 ( V_2 ) ;
memset ( & V_2 -> V_189 , 0x0 , sizeof( V_2 -> V_189 ) ) ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_425 * V_426 = & V_2 -> V_426 ;
V_426 -> V_427 =
F_6 ( V_2 -> V_38 , V_428 ,
& V_426 -> V_429 , V_21 ) ;
if ( F_14 ( ! V_426 -> V_427 ) )
return - V_22 ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 ,
V_9 V_430 )
{
struct V_425 * V_426 = & V_2 -> V_426 ;
V_426 -> V_431 =
F_6 ( V_2 -> V_38 , V_430 ,
& V_426 -> V_432 , V_21 ) ;
if ( F_14 ( ! V_426 -> V_431 ) ) {
V_426 -> V_430 = 0 ;
return - V_22 ;
}
V_426 -> V_430 = V_430 ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_425 * V_426 = & V_2 -> V_426 ;
if ( V_426 -> V_427 ) {
F_56 ( V_2 -> V_38 , V_428 , V_426 -> V_427 ,
V_426 -> V_429 ) ;
V_426 -> V_427 = NULL ;
}
}
void F_127 ( struct V_1 * V_2 )
{
struct V_425 * V_426 = & V_2 -> V_426 ;
if ( V_426 -> V_431 ) {
F_56 ( V_2 -> V_38 , V_426 -> V_430 ,
V_426 -> V_431 ,
V_426 -> V_432 ) ;
V_426 -> V_431 = NULL ;
}
}
int F_128 ( struct V_1 * V_2 )
{
struct V_425 * V_426 = & V_2 -> V_426 ;
struct V_12 * V_53 ;
struct V_270 V_55 ;
struct V_271 V_272 ;
int V_129 ;
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_275 ;
V_55 . V_187 . V_172 = V_433 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_197 . V_426 . V_434 ,
V_426 -> V_432 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_129 = F_1 ( V_2 ,
& V_55 . V_197 . V_426 . V_435 ,
V_426 -> V_429 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_197 . V_426 . V_430 = V_426 -> V_430 ;
V_129 = F_54 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_272 ,
sizeof( V_272 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_63 , V_129 ) ;
return V_129 ;
}
bool F_129 ( struct V_1 * V_2 )
{
return F_59 ( V_2 ,
V_436 ) ;
}
int F_130 ( struct V_1 * V_2 ,
V_9 V_437 )
{
if ( ! V_2 -> V_242 ) {
F_3 ( L_64 ) ;
return - V_438 ;
}
V_2 -> V_244 = V_437 /
V_2 -> V_242 ;
return 0 ;
}
int F_131 ( struct V_1 * V_2 ,
V_9 V_439 )
{
if ( ! V_2 -> V_242 ) {
F_3 ( L_64 ) ;
return - V_438 ;
}
V_2 -> V_241 [ V_440 ] . V_243 =
V_439 / V_2 -> V_242 ;
return 0 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_241 )
F_57 ( V_2 -> V_38 , V_2 -> V_241 ) ;
V_2 -> V_241 = NULL ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_176 V_177 ;
T_2 V_441 ;
int V_332 ;
V_332 = F_61 ( V_2 , & V_177 ,
V_436 ) ;
if ( V_332 ) {
if ( V_332 == - V_124 ) {
F_21 ( L_18 ,
V_436 ) ;
V_332 = 0 ;
} else {
F_3 ( L_65 ,
V_332 ) ;
}
F_134 ( V_2 ) ;
return V_332 ;
}
V_332 = F_71 ( V_2 ) ;
if ( V_332 )
goto V_134;
V_441 = V_177 . V_197 . V_442 . V_242 ;
F_73 ( V_2 , V_441 ) ;
F_135 ( V_2 ) ;
return 0 ;
V_134:
F_132 ( V_2 ) ;
return V_332 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_239 * V_241 = V_2 -> V_241 ;
if ( ! V_241 )
return;
V_241 [ V_440 ] . V_243 =
V_443 ;
V_241 [ V_440 ] . V_444 =
V_445 ;
V_241 [ V_440 ] . V_446 =
V_447 ;
V_241 [ V_448 ] . V_243 =
V_449 ;
V_241 [ V_448 ] . V_444 =
V_450 ;
V_241 [ V_448 ] . V_446 =
V_451 ;
V_241 [ V_452 ] . V_243 =
V_453 ;
V_241 [ V_452 ] . V_444 =
V_454 ;
V_241 [ V_452 ] . V_446 =
V_455 ;
V_241 [ V_456 ] . V_243 =
V_457 ;
V_241 [ V_456 ] . V_444 =
V_458 ;
V_241 [ V_456 ] . V_446 =
V_459 ;
V_241 [ V_460 ] . V_243 =
V_461 ;
V_241 [ V_460 ] . V_444 =
V_462 ;
V_241 [ V_460 ] . V_446 =
V_463 ;
}
unsigned int F_136 ( struct V_1 * V_2 )
{
return V_2 -> V_244 ;
}
unsigned int F_137 ( struct V_1 * V_2 )
{
struct V_239 * V_241 = V_2 -> V_241 ;
if ( V_241 )
return V_241 [ V_440 ] . V_243 ;
return 0 ;
}
void F_138 ( struct V_1 * V_2 ,
enum V_464 V_465 ,
struct V_239 * V_466 )
{
struct V_239 * V_241 = V_2 -> V_241 ;
if ( V_465 >= V_240 )
return;
V_241 [ V_465 ] . V_243 = V_466 -> V_243 ;
if ( V_2 -> V_242 )
V_241 [ V_465 ] . V_243 /=
V_2 -> V_242 ;
V_241 [ V_465 ] . V_444 = V_466 -> V_444 ;
if ( V_466 -> V_446 != V_467 )
V_241 [ V_465 ] . V_446 = V_466 -> V_446 ;
}
void F_139 ( struct V_1 * V_2 ,
enum V_464 V_465 ,
struct V_239 * V_466 )
{
struct V_239 * V_241 = V_2 -> V_241 ;
if ( V_465 >= V_240 )
return;
V_466 -> V_243 = V_241 [ V_465 ] . V_243 ;
if ( V_2 -> V_242 )
V_466 -> V_243 *= V_2 -> V_242 ;
V_466 -> V_444 =
V_241 [ V_465 ] . V_444 ;
V_466 -> V_446 = V_241 [ V_465 ] . V_446 ;
}
