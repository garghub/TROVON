static inline void F_1 ( void )
{
F_2 ( 1000 , 2000 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
F_4 ( V_2 -> V_4 , V_5 + V_2 -> V_6 ,
V_3 ) ;
}
static int F_5 ( struct V_7 * V_4 )
{
int V_8 ;
V_8 = F_4 ( V_4 , V_9 , V_10 ) ;
if ( V_8 )
return V_8 ;
F_2 ( 1000 , 2000 ) ;
V_8 = F_4 ( V_4 , V_11 ,
V_12 | V_13 |
V_14 | V_15 |
V_16 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_17 , 0x01 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_18 , 0xff ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_4 ) ;
}
static void F_7 ( struct V_7 * V_4 )
{
enum V_19 V_20 = V_4 -> V_21 ;
T_1 V_22 [] = {
[ V_23 ] = V_24 ,
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
} ;
T_1 V_29 [] = {
[ V_23 ] = V_30 ,
[ V_25 ] = V_31 ,
[ V_27 ] = V_32 ,
} ;
F_8 ( V_4 , V_33 , V_22 [ V_20 ] , V_29 [ V_20 ] ) ;
F_1 () ;
}
static void F_9 ( struct V_7 * V_4 )
{
enum V_19 V_20 = V_4 -> V_21 ;
T_1 V_34 [] = {
[ V_23 ] = V_35 ,
[ V_25 ] = V_36 ,
[ V_27 ] = V_37 ,
} ;
F_7 ( V_4 ) ;
F_4 ( V_4 , V_38 , V_34 [ V_20 ] ) ;
}
static void F_10 ( struct V_7 * V_4 )
{
F_4 ( V_4 , V_33 , 0 ) ;
F_1 () ;
}
static void F_11 ( struct V_7 * V_4 )
{
enum V_19 V_20 = V_4 -> V_21 ;
T_1 V_22 [] = {
[ V_23 ] = V_24 ,
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
} ;
F_8 ( V_4 , V_33 , V_22 [ V_20 ] , 0 ) ;
F_1 () ;
}
static void F_12 ( struct V_7 * V_4 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_4 ( V_4 , V_41 + V_39 , 0 ) ;
}
static void F_13 ( struct V_7 * V_4 , bool V_42 )
{
int V_8 ;
T_1 V_43 ;
T_1 V_44 ;
if ( ! V_42 ) {
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
return;
}
V_8 = F_14 ( V_4 , V_33 , & V_43 ) ;
if ( V_8 )
return;
V_8 = F_14 ( V_4 , V_9 , & V_44 ) ;
if ( V_8 )
return;
if ( F_15 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_24 ) | V_45 ;
V_44 = ( V_44 & ~ V_46 ) | V_45 ;
}
if ( F_16 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_26 ) | V_47 ;
V_44 = ( V_44 & ~ V_48 ) | V_47 ;
}
if ( F_17 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_28 ) | V_49 ;
V_44 = ( V_44 & ~ V_50 ) | V_49 ;
}
F_4 ( V_4 , V_33 , V_43 ) ;
F_1 () ;
F_8 ( V_4 , V_9 , V_51 , V_44 ) ;
}
static int F_6 ( struct V_7 * V_4 )
{
int V_39 ;
int V_52 ;
int V_8 ;
T_1 V_53 ;
static const T_1 V_54 [] [ V_55 ] = {
{ 0x9c , 0x30 , 0x9c , 0xb0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x40 , 0x9c , 0xc0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
{ 0x9c , 0x50 , 0x9c , 0xd0 , 0x9d , 0x80 , 0xd8 , 0x00 , 0 } ,
} ;
V_8 = F_4 ( V_4 , V_56 , 0x00 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_57 , 0x10 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_58 , 0x20 ) ;
if ( V_8 )
return V_8 ;
for ( V_39 = V_23 ; V_39 <= V_27 ; V_39 ++ ) {
V_4 -> V_21 = V_39 ;
F_9 ( V_4 ) ;
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
V_8 = F_4 ( V_4 , V_59 + V_52 ,
V_54 [ V_39 - 1 ] [ V_52 ] ) ;
if ( V_8 )
goto V_60;
}
}
F_13 ( V_4 , true ) ;
F_2 ( 3000 , 6000 ) ;
F_14 ( V_4 , V_61 , & V_53 ) ;
V_53 &= V_62 ;
if ( V_53 != V_62 ) {
F_18 ( & V_4 -> V_63 -> V_64 ,
L_1 ,
V_53 ) ;
V_8 = - 1 ;
}
V_60:
F_10 ( V_4 ) ;
return V_8 ;
}
static int F_19 ( struct V_7 * V_4 ,
const T_1 * V_65 , T_2 V_66 )
{
T_1 V_54 [ V_55 ] = { 0 } ;
unsigned V_67 ;
char V_68 [ 3 ] ;
int V_69 ;
int V_8 ;
int V_70 = 0 ;
int V_39 = 0 ;
while ( ( V_70 < V_66 - 1 ) && ( V_39 < V_55 ) ) {
V_8 = sscanf ( V_65 + V_70 , L_2 , V_68 , & V_69 ) ;
if ( V_8 != 1 )
goto V_71;
V_8 = sscanf ( V_68 , L_3 , & V_67 ) ;
if ( V_8 != 1 )
goto V_71;
V_54 [ V_39 ] = ( T_1 ) V_67 ;
V_70 += V_69 ;
V_39 ++ ;
}
if ( V_39 % 2 )
goto V_71;
for ( V_39 = 0 ; V_39 < V_55 ; V_39 ++ ) {
V_8 = F_4 ( V_4 , V_59 + V_39 , V_54 [ V_39 ] ) ;
if ( V_8 )
return - V_72 ;
}
return V_66 ;
V_71:
F_18 ( & V_4 -> V_63 -> V_64 , L_4 ) ;
return - V_72 ;
}
static void F_20 ( struct V_7 * V_4 )
{
const struct V_73 * V_74 = V_4 -> V_74 ;
if ( V_74 -> V_66 > V_55 ) {
F_18 ( & V_4 -> V_63 -> V_64 , L_5 ,
V_74 -> V_66 ) ;
return;
}
F_9 ( V_4 ) ;
F_19 ( V_4 , V_74 -> V_65 , V_74 -> V_66 ) ;
}
static T_3 F_21 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
char * V_78 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
enum V_80 V_43 = V_4 -> V_81 [ V_79 - 1 ] . V_43 ;
switch ( V_43 ) {
case V_82 :
return sprintf ( V_78 , L_6 ) ;
case V_83 :
return sprintf ( V_78 , L_7 ) ;
case V_84 :
default:
return sprintf ( V_78 , L_8 ) ;
}
}
static T_3 F_24 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_85 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_86 * V_87 = & V_4 -> V_81 [ V_79 - 1 ] ;
F_25 ( & V_4 -> V_88 ) ;
V_4 -> V_21 = V_79 ;
if ( ! strncmp ( V_78 , L_9 , 3 ) ) {
F_13 ( V_4 , true ) ;
V_87 -> V_43 = V_82 ;
} else if ( ! strncmp ( V_78 , L_10 , 4 ) ) {
F_11 ( V_4 ) ;
F_7 ( V_4 ) ;
V_87 -> V_43 = V_83 ;
} else if ( ! strncmp ( V_78 , L_11 , 8 ) ) {
F_11 ( V_4 ) ;
V_87 -> V_43 = V_84 ;
}
F_26 ( & V_4 -> V_88 ) ;
return V_85 ;
}
static int F_27 ( const char * V_78 , T_4 * V_89 , T_2 V_85 )
{
T_4 V_90 = 0 ;
int V_39 ;
V_85 = F_28 ( int , V_85 , V_40 ) ;
for ( V_39 = 0 ; V_39 < V_85 ; V_39 ++ ) {
switch ( V_78 [ V_39 ] ) {
case '1' :
V_90 |= ( 1 << V_39 ) ;
break;
case '0' :
break;
case '\n' :
V_39 = V_85 ;
break;
default:
return - 1 ;
}
}
* V_89 = V_90 ;
return 0 ;
}
static void F_29 ( T_4 V_91 , char * V_92 )
{
int V_39 , V_93 = 0 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_93 += sprintf ( V_92 + V_93 , L_12 , F_30 ( V_91 , V_39 ) ) ;
V_92 [ V_93 ] = '\0' ;
}
static T_3 F_31 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
char * V_78 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
char V_89 [ V_40 + 1 ] ;
F_29 ( V_4 -> V_81 [ V_79 - 1 ] . V_91 , V_89 ) ;
return sprintf ( V_78 , L_13 , V_89 ) ;
}
static int F_32 ( struct V_7 * V_4 , T_4 V_89 , int V_79 )
{
struct V_86 * V_87 = & V_4 -> V_81 [ V_79 - 1 ] ;
int V_8 ;
T_1 V_94 [] = {
[ V_23 ] = V_95 ,
[ V_25 ] = V_96 ,
[ V_27 ] = V_97 ,
} ;
F_7 ( V_4 ) ;
V_8 = F_4 ( V_4 , V_38 , V_94 [ V_79 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_59 , ( T_1 ) ( V_89 >> 8 ) ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_59 + 1 , ( T_1 ) ( V_89 ) ) ;
if ( V_8 )
return V_8 ;
V_87 -> V_91 = V_89 ;
return 0 ;
}
static T_3 F_33 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_85 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_86 * V_87 = & V_4 -> V_81 [ V_79 - 1 ] ;
T_4 V_89 = 0 ;
T_3 V_8 ;
if ( F_27 ( V_78 , & V_89 , V_85 ) )
return - V_72 ;
F_25 ( & V_4 -> V_88 ) ;
V_4 -> V_21 = V_79 ;
V_8 = - V_72 ;
if ( V_87 -> V_43 != V_83 )
goto V_98;
if ( F_32 ( V_4 , V_89 , V_79 ) )
goto V_98;
V_8 = V_85 ;
V_98:
F_26 ( & V_4 -> V_88 ) ;
return V_8 ;
}
static T_3 F_34 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_85 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_8 ;
F_25 ( & V_4 -> V_88 ) ;
V_4 -> V_21 = V_79 ;
F_9 ( V_4 ) ;
V_8 = F_19 ( V_4 , V_78 , V_85 ) ;
F_26 ( & V_4 -> V_88 ) ;
return V_8 ;
}
static T_3 F_35 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
char * V_78 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_99 * V_100 = V_4 -> V_100 ;
int V_39 , V_8 , V_93 = 0 ;
T_1 V_53 , V_101 , V_102 ;
F_25 ( & V_4 -> V_88 ) ;
V_8 = F_14 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( V_100 -> V_104 == V_105 ) {
if ( ( V_53 & V_106 ) == 0 )
goto V_103;
}
F_4 ( V_4 , V_107 , V_108 | 16 ) ;
F_2 ( 3000 , 6000 ) ;
V_8 = F_14 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( ! ( V_53 & V_109 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_14 ( V_4 , V_110 , & V_102 ) ;
if ( V_8 < 0 )
goto V_103;
V_102 -- ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( V_100 -> V_111 [ V_39 ] . V_3 == 0 )
continue;
F_4 ( V_4 , V_5 + V_39 ,
V_100 -> V_111 [ V_39 ] . V_3 ) ;
F_4 ( V_4 , V_41 + V_39 , 0xff ) ;
F_2 ( 2000 , 4000 ) ;
F_4 ( V_4 , V_107 ,
V_108 | V_39 ) ;
F_2 ( 3000 , 6000 ) ;
V_8 = F_14 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( ! ( V_53 & V_109 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_14 ( V_4 , V_110 , & V_101 ) ;
if ( V_8 < 0 )
goto V_103;
if ( V_101 >= V_102 || V_101 < V_112 )
V_93 += sprintf ( V_78 + V_93 , L_14 , V_39 ) ;
F_4 ( V_4 , V_41 + V_39 , 0x00 ) ;
F_4 ( V_4 , V_5 + V_39 ,
V_2 -> V_3 ) ;
V_2 ++ ;
}
if ( V_93 == 0 )
V_93 = sprintf ( V_78 , L_15 ) ;
goto V_113;
V_103:
V_93 = sprintf ( V_78 , L_16 ) ;
V_113:
F_26 ( & V_4 -> V_88 ) ;
return V_93 ;
}
static T_3 F_36 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
char * V_78 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_8 ;
T_1 V_29 ;
F_25 ( & V_4 -> V_88 ) ;
V_8 = F_14 ( V_4 , V_114 + V_79 - 1 , & V_29 ) ;
F_26 ( & V_4 -> V_88 ) ;
if ( V_8 == 0 )
V_8 = sprintf ( V_78 , L_17 , V_29 ) ;
return V_8 ;
}
static T_3 F_37 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_85 , int V_79 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_8 ;
unsigned long V_29 ;
if ( F_38 ( V_78 , 0 , & V_29 ) )
return - V_72 ;
if ( V_29 > 0xff )
return - V_72 ;
F_25 ( & V_4 -> V_88 ) ;
V_8 = F_4 ( V_4 , V_114 + V_79 - 1 ,
( T_1 ) V_29 ) ;
F_26 ( & V_4 -> V_88 ) ;
if ( V_8 == 0 )
V_8 = V_85 ;
return V_8 ;
}
static T_3 F_39 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
char * V_78 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_39 , V_8 , V_93 = 0 ;
T_1 V_29 ;
F_25 ( & V_4 -> V_88 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_8 = F_14 ( V_4 , V_115 + V_39 , & V_29 ) ;
if ( V_8 )
goto V_98;
V_29 = ( V_29 & V_116 )
>> V_117 ;
if ( V_29 > 3 ) {
V_8 = - V_72 ;
goto V_98;
}
V_78 [ V_93 ++ ] = V_29 + '0' ;
}
V_78 [ V_93 ++ ] = '\n' ;
V_8 = V_93 ;
V_98:
F_26 ( & V_4 -> V_88 ) ;
return V_8 ;
}
static T_3 F_40 ( struct V_75 * V_64 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_85 )
{
struct V_1 * V_2 = F_22 ( F_23 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_39 , V_118 , V_8 ;
T_1 V_29 ;
V_118 = F_28 ( int , V_85 , V_40 ) ;
F_25 ( & V_4 -> V_88 ) ;
for ( V_39 = 0 ; V_39 < V_118 ; V_39 ++ ) {
if ( V_78 [ V_39 ] >= '0' && V_78 [ V_39 ] <= '3' ) {
V_29 = ( V_78 [ V_39 ] - '0' ) << V_117 ;
V_8 = F_8 ( V_4 ,
V_115 + V_39 ,
V_116 ,
V_29 ) ;
if ( V_8 )
goto V_98;
} else {
V_8 = - V_72 ;
goto V_98;
}
}
V_8 = V_85 ;
V_98:
F_26 ( & V_4 -> V_88 ) ;
return V_8 ;
}
static void F_41 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_42 ( V_120 , struct V_1 ,
V_121 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_25 ( & V_4 -> V_88 ) ;
F_4 ( V_4 , V_41 + V_2 -> V_6 ,
V_2 -> V_122 ) ;
F_26 ( & V_4 -> V_88 ) ;
}
static int F_43 ( struct V_123 * V_124 ,
const struct V_125 * V_126 )
{
int V_8 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_99 * V_100 = F_44 ( & V_124 -> V_64 ) ;
struct V_127 * V_128 = V_124 -> V_64 . V_129 ;
if ( ! V_100 ) {
if ( V_128 ) {
V_100 = F_45 ( & V_124 -> V_64 , V_128 ) ;
if ( F_46 ( V_100 ) )
return F_47 ( V_100 ) ;
} else {
F_18 ( & V_124 -> V_64 , L_18 ) ;
return - V_72 ;
}
}
V_4 = F_48 ( & V_124 -> V_64 , sizeof( * V_4 ) , V_130 ) ;
if ( ! V_4 )
return - V_131 ;
V_2 = F_48 ( & V_124 -> V_64 ,
sizeof( * V_2 ) * V_100 -> V_132 , V_130 ) ;
if ( ! V_2 )
return - V_131 ;
V_4 -> V_63 = V_124 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_133 = & V_134 ;
F_49 ( & V_4 -> V_88 ) ;
F_50 ( V_124 , V_2 ) ;
V_8 = F_51 ( V_4 ) ;
if ( V_8 )
goto V_135;
F_52 ( & V_124 -> V_64 , L_19 , V_126 -> V_136 ) ;
V_8 = F_53 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_137;
V_8 = F_54 ( V_4 ) ;
if ( V_8 ) {
F_18 ( & V_124 -> V_64 , L_20 ) ;
goto V_138;
}
return 0 ;
V_138:
F_55 ( V_2 , V_4 ) ;
V_137:
F_56 ( V_4 ) ;
V_135:
return V_8 ;
}
static int F_57 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_22 ( V_124 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_10 ( V_4 ) ;
F_58 ( V_4 ) ;
F_55 ( V_2 , V_4 ) ;
F_56 ( V_4 ) ;
return 0 ;
}
