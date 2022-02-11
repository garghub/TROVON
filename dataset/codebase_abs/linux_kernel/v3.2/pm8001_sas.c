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
void F_20 ( struct V_64 * V_65 )
{
int V_16 ;
struct V_8 * V_9 ;
struct V_31 * V_32 = F_21 ( V_65 ) ;
V_9 = V_32 -> V_35 ;
V_53 -> V_66 ( V_9 ) ;
for ( V_16 = 0 ; V_16 < V_9 -> V_67 -> V_68 ; ++ V_16 )
V_53 -> V_54 ( V_9 , V_16 ) ;
}
int F_22 ( struct V_64 * V_65 , unsigned long time )
{
if ( time < V_69 )
return 0 ;
F_23 ( V_65 ) ;
return 1 ;
}
static int F_24 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_70 ( V_9 , V_6 ) ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_71 * V_72 = V_2 -> V_73 ;
if ( V_72 ) {
if ( V_72 -> V_74 . V_75 == V_76 ||
V_72 -> V_74 . V_75 == V_77 ) {
* V_3 = V_72 -> V_3 ;
return 1 ;
}
}
return 0 ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_78 ( V_9 , V_6 ) ;
}
static int F_27 ( struct V_8 * V_9 ,
struct V_5 * V_6 , struct V_79 * V_80 )
{
return V_53 -> V_81 ( V_9 , V_6 , V_80 ) ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
return V_53 -> V_82 ( V_9 , V_6 ) ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_29 * V_18 = V_30 -> V_83 ;
if ( ! V_18 )
return V_30 -> V_33 -> V_43 ;
while ( V_18 ) {
struct V_29 * V_84 = V_18 -> V_83 ;
if ( ! V_84 )
return V_18 -> V_33 -> V_43 ;
V_18 = V_18 -> V_83 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , const int V_85 ,
T_5 V_86 , int V_87 , struct V_79 * V_80 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 ;
struct V_88 * V_89 ;
struct V_90 * V_33 = NULL ;
struct V_1 * V_91 = V_2 ;
struct V_5 * V_6 ;
T_1 V_3 = 0xdeadbeef , V_41 , V_92 = 0 ;
T_1 V_93 = V_85 ;
unsigned long V_94 = 0 , V_95 = 0 ;
if ( ! V_30 -> V_33 ) {
struct V_96 * V_97 = & V_91 -> V_98 ;
V_97 -> V_99 = V_100 ;
V_97 -> V_101 = V_102 ;
if ( V_30 -> V_103 != V_104 )
V_91 -> V_105 ( V_91 ) ;
return 0 ;
}
V_9 = F_15 ( V_2 -> V_30 ) ;
F_31 ( V_9 , F_12 ( L_2 ) ) ;
F_32 ( & V_9 -> V_106 , V_94 ) ;
do {
V_30 = V_91 -> V_30 ;
V_89 = V_30 -> V_107 ;
V_33 = & V_9 -> V_33 [ F_29 ( V_30 ) ] ;
if ( F_33 ( V_89 ) || ! V_33 -> V_108 ) {
if ( F_34 ( V_91 -> V_109 ) ) {
struct V_96 * V_110 = & V_91 -> V_98 ;
V_110 -> V_99 = V_100 ;
V_110 -> V_101 = V_102 ;
F_35 ( & V_9 -> V_106 , V_94 ) ;
F_35 ( V_30 -> V_111 . V_112 -> V_106 ,
V_95 ) ;
V_91 -> V_105 ( V_91 ) ;
F_32 ( V_30 -> V_111 . V_112 -> V_106 ,
V_95 ) ;
F_32 ( & V_9 -> V_106 , V_94 ) ;
if ( V_93 > 1 )
V_91 = F_36 ( V_91 -> V_113 . V_114 ,
struct V_1 , V_113 ) ;
continue;
} else {
struct V_96 * V_110 = & V_91 -> V_98 ;
V_110 -> V_99 = V_100 ;
V_110 -> V_101 = V_102 ;
V_91 -> V_105 ( V_91 ) ;
if ( V_93 > 1 )
V_91 = F_36 ( V_91 -> V_113 . V_114 ,
struct V_1 , V_113 ) ;
continue;
}
}
V_41 = F_7 ( V_9 , & V_3 ) ;
if ( V_41 )
goto V_115;
V_6 = & V_9 -> V_116 [ V_3 ] ;
if ( ! F_34 ( V_91 -> V_109 ) ) {
if ( V_91 -> V_117 ) {
V_92 = F_37 ( V_9 -> V_30 ,
V_91 -> V_118 ,
V_91 -> V_117 ,
V_91 -> V_119 ) ;
if ( ! V_92 ) {
V_41 = - V_120 ;
goto V_121;
}
}
} else {
V_92 = V_91 -> V_117 ;
}
V_91 -> V_4 = V_6 ;
V_6 -> V_92 = V_92 ;
V_6 -> V_7 = V_3 ;
V_6 -> V_2 = V_91 ;
switch ( V_91 -> V_109 ) {
case V_122 :
V_41 = F_24 ( V_9 , V_6 ) ;
break;
case V_123 :
if ( V_87 )
V_41 = F_27 ( V_9 ,
V_6 , V_80 ) ;
else
V_41 = F_28 ( V_9 , V_6 ) ;
break;
case V_124 :
case V_125 :
case V_124 | V_125 :
V_41 = F_26 ( V_9 , V_6 ) ;
break;
default:
F_38 ( V_126 , V_9 -> V_30 ,
L_3 ,
V_91 -> V_109 ) ;
V_41 = - V_127 ;
break;
}
if ( V_41 ) {
F_31 ( V_9 ,
F_12 ( L_4 , V_41 ) ) ;
goto V_121;
}
F_39 ( & V_91 -> V_128 ) ;
V_91 -> V_129 |= V_130 ;
F_40 ( & V_91 -> V_128 ) ;
V_89 -> V_131 ++ ;
if ( V_93 > 1 )
V_91 = F_36 ( V_91 -> V_113 . V_114 , struct V_1 , V_113 ) ;
} while ( -- V_93 );
V_41 = 0 ;
goto V_132;
V_121:
F_4 ( V_9 , V_3 ) ;
V_115:
F_38 ( V_126 , V_9 -> V_30 , L_5 , V_41 ) ;
if ( ! F_34 ( V_91 -> V_109 ) )
if ( V_92 )
F_41 ( V_9 -> V_30 , V_91 -> V_118 , V_92 ,
V_91 -> V_119 ) ;
V_132:
F_35 ( & V_9 -> V_106 , V_94 ) ;
return V_41 ;
}
int F_42 ( struct V_1 * V_2 , const int V_85 ,
T_5 V_86 )
{
return F_30 ( V_2 , V_85 , V_86 , 0 , NULL ) ;
}
void F_43 ( struct V_8 * V_9 , T_1 V_133 )
{
F_2 ( V_9 , V_133 ) ;
}
void F_44 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_5 * V_6 , T_1 V_133 )
{
if ( ! V_6 -> V_2 )
return;
if ( ! F_34 ( V_2 -> V_109 ) )
if ( V_6 -> V_92 )
F_41 ( V_9 -> V_30 , V_2 -> V_118 ,
V_2 -> V_117 , V_2 -> V_119 ) ;
switch ( V_2 -> V_109 ) {
case V_122 :
F_41 ( V_9 -> V_30 , & V_2 -> V_134 . V_135 , 1 ,
V_136 ) ;
F_41 ( V_9 -> V_30 , & V_2 -> V_134 . V_70 , 1 ,
V_137 ) ;
break;
case V_124 :
case V_125 :
case V_123 :
default:
break;
}
V_2 -> V_4 = NULL ;
V_6 -> V_2 = NULL ;
V_6 -> V_7 = 0xFFFFFFFF ;
F_43 ( V_9 , V_133 ) ;
}
struct V_88 * F_45 ( struct V_8 * V_9 )
{
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_138 ; V_30 ++ ) {
if ( V_9 -> V_139 [ V_30 ] . V_103 == V_140 ) {
V_9 -> V_139 [ V_30 ] . V_43 = V_30 ;
return & V_9 -> V_139 [ V_30 ] ;
}
}
if ( V_30 == V_138 ) {
F_46 ( V_9 ,
F_12 ( L_6 ,
V_138 ) ) ;
}
return NULL ;
}
static void F_47 ( struct V_88 * V_89 )
{
T_1 V_43 = V_89 -> V_43 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_43 = V_43 ;
V_89 -> V_103 = V_140 ;
V_89 -> V_141 = V_138 ;
V_89 -> V_142 = NULL ;
}
static int F_48 ( struct V_29 * V_30 )
{
unsigned long V_94 = 0 ;
int V_143 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_29 * V_144 = V_30 -> V_83 ;
struct V_88 * V_88 ;
F_17 ( V_46 ) ;
T_1 V_145 = 0 ;
V_9 = F_15 ( V_30 ) ;
F_32 ( & V_9 -> V_106 , V_94 ) ;
V_88 = F_45 ( V_9 ) ;
if ( ! V_88 ) {
V_143 = - 1 ;
goto V_146;
}
V_88 -> V_142 = V_30 ;
V_30 -> V_107 = V_88 ;
V_88 -> V_103 = V_30 -> V_103 ;
V_88 -> V_147 = & V_46 ;
if ( V_144 && F_49 ( V_144 -> V_103 ) ) {
int V_42 ;
struct V_148 * V_47 ;
for ( V_42 = 0 ; V_42 < V_144 -> V_149 . V_150 ;
V_42 ++ ) {
V_47 = & V_144 -> V_149 . V_148 [ V_42 ] ;
if ( F_50 ( V_47 -> V_151 )
== F_50 ( V_30 -> V_152 ) ) {
V_88 -> V_153 = V_42 ;
break;
}
}
if ( V_42 == V_144 -> V_149 . V_150 ) {
F_46 ( V_9 ,
F_12 ( L_7
L_8 , F_50 ( V_30 -> V_152 ) ,
F_50 ( V_144 -> V_152 ) ) ) ;
V_143 = - 1 ;
}
} else {
if ( V_30 -> V_103 == V_104 ) {
V_88 -> V_153 =
V_30 -> V_154 -> V_155 . V_156 ;
V_145 = 1 ;
}
}
F_51 ( V_9 , F_12 ( L_9 ) ) ;
V_53 -> V_157 ( V_9 , V_88 , V_145 ) ;
F_35 ( & V_9 -> V_106 , V_94 ) ;
F_18 ( & V_46 ) ;
if ( V_30 -> V_103 == V_158 )
F_19 ( 50 ) ;
V_9 -> V_94 |= V_159 ;
return 0 ;
V_146:
F_35 ( & V_9 -> V_106 , V_94 ) ;
return V_143 ;
}
int F_52 ( struct V_29 * V_30 )
{
return F_48 ( V_30 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( ! F_54 ( & V_2 -> V_160 ) )
return;
F_55 ( & V_2 -> V_46 ) ;
}
static void F_56 ( unsigned long V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
V_2 -> V_129 |= V_162 ;
F_55 ( & V_2 -> V_46 ) ;
}
static int F_57 ( struct V_29 * V_30 ,
void * V_163 , T_1 V_164 , struct V_79 * V_80 )
{
int V_143 , V_165 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
for ( V_165 = 0 ; V_165 < 3 ; V_165 ++ ) {
V_2 = F_58 ( V_166 ) ;
if ( ! V_2 )
return - V_120 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_109 = V_30 -> V_167 ;
memcpy ( & V_2 -> V_168 , V_163 , V_164 ) ;
V_2 -> V_105 = F_53 ;
V_2 -> V_160 . V_161 = ( unsigned long ) V_2 ;
V_2 -> V_160 . V_169 = F_56 ;
V_2 -> V_160 . V_170 = V_171 + V_172 * V_69 ;
F_59 ( & V_2 -> V_160 ) ;
V_143 = F_30 ( V_2 , 1 , V_166 , 1 , V_80 ) ;
if ( V_143 ) {
F_54 ( & V_2 -> V_160 ) ;
F_46 ( V_9 ,
F_12 ( L_10
L_11 ) ) ;
goto V_173;
}
F_18 ( & V_2 -> V_46 ) ;
V_143 = - V_174 ;
if ( ( V_2 -> V_129 & V_162 ) ) {
if ( ! ( V_2 -> V_129 & V_175 ) ) {
F_46 ( V_9 ,
F_12 ( L_12 ,
V_80 -> V_80 ) ) ;
goto V_173;
}
}
if ( V_2 -> V_98 . V_99 == V_176 &&
V_2 -> V_98 . V_101 == V_177 ) {
V_143 = V_178 ;
break;
}
if ( V_2 -> V_98 . V_99 == V_176 &&
V_2 -> V_98 . V_101 == V_179 ) {
V_143 = V_2 -> V_98 . V_180 ;
break;
}
if ( V_2 -> V_98 . V_99 == V_176 &&
V_2 -> V_98 . V_101 == V_181 ) {
F_46 ( V_9 ,
F_12 ( L_13 ) ) ;
V_143 = - V_182 ;
break;
} else {
F_60 ( V_9 ,
F_12 ( L_14
L_15 ,
F_50 ( V_30 -> V_152 ) ,
V_2 -> V_98 . V_99 ,
V_2 -> V_98 . V_101 ) ) ;
F_61 ( V_2 ) ;
V_2 = NULL ;
}
}
V_173:
F_62 ( V_165 == 3 && V_2 != NULL ) ;
F_61 ( V_2 ) ;
return V_143 ;
}
static int
F_63 ( struct V_8 * V_9 ,
struct V_88 * V_89 , struct V_29 * V_30 , T_1 V_145 ,
T_1 V_183 )
{
int V_143 , V_165 ;
T_1 V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
for ( V_165 = 0 ; V_165 < 3 ; V_165 ++ ) {
V_2 = F_58 ( V_166 ) ;
if ( ! V_2 )
return - V_120 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_109 = V_30 -> V_167 ;
V_2 -> V_105 = F_53 ;
V_2 -> V_160 . V_161 = ( unsigned long ) V_2 ;
V_2 -> V_160 . V_169 = F_56 ;
V_2 -> V_160 . V_170 = V_171 + V_172 * V_69 ;
F_59 ( & V_2 -> V_160 ) ;
V_143 = F_7 ( V_9 , & V_7 ) ;
if ( V_143 )
return V_143 ;
V_6 = & V_9 -> V_116 [ V_7 ] ;
V_6 -> V_184 = V_89 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_143 = V_53 -> V_185 ( V_9 ,
V_89 , V_145 , V_183 , V_7 ) ;
if ( V_143 ) {
F_54 ( & V_2 -> V_160 ) ;
F_46 ( V_9 ,
F_12 ( L_10
L_11 ) ) ;
goto V_173;
}
F_18 ( & V_2 -> V_46 ) ;
V_143 = V_174 ;
if ( ( V_2 -> V_129 & V_162 ) ) {
if ( ! ( V_2 -> V_129 & V_175 ) ) {
F_46 ( V_9 ,
F_12 ( L_16 ) ) ;
goto V_173;
}
}
if ( V_2 -> V_98 . V_99 == V_176 &&
V_2 -> V_98 . V_101 == V_177 ) {
V_143 = V_178 ;
break;
} else {
F_60 ( V_9 ,
F_12 ( L_17
L_15 ,
F_50 ( V_30 -> V_152 ) ,
V_2 -> V_98 . V_99 ,
V_2 -> V_98 . V_101 ) ) ;
F_61 ( V_2 ) ;
V_2 = NULL ;
}
}
V_173:
F_62 ( V_165 == 3 && V_2 != NULL ) ;
F_61 ( V_2 ) ;
return V_143 ;
}
static void F_64 ( struct V_29 * V_30 )
{
unsigned long V_94 = 0 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_88 * V_89 = V_30 -> V_107 ;
V_9 = F_15 ( V_30 ) ;
F_32 ( & V_9 -> V_106 , V_94 ) ;
F_7 ( V_9 , & V_3 ) ;
if ( V_89 ) {
T_1 V_141 = V_89 -> V_141 ;
F_51 ( V_9 ,
F_12 ( L_18 ,
V_89 -> V_141 , V_89 -> V_103 ) ) ;
if ( V_89 -> V_131 ) {
F_35 ( & V_9 -> V_106 , V_94 ) ;
F_63 ( V_9 , V_89 ,
V_30 , 1 , 0 ) ;
F_32 ( & V_9 -> V_106 , V_94 ) ;
}
V_53 -> V_186 ( V_9 , V_141 ) ;
F_47 ( V_89 ) ;
} else {
F_51 ( V_9 ,
F_12 ( L_19 ) ) ;
}
V_30 -> V_107 = NULL ;
F_35 ( & V_9 -> V_106 , V_94 ) ;
}
void F_65 ( struct V_29 * V_30 )
{
F_64 ( V_30 ) ;
}
static int F_66 ( struct V_29 * V_30 ,
T_6 * V_187 , struct V_79 * V_80 )
{
struct V_188 V_168 ;
if ( ! ( V_30 -> V_167 & V_123 ) )
return V_189 ;
strncpy ( ( T_6 * ) & V_168 . V_190 , V_187 , 8 ) ;
return F_57 ( V_30 , & V_168 , sizeof( V_168 ) ,
V_80 ) ;
}
int F_67 ( struct V_29 * V_30 )
{
int V_41 = V_174 ;
struct V_88 * V_89 ;
struct V_8 * V_9 ;
struct V_37 * V_47 ;
if ( ! V_30 || ! V_30 -> V_107 )
return - 1 ;
V_89 = V_30 -> V_107 ;
V_9 = F_15 ( V_30 ) ;
V_47 = F_68 ( V_30 ) ;
if ( F_69 ( V_30 ) ) {
F_17 ( V_191 ) ;
if ( F_70 ( V_47 ) )
return 0 ;
V_41 = F_71 ( V_47 , 1 ) ;
F_19 ( 2000 ) ;
V_41 = F_63 ( V_9 , V_89 ,
V_30 , 1 , 0 ) ;
V_89 -> V_192 = & V_191 ;
V_41 = V_53 -> V_193 ( V_9 ,
V_89 , 0x01 ) ;
F_18 ( & V_191 ) ;
} else{
V_41 = F_71 ( V_47 , 1 ) ;
F_19 ( 2000 ) ;
}
F_60 ( V_9 , F_12 ( L_20 ,
V_89 -> V_141 , V_41 ) ) ;
return V_41 ;
}
int F_72 ( struct V_29 * V_30 , T_6 * V_187 )
{
int V_41 = V_174 ;
struct V_79 V_194 ;
struct V_88 * V_89 = V_30 -> V_107 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
if ( F_69 ( V_30 ) ) {
struct V_37 * V_47 = F_68 ( V_30 ) ;
V_41 = F_63 ( V_9 , V_89 ,
V_30 , 1 , 0 ) ;
V_41 = F_71 ( V_47 , 1 ) ;
V_41 = V_53 -> V_193 ( V_9 ,
V_89 , 0x01 ) ;
F_19 ( 2000 ) ;
} else {
V_194 . V_80 = V_195 ;
V_41 = F_66 ( V_30 , V_187 , & V_194 ) ;
}
F_60 ( V_9 , F_12 ( L_21 ,
V_89 -> V_141 , V_41 ) ) ;
return V_41 ;
}
int F_73 ( struct V_1 * V_2 )
{
T_1 V_3 = 0xdeadbeef ;
int V_16 = 0 ;
struct V_196 V_187 ;
struct V_79 V_194 ;
int V_41 = V_174 ;
if ( F_74 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
if ( V_2 -> V_109 & V_123 ) {
struct V_197 * V_198 = V_2 -> V_73 ;
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_8 * V_9 =
F_15 ( V_30 ) ;
F_75 ( V_198 -> V_184 -> V_187 , & V_187 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
V_41 = V_174 ;
return V_41 ;
}
F_60 ( V_9 , F_12 ( L_22 ) ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_76 ( V_199 L_23 , V_198 -> V_198 [ V_16 ] ) ;
F_76 ( V_199 L_24 ) ;
V_194 . V_80 = V_200 ;
V_194 . V_201 = V_3 ;
V_41 = F_66 ( V_30 , V_187 . V_196 , & V_194 ) ;
switch ( V_41 ) {
case V_202 :
F_60 ( V_9 ,
F_12 ( L_25 ) ) ;
break;
case V_174 :
case V_178 :
F_60 ( V_9 ,
F_12 ( L_26
L_27 ) ) ;
break;
}
}
F_12 ( L_28 , V_41 ) ;
return V_41 ;
}
int F_77 ( struct V_1 * V_2 )
{
unsigned long V_94 ;
T_1 V_3 = 0xdeadbeef ;
T_1 V_141 ;
struct V_29 * V_30 ;
struct V_8 * V_9 = NULL ;
struct V_5 * V_6 ;
struct V_196 V_187 ;
struct V_88 * V_89 ;
struct V_79 V_194 ;
int V_41 = V_174 ;
if ( F_74 ( ! V_2 || ! V_2 -> V_4 || ! V_2 -> V_30 ) )
return V_41 ;
F_32 ( & V_2 -> V_128 , V_94 ) ;
if ( V_2 -> V_129 & V_175 ) {
F_35 ( & V_2 -> V_128 , V_94 ) ;
V_41 = V_178 ;
goto V_203;
}
F_35 ( & V_2 -> V_128 , V_94 ) ;
if ( V_2 -> V_109 & V_123 ) {
struct V_197 * V_198 = V_2 -> V_73 ;
V_30 = V_2 -> V_30 ;
V_6 = V_2 -> V_4 ;
V_89 = V_30 -> V_107 ;
V_9 = F_15 ( V_30 ) ;
F_75 ( V_198 -> V_184 -> V_187 , & V_187 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_76 ( V_199 L_29 , V_204 ) ;
V_41 = V_174 ;
return V_41 ;
}
V_141 = V_89 -> V_141 ;
F_60 ( V_9 ,
F_12 ( L_30 , V_141 ) ) ;
V_194 . V_80 = V_205 ;
V_194 . V_201 = V_3 ;
V_41 = F_66 ( V_30 , V_187 . V_196 , & V_194 ) ;
F_63 ( V_9 , V_89 ,
V_89 -> V_142 , 0 , V_3 ) ;
} else if ( V_2 -> V_109 & V_124 ||
V_2 -> V_109 & V_125 ) {
V_30 = V_2 -> V_30 ;
V_89 = V_30 -> V_107 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_76 ( V_199 L_29 , V_204 ) ;
V_41 = V_174 ;
return V_41 ;
}
V_41 = F_63 ( V_9 , V_89 ,
V_89 -> V_142 , 0 , V_3 ) ;
} else if ( V_2 -> V_109 & V_122 ) {
V_30 = V_2 -> V_30 ;
V_89 = V_30 -> V_107 ;
V_9 = F_15 ( V_30 ) ;
V_41 = F_1 ( V_2 , & V_3 ) ;
if ( V_41 == 0 ) {
F_76 ( V_199 L_29 , V_204 ) ;
V_41 = V_174 ;
return V_41 ;
}
V_41 = F_63 ( V_9 , V_89 ,
V_89 -> V_142 , 0 , V_3 ) ;
}
V_203:
if ( V_41 != V_178 )
F_12 ( L_31 , V_41 ) ;
return V_41 ;
}
int F_78 ( struct V_29 * V_30 , T_6 * V_187 )
{
int V_41 = V_174 ;
struct V_79 V_194 ;
V_194 . V_80 = V_206 ;
V_41 = F_66 ( V_30 , V_187 , & V_194 ) ;
return V_41 ;
}
int F_79 ( struct V_29 * V_30 , T_6 * V_187 )
{
int V_41 = V_174 ;
struct V_79 V_194 ;
V_194 . V_80 = V_207 ;
V_41 = F_66 ( V_30 , V_187 , & V_194 ) ;
return V_41 ;
}
int F_80 ( struct V_29 * V_30 , T_6 * V_187 )
{
int V_41 = V_174 ;
struct V_79 V_194 ;
struct V_88 * V_89 = V_30 -> V_107 ;
struct V_8 * V_9 = F_15 ( V_30 ) ;
F_60 ( V_9 ,
F_12 ( L_32 ,
V_89 -> V_141 ) ) ;
V_194 . V_80 = V_208 ;
V_41 = F_66 ( V_30 , V_187 , & V_194 ) ;
return V_41 ;
}
