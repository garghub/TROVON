static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
T_1 V_6 , T_1 V_4 )
{
V_4 ^= F_3 ( V_2 , V_3 ) & ~ V_6 ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_7 )
{
int V_8 , V_9 , V_10 , V_11 ;
V_9 = 0 ;
V_11 = ~ V_12 ;
for ( V_8 = 1000000 ; -- V_8 && V_9 < 6 ; ) {
V_10 = F_3 ( V_2 , F_7 ( V_7 ) )
& V_12 ;
if ( V_11 != V_10 ) {
V_11 = V_10 ;
V_9 ++ ;
}
}
if ( V_9 < 6 )
F_8 ( V_13 L_1 ) ;
F_1 ( V_2 , F_9 ( V_7 ) , V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_7 )
{
F_1 ( V_2 , F_9 ( V_7 ) , V_15 ) ;
}
static void F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = F_12 ( V_19 -> V_21 ) ;
int V_7 ;
V_7 = ( V_17 -> V_22 == V_23 ) ?
V_2 -> V_24 : V_2 -> V_25 ;
F_6 ( V_2 , V_7 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = F_12 ( V_19 -> V_21 ) ;
int V_7 ;
V_7 = ( V_17 -> V_22 == V_23 ) ?
V_2 -> V_24 : V_2 -> V_25 ;
F_10 ( V_2 , V_7 ) ;
}
static int F_14 ( struct V_16 * V_17 , int V_26 ,
int V_27 )
{
switch ( V_26 ) {
case V_28 :
case V_29 :
case V_30 :
if ( ( V_17 -> V_22 == V_31 ) ^ ! V_27 )
F_11 ( V_17 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
if ( ! V_27 )
F_13 ( V_17 ) ;
}
return 0 ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
V_35 = F_3 ( V_2 , V_36 ) ;
V_35 &= V_37 |
V_38 |
V_39 ;
F_1 ( V_2 , V_40 , V_35 ) ;
return V_35 ;
}
static unsigned int F_16 ( struct V_41 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_21 ) ;
unsigned int V_42 ;
unsigned int V_43 ;
V_42 = F_15 ( V_2 ) ;
if ( F_17 ( ! V_42 ) )
return 0 ;
V_43 = 0 ;
if ( V_42 & V_37 )
F_8 ( V_44 L_2 ) ;
if ( V_42 & V_38 )
V_43 |= 1 << V_23 ;
if ( V_42 & V_39 )
V_43 |= 1 << V_31 ;
return V_43 ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_7 ;
int V_45 = 50 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
while ( -- V_45 >= 0 ) {
int V_46 = F_3 ( V_2 , F_9 ( V_7 ) ) ;
if ( ( V_46 & V_47 )
|| ! ( V_46 & ( V_48 | V_49 ) ) )
break;
F_19 ( 20 ) ;
}
}
if ( V_45 < 0 )
F_8 ( V_13 L_3 ) ;
}
static int F_20 ( struct V_41 * V_21 ,
unsigned int V_50 )
{
struct V_1 * V_2 = F_12 ( V_21 ) ;
T_1 V_51 ;
switch ( V_50 & V_52 ) {
case V_53 :
V_51 = V_54 | V_55 ;
break;
case V_56 :
V_51 = V_57 | V_55 ;
break;
case V_58 :
V_51 = V_54 | V_59 ;
break;
case V_60 :
V_51 = V_57 | V_59 ;
break;
default:
return - V_61 ;
}
switch ( V_50 & V_62 ) {
case V_63 :
V_51 |= V_64 ;
break;
case V_65 :
V_51 |= V_66 ;
break;
default:
return - V_61 ;
}
F_5 ( V_2 , F_7 ( 0 ) ,
V_67 | V_68 | V_69 , V_51 ) ;
F_5 ( V_2 , F_7 ( 1 ) ,
V_67 | V_68 | V_69 , V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_41 * V_70 , int V_71 , int div )
{
struct V_1 * V_2 = F_12 ( V_70 ) ;
if ( ! div || ( div & 1 ) || div > ( V_72 + 1 ) * 2 )
return - V_61 ;
F_5 ( V_2 , F_7 ( V_71 ) ,
V_72 , div / 2 - 1 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_73 * V_74 ,
struct V_41 * V_70 )
{
struct V_1 * V_2 = F_12 ( V_70 ) ;
int V_75 ;
T_1 V_51 = 0 ;
if ( V_2 -> V_76 )
V_75 = 0 ;
else {
V_51 |= ( ( ( F_23 ( V_74 ) - 2 ) / 2 )
<< V_77 ) & V_78 ;
V_75 = ( V_17 -> V_22 == V_23 )
? V_2 -> V_24 : V_2 -> V_25 ;
}
switch ( F_24 ( V_74 ) ) {
case V_79 :
V_51 |= V_80 | V_81 ;
break;
case V_82 :
V_51 |= V_83 | V_84 ;
break;
default:
F_8 ( V_13 L_4 ,
F_24 ( V_74 ) ) ;
return - V_61 ;
}
if ( F_3 ( V_2 , F_7 ( V_75 ) )
& V_47 ) {
F_8 ( V_44 L_5 ) ;
return - V_85 ;
}
F_5 ( V_2 , F_7 ( V_75 ) ,
V_78 | V_86 | V_87 ,
V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_41 * V_70 )
{
struct V_1 * V_2 = F_12 ( V_70 ) ;
struct V_88 * V_89 = V_70 -> V_2 -> V_90 ;
if ( ! V_89 )
return - V_61 ;
V_70 -> V_91 = & V_2 -> V_92 ;
V_70 -> V_93 = & V_2 -> V_92 ;
V_2 -> V_76 = V_89 -> V_76 ;
V_2 -> V_25 = V_89 -> V_25 ;
V_2 -> V_24 = V_89 -> V_24 ;
V_2 -> V_94 = V_89 -> V_94 ;
V_2 -> V_95 = V_89 -> V_95 ;
F_1 ( V_2 , V_96 ,
V_2 -> V_76 ? V_97 : V_98 ) ;
if ( V_2 -> V_76 ) {
int V_8 ;
if ( V_2 -> V_94 + V_2 -> V_95 > V_99 )
return - V_61 ;
V_2 -> V_25 = 0 ;
V_2 -> V_24 = 1 ;
V_70 -> V_100 -> V_101 . V_102 = 2 * V_2 -> V_94 ;
V_70 -> V_100 -> V_101 . V_103 = V_70 -> V_100 -> V_101 . V_102 ;
V_70 -> V_100 -> V_104 . V_102 = 2 * V_2 -> V_95 ;
V_70 -> V_100 -> V_104 . V_103 = V_70 -> V_100 -> V_104 . V_102 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_95 ; V_8 ++ )
F_1 ( V_2 , F_26 ( V_8 ) , V_105 ) ;
for (; V_8 < V_99 - V_2 -> V_94 ; V_8 ++ )
F_1 ( V_2 , F_26 ( V_8 ) ,
V_106 ) ;
for (; V_8 < V_99 ; V_8 ++ )
F_1 ( V_2 , F_26 ( V_8 ) , V_107 ) ;
} else {
unsigned int V_108 [ 2 ] = { V_106 , V_106 } ;
if ( V_2 -> V_94 > 1 || V_2 -> V_95 > 1 )
return - V_61 ;
V_70 -> V_100 -> V_101 . V_102 = 2 * V_2 -> V_94 ;
V_70 -> V_100 -> V_101 . V_103 = 8 * V_2 -> V_94 ;
V_70 -> V_100 -> V_104 . V_102 = 2 * V_2 -> V_95 ;
V_70 -> V_100 -> V_104 . V_103 = 8 * V_2 -> V_95 ;
if ( V_2 -> V_94 )
V_108 [ V_2 -> V_25 ] = V_107 ;
if ( V_2 -> V_95 )
V_108 [ V_2 -> V_24 ] = V_105 ;
F_1 ( V_2 , F_26 ( 0 ) , V_108 [ 0 ] ) ;
F_1 ( V_2 , F_26 ( 1 ) , V_108 [ 1 ] ) ;
}
if ( V_2 -> V_95 ) {
if ( V_2 -> V_94 ) {
if ( ! V_2 -> V_92 . V_109 )
return - V_110 ;
} else {
V_2 -> V_92 . V_109 = V_2 -> V_92 . V_111 ;
V_2 -> V_92 . V_111 = 0 ;
}
}
V_2 -> V_92 . V_112 = V_2 -> V_113 + ( V_2 -> V_25 ?
V_114 : V_115 ) ;
V_2 -> V_92 . V_116 = V_2 -> V_113 + ( V_2 -> V_24 ?
V_114 : V_115 ) ;
V_2 -> V_92 . V_117 = V_89 -> V_117 | V_89 -> V_76 ;
return 0 ;
}
static int F_27 ( struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_120 * V_121 , * V_122 , * V_123 , * V_124 , * V_125 ;
T_2 T_3 * V_126 ;
int V_43 ;
V_121 = F_28 ( V_119 , V_127 , 0 ) ;
if ( ! V_121 ) {
F_29 ( & V_119 -> V_2 , L_6 ) ;
V_43 = - V_110 ;
goto V_128;
}
V_123 = F_30 ( V_121 -> V_129 , F_31 ( V_121 ) ,
V_119 -> V_130 ) ;
if ( ! V_123 ) {
F_29 ( & V_119 -> V_2 , L_7 ) ;
V_43 = - V_85 ;
goto V_128;
}
V_126 = F_32 ( V_121 -> V_129 , F_31 ( V_121 ) ) ;
if ( ! V_126 ) {
F_29 ( & V_119 -> V_2 , L_8 ) ;
V_43 = - V_131 ;
goto V_132;
}
V_122 = F_28 ( V_119 , V_127 , 1 ) ;
if ( ! V_122 ) {
F_29 ( & V_119 -> V_2 , L_9 ) ;
V_43 = - V_110 ;
goto V_133;
}
V_123 = F_30 ( V_122 -> V_129 , F_31 ( V_122 ) ,
V_119 -> V_130 ) ;
if ( ! V_123 ) {
F_29 ( & V_119 -> V_2 , L_10 ) ;
V_43 = - V_85 ;
goto V_133;
}
V_124 = F_28 ( V_119 , V_134 , 0 ) ;
if ( ! V_124 ) {
F_29 ( & V_119 -> V_2 , L_11 ) ;
V_43 = - V_110 ;
goto V_135;
}
V_123 = F_30 ( V_124 -> V_129 , F_31 ( V_124 ) ,
V_119 -> V_130 ) ;
if ( ! V_123 ) {
F_29 ( & V_119 -> V_2 , L_12 ) ;
V_43 = - V_85 ;
goto V_135;
}
V_125 = F_28 ( V_119 , V_134 , 1 ) ;
if ( V_125 ) {
V_123 = F_30 ( V_125 -> V_129 , F_31 ( V_125 ) ,
V_119 -> V_130 ) ;
if ( ! V_123 ) {
F_29 ( & V_119 -> V_2 ,
L_12 ) ;
V_43 = - V_85 ;
goto V_136;
}
}
V_2 = F_33 ( sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_2 ) {
V_43 = - V_131 ;
goto V_138;
}
F_34 ( & V_119 -> V_2 , V_2 ) ;
V_2 -> V_113 = V_122 -> V_129 ;
V_2 -> V_5 = V_126 ;
F_1 ( V_2 , V_139 , 0 ) ;
F_1 ( V_2 , V_40 ,
V_37 |
V_38 |
V_39 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 1 ) ;
F_18 ( V_2 ) ;
V_2 -> V_92 . V_140 = F_16 ;
V_2 -> V_92 . V_141 = F_14 ;
V_2 -> V_92 . V_111 = V_124 -> V_129 ;
V_2 -> V_92 . V_109 = V_125 ? V_125 -> V_129 : 0 ;
V_2 -> V_92 . V_142 = F_35 ( V_119 , 0 ) ;
if ( V_2 -> V_92 . V_142 < 0 ) {
F_29 ( & V_119 -> V_2 , L_13 ) ;
V_43 = - V_110 ;
goto V_143;
}
F_1 ( V_2 , V_139 ,
V_37 |
V_38 |
V_39 ) ;
V_43 = F_36 ( & V_119 -> V_2 , & V_144 ,
& V_145 , 1 ) ;
if ( V_43 )
goto V_143;
return 0 ;
V_143:
F_37 ( V_2 ) ;
V_138:
if ( V_125 )
F_38 ( V_125 -> V_129 , F_31 ( V_125 ) ) ;
V_136:
F_38 ( V_124 -> V_129 , F_31 ( V_124 ) ) ;
V_135:
F_38 ( V_122 -> V_129 , F_31 ( V_122 ) ) ;
V_133:
F_39 ( V_126 ) ;
V_132:
F_38 ( V_121 -> V_129 , F_31 ( V_121 ) ) ;
V_128:
return V_43 ;
}
static int F_40 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_41 ( & V_119 -> V_2 ) ;
struct V_120 * V_123 ;
void T_3 * V_126 = V_2 -> V_5 ;
F_42 ( & V_119 -> V_2 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 1 ) ;
F_1 ( V_2 , V_139 , 0 ) ;
F_37 ( V_2 ) ;
V_123 = F_28 ( V_119 , V_134 , 0 ) ;
F_38 ( V_123 -> V_129 , F_31 ( V_123 ) ) ;
V_123 = F_28 ( V_119 , V_134 , 1 ) ;
if ( V_123 )
F_38 ( V_123 -> V_129 , F_31 ( V_123 ) ) ;
V_123 = F_28 ( V_119 , V_127 , 0 ) ;
F_38 ( V_123 -> V_129 , F_31 ( V_123 ) ) ;
F_39 ( V_126 ) ;
V_123 = F_28 ( V_119 , V_146 , 0 ) ;
F_38 ( V_123 -> V_129 , F_31 ( V_123 ) ) ;
return 0 ;
}
