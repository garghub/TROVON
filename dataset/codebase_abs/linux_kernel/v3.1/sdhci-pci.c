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
static int F_8 ( struct V_1 * V_2 )
{
int V_23 ;
T_1 V_24 ;
switch ( V_2 -> V_3 -> V_25 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_23 = F_9 ( V_2 -> V_3 , V_30 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 &= 0x7f ;
F_10 ( V_2 -> V_3 , V_30 , V_24 ) ;
F_10 ( V_2 -> V_3 , V_31 , 0x08 ) ;
V_23 = F_9 ( V_2 -> V_3 , V_32 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 |= 0x20 ;
F_10 ( V_2 -> V_3 , V_32 , V_24 ) ;
V_23 = F_9 ( V_2 -> V_3 , V_33 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 |= 0x01 ;
F_10 ( V_2 -> V_3 , V_33 , V_24 ) ;
F_10 ( V_2 -> V_3 , V_33 , 0x73 ) ;
F_10 ( V_2 -> V_3 , V_34 , 0x39 ) ;
F_10 ( V_2 -> V_3 , V_35 , 0x08 ) ;
V_23 = F_9 ( V_2 -> V_3 , V_36 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 |= 0x08 ;
F_10 ( V_2 -> V_3 , V_36 , V_24 ) ;
V_23 = F_9 ( V_2 -> V_3 , V_30 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_24 |= 0x80 ;
F_10 ( V_2 -> V_3 , V_30 , V_24 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_37 )
{
T_1 V_24 ;
int V_23 ;
V_23 = F_9 ( V_2 -> V_3 , 0xAE , & V_24 ) ;
if ( V_23 )
return V_23 ;
if ( V_37 )
V_24 |= 0x47 ;
else
V_24 &= ~ 0x47 ;
V_23 = F_10 ( V_2 -> V_3 , 0xAE , V_24 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_23 ;
T_2 V_38 = 0 ;
if ( V_2 -> V_3 -> V_39 == 0 ) {
V_2 -> V_7 |= V_40 |
V_41 |
V_42 |
V_43 |
V_44 ;
}
if ( V_2 -> V_3 -> V_25 == V_45 )
V_38 = V_46 ;
else if ( V_2 -> V_3 -> V_25 == V_47 )
V_38 = V_48 ;
if ( V_38 ) {
struct V_49 * V_50 ;
V_50 = NULL ;
while ( ( V_50 = F_13 ( V_51 ,
V_38 , V_50 ) ) != NULL ) {
if ( ( F_14 ( V_2 -> V_3 -> V_52 ) ==
F_14 ( V_50 -> V_52 ) ) &&
( V_2 -> V_3 -> V_53 == V_50 -> V_53 ) )
break;
}
if ( V_50 ) {
F_15 ( V_50 ) ;
F_16 ( & V_2 -> V_3 -> V_54 , L_1
L_2 ) ;
return - V_55 ;
}
}
V_23 = F_11 ( V_2 , 1 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_3 -> V_54 , L_3 ) ;
return V_23 ;
}
if ( V_2 -> V_3 -> V_25 == V_47 ||
V_2 -> V_3 -> V_25 == V_48 )
V_2 -> V_7 |= V_56 ;
return 0 ;
}
static void F_18 ( struct V_57 * V_11 , int V_37 )
{
T_1 V_24 ;
V_24 = F_19 ( V_11 -> V_58 + 0xC0 ) ;
if ( V_37 )
V_24 |= 0x01 ;
else
V_24 &= ~ 0x01 ;
F_20 ( V_24 , V_11 -> V_58 + 0xC0 ) ;
}
static int F_21 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_39 == 0 ) {
T_2 V_59 ;
V_59 = F_22 ( V_10 -> V_11 -> V_58 + V_60 ) ;
V_59 = ( V_59 & V_61 ) >>
V_62 ;
if ( V_59 < 0xAC )
V_10 -> V_11 -> V_7 |= V_63 ;
}
if ( V_10 -> V_2 -> V_3 -> V_25 == V_48 ) {
V_10 -> V_11 -> V_64 = V_65 | V_66 |
V_67 | V_68 |
V_69 ;
V_10 -> V_11 -> V_70 = V_65 | V_66 |
V_67 | V_68 ;
}
if ( V_10 -> V_2 -> V_3 -> V_25 == V_46 ||
V_10 -> V_2 -> V_3 -> V_25 == V_48 )
F_18 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_20 -> V_12 |= V_71 ;
return 0 ;
}
static void F_23 ( struct V_9 * V_10 , int V_72 )
{
if ( V_72 )
return;
if ( V_10 -> V_2 -> V_3 -> V_25 == V_46 ||
V_10 -> V_2 -> V_3 -> V_25 == V_48 )
F_18 ( V_10 -> V_11 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_3 V_73 )
{
int V_74 ;
if ( V_2 -> V_3 -> V_25 == V_46 ||
V_2 -> V_3 -> V_25 == V_48 ) {
for ( V_74 = 0 ; V_74 < V_2 -> V_22 ; V_74 ++ )
F_18 ( V_2 -> V_75 [ V_74 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_23 , V_74 ;
if ( V_2 -> V_3 -> V_25 == V_46 ||
V_2 -> V_3 -> V_25 == V_48 ) {
for ( V_74 = 0 ; V_74 < V_2 -> V_22 ; V_74 ++ )
F_18 ( V_2 -> V_75 [ V_74 ] -> V_11 , 1 ) ;
}
V_23 = F_11 ( V_2 , 1 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_3 -> V_54 , L_3 ) ;
return V_23 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_76 & 0x0000FF ) == V_77 ) {
V_2 -> V_3 -> V_76 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_76 |= V_78 ;
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
int V_79 , V_80 ;
T_1 V_81 = F_19 ( V_10 -> V_11 -> V_58 + V_82 ) ;
T_1 V_83 = F_19 ( V_10 -> V_11 -> V_58 + V_84 ) ;
F_16 ( & V_10 -> V_2 -> V_3 -> V_54 , L_4
L_5 ,
V_81 >> 4 , V_81 & 0xf ,
V_83 >> 4 , V_83 & 0xf ) ;
if ( V_83 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_85 ;
F_20 ( V_86 , V_10 -> V_11 -> V_58 + V_87 ) ;
F_20 ( V_88 , V_10 -> V_11 -> V_58 + V_89 ) ;
F_28 ( 50 ) ;
V_79 = 10 ;
do {
V_80 = F_29 ( V_10 -> V_11 -> V_58 + V_90 ) ;
if ( V_80 & V_91 )
break;
F_28 ( 100 ) ;
} while ( -- V_79 );
if ( ! V_79 ) {
F_17 ( & V_10 -> V_2 -> V_3 -> V_54 ,
L_6 ) ;
F_20 ( 0 , V_10 -> V_11 -> V_58 + V_89 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_39 == 0x10 )
V_2 -> V_7 |= V_92 ;
return 0 ;
}
static int F_31 ( struct V_57 * V_11 )
{
struct V_9 * V_10 ;
struct V_49 * V_3 ;
int V_23 ;
V_10 = F_32 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_76 & 0xFFFF00 ) == ( V_93 << 8 ) ) &&
( ( V_3 -> V_76 & 0x0000FF ) != V_78 ) &&
( V_11 -> V_94 & V_95 ) ) {
F_33 ( & V_3 -> V_54 , L_7
L_8 ) ;
}
V_23 = F_34 ( V_3 , F_35 ( 32 ) ) ;
if ( V_23 )
return V_23 ;
F_36 ( V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_57 * V_11 , int V_96 )
{
T_1 V_97 ;
V_97 = F_38 ( V_11 , V_98 ) ;
switch ( V_96 ) {
case V_99 :
V_97 |= V_100 ;
V_97 &= ~ V_101 ;
break;
case V_102 :
V_97 |= V_101 ;
V_97 &= ~ V_100 ;
break;
default:
V_97 &= ~ ( V_100 | V_101 ) ;
break;
}
F_39 ( V_11 , V_97 , V_98 ) ;
return 0 ;
}
static int F_40 ( struct V_49 * V_3 , T_3 V_73 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_103 ;
T_4 V_104 = 0 ;
int V_74 , V_23 ;
V_2 = F_41 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_22 ; V_74 ++ ) {
V_10 = V_2 -> V_75 [ V_74 ] ;
if ( ! V_10 )
continue;
V_23 = F_42 ( V_10 -> V_11 , V_73 ) ;
if ( V_23 ) {
for ( V_74 -- ; V_74 >= 0 ; V_74 -- )
F_43 ( V_2 -> V_75 [ V_74 ] -> V_11 ) ;
return V_23 ;
}
V_103 = V_10 -> V_11 -> V_20 -> V_104 ;
if ( V_103 & V_105 )
F_44 ( V_10 -> V_11 ) ;
V_104 |= V_103 ;
}
if ( V_2 -> V_106 && V_2 -> V_106 -> V_107 ) {
V_23 = V_2 -> V_106 -> V_107 ( V_2 , V_73 ) ;
if ( V_23 ) {
for ( V_74 = V_2 -> V_22 - 1 ; V_74 >= 0 ; V_74 -- )
F_43 ( V_2 -> V_75 [ V_74 ] -> V_11 ) ;
return V_23 ;
}
}
F_45 ( V_3 ) ;
if ( V_104 & V_108 ) {
if ( V_104 & V_105 ) {
F_46 ( V_3 , true ) ;
F_47 ( V_3 , V_109 , 1 ) ;
}
F_48 ( V_3 , V_109 ) ;
} else {
F_47 ( V_3 , F_49 ( V_3 , V_73 ) , 0 ) ;
F_50 ( V_3 ) ;
F_48 ( V_3 , F_49 ( V_3 , V_73 ) ) ;
}
return 0 ;
}
static int F_51 ( struct V_49 * V_3 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_74 , V_23 ;
V_2 = F_41 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_48 ( V_3 , V_110 ) ;
F_52 ( V_3 ) ;
V_23 = F_53 ( V_3 ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_106 && V_2 -> V_106 -> V_111 ) {
V_23 = V_2 -> V_106 -> V_111 ( V_2 ) ;
if ( V_23 )
return V_23 ;
}
for ( V_74 = 0 ; V_74 < V_2 -> V_22 ; V_74 ++ ) {
V_10 = V_2 -> V_75 [ V_74 ] ;
if ( ! V_10 )
continue;
V_23 = F_43 ( V_10 -> V_11 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static struct V_9 * T_5 F_54 (
struct V_49 * V_3 , struct V_1 * V_2 , int V_112 )
{
struct V_9 * V_10 ;
struct V_57 * V_11 ;
int V_23 ;
if ( ! ( F_55 ( V_3 , V_112 ) & V_113 ) ) {
F_17 ( & V_3 -> V_54 , L_9 , V_112 ) ;
return F_56 ( - V_55 ) ;
}
if ( F_57 ( V_3 , V_112 ) != 0x100 ) {
F_17 ( & V_3 -> V_54 , L_10
L_11 ) ;
}
if ( ( V_3 -> V_76 & 0x0000FF ) == V_77 ) {
F_17 ( & V_3 -> V_54 , L_12 ) ;
return F_56 ( - V_55 ) ;
}
if ( ( V_3 -> V_76 & 0x0000FF ) > V_77 ) {
F_17 ( & V_3 -> V_54 , L_13 ) ;
return F_56 ( - V_55 ) ;
}
V_11 = F_58 ( & V_3 -> V_54 , sizeof( struct V_9 ) ) ;
if ( F_59 ( V_11 ) ) {
F_17 ( & V_3 -> V_54 , L_14 ) ;
return F_60 ( V_11 ) ;
}
V_10 = F_32 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_114 = V_112 ;
V_11 -> V_115 = L_15 ;
V_11 -> V_116 = & V_117 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_118 = V_3 -> V_118 ;
V_23 = F_61 ( V_3 , V_112 , F_62 ( V_11 -> V_20 ) ) ;
if ( V_23 ) {
F_17 ( & V_3 -> V_54 , L_16 ) ;
goto free;
}
V_11 -> V_58 = F_63 ( V_3 , V_112 ) ;
if ( ! V_11 -> V_58 ) {
F_17 ( & V_3 -> V_54 , L_17 ) ;
V_23 = - V_119 ;
goto V_120;
}
if ( V_2 -> V_106 && V_2 -> V_106 -> V_121 ) {
V_23 = V_2 -> V_106 -> V_121 ( V_10 ) ;
if ( V_23 )
goto V_122;
}
V_11 -> V_20 -> V_123 = V_108 | V_105 ;
V_23 = F_64 ( V_11 ) ;
if ( V_23 )
goto remove;
return V_10 ;
remove:
if ( V_2 -> V_106 && V_2 -> V_106 -> V_124 )
V_2 -> V_106 -> V_124 ( V_10 , 0 ) ;
V_122:
F_65 ( V_11 -> V_58 ) ;
V_120:
F_66 ( V_3 , V_112 ) ;
free:
F_67 ( V_11 ) ;
return F_56 ( V_23 ) ;
}
static void F_68 ( struct V_9 * V_10 )
{
int V_72 ;
T_6 V_24 ;
V_72 = 0 ;
V_24 = F_22 ( V_10 -> V_11 -> V_58 + V_125 ) ;
if ( V_24 == ( T_6 ) - 1 )
V_72 = 1 ;
F_69 ( V_10 -> V_11 , V_72 ) ;
if ( V_10 -> V_2 -> V_106 && V_10 -> V_2 -> V_106 -> V_124 )
V_10 -> V_2 -> V_106 -> V_124 ( V_10 , V_72 ) ;
F_66 ( V_10 -> V_2 -> V_3 , V_10 -> V_114 ) ;
F_67 ( V_10 -> V_11 ) ;
}
static int T_5 F_70 ( struct V_49 * V_3 ,
const struct V_126 * V_127 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_1 V_75 , V_128 ;
int V_23 , V_74 ;
F_71 ( V_3 == NULL ) ;
F_71 ( V_127 == NULL ) ;
F_16 ( & V_3 -> V_54 , L_18 ,
( int ) V_3 -> V_129 , ( int ) V_3 -> V_25 , ( int ) V_3 -> V_39 ) ;
V_23 = F_9 ( V_3 , V_130 , & V_75 ) ;
if ( V_23 )
return V_23 ;
V_75 = F_72 ( V_75 ) + 1 ;
F_73 ( & V_3 -> V_54 , L_19 , V_75 ) ;
if ( V_75 == 0 )
return - V_55 ;
F_71 ( V_75 > V_131 ) ;
V_23 = F_9 ( V_3 , V_130 , & V_128 ) ;
if ( V_23 )
return V_23 ;
V_128 &= V_132 ;
if ( V_128 > 5 ) {
F_17 ( & V_3 -> V_54 , L_20 ) ;
return - V_55 ;
}
V_23 = F_53 ( V_3 ) ;
if ( V_23 )
return V_23 ;
V_2 = F_74 ( sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_2 ) {
V_23 = - V_119 ;
goto V_134;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_106 = ( const struct V_135 * ) V_127 -> V_136 ;
if ( V_2 -> V_106 )
V_2 -> V_7 = V_2 -> V_106 -> V_7 ;
V_2 -> V_22 = V_75 ;
F_75 ( V_3 , V_2 ) ;
if ( V_2 -> V_106 && V_2 -> V_106 -> V_137 ) {
V_23 = V_2 -> V_106 -> V_137 ( V_2 ) ;
if ( V_23 )
goto free;
}
V_75 = V_2 -> V_22 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
V_10 = F_54 ( V_3 , V_2 , V_128 + V_74 ) ;
if ( F_59 ( V_10 ) ) {
for ( V_74 -- ; V_74 >= 0 ; V_74 -- )
F_68 ( V_2 -> V_75 [ V_74 ] ) ;
V_23 = F_76 ( V_10 ) ;
goto free;
}
V_2 -> V_75 [ V_74 ] = V_10 ;
}
return 0 ;
free:
F_75 ( V_3 , NULL ) ;
F_77 ( V_2 ) ;
V_134:
F_50 ( V_3 ) ;
return V_23 ;
}
static void T_7 F_78 ( struct V_49 * V_3 )
{
int V_74 ;
struct V_1 * V_2 ;
V_2 = F_41 ( V_3 ) ;
if ( V_2 ) {
for ( V_74 = 0 ; V_74 < V_2 -> V_22 ; V_74 ++ )
F_68 ( V_2 -> V_75 [ V_74 ] ) ;
F_75 ( V_3 , NULL ) ;
F_77 ( V_2 ) ;
}
F_50 ( V_3 ) ;
}
static int T_8 F_79 ( void )
{
return F_80 ( & V_138 ) ;
}
static void T_9 F_81 ( void )
{
F_82 ( & V_138 ) ;
}
