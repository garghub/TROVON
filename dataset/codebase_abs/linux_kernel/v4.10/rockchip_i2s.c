static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , true ) ;
F_4 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_7 ( V_4 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
F_3 ( V_4 -> V_5 , false ) ;
F_8 ( V_4 -> V_5 ) ;
V_7 = F_9 ( V_4 -> V_5 ) ;
if ( V_7 )
F_4 ( V_4 -> V_6 ) ;
return V_7 ;
}
static inline struct V_3 * F_10 ( struct V_8 * V_9 )
{
return F_11 ( V_9 ) ;
}
static void F_12 ( struct V_3 * V_4 , int V_10 )
{
unsigned int V_11 = 0 ;
int V_12 = 10 ;
if ( V_10 ) {
F_13 ( V_4 -> V_5 , V_13 ,
V_14 , V_14 ) ;
F_13 ( V_4 -> V_5 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_18 = true ;
} else {
V_4 -> V_18 = false ;
F_13 ( V_4 -> V_5 , V_13 ,
V_14 , V_19 ) ;
if ( ! V_4 -> V_20 ) {
F_13 ( V_4 -> V_5 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_13 ( V_4 -> V_5 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_14 ( V_4 -> V_5 , V_23 , & V_11 ) ;
while ( V_11 ) {
F_14 ( V_4 -> V_5 , V_23 , & V_11 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_15 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
}
static void F_16 ( struct V_3 * V_4 , int V_10 )
{
unsigned int V_11 = 0 ;
int V_12 = 10 ;
if ( V_10 ) {
F_13 ( V_4 -> V_5 , V_13 ,
V_26 , V_26 ) ;
F_13 ( V_4 -> V_5 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_20 = true ;
} else {
V_4 -> V_20 = false ;
F_13 ( V_4 -> V_5 , V_13 ,
V_26 , V_27 ) ;
if ( ! V_4 -> V_18 ) {
F_13 ( V_4 -> V_5 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_13 ( V_4 -> V_5 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_14 ( V_4 -> V_5 , V_23 , & V_11 ) ;
while ( V_11 ) {
F_14 ( V_4 -> V_5 , V_23 , & V_11 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_15 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
}
static int F_17 ( struct V_8 * V_28 ,
unsigned int V_29 )
{
struct V_3 * V_4 = F_10 ( V_28 ) ;
unsigned int V_30 = 0 , V_11 = 0 ;
V_30 = V_31 ;
switch ( V_29 & V_32 ) {
case V_33 :
V_11 = V_34 ;
V_4 -> V_35 = true ;
break;
case V_36 :
V_11 = V_37 ;
V_4 -> V_35 = false ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_39 , V_30 , V_11 ) ;
V_30 = V_40 ;
switch ( V_29 & V_41 ) {
case V_42 :
V_11 = V_43 ;
break;
case V_44 :
V_11 = V_45 ;
break;
case V_46 :
V_11 = V_47 ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_48 , V_30 , V_11 ) ;
V_30 = V_49 ;
switch ( V_29 & V_41 ) {
case V_42 :
V_11 = V_50 ;
break;
case V_44 :
V_11 = V_51 ;
break;
case V_46 :
V_11 = V_52 ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_53 , V_30 , V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_10 ( V_9 ) ;
struct V_58 * V_59 = V_55 -> V_60 ;
unsigned int V_11 = 0 ;
unsigned int V_61 , V_62 , V_63 , V_64 ;
if ( V_4 -> V_35 ) {
V_61 = F_19 ( V_4 -> V_6 ) ;
V_62 = 2 * 32 * F_20 ( V_57 ) ;
if ( V_62 && V_61 % V_62 )
return - V_38 ;
V_63 = V_61 / V_62 ;
V_64 = V_62 / F_20 ( V_57 ) ;
F_13 ( V_4 -> V_5 , V_39 ,
V_65 ,
F_21 ( V_63 ) ) ;
F_13 ( V_4 -> V_5 , V_39 ,
V_66 |
V_67 ,
F_22 ( V_64 ) |
F_23 ( V_64 ) ) ;
}
switch ( F_24 ( V_57 ) ) {
case V_68 :
V_11 |= F_25 ( 8 ) ;
break;
case V_69 :
V_11 |= F_25 ( 16 ) ;
break;
case V_70 :
V_11 |= F_25 ( 20 ) ;
break;
case V_71 :
V_11 |= F_25 ( 24 ) ;
break;
case V_72 :
V_11 |= F_25 ( 32 ) ;
break;
default:
return - V_38 ;
}
switch ( F_26 ( V_57 ) ) {
case 8 :
V_11 |= V_73 ;
break;
case 6 :
V_11 |= V_74 ;
break;
case 4 :
V_11 |= V_75 ;
break;
case 2 :
V_11 |= V_76 ;
break;
default:
F_7 ( V_4 -> V_2 , L_3 ,
F_26 ( V_57 ) ) ;
return - V_38 ;
}
if ( V_55 -> V_77 == V_78 )
F_13 ( V_4 -> V_5 , V_53 ,
V_79 | V_80 ,
V_11 ) ;
else
F_13 ( V_4 -> V_5 , V_48 ,
V_81 | V_82 ,
V_11 ) ;
if ( ! F_27 ( V_4 -> V_83 ) && V_4 -> V_84 ) {
F_14 ( V_4 -> V_5 , V_48 , & V_11 ) ;
V_11 &= V_82 ;
switch ( V_11 ) {
case V_75 :
V_11 = V_85 ;
break;
case V_74 :
V_11 = V_86 ;
break;
case V_73 :
V_11 = V_87 ;
break;
default:
V_11 = V_88 ;
break;
}
V_11 <<= V_4 -> V_84 -> V_89 ;
V_11 |= ( V_90 << V_4 -> V_84 -> V_89 ) << 16 ;
F_28 ( V_4 -> V_83 , V_4 -> V_84 -> V_91 , V_11 ) ;
}
F_13 ( V_4 -> V_5 , V_13 , V_92 ,
F_29 ( 16 ) ) ;
F_13 ( V_4 -> V_5 , V_13 , V_93 ,
F_30 ( 16 ) ) ;
V_11 = V_94 ;
if ( V_9 -> V_95 -> V_96 && V_59 -> V_97 -> V_96 )
V_11 = V_98 ;
F_13 ( V_4 -> V_5 , V_39 ,
V_99 ,
V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_55 ,
int V_100 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_10 ( V_9 ) ;
int V_7 = 0 ;
switch ( V_100 ) {
case V_101 :
case V_102 :
case V_103 :
if ( V_55 -> V_77 == V_78 )
F_16 ( V_4 , 1 ) ;
else
F_12 ( V_4 , 1 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
if ( V_55 -> V_77 == V_78 )
F_16 ( V_4 , 0 ) ;
else
F_12 ( V_4 , 0 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_32 ( struct V_8 * V_28 , int V_107 ,
unsigned int V_108 , int V_109 )
{
struct V_3 * V_4 = F_10 ( V_28 ) ;
int V_7 ;
V_7 = F_33 ( V_4 -> V_6 , V_108 ) ;
if ( V_7 )
F_7 ( V_4 -> V_2 , L_4 , V_7 ) ;
return V_7 ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_11 ( V_9 ) ;
V_9 -> V_110 = & V_4 -> V_110 ;
V_9 -> V_111 = & V_4 -> V_111 ;
return 0 ;
}
static bool F_35 ( struct V_1 * V_2 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_48 :
case V_53 :
case V_39 :
case V_13 :
case V_113 :
case V_15 :
case V_23 :
case V_114 :
return true ;
default:
return false ;
}
}
static bool F_36 ( struct V_1 * V_2 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_48 :
case V_53 :
case V_39 :
case V_13 :
case V_113 :
case V_15 :
case V_23 :
case V_115 :
case V_116 :
case V_117 :
return true ;
default:
return false ;
}
}
static bool F_37 ( struct V_1 * V_2 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_117 :
case V_23 :
return true ;
default:
return false ;
}
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_112 )
{
switch ( V_112 ) {
default:
return false ;
}
}
static int F_39 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = V_119 -> V_2 . V_122 ;
const struct V_123 * V_124 ;
struct V_3 * V_4 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
void T_1 * V_129 ;
int V_7 ;
int V_11 ;
V_4 = F_40 ( & V_119 -> V_2 , sizeof( * V_4 ) , V_130 ) ;
if ( ! V_4 ) {
F_7 ( & V_119 -> V_2 , L_5 ) ;
return - V_131 ;
}
V_4 -> V_2 = & V_119 -> V_2 ;
V_4 -> V_83 = F_41 ( V_121 , L_6 ) ;
if ( ! F_27 ( V_4 -> V_83 ) ) {
V_124 = F_42 ( V_132 , & V_119 -> V_2 ) ;
if ( ! V_124 || ! V_124 -> V_133 )
return - V_38 ;
V_4 -> V_84 = V_124 -> V_133 ;
}
V_4 -> V_134 = F_43 ( & V_119 -> V_2 , L_7 ) ;
if ( F_27 ( V_4 -> V_134 ) ) {
F_7 ( & V_119 -> V_2 , L_8 ) ;
return F_44 ( V_4 -> V_134 ) ;
}
V_7 = F_6 ( V_4 -> V_134 ) ;
if ( V_7 ) {
F_7 ( V_4 -> V_2 , L_9 , V_7 ) ;
return V_7 ;
}
V_4 -> V_6 = F_43 ( & V_119 -> V_2 , L_10 ) ;
if ( F_27 ( V_4 -> V_6 ) ) {
F_7 ( & V_119 -> V_2 , L_11 ) ;
return F_44 ( V_4 -> V_6 ) ;
}
V_128 = F_45 ( V_119 , V_135 , 0 ) ;
V_129 = F_46 ( & V_119 -> V_2 , V_128 ) ;
if ( F_27 ( V_129 ) )
return F_44 ( V_129 ) ;
V_4 -> V_5 = F_47 ( & V_119 -> V_2 , V_129 ,
& V_136 ) ;
if ( F_27 ( V_4 -> V_5 ) ) {
F_7 ( & V_119 -> V_2 ,
L_12 ) ;
return F_44 ( V_4 -> V_5 ) ;
}
V_4 -> V_111 . V_137 = V_128 -> V_138 + V_114 ;
V_4 -> V_111 . V_139 = V_140 ;
V_4 -> V_111 . V_141 = 4 ;
V_4 -> V_110 . V_137 = V_128 -> V_138 + V_115 ;
V_4 -> V_110 . V_139 = V_140 ;
V_4 -> V_110 . V_141 = 4 ;
F_48 ( & V_119 -> V_2 , V_4 ) ;
F_49 ( & V_119 -> V_2 ) ;
if ( ! F_50 ( & V_119 -> V_2 ) ) {
V_7 = F_5 ( & V_119 -> V_2 ) ;
if ( V_7 )
goto V_142;
}
V_126 = F_40 ( & V_119 -> V_2 ,
sizeof( * V_126 ) , V_130 ) ;
if ( ! V_126 )
return - V_131 ;
memcpy ( V_126 , & V_143 , sizeof( * V_126 ) ) ;
if ( ! F_51 ( V_121 , L_13 , & V_11 ) ) {
if ( V_11 >= 2 && V_11 <= 8 )
V_126 -> V_144 . V_145 = V_11 ;
}
if ( ! F_51 ( V_121 , L_14 , & V_11 ) ) {
if ( V_11 >= 2 && V_11 <= 8 )
V_126 -> V_146 . V_145 = V_11 ;
}
V_7 = F_52 ( & V_119 -> V_2 ,
& V_147 ,
V_126 , 1 ) ;
if ( V_7 ) {
F_7 ( & V_119 -> V_2 , L_15 ) ;
goto V_148;
}
V_7 = F_53 ( & V_119 -> V_2 , NULL , 0 ) ;
if ( V_7 ) {
F_7 ( & V_119 -> V_2 , L_16 ) ;
return V_7 ;
}
return 0 ;
V_148:
if ( ! F_54 ( & V_119 -> V_2 ) )
F_1 ( & V_119 -> V_2 ) ;
V_142:
F_55 ( & V_119 -> V_2 ) ;
return V_7 ;
}
static int F_56 ( struct V_118 * V_119 )
{
struct V_3 * V_4 = F_2 ( & V_119 -> V_2 ) ;
F_55 ( & V_119 -> V_2 ) ;
if ( ! F_54 ( & V_119 -> V_2 ) )
F_1 ( & V_119 -> V_2 ) ;
F_4 ( V_4 -> V_6 ) ;
F_4 ( V_4 -> V_134 ) ;
return 0 ;
}
