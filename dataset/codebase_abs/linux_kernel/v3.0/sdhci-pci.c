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
static int F_5 ( struct V_1 * V_2 )
{
V_2 -> V_20 = 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_21 ;
T_1 V_22 ;
switch ( V_2 -> V_3 -> V_23 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_21 = F_7 ( V_2 -> V_3 , V_28 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 &= 0x7f ;
F_8 ( V_2 -> V_3 , V_28 , V_22 ) ;
F_8 ( V_2 -> V_3 , V_29 , 0x08 ) ;
V_21 = F_7 ( V_2 -> V_3 , V_30 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 |= 0x20 ;
F_8 ( V_2 -> V_3 , V_30 , V_22 ) ;
V_21 = F_7 ( V_2 -> V_3 , V_31 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 |= 0x01 ;
F_8 ( V_2 -> V_3 , V_31 , V_22 ) ;
F_8 ( V_2 -> V_3 , V_31 , 0x73 ) ;
F_8 ( V_2 -> V_3 , V_32 , 0x39 ) ;
F_8 ( V_2 -> V_3 , V_33 , 0x08 ) ;
V_21 = F_7 ( V_2 -> V_3 , V_34 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 |= 0x08 ;
F_8 ( V_2 -> V_3 , V_34 , V_22 ) ;
V_21 = F_7 ( V_2 -> V_3 , V_28 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 |= 0x80 ;
F_8 ( V_2 -> V_3 , V_28 , V_22 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_35 )
{
T_1 V_22 ;
int V_21 ;
V_21 = F_7 ( V_2 -> V_3 , 0xAE , & V_22 ) ;
if ( V_21 )
return V_21 ;
if ( V_35 )
V_22 |= 0x47 ;
else
V_22 &= ~ 0x47 ;
V_21 = F_8 ( V_2 -> V_3 , 0xAE , V_22 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_21 ;
T_2 V_36 = 0 ;
if ( V_2 -> V_3 -> V_37 == 0 ) {
V_2 -> V_7 |= V_38 |
V_39 |
V_40 |
V_41 |
V_42 ;
}
if ( V_2 -> V_3 -> V_23 == V_43 )
V_36 = V_44 ;
else if ( V_2 -> V_3 -> V_23 == V_45 )
V_36 = V_46 ;
if ( V_36 ) {
struct V_47 * V_48 ;
V_48 = NULL ;
while ( ( V_48 = F_11 ( V_49 ,
V_36 , V_48 ) ) != NULL ) {
if ( ( F_12 ( V_2 -> V_3 -> V_50 ) ==
F_12 ( V_48 -> V_50 ) ) &&
( V_2 -> V_3 -> V_51 == V_48 -> V_51 ) )
break;
}
if ( V_48 ) {
F_13 ( V_48 ) ;
F_14 ( & V_2 -> V_3 -> V_52 , L_1
L_2 ) ;
return - V_53 ;
}
}
V_21 = F_9 ( V_2 , 1 ) ;
if ( V_21 ) {
F_15 ( & V_2 -> V_3 -> V_52 , L_3 ) ;
return V_21 ;
}
if ( V_2 -> V_3 -> V_23 == V_45 ||
V_2 -> V_3 -> V_23 == V_46 )
V_2 -> V_7 |= V_54 ;
return 0 ;
}
static void F_16 ( struct V_55 * V_11 , int V_35 )
{
T_1 V_22 ;
V_22 = F_17 ( V_11 -> V_56 + 0xC0 ) ;
if ( V_35 )
V_22 |= 0x01 ;
else
V_22 &= ~ 0x01 ;
F_18 ( V_22 , V_11 -> V_56 + 0xC0 ) ;
}
static int F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_37 == 0 ) {
T_2 V_57 ;
V_57 = F_20 ( V_10 -> V_11 -> V_56 + V_58 ) ;
V_57 = ( V_57 & V_59 ) >>
V_60 ;
if ( V_57 < 0xAC )
V_10 -> V_11 -> V_7 |= V_61 ;
}
if ( V_10 -> V_2 -> V_3 -> V_23 == V_46 ) {
V_10 -> V_11 -> V_62 = V_63 | V_64 |
V_65 | V_66 |
V_67 ;
V_10 -> V_11 -> V_68 = V_63 | V_64 |
V_65 | V_66 ;
}
if ( V_10 -> V_2 -> V_3 -> V_23 == V_44 ||
V_10 -> V_2 -> V_3 -> V_23 == V_46 )
F_16 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_69 -> V_12 |= V_70 ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 , int V_71 )
{
if ( V_71 )
return;
if ( V_10 -> V_2 -> V_3 -> V_23 == V_44 ||
V_10 -> V_2 -> V_3 -> V_23 == V_46 )
F_16 ( V_10 -> V_11 , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_72 )
{
int V_73 ;
if ( V_2 -> V_3 -> V_23 == V_44 ||
V_2 -> V_3 -> V_23 == V_46 ) {
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; V_73 ++ )
F_16 ( V_2 -> V_74 [ V_73 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_21 , V_73 ;
if ( V_2 -> V_3 -> V_23 == V_44 ||
V_2 -> V_3 -> V_23 == V_46 ) {
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; V_73 ++ )
F_16 ( V_2 -> V_74 [ V_73 ] -> V_11 , 1 ) ;
}
V_21 = F_9 ( V_2 , 1 ) ;
if ( V_21 ) {
F_15 ( & V_2 -> V_3 -> V_52 , L_3 ) ;
return V_21 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_75 & 0x0000FF ) == V_76 ) {
V_2 -> V_3 -> V_75 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_75 |= V_77 ;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
int V_78 , V_79 ;
T_1 V_80 = F_17 ( V_10 -> V_11 -> V_56 + V_81 ) ;
T_1 V_82 = F_17 ( V_10 -> V_11 -> V_56 + V_83 ) ;
F_14 ( & V_10 -> V_2 -> V_3 -> V_52 , L_4
L_5 ,
V_80 >> 4 , V_80 & 0xf ,
V_82 >> 4 , V_82 & 0xf ) ;
if ( V_82 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_84 ;
F_18 ( V_85 , V_10 -> V_11 -> V_56 + V_86 ) ;
F_18 ( V_87 , V_10 -> V_11 -> V_56 + V_88 ) ;
F_26 ( 50 ) ;
V_78 = 10 ;
do {
V_79 = F_27 ( V_10 -> V_11 -> V_56 + V_89 ) ;
if ( V_79 & V_90 )
break;
F_26 ( 100 ) ;
} while ( -- V_78 );
if ( ! V_78 ) {
F_15 ( & V_10 -> V_2 -> V_3 -> V_52 ,
L_6 ) ;
F_18 ( 0 , V_10 -> V_11 -> V_56 + V_88 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_37 == 0x10 )
V_2 -> V_7 |= V_91 ;
return 0 ;
}
static int F_29 ( struct V_55 * V_11 )
{
struct V_9 * V_10 ;
struct V_47 * V_3 ;
int V_21 ;
V_10 = F_30 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_75 & 0xFFFF00 ) == ( V_92 << 8 ) ) &&
( ( V_3 -> V_75 & 0x0000FF ) != V_77 ) &&
( V_11 -> V_93 & V_94 ) ) {
F_31 ( & V_3 -> V_52 , L_7
L_8 ) ;
}
V_21 = F_32 ( V_3 , F_33 ( 32 ) ) ;
if ( V_21 )
return V_21 ;
F_34 ( V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_47 * V_3 , T_3 V_72 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_4 V_95 ;
T_4 V_96 = 0 ;
int V_73 , V_21 ;
V_2 = F_36 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; V_73 ++ ) {
V_10 = V_2 -> V_74 [ V_73 ] ;
if ( ! V_10 )
continue;
V_21 = F_37 ( V_10 -> V_11 , V_72 ) ;
if ( V_21 ) {
for ( V_73 -- ; V_73 >= 0 ; V_73 -- )
F_38 ( V_2 -> V_74 [ V_73 ] -> V_11 ) ;
return V_21 ;
}
V_95 = V_10 -> V_11 -> V_69 -> V_96 ;
if ( V_95 & V_97 )
F_39 ( V_10 -> V_11 ) ;
V_96 |= V_95 ;
}
if ( V_2 -> V_98 && V_2 -> V_98 -> V_99 ) {
V_21 = V_2 -> V_98 -> V_99 ( V_2 , V_72 ) ;
if ( V_21 ) {
for ( V_73 = V_2 -> V_20 - 1 ; V_73 >= 0 ; V_73 -- )
F_38 ( V_2 -> V_74 [ V_73 ] -> V_11 ) ;
return V_21 ;
}
}
F_40 ( V_3 ) ;
if ( V_96 & V_100 ) {
if ( V_96 & V_97 ) {
F_41 ( V_3 , true ) ;
F_42 ( V_3 , V_101 , 1 ) ;
}
F_43 ( V_3 , V_101 ) ;
} else {
F_42 ( V_3 , F_44 ( V_3 , V_72 ) , 0 ) ;
F_45 ( V_3 ) ;
F_43 ( V_3 , F_44 ( V_3 , V_72 ) ) ;
}
return 0 ;
}
static int F_46 ( struct V_47 * V_3 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_73 , V_21 ;
V_2 = F_36 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
F_43 ( V_3 , V_102 ) ;
F_47 ( V_3 ) ;
V_21 = F_48 ( V_3 ) ;
if ( V_21 )
return V_21 ;
if ( V_2 -> V_98 && V_2 -> V_98 -> V_103 ) {
V_21 = V_2 -> V_98 -> V_103 ( V_2 ) ;
if ( V_21 )
return V_21 ;
}
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; V_73 ++ ) {
V_10 = V_2 -> V_74 [ V_73 ] ;
if ( ! V_10 )
continue;
V_21 = F_38 ( V_10 -> V_11 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static struct V_9 * T_5 F_49 (
struct V_47 * V_3 , struct V_1 * V_2 , int V_104 )
{
struct V_9 * V_10 ;
struct V_55 * V_11 ;
int V_21 ;
if ( ! ( F_50 ( V_3 , V_104 ) & V_105 ) ) {
F_15 ( & V_3 -> V_52 , L_9 , V_104 ) ;
return F_51 ( - V_53 ) ;
}
if ( F_52 ( V_3 , V_104 ) != 0x100 ) {
F_15 ( & V_3 -> V_52 , L_10
L_11 ) ;
}
if ( ( V_3 -> V_75 & 0x0000FF ) == V_76 ) {
F_15 ( & V_3 -> V_52 , L_12 ) ;
return F_51 ( - V_53 ) ;
}
if ( ( V_3 -> V_75 & 0x0000FF ) > V_76 ) {
F_15 ( & V_3 -> V_52 , L_13 ) ;
return F_51 ( - V_53 ) ;
}
V_11 = F_53 ( & V_3 -> V_52 , sizeof( struct V_9 ) ) ;
if ( F_54 ( V_11 ) ) {
F_15 ( & V_3 -> V_52 , L_14 ) ;
return F_55 ( V_11 ) ;
}
V_10 = F_30 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_106 = V_104 ;
V_11 -> V_107 = L_15 ;
V_11 -> V_108 = & V_109 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_110 = V_3 -> V_110 ;
V_21 = F_56 ( V_3 , V_104 , F_57 ( V_11 -> V_69 ) ) ;
if ( V_21 ) {
F_15 ( & V_3 -> V_52 , L_16 ) ;
goto free;
}
V_11 -> V_56 = F_58 ( V_3 , V_104 ) ;
if ( ! V_11 -> V_56 ) {
F_15 ( & V_3 -> V_52 , L_17 ) ;
V_21 = - V_111 ;
goto V_112;
}
if ( V_2 -> V_98 && V_2 -> V_98 -> V_113 ) {
V_21 = V_2 -> V_98 -> V_113 ( V_10 ) ;
if ( V_21 )
goto V_114;
}
V_11 -> V_69 -> V_115 = V_100 | V_97 ;
V_21 = F_59 ( V_11 ) ;
if ( V_21 )
goto remove;
return V_10 ;
remove:
if ( V_2 -> V_98 && V_2 -> V_98 -> V_116 )
V_2 -> V_98 -> V_116 ( V_10 , 0 ) ;
V_114:
F_60 ( V_11 -> V_56 ) ;
V_112:
F_61 ( V_3 , V_104 ) ;
free:
F_62 ( V_11 ) ;
return F_51 ( V_21 ) ;
}
static void F_63 ( struct V_9 * V_10 )
{
int V_71 ;
T_6 V_22 ;
V_71 = 0 ;
V_22 = F_20 ( V_10 -> V_11 -> V_56 + V_117 ) ;
if ( V_22 == ( T_6 ) - 1 )
V_71 = 1 ;
F_64 ( V_10 -> V_11 , V_71 ) ;
if ( V_10 -> V_2 -> V_98 && V_10 -> V_2 -> V_98 -> V_116 )
V_10 -> V_2 -> V_98 -> V_116 ( V_10 , V_71 ) ;
F_61 ( V_10 -> V_2 -> V_3 , V_10 -> V_106 ) ;
F_62 ( V_10 -> V_11 ) ;
}
static int T_5 F_65 ( struct V_47 * V_3 ,
const struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_1 V_74 , V_120 ;
int V_21 , V_73 ;
F_66 ( V_3 == NULL ) ;
F_66 ( V_119 == NULL ) ;
F_14 ( & V_3 -> V_52 , L_18 ,
( int ) V_3 -> V_121 , ( int ) V_3 -> V_23 , ( int ) V_3 -> V_37 ) ;
V_21 = F_7 ( V_3 , V_122 , & V_74 ) ;
if ( V_21 )
return V_21 ;
V_74 = F_67 ( V_74 ) + 1 ;
F_68 ( & V_3 -> V_52 , L_19 , V_74 ) ;
if ( V_74 == 0 )
return - V_53 ;
F_66 ( V_74 > V_123 ) ;
V_21 = F_7 ( V_3 , V_122 , & V_120 ) ;
if ( V_21 )
return V_21 ;
V_120 &= V_124 ;
if ( V_120 > 5 ) {
F_15 ( & V_3 -> V_52 , L_20 ) ;
return - V_53 ;
}
V_21 = F_48 ( V_3 ) ;
if ( V_21 )
return V_21 ;
V_2 = F_69 ( sizeof( struct V_1 ) , V_125 ) ;
if ( ! V_2 ) {
V_21 = - V_111 ;
goto V_126;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_98 = ( const struct V_127 * ) V_119 -> V_128 ;
if ( V_2 -> V_98 )
V_2 -> V_7 = V_2 -> V_98 -> V_7 ;
V_2 -> V_20 = V_74 ;
F_70 ( V_3 , V_2 ) ;
if ( V_2 -> V_98 && V_2 -> V_98 -> V_129 ) {
V_21 = V_2 -> V_98 -> V_129 ( V_2 ) ;
if ( V_21 )
goto free;
}
V_74 = V_2 -> V_20 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
V_10 = F_49 ( V_3 , V_2 , V_120 + V_73 ) ;
if ( F_54 ( V_10 ) ) {
for ( V_73 -- ; V_73 >= 0 ; V_73 -- )
F_63 ( V_2 -> V_74 [ V_73 ] ) ;
V_21 = F_71 ( V_10 ) ;
goto free;
}
V_2 -> V_74 [ V_73 ] = V_10 ;
}
return 0 ;
free:
F_70 ( V_3 , NULL ) ;
F_72 ( V_2 ) ;
V_126:
F_45 ( V_3 ) ;
return V_21 ;
}
static void T_7 F_73 ( struct V_47 * V_3 )
{
int V_73 ;
struct V_1 * V_2 ;
V_2 = F_36 ( V_3 ) ;
if ( V_2 ) {
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; V_73 ++ )
F_63 ( V_2 -> V_74 [ V_73 ] ) ;
F_70 ( V_3 , NULL ) ;
F_72 ( V_2 ) ;
}
F_45 ( V_3 ) ;
}
static int T_8 F_74 ( void )
{
return F_75 ( & V_130 ) ;
}
static void T_9 F_76 ( void )
{
F_77 ( & V_130 ) ;
}
