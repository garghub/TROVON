static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
sscanf ( V_5 , L_2 , & V_6 ) ;
return V_7 ;
}
static void F_3 ( char * V_8 , int V_9 )
{
F_4 ( V_10 , L_3 , V_11 , 16 , 4 ,
V_8 , V_9 , false ) ;
}
static void F_5 ( unsigned int V_12 )
{
unsigned char type = F_6 ( V_12 ) ;
unsigned char V_13 = F_7 ( V_12 ) ;
unsigned char V_2 = F_8 ( V_12 ) ;
unsigned char V_14 = F_9 ( V_12 ) ;
F_10 ( L_4 , V_2 , V_13 , V_14 ? L_5 : L_6 ) ;
switch ( type ) {
case V_15 :
F_10 ( L_7 ) ;
break;
case V_16 :
F_10 ( L_8 ) ;
break;
case V_17 :
F_10 ( L_9 ) ;
break;
case V_18 :
F_10 ( L_10 ) ;
break;
default:
F_10 ( L_11 ) ;
break;
}
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
int V_21 ;
F_12 ( V_2 , L_12 ,
V_20 -> V_22 , V_20 -> V_23 ) ;
switch ( V_20 -> V_24 ) {
case V_25 :
F_10 ( L_13 ) ;
break;
case V_26 :
F_10 ( L_14 ) ;
break;
case V_27 :
F_10 ( L_15 ) ;
break;
case V_28 :
F_10 ( L_16 ) ;
break;
default:
F_10 ( L_17 ) ;
break;
}
F_10 ( L_18 , V_20 -> V_29 , V_20 -> V_30 ) ;
F_12 ( V_2 , L_19 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_10 ( L_20 , V_21 ) ;
F_10 ( L_21 ) ;
F_12 ( V_2 , L_22 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_10 ( L_20 , ( V_20 -> V_31 [ 0 ] & ( 1 << V_21 ) ) ? 1 : 0 ) ;
F_10 ( L_21 ) ;
F_12 ( V_2 , L_23 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_10 ( L_20 , ( V_20 -> V_31 [ 1 ] & ( 1 << V_21 ) ) ? 1 : 0 ) ;
F_10 ( L_21 ) ;
F_12 ( V_2 , L_24 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
if ( V_20 -> V_32 [ V_21 ] )
F_10 ( L_20 ,
F_13 ( V_20 -> V_32 [ V_21 ] -> V_33 . V_34 ) ) ;
}
F_10 ( L_21 ) ;
F_12 ( V_2 , L_25 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
if ( V_20 -> V_35 [ V_21 ] )
F_10 ( L_20 ,
F_13 ( V_20 -> V_35 [ V_21 ] -> V_33 . V_34 ) ) ;
}
F_10 ( L_21 ) ;
F_12 ( V_2 , L_26 , V_20 -> V_36 , V_20 -> V_37 ) ;
F_12 ( V_2 , L_27
L_28 , & V_20 -> V_38 , V_20 -> V_39 ,
V_20 -> V_40 , V_20 -> V_41 ) ;
F_12 ( V_2 , L_29 ,
V_20 -> V_42 , V_20 -> V_43 ) ;
F_12 ( V_2 , L_30 ,
V_20 -> V_44 , V_20 -> V_45 ) ;
}
static void F_14 ( T_3 V_46 )
{
switch ( V_46 & V_47 ) {
case V_48 :
F_10 ( L_31 ) ;
break;
case V_49 :
F_10 ( L_32 ) ;
break;
case V_50 :
F_10 ( L_33 ) ;
break;
case V_51 :
F_10 ( L_34 ) ;
break;
default:
F_10 ( L_35 ) ;
break;
}
}
static void F_15 ( struct V_52 * V_53 )
{
if ( ! V_53 ) {
F_10 ( L_36 ) ;
return;
}
F_10 ( L_37 ) ;
F_10 ( L_38
L_39 , V_53 -> V_54 , V_53 -> V_55 ,
V_53 -> V_56 , V_53 -> V_57 , V_53 -> V_58 ) ;
F_10 ( L_40 ) ;
if ( ( V_53 -> V_54 & V_59 ) == V_60 ) {
F_10 ( L_41 ) ;
switch ( V_53 -> V_55 ) {
case V_61 :
F_10 ( L_42 ) ;
break;
case V_62 :
F_10 ( L_43 ) ;
break;
case V_63 :
F_10 ( L_44 ) ;
break;
case V_64 :
F_10 ( L_45 ) ;
break;
case V_65 :
F_10 ( L_46 ) ;
break;
case V_66 :
F_10 ( L_47 ) ;
break;
case V_67 :
F_10 ( L_48 ) ;
break;
case V_68 :
F_10 ( L_49 ) ;
break;
case V_69 :
F_10 ( L_50 ) ;
break;
case V_70 :
F_10 ( L_51 ) ;
break;
case V_71 :
F_10 ( L_52 ) ;
break;
default:
F_10 ( L_53 , V_53 -> V_55 ) ;
break;
}
F_14 ( V_53 -> V_54 ) ;
} else if ( ( V_53 -> V_54 & V_59 ) == V_72 ) {
F_10 ( L_54 ) ;
} else if ( ( V_53 -> V_54 & V_59 ) == V_73 ) {
F_10 ( L_55 ) ;
} else if ( ( V_53 -> V_54 & V_59 ) == V_74 ) {
F_10 ( L_56 ) ;
}
}
void F_16 ( struct V_75 * V_75 )
{
struct V_1 * V_2 ;
if ( ! V_75 ) {
F_10 ( L_57 ) ;
return;
}
if ( ! V_75 -> V_2 ) {
F_10 ( L_58 ) ;
return;
}
V_2 = & V_75 -> V_2 -> V_2 ;
F_12 ( V_2 , L_59 , V_75 ) ;
F_12 ( V_2 , L_60 , V_75 -> V_2 ) ;
F_11 ( V_75 -> V_2 ) ;
F_12 ( V_2 , L_61 , V_75 -> V_76 ) ;
F_5 ( V_75 -> V_76 ) ;
F_12 ( V_2 , L_62 , V_75 -> V_77 ) ;
F_12 ( V_2 , L_63 , V_75 -> V_78 ) ;
F_12 ( V_2 , L_64 , V_75 -> V_79 ) ;
F_12 ( V_2 , L_65 ,
V_75 -> V_80 ) ;
F_12 ( V_2 , L_66 , V_75 -> V_81 ) ;
F_12 ( V_2 , L_67 , V_75 -> V_82 ) ;
if ( V_75 -> V_82 && F_6 ( V_75 -> V_76 ) == V_17 )
F_15 (
(struct V_52 * ) V_75 -> V_82 ) ;
F_12 ( V_2 , L_68 , V_75 -> V_83 ) ;
F_12 ( V_2 , L_69 , V_75 -> V_84 ) ;
F_12 ( V_2 , L_70 , V_75 -> V_85 ) ;
F_12 ( V_2 , L_71 , V_75 -> V_86 ) ;
F_12 ( V_2 , L_72 , V_75 -> V_87 ) ;
F_12 ( V_2 , L_73 , V_75 -> V_88 ) ;
}
void F_17 ( struct V_89 * V_90 )
{
F_10 ( L_74 ,
V_90 -> V_91 . V_92 ,
V_90 -> V_91 . V_93 ,
V_90 -> V_91 . V_94 ,
V_90 -> V_91 . V_95 ,
V_90 -> V_91 . V_13 ) ;
switch ( V_90 -> V_91 . V_92 ) {
case V_96 :
F_10 ( L_75
L_76 ,
V_90 -> V_97 . V_98 . V_78 ,
V_90 -> V_97 . V_98 . V_80 ,
V_90 -> V_97 . V_98 . V_83 ,
V_90 -> V_97 . V_98 . V_84 ,
V_90 -> V_97 . V_98 . V_85 ) ;
break;
case V_99 :
F_10 ( L_77 ,
V_90 -> V_97 . V_100 . V_93 ) ;
break;
case V_101 :
F_10 ( L_78 ,
V_90 -> V_97 . V_102 . V_77 ,
V_90 -> V_97 . V_102 . V_81 ,
V_90 -> V_97 . V_102 . V_83 ,
V_90 -> V_97 . V_102 . V_84 ,
V_90 -> V_97 . V_102 . V_86 ) ;
break;
case V_103 :
F_10 ( L_79 ,
V_90 -> V_97 . V_104 . V_77 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
int F_19 ( int V_105 , struct V_106 * V_107 , char * V_5 , int V_108 ,
int V_109 )
{
int V_110 ;
struct V_111 V_112 ;
struct V_113 V_114 ;
int V_115 = 0 ;
char * V_116 = V_5 ;
int V_117 = V_108 ;
F_20 ( L_81 ) ;
if ( ! V_107 || ! V_5 || ! V_108 ) {
F_18 ( L_82 , V_107 , V_5 ,
V_108 ) ;
return - V_118 ;
}
if ( V_119 ) {
if ( V_105 ) {
if ( ! F_21 () )
F_10 ( L_83 , V_120 -> V_121 ) ;
else
F_10 ( L_84 ) ;
F_10 ( L_85
L_86 , V_107 , V_5 , V_108 , V_109 ) ;
F_3 ( V_5 , V_108 ) ;
}
}
do {
V_107 -> V_122 -> V_123 = V_124 ;
V_114 . V_125 = V_5 ;
V_114 . V_126 = V_108 ;
V_112 . V_127 = NULL ;
V_112 . V_128 = 0 ;
V_112 . V_129 = NULL ;
V_112 . V_130 = 0 ;
V_112 . V_128 = 0 ;
V_112 . V_109 = V_109 | V_131 ;
if ( V_105 )
V_110 = F_22 ( V_107 , & V_112 , & V_114 , 1 , V_108 ) ;
else
V_110 = F_23 ( V_107 , & V_112 , & V_114 , 1 , V_108 ,
V_132 ) ;
if ( V_110 <= 0 ) {
F_10 ( L_87 ,
V_105 ? L_88 : L_89 , V_107 , V_5 , V_108 ,
V_110 , V_115 ) ;
goto V_133;
}
V_108 -= V_110 ;
V_5 += V_110 ;
V_115 += V_110 ;
} while ( V_108 > 0 );
if ( V_119 ) {
if ( ! V_105 ) {
if ( ! F_21 () )
F_10 ( L_83 , V_120 -> V_121 ) ;
else
F_10 ( L_84 ) ;
F_10 ( L_90 ) ;
F_3 ( V_116 , V_117 ) ;
F_10 ( L_91 ,
V_117 , V_110 , V_108 , V_115 ) ;
}
if ( V_105 )
F_10 ( L_92 , V_115 ) ;
}
return V_115 ;
V_133:
return V_110 ;
}
struct V_106 * F_24 ( unsigned int V_134 )
{
struct V_106 * V_106 ;
struct V_135 * V_135 ;
struct V_136 * V_136 ;
V_135 = F_25 ( V_134 ) ;
if ( ! V_135 ) {
F_18 ( L_93 ) ;
return NULL ;
}
V_136 = V_135 -> V_137 -> V_138 ;
if ( ! V_136 || ! F_26 ( V_136 -> V_139 ) )
return NULL ;
V_106 = F_27 ( V_136 ) ;
return V_106 ;
}
static unsigned int F_28 ( unsigned int V_140 )
{
V_140 &= ~ V_141 ;
return V_140 ;
}
static void F_29 ( struct V_89 * V_90 , struct V_75 * V_75 ,
int V_142 )
{
struct V_143 * V_144 = & V_90 -> V_97 . V_98 ;
if ( V_142 ) {
V_144 -> V_78 =
F_28 ( V_75 -> V_78 ) ;
V_144 -> V_80 = V_75 -> V_80 ;
V_144 -> V_83 = V_75 -> V_83 ;
V_144 -> V_84 = V_75 -> V_84 ;
V_144 -> V_85 = V_75 -> V_85 ;
} else {
V_75 -> V_78 = V_144 -> V_78 ;
V_75 -> V_80 = V_144 -> V_80 ;
V_75 -> V_83 = V_144 -> V_83 ;
V_75 -> V_84 = V_144 -> V_84 ;
V_75 -> V_85 = V_144 -> V_85 ;
}
}
static void F_30 ( struct V_89 * V_90 , struct V_75 * V_75 ,
int V_142 )
{
struct V_145 * V_146 = & V_90 -> V_97 . V_102 ;
if ( V_142 ) {
V_146 -> V_77 = V_75 -> V_77 ;
V_146 -> V_81 = V_75 -> V_81 ;
V_146 -> V_83 = V_75 -> V_83 ;
V_146 -> V_84 = V_75 -> V_84 ;
V_146 -> V_86 = V_75 -> V_86 ;
} else {
V_75 -> V_77 = V_146 -> V_77 ;
V_75 -> V_81 = V_146 -> V_81 ;
V_75 -> V_83 = V_146 -> V_83 ;
V_75 -> V_84 = V_146 -> V_84 ;
V_75 -> V_86 = V_146 -> V_86 ;
}
}
void F_31 ( struct V_89 * V_90 , struct V_75 * V_75 , int V_53 ,
int V_142 )
{
switch ( V_53 ) {
case V_96 :
F_29 ( V_90 , V_75 , V_142 ) ;
break;
case V_101 :
F_30 ( V_90 , V_75 , V_142 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
static void F_32 ( struct V_147 * V_91 , int V_105 )
{
if ( V_105 ) {
V_91 -> V_92 = F_33 ( V_91 -> V_92 ) ;
V_91 -> V_93 = F_33 ( V_91 -> V_93 ) ;
V_91 -> V_94 = F_33 ( V_91 -> V_94 ) ;
V_91 -> V_95 = F_33 ( V_91 -> V_95 ) ;
V_91 -> V_13 = F_33 ( V_91 -> V_13 ) ;
} else {
V_91 -> V_92 = F_34 ( V_91 -> V_92 ) ;
V_91 -> V_93 = F_34 ( V_91 -> V_93 ) ;
V_91 -> V_94 = F_34 ( V_91 -> V_94 ) ;
V_91 -> V_95 = F_34 ( V_91 -> V_95 ) ;
V_91 -> V_13 = F_34 ( V_91 -> V_13 ) ;
}
}
static void F_35 ( struct V_143 * V_90 ,
int V_105 )
{
if ( V_105 ) {
V_90 -> V_78 = F_33 ( V_90 -> V_78 ) ;
F_36 ( & V_90 -> V_80 ) ;
F_36 ( & V_90 -> V_83 ) ;
F_36 ( & V_90 -> V_84 ) ;
F_36 ( & V_90 -> V_85 ) ;
} else {
V_90 -> V_78 = F_34 ( V_90 -> V_78 ) ;
F_37 ( & V_90 -> V_80 ) ;
F_37 ( & V_90 -> V_83 ) ;
F_37 ( & V_90 -> V_84 ) ;
F_37 ( & V_90 -> V_85 ) ;
}
}
static void F_38 ( struct V_145 * V_90 ,
int V_105 )
{
if ( V_105 ) {
F_36 ( & V_90 -> V_77 ) ;
F_36 ( & V_90 -> V_81 ) ;
F_36 ( & V_90 -> V_83 ) ;
F_36 ( & V_90 -> V_84 ) ;
F_36 ( & V_90 -> V_86 ) ;
} else {
F_37 ( & V_90 -> V_77 ) ;
F_37 ( & V_90 -> V_81 ) ;
F_37 ( & V_90 -> V_83 ) ;
F_37 ( & V_90 -> V_84 ) ;
F_37 ( & V_90 -> V_86 ) ;
}
}
static void F_39 ( struct V_148 * V_90 ,
int V_105 )
{
if ( V_105 )
V_90 -> V_93 = F_33 ( V_90 -> V_93 ) ;
else
V_90 -> V_93 = F_34 ( V_90 -> V_93 ) ;
}
static void F_40 ( struct V_149 * V_90 ,
int V_105 )
{
if ( V_105 )
F_36 ( & V_90 -> V_77 ) ;
else
F_37 ( & V_90 -> V_77 ) ;
}
void F_41 ( struct V_89 * V_90 , int V_105 )
{
T_4 V_53 = 0 ;
if ( V_105 )
V_53 = V_90 -> V_91 . V_92 ;
F_32 ( & V_90 -> V_91 , V_105 ) ;
if ( ! V_105 )
V_53 = V_90 -> V_91 . V_92 ;
switch ( V_53 ) {
case V_96 :
F_35 ( & V_90 -> V_97 . V_98 , V_105 ) ;
break;
case V_101 :
F_38 ( & V_90 -> V_97 . V_102 , V_105 ) ;
break;
case V_99 :
F_39 ( & V_90 -> V_97 . V_100 , V_105 ) ;
break;
case V_103 :
F_40 ( & V_90 -> V_97 . V_104 , V_105 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
static void F_42 (
struct V_150 * V_151 , int V_105 )
{
if ( V_105 ) {
V_151 -> V_152 = F_33 ( V_151 -> V_152 ) ;
V_151 -> V_153 = F_33 ( V_151 -> V_153 ) ;
V_151 -> V_77 = F_33 ( V_151 -> V_77 ) ;
V_151 -> V_81 = F_33 ( V_151 -> V_81 ) ;
} else {
V_151 -> V_152 = F_34 ( V_151 -> V_152 ) ;
V_151 -> V_153 = F_34 ( V_151 -> V_153 ) ;
V_151 -> V_77 = F_34 ( V_151 -> V_77 ) ;
V_151 -> V_81 = F_34 ( V_151 -> V_81 ) ;
}
}
static void F_43 ( struct V_150 * V_151 ,
struct V_154 * V_155 , int V_142 )
{
if ( V_142 ) {
V_151 -> V_152 = V_155 -> V_152 ;
V_151 -> V_153 = V_155 -> V_153 ;
V_151 -> V_77 = V_155 -> V_77 ;
V_151 -> V_81 = V_155 -> V_81 ;
} else {
V_155 -> V_152 = V_151 -> V_152 ;
V_155 -> V_153 = V_151 -> V_153 ;
V_155 -> V_77 = V_151 -> V_77 ;
V_155 -> V_81 = V_151 -> V_81 ;
}
}
void * F_44 ( struct V_75 * V_75 , T_1 * V_9 )
{
void * V_8 ;
struct V_150 * V_151 ;
int V_156 = V_75 -> V_84 ;
T_1 V_108 = V_156 * sizeof( * V_151 ) ;
int V_21 ;
V_8 = F_45 ( V_108 , V_157 ) ;
if ( ! V_8 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ ) {
V_151 = V_8 + ( V_21 * sizeof( * V_151 ) ) ;
F_43 ( V_151 , & V_75 -> V_158 [ V_21 ] , 1 ) ;
F_42 ( V_151 , 1 ) ;
}
* V_9 = V_108 ;
return V_8 ;
}
int F_46 ( struct V_159 * V_160 , struct V_75 * V_75 )
{
void * V_8 ;
struct V_150 * V_151 ;
int V_156 = V_75 -> V_84 ;
int V_108 = V_156 * sizeof( * V_151 ) ;
int V_21 ;
int V_161 ;
int V_162 = 0 ;
if ( ! F_47 ( V_75 -> V_76 ) )
return 0 ;
if ( V_156 == 0 ) {
return 0 ;
}
V_8 = F_45 ( V_108 , V_157 ) ;
if ( ! V_8 )
return - V_163 ;
V_161 = F_19 ( 0 , V_160 -> V_164 , V_8 , V_108 , 0 ) ;
if ( V_161 != V_108 ) {
F_48 ( & V_75 -> V_2 -> V_2 , L_94 ,
V_161 ) ;
F_49 ( V_8 ) ;
if ( V_160 -> V_165 == V_166 )
F_50 ( V_160 , V_167 ) ;
else
F_50 ( V_160 , V_168 ) ;
return - V_169 ;
}
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ ) {
V_151 = V_8 + ( V_21 * sizeof( * V_151 ) ) ;
F_42 ( V_151 , 0 ) ;
F_43 ( V_151 , & V_75 -> V_158 [ V_21 ] , 0 ) ;
V_162 += V_75 -> V_158 [ V_21 ] . V_81 ;
}
F_49 ( V_8 ) ;
if ( V_162 != V_75 -> V_81 ) {
F_48 ( & V_75 -> V_2 -> V_2 ,
L_95
L_96 ,
V_162 , V_75 -> V_81 ) ;
if ( V_160 -> V_165 == V_166 )
F_50 ( V_160 , V_167 ) ;
else
F_50 ( V_160 , V_168 ) ;
return - V_169 ;
}
return V_161 ;
}
int F_51 ( struct V_159 * V_160 , struct V_75 * V_75 )
{
int V_156 = V_75 -> V_84 ;
int V_21 ;
int V_161 ;
int V_170 = V_75 -> V_81 ;
if ( ! F_47 ( V_75 -> V_76 ) )
return 0 ;
if ( V_156 == 0 || V_75 -> V_81 == 0 )
return 0 ;
if ( V_75 -> V_81 == V_75 -> V_80 )
return 0 ;
for ( V_21 = V_156 - 1 ; V_21 > 0 ; V_21 -- ) {
V_170 -= V_75 -> V_158 [ V_21 ] . V_81 ;
memmove ( V_75 -> V_79 + V_75 -> V_158 [ V_21 ] . V_152 ,
V_75 -> V_79 + V_170 ,
V_75 -> V_158 [ V_21 ] . V_81 ) ;
}
return V_161 ;
}
int F_52 ( struct V_159 * V_160 , struct V_75 * V_75 )
{
int V_161 ;
int V_108 ;
if ( V_160 -> V_165 == V_166 ) {
if ( F_9 ( V_75 -> V_76 ) )
return 0 ;
V_108 = V_75 -> V_80 ;
} else {
if ( F_53 ( V_75 -> V_76 ) )
return 0 ;
V_108 = V_75 -> V_81 ;
}
if ( ! ( V_108 > 0 ) )
return 0 ;
V_161 = F_19 ( 0 , V_160 -> V_164 , ( char * ) V_75 -> V_79 ,
V_108 , 0 ) ;
if ( V_161 != V_108 ) {
F_48 ( & V_75 -> V_2 -> V_2 , L_97 , V_161 ) ;
if ( V_160 -> V_165 == V_166 ) {
F_50 ( V_160 , V_167 ) ;
} else {
F_50 ( V_160 , V_168 ) ;
return - V_169 ;
}
}
return V_161 ;
}
static int T_5 F_54 ( void )
{
F_55 ( V_171 L_98 V_172 L_21 ) ;
return 0 ;
}
static void T_6 F_56 ( void )
{
return;
}
