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
int F_17 ( struct V_17 * V_18 ,
struct V_1 * V_4 , bool V_19 )
{
unsigned long V_20 ;
int V_5 ;
T_1 V_12 ;
unsigned V_21 ;
F_18 ( V_4 -> V_3 ) ;
V_4 -> V_14 = F_19 ( V_4 -> V_3 , 0 ) ;
if ( ! V_4 -> V_14 ) {
F_20 ( V_18 -> V_22 ,
L_3 ) ;
return - V_23 ;
}
V_4 -> V_24 = F_21 ( V_4 -> V_3 , 0 ) ;
V_18 -> V_25 = F_19 ( V_4 -> V_3 , 1 ) ;
if ( ! V_18 -> V_25 ) {
F_20 ( V_18 -> V_22 ,
L_4 ) ;
return - V_23 ;
}
V_4 -> V_26 = F_21 ( V_4 -> V_3 , 1 ) ;
V_20 = F_22 ( V_4 -> V_3 , 1 ) ;
if ( V_19 ) {
F_23 ( 0 , V_4 -> V_14 + V_27 ) ;
F_24 ( V_18 -> V_22 ,
L_5 ) ;
F_23 ( V_4 -> V_26 | V_28 |
F_25 ( V_20 ) ,
V_4 -> V_14 + V_29 ) ;
F_23 ( 0 , V_4 -> V_14 + V_30 ) ;
} else {
F_23 ( V_4 -> V_26 | V_28 ,
V_4 -> V_14 + V_27 ) ;
}
V_21 =
F_15 ( V_4 -> V_14 + V_31 ) ;
V_21 |= V_32 ;
F_23 ( V_21 ,
V_4 -> V_14 + V_31 ) ;
V_12 = F_15 ( V_4 -> V_14 + V_33 ) ;
V_4 -> V_34 = F_10 ( V_12 ) ;
if ( V_4 -> V_34 > V_8 ) {
F_26 ( V_18 -> V_22 ,
L_6 ,
V_4 -> V_34 , V_8 ) ;
V_4 -> V_34 = V_8 ;
}
F_4 ( V_12 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_34 ; V_5 ++ ) {
F_23 ( V_35 , V_4 -> V_14 + F_27 ( V_5 ) ) ;
F_23 ( V_36 | V_37 | V_38 |
V_39 | V_40 | V_41 |
V_42 | V_43 ,
V_4 -> V_14 + F_28 ( V_5 ) ) ;
}
V_4 -> V_44 = F_14 ( V_4 , 0 ) ;
F_24 ( V_18 -> V_22 , L_7 , V_4 -> V_44 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_14 )
F_30 ( V_4 -> V_14 ) ;
F_31 ( V_4 ) ;
}
struct V_45 * F_32 ( struct V_1 * V_4 )
{
struct V_45 * V_46 =
F_33 ( sizeof( struct V_45 ) , V_6 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_47 = F_34 ( & V_4 -> V_3 -> V_18 ) ;
if ( ! V_46 -> V_47 ) {
F_31 ( V_46 ) ;
return NULL ;
}
V_46 -> V_48 = 0 ;
V_46 -> V_49 = NULL ;
V_46 -> V_50 = 0 ;
return V_46 ;
}
void F_35 ( struct V_45 * V_46 )
{
if ( V_46 ) {
if ( V_46 -> V_49 ) {
F_36 ( V_46 -> V_47 ,
V_46 -> V_48 *
sizeof( struct V_51 ) ,
V_46 -> V_49 ,
V_46 -> V_50 ) ;
}
F_37 ( V_46 -> V_47 ) ;
F_31 ( V_46 ) ;
}
}
struct V_52 * F_38 ( struct V_1 * V_4 ,
struct
V_45
* V_46 , unsigned V_53 ,
unsigned V_54 )
{
int V_5 ;
unsigned long V_55 ;
struct V_52 * V_10 = NULL ;
F_39 ( & V_4 -> V_7 , V_55 ) ;
for ( V_5 = V_53 ; V_5 <= V_54 ; ++ V_5 ) {
if ( V_4 -> V_56 [ V_5 ] == 0 ) {
V_4 -> V_56 [ V_5 ] = 1 ;
V_10 = & V_4 -> V_9 [ V_5 ] ;
V_10 -> V_46 = V_46 ;
break;
}
}
F_40 ( & V_4 -> V_7 , V_55 ) ;
return V_10 ;
}
void F_41 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
unsigned long V_55 ;
F_39 ( & V_4 -> V_7 , V_55 ) ;
if ( V_4 -> V_56 [ V_57 -> V_10 ] ) {
F_42 ( V_57 ) ;
F_43 ( V_57 ) ;
F_23 ( V_36 | V_37 |
V_38 | V_39 |
V_40 | V_41 |
V_42 | V_43 ,
V_4 -> V_14 + F_28 ( V_57 -> V_10 ) ) ;
V_4 -> V_56 [ V_57 -> V_10 ] = 0 ;
V_57 -> V_46 = NULL ;
F_44 () ;
}
F_40 ( & V_4 -> V_7 , V_55 ) ;
}
void F_45 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
int V_58 ;
unsigned long V_55 ;
F_46 () ;
V_58 = V_59 ;
F_39 ( & V_4 -> V_7 , V_55 ) ;
V_57 -> V_11 = 0 ;
F_23 ( V_58 , V_4 -> V_14 + F_27 ( V_57 -> V_10 ) ) ;
F_44 () ;
F_40 ( & V_4 -> V_7 , V_55 ) ;
}
int F_47 ( struct V_45 * V_46 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_63 ;
unsigned int V_48 ;
int V_5 ;
if ( V_46 -> V_49 ) {
F_36 ( V_46 -> V_47 ,
V_46 -> V_48 *
sizeof( struct V_51 ) ,
V_46 -> V_49 ,
V_46 -> V_50 ) ;
}
V_46 -> V_49 = NULL ;
V_46 -> V_50 = 0 ;
V_46 -> V_48 = 0 ;
if ( V_63 -> V_64 == 0 )
return 0 ;
V_48 = V_63 -> V_64 >> V_65 ;
V_46 -> V_49 =
F_48 ( V_46 -> V_47 ,
V_48 * sizeof( struct V_51 ) ,
& V_46 -> V_50 , V_6 ) ;
if ( ! V_46 -> V_49 ) {
F_20 ( V_61 -> V_66 -> V_22 ,
L_8 ) ;
return - V_23 ;
}
V_46 -> V_48 = V_48 ;
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
V_46 -> V_49 [ V_5 ] . V_67 = F_49 ( V_68 ) ;
V_46 -> V_49 [ V_5 ] . V_69 =
F_49 ( V_63 -> V_70 -> V_71 [ V_5 ] . V_72 ) ;
V_46 -> V_49 [ V_5 ] . V_73 =
F_49 ( V_46 -> V_50 + ( V_5 +
1 ) *
sizeof( struct V_51 ) ) ;
}
V_46 -> V_49 [ V_48 - 1 ] . V_73 =
F_49 ( V_46 -> V_50 ) ;
F_50 () ;
return 0 ;
}
void F_51 ( struct V_52 * V_57 ,
unsigned int V_74 , unsigned int V_75 )
{
unsigned int V_58 , V_76 , V_77 , V_78 , V_79 ;
struct V_1 * V_4 = V_57 -> V_4 ;
V_58 = V_35 | V_80 ;
F_23 ( V_58 , V_4 -> V_14 + F_27 ( V_57 -> V_10 ) ) ;
V_76 = V_81 | V_82 | V_83 |
V_84 ;
V_76 |= V_85 ;
if ( V_75 == 32 && V_74 == 16 ) {
V_76 |= V_86 | V_87 ;
}
if ( V_57 -> V_88 == V_89 )
V_76 |= V_90 ;
F_23 ( V_76 , V_4 -> V_14 + F_28 ( V_57 -> V_10 ) ) ;
V_77 = F_52 ( 64 ) | V_91 ;
switch ( V_75 ) {
case 8 :
V_77 |= V_92 ;
break;
case 16 :
V_77 |= V_93 ;
break;
case 32 :
V_77 |= V_94 ;
break;
default:
F_53 ( L_9 ) ;
break;
}
F_23 ( V_77 , V_4 -> V_14 + F_54 ( V_57 -> V_10 ) ) ;
V_78 = F_52 ( 64 ) | V_91 ;
V_78 |= V_95 | V_96 | F_55 ( V_57 -> V_10 ) ;
switch ( V_74 ) {
case 8 :
V_78 |= V_92 ;
break;
case 16 :
V_78 |= V_93 ;
break;
case 32 :
V_78 |= V_94 ;
break;
default:
F_53 ( L_10 ) ;
break;
}
F_23 ( V_78 , V_4 -> V_14 + F_56 ( V_57 -> V_10 ) ) ;
F_23 ( 0 , V_4 -> V_14 + F_57 ( V_57 -> V_10 ) ) ;
V_79 = F_52 ( 64 ) | V_91 | V_94 ;
F_23 ( V_79 , V_4 -> V_14 + F_58 ( V_57 -> V_10 ) ) ;
F_23 ( V_57 -> V_46 -> V_50 ,
V_4 -> V_14 + F_59 ( V_57 -> V_10 ) ) ;
}
static T_1 F_60 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
return F_15 ( V_4 -> V_14 + F_57 ( V_57 -> V_10 ) ) ;
}
T_1 F_61 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
return F_15 ( V_4 -> V_14 +
F_16 ( V_57 -> V_10 ) ) & 0x000000FF ;
}
T_1 F_62 ( struct V_52 * V_57 )
{
T_1 V_97 ;
V_97 = F_60 ( V_57 ) ;
return V_97 - F_61 ( V_57 ) ;
}
T_1 F_63 ( struct V_52 * V_57 )
{
T_1 V_98 ;
V_98 = F_61 ( V_57 ) ;
return F_60 ( V_57 ) - V_98 ;
}
T_1 F_64 ( struct V_52 * V_57 )
{
T_1 V_97 ;
V_97 = F_60 ( V_57 ) ;
return V_97 + F_61 ( V_57 ) ;
}
T_1 F_65 ( struct V_52 * V_57 )
{
T_1 V_98 ;
V_98 = F_61 ( V_57 ) ;
return F_60 ( V_57 ) + V_98 ;
}
unsigned F_66 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
return F_15 ( V_4 -> V_14 + F_67 ( V_57 -> V_10 ) ) ;
}
void F_42 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
unsigned V_58 ;
V_58 = V_99 ;
F_23 ( V_58 , V_4 -> V_14 + F_27 ( V_57 -> V_10 ) ) ;
}
int F_68 ( struct V_52 * V_57 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_63 ;
int V_67 ;
unsigned int V_100 , V_101 ;
V_101 = V_63 -> V_102 ;
F_69 ( V_61 , V_63 -> V_64 ) ;
V_100 = F_62 ( V_57 ) ;
if ( ( int ) ( F_63 ( V_57 ) -
V_101 ) > 0 ) {
F_26 ( V_61 -> V_66 -> V_22 ,
L_11 ) ;
V_63 -> V_103 |= V_104 ;
return - 1 ;
}
V_67 = V_100 - V_63 -> V_105 ;
if ( V_67 <= 0 )
return 0 ;
F_70 ( V_61 , V_67 ) ;
F_71 ( V_61 , V_67 ) ;
V_63 -> V_103 |= V_106 ;
return 0 ;
}
int F_72 ( struct V_52 * V_57 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_63 ;
struct V_107 * V_108 = & V_63 -> V_108 ;
T_1 V_109 = V_108 -> V_110 * F_73 ( V_61 ) ;
unsigned int V_101 = V_63 -> V_111 ;
T_1 V_112 , V_113 ;
int V_67 ;
F_74 ( V_61 , V_63 -> V_64 ) ;
V_113 = F_64 ( V_57 ) ;
if ( V_108 -> V_114 == V_115 && ( int ) ( V_113 - V_109 ) > 0 )
V_113 = V_109 ;
V_112 = F_65 ( V_57 ) ;
if ( V_108 -> V_114 == V_115 && ( int ) ( V_112 - V_109 ) > 0 )
V_112 = V_109 ;
if ( ( int ) ( V_112 - V_101 ) > 0 ) {
F_26 ( V_61 -> V_66 -> V_22 , L_12 ) ;
V_63 -> V_103 |= V_104 ;
return - 1 ;
}
V_67 = V_113 - V_63 -> V_116 ;
if ( V_67 <= 0 )
return 0 ;
if ( V_67 ) {
F_75 ( V_61 , V_67 ) ;
V_63 -> V_103 |= V_106 ;
}
return 0 ;
}
unsigned F_76 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
unsigned V_117 ;
unsigned long V_55 ;
F_39 ( & V_4 -> V_7 , V_55 ) ;
V_117 = F_15 ( V_4 -> V_14 + F_77 ( V_57 -> V_10 ) ) ;
if ( V_117 & V_118 ) {
V_57 -> V_11 = 1 ;
F_23 ( V_119 ,
V_4 -> V_14 + F_27 ( V_57 -> V_10 ) ) ;
}
F_44 () ;
F_40 ( & V_4 -> V_7 , V_55 ) ;
return V_117 ;
}
int F_78 ( struct V_52 * V_57 )
{
struct V_1 * V_4 = V_57 -> V_4 ;
unsigned long V_55 ;
int V_11 ;
F_76 ( V_57 ) ;
F_39 ( & V_4 -> V_7 , V_55 ) ;
V_11 = V_57 -> V_11 ;
F_40 ( & V_4 -> V_7 , V_55 ) ;
return V_11 ;
}
static int T_2 F_79 ( void )
{
return 0 ;
}
static void T_3 F_80 ( void )
{
}
