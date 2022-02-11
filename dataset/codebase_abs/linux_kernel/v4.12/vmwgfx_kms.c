void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_7 ) ;
F_6 ( & V_2 -> V_5 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
T_1 * V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct {
T_1 V_15 ;
T_2 V_4 ;
} * V_15 ;
T_1 V_16 = V_11 * V_12 * 4 ;
T_1 V_17 = sizeof( * V_15 ) + V_16 ;
if ( ! V_10 )
return - V_18 ;
V_15 = F_8 ( V_9 , V_17 ) ;
if ( F_9 ( V_15 == NULL ) ) {
F_10 ( L_1 ) ;
return - V_19 ;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
memcpy ( & V_15 [ 1 ] , V_10 , V_16 ) ;
V_15 -> V_15 = V_20 ;
V_15 -> V_4 . V_21 = 0 ;
V_15 -> V_4 . V_11 = V_11 ;
V_15 -> V_4 . V_12 = V_12 ;
V_15 -> V_4 . V_13 = V_13 ;
V_15 -> V_4 . V_14 = V_14 ;
F_11 ( V_9 , V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_24 V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
void * V_28 ;
bool V_29 ;
int V_30 ;
V_26 = 0 ;
V_27 = ( V_11 * V_12 * 4 + V_31 - 1 ) >> V_32 ;
V_30 = F_13 ( & V_23 -> V_33 , true , false , NULL ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_10 ( L_2 ) ;
return - V_18 ;
}
V_30 = F_14 ( & V_23 -> V_33 , V_26 , V_27 , & V_25 ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_34;
V_28 = F_15 ( & V_25 , & V_29 ) ;
V_30 = F_7 ( V_9 , V_28 , V_11 , V_12 ,
V_13 , V_14 ) ;
F_16 ( & V_25 ) ;
V_34:
F_17 ( & V_23 -> V_33 ) ;
return V_30 ;
}
static void F_18 ( struct V_8 * V_9 ,
bool V_35 , int V_36 , int V_37 )
{
T_1 * V_38 = V_9 -> V_39 ;
T_3 V_40 ;
F_19 ( & V_9 -> V_41 ) ;
F_20 ( V_35 ? 1 : 0 , V_38 + V_42 ) ;
F_20 ( V_36 , V_38 + V_43 ) ;
F_20 ( V_37 , V_38 + V_44 ) ;
V_40 = F_21 ( V_38 + V_45 ) ;
F_20 ( ++ V_40 , V_38 + V_45 ) ;
F_22 ( & V_9 -> V_41 ) ;
}
void F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
T_4 * V_52 )
{
struct V_24 V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
T_5 * V_53 ;
unsigned V_54 ;
void * V_28 ;
bool V_29 ;
struct V_55 {
T_4 V_52 ;
T_6 V_56 ;
} * V_15 ;
int V_57 , V_30 ;
V_15 = F_24 ( V_52 , struct V_55 , V_52 ) ;
if ( ! V_47 -> V_58 . V_10 )
return;
if ( V_15 -> V_56 . V_59 . V_60 != 0 || V_15 -> V_56 . V_59 . V_61 != 0 ) {
F_10 ( L_3 ) ;
return;
}
if ( V_15 -> V_52 . V_62 < 64 ) {
F_10 ( L_4 ) ;
return;
}
V_53 = ( T_5 * ) & V_15 [ 1 ] ;
V_54 = ( V_15 -> V_52 . V_62 - sizeof( T_6 ) ) /
sizeof( T_5 ) ;
if ( V_15 -> V_56 . V_63 . V_64 . V_65 % V_31 ||
V_53 -> V_36 != 0 || V_53 -> V_37 != 0 || V_53 -> V_66 != 0 ||
V_53 -> V_67 != 0 || V_53 -> V_68 != 0 || V_53 -> V_69 != 0 ||
V_53 -> V_70 != 1 || V_54 != 1 ) {
F_10 ( L_5 ) ;
F_10 ( L_6 ,
V_53 -> V_67 , V_53 -> V_68 , V_53 -> V_69 ,
V_53 -> V_36 , V_53 -> V_37 , V_53 -> V_66 ,
V_53 -> V_71 , V_53 -> V_72 , V_53 -> V_70 , V_54 ,
V_15 -> V_56 . V_63 . V_64 . V_65 ) ;
return;
}
V_26 = V_15 -> V_56 . V_63 . V_64 . V_65 >> V_32 ;
V_27 = ( 64 * 64 * 4 ) >> V_32 ;
V_30 = F_13 ( V_51 , true , false , NULL ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_10 ( L_2 ) ;
return;
}
V_30 = F_14 ( V_51 , V_26 , V_27 , & V_25 ) ;
if ( F_9 ( V_30 != 0 ) )
goto V_34;
V_28 = F_15 ( & V_25 , & V_29 ) ;
if ( V_53 -> V_71 == 64 && V_15 -> V_56 . V_63 . V_73 == 64 * 4 ) {
memcpy ( V_47 -> V_58 . V_10 , V_28 , 64 * 64 * 4 ) ;
} else {
for ( V_57 = 0 ; V_57 < V_53 -> V_72 ; V_57 ++ )
memcpy ( V_47 -> V_58 . V_10 + V_57 * 64 ,
V_28 + V_57 * V_15 -> V_56 . V_63 . V_73 ,
V_53 -> V_71 * 4 ) ;
}
V_47 -> V_58 . V_74 ++ ;
F_16 ( & V_25 ) ;
V_34:
F_17 ( V_51 ) ;
}
void F_25 ( struct V_8 * V_9 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_1 * V_2 ;
struct V_77 * V_6 ;
F_26 ( V_76 ) ;
F_27 (crtc, dev) {
V_2 = F_28 ( V_6 ) ;
V_2 -> V_78 = 0 ;
V_2 -> V_79 = 0 ;
}
F_29 ( V_76 ) ;
}
void F_30 ( struct V_8 * V_9 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_1 * V_2 ;
struct V_77 * V_6 ;
F_31 ( & V_76 -> V_80 . V_81 ) ;
F_32 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_28 ( V_6 ) ;
if ( ! V_2 -> V_82 ||
V_2 -> V_83 == V_2 -> V_82 -> V_58 . V_74 )
continue;
V_2 -> V_83 = V_2 -> V_82 -> V_58 . V_74 ;
F_7 ( V_9 ,
V_2 -> V_82 -> V_58 . V_10 ,
64 , 64 ,
V_2 -> V_78 + V_2 -> V_84 ,
V_2 -> V_79 + V_2 -> V_85 ) ;
}
F_33 ( & V_76 -> V_80 . V_81 ) ;
}
void F_34 ( struct V_86 * V_87 )
{
F_18 ( V_87 -> V_76 -> V_88 , false , 0 , 0 ) ;
F_2 ( V_87 ) ;
}
void F_35 ( struct V_86 * V_87 )
{
F_2 ( V_87 ) ;
}
void F_36 ( struct V_89 * V_90 ,
bool V_91 )
{
if ( V_90 -> V_92 ) {
if ( V_90 -> V_93 ) {
F_37 ( & V_90 -> V_92 -> V_94 ) ;
V_90 -> V_93 -- ;
}
if ( V_91 ) {
if ( V_90 -> V_93 )
F_10 ( L_7 ) ;
F_38 ( & V_90 -> V_92 ) ;
}
}
}
void
F_39 ( struct V_86 * V_87 ,
struct V_95 * V_96 )
{
struct V_89 * V_90 = F_40 ( V_96 ) ;
F_36 ( V_90 , false ) ;
}
int
F_41 ( struct V_86 * V_87 ,
struct V_95 * V_97 )
{
struct V_98 * V_99 = V_97 -> V_99 ;
struct V_89 * V_90 = F_40 ( V_97 ) ;
if ( V_90 -> V_92 )
F_38 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_23 )
F_42 ( & V_90 -> V_23 ) ;
if ( V_99 ) {
if ( F_43 ( V_99 ) -> V_23 ) {
V_90 -> V_23 = F_44 ( V_99 ) -> V_100 ;
F_45 ( V_90 -> V_23 ) ;
} else {
V_90 -> V_92 = F_46 ( V_99 ) -> V_101 ;
F_47 ( V_90 -> V_92 ) ;
}
}
return 0 ;
}
void
F_48 ( struct V_86 * V_87 ,
struct V_95 * V_96 )
{
struct V_77 * V_6 = V_87 -> V_102 -> V_6 ? : V_96 -> V_6 ;
struct V_8 * V_9 = F_49 ( V_6 -> V_76 ) ;
struct V_1 * V_2 = F_28 ( V_6 ) ;
struct V_89 * V_90 = F_40 ( V_87 -> V_102 ) ;
T_7 V_78 , V_79 ;
int V_30 = 0 ;
V_78 = V_2 -> V_78 ;
V_79 = V_2 -> V_79 ;
V_2 -> V_82 = V_90 -> V_92 ;
V_2 -> V_103 = V_90 -> V_23 ;
if ( V_90 -> V_92 ) {
V_2 -> V_83 = V_2 -> V_82 -> V_58 . V_74 ;
V_30 = F_7 ( V_9 ,
V_90 -> V_92 -> V_58 . V_10 ,
64 , 64 , V_78 , V_79 ) ;
} else if ( V_90 -> V_23 ) {
V_30 = F_12 ( V_9 , V_90 -> V_23 ,
V_87 -> V_102 -> V_104 ,
V_87 -> V_102 -> V_105 ,
V_78 , V_79 ) ;
} else {
F_18 ( V_9 , false , 0 , 0 ) ;
return;
}
if ( ! V_30 ) {
V_2 -> V_106 = V_87 -> V_102 -> V_107 + V_2 -> V_108 ;
V_2 -> V_109 = V_87 -> V_102 -> V_110 + V_2 -> V_111 ;
F_18 ( V_9 , true ,
V_2 -> V_106 + V_78 ,
V_2 -> V_109 + V_79 ) ;
} else {
F_10 ( L_8 ) ;
}
}
int F_50 ( struct V_86 * V_87 ,
struct V_95 * V_102 )
{
struct V_98 * V_112 = V_102 -> V_99 ;
bool V_113 ;
struct V_114 V_115 = {
. V_116 = V_102 -> V_117 ,
. y1 = V_102 -> V_118 ,
. V_119 = V_102 -> V_117 + V_102 -> V_120 ,
. V_121 = V_102 -> V_118 + V_102 -> V_122 ,
} ;
struct V_114 V_123 = {
. V_116 = V_102 -> V_107 ,
. y1 = V_102 -> V_110 ,
. V_119 = V_102 -> V_107 + V_102 -> V_104 ,
. V_121 = V_102 -> V_110 + V_102 -> V_105 ,
} ;
struct V_114 V_124 = V_123 ;
int V_30 ;
V_30 = F_51 ( V_87 , V_102 -> V_6 , V_112 ,
& V_115 , & V_123 , & V_124 ,
V_125 ,
V_126 ,
V_126 ,
false , true , & V_113 ) ;
if ( ! V_30 && V_112 ) {
struct V_77 * V_6 = V_102 -> V_6 ;
struct V_127 * V_128 ;
struct V_1 * V_2 = F_28 ( V_6 ) ;
struct V_8 * V_9 = F_49 ( V_6 -> V_76 ) ;
struct V_129 * V_130 = F_43 ( V_112 ) ;
V_128 = F_52 ( V_2 -> V_5 . V_102 ) ;
if ( ( V_123 . V_119 > V_112 -> V_11 ||
V_123 . V_121 > V_112 -> V_12 ) ) {
F_10 ( L_9 ) ;
return - V_18 ;
}
F_31 ( & V_9 -> V_131 ) ;
if ( V_128 -> V_132 && V_9 -> V_133 &&
! ( V_9 -> V_134 == 1 && V_2 -> V_135 )
&& V_9 -> V_133 != V_130 ) {
F_10 ( L_10
L_11 ) ;
V_30 = - V_18 ;
}
F_33 ( & V_9 -> V_131 ) ;
}
return V_30 ;
}
int F_53 ( struct V_86 * V_87 ,
struct V_95 * V_97 )
{
int V_30 = 0 ;
struct V_46 * V_101 = NULL ;
struct V_98 * V_99 = V_97 -> V_99 ;
if ( ! V_99 )
return V_30 ;
if ( V_97 -> V_104 != 64 || V_97 -> V_105 != 64 ) {
F_10 ( L_12 ,
V_97 -> V_104 , V_97 -> V_105 ) ;
V_30 = - V_18 ;
}
if ( ! F_43 ( V_99 ) -> V_23 )
V_101 = F_46 ( V_99 ) -> V_101 ;
if ( V_101 && ! V_101 -> V_58 . V_10 ) {
F_10 ( L_13 ) ;
V_30 = - V_18 ;
}
return V_30 ;
}
int F_54 ( struct V_77 * V_6 ,
struct V_136 * V_97 )
{
struct V_1 * V_2 = F_28 ( V_97 -> V_6 ) ;
int V_137 = 1 << F_55 ( & V_2 -> V_5 ) ;
bool V_138 = V_97 -> V_139 &
F_56 ( F_57 ( V_6 -> V_3 ) ) ;
if ( V_138 != V_97 -> V_140 )
return - V_18 ;
if ( V_97 -> V_137 != V_137 &&
V_97 -> V_137 != 0 ) {
F_10 ( L_14 ) ;
return - V_18 ;
}
if ( V_97 -> V_141 . V_142 == 0 )
V_97 -> V_143 . V_142 = V_97 -> V_141 . clock ;
return 0 ;
}
void F_58 ( struct V_77 * V_6 ,
struct V_136 * V_144 )
{
}
void F_59 ( struct V_77 * V_6 ,
struct V_136 * V_144 )
{
struct V_145 * V_146 = V_6 -> V_102 -> V_146 ;
if ( V_146 ) {
V_6 -> V_102 -> V_146 = NULL ;
F_60 ( & V_6 -> V_76 -> V_147 ) ;
if ( F_61 ( V_6 ) == 0 )
F_62 ( V_6 , V_146 ) ;
else
F_63 ( V_6 , V_146 ) ;
F_64 ( & V_6 -> V_76 -> V_147 ) ;
}
}
struct V_136 *
F_65 ( struct V_77 * V_6 )
{
struct V_136 * V_102 ;
struct V_148 * V_128 ;
if ( F_66 ( ! V_6 -> V_102 ) )
return NULL ;
V_128 = F_67 ( V_6 -> V_102 , sizeof( * V_128 ) , V_149 ) ;
if ( ! V_128 )
return NULL ;
V_102 = & V_128 -> V_33 ;
F_68 ( V_6 , V_102 ) ;
return V_102 ;
}
void F_69 ( struct V_77 * V_6 )
{
struct V_148 * V_128 ;
if ( V_6 -> V_102 ) {
F_70 ( V_6 -> V_102 ) ;
F_71 ( F_72 ( V_6 -> V_102 ) ) ;
}
V_128 = F_73 ( sizeof( * V_128 ) , V_149 ) ;
if ( ! V_128 ) {
F_10 ( L_15 ) ;
return;
}
V_6 -> V_102 = & V_128 -> V_33 ;
V_6 -> V_102 -> V_6 = V_6 ;
}
void
F_74 ( struct V_77 * V_6 ,
struct V_136 * V_102 )
{
F_75 ( V_6 , V_102 ) ;
}
struct V_95 *
F_76 ( struct V_86 * V_87 )
{
struct V_95 * V_102 ;
struct V_89 * V_90 ;
V_90 = F_67 ( V_87 -> V_102 , sizeof( * V_90 ) , V_149 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_93 = 0 ;
memset ( & V_90 -> V_150 , 0 , sizeof( V_90 -> V_150 ) ) ;
memset ( & V_90 -> V_151 , 0 , sizeof( V_90 -> V_151 ) ) ;
V_90 -> V_152 = 0 ;
if ( V_90 -> V_92 )
( void ) F_47 ( V_90 -> V_92 ) ;
if ( V_90 -> V_23 )
( void ) F_45 ( V_90 -> V_23 ) ;
V_102 = & V_90 -> V_33 ;
F_77 ( V_87 , V_102 ) ;
return V_102 ;
}
void F_78 ( struct V_86 * V_87 )
{
struct V_89 * V_90 ;
if ( V_87 -> V_102 )
F_79 ( V_87 , V_87 -> V_102 ) ;
V_90 = F_73 ( sizeof( * V_90 ) , V_149 ) ;
if ( ! V_90 ) {
F_10 ( L_16 ) ;
return;
}
V_87 -> V_102 = & V_90 -> V_33 ;
V_87 -> V_102 -> V_87 = V_87 ;
V_87 -> V_102 -> V_153 = V_125 ;
}
void
F_79 ( struct V_86 * V_87 ,
struct V_95 * V_102 )
{
struct V_89 * V_90 = F_40 ( V_102 ) ;
if ( V_90 -> V_150 . V_28 ) {
F_10 ( L_17 ) ;
F_16 ( & V_90 -> V_150 ) ;
}
if ( V_90 -> V_151 . V_28 ) {
F_10 ( L_18 ) ;
F_16 ( & V_90 -> V_151 ) ;
}
if ( V_90 -> V_92 )
F_38 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_23 )
F_42 ( & V_90 -> V_23 ) ;
F_80 ( V_87 , V_102 ) ;
}
struct V_154 *
F_81 ( struct V_155 * V_5 )
{
struct V_154 * V_102 ;
struct V_127 * V_128 ;
if ( F_66 ( ! V_5 -> V_102 ) )
return NULL ;
V_128 = F_67 ( V_5 -> V_102 , sizeof( * V_128 ) , V_149 ) ;
if ( ! V_128 )
return NULL ;
V_102 = & V_128 -> V_33 ;
F_82 ( V_5 , V_102 ) ;
return V_102 ;
}
void F_83 ( struct V_155 * V_5 )
{
struct V_127 * V_128 ;
if ( V_5 -> V_102 ) {
F_84 ( V_5 -> V_102 ) ;
F_71 ( F_52 ( V_5 -> V_102 ) ) ;
}
V_128 = F_73 ( sizeof( * V_128 ) , V_149 ) ;
if ( ! V_128 ) {
F_10 ( L_19 ) ;
return;
}
F_85 ( V_5 , & V_128 -> V_33 ) ;
}
void
F_86 ( struct V_155 * V_5 ,
struct V_154 * V_102 )
{
F_87 ( V_5 , V_102 ) ;
}
static void F_88 ( struct V_98 * V_156 )
{
struct V_157 * V_158 =
F_46 ( V_156 ) ;
F_89 ( V_156 ) ;
F_38 ( & V_158 -> V_101 ) ;
if ( V_158 -> V_33 . V_159 )
F_90 ( & V_158 -> V_33 . V_159 ) ;
F_71 ( V_158 ) ;
}
static int F_91 ( struct V_98 * V_156 ,
struct V_160 * V_161 ,
unsigned V_162 , unsigned V_163 ,
struct V_164 * V_165 ,
unsigned V_166 )
{
struct V_8 * V_9 = F_49 ( V_156 -> V_76 ) ;
struct V_157 * V_158 =
F_46 ( V_156 ) ;
struct V_164 V_167 ;
int V_30 , V_168 = 1 ;
if ( V_9 -> V_169 == V_170 )
return - V_18 ;
F_26 ( V_9 -> V_76 ) ;
V_30 = F_92 ( & V_9 -> V_171 , true ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
if ( ! V_166 ) {
V_166 = 1 ;
V_165 = & V_167 ;
V_167 . V_116 = V_167 . y1 = 0 ;
V_167 . V_119 = V_156 -> V_11 ;
V_167 . V_121 = V_156 -> V_12 ;
} else if ( V_162 & V_172 ) {
V_166 /= 2 ;
V_168 = 2 ;
}
if ( V_9 -> V_169 == V_173 )
V_30 = F_93 ( V_9 , & V_158 -> V_33 ,
V_165 , NULL , NULL , 0 , 0 ,
V_166 , V_168 , NULL ) ;
else
V_30 = F_94 ( V_9 , & V_158 -> V_33 ,
V_165 , NULL , NULL , 0 , 0 ,
V_166 , V_168 , NULL ) ;
F_95 ( V_9 , false ) ;
F_96 ( & V_9 -> V_171 ) ;
F_29 ( V_9 -> V_76 ) ;
return 0 ;
}
int F_97 ( struct V_8 * V_9 ,
struct V_160 * V_161 ,
struct V_129 * V_130 ,
struct V_174 T_8 * V_175 ,
struct V_176 * V_177 ,
T_3 V_166 )
{
switch ( V_9 -> V_169 ) {
case V_173 :
return F_98 ( V_9 , V_161 , V_130 ,
V_175 , V_177 , V_166 ) ;
case V_178 :
return F_99 ( V_9 , V_161 , V_130 ,
V_175 , NULL , V_177 , V_166 ,
1 , false , true ) ;
default:
F_100 ( true ,
L_20 ) ;
}
return - V_179 ;
}
static int F_101 ( struct V_8 * V_9 ,
struct V_46 * V_101 ,
struct V_129 * * V_180 ,
const struct V_181
* V_182 ,
bool V_183 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_157 * V_158 ;
enum V_184 V_185 ;
int V_30 ;
struct V_186 V_187 ;
if ( V_9 -> V_169 == V_170 )
return - V_179 ;
if ( F_9 ( ! V_101 -> V_188 ) )
return - V_18 ;
if ( F_9 ( V_101 -> V_189 [ 0 ] != 1 ||
V_101 -> V_190 != 1 ||
V_101 -> V_191 . V_11 < V_182 -> V_11 ||
V_101 -> V_191 . V_12 < V_182 -> V_12 ||
V_101 -> V_191 . V_192 != 1 ) ) {
F_10 ( L_21
L_22 ) ;
return - V_18 ;
}
switch ( V_182 -> V_193 ) {
case V_194 :
V_185 = V_195 ;
break;
case V_196 :
V_185 = V_197 ;
break;
case V_198 :
V_185 = V_199 ;
break;
case V_200 :
V_185 = V_201 ;
break;
default:
F_10 ( L_23 ,
F_102 ( V_182 -> V_193 , & V_187 ) ) ;
return - V_18 ;
}
if ( ! V_9 -> V_202 && V_185 != V_101 -> V_185 ) {
F_10 ( L_24 ) ;
return - V_18 ;
}
V_158 = F_73 ( sizeof( * V_158 ) , V_149 ) ;
if ( ! V_158 ) {
V_30 = - V_19 ;
goto V_203;
}
F_103 ( V_76 , & V_158 -> V_33 . V_33 , V_182 ) ;
V_158 -> V_101 = F_47 ( V_101 ) ;
V_158 -> V_33 . V_204 = V_182 -> V_205 [ 0 ] ;
V_158 -> V_183 = V_183 ;
* V_180 = & V_158 -> V_33 ;
V_30 = F_104 ( V_76 , & V_158 -> V_33 . V_33 ,
& V_206 ) ;
if ( V_30 )
goto V_207;
return 0 ;
V_207:
F_38 ( & V_101 ) ;
F_71 ( V_158 ) ;
V_203:
return V_30 ;
}
static void F_105 ( struct V_98 * V_156 )
{
struct V_208 * V_209 =
F_44 ( V_156 ) ;
F_89 ( V_156 ) ;
F_42 ( & V_209 -> V_100 ) ;
if ( V_209 -> V_33 . V_159 )
F_90 ( & V_209 -> V_33 . V_159 ) ;
F_71 ( V_209 ) ;
}
static int F_106 ( struct V_98 * V_156 ,
struct V_160 * V_161 ,
unsigned V_162 , unsigned V_163 ,
struct V_164 * V_165 ,
unsigned V_166 )
{
struct V_8 * V_9 = F_49 ( V_156 -> V_76 ) ;
struct V_208 * V_209 =
F_44 ( V_156 ) ;
struct V_164 V_167 ;
int V_30 , V_210 = 1 ;
F_26 ( V_9 -> V_76 ) ;
V_30 = F_92 ( & V_9 -> V_171 , true ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
if ( ! V_166 ) {
V_166 = 1 ;
V_165 = & V_167 ;
V_167 . V_116 = V_167 . y1 = 0 ;
V_167 . V_119 = V_156 -> V_11 ;
V_167 . V_121 = V_156 -> V_12 ;
} else if ( V_162 & V_172 ) {
V_166 /= 2 ;
V_210 = 2 ;
}
switch ( V_9 -> V_169 ) {
case V_178 :
V_30 = F_99 ( V_9 , NULL , & V_209 -> V_33 , NULL ,
V_165 , NULL , V_166 , V_210 ,
true , true ) ;
break;
case V_173 :
V_30 = F_107 ( V_9 , & V_209 -> V_33 ,
V_165 , NULL , V_166 ,
V_210 , true , NULL ) ;
break;
case V_170 :
V_30 = F_108 ( V_9 , & V_209 -> V_33 , 0 , 0 ,
V_165 , V_166 , V_210 ) ;
break;
default:
V_30 = - V_18 ;
F_100 ( true , L_25 ) ;
break;
}
F_95 ( V_9 , false ) ;
F_96 ( & V_9 -> V_171 ) ;
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
static int F_109 ( struct V_129 * V_130 )
{
struct V_8 * V_9 = F_49 ( V_130 -> V_33 . V_76 ) ;
struct V_22 * V_211 ;
int V_30 ;
V_211 = V_130 -> V_23 ? F_44 ( & V_130 -> V_33 ) -> V_100 :
F_46 ( & V_130 -> V_33 ) -> V_101 -> V_94 . V_212 ;
if ( ! V_211 )
return 0 ;
switch ( V_9 -> V_169 ) {
case V_170 :
F_110 ( V_9 ) ;
V_30 = F_111 ( V_9 , V_211 , false ) ;
F_112 ( V_9 ) ;
break;
case V_173 :
case V_178 :
if ( V_130 -> V_23 )
return F_113 ( V_9 , V_211 ,
false ) ;
return F_114 ( V_9 , V_211 ,
& V_213 , false ) ;
default:
return - V_18 ;
}
return V_30 ;
}
static int F_115 ( struct V_129 * V_130 )
{
struct V_8 * V_9 = F_49 ( V_130 -> V_33 . V_76 ) ;
struct V_22 * V_211 ;
V_211 = V_130 -> V_23 ? F_44 ( & V_130 -> V_33 ) -> V_100 :
F_46 ( & V_130 -> V_33 ) -> V_101 -> V_94 . V_212 ;
if ( F_66 ( ! V_211 ) )
return 0 ;
return F_116 ( V_9 , V_211 , false ) ;
}
static int F_117 ( struct V_75 * V_76 ,
const struct V_181 * V_182 ,
struct V_22 * V_214 ,
struct V_46 * * V_215 )
{
T_3 V_185 ;
struct V_216 V_217 = { 0 } ;
struct V_218 * V_94 ;
unsigned int V_219 ;
struct V_186 V_187 ;
int V_30 ;
switch ( V_182 -> V_193 ) {
case V_194 :
case V_196 :
V_185 = V_197 ;
V_219 = 4 ;
break;
case V_198 :
case V_200 :
V_185 = V_199 ;
V_219 = 2 ;
break;
case 8 :
V_185 = V_220 ;
V_219 = 1 ;
break;
default:
F_10 ( L_26 ,
F_102 ( V_182 -> V_193 , & V_187 ) ) ;
return - V_18 ;
}
V_217 . V_11 = V_182 -> V_221 [ 0 ] / V_219 ;
V_217 . V_12 = V_182 -> V_12 ;
V_217 . V_192 = 1 ;
V_30 = F_118 ( V_76 ,
0 ,
0 ,
V_185 ,
true ,
1 ,
0 ,
0 ,
V_217 ,
V_215 ) ;
if ( V_30 ) {
F_10 ( L_27 ) ;
return V_30 ;
}
V_94 = & ( * V_215 ) -> V_94 ;
F_31 ( & V_94 -> V_9 -> V_222 ) ;
( void ) F_119 ( V_94 , false , true ) ;
F_42 ( & V_94 -> V_212 ) ;
V_94 -> V_212 = F_45 ( V_214 ) ;
V_94 -> V_223 = 0 ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_222 ) ;
return 0 ;
}
static int F_121 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_129 * * V_180 ,
const struct V_181
* V_182 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_208 * V_209 ;
unsigned int V_224 ;
struct V_186 V_187 ;
int V_30 ;
V_224 = V_182 -> V_12 * V_182 -> V_221 [ 0 ] ;
if ( F_9 ( V_224 > V_23 -> V_33 . V_225 * V_31 ) ) {
F_10 ( L_28
L_22 ) ;
return - V_18 ;
}
if ( V_9 -> V_169 == V_173 ) {
switch ( V_182 -> V_193 ) {
case V_196 :
case V_194 :
break;
case V_200 :
case V_198 :
break;
default:
F_10 ( L_23 ,
F_102 ( V_182 -> V_193 , & V_187 ) ) ;
return - V_18 ;
}
}
V_209 = F_73 ( sizeof( * V_209 ) , V_149 ) ;
if ( ! V_209 ) {
V_30 = - V_19 ;
goto V_203;
}
F_103 ( V_76 , & V_209 -> V_33 . V_33 , V_182 ) ;
V_209 -> V_33 . V_23 = true ;
V_209 -> V_100 = F_45 ( V_23 ) ;
V_209 -> V_33 . V_204 = V_182 -> V_205 [ 0 ] ;
* V_180 = & V_209 -> V_33 ;
V_30 = F_104 ( V_76 , & V_209 -> V_33 . V_33 ,
& V_226 ) ;
if ( V_30 )
goto V_207;
return 0 ;
V_207:
F_42 ( & V_23 ) ;
F_71 ( V_209 ) ;
V_203:
return V_30 ;
}
static bool
F_122 ( struct V_8 * V_9 , T_3 V_11 , T_3 V_12 )
{
if ( V_11 > V_9 -> V_227 ||
V_12 > V_9 -> V_228 )
return false ;
return true ;
}
struct V_129 *
F_123 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_46 * V_101 ,
bool V_229 ,
const struct V_181 * V_182 )
{
struct V_129 * V_130 = NULL ;
bool V_183 = false ;
int V_30 ;
if ( F_122 ( V_9 , V_182 -> V_11 , V_182 -> V_12 ) &&
V_23 && V_229 &&
V_182 -> V_11 > 64 &&
V_9 -> V_169 == V_178 ) {
V_30 = F_117 ( V_9 -> V_76 , V_182 ,
V_23 , & V_101 ) ;
if ( V_30 )
return F_124 ( V_30 ) ;
V_183 = true ;
}
if ( V_101 ) {
V_30 = F_101 ( V_9 , V_101 , & V_130 ,
V_182 ,
V_183 ) ;
if ( V_183 )
F_38 ( & V_101 ) ;
} else if ( V_23 ) {
V_30 = F_121 ( V_9 , V_23 , & V_130 ,
V_182 ) ;
} else {
F_125 () ;
}
if ( V_30 )
return F_124 ( V_30 ) ;
V_130 -> V_230 = F_109 ;
V_130 -> V_231 = F_115 ;
return V_130 ;
}
static struct V_98 * F_126 ( struct V_75 * V_76 ,
struct V_160 * V_161 ,
const struct V_181 * V_182 )
{
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_48 * V_49 = F_127 ( V_161 ) -> V_49 ;
struct V_129 * V_130 = NULL ;
struct V_46 * V_101 = NULL ;
struct V_22 * V_51 = NULL ;
struct V_232 * V_159 ;
int V_30 ;
if ( ! F_128 ( V_9 ,
V_182 -> V_221 [ 0 ] ,
V_182 -> V_12 ) ) {
F_10 ( L_29 ) ;
return F_124 ( - V_19 ) ;
}
V_159 = F_129 ( V_49 , V_182 -> V_205 [ 0 ] ) ;
if ( F_9 ( V_159 == NULL ) ) {
F_10 ( L_30 ) ;
return F_124 ( - V_233 ) ;
}
V_30 = F_130 ( V_9 , V_49 ,
V_182 -> V_205 [ 0 ] ,
& V_101 , & V_51 ) ;
if ( V_30 )
goto V_234;
if ( ! V_51 &&
! F_122 ( V_9 , V_182 -> V_11 , V_182 -> V_12 ) ) {
F_10 ( L_31 ,
V_9 -> V_227 ,
V_9 -> V_228 ) ;
goto V_234;
}
V_130 = F_123 ( V_9 , V_51 , V_101 ,
! ( V_9 -> V_235 & V_236 ) ,
V_182 ) ;
if ( F_131 ( V_130 ) ) {
V_30 = F_132 ( V_130 ) ;
goto V_234;
}
V_234:
if ( V_51 )
F_42 ( & V_51 ) ;
if ( V_101 )
F_38 ( & V_101 ) ;
if ( V_30 ) {
F_10 ( L_32 , V_30 ) ;
F_90 ( & V_159 ) ;
return F_124 ( V_30 ) ;
} else
V_130 -> V_159 = V_159 ;
return & V_130 -> V_33 ;
}
int
F_133 ( struct V_75 * V_76 ,
struct V_237 * V_102 )
{
struct V_136 * V_238 ;
struct V_77 * V_6 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
int V_57 ;
F_134 (state, crtc, crtc_state, i) {
unsigned long V_239 = 0 ;
if ( V_9 -> V_169 == V_178 ) {
if ( V_6 -> V_3 -> V_99 ) {
int V_152 = V_6 -> V_3 -> V_99 -> V_221 [ 0 ] /
V_6 -> V_3 -> V_99 -> V_11 ;
V_239 += V_6 -> V_141 . V_240 * V_152 *
V_6 -> V_141 . V_241 ;
}
if ( V_239 > V_9 -> V_242 )
return - V_18 ;
}
}
return F_135 ( V_76 , V_102 ) ;
}
static int F_136 ( struct V_8 * V_9 ,
struct V_160 * V_161 ,
struct V_129 * V_130 ,
struct V_46 * V_101 ,
T_3 V_243 ,
T_9 V_244 , T_9 V_245 ,
struct V_176 * V_165 ,
T_3 V_166 )
{
return F_93 ( V_9 , V_130 , NULL , V_165 ,
& V_101 -> V_94 , V_244 , V_245 ,
V_166 , 1 , NULL ) ;
}
int F_137 ( struct V_8 * V_9 ,
struct V_160 * V_161 ,
struct V_129 * V_130 ,
struct V_46 * V_101 ,
T_3 V_243 ,
T_9 V_244 , T_9 V_245 ,
struct V_176 * V_165 ,
T_3 V_166 )
{
int V_30 ;
switch ( V_9 -> V_169 ) {
case V_178 :
V_30 = F_94 ( V_9 , V_130 , NULL , V_165 ,
& V_101 -> V_94 , V_244 , V_245 ,
V_166 , 1 , NULL ) ;
break;
case V_173 :
V_30 = F_136 ( V_9 , V_161 , V_130 , V_101 ,
V_243 , V_244 , V_245 , V_165 ,
V_166 ) ;
break;
default:
F_100 ( true ,
L_33 ) ;
V_30 = - V_179 ;
break;
}
if ( V_30 )
return V_30 ;
F_95 ( V_9 , false ) ;
return 0 ;
}
static void
F_138 ( struct V_8 * V_9 )
{
if ( V_9 -> V_246 )
return;
V_9 -> V_246 =
F_139 ( V_9 -> V_76 ,
V_247 ,
L_34 , 0 , 1 ) ;
if ( ! V_9 -> V_246 )
return;
}
int F_140 ( struct V_8 * V_9 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
int V_30 ;
F_141 ( V_76 ) ;
V_76 -> V_80 . V_248 = & V_249 ;
V_76 -> V_80 . V_250 = 1 ;
V_76 -> V_80 . V_251 = 1 ;
V_76 -> V_80 . V_252 = V_9 -> V_227 ;
V_76 -> V_80 . V_253 = V_9 -> V_228 ;
F_142 ( V_76 ) ;
F_138 ( V_9 ) ;
V_30 = F_143 ( V_9 ) ;
if ( V_30 ) {
V_30 = F_144 ( V_9 ) ;
if ( V_30 )
V_30 = F_145 ( V_9 ) ;
}
return V_30 ;
}
int F_146 ( struct V_8 * V_9 )
{
int V_30 ;
F_147 ( V_9 -> V_76 ) ;
if ( V_9 -> V_169 == V_173 )
V_30 = F_148 ( V_9 ) ;
else if ( V_9 -> V_169 == V_178 )
V_30 = F_149 ( V_9 ) ;
else
V_30 = F_150 ( V_9 ) ;
return V_30 ;
}
int F_151 ( struct V_75 * V_76 , void * V_254 ,
struct V_160 * V_161 )
{
struct V_255 * V_256 = V_254 ;
struct V_1 * V_2 ;
struct V_77 * V_6 ;
int V_30 = 0 ;
F_31 ( & V_76 -> V_80 . V_81 ) ;
if ( V_256 -> V_162 & V_257 ) {
F_32 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_28 ( V_6 ) ;
V_2 -> V_78 = V_256 -> V_258 ;
V_2 -> V_79 = V_256 -> V_259 ;
}
F_33 ( & V_76 -> V_80 . V_81 ) ;
return 0 ;
}
V_6 = F_152 ( V_76 , V_256 -> V_260 ) ;
if ( ! V_6 ) {
V_30 = - V_233 ;
goto V_180;
}
V_2 = F_28 ( V_6 ) ;
V_2 -> V_78 = V_256 -> V_258 ;
V_2 -> V_79 = V_256 -> V_259 ;
V_180:
F_33 ( & V_76 -> V_80 . V_81 ) ;
return V_30 ;
}
int F_153 ( struct V_8 * F_49 ,
unsigned V_11 , unsigned V_12 , unsigned V_73 ,
unsigned V_261 , unsigned V_192 )
{
if ( F_49 -> V_235 & V_262 )
F_154 ( F_49 , V_263 , V_73 ) ;
else if ( F_155 ( F_49 ) )
F_20 ( V_73 , F_49 -> V_39 +
V_264 ) ;
F_154 ( F_49 , V_265 , V_11 ) ;
F_154 ( F_49 , V_266 , V_12 ) ;
F_154 ( F_49 , V_267 , V_261 ) ;
if ( F_156 ( F_49 , V_268 ) != V_192 ) {
F_10 ( L_35 ,
V_192 , V_261 , F_156 ( F_49 , V_268 ) ) ;
return - V_18 ;
}
return 0 ;
}
int F_157 ( struct V_8 * F_49 )
{
struct V_269 * V_270 ;
T_3 V_57 ;
F_49 -> V_271 = F_156 ( F_49 , V_265 ) ;
F_49 -> V_272 = F_156 ( F_49 , V_266 ) ;
F_49 -> V_273 = F_156 ( F_49 , V_267 ) ;
if ( F_49 -> V_235 & V_262 )
F_49 -> V_274 =
F_156 ( F_49 , V_263 ) ;
else if ( F_155 ( F_49 ) )
F_49 -> V_274 = F_21 ( F_49 -> V_39 +
V_264 ) ;
if ( ! ( F_49 -> V_235 & V_275 ) )
return 0 ;
F_49 -> V_276 = F_156 ( F_49 ,
V_277 ) ;
if ( F_49 -> V_276 == 0 )
F_49 -> V_276 = 1 ;
for ( V_57 = 0 ; V_57 < F_49 -> V_276 ; ++ V_57 ) {
V_270 = & F_49 -> V_278 [ V_57 ] ;
F_154 ( F_49 , V_279 , V_57 ) ;
V_270 -> V_3 = F_156 ( F_49 , V_280 ) ;
V_270 -> V_281 = F_156 ( F_49 , V_282 ) ;
V_270 -> V_283 = F_156 ( F_49 , V_284 ) ;
V_270 -> V_11 = F_156 ( F_49 , V_285 ) ;
V_270 -> V_12 = F_156 ( F_49 , V_286 ) ;
F_154 ( F_49 , V_279 , V_287 ) ;
if ( V_57 == 0 && F_49 -> V_276 == 1 &&
V_270 -> V_11 == 0 && V_270 -> V_12 == 0 ) {
V_270 -> V_11 = F_49 -> V_271 - V_270 -> V_281 ;
V_270 -> V_12 = F_49 -> V_272 - V_270 -> V_283 ;
}
}
return 0 ;
}
int F_158 ( struct V_8 * F_49 )
{
struct V_269 * V_270 ;
T_3 V_57 ;
F_154 ( F_49 , V_265 , F_49 -> V_271 ) ;
F_154 ( F_49 , V_266 , F_49 -> V_272 ) ;
F_154 ( F_49 , V_267 , F_49 -> V_273 ) ;
if ( F_49 -> V_235 & V_262 )
F_154 ( F_49 , V_263 ,
F_49 -> V_274 ) ;
else if ( F_155 ( F_49 ) )
F_20 ( F_49 -> V_274 ,
F_49 -> V_39 + V_264 ) ;
if ( ! ( F_49 -> V_235 & V_275 ) )
return 0 ;
for ( V_57 = 0 ; V_57 < F_49 -> V_276 ; ++ V_57 ) {
V_270 = & F_49 -> V_278 [ V_57 ] ;
F_154 ( F_49 , V_279 , V_57 ) ;
F_154 ( F_49 , V_280 , V_270 -> V_3 ) ;
F_154 ( F_49 , V_282 , V_270 -> V_281 ) ;
F_154 ( F_49 , V_284 , V_270 -> V_283 ) ;
F_154 ( F_49 , V_285 , V_270 -> V_11 ) ;
F_154 ( F_49 , V_286 , V_270 -> V_12 ) ;
F_154 ( F_49 , V_279 , V_287 ) ;
}
return 0 ;
}
bool F_128 ( struct V_8 * V_9 ,
T_3 V_73 ,
T_3 V_12 )
{
return ( ( V_288 ) V_73 * ( V_288 ) V_12 ) < ( V_288 )
( ( V_9 -> V_169 == V_178 ) ?
V_9 -> V_242 : V_9 -> V_289 ) ;
}
T_1 F_159 ( struct V_75 * V_76 , unsigned int V_290 )
{
return 0 ;
}
int F_160 ( struct V_75 * V_76 , unsigned int V_290 )
{
return - V_179 ;
}
void F_161 ( struct V_75 * V_76 , unsigned int V_290 )
{
}
static int F_162 ( struct V_8 * V_9 , unsigned V_291 ,
struct V_176 * V_292 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_1 * V_2 ;
struct V_155 * V_293 ;
F_31 ( & V_76 -> V_80 . V_81 ) ;
#if 0
{
unsigned int i;
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
}
#endif
F_32 (con, &dev->mode_config.connector_list, head) {
V_2 = F_163 ( V_293 ) ;
if ( V_291 > V_2 -> V_294 ) {
V_2 -> V_295 = V_292 [ V_2 -> V_294 ] . V_71 ;
V_2 -> V_296 = V_292 [ V_2 -> V_294 ] . V_72 ;
V_2 -> V_297 = true ;
V_2 -> V_298 = V_292 [ V_2 -> V_294 ] . V_36 ;
V_2 -> V_299 = V_292 [ V_2 -> V_294 ] . V_37 ;
F_164
( & V_293 -> V_33 , V_76 -> V_80 . V_300 ,
V_2 -> V_298 ) ;
F_164
( & V_293 -> V_33 , V_76 -> V_80 . V_301 ,
V_2 -> V_299 ) ;
} else {
V_2 -> V_295 = 800 ;
V_2 -> V_296 = 600 ;
V_2 -> V_297 = false ;
F_164
( & V_293 -> V_33 , V_76 -> V_80 . V_300 ,
0 ) ;
F_164
( & V_293 -> V_33 , V_76 -> V_80 . V_301 ,
0 ) ;
}
V_293 -> V_302 = F_165 ( V_293 , true ) ;
}
F_33 ( & V_76 -> V_80 . V_81 ) ;
F_166 ( V_76 ) ;
return 0 ;
}
int F_167 ( struct V_77 * V_6 ,
T_10 * V_303 , T_10 * V_304 , T_10 * V_305 ,
T_3 V_62 ,
struct V_306 * V_307 )
{
struct V_8 * V_9 = F_49 ( V_6 -> V_76 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ ) {
F_168 ( L_36 , V_57 ,
V_303 [ V_57 ] , V_304 [ V_57 ] , V_305 [ V_57 ] ) ;
F_154 ( V_9 , V_308 + V_57 * 3 + 0 , V_303 [ V_57 ] >> 8 ) ;
F_154 ( V_9 , V_308 + V_57 * 3 + 1 , V_304 [ V_57 ] >> 8 ) ;
F_154 ( V_9 , V_308 + V_57 * 3 + 2 , V_305 [ V_57 ] >> 8 ) ;
}
return 0 ;
}
int F_169 ( struct V_155 * V_5 , int V_141 )
{
return 0 ;
}
enum V_309
F_165 ( struct V_155 * V_5 , bool V_310 )
{
T_3 V_276 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_1 * V_2 = F_163 ( V_5 ) ;
V_276 = F_156 ( V_9 , V_311 ) ;
return ( ( F_163 ( V_5 ) -> V_294 < V_276 &&
V_2 -> V_297 ) ?
V_312 : V_313 ) ;
}
void F_170 ( struct V_314 * V_141 )
{
V_141 -> V_315 = V_141 -> V_240 + 50 ;
V_141 -> V_316 = V_141 -> V_315 + 50 ;
V_141 -> V_317 = V_141 -> V_316 + 50 ;
V_141 -> V_318 = V_141 -> V_241 + 50 ;
V_141 -> V_319 = V_141 -> V_318 + 50 ;
V_141 -> V_320 = V_141 -> V_319 + 50 ;
V_141 -> clock = ( T_1 ) V_141 -> V_317 * ( T_1 ) V_141 -> V_320 / 100 * 6 ;
V_141 -> V_321 = F_171 ( V_141 ) ;
}
int F_172 ( struct V_155 * V_5 ,
T_3 V_252 , T_3 V_253 )
{
struct V_1 * V_2 = F_163 ( V_5 ) ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_314 * V_141 = NULL ;
struct V_314 * V_322 ;
struct V_314 V_323 = { F_173 ( L_37 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_57 ;
T_1 V_324 = 4 ;
if ( V_9 -> V_325 )
V_324 = 2 ;
if ( V_9 -> V_169 == V_178 ) {
V_252 = F_174 ( V_252 , V_9 -> V_326 ) ;
V_252 = F_174 ( V_252 , V_9 -> V_227 ) ;
V_253 = F_174 ( V_253 , V_9 -> V_327 ) ;
V_253 = F_174 ( V_253 , V_9 -> V_228 ) ;
}
V_141 = F_175 ( V_76 , & V_323 ) ;
if ( ! V_141 )
return 0 ;
V_141 -> V_240 = V_2 -> V_295 ;
V_141 -> V_241 = V_2 -> V_296 ;
F_170 ( V_141 ) ;
if ( F_128 ( V_9 ,
V_141 -> V_240 * V_324 ,
V_141 -> V_241 ) ) {
F_176 ( V_5 , V_141 ) ;
} else {
F_177 ( V_76 , V_141 ) ;
V_141 = NULL ;
}
if ( V_2 -> V_328 ) {
F_178 ( & V_2 -> V_328 -> V_329 ) ;
F_177 ( V_76 , V_2 -> V_328 ) ;
}
V_2 -> V_328 = V_141 ;
for ( V_57 = 0 ; V_330 [ V_57 ] . type != 0 ; V_57 ++ ) {
V_322 = & V_330 [ V_57 ] ;
if ( V_322 -> V_240 > V_252 ||
V_322 -> V_241 > V_253 )
continue;
if ( ! F_128 ( V_9 ,
V_322 -> V_240 * V_324 ,
V_322 -> V_241 ) )
continue;
V_141 = F_175 ( V_76 , V_322 ) ;
if ( ! V_141 )
return 0 ;
V_141 -> V_321 = F_171 ( V_141 ) ;
F_176 ( V_5 , V_141 ) ;
}
F_179 ( V_5 ) ;
F_180 ( & V_5 -> V_331 ) ;
return 1 ;
}
int F_181 ( struct V_155 * V_5 ,
struct V_332 * V_333 ,
T_11 V_334 )
{
struct V_1 * V_2 = F_163 ( V_5 ) ;
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
if ( V_333 == V_9 -> V_335 )
V_2 -> V_132 = V_334 ;
return 0 ;
}
int
F_182 ( struct V_155 * V_5 ,
struct V_154 * V_102 ,
struct V_332 * V_333 ,
T_11 V_334 )
{
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
struct V_127 * V_128 = F_52 ( V_102 ) ;
struct V_1 * V_2 = F_163 ( V_5 ) ;
if ( V_333 == V_9 -> V_335 ) {
V_128 -> V_132 = V_334 ;
V_2 -> V_132 = V_128 -> V_132 ;
} else {
return - V_18 ;
}
return 0 ;
}
int
F_183 ( struct V_155 * V_5 ,
const struct V_154 * V_102 ,
struct V_332 * V_333 ,
T_11 * V_334 )
{
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
struct V_127 * V_128 = F_52 ( V_102 ) ;
if ( V_333 == V_9 -> V_335 )
* V_334 = V_128 -> V_132 ;
else {
F_10 ( L_38 , V_333 -> V_336 ) ;
return - V_18 ;
}
return 0 ;
}
int F_184 ( struct V_75 * V_76 , void * V_254 ,
struct V_160 * V_161 )
{
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_337 * V_256 =
(struct V_337 * ) V_254 ;
void T_8 * V_338 ;
struct V_176 * V_292 ;
unsigned V_339 ;
int V_30 ;
int V_57 ;
V_288 V_340 = 0 ;
struct V_341 * V_80 = & V_76 -> V_80 ;
struct V_176 V_342 = { 0 } ;
if ( ! V_256 -> V_343 ) {
struct V_176 V_344 = { 0 , 0 , 800 , 600 } ;
F_162 ( V_9 , 1 , & V_344 ) ;
return 0 ;
}
V_339 = V_256 -> V_343 * sizeof( struct V_176 ) ;
V_292 = F_185 ( V_256 -> V_343 , sizeof( struct V_176 ) ,
V_149 ) ;
if ( F_9 ( ! V_292 ) )
return - V_19 ;
V_338 = ( void T_8 * ) ( unsigned long ) V_256 -> V_292 ;
V_30 = F_186 ( V_292 , V_338 , V_339 ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_10 ( L_39 ) ;
V_30 = - V_345 ;
goto V_346;
}
for ( V_57 = 0 ; V_57 < V_256 -> V_343 ; ++ V_57 ) {
if ( V_292 [ V_57 ] . V_36 < 0 ||
V_292 [ V_57 ] . V_37 < 0 ||
V_292 [ V_57 ] . V_36 + V_292 [ V_57 ] . V_71 > V_80 -> V_252 ||
V_292 [ V_57 ] . V_37 + V_292 [ V_57 ] . V_72 > V_80 -> V_253 ) {
F_10 ( L_40 ) ;
V_30 = - V_18 ;
goto V_346;
}
if ( V_292 [ V_57 ] . V_36 + V_292 [ V_57 ] . V_71 > V_342 . V_71 )
V_342 . V_71 = V_292 [ V_57 ] . V_36 + V_292 [ V_57 ] . V_71 ;
if ( V_292 [ V_57 ] . V_37 + V_292 [ V_57 ] . V_72 > V_342 . V_72 )
V_342 . V_72 = V_292 [ V_57 ] . V_37 + V_292 [ V_57 ] . V_72 ;
V_340 += ( V_288 ) V_292 [ V_57 ] . V_71 * ( V_288 ) V_292 [ V_57 ] . V_72 ;
}
if ( V_9 -> V_169 == V_178 ) {
V_288 V_347 = ( V_288 ) V_342 . V_71 * V_342 . V_72 * 4 ;
V_288 V_348 = V_340 * 4 ;
if ( V_347 > V_9 -> V_242 ) {
F_10 ( L_41 ) ;
V_30 = - V_18 ;
goto V_346;
}
if ( V_348 > V_9 -> V_242 ) {
F_10 ( L_42 ) ;
V_30 = - V_18 ;
goto V_346;
}
}
F_162 ( V_9 , V_256 -> V_343 , V_292 ) ;
V_346:
F_71 ( V_292 ) ;
return V_30 ;
}
int F_187 ( struct V_8 * V_9 ,
struct V_129 * V_156 ,
const struct V_164 * V_165 ,
const struct V_176 * V_177 ,
T_7 V_349 , T_7 V_350 ,
int V_166 ,
int V_210 ,
struct V_351 * V_352 )
{
struct V_1 * V_353 [ V_354 ] ;
struct V_77 * V_6 ;
T_1 V_355 = 0 ;
T_1 V_57 , V_356 ;
V_352 -> V_9 = V_9 ;
F_32 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_3 -> V_99 != & V_156 -> V_33 )
continue;
V_353 [ V_355 ++ ] = F_28 ( V_6 ) ;
}
for ( V_356 = 0 ; V_356 < V_355 ; V_356 ++ ) {
struct V_1 * V_294 = V_353 [ V_356 ] ;
T_7 V_107 = V_294 -> V_6 . V_36 ;
T_7 V_110 = V_294 -> V_6 . V_37 ;
T_7 V_357 = V_294 -> V_6 . V_141 . V_240 ;
T_7 V_358 = V_294 -> V_6 . V_141 . V_241 ;
const struct V_164 * V_359 = V_165 ;
const struct V_176 * V_360 = V_177 ;
V_352 -> V_294 = V_294 ;
if ( V_352 -> V_361 > 0 ) {
V_352 -> V_15 = F_8 ( V_9 ,
V_352 -> V_361 ) ;
if ( ! V_352 -> V_15 ) {
F_10 ( L_43
L_44 ) ;
return - V_19 ;
}
memset ( V_352 -> V_15 , 0 , V_352 -> V_361 ) ;
}
V_352 -> V_362 = 0 ;
for ( V_57 = 0 ; V_57 < V_166 ; V_57 ++ , V_359 += V_210 ,
V_360 += V_210 ) {
T_7 V_363 ;
T_7 V_364 ;
if ( V_165 ) {
V_352 -> V_365 = ( T_7 ) V_359 -> V_116 ;
V_352 -> V_366 = ( T_7 ) V_359 -> y1 ;
V_352 -> V_367 = ( T_7 ) V_359 -> V_119 + V_349 -
V_107 ;
V_352 -> V_368 = ( T_7 ) V_359 -> V_121 + V_350 -
V_110 ;
} else {
V_352 -> V_365 = V_360 -> V_36 ;
V_352 -> V_366 = V_360 -> V_37 ;
V_352 -> V_367 = V_352 -> V_365 + V_360 -> V_71 +
V_349 - V_107 ;
V_352 -> V_368 = V_352 -> V_366 + V_360 -> V_72 +
V_350 - V_110 ;
}
V_352 -> V_369 = V_352 -> V_365 + V_349 - V_107 ;
V_352 -> V_370 = V_352 -> V_366 + V_350 - V_110 ;
if ( V_352 -> V_369 >= V_357 ||
V_352 -> V_370 >= V_358 ||
V_352 -> V_367 <= 0 || V_352 -> V_368 <= 0 )
continue;
V_352 -> V_367 = F_188 ( T_7 , V_352 -> V_367 ,
V_357 ) ;
V_352 -> V_368 = F_188 ( T_7 , V_352 -> V_368 ,
V_358 ) ;
V_363 = F_188 ( T_7 , V_352 -> V_369 , 0 ) ;
V_364 = F_188 ( T_7 , V_352 -> V_370 , 0 ) ;
V_352 -> V_369 -= V_363 ;
V_352 -> V_370 -= V_364 ;
V_352 -> V_365 -= V_363 ;
V_352 -> V_366 -= V_364 ;
V_352 -> V_124 ( V_352 ) ;
}
V_352 -> V_371 ( V_352 ) ;
}
return 0 ;
}
int F_189 ( struct V_8 * V_9 ,
struct V_22 * V_211 ,
bool V_372 ,
bool V_373 )
{
struct V_50 * V_51 = & V_211 -> V_33 ;
int V_30 ;
F_13 ( V_51 , false , false , NULL ) ;
V_30 = F_190 ( V_9 , V_51 , V_372 ,
V_373 ) ;
if ( V_30 )
F_17 ( V_51 ) ;
return V_30 ;
}
void F_191 ( struct V_22 * V_211 )
{
if ( V_211 )
F_17 ( & V_211 -> V_33 ) ;
}
void F_192 ( struct V_8 * V_9 ,
struct V_160 * V_161 ,
struct V_22 * V_211 ,
struct V_374 * * V_375 ,
struct V_174 T_8 *
V_175 )
{
struct V_374 * V_376 ;
T_3 V_377 ;
int V_30 ;
V_30 = F_193 ( V_161 , V_9 , & V_376 ,
V_161 ? & V_377 : NULL ) ;
if ( V_211 )
F_194 ( & V_211 -> V_33 , V_376 ) ;
if ( V_161 )
F_195 ( V_9 , F_127 ( V_161 ) ,
V_30 , V_175 , V_376 ,
V_377 ) ;
if ( V_375 )
* V_375 = V_376 ;
else
F_196 ( & V_376 ) ;
F_191 ( V_211 ) ;
}
void F_197 ( struct V_218 * V_94 )
{
F_191 ( V_94 -> V_212 ) ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_222 ) ;
}
int F_198 ( struct V_218 * V_94 ,
bool V_372 )
{
int V_30 = 0 ;
if ( V_372 )
V_30 = F_199 ( & V_94 -> V_9 -> V_222 ) ;
else
F_31 ( & V_94 -> V_9 -> V_222 ) ;
if ( F_9 ( V_30 != 0 ) )
return - V_378 ;
V_30 = F_119 ( V_94 , V_372 , false ) ;
if ( V_30 )
goto V_379;
if ( V_94 -> V_212 ) {
V_30 = F_189 ( V_94 -> V_9 , V_94 -> V_212 ,
V_372 ,
V_94 -> V_9 -> V_380 ) ;
if ( V_30 )
goto V_381;
}
V_30 = F_200 ( V_94 ) ;
if ( V_30 )
goto V_382;
return 0 ;
V_382:
F_191 ( V_94 -> V_212 ) ;
V_381:
F_120 ( V_94 , false , NULL , 0 ) ;
V_379:
F_33 ( & V_94 -> V_9 -> V_222 ) ;
return V_30 ;
}
void F_201 ( struct V_218 * V_94 ,
struct V_374 * * V_375 )
{
if ( V_94 -> V_212 || V_375 )
F_192 ( V_94 -> V_9 , NULL , V_94 -> V_212 ,
V_375 , NULL ) ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_222 ) ;
}
int F_202 ( struct V_218 * V_94 ,
const struct V_164 * V_165 ,
unsigned V_166 ,
int V_210 )
{
struct V_8 * V_9 = V_94 -> V_9 ;
struct V_216 * V_62 = & F_203 ( V_94 ) -> V_191 ;
struct {
T_4 V_52 ;
T_12 V_383 ;
} * V_15 ;
T_13 * V_53 ;
T_14 V_384 = 0 ;
int V_57 ;
if ( ! V_165 )
return 0 ;
V_15 = F_8 ( V_9 , sizeof( * V_15 ) * V_166 ) ;
if ( ! V_15 ) {
F_10 ( L_45
L_46 ) ;
return - V_19 ;
}
for ( V_57 = 0 ; V_57 < V_166 ; ++ V_57 , V_165 += V_210 , ++ V_15 ) {
V_53 = & V_15 -> V_383 . V_53 ;
V_15 -> V_52 . V_21 = V_385 ;
V_15 -> V_52 . V_62 = sizeof( V_15 -> V_383 ) ;
V_15 -> V_383 . V_10 . V_243 = V_94 -> V_21 ;
V_15 -> V_383 . V_10 . V_60 = 0 ;
V_15 -> V_383 . V_10 . V_61 = 0 ;
if ( V_165 -> V_116 > V_62 -> V_11 || V_165 -> V_119 > V_62 -> V_11 ||
V_165 -> y1 > V_62 -> V_12 || V_165 -> V_121 > V_62 -> V_12 ) {
F_10 ( L_47 ) ;
return - V_18 ;
}
V_53 -> V_36 = V_165 -> V_116 ;
V_53 -> V_37 = V_165 -> y1 ;
V_53 -> V_66 = 0 ;
V_53 -> V_71 = V_165 -> V_119 - V_165 -> V_116 ;
V_53 -> V_72 = V_165 -> V_121 - V_165 -> y1 ;
V_53 -> V_70 = 1 ;
V_384 += sizeof( * V_15 ) ;
}
F_204 ( V_9 , V_384 ) ;
return 0 ;
}
int F_205 ( struct V_8 * V_9 ,
unsigned V_294 ,
T_1 V_252 ,
T_1 V_253 ,
struct V_155 * * V_386 ,
struct V_77 * * V_387 ,
struct V_314 * * V_388 )
{
struct V_155 * V_293 ;
struct V_1 * V_2 ;
struct V_314 * V_141 ;
int V_57 = 0 ;
F_32 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_57 == V_294 )
break;
++ V_57 ;
}
if ( V_57 != V_294 ) {
F_10 ( L_48 ) ;
return - V_18 ;
}
if ( F_206 ( & V_293 -> V_331 ) )
( void ) F_172 ( V_293 , V_252 , V_253 ) ;
if ( F_206 ( & V_293 -> V_331 ) ) {
F_10 ( L_49 ) ;
return - V_18 ;
}
V_2 = F_163 ( V_293 ) ;
* V_386 = V_293 ;
* V_387 = & V_2 -> V_6 ;
F_32 (mode, &con->modes, head) {
if ( V_141 -> type & V_389 )
break;
}
if ( V_141 -> type & V_389 )
* V_388 = V_141 ;
else {
F_100 ( true , L_50 ) ;
* V_388 = F_207 ( & V_293 -> V_331 ,
struct V_314 ,
V_329 ) ;
}
return 0 ;
}
void F_208 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_31 ( & V_9 -> V_131 ) ;
if ( V_2 -> V_135 ) {
if ( -- ( V_9 -> V_134 ) == 0 )
V_9 -> V_133 = NULL ;
V_2 -> V_135 = false ;
}
F_33 ( & V_9 -> V_131 ) ;
}
void F_209 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_129 * V_130 )
{
F_31 ( & V_9 -> V_131 ) ;
F_210 ( ! V_9 -> V_134 && V_9 -> V_133 ) ;
if ( ! V_2 -> V_135 && V_2 -> V_132 ) {
V_9 -> V_133 = V_130 ;
V_2 -> V_135 = true ;
V_9 -> V_134 ++ ;
}
F_33 ( & V_9 -> V_131 ) ;
}
bool F_211 ( struct V_8 * V_9 ,
struct V_77 * V_6 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
bool V_30 ;
F_31 ( & V_9 -> V_131 ) ;
V_30 = ! V_2 -> V_132 || V_9 -> V_134 == 1 ;
F_33 ( & V_9 -> V_131 ) ;
return V_30 ;
}
void F_212 ( struct V_8 * V_9 ,
struct V_77 * V_6 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
struct V_129 * V_130 ;
F_31 ( & V_9 -> V_131 ) ;
if ( ! V_2 -> V_132 )
goto V_379;
V_130 = F_43 ( V_6 -> V_3 -> V_99 ) ;
F_210 ( V_9 -> V_134 != 1 &&
V_9 -> V_133 != V_130 ) ;
V_9 -> V_133 = V_130 ;
V_379:
F_33 ( & V_9 -> V_131 ) ;
}
void
F_213 ( struct V_8 * V_9 ,
bool V_390 )
{
if ( V_9 -> V_335 )
return;
V_9 -> V_335 =
F_139 ( V_9 -> V_76 ,
V_390 ?
V_247 : 0 ,
L_51 , 0 , 1 ) ;
}
int F_214 ( struct V_391 * V_392 ,
struct V_306 * V_307 )
{
if ( V_392 && V_392 -> V_141 )
V_392 -> V_141 -> type = 0 ;
return F_215 ( V_392 , V_307 ) ;
}
