static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == V_5 ||
V_2 -> V_3 -> V_4 == V_6 )
V_2 -> V_7 |= V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_12 =
( ( 0x21 << V_13 )
& V_14 ) |
( ( 0x21 << V_15 )
& V_16 ) |
V_17 |
V_18 |
V_19 |
V_20 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_23 = 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static T_1 F_8 ( int V_24 , void * V_25 )
{
struct V_9 * V_10 = V_25 ;
struct V_26 * V_11 = V_10 -> V_11 ;
F_9 ( V_11 -> V_21 , F_10 ( 200 ) ) ;
return V_27 ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_28 , V_24 , V_29 = V_10 -> V_30 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_32 = - V_31 ;
if ( ! F_12 ( V_29 ) )
return;
V_28 = F_13 ( V_29 , L_1 ) ;
if ( V_28 < 0 )
goto V_33;
V_28 = F_14 ( V_29 ) ;
if ( V_28 < 0 )
goto V_34;
V_24 = F_15 ( V_29 ) ;
if ( V_24 < 0 )
goto V_34;
V_28 = F_16 ( V_24 , F_8 , V_35 |
V_36 , L_1 , V_10 ) ;
if ( V_28 )
goto V_34;
V_10 -> V_30 = V_29 ;
V_10 -> V_32 = V_24 ;
return;
V_34:
F_17 ( V_29 ) ;
V_33:
F_18 ( & V_10 -> V_2 -> V_3 -> V_37 , L_2 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_32 >= 0 )
F_20 ( V_10 -> V_32 , V_10 ) ;
if ( F_12 ( V_10 -> V_30 ) )
F_17 ( V_10 -> V_30 ) ;
}
static inline void F_11 ( struct V_9 * V_10 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_40 |
V_41 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_11 )
{
T_2 V_43 ;
V_43 = F_24 ( V_11 , V_44 ) ;
V_43 |= 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_26 ( 9 ) ;
V_43 &= ~ 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_27 ( 300 , 1000 ) ;
}
static int F_28 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_45 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_46 = F_23 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_47 ;
T_2 V_48 ;
switch ( V_2 -> V_3 -> V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_47 = F_31 ( V_2 -> V_3 , V_54 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_48 &= 0x7f ;
F_32 ( V_2 -> V_3 , V_54 , V_48 ) ;
F_32 ( V_2 -> V_3 , V_55 , 0x08 ) ;
V_47 = F_31 ( V_2 -> V_3 , V_56 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_48 |= 0x20 ;
F_32 ( V_2 -> V_3 , V_56 , V_48 ) ;
V_47 = F_31 ( V_2 -> V_3 , V_57 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_48 |= 0x01 ;
F_32 ( V_2 -> V_3 , V_57 , V_48 ) ;
F_32 ( V_2 -> V_3 , V_57 , 0x73 ) ;
F_32 ( V_2 -> V_3 , V_58 , 0x39 ) ;
F_32 ( V_2 -> V_3 , V_59 , 0x08 ) ;
V_47 = F_31 ( V_2 -> V_3 , V_60 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_48 |= 0x08 ;
F_32 ( V_2 -> V_3 , V_60 , V_48 ) ;
V_47 = F_31 ( V_2 -> V_3 , V_54 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_48 |= 0x80 ;
F_32 ( V_2 -> V_3 , V_54 , V_48 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_61 )
{
T_2 V_48 ;
int V_47 ;
V_47 = F_31 ( V_2 -> V_3 , 0xAE , & V_48 ) ;
if ( V_47 )
return V_47 ;
if ( V_61 )
V_48 |= 0x47 ;
else
V_48 &= ~ 0x47 ;
V_47 = F_32 ( V_2 -> V_3 , 0xAE , V_48 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_47 ;
T_3 V_62 = 0 ;
if ( V_2 -> V_3 -> V_63 == 0 ) {
V_2 -> V_7 |= V_64 |
V_65 |
V_66 |
V_67 |
V_68 ;
}
if ( V_2 -> V_3 -> V_49 == V_69 )
V_62 = V_70 ;
else if ( V_2 -> V_3 -> V_49 == V_71 )
V_62 = V_72 ;
if ( V_62 ) {
struct V_73 * V_74 ;
V_74 = NULL ;
while ( ( V_74 = F_35 ( V_75 ,
V_62 , V_74 ) ) != NULL ) {
if ( ( F_36 ( V_2 -> V_3 -> V_76 ) ==
F_36 ( V_74 -> V_76 ) ) &&
( V_2 -> V_3 -> V_77 == V_74 -> V_77 ) )
break;
}
if ( V_74 ) {
F_37 ( V_74 ) ;
F_38 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_78 ;
}
}
V_47 = F_33 ( V_2 , 1 ) ;
if ( V_47 ) {
F_39 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_47 ;
}
if ( V_2 -> V_3 -> V_49 == V_71 ||
V_2 -> V_3 -> V_49 == V_72 )
V_2 -> V_7 |= V_79 ;
return 0 ;
}
static void F_40 ( struct V_26 * V_11 , int V_61 )
{
T_2 V_48 ;
V_48 = F_41 ( V_11 -> V_80 + 0xC0 ) ;
if ( V_61 )
V_48 |= 0x01 ;
else
V_48 &= ~ 0x01 ;
F_42 ( V_48 , V_11 -> V_80 + 0xC0 ) ;
}
static int F_43 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_63 == 0 ) {
T_3 V_81 ;
V_81 = F_44 ( V_10 -> V_11 -> V_80 + V_82 ) ;
V_81 = ( V_81 & V_83 ) >>
V_84 ;
if ( V_81 < 0xAC )
V_10 -> V_11 -> V_7 |= V_85 ;
}
if ( V_10 -> V_2 -> V_3 -> V_49 == V_72 ) {
V_10 -> V_11 -> V_86 = V_87 | V_88 |
V_89 | V_90 |
V_91 ;
V_10 -> V_11 -> V_92 = V_87 | V_88 |
V_89 | V_90 ;
}
if ( V_10 -> V_2 -> V_3 -> V_49 == V_70 ||
V_10 -> V_2 -> V_3 -> V_49 == V_72 )
F_40 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_93 ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 , int V_94 )
{
if ( V_94 )
return;
if ( V_10 -> V_2 -> V_3 -> V_49 == V_70 ||
V_10 -> V_2 -> V_3 -> V_49 == V_72 )
F_40 ( V_10 -> V_11 , 0 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_95 ;
if ( V_2 -> V_3 -> V_49 == V_70 ||
V_2 -> V_3 -> V_49 == V_72 ) {
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ )
F_40 ( V_2 -> V_96 [ V_95 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_47 , V_95 ;
if ( V_2 -> V_3 -> V_49 == V_70 ||
V_2 -> V_3 -> V_49 == V_72 ) {
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ )
F_40 ( V_2 -> V_96 [ V_95 ] -> V_11 , 1 ) ;
}
V_47 = F_33 ( V_2 , 1 ) ;
if ( V_47 ) {
F_39 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_47 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_97 & 0x0000FF ) == V_98 ) {
V_2 -> V_3 -> V_97 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_97 |= V_99 ;
}
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
int V_100 , V_101 ;
T_2 V_102 = F_41 ( V_10 -> V_11 -> V_80 + V_103 ) ;
T_2 V_104 = F_41 ( V_10 -> V_11 -> V_80 + V_105 ) ;
F_38 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_102 >> 4 , V_102 & 0xf ,
V_104 >> 4 , V_104 & 0xf ) ;
if ( V_104 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_106 ;
F_42 ( V_107 , V_10 -> V_11 -> V_80 + V_108 ) ;
F_42 ( V_109 , V_10 -> V_11 -> V_80 + V_110 ) ;
F_26 ( 50 ) ;
V_100 = 10 ;
do {
V_101 = F_50 ( V_10 -> V_11 -> V_80 + V_111 ) ;
if ( V_101 & V_112 )
break;
F_26 ( 100 ) ;
} while ( -- V_100 );
if ( ! V_100 ) {
F_39 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_42 ( 0 , V_10 -> V_11 -> V_80 + V_110 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_63 == 0x10 )
V_2 -> V_7 |= V_113 ;
return 0 ;
}
static int F_52 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_73 * V_3 ;
int V_47 ;
V_10 = F_53 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_97 & 0xFFFF00 ) == ( V_114 << 8 ) ) &&
( ( V_3 -> V_97 & 0x0000FF ) != V_99 ) &&
( V_11 -> V_115 & V_116 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
V_47 = F_54 ( V_3 , F_55 ( 32 ) ) ;
if ( V_47 )
return V_47 ;
F_56 ( V_3 ) ;
return 0 ;
}
static int F_57 ( struct V_26 * V_11 , int V_117 )
{
T_2 V_118 ;
V_118 = F_24 ( V_11 , V_119 ) ;
switch ( V_117 ) {
case V_120 :
V_118 |= V_121 ;
V_118 &= ~ V_122 ;
break;
case V_123 :
V_118 |= V_122 ;
V_118 &= ~ V_121 ;
break;
default:
V_118 &= ~ ( V_121 | V_122 ) ;
break;
}
F_25 ( V_11 , V_118 , V_119 ) ;
return 0 ;
}
static void F_58 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_53 ( V_11 ) ;
int V_124 = V_10 -> V_124 ;
if ( ! F_12 ( V_124 ) )
return;
F_59 ( V_124 , 0 ) ;
F_26 ( 10 ) ;
F_59 ( V_124 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_60 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_53 ( V_11 ) ;
if ( V_10 -> V_46 )
V_10 -> V_46 ( V_11 ) ;
}
static int F_61 ( struct V_49 * V_37 )
{
struct V_73 * V_3 = F_62 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_125 ;
T_4 V_126 = 0 ;
int V_95 , V_47 ;
V_2 = F_63 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ ) {
V_10 = V_2 -> V_96 [ V_95 ] ;
if ( ! V_10 )
continue;
V_47 = F_64 ( V_10 -> V_11 ) ;
if ( V_47 )
goto V_127;
V_125 = V_10 -> V_11 -> V_21 -> V_126 ;
if ( V_125 & V_128 )
F_65 ( V_10 -> V_11 ) ;
V_126 |= V_125 ;
}
if ( V_2 -> V_129 && V_2 -> V_129 -> V_130 ) {
V_47 = V_2 -> V_129 -> V_130 ( V_2 ) ;
if ( V_47 )
goto V_127;
}
F_66 ( V_3 ) ;
if ( V_126 & V_131 ) {
if ( V_126 & V_128 ) {
F_67 ( V_3 , true ) ;
F_68 ( V_3 , V_132 , 1 ) ;
}
F_69 ( V_3 , V_132 ) ;
} else {
F_68 ( V_3 , V_132 , 0 ) ;
F_70 ( V_3 ) ;
F_69 ( V_3 , V_132 ) ;
}
return 0 ;
V_127:
while ( -- V_95 >= 0 )
F_71 ( V_2 -> V_96 [ V_95 ] -> V_11 ) ;
return V_47 ;
}
static int F_72 ( struct V_49 * V_37 )
{
struct V_73 * V_3 = F_62 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_95 , V_47 ;
V_2 = F_63 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_69 ( V_3 , V_133 ) ;
F_73 ( V_3 ) ;
V_47 = F_74 ( V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_2 -> V_129 && V_2 -> V_129 -> V_134 ) {
V_47 = V_2 -> V_129 -> V_134 ( V_2 ) ;
if ( V_47 )
return V_47 ;
}
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ ) {
V_10 = V_2 -> V_96 [ V_95 ] ;
if ( ! V_10 )
continue;
V_47 = F_71 ( V_10 -> V_11 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_75 ( struct V_49 * V_37 )
{
struct V_73 * V_3 = F_76 ( V_37 , struct V_73 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_95 , V_47 ;
V_2 = F_63 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ ) {
V_10 = V_2 -> V_96 [ V_95 ] ;
if ( ! V_10 )
continue;
V_47 = F_77 ( V_10 -> V_11 ) ;
if ( V_47 )
goto V_135;
}
if ( V_2 -> V_129 && V_2 -> V_129 -> V_130 ) {
V_47 = V_2 -> V_129 -> V_130 ( V_2 ) ;
if ( V_47 )
goto V_135;
}
return 0 ;
V_135:
while ( -- V_95 >= 0 )
F_78 ( V_2 -> V_96 [ V_95 ] -> V_11 ) ;
return V_47 ;
}
static int F_79 ( struct V_49 * V_37 )
{
struct V_73 * V_3 = F_76 ( V_37 , struct V_73 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_95 , V_47 ;
V_2 = F_63 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_129 && V_2 -> V_129 -> V_134 ) {
V_47 = V_2 -> V_129 -> V_134 ( V_2 ) ;
if ( V_47 )
return V_47 ;
}
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ ) {
V_10 = V_2 -> V_96 [ V_95 ] ;
if ( ! V_10 )
continue;
V_47 = F_78 ( V_10 -> V_11 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_80 ( struct V_49 * V_37 )
{
return 0 ;
}
static struct V_9 * F_81 (
struct V_73 * V_3 , struct V_1 * V_2 , int V_136 ,
int V_137 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_47 , V_138 = V_136 + V_137 ;
if ( ! ( F_82 ( V_3 , V_138 ) & V_139 ) ) {
F_39 ( & V_3 -> V_37 , L_11 , V_138 ) ;
return F_83 ( - V_78 ) ;
}
if ( F_84 ( V_3 , V_138 ) < 0x100 ) {
F_39 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_97 & 0x0000FF ) == V_98 ) {
F_39 ( & V_3 -> V_37 , L_14 ) ;
return F_83 ( - V_78 ) ;
}
if ( ( V_3 -> V_97 & 0x0000FF ) > V_98 ) {
F_39 ( & V_3 -> V_37 , L_15 ) ;
return F_83 ( - V_78 ) ;
}
V_11 = F_85 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_86 ( V_11 ) ) {
F_39 ( & V_3 -> V_37 , L_16 ) ;
return F_87 ( V_11 ) ;
}
V_10 = F_53 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_140 = V_138 ;
V_10 -> V_124 = - V_31 ;
V_10 -> V_30 = - V_31 ;
if ( * V_141 )
V_10 -> V_142 = V_141 ( V_3 , V_137 ) ;
if ( V_10 -> V_142 ) {
if ( V_10 -> V_142 -> V_143 ) {
V_47 = V_10 -> V_142 -> V_143 ( V_10 -> V_142 ) ;
if ( V_47 ) {
F_39 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_124 = V_10 -> V_142 -> V_124 ;
V_10 -> V_30 = V_10 -> V_142 -> V_30 ;
}
V_11 -> V_144 = L_18 ;
V_11 -> V_145 = & V_146 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_147 = V_2 -> V_147 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_47 = F_88 ( V_3 , V_138 , F_89 ( V_11 -> V_21 ) ) ;
if ( V_47 ) {
F_39 ( & V_3 -> V_37 , L_19 ) ;
goto V_148;
}
V_11 -> V_80 = F_90 ( V_3 , V_138 ) ;
if ( ! V_11 -> V_80 ) {
F_39 ( & V_3 -> V_37 , L_20 ) ;
V_47 = - V_149 ;
goto V_150;
}
if ( V_2 -> V_129 && V_2 -> V_129 -> V_151 ) {
V_47 = V_2 -> V_129 -> V_151 ( V_10 ) ;
if ( V_47 )
goto V_152;
}
if ( F_12 ( V_10 -> V_124 ) ) {
if ( ! F_13 ( V_10 -> V_124 , L_21 ) ) {
F_91 ( V_10 -> V_124 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_45 ;
V_10 -> V_46 = F_58 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_124 = - V_31 ;
}
}
V_11 -> V_21 -> V_153 = V_131 | V_128 ;
V_11 -> V_21 -> V_137 = V_137 ;
V_11 -> V_21 -> V_39 |= V_154 ;
V_47 = F_92 ( V_11 ) ;
if ( V_47 )
goto remove;
F_11 ( V_10 ) ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_124 ) )
F_17 ( V_10 -> V_124 ) ;
if ( V_2 -> V_129 && V_2 -> V_129 -> V_155 )
V_2 -> V_129 -> V_155 ( V_10 , 0 ) ;
V_152:
F_93 ( V_11 -> V_80 ) ;
V_150:
F_94 ( V_3 , V_138 ) ;
V_148:
if ( V_10 -> V_142 && V_10 -> V_142 -> V_148 )
V_10 -> V_142 -> V_148 ( V_10 -> V_142 ) ;
free:
F_95 ( V_11 ) ;
return F_83 ( V_47 ) ;
}
static void F_96 ( struct V_9 * V_10 )
{
int V_94 ;
T_5 V_48 ;
F_19 ( V_10 ) ;
V_94 = 0 ;
V_48 = F_44 ( V_10 -> V_11 -> V_80 + V_156 ) ;
if ( V_48 == ( T_5 ) - 1 )
V_94 = 1 ;
F_97 ( V_10 -> V_11 , V_94 ) ;
if ( F_12 ( V_10 -> V_124 ) )
F_17 ( V_10 -> V_124 ) ;
if ( V_10 -> V_2 -> V_129 && V_10 -> V_2 -> V_129 -> V_155 )
V_10 -> V_2 -> V_129 -> V_155 ( V_10 , V_94 ) ;
if ( V_10 -> V_142 && V_10 -> V_142 -> V_148 )
V_10 -> V_142 -> V_148 ( V_10 -> V_142 ) ;
F_94 ( V_10 -> V_2 -> V_3 , V_10 -> V_140 ) ;
F_95 ( V_10 -> V_11 ) ;
}
static void F_98 ( struct V_49 * V_37 )
{
F_99 ( V_37 ) ;
F_100 ( V_37 ) ;
F_101 ( V_37 , 50 ) ;
F_102 ( V_37 ) ;
F_103 ( V_37 , 1 ) ;
}
static void F_104 ( struct V_49 * V_37 )
{
F_105 ( V_37 ) ;
F_106 ( V_37 ) ;
}
static int F_107 ( struct V_73 * V_3 ,
const struct V_157 * V_158 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_96 , V_136 ;
int V_47 , V_95 ;
F_108 ( V_3 == NULL ) ;
F_108 ( V_158 == NULL ) ;
F_38 ( & V_3 -> V_37 , L_23 ,
( int ) V_3 -> V_159 , ( int ) V_3 -> V_49 , ( int ) V_3 -> V_63 ) ;
V_47 = F_31 ( V_3 , V_160 , & V_96 ) ;
if ( V_47 )
return V_47 ;
V_96 = F_109 ( V_96 ) + 1 ;
F_110 ( & V_3 -> V_37 , L_24 , V_96 ) ;
if ( V_96 == 0 )
return - V_78 ;
F_108 ( V_96 > V_161 ) ;
V_47 = F_31 ( V_3 , V_160 , & V_136 ) ;
if ( V_47 )
return V_47 ;
V_136 &= V_162 ;
if ( V_136 > 5 ) {
F_39 ( & V_3 -> V_37 , L_25 ) ;
return - V_78 ;
}
V_47 = F_74 ( V_3 ) ;
if ( V_47 )
return V_47 ;
V_2 = F_111 ( sizeof( struct V_1 ) , V_163 ) ;
if ( ! V_2 ) {
V_47 = - V_149 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_129 = ( const struct V_164 * ) V_158 -> V_165 ;
if ( V_2 -> V_129 ) {
V_2 -> V_7 = V_2 -> V_129 -> V_7 ;
V_2 -> V_147 = V_2 -> V_129 -> V_147 ;
V_2 -> V_166 = V_2 -> V_129 -> V_166 ;
}
V_2 -> V_23 = V_96 ;
F_112 ( V_3 , V_2 ) ;
if ( V_2 -> V_129 && V_2 -> V_129 -> V_167 ) {
V_47 = V_2 -> V_129 -> V_167 ( V_2 ) ;
if ( V_47 )
goto free;
}
V_96 = V_2 -> V_23 ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_10 = F_81 ( V_3 , V_2 , V_136 , V_95 ) ;
if ( F_86 ( V_10 ) ) {
for ( V_95 -- ; V_95 >= 0 ; V_95 -- )
F_96 ( V_2 -> V_96 [ V_95 ] ) ;
V_47 = F_113 ( V_10 ) ;
goto free;
}
V_2 -> V_96 [ V_95 ] = V_10 ;
}
if ( V_2 -> V_166 )
F_98 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_112 ( V_3 , NULL ) ;
F_114 ( V_2 ) ;
V_28:
F_70 ( V_3 ) ;
return V_47 ;
}
static void F_115 ( struct V_73 * V_3 )
{
int V_95 ;
struct V_1 * V_2 ;
V_2 = F_63 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_166 )
F_104 ( & V_3 -> V_37 ) ;
for ( V_95 = 0 ; V_95 < V_2 -> V_23 ; V_95 ++ )
F_96 ( V_2 -> V_96 [ V_95 ] ) ;
F_112 ( V_3 , NULL ) ;
F_114 ( V_2 ) ;
}
F_70 ( V_3 ) ;
}
