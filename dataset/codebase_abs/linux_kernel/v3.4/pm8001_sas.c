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
if ( - 1 == F_20 ( V_9 ,
( V_42 < 4 ) ? 0x30000 : 0x40000 ) ) {
F_21 ( & V_9 -> V_65 , V_47 ) ;
return - V_66 ;
}
{
struct V_37 * V_48 = V_37 -> V_48 ;
T_5 * V_67 = ( T_5 * ) ( ( ( char * )
V_9 -> V_68 [ 2 ] . V_69 )
+ 0x1034 + ( 0x4000 * ( V_42 & 3 ) ) ) ;
V_48 -> V_70 = V_67 [ 0 ] ;
V_48 -> V_71 = V_67 [ 1 ] ;
V_48 -> V_72 = V_67 [ 3 ] ;
V_48 -> V_73 = V_67 [ 4 ] ;
}
F_20 ( V_9 , 0 ) ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
return 0 ;
default:
V_41 = - V_74 ;
}
F_22 ( 300 ) ;
return V_41 ;
}
void F_23 ( struct V_75 * V_76 )
{
int V_16 ;
struct V_8 * V_9 ;
struct V_31 * V_32 = F_24 ( V_76 ) ;
V_9 = V_32 -> V_35 ;
V_54 -> V_77 ( V_9 ) ;
for ( V_16 = 0 ; V_16 < V_9 -> V_78 -> V_79 ; ++ V_16 )
V_54 -> V_55 ( V_9 , V_16 ) ;
}
int F_25 ( struct V_75 * V_76 , unsigned long time )
{
struct V_31 * V_34 = F_24 ( V_76 ) ;
if ( time < V_80 )
return 0 ;
F_26 ( V_34 ) ;
return 1 ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_81 ( V_9 , V_6 ) ;
}
T_1 F_28 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_82 * V_83 = V_2 -> V_84 ;
if ( V_83 ) {
if ( V_83 -> V_85 . V_86 == V_87 ||
V_83 -> V_85 . V_86 == V_88 ) {
* V_3 = V_83 -> V_3 ;
return 1 ;
}
}
return 0 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_89 ( V_9 , V_6 ) ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_5 * V_6 , struct V_90 * V_91 )
{
return V_54 -> V_92 ( V_9 , V_6 , V_91 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_54 -> V_93 ( V_9 , V_6 ) ;
}
static int F_32 ( struct V_29 * V_30 )
{
struct V_29 * V_18 = V_30 -> V_94 ;
if ( ! V_18 )
return V_30 -> V_33 -> V_43 ;
while ( V_18 ) {
struct V_29 * V_95 = V_18 -> V_94 ;
if ( ! V_95 )
return V_18 -> V_33 -> V_43 ;
V_18 = V_18 -> V_94 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , const int V_96 ,
T_6 V_97 , int V_98 , struct V_90 * V_91 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 ;
struct V_99 * V_100 ;
struct V_101 * V_33 = NULL ;
struct V_1 * V_102 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_41 , V_103 = 0 ;
T_1 V_104 = V_96 ;
unsigned long V_47 = 0 ;
if ( ! V_30 -> V_33 ) {
struct V_105 * V_106 = & V_102 -> V_107 ;
V_106 -> V_108 = V_109 ;
V_106 -> V_110 = V_111 ;
if ( V_30 -> V_112 != V_113 )
V_102 -> V_114 ( V_102 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_30 ) ;
F_34 ( V_9 , F_12 ( L_2 ) ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
do {
V_30 = V_102 -> V_30 ;
V_100 = V_30 -> V_115 ;
V_33 = & V_9 -> V_33 [ F_32 ( V_30 ) ] ;
if ( F_35 ( V_100 ) || ! V_33 -> V_116 ) {
if ( F_36 ( V_102 -> V_117 ) ) {
struct V_105 * V_118 = & V_102 -> V_107 ;
V_118 -> V_108 = V_109 ;
V_118 -> V_110 = V_111 ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
V_102 -> V_114 ( V_102 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
if ( V_104 > 1 )
V_102 = F_37 ( V_102 -> V_119 . V_120 ,
struct V_1 , V_119 ) ;
continue;
} else {
struct V_105 * V_118 = & V_102 -> V_107 ;
V_118 -> V_108 = V_109 ;
V_118 -> V_110 = V_111 ;
V_102 -> V_114 ( V_102 ) ;
if ( V_104 > 1 )
V_102 = F_37 ( V_102 -> V_119 . V_120 ,
struct V_1 , V_119 ) ;
continue;
}
}
V_41 = F_7 ( V_9 , & V_3 ) ;
if ( V_41 )
goto V_121;
V_6 = & V_9 -> V_122 [ V_3 ] ;
if ( ! F_36 ( V_102 -> V_117 ) ) {
if ( V_102 -> V_123 ) {
V_103 = F_38 ( V_9 -> V_30 ,
V_102 -> V_124 ,
V_102 -> V_123 ,
V_102 -> V_125 ) ;
if ( ! V_103 ) {
V_41 = - V_126 ;
goto V_127;
}
}
} else {
V_103 = V_102 -> V_123 ;
}
V_102 -> V_4 = V_6 ;
V_6 -> V_103 = V_103 ;
V_6 -> V_7 = V_3 ;
V_6 -> V_2 = V_102 ;
switch ( V_102 -> V_117 ) {
case V_128 :
V_41 = F_27 ( V_9 , V_6 ) ;
break;
case V_129 :
if ( V_98 )
V_41 = F_30 ( V_9 ,
V_6 , V_91 ) ;
else
V_41 = F_31 ( V_9 , V_6 ) ;
break;
case V_130 :
case V_131 :
case V_130 | V_131 :
V_41 = F_29 ( V_9 , V_6 ) ;
break;
default:
F_39 ( V_132 , V_9 -> V_30 ,
L_3 ,
V_102 -> V_117 ) ;
V_41 = - V_66 ;
break;
}
if ( V_41 ) {
F_34 ( V_9 ,
F_12 ( L_4 , V_41 ) ) ;
goto V_127;
}
F_40 ( & V_102 -> V_133 ) ;
V_102 -> V_134 |= V_135 ;
F_41 ( & V_102 -> V_133 ) ;
V_100 -> V_136 ++ ;
if ( V_104 > 1 )
V_102 = F_37 ( V_102 -> V_119 . V_120 , struct V_1 , V_119 ) ;
} while ( -- V_104 );
V_41 = 0 ;
goto V_137;
V_127:
F_4 ( V_9 , V_3 ) ;
V_121:
F_39 ( V_132 , V_9 -> V_30 , L_5 , V_41 ) ;
if ( ! F_36 ( V_102 -> V_117 ) )
if ( V_103 )
F_42 ( V_9 -> V_30 , V_102 -> V_124 , V_103 ,
V_102 -> V_125 ) ;
V_137:
F_21 ( & V_9 -> V_65 , V_47 ) ;
return V_41 ;
}
int F_43 ( struct V_1 * V_2 , const int V_96 ,
T_6 V_97 )
{
return F_33 ( V_2 , V_96 , V_97 , 0 , NULL ) ;
}
void F_44 ( struct V_8 * V_9 , T_1 V_138 )
{
F_2 ( V_9 , V_138 ) ;
}
void F_45 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_138 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_36 ( V_2 -> V_117 ) )
if ( V_6 -> V_103 )
F_42 ( V_9 -> V_30 , V_2 -> V_124 ,
V_2 -> V_123 , V_2 -> V_125 ) ;
switch ( V_2 -> V_117 ) {
case V_128 :
F_42 ( V_9 -> V_30 , & V_2 -> V_139 . V_140 , 1 ,
V_141 ) ;
F_42 ( V_9 -> V_30 , & V_2 -> V_139 . V_81 , 1 ,
V_142 ) ;
break;
case V_130 :
case V_131 :
case V_129 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
V_6 -> V_143 = 0 ;
F_44 ( V_9 , V_138 ) ;
}
struct V_99 * F_46 ( struct V_8 * V_9 )
{
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_144 ; V_30 ++ ) {
if ( V_9 -> V_145 [ V_30 ] . V_112 == V_146 ) {
V_9 -> V_145 [ V_30 ] . V_43 = V_30 ;
return & V_9 -> V_145 [ V_30 ] ;
}
}
if ( V_30 == V_144 ) {
F_47 ( V_9 ,
F_12 ( L_6 ,
V_144 ) ) ;
}
return NULL ;
}
static void F_48 ( struct V_99 * V_100 )
{
T_1 V_43 = V_100 -> V_43 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_43 = V_43 ;
V_100 -> V_112 = V_146 ;
V_100 -> V_147 = V_144 ;
V_100 -> V_148 = NULL ;
}
static int F_49 ( struct V_29 * V_30 )
{
unsigned long V_47 = 0 ;
int V_149 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_29 * V_150 = V_30 -> V_94 ;
struct V_99 * V_99 ;
F_17 ( V_46 ) ;
T_1 V_151 = 0 ;
V_9 = F_15 ( V_30 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
V_99 = F_46 ( V_9 ) ;
if ( ! V_99 ) {
V_149 = - 1 ;
goto V_152;
}
V_99 -> V_148 = V_30 ;
V_30 -> V_115 = V_99 ;
V_99 -> V_112 = V_30 -> V_112 ;
V_99 -> V_153 = & V_46 ;
if ( V_150 && F_50 ( V_150 -> V_112 ) ) {
int V_42 ;
struct V_154 * V_48 ;
for ( V_42 = 0 ; V_42 < V_150 -> V_155 . V_156 ;
V_42 ++ ) {
V_48 = & V_150 -> V_155 . V_154 [ V_42 ] ;
if ( F_51 ( V_48 -> V_157 )
== F_51 ( V_30 -> V_158 ) ) {
V_99 -> V_159 = V_42 ;
break;
}
}
if ( V_42 == V_150 -> V_155 . V_156 ) {
F_47 ( V_9 ,
F_12 ( L_7
L_8 , F_51 ( V_30 -> V_158 ) ,
F_51 ( V_150 -> V_158 ) ) ) ;
V_149 = - 1 ;
}
} else {
if ( V_30 -> V_112 == V_113 ) {
V_99 -> V_159 =
V_30 -> V_160 -> V_161 . V_162 ;
V_151 = 1 ;
}
}
F_52 ( V_9 , F_12 ( L_9 ) ) ;
V_54 -> V_163 ( V_9 , V_99 , V_151 ) ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
F_18 ( & V_46 ) ;
if ( V_30 -> V_112 == V_164 )
F_22 ( 50 ) ;
V_9 -> V_47 = V_165 ;
return 0 ;
V_152:
F_21 ( & V_9 -> V_65 , V_47 ) ;
return V_149 ;
}
int F_53 ( struct V_29 * V_30 )
{
return F_49 ( V_30 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ! F_55 ( & V_2 -> V_166 ) )
return;
F_56 ( & V_2 -> V_46 ) ;
}
static void F_57 ( unsigned long V_167 )
{
struct V_1 * V_2 = (struct V_1 * ) V_167 ;
V_2 -> V_134 |= V_168 ;
F_56 ( & V_2 -> V_46 ) ;
}
static int F_58 ( struct V_29 * V_30 ,
void * V_169 , T_1 V_170 , struct V_90 * V_91 )
{
int V_149 , V_171 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
for ( V_171 = 0 ; V_171 < 3 ; V_171 ++ ) {
V_2 = F_59 ( V_172 ) ;
if ( ! V_2 )
return - V_126 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_117 = V_30 -> V_173 ;
memcpy ( & V_2 -> V_174 , V_169 , V_170 ) ;
V_2 -> V_114 = F_54 ;
V_2 -> V_166 . V_167 = ( unsigned long ) V_2 ;
V_2 -> V_166 . V_175 = F_57 ;
V_2 -> V_166 . V_176 = V_177 + V_178 * V_80 ;
F_60 ( & V_2 -> V_166 ) ;
V_149 = F_33 ( V_2 , 1 , V_172 , 1 , V_91 ) ;
if ( V_149 ) {
F_55 ( & V_2 -> V_166 ) ;
F_47 ( V_9 ,
F_12 ( L_10
L_11 ) ) ;
goto V_179;
}
F_18 ( & V_2 -> V_46 ) ;
V_149 = - V_180 ;
if ( ( V_2 -> V_134 & V_168 ) ) {
if ( ! ( V_2 -> V_134 & V_181 ) ) {
F_47 ( V_9 ,
F_12 ( L_12 ,
V_91 -> V_91 ) ) ;
goto V_179;
}
}
if ( V_2 -> V_107 . V_108 == V_182 &&
V_2 -> V_107 . V_110 == V_183 ) {
V_149 = V_184 ;
break;
}
if ( V_2 -> V_107 . V_108 == V_182 &&
V_2 -> V_107 . V_110 == V_185 ) {
V_149 = V_2 -> V_107 . V_186 ;
break;
}
if ( V_2 -> V_107 . V_108 == V_182 &&
V_2 -> V_107 . V_110 == V_187 ) {
F_47 ( V_9 ,
F_12 ( L_13 ) ) ;
V_149 = - V_188 ;
break;
} else {
F_61 ( V_9 ,
F_12 ( L_14
L_15 ,
F_51 ( V_30 -> V_158 ) ,
V_2 -> V_107 . V_108 ,
V_2 -> V_107 . V_110 ) ) ;
F_62 ( V_2 ) ;
V_2 = NULL ;
}
}
V_179:
F_63 ( V_171 == 3 && V_2 != NULL ) ;
F_62 ( V_2 ) ;
return V_149 ;
}
static int
F_64 ( struct V_8 * V_9 ,
struct V_99 * V_100 , struct V_29 * V_30 , T_1 V_151 ,
T_1 V_189 )
{
int V_149 , V_171 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_171 = 0 ; V_171 < 3 ; V_171 ++ ) {
V_2 = F_59 ( V_172 ) ;
if ( ! V_2 )
return - V_126 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_117 = V_30 -> V_173 ;
V_2 -> V_114 = F_54 ;
V_2 -> V_166 . V_167 = ( unsigned long ) V_2 ;
V_2 -> V_166 . V_175 = F_57 ;
V_2 -> V_166 . V_176 = V_177 + V_178 * V_80 ;
F_60 ( & V_2 -> V_166 ) ;
V_149 = F_7 ( V_9 , & V_7 ) ;
if ( V_149 )
return V_149 ;
V_6 = & V_9 -> V_122 [ V_7 ] ;
V_6 -> V_190 = V_100 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_149 = V_54 -> V_191 ( V_9 ,
V_100 , V_151 , V_189 , V_7 ) ;
if ( V_149 ) {
F_55 ( & V_2 -> V_166 ) ;
F_47 ( V_9 ,
F_12 ( L_10
L_11 ) ) ;
goto V_179;
}
F_18 ( & V_2 -> V_46 ) ;
V_149 = V_180 ;
if ( ( V_2 -> V_134 & V_168 ) ) {
if ( ! ( V_2 -> V_134 & V_181 ) ) {
F_47 ( V_9 ,
F_12 ( L_16 ) ) ;
goto V_179;
}
}
if ( V_2 -> V_107 . V_108 == V_182 &&
V_2 -> V_107 . V_110 == V_183 ) {
V_149 = V_184 ;
break;
} else {
F_61 ( V_9 ,
F_12 ( L_17
L_15 ,
F_51 ( V_30 -> V_158 ) ,
V_2 -> V_107 . V_108 ,
V_2 -> V_107 . V_110 ) ) ;
F_62 ( V_2 ) ;
V_2 = NULL ;
}
}
V_179:
F_63 ( V_171 == 3 && V_2 != NULL ) ;
F_62 ( V_2 ) ;
return V_149 ;
}
static void F_65 ( struct V_29 * V_30 )
{
unsigned long V_47 = 0 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_99 * V_100 = V_30 -> V_115 ;
V_9 = F_15 ( V_30 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
F_7 ( V_9 , & V_3 ) ;
if ( V_100 ) {
T_1 V_147 = V_100 -> V_147 ;
F_52 ( V_9 ,
F_12 ( L_18 ,
V_100 -> V_147 , V_100 -> V_112 ) ) ;
if ( V_100 -> V_136 ) {
F_21 ( & V_9 -> V_65 , V_47 ) ;
F_64 ( V_9 , V_100 ,
V_30 , 1 , 0 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
}
V_54 -> V_192 ( V_9 , V_147 ) ;
F_48 ( V_100 ) ;
} else {
F_52 ( V_9 ,
F_12 ( L_19 ) ) ;
}
V_30 -> V_115 = NULL ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
}
void F_66 ( struct V_29 * V_30 )
{
F_65 ( V_30 ) ;
}
static int F_67 ( struct V_29 * V_30 ,
T_7 * V_193 , struct V_90 * V_91 )
{
struct V_194 V_174 ;
if ( ! ( V_30 -> V_173 & V_129 ) )
return V_195 ;
strncpy ( ( T_7 * ) & V_174 . V_196 , V_193 , 8 ) ;
return F_58 ( V_30 , & V_174 , sizeof( V_174 ) ,
V_91 ) ;
}
void F_68 (
struct V_8 * V_9 ,
struct V_1 * V_197 ,
struct V_99 * V_198 )
{
int V_16 ;
unsigned long V_47 ;
if ( V_9 == NULL )
return;
F_19 ( & V_9 -> V_65 , V_47 ) ;
for ( V_16 = 0 ; V_16 < V_199 ; V_16 ++ ) {
struct V_1 * V_2 ;
struct V_105 * V_118 ;
struct V_99 * V_100 ;
unsigned long V_200 ;
T_1 V_3 ;
struct V_5 * V_6 = & V_9 -> V_122 [ V_16 ] ;
V_100 = V_6 -> V_190 ;
if ( ! V_100 || ( V_100 -> V_112 == V_146 ) )
continue;
if ( ! V_198 ) {
T_8 V_201 = ( T_8 ) V_100
- ( T_8 ) & V_9 -> V_145 ;
if ( ( ( V_201 % sizeof( * V_100 ) ) != 0 )
|| ( ( V_201 / sizeof( * V_100 ) ) >= V_144 ) )
continue;
} else if ( V_100 != V_198 )
continue;
V_3 = V_6 -> V_7 ;
if ( ! V_3 || ( V_3 == 0xFFFFFFFF ) )
continue;
V_2 = V_6 -> V_2 ;
if ( ! V_2 || ! V_2 -> V_114 )
continue;
if ( V_197 && ( V_2 != V_197 ) )
continue;
V_118 = & V_2 -> V_107 ;
V_118 -> V_108 = V_182 ;
V_118 -> V_110 = V_202 ;
V_118 -> V_203 = V_204 ;
if ( V_100 )
V_100 -> V_136 -- ;
F_19 ( & V_2 -> V_133 , V_200 ) ;
V_2 -> V_134 &= ~ V_205 ;
V_2 -> V_134 &= ~ V_135 ;
V_2 -> V_134 |= V_181 ;
if ( F_69 ( ( V_2 -> V_134
& V_168 ) ) ) {
F_21 ( & V_2 -> V_133 ,
V_200 ) ;
F_45 ( V_9 , V_2 , V_6 , V_3 ) ;
} else {
F_21 ( & V_2 -> V_133 ,
V_200 ) ;
F_45 ( V_9 , V_2 , V_6 , V_3 ) ;
F_70 () ;
F_21 ( & V_9 -> V_65 , V_47 ) ;
V_2 -> V_114 ( V_2 ) ;
F_19 ( & V_9 -> V_65 , V_47 ) ;
}
}
F_21 ( & V_9 -> V_65 , V_47 ) ;
}
int F_71 ( struct V_29 * V_30 )
{
int V_41 = V_180 ;
struct V_99 * V_100 ;
struct V_8 * V_9 ;
struct V_37 * V_48 ;
if ( ! V_30 || ! V_30 -> V_115 )
return - 1 ;
V_100 = V_30 -> V_115 ;
V_9 = F_15 ( V_30 ) ;
V_48 = F_72 ( V_30 ) ;
if ( F_73 ( V_30 ) ) {
F_17 ( V_206 ) ;
if ( F_74 ( V_48 ) ) {
V_41 = 0 ;
goto V_207;
}
V_41 = F_75 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
V_41 = F_64 ( V_9 , V_100 ,
V_30 , 1 , 0 ) ;
V_100 -> V_208 = & V_206 ;
V_41 = V_54 -> V_209 ( V_9 ,
V_100 , 0x01 ) ;
F_18 ( & V_206 ) ;
} else {
V_41 = F_75 ( V_48 , 1 ) ;
F_22 ( 2000 ) ;
}
F_61 ( V_9 , F_12 ( L_20 ,
V_100 -> V_147 , V_41 ) ) ;
V_207:
F_76 ( V_48 ) ;
return V_41 ;
}
int F_77 ( struct V_29 * V_30 , T_7 * V_193 )
{
int V_41 = V_180 ;
struct V_90 V_210 ;
struct V_99 * V_100 = V_30 -> V_115 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
if ( F_73 ( V_30 ) ) {
struct V_37 * V_48 = F_72 ( V_30 ) ;
V_41 = F_64 ( V_9 , V_100 ,
V_30 , 1 , 0 ) ;
V_41 = F_75 ( V_48 , 1 ) ;
F_76 ( V_48 ) ;
V_41 = V_54 -> V_209 ( V_9 ,
V_100 , 0x01 ) ;
F_22 ( 2000 ) ;
} else {
V_210 . V_91 = V_211 ;
V_41 = F_67 ( V_30 , V_193 , & V_210 ) ;
}
F_61 ( V_9 , F_12 ( L_21 ,
V_100 -> V_147 , V_41 ) ) ;
return V_41 ;
}
int F_78 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_16 = 0 ;
struct V_212 V_193 ;
struct V_90 V_210 ;
int V_41 = V_180 ;
if ( F_69 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
if ( V_2 -> V_117 & V_129 ) {
struct V_213 * V_214 = V_2 -> V_84 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 =
F_15 ( V_30 ) ;
F_79 ( V_214 -> V_190 -> V_193 , & V_193 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
V_41 = V_180 ;
return V_41 ;
}
F_61 ( V_9 , F_12 ( L_22 ) ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_80 ( V_215 L_23 , V_214 -> V_214 [ V_16 ] ) ;
F_80 ( V_215 L_24 ) ;
V_210 . V_91 = V_216 ;
V_210 . V_217 = V_3 ;
V_41 = F_67 ( V_30 , V_193 . V_212 , & V_210 ) ;
switch ( V_41 ) {
case V_218 :
F_61 ( V_9 ,
F_12 ( L_25 ) ) ;
break;
case V_180 :
case V_184 :
F_61 ( V_9 ,
F_12 ( L_26
L_27 ) ) ;
break;
}
}
F_12 ( L_28 , V_41 ) ;
return V_41 ;
}
int F_81 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_147 ;
struct V_29 * V_30 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_212 V_193 ;
struct V_99 * V_100 ;
struct V_90 V_210 ;
int V_41 = V_180 ;
if ( F_69 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
F_19 ( & V_2 -> V_133 , V_47 ) ;
if ( V_2 -> V_134 & V_181 ) {
F_21 ( & V_2 -> V_133 , V_47 ) ;
V_41 = V_184 ;
goto V_207;
}
F_21 ( & V_2 -> V_133 , V_47 ) ;
if ( V_2 -> V_117 & V_129 ) {
struct V_213 * V_214 = V_2 -> V_84 ;
V_30 = V_2 -> V_30 ;
V_6 = V_2 -> V_4 ;
V_100 = V_30 -> V_115 ;
V_9 = F_15 ( V_30 ) ;
F_79 ( V_214 -> V_190 -> V_193 , & V_193 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_80 ( V_215 L_29 , V_219 ) ;
V_41 = V_180 ;
return V_41 ;
}
V_147 = V_100 -> V_147 ;
F_61 ( V_9 ,
F_12 ( L_30 , V_147 ) ) ;
V_210 . V_91 = V_220 ;
V_210 . V_217 = V_3 ;
V_41 = F_67 ( V_30 , V_193 . V_212 , & V_210 ) ;
F_64 ( V_9 , V_100 ,
V_100 -> V_148 , 0 , V_3 ) ;
} else if ( V_2 -> V_117 & V_130 ||
V_2 -> V_117 & V_131 ) {
V_30 = V_2 -> V_30 ;
V_100 = V_30 -> V_115 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_80 ( V_215 L_29 , V_219 ) ;
V_41 = V_180 ;
return V_41 ;
}
V_41 = F_64 ( V_9 , V_100 ,
V_100 -> V_148 , 0 , V_3 ) ;
} else if ( V_2 -> V_117 & V_128 ) {
V_30 = V_2 -> V_30 ;
V_100 = V_30 -> V_115 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_80 ( V_215 L_29 , V_219 ) ;
V_41 = V_180 ;
return V_41 ;
}
V_41 = F_64 ( V_9 , V_100 ,
V_100 -> V_148 , 0 , V_3 ) ;
}
V_207:
if ( V_41 != V_184 )
F_12 ( L_31 , V_41 ) ;
return V_41 ;
}
int F_82 ( struct V_29 * V_30 , T_7 * V_193 )
{
int V_41 = V_180 ;
struct V_90 V_210 ;
V_210 . V_91 = V_221 ;
V_41 = F_67 ( V_30 , V_193 , & V_210 ) ;
return V_41 ;
}
int F_83 ( struct V_29 * V_30 , T_7 * V_193 )
{
int V_41 = V_180 ;
struct V_90 V_210 ;
V_210 . V_91 = V_222 ;
V_41 = F_67 ( V_30 , V_193 , & V_210 ) ;
return V_41 ;
}
int F_84 ( struct V_29 * V_30 , T_7 * V_193 )
{
int V_41 = V_180 ;
struct V_90 V_210 ;
struct V_99 * V_100 = V_30 -> V_115 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
F_61 ( V_9 ,
F_12 ( L_32 ,
V_100 -> V_147 ) ) ;
V_210 . V_91 = V_223 ;
V_41 = F_67 ( V_30 , V_193 , & V_210 ) ;
return V_41 ;
}
