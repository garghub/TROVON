static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 ;
unsigned int V_8 ;
while ( 1 ) {
V_8 = F_4 ( V_2 -> V_4 + V_9 ) ;
if ( V_8 & V_10 ) {
F_2 ( V_8 , V_2 -> V_4 + V_9 ) ;
return - V_11 ;
}
if ( V_8 & ( V_12 | V_13 ) )
break;
if ( F_5 ( V_7 , V_6 + F_6 ( 500 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 , L_1 ) ;
return - V_16 ;
}
F_8 () ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_17 = V_2 -> V_17 ;
enum V_18 V_19 ;
if ( V_17 < V_20 )
V_19 = V_21 ;
else if ( V_17 < V_22 )
V_19 = V_23 ;
else if ( V_17 < V_24 )
V_19 = V_25 ;
else if ( V_17 < V_26 )
V_19 = V_27 ;
else
V_19 = V_28 ;
V_2 -> V_19 = V_19 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
unsigned int V_8 ;
T_1 V_31 ;
V_8 = F_4 ( V_2 -> V_4 + V_32 ) ;
V_8 |= V_33 | V_34 ;
F_2 ( V_8 , V_2 -> V_4 + V_32 ) ;
F_2 ( 0x7f00 , V_2 -> V_4 + V_9 ) ;
V_31 = V_30 -> V_35 & V_36 ;
V_8 = ( V_30 -> V_37 << 1 | V_31 ) | ( V_38 << 8 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_39 ) ;
return F_3 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 ;
unsigned int V_8 ;
F_2 ( V_40 << 8 , V_2 -> V_4 + V_39 ) ;
do {
V_8 = F_4 ( V_2 -> V_4 + V_9 ) ;
if ( V_8 & V_41 )
break;
if ( F_5 ( V_7 , V_6 + F_6 ( 500 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 , L_2 ) ;
break;
}
F_8 () ;
} while ( 1 );
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
unsigned int V_48 , V_49 ;
enum V_50 V_51 ;
unsigned int V_8 ;
F_9 ( V_2 ) ;
V_48 = F_13 ( V_2 -> V_52 ) ;
if ( V_2 -> V_19 == V_27 || V_2 -> V_19 == V_28 )
V_43 = 0 ;
else
V_43 = 2 ;
for ( V_42 = 0 ; V_42 <= 7 ; V_42 ++ ) {
V_49 = V_48 / ( ( 1 << V_42 ) * V_2 -> V_17 )
- 3 - ( V_43 >> 1 ) ;
V_45 = ( V_49 + V_53 ) / ( V_53 + 1 ) ;
V_46 = V_49 - V_45 ;
if ( V_46 < 64 )
break;
}
if ( V_42 > 7 )
return - V_54 ;
if ( V_2 -> V_19 == V_28 )
V_51 = V_55 ;
else
V_51 = V_56 ;
V_8 = V_42 | V_51 << 24 ;
if ( V_2 -> V_19 == V_28 )
V_8 |= V_57 ;
F_2 ( V_8 , V_2 -> V_4 + V_58 ) ;
V_8 = ( V_43 << 16 ) | ( V_43 << 24 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_59 ) ;
V_44 = V_45 ;
V_47 = V_45 >> 1 ;
V_8 = V_47 << 24 | V_44 << 16 | V_45 << 8 | V_46 ;
if ( V_2 -> V_19 == V_27 )
F_2 ( V_8 , V_2 -> V_4 + V_60 ) ;
else
F_2 ( V_8 , V_2 -> V_4 + V_61 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
int V_62 ;
V_62 = F_15 ( V_2 -> V_52 ) ;
if ( V_62 )
return V_62 ;
V_8 = V_63 ;
F_2 ( V_8 , V_2 -> V_4 + V_32 ) ;
F_2 ( 0 , V_2 -> V_4 + V_32 ) ;
V_62 = F_12 ( V_2 ) ;
if ( V_62 )
goto V_64;
V_8 = F_4 ( V_2 -> V_4 + V_32 ) ;
V_8 |= V_65 ;
F_2 ( V_8 , V_2 -> V_4 + V_32 ) ;
return 0 ;
V_64:
V_64 ( V_2 -> V_52 ) ;
return V_62 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_8 ;
V_8 = F_4 ( V_2 -> V_4 + V_32 ) ;
V_8 &= ~ V_65 ;
F_2 ( V_8 , V_2 -> V_4 + V_32 ) ;
V_64 ( V_2 -> V_52 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_66 ;
V_66 = F_18 ( & V_2 -> V_67 , V_68 ) ;
return V_66 ? 0 : - V_16 ;
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 ;
T_2 V_69 ;
do {
V_69 = F_4 ( V_2 -> V_4 + V_70 ) & 0xff ;
if ( F_4 ( V_2 -> V_4 + V_9 ) & V_71 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_3 ) ;
return - V_72 ;
}
if ( F_5 ( V_7 , V_6 + F_6 ( 500 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 , L_4 ) ;
return - V_16 ;
}
F_8 () ;
} while ( V_69 );
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_73 >> 1 , V_2 -> V_4 + V_74 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned int V_8 , V_75 ;
V_75 = V_2 -> V_76 - V_2 -> V_77 ;
if ( V_75 > ( V_2 -> V_78 >> 1 ) )
V_8 = V_2 -> V_78 >> 1 ;
else
V_8 = 0 ;
F_2 ( V_8 << 16 , V_2 -> V_4 + V_74 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned int V_79 , V_69 ;
V_69 = F_4 ( V_2 -> V_4 + V_70 ) & 0xff ;
while ( V_69 < V_2 -> V_73 ) {
if ( V_2 -> V_77 == V_2 -> V_76 )
break;
V_79 = V_2 -> V_80 [ V_2 -> V_77 ++ ] ;
F_2 ( V_79 , V_2 -> V_4 + V_39 ) ;
V_69 ++ ;
}
if ( V_2 -> V_77 < V_2 -> V_76 )
F_1 ( V_2 , V_81 | V_82 ) ;
else
V_67 ( & V_2 -> V_67 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_83 , V_75 ;
unsigned int V_8 , V_79 ;
do {
V_79 = F_4 ( V_2 -> V_4 + V_84 ) ;
if ( V_79 & V_85 )
break;
V_2 -> V_86 [ V_2 -> V_77 ++ ] = V_79 & 0xff ;
} while ( 1 );
if ( V_2 -> V_87 ) {
V_83 = V_2 -> V_86 [ 0 ] ;
V_2 -> V_76 += V_83 ;
}
V_75 = V_2 -> V_76 - V_2 -> V_77 ;
if ( ! V_75 ) {
V_67 ( & V_2 -> V_67 ) ;
return;
}
F_21 ( V_2 ) ;
if ( V_2 -> V_87 ) {
V_2 -> V_87 = 0 ;
V_8 = V_75 ;
V_8 |= ( V_88 << 8 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_39 ) ;
} else if ( ! ( V_2 -> V_77 & 0xff ) ) {
V_8 = ( V_75 > V_89 ? V_89 : V_75 ) - 1 ;
V_8 |= ( V_88 << 8 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_39 ) ;
}
F_1 ( V_2 , V_90 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
V_2 -> V_80 = V_30 -> V_91 ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
unsigned int V_8 ;
V_2 -> V_86 = V_30 -> V_91 ;
V_2 -> V_87 = V_30 -> V_35 & V_92 ;
F_21 ( V_2 ) ;
V_8 = V_30 -> V_93 > V_89 ? V_89 - 1 : V_30 -> V_93 - 1 ;
V_8 |= ( V_88 << 8 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_39 ) ;
F_1 ( V_2 , V_90 | V_82 ) ;
}
static int F_26 ( struct V_94 * V_14 ,
struct V_29 * V_30 , int V_95 )
{
struct V_1 * V_2 = F_27 ( V_14 ) ;
unsigned int V_8 ;
int V_96 , V_97 ;
V_97 = F_14 ( V_2 ) ;
if ( V_97 )
return V_97 ;
for ( V_96 = 0 ; V_96 < V_95 ; V_96 ++ ) {
V_97 = F_10 ( V_2 , & V_30 [ V_96 ] ) ;
if ( V_97 )
goto V_98;
if ( V_95 == 1 && V_30 [ 0 ] . V_93 == 0 )
goto V_99;
V_2 -> V_77 = 0 ;
V_2 -> V_76 = V_30 [ V_96 ] . V_93 ;
F_28 ( & V_2 -> V_67 ) ;
if ( V_30 [ V_96 ] . V_35 & V_36 )
F_25 ( V_2 , & V_30 [ V_96 ] ) ;
else
F_24 ( V_2 , & V_30 [ V_96 ] ) ;
V_97 = F_17 ( V_2 ) ;
if ( V_97 )
goto V_99;
if ( ! ( V_30 [ V_96 ] . V_35 & V_36 ) ) {
V_97 = F_19 ( V_2 ) ;
if ( V_97 )
goto V_99;
}
}
V_99:
F_11 ( V_2 ) ;
V_8 = F_4 ( V_2 -> V_4 + V_9 ) ;
if ( ( V_8 & V_71 ) && ! V_97 )
V_97 = - V_72 ;
V_98:
F_16 ( V_2 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_5 , V_100 ,
( V_97 < 0 ) ? L_6 : L_7 ,
( V_97 < 0 ) ? V_97 : V_95 ) ;
return ( V_97 < 0 ) ? V_97 : V_95 ;
}
static T_3 F_29 ( int V_101 , void * V_102 )
{
struct V_1 * V_2 = V_102 ;
unsigned int V_8 ;
F_1 ( V_2 , 0 ) ;
V_8 = F_4 ( V_2 -> V_4 + V_9 ) ;
if ( V_8 & V_103 )
F_23 ( V_2 ) ;
if ( V_8 & V_104 )
F_22 ( V_2 ) ;
if ( V_8 & V_71 )
V_67 ( & V_2 -> V_67 ) ;
return V_105 ;
}
static T_2 F_30 ( struct V_94 * V_14 )
{
return V_106 | V_107 |
V_108 ;
}
static int F_31 ( struct V_109 * V_110 )
{
struct V_1 * V_2 ;
struct V_111 * V_112 ;
unsigned int V_8 ;
int V_101 , V_62 ;
V_2 = F_32 ( & V_110 -> V_15 , sizeof( * V_2 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_112 = F_33 ( V_110 , V_115 , 0 ) ;
V_2 -> V_4 = F_34 ( & V_110 -> V_15 , V_112 ) ;
if ( F_35 ( V_2 -> V_4 ) )
return F_36 ( V_2 -> V_4 ) ;
V_101 = F_37 ( V_110 , 0 ) ;
if ( V_101 < 0 ) {
F_38 ( & V_110 -> V_15 , L_8 ) ;
return V_101 ;
}
V_2 -> V_14 . V_116 = V_117 ;
V_2 -> V_14 . V_118 = & V_119 ;
V_2 -> V_14 . V_15 . V_120 = & V_110 -> V_15 ;
V_2 -> V_14 . V_15 . V_121 = V_110 -> V_15 . V_121 ;
F_39 ( V_2 -> V_14 . V_122 , V_110 -> V_122 ,
sizeof( V_2 -> V_14 . V_122 ) ) ;
V_2 -> V_52 = F_40 ( & V_110 -> V_15 , NULL ) ;
if ( F_35 ( V_2 -> V_52 ) ) {
F_38 ( & V_110 -> V_15 , L_9 ) ;
return F_36 ( V_2 -> V_52 ) ;
}
V_62 = F_41 ( V_110 -> V_15 . V_121 ,
L_10 , & V_2 -> V_17 ) ;
if ( V_62 )
V_2 -> V_17 = V_123 ;
V_62 = F_42 ( & V_110 -> V_15 , V_101 , F_29 , 0 ,
V_110 -> V_122 , V_2 ) ;
if ( V_62 ) {
F_38 ( & V_110 -> V_15 , L_11 , V_101 ) ;
return V_62 ;
}
F_43 ( & V_2 -> V_14 , V_2 ) ;
F_44 ( V_110 , V_2 ) ;
V_62 = F_45 ( V_2 -> V_52 ) ;
if ( V_62 ) {
F_38 ( & V_110 -> V_15 , L_12 , V_62 ) ;
return V_62 ;
}
V_8 = F_4 ( V_2 -> V_4 + V_124 ) ;
V_2 -> V_73 = 1 << ( V_8 & 0x0f ) ;
V_2 -> V_78 = 1 << ( ( V_8 >> 8 ) & 0x0f ) ;
V_64 ( V_2 -> V_52 ) ;
V_62 = F_46 ( & V_2 -> V_14 ) ;
if ( V_62 )
goto V_125;
F_47 ( & V_2 -> V_14 . V_15 , L_13 ) ;
return 0 ;
V_125:
V_125 ( V_2 -> V_52 ) ;
return V_62 ;
}
static int F_48 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_49 ( V_110 ) ;
F_50 ( & V_2 -> V_14 ) ;
V_125 ( V_2 -> V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_126 * V_15 )
{
F_52 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_126 * V_15 )
{
F_54 ( V_15 ) ;
return 0 ;
}
