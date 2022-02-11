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
long V_22 = F_12 ( V_9 , NULL , 10 ) / 1000 ;
V_22 = F_13 ( V_22 , - 128 , 127 ) + 128 ;
F_14 ( & V_4 -> V_23 ) ;
F_15 ( F_16 ( V_6 ) ,
V_24 [ V_4 -> V_12 ] [ V_11 ] , V_22 ) ;
V_4 -> V_20 [ V_11 ] = V_22 ;
F_17 ( & V_4 -> V_23 ) ;
return V_21 ;
}
static T_1 F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_25 [ V_11 ] & V_26 )
return sprintf ( V_9 , L_2 ) ;
else
return sprintf ( V_9 , L_3 ) ;
}
static T_1 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( ( V_4 -> V_25 [ V_11 ] & V_27 ) ==
V_27 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_4 , F_21 ( V_4 -> V_28 [ V_11 ] ) ) ;
}
static T_1 F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
return sprintf ( V_9 , L_1 , 1 << ( V_4 -> V_29 [ V_11 ] & 3 ) ) ;
}
static T_1 F_23 ( struct V_5 * V_6 , struct V_7
* V_8 , const char * V_9 , T_2 V_21 )
{
T_3 V_30 ;
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 = F_24 ( V_9 , NULL , 10 ) ;
switch ( V_22 ) {
case 2 : V_22 = 1 ; break;
case 4 : V_22 = 2 ; break;
case 8 : V_22 = 3 ; break;
default:
F_25 ( V_6 , L_5
L_6 , V_22 ) ;
return - V_31 ;
}
F_14 ( & V_4 -> V_23 ) ;
V_30 = F_26 ( F_16 ( V_6 ) ,
V_32 [ V_4 -> V_12 ] [ V_11 ] ) ;
V_30 &= ~ 0x03 ;
V_30 |= V_22 ;
F_15 ( F_16 ( V_6 ) ,
V_32 [ V_4 -> V_12 ] [ V_11 ] , V_30 ) ;
V_4 -> V_29 [ V_11 ] = V_30 ;
F_17 ( & V_4 -> V_23 ) ;
return V_21 ;
}
static T_1 F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_33 [ V_11 ] & V_34 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_33 [ V_11 ] & V_35 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_6 ( V_6 ) ;
int V_36 = V_4 -> V_37 [ V_11 ] ;
if ( V_36 || V_4 -> V_12 == V_38 )
V_36 = V_36 / 2 + 128 ;
return sprintf ( V_9 , L_1 , V_36 ) ;
}
static T_1 F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 , T_2 V_21 )
{
int V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 = F_24 ( V_9 , NULL , 10 ) ;
if ( V_22 || V_4 -> V_12 == V_38 ) {
V_22 = F_13 ( V_22 , 128 , 255 ) ;
V_22 = ( V_22 - 128 ) * 2 + 1 ;
}
F_14 ( & V_4 -> V_23 ) ;
F_15 ( F_16 ( V_6 ) ,
V_39 [ V_4 -> V_12 ] [ V_11 ] , V_22 ) ;
V_4 -> V_37 [ V_11 ] = V_22 ;
F_17 ( & V_4 -> V_23 ) ;
return V_21 ;
}
static T_1 F_31 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_3 * V_4 = F_6 ( V_6 ) ;
if ( V_4 -> V_40 & V_41 )
return sprintf ( V_9 , L_3 ) ;
else
return sprintf ( V_9 , L_2 ) ;
}
static T_1 F_32 ( struct V_5 * V_6 ,
struct V_7 * V_8 , const char * V_9 , T_2 V_21 )
{
T_3 V_30 ;
struct V_3 * V_4 = F_11 ( V_6 ) ;
unsigned long V_22 = F_24 ( V_9 , NULL , 10 ) ;
F_14 ( & V_4 -> V_23 ) ;
V_30 = F_26 ( F_16 ( V_6 ) , V_42 ) ;
if ( V_22 )
V_30 |= V_41 ;
else
V_30 &= ~ V_41 ;
F_15 ( F_16 ( V_6 ) , V_42 , V_30 ) ;
V_4 -> V_40 = V_30 ;
F_17 ( & V_4 -> V_23 ) ;
return V_21 ;
}
static int F_33 ( struct V_3 * V_4 , int V_43 )
{
int V_44 , V_45 ;
int V_12 = V_4 -> V_12 + 1 ;
if ( V_43 <= 510 || V_12 == V_46 || V_12 == V_47 )
V_45 = 2 ;
else
V_45 = 60 ;
if ( V_43 < V_45 || V_43 > ( V_45 * 255 ) )
return - V_31 ;
F_14 ( & V_4 -> V_48 ) ;
if ( ! V_4 -> V_49 ) {
V_44 = - V_50 ;
goto V_51;
}
if ( V_45 == 2 )
V_4 -> V_52 &= ~ V_53 ;
else
V_4 -> V_52 |= V_53 ;
V_4 -> V_54 = F_34 ( V_43 , V_45 ) ;
F_15 ( V_4 -> V_49 ,
V_55 [ V_4 -> V_12 ] , V_4 -> V_54 ) ;
F_15 ( V_4 -> V_49 ,
V_56 [ V_4 -> V_12 ] ,
V_4 -> V_52 & ~ V_57 ) ;
V_44 = V_4 -> V_54 * V_45 ;
V_51:
F_17 ( & V_4 -> V_48 ) ;
return V_44 ;
}
static int F_35 ( struct V_3 * V_4 )
{
int V_43 ;
F_14 ( & V_4 -> V_48 ) ;
if ( V_4 -> V_52 & V_53 )
V_43 = V_4 -> V_54 * 60 ;
else
V_43 = V_4 -> V_54 * 2 ;
F_17 ( & V_4 -> V_48 ) ;
return V_43 ;
}
static int F_36 ( struct V_3 * V_4 )
{
int V_44 = 0 ;
F_14 ( & V_4 -> V_48 ) ;
if ( ! V_4 -> V_49 ) {
V_44 = - V_50 ;
goto V_51;
}
V_4 -> V_52 |= V_57 ;
F_15 ( V_4 -> V_49 ,
V_56 [ V_4 -> V_12 ] ,
V_4 -> V_52 ) ;
V_51:
F_17 ( & V_4 -> V_48 ) ;
return V_44 ;
}
static int F_37 ( struct V_3 * V_4 )
{
int V_44 = 0 ;
F_14 ( & V_4 -> V_48 ) ;
if ( ! V_4 -> V_49 ) {
V_44 = - V_50 ;
goto V_51;
}
V_4 -> V_52 &= ~ V_58 ;
F_15 ( V_4 -> V_49 ,
V_56 [ V_4 -> V_12 ] ,
V_4 -> V_52 | V_59 ) ;
V_51:
F_17 ( & V_4 -> V_48 ) ;
return V_44 ;
}
static int F_38 ( struct V_60 * V_60 , struct V_61 * V_62 )
{
struct V_3 * V_63 , * V_4 = NULL ;
int V_64 ;
if ( ! F_39 ( & V_65 ) )
return - V_66 ;
F_40 (pos, &watchdog_data_list, list) {
if ( V_63 -> V_67 . V_68 == F_41 ( V_60 ) ) {
V_4 = V_63 ;
break;
}
}
V_64 = F_42 ( 0 , & V_4 -> V_64 ) ;
if ( ! V_64 )
F_43 ( & V_4 -> V_1 ) ;
F_17 ( & V_65 ) ;
if ( V_64 )
return - V_69 ;
F_36 ( V_4 ) ;
V_62 -> V_70 = V_4 ;
return F_44 ( V_60 , V_62 ) ;
}
static int F_45 ( struct V_60 * V_60 , struct V_61 * V_62 )
{
struct V_3 * V_4 = V_62 -> V_70 ;
if ( V_4 -> V_71 ) {
F_37 ( V_4 ) ;
V_4 -> V_71 = 0 ;
} else {
F_36 ( V_4 ) ;
F_46 ( & V_4 -> V_49 -> V_6 ,
L_7 ) ;
}
F_47 ( 0 , & V_4 -> V_64 ) ;
F_14 ( & V_65 ) ;
F_48 ( & V_4 -> V_1 , F_1 ) ;
F_17 ( & V_65 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_61 * V_62 , const char T_4 * V_9 ,
T_2 V_21 , T_5 * V_72 )
{
int V_44 ;
struct V_3 * V_4 = V_62 -> V_70 ;
if ( V_21 ) {
if ( ! V_73 ) {
T_2 V_74 ;
V_4 -> V_71 = 0 ;
for ( V_74 = 0 ; V_74 != V_21 ; V_74 ++ ) {
char V_75 ;
if ( F_50 ( V_75 , V_9 + V_74 ) )
return - V_76 ;
if ( V_75 == 'V' )
V_4 -> V_71 = 1 ;
}
}
V_44 = F_36 ( V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return V_21 ;
}
static long F_51 ( struct V_61 * V_62 , unsigned int V_77 , unsigned long V_78 )
{
struct V_79 V_80 = {
. V_81 = V_82 | V_83 |
V_84 ,
. V_85 = L_8
} ;
int V_74 , V_44 = 0 ;
struct V_3 * V_4 = V_62 -> V_70 ;
switch ( V_77 ) {
case V_86 :
V_80 . V_87 = V_4 -> V_88 ;
if ( ! V_73 )
V_80 . V_81 |= V_89 ;
if ( F_52 ( ( void T_4 * ) V_78 , & V_80 , sizeof( V_80 ) ) )
V_44 = - V_76 ;
break;
case V_90 :
V_44 = F_53 ( 0 , ( int T_4 * ) V_78 ) ;
break;
case V_91 :
if ( V_4 -> V_92 & V_93 )
V_44 = F_53 ( V_84 , ( int T_4 * ) V_78 ) ;
else
V_44 = F_53 ( 0 , ( int T_4 * ) V_78 ) ;
break;
case V_94 :
V_44 = F_36 ( V_4 ) ;
break;
case V_95 :
V_74 = F_35 ( V_4 ) ;
V_44 = F_53 ( V_74 , ( int T_4 * ) V_78 ) ;
break;
case V_96 :
if ( F_50 ( V_74 , ( int T_4 * ) V_78 ) ) {
V_44 = - V_76 ;
break;
}
V_44 = F_33 ( V_4 , V_74 ) ;
if ( V_44 > 0 )
V_44 = F_53 ( V_44 , ( int T_4 * ) V_78 ) ;
break;
case V_97 :
if ( F_50 ( V_74 , ( int T_4 * ) V_78 ) ) {
V_44 = - V_76 ;
break;
}
if ( V_74 & V_98 )
V_44 = F_37 ( V_4 ) ;
else if ( V_74 & V_99 )
V_44 = F_36 ( V_4 ) ;
else
V_44 = - V_31 ;
break;
default:
V_44 = - V_100 ;
}
return V_44 ;
}
static void F_54 ( const struct V_101 * V_102 , void * V_103 )
{
int V_74 , V_104 [ 3 ] = { 0 } , V_72 [ 3 ] = { 0 } , V_105 = 0 , V_106 = 0 ;
T_3 * V_107 = ( T_3 * ) V_102 ;
if ( V_102 -> type != 185 )
return;
if ( V_102 -> V_108 < 5 || V_107 [ 4 ] != 19 )
return;
for ( V_74 = 6 ; ( V_74 + 4 ) < V_102 -> V_108 ; V_74 += 5 ) {
if ( V_107 [ V_74 ] >= 1 && V_107 [ V_74 ] <= 3 ) {
const int V_109 [ 3 ] = { 1 , 0 , 2 } ;
int V_110 = V_109 [ V_107 [ V_74 ] - 1 ] ;
if ( V_106 & ( 1 << V_110 ) )
return;
V_104 [ V_110 ] = V_107 [ V_74 + 1 ] | ( V_107 [ V_74 + 2 ] << 8 ) ;
V_72 [ V_110 ] = V_107 [ V_74 + 3 ] | ( V_107 [ V_74 + 4 ] << 8 ) ;
V_106 |= 1 << V_110 ;
}
if ( V_107 [ V_74 ] == 7 ) {
if ( V_106 & 0x08 )
return;
V_105 = V_107 [ V_74 + 1 ] | ( V_107 [ V_74 + 2 ] << 8 ) ;
V_106 |= 0x08 ;
}
}
if ( V_106 == 0x0F ) {
for ( V_74 = 0 ; V_74 < 3 ; V_74 ++ ) {
V_17 [ V_74 ] = V_104 [ V_74 ] * 10 ;
V_18 [ V_74 ] = V_72 [ V_74 ] * 10 ;
}
V_17 [ 3 ] = V_17 [ 2 ] ;
V_17 [ 4 ] = V_17 [ 1 ] ;
V_17 [ 5 ] = V_17 [ 2 ] ;
V_18 [ 3 ] = V_18 [ 2 ] ;
V_18 [ 4 ] = V_18 [ 1 ] ;
V_18 [ 5 ] = V_18 [ 2 ] ;
V_16 = V_105 ;
}
}
static int F_55 ( struct V_111 * V_49 ,
struct V_112 * V_113 )
{
enum V_114 V_12 ;
struct V_115 * V_116 = V_49 -> V_116 ;
char V_117 [ 4 ] ;
if ( ! F_56 ( V_116 , V_118 ) )
return - V_50 ;
V_117 [ 0 ] = F_26 ( V_49 , V_119 ) ;
V_117 [ 1 ] = F_26 ( V_49 , V_120 ) ;
V_117 [ 2 ] = F_26 ( V_49 , V_121 ) ;
V_117 [ 3 ] = '\0' ;
if ( ! strcmp ( V_117 , L_9 ) )
V_12 = V_46 ;
else if ( ! strcmp ( V_117 , L_10 ) )
V_12 = V_13 ;
else if ( ! strcmp ( V_117 , L_11 ) )
V_12 = V_47 ;
else if ( ! strcmp ( V_117 , L_12 ) )
V_12 = V_14 ;
else if ( ! strcmp ( V_117 , L_13 ) )
V_12 = V_122 ;
else if ( ! strcmp ( V_117 , L_14 ) )
V_12 = V_123 ;
else if ( ! strcmp ( V_117 , L_15 ) )
V_12 = V_38 ;
else
return - V_50 ;
F_57 ( V_113 -> type , V_124 [ V_12 ] . V_125 , V_126 ) ;
return 0 ;
}
static int F_58 ( struct V_111 * V_49 ,
const struct V_127 * V_117 )
{
struct V_3 * V_4 ;
const char * const V_128 [ 7 ] = { L_16 , L_17 , L_18 ,
L_19 , L_20 , L_21 , L_22 } ;
const int V_129 [] = { V_130 , 212 , 213 , 214 , 215 } ;
int V_74 , V_131 ;
enum V_114 V_12 = V_117 -> V_132 ;
V_4 = F_59 ( sizeof( struct V_3 ) , V_133 ) ;
if ( ! V_4 )
return - V_134 ;
F_60 ( V_49 , V_4 ) ;
F_61 ( & V_4 -> V_23 ) ;
F_61 ( & V_4 -> V_48 ) ;
F_62 ( & V_4 -> V_135 ) ;
F_63 ( & V_4 -> V_1 ) ;
V_4 -> V_49 = V_49 ;
V_4 -> V_12 = V_12 ;
if ( V_12 == V_46 ) {
V_4 -> V_20 [ 0 ] = 70 + 128 ;
V_4 -> V_20 [ 1 ] = 50 + 128 ;
V_4 -> V_20 [ 2 ] = 50 + 128 ;
}
if ( ( V_12 == V_13 || V_12 >= V_14 ) && V_16 == - 1 ) {
F_64 ( F_54 , NULL ) ;
if ( V_16 == - 1 ) {
F_65 ( & V_49 -> V_6 ,
L_23
L_24 ) ;
V_16 = 33 ;
}
}
V_4 -> V_88 = F_26 ( V_49 , V_136 ) ;
V_4 -> V_40 = F_26 ( V_49 ,
V_42 ) ;
V_4 -> V_52 = F_26 ( V_49 ,
V_56 [ V_4 -> V_12 ] ) ;
V_4 -> V_92 = F_26 ( V_49 ,
V_137 [ V_4 -> V_12 ] ) ;
V_4 -> V_54 = F_26 ( V_49 ,
V_55 [ V_4 -> V_12 ] ) ;
V_131 = F_66 ( & V_49 -> V_6 , & V_138 ) ;
if ( V_131 )
goto V_139;
for ( V_74 = 0 ; V_74 < V_140 [ V_4 -> V_12 ] ; V_74 ++ ) {
V_131 = F_66 ( & V_49 -> V_6 ,
& V_141 [ V_74 ] . V_142 ) ;
if ( V_131 )
goto V_139;
}
for ( V_74 = 0 ; V_74 < ( V_143 [ V_4 -> V_12 ] * 4 ) ; V_74 ++ ) {
if ( V_12 == V_46 && V_144 [ V_74 ] . V_142 . V_145 ==
F_9 )
continue;
if ( V_12 == V_38 ) {
if ( V_74 % 4 == 0 )
V_4 -> V_25 [ V_74 / 4 ] =
F_26 ( V_49 ,
V_146
[ V_4 -> V_12 ] [ V_74 / 4 ] ) ;
if ( V_4 -> V_25 [ V_74 / 4 ] & V_147 )
continue;
}
V_131 = F_66 ( & V_49 -> V_6 ,
& V_144 [ V_74 ] . V_142 ) ;
if ( V_131 )
goto V_139;
}
for ( V_74 = 0 ; V_74 < ( V_148 [ V_4 -> V_12 ] * 5 ) ; V_74 ++ ) {
if ( V_12 == V_46 &&
! strcmp ( V_149 [ V_74 ] . V_142 . V_150 . V_125 ,
L_25 ) )
continue;
if ( V_12 == V_38 ) {
if ( V_74 % 5 == 0 )
V_4 -> V_33 [ V_74 / 5 ] =
F_26 ( V_49 ,
V_151
[ V_4 -> V_12 ] [ V_74 / 5 ] ) ;
if ( V_4 -> V_33 [ V_74 / 5 ] & V_152 )
continue;
}
V_131 = F_66 ( & V_49 -> V_6 ,
& V_149 [ V_74 ] . V_142 ) ;
if ( V_131 )
goto V_139;
}
V_4 -> V_153 = F_67 ( & V_49 -> V_6 ) ;
if ( F_68 ( V_4 -> V_153 ) ) {
V_131 = F_69 ( V_4 -> V_153 ) ;
V_4 -> V_153 = NULL ;
goto V_139;
}
F_14 ( & V_65 ) ;
for ( V_74 = 0 ; V_74 < F_70 ( V_129 ) ; V_74 ++ ) {
snprintf ( V_4 -> V_154 , sizeof( V_4 -> V_154 ) ,
L_26 , ( V_74 == 0 ) ? '\0' : ( '0' + V_74 ) ) ;
V_4 -> V_67 . V_125 = V_4 -> V_154 ;
V_4 -> V_67 . V_155 = & V_156 ;
V_4 -> V_67 . V_68 = V_129 [ V_74 ] ;
V_131 = F_71 ( & V_4 -> V_67 ) ;
if ( V_131 == - V_69 )
continue;
if ( V_131 ) {
V_4 -> V_67 . V_68 = 0 ;
F_25 ( & V_49 -> V_6 ,
L_27 , V_131 ) ;
break;
}
F_72 ( & V_4 -> V_135 , & V_157 ) ;
F_33 ( V_4 , 60 ) ;
F_73 ( & V_49 -> V_6 ,
L_28 ,
V_129 [ V_74 ] ) ;
break;
}
if ( V_74 == F_70 ( V_129 ) ) {
V_4 -> V_67 . V_68 = 0 ;
F_65 ( & V_49 -> V_6 , L_29
L_30 ) ;
}
F_17 ( & V_65 ) ;
F_73 ( & V_49 -> V_6 , L_31 ,
V_128 [ V_4 -> V_12 ] , ( int ) V_4 -> V_88 ) ;
return 0 ;
V_139:
F_74 ( V_49 ) ;
return V_131 ;
}
static int F_74 ( struct V_111 * V_49 )
{
struct V_3 * V_4 = F_75 ( V_49 ) ;
int V_74 ;
if ( V_4 -> V_67 . V_68 ) {
F_76 ( & V_4 -> V_67 ) ;
if ( V_4 -> V_64 ) {
F_65 ( & V_49 -> V_6 ,
L_32
L_33 ) ;
F_37 ( V_4 ) ;
}
F_14 ( & V_65 ) ;
F_77 ( & V_4 -> V_135 ) ;
F_17 ( & V_65 ) ;
F_14 ( & V_4 -> V_48 ) ;
V_4 -> V_49 = NULL ;
F_17 ( & V_4 -> V_48 ) ;
}
if ( V_4 -> V_153 )
F_78 ( V_4 -> V_153 ) ;
F_79 ( & V_49 -> V_6 , & V_138 ) ;
for ( V_74 = 0 ; V_74 < ( V_140 [ V_4 -> V_12 ] ) ; V_74 ++ )
F_79 ( & V_49 -> V_6 , & V_141 [ V_74 ] . V_142 ) ;
for ( V_74 = 0 ; V_74 < ( V_143 [ V_4 -> V_12 ] * 4 ) ; V_74 ++ )
F_79 ( & V_49 -> V_6 ,
& V_144 [ V_74 ] . V_142 ) ;
for ( V_74 = 0 ; V_74 < ( V_148 [ V_4 -> V_12 ] * 5 ) ; V_74 ++ )
F_79 ( & V_49 -> V_6 ,
& V_149 [ V_74 ] . V_142 ) ;
F_14 ( & V_65 ) ;
F_48 ( & V_4 -> V_1 , F_1 ) ;
F_17 ( & V_65 ) ;
return 0 ;
}
static struct V_3 * F_6 ( struct V_5 * V_6 )
{
struct V_111 * V_49 = F_16 ( V_6 ) ;
struct V_3 * V_4 = F_75 ( V_49 ) ;
int V_74 ;
F_14 ( & V_4 -> V_23 ) ;
if ( F_80 ( V_158 , V_4 -> V_159 + 2 * V_160 ) || ! V_4 -> V_161 ) {
for ( V_74 = 0 ; V_74 < V_143 [ V_4 -> V_12 ] ; V_74 ++ ) {
V_4 -> V_19 [ V_74 ] = F_26 ( V_49 ,
V_162 [ V_4 -> V_12 ] [ V_74 ] ) ;
V_4 -> V_25 [ V_74 ] = F_26 ( V_49 ,
V_146 [ V_4 -> V_12 ] [ V_74 ] ) ;
if ( V_24 [ V_4 -> V_12 ] [ V_74 ] )
V_4 -> V_20 [ V_74 ] = F_26 (
V_49 ,
V_24 [ V_4 -> V_12 ] [ V_74 ] ) ;
if ( ( V_4 -> V_25 [ V_74 ] & V_27 ) ==
V_27 &&
V_4 -> V_19 [ V_74 ] < V_4 -> V_20 [ V_74 ] )
F_15 ( V_49 ,
V_146 [ V_4 -> V_12 ] [ V_74 ] ,
V_4 -> V_25 [ V_74 ] ) ;
}
for ( V_74 = 0 ; V_74 < V_148 [ V_4 -> V_12 ] ; V_74 ++ ) {
V_4 -> V_28 [ V_74 ] = F_26 ( V_49 ,
V_163 [ V_4 -> V_12 ] [ V_74 ] ) ;
V_4 -> V_33 [ V_74 ] = F_26 ( V_49 ,
V_151 [ V_4 -> V_12 ] [ V_74 ] ) ;
V_4 -> V_29 [ V_74 ] = F_26 ( V_49 ,
V_32 [ V_4 -> V_12 ] [ V_74 ] ) ;
if ( V_39 [ V_4 -> V_12 ] [ V_74 ] )
V_4 -> V_37 [ V_74 ] = F_26 (
V_49 ,
V_39 [ V_4 -> V_12 ] [ V_74 ] ) ;
if ( ( V_4 -> V_33 [ V_74 ] & V_34 ) &&
V_4 -> V_28 [ V_74 ] )
F_15 ( V_49 ,
V_151 [ V_4 -> V_12 ] [ V_74 ] ,
V_4 -> V_33 [ V_74 ] ) ;
}
for ( V_74 = 0 ; V_74 < V_140 [ V_4 -> V_12 ] ; V_74 ++ )
V_4 -> V_15 [ V_74 ] = F_26 ( V_49 ,
V_164 [ V_4 -> V_12 ] [ V_74 ] ) ;
V_4 -> V_159 = V_158 ;
V_4 -> V_161 = 1 ;
}
F_17 ( & V_4 -> V_23 ) ;
return V_4 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_165 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_165 ) ;
}
