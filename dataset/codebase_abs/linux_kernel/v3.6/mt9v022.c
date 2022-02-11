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
V_13 = F_7 ( V_9 , V_20 , 480 ) ;
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
if ( V_26 )
V_7 -> V_14 &= ~ 0x10 ;
else
V_7 -> V_14 |= 0x10 ;
if ( F_7 ( V_9 , V_15 , V_7 -> V_14 ) < 0 )
return - V_27 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 , struct V_28 * V_29 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_30 V_31 = V_29 -> V_32 ;
int V_13 ;
if ( V_7 -> V_33 == V_34 ) {
V_31 . V_35 = F_16 ( V_31 . V_35 , 2 ) ;
V_31 . V_36 = F_16 ( V_31 . V_36 , 2 ) ;
}
F_17 ( & V_31 . V_37 , & V_31 . V_35 ,
V_38 , V_39 , V_40 ) ;
F_17 ( & V_31 . V_41 , & V_31 . V_36 ,
V_42 , V_43 , V_44 ) ;
V_13 = F_5 ( V_9 , V_17 ) ;
if ( V_13 >= 0 ) {
if ( V_13 & 1 )
V_13 = F_7 ( V_9 , V_20 ,
V_31 . V_36 + V_7 -> V_45 + 43 ) ;
else
V_13 = F_7 ( V_9 , V_19 ,
V_31 . V_36 + V_7 -> V_45 + 43 ) ;
}
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_46 , V_31 . V_37 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_47 , V_31 . V_41 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_48 ,
V_31 . V_35 > 660 - 43 ? 43 :
660 - V_31 . V_35 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_49 , 45 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_50 , V_31 . V_35 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_51 ,
V_31 . V_36 + V_7 -> V_45 ) ;
if ( V_13 < 0 )
return V_13 ;
F_18 ( & V_9 -> V_52 , L_1 , V_31 . V_35 , V_31 . V_36 ) ;
V_7 -> V_31 = V_31 ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 , struct V_28 * V_29 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_29 -> V_32 = V_7 -> V_31 ;
V_29 -> type = V_53 ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 , struct V_54 * V_29 )
{
V_29 -> V_55 . V_37 = V_38 ;
V_29 -> V_55 . V_41 = V_42 ;
V_29 -> V_55 . V_35 = V_40 ;
V_29 -> V_55 . V_36 = V_44 ;
V_29 -> V_56 = V_29 -> V_55 ;
V_29 -> type = V_53 ;
V_29 -> V_57 . V_58 = 1 ;
V_29 -> V_57 . V_59 = 1 ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_60 * V_61 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_61 -> V_35 = V_7 -> V_31 . V_35 ;
V_61 -> V_36 = V_7 -> V_31 . V_36 ;
V_61 -> V_3 = V_7 -> V_4 -> V_3 ;
V_61 -> V_62 = V_7 -> V_4 -> V_62 ;
V_61 -> V_63 = V_64 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_60 * V_61 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_28 V_29 = {
. V_32 = {
. V_37 = V_7 -> V_31 . V_37 ,
. V_41 = V_7 -> V_31 . V_41 ,
. V_35 = V_61 -> V_35 ,
. V_36 = V_61 -> V_36 ,
} ,
} ;
int V_13 ;
switch ( V_61 -> V_3 ) {
case V_65 :
case V_66 :
if ( V_7 -> V_67 != V_68 )
return - V_69 ;
break;
case V_70 :
case V_71 :
if ( V_7 -> V_67 != V_72 )
return - V_69 ;
break;
default:
return - V_69 ;
}
V_13 = F_15 ( V_25 , & V_29 ) ;
if ( ! V_13 ) {
V_61 -> V_35 = V_7 -> V_31 . V_35 ;
V_61 -> V_36 = V_7 -> V_31 . V_36 ;
V_7 -> V_4 = F_1 ( V_61 -> V_3 ,
V_7 -> V_33 , V_7 -> V_73 ) ;
V_61 -> V_62 = V_7 -> V_4 -> V_62 ;
}
return V_13 ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_60 * V_61 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_74 = V_61 -> V_3 == V_70 ||
V_61 -> V_3 == V_71 ;
F_24 ( & V_61 -> V_35 , V_39 ,
V_40 , V_74 ,
& V_61 -> V_36 , V_43 + V_7 -> V_45 ,
V_44 + V_7 -> V_45 , V_74 , 0 ) ;
V_4 = F_1 ( V_61 -> V_3 , V_7 -> V_33 ,
V_7 -> V_73 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_61 -> V_3 = V_4 -> V_3 ;
}
V_61 -> V_62 = V_4 -> V_62 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_75 * V_76 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_76 -> V_77 . type != V_78 )
return - V_69 ;
if ( V_76 -> V_77 . V_79 != V_9 -> V_79 )
return - V_80 ;
V_76 -> V_81 = V_7 -> V_67 ;
V_76 -> V_82 = 0 ;
return 0 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_83 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_77 . type != V_78 || V_11 -> V_11 > 0xff )
return - V_69 ;
if ( V_11 -> V_77 . V_79 != V_9 -> V_79 )
return - V_80 ;
V_11 -> V_84 = 2 ;
V_11 -> V_85 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_85 > 0xffff )
return - V_27 ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
struct V_83 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
if ( V_11 -> V_77 . type != V_78 || V_11 -> V_11 > 0xff )
return - V_69 ;
if ( V_11 -> V_77 . V_79 != V_9 -> V_79 )
return - V_80 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_85 ) < 0 )
return - V_27 ;
return 0 ;
}
static int F_28 ( struct V_86 * V_87 )
{
struct V_7 * V_7 = F_3 ( V_87 -> V_88 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_86 * V_89 = V_7 -> V_89 ;
struct V_86 * exp = V_7 -> V_90 ;
unsigned long V_91 ;
int V_12 ;
switch ( V_87 -> V_76 ) {
case V_92 :
V_12 = F_5 ( V_9 , V_18 ) ;
if ( V_12 < 0 )
return - V_27 ;
V_91 = V_89 -> V_93 - V_89 -> V_94 ;
V_89 -> V_85 = ( ( V_12 - 16 ) * V_91 + 24 ) / 48 + V_89 -> V_94 ;
return 0 ;
case V_95 :
V_12 = F_5 ( V_9 , V_19 ) ;
if ( V_12 < 0 )
return - V_27 ;
V_91 = exp -> V_93 - exp -> V_94 ;
exp -> V_85 = ( ( V_12 - 1 ) * V_91 + 239 ) / 479 + exp -> V_94 ;
return 0 ;
}
return - V_69 ;
}
static int F_29 ( struct V_86 * V_87 )
{
struct V_7 * V_7 = F_3 ( V_87 -> V_88 ,
struct V_7 , V_23 ) ;
struct V_24 * V_25 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_25 ) ;
int V_12 ;
switch ( V_87 -> V_76 ) {
case V_96 :
if ( V_87 -> V_85 )
V_12 = F_9 ( V_9 , V_16 , 0x10 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x10 ) ;
if ( V_12 < 0 )
return - V_27 ;
return 0 ;
case V_97 :
if ( V_87 -> V_85 )
V_12 = F_9 ( V_9 , V_16 , 0x20 ) ;
else
V_12 = F_10 ( V_9 , V_16 , 0x20 ) ;
if ( V_12 < 0 )
return - V_27 ;
return 0 ;
case V_92 :
if ( V_87 -> V_85 ) {
if ( F_9 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_27 ;
} else {
struct V_86 * V_89 = V_7 -> V_89 ;
unsigned long V_91 = V_89 -> V_93 - V_89 -> V_94 ;
unsigned long V_98 = ( ( V_89 -> V_85 - V_89 -> V_94 ) *
48 + V_91 / 2 ) / V_91 + 16 ;
if ( V_98 >= 32 )
V_98 &= ~ 1 ;
if ( F_10 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_27 ;
F_18 ( & V_9 -> V_52 , L_2 ,
F_5 ( V_9 , V_18 ) , V_98 ) ;
if ( F_7 ( V_9 , V_18 , V_98 ) < 0 )
return - V_27 ;
}
return 0 ;
case V_95 :
if ( V_87 -> V_85 == V_99 ) {
V_12 = F_9 ( V_9 , V_17 , 0x1 ) ;
} else {
struct V_86 * exp = V_7 -> V_90 ;
unsigned long V_91 = exp -> V_93 - exp -> V_94 ;
unsigned long V_100 = ( ( exp -> V_85 - exp -> V_94 ) *
479 + V_91 / 2 ) / V_91 + 1 ;
V_12 = F_10 ( V_9 , V_17 , 0x1 ) ;
if ( V_12 < 0 )
return - V_27 ;
F_18 ( & V_9 -> V_52 , L_3 ,
F_5 ( V_9 , V_19 ) ,
V_100 ) ;
if ( F_7 ( V_9 , V_19 ,
V_100 ) < 0 )
return - V_27 ;
}
return 0 ;
}
return - V_69 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_101 * V_102 = F_31 ( V_9 ) ;
T_3 V_12 ;
int V_13 ;
unsigned long V_103 ;
V_12 = F_5 ( V_9 , V_104 ) ;
if ( V_12 != 0x1311 && V_12 != 0x1313 ) {
V_13 = - V_80 ;
F_32 ( & V_9 -> V_52 , L_4 ,
V_12 ) ;
goto V_105;
}
V_13 = F_7 ( V_9 , V_106 , 1 ) ;
if ( V_13 < 0 )
goto V_105;
F_33 ( 200 ) ;
if ( F_5 ( V_9 , V_106 ) ) {
F_34 ( & V_9 -> V_52 , L_5 ) ;
if ( V_13 > 0 )
V_13 = - V_27 ;
goto V_105;
}
if ( V_107 && ( ! strcmp ( L_6 , V_107 ) ||
! strcmp ( L_7 , V_107 ) ) ) {
V_13 = F_7 ( V_9 , V_108 , 4 | 0x11 ) ;
V_7 -> V_67 = V_72 ;
V_7 -> V_33 = V_34 ;
} else {
V_13 = F_7 ( V_9 , V_108 , 0x11 ) ;
V_7 -> V_67 = V_68 ;
V_7 -> V_33 = V_109 ;
}
if ( V_13 < 0 )
goto V_105;
V_7 -> V_73 = 0 ;
if ( V_102 -> V_110 )
V_103 = V_102 -> V_110 ( V_102 ) ;
else
V_103 = V_111 ;
if ( V_103 & V_111 )
V_7 -> V_73 ++ ;
else
V_7 -> V_33 ++ ;
if ( V_103 & V_112 )
V_7 -> V_73 ++ ;
V_7 -> V_4 = & V_7 -> V_33 [ 0 ] ;
F_32 ( & V_9 -> V_52 , L_8 ,
V_12 , V_7 -> V_67 == V_68 ?
L_9 : L_6 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 )
F_34 ( & V_9 -> V_52 , L_10 ) ;
V_105:
return V_13 ;
}
static int F_35 ( struct V_24 * V_25 , T_4 * V_113 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_113 = V_7 -> V_45 ;
return 0 ;
}
static int F_36 ( struct V_24 * V_25 , unsigned int V_114 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_114 >= V_7 -> V_73 )
return - V_69 ;
* V_3 = V_7 -> V_33 [ V_114 ] . V_3 ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_115 * V_116 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_101 * V_102 = F_31 ( V_9 ) ;
V_116 -> V_103 = V_117 | V_118 |
V_119 | V_120 |
V_121 | V_122 |
V_123 | V_124 |
V_125 ;
V_116 -> type = V_126 ;
V_116 -> V_103 = F_38 ( V_102 , V_116 ) ;
return 0 ;
}
static int F_39 ( struct V_24 * V_25 ,
const struct V_115 * V_116 )
{
struct V_8 * V_9 = F_14 ( V_25 ) ;
struct V_101 * V_102 = F_31 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned long V_103 = F_38 ( V_102 , V_116 ) ;
unsigned int V_127 = F_40 ( V_7 -> V_4 -> V_3 ) -> V_128 ;
int V_13 ;
T_2 V_129 = 0 ;
if ( V_102 -> V_130 ) {
V_13 = V_102 -> V_130 ( V_102 , 1 << ( V_127 - 1 ) ) ;
if ( V_13 )
return V_13 ;
} else if ( V_127 != 10 ) {
return - V_69 ;
}
if ( V_103 & V_120 )
V_129 |= 0x10 ;
if ( ! ( V_103 & V_121 ) )
V_129 |= 0x1 ;
if ( ! ( V_103 & V_123 ) )
V_129 |= 0x2 ;
V_13 = F_7 ( V_9 , V_131 , V_129 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_103 & V_117 ) )
V_7 -> V_14 &= ~ 0x8 ;
V_13 = F_7 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_18 ( & V_9 -> V_52 , L_11 ,
V_129 , V_7 -> V_14 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_132 * V_133 )
{
struct V_7 * V_7 ;
struct V_101 * V_102 = F_31 ( V_9 ) ;
struct V_134 * V_135 = F_42 ( V_9 -> V_52 . V_136 ) ;
int V_13 ;
if ( ! V_102 ) {
F_34 ( & V_9 -> V_52 , L_12 ) ;
return - V_69 ;
}
if ( ! F_43 ( V_135 , V_137 ) ) {
F_44 ( & V_135 -> V_52 ,
L_13 ) ;
return - V_27 ;
}
V_7 = F_45 ( sizeof( struct V_7 ) , V_138 ) ;
if ( ! V_7 )
return - V_139 ;
F_46 ( & V_7 -> V_10 , V_9 , & V_140 ) ;
F_47 ( & V_7 -> V_23 , 6 ) ;
F_48 ( & V_7 -> V_23 , & V_141 ,
V_96 , 0 , 1 , 1 , 0 ) ;
F_48 ( & V_7 -> V_23 , & V_141 ,
V_97 , 0 , 1 , 1 , 0 ) ;
V_7 -> V_142 = F_48 ( & V_7 -> V_23 , & V_141 ,
V_92 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_89 = F_48 ( & V_7 -> V_23 , & V_141 ,
V_143 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_144 = F_49 ( & V_7 -> V_23 ,
& V_141 , V_95 , 1 , 0 ,
V_99 ) ;
V_7 -> V_90 = F_48 ( & V_7 -> V_23 , & V_141 ,
V_145 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_10 . V_146 = & V_7 -> V_23 ;
if ( V_7 -> V_23 . error ) {
int V_147 = V_7 -> V_23 . error ;
F_50 ( V_7 ) ;
return V_147 ;
}
F_51 ( 2 , & V_7 -> V_144 ,
V_148 , true ) ;
F_51 ( 2 , & V_7 -> V_142 , 0 , true ) ;
V_7 -> V_14 = V_149 ;
V_7 -> V_45 = 1 ;
V_7 -> V_31 . V_37 = V_38 ;
V_7 -> V_31 . V_41 = V_42 ;
V_7 -> V_31 . V_35 = V_40 ;
V_7 -> V_31 . V_36 = V_44 ;
V_13 = F_30 ( V_9 ) ;
if ( V_13 ) {
F_52 ( & V_7 -> V_23 ) ;
F_50 ( V_7 ) ;
}
return V_13 ;
}
static int F_53 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_101 * V_102 = F_31 ( V_9 ) ;
F_54 ( & V_7 -> V_10 ) ;
if ( V_102 -> V_150 )
V_102 -> V_150 ( V_102 ) ;
F_52 ( & V_7 -> V_23 ) ;
F_50 ( V_7 ) ;
return 0 ;
}
