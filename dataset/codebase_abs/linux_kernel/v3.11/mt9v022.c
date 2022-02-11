static const struct V_1 * F_1 (
enum V_2 V_3 , const struct V_1 * V_4 ,
int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_3 == V_3 )
return V_4 + V_6 ;
return NULL ;
}
static struct V_7 * F_2 ( const struct V_8 * V_9 )
{
return F_3 ( F_4 ( V_9 ) , struct V_7 , V_10 ) ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 V_11 )
{
return F_6 ( V_9 , V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
return F_8 ( V_9 , V_11 , V_12 ) ;
}
static int F_9 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_9 , V_11 , V_13 | V_12 ) ;
}
static int F_10 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_9 , V_11 , V_13 & ~ V_12 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_13 ;
V_7 -> V_14 |= 0x10 ;
V_13 = F_7 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_16 , 0x300 ) ;
if ( ! V_13 )
V_13 = F_9 ( V_9 , V_17 , 0x3 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_18 , 16 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_19 , 480 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_20 , 480 ) ;
if ( ! V_13 )
V_13 = F_10 ( V_9 , V_21 , 1 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_22 , 0 ) ;
if ( ! V_13 )
return F_12 ( & V_7 -> V_23 ) ;
return V_13 ;
}
static int F_13 ( struct V_24 * V_25 , int V_26 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_26 ) {
V_7 -> V_14 &= ~ 0x10 ;
if ( F_15 ( V_7 -> V_27 ) ||
F_16 ( V_7 -> V_27 ) ) {
if ( F_10 ( V_9 , V_28 , 0x204 ) )
return - V_29 ;
}
} else {
V_7 -> V_14 |= 0x10 ;
if ( F_15 ( V_7 -> V_27 ) ||
F_16 ( V_7 -> V_27 ) ) {
if ( F_9 ( V_9 , V_28 , 0x204 ) )
return - V_29 ;
}
}
if ( F_7 ( V_9 , V_15 , V_7 -> V_14 ) < 0 )
return - V_29 ;
return 0 ;
}
static int F_17 ( struct V_24 * V_25 , const struct V_30 * V_31 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_32 V_33 = V_31 -> V_34 ;
int V_35 , V_36 ;
int V_13 ;
if ( V_7 -> V_37 == V_38 ) {
V_33 . V_39 = F_18 ( V_33 . V_39 , 2 ) ;
V_33 . V_40 = F_18 ( V_33 . V_40 , 2 ) ;
}
F_19 ( & V_33 . V_41 , & V_33 . V_39 ,
V_42 , V_43 , V_44 ) ;
F_19 ( & V_33 . V_45 , & V_33 . V_40 ,
V_46 , V_47 , V_48 ) ;
V_13 = F_5 ( V_9 , V_17 ) ;
if ( V_13 >= 0 ) {
if ( V_13 & 1 )
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_20 ,
V_33 . V_40 + V_7 -> V_49 + 43 ) ;
}
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_50 , V_33 . V_41 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_51 , V_33 . V_45 ) ;
if ( F_16 ( V_7 -> V_27 ) ) {
V_35 = 690 ;
V_36 = 61 ;
} else {
V_35 = 660 ;
V_36 = 43 ;
}
if ( ! V_13 )
V_13 = F_20 ( V_7 -> V_52 ,
V_33 . V_39 > V_35 - V_36 ?
V_36 : V_35 - V_33 . V_39 ) ;
if ( ! V_13 )
V_13 = F_20 ( V_7 -> V_53 , 45 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_54 , V_33 . V_39 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_55 ,
V_33 . V_40 + V_7 -> V_49 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_56 , L_1 , V_33 . V_39 , V_33 . V_40 ) ;
V_7 -> V_33 = V_33 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_31 -> V_34 = V_7 -> V_33 ;
V_31 -> type = V_57 ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 , struct V_58 * V_31 )
{
V_31 -> V_59 . V_41 = V_42 ;
V_31 -> V_59 . V_45 = V_46 ;
V_31 -> V_59 . V_39 = V_44 ;
V_31 -> V_59 . V_40 = V_48 ;
V_31 -> V_60 = V_31 -> V_59 ;
V_31 -> type = V_57 ;
V_31 -> V_61 . V_62 = 1 ;
V_31 -> V_61 . V_63 = 1 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_65 -> V_39 = V_7 -> V_33 . V_39 ;
V_65 -> V_40 = V_7 -> V_33 . V_40 ;
V_65 -> V_3 = V_7 -> V_4 -> V_3 ;
V_65 -> V_66 = V_7 -> V_4 -> V_66 ;
V_65 -> V_67 = V_68 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_30 V_31 = {
. V_34 = {
. V_41 = V_7 -> V_33 . V_41 ,
. V_45 = V_7 -> V_33 . V_45 ,
. V_39 = V_65 -> V_39 ,
. V_40 = V_65 -> V_40 ,
} ,
} ;
int V_13 ;
switch ( V_65 -> V_3 ) {
case V_69 :
case V_70 :
if ( V_7 -> V_71 != V_72 )
return - V_73 ;
break;
case V_74 :
case V_75 :
if ( V_7 -> V_71 != V_76 )
return - V_73 ;
break;
default:
return - V_73 ;
}
V_13 = F_17 ( V_25 , & V_31 ) ;
if ( ! V_13 ) {
V_65 -> V_39 = V_7 -> V_33 . V_39 ;
V_65 -> V_40 = V_7 -> V_33 . V_40 ;
V_7 -> V_4 = F_1 ( V_65 -> V_3 ,
V_7 -> V_37 , V_7 -> V_77 ) ;
V_65 -> V_66 = V_7 -> V_4 -> V_66 ;
}
return V_13 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_78 = V_65 -> V_3 == V_74 ||
V_65 -> V_3 == V_75 ;
F_27 ( & V_65 -> V_39 , V_43 ,
V_44 , V_78 ,
& V_65 -> V_40 , V_47 + V_7 -> V_49 ,
V_48 + V_7 -> V_49 , V_78 , 0 ) ;
V_4 = F_1 ( V_65 -> V_3 , V_7 -> V_37 ,
V_7 -> V_77 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_65 -> V_3 = V_4 -> V_3 ;
}
V_65 -> V_66 = V_4 -> V_66 ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_79 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_11 > 0xff )
return - V_73 ;
V_11 -> V_80 = 2 ;
V_11 -> V_81 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_81 > 0xffff )
return - V_29 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
const struct V_79 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_11 > 0xff )
return - V_73 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_81 ) < 0 )
return - V_29 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 , int V_82 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
return F_32 ( & V_9 -> V_56 , V_84 , V_7 -> V_85 , V_82 ) ;
}
static int F_33 ( struct V_86 * V_87 )
{
struct V_7 * V_7 = F_3 ( V_87 -> V_88 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_86 * V_89 = V_7 -> V_89 ;
struct V_86 * exp = V_7 -> V_90 ;
unsigned long V_91 ;
int V_12 ;
switch ( V_87 -> V_92 ) {
case V_93 :
V_12 = F_5 ( V_9 , V_18 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_91 = V_89 -> V_94 - V_89 -> V_95 ;
V_89 -> V_81 = ( ( V_12 - 16 ) * V_91 + 24 ) / 48 + V_89 -> V_95 ;
return 0 ;
case V_96 :
V_12 = F_5 ( V_9 , V_19 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_91 = exp -> V_94 - exp -> V_95 ;
exp -> V_81 = ( ( V_12 - 1 ) * V_91 + 239 ) / 479 + exp -> V_95 ;
return 0 ;
case V_97 :
V_12 = F_5 ( V_9 , V_98 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_87 -> V_81 = V_12 ;
return 0 ;
case V_99 :
V_12 = F_5 ( V_9 , V_100 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_87 -> V_81 = V_12 ;
return 0 ;
}
return - V_73 ;
}
static int F_34 ( struct V_86 * V_87 )
{
struct V_7 * V_7 = F_3 ( V_87 -> V_88 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
int V_12 ;
switch ( V_87 -> V_92 ) {
case V_101 :
if ( V_87 -> V_81 )
V_12 = F_9 ( V_9 , V_16 , 0x10 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x10 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_102 :
if ( V_87 -> V_81 )
V_12 = F_9 ( V_9 , V_16 , 0x20 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x20 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_93 :
if ( V_87 -> V_81 ) {
if ( F_9 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
} else {
struct V_86 * V_89 = V_7 -> V_89 ;
unsigned long V_91 = V_89 -> V_94 - V_89 -> V_95 ;
unsigned long V_103 = ( ( V_89 -> V_81 - V_89 -> V_95 ) *
48 + V_91 / 2 ) / V_91 + 16 ;
if ( V_103 >= 32 )
V_103 &= ~ 1 ;
if ( F_10 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_56 , L_2 ,
F_5 ( V_9 , V_18 ) , V_103 ) ;
if ( F_7 ( V_9 , V_18 , V_103 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_96 :
if ( V_87 -> V_81 == V_104 ) {
V_12 = F_9 ( V_9 , V_17 , 0x1 ) ;
} else {
struct V_86 * exp = V_7 -> V_90 ;
unsigned long V_91 = exp -> V_94 - exp -> V_95 ;
unsigned long V_105 = ( ( exp -> V_81 - exp -> V_95 ) *
479 + V_91 / 2 ) / V_91 + 1 ;
V_12 = F_10 ( V_9 , V_17 , 0x1 ) ;
if ( V_12 < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_56 , L_3 ,
F_5 ( V_9 , V_19 ) ,
V_105 ) ;
if ( F_7 ( V_9 , V_19 ,
V_105 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_97 :
if ( F_7 ( V_9 , V_98 ,
V_87 -> V_81 ) < 0 )
return - V_29 ;
return 0 ;
case V_99 :
if ( F_7 ( V_9 , V_100 ,
V_87 -> V_81 ) < 0 )
return - V_29 ;
return 0 ;
}
return - V_73 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
T_3 V_12 ;
int V_13 ;
unsigned long V_106 ;
V_13 = F_30 ( & V_7 -> V_10 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_5 ( V_9 , V_107 ) ;
if ( V_12 != 0x1311 && V_12 != 0x1313 && V_12 != 0x1324 ) {
V_13 = - V_108 ;
F_36 ( & V_9 -> V_56 , L_4 ,
V_12 ) ;
goto V_109;
}
V_7 -> V_27 = V_12 ;
V_7 -> V_11 = F_16 ( V_12 ) ? & V_110 :
& V_111 ;
V_13 = F_7 ( V_9 , V_112 , 1 ) ;
if ( V_13 < 0 )
goto V_109;
F_37 ( 200 ) ;
if ( F_5 ( V_9 , V_112 ) ) {
F_38 ( & V_9 -> V_56 , L_5 ) ;
if ( V_13 > 0 )
V_13 = - V_29 ;
goto V_109;
}
if ( V_113 && ( ! strcmp ( L_6 , V_113 ) ||
! strcmp ( L_7 , V_113 ) ) ) {
V_13 = F_7 ( V_9 , V_114 , 4 | 0x11 ) ;
V_7 -> V_71 = V_76 ;
V_7 -> V_37 = V_38 ;
} else {
V_13 = F_7 ( V_9 , V_114 , 0x11 ) ;
V_7 -> V_71 = V_72 ;
V_7 -> V_37 = V_115 ;
}
if ( V_13 < 0 )
goto V_109;
V_7 -> V_77 = 0 ;
if ( V_84 -> V_116 )
V_106 = V_84 -> V_116 ( V_84 ) ;
else
V_106 = V_117 ;
if ( V_106 & V_117 )
V_7 -> V_77 ++ ;
else
V_7 -> V_37 ++ ;
if ( V_106 & V_118 )
V_7 -> V_77 ++ ;
V_7 -> V_4 = & V_7 -> V_37 [ 0 ] ;
F_36 ( & V_9 -> V_56 , L_8 ,
V_12 , V_7 -> V_71 == V_72 ?
L_9 : L_6 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 )
F_38 ( & V_9 -> V_56 , L_10 ) ;
V_109:
F_30 ( & V_7 -> V_10 , 0 ) ;
return V_13 ;
}
static int F_39 ( struct V_24 * V_25 , T_4 * V_119 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_119 = V_7 -> V_49 ;
return 0 ;
}
static int F_40 ( struct V_24 * V_25 , unsigned int V_120 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_120 >= V_7 -> V_77 )
return - V_73 ;
* V_3 = V_7 -> V_37 [ V_120 ] . V_3 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_121 * V_122 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
V_122 -> V_106 = V_123 | V_124 |
V_125 | V_126 |
V_127 | V_128 |
V_129 | V_130 |
V_131 ;
V_122 -> type = V_132 ;
V_122 -> V_106 = F_42 ( V_84 , V_122 ) ;
return 0 ;
}
static int F_43 ( struct V_24 * V_25 ,
const struct V_121 * V_122 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned long V_106 = F_42 ( V_84 , V_122 ) ;
unsigned int V_133 = F_44 ( V_7 -> V_4 -> V_3 ) -> V_134 ;
int V_13 ;
T_2 V_135 = 0 ;
if ( V_84 -> V_136 ) {
V_13 = V_84 -> V_136 ( V_84 , 1 << ( V_133 - 1 ) ) ;
if ( V_13 )
return V_13 ;
} else if ( V_133 != 10 ) {
return - V_73 ;
}
if ( V_106 & V_126 )
V_135 |= 0x10 ;
if ( ! ( V_106 & V_127 ) )
V_135 |= 0x1 ;
if ( ! ( V_106 & V_129 ) )
V_135 |= 0x2 ;
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_137 , V_135 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_106 & V_123 ) )
V_7 -> V_14 &= ~ 0x8 ;
V_13 = F_7 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_56 , L_11 ,
V_135 , V_7 -> V_14 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 ,
const struct V_138 * V_139 )
{
struct V_7 * V_7 ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
struct V_140 * V_141 = F_46 ( V_9 -> V_56 . V_142 ) ;
struct V_143 * V_144 ;
int V_13 ;
if ( ! V_84 ) {
F_38 ( & V_9 -> V_56 , L_12 ) ;
return - V_73 ;
}
if ( ! F_47 ( V_141 , V_145 ) ) {
F_48 ( & V_141 -> V_56 ,
L_13 ) ;
return - V_29 ;
}
V_7 = F_49 ( & V_9 -> V_56 , sizeof( struct V_7 ) , V_146 ) ;
if ( ! V_7 )
return - V_147 ;
V_144 = V_84 -> V_148 ;
F_50 ( & V_7 -> V_10 , V_9 , & V_149 ) ;
F_51 ( & V_7 -> V_23 , 6 ) ;
F_52 ( & V_7 -> V_23 , & V_150 ,
V_101 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_7 -> V_23 , & V_150 ,
V_102 , 0 , 1 , 1 , 0 ) ;
V_7 -> V_151 = F_52 ( & V_7 -> V_23 , & V_150 ,
V_93 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_89 = F_52 ( & V_7 -> V_23 , & V_150 ,
V_152 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_153 = F_53 ( & V_7 -> V_23 ,
& V_150 , V_96 , 1 , 0 ,
V_104 ) ;
V_7 -> V_90 = F_52 ( & V_7 -> V_23 , & V_150 ,
V_154 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_52 = F_52 ( & V_7 -> V_23 , & V_150 ,
V_97 , V_155 ,
V_156 , 1 ,
V_157 ) ;
V_7 -> V_53 = F_52 ( & V_7 -> V_23 , & V_150 ,
V_99 , V_158 ,
V_159 , 1 ,
V_160 ) ;
V_7 -> V_10 . V_161 = & V_7 -> V_23 ;
if ( V_7 -> V_23 . error ) {
int V_162 = V_7 -> V_23 . error ;
F_38 ( & V_9 -> V_56 , L_14 , V_162 ) ;
return V_162 ;
}
F_54 ( 2 , & V_7 -> V_153 ,
V_163 , true ) ;
F_54 ( 2 , & V_7 -> V_151 , 0 , true ) ;
V_7 -> V_14 = V_164 ;
V_7 -> V_49 = V_144 ? V_144 -> V_49 : 0 ;
V_7 -> V_33 . V_41 = V_42 ;
V_7 -> V_33 . V_45 = V_46 ;
V_7 -> V_33 . V_39 = V_44 ;
V_7 -> V_33 . V_40 = V_48 ;
V_7 -> V_85 = F_55 ( & V_9 -> V_56 , L_15 ) ;
if ( F_56 ( V_7 -> V_85 ) ) {
V_13 = F_57 ( V_7 -> V_85 ) ;
goto V_165;
}
V_13 = F_35 ( V_9 ) ;
if ( V_13 ) {
F_58 ( V_7 -> V_85 ) ;
V_165:
F_59 ( & V_7 -> V_23 ) ;
}
return V_13 ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_83 * V_84 = F_31 ( V_9 ) ;
F_58 ( V_7 -> V_85 ) ;
F_61 ( & V_7 -> V_10 ) ;
if ( V_84 -> V_166 )
V_84 -> V_166 ( V_84 ) ;
F_59 ( & V_7 -> V_23 ) ;
return 0 ;
}
