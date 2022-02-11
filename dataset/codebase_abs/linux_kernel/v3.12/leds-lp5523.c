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
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_4 ( V_4 , V_41 + V_39 , 0 ) ;
}
static void F_12 ( struct V_7 * V_4 , bool V_42 )
{
int V_8 ;
T_1 V_43 ;
T_1 V_44 ;
if ( ! V_42 ) {
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
return;
}
V_8 = F_13 ( V_4 , V_33 , & V_43 ) ;
if ( V_8 )
return;
V_8 = F_13 ( V_4 , V_9 , & V_44 ) ;
if ( V_8 )
return;
if ( F_14 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_24 ) | V_45 ;
V_44 = ( V_44 & ~ V_46 ) | V_45 ;
}
if ( F_15 ( V_43 ) ) {
V_43 = ( V_43 & ~ V_26 ) | V_47 ;
V_44 = ( V_44 & ~ V_48 ) | V_47 ;
}
if ( F_16 ( V_43 ) ) {
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
F_12 ( V_4 , true ) ;
F_2 ( 3000 , 6000 ) ;
F_13 ( V_4 , V_61 , & V_53 ) ;
V_53 &= V_62 ;
if ( V_53 != V_62 ) {
F_17 ( & V_4 -> V_63 -> V_64 ,
L_1 ,
V_53 ) ;
V_8 = - 1 ;
}
V_60:
F_10 ( V_4 ) ;
return V_8 ;
}
static int F_18 ( struct V_7 * V_4 ,
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
F_19 ( & V_4 -> V_72 ) ;
for ( V_39 = 0 ; V_39 < V_55 ; V_39 ++ ) {
V_8 = F_4 ( V_4 , V_59 + V_39 , V_54 [ V_39 ] ) ;
if ( V_8 ) {
F_20 ( & V_4 -> V_72 ) ;
return - V_73 ;
}
}
F_20 ( & V_4 -> V_72 ) ;
return V_66 ;
V_71:
F_17 ( & V_4 -> V_63 -> V_64 , L_4 ) ;
return - V_73 ;
}
static void F_21 ( struct V_7 * V_4 )
{
const struct V_74 * V_75 = V_4 -> V_75 ;
if ( V_75 -> V_66 > V_55 ) {
F_17 ( & V_4 -> V_63 -> V_64 , L_5 ,
V_75 -> V_66 ) ;
return;
}
F_9 ( V_4 ) ;
F_18 ( V_4 , V_75 -> V_65 , V_75 -> V_66 ) ;
}
static T_3 F_22 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
char * V_79 , int V_80 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
enum V_81 V_43 = V_4 -> V_82 [ V_80 - 1 ] . V_43 ;
switch ( V_43 ) {
case V_83 :
return sprintf ( V_79 , L_6 ) ;
case V_84 :
return sprintf ( V_79 , L_7 ) ;
case V_85 :
default:
return sprintf ( V_79 , L_8 ) ;
}
}
static T_3 F_25 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
const char * V_79 , T_2 V_86 , int V_80 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_87 * V_88 = & V_4 -> V_82 [ V_80 - 1 ] ;
F_19 ( & V_4 -> V_72 ) ;
V_4 -> V_21 = V_80 ;
if ( ! strncmp ( V_79 , L_9 , 3 ) ) {
F_12 ( V_4 , true ) ;
V_88 -> V_43 = V_83 ;
} else if ( ! strncmp ( V_79 , L_10 , 4 ) ) {
F_10 ( V_4 ) ;
F_7 ( V_4 ) ;
V_88 -> V_43 = V_84 ;
} else if ( ! strncmp ( V_79 , L_11 , 8 ) ) {
F_10 ( V_4 ) ;
V_88 -> V_43 = V_85 ;
}
F_20 ( & V_4 -> V_72 ) ;
return V_86 ;
}
static int F_26 ( const char * V_79 , T_4 * V_89 , T_2 V_86 )
{
T_4 V_90 = 0 ;
int V_39 ;
V_86 = F_27 ( int , V_86 , V_40 ) ;
for ( V_39 = 0 ; V_39 < V_86 ; V_39 ++ ) {
switch ( V_79 [ V_39 ] ) {
case '1' :
V_90 |= ( 1 << V_39 ) ;
break;
case '0' :
break;
case '\n' :
V_39 = V_86 ;
break;
default:
return - 1 ;
}
}
* V_89 = V_90 ;
return 0 ;
}
static void F_28 ( T_4 V_91 , char * V_92 )
{
int V_39 , V_93 = 0 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_93 += sprintf ( V_92 + V_93 , L_12 , F_29 ( V_91 , V_39 ) ) ;
V_92 [ V_93 ] = '\0' ;
}
static T_3 F_30 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
char * V_79 , int V_80 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
char V_89 [ V_40 + 1 ] ;
F_28 ( V_4 -> V_82 [ V_80 - 1 ] . V_91 , V_89 ) ;
return sprintf ( V_79 , L_13 , V_89 ) ;
}
static int F_31 ( struct V_7 * V_4 , T_4 V_89 , int V_80 )
{
struct V_87 * V_88 = & V_4 -> V_82 [ V_80 - 1 ] ;
int V_8 ;
T_1 V_94 [] = {
[ V_23 ] = V_95 ,
[ V_25 ] = V_96 ,
[ V_27 ] = V_97 ,
} ;
F_7 ( V_4 ) ;
V_8 = F_4 ( V_4 , V_38 , V_94 [ V_80 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_59 , ( T_1 ) ( V_89 >> 8 ) ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_4 , V_59 + 1 , ( T_1 ) ( V_89 ) ) ;
if ( V_8 )
return V_8 ;
V_88 -> V_91 = V_89 ;
return 0 ;
}
static T_3 F_32 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
const char * V_79 , T_2 V_86 , int V_80 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_87 * V_88 = & V_4 -> V_82 [ V_80 - 1 ] ;
T_4 V_89 = 0 ;
T_3 V_8 ;
if ( F_26 ( V_79 , & V_89 , V_86 ) )
return - V_73 ;
F_19 ( & V_4 -> V_72 ) ;
V_4 -> V_21 = V_80 ;
V_8 = - V_73 ;
if ( V_88 -> V_43 != V_84 )
goto V_98;
if ( F_31 ( V_4 , V_89 , V_80 ) )
goto V_98;
V_8 = V_86 ;
V_98:
F_20 ( & V_4 -> V_72 ) ;
return V_8 ;
}
static T_3 F_33 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
const char * V_79 , T_2 V_86 , int V_80 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_19 ( & V_4 -> V_72 ) ;
V_4 -> V_21 = V_80 ;
F_9 ( V_4 ) ;
F_20 ( & V_4 -> V_72 ) ;
return F_18 ( V_4 , V_79 , V_86 ) ;
}
static T_3 F_34 ( struct V_76 * V_64 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_1 * V_2 = F_23 ( F_24 ( V_64 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_99 * V_100 = V_4 -> V_100 ;
int V_39 , V_8 , V_93 = 0 ;
T_1 V_53 , V_101 , V_102 ;
F_19 ( & V_4 -> V_72 ) ;
V_8 = F_13 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( V_100 -> V_104 == V_105 ) {
if ( ( V_53 & V_106 ) == 0 )
goto V_103;
}
F_4 ( V_4 , V_107 , V_108 | 16 ) ;
F_2 ( 3000 , 6000 ) ;
V_8 = F_13 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( ! ( V_53 & V_109 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_13 ( V_4 , V_110 , & V_102 ) ;
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
V_8 = F_13 ( V_4 , V_61 , & V_53 ) ;
if ( V_8 < 0 )
goto V_103;
if ( ! ( V_53 & V_109 ) )
F_2 ( 3000 , 6000 ) ;
V_8 = F_13 ( V_4 , V_110 , & V_101 ) ;
if ( V_8 < 0 )
goto V_103;
if ( V_101 >= V_102 || V_101 < V_112 )
V_93 += sprintf ( V_79 + V_93 , L_14 , V_39 ) ;
F_4 ( V_4 , V_41 + V_39 , 0x00 ) ;
F_4 ( V_4 , V_5 + V_39 ,
V_2 -> V_3 ) ;
V_2 ++ ;
}
if ( V_93 == 0 )
V_93 = sprintf ( V_79 , L_15 ) ;
goto V_113;
V_103:
V_93 = sprintf ( V_79 , L_16 ) ;
V_113:
F_20 ( & V_4 -> V_72 ) ;
return V_93 ;
}
static void F_35 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_36 ( V_115 , struct V_1 ,
V_116 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_19 ( & V_4 -> V_72 ) ;
F_4 ( V_4 , V_41 + V_2 -> V_6 ,
V_2 -> V_117 ) ;
F_20 ( & V_4 -> V_72 ) ;
}
static int F_37 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
int V_8 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_99 * V_100 ;
struct V_122 * V_123 = V_119 -> V_64 . V_124 ;
if ( ! F_38 ( & V_119 -> V_64 ) ) {
if ( V_123 ) {
V_8 = F_39 ( & V_119 -> V_64 , V_123 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
F_17 ( & V_119 -> V_64 , L_17 ) ;
return - V_73 ;
}
}
V_100 = F_38 ( & V_119 -> V_64 ) ;
V_4 = F_40 ( & V_119 -> V_64 , sizeof( * V_4 ) , V_125 ) ;
if ( ! V_4 )
return - V_126 ;
V_2 = F_40 ( & V_119 -> V_64 ,
sizeof( * V_2 ) * V_100 -> V_127 , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
V_4 -> V_63 = V_119 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_128 = & V_129 ;
F_41 ( & V_4 -> V_72 ) ;
F_42 ( V_119 , V_2 ) ;
V_8 = F_43 ( V_4 ) ;
if ( V_8 )
goto V_130;
F_44 ( & V_119 -> V_64 , L_18 , V_121 -> V_131 ) ;
V_8 = F_45 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_132;
V_8 = F_46 ( V_4 ) ;
if ( V_8 ) {
F_17 ( & V_119 -> V_64 , L_19 ) ;
goto V_133;
}
return 0 ;
V_133:
F_47 ( V_2 , V_4 ) ;
V_132:
F_48 ( V_4 ) ;
V_130:
return V_8 ;
}
static int F_49 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_23 ( V_119 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_10 ( V_4 ) ;
F_50 ( V_4 ) ;
F_47 ( V_2 , V_4 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
