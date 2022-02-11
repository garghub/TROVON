static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_1 ) ;
F_3 ( V_4 ) ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
const int V_10 [ 3 ] = { 14200 , 6600 , 3300 } ;
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_12 == V_13 || V_4 -> V_12 >= V_14 )
return sprintf ( V_9 , L_1 , ( V_4 -> V_15 [ V_11 ] * V_16 *
V_17 [ V_11 ] ) / 255 + V_18 [ V_11 ] ) ;
else
return sprintf ( V_9 , L_1 , ( V_4 -> V_15 [ V_11 ] *
V_10 [ V_11 ] + 128 ) / 255 ) ;
}
static T_1 F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_8 ( V_4 -> V_19 [ V_11 ] ) ) ;
}
static T_1 F_9 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_1 , F_8 ( V_4 -> V_20 [ V_11 ] ) ) ;
}
static T_1 F_10 ( struct V_5 * V_6 , struct V_7
* V_8 , const char * V_9 , T_2 V_21 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
long V_22 ;
int V_23 ;
V_23 = F_12 ( V_9 , 10 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_22 = F_13 ( V_22 / 1000 , - 128 , 127 ) + 128 ;
F_14 ( & V_4 -> V_24 ) ;
F_15 ( F_16 ( V_6 ) ,
V_25 [ V_4 -> V_12 ] [ V_11 ] , V_22 ) ;
V_4 -> V_20 [ V_11 ] = V_22 ;
F_17 ( & V_4 -> V_24 ) ;
return V_21 ;
}
static T_1 F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_26 [ V_11 ] & V_27 )
return sprintf ( V_9 , L_2 ) ;
else
return sprintf ( V_9 , L_3 ) ;
}
static T_1 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( ( V_4 -> V_26 [ V_11 ] & V_28 ) ==
V_28 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_4 , F_21 ( V_4 -> V_29 [ V_11 ] ) ) ;
}
static T_1 F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_1 , 1 << ( V_4 -> V_30 [ V_11 ] & 3 ) ) ;
}
static T_1 F_23 ( struct V_5 * V_6 , struct V_7
* V_8 , const char * V_9 , T_2 V_21 )
{
T_3 V_31 ;
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 ;
int V_23 ;
V_23 = F_24 ( V_9 , 10 , & V_22 ) ;
if ( V_23 )
return V_23 ;
switch ( V_22 ) {
case 2 :
V_22 = 1 ;
break;
case 4 :
V_22 = 2 ;
break;
case 8 :
V_22 = 3 ;
break;
default:
F_25 ( V_6 ,
L_5 ,
V_22 ) ;
return - V_32 ;
}
F_14 ( & V_4 -> V_24 ) ;
V_31 = F_26 ( F_16 ( V_6 ) ,
V_33 [ V_4 -> V_12 ] [ V_11 ] ) ;
V_31 &= ~ 0x03 ;
V_31 |= V_22 ;
F_15 ( F_16 ( V_6 ) ,
V_33 [ V_4 -> V_12 ] [ V_11 ] , V_31 ) ;
V_4 -> V_30 [ V_11 ] = V_31 ;
F_17 ( & V_4 -> V_24 ) ;
return V_21 ;
}
static T_1 F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_34 [ V_11 ] & V_35 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_34 [ V_11 ] & V_36 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
int V_37 = V_4 -> V_38 [ V_11 ] ;
if ( V_37 || V_4 -> V_12 == V_39 )
V_37 = V_37 / 2 + 128 ;
return sprintf ( V_9 , L_1 , V_37 ) ;
}
static T_1 F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 , T_2 V_21 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 ;
int V_23 ;
V_23 = F_24 ( V_9 , 10 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 || V_4 -> V_12 == V_39 ) {
V_22 = F_13 ( V_22 , 128 , 255 ) ;
V_22 = ( V_22 - 128 ) * 2 + 1 ;
}
F_14 ( & V_4 -> V_24 ) ;
F_15 ( F_16 ( V_6 ) ,
V_40 [ V_4 -> V_12 ] [ V_11 ] , V_22 ) ;
V_4 -> V_38 [ V_11 ] = V_22 ;
F_17 ( & V_4 -> V_24 ) ;
return V_21 ;
}
static T_1 F_31 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_41 & V_42 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_32 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 , T_2 V_21 )
{
T_3 V_31 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 ;
int V_23 ;
V_23 = F_24 ( V_9 , 10 , & V_22 ) ;
if ( V_23 )
return V_23 ;
F_14 ( & V_4 -> V_24 ) ;
V_31 = F_26 ( F_16 ( V_6 ) , V_43 ) ;
if ( V_22 )
V_31 |= V_42 ;
else
V_31 &= ~ V_42 ;
F_15 ( F_16 ( V_6 ) , V_43 , V_31 ) ;
V_4 -> V_41 = V_31 ;
F_17 ( & V_4 -> V_24 ) ;
return V_21 ;
}
static int F_33 ( struct V_3 * V_4 , int V_44 )
{
int V_45 , V_46 ;
int V_12 = V_4 -> V_12 + 1 ;
if ( V_44 <= 510 || V_12 == V_47 || V_12 == V_48 )
V_46 = 2 ;
else
V_46 = 60 ;
if ( V_44 < V_46 || V_44 > ( V_46 * 255 ) )
return - V_32 ;
F_14 ( & V_4 -> V_49 ) ;
if ( ! V_4 -> V_50 ) {
V_45 = - V_51 ;
goto V_52;
}
if ( V_46 == 2 )
V_4 -> V_53 &= ~ V_54 ;
else
V_4 -> V_53 |= V_54 ;
V_4 -> V_55 = F_34 ( V_44 , V_46 ) ;
F_15 ( V_4 -> V_50 ,
V_56 [ V_4 -> V_12 ] , V_4 -> V_55 ) ;
F_15 ( V_4 -> V_50 ,
V_57 [ V_4 -> V_12 ] ,
V_4 -> V_53 & ~ V_58 ) ;
V_45 = V_4 -> V_55 * V_46 ;
V_52:
F_17 ( & V_4 -> V_49 ) ;
return V_45 ;
}
static int F_35 ( struct V_3 * V_4 )
{
int V_44 ;
F_14 ( & V_4 -> V_49 ) ;
if ( V_4 -> V_53 & V_54 )
V_44 = V_4 -> V_55 * 60 ;
else
V_44 = V_4 -> V_55 * 2 ;
F_17 ( & V_4 -> V_49 ) ;
return V_44 ;
}
static int F_36 ( struct V_3 * V_4 )
{
int V_45 = 0 ;
F_14 ( & V_4 -> V_49 ) ;
if ( ! V_4 -> V_50 ) {
V_45 = - V_51 ;
goto V_52;
}
V_4 -> V_53 |= V_58 ;
F_15 ( V_4 -> V_50 ,
V_57 [ V_4 -> V_12 ] ,
V_4 -> V_53 ) ;
V_52:
F_17 ( & V_4 -> V_49 ) ;
return V_45 ;
}
static int F_37 ( struct V_3 * V_4 )
{
int V_45 = 0 ;
F_14 ( & V_4 -> V_49 ) ;
if ( ! V_4 -> V_50 ) {
V_45 = - V_51 ;
goto V_52;
}
V_4 -> V_53 &= ~ V_59 ;
F_15 ( V_4 -> V_50 ,
V_57 [ V_4 -> V_12 ] ,
V_4 -> V_53 | V_60 ) ;
V_52:
F_17 ( & V_4 -> V_49 ) ;
return V_45 ;
}
static int F_38 ( struct V_61 * V_61 , struct V_62 * V_63 )
{
struct V_3 * V_64 , * V_4 = NULL ;
int V_65 ;
if ( ! F_39 ( & V_66 ) )
return - V_67 ;
F_40 (pos, &watchdog_data_list, list) {
if ( V_64 -> V_68 . V_69 == F_41 ( V_61 ) ) {
V_4 = V_64 ;
break;
}
}
V_65 = F_42 ( 0 , & V_4 -> V_65 ) ;
if ( ! V_65 )
F_43 ( & V_4 -> V_1 ) ;
F_17 ( & V_66 ) ;
if ( V_65 )
return - V_70 ;
F_36 ( V_4 ) ;
V_63 -> V_71 = V_4 ;
return F_44 ( V_61 , V_63 ) ;
}
static int F_45 ( struct V_61 * V_61 , struct V_62 * V_63 )
{
struct V_3 * V_4 = V_63 -> V_71 ;
if ( V_4 -> V_72 ) {
F_37 ( V_4 ) ;
V_4 -> V_72 = 0 ;
} else {
F_36 ( V_4 ) ;
F_46 ( & V_4 -> V_50 -> V_6 ,
L_6 ) ;
}
F_47 ( 0 , & V_4 -> V_65 ) ;
F_14 ( & V_66 ) ;
F_48 ( & V_4 -> V_1 , F_1 ) ;
F_17 ( & V_66 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_62 * V_63 , const char T_4 * V_9 ,
T_2 V_21 , T_5 * V_73 )
{
int V_45 ;
struct V_3 * V_4 = V_63 -> V_71 ;
if ( V_21 ) {
if ( ! V_74 ) {
T_2 V_75 ;
V_4 -> V_72 = 0 ;
for ( V_75 = 0 ; V_75 != V_21 ; V_75 ++ ) {
char V_76 ;
if ( F_50 ( V_76 , V_9 + V_75 ) )
return - V_77 ;
if ( V_76 == 'V' )
V_4 -> V_72 = 1 ;
}
}
V_45 = F_36 ( V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return V_21 ;
}
static long F_51 ( struct V_62 * V_63 , unsigned int V_78 ,
unsigned long V_79 )
{
struct V_80 V_81 = {
. V_82 = V_83 | V_84 |
V_85 ,
. V_86 = L_7
} ;
int V_75 , V_45 = 0 ;
struct V_3 * V_4 = V_63 -> V_71 ;
switch ( V_78 ) {
case V_87 :
V_81 . V_88 = V_4 -> V_89 ;
if ( ! V_74 )
V_81 . V_82 |= V_90 ;
if ( F_52 ( ( void T_4 * ) V_79 , & V_81 , sizeof( V_81 ) ) )
V_45 = - V_77 ;
break;
case V_91 :
V_45 = F_53 ( 0 , ( int T_4 * ) V_79 ) ;
break;
case V_92 :
if ( V_4 -> V_93 & V_94 )
V_45 = F_53 ( V_85 , ( int T_4 * ) V_79 ) ;
else
V_45 = F_53 ( 0 , ( int T_4 * ) V_79 ) ;
break;
case V_95 :
V_45 = F_36 ( V_4 ) ;
break;
case V_96 :
V_75 = F_35 ( V_4 ) ;
V_45 = F_53 ( V_75 , ( int T_4 * ) V_79 ) ;
break;
case V_97 :
if ( F_50 ( V_75 , ( int T_4 * ) V_79 ) ) {
V_45 = - V_77 ;
break;
}
V_45 = F_33 ( V_4 , V_75 ) ;
if ( V_45 > 0 )
V_45 = F_53 ( V_45 , ( int T_4 * ) V_79 ) ;
break;
case V_98 :
if ( F_50 ( V_75 , ( int T_4 * ) V_79 ) ) {
V_45 = - V_77 ;
break;
}
if ( V_75 & V_99 )
V_45 = F_37 ( V_4 ) ;
else if ( V_75 & V_100 )
V_45 = F_36 ( V_4 ) ;
else
V_45 = - V_32 ;
break;
default:
V_45 = - V_101 ;
}
return V_45 ;
}
static void F_54 ( const struct V_102 * V_103 , void * V_104 )
{
int V_75 , V_105 [ 3 ] = { 0 } , V_73 [ 3 ] = { 0 } , V_106 = 0 , V_107 = 0 ;
T_3 * V_108 = ( T_3 * ) V_103 ;
if ( V_103 -> type != 185 )
return;
if ( V_103 -> V_109 < 5 || V_108 [ 4 ] != 19 )
return;
for ( V_75 = 6 ; ( V_75 + 4 ) < V_103 -> V_109 ; V_75 += 5 ) {
if ( V_108 [ V_75 ] >= 1 && V_108 [ V_75 ] <= 3 ) {
const int V_110 [ 3 ] = { 1 , 0 , 2 } ;
int V_111 = V_110 [ V_108 [ V_75 ] - 1 ] ;
if ( V_107 & ( 1 << V_111 ) )
return;
V_105 [ V_111 ] = V_108 [ V_75 + 1 ] | ( V_108 [ V_75 + 2 ] << 8 ) ;
V_73 [ V_111 ] = V_108 [ V_75 + 3 ] | ( V_108 [ V_75 + 4 ] << 8 ) ;
V_107 |= 1 << V_111 ;
}
if ( V_108 [ V_75 ] == 7 ) {
if ( V_107 & 0x08 )
return;
V_106 = V_108 [ V_75 + 1 ] | ( V_108 [ V_75 + 2 ] << 8 ) ;
V_107 |= 0x08 ;
}
}
if ( V_107 == 0x0F ) {
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
V_17 [ V_75 ] = V_105 [ V_75 ] * 10 ;
V_18 [ V_75 ] = V_73 [ V_75 ] * 10 ;
}
V_17 [ 3 ] = V_17 [ 2 ] ;
V_17 [ 4 ] = V_17 [ 1 ] ;
V_17 [ 5 ] = V_17 [ 2 ] ;
V_18 [ 3 ] = V_18 [ 2 ] ;
V_18 [ 4 ] = V_18 [ 1 ] ;
V_18 [ 5 ] = V_18 [ 2 ] ;
V_16 = V_106 ;
}
}
static int F_55 ( struct V_112 * V_50 ,
struct V_113 * V_114 )
{
enum V_115 V_12 ;
struct V_116 * V_117 = V_50 -> V_117 ;
char V_118 [ 4 ] ;
if ( ! F_56 ( V_117 , V_119 ) )
return - V_51 ;
V_118 [ 0 ] = F_26 ( V_50 , V_120 ) ;
V_118 [ 1 ] = F_26 ( V_50 , V_121 ) ;
V_118 [ 2 ] = F_26 ( V_50 , V_122 ) ;
V_118 [ 3 ] = '\0' ;
if ( ! strcmp ( V_118 , L_8 ) )
V_12 = V_47 ;
else if ( ! strcmp ( V_118 , L_9 ) )
V_12 = V_13 ;
else if ( ! strcmp ( V_118 , L_10 ) )
V_12 = V_48 ;
else if ( ! strcmp ( V_118 , L_11 ) )
V_12 = V_14 ;
else if ( ! strcmp ( V_118 , L_12 ) )
V_12 = V_123 ;
else if ( ! strcmp ( V_118 , L_13 ) )
V_12 = V_124 ;
else if ( ! strcmp ( V_118 , L_14 ) )
V_12 = V_39 ;
else
return - V_51 ;
F_57 ( V_114 -> type , V_125 [ V_12 ] . V_126 , V_127 ) ;
return 0 ;
}
static int F_58 ( struct V_112 * V_50 ,
const struct V_128 * V_118 )
{
struct V_3 * V_4 ;
const char * const V_129 [ 7 ] = { L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 } ;
const int V_130 [] = { V_131 , 212 , 213 , 214 , 215 } ;
int V_75 , V_23 ;
enum V_115 V_12 = V_118 -> V_132 ;
V_4 = F_59 ( sizeof( struct V_3 ) , V_133 ) ;
if ( ! V_4 )
return - V_134 ;
F_60 ( V_50 , V_4 ) ;
F_61 ( & V_4 -> V_24 ) ;
F_61 ( & V_4 -> V_49 ) ;
F_62 ( & V_4 -> V_135 ) ;
F_63 ( & V_4 -> V_1 ) ;
V_4 -> V_50 = V_50 ;
V_4 -> V_12 = V_12 ;
if ( V_12 == V_47 ) {
V_4 -> V_20 [ 0 ] = 70 + 128 ;
V_4 -> V_20 [ 1 ] = 50 + 128 ;
V_4 -> V_20 [ 2 ] = 50 + 128 ;
}
if ( ( V_12 == V_13 || V_12 >= V_14 ) && V_16 == - 1 ) {
F_64 ( F_54 , NULL ) ;
if ( V_16 == - 1 ) {
F_65 ( & V_50 -> V_6 ,
L_22
L_23 ) ;
V_16 = 33 ;
}
}
V_4 -> V_89 = F_26 ( V_50 , V_136 ) ;
V_4 -> V_41 = F_26 ( V_50 ,
V_43 ) ;
V_4 -> V_53 = F_26 ( V_50 ,
V_57 [ V_4 -> V_12 ] ) ;
V_4 -> V_93 = F_26 ( V_50 ,
V_137 [ V_4 -> V_12 ] ) ;
V_4 -> V_55 = F_26 ( V_50 ,
V_56 [ V_4 -> V_12 ] ) ;
V_23 = F_66 ( & V_50 -> V_6 , & V_138 ) ;
if ( V_23 )
goto V_139;
for ( V_75 = 0 ; V_75 < V_140 [ V_4 -> V_12 ] ; V_75 ++ ) {
V_23 = F_66 ( & V_50 -> V_6 ,
& V_141 [ V_75 ] . V_142 ) ;
if ( V_23 )
goto V_139;
}
for ( V_75 = 0 ; V_75 < ( V_143 [ V_4 -> V_12 ] * 4 ) ; V_75 ++ ) {
if ( V_12 == V_47 && V_144 [ V_75 ] . V_142 . V_145 ==
F_9 )
continue;
if ( V_12 == V_39 ) {
if ( V_75 % 4 == 0 )
V_4 -> V_26 [ V_75 / 4 ] =
F_26 ( V_50 ,
V_146
[ V_4 -> V_12 ] [ V_75 / 4 ] ) ;
if ( V_4 -> V_26 [ V_75 / 4 ] & V_147 )
continue;
}
V_23 = F_66 ( & V_50 -> V_6 ,
& V_144 [ V_75 ] . V_142 ) ;
if ( V_23 )
goto V_139;
}
for ( V_75 = 0 ; V_75 < ( V_148 [ V_4 -> V_12 ] * 5 ) ; V_75 ++ ) {
if ( V_12 == V_47 &&
! strcmp ( V_149 [ V_75 ] . V_142 . V_150 . V_126 ,
L_24 ) )
continue;
if ( V_12 == V_39 ) {
if ( V_75 % 5 == 0 )
V_4 -> V_34 [ V_75 / 5 ] =
F_26 ( V_50 ,
V_151
[ V_4 -> V_12 ] [ V_75 / 5 ] ) ;
if ( V_4 -> V_34 [ V_75 / 5 ] & V_152 )
continue;
}
V_23 = F_66 ( & V_50 -> V_6 ,
& V_149 [ V_75 ] . V_142 ) ;
if ( V_23 )
goto V_139;
}
V_4 -> V_153 = F_67 ( & V_50 -> V_6 ) ;
if ( F_68 ( V_4 -> V_153 ) ) {
V_23 = F_69 ( V_4 -> V_153 ) ;
V_4 -> V_153 = NULL ;
goto V_139;
}
F_14 ( & V_66 ) ;
for ( V_75 = 0 ; V_75 < F_70 ( V_130 ) ; V_75 ++ ) {
snprintf ( V_4 -> V_154 , sizeof( V_4 -> V_154 ) ,
L_25 , ( V_75 == 0 ) ? '\0' : ( '0' + V_75 ) ) ;
V_4 -> V_68 . V_126 = V_4 -> V_154 ;
V_4 -> V_68 . V_155 = & V_156 ;
V_4 -> V_68 . V_69 = V_130 [ V_75 ] ;
V_23 = F_71 ( & V_4 -> V_68 ) ;
if ( V_23 == - V_70 )
continue;
if ( V_23 ) {
V_4 -> V_68 . V_69 = 0 ;
F_25 ( & V_50 -> V_6 ,
L_26 , V_23 ) ;
break;
}
F_72 ( & V_4 -> V_135 , & V_157 ) ;
F_33 ( V_4 , 60 ) ;
F_73 ( & V_50 -> V_6 ,
L_27 ,
V_130 [ V_75 ] ) ;
break;
}
if ( V_75 == F_70 ( V_130 ) ) {
V_4 -> V_68 . V_69 = 0 ;
F_65 ( & V_50 -> V_6 ,
L_28 ) ;
}
F_17 ( & V_66 ) ;
F_73 ( & V_50 -> V_6 , L_29 ,
V_129 [ V_4 -> V_12 ] , ( int ) V_4 -> V_89 ) ;
return 0 ;
V_139:
F_74 ( V_50 ) ;
return V_23 ;
}
static int F_74 ( struct V_112 * V_50 )
{
struct V_3 * V_4 = F_75 ( V_50 ) ;
int V_75 ;
if ( V_4 -> V_68 . V_69 ) {
F_76 ( & V_4 -> V_68 ) ;
if ( V_4 -> V_65 ) {
F_65 ( & V_50 -> V_6 ,
L_30
L_31 ) ;
F_37 ( V_4 ) ;
}
F_14 ( & V_66 ) ;
F_77 ( & V_4 -> V_135 ) ;
F_17 ( & V_66 ) ;
F_14 ( & V_4 -> V_49 ) ;
V_4 -> V_50 = NULL ;
F_17 ( & V_4 -> V_49 ) ;
}
if ( V_4 -> V_153 )
F_78 ( V_4 -> V_153 ) ;
F_79 ( & V_50 -> V_6 , & V_138 ) ;
for ( V_75 = 0 ; V_75 < ( V_140 [ V_4 -> V_12 ] ) ; V_75 ++ )
F_79 ( & V_50 -> V_6 , & V_141 [ V_75 ] . V_142 ) ;
for ( V_75 = 0 ; V_75 < ( V_143 [ V_4 -> V_12 ] * 4 ) ; V_75 ++ )
F_79 ( & V_50 -> V_6 ,
& V_144 [ V_75 ] . V_142 ) ;
for ( V_75 = 0 ; V_75 < ( V_148 [ V_4 -> V_12 ] * 5 ) ; V_75 ++ )
F_79 ( & V_50 -> V_6 ,
& V_149 [ V_75 ] . V_142 ) ;
F_14 ( & V_66 ) ;
F_48 ( & V_4 -> V_1 , F_1 ) ;
F_17 ( & V_66 ) ;
return 0 ;
}
static struct V_3 * F_6 ( struct V_5 * V_6 )
{
struct V_112 * V_50 = F_16 ( V_6 ) ;
struct V_3 * V_4 = F_75 ( V_50 ) ;
int V_75 ;
F_14 ( & V_4 -> V_24 ) ;
if ( F_80 ( V_158 , V_4 -> V_159 + 2 * V_160 ) || ! V_4 -> V_161 ) {
for ( V_75 = 0 ; V_75 < V_143 [ V_4 -> V_12 ] ; V_75 ++ ) {
V_4 -> V_19 [ V_75 ] = F_26 ( V_50 ,
V_162 [ V_4 -> V_12 ] [ V_75 ] ) ;
V_4 -> V_26 [ V_75 ] = F_26 ( V_50 ,
V_146 [ V_4 -> V_12 ] [ V_75 ] ) ;
if ( V_25 [ V_4 -> V_12 ] [ V_75 ] )
V_4 -> V_20 [ V_75 ] = F_26 (
V_50 ,
V_25 [ V_4 -> V_12 ] [ V_75 ] ) ;
if ( ( V_4 -> V_26 [ V_75 ] & V_28 ) ==
V_28 &&
V_4 -> V_19 [ V_75 ] < V_4 -> V_20 [ V_75 ] )
F_15 ( V_50 ,
V_146 [ V_4 -> V_12 ] [ V_75 ] ,
V_4 -> V_26 [ V_75 ] ) ;
}
for ( V_75 = 0 ; V_75 < V_148 [ V_4 -> V_12 ] ; V_75 ++ ) {
V_4 -> V_29 [ V_75 ] = F_26 ( V_50 ,
V_163 [ V_4 -> V_12 ] [ V_75 ] ) ;
V_4 -> V_34 [ V_75 ] = F_26 ( V_50 ,
V_151 [ V_4 -> V_12 ] [ V_75 ] ) ;
V_4 -> V_30 [ V_75 ] = F_26 ( V_50 ,
V_33 [ V_4 -> V_12 ] [ V_75 ] ) ;
if ( V_40 [ V_4 -> V_12 ] [ V_75 ] )
V_4 -> V_38 [ V_75 ] = F_26 (
V_50 ,
V_40 [ V_4 -> V_12 ] [ V_75 ] ) ;
if ( ( V_4 -> V_34 [ V_75 ] & V_35 ) &&
V_4 -> V_29 [ V_75 ] )
F_15 ( V_50 ,
V_151 [ V_4 -> V_12 ] [ V_75 ] ,
V_4 -> V_34 [ V_75 ] ) ;
}
for ( V_75 = 0 ; V_75 < V_140 [ V_4 -> V_12 ] ; V_75 ++ )
V_4 -> V_15 [ V_75 ] = F_26 ( V_50 ,
V_164 [ V_4 -> V_12 ] [ V_75 ] ) ;
V_4 -> V_159 = V_158 ;
V_4 -> V_161 = 1 ;
}
F_17 ( & V_4 -> V_24 ) ;
return V_4 ;
}
