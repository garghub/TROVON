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
V_45 | V_46 |
V_47 |
V_48 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_49 = F_23 ;
if ( V_10 -> V_2 -> V_3 -> V_50 == V_51 )
V_10 -> V_11 -> V_52 = 1000 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_47 |
V_48 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_47 |
V_48 ;
V_10 -> V_53 = NULL ;
V_10 -> V_54 = 0 ;
V_10 -> V_55 = true ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 )
{
if ( ( F_32 ( V_10 -> V_2 -> V_3 -> V_56 ) != V_57 ) &&
( F_32 ( V_10 -> V_2 -> V_3 -> V_56 ) != V_58 ) )
return - V_59 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_46 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_60 )
{
T_2 V_61 ;
int V_62 ;
V_62 = F_34 ( V_2 -> V_3 , 0xAE , & V_61 ) ;
if ( V_62 )
return V_62 ;
if ( V_60 )
V_61 |= 0x47 ;
else
V_61 &= ~ 0x47 ;
V_62 = F_35 ( V_2 -> V_3 , 0xAE , V_61 ) ;
if ( V_62 )
return V_62 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_62 ;
T_3 V_63 = 0 ;
if ( V_2 -> V_3 -> V_64 == 0 ) {
V_2 -> V_7 |= V_65 |
V_66 |
V_67 |
V_68 |
V_69 ;
}
if ( V_2 -> V_3 -> V_50 == V_70 )
V_63 = V_71 ;
else if ( V_2 -> V_3 -> V_50 == V_72 )
V_63 = V_73 ;
if ( V_63 ) {
struct V_74 * V_75 ;
V_75 = NULL ;
while ( ( V_75 = F_37 ( V_76 ,
V_63 , V_75 ) ) != NULL ) {
if ( ( F_38 ( V_2 -> V_3 -> V_56 ) ==
F_38 ( V_75 -> V_56 ) ) &&
( V_2 -> V_3 -> V_77 == V_75 -> V_77 ) )
break;
}
if ( V_75 ) {
F_39 ( V_75 ) ;
F_40 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_59 ;
}
}
V_62 = F_33 ( V_2 , 1 ) ;
if ( V_62 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_62 ;
}
if ( V_2 -> V_3 -> V_50 == V_72 ||
V_2 -> V_3 -> V_50 == V_73 )
V_2 -> V_7 |= V_78 ;
return 0 ;
}
static void F_42 ( struct V_26 * V_11 , int V_60 )
{
T_2 V_61 ;
V_61 = F_43 ( V_11 -> V_79 + 0xC0 ) ;
if ( V_60 )
V_61 |= 0x01 ;
else
V_61 &= ~ 0x01 ;
F_44 ( V_61 , V_11 -> V_79 + 0xC0 ) ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_64 == 0 ) {
T_3 V_80 ;
V_80 = F_46 ( V_10 -> V_11 -> V_79 + V_81 ) ;
V_80 = ( V_80 & V_82 ) >>
V_83 ;
if ( V_80 < 0xAC )
V_10 -> V_11 -> V_7 |= V_84 ;
}
if ( V_10 -> V_2 -> V_3 -> V_50 == V_73 ) {
V_10 -> V_11 -> V_85 = V_86 | V_87 |
V_88 | V_89 |
V_90 ;
V_10 -> V_11 -> V_91 = V_86 | V_87 |
V_88 | V_89 ;
}
if ( V_10 -> V_2 -> V_3 -> V_50 == V_71 ||
V_10 -> V_2 -> V_3 -> V_50 == V_73 )
F_42 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_47 ;
return 0 ;
}
static void F_47 ( struct V_9 * V_10 , int V_92 )
{
if ( V_92 )
return;
if ( V_10 -> V_2 -> V_3 -> V_50 == V_71 ||
V_10 -> V_2 -> V_3 -> V_50 == V_73 )
F_42 ( V_10 -> V_11 , 0 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_93 ;
if ( V_2 -> V_3 -> V_50 == V_71 ||
V_2 -> V_3 -> V_50 == V_73 ) {
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ )
F_42 ( V_2 -> V_94 [ V_93 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_62 , V_93 ;
if ( V_2 -> V_3 -> V_50 == V_71 ||
V_2 -> V_3 -> V_50 == V_73 ) {
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ )
F_42 ( V_2 -> V_94 [ V_93 ] -> V_11 , 1 ) ;
}
V_62 = F_33 ( V_2 , 1 ) ;
if ( V_62 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_62 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_95 & 0x0000FF ) == V_96 ) {
V_2 -> V_3 -> V_95 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_95 |= V_97 ;
}
return 0 ;
}
static int F_51 ( struct V_9 * V_10 )
{
int V_98 , V_99 ;
T_2 V_100 = F_43 ( V_10 -> V_11 -> V_79 + V_101 ) ;
T_2 V_102 = F_43 ( V_10 -> V_11 -> V_79 + V_103 ) ;
F_40 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_100 >> 4 , V_100 & 0xf ,
V_102 >> 4 , V_102 & 0xf ) ;
if ( V_102 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_104 ;
F_44 ( V_105 , V_10 -> V_11 -> V_79 + V_106 ) ;
F_44 ( V_107 , V_10 -> V_11 -> V_79 + V_108 ) ;
F_26 ( 50 ) ;
V_98 = 10 ;
do {
V_99 = F_52 ( V_10 -> V_11 -> V_79 + V_109 ) ;
if ( V_99 & V_110 )
break;
F_26 ( 100 ) ;
} while ( -- V_98 );
if ( ! V_98 ) {
F_41 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_44 ( 0 , V_10 -> V_11 -> V_79 + V_108 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_64 == 0x10 )
V_2 -> V_7 |= V_111 ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_112 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_74 * V_113 ;
V_113 = F_37 ( V_114 ,
V_115 , NULL ) ;
if ( V_113 && ( V_113 -> V_64 < 0x51 ) ) {
V_2 -> V_116 |= V_117 ;
V_2 -> V_116 |= V_118 ;
}
return 0 ;
}
static int F_56 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_74 * V_3 ;
int V_62 = - 1 ;
V_10 = F_57 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_95 & 0xFFFF00 ) == ( V_119 << 8 ) ) &&
( ( V_3 -> V_95 & 0x0000FF ) != V_97 ) &&
( V_11 -> V_120 & V_121 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
if ( V_11 -> V_120 & V_122 ) {
if ( V_11 -> V_116 & V_123 ) {
V_11 -> V_120 &= ~ V_122 ;
} else {
V_62 = F_58 ( V_3 , F_59 ( 64 ) ) ;
if ( V_62 )
F_18 ( & V_3 -> V_37 , L_11 ) ;
}
}
if ( V_62 )
V_62 = F_58 ( V_3 , F_59 ( 32 ) ) ;
if ( V_62 )
return V_62 ;
F_60 ( V_3 ) ;
return 0 ;
}
static void F_61 ( struct V_26 * V_11 , int V_124 )
{
T_2 V_125 ;
V_125 = F_24 ( V_11 , V_126 ) ;
switch ( V_124 ) {
case V_127 :
V_125 |= V_128 ;
V_125 &= ~ V_129 ;
break;
case V_130 :
V_125 |= V_129 ;
V_125 &= ~ V_128 ;
break;
default:
V_125 &= ~ ( V_128 | V_129 ) ;
break;
}
F_25 ( V_11 , V_125 , V_126 ) ;
}
static void F_62 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_57 ( V_11 ) ;
int V_131 = V_10 -> V_131 ;
if ( ! F_12 ( V_131 ) )
return;
F_63 ( V_131 , 0 ) ;
F_26 ( 10 ) ;
F_63 ( V_131 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_64 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_57 ( V_11 ) ;
if ( V_10 -> V_49 )
V_10 -> V_49 ( V_11 ) ;
}
static int F_65 ( struct V_50 * V_37 )
{
struct V_74 * V_3 = F_66 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_132 ;
T_4 V_133 = 0 ;
int V_93 , V_62 ;
V_2 = F_67 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ ) {
V_10 = V_2 -> V_94 [ V_93 ] ;
if ( ! V_10 )
continue;
V_62 = F_68 ( V_10 -> V_11 ) ;
if ( V_62 )
goto V_134;
V_132 = V_10 -> V_11 -> V_21 -> V_133 ;
if ( V_132 & V_135 )
F_69 ( V_10 -> V_11 ) ;
V_133 |= V_132 ;
}
if ( V_2 -> V_136 && V_2 -> V_136 -> V_137 ) {
V_62 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_62 )
goto V_134;
}
if ( V_133 & V_138 ) {
if ( V_133 & V_135 )
F_70 ( V_37 , true ) ;
else
F_70 ( V_37 , false ) ;
} else
F_70 ( V_37 , false ) ;
return 0 ;
V_134:
while ( -- V_93 >= 0 )
F_71 ( V_2 -> V_94 [ V_93 ] -> V_11 ) ;
return V_62 ;
}
static int F_72 ( struct V_50 * V_37 )
{
struct V_74 * V_3 = F_66 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_93 , V_62 ;
V_2 = F_67 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_139 ) {
V_62 = V_2 -> V_136 -> V_139 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ ) {
V_10 = V_2 -> V_94 [ V_93 ] ;
if ( ! V_10 )
continue;
V_62 = F_71 ( V_10 -> V_11 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_73 ( struct V_50 * V_37 )
{
struct V_74 * V_3 = F_74 ( V_37 , struct V_74 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_93 , V_62 ;
V_2 = F_67 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ ) {
V_10 = V_2 -> V_94 [ V_93 ] ;
if ( ! V_10 )
continue;
V_62 = F_75 ( V_10 -> V_11 ) ;
if ( V_62 )
goto V_140;
}
if ( V_2 -> V_136 && V_2 -> V_136 -> V_137 ) {
V_62 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_62 )
goto V_140;
}
return 0 ;
V_140:
while ( -- V_93 >= 0 )
F_76 ( V_2 -> V_94 [ V_93 ] -> V_11 ) ;
return V_62 ;
}
static int F_77 ( struct V_50 * V_37 )
{
struct V_74 * V_3 = F_74 ( V_37 , struct V_74 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_93 , V_62 ;
V_2 = F_67 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_139 ) {
V_62 = V_2 -> V_136 -> V_139 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ ) {
V_10 = V_2 -> V_94 [ V_93 ] ;
if ( ! V_10 )
continue;
V_62 = F_76 ( V_10 -> V_11 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static struct V_9 * F_78 (
struct V_74 * V_3 , struct V_1 * V_2 , int V_141 ,
int V_142 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_62 , V_143 = V_141 + V_142 ;
if ( ! ( F_79 ( V_3 , V_143 ) & V_144 ) ) {
F_41 ( & V_3 -> V_37 , L_12 , V_143 ) ;
return F_80 ( - V_59 ) ;
}
if ( F_81 ( V_3 , V_143 ) < 0x100 ) {
F_41 ( & V_3 -> V_37 , L_13
L_14 ) ;
}
if ( ( V_3 -> V_95 & 0x0000FF ) == V_96 ) {
F_41 ( & V_3 -> V_37 , L_15 ) ;
return F_80 ( - V_59 ) ;
}
if ( ( V_3 -> V_95 & 0x0000FF ) > V_96 ) {
F_41 ( & V_3 -> V_37 , L_16 ) ;
return F_80 ( - V_59 ) ;
}
V_11 = F_82 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_83 ( V_11 ) ) {
F_41 ( & V_3 -> V_37 , L_17 ) ;
return F_84 ( V_11 ) ;
}
V_10 = F_57 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_145 = V_143 ;
V_10 -> V_131 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_54 = - 1 ;
if ( * V_146 )
V_10 -> V_147 = V_146 ( V_3 , V_142 ) ;
if ( V_10 -> V_147 ) {
if ( V_10 -> V_147 -> V_148 ) {
V_62 = V_10 -> V_147 -> V_148 ( V_10 -> V_147 ) ;
if ( V_62 ) {
F_41 ( & V_3 -> V_37 , L_18 ) ;
goto free;
}
}
V_10 -> V_131 = V_10 -> V_147 -> V_131 ;
V_10 -> V_30 = V_10 -> V_147 -> V_30 ;
}
V_11 -> V_149 = L_19 ;
V_11 -> V_150 = & V_151 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_116 = V_2 -> V_116 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_62 = F_85 ( V_3 , V_143 , F_86 ( V_11 -> V_21 ) ) ;
if ( V_62 ) {
F_41 ( & V_3 -> V_37 , L_20 ) ;
goto V_152;
}
V_11 -> V_79 = F_87 ( V_3 , V_143 ) ;
if ( ! V_11 -> V_79 ) {
F_41 ( & V_3 -> V_37 , L_21 ) ;
V_62 = - V_153 ;
goto V_154;
}
if ( V_2 -> V_136 && V_2 -> V_136 -> V_155 ) {
V_62 = V_2 -> V_136 -> V_155 ( V_10 ) ;
if ( V_62 )
goto V_156;
}
if ( F_12 ( V_10 -> V_131 ) ) {
if ( ! F_13 ( V_10 -> V_131 , L_22 ) ) {
F_88 ( V_10 -> V_131 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_45 ;
V_10 -> V_49 = F_62 ;
} else {
F_18 ( & V_3 -> V_37 , L_23 ) ;
V_10 -> V_131 = - V_31 ;
}
}
V_11 -> V_21 -> V_157 = V_138 | V_135 ;
V_11 -> V_21 -> V_142 = V_142 ;
V_11 -> V_21 -> V_39 |= V_158 ;
if ( V_10 -> V_54 >= 0 &&
F_89 ( V_11 -> V_21 , V_10 -> V_53 , V_10 -> V_54 ,
V_10 -> V_55 , 0 , NULL ) ) {
F_18 ( & V_3 -> V_37 , L_24 ) ;
V_10 -> V_54 = - 1 ;
}
V_62 = F_90 ( V_11 ) ;
if ( V_62 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_159 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_54 < 0 )
V_2 -> V_160 = false ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_131 ) )
F_17 ( V_10 -> V_131 ) ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_161 )
V_2 -> V_136 -> V_161 ( V_10 , 0 ) ;
V_156:
F_91 ( V_11 -> V_79 ) ;
V_154:
F_92 ( V_3 , V_143 ) ;
V_152:
if ( V_10 -> V_147 && V_10 -> V_147 -> V_152 )
V_10 -> V_147 -> V_152 ( V_10 -> V_147 ) ;
free:
F_93 ( V_11 ) ;
return F_80 ( V_62 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
int V_92 ;
T_5 V_61 ;
F_19 ( V_10 ) ;
V_92 = 0 ;
V_61 = F_46 ( V_10 -> V_11 -> V_79 + V_162 ) ;
if ( V_61 == ( T_5 ) - 1 )
V_92 = 1 ;
F_95 ( V_10 -> V_11 , V_92 ) ;
if ( F_12 ( V_10 -> V_131 ) )
F_17 ( V_10 -> V_131 ) ;
if ( V_10 -> V_2 -> V_136 && V_10 -> V_2 -> V_136 -> V_161 )
V_10 -> V_2 -> V_136 -> V_161 ( V_10 , V_92 ) ;
if ( V_10 -> V_147 && V_10 -> V_147 -> V_152 )
V_10 -> V_147 -> V_152 ( V_10 -> V_147 ) ;
F_92 ( V_10 -> V_2 -> V_3 , V_10 -> V_145 ) ;
F_93 ( V_10 -> V_11 ) ;
}
static void F_96 ( struct V_50 * V_37 )
{
F_97 ( V_37 ) ;
F_98 ( V_37 ) ;
F_99 ( V_37 , 50 ) ;
F_100 ( V_37 ) ;
F_101 ( V_37 , 1 ) ;
}
static void F_102 ( struct V_50 * V_37 )
{
F_103 ( V_37 ) ;
F_104 ( V_37 ) ;
}
static int F_105 ( struct V_74 * V_3 ,
const struct V_163 * V_164 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_94 , V_141 ;
int V_62 , V_93 ;
F_106 ( V_3 == NULL ) ;
F_106 ( V_164 == NULL ) ;
F_40 ( & V_3 -> V_37 , L_25 ,
( int ) V_3 -> V_165 , ( int ) V_3 -> V_50 , ( int ) V_3 -> V_64 ) ;
V_62 = F_34 ( V_3 , V_166 , & V_94 ) ;
if ( V_62 )
return V_62 ;
V_94 = F_107 ( V_94 ) + 1 ;
F_108 ( & V_3 -> V_37 , L_26 , V_94 ) ;
if ( V_94 == 0 )
return - V_59 ;
F_106 ( V_94 > V_167 ) ;
V_62 = F_34 ( V_3 , V_166 , & V_141 ) ;
if ( V_62 )
return V_62 ;
V_141 &= V_168 ;
if ( V_141 > 5 ) {
F_41 ( & V_3 -> V_37 , L_27 ) ;
return - V_59 ;
}
V_62 = F_109 ( V_3 ) ;
if ( V_62 )
return V_62 ;
V_2 = F_110 ( sizeof( struct V_1 ) , V_169 ) ;
if ( ! V_2 ) {
V_62 = - V_153 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_136 = ( const struct V_170 * ) V_164 -> V_171 ;
if ( V_2 -> V_136 ) {
V_2 -> V_7 = V_2 -> V_136 -> V_7 ;
V_2 -> V_116 = V_2 -> V_136 -> V_116 ;
V_2 -> V_160 = V_2 -> V_136 -> V_160 ;
}
V_2 -> V_23 = V_94 ;
F_111 ( V_3 , V_2 ) ;
if ( V_2 -> V_136 && V_2 -> V_136 -> V_172 ) {
V_62 = V_2 -> V_136 -> V_172 ( V_2 ) ;
if ( V_62 )
goto free;
}
V_94 = V_2 -> V_23 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
V_10 = F_78 ( V_3 , V_2 , V_141 , V_93 ) ;
if ( F_83 ( V_10 ) ) {
for ( V_93 -- ; V_93 >= 0 ; V_93 -- )
F_94 ( V_2 -> V_94 [ V_93 ] ) ;
V_62 = F_112 ( V_10 ) ;
goto free;
}
V_2 -> V_94 [ V_93 ] = V_10 ;
}
if ( V_2 -> V_160 )
F_96 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_111 ( V_3 , NULL ) ;
F_113 ( V_2 ) ;
V_28:
F_114 ( V_3 ) ;
return V_62 ;
}
static void F_115 ( struct V_74 * V_3 )
{
int V_93 ;
struct V_1 * V_2 ;
V_2 = F_67 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_160 )
F_102 ( & V_3 -> V_37 ) ;
for ( V_93 = 0 ; V_93 < V_2 -> V_23 ; V_93 ++ )
F_94 ( V_2 -> V_94 [ V_93 ] ) ;
F_111 ( V_3 , NULL ) ;
F_113 ( V_2 ) ;
}
F_114 ( V_3 ) ;
}
