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
static int F_30 ( struct V_9 * V_10 )
{
if ( ( F_31 ( V_10 -> V_2 -> V_3 -> V_47 ) != V_48 ) &&
( F_31 ( V_10 -> V_2 -> V_3 -> V_47 ) != V_49 ) )
return - V_50 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_51 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_52 ;
T_2 V_53 ;
switch ( V_2 -> V_3 -> V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_52 = F_33 ( V_2 -> V_3 , V_59 , & V_53 ) ;
if ( V_52 )
return V_52 ;
V_53 &= 0x7f ;
F_34 ( V_2 -> V_3 , V_59 , V_53 ) ;
F_34 ( V_2 -> V_3 , V_60 , 0x08 ) ;
V_52 = F_33 ( V_2 -> V_3 , V_61 , & V_53 ) ;
if ( V_52 )
return V_52 ;
V_53 |= 0x20 ;
F_34 ( V_2 -> V_3 , V_61 , V_53 ) ;
V_52 = F_33 ( V_2 -> V_3 , V_62 , & V_53 ) ;
if ( V_52 )
return V_52 ;
V_53 |= 0x01 ;
F_34 ( V_2 -> V_3 , V_62 , V_53 ) ;
F_34 ( V_2 -> V_3 , V_62 , 0x73 ) ;
F_34 ( V_2 -> V_3 , V_63 , 0x39 ) ;
F_34 ( V_2 -> V_3 , V_64 , 0x08 ) ;
V_52 = F_33 ( V_2 -> V_3 , V_65 , & V_53 ) ;
if ( V_52 )
return V_52 ;
V_53 |= 0x08 ;
F_34 ( V_2 -> V_3 , V_65 , V_53 ) ;
V_52 = F_33 ( V_2 -> V_3 , V_59 , & V_53 ) ;
if ( V_52 )
return V_52 ;
V_53 |= 0x80 ;
F_34 ( V_2 -> V_3 , V_59 , V_53 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_66 )
{
T_2 V_53 ;
int V_52 ;
V_52 = F_33 ( V_2 -> V_3 , 0xAE , & V_53 ) ;
if ( V_52 )
return V_52 ;
if ( V_66 )
V_53 |= 0x47 ;
else
V_53 &= ~ 0x47 ;
V_52 = F_34 ( V_2 -> V_3 , 0xAE , V_53 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_52 ;
T_3 V_67 = 0 ;
if ( V_2 -> V_3 -> V_68 == 0 ) {
V_2 -> V_7 |= V_69 |
V_70 |
V_71 |
V_72 |
V_73 ;
}
if ( V_2 -> V_3 -> V_54 == V_74 )
V_67 = V_75 ;
else if ( V_2 -> V_3 -> V_54 == V_76 )
V_67 = V_77 ;
if ( V_67 ) {
struct V_78 * V_79 ;
V_79 = NULL ;
while ( ( V_79 = F_37 ( V_80 ,
V_67 , V_79 ) ) != NULL ) {
if ( ( F_38 ( V_2 -> V_3 -> V_47 ) ==
F_38 ( V_79 -> V_47 ) ) &&
( V_2 -> V_3 -> V_81 == V_79 -> V_81 ) )
break;
}
if ( V_79 ) {
F_39 ( V_79 ) ;
F_40 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_50 ;
}
}
V_52 = F_35 ( V_2 , 1 ) ;
if ( V_52 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_52 ;
}
if ( V_2 -> V_3 -> V_54 == V_76 ||
V_2 -> V_3 -> V_54 == V_77 )
V_2 -> V_7 |= V_82 ;
return 0 ;
}
static void F_42 ( struct V_26 * V_11 , int V_66 )
{
T_2 V_53 ;
V_53 = F_43 ( V_11 -> V_83 + 0xC0 ) ;
if ( V_66 )
V_53 |= 0x01 ;
else
V_53 &= ~ 0x01 ;
F_44 ( V_53 , V_11 -> V_83 + 0xC0 ) ;
}
static int F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_68 == 0 ) {
T_3 V_84 ;
V_84 = F_46 ( V_10 -> V_11 -> V_83 + V_85 ) ;
V_84 = ( V_84 & V_86 ) >>
V_87 ;
if ( V_84 < 0xAC )
V_10 -> V_11 -> V_7 |= V_88 ;
}
if ( V_10 -> V_2 -> V_3 -> V_54 == V_77 ) {
V_10 -> V_11 -> V_89 = V_90 | V_91 |
V_92 | V_93 |
V_94 ;
V_10 -> V_11 -> V_95 = V_90 | V_91 |
V_92 | V_93 ;
}
if ( V_10 -> V_2 -> V_3 -> V_54 == V_75 ||
V_10 -> V_2 -> V_3 -> V_54 == V_77 )
F_42 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_96 ;
return 0 ;
}
static void F_47 ( struct V_9 * V_10 , int V_97 )
{
if ( V_97 )
return;
if ( V_10 -> V_2 -> V_3 -> V_54 == V_75 ||
V_10 -> V_2 -> V_3 -> V_54 == V_77 )
F_42 ( V_10 -> V_11 , 0 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_98 ;
if ( V_2 -> V_3 -> V_54 == V_75 ||
V_2 -> V_3 -> V_54 == V_77 ) {
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ )
F_42 ( V_2 -> V_99 [ V_98 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_52 , V_98 ;
if ( V_2 -> V_3 -> V_54 == V_75 ||
V_2 -> V_3 -> V_54 == V_77 ) {
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ )
F_42 ( V_2 -> V_99 [ V_98 ] -> V_11 , 1 ) ;
}
V_52 = F_35 ( V_2 , 1 ) ;
if ( V_52 ) {
F_41 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_52 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_100 & 0x0000FF ) == V_101 ) {
V_2 -> V_3 -> V_100 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_100 |= V_102 ;
}
return 0 ;
}
static int F_51 ( struct V_9 * V_10 )
{
int V_103 , V_104 ;
T_2 V_105 = F_43 ( V_10 -> V_11 -> V_83 + V_106 ) ;
T_2 V_107 = F_43 ( V_10 -> V_11 -> V_83 + V_108 ) ;
F_40 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_105 >> 4 , V_105 & 0xf ,
V_107 >> 4 , V_107 & 0xf ) ;
if ( V_107 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_109 ;
F_44 ( V_110 , V_10 -> V_11 -> V_83 + V_111 ) ;
F_44 ( V_112 , V_10 -> V_11 -> V_83 + V_113 ) ;
F_26 ( 50 ) ;
V_103 = 10 ;
do {
V_104 = F_52 ( V_10 -> V_11 -> V_83 + V_114 ) ;
if ( V_104 & V_115 )
break;
F_26 ( 100 ) ;
} while ( -- V_103 );
if ( ! V_103 ) {
F_41 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_44 ( 0 , V_10 -> V_11 -> V_83 + V_113 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_68 == 0x10 )
V_2 -> V_7 |= V_116 ;
return 0 ;
}
static int F_54 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_78 * V_3 ;
int V_52 ;
V_10 = F_55 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_100 & 0xFFFF00 ) == ( V_117 << 8 ) ) &&
( ( V_3 -> V_100 & 0x0000FF ) != V_102 ) &&
( V_11 -> V_118 & V_119 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
V_52 = F_56 ( V_3 , F_57 ( 32 ) ) ;
if ( V_52 )
return V_52 ;
F_58 ( V_3 ) ;
return 0 ;
}
static int F_59 ( struct V_26 * V_11 , int V_120 )
{
T_2 V_121 ;
V_121 = F_24 ( V_11 , V_122 ) ;
switch ( V_120 ) {
case V_123 :
V_121 |= V_124 ;
V_121 &= ~ V_125 ;
break;
case V_126 :
V_121 |= V_125 ;
V_121 &= ~ V_124 ;
break;
default:
V_121 &= ~ ( V_124 | V_125 ) ;
break;
}
F_25 ( V_11 , V_121 , V_122 ) ;
return 0 ;
}
static void F_60 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_55 ( V_11 ) ;
int V_127 = V_10 -> V_127 ;
if ( ! F_12 ( V_127 ) )
return;
F_61 ( V_127 , 0 ) ;
F_26 ( 10 ) ;
F_61 ( V_127 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_62 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_55 ( V_11 ) ;
if ( V_10 -> V_46 )
V_10 -> V_46 ( V_11 ) ;
}
static int F_63 ( struct V_54 * V_37 )
{
struct V_78 * V_3 = F_64 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_128 ;
T_4 V_129 = 0 ;
int V_98 , V_52 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ ) {
V_10 = V_2 -> V_99 [ V_98 ] ;
if ( ! V_10 )
continue;
V_52 = F_66 ( V_10 -> V_11 ) ;
if ( V_52 )
goto V_130;
V_128 = V_10 -> V_11 -> V_21 -> V_129 ;
if ( V_128 & V_131 )
F_67 ( V_10 -> V_11 ) ;
V_129 |= V_128 ;
}
if ( V_2 -> V_132 && V_2 -> V_132 -> V_133 ) {
V_52 = V_2 -> V_132 -> V_133 ( V_2 ) ;
if ( V_52 )
goto V_130;
}
F_68 ( V_3 ) ;
if ( V_129 & V_134 ) {
if ( V_129 & V_131 ) {
F_69 ( V_3 , true ) ;
F_70 ( V_3 , V_135 , 1 ) ;
}
F_71 ( V_3 , V_135 ) ;
} else {
F_70 ( V_3 , V_135 , 0 ) ;
F_72 ( V_3 ) ;
F_71 ( V_3 , V_135 ) ;
}
return 0 ;
V_130:
while ( -- V_98 >= 0 )
F_73 ( V_2 -> V_99 [ V_98 ] -> V_11 ) ;
return V_52 ;
}
static int F_74 ( struct V_54 * V_37 )
{
struct V_78 * V_3 = F_64 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_98 , V_52 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_71 ( V_3 , V_136 ) ;
F_75 ( V_3 ) ;
V_52 = F_76 ( V_3 ) ;
if ( V_52 )
return V_52 ;
if ( V_2 -> V_132 && V_2 -> V_132 -> V_137 ) {
V_52 = V_2 -> V_132 -> V_137 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ ) {
V_10 = V_2 -> V_99 [ V_98 ] ;
if ( ! V_10 )
continue;
V_52 = F_73 ( V_10 -> V_11 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_77 ( struct V_54 * V_37 )
{
struct V_78 * V_3 = F_78 ( V_37 , struct V_78 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_98 , V_52 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ ) {
V_10 = V_2 -> V_99 [ V_98 ] ;
if ( ! V_10 )
continue;
V_52 = F_79 ( V_10 -> V_11 ) ;
if ( V_52 )
goto V_138;
}
if ( V_2 -> V_132 && V_2 -> V_132 -> V_133 ) {
V_52 = V_2 -> V_132 -> V_133 ( V_2 ) ;
if ( V_52 )
goto V_138;
}
return 0 ;
V_138:
while ( -- V_98 >= 0 )
F_80 ( V_2 -> V_99 [ V_98 ] -> V_11 ) ;
return V_52 ;
}
static int F_81 ( struct V_54 * V_37 )
{
struct V_78 * V_3 = F_78 ( V_37 , struct V_78 , V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_98 , V_52 ;
V_2 = F_65 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_132 && V_2 -> V_132 -> V_137 ) {
V_52 = V_2 -> V_132 -> V_137 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ ) {
V_10 = V_2 -> V_99 [ V_98 ] ;
if ( ! V_10 )
continue;
V_52 = F_80 ( V_10 -> V_11 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_82 ( struct V_54 * V_37 )
{
return 0 ;
}
static struct V_9 * F_83 (
struct V_78 * V_3 , struct V_1 * V_2 , int V_139 ,
int V_140 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_52 , V_141 = V_139 + V_140 ;
if ( ! ( F_84 ( V_3 , V_141 ) & V_142 ) ) {
F_41 ( & V_3 -> V_37 , L_11 , V_141 ) ;
return F_85 ( - V_50 ) ;
}
if ( F_86 ( V_3 , V_141 ) < 0x100 ) {
F_41 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_100 & 0x0000FF ) == V_101 ) {
F_41 ( & V_3 -> V_37 , L_14 ) ;
return F_85 ( - V_50 ) ;
}
if ( ( V_3 -> V_100 & 0x0000FF ) > V_101 ) {
F_41 ( & V_3 -> V_37 , L_15 ) ;
return F_85 ( - V_50 ) ;
}
V_11 = F_87 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_88 ( V_11 ) ) {
F_41 ( & V_3 -> V_37 , L_16 ) ;
return F_89 ( V_11 ) ;
}
V_10 = F_55 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_143 = V_141 ;
V_10 -> V_127 = - V_31 ;
V_10 -> V_30 = - V_31 ;
if ( * V_144 )
V_10 -> V_145 = V_144 ( V_3 , V_140 ) ;
if ( V_10 -> V_145 ) {
if ( V_10 -> V_145 -> V_146 ) {
V_52 = V_10 -> V_145 -> V_146 ( V_10 -> V_145 ) ;
if ( V_52 ) {
F_41 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_127 = V_10 -> V_145 -> V_127 ;
V_10 -> V_30 = V_10 -> V_145 -> V_30 ;
}
V_11 -> V_147 = L_18 ;
V_11 -> V_148 = & V_149 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_150 = V_2 -> V_150 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_52 = F_90 ( V_3 , V_141 , F_91 ( V_11 -> V_21 ) ) ;
if ( V_52 ) {
F_41 ( & V_3 -> V_37 , L_19 ) ;
goto V_151;
}
V_11 -> V_83 = F_92 ( V_3 , V_141 ) ;
if ( ! V_11 -> V_83 ) {
F_41 ( & V_3 -> V_37 , L_20 ) ;
V_52 = - V_152 ;
goto V_153;
}
if ( V_2 -> V_132 && V_2 -> V_132 -> V_154 ) {
V_52 = V_2 -> V_132 -> V_154 ( V_10 ) ;
if ( V_52 )
goto V_155;
}
if ( F_12 ( V_10 -> V_127 ) ) {
if ( ! F_13 ( V_10 -> V_127 , L_21 ) ) {
F_93 ( V_10 -> V_127 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_45 ;
V_10 -> V_46 = F_60 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_127 = - V_31 ;
}
}
V_11 -> V_21 -> V_156 = V_134 | V_131 ;
V_11 -> V_21 -> V_140 = V_140 ;
V_11 -> V_21 -> V_39 |= V_157 ;
V_52 = F_94 ( V_11 ) ;
if ( V_52 )
goto remove;
F_11 ( V_10 ) ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_127 ) )
F_17 ( V_10 -> V_127 ) ;
if ( V_2 -> V_132 && V_2 -> V_132 -> V_158 )
V_2 -> V_132 -> V_158 ( V_10 , 0 ) ;
V_155:
F_95 ( V_11 -> V_83 ) ;
V_153:
F_96 ( V_3 , V_141 ) ;
V_151:
if ( V_10 -> V_145 && V_10 -> V_145 -> V_151 )
V_10 -> V_145 -> V_151 ( V_10 -> V_145 ) ;
free:
F_97 ( V_11 ) ;
return F_85 ( V_52 ) ;
}
static void F_98 ( struct V_9 * V_10 )
{
int V_97 ;
T_5 V_53 ;
F_19 ( V_10 ) ;
V_97 = 0 ;
V_53 = F_46 ( V_10 -> V_11 -> V_83 + V_159 ) ;
if ( V_53 == ( T_5 ) - 1 )
V_97 = 1 ;
F_99 ( V_10 -> V_11 , V_97 ) ;
if ( F_12 ( V_10 -> V_127 ) )
F_17 ( V_10 -> V_127 ) ;
if ( V_10 -> V_2 -> V_132 && V_10 -> V_2 -> V_132 -> V_158 )
V_10 -> V_2 -> V_132 -> V_158 ( V_10 , V_97 ) ;
if ( V_10 -> V_145 && V_10 -> V_145 -> V_151 )
V_10 -> V_145 -> V_151 ( V_10 -> V_145 ) ;
F_96 ( V_10 -> V_2 -> V_3 , V_10 -> V_143 ) ;
F_97 ( V_10 -> V_11 ) ;
}
static void F_100 ( struct V_54 * V_37 )
{
F_101 ( V_37 ) ;
F_102 ( V_37 ) ;
F_103 ( V_37 , 50 ) ;
F_104 ( V_37 ) ;
F_105 ( V_37 , 1 ) ;
}
static void F_106 ( struct V_54 * V_37 )
{
F_107 ( V_37 ) ;
F_108 ( V_37 ) ;
}
static int F_109 ( struct V_78 * V_3 ,
const struct V_160 * V_161 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_99 , V_139 ;
int V_52 , V_98 ;
F_110 ( V_3 == NULL ) ;
F_110 ( V_161 == NULL ) ;
F_40 ( & V_3 -> V_37 , L_23 ,
( int ) V_3 -> V_162 , ( int ) V_3 -> V_54 , ( int ) V_3 -> V_68 ) ;
V_52 = F_33 ( V_3 , V_163 , & V_99 ) ;
if ( V_52 )
return V_52 ;
V_99 = F_111 ( V_99 ) + 1 ;
F_112 ( & V_3 -> V_37 , L_24 , V_99 ) ;
if ( V_99 == 0 )
return - V_50 ;
F_110 ( V_99 > V_164 ) ;
V_52 = F_33 ( V_3 , V_163 , & V_139 ) ;
if ( V_52 )
return V_52 ;
V_139 &= V_165 ;
if ( V_139 > 5 ) {
F_41 ( & V_3 -> V_37 , L_25 ) ;
return - V_50 ;
}
V_52 = F_76 ( V_3 ) ;
if ( V_52 )
return V_52 ;
V_2 = F_113 ( sizeof( struct V_1 ) , V_166 ) ;
if ( ! V_2 ) {
V_52 = - V_152 ;
goto V_28;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_132 = ( const struct V_167 * ) V_161 -> V_168 ;
if ( V_2 -> V_132 ) {
V_2 -> V_7 = V_2 -> V_132 -> V_7 ;
V_2 -> V_150 = V_2 -> V_132 -> V_150 ;
V_2 -> V_169 = V_2 -> V_132 -> V_169 ;
}
V_2 -> V_23 = V_99 ;
F_114 ( V_3 , V_2 ) ;
if ( V_2 -> V_132 && V_2 -> V_132 -> V_170 ) {
V_52 = V_2 -> V_132 -> V_170 ( V_2 ) ;
if ( V_52 )
goto free;
}
V_99 = V_2 -> V_23 ;
for ( V_98 = 0 ; V_98 < V_99 ; V_98 ++ ) {
V_10 = F_83 ( V_3 , V_2 , V_139 , V_98 ) ;
if ( F_88 ( V_10 ) ) {
for ( V_98 -- ; V_98 >= 0 ; V_98 -- )
F_98 ( V_2 -> V_99 [ V_98 ] ) ;
V_52 = F_115 ( V_10 ) ;
goto free;
}
V_2 -> V_99 [ V_98 ] = V_10 ;
}
if ( V_2 -> V_169 )
F_100 ( & V_3 -> V_37 ) ;
return 0 ;
free:
F_114 ( V_3 , NULL ) ;
F_116 ( V_2 ) ;
V_28:
F_72 ( V_3 ) ;
return V_52 ;
}
static void F_117 ( struct V_78 * V_3 )
{
int V_98 ;
struct V_1 * V_2 ;
V_2 = F_65 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_169 )
F_106 ( & V_3 -> V_37 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_23 ; V_98 ++ )
F_98 ( V_2 -> V_99 [ V_98 ] ) ;
F_114 ( V_3 , NULL ) ;
F_116 ( V_2 ) ;
}
F_72 ( V_3 ) ;
}
