T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
T_1 V_6 = V_7 ;
V_5 = F_2 ( V_4 -> V_8 + V_9 ) ;
if ( ! V_5 )
return V_7 ;
if ( V_5 & V_10 ) {
F_3 ( & V_4 -> V_11 . V_12 ) ;
V_6 = V_13 ;
}
F_4 ( V_5 , V_4 -> V_8 + V_14 ) ;
return V_6 ;
}
static int F_5 ( struct V_15 * V_11 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
const struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 = V_11 -> V_24 . V_25 -> V_26 ;
struct V_22 * V_26 = V_17 -> V_26 ;
if ( V_21 -> V_27 % 16 )
return - V_28 ;
if ( V_26 ) {
T_2 V_29 = F_6 ( V_26 , V_17 , 0 ) ;
if ( V_29 & 3 )
return - V_28 ;
if ( V_26 -> V_30 [ 0 ] != V_21 -> V_27 * V_26 -> V_31 -> V_32 [ 0 ] )
return - V_28 ;
if ( V_23 && V_23 -> V_31 != V_26 -> V_31 )
V_19 -> V_33 = true ;
}
return 0 ;
}
static void F_7 ( struct V_15 * V_11 ,
struct V_18 * V_19 )
{
struct V_34 * V_12 = & V_11 -> V_12 ;
struct V_35 * V_24 = & V_11 -> V_24 ;
struct V_36 * V_37 = V_12 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_39 ;
const struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_26 = V_24 -> V_25 -> V_26 ;
struct V_40 * V_41 = & V_4 -> V_41 . V_41 ;
T_2 V_42 ;
T_2 V_43 , V_44 , V_45 , V_46 ;
T_2 V_47 , V_48 , V_49 , V_50 ;
T_2 V_51 , V_52 ;
int V_53 ;
V_53 = F_8 ( V_4 -> V_54 , V_21 -> clock * 1000 ) ;
if ( V_53 ) {
F_9 ( V_37 -> V_38 ,
L_1 ,
V_21 -> clock * 1000 , V_53 ) ;
}
F_10 ( V_4 -> V_54 ) ;
V_43 = ( V_21 -> V_27 / 16 ) - 1 ;
V_44 = V_21 -> V_55 - V_21 -> V_56 - 1 ;
V_45 = V_21 -> V_56 - V_21 -> V_27 - 1 ;
V_46 = V_21 -> V_57 - V_21 -> V_55 - 1 ;
V_47 = V_21 -> V_58 - 1 ;
V_48 = V_21 -> V_59 - V_21 -> V_60 - 1 ;
V_49 = V_21 -> V_60 - V_21 -> V_58 ;
V_50 = V_21 -> V_61 - V_21 -> V_59 ;
V_51 = V_21 -> V_27 - 1 ;
F_4 ( ( V_43 << 2 ) |
( V_44 << 8 ) |
( V_45 << 16 ) |
( V_46 << 24 ) ,
V_4 -> V_8 + V_62 ) ;
F_4 ( V_47 |
( V_48 << 10 ) |
( V_49 << 16 ) |
( V_50 << 24 ) ,
V_4 -> V_8 + V_63 ) ;
F_11 ( & V_4 -> V_64 ) ;
V_52 = F_2 ( V_4 -> V_8 + V_65 ) ;
V_52 &= ( V_66 | V_67 | V_68 ) ;
if ( V_21 -> V_69 & V_70 )
V_52 |= V_71 ;
if ( V_21 -> V_69 & V_72 )
V_52 |= V_73 ;
if ( V_41 -> V_74 . V_75 & V_76 )
V_52 |= V_77 ;
if ( V_41 -> V_74 . V_75 & V_78 )
V_52 |= V_79 ;
V_52 |= V_51 << 16 ;
F_4 ( V_52 , V_4 -> V_8 + V_65 ) ;
F_12 ( & V_4 -> V_64 ) ;
F_4 ( 0 , V_4 -> V_8 + V_80 ) ;
F_13 ( V_4 -> V_41 . V_81 ) ;
V_42 = V_82 | V_83 | V_84 | F_14 ( 1 ) ;
switch ( V_26 -> V_31 -> V_31 ) {
case V_85 :
case V_86 :
V_42 |= V_87 ;
break;
case V_88 :
case V_89 :
V_42 |= V_87 | V_90 ;
break;
case V_91 :
V_42 |= V_92 ;
break;
case V_93 :
V_42 |= V_92 | V_90 ;
break;
case V_94 :
case V_95 :
V_42 |= V_96 ;
break;
case V_97 :
case V_98 :
V_42 |= V_96 | V_90 ;
break;
case V_99 :
case V_100 :
V_42 |= V_101 ;
break;
case V_102 :
case V_103 :
V_42 |= V_101 | V_90 ;
break;
default:
F_15 ( true , L_2 ,
V_26 -> V_31 -> V_31 ) ;
break;
}
F_4 ( V_42 , V_4 -> V_8 + V_104 ) ;
F_16 ( V_4 -> V_41 . V_81 ) ;
F_17 ( V_12 ) ;
}
void F_18 ( struct V_15 * V_11 )
{
struct V_34 * V_12 = & V_11 -> V_12 ;
struct V_36 * V_37 = V_12 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_39 ;
F_19 ( V_12 ) ;
F_20 ( V_4 -> V_41 . V_81 ) ;
F_4 ( 0 , V_4 -> V_8 + V_104 ) ;
F_21 ( V_4 -> V_41 . V_81 ) ;
F_22 ( V_4 -> V_54 ) ;
}
static void F_23 ( struct V_15 * V_11 ,
struct V_16 * V_105 )
{
struct V_34 * V_12 = & V_11 -> V_12 ;
struct V_36 * V_37 = V_12 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_39 ;
struct V_106 * V_107 = V_12 -> V_25 -> V_107 ;
struct V_35 * V_24 = & V_11 -> V_24 ;
struct V_16 * V_17 = V_24 -> V_25 ;
struct V_22 * V_26 = V_17 -> V_26 ;
if ( V_26 ) {
T_2 V_108 = F_6 ( V_26 , V_17 , 0 ) ;
F_4 ( V_108 , V_4 -> V_8 + V_109 ) ;
}
if ( V_107 ) {
V_12 -> V_25 -> V_107 = NULL ;
F_24 ( & V_12 -> V_38 -> V_110 ) ;
if ( V_12 -> V_25 -> V_111 && F_25 ( V_12 ) == 0 )
F_26 ( V_12 , V_107 ) ;
else
F_27 ( V_12 , V_107 ) ;
F_28 ( & V_12 -> V_38 -> V_110 ) ;
}
}
int F_29 ( struct V_36 * V_37 , unsigned int V_12 )
{
struct V_3 * V_4 = V_37 -> V_39 ;
F_4 ( V_10 , V_4 -> V_8 + V_112 ) ;
return 0 ;
}
void F_30 ( struct V_36 * V_37 , unsigned int V_12 )
{
struct V_3 * V_4 = V_37 -> V_39 ;
F_4 ( 0 , V_4 -> V_8 + V_112 ) ;
}
static int F_31 ( struct V_15 * V_11 ,
struct V_16 * V_113 )
{
return F_32 ( & V_11 -> V_24 , V_113 ) ;
}
static int F_33 ( struct V_114 * V_115 , unsigned long V_116 ,
unsigned long * V_117 , bool V_118 )
{
int V_119 = 1 , div ;
struct V_114 * V_120 = F_34 ( V_115 ) ;
unsigned long V_121 = 0 ;
unsigned long V_122 = ~ 0ul ;
int V_123 = ( 1 << ( V_124 + V_125 ) ) - 1 ;
for ( div = 1 ; div < V_123 ; div ++ ) {
unsigned long V_126 , V_127 , V_128 ;
if ( V_118 )
V_126 = F_35 ( V_120 , V_116 * div ) ;
else
V_126 = * V_117 ;
V_127 = F_36 ( V_126 , div ) ;
V_128 = abs ( V_116 - V_127 ) ;
if ( V_128 < V_122 ) {
V_119 = div ;
V_122 = V_128 ;
V_121 = V_126 ;
}
}
* V_117 = V_121 ;
return V_119 ;
}
static long F_37 ( struct V_114 * V_115 , unsigned long V_116 ,
unsigned long * V_117 )
{
int div = F_33 ( V_115 , V_116 , V_117 , true ) ;
return F_36 ( * V_117 , div ) ;
}
static unsigned long F_38 ( struct V_114 * V_115 ,
unsigned long V_117 )
{
struct V_3 * V_4 =
F_39 ( V_115 , struct V_3 , V_129 ) ;
T_2 V_52 = F_2 ( V_4 -> V_8 + V_65 ) ;
int div ;
if ( V_52 & V_66 )
return V_117 ;
div = V_52 & V_67 ;
div |= ( V_52 & V_68 ) >>
( V_130 - V_124 ) ;
div += 2 ;
return F_36 ( V_117 , div ) ;
}
static int F_40 ( struct V_114 * V_115 , unsigned long V_116 ,
unsigned long V_117 )
{
struct V_3 * V_4 =
F_39 ( V_115 , struct V_3 , V_129 ) ;
int div = F_33 ( V_115 , V_116 , & V_117 , false ) ;
T_2 V_52 ;
F_11 ( & V_4 -> V_64 ) ;
V_52 = F_2 ( V_4 -> V_8 + V_65 ) ;
V_52 &= ~ ( V_66 | V_67 | V_68 ) ;
if ( div == 1 ) {
V_52 |= V_66 ;
} else {
div -= 2 ;
V_52 |= div & V_67 ;
V_52 |= ( div >> V_124 ) << V_130 ;
}
F_4 ( V_52 , V_4 -> V_8 + V_65 ) ;
F_12 ( & V_4 -> V_64 ) ;
return 0 ;
}
static int
F_41 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_39 ;
struct V_54 * V_120 = F_42 ( V_37 -> V_38 , L_3 ) ;
struct V_114 * div = & V_4 -> V_129 ;
const char * V_131 ;
struct V_132 V_133 = {
. V_134 = L_4 ,
. V_135 = & V_136 ,
. V_137 = & V_131 ,
. V_138 = 1 ,
. V_69 = V_139 ,
} ;
int V_53 ;
if ( F_43 ( V_120 ) ) {
F_9 ( V_37 -> V_38 , L_5 ) ;
return F_44 ( V_120 ) ;
}
V_131 = F_45 ( V_120 ) ;
F_46 ( & V_4 -> V_64 ) ;
div -> V_133 = & V_133 ;
V_53 = F_47 ( V_37 -> V_38 , div ) ;
V_4 -> V_54 = div -> V_54 ;
return V_53 ;
}
int F_48 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_39 ;
struct V_140 * V_38 = V_37 -> V_38 ;
struct V_141 * V_142 ;
T_2 V_143 [ 3 ] ;
int V_53 ;
static const T_2 V_144 [] = {
V_85 ,
V_86 ,
V_88 ,
V_89 ,
V_91 ,
V_93 ,
V_94 ,
V_95 ,
V_97 ,
V_98 ,
V_99 ,
V_100 ,
V_102 ,
V_103 ,
} ;
V_142 = F_49 ( V_38 -> V_145 , NULL ) ;
if ( ! V_142 )
return - V_146 ;
if ( F_50 ( V_142 ,
L_6 ,
V_143 ,
F_51 ( V_143 ) ) != 0 ) {
F_9 ( V_38 , L_7 ) ;
F_52 ( V_142 ) ;
return - V_147 ;
}
F_52 ( V_142 ) ;
if ( V_143 [ 0 ] != 0 ||
V_143 [ 1 ] != 8 ||
V_143 [ 2 ] != 16 ) {
F_9 ( V_38 , L_8 ) ;
return - V_28 ;
}
V_53 = F_41 ( V_37 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_53 ( V_37 , & V_4 -> V_11 ,
& V_148 ,
V_144 , F_51 ( V_144 ) ,
& V_4 -> V_41 . V_41 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
