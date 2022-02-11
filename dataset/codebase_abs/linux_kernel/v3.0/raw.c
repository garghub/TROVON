void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
struct V_7 * V_8 ;
V_8 = & V_4 -> V_9 [ F_2 ( V_2 ) -> V_10 & ( V_11 - 1 ) ] ;
F_3 ( & V_4 -> V_12 ) ;
F_4 ( V_2 , V_8 ) ;
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 . V_6 ;
F_3 ( & V_4 -> V_12 ) ;
if ( F_9 ( V_2 ) )
F_5 ( F_6 ( V_2 ) , V_2 -> V_5 , - 1 ) ;
F_7 ( & V_4 -> V_12 ) ;
}
static struct V_1 * F_10 ( struct V_13 * V_13 , struct V_1 * V_2 ,
unsigned short V_14 , T_1 V_15 , T_1 V_16 , int V_17 )
{
struct V_18 * V_19 ;
F_11 (sk, node) {
struct V_20 * V_21 = F_2 ( V_2 ) ;
if ( F_12 ( F_6 ( V_2 ) , V_13 ) && V_21 -> V_10 == V_14 &&
! ( V_21 -> V_22 && V_21 -> V_22 != V_15 ) &&
! ( V_21 -> V_23 && V_21 -> V_23 != V_16 ) &&
! ( V_2 -> V_24 && V_2 -> V_24 != V_17 ) )
goto V_25;
}
V_2 = NULL ;
V_25:
return V_2 ;
}
static T_2 int F_13 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int type ;
if ( ! F_14 ( V_27 , sizeof( struct V_28 ) ) )
return 1 ;
type = F_15 ( V_27 ) -> type ;
if ( type < 32 ) {
T_3 V_29 = F_16 ( V_2 ) -> V_30 . V_29 ;
return ( ( 1 << type ) & V_29 ) != 0 ;
}
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , const struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_34 = 0 ;
struct V_13 * V_13 ;
F_18 ( & V_35 . V_12 ) ;
V_8 = & V_35 . V_9 [ V_33 ] ;
if ( F_19 ( V_8 ) )
goto V_36;
V_13 = F_20 ( V_27 -> V_37 ) ;
V_2 = F_10 ( V_13 , F_21 ( V_8 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_27 -> V_37 -> V_41 ) ;
while ( V_2 ) {
V_34 = 1 ;
if ( V_32 -> V_38 != V_42 || ! F_13 ( V_2 , V_27 ) ) {
struct V_26 * V_43 = F_22 ( V_27 , V_44 ) ;
if ( V_43 )
F_23 ( V_2 , V_43 ) ;
}
V_2 = F_10 ( V_13 , F_24 ( V_2 ) , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_27 -> V_37 -> V_41 ) ;
}
V_36:
F_25 ( & V_35 . V_12 ) ;
return V_34 ;
}
int F_26 ( struct V_26 * V_27 , int V_38 )
{
int V_33 ;
struct V_1 * F_16 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 && ! F_17 ( V_27 , F_28 ( V_27 ) , V_33 ) )
F_16 = NULL ;
return F_16 != NULL ;
}
static void F_29 ( struct V_1 * V_2 , struct V_26 * V_27 , T_4 V_45 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
const int type = F_15 ( V_27 ) -> type ;
const int V_46 = F_15 ( V_27 ) -> V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
if ( ! V_21 -> V_49 && V_2 -> V_50 != V_51 )
return;
switch ( type ) {
default:
case V_52 :
V_47 = V_53 ;
break;
case V_54 :
return;
case V_55 :
V_47 = V_56 ;
V_48 = 1 ;
break;
case V_57 :
V_47 = V_53 ;
if ( V_46 > V_58 )
break;
V_47 = V_59 [ V_46 ] . V_60 ;
V_48 = V_59 [ V_46 ] . V_61 ;
if ( V_46 == V_62 ) {
V_48 = V_21 -> V_63 != V_64 ;
V_47 = V_65 ;
}
}
if ( V_21 -> V_49 ) {
const struct V_31 * V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
T_5 * V_66 = V_27 -> V_29 + ( V_32 -> V_67 << 2 ) ;
if ( V_21 -> V_68 )
V_66 = V_27 -> V_29 ;
F_30 ( V_2 , V_27 , V_47 , 0 , V_45 , V_66 ) ;
}
if ( V_21 -> V_49 || V_48 ) {
V_2 -> V_69 = V_47 ;
V_2 -> V_70 ( V_2 ) ;
}
}
void F_31 ( struct V_26 * V_27 , int V_38 , T_4 V_45 )
{
int V_33 ;
struct V_1 * F_16 ;
const struct V_31 * V_32 ;
struct V_13 * V_13 ;
V_33 = V_38 & ( V_11 - 1 ) ;
F_18 ( & V_35 . V_12 ) ;
F_16 = F_27 ( & V_35 . V_9 [ V_33 ] ) ;
if ( F_16 != NULL ) {
V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
V_13 = F_20 ( V_27 -> V_37 ) ;
while ( ( F_16 = F_10 ( V_13 , F_16 , V_38 ,
V_32 -> V_40 , V_32 -> V_39 ,
V_27 -> V_37 -> V_41 ) ) != NULL ) {
F_29 ( F_16 , V_27 , V_45 ) ;
F_16 = F_24 ( F_16 ) ;
V_32 = ( const struct V_31 * ) V_27 -> V_29 ;
}
}
F_25 ( & V_35 . V_12 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( F_33 ( V_2 , V_27 ) < 0 ) {
F_34 ( V_27 ) ;
return V_71 ;
}
return V_72 ;
}
int F_23 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( ! F_35 ( V_2 , V_73 , V_27 ) ) {
F_36 ( & V_2 -> V_74 ) ;
F_34 ( V_27 ) ;
return V_71 ;
}
F_37 ( V_27 ) ;
F_38 ( V_27 , V_27 -> V_29 - F_39 ( V_27 ) ) ;
F_32 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_75 * V_76 ,
void * V_77 , T_6 V_78 ,
struct V_79 * * V_80 ,
unsigned int V_81 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
struct V_31 * V_32 ;
struct V_26 * V_27 ;
unsigned int V_82 ;
int V_47 ;
struct V_79 * V_83 = * V_80 ;
if ( V_78 > V_83 -> V_84 . V_37 -> V_85 ) {
F_41 ( V_2 , V_65 , V_76 -> V_40 , V_21 -> V_86 ,
V_83 -> V_84 . V_37 -> V_85 ) ;
return - V_65 ;
}
if ( V_81 & V_87 )
goto V_36;
V_27 = F_42 ( V_2 ,
V_78 + F_43 ( V_83 -> V_84 . V_37 ) + 15 ,
V_81 & V_88 , & V_47 ) ;
if ( V_27 == NULL )
goto error;
F_44 ( V_27 , F_45 ( V_83 -> V_84 . V_37 ) ) ;
V_27 -> V_89 = V_2 -> V_90 ;
V_27 -> V_91 = V_2 -> V_92 ;
F_46 ( V_27 , & V_83 -> V_84 ) ;
* V_80 = NULL ;
F_47 ( V_27 ) ;
V_32 = F_28 ( V_27 ) ;
F_48 ( V_27 , V_78 ) ;
V_27 -> V_93 = V_94 ;
V_27 -> V_95 = V_27 -> V_96 ;
V_47 = - V_97 ;
if ( F_49 ( ( void * ) V_32 , V_77 , 0 , V_78 ) )
goto V_98;
V_82 = V_32 -> V_67 * 4 ;
V_47 = - V_99 ;
if ( V_82 > V_78 )
goto V_98;
if ( V_82 >= sizeof( * V_32 ) ) {
if ( ! V_32 -> V_39 )
V_32 -> V_39 = V_76 -> V_39 ;
V_32 -> V_100 = 0 ;
V_32 -> V_101 = F_50 ( V_78 ) ;
if ( ! V_32 -> V_102 )
F_51 ( V_32 , & V_83 -> V_84 , NULL ) ;
V_32 -> V_100 = F_52 ( ( unsigned char * ) V_32 , V_32 -> V_67 ) ;
}
if ( V_32 -> V_38 == V_42 )
F_53 ( V_13 , ( (struct V_28 * )
F_54 ( V_27 ) ) -> type ) ;
V_47 = F_55 ( V_103 , V_104 , V_27 , NULL ,
V_83 -> V_84 . V_37 , V_105 ) ;
if ( V_47 > 0 )
V_47 = F_56 ( V_47 ) ;
if ( V_47 )
goto error;
V_36:
return 0 ;
V_98:
F_34 ( V_27 ) ;
error:
F_57 ( V_13 , V_106 ) ;
if ( V_47 == - V_107 && ! V_21 -> V_49 )
V_47 = 0 ;
return V_47 ;
}
static int F_58 ( struct V_75 * V_76 , struct V_108 * V_109 )
{
struct V_110 * V_111 ;
T_5 T_7 * type = NULL ;
T_5 T_7 * V_46 = NULL ;
int V_112 = 0 ;
unsigned int V_113 ;
if ( ! V_109 -> V_114 )
return 0 ;
for ( V_113 = 0 ; V_113 < V_109 -> V_115 ; V_113 ++ ) {
V_111 = & V_109 -> V_114 [ V_113 ] ;
if ( ! V_111 )
continue;
switch ( V_76 -> V_116 ) {
case V_42 :
if ( V_111 -> V_117 && V_111 -> V_118 < 1 )
break;
if ( ! type ) {
type = V_111 -> V_117 ;
if ( V_111 -> V_118 > 1 )
V_46 = type + 1 ;
} else if ( ! V_46 )
V_46 = V_111 -> V_117 ;
if ( type && V_46 ) {
if ( F_59 ( V_76 -> V_119 , type ) ||
F_59 ( V_76 -> V_120 , V_46 ) )
return - V_97 ;
V_112 = 1 ;
}
break;
default:
V_112 = 1 ;
break;
}
if ( V_112 )
break;
}
return 0 ;
}
static int F_60 ( struct V_121 * V_122 , struct V_1 * V_2 , struct V_108 * V_109 ,
T_6 V_123 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_124 V_125 ;
struct V_79 * V_83 = NULL ;
struct V_75 V_76 ;
int free = 0 ;
T_1 V_40 ;
T_1 V_39 ;
T_5 V_126 ;
int V_47 ;
struct V_127 V_128 ;
V_47 = - V_65 ;
if ( V_123 > 0xFFFF )
goto V_36;
V_47 = - V_129 ;
if ( V_109 -> V_130 & V_131 )
goto V_36;
if ( V_109 -> V_132 ) {
struct V_133 * V_134 = (struct V_133 * ) V_109 -> V_135 ;
V_47 = - V_99 ;
if ( V_109 -> V_132 < sizeof( * V_134 ) )
goto V_36;
if ( V_134 -> V_136 != V_137 ) {
static int V_138 ;
if ( ! V_138 ++ )
F_61 ( V_139 L_1
L_2 ,
V_140 -> V_141 ) ;
V_47 = - V_142 ;
if ( V_134 -> V_136 )
goto V_36;
}
V_40 = V_134 -> V_143 . V_144 ;
} else {
V_47 = - V_145 ;
if ( V_2 -> V_50 != V_51 )
goto V_36;
V_40 = V_21 -> V_22 ;
}
V_125 . V_146 = V_21 -> V_147 ;
V_125 . V_148 = NULL ;
V_125 . V_149 = 0 ;
V_125 . V_150 = V_2 -> V_24 ;
if ( V_109 -> V_151 ) {
V_47 = F_62 ( F_6 ( V_2 ) , V_109 , & V_125 ) ;
if ( V_47 )
goto V_36;
if ( V_125 . V_148 )
free = 1 ;
}
V_39 = V_125 . V_146 ;
V_125 . V_146 = V_40 ;
if ( ! V_125 . V_148 ) {
struct V_152 * V_153 ;
F_63 () ;
V_153 = F_64 ( V_21 -> V_153 ) ;
if ( V_153 ) {
memcpy ( & V_128 , V_153 ,
sizeof( * V_153 ) + V_153 -> V_148 . V_154 ) ;
V_125 . V_148 = & V_128 . V_148 ;
}
F_65 () ;
}
if ( V_125 . V_148 ) {
V_47 = - V_99 ;
if ( V_21 -> V_68 )
goto V_155;
if ( V_125 . V_148 -> V_148 . V_156 ) {
if ( ! V_40 )
goto V_155;
V_40 = V_125 . V_148 -> V_148 . V_157 ;
}
}
V_126 = F_66 ( V_2 ) ;
if ( V_109 -> V_130 & V_158 )
V_126 |= V_159 ;
if ( F_67 ( V_40 ) ) {
if ( ! V_125 . V_150 )
V_125 . V_150 = V_21 -> V_160 ;
if ( ! V_39 )
V_39 = V_21 -> V_161 ;
}
F_68 ( & V_76 , V_125 . V_150 , V_2 -> V_92 , V_126 ,
V_162 ,
V_21 -> V_68 ? V_163 : V_2 -> V_164 ,
V_165 , V_40 , V_39 , 0 , 0 ) ;
if ( ! V_21 -> V_68 ) {
V_47 = F_58 ( & V_76 , V_109 ) ;
if ( V_47 )
goto V_155;
}
F_69 ( V_2 , F_70 ( & V_76 ) ) ;
V_83 = F_71 ( F_6 ( V_2 ) , & V_76 , V_2 ) ;
if ( F_72 ( V_83 ) ) {
V_47 = F_73 ( V_83 ) ;
V_83 = NULL ;
goto V_155;
}
V_47 = - V_166 ;
if ( V_83 -> V_167 & V_168 && ! F_74 ( V_2 , V_169 ) )
goto V_155;
if ( V_109 -> V_130 & V_170 )
goto V_171;
V_172:
if ( V_21 -> V_68 )
V_47 = F_40 ( V_2 , & V_76 , V_109 -> V_114 , V_123 ,
& V_83 , V_109 -> V_130 ) ;
else {
if ( ! V_125 . V_146 )
V_125 . V_146 = V_76 . V_40 ;
F_75 ( V_2 ) ;
V_47 = F_76 ( V_2 , & V_76 , V_173 ,
V_109 -> V_114 , V_123 , 0 ,
& V_125 , & V_83 , V_109 -> V_130 ) ;
if ( V_47 )
F_77 ( V_2 ) ;
else if ( ! ( V_109 -> V_130 & V_174 ) ) {
V_47 = F_78 ( V_2 , & V_76 ) ;
if ( V_47 == - V_107 && ! V_21 -> V_49 )
V_47 = 0 ;
}
F_79 ( V_2 ) ;
}
V_155:
if ( free )
F_80 ( V_125 . V_148 ) ;
F_81 ( V_83 ) ;
V_36:
if ( V_47 < 0 )
return V_47 ;
return V_123 ;
V_171:
F_82 ( & V_83 -> V_84 ) ;
if ( ! ( V_109 -> V_130 & V_87 ) || V_123 )
goto V_172;
V_47 = 0 ;
goto V_155;
}
static void F_83 ( struct V_1 * V_2 , long V_175 )
{
F_84 ( V_2 , 0 , NULL ) ;
F_85 ( V_2 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
F_77 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static int F_87 ( struct V_1 * V_2 , struct V_176 * V_177 , int V_178 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
struct V_133 * V_146 = (struct V_133 * ) V_177 ;
int V_179 = - V_99 ;
int V_180 ;
if ( V_2 -> V_50 != V_181 || V_178 < sizeof( struct V_133 ) )
goto V_36;
V_180 = F_88 ( F_6 ( V_2 ) , V_146 -> V_143 . V_144 ) ;
V_179 = - V_182 ;
if ( V_146 -> V_143 . V_144 && V_180 != V_183 &&
V_180 != V_184 && V_180 != V_185 )
goto V_36;
V_21 -> V_23 = V_21 -> V_147 = V_146 -> V_143 . V_144 ;
if ( V_180 == V_184 || V_180 == V_185 )
V_21 -> V_147 = 0 ;
F_89 ( V_2 ) ;
V_179 = 0 ;
V_36: return V_179 ;
}
static int F_90 ( struct V_121 * V_122 , struct V_1 * V_2 , struct V_108 * V_109 ,
T_6 V_123 , int V_186 , int V_81 , int * V_178 )
{
struct V_20 * V_21 = F_2 ( V_2 ) ;
T_6 V_187 = 0 ;
int V_47 = - V_129 ;
struct V_133 * sin = (struct V_133 * ) V_109 -> V_135 ;
struct V_26 * V_27 ;
if ( V_81 & V_131 )
goto V_36;
if ( V_178 )
* V_178 = sizeof( * sin ) ;
if ( V_81 & V_188 ) {
V_47 = F_91 ( V_2 , V_109 , V_123 ) ;
goto V_36;
}
V_27 = F_92 ( V_2 , V_81 , V_186 , & V_47 ) ;
if ( ! V_27 )
goto V_36;
V_187 = V_27 -> V_123 ;
if ( V_123 < V_187 ) {
V_109 -> V_130 |= V_189 ;
V_187 = V_123 ;
}
V_47 = F_93 ( V_27 , 0 , V_109 -> V_114 , V_187 ) ;
if ( V_47 )
goto V_155;
F_94 ( V_109 , V_2 , V_27 ) ;
if ( sin ) {
sin -> V_136 = V_137 ;
sin -> V_143 . V_144 = F_28 ( V_27 ) -> V_39 ;
sin -> V_190 = 0 ;
memset ( & sin -> V_191 , 0 , sizeof( sin -> V_191 ) ) ;
}
if ( V_21 -> V_192 )
F_95 ( V_109 , V_27 ) ;
if ( V_81 & V_189 )
V_187 = V_27 -> V_123 ;
V_155:
F_96 ( V_2 , V_27 ) ;
V_36:
if ( V_47 )
return V_47 ;
return V_187 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_193 * V_194 = F_16 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_10 == V_42 )
memset ( & V_194 -> V_30 , 0 , sizeof( V_194 -> V_30 ) ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , char T_7 * V_195 , int V_154 )
{
if ( V_154 > sizeof( struct F_13 ) )
V_154 = sizeof( struct F_13 ) ;
if ( F_99 ( & F_16 ( V_2 ) -> V_30 , V_195 , V_154 ) )
return - V_97 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , char T_7 * V_195 , int T_7 * V_154 )
{
int V_123 , V_179 = - V_97 ;
if ( F_59 ( V_123 , V_154 ) )
goto V_36;
V_179 = - V_99 ;
if ( V_123 < 0 )
goto V_36;
if ( V_123 > sizeof( struct F_13 ) )
V_123 = sizeof( struct F_13 ) ;
V_179 = - V_97 ;
if ( F_101 ( V_123 , V_154 ) ||
F_102 ( V_195 , & F_16 ( V_2 ) -> V_30 , V_123 ) )
goto V_36;
V_179 = 0 ;
V_36: return V_179 ;
}
static int F_103 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , unsigned int V_154 )
{
if ( V_197 == V_198 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_129 ;
else
return F_98 ( V_2 , V_195 , V_154 ) ;
}
return - V_199 ;
}
static int F_104 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , unsigned int V_154 )
{
if ( V_196 != V_200 )
return F_105 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
return F_103 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
}
static int F_106 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , unsigned int V_154 )
{
if ( V_196 != V_200 )
return F_107 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
return F_103 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
}
static int F_108 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , int T_7 * V_154 )
{
if ( V_197 == V_198 ) {
if ( F_2 ( V_2 ) -> V_10 != V_42 )
return - V_129 ;
else
return F_100 ( V_2 , V_195 , V_154 ) ;
}
return - V_199 ;
}
static int F_109 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , int T_7 * V_154 )
{
if ( V_196 != V_200 )
return F_110 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
return F_108 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
}
static int F_111 ( struct V_1 * V_2 , int V_196 , int V_197 ,
char T_7 * V_195 , int T_7 * V_154 )
{
if ( V_196 != V_200 )
return F_112 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
return F_108 ( V_2 , V_196 , V_197 , V_195 , V_154 ) ;
}
static int F_113 ( struct V_1 * V_2 , int V_201 , unsigned long V_202 )
{
switch ( V_201 ) {
case V_203 : {
int V_204 = F_114 ( V_2 ) ;
return F_101 ( V_204 , ( int T_7 * ) V_202 ) ;
}
case V_205 : {
struct V_26 * V_27 ;
int V_204 = 0 ;
F_115 ( & V_2 -> V_206 . V_12 ) ;
V_27 = F_116 ( & V_2 -> V_206 ) ;
if ( V_27 != NULL )
V_204 = V_27 -> V_123 ;
F_117 ( & V_2 -> V_206 . V_12 ) ;
return F_101 ( V_204 , ( int T_7 * ) V_202 ) ;
}
default:
#ifdef F_118
return F_119 ( V_2 , V_201 , ( void T_7 * ) V_202 ) ;
#else
return - V_207 ;
#endif
}
}
static int F_120 ( struct V_1 * V_2 , unsigned int V_201 , unsigned long V_202 )
{
switch ( V_201 ) {
case V_203 :
case V_205 :
return - V_207 ;
default:
#ifdef F_118
return F_121 ( V_2 , V_201 , F_122 ( V_202 ) ) ;
#else
return - V_207 ;
#endif
}
}
static struct V_1 * F_123 ( struct V_208 * V_209 )
{
struct V_1 * V_2 ;
struct V_210 * V_211 = F_124 ( V_209 ) ;
for ( V_211 -> V_212 = 0 ; V_211 -> V_212 < V_11 ;
++ V_211 -> V_212 ) {
struct V_18 * V_19 ;
F_125 (sk, node, &state->h->ht[state->bucket])
if ( F_6 ( V_2 ) == F_126 ( V_209 ) )
goto V_25;
}
V_2 = NULL ;
V_25:
return V_2 ;
}
static struct V_1 * F_127 ( struct V_208 * V_209 , struct V_1 * V_2 )
{
struct V_210 * V_211 = F_124 ( V_209 ) ;
do {
V_2 = F_24 ( V_2 ) ;
V_213:
;
} while ( V_2 && F_6 ( V_2 ) != F_126 ( V_209 ) );
if ( ! V_2 && ++ V_211 -> V_212 < V_11 ) {
V_2 = F_27 ( & V_211 -> V_4 -> V_9 [ V_211 -> V_212 ] ) ;
goto V_213;
}
return V_2 ;
}
static struct V_1 * F_128 ( struct V_208 * V_209 , T_8 V_214 )
{
struct V_1 * V_2 = F_123 ( V_209 ) ;
if ( V_2 )
while ( V_214 && ( V_2 = F_127 ( V_209 , V_2 ) ) != NULL )
-- V_214 ;
return V_214 ? NULL : V_2 ;
}
void * F_129 ( struct V_208 * V_209 , T_8 * V_214 )
{
struct V_210 * V_211 = F_124 ( V_209 ) ;
F_18 ( & V_211 -> V_4 -> V_12 ) ;
return * V_214 ? F_128 ( V_209 , * V_214 - 1 ) : V_215 ;
}
void * F_130 ( struct V_208 * V_209 , void * V_216 , T_8 * V_214 )
{
struct V_1 * V_2 ;
if ( V_216 == V_215 )
V_2 = F_123 ( V_209 ) ;
else
V_2 = F_127 ( V_209 , V_216 ) ;
++ * V_214 ;
return V_2 ;
}
void F_131 ( struct V_208 * V_209 , void * V_216 )
{
struct V_210 * V_211 = F_124 ( V_209 ) ;
F_25 ( & V_211 -> V_4 -> V_12 ) ;
}
static void F_132 ( struct V_208 * V_209 , struct V_1 * V_217 , int V_113 )
{
struct V_20 * V_21 = F_2 ( V_217 ) ;
T_1 V_218 = V_21 -> V_22 ,
V_219 = V_21 -> V_23 ;
T_9 V_220 = 0 ,
V_221 = V_21 -> V_10 ;
F_133 ( V_209 , L_3
L_4 ,
V_113 , V_219 , V_221 , V_218 , V_220 , V_217 -> V_50 ,
F_114 ( V_217 ) ,
F_134 ( V_217 ) ,
0 , 0L , 0 , F_135 ( V_217 ) , 0 , F_136 ( V_217 ) ,
F_137 ( & V_217 -> V_222 ) , V_217 , F_137 ( & V_217 -> V_74 ) ) ;
}
static int F_138 ( struct V_208 * V_209 , void * V_216 )
{
if ( V_216 == V_215 )
F_133 ( V_209 , L_5
L_6
L_7 ) ;
else
F_132 ( V_209 , V_216 , F_124 ( V_209 ) -> V_212 ) ;
return 0 ;
}
int F_139 ( struct V_223 * V_224 , struct V_225 * V_225 ,
struct V_3 * V_4 , const struct V_226 * V_227 )
{
int V_47 ;
struct V_210 * V_113 ;
V_47 = F_140 ( V_224 , V_225 , V_227 , sizeof( struct V_210 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_113 = F_124 ( (struct V_208 * ) V_225 -> V_228 ) ;
V_113 -> V_4 = V_4 ;
return 0 ;
}
static int F_141 ( struct V_223 * V_223 , struct V_225 * V_225 )
{
return F_139 ( V_223 , V_225 , & V_35 , & V_229 ) ;
}
static T_10 int F_142 ( struct V_13 * V_13 )
{
if ( ! F_143 ( V_13 , L_8 , V_230 , & V_231 ) )
return - V_232 ;
return 0 ;
}
static T_11 void F_144 ( struct V_13 * V_13 )
{
F_145 ( V_13 , L_8 ) ;
}
int T_12 F_146 ( void )
{
return F_147 ( & V_233 ) ;
}
void T_12 F_148 ( void )
{
F_149 ( & V_233 ) ;
}
