static void F_1 ( struct V_1 * V_2 ,
unsigned short V_3 [] ,
unsigned int V_4 ,
unsigned short V_5 [] ,
unsigned int V_6 )
{
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
if ( V_3 [ V_7 ] == V_5 [ V_8 ] )
break;
if ( V_8 == V_6 )
F_2 ( V_2 , V_3 [ V_7 ] , 0 ) ;
}
}
static void F_3 ( struct V_1 * V_2 ,
unsigned char V_9 [] ,
unsigned short V_10 [] ,
unsigned int V_11 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
F_4 ( V_2 , V_12 , V_13 , V_9 [ V_7 ] ) ;
F_2 ( V_2 , V_10 [ V_7 ] , 1 ) ;
}
}
static void F_5 ( struct V_14 * V_15 )
{
unsigned char V_9 [ V_16 ] ;
unsigned short V_10 [ V_16 ] ;
T_1 V_17 = 0 ;
unsigned int V_7 ;
unsigned int V_18 = 0 ;
bool V_19 = false ;
bool V_20 = false ;
bool V_21 = false ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ ) {
if ( ( V_7 % 4 ) == 0 )
V_17 = F_6 ( V_15 -> V_22 + V_23 + V_7 ) ;
if ( V_17 & 0x80 ) {
unsigned int V_24 = V_17 & 0x07 ;
unsigned int V_25 = ( V_17 >> 3 ) & 0x0f ;
unsigned char V_26 =
F_7 ( V_25 , V_24 , V_27 ) ;
V_9 [ V_18 ] = V_26 ;
V_10 [ V_18 ] = V_15 -> V_28 [ V_26 ] ;
if ( ( V_10 [ V_18 ] == V_29 ) && V_15 -> V_30 )
V_19 = true ;
else
V_18 ++ ;
}
V_17 >>= 8 ;
}
if ( V_15 -> V_31 && V_18 >= 3 ) {
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
unsigned int V_8 ;
T_2 V_32 = V_9 [ V_7 ] & 0x07 ;
T_2 V_33 = V_9 [ V_7 ] >> V_27 ;
for ( V_8 = V_7 + 1 ; V_8 < V_18 ; V_8 ++ ) {
T_2 V_24 = V_9 [ V_8 ] & 0x07 ;
T_2 V_25 = V_9 [ V_8 ] >> V_27 ;
if ( V_24 == V_32 )
V_21 = true ;
if ( V_25 == V_33 )
V_20 = true ;
}
}
}
if ( V_19 ) {
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_9 [ V_7 ] += V_34 ;
V_10 [ V_7 ] = V_15 -> V_28 [ V_9 [ V_7 ] ] ;
}
}
if ( V_21 && V_20 )
return;
F_1 ( V_15 -> V_35 ,
V_15 -> V_36 , V_15 -> V_11 ,
V_10 , V_18 ) ;
F_3 ( V_15 -> V_35 , V_9 , V_10 , V_18 ) ;
F_8 ( V_15 -> V_35 ) ;
memcpy ( V_15 -> V_36 , V_10 , sizeof( V_15 -> V_36 ) ) ;
V_15 -> V_11 = V_18 ;
}
static void F_9 ( struct V_14 * V_15 , bool V_37 )
{
T_1 V_17 ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
if ( V_37 )
V_17 |= V_39 ;
else
V_17 &= ~ V_39 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
}
static void F_11 ( unsigned long V_40 )
{
struct V_14 * V_15 = (struct V_14 * ) V_40 ;
unsigned long V_41 ;
T_1 V_17 ;
unsigned int V_7 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = ( F_6 ( V_15 -> V_22 + V_43 ) >> 4 ) & 0xf ;
if ( V_17 ) {
unsigned long V_44 ;
F_5 ( V_15 ) ;
V_44 = ( V_17 == 1 ) ? V_15 -> V_45 : 1 ;
F_13 ( & V_15 -> V_46 , V_47 + F_14 ( V_44 ) ) ;
} else {
for ( V_7 = 0 ; V_7 < V_15 -> V_11 ; V_7 ++ )
F_2 ( V_15 -> V_35 , V_15 -> V_36 [ V_7 ] , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
V_15 -> V_11 = 0 ;
F_9 ( V_15 , true ) ;
}
F_15 ( & V_15 -> V_42 , V_41 ) ;
}
static T_3 F_16 ( int V_48 , void * args )
{
struct V_14 * V_15 = args ;
unsigned long V_41 ;
T_1 V_17 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
F_10 ( V_17 , V_15 -> V_22 + V_43 ) ;
if ( V_17 & V_49 ) {
F_9 ( V_15 , false ) ;
F_13 ( & V_15 -> V_46 , V_47 + V_15 -> V_50 ) ;
}
F_15 ( & V_15 -> V_42 , V_41 ) ;
return V_51 ;
}
static void F_17 ( struct V_14 * V_15 , bool V_52 )
{
const struct V_53 * V_54 = V_15 -> V_54 ;
int V_7 ;
unsigned int V_55 ;
V_55 = ( V_52 && ! V_54 -> V_56 ) ? ~ 0 : 0 ;
for ( V_7 = 0 ; V_7 < V_57 ; V_7 ++ )
F_10 ( V_55 , V_15 -> V_22 + V_58 + V_7 * 4 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
const struct V_53 * V_54 = V_15 -> V_54 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_59 ; V_7 ++ ) {
T_1 V_60 = 5 * ( V_7 % 6 ) ;
T_1 V_61 = 4 * ( V_7 % 8 ) ;
T_1 V_62 = 0x1f << V_60 ;
T_1 V_63 = 0x0f << V_61 ;
T_1 V_64 = ( V_7 / 6 ) * 4 + V_65 ;
T_1 V_66 = ( V_7 / 8 ) * 4 + V_67 ;
T_1 V_68 = F_6 ( V_15 -> V_22 + V_64 ) ;
T_1 V_69 = F_6 ( V_15 -> V_22 + V_66 ) ;
V_68 &= ~ V_62 ;
V_69 &= ~ V_63 ;
if ( V_54 -> V_70 [ V_7 ] . V_71 )
V_68 |= ( ( V_54 -> V_70 [ V_7 ] . V_72 << 1 ) | 1 ) << V_60 ;
else
V_69 |= ( ( V_54 -> V_70 [ V_7 ] . V_72 << 1 ) | 1 ) << V_61 ;
F_10 ( V_68 , V_15 -> V_22 + V_64 ) ;
F_10 ( V_69 , V_15 -> V_22 + V_66 ) ;
}
}
static int F_19 ( struct V_14 * V_15 )
{
const struct V_53 * V_54 = V_15 -> V_54 ;
unsigned int V_73 ;
T_1 V_17 = 0 ;
F_20 ( V_15 -> V_74 ) ;
F_21 ( V_15 -> V_74 ) ;
F_22 ( 100 ) ;
F_23 ( V_15 -> V_74 ) ;
F_22 ( 100 ) ;
F_18 ( V_15 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_54 -> V_75 , V_15 -> V_22 + V_76 ) ;
V_73 = F_24 ( V_54 -> V_73 , V_77 ) ;
V_17 = F_25 ( V_73 ) ;
V_17 |= F_26 ( 1 ) ;
V_17 |= V_39 ;
V_17 |= V_78 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_79 ) ;
V_15 -> V_50 = F_27 ( ( V_17 & 0xfffff ) * 32 ) ;
V_15 -> V_11 = 0 ;
while ( 1 ) {
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
V_17 >>= 4 ;
if ( ! V_17 )
break;
V_17 = F_6 ( V_15 -> V_22 + V_23 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_80 ) ;
}
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
F_28 ( V_15 -> V_48 ) ;
return 0 ;
}
static void F_29 ( struct V_14 * V_15 )
{
unsigned long V_41 ;
T_1 V_17 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
V_17 &= ~ 1 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
F_15 ( & V_15 -> V_42 , V_41 ) ;
F_30 ( V_15 -> V_48 ) ;
F_31 ( & V_15 -> V_46 ) ;
F_32 ( V_15 -> V_74 ) ;
}
static int F_33 ( struct V_1 * V_81 )
{
struct V_14 * V_15 = F_34 ( V_81 ) ;
return F_19 ( V_15 ) ;
}
static void F_35 ( struct V_1 * V_81 )
{
struct V_14 * V_15 = F_34 ( V_81 ) ;
return F_29 ( V_15 ) ;
}
static bool T_4
F_36 ( const struct V_53 * V_54 ,
struct V_82 * V_81 , unsigned int * V_83 )
{
int V_7 ;
* V_83 = 0 ;
for ( V_7 = 0 ; V_7 < V_59 ; V_7 ++ ) {
const struct V_84 * V_70 = & V_54 -> V_70 [ V_7 ] ;
if ( V_70 -> V_71 ) {
if ( V_70 -> V_72 >= V_57 ) {
F_37 ( V_81 ,
L_1 ,
V_7 , V_70 -> V_72 ) ;
return false ;
}
( * V_83 ) ++ ;
} else {
if ( V_70 -> V_72 >= V_85 ) {
F_37 ( V_81 ,
L_2 ,
V_7 , V_70 -> V_72 ) ;
return false ;
}
}
}
return true ;
}
static int T_4 F_38 ( struct V_86 * V_87 )
{
const struct V_53 * V_54 = V_87 -> V_81 . V_88 ;
const struct V_89 * V_90 ;
struct V_14 * V_15 ;
struct V_1 * V_1 ;
struct V_91 * V_92 ;
int V_48 ;
int V_93 ;
int V_83 = 0 ;
unsigned int V_73 ;
unsigned int V_94 ;
if ( ! V_54 )
return - V_95 ;
if ( ! F_36 ( V_54 , & V_87 -> V_81 , & V_83 ) )
return - V_95 ;
V_92 = F_39 ( V_87 , V_96 , 0 ) ;
if ( ! V_92 ) {
F_37 ( & V_87 -> V_81 , L_3 ) ;
return - V_97 ;
}
V_48 = F_40 ( V_87 , 0 ) ;
if ( V_48 < 0 ) {
F_37 ( & V_87 -> V_81 , L_4 ) ;
return - V_97 ;
}
V_15 = F_41 ( sizeof( * V_15 ) , V_98 ) ;
V_1 = F_42 () ;
if ( ! V_15 || ! V_1 ) {
V_93 = - V_99 ;
goto V_100;
}
V_15 -> V_54 = V_54 ;
V_15 -> V_35 = V_1 ;
V_15 -> V_48 = V_48 ;
F_43 ( & V_15 -> V_42 ) ;
F_44 ( & V_15 -> V_46 , F_11 , ( unsigned long ) V_15 ) ;
V_92 = F_45 ( V_92 -> V_101 , F_46 ( V_92 ) , V_87 -> V_102 ) ;
if ( ! V_92 ) {
F_37 ( & V_87 -> V_81 , L_5 ) ;
V_93 = - V_103 ;
goto V_100;
}
V_15 -> V_22 = F_47 ( V_92 -> V_101 , F_46 ( V_92 ) ) ;
if ( ! V_15 -> V_22 ) {
F_37 ( & V_87 -> V_81 , L_6 ) ;
V_93 = - V_97 ;
goto V_104;
}
V_15 -> V_74 = F_48 ( & V_87 -> V_81 , NULL ) ;
if ( F_49 ( V_15 -> V_74 ) ) {
F_37 ( & V_87 -> V_81 , L_7 ) ;
V_93 = F_50 ( V_15 -> V_74 ) ;
goto V_105;
}
V_73 = F_24 ( V_54 -> V_73 , V_77 ) ;
V_94 = ( V_106 + V_73 ) * V_83 ;
V_15 -> V_45 = V_107 + V_94 + V_54 -> V_75 ;
V_15 -> V_45 = F_51 ( V_15 -> V_45 , V_108 ) ;
V_1 -> V_102 = V_87 -> V_102 ;
V_1 -> V_109 . V_110 = V_111 ;
V_1 -> V_81 . V_112 = & V_87 -> V_81 ;
V_1 -> V_113 = F_33 ;
V_1 -> V_114 = F_35 ;
F_52 ( V_1 , V_15 ) ;
V_1 -> V_115 [ 0 ] = F_53 ( V_116 ) | F_53 ( V_117 ) ;
F_54 ( V_1 , V_12 , V_13 ) ;
V_1 -> V_28 = V_15 -> V_28 ;
V_1 -> V_118 = sizeof( V_15 -> V_28 [ 0 ] ) ;
V_1 -> V_119 = V_34 ;
if ( V_54 -> V_30 )
V_1 -> V_119 *= 2 ;
V_15 -> V_30 = V_54 -> V_30 ;
V_15 -> V_31 = V_54 -> V_31 ;
V_90 = V_54 -> V_90 ? : & V_120 ;
F_55 ( V_90 , V_27 ,
V_1 -> V_28 , V_1 -> V_121 ) ;
V_93 = F_56 ( V_15 -> V_48 , F_16 , V_122 ,
V_87 -> V_102 , V_15 ) ;
if ( V_93 ) {
F_37 ( & V_87 -> V_81 , L_8 ) ;
goto V_123;
}
F_30 ( V_15 -> V_48 ) ;
V_93 = F_57 ( V_15 -> V_35 ) ;
if ( V_93 ) {
F_37 ( & V_87 -> V_81 , L_9 ) ;
goto V_124;
}
F_58 ( V_87 , V_15 ) ;
F_59 ( & V_87 -> V_81 , V_54 -> V_56 ) ;
return 0 ;
V_124:
F_60 ( V_15 -> V_48 , V_87 ) ;
V_123:
F_61 ( V_15 -> V_74 ) ;
V_105:
F_62 ( V_15 -> V_22 ) ;
V_104:
F_63 ( V_92 -> V_101 , F_46 ( V_92 ) ) ;
V_100:
F_64 ( V_1 ) ;
F_65 ( V_15 ) ;
return V_93 ;
}
static int T_5 F_66 ( struct V_86 * V_87 )
{
struct V_14 * V_15 = F_67 ( V_87 ) ;
struct V_91 * V_92 ;
F_60 ( V_15 -> V_48 , V_87 ) ;
F_61 ( V_15 -> V_74 ) ;
F_68 ( V_15 -> V_35 ) ;
F_62 ( V_15 -> V_22 ) ;
V_92 = F_39 ( V_87 , V_96 , 0 ) ;
F_63 ( V_92 -> V_101 , F_46 ( V_92 ) ) ;
F_65 ( V_15 ) ;
F_58 ( V_87 , NULL ) ;
return 0 ;
}
static int F_69 ( struct V_82 * V_81 )
{
struct V_86 * V_87 = F_70 ( V_81 ) ;
struct V_14 * V_15 = F_67 ( V_87 ) ;
F_71 ( & V_15 -> V_35 -> V_125 ) ;
if ( F_72 ( & V_87 -> V_81 ) ) {
F_30 ( V_15 -> V_48 ) ;
F_31 ( & V_15 -> V_46 ) ;
F_9 ( V_15 , false ) ;
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
V_15 -> V_126 = F_6 ( V_15 -> V_22 + V_127 ) ;
F_10 ( 0 , V_15 -> V_22 + V_127 ) ;
F_17 ( V_15 , true ) ;
F_73 ( 30 ) ;
F_74 ( V_15 -> V_48 ) ;
} else {
if ( V_15 -> V_35 -> V_128 )
F_29 ( V_15 ) ;
}
F_75 ( & V_15 -> V_35 -> V_125 ) ;
return 0 ;
}
static int F_76 ( struct V_82 * V_81 )
{
struct V_86 * V_87 = F_70 ( V_81 ) ;
struct V_14 * V_15 = F_67 ( V_87 ) ;
int V_93 = 0 ;
F_71 ( & V_15 -> V_35 -> V_125 ) ;
if ( F_72 ( & V_87 -> V_81 ) ) {
F_77 ( V_15 -> V_48 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_15 -> V_126 , V_15 -> V_22 + V_127 ) ;
F_9 ( V_15 , true ) ;
F_28 ( V_15 -> V_48 ) ;
} else {
if ( V_15 -> V_35 -> V_128 )
V_93 = F_19 ( V_15 ) ;
}
F_75 ( & V_15 -> V_35 -> V_125 ) ;
return V_93 ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_129 ) ;
}
static int T_7 F_80 ( void )
{
return F_81 ( & V_129 ) ;
}
