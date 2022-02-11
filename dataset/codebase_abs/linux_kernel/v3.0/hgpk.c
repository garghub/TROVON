static int F_1 ( const char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
const char * V_5 = V_4 [ V_3 ] ;
if ( strlen ( V_5 ) == V_2 && ! strncasecmp ( V_5 , V_1 , V_2 ) )
return V_3 ;
}
return V_6 ;
}
static int F_3 ( int V_7 , int V_8 )
{
int V_9 , V_10 ;
if ( V_7 < 5 || V_8 < 5 )
return 0 ;
V_9 = ( V_8 * 8 ) / 20 ;
V_10 = ( V_8 * 12 ) / 20 ;
return V_9 < V_7 && V_7 <= V_10 ;
}
static int F_4 ( struct V_11 * V_11 , int V_12 , int V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_17 , V_18 ;
bool V_19 = false ;
V_17 = abs ( V_12 ) ;
V_18 = abs ( V_13 ) ;
if ( V_17 > V_20 ||
( V_17 > V_20 / 2 && ( ( V_17 / 4 ) > V_15 -> V_21 ) ) ) {
F_5 ( V_11 , L_1 , V_12 ) ;
V_15 -> V_22 = V_17 ;
} else if ( F_3 ( V_17 , V_15 -> V_22 ) ) {
F_5 ( V_11 , L_2 , V_12 ) ;
V_15 -> V_22 = V_17 ;
V_15 -> V_23 ++ ;
} else {
if ( V_15 -> V_22 && V_15 -> V_23 > 1 )
V_19 = true ;
V_15 -> V_22 = 0 ;
V_15 -> V_23 = 0 ;
}
if ( V_18 > V_20 ||
( V_18 > V_20 / 2 && ( ( V_18 / 4 ) > V_15 -> V_24 ) ) ) {
F_5 ( V_11 , L_3 , V_13 ) ;
V_15 -> V_25 = V_18 ;
} else if ( F_3 ( V_18 , V_15 -> V_25 ) ) {
F_5 ( V_11 , L_4 , V_13 ) ;
V_15 -> V_25 = V_18 ;
V_15 -> V_26 ++ ;
} else {
if ( V_15 -> V_25 && V_15 -> V_26 > 1 )
V_19 = true ;
V_15 -> V_25 = 0 ;
V_15 -> V_26 = 0 ;
}
V_15 -> V_21 = V_17 ;
V_15 -> V_24 = V_18 ;
if ( V_19 && V_27 ) {
F_5 ( V_11 , L_5 ) ;
F_6 ( V_11 , & V_15 -> V_28 ,
F_7 ( V_27 ) ) ;
}
return V_15 -> V_22 || V_15 -> V_25 ;
}
static void F_8 ( struct V_14 * V_15 )
{
V_15 -> V_29 = 0 ;
V_15 -> V_30 = 0 ;
V_15 -> V_31 = 0 ;
V_15 -> V_32 = 0 ;
V_15 -> V_33 = V_34 ;
}
static void F_9 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
V_15 -> V_35 = V_15 -> V_36 = - 1 ;
V_15 -> V_21 = V_15 -> V_24 = V_37 ;
V_15 -> V_22 = V_15 -> V_25 = 0 ;
V_15 -> V_23 = V_15 -> V_26 = 0 ;
F_8 ( V_15 ) ;
}
static void F_10 ( struct V_11 * V_11 ,
int V_38 , int V_39 , int V_12 , int V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_38 || V_39 )
return;
if ( ! V_40 )
return;
if ( abs ( V_12 ) > 3 || abs ( V_13 ) > 3 ) {
F_8 ( V_15 ) ;
return;
}
V_15 -> V_31 += V_12 ;
V_15 -> V_32 += V_13 ;
switch ( V_15 -> V_33 ) {
case V_34 :
V_15 -> V_33 = V_41 ;
case V_41 :
V_15 -> V_29 ++ ;
if ( V_15 -> V_29 < V_42 )
break;
V_15 -> V_33 = V_43 ;
case V_43 :
if ( abs ( V_15 -> V_31 ) < 3 && abs ( V_15 -> V_32 ) < 3 ) {
F_5 ( V_11 , L_6 ,
V_15 -> V_31 , V_15 -> V_32 ) ;
V_15 -> V_33 = V_44 ;
F_6 ( V_11 , & V_15 -> V_28 ,
F_7 ( V_40 ) ) ;
}
break;
case V_44 :
break;
}
}
static bool F_11 ( struct V_11 * V_11 , unsigned char * V_45 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_46 = V_11 -> V_46 ;
bool V_47 ;
switch ( V_15 -> V_48 ) {
case V_49 :
V_47 = ( V_45 [ 0 ] & 0x0C ) == 0x08 ;
break;
case V_50 :
V_47 = V_46 == 1 ?
V_45 [ 0 ] == V_51 : ! ( V_45 [ V_46 - 1 ] & 0x80 ) ;
break;
case V_52 :
V_47 = V_46 == 1 ?
V_45 [ 0 ] == V_53 : ! ( V_45 [ V_46 - 1 ] & 0x80 ) ;
break;
default:
V_47 = false ;
break;
}
if ( ! V_47 )
F_12 ( V_11 ,
L_7 ,
V_15 -> V_48 , V_46 ,
V_11 -> V_45 [ 0 ] , V_11 -> V_45 [ 1 ] ,
V_11 -> V_45 [ 2 ] , V_11 -> V_45 [ 3 ] ,
V_11 -> V_45 [ 4 ] , V_11 -> V_45 [ 5 ] ) ;
return V_47 ;
}
static void F_13 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_54 * V_55 = V_11 -> V_56 ;
unsigned char * V_45 = V_11 -> V_45 ;
int V_57 = ! ! ( V_45 [ 2 ] & 2 ) ;
int V_58 = ! ! ( V_45 [ 3 ] & 1 ) ;
int V_59 = ! ! ( V_45 [ 3 ] & 2 ) ;
int V_12 = V_45 [ 1 ] | ( ( V_45 [ 2 ] & 0x78 ) << 4 ) ;
int V_13 = V_45 [ 4 ] | ( ( V_45 [ 3 ] & 0x70 ) << 3 ) ;
if ( V_15 -> V_48 == V_50 ) {
int V_60 = ! ! ( V_45 [ 2 ] & 1 ) ;
int V_61 = ! ! ( V_45 [ 2 ] & 2 ) ;
int V_62 = V_45 [ 5 ] ;
F_14 ( V_55 , V_63 , V_62 ) ;
if ( V_64 )
F_12 ( V_11 , L_8 ,
V_60 , V_61 , V_62 ) ;
} else {
if ( V_64 )
F_12 ( V_11 , L_9 , V_57 ) ;
}
if ( V_64 )
F_12 ( V_11 , L_10 , V_58 , V_59 , V_12 , V_13 ) ;
F_15 ( V_55 , V_65 , V_57 ) ;
F_15 ( V_55 , V_66 , V_58 ) ;
F_15 ( V_55 , V_67 , V_59 ) ;
if ( ! V_57 ) {
F_9 ( V_11 ) ;
goto V_68;
}
if ( V_12 == V_15 -> V_35 && V_13 == V_15 -> V_36 ) {
if ( ++ V_15 -> V_30 > V_42 ) {
if ( V_64 )
F_12 ( V_11 , L_11 ) ;
V_15 -> V_33 = V_44 ;
F_6 ( V_11 , & V_15 -> V_28 ,
F_7 ( V_40 ) ) ;
}
goto V_68;
}
V_15 -> V_30 = 0 ;
if ( V_15 -> V_48 != V_52 && V_15 -> V_35 != - 1 ) {
int V_69 = V_15 -> V_35 - V_12 ;
int V_70 = V_15 -> V_36 - V_13 ;
if ( F_4 ( V_11 , V_69 , V_70 ) ) {
if ( V_64 )
F_12 ( V_11 , L_12 ) ;
goto V_68;
}
F_10 ( V_11 , V_58 , V_59 , V_69 , V_70 ) ;
}
F_14 ( V_55 , V_71 , V_12 ) ;
F_14 ( V_55 , V_72 , V_13 ) ;
V_15 -> V_35 = V_12 ;
V_15 -> V_36 = V_13 ;
V_68:
F_16 ( V_55 ) ;
}
static void F_17 ( struct V_11 * V_11 )
{
struct V_54 * V_56 = V_11 -> V_56 ;
unsigned char * V_45 = V_11 -> V_45 ;
int V_58 = V_45 [ 0 ] & 1 ;
int V_59 = ( V_45 [ 0 ] >> 1 ) & 1 ;
int V_12 = V_45 [ 1 ] - ( ( V_45 [ 0 ] << 4 ) & 0x100 ) ;
int V_13 = ( ( V_45 [ 0 ] << 3 ) & 0x100 ) - V_45 [ 2 ] ;
if ( V_45 [ 0 ] & 0xc0 )
F_12 ( V_11 ,
L_13 ,
V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] ) ;
if ( F_4 ( V_11 , V_12 , V_13 ) ) {
if ( V_64 )
F_12 ( V_11 , L_12 ) ;
return;
}
F_10 ( V_11 , V_58 , V_59 , V_12 , V_13 ) ;
if ( V_64 )
F_12 ( V_11 , L_10 , V_58 , V_59 , V_12 , V_13 ) ;
F_15 ( V_56 , V_66 , V_58 ) ;
F_15 ( V_56 , V_67 , V_59 ) ;
F_18 ( V_56 , V_73 , V_12 ) ;
F_18 ( V_56 , V_74 , V_13 ) ;
F_16 ( V_56 ) ;
}
static T_1 F_19 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
if ( ! F_11 ( V_11 , V_11 -> V_45 ) )
return V_75 ;
if ( V_11 -> V_46 >= V_11 -> V_76 ) {
if ( V_15 -> V_48 == V_49 )
F_17 ( V_11 ) ;
else
F_13 ( V_11 ) ;
return V_77 ;
}
if ( V_15 -> V_78 ) {
if ( F_20 ( V_79 , V_15 -> V_78 ) ) {
F_12 ( V_11 ,
L_14
L_15 ) ;
F_6 ( V_11 , & V_15 -> V_28 ,
F_7 ( V_80 ) ) ;
}
V_15 -> V_78 = 0 ;
}
return V_81 ;
}
static int F_21 ( struct V_11 * V_11 )
{
struct V_82 * V_82 = & V_11 -> V_82 ;
struct V_14 * V_15 = V_11 -> V_16 ;
int V_3 ;
int V_83 ;
const int V_84 [] = {
V_85 , V_85 ,
V_85 , V_85 ,
0xf2 , 0xf2 , 0xf2 ,
} ;
switch ( V_15 -> V_48 ) {
case V_49 :
V_11 -> V_76 = 3 ;
break;
case V_50 :
case V_52 :
V_11 -> V_76 = 6 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_84 ) ; V_3 ++ )
if ( F_22 ( V_82 , NULL , V_84 [ V_3 ] ) )
return - V_86 ;
V_83 = V_15 -> V_48 == V_50 ?
V_87 : V_88 ;
if ( F_22 ( V_82 , NULL , V_83 ) )
return - V_86 ;
break;
default:
return - V_89 ;
}
return 0 ;
}
static void F_23 ( struct V_54 * V_90 ,
struct V_54 * V_91 ,
enum V_92 V_48 )
{
if ( V_91 ) {
V_90 -> V_5 = V_91 -> V_5 ;
V_90 -> V_93 = V_91 -> V_93 ;
V_90 -> V_94 = V_91 -> V_94 ;
V_90 -> V_56 . V_95 = V_91 -> V_56 . V_95 ;
}
memset ( V_90 -> V_96 , 0 , sizeof( V_90 -> V_96 ) ) ;
memset ( V_90 -> V_97 , 0 , sizeof( V_90 -> V_97 ) ) ;
memset ( V_90 -> V_98 , 0 , sizeof( V_90 -> V_98 ) ) ;
F_24 ( V_99 , V_90 -> V_96 ) ;
F_24 ( V_66 , V_90 -> V_98 ) ;
F_24 ( V_67 , V_90 -> V_98 ) ;
switch ( V_48 ) {
case V_49 :
F_24 ( V_100 , V_90 -> V_96 ) ;
F_24 ( V_73 , V_90 -> V_97 ) ;
F_24 ( V_74 , V_90 -> V_97 ) ;
break;
case V_50 :
F_24 ( V_65 , V_90 -> V_98 ) ;
F_24 ( V_101 , V_90 -> V_98 ) ;
F_24 ( V_102 , V_90 -> V_96 ) ;
F_25 ( V_90 , V_63 , 0 , 15 , 0 , 0 ) ;
F_25 ( V_90 , V_71 , 0 , 399 , 0 , 0 ) ;
F_25 ( V_90 , V_72 , 0 , 290 , 0 , 0 ) ;
F_26 ( V_90 , V_71 , 8 ) ;
F_26 ( V_90 , V_72 , 8 ) ;
break;
case V_52 :
F_24 ( V_65 , V_90 -> V_98 ) ;
F_24 ( V_101 , V_90 -> V_98 ) ;
F_24 ( V_102 , V_90 -> V_96 ) ;
F_25 ( V_90 , V_71 , 0 , 999 , 0 , 0 ) ;
F_25 ( V_90 , V_72 , 5 , 239 , 0 , 0 ) ;
F_26 ( V_90 , V_71 , 6 ) ;
F_26 ( V_90 , V_72 , 8 ) ;
break;
default:
F_27 () ;
}
}
static int F_28 ( struct V_11 * V_11 , bool V_103 )
{
int V_104 ;
F_29 ( V_11 ) ;
if ( V_103 ) {
struct V_82 * V_82 = & V_11 -> V_82 ;
if ( F_22 ( V_82 , NULL , 0xf5 ) ||
F_22 ( V_82 , NULL , 0xf5 ) ||
F_22 ( V_82 , NULL , 0xe6 ) ||
F_22 ( V_82 , NULL , 0xf5 ) ) {
return - 1 ;
}
F_30 ( 150 ) ;
}
V_104 = F_21 ( V_11 ) ;
if ( V_104 ) {
F_5 ( V_11 , L_16 ) ;
return V_104 ;
}
F_9 ( V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_11 * V_11 )
{
struct V_82 * V_82 = & V_11 -> V_82 ;
struct V_14 * V_15 = V_11 -> V_16 ;
int V_104 ;
if ( V_11 -> V_105 < V_106 )
return 0 ;
if ( ! V_107 ) {
F_12 ( V_11 , L_17 ) ;
return 0 ;
}
F_12 ( V_11 , L_18 ) ;
F_32 ( V_11 , V_108 ) ;
V_104 = F_28 ( V_11 , true ) ;
if ( V_104 )
return V_104 ;
if ( F_22 ( V_82 , NULL , V_109 ) )
return - 1 ;
F_32 ( V_11 , V_110 ) ;
if ( V_64 )
F_12 ( V_11 , L_19 ) ;
if ( V_111 )
V_15 -> V_78 = V_79 +
F_7 ( V_111 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_11 , int V_112 )
{
struct V_82 * V_82 = & V_11 -> V_82 ;
int V_113 ;
int V_104 ;
if ( V_11 -> V_105 < V_114 )
return 0 ;
if ( V_112 ) {
F_32 ( V_11 , V_108 ) ;
for ( V_113 = 20 ; V_113 > 0 ; V_113 -- ) {
if ( ! F_34 ( & V_11 -> V_82 ,
V_85 , 20 ) )
break;
F_30 ( 25 ) ;
}
V_104 = F_28 ( V_11 , false ) ;
if ( V_104 ) {
F_5 ( V_11 , L_20 ) ;
return V_104 ;
}
F_22 ( & V_11 -> V_82 , NULL , V_109 ) ;
F_32 ( V_11 , V_110 ) ;
F_12 ( V_11 , L_21 ) ;
} else {
F_12 ( V_11 , L_22 ) ;
if ( F_22 ( V_82 , NULL , 0xec ) ||
F_22 ( V_82 , NULL , 0xec ) ||
F_22 ( V_82 , NULL , 0xea ) ) {
return - 1 ;
}
F_32 ( V_11 , V_115 ) ;
F_34 ( & V_11 -> V_82 , 0xec , 20 ) ;
}
return 0 ;
}
static int F_35 ( struct V_11 * V_11 )
{
return - 1 ;
}
static int F_36 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
if ( F_37 ( F_38 ( 0xb2 ) ) )
if ( V_11 -> V_82 . V_116 -> V_56 . V_117 . V_118 . V_119 !=
V_120 )
return 0 ;
V_15 -> V_121 = 1 ;
return F_28 ( V_11 , false ) ;
}
static T_2 F_39 ( struct V_11 * V_11 , void * V_122 , char * V_1 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
return sprintf ( V_1 , L_23 , V_15 -> V_121 ) ;
}
static T_2 F_40 ( struct V_11 * V_11 , void * V_122 ,
const char * V_1 , T_3 V_123 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
unsigned long V_124 ;
int V_104 ;
V_104 = F_41 ( V_1 , 10 , & V_124 ) ;
if ( V_104 || V_124 > 1 )
return - V_89 ;
if ( V_124 != V_15 -> V_121 ) {
V_104 = F_33 ( V_11 , V_124 ) ;
if ( ! V_104 )
V_15 -> V_121 = V_124 ;
}
return V_104 ? V_104 : V_123 ;
}
static T_2 F_42 ( struct V_11 * V_11 , void * V_122 , char * V_1 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
return sprintf ( V_1 , L_24 , V_4 [ V_15 -> V_48 ] ) ;
}
static T_2 F_43 ( struct V_11 * V_11 , void * V_122 ,
const char * V_1 , T_3 V_2 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
enum V_92 V_125 = V_15 -> V_48 ;
enum V_92 V_126 = F_1 ( V_1 , V_2 ) ;
struct V_54 * V_127 = V_11 -> V_56 ;
struct V_54 * V_128 ;
int V_104 ;
if ( V_126 == V_6 )
return - V_89 ;
if ( V_125 == V_126 )
return V_2 ;
V_128 = F_44 () ;
if ( ! V_128 )
return - V_129 ;
F_32 ( V_11 , V_108 ) ;
V_15 -> V_48 = V_126 ;
V_104 = F_28 ( V_11 , false ) ;
if ( V_104 )
goto V_130;
F_23 ( V_128 , V_127 , V_126 ) ;
F_32 ( V_11 , V_131 ) ;
V_104 = F_45 ( V_128 ) ;
if ( V_104 )
goto V_130;
V_11 -> V_56 = V_128 ;
F_46 ( V_127 ) ;
return V_2 ;
V_130:
F_47 ( V_128 ) ;
V_15 -> V_48 = V_125 ;
F_28 ( V_11 , false ) ;
return V_104 ;
}
static T_2 F_48 ( struct V_11 * V_11 ,
void * V_122 , char * V_1 )
{
return - V_89 ;
}
static T_2 F_49 ( struct V_11 * V_11 , void * V_122 ,
const char * V_1 , T_3 V_123 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
unsigned long V_124 ;
int V_104 ;
V_104 = F_41 ( V_1 , 10 , & V_124 ) ;
if ( V_104 || V_124 != 1 )
return - V_89 ;
F_6 ( V_11 , & V_15 -> V_28 , 0 ) ;
return V_123 ;
}
static void F_50 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_51 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_132 . V_133 ) ;
F_51 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_134 . V_133 ) ;
if ( V_11 -> V_105 >= V_106 )
F_51 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_135 . V_133 ) ;
F_29 ( V_11 ) ;
F_52 ( V_15 ) ;
}
static void F_53 ( struct V_136 * V_137 )
{
struct V_138 * V_139 = F_54 ( V_137 ) ;
struct V_14 * V_15 = F_55 ( V_139 , struct V_14 , V_28 ) ;
struct V_11 * V_11 = V_15 -> V_11 ;
if ( F_31 ( V_11 ) )
F_5 ( V_11 , L_25 ) ;
}
static int F_56 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_104 ;
V_11 -> V_140 = F_19 ;
V_11 -> V_141 = F_35 ;
V_11 -> V_142 = F_50 ;
V_11 -> V_143 = F_36 ;
V_11 -> V_144 = 0 ;
V_11 -> V_145 = 1024 ;
F_23 ( V_11 -> V_56 , NULL , V_15 -> V_48 ) ;
V_104 = F_57 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_132 . V_133 ) ;
if ( V_104 ) {
F_5 ( V_11 , L_26 ) ;
return V_104 ;
}
V_104 = F_57 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_134 . V_133 ) ;
if ( V_104 ) {
F_5 ( V_11 , L_27 ) ;
goto V_146;
}
if ( V_11 -> V_105 >= V_106 ) {
V_104 = F_57 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_135 . V_133 ) ;
if ( V_104 ) {
F_5 ( V_11 ,
L_28 ) ;
goto V_147;
}
}
return 0 ;
V_147:
F_51 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_134 . V_133 ) ;
V_146:
F_51 ( & V_11 -> V_82 . V_116 -> V_56 ,
& V_132 . V_133 ) ;
return V_104 ;
}
int F_58 ( struct V_11 * V_11 )
{
struct V_14 * V_15 ;
int V_104 ;
V_15 = F_59 ( sizeof( struct V_14 ) , V_148 ) ;
if ( ! V_15 ) {
V_104 = - V_129 ;
goto V_149;
}
V_11 -> V_16 = V_15 ;
V_15 -> V_11 = V_11 ;
V_15 -> V_121 = true ;
V_15 -> V_48 = V_150 ;
F_60 ( & V_15 -> V_28 , F_53 ) ;
V_104 = F_28 ( V_11 , false ) ;
if ( V_104 )
goto V_151;
V_104 = F_56 ( V_11 ) ;
if ( V_104 )
goto V_151;
return 0 ;
V_151:
F_52 ( V_15 ) ;
V_149:
return V_104 ;
}
static enum V_152 F_61 ( struct V_11 * V_11 )
{
struct V_82 * V_82 = & V_11 -> V_82 ;
unsigned char V_153 [ 3 ] ;
if ( F_22 ( V_82 , NULL , V_88 ) ||
F_22 ( V_82 , NULL , V_88 ) ||
F_22 ( V_82 , NULL , V_88 ) ||
F_22 ( V_82 , V_153 , V_154 ) ) {
return - V_86 ;
}
F_12 ( V_11 , L_29 , V_153 [ 0 ] , V_153 [ 1 ] , V_153 [ 2 ] ) ;
if ( V_153 [ 0 ] != 0x67 || V_153 [ 1 ] != 0x00 )
return - V_155 ;
F_62 ( V_11 , L_30 , V_153 [ 2 ] ) ;
return V_153 [ 2 ] ;
}
int F_63 ( struct V_11 * V_11 , bool V_156 )
{
int V_157 ;
V_157 = F_61 ( V_11 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_156 ) {
V_11 -> V_158 = L_31 ;
V_11 -> V_5 = L_32 ;
V_11 -> V_105 = V_157 ;
}
return 0 ;
}
void F_64 ( void )
{
V_150 = F_1 ( V_159 ,
strlen ( V_159 ) ) ;
if ( V_150 == V_6 ) {
V_150 = V_49 ;
F_65 ( V_159 , V_4 [ V_49 ] ,
sizeof( V_159 ) ) ;
}
}
