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
V_45 | V_46 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_47 = F_23 ;
if ( V_10 -> V_2 -> V_3 -> V_48 == V_49 )
V_10 -> V_11 -> V_50 = 1000 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
V_10 -> V_51 = NULL ;
V_10 -> V_52 = 0 ;
V_10 -> V_53 = true ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 )
{
if ( ( F_32 ( V_10 -> V_2 -> V_3 -> V_54 ) != V_55 ) &&
( F_32 ( V_10 -> V_2 -> V_3 -> V_54 ) != V_56 ) )
return - V_57 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_46 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_58 )
{
T_2 V_59 ;
int V_60 ;
V_60 = F_34 ( V_2 -> V_3 , 0xAE , & V_59 ) ;
if ( V_60 )
return V_60 ;
if ( V_58 )
V_59 |= 0x47 ;
else
V_59 &= ~ 0x47 ;
V_60 = F_35 ( V_2 -> V_3 , 0xAE , V_59 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_60 ;
T_3 V_61 = 0 ;
if ( V_2 -> V_3 -> V_62 == 0 ) {
V_2 -> V_7 |= V_63 |
V_64 |
V_65 |
V_66 |
V_67 ;
}
if ( V_2 -> V_3 -> V_48 == V_68 )
V_61 = V_69 ;
else if ( V_2 -> V_3 -> V_48 == V_70 )
V_61 = V_71 ;
if ( V_61 ) {
struct V_72 * V_73 ;
V_73 = NULL ;
while ( ( V_73 = F_37 ( V_74 ,
V_61 , V_73 ) ) != NULL ) {
if ( ( F_38 ( V_2 -> V_3 -> V_54 ) ==
F_38 ( V_73 -> V_54 ) ) &&
( V_2 -> V_3 -> V_75 == V_73 -> V_75 ) )
break;
}
if ( V_73 ) {
F_39 ( V_73 ) ;
F_40 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_57 ;
}
}
V_60 = F_33 ( V_2 , 1 ) ;
if ( V_60 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_60 ;
}
if ( V_2 -> V_3 -> V_48 == V_70 ||
V_2 -> V_3 -> V_48 == V_71 )
V_2 -> V_7 |= V_76 ;
return 0 ;
}
static void F_42 ( struct V_26 * V_11 , int V_58 )
{
T_2 V_59 ;
V_59 = F_43 ( V_11 -> V_77 + 0xC0 ) ;
if ( V_58 )
V_59 |= 0x01 ;
else
V_59 &= ~ 0x01 ;
F_44 ( V_59 , V_11 -> V_77 + 0xC0 ) ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_62 == 0 ) {
T_3 V_78 ;
V_78 = F_46 ( V_10 -> V_11 -> V_77 + V_79 ) ;
V_78 = ( V_78 & V_80 ) >>
V_81 ;
if ( V_78 < 0xAC )
V_10 -> V_11 -> V_7 |= V_82 ;
}
if ( V_10 -> V_2 -> V_3 -> V_48 == V_71 ) {
V_10 -> V_11 -> V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 ;
V_10 -> V_11 -> V_89 = V_84 | V_85 |
V_86 | V_87 ;
}
if ( V_10 -> V_2 -> V_3 -> V_48 == V_69 ||
V_10 -> V_2 -> V_3 -> V_48 == V_71 )
F_42 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_90 ;
return 0 ;
}
static void F_47 ( struct V_9 * V_10 , int V_91 )
{
if ( V_91 )
return;
if ( V_10 -> V_2 -> V_3 -> V_48 == V_69 ||
V_10 -> V_2 -> V_3 -> V_48 == V_71 )
F_42 ( V_10 -> V_11 , 0 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_3 -> V_48 == V_69 ||
V_2 -> V_3 -> V_48 == V_71 ) {
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ )
F_42 ( V_2 -> V_93 [ V_92 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_60 , V_92 ;
if ( V_2 -> V_3 -> V_48 == V_69 ||
V_2 -> V_3 -> V_48 == V_71 ) {
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ )
F_42 ( V_2 -> V_93 [ V_92 ] -> V_11 , 1 ) ;
}
V_60 = F_33 ( V_2 , 1 ) ;
if ( V_60 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_60 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_94 & 0x0000FF ) == V_95 ) {
V_2 -> V_3 -> V_94 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_94 |= V_96 ;
}
return 0 ;
}
static int F_51 ( struct V_9 * V_10 )
{
int V_97 , V_98 ;
T_2 V_99 = F_43 ( V_10 -> V_11 -> V_77 + V_100 ) ;
T_2 V_101 = F_43 ( V_10 -> V_11 -> V_77 + V_102 ) ;
F_40 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_99 >> 4 , V_99 & 0xf ,
V_101 >> 4 , V_101 & 0xf ) ;
if ( V_101 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_103 ;
F_44 ( V_104 , V_10 -> V_11 -> V_77 + V_105 ) ;
F_44 ( V_106 , V_10 -> V_11 -> V_77 + V_107 ) ;
F_26 ( 50 ) ;
V_97 = 10 ;
do {
V_98 = F_52 ( V_10 -> V_11 -> V_77 + V_108 ) ;
if ( V_98 & V_109 )
break;
F_26 ( 100 ) ;
} while ( -- V_97 );
if ( ! V_97 ) {
F_41 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_44 ( 0 , V_10 -> V_11 -> V_77 + V_107 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_62 == 0x10 )
V_2 -> V_7 |= V_110 ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_111 ;
return 0 ;
}
static int F_55 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_72 * V_3 ;
int V_60 ;
V_10 = F_56 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_94 & 0xFFFF00 ) == ( V_112 << 8 ) ) &&
( ( V_3 -> V_94 & 0x0000FF ) != V_96 ) &&
( V_11 -> V_113 & V_114 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
V_60 = F_57 ( V_3 , F_58 ( 32 ) ) ;
if ( V_60 )
return V_60 ;
F_59 ( V_3 ) ;
return 0 ;
}
static void F_60 ( struct V_26 * V_11 , int V_115 )
{
T_2 V_116 ;
V_116 = F_24 ( V_11 , V_117 ) ;
switch ( V_115 ) {
case V_118 :
V_116 |= V_119 ;
V_116 &= ~ V_120 ;
break;
case V_121 :
V_116 |= V_120 ;
V_116 &= ~ V_119 ;
break;
default:
V_116 &= ~ ( V_119 | V_120 ) ;
break;
}
F_25 ( V_11 , V_116 , V_117 ) ;
}
static void F_61 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_56 ( V_11 ) ;
int V_122 = V_10 -> V_122 ;
if ( ! F_12 ( V_122 ) )
return;
F_62 ( V_122 , 0 ) ;
F_26 ( 10 ) ;
F_62 ( V_122 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_63 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_56 ( V_11 ) ;
if ( V_10 -> V_47 )
V_10 -> V_47 ( V_11 ) ;
}
static int F_64 ( struct V_48 * V_37 )
{
struct V_72 * V_3 = F_65 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_123 ;
T_4 V_124 = 0 ;
int V_92 , V_60 ;
V_2 = F_66 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ ) {
V_10 = V_2 -> V_93 [ V_92 ] ;
if ( ! V_10 )
continue;
V_60 = F_67 ( V_10 -> V_11 ) ;
if ( V_60 )
goto V_125;
V_123 = V_10 -> V_11 -> V_21 -> V_124 ;
if ( V_123 & V_126 )
F_68 ( V_10 -> V_11 ) ;
V_124 |= V_123 ;
}
if ( V_2 -> V_127 && V_2 -> V_127 -> V_128 ) {
V_60 = V_2 -> V_127 -> V_128 ( V_2 ) ;
if ( V_60 )
goto V_125;
}
if ( V_124 & V_129 ) {
if ( V_124 & V_126 )
F_69 ( V_37 , true ) ;
else
F_69 ( V_37 , false ) ;
} else
F_69 ( V_37 , false ) ;
return 0 ;
V_125:
while ( -- V_92 >= 0 )
F_70 ( V_2 -> V_93 [ V_92 ] -> V_11 ) ;
return V_60 ;
}
static int F_71 ( struct V_48 * V_37 )
{
struct V_72 * V_3 = F_65 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_92 , V_60 ;
V_2 = F_66 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_127 && V_2 -> V_127 -> V_130 ) {
V_60 = V_2 -> V_127 -> V_130 ( V_2 ) ;
if ( V_60 )
return V_60 ;
}
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ ) {
V_10 = V_2 -> V_93 [ V_92 ] ;
if ( ! V_10 )
continue;
V_60 = F_70 ( V_10 -> V_11 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_72 ( struct V_48 * V_37 )
{
struct V_72 * V_3 = F_73 ( V_37 , struct V_72 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_92 , V_60 ;
V_2 = F_66 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ ) {
V_10 = V_2 -> V_93 [ V_92 ] ;
if ( ! V_10 )
continue;
V_60 = F_74 ( V_10 -> V_11 ) ;
if ( V_60 )
goto V_131;
}
if ( V_2 -> V_127 && V_2 -> V_127 -> V_128 ) {
V_60 = V_2 -> V_127 -> V_128 ( V_2 ) ;
if ( V_60 )
goto V_131;
}
return 0 ;
V_131:
while ( -- V_92 >= 0 )
F_75 ( V_2 -> V_93 [ V_92 ] -> V_11 ) ;
return V_60 ;
}
static int F_76 ( struct V_48 * V_37 )
{
struct V_72 * V_3 = F_73 ( V_37 , struct V_72 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_92 , V_60 ;
V_2 = F_66 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_127 && V_2 -> V_127 -> V_130 ) {
V_60 = V_2 -> V_127 -> V_130 ( V_2 ) ;
if ( V_60 )
return V_60 ;
}
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ ) {
V_10 = V_2 -> V_93 [ V_92 ] ;
if ( ! V_10 )
continue;
V_60 = F_75 ( V_10 -> V_11 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_77 ( struct V_48 * V_37 )
{
return 0 ;
}
static struct V_9 * F_78 (
struct V_72 * V_3 , struct V_1 * V_2 , int V_132 ,
int V_133 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_60 , V_134 = V_132 + V_133 ;
if ( ! ( F_79 ( V_3 , V_134 ) & V_135 ) ) {
F_41 ( & V_3 -> V_37 , L_11 , V_134 ) ;
return F_80 ( - V_57 ) ;
}
if ( F_81 ( V_3 , V_134 ) < 0x100 ) {
F_41 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_94 & 0x0000FF ) == V_95 ) {
F_41 ( & V_3 -> V_37 , L_14 ) ;
return F_80 ( - V_57 ) ;
}
if ( ( V_3 -> V_94 & 0x0000FF ) > V_95 ) {
F_41 ( & V_3 -> V_37 , L_15 ) ;
return F_80 ( - V_57 ) ;
}
V_11 = F_82 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_83 ( V_11 ) ) {
F_41 ( & V_3 -> V_37 , L_16 ) ;
return F_84 ( V_11 ) ;
}
V_10 = F_56 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_136 = V_134 ;
V_10 -> V_122 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_52 = - 1 ;
if ( * V_137 )
V_10 -> V_138 = V_137 ( V_3 , V_133 ) ;
if ( V_10 -> V_138 ) {
if ( V_10 -> V_138 -> V_139 ) {
V_60 = V_10 -> V_138 -> V_139 ( V_10 -> V_138 ) ;
if ( V_60 ) {
F_41 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_122 = V_10 -> V_138 -> V_122 ;
V_10 -> V_30 = V_10 -> V_138 -> V_30 ;
}
V_11 -> V_140 = L_18 ;
V_11 -> V_141 = & V_142 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_143 = V_2 -> V_143 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_60 = F_85 ( V_3 , V_134 , F_86 ( V_11 -> V_21 ) ) ;
if ( V_60 ) {
F_41 ( & V_3 -> V_37 , L_19 ) ;
goto V_144;
}
V_11 -> V_77 = F_87 ( V_3 , V_134 ) ;
if ( ! V_11 -> V_77 ) {
F_41 ( & V_3 -> V_37 , L_20 ) ;
V_60 = - V_145 ;
goto V_146;
}
if ( V_2 -> V_127 && V_2 -> V_127 -> V_147 ) {
V_60 = V_2 -> V_127 -> V_147 ( V_10 ) ;
if ( V_60 )
goto V_148;
}
if ( F_12 ( V_10 -> V_122 ) ) {
if ( ! F_13 ( V_10 -> V_122 , L_21 ) ) {
F_88 ( V_10 -> V_122 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_45 ;
V_10 -> V_47 = F_61 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_122 = - V_31 ;
}
}
V_11 -> V_21 -> V_149 = V_129 | V_126 ;
V_11 -> V_21 -> V_133 = V_133 ;
V_11 -> V_21 -> V_39 |= V_150 ;
if ( V_10 -> V_52 >= 0 &&
F_89 ( V_11 -> V_21 , V_10 -> V_51 , V_10 -> V_52 ,
V_10 -> V_53 , 0 , NULL ) ) {
F_18 ( & V_3 -> V_37 , L_23 ) ;
V_10 -> V_52 = - 1 ;
}
V_60 = F_90 ( V_11 ) ;
if ( V_60 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_127 && V_2 -> V_127 -> V_151 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_52 < 0 )
V_2 -> V_152 = false ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_122 ) )
F_17 ( V_10 -> V_122 ) ;
if ( V_2 -> V_127 && V_2 -> V_127 -> V_153 )
V_2 -> V_127 -> V_153 ( V_10 , 0 ) ;
V_148:
F_91 ( V_11 -> V_77 ) ;
V_146:
F_92 ( V_3 , V_134 ) ;
V_144:
if ( V_10 -> V_138 && V_10 -> V_138 -> V_144 )
V_10 -> V_138 -> V_144 ( V_10 -> V_138 ) ;
free:
F_93 ( V_11 ) ;
return F_80 ( V_60 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
int V_91 ;
T_5 V_59 ;
F_19 ( V_10 ) ;
V_91 = 0 ;
V_59 = F_46 ( V_10 -> V_11 -> V_77 + V_154 ) ;
if ( V_59 == ( T_5 ) - 1 )
V_91 = 1 ;
F_95 ( V_10 -> V_11 , V_91 ) ;
if ( F_12 ( V_10 -> V_122 ) )
F_17 ( V_10 -> V_122 ) ;
if ( V_10 -> V_2 -> V_127 && V_10 -> V_2 -> V_127 -> V_153 )
V_10 -> V_2 -> V_127 -> V_153 ( V_10 , V_91 ) ;
if ( V_10 -> V_138 && V_10 -> V_138 -> V_144 )
V_10 -> V_138 -> V_144 ( V_10 -> V_138 ) ;
F_92 ( V_10 -> V_2 -> V_3 , V_10 -> V_136 ) ;
F_93 ( V_10 -> V_11 ) ;
}
static void F_96 ( struct V_48 * V_37 )
{
F_97 ( V_37 ) ;
F_98 ( V_37 ) ;
F_99 ( V_37 , 50 ) ;
F_100 ( V_37 ) ;
F_101 ( V_37 , 1 ) ;
}
static void F_102 ( struct V_48 * V_37 )
{
F_103 ( V_37 ) ;
F_104 ( V_37 ) ;
}
static int F_105 ( struct V_72 * V_3 ,
const struct V_155 * V_156 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_93 , V_132 ;
int V_60 , V_92 ;
F_106 ( V_3 == NULL ) ;
F_106 ( V_156 == NULL ) ;
F_40 ( & V_3 -> V_37 , L_24 ,
( int ) V_3 -> V_157 , ( int ) V_3 -> V_48 , ( int ) V_3 -> V_62 ) ;
V_60 = F_34 ( V_3 , V_158 , & V_93 ) ;
if ( V_60 )
return V_60 ;
V_93 = F_107 ( V_93 ) + 1 ;
F_108 ( & V_3 -> V_37 , L_25 , V_93 ) ;
if ( V_93 == 0 )
return - V_57 ;
F_106 ( V_93 > V_159 ) ;
V_60 = F_34 ( V_3 , V_158 , & V_132 ) ;
if ( V_60 )
return V_60 ;
V_132 &= V_160 ;
if ( V_132 > 5 ) {
F_41 ( & V_3 -> V_37 , L_26 ) ;
return - V_57 ;
}
V_60 = F_109 ( V_3 ) ;
if ( V_60 )
return V_60 ;
V_2 = F_110 ( sizeof( struct V_1 ) , V_161 ) ;
if ( ! V_2 ) {
V_60 = - V_145 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_127 = ( const struct V_162 * ) V_156 -> V_163 ;
if ( V_2 -> V_127 ) {
V_2 -> V_7 = V_2 -> V_127 -> V_7 ;
V_2 -> V_143 = V_2 -> V_127 -> V_143 ;
V_2 -> V_152 = V_2 -> V_127 -> V_152 ;
}
V_2 -> V_23 = V_93 ;
F_111 ( V_3 , V_2 ) ;
if ( V_2 -> V_127 && V_2 -> V_127 -> V_164 ) {
V_60 = V_2 -> V_127 -> V_164 ( V_2 ) ;
if ( V_60 )
goto free;
}
V_93 = V_2 -> V_23 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_10 = F_78 ( V_3 , V_2 , V_132 , V_92 ) ;
if ( F_83 ( V_10 ) ) {
for ( V_92 -- ; V_92 >= 0 ; V_92 -- )
F_94 ( V_2 -> V_93 [ V_92 ] ) ;
V_60 = F_112 ( V_10 ) ;
goto free;
}
V_2 -> V_93 [ V_92 ] = V_10 ;
}
if ( V_2 -> V_152 )
F_96 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_111 ( V_3 , NULL ) ;
F_113 ( V_2 ) ;
V_28:
F_114 ( V_3 ) ;
return V_60 ;
}
static void F_115 ( struct V_72 * V_3 )
{
int V_92 ;
struct V_1 * V_2 ;
V_2 = F_66 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_152 )
F_102 ( & V_3 -> V_37 ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_23 ; V_92 ++ )
F_94 ( V_2 -> V_93 [ V_92 ] ) ;
F_111 ( V_3 , NULL ) ;
F_113 ( V_2 ) ;
}
F_114 ( V_3 ) ;
}
