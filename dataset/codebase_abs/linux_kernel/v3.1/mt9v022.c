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
T_2 V_12 = F_6 ( V_9 , V_11 ) ;
return V_12 < 0 ? V_12 : F_7 ( V_12 ) ;
}
static int F_8 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
return F_9 ( V_9 , V_11 , F_7 ( V_12 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_9 , V_11 , V_13 | V_12 ) ;
}
static int F_11 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_9 , V_11 , V_13 & ~ V_12 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_13 ;
V_7 -> V_14 |= 0x10 ;
V_13 = F_8 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_16 , 0x300 ) ;
if ( ! V_13 )
V_13 = F_10 ( V_9 , V_17 , 0x3 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_18 , 16 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_19 , 480 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_20 , 480 ) ;
if ( ! V_13 )
V_13 = F_11 ( V_9 , V_21 , 1 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_22 , 0 ) ;
return V_13 ;
}
static int F_13 ( struct V_23 * V_24 , int V_25 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_25 )
V_7 -> V_14 &= ~ 0x10 ;
else
V_7 -> V_14 |= 0x10 ;
if ( F_8 ( V_9 , V_15 , V_7 -> V_14 ) < 0 )
return - V_26 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
unsigned long V_29 )
{
struct V_8 * V_9 = F_16 ( F_17 ( V_28 ) ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_30 * V_31 = F_18 ( V_28 ) ;
unsigned int V_32 = V_29 & V_33 ;
int V_13 ;
T_3 V_34 = 0 ;
if ( ! F_19 ( V_32 ) )
return - V_35 ;
if ( V_31 -> V_36 ) {
V_13 = V_31 -> V_36 ( V_31 , V_32 ) ;
if ( V_13 )
return V_13 ;
} else {
if ( V_32 != V_37 )
return - V_35 ;
}
V_29 = F_20 ( V_31 , V_29 ) ;
if ( V_29 & V_38 )
V_34 |= 0x10 ;
if ( ! ( V_29 & V_39 ) )
V_34 |= 0x1 ;
if ( ! ( V_29 & V_40 ) )
V_34 |= 0x2 ;
V_13 = F_8 ( V_9 , V_41 , V_34 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_29 & V_42 ) )
V_7 -> V_14 &= ~ 0x8 ;
V_13 = F_8 ( V_9 , V_15 , V_7 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_43 , L_1 ,
V_34 , V_7 -> V_14 ) ;
return 0 ;
}
static unsigned long F_22 ( struct V_27 * V_28 )
{
struct V_30 * V_31 = F_18 ( V_28 ) ;
unsigned int V_29 = V_42 | V_44 |
V_45 | V_38 |
V_39 | V_46 |
V_40 | V_47 |
V_48 ;
if ( V_31 -> V_49 )
V_29 |= V_31 -> V_49 ( V_31 ) & V_33 ;
else
V_29 |= V_37 ;
return F_20 ( V_31 , V_29 ) ;
}
static int F_23 ( struct V_23 * V_24 , struct V_50 * V_51 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_52 V_53 = V_51 -> V_54 ;
int V_13 ;
if ( V_7 -> V_55 == V_56 ) {
V_53 . V_57 = F_24 ( V_53 . V_57 , 2 ) ;
V_53 . V_58 = F_24 ( V_53 . V_58 , 2 ) ;
}
F_25 ( & V_53 . V_59 , & V_53 . V_57 ,
V_60 , V_61 , V_62 ) ;
F_25 ( & V_53 . V_63 , & V_53 . V_58 ,
V_64 , V_65 , V_66 ) ;
V_13 = F_5 ( V_9 , V_17 ) ;
if ( V_13 >= 0 ) {
if ( V_13 & 1 )
V_13 = F_8 ( V_9 , V_20 ,
V_53 . V_58 + V_7 -> V_67 + 43 ) ;
else
V_13 = F_8 ( V_9 , V_19 ,
V_53 . V_58 + V_7 -> V_67 + 43 ) ;
}
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_68 , V_53 . V_59 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_69 , V_53 . V_63 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_70 ,
V_53 . V_57 > 660 - 43 ? 43 :
660 - V_53 . V_57 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_71 , 45 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_72 , V_53 . V_57 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_73 ,
V_53 . V_58 + V_7 -> V_67 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_9 -> V_43 , L_2 , V_53 . V_57 , V_53 . V_58 ) ;
V_7 -> V_53 = V_53 ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 , struct V_50 * V_51 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_51 -> V_54 = V_7 -> V_53 ;
V_51 -> type = V_74 ;
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , struct V_75 * V_51 )
{
V_51 -> V_76 . V_59 = V_60 ;
V_51 -> V_76 . V_63 = V_64 ;
V_51 -> V_76 . V_57 = V_62 ;
V_51 -> V_76 . V_58 = V_66 ;
V_51 -> V_77 = V_51 -> V_76 ;
V_51 -> type = V_74 ;
V_51 -> V_78 . V_79 = 1 ;
V_51 -> V_78 . V_80 = 1 ;
return 0 ;
}
static int F_28 ( struct V_23 * V_24 ,
struct V_81 * V_82 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_82 -> V_57 = V_7 -> V_53 . V_57 ;
V_82 -> V_58 = V_7 -> V_53 . V_58 ;
V_82 -> V_3 = V_7 -> V_4 -> V_3 ;
V_82 -> V_83 = V_7 -> V_4 -> V_83 ;
V_82 -> V_84 = V_85 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 ,
struct V_81 * V_82 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_50 V_51 = {
. V_54 = {
. V_59 = V_7 -> V_53 . V_59 ,
. V_63 = V_7 -> V_53 . V_63 ,
. V_57 = V_82 -> V_57 ,
. V_58 = V_82 -> V_58 ,
} ,
} ;
int V_13 ;
switch ( V_82 -> V_3 ) {
case V_86 :
case V_87 :
if ( V_7 -> V_88 != V_89 )
return - V_35 ;
break;
case V_90 :
case V_91 :
if ( V_7 -> V_88 != V_92 )
return - V_35 ;
break;
default:
return - V_35 ;
}
V_13 = F_23 ( V_24 , & V_51 ) ;
if ( ! V_13 ) {
V_82 -> V_57 = V_7 -> V_53 . V_57 ;
V_82 -> V_58 = V_7 -> V_53 . V_58 ;
V_7 -> V_4 = F_1 ( V_82 -> V_3 ,
V_7 -> V_55 , V_7 -> V_93 ) ;
V_82 -> V_83 = V_7 -> V_4 -> V_83 ;
}
return V_13 ;
}
static int F_30 ( struct V_23 * V_24 ,
struct V_81 * V_82 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
int V_94 = V_82 -> V_3 == V_90 ||
V_82 -> V_3 == V_91 ;
F_31 ( & V_82 -> V_57 , V_61 ,
V_62 , V_94 ,
& V_82 -> V_58 , V_65 + V_7 -> V_67 ,
V_66 + V_7 -> V_67 , V_94 , 0 ) ;
V_4 = F_1 ( V_82 -> V_3 , V_7 -> V_55 ,
V_7 -> V_93 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_82 -> V_3 = V_4 -> V_3 ;
}
V_82 -> V_83 = V_4 -> V_83 ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 ,
struct V_95 * V_96 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_96 -> V_97 . type != V_98 )
return - V_35 ;
if ( V_96 -> V_97 . V_99 != V_9 -> V_99 )
return - V_100 ;
V_96 -> V_101 = V_7 -> V_88 ;
V_96 -> V_102 = 0 ;
return 0 ;
}
static int F_33 ( struct V_23 * V_24 ,
struct V_103 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
if ( V_11 -> V_97 . type != V_98 || V_11 -> V_11 > 0xff )
return - V_35 ;
if ( V_11 -> V_97 . V_99 != V_9 -> V_99 )
return - V_100 ;
V_11 -> V_104 = 2 ;
V_11 -> V_105 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_105 > 0xffff )
return - V_26 ;
return 0 ;
}
static int F_34 ( struct V_23 * V_24 ,
struct V_103 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
if ( V_11 -> V_97 . type != V_98 || V_11 -> V_11 > 0xff )
return - V_35 ;
if ( V_11 -> V_97 . V_99 != V_9 -> V_99 )
return - V_100 ;
if ( F_8 ( V_9 , V_11 -> V_11 , V_11 -> V_105 ) < 0 )
return - V_26 ;
return 0 ;
}
static int F_35 ( struct V_23 * V_24 , struct V_106 * V_107 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
const struct V_108 * V_109 ;
unsigned long V_110 ;
int V_12 ;
V_109 = F_36 ( & V_111 , V_107 -> V_96 ) ;
switch ( V_107 -> V_96 ) {
case V_112 :
V_12 = F_5 ( V_9 , V_16 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_107 -> V_113 = ! ! ( V_12 & 0x10 ) ;
break;
case V_114 :
V_12 = F_5 ( V_9 , V_16 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_107 -> V_113 = ! ! ( V_12 & 0x20 ) ;
break;
case V_115 :
V_12 = F_5 ( V_9 , V_17 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_107 -> V_113 = ! ! ( V_12 & 0x1 ) ;
break;
case V_116 :
V_12 = F_5 ( V_9 , V_17 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_107 -> V_113 = ! ! ( V_12 & 0x2 ) ;
break;
case V_117 :
V_12 = F_5 ( V_9 , V_18 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_110 = V_109 -> V_118 - V_109 -> V_119 ;
V_107 -> V_113 = ( ( V_12 - 16 ) * V_110 + 24 ) / 48 + V_109 -> V_119 ;
break;
case V_120 :
V_12 = F_5 ( V_9 , V_19 ) ;
if ( V_12 < 0 )
return - V_26 ;
V_110 = V_109 -> V_118 - V_109 -> V_119 ;
V_107 -> V_113 = ( ( V_12 - 1 ) * V_110 + 239 ) / 479 + V_109 -> V_119 ;
break;
}
return 0 ;
}
static int F_37 ( struct V_23 * V_24 , struct V_106 * V_107 )
{
int V_12 ;
struct V_8 * V_9 = F_14 ( V_24 ) ;
const struct V_108 * V_109 ;
V_109 = F_36 ( & V_111 , V_107 -> V_96 ) ;
if ( ! V_109 )
return - V_35 ;
switch ( V_107 -> V_96 ) {
case V_112 :
if ( V_107 -> V_113 )
V_12 = F_10 ( V_9 , V_16 , 0x10 ) ;
else
V_12 = F_11 ( V_9 , V_16 , 0x10 ) ;
if ( V_12 < 0 )
return - V_26 ;
break;
case V_114 :
if ( V_107 -> V_113 )
V_12 = F_10 ( V_9 , V_16 , 0x20 ) ;
else
V_12 = F_11 ( V_9 , V_16 , 0x20 ) ;
if ( V_12 < 0 )
return - V_26 ;
break;
case V_117 :
if ( V_107 -> V_113 > V_109 -> V_118 || V_107 -> V_113 < V_109 -> V_119 )
return - V_35 ;
else {
unsigned long V_110 = V_109 -> V_118 - V_109 -> V_119 ;
unsigned long V_121 = ( ( V_107 -> V_113 - V_109 -> V_119 ) *
48 + V_110 / 2 ) / V_110 + 16 ;
if ( V_121 >= 32 )
V_121 &= ~ 1 ;
if ( F_11 ( V_9 , V_17 , 0x2 ) < 0 )
return - V_26 ;
F_21 ( & V_9 -> V_43 , L_3 ,
F_5 ( V_9 , V_18 ) , V_121 ) ;
if ( F_8 ( V_9 , V_18 , V_121 ) < 0 )
return - V_26 ;
}
break;
case V_120 :
if ( V_107 -> V_113 > V_109 -> V_118 || V_107 -> V_113 < V_109 -> V_119 )
return - V_35 ;
else {
unsigned long V_110 = V_109 -> V_118 - V_109 -> V_119 ;
unsigned long V_122 = ( ( V_107 -> V_113 - V_109 -> V_119 ) *
479 + V_110 / 2 ) / V_110 + 1 ;
if ( F_11 ( V_9 , V_17 , 0x1 ) < 0 )
return - V_26 ;
F_21 ( & V_9 -> V_43 , L_4 ,
F_5 ( V_9 , V_19 ) ,
V_122 ) ;
if ( F_8 ( V_9 , V_19 ,
V_122 ) < 0 )
return - V_26 ;
}
break;
case V_116 :
if ( V_107 -> V_113 )
V_12 = F_10 ( V_9 , V_17 , 0x2 ) ;
else
V_12 = F_11 ( V_9 , V_17 , 0x2 ) ;
if ( V_12 < 0 )
return - V_26 ;
break;
case V_115 :
if ( V_107 -> V_113 )
V_12 = F_10 ( V_9 , V_17 , 0x1 ) ;
else
V_12 = F_11 ( V_9 , V_17 , 0x1 ) ;
if ( V_12 < 0 )
return - V_26 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_30 * V_31 = F_18 ( V_28 ) ;
T_2 V_12 ;
int V_13 ;
unsigned long V_29 ;
F_39 ( ! V_28 -> V_123 ||
F_40 ( V_28 -> V_123 ) -> V_124 != V_28 -> V_125 ) ;
V_12 = F_5 ( V_9 , V_126 ) ;
if ( V_12 != 0x1311 && V_12 != 0x1313 ) {
V_13 = - V_100 ;
F_41 ( & V_9 -> V_43 , L_5 ,
V_12 ) ;
goto V_127;
}
V_13 = F_8 ( V_9 , V_128 , 1 ) ;
if ( V_13 < 0 )
goto V_127;
F_42 ( 200 ) ;
if ( F_5 ( V_9 , V_128 ) ) {
F_43 ( & V_9 -> V_43 , L_6 ) ;
if ( V_13 > 0 )
V_13 = - V_26 ;
goto V_127;
}
if ( V_129 && ( ! strcmp ( L_7 , V_129 ) ||
! strcmp ( L_8 , V_129 ) ) ) {
V_13 = F_8 ( V_9 , V_130 , 4 | 0x11 ) ;
V_7 -> V_88 = V_92 ;
V_7 -> V_55 = V_56 ;
} else {
V_13 = F_8 ( V_9 , V_130 , 0x11 ) ;
V_7 -> V_88 = V_89 ;
V_7 -> V_55 = V_131 ;
}
if ( V_13 < 0 )
goto V_127;
V_7 -> V_93 = 0 ;
if ( V_31 -> V_49 )
V_29 = V_31 -> V_49 ( V_31 ) ;
else
V_29 = V_37 ;
if ( V_29 & V_37 )
V_7 -> V_93 ++ ;
else
V_7 -> V_55 ++ ;
if ( V_29 & V_132 )
V_7 -> V_93 ++ ;
V_7 -> V_4 = & V_7 -> V_55 [ 0 ] ;
F_41 ( & V_9 -> V_43 , L_9 ,
V_12 , V_7 -> V_88 == V_89 ?
L_10 : L_7 ) ;
V_13 = F_12 ( V_9 ) ;
if ( V_13 < 0 )
F_43 ( & V_9 -> V_43 , L_11 ) ;
V_127:
return V_13 ;
}
static void F_44 ( struct V_27 * V_28 )
{
struct V_30 * V_31 = F_18 ( V_28 ) ;
F_21 ( V_28 -> V_133 , L_12 ,
V_28 -> V_123 , V_28 -> V_134 ) ;
if ( V_31 -> V_135 )
V_31 -> V_135 ( V_31 ) ;
}
static int F_45 ( struct V_23 * V_24 , T_4 * V_136 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_136 = V_7 -> V_67 ;
return 0 ;
}
static int F_46 ( struct V_23 * V_24 , unsigned int V_137 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_137 >= V_7 -> V_93 )
return - V_35 ;
* V_3 = V_7 -> V_55 [ V_137 ] . V_3 ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 ,
const struct V_138 * V_139 )
{
struct V_7 * V_7 ;
struct V_27 * V_28 = V_9 -> V_43 . V_140 ;
struct V_141 * V_142 = F_48 ( V_9 -> V_43 . V_123 ) ;
struct V_30 * V_31 ;
int V_13 ;
if ( ! V_28 ) {
F_43 ( & V_9 -> V_43 , L_13 ) ;
return - V_35 ;
}
V_31 = F_18 ( V_28 ) ;
if ( ! V_31 ) {
F_43 ( & V_9 -> V_43 , L_14 ) ;
return - V_35 ;
}
if ( ! F_49 ( V_142 , V_143 ) ) {
F_50 ( & V_142 -> V_43 ,
L_15 ) ;
return - V_26 ;
}
V_7 = F_51 ( sizeof( struct V_7 ) , V_144 ) ;
if ( ! V_7 )
return - V_145 ;
F_52 ( & V_7 -> V_10 , V_9 , & V_146 ) ;
V_7 -> V_14 = V_147 ;
V_28 -> V_148 = & V_111 ;
V_7 -> V_67 = 1 ;
V_7 -> V_53 . V_59 = V_60 ;
V_7 -> V_53 . V_63 = V_64 ;
V_7 -> V_53 . V_57 = V_62 ;
V_7 -> V_53 . V_58 = V_66 ;
V_13 = F_38 ( V_28 , V_9 ) ;
if ( V_13 ) {
V_28 -> V_148 = NULL ;
F_53 ( V_7 ) ;
}
return V_13 ;
}
static int F_54 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_27 * V_28 = V_9 -> V_43 . V_140 ;
V_28 -> V_148 = NULL ;
F_44 ( V_28 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_149 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_149 ) ;
}
