int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
bool V_4 ,
T_2 * V_5 ,
T_3 V_6 )
{
int V_7 ;
int V_8 ;
T_3 V_9 [ 4 ] ;
if ( V_4 ) {
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] = * V_3 ;
} else {
memcpy ( V_9 , V_3 , sizeof( V_9 ) ) ;
}
for ( V_7 = 0 ; ( T_3 ) V_7 < V_2 -> V_10 ; V_7 ++ )
if ( memcmp ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) == 0 )
break;
switch ( V_6 ) {
case V_12 :
if ( V_7 != V_2 -> V_10 )
return - 1 ;
V_7 = 0 ;
V_8 = F_2 ( V_2 , V_2 -> V_13 ,
V_2 -> V_10 ,
( T_3 * ) & V_7 ,
& V_2 -> V_14 ) ;
if ( V_8 )
return V_8 ;
memcpy ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) ;
F_3 ( V_2 -> V_11 [ V_7 ] . V_5 , V_5 ) ;
break;
case V_15 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
break;
case V_16 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
memset ( V_2 -> V_11 [ V_7 ] . V_3 , 0 ,
sizeof( V_2 -> V_11 [ V_7 ] . V_3 ) ) ;
F_4 ( V_2 -> V_11 [ V_7 ] . V_5 ) ;
F_5 ( V_2 , V_2 -> V_13 , V_7 ) ;
break;
default:
return - 1 ;
}
return V_7 ;
}
inline void F_6 ( struct V_17 * V_18 , T_3 V_19 , T_3 V_20 )
{
F_7 ( V_20 , V_18 -> V_21 + V_19 ) ;
}
inline T_3 F_8 ( struct V_17 * V_18 , T_3 V_19 )
{
return F_9 ( V_18 -> V_21 + V_19 ) ;
}
int F_10 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_28 * V_29 = V_27 -> V_30 -> V_31 ;
struct V_28 * V_32 ;
struct V_28 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_36 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( V_32 != V_29 )
return V_37 ;
switch ( V_24 ) {
case V_40 :
if ( V_33 )
V_36 =
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ;
else
V_36 = V_27 -> V_44 ;
V_36 = F_13 ( V_36 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_16 ) ;
return V_46 ;
case V_47 :
if ( V_33 )
V_36 =
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ;
else
V_36 = V_27 -> V_44 ;
V_36 = F_13 ( V_36 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_12 ) ;
break;
case V_48 :
if ( V_33 )
V_36 =
( (struct V_41 * ) V_33 -> V_42 ) -> V_43 -> V_44 ;
else
V_36 = V_27 -> V_44 ;
V_36 = F_13 ( V_36 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
& V_36 ,
true ,
V_12 ) ;
break;
default:
break;
}
return V_37 ;
}
int F_15 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_49 * V_27 = (struct V_49 * ) V_25 ;
struct V_28 * V_29 = V_27 -> V_50 -> V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_51 [ 4 ] ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
if ( V_32 != V_29 )
return V_37 ;
switch ( V_24 ) {
case V_40 :
F_16 ( V_51 , V_27 -> V_52 . V_53 . V_54 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
V_51 ,
false ,
V_16 ) ;
return V_46 ;
case V_47 :
case V_48 :
F_16 ( V_51 , V_27 -> V_52 . V_53 . V_54 ) ;
F_14 ( V_2 ,
V_32 -> V_45 ,
V_51 ,
false ,
V_12 ) ;
break;
default:
break;
}
return V_37 ;
}
int F_17 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_55 * V_56 = V_25 ;
struct V_1 * V_2 ;
struct V_34 * V_57 ;
T_1 * V_58 ;
T_3 V_36 [ 4 ] ;
switch ( V_24 ) {
case V_59 :
V_57 = F_11 ( (struct V_28 * ) V_56 -> V_31 ) ;
if ( ! V_57 )
return V_37 ;
V_2 = & V_57 -> V_38 ;
V_58 = ( T_1 * ) V_56 -> V_60 ;
F_16 ( V_36 , V_58 ) ;
if ( V_56 -> V_61 & V_62 ) {
F_14 ( V_2 ,
V_56 -> V_63 ,
V_36 ,
false ,
V_12 ) ;
} else {
F_14 ( V_2 ,
V_56 -> V_63 ,
V_36 ,
false ,
V_16 ) ;
}
break;
default:
break;
}
return V_37 ;
}
struct V_64 * F_18 ( struct V_65 * V_66 , bool V_67 )
{
struct V_64 * V_68 = NULL ;
unsigned long V_69 ;
F_19 ( & V_66 -> V_70 , V_69 ) ;
if ( ! F_20 ( & V_66 -> V_71 ) ) {
V_68 = F_21 ( V_66 -> V_71 . V_72 ,
struct V_64 , V_73 ) ;
F_22 ( & V_68 -> V_73 ) ;
}
F_23 ( & V_66 -> V_70 , V_69 ) ;
if ( ! V_68 ) {
V_68 = F_24 ( sizeof( * V_68 ) , V_74 ) ;
if ( V_68 ) {
V_68 -> V_75 = true ;
F_25 ( & V_68 -> V_73 ) ;
F_26 ( & V_68 -> V_76 ) ;
}
}
if ( ! V_68 ) {
F_27 ( L_1 ) ;
return NULL ;
}
if ( V_67 ) {
F_28 ( & V_68 -> V_77 , 2 ) ;
V_68 -> V_78 = true ;
} else {
F_28 ( & V_68 -> V_77 , 1 ) ;
}
return V_68 ;
}
void F_29 ( struct V_65 * V_66 , struct V_64 * V_68 )
{
unsigned long V_69 ;
if ( V_68 -> V_75 ) {
F_30 ( V_68 ) ;
} else {
V_68 -> V_79 = false ;
V_68 -> V_80 = NULL ;
V_68 -> V_78 = false ;
F_19 ( & V_66 -> V_70 , V_69 ) ;
F_31 ( & V_68 -> V_73 , & V_66 -> V_71 ) ;
F_23 ( & V_66 -> V_70 , V_69 ) ;
}
}
void F_32 ( struct V_65 * V_66 ,
struct V_64 * V_68 )
{
if ( F_33 ( & V_68 -> V_77 ) )
F_29 ( V_66 , V_68 ) ;
}
static void F_34 ( struct V_64 * V_68 , T_3 V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_68 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) V_83 -> V_87 ;
struct V_1 * V_2 ;
T_3 V_88 = V_86 -> V_89 . V_88 ;
V_2 = V_86 -> V_2 ;
F_35 ( V_86 -> V_90 , V_2 ) ;
F_36 ( V_2 , V_86 , V_88 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_64 * V_68 )
{
struct V_91 * V_92 = & V_68 -> V_92 ;
struct V_65 * V_93 = & V_2 -> V_66 ;
bool V_94 = false ;
int V_95 = 0 ;
int V_96 = 0 ;
V_96 = F_38 ( V_68 -> V_76 ,
V_68 -> V_79 ,
V_97 ) ;
if ( ! V_96 ) {
F_27 ( L_2 ,
V_92 -> V_98 , V_96 ) ;
V_95 = - V_99 ;
F_39 ( V_2 ) ;
goto V_100;
}
V_94 = V_68 -> V_101 . error ;
if ( V_94 ) {
F_27 ( L_3 ,
V_92 -> V_98 , V_68 -> V_101 . V_102 ,
V_68 -> V_101 . V_103 ) ;
V_95 = - V_104 ;
goto V_100;
}
V_100:
F_32 ( V_93 , V_68 ) ;
return V_95 ;
}
enum V_105 F_40 ( struct V_1 * V_2 ,
struct V_64
* V_68 )
{
struct V_106 * V_31 = & V_2 -> V_107 ;
enum V_105 V_108 ;
struct V_91 * V_92 = & V_68 -> V_92 ;
int V_95 = 0 ;
V_108 = F_41 ( V_31 , V_92 ) ;
if ( V_108 ) {
F_27 ( L_4 , V_92 -> V_98 ) ;
F_29 ( & V_2 -> V_66 , V_68 ) ;
return V_108 ;
}
if ( V_68 -> V_78 )
V_95 = F_37 ( V_2 , V_68 ) ;
if ( V_95 )
V_108 = V_109 ;
return V_108 ;
}
void F_42 ( struct V_110 * V_90 )
{
F_43 ( & V_90 -> V_111 ) ;
}
void F_35 ( struct V_110 * V_90 , struct V_1 * V_2 )
{
if ( ! F_33 ( & V_90 -> V_111 ) )
return;
F_5 ( V_2 , V_2 -> V_112 , V_90 -> V_113 . V_114 ) ;
F_30 ( V_90 ) ;
}
void F_44 ( struct V_115 * V_89 )
{
struct V_85 * V_86 = (struct V_85 * ) V_89 ;
F_43 ( & V_86 -> V_77 ) ;
}
void F_45 ( struct V_115 * V_89 )
{
struct V_85 * V_86 ;
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 ;
T_3 V_88 ;
V_86 = F_46 ( V_89 ) ;
if ( ! F_33 ( & V_86 -> V_77 ) )
return;
V_2 = V_86 -> V_2 ;
V_88 = V_86 -> V_89 . V_88 ;
V_2 -> V_117 [ V_88 ] = NULL ;
V_68 = F_18 ( & V_2 -> V_66 , false ) ;
if ( ! V_68 )
return;
V_68 -> V_80 = F_34 ;
V_68 -> V_84 = ( void * ) & V_86 -> V_118 ;
V_116 = & V_68 -> V_92 ;
V_116 -> V_98 = V_119 ;
V_116 -> V_120 = 1 ;
V_116 -> V_121 . V_122 . V_123 . V_83 = & V_86 -> V_118 ;
V_116 -> V_121 . V_122 . V_123 . V_124 = ( V_125 ) V_68 ;
V_116 -> V_121 . V_122 . V_123 . V_126 = true ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_5 ) ;
}
struct V_115 * F_47 ( struct V_127 * V_38 , int V_128 )
{
struct V_1 * V_2 = F_48 ( V_38 ) ;
if ( ( V_128 < V_129 ) || ( V_128 >= V_2 -> V_130 ) )
return NULL ;
return & V_2 -> V_117 [ V_128 ] -> V_89 ;
}
void F_49 ( struct V_106 * V_31 ,
enum V_131 V_132 ,
char * V_133 ,
T_4 * V_134 ,
T_3 V_135 )
{
T_3 V_136 ;
if ( ! ( V_31 -> V_137 & V_132 ) )
return;
F_50 ( V_31 , V_132 , L_6 , V_133 ) ;
F_50 ( V_31 , V_132 , L_7 , V_134 ,
( unsigned long long ) F_51 ( V_134 ) ) ;
for ( V_136 = 0 ; V_136 < V_135 ; V_136 += 8 )
F_50 ( V_31 , V_132 , L_8 , V_136 , V_134 [ V_136 / 8 ] ) ;
}
T_2 T_5 * F_52 ( void * V_138 )
{
struct V_106 * V_31 = (struct V_106 * ) V_138 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_53 ( struct V_139 * V_73 )
{
struct V_139 * V_140 ;
if ( F_20 ( V_73 ) )
return NULL ;
V_140 = ( void * ) V_73 -> V_72 ;
F_54 ( V_140 ) ;
return ( void * ) V_140 ;
}
enum V_105 F_55 ( struct V_17 * V_18 ,
struct V_141 * V_142 ,
T_4 V_135 ,
T_3 V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) V_18 -> V_146 ;
if ( ! V_142 )
return V_147 ;
V_142 -> V_135 = F_56 ( V_135 , V_143 ) ;
V_142 -> V_148 = F_57 ( & V_145 -> V_31 , V_142 -> V_135 ,
( V_149 * ) & V_142 -> V_150 , V_151 ) ;
if ( ! V_142 -> V_148 )
return V_152 ;
return 0 ;
}
void F_58 ( struct V_17 * V_18 , struct V_141 * V_142 )
{
struct V_144 * V_145 = (struct V_144 * ) V_18 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 )
return;
F_59 ( & V_145 -> V_31 , V_142 -> V_135 ,
V_142 -> V_148 , ( V_149 ) V_142 -> V_150 ) ;
V_142 -> V_148 = NULL ;
}
enum V_105 F_60 ( struct V_17 * V_18 ,
struct V_153 * V_142 ,
T_3 V_135 )
{
if ( ! V_142 )
return V_147 ;
V_142 -> V_135 = V_135 ;
V_142 -> V_148 = F_24 ( V_135 , V_151 ) ;
if ( V_142 -> V_148 )
return 0 ;
else
return V_152 ;
}
enum V_105 F_61 ( struct V_17 * V_18 ,
struct V_153 * V_142 )
{
if ( ! V_142 )
return V_147 ;
F_30 ( V_142 -> V_148 ) ;
V_142 -> V_148 = NULL ;
return 0 ;
}
enum V_105 F_62 ( struct V_106 * V_31 ,
struct V_154 * V_155 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_152 ;
V_116 = & V_68 -> V_92 ;
memcpy ( & V_116 -> V_121 . V_122 . V_157 . V_92 , V_155 ,
sizeof( V_116 -> V_121 . V_122 . V_157 . V_92 ) ) ;
V_116 -> V_98 = V_158 ;
V_116 -> V_120 = 1 ;
V_116 -> V_121 . V_122 . V_157 . V_31 = V_31 ;
V_116 -> V_121 . V_122 . V_157 . V_124 = ( V_125 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_9 ) ;
return V_108 ;
}
void F_63 ( struct V_82 * V_83 , T_2 V_159 , T_2 V_160 , T_2 V_161 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_64 ( V_86 , V_159 , 0 , V_160 , V_161 ) ;
}
void F_65 ( struct V_82 * V_83 , int V_162 )
{
struct V_85 * V_86 ;
T_3 V_163 = V_164 ;
T_2 V_165 = 0 ;
bool V_166 ;
unsigned long V_69 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_19 ( & V_86 -> V_167 , V_69 ) ;
if ( V_86 -> V_168 ) {
V_86 -> V_168 = 0 ;
V_165 = 1 ;
}
V_166 = ! ( V_83 -> V_169 & V_170 ) ;
V_83 -> V_169 |= V_170 ;
F_23 ( & V_86 -> V_167 , V_69 ) ;
if ( V_166 ) {
if ( ! V_162 )
F_66 ( V_83 ) ;
else
V_163 = V_171 ;
F_64 ( V_86 , V_163 , V_165 , 0 , 0 ) ;
F_67 ( V_86 ) ;
}
}
static void F_68 ( unsigned long V_172 )
{
struct V_85 * V_86 = (struct V_85 * ) V_172 ;
struct V_82 * V_83 = (struct V_82 * ) & V_86 -> V_118 ;
F_65 ( V_83 , 1 ) ;
}
void F_69 ( struct V_82 * V_83 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_70 ( & V_86 -> V_173 ) ;
V_86 -> V_173 . V_174 = F_68 ;
V_86 -> V_173 . V_175 = V_176 + V_177 ;
V_86 -> V_173 . V_178 = ( unsigned long ) V_86 ;
F_71 ( & V_86 -> V_173 ) ;
}
void F_66 ( struct V_82 * V_83 )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_83 -> V_87 ;
F_72 ( & V_86 -> V_173 ) ;
}
static void F_73 ( struct V_179 * V_180 )
{
struct V_181 * V_182 =
& ( (struct V_183 * ) V_180 ) -> V_182 ;
if ( V_182 -> V_184 )
V_182 -> V_80 ( V_182 -> V_184 ) ;
}
void F_74 ( struct V_106 * V_31 ,
struct V_181 * V_182 ,
T_3 V_185 )
{
struct V_183 * V_180 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
V_180 = & V_2 -> V_186 [ V_185 ] ;
memcpy ( & V_180 -> V_182 , V_182 , sizeof( * V_182 ) ) ;
F_75 ( & V_180 -> V_180 , F_73 ) ;
F_76 ( V_2 -> V_187 , & V_180 -> V_180 ) ;
}
static void F_77 ( struct V_179 * V_180 )
{
struct V_64 * V_68 =
( (struct V_183 * ) V_180 ) -> V_68 ;
struct V_188 V_189 ;
struct V_190 * V_191 =
& V_68 -> V_92 . V_121 . V_122 . V_192 . V_92 ;
struct V_1 * V_2 =
(struct V_1 * ) V_68 -> V_92 . V_121 . V_122 . V_192 . V_31 -> V_156 ;
V_189 . V_66 = NULL ;
V_189 . V_102 = V_68 -> V_101 . V_102 ;
V_189 . V_103 = V_68 -> V_101 . V_103 ;
V_189 . V_193 = V_68 -> V_101 . V_193 ;
V_189 . V_194 = V_68 -> V_101 . V_194 ;
V_189 . V_124 = 0 ;
V_189 . error = V_68 -> V_101 . error ;
V_191 -> V_80 ( V_68 -> V_92 . V_121 . V_122 . V_192 . V_31 ,
V_191 -> V_195 , & V_189 ) ;
F_32 ( & V_2 -> V_66 , V_68 ) ;
}
static void F_78 ( struct V_64 * V_68 ,
T_3 V_196 )
{
struct V_183 * V_180 ;
struct V_190 * V_191 =
& V_68 -> V_92 . V_121 . V_122 . V_192 . V_92 ;
struct V_1 * V_2 =
(struct V_1 * ) V_68 -> V_92 . V_121 . V_122 . V_192 . V_31 ->
V_156 ;
if ( V_191 && V_191 -> V_80 ) {
F_50 ( & V_2 -> V_107 , V_197 , L_10 , V_198 ) ;
F_43 ( & V_68 -> V_77 ) ;
V_180 = & V_2 -> V_186 [ V_191 -> V_185 ] ;
V_180 -> V_68 = V_68 ;
F_75 ( & V_180 -> V_180 , F_77 ) ;
F_76 ( V_2 -> V_187 , & V_180 -> V_180 ) ;
F_50 ( & V_2 -> V_107 , V_197 , L_11 , V_198 ) ;
} else {
F_50 ( & V_2 -> V_107 , V_197 , L_12 , V_198 ) ;
}
}
enum V_105 F_79 ( struct V_106 * V_31 ,
struct V_190 * V_191 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
F_50 ( & V_2 -> V_107 , V_197 , L_6 , V_198 ) ;
V_68 = F_18 ( & V_2 -> V_66 , false ) ;
if ( ! V_68 )
return V_152 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_80 = F_78 ;
V_68 -> V_84 = V_191 ;
memcpy ( & V_116 -> V_121 . V_122 . V_192 . V_92 , V_191 ,
sizeof( * V_191 ) ) ;
V_116 -> V_121 . V_122 . V_192 . V_31 = V_31 ;
V_116 -> V_98 = V_199 ;
V_116 -> V_120 = 1 ;
V_116 -> V_121 . V_122 . V_192 . V_124 = ( V_125 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_13 ) ;
return V_108 ;
}
enum V_105 F_80 ( struct V_106 * V_31 ,
struct V_141 * V_200 ,
T_2 V_201 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_152 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_84 = NULL ;
V_116 -> V_121 . V_122 . V_202 . V_66 = V_31 -> V_66 ;
V_116 -> V_121 . V_122 . V_202 . V_203 = V_200 -> V_150 ;
V_116 -> V_121 . V_122 . V_202 . V_204 = V_200 -> V_148 ;
V_116 -> V_121 . V_122 . V_202 . V_201 = V_201 ;
V_116 -> V_98 = V_205 ;
V_116 -> V_120 = 1 ;
V_116 -> V_121 . V_122 . V_202 . V_124 = ( V_125 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_14 ) ;
return V_108 ;
}
enum V_105 F_81 ( struct V_106 * V_31 ,
struct V_141 * V_200 ,
T_2 V_201 )
{
enum V_105 V_108 ;
struct V_64 * V_68 ;
struct V_91 * V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
V_68 = F_18 ( & V_2 -> V_66 , true ) ;
if ( ! V_68 )
return V_152 ;
V_116 = & V_68 -> V_92 ;
V_68 -> V_84 = NULL ;
V_116 -> V_121 . V_122 . V_206 . V_66 = V_31 -> V_66 ;
V_116 -> V_121 . V_122 . V_206 . V_203 = V_200 -> V_150 ;
V_116 -> V_121 . V_122 . V_206 . V_204 = V_200 -> V_148 ;
V_116 -> V_121 . V_122 . V_206 . V_201 = V_201 ;
V_116 -> V_98 = V_207 ;
V_116 -> V_120 = 1 ;
V_116 -> V_121 . V_122 . V_206 . V_124 = ( V_125 ) V_68 ;
V_108 = F_40 ( V_2 , V_68 ) ;
if ( V_108 )
F_27 ( L_15 ) ;
return V_108 ;
}
enum V_105 F_82 ( struct V_106 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_156 ;
enum V_105 V_95 = 0 ;
int V_96 ;
F_50 ( V_31 , V_208 , L_16 ,
V_198 , __LINE__ , V_31 , V_2 ) ;
F_83 ( 2 , & V_2 -> V_209 ) ;
V_96 = F_38 ( V_2 -> V_210 ,
( F_84 ( & V_2 -> V_209 ) == 1 ) ,
V_211 ) ;
F_85 ( & V_2 -> V_209 ) ;
if ( ! V_96 ) {
F_27 ( L_17 , V_96 ) ;
V_95 = V_212 ;
}
return V_95 ;
}
void F_86 ( struct V_106 * V_31 , struct V_82 * V_83 )
{
struct V_213 V_92 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
F_50 ( V_31 , V_214 , L_18 , V_198 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_215 = V_216 ;
V_92 . V_217 = true ;
V_92 . V_218 = 0x3 ;
( void ) F_87 ( V_2 , V_83 , & V_92 , false ) ;
}
enum V_105 F_88 ( struct V_219 * * V_133 )
{
struct V_220 * V_221 ;
struct V_219 * V_222 ;
V_221 = F_89 ( L_19 , 0 , 0 ) ;
if ( F_90 ( V_221 ) )
return V_223 ;
V_222 = F_24 ( sizeof( * V_222 ) + F_91 ( V_221 ) ,
V_151 ) ;
if ( ! V_222 ) {
F_92 ( V_221 ) ;
return V_223 ;
}
V_222 -> V_221 = V_221 ;
* V_133 = V_222 ;
return 0 ;
}
void F_93 ( struct V_219 * V_133 )
{
if ( V_133 ) {
F_92 ( V_133 -> V_221 ) ;
F_30 ( V_133 ) ;
}
}
enum V_105 F_94 ( struct V_106 * V_31 ,
struct V_141 * V_142 )
{
enum V_105 V_108 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
V_108 = F_95 ( V_2 , V_142 , V_224 ,
V_225 ) ;
return V_108 ;
}
enum V_105 F_96 ( struct V_219 * V_133 ,
void * V_52 ,
T_3 V_226 ,
T_3 V_20 )
{
T_3 V_227 = 0 ;
int V_228 ;
enum V_105 V_229 = 0 ;
F_97 ( V_133 ) ;
V_228 = F_98 ( V_133 , V_52 , V_226 ) ;
if ( ! V_228 )
F_99 ( V_133 , ( T_2 * ) & V_227 ) ;
if ( V_227 != V_20 ) {
F_27 ( L_20 ) ;
V_229 = V_223 ;
}
return V_229 ;
}
struct V_82 * F_100 ( struct V_106 * V_31 ,
struct V_230 * V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_156 ;
struct V_85 * V_86 ;
struct V_231 * V_232 ;
T_3 V_233 [ 4 ] , V_234 [ 4 ] ;
T_6 V_235 , V_236 ;
struct V_237 * V_238 ;
struct V_239 * V_240 = (struct V_239 * ) V_134 -> V_240 ;
struct V_241 * V_242 = (struct V_241 * ) V_134 -> V_242 ;
if ( V_240 -> V_243 == 4 ) {
memset ( V_233 , 0 , sizeof( V_233 ) ) ;
V_233 [ 0 ] = F_13 ( V_240 -> V_244 ) ;
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
V_234 [ 0 ] = F_13 ( V_240 -> V_245 ) ;
} else {
V_238 = (struct V_237 * ) V_134 -> V_240 ;
F_16 ( V_233 , V_238 -> V_244 . V_53 . V_54 ) ;
F_16 ( V_234 , V_238 -> V_245 . V_53 . V_54 ) ;
}
V_235 = F_101 ( V_242 -> V_246 ) ;
V_236 = F_101 ( V_242 -> V_247 ) ;
V_232 = F_102 ( & V_2 -> V_248 , V_236 , V_234 , V_235 ,
V_233 , false ) ;
if ( ! V_232 )
return NULL ;
V_86 = V_232 -> V_86 ;
return & V_86 -> V_118 ;
}
void F_103 ( struct V_230 * V_134 , T_6 V_226 , T_3 V_249 )
{
struct V_241 * V_242 ;
struct V_239 * V_240 ;
T_6 V_250 ;
T_6 V_251 ;
T_2 * V_52 = ( T_2 * ) V_134 -> V_142 . V_148 ;
V_250 = ( V_134 -> V_4 ) ? 20 : 40 ;
V_240 = (struct V_239 * ) ( V_52 + V_134 -> V_252 ) ;
V_242 = (struct V_241 * ) ( V_52 + V_134 -> V_252 + V_250 ) ;
V_251 = V_226 + V_134 -> V_253 + V_250 ;
V_240 -> V_254 = F_104 ( V_251 ) ;
V_242 -> V_255 = F_105 ( V_249 ) ;
}
enum V_105 F_106 ( struct V_256 * V_92 ,
struct V_230 * V_134 )
{
struct V_239 * V_240 ;
struct V_237 * V_238 ;
struct V_241 * V_242 ;
T_6 V_250 ;
T_6 V_257 ;
T_2 * V_142 = ( T_2 * ) V_134 -> V_142 . V_148 ;
struct V_258 * V_259 = (struct V_258 * ) V_134 -> V_142 . V_148 ;
if ( V_259 -> V_260 == F_104 ( 0x8100 ) ) {
V_92 -> V_261 = true ;
V_134 -> V_262 = F_101 ( ( (struct V_263 * ) V_259 ) -> V_264 ) & V_265 ;
}
V_134 -> V_252 = ( V_92 -> V_261 ) ? 18 : 14 ;
V_250 = ( V_92 -> V_266 ) ? 40 : 20 ;
V_134 -> V_4 = ( V_92 -> V_266 ) ? false : true ;
V_134 -> V_240 = V_142 + V_134 -> V_252 ;
V_240 = (struct V_239 * ) V_134 -> V_240 ;
V_134 -> V_242 = V_134 -> V_240 + V_250 ;
V_242 = (struct V_241 * ) V_134 -> V_242 ;
if ( V_134 -> V_4 ) {
V_257 = F_101 ( V_240 -> V_254 ) ;
} else {
V_238 = (struct V_237 * ) V_134 -> V_240 ;
V_257 = F_101 ( V_238 -> V_267 ) + V_250 ;
}
V_134 -> V_268 = V_257 + V_134 -> V_252 ;
if ( V_92 -> V_267 < V_134 -> V_268 - 4 ) {
F_27 ( L_21 ,
V_92 -> V_267 , V_134 -> V_268 ) ;
return V_269 ;
}
V_134 -> V_253 = ( V_242 -> V_270 ) << 2 ;
V_134 -> V_271 = V_257 - V_250 - V_134 -> V_253 ;
V_134 -> V_178 = ( V_134 -> V_271 ) ? V_134 -> V_242 + V_134 -> V_253 : NULL ;
V_134 -> V_272 = V_134 -> V_252 + V_250 + V_134 -> V_253 ;
V_134 -> V_249 = F_13 ( V_242 -> V_255 ) ;
return 0 ;
}
static void F_107 ( unsigned long V_31 )
{
struct V_106 * V_273 = (struct V_106 * ) V_31 ;
struct V_274 * V_275 = & V_273 -> V_276 ;
struct V_274 * V_277 = NULL ;
T_6 V_185 ;
unsigned long V_69 ;
V_275 -> V_278 . V_279 ( V_275 , & V_275 -> V_280 ) ;
for ( V_185 = 0 ; V_185 < V_281 ; V_185 ++ ) {
F_19 ( & V_275 -> V_282 , V_69 ) ;
if ( V_273 -> V_283 [ V_185 ] ) {
if ( V_273 -> V_283 [ V_185 ] -> V_284 ) {
V_277 = & V_273 -> V_283 [ V_185 ] -> V_276 ;
V_277 -> V_278 . V_279 ( V_277 , & V_277 -> V_280 ) ;
}
}
F_23 ( & V_275 -> V_282 , V_69 ) ;
}
F_108 ( & V_275 -> V_285 ,
V_176 + F_109 ( V_286 ) ) ;
}
void F_110 ( struct V_106 * V_31 )
{
struct V_274 * V_287 = & V_31 -> V_276 ;
F_70 ( & V_287 -> V_285 ) ;
V_287 -> V_285 . V_174 = F_107 ;
V_287 -> V_285 . V_178 = ( unsigned long ) V_31 ;
F_108 ( & V_287 -> V_285 ,
V_176 + F_109 ( V_286 ) ) ;
}
void F_111 ( struct V_106 * V_31 )
{
struct V_274 * V_287 = & V_31 -> V_276 ;
F_112 ( & V_287 -> V_285 ) ;
}
