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
if ( V_87 -> V_99 ) {
V_78 += V_87 -> V_99 -> V_103 ;
V_79 += V_87 -> V_99 -> V_104 ;
}
V_2 -> V_82 = V_90 -> V_92 ;
V_2 -> V_105 = V_90 -> V_23 ;
if ( V_90 -> V_92 ) {
V_2 -> V_83 = V_2 -> V_82 -> V_58 . V_74 ;
V_30 = F_7 ( V_9 ,
V_90 -> V_92 -> V_58 . V_10 ,
64 , 64 , V_78 , V_79 ) ;
} else if ( V_90 -> V_23 ) {
V_30 = F_12 ( V_9 , V_90 -> V_23 ,
V_87 -> V_102 -> V_106 ,
V_87 -> V_102 -> V_107 ,
V_78 , V_79 ) ;
} else {
F_18 ( V_9 , false , 0 , 0 ) ;
return;
}
if ( ! V_30 ) {
V_2 -> V_108 = V_87 -> V_102 -> V_109 + V_2 -> V_110 ;
V_2 -> V_111 = V_87 -> V_102 -> V_112 + V_2 -> V_113 ;
F_18 ( V_9 , true ,
V_2 -> V_108 + V_78 ,
V_2 -> V_111 + V_79 ) ;
V_2 -> V_84 = V_78 - V_2 -> V_78 ;
V_2 -> V_85 = V_79 - V_2 -> V_79 ;
} else {
F_10 ( L_8 ) ;
}
}
int F_50 ( struct V_86 * V_87 ,
struct V_95 * V_102 )
{
struct V_98 * V_114 = V_102 -> V_99 ;
bool V_115 ;
struct V_116 V_117 = {
. V_118 = V_102 -> V_119 ,
. y1 = V_102 -> V_120 ,
. V_121 = V_102 -> V_119 + V_102 -> V_122 ,
. V_123 = V_102 -> V_120 + V_102 -> V_124 ,
} ;
struct V_116 V_125 = {
. V_118 = V_102 -> V_109 ,
. y1 = V_102 -> V_112 ,
. V_121 = V_102 -> V_109 + V_102 -> V_106 ,
. V_123 = V_102 -> V_112 + V_102 -> V_107 ,
} ;
struct V_116 V_126 = V_125 ;
int V_30 ;
V_30 = F_51 ( V_87 , V_102 -> V_6 , V_114 ,
& V_117 , & V_125 , & V_126 ,
V_127 ,
V_128 ,
V_128 ,
false , true , & V_115 ) ;
if ( ! V_30 && V_114 ) {
struct V_77 * V_6 = V_102 -> V_6 ;
struct V_129 * V_130 ;
struct V_1 * V_2 = F_28 ( V_6 ) ;
struct V_8 * V_9 = F_49 ( V_6 -> V_76 ) ;
struct V_131 * V_132 = F_43 ( V_114 ) ;
V_130 = F_52 ( V_2 -> V_5 . V_102 ) ;
if ( ( V_125 . V_121 > V_114 -> V_11 ||
V_125 . V_123 > V_114 -> V_12 ) ) {
F_10 ( L_9 ) ;
return - V_18 ;
}
F_31 ( & V_9 -> V_133 ) ;
if ( V_130 -> V_134 && V_9 -> V_135 &&
! ( V_9 -> V_136 == 1 && V_2 -> V_137 )
&& V_9 -> V_135 != V_132 ) {
F_10 ( L_10
L_11 ) ;
V_30 = - V_18 ;
}
F_33 ( & V_9 -> V_133 ) ;
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
if ( V_97 -> V_106 != 64 || V_97 -> V_107 != 64 ) {
F_10 ( L_12 ,
V_97 -> V_106 , V_97 -> V_107 ) ;
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
struct V_138 * V_97 )
{
struct V_1 * V_2 = F_28 ( V_97 -> V_6 ) ;
int V_139 = 1 << F_55 ( & V_2 -> V_5 ) ;
bool V_140 = V_97 -> V_141 &
F_56 ( F_57 ( V_6 -> V_3 ) ) ;
if ( V_140 != V_97 -> V_142 )
return - V_18 ;
if ( V_97 -> V_139 != V_139 &&
V_97 -> V_139 != 0 ) {
F_10 ( L_14 ) ;
return - V_18 ;
}
if ( V_97 -> V_143 . V_144 == 0 )
V_97 -> V_145 . V_144 = V_97 -> V_143 . clock ;
return 0 ;
}
void F_58 ( struct V_77 * V_6 ,
struct V_138 * V_146 )
{
}
void F_59 ( struct V_77 * V_6 ,
struct V_138 * V_146 )
{
struct V_147 * V_148 = V_6 -> V_102 -> V_148 ;
if ( V_148 ) {
V_6 -> V_102 -> V_148 = NULL ;
F_60 ( & V_6 -> V_76 -> V_149 ) ;
if ( F_61 ( V_6 ) == 0 )
F_62 ( V_6 , V_148 ) ;
else
F_63 ( V_6 , V_148 ) ;
F_64 ( & V_6 -> V_76 -> V_149 ) ;
}
}
struct V_138 *
F_65 ( struct V_77 * V_6 )
{
struct V_138 * V_102 ;
struct V_150 * V_130 ;
if ( F_66 ( ! V_6 -> V_102 ) )
return NULL ;
V_130 = F_67 ( V_6 -> V_102 , sizeof( * V_130 ) , V_151 ) ;
if ( ! V_130 )
return NULL ;
V_102 = & V_130 -> V_33 ;
F_68 ( V_6 , V_102 ) ;
return V_102 ;
}
void F_69 ( struct V_77 * V_6 )
{
struct V_150 * V_130 ;
if ( V_6 -> V_102 ) {
F_70 ( V_6 -> V_102 ) ;
F_71 ( F_72 ( V_6 -> V_102 ) ) ;
}
V_130 = F_73 ( sizeof( * V_130 ) , V_151 ) ;
if ( ! V_130 ) {
F_10 ( L_15 ) ;
return;
}
V_6 -> V_102 = & V_130 -> V_33 ;
V_6 -> V_102 -> V_6 = V_6 ;
}
void
F_74 ( struct V_77 * V_6 ,
struct V_138 * V_102 )
{
F_75 ( V_6 , V_102 ) ;
}
struct V_95 *
F_76 ( struct V_86 * V_87 )
{
struct V_95 * V_102 ;
struct V_89 * V_90 ;
V_90 = F_67 ( V_87 -> V_102 , sizeof( * V_90 ) , V_151 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_93 = 0 ;
memset ( & V_90 -> V_152 , 0 , sizeof( V_90 -> V_152 ) ) ;
memset ( & V_90 -> V_153 , 0 , sizeof( V_90 -> V_153 ) ) ;
V_90 -> V_154 = 0 ;
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
V_90 = F_73 ( sizeof( * V_90 ) , V_151 ) ;
if ( ! V_90 ) {
F_10 ( L_16 ) ;
return;
}
V_87 -> V_102 = & V_90 -> V_33 ;
V_87 -> V_102 -> V_87 = V_87 ;
V_87 -> V_102 -> V_155 = V_127 ;
}
void
F_79 ( struct V_86 * V_87 ,
struct V_95 * V_102 )
{
struct V_89 * V_90 = F_40 ( V_102 ) ;
if ( V_90 -> V_152 . V_28 ) {
F_10 ( L_17 ) ;
F_16 ( & V_90 -> V_152 ) ;
}
if ( V_90 -> V_153 . V_28 ) {
F_10 ( L_18 ) ;
F_16 ( & V_90 -> V_153 ) ;
}
if ( V_90 -> V_92 )
F_38 ( & V_90 -> V_92 ) ;
if ( V_90 -> V_23 )
F_42 ( & V_90 -> V_23 ) ;
F_80 ( V_87 , V_102 ) ;
}
struct V_156 *
F_81 ( struct V_157 * V_5 )
{
struct V_156 * V_102 ;
struct V_129 * V_130 ;
if ( F_66 ( ! V_5 -> V_102 ) )
return NULL ;
V_130 = F_67 ( V_5 -> V_102 , sizeof( * V_130 ) , V_151 ) ;
if ( ! V_130 )
return NULL ;
V_102 = & V_130 -> V_33 ;
F_82 ( V_5 , V_102 ) ;
return V_102 ;
}
void F_83 ( struct V_157 * V_5 )
{
struct V_129 * V_130 ;
if ( V_5 -> V_102 ) {
F_84 ( V_5 -> V_102 ) ;
F_71 ( F_52 ( V_5 -> V_102 ) ) ;
}
V_130 = F_73 ( sizeof( * V_130 ) , V_151 ) ;
if ( ! V_130 ) {
F_10 ( L_19 ) ;
return;
}
F_85 ( V_5 , & V_130 -> V_33 ) ;
}
void
F_86 ( struct V_157 * V_5 ,
struct V_156 * V_102 )
{
F_87 ( V_5 , V_102 ) ;
}
static void F_88 ( struct V_98 * V_158 )
{
struct V_159 * V_160 =
F_46 ( V_158 ) ;
F_89 ( V_158 ) ;
F_38 ( & V_160 -> V_101 ) ;
if ( V_160 -> V_33 . V_161 )
F_90 ( & V_160 -> V_33 . V_161 ) ;
F_71 ( V_160 ) ;
}
static int F_91 ( struct V_98 * V_158 ,
struct V_162 * V_163 ,
unsigned V_164 , unsigned V_165 ,
struct V_166 * V_167 ,
unsigned V_168 )
{
struct V_8 * V_9 = F_49 ( V_158 -> V_76 ) ;
struct V_159 * V_160 =
F_46 ( V_158 ) ;
struct V_166 V_169 ;
int V_30 , V_170 = 1 ;
if ( V_9 -> V_171 == V_172 )
return - V_18 ;
F_26 ( V_9 -> V_76 ) ;
V_30 = F_92 ( & V_9 -> V_173 , true ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
if ( ! V_168 ) {
V_168 = 1 ;
V_167 = & V_169 ;
V_169 . V_118 = V_169 . y1 = 0 ;
V_169 . V_121 = V_158 -> V_11 ;
V_169 . V_123 = V_158 -> V_12 ;
} else if ( V_164 & V_174 ) {
V_168 /= 2 ;
V_170 = 2 ;
}
if ( V_9 -> V_171 == V_175 )
V_30 = F_93 ( V_9 , & V_160 -> V_33 ,
V_167 , NULL , NULL , 0 , 0 ,
V_168 , V_170 , NULL ) ;
else
V_30 = F_94 ( V_9 , & V_160 -> V_33 ,
V_167 , NULL , NULL , 0 , 0 ,
V_168 , V_170 , NULL ) ;
F_95 ( V_9 , false ) ;
F_96 ( & V_9 -> V_173 ) ;
F_29 ( V_9 -> V_76 ) ;
return 0 ;
}
int F_97 ( struct V_8 * V_9 ,
struct V_162 * V_163 ,
struct V_131 * V_132 ,
struct V_176 T_8 * V_177 ,
struct V_178 * V_179 ,
T_3 V_168 )
{
switch ( V_9 -> V_171 ) {
case V_175 :
return F_98 ( V_9 , V_163 , V_132 ,
V_177 , V_179 , V_168 ) ;
case V_180 :
return F_99 ( V_9 , V_163 , V_132 ,
V_177 , NULL , V_179 , V_168 ,
1 , false , true ) ;
default:
F_100 ( true ,
L_20 ) ;
}
return - V_181 ;
}
static int F_101 ( struct V_8 * V_9 ,
struct V_46 * V_101 ,
struct V_131 * * V_182 ,
const struct V_183
* V_184 ,
bool V_185 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_159 * V_160 ;
enum V_186 V_187 ;
int V_30 ;
struct V_188 V_189 ;
if ( V_9 -> V_171 == V_172 )
return - V_181 ;
if ( F_9 ( ! V_101 -> V_190 ) )
return - V_18 ;
if ( F_9 ( V_101 -> V_191 [ 0 ] != 1 ||
V_101 -> V_192 != 1 ||
V_101 -> V_193 . V_11 < V_184 -> V_11 ||
V_101 -> V_193 . V_12 < V_184 -> V_12 ||
V_101 -> V_193 . V_194 != 1 ) ) {
F_10 ( L_21
L_22 ) ;
return - V_18 ;
}
switch ( V_184 -> V_195 ) {
case V_196 :
V_187 = V_197 ;
break;
case V_198 :
V_187 = V_199 ;
break;
case V_200 :
V_187 = V_201 ;
break;
case V_202 :
V_187 = V_203 ;
break;
default:
F_10 ( L_23 ,
F_102 ( V_184 -> V_195 , & V_189 ) ) ;
return - V_18 ;
}
if ( ! V_9 -> V_204 && V_187 != V_101 -> V_187 ) {
F_10 ( L_24 ) ;
return - V_18 ;
}
V_160 = F_73 ( sizeof( * V_160 ) , V_151 ) ;
if ( ! V_160 ) {
V_30 = - V_19 ;
goto V_205;
}
F_103 ( V_76 , & V_160 -> V_33 . V_33 , V_184 ) ;
V_160 -> V_101 = F_47 ( V_101 ) ;
V_160 -> V_33 . V_206 = V_184 -> V_207 [ 0 ] ;
V_160 -> V_185 = V_185 ;
* V_182 = & V_160 -> V_33 ;
V_30 = F_104 ( V_76 , & V_160 -> V_33 . V_33 ,
& V_208 ) ;
if ( V_30 )
goto V_209;
return 0 ;
V_209:
F_38 ( & V_101 ) ;
F_71 ( V_160 ) ;
V_205:
return V_30 ;
}
static void F_105 ( struct V_98 * V_158 )
{
struct V_210 * V_211 =
F_44 ( V_158 ) ;
F_89 ( V_158 ) ;
F_42 ( & V_211 -> V_100 ) ;
if ( V_211 -> V_33 . V_161 )
F_90 ( & V_211 -> V_33 . V_161 ) ;
F_71 ( V_211 ) ;
}
static int F_106 ( struct V_98 * V_158 ,
struct V_162 * V_163 ,
unsigned V_164 , unsigned V_165 ,
struct V_166 * V_167 ,
unsigned V_168 )
{
struct V_8 * V_9 = F_49 ( V_158 -> V_76 ) ;
struct V_210 * V_211 =
F_44 ( V_158 ) ;
struct V_166 V_169 ;
int V_30 , V_212 = 1 ;
F_26 ( V_9 -> V_76 ) ;
V_30 = F_92 ( & V_9 -> V_173 , true ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
if ( ! V_168 ) {
V_168 = 1 ;
V_167 = & V_169 ;
V_169 . V_118 = V_169 . y1 = 0 ;
V_169 . V_121 = V_158 -> V_11 ;
V_169 . V_123 = V_158 -> V_12 ;
} else if ( V_164 & V_174 ) {
V_168 /= 2 ;
V_212 = 2 ;
}
switch ( V_9 -> V_171 ) {
case V_180 :
V_30 = F_99 ( V_9 , NULL , & V_211 -> V_33 , NULL ,
V_167 , NULL , V_168 , V_212 ,
true , true ) ;
break;
case V_175 :
V_30 = F_107 ( V_9 , & V_211 -> V_33 ,
V_167 , NULL , V_168 ,
V_212 , true , NULL ) ;
break;
case V_172 :
V_30 = F_108 ( V_9 , & V_211 -> V_33 , 0 , 0 ,
V_167 , V_168 , V_212 ) ;
break;
default:
V_30 = - V_18 ;
F_100 ( true , L_25 ) ;
break;
}
F_95 ( V_9 , false ) ;
F_96 ( & V_9 -> V_173 ) ;
F_29 ( V_9 -> V_76 ) ;
return V_30 ;
}
static int F_109 ( struct V_131 * V_132 )
{
struct V_8 * V_9 = F_49 ( V_132 -> V_33 . V_76 ) ;
struct V_22 * V_213 ;
int V_30 ;
V_213 = V_132 -> V_23 ? F_44 ( & V_132 -> V_33 ) -> V_100 :
F_46 ( & V_132 -> V_33 ) -> V_101 -> V_94 . V_214 ;
if ( ! V_213 )
return 0 ;
switch ( V_9 -> V_171 ) {
case V_172 :
F_110 ( V_9 ) ;
V_30 = F_111 ( V_9 , V_213 , false ) ;
F_112 ( V_9 ) ;
break;
case V_175 :
case V_180 :
if ( V_132 -> V_23 )
return F_113 ( V_9 , V_213 ,
false ) ;
return F_114 ( V_9 , V_213 ,
& V_215 , false ) ;
default:
return - V_18 ;
}
return V_30 ;
}
static int F_115 ( struct V_131 * V_132 )
{
struct V_8 * V_9 = F_49 ( V_132 -> V_33 . V_76 ) ;
struct V_22 * V_213 ;
V_213 = V_132 -> V_23 ? F_44 ( & V_132 -> V_33 ) -> V_100 :
F_46 ( & V_132 -> V_33 ) -> V_101 -> V_94 . V_214 ;
if ( F_66 ( ! V_213 ) )
return 0 ;
return F_116 ( V_9 , V_213 , false ) ;
}
static int F_117 ( struct V_75 * V_76 ,
const struct V_183 * V_184 ,
struct V_22 * V_216 ,
struct V_46 * * V_217 )
{
T_3 V_187 ;
struct V_218 V_219 = { 0 } ;
struct V_220 * V_94 ;
unsigned int V_221 ;
struct V_188 V_189 ;
int V_30 ;
switch ( V_184 -> V_195 ) {
case V_196 :
case V_198 :
V_187 = V_199 ;
V_221 = 4 ;
break;
case V_200 :
case V_202 :
V_187 = V_201 ;
V_221 = 2 ;
break;
case 8 :
V_187 = V_222 ;
V_221 = 1 ;
break;
default:
F_10 ( L_26 ,
F_102 ( V_184 -> V_195 , & V_189 ) ) ;
return - V_18 ;
}
V_219 . V_11 = V_184 -> V_223 [ 0 ] / V_221 ;
V_219 . V_12 = V_184 -> V_12 ;
V_219 . V_194 = 1 ;
V_30 = F_118 ( V_76 ,
0 ,
0 ,
V_187 ,
true ,
1 ,
0 ,
0 ,
V_219 ,
V_217 ) ;
if ( V_30 ) {
F_10 ( L_27 ) ;
return V_30 ;
}
V_94 = & ( * V_217 ) -> V_94 ;
F_31 ( & V_94 -> V_9 -> V_224 ) ;
( void ) F_119 ( V_94 , false , true ) ;
F_42 ( & V_94 -> V_214 ) ;
V_94 -> V_214 = F_45 ( V_216 ) ;
V_94 -> V_225 = 0 ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_224 ) ;
return 0 ;
}
static int F_121 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_131 * * V_182 ,
const struct V_183
* V_184 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_210 * V_211 ;
unsigned int V_226 ;
struct V_188 V_189 ;
int V_30 ;
V_226 = V_184 -> V_12 * V_184 -> V_223 [ 0 ] ;
if ( F_9 ( V_226 > V_23 -> V_33 . V_227 * V_31 ) ) {
F_10 ( L_28
L_22 ) ;
return - V_18 ;
}
if ( V_9 -> V_171 == V_175 ) {
switch ( V_184 -> V_195 ) {
case V_198 :
case V_196 :
break;
case V_202 :
case V_200 :
break;
default:
F_10 ( L_23 ,
F_102 ( V_184 -> V_195 , & V_189 ) ) ;
return - V_18 ;
}
}
V_211 = F_73 ( sizeof( * V_211 ) , V_151 ) ;
if ( ! V_211 ) {
V_30 = - V_19 ;
goto V_205;
}
F_103 ( V_76 , & V_211 -> V_33 . V_33 , V_184 ) ;
V_211 -> V_33 . V_23 = true ;
V_211 -> V_100 = F_45 ( V_23 ) ;
V_211 -> V_33 . V_206 = V_184 -> V_207 [ 0 ] ;
* V_182 = & V_211 -> V_33 ;
V_30 = F_104 ( V_76 , & V_211 -> V_33 . V_33 ,
& V_228 ) ;
if ( V_30 )
goto V_209;
return 0 ;
V_209:
F_42 ( & V_23 ) ;
F_71 ( V_211 ) ;
V_205:
return V_30 ;
}
static bool
F_122 ( struct V_8 * V_9 , T_3 V_11 , T_3 V_12 )
{
if ( V_11 > V_9 -> V_229 ||
V_12 > V_9 -> V_230 )
return false ;
return true ;
}
struct V_131 *
F_123 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_46 * V_101 ,
bool V_231 ,
const struct V_183 * V_184 )
{
struct V_131 * V_132 = NULL ;
bool V_185 = false ;
int V_30 ;
if ( F_122 ( V_9 , V_184 -> V_11 , V_184 -> V_12 ) &&
V_23 && V_231 &&
V_184 -> V_11 > 64 &&
V_9 -> V_171 == V_180 ) {
V_30 = F_117 ( V_9 -> V_76 , V_184 ,
V_23 , & V_101 ) ;
if ( V_30 )
return F_124 ( V_30 ) ;
V_185 = true ;
}
if ( V_101 ) {
V_30 = F_101 ( V_9 , V_101 , & V_132 ,
V_184 ,
V_185 ) ;
if ( V_185 )
F_38 ( & V_101 ) ;
} else if ( V_23 ) {
V_30 = F_121 ( V_9 , V_23 , & V_132 ,
V_184 ) ;
} else {
F_125 () ;
}
if ( V_30 )
return F_124 ( V_30 ) ;
V_132 -> V_232 = F_109 ;
V_132 -> V_233 = F_115 ;
return V_132 ;
}
static struct V_98 * F_126 ( struct V_75 * V_76 ,
struct V_162 * V_163 ,
const struct V_183 * V_184 )
{
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_48 * V_49 = F_127 ( V_163 ) -> V_49 ;
struct V_131 * V_132 = NULL ;
struct V_46 * V_101 = NULL ;
struct V_22 * V_51 = NULL ;
struct V_234 * V_161 ;
int V_30 ;
if ( ! F_128 ( V_9 ,
V_184 -> V_223 [ 0 ] ,
V_184 -> V_12 ) ) {
F_10 ( L_29 ) ;
return F_124 ( - V_19 ) ;
}
V_161 = F_129 ( V_49 , V_184 -> V_207 [ 0 ] ) ;
if ( F_9 ( V_161 == NULL ) ) {
F_10 ( L_30 ) ;
return F_124 ( - V_235 ) ;
}
V_30 = F_130 ( V_9 , V_49 ,
V_184 -> V_207 [ 0 ] ,
& V_101 , & V_51 ) ;
if ( V_30 )
goto V_236;
if ( ! V_51 &&
! F_122 ( V_9 , V_184 -> V_11 , V_184 -> V_12 ) ) {
F_10 ( L_31 ,
V_9 -> V_229 ,
V_9 -> V_230 ) ;
goto V_236;
}
V_132 = F_123 ( V_9 , V_51 , V_101 ,
! ( V_9 -> V_237 & V_238 ) ,
V_184 ) ;
if ( F_131 ( V_132 ) ) {
V_30 = F_132 ( V_132 ) ;
goto V_236;
}
V_236:
if ( V_51 )
F_42 ( & V_51 ) ;
if ( V_101 )
F_38 ( & V_101 ) ;
if ( V_30 ) {
F_10 ( L_32 , V_30 ) ;
F_90 ( & V_161 ) ;
return F_124 ( V_30 ) ;
} else
V_132 -> V_161 = V_161 ;
return & V_132 -> V_33 ;
}
int
F_133 ( struct V_75 * V_76 ,
struct V_239 * V_102 )
{
struct V_138 * V_240 ;
struct V_77 * V_6 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
int V_57 ;
F_134 (state, crtc, crtc_state, i) {
unsigned long V_241 = 0 ;
if ( V_9 -> V_171 == V_180 ) {
if ( V_6 -> V_3 -> V_99 ) {
int V_154 = V_6 -> V_3 -> V_99 -> V_223 [ 0 ] /
V_6 -> V_3 -> V_99 -> V_11 ;
V_241 += V_6 -> V_143 . V_242 * V_154 *
V_6 -> V_143 . V_243 ;
}
if ( V_241 > V_9 -> V_244 )
return - V_18 ;
}
}
return F_135 ( V_76 , V_102 ) ;
}
int F_136 ( struct V_75 * V_76 ,
struct V_239 * V_102 ,
bool V_245 )
{
return F_137 ( V_76 , V_102 , false ) ;
}
static int F_138 ( struct V_8 * V_9 ,
struct V_162 * V_163 ,
struct V_131 * V_132 ,
struct V_46 * V_101 ,
T_3 V_246 ,
T_9 V_247 , T_9 V_248 ,
struct V_178 * V_167 ,
T_3 V_168 )
{
return F_93 ( V_9 , V_132 , NULL , V_167 ,
& V_101 -> V_94 , V_247 , V_248 ,
V_168 , 1 , NULL ) ;
}
int F_139 ( struct V_8 * V_9 ,
struct V_162 * V_163 ,
struct V_131 * V_132 ,
struct V_46 * V_101 ,
T_3 V_246 ,
T_9 V_247 , T_9 V_248 ,
struct V_178 * V_167 ,
T_3 V_168 )
{
int V_30 ;
switch ( V_9 -> V_171 ) {
case V_180 :
V_30 = F_94 ( V_9 , V_132 , NULL , V_167 ,
& V_101 -> V_94 , V_247 , V_248 ,
V_168 , 1 , NULL ) ;
break;
case V_175 :
V_30 = F_138 ( V_9 , V_163 , V_132 , V_101 ,
V_246 , V_247 , V_248 , V_167 ,
V_168 ) ;
break;
default:
F_100 ( true ,
L_33 ) ;
V_30 = - V_181 ;
break;
}
if ( V_30 )
return V_30 ;
F_95 ( V_9 , false ) ;
return 0 ;
}
static void
F_140 ( struct V_8 * V_9 )
{
if ( V_9 -> V_249 )
return;
V_9 -> V_249 =
F_141 ( V_9 -> V_76 ,
V_250 ,
L_34 , 0 , 1 ) ;
if ( ! V_9 -> V_249 )
return;
}
int F_142 ( struct V_8 * V_9 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
int V_30 ;
F_143 ( V_76 ) ;
V_76 -> V_80 . V_251 = & V_252 ;
V_76 -> V_80 . V_253 = 1 ;
V_76 -> V_80 . V_254 = 1 ;
V_76 -> V_80 . V_255 = V_9 -> V_229 ;
V_76 -> V_80 . V_256 = V_9 -> V_230 ;
F_144 ( V_76 ) ;
F_140 ( V_9 ) ;
V_30 = F_145 ( V_9 ) ;
if ( V_30 ) {
V_30 = F_146 ( V_9 ) ;
if ( V_30 )
V_30 = F_147 ( V_9 ) ;
}
return V_30 ;
}
int F_148 ( struct V_8 * V_9 )
{
int V_30 ;
F_149 ( V_9 -> V_76 ) ;
if ( V_9 -> V_171 == V_175 )
V_30 = F_150 ( V_9 ) ;
else if ( V_9 -> V_171 == V_180 )
V_30 = F_151 ( V_9 ) ;
else
V_30 = F_152 ( V_9 ) ;
return V_30 ;
}
int F_153 ( struct V_75 * V_76 , void * V_257 ,
struct V_162 * V_163 )
{
struct V_258 * V_259 = V_257 ;
struct V_1 * V_2 ;
struct V_77 * V_6 ;
int V_30 = 0 ;
F_31 ( & V_76 -> V_80 . V_81 ) ;
if ( V_259 -> V_164 & V_260 ) {
F_32 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_28 ( V_6 ) ;
V_2 -> V_78 = V_259 -> V_261 ;
V_2 -> V_79 = V_259 -> V_262 ;
}
F_33 ( & V_76 -> V_80 . V_81 ) ;
return 0 ;
}
V_6 = F_154 ( V_76 , V_259 -> V_263 ) ;
if ( ! V_6 ) {
V_30 = - V_235 ;
goto V_182;
}
V_2 = F_28 ( V_6 ) ;
V_2 -> V_78 = V_259 -> V_261 ;
V_2 -> V_79 = V_259 -> V_262 ;
V_182:
F_33 ( & V_76 -> V_80 . V_81 ) ;
return V_30 ;
}
int F_155 ( struct V_8 * F_49 ,
unsigned V_11 , unsigned V_12 , unsigned V_73 ,
unsigned V_264 , unsigned V_194 )
{
if ( F_49 -> V_237 & V_265 )
F_156 ( F_49 , V_266 , V_73 ) ;
else if ( F_157 ( F_49 ) )
F_20 ( V_73 , F_49 -> V_39 +
V_267 ) ;
F_156 ( F_49 , V_268 , V_11 ) ;
F_156 ( F_49 , V_269 , V_12 ) ;
F_156 ( F_49 , V_270 , V_264 ) ;
if ( F_158 ( F_49 , V_271 ) != V_194 ) {
F_10 ( L_35 ,
V_194 , V_264 , F_158 ( F_49 , V_271 ) ) ;
return - V_18 ;
}
return 0 ;
}
int F_159 ( struct V_8 * F_49 )
{
struct V_272 * V_273 ;
T_3 V_57 ;
F_49 -> V_274 = F_158 ( F_49 , V_268 ) ;
F_49 -> V_275 = F_158 ( F_49 , V_269 ) ;
F_49 -> V_276 = F_158 ( F_49 , V_270 ) ;
if ( F_49 -> V_237 & V_265 )
F_49 -> V_277 =
F_158 ( F_49 , V_266 ) ;
else if ( F_157 ( F_49 ) )
F_49 -> V_277 = F_21 ( F_49 -> V_39 +
V_267 ) ;
if ( ! ( F_49 -> V_237 & V_278 ) )
return 0 ;
F_49 -> V_279 = F_158 ( F_49 ,
V_280 ) ;
if ( F_49 -> V_279 == 0 )
F_49 -> V_279 = 1 ;
for ( V_57 = 0 ; V_57 < F_49 -> V_279 ; ++ V_57 ) {
V_273 = & F_49 -> V_281 [ V_57 ] ;
F_156 ( F_49 , V_282 , V_57 ) ;
V_273 -> V_3 = F_158 ( F_49 , V_283 ) ;
V_273 -> V_284 = F_158 ( F_49 , V_285 ) ;
V_273 -> V_286 = F_158 ( F_49 , V_287 ) ;
V_273 -> V_11 = F_158 ( F_49 , V_288 ) ;
V_273 -> V_12 = F_158 ( F_49 , V_289 ) ;
F_156 ( F_49 , V_282 , V_290 ) ;
if ( V_57 == 0 && F_49 -> V_279 == 1 &&
V_273 -> V_11 == 0 && V_273 -> V_12 == 0 ) {
V_273 -> V_11 = F_49 -> V_274 - V_273 -> V_284 ;
V_273 -> V_12 = F_49 -> V_275 - V_273 -> V_286 ;
}
}
return 0 ;
}
int F_160 ( struct V_8 * F_49 )
{
struct V_272 * V_273 ;
T_3 V_57 ;
F_156 ( F_49 , V_268 , F_49 -> V_274 ) ;
F_156 ( F_49 , V_269 , F_49 -> V_275 ) ;
F_156 ( F_49 , V_270 , F_49 -> V_276 ) ;
if ( F_49 -> V_237 & V_265 )
F_156 ( F_49 , V_266 ,
F_49 -> V_277 ) ;
else if ( F_157 ( F_49 ) )
F_20 ( F_49 -> V_277 ,
F_49 -> V_39 + V_267 ) ;
if ( ! ( F_49 -> V_237 & V_278 ) )
return 0 ;
for ( V_57 = 0 ; V_57 < F_49 -> V_279 ; ++ V_57 ) {
V_273 = & F_49 -> V_281 [ V_57 ] ;
F_156 ( F_49 , V_282 , V_57 ) ;
F_156 ( F_49 , V_283 , V_273 -> V_3 ) ;
F_156 ( F_49 , V_285 , V_273 -> V_284 ) ;
F_156 ( F_49 , V_287 , V_273 -> V_286 ) ;
F_156 ( F_49 , V_288 , V_273 -> V_11 ) ;
F_156 ( F_49 , V_289 , V_273 -> V_12 ) ;
F_156 ( F_49 , V_282 , V_290 ) ;
}
return 0 ;
}
bool F_128 ( struct V_8 * V_9 ,
T_3 V_73 ,
T_3 V_12 )
{
return ( ( V_291 ) V_73 * ( V_291 ) V_12 ) < ( V_291 )
( ( V_9 -> V_171 == V_180 ) ?
V_9 -> V_244 : V_9 -> V_292 ) ;
}
T_1 F_161 ( struct V_75 * V_76 , unsigned int V_293 )
{
return 0 ;
}
int F_162 ( struct V_75 * V_76 , unsigned int V_293 )
{
return - V_181 ;
}
void F_163 ( struct V_75 * V_76 , unsigned int V_293 )
{
}
static int F_164 ( struct V_8 * V_9 , unsigned V_294 ,
struct V_178 * V_295 )
{
struct V_75 * V_76 = V_9 -> V_76 ;
struct V_1 * V_2 ;
struct V_157 * V_296 ;
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
V_2 = F_165 ( V_296 ) ;
if ( V_294 > V_2 -> V_297 ) {
V_2 -> V_298 = V_295 [ V_2 -> V_297 ] . V_71 ;
V_2 -> V_299 = V_295 [ V_2 -> V_297 ] . V_72 ;
V_2 -> V_300 = true ;
V_2 -> V_301 = V_295 [ V_2 -> V_297 ] . V_36 ;
V_2 -> V_302 = V_295 [ V_2 -> V_297 ] . V_37 ;
F_166
( & V_296 -> V_33 , V_76 -> V_80 . V_303 ,
V_2 -> V_301 ) ;
F_166
( & V_296 -> V_33 , V_76 -> V_80 . V_304 ,
V_2 -> V_302 ) ;
} else {
V_2 -> V_298 = 800 ;
V_2 -> V_299 = 600 ;
V_2 -> V_300 = false ;
F_166
( & V_296 -> V_33 , V_76 -> V_80 . V_303 ,
0 ) ;
F_166
( & V_296 -> V_33 , V_76 -> V_80 . V_304 ,
0 ) ;
}
V_296 -> V_305 = F_167 ( V_296 , true ) ;
}
F_33 ( & V_76 -> V_80 . V_81 ) ;
F_168 ( V_76 ) ;
return 0 ;
}
int F_169 ( struct V_77 * V_6 ,
T_10 * V_306 , T_10 * V_307 , T_10 * V_308 ,
T_3 V_62 ,
struct V_309 * V_310 )
{
struct V_8 * V_9 = F_49 ( V_6 -> V_76 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ ) {
F_170 ( L_36 , V_57 ,
V_306 [ V_57 ] , V_307 [ V_57 ] , V_308 [ V_57 ] ) ;
F_156 ( V_9 , V_311 + V_57 * 3 + 0 , V_306 [ V_57 ] >> 8 ) ;
F_156 ( V_9 , V_311 + V_57 * 3 + 1 , V_307 [ V_57 ] >> 8 ) ;
F_156 ( V_9 , V_311 + V_57 * 3 + 2 , V_308 [ V_57 ] >> 8 ) ;
}
return 0 ;
}
int F_171 ( struct V_157 * V_5 , int V_143 )
{
return 0 ;
}
enum V_312
F_167 ( struct V_157 * V_5 , bool V_313 )
{
T_3 V_279 ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_1 * V_2 = F_165 ( V_5 ) ;
V_279 = F_158 ( V_9 , V_314 ) ;
return ( ( F_165 ( V_5 ) -> V_297 < V_279 &&
V_2 -> V_300 ) ?
V_315 : V_316 ) ;
}
void F_172 ( struct V_317 * V_143 )
{
V_143 -> V_318 = V_143 -> V_242 + 50 ;
V_143 -> V_319 = V_143 -> V_318 + 50 ;
V_143 -> V_320 = V_143 -> V_319 + 50 ;
V_143 -> V_321 = V_143 -> V_243 + 50 ;
V_143 -> V_322 = V_143 -> V_321 + 50 ;
V_143 -> V_323 = V_143 -> V_322 + 50 ;
V_143 -> clock = ( T_1 ) V_143 -> V_320 * ( T_1 ) V_143 -> V_323 / 100 * 6 ;
V_143 -> V_324 = F_173 ( V_143 ) ;
}
int F_174 ( struct V_157 * V_5 ,
T_3 V_255 , T_3 V_256 )
{
struct V_1 * V_2 = F_165 ( V_5 ) ;
struct V_75 * V_76 = V_5 -> V_76 ;
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_317 * V_143 = NULL ;
struct V_317 * V_325 ;
struct V_317 V_326 = { F_175 ( L_37 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_57 ;
T_1 V_327 = 4 ;
if ( V_9 -> V_328 )
V_327 = 2 ;
if ( V_9 -> V_171 == V_180 ) {
V_255 = F_176 ( V_255 , V_9 -> V_329 ) ;
V_255 = F_176 ( V_255 , V_9 -> V_229 ) ;
V_256 = F_176 ( V_256 , V_9 -> V_330 ) ;
V_256 = F_176 ( V_256 , V_9 -> V_230 ) ;
}
V_143 = F_177 ( V_76 , & V_326 ) ;
if ( ! V_143 )
return 0 ;
V_143 -> V_242 = V_2 -> V_298 ;
V_143 -> V_243 = V_2 -> V_299 ;
F_172 ( V_143 ) ;
if ( F_128 ( V_9 ,
V_143 -> V_242 * V_327 ,
V_143 -> V_243 ) ) {
F_178 ( V_5 , V_143 ) ;
} else {
F_179 ( V_76 , V_143 ) ;
V_143 = NULL ;
}
if ( V_2 -> V_331 ) {
F_180 ( & V_2 -> V_331 -> V_332 ) ;
F_179 ( V_76 , V_2 -> V_331 ) ;
}
V_2 -> V_331 = V_143 ;
for ( V_57 = 0 ; V_333 [ V_57 ] . type != 0 ; V_57 ++ ) {
V_325 = & V_333 [ V_57 ] ;
if ( V_325 -> V_242 > V_255 ||
V_325 -> V_243 > V_256 )
continue;
if ( ! F_128 ( V_9 ,
V_325 -> V_242 * V_327 ,
V_325 -> V_243 ) )
continue;
V_143 = F_177 ( V_76 , V_325 ) ;
if ( ! V_143 )
return 0 ;
V_143 -> V_324 = F_173 ( V_143 ) ;
F_178 ( V_5 , V_143 ) ;
}
F_181 ( V_5 ) ;
F_182 ( & V_5 -> V_334 ) ;
return 1 ;
}
int F_183 ( struct V_157 * V_5 ,
struct V_335 * V_336 ,
T_11 V_337 )
{
struct V_1 * V_2 = F_165 ( V_5 ) ;
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
if ( V_336 == V_9 -> V_338 )
V_2 -> V_134 = V_337 ;
return 0 ;
}
int
F_184 ( struct V_157 * V_5 ,
struct V_156 * V_102 ,
struct V_335 * V_336 ,
T_11 V_337 )
{
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
struct V_129 * V_130 = F_52 ( V_102 ) ;
struct V_1 * V_2 = F_165 ( V_5 ) ;
if ( V_336 == V_9 -> V_338 ) {
V_130 -> V_134 = V_337 ;
V_2 -> V_134 = V_130 -> V_134 ;
} else {
return - V_18 ;
}
return 0 ;
}
int
F_185 ( struct V_157 * V_5 ,
const struct V_156 * V_102 ,
struct V_335 * V_336 ,
T_11 * V_337 )
{
struct V_8 * V_9 = F_49 ( V_5 -> V_76 ) ;
struct V_129 * V_130 = F_52 ( V_102 ) ;
if ( V_336 == V_9 -> V_338 )
* V_337 = V_130 -> V_134 ;
else {
F_10 ( L_38 , V_336 -> V_339 ) ;
return - V_18 ;
}
return 0 ;
}
int F_186 ( struct V_75 * V_76 , void * V_257 ,
struct V_162 * V_163 )
{
struct V_8 * V_9 = F_49 ( V_76 ) ;
struct V_340 * V_259 =
(struct V_340 * ) V_257 ;
void T_8 * V_341 ;
struct V_178 * V_295 ;
unsigned V_342 ;
int V_30 ;
int V_57 ;
V_291 V_343 = 0 ;
struct V_344 * V_80 = & V_76 -> V_80 ;
struct V_178 V_345 = { 0 } ;
if ( ! V_259 -> V_346 ) {
struct V_178 V_347 = { 0 , 0 , 800 , 600 } ;
F_164 ( V_9 , 1 , & V_347 ) ;
return 0 ;
}
V_342 = V_259 -> V_346 * sizeof( struct V_178 ) ;
V_295 = F_187 ( V_259 -> V_346 , sizeof( struct V_178 ) ,
V_151 ) ;
if ( F_9 ( ! V_295 ) )
return - V_19 ;
V_341 = ( void T_8 * ) ( unsigned long ) V_259 -> V_295 ;
V_30 = F_188 ( V_295 , V_341 , V_342 ) ;
if ( F_9 ( V_30 != 0 ) ) {
F_10 ( L_39 ) ;
V_30 = - V_348 ;
goto V_349;
}
for ( V_57 = 0 ; V_57 < V_259 -> V_346 ; ++ V_57 ) {
if ( V_295 [ V_57 ] . V_36 < 0 ||
V_295 [ V_57 ] . V_37 < 0 ||
V_295 [ V_57 ] . V_36 + V_295 [ V_57 ] . V_71 > V_80 -> V_255 ||
V_295 [ V_57 ] . V_37 + V_295 [ V_57 ] . V_72 > V_80 -> V_256 ) {
F_10 ( L_40 ) ;
V_30 = - V_18 ;
goto V_349;
}
if ( V_295 [ V_57 ] . V_36 + V_295 [ V_57 ] . V_71 > V_345 . V_71 )
V_345 . V_71 = V_295 [ V_57 ] . V_36 + V_295 [ V_57 ] . V_71 ;
if ( V_295 [ V_57 ] . V_37 + V_295 [ V_57 ] . V_72 > V_345 . V_72 )
V_345 . V_72 = V_295 [ V_57 ] . V_37 + V_295 [ V_57 ] . V_72 ;
V_343 += ( V_291 ) V_295 [ V_57 ] . V_71 * ( V_291 ) V_295 [ V_57 ] . V_72 ;
}
if ( V_9 -> V_171 == V_180 ) {
V_291 V_350 = ( V_291 ) V_345 . V_71 * V_345 . V_72 * 4 ;
V_291 V_351 = V_343 * 4 ;
if ( V_350 > V_9 -> V_244 ) {
F_10 ( L_41 ) ;
V_30 = - V_18 ;
goto V_349;
}
if ( V_351 > V_9 -> V_244 ) {
F_10 ( L_42 ) ;
V_30 = - V_18 ;
goto V_349;
}
}
F_164 ( V_9 , V_259 -> V_346 , V_295 ) ;
V_349:
F_71 ( V_295 ) ;
return V_30 ;
}
int F_189 ( struct V_8 * V_9 ,
struct V_131 * V_158 ,
const struct V_166 * V_167 ,
const struct V_178 * V_179 ,
T_7 V_352 , T_7 V_353 ,
int V_168 ,
int V_212 ,
struct V_354 * V_355 )
{
struct V_1 * V_356 [ V_357 ] ;
struct V_77 * V_6 ;
T_1 V_358 = 0 ;
T_1 V_57 , V_359 ;
V_355 -> V_9 = V_9 ;
F_32 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_3 -> V_99 != & V_158 -> V_33 )
continue;
V_356 [ V_358 ++ ] = F_28 ( V_6 ) ;
}
for ( V_359 = 0 ; V_359 < V_358 ; V_359 ++ ) {
struct V_1 * V_297 = V_356 [ V_359 ] ;
T_7 V_109 = V_297 -> V_6 . V_36 ;
T_7 V_112 = V_297 -> V_6 . V_37 ;
T_7 V_360 = V_297 -> V_6 . V_143 . V_242 ;
T_7 V_361 = V_297 -> V_6 . V_143 . V_243 ;
const struct V_166 * V_362 = V_167 ;
const struct V_178 * V_363 = V_179 ;
V_355 -> V_297 = V_297 ;
if ( V_355 -> V_364 > 0 ) {
V_355 -> V_15 = F_8 ( V_9 ,
V_355 -> V_364 ) ;
if ( ! V_355 -> V_15 ) {
F_10 ( L_43
L_44 ) ;
return - V_19 ;
}
memset ( V_355 -> V_15 , 0 , V_355 -> V_364 ) ;
}
V_355 -> V_365 = 0 ;
for ( V_57 = 0 ; V_57 < V_168 ; V_57 ++ , V_362 += V_212 ,
V_363 += V_212 ) {
T_7 V_366 ;
T_7 V_367 ;
if ( V_167 ) {
V_355 -> V_368 = ( T_7 ) V_362 -> V_118 ;
V_355 -> V_369 = ( T_7 ) V_362 -> y1 ;
V_355 -> V_370 = ( T_7 ) V_362 -> V_121 + V_352 -
V_109 ;
V_355 -> V_371 = ( T_7 ) V_362 -> V_123 + V_353 -
V_112 ;
} else {
V_355 -> V_368 = V_363 -> V_36 ;
V_355 -> V_369 = V_363 -> V_37 ;
V_355 -> V_370 = V_355 -> V_368 + V_363 -> V_71 +
V_352 - V_109 ;
V_355 -> V_371 = V_355 -> V_369 + V_363 -> V_72 +
V_353 - V_112 ;
}
V_355 -> V_372 = V_355 -> V_368 + V_352 - V_109 ;
V_355 -> V_373 = V_355 -> V_369 + V_353 - V_112 ;
if ( V_355 -> V_372 >= V_360 ||
V_355 -> V_373 >= V_361 ||
V_355 -> V_370 <= 0 || V_355 -> V_371 <= 0 )
continue;
V_355 -> V_370 = F_190 ( T_7 , V_355 -> V_370 ,
V_360 ) ;
V_355 -> V_371 = F_190 ( T_7 , V_355 -> V_371 ,
V_361 ) ;
V_366 = F_190 ( T_7 , V_355 -> V_372 , 0 ) ;
V_367 = F_190 ( T_7 , V_355 -> V_373 , 0 ) ;
V_355 -> V_372 -= V_366 ;
V_355 -> V_373 -= V_367 ;
V_355 -> V_368 -= V_366 ;
V_355 -> V_369 -= V_367 ;
V_355 -> V_126 ( V_355 ) ;
}
V_355 -> V_374 ( V_355 ) ;
}
return 0 ;
}
int F_191 ( struct V_8 * V_9 ,
struct V_22 * V_213 ,
bool V_375 ,
bool V_376 )
{
struct V_50 * V_51 = & V_213 -> V_33 ;
int V_30 ;
F_13 ( V_51 , false , false , NULL ) ;
V_30 = F_192 ( V_9 , V_51 , V_375 ,
V_376 ) ;
if ( V_30 )
F_17 ( V_51 ) ;
return V_30 ;
}
void F_193 ( struct V_22 * V_213 )
{
if ( V_213 )
F_17 ( & V_213 -> V_33 ) ;
}
void F_194 ( struct V_8 * V_9 ,
struct V_162 * V_163 ,
struct V_22 * V_213 ,
struct V_377 * * V_378 ,
struct V_176 T_8 *
V_177 )
{
struct V_377 * V_379 ;
T_3 V_380 ;
int V_30 ;
V_30 = F_195 ( V_163 , V_9 , & V_379 ,
V_163 ? & V_380 : NULL ) ;
if ( V_213 )
F_196 ( & V_213 -> V_33 , V_379 ) ;
if ( V_163 )
F_197 ( V_9 , F_127 ( V_163 ) ,
V_30 , V_177 , V_379 ,
V_380 ) ;
if ( V_378 )
* V_378 = V_379 ;
else
F_198 ( & V_379 ) ;
F_193 ( V_213 ) ;
}
void F_199 ( struct V_220 * V_94 )
{
F_193 ( V_94 -> V_214 ) ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_224 ) ;
}
int F_200 ( struct V_220 * V_94 ,
bool V_375 )
{
int V_30 = 0 ;
if ( V_375 )
V_30 = F_201 ( & V_94 -> V_9 -> V_224 ) ;
else
F_31 ( & V_94 -> V_9 -> V_224 ) ;
if ( F_9 ( V_30 != 0 ) )
return - V_381 ;
V_30 = F_119 ( V_94 , V_375 , false ) ;
if ( V_30 )
goto V_382;
if ( V_94 -> V_214 ) {
V_30 = F_191 ( V_94 -> V_9 , V_94 -> V_214 ,
V_375 ,
V_94 -> V_9 -> V_383 ) ;
if ( V_30 )
goto V_384;
}
V_30 = F_202 ( V_94 ) ;
if ( V_30 )
goto V_385;
return 0 ;
V_385:
F_193 ( V_94 -> V_214 ) ;
V_384:
F_120 ( V_94 , false , NULL , 0 ) ;
V_382:
F_33 ( & V_94 -> V_9 -> V_224 ) ;
return V_30 ;
}
void F_203 ( struct V_220 * V_94 ,
struct V_377 * * V_378 )
{
if ( V_94 -> V_214 || V_378 )
F_194 ( V_94 -> V_9 , NULL , V_94 -> V_214 ,
V_378 , NULL ) ;
F_120 ( V_94 , false , NULL , 0 ) ;
F_33 ( & V_94 -> V_9 -> V_224 ) ;
}
int F_204 ( struct V_220 * V_94 ,
const struct V_166 * V_167 ,
unsigned V_168 ,
int V_212 )
{
struct V_8 * V_9 = V_94 -> V_9 ;
struct V_218 * V_62 = & F_205 ( V_94 ) -> V_193 ;
struct {
T_4 V_52 ;
T_12 V_386 ;
} * V_15 ;
T_13 * V_53 ;
T_14 V_387 = 0 ;
int V_57 ;
if ( ! V_167 )
return 0 ;
V_15 = F_8 ( V_9 , sizeof( * V_15 ) * V_168 ) ;
if ( ! V_15 ) {
F_10 ( L_45
L_46 ) ;
return - V_19 ;
}
for ( V_57 = 0 ; V_57 < V_168 ; ++ V_57 , V_167 += V_212 , ++ V_15 ) {
V_53 = & V_15 -> V_386 . V_53 ;
V_15 -> V_52 . V_21 = V_388 ;
V_15 -> V_52 . V_62 = sizeof( V_15 -> V_386 ) ;
V_15 -> V_386 . V_10 . V_246 = V_94 -> V_21 ;
V_15 -> V_386 . V_10 . V_60 = 0 ;
V_15 -> V_386 . V_10 . V_61 = 0 ;
if ( V_167 -> V_118 > V_62 -> V_11 || V_167 -> V_121 > V_62 -> V_11 ||
V_167 -> y1 > V_62 -> V_12 || V_167 -> V_123 > V_62 -> V_12 ) {
F_10 ( L_47 ) ;
return - V_18 ;
}
V_53 -> V_36 = V_167 -> V_118 ;
V_53 -> V_37 = V_167 -> y1 ;
V_53 -> V_66 = 0 ;
V_53 -> V_71 = V_167 -> V_121 - V_167 -> V_118 ;
V_53 -> V_72 = V_167 -> V_123 - V_167 -> y1 ;
V_53 -> V_70 = 1 ;
V_387 += sizeof( * V_15 ) ;
}
F_206 ( V_9 , V_387 ) ;
return 0 ;
}
int F_207 ( struct V_8 * V_9 ,
unsigned V_297 ,
T_1 V_255 ,
T_1 V_256 ,
struct V_157 * * V_389 ,
struct V_77 * * V_390 ,
struct V_317 * * V_391 )
{
struct V_157 * V_296 ;
struct V_1 * V_2 ;
struct V_317 * V_143 ;
int V_57 = 0 ;
F_32 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_57 == V_297 )
break;
++ V_57 ;
}
if ( V_57 != V_297 ) {
F_10 ( L_48 ) ;
return - V_18 ;
}
if ( F_208 ( & V_296 -> V_334 ) )
( void ) F_174 ( V_296 , V_255 , V_256 ) ;
if ( F_208 ( & V_296 -> V_334 ) ) {
F_10 ( L_49 ) ;
return - V_18 ;
}
V_2 = F_165 ( V_296 ) ;
* V_389 = V_296 ;
* V_390 = & V_2 -> V_6 ;
F_32 (mode, &con->modes, head) {
if ( V_143 -> type & V_392 )
break;
}
if ( V_143 -> type & V_392 )
* V_391 = V_143 ;
else {
F_100 ( true , L_50 ) ;
* V_391 = F_209 ( & V_296 -> V_334 ,
struct V_317 ,
V_332 ) ;
}
return 0 ;
}
void F_210 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_31 ( & V_9 -> V_133 ) ;
if ( V_2 -> V_137 ) {
if ( -- ( V_9 -> V_136 ) == 0 )
V_9 -> V_135 = NULL ;
V_2 -> V_137 = false ;
}
F_33 ( & V_9 -> V_133 ) ;
}
void F_211 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_131 * V_132 )
{
F_31 ( & V_9 -> V_133 ) ;
F_212 ( ! V_9 -> V_136 && V_9 -> V_135 ) ;
if ( ! V_2 -> V_137 && V_2 -> V_134 ) {
V_9 -> V_135 = V_132 ;
V_2 -> V_137 = true ;
V_9 -> V_136 ++ ;
}
F_33 ( & V_9 -> V_133 ) ;
}
bool F_213 ( struct V_8 * V_9 ,
struct V_77 * V_6 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
bool V_30 ;
F_31 ( & V_9 -> V_133 ) ;
V_30 = ! V_2 -> V_134 || V_9 -> V_136 == 1 ;
F_33 ( & V_9 -> V_133 ) ;
return V_30 ;
}
void F_214 ( struct V_8 * V_9 ,
struct V_77 * V_6 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
struct V_131 * V_132 ;
F_31 ( & V_9 -> V_133 ) ;
if ( ! V_2 -> V_134 )
goto V_382;
V_132 = F_43 ( V_6 -> V_3 -> V_99 ) ;
F_212 ( V_9 -> V_136 != 1 &&
V_9 -> V_135 != V_132 ) ;
V_9 -> V_135 = V_132 ;
V_382:
F_33 ( & V_9 -> V_133 ) ;
}
void
F_215 ( struct V_8 * V_9 ,
bool V_393 )
{
if ( V_9 -> V_338 )
return;
V_9 -> V_338 =
F_141 ( V_9 -> V_76 ,
V_393 ?
V_250 : 0 ,
L_51 , 0 , 1 ) ;
}
int F_216 ( struct V_394 * V_395 ,
struct V_309 * V_310 )
{
if ( V_395 && V_395 -> V_143 )
V_395 -> V_143 -> type = 0 ;
return F_217 ( V_395 , V_310 ) ;
}
