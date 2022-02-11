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
struct V_79 * V_80 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_80 -> V_81 . type != V_82 )
return - V_73 ;
if ( V_80 -> V_81 . V_83 != V_9 -> V_83 )
return - V_84 ;
V_80 -> V_85 = V_7 -> V_71 ;
V_80 -> V_86 = 0 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_87 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_81 . type != V_82 || V_11 -> V_11 > 0xff )
return - V_73 ;
if ( V_11 -> V_81 . V_83 != V_9 -> V_83 )
return - V_84 ;
V_11 -> V_88 = 2 ;
V_11 -> V_89 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_89 > 0xffff )
return - V_29 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
const struct V_87 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_81 . type != V_82 || V_11 -> V_11 > 0xff )
return - V_73 ;
if ( V_11 -> V_81 . V_83 != V_9 -> V_83 )
return - V_84 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_89 ) < 0 )
return - V_29 ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 , int V_90 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
return F_33 ( & V_9 -> V_56 , V_92 , V_90 ) ;
}
static int F_34 ( struct V_93 * V_94 )
{
struct V_7 * V_7 = F_3 ( V_94 -> V_95 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_93 * V_96 = V_7 -> V_96 ;
struct V_93 * exp = V_7 -> V_97 ;
unsigned long V_98 ;
int V_12 ;
switch ( V_94 -> V_80 ) {
case V_99 :
V_12 = F_5 ( V_9 , V_18 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_98 = V_96 -> V_100 - V_96 -> V_101 ;
V_96 -> V_89 = ( ( V_12 - 16 ) * V_98 + 24 ) / 48 + V_96 -> V_101 ;
return 0 ;
case V_102 :
V_12 = F_5 ( V_9 , V_19 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_98 = exp -> V_100 - exp -> V_101 ;
exp -> V_89 = ( ( V_12 - 1 ) * V_98 + 239 ) / 479 + exp -> V_101 ;
return 0 ;
case V_103 :
V_12 = F_5 ( V_9 , V_104 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_94 -> V_89 = V_12 ;
return 0 ;
case V_105 :
V_12 = F_5 ( V_9 , V_106 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_94 -> V_89 = V_12 ;
return 0 ;
}
return - V_73 ;
}
static int F_35 ( struct V_93 * V_94 )
{
struct V_7 * V_7 = F_3 ( V_94 -> V_95 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
int V_12 ;
switch ( V_94 -> V_80 ) {
case V_107 :
if ( V_94 -> V_89 )
V_12 = F_9 ( V_9 , V_16 , 0x10 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x10 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_108 :
if ( V_94 -> V_89 )
V_12 = F_9 ( V_9 , V_16 , 0x20 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x20 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_99 :
if ( V_94 -> V_89 ) {
if ( F_9 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
} else {
struct V_93 * V_96 = V_7 -> V_96 ;
unsigned long V_98 = V_96 -> V_100 - V_96 -> V_101 ;
unsigned long V_109 = ( ( V_96 -> V_89 - V_96 -> V_101 ) *
48 + V_98 / 2 ) / V_98 + 16 ;
if ( V_109 >= 32 )
V_109 &= ~ 1 ;
if ( F_10 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_56 , L_2 ,
F_5 ( V_9 , V_18 ) , V_109 ) ;
if ( F_7 ( V_9 , V_18 , V_109 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_102 :
if ( V_94 -> V_89 == V_110 ) {
V_12 = F_9 ( V_9 , V_17 , 0x1 ) ;
} else {
struct V_93 * exp = V_7 -> V_97 ;
unsigned long V_98 = exp -> V_100 - exp -> V_101 ;
unsigned long V_111 = ( ( exp -> V_89 - exp -> V_101 ) *
479 + V_98 / 2 ) / V_98 + 1 ;
V_12 = F_10 ( V_9 , V_17 , 0x1 ) ;
if ( V_12 < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_56 , L_3 ,
F_5 ( V_9 , V_19 ) ,
V_111 ) ;
if ( F_7 ( V_9 , V_19 ,
V_111 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_103 :
if ( F_7 ( V_9 , V_104 ,
V_94 -> V_89 ) < 0 )
return - V_29 ;
return 0 ;
case V_105 :
if ( F_7 ( V_9 , V_106 ,
V_94 -> V_89 ) < 0 )
return - V_29 ;
return 0 ;
}
return - V_73 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
T_3 V_12 ;
int V_13 ;
unsigned long V_112 ;
V_13 = F_31 ( & V_7 -> V_10 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_5 ( V_9 , V_113 ) ;
if ( V_12 != 0x1311 && V_12 != 0x1313 && V_12 != 0x1324 ) {
V_13 = - V_84 ;
F_37 ( & V_9 -> V_56 , L_4 ,
V_12 ) ;
goto V_114;
}
V_7 -> V_27 = V_12 ;
V_7 -> V_11 = F_16 ( V_12 ) ? & V_115 :
& V_116 ;
V_13 = F_7 ( V_9 , V_117 , 1 ) ;
if ( V_13 < 0 )
goto V_114;
F_38 ( 200 ) ;
if ( F_5 ( V_9 , V_117 ) ) {
F_39 ( & V_9 -> V_56 , L_5 ) ;
if ( V_13 > 0 )
V_13 = - V_29 ;
goto V_114;
}
if ( V_118 && ( ! strcmp ( L_6 , V_118 ) ||
! strcmp ( L_7 , V_118 ) ) ) {
V_13 = F_7 ( V_9 , V_119 , 4 | 0x11 ) ;
V_7 -> V_71 = V_76 ;
V_7 -> V_37 = V_38 ;
} else {
V_13 = F_7 ( V_9 , V_119 , 0x11 ) ;
V_7 -> V_71 = V_72 ;
V_7 -> V_37 = V_120 ;
}
if ( V_13 < 0 )
goto V_114;
V_7 -> V_77 = 0 ;
if ( V_92 -> V_121 )
V_112 = V_92 -> V_121 ( V_92 ) ;
else
V_112 = V_122 ;
if ( V_112 & V_122 )
V_7 -> V_77 ++ ;
else
V_7 -> V_37 ++ ;
if ( V_112 & V_123 )
V_7 -> V_77 ++ ;
V_7 -> V_4 = & V_7 -> V_37 [ 0 ] ;
F_37 ( & V_9 -> V_56 , L_8 ,
V_12 , V_7 -> V_71 == V_72 ?
L_9 : L_6 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 )
F_39 ( & V_9 -> V_56 , L_10 ) ;
V_114:
F_31 ( & V_7 -> V_10 , 0 ) ;
return V_13 ;
}
static int F_40 ( struct V_24 * V_25 , T_4 * V_124 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_124 = V_7 -> V_49 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 , unsigned int V_125 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_125 >= V_7 -> V_77 )
return - V_73 ;
* V_3 = V_7 -> V_37 [ V_125 ] . V_3 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_126 * V_127 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
V_127 -> V_112 = V_128 | V_129 |
V_130 | V_131 |
V_132 | V_133 |
V_134 | V_135 |
V_136 ;
V_127 -> type = V_137 ;
V_127 -> V_112 = F_43 ( V_92 , V_127 ) ;
return 0 ;
}
static int F_44 ( struct V_24 * V_25 ,
const struct V_126 * V_127 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned long V_112 = F_43 ( V_92 , V_127 ) ;
unsigned int V_138 = F_45 ( V_7 -> V_4 -> V_3 ) -> V_139 ;
int V_13 ;
T_2 V_140 = 0 ;
if ( V_92 -> V_141 ) {
V_13 = V_92 -> V_141 ( V_92 , 1 << ( V_138 - 1 ) ) ;
if ( V_13 )
return V_13 ;
} else if ( V_138 != 10 ) {
return - V_73 ;
}
if ( V_112 & V_131 )
V_140 |= 0x10 ;
if ( ! ( V_112 & V_132 ) )
V_140 |= 0x1 ;
if ( ! ( V_112 & V_134 ) )
V_140 |= 0x2 ;
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_142 , V_140 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_112 & V_128 ) )
V_7 -> V_14 &= ~ 0x8 ;
V_13 = F_7 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_56 , L_11 ,
V_140 , V_7 -> V_14 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 ,
const struct V_143 * V_144 )
{
struct V_7 * V_7 ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
struct V_145 * V_146 = F_47 ( V_9 -> V_56 . V_147 ) ;
struct V_148 * V_149 ;
int V_13 ;
if ( ! V_92 ) {
F_39 ( & V_9 -> V_56 , L_12 ) ;
return - V_73 ;
}
if ( ! F_48 ( V_146 , V_150 ) ) {
F_49 ( & V_146 -> V_56 ,
L_13 ) ;
return - V_29 ;
}
V_7 = F_50 ( & V_9 -> V_56 , sizeof( struct V_7 ) , V_151 ) ;
if ( ! V_7 )
return - V_152 ;
V_149 = V_92 -> V_153 ;
F_51 ( & V_7 -> V_10 , V_9 , & V_154 ) ;
F_52 ( & V_7 -> V_23 , 6 ) ;
F_53 ( & V_7 -> V_23 , & V_155 ,
V_107 , 0 , 1 , 1 , 0 ) ;
F_53 ( & V_7 -> V_23 , & V_155 ,
V_108 , 0 , 1 , 1 , 0 ) ;
V_7 -> V_156 = F_53 ( & V_7 -> V_23 , & V_155 ,
V_99 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_96 = F_53 ( & V_7 -> V_23 , & V_155 ,
V_157 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_158 = F_54 ( & V_7 -> V_23 ,
& V_155 , V_102 , 1 , 0 ,
V_110 ) ;
V_7 -> V_97 = F_53 ( & V_7 -> V_23 , & V_155 ,
V_159 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_52 = F_53 ( & V_7 -> V_23 , & V_155 ,
V_103 , V_160 ,
V_161 , 1 ,
V_162 ) ;
V_7 -> V_53 = F_53 ( & V_7 -> V_23 , & V_155 ,
V_105 , V_163 ,
V_164 , 1 ,
V_165 ) ;
V_7 -> V_10 . V_166 = & V_7 -> V_23 ;
if ( V_7 -> V_23 . error ) {
int V_167 = V_7 -> V_23 . error ;
F_39 ( & V_9 -> V_56 , L_14 , V_167 ) ;
return V_167 ;
}
F_55 ( 2 , & V_7 -> V_158 ,
V_168 , true ) ;
F_55 ( 2 , & V_7 -> V_156 , 0 , true ) ;
V_7 -> V_14 = V_169 ;
V_7 -> V_49 = V_149 ? V_149 -> V_49 : 0 ;
V_7 -> V_33 . V_41 = V_42 ;
V_7 -> V_33 . V_45 = V_46 ;
V_7 -> V_33 . V_39 = V_44 ;
V_7 -> V_33 . V_40 = V_48 ;
V_13 = F_36 ( V_9 ) ;
if ( V_13 )
F_56 ( & V_7 -> V_23 ) ;
return V_13 ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_91 * V_92 = F_32 ( V_9 ) ;
F_58 ( & V_7 -> V_10 ) ;
if ( V_92 -> V_170 )
V_92 -> V_170 ( V_92 ) ;
F_56 ( & V_7 -> V_23 ) ;
return 0 ;
}
