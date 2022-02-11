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
void F_2 ( struct V_8 * V_9 , T_1 V_3 )
{
void * V_10 = V_9 -> V_11 ;
F_3 ( V_3 , V_10 ) ;
}
inline int F_4 ( struct V_8 * V_9 , T_1 * V_12 )
{
unsigned int V_3 ;
void * V_10 = V_9 -> V_11 ;
unsigned long V_13 ;
F_5 ( & V_9 -> V_14 , V_13 ) ;
V_3 = F_6 ( V_10 , V_9 -> V_15 ) ;
if ( V_3 >= V_9 -> V_15 ) {
F_7 ( & V_9 -> V_14 , V_13 ) ;
return - V_16 ;
}
F_8 ( V_3 , V_10 ) ;
F_7 ( & V_9 -> V_14 , V_13 ) ;
* V_12 = V_3 ;
return 0 ;
}
void F_9 ( struct V_8 * V_9 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_9 -> V_15 ; ++ V_17 )
F_2 ( V_9 , V_17 ) ;
}
int F_10 ( struct V_18 * V_19 , void * * V_20 ,
T_2 * V_21 , T_1 * V_22 ,
T_1 * V_23 , T_1 V_24 , T_1 V_25 )
{
T_3 V_26 ;
T_2 V_27 ;
T_4 V_28 ;
T_4 V_29 = 0 ;
if ( V_25 )
V_29 = ( T_2 ) V_25 - 1 ;
V_26 = F_11 ( V_19 , V_24 + V_25 ,
& V_27 ) ;
if ( ! V_26 ) {
F_12 ( L_1 ) ;
return - 1 ;
}
* V_21 = V_27 ;
V_28 = ( * V_21 + V_29 ) & ~ V_29 ;
* V_20 = ( void * ) V_26 + V_28 - * V_21 ;
* V_22 = F_13 ( V_28 ) ;
* V_23 = F_14 ( V_28 ) ;
return 0 ;
}
static
struct V_8 * F_15 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_34 -> V_35 ;
struct V_8 * V_9 = V_33 -> V_36 ;
return V_9 ;
}
int F_16 ( struct V_37 * V_38 , enum V_39 V_40 ,
void * V_41 )
{
int V_42 = 0 , V_43 = V_38 -> V_44 ;
struct V_8 * V_9 = NULL ;
struct V_45 * V_46 ;
F_17 ( V_47 ) ;
unsigned long V_13 ;
V_9 = V_38 -> V_35 -> V_36 ;
V_9 -> V_48 [ V_43 ] . V_49 = & V_47 ;
switch ( V_40 ) {
case V_50 :
V_46 = V_41 ;
if ( V_46 -> V_51 ) {
V_9 -> V_48 [ V_43 ] . V_51 =
V_46 -> V_51 ;
}
if ( V_46 -> V_52 ) {
V_9 -> V_48 [ V_43 ] . V_52 =
V_46 -> V_52 ;
}
if ( V_9 -> V_48 [ V_43 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_43 ) ;
F_18 ( & V_47 ) ;
}
V_54 -> V_56 ( V_9 , V_43 ,
V_57 ) ;
break;
case V_58 :
if ( V_9 -> V_48 [ V_43 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_43 ) ;
F_18 ( & V_47 ) ;
}
V_54 -> V_56 ( V_9 , V_43 ,
V_59 ) ;
break;
case V_60 :
if ( V_9 -> V_48 [ V_43 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_43 ) ;
F_18 ( & V_47 ) ;
}
V_54 -> V_56 ( V_9 , V_43 ,
V_57 ) ;
break;
case V_61 :
V_54 -> V_56 ( V_9 , V_43 ,
V_57 ) ;
break;
case V_62 :
V_54 -> V_63 ( V_9 , V_43 ) ;
break;
case V_64 :
F_5 ( & V_9 -> V_65 , V_13 ) ;
if ( V_9 -> V_66 == V_67 ) {
if ( - 1 == F_19 ( V_9 ,
( V_43 < 4 ) ? 0x30000 : 0x40000 ) ) {
F_7 ( & V_9 -> V_65 , V_13 ) ;
return - V_68 ;
}
}
{
struct V_38 * V_48 = V_38 -> V_48 ;
T_5 * V_69 = ( T_5 * ) ( ( ( char * )
V_9 -> V_70 [ 2 ] . V_71 )
+ 0x1034 + ( 0x4000 * ( V_43 & 3 ) ) ) ;
V_48 -> V_72 = V_69 [ 0 ] ;
V_48 -> V_73 = V_69 [ 1 ] ;
V_48 -> V_74 = V_69 [ 3 ] ;
V_48 -> V_75 = V_69 [ 4 ] ;
}
if ( V_9 -> V_66 == V_67 )
F_19 ( V_9 , 0 ) ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
return 0 ;
default:
V_42 = - V_76 ;
}
F_20 ( 300 ) ;
return V_42 ;
}
void F_21 ( struct V_77 * V_78 )
{
int V_17 ;
struct V_8 * V_9 ;
struct V_32 * V_33 = F_22 ( V_78 ) ;
V_9 = V_33 -> V_36 ;
if ( V_9 -> V_66 == V_67 )
V_54 -> V_79 ( V_9 ) ;
for ( V_17 = 0 ; V_17 < V_9 -> V_80 -> V_81 ; ++ V_17 )
V_54 -> V_55 ( V_9 , V_17 ) ;
}
int F_23 ( struct V_77 * V_78 , unsigned long time )
{
struct V_32 * V_35 = F_22 ( V_78 ) ;
if ( time < V_82 )
return 0 ;
F_24 ( V_35 ) ;
return 1 ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_83 ( V_9 , V_6 ) ;
}
T_1 F_26 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
if ( V_85 ) {
if ( V_85 -> V_87 . V_88 == V_89 ||
V_85 -> V_87 . V_88 == V_90 ) {
* V_3 = V_85 -> V_3 ;
return 1 ;
}
}
return 0 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_91 ( V_9 , V_6 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_5 * V_6 , struct V_92 * V_93 )
{
return V_54 -> V_94 ( V_9 , V_6 , V_93 ) ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_95 ( V_9 , V_6 ) ;
}
static int F_30 ( struct V_30 * V_31 )
{
struct V_30 * V_19 = V_31 -> V_96 ;
if ( ! V_19 )
return V_31 -> V_34 -> V_44 ;
while ( V_19 ) {
struct V_30 * V_97 = V_19 -> V_96 ;
if ( ! V_97 )
return V_19 -> V_34 -> V_44 ;
V_19 = V_19 -> V_96 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , const int V_98 ,
T_6 V_99 , int V_100 , struct V_92 * V_93 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_8 * V_9 ;
struct V_101 * V_102 ;
struct V_103 * V_34 = NULL ;
struct V_1 * V_104 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_42 , V_105 = 0 ;
T_1 V_106 = V_98 ;
unsigned long V_13 = 0 ;
if ( ! V_31 -> V_34 ) {
struct V_107 * V_108 = & V_104 -> V_109 ;
V_108 -> V_110 = V_111 ;
V_108 -> V_112 = V_113 ;
if ( V_31 -> V_114 != V_115 )
V_104 -> V_116 ( V_104 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_31 ) ;
F_32 ( V_9 , F_12 ( L_2 ) ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
do {
V_31 = V_104 -> V_31 ;
V_102 = V_31 -> V_117 ;
V_34 = & V_9 -> V_34 [ F_30 ( V_31 ) ] ;
if ( F_33 ( V_102 ) || ! V_34 -> V_118 ) {
if ( F_34 ( V_104 -> V_119 ) ) {
struct V_107 * V_120 = & V_104 -> V_109 ;
V_120 -> V_110 = V_111 ;
V_120 -> V_112 = V_113 ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
V_104 -> V_116 ( V_104 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
if ( V_106 > 1 )
V_104 = F_35 ( V_104 -> V_121 . V_122 ,
struct V_1 , V_121 ) ;
continue;
} else {
struct V_107 * V_120 = & V_104 -> V_109 ;
V_120 -> V_110 = V_111 ;
V_120 -> V_112 = V_113 ;
V_104 -> V_116 ( V_104 ) ;
if ( V_106 > 1 )
V_104 = F_35 ( V_104 -> V_121 . V_122 ,
struct V_1 , V_121 ) ;
continue;
}
}
V_42 = F_4 ( V_9 , & V_3 ) ;
if ( V_42 )
goto V_123;
V_6 = & V_9 -> V_124 [ V_3 ] ;
if ( ! F_34 ( V_104 -> V_119 ) ) {
if ( V_104 -> V_125 ) {
V_105 = F_36 ( V_9 -> V_31 ,
V_104 -> V_126 ,
V_104 -> V_125 ,
V_104 -> V_127 ) ;
if ( ! V_105 ) {
V_42 = - V_128 ;
goto V_129;
}
}
} else {
V_105 = V_104 -> V_125 ;
}
V_104 -> V_4 = V_6 ;
V_6 -> V_105 = V_105 ;
V_6 -> V_7 = V_3 ;
V_6 -> V_2 = V_104 ;
V_6 -> V_130 = V_102 ;
switch ( V_104 -> V_119 ) {
case V_131 :
V_42 = F_25 ( V_9 , V_6 ) ;
break;
case V_132 :
if ( V_100 )
V_42 = F_28 ( V_9 ,
V_6 , V_93 ) ;
else
V_42 = F_29 ( V_9 , V_6 ) ;
break;
case V_133 :
case V_134 :
V_42 = F_27 ( V_9 , V_6 ) ;
break;
default:
F_37 ( V_135 , V_9 -> V_31 ,
L_3 ,
V_104 -> V_119 ) ;
V_42 = - V_68 ;
break;
}
if ( V_42 ) {
F_32 ( V_9 ,
F_12 ( L_4 , V_42 ) ) ;
goto V_129;
}
F_38 ( & V_104 -> V_136 ) ;
V_104 -> V_137 |= V_138 ;
F_39 ( & V_104 -> V_136 ) ;
V_102 -> V_139 ++ ;
if ( V_106 > 1 )
V_104 = F_35 ( V_104 -> V_121 . V_122 , struct V_1 , V_121 ) ;
} while ( -- V_106 );
V_42 = 0 ;
goto V_140;
V_129:
F_2 ( V_9 , V_3 ) ;
V_123:
F_37 ( V_135 , V_9 -> V_31 , L_5 , V_42 ) ;
if ( ! F_34 ( V_104 -> V_119 ) )
if ( V_105 )
F_40 ( V_9 -> V_31 , V_104 -> V_126 , V_105 ,
V_104 -> V_127 ) ;
V_140:
F_7 ( & V_9 -> V_65 , V_13 ) ;
return V_42 ;
}
int F_41 ( struct V_1 * V_2 , const int V_98 ,
T_6 V_99 )
{
return F_31 ( V_2 , V_98 , V_99 , 0 , NULL ) ;
}
void F_42 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_141 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_34 ( V_2 -> V_119 ) )
if ( V_6 -> V_105 )
F_40 ( V_9 -> V_31 , V_2 -> V_126 ,
V_2 -> V_125 , V_2 -> V_127 ) ;
switch ( V_2 -> V_119 ) {
case V_131 :
F_40 ( V_9 -> V_31 , & V_2 -> V_142 . V_143 , 1 ,
V_144 ) ;
F_40 ( V_9 -> V_31 , & V_2 -> V_142 . V_83 , 1 ,
V_145 ) ;
break;
case V_133 :
case V_134 :
case V_132 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
V_6 -> V_146 = 0 ;
F_2 ( V_9 , V_141 ) ;
}
struct V_101 * F_43 ( struct V_8 * V_9 )
{
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_147 ; V_31 ++ ) {
if ( V_9 -> V_148 [ V_31 ] . V_114 == V_149 ) {
V_9 -> V_148 [ V_31 ] . V_44 = V_31 ;
return & V_9 -> V_148 [ V_31 ] ;
}
}
if ( V_31 == V_147 ) {
F_44 ( V_9 ,
F_12 ( L_6 ,
V_147 ) ) ;
}
return NULL ;
}
struct V_101 * F_45 ( struct V_8 * V_9 ,
T_1 V_150 )
{
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_147 ; V_31 ++ ) {
if ( V_9 -> V_148 [ V_31 ] . V_150 == V_150 )
return & V_9 -> V_148 [ V_31 ] ;
}
if ( V_31 == V_147 ) {
F_44 ( V_9 , F_12 ( L_7
L_8 ) ) ;
}
return NULL ;
}
static void F_46 ( struct V_101 * V_102 )
{
T_1 V_44 = V_102 -> V_44 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_102 -> V_44 = V_44 ;
V_102 -> V_114 = V_149 ;
V_102 -> V_150 = V_147 ;
V_102 -> V_151 = NULL ;
}
static int F_47 ( struct V_30 * V_31 )
{
unsigned long V_13 = 0 ;
int V_152 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_30 * V_153 = V_31 -> V_96 ;
struct V_101 * V_101 ;
F_17 ( V_47 ) ;
T_1 V_154 = 0 ;
V_9 = F_15 ( V_31 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
V_101 = F_43 ( V_9 ) ;
if ( ! V_101 ) {
V_152 = - 1 ;
goto V_155;
}
V_101 -> V_151 = V_31 ;
V_31 -> V_117 = V_101 ;
V_101 -> V_114 = V_31 -> V_114 ;
V_101 -> V_156 = & V_47 ;
if ( V_153 && F_48 ( V_153 -> V_114 ) ) {
int V_43 ;
struct V_157 * V_48 ;
for ( V_43 = 0 ; V_43 < V_153 -> V_158 . V_159 ;
V_43 ++ ) {
V_48 = & V_153 -> V_158 . V_157 [ V_43 ] ;
if ( F_49 ( V_48 -> V_160 )
== F_49 ( V_31 -> V_161 ) ) {
V_101 -> V_162 = V_43 ;
break;
}
}
if ( V_43 == V_153 -> V_158 . V_159 ) {
F_44 ( V_9 ,
F_12 ( L_9
L_10 , F_49 ( V_31 -> V_161 ) ,
F_49 ( V_153 -> V_161 ) ) ) ;
V_152 = - 1 ;
}
} else {
if ( V_31 -> V_114 == V_115 ) {
V_101 -> V_162 =
V_31 -> V_163 -> V_164 . V_165 ;
V_154 = 1 ;
}
}
F_50 ( V_9 , F_12 ( L_11 ) ) ;
V_54 -> V_166 ( V_9 , V_101 , V_154 ) ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
F_18 ( & V_47 ) ;
if ( V_31 -> V_114 == V_167 )
F_20 ( 50 ) ;
V_9 -> V_13 = V_168 ;
return 0 ;
V_155:
F_7 ( & V_9 -> V_65 , V_13 ) ;
return V_152 ;
}
int F_51 ( struct V_30 * V_31 )
{
return F_47 ( V_31 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( ! F_53 ( & V_2 -> V_169 -> V_170 ) )
return;
F_54 ( & V_2 -> V_169 -> V_47 ) ;
}
static void F_55 ( unsigned long V_171 )
{
struct V_1 * V_2 = (struct V_1 * ) V_171 ;
V_2 -> V_137 |= V_172 ;
F_54 ( & V_2 -> V_169 -> V_47 ) ;
}
static int F_56 ( struct V_30 * V_31 ,
void * V_173 , T_1 V_174 , struct V_92 * V_93 )
{
int V_152 , V_175 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
struct V_101 * V_102 = V_31 -> V_117 ;
F_17 ( V_176 ) ;
for ( V_175 = 0 ; V_175 < 3 ; V_175 ++ ) {
V_2 = F_57 ( V_177 ) ;
if ( ! V_2 )
return - V_128 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_119 = V_31 -> V_178 ;
memcpy ( & V_2 -> V_179 , V_173 , V_174 ) ;
V_2 -> V_116 = F_52 ;
V_2 -> V_169 -> V_170 . V_171 = ( unsigned long ) V_2 ;
V_2 -> V_169 -> V_170 . V_180 = F_55 ;
V_2 -> V_169 -> V_170 . V_181 = V_182 + V_183 * V_82 ;
F_58 ( & V_2 -> V_169 -> V_170 ) ;
V_152 = F_31 ( V_2 , 1 , V_177 , 1 , V_93 ) ;
if ( V_152 ) {
F_53 ( & V_2 -> V_169 -> V_170 ) ;
F_44 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_184;
}
F_18 ( & V_2 -> V_169 -> V_47 ) ;
if ( V_9 -> V_66 != V_67 ) {
V_102 -> V_185 = & V_176 ;
V_54 -> V_186 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_176 ) ;
}
V_152 = - V_187 ;
if ( ( V_2 -> V_137 & V_172 ) ) {
if ( ! ( V_2 -> V_137 & V_188 ) ) {
F_44 ( V_9 ,
F_12 ( L_14 ,
V_93 -> V_93 ) ) ;
goto V_184;
}
}
if ( V_2 -> V_109 . V_110 == V_189 &&
V_2 -> V_109 . V_112 == V_190 ) {
V_152 = V_191 ;
break;
}
if ( V_2 -> V_109 . V_110 == V_189 &&
V_2 -> V_109 . V_112 == V_192 ) {
V_152 = V_2 -> V_109 . V_193 ;
break;
}
if ( V_2 -> V_109 . V_110 == V_189 &&
V_2 -> V_109 . V_112 == V_194 ) {
F_44 ( V_9 ,
F_12 ( L_15 ) ) ;
V_152 = - V_195 ;
break;
} else {
F_59 ( V_9 ,
F_12 ( L_16
L_17 ,
F_49 ( V_31 -> V_161 ) ,
V_2 -> V_109 . V_110 ,
V_2 -> V_109 . V_112 ) ) ;
F_60 ( V_2 ) ;
V_2 = NULL ;
}
}
V_184:
F_61 ( V_175 == 3 && V_2 != NULL ) ;
F_60 ( V_2 ) ;
return V_152 ;
}
static int
F_62 ( struct V_8 * V_9 ,
struct V_101 * V_102 , struct V_30 * V_31 , T_1 V_154 ,
T_1 V_196 )
{
int V_152 , V_175 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_175 = 0 ; V_175 < 3 ; V_175 ++ ) {
V_2 = F_57 ( V_177 ) ;
if ( ! V_2 )
return - V_128 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_119 = V_31 -> V_178 ;
V_2 -> V_116 = F_52 ;
V_2 -> V_169 -> V_170 . V_171 = ( unsigned long ) V_2 ;
V_2 -> V_169 -> V_170 . V_180 = F_55 ;
V_2 -> V_169 -> V_170 . V_181 = V_182 + V_183 * V_82 ;
F_58 ( & V_2 -> V_169 -> V_170 ) ;
V_152 = F_4 ( V_9 , & V_7 ) ;
if ( V_152 )
return V_152 ;
V_6 = & V_9 -> V_124 [ V_7 ] ;
V_6 -> V_130 = V_102 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_152 = V_54 -> V_197 ( V_9 ,
V_102 , V_154 , V_196 , V_7 ) ;
if ( V_152 ) {
F_53 ( & V_2 -> V_169 -> V_170 ) ;
F_44 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_184;
}
F_18 ( & V_2 -> V_169 -> V_47 ) ;
V_152 = V_187 ;
if ( ( V_2 -> V_137 & V_172 ) ) {
if ( ! ( V_2 -> V_137 & V_188 ) ) {
F_44 ( V_9 ,
F_12 ( L_18 ) ) ;
goto V_184;
}
}
if ( V_2 -> V_109 . V_110 == V_189 &&
V_2 -> V_109 . V_112 == V_190 ) {
V_152 = V_191 ;
break;
} else {
F_59 ( V_9 ,
F_12 ( L_19
L_17 ,
F_49 ( V_31 -> V_161 ) ,
V_2 -> V_109 . V_110 ,
V_2 -> V_109 . V_112 ) ) ;
F_60 ( V_2 ) ;
V_2 = NULL ;
}
}
V_184:
F_61 ( V_175 == 3 && V_2 != NULL ) ;
F_60 ( V_2 ) ;
return V_152 ;
}
static void F_63 ( struct V_30 * V_31 )
{
unsigned long V_13 = 0 ;
struct V_8 * V_9 ;
struct V_101 * V_102 = V_31 -> V_117 ;
V_9 = F_15 ( V_31 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
if ( V_102 ) {
T_1 V_150 = V_102 -> V_150 ;
F_50 ( V_9 ,
F_12 ( L_20 ,
V_102 -> V_150 , V_102 -> V_114 ) ) ;
if ( V_102 -> V_139 ) {
F_7 ( & V_9 -> V_65 , V_13 ) ;
F_62 ( V_9 , V_102 ,
V_31 , 1 , 0 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
}
V_54 -> V_198 ( V_9 , V_150 ) ;
F_46 ( V_102 ) ;
} else {
F_50 ( V_9 ,
F_12 ( L_21 ) ) ;
}
V_31 -> V_117 = NULL ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
}
void F_64 ( struct V_30 * V_31 )
{
F_63 ( V_31 ) ;
}
static int F_65 ( struct V_30 * V_31 ,
T_7 * V_199 , struct V_92 * V_93 )
{
struct V_200 V_179 ;
if ( ! ( V_31 -> V_178 & V_132 ) )
return V_201 ;
strncpy ( ( T_7 * ) & V_179 . V_202 , V_199 , 8 ) ;
return F_56 ( V_31 , & V_179 , sizeof( V_179 ) ,
V_93 ) ;
}
void F_66 (
struct V_8 * V_9 ,
struct V_1 * V_203 ,
struct V_101 * V_204 )
{
int V_17 ;
unsigned long V_13 ;
if ( V_9 == NULL )
return;
F_5 ( & V_9 -> V_65 , V_13 ) ;
for ( V_17 = 0 ; V_17 < V_205 ; V_17 ++ ) {
struct V_1 * V_2 ;
struct V_107 * V_120 ;
struct V_101 * V_102 ;
unsigned long V_206 ;
T_1 V_3 ;
struct V_5 * V_6 = & V_9 -> V_124 [ V_17 ] ;
V_102 = V_6 -> V_130 ;
if ( ! V_102 || ( V_102 -> V_114 == V_149 ) )
continue;
if ( ! V_204 ) {
T_8 V_207 = ( T_8 ) V_102
- ( T_8 ) & V_9 -> V_148 ;
if ( ( ( V_207 % sizeof( * V_102 ) ) != 0 )
|| ( ( V_207 / sizeof( * V_102 ) ) >= V_147 ) )
continue;
} else if ( V_102 != V_204 )
continue;
V_3 = V_6 -> V_7 ;
if ( ! V_3 || ( V_3 == 0xFFFFFFFF ) )
continue;
V_2 = V_6 -> V_2 ;
if ( ! V_2 || ! V_2 -> V_116 )
continue;
if ( V_203 && ( V_2 != V_203 ) )
continue;
V_120 = & V_2 -> V_109 ;
V_120 -> V_110 = V_189 ;
V_120 -> V_112 = V_208 ;
V_120 -> V_209 = V_210 ;
if ( V_102 )
V_102 -> V_139 -- ;
F_5 ( & V_2 -> V_136 , V_206 ) ;
V_2 -> V_137 &= ~ V_211 ;
V_2 -> V_137 &= ~ V_138 ;
V_2 -> V_137 |= V_188 ;
if ( F_67 ( ( V_2 -> V_137
& V_172 ) ) ) {
F_7 ( & V_2 -> V_136 ,
V_206 ) ;
F_42 ( V_9 , V_2 , V_6 , V_3 ) ;
} else {
F_7 ( & V_2 -> V_136 ,
V_206 ) ;
F_42 ( V_9 , V_2 , V_6 , V_3 ) ;
F_68 () ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
V_2 -> V_116 ( V_2 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
}
}
F_7 ( & V_9 -> V_65 , V_13 ) ;
}
int F_69 ( struct V_30 * V_31 )
{
int V_42 = V_187 ;
struct V_101 * V_102 ;
struct V_8 * V_9 ;
struct V_38 * V_48 ;
if ( ! V_31 || ! V_31 -> V_117 )
return - V_212 ;
V_102 = V_31 -> V_117 ;
V_9 = F_15 ( V_31 ) ;
V_48 = F_70 ( V_31 ) ;
if ( F_71 ( V_31 ) ) {
F_17 ( V_176 ) ;
if ( F_72 ( V_48 ) ) {
V_42 = 0 ;
goto V_213;
}
V_42 = F_73 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
V_42 = F_62 ( V_9 , V_102 ,
V_31 , 1 , 0 ) ;
V_102 -> V_185 = & V_176 ;
V_42 = V_54 -> V_186 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_176 ) ;
} else {
V_42 = F_73 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
}
F_59 ( V_9 , F_12 ( L_22 ,
V_102 -> V_150 , V_42 ) ) ;
V_213:
F_74 ( V_48 ) ;
return V_42 ;
}
int F_75 ( struct V_30 * V_31 )
{
int V_42 = V_187 ;
struct V_101 * V_102 ;
struct V_8 * V_9 ;
struct V_38 * V_48 ;
T_1 V_150 = 0 ;
if ( ! V_31 || ! V_31 -> V_117 )
return - 1 ;
V_102 = V_31 -> V_117 ;
V_150 = V_102 -> V_150 ;
V_9 = F_15 ( V_31 ) ;
F_59 ( V_9 ,
F_12 ( L_23 ) ) ;
V_48 = F_70 ( V_31 ) ;
if ( F_71 ( V_31 ) ) {
F_17 ( V_176 ) ;
if ( F_72 ( V_48 ) ) {
V_42 = 0 ;
goto V_213;
}
V_42 = F_62 ( V_9 , V_102 ,
V_31 , 1 , 0 ) ;
F_20 ( 100 ) ;
F_63 ( V_31 ) ;
F_20 ( 200 ) ;
V_42 = F_73 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
V_102 -> V_185 = & V_176 ;
F_18 ( & V_176 ) ;
} else {
V_42 = F_62 ( V_9 , V_102 ,
V_31 , 1 , 0 ) ;
F_20 ( 100 ) ;
F_63 ( V_31 ) ;
F_20 ( 200 ) ;
V_42 = F_73 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
}
F_59 ( V_9 , F_12 ( L_22 ,
V_102 -> V_150 , V_42 ) ) ;
V_213:
F_74 ( V_48 ) ;
return V_42 ;
}
int F_76 ( struct V_30 * V_31 , T_7 * V_199 )
{
int V_42 = V_187 ;
struct V_92 V_214 ;
struct V_101 * V_102 = V_31 -> V_117 ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
F_17 ( V_176 ) ;
if ( F_71 ( V_31 ) ) {
struct V_38 * V_48 = F_70 ( V_31 ) ;
V_42 = F_62 ( V_9 , V_102 ,
V_31 , 1 , 0 ) ;
V_42 = F_73 ( V_48 , 1 ) ;
F_74 ( V_48 ) ;
V_102 -> V_185 = & V_176 ;
V_42 = V_54 -> V_186 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_176 ) ;
} else {
V_214 . V_93 = V_215 ;
V_42 = F_65 ( V_31 , V_199 , & V_214 ) ;
}
F_59 ( V_9 , F_12 ( L_24 ,
V_102 -> V_150 , V_42 ) ) ;
return V_42 ;
}
int F_77 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_17 = 0 ;
struct V_216 V_199 ;
struct V_92 V_214 ;
int V_42 = V_187 ;
if ( F_67 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_31 ) )
return V_42 ;
if ( V_2 -> V_119 & V_132 ) {
struct V_217 * V_218 = V_2 -> V_86 ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_8 * V_9 =
F_15 ( V_31 ) ;
F_78 ( V_218 -> V_130 -> V_199 , & V_199 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
V_42 = V_187 ;
return V_42 ;
}
F_59 ( V_9 , F_12 ( L_25 ) ) ;
for ( V_17 = 0 ; V_17 < 16 ; V_17 ++ )
F_79 ( V_219 L_26 , V_218 -> V_218 [ V_17 ] ) ;
F_79 ( V_219 L_27 ) ;
V_214 . V_93 = V_220 ;
V_214 . V_221 = V_3 ;
V_42 = F_65 ( V_31 , V_199 . V_216 , & V_214 ) ;
switch ( V_42 ) {
case V_222 :
F_59 ( V_9 ,
F_12 ( L_28 ) ) ;
break;
case V_187 :
case V_191 :
F_59 ( V_9 ,
F_12 ( L_29
L_30 ) ) ;
break;
}
}
F_12 ( L_31 , V_42 ) ;
return V_42 ;
}
int F_80 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_150 ;
struct V_30 * V_31 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_216 V_199 ;
struct V_101 * V_102 ;
struct V_92 V_214 ;
int V_42 = V_187 ;
if ( F_67 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_31 ) )
return V_42 ;
F_5 ( & V_2 -> V_136 , V_13 ) ;
if ( V_2 -> V_137 & V_188 ) {
F_7 ( & V_2 -> V_136 , V_13 ) ;
V_42 = V_191 ;
goto V_213;
}
F_7 ( & V_2 -> V_136 , V_13 ) ;
if ( V_2 -> V_119 & V_132 ) {
struct V_217 * V_218 = V_2 -> V_86 ;
V_31 = V_2 -> V_31 ;
V_6 = V_2 -> V_4 ;
V_102 = V_31 -> V_117 ;
V_9 = F_15 ( V_31 ) ;
F_78 ( V_218 -> V_130 -> V_199 , & V_199 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_79 ( V_219 L_32 , V_223 ) ;
V_42 = V_187 ;
return V_42 ;
}
V_150 = V_102 -> V_150 ;
F_59 ( V_9 ,
F_12 ( L_33 , V_150 ) ) ;
V_214 . V_93 = V_224 ;
V_214 . V_221 = V_3 ;
V_42 = F_65 ( V_31 , V_199 . V_216 , & V_214 ) ;
F_62 ( V_9 , V_102 ,
V_102 -> V_151 , 0 , V_3 ) ;
} else if ( V_2 -> V_119 & V_133 ||
V_2 -> V_119 & V_134 ) {
V_31 = V_2 -> V_31 ;
V_102 = V_31 -> V_117 ;
V_9 = F_15 ( V_31 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_79 ( V_219 L_32 , V_223 ) ;
V_42 = V_187 ;
return V_42 ;
}
V_42 = F_62 ( V_9 , V_102 ,
V_102 -> V_151 , 0 , V_3 ) ;
} else if ( V_2 -> V_119 & V_131 ) {
V_31 = V_2 -> V_31 ;
V_102 = V_31 -> V_117 ;
V_9 = F_15 ( V_31 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_79 ( V_219 L_32 , V_223 ) ;
V_42 = V_187 ;
return V_42 ;
}
V_42 = F_62 ( V_9 , V_102 ,
V_102 -> V_151 , 0 , V_3 ) ;
}
V_213:
if ( V_42 != V_191 )
F_12 ( L_34 , V_42 ) ;
return V_42 ;
}
int F_81 ( struct V_30 * V_31 , T_7 * V_199 )
{
int V_42 = V_187 ;
struct V_92 V_214 ;
V_214 . V_93 = V_225 ;
V_42 = F_65 ( V_31 , V_199 , & V_214 ) ;
return V_42 ;
}
int F_82 ( struct V_30 * V_31 , T_7 * V_199 )
{
int V_42 = V_187 ;
struct V_92 V_214 ;
V_214 . V_93 = V_226 ;
V_42 = F_65 ( V_31 , V_199 , & V_214 ) ;
return V_42 ;
}
int F_83 ( struct V_30 * V_31 , T_7 * V_199 )
{
int V_42 = V_187 ;
struct V_92 V_214 ;
struct V_101 * V_102 = V_31 -> V_117 ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
F_59 ( V_9 ,
F_12 ( L_35 ,
V_102 -> V_150 ) ) ;
V_214 . V_93 = V_227 ;
V_42 = F_65 ( V_31 , V_199 , & V_214 ) ;
return V_42 ;
}
