void F_1 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
F_2 (pcidev) {
if ( V_2 -> V_5 == V_6 ) {
unsigned V_7 ;
V_4 = F_3 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 ) {
F_4 ( V_9 L_1 ) ;
F_5 ( V_2 ) ;
return;
}
F_6 ( & V_4 -> V_10 ) ;
V_4 -> V_2 = F_7 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; ++ V_7 ) {
V_4 -> V_12 [ V_7 ] . V_4 = V_4 ;
V_4 -> V_12 [ V_7 ] . V_13 = V_7 ;
V_4 -> V_12 [ V_7 ] . V_14 = 1 ;
}
V_4 -> V_15 = V_16 ;
V_16 = V_4 ;
}
}
}
static void F_8 ( T_1 V_17 )
{
F_4 ( V_18 L_2
L_3 ,
F_9 ( V_17 ) , F_10 ( V_17 ) ,
F_11 ( V_17 ) , F_12 ( V_17 ) ) ;
F_4 ( V_18 L_4
L_5 ,
F_13 ( V_17 ) , F_14 ( V_17 ) ,
F_15 ( V_17 ) , F_16 ( V_17 ) ) ;
}
unsigned F_17 ( struct V_3 * V_4 , unsigned V_13 )
{
unsigned V_19 = F_18 ( V_4 -> V_20 + F_19 ( V_13 ) ) ;
unsigned V_21 = ( V_19 >> 16 ) & 0xff ;
unsigned V_22 = V_19 & 0xff ;
return V_21 + V_22 ;
}
int F_20 ( struct V_3 * V_4 , unsigned V_23 )
{
unsigned long V_24 ;
T_2 V_25 ;
int V_7 ;
T_1 V_17 ;
unsigned V_26 ;
if ( F_21 ( V_4 -> V_2 , L_6 ) ) {
F_4 ( V_9 L_7 ) ;
return - V_27 ;
}
F_22 ( V_4 -> V_2 ) ;
V_25 = F_23 ( V_4 -> V_2 , 0 ) ;
V_4 -> V_28 = V_25 ;
V_4 -> V_20 = F_24 ( V_25 , V_29 ) ;
if ( ! V_4 -> V_20 ) {
F_4 ( V_9 L_8 ) ;
return - V_30 ;
}
F_4 ( V_18 L_9 ,
( unsigned long long ) V_4 -> V_28 , V_4 -> V_20 ) ;
V_25 = F_23 ( V_4 -> V_2 , 1 ) ;
V_4 -> V_31 = V_25 ;
V_24 = F_25 ( V_4 -> V_2 , 1 ) ;
V_4 -> V_32 = F_24 ( V_4 -> V_31 , V_24 ) ;
if ( ! V_4 -> V_32 ) {
F_4 ( V_9 L_10 ) ;
return - V_30 ;
}
F_4 ( V_18 L_11 ,
( unsigned long long ) V_4 -> V_31 , V_4 -> V_32 ) ;
if ( V_23 ) {
F_26 ( 0 , V_4 -> V_20 + V_33 ) ;
F_4 ( V_18 L_12 ) ;
F_26 ( V_4 -> V_31 | V_34 |
F_27 ( V_24 ) ,
V_4 -> V_20 + V_35 ) ;
F_26 ( 0 , V_4 -> V_20 + V_36 ) ;
} else {
F_26 ( V_4 -> V_31 | V_34 ,
V_4 -> V_20 + V_33 ) ;
}
V_26 =
F_18 ( V_4 -> V_20 + V_37 ) ;
V_26 |= V_38 ;
F_26 ( V_26 ,
V_4 -> V_20 + V_37 ) ;
V_17 = F_18 ( V_4 -> V_20 + V_39 ) ;
V_4 -> V_40 = F_13 ( V_17 ) ;
if ( V_4 -> V_40 > V_11 ) {
F_4 ( V_41 L_13
L_14 ,
V_4 -> V_40 , V_11 ) ;
V_4 -> V_40 = V_11 ;
}
F_8 ( V_17 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_40 ; V_7 ++ ) {
F_26 ( V_42 , V_4 -> V_20 + F_28 ( V_7 ) ) ;
F_26 ( V_43 | V_44 | V_45 |
V_46 | V_47 | V_48 |
V_49 | V_50 ,
V_4 -> V_20 + F_29 ( V_7 ) ) ;
}
V_4 -> V_51 = F_17 ( V_4 , 0 ) ;
F_4 ( V_18 L_15 , V_4 -> V_51 ) ;
V_4 -> V_52 = 1 ;
return 0 ;
}
int F_30 ( struct V_3 * V_4 )
{
return F_20 ( V_4 , 0 ) ;
}
void F_31 ( void )
{
struct V_3 * V_4 , * V_15 ;
for ( V_4 = V_16 ; V_4 ; V_4 = V_15 ) {
F_5 ( V_4 -> V_2 ) ;
V_15 = V_4 -> V_15 ;
F_32 ( V_4 ) ;
}
}
void F_33 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_20 ) {
F_34 ( V_4 -> V_20 ) ;
V_4 -> V_20 = NULL ;
}
if ( V_4 -> V_32 ) {
F_34 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
}
if ( V_4 -> V_28 ) {
F_35 ( V_4 -> V_2 ) ;
V_4 -> V_28 = 0 ;
}
V_4 -> V_52 = 0 ;
}
void F_36 ( void )
{
struct V_3 * V_4 , * V_15 ;
F_4 ( V_18 L_16 ) ;
if ( V_16 )
for ( V_4 = V_16 ; V_4 ; V_4 = V_15 ) {
V_15 = V_4 -> V_15 ;
F_4 ( V_18 L_17 , F_37 ( V_4 ) ) ;
if ( V_4 -> V_52 )
F_4 ( V_18 L_18 ) ;
}
F_4 ( V_18 L_19 ) ;
}
struct V_53 * F_38 ( struct V_3 * V_4 ,
struct
V_54
* V_55 , unsigned V_56 ,
unsigned V_57 )
{
int V_7 ;
unsigned long V_58 ;
struct V_53 * V_13 = NULL ;
F_39 ( & V_4 -> V_10 , V_58 ) ;
for ( V_7 = V_56 ; V_7 <= V_57 ; ++ V_7 ) {
if ( V_4 -> V_59 [ V_7 ] == 0 ) {
V_4 -> V_59 [ V_7 ] = 1 ;
V_13 = & V_4 -> V_12 [ V_7 ] ;
V_13 -> V_55 = V_55 ;
break;
}
}
F_40 ( & V_4 -> V_10 , V_58 ) ;
return V_13 ;
}
void F_41 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
unsigned long V_58 ;
F_39 ( & V_4 -> V_10 , V_58 ) ;
if ( V_4 -> V_59 [ V_60 -> V_13 ] ) {
F_42 ( V_60 ) ;
F_43 ( V_60 ) ;
F_26 ( V_43 | V_44 |
V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 ,
V_4 -> V_20 + F_29 ( V_60 -> V_13 ) ) ;
V_4 -> V_59 [ V_60 -> V_13 ] = 0 ;
V_60 -> V_55 = NULL ;
F_44 () ;
}
F_40 ( & V_4 -> V_10 , V_58 ) ;
}
void F_45 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
int V_61 ;
unsigned long V_58 ;
F_46 ( L_20 , V_13 ) ;
F_47 () ;
V_61 = V_62 ;
F_39 ( & V_4 -> V_10 , V_58 ) ;
V_60 -> V_14 = 0 ;
F_26 ( V_61 , V_4 -> V_20 + F_28 ( V_60 -> V_13 ) ) ;
F_44 () ;
F_40 ( & V_4 -> V_10 , V_58 ) ;
}
int F_48 ( struct V_54 * V_55 ,
struct V_63 * V_64 )
{
unsigned int V_65 ;
int V_7 ;
if ( V_55 -> V_66 ) {
F_49 ( V_55 -> V_67 ,
V_55 -> V_65 *
sizeof( struct V_68 ) ,
V_55 -> V_66 ,
V_55 -> V_69 ) ;
}
V_55 -> V_66 = NULL ;
V_55 -> V_69 = 0 ;
V_55 -> V_65 = 0 ;
if ( V_64 -> V_70 == 0 )
return 0 ;
V_65 = V_64 -> V_70 >> V_71 ;
F_46 ( L_21 , V_55 -> V_67 , V_65 ) ;
V_55 -> V_66 =
F_50 ( V_55 -> V_67 ,
V_65 * sizeof( struct V_68 ) ,
& V_55 -> V_69 , V_8 ) ;
if ( ! V_55 -> V_66 ) {
F_4 ( V_9 L_22 ) ;
return - V_30 ;
}
V_55 -> V_65 = V_65 ;
for ( V_7 = 0 ; V_7 < V_65 ; V_7 ++ ) {
V_55 -> V_66 [ V_7 ] . V_72 = F_51 ( V_73 ) ;
V_55 -> V_66 [ V_7 ] . V_25 =
F_51 ( V_64 -> V_74 [ V_7 ] . V_75 ) ;
V_55 -> V_66 [ V_7 ] . V_15 =
F_51 ( V_55 -> V_69 + ( V_7 +
1 ) *
sizeof( struct V_68 ) ) ;
}
V_55 -> V_66 [ V_65 - 1 ] . V_15 =
F_51 ( V_55 -> V_69 ) ;
F_52 () ;
return 0 ;
}
void F_53 ( struct V_53 * V_60 ,
unsigned int V_76 , unsigned int V_77 )
{
unsigned int V_61 , V_78 , V_79 , V_80 , V_81 ;
struct V_3 * V_4 = V_60 -> V_4 ;
F_46 ( L_23 , V_60 -> V_13 ) ;
V_61 = V_42 | V_82 ;
F_26 ( V_61 , V_4 -> V_20 + F_28 ( V_60 -> V_13 ) ) ;
V_78 = V_83 | V_84 | V_85 |
V_86 ;
V_78 |= V_87 ;
if ( V_77 == 32 && V_76 == 16 ) {
V_78 |= V_88 | V_89 ;
}
if ( V_60 -> V_90 == V_91 )
V_78 |= V_92 ;
F_26 ( V_78 , V_4 -> V_20 + F_29 ( V_60 -> V_13 ) ) ;
V_79 = F_54 ( 64 ) | V_93 ;
switch ( V_77 ) {
case 8 :
V_79 |= V_94 ;
break;
case 16 :
V_79 |= V_95 ;
break;
case 32 :
V_79 |= V_96 ;
break;
default:
F_4 ( V_41 L_24
L_25 ) ;
break;
}
F_26 ( V_79 , V_4 -> V_20 + F_55 ( V_60 -> V_13 ) ) ;
V_80 = F_54 ( 64 ) | V_93 ;
V_80 |= V_97 | V_98 | F_56 ( V_60 -> V_13 ) ;
switch ( V_76 ) {
case 8 :
V_80 |= V_94 ;
break;
case 16 :
V_80 |= V_95 ;
break;
case 32 :
V_80 |= V_96 ;
break;
default:
F_4 ( V_41 L_26
L_25 ) ;
break;
}
F_26 ( V_80 , V_4 -> V_20 + F_57 ( V_60 -> V_13 ) ) ;
F_26 ( 0 , V_4 -> V_20 + F_58 ( V_60 -> V_13 ) ) ;
V_81 = F_54 ( 64 ) | V_93 | V_96 ;
F_26 ( V_81 , V_4 -> V_20 + F_59 ( V_60 -> V_13 ) ) ;
F_26 ( V_60 -> V_55 -> V_69 ,
V_4 -> V_20 + F_60 ( V_60 -> V_13 ) ) ;
F_46 ( L_27 ) ;
}
T_1 F_61 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
return F_18 ( V_4 -> V_20 + F_58 ( V_60 -> V_13 ) ) ;
}
T_1 F_62 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
return F_18 ( V_4 -> V_20 +
F_19 ( V_60 -> V_13 ) ) & 0x000000FF ;
}
T_1 F_63 ( struct V_53 * V_60 )
{
T_1 V_99 ;
V_99 = F_61 ( V_60 ) ;
return V_99 - F_62 ( V_60 ) ;
}
T_1 F_64 ( struct V_53 * V_60 )
{
T_1 V_100 ;
V_100 = F_62 ( V_60 ) ;
return F_61 ( V_60 ) - V_100 ;
}
T_1 F_65 ( struct V_53 * V_60 )
{
T_1 V_99 ;
V_99 = F_61 ( V_60 ) ;
return V_99 + F_62 ( V_60 ) ;
}
T_1 F_66 ( struct V_53 * V_60 )
{
T_1 V_100 ;
V_100 = F_62 ( V_60 ) ;
return F_61 ( V_60 ) + V_100 ;
}
unsigned F_67 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
int V_101 ;
int V_102 ;
V_102 = F_18 ( V_4 -> V_20 + F_60 ( V_60 -> V_13 ) ) ;
V_101 = F_18 ( V_4 -> V_20 + F_68 ( V_60 -> V_13 ) ) ;
F_46 ( L_28 , V_60 -> V_13 ,
V_102 , V_101 ) ;
return V_101 ;
}
void F_42 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
unsigned V_61 ;
V_61 = V_103 ;
F_26 ( V_61 , V_4 -> V_20 + F_28 ( V_60 -> V_13 ) ) ;
}
int F_69 ( struct V_53 * V_60 ,
struct V_63 * V_64 )
{
int V_72 ;
unsigned int V_104 , V_105 ;
const unsigned V_106 = F_70 ( V_64 -> V_107 ) ;
V_105 = V_64 -> V_108 ;
F_71 ( V_64 , V_64 -> V_70 ) ;
V_104 = F_63 ( V_60 ) ;
if ( ( int ) ( F_64 ( V_60 ) -
V_105 ) > 0 ) {
F_4 ( L_29 ) ;
V_64 -> V_109 |= V_110 ;
return - 1 ;
}
V_72 = V_104 - V_64 -> V_111 ;
if ( V_72 <= 0 )
return 0 ;
F_72 ( V_64 , V_72 ) ;
V_64 -> V_112 += V_72 ;
if ( V_64 -> V_112 >= V_106 ) {
V_64 -> V_112 %= V_106 ;
V_64 -> V_109 |= V_113 ;
}
V_64 -> V_109 |= V_114 ;
return 0 ;
}
int F_73 ( struct V_53 * V_60 ,
struct V_63 * V_64 )
{
int V_72 ;
T_1 V_115 , V_116 ;
unsigned int V_105 ;
T_1 V_117 =
V_64 -> V_118 . V_119 * F_70 ( V_64 -> V_107 ) ;
V_105 = V_64 -> V_120 ;
F_74 ( V_64 , V_64 -> V_70 ) ;
V_116 = F_65 ( V_60 ) ;
if ( V_64 -> V_118 . V_121 == V_122 &&
( int ) ( V_116 - V_117 ) > 0 )
V_116 = V_117 ;
V_115 = F_66 ( V_60 ) ;
if ( V_64 -> V_118 . V_121 == V_122 &&
( int ) ( V_115 - V_117 ) > 0 )
V_115 = V_117 ;
if ( ( int ) ( V_115 - V_105 ) > 0 ) {
F_4 ( V_9 L_30 ) ;
V_64 -> V_109 |= V_110 ;
return - 1 ;
}
V_72 = V_116 - V_64 -> V_123 ;
if ( V_72 <= 0 )
return 0 ;
if ( V_72 ) {
F_75 ( V_64 , V_72 ) ;
V_64 -> V_109 |= V_114 ;
}
return 0 ;
}
unsigned F_76 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
unsigned V_124 ;
unsigned long V_58 ;
F_39 ( & V_4 -> V_10 , V_58 ) ;
V_124 = F_18 ( V_4 -> V_20 + F_77 ( V_60 -> V_13 ) ) ;
if ( V_124 & V_125 ) {
V_60 -> V_14 = 1 ;
F_26 ( V_126 ,
V_4 -> V_20 + F_28 ( V_60 -> V_13 ) ) ;
}
F_44 () ;
F_40 ( & V_4 -> V_10 , V_58 ) ;
return V_124 ;
}
int F_78 ( struct V_53 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_4 ;
unsigned long V_58 ;
int V_14 ;
F_76 ( V_60 ) ;
F_39 ( & V_4 -> V_10 , V_58 ) ;
V_14 = V_60 -> V_14 ;
F_40 ( & V_4 -> V_10 , V_58 ) ;
return V_14 ;
}
void F_79 ( struct V_53 * V_60 )
{
unsigned long V_20 =
( unsigned long ) V_60 -> V_4 -> V_20 ;
unsigned long V_25 = 0 ;
unsigned long V_127 = 0 ;
F_4 ( V_128 L_31 , V_60 -> V_13 ) ;
F_4 ( V_128 L_32 , V_20 ) ;
V_25 = V_20 + F_28 ( V_13 ) ;
F_4 ( V_128 L_33 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_129 , V_127 ) ;
V_25 = V_20 + F_29 ( V_13 ) ;
F_4 ( V_128 L_34 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_130 , V_127 ) ;
V_25 = V_20 + F_68 ( V_13 ) ;
F_4 ( V_128 L_35 , V_25 ,
F_18 ( V_25 ) ) ;
V_25 = V_20 + F_55 ( V_13 ) ;
F_4 ( V_128 L_36 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_131 , V_127 ) ;
V_25 = V_20 + F_81 ( V_13 ) ;
F_4 ( V_128 L_37 , V_25 ,
F_18 ( V_25 ) ) ;
V_25 = V_20 + F_57 ( V_13 ) ;
F_4 ( V_128 L_38 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_132 , V_127 ) ;
V_25 = V_20 + F_58 ( V_13 ) ;
F_4 ( V_128 L_39 , V_25 ,
F_18 ( V_25 ) ) ;
V_25 = V_20 + F_59 ( V_13 ) ;
F_4 ( V_128 L_40 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_133 , V_127 ) ;
V_25 = V_20 + F_60 ( V_13 ) ;
F_4 ( V_128 L_41 , V_25 ,
F_18 ( V_25 ) ) ;
V_25 = V_20 + F_77 ( V_13 ) ;
F_4 ( V_128 L_42 , V_25 ,
V_127 = F_18 ( V_25 ) ) ;
F_80 ( V_134 , V_127 ) ;
V_25 = V_20 + F_19 ( V_13 ) ;
F_4 ( V_128 L_43 , V_25 ,
F_18 ( V_25 ) ) ;
}
static void F_80 ( char * * V_135 , unsigned int V_136 )
{
int V_7 ;
for ( V_7 = 31 ; V_7 >= 0 ; V_7 -- ) {
if ( V_136 & ( 1 << V_7 ) )
F_4 ( V_128 L_44 , V_135 [ V_7 ] ) ;
}
F_4 ( V_128 L_19 ) ;
}
int T_3 F_82 ( void )
{
F_1 () ;
F_36 () ;
return 0 ;
}
void T_4 F_83 ( void )
{
F_31 () ;
}
