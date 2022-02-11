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
static int F_31 ( struct V_1 * V_2 ,
T_6 V_98 , int V_99 , struct V_92 * V_93 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_8 * V_9 ;
struct V_100 * V_101 ;
struct V_102 * V_34 = NULL ;
struct V_1 * V_103 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_42 , V_104 = 0 ;
unsigned long V_13 = 0 ;
if ( ! V_31 -> V_34 ) {
struct V_105 * V_106 = & V_103 -> V_107 ;
V_106 -> V_108 = V_109 ;
V_106 -> V_110 = V_111 ;
if ( V_31 -> V_112 != V_113 )
V_103 -> V_114 ( V_103 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_31 ) ;
F_32 ( V_9 , F_12 ( L_2 ) ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
do {
V_31 = V_103 -> V_31 ;
V_101 = V_31 -> V_115 ;
V_34 = & V_9 -> V_34 [ F_30 ( V_31 ) ] ;
if ( F_33 ( V_101 ) || ! V_34 -> V_116 ) {
if ( F_34 ( V_103 -> V_117 ) ) {
struct V_105 * V_118 = & V_103 -> V_107 ;
V_118 -> V_108 = V_109 ;
V_118 -> V_110 = V_111 ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
V_103 -> V_114 ( V_103 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
continue;
} else {
struct V_105 * V_118 = & V_103 -> V_107 ;
V_118 -> V_108 = V_109 ;
V_118 -> V_110 = V_111 ;
V_103 -> V_114 ( V_103 ) ;
continue;
}
}
V_42 = F_4 ( V_9 , & V_3 ) ;
if ( V_42 )
goto V_119;
V_6 = & V_9 -> V_120 [ V_3 ] ;
if ( ! F_34 ( V_103 -> V_117 ) ) {
if ( V_103 -> V_121 ) {
V_104 = F_35 ( V_9 -> V_31 ,
V_103 -> V_122 ,
V_103 -> V_121 ,
V_103 -> V_123 ) ;
if ( ! V_104 ) {
V_42 = - V_124 ;
goto V_125;
}
}
} else {
V_104 = V_103 -> V_121 ;
}
V_103 -> V_4 = V_6 ;
V_6 -> V_104 = V_104 ;
V_6 -> V_7 = V_3 ;
V_6 -> V_2 = V_103 ;
V_6 -> V_126 = V_101 ;
switch ( V_103 -> V_117 ) {
case V_127 :
V_42 = F_25 ( V_9 , V_6 ) ;
break;
case V_128 :
if ( V_99 )
V_42 = F_28 ( V_9 ,
V_6 , V_93 ) ;
else
V_42 = F_29 ( V_9 , V_6 ) ;
break;
case V_129 :
case V_130 :
V_42 = F_27 ( V_9 , V_6 ) ;
break;
default:
F_36 ( V_131 , V_9 -> V_31 ,
L_3 ,
V_103 -> V_117 ) ;
V_42 = - V_68 ;
break;
}
if ( V_42 ) {
F_32 ( V_9 ,
F_12 ( L_4 , V_42 ) ) ;
goto V_125;
}
F_37 ( & V_103 -> V_132 ) ;
V_103 -> V_133 |= V_134 ;
F_38 ( & V_103 -> V_132 ) ;
V_101 -> V_135 ++ ;
} while ( 0 );
V_42 = 0 ;
goto V_136;
V_125:
F_2 ( V_9 , V_3 ) ;
V_119:
F_36 ( V_131 , V_9 -> V_31 , L_5 , V_42 ) ;
if ( ! F_34 ( V_103 -> V_117 ) )
if ( V_104 )
F_39 ( V_9 -> V_31 , V_103 -> V_122 , V_104 ,
V_103 -> V_123 ) ;
V_136:
F_7 ( & V_9 -> V_65 , V_13 ) ;
return V_42 ;
}
int F_40 ( struct V_1 * V_2 , T_6 V_98 )
{
return F_31 ( V_2 , V_98 , 0 , NULL ) ;
}
void F_41 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_137 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_34 ( V_2 -> V_117 ) )
if ( V_6 -> V_104 )
F_39 ( V_9 -> V_31 , V_2 -> V_122 ,
V_2 -> V_121 , V_2 -> V_123 ) ;
switch ( V_2 -> V_117 ) {
case V_127 :
F_39 ( V_9 -> V_31 , & V_2 -> V_138 . V_139 , 1 ,
V_140 ) ;
F_39 ( V_9 -> V_31 , & V_2 -> V_138 . V_83 , 1 ,
V_141 ) ;
break;
case V_129 :
case V_130 :
case V_128 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
V_6 -> V_142 = 0 ;
F_2 ( V_9 , V_137 ) ;
}
struct V_100 * F_42 ( struct V_8 * V_9 )
{
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_143 ; V_31 ++ ) {
if ( V_9 -> V_144 [ V_31 ] . V_112 == V_145 ) {
V_9 -> V_144 [ V_31 ] . V_44 = V_31 ;
return & V_9 -> V_144 [ V_31 ] ;
}
}
if ( V_31 == V_143 ) {
F_43 ( V_9 ,
F_12 ( L_6 ,
V_143 ) ) ;
}
return NULL ;
}
struct V_100 * F_44 ( struct V_8 * V_9 ,
T_1 V_146 )
{
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_143 ; V_31 ++ ) {
if ( V_9 -> V_144 [ V_31 ] . V_146 == V_146 )
return & V_9 -> V_144 [ V_31 ] ;
}
if ( V_31 == V_143 ) {
F_43 ( V_9 , F_12 ( L_7
L_8 ) ) ;
}
return NULL ;
}
static void F_45 ( struct V_100 * V_101 )
{
T_1 V_44 = V_101 -> V_44 ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_44 = V_44 ;
V_101 -> V_112 = V_145 ;
V_101 -> V_146 = V_143 ;
V_101 -> V_147 = NULL ;
}
static int F_46 ( struct V_30 * V_31 )
{
unsigned long V_13 = 0 ;
int V_148 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_30 * V_149 = V_31 -> V_96 ;
struct V_100 * V_100 ;
F_17 ( V_47 ) ;
T_1 V_150 = 0 ;
V_9 = F_15 ( V_31 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
V_100 = F_42 ( V_9 ) ;
if ( ! V_100 ) {
V_148 = - 1 ;
goto V_151;
}
V_100 -> V_147 = V_31 ;
V_31 -> V_115 = V_100 ;
V_100 -> V_112 = V_31 -> V_112 ;
V_100 -> V_152 = & V_47 ;
if ( V_149 && F_47 ( V_149 -> V_112 ) ) {
int V_43 ;
struct V_153 * V_48 ;
for ( V_43 = 0 ; V_43 < V_149 -> V_154 . V_155 ;
V_43 ++ ) {
V_48 = & V_149 -> V_154 . V_153 [ V_43 ] ;
if ( F_48 ( V_48 -> V_156 )
== F_48 ( V_31 -> V_157 ) ) {
V_100 -> V_158 = V_43 ;
break;
}
}
if ( V_43 == V_149 -> V_154 . V_155 ) {
F_43 ( V_9 ,
F_12 ( L_9
L_10 , F_48 ( V_31 -> V_157 ) ,
F_48 ( V_149 -> V_157 ) ) ) ;
V_148 = - 1 ;
}
} else {
if ( V_31 -> V_112 == V_113 ) {
V_100 -> V_158 =
V_31 -> V_159 -> V_160 . V_161 ;
V_150 = 1 ;
}
}
F_49 ( V_9 , F_12 ( L_11 ) ) ;
V_54 -> V_162 ( V_9 , V_100 , V_150 ) ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
F_18 ( & V_47 ) ;
if ( V_31 -> V_112 == V_163 )
F_20 ( 50 ) ;
V_9 -> V_13 = V_164 ;
return 0 ;
V_151:
F_7 ( & V_9 -> V_65 , V_13 ) ;
return V_148 ;
}
int F_50 ( struct V_30 * V_31 )
{
return F_46 ( V_31 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
if ( ! F_52 ( & V_2 -> V_165 -> V_166 ) )
return;
F_53 ( & V_2 -> V_165 -> V_47 ) ;
}
static void F_54 ( unsigned long V_167 )
{
struct V_1 * V_2 = (struct V_1 * ) V_167 ;
V_2 -> V_133 |= V_168 ;
F_53 ( & V_2 -> V_165 -> V_47 ) ;
}
static int F_55 ( struct V_30 * V_31 ,
void * V_169 , T_1 V_170 , struct V_92 * V_93 )
{
int V_148 , V_171 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
struct V_100 * V_101 = V_31 -> V_115 ;
F_17 ( V_172 ) ;
for ( V_171 = 0 ; V_171 < 3 ; V_171 ++ ) {
V_2 = F_56 ( V_173 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_117 = V_31 -> V_174 ;
memcpy ( & V_2 -> V_175 , V_169 , V_170 ) ;
V_2 -> V_114 = F_51 ;
V_2 -> V_165 -> V_166 . V_167 = ( unsigned long ) V_2 ;
V_2 -> V_165 -> V_166 . V_176 = F_54 ;
V_2 -> V_165 -> V_166 . V_177 = V_178 + V_179 * V_82 ;
F_57 ( & V_2 -> V_165 -> V_166 ) ;
V_148 = F_31 ( V_2 , V_173 , 1 , V_93 ) ;
if ( V_148 ) {
F_52 ( & V_2 -> V_165 -> V_166 ) ;
F_43 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_180;
}
F_18 ( & V_2 -> V_165 -> V_47 ) ;
if ( V_9 -> V_66 != V_67 ) {
V_101 -> V_181 = & V_172 ;
V_54 -> V_182 ( V_9 ,
V_101 , 0x01 ) ;
F_18 ( & V_172 ) ;
}
V_148 = - V_183 ;
if ( ( V_2 -> V_133 & V_168 ) ) {
if ( ! ( V_2 -> V_133 & V_184 ) ) {
F_43 ( V_9 ,
F_12 ( L_14 ,
V_93 -> V_93 ) ) ;
goto V_180;
}
}
if ( V_2 -> V_107 . V_108 == V_185 &&
V_2 -> V_107 . V_110 == V_186 ) {
V_148 = V_187 ;
break;
}
if ( V_2 -> V_107 . V_108 == V_185 &&
V_2 -> V_107 . V_110 == V_188 ) {
V_148 = V_2 -> V_107 . V_189 ;
break;
}
if ( V_2 -> V_107 . V_108 == V_185 &&
V_2 -> V_107 . V_110 == V_190 ) {
F_43 ( V_9 ,
F_12 ( L_15 ) ) ;
V_148 = - V_191 ;
break;
} else {
F_58 ( V_9 ,
F_12 ( L_16
L_17 ,
F_48 ( V_31 -> V_157 ) ,
V_2 -> V_107 . V_108 ,
V_2 -> V_107 . V_110 ) ) ;
F_59 ( V_2 ) ;
V_2 = NULL ;
}
}
V_180:
F_60 ( V_171 == 3 && V_2 != NULL ) ;
F_59 ( V_2 ) ;
return V_148 ;
}
static int
F_61 ( struct V_8 * V_9 ,
struct V_100 * V_101 , struct V_30 * V_31 , T_1 V_150 ,
T_1 V_192 )
{
int V_148 , V_171 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_171 = 0 ; V_171 < 3 ; V_171 ++ ) {
V_2 = F_56 ( V_173 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_117 = V_31 -> V_174 ;
V_2 -> V_114 = F_51 ;
V_2 -> V_165 -> V_166 . V_167 = ( unsigned long ) V_2 ;
V_2 -> V_165 -> V_166 . V_176 = F_54 ;
V_2 -> V_165 -> V_166 . V_177 = V_178 + V_179 * V_82 ;
F_57 ( & V_2 -> V_165 -> V_166 ) ;
V_148 = F_4 ( V_9 , & V_7 ) ;
if ( V_148 )
return V_148 ;
V_6 = & V_9 -> V_120 [ V_7 ] ;
V_6 -> V_126 = V_101 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_148 = V_54 -> V_193 ( V_9 ,
V_101 , V_150 , V_192 , V_7 ) ;
if ( V_148 ) {
F_52 ( & V_2 -> V_165 -> V_166 ) ;
F_43 ( V_9 ,
F_12 ( L_12
L_13 ) ) ;
goto V_180;
}
F_18 ( & V_2 -> V_165 -> V_47 ) ;
V_148 = V_183 ;
if ( ( V_2 -> V_133 & V_168 ) ) {
if ( ! ( V_2 -> V_133 & V_184 ) ) {
F_43 ( V_9 ,
F_12 ( L_18 ) ) ;
goto V_180;
}
}
if ( V_2 -> V_107 . V_108 == V_185 &&
V_2 -> V_107 . V_110 == V_186 ) {
V_148 = V_187 ;
break;
} else {
F_58 ( V_9 ,
F_12 ( L_19
L_17 ,
F_48 ( V_31 -> V_157 ) ,
V_2 -> V_107 . V_108 ,
V_2 -> V_107 . V_110 ) ) ;
F_59 ( V_2 ) ;
V_2 = NULL ;
}
}
V_180:
F_60 ( V_171 == 3 && V_2 != NULL ) ;
F_59 ( V_2 ) ;
return V_148 ;
}
static void F_62 ( struct V_30 * V_31 )
{
unsigned long V_13 = 0 ;
struct V_8 * V_9 ;
struct V_100 * V_101 = V_31 -> V_115 ;
V_9 = F_15 ( V_31 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
if ( V_101 ) {
T_1 V_146 = V_101 -> V_146 ;
F_49 ( V_9 ,
F_12 ( L_20 ,
V_101 -> V_146 , V_101 -> V_112 ) ) ;
if ( V_101 -> V_135 ) {
F_7 ( & V_9 -> V_65 , V_13 ) ;
F_61 ( V_9 , V_101 ,
V_31 , 1 , 0 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
}
V_54 -> V_194 ( V_9 , V_146 ) ;
F_45 ( V_101 ) ;
} else {
F_49 ( V_9 ,
F_12 ( L_21 ) ) ;
}
V_31 -> V_115 = NULL ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
}
void F_63 ( struct V_30 * V_31 )
{
F_62 ( V_31 ) ;
}
static int F_64 ( struct V_30 * V_31 ,
T_7 * V_195 , struct V_92 * V_93 )
{
struct V_196 V_175 ;
if ( ! ( V_31 -> V_174 & V_128 ) )
return V_197 ;
strncpy ( ( T_7 * ) & V_175 . V_198 , V_195 , 8 ) ;
return F_55 ( V_31 , & V_175 , sizeof( V_175 ) ,
V_93 ) ;
}
void F_65 (
struct V_8 * V_9 ,
struct V_1 * V_199 ,
struct V_100 * V_200 )
{
int V_17 ;
unsigned long V_13 ;
if ( V_9 == NULL )
return;
F_5 ( & V_9 -> V_65 , V_13 ) ;
for ( V_17 = 0 ; V_17 < V_201 ; V_17 ++ ) {
struct V_1 * V_2 ;
struct V_105 * V_118 ;
struct V_100 * V_101 ;
unsigned long V_202 ;
T_1 V_3 ;
struct V_5 * V_6 = & V_9 -> V_120 [ V_17 ] ;
V_101 = V_6 -> V_126 ;
if ( ! V_101 || ( V_101 -> V_112 == V_145 ) )
continue;
if ( ! V_200 ) {
T_8 V_203 = ( T_8 ) V_101
- ( T_8 ) & V_9 -> V_144 ;
if ( ( ( V_203 % sizeof( * V_101 ) ) != 0 )
|| ( ( V_203 / sizeof( * V_101 ) ) >= V_143 ) )
continue;
} else if ( V_101 != V_200 )
continue;
V_3 = V_6 -> V_7 ;
if ( ! V_3 || ( V_3 == 0xFFFFFFFF ) )
continue;
V_2 = V_6 -> V_2 ;
if ( ! V_2 || ! V_2 -> V_114 )
continue;
if ( V_199 && ( V_2 != V_199 ) )
continue;
V_118 = & V_2 -> V_107 ;
V_118 -> V_108 = V_185 ;
V_118 -> V_110 = V_204 ;
V_118 -> V_205 = V_206 ;
if ( V_101 )
V_101 -> V_135 -- ;
F_5 ( & V_2 -> V_132 , V_202 ) ;
V_2 -> V_133 &= ~ V_207 ;
V_2 -> V_133 &= ~ V_134 ;
V_2 -> V_133 |= V_184 ;
if ( F_66 ( ( V_2 -> V_133
& V_168 ) ) ) {
F_7 ( & V_2 -> V_132 ,
V_202 ) ;
F_41 ( V_9 , V_2 , V_6 , V_3 ) ;
} else {
F_7 ( & V_2 -> V_132 ,
V_202 ) ;
F_41 ( V_9 , V_2 , V_6 , V_3 ) ;
F_67 () ;
F_7 ( & V_9 -> V_65 , V_13 ) ;
V_2 -> V_114 ( V_2 ) ;
F_5 ( & V_9 -> V_65 , V_13 ) ;
}
}
F_7 ( & V_9 -> V_65 , V_13 ) ;
}
int F_68 ( struct V_30 * V_31 )
{
int V_42 = V_183 ;
struct V_100 * V_101 ;
struct V_8 * V_9 ;
struct V_38 * V_48 ;
if ( ! V_31 || ! V_31 -> V_115 )
return - V_208 ;
V_101 = V_31 -> V_115 ;
V_9 = F_15 ( V_31 ) ;
V_48 = F_69 ( V_31 ) ;
if ( F_70 ( V_31 ) ) {
F_17 ( V_172 ) ;
if ( F_71 ( V_48 ) ) {
V_42 = 0 ;
goto V_209;
}
V_42 = F_72 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
V_42 = F_61 ( V_9 , V_101 ,
V_31 , 1 , 0 ) ;
V_101 -> V_181 = & V_172 ;
V_42 = V_54 -> V_182 ( V_9 ,
V_101 , 0x01 ) ;
F_18 ( & V_172 ) ;
} else {
V_42 = F_72 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
}
F_58 ( V_9 , F_12 ( L_22 ,
V_101 -> V_146 , V_42 ) ) ;
V_209:
F_73 ( V_48 ) ;
return V_42 ;
}
int F_74 ( struct V_30 * V_31 )
{
int V_42 = V_183 ;
struct V_100 * V_101 ;
struct V_8 * V_9 ;
struct V_38 * V_48 ;
T_1 V_146 = 0 ;
if ( ! V_31 || ! V_31 -> V_115 )
return - 1 ;
V_101 = V_31 -> V_115 ;
V_146 = V_101 -> V_146 ;
V_9 = F_15 ( V_31 ) ;
F_58 ( V_9 ,
F_12 ( L_23 ) ) ;
V_48 = F_69 ( V_31 ) ;
if ( F_70 ( V_31 ) ) {
F_17 ( V_172 ) ;
if ( F_71 ( V_48 ) ) {
V_42 = 0 ;
goto V_209;
}
V_42 = F_61 ( V_9 , V_101 ,
V_31 , 1 , 0 ) ;
F_20 ( 100 ) ;
F_62 ( V_31 ) ;
F_20 ( 200 ) ;
V_42 = F_72 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
V_101 -> V_181 = & V_172 ;
F_18 ( & V_172 ) ;
} else {
V_42 = F_61 ( V_9 , V_101 ,
V_31 , 1 , 0 ) ;
F_20 ( 100 ) ;
F_62 ( V_31 ) ;
F_20 ( 200 ) ;
V_42 = F_72 ( V_48 , 1 ) ;
F_20 ( 2000 ) ;
}
F_58 ( V_9 , F_12 ( L_22 ,
V_101 -> V_146 , V_42 ) ) ;
V_209:
F_73 ( V_48 ) ;
return V_42 ;
}
int F_75 ( struct V_30 * V_31 , T_7 * V_195 )
{
int V_42 = V_183 ;
struct V_92 V_210 ;
struct V_100 * V_101 = V_31 -> V_115 ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
F_17 ( V_172 ) ;
if ( F_70 ( V_31 ) ) {
struct V_38 * V_48 = F_69 ( V_31 ) ;
V_42 = F_61 ( V_9 , V_101 ,
V_31 , 1 , 0 ) ;
V_42 = F_72 ( V_48 , 1 ) ;
F_73 ( V_48 ) ;
V_101 -> V_181 = & V_172 ;
V_42 = V_54 -> V_182 ( V_9 ,
V_101 , 0x01 ) ;
F_18 ( & V_172 ) ;
} else {
V_210 . V_93 = V_211 ;
V_42 = F_64 ( V_31 , V_195 , & V_210 ) ;
}
F_58 ( V_9 , F_12 ( L_24 ,
V_101 -> V_146 , V_42 ) ) ;
return V_42 ;
}
int F_76 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_17 = 0 ;
struct V_212 V_195 ;
struct V_92 V_210 ;
int V_42 = V_183 ;
if ( F_66 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_31 ) )
return V_42 ;
if ( V_2 -> V_117 & V_128 ) {
struct V_213 * V_214 = V_2 -> V_86 ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_8 * V_9 =
F_15 ( V_31 ) ;
F_77 ( V_214 -> V_126 -> V_195 , & V_195 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
V_42 = V_183 ;
return V_42 ;
}
F_58 ( V_9 , F_12 ( L_25 ) ) ;
for ( V_17 = 0 ; V_17 < 16 ; V_17 ++ )
F_78 ( V_215 L_26 , V_214 -> V_214 [ V_17 ] ) ;
F_78 ( V_215 L_27 ) ;
V_210 . V_93 = V_216 ;
V_210 . V_217 = V_3 ;
V_42 = F_64 ( V_31 , V_195 . V_212 , & V_210 ) ;
switch ( V_42 ) {
case V_218 :
F_58 ( V_9 ,
F_12 ( L_28 ) ) ;
break;
case V_183 :
case V_187 :
F_58 ( V_9 ,
F_12 ( L_29
L_30 ) ) ;
break;
}
}
F_12 ( L_31 , V_42 ) ;
return V_42 ;
}
int F_79 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_146 ;
struct V_30 * V_31 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_212 V_195 ;
struct V_100 * V_101 ;
struct V_92 V_210 ;
int V_42 = V_183 ;
if ( F_66 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_31 ) )
return V_42 ;
F_5 ( & V_2 -> V_132 , V_13 ) ;
if ( V_2 -> V_133 & V_184 ) {
F_7 ( & V_2 -> V_132 , V_13 ) ;
V_42 = V_187 ;
goto V_209;
}
F_7 ( & V_2 -> V_132 , V_13 ) ;
if ( V_2 -> V_117 & V_128 ) {
struct V_213 * V_214 = V_2 -> V_86 ;
V_31 = V_2 -> V_31 ;
V_6 = V_2 -> V_4 ;
V_101 = V_31 -> V_115 ;
V_9 = F_15 ( V_31 ) ;
F_77 ( V_214 -> V_126 -> V_195 , & V_195 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_78 ( V_215 L_32 , V_219 ) ;
V_42 = V_183 ;
return V_42 ;
}
V_146 = V_101 -> V_146 ;
F_58 ( V_9 ,
F_12 ( L_33 , V_146 ) ) ;
V_210 . V_93 = V_220 ;
V_210 . V_217 = V_3 ;
V_42 = F_64 ( V_31 , V_195 . V_212 , & V_210 ) ;
F_61 ( V_9 , V_101 ,
V_101 -> V_147 , 0 , V_3 ) ;
} else if ( V_2 -> V_117 & V_129 ||
V_2 -> V_117 & V_130 ) {
V_31 = V_2 -> V_31 ;
V_101 = V_31 -> V_115 ;
V_9 = F_15 ( V_31 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_78 ( V_215 L_32 , V_219 ) ;
V_42 = V_183 ;
return V_42 ;
}
V_42 = F_61 ( V_9 , V_101 ,
V_101 -> V_147 , 0 , V_3 ) ;
} else if ( V_2 -> V_117 & V_127 ) {
V_31 = V_2 -> V_31 ;
V_101 = V_31 -> V_115 ;
V_9 = F_15 ( V_31 ) ;
V_42 = F_1 ( V_2 , & V_3 ) ;
if ( V_42 == 0 ) {
F_78 ( V_215 L_32 , V_219 ) ;
V_42 = V_183 ;
return V_42 ;
}
V_42 = F_61 ( V_9 , V_101 ,
V_101 -> V_147 , 0 , V_3 ) ;
}
V_209:
if ( V_42 != V_187 )
F_12 ( L_34 , V_42 ) ;
return V_42 ;
}
int F_80 ( struct V_30 * V_31 , T_7 * V_195 )
{
int V_42 = V_183 ;
struct V_92 V_210 ;
V_210 . V_93 = V_221 ;
V_42 = F_64 ( V_31 , V_195 , & V_210 ) ;
return V_42 ;
}
int F_81 ( struct V_30 * V_31 , T_7 * V_195 )
{
int V_42 = V_183 ;
struct V_92 V_210 ;
V_210 . V_93 = V_222 ;
V_42 = F_64 ( V_31 , V_195 , & V_210 ) ;
return V_42 ;
}
int F_82 ( struct V_30 * V_31 , T_7 * V_195 )
{
int V_42 = V_183 ;
struct V_92 V_210 ;
struct V_100 * V_101 = V_31 -> V_115 ;
struct V_8 * V_9 = F_15 ( V_31 ) ;
F_58 ( V_9 ,
F_12 ( L_35 ,
V_101 -> V_146 ) ) ;
V_210 . V_93 = V_223 ;
V_42 = F_64 ( V_31 , V_195 , & V_210 ) ;
return V_42 ;
}
