int F_1 ( struct V_1 * V_2 ,
void (* F_2)( void * V_3 ,
enum V_4 V_5 ) )
{
if ( V_2 -> V_6 )
return - V_7 ;
V_2 -> V_6 = F_2 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = NULL ;
}
static void F_4 ( unsigned long V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
int V_11 ;
V_11 = V_10 -> V_12 ( V_10 -> V_8 , V_10 -> V_13 ) ;
if ( V_11 )
F_5 ( & V_10 -> V_14 ) ;
else {
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_15 ;
V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
F_7 ( V_10 -> V_13 * V_2 -> V_18 , & V_15 ) ;
F_8 ( V_15 , V_2 -> V_16 . V_17 ) ;
}
}
int F_9 ( struct V_1 * V_2 , unsigned int V_19 ,
void * V_8 , int (* F_2)( void * V_8 , int V_13 ) )
{
unsigned long V_15 ;
if ( V_19 >= V_2 -> V_20 || V_2 -> V_10 [ V_19 ] . V_12 ) {
F_10 ( & V_2 -> V_21 -> V_22 , L_1 ) ;
return - V_7 ;
}
V_2 -> V_10 [ V_19 ] . V_12 = F_2 ;
V_2 -> V_10 [ V_19 ] . V_8 = V_8 ;
V_2 -> V_10 [ V_19 ] . V_2 = V_2 ;
F_11 ( & V_2 -> V_10 [ V_19 ] . V_14 , F_4 ,
( unsigned long ) & V_2 -> V_10 [ V_19 ] ) ;
V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
F_7 ( V_19 * V_2 -> V_18 , & V_15 ) ;
F_8 ( V_15 , V_2 -> V_16 . V_17 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_19 )
{
unsigned long V_15 ;
if ( V_19 >= V_2 -> V_20 || ! V_2 -> V_10 [ V_19 ] . V_12 )
return;
V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
F_13 ( V_19 * V_2 -> V_18 , & V_15 ) ;
F_8 ( V_15 , V_2 -> V_16 . V_17 ) ;
F_14 ( & V_2 -> V_10 [ V_19 ] . V_14 ) ;
V_2 -> V_10 [ V_19 ] . V_12 = NULL ;
}
void * F_15 ( struct V_23 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
return V_2 -> V_24 ;
}
struct V_1 * F_17 ( struct V_23 * V_21 , void * V_25 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
if ( V_2 -> V_24 )
return NULL ;
V_2 -> V_24 = V_25 ;
return V_2 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_26 ;
if ( ! V_2 -> V_24 )
return;
for ( V_26 = 0 ; V_26 < V_2 -> V_20 ; V_26 ++ )
F_12 ( V_2 , V_26 ) ;
F_3 ( V_2 ) ;
V_2 -> V_24 = NULL ;
}
int F_19 ( struct V_1 * V_2 , unsigned int V_19 , T_1 V_27 )
{
if ( V_19 >= V_2 -> V_28 . V_29 )
return - V_7 ;
F_20 ( & V_2 -> V_21 -> V_22 , L_2 ,
V_27 , V_19 ) ;
F_21 ( V_27 , V_2 -> V_16 . V_30 + V_19 * 4 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_19 , T_1 * V_27 )
{
if ( V_19 >= V_2 -> V_28 . V_29 )
return - V_7 ;
* V_27 = F_23 ( V_2 -> V_16 . V_31 + V_19 * 4 ) ;
F_20 ( & V_2 -> V_21 -> V_22 ,
L_3 , * V_27 , V_19 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_19 , T_1 V_27 )
{
if ( V_19 >= V_2 -> V_28 . V_29 )
return - V_7 ;
F_20 ( & V_2 -> V_21 -> V_22 , L_4 ,
V_27 , V_19 ) ;
F_21 ( V_27 , V_2 -> V_16 . V_31 + V_19 * 4 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_19 , T_1 * V_27 )
{
if ( V_19 >= V_2 -> V_28 . V_29 )
return - V_7 ;
* V_27 = F_23 ( V_2 -> V_16 . V_30 + V_19 * 4 ) ;
F_20 ( & V_2 -> V_21 -> V_22 ,
L_5 , * V_27 , V_19 ) ;
return 0 ;
}
T_2 F_26 ( struct V_1 * V_2 , unsigned int V_32 )
{
if ( V_32 >= F_27 ( V_2 ) )
return 0 ;
return F_28 ( V_2 -> V_21 , F_29 ( V_32 ) ) ;
}
void T_3 * F_30 ( struct V_1 * V_2 , unsigned int V_32 )
{
if ( V_32 >= F_27 ( V_2 ) )
return NULL ;
return V_2 -> V_32 [ V_32 ] . V_33 ;
}
T_4 F_31 ( struct V_1 * V_2 , unsigned int V_32 )
{
if ( V_32 >= F_27 ( V_2 ) )
return 0 ;
return V_2 -> V_32 [ V_32 ] . V_34 ;
}
void F_32 ( struct V_1 * V_2 , unsigned int V_32 , T_4 V_35 )
{
if ( V_32 >= F_27 ( V_2 ) )
return;
F_20 ( & V_2 -> V_21 -> V_22 , L_6 , V_35 ,
F_29 ( V_32 ) ) ;
V_2 -> V_32 [ V_32 ] . V_36 = V_35 ;
switch ( F_29 ( V_32 ) ) {
case V_37 :
F_33 ( V_35 , V_2 -> V_16 . V_38 ) ;
break;
case V_39 :
F_33 ( V_35 , V_2 -> V_16 . V_40 ) ;
break;
}
}
void F_34 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_20 ( & V_2 -> V_21 -> V_22 , L_7 , V_42 , V_41 ) ;
if ( V_2 -> V_43 == V_44 )
F_33 ( ( T_4 ) 1 << V_41 , V_2 -> V_16 . V_45 ) ;
else
F_8 ( ( ( 1 << V_2 -> V_18 ) - 1 ) <<
( V_41 * V_2 -> V_18 ) , V_2 -> V_16 . V_45 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_46 ;
F_36 ( 0xe0 , V_2 -> V_47 + V_48 ) ;
F_36 ( 0x40 , V_2 -> V_47 + V_49 ) ;
F_36 ( 0x60 , V_2 -> V_47 + V_49 ) ;
F_36 ( 0x60 , V_2 -> V_47 + V_48 ) ;
F_37 ( 100 ) ;
V_46 = F_23 ( V_2 -> V_47 + V_50 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_8 , V_46 ) ;
V_46 &= V_51 ;
F_21 ( V_46 , V_2 -> V_47 + V_50 ) ;
V_46 = F_23 ( V_2 -> V_47 + V_52 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_9 , V_46 ) ;
V_46 |= V_53 ;
F_21 ( V_46 , V_2 -> V_47 + V_52 ) ;
V_46 = F_23 ( V_2 -> V_47 + V_54 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_10 , V_46 ) ;
V_46 |= V_55 ;
F_21 ( V_46 , V_2 -> V_47 + V_54 ) ;
V_46 = F_23 ( V_2 -> V_47 + V_56 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_11 , V_46 ) ;
V_46 &= V_57 ;
F_21 ( V_46 , V_2 -> V_47 + V_56 ) ;
V_46 = F_23 ( V_2 -> V_47 + V_58 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_12 , V_46 ) ;
V_46 &= ~ V_59 ;
F_21 ( V_46 , V_2 -> V_47 + V_58 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_60 )
{
unsigned int V_5 ;
if ( V_2 -> V_61 == V_60 )
return;
if ( V_60 == V_62 ) {
T_5 V_46 ;
F_39 ( & V_2 -> V_21 -> V_22 , L_13 ) ;
V_2 -> V_61 = V_62 ;
V_5 = V_63 ;
if ( V_2 -> V_43 == V_44 ||
V_2 -> V_64 == V_65 )
V_46 = F_6 ( V_2 -> V_16 . V_66 ) ;
else {
int V_11 = F_40 ( V_2 -> V_21 ,
V_67 ,
& V_46 ) ;
if ( V_11 )
return;
}
V_2 -> V_68 = ( V_46 & V_69 ) >> 4 ;
V_2 -> V_70 = ( V_46 & V_71 ) ;
F_39 ( & V_2 -> V_21 -> V_22 , L_14 ,
V_2 -> V_68 , V_2 -> V_70 ) ;
} else {
F_39 ( & V_2 -> V_21 -> V_22 , L_15 ) ;
V_2 -> V_61 = V_72 ;
V_5 = V_73 ;
}
if ( V_2 -> V_6 )
V_2 -> V_6 ( V_2 -> V_24 , V_5 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_60 ;
if ( V_2 -> V_43 == V_44 ) {
T_1 V_74 ;
V_74 = F_23 ( V_2 -> V_16 . V_75 ) ;
if ( V_74 & V_76 )
V_60 = V_72 ;
else
V_60 = V_62 ;
} else {
T_5 V_46 ;
int V_11 ;
V_11 = F_40 ( V_2 -> V_21 , V_67 ,
& V_46 ) ;
if ( V_11 )
return V_11 ;
if ( V_46 & V_77 )
V_60 = V_62 ;
else
V_60 = V_72 ;
}
F_38 ( V_2 , V_60 ) ;
return 0 ;
}
static void F_42 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_43 ( V_79 , struct V_1 ,
V_80 . V_79 ) ;
T_1 V_81 ;
F_35 ( V_2 ) ;
F_37 ( V_82 + F_44 () % V_82 ) ;
V_81 = F_23 ( V_2 -> V_47 + V_58 ) ;
if ( V_81 & V_59 )
goto V_83;
V_81 = F_23 ( V_2 -> V_47 + V_56 ) ;
if ( V_81 & V_57 )
goto V_83;
V_81 = F_23 ( V_2 -> V_16 . V_75 ) ;
if ( ! ( V_81 & V_76 ) ) {
unsigned char V_84 , V_85 ;
T_5 V_86 ;
V_86 = F_6 ( V_2 -> V_16 . V_66 ) ;
V_85 = ( V_86 & V_69 ) >> 4 ;
V_84 = ( V_86 & V_71 ) ;
if ( V_2 -> V_68 != V_85 || V_2 -> V_70 != V_84 )
goto V_83;
}
F_45 ( & V_2 -> V_87 , V_88 ) ;
return;
V_83:
F_45 ( & V_2 -> V_80 , V_88 ) ;
}
static void F_46 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_43 ( V_79 , struct V_1 ,
V_87 . V_79 ) ;
unsigned long V_89 = V_90 ;
if ( V_89 > V_2 -> V_91 + V_88 ) {
int V_11 = F_41 ( V_2 ) ;
if ( V_11 )
F_47 ( & V_2 -> V_21 -> V_22 ,
L_16 ) ;
if ( V_2 -> V_61 == V_72 ) {
T_1 V_81 = F_23 ( V_2 -> V_47 +
V_58 ) ;
if ( V_81 & V_59 ) {
F_45 ( & V_2 -> V_80 , 0 ) ;
return;
}
}
}
F_45 ( & V_2 -> V_87 , V_88 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_11 ;
T_6 V_27 ;
V_2 -> V_43 = V_92 ;
V_11 = F_49 ( V_2 -> V_21 , V_93 , & V_27 ) ;
if ( V_11 )
return V_11 ;
if ( V_27 & V_94 )
V_2 -> V_95 = V_96 ;
else
V_2 -> V_95 = V_97 ;
switch ( V_27 & V_98 ) {
case V_99 :
F_39 ( & V_2 -> V_21 -> V_22 , L_17 ) ;
V_2 -> V_64 = V_99 ;
V_2 -> V_16 . V_100 = V_2 -> V_47 + V_101 ;
V_2 -> V_16 . V_17 = V_2 -> V_47 + V_102 ;
V_2 -> V_16 . V_30 = V_2 -> V_47 + V_103 ;
V_2 -> V_16 . V_38 = V_2 -> V_47 + V_104 ;
V_2 -> V_16 . V_40 = V_2 -> V_47 + V_105 ;
V_2 -> V_28 . V_29 = V_106 ;
if ( V_107 ) {
if ( ! V_2 -> V_32 [ 1 ] . V_34 )
return - V_7 ;
V_2 -> V_28 . V_108 = V_109 ;
V_2 -> V_28 . V_110 = V_111 ;
V_2 -> V_16 . V_31 = V_2 -> V_32 [ 1 ] . V_33 +
V_103 ;
V_2 -> V_16 . V_45 = V_2 -> V_32 [ 1 ] . V_33 +
V_101 ;
F_33 ( V_2 -> V_32 [ 1 ] . V_34 + 0x1000 , V_2 -> V_47 +
V_112 ) ;
} else {
V_2 -> V_28 . V_108 = V_113 ;
V_2 -> V_28 . V_110 = V_111 - 1 ;
V_2 -> V_16 . V_31 = V_2 -> V_47 +
V_114 ;
V_2 -> V_16 . V_45 = V_2 -> V_47 +
V_115 ;
F_33 ( 0 , V_2 -> V_47 + V_112 ) ;
}
if ( V_2 -> V_95 == V_96 ) {
F_33 ( V_116 , V_2 -> V_47 +
V_117 ) ;
if ( V_107 )
F_33 ( V_118 , V_2 -> V_47 +
V_119 ) ;
else {
F_33 ( V_120 , V_2 -> V_47 +
V_119 ) ;
F_21 ( V_118 & 0xffffffff ,
V_2 -> V_47 + V_121 ) ;
F_21 ( V_118 >> 32 ,
V_2 -> V_47 + V_122 ) ;
}
F_33 ( V_123 , V_2 -> V_47 +
V_124 ) ;
F_33 ( V_125 , V_2 -> V_47 +
V_126 ) ;
F_33 ( V_127 , V_2 -> V_47 +
V_128 ) ;
} else {
F_33 ( V_125 , V_2 -> V_47 +
V_117 ) ;
if ( V_107 )
F_33 ( V_123 , V_2 -> V_47 +
V_119 ) ;
else {
F_33 ( V_127 , V_2 -> V_47 +
V_119 ) ;
F_21 ( V_123 & 0xffffffff ,
V_2 -> V_47 + V_121 ) ;
F_21 ( V_123 >> 32 ,
V_2 -> V_47 + V_122 ) ;
}
F_33 ( V_118 , V_2 -> V_47 +
V_124 ) ;
F_33 ( V_116 , V_2 -> V_47 +
V_126 ) ;
F_33 ( V_120 , V_2 -> V_47 +
V_128 ) ;
}
break;
case V_129 :
F_39 ( & V_2 -> V_21 -> V_22 , L_18 ) ;
V_2 -> V_64 = V_129 ;
if ( V_107 ) {
F_47 ( & V_2 -> V_21 -> V_22 ,
L_19 ) ;
return - V_7 ;
}
V_2 -> V_28 . V_29 = V_130 / 2 ;
V_2 -> V_28 . V_110 = V_111 ;
V_2 -> V_16 . V_45 = V_2 -> V_47 + V_131 ;
V_2 -> V_16 . V_100 = V_2 -> V_47 + V_101 ;
V_2 -> V_16 . V_17 = V_2 -> V_47 + V_102 ;
V_2 -> V_16 . V_31 = V_2 -> V_47 + V_103 +
V_2 -> V_28 . V_29 * 4 ;
V_2 -> V_16 . V_30 = V_2 -> V_47 + V_103 ;
V_2 -> V_16 . V_38 = V_2 -> V_47 + V_104 ;
V_2 -> V_16 . V_40 = V_2 -> V_47 + V_105 ;
V_2 -> V_28 . V_108 = V_113 ;
break;
case V_65 :
F_39 ( & V_2 -> V_21 -> V_22 , L_20 ) ;
V_2 -> V_64 = V_65 ;
V_2 -> V_28 . V_29 = V_130 / 2 ;
V_2 -> V_28 . V_110 = V_111 ;
V_2 -> V_16 . V_45 = V_2 -> V_47 + V_101 ;
V_2 -> V_16 . V_100 = V_2 -> V_47 + V_131 ;
V_2 -> V_16 . V_17 = V_2 -> V_47 + V_132 ;
V_2 -> V_16 . V_31 = V_2 -> V_47 + V_103 ;
V_2 -> V_16 . V_30 = V_2 -> V_47 + V_103 +
V_2 -> V_28 . V_29 * 4 ;
V_2 -> V_16 . V_38 = V_2 -> V_47 + V_117 ;
V_2 -> V_16 . V_40 = V_2 -> V_47 + V_119 ;
V_2 -> V_28 . V_108 = V_113 ;
break;
default:
F_47 ( & V_2 -> V_21 -> V_22 , L_21 , V_27 ) ;
return - V_7 ;
}
V_2 -> V_16 . V_75 = V_2 -> V_47 + V_133 ;
V_2 -> V_16 . V_66 = V_2 -> V_47 + V_134 ;
V_2 -> V_16 . V_135 = V_2 -> V_47 + V_136 ;
V_2 -> V_28 . V_137 = V_138 ;
V_2 -> V_18 = V_139 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_27 ;
V_2 -> V_43 = V_44 ;
V_11 = F_51 ( V_2 -> V_21 , V_93 , & V_27 ) ;
if ( V_11 )
return V_11 ;
switch ( ( V_27 & V_140 ) >> 8 ) {
case V_99 :
V_2 -> V_64 = V_99 ;
break;
case V_129 :
default:
F_47 ( & V_2 -> V_21 -> V_22 , L_22 ) ;
return - V_7 ;
}
if ( V_27 & V_141 )
V_2 -> V_95 = V_97 ;
else
V_2 -> V_95 = V_96 ;
V_11 = F_52 ( V_2 -> V_21 , V_93 ,
V_27 | V_142 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_16 . V_100 = V_2 -> V_47 + V_143 ;
V_2 -> V_16 . V_17 = V_2 -> V_47 + V_144 ;
V_2 -> V_16 . V_45 = V_2 -> V_47 + V_145 ;
V_2 -> V_16 . V_38 = V_2 -> V_47 + V_146 ;
V_2 -> V_16 . V_40 = V_2 -> V_47 + V_147 ;
V_2 -> V_16 . V_75 = V_2 -> V_47 + V_148 ;
V_2 -> V_16 . V_66 = V_2 -> V_47 + V_149 ;
V_2 -> V_16 . V_30 = V_2 -> V_47 + V_150 ;
V_2 -> V_16 . V_31 = V_2 -> V_47 + V_151 ;
V_2 -> V_16 . V_135 = V_2 -> V_47 + V_152 ;
V_2 -> V_28 . V_108 = V_153 ;
V_2 -> V_28 . V_29 = V_154 ;
V_2 -> V_28 . V_110 = V_155 ;
V_2 -> V_28 . V_137 = V_156 ;
V_2 -> V_18 = V_157 ;
F_53 ( & V_2 -> V_87 , F_46 ) ;
F_53 ( & V_2 -> V_80 , F_42 ) ;
F_45 ( & V_2 -> V_87 , V_88 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_11 ;
switch ( V_2 -> V_21 -> V_158 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
V_11 = F_48 ( V_2 ) ;
break;
case V_171 :
V_11 = F_50 ( V_2 ) ;
break;
default:
V_11 = - V_172 ;
}
if ( V_11 )
return V_11 ;
F_39 ( & V_2 -> V_21 -> V_22 , L_23 ,
V_2 -> V_95 == V_96 ? L_24 : L_25 ) ;
if ( V_2 -> V_64 == V_99 )
F_8 ( V_173 | V_174 ,
V_2 -> V_16 . V_135 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 == V_44 ) {
F_56 ( & V_2 -> V_87 ) ;
F_56 ( & V_2 -> V_80 ) ;
}
}
static T_7 F_57 ( int V_175 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_15 ;
F_20 ( & V_2 -> V_21 -> V_22 , L_26 , V_175 ,
V_10 -> V_13 ) ;
V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
F_13 ( V_10 -> V_13 * V_2 -> V_18 , & V_15 ) ;
F_8 ( V_15 , V_2 -> V_16 . V_17 ) ;
F_5 ( & V_10 -> V_14 ) ;
V_2 -> V_91 = V_90 ;
F_33 ( ( T_4 ) 1 << V_10 -> V_13 , V_2 -> V_16 . V_100 ) ;
return V_176 ;
}
static T_7 F_58 ( int V_175 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_15 ;
F_20 ( & V_2 -> V_21 -> V_22 , L_26 , V_175 ,
V_10 -> V_13 ) ;
V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
F_13 ( V_10 -> V_13 * V_2 -> V_18 , & V_15 ) ;
F_8 ( V_15 , V_2 -> V_16 . V_17 ) ;
F_5 ( & V_10 -> V_14 ) ;
F_8 ( ( ( 1 << V_2 -> V_18 ) - 1 ) <<
( V_10 -> V_13 * V_2 -> V_18 ) , V_2 -> V_16 . V_100 ) ;
return V_176 ;
}
static T_7 F_59 ( int V_175 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
int V_11 ;
F_20 ( & V_2 -> V_21 -> V_22 , L_27 , V_175 ) ;
V_11 = F_41 ( V_2 ) ;
if ( V_11 )
F_47 ( & V_2 -> V_21 -> V_22 , L_16 ) ;
F_8 ( 1 << V_177 , V_2 -> V_16 . V_100 ) ;
return V_176 ;
}
static T_7 F_60 ( int V_175 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
unsigned int V_26 = 0 ;
if ( V_2 -> V_43 == V_44 ) {
T_4 V_100 = F_61 ( V_2 -> V_16 . V_100 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_28 , V_175 , V_100 ) ;
while ( V_100 ) {
V_26 = F_62 ( V_100 ) ;
V_100 &= V_100 - 1 ;
F_57 ( V_175 , & V_2 -> V_10 [ V_26 ] ) ;
}
} else {
T_5 V_100 = F_6 ( V_2 -> V_16 . V_100 ) ;
F_20 ( & V_2 -> V_21 -> V_22 , L_29 , V_175 , V_100 ) ;
if ( V_100 & V_178 ) {
F_59 ( V_175 , V_22 ) ;
V_100 &= ~ V_178 ;
}
while ( V_100 ) {
V_26 = F_62 ( V_100 ) ;
V_100 &= V_100 - 1 ;
F_58 ( V_175 , & V_2 -> V_10 [ V_26 ] ) ;
}
}
return V_176 ;
}
static int F_63 ( struct V_1 * V_2 , int V_179 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
struct V_180 * V_181 ;
int V_11 , V_26 ;
if ( V_179 < V_2 -> V_28 . V_137 )
return - V_182 ;
V_11 = F_64 ( V_21 , V_2 -> V_179 , V_179 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_26 = 0 ; V_26 < V_179 ; V_26 ++ ) {
V_181 = & V_2 -> V_179 [ V_26 ] ;
F_65 ( ! V_181 -> V_183 ) ;
if ( V_26 == V_179 - 1 ) {
V_11 = F_66 ( V_181 -> V_183 ,
F_59 , 0 ,
L_30 , V_2 ) ;
if ( V_11 )
goto V_184;
} else {
V_11 = F_66 ( V_181 -> V_183 ,
F_58 , 0 ,
L_31 ,
& V_2 -> V_10 [ V_26 ] ) ;
if ( V_11 )
goto V_184;
}
}
V_2 -> V_185 = V_179 ;
V_2 -> V_20 = V_179 - 1 ;
return 0 ;
V_184:
while ( -- V_26 >= 0 ) {
V_181 = & V_2 -> V_179 [ V_26 ] ;
F_67 ( V_181 -> V_183 , & V_2 -> V_10 [ V_26 ] ) ;
}
F_68 ( V_21 ) ;
V_2 -> V_185 = 0 ;
return V_11 ;
}
static int F_69 ( struct V_1 * V_2 , int V_179 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
struct V_180 * V_181 ;
int V_11 , V_26 ;
V_179 = F_70 ( V_21 , V_2 -> V_179 ,
1 , V_179 ) ;
if ( V_179 < 0 )
return V_179 ;
for ( V_26 = 0 ; V_26 < V_179 ; V_26 ++ ) {
V_181 = & V_2 -> V_179 [ V_26 ] ;
F_65 ( ! V_181 -> V_183 ) ;
V_11 = F_66 ( V_181 -> V_183 , F_57 , 0 ,
L_31 , & V_2 -> V_10 [ V_26 ] ) ;
if ( V_11 )
goto V_184;
}
V_2 -> V_185 = V_179 ;
V_2 -> V_20 = V_179 ;
return 0 ;
V_184:
while ( -- V_26 >= 0 )
F_67 ( V_181 -> V_183 , & V_2 -> V_10 [ V_26 ] ) ;
F_68 ( V_21 ) ;
V_2 -> V_185 = 0 ;
return V_11 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
int V_179 ;
int V_11 , V_26 ;
V_179 = F_72 ( V_21 ) ;
if ( V_179 < 0 ) {
V_11 = V_179 ;
goto V_184;
} else if ( V_179 > V_2 -> V_28 . V_137 ) {
V_11 = - V_7 ;
goto V_184;
}
V_2 -> V_179 = F_73 ( sizeof( struct V_180 ) * V_179 ,
V_186 ) ;
if ( ! V_2 -> V_179 ) {
V_11 = - V_187 ;
goto V_184;
}
for ( V_26 = 0 ; V_26 < V_179 ; V_26 ++ )
V_2 -> V_179 [ V_26 ] . V_188 = V_26 ;
if ( V_2 -> V_43 == V_44 )
V_11 = F_69 ( V_2 , V_179 ) ;
else
V_11 = F_63 ( V_2 , V_179 ) ;
if ( V_11 )
goto V_189;
return 0 ;
V_189:
F_74 ( V_2 -> V_179 ) ;
V_184:
F_47 ( & V_21 -> V_22 , L_32 ) ;
return V_11 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
int V_11 ;
V_11 = F_76 ( V_21 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_66 ( V_21 -> V_175 , F_60 , 0 , L_33 , V_2 ) ;
if ( V_11 ) {
F_77 ( V_21 ) ;
F_47 ( & V_21 -> V_22 , L_34 ) ;
return V_11 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
int V_11 ;
F_79 ( V_21 ) ;
F_80 ( V_21 , 1 ) ;
V_11 = F_66 ( V_21 -> V_175 , F_60 , V_190 , L_35 ,
V_2 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_43 == V_44 )
F_33 ( ~ 0 , V_2 -> V_16 . V_17 ) ;
else {
T_5 V_191 = 1 << V_177 ;
F_8 ( ~ V_191 , V_2 -> V_16 . V_17 ) ;
}
V_11 = F_71 ( V_2 ) ;
if ( ! V_11 )
goto V_192;
V_2 -> V_18 = 1 ;
V_2 -> V_20 = V_2 -> V_28 . V_110 ;
V_11 = F_75 ( V_2 ) ;
if ( ! V_11 )
goto V_192;
V_11 = F_78 ( V_2 ) ;
if ( V_11 ) {
F_47 ( & V_2 -> V_21 -> V_22 , L_36 ) ;
return V_11 ;
}
V_192:
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_23 * V_21 = V_2 -> V_21 ;
if ( V_2 -> V_43 == V_44 )
F_33 ( ~ 0 , V_2 -> V_16 . V_17 ) ;
else
F_8 ( ~ 0 , V_2 -> V_16 . V_17 ) ;
if ( V_2 -> V_185 ) {
struct V_180 * V_181 ;
T_1 V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_185 ; V_26 ++ ) {
V_181 = & V_2 -> V_179 [ V_26 ] ;
if ( V_2 -> V_43 != V_44 && V_26 == V_2 -> V_185 - 1 )
F_67 ( V_181 -> V_183 , V_2 ) ;
else
F_67 ( V_181 -> V_183 , & V_2 -> V_10 [ V_26 ] ) ;
}
F_68 ( V_21 ) ;
F_74 ( V_2 -> V_179 ) ;
} else {
F_67 ( V_21 -> V_175 , V_2 ) ;
if ( F_83 ( V_21 ) )
F_77 ( V_21 ) ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
int V_26 ;
V_2 -> V_10 = F_85 ( V_2 -> V_28 . V_110 ,
sizeof( struct V_9 ) ,
V_186 ) ;
if ( ! V_2 -> V_10 )
return - V_187 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_28 . V_110 ; V_26 ++ ) {
V_2 -> V_10 [ V_26 ] . V_13 = V_26 ;
V_2 -> V_10 [ V_26 ] . V_2 = V_2 ;
}
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_28 . V_110 ; V_26 ++ )
F_12 ( V_2 , V_26 ) ;
F_74 ( V_2 -> V_10 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( ! F_88 () )
return;
if ( ! V_193 )
V_193 = F_89 ( V_194 , NULL ) ;
V_2 -> V_193 = F_89 ( F_90 ( V_2 -> V_21 ) ,
V_193 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_92 ( V_2 -> V_193 ) ;
if ( V_193 && F_93 ( V_193 ) ) {
F_92 ( V_193 ) ;
V_193 = NULL ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 == V_65 )
F_38 ( V_2 , V_62 ) ;
else {
T_1 V_74 ;
V_74 = F_23 ( V_2 -> V_16 . V_75 ) ;
V_74 &= ~ ( V_195 | V_196 ) ;
V_74 |= V_197 | V_198 ;
V_74 |= V_199 | V_200 ;
F_21 ( V_74 , V_2 -> V_16 . V_75 ) ;
}
}
static void F_95 ( struct V_1 * V_2 )
{
T_1 V_74 ;
if ( V_2 -> V_64 == V_65 ) {
F_38 ( V_2 , V_72 ) ;
return;
}
V_74 = F_23 ( V_2 -> V_16 . V_75 ) ;
V_74 &= ~ ( V_197 | V_198 ) ;
V_74 &= ~ ( V_199 | V_200 ) ;
V_74 |= V_195 | V_196 ;
F_21 ( V_74 , V_2 -> V_16 . V_75 ) ;
}
static int F_96 ( struct V_23 * V_21 , const struct V_201 * V_202 )
{
struct V_1 * V_2 ;
int V_11 , V_26 ;
V_2 = F_97 ( sizeof( struct V_1 ) , V_186 ) ;
if ( ! V_2 )
return - V_187 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_61 = V_72 ;
F_98 ( V_21 , V_2 ) ;
F_87 ( V_2 ) ;
V_11 = F_99 ( V_21 ) ;
if ( V_11 )
goto V_184;
F_100 ( V_2 -> V_21 ) ;
V_11 = F_101 ( V_21 , V_203 , V_194 ) ;
if ( V_11 )
goto V_189;
V_2 -> V_47 = F_102 ( V_21 , V_204 ) ;
if ( ! V_2 -> V_47 ) {
F_10 ( & V_21 -> V_22 , L_37 ) ;
V_11 = - V_205 ;
goto V_206;
}
for ( V_26 = 0 ; V_26 < V_207 ; V_26 ++ ) {
V_2 -> V_32 [ V_26 ] . V_34 = F_103 ( V_21 , F_29 ( V_26 ) ) ;
V_2 -> V_32 [ V_26 ] . V_33 =
F_104 ( F_28 ( V_21 , F_29 ( V_26 ) ) ,
V_2 -> V_32 [ V_26 ] . V_34 ) ;
F_39 ( & V_21 -> V_22 , L_38 , V_26 ,
( unsigned long long ) V_2 -> V_32 [ V_26 ] . V_34 ) ;
if ( ! V_2 -> V_32 [ V_26 ] . V_33 ) {
F_10 ( & V_21 -> V_22 , L_39 ,
F_29 ( V_26 ) ) ;
V_11 = - V_205 ;
goto V_208;
}
}
V_11 = F_105 ( V_21 , F_106 ( 64 ) ) ;
if ( V_11 ) {
V_11 = F_105 ( V_21 , F_106 ( 32 ) ) ;
if ( V_11 )
goto V_208;
F_10 ( & V_21 -> V_22 , L_40 ) ;
}
V_11 = F_107 ( V_21 , F_106 ( 64 ) ) ;
if ( V_11 ) {
V_11 = F_107 ( V_21 , F_106 ( 32 ) ) ;
if ( V_11 )
goto V_208;
F_10 ( & V_21 -> V_22 , L_41 ) ;
}
V_11 = F_54 ( V_2 ) ;
if ( V_11 )
goto V_208;
V_11 = F_84 ( V_2 ) ;
if ( V_11 )
goto V_209;
V_11 = F_81 ( V_2 ) ;
if ( V_11 )
goto V_210;
for ( V_26 = 0 ; V_26 < V_2 -> V_28 . V_29 ; V_26 ++ ) {
F_19 ( V_2 , V_26 , 0 ) ;
F_24 ( V_2 , V_26 , 0 ) ;
}
V_11 = F_108 ( V_21 ) ;
if ( V_11 )
goto V_211;
F_94 ( V_2 ) ;
return 0 ;
V_211:
F_82 ( V_2 ) ;
V_210:
F_86 ( V_2 ) ;
V_209:
F_55 ( V_2 ) ;
V_208:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- )
F_109 ( V_2 -> V_32 [ V_26 ] . V_33 ) ;
F_109 ( V_2 -> V_47 ) ;
V_206:
F_110 ( V_21 , V_203 ) ;
V_189:
F_111 ( V_21 ) ;
V_184:
F_91 ( V_2 ) ;
F_74 ( V_2 ) ;
F_47 ( & V_21 -> V_22 , L_42 , V_194 ) ;
return V_11 ;
}
static void F_112 ( struct V_23 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
int V_26 ;
F_95 ( V_2 ) ;
F_113 ( V_2 -> V_24 ) ;
F_82 ( V_2 ) ;
F_86 ( V_2 ) ;
F_55 ( V_2 ) ;
for ( V_26 = 0 ; V_26 < V_207 ; V_26 ++ )
F_109 ( V_2 -> V_32 [ V_26 ] . V_33 ) ;
F_109 ( V_2 -> V_47 ) ;
F_110 ( V_21 , V_203 ) ;
F_111 ( V_21 ) ;
F_91 ( V_2 ) ;
F_74 ( V_2 ) ;
}
