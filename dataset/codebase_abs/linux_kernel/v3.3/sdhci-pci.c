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
static T_1 F_7 ( int V_23 , void * V_24 )
{
struct V_9 * V_10 = V_24 ;
struct V_25 * V_11 = V_10 -> V_11 ;
F_8 ( V_11 -> V_20 , F_9 ( 200 ) ) ;
return V_26 ;
}
static void F_10 ( struct V_9 * V_10 )
{
int V_27 , V_23 , V_28 = V_10 -> V_29 ;
V_10 -> V_29 = - V_30 ;
V_10 -> V_31 = - V_30 ;
if ( ! F_11 ( V_28 ) )
return;
V_27 = F_12 ( V_28 , L_1 ) ;
if ( V_27 < 0 )
goto V_32;
V_27 = F_13 ( V_28 ) ;
if ( V_27 < 0 )
goto V_33;
V_23 = F_14 ( V_28 ) ;
if ( V_23 < 0 )
goto V_33;
V_27 = F_15 ( V_23 , F_7 , V_34 |
V_35 , L_1 , V_10 ) ;
if ( V_27 )
goto V_33;
V_10 -> V_29 = V_28 ;
V_10 -> V_31 = V_23 ;
return;
V_33:
F_16 ( V_28 ) ;
V_32:
F_17 ( & V_10 -> V_2 -> V_3 -> V_36 , L_2 ) ;
}
static void F_18 ( struct V_9 * V_10 )
{
if ( V_10 -> V_31 >= 0 )
F_19 ( V_10 -> V_31 , V_10 ) ;
if ( F_11 ( V_10 -> V_29 ) )
F_16 ( V_10 -> V_29 ) ;
}
static inline void F_10 ( struct V_9 * V_10 )
{
}
static inline void F_18 ( struct V_9 * V_10 )
{
}
static int F_20 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_21 | V_37 ;
V_10 -> V_11 -> V_20 -> V_38 = V_39 ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_20 -> V_12 |= V_40 | V_37 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_41 ;
T_2 V_42 ;
switch ( V_2 -> V_3 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
V_41 = F_23 ( V_2 -> V_3 , V_48 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 &= 0x7f ;
F_24 ( V_2 -> V_3 , V_48 , V_42 ) ;
F_24 ( V_2 -> V_3 , V_49 , 0x08 ) ;
V_41 = F_23 ( V_2 -> V_3 , V_50 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 |= 0x20 ;
F_24 ( V_2 -> V_3 , V_50 , V_42 ) ;
V_41 = F_23 ( V_2 -> V_3 , V_51 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 |= 0x01 ;
F_24 ( V_2 -> V_3 , V_51 , V_42 ) ;
F_24 ( V_2 -> V_3 , V_51 , 0x73 ) ;
F_24 ( V_2 -> V_3 , V_52 , 0x39 ) ;
F_24 ( V_2 -> V_3 , V_53 , 0x08 ) ;
V_41 = F_23 ( V_2 -> V_3 , V_54 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 |= 0x08 ;
F_24 ( V_2 -> V_3 , V_54 , V_42 ) ;
V_41 = F_23 ( V_2 -> V_3 , V_48 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 |= 0x80 ;
F_24 ( V_2 -> V_3 , V_48 , V_42 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_55 )
{
T_2 V_42 ;
int V_41 ;
V_41 = F_23 ( V_2 -> V_3 , 0xAE , & V_42 ) ;
if ( V_41 )
return V_41 ;
if ( V_55 )
V_42 |= 0x47 ;
else
V_42 &= ~ 0x47 ;
V_41 = F_24 ( V_2 -> V_3 , 0xAE , V_42 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_41 ;
T_3 V_56 = 0 ;
if ( V_2 -> V_3 -> V_57 == 0 ) {
V_2 -> V_7 |= V_58 |
V_59 |
V_60 |
V_61 |
V_62 ;
}
if ( V_2 -> V_3 -> V_43 == V_63 )
V_56 = V_64 ;
else if ( V_2 -> V_3 -> V_43 == V_65 )
V_56 = V_66 ;
if ( V_56 ) {
struct V_67 * V_68 ;
V_68 = NULL ;
while ( ( V_68 = F_27 ( V_69 ,
V_56 , V_68 ) ) != NULL ) {
if ( ( F_28 ( V_2 -> V_3 -> V_70 ) ==
F_28 ( V_68 -> V_70 ) ) &&
( V_2 -> V_3 -> V_71 == V_68 -> V_71 ) )
break;
}
if ( V_68 ) {
F_29 ( V_68 ) ;
F_30 ( & V_2 -> V_3 -> V_36 , L_3
L_4 ) ;
return - V_72 ;
}
}
V_41 = F_25 ( V_2 , 1 ) ;
if ( V_41 ) {
F_31 ( & V_2 -> V_3 -> V_36 , L_5 ) ;
return V_41 ;
}
if ( V_2 -> V_3 -> V_43 == V_65 ||
V_2 -> V_3 -> V_43 == V_66 )
V_2 -> V_7 |= V_73 ;
return 0 ;
}
static void F_32 ( struct V_25 * V_11 , int V_55 )
{
T_2 V_42 ;
V_42 = F_33 ( V_11 -> V_74 + 0xC0 ) ;
if ( V_55 )
V_42 |= 0x01 ;
else
V_42 &= ~ 0x01 ;
F_34 ( V_42 , V_11 -> V_74 + 0xC0 ) ;
}
static int F_35 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_57 == 0 ) {
T_3 V_75 ;
V_75 = F_36 ( V_10 -> V_11 -> V_74 + V_76 ) ;
V_75 = ( V_75 & V_77 ) >>
V_78 ;
if ( V_75 < 0xAC )
V_10 -> V_11 -> V_7 |= V_79 ;
}
if ( V_10 -> V_2 -> V_3 -> V_43 == V_66 ) {
V_10 -> V_11 -> V_80 = V_81 | V_82 |
V_83 | V_84 |
V_85 ;
V_10 -> V_11 -> V_86 = V_81 | V_82 |
V_83 | V_84 ;
}
if ( V_10 -> V_2 -> V_3 -> V_43 == V_64 ||
V_10 -> V_2 -> V_3 -> V_43 == V_66 )
F_32 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_87 ;
return 0 ;
}
static void F_37 ( struct V_9 * V_10 , int V_88 )
{
if ( V_88 )
return;
if ( V_10 -> V_2 -> V_3 -> V_43 == V_64 ||
V_10 -> V_2 -> V_3 -> V_43 == V_66 )
F_32 ( V_10 -> V_11 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_89 ;
if ( V_2 -> V_3 -> V_43 == V_64 ||
V_2 -> V_3 -> V_43 == V_66 ) {
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ )
F_32 ( V_2 -> V_90 [ V_89 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_41 , V_89 ;
if ( V_2 -> V_3 -> V_43 == V_64 ||
V_2 -> V_3 -> V_43 == V_66 ) {
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ )
F_32 ( V_2 -> V_90 [ V_89 ] -> V_11 , 1 ) ;
}
V_41 = F_25 ( V_2 , 1 ) ;
if ( V_41 ) {
F_31 ( & V_2 -> V_3 -> V_36 , L_5 ) ;
return V_41 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_91 & 0x0000FF ) == V_92 ) {
V_2 -> V_3 -> V_91 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_91 |= V_93 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
int V_94 , V_95 ;
T_2 V_96 = F_33 ( V_10 -> V_11 -> V_74 + V_97 ) ;
T_2 V_98 = F_33 ( V_10 -> V_11 -> V_74 + V_99 ) ;
F_30 ( & V_10 -> V_2 -> V_3 -> V_36 , L_6
L_7 ,
V_96 >> 4 , V_96 & 0xf ,
V_98 >> 4 , V_98 & 0xf ) ;
if ( V_98 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_100 ;
F_34 ( V_101 , V_10 -> V_11 -> V_74 + V_102 ) ;
F_34 ( V_103 , V_10 -> V_11 -> V_74 + V_104 ) ;
F_42 ( 50 ) ;
V_94 = 10 ;
do {
V_95 = F_43 ( V_10 -> V_11 -> V_74 + V_105 ) ;
if ( V_95 & V_106 )
break;
F_42 ( 100 ) ;
} while ( -- V_94 );
if ( ! V_94 ) {
F_31 ( & V_10 -> V_2 -> V_3 -> V_36 ,
L_8 ) ;
F_34 ( 0 , V_10 -> V_11 -> V_74 + V_104 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_57 == 0x10 )
V_2 -> V_7 |= V_107 ;
return 0 ;
}
static int F_45 ( struct V_25 * V_11 )
{
struct V_9 * V_10 ;
struct V_67 * V_3 ;
int V_41 ;
V_10 = F_46 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_91 & 0xFFFF00 ) == ( V_108 << 8 ) ) &&
( ( V_3 -> V_91 & 0x0000FF ) != V_93 ) &&
( V_11 -> V_109 & V_110 ) ) {
F_17 ( & V_3 -> V_36 , L_9
L_10 ) ;
}
V_41 = F_47 ( V_3 , F_48 ( 32 ) ) ;
if ( V_41 )
return V_41 ;
F_49 ( V_3 ) ;
return 0 ;
}
static int F_50 ( struct V_25 * V_11 , int V_111 )
{
T_2 V_112 ;
V_112 = F_51 ( V_11 , V_113 ) ;
switch ( V_111 ) {
case V_114 :
V_112 |= V_115 ;
V_112 &= ~ V_116 ;
break;
case V_117 :
V_112 |= V_116 ;
V_112 &= ~ V_115 ;
break;
default:
V_112 &= ~ ( V_115 | V_116 ) ;
break;
}
F_52 ( V_11 , V_112 , V_113 ) ;
return 0 ;
}
static void F_53 ( struct V_25 * V_11 )
{
struct V_9 * V_10 = F_46 ( V_11 ) ;
int V_118 = V_10 -> V_118 ;
if ( ! F_11 ( V_118 ) )
return;
F_54 ( V_118 , 0 ) ;
F_42 ( 10 ) ;
F_54 ( V_118 , 1 ) ;
F_55 ( 300 , 1000 ) ;
}
static int F_56 ( struct V_43 * V_36 )
{
struct V_67 * V_3 = F_57 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_119 ;
T_4 V_120 = 0 ;
int V_89 , V_41 ;
V_2 = F_58 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ ) {
V_10 = V_2 -> V_90 [ V_89 ] ;
if ( ! V_10 )
continue;
V_41 = F_59 ( V_10 -> V_11 ) ;
if ( V_41 )
goto V_121;
V_119 = V_10 -> V_11 -> V_20 -> V_120 ;
if ( V_119 & V_122 )
F_60 ( V_10 -> V_11 ) ;
V_120 |= V_119 ;
}
if ( V_2 -> V_123 && V_2 -> V_123 -> V_124 ) {
V_41 = V_2 -> V_123 -> V_124 ( V_2 ) ;
if ( V_41 )
goto V_121;
}
F_61 ( V_3 ) ;
if ( V_120 & V_125 ) {
if ( V_120 & V_122 ) {
F_62 ( V_3 , true ) ;
F_63 ( V_3 , V_126 , 1 ) ;
}
F_64 ( V_3 , V_126 ) ;
} else {
F_63 ( V_3 , V_126 , 0 ) ;
F_65 ( V_3 ) ;
F_64 ( V_3 , V_126 ) ;
}
return 0 ;
V_121:
while ( -- V_89 >= 0 )
F_66 ( V_2 -> V_90 [ V_89 ] -> V_11 ) ;
return V_41 ;
}
static int F_67 ( struct V_43 * V_36 )
{
struct V_67 * V_3 = F_57 ( V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_89 , V_41 ;
V_2 = F_58 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_64 ( V_3 , V_127 ) ;
F_68 ( V_3 ) ;
V_41 = F_69 ( V_3 ) ;
if ( V_41 )
return V_41 ;
if ( V_2 -> V_123 && V_2 -> V_123 -> V_128 ) {
V_41 = V_2 -> V_123 -> V_128 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ ) {
V_10 = V_2 -> V_90 [ V_89 ] ;
if ( ! V_10 )
continue;
V_41 = F_66 ( V_10 -> V_11 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_70 ( struct V_43 * V_36 )
{
struct V_67 * V_3 = F_71 ( V_36 , struct V_67 , V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_89 , V_41 ;
V_2 = F_58 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ ) {
V_10 = V_2 -> V_90 [ V_89 ] ;
if ( ! V_10 )
continue;
V_41 = F_72 ( V_10 -> V_11 ) ;
if ( V_41 )
goto V_129;
}
if ( V_2 -> V_123 && V_2 -> V_123 -> V_124 ) {
V_41 = V_2 -> V_123 -> V_124 ( V_2 ) ;
if ( V_41 )
goto V_129;
}
return 0 ;
V_129:
while ( -- V_89 >= 0 )
F_73 ( V_2 -> V_90 [ V_89 ] -> V_11 ) ;
return V_41 ;
}
static int F_74 ( struct V_43 * V_36 )
{
struct V_67 * V_3 = F_71 ( V_36 , struct V_67 , V_36 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_89 , V_41 ;
V_2 = F_58 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_123 && V_2 -> V_123 -> V_128 ) {
V_41 = V_2 -> V_123 -> V_128 ( V_2 ) ;
if ( V_41 )
return V_41 ;
}
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ ) {
V_10 = V_2 -> V_90 [ V_89 ] ;
if ( ! V_10 )
continue;
V_41 = F_73 ( V_10 -> V_11 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_75 ( struct V_43 * V_36 )
{
return 0 ;
}
static struct V_9 * T_5 F_76 (
struct V_67 * V_3 , struct V_1 * V_2 , int V_130 ,
int V_131 )
{
struct V_9 * V_10 ;
struct V_25 * V_11 ;
int V_41 , V_132 = V_130 + V_131 ;
if ( ! ( F_77 ( V_3 , V_132 ) & V_133 ) ) {
F_31 ( & V_3 -> V_36 , L_11 , V_132 ) ;
return F_78 ( - V_72 ) ;
}
if ( F_79 ( V_3 , V_132 ) != 0x100 ) {
F_31 ( & V_3 -> V_36 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_91 & 0x0000FF ) == V_92 ) {
F_31 ( & V_3 -> V_36 , L_14 ) ;
return F_78 ( - V_72 ) ;
}
if ( ( V_3 -> V_91 & 0x0000FF ) > V_92 ) {
F_31 ( & V_3 -> V_36 , L_15 ) ;
return F_78 ( - V_72 ) ;
}
V_11 = F_80 ( & V_3 -> V_36 , sizeof( struct V_9 ) ) ;
if ( F_81 ( V_11 ) ) {
F_31 ( & V_3 -> V_36 , L_16 ) ;
return F_82 ( V_11 ) ;
}
V_10 = F_46 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_134 = V_132 ;
V_10 -> V_118 = - V_30 ;
V_10 -> V_29 = - V_30 ;
if ( * V_135 )
V_10 -> V_136 = V_135 ( V_3 , V_131 ) ;
if ( V_10 -> V_136 ) {
if ( V_10 -> V_136 -> V_137 ) {
V_41 = V_10 -> V_136 -> V_137 ( V_10 -> V_136 ) ;
if ( V_41 ) {
F_31 ( & V_3 -> V_36 , L_17 ) ;
goto free;
}
}
V_10 -> V_118 = V_10 -> V_136 -> V_118 ;
V_10 -> V_29 = V_10 -> V_136 -> V_29 ;
}
V_11 -> V_138 = L_18 ;
V_11 -> V_139 = & V_140 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_23 = V_3 -> V_23 ;
V_41 = F_83 ( V_3 , V_132 , F_84 ( V_11 -> V_20 ) ) ;
if ( V_41 ) {
F_31 ( & V_3 -> V_36 , L_19 ) ;
goto V_141;
}
V_11 -> V_74 = F_85 ( V_3 , V_132 ) ;
if ( ! V_11 -> V_74 ) {
F_31 ( & V_3 -> V_36 , L_20 ) ;
V_41 = - V_142 ;
goto V_143;
}
if ( V_2 -> V_123 && V_2 -> V_123 -> V_144 ) {
V_41 = V_2 -> V_123 -> V_144 ( V_10 ) ;
if ( V_41 )
goto V_145;
}
if ( F_11 ( V_10 -> V_118 ) ) {
if ( ! F_12 ( V_10 -> V_118 , L_21 ) ) {
F_86 ( V_10 -> V_118 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_146 ;
} else {
F_17 ( & V_3 -> V_36 , L_22 ) ;
V_10 -> V_118 = - V_30 ;
}
}
V_11 -> V_20 -> V_147 = V_125 | V_122 ;
V_41 = F_87 ( V_11 ) ;
if ( V_41 )
goto remove;
F_10 ( V_10 ) ;
return V_10 ;
remove:
if ( F_11 ( V_10 -> V_118 ) )
F_16 ( V_10 -> V_118 ) ;
if ( V_2 -> V_123 && V_2 -> V_123 -> V_148 )
V_2 -> V_123 -> V_148 ( V_10 , 0 ) ;
V_145:
F_88 ( V_11 -> V_74 ) ;
V_143:
F_89 ( V_3 , V_132 ) ;
V_141:
if ( V_10 -> V_136 && V_10 -> V_136 -> V_141 )
V_10 -> V_136 -> V_141 ( V_10 -> V_136 ) ;
free:
F_90 ( V_11 ) ;
return F_78 ( V_41 ) ;
}
static void F_91 ( struct V_9 * V_10 )
{
int V_88 ;
T_6 V_42 ;
F_18 ( V_10 ) ;
V_88 = 0 ;
V_42 = F_36 ( V_10 -> V_11 -> V_74 + V_149 ) ;
if ( V_42 == ( T_6 ) - 1 )
V_88 = 1 ;
F_92 ( V_10 -> V_11 , V_88 ) ;
if ( F_11 ( V_10 -> V_118 ) )
F_16 ( V_10 -> V_118 ) ;
if ( V_10 -> V_2 -> V_123 && V_10 -> V_2 -> V_123 -> V_148 )
V_10 -> V_2 -> V_123 -> V_148 ( V_10 , V_88 ) ;
if ( V_10 -> V_136 && V_10 -> V_136 -> V_141 )
V_10 -> V_136 -> V_141 ( V_10 -> V_136 ) ;
F_89 ( V_10 -> V_2 -> V_3 , V_10 -> V_134 ) ;
F_90 ( V_10 -> V_11 ) ;
}
static void T_5 F_93 ( struct V_43 * V_36 )
{
F_94 ( V_36 ) ;
F_95 ( V_36 ) ;
F_96 ( V_36 , 50 ) ;
F_97 ( V_36 ) ;
F_98 ( V_36 , 1 ) ;
}
static void T_7 F_99 ( struct V_43 * V_36 )
{
F_100 ( V_36 ) ;
F_101 ( V_36 ) ;
}
static int T_5 F_102 ( struct V_67 * V_3 ,
const struct V_150 * V_151 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_90 , V_130 ;
int V_41 , V_89 ;
F_103 ( V_3 == NULL ) ;
F_103 ( V_151 == NULL ) ;
F_30 ( & V_3 -> V_36 , L_23 ,
( int ) V_3 -> V_152 , ( int ) V_3 -> V_43 , ( int ) V_3 -> V_57 ) ;
V_41 = F_23 ( V_3 , V_153 , & V_90 ) ;
if ( V_41 )
return V_41 ;
V_90 = F_104 ( V_90 ) + 1 ;
F_105 ( & V_3 -> V_36 , L_24 , V_90 ) ;
if ( V_90 == 0 )
return - V_72 ;
F_103 ( V_90 > V_154 ) ;
V_41 = F_23 ( V_3 , V_153 , & V_130 ) ;
if ( V_41 )
return V_41 ;
V_130 &= V_155 ;
if ( V_130 > 5 ) {
F_31 ( & V_3 -> V_36 , L_25 ) ;
return - V_72 ;
}
V_41 = F_69 ( V_3 ) ;
if ( V_41 )
return V_41 ;
V_2 = F_106 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_2 ) {
V_41 = - V_142 ;
goto V_27;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_123 = ( const struct V_157 * ) V_151 -> V_158 ;
if ( V_2 -> V_123 ) {
V_2 -> V_7 = V_2 -> V_123 -> V_7 ;
V_2 -> V_159 = V_2 -> V_123 -> V_159 ;
}
V_2 -> V_22 = V_90 ;
F_107 ( V_3 , V_2 ) ;
if ( V_2 -> V_123 && V_2 -> V_123 -> V_160 ) {
V_41 = V_2 -> V_123 -> V_160 ( V_2 ) ;
if ( V_41 )
goto free;
}
V_90 = V_2 -> V_22 ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_10 = F_76 ( V_3 , V_2 , V_130 , V_89 ) ;
if ( F_81 ( V_10 ) ) {
for ( V_89 -- ; V_89 >= 0 ; V_89 -- )
F_91 ( V_2 -> V_90 [ V_89 ] ) ;
V_41 = F_108 ( V_10 ) ;
goto free;
}
V_2 -> V_90 [ V_89 ] = V_10 ;
}
if ( V_2 -> V_159 )
F_93 ( & V_3 -> V_36 ) ;
return 0 ;
free:
F_107 ( V_3 , NULL ) ;
F_109 ( V_2 ) ;
V_27:
F_65 ( V_3 ) ;
return V_41 ;
}
static void T_7 F_110 ( struct V_67 * V_3 )
{
int V_89 ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_3 ) ;
if ( V_2 ) {
if ( V_2 -> V_159 )
F_99 ( & V_3 -> V_36 ) ;
for ( V_89 = 0 ; V_89 < V_2 -> V_22 ; V_89 ++ )
F_91 ( V_2 -> V_90 [ V_89 ] ) ;
F_107 ( V_3 , NULL ) ;
F_109 ( V_2 ) ;
}
F_65 ( V_3 ) ;
}
static int T_8 F_111 ( void )
{
return F_112 ( & V_161 ) ;
}
static void T_9 F_113 ( void )
{
F_114 ( & V_161 ) ;
}
