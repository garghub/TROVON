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
static int F_23 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_43 ;
T_2 V_44 ;
switch ( V_2 -> V_3 -> V_45 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_43 = F_26 ( V_2 -> V_3 , V_50 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_44 &= 0x7f ;
F_27 ( V_2 -> V_3 , V_50 , V_44 ) ;
F_27 ( V_2 -> V_3 , V_51 , 0x08 ) ;
V_43 = F_26 ( V_2 -> V_3 , V_52 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_44 |= 0x20 ;
F_27 ( V_2 -> V_3 , V_52 , V_44 ) ;
V_43 = F_26 ( V_2 -> V_3 , V_53 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_44 |= 0x01 ;
F_27 ( V_2 -> V_3 , V_53 , V_44 ) ;
F_27 ( V_2 -> V_3 , V_53 , 0x73 ) ;
F_27 ( V_2 -> V_3 , V_54 , 0x39 ) ;
F_27 ( V_2 -> V_3 , V_55 , 0x08 ) ;
V_43 = F_26 ( V_2 -> V_3 , V_56 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_44 |= 0x08 ;
F_27 ( V_2 -> V_3 , V_56 , V_44 ) ;
V_43 = F_26 ( V_2 -> V_3 , V_50 , & V_44 ) ;
if ( V_43 )
return V_43 ;
V_44 |= 0x80 ;
F_27 ( V_2 -> V_3 , V_50 , V_44 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_57 )
{
T_2 V_44 ;
int V_43 ;
V_43 = F_26 ( V_2 -> V_3 , 0xAE , & V_44 ) ;
if ( V_43 )
return V_43 ;
if ( V_57 )
V_44 |= 0x47 ;
else
V_44 &= ~ 0x47 ;
V_43 = F_27 ( V_2 -> V_3 , 0xAE , V_44 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_43 ;
T_3 V_58 = 0 ;
if ( V_2 -> V_3 -> V_59 == 0 ) {
V_2 -> V_7 |= V_60 |
V_61 |
V_62 |
V_63 |
V_64 ;
}
if ( V_2 -> V_3 -> V_45 == V_65 )
V_58 = V_66 ;
else if ( V_2 -> V_3 -> V_45 == V_67 )
V_58 = V_68 ;
if ( V_58 ) {
struct V_69 * V_70 ;
V_70 = NULL ;
while ( ( V_70 = F_30 ( V_71 ,
V_58 , V_70 ) ) != NULL ) {
if ( ( F_31 ( V_2 -> V_3 -> V_72 ) ==
F_31 ( V_70 -> V_72 ) ) &&
( V_2 -> V_3 -> V_73 == V_70 -> V_73 ) )
break;
}
if ( V_70 ) {
F_32 ( V_70 ) ;
F_33 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_74 ;
}
}
V_43 = F_28 ( V_2 , 1 ) ;
if ( V_43 ) {
F_34 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_43 ;
}
if ( V_2 -> V_3 -> V_45 == V_67 ||
V_2 -> V_3 -> V_45 == V_68 )
V_2 -> V_7 |= V_75 ;
return 0 ;
}
static void F_35 ( struct V_26 * V_11 , int V_57 )
{
T_2 V_44 ;
V_44 = F_36 ( V_11 -> V_76 + 0xC0 ) ;
if ( V_57 )
V_44 |= 0x01 ;
else
V_44 &= ~ 0x01 ;
F_37 ( V_44 , V_11 -> V_76 + 0xC0 ) ;
}
static int F_38 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_59 == 0 ) {
T_3 V_77 ;
V_77 = F_39 ( V_10 -> V_11 -> V_76 + V_78 ) ;
V_77 = ( V_77 & V_79 ) >>
V_80 ;
if ( V_77 < 0xAC )
V_10 -> V_11 -> V_7 |= V_81 ;
}
if ( V_10 -> V_2 -> V_3 -> V_45 == V_68 ) {
V_10 -> V_11 -> V_82 = V_83 | V_84 |
V_85 | V_86 |
V_87 ;
V_10 -> V_11 -> V_88 = V_83 | V_84 |
V_85 | V_86 ;
}
if ( V_10 -> V_2 -> V_3 -> V_45 == V_66 ||
V_10 -> V_2 -> V_3 -> V_45 == V_68 )
F_35 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_89 ;
return 0 ;
}
static void F_40 ( struct V_9 * V_10 , int V_90 )
{
if ( V_90 )
return;
if ( V_10 -> V_2 -> V_3 -> V_45 == V_66 ||
V_10 -> V_2 -> V_3 -> V_45 == V_68 )
F_35 ( V_10 -> V_11 , 0 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_91 ;
if ( V_2 -> V_3 -> V_45 == V_66 ||
V_2 -> V_3 -> V_45 == V_68 ) {
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ )
F_35 ( V_2 -> V_92 [ V_91 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_43 , V_91 ;
if ( V_2 -> V_3 -> V_45 == V_66 ||
V_2 -> V_3 -> V_45 == V_68 ) {
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ )
F_35 ( V_2 -> V_92 [ V_91 ] -> V_11 , 1 ) ;
}
V_43 = F_28 ( V_2 , 1 ) ;
if ( V_43 ) {
F_34 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_43 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_93 & 0x0000FF ) == V_94 ) {
V_2 -> V_3 -> V_93 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_93 |= V_95 ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
int V_96 , V_97 ;
T_2 V_98 = F_36 ( V_10 -> V_11 -> V_76 + V_99 ) ;
T_2 V_100 = F_36 ( V_10 -> V_11 -> V_76 + V_101 ) ;
F_33 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_98 >> 4 , V_98 & 0xf ,
V_100 >> 4 , V_100 & 0xf ) ;
if ( V_100 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_102 ;
F_37 ( V_103 , V_10 -> V_11 -> V_76 + V_104 ) ;
F_37 ( V_105 , V_10 -> V_11 -> V_76 + V_106 ) ;
F_45 ( 50 ) ;
V_96 = 10 ;
do {
V_97 = F_46 ( V_10 -> V_11 -> V_76 + V_107 ) ;
if ( V_97 & V_108 )
break;
F_45 ( 100 ) ;
} while ( -- V_96 );
if ( ! V_96 ) {
F_34 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_37 ( 0 , V_10 -> V_11 -> V_76 + V_106 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_59 == 0x10 )
V_2 -> V_7 |= V_109 ;
return 0 ;
}
static int F_48 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_69 * V_3 ;
int V_43 ;
V_10 = F_49 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_93 & 0xFFFF00 ) == ( V_110 << 8 ) ) &&
( ( V_3 -> V_93 & 0x0000FF ) != V_95 ) &&
( V_11 -> V_111 & V_112 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
V_43 = F_50 ( V_3 , F_51 ( 32 ) ) ;
if ( V_43 )
return V_43 ;
F_52 ( V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_26 * V_11 , int V_113 )
{
T_2 V_114 ;
V_114 = F_54 ( V_11 , V_115 ) ;
switch ( V_113 ) {
case V_116 :
V_114 |= V_117 ;
V_114 &= ~ V_118 ;
break;
case V_119 :
V_114 |= V_118 ;
V_114 &= ~ V_117 ;
break;
default:
V_114 &= ~ ( V_117 | V_118 ) ;
break;
}
F_55 ( V_11 , V_114 , V_115 ) ;
return 0 ;
}
static void F_56 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_49 ( V_11 ) ;
int V_120 = V_10 -> V_120 ;
if ( ! F_12 ( V_120 ) )
return;
F_57 ( V_120 , 0 ) ;
F_45 ( 10 ) ;
F_57 ( V_120 , 1 ) ;
F_58 ( 300 , 1000 ) ;
}
static int F_59 ( struct V_45 * V_37 )
{
struct V_69 * V_3 = F_60 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_121 ;
T_4 V_122 = 0 ;
int V_91 , V_43 ;
V_2 = F_61 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ ) {
V_10 = V_2 -> V_92 [ V_91 ] ;
if ( ! V_10 )
continue;
V_43 = F_62 ( V_10 -> V_11 ) ;
if ( V_43 )
goto V_123;
V_121 = V_10 -> V_11 -> V_21 -> V_122 ;
if ( V_121 & V_124 )
F_63 ( V_10 -> V_11 ) ;
V_122 |= V_121 ;
}
if ( V_2 -> V_125 && V_2 -> V_125 -> V_126 ) {
V_43 = V_2 -> V_125 -> V_126 ( V_2 ) ;
if ( V_43 )
goto V_123;
}
F_64 ( V_3 ) ;
if ( V_122 & V_127 ) {
if ( V_122 & V_124 ) {
F_65 ( V_3 , true ) ;
F_66 ( V_3 , V_128 , 1 ) ;
}
F_67 ( V_3 , V_128 ) ;
} else {
F_66 ( V_3 , V_128 , 0 ) ;
F_68 ( V_3 ) ;
F_67 ( V_3 , V_128 ) ;
}
return 0 ;
V_123:
while ( -- V_91 >= 0 )
F_69 ( V_2 -> V_92 [ V_91 ] -> V_11 ) ;
return V_43 ;
}
static int F_70 ( struct V_45 * V_37 )
{
struct V_69 * V_3 = F_60 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_91 , V_43 ;
V_2 = F_61 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_67 ( V_3 , V_129 ) ;
F_71 ( V_3 ) ;
V_43 = F_72 ( V_3 ) ;
if ( V_43 )
return V_43 ;
if ( V_2 -> V_125 && V_2 -> V_125 -> V_130 ) {
V_43 = V_2 -> V_125 -> V_130 ( V_2 ) ;
if ( V_43 )
return V_43 ;
}
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ ) {
V_10 = V_2 -> V_92 [ V_91 ] ;
if ( ! V_10 )
continue;
V_43 = F_69 ( V_10 -> V_11 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_73 ( struct V_45 * V_37 )
{
struct V_69 * V_3 = F_74 ( V_37 , struct V_69 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_91 , V_43 ;
V_2 = F_61 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ ) {
V_10 = V_2 -> V_92 [ V_91 ] ;
if ( ! V_10 )
continue;
V_43 = F_75 ( V_10 -> V_11 ) ;
if ( V_43 )
goto V_131;
}
if ( V_2 -> V_125 && V_2 -> V_125 -> V_126 ) {
V_43 = V_2 -> V_125 -> V_126 ( V_2 ) ;
if ( V_43 )
goto V_131;
}
return 0 ;
V_131:
while ( -- V_91 >= 0 )
F_76 ( V_2 -> V_92 [ V_91 ] -> V_11 ) ;
return V_43 ;
}
static int F_77 ( struct V_45 * V_37 )
{
struct V_69 * V_3 = F_74 ( V_37 , struct V_69 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_91 , V_43 ;
V_2 = F_61 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_125 && V_2 -> V_125 -> V_130 ) {
V_43 = V_2 -> V_125 -> V_130 ( V_2 ) ;
if ( V_43 )
return V_43 ;
}
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ ) {
V_10 = V_2 -> V_92 [ V_91 ] ;
if ( ! V_10 )
continue;
V_43 = F_76 ( V_10 -> V_11 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_78 ( struct V_45 * V_37 )
{
return 0 ;
}
static struct V_9 * F_79 (
struct V_69 * V_3 , struct V_1 * V_2 , int V_132 ,
int V_133 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_43 , V_134 = V_132 + V_133 ;
if ( ! ( F_80 ( V_3 , V_134 ) & V_135 ) ) {
F_34 ( & V_3 -> V_37 , L_11 , V_134 ) ;
return F_81 ( - V_74 ) ;
}
if ( F_82 ( V_3 , V_134 ) < 0x100 ) {
F_34 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_93 & 0x0000FF ) == V_94 ) {
F_34 ( & V_3 -> V_37 , L_14 ) ;
return F_81 ( - V_74 ) ;
}
if ( ( V_3 -> V_93 & 0x0000FF ) > V_94 ) {
F_34 ( & V_3 -> V_37 , L_15 ) ;
return F_81 ( - V_74 ) ;
}
V_11 = F_83 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_84 ( V_11 ) ) {
F_34 ( & V_3 -> V_37 , L_16 ) ;
return F_85 ( V_11 ) ;
}
V_10 = F_49 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_136 = V_134 ;
V_10 -> V_120 = - V_31 ;
V_10 -> V_30 = - V_31 ;
if ( * V_137 )
V_10 -> V_138 = V_137 ( V_3 , V_133 ) ;
if ( V_10 -> V_138 ) {
if ( V_10 -> V_138 -> V_139 ) {
V_43 = V_10 -> V_138 -> V_139 ( V_10 -> V_138 ) ;
if ( V_43 ) {
F_34 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_120 = V_10 -> V_138 -> V_120 ;
V_10 -> V_30 = V_10 -> V_138 -> V_30 ;
}
V_11 -> V_140 = L_18 ;
V_11 -> V_141 = & V_142 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_143 = V_2 -> V_143 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_43 = F_86 ( V_3 , V_134 , F_87 ( V_11 -> V_21 ) ) ;
if ( V_43 ) {
F_34 ( & V_3 -> V_37 , L_19 ) ;
goto V_144;
}
V_11 -> V_76 = F_88 ( V_3 , V_134 ) ;
if ( ! V_11 -> V_76 ) {
F_34 ( & V_3 -> V_37 , L_20 ) ;
V_43 = - V_145 ;
goto V_146;
}
if ( V_2 -> V_125 && V_2 -> V_125 -> V_147 ) {
V_43 = V_2 -> V_125 -> V_147 ( V_10 ) ;
if ( V_43 )
goto V_148;
}
if ( F_12 ( V_10 -> V_120 ) ) {
if ( ! F_13 ( V_10 -> V_120 , L_21 ) ) {
F_89 ( V_10 -> V_120 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_149 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_120 = - V_31 ;
}
}
V_11 -> V_21 -> V_150 = V_127 | V_124 ;
V_11 -> V_21 -> V_133 = V_133 ;
V_11 -> V_21 -> V_39 |= V_151 ;
V_43 = F_90 ( V_11 ) ;
if ( V_43 )
goto remove;
F_11 ( V_10 ) ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_120 ) )
F_17 ( V_10 -> V_120 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 -> V_152 )
V_2 -> V_125 -> V_152 ( V_10 , 0 ) ;
V_148:
F_91 ( V_11 -> V_76 ) ;
V_146:
F_92 ( V_3 , V_134 ) ;
V_144:
if ( V_10 -> V_138 && V_10 -> V_138 -> V_144 )
V_10 -> V_138 -> V_144 ( V_10 -> V_138 ) ;
free:
F_93 ( V_11 ) ;
return F_81 ( V_43 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
int V_90 ;
T_5 V_44 ;
F_19 ( V_10 ) ;
V_90 = 0 ;
V_44 = F_39 ( V_10 -> V_11 -> V_76 + V_153 ) ;
if ( V_44 == ( T_5 ) - 1 )
V_90 = 1 ;
F_95 ( V_10 -> V_11 , V_90 ) ;
if ( F_12 ( V_10 -> V_120 ) )
F_17 ( V_10 -> V_120 ) ;
if ( V_10 -> V_2 -> V_125 && V_10 -> V_2 -> V_125 -> V_152 )
V_10 -> V_2 -> V_125 -> V_152 ( V_10 , V_90 ) ;
if ( V_10 -> V_138 && V_10 -> V_138 -> V_144 )
V_10 -> V_138 -> V_144 ( V_10 -> V_138 ) ;
F_92 ( V_10 -> V_2 -> V_3 , V_10 -> V_136 ) ;
F_93 ( V_10 -> V_11 ) ;
}
static void F_96 ( struct V_45 * V_37 )
{
F_97 ( V_37 ) ;
F_98 ( V_37 ) ;
F_99 ( V_37 , 50 ) ;
F_100 ( V_37 ) ;
F_101 ( V_37 , 1 ) ;
}
static void F_102 ( struct V_45 * V_37 )
{
F_103 ( V_37 ) ;
F_104 ( V_37 ) ;
}
static int F_105 ( struct V_69 * V_3 ,
const struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_92 , V_132 ;
int V_43 , V_91 ;
F_106 ( V_3 == NULL ) ;
F_106 ( V_155 == NULL ) ;
F_33 ( & V_3 -> V_37 , L_23 ,
( int ) V_3 -> V_156 , ( int ) V_3 -> V_45 , ( int ) V_3 -> V_59 ) ;
V_43 = F_26 ( V_3 , V_157 , & V_92 ) ;
if ( V_43 )
return V_43 ;
V_92 = F_107 ( V_92 ) + 1 ;
F_108 ( & V_3 -> V_37 , L_24 , V_92 ) ;
if ( V_92 == 0 )
return - V_74 ;
F_106 ( V_92 > V_158 ) ;
V_43 = F_26 ( V_3 , V_157 , & V_132 ) ;
if ( V_43 )
return V_43 ;
V_132 &= V_159 ;
if ( V_132 > 5 ) {
F_34 ( & V_3 -> V_37 , L_25 ) ;
return - V_74 ;
}
V_43 = F_72 ( V_3 ) ;
if ( V_43 )
return V_43 ;
V_2 = F_109 ( sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_2 ) {
V_43 = - V_145 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_125 = ( const struct V_161 * ) V_155 -> V_162 ;
if ( V_2 -> V_125 ) {
V_2 -> V_7 = V_2 -> V_125 -> V_7 ;
V_2 -> V_143 = V_2 -> V_125 -> V_143 ;
V_2 -> V_163 = V_2 -> V_125 -> V_163 ;
}
V_2 -> V_23 = V_92 ;
F_110 ( V_3 , V_2 ) ;
if ( V_2 -> V_125 && V_2 -> V_125 -> V_164 ) {
V_43 = V_2 -> V_125 -> V_164 ( V_2 ) ;
if ( V_43 )
goto free;
}
V_92 = V_2 -> V_23 ;
for ( V_91 = 0 ; V_91 < V_92 ; V_91 ++ ) {
V_10 = F_79 ( V_3 , V_2 , V_132 , V_91 ) ;
if ( F_84 ( V_10 ) ) {
for ( V_91 -- ; V_91 >= 0 ; V_91 -- )
F_94 ( V_2 -> V_92 [ V_91 ] ) ;
V_43 = F_111 ( V_10 ) ;
goto free;
}
V_2 -> V_92 [ V_91 ] = V_10 ;
}
if ( V_2 -> V_163 )
F_96 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_110 ( V_3 , NULL ) ;
F_112 ( V_2 ) ;
V_28:
F_68 ( V_3 ) ;
return V_43 ;
}
static void F_113 ( struct V_69 * V_3 )
{
int V_91 ;
struct V_1 * V_2 ;
V_2 = F_61 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_163 )
F_102 ( & V_3 -> V_37 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_23 ; V_91 ++ )
F_94 ( V_2 -> V_92 [ V_91 ] ) ;
F_110 ( V_3 , NULL ) ;
F_112 ( V_2 ) ;
}
F_68 ( V_3 ) ;
}
