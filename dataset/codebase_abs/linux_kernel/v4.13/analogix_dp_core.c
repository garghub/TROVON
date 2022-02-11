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
return 0 ;
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
int V_22 ;
if ( ! V_2 -> V_10 )
return 0 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 . V_14 = 0 ;
V_12 . V_13 . V_15 = 0x7 ;
V_12 . V_13 . V_16 = 0x2 ;
V_12 . V_13 . V_17 = 0x8 ;
V_12 . V_18 = 0 ;
V_12 . V_19 = 0 ;
V_22 = F_22 ( & V_2 -> V_23 , V_24 , V_25 ) ;
if ( V_22 != 1 )
F_16 ( V_2 -> V_7 , L_4 , V_22 ) ;
F_20 ( V_2 , & V_12 ) ;
return 0 ;
}
static bool F_23 ( struct V_1 * V_2 )
{
unsigned char V_26 ;
F_24 ( & V_2 -> V_23 , V_27 , & V_26 ) ;
F_14 ( V_2 -> V_7 , L_5 , V_26 ) ;
return ( V_26 & V_28 ) ? true : false ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char V_29 ;
F_24 ( & V_2 -> V_23 , V_30 , & V_29 ) ;
V_29 &= ~ V_31 ;
F_22 ( & V_2 -> V_23 , V_30 , V_29 ) ;
V_29 = V_32 | V_33 ;
F_22 ( & V_2 -> V_23 , V_30 , V_29 ) ;
V_29 = V_31 | V_32 |
V_33 ;
F_22 ( & V_2 -> V_23 , V_30 , V_29 ) ;
F_26 ( V_2 ) ;
}
static void
F_27 ( struct V_1 * V_2 ,
bool V_34 )
{
T_1 V_35 ;
F_24 ( & V_2 -> V_23 , V_36 , & V_35 ) ;
if ( V_34 )
F_22 ( & V_2 -> V_23 , V_36 ,
V_37 |
F_28 ( V_35 ) ) ;
else
F_22 ( & V_2 -> V_23 , V_36 ,
F_28 ( V_35 ) ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_35 ;
int V_38 ;
F_24 ( & V_2 -> V_23 , V_39 , & V_35 ) ;
V_38 = F_30 ( V_35 ) ;
return V_38 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_35 ;
V_35 = F_29 ( V_2 ) ;
F_27 ( V_2 , V_35 ) ;
F_32 ( V_2 , V_35 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 , V_40 ) ;
F_22 ( & V_2 -> V_23 , V_41 ,
V_42 ) ;
}
static void
F_35 ( struct V_1 * V_2 ,
int V_43 , int V_44 )
{
switch ( V_44 ) {
case 0 :
F_36 ( V_2 , V_43 ) ;
break;
case 1 :
F_37 ( V_2 , V_43 ) ;
break;
case 2 :
F_38 ( V_2 , V_43 ) ;
break;
case 3 :
F_39 ( V_2 , V_43 ) ;
break;
}
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_45 [ 4 ] ;
int V_44 , V_46 , V_47 , V_38 ;
V_46 = V_2 -> V_48 . V_46 ;
V_2 -> V_48 . V_49 = V_50 ;
V_2 -> V_48 . V_51 = 0 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
V_2 -> V_48 . V_52 [ V_44 ] = 0 ;
F_41 ( V_2 , V_2 -> V_48 . V_53 ) ;
F_42 ( V_2 , V_2 -> V_48 . V_46 ) ;
V_45 [ 0 ] = V_2 -> V_48 . V_53 ;
V_45 [ 1 ] = V_2 -> V_48 . V_46 ;
V_38 = F_43 ( & V_2 -> V_23 , V_54 , V_45 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
F_35 ( V_2 ,
V_55 , V_44 ) ;
V_47 = 0 ;
while ( F_44 ( V_2 ) == V_56 ) {
if ( V_47 == V_4 ) {
F_16 ( V_2 -> V_7 , L_6 ) ;
return - V_6 ;
}
V_47 ++ ;
F_13 ( 90 , 120 ) ;
}
F_34 ( V_2 , V_57 ) ;
V_38 = F_22 ( & V_2 -> V_23 , V_41 ,
V_58 |
V_59 ) ;
if ( V_38 < 0 )
return V_38 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
V_45 [ V_44 ] = V_60 |
V_61 ;
V_38 = F_43 ( & V_2 -> V_23 , V_62 , V_45 ,
V_46 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static unsigned char F_45 ( T_1 V_63 [ 2 ] , int V_44 )
{
int V_64 = ( V_44 & 1 ) * 4 ;
T_1 V_65 = V_63 [ V_44 >> 1 ] ;
return ( V_65 >> V_64 ) & 0xf ;
}
static int F_46 ( T_1 V_63 [ 2 ] , int V_46 )
{
int V_44 ;
T_1 V_66 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
V_66 = F_45 ( V_63 , V_44 ) ;
if ( ( V_66 & V_67 ) == 0 )
return - V_8 ;
}
return 0 ;
}
static int F_47 ( T_1 V_63 [ 2 ] , T_1 V_68 ,
int V_46 )
{
int V_44 ;
T_1 V_66 ;
if ( ( V_68 & V_69 ) == 0 )
return - V_8 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
V_66 = F_45 ( V_63 , V_44 ) ;
V_66 &= V_70 ;
if ( V_66 != V_70 )
return - V_8 ;
}
return 0 ;
}
static unsigned char
F_48 ( T_1 V_71 [ 2 ] , int V_44 )
{
int V_64 = ( V_44 & 1 ) * 4 ;
T_1 V_65 = V_71 [ V_44 >> 1 ] ;
return ( V_65 >> V_64 ) & 0x3 ;
}
static unsigned char F_49 (
T_1 V_71 [ 2 ] ,
int V_44 )
{
int V_64 = ( V_44 & 1 ) * 4 ;
T_1 V_65 = V_71 [ V_44 >> 1 ] ;
return ( ( V_65 >> V_64 ) & 0xc ) >> 2 ;
}
static void F_50 ( struct V_1 * V_2 ,
T_1 V_72 , int V_44 )
{
switch ( V_44 ) {
case 0 :
F_51 ( V_2 , V_72 ) ;
break;
case 1 :
F_52 ( V_2 , V_72 ) ;
break;
case 2 :
F_53 ( V_2 , V_72 ) ;
break;
case 3 :
F_54 ( V_2 , V_72 ) ;
break;
}
}
static unsigned int
F_55 ( struct V_1 * V_2 ,
int V_44 )
{
T_2 V_73 ;
switch ( V_44 ) {
case 0 :
V_73 = F_56 ( V_2 ) ;
break;
case 1 :
V_73 = F_57 ( V_2 ) ;
break;
case 2 :
V_73 = F_58 ( V_2 ) ;
break;
case 3 :
V_73 = F_59 ( V_2 ) ;
break;
default:
F_60 ( 1 ) ;
return 0 ;
}
return V_73 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
V_2 -> V_48 . V_49 = V_74 ;
}
static void F_62 ( struct V_1 * V_2 ,
T_1 V_71 [ 2 ] )
{
int V_44 , V_46 ;
T_1 V_75 , V_43 , V_76 ;
V_46 = V_2 -> V_48 . V_46 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
V_75 = F_48 (
V_71 , V_44 ) ;
V_43 = F_49 (
V_71 , V_44 ) ;
V_76 = F_63 ( V_75 ) |
F_64 ( V_43 ) ;
if ( V_75 == V_77 )
V_76 |= V_78 ;
if ( V_43 == V_79 )
V_76 |= V_80 ;
V_2 -> V_48 . V_76 [ V_44 ] = V_76 ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
int V_44 , V_46 , V_38 ;
T_1 V_75 , V_43 , V_76 ;
T_1 V_63 [ 2 ] , V_71 [ 2 ] ;
F_13 ( 100 , 101 ) ;
V_46 = V_2 -> V_48 . V_46 ;
V_38 = F_66 ( & V_2 -> V_23 , V_81 , V_63 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_66 ( & V_2 -> V_23 , V_82 ,
V_71 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_46 ( V_63 , V_46 ) == 0 ) {
F_34 ( V_2 , V_83 ) ;
V_38 = F_22 ( & V_2 -> V_23 , V_41 ,
V_58 |
V_84 ) ;
if ( V_38 < 0 )
return V_38 ;
F_67 ( V_2 -> V_7 , L_7 ) ;
V_2 -> V_48 . V_49 = V_85 ;
} else {
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
V_76 = F_55 (
V_2 , V_44 ) ;
V_75 = F_48 (
V_71 , V_44 ) ;
V_43 = F_49 (
V_71 , V_44 ) ;
if ( F_68 ( V_76 ) ==
V_75 &&
F_69 ( V_76 ) ==
V_43 )
V_2 -> V_48 . V_52 [ V_44 ] ++ ;
if ( V_2 -> V_48 . V_52 [ V_44 ] == V_86 ||
V_75 == V_77 ||
V_43 == V_79 ) {
F_16 ( V_2 -> V_7 , L_8 ,
V_2 -> V_48 . V_52 [ V_44 ] ,
V_75 , V_43 ) ;
F_61 ( V_2 ) ;
return - V_87 ;
}
}
}
F_62 ( V_2 , V_71 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
F_50 ( V_2 ,
V_2 -> V_48 . V_76 [ V_44 ] , V_44 ) ;
V_38 = F_43 ( & V_2 -> V_23 , V_62 ,
V_2 -> V_48 . V_76 , V_46 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_44 , V_46 , V_38 ;
T_2 V_73 ;
T_1 V_68 , V_63 [ 2 ] , V_71 [ 2 ] ;
F_13 ( 400 , 401 ) ;
V_46 = V_2 -> V_48 . V_46 ;
V_38 = F_66 ( & V_2 -> V_23 , V_81 , V_63 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_46 ( V_63 , V_46 ) ) {
F_61 ( V_2 ) ;
return - V_87 ;
}
V_38 = F_66 ( & V_2 -> V_23 , V_82 ,
V_71 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_24 ( & V_2 -> V_23 , V_88 ,
& V_68 ) ;
if ( V_38 < 0 )
return V_38 ;
F_62 ( V_2 , V_71 ) ;
if ( ! F_47 ( V_63 , V_68 , V_46 ) ) {
F_33 ( V_2 ) ;
F_67 ( V_2 -> V_7 , L_9 ) ;
F_71 ( V_2 , & V_73 ) ;
V_2 -> V_48 . V_53 = V_73 ;
F_14 ( V_2 -> V_7 , L_10 ,
V_2 -> V_48 . V_53 ) ;
F_72 ( V_2 , & V_73 ) ;
V_2 -> V_48 . V_46 = V_73 ;
F_14 ( V_2 -> V_7 , L_11 ,
V_2 -> V_48 . V_46 ) ;
F_31 ( V_2 ) ;
V_2 -> V_48 . V_49 = V_89 ;
return 0 ;
}
V_2 -> V_48 . V_51 ++ ;
if ( V_2 -> V_48 . V_51 > V_90 ) {
F_16 ( V_2 -> V_7 , L_12 ) ;
F_61 ( V_2 ) ;
return - V_87 ;
}
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ )
F_50 ( V_2 ,
V_2 -> V_48 . V_76 [ V_44 ] , V_44 ) ;
V_38 = F_43 ( & V_2 -> V_23 , V_62 ,
V_2 -> V_48 . V_76 , V_46 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
T_1 * V_91 )
{
T_1 V_35 ;
F_24 ( & V_2 -> V_23 , V_92 , & V_35 ) ;
* V_91 = V_35 ;
}
static void F_74 ( struct V_1 * V_2 ,
T_1 * V_46 )
{
T_1 V_35 ;
F_24 ( & V_2 -> V_23 , V_39 , & V_35 ) ;
* V_46 = F_75 ( V_35 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
enum V_93 V_94 ,
int V_95 )
{
F_77 ( V_2 ) ;
F_73 ( V_2 , & V_2 -> V_48 . V_53 ) ;
F_74 ( V_2 , & V_2 -> V_48 . V_46 ) ;
if ( ( V_2 -> V_48 . V_53 != V_96 ) &&
( V_2 -> V_48 . V_53 != V_97 ) &&
( V_2 -> V_48 . V_53 != V_98 ) ) {
F_16 ( V_2 -> V_7 , L_13 ,
V_2 -> V_48 . V_53 ) ;
V_2 -> V_48 . V_53 = V_96 ;
}
if ( V_2 -> V_48 . V_46 == 0 ) {
F_16 ( V_2 -> V_7 , L_14 ,
V_2 -> V_48 . V_46 ) ;
V_2 -> V_48 . V_46 = ( T_1 ) V_99 ;
}
if ( V_2 -> V_48 . V_46 > V_94 )
V_2 -> V_48 . V_46 = V_94 ;
if ( V_2 -> V_48 . V_53 > V_95 )
V_2 -> V_48 . V_53 = V_95 ;
F_78 ( V_2 , V_100 , 0 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_38 = 0 , V_101 = 0 ;
V_2 -> V_48 . V_49 = V_102 ;
while ( ! V_38 && ! V_101 ) {
switch ( V_2 -> V_48 . V_49 ) {
case V_102 :
V_38 = F_40 ( V_2 ) ;
if ( V_38 )
F_16 ( V_2 -> V_7 , L_15 ) ;
break;
case V_50 :
V_38 = F_65 ( V_2 ) ;
if ( V_38 )
F_16 ( V_2 -> V_7 , L_16 ) ;
break;
case V_85 :
V_38 = F_70 ( V_2 ) ;
if ( V_38 )
F_16 ( V_2 -> V_7 , L_17 ) ;
break;
case V_89 :
V_101 = 1 ;
break;
case V_74 :
return - V_103 ;
}
}
if ( V_38 )
F_16 ( V_2 -> V_7 , L_18 , V_38 ) ;
return V_38 ;
}
static int F_80 ( struct V_1 * V_2 ,
T_2 V_104 , T_2 V_105 )
{
int V_106 ;
int V_38 ;
for ( V_106 = 0 ; V_106 < V_4 ; V_106 ++ ) {
F_76 ( V_2 , V_104 , V_105 ) ;
V_38 = F_79 ( V_2 ) ;
if ( V_38 == 0 )
break;
F_13 ( 100 , 110 ) ;
}
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
int V_3 = 0 ;
int V_107 = 0 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( F_44 ( V_2 ) == V_56 ) {
F_16 ( V_2 -> V_7 , L_19 ) ;
return - V_8 ;
}
for (; ; ) {
V_3 ++ ;
if ( F_84 ( V_2 ) == 0 )
break;
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_20 ) ;
return - V_6 ;
}
F_13 ( 1 , 2 ) ;
}
F_85 ( V_2 , V_108 , 0 , 0 ) ;
F_86 ( V_2 , V_109 ) ;
F_87 ( V_2 , 0 ) ;
F_88 ( V_2 , 0 ) ;
V_3 = 0 ;
for (; ; ) {
V_3 ++ ;
if ( F_89 ( V_2 ) == 0 ) {
V_107 ++ ;
if ( V_107 > 10 )
break;
} else if ( V_107 ) {
V_107 = 0 ;
}
if ( V_3 > V_4 ) {
F_16 ( V_2 -> V_7 , L_20 ) ;
return - V_6 ;
}
F_13 ( 1000 , 1001 ) ;
}
if ( V_38 != 0 )
F_16 ( V_2 -> V_7 , L_21 ) ;
return V_38 ;
}
static void F_90 ( struct V_1 * V_2 ,
bool V_34 )
{
T_1 V_35 ;
if ( V_34 ) {
F_91 ( V_2 ) ;
F_24 ( & V_2 -> V_23 , V_41 , & V_35 ) ;
F_22 ( & V_2 -> V_23 , V_41 ,
( T_1 ) ( V_35 & ~ V_58 ) ) ;
} else {
F_92 ( V_2 ) ;
F_24 ( & V_2 -> V_23 , V_41 , & V_35 ) ;
F_22 ( & V_2 -> V_23 , V_41 ,
( T_1 ) ( V_35 | V_58 ) ) ;
}
}
static T_3 F_93 ( int V_110 , void * V_111 )
{
struct V_1 * V_2 = V_111 ;
T_3 V_22 = V_112 ;
enum V_113 V_114 ;
V_114 = F_94 ( V_2 ) ;
if ( V_114 != V_115 ) {
F_95 ( V_2 ) ;
V_22 = V_116 ;
}
return V_22 ;
}
static T_3 F_96 ( int V_110 , void * V_111 )
{
struct V_1 * V_2 = V_111 ;
enum V_113 V_114 ;
V_114 = F_94 ( V_2 ) ;
if ( V_114 & V_117 ||
V_114 & V_118 ) {
F_14 ( V_2 -> V_7 , L_22 ) ;
if ( V_2 -> V_119 )
F_97 ( V_2 -> V_119 ) ;
}
if ( V_114 != V_115 ) {
F_98 ( V_2 ) ;
F_99 ( V_2 ) ;
}
return V_120 ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_22 ;
if ( V_2 -> V_121 -> V_122 ) {
if ( F_101 ( V_2 -> V_121 -> V_122 ) )
F_102 ( L_23 ) ;
}
V_22 = F_80 ( V_2 , V_2 -> V_123 . V_124 ,
V_2 -> V_123 . V_125 ) ;
if ( V_22 ) {
F_16 ( V_2 -> V_7 , L_24 ) ;
return;
}
F_90 ( V_2 , 1 ) ;
F_27 ( V_2 , 1 ) ;
F_32 ( V_2 , 1 ) ;
F_103 ( V_2 ) ;
V_22 = F_81 ( V_2 ) ;
if ( V_22 )
F_16 ( V_2 -> V_7 , L_25 ) ;
if ( V_2 -> V_121 -> V_122 ) {
if ( F_104 ( V_2 -> V_121 -> V_122 ) )
F_102 ( L_26 ) ;
}
F_105 ( V_2 ) ;
V_2 -> V_10 = F_23 ( V_2 ) ;
if ( V_2 -> V_10 )
F_25 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
bool V_126 , bool V_127 )
{
int V_22 = 0 ;
if ( ! V_2 -> V_121 -> V_122 )
return 0 ;
F_107 ( & V_2 -> V_128 ) ;
if ( V_2 -> V_129 && ! V_127 )
goto V_130;
if ( V_126 )
V_22 = F_108 ( V_2 -> V_121 -> V_122 ) ;
else
V_22 = F_109 ( V_2 -> V_121 -> V_122 ) ;
if ( V_22 )
goto V_130;
if ( V_127 )
V_2 -> V_129 = V_126 ;
V_130:
F_110 ( & V_2 -> V_128 ) ;
return V_22 ;
}
static int F_111 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_112 ( V_132 ) ;
struct V_133 * V_133 ;
int V_22 , V_134 = 0 ;
if ( V_2 -> V_121 -> V_122 ) {
V_134 += F_113 ( V_2 -> V_121 -> V_122 ) ;
} else {
V_22 = F_106 ( V_2 , true , false ) ;
if ( V_22 ) {
F_102 ( L_27 , V_22 ) ;
return 0 ;
}
V_133 = F_114 ( V_132 , & V_2 -> V_23 . V_135 ) ;
if ( V_133 ) {
F_115 ( & V_2 -> V_132 ,
V_133 ) ;
V_134 += F_116 ( & V_2 -> V_132 , V_133 ) ;
F_117 ( V_133 ) ;
}
V_22 = F_106 ( V_2 , false , false ) ;
if ( V_22 )
F_102 ( L_28 , V_22 ) ;
}
if ( V_2 -> V_121 -> V_136 )
V_134 += V_2 -> V_121 -> V_136 ( V_2 -> V_121 , V_132 ) ;
return V_134 ;
}
static struct V_137 *
F_118 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_112 ( V_132 ) ;
return V_2 -> V_138 ;
}
static enum V_139
F_119 ( struct V_131 * V_132 , bool V_140 )
{
struct V_1 * V_2 = F_112 ( V_132 ) ;
enum V_139 V_141 = V_142 ;
int V_22 ;
if ( V_2 -> V_121 -> V_122 )
return V_143 ;
V_22 = F_106 ( V_2 , true , false ) ;
if ( V_22 ) {
F_102 ( L_27 , V_22 ) ;
return V_142 ;
}
if ( ! F_11 ( V_2 ) )
V_141 = V_143 ;
V_22 = F_106 ( V_2 , false , false ) ;
if ( V_22 )
F_102 ( L_28 , V_22 ) ;
return V_141 ;
}
static int F_120 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_137 * V_138 = V_2 -> V_138 ;
struct V_131 * V_132 = & V_2 -> V_132 ;
int V_22 ;
if ( ! V_145 -> V_138 ) {
F_102 ( L_29 ) ;
return - V_147 ;
}
V_132 -> V_148 = V_149 ;
V_22 = F_121 ( V_2 -> V_119 , V_132 ,
& V_150 ,
V_151 ) ;
if ( V_22 ) {
F_102 ( L_30 ) ;
return V_22 ;
}
F_122 ( V_132 ,
& V_152 ) ;
F_123 ( V_132 , V_138 ) ;
if ( V_2 -> V_121 -> V_153 ) {
V_22 = V_2 -> V_121 -> V_153 ( V_2 -> V_121 , V_145 , V_132 ) ;
if ( V_22 ) {
F_102 ( L_31 ) ;
return V_22 ;
}
}
if ( V_2 -> V_121 -> V_122 ) {
V_22 = F_124 ( V_2 -> V_121 -> V_122 , & V_2 -> V_132 ) ;
if ( V_22 ) {
F_102 ( L_32 ) ;
return V_22 ;
}
}
return 0 ;
}
static void F_125 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
int V_22 ;
V_22 = F_106 ( V_2 , true , true ) ;
if ( V_22 )
F_102 ( L_33 , V_22 ) ;
}
static void F_126 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
if ( V_2 -> V_154 == V_155 )
return;
F_127 ( V_2 -> V_7 ) ;
if ( V_2 -> V_121 -> V_156 )
V_2 -> V_121 -> V_156 ( V_2 -> V_121 ) ;
F_128 ( V_2 -> V_157 ) ;
F_1 ( V_2 ) ;
F_129 ( V_2 -> V_110 ) ;
F_100 ( V_2 ) ;
V_2 -> V_154 = V_155 ;
}
static void F_130 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
int V_22 ;
if ( V_2 -> V_154 != V_155 )
return;
if ( V_2 -> V_121 -> V_122 ) {
if ( F_101 ( V_2 -> V_121 -> V_122 ) ) {
F_102 ( L_23 ) ;
return;
}
}
F_131 ( V_2 -> V_110 ) ;
F_132 ( V_2 -> V_157 ) ;
if ( V_2 -> V_121 -> V_158 )
V_2 -> V_121 -> V_158 ( V_2 -> V_121 ) ;
F_133 ( V_2 -> V_7 ) ;
V_22 = F_106 ( V_2 , false , true ) ;
if ( V_22 )
F_102 ( L_33 , V_22 ) ;
V_2 -> V_154 = V_159 ;
}
static void F_134 ( struct V_144 * V_145 ,
struct V_160 * V_161 ,
struct V_160 * V_162 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_163 * V_164 = & V_2 -> V_132 . V_164 ;
struct V_123 * V_165 = & V_2 -> V_123 ;
struct V_166 * V_167 = V_2 -> V_7 -> V_168 ;
int V_169 ;
V_165 -> V_170 = ! ! ( V_162 -> V_171 & V_172 ) ;
V_165 -> V_173 = ! ! ( V_162 -> V_171 & V_174 ) ;
V_165 -> V_175 = ! ! ( V_162 -> V_171 & V_176 ) ;
V_169 = F_135 ( V_162 ) ;
if ( ( V_169 == 6 ) || ( V_169 == 7 ) || ( V_169 == 21 ) || ( V_169 == 22 ) ||
( V_169 == 2 ) || ( V_169 == 3 ) || ( V_169 == 17 ) || ( V_169 == 18 ) ) {
V_165 -> V_177 = V_178 ;
V_165 -> V_179 = V_180 ;
} else if ( V_169 ) {
V_165 -> V_177 = V_178 ;
V_165 -> V_179 = V_181 ;
} else {
V_165 -> V_177 = V_182 ;
V_165 -> V_179 = V_181 ;
}
switch ( V_164 -> V_183 ) {
case 12 :
V_165 -> V_184 = V_185 ;
break;
case 10 :
V_165 -> V_184 = V_186 ;
break;
case 8 :
V_165 -> V_184 = V_187 ;
break;
case 6 :
V_165 -> V_184 = V_188 ;
break;
default:
V_165 -> V_184 = V_187 ;
break;
}
if ( V_164 -> V_189 & V_190 )
V_165 -> V_191 = V_192 ;
else if ( V_164 -> V_189 & V_193 )
V_165 -> V_191 = V_194 ;
else if ( V_164 -> V_189 & V_195 )
V_165 -> V_191 = V_196 ;
else
V_165 -> V_191 = V_196 ;
F_136 ( V_167 , L_34 ,
& V_165 -> V_191 ) ;
F_136 ( V_167 , L_35 ,
& V_165 -> V_177 ) ;
F_136 ( V_167 , L_36 ,
& V_165 -> V_179 ) ;
F_136 ( V_167 , L_37 ,
& V_165 -> V_184 ) ;
if ( F_137 ( V_167 , L_38 ) )
V_165 -> V_175 = true ;
if ( F_137 ( V_167 , L_39 ) )
V_165 -> V_173 = true ;
if ( F_137 ( V_167 , L_40 ) )
V_165 -> V_170 = true ;
}
static void F_138 ( struct V_144 * V_145 )
{
}
static int F_139 ( struct V_197 * V_119 ,
struct V_1 * V_2 )
{
struct V_144 * V_145 ;
int V_22 ;
V_145 = F_140 ( V_119 -> V_7 , sizeof( * V_145 ) , V_198 ) ;
if ( ! V_145 ) {
F_102 ( L_41 ) ;
return - V_199 ;
}
V_2 -> V_145 = V_145 ;
V_145 -> V_146 = V_2 ;
V_145 -> V_200 = & V_201 ;
V_22 = F_141 ( V_2 -> V_138 , V_145 , NULL ) ;
if ( V_22 ) {
F_102 ( L_42 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_166 * V_167 = V_2 -> V_7 -> V_168 ;
struct V_123 * V_123 = & V_2 -> V_123 ;
switch ( V_2 -> V_121 -> V_202 ) {
case V_203 :
case V_204 :
V_123 -> V_125 = 0x0A ;
V_123 -> V_124 = 0x04 ;
break;
case V_205 :
F_136 ( V_167 , L_43 ,
& V_123 -> V_125 ) ;
F_136 ( V_167 , L_44 ,
& V_123 -> V_124 ) ;
break;
}
return 0 ;
}
static T_4 F_143 ( struct V_206 * V_23 ,
struct V_207 * V_208 )
{
struct V_1 * V_2 = F_112 ( V_23 ) ;
return F_144 ( V_2 , V_208 ) ;
}
int F_145 ( struct V_9 * V_7 , struct V_197 * V_119 ,
struct V_209 * V_121 )
{
struct V_210 * V_211 = F_146 ( V_7 ) ;
struct V_1 * V_2 ;
struct V_212 * V_213 ;
unsigned int V_214 ;
int V_22 ;
if ( ! V_121 ) {
F_16 ( V_7 , L_45 ) ;
return - V_8 ;
}
V_2 = F_140 ( V_7 , sizeof( struct V_1 ) , V_198 ) ;
if ( ! V_2 )
return - V_199 ;
F_147 ( V_7 , V_2 ) ;
V_2 -> V_7 = & V_211 -> V_7 ;
V_2 -> V_154 = V_159 ;
F_148 ( & V_2 -> V_128 ) ;
V_2 -> V_129 = false ;
V_2 -> V_121 = V_121 ;
V_22 = F_142 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_157 = F_149 ( V_2 -> V_7 , L_46 ) ;
if ( F_150 ( V_2 -> V_157 ) ) {
F_16 ( V_2 -> V_7 , L_47 ) ;
V_22 = F_151 ( V_2 -> V_157 ) ;
if ( V_22 ) {
if ( V_22 == - V_215 || V_22 == - V_147 )
V_2 -> V_157 = NULL ;
else
return V_22 ;
}
}
V_2 -> clock = F_152 ( & V_211 -> V_7 , L_46 ) ;
if ( F_150 ( V_2 -> clock ) ) {
F_16 ( & V_211 -> V_7 , L_48 ) ;
return F_151 ( V_2 -> clock ) ;
}
F_153 ( V_2 -> clock ) ;
V_213 = F_154 ( V_211 , V_216 , 0 ) ;
V_2 -> V_217 = F_155 ( & V_211 -> V_7 , V_213 ) ;
if ( F_150 ( V_2 -> V_217 ) )
return F_151 ( V_2 -> V_217 ) ;
V_2 -> V_5 = F_137 ( V_7 -> V_168 , L_49 ) ;
V_2 -> V_218 = F_156 ( V_7 -> V_168 , L_50 , 0 ) ;
if ( ! F_157 ( V_2 -> V_218 ) )
V_2 -> V_218 = F_156 ( V_7 -> V_168 ,
L_51 , 0 ) ;
if ( F_157 ( V_2 -> V_218 ) ) {
V_22 = F_158 ( & V_211 -> V_7 , V_2 -> V_218 , V_219 ,
L_52 ) ;
if ( V_22 ) {
F_16 ( & V_211 -> V_7 , L_53 ) ;
return V_22 ;
}
V_2 -> V_110 = F_159 ( V_2 -> V_218 ) ;
V_214 = V_220 | V_221 ;
} else {
V_2 -> V_218 = - V_147 ;
V_2 -> V_110 = F_160 ( V_211 , 0 ) ;
V_214 = 0 ;
}
if ( V_2 -> V_110 == - V_222 ) {
F_16 ( & V_211 -> V_7 , L_54 ) ;
return - V_147 ;
}
F_161 ( V_7 ) ;
F_127 ( V_7 ) ;
F_128 ( V_2 -> V_157 ) ;
F_1 ( V_2 ) ;
V_22 = F_162 ( & V_211 -> V_7 , V_2 -> V_110 ,
F_93 ,
F_96 ,
V_214 , L_55 , V_2 ) ;
if ( V_22 ) {
F_16 ( & V_211 -> V_7 , L_56 ) ;
goto V_223;
}
F_131 ( V_2 -> V_110 ) ;
V_2 -> V_119 = V_119 ;
V_2 -> V_138 = V_2 -> V_121 -> V_138 ;
V_2 -> V_23 . V_224 = L_57 ;
V_2 -> V_23 . V_225 = F_143 ;
V_2 -> V_23 . V_7 = & V_211 -> V_7 ;
V_22 = F_163 ( & V_2 -> V_23 ) ;
if ( V_22 )
goto V_223;
V_22 = F_139 ( V_119 , V_2 ) ;
if ( V_22 ) {
F_102 ( L_58 , V_22 ) ;
F_164 ( V_2 -> V_138 ) ;
goto V_223;
}
F_132 ( V_2 -> V_157 ) ;
F_165 ( V_7 ) ;
return 0 ;
V_223:
F_132 ( V_2 -> V_157 ) ;
F_165 ( V_7 ) ;
F_166 ( V_7 ) ;
return V_22 ;
}
void F_167 ( struct V_9 * V_7 , struct V_9 * V_226 ,
void * V_35 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
F_130 ( V_2 -> V_145 ) ;
V_2 -> V_132 . V_200 -> V_227 ( & V_2 -> V_132 ) ;
V_2 -> V_138 -> V_200 -> V_227 ( V_2 -> V_138 ) ;
if ( V_2 -> V_121 -> V_122 ) {
if ( F_109 ( V_2 -> V_121 -> V_122 ) )
F_102 ( L_59 ) ;
if ( F_168 ( V_2 -> V_121 -> V_122 ) )
F_102 ( L_60 ) ;
}
F_169 ( & V_2 -> V_23 ) ;
F_166 ( V_7 ) ;
F_170 ( V_2 -> clock ) ;
}
int F_171 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
F_170 ( V_2 -> clock ) ;
if ( V_2 -> V_121 -> V_122 ) {
if ( F_109 ( V_2 -> V_121 -> V_122 ) )
F_102 ( L_59 ) ;
}
return 0 ;
}
int F_172 ( struct V_9 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
int V_22 ;
V_22 = F_153 ( V_2 -> clock ) ;
if ( V_22 < 0 ) {
F_102 ( L_61 , V_22 ) ;
return V_22 ;
}
if ( V_2 -> V_121 -> V_122 ) {
if ( F_108 ( V_2 -> V_121 -> V_122 ) ) {
F_102 ( L_62 ) ;
return - V_228 ;
}
}
return 0 ;
}
int F_173 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_112 ( V_132 ) ;
if ( ! V_132 -> V_229 -> V_230 ) {
F_102 ( L_63 ,
V_132 -> V_224 ) ;
return - V_8 ;
}
return F_174 ( & V_2 -> V_23 , V_132 -> V_229 -> V_230 ) ;
}
int F_175 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_112 ( V_132 ) ;
return F_176 ( & V_2 -> V_23 ) ;
}
