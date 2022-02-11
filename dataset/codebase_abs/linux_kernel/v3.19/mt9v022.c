static const struct V_1 * F_1 (
T_1 V_2 , const struct V_1 * V_3 ,
int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
if ( V_3 [ V_5 ] . V_2 == V_2 )
return V_3 + V_5 ;
return NULL ;
}
static struct V_6 * F_2 ( const struct V_7 * V_8 )
{
return F_3 ( F_4 ( V_8 ) , struct V_6 , V_9 ) ;
}
static int F_5 ( struct V_7 * V_8 , const T_2 V_10 )
{
return F_6 ( V_8 , V_10 ) ;
}
static int F_7 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
return F_8 ( V_8 , V_10 , V_11 ) ;
}
static int F_9 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_8 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_8 , V_10 , V_12 | V_11 ) ;
}
static int F_10 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_8 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_8 , V_10 , V_12 & ~ V_11 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
int V_12 ;
V_6 -> V_13 |= 0x10 ;
V_12 = F_7 ( V_8 , V_14 , V_6 -> V_13 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_15 , 0x300 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_8 , V_16 , 0x3 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_17 , 16 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_18 , 480 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_6 -> V_10 -> V_19 , 480 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_8 , V_20 , 1 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_21 , 0 ) ;
if ( ! V_12 )
return F_12 ( & V_6 -> V_22 ) ;
return V_12 ;
}
static int F_13 ( struct V_23 * V_24 , int V_25 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_25 ) {
V_6 -> V_13 &= ~ 0x10 ;
if ( F_15 ( V_6 -> V_26 ) ||
F_16 ( V_6 -> V_26 ) ) {
if ( F_10 ( V_8 , V_27 , 0x204 ) )
return - V_28 ;
}
} else {
V_6 -> V_13 |= 0x10 ;
if ( F_15 ( V_6 -> V_26 ) ||
F_16 ( V_6 -> V_26 ) ) {
if ( F_9 ( V_8 , V_27 , 0x204 ) )
return - V_28 ;
}
}
if ( F_7 ( V_8 , V_14 , V_6 -> V_13 ) < 0 )
return - V_28 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_24 , const struct V_29 * V_30 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_31 V_32 = V_30 -> V_33 ;
int V_34 , V_35 ;
int V_12 ;
if ( V_6 -> V_36 == V_37 ) {
V_32 . V_38 = F_18 ( V_32 . V_38 , 2 ) ;
V_32 . V_39 = F_18 ( V_32 . V_39 , 2 ) ;
}
F_19 ( & V_32 . V_40 , & V_32 . V_38 ,
V_41 , V_42 , V_43 ) ;
F_19 ( & V_32 . V_44 , & V_32 . V_39 ,
V_45 , V_46 , V_47 ) ;
V_12 = F_5 ( V_8 , V_16 ) ;
if ( V_12 >= 0 ) {
if ( V_12 & 1 )
V_12 = F_7 ( V_8 , V_6 -> V_10 -> V_19 ,
V_32 . V_39 + V_6 -> V_48 + 43 ) ;
}
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_49 , V_32 . V_40 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_50 , V_32 . V_44 ) ;
if ( F_16 ( V_6 -> V_26 ) ) {
V_34 = 690 ;
V_35 = 61 ;
} else {
V_34 = 660 ;
V_35 = 43 ;
}
if ( ! V_12 )
V_12 = F_20 ( V_6 -> V_51 ,
V_32 . V_38 > V_34 - V_35 ?
V_35 : V_34 - V_32 . V_38 ) ;
if ( ! V_12 )
V_12 = F_20 ( V_6 -> V_52 , 45 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_53 , V_32 . V_38 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_54 ,
V_32 . V_39 + V_6 -> V_48 ) ;
if ( V_12 < 0 )
return V_12 ;
F_21 ( & V_8 -> V_55 , L_1 , V_32 . V_38 , V_32 . V_39 ) ;
V_6 -> V_32 = V_32 ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 , struct V_29 * V_30 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_30 -> V_33 = V_6 -> V_32 ;
V_30 -> type = V_56 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 , struct V_57 * V_30 )
{
V_30 -> V_58 . V_40 = V_41 ;
V_30 -> V_58 . V_44 = V_45 ;
V_30 -> V_58 . V_38 = V_43 ;
V_30 -> V_58 . V_39 = V_47 ;
V_30 -> V_59 = V_30 -> V_58 ;
V_30 -> type = V_56 ;
V_30 -> V_60 . V_61 = 1 ;
V_30 -> V_60 . V_62 = 1 ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_63 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_64 -> V_38 = V_6 -> V_32 . V_38 ;
V_64 -> V_39 = V_6 -> V_32 . V_39 ;
V_64 -> V_2 = V_6 -> V_3 -> V_2 ;
V_64 -> V_65 = V_6 -> V_3 -> V_65 ;
V_64 -> V_66 = V_67 ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_63 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_29 V_30 = {
. V_33 = {
. V_40 = V_6 -> V_32 . V_40 ,
. V_44 = V_6 -> V_32 . V_44 ,
. V_38 = V_64 -> V_38 ,
. V_39 = V_64 -> V_39 ,
} ,
} ;
int V_12 ;
switch ( V_64 -> V_2 ) {
case V_68 :
case V_69 :
if ( V_6 -> V_70 != V_71 )
return - V_72 ;
break;
case V_73 :
case V_74 :
if ( V_6 -> V_70 != V_75 )
return - V_72 ;
break;
default:
return - V_72 ;
}
V_12 = F_17 ( V_24 , & V_30 ) ;
if ( ! V_12 ) {
V_64 -> V_38 = V_6 -> V_32 . V_38 ;
V_64 -> V_39 = V_6 -> V_32 . V_39 ;
V_6 -> V_3 = F_1 ( V_64 -> V_2 ,
V_6 -> V_36 , V_6 -> V_76 ) ;
V_64 -> V_65 = V_6 -> V_3 -> V_65 ;
}
return V_12 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_63 * V_64 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
int V_77 = V_64 -> V_2 == V_73 ||
V_64 -> V_2 == V_74 ;
F_27 ( & V_64 -> V_38 , V_42 ,
V_43 , V_77 ,
& V_64 -> V_39 , V_46 + V_6 -> V_48 ,
V_47 + V_6 -> V_48 , V_77 , 0 ) ;
V_3 = F_1 ( V_64 -> V_2 , V_6 -> V_36 ,
V_6 -> V_76 ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_64 -> V_2 = V_3 -> V_2 ;
}
V_64 -> V_65 = V_3 -> V_65 ;
return 0 ;
}
static int F_28 ( struct V_23 * V_24 ,
struct V_78 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_72 ;
V_10 -> V_79 = 2 ;
V_10 -> V_80 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_80 > 0xffff )
return - V_28 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 ,
const struct V_78 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_72 ;
if ( F_7 ( V_8 , V_10 -> V_10 , V_10 -> V_80 ) < 0 )
return - V_28 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 , int V_81 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_32 ( & V_8 -> V_55 , V_83 , V_6 -> V_84 , V_81 ) ;
}
static int F_33 ( struct V_85 * V_86 )
{
struct V_6 * V_6 = F_3 ( V_86 -> V_87 ,
struct V_6 , V_22 ) ;
struct V_23 * V_24 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_85 * V_88 = V_6 -> V_88 ;
struct V_85 * exp = V_6 -> V_89 ;
unsigned long V_90 ;
int V_11 ;
switch ( V_86 -> V_91 ) {
case V_92 :
V_11 = F_5 ( V_8 , V_17 ) ;
if ( V_11 < 0 )
return - V_28 ;
V_90 = V_88 -> V_93 - V_88 -> V_94 ;
V_88 -> V_80 = ( ( V_11 - 16 ) * V_90 + 24 ) / 48 + V_88 -> V_94 ;
return 0 ;
case V_95 :
V_11 = F_5 ( V_8 , V_18 ) ;
if ( V_11 < 0 )
return - V_28 ;
V_90 = exp -> V_93 - exp -> V_94 ;
exp -> V_80 = ( ( V_11 - 1 ) * V_90 + 239 ) / 479 + exp -> V_94 ;
return 0 ;
case V_96 :
V_11 = F_5 ( V_8 , V_97 ) ;
if ( V_11 < 0 )
return - V_28 ;
V_86 -> V_80 = V_11 ;
return 0 ;
case V_98 :
V_11 = F_5 ( V_8 , V_99 ) ;
if ( V_11 < 0 )
return - V_28 ;
V_86 -> V_80 = V_11 ;
return 0 ;
}
return - V_72 ;
}
static int F_34 ( struct V_85 * V_86 )
{
struct V_6 * V_6 = F_3 ( V_86 -> V_87 ,
struct V_6 , V_22 ) ;
struct V_23 * V_24 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_14 ( V_24 ) ;
int V_11 ;
switch ( V_86 -> V_91 ) {
case V_100 :
if ( V_86 -> V_80 )
V_11 = F_9 ( V_8 , V_15 , 0x10 ) ;
else
V_11 = F_10 ( V_8 , V_15 , 0x10 ) ;
if ( V_11 < 0 )
return - V_28 ;
return 0 ;
case V_101 :
if ( V_86 -> V_80 )
V_11 = F_9 ( V_8 , V_15 , 0x20 ) ;
else
V_11 = F_10 ( V_8 , V_15 , 0x20 ) ;
if ( V_11 < 0 )
return - V_28 ;
return 0 ;
case V_92 :
if ( V_86 -> V_80 ) {
if ( F_9 ( V_8 , V_16 , 0x2 ) < 0 )
return - V_28 ;
} else {
struct V_85 * V_88 = V_6 -> V_88 ;
unsigned long V_90 = V_88 -> V_93 - V_88 -> V_94 ;
unsigned long V_102 = ( ( V_88 -> V_80 - ( V_103 ) V_88 -> V_94 ) *
48 + V_90 / 2 ) / V_90 + 16 ;
if ( V_102 >= 32 )
V_102 &= ~ 1 ;
if ( F_10 ( V_8 , V_16 , 0x2 ) < 0 )
return - V_28 ;
F_21 ( & V_8 -> V_55 , L_2 ,
F_5 ( V_8 , V_17 ) , V_102 ) ;
if ( F_7 ( V_8 , V_17 , V_102 ) < 0 )
return - V_28 ;
}
return 0 ;
case V_95 :
if ( V_86 -> V_80 == V_104 ) {
V_11 = F_9 ( V_8 , V_16 , 0x1 ) ;
} else {
struct V_85 * exp = V_6 -> V_89 ;
unsigned long V_90 = exp -> V_93 - exp -> V_94 ;
unsigned long V_105 = ( ( exp -> V_80 - ( V_103 ) exp -> V_94 ) *
479 + V_90 / 2 ) / V_90 + 1 ;
V_11 = F_10 ( V_8 , V_16 , 0x1 ) ;
if ( V_11 < 0 )
return - V_28 ;
F_21 ( & V_8 -> V_55 , L_3 ,
F_5 ( V_8 , V_18 ) ,
V_105 ) ;
if ( F_7 ( V_8 , V_18 ,
V_105 ) < 0 )
return - V_28 ;
}
return 0 ;
case V_96 :
if ( F_7 ( V_8 , V_97 ,
V_86 -> V_80 ) < 0 )
return - V_28 ;
return 0 ;
case V_98 :
if ( F_7 ( V_8 , V_99 ,
V_86 -> V_80 ) < 0 )
return - V_28 ;
return 0 ;
}
return - V_72 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
V_103 V_11 ;
int V_12 ;
unsigned long V_106 ;
V_12 = F_30 ( & V_6 -> V_9 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_5 ( V_8 , V_107 ) ;
if ( V_11 != 0x1311 && V_11 != 0x1313 && V_11 != 0x1324 ) {
V_12 = - V_108 ;
F_36 ( & V_8 -> V_55 , L_4 ,
V_11 ) ;
goto V_109;
}
V_6 -> V_26 = V_11 ;
V_6 -> V_10 = F_16 ( V_11 ) ? & V_110 :
& V_111 ;
V_12 = F_7 ( V_8 , V_112 , 1 ) ;
if ( V_12 < 0 )
goto V_109;
F_37 ( 200 ) ;
if ( F_5 ( V_8 , V_112 ) ) {
F_38 ( & V_8 -> V_55 , L_5 ) ;
if ( V_12 > 0 )
V_12 = - V_28 ;
goto V_109;
}
if ( V_113 && ( ! strcmp ( L_6 , V_113 ) ||
! strcmp ( L_7 , V_113 ) ) ) {
V_12 = F_7 ( V_8 , V_114 , 4 | 0x11 ) ;
V_6 -> V_70 = V_75 ;
V_6 -> V_36 = V_37 ;
} else {
V_12 = F_7 ( V_8 , V_114 , 0x11 ) ;
V_6 -> V_70 = V_71 ;
V_6 -> V_36 = V_115 ;
}
if ( V_12 < 0 )
goto V_109;
V_6 -> V_76 = 0 ;
if ( V_83 -> V_116 )
V_106 = V_83 -> V_116 ( V_83 ) ;
else
V_106 = V_117 ;
if ( V_106 & V_117 )
V_6 -> V_76 ++ ;
else
V_6 -> V_36 ++ ;
if ( V_106 & V_118 )
V_6 -> V_76 ++ ;
V_6 -> V_3 = & V_6 -> V_36 [ 0 ] ;
F_36 ( & V_8 -> V_55 , L_8 ,
V_11 , V_6 -> V_70 == V_71 ?
L_9 : L_6 ) ;
V_12 = F_11 ( V_8 ) ;
if ( V_12 < 0 )
F_38 ( & V_8 -> V_55 , L_10 ) ;
V_109:
F_30 ( & V_6 -> V_9 , 0 ) ;
return V_12 ;
}
static int F_39 ( struct V_23 * V_24 , T_1 * V_119 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
* V_119 = V_6 -> V_48 ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 , unsigned int V_120 ,
T_1 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_120 >= V_6 -> V_76 )
return - V_72 ;
* V_2 = V_6 -> V_36 [ V_120 ] . V_2 ;
return 0 ;
}
static int F_41 ( struct V_23 * V_24 ,
struct V_121 * V_122 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
V_122 -> V_106 = V_123 | V_124 |
V_125 | V_126 |
V_127 | V_128 |
V_129 | V_130 |
V_131 ;
V_122 -> type = V_132 ;
V_122 -> V_106 = F_42 ( V_83 , V_122 ) ;
return 0 ;
}
static int F_43 ( struct V_23 * V_24 ,
const struct V_121 * V_122 )
{
struct V_7 * V_8 = F_14 ( V_24 ) ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned long V_106 = F_42 ( V_83 , V_122 ) ;
unsigned int V_133 = F_44 ( V_6 -> V_3 -> V_2 ) -> V_134 ;
int V_12 ;
T_3 V_135 = 0 ;
if ( V_83 -> V_136 ) {
V_12 = V_83 -> V_136 ( V_83 , 1 << ( V_133 - 1 ) ) ;
if ( V_12 )
return V_12 ;
} else if ( V_133 != 10 ) {
return - V_72 ;
}
if ( V_106 & V_126 )
V_135 |= 0x10 ;
if ( ! ( V_106 & V_127 ) )
V_135 |= 0x1 ;
if ( ! ( V_106 & V_129 ) )
V_135 |= 0x2 ;
V_12 = F_7 ( V_8 , V_6 -> V_10 -> V_137 , V_135 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_106 & V_123 ) )
V_6 -> V_13 &= ~ 0x8 ;
V_12 = F_7 ( V_8 , V_14 , V_6 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
F_21 ( & V_8 -> V_55 , L_11 ,
V_135 , V_6 -> V_13 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
const struct V_138 * V_139 )
{
struct V_6 * V_6 ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
struct V_140 * V_141 = F_46 ( V_8 -> V_55 . V_142 ) ;
struct V_143 * V_144 ;
int V_12 ;
if ( ! V_83 ) {
F_38 ( & V_8 -> V_55 , L_12 ) ;
return - V_72 ;
}
if ( ! F_47 ( V_141 , V_145 ) ) {
F_48 ( & V_141 -> V_55 ,
L_13 ) ;
return - V_28 ;
}
V_6 = F_49 ( & V_8 -> V_55 , sizeof( struct V_6 ) , V_146 ) ;
if ( ! V_6 )
return - V_147 ;
V_144 = V_83 -> V_148 ;
F_50 ( & V_6 -> V_9 , V_8 , & V_149 ) ;
F_51 ( & V_6 -> V_22 , 6 ) ;
F_52 ( & V_6 -> V_22 , & V_150 ,
V_100 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_6 -> V_22 , & V_150 ,
V_101 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_151 = F_52 ( & V_6 -> V_22 , & V_150 ,
V_92 , 0 , 1 , 1 , 1 ) ;
V_6 -> V_88 = F_52 ( & V_6 -> V_22 , & V_150 ,
V_152 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_153 = F_53 ( & V_6 -> V_22 ,
& V_150 , V_95 , 1 , 0 ,
V_104 ) ;
V_6 -> V_89 = F_52 ( & V_6 -> V_22 , & V_150 ,
V_154 , 1 , 255 , 1 , 255 ) ;
V_6 -> V_51 = F_52 ( & V_6 -> V_22 , & V_150 ,
V_96 , V_155 ,
V_156 , 1 ,
V_157 ) ;
V_6 -> V_52 = F_52 ( & V_6 -> V_22 , & V_150 ,
V_98 , V_158 ,
V_159 , 1 ,
V_160 ) ;
V_6 -> V_9 . V_161 = & V_6 -> V_22 ;
if ( V_6 -> V_22 . error ) {
int V_162 = V_6 -> V_22 . error ;
F_38 ( & V_8 -> V_55 , L_14 , V_162 ) ;
return V_162 ;
}
F_54 ( 2 , & V_6 -> V_153 ,
V_163 , true ) ;
F_54 ( 2 , & V_6 -> V_151 , 0 , true ) ;
V_6 -> V_13 = V_164 ;
V_6 -> V_48 = V_144 ? V_144 -> V_48 : 0 ;
V_6 -> V_32 . V_40 = V_41 ;
V_6 -> V_32 . V_44 = V_45 ;
V_6 -> V_32 . V_38 = V_43 ;
V_6 -> V_32 . V_39 = V_47 ;
V_6 -> V_84 = F_55 ( & V_8 -> V_55 , L_15 ) ;
if ( F_56 ( V_6 -> V_84 ) ) {
V_12 = F_57 ( V_6 -> V_84 ) ;
goto V_165;
}
V_12 = F_35 ( V_8 ) ;
if ( V_12 ) {
F_58 ( V_6 -> V_84 ) ;
V_165:
F_59 ( & V_6 -> V_22 ) ;
}
return V_12 ;
}
static int F_60 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_82 * V_83 = F_31 ( V_8 ) ;
F_58 ( V_6 -> V_84 ) ;
F_61 ( & V_6 -> V_9 ) ;
if ( V_83 -> V_166 )
V_83 -> V_166 ( V_83 ) ;
F_59 ( & V_6 -> V_22 ) ;
return 0 ;
}
