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
F_12 ( V_2 , L_30 , V_20 -> V_44 ) ;
}
static void F_14 ( T_3 V_45 )
{
switch ( V_45 & V_46 ) {
case V_47 :
F_10 ( L_31 ) ;
break;
case V_48 :
F_10 ( L_32 ) ;
break;
case V_49 :
F_10 ( L_33 ) ;
break;
case V_50 :
F_10 ( L_34 ) ;
break;
default:
F_10 ( L_35 ) ;
break;
}
}
static void F_15 ( struct V_51 * V_52 )
{
if ( ! V_52 ) {
F_10 ( L_36 ) ;
return;
}
F_10 ( L_37 ) ;
F_10 ( L_38
L_39 , V_52 -> V_53 , V_52 -> V_54 ,
V_52 -> V_55 , V_52 -> V_56 , V_52 -> V_57 ) ;
F_10 ( L_40 ) ;
if ( ( V_52 -> V_53 & V_58 ) == V_59 ) {
F_10 ( L_41 ) ;
switch ( V_52 -> V_54 ) {
case V_60 :
F_10 ( L_42 ) ;
break;
case V_61 :
F_10 ( L_43 ) ;
break;
case V_62 :
F_10 ( L_44 ) ;
break;
case V_63 :
F_10 ( L_45 ) ;
break;
case V_64 :
F_10 ( L_46 ) ;
break;
case V_65 :
F_10 ( L_47 ) ;
break;
case V_66 :
F_10 ( L_48 ) ;
break;
case V_67 :
F_10 ( L_49 ) ;
break;
case V_68 :
F_10 ( L_50 ) ;
break;
case V_69 :
F_10 ( L_51 ) ;
break;
case V_70 :
F_10 ( L_52 ) ;
break;
default:
F_10 ( L_53 , V_52 -> V_54 ) ;
break;
}
F_14 ( V_52 -> V_53 ) ;
} else if ( ( V_52 -> V_53 & V_58 ) == V_71 ) {
F_10 ( L_54 ) ;
} else if ( ( V_52 -> V_53 & V_58 ) == V_72 ) {
F_10 ( L_55 ) ;
} else if ( ( V_52 -> V_53 & V_58 ) == V_73 ) {
F_10 ( L_56 ) ;
}
}
void F_16 ( struct V_74 * V_74 )
{
struct V_1 * V_2 ;
if ( ! V_74 ) {
F_10 ( L_57 ) ;
return;
}
if ( ! V_74 -> V_2 ) {
F_10 ( L_58 ) ;
return;
}
V_2 = & V_74 -> V_2 -> V_2 ;
F_12 ( V_2 , L_59 , V_74 ) ;
F_12 ( V_2 , L_60 , V_74 -> V_2 ) ;
F_11 ( V_74 -> V_2 ) ;
F_12 ( V_2 , L_61 , V_74 -> V_75 ) ;
F_5 ( V_74 -> V_75 ) ;
F_12 ( V_2 , L_62 , V_74 -> V_76 ) ;
F_12 ( V_2 , L_63 , V_74 -> V_77 ) ;
F_12 ( V_2 , L_64 , V_74 -> V_78 ) ;
F_12 ( V_2 , L_65 ,
V_74 -> V_79 ) ;
F_12 ( V_2 , L_66 , V_74 -> V_80 ) ;
F_12 ( V_2 , L_67 , V_74 -> V_81 ) ;
if ( V_74 -> V_81 && F_6 ( V_74 -> V_75 ) == V_17 )
F_15 (
(struct V_51 * ) V_74 -> V_81 ) ;
F_12 ( V_2 , L_68 , V_74 -> V_82 ) ;
F_12 ( V_2 , L_69 , V_74 -> V_83 ) ;
F_12 ( V_2 , L_70 , V_74 -> V_84 ) ;
F_12 ( V_2 , L_71 , V_74 -> V_85 ) ;
F_12 ( V_2 , L_72 , V_74 -> V_86 ) ;
F_12 ( V_2 , L_73 , V_74 -> V_87 ) ;
}
void F_17 ( struct V_88 * V_89 )
{
F_10 ( L_74 ,
V_89 -> V_90 . V_91 ,
V_89 -> V_90 . V_92 ,
V_89 -> V_90 . V_93 ,
V_89 -> V_90 . V_94 ,
V_89 -> V_90 . V_13 ) ;
switch ( V_89 -> V_90 . V_91 ) {
case V_95 :
F_10 ( L_75
L_76 ,
V_89 -> V_96 . V_97 . V_77 ,
V_89 -> V_96 . V_97 . V_79 ,
V_89 -> V_96 . V_97 . V_82 ,
V_89 -> V_96 . V_97 . V_83 ,
V_89 -> V_96 . V_97 . V_84 ) ;
break;
case V_98 :
F_10 ( L_77 ,
V_89 -> V_96 . V_99 . V_92 ) ;
break;
case V_100 :
F_10 ( L_78 ,
V_89 -> V_96 . V_101 . V_76 ,
V_89 -> V_96 . V_101 . V_80 ,
V_89 -> V_96 . V_101 . V_82 ,
V_89 -> V_96 . V_101 . V_83 ,
V_89 -> V_96 . V_101 . V_85 ) ;
break;
case V_102 :
F_10 ( L_79 ,
V_89 -> V_96 . V_103 . V_76 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
int F_19 ( struct V_104 * V_105 , void * V_5 , int V_106 )
{
int V_107 ;
struct V_108 V_109 ;
struct V_110 V_111 ;
int V_112 = 0 ;
char * V_113 = V_5 ;
int V_114 = V_106 ;
F_20 ( L_81 ) ;
if ( ! V_105 || ! V_5 || ! V_106 ) {
F_18 ( L_82 , V_105 , V_5 ,
V_106 ) ;
return - V_115 ;
}
do {
V_105 -> V_116 -> V_117 = V_118 ;
V_111 . V_119 = V_5 ;
V_111 . V_120 = V_106 ;
V_109 . V_121 = NULL ;
V_109 . V_122 = 0 ;
V_109 . V_123 = NULL ;
V_109 . V_124 = 0 ;
V_109 . V_122 = 0 ;
V_109 . V_125 = V_126 ;
V_107 = F_21 ( V_105 , & V_109 , & V_111 , 1 , V_106 , V_127 ) ;
if ( V_107 <= 0 ) {
F_10 ( L_83 ,
V_105 , V_5 , V_106 , V_107 , V_112 ) ;
goto V_128;
}
V_106 -= V_107 ;
V_5 += V_107 ;
V_112 += V_107 ;
} while ( V_106 > 0 );
if ( V_129 ) {
if ( ! F_22 () )
F_10 ( L_84 , V_130 -> V_131 ) ;
else
F_10 ( L_85 ) ;
F_10 ( L_86 ) ;
F_3 ( V_113 , V_114 ) ;
F_10 ( L_87 ,
V_114 , V_107 , V_106 , V_112 ) ;
}
return V_112 ;
V_128:
return V_107 ;
}
struct V_104 * F_23 ( unsigned int V_132 )
{
struct V_104 * V_104 ;
struct V_133 * V_133 ;
struct V_134 * V_134 ;
V_133 = F_24 ( V_132 ) ;
if ( ! V_133 ) {
F_18 ( L_88 ) ;
return NULL ;
}
V_134 = V_133 -> V_135 -> V_136 ;
if ( ! V_134 || ! F_25 ( V_134 -> V_137 ) ) {
F_26 ( V_133 ) ;
return NULL ;
}
V_104 = F_27 ( V_134 ) ;
return V_104 ;
}
static unsigned int F_28 ( unsigned int V_138 )
{
V_138 &= ~ V_139 ;
return V_138 ;
}
static void F_29 ( struct V_88 * V_89 , struct V_74 * V_74 ,
int V_140 )
{
struct V_141 * V_142 = & V_89 -> V_96 . V_97 ;
if ( V_140 ) {
V_142 -> V_77 =
F_28 ( V_74 -> V_77 ) ;
V_142 -> V_79 = V_74 -> V_79 ;
V_142 -> V_82 = V_74 -> V_82 ;
V_142 -> V_83 = V_74 -> V_83 ;
V_142 -> V_84 = V_74 -> V_84 ;
} else {
V_74 -> V_77 = V_142 -> V_77 ;
V_74 -> V_79 = V_142 -> V_79 ;
V_74 -> V_82 = V_142 -> V_82 ;
V_74 -> V_83 = V_142 -> V_83 ;
V_74 -> V_84 = V_142 -> V_84 ;
}
}
static void F_30 ( struct V_88 * V_89 , struct V_74 * V_74 ,
int V_140 )
{
struct V_143 * V_144 = & V_89 -> V_96 . V_101 ;
if ( V_140 ) {
V_144 -> V_76 = V_74 -> V_76 ;
V_144 -> V_80 = V_74 -> V_80 ;
V_144 -> V_82 = V_74 -> V_82 ;
V_144 -> V_83 = V_74 -> V_83 ;
V_144 -> V_85 = V_74 -> V_85 ;
} else {
V_74 -> V_76 = V_144 -> V_76 ;
V_74 -> V_80 = V_144 -> V_80 ;
V_74 -> V_82 = V_144 -> V_82 ;
V_74 -> V_83 = V_144 -> V_83 ;
V_74 -> V_85 = V_144 -> V_85 ;
}
}
void F_31 ( struct V_88 * V_89 , struct V_74 * V_74 , int V_52 ,
int V_140 )
{
switch ( V_52 ) {
case V_95 :
F_29 ( V_89 , V_74 , V_140 ) ;
break;
case V_100 :
F_30 ( V_89 , V_74 , V_140 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
static void F_32 ( struct V_145 * V_90 , int V_146 )
{
if ( V_146 ) {
V_90 -> V_91 = F_33 ( V_90 -> V_91 ) ;
V_90 -> V_92 = F_33 ( V_90 -> V_92 ) ;
V_90 -> V_93 = F_33 ( V_90 -> V_93 ) ;
V_90 -> V_94 = F_33 ( V_90 -> V_94 ) ;
V_90 -> V_13 = F_33 ( V_90 -> V_13 ) ;
} else {
V_90 -> V_91 = F_34 ( V_90 -> V_91 ) ;
V_90 -> V_92 = F_34 ( V_90 -> V_92 ) ;
V_90 -> V_93 = F_34 ( V_90 -> V_93 ) ;
V_90 -> V_94 = F_34 ( V_90 -> V_94 ) ;
V_90 -> V_13 = F_34 ( V_90 -> V_13 ) ;
}
}
static void F_35 ( struct V_141 * V_89 ,
int V_146 )
{
if ( V_146 ) {
V_89 -> V_77 = F_33 ( V_89 -> V_77 ) ;
F_36 ( & V_89 -> V_79 ) ;
F_36 ( & V_89 -> V_82 ) ;
F_36 ( & V_89 -> V_83 ) ;
F_36 ( & V_89 -> V_84 ) ;
} else {
V_89 -> V_77 = F_34 ( V_89 -> V_77 ) ;
F_37 ( & V_89 -> V_79 ) ;
F_37 ( & V_89 -> V_82 ) ;
F_37 ( & V_89 -> V_83 ) ;
F_37 ( & V_89 -> V_84 ) ;
}
}
static void F_38 ( struct V_143 * V_89 ,
int V_146 )
{
if ( V_146 ) {
F_36 ( & V_89 -> V_76 ) ;
F_36 ( & V_89 -> V_80 ) ;
F_36 ( & V_89 -> V_82 ) ;
F_36 ( & V_89 -> V_83 ) ;
F_36 ( & V_89 -> V_85 ) ;
} else {
F_37 ( & V_89 -> V_76 ) ;
F_37 ( & V_89 -> V_80 ) ;
F_37 ( & V_89 -> V_82 ) ;
F_37 ( & V_89 -> V_83 ) ;
F_37 ( & V_89 -> V_85 ) ;
}
}
static void F_39 ( struct V_147 * V_89 ,
int V_146 )
{
if ( V_146 )
V_89 -> V_92 = F_33 ( V_89 -> V_92 ) ;
else
V_89 -> V_92 = F_34 ( V_89 -> V_92 ) ;
}
static void F_40 ( struct V_148 * V_89 ,
int V_146 )
{
if ( V_146 )
F_36 ( & V_89 -> V_76 ) ;
else
F_37 ( & V_89 -> V_76 ) ;
}
void F_41 ( struct V_88 * V_89 , int V_146 )
{
T_4 V_52 = 0 ;
if ( V_146 )
V_52 = V_89 -> V_90 . V_91 ;
F_32 ( & V_89 -> V_90 , V_146 ) ;
if ( ! V_146 )
V_52 = V_89 -> V_90 . V_91 ;
switch ( V_52 ) {
case V_95 :
F_35 ( & V_89 -> V_96 . V_97 , V_146 ) ;
break;
case V_100 :
F_38 ( & V_89 -> V_96 . V_101 , V_146 ) ;
break;
case V_98 :
F_39 ( & V_89 -> V_96 . V_99 , V_146 ) ;
break;
case V_102 :
F_40 ( & V_89 -> V_96 . V_103 , V_146 ) ;
break;
default:
F_18 ( L_80 ) ;
break;
}
}
static void F_42 (
struct V_149 * V_150 , int V_146 )
{
if ( V_146 ) {
V_150 -> V_151 = F_33 ( V_150 -> V_151 ) ;
V_150 -> V_152 = F_33 ( V_150 -> V_152 ) ;
V_150 -> V_76 = F_33 ( V_150 -> V_76 ) ;
V_150 -> V_80 = F_33 ( V_150 -> V_80 ) ;
} else {
V_150 -> V_151 = F_34 ( V_150 -> V_151 ) ;
V_150 -> V_152 = F_34 ( V_150 -> V_152 ) ;
V_150 -> V_76 = F_34 ( V_150 -> V_76 ) ;
V_150 -> V_80 = F_34 ( V_150 -> V_80 ) ;
}
}
static void F_43 ( struct V_149 * V_150 ,
struct V_153 * V_154 , int V_140 )
{
if ( V_140 ) {
V_150 -> V_151 = V_154 -> V_151 ;
V_150 -> V_152 = V_154 -> V_152 ;
V_150 -> V_76 = V_154 -> V_76 ;
V_150 -> V_80 = V_154 -> V_80 ;
} else {
V_154 -> V_151 = V_150 -> V_151 ;
V_154 -> V_152 = V_150 -> V_152 ;
V_154 -> V_76 = V_150 -> V_76 ;
V_154 -> V_80 = V_150 -> V_80 ;
}
}
struct V_149 *
F_44 ( struct V_74 * V_74 , T_1 * V_9 )
{
struct V_149 * V_150 ;
int V_155 = V_74 -> V_83 ;
T_1 V_106 = V_155 * sizeof( * V_150 ) ;
int V_21 ;
V_150 = F_45 ( V_106 , V_156 ) ;
if ( ! V_150 )
return NULL ;
for ( V_21 = 0 ; V_21 < V_155 ; V_21 ++ ) {
F_43 ( & V_150 [ V_21 ] , & V_74 -> V_157 [ V_21 ] , 1 ) ;
F_42 ( & V_150 [ V_21 ] , 1 ) ;
}
* V_9 = V_106 ;
return V_150 ;
}
int F_46 ( struct V_158 * V_159 , struct V_74 * V_74 )
{
void * V_8 ;
struct V_149 * V_150 ;
int V_155 = V_74 -> V_83 ;
int V_106 = V_155 * sizeof( * V_150 ) ;
int V_21 ;
int V_160 ;
int V_161 = 0 ;
if ( ! F_47 ( V_74 -> V_75 ) )
return 0 ;
if ( V_155 == 0 ) {
return 0 ;
}
V_8 = F_45 ( V_106 , V_156 ) ;
if ( ! V_8 )
return - V_162 ;
V_160 = F_19 ( V_159 -> V_163 , V_8 , V_106 ) ;
if ( V_160 != V_106 ) {
F_48 ( & V_74 -> V_2 -> V_2 , L_89 ,
V_160 ) ;
F_49 ( V_8 ) ;
if ( V_159 -> V_164 == V_165 )
F_50 ( V_159 , V_166 ) ;
else
F_50 ( V_159 , V_167 ) ;
return - V_168 ;
}
V_150 = (struct V_149 * ) V_8 ;
for ( V_21 = 0 ; V_21 < V_155 ; V_21 ++ ) {
F_42 ( & V_150 [ V_21 ] , 0 ) ;
F_43 ( & V_150 [ V_21 ] , & V_74 -> V_157 [ V_21 ] , 0 ) ;
V_161 += V_74 -> V_157 [ V_21 ] . V_80 ;
}
F_49 ( V_8 ) ;
if ( V_161 != V_74 -> V_80 ) {
F_48 ( & V_74 -> V_2 -> V_2 ,
L_90
L_91 ,
V_161 , V_74 -> V_80 ) ;
if ( V_159 -> V_164 == V_165 )
F_50 ( V_159 , V_166 ) ;
else
F_50 ( V_159 , V_167 ) ;
return - V_168 ;
}
return V_160 ;
}
void F_51 ( struct V_158 * V_159 , struct V_74 * V_74 )
{
int V_155 = V_74 -> V_83 ;
int V_21 ;
int V_169 = V_74 -> V_80 ;
if ( ! F_47 ( V_74 -> V_75 ) )
return;
if ( V_155 == 0 || V_74 -> V_80 == 0 )
return;
if ( V_74 -> V_80 == V_74 -> V_79 )
return;
for ( V_21 = V_155 - 1 ; V_21 > 0 ; V_21 -- ) {
V_169 -= V_74 -> V_157 [ V_21 ] . V_80 ;
memmove ( V_74 -> V_78 + V_74 -> V_157 [ V_21 ] . V_151 ,
V_74 -> V_78 + V_169 ,
V_74 -> V_157 [ V_21 ] . V_80 ) ;
}
}
int F_52 ( struct V_158 * V_159 , struct V_74 * V_74 )
{
int V_160 ;
int V_106 ;
if ( V_159 -> V_164 == V_165 ) {
if ( F_9 ( V_74 -> V_75 ) )
return 0 ;
V_106 = V_74 -> V_79 ;
} else {
if ( F_53 ( V_74 -> V_75 ) )
return 0 ;
V_106 = V_74 -> V_80 ;
}
if ( ! ( V_106 > 0 ) )
return 0 ;
V_160 = F_19 ( V_159 -> V_163 , V_74 -> V_78 , V_106 ) ;
if ( V_160 != V_106 ) {
F_48 ( & V_74 -> V_2 -> V_2 , L_92 , V_160 ) ;
if ( V_159 -> V_164 == V_165 ) {
F_50 ( V_159 , V_166 ) ;
} else {
F_50 ( V_159 , V_167 ) ;
return - V_168 ;
}
}
return V_160 ;
}
static int T_5 F_54 ( void )
{
F_55 ( V_170 L_93 V_171 L_21 ) ;
return 0 ;
}
static void T_6 F_56 ( void )
{
return;
}
