static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_7 )
{
if ( sscanf ( V_5 , L_2 , & V_6 ) != 1 )
return - V_8 ;
return V_7 ;
}
static void F_3 ( char * V_9 , int V_10 )
{
F_4 ( V_11 , L_3 , V_12 , 16 , 4 ,
V_9 , V_10 , false ) ;
}
static void F_5 ( unsigned int V_13 )
{
unsigned char type = F_6 ( V_13 ) ;
unsigned char V_14 = F_7 ( V_13 ) ;
unsigned char V_2 = F_8 ( V_13 ) ;
unsigned char V_15 = F_9 ( V_13 ) ;
F_10 ( L_4 , V_2 , V_14 , V_15 ? L_5 : L_6 ) ;
switch ( type ) {
case V_16 :
F_10 ( L_7 ) ;
break;
case V_17 :
F_10 ( L_8 ) ;
break;
case V_18 :
F_10 ( L_9 ) ;
break;
case V_19 :
F_10 ( L_10 ) ;
break;
default:
F_10 ( L_11 ) ;
break;
}
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
int V_22 ;
F_12 ( V_2 , L_12 ,
V_21 -> V_23 , V_21 -> V_24 , F_13 ( V_21 -> V_25 ) ) ;
F_10 ( L_13 , V_21 -> V_26 , V_21 -> V_27 ) ;
F_12 ( V_2 , L_14 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_10 ( L_15 , V_22 ) ;
F_10 ( L_16 ) ;
F_12 ( V_2 , L_17 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_10 ( L_15 , ( V_21 -> V_28 [ 0 ] & ( 1 << V_22 ) ) ? 1 : 0 ) ;
F_10 ( L_16 ) ;
F_12 ( V_2 , L_18 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ )
F_10 ( L_15 , ( V_21 -> V_28 [ 1 ] & ( 1 << V_22 ) ) ? 1 : 0 ) ;
F_10 ( L_16 ) ;
F_12 ( V_2 , L_19 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
if ( V_21 -> V_29 [ V_22 ] )
F_10 ( L_15 ,
F_14 ( V_21 -> V_29 [ V_22 ] -> V_30 . V_31 ) ) ;
}
F_10 ( L_16 ) ;
F_12 ( V_2 , L_20 ) ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
if ( V_21 -> V_32 [ V_22 ] )
F_10 ( L_15 ,
F_14 ( V_21 -> V_32 [ V_22 ] -> V_30 . V_31 ) ) ;
}
F_10 ( L_16 ) ;
F_12 ( V_2 , L_21 , V_21 -> V_33 , V_21 -> V_34 ) ;
F_12 ( V_2 ,
L_22 ,
& V_21 -> V_35 , V_21 -> V_36 ,
V_21 -> V_37 , V_21 -> V_38 ) ;
F_12 ( V_2 , L_23 ,
V_21 -> V_39 , V_21 -> V_40 ) ;
F_12 ( V_2 , L_24 , V_21 -> V_41 ) ;
}
static void F_15 ( T_3 V_42 )
{
switch ( V_42 & V_43 ) {
case V_44 :
F_10 ( L_25 ) ;
break;
case V_45 :
F_10 ( L_26 ) ;
break;
case V_46 :
F_10 ( L_27 ) ;
break;
case V_47 :
F_10 ( L_28 ) ;
break;
default:
F_10 ( L_29 ) ;
break;
}
}
static void F_16 ( struct V_48 * V_49 )
{
if ( ! V_49 ) {
F_10 ( L_30 ) ;
return;
}
F_10 ( L_31 ) ;
F_10 ( L_32 ,
V_49 -> V_50 , V_49 -> V_51 ,
V_49 -> V_52 , V_49 -> V_53 , V_49 -> V_54 ) ;
F_10 ( L_33 ) ;
if ( ( V_49 -> V_50 & V_55 ) == V_56 ) {
F_10 ( L_34 ) ;
switch ( V_49 -> V_51 ) {
case V_57 :
F_10 ( L_35 ) ;
break;
case V_58 :
F_10 ( L_36 ) ;
break;
case V_59 :
F_10 ( L_37 ) ;
break;
case V_60 :
F_10 ( L_38 ) ;
break;
case V_61 :
F_10 ( L_39 ) ;
break;
case V_62 :
F_10 ( L_40 ) ;
break;
case V_63 :
F_10 ( L_41 ) ;
break;
case V_64 :
F_10 ( L_42 ) ;
break;
case V_65 :
F_10 ( L_43 ) ;
break;
case V_66 :
F_10 ( L_44 ) ;
break;
case V_67 :
F_10 ( L_45 ) ;
break;
default:
F_10 ( L_46 , V_49 -> V_51 ) ;
break;
}
F_15 ( V_49 -> V_50 ) ;
} else if ( ( V_49 -> V_50 & V_55 ) == V_68 ) {
F_10 ( L_47 ) ;
} else if ( ( V_49 -> V_50 & V_55 ) == V_69 ) {
F_10 ( L_48 ) ;
} else if ( ( V_49 -> V_50 & V_55 ) == V_70 ) {
F_10 ( L_49 ) ;
}
}
void F_17 ( struct V_71 * V_71 )
{
struct V_1 * V_2 ;
if ( ! V_71 ) {
F_10 ( L_50 ) ;
return;
}
if ( ! V_71 -> V_2 ) {
F_10 ( L_51 ) ;
return;
}
V_2 = & V_71 -> V_2 -> V_2 ;
F_12 ( V_2 , L_52 , V_71 ) ;
F_12 ( V_2 , L_53 , V_71 -> V_2 ) ;
F_11 ( V_71 -> V_2 ) ;
F_12 ( V_2 , L_54 , V_71 -> V_72 ) ;
F_5 ( V_71 -> V_72 ) ;
F_12 ( V_2 , L_55 , V_71 -> V_73 ) ;
F_12 ( V_2 , L_56 , V_71 -> V_74 ) ;
F_12 ( V_2 , L_57 , V_71 -> V_75 ) ;
F_12 ( V_2 , L_58 ,
V_71 -> V_76 ) ;
F_12 ( V_2 , L_59 , V_71 -> V_77 ) ;
F_12 ( V_2 , L_60 , V_71 -> V_78 ) ;
if ( V_71 -> V_78 && F_6 ( V_71 -> V_72 ) == V_18 )
F_16 (
(struct V_48 * ) V_71 -> V_78 ) ;
F_12 ( V_2 , L_61 , V_71 -> V_79 ) ;
F_12 ( V_2 , L_62 , V_71 -> V_80 ) ;
F_12 ( V_2 , L_63 , V_71 -> V_81 ) ;
F_12 ( V_2 , L_64 , V_71 -> V_82 ) ;
F_12 ( V_2 , L_65 , V_71 -> V_83 ) ;
F_12 ( V_2 , L_66 , V_71 -> V_84 ) ;
}
void F_18 ( struct V_85 * V_86 )
{
F_10 ( L_67 ,
V_86 -> V_87 . V_88 ,
V_86 -> V_87 . V_89 ,
V_86 -> V_87 . V_90 ,
V_86 -> V_87 . V_91 ,
V_86 -> V_87 . V_14 ) ;
switch ( V_86 -> V_87 . V_88 ) {
case V_92 :
F_10 ( L_68 ,
V_86 -> V_93 . V_94 . V_74 ,
V_86 -> V_93 . V_94 . V_76 ,
V_86 -> V_93 . V_94 . V_79 ,
V_86 -> V_93 . V_94 . V_80 ,
V_86 -> V_93 . V_94 . V_81 ) ;
break;
case V_95 :
F_10 ( L_69 ,
V_86 -> V_93 . V_96 . V_89 ) ;
break;
case V_97 :
F_10 ( L_70 ,
V_86 -> V_93 . V_98 . V_73 ,
V_86 -> V_93 . V_98 . V_77 ,
V_86 -> V_93 . V_98 . V_79 ,
V_86 -> V_93 . V_98 . V_80 ,
V_86 -> V_93 . V_98 . V_82 ) ;
break;
case V_99 :
F_10 ( L_71 ,
V_86 -> V_93 . V_100 . V_73 ) ;
break;
default:
F_19 ( L_72 ) ;
break;
}
}
int F_20 ( struct V_101 * V_102 , void * V_5 , int V_103 )
{
int V_104 ;
struct V_105 V_106 = { . V_107 = V_5 , . V_108 = V_103 } ;
struct V_109 V_110 = { . V_111 = V_112 } ;
int V_113 = 0 ;
F_21 ( & V_110 . V_114 , V_115 | V_116 , & V_106 , 1 , V_103 ) ;
F_22 ( L_73 ) ;
if ( ! V_102 || ! V_5 || ! V_103 ) {
F_19 ( L_74 , V_102 , V_5 ,
V_103 ) ;
return - V_8 ;
}
do {
int V_117 = F_23 ( & V_110 ) ;
V_102 -> V_118 -> V_119 = V_120 ;
V_104 = F_24 ( V_102 , & V_110 , V_121 ) ;
if ( V_104 <= 0 ) {
F_10 ( L_75 ,
V_102 , V_5 + V_113 , V_117 , V_104 , V_113 ) ;
goto V_122;
}
V_113 += V_104 ;
} while ( F_23 ( & V_110 ) );
if ( V_123 ) {
if ( ! F_25 () )
F_10 ( L_76 , V_124 -> V_125 ) ;
else
F_10 ( L_77 ) ;
F_10 ( L_78 ) ;
F_3 ( V_5 , V_103 ) ;
F_10 ( L_79 ,
V_103 , V_104 , F_23 ( & V_110 ) , V_113 ) ;
}
return V_113 ;
V_122:
return V_104 ;
}
static unsigned int F_26 ( unsigned int V_126 )
{
V_126 &= ~ V_127 ;
return V_126 ;
}
static void F_27 ( struct V_85 * V_86 , struct V_71 * V_71 ,
int V_128 )
{
struct V_129 * V_130 = & V_86 -> V_93 . V_94 ;
if ( V_128 ) {
V_130 -> V_74 =
F_26 ( V_71 -> V_74 ) ;
V_130 -> V_76 = V_71 -> V_76 ;
V_130 -> V_79 = V_71 -> V_79 ;
V_130 -> V_80 = V_71 -> V_80 ;
V_130 -> V_81 = V_71 -> V_81 ;
} else {
V_71 -> V_74 = V_130 -> V_74 ;
V_71 -> V_76 = V_130 -> V_76 ;
V_71 -> V_79 = V_130 -> V_79 ;
V_71 -> V_80 = V_130 -> V_80 ;
V_71 -> V_81 = V_130 -> V_81 ;
}
}
static void F_28 ( struct V_85 * V_86 , struct V_71 * V_71 ,
int V_128 )
{
struct V_131 * V_132 = & V_86 -> V_93 . V_98 ;
if ( V_128 ) {
V_132 -> V_73 = V_71 -> V_73 ;
V_132 -> V_77 = V_71 -> V_77 ;
V_132 -> V_79 = V_71 -> V_79 ;
V_132 -> V_80 = V_71 -> V_80 ;
V_132 -> V_82 = V_71 -> V_82 ;
} else {
V_71 -> V_73 = V_132 -> V_73 ;
V_71 -> V_77 = V_132 -> V_77 ;
V_71 -> V_79 = V_132 -> V_79 ;
V_71 -> V_80 = V_132 -> V_80 ;
V_71 -> V_82 = V_132 -> V_82 ;
}
}
void F_29 ( struct V_85 * V_86 , struct V_71 * V_71 , int V_49 ,
int V_128 )
{
switch ( V_49 ) {
case V_92 :
F_27 ( V_86 , V_71 , V_128 ) ;
break;
case V_97 :
F_28 ( V_86 , V_71 , V_128 ) ;
break;
default:
F_19 ( L_72 ) ;
break;
}
}
static void F_30 ( struct V_133 * V_87 , int V_134 )
{
if ( V_134 ) {
V_87 -> V_88 = F_31 ( V_87 -> V_88 ) ;
V_87 -> V_89 = F_31 ( V_87 -> V_89 ) ;
V_87 -> V_90 = F_31 ( V_87 -> V_90 ) ;
V_87 -> V_91 = F_31 ( V_87 -> V_91 ) ;
V_87 -> V_14 = F_31 ( V_87 -> V_14 ) ;
} else {
V_87 -> V_88 = F_32 ( V_87 -> V_88 ) ;
V_87 -> V_89 = F_32 ( V_87 -> V_89 ) ;
V_87 -> V_90 = F_32 ( V_87 -> V_90 ) ;
V_87 -> V_91 = F_32 ( V_87 -> V_91 ) ;
V_87 -> V_14 = F_32 ( V_87 -> V_14 ) ;
}
}
static void F_33 ( struct V_129 * V_86 ,
int V_134 )
{
if ( V_134 ) {
V_86 -> V_74 = F_31 ( V_86 -> V_74 ) ;
F_34 ( & V_86 -> V_76 ) ;
F_34 ( & V_86 -> V_79 ) ;
F_34 ( & V_86 -> V_80 ) ;
F_34 ( & V_86 -> V_81 ) ;
} else {
V_86 -> V_74 = F_32 ( V_86 -> V_74 ) ;
F_35 ( & V_86 -> V_76 ) ;
F_35 ( & V_86 -> V_79 ) ;
F_35 ( & V_86 -> V_80 ) ;
F_35 ( & V_86 -> V_81 ) ;
}
}
static void F_36 ( struct V_131 * V_86 ,
int V_134 )
{
if ( V_134 ) {
F_34 ( & V_86 -> V_73 ) ;
F_34 ( & V_86 -> V_77 ) ;
F_34 ( & V_86 -> V_79 ) ;
F_34 ( & V_86 -> V_80 ) ;
F_34 ( & V_86 -> V_82 ) ;
} else {
F_35 ( & V_86 -> V_73 ) ;
F_35 ( & V_86 -> V_77 ) ;
F_35 ( & V_86 -> V_79 ) ;
F_35 ( & V_86 -> V_80 ) ;
F_35 ( & V_86 -> V_82 ) ;
}
}
static void F_37 ( struct V_135 * V_86 ,
int V_134 )
{
if ( V_134 )
V_86 -> V_89 = F_31 ( V_86 -> V_89 ) ;
else
V_86 -> V_89 = F_32 ( V_86 -> V_89 ) ;
}
static void F_38 ( struct V_136 * V_86 ,
int V_134 )
{
if ( V_134 )
F_34 ( & V_86 -> V_73 ) ;
else
F_35 ( & V_86 -> V_73 ) ;
}
void F_39 ( struct V_85 * V_86 , int V_134 )
{
T_4 V_49 = 0 ;
if ( V_134 )
V_49 = V_86 -> V_87 . V_88 ;
F_30 ( & V_86 -> V_87 , V_134 ) ;
if ( ! V_134 )
V_49 = V_86 -> V_87 . V_88 ;
switch ( V_49 ) {
case V_92 :
F_33 ( & V_86 -> V_93 . V_94 , V_134 ) ;
break;
case V_97 :
F_36 ( & V_86 -> V_93 . V_98 , V_134 ) ;
break;
case V_95 :
F_37 ( & V_86 -> V_93 . V_96 , V_134 ) ;
break;
case V_99 :
F_38 ( & V_86 -> V_93 . V_100 , V_134 ) ;
break;
default:
F_19 ( L_72 ) ;
break;
}
}
static void F_40 (
struct V_137 * V_138 , int V_134 )
{
if ( V_134 ) {
V_138 -> V_139 = F_31 ( V_138 -> V_139 ) ;
V_138 -> V_140 = F_31 ( V_138 -> V_140 ) ;
V_138 -> V_73 = F_31 ( V_138 -> V_73 ) ;
V_138 -> V_77 = F_31 ( V_138 -> V_77 ) ;
} else {
V_138 -> V_139 = F_32 ( V_138 -> V_139 ) ;
V_138 -> V_140 = F_32 ( V_138 -> V_140 ) ;
V_138 -> V_73 = F_32 ( V_138 -> V_73 ) ;
V_138 -> V_77 = F_32 ( V_138 -> V_77 ) ;
}
}
static void F_41 ( struct V_137 * V_138 ,
struct V_141 * V_142 , int V_128 )
{
if ( V_128 ) {
V_138 -> V_139 = V_142 -> V_139 ;
V_138 -> V_140 = V_142 -> V_140 ;
V_138 -> V_73 = V_142 -> V_73 ;
V_138 -> V_77 = V_142 -> V_77 ;
} else {
V_142 -> V_139 = V_138 -> V_139 ;
V_142 -> V_140 = V_138 -> V_140 ;
V_142 -> V_73 = V_138 -> V_73 ;
V_142 -> V_77 = V_138 -> V_77 ;
}
}
struct V_137 *
F_42 ( struct V_71 * V_71 , T_1 * V_10 )
{
struct V_137 * V_138 ;
int V_143 = V_71 -> V_80 ;
T_1 V_103 = V_143 * sizeof( * V_138 ) ;
int V_22 ;
V_138 = F_43 ( V_103 , V_144 ) ;
if ( ! V_138 )
return NULL ;
for ( V_22 = 0 ; V_22 < V_143 ; V_22 ++ ) {
F_41 ( & V_138 [ V_22 ] , & V_71 -> V_145 [ V_22 ] , 1 ) ;
F_40 ( & V_138 [ V_22 ] , 1 ) ;
}
* V_10 = V_103 ;
return V_138 ;
}
int F_44 ( struct V_146 * V_147 , struct V_71 * V_71 )
{
void * V_9 ;
struct V_137 * V_138 ;
int V_143 = V_71 -> V_80 ;
int V_103 = V_143 * sizeof( * V_138 ) ;
int V_22 ;
int V_148 ;
int V_149 = 0 ;
if ( ! F_45 ( V_71 -> V_72 ) )
return 0 ;
if ( V_143 == 0 )
return 0 ;
V_9 = F_43 ( V_103 , V_144 ) ;
if ( ! V_9 )
return - V_150 ;
V_148 = F_20 ( V_147 -> V_151 , V_9 , V_103 ) ;
if ( V_148 != V_103 ) {
F_46 ( & V_71 -> V_2 -> V_2 , L_80 ,
V_148 ) ;
F_47 ( V_9 ) ;
if ( V_147 -> V_152 == V_153 || V_147 -> V_152 == V_154 )
F_48 ( V_147 , V_155 ) ;
else
F_48 ( V_147 , V_156 ) ;
return - V_157 ;
}
V_138 = (struct V_137 * ) V_9 ;
for ( V_22 = 0 ; V_22 < V_143 ; V_22 ++ ) {
F_40 ( & V_138 [ V_22 ] , 0 ) ;
F_41 ( & V_138 [ V_22 ] , & V_71 -> V_145 [ V_22 ] , 0 ) ;
V_149 += V_71 -> V_145 [ V_22 ] . V_77 ;
}
F_47 ( V_9 ) ;
if ( V_149 != V_71 -> V_77 ) {
F_46 ( & V_71 -> V_2 -> V_2 ,
L_81 ,
V_149 , V_71 -> V_77 ) ;
if ( V_147 -> V_152 == V_153 || V_147 -> V_152 == V_154 )
F_48 ( V_147 , V_155 ) ;
else
F_48 ( V_147 , V_156 ) ;
return - V_157 ;
}
return V_148 ;
}
void F_49 ( struct V_146 * V_147 , struct V_71 * V_71 )
{
int V_143 = V_71 -> V_80 ;
int V_22 ;
int V_158 = V_71 -> V_77 ;
if ( ! F_45 ( V_71 -> V_72 ) )
return;
if ( V_143 == 0 || V_71 -> V_77 == 0 )
return;
if ( V_71 -> V_77 == V_71 -> V_76 )
return;
for ( V_22 = V_143 - 1 ; V_22 > 0 ; V_22 -- ) {
V_158 -= V_71 -> V_145 [ V_22 ] . V_77 ;
memmove ( V_71 -> V_75 + V_71 -> V_145 [ V_22 ] . V_139 ,
V_71 -> V_75 + V_158 ,
V_71 -> V_145 [ V_22 ] . V_77 ) ;
}
}
int F_50 ( struct V_146 * V_147 , struct V_71 * V_71 )
{
int V_148 ;
int V_103 ;
if ( V_147 -> V_152 == V_153 || V_147 -> V_152 == V_154 ) {
if ( F_9 ( V_71 -> V_72 ) )
return 0 ;
V_103 = V_71 -> V_76 ;
} else {
if ( F_51 ( V_71 -> V_72 ) )
return 0 ;
V_103 = V_71 -> V_77 ;
}
if ( ! ( V_103 > 0 ) )
return 0 ;
if ( V_103 > V_71 -> V_76 ) {
if ( V_147 -> V_152 == V_153 ) {
F_48 ( V_147 , V_155 ) ;
return 0 ;
} else {
F_48 ( V_147 , V_156 ) ;
return - V_157 ;
}
}
V_148 = F_20 ( V_147 -> V_151 , V_71 -> V_75 , V_103 ) ;
if ( V_148 != V_103 ) {
F_46 ( & V_71 -> V_2 -> V_2 , L_82 , V_148 ) ;
if ( V_147 -> V_152 == V_153 || V_147 -> V_152 == V_154 ) {
F_48 ( V_147 , V_155 ) ;
} else {
F_48 ( V_147 , V_156 ) ;
return - V_157 ;
}
}
return V_148 ;
}
static int T_5 F_52 ( void )
{
int V_148 ;
F_53 ( V_159 L_83 V_160 L_16 ) ;
V_148 = F_54 () ;
if ( V_148 )
return V_148 ;
return 0 ;
}
static void T_6 F_55 ( void )
{
F_56 () ;
return;
}
