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
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
if ( ( F_31 ( V_10 -> V_2 -> V_3 -> V_48 ) != V_49 ) &&
( F_31 ( V_10 -> V_2 -> V_3 -> V_48 ) != V_50 ) )
return - V_51 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_46 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_52 )
{
T_2 V_53 ;
int V_54 ;
V_54 = F_33 ( V_2 -> V_3 , 0xAE , & V_53 ) ;
if ( V_54 )
return V_54 ;
if ( V_52 )
V_53 |= 0x47 ;
else
V_53 &= ~ 0x47 ;
V_54 = F_34 ( V_2 -> V_3 , 0xAE , V_53 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_54 ;
T_3 V_55 = 0 ;
if ( V_2 -> V_3 -> V_56 == 0 ) {
V_2 -> V_7 |= V_57 |
V_58 |
V_59 |
V_60 |
V_61 ;
}
if ( V_2 -> V_3 -> V_62 == V_63 )
V_55 = V_64 ;
else if ( V_2 -> V_3 -> V_62 == V_65 )
V_55 = V_66 ;
if ( V_55 ) {
struct V_67 * V_68 ;
V_68 = NULL ;
while ( ( V_68 = F_36 ( V_69 ,
V_55 , V_68 ) ) != NULL ) {
if ( ( F_37 ( V_2 -> V_3 -> V_48 ) ==
F_37 ( V_68 -> V_48 ) ) &&
( V_2 -> V_3 -> V_70 == V_68 -> V_70 ) )
break;
}
if ( V_68 ) {
F_38 ( V_68 ) ;
F_39 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_51 ;
}
}
V_54 = F_32 ( V_2 , 1 ) ;
if ( V_54 ) {
F_40 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_54 ;
}
if ( V_2 -> V_3 -> V_62 == V_65 ||
V_2 -> V_3 -> V_62 == V_66 )
V_2 -> V_7 |= V_71 ;
return 0 ;
}
static void F_41 ( struct V_26 * V_11 , int V_52 )
{
T_2 V_53 ;
V_53 = F_42 ( V_11 -> V_72 + 0xC0 ) ;
if ( V_52 )
V_53 |= 0x01 ;
else
V_53 &= ~ 0x01 ;
F_43 ( V_53 , V_11 -> V_72 + 0xC0 ) ;
}
static int F_44 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_56 == 0 ) {
T_3 V_73 ;
V_73 = F_45 ( V_10 -> V_11 -> V_72 + V_74 ) ;
V_73 = ( V_73 & V_75 ) >>
V_76 ;
if ( V_73 < 0xAC )
V_10 -> V_11 -> V_7 |= V_77 ;
}
if ( V_10 -> V_2 -> V_3 -> V_62 == V_66 ) {
V_10 -> V_11 -> V_78 = V_79 | V_80 |
V_81 | V_82 |
V_83 ;
V_10 -> V_11 -> V_84 = V_79 | V_80 |
V_81 | V_82 ;
}
if ( V_10 -> V_2 -> V_3 -> V_62 == V_64 ||
V_10 -> V_2 -> V_3 -> V_62 == V_66 )
F_41 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_85 ;
return 0 ;
}
static void F_46 ( struct V_9 * V_10 , int V_86 )
{
if ( V_86 )
return;
if ( V_10 -> V_2 -> V_3 -> V_62 == V_64 ||
V_10 -> V_2 -> V_3 -> V_62 == V_66 )
F_41 ( V_10 -> V_11 , 0 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_87 ;
if ( V_2 -> V_3 -> V_62 == V_64 ||
V_2 -> V_3 -> V_62 == V_66 ) {
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ )
F_41 ( V_2 -> V_88 [ V_87 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_54 , V_87 ;
if ( V_2 -> V_3 -> V_62 == V_64 ||
V_2 -> V_3 -> V_62 == V_66 ) {
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ )
F_41 ( V_2 -> V_88 [ V_87 ] -> V_11 , 1 ) ;
}
V_54 = F_32 ( V_2 , 1 ) ;
if ( V_54 ) {
F_40 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_54 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_89 & 0x0000FF ) == V_90 ) {
V_2 -> V_3 -> V_89 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_89 |= V_91 ;
}
return 0 ;
}
static int F_50 ( struct V_9 * V_10 )
{
int V_92 , V_93 ;
T_2 V_94 = F_42 ( V_10 -> V_11 -> V_72 + V_95 ) ;
T_2 V_96 = F_42 ( V_10 -> V_11 -> V_72 + V_97 ) ;
F_39 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_94 >> 4 , V_94 & 0xf ,
V_96 >> 4 , V_96 & 0xf ) ;
if ( V_96 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_98 ;
F_43 ( V_99 , V_10 -> V_11 -> V_72 + V_100 ) ;
F_43 ( V_101 , V_10 -> V_11 -> V_72 + V_102 ) ;
F_26 ( 50 ) ;
V_92 = 10 ;
do {
V_93 = F_51 ( V_10 -> V_11 -> V_72 + V_103 ) ;
if ( V_93 & V_104 )
break;
F_26 ( 100 ) ;
} while ( -- V_92 );
if ( ! V_92 ) {
F_40 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_43 ( 0 , V_10 -> V_11 -> V_72 + V_102 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_56 == 0x10 )
V_2 -> V_7 |= V_105 ;
return 0 ;
}
static int F_53 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_106 ;
return 0 ;
}
static int F_54 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_67 * V_3 ;
int V_54 ;
V_10 = F_55 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_89 & 0xFFFF00 ) == ( V_107 << 8 ) ) &&
( ( V_3 -> V_89 & 0x0000FF ) != V_91 ) &&
( V_11 -> V_108 & V_109 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
V_54 = F_56 ( V_3 , F_57 ( 32 ) ) ;
if ( V_54 )
return V_54 ;
F_58 ( V_3 ) ;
return 0 ;
}
static void F_59 ( struct V_26 * V_11 , int V_110 )
{
T_2 V_111 ;
V_111 = F_24 ( V_11 , V_112 ) ;
switch ( V_110 ) {
case V_113 :
V_111 |= V_114 ;
V_111 &= ~ V_115 ;
break;
case V_116 :
V_111 |= V_115 ;
V_111 &= ~ V_114 ;
break;
default:
V_111 &= ~ ( V_114 | V_115 ) ;
break;
}
F_25 ( V_11 , V_111 , V_112 ) ;
}
static void F_60 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_55 ( V_11 ) ;
int V_117 = V_10 -> V_117 ;
if ( ! F_12 ( V_117 ) )
return;
F_61 ( V_117 , 0 ) ;
F_26 ( 10 ) ;
F_61 ( V_117 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_62 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_55 ( V_11 ) ;
if ( V_10 -> V_47 )
V_10 -> V_47 ( V_11 ) ;
}
static int F_63 ( struct V_62 * V_37 )
{
struct V_67 * V_3 = F_64 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_118 ;
T_4 V_119 = 0 ;
int V_87 , V_54 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ ) {
V_10 = V_2 -> V_88 [ V_87 ] ;
if ( ! V_10 )
continue;
V_54 = F_66 ( V_10 -> V_11 ) ;
if ( V_54 )
goto V_120;
V_118 = V_10 -> V_11 -> V_21 -> V_119 ;
if ( V_118 & V_121 )
F_67 ( V_10 -> V_11 ) ;
V_119 |= V_118 ;
}
if ( V_2 -> V_122 && V_2 -> V_122 -> V_123 ) {
V_54 = V_2 -> V_122 -> V_123 ( V_2 ) ;
if ( V_54 )
goto V_120;
}
if ( V_119 & V_124 ) {
if ( V_119 & V_121 )
F_68 ( V_37 , true ) ;
else
F_68 ( V_37 , false ) ;
} else
F_68 ( V_37 , false ) ;
return 0 ;
V_120:
while ( -- V_87 >= 0 )
F_69 ( V_2 -> V_88 [ V_87 ] -> V_11 ) ;
return V_54 ;
}
static int F_70 ( struct V_62 * V_37 )
{
struct V_67 * V_3 = F_64 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_87 , V_54 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_125 ) {
V_54 = V_2 -> V_122 -> V_125 ( V_2 ) ;
if ( V_54 )
return V_54 ;
}
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ ) {
V_10 = V_2 -> V_88 [ V_87 ] ;
if ( ! V_10 )
continue;
V_54 = F_69 ( V_10 -> V_11 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_71 ( struct V_62 * V_37 )
{
struct V_67 * V_3 = F_72 ( V_37 , struct V_67 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_87 , V_54 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ ) {
V_10 = V_2 -> V_88 [ V_87 ] ;
if ( ! V_10 )
continue;
V_54 = F_73 ( V_10 -> V_11 ) ;
if ( V_54 )
goto V_126;
}
if ( V_2 -> V_122 && V_2 -> V_122 -> V_123 ) {
V_54 = V_2 -> V_122 -> V_123 ( V_2 ) ;
if ( V_54 )
goto V_126;
}
return 0 ;
V_126:
while ( -- V_87 >= 0 )
F_74 ( V_2 -> V_88 [ V_87 ] -> V_11 ) ;
return V_54 ;
}
static int F_75 ( struct V_62 * V_37 )
{
struct V_67 * V_3 = F_72 ( V_37 , struct V_67 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_87 , V_54 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_125 ) {
V_54 = V_2 -> V_122 -> V_125 ( V_2 ) ;
if ( V_54 )
return V_54 ;
}
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ ) {
V_10 = V_2 -> V_88 [ V_87 ] ;
if ( ! V_10 )
continue;
V_54 = F_74 ( V_10 -> V_11 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_76 ( struct V_62 * V_37 )
{
return 0 ;
}
static struct V_9 * F_77 (
struct V_67 * V_3 , struct V_1 * V_2 , int V_127 ,
int V_128 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_54 , V_129 = V_127 + V_128 ;
if ( ! ( F_78 ( V_3 , V_129 ) & V_130 ) ) {
F_40 ( & V_3 -> V_37 , L_11 , V_129 ) ;
return F_79 ( - V_51 ) ;
}
if ( F_80 ( V_3 , V_129 ) < 0x100 ) {
F_40 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_89 & 0x0000FF ) == V_90 ) {
F_40 ( & V_3 -> V_37 , L_14 ) ;
return F_79 ( - V_51 ) ;
}
if ( ( V_3 -> V_89 & 0x0000FF ) > V_90 ) {
F_40 ( & V_3 -> V_37 , L_15 ) ;
return F_79 ( - V_51 ) ;
}
V_11 = F_81 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_82 ( V_11 ) ) {
F_40 ( & V_3 -> V_37 , L_16 ) ;
return F_83 ( V_11 ) ;
}
V_10 = F_55 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_131 = V_129 ;
V_10 -> V_117 = - V_31 ;
V_10 -> V_30 = - V_31 ;
if ( * V_132 )
V_10 -> V_133 = V_132 ( V_3 , V_128 ) ;
if ( V_10 -> V_133 ) {
if ( V_10 -> V_133 -> V_134 ) {
V_54 = V_10 -> V_133 -> V_134 ( V_10 -> V_133 ) ;
if ( V_54 ) {
F_40 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_117 = V_10 -> V_133 -> V_117 ;
V_10 -> V_30 = V_10 -> V_133 -> V_30 ;
}
V_11 -> V_135 = L_18 ;
V_11 -> V_136 = & V_137 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_138 = V_2 -> V_138 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_54 = F_84 ( V_3 , V_129 , F_85 ( V_11 -> V_21 ) ) ;
if ( V_54 ) {
F_40 ( & V_3 -> V_37 , L_19 ) ;
goto V_139;
}
V_11 -> V_72 = F_86 ( V_3 , V_129 ) ;
if ( ! V_11 -> V_72 ) {
F_40 ( & V_3 -> V_37 , L_20 ) ;
V_54 = - V_140 ;
goto V_141;
}
if ( V_2 -> V_122 && V_2 -> V_122 -> V_142 ) {
V_54 = V_2 -> V_122 -> V_142 ( V_10 ) ;
if ( V_54 )
goto V_143;
}
if ( F_12 ( V_10 -> V_117 ) ) {
if ( ! F_13 ( V_10 -> V_117 , L_21 ) ) {
F_87 ( V_10 -> V_117 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_45 ;
V_10 -> V_47 = F_60 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_117 = - V_31 ;
}
}
V_11 -> V_21 -> V_144 = V_124 | V_121 ;
V_11 -> V_21 -> V_128 = V_128 ;
V_11 -> V_21 -> V_39 |= V_145 ;
V_54 = F_88 ( V_11 ) ;
if ( V_54 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_146 &&
! F_12 ( V_10 -> V_30 ) )
V_2 -> V_147 = false ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_117 ) )
F_17 ( V_10 -> V_117 ) ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_148 )
V_2 -> V_122 -> V_148 ( V_10 , 0 ) ;
V_143:
F_89 ( V_11 -> V_72 ) ;
V_141:
F_90 ( V_3 , V_129 ) ;
V_139:
if ( V_10 -> V_133 && V_10 -> V_133 -> V_139 )
V_10 -> V_133 -> V_139 ( V_10 -> V_133 ) ;
free:
F_91 ( V_11 ) ;
return F_79 ( V_54 ) ;
}
static void F_92 ( struct V_9 * V_10 )
{
int V_86 ;
T_5 V_53 ;
F_19 ( V_10 ) ;
V_86 = 0 ;
V_53 = F_45 ( V_10 -> V_11 -> V_72 + V_149 ) ;
if ( V_53 == ( T_5 ) - 1 )
V_86 = 1 ;
F_93 ( V_10 -> V_11 , V_86 ) ;
if ( F_12 ( V_10 -> V_117 ) )
F_17 ( V_10 -> V_117 ) ;
if ( V_10 -> V_2 -> V_122 && V_10 -> V_2 -> V_122 -> V_148 )
V_10 -> V_2 -> V_122 -> V_148 ( V_10 , V_86 ) ;
if ( V_10 -> V_133 && V_10 -> V_133 -> V_139 )
V_10 -> V_133 -> V_139 ( V_10 -> V_133 ) ;
F_90 ( V_10 -> V_2 -> V_3 , V_10 -> V_131 ) ;
F_91 ( V_10 -> V_11 ) ;
}
static void F_94 ( struct V_62 * V_37 )
{
F_95 ( V_37 ) ;
F_96 ( V_37 ) ;
F_97 ( V_37 , 50 ) ;
F_98 ( V_37 ) ;
F_99 ( V_37 , 1 ) ;
}
static void F_100 ( struct V_62 * V_37 )
{
F_101 ( V_37 ) ;
F_102 ( V_37 ) ;
}
static int F_103 ( struct V_67 * V_3 ,
const struct V_150 * V_151 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_88 , V_127 ;
int V_54 , V_87 ;
F_104 ( V_3 == NULL ) ;
F_104 ( V_151 == NULL ) ;
F_39 ( & V_3 -> V_37 , L_23 ,
( int ) V_3 -> V_152 , ( int ) V_3 -> V_62 , ( int ) V_3 -> V_56 ) ;
V_54 = F_33 ( V_3 , V_153 , & V_88 ) ;
if ( V_54 )
return V_54 ;
V_88 = F_105 ( V_88 ) + 1 ;
F_106 ( & V_3 -> V_37 , L_24 , V_88 ) ;
if ( V_88 == 0 )
return - V_51 ;
F_104 ( V_88 > V_154 ) ;
V_54 = F_33 ( V_3 , V_153 , & V_127 ) ;
if ( V_54 )
return V_54 ;
V_127 &= V_155 ;
if ( V_127 > 5 ) {
F_40 ( & V_3 -> V_37 , L_25 ) ;
return - V_51 ;
}
V_54 = F_107 ( V_3 ) ;
if ( V_54 )
return V_54 ;
V_2 = F_108 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_2 ) {
V_54 = - V_140 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_122 = ( const struct V_157 * ) V_151 -> V_158 ;
if ( V_2 -> V_122 ) {
V_2 -> V_7 = V_2 -> V_122 -> V_7 ;
V_2 -> V_138 = V_2 -> V_122 -> V_138 ;
V_2 -> V_147 = V_2 -> V_122 -> V_147 ;
}
V_2 -> V_23 = V_88 ;
F_109 ( V_3 , V_2 ) ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_159 ) {
V_54 = V_2 -> V_122 -> V_159 ( V_2 ) ;
if ( V_54 )
goto free;
}
V_88 = V_2 -> V_23 ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
V_10 = F_77 ( V_3 , V_2 , V_127 , V_87 ) ;
if ( F_82 ( V_10 ) ) {
for ( V_87 -- ; V_87 >= 0 ; V_87 -- )
F_92 ( V_2 -> V_88 [ V_87 ] ) ;
V_54 = F_110 ( V_10 ) ;
goto free;
}
V_2 -> V_88 [ V_87 ] = V_10 ;
}
if ( V_2 -> V_147 )
F_94 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_109 ( V_3 , NULL ) ;
F_111 ( V_2 ) ;
V_28:
F_112 ( V_3 ) ;
return V_54 ;
}
static void F_113 ( struct V_67 * V_3 )
{
int V_87 ;
struct V_1 * V_2 ;
V_2 = F_65 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_147 )
F_100 ( & V_3 -> V_37 ) ;
for ( V_87 = 0 ; V_87 < V_2 -> V_23 ; V_87 ++ )
F_92 ( V_2 -> V_88 [ V_87 ] ) ;
F_109 ( V_3 , NULL ) ;
F_111 ( V_2 ) ;
}
F_112 ( V_3 ) ;
}
