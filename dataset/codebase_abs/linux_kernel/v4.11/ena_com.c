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
V_63 = V_53 -> V_15 . V_24 - V_53 -> V_15 . V_23 ;
if ( V_63 >= V_53 -> V_17 ) {
F_20 ( L_6 ,
V_53 -> V_15 . V_24 , V_53 -> V_15 . V_23 ,
V_53 -> V_17 ) ;
V_53 -> V_64 . V_65 ++ ;
return F_21 ( - V_66 ) ;
}
V_61 = V_53 -> V_67 ;
V_55 -> V_68 . V_69 |= V_53 -> V_15 . V_25 &
V_70 ;
V_55 -> V_68 . V_51 |= V_61 &
V_71 ;
V_48 = F_17 ( V_53 , V_61 , true ) ;
if ( F_14 ( ! V_48 ) )
return F_21 ( - V_7 ) ;
V_48 -> V_72 = V_73 ;
V_48 -> V_74 = ( V_9 ) V_59 ;
V_48 -> V_75 = V_58 ;
V_48 -> V_76 = V_55 -> V_68 . V_77 ;
F_22 ( & V_48 -> V_78 ) ;
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
static inline int F_23 ( struct V_12 * V_13 )
{
T_3 V_16 = V_13 -> V_17 * sizeof( struct V_47 ) ;
struct V_47 * V_48 ;
T_2 V_80 ;
V_13 -> V_48 = F_24 ( V_13 -> V_19 , V_16 , V_21 ) ;
if ( F_14 ( ! V_13 -> V_48 ) ) {
F_3 ( L_2 ) ;
return - V_22 ;
}
for ( V_80 = 0 ; V_80 < V_13 -> V_17 ; V_80 ++ ) {
V_48 = F_17 ( V_13 , V_80 , false ) ;
if ( V_48 )
F_25 ( & V_48 -> V_78 ) ;
}
return 0 ;
}
static struct V_47 * F_26 ( struct V_12 * V_53 ,
struct V_54 * V_55 ,
T_3 V_56 ,
struct V_57 * V_58 ,
T_3 V_59 )
{
unsigned long V_69 ;
struct V_47 * V_48 ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
if ( F_14 ( ! V_53 -> V_82 ) ) {
F_28 ( & V_53 -> V_81 , V_69 ) ;
return F_21 ( - V_83 ) ;
}
V_48 = F_19 ( V_53 , V_55 ,
V_56 ,
V_58 ,
V_59 ) ;
if ( F_14 ( F_29 ( V_48 ) ) )
V_53 -> V_82 = false ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
return V_48 ;
}
static int F_30 ( struct V_1 * V_2 ,
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
V_88 = F_31 ( V_2 -> V_38 ) ;
F_32 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_87 -> V_89 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_87 -> V_89 . V_100 ,
V_21 ) ;
F_32 ( V_2 -> V_38 , V_88 ) ;
if ( ! V_87 -> V_89 . V_99 ) {
V_87 -> V_89 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_87 -> V_89 . V_100 ,
V_21 ) ;
}
} else {
V_88 = F_31 ( V_2 -> V_38 ) ;
F_32 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_87 -> V_89 . V_99 =
F_24 ( V_2 -> V_38 , V_16 , V_21 ) ;
F_32 ( V_2 -> V_38 , V_88 ) ;
if ( ! V_87 -> V_89 . V_99 ) {
V_87 -> V_89 . V_99 =
F_24 ( V_2 -> V_38 , V_16 , V_21 ) ;
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
static int F_33 ( struct V_1 * V_2 ,
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
V_104 = F_31 ( V_2 -> V_38 ) ;
F_32 ( V_2 -> V_38 , V_85 -> V_98 ) ;
V_103 -> V_105 . V_99 =
F_6 ( V_2 -> V_38 , V_16 ,
& V_103 -> V_105 . V_100 , V_21 ) ;
F_32 ( V_2 -> V_38 , V_104 ) ;
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
static void F_34 ( struct V_12 * V_53 ,
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
F_35 ( & V_48 -> V_78 ) ;
}
static void F_36 ( struct V_12 * V_53 )
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
F_37 () ;
F_34 ( V_53 , V_109 ) ;
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
static int F_38 ( T_4 V_114 )
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
static int F_39 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
unsigned long V_69 ;
V_9 V_128 ;
int V_129 ;
V_128 = ( ( V_9 ) F_40 ( V_130 ) ) ;
while ( V_48 -> V_72 == V_73 ) {
if ( ( ( ( V_9 ) F_40 ( V_130 ) ) - V_128 ) >
V_131 ) {
F_3 ( L_9 ) ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
V_53 -> V_64 . V_132 ++ ;
V_53 -> V_82 = false ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
V_129 = - V_133 ;
goto V_134;
}
F_27 ( & V_53 -> V_81 , V_69 ) ;
F_36 ( V_53 ) ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
F_41 ( 100 ) ;
}
if ( F_14 ( V_48 -> V_72 == V_135 ) ) {
F_3 ( L_10 ) ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
V_53 -> V_64 . V_136 ++ ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
V_129 = - V_83 ;
goto V_134;
}
F_42 ( V_48 -> V_72 != V_113 , L_11 ,
V_48 -> V_72 ) ;
V_129 = F_38 ( V_48 -> V_114 ) ;
V_134:
F_15 ( V_53 , V_48 ) ;
return V_129 ;
}
static int F_43 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
unsigned long V_69 ;
int V_129 ;
F_44 ( & V_48 -> V_78 ,
F_45 ( V_131 ) ) ;
if ( F_14 ( V_48 -> V_72 == V_73 ) ) {
F_27 ( & V_53 -> V_81 , V_69 ) ;
F_36 ( V_53 ) ;
V_53 -> V_64 . V_132 ++ ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
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
V_129 = F_38 ( V_48 -> V_114 ) ;
V_134:
F_15 ( V_53 , V_48 ) ;
return V_129 ;
}
static V_9 F_46 ( struct V_1 * V_2 , T_2 V_137 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
volatile struct V_140 * V_141 =
V_139 -> V_141 ;
V_9 V_142 , V_129 ;
unsigned long V_69 ;
int V_80 ;
F_47 () ;
if ( ! V_139 -> V_143 )
return F_48 ( V_2 -> V_39 + V_137 ) ;
F_27 ( & V_139 -> V_144 , V_69 ) ;
V_139 -> V_145 ++ ;
V_141 -> V_146 = V_139 -> V_145 + 0xDEAD ;
V_142 = ( V_137 << V_147 ) &
V_148 ;
V_142 |= V_139 -> V_145 &
V_149 ;
F_49 () ;
F_13 ( V_142 , V_2 -> V_39 + V_150 ) ;
for ( V_80 = 0 ; V_80 < V_151 ; V_80 ++ ) {
if ( V_141 -> V_146 == V_139 -> V_145 )
break;
F_50 ( 1 ) ;
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
F_28 ( & V_139 -> V_144 , V_69 ) ;
return V_129 ;
}
static int F_51 ( struct V_47 * V_48 ,
struct V_12 * V_53 )
{
if ( V_53 -> V_115 )
return F_39 ( V_48 ,
V_53 ) ;
return F_43 ( V_48 ,
V_53 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
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
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_156 ,
sizeof( V_156 ) ,
(struct V_57 * ) & V_158 ,
sizeof( V_158 ) ) ;
if ( F_14 ( V_129 && ( V_129 != - V_83 ) ) )
F_3 ( L_16 , V_129 ) ;
return V_129 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_102 * V_103 )
{
T_3 V_16 ;
if ( V_103 -> V_105 . V_99 ) {
V_16 = V_103 -> V_106 * V_103 -> V_17 ;
F_55 ( V_2 -> V_38 , V_16 ,
V_103 -> V_105 . V_99 ,
V_103 -> V_105 . V_100 ) ;
V_103 -> V_105 . V_99 = NULL ;
}
if ( V_87 -> V_89 . V_99 ) {
V_16 = V_87 -> V_91 * V_87 -> V_17 ;
if ( V_87 -> V_96 == V_97 )
F_55 ( V_2 -> V_38 , V_16 ,
V_87 -> V_89 . V_99 ,
V_87 -> V_89 . V_100 ) ;
else
F_56 ( V_2 -> V_38 , V_87 -> V_89 . V_99 ) ;
V_87 -> V_89 . V_99 = NULL ;
}
}
static int F_57 ( struct V_1 * V_2 , V_9 V_167 ,
T_2 V_168 )
{
V_9 V_169 , V_80 ;
for ( V_80 = 0 ; V_80 < V_167 ; V_80 ++ ) {
V_169 = F_46 ( V_2 , V_170 ) ;
if ( F_14 ( V_169 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
if ( ( V_169 & V_171 ) ==
V_168 )
return 0 ;
F_41 ( 100 ) ;
}
return - V_133 ;
}
static bool F_58 ( struct V_1 * V_2 ,
enum V_172 V_173 )
{
V_9 V_174 = 1 << V_173 ;
if ( ( V_173 != V_175 ) &&
! ( V_2 -> V_176 & V_174 ) )
return false ;
return true ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_177 * V_178 ,
enum V_172 V_173 ,
T_1 V_179 ,
V_9 V_180 )
{
struct V_12 * V_53 ;
struct V_181 V_182 ;
int V_129 ;
if ( ! F_58 ( V_2 , V_173 ) ) {
F_20 ( L_18 , V_173 ) ;
return - V_124 ;
}
memset ( & V_182 , 0x0 , sizeof( V_182 ) ) ;
V_53 = & V_2 -> V_53 ;
V_182 . V_68 . V_77 = V_183 ;
if ( V_180 )
V_182 . V_68 . V_69 =
V_184 ;
else
V_182 . V_68 . V_69 = 0 ;
V_129 = F_1 ( V_2 ,
& V_182 . V_185 . V_186 ,
V_179 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_182 . V_185 . V_187 = V_180 ;
V_182 . V_188 . V_173 = V_173 ;
V_129 = F_53 ( V_53 ,
(struct V_54 * )
& V_182 ,
sizeof( V_182 ) ,
(struct V_57 * )
V_178 ,
sizeof( * V_178 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_20 ,
V_173 , V_129 ) ;
return V_129 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_177 * V_178 ,
enum V_172 V_173 )
{
return F_59 ( V_2 ,
V_178 ,
V_173 ,
0 ,
0 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
V_190 -> V_191 =
F_6 ( V_2 -> V_38 , sizeof( * V_190 -> V_191 ) ,
& V_190 -> V_192 , V_21 ) ;
if ( F_14 ( ! V_190 -> V_191 ) )
return - V_22 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
if ( V_190 -> V_191 )
F_55 ( V_2 -> V_38 , sizeof( * V_190 -> V_191 ) ,
V_190 -> V_191 , V_190 -> V_192 ) ;
V_190 -> V_191 = NULL ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
V_190 -> V_193 =
F_6 ( V_2 -> V_38 , sizeof( * V_190 -> V_193 ) ,
& V_190 -> V_194 , V_21 ) ;
if ( F_14 ( ! V_190 -> V_193 ) )
return - V_22 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
if ( V_190 -> V_193 )
F_55 ( V_2 -> V_38 , sizeof( * V_190 -> V_193 ) ,
V_190 -> V_193 , V_190 -> V_194 ) ;
V_190 -> V_193 = NULL ;
}
static int F_65 ( struct V_1 * V_2 ,
T_2 V_195 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_177 V_178 ;
T_3 V_196 ;
int V_129 ;
V_129 = F_60 ( V_2 , & V_178 ,
V_197 ) ;
if ( F_14 ( V_129 ) )
return V_129 ;
if ( ( V_178 . V_198 . V_199 . V_200 > V_195 ) ||
( V_178 . V_198 . V_199 . V_201 < V_195 ) ) {
F_3 ( L_21 ,
1 << V_195 , 1 << V_178 . V_198 . V_199 . V_200 ,
1 << V_178 . V_198 . V_199 . V_201 ) ;
return - V_7 ;
}
V_196 = ( 1ULL << V_195 ) *
sizeof( struct V_202 ) ;
V_190 -> V_203 =
F_6 ( V_2 -> V_38 , V_196 ,
& V_190 -> V_204 , V_21 ) ;
if ( F_14 ( ! V_190 -> V_203 ) )
goto V_205;
V_196 = ( 1ULL << V_195 ) * sizeof( T_2 ) ;
V_190 -> V_206 =
F_24 ( V_2 -> V_38 , V_196 , V_21 ) ;
if ( F_14 ( ! V_190 -> V_206 ) )
goto V_207;
V_190 -> V_208 = V_195 ;
return 0 ;
V_207:
V_196 = ( 1ULL << V_195 ) *
sizeof( struct V_202 ) ;
F_55 ( V_2 -> V_38 , V_196 , V_190 -> V_203 ,
V_190 -> V_204 ) ;
V_190 -> V_203 = NULL ;
V_205:
V_190 -> V_208 = 0 ;
return - V_22 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
T_3 V_196 = ( 1ULL << V_190 -> V_208 ) *
sizeof( struct V_202 ) ;
if ( V_190 -> V_203 )
F_55 ( V_2 -> V_38 , V_196 , V_190 -> V_203 ,
V_190 -> V_204 ) ;
V_190 -> V_203 = NULL ;
if ( V_190 -> V_206 )
F_56 ( V_2 -> V_38 , V_190 -> V_206 ) ;
V_190 -> V_206 = NULL ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_86 * V_87 , T_2 V_209 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_210 V_211 ;
struct V_212 V_213 ;
T_4 V_92 ;
int V_129 ;
memset ( & V_211 , 0x0 , sizeof( struct V_210 ) ) ;
V_211 . V_68 . V_77 = V_214 ;
if ( V_87 -> V_92 == V_93 )
V_92 = V_159 ;
else
V_92 = V_160 ;
V_211 . V_161 |= ( V_92 <<
V_215 ) &
V_216 ;
V_211 . V_217 |= V_87 -> V_96 &
V_218 ;
V_211 . V_217 |= ( V_219 <<
V_220 ) &
V_221 ;
V_211 . V_222 |=
V_223 ;
V_211 . V_209 = V_209 ;
V_211 . V_224 = V_87 -> V_17 ;
if ( V_87 -> V_96 == V_97 ) {
V_129 = F_1 ( V_2 ,
& V_211 . V_225 ,
V_87 -> V_89 . V_100 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
}
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_211 ,
sizeof( V_211 ) ,
(struct V_57 * ) & V_213 ,
sizeof( V_213 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_22 , V_129 ) ;
return V_129 ;
}
V_87 -> V_165 = V_213 . V_164 ;
V_87 -> V_26 = ( V_9 V_226 * ) ( ( V_227 ) V_2 -> V_39 +
( V_227 ) V_213 . V_228 ) ;
if ( V_87 -> V_96 == V_229 ) {
V_87 -> V_230 = ( T_4 V_226 * ) ( ( V_227 ) V_2 -> V_231
+ V_213 . V_232 ) ;
V_87 -> V_89 . V_233 =
( T_4 V_226 * ) ( ( V_227 ) V_2 -> V_231 +
V_213 . V_234 ) ;
}
F_20 ( L_23 , V_87 -> V_165 , V_87 -> V_17 ) ;
return V_129 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_86 * V_87 ;
T_2 V_235 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < 1 << V_190 -> V_208 ; V_80 ++ ) {
V_235 = V_190 -> V_206 [ V_80 ] ;
if ( V_235 >= V_236 )
return - V_7 ;
V_87 = & V_2 -> V_237 [ V_235 ] ;
if ( V_87 -> V_92 != V_238 )
return - V_7 ;
V_190 -> V_203 [ V_80 ] . V_209 = V_87 -> V_165 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_239 [ V_236 ] = { ( T_2 ) - 1 } ;
struct V_189 * V_190 = & V_2 -> V_190 ;
T_4 V_165 ;
T_2 V_80 ;
for ( V_80 = 0 ; V_80 < V_236 ; V_80 ++ )
V_239 [ V_2 -> V_237 [ V_80 ] . V_165 ] = V_80 ;
for ( V_80 = 0 ; V_80 < 1 << V_190 -> V_208 ; V_80 ++ ) {
if ( V_190 -> V_203 [ V_80 ] . V_209 > V_236 )
return - V_7 ;
V_165 = ( T_4 ) V_190 -> V_203 [ V_80 ] . V_209 ;
if ( V_239 [ V_165 ] > V_236 )
return - V_7 ;
V_190 -> V_206 [ V_80 ] = V_239 [ V_165 ] ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_3 V_16 ;
V_16 = sizeof( struct V_240 ) * V_241 ;
V_2 -> V_242 =
F_24 ( V_2 -> V_38 , V_16 , V_21 ) ;
if ( ! V_2 -> V_242 )
return - V_22 ;
F_71 ( V_2 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 ,
T_2 V_243 )
{
struct V_240 * V_242 = V_2 -> V_242 ;
unsigned int V_80 ;
if ( ! V_243 ) {
F_3 ( L_24 ) ;
V_243 = 1 ;
}
V_2 -> V_243 = V_243 ;
for ( V_80 = 0 ; V_80 < V_241 ; V_80 ++ )
V_242 [ V_80 ] . V_244 /= V_243 ;
V_2 -> V_245 /= V_243 ;
}
int F_53 ( struct V_12 * V_53 ,
struct V_54 * V_55 ,
T_3 V_246 ,
struct V_57 * V_58 ,
T_3 V_74 )
{
struct V_47 * V_48 ;
int V_129 ;
V_48 = F_26 ( V_53 , V_55 , V_246 ,
V_58 , V_74 ) ;
if ( F_14 ( F_29 ( V_48 ) ) ) {
if ( V_48 == F_21 ( - V_83 ) )
F_20 ( L_25 ,
F_73 ( V_48 ) ) ;
else
F_3 ( L_25 ,
F_73 ( V_48 ) ) ;
return F_73 ( V_48 ) ;
}
V_129 = F_51 ( V_48 , V_53 ) ;
if ( F_14 ( V_129 ) ) {
if ( V_53 -> V_82 )
F_3 ( L_26 , V_129 ) ;
else
F_20 ( L_26 , V_129 ) ;
}
return V_129 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_247 V_211 ;
struct V_248 V_213 ;
int V_129 ;
memset ( & V_211 , 0x0 , sizeof( struct V_247 ) ) ;
V_211 . V_68 . V_77 = V_249 ;
V_211 . V_250 |= ( V_103 -> V_106 / 4 ) &
V_251 ;
V_211 . V_252 |=
V_253 ;
V_211 . V_254 = V_103 -> V_254 ;
V_211 . V_255 = V_103 -> V_17 ;
V_129 = F_1 ( V_2 ,
& V_211 . V_256 ,
V_103 -> V_105 . V_100 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_211 ,
sizeof( V_211 ) ,
(struct V_57 * ) & V_213 ,
sizeof( V_213 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_27 , V_129 ) ;
return V_129 ;
}
V_103 -> V_165 = V_213 . V_209 ;
V_103 -> V_257 = ( V_9 V_226 * ) ( ( V_227 ) V_2 -> V_39 +
V_213 . V_258 ) ;
if ( V_213 . V_259 )
V_103 -> V_260 =
( V_9 V_226 * ) ( ( V_227 ) V_2 -> V_39 +
V_213 . V_259 ) ;
if ( V_213 . V_261 )
V_103 -> V_262 =
( V_9 V_226 * ) ( ( V_227 ) V_2 -> V_39 +
V_213 . V_261 ) ;
F_20 ( L_28 , V_103 -> V_165 , V_103 -> V_17 ) ;
return V_129 ;
}
int F_75 ( struct V_1 * V_2 , T_2 V_235 ,
struct V_86 * * V_87 ,
struct V_102 * * V_103 )
{
if ( V_235 >= V_236 ) {
F_3 ( L_29 , V_235 ,
V_236 ) ;
return - V_7 ;
}
* V_87 = & V_2 -> V_237 [ V_235 ] ;
* V_103 = & V_2 -> V_263 [ V_235 ] ;
return 0 ;
}
void F_76 ( struct V_1 * V_2 )
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
F_35 ( & V_48 -> V_78 ) ;
}
}
void F_77 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
unsigned long V_69 ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
while ( F_78 ( & V_53 -> V_50 ) != 0 ) {
F_28 ( & V_53 -> V_81 , V_69 ) ;
F_41 ( 20 ) ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
}
F_28 ( & V_53 -> V_81 , V_69 ) ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_264 V_156 ;
struct V_265 V_158 ;
int V_129 ;
memset ( & V_156 , 0x0 , sizeof( struct V_155 ) ) ;
V_156 . V_209 = V_103 -> V_165 ;
V_156 . V_68 . V_77 = V_266 ;
V_129 = F_53 ( V_53 ,
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
void F_81 ( struct V_1 * V_2 , bool V_267 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
unsigned long V_69 ;
F_27 ( & V_53 -> V_81 , V_69 ) ;
V_2 -> V_53 . V_82 = V_267 ;
F_28 ( & V_53 -> V_81 , V_69 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
T_2 V_268 = V_2 -> V_33 . V_17 ;
F_42 ( V_2 -> V_33 . V_23 != V_268 , L_31 ) ;
F_13 ( V_268 , V_2 -> V_39 + V_269 ) ;
}
int F_83 ( struct V_1 * V_2 , V_9 V_270 )
{
struct V_12 * V_53 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
struct V_177 V_178 ;
int V_129 ;
V_129 = F_60 ( V_2 , & V_178 , V_274 ) ;
if ( V_129 ) {
F_84 ( L_32 ) ;
return V_129 ;
}
if ( ( V_178 . V_198 . V_33 . V_275 & V_270 ) != V_270 ) {
F_85 ( L_33 ,
V_178 . V_198 . V_33 . V_275 , V_270 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_68 . V_69 = 0 ;
V_55 . V_188 . V_173 = V_274 ;
V_55 . V_198 . V_33 . V_277 = V_270 ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_34 , V_129 ) ;
return V_129 ;
}
int F_86 ( struct V_1 * V_2 )
{
V_9 V_278 = F_46 ( V_2 , V_279 ) ;
int V_280 ;
if ( F_14 ( V_278 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
V_280 = ( V_278 & V_281 ) >>
V_282 ;
F_20 ( L_35 , V_280 ) ;
if ( ( V_280 < 32 ) || V_280 > V_283 ) {
F_3 ( L_36 , V_280 ) ;
return - V_7 ;
}
V_2 -> V_6 = V_280 ;
return V_280 ;
}
int F_87 ( struct V_1 * V_2 )
{
V_9 V_284 ;
V_9 V_285 ;
V_9 V_286 ;
V_284 = F_46 ( V_2 , V_287 ) ;
V_285 = F_46 ( V_2 ,
V_288 ) ;
if ( F_14 ( ( V_284 == V_153 ) ||
( V_285 == V_153 ) ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
F_84 ( L_37 ,
( V_284 & V_289 ) >>
V_290 ,
V_284 & V_291 ) ;
if ( V_284 < V_292 ) {
F_3 ( L_38 ) ;
return - 1 ;
}
F_84 ( L_39 ,
( V_285 & V_293 ) >>
V_294 ,
( V_285 & V_295 ) >>
V_296 ,
( V_285 & V_297 ) ,
( V_285 & V_298 ) >>
V_299 ) ;
V_286 =
( V_285 & V_293 ) |
( V_285 & V_295 ) |
( V_285 & V_297 ) ;
if ( V_286 < V_300 ) {
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
F_56 ( V_2 -> V_38 , V_53 -> V_48 ) ;
V_53 -> V_48 = NULL ;
V_16 = F_5 ( V_53 -> V_17 ) ;
if ( V_15 -> V_18 )
F_55 ( V_2 -> V_38 , V_16 , V_15 -> V_18 ,
V_15 -> V_20 ) ;
V_15 -> V_18 = NULL ;
V_16 = F_8 ( V_53 -> V_17 ) ;
if ( V_28 -> V_18 )
F_55 ( V_2 -> V_38 , V_16 , V_28 -> V_18 ,
V_28 -> V_20 ) ;
V_28 -> V_18 = NULL ;
V_16 = F_10 ( V_33 -> V_17 ) ;
if ( V_2 -> V_33 . V_18 )
F_55 ( V_2 -> V_38 , V_16 , V_33 -> V_18 ,
V_33 -> V_20 ) ;
V_33 -> V_18 = NULL ;
}
void F_89 ( struct V_1 * V_2 , bool V_115 )
{
V_2 -> V_53 . V_115 = V_115 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
F_91 ( & V_139 -> V_144 ) ;
V_139 -> V_141 =
F_6 ( V_2 -> V_38 ,
sizeof( * V_139 -> V_141 ) ,
& V_139 -> V_301 , V_21 ) ;
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
F_13 ( 0x0 , V_2 -> V_39 + V_302 ) ;
F_13 ( 0x0 , V_2 -> V_39 + V_303 ) ;
F_55 ( V_2 -> V_38 , sizeof( * V_139 -> V_141 ) ,
V_139 -> V_141 , V_139 -> V_301 ) ;
V_139 -> V_141 = NULL ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = & V_2 -> V_139 ;
V_9 V_34 , V_35 ;
V_34 = F_11 ( V_139 -> V_301 ) ;
V_35 = F_12 ( V_139 -> V_301 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_302 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_303 ) ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
bool V_304 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
V_9 V_305 , V_306 , V_307 , V_34 , V_35 ;
int V_129 ;
V_307 = F_46 ( V_2 , V_170 ) ;
if ( F_14 ( V_307 == V_153 ) ) {
F_3 ( L_17 ) ;
return - V_133 ;
}
if ( ! ( V_307 & V_308 ) ) {
F_3 ( L_41 ) ;
return - V_83 ;
}
V_53 -> V_17 = V_309 ;
V_53 -> V_19 = V_2 -> V_38 ;
V_53 -> V_115 = false ;
V_53 -> V_67 = 0 ;
F_96 ( & V_53 -> V_50 , 0 ) ;
if ( V_304 )
F_91 ( & V_53 -> V_81 ) ;
V_129 = F_23 ( V_53 ) ;
if ( V_129 )
goto error;
V_129 = F_4 ( V_53 ) ;
if ( V_129 )
goto error;
V_129 = F_7 ( V_53 ) ;
if ( V_129 )
goto error;
V_53 -> V_15 . V_26 = ( V_9 V_226 * ) ( ( V_227 ) V_2 -> V_39 +
V_310 ) ;
V_34 = F_11 ( V_53 -> V_15 . V_20 ) ;
V_35 = F_12 ( V_53 -> V_15 . V_20 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_311 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_312 ) ;
V_34 = F_11 ( V_53 -> V_28 . V_20 ) ;
V_35 = F_12 ( V_53 -> V_28 . V_20 ) ;
F_13 ( V_34 , V_2 -> V_39 + V_313 ) ;
F_13 ( V_35 , V_2 -> V_39 + V_314 ) ;
V_305 = 0 ;
V_305 |= V_53 -> V_17 & V_315 ;
V_305 |= ( sizeof( struct V_54 ) <<
V_316 ) &
V_317 ;
V_306 = 0 ;
V_306 |= V_53 -> V_17 & V_318 ;
V_306 |= ( sizeof( struct V_57 ) <<
V_319 ) &
V_320 ;
F_13 ( V_305 , V_2 -> V_39 + V_321 ) ;
F_13 ( V_306 , V_2 -> V_39 + V_322 ) ;
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
if ( V_85 -> V_235 >= V_236 ) {
F_3 ( L_42 ,
V_85 -> V_235 , V_236 ) ;
return - V_7 ;
}
V_87 = & V_2 -> V_237 [ V_85 -> V_235 ] ;
V_103 = & V_2 -> V_263 [ V_85 -> V_235 ] ;
memset ( V_87 , 0x0 , sizeof( struct V_86 ) ) ;
memset ( V_103 , 0x0 , sizeof( struct V_102 ) ) ;
V_103 -> V_17 = V_85 -> V_323 ;
V_103 -> V_92 = V_85 -> V_92 ;
V_103 -> V_235 = V_85 -> V_235 ;
V_103 -> V_254 = V_85 -> V_254 ;
V_87 -> V_17 = V_85 -> V_323 ;
V_87 -> V_92 = V_85 -> V_92 ;
V_87 -> V_235 = V_85 -> V_235 ;
V_87 -> V_96 = V_85 -> V_96 ;
if ( V_85 -> V_92 == V_93 )
V_87 -> V_324 =
F_98 ( V_9 , V_2 -> V_324 , V_325 ) ;
V_129 = F_30 ( V_2 , V_85 , V_87 ) ;
if ( V_129 )
goto error;
V_129 = F_33 ( V_2 , V_85 , V_103 ) ;
if ( V_129 )
goto error;
V_129 = F_74 ( V_2 , V_103 ) ;
if ( V_129 )
goto error;
V_129 = F_67 ( V_2 , V_87 , V_103 -> V_165 ) ;
if ( V_129 )
goto V_326;
return 0 ;
V_326:
F_79 ( V_2 , V_103 ) ;
error:
F_54 ( V_2 , V_87 , V_103 ) ;
return V_129 ;
}
void F_99 ( struct V_1 * V_2 , T_2 V_235 )
{
struct V_86 * V_87 ;
struct V_102 * V_103 ;
if ( V_235 >= V_236 ) {
F_3 ( L_42 , V_235 ,
V_236 ) ;
return;
}
V_87 = & V_2 -> V_237 [ V_235 ] ;
V_103 = & V_2 -> V_263 [ V_235 ] ;
F_52 ( V_2 , V_87 ) ;
F_79 ( V_2 , V_103 ) ;
F_54 ( V_2 , V_87 , V_103 ) ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_177 * V_273 )
{
return F_60 ( V_2 , V_273 , V_327 ) ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_328 * V_329 )
{
struct V_177 V_178 ;
int V_330 ;
V_330 = F_60 ( V_2 , & V_178 ,
V_175 ) ;
if ( V_330 )
return V_330 ;
memcpy ( & V_329 -> V_331 , & V_178 . V_198 . V_331 ,
sizeof( V_178 . V_198 . V_331 ) ) ;
V_2 -> V_176 = V_178 . V_198 . V_331 . V_176 ;
V_330 = F_60 ( V_2 , & V_178 ,
V_332 ) ;
if ( V_330 )
return V_330 ;
memcpy ( & V_329 -> V_333 , & V_178 . V_198 . V_334 ,
sizeof( V_178 . V_198 . V_334 ) ) ;
V_2 -> V_324 = V_178 . V_198 . V_334 . V_335 ;
V_330 = F_60 ( V_2 , & V_178 ,
V_274 ) ;
if ( V_330 )
return V_330 ;
memcpy ( & V_329 -> V_33 , & V_178 . V_198 . V_33 ,
sizeof( V_178 . V_198 . V_33 ) ) ;
V_330 = F_60 ( V_2 , & V_178 ,
V_336 ) ;
if ( V_330 )
return V_330 ;
memcpy ( & V_329 -> V_337 , & V_178 . V_198 . V_337 ,
sizeof( V_178 . V_198 . V_337 ) ) ;
return 0 ;
}
void F_102 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_53 ) ;
}
static T_5 F_103 ( struct V_1 * V_29 ,
T_2 V_338 )
{
struct V_30 * V_31 = V_29 -> V_33 . V_31 ;
if ( ( V_338 < V_339 ) && V_31 -> V_340 [ V_338 ] )
return V_31 -> V_340 [ V_338 ] ;
return V_31 -> V_341 ;
}
void F_104 ( struct V_1 * V_29 , void * V_342 )
{
struct V_43 * V_343 ;
struct V_344 * V_345 ;
struct V_32 * V_33 = & V_29 -> V_33 ;
T_5 V_346 ;
T_2 V_347 , V_348 = 0 ;
T_4 V_25 ;
V_347 = V_33 -> V_23 & ( V_33 -> V_17 - 1 ) ;
V_25 = V_33 -> V_25 ;
V_343 = & V_33 -> V_18 [ V_347 ] ;
V_345 = & V_343 -> V_349 ;
while ( ( V_345 -> V_69 & V_350 ) ==
V_25 ) {
F_20 ( L_43 ,
V_345 -> V_338 , V_345 -> V_351 ,
( V_11 ) V_345 -> V_352 +
( ( V_11 ) V_345 -> V_353 << 32 ) ) ;
V_346 = F_103 ( V_29 ,
V_345 -> V_338 ) ;
V_346 ( V_342 , V_343 ) ;
V_347 ++ ;
V_348 ++ ;
if ( F_14 ( V_347 == V_33 -> V_17 ) ) {
V_347 = 0 ;
V_25 = ! V_25 ;
}
V_343 = & V_33 -> V_18 [ V_347 ] ;
V_345 = & V_343 -> V_349 ;
}
V_33 -> V_23 += V_348 ;
V_33 -> V_25 = V_25 ;
if ( ! V_348 )
return;
F_105 () ;
F_13 ( ( V_9 ) V_33 -> V_23 , V_29 -> V_39 + V_269 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
V_9 V_354 , V_167 , V_355 , V_356 ;
int V_330 ;
V_354 = F_46 ( V_2 , V_170 ) ;
V_355 = F_46 ( V_2 , V_279 ) ;
if ( F_14 ( ( V_354 == V_153 ) ||
( V_355 == V_153 ) ) ) {
F_3 ( L_44 ) ;
return - V_133 ;
}
if ( ( V_354 & V_308 ) == 0 ) {
F_3 ( L_45 ) ;
return - V_7 ;
}
V_167 = ( V_355 & V_357 ) >>
V_358 ;
if ( V_167 == 0 ) {
F_3 ( L_46 ) ;
return - V_7 ;
}
V_356 = V_359 ;
F_13 ( V_356 , V_2 -> V_39 + V_360 ) ;
F_92 ( V_2 ) ;
V_330 = F_57 ( V_2 , V_167 ,
V_171 ) ;
if ( V_330 != 0 ) {
F_3 ( L_47 ) ;
return V_330 ;
}
F_13 ( 0 , V_2 -> V_39 + V_360 ) ;
V_330 = F_57 ( V_2 , V_167 , 0 ) ;
if ( V_330 != 0 ) {
F_3 ( L_48 ) ;
return V_330 ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_361 * V_85 ,
enum V_362 type )
{
struct V_363 * V_182 = & V_85 -> V_182 ;
struct V_364 * V_178 = & V_85 -> V_178 ;
struct V_12 * V_53 ;
int V_129 ;
V_53 = & V_2 -> V_53 ;
V_182 -> V_68 . V_77 = V_365 ;
V_182 -> V_68 . V_69 = 0 ;
V_182 -> type = type ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) V_182 ,
sizeof( * V_182 ) ,
(struct V_57 * ) V_178 ,
sizeof( * V_178 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_49 , V_129 ) ;
return V_129 ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_366 * V_64 )
{
struct V_361 V_85 ;
int V_129 ;
memset ( & V_85 , 0x0 , sizeof( V_85 ) ) ;
V_129 = F_107 ( V_2 , & V_85 , V_367 ) ;
if ( F_109 ( V_129 == 0 ) )
memcpy ( V_64 , & V_85 . V_178 . V_368 ,
sizeof( V_85 . V_178 . V_368 ) ) ;
return V_129 ;
}
int F_110 ( struct V_1 * V_2 , int V_369 )
{
struct V_12 * V_53 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
int V_129 ;
if ( ! F_58 ( V_2 , V_370 ) ) {
F_20 ( L_18 , V_370 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_68 . V_69 = 0 ;
V_55 . V_188 . V_173 = V_370 ;
V_55 . V_198 . V_369 . V_369 = V_369 ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_50 , V_369 , V_129 ) ;
return V_129 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_371 * V_337 )
{
int V_129 ;
struct V_177 V_273 ;
V_129 = F_60 ( V_2 , & V_273 ,
V_336 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_51 , V_129 ) ;
return V_129 ;
}
memcpy ( V_337 , & V_273 . V_198 . V_337 , sizeof( V_273 . V_198 . V_337 ) ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
struct V_177 V_178 ;
int V_129 ;
if ( ! F_58 ( V_2 ,
V_372 ) ) {
F_20 ( L_18 ,
V_372 ) ;
return - V_124 ;
}
V_129 = F_60 ( V_2 , & V_178 ,
V_372 ) ;
if ( F_14 ( V_129 ) )
return V_129 ;
if ( V_178 . V_198 . V_373 . V_374 & ( 1 << V_190 -> V_375 ) ) {
F_3 ( L_52 ,
V_190 -> V_375 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_68 . V_69 =
V_184 ;
V_55 . V_188 . V_173 = V_372 ;
V_55 . V_198 . V_373 . V_376 = V_190 -> V_377 ;
V_55 . V_198 . V_373 . V_378 = 1 << V_190 -> V_375 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_185 . V_186 ,
V_190 -> V_192 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_185 . V_187 = sizeof( * V_190 -> V_191 ) ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_53 ,
V_190 -> V_375 , V_129 ) ;
return - V_7 ;
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 ,
enum V_379 V_380 ,
const T_4 * V_381 , T_2 V_382 , V_9 V_376 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_177 V_178 ;
struct V_383 * V_191 =
V_190 -> V_191 ;
int V_330 ;
if ( F_14 ( V_382 & 0x3 ) )
return - V_7 ;
V_330 = F_59 ( V_2 , & V_178 ,
V_372 ,
V_190 -> V_192 ,
sizeof( * V_190 -> V_191 ) ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
if ( ! ( ( 1 << V_380 ) & V_178 . V_198 . V_373 . V_374 ) ) {
F_3 ( L_54 , V_380 ) ;
return - V_124 ;
}
switch ( V_380 ) {
case V_384 :
if ( V_382 > sizeof( V_191 -> V_381 ) ) {
F_3 ( L_55 ,
V_382 , sizeof( V_191 -> V_381 ) ) ;
return - V_7 ;
}
memcpy ( V_191 -> V_381 , V_381 , V_382 ) ;
V_190 -> V_377 = V_376 ;
V_191 -> V_385 = V_382 >> 2 ;
break;
case V_386 :
V_190 -> V_377 = V_376 ;
break;
default:
F_3 ( L_56 , V_380 ) ;
return - V_7 ;
}
V_330 = F_112 ( V_2 ) ;
if ( F_14 ( V_330 ) )
F_114 ( V_2 , NULL , NULL ) ;
return V_330 ;
}
int F_114 ( struct V_1 * V_2 ,
enum V_379 * V_380 ,
T_4 * V_381 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_177 V_178 ;
struct V_383 * V_191 =
V_190 -> V_191 ;
int V_330 ;
V_330 = F_59 ( V_2 , & V_178 ,
V_372 ,
V_190 -> V_192 ,
sizeof( * V_190 -> V_191 ) ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
V_190 -> V_375 = V_178 . V_198 . V_373 . V_378 ;
if ( V_380 )
* V_380 = V_190 -> V_375 ;
if ( V_381 )
memcpy ( V_381 , V_191 -> V_381 , ( T_3 ) ( V_191 -> V_385 ) << 2 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 ,
enum V_387 V_388 ,
T_2 * V_389 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_177 V_178 ;
int V_330 ;
V_330 = F_59 ( V_2 , & V_178 ,
V_390 ,
V_190 -> V_194 ,
sizeof( * V_190 -> V_193 ) ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
if ( V_389 )
* V_389 = V_190 -> V_193 -> V_391 [ V_388 ] . V_389 ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_392 * V_193 = V_190 -> V_193 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
int V_129 ;
if ( ! F_58 ( V_2 ,
V_390 ) ) {
F_20 ( L_18 ,
V_390 ) ;
return - V_124 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_68 . V_69 =
V_184 ;
V_55 . V_188 . V_173 = V_390 ;
V_55 . V_198 . V_393 . V_394 =
V_395 |
V_396 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_185 . V_186 ,
V_190 -> V_194 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_185 . V_187 = sizeof( * V_193 ) ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_57 , V_129 ) ;
return V_129 ;
}
int F_117 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_392 * V_193 =
V_190 -> V_193 ;
T_2 V_397 = 0 ;
int V_330 , V_80 ;
V_330 = F_115 ( V_2 , 0 , NULL ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
V_193 -> V_391 [ V_398 ] . V_389 =
V_399 | V_400 |
V_401 | V_402 ;
V_193 -> V_391 [ V_403 ] . V_389 =
V_399 | V_400 |
V_401 | V_402 ;
V_193 -> V_391 [ V_404 ] . V_389 =
V_399 | V_400 |
V_401 | V_402 ;
V_193 -> V_391 [ V_405 ] . V_389 =
V_399 | V_400 |
V_401 | V_402 ;
V_193 -> V_391 [ V_406 ] . V_389 =
V_399 | V_400 ;
V_193 -> V_391 [ V_407 ] . V_389 =
V_399 | V_400 ;
V_193 -> V_391 [ V_408 ] . V_389 =
V_399 | V_400 ;
V_193 -> V_391 [ V_409 ] . V_389 =
V_410 | V_411 ;
for ( V_80 = 0 ; V_80 < V_412 ; V_80 ++ ) {
V_397 = V_193 -> V_391 [ V_80 ] . V_389 &
V_193 -> V_413 [ V_80 ] . V_389 ;
if ( V_397 != V_193 -> V_391 [ V_80 ] . V_389 ) {
F_3 ( L_58 ,
V_80 , V_193 -> V_413 [ V_80 ] . V_389 ,
V_193 -> V_391 [ V_80 ] . V_389 ) ;
return - V_124 ;
}
}
V_330 = F_116 ( V_2 ) ;
if ( F_14 ( V_330 ) )
F_115 ( V_2 , 0 , NULL ) ;
return V_330 ;
}
int F_118 ( struct V_1 * V_2 ,
enum V_387 V_388 ,
T_2 V_414 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_392 * V_193 = V_190 -> V_193 ;
T_2 V_413 ;
int V_330 ;
if ( V_388 >= V_412 ) {
F_3 ( L_59 , V_388 ) ;
return - V_7 ;
}
V_330 = F_115 ( V_2 , V_388 , NULL ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
V_413 = V_193 -> V_413 [ V_388 ] . V_389 ;
if ( ( V_414 & V_413 ) != V_414 ) {
F_3 ( L_60 ,
V_388 , V_414 , V_413 ) ;
}
V_193 -> V_391 [ V_388 ] . V_389 = V_414 ;
V_330 = F_116 ( V_2 ) ;
if ( F_14 ( V_330 ) )
F_115 ( V_2 , 0 , NULL ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 ,
T_2 V_415 , T_2 V_416 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
if ( F_14 ( V_415 >= ( 1 << V_190 -> V_208 ) ) )
return - V_7 ;
if ( F_14 ( ( V_416 > V_236 ) ) )
return - V_7 ;
V_190 -> V_206 [ V_415 ] = V_416 ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
int V_129 ;
if ( ! F_58 (
V_2 , V_197 ) ) {
F_20 ( L_18 ,
V_197 ) ;
return - V_124 ;
}
V_129 = F_68 ( V_2 ) ;
if ( V_129 ) {
F_3 ( L_61 ) ;
return V_129 ;
}
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_68 . V_69 =
V_184 ;
V_55 . V_188 . V_173 = V_197 ;
V_55 . V_198 . V_199 . V_16 = V_190 -> V_208 ;
V_55 . V_198 . V_199 . V_417 = 0xFFFFFFFF ;
V_129 = F_1 ( V_2 ,
& V_55 . V_185 . V_186 ,
V_190 -> V_204 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_185 . V_187 = ( 1ULL << V_190 -> V_208 ) *
sizeof( struct V_202 ) ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_62 , V_129 ) ;
return V_129 ;
}
int F_121 ( struct V_1 * V_2 , V_9 * V_418 )
{
struct V_189 * V_190 = & V_2 -> V_190 ;
struct V_177 V_178 ;
V_9 V_196 ;
int V_80 , V_330 ;
V_196 = ( 1ULL << V_190 -> V_208 ) *
sizeof( struct V_202 ) ;
V_330 = F_59 ( V_2 , & V_178 ,
V_197 ,
V_190 -> V_204 ,
V_196 ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
if ( ! V_418 )
return 0 ;
V_330 = F_69 ( V_2 ) ;
if ( F_14 ( V_330 ) )
return V_330 ;
for ( V_80 = 0 ; V_80 < ( 1 << V_190 -> V_208 ) ; V_80 ++ )
V_418 [ V_80 ] = V_190 -> V_206 [ V_80 ] ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_2 V_419 )
{
int V_330 ;
memset ( & V_2 -> V_190 , 0x0 , sizeof( V_2 -> V_190 ) ) ;
V_330 = F_65 ( V_2 , V_419 ) ;
if ( F_14 ( V_330 ) )
goto V_420;
V_330 = F_61 ( V_2 ) ;
if ( F_14 ( V_330 ) )
goto V_421;
V_330 = F_63 ( V_2 ) ;
if ( F_14 ( V_330 ) )
goto V_422;
return 0 ;
V_422:
F_62 ( V_2 ) ;
V_421:
F_66 ( V_2 ) ;
V_420:
return V_330 ;
}
void F_123 ( struct V_1 * V_2 )
{
F_66 ( V_2 ) ;
F_62 ( V_2 ) ;
F_64 ( V_2 ) ;
memset ( & V_2 -> V_190 , 0x0 , sizeof( V_2 -> V_190 ) ) ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_423 * V_424 = & V_2 -> V_424 ;
V_424 -> V_425 =
F_6 ( V_2 -> V_38 , V_426 ,
& V_424 -> V_427 , V_21 ) ;
if ( F_14 ( ! V_424 -> V_425 ) )
return - V_22 ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 ,
V_9 V_428 )
{
struct V_423 * V_424 = & V_2 -> V_424 ;
V_424 -> V_429 =
F_6 ( V_2 -> V_38 , V_428 ,
& V_424 -> V_430 , V_21 ) ;
if ( F_14 ( ! V_424 -> V_429 ) ) {
V_424 -> V_428 = 0 ;
return - V_22 ;
}
V_424 -> V_428 = V_428 ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_423 * V_424 = & V_2 -> V_424 ;
if ( V_424 -> V_425 ) {
F_55 ( V_2 -> V_38 , V_426 , V_424 -> V_425 ,
V_424 -> V_427 ) ;
V_424 -> V_425 = NULL ;
}
}
void F_127 ( struct V_1 * V_2 )
{
struct V_423 * V_424 = & V_2 -> V_424 ;
if ( V_424 -> V_429 ) {
F_55 ( V_2 -> V_38 , V_424 -> V_428 ,
V_424 -> V_429 ,
V_424 -> V_430 ) ;
V_424 -> V_429 = NULL ;
}
}
int F_128 ( struct V_1 * V_2 )
{
struct V_423 * V_424 = & V_2 -> V_424 ;
struct V_12 * V_53 ;
struct V_271 V_55 ;
struct V_272 V_273 ;
int V_129 ;
memset ( & V_55 , 0x0 , sizeof( V_55 ) ) ;
V_53 = & V_2 -> V_53 ;
V_55 . V_68 . V_77 = V_276 ;
V_55 . V_188 . V_173 = V_431 ;
V_129 = F_1 ( V_2 ,
& V_55 . V_198 . V_424 . V_432 ,
V_424 -> V_430 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_129 = F_1 ( V_2 ,
& V_55 . V_198 . V_424 . V_433 ,
V_424 -> V_427 ) ;
if ( F_14 ( V_129 ) ) {
F_3 ( L_19 ) ;
return V_129 ;
}
V_55 . V_198 . V_424 . V_428 = V_424 -> V_428 ;
V_129 = F_53 ( V_53 ,
(struct V_54 * ) & V_55 ,
sizeof( V_55 ) ,
(struct V_57 * ) & V_273 ,
sizeof( V_273 ) ) ;
if ( F_14 ( V_129 ) )
F_3 ( L_63 , V_129 ) ;
return V_129 ;
}
bool F_129 ( struct V_1 * V_2 )
{
return F_58 ( V_2 ,
V_434 ) ;
}
int F_130 ( struct V_1 * V_2 ,
V_9 V_435 )
{
if ( ! V_2 -> V_243 ) {
F_3 ( L_64 ) ;
return - V_436 ;
}
V_2 -> V_245 = V_435 /
V_2 -> V_243 ;
return 0 ;
}
int F_131 ( struct V_1 * V_2 ,
V_9 V_437 )
{
if ( ! V_2 -> V_243 ) {
F_3 ( L_64 ) ;
return - V_436 ;
}
V_2 -> V_242 [ V_438 ] . V_244 =
V_437 / V_2 -> V_243 ;
return 0 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_242 )
F_56 ( V_2 -> V_38 , V_2 -> V_242 ) ;
V_2 -> V_242 = NULL ;
}
int F_133 ( struct V_1 * V_2 )
{
struct V_177 V_178 ;
T_2 V_439 ;
int V_330 ;
V_330 = F_60 ( V_2 , & V_178 ,
V_434 ) ;
if ( V_330 ) {
if ( V_330 == - V_124 ) {
F_20 ( L_18 ,
V_434 ) ;
V_330 = 0 ;
} else {
F_3 ( L_65 ,
V_330 ) ;
}
F_134 ( V_2 ) ;
return V_330 ;
}
V_330 = F_70 ( V_2 ) ;
if ( V_330 )
goto V_134;
V_439 = V_178 . V_198 . V_440 . V_243 ;
F_72 ( V_2 , V_439 ) ;
F_135 ( V_2 ) ;
return 0 ;
V_134:
F_132 ( V_2 ) ;
return V_330 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_240 * V_242 = V_2 -> V_242 ;
if ( ! V_242 )
return;
V_242 [ V_438 ] . V_244 =
V_441 ;
V_242 [ V_438 ] . V_442 =
V_443 ;
V_242 [ V_438 ] . V_444 =
V_445 ;
V_242 [ V_446 ] . V_244 =
V_447 ;
V_242 [ V_446 ] . V_442 =
V_448 ;
V_242 [ V_446 ] . V_444 =
V_449 ;
V_242 [ V_450 ] . V_244 =
V_451 ;
V_242 [ V_450 ] . V_442 =
V_452 ;
V_242 [ V_450 ] . V_444 =
V_453 ;
V_242 [ V_454 ] . V_244 =
V_455 ;
V_242 [ V_454 ] . V_442 =
V_456 ;
V_242 [ V_454 ] . V_444 =
V_457 ;
V_242 [ V_458 ] . V_244 =
V_459 ;
V_242 [ V_458 ] . V_442 =
V_460 ;
V_242 [ V_458 ] . V_444 =
V_461 ;
}
unsigned int F_136 ( struct V_1 * V_2 )
{
return V_2 -> V_245 ;
}
unsigned int F_137 ( struct V_1 * V_2 )
{
struct V_240 * V_242 = V_2 -> V_242 ;
if ( V_242 )
return V_242 [ V_438 ] . V_244 ;
return 0 ;
}
void F_138 ( struct V_1 * V_2 ,
enum V_462 V_463 ,
struct V_240 * V_464 )
{
struct V_240 * V_242 = V_2 -> V_242 ;
if ( V_463 >= V_241 )
return;
V_242 [ V_463 ] . V_244 = V_464 -> V_244 ;
if ( V_2 -> V_243 )
V_242 [ V_463 ] . V_244 /=
V_2 -> V_243 ;
V_242 [ V_463 ] . V_442 = V_464 -> V_442 ;
if ( V_464 -> V_444 != V_465 )
V_242 [ V_463 ] . V_444 = V_464 -> V_444 ;
}
void F_139 ( struct V_1 * V_2 ,
enum V_462 V_463 ,
struct V_240 * V_464 )
{
struct V_240 * V_242 = V_2 -> V_242 ;
if ( V_463 >= V_241 )
return;
V_464 -> V_244 = V_242 [ V_463 ] . V_244 ;
if ( V_2 -> V_243 )
V_464 -> V_244 *= V_2 -> V_243 ;
V_464 -> V_442 =
V_242 [ V_463 ] . V_442 ;
V_464 -> V_444 = V_242 [ V_463 ] . V_444 ;
}
