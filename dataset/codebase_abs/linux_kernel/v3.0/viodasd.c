static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_2 V_8 ;
struct V_9 V_10 ;
T_3 V_11 = 0 ;
if ( V_5 -> V_12 ) {
if ( V_3 & V_13 )
return - V_14 ;
V_11 = V_15 ;
}
F_2 ( & V_10 . V_16 ) ;
V_8 = F_3 ( V_17 ,
V_18 ,
V_19 | V_20 ,
V_21 , V_22 ,
F_4 ( V_17 ) ,
F_5 ( V_17 ) ,
( V_23 ) ( unsigned long ) & V_10 , V_24 << 16 ,
( ( V_23 ) F_6 ( V_5 ) << 48 ) | ( ( V_23 ) V_11 << 32 ) ,
0 , 0 , 0 ) ;
if ( V_8 != 0 ) {
F_7 ( L_1 , ( int ) V_8 ) ;
return - V_25 ;
}
F_8 ( & V_10 . V_16 ) ;
if ( V_10 . V_26 != 0 ) {
const struct V_27 * V_28 =
F_9 ( V_29 , V_10 . V_30 ) ;
F_7 ( L_2 ,
( int ) V_10 . V_26 , V_10 . V_30 , V_28 -> V_31 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_32 ;
F_11 ( & V_33 ) ;
V_32 = F_1 ( V_2 , V_3 ) ;
F_12 ( & V_33 ) ;
return V_32 ;
}
static int F_13 ( struct V_34 * V_35 , T_1 V_3 )
{
struct V_4 * V_5 = V_35 -> V_7 ;
T_2 V_8 ;
F_11 ( & V_33 ) ;
V_8 = F_3 ( V_17 ,
V_18 ,
V_19 | V_36 ,
V_37 , V_22 ,
F_4 ( V_17 ) ,
F_5 ( V_17 ) ,
0 , V_24 << 16 ,
( ( V_23 ) F_6 ( V_5 ) << 48 ) ,
0 , 0 , 0 ) ;
if ( V_8 != 0 )
F_7 ( L_3 , ( int ) V_8 ) ;
F_12 ( & V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_34 * V_35 = V_2 -> V_6 ;
struct V_4 * V_5 = V_35 -> V_7 ;
V_39 -> V_40 = V_5 -> V_40 ? V_5 -> V_40 : 32 ;
V_39 -> V_41 = V_5 -> V_42 ? V_5 -> V_42 : 64 ;
V_39 -> V_43 = V_5 -> V_43 ? V_5 -> V_43 :
F_15 ( V_35 ) / ( V_39 -> V_40 * V_39 -> V_41 ) ;
return 0 ;
}
static void F_16 ( struct V_44 * V_45 , int error ,
int V_46 )
{
F_17 ( V_45 , error , V_46 << 9 ) ;
}
static int F_18 ( struct V_44 * V_45 )
{
V_23 V_47 ;
int V_48 ;
int V_49 ;
T_3 V_50 ;
T_2 V_8 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 [ V_57 ] ;
int V_58 ;
struct V_4 * V_5 ;
unsigned long V_11 ;
V_47 = ( V_23 ) F_19 ( V_45 ) << 9 ;
if ( F_20 ( V_45 ) == V_59 ) {
V_48 = V_60 ;
V_50 = V_19 | V_61 ;
} else {
V_48 = V_62 ;
V_50 = V_19 | V_63 ;
}
V_5 = V_45 -> V_64 -> V_7 ;
F_21 ( V_56 , V_57 ) ;
V_49 = F_22 ( V_45 -> V_65 , V_45 , V_56 ) ;
V_49 = F_23 ( V_5 -> V_66 , V_56 , V_49 , V_48 ) ;
F_24 ( & V_67 , V_11 ) ;
V_68 ++ ;
if ( V_49 == 1 )
V_8 = F_3 ( V_17 ,
V_18 , V_50 ,
V_21 ,
V_22 ,
F_4 ( V_17 ) ,
F_5 ( V_17 ) ,
( V_23 ) ( unsigned long ) V_45 , V_24 << 16 ,
( ( V_23 ) F_6 ( V_5 ) << 48 ) , V_47 ,
( ( V_23 ) F_25 ( & V_56 [ 0 ] ) ) << 32 ,
F_26 ( & V_56 [ 0 ] ) ) ;
else {
V_52 = (struct V_51 * )
F_27 ( V_19 ) ;
if ( V_52 == NULL ) {
F_7 ( L_4 ) ;
goto V_69;
}
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_54 = & V_52 -> V_70 ;
V_54 -> V_11 = V_71 | V_72 |
V_73 ;
V_54 -> V_74 = V_18 ;
V_54 -> V_75 = V_50 ;
V_54 -> V_76 = F_28 () ;
V_54 -> V_77 = V_17 ;
V_54 -> V_78 =
F_29 ( struct V_51 , V_79 . V_80 . V_81 ) +
( sizeof( V_52 -> V_79 . V_80 . V_81 [ 0 ] ) * V_49 ) - 1 ;
V_54 -> V_82 = F_4 ( V_17 ) ;
V_54 -> V_83 = F_5 ( V_17 ) ;
V_54 -> V_84 = ( V_23 ) V_45 ;
V_52 -> V_85 = V_24 ;
V_52 -> V_35 = F_6 ( V_5 ) ;
V_52 -> V_79 . V_80 . V_86 = V_47 ;
for ( V_58 = 0 ; V_58 < V_49 ; V_58 ++ ) {
V_52 -> V_79 . V_80 . V_81 [ V_58 ] . V_87 =
F_25 ( & V_56 [ V_58 ] ) ;
V_52 -> V_79 . V_80 . V_81 [ V_58 ] . V_88 =
F_26 ( & V_56 [ V_58 ] ) ;
}
V_8 = F_30 ( & V_52 -> V_70 ) ;
F_31 ( V_19 , V_52 ) ;
}
if ( V_8 != V_89 ) {
F_7 ( L_5 ,
( int ) V_8 ) ;
goto V_69;
}
F_32 ( & V_67 , V_11 ) ;
return 0 ;
V_69:
V_68 -- ;
F_32 ( & V_67 , V_11 ) ;
F_33 ( V_5 -> V_66 , V_56 , V_49 , V_48 ) ;
return - 1 ;
}
static void F_34 ( struct V_90 * V_65 )
{
struct V_44 * V_45 ;
while ( V_68 < V_91 ) {
V_45 = F_35 ( V_65 ) ;
if ( V_45 == NULL )
return;
if ( V_45 -> V_92 != V_93 ) {
F_16 ( V_45 , - V_25 , F_36 ( V_45 ) ) ;
continue;
}
if ( F_18 ( V_45 ) != 0 )
F_16 ( V_45 , - V_25 , F_36 ( V_45 ) ) ;
}
}
static int F_37 ( struct V_4 * V_5 )
{
T_2 V_8 ;
struct V_9 V_10 ;
int V_94 = F_6 ( V_5 ) ;
struct V_34 * V_95 ;
struct V_90 * V_65 ;
T_3 V_11 = 0 ;
V_96:
F_2 ( & V_10 . V_16 ) ;
V_8 = F_3 ( V_17 ,
V_18 ,
V_19 | V_20 ,
V_21 , V_22 ,
F_4 ( V_17 ) ,
F_5 ( V_17 ) ,
( V_23 ) ( unsigned long ) & V_10 , V_24 << 16 ,
( ( V_23 ) V_94 << 48 ) | ( ( V_23 ) V_11 << 32 ) ,
0 , 0 , 0 ) ;
if ( V_8 != 0 ) {
F_7 ( L_6 , ( int ) V_8 ) ;
return 0 ;
}
F_8 ( & V_10 . V_16 ) ;
if ( V_10 . V_26 != 0 ) {
if ( V_11 != 0 )
return 0 ;
V_11 = V_15 ;
goto V_96;
}
if ( V_10 . V_97 > ( V_98 - 1 ) ) {
F_38 (KERN_INFO pr_fmt(L_7),
MAX_DISKNO, we.max_disk + 1 ) ;
}
V_8 = F_3 ( V_17 ,
V_18 ,
V_19 | V_36 ,
V_37 , V_22 ,
F_4 ( V_17 ) ,
F_5 ( V_17 ) ,
0 , V_24 << 16 ,
( ( V_23 ) V_94 << 48 ) | ( ( V_23 ) V_11 << 32 ) ,
0 , 0 , 0 ) ;
if ( V_8 != 0 ) {
F_7 ( L_8 , ( int ) V_8 ) ;
return 0 ;
}
if ( V_5 -> V_66 == NULL ) {
if ( F_39 ( V_94 ) == NULL ) {
F_7 ( L_9 ,
V_94 ) ;
return 0 ;
}
return 1 ;
}
F_40 ( & V_5 -> V_99 ) ;
V_65 = F_41 ( F_34 , & V_5 -> V_99 ) ;
if ( V_65 == NULL ) {
F_7 ( L_10 , V_94 ) ;
return 0 ;
}
V_95 = F_42 ( 1 << V_100 ) ;
if ( V_95 == NULL ) {
F_7 ( L_11 ,
V_94 ) ;
F_43 ( V_65 ) ;
return 0 ;
}
V_5 -> V_35 = V_95 ;
F_44 ( V_65 , V_57 ) ;
F_45 ( V_65 , V_101 ) ;
V_95 -> V_102 = V_103 ;
V_95 -> V_104 = V_94 << V_100 ;
if ( V_94 >= 26 )
snprintf ( V_95 -> V_105 , sizeof( V_95 -> V_105 ) ,
V_106 L_12 ,
'a' + ( V_94 / 26 ) - 1 , 'a' + ( V_94 % 26 ) ) ;
else
snprintf ( V_95 -> V_105 , sizeof( V_95 -> V_105 ) ,
V_106 L_13 , 'a' + ( V_94 % 26 ) ) ;
V_95 -> V_107 = & V_108 ;
V_95 -> V_109 = V_65 ;
V_95 -> V_7 = V_5 ;
V_95 -> V_110 = V_5 -> V_66 ;
F_46 ( V_95 , V_5 -> V_111 >> 9 ) ;
F_47 ( L_14 ,
V_94 , ( unsigned long ) ( V_5 -> V_111 >> 9 ) ,
( unsigned long ) ( V_5 -> V_111 >> 20 ) ,
( int ) V_5 -> V_43 , ( int ) V_5 -> V_42 ,
( int ) V_5 -> V_40 , ( int ) V_5 -> V_112 ,
V_5 -> V_12 ? L_15 : L_16 ) ;
F_48 ( V_95 ) ;
return 1 ;
}
static int F_49 ( const struct V_51 * V_52 ,
struct V_55 * V_56 , int * V_113 )
{
int V_114 , V_115 ;
const struct V_80 * V_80 = & V_52 -> V_79 . V_80 ;
static const int V_86 =
F_29 ( struct V_51 , V_79 . V_80 . V_81 ) ;
static const int V_116 = sizeof( V_80 -> V_81 [ 0 ] ) ;
V_115 = ( ( V_52 -> V_70 . V_78 + 1 ) - V_86 ) / V_116 ;
if ( V_115 > V_57 )
V_115 = V_57 ;
* V_113 = 0 ;
F_21 ( V_56 , V_57 ) ;
for ( V_114 = 0 ; ( V_114 < V_115 ) && ( V_80 -> V_81 [ V_114 ] . V_88 > 0 ) ; ++ V_114 ) {
F_25 ( & V_56 [ V_114 ] ) = V_80 -> V_81 [ V_114 ] . V_87 ;
F_26 ( & V_56 [ V_114 ] ) = V_80 -> V_81 [ V_114 ] . V_88 ;
* V_113 += V_80 -> V_81 [ V_114 ] . V_88 ;
}
return V_114 ;
}
static void F_50 ( int V_117 )
{
int V_114 ;
for ( V_114 = V_117 + 1 ; V_114 < V_98 ; ++ V_114 )
if ( V_118 [ V_114 ] . V_35 )
F_51 ( V_118 [ V_114 ] . V_35 -> V_109 ) ;
for ( V_114 = 0 ; V_114 <= V_117 ; ++ V_114 )
if ( V_118 [ V_114 ] . V_35 )
F_51 ( V_118 [ V_114 ] . V_35 -> V_109 ) ;
}
static int F_52 ( struct V_51 * V_52 )
{
int V_119 , V_120 , V_121 , V_113 ;
struct V_44 * V_45 ;
struct V_55 V_56 [ V_57 ] ;
struct V_53 * V_70 = & V_52 -> V_70 ;
unsigned long V_122 ;
struct V_4 * V_5 ;
int error ;
T_4 * V_123 ;
V_119 = F_49 ( V_52 , V_56 , & V_113 ) ;
V_120 = V_113 >> 9 ;
if ( V_70 -> V_75 == ( V_19 | V_61 ) )
V_121 = V_60 ;
else
V_121 = V_62 ;
V_45 = (struct V_44 * ) V_52 -> V_70 . V_84 ;
V_5 = V_45 -> V_64 -> V_7 ;
F_33 ( V_5 -> V_66 , V_56 , V_119 , V_121 ) ;
F_24 ( & V_67 , V_122 ) ;
V_68 -- ;
F_32 ( & V_67 , V_122 ) ;
error = ( V_70 -> V_124 == V_89 ) ? 0 : - V_25 ;
if ( error ) {
const struct V_27 * V_28 ;
V_28 = F_9 ( V_29 , V_52 -> V_30 ) ;
F_7 ( L_17 ,
V_70 -> V_124 , V_52 -> V_30 , V_28 -> V_31 ) ;
V_120 = F_36 ( V_45 ) ;
}
V_123 = V_45 -> V_65 -> V_125 ;
F_24 ( V_123 , V_122 ) ;
F_16 ( V_45 , error , V_120 ) ;
F_32 ( V_123 , V_122 ) ;
F_50 ( F_6 ( V_5 ) ) ;
return 0 ;
}
static void F_53 ( struct V_53 * V_70 )
{
struct V_51 * V_52 = (struct V_51 * ) V_70 ;
struct V_9 * V_126 ;
if ( V_70 == NULL )
return;
if ( F_54 ( V_70 ) ) {
F_7 ( L_18 ) ;
if ( F_55 ( V_70 ) ) {
V_70 -> V_124 = V_127 ;
F_56 ( V_70 ) ;
}
}
switch ( V_70 -> V_75 & V_128 ) {
case V_20 :
V_126 = (struct V_9 * ) V_70 -> V_84 ;
V_126 -> V_26 = V_70 -> V_124 ;
V_126 -> V_30 = V_52 -> V_30 ;
if ( V_70 -> V_124 == V_89 ) {
const struct V_129 * V_130 = & V_52 -> V_79 . V_129 ;
struct V_4 * V_131 =
& V_118 [ V_52 -> V_35 ] ;
V_131 -> V_12 =
V_52 -> V_11 & V_15 ;
V_131 -> V_111 = V_130 -> V_132 ;
V_131 -> V_43 = V_130 -> V_43 ;
V_131 -> V_42 = V_130 -> V_42 ;
V_131 -> V_40 = V_130 -> V_40 ;
V_131 -> V_112 = V_130 -> V_112 ;
V_126 -> V_97 = V_130 -> V_97 ;
}
F_57 ( & V_126 -> V_16 ) ;
break;
case V_36 :
break;
case V_61 :
case V_63 :
F_52 ( V_52 ) ;
break;
default:
F_7 ( L_19 ) ;
if ( F_55 ( V_70 ) ) {
V_70 -> V_124 = V_127 ;
F_56 ( V_70 ) ;
}
}
}
static T_5 F_58 ( struct V_133 * V_134 , const char * V_135 ,
T_6 V_136 )
{
struct V_4 * V_5 ;
for ( V_5 = V_118 ; V_5 < & V_118 [ V_98 ] ; V_5 ++ ) {
if ( V_5 -> V_35 == NULL )
F_37 ( V_5 ) ;
}
return V_136 ;
}
static int F_59 ( struct V_137 * V_138 , const struct V_139 * V_140 )
{
struct V_4 * V_5 = & V_118 [ V_138 -> V_141 ] ;
V_5 -> V_66 = & V_138 -> V_66 ;
if ( ! F_37 ( V_5 ) )
return - V_142 ;
return 0 ;
}
static int F_60 ( struct V_137 * V_138 )
{
struct V_4 * V_5 ;
V_5 = & V_118 [ V_138 -> V_141 ] ;
if ( V_5 -> V_35 ) {
F_61 ( V_5 -> V_35 ) ;
F_43 ( V_5 -> V_35 -> V_109 ) ;
F_62 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
}
V_5 -> V_66 = NULL ;
return 0 ;
}
static int T_7 F_63 ( void )
{
int V_26 ;
if ( ! F_64 ( V_143 ) ) {
V_26 = - V_142 ;
goto V_144;
}
if ( V_17 == V_145 )
F_65 () ;
if ( V_17 == V_145 ) {
F_7 ( L_20 ) ;
V_26 = - V_25 ;
goto V_144;
}
F_47 ( L_21 V_146 L_22 , V_17 ) ;
V_26 = F_66 ( V_103 , V_106 ) ;
if ( V_26 ) {
F_7 ( L_23 ,
V_103 , V_106 ) ;
goto V_144;
}
V_26 = F_67 ( V_17 , V_19 ,
V_91 + 2 ) ;
if ( V_26 ) {
F_7 ( L_24 ,
V_17 ) ;
goto V_147;
}
F_68 ( V_19 , F_53 ) ;
V_26 = F_69 ( & V_148 ) ;
if ( V_26 ) {
F_7 ( L_25 ) ;
goto V_149;
}
if ( ! F_70 ( & V_148 . V_150 , & V_151 ) )
V_152 = 1 ;
return 0 ;
V_149:
F_71 ( V_19 ) ;
F_72 ( V_17 , V_19 , V_91 + 2 ) ;
V_147:
F_73 ( V_103 , V_106 ) ;
V_144:
return V_26 ;
}
void T_8 F_74 ( void )
{
if ( V_152 )
F_75 ( & V_148 . V_150 , & V_151 ) ;
F_76 ( & V_148 ) ;
F_71 ( V_19 ) ;
F_72 ( V_17 , V_19 , V_91 + 2 ) ;
F_73 ( V_103 , V_106 ) ;
}
