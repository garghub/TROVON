static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( V_2 -> V_4 ) {
struct V_5 * V_6 ;
V_6 = V_2 -> V_4 ;
* V_3 = V_6 -> V_7 ;
return 1 ;
}
return 0 ;
}
static void F_2 ( struct V_8 * V_9 , T_1 V_3 )
{
void * V_10 = V_9 -> V_11 ;
F_3 ( V_3 , V_10 ) ;
}
static void F_4 ( struct V_8 * V_9 , T_1 V_3 )
{
F_2 ( V_9 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_9 , T_1 V_3 )
{
void * V_10 = V_9 -> V_11 ;
F_6 ( V_3 , V_10 ) ;
}
inline int F_7 ( struct V_8 * V_9 , T_1 * V_12 )
{
unsigned int V_13 , V_3 ;
void * V_10 = V_9 -> V_11 ;
V_13 = F_8 ( V_10 , V_9 -> V_14 ) ;
V_3 = V_13 ;
if ( V_3 >= V_9 -> V_14 )
return - V_15 ;
F_5 ( V_9 , V_3 ) ;
* V_12 = V_3 ;
return 0 ;
}
void F_9 ( struct V_8 * V_9 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_14 ; ++ V_16 )
F_2 ( V_9 , V_16 ) ;
}
int F_10 ( struct V_17 * V_18 , void * * V_19 ,
T_2 * V_20 , T_1 * V_21 ,
T_1 * V_22 , T_1 V_23 , T_1 V_24 )
{
T_3 V_25 ;
T_2 V_26 ;
T_4 V_27 ;
T_4 V_28 = 0 ;
if ( V_24 )
V_28 = ( T_2 ) V_24 - 1 ;
V_25 =
F_11 ( V_18 , V_23 + V_24 , & V_26 ) ;
if ( ! V_25 ) {
F_12 ( L_1 ) ;
return - 1 ;
}
memset ( ( void * ) V_25 , 0 , V_23 + V_24 ) ;
* V_20 = V_26 ;
V_27 = ( * V_20 + V_28 ) & ~ V_28 ;
* V_19 = ( void * ) V_25 + V_27 - * V_20 ;
* V_21 = F_13 ( V_27 ) ;
* V_22 = F_14 ( V_27 ) ;
return 0 ;
}
static
struct V_8 * F_15 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 -> V_34 ;
struct V_8 * V_9 = V_32 -> V_35 ;
return V_9 ;
}
int F_16 ( struct V_36 * V_37 , enum V_38 V_39 ,
void * V_40 )
{
int V_41 = 0 , V_42 = V_37 -> V_43 ;
struct V_8 * V_9 = NULL ;
struct V_44 * V_45 ;
F_17 ( V_46 ) ;
V_9 = V_37 -> V_34 -> V_35 ;
V_9 -> V_47 [ V_42 ] . V_48 = & V_46 ;
switch ( V_39 ) {
case V_49 :
V_45 = V_40 ;
if ( V_45 -> V_50 ) {
V_9 -> V_47 [ V_42 ] . V_50 =
V_45 -> V_50 ;
}
if ( V_45 -> V_51 ) {
V_9 -> V_47 [ V_42 ] . V_51 =
V_45 -> V_51 ;
}
if ( V_9 -> V_47 [ V_42 ] . V_52 == 0 ) {
V_53 -> V_54 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_53 -> V_55 ( V_9 , V_42 ,
V_56 ) ;
break;
case V_57 :
if ( V_9 -> V_47 [ V_42 ] . V_52 == 0 ) {
V_53 -> V_54 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_53 -> V_55 ( V_9 , V_42 ,
V_58 ) ;
break;
case V_59 :
if ( V_9 -> V_47 [ V_42 ] . V_52 == 0 ) {
V_53 -> V_54 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_53 -> V_55 ( V_9 , V_42 ,
V_56 ) ;
break;
case V_60 :
V_53 -> V_55 ( V_9 , V_42 ,
V_56 ) ;
break;
case V_61 :
V_53 -> V_62 ( V_9 , V_42 ) ;
break;
default:
V_41 = - V_63 ;
}
F_19 ( 300 ) ;
return V_41 ;
}
int F_20 ( struct V_64 * V_65 )
{
struct V_29 * V_30 = F_21 ( V_65 ) ;
if ( F_22 ( V_30 ) ) {
if ( V_65 -> V_66 > 0 )
return - V_67 ;
V_65 -> V_68 = 1 ;
}
return F_23 ( V_65 ) ;
}
void F_24 ( struct V_69 * V_70 )
{
int V_16 ;
struct V_8 * V_9 ;
struct V_31 * V_32 = F_25 ( V_70 ) ;
V_9 = V_32 -> V_35 ;
V_53 -> V_71 ( V_9 ) ;
for ( V_16 = 0 ; V_16 < V_9 -> V_72 -> V_73 ; ++ V_16 )
V_53 -> V_54 ( V_9 , V_16 ) ;
}
int F_26 ( struct V_69 * V_70 , unsigned long time )
{
if ( time < V_74 )
return 0 ;
F_27 ( V_70 ) ;
return 1 ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_75 ( V_9 , V_6 ) ;
}
T_1 F_29 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_76 * V_77 = V_2 -> V_78 ;
if ( V_77 ) {
if ( V_77 -> V_79 . V_80 == V_81 ||
V_77 -> V_79 . V_80 == V_82 ) {
* V_3 = V_77 -> V_3 ;
return 1 ;
}
}
return 0 ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_83 ( V_9 , V_6 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_5 * V_6 , struct V_84 * V_85 )
{
return V_53 -> V_86 ( V_9 , V_6 , V_85 ) ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_87 ( V_9 , V_6 ) ;
}
int F_33 ( struct V_64 * V_88 )
{
struct V_29 * V_30 = F_21 ( V_88 ) ;
int V_89 = F_34 ( V_88 ) ;
if ( V_89 )
return V_89 ;
if ( F_22 ( V_30 ) ) {
#ifdef F_35
struct V_90 * V_91 = V_30 -> V_92 . V_91 ;
struct V_93 * V_94 = V_91 -> V_95 . V_96 ;
V_94 -> V_97 |= V_98 ;
F_36 ( V_88 , V_99 , 1 ) ;
#endif
}
return 0 ;
}
static int F_37 ( struct V_29 * V_30 )
{
struct V_29 * V_18 = V_30 -> V_100 ;
if ( ! V_18 )
return V_30 -> V_33 -> V_43 ;
while ( V_18 ) {
struct V_29 * V_101 = V_18 -> V_100 ;
if ( ! V_101 )
return V_18 -> V_33 -> V_43 ;
V_18 = V_18 -> V_100 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , const int V_102 ,
T_5 V_103 , int V_104 , struct V_84 * V_85 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 ;
struct V_105 * V_106 ;
struct V_107 * V_33 = NULL ;
struct V_1 * V_108 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_41 , V_109 = 0 ;
T_1 V_110 = V_102 ;
unsigned long V_97 = 0 , V_111 = 0 ;
if ( ! V_30 -> V_33 ) {
struct V_112 * V_113 = & V_108 -> V_114 ;
V_113 -> V_115 = V_116 ;
V_113 -> V_117 = V_118 ;
if ( V_30 -> V_119 != V_120 )
V_108 -> V_121 ( V_108 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_30 ) ;
F_39 ( V_9 , F_12 ( L_2 ) ) ;
F_40 ( & V_9 -> V_122 , V_97 ) ;
do {
V_30 = V_108 -> V_30 ;
V_106 = V_30 -> V_123 ;
if ( F_41 ( V_106 ) ) {
if ( V_106 ) {
F_39 ( V_9 ,
F_12 ( L_3 ,
V_106 -> V_124 ) ) ;
} else {
F_39 ( V_9 ,
F_12 ( L_4
L_5 , F_42 ( V_30 -> V_125 ) ) ) ;
}
V_41 = V_118 ;
goto V_126;
}
V_33 = & V_9 -> V_33 [ F_37 ( V_30 ) ] ;
if ( ! V_33 -> V_127 ) {
if ( F_43 ( V_108 -> V_128 ) ) {
struct V_112 * V_129 = & V_108 -> V_114 ;
V_129 -> V_115 = V_116 ;
V_129 -> V_117 = V_118 ;
F_44 ( & V_9 -> V_122 , V_97 ) ;
F_44 ( V_30 -> V_92 . V_91 -> V_122 ,
V_111 ) ;
V_108 -> V_121 ( V_108 ) ;
F_40 ( V_30 -> V_92 . V_91 -> V_122 ,
V_111 ) ;
F_40 ( & V_9 -> V_122 , V_97 ) ;
if ( V_110 > 1 )
V_108 = F_45 ( V_108 -> V_130 . V_131 ,
struct V_1 , V_130 ) ;
continue;
} else {
struct V_112 * V_129 = & V_108 -> V_114 ;
V_129 -> V_115 = V_116 ;
V_129 -> V_117 = V_118 ;
V_108 -> V_121 ( V_108 ) ;
if ( V_110 > 1 )
V_108 = F_45 ( V_108 -> V_130 . V_131 ,
struct V_1 , V_130 ) ;
continue;
}
}
V_41 = F_7 ( V_9 , & V_3 ) ;
if ( V_41 )
goto V_132;
V_6 = & V_9 -> V_133 [ V_3 ] ;
if ( ! F_43 ( V_108 -> V_128 ) ) {
if ( V_108 -> V_134 ) {
V_109 = F_46 ( V_9 -> V_30 ,
V_108 -> V_135 ,
V_108 -> V_134 ,
V_108 -> V_136 ) ;
if ( ! V_109 ) {
V_41 = - V_137 ;
goto V_138;
}
}
} else {
V_109 = V_108 -> V_134 ;
}
V_108 -> V_4 = V_6 ;
V_6 -> V_109 = V_109 ;
V_6 -> V_7 = V_3 ;
V_6 -> V_2 = V_108 ;
switch ( V_108 -> V_128 ) {
case V_139 :
V_41 = F_28 ( V_9 , V_6 ) ;
break;
case V_140 :
if ( V_104 )
V_41 = F_31 ( V_9 ,
V_6 , V_85 ) ;
else
V_41 = F_32 ( V_9 , V_6 ) ;
break;
case V_141 :
case V_142 :
case V_141 | V_142 :
V_41 = F_30 ( V_9 , V_6 ) ;
break;
default:
F_47 ( V_143 , V_9 -> V_30 ,
L_6 ,
V_108 -> V_128 ) ;
V_41 = - V_144 ;
break;
}
if ( V_41 ) {
F_39 ( V_9 ,
F_12 ( L_7 , V_41 ) ) ;
goto V_138;
}
F_48 ( & V_108 -> V_145 ) ;
V_108 -> V_146 |= V_147 ;
F_49 ( & V_108 -> V_145 ) ;
V_106 -> V_148 ++ ;
if ( V_110 > 1 )
V_108 = F_45 ( V_108 -> V_130 . V_131 , struct V_1 , V_130 ) ;
} while ( -- V_110 );
V_41 = 0 ;
goto V_126;
V_138:
F_4 ( V_9 , V_3 ) ;
V_132:
F_47 ( V_143 , V_9 -> V_30 , L_8 , V_41 ) ;
if ( ! F_43 ( V_108 -> V_128 ) )
if ( V_109 )
F_50 ( V_9 -> V_30 , V_108 -> V_135 , V_109 ,
V_108 -> V_136 ) ;
V_126:
F_44 ( & V_9 -> V_122 , V_97 ) ;
return V_41 ;
}
int F_51 ( struct V_1 * V_2 , const int V_102 ,
T_5 V_103 )
{
return F_38 ( V_2 , V_102 , V_103 , 0 , NULL ) ;
}
void F_52 ( struct V_8 * V_9 , T_1 V_149 )
{
F_2 ( V_9 , V_149 ) ;
}
void F_53 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_149 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_43 ( V_2 -> V_128 ) )
if ( V_6 -> V_109 )
F_50 ( V_9 -> V_30 , V_2 -> V_135 ,
V_2 -> V_134 , V_2 -> V_136 ) ;
switch ( V_2 -> V_128 ) {
case V_139 :
F_50 ( V_9 -> V_30 , & V_2 -> V_150 . V_151 , 1 ,
V_152 ) ;
F_50 ( V_9 -> V_30 , & V_2 -> V_150 . V_75 , 1 ,
V_153 ) ;
break;
case V_141 :
case V_142 :
case V_140 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
F_52 ( V_9 , V_149 ) ;
}
struct V_105 * F_54 ( struct V_8 * V_9 )
{
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_154 ; V_30 ++ ) {
if ( V_9 -> V_155 [ V_30 ] . V_119 == V_156 ) {
V_9 -> V_155 [ V_30 ] . V_43 = V_30 ;
return & V_9 -> V_155 [ V_30 ] ;
}
}
if ( V_30 == V_154 ) {
F_55 ( V_9 ,
F_12 ( L_9 ,
V_154 ) ) ;
}
return NULL ;
}
static void F_56 ( struct V_105 * V_106 )
{
T_1 V_43 = V_106 -> V_43 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_43 = V_43 ;
V_106 -> V_119 = V_156 ;
V_106 -> V_124 = V_154 ;
V_106 -> V_157 = NULL ;
}
static int F_57 ( struct V_29 * V_30 )
{
unsigned long V_97 = 0 ;
int V_158 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_29 * V_159 = V_30 -> V_100 ;
struct V_105 * V_105 ;
F_17 ( V_46 ) ;
T_1 V_160 = 0 ;
V_9 = F_15 ( V_30 ) ;
F_40 ( & V_9 -> V_122 , V_97 ) ;
V_105 = F_54 ( V_9 ) ;
if ( ! V_105 ) {
V_158 = - 1 ;
goto V_161;
}
V_105 -> V_157 = V_30 ;
V_30 -> V_123 = V_105 ;
V_105 -> V_119 = V_30 -> V_119 ;
V_105 -> V_162 = & V_46 ;
if ( V_159 && F_58 ( V_159 -> V_119 ) ) {
int V_42 ;
struct V_163 * V_47 ;
for ( V_42 = 0 ; V_42 < V_159 -> V_164 . V_165 ;
V_42 ++ ) {
V_47 = & V_159 -> V_164 . V_163 [ V_42 ] ;
if ( F_42 ( V_47 -> V_166 )
== F_42 ( V_30 -> V_125 ) ) {
V_105 -> V_167 = V_42 ;
break;
}
}
if ( V_42 == V_159 -> V_164 . V_165 ) {
F_55 ( V_9 ,
F_12 ( L_10
L_11 , F_42 ( V_30 -> V_125 ) ,
F_42 ( V_159 -> V_125 ) ) ) ;
V_158 = - 1 ;
}
} else {
if ( V_30 -> V_119 == V_120 ) {
V_105 -> V_167 =
V_30 -> V_168 -> V_169 . V_170 ;
V_160 = 1 ;
}
}
F_59 ( V_9 , F_12 ( L_12 ) ) ;
V_53 -> V_171 ( V_9 , V_105 , V_160 ) ;
F_44 ( & V_9 -> V_122 , V_97 ) ;
F_18 ( & V_46 ) ;
if ( V_30 -> V_119 == V_172 )
F_19 ( 50 ) ;
V_9 -> V_97 |= V_173 ;
return 0 ;
V_161:
F_44 ( & V_9 -> V_122 , V_97 ) ;
return V_158 ;
}
int F_60 ( struct V_29 * V_30 )
{
return F_57 ( V_30 ) ;
}
static struct V_1 * F_61 ( void )
{
struct V_1 * V_2 = F_62 ( sizeof( * V_2 ) , V_174 ) ;
if ( V_2 ) {
F_63 ( & V_2 -> V_130 ) ;
F_64 ( & V_2 -> V_145 ) ;
V_2 -> V_146 = V_175 ;
F_65 ( & V_2 -> V_176 ) ;
F_66 ( & V_2 -> V_46 ) ;
}
return V_2 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_68 ( ! F_69 ( & V_2 -> V_130 ) ) ;
F_70 ( V_2 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
if ( ! F_72 ( & V_2 -> V_176 ) )
return;
F_73 ( & V_2 -> V_46 ) ;
}
static void F_74 ( unsigned long V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
V_2 -> V_146 |= V_178 ;
F_73 ( & V_2 -> V_46 ) ;
}
static int F_75 ( struct V_29 * V_30 ,
void * V_179 , T_1 V_180 , struct V_84 * V_85 )
{
int V_158 , V_181 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
for ( V_181 = 0 ; V_181 < 3 ; V_181 ++ ) {
V_2 = F_61 () ;
if ( ! V_2 )
return - V_137 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_128 = V_30 -> V_182 ;
memcpy ( & V_2 -> V_183 , V_179 , V_180 ) ;
V_2 -> V_121 = F_71 ;
V_2 -> V_176 . V_177 = ( unsigned long ) V_2 ;
V_2 -> V_176 . V_184 = F_74 ;
V_2 -> V_176 . V_185 = V_186 + V_187 * V_74 ;
F_76 ( & V_2 -> V_176 ) ;
V_158 = F_38 ( V_2 , 1 , V_174 , 1 , V_85 ) ;
if ( V_158 ) {
F_72 ( & V_2 -> V_176 ) ;
F_55 ( V_9 ,
F_12 ( L_13
L_14 ) ) ;
goto V_188;
}
F_18 ( & V_2 -> V_46 ) ;
V_158 = - V_189 ;
if ( ( V_2 -> V_146 & V_178 ) ) {
if ( ! ( V_2 -> V_146 & V_190 ) ) {
F_55 ( V_9 ,
F_12 ( L_15 ,
V_85 -> V_85 ) ) ;
goto V_188;
}
}
if ( V_2 -> V_114 . V_115 == V_191 &&
V_2 -> V_114 . V_117 == V_192 ) {
V_158 = V_193 ;
break;
}
if ( V_2 -> V_114 . V_115 == V_191 &&
V_2 -> V_114 . V_117 == V_194 ) {
V_158 = V_2 -> V_114 . V_195 ;
break;
}
if ( V_2 -> V_114 . V_115 == V_191 &&
V_2 -> V_114 . V_117 == V_196 ) {
F_55 ( V_9 ,
F_12 ( L_16 ) ) ;
V_158 = - V_197 ;
break;
} else {
F_77 ( V_9 ,
F_12 ( L_17
L_18 ,
F_42 ( V_30 -> V_125 ) ,
V_2 -> V_114 . V_115 ,
V_2 -> V_114 . V_117 ) ) ;
F_67 ( V_2 ) ;
V_2 = NULL ;
}
}
V_188:
F_68 ( V_181 == 3 && V_2 != NULL ) ;
if ( V_2 != NULL )
F_67 ( V_2 ) ;
return V_158 ;
}
static int
F_78 ( struct V_8 * V_9 ,
struct V_105 * V_106 , struct V_29 * V_30 , T_1 V_160 ,
T_1 V_198 )
{
int V_158 , V_181 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_181 = 0 ; V_181 < 3 ; V_181 ++ ) {
V_2 = F_61 () ;
if ( ! V_2 )
return - V_137 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_128 = V_30 -> V_182 ;
V_2 -> V_121 = F_71 ;
V_2 -> V_176 . V_177 = ( unsigned long ) V_2 ;
V_2 -> V_176 . V_184 = F_74 ;
V_2 -> V_176 . V_185 = V_186 + V_187 * V_74 ;
F_76 ( & V_2 -> V_176 ) ;
V_158 = F_7 ( V_9 , & V_7 ) ;
if ( V_158 )
return V_158 ;
V_6 = & V_9 -> V_133 [ V_7 ] ;
V_6 -> V_96 = V_106 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_158 = V_53 -> V_199 ( V_9 ,
V_106 , V_160 , V_198 , V_7 ) ;
if ( V_158 ) {
F_72 ( & V_2 -> V_176 ) ;
F_55 ( V_9 ,
F_12 ( L_13
L_14 ) ) ;
goto V_188;
}
F_18 ( & V_2 -> V_46 ) ;
V_158 = V_189 ;
if ( ( V_2 -> V_146 & V_178 ) ) {
if ( ! ( V_2 -> V_146 & V_190 ) ) {
F_55 ( V_9 ,
F_12 ( L_19 ) ) ;
goto V_188;
}
}
if ( V_2 -> V_114 . V_115 == V_191 &&
V_2 -> V_114 . V_117 == V_192 ) {
V_158 = V_193 ;
break;
} else {
F_77 ( V_9 ,
F_12 ( L_20
L_18 ,
F_42 ( V_30 -> V_125 ) ,
V_2 -> V_114 . V_115 ,
V_2 -> V_114 . V_117 ) ) ;
F_67 ( V_2 ) ;
V_2 = NULL ;
}
}
V_188:
F_68 ( V_181 == 3 && V_2 != NULL ) ;
if ( V_2 != NULL )
F_67 ( V_2 ) ;
return V_158 ;
}
static void F_79 ( struct V_29 * V_30 )
{
unsigned long V_97 = 0 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_105 * V_106 = V_30 -> V_123 ;
V_9 = F_15 ( V_30 ) ;
F_40 ( & V_9 -> V_122 , V_97 ) ;
F_7 ( V_9 , & V_3 ) ;
if ( V_106 ) {
T_1 V_124 = V_106 -> V_124 ;
F_59 ( V_9 ,
F_12 ( L_21 ,
V_106 -> V_124 , V_106 -> V_119 ) ) ;
if ( V_106 -> V_148 ) {
F_44 ( & V_9 -> V_122 , V_97 ) ;
F_78 ( V_9 , V_106 ,
V_30 , 1 , 0 ) ;
F_40 ( & V_9 -> V_122 , V_97 ) ;
}
V_53 -> V_200 ( V_9 , V_124 ) ;
F_56 ( V_106 ) ;
} else {
F_59 ( V_9 ,
F_12 ( L_22 ) ) ;
}
V_30 -> V_123 = NULL ;
F_44 ( & V_9 -> V_122 , V_97 ) ;
}
void F_80 ( struct V_29 * V_30 )
{
F_79 ( V_30 ) ;
}
static int F_81 ( struct V_29 * V_30 ,
T_6 * V_66 , struct V_84 * V_85 )
{
struct V_201 V_183 ;
if ( ! ( V_30 -> V_182 & V_140 ) )
return V_202 ;
strncpy ( ( T_6 * ) & V_183 . V_203 , V_66 , 8 ) ;
return F_75 ( V_30 , & V_183 , sizeof( V_183 ) ,
V_85 ) ;
}
int F_82 ( struct V_29 * V_30 )
{
int V_41 = V_189 ;
struct V_105 * V_106 ;
struct V_8 * V_9 ;
struct V_37 * V_47 ;
if ( ! V_30 || ! V_30 -> V_123 )
return - 1 ;
V_106 = V_30 -> V_123 ;
V_9 = F_15 ( V_30 ) ;
V_47 = F_83 ( V_30 ) ;
if ( F_22 ( V_30 ) ) {
F_17 ( V_204 ) ;
if ( F_84 ( V_47 ) )
return 0 ;
V_41 = F_85 ( V_47 , 1 ) ;
F_19 ( 2000 ) ;
V_41 = F_78 ( V_9 , V_106 ,
V_30 , 1 , 0 ) ;
V_106 -> V_205 = & V_204 ;
V_41 = V_53 -> V_206 ( V_9 ,
V_106 , 0x01 ) ;
F_18 ( & V_204 ) ;
} else{
V_41 = F_85 ( V_47 , 1 ) ;
F_19 ( 2000 ) ;
}
F_77 ( V_9 , F_12 ( L_23 ,
V_106 -> V_124 , V_41 ) ) ;
return V_41 ;
}
int F_86 ( struct V_29 * V_30 , T_6 * V_66 )
{
int V_41 = V_189 ;
struct V_84 V_207 ;
struct V_105 * V_106 = V_30 -> V_123 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
if ( F_22 ( V_30 ) ) {
struct V_37 * V_47 = F_83 ( V_30 ) ;
V_41 = F_78 ( V_9 , V_106 ,
V_30 , 1 , 0 ) ;
V_41 = F_85 ( V_47 , 1 ) ;
V_41 = V_53 -> V_206 ( V_9 ,
V_106 , 0x01 ) ;
F_19 ( 2000 ) ;
} else {
V_207 . V_85 = V_208 ;
V_41 = F_81 ( V_30 , V_66 , & V_207 ) ;
}
F_77 ( V_9 , F_12 ( L_24 ,
V_106 -> V_124 , V_41 ) ) ;
return V_41 ;
}
int F_87 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_16 = 0 ;
struct V_209 V_66 ;
struct V_84 V_207 ;
int V_41 = V_189 ;
if ( F_88 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
if ( V_2 -> V_128 & V_140 ) {
struct V_210 * V_211 = V_2 -> V_78 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 =
F_15 ( V_30 ) ;
F_89 ( V_211 -> V_96 -> V_66 , & V_66 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
V_41 = V_189 ;
return V_41 ;
}
F_77 ( V_9 , F_12 ( L_25 ) ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_90 ( V_212 L_26 , V_211 -> V_211 [ V_16 ] ) ;
F_90 ( V_212 L_27 ) ;
V_207 . V_85 = V_213 ;
V_207 . V_214 = V_3 ;
V_41 = F_81 ( V_30 , V_66 . V_209 , & V_207 ) ;
switch ( V_41 ) {
case V_215 :
F_77 ( V_9 ,
F_12 ( L_28 ) ) ;
case V_189 :
case V_193 :
F_77 ( V_9 ,
F_12 ( L_29
L_30 ) ) ;
break;
}
}
F_12 ( L_31 , V_41 ) ;
return V_41 ;
}
int F_91 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_124 ;
struct V_29 * V_30 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_209 V_66 ;
struct V_105 * V_106 ;
struct V_84 V_207 ;
int V_41 = V_189 ;
if ( F_88 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
F_40 ( & V_2 -> V_145 , V_97 ) ;
if ( V_2 -> V_146 & V_190 ) {
F_44 ( & V_2 -> V_145 , V_97 ) ;
V_41 = V_193 ;
goto V_216;
}
F_44 ( & V_2 -> V_145 , V_97 ) ;
if ( V_2 -> V_128 & V_140 ) {
struct V_210 * V_211 = V_2 -> V_78 ;
V_30 = V_2 -> V_30 ;
V_6 = V_2 -> V_4 ;
V_106 = V_30 -> V_123 ;
V_9 = F_15 ( V_30 ) ;
F_89 ( V_211 -> V_96 -> V_66 , & V_66 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_90 ( V_212 L_32 , V_217 ) ;
V_41 = V_189 ;
return V_41 ;
}
V_124 = V_106 -> V_124 ;
F_77 ( V_9 ,
F_12 ( L_33 , V_124 ) ) ;
V_207 . V_85 = V_218 ;
V_207 . V_214 = V_3 ;
V_41 = F_81 ( V_30 , V_66 . V_209 , & V_207 ) ;
F_78 ( V_9 , V_106 ,
V_106 -> V_157 , 0 , V_3 ) ;
} else if ( V_2 -> V_128 & V_141 ||
V_2 -> V_128 & V_142 ) {
V_30 = V_2 -> V_30 ;
V_106 = V_30 -> V_123 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_90 ( V_212 L_32 , V_217 ) ;
V_41 = V_189 ;
return V_41 ;
}
V_41 = F_78 ( V_9 , V_106 ,
V_106 -> V_157 , 0 , V_3 ) ;
} else if ( V_2 -> V_128 & V_139 ) {
V_30 = V_2 -> V_30 ;
V_106 = V_30 -> V_123 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_90 ( V_212 L_32 , V_217 ) ;
V_41 = V_189 ;
return V_41 ;
}
V_41 = F_78 ( V_9 , V_106 ,
V_106 -> V_157 , 0 , V_3 ) ;
}
V_216:
if ( V_41 != V_193 )
F_12 ( L_34 , V_41 ) ;
return V_41 ;
}
int F_92 ( struct V_29 * V_30 , T_6 * V_66 )
{
int V_41 = V_189 ;
struct V_84 V_207 ;
V_207 . V_85 = V_219 ;
V_41 = F_81 ( V_30 , V_66 , & V_207 ) ;
return V_41 ;
}
int F_93 ( struct V_29 * V_30 , T_6 * V_66 )
{
int V_41 = V_189 ;
struct V_84 V_207 ;
V_207 . V_85 = V_220 ;
V_41 = F_81 ( V_30 , V_66 , & V_207 ) ;
return V_41 ;
}
int F_94 ( struct V_29 * V_30 , T_6 * V_66 )
{
int V_41 = V_189 ;
struct V_84 V_207 ;
struct V_105 * V_106 = V_30 -> V_123 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
F_77 ( V_9 ,
F_12 ( L_35 ,
V_106 -> V_124 ) ) ;
V_207 . V_85 = V_221 ;
V_41 = F_81 ( V_30 , V_66 , & V_207 ) ;
return V_41 ;
}
