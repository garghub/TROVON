static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
int V_7 ;
if ( V_4 == V_6 -> V_8 || ! V_6 -> V_9 )
return;
if ( ! V_4 ) {
F_3 ( V_6 -> V_9 ) ;
} else {
V_7 = F_4 ( V_6 -> V_9 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_1 ,
V_7 ) ;
}
V_6 -> V_8 = V_4 ;
}
static enum V_3 F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
return ! ! F_7 ( V_6 -> V_9 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
T_1 V_12 = V_13 ;
struct V_14 V_15 [ 2 ] = {
{
. V_16 = V_6 -> V_10 -> V_16 ,
. V_17 = 1 ,
. V_18 = & V_12 ,
} ,
{
. V_16 = V_6 -> V_10 -> V_16 ,
. V_19 = V_20 ,
. V_17 = V_21 ,
. V_18 = V_6 -> V_22 ,
} ,
} ;
int V_23 ;
V_23 = F_9 ( V_6 -> V_10 -> V_24 , V_15 , F_10 ( V_15 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return V_23 == F_10 ( V_15 ) ? 0 : - V_25 ;
}
static void F_11 ( struct V_5 * V_6 ,
const T_1 V_26 [] )
{
T_1 V_27 = ( V_26 [ 0 ] & V_28 ) >> 4 ;
T_2 V_29 = V_26 [ 1 ] | ( ( V_26 [ 2 ] & V_30 ) << 8 ) ;
T_2 V_31 = ( V_26 [ 2 ] >> 4 ) | ( V_26 [ 3 ] << 4 ) ;
T_1 V_32 = V_26 [ 4 ] ;
T_1 V_33 = V_26 [ 5 ] ;
T_1 V_34 = V_26 [ 6 ] ;
T_1 V_35 = V_26 [ 7 ] ;
F_12 ( V_6 -> V_36 , V_27 ) ;
F_13 ( V_6 -> V_36 , V_37 , true ) ;
F_14 ( V_6 -> V_36 , V_38 , V_29 ) ;
F_14 ( V_6 -> V_36 , V_39 , V_31 ) ;
F_14 ( V_6 -> V_36 , V_40 , V_32 ) ;
F_14 ( V_6 -> V_36 , V_41 , V_33 ) ;
F_14 ( V_6 -> V_36 , V_42 , V_35 ) ;
F_14 ( V_6 -> V_36 , V_43 , V_34 ) ;
F_15 ( V_6 -> V_36 ) ;
}
static void F_16 ( struct V_5 * V_6 ,
const T_1 V_26 [] )
{
T_1 V_27 = ( V_26 [ 0 ] & V_28 ) >> 4 ;
F_12 ( V_6 -> V_36 , V_27 ) ;
F_13 ( V_6 -> V_36 , V_37 , false ) ;
F_15 ( V_6 -> V_36 ) ;
}
static void F_17 ( struct V_5 * V_6 ,
const T_1 V_26 [] )
{
T_2 V_29 = ( V_26 [ 2 ] << 4 ) | ( V_26 [ 4 ] >> 4 ) ;
T_2 V_31 = ( V_26 [ 3 ] << 4 ) | ( V_26 [ 4 ] & V_44 ) ;
T_1 V_45 = V_26 [ 5 ] ;
F_14 ( V_6 -> V_36 , V_46 , V_29 ) ;
F_14 ( V_6 -> V_36 , V_47 , V_31 ) ;
F_14 ( V_6 -> V_36 , V_48 , V_45 ) ;
F_15 ( V_6 -> V_36 ) ;
}
static void F_18 ( struct V_5 * V_6 , const T_1 V_26 [] )
{
switch ( V_26 [ 2 ] ) {
case 0 :
F_19 ( V_6 -> V_36 , V_49 , 0 ) ;
F_19 ( V_6 -> V_36 , V_50 , 0 ) ;
break;
case V_51 :
F_19 ( V_6 -> V_36 , V_49 , 1 ) ;
break;
case V_52 :
F_19 ( V_6 -> V_36 , V_50 , 1 ) ;
break;
default:
F_5 ( & V_6 -> V_10 -> V_11 ,
L_2 , V_26 [ 2 ] ) ;
break;
}
F_15 ( V_6 -> V_36 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
T_1 * V_26 = & V_6 -> V_22 [ V_53 * V_55 ] ;
switch ( V_26 [ 0 ] ) {
case V_56 :
case V_57 :
case V_58 :
F_21 ( & V_6 -> V_59 ) ;
case V_60 :
case V_61 :
return;
}
switch ( V_26 [ 0 ] & V_62 ) {
case V_63 :
case V_64 :
F_11 ( V_6 , V_26 ) ;
break;
case V_65 :
F_16 ( V_6 , V_26 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
F_17 ( V_6 , V_26 ) ;
break;
case V_69 :
F_18 ( V_6 , V_26 ) ;
break;
case V_70 :
F_5 ( & V_6 -> V_10 -> V_11 ,
L_3 ,
V_26 [ 6 ] , V_26 [ 5 ] , V_26 [ 4 ] ,
V_26 [ 3 ] , V_26 [ 2 ] , V_26 [ 1 ] ) ;
break;
default:
F_22 ( & V_6 -> V_10 -> V_11 ,
L_4 , V_26 [ 0 ] ) ;
}
}
}
static T_3 F_23 ( int V_71 , void * V_11 )
{
struct V_5 * V_6 = V_11 ;
int V_7 ;
F_24 ( & V_6 -> V_72 ) ;
V_7 = F_8 ( V_6 ) ;
if ( F_25 ( V_7 ) )
F_22 ( & V_6 -> V_10 -> V_11 ,
L_5 , V_7 ) ;
else
F_20 ( V_6 ) ;
F_26 ( & V_6 -> V_72 ) ;
return V_73 ;
}
static int F_27 ( struct V_5 * V_6 , const T_1 V_12 )
{
int V_7 ;
F_28 ( & V_6 -> V_59 ) ;
V_7 = F_29 ( V_6 -> V_10 , V_12 ) ;
if ( V_7 )
return V_7 ;
if ( ! F_30 ( & V_6 -> V_59 ,
F_31 ( 1000 ) ) )
return - V_74 ;
return 0 ;
}
static int F_32 ( struct V_75 * V_11 )
{
struct V_5 * V_6 = F_33 ( V_11 ) ;
int V_7 ;
V_7 = F_34 ( & V_6 -> V_10 -> V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_29 ( V_6 -> V_10 , V_76 ) ;
if ( V_7 )
return V_7 ;
F_24 ( & V_6 -> V_72 ) ;
V_6 -> V_77 = true ;
if ( V_6 -> V_78 ) {
V_7 = F_29 ( V_6 -> V_10 ,
V_79 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_6 ) ;
}
F_26 ( & V_6 -> V_72 ) ;
if ( V_6 -> V_80 ) {
V_7 = F_29 ( V_6 -> V_10 ,
V_81 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_7 ) ;
}
return 0 ;
}
static void F_35 ( struct V_75 * V_11 )
{
struct V_5 * V_6 = F_33 ( V_11 ) ;
int V_7 ;
V_7 = F_29 ( V_6 -> V_10 , V_82 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_8 , V_7 ) ;
F_24 ( & V_6 -> V_72 ) ;
V_6 -> V_77 = false ;
if ( V_6 -> V_78 ) {
V_7 = F_29 ( V_6 -> V_10 ,
V_83 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_9 , V_7 ) ;
}
F_26 ( & V_6 -> V_72 ) ;
if ( V_6 -> V_80 ) {
V_7 = F_29 ( V_6 -> V_10 ,
V_84 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_10 , V_7 ) ;
}
F_36 ( & V_6 -> V_10 -> V_11 ) ;
}
static T_4 F_37 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_11 , V_6 -> V_88 ) ;
}
static T_4 F_39 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_12 , V_6 -> V_89 ) ;
}
static T_4 F_40 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_12 , V_6 -> V_90 ) ;
}
static T_4 F_41 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_11 , V_6 -> V_91 ) ;
}
static T_4 F_42 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_12 , V_6 -> V_92 ) ;
}
static T_4 F_43 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
T_1 V_93 [ 4 ] ;
int V_7 ;
V_7 = F_44 ( V_6 -> V_10 , V_94 ,
sizeof( V_93 ) , V_93 ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_18 , L_13 , V_93 [ 0 ] ) ;
}
static T_4 F_45 ( struct V_85 * V_11 ,
struct V_86 * V_87 , char * V_18 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return sprintf ( V_18 , L_12 , V_6 -> V_78 ) ;
}
static T_4 F_46 ( struct V_85 * V_11 ,
struct V_86 * V_87 ,
const char * V_18 , T_5 V_17 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
unsigned long V_4 ;
int V_7 = 0 ;
if ( F_47 ( V_18 , 0 , & V_4 ) )
return - V_95 ;
F_24 ( & V_6 -> V_72 ) ;
if ( V_4 & V_6 -> V_78 )
goto V_96;
if ( V_6 -> V_77 )
V_7 = F_29 ( V_6 -> V_10 ,
V_4 ? V_79 :
V_83 ) ;
if ( ! V_7 )
V_6 -> V_78 = ! ! V_4 ;
V_96:
F_26 ( & V_6 -> V_72 ) ;
return V_17 ;
}
static int F_48 ( struct V_5 * V_6 )
{
int V_7 ;
T_1 V_97 [ 8 ] ;
V_7 = F_49 ( F_10 ( V_6 -> V_98 ) ,
V_6 -> V_98 ) ;
if ( V_7 )
return V_7 ;
F_50 ( 20 ) ;
V_7 = F_44 ( V_6 -> V_10 , V_99 ,
sizeof( V_97 ) , V_97 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != sizeof( V_97 ) )
return - V_25 ;
V_6 -> V_88 = F_51 ( ( V_100 * ) & V_97 [ 6 ] ) ;
V_6 -> V_89 = V_97 [ 0 ] ;
V_6 -> V_90 = F_51 ( ( V_100 * ) & V_97 [ 2 ] ) ;
V_6 -> V_91 = V_97 [ 4 ] ;
V_6 -> V_92 = V_97 [ 5 ] ;
F_52 ( V_6 -> V_10 -> V_71 ) ;
F_50 ( 50 ) ;
V_7 = F_27 ( V_6 , V_101 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_27 ( V_6 , V_102 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_27 ( V_6 , V_103 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_14 , V_7 ) ;
V_7 = F_27 ( V_6 , V_104 ) ;
if ( V_7 )
F_5 ( & V_6 -> V_10 -> V_11 ,
L_15 , V_7 ) ;
V_7 = F_27 ( V_6 , V_105 ) ;
if ( V_7 )
return V_7 ;
( void ) F_29 ( V_6 -> V_10 , V_106 ) ;
return 0 ;
}
static void F_53 ( void * V_22 )
{
struct V_5 * V_6 = V_22 ;
F_54 ( V_6 -> V_10 -> V_71 ) ;
F_55 ( F_10 ( V_6 -> V_98 ) ,
V_6 -> V_98 ) ;
}
static int F_56 ( struct V_5 * V_6 )
{
int V_7 ;
V_6 -> V_9 = F_57 ( & V_6 -> V_10 -> V_11 , L_16 ) ;
if ( F_58 ( V_6 -> V_9 ) )
return F_59 ( V_6 -> V_9 ) ;
V_6 -> V_2 . V_107 = V_108 ;
V_6 -> V_2 . V_109 = V_110 ;
V_6 -> V_2 . V_111 = V_112 ;
V_6 -> V_2 . V_113 = F_1 ;
V_6 -> V_2 . V_114 = F_6 ;
V_7 = F_60 ( & V_6 -> V_10 -> V_11 , & V_6 -> V_2 ) ;
if ( V_7 ) {
F_61 ( V_6 -> V_9 ) ;
return V_7 ;
}
return 0 ;
}
static int F_62 ( struct V_115 * V_10 ,
const struct V_116 * V_117 )
{
int V_7 ;
struct V_5 * V_6 ;
if ( ! F_63 ( V_10 -> V_24 , V_118 |
V_119 |
V_120 ) )
return - V_121 ;
V_6 = F_64 ( & V_10 -> V_11 , sizeof( * V_6 ) , V_122 ) ;
if ( ! V_6 )
return - V_123 ;
F_65 ( V_10 , V_6 ) ;
V_6 -> V_10 = V_10 ;
F_66 ( & V_6 -> V_72 ) ;
F_67 ( & V_6 -> V_59 ) ;
V_6 -> V_98 [ V_124 ] . V_125 = L_17 ;
V_6 -> V_98 [ V_126 ] . V_125 = L_18 ;
V_7 = F_68 ( & V_10 -> V_11 ,
F_10 ( V_6 -> V_98 ) ,
V_6 -> V_98 ) ;
if ( V_7 )
return V_7 ;
V_6 -> V_36 = F_69 ( & V_10 -> V_11 ) ;
if ( ! V_6 -> V_36 )
return - V_123 ;
V_6 -> V_36 -> V_107 = V_108 ;
V_6 -> V_36 -> V_117 . V_127 = V_128 ;
V_6 -> V_36 -> V_129 = F_32 ;
V_6 -> V_36 -> V_130 = F_35 ;
F_70 ( V_6 -> V_36 , true , & V_6 -> V_131 ) ;
F_71 ( V_6 -> V_36 , V_38 , 0 ,
V_6 -> V_131 . V_132 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_39 , 0 ,
V_6 -> V_131 . V_133 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_40 , 0 , 255 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_41 , 0 , 255 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_43 , 0 , 255 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_42 , 0 , 255 , 0 , 0 ) ;
F_71 ( V_6 -> V_36 , V_48 , 0 , 255 , 0 , 0 ) ;
V_6 -> V_80 = F_72 ( & V_10 -> V_11 ,
L_19 ) ;
if ( V_6 -> V_80 ) {
F_73 ( V_6 -> V_36 , V_134 , V_50 ) ;
F_73 ( V_6 -> V_36 , V_134 , V_49 ) ;
}
V_7 = F_74 ( V_6 -> V_36 ,
V_135 , V_136 ) ;
if ( V_7 )
return V_7 ;
F_75 ( V_6 -> V_36 , V_6 ) ;
V_7 = F_76 ( & V_10 -> V_11 , V_10 -> V_71 ,
NULL , F_23 ,
V_137 ,
L_20 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_54 ( V_10 -> V_71 ) ;
F_77 ( & V_10 -> V_11 , L_21 ) ;
V_7 = F_48 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_78 ( & V_10 -> V_11 , F_53 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_79 ( V_6 -> V_36 ) ;
if ( V_7 )
return V_7 ;
if ( V_6 -> V_80 ) {
V_7 = F_56 ( V_6 ) ;
if ( V_7 ) {
F_5 ( & V_10 -> V_11 , L_22 ) ;
V_6 -> V_9 = NULL ;
}
}
V_7 = F_80 ( & V_6 -> V_10 -> V_11 . V_138 ,
& V_139 ) ;
if ( V_7 )
return V_7 ;
F_81 ( & V_10 -> V_11 ) ;
return 0 ;
}
static int F_82 ( struct V_115 * V_10 )
{
F_83 ( & V_10 -> V_11 ) ;
F_84 ( & V_10 -> V_11 . V_138 , & V_139 ) ;
return 0 ;
}
static int T_6 F_85 ( struct V_85 * V_11 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
int V_23 ;
V_23 = F_29 ( V_6 -> V_10 , V_106 ) ;
if ( V_23 )
F_5 ( V_11 , L_23 , V_23 ) ;
return V_23 ;
}
static int T_6 F_86 ( struct V_85 * V_11 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
int V_23 ;
V_23 = F_29 ( V_6 -> V_10 , V_102 ) ;
if ( V_23 )
F_22 ( V_11 , L_24 , V_23 ) ;
return V_23 ;
}
static int T_6 F_87 ( struct V_85 * V_11 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
F_53 ( V_6 ) ;
return 0 ;
}
static int T_6 F_88 ( struct V_85 * V_11 )
{
struct V_5 * V_6 = F_38 ( V_11 ) ;
return F_48 ( V_6 ) ;
}
