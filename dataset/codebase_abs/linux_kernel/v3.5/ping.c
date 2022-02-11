static inline int F_1 ( struct V_1 * V_1 , unsigned int V_2 , unsigned int V_3 )
{
int V_4 = ( V_2 + F_2 ( V_1 ) ) & V_3 ;
F_3 ( L_1 , V_2 , V_4 ) ;
return V_4 ;
}
static inline struct V_5 * F_4 ( struct V_6 * V_7 ,
struct V_1 * V_1 , unsigned int V_2 )
{
return & V_7 -> V_8 [ F_1 ( V_1 , V_2 , V_9 ) ] ;
}
static int F_5 ( struct V_10 * V_11 , unsigned short V_12 )
{
struct V_13 * V_14 ;
struct V_5 * V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_10 * V_19 = NULL ;
V_17 = F_6 ( V_11 ) ;
F_7 ( & V_6 . V_20 ) ;
if ( V_12 == 0 ) {
T_1 V_21 ;
T_2 V_22 = V_23 + 1 ;
for ( V_21 = 0 ; V_21 < ( 1L << 16 ) ; V_21 ++ , V_22 ++ ) {
if ( ! V_22 )
V_22 ++ ;
V_15 = F_4 ( & V_6 , F_8 ( V_11 ) ,
V_22 ) ;
F_9 (sk2, node, hlist) {
V_18 = F_6 ( V_19 ) ;
if ( V_18 -> V_24 == V_22 )
goto V_25;
}
V_23 = V_12 = V_22 ;
break;
V_25:
;
}
if ( V_21 >= ( 1L << 16 ) )
goto V_26;
} else {
V_15 = F_4 ( & V_6 , F_8 ( V_11 ) , V_12 ) ;
F_9 (sk2, node, hlist) {
V_18 = F_6 ( V_19 ) ;
if ( ( V_18 -> V_24 == V_12 ) &&
( V_19 != V_11 ) &&
( ! V_19 -> V_27 || ! V_11 -> V_27 ) )
goto V_26;
}
}
F_3 ( L_2 , V_12 ) ;
V_17 -> V_24 = V_12 ;
if ( F_10 ( V_11 ) ) {
F_3 ( L_3 ) ;
F_11 ( V_11 ) ;
F_12 ( & V_11 -> V_28 , V_15 ) ;
F_13 ( F_8 ( V_11 ) , V_11 -> V_29 , 1 ) ;
}
F_14 ( & V_6 . V_20 ) ;
return 0 ;
V_26:
F_14 ( & V_6 . V_20 ) ;
return 1 ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_3 ( L_4 , F_6 ( V_11 ) -> V_24 ) ;
F_16 () ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = F_6 ( V_11 ) ;
F_3 ( L_5 , V_17 , V_17 -> V_24 ) ;
if ( F_18 ( V_11 ) ) {
F_7 ( & V_6 . V_20 ) ;
F_19 ( & V_11 -> V_28 ) ;
F_20 ( V_11 ) ;
V_17 -> V_24 = 0 ;
V_17 -> V_30 = 0 ;
F_13 ( F_8 ( V_11 ) , V_11 -> V_29 , - 1 ) ;
F_14 ( & V_6 . V_20 ) ;
}
}
static struct V_10 * F_21 ( struct V_1 * V_1 , T_3 V_31 , T_3 V_32 ,
T_2 V_12 , int V_33 )
{
struct V_5 * V_34 = F_4 ( & V_6 , V_1 , V_12 ) ;
struct V_10 * V_11 = NULL ;
struct V_16 * V_17 ;
struct V_13 * V_35 ;
F_3 ( L_6 ,
( int ) V_12 , & V_32 , V_33 ) ;
F_22 ( & V_6 . V_20 ) ;
F_9 (sk, hnode, hslot) {
V_17 = F_6 ( V_11 ) ;
F_3 ( L_7 , V_11 ,
( int ) V_17 -> V_24 , & V_17 -> V_36 ,
V_11 -> V_37 ) ;
F_3 ( L_8 ) ;
if ( V_17 -> V_24 != V_12 )
continue;
if ( V_17 -> V_36 && V_17 -> V_36 != V_32 )
continue;
if ( V_11 -> V_37 && V_11 -> V_37 != V_33 )
continue;
F_11 ( V_11 ) ;
goto exit;
}
V_11 = NULL ;
exit:
F_23 ( & V_6 . V_20 ) ;
return V_11 ;
}
static void F_24 ( struct V_1 * V_1 , T_4 * V_38 ,
T_4 * V_39 )
{
T_4 * V_40 = V_1 -> V_41 . V_42 ;
unsigned int V_43 ;
do {
V_43 = F_25 ( & V_44 . V_20 ) ;
* V_38 = V_40 [ 0 ] ;
* V_39 = V_40 [ 1 ] ;
} while ( F_26 ( & V_44 . V_20 , V_43 ) );
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
T_4 V_45 = F_28 () ;
T_4 V_46 [ 2 ] ;
struct V_47 * V_47 = F_29 () ;
int V_21 , V_48 , V_49 = V_47 -> V_50 ;
T_5 V_38 , V_39 ;
F_24 ( V_1 , V_46 , V_46 + 1 ) ;
V_38 = F_30 ( & V_51 , V_46 [ 0 ] ) ;
V_39 = F_30 ( & V_51 , V_46 [ 1 ] ) ;
if ( ! F_31 ( V_38 ) || ! F_31 ( V_39 ) || F_32 ( V_39 , V_38 ) )
return - V_52 ;
if ( V_46 [ 0 ] <= V_45 && V_45 <= V_46 [ 1 ] )
return 0 ;
for ( V_21 = 0 ; V_21 < V_47 -> V_53 ; V_21 ++ ) {
int V_54 = F_33 ( int , V_55 , V_49 ) ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
T_5 V_56 = V_47 -> V_57 [ V_21 ] [ V_48 ] ;
if ( F_34 ( V_38 , V_56 ) && F_34 ( V_56 , V_39 ) )
return 0 ;
}
V_49 -= V_54 ;
}
return - V_52 ;
}
static void F_35 ( struct V_10 * V_11 , long V_58 )
{
F_3 ( L_9 ,
F_6 ( V_11 ) , F_6 ( V_11 ) -> V_24 ) ;
F_3 ( L_10 , V_11 -> V_59 . V_60 ) ;
F_36 ( V_11 ) ;
}
static int F_37 ( struct V_10 * V_11 , struct V_61 * V_62 , int V_63 )
{
struct V_64 * V_65 = (struct V_64 * ) V_62 ;
struct V_16 * V_17 = F_6 ( V_11 ) ;
unsigned short V_66 ;
int V_67 ;
int V_68 ;
if ( V_63 < sizeof( struct V_64 ) )
return - V_69 ;
F_3 ( L_11 ,
V_11 , V_65 -> V_70 . V_71 , F_38 ( V_65 -> V_72 ) ) ;
V_67 = F_39 ( F_8 ( V_11 ) , V_65 -> V_70 . V_71 ) ;
if ( V_65 -> V_70 . V_71 == F_40 ( V_73 ) )
V_67 = V_74 ;
if ( ( V_75 == 0 &&
V_17 -> V_76 == 0 && V_17 -> V_77 == 0 &&
V_67 != V_74 ) ||
V_67 == V_78 ||
V_67 == V_79 )
return - V_80 ;
F_41 ( V_11 ) ;
V_68 = - V_69 ;
if ( V_17 -> V_24 != 0 )
goto V_81;
V_68 = - V_82 ;
V_17 -> V_36 = V_17 -> V_83 = V_65 -> V_70 . V_71 ;
V_66 = F_38 ( V_65 -> V_72 ) ;
if ( F_5 ( V_11 , V_66 ) != 0 ) {
V_17 -> V_83 = V_17 -> V_36 = 0 ;
goto V_81;
}
F_3 ( L_12 ,
( int ) V_17 -> V_24 ,
& V_17 -> V_36 ,
( int ) V_11 -> V_37 ) ;
V_68 = 0 ;
if ( V_17 -> V_36 )
V_11 -> V_84 |= V_85 ;
if ( V_66 )
V_11 -> V_84 |= V_86 ;
V_17 -> V_30 = F_42 ( V_17 -> V_24 ) ;
V_17 -> V_87 = 0 ;
V_17 -> V_88 = 0 ;
F_43 ( V_11 ) ;
V_81:
F_44 ( V_11 ) ;
F_3 ( L_13 , V_68 ) ;
return V_68 ;
}
static inline int F_45 ( int type , int V_89 )
{
if ( type == V_90 && V_89 == 0 )
return 1 ;
return 0 ;
}
void F_46 ( struct V_91 * V_92 , T_1 V_93 )
{
struct V_94 * V_95 = (struct V_94 * ) V_92 -> V_40 ;
struct V_96 * V_97 = (struct V_96 * ) ( V_92 -> V_40 + ( V_95 -> V_98 << 2 ) ) ;
struct V_16 * V_16 ;
int type = V_97 -> type ;
int V_89 = V_97 -> V_89 ;
struct V_1 * V_1 = F_47 ( V_92 -> V_99 ) ;
struct V_10 * V_11 ;
int V_100 ;
int V_68 ;
if ( ! F_45 ( V_97 -> type , V_97 -> V_89 ) )
return;
F_3 ( L_14 , type ,
V_89 , F_38 ( V_97 -> V_101 . V_102 . V_103 ) , F_38 ( V_97 -> V_101 . V_102 . V_104 ) ) ;
V_11 = F_21 ( V_1 , V_95 -> V_32 , V_95 -> V_31 ,
F_38 ( V_97 -> V_101 . V_102 . V_103 ) , V_92 -> V_99 -> V_105 ) ;
if ( V_11 == NULL ) {
F_3 ( L_15 ) ;
return;
}
F_3 ( L_16 , V_11 ) ;
V_68 = 0 ;
V_100 = 0 ;
V_16 = F_6 ( V_11 ) ;
switch ( type ) {
default:
case V_106 :
V_68 = V_107 ;
break;
case V_108 :
V_68 = V_109 ;
break;
case V_110 :
V_68 = V_111 ;
V_100 = 1 ;
break;
case V_112 :
if ( V_89 == V_113 ) {
if ( V_16 -> V_114 != V_115 ) {
V_68 = V_116 ;
V_100 = 1 ;
break;
}
goto V_81;
}
V_68 = V_107 ;
if ( V_89 <= V_117 ) {
V_100 = V_118 [ V_89 ] . V_119 ;
V_68 = V_118 [ V_89 ] . V_120 ;
}
break;
case V_121 :
V_68 = V_109 ;
break;
}
if ( ! V_16 -> V_122 ) {
if ( ! V_100 || V_11 -> V_123 != V_124 )
goto V_81;
} else {
F_48 ( V_11 , V_92 , V_68 , 0 ,
V_93 , ( V_125 * ) V_97 ) ;
}
V_11 -> V_126 = V_68 ;
V_11 -> V_127 ( V_11 ) ;
V_81:
F_20 ( V_11 ) ;
}
static int F_49 ( void * V_128 , char * V_129 ,
int V_130 , int V_131 , int V_132 , struct V_91 * V_92 )
{
struct V_133 * V_134 = (struct V_133 * ) V_128 ;
if ( V_130 == 0 ) {
if ( V_131 < sizeof( struct V_96 ) )
F_16 () ;
if ( F_50 ( V_129 + sizeof( struct V_96 ) ,
V_134 -> V_135 , 0 , V_131 - sizeof( struct V_96 ) ,
& V_134 -> V_136 ) )
return - V_137 ;
return 0 ;
}
if ( V_130 < sizeof( struct V_96 ) )
F_16 () ;
if ( F_50
( V_129 , V_134 -> V_135 , V_130 - sizeof( struct V_96 ) ,
V_131 , & V_134 -> V_136 ) )
return - V_137 ;
return 0 ;
}
static int F_51 ( struct V_10 * V_11 , struct V_133 * V_134 ,
struct V_138 * V_139 )
{
struct V_91 * V_92 = F_52 ( & V_11 -> V_140 ) ;
V_134 -> V_136 = F_53 ( ( char * ) & V_134 -> V_97 ,
sizeof( struct V_96 ) , V_134 -> V_136 ) ;
V_134 -> V_97 . V_141 = F_54 ( V_134 -> V_136 ) ;
memcpy ( F_55 ( V_92 ) , & V_134 -> V_97 , sizeof( struct V_96 ) ) ;
V_92 -> V_142 = V_143 ;
return F_56 ( V_11 , V_139 ) ;
}
static int F_57 ( struct V_144 * V_145 , struct V_10 * V_11 , struct V_146 * V_147 ,
T_6 V_148 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
struct V_138 V_139 ;
struct V_16 * V_149 = F_6 ( V_11 ) ;
struct V_150 V_151 ;
struct V_96 V_152 ;
struct V_133 V_134 ;
struct V_153 * V_154 = NULL ;
struct V_155 V_156 ;
int free = 0 ;
T_3 V_31 , V_32 , V_157 ;
V_125 V_158 ;
int V_68 ;
F_3 ( L_17 , V_149 , V_149 -> V_24 ) ;
if ( V_148 > 0xFFFF )
return - V_116 ;
if ( V_147 -> V_159 & V_160 )
return - V_161 ;
if ( F_58 ( ( V_125 * ) & V_152 , V_147 -> V_162 ,
sizeof( struct V_96 ) ) )
return - V_137 ;
if ( ! F_45 ( V_152 . type , V_152 . V_89 ) )
return - V_69 ;
if ( V_147 -> V_163 ) {
struct V_64 * V_164 = (struct V_64 * ) V_147 -> V_163 ;
if ( V_147 -> V_165 < sizeof( * V_164 ) )
return - V_69 ;
if ( V_164 -> V_166 != V_167 )
return - V_69 ;
V_32 = V_164 -> V_70 . V_71 ;
} else {
if ( V_11 -> V_123 != V_124 )
return - V_168 ;
V_32 = V_149 -> V_87 ;
}
V_151 . V_65 = V_149 -> V_83 ;
V_151 . V_169 = NULL ;
V_151 . V_170 = V_11 -> V_37 ;
V_151 . V_171 = 0 ;
V_68 = F_59 ( V_11 , & V_151 . V_171 ) ;
if ( V_68 )
return V_68 ;
if ( V_147 -> V_172 ) {
V_68 = F_60 ( F_8 ( V_11 ) , V_147 , & V_151 ) ;
if ( V_68 )
return V_68 ;
if ( V_151 . V_169 )
free = 1 ;
}
if ( ! V_151 . V_169 ) {
struct V_173 * V_174 ;
F_61 () ;
V_174 = F_62 ( V_149 -> V_174 ) ;
if ( V_174 ) {
memcpy ( & V_156 , V_174 ,
sizeof( * V_174 ) + V_174 -> V_169 . V_175 ) ;
V_151 . V_169 = & V_156 . V_169 ;
}
F_63 () ;
}
V_31 = V_151 . V_65 ;
V_151 . V_65 = V_157 = V_32 ;
if ( V_151 . V_169 && V_151 . V_169 -> V_169 . V_176 ) {
if ( ! V_32 )
return - V_69 ;
V_157 = V_151 . V_169 -> V_169 . V_157 ;
}
V_158 = F_64 ( V_149 -> V_158 ) ;
if ( F_65 ( V_11 , V_177 ) ||
( V_147 -> V_159 & V_178 ) ||
( V_151 . V_169 && V_151 . V_169 -> V_169 . V_179 ) ) {
V_158 |= V_180 ;
}
if ( F_66 ( V_32 ) ) {
if ( ! V_151 . V_170 )
V_151 . V_170 = V_149 -> V_181 ;
if ( ! V_31 )
V_31 = V_149 -> V_182 ;
} else if ( ! V_151 . V_170 )
V_151 . V_170 = V_149 -> V_183 ;
F_67 ( & V_139 , V_151 . V_170 , V_11 -> V_184 , V_158 ,
V_185 , V_11 -> V_186 ,
F_68 ( V_11 ) , V_157 , V_31 , 0 , 0 ) ;
F_69 ( V_11 , F_70 ( & V_139 ) ) ;
V_154 = F_71 ( V_1 , & V_139 , V_11 ) ;
if ( F_72 ( V_154 ) ) {
V_68 = F_73 ( V_154 ) ;
V_154 = NULL ;
if ( V_68 == - V_187 )
F_74 ( V_1 , V_188 ) ;
goto V_81;
}
V_68 = - V_52 ;
if ( ( V_154 -> V_189 & V_190 ) &&
! F_65 ( V_11 , V_191 ) )
goto V_81;
if ( V_147 -> V_159 & V_192 )
goto V_193;
V_194:
if ( ! V_151 . V_65 )
V_151 . V_65 = V_139 . V_32 ;
F_41 ( V_11 ) ;
V_134 . V_97 . type = V_152 . type ;
V_134 . V_97 . V_89 = V_152 . V_89 ;
V_134 . V_97 . V_141 = 0 ;
V_134 . V_97 . V_101 . V_102 . V_103 = V_149 -> V_30 ;
V_134 . V_97 . V_101 . V_102 . V_104 = V_152 . V_101 . V_102 . V_104 ;
V_134 . V_135 = V_147 -> V_162 ;
V_134 . V_136 = 0 ;
V_68 = F_75 ( V_11 , & V_139 , F_49 , & V_134 , V_148 ,
0 , & V_151 , & V_154 , V_147 -> V_159 ) ;
if ( V_68 )
F_76 ( V_11 ) ;
else
V_68 = F_51 ( V_11 , & V_134 , & V_139 ) ;
F_44 ( V_11 ) ;
V_81:
F_77 ( V_154 ) ;
if ( free )
F_78 ( V_151 . V_169 ) ;
if ( ! V_68 ) {
F_79 ( F_8 ( V_11 ) , V_152 . type ) ;
return V_148 ;
}
return V_68 ;
V_193:
F_80 ( & V_154 -> V_195 ) ;
if ( ! ( V_147 -> V_159 & V_196 ) || V_148 )
goto V_194;
V_68 = 0 ;
goto V_81;
}
static int F_81 ( struct V_144 * V_145 , struct V_10 * V_11 , struct V_146 * V_147 ,
T_6 V_148 , int V_197 , int V_198 , int * V_63 )
{
struct V_16 * V_17 = F_6 ( V_11 ) ;
struct V_64 * sin = (struct V_64 * ) V_147 -> V_163 ;
struct V_91 * V_92 ;
int V_199 , V_68 ;
F_3 ( L_18 , V_17 , V_17 -> V_24 ) ;
V_68 = - V_161 ;
if ( V_198 & V_160 )
goto V_81;
if ( V_63 )
* V_63 = sizeof( * sin ) ;
if ( V_198 & V_200 )
return F_82 ( V_11 , V_147 , V_148 ) ;
V_92 = F_83 ( V_11 , V_198 , V_197 , & V_68 ) ;
if ( ! V_92 )
goto V_81;
V_199 = V_92 -> V_148 ;
if ( V_199 > V_148 ) {
V_147 -> V_159 |= V_201 ;
V_199 = V_148 ;
}
V_68 = F_84 ( V_92 , 0 , V_147 -> V_162 , V_199 ) ;
if ( V_68 )
goto V_202;
F_85 ( V_147 , V_11 , V_92 ) ;
if ( sin ) {
sin -> V_166 = V_167 ;
sin -> V_72 = 0 ;
sin -> V_70 . V_71 = F_86 ( V_92 ) -> V_31 ;
memset ( sin -> V_203 , 0 , sizeof( sin -> V_203 ) ) ;
}
if ( V_17 -> V_204 )
F_87 ( V_147 , V_92 ) ;
V_68 = V_199 ;
V_202:
F_88 ( V_11 , V_92 ) ;
V_81:
F_3 ( L_19 , V_68 ) ;
return V_68 ;
}
static int F_89 ( struct V_10 * V_11 , struct V_91 * V_92 )
{
F_3 ( L_20 ,
F_6 ( V_11 ) , F_6 ( V_11 ) -> V_24 , V_92 ) ;
if ( F_90 ( V_11 , V_92 ) < 0 ) {
F_91 ( V_92 ) ;
F_3 ( L_21 ) ;
return - 1 ;
}
return 0 ;
}
void F_92 ( struct V_91 * V_92 )
{
struct V_10 * V_11 ;
struct V_1 * V_1 = F_47 ( V_92 -> V_99 ) ;
struct V_94 * V_95 = F_86 ( V_92 ) ;
struct V_96 * V_97 = F_55 ( V_92 ) ;
T_3 V_31 = V_95 -> V_31 ;
T_3 V_32 = V_95 -> V_32 ;
F_3 ( L_22 ,
V_92 , F_38 ( V_97 -> V_101 . V_102 . V_103 ) , F_38 ( V_97 -> V_101 . V_102 . V_104 ) ) ;
F_93 ( V_92 , V_92 -> V_40 - ( V_125 * ) V_97 ) ;
V_11 = F_21 ( V_1 , V_31 , V_32 , F_38 ( V_97 -> V_101 . V_102 . V_103 ) ,
V_92 -> V_99 -> V_105 ) ;
if ( V_11 != NULL ) {
F_3 ( L_23 , V_11 ) ;
F_89 ( V_11 , F_94 ( V_92 ) ) ;
F_20 ( V_11 ) ;
return;
}
F_3 ( L_15 ) ;
}
static struct V_10 * F_95 ( struct V_205 * V_43 , int V_206 )
{
struct V_10 * V_11 ;
struct V_207 * V_208 = V_43 -> V_209 ;
struct V_1 * V_1 = F_96 ( V_43 ) ;
for ( V_208 -> V_210 = V_206 ; V_208 -> V_210 < V_211 ;
++ V_208 -> V_210 ) {
struct V_13 * V_14 ;
struct V_5 * V_34 ;
V_34 = & V_6 . V_8 [ V_208 -> V_210 ] ;
if ( F_97 ( V_34 ) )
continue;
F_98 (sk, node, hslot) {
if ( F_99 ( F_8 ( V_11 ) , V_1 ) )
goto V_212;
}
}
V_11 = NULL ;
V_212:
return V_11 ;
}
static struct V_10 * F_100 ( struct V_205 * V_43 , struct V_10 * V_11 )
{
struct V_207 * V_208 = V_43 -> V_209 ;
struct V_1 * V_1 = F_96 ( V_43 ) ;
do {
V_11 = F_101 ( V_11 ) ;
} while ( V_11 && ( ! F_99 ( F_8 ( V_11 ) , V_1 ) ) );
if ( ! V_11 )
return F_95 ( V_43 , V_208 -> V_210 + 1 ) ;
return V_11 ;
}
static struct V_10 * F_102 ( struct V_205 * V_43 , T_7 V_213 )
{
struct V_10 * V_11 = F_95 ( V_43 , 0 ) ;
if ( V_11 )
while ( V_213 && ( V_11 = F_100 ( V_43 , V_11 ) ) != NULL )
-- V_213 ;
return V_213 ? NULL : V_11 ;
}
static void * F_103 ( struct V_205 * V_43 , T_7 * V_213 )
{
struct V_207 * V_208 = V_43 -> V_209 ;
V_208 -> V_210 = 0 ;
F_22 ( & V_6 . V_20 ) ;
return * V_213 ? F_102 ( V_43 , * V_213 - 1 ) : V_214 ;
}
static void * F_104 ( struct V_205 * V_43 , void * V_215 , T_7 * V_213 )
{
struct V_10 * V_11 ;
if ( V_215 == V_214 )
V_11 = F_102 ( V_43 , 0 ) ;
else
V_11 = F_100 ( V_43 , V_215 ) ;
++ * V_213 ;
return V_11 ;
}
static void F_105 ( struct V_205 * V_43 , void * V_215 )
{
F_23 ( & V_6 . V_20 ) ;
}
static void F_106 ( struct V_10 * V_216 , struct V_205 * V_217 ,
int V_210 , int * V_148 )
{
struct V_16 * V_149 = F_6 ( V_216 ) ;
T_3 V_218 = V_149 -> V_87 ;
T_3 V_219 = V_149 -> V_36 ;
T_8 V_220 = F_38 ( V_149 -> V_88 ) ;
T_8 V_221 = F_38 ( V_149 -> V_30 ) ;
F_107 ( V_217 , L_24
L_25 ,
V_210 , V_219 , V_221 , V_218 , V_220 , V_216 -> V_123 ,
F_108 ( V_216 ) ,
F_109 ( V_216 ) ,
0 , 0L , 0 , F_110 ( V_216 ) , 0 , F_111 ( V_216 ) ,
F_112 ( & V_216 -> V_59 ) , V_216 ,
F_112 ( & V_216 -> V_222 ) , V_148 ) ;
}
static int F_113 ( struct V_205 * V_43 , void * V_215 )
{
if ( V_215 == V_214 )
F_107 ( V_43 , L_26 ,
L_27
L_28
L_29 ) ;
else {
struct V_207 * V_208 = V_43 -> V_209 ;
int V_148 ;
F_106 ( V_215 , V_43 , V_208 -> V_210 , & V_148 ) ;
F_107 ( V_43 , L_30 , 127 - V_148 , L_31 ) ;
}
return 0 ;
}
static int F_114 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
return F_115 ( V_223 , V_224 , & V_225 ,
sizeof( struct V_207 ) ) ;
}
static int F_116 ( struct V_1 * V_1 )
{
struct V_226 * V_227 ;
int V_228 = 0 ;
V_227 = F_117 ( V_1 , L_32 , V_229 , & V_230 ) ;
if ( ! V_227 )
V_228 = - V_231 ;
return V_228 ;
}
static void F_118 ( struct V_1 * V_1 )
{
F_119 ( V_1 , L_32 ) ;
}
static int T_9 F_120 ( struct V_1 * V_1 )
{
return F_116 ( V_1 ) ;
}
static void T_10 F_121 ( struct V_1 * V_1 )
{
F_118 ( V_1 ) ;
}
int T_11 F_122 ( void )
{
return F_123 ( & V_232 ) ;
}
void F_124 ( void )
{
F_125 ( & V_232 ) ;
}
void T_11 F_126 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_211 ; V_21 ++ )
F_127 ( & V_6 . V_8 [ V_21 ] , V_21 ) ;
F_128 ( & V_6 . V_20 ) ;
}
