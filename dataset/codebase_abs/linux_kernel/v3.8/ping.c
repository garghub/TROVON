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
struct V_46 * V_46 = F_29 () ;
int V_21 , V_47 , V_48 = V_46 -> V_49 ;
T_4 V_38 , V_39 ;
F_24 ( V_1 , & V_38 , & V_39 ) ;
if ( F_30 ( V_38 , V_45 ) && F_30 ( V_45 , V_39 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_50 ; V_21 ++ ) {
int V_51 = F_31 ( int , V_52 , V_48 ) ;
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ ) {
T_4 V_53 = V_46 -> V_54 [ V_21 ] [ V_47 ] ;
if ( F_30 ( V_38 , V_53 ) && F_30 ( V_53 , V_39 ) )
return 0 ;
}
V_48 -= V_51 ;
}
return - V_55 ;
}
static void F_32 ( struct V_10 * V_11 , long V_56 )
{
F_3 ( L_9 ,
F_6 ( V_11 ) , F_6 ( V_11 ) -> V_24 ) ;
F_3 ( L_10 , V_11 -> V_57 . V_58 ) ;
F_33 ( V_11 ) ;
}
static int F_34 ( struct V_10 * V_11 , struct V_59 * V_60 , int V_61 )
{
struct V_62 * V_63 = (struct V_62 * ) V_60 ;
struct V_16 * V_17 = F_6 ( V_11 ) ;
unsigned short V_64 ;
int V_65 ;
int V_66 ;
if ( V_61 < sizeof( struct V_62 ) )
return - V_67 ;
F_3 ( L_11 ,
V_11 , V_63 -> V_68 . V_69 , F_35 ( V_63 -> V_70 ) ) ;
V_65 = F_36 ( F_8 ( V_11 ) , V_63 -> V_68 . V_69 ) ;
if ( V_63 -> V_68 . V_69 == F_37 ( V_71 ) )
V_65 = V_72 ;
if ( ( V_73 == 0 &&
V_17 -> V_74 == 0 && V_17 -> V_75 == 0 &&
V_65 != V_72 ) ||
V_65 == V_76 ||
V_65 == V_77 )
return - V_78 ;
F_38 ( V_11 ) ;
V_66 = - V_67 ;
if ( V_17 -> V_24 != 0 )
goto V_79;
V_66 = - V_80 ;
V_17 -> V_36 = V_17 -> V_81 = V_63 -> V_68 . V_69 ;
V_64 = F_35 ( V_63 -> V_70 ) ;
if ( F_5 ( V_11 , V_64 ) != 0 ) {
V_17 -> V_81 = V_17 -> V_36 = 0 ;
goto V_79;
}
F_3 ( L_12 ,
( int ) V_17 -> V_24 ,
& V_17 -> V_36 ,
( int ) V_11 -> V_37 ) ;
V_66 = 0 ;
if ( V_17 -> V_36 )
V_11 -> V_82 |= V_83 ;
if ( V_64 )
V_11 -> V_82 |= V_84 ;
V_17 -> V_30 = F_39 ( V_17 -> V_24 ) ;
V_17 -> V_85 = 0 ;
V_17 -> V_86 = 0 ;
F_40 ( V_11 ) ;
V_79:
F_41 ( V_11 ) ;
F_3 ( L_13 , V_66 ) ;
return V_66 ;
}
static inline int F_42 ( int type , int V_87 )
{
if ( type == V_88 && V_87 == 0 )
return 1 ;
return 0 ;
}
void F_43 ( struct V_89 * V_90 , T_1 V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 -> V_40 ;
struct V_94 * V_95 = (struct V_94 * ) ( V_90 -> V_40 + ( V_93 -> V_96 << 2 ) ) ;
struct V_16 * V_16 ;
int type = V_95 -> type ;
int V_87 = V_95 -> V_87 ;
struct V_1 * V_1 = F_44 ( V_90 -> V_97 ) ;
struct V_10 * V_11 ;
int V_98 ;
int V_66 ;
if ( ! F_42 ( V_95 -> type , V_95 -> V_87 ) )
return;
F_3 ( L_14 , type ,
V_87 , F_35 ( V_95 -> V_99 . V_100 . V_101 ) , F_35 ( V_95 -> V_99 . V_100 . V_102 ) ) ;
V_11 = F_21 ( V_1 , V_93 -> V_32 , V_93 -> V_31 ,
F_35 ( V_95 -> V_99 . V_100 . V_101 ) , V_90 -> V_97 -> V_103 ) ;
if ( V_11 == NULL ) {
F_3 ( L_15 ) ;
return;
}
F_3 ( L_16 , V_11 ) ;
V_66 = 0 ;
V_98 = 0 ;
V_16 = F_6 ( V_11 ) ;
switch ( type ) {
default:
case V_104 :
V_66 = V_105 ;
break;
case V_106 :
V_66 = V_107 ;
break;
case V_108 :
V_66 = V_109 ;
V_98 = 1 ;
break;
case V_110 :
if ( V_87 == V_111 ) {
F_45 ( V_90 , V_11 , V_91 ) ;
if ( V_16 -> V_112 != V_113 ) {
V_66 = V_114 ;
V_98 = 1 ;
break;
}
goto V_79;
}
V_66 = V_105 ;
if ( V_87 <= V_115 ) {
V_98 = V_116 [ V_87 ] . V_117 ;
V_66 = V_116 [ V_87 ] . V_118 ;
}
break;
case V_119 :
F_46 ( V_90 , V_11 ) ;
V_66 = V_107 ;
break;
}
if ( ! V_16 -> V_120 ) {
if ( ! V_98 || V_11 -> V_121 != V_122 )
goto V_79;
} else {
F_47 ( V_11 , V_90 , V_66 , 0 ,
V_91 , ( V_123 * ) V_95 ) ;
}
V_11 -> V_124 = V_66 ;
V_11 -> V_125 ( V_11 ) ;
V_79:
F_20 ( V_11 ) ;
}
static int F_48 ( void * V_126 , char * V_127 ,
int V_128 , int V_129 , int V_130 , struct V_89 * V_90 )
{
struct V_131 * V_132 = (struct V_131 * ) V_126 ;
if ( V_128 == 0 ) {
if ( V_129 < sizeof( struct V_94 ) )
F_16 () ;
if ( F_49 ( V_127 + sizeof( struct V_94 ) ,
V_132 -> V_133 , 0 , V_129 - sizeof( struct V_94 ) ,
& V_132 -> V_134 ) )
return - V_135 ;
return 0 ;
}
if ( V_128 < sizeof( struct V_94 ) )
F_16 () ;
if ( F_49
( V_127 , V_132 -> V_133 , V_128 - sizeof( struct V_94 ) ,
V_129 , & V_132 -> V_134 ) )
return - V_135 ;
return 0 ;
}
static int F_50 ( struct V_10 * V_11 , struct V_131 * V_132 ,
struct V_136 * V_137 )
{
struct V_89 * V_90 = F_51 ( & V_11 -> V_138 ) ;
V_132 -> V_134 = F_52 ( ( char * ) & V_132 -> V_95 ,
sizeof( struct V_94 ) , V_132 -> V_134 ) ;
V_132 -> V_95 . V_139 = F_53 ( V_132 -> V_134 ) ;
memcpy ( F_54 ( V_90 ) , & V_132 -> V_95 , sizeof( struct V_94 ) ) ;
V_90 -> V_140 = V_141 ;
return F_55 ( V_11 , V_137 ) ;
}
static int F_56 ( struct V_142 * V_143 , struct V_10 * V_11 , struct V_144 * V_145 ,
T_5 V_146 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
struct V_136 V_137 ;
struct V_16 * V_147 = F_6 ( V_11 ) ;
struct V_148 V_149 ;
struct V_94 V_150 ;
struct V_131 V_132 ;
struct V_151 * V_152 = NULL ;
struct V_153 V_154 ;
int free = 0 ;
T_3 V_31 , V_32 , V_155 ;
V_123 V_156 ;
int V_66 ;
F_3 ( L_17 , V_147 , V_147 -> V_24 ) ;
if ( V_146 > 0xFFFF )
return - V_114 ;
if ( V_145 -> V_157 & V_158 )
return - V_159 ;
if ( F_57 ( ( V_123 * ) & V_150 , V_145 -> V_160 ,
sizeof( struct V_94 ) ) )
return - V_135 ;
if ( ! F_42 ( V_150 . type , V_150 . V_87 ) )
return - V_67 ;
if ( V_145 -> V_161 ) {
struct V_62 * V_162 = (struct V_62 * ) V_145 -> V_161 ;
if ( V_145 -> V_163 < sizeof( * V_162 ) )
return - V_67 ;
if ( V_162 -> V_164 != V_165 )
return - V_67 ;
V_32 = V_162 -> V_68 . V_69 ;
} else {
if ( V_11 -> V_121 != V_122 )
return - V_166 ;
V_32 = V_147 -> V_85 ;
}
V_149 . V_63 = V_147 -> V_81 ;
V_149 . V_167 = NULL ;
V_149 . V_168 = V_11 -> V_37 ;
V_149 . V_169 = 0 ;
V_66 = F_58 ( V_11 , & V_149 . V_169 ) ;
if ( V_66 )
return V_66 ;
if ( V_145 -> V_170 ) {
V_66 = F_59 ( F_8 ( V_11 ) , V_145 , & V_149 ) ;
if ( V_66 )
return V_66 ;
if ( V_149 . V_167 )
free = 1 ;
}
if ( ! V_149 . V_167 ) {
struct V_171 * V_172 ;
F_60 () ;
V_172 = F_61 ( V_147 -> V_172 ) ;
if ( V_172 ) {
memcpy ( & V_154 , V_172 ,
sizeof( * V_172 ) + V_172 -> V_167 . V_173 ) ;
V_149 . V_167 = & V_154 . V_167 ;
}
F_62 () ;
}
V_31 = V_149 . V_63 ;
V_149 . V_63 = V_155 = V_32 ;
if ( V_149 . V_167 && V_149 . V_167 -> V_167 . V_174 ) {
if ( ! V_32 )
return - V_67 ;
V_155 = V_149 . V_167 -> V_167 . V_155 ;
}
V_156 = F_63 ( V_147 -> V_156 ) ;
if ( F_64 ( V_11 , V_175 ) ||
( V_145 -> V_157 & V_176 ) ||
( V_149 . V_167 && V_149 . V_167 -> V_167 . V_177 ) ) {
V_156 |= V_178 ;
}
if ( F_65 ( V_32 ) ) {
if ( ! V_149 . V_168 )
V_149 . V_168 = V_147 -> V_179 ;
if ( ! V_31 )
V_31 = V_147 -> V_180 ;
} else if ( ! V_149 . V_168 )
V_149 . V_168 = V_147 -> V_181 ;
F_66 ( & V_137 , V_149 . V_168 , V_11 -> V_182 , V_156 ,
V_183 , V_11 -> V_184 ,
F_67 ( V_11 ) , V_155 , V_31 , 0 , 0 ) ;
F_68 ( V_11 , F_69 ( & V_137 ) ) ;
V_152 = F_70 ( V_1 , & V_137 , V_11 ) ;
if ( F_71 ( V_152 ) ) {
V_66 = F_72 ( V_152 ) ;
V_152 = NULL ;
if ( V_66 == - V_185 )
F_73 ( V_1 , V_186 ) ;
goto V_79;
}
V_66 = - V_55 ;
if ( ( V_152 -> V_187 & V_188 ) &&
! F_64 ( V_11 , V_189 ) )
goto V_79;
if ( V_145 -> V_157 & V_190 )
goto V_191;
V_192:
if ( ! V_149 . V_63 )
V_149 . V_63 = V_137 . V_32 ;
F_38 ( V_11 ) ;
V_132 . V_95 . type = V_150 . type ;
V_132 . V_95 . V_87 = V_150 . V_87 ;
V_132 . V_95 . V_139 = 0 ;
V_132 . V_95 . V_99 . V_100 . V_101 = V_147 -> V_30 ;
V_132 . V_95 . V_99 . V_100 . V_102 = V_150 . V_99 . V_100 . V_102 ;
V_132 . V_133 = V_145 -> V_160 ;
V_132 . V_134 = 0 ;
V_66 = F_74 ( V_11 , & V_137 , F_48 , & V_132 , V_146 ,
0 , & V_149 , & V_152 , V_145 -> V_157 ) ;
if ( V_66 )
F_75 ( V_11 ) ;
else
V_66 = F_50 ( V_11 , & V_132 , & V_137 ) ;
F_41 ( V_11 ) ;
V_79:
F_76 ( V_152 ) ;
if ( free )
F_77 ( V_149 . V_167 ) ;
if ( ! V_66 ) {
F_78 ( F_8 ( V_11 ) , V_150 . type ) ;
return V_146 ;
}
return V_66 ;
V_191:
F_79 ( & V_152 -> V_193 ) ;
if ( ! ( V_145 -> V_157 & V_194 ) || V_146 )
goto V_192;
V_66 = 0 ;
goto V_79;
}
static int F_80 ( struct V_142 * V_143 , struct V_10 * V_11 , struct V_144 * V_145 ,
T_5 V_146 , int V_195 , int V_196 , int * V_61 )
{
struct V_16 * V_17 = F_6 ( V_11 ) ;
struct V_62 * sin = (struct V_62 * ) V_145 -> V_161 ;
struct V_89 * V_90 ;
int V_197 , V_66 ;
F_3 ( L_18 , V_17 , V_17 -> V_24 ) ;
V_66 = - V_159 ;
if ( V_196 & V_158 )
goto V_79;
if ( V_61 )
* V_61 = sizeof( * sin ) ;
if ( V_196 & V_198 )
return F_81 ( V_11 , V_145 , V_146 ) ;
V_90 = F_82 ( V_11 , V_196 , V_195 , & V_66 ) ;
if ( ! V_90 )
goto V_79;
V_197 = V_90 -> V_146 ;
if ( V_197 > V_146 ) {
V_145 -> V_157 |= V_199 ;
V_197 = V_146 ;
}
V_66 = F_83 ( V_90 , 0 , V_145 -> V_160 , V_197 ) ;
if ( V_66 )
goto V_200;
F_84 ( V_145 , V_11 , V_90 ) ;
if ( sin ) {
sin -> V_164 = V_165 ;
sin -> V_70 = 0 ;
sin -> V_68 . V_69 = F_85 ( V_90 ) -> V_31 ;
memset ( sin -> V_201 , 0 , sizeof( sin -> V_201 ) ) ;
}
if ( V_17 -> V_202 )
F_86 ( V_145 , V_90 ) ;
V_66 = V_197 ;
V_200:
F_87 ( V_11 , V_90 ) ;
V_79:
F_3 ( L_19 , V_66 ) ;
return V_66 ;
}
static int F_88 ( struct V_10 * V_11 , struct V_89 * V_90 )
{
F_3 ( L_20 ,
F_6 ( V_11 ) , F_6 ( V_11 ) -> V_24 , V_90 ) ;
if ( F_89 ( V_11 , V_90 ) < 0 ) {
F_90 ( V_90 ) ;
F_3 ( L_21 ) ;
return - 1 ;
}
return 0 ;
}
void F_91 ( struct V_89 * V_90 )
{
struct V_10 * V_11 ;
struct V_1 * V_1 = F_44 ( V_90 -> V_97 ) ;
struct V_92 * V_93 = F_85 ( V_90 ) ;
struct V_94 * V_95 = F_54 ( V_90 ) ;
T_3 V_31 = V_93 -> V_31 ;
T_3 V_32 = V_93 -> V_32 ;
F_3 ( L_22 ,
V_90 , F_35 ( V_95 -> V_99 . V_100 . V_101 ) , F_35 ( V_95 -> V_99 . V_100 . V_102 ) ) ;
F_92 ( V_90 , V_90 -> V_40 - ( V_123 * ) V_95 ) ;
V_11 = F_21 ( V_1 , V_31 , V_32 , F_35 ( V_95 -> V_99 . V_100 . V_101 ) ,
V_90 -> V_97 -> V_103 ) ;
if ( V_11 != NULL ) {
F_3 ( L_23 , V_11 ) ;
F_88 ( V_11 , F_93 ( V_90 ) ) ;
F_20 ( V_11 ) ;
return;
}
F_3 ( L_15 ) ;
}
static struct V_10 * F_94 ( struct V_203 * V_43 , int V_204 )
{
struct V_10 * V_11 ;
struct V_205 * V_206 = V_43 -> V_207 ;
struct V_1 * V_1 = F_95 ( V_43 ) ;
for ( V_206 -> V_208 = V_204 ; V_206 -> V_208 < V_209 ;
++ V_206 -> V_208 ) {
struct V_13 * V_14 ;
struct V_5 * V_34 ;
V_34 = & V_6 . V_8 [ V_206 -> V_208 ] ;
if ( F_96 ( V_34 ) )
continue;
F_97 (sk, node, hslot) {
if ( F_98 ( F_8 ( V_11 ) , V_1 ) )
goto V_210;
}
}
V_11 = NULL ;
V_210:
return V_11 ;
}
static struct V_10 * F_99 ( struct V_203 * V_43 , struct V_10 * V_11 )
{
struct V_205 * V_206 = V_43 -> V_207 ;
struct V_1 * V_1 = F_95 ( V_43 ) ;
do {
V_11 = F_100 ( V_11 ) ;
} while ( V_11 && ( ! F_98 ( F_8 ( V_11 ) , V_1 ) ) );
if ( ! V_11 )
return F_94 ( V_43 , V_206 -> V_208 + 1 ) ;
return V_11 ;
}
static struct V_10 * F_101 ( struct V_203 * V_43 , T_6 V_211 )
{
struct V_10 * V_11 = F_94 ( V_43 , 0 ) ;
if ( V_11 )
while ( V_211 && ( V_11 = F_99 ( V_43 , V_11 ) ) != NULL )
-- V_211 ;
return V_211 ? NULL : V_11 ;
}
static void * F_102 ( struct V_203 * V_43 , T_6 * V_211 )
{
struct V_205 * V_206 = V_43 -> V_207 ;
V_206 -> V_208 = 0 ;
F_22 ( & V_6 . V_20 ) ;
return * V_211 ? F_101 ( V_43 , * V_211 - 1 ) : V_212 ;
}
static void * F_103 ( struct V_203 * V_43 , void * V_213 , T_6 * V_211 )
{
struct V_10 * V_11 ;
if ( V_213 == V_212 )
V_11 = F_101 ( V_43 , 0 ) ;
else
V_11 = F_99 ( V_43 , V_213 ) ;
++ * V_211 ;
return V_11 ;
}
static void F_104 ( struct V_203 * V_43 , void * V_213 )
{
F_23 ( & V_6 . V_20 ) ;
}
static void F_105 ( struct V_10 * V_214 , struct V_203 * V_215 ,
int V_208 , int * V_146 )
{
struct V_16 * V_147 = F_6 ( V_214 ) ;
T_3 V_216 = V_147 -> V_85 ;
T_3 V_217 = V_147 -> V_36 ;
T_7 V_218 = F_35 ( V_147 -> V_86 ) ;
T_7 V_219 = F_35 ( V_147 -> V_30 ) ;
F_106 ( V_215 , L_24
L_25 ,
V_208 , V_217 , V_219 , V_216 , V_218 , V_214 -> V_121 ,
F_107 ( V_214 ) ,
F_108 ( V_214 ) ,
0 , 0L , 0 ,
F_109 ( F_110 ( V_215 ) , F_111 ( V_214 ) ) ,
0 , F_112 ( V_214 ) ,
F_113 ( & V_214 -> V_57 ) , V_214 ,
F_113 ( & V_214 -> V_220 ) , V_146 ) ;
}
static int F_114 ( struct V_203 * V_43 , void * V_213 )
{
if ( V_213 == V_212 )
F_106 ( V_43 , L_26 ,
L_27
L_28
L_29 ) ;
else {
struct V_205 * V_206 = V_43 -> V_207 ;
int V_146 ;
F_105 ( V_213 , V_43 , V_206 -> V_208 , & V_146 ) ;
F_106 ( V_43 , L_30 , 127 - V_146 , L_31 ) ;
}
return 0 ;
}
static int F_115 ( struct V_221 * V_221 , struct V_222 * V_222 )
{
return F_116 ( V_221 , V_222 , & V_223 ,
sizeof( struct V_205 ) ) ;
}
static int F_117 ( struct V_1 * V_1 )
{
struct V_224 * V_225 ;
int V_226 = 0 ;
V_225 = F_118 ( V_1 , L_32 , V_227 , & V_228 ) ;
if ( ! V_225 )
V_226 = - V_229 ;
return V_226 ;
}
static void F_119 ( struct V_1 * V_1 )
{
F_120 ( V_1 , L_32 ) ;
}
static int T_8 F_121 ( struct V_1 * V_1 )
{
return F_117 ( V_1 ) ;
}
static void T_9 F_122 ( struct V_1 * V_1 )
{
F_119 ( V_1 ) ;
}
int T_10 F_123 ( void )
{
return F_124 ( & V_230 ) ;
}
void F_125 ( void )
{
F_126 ( & V_230 ) ;
}
void T_10 F_127 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_209 ; V_21 ++ )
F_128 ( & V_6 . V_8 [ V_21 ] , V_21 ) ;
F_129 ( & V_6 . V_20 ) ;
}
