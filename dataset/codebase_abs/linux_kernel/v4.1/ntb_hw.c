static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
return 1 ;
default:
return 0 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 -> V_4 ) {
case V_17 :
return 1 ;
default:
return 0 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_18 |= V_19 ;
break;
}
}
int F_4 ( struct V_1 * V_2 ,
void (* F_5)( void * V_20 ,
enum V_21 V_22 ) )
{
if ( V_2 -> V_23 )
return - V_24 ;
V_2 -> V_23 = F_5 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_23 = NULL ;
}
static void F_7 ( unsigned long V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
int V_28 ;
V_28 = V_27 -> V_29 ( V_27 -> V_25 , V_27 -> V_30 ) ;
if ( V_28 )
F_8 ( & V_27 -> V_31 ) ;
else {
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_32 ;
V_32 = F_9 ( V_2 -> V_33 . V_34 ) ;
F_10 ( V_27 -> V_30 * V_2 -> V_35 , & V_32 ) ;
F_11 ( V_32 , V_2 -> V_33 . V_34 ) ;
}
}
int F_12 ( struct V_1 * V_2 , unsigned int V_36 ,
void * V_25 , int (* F_5)( void * V_25 , int V_30 ) )
{
unsigned long V_32 ;
if ( V_36 >= V_2 -> V_37 || V_2 -> V_27 [ V_36 ] . V_29 ) {
F_13 ( & V_2 -> V_3 -> V_38 , L_1 ) ;
return - V_24 ;
}
V_2 -> V_27 [ V_36 ] . V_29 = F_5 ;
V_2 -> V_27 [ V_36 ] . V_25 = V_25 ;
V_2 -> V_27 [ V_36 ] . V_2 = V_2 ;
F_14 ( & V_2 -> V_27 [ V_36 ] . V_31 , F_7 ,
( unsigned long ) & V_2 -> V_27 [ V_36 ] ) ;
V_32 = F_9 ( V_2 -> V_33 . V_34 ) ;
F_10 ( V_36 * V_2 -> V_35 , & V_32 ) ;
F_11 ( V_32 , V_2 -> V_33 . V_34 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_36 )
{
unsigned long V_32 ;
if ( V_36 >= V_2 -> V_37 || ! V_2 -> V_27 [ V_36 ] . V_29 )
return;
V_32 = F_9 ( V_2 -> V_33 . V_34 ) ;
F_16 ( V_36 * V_2 -> V_35 , & V_32 ) ;
F_11 ( V_32 , V_2 -> V_33 . V_34 ) ;
F_17 ( & V_2 -> V_27 [ V_36 ] . V_31 ) ;
V_2 -> V_27 [ V_36 ] . V_29 = NULL ;
}
void * F_18 ( struct V_39 * V_3 )
{
struct V_1 * V_2 = F_19 ( V_3 ) ;
return V_2 -> V_40 ;
}
struct V_1 * F_20 ( struct V_39 * V_3 , void * V_41 )
{
struct V_1 * V_2 = F_19 ( V_3 ) ;
if ( V_2 -> V_40 )
return NULL ;
V_2 -> V_40 = V_41 ;
return V_2 ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_42 ;
if ( ! V_2 -> V_40 )
return;
for ( V_42 = 0 ; V_42 < V_2 -> V_37 ; V_42 ++ )
F_15 ( V_2 , V_42 ) ;
F_6 ( V_2 ) ;
V_2 -> V_40 = NULL ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_36 , T_1 V_43 )
{
if ( V_36 >= V_2 -> V_44 . V_45 )
return - V_24 ;
F_23 ( & V_2 -> V_3 -> V_38 , L_2 ,
V_43 , V_36 ) ;
F_24 ( V_43 , V_2 -> V_33 . V_46 + V_36 * 4 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_36 , T_1 * V_43 )
{
if ( V_36 >= V_2 -> V_44 . V_45 )
return - V_24 ;
* V_43 = F_26 ( V_2 -> V_33 . V_47 + V_36 * 4 ) ;
F_23 ( & V_2 -> V_3 -> V_38 ,
L_3 , * V_43 , V_36 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_36 , T_1 V_43 )
{
if ( V_36 >= V_2 -> V_44 . V_45 )
return - V_24 ;
F_23 ( & V_2 -> V_3 -> V_38 , L_4 ,
V_43 , V_36 ) ;
F_24 ( V_43 , V_2 -> V_33 . V_47 + V_36 * 4 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , unsigned int V_36 , T_1 * V_43 )
{
if ( V_36 >= V_2 -> V_44 . V_45 )
return - V_24 ;
* V_43 = F_26 ( V_2 -> V_33 . V_46 + V_36 * 4 ) ;
F_23 ( & V_2 -> V_3 -> V_38 ,
L_5 , * V_43 , V_36 ) ;
return 0 ;
}
T_2 F_29 ( struct V_1 * V_2 , unsigned int V_48 )
{
if ( V_48 >= F_30 ( V_2 ) )
return 0 ;
return F_31 ( V_2 -> V_3 , F_32 ( V_48 ) ) ;
}
void T_3 * F_33 ( struct V_1 * V_2 , unsigned int V_48 )
{
if ( V_48 >= F_30 ( V_2 ) )
return NULL ;
return V_2 -> V_48 [ V_48 ] . V_49 ;
}
T_4 F_34 ( struct V_1 * V_2 , unsigned int V_48 )
{
if ( V_48 >= F_30 ( V_2 ) )
return 0 ;
return V_2 -> V_48 [ V_48 ] . V_50 ;
}
void F_35 ( struct V_1 * V_2 , unsigned int V_48 , T_4 V_51 )
{
if ( V_48 >= F_30 ( V_2 ) )
return;
F_23 ( & V_2 -> V_3 -> V_38 , L_6 , V_51 ,
F_32 ( V_48 ) ) ;
V_2 -> V_48 [ V_48 ] . V_52 = V_51 ;
switch ( F_32 ( V_48 ) ) {
case V_53 :
F_36 ( V_51 , V_2 -> V_33 . V_54 ) ;
break;
case V_55 :
if ( V_2 -> V_56 )
F_24 ( V_51 , V_2 -> V_33 . V_57 ) ;
else
F_36 ( V_51 , V_2 -> V_33 . V_57 ) ;
break;
case V_58 :
F_24 ( V_51 , V_2 -> V_33 . V_59 ) ;
break;
}
}
void F_37 ( struct V_1 * V_2 , unsigned int V_60 )
{
F_23 ( & V_2 -> V_3 -> V_38 , L_7 , V_61 , V_60 ) ;
if ( V_2 -> V_62 == V_63 )
F_36 ( ( T_4 ) 1 << V_60 , V_2 -> V_33 . V_64 ) ;
else
F_11 ( ( ( 1 << V_2 -> V_35 ) - 1 ) <<
( V_60 * V_2 -> V_35 ) , V_2 -> V_33 . V_64 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_65 ;
F_39 ( 0xe0 , V_2 -> V_66 + V_67 ) ;
F_39 ( 0x40 , V_2 -> V_66 + V_68 ) ;
F_39 ( 0x60 , V_2 -> V_66 + V_68 ) ;
F_39 ( 0x60 , V_2 -> V_66 + V_67 ) ;
F_40 ( 100 ) ;
V_65 = F_26 ( V_2 -> V_66 + V_69 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_8 , V_65 ) ;
V_65 &= V_70 ;
F_24 ( V_65 , V_2 -> V_66 + V_69 ) ;
V_65 = F_26 ( V_2 -> V_66 + V_71 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_9 , V_65 ) ;
V_65 |= V_72 ;
F_24 ( V_65 , V_2 -> V_66 + V_71 ) ;
V_65 = F_26 ( V_2 -> V_66 + V_73 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_10 , V_65 ) ;
V_65 |= V_74 ;
F_24 ( V_65 , V_2 -> V_66 + V_73 ) ;
V_65 = F_26 ( V_2 -> V_66 + V_75 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_11 , V_65 ) ;
V_65 &= V_76 ;
F_24 ( V_65 , V_2 -> V_66 + V_75 ) ;
V_65 = F_26 ( V_2 -> V_66 + V_77 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_12 , V_65 ) ;
V_65 &= ~ V_78 ;
F_24 ( V_65 , V_2 -> V_66 + V_77 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_79 )
{
unsigned int V_22 ;
if ( V_2 -> V_80 == V_79 )
return;
if ( V_79 == V_81 ) {
T_5 V_65 ;
F_42 ( & V_2 -> V_3 -> V_38 , L_13 ) ;
V_2 -> V_80 = V_81 ;
V_22 = V_82 ;
if ( F_2 ( V_2 ) ||
V_2 -> V_83 == V_84 )
V_65 = F_9 ( V_2 -> V_33 . V_85 ) ;
else {
int V_28 = F_43 ( V_2 -> V_3 ,
V_86 ,
& V_65 ) ;
if ( V_28 )
return;
}
V_2 -> V_87 = ( V_65 & V_88 ) >> 4 ;
V_2 -> V_89 = ( V_65 & V_90 ) ;
F_42 ( & V_2 -> V_3 -> V_38 , L_14 ,
V_2 -> V_87 , V_2 -> V_89 ) ;
} else {
F_42 ( & V_2 -> V_3 -> V_38 , L_15 ) ;
V_2 -> V_80 = V_91 ;
V_22 = V_92 ;
}
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_2 -> V_40 , V_22 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_79 ;
if ( F_2 ( V_2 ) ) {
T_1 V_93 ;
V_93 = F_26 ( V_2 -> V_33 . V_94 ) ;
if ( V_93 & V_95 )
V_79 = V_91 ;
else
V_79 = V_81 ;
} else {
T_5 V_65 ;
int V_28 ;
V_28 = F_43 ( V_2 -> V_3 , V_86 ,
& V_65 ) ;
if ( V_28 )
return V_28 ;
if ( V_65 & V_96 )
V_79 = V_81 ;
else
V_79 = V_91 ;
}
F_41 ( V_2 , V_79 ) ;
return 0 ;
}
static void F_45 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_46 ( V_98 , struct V_1 ,
V_99 . V_98 ) ;
T_1 V_100 ;
F_38 ( V_2 ) ;
F_40 ( V_101 + F_47 () % V_101 ) ;
V_100 = F_26 ( V_2 -> V_66 + V_77 ) ;
if ( V_100 & V_78 )
goto V_102;
V_100 = F_26 ( V_2 -> V_66 + V_75 ) ;
if ( V_100 & V_76 )
goto V_102;
V_100 = F_26 ( V_2 -> V_33 . V_94 ) ;
if ( ! ( V_100 & V_95 ) ) {
unsigned char V_103 , V_104 ;
T_5 V_105 ;
V_105 = F_9 ( V_2 -> V_33 . V_85 ) ;
V_104 = ( V_105 & V_88 ) >> 4 ;
V_103 = ( V_105 & V_90 ) ;
if ( V_2 -> V_87 != V_104 || V_2 -> V_89 != V_103 )
goto V_102;
}
F_48 ( & V_2 -> V_106 , V_107 ) ;
return;
V_102:
F_48 ( & V_2 -> V_99 , V_107 ) ;
}
static void F_49 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_46 ( V_98 , struct V_1 ,
V_106 . V_98 ) ;
unsigned long V_108 = V_109 ;
if ( V_108 > V_2 -> V_110 + V_107 ) {
int V_28 = F_44 ( V_2 ) ;
if ( V_28 )
F_50 ( & V_2 -> V_3 -> V_38 ,
L_16 ) ;
if ( V_2 -> V_80 == V_91 ) {
T_1 V_100 = F_26 ( V_2 -> V_66 +
V_77 ) ;
if ( V_100 & V_78 ) {
F_48 ( & V_2 -> V_99 , 0 ) ;
return;
}
}
}
F_48 ( & V_2 -> V_106 , V_107 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_83 ) {
case V_111 :
V_2 -> V_33 . V_112 = V_2 -> V_66 + V_113 ;
V_2 -> V_33 . V_34 = V_2 -> V_66 + V_114 ;
V_2 -> V_33 . V_46 = V_2 -> V_66 + V_115 ;
V_2 -> V_33 . V_54 = V_2 -> V_66 + V_116 ;
V_2 -> V_33 . V_57 = V_2 -> V_66 + V_117 ;
if ( V_2 -> V_56 )
V_2 -> V_33 . V_59 =
V_2 -> V_66 + V_118 ;
V_2 -> V_44 . V_45 = V_119 ;
if ( V_2 -> V_18 & V_19 ) {
if ( ! V_2 -> V_48 [ V_2 -> V_44 . V_120 - 1 ] . V_50 )
return - V_24 ;
V_2 -> V_44 . V_121 = V_122 ;
V_2 -> V_33 . V_47 =
V_2 -> V_48 [ V_2 -> V_44 . V_120 - 1 ] . V_49 +
V_115 ;
V_2 -> V_33 . V_64 =
V_2 -> V_48 [ V_2 -> V_44 . V_120 - 1 ] . V_49 +
V_113 ;
F_36 ( V_2 -> V_48 [ 1 ] . V_50 + 0x1000 , V_2 -> V_66 +
V_123 ) ;
V_2 -> V_44 . V_120 = V_124 ;
} else {
V_2 -> V_44 . V_121 = V_122 - 1 ;
V_2 -> V_33 . V_47 = V_2 -> V_66 +
V_125 ;
V_2 -> V_33 . V_64 = V_2 -> V_66 +
V_126 ;
F_36 ( 0 , V_2 -> V_66 + V_123 ) ;
if ( V_2 -> V_56 )
V_2 -> V_44 . V_120 = V_127 ;
else
V_2 -> V_44 . V_120 = V_128 ;
}
if ( V_2 -> V_129 == V_130 ) {
F_36 ( V_131 , V_2 -> V_66 +
V_132 ) ;
if ( V_2 -> V_18 & V_19 )
F_36 ( V_133 , V_2 -> V_66 +
V_134 ) ;
else {
if ( V_2 -> V_56 ) {
F_24 ( V_135 ,
V_2 -> V_66 +
V_134 ) ;
F_24 ( V_136 ,
V_2 -> V_66 +
V_137 ) ;
} else
F_36 ( V_135 ,
V_2 -> V_66 +
V_134 ) ;
F_24 ( V_133 & 0xffffffff ,
V_2 -> V_66 + V_138 ) ;
F_24 ( V_133 >> 32 ,
V_2 -> V_66 + V_139 ) ;
}
F_36 ( V_140 , V_2 -> V_66 +
V_141 ) ;
F_36 ( V_142 , V_2 -> V_66 +
V_143 ) ;
if ( V_2 -> V_56 ) {
F_24 ( V_144 , V_2 -> V_66 +
V_145 ) ;
F_24 ( V_146 , V_2 -> V_66 +
V_147 ) ;
} else
F_36 ( V_144 , V_2 -> V_66 +
V_145 ) ;
} else {
F_36 ( V_142 , V_2 -> V_66 +
V_132 ) ;
if ( V_2 -> V_18 & V_19 )
F_36 ( V_140 , V_2 -> V_66 +
V_134 ) ;
else {
if ( V_2 -> V_56 ) {
F_24 ( V_144 ,
V_2 -> V_66 +
V_134 ) ;
F_24 ( V_146 ,
V_2 -> V_66 +
V_137 ) ;
} else
F_36 ( V_144 ,
V_2 -> V_66 +
V_134 ) ;
F_24 ( V_140 & 0xffffffff ,
V_2 -> V_66 + V_138 ) ;
F_24 ( V_140 >> 32 ,
V_2 -> V_66 + V_139 ) ;
}
F_36 ( V_133 , V_2 -> V_66 +
V_141 ) ;
F_36 ( V_131 , V_2 -> V_66 +
V_143 ) ;
if ( V_2 -> V_56 ) {
F_24 ( V_135 , V_2 -> V_66 +
V_145 ) ;
F_24 ( V_136 , V_2 -> V_66 +
V_147 ) ;
} else
F_36 ( V_135 , V_2 -> V_66 +
V_145 ) ;
}
break;
case V_148 :
if ( V_2 -> V_18 & V_19 ) {
F_50 ( & V_2 -> V_3 -> V_38 ,
L_17 ) ;
return - V_24 ;
}
V_2 -> V_44 . V_45 = V_149 / 2 ;
V_2 -> V_44 . V_121 = V_122 ;
V_2 -> V_33 . V_64 = V_2 -> V_66 + V_150 ;
V_2 -> V_33 . V_112 = V_2 -> V_66 + V_113 ;
V_2 -> V_33 . V_34 = V_2 -> V_66 + V_114 ;
V_2 -> V_33 . V_47 = V_2 -> V_66 + V_115 +
V_2 -> V_44 . V_45 * 4 ;
V_2 -> V_33 . V_46 = V_2 -> V_66 + V_115 ;
V_2 -> V_33 . V_54 = V_2 -> V_66 + V_116 ;
V_2 -> V_33 . V_57 = V_2 -> V_66 + V_117 ;
if ( V_2 -> V_56 ) {
V_2 -> V_33 . V_59 =
V_2 -> V_66 + V_118 ;
V_2 -> V_44 . V_120 = V_127 ;
} else
V_2 -> V_44 . V_120 = V_128 ;
break;
case V_84 :
if ( V_2 -> V_18 & V_19 ) {
F_50 ( & V_2 -> V_3 -> V_38 ,
L_18 ) ;
return - V_24 ;
}
V_2 -> V_44 . V_45 = V_149 / 2 ;
V_2 -> V_44 . V_121 = V_122 ;
V_2 -> V_33 . V_64 = V_2 -> V_66 + V_113 ;
V_2 -> V_33 . V_112 = V_2 -> V_66 + V_150 ;
V_2 -> V_33 . V_34 = V_2 -> V_66 + V_151 ;
V_2 -> V_33 . V_47 = V_2 -> V_66 + V_115 ;
V_2 -> V_33 . V_46 = V_2 -> V_66 + V_115 +
V_2 -> V_44 . V_45 * 4 ;
V_2 -> V_33 . V_54 = V_2 -> V_66 + V_132 ;
V_2 -> V_33 . V_57 = V_2 -> V_66 + V_134 ;
if ( V_2 -> V_56 ) {
V_2 -> V_33 . V_59 =
V_2 -> V_66 + V_137 ;
V_2 -> V_44 . V_120 = V_127 ;
} else
V_2 -> V_44 . V_120 = V_128 ;
break;
default:
return - V_24 ;
}
V_2 -> V_33 . V_94 = V_2 -> V_66 + V_152 ;
V_2 -> V_33 . V_85 = V_2 -> V_66 + V_153 ;
V_2 -> V_33 . V_154 = V_2 -> V_66 + V_155 ;
V_2 -> V_44 . V_156 = V_157 ;
V_2 -> V_35 = V_158 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_28 ;
T_1 V_43 ;
V_2 -> V_62 = V_63 ;
V_28 = F_53 ( V_2 -> V_3 , V_159 , & V_43 ) ;
if ( V_28 )
return V_28 ;
switch ( ( V_43 & V_160 ) >> 8 ) {
case V_111 :
V_2 -> V_83 = V_111 ;
break;
case V_148 :
default:
F_50 ( & V_2 -> V_3 -> V_38 , L_19 ) ;
return - V_24 ;
}
if ( V_43 & V_161 )
V_2 -> V_129 = V_162 ;
else
V_2 -> V_129 = V_130 ;
V_28 = F_54 ( V_2 -> V_3 , V_159 ,
V_43 | V_163 ) ;
if ( V_28 )
return V_28 ;
V_2 -> V_33 . V_112 = V_2 -> V_66 + V_164 ;
V_2 -> V_33 . V_34 = V_2 -> V_66 + V_165 ;
V_2 -> V_33 . V_64 = V_2 -> V_66 + V_166 ;
V_2 -> V_33 . V_54 = V_2 -> V_66 + V_167 ;
V_2 -> V_33 . V_57 = V_2 -> V_66 + V_168 ;
V_2 -> V_33 . V_94 = V_2 -> V_66 + V_169 ;
V_2 -> V_33 . V_85 = V_2 -> V_66 + V_170 ;
V_2 -> V_33 . V_46 = V_2 -> V_66 + V_171 ;
V_2 -> V_33 . V_47 = V_2 -> V_66 + V_172 ;
V_2 -> V_33 . V_154 = V_2 -> V_66 + V_173 ;
V_2 -> V_44 . V_120 = V_174 ;
V_2 -> V_44 . V_45 = V_175 ;
V_2 -> V_44 . V_121 = V_176 ;
V_2 -> V_44 . V_156 = V_177 ;
V_2 -> V_35 = V_178 ;
F_55 ( & V_2 -> V_106 , F_49 ) ;
F_55 ( & V_2 -> V_99 , F_45 ) ;
F_48 ( & V_2 -> V_106 , V_107 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_28 ;
if ( F_1 ( V_2 ) )
V_28 = F_51 ( V_2 ) ;
else if ( F_2 ( V_2 ) )
V_28 = F_52 ( V_2 ) ;
else
V_28 = - V_179 ;
if ( V_28 )
return V_28 ;
if ( V_2 -> V_83 == V_111 )
F_11 ( V_180 | V_181 ,
V_2 -> V_33 . V_154 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_58 ( & V_2 -> V_106 ) ;
F_58 ( & V_2 -> V_99 ) ;
}
}
static T_6 F_59 ( int V_182 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_32 ;
F_23 ( & V_2 -> V_3 -> V_38 , L_20 , V_182 ,
V_27 -> V_30 ) ;
V_32 = F_9 ( V_2 -> V_33 . V_34 ) ;
F_16 ( V_27 -> V_30 * V_2 -> V_35 , & V_32 ) ;
F_11 ( V_32 , V_2 -> V_33 . V_34 ) ;
F_8 ( & V_27 -> V_31 ) ;
V_2 -> V_110 = V_109 ;
F_36 ( ( T_4 ) 1 << V_27 -> V_30 , V_2 -> V_33 . V_112 ) ;
return V_183 ;
}
static T_6 F_60 ( int V_182 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
unsigned long V_32 ;
F_23 ( & V_2 -> V_3 -> V_38 , L_20 , V_182 ,
V_27 -> V_30 ) ;
V_32 = F_9 ( V_2 -> V_33 . V_34 ) ;
F_16 ( V_27 -> V_30 * V_2 -> V_35 , & V_32 ) ;
F_11 ( V_32 , V_2 -> V_33 . V_34 ) ;
F_8 ( & V_27 -> V_31 ) ;
F_11 ( ( ( 1 << V_2 -> V_35 ) - 1 ) <<
( V_27 -> V_30 * V_2 -> V_35 ) , V_2 -> V_33 . V_112 ) ;
return V_183 ;
}
static T_6 F_61 ( int V_182 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
int V_28 ;
F_23 ( & V_2 -> V_3 -> V_38 , L_21 , V_182 ) ;
V_28 = F_44 ( V_2 ) ;
if ( V_28 )
F_50 ( & V_2 -> V_3 -> V_38 , L_16 ) ;
F_11 ( 1 << V_184 , V_2 -> V_33 . V_112 ) ;
return V_183 ;
}
static T_6 F_62 ( int V_182 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
unsigned int V_42 = 0 ;
if ( F_2 ( V_2 ) ) {
T_4 V_112 = F_63 ( V_2 -> V_33 . V_112 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_22 , V_182 , V_112 ) ;
while ( V_112 ) {
V_42 = F_64 ( V_112 ) ;
V_112 &= V_112 - 1 ;
F_59 ( V_182 , & V_2 -> V_27 [ V_42 ] ) ;
}
} else {
T_5 V_112 = F_9 ( V_2 -> V_33 . V_112 ) ;
F_23 ( & V_2 -> V_3 -> V_38 , L_23 , V_182 , V_112 ) ;
if ( V_112 & V_185 ) {
F_61 ( V_182 , V_38 ) ;
V_112 &= ~ V_185 ;
}
while ( V_112 ) {
V_42 = F_64 ( V_112 ) ;
V_112 &= V_112 - 1 ;
F_60 ( V_182 , & V_2 -> V_27 [ V_42 ] ) ;
}
}
return V_183 ;
}
static int F_65 ( struct V_1 * V_2 , int V_186 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
struct V_187 * V_188 ;
int V_28 , V_42 ;
if ( V_186 < V_2 -> V_44 . V_156 )
return - V_189 ;
V_28 = F_66 ( V_3 , V_2 -> V_186 , V_186 ) ;
if ( V_28 < 0 )
return V_28 ;
for ( V_42 = 0 ; V_42 < V_186 ; V_42 ++ ) {
V_188 = & V_2 -> V_186 [ V_42 ] ;
F_67 ( ! V_188 -> V_190 ) ;
if ( V_42 == V_186 - 1 ) {
V_28 = F_68 ( V_188 -> V_190 ,
F_61 , 0 ,
L_24 , V_2 ) ;
if ( V_28 )
goto V_191;
} else {
V_28 = F_68 ( V_188 -> V_190 ,
F_60 , 0 ,
L_25 ,
& V_2 -> V_27 [ V_42 ] ) ;
if ( V_28 )
goto V_191;
}
}
V_2 -> V_192 = V_186 ;
V_2 -> V_37 = V_186 - 1 ;
return 0 ;
V_191:
while ( -- V_42 >= 0 ) {
V_188 = & V_2 -> V_186 [ V_42 ] ;
F_69 ( V_188 -> V_190 , & V_2 -> V_27 [ V_42 ] ) ;
}
F_70 ( V_3 ) ;
V_2 -> V_192 = 0 ;
return V_28 ;
}
static int F_71 ( struct V_1 * V_2 , int V_186 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
struct V_187 * V_188 ;
int V_28 , V_42 ;
V_186 = F_72 ( V_3 , V_2 -> V_186 ,
1 , V_186 ) ;
if ( V_186 < 0 )
return V_186 ;
for ( V_42 = 0 ; V_42 < V_186 ; V_42 ++ ) {
V_188 = & V_2 -> V_186 [ V_42 ] ;
F_67 ( ! V_188 -> V_190 ) ;
V_28 = F_68 ( V_188 -> V_190 , F_59 , 0 ,
L_25 , & V_2 -> V_27 [ V_42 ] ) ;
if ( V_28 )
goto V_191;
}
V_2 -> V_192 = V_186 ;
V_2 -> V_37 = V_186 ;
return 0 ;
V_191:
while ( -- V_42 >= 0 )
F_69 ( V_188 -> V_190 , & V_2 -> V_27 [ V_42 ] ) ;
F_70 ( V_3 ) ;
V_2 -> V_192 = 0 ;
return V_28 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
int V_186 ;
int V_28 , V_42 ;
V_186 = F_74 ( V_3 ) ;
if ( V_186 < 0 ) {
V_28 = V_186 ;
goto V_191;
} else if ( V_186 > V_2 -> V_44 . V_156 ) {
V_28 = - V_24 ;
goto V_191;
}
V_2 -> V_186 = F_75 ( sizeof( struct V_187 ) * V_186 ,
V_193 ) ;
if ( ! V_2 -> V_186 ) {
V_28 = - V_194 ;
goto V_191;
}
for ( V_42 = 0 ; V_42 < V_186 ; V_42 ++ )
V_2 -> V_186 [ V_42 ] . V_195 = V_42 ;
if ( F_2 ( V_2 ) )
V_28 = F_71 ( V_2 , V_186 ) ;
else
V_28 = F_65 ( V_2 , V_186 ) ;
if ( V_28 )
goto V_196;
return 0 ;
V_196:
F_76 ( V_2 -> V_186 ) ;
V_191:
F_50 ( & V_3 -> V_38 , L_26 ) ;
return V_28 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
int V_28 ;
V_28 = F_78 ( V_3 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_68 ( V_3 -> V_182 , F_62 , 0 , L_27 , V_2 ) ;
if ( V_28 ) {
F_79 ( V_3 ) ;
F_50 ( & V_3 -> V_38 , L_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
int V_28 ;
F_81 ( V_3 ) ;
F_82 ( V_3 , 1 ) ;
V_28 = F_68 ( V_3 -> V_182 , F_62 , V_197 , L_29 ,
V_2 ) ;
if ( V_28 )
return V_28 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_28 ;
if ( F_2 ( V_2 ) )
F_36 ( ~ 0 , V_2 -> V_33 . V_34 ) ;
else {
T_5 V_198 = 1 << V_184 ;
F_11 ( ~ V_198 , V_2 -> V_33 . V_34 ) ;
}
V_28 = F_73 ( V_2 ) ;
if ( ! V_28 )
goto V_199;
V_2 -> V_35 = 1 ;
V_2 -> V_37 = V_2 -> V_44 . V_121 ;
V_28 = F_77 ( V_2 ) ;
if ( ! V_28 )
goto V_199;
V_28 = F_80 ( V_2 ) ;
if ( V_28 ) {
F_50 ( & V_2 -> V_3 -> V_38 , L_30 ) ;
return V_28 ;
}
V_199:
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_39 * V_3 = V_2 -> V_3 ;
if ( F_2 ( V_2 ) )
F_36 ( ~ 0 , V_2 -> V_33 . V_34 ) ;
else
F_11 ( ~ 0 , V_2 -> V_33 . V_34 ) ;
if ( V_2 -> V_192 ) {
struct V_187 * V_188 ;
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_192 ; V_42 ++ ) {
V_188 = & V_2 -> V_186 [ V_42 ] ;
if ( F_1 ( V_2 ) && V_42 == V_2 -> V_192 - 1 )
F_69 ( V_188 -> V_190 , V_2 ) ;
else
F_69 ( V_188 -> V_190 , & V_2 -> V_27 [ V_42 ] ) ;
}
F_70 ( V_3 ) ;
F_76 ( V_2 -> V_186 ) ;
} else {
F_69 ( V_3 -> V_182 , V_2 ) ;
if ( F_85 ( V_3 ) )
F_79 ( V_3 ) ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
int V_42 ;
V_2 -> V_27 = F_87 ( V_2 -> V_44 . V_121 ,
sizeof( struct V_26 ) ,
V_193 ) ;
if ( ! V_2 -> V_27 )
return - V_194 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_44 . V_121 ; V_42 ++ ) {
V_2 -> V_27 [ V_42 ] . V_30 = V_42 ;
V_2 -> V_27 [ V_42 ] . V_2 = V_2 ;
}
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_44 . V_121 ; V_42 ++ )
F_15 ( V_2 , V_42 ) ;
F_76 ( V_2 -> V_27 ) ;
}
static T_7 F_89 ( struct V_200 * V_201 , char T_8 * V_202 ,
T_9 V_203 , T_10 * V_204 )
{
struct V_1 * V_2 ;
char * V_205 ;
T_7 V_206 , V_207 , V_208 ;
V_208 = 500 ;
V_205 = F_75 ( V_208 , V_193 ) ;
if ( ! V_205 )
return - V_194 ;
V_2 = V_201 -> V_209 ;
V_207 = 0 ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_31 ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_32 ,
V_2 -> V_83 == V_84 ?
L_33 : ( V_2 -> V_83 == V_111 ) ?
L_34 : L_35 ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_36 ,
V_2 -> V_129 == V_130 ?
L_37 : L_38 ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_39 ,
F_90 ( V_2 ) ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_40 ,
F_91 ( V_2 ) ? L_41 : L_42 ) ;
if ( F_91 ( V_2 ) ) {
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_43 ,
V_2 -> V_89 ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_44 ,
V_2 -> V_87 ) ;
}
if ( F_1 ( V_2 ) ) {
T_1 V_100 ;
T_5 V_105 ;
int V_28 ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_45 ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_46 ,
F_9 ( V_2 -> V_66 +
V_210 ) ) ;
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_47 ) ;
V_28 = F_43 ( V_2 -> V_3 , V_211 ,
& V_105 ) ;
if ( ! V_28 )
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_48 , V_105 ) ;
V_28 = F_43 ( V_2 -> V_3 , V_86 ,
& V_105 ) ;
if ( ! V_28 )
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_49 , V_105 ) ;
V_28 = F_53 ( V_2 -> V_3 , V_212 ,
& V_100 ) ;
if ( ! V_28 )
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_50 , V_100 ) ;
V_28 = F_53 ( V_2 -> V_3 , V_213 ,
& V_100 ) ;
if ( ! V_28 )
V_207 += snprintf ( V_205 + V_207 , V_208 - V_207 ,
L_51 , V_100 ) ;
}
if ( V_207 > V_208 )
V_207 = V_208 ;
V_206 = F_92 ( V_202 , V_203 , V_204 , V_205 , V_207 ) ;
F_76 ( V_205 ) ;
return V_206 ;
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! F_94 () )
return;
if ( ! V_214 )
V_214 = F_95 ( V_215 , NULL ) ;
V_2 -> V_214 = F_95 ( F_96 ( V_2 -> V_3 ) ,
V_214 ) ;
if ( V_2 -> V_214 )
V_2 -> V_216 = F_97 ( L_52 , V_217 ,
V_2 -> V_214 ,
V_2 ,
& V_218 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_99 ( V_2 -> V_214 ) ;
if ( V_214 && F_100 ( V_214 ) ) {
F_99 ( V_214 ) ;
V_214 = NULL ;
}
}
static void F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 == V_84 )
F_41 ( V_2 , V_81 ) ;
else {
T_1 V_93 ;
V_93 = F_26 ( V_2 -> V_33 . V_94 ) ;
V_93 &= ~ ( V_219 | V_220 ) ;
V_93 |= V_221 | V_222 ;
V_93 |= V_223 | V_224 ;
if ( V_2 -> V_56 )
V_93 |= V_225 |
V_226 ;
F_24 ( V_93 , V_2 -> V_33 . V_94 ) ;
}
}
static void F_102 ( struct V_1 * V_2 )
{
T_1 V_93 ;
if ( V_2 -> V_83 == V_84 ) {
F_41 ( V_2 , V_91 ) ;
return;
}
V_93 = F_26 ( V_2 -> V_33 . V_94 ) ;
V_93 &= ~ ( V_221 | V_222 ) ;
V_93 &= ~ ( V_223 | V_224 ) ;
if ( V_2 -> V_56 )
V_93 &= ~ ( V_225 |
V_226 ) ;
V_93 |= V_219 | V_220 ;
F_24 ( V_93 , V_2 -> V_33 . V_94 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 )
V_2 -> V_44 . V_120 = V_127 ;
else
V_2 -> V_44 . V_120 = V_128 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_28 , V_227 ;
T_1 V_228 ;
T_11 V_229 ;
V_2 -> V_62 = V_230 ;
V_28 = F_105 ( V_2 -> V_3 , V_159 , & V_229 ) ;
if ( V_28 )
return - V_231 ;
if ( V_229 & V_232 )
V_2 -> V_129 = V_130 ;
else
V_2 -> V_129 = V_162 ;
V_2 -> V_56 = ( V_229 & V_233 ) ? 1 : 0 ;
switch ( V_229 & V_234 ) {
case V_111 :
F_42 ( & V_2 -> V_3 -> V_38 , L_53 ) ;
V_2 -> V_83 = V_111 ;
break;
case V_148 :
F_42 ( & V_2 -> V_3 -> V_38 , L_54 ) ;
V_2 -> V_83 = V_148 ;
break;
case V_84 :
F_42 ( & V_2 -> V_3 -> V_38 , L_55 ) ;
V_2 -> V_83 = V_84 ;
V_2 -> V_129 = V_130 ;
V_227 = F_106 ( V_2 -> V_3 , V_235 ) ;
V_228 = F_107 ( V_227 ) ;
if ( V_228 == ( V_127 + 1 ) )
V_2 -> V_56 = 1 ;
break;
default:
F_50 ( & V_2 -> V_3 -> V_38 , L_56 , V_229 ) ;
return - V_179 ;
}
F_103 ( V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_28 ;
T_1 V_229 ;
V_2 -> V_62 = V_63 ;
V_2 -> V_44 . V_120 = V_174 ;
V_28 = F_53 ( V_2 -> V_3 , V_159 , & V_229 ) ;
if ( V_28 )
return V_28 ;
switch ( ( V_229 & V_160 ) >> 8 ) {
case V_111 :
F_42 ( & V_2 -> V_3 -> V_38 , L_53 ) ;
V_2 -> V_83 = V_111 ;
break;
case V_148 :
default:
F_50 ( & V_2 -> V_3 -> V_38 , L_19 ) ;
return - V_24 ;
}
if ( V_229 & V_161 )
V_2 -> V_129 = V_162 ;
else
V_2 -> V_129 = V_130 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_28 ;
if ( F_1 ( V_2 ) )
V_28 = F_104 ( V_2 ) ;
else if ( F_2 ( V_2 ) )
V_28 = F_108 ( V_2 ) ;
else
V_28 = - V_179 ;
F_42 ( & V_2 -> V_3 -> V_38 , L_57 ,
V_2 -> V_129 == V_130 ? L_38 : L_37 ) ;
return 0 ;
}
static int F_110 ( struct V_39 * V_3 , const struct V_236 * V_237 )
{
struct V_1 * V_2 ;
int V_28 , V_42 ;
V_2 = F_111 ( sizeof( struct V_1 ) , V_193 ) ;
if ( ! V_2 )
return - V_194 ;
V_2 -> V_3 = V_3 ;
F_3 ( V_2 ) ;
V_2 -> V_80 = V_91 ;
F_112 ( V_3 , V_2 ) ;
F_93 ( V_2 ) ;
V_28 = F_113 ( V_3 ) ;
if ( V_28 )
goto V_191;
F_114 ( V_2 -> V_3 ) ;
V_28 = F_109 ( V_2 ) ;
if ( V_28 )
goto V_191;
V_2 -> V_48 = F_87 ( V_2 -> V_44 . V_120 , sizeof( struct V_238 ) ,
V_193 ) ;
if ( ! V_2 -> V_48 ) {
V_28 = - V_194 ;
goto V_196;
}
if ( V_2 -> V_56 )
V_28 = F_115 ( V_3 , V_239 ,
V_215 ) ;
else
V_28 = F_115 ( V_3 , V_240 ,
V_215 ) ;
if ( V_28 )
goto V_241;
V_2 -> V_66 = F_116 ( V_3 , V_242 ) ;
if ( ! V_2 -> V_66 ) {
F_13 ( & V_3 -> V_38 , L_58 ) ;
V_28 = - V_231 ;
goto V_243;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_44 . V_120 ; V_42 ++ ) {
V_2 -> V_48 [ V_42 ] . V_50 = F_117 ( V_3 , F_32 ( V_42 ) ) ;
if ( ( V_2 -> V_18 & V_19 ) &&
( V_42 == ( V_2 -> V_44 . V_120 - 1 ) ) ) {
V_2 -> V_48 [ V_42 ] . V_49 =
F_118 ( F_31 ( V_3 ,
F_32 ( V_42 ) ) ,
V_2 -> V_48 [ V_42 ] . V_50 ) ;
} else {
V_2 -> V_48 [ V_42 ] . V_49 =
F_119 ( F_31 ( V_3 ,
F_32 ( V_42 ) ) ,
V_2 -> V_48 [ V_42 ] . V_50 ) ;
}
F_42 ( & V_3 -> V_38 , L_59 , V_42 ,
( unsigned long long ) V_2 -> V_48 [ V_42 ] . V_50 ) ;
if ( ! V_2 -> V_48 [ V_42 ] . V_49 ) {
F_13 ( & V_3 -> V_38 , L_60 ,
F_32 ( V_42 ) ) ;
V_28 = - V_231 ;
goto V_244;
}
}
V_28 = F_120 ( V_3 , F_121 ( 64 ) ) ;
if ( V_28 ) {
V_28 = F_120 ( V_3 , F_121 ( 32 ) ) ;
if ( V_28 )
goto V_244;
F_13 ( & V_3 -> V_38 , L_61 ) ;
}
V_28 = F_122 ( V_3 , F_121 ( 64 ) ) ;
if ( V_28 ) {
V_28 = F_122 ( V_3 , F_121 ( 32 ) ) ;
if ( V_28 )
goto V_244;
F_13 ( & V_3 -> V_38 , L_62 ) ;
}
V_28 = F_56 ( V_2 ) ;
if ( V_28 )
goto V_244;
V_28 = F_86 ( V_2 ) ;
if ( V_28 )
goto V_245;
V_28 = F_83 ( V_2 ) ;
if ( V_28 )
goto V_246;
for ( V_42 = 0 ; V_42 < V_2 -> V_44 . V_45 ; V_42 ++ ) {
F_22 ( V_2 , V_42 , 0 ) ;
F_27 ( V_2 , V_42 , 0 ) ;
}
V_28 = F_123 ( V_3 ) ;
if ( V_28 )
goto V_247;
F_101 ( V_2 ) ;
return 0 ;
V_247:
F_84 ( V_2 ) ;
V_246:
F_88 ( V_2 ) ;
V_245:
F_57 ( V_2 ) ;
V_244:
for ( V_42 -- ; V_42 >= 0 ; V_42 -- )
F_124 ( V_2 -> V_48 [ V_42 ] . V_49 ) ;
F_124 ( V_2 -> V_66 ) ;
V_243:
if ( V_2 -> V_56 )
F_125 ( V_3 , V_239 ) ;
else
F_125 ( V_3 , V_240 ) ;
V_241:
F_76 ( V_2 -> V_48 ) ;
V_196:
F_126 ( V_3 ) ;
V_191:
F_98 ( V_2 ) ;
F_76 ( V_2 ) ;
F_50 ( & V_3 -> V_38 , L_63 , V_215 ) ;
return V_28 ;
}
static void F_127 ( struct V_39 * V_3 )
{
struct V_1 * V_2 = F_19 ( V_3 ) ;
int V_42 ;
F_102 ( V_2 ) ;
F_128 ( V_2 -> V_40 ) ;
F_84 ( V_2 ) ;
F_88 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_62 == V_230 )
F_103 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_44 . V_120 ; V_42 ++ )
F_124 ( V_2 -> V_48 [ V_42 ] . V_49 ) ;
F_76 ( V_2 -> V_48 ) ;
F_124 ( V_2 -> V_66 ) ;
if ( V_2 -> V_56 )
F_125 ( V_3 , V_239 ) ;
else
F_125 ( V_3 , V_240 ) ;
F_126 ( V_3 ) ;
F_98 ( V_2 ) ;
F_76 ( V_2 ) ;
}
