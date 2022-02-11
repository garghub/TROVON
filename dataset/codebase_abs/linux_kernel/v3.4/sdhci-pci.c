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
V_19 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_21 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_22 = 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_21 ;
return 0 ;
}
static T_1 F_8 ( int V_23 , void * V_24 )
{
struct V_9 * V_10 = V_24 ;
struct V_25 * V_11 = V_10 -> V_11 ;
F_9 ( V_11 -> V_20 , F_10 ( 200 ) ) ;
return V_26 ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_27 , V_23 , V_28 = V_10 -> V_29 ;
V_10 -> V_29 = - V_30 ;
V_10 -> V_31 = - V_30 ;
if ( ! F_12 ( V_28 ) )
return;
V_27 = F_13 ( V_28 , L_1 ) ;
if ( V_27 < 0 )
goto V_32;
V_27 = F_14 ( V_28 ) ;
if ( V_27 < 0 )
goto V_33;
V_23 = F_15 ( V_28 ) ;
if ( V_23 < 0 )
goto V_33;
V_27 = F_16 ( V_23 , F_8 , V_34 |
V_35 , L_1 , V_10 ) ;
if ( V_27 )
goto V_33;
V_10 -> V_29 = V_28 ;
V_10 -> V_31 = V_23 ;
return;
V_33:
F_17 ( V_28 ) ;
V_32:
F_18 ( & V_10 -> V_2 -> V_3 -> V_36 , L_2 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_31 >= 0 )
F_20 ( V_10 -> V_31 , V_10 ) ;
if ( F_12 ( V_10 -> V_29 ) )
F_17 ( V_10 -> V_29 ) ;
}
static inline void F_11 ( struct V_9 * V_10 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_21 | V_37 ;
V_10 -> V_11 -> V_20 -> V_38 |= V_39 |
V_40 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_41 | V_37 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_42 ;
T_2 V_43 ;
switch ( V_2 -> V_3 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_42 = F_24 ( V_2 -> V_3 , V_49 , & V_43 ) ;
if ( V_42 )
return V_42 ;
V_43 &= 0x7f ;
F_25 ( V_2 -> V_3 , V_49 , V_43 ) ;
F_25 ( V_2 -> V_3 , V_50 , 0x08 ) ;
V_42 = F_24 ( V_2 -> V_3 , V_51 , & V_43 ) ;
if ( V_42 )
return V_42 ;
V_43 |= 0x20 ;
F_25 ( V_2 -> V_3 , V_51 , V_43 ) ;
V_42 = F_24 ( V_2 -> V_3 , V_52 , & V_43 ) ;
if ( V_42 )
return V_42 ;
V_43 |= 0x01 ;
F_25 ( V_2 -> V_3 , V_52 , V_43 ) ;
F_25 ( V_2 -> V_3 , V_52 , 0x73 ) ;
F_25 ( V_2 -> V_3 , V_53 , 0x39 ) ;
F_25 ( V_2 -> V_3 , V_54 , 0x08 ) ;
V_42 = F_24 ( V_2 -> V_3 , V_55 , & V_43 ) ;
if ( V_42 )
return V_42 ;
V_43 |= 0x08 ;
F_25 ( V_2 -> V_3 , V_55 , V_43 ) ;
V_42 = F_24 ( V_2 -> V_3 , V_49 , & V_43 ) ;
if ( V_42 )
return V_42 ;
V_43 |= 0x80 ;
F_25 ( V_2 -> V_3 , V_49 , V_43 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_56 )
{
T_2 V_43 ;
int V_42 ;
V_42 = F_24 ( V_2 -> V_3 , 0xAE , & V_43 ) ;
if ( V_42 )
return V_42 ;
if ( V_56 )
V_43 |= 0x47 ;
else
V_43 &= ~ 0x47 ;
V_42 = F_25 ( V_2 -> V_3 , 0xAE , V_43 ) ;
if ( V_42 )
return V_42 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_42 ;
T_3 V_57 = 0 ;
if ( V_2 -> V_3 -> V_58 == 0 ) {
V_2 -> V_7 |= V_59 |
V_60 |
V_61 |
V_62 |
V_63 ;
}
if ( V_2 -> V_3 -> V_44 == V_64 )
V_57 = V_65 ;
else if ( V_2 -> V_3 -> V_44 == V_66 )
V_57 = V_67 ;
if ( V_57 ) {
struct V_68 * V_69 ;
V_69 = NULL ;
while ( ( V_69 = F_28 ( V_70 ,
V_57 , V_69 ) ) != NULL ) {
if ( ( F_29 ( V_2 -> V_3 -> V_71 ) ==
F_29 ( V_69 -> V_71 ) ) &&
( V_2 -> V_3 -> V_72 == V_69 -> V_72 ) )
break;
}
if ( V_69 ) {
F_30 ( V_69 ) ;
F_31 ( & V_2 -> V_3 -> V_36 , L_3
L_4 ) ;
return - V_73 ;
}
}
V_42 = F_26 ( V_2 , 1 ) ;
if ( V_42 ) {
F_32 ( & V_2 -> V_3 -> V_36 , L_5 ) ;
return V_42 ;
}
if ( V_2 -> V_3 -> V_44 == V_66 ||
V_2 -> V_3 -> V_44 == V_67 )
V_2 -> V_7 |= V_74 ;
return 0 ;
}
static void F_33 ( struct V_25 * V_11 , int V_56 )
{
T_2 V_43 ;
V_43 = F_34 ( V_11 -> V_75 + 0xC0 ) ;
if ( V_56 )
V_43 |= 0x01 ;
else
V_43 &= ~ 0x01 ;
F_35 ( V_43 , V_11 -> V_75 + 0xC0 ) ;
}
static int F_36 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_58 == 0 ) {
T_3 V_76 ;
V_76 = F_37 ( V_10 -> V_11 -> V_75 + V_77 ) ;
V_76 = ( V_76 & V_78 ) >>
V_79 ;
if ( V_76 < 0xAC )
V_10 -> V_11 -> V_7 |= V_80 ;
}
if ( V_10 -> V_2 -> V_3 -> V_44 == V_67 ) {
V_10 -> V_11 -> V_81 = V_82 | V_83 |
V_84 | V_85 |
V_86 ;
V_10 -> V_11 -> V_87 = V_82 | V_83 |
V_84 | V_85 ;
}
if ( V_10 -> V_2 -> V_3 -> V_44 == V_65 ||
V_10 -> V_2 -> V_3 -> V_44 == V_67 )
F_33 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_88 ;
return 0 ;
}
static void F_38 ( struct V_9 * V_10 , int V_89 )
{
if ( V_89 )
return;
if ( V_10 -> V_2 -> V_3 -> V_44 == V_65 ||
V_10 -> V_2 -> V_3 -> V_44 == V_67 )
F_33 ( V_10 -> V_11 , 0 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_90 ;
if ( V_2 -> V_3 -> V_44 == V_65 ||
V_2 -> V_3 -> V_44 == V_67 ) {
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ )
F_33 ( V_2 -> V_91 [ V_90 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_42 , V_90 ;
if ( V_2 -> V_3 -> V_44 == V_65 ||
V_2 -> V_3 -> V_44 == V_67 ) {
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ )
F_33 ( V_2 -> V_91 [ V_90 ] -> V_11 , 1 ) ;
}
V_42 = F_26 ( V_2 , 1 ) ;
if ( V_42 ) {
F_32 ( & V_2 -> V_3 -> V_36 , L_5 ) ;
return V_42 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_92 & 0x0000FF ) == V_93 ) {
V_2 -> V_3 -> V_92 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_92 |= V_94 ;
}
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
int V_95 , V_96 ;
T_2 V_97 = F_34 ( V_10 -> V_11 -> V_75 + V_98 ) ;
T_2 V_99 = F_34 ( V_10 -> V_11 -> V_75 + V_100 ) ;
F_31 ( & V_10 -> V_2 -> V_3 -> V_36 , L_6
L_7 ,
V_97 >> 4 , V_97 & 0xf ,
V_99 >> 4 , V_99 & 0xf ) ;
if ( V_99 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_101 ;
F_35 ( V_102 , V_10 -> V_11 -> V_75 + V_103 ) ;
F_35 ( V_104 , V_10 -> V_11 -> V_75 + V_105 ) ;
F_43 ( 50 ) ;
V_95 = 10 ;
do {
V_96 = F_44 ( V_10 -> V_11 -> V_75 + V_106 ) ;
if ( V_96 & V_107 )
break;
F_43 ( 100 ) ;
} while ( -- V_95 );
if ( ! V_95 ) {
F_32 ( & V_10 -> V_2 -> V_3 -> V_36 ,
L_8 ) ;
F_35 ( 0 , V_10 -> V_11 -> V_75 + V_105 ) ;
return - V_73 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_58 == 0x10 )
V_2 -> V_7 |= V_108 ;
return 0 ;
}
static int F_46 ( struct V_25 * V_11 )
{
struct V_9 * V_10 ;
struct V_68 * V_3 ;
int V_42 ;
V_10 = F_47 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_92 & 0xFFFF00 ) == ( V_109 << 8 ) ) &&
( ( V_3 -> V_92 & 0x0000FF ) != V_94 ) &&
( V_11 -> V_110 & V_111 ) ) {
F_18 ( & V_3 -> V_36 , L_9
L_10 ) ;
}
V_42 = F_48 ( V_3 , F_49 ( 32 ) ) ;
if ( V_42 )
return V_42 ;
F_50 ( V_3 ) ;
return 0 ;
}
static int F_51 ( struct V_25 * V_11 , int V_112 )
{
T_2 V_113 ;
V_113 = F_52 ( V_11 , V_114 ) ;
switch ( V_112 ) {
case V_115 :
V_113 |= V_116 ;
V_113 &= ~ V_117 ;
break;
case V_118 :
V_113 |= V_117 ;
V_113 &= ~ V_116 ;
break;
default:
V_113 &= ~ ( V_116 | V_117 ) ;
break;
}
F_53 ( V_11 , V_113 , V_114 ) ;
return 0 ;
}
static void F_54 ( struct V_25 * V_11 )
{
struct V_9 * V_10 = F_47 ( V_11 ) ;
int V_119 = V_10 -> V_119 ;
if ( ! F_12 ( V_119 ) )
return;
F_55 ( V_119 , 0 ) ;
F_43 ( 10 ) ;
F_55 ( V_119 , 1 ) ;
F_56 ( 300 , 1000 ) ;
}
static int F_57 ( struct V_44 * V_36 )
{
struct V_68 * V_3 = F_58 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_120 ;
T_4 V_121 = 0 ;
int V_90 , V_42 ;
V_2 = F_59 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ ) {
V_10 = V_2 -> V_91 [ V_90 ] ;
if ( ! V_10 )
continue;
V_42 = F_60 ( V_10 -> V_11 ) ;
if ( V_42 )
goto V_122;
V_120 = V_10 -> V_11 -> V_20 -> V_121 ;
if ( V_120 & V_123 )
F_61 ( V_10 -> V_11 ) ;
V_121 |= V_120 ;
}
if ( V_2 -> V_124 && V_2 -> V_124 -> V_125 ) {
V_42 = V_2 -> V_124 -> V_125 ( V_2 ) ;
if ( V_42 )
goto V_122;
}
F_62 ( V_3 ) ;
if ( V_121 & V_126 ) {
if ( V_121 & V_123 ) {
F_63 ( V_3 , true ) ;
F_64 ( V_3 , V_127 , 1 ) ;
}
F_65 ( V_3 , V_127 ) ;
} else {
F_64 ( V_3 , V_127 , 0 ) ;
F_66 ( V_3 ) ;
F_65 ( V_3 , V_127 ) ;
}
return 0 ;
V_122:
while ( -- V_90 >= 0 )
F_67 ( V_2 -> V_91 [ V_90 ] -> V_11 ) ;
return V_42 ;
}
static int F_68 ( struct V_44 * V_36 )
{
struct V_68 * V_3 = F_58 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_90 , V_42 ;
V_2 = F_59 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_65 ( V_3 , V_128 ) ;
F_69 ( V_3 ) ;
V_42 = F_70 ( V_3 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 -> V_124 && V_2 -> V_124 -> V_129 ) {
V_42 = V_2 -> V_124 -> V_129 ( V_2 ) ;
if ( V_42 )
return V_42 ;
}
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ ) {
V_10 = V_2 -> V_91 [ V_90 ] ;
if ( ! V_10 )
continue;
V_42 = F_67 ( V_10 -> V_11 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static int F_71 ( struct V_44 * V_36 )
{
struct V_68 * V_3 = F_72 ( V_36 , struct V_68 , V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_90 , V_42 ;
V_2 = F_59 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ ) {
V_10 = V_2 -> V_91 [ V_90 ] ;
if ( ! V_10 )
continue;
V_42 = F_73 ( V_10 -> V_11 ) ;
if ( V_42 )
goto V_130;
}
if ( V_2 -> V_124 && V_2 -> V_124 -> V_125 ) {
V_42 = V_2 -> V_124 -> V_125 ( V_2 ) ;
if ( V_42 )
goto V_130;
}
return 0 ;
V_130:
while ( -- V_90 >= 0 )
F_74 ( V_2 -> V_91 [ V_90 ] -> V_11 ) ;
return V_42 ;
}
static int F_75 ( struct V_44 * V_36 )
{
struct V_68 * V_3 = F_72 ( V_36 , struct V_68 , V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_90 , V_42 ;
V_2 = F_59 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_124 && V_2 -> V_124 -> V_129 ) {
V_42 = V_2 -> V_124 -> V_129 ( V_2 ) ;
if ( V_42 )
return V_42 ;
}
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ ) {
V_10 = V_2 -> V_91 [ V_90 ] ;
if ( ! V_10 )
continue;
V_42 = F_74 ( V_10 -> V_11 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
static int F_76 ( struct V_44 * V_36 )
{
return 0 ;
}
static struct V_9 * T_5 F_77 (
struct V_68 * V_3 , struct V_1 * V_2 , int V_131 ,
int V_132 )
{
struct V_9 * V_10 ;
struct V_25 * V_11 ;
int V_42 , V_133 = V_131 + V_132 ;
if ( ! ( F_78 ( V_3 , V_133 ) & V_134 ) ) {
F_32 ( & V_3 -> V_36 , L_11 , V_133 ) ;
return F_79 ( - V_73 ) ;
}
if ( F_80 ( V_3 , V_133 ) != 0x100 ) {
F_32 ( & V_3 -> V_36 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_92 & 0x0000FF ) == V_93 ) {
F_32 ( & V_3 -> V_36 , L_14 ) ;
return F_79 ( - V_73 ) ;
}
if ( ( V_3 -> V_92 & 0x0000FF ) > V_93 ) {
F_32 ( & V_3 -> V_36 , L_15 ) ;
return F_79 ( - V_73 ) ;
}
V_11 = F_81 ( & V_3 -> V_36 , sizeof( struct V_9 ) ) ;
if ( F_82 ( V_11 ) ) {
F_32 ( & V_3 -> V_36 , L_16 ) ;
return F_83 ( V_11 ) ;
}
V_10 = F_47 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_135 = V_133 ;
V_10 -> V_119 = - V_30 ;
V_10 -> V_29 = - V_30 ;
if ( * V_136 )
V_10 -> V_137 = V_136 ( V_3 , V_132 ) ;
if ( V_10 -> V_137 ) {
if ( V_10 -> V_137 -> V_138 ) {
V_42 = V_10 -> V_137 -> V_138 ( V_10 -> V_137 ) ;
if ( V_42 ) {
F_32 ( & V_3 -> V_36 , L_17 ) ;
goto free;
}
}
V_10 -> V_119 = V_10 -> V_137 -> V_119 ;
V_10 -> V_29 = V_10 -> V_137 -> V_29 ;
}
V_11 -> V_139 = L_18 ;
V_11 -> V_140 = & V_141 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_142 = V_2 -> V_142 ;
V_11 -> V_23 = V_3 -> V_23 ;
V_42 = F_84 ( V_3 , V_133 , F_85 ( V_11 -> V_20 ) ) ;
if ( V_42 ) {
F_32 ( & V_3 -> V_36 , L_19 ) ;
goto V_143;
}
V_11 -> V_75 = F_86 ( V_3 , V_133 ) ;
if ( ! V_11 -> V_75 ) {
F_32 ( & V_3 -> V_36 , L_20 ) ;
V_42 = - V_144 ;
goto V_145;
}
if ( V_2 -> V_124 && V_2 -> V_124 -> V_146 ) {
V_42 = V_2 -> V_124 -> V_146 ( V_10 ) ;
if ( V_42 )
goto V_147;
}
if ( F_12 ( V_10 -> V_119 ) ) {
if ( ! F_13 ( V_10 -> V_119 , L_21 ) ) {
F_87 ( V_10 -> V_119 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_148 ;
} else {
F_18 ( & V_3 -> V_36 , L_22 ) ;
V_10 -> V_119 = - V_30 ;
}
}
V_11 -> V_20 -> V_149 = V_126 | V_123 ;
V_42 = F_88 ( V_11 ) ;
if ( V_42 )
goto remove;
F_11 ( V_10 ) ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_119 ) )
F_17 ( V_10 -> V_119 ) ;
if ( V_2 -> V_124 && V_2 -> V_124 -> V_150 )
V_2 -> V_124 -> V_150 ( V_10 , 0 ) ;
V_147:
F_89 ( V_11 -> V_75 ) ;
V_145:
F_90 ( V_3 , V_133 ) ;
V_143:
if ( V_10 -> V_137 && V_10 -> V_137 -> V_143 )
V_10 -> V_137 -> V_143 ( V_10 -> V_137 ) ;
free:
F_91 ( V_11 ) ;
return F_79 ( V_42 ) ;
}
static void F_92 ( struct V_9 * V_10 )
{
int V_89 ;
T_6 V_43 ;
F_19 ( V_10 ) ;
V_89 = 0 ;
V_43 = F_37 ( V_10 -> V_11 -> V_75 + V_151 ) ;
if ( V_43 == ( T_6 ) - 1 )
V_89 = 1 ;
F_93 ( V_10 -> V_11 , V_89 ) ;
if ( F_12 ( V_10 -> V_119 ) )
F_17 ( V_10 -> V_119 ) ;
if ( V_10 -> V_2 -> V_124 && V_10 -> V_2 -> V_124 -> V_150 )
V_10 -> V_2 -> V_124 -> V_150 ( V_10 , V_89 ) ;
if ( V_10 -> V_137 && V_10 -> V_137 -> V_143 )
V_10 -> V_137 -> V_143 ( V_10 -> V_137 ) ;
F_90 ( V_10 -> V_2 -> V_3 , V_10 -> V_135 ) ;
F_91 ( V_10 -> V_11 ) ;
}
static void T_5 F_94 ( struct V_44 * V_36 )
{
F_95 ( V_36 ) ;
F_96 ( V_36 ) ;
F_97 ( V_36 , 50 ) ;
F_98 ( V_36 ) ;
F_99 ( V_36 , 1 ) ;
}
static void T_7 F_100 ( struct V_44 * V_36 )
{
F_101 ( V_36 ) ;
F_102 ( V_36 ) ;
}
static int T_5 F_103 ( struct V_68 * V_3 ,
const struct V_152 * V_153 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_91 , V_131 ;
int V_42 , V_90 ;
F_104 ( V_3 == NULL ) ;
F_104 ( V_153 == NULL ) ;
F_31 ( & V_3 -> V_36 , L_23 ,
( int ) V_3 -> V_154 , ( int ) V_3 -> V_44 , ( int ) V_3 -> V_58 ) ;
V_42 = F_24 ( V_3 , V_155 , & V_91 ) ;
if ( V_42 )
return V_42 ;
V_91 = F_105 ( V_91 ) + 1 ;
F_106 ( & V_3 -> V_36 , L_24 , V_91 ) ;
if ( V_91 == 0 )
return - V_73 ;
F_104 ( V_91 > V_156 ) ;
V_42 = F_24 ( V_3 , V_155 , & V_131 ) ;
if ( V_42 )
return V_42 ;
V_131 &= V_157 ;
if ( V_131 > 5 ) {
F_32 ( & V_3 -> V_36 , L_25 ) ;
return - V_73 ;
}
V_42 = F_70 ( V_3 ) ;
if ( V_42 )
return V_42 ;
V_2 = F_107 ( sizeof( struct V_1 ) , V_158 ) ;
if ( ! V_2 ) {
V_42 = - V_144 ;
goto V_27;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_124 = ( const struct V_159 * ) V_153 -> V_160 ;
if ( V_2 -> V_124 ) {
V_2 -> V_7 = V_2 -> V_124 -> V_7 ;
V_2 -> V_142 = V_2 -> V_124 -> V_142 ;
V_2 -> V_161 = V_2 -> V_124 -> V_161 ;
}
V_2 -> V_22 = V_91 ;
F_108 ( V_3 , V_2 ) ;
if ( V_2 -> V_124 && V_2 -> V_124 -> V_162 ) {
V_42 = V_2 -> V_124 -> V_162 ( V_2 ) ;
if ( V_42 )
goto free;
}
V_91 = V_2 -> V_22 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
V_10 = F_77 ( V_3 , V_2 , V_131 , V_90 ) ;
if ( F_82 ( V_10 ) ) {
for ( V_90 -- ; V_90 >= 0 ; V_90 -- )
F_92 ( V_2 -> V_91 [ V_90 ] ) ;
V_42 = F_109 ( V_10 ) ;
goto free;
}
V_2 -> V_91 [ V_90 ] = V_10 ;
}
if ( V_2 -> V_161 )
F_94 ( & V_3 -> V_36 ) ;
return 0 ;
free:
F_108 ( V_3 , NULL ) ;
F_110 ( V_2 ) ;
V_27:
F_66 ( V_3 ) ;
return V_42 ;
}
static void T_7 F_111 ( struct V_68 * V_3 )
{
int V_90 ;
struct V_1 * V_2 ;
V_2 = F_59 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_161 )
F_100 ( & V_3 -> V_36 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_22 ; V_90 ++ )
F_92 ( V_2 -> V_91 [ V_90 ] ) ;
F_108 ( V_3 , NULL ) ;
F_110 ( V_2 ) ;
}
F_66 ( V_3 ) ;
}
static int T_8 F_112 ( void )
{
return F_113 ( & V_163 ) ;
}
static void T_9 F_114 ( void )
{
F_115 ( & V_163 ) ;
}
