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
void F_4 ( struct V_8 * V_9 , T_1 V_3 )
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
unsigned long V_47 ;
V_9 = V_37 -> V_34 -> V_35 ;
V_9 -> V_48 [ V_42 ] . V_49 = & V_46 ;
switch ( V_39 ) {
case V_50 :
V_45 = V_40 ;
if ( V_45 -> V_51 ) {
V_9 -> V_48 [ V_42 ] . V_51 =
V_45 -> V_51 ;
}
if ( V_45 -> V_52 ) {
V_9 -> V_48 [ V_42 ] . V_52 =
V_45 -> V_52 ;
}
if ( V_9 -> V_48 [ V_42 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_54 -> V_56 ( V_9 , V_42 ,
V_57 ) ;
break;
case V_58 :
if ( V_9 -> V_48 [ V_42 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_54 -> V_56 ( V_9 , V_42 ,
V_59 ) ;
break;
case V_60 :
if ( V_9 -> V_48 [ V_42 ] . V_53 == 0 ) {
V_54 -> V_55 ( V_9 , V_42 ) ;
F_18 ( & V_46 ) ;
}
V_54 -> V_56 ( V_9 , V_42 ,
V_57 ) ;
break;
case V_61 :
V_54 -> V_56 ( V_9 , V_42 ,
V_57 ) ;
break;
case V_62 :
V_54 -> V_63 ( V_9 , V_42 ) ;
break;
case V_64 :
F_19 ( & V_9 -> V_65 , V_47 ) ;
if ( V_9 -> V_66 == V_67 ) {
if ( - 1 == F_20 ( V_9 ,
( V_42 < 4 ) ? 0x30000 : 0x40000 ) ) {
F_21 ( & V_9 -> V_65 , V_47 ) ;
return - V_68 ;
}
}
{
struct V_37 * V_48 = V_37 -> V_48 ;
T_5 * V_69 = ( T_5 * ) ( ( ( char * )
V_9 -> V_70 [ 2 ] . V_71 )
+ 0x1034 + ( 0x4000 * ( V_42 & 3 ) ) ) ;
V_48 -> V_72 = V_69 [ 0 ] ;
V_48 -> V_73 = V_69 [ 1 ] ;
V_48 -> V_74 = V_69 [ 3 ] ;
V_48 -> V_75 = V_69 [ 4 ] ;
}
if ( V_9 -> V_66 == V_67 )
F_20 ( V_9 , 0 ) ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
return 0 ;
default:
V_41 = - V_76 ;
}
F_22 ( 300 ) ;
return V_41 ;
}
void F_23 ( struct V_77 * V_78 )
{
int V_16 ;
struct V_8 * V_9 ;
struct V_31 * V_32 = F_24 ( V_78 ) ;
V_9 = V_32 -> V_35 ;
if ( V_9 -> V_66 == V_67 )
V_54 -> V_79 ( V_9 ) ;
for ( V_16 = 0 ; V_16 < V_9 -> V_80 -> V_81 ; ++ V_16 )
V_54 -> V_55 ( V_9 , V_16 ) ;
}
int F_25 ( struct V_77 * V_78 , unsigned long time )
{
struct V_31 * V_34 = F_24 ( V_78 ) ;
if ( time < V_82 )
return 0 ;
F_26 ( V_34 ) ;
return 1 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_83 ( V_9 , V_6 ) ;
}
T_1 F_28 ( struct V_1 * V_2 , T_1 * V_3 )
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
static int F_29 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_91 ( V_9 , V_6 ) ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_5 * V_6 , struct V_92 * V_93 )
{
return V_54 -> V_94 ( V_9 , V_6 , V_93 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_95 ( V_9 , V_6 ) ;
}
static int F_32 ( struct V_29 * V_30 )
{
struct V_29 * V_18 = V_30 -> V_96 ;
if ( ! V_18 )
return V_30 -> V_33 -> V_43 ;
while ( V_18 ) {
struct V_29 * V_97 = V_18 -> V_96 ;
if ( ! V_97 )
return V_18 -> V_33 -> V_43 ;
V_18 = V_18 -> V_96 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , const int V_98 ,
T_6 V_99 , int V_100 , struct V_92 * V_93 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 ;
struct V_101 * V_102 ;
struct V_103 * V_33 = NULL ;
struct V_1 * V_104 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_41 , V_105 = 0 ;
T_1 V_106 = V_98 ;
unsigned long V_47 = 0 ;
if ( ! V_30 -> V_33 ) {
struct V_107 * V_108 = & V_104 -> V_109 ;
V_108 -> V_110 = V_111 ;
V_108 -> V_112 = V_113 ;
if ( V_30 -> V_114 != V_115 )
V_104 -> V_116 ( V_104 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_30 ) ;
F_34 ( V_9 , F_12 ( L_2 ) ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
do {
V_30 = V_104 -> V_30 ;
V_102 = V_30 -> V_117 ;
V_33 = & V_9 -> V_33 [ F_32 ( V_30 ) ] ;
if ( F_35 ( V_102 ) || ! V_33 -> V_118 ) {
if ( F_36 ( V_104 -> V_119 ) ) {
struct V_107 * V_120 = & V_104 -> V_109 ;
V_120 -> V_110 = V_111 ;
V_120 -> V_112 = V_113 ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
V_104 -> V_116 ( V_104 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
if ( V_106 > 1 )
V_104 = F_37 ( V_104 -> V_121 . V_122 ,
struct V_1 , V_121 ) ;
continue;
} else {
struct V_107 * V_120 = & V_104 -> V_109 ;
V_120 -> V_110 = V_111 ;
V_120 -> V_112 = V_113 ;
V_104 -> V_116 ( V_104 ) ;
if ( V_106 > 1 )
V_104 = F_37 ( V_104 -> V_121 . V_122 ,
struct V_1 , V_121 ) ;
continue;
}
}
V_41 = F_7 ( V_9 , & V_3 ) ;
if ( V_41 )
goto V_123;
V_6 = & V_9 -> V_124 [ V_3 ] ;
if ( ! F_36 ( V_104 -> V_119 ) ) {
if ( V_104 -> V_125 ) {
V_105 = F_38 ( V_9 -> V_30 ,
V_104 -> V_126 ,
V_104 -> V_125 ,
V_104 -> V_127 ) ;
if ( ! V_105 ) {
V_41 = - V_128 ;
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
switch ( V_104 -> V_119 ) {
case V_130 :
V_41 = F_27 ( V_9 , V_6 ) ;
break;
case V_131 :
if ( V_100 )
V_41 = F_30 ( V_9 ,
V_6 , V_93 ) ;
else
V_41 = F_31 ( V_9 , V_6 ) ;
break;
case V_132 :
case V_133 :
V_41 = F_29 ( V_9 , V_6 ) ;
break;
default:
F_39 ( V_134 , V_9 -> V_30 ,
L_3 ,
V_104 -> V_119 ) ;
V_41 = - V_68 ;
break;
}
if ( V_41 ) {
F_34 ( V_9 ,
F_12 ( L_4 , V_41 ) ) ;
goto V_129;
}
F_40 ( & V_104 -> V_135 ) ;
V_104 -> V_136 |= V_137 ;
F_41 ( & V_104 -> V_135 ) ;
V_102 -> V_138 ++ ;
if ( V_106 > 1 )
V_104 = F_37 ( V_104 -> V_121 . V_122 , struct V_1 , V_121 ) ;
} while ( -- V_106 );
V_41 = 0 ;
goto V_139;
V_129:
F_4 ( V_9 , V_3 ) ;
V_123:
F_39 ( V_134 , V_9 -> V_30 , L_5 , V_41 ) ;
if ( ! F_36 ( V_104 -> V_119 ) )
if ( V_105 )
F_42 ( V_9 -> V_30 , V_104 -> V_126 , V_105 ,
V_104 -> V_127 ) ;
V_139:
F_21 ( & V_9 -> V_65 , V_47 ) ;
return V_41 ;
}
int F_43 ( struct V_1 * V_2 , const int V_98 ,
T_6 V_99 )
{
return F_33 ( V_2 , V_98 , V_99 , 0 , NULL ) ;
}
void F_44 ( struct V_8 * V_9 , T_1 V_140 )
{
F_2 ( V_9 , V_140 ) ;
}
void F_45 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_140 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_36 ( V_2 -> V_119 ) )
if ( V_6 -> V_105 )
F_42 ( V_9 -> V_30 , V_2 -> V_126 ,
V_2 -> V_125 , V_2 -> V_127 ) ;
switch ( V_2 -> V_119 ) {
case V_130 :
F_42 ( V_9 -> V_30 , & V_2 -> V_141 . V_142 , 1 ,
V_143 ) ;
F_42 ( V_9 -> V_30 , & V_2 -> V_141 . V_83 , 1 ,
V_144 ) ;
break;
case V_132 :
case V_133 :
case V_131 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
V_6 -> V_145 = 0 ;
F_44 ( V_9 , V_140 ) ;
}
struct V_101 * F_46 ( struct V_8 * V_9 )
{
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_146 ; V_30 ++ ) {
if ( V_9 -> V_147 [ V_30 ] . V_114 == V_148 ) {
V_9 -> V_147 [ V_30 ] . V_43 = V_30 ;
return & V_9 -> V_147 [ V_30 ] ;
}
}
if ( V_30 == V_146 ) {
F_47 ( V_9 ,
F_12 ( L_6 ,
V_146 ) ) ;
}
return NULL ;
}
struct V_101 * F_48 ( struct V_8 * V_9 ,
T_1 V_149 )
{
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_146 ; V_30 ++ ) {
if ( V_9 -> V_147 [ V_30 ] . V_149 == V_149 )
return & V_9 -> V_147 [ V_30 ] ;
}
if ( V_30 == V_146 ) {
F_47 ( V_9 , F_12 ( L_7
L_8 ) ) ;
}
return NULL ;
}
static void F_49 ( struct V_101 * V_102 )
{
T_1 V_43 = V_102 -> V_43 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_102 -> V_43 = V_43 ;
V_102 -> V_114 = V_148 ;
V_102 -> V_149 = V_146 ;
V_102 -> V_150 = NULL ;
}
static int F_50 ( struct V_29 * V_30 )
{
unsigned long V_47 = 0 ;
int V_151 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_29 * V_152 = V_30 -> V_96 ;
struct V_101 * V_101 ;
F_17 ( V_46 ) ;
T_1 V_153 = 0 ;
V_9 = F_15 ( V_30 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
V_101 = F_46 ( V_9 ) ;
if ( ! V_101 ) {
V_151 = - 1 ;
goto V_154;
}
V_101 -> V_150 = V_30 ;
V_30 -> V_117 = V_101 ;
V_101 -> V_114 = V_30 -> V_114 ;
V_101 -> V_155 = & V_46 ;
if ( V_152 && F_51 ( V_152 -> V_114 ) ) {
int V_42 ;
struct V_156 * V_48 ;
for ( V_42 = 0 ; V_42 < V_152 -> V_157 . V_158 ;
V_42 ++ ) {
V_48 = & V_152 -> V_157 . V_156 [ V_42 ] ;
if ( F_52 ( V_48 -> V_159 )
== F_52 ( V_30 -> V_160 ) ) {
V_101 -> V_161 = V_42 ;
break;
}
}
if ( V_42 == V_152 -> V_157 . V_158 ) {
F_47 ( V_9 ,
F_12 ( L_9
L_10 , F_52 ( V_30 -> V_160 ) ,
F_52 ( V_152 -> V_160 ) ) ) ;
V_151 = - 1 ;
}
} else {
if ( V_30 -> V_114 == V_115 ) {
V_101 -> V_161 =
V_30 -> V_162 -> V_163 . V_164 ;
V_153 = 1 ;
}
}
F_53 ( V_9 , F_12 ( L_11 ) ) ;
V_54 -> V_165 ( V_9 , V_101 , V_153 ) ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
F_18 ( & V_46 ) ;
if ( V_30 -> V_114 == V_166 )
F_22 ( 50 ) ;
V_9 -> V_47 = V_167 ;
return 0 ;
V_154:
F_21 ( & V_9 -> V_65 , V_47 ) ;
return V_151 ;
}
int F_54 ( struct V_29 * V_30 )
{
return F_50 ( V_30 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( ! F_56 ( & V_2 -> V_168 -> V_169 ) )
return;
F_57 ( & V_2 -> V_168 -> V_46 ) ;
}
static void F_58 ( unsigned long V_170 )
{
struct V_1 * V_2 = (struct V_1 * ) V_170 ;
V_2 -> V_136 |= V_171 ;
F_57 ( & V_2 -> V_168 -> V_46 ) ;
}
static int F_59 ( struct V_29 * V_30 ,
void * V_172 , T_1 V_173 , struct V_92 * V_93 )
{
int V_151 , V_174 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
struct V_101 * V_102 = V_30 -> V_117 ;
F_17 ( V_175 ) ;
for ( V_174 = 0 ; V_174 < 3 ; V_174 ++ ) {
V_2 = F_60 ( V_176 ) ;
if ( ! V_2 )
return - V_128 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_119 = V_30 -> V_177 ;
memcpy ( & V_2 -> V_178 , V_172 , V_173 ) ;
V_2 -> V_116 = F_55 ;
V_2 -> V_168 -> V_169 . V_170 = ( unsigned long ) V_2 ;
V_2 -> V_168 -> V_169 . V_179 = F_58 ;
V_2 -> V_168 -> V_169 . V_180 = V_181 + V_182 * V_82 ;
F_61 ( & V_2 -> V_168 -> V_169 ) ;
V_151 = F_33 ( V_2 , 1 , V_176 , 1 , V_93 ) ;
if ( V_151 ) {
F_56 ( & V_2 -> V_168 -> V_169 ) ;
F_47 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_183;
}
F_18 ( & V_2 -> V_168 -> V_46 ) ;
if ( V_9 -> V_66 != V_67 ) {
V_102 -> V_184 = & V_175 ;
V_54 -> V_185 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_175 ) ;
}
V_151 = - V_186 ;
if ( ( V_2 -> V_136 & V_171 ) ) {
if ( ! ( V_2 -> V_136 & V_187 ) ) {
F_47 ( V_9 ,
F_12 ( L_14 ,
V_93 -> V_93 ) ) ;
goto V_183;
}
}
if ( V_2 -> V_109 . V_110 == V_188 &&
V_2 -> V_109 . V_112 == V_189 ) {
V_151 = V_190 ;
break;
}
if ( V_2 -> V_109 . V_110 == V_188 &&
V_2 -> V_109 . V_112 == V_191 ) {
V_151 = V_2 -> V_109 . V_192 ;
break;
}
if ( V_2 -> V_109 . V_110 == V_188 &&
V_2 -> V_109 . V_112 == V_193 ) {
F_47 ( V_9 ,
F_12 ( L_15 ) ) ;
V_151 = - V_194 ;
break;
} else {
F_62 ( V_9 ,
F_12 ( L_16
L_17 ,
F_52 ( V_30 -> V_160 ) ,
V_2 -> V_109 . V_110 ,
V_2 -> V_109 . V_112 ) ) ;
F_63 ( V_2 ) ;
V_2 = NULL ;
}
}
V_183:
F_64 ( V_174 == 3 && V_2 != NULL ) ;
F_63 ( V_2 ) ;
return V_151 ;
}
static int
F_65 ( struct V_8 * V_9 ,
struct V_101 * V_102 , struct V_29 * V_30 , T_1 V_153 ,
T_1 V_195 )
{
int V_151 , V_174 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_174 = 0 ; V_174 < 3 ; V_174 ++ ) {
V_2 = F_60 ( V_176 ) ;
if ( ! V_2 )
return - V_128 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_119 = V_30 -> V_177 ;
V_2 -> V_116 = F_55 ;
V_2 -> V_168 -> V_169 . V_170 = ( unsigned long ) V_2 ;
V_2 -> V_168 -> V_169 . V_179 = F_58 ;
V_2 -> V_168 -> V_169 . V_180 = V_181 + V_182 * V_82 ;
F_61 ( & V_2 -> V_168 -> V_169 ) ;
V_151 = F_7 ( V_9 , & V_7 ) ;
if ( V_151 )
return V_151 ;
V_6 = & V_9 -> V_124 [ V_7 ] ;
V_6 -> V_196 = V_102 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_151 = V_54 -> V_197 ( V_9 ,
V_102 , V_153 , V_195 , V_7 ) ;
if ( V_151 ) {
F_56 ( & V_2 -> V_168 -> V_169 ) ;
F_47 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_183;
}
F_18 ( & V_2 -> V_168 -> V_46 ) ;
V_151 = V_186 ;
if ( ( V_2 -> V_136 & V_171 ) ) {
if ( ! ( V_2 -> V_136 & V_187 ) ) {
F_47 ( V_9 ,
F_12 ( L_18 ) ) ;
goto V_183;
}
}
if ( V_2 -> V_109 . V_110 == V_188 &&
V_2 -> V_109 . V_112 == V_189 ) {
V_151 = V_190 ;
break;
} else {
F_62 ( V_9 ,
F_12 ( L_19
L_17 ,
F_52 ( V_30 -> V_160 ) ,
V_2 -> V_109 . V_110 ,
V_2 -> V_109 . V_112 ) ) ;
F_63 ( V_2 ) ;
V_2 = NULL ;
}
}
V_183:
F_64 ( V_174 == 3 && V_2 != NULL ) ;
F_63 ( V_2 ) ;
return V_151 ;
}
static void F_66 ( struct V_29 * V_30 )
{
unsigned long V_47 = 0 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_101 * V_102 = V_30 -> V_117 ;
V_9 = F_15 ( V_30 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
F_7 ( V_9 , & V_3 ) ;
if ( V_102 ) {
T_1 V_149 = V_102 -> V_149 ;
F_53 ( V_9 ,
F_12 ( L_20 ,
V_102 -> V_149 , V_102 -> V_114 ) ) ;
if ( V_102 -> V_138 ) {
F_21 ( & V_9 -> V_65 , V_47 ) ;
F_65 ( V_9 , V_102 ,
V_30 , 1 , 0 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
}
V_54 -> V_198 ( V_9 , V_149 ) ;
F_49 ( V_102 ) ;
} else {
F_53 ( V_9 ,
F_12 ( L_21 ) ) ;
}
V_30 -> V_117 = NULL ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
}
void F_67 ( struct V_29 * V_30 )
{
F_66 ( V_30 ) ;
}
static int F_68 ( struct V_29 * V_30 ,
T_7 * V_199 , struct V_92 * V_93 )
{
struct V_200 V_178 ;
if ( ! ( V_30 -> V_177 & V_131 ) )
return V_201 ;
strncpy ( ( T_7 * ) & V_178 . V_202 , V_199 , 8 ) ;
return F_59 ( V_30 , & V_178 , sizeof( V_178 ) ,
V_93 ) ;
}
void F_69 (
struct V_8 * V_9 ,
struct V_1 * V_203 ,
struct V_101 * V_204 )
{
int V_16 ;
unsigned long V_47 ;
if ( V_9 == NULL )
return;
F_19 ( & V_9 -> V_65 , V_47 ) ;
for ( V_16 = 0 ; V_16 < V_205 ; V_16 ++ ) {
struct V_1 * V_2 ;
struct V_107 * V_120 ;
struct V_101 * V_102 ;
unsigned long V_206 ;
T_1 V_3 ;
struct V_5 * V_6 = & V_9 -> V_124 [ V_16 ] ;
V_102 = V_6 -> V_196 ;
if ( ! V_102 || ( V_102 -> V_114 == V_148 ) )
continue;
if ( ! V_204 ) {
T_8 V_207 = ( T_8 ) V_102
- ( T_8 ) & V_9 -> V_147 ;
if ( ( ( V_207 % sizeof( * V_102 ) ) != 0 )
|| ( ( V_207 / sizeof( * V_102 ) ) >= V_146 ) )
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
V_120 -> V_110 = V_188 ;
V_120 -> V_112 = V_208 ;
V_120 -> V_209 = V_210 ;
if ( V_102 )
V_102 -> V_138 -- ;
F_19 ( & V_2 -> V_135 , V_206 ) ;
V_2 -> V_136 &= ~ V_211 ;
V_2 -> V_136 &= ~ V_137 ;
V_2 -> V_136 |= V_187 ;
if ( F_70 ( ( V_2 -> V_136
& V_171 ) ) ) {
F_21 ( & V_2 -> V_135 ,
V_206 ) ;
F_45 ( V_9 , V_2 , V_6 , V_3 ) ;
} else {
F_21 ( & V_2 -> V_135 ,
V_206 ) ;
F_45 ( V_9 , V_2 , V_6 , V_3 ) ;
F_71 () ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
V_2 -> V_116 ( V_2 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
}
}
F_21 ( & V_9 -> V_65 , V_47 ) ;
}
int F_72 ( struct V_29 * V_30 )
{
int V_41 = V_186 ;
struct V_101 * V_102 ;
struct V_8 * V_9 ;
struct V_37 * V_48 ;
if ( ! V_30 || ! V_30 -> V_117 )
return - V_212 ;
V_102 = V_30 -> V_117 ;
V_9 = F_15 ( V_30 ) ;
V_48 = F_73 ( V_30 ) ;
if ( F_74 ( V_30 ) ) {
F_17 ( V_175 ) ;
if ( F_75 ( V_48 ) ) {
V_41 = 0 ;
goto V_213;
}
V_41 = F_76 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
V_41 = F_65 ( V_9 , V_102 ,
V_30 , 1 , 0 ) ;
V_102 -> V_184 = & V_175 ;
V_41 = V_54 -> V_185 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_175 ) ;
} else {
V_41 = F_76 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
}
F_62 ( V_9 , F_12 ( L_22 ,
V_102 -> V_149 , V_41 ) ) ;
V_213:
F_77 ( V_48 ) ;
return V_41 ;
}
int F_78 ( struct V_29 * V_30 )
{
int V_41 = V_186 ;
struct V_101 * V_102 ;
struct V_8 * V_9 ;
struct V_37 * V_48 ;
T_1 V_149 = 0 ;
if ( ! V_30 || ! V_30 -> V_117 )
return - 1 ;
V_102 = V_30 -> V_117 ;
V_149 = V_102 -> V_149 ;
V_9 = F_15 ( V_30 ) ;
F_62 ( V_9 ,
F_12 ( L_23 ) ) ;
V_48 = F_73 ( V_30 ) ;
if ( F_74 ( V_30 ) ) {
F_17 ( V_175 ) ;
if ( F_75 ( V_48 ) ) {
V_41 = 0 ;
goto V_213;
}
V_41 = F_65 ( V_9 , V_102 ,
V_30 , 1 , 0 ) ;
F_22 ( 100 ) ;
F_66 ( V_30 ) ;
F_22 ( 200 ) ;
V_41 = F_76 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
V_102 -> V_184 = & V_175 ;
F_18 ( & V_175 ) ;
} else {
V_41 = F_65 ( V_9 , V_102 ,
V_30 , 1 , 0 ) ;
F_22 ( 100 ) ;
F_66 ( V_30 ) ;
F_22 ( 200 ) ;
V_41 = F_76 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
}
F_62 ( V_9 , F_12 ( L_22 ,
V_102 -> V_149 , V_41 ) ) ;
V_213:
F_77 ( V_48 ) ;
return V_41 ;
}
int F_79 ( struct V_29 * V_30 , T_7 * V_199 )
{
int V_41 = V_186 ;
struct V_92 V_214 ;
struct V_101 * V_102 = V_30 -> V_117 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
F_17 ( V_175 ) ;
if ( F_74 ( V_30 ) ) {
struct V_37 * V_48 = F_73 ( V_30 ) ;
V_41 = F_65 ( V_9 , V_102 ,
V_30 , 1 , 0 ) ;
V_41 = F_76 ( V_48 , 1 ) ;
F_77 ( V_48 ) ;
V_102 -> V_184 = & V_175 ;
V_41 = V_54 -> V_185 ( V_9 ,
V_102 , 0x01 ) ;
F_18 ( & V_175 ) ;
} else {
V_214 . V_93 = V_215 ;
V_41 = F_68 ( V_30 , V_199 , & V_214 ) ;
}
F_62 ( V_9 , F_12 ( L_24 ,
V_102 -> V_149 , V_41 ) ) ;
return V_41 ;
}
int F_80 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_16 = 0 ;
struct V_216 V_199 ;
struct V_92 V_214 ;
int V_41 = V_186 ;
if ( F_70 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
if ( V_2 -> V_119 & V_131 ) {
struct V_217 * V_218 = V_2 -> V_86 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 =
F_15 ( V_30 ) ;
F_81 ( V_218 -> V_196 -> V_199 , & V_199 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
V_41 = V_186 ;
return V_41 ;
}
F_62 ( V_9 , F_12 ( L_25 ) ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_82 ( V_219 L_26 , V_218 -> V_218 [ V_16 ] ) ;
F_82 ( V_219 L_27 ) ;
V_214 . V_93 = V_220 ;
V_214 . V_221 = V_3 ;
V_41 = F_68 ( V_30 , V_199 . V_216 , & V_214 ) ;
switch ( V_41 ) {
case V_222 :
F_62 ( V_9 ,
F_12 ( L_28 ) ) ;
break;
case V_186 :
case V_190 :
F_62 ( V_9 ,
F_12 ( L_29
L_30 ) ) ;
break;
}
}
F_12 ( L_31 , V_41 ) ;
return V_41 ;
}
int F_83 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_149 ;
struct V_29 * V_30 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_216 V_199 ;
struct V_101 * V_102 ;
struct V_92 V_214 ;
int V_41 = V_186 ;
if ( F_70 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
F_19 ( & V_2 -> V_135 , V_47 ) ;
if ( V_2 -> V_136 & V_187 ) {
F_21 ( & V_2 -> V_135 , V_47 ) ;
V_41 = V_190 ;
goto V_213;
}
F_21 ( & V_2 -> V_135 , V_47 ) ;
if ( V_2 -> V_119 & V_131 ) {
struct V_217 * V_218 = V_2 -> V_86 ;
V_30 = V_2 -> V_30 ;
V_6 = V_2 -> V_4 ;
V_102 = V_30 -> V_117 ;
V_9 = F_15 ( V_30 ) ;
F_81 ( V_218 -> V_196 -> V_199 , & V_199 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_82 ( V_219 L_32 , V_223 ) ;
V_41 = V_186 ;
return V_41 ;
}
V_149 = V_102 -> V_149 ;
F_62 ( V_9 ,
F_12 ( L_33 , V_149 ) ) ;
V_214 . V_93 = V_224 ;
V_214 . V_221 = V_3 ;
V_41 = F_68 ( V_30 , V_199 . V_216 , & V_214 ) ;
F_65 ( V_9 , V_102 ,
V_102 -> V_150 , 0 , V_3 ) ;
} else if ( V_2 -> V_119 & V_132 ||
V_2 -> V_119 & V_133 ) {
V_30 = V_2 -> V_30 ;
V_102 = V_30 -> V_117 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_82 ( V_219 L_32 , V_223 ) ;
V_41 = V_186 ;
return V_41 ;
}
V_41 = F_65 ( V_9 , V_102 ,
V_102 -> V_150 , 0 , V_3 ) ;
} else if ( V_2 -> V_119 & V_130 ) {
V_30 = V_2 -> V_30 ;
V_102 = V_30 -> V_117 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_82 ( V_219 L_32 , V_223 ) ;
V_41 = V_186 ;
return V_41 ;
}
V_41 = F_65 ( V_9 , V_102 ,
V_102 -> V_150 , 0 , V_3 ) ;
}
V_213:
if ( V_41 != V_190 )
F_12 ( L_34 , V_41 ) ;
return V_41 ;
}
int F_84 ( struct V_29 * V_30 , T_7 * V_199 )
{
int V_41 = V_186 ;
struct V_92 V_214 ;
V_214 . V_93 = V_225 ;
V_41 = F_68 ( V_30 , V_199 , & V_214 ) ;
return V_41 ;
}
int F_85 ( struct V_29 * V_30 , T_7 * V_199 )
{
int V_41 = V_186 ;
struct V_92 V_214 ;
V_214 . V_93 = V_226 ;
V_41 = F_68 ( V_30 , V_199 , & V_214 ) ;
return V_41 ;
}
int F_86 ( struct V_29 * V_30 , T_7 * V_199 )
{
int V_41 = V_186 ;
struct V_92 V_214 ;
struct V_101 * V_102 = V_30 -> V_117 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
F_62 ( V_9 ,
F_12 ( L_35 ,
V_102 -> V_149 ) ) ;
V_214 . V_93 = V_227 ;
V_41 = F_68 ( V_30 , V_199 , & V_214 ) ;
return V_41 ;
}
