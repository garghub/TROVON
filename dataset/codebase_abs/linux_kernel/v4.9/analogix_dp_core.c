static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
while ( V_3 < V_4 ) {
if ( F_12 ( V_2 ) == 0 )
return 0 ;
V_3 ++ ;
F_13 ( 10 , 11 ) ;
}
if ( ! V_2 -> V_5 )
return - V_6 ;
F_14 ( V_2 -> V_7 , L_1 ) ;
F_15 ( V_2 ) ;
if ( F_12 ( V_2 ) != 0 ) {
F_16 ( V_2 -> V_7 , L_2 ) ;
return - V_8 ;
}
F_14 ( V_2 -> V_7 , L_3 ) ;
return 0 ;
}
int F_17 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
return V_2 -> V_10 ;
}
int F_19 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
struct V_11 V_12 ;
if ( ! V_2 -> V_10 )
return - V_8 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 . V_14 = 0 ;
V_12 . V_13 . V_15 = 0x7 ;
V_12 . V_13 . V_16 = 0x2 ;
V_12 . V_13 . V_17 = 0x8 ;
V_12 . V_18 = 0 ;
V_12 . V_19 = V_20 | V_21 ;
F_20 ( V_2 , & V_12 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
struct V_11 V_12 ;
if ( ! V_2 -> V_10 )
return - V_8 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 . V_14 = 0 ;
V_12 . V_13 . V_15 = 0x7 ;
V_12 . V_13 . V_16 = 0x2 ;
V_12 . V_13 . V_17 = 0x8 ;
V_12 . V_18 = 0 ;
V_12 . V_19 = 0 ;
F_20 ( V_2 , & V_12 ) ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
unsigned char V_22 ;
F_23 ( & V_2 -> V_23 , V_24 , & V_22 ) ;
F_14 ( V_2 -> V_7 , L_4 , V_22 ) ;
return ( V_22 & V_25 ) ? true : false ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned char V_26 ;
F_23 ( & V_2 -> V_23 , V_27 , & V_26 ) ;
V_26 &= ~ V_28 ;
F_25 ( & V_2 -> V_23 , V_27 , V_26 ) ;
V_26 = V_29 | V_30 ;
F_25 ( & V_2 -> V_23 , V_27 , V_26 ) ;
V_26 = V_28 | V_29 |
V_30 ;
F_25 ( & V_2 -> V_23 , V_27 , V_26 ) ;
F_26 ( V_2 ) ;
}
static void
F_27 ( struct V_1 * V_2 ,
bool V_31 )
{
T_1 V_32 ;
F_23 ( & V_2 -> V_23 , V_33 , & V_32 ) ;
if ( V_31 )
F_25 ( & V_2 -> V_23 , V_33 ,
V_34 |
F_28 ( V_32 ) ) ;
else
F_25 ( & V_2 -> V_23 , V_33 ,
F_28 ( V_32 ) ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_32 ;
int V_35 ;
F_23 ( & V_2 -> V_23 , V_36 , & V_32 ) ;
V_35 = F_30 ( V_32 ) ;
return V_35 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = F_29 ( V_2 ) ;
F_27 ( V_2 , V_32 ) ;
F_32 ( V_2 , V_32 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 , V_37 ) ;
F_25 ( & V_2 -> V_23 , V_38 ,
V_39 ) ;
}
static void
F_35 ( struct V_1 * V_2 ,
int V_40 , int V_41 )
{
switch ( V_41 ) {
case 0 :
F_36 ( V_2 , V_40 ) ;
break;
case 1 :
F_37 ( V_2 , V_40 ) ;
break;
case 2 :
F_38 ( V_2 , V_40 ) ;
break;
case 3 :
F_39 ( V_2 , V_40 ) ;
break;
}
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_42 [ 4 ] ;
int V_41 , V_43 , V_44 , V_35 ;
V_43 = V_2 -> V_45 . V_43 ;
V_2 -> V_45 . V_46 = V_47 ;
V_2 -> V_45 . V_48 = 0 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
V_2 -> V_45 . V_49 [ V_41 ] = 0 ;
F_41 ( V_2 , V_2 -> V_45 . V_50 ) ;
F_42 ( V_2 , V_2 -> V_45 . V_43 ) ;
V_42 [ 0 ] = V_2 -> V_45 . V_50 ;
V_42 [ 1 ] = V_2 -> V_45 . V_43 ;
V_35 = F_43 ( & V_2 -> V_23 , V_51 , V_42 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
F_35 ( V_2 ,
V_52 , V_41 ) ;
V_44 = 0 ;
while ( F_44 ( V_2 ) == V_53 ) {
if ( V_44 == V_4 ) {
F_16 ( V_2 -> V_7 , L_5 ) ;
return - V_6 ;
}
V_44 ++ ;
F_13 ( 90 , 120 ) ;
}
F_34 ( V_2 , V_54 ) ;
V_35 = F_25 ( & V_2 -> V_23 , V_38 ,
V_55 |
V_56 ) ;
if ( V_35 < 0 )
return V_35 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
V_42 [ V_41 ] = V_57 |
V_58 ;
V_35 = F_43 ( & V_2 -> V_23 , V_59 , V_42 ,
V_43 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static unsigned char F_45 ( T_1 V_60 [ 2 ] , int V_41 )
{
int V_61 = ( V_41 & 1 ) * 4 ;
T_1 V_62 = V_60 [ V_41 >> 1 ] ;
return ( V_62 >> V_61 ) & 0xf ;
}
static int F_46 ( T_1 V_60 [ 2 ] , int V_43 )
{
int V_41 ;
T_1 V_63 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_63 = F_45 ( V_60 , V_41 ) ;
if ( ( V_63 & V_64 ) == 0 )
return - V_8 ;
}
return 0 ;
}
static int F_47 ( T_1 V_60 [ 2 ] , T_1 V_65 ,
int V_43 )
{
int V_41 ;
T_1 V_63 ;
if ( ( V_65 & V_66 ) == 0 )
return - V_8 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_63 = F_45 ( V_60 , V_41 ) ;
V_63 &= V_67 ;
if ( V_63 != V_67 )
return - V_8 ;
}
return 0 ;
}
static unsigned char
F_48 ( T_1 V_68 [ 2 ] , int V_41 )
{
int V_61 = ( V_41 & 1 ) * 4 ;
T_1 V_62 = V_68 [ V_41 >> 1 ] ;
return ( V_62 >> V_61 ) & 0x3 ;
}
static unsigned char F_49 (
T_1 V_68 [ 2 ] ,
int V_41 )
{
int V_61 = ( V_41 & 1 ) * 4 ;
T_1 V_62 = V_68 [ V_41 >> 1 ] ;
return ( ( V_62 >> V_61 ) & 0xc ) >> 2 ;
}
static void F_50 ( struct V_1 * V_2 ,
T_1 V_69 , int V_41 )
{
switch ( V_41 ) {
case 0 :
F_51 ( V_2 , V_69 ) ;
break;
case 1 :
F_52 ( V_2 , V_69 ) ;
break;
case 2 :
F_53 ( V_2 , V_69 ) ;
break;
case 3 :
F_54 ( V_2 , V_69 ) ;
break;
}
}
static unsigned int
F_55 ( struct V_1 * V_2 ,
int V_41 )
{
T_2 V_70 ;
switch ( V_41 ) {
case 0 :
V_70 = F_56 ( V_2 ) ;
break;
case 1 :
V_70 = F_57 ( V_2 ) ;
break;
case 2 :
V_70 = F_58 ( V_2 ) ;
break;
case 3 :
V_70 = F_59 ( V_2 ) ;
break;
default:
F_60 ( 1 ) ;
return 0 ;
}
return V_70 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
V_2 -> V_45 . V_46 = V_71 ;
}
static void F_62 ( struct V_1 * V_2 ,
T_1 V_68 [ 2 ] )
{
int V_41 , V_43 ;
T_1 V_72 , V_40 , V_73 ;
V_43 = V_2 -> V_45 . V_43 ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_72 = F_48 (
V_68 , V_41 ) ;
V_40 = F_49 (
V_68 , V_41 ) ;
V_73 = F_63 ( V_72 ) |
F_64 ( V_40 ) ;
if ( V_72 == V_74 )
V_73 |= V_75 ;
if ( V_40 == V_76 )
V_73 |= V_77 ;
V_2 -> V_45 . V_73 [ V_41 ] = V_73 ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
int V_41 , V_43 , V_35 ;
T_1 V_72 , V_40 , V_73 ;
T_1 V_60 [ 2 ] , V_68 [ 2 ] ;
F_13 ( 100 , 101 ) ;
V_43 = V_2 -> V_45 . V_43 ;
V_35 = F_66 ( & V_2 -> V_23 , V_78 , V_60 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_66 ( & V_2 -> V_23 , V_79 ,
V_68 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_46 ( V_60 , V_43 ) == 0 ) {
F_34 ( V_2 , V_80 ) ;
V_35 = F_25 ( & V_2 -> V_23 , V_38 ,
V_55 |
V_81 ) ;
if ( V_35 < 0 )
return V_35 ;
F_67 ( V_2 -> V_7 , L_6 ) ;
V_2 -> V_45 . V_46 = V_82 ;
} else {
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_73 = F_55 (
V_2 , V_41 ) ;
V_72 = F_48 (
V_68 , V_41 ) ;
V_40 = F_49 (
V_68 , V_41 ) ;
if ( F_68 ( V_73 ) ==
V_72 &&
F_69 ( V_73 ) ==
V_40 )
V_2 -> V_45 . V_49 [ V_41 ] ++ ;
if ( V_2 -> V_45 . V_49 [ V_41 ] == V_83 ||
V_72 == V_74 ||
V_40 == V_76 ) {
F_16 ( V_2 -> V_7 , L_7 ,
V_2 -> V_45 . V_49 [ V_41 ] ,
V_72 , V_40 ) ;
F_61 ( V_2 ) ;
return - V_84 ;
}
}
}
F_62 ( V_2 , V_68 ) ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
F_50 ( V_2 ,
V_2 -> V_45 . V_73 [ V_41 ] , V_41 ) ;
V_35 = F_43 ( & V_2 -> V_23 , V_59 ,
V_2 -> V_45 . V_73 , V_43 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_41 , V_43 , V_35 ;
T_2 V_70 ;
T_1 V_65 , V_60 [ 2 ] , V_68 [ 2 ] ;
F_13 ( 400 , 401 ) ;
V_43 = V_2 -> V_45 . V_43 ;
V_35 = F_66 ( & V_2 -> V_23 , V_78 , V_60 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_46 ( V_60 , V_43 ) ) {
F_61 ( V_2 ) ;
return - V_84 ;
}
V_35 = F_66 ( & V_2 -> V_23 , V_79 ,
V_68 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_23 ( & V_2 -> V_23 , V_85 ,
& V_65 ) ;
if ( V_35 < 0 )
return V_35 ;
F_62 ( V_2 , V_68 ) ;
if ( ! F_47 ( V_60 , V_65 , V_43 ) ) {
F_33 ( V_2 ) ;
F_67 ( V_2 -> V_7 , L_8 ) ;
F_71 ( V_2 , & V_70 ) ;
V_2 -> V_45 . V_50 = V_70 ;
F_14 ( V_2 -> V_7 , L_9 ,
V_2 -> V_45 . V_50 ) ;
F_72 ( V_2 , & V_70 ) ;
V_2 -> V_45 . V_43 = V_70 ;
F_14 ( V_2 -> V_7 , L_10 ,
V_2 -> V_45 . V_43 ) ;
F_31 ( V_2 ) ;
V_2 -> V_45 . V_46 = V_86 ;
return 0 ;
}
V_2 -> V_45 . V_48 ++ ;
if ( V_2 -> V_45 . V_48 > V_87 ) {
F_16 ( V_2 -> V_7 , L_11 ) ;
F_61 ( V_2 ) ;
return - V_84 ;
}
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
F_50 ( V_2 ,
V_2 -> V_45 . V_73 [ V_41 ] , V_41 ) ;
V_35 = F_43 ( & V_2 -> V_23 , V_59 ,
V_2 -> V_45 . V_73 , V_43 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
T_1 * V_88 )
{
T_1 V_32 ;
F_23 ( & V_2 -> V_23 , V_89 , & V_32 ) ;
* V_88 = V_32 ;
}
static void F_74 ( struct V_1 * V_2 ,
T_1 * V_43 )
{
T_1 V_32 ;
F_23 ( & V_2 -> V_23 , V_36 , & V_32 ) ;
* V_43 = F_75 ( V_32 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
enum V_90 V_91 ,
int V_92 )
{
F_77 ( V_2 ) ;
F_73 ( V_2 , & V_2 -> V_45 . V_50 ) ;
F_74 ( V_2 , & V_2 -> V_45 . V_43 ) ;
if ( ( V_2 -> V_45 . V_50 != V_93 ) &&
( V_2 -> V_45 . V_50 != V_94 ) &&
( V_2 -> V_45 . V_50 != V_95 ) ) {
F_16 ( V_2 -> V_7 , L_12 ,
V_2 -> V_45 . V_50 ) ;
V_2 -> V_45 . V_50 = V_93 ;
}
if ( V_2 -> V_45 . V_43 == 0 ) {
F_16 ( V_2 -> V_7 , L_13 ,
V_2 -> V_45 . V_43 ) ;
V_2 -> V_45 . V_43 = ( T_1 ) V_96 ;
}
if ( V_2 -> V_45 . V_43 > V_91 )
V_2 -> V_45 . V_43 = V_91 ;
if ( V_2 -> V_45 . V_50 > V_92 )
V_2 -> V_45 . V_50 = V_92 ;
F_78 ( V_2 , V_97 , 0 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_35 = 0 , V_98 = 0 ;
V_2 -> V_45 . V_46 = V_99 ;
while ( ! V_35 && ! V_98 ) {
switch ( V_2 -> V_45 . V_46 ) {
case V_99 :
V_35 = F_40 ( V_2 ) ;
if ( V_35 )
F_16 ( V_2 -> V_7 , L_14 ) ;
break;
case V_47 :
V_35 = F_65 ( V_2 ) ;
if ( V_35 )
F_16 ( V_2 -> V_7 , L_15 ) ;
break;
case V_82 :
V_35 = F_70 ( V_2 ) ;
if ( V_35 )
F_16 ( V_2 -> V_7 , L_16 ) ;
break;
case V_86 :
V_98 = 1 ;
break;
case V_71 :
return - V_100 ;
}
}
if ( V_35 )
F_16 ( V_2 -> V_7 , L_17 , V_35 ) ;
return V_35 ;
}
static int F_80 ( struct V_1 * V_2 ,
T_2 V_101 , T_2 V_102 )
{
int V_103 ;
int V_35 ;
for ( V_103 = 0 ; V_103 < V_4 ; V_103 ++ ) {
F_76 ( V_2 , V_101 , V_102 ) ;
V_35 = F_79 ( V_2 ) ;
if ( V_35 == 0 )
break;
F_13 ( 100 , 110 ) ;
}
return V_35 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
int V_3 = 0 ;
int V_104 = 0 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( F_44 ( V_2 ) == V_53 ) {
F_16 ( V_2 -> V_7 , L_18 ) ;
return - V_8 ;
}
for (; ; ) {
V_3 ++ ;
if ( F_84 ( V_2 ) == 0 )
break;
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_19 ) ;
return - V_6 ;
}
F_13 ( 1 , 2 ) ;
}
F_85 ( V_2 , V_105 , 0 , 0 ) ;
F_86 ( V_2 , V_106 ) ;
F_87 ( V_2 , 0 ) ;
F_88 ( V_2 , 0 ) ;
V_3 = 0 ;
for (; ; ) {
V_3 ++ ;
if ( F_89 ( V_2 ) == 0 ) {
V_104 ++ ;
if ( V_104 > 10 )
break;
} else if ( V_104 ) {
V_104 = 0 ;
}
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_19 ) ;
return - V_6 ;
}
F_13 ( 1000 , 1001 ) ;
}
if ( V_35 != 0 )
F_16 ( V_2 -> V_7 , L_20 ) ;
return V_35 ;
}
static void F_90 ( struct V_1 * V_2 ,
bool V_31 )
{
T_1 V_32 ;
if ( V_31 ) {
F_91 ( V_2 ) ;
F_23 ( & V_2 -> V_23 , V_38 , & V_32 ) ;
F_25 ( & V_2 -> V_23 , V_38 ,
( T_1 ) ( V_32 & ~ V_55 ) ) ;
} else {
F_92 ( V_2 ) ;
F_23 ( & V_2 -> V_23 , V_38 , & V_32 ) ;
F_25 ( & V_2 -> V_23 , V_38 ,
( T_1 ) ( V_32 | V_55 ) ) ;
}
}
static T_3 F_93 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
T_3 V_109 = V_110 ;
enum V_111 V_112 ;
V_112 = F_94 ( V_2 ) ;
if ( V_112 != V_113 ) {
F_95 ( V_2 ) ;
V_109 = V_114 ;
}
return V_109 ;
}
static T_3 F_96 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
enum V_111 V_112 ;
V_112 = F_94 ( V_2 ) ;
if ( V_112 & V_115 ||
V_112 & V_116 ) {
F_14 ( V_2 -> V_7 , L_21 ) ;
if ( V_2 -> V_117 )
F_97 ( V_2 -> V_117 ) ;
}
if ( V_112 != V_113 ) {
F_98 ( V_2 ) ;
F_99 ( V_2 ) ;
}
return V_118 ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_109 ;
if ( V_2 -> V_119 -> V_120 ) {
if ( F_101 ( V_2 -> V_119 -> V_120 ) )
F_102 ( L_22 ) ;
}
V_109 = F_80 ( V_2 , V_2 -> V_121 . V_122 ,
V_2 -> V_121 . V_123 ) ;
if ( V_109 ) {
F_16 ( V_2 -> V_7 , L_23 ) ;
return;
}
F_90 ( V_2 , 1 ) ;
F_27 ( V_2 , 1 ) ;
F_32 ( V_2 , 1 ) ;
F_103 ( V_2 ) ;
V_109 = F_81 ( V_2 ) ;
if ( V_109 )
F_16 ( V_2 -> V_7 , L_24 ) ;
if ( V_2 -> V_119 -> V_120 ) {
if ( F_104 ( V_2 -> V_119 -> V_120 ) )
F_102 ( L_25 ) ;
}
F_105 ( V_2 ) ;
V_2 -> V_10 = F_22 ( V_2 ) ;
if ( V_2 -> V_10 )
F_24 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
bool V_124 , bool V_125 )
{
int V_109 = 0 ;
if ( ! V_2 -> V_119 -> V_120 )
return 0 ;
F_107 ( & V_2 -> V_126 ) ;
if ( V_2 -> V_127 && ! V_125 )
goto V_128;
if ( V_124 )
V_109 = F_108 ( V_2 -> V_119 -> V_120 ) ;
else
V_109 = F_109 ( V_2 -> V_119 -> V_120 ) ;
if ( V_109 )
goto V_128;
if ( V_125 )
V_2 -> V_127 = V_124 ;
V_128:
F_110 ( & V_2 -> V_126 ) ;
return V_109 ;
}
static int F_111 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_112 ( V_130 ) ;
struct V_131 * V_131 ;
int V_109 , V_132 = 0 ;
if ( V_2 -> V_119 -> V_120 ) {
V_132 += F_113 ( V_2 -> V_119 -> V_120 ) ;
} else {
V_109 = F_106 ( V_2 , true , false ) ;
if ( V_109 ) {
F_102 ( L_26 , V_109 ) ;
return 0 ;
}
V_131 = F_114 ( V_130 , & V_2 -> V_23 . V_133 ) ;
if ( V_131 ) {
F_115 ( & V_2 -> V_130 ,
V_131 ) ;
V_132 += F_116 ( & V_2 -> V_130 , V_131 ) ;
F_117 ( V_131 ) ;
}
V_109 = F_106 ( V_2 , false , false ) ;
if ( V_109 )
F_102 ( L_27 , V_109 ) ;
}
if ( V_2 -> V_119 -> V_134 )
V_132 += V_2 -> V_119 -> V_134 ( V_2 -> V_119 , V_130 ) ;
return V_132 ;
}
static struct V_135 *
F_118 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_112 ( V_130 ) ;
return V_2 -> V_136 ;
}
static enum V_137
F_119 ( struct V_129 * V_130 , bool V_138 )
{
struct V_1 * V_2 = F_112 ( V_130 ) ;
enum V_137 V_139 = V_140 ;
int V_109 ;
if ( V_2 -> V_119 -> V_120 )
return V_141 ;
V_109 = F_106 ( V_2 , true , false ) ;
if ( V_109 ) {
F_102 ( L_26 , V_109 ) ;
return V_140 ;
}
if ( ! F_11 ( V_2 ) )
V_139 = V_141 ;
V_109 = F_106 ( V_2 , false , false ) ;
if ( V_109 )
F_102 ( L_27 , V_109 ) ;
return V_139 ;
}
static int F_120 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = V_143 -> V_144 ;
struct V_135 * V_136 = V_2 -> V_136 ;
struct V_129 * V_130 = & V_2 -> V_130 ;
int V_109 ;
if ( ! V_143 -> V_136 ) {
F_102 ( L_28 ) ;
return - V_145 ;
}
V_130 -> V_146 = V_147 ;
V_109 = F_121 ( V_2 -> V_117 , V_130 ,
& V_148 ,
V_149 ) ;
if ( V_109 ) {
F_102 ( L_29 ) ;
return V_109 ;
}
F_122 ( V_130 ,
& V_150 ) ;
F_123 ( V_130 , V_136 ) ;
if ( V_2 -> V_119 -> V_151 ) {
V_109 = V_2 -> V_119 -> V_151 ( V_2 -> V_119 , V_143 , V_130 ) ;
if ( V_109 ) {
F_102 ( L_30 ) ;
return V_109 ;
}
}
if ( V_2 -> V_119 -> V_120 ) {
V_109 = F_124 ( V_2 -> V_119 -> V_120 , & V_2 -> V_130 ) ;
if ( V_109 ) {
F_102 ( L_31 ) ;
return V_109 ;
}
}
return 0 ;
}
static void F_125 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = V_143 -> V_144 ;
int V_109 ;
V_109 = F_106 ( V_2 , true , true ) ;
if ( V_109 )
F_102 ( L_32 , V_109 ) ;
}
static void F_126 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = V_143 -> V_144 ;
if ( V_2 -> V_152 == V_153 )
return;
F_127 ( V_2 -> V_7 ) ;
if ( V_2 -> V_119 -> V_154 )
V_2 -> V_119 -> V_154 ( V_2 -> V_119 ) ;
F_128 ( V_2 -> V_155 ) ;
F_1 ( V_2 ) ;
F_129 ( V_2 -> V_107 ) ;
F_100 ( V_2 ) ;
V_2 -> V_152 = V_153 ;
}
static void F_130 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = V_143 -> V_144 ;
int V_109 ;
if ( V_2 -> V_152 != V_153 )
return;
if ( V_2 -> V_119 -> V_120 ) {
if ( F_101 ( V_2 -> V_119 -> V_120 ) ) {
F_102 ( L_22 ) ;
return;
}
}
F_131 ( V_2 -> V_107 ) ;
F_132 ( V_2 -> V_155 ) ;
if ( V_2 -> V_119 -> V_156 )
V_2 -> V_119 -> V_156 ( V_2 -> V_119 ) ;
F_133 ( V_2 -> V_7 ) ;
V_109 = F_106 ( V_2 , false , true ) ;
if ( V_109 )
F_102 ( L_32 , V_109 ) ;
V_2 -> V_152 = V_157 ;
}
static void F_134 ( struct V_142 * V_143 ,
struct V_158 * V_159 ,
struct V_158 * V_160 )
{
struct V_1 * V_2 = V_143 -> V_144 ;
struct V_161 * V_162 = & V_2 -> V_130 . V_162 ;
struct V_121 * V_163 = & V_2 -> V_121 ;
struct V_164 * V_165 = V_2 -> V_7 -> V_166 ;
int V_167 ;
V_163 -> V_168 = ! ! ( V_160 -> V_169 & V_170 ) ;
V_163 -> V_171 = ! ! ( V_160 -> V_169 & V_172 ) ;
V_163 -> V_173 = ! ! ( V_160 -> V_169 & V_174 ) ;
V_167 = F_135 ( V_160 ) ;
if ( ( V_167 == 6 ) || ( V_167 == 7 ) || ( V_167 == 21 ) || ( V_167 == 22 ) ||
( V_167 == 2 ) || ( V_167 == 3 ) || ( V_167 == 17 ) || ( V_167 == 18 ) ) {
V_163 -> V_175 = V_176 ;
V_163 -> V_177 = V_178 ;
} else if ( V_167 ) {
V_163 -> V_175 = V_176 ;
V_163 -> V_177 = V_179 ;
} else {
V_163 -> V_175 = V_180 ;
V_163 -> V_177 = V_179 ;
}
switch ( V_162 -> V_181 ) {
case 12 :
V_163 -> V_182 = V_183 ;
break;
case 10 :
V_163 -> V_182 = V_184 ;
break;
case 8 :
V_163 -> V_182 = V_185 ;
break;
case 6 :
V_163 -> V_182 = V_186 ;
break;
default:
V_163 -> V_182 = V_185 ;
break;
}
if ( V_162 -> V_187 & V_188 )
V_163 -> V_189 = V_190 ;
else if ( V_162 -> V_187 & V_191 )
V_163 -> V_189 = V_192 ;
else if ( V_162 -> V_187 & V_193 )
V_163 -> V_189 = V_194 ;
else
V_163 -> V_189 = V_194 ;
F_136 ( V_165 , L_33 ,
& V_163 -> V_189 ) ;
F_136 ( V_165 , L_34 ,
& V_163 -> V_175 ) ;
F_136 ( V_165 , L_35 ,
& V_163 -> V_177 ) ;
F_136 ( V_165 , L_36 ,
& V_163 -> V_182 ) ;
if ( F_137 ( V_165 , L_37 ) )
V_163 -> V_173 = true ;
if ( F_137 ( V_165 , L_38 ) )
V_163 -> V_171 = true ;
if ( F_137 ( V_165 , L_39 ) )
V_163 -> V_168 = true ;
}
static void F_138 ( struct V_142 * V_143 )
{
}
static int F_139 ( struct V_195 * V_117 ,
struct V_1 * V_2 )
{
struct V_142 * V_143 ;
int V_109 ;
V_143 = F_140 ( V_117 -> V_7 , sizeof( * V_143 ) , V_196 ) ;
if ( ! V_143 ) {
F_102 ( L_40 ) ;
return - V_197 ;
}
V_2 -> V_143 = V_143 ;
V_2 -> V_136 -> V_143 = V_143 ;
V_143 -> V_144 = V_2 ;
V_143 -> V_136 = V_2 -> V_136 ;
V_143 -> V_198 = & V_199 ;
V_109 = F_141 ( V_117 , V_143 ) ;
if ( V_109 ) {
F_102 ( L_41 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = V_2 -> V_7 -> V_166 ;
struct V_121 * V_121 = & V_2 -> V_121 ;
switch ( V_2 -> V_119 -> V_200 ) {
case V_201 :
case V_202 :
V_121 -> V_123 = 0x0A ;
V_121 -> V_122 = 0x04 ;
break;
case V_203 :
F_136 ( V_165 , L_42 ,
& V_121 -> V_123 ) ;
F_136 ( V_165 , L_43 ,
& V_121 -> V_122 ) ;
break;
}
return 0 ;
}
static T_4 F_143 ( struct V_204 * V_23 ,
struct V_205 * V_206 )
{
struct V_1 * V_2 = F_112 ( V_23 ) ;
return F_144 ( V_2 , V_206 ) ;
}
int F_145 ( struct V_9 * V_7 , struct V_195 * V_117 ,
struct V_207 * V_119 )
{
struct V_208 * V_209 = F_146 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_210 * V_211 ;
unsigned int V_212 ;
int V_109 ;
if ( ! V_119 ) {
F_16 ( V_7 , L_44 ) ;
return - V_8 ;
}
V_2 = F_140 ( V_7 , sizeof( struct V_1 ) , V_196 ) ;
if ( ! V_2 )
return - V_197 ;
F_147 ( V_7 , V_2 ) ;
V_2 -> V_7 = & V_209 -> V_7 ;
V_2 -> V_152 = V_157 ;
F_148 ( & V_2 -> V_126 ) ;
V_2 -> V_127 = false ;
V_2 -> V_119 = V_119 ;
V_109 = F_142 ( V_2 ) ;
if ( V_109 )
return V_109 ;
V_2 -> V_155 = F_149 ( V_2 -> V_7 , L_45 ) ;
if ( F_150 ( V_2 -> V_155 ) ) {
F_16 ( V_2 -> V_7 , L_46 ) ;
V_109 = F_151 ( V_2 -> V_155 ) ;
if ( V_109 ) {
if ( V_109 == - V_213 || V_109 == - V_145 )
V_2 -> V_155 = NULL ;
else
return V_109 ;
}
}
V_2 -> clock = F_152 ( & V_209 -> V_7 , L_45 ) ;
if ( F_150 ( V_2 -> clock ) ) {
F_16 ( & V_209 -> V_7 , L_47 ) ;
return F_151 ( V_2 -> clock ) ;
}
F_153 ( V_2 -> clock ) ;
V_211 = F_154 ( V_209 , V_214 , 0 ) ;
V_2 -> V_215 = F_155 ( & V_209 -> V_7 , V_211 ) ;
if ( F_150 ( V_2 -> V_215 ) )
return F_151 ( V_2 -> V_215 ) ;
V_2 -> V_5 = F_137 ( V_7 -> V_166 , L_48 ) ;
V_2 -> V_216 = F_156 ( V_7 -> V_166 , L_49 , 0 ) ;
if ( ! F_157 ( V_2 -> V_216 ) )
V_2 -> V_216 = F_156 ( V_7 -> V_166 ,
L_50 , 0 ) ;
if ( F_157 ( V_2 -> V_216 ) ) {
V_109 = F_158 ( & V_209 -> V_7 , V_2 -> V_216 , V_217 ,
L_51 ) ;
if ( V_109 ) {
F_16 ( & V_209 -> V_7 , L_52 ) ;
return V_109 ;
}
V_2 -> V_107 = F_159 ( V_2 -> V_216 ) ;
V_212 = V_218 | V_219 ;
} else {
V_2 -> V_216 = - V_145 ;
V_2 -> V_107 = F_160 ( V_209 , 0 ) ;
V_212 = 0 ;
}
if ( V_2 -> V_107 == - V_220 ) {
F_16 ( & V_209 -> V_7 , L_53 ) ;
return - V_145 ;
}
F_161 ( V_7 ) ;
F_128 ( V_2 -> V_155 ) ;
F_1 ( V_2 ) ;
V_109 = F_162 ( & V_209 -> V_7 , V_2 -> V_107 ,
F_93 ,
F_96 ,
V_212 , L_54 , V_2 ) ;
if ( V_109 ) {
F_16 ( & V_209 -> V_7 , L_55 ) ;
goto V_221;
}
F_131 ( V_2 -> V_107 ) ;
V_2 -> V_117 = V_117 ;
V_2 -> V_136 = V_2 -> V_119 -> V_136 ;
V_2 -> V_23 . V_222 = L_56 ;
V_2 -> V_23 . V_223 = F_143 ;
V_2 -> V_23 . V_7 = & V_209 -> V_7 ;
V_109 = F_163 ( & V_2 -> V_23 ) ;
if ( V_109 )
goto V_221;
V_109 = F_139 ( V_117 , V_2 ) ;
if ( V_109 ) {
F_102 ( L_57 , V_109 ) ;
F_164 ( V_2 -> V_136 ) ;
goto V_221;
}
return 0 ;
V_221:
F_165 ( V_7 ) ;
return V_109 ;
}
void F_166 ( struct V_9 * V_7 , struct V_9 * V_224 ,
void * V_32 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
F_130 ( V_2 -> V_143 ) ;
if ( V_2 -> V_119 -> V_120 ) {
if ( F_109 ( V_2 -> V_119 -> V_120 ) )
F_102 ( L_58 ) ;
}
F_165 ( V_7 ) ;
}
int F_167 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
F_168 ( V_2 -> clock ) ;
if ( V_2 -> V_119 -> V_120 ) {
if ( F_109 ( V_2 -> V_119 -> V_120 ) )
F_102 ( L_58 ) ;
}
return 0 ;
}
int F_169 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
int V_109 ;
V_109 = F_153 ( V_2 -> clock ) ;
if ( V_109 < 0 ) {
F_102 ( L_59 , V_109 ) ;
return V_109 ;
}
if ( V_2 -> V_119 -> V_120 ) {
if ( F_108 ( V_2 -> V_119 -> V_120 ) ) {
F_102 ( L_60 ) ;
return - V_225 ;
}
}
return 0 ;
}
