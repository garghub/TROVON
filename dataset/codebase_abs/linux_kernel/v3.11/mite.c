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
int V_5 ;
T_1 V_12 ;
unsigned V_19 ;
F_18 ( V_4 -> V_3 ) ;
V_4 -> V_14 = F_19 ( V_4 -> V_3 , 0 ) ;
if ( ! V_4 -> V_14 ) {
F_20 ( & V_4 -> V_3 -> V_20 ,
L_3 ) ;
return - V_21 ;
}
V_4 -> V_22 = F_21 ( V_4 -> V_3 , 0 ) ;
V_4 -> V_23 = F_19 ( V_4 -> V_3 , 1 ) ;
if ( ! V_4 -> V_23 ) {
F_20 ( & V_4 -> V_3 -> V_20 ,
L_4 ) ;
return - V_21 ;
}
V_4 -> V_24 = F_21 ( V_4 -> V_3 , 1 ) ;
V_18 = F_22 ( V_4 -> V_3 , 1 ) ;
if ( V_17 ) {
F_23 ( 0 , V_4 -> V_14 + V_25 ) ;
F_24 ( & V_4 -> V_3 -> V_20 ,
L_5 ) ;
F_23 ( V_4 -> V_24 | V_26 |
F_25 ( V_18 ) ,
V_4 -> V_14 + V_27 ) ;
F_23 ( 0 , V_4 -> V_14 + V_28 ) ;
} else {
F_23 ( V_4 -> V_24 | V_26 ,
V_4 -> V_14 + V_25 ) ;
}
V_19 =
F_15 ( V_4 -> V_14 + V_29 ) ;
V_19 |= V_30 ;
F_23 ( V_19 ,
V_4 -> V_14 + V_29 ) ;
V_12 = F_15 ( V_4 -> V_14 + V_31 ) ;
V_4 -> V_32 = F_10 ( V_12 ) ;
if ( V_4 -> V_32 > V_8 ) {
F_26 ( & V_4 -> V_3 -> V_20 ,
L_6 ,
V_4 -> V_32 , V_8 ) ;
V_4 -> V_32 = V_8 ;
}
F_4 ( V_12 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_32 ; V_5 ++ ) {
F_23 ( V_33 , V_4 -> V_14 + F_27 ( V_5 ) ) ;
F_23 ( V_34 | V_35 | V_36 |
V_37 | V_38 | V_39 |
V_40 | V_41 ,
V_4 -> V_14 + F_28 ( V_5 ) ) ;
}
V_4 -> V_42 = F_14 ( V_4 , 0 ) ;
F_24 ( & V_4 -> V_3 -> V_20 , L_7 , V_4 -> V_42 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_4 )
{
return F_17 ( V_4 , 0 ) ;
}
void F_30 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_14 ) {
F_31 ( V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
}
if ( V_4 -> V_23 ) {
F_31 ( V_4 -> V_23 ) ;
V_4 -> V_23 = NULL ;
}
if ( V_4 -> V_22 )
V_4 -> V_22 = 0 ;
}
struct V_43 * F_32 ( struct V_1 * V_4 )
{
struct V_43 * V_44 =
F_33 ( sizeof( struct V_43 ) , V_6 ) ;
if ( V_44 == NULL )
return V_44 ;
V_44 -> V_45 = F_34 ( & V_4 -> V_3 -> V_20 ) ;
if ( V_44 -> V_45 == NULL ) {
F_35 ( V_44 ) ;
return NULL ;
}
V_44 -> V_46 = 0 ;
V_44 -> V_47 = NULL ;
V_44 -> V_48 = 0 ;
return V_44 ;
}
void F_36 ( struct V_43 * V_44 )
{
if ( V_44 ) {
if ( V_44 -> V_47 ) {
F_37 ( V_44 -> V_45 ,
V_44 -> V_46 *
sizeof( struct V_49 ) ,
V_44 -> V_47 ,
V_44 -> V_48 ) ;
}
F_38 ( V_44 -> V_45 ) ;
F_35 ( V_44 ) ;
}
}
struct V_50 * F_39 ( struct V_1 * V_4 ,
struct
V_43
* V_44 , unsigned V_51 ,
unsigned V_52 )
{
int V_5 ;
unsigned long V_53 ;
struct V_50 * V_10 = NULL ;
F_40 ( & V_4 -> V_7 , V_53 ) ;
for ( V_5 = V_51 ; V_5 <= V_52 ; ++ V_5 ) {
if ( V_4 -> V_54 [ V_5 ] == 0 ) {
V_4 -> V_54 [ V_5 ] = 1 ;
V_10 = & V_4 -> V_9 [ V_5 ] ;
V_10 -> V_44 = V_44 ;
break;
}
}
F_41 ( & V_4 -> V_7 , V_53 ) ;
return V_10 ;
}
void F_42 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
unsigned long V_53 ;
F_40 ( & V_4 -> V_7 , V_53 ) ;
if ( V_4 -> V_54 [ V_55 -> V_10 ] ) {
F_43 ( V_55 ) ;
F_44 ( V_55 ) ;
F_23 ( V_34 | V_35 |
V_36 | V_37 |
V_38 | V_39 |
V_40 | V_41 ,
V_4 -> V_14 + F_28 ( V_55 -> V_10 ) ) ;
V_4 -> V_54 [ V_55 -> V_10 ] = 0 ;
V_55 -> V_44 = NULL ;
F_45 () ;
}
F_41 ( & V_4 -> V_7 , V_53 ) ;
}
void F_46 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
int V_56 ;
unsigned long V_53 ;
F_47 ( L_8 , V_55 -> V_10 ) ;
F_48 () ;
V_56 = V_57 ;
F_40 ( & V_4 -> V_7 , V_53 ) ;
V_55 -> V_11 = 0 ;
F_23 ( V_56 , V_4 -> V_14 + F_27 ( V_55 -> V_10 ) ) ;
F_45 () ;
F_41 ( & V_4 -> V_7 , V_53 ) ;
}
int F_49 ( struct V_43 * V_44 ,
struct V_58 * V_59 )
{
unsigned int V_46 ;
int V_5 ;
if ( V_44 -> V_47 ) {
F_37 ( V_44 -> V_45 ,
V_44 -> V_46 *
sizeof( struct V_49 ) ,
V_44 -> V_47 ,
V_44 -> V_48 ) ;
}
V_44 -> V_47 = NULL ;
V_44 -> V_48 = 0 ;
V_44 -> V_46 = 0 ;
if ( V_59 -> V_60 == 0 )
return 0 ;
V_46 = V_59 -> V_60 >> V_61 ;
F_47 ( L_9 , V_44 -> V_45 , V_46 ) ;
V_44 -> V_47 =
F_50 ( V_44 -> V_45 ,
V_46 * sizeof( struct V_49 ) ,
& V_44 -> V_48 , V_6 ) ;
if ( ! V_44 -> V_47 ) {
F_20 ( V_59 -> V_62 -> V_63 -> V_64 ,
L_10 ) ;
return - V_21 ;
}
V_44 -> V_46 = V_46 ;
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ ) {
V_44 -> V_47 [ V_5 ] . V_65 = F_51 ( V_66 ) ;
V_44 -> V_47 [ V_5 ] . V_67 =
F_51 ( V_59 -> V_68 [ V_5 ] . V_69 ) ;
V_44 -> V_47 [ V_5 ] . V_70 =
F_51 ( V_44 -> V_48 + ( V_5 +
1 ) *
sizeof( struct V_49 ) ) ;
}
V_44 -> V_47 [ V_46 - 1 ] . V_70 =
F_51 ( V_44 -> V_48 ) ;
F_52 () ;
return 0 ;
}
void F_53 ( struct V_50 * V_55 ,
unsigned int V_71 , unsigned int V_72 )
{
unsigned int V_56 , V_73 , V_74 , V_75 , V_76 ;
struct V_1 * V_4 = V_55 -> V_4 ;
F_47 ( L_11 , V_55 -> V_10 ) ;
V_56 = V_33 | V_77 ;
F_23 ( V_56 , V_4 -> V_14 + F_27 ( V_55 -> V_10 ) ) ;
V_73 = V_78 | V_79 | V_80 |
V_81 ;
V_73 |= V_82 ;
if ( V_72 == 32 && V_71 == 16 ) {
V_73 |= V_83 | V_84 ;
}
if ( V_55 -> V_85 == V_86 )
V_73 |= V_87 ;
F_23 ( V_73 , V_4 -> V_14 + F_28 ( V_55 -> V_10 ) ) ;
V_74 = F_54 ( 64 ) | V_88 ;
switch ( V_72 ) {
case 8 :
V_74 |= V_89 ;
break;
case 16 :
V_74 |= V_90 ;
break;
case 32 :
V_74 |= V_91 ;
break;
default:
F_55 ( L_12 ) ;
break;
}
F_23 ( V_74 , V_4 -> V_14 + F_56 ( V_55 -> V_10 ) ) ;
V_75 = F_54 ( 64 ) | V_88 ;
V_75 |= V_92 | V_93 | F_57 ( V_55 -> V_10 ) ;
switch ( V_71 ) {
case 8 :
V_75 |= V_89 ;
break;
case 16 :
V_75 |= V_90 ;
break;
case 32 :
V_75 |= V_91 ;
break;
default:
F_55 ( L_13 ) ;
break;
}
F_23 ( V_75 , V_4 -> V_14 + F_58 ( V_55 -> V_10 ) ) ;
F_23 ( 0 , V_4 -> V_14 + F_59 ( V_55 -> V_10 ) ) ;
V_76 = F_54 ( 64 ) | V_88 | V_91 ;
F_23 ( V_76 , V_4 -> V_14 + F_60 ( V_55 -> V_10 ) ) ;
F_23 ( V_55 -> V_44 -> V_48 ,
V_4 -> V_14 + F_61 ( V_55 -> V_10 ) ) ;
F_47 ( L_14 ) ;
}
static T_1 F_62 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
return F_15 ( V_4 -> V_14 + F_59 ( V_55 -> V_10 ) ) ;
}
T_1 F_63 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
return F_15 ( V_4 -> V_14 +
F_16 ( V_55 -> V_10 ) ) & 0x000000FF ;
}
T_1 F_64 ( struct V_50 * V_55 )
{
T_1 V_94 ;
V_94 = F_62 ( V_55 ) ;
return V_94 - F_63 ( V_55 ) ;
}
T_1 F_65 ( struct V_50 * V_55 )
{
T_1 V_95 ;
V_95 = F_63 ( V_55 ) ;
return F_62 ( V_55 ) - V_95 ;
}
T_1 F_66 ( struct V_50 * V_55 )
{
T_1 V_94 ;
V_94 = F_62 ( V_55 ) ;
return V_94 + F_63 ( V_55 ) ;
}
T_1 F_67 ( struct V_50 * V_55 )
{
T_1 V_95 ;
V_95 = F_63 ( V_55 ) ;
return F_62 ( V_55 ) + V_95 ;
}
unsigned F_68 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
int V_96 ;
int V_97 ;
V_97 = F_15 ( V_4 -> V_14 + F_61 ( V_55 -> V_10 ) ) ;
V_96 = F_15 ( V_4 -> V_14 + F_69 ( V_55 -> V_10 ) ) ;
F_47 ( L_15 , V_55 -> V_10 ,
V_97 , V_96 ) ;
return V_96 ;
}
void F_43 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
unsigned V_56 ;
V_56 = V_98 ;
F_23 ( V_56 , V_4 -> V_14 + F_27 ( V_55 -> V_10 ) ) ;
}
int F_70 ( struct V_50 * V_55 ,
struct V_58 * V_59 )
{
int V_65 ;
unsigned int V_99 , V_100 ;
const unsigned V_101 = F_71 ( V_59 -> V_62 ) ;
V_100 = V_59 -> V_102 ;
F_72 ( V_59 , V_59 -> V_60 ) ;
V_99 = F_64 ( V_55 ) ;
if ( ( int ) ( F_65 ( V_55 ) -
V_100 ) > 0 ) {
F_26 ( V_59 -> V_62 -> V_63 -> V_64 ,
L_16 ) ;
V_59 -> V_103 |= V_104 ;
return - 1 ;
}
V_65 = V_99 - V_59 -> V_105 ;
if ( V_65 <= 0 )
return 0 ;
F_73 ( V_59 , V_65 ) ;
V_59 -> V_106 += V_65 ;
if ( V_59 -> V_106 >= V_101 ) {
V_59 -> V_106 %= V_101 ;
V_59 -> V_103 |= V_107 ;
}
V_59 -> V_103 |= V_108 ;
return 0 ;
}
int F_74 ( struct V_50 * V_55 ,
struct V_58 * V_59 )
{
int V_65 ;
T_1 V_109 , V_110 ;
unsigned int V_100 ;
T_1 V_111 =
V_59 -> V_112 . V_113 * F_71 ( V_59 -> V_62 ) ;
V_100 = V_59 -> V_114 ;
F_75 ( V_59 , V_59 -> V_60 ) ;
V_110 = F_66 ( V_55 ) ;
if ( V_59 -> V_112 . V_115 == V_116 &&
( int ) ( V_110 - V_111 ) > 0 )
V_110 = V_111 ;
V_109 = F_67 ( V_55 ) ;
if ( V_59 -> V_112 . V_115 == V_116 &&
( int ) ( V_109 - V_111 ) > 0 )
V_109 = V_111 ;
if ( ( int ) ( V_109 - V_100 ) > 0 ) {
F_26 ( V_59 -> V_62 -> V_63 -> V_64 ,
L_17 ) ;
V_59 -> V_103 |= V_104 ;
return - 1 ;
}
V_65 = V_110 - V_59 -> V_117 ;
if ( V_65 <= 0 )
return 0 ;
if ( V_65 ) {
F_76 ( V_59 , V_65 ) ;
V_59 -> V_103 |= V_108 ;
}
return 0 ;
}
unsigned F_77 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
unsigned V_118 ;
unsigned long V_53 ;
F_40 ( & V_4 -> V_7 , V_53 ) ;
V_118 = F_15 ( V_4 -> V_14 + F_78 ( V_55 -> V_10 ) ) ;
if ( V_118 & V_119 ) {
V_55 -> V_11 = 1 ;
F_23 ( V_120 ,
V_4 -> V_14 + F_27 ( V_55 -> V_10 ) ) ;
}
F_45 () ;
F_41 ( & V_4 -> V_7 , V_53 ) ;
return V_118 ;
}
int F_79 ( struct V_50 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_4 ;
unsigned long V_53 ;
int V_11 ;
F_77 ( V_55 ) ;
F_40 ( & V_4 -> V_7 , V_53 ) ;
V_11 = V_55 -> V_11 ;
F_41 ( & V_4 -> V_7 , V_53 ) ;
return V_11 ;
}
static void F_80 ( const char * const * V_121 , unsigned int V_122 )
{
int V_5 ;
for ( V_5 = 31 ; V_5 >= 0 ; V_5 -- ) {
if ( V_122 & ( 1 << V_5 ) )
F_81 ( L_18 , V_121 [ V_5 ] ) ;
}
}
void F_82 ( struct V_50 * V_55 )
{
void T_2 * V_14 = V_55 -> V_4 -> V_14 ;
unsigned int V_123 ;
unsigned int V_124 ;
int V_10 = V_55 -> V_10 ;
F_81 ( L_19 , V_10 ) ;
F_81 ( L_20 , V_14 ) ;
V_123 = F_27 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_21 , V_123 , V_124 ) ;
F_80 ( V_125 , V_124 ) ;
V_123 = F_28 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_22 , V_123 , V_124 ) ;
F_80 ( V_126 , V_124 ) ;
V_123 = F_69 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_23 , V_123 , V_124 ) ;
V_123 = F_56 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_24 , V_123 , V_124 ) ;
F_80 ( V_127 , V_124 ) ;
V_123 = F_83 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_25 , V_123 , V_124 ) ;
V_123 = F_58 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_26 , V_123 , V_124 ) ;
F_80 ( V_128 , V_124 ) ;
V_123 = F_59 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_27 , V_123 , V_124 ) ;
V_123 = F_60 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_28 , V_123 , V_124 ) ;
F_80 ( V_129 , V_124 ) ;
V_123 = F_61 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_29 , V_123 , V_124 ) ;
V_123 = F_78 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_30 , V_123 , V_124 ) ;
F_80 ( V_130 , V_124 ) ;
V_123 = F_16 ( V_10 ) ;
V_124 = F_15 ( V_14 + V_123 ) ;
F_81 ( L_31 , V_123 , V_124 ) ;
}
static int T_3 F_84 ( void )
{
return 0 ;
}
static void T_4 F_85 ( void )
{
}
