static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 )
{
if ( V_3 == V_5 )
V_4 |= V_2 -> V_6 ;
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_7 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_8 , unsigned char V_9 )
{
F_1 ( V_2 , V_3 , ( F_3 ( V_2 , V_3 ) | V_8 ) & ~ V_9 ) ;
}
static T_1 F_6 ( unsigned long V_10 , T_1 V_11 , T_1 V_12 )
{
return ( ( ( V_10 * ( V_11 + V_12 ) ) + 5000 ) / 10000 ) ;
}
static T_1 F_7 ( unsigned long V_10 , T_1 V_13 , T_1 V_12 )
{
return ( ( ( V_10 * ( V_13 + V_12 ) ) + 5000 ) / 10000 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
T_1 V_13 , V_11 , V_12 ;
T_2 V_15 ;
F_9 ( V_2 -> V_16 ) ;
V_14 = F_10 ( V_2 -> V_16 ) / 1000 ;
F_11 ( V_2 -> V_16 ) ;
V_14 /= V_2 -> V_17 ;
if ( V_2 -> V_18 == V_19 ) {
V_11 = 47 ;
V_13 = 40 ;
V_12 = 3 ;
} else if ( V_2 -> V_18 == V_20 ) {
V_11 = 13 ;
V_13 = 6 ;
V_12 = 3 ;
} else {
F_12 ( V_2 -> V_21 , L_1 ,
V_2 -> V_18 ) ;
return - V_22 ;
}
V_2 -> V_23 = F_6 ( V_14 , V_11 , V_12 ) ;
V_2 -> V_24 = F_7 ( V_14 , V_13 , V_12 ) ;
V_15 = V_2 -> V_25 & V_26 ? 0x1ff : 0xff ;
if ( V_2 -> V_23 > V_15 || V_2 -> V_24 > V_15 ) {
F_12 ( V_2 -> V_21 , L_2 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
return - V_22 ;
}
if ( V_2 -> V_23 & 0x100 )
V_2 -> V_6 |= V_27 ;
else
V_2 -> V_6 &= ~ V_27 ;
if ( V_2 -> V_24 & 0x100 )
V_2 -> V_6 |= V_28 ;
else
V_2 -> V_6 &= ~ V_28 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_21 ) ;
F_9 ( V_2 -> V_16 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_24 & 0xff ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , 0 ) ;
F_1 ( V_2 , V_5 , 0 ) ;
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_11 ( V_2 -> V_16 ) ;
F_16 ( V_2 -> V_21 ) ;
}
static unsigned char F_17 ( struct V_1 * V_2 ,
enum V_34 V_35 , unsigned char V_4 )
{
unsigned char V_36 = 0 ;
unsigned long V_25 ;
F_18 ( V_2 -> V_21 , L_3 , V_35 , V_4 ) ;
F_19 ( & V_2 -> V_37 , V_25 ) ;
switch ( V_35 ) {
case V_38 :
F_1 ( V_2 , V_29 , V_30 | V_39 | V_40 ) ;
break;
case V_41 :
F_1 ( V_2 , V_5 , V_42 | V_43 | V_44 ) ;
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_46 :
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_47 :
F_1 ( V_2 , V_45 , V_4 ) ;
F_1 ( V_2 , V_29 , V_2 -> V_48 ? V_30 | V_39
: V_30 | V_39 | V_40 ) ;
break;
case V_49 :
F_1 ( V_2 , V_29 , V_30 | V_50 ) ;
break;
case V_51 :
V_36 = F_3 ( V_2 , V_45 ) ;
break;
case V_52 :
F_1 ( V_2 , V_5 ,
V_53 | V_42 | V_43 | V_44 ) ;
F_1 ( V_2 , V_29 , V_30 | V_54 ) ;
break;
case V_55 :
F_1 ( V_2 , V_5 ,
V_53 | V_42 | V_43 | V_44 ) ;
V_36 = F_3 ( V_2 , V_45 ) ;
F_1 ( V_2 , V_29 , V_30 | V_54 ) ;
break;
}
F_20 ( & V_2 -> V_37 , V_25 ) ;
F_18 ( V_2 -> V_21 , L_4 , V_35 , V_36 ) ;
return V_36 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_56 == - 1 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_56 == V_2 -> V_57 -> V_58 - 1 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned char * V_59 )
{
switch ( V_2 -> V_56 ) {
case - 1 :
* V_59 = ( V_2 -> V_57 -> V_60 & 0x7f ) << 1 ;
* V_59 |= ( V_2 -> V_57 -> V_25 & V_61 ) ? 1 : 0 ;
break;
default:
* V_59 = V_2 -> V_57 -> V_59 [ V_2 -> V_56 ] ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
if ( V_2 -> V_56 == V_2 -> V_57 -> V_58 )
return 1 ;
F_23 ( V_2 , & V_4 ) ;
if ( F_22 ( V_2 ) )
F_17 ( V_2 , V_47 , V_4 ) ;
else if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_41 , V_4 ) ;
else
F_17 ( V_2 , V_46 , V_4 ) ;
V_2 -> V_56 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_4 ;
int V_62 ;
do {
if ( V_2 -> V_56 <= - 1 ) {
F_23 ( V_2 , & V_4 ) ;
if ( F_21 ( V_2 ) )
F_17 ( V_2 , V_41 , V_4 ) ;
else
F_17 ( V_2 , V_46 , V_4 ) ;
break;
}
if ( V_2 -> V_56 == 0 ) {
F_17 ( V_2 , V_49 , 0 ) ;
break;
}
V_62 = V_2 -> V_56 - 2 ;
if ( V_2 -> V_56 == V_2 -> V_57 -> V_58 ) {
if ( V_62 < 0 ) {
F_17 ( V_2 , V_52 , 0 ) ;
break;
}
V_4 = F_17 ( V_2 , V_55 , 0 ) ;
} else
V_4 = F_17 ( V_2 , V_51 , 0 ) ;
if ( V_62 >= 0 )
V_2 -> V_57 -> V_59 [ V_62 ] = V_4 ;
} while ( 0 );
V_2 -> V_56 ++ ;
return V_2 -> V_56 == ( V_2 -> V_57 -> V_58 + 2 ) ;
}
static T_3 F_26 ( int V_63 , void * V_64 )
{
struct V_65 * V_21 = V_64 ;
struct V_1 * V_2 = F_27 ( V_21 ) ;
unsigned char V_66 ;
int V_67 ;
V_66 = F_3 ( V_2 , V_33 ) ;
V_2 -> V_66 |= V_66 ;
F_18 ( V_2 -> V_21 , L_5 , V_66 , V_2 -> V_66 ,
( V_2 -> V_57 -> V_25 & V_61 ) ? L_6 : L_7 ,
V_2 -> V_56 , V_2 -> V_57 -> V_58 ) ;
if ( V_66 & ( V_68 | V_69 ) ) {
F_1 ( V_2 , V_33 , V_66 & ~ ( V_68 | V_69 ) ) ;
V_67 = 0 ;
} else if ( V_2 -> V_57 -> V_25 & V_61 )
V_67 = F_25 ( V_2 ) ;
else
V_67 = F_24 ( V_2 ) ;
if ( V_66 & V_70 )
F_1 ( V_2 , V_33 , V_66 & ~ V_70 ) ;
if ( V_67 ) {
V_2 -> V_66 |= V_71 ;
F_28 ( & V_2 -> V_72 ) ;
}
F_3 ( V_2 , V_33 ) ;
return V_73 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_74 * V_75 ,
bool V_76 )
{
if ( V_75 -> V_58 == 0 && ( V_75 -> V_25 & V_61 ) ) {
F_12 ( V_2 -> V_21 , L_8 ) ;
return - V_77 ;
}
if ( V_76 ) {
F_5 ( V_2 , V_29 , 0 , V_30 ) ;
F_5 ( V_2 , V_29 , V_30 , 0 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_23 & 0xff ) ;
F_1 ( V_2 , V_32 , V_2 -> V_24 & 0xff ) ;
}
V_2 -> V_57 = V_75 ;
V_2 -> V_56 = - 1 ;
V_2 -> V_66 = 0 ;
F_1 ( V_2 , V_5 , V_53 | V_42 | V_43 | V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_78 ;
for ( V_78 = 1000 ; V_78 ; V_78 -- ) {
T_4 V_79 = F_3 ( V_2 , V_33 ) ;
if ( V_79 & V_80 )
break;
if ( V_79 & V_69 )
return - V_81 ;
F_31 ( 10 ) ;
}
return V_78 ? 0 : - V_82 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_78 ;
for ( V_78 = 1000 ; V_78 ; V_78 -- ) {
T_4 V_79 = F_3 ( V_2 , V_33 ) ;
F_18 ( V_2 -> V_21 , L_9 , V_79 , V_2 -> V_66 ) ;
if ( ! ( V_79 & V_83 ) ) {
V_79 |= V_2 -> V_66 ;
if ( V_79 & V_69 )
return - V_81 ;
if ( V_79 & V_68 )
return - V_84 ;
break;
}
F_31 ( 10 ) ;
}
return V_78 ? 0 : - V_82 ;
}
static int F_33 ( struct V_85 * V_86 ,
struct V_74 * V_87 ,
int V_88 )
{
struct V_1 * V_2 = F_34 ( V_86 ) ;
struct V_74 * V_57 ;
int V_89 = 0 ;
int V_78 , V_90 ;
F_13 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_88 ; V_78 ++ ) {
bool V_91 = V_2 -> V_48 || ! V_78 ;
V_57 = & V_87 [ V_78 ] ;
V_2 -> V_48 = V_78 == V_88 - 1 || V_57 -> V_25 & V_92 ;
V_89 = F_29 ( V_2 , V_57 , V_91 ) ;
if ( V_89 )
break;
if ( V_91 )
F_17 ( V_2 , V_38 , 0 ) ;
V_90 = F_35 ( V_2 -> V_72 ,
V_2 -> V_66 & ( V_69 | V_71 ) ,
5 * V_93 ) ;
if ( ! V_90 ) {
F_12 ( V_2 -> V_21 , L_10 ) ;
V_89 = - V_82 ;
break;
}
if ( V_2 -> V_48 )
V_89 = F_32 ( V_2 ) ;
else
V_89 = F_30 ( V_2 ) ;
if ( V_89 < 0 )
break;
}
F_15 ( V_2 ) ;
if ( ! V_89 )
V_89 = V_88 ;
return V_89 ;
}
static T_1 F_36 ( struct V_85 * V_86 )
{
return V_94 | V_95 | V_96 ;
}
static int F_37 ( struct V_65 * V_21 )
{
struct V_97 * V_98 ;
T_5 V_99 ;
int V_90 = 0 , V_36 ;
while ( ( V_98 = F_38 ( V_21 , V_100 , V_90 ) ) ) {
for ( V_99 = V_98 -> V_101 ; V_99 <= V_98 -> V_102 ; V_99 ++ ) {
V_36 = F_39 ( & V_21 -> V_21 , V_99 , F_26 ,
0 , F_40 ( & V_21 -> V_21 ) , V_21 ) ;
if ( V_36 ) {
F_12 ( & V_21 -> V_21 , L_11 , & V_99 ) ;
return V_36 ;
}
}
V_90 ++ ;
}
return V_90 > 0 ? 0 : - V_103 ;
}
static int F_41 ( struct V_65 * V_21 )
{
struct V_104 * V_105 = F_42 ( & V_21 -> V_21 ) ;
struct V_1 * V_2 ;
struct V_85 * V_106 ;
struct V_97 * V_98 ;
int V_36 ;
T_1 V_18 ;
V_2 = F_43 ( & V_21 -> V_21 , sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_2 )
return - V_108 ;
V_2 -> V_16 = F_44 ( & V_21 -> V_21 , NULL ) ;
if ( F_45 ( V_2 -> V_16 ) ) {
F_12 ( & V_21 -> V_21 , L_12 ) ;
return F_46 ( V_2 -> V_16 ) ;
}
V_36 = F_37 ( V_21 ) ;
if ( V_36 )
return V_36 ;
V_2 -> V_21 = & V_21 -> V_21 ;
F_47 ( V_21 , V_2 ) ;
V_98 = F_38 ( V_21 , V_109 , 0 ) ;
V_2 -> V_7 = F_48 ( & V_21 -> V_21 , V_98 ) ;
if ( F_45 ( V_2 -> V_7 ) )
return F_46 ( V_2 -> V_7 ) ;
V_36 = F_49 ( V_21 -> V_21 . V_110 , L_13 , & V_18 ) ;
V_2 -> V_18 = V_36 ? V_19 : V_18 ;
V_2 -> V_17 = 1 ;
if ( V_21 -> V_21 . V_110 ) {
const struct V_111 * V_112 ;
V_112 = F_50 ( V_113 , & V_21 -> V_21 ) ;
if ( V_112 ) {
const struct V_114 * V_115 ;
V_115 = V_112 -> V_4 ;
V_2 -> V_17 = V_115 -> V_17 ;
}
} else {
if ( V_105 && V_105 -> V_18 )
V_2 -> V_18 = V_105 -> V_18 ;
if ( V_105 && V_105 -> V_17 )
V_2 -> V_17 = V_105 -> V_17 ;
}
if ( F_51 ( V_98 ) > 0x17 )
V_2 -> V_25 |= V_26 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_52 ( & V_21 -> V_21 , true ) ;
F_53 ( & V_21 -> V_21 ) ;
V_106 = & V_2 -> V_106 ;
F_54 ( V_106 , V_2 ) ;
V_106 -> V_116 = V_117 ;
V_106 -> V_118 = & V_119 ;
V_106 -> V_21 . V_120 = & V_21 -> V_21 ;
V_106 -> V_121 = 5 ;
V_106 -> V_122 = V_21 -> V_123 ;
V_106 -> V_21 . V_110 = V_21 -> V_21 . V_110 ;
F_55 ( V_106 -> V_124 , V_21 -> V_124 , sizeof( V_106 -> V_124 ) ) ;
F_56 ( & V_2 -> V_37 ) ;
F_57 ( & V_2 -> V_72 ) ;
V_36 = F_58 ( V_106 ) ;
if ( V_36 < 0 ) {
F_12 ( & V_21 -> V_21 , L_14 ) ;
return V_36 ;
}
F_59 ( & V_21 -> V_21 ,
L_15 ,
V_106 -> V_122 , V_2 -> V_18 , V_2 -> V_23 , V_2 -> V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_65 * V_21 )
{
struct V_1 * V_2 = F_27 ( V_21 ) ;
F_61 ( & V_2 -> V_106 ) ;
F_62 ( & V_21 -> V_21 ) ;
return 0 ;
}
static int F_63 ( struct V_125 * V_21 )
{
return 0 ;
}
static int T_6 F_64 ( void )
{
return F_65 ( & V_126 ) ;
}
static void T_7 F_66 ( void )
{
F_67 ( & V_126 ) ;
}
