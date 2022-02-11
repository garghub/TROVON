static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_16 ) ;
if ( ! V_5 )
return - V_17 ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
V_5 -> V_20 = F_3 ( V_2 -> V_21 -> V_22 . V_23 ) ;
switch ( V_5 -> V_20 ) {
case V_24 :
F_4 ( V_25 L_1 ) ;
break;
case V_26 :
F_4 ( V_25
L_2 ) ;
break;
case V_27 :
F_4 ( V_25 L_3 ) ;
break;
case V_28 :
F_4 ( V_25 L_4 ) ;
break;
}
F_5 ( V_2 -> V_29 [ 0 ] , V_5 ) ;
V_7 = V_2 -> V_21 ;
V_9 = V_7 -> V_9 ;
V_11 = V_9 -> V_11 [ 0 ] ;
V_13 = V_11 -> V_30 ;
V_15 = V_13 -> V_15 ;
for ( V_3 = 0 ; V_3 < V_13 -> V_31 . V_32 ; V_3 ++ ) {
V_15 = & V_13 -> V_15 [ V_3 ] ;
if ( F_6 ( & V_15 -> V_31 ) ) {
F_7 ( L_5 ,
V_33 , V_15 -> V_31 . V_34 ) ;
V_5 -> V_35 =
V_15 -> V_31 . V_34 ;
}
if ( F_8 ( & V_15 -> V_31 ) ) {
F_7 ( L_6 ,
V_33 , V_15 -> V_31 . V_34 ) ;
V_5 -> V_36 =
V_15 -> V_31 . V_34 ;
}
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_3 ;
F_7 ( L_7 , V_33 , V_2 -> V_29 [ 0 ] -> V_37 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_38 ; ++ V_3 )
F_10 ( F_11 ( V_2 -> V_29 [ V_3 ] ) ) ;
}
static void F_12 ( struct V_39 * V_40 )
{
V_40 -> V_41 -> V_42 = 0 ;
V_40 -> V_41 -> V_42 &= ~ ( V_43 | V_44 | V_45 | V_46 | V_47 ) ;
V_40 -> V_41 -> V_48 = V_49 | V_50 | V_51 ;
V_40 -> V_41 -> V_52 &= ~ V_53 ;
}
static int F_13 ( struct V_39 * V_40 , struct V_54 * V_29 )
{
int V_55 = 0 ;
struct V_4 * V_5 ;
unsigned char * V_56 ;
int V_57 = 8 ;
int V_58 = 8 ;
F_7 ( L_7 , V_33 , V_29 -> V_37 ) ;
V_5 = F_11 ( V_29 ) ;
V_56 = F_14 ( V_57 , V_16 ) ;
if ( ! V_56 )
return - V_17 ;
if ( ! V_29 -> V_59 ) {
F_7 ( L_8 ,
V_33 , V_29 -> V_37 ) ;
V_29 -> V_59 = F_15 ( 0 , V_16 ) ;
if ( ! V_29 -> V_59 ) {
F_7 ( L_9 ,
V_33 , V_29 -> V_37 ) ;
F_10 ( V_56 ) ;
return - V_17 ;
}
}
V_29 -> V_59 -> V_56 =
F_2 ( V_58 , V_16 ) ;
if ( ! V_29 -> V_59 -> V_56 ) {
F_10 ( V_56 ) ;
F_16 ( V_29 -> V_59 ) ;
V_29 -> V_59 = NULL ;
return - V_17 ;
}
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_60 ,
V_61 | V_62 | V_63 ,
V_64 ,
0 ,
V_56 ,
V_57 ,
V_65
) ;
F_7 ( L_10 ,
V_33 , V_29 -> V_37 , V_55 ) ;
F_7 ( L_11 ,
V_56 [ 0 ] , V_56 [ 1 ] , V_56 [ 2 ] ) ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_60 ,
V_61 | V_62 | V_63 ,
V_66 ,
0 ,
V_56 ,
V_57 ,
V_65
) ;
F_7 ( L_12 ,
V_33 , V_29 -> V_37 , V_55 ) ;
F_7 ( L_13 ,
V_56 [ 0 ] , V_56 [ 1 ] , V_56 [ 2 ] ) ;
if ( V_5 -> V_20 == V_24 ||
V_5 -> V_20 == V_26 ) {
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_67 ,
V_61 | V_62 | V_68 ,
V_69 | V_70 |
V_71 ,
0 ,
V_56 ,
0 ,
V_65
) ;
F_7 ( L_14 ,
V_33 , V_29 -> V_37 , V_55 ) ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_72 ,
V_61 | V_62 | V_68 ,
V_73 ,
0 ,
V_56 ,
0 ,
V_65
) ;
F_7 ( L_15 ,
V_33 , V_29 -> V_37 , V_55 ) ;
}
if ( V_5 -> V_20 == V_27 ||
V_5 -> V_20 == V_24 ||
V_5 -> V_20 == V_28 ) {
V_55 = F_19 ( V_29 -> V_74 , V_75 ) ;
F_7 ( L_16 ,
V_33 , V_29 -> V_37 , V_55 ) ;
}
F_10 ( V_56 ) ;
return 0 ;
}
static void F_20 ( struct V_54 * V_29 )
{
F_7 ( L_7 , V_33 , V_29 -> V_37 ) ;
if ( V_29 -> V_59 ) {
F_21 ( V_29 -> V_59 ) ;
F_10 ( V_29 -> V_59 -> V_56 ) ;
F_16 ( V_29 -> V_59 ) ;
V_29 -> V_59 = NULL ;
}
F_22 ( V_29 -> V_74 ) ;
}
static void F_23 ( struct V_76 * V_76 )
{
int V_55 ;
struct V_54 * V_29 = V_76 -> V_77 ;
struct V_39 * V_40 ;
unsigned char * V_78 = V_76 -> V_56 ;
int V_79 = V_76 -> V_79 ;
F_7 ( L_7 , V_33 , V_29 -> V_37 ) ;
if ( V_79 ) {
F_7 ( L_17 ,
V_33 , V_29 -> V_37 , V_79 ) ;
return;
}
V_40 = F_24 ( & V_29 -> V_29 ) ;
if ( V_40 && V_76 -> V_80 ) {
F_25 ( V_40 , V_78 , V_76 -> V_80 ) ;
F_26 ( V_40 ) ;
}
F_27 ( V_40 ) ;
V_55 = F_19 ( V_29 -> V_74 , V_75 ) ;
F_7 ( L_16 ,
V_33 , V_29 -> V_37 , V_55 ) ;
}
static void F_28 ( struct V_76 * V_81 )
{
}
static int F_29 ( struct V_39 * V_40 , struct V_54 * V_29 ,
const unsigned char * V_82 , int V_83 )
{
int V_84 = 0 ;
int V_55 = 0 ;
int V_85 = 0 ;
struct V_4 * V_5 ;
if ( V_83 == 0 ) {
F_7 ( L_18 ,
V_33 , V_29 -> V_37 ) ;
return 0 ;
}
V_5 = F_11 ( V_29 ) ;
if ( V_83 > ( V_86 - V_5 -> V_18 ) ) {
F_7 ( L_19 , V_33 , V_29 -> V_37 ) ;
return - V_17 ;
}
memcpy ( V_5 -> V_82 + V_5 -> V_18 , V_82 , V_83 ) ;
F_30 ( V_87 , & V_29 -> V_21 , V_33 , V_83 ,
V_5 -> V_82 + V_5 -> V_18 ) ;
V_5 -> V_18 = V_5 -> V_18 + V_83 ;
if ( ( ( V_5 -> V_20 != V_24 ) && ( V_5 -> V_18 > 2 ) && ( V_5 -> V_18 >= ( V_5 -> V_82 [ 1 ] + 3 ) ) ) ||
( ( V_5 -> V_20 == V_24 ) && ( V_5 -> V_18 > 3 ) && ( V_5 -> V_18 >= ( V_5 -> V_82 [ 2 ] + 4 ) ) ) ) {
if ( ( V_5 -> V_20 == V_24 )
|| ( V_5 -> V_20 == V_26 ) )
F_22 ( V_29 -> V_74 ) ;
V_85 = V_5 -> V_18 - V_5 -> V_19 ;
while ( V_85 > 0 ) {
V_84 = ( V_85 < 8 ) ? V_85 : 8 ;
memcpy ( V_29 -> V_59 -> V_56 ,
V_5 -> V_82 + V_5 -> V_19 , V_84 ) ;
F_31 ( V_29 -> V_59 ,
V_29 -> V_2 -> V_21 ,
F_32 ( V_29 -> V_2 -> V_21 ,
V_5 -> V_35 ) ,
V_29 -> V_59 -> V_56 ,
V_84 ,
F_28 ,
V_29 ,
8
) ;
V_5 -> V_19 = V_5 -> V_19 + V_84 ;
V_55 = F_19 ( V_29 -> V_59 , V_88 ) ;
F_7 ( L_20 ,
V_33 , V_29 -> V_37 , V_55 ) ;
V_85 = V_5 -> V_18 - V_5 -> V_19 ;
if ( V_85 > 0 )
F_33 ( 24 ) ;
}
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
if ( V_5 -> V_20 == V_24 ||
V_5 -> V_20 == V_26 ) {
V_55 = F_19 ( V_29 -> V_74 ,
V_88 ) ;
F_7 ( L_16 ,
V_33 , V_29 -> V_37 , V_55 ) ;
}
}
return V_83 ;
}
static int F_34 ( struct V_39 * V_40 )
{
return 8 ;
}
static int F_35 ( struct V_39 * V_40 )
{
struct V_54 * V_29 = V_40 -> V_89 ;
struct V_4 * V_5 ;
int V_55 ;
unsigned char * V_56 ;
int V_57 = 8 ;
V_5 = F_11 ( V_29 ) ;
if ( V_5 -> V_20 == V_27
|| V_5 -> V_20 == V_28 ) {
return - V_90 ;
}
V_56 = F_14 ( V_57 , V_16 ) ;
if ( ! V_56 )
return - V_17 ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_91 ,
V_61 | V_62 | V_63 ,
0 ,
0 ,
V_56 ,
V_57 ,
V_65 ) ;
F_7 ( L_21 ,
V_33 , V_29 -> V_37 , V_55 , V_56 [ 0 ] ) ;
V_55 = 0 ;
if ( ( V_56 [ 0 ] & V_92 ) != 0 )
V_55 = V_93 ;
F_10 ( V_56 ) ;
return V_55 ;
}
static int F_36 ( struct V_39 * V_40 ,
unsigned int V_94 , unsigned int V_95 )
{
struct V_54 * V_29 = V_40 -> V_89 ;
struct V_4 * V_5 ;
int V_55 ;
int V_96 = 0 ;
int V_97 = 0 ;
unsigned char * V_56 ;
int V_57 = 8 ;
V_5 = F_11 ( V_29 ) ;
if ( V_5 -> V_20 == V_27
|| V_5 -> V_20 == V_28 ) {
return - V_90 ;
}
V_56 = F_14 ( V_57 , V_16 ) ;
if ( ! V_56 )
return - V_17 ;
if ( V_94 & V_98 )
V_97 = 1 ;
if ( V_94 & V_99 )
V_96 = 1 ;
if ( V_95 & V_98 )
V_97 = 0 ;
if ( V_95 & V_99 )
V_96 = 0 ;
if ( V_5 -> V_20 == V_24 ) {
if ( V_96 != 0 )
F_7 ( L_22 ,
V_33 , V_29 -> V_37 ) ;
else
F_7 ( L_23 ,
V_33 , V_29 -> V_37 ) ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_100 ,
V_61 | V_62 | V_68 ,
( ( V_96 != 0 ) ? V_101 : V_102 ) ,
0 ,
V_56 ,
0 ,
V_65 ) ;
} else {
if ( V_97 != 0 )
F_7 ( L_24 ,
V_33 , V_29 -> V_37 ) ;
else
F_7 ( L_25 ,
V_33 , V_29 -> V_37 ) ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_100 ,
V_61 | V_62 | V_68 ,
( ( V_97 != 0 ) ? V_103 : V_104 ) ,
0 ,
V_56 ,
0 ,
V_65 ) ;
}
F_7 ( L_26 ,
V_33 , V_29 -> V_37 , V_55 ) ;
F_10 ( V_56 ) ;
return ( V_55 < 0 ) ? V_55 : 0 ;
}
static void F_37 ( struct V_39 * V_40 ,
struct V_54 * V_29 , struct V_105 * V_106 )
{
struct V_4 * V_5 ;
int V_55 ;
unsigned short V_107 = 0 ;
int V_108 = V_40 -> V_41 -> V_108 ;
T_1 V_109 ;
V_5 = F_11 ( V_29 ) ;
if ( V_5 -> V_20 == V_27 ||
V_5 -> V_20 == V_28 ) {
* V_40 -> V_41 = * V_106 ;
return;
}
V_109 = F_38 ( V_40 ) ;
switch ( V_109 ) {
case 1200 :
V_107 = V_110 ;
break;
default:
V_109 = 9600 ;
case 9600 :
V_107 = V_69 ;
break;
}
V_107 |= ( V_108 & V_111 ) ? V_112 :
V_71 ;
if ( V_108 & V_113 ) {
if ( V_108 & V_114 )
V_107 |= V_115 ;
else
V_107 |= V_70 ;
} else
V_107 |= V_116 ;
V_40 -> V_41 -> V_108 &= ~ V_117 ;
F_39 ( V_40 , V_109 , V_109 ) ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_67 ,
V_61 | V_62 | V_68 ,
V_107 ,
0 ,
NULL ,
0 ,
V_65
) ;
}
static int F_40 ( struct V_39 * V_40 ,
unsigned int V_118 , unsigned long V_119 )
{
struct V_54 * V_29 = V_40 -> V_89 ;
struct V_4 * V_5 = F_11 ( V_29 ) ;
unsigned char * V_56 ;
int V_57 = 8 ;
int V_55 ;
if ( V_5 -> V_20 == V_27 ||
V_5 -> V_20 == V_28 )
return - V_120 ;
switch ( V_118 ) {
case V_121 :
V_56 = F_2 ( V_57 , V_16 ) ;
if ( ! V_56 )
return - V_122 ;
V_55 = F_17 ( V_29 -> V_2 -> V_21 ,
F_18 ( V_29 -> V_2 -> V_21 , 0 ) ,
V_72 ,
V_61 | V_62 | V_68 ,
V_73 ,
0 ,
NULL ,
0 ,
V_65
) ;
F_7 ( L_27 , V_33 , V_29 -> V_37 , V_55 ) ;
F_10 ( V_56 ) ;
return ( V_55 < 0 ) ? - V_123 : 0 ;
default:
return - V_120 ;
}
}
static int T_2 F_41 ( void )
{
int V_124 ;
V_124 = F_42 ( & V_125 ) ;
if ( V_124 )
goto V_126;
V_124 = F_43 ( & V_127 ) ;
if ( V_124 )
goto V_128;
F_4 (KERN_INFO KBUILD_MODNAME L_28 DRIVER_VERSION L_29
DRIVER_DESC L_30 ) ;
return 0 ;
V_128:
F_44 ( & V_125 ) ;
V_126:
return V_124 ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_127 ) ;
F_44 ( & V_125 ) ;
}
