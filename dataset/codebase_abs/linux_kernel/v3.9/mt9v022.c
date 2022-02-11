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
int V_13 ;
if ( V_7 -> V_35 == V_36 ) {
V_33 . V_37 = F_18 ( V_33 . V_37 , 2 ) ;
V_33 . V_38 = F_18 ( V_33 . V_38 , 2 ) ;
}
F_19 ( & V_33 . V_39 , & V_33 . V_37 ,
V_40 , V_41 , V_42 ) ;
F_19 ( & V_33 . V_43 , & V_33 . V_38 ,
V_44 , V_45 , V_46 ) ;
V_13 = F_5 ( V_9 , V_17 ) ;
if ( V_13 >= 0 ) {
if ( V_13 & 1 )
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_20 ,
V_33 . V_38 + V_7 -> V_47 + 43 ) ;
}
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_48 , V_33 . V_39 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_49 , V_33 . V_43 ) ;
if ( ! V_13 )
V_13 = F_20 ( V_7 -> V_50 ,
V_33 . V_37 > 660 - 43 ? 43 : 660 - V_33 . V_37 ) ;
if ( ! V_13 )
V_13 = F_20 ( V_7 -> V_51 , 45 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_52 , V_33 . V_37 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_53 ,
V_33 . V_38 + V_7 -> V_47 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_54 , L_1 , V_33 . V_37 , V_33 . V_38 ) ;
V_7 -> V_33 = V_33 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , struct V_30 * V_31 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_31 -> V_34 = V_7 -> V_33 ;
V_31 -> type = V_55 ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 , struct V_56 * V_31 )
{
V_31 -> V_57 . V_39 = V_40 ;
V_31 -> V_57 . V_43 = V_44 ;
V_31 -> V_57 . V_37 = V_42 ;
V_31 -> V_57 . V_38 = V_46 ;
V_31 -> V_58 = V_31 -> V_57 ;
V_31 -> type = V_55 ;
V_31 -> V_59 . V_60 = 1 ;
V_31 -> V_59 . V_61 = 1 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_63 -> V_37 = V_7 -> V_33 . V_37 ;
V_63 -> V_38 = V_7 -> V_33 . V_38 ;
V_63 -> V_3 = V_7 -> V_4 -> V_3 ;
V_63 -> V_64 = V_7 -> V_4 -> V_64 ;
V_63 -> V_65 = V_66 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_30 V_31 = {
. V_34 = {
. V_39 = V_7 -> V_33 . V_39 ,
. V_43 = V_7 -> V_33 . V_43 ,
. V_37 = V_63 -> V_37 ,
. V_38 = V_63 -> V_38 ,
} ,
} ;
int V_13 ;
switch ( V_63 -> V_3 ) {
case V_67 :
case V_68 :
if ( V_7 -> V_69 != V_70 )
return - V_71 ;
break;
case V_72 :
case V_73 :
if ( V_7 -> V_69 != V_74 )
return - V_71 ;
break;
default:
return - V_71 ;
}
V_13 = F_17 ( V_25 , & V_31 ) ;
if ( ! V_13 ) {
V_63 -> V_37 = V_7 -> V_33 . V_37 ;
V_63 -> V_38 = V_7 -> V_33 . V_38 ;
V_7 -> V_4 = F_1 ( V_63 -> V_3 ,
V_7 -> V_35 , V_7 -> V_75 ) ;
V_63 -> V_64 = V_7 -> V_4 -> V_64 ;
}
return V_13 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_76 = V_63 -> V_3 == V_72 ||
V_63 -> V_3 == V_73 ;
F_27 ( & V_63 -> V_37 , V_41 ,
V_42 , V_76 ,
& V_63 -> V_38 , V_45 + V_7 -> V_47 ,
V_46 + V_7 -> V_47 , V_76 , 0 ) ;
V_4 = F_1 ( V_63 -> V_3 , V_7 -> V_35 ,
V_7 -> V_75 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_63 -> V_3 = V_4 -> V_3 ;
}
V_63 -> V_64 = V_4 -> V_64 ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_77 * V_78 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_78 -> V_79 . type != V_80 )
return - V_71 ;
if ( V_78 -> V_79 . V_81 != V_9 -> V_81 )
return - V_82 ;
V_78 -> V_83 = V_7 -> V_69 ;
V_78 -> V_84 = 0 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_85 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_79 . type != V_80 || V_11 -> V_11 > 0xff )
return - V_71 ;
if ( V_11 -> V_79 . V_81 != V_9 -> V_81 )
return - V_82 ;
V_11 -> V_86 = 2 ;
V_11 -> V_87 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_87 > 0xffff )
return - V_29 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_85 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_79 . type != V_80 || V_11 -> V_11 > 0xff )
return - V_71 ;
if ( V_11 -> V_79 . V_81 != V_9 -> V_81 )
return - V_82 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_87 ) < 0 )
return - V_29 ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 , int V_88 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
return F_33 ( & V_9 -> V_54 , V_90 , V_88 ) ;
}
static int F_34 ( struct V_91 * V_92 )
{
struct V_7 * V_7 = F_3 ( V_92 -> V_93 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_91 * V_94 = V_7 -> V_94 ;
struct V_91 * exp = V_7 -> V_95 ;
unsigned long V_96 ;
int V_12 ;
switch ( V_92 -> V_78 ) {
case V_97 :
V_12 = F_5 ( V_9 , V_18 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_96 = V_94 -> V_98 - V_94 -> V_99 ;
V_94 -> V_87 = ( ( V_12 - 16 ) * V_96 + 24 ) / 48 + V_94 -> V_99 ;
return 0 ;
case V_100 :
V_12 = F_5 ( V_9 , V_19 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_96 = exp -> V_98 - exp -> V_99 ;
exp -> V_87 = ( ( V_12 - 1 ) * V_96 + 239 ) / 479 + exp -> V_99 ;
return 0 ;
case V_101 :
V_12 = F_5 ( V_9 , V_102 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_92 -> V_87 = V_12 ;
return 0 ;
case V_103 :
V_12 = F_5 ( V_9 , V_104 ) ;
if ( V_12 < 0 )
return - V_29 ;
V_92 -> V_87 = V_12 ;
return 0 ;
}
return - V_71 ;
}
static int F_35 ( struct V_91 * V_92 )
{
struct V_7 * V_7 = F_3 ( V_92 -> V_93 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
int V_12 ;
switch ( V_92 -> V_78 ) {
case V_105 :
if ( V_92 -> V_87 )
V_12 = F_9 ( V_9 , V_16 , 0x10 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x10 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_106 :
if ( V_92 -> V_87 )
V_12 = F_9 ( V_9 , V_16 , 0x20 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x20 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
case V_97 :
if ( V_92 -> V_87 ) {
if ( F_9 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
} else {
struct V_91 * V_94 = V_7 -> V_94 ;
unsigned long V_96 = V_94 -> V_98 - V_94 -> V_99 ;
unsigned long V_107 = ( ( V_94 -> V_87 - V_94 -> V_99 ) *
48 + V_96 / 2 ) / V_96 + 16 ;
if ( V_107 >= 32 )
V_107 &= ~ 1 ;
if ( F_10 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_54 , L_2 ,
F_5 ( V_9 , V_18 ) , V_107 ) ;
if ( F_7 ( V_9 , V_18 , V_107 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_100 :
if ( V_92 -> V_87 == V_108 ) {
V_12 = F_9 ( V_9 , V_17 , 0x1 ) ;
} else {
struct V_91 * exp = V_7 -> V_95 ;
unsigned long V_96 = exp -> V_98 - exp -> V_99 ;
unsigned long V_109 = ( ( exp -> V_87 - exp -> V_99 ) *
479 + V_96 / 2 ) / V_96 + 1 ;
V_12 = F_10 ( V_9 , V_17 , 0x1 ) ;
if ( V_12 < 0 )
return - V_29 ;
F_21 ( & V_9 -> V_54 , L_3 ,
F_5 ( V_9 , V_19 ) ,
V_109 ) ;
if ( F_7 ( V_9 , V_19 ,
V_109 ) < 0 )
return - V_29 ;
}
return 0 ;
case V_101 :
if ( F_7 ( V_9 , V_102 ,
V_92 -> V_87 ) < 0 )
return - V_29 ;
return 0 ;
case V_103 :
if ( F_7 ( V_9 , V_104 ,
V_92 -> V_87 ) < 0 )
return - V_29 ;
return 0 ;
}
return - V_71 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
T_3 V_12 ;
int V_13 ;
unsigned long V_110 ;
V_13 = F_31 ( & V_7 -> V_10 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_5 ( V_9 , V_111 ) ;
if ( V_12 != 0x1311 && V_12 != 0x1313 && V_12 != 0x1324 ) {
V_13 = - V_82 ;
F_37 ( & V_9 -> V_54 , L_4 ,
V_12 ) ;
goto V_112;
}
V_7 -> V_27 = V_12 ;
V_7 -> V_11 = F_16 ( V_12 ) ? & V_113 :
& V_114 ;
V_13 = F_7 ( V_9 , V_115 , 1 ) ;
if ( V_13 < 0 )
goto V_112;
F_38 ( 200 ) ;
if ( F_5 ( V_9 , V_115 ) ) {
F_39 ( & V_9 -> V_54 , L_5 ) ;
if ( V_13 > 0 )
V_13 = - V_29 ;
goto V_112;
}
if ( V_116 && ( ! strcmp ( L_6 , V_116 ) ||
! strcmp ( L_7 , V_116 ) ) ) {
V_13 = F_7 ( V_9 , V_117 , 4 | 0x11 ) ;
V_7 -> V_69 = V_74 ;
V_7 -> V_35 = V_36 ;
} else {
V_13 = F_7 ( V_9 , V_117 , 0x11 ) ;
V_7 -> V_69 = V_70 ;
V_7 -> V_35 = V_118 ;
}
if ( V_13 < 0 )
goto V_112;
V_7 -> V_75 = 0 ;
if ( V_90 -> V_119 )
V_110 = V_90 -> V_119 ( V_90 ) ;
else
V_110 = V_120 ;
if ( V_110 & V_120 )
V_7 -> V_75 ++ ;
else
V_7 -> V_35 ++ ;
if ( V_110 & V_121 )
V_7 -> V_75 ++ ;
V_7 -> V_4 = & V_7 -> V_35 [ 0 ] ;
F_37 ( & V_9 -> V_54 , L_8 ,
V_12 , V_7 -> V_69 == V_70 ?
L_9 : L_6 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 )
F_39 ( & V_9 -> V_54 , L_10 ) ;
V_112:
F_31 ( & V_7 -> V_10 , 0 ) ;
return V_13 ;
}
static int F_40 ( struct V_24 * V_25 , T_4 * V_122 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_122 = V_7 -> V_47 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 , unsigned int V_123 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_123 >= V_7 -> V_75 )
return - V_71 ;
* V_3 = V_7 -> V_35 [ V_123 ] . V_3 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_124 * V_125 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
V_125 -> V_110 = V_126 | V_127 |
V_128 | V_129 |
V_130 | V_131 |
V_132 | V_133 |
V_134 ;
V_125 -> type = V_135 ;
V_125 -> V_110 = F_43 ( V_90 , V_125 ) ;
return 0 ;
}
static int F_44 ( struct V_24 * V_25 ,
const struct V_124 * V_125 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned long V_110 = F_43 ( V_90 , V_125 ) ;
unsigned int V_136 = F_45 ( V_7 -> V_4 -> V_3 ) -> V_137 ;
int V_13 ;
T_2 V_138 = 0 ;
if ( V_90 -> V_139 ) {
V_13 = V_90 -> V_139 ( V_90 , 1 << ( V_136 - 1 ) ) ;
if ( V_13 )
return V_13 ;
} else if ( V_136 != 10 ) {
return - V_71 ;
}
if ( V_110 & V_129 )
V_138 |= 0x10 ;
if ( ! ( V_110 & V_130 ) )
V_138 |= 0x1 ;
if ( ! ( V_110 & V_132 ) )
V_138 |= 0x2 ;
V_13 = F_7 ( V_9 , V_7 -> V_11 -> V_140 , V_138 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_110 & V_126 ) )
V_7 -> V_14 &= ~ 0x8 ;
V_13 = F_7 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_54 , L_11 ,
V_138 , V_7 -> V_14 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 ,
const struct V_141 * V_142 )
{
struct V_7 * V_7 ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
struct V_143 * V_144 = F_47 ( V_9 -> V_54 . V_145 ) ;
struct V_146 * V_147 ;
int V_13 ;
if ( ! V_90 ) {
F_39 ( & V_9 -> V_54 , L_12 ) ;
return - V_71 ;
}
if ( ! F_48 ( V_144 , V_148 ) ) {
F_49 ( & V_144 -> V_54 ,
L_13 ) ;
return - V_29 ;
}
V_7 = F_50 ( & V_9 -> V_54 , sizeof( struct V_7 ) , V_149 ) ;
if ( ! V_7 )
return - V_150 ;
V_147 = V_90 -> V_151 ;
F_51 ( & V_7 -> V_10 , V_9 , & V_152 ) ;
F_52 ( & V_7 -> V_23 , 6 ) ;
F_53 ( & V_7 -> V_23 , & V_153 ,
V_105 , 0 , 1 , 1 , 0 ) ;
F_53 ( & V_7 -> V_23 , & V_153 ,
V_106 , 0 , 1 , 1 , 0 ) ;
V_7 -> V_154 = F_53 ( & V_7 -> V_23 , & V_153 ,
V_97 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_94 = F_53 ( & V_7 -> V_23 , & V_153 ,
V_155 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_156 = F_54 ( & V_7 -> V_23 ,
& V_153 , V_100 , 1 , 0 ,
V_108 ) ;
V_7 -> V_95 = F_53 ( & V_7 -> V_23 , & V_153 ,
V_157 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_50 = F_53 ( & V_7 -> V_23 , & V_153 ,
V_101 , V_158 ,
V_159 , 1 ,
V_160 ) ;
V_7 -> V_51 = F_53 ( & V_7 -> V_23 , & V_153 ,
V_103 , V_161 ,
V_162 , 1 ,
V_163 ) ;
V_7 -> V_10 . V_164 = & V_7 -> V_23 ;
if ( V_7 -> V_23 . error ) {
int V_165 = V_7 -> V_23 . error ;
F_39 ( & V_9 -> V_54 , L_14 , V_165 ) ;
return V_165 ;
}
F_55 ( 2 , & V_7 -> V_156 ,
V_166 , true ) ;
F_55 ( 2 , & V_7 -> V_154 , 0 , true ) ;
V_7 -> V_14 = V_167 ;
V_7 -> V_47 = V_147 ? V_147 -> V_47 : 0 ;
V_7 -> V_33 . V_39 = V_40 ;
V_7 -> V_33 . V_43 = V_44 ;
V_7 -> V_33 . V_37 = V_42 ;
V_7 -> V_33 . V_38 = V_46 ;
V_13 = F_36 ( V_9 ) ;
if ( V_13 )
F_56 ( & V_7 -> V_23 ) ;
return V_13 ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_89 * V_90 = F_32 ( V_9 ) ;
F_58 ( & V_7 -> V_10 ) ;
if ( V_90 -> V_168 )
V_90 -> V_168 ( V_90 ) ;
F_56 ( & V_7 -> V_23 ) ;
return 0 ;
}
