struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( V_4 ) {
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_3 = V_3 ;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
V_4 -> V_9 [ V_5 ] . V_4 = V_4 ;
V_4 -> V_9 [ V_5 ] . V_10 = V_5 ;
V_4 -> V_9 [ V_5 ] . V_11 = 1 ;
}
}
return V_4 ;
}
static void F_4 ( T_1 V_12 )
{
F_5 ( L_1 ,
F_6 ( V_12 ) , F_7 ( V_12 ) ,
F_8 ( V_12 ) , F_9 ( V_12 ) ) ;
F_5 ( L_2 ,
F_10 ( V_12 ) , F_11 ( V_12 ) ,
F_12 ( V_12 ) , F_13 ( V_12 ) ) ;
}
static unsigned F_14 ( struct V_1 * V_4 , unsigned V_10 )
{
unsigned V_13 = F_15 ( V_4 -> V_14 + F_16 ( V_10 ) ) ;
unsigned V_15 = ( V_13 >> 16 ) & 0xff ;
unsigned V_16 = V_13 & 0xff ;
return V_15 + V_16 ;
}
int F_17 ( struct V_1 * V_4 , unsigned V_17 )
{
unsigned long V_18 ;
T_2 V_19 ;
int V_5 ;
T_1 V_12 ;
unsigned V_20 ;
if ( F_18 ( V_4 -> V_3 , L_3 ) ) {
F_19 ( & V_4 -> V_3 -> V_21 ,
L_4 ) ;
return - V_22 ;
}
F_20 ( V_4 -> V_3 ) ;
V_19 = F_21 ( V_4 -> V_3 , 0 ) ;
V_4 -> V_23 = V_19 ;
V_4 -> V_14 = F_22 ( V_19 , V_24 ) ;
if ( ! V_4 -> V_14 ) {
F_19 ( & V_4 -> V_3 -> V_21 ,
L_5 ) ;
return - V_25 ;
}
V_19 = F_21 ( V_4 -> V_3 , 1 ) ;
V_4 -> V_26 = V_19 ;
V_18 = F_23 ( V_4 -> V_3 , 1 ) ;
V_4 -> V_27 = F_22 ( V_4 -> V_26 , V_18 ) ;
if ( ! V_4 -> V_27 ) {
F_19 ( & V_4 -> V_3 -> V_21 ,
L_6 ) ;
return - V_25 ;
}
if ( V_17 ) {
F_24 ( 0 , V_4 -> V_14 + V_28 ) ;
F_25 ( & V_4 -> V_3 -> V_21 ,
L_7 ) ;
F_24 ( V_4 -> V_26 | V_29 |
F_26 ( V_18 ) ,
V_4 -> V_14 + V_30 ) ;
F_24 ( 0 , V_4 -> V_14 + V_31 ) ;
} else {
F_24 ( V_4 -> V_26 | V_29 ,
V_4 -> V_14 + V_28 ) ;
}
V_20 =
F_15 ( V_4 -> V_14 + V_32 ) ;
V_20 |= V_33 ;
F_24 ( V_20 ,
V_4 -> V_14 + V_32 ) ;
V_12 = F_15 ( V_4 -> V_14 + V_34 ) ;
V_4 -> V_35 = F_10 ( V_12 ) ;
if ( V_4 -> V_35 > V_8 ) {
F_27 ( & V_4 -> V_3 -> V_21 ,
L_8 ,
V_4 -> V_35 , V_8 ) ;
V_4 -> V_35 = V_8 ;
}
F_4 ( V_12 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_35 ; V_5 ++ ) {
F_24 ( V_36 , V_4 -> V_14 + F_28 ( V_5 ) ) ;
F_24 ( V_37 | V_38 | V_39 |
V_40 | V_41 | V_42 |
V_43 | V_44 ,
V_4 -> V_14 + F_29 ( V_5 ) ) ;
}
V_4 -> V_45 = F_14 ( V_4 , 0 ) ;
F_25 ( & V_4 -> V_3 -> V_21 , L_9 , V_4 -> V_45 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_4 )
{
return F_17 ( V_4 , 0 ) ;
}
void F_31 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_14 ) {
F_32 ( V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
}
if ( V_4 -> V_27 ) {
F_32 ( V_4 -> V_27 ) ;
V_4 -> V_27 = NULL ;
}
if ( V_4 -> V_23 ) {
F_33 ( V_4 -> V_3 ) ;
V_4 -> V_23 = 0 ;
}
}
struct V_46 * F_34 ( struct V_1 * V_4 )
{
struct V_46 * V_47 =
F_35 ( sizeof( struct V_46 ) , V_6 ) ;
if ( V_47 == NULL )
return V_47 ;
V_47 -> V_48 = F_36 ( & V_4 -> V_3 -> V_21 ) ;
if ( V_47 -> V_48 == NULL ) {
F_37 ( V_47 ) ;
return NULL ;
}
V_47 -> V_49 = 0 ;
V_47 -> V_50 = NULL ;
V_47 -> V_51 = 0 ;
return V_47 ;
}
void F_38 ( struct V_46 * V_47 )
{
if ( V_47 ) {
if ( V_47 -> V_50 ) {
F_39 ( V_47 -> V_48 ,
V_47 -> V_49 *
sizeof( struct V_52 ) ,
V_47 -> V_50 ,
V_47 -> V_51 ) ;
}
F_40 ( V_47 -> V_48 ) ;
F_37 ( V_47 ) ;
}
}
struct V_53 * F_41 ( struct V_1 * V_4 ,
struct
V_46
* V_47 , unsigned V_54 ,
unsigned V_55 )
{
int V_5 ;
unsigned long V_56 ;
struct V_53 * V_10 = NULL ;
F_42 ( & V_4 -> V_7 , V_56 ) ;
for ( V_5 = V_54 ; V_5 <= V_55 ; ++ V_5 ) {
if ( V_4 -> V_57 [ V_5 ] == 0 ) {
V_4 -> V_57 [ V_5 ] = 1 ;
V_10 = & V_4 -> V_9 [ V_5 ] ;
V_10 -> V_47 = V_47 ;
break;
}
}
F_43 ( & V_4 -> V_7 , V_56 ) ;
return V_10 ;
}
void F_44 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
unsigned long V_56 ;
F_42 ( & V_4 -> V_7 , V_56 ) ;
if ( V_4 -> V_57 [ V_58 -> V_10 ] ) {
F_45 ( V_58 ) ;
F_46 ( V_58 ) ;
F_24 ( V_37 | V_38 |
V_39 | V_40 |
V_41 | V_42 |
V_43 | V_44 ,
V_4 -> V_14 + F_29 ( V_58 -> V_10 ) ) ;
V_4 -> V_57 [ V_58 -> V_10 ] = 0 ;
V_58 -> V_47 = NULL ;
F_47 () ;
}
F_43 ( & V_4 -> V_7 , V_56 ) ;
}
void F_48 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
int V_59 ;
unsigned long V_56 ;
F_49 ( L_10 , V_58 -> V_10 ) ;
F_50 () ;
V_59 = V_60 ;
F_42 ( & V_4 -> V_7 , V_56 ) ;
V_58 -> V_11 = 0 ;
F_24 ( V_59 , V_4 -> V_14 + F_28 ( V_58 -> V_10 ) ) ;
F_47 () ;
F_43 ( & V_4 -> V_7 , V_56 ) ;
}
int F_51 ( struct V_46 * V_47 ,
struct V_61 * V_62 )
{
unsigned int V_49 ;
int V_5 ;
if ( V_47 -> V_50 ) {
F_39 ( V_47 -> V_48 ,
V_47 -> V_49 *
sizeof( struct V_52 ) ,
V_47 -> V_50 ,
V_47 -> V_51 ) ;
}
V_47 -> V_50 = NULL ;
V_47 -> V_51 = 0 ;
V_47 -> V_49 = 0 ;
if ( V_62 -> V_63 == 0 )
return 0 ;
V_49 = V_62 -> V_63 >> V_64 ;
F_49 ( L_11 , V_47 -> V_48 , V_49 ) ;
V_47 -> V_50 =
F_52 ( V_47 -> V_48 ,
V_49 * sizeof( struct V_52 ) ,
& V_47 -> V_51 , V_6 ) ;
if ( ! V_47 -> V_50 ) {
F_19 ( V_62 -> V_65 -> V_66 -> V_67 ,
L_12 ) ;
return - V_25 ;
}
V_47 -> V_49 = V_49 ;
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ ) {
V_47 -> V_50 [ V_5 ] . V_68 = F_53 ( V_69 ) ;
V_47 -> V_50 [ V_5 ] . V_19 =
F_53 ( V_62 -> V_70 [ V_5 ] . V_71 ) ;
V_47 -> V_50 [ V_5 ] . V_72 =
F_53 ( V_47 -> V_51 + ( V_5 +
1 ) *
sizeof( struct V_52 ) ) ;
}
V_47 -> V_50 [ V_49 - 1 ] . V_72 =
F_53 ( V_47 -> V_51 ) ;
F_54 () ;
return 0 ;
}
void F_55 ( struct V_53 * V_58 ,
unsigned int V_73 , unsigned int V_74 )
{
unsigned int V_59 , V_75 , V_76 , V_77 , V_78 ;
struct V_1 * V_4 = V_58 -> V_4 ;
F_49 ( L_13 , V_58 -> V_10 ) ;
V_59 = V_36 | V_79 ;
F_24 ( V_59 , V_4 -> V_14 + F_28 ( V_58 -> V_10 ) ) ;
V_75 = V_80 | V_81 | V_82 |
V_83 ;
V_75 |= V_84 ;
if ( V_74 == 32 && V_73 == 16 ) {
V_75 |= V_85 | V_86 ;
}
if ( V_58 -> V_87 == V_88 )
V_75 |= V_89 ;
F_24 ( V_75 , V_4 -> V_14 + F_29 ( V_58 -> V_10 ) ) ;
V_76 = F_56 ( 64 ) | V_90 ;
switch ( V_74 ) {
case 8 :
V_76 |= V_91 ;
break;
case 16 :
V_76 |= V_92 ;
break;
case 32 :
V_76 |= V_93 ;
break;
default:
F_57 ( L_14 ) ;
break;
}
F_24 ( V_76 , V_4 -> V_14 + F_58 ( V_58 -> V_10 ) ) ;
V_77 = F_56 ( 64 ) | V_90 ;
V_77 |= V_94 | V_95 | F_59 ( V_58 -> V_10 ) ;
switch ( V_73 ) {
case 8 :
V_77 |= V_91 ;
break;
case 16 :
V_77 |= V_92 ;
break;
case 32 :
V_77 |= V_93 ;
break;
default:
F_57 ( L_15 ) ;
break;
}
F_24 ( V_77 , V_4 -> V_14 + F_60 ( V_58 -> V_10 ) ) ;
F_24 ( 0 , V_4 -> V_14 + F_61 ( V_58 -> V_10 ) ) ;
V_78 = F_56 ( 64 ) | V_90 | V_93 ;
F_24 ( V_78 , V_4 -> V_14 + F_62 ( V_58 -> V_10 ) ) ;
F_24 ( V_58 -> V_47 -> V_51 ,
V_4 -> V_14 + F_63 ( V_58 -> V_10 ) ) ;
F_49 ( L_16 ) ;
}
static T_1 F_64 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
return F_15 ( V_4 -> V_14 + F_61 ( V_58 -> V_10 ) ) ;
}
T_1 F_65 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
return F_15 ( V_4 -> V_14 +
F_16 ( V_58 -> V_10 ) ) & 0x000000FF ;
}
T_1 F_66 ( struct V_53 * V_58 )
{
T_1 V_96 ;
V_96 = F_64 ( V_58 ) ;
return V_96 - F_65 ( V_58 ) ;
}
T_1 F_67 ( struct V_53 * V_58 )
{
T_1 V_97 ;
V_97 = F_65 ( V_58 ) ;
return F_64 ( V_58 ) - V_97 ;
}
T_1 F_68 ( struct V_53 * V_58 )
{
T_1 V_96 ;
V_96 = F_64 ( V_58 ) ;
return V_96 + F_65 ( V_58 ) ;
}
T_1 F_69 ( struct V_53 * V_58 )
{
T_1 V_97 ;
V_97 = F_65 ( V_58 ) ;
return F_64 ( V_58 ) + V_97 ;
}
unsigned F_70 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
int V_98 ;
int V_99 ;
V_99 = F_15 ( V_4 -> V_14 + F_63 ( V_58 -> V_10 ) ) ;
V_98 = F_15 ( V_4 -> V_14 + F_71 ( V_58 -> V_10 ) ) ;
F_49 ( L_17 , V_58 -> V_10 ,
V_99 , V_98 ) ;
return V_98 ;
}
void F_45 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
unsigned V_59 ;
V_59 = V_100 ;
F_24 ( V_59 , V_4 -> V_14 + F_28 ( V_58 -> V_10 ) ) ;
}
int F_72 ( struct V_53 * V_58 ,
struct V_61 * V_62 )
{
int V_68 ;
unsigned int V_101 , V_102 ;
const unsigned V_103 = F_73 ( V_62 -> V_65 ) ;
V_102 = V_62 -> V_104 ;
F_74 ( V_62 , V_62 -> V_63 ) ;
V_101 = F_66 ( V_58 ) ;
if ( ( int ) ( F_67 ( V_58 ) -
V_102 ) > 0 ) {
F_27 ( V_62 -> V_65 -> V_66 -> V_67 ,
L_18 ) ;
V_62 -> V_105 |= V_106 ;
return - 1 ;
}
V_68 = V_101 - V_62 -> V_107 ;
if ( V_68 <= 0 )
return 0 ;
F_75 ( V_62 , V_68 ) ;
V_62 -> V_108 += V_68 ;
if ( V_62 -> V_108 >= V_103 ) {
V_62 -> V_108 %= V_103 ;
V_62 -> V_105 |= V_109 ;
}
V_62 -> V_105 |= V_110 ;
return 0 ;
}
int F_76 ( struct V_53 * V_58 ,
struct V_61 * V_62 )
{
int V_68 ;
T_1 V_111 , V_112 ;
unsigned int V_102 ;
T_1 V_113 =
V_62 -> V_114 . V_115 * F_73 ( V_62 -> V_65 ) ;
V_102 = V_62 -> V_116 ;
F_77 ( V_62 , V_62 -> V_63 ) ;
V_112 = F_68 ( V_58 ) ;
if ( V_62 -> V_114 . V_117 == V_118 &&
( int ) ( V_112 - V_113 ) > 0 )
V_112 = V_113 ;
V_111 = F_69 ( V_58 ) ;
if ( V_62 -> V_114 . V_117 == V_118 &&
( int ) ( V_111 - V_113 ) > 0 )
V_111 = V_113 ;
if ( ( int ) ( V_111 - V_102 ) > 0 ) {
F_27 ( V_62 -> V_65 -> V_66 -> V_67 ,
L_19 ) ;
V_62 -> V_105 |= V_106 ;
return - 1 ;
}
V_68 = V_112 - V_62 -> V_119 ;
if ( V_68 <= 0 )
return 0 ;
if ( V_68 ) {
F_78 ( V_62 , V_68 ) ;
V_62 -> V_105 |= V_110 ;
}
return 0 ;
}
unsigned F_79 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
unsigned V_120 ;
unsigned long V_56 ;
F_42 ( & V_4 -> V_7 , V_56 ) ;
V_120 = F_15 ( V_4 -> V_14 + F_80 ( V_58 -> V_10 ) ) ;
if ( V_120 & V_121 ) {
V_58 -> V_11 = 1 ;
F_24 ( V_122 ,
V_4 -> V_14 + F_28 ( V_58 -> V_10 ) ) ;
}
F_47 () ;
F_43 ( & V_4 -> V_7 , V_56 ) ;
return V_120 ;
}
int F_81 ( struct V_53 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_4 ;
unsigned long V_56 ;
int V_11 ;
F_79 ( V_58 ) ;
F_42 ( & V_4 -> V_7 , V_56 ) ;
V_11 = V_58 -> V_11 ;
F_43 ( & V_4 -> V_7 , V_56 ) ;
return V_11 ;
}
static void F_82 ( const char * const * V_123 , unsigned int V_124 )
{
int V_5 ;
for ( V_5 = 31 ; V_5 >= 0 ; V_5 -- ) {
if ( V_124 & ( 1 << V_5 ) )
F_83 ( L_20 , V_123 [ V_5 ] ) ;
}
}
void F_84 ( struct V_53 * V_58 )
{
void T_3 * V_14 = V_58 -> V_4 -> V_14 ;
unsigned int V_125 ;
unsigned int V_126 ;
int V_10 = V_58 -> V_10 ;
F_83 ( L_21 , V_10 ) ;
F_83 ( L_22 , V_14 ) ;
V_125 = F_28 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_23 , V_125 , V_126 ) ;
F_82 ( V_127 , V_126 ) ;
V_125 = F_29 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_24 , V_125 , V_126 ) ;
F_82 ( V_128 , V_126 ) ;
V_125 = F_71 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_25 , V_125 , V_126 ) ;
V_125 = F_58 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_26 , V_125 , V_126 ) ;
F_82 ( V_129 , V_126 ) ;
V_125 = F_85 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_27 , V_125 , V_126 ) ;
V_125 = F_60 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_28 , V_125 , V_126 ) ;
F_82 ( V_130 , V_126 ) ;
V_125 = F_61 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_29 , V_125 , V_126 ) ;
V_125 = F_62 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_30 , V_125 , V_126 ) ;
F_82 ( V_131 , V_126 ) ;
V_125 = F_63 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_31 , V_125 , V_126 ) ;
V_125 = F_80 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_32 , V_125 , V_126 ) ;
F_82 ( V_132 , V_126 ) ;
V_125 = F_16 ( V_10 ) ;
V_126 = F_15 ( V_14 + V_125 ) ;
F_83 ( L_33 , V_125 , V_126 ) ;
}
static int T_4 F_86 ( void )
{
return 0 ;
}
static void T_5 F_87 ( void )
{
}
