static char * F_1 ( T_1 V_1 )
{
switch( F_2 ( V_1 ) ) {
case 0 :
return L_1 ;
case 1 :
return L_2 ;
case 2 :
return L_3 ;
default:
return L_4 ;
}
}
static inline int F_3 ( const struct V_2 * V_3 , T_1 V_1 ,
int V_4 )
{
return F_4 ( V_1 , V_3 [ V_4 ] . V_5 ,
V_3 [ V_4 ] . V_6 ) ;
}
static inline int F_5 ( enum type type , T_1 V_7 )
{
int V_8 = ( 1 << F_6 ( V_7 ) ) ;
int V_9 = 4 ;
if ( type == V_10 || type == V_11 )
V_9 = 8 ;
if ( V_8 > V_9 ) {
F_7 ( 0 , L_5 ,
V_8 , V_9 , ( unsigned int ) F_6 ( V_7 ) , V_7 ) ;
return - V_12 ;
}
return V_8 ;
}
static inline int F_8 ( T_1 V_7 )
{
int V_13 = ( F_9 ( V_7 ) + 12 ) ;
if ( V_13 < 13 || V_13 > 18 ) {
F_7 ( 0 , L_6 ,
V_13 , ( unsigned int ) F_9 ( V_7 ) , V_7 ) ;
return - V_12 ;
}
return 1 << V_13 ;
}
static inline int F_10 ( T_1 V_7 )
{
int V_14 = ( F_11 ( V_7 ) + 10 ) ;
if ( V_14 > 12 ) {
F_7 ( 0 , L_7 ,
V_14 , ( unsigned int ) F_11 ( V_7 ) , V_7 ) ;
return - V_12 ;
}
return 1 << V_14 ;
}
static struct V_15 * F_12 ( T_2 V_16 )
{
struct V_15 * V_15 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_15 -> V_16 == V_16 )
return V_15 ;
}
return NULL ;
}
static struct V_15 * F_14 ( T_2 V_16 ,
const struct V_17 * V_3 )
{
struct V_15 * V_15 ;
V_15 = F_15 ( sizeof( * V_15 ) , V_18 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_19 = F_15 ( sizeof( * V_15 -> V_19 ) * V_3 -> V_20 ,
V_18 ) ;
if ( ! V_15 -> V_19 ) {
F_16 ( V_15 ) ;
return NULL ;
}
V_15 -> V_16 = V_16 ;
V_15 -> V_20 = V_3 -> V_20 ;
F_17 ( & V_15 -> V_21 , & V_22 ) ;
return V_15 ;
}
static void F_18 ( struct V_15 * V_15 )
{
F_19 ( & V_15 -> V_21 ) ;
F_16 ( V_15 -> V_19 ) ;
F_16 ( V_15 ) ;
}
static T_3 F_20 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_25 , V_26 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_23 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_25 , V_27 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_25 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_28 , V_26 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_26 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_28 , V_27 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_27 ( T_1 V_1 )
{
return ( ( T_3 ) F_4 ( V_1 , 1 , 10 ) << 29 ) | 0x1fffffff ;
}
static enum V_29 F_28 ( struct V_23 * V_24 )
{
T_1 V_1 ;
enum V_29 V_30 ;
if ( V_24 -> V_31 ) {
F_21 ( V_24 -> V_31 , V_24 -> V_32 . V_33 ,
& V_1 ) ;
if ( F_4 ( V_1 , 11 , 11 ) )
V_30 = V_34 ;
else
V_30 = V_35 ;
} else
V_30 = V_36 ;
return V_30 ;
}
static enum V_29 F_29 ( struct V_23 * V_24 )
{
T_1 V_1 ;
bool V_37 = false ;
enum V_29 V_30 = V_36 ;
if ( ! V_24 -> V_31 )
goto V_38;
F_21 ( V_24 -> V_31 ,
V_39 , & V_1 ) ;
if ( F_4 ( V_1 , 16 , 16 ) )
V_37 = true ;
F_21 ( V_24 -> V_40 , V_41 , & V_1 ) ;
if ( F_4 ( V_1 , 14 , 14 ) ) {
if ( V_37 )
V_30 = V_42 ;
else
V_30 = V_43 ;
} else {
if ( V_37 )
V_30 = V_34 ;
else
V_30 = V_35 ;
}
V_38:
return V_30 ;
}
static enum V_44 F_30 ( struct V_23 * V_24 , T_1 V_7 )
{
return V_45 ;
}
static enum V_44 F_31 ( T_1 V_7 )
{
enum V_44 type ;
switch ( V_7 ) {
case 3 :
type = V_45 ;
break;
case 2 :
type = V_46 ;
break;
case 1 :
type = V_47 ;
break;
case 0 :
type = V_48 ;
break;
}
return type ;
}
static enum V_44 F_32 ( struct V_23 * V_24 , T_1 V_7 )
{
return F_31 ( F_4 ( V_7 , 7 , 8 ) ) ;
}
static enum V_44 F_33 ( struct V_23 * V_24 , T_1 V_7 )
{
return F_31 ( F_4 ( V_7 , 8 , 9 ) ) ;
}
static T_2 F_34 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_49 , V_50 , & V_1 ) ;
return F_4 ( V_1 , 0 , 2 ) ;
}
static T_2 F_35 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_25 , V_50 , & V_1 ) ;
return F_4 ( V_1 , 0 , 3 ) ;
}
static T_3 F_36 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_32 . V_51 , V_52 , & V_1 ) ;
return ( F_4 ( V_1 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_37 ( struct V_23 * V_24 )
{
T_3 V_53 ;
T_1 V_1 ;
F_21 ( V_24 -> V_32 . V_51 , V_54 , & V_1 ) ;
V_53 = F_4 ( V_1 , 26 , 31 ) ;
F_21 ( V_24 -> V_32 . V_51 , V_55 , & V_1 ) ;
V_53 = ( ( V_1 << 6 ) | V_53 ) << 26 ;
return V_53 | 0x1ffffff ;
}
static T_3 F_38 ( T_1 V_1 )
{
return ( ( ( T_3 ) F_4 ( V_1 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_39 ( T_2 V_56 )
{
return ( ( V_56 >> 3 ) << 2 ) | ( V_56 & 0x3 ) ;
}
static inline T_2 F_40 ( T_2 V_56 )
{
return ( V_56 >> 2 ) & 0x1 ;
}
static struct V_57 * F_41 ( T_2 V_16 , T_1 V_58 )
{
struct V_57 * V_19 = NULL ;
do {
V_19 = F_42 ( V_59 , V_58 , V_19 ) ;
if ( V_19 && V_19 -> V_16 -> V_60 == V_16 )
break;
} while ( V_19 );
return V_19 ;
}
static int F_43 ( const T_2 V_16 , enum type type )
{
struct V_57 * V_19 = NULL ;
T_1 V_61 , V_58 ;
switch ( type ) {
case V_62 :
V_58 = V_63 ;
break;
case V_10 :
V_58 = V_64 ;
break;
case V_65 :
V_58 = V_66 ;
break;
case V_11 :
V_58 = V_67 ;
break;
default:
return - V_68 ;
}
V_19 = F_41 ( V_16 , V_58 ) ;
if ( ! V_19 ) {
F_44 ( V_69 , L_8
L_9 ,
V_59 , V_58 , V_16 ) ;
return - V_68 ;
}
F_21 ( V_19 , V_41 , & V_61 ) ;
if ( ! F_45 ( V_61 ) ) {
F_44 ( V_69 , L_10 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_46 ( struct V_70 * V_71 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_73 * V_74 ;
unsigned V_75 , V_76 , V_77 , V_8 , V_13 , V_14 , V_78 ;
T_3 V_79 ;
T_1 V_1 ;
enum V_80 V_81 ;
enum V_29 V_30 ;
if ( V_24 -> V_32 . type == V_10 || V_24 -> V_32 . type == V_11 )
F_21 ( V_24 -> V_25 , V_82 , & V_1 ) ;
else
F_21 ( V_24 -> V_49 , V_82 , & V_1 ) ;
V_24 -> V_15 -> V_83 = F_47 ( V_1 ) ;
V_24 -> V_15 -> V_84 = V_24 -> V_32 . F_34 ( V_24 ) ;
F_7 ( 0 , L_11 ,
V_24 -> V_15 -> V_85 ,
V_24 -> V_15 -> V_84 ,
V_24 -> V_15 -> V_83 ) ;
F_21 ( V_24 -> V_86 , V_87 , & V_1 ) ;
if ( F_48 ( V_1 ) ) {
F_7 ( 0 , L_12 ) ;
V_24 -> V_88 = true ;
} else {
F_7 ( 0 , L_13 ) ;
V_24 -> V_88 = false ;
}
F_21 ( V_24 -> V_40 , V_41 , & V_24 -> V_32 . V_61 ) ;
if ( F_49 ( V_24 -> V_32 . V_61 ) ) {
F_7 ( 0 , L_14 ) ;
V_81 = V_89 ;
V_24 -> V_90 = true ;
} else {
F_7 ( 0 , L_15 ) ;
V_81 = V_91 ;
V_24 -> V_90 = false ;
}
if ( F_50 ( V_24 -> V_32 . V_61 ) ) {
F_7 ( 0 , L_16 ) ;
V_24 -> V_92 = true ;
} else {
F_7 ( 0 , L_17 ) ;
V_24 -> V_92 = false ;
}
V_30 = V_24 -> V_32 . F_28 ( V_24 ) ;
if ( V_30 == V_34 || V_30 == V_42 )
F_7 ( 0 , L_18 ) ;
else if ( V_30 == V_36 )
F_7 ( 0 , L_19 ) ;
else
F_7 ( 0 , L_20 ) ;
if ( V_30 == V_43 || V_30 == V_42 )
V_77 = 16 ;
else
V_77 = 8 ;
for ( V_75 = 0 ; V_75 < V_93 ; V_75 ++ ) {
T_1 V_7 ;
if ( ! V_24 -> V_94 [ V_75 ] )
continue;
for ( V_76 = 0 ; V_76 < F_51 ( V_95 ) ; V_76 ++ ) {
V_74 = F_52 ( V_71 -> V_96 , V_71 -> V_97 , V_71 -> V_98 ,
V_75 , V_76 , 0 ) ;
F_21 ( V_24 -> V_94 [ V_75 ] ,
V_95 [ V_76 ] , & V_7 ) ;
F_7 ( 4 , L_21 , V_75 , V_76 , V_7 ) ;
if ( F_53 ( V_7 ) ) {
V_24 -> V_99 [ V_75 ] . V_97 ++ ;
V_8 = F_5 ( V_24 -> V_32 . type , V_7 ) ;
V_13 = F_8 ( V_7 ) ;
V_14 = F_10 ( V_7 ) ;
V_79 = ( ( T_3 ) V_13 * V_14 * V_77 * V_8 ) >> ( 20 - 3 ) ;
V_78 = F_54 ( V_79 ) ;
F_7 ( 0 , L_22 ,
V_24 -> V_15 -> V_85 , V_75 / 4 , V_75 % 4 , V_76 ,
V_79 , V_78 ,
V_77 , V_8 , V_13 , V_14 ) ;
V_74 -> V_100 = V_78 ;
V_74 -> V_101 = 32 ;
V_74 -> V_102 = V_24 -> V_32 . V_103 ( V_24 , V_7 ) ;
V_74 -> V_30 = V_30 ;
V_74 -> V_104 = V_81 ;
snprintf ( V_74 -> V_105 , sizeof( V_74 -> V_105 ) ,
L_23 ,
V_24 -> V_15 -> V_83 , V_75 / 4 , V_75 % 4 , V_76 ) ;
}
}
}
return 0 ;
}
static void F_55 ( const struct V_70 * V_71 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
int V_75 , V_76 , V_106 , V_107 , V_108 , V_109 ;
T_1 V_1 ;
T_3 V_110 , V_111 = 0 ;
T_3 V_112 ;
T_1 V_113 , V_114 ;
T_1 V_115 ;
V_24 -> V_116 = V_24 -> V_32 . V_117 ( V_24 ) ;
V_112 = ( 1 + V_24 -> V_116 ) >> 20 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_24 ,
V_113 , ( V_114 * 1000 ) / 1024 , ( T_3 ) V_24 -> V_116 ) ;
V_24 -> V_118 = V_24 -> V_32 . V_119 ( V_24 ) ;
V_112 = ( 1 + V_24 -> V_118 ) >> 20 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_25 ,
V_113 , ( V_114 * 1000 ) / 1024 , ( T_3 ) V_24 -> V_118 ) ;
V_111 = 0 ;
for ( V_107 = 0 ; V_107 < V_24 -> V_32 . V_120 ; V_107 ++ ) {
F_21 ( V_24 -> V_121 , V_24 -> V_32 . V_122 [ V_107 ] ,
& V_1 ) ;
V_110 = F_57 ( V_1 ) ;
if ( ! F_58 ( V_1 ) )
continue;
if ( V_110 <= V_111 )
break;
V_112 = ( V_110 + 1 ) >> 20 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_26 ,
V_107 ,
F_1 ( V_1 ) ,
V_113 , ( V_114 * 1000 ) / 1024 ,
( ( T_3 ) V_112 ) << 20L ,
F_59 ( V_1 ) ? L_27 : L_28 ,
V_1 ) ;
V_111 = V_110 ;
F_21 ( V_24 -> V_121 , V_24 -> V_32 . V_123 [ V_107 ] ,
& V_1 ) ;
V_109 = F_3 ( V_24 -> V_32 . V_2 , V_1 , 0 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
T_1 V_56 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_76 ) ;
if ( V_76 > 0 && V_109 == V_56 )
break;
F_7 ( 0 , L_29 ,
V_107 , V_76 , V_56 ) ;
}
}
V_111 = 0 ;
for ( V_108 = 0 ; V_108 < V_124 ; V_108 ++ ) {
F_21 ( V_24 -> V_125 , V_126 [ V_108 ] ,
& V_1 ) ;
V_110 = F_60 ( V_1 ) ;
if ( V_110 <= V_111 )
break;
V_112 = ( V_110 + 1 ) >> 20 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_30 ,
V_108 , V_113 , ( V_114 * 1000 ) / 1024 ,
( ( T_3 ) V_112 ) << 20L ,
( T_1 ) F_61 ( V_1 ) ,
( T_1 ) F_62 ( V_1 ) ,
( T_1 ) F_63 ( V_1 ) ,
( T_1 ) F_64 ( V_1 ) ,
( T_1 ) F_65 ( V_1 ) ,
( T_1 ) F_66 ( V_1 ) ,
V_1 ) ;
V_111 = V_110 ;
}
for ( V_75 = 0 ; V_75 < V_93 ; V_75 ++ ) {
if ( ! V_24 -> V_99 [ V_75 ] . V_97 )
continue;
for ( V_76 = 0 ; V_76 < V_108 ; V_76 ++ ) {
F_21 ( V_24 -> V_94 [ V_75 ] ,
V_127 [ V_76 ] ,
& V_1 ) ;
V_112 = F_67 ( V_1 ) >> 20 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_31 ,
V_75 , V_76 ,
V_113 , ( V_114 * 1000 ) / 1024 ,
( ( T_3 ) V_112 ) << 20L ,
V_1 ) ;
}
}
for ( V_75 = 0 ; V_75 < V_93 ; V_75 ++ ) {
if ( ! V_24 -> V_99 [ V_75 ] . V_97 )
continue;
for ( V_76 = 0 ; V_76 < V_128 ; V_76 ++ ) {
F_21 ( V_24 -> V_94 [ V_75 ] ,
V_129 [ V_76 ] ,
& V_1 ) ;
if ( ! F_68 ( V_1 ) )
continue;
V_112 = V_24 -> V_32 . F_27 ( V_1 ) >> 20 ;
V_115 = 1 << F_69 ( V_1 ) ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_32 ,
V_75 , V_76 ,
V_113 , ( V_114 * 1000 ) / 1024 ,
( ( T_3 ) V_112 ) << 20L ,
V_115 ,
V_1 ) ;
for ( V_106 = 0 ; V_106 < V_115 ; V_106 ++ ) {
F_21 ( V_24 -> V_94 [ V_75 ] ,
V_130 [ V_76 ] [ V_106 ] ,
& V_1 ) ;
V_112 = F_70 ( V_1 ) << 6 ;
V_113 = F_56 ( V_112 , 1024 , & V_114 ) ;
F_7 ( 0 , L_33 ,
V_75 , V_76 , V_106 ,
V_113 , ( V_114 * 1000 ) / 1024 ,
( ( T_3 ) V_112 ) << 20L ,
( T_1 ) F_71 ( V_1 ) ,
V_1 ) ;
}
}
}
}
static struct V_70 * F_72 ( T_2 V_84 )
{
struct V_15 * V_15 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_15 -> V_84 == V_84 )
return V_15 -> V_71 ;
}
return NULL ;
}
static int F_73 ( struct V_70 * V_71 ,
T_3 V_131 ,
T_2 * V_132 , T_2 * V_133 ,
long * V_134 ,
T_2 * V_135 ,
char * * V_136 , char * V_137 )
{
struct V_70 * V_138 ;
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_57 * V_139 ;
int V_140 , V_107 , V_108 , V_141 , V_142 ;
int V_109 , V_143 , V_144 ;
int V_145 , V_146 = 0 ;
unsigned V_147 [ V_24 -> V_32 . V_148 ] ;
T_1 V_1 , V_122 ;
T_2 V_149 , V_150 , V_56 , V_151 = 0 , V_152 = 0 ;
T_1 V_153 ;
T_1 V_115 ;
T_1 V_114 , V_113 ;
T_3 V_154 , V_155 , V_110 = 0 , V_111 = 0 ;
if ( ( V_131 > ( T_3 ) V_24 -> V_116 ) && ( V_131 < ( 1LL << 32 ) ) ) {
sprintf ( V_137 , L_34 , V_131 ) ;
return - V_12 ;
}
if ( V_131 >= ( T_3 ) V_24 -> V_118 ) {
sprintf ( V_137 , L_35 , V_131 ) ;
return - V_12 ;
}
for ( V_107 = 0 ; V_107 < V_24 -> V_32 . V_120 ; V_107 ++ ) {
F_21 ( V_24 -> V_121 , V_24 -> V_32 . V_122 [ V_107 ] ,
& V_1 ) ;
if ( ! F_58 ( V_1 ) )
continue;
V_110 = F_57 ( V_1 ) ;
if ( V_110 <= V_111 ) {
sprintf ( V_137 , L_36 ) ;
return - V_12 ;
}
if ( V_131 <= V_110 )
break;
V_111 = V_110 ;
}
if ( V_107 == V_24 -> V_32 . V_120 ) {
sprintf ( V_137 , L_36 ) ;
return - V_12 ;
}
V_122 = V_1 ;
* V_136 = F_1 ( V_122 ) ;
V_145 = F_59 ( V_122 ) ;
F_21 ( V_24 -> V_121 , V_24 -> V_32 . V_123 [ V_107 ] ,
& V_1 ) ;
if ( V_24 -> V_32 . type == V_65 ) {
V_109 = F_3 ( V_24 -> V_32 . V_2 , V_1 , 0 ) ;
for ( V_141 = 0 ; V_141 < 8 ; V_141 ++ ) {
T_1 V_56 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_141 ) ;
if ( V_141 > 0 && V_109 == V_56 )
break;
V_147 [ V_141 ] = V_56 ;
F_7 ( 0 , L_37 ,
V_141 , V_147 [ V_141 ] ) ;
}
F_7 ( 0 , L_38 ,
V_24 -> V_15 -> V_85 ,
V_107 ,
V_131 ,
V_110 ,
V_141 + 7 ,
! V_145 ? L_39 : L_40 ) ;
if ( V_145 )
V_143 = ( ( V_131 >> 6 ) ^ ( V_131 >> 16 ) ) & 7 ;
else
V_143 = ( V_131 >> 6 ) & 7 ;
switch ( V_141 ) {
case 1 :
V_143 = 0 ;
break;
case 2 :
V_143 = V_143 & 1 ;
break;
case 4 :
V_143 = V_143 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_137 , L_41 ) ;
return - V_12 ;
}
* V_132 = V_147 [ V_143 ] ;
F_7 ( 0 , L_42 ,
V_143 , V_141 , * V_132 ) ;
} else if ( V_24 -> V_32 . type == V_10 || V_24 -> V_32 . type == V_11 ) {
int V_156 , V_157 = F_74 ( V_122 ) ;
if ( V_157 ) {
V_156 = F_4 ( V_131 , 7 , 8 ) << 1 ;
V_156 |= F_4 ( V_131 , 9 , 9 ) ;
} else
V_156 = F_4 ( V_131 , 6 , 8 ) ;
if ( V_145 == 0 ) {
V_143 = F_4 ( V_131 , 16 , 18 ) ;
V_143 ^= V_156 ;
} else
V_143 = V_156 ;
V_56 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_143 ) ;
* V_132 = F_39 ( V_56 ) ;
V_151 = F_40 ( V_56 ) ;
if ( V_151 )
V_152 = 4 ;
if ( V_157 ) {
F_21 ( V_24 -> V_125 ,
V_158 , & V_1 ) ;
V_146 = F_4 ( V_1 , 22 , 22 ) ;
}
F_7 ( 0 , L_43 ,
V_143 , * V_132 , V_151 , V_146 ) ;
} else {
V_143 = ( V_131 >> 6 ) & 7 ;
V_56 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_143 ) ;
* V_132 = F_39 ( V_56 ) ;
V_151 = F_40 ( V_56 ) ;
if ( V_151 )
V_152 = 4 ;
F_7 ( 0 , L_44 ,
V_143 , * V_132 , V_151 ) ;
}
* V_133 = V_151 ;
V_138 = F_72 ( * V_132 ) ;
if ( ! V_138 ) {
sprintf ( V_137 , L_45 ,
* V_132 ) ;
return - V_12 ;
}
V_71 = V_138 ;
V_24 = V_71 -> V_72 ;
V_111 = 0 ;
if ( V_24 -> V_32 . type == V_65 )
V_139 = V_24 -> V_125 ;
else {
if ( V_151 )
V_139 = V_24 -> V_159 ;
else
V_139 = V_24 -> V_125 ;
}
for ( V_108 = 0 ; V_108 < V_124 ; V_108 ++ ) {
F_21 ( V_139 , V_126 [ V_108 ] , & V_1 ) ;
V_110 = F_60 ( V_1 ) ;
if ( V_110 <= V_111 ) {
sprintf ( V_137 , L_46 ) ;
return - V_12 ;
}
if ( V_131 <= V_110 )
break;
V_111 = V_110 ;
}
if ( V_108 == V_124 ) {
sprintf ( V_137 , L_46 ) ;
return - V_12 ;
}
V_149 = F_62 ( V_1 ) + 1 ;
V_150 = F_61 ( V_1 ) + 1 ;
if ( V_149 == 3 )
V_143 = V_131 >> 6 ;
else
V_143 = ( V_131 >> ( 6 + V_150 + V_146 ) ) & 0x3 ;
V_143 = V_143 % V_149 ;
switch ( V_143 ) {
case 0 :
V_144 = F_63 ( V_1 ) ;
break;
case 1 :
V_144 = F_64 ( V_1 ) ;
break;
case 2 :
V_144 = F_65 ( V_1 ) ;
break;
case 3 :
V_144 = F_66 ( V_1 ) ;
break;
default:
sprintf ( V_137 , L_47 ) ;
return - V_12 ;
}
* V_134 = 1 << V_144 ;
F_21 ( V_24 -> V_94 [ V_152 + V_144 ] ,
V_127 [ V_108 ] ,
& V_153 ) ;
if ( V_24 -> V_88 ) {
* V_134 |= 1 << ( ( V_144 + 2 ) % 4 ) ;
switch( V_149 ) {
case 2 :
case 4 :
V_142 = 1 << V_150 * ( V_149 >> 1 ) ;
break;
default:
sprintf ( V_137 , L_48 ) ;
return - V_12 ;
}
} else
V_142 = ( 1 << V_150 ) * V_149 ;
if ( V_24 -> V_90 )
* V_134 |= 1 << ( ( V_144 + 1 ) % 4 ) ;
V_155 = F_67 ( V_153 ) ;
F_7 ( 0 , L_49 ,
V_108 ,
V_131 ,
V_110 ,
( T_1 ) F_61 ( V_1 ) ,
V_149 ,
V_155 ,
V_143 ,
V_144 ,
* V_134 ) ;
if ( V_155 > V_131 ) {
sprintf ( V_137 , L_50 ,
V_155 , V_131 ) ;
return - V_12 ;
}
V_131 -= V_155 ;
V_154 = V_131 & 0x7f ;
V_131 >>= 6 ;
V_131 = F_75 ( V_131 , V_142 ) ;
#if 0
addr = addr / ch_way;
#endif
V_154 |= V_131 << 6 ;
for ( V_140 = 0 ; V_140 < V_128 ; V_140 ++ ) {
F_21 ( V_24 -> V_94 [ V_152 + V_144 ] ,
V_129 [ V_140 ] ,
& V_1 ) ;
if ( ! F_68 ( V_1 ) )
continue;
V_110 = V_24 -> V_32 . F_27 ( V_1 ) ;
V_113 = F_56 ( V_110 >> 20 , 1024 , & V_114 ) ;
F_7 ( 0 , L_51 ,
V_140 ,
V_113 , ( V_114 * 1000 ) / 1024 ,
V_110 ,
1 << F_69 ( V_1 ) ) ;
if ( V_154 <= V_110 )
break;
}
if ( V_140 == V_128 ) {
sprintf ( V_137 , L_52 ,
V_154 ) ;
return - V_12 ;
}
V_115 = F_69 ( V_1 ) ;
if ( V_24 -> V_92 )
V_143 = ( V_154 >> 6 ) ;
else
V_143 = ( V_154 >> 13 ) ;
V_143 %= 1 << V_115 ;
F_21 ( V_24 -> V_94 [ V_152 + V_144 ] ,
V_130 [ V_140 ] [ V_143 ] ,
& V_1 ) ;
* V_135 = F_71 ( V_1 ) ;
F_7 ( 0 , L_53 ,
V_140 ,
V_154 ,
V_110 ,
V_115 ,
V_143 ) ;
return 0 ;
}
static void F_76 ( struct V_15 * V_15 )
{
int V_75 ;
F_7 ( 0 , L_54 ) ;
for ( V_75 = 0 ; V_75 < V_15 -> V_20 ; V_75 ++ ) {
struct V_57 * V_19 = V_15 -> V_19 [ V_75 ] ;
if ( ! V_19 )
continue;
F_7 ( 0 , L_55 ,
V_19 -> V_16 -> V_60 ,
F_77 ( V_19 -> V_160 ) , F_78 ( V_19 -> V_160 ) ) ;
F_79 ( V_19 ) ;
}
}
static void F_80 ( void )
{
struct V_15 * V_15 , * V_161 ;
F_81 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_76 ( V_15 ) ;
F_18 ( V_15 ) ;
}
}
static int F_82 ( struct V_57 * * V_162 ,
T_2 * V_163 ,
const struct V_17 * V_3 ,
const unsigned V_164 )
{
struct V_15 * V_15 ;
const struct V_165 * V_166 = & V_3 -> V_167 [ V_164 ] ;
struct V_57 * V_19 = NULL ;
T_2 V_16 = 0 ;
F_44 ( V_168 ,
L_56 ,
V_59 , V_166 -> V_169 ) ;
V_19 = F_42 ( V_59 ,
V_166 -> V_169 , * V_162 ) ;
if ( ! V_19 ) {
if ( * V_162 ) {
* V_162 = V_19 ;
return 0 ;
}
if ( V_166 -> V_170 )
return 0 ;
if ( V_164 == 0 )
return - V_68 ;
F_44 ( V_171 ,
L_57 ,
V_59 , V_166 -> V_169 ) ;
return - V_68 ;
}
V_16 = V_19 -> V_16 -> V_60 ;
V_15 = F_12 ( V_16 ) ;
if ( ! V_15 ) {
V_15 = F_14 ( V_16 , V_3 ) ;
if ( ! V_15 ) {
F_79 ( V_19 ) ;
return - V_172 ;
}
( * V_163 ) ++ ;
}
if ( V_15 -> V_19 [ V_164 ] ) {
F_44 ( V_69 ,
L_58 ,
V_59 , V_166 -> V_169 ) ;
F_79 ( V_19 ) ;
return - V_68 ;
}
V_15 -> V_19 [ V_164 ] = V_19 ;
if ( F_83 ( F_84 ( V_19 ) < 0 ) ) {
F_44 ( V_69 ,
L_59 ,
V_59 , V_166 -> V_169 ) ;
return - V_68 ;
}
F_7 ( 0 , L_60 ,
V_59 , V_166 -> V_169 ) ;
F_85 ( V_19 ) ;
* V_162 = V_19 ;
return 0 ;
}
static int F_86 ( T_2 * V_163 ,
const struct V_17 * V_3 )
{
int V_75 , V_53 ;
struct V_57 * V_19 = NULL ;
while ( V_3 && V_3 -> V_167 ) {
for ( V_75 = 0 ; V_75 < V_3 -> V_20 ; V_75 ++ ) {
V_19 = NULL ;
do {
V_53 = F_82 ( & V_19 , V_163 ,
V_3 , V_75 ) ;
if ( V_53 < 0 ) {
if ( V_75 == 0 ) {
V_75 = V_3 -> V_20 ;
break;
}
F_80 () ;
return - V_68 ;
}
} while ( V_19 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_87 ( struct V_70 * V_71 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_57 * V_19 ;
T_2 V_173 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_15 -> V_20 ; V_75 ++ ) {
V_19 = V_15 -> V_19 [ V_75 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_174 ) {
case V_175 :
V_24 -> V_121 = V_19 ;
break;
case V_176 :
V_24 -> V_25 = V_19 ;
break;
case V_177 :
V_24 -> V_49 = V_19 ;
break;
case V_178 :
V_24 -> V_125 = V_19 ;
break;
case V_66 :
V_24 -> V_40 = V_19 ;
break;
case V_179 :
V_24 -> V_86 = V_19 ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
{
int V_58 = V_19 -> V_174 - V_180 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_184 :
V_24 -> V_31 = V_19 ;
break;
default:
goto error;
}
F_7 ( 0 , L_61 ,
V_19 -> V_185 , V_19 -> V_174 ,
V_15 -> V_16 ,
V_19 ) ;
}
if ( ! V_24 -> V_121 || ! V_24 -> V_25 || ! V_24 -> V_125 ||
! V_24 -> V_94 || ! V_24 -> V_86 || ! V_24 -> V_40 )
goto V_186;
if ( V_173 != 0x0f )
goto V_186;
return 0 ;
V_186:
F_44 ( V_69 , L_62 ) ;
return - V_68 ;
error:
F_44 ( V_69 , L_63 ,
V_59 , V_19 -> V_174 ) ;
return - V_12 ;
}
static int F_88 ( struct V_70 * V_71 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_57 * V_19 ;
T_2 V_173 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_15 -> V_20 ; V_75 ++ ) {
V_19 = V_15 -> V_19 [ V_75 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_174 ) {
case V_187 :
V_24 -> V_125 = V_19 ;
break;
case V_63 :
V_24 -> V_40 = V_19 ;
case V_188 :
V_24 -> V_86 = V_19 ;
break;
case V_189 :
case V_190 :
case V_191 :
case V_192 :
{
int V_58 = V_19 -> V_174 - V_189 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_193 :
V_24 -> V_31 = V_19 ;
break;
case V_194 :
V_24 -> V_31 = V_19 ;
break;
case V_195 :
V_24 -> V_121 = V_19 ;
break;
case V_196 :
V_24 -> V_49 = V_19 ;
break;
case V_197 :
V_24 -> V_28 = V_19 ;
break;
case V_198 :
V_24 -> V_159 = V_19 ;
break;
case V_199 :
case V_200 :
case V_201 :
case V_202 :
{
int V_58 = V_19 -> V_174 - V_199 + 4 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_77 ( V_19 -> V_160 ) , F_78 ( V_19 -> V_160 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_121 || ! V_24 -> V_125 || ! V_24 -> V_49 ||
! V_24 -> V_28 || ! V_24 -> V_94 || ! V_24 -> V_86 ||
! V_24 -> V_40 )
goto V_186;
if ( V_173 != 0x0f &&
V_173 != 0x33 &&
V_173 != 0xff )
goto V_186;
return 0 ;
V_186:
F_44 ( V_69 , L_62 ) ;
return - V_68 ;
error:
F_44 ( V_69 ,
L_63 , V_59 ,
V_19 -> V_174 ) ;
return - V_12 ;
}
static int F_89 ( struct V_70 * V_71 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_57 * V_19 ;
T_2 V_173 = 0 ;
int V_75 ;
if ( V_24 -> V_32 . V_51 == NULL )
V_24 -> V_32 . V_51 = F_42 ( V_59 ,
V_203 ,
NULL ) ;
for ( V_75 = 0 ; V_75 < V_15 -> V_20 ; V_75 ++ ) {
V_19 = V_15 -> V_19 [ V_75 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_174 ) {
case V_204 :
V_24 -> V_121 = V_19 ;
break;
case V_205 :
V_24 -> V_25 = V_19 ;
break;
case V_206 :
V_24 -> V_125 = V_19 ;
break;
case V_64 :
V_24 -> V_40 = V_19 ;
break;
case V_207 :
V_24 -> V_86 = V_19 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
{
int V_58 = V_19 -> V_174 - V_208 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_212 :
case V_213 :
case V_214 :
case V_215 :
{
int V_58 = V_19 -> V_174 - V_212 + 4 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
if ( ! V_24 -> V_31 )
V_24 -> V_31 = V_19 ;
break;
case V_220 :
V_24 -> V_159 = V_19 ;
break;
case V_221 :
V_24 -> V_222 = V_19 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_77 ( V_19 -> V_160 ) , F_78 ( V_19 -> V_160 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_121 || ! V_24 -> V_125 || ! V_24 -> V_25 ||
! V_24 -> V_86 || ! V_24 -> V_40 || ! V_24 -> V_32 . V_51 )
goto V_186;
if ( V_173 != 0x0f &&
V_173 != 0x33 &&
V_173 != 0xff )
goto V_186;
return 0 ;
V_186:
F_44 ( V_69 , L_62 ) ;
return - V_68 ;
}
static int F_90 ( struct V_70 * V_71 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
struct V_57 * V_19 ;
T_2 V_173 = 0 ;
int V_75 ;
if ( V_24 -> V_32 . V_51 == NULL )
V_24 -> V_32 . V_51 = F_42 ( V_59 ,
V_223 ,
NULL ) ;
for ( V_75 = 0 ; V_75 < V_15 -> V_20 ; V_75 ++ ) {
V_19 = V_15 -> V_19 [ V_75 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_174 ) {
case V_224 :
V_24 -> V_121 = V_19 ;
break;
case V_225 :
V_24 -> V_25 = V_19 ;
break;
case V_226 :
V_24 -> V_125 = V_19 ;
break;
case V_67 :
V_24 -> V_40 = V_19 ;
break;
case V_227 :
V_24 -> V_86 = V_19 ;
break;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
{
int V_58 = V_19 -> V_174 - V_228 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_232 :
case V_233 :
case V_234 :
case V_235 :
{
int V_58 = V_19 -> V_174 - V_232 + 4 ;
V_24 -> V_94 [ V_58 ] = V_19 ;
V_173 |= 1 << V_58 ;
}
break;
case V_236 :
V_24 -> V_31 = V_19 ;
break;
case V_237 :
V_24 -> V_159 = V_19 ;
break;
case V_238 :
V_24 -> V_222 = V_19 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_77 ( V_19 -> V_160 ) , F_78 ( V_19 -> V_160 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_121 || ! V_24 -> V_125 || ! V_24 -> V_25 ||
! V_24 -> V_86 || ! V_24 -> V_40 || ! V_24 -> V_32 . V_51 )
goto V_186;
if ( V_173 != 0x0f &&
V_173 != 0x33 &&
V_173 != 0xff )
goto V_186;
return 0 ;
V_186:
F_44 ( V_69 , L_62 ) ;
return - V_68 ;
}
static void F_91 ( struct V_70 * V_71 ,
const struct V_239 * V_240 )
{
struct V_70 * V_138 ;
struct V_23 * V_24 = V_71 -> V_72 ;
enum V_241 V_242 ;
char * type , * V_243 , V_137 [ 256 ] ;
bool V_244 = F_4 ( V_240 -> V_245 , 0 , 0 ) ;
bool V_246 = F_4 ( V_240 -> V_247 , 62 , 62 ) ;
bool V_248 = F_4 ( V_240 -> V_247 , 61 , 61 ) ;
bool V_249 ;
T_1 V_250 = F_4 ( V_240 -> V_247 , 38 , 52 ) ;
T_1 V_251 = F_4 ( V_240 -> V_247 , 16 , 31 ) ;
T_1 V_252 = F_4 ( V_240 -> V_247 , 0 , 15 ) ;
T_1 V_99 = F_4 ( V_240 -> V_247 , 0 , 3 ) ;
T_1 V_253 = F_4 ( V_240 -> V_247 , 4 , 6 ) ;
long V_134 , V_254 ;
T_2 V_135 , V_132 , V_133 ;
int V_53 , V_74 ;
char * V_136 = NULL ;
if ( V_24 -> V_32 . type != V_65 )
V_249 = true ;
else
V_249 = F_4 ( V_240 -> V_247 , 56 , 56 ) ;
if ( V_248 ) {
if ( V_244 ) {
type = L_65 ;
V_242 = V_255 ;
} else {
type = L_66 ;
V_242 = V_256 ;
}
} else {
type = L_67 ;
V_242 = V_257 ;
}
if ( ! ( ( V_252 & 0xef80 ) == 0x80 ) ) {
V_243 = L_68 ;
} else {
switch ( V_253 ) {
case 0 :
V_243 = L_69 ;
break;
case 1 :
V_243 = L_70 ;
break;
case 2 :
V_243 = L_71 ;
break;
case 3 :
V_243 = L_72 ;
break;
case 4 :
V_243 = L_73 ;
break;
default:
V_243 = L_74 ;
break;
}
}
if ( ! F_4 ( V_240 -> V_247 , 58 , 58 ) )
return;
V_53 = F_73 ( V_71 , V_240 -> V_131 , & V_132 , & V_133 ,
& V_134 , & V_135 , & V_136 , V_137 ) ;
if ( V_53 < 0 )
goto V_258;
V_138 = F_72 ( V_132 ) ;
if ( ! V_138 ) {
strcpy ( V_137 , L_75 ) ;
goto V_258;
}
V_71 = V_138 ;
V_24 = V_71 -> V_72 ;
V_254 = F_92 ( & V_134 , V_93 ) ;
if ( V_135 < 4 )
V_74 = 0 ;
else if ( V_135 < 8 )
V_74 = 1 ;
else
V_74 = 2 ;
if ( ! V_24 -> V_90 && ! V_24 -> V_88 && ! V_24 -> V_92 )
V_99 = V_254 ;
snprintf ( V_137 , sizeof( V_137 ) ,
L_76 ,
V_246 ? L_77 : L_39 ,
( V_248 && V_249 ) ? L_78 : L_39 ,
V_136 ,
V_251 , V_252 ,
V_132 , V_133 ,
V_134 ,
V_135 ) ;
F_7 ( 0 , L_79 , V_137 ) ;
if ( V_99 == V_259 )
V_99 = - 1 ;
F_93 ( V_242 , V_71 , V_250 ,
V_240 -> V_131 >> V_260 , V_240 -> V_131 & ~ V_261 , 0 ,
4 * V_133 + V_99 , V_74 , - 1 ,
V_243 , V_137 ) ;
return;
V_258:
F_93 ( V_242 , V_71 , V_250 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_137 , L_39 ) ;
}
static void F_94 ( struct V_70 * V_71 )
{
struct V_23 * V_24 = V_71 -> V_72 ;
int V_75 ;
unsigned V_262 = 0 ;
struct V_239 * V_240 ;
F_95 () ;
V_262 = ( V_24 -> V_263 + V_264 - V_24 -> V_265 )
% V_264 ;
if ( ! V_262 )
return;
V_240 = V_24 -> V_266 ;
if ( V_24 -> V_265 + V_262 > V_264 ) {
unsigned V_267 = V_264 - V_24 -> V_265 ;
memcpy ( V_240 , & V_24 -> V_268 [ V_24 -> V_265 ] , sizeof( * V_240 ) * V_267 ) ;
F_96 () ;
V_24 -> V_265 = 0 ;
V_262 -= V_267 ;
V_240 += V_267 ;
}
memcpy ( V_240 , & V_24 -> V_268 [ V_24 -> V_265 ] , sizeof( * V_240 ) * V_262 ) ;
F_96 () ;
V_24 -> V_265 += V_262 ;
F_95 () ;
if ( V_24 -> V_269 ) {
F_44 ( V_69 , L_80 ,
V_24 -> V_269 ) ;
F_96 () ;
V_24 -> V_269 = 0 ;
}
for ( V_75 = 0 ; V_75 < V_262 ; V_75 ++ )
F_91 ( V_71 , & V_24 -> V_266 [ V_75 ] ) ;
}
static int F_97 ( struct V_270 * V_271 , unsigned long V_272 ,
void * V_273 )
{
struct V_239 * V_239 = (struct V_239 * ) V_273 ;
struct V_70 * V_71 ;
struct V_23 * V_24 ;
char * type ;
if ( F_98 () == V_274 )
return V_275 ;
V_71 = F_72 ( V_239 -> V_276 ) ;
if ( ! V_71 )
return V_277 ;
V_24 = V_71 -> V_72 ;
if ( ( V_239 -> V_247 & 0xefff ) >> 7 != 1 )
return V_275 ;
if ( V_239 -> V_245 & V_278 )
type = L_81 ;
else
type = L_82 ;
F_99 ( V_71 , V_168 , L_83 ) ;
F_99 ( V_71 , V_168 , L_84
L_85 , V_239 -> V_279 , type ,
V_239 -> V_245 , V_239 -> V_280 , V_239 -> V_247 ) ;
F_99 ( V_71 , V_168 , L_86 , V_239 -> V_281 ) ;
F_99 ( V_71 , V_168 , L_87 , V_239 -> V_131 ) ;
F_99 ( V_71 , V_168 , L_88 , V_239 -> V_282 ) ;
F_99 ( V_71 , V_168 , L_89
L_90 , V_239 -> V_283 , V_239 -> V_284 ,
V_239 -> time , V_239 -> V_276 , V_239 -> V_285 ) ;
F_95 () ;
if ( ( V_24 -> V_263 + 1 ) % V_264 == V_24 -> V_265 ) {
F_96 () ;
V_24 -> V_269 ++ ;
return V_275 ;
}
memcpy ( & V_24 -> V_268 [ V_24 -> V_263 ] , V_239 , sizeof( * V_239 ) ) ;
F_96 () ;
V_24 -> V_263 = ( V_24 -> V_263 + 1 ) % V_264 ;
if ( V_239 -> V_245 & 1 )
F_94 ( V_71 ) ;
return V_286 ;
}
static void F_100 ( struct V_15 * V_15 )
{
struct V_70 * V_71 = V_15 -> V_71 ;
struct V_23 * V_24 ;
if ( F_83 ( ! V_71 || ! V_71 -> V_72 ) ) {
F_7 ( 0 , L_91 , & V_15 -> V_19 [ 0 ] -> V_287 ) ;
F_44 ( V_69 , L_92 ) ;
return;
}
V_24 = V_71 -> V_72 ;
F_7 ( 0 , L_93 ,
V_71 , & V_15 -> V_19 [ 0 ] -> V_287 ) ;
F_101 ( V_71 -> V_19 ) ;
F_7 ( 1 , L_94 , V_71 -> V_288 ) ;
F_16 ( V_71 -> V_288 ) ;
F_102 ( V_71 ) ;
V_15 -> V_71 = NULL ;
}
static int F_103 ( struct V_15 * V_15 , enum type type )
{
struct V_70 * V_71 ;
struct V_289 V_96 [ 2 ] ;
struct V_23 * V_24 ;
struct V_57 * V_19 = V_15 -> V_19 [ 0 ] ;
int V_53 ;
V_53 = F_43 ( V_15 -> V_16 , type ) ;
if ( F_83 ( V_53 < 0 ) )
return V_53 ;
V_96 [ 0 ] . type = V_290 ;
V_96 [ 0 ] . V_79 = V_93 ;
V_96 [ 0 ] . V_291 = false ;
V_96 [ 1 ] . type = V_292 ;
V_96 [ 1 ] . V_79 = V_293 ;
V_96 [ 1 ] . V_291 = true ;
V_71 = F_104 ( V_15 -> V_85 , F_51 ( V_96 ) , V_96 ,
sizeof( * V_24 ) ) ;
if ( F_83 ( ! V_71 ) )
return - V_172 ;
F_7 ( 0 , L_93 ,
V_71 , & V_19 -> V_287 ) ;
V_24 = V_71 -> V_72 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_15 = V_15 ;
V_15 -> V_71 = V_71 ;
V_71 -> V_294 = V_295 ;
V_71 -> V_296 = V_297 ;
V_71 -> V_298 = V_297 ;
V_71 -> V_299 = L_95 ;
V_71 -> V_300 = V_301 ;
V_71 -> V_302 = F_105 ( V_19 ) ;
V_71 -> V_303 = NULL ;
V_71 -> V_304 = F_94 ;
V_24 -> V_32 . type = type ;
switch ( type ) {
case V_62 :
V_24 -> V_32 . V_33 = V_305 ;
V_24 -> V_32 . V_117 = F_25 ;
V_24 -> V_32 . V_119 = F_26 ;
V_24 -> V_32 . V_122 = V_306 ;
V_24 -> V_32 . F_28 = F_28 ;
V_24 -> V_32 . F_34 = F_34 ;
V_24 -> V_32 . F_27 = F_27 ;
V_24 -> V_32 . V_120 = F_51 ( V_306 ) ;
V_24 -> V_32 . V_123 = V_307 ;
V_24 -> V_32 . V_148 = F_51 ( V_307 ) ;
V_24 -> V_32 . V_2 = V_308 ;
V_24 -> V_32 . V_103 = F_32 ;
V_71 -> V_288 = F_106 ( V_18 , L_96 , V_71 -> V_309 ) ;
V_53 = F_88 ( V_71 , V_15 ) ;
if ( F_83 ( V_53 < 0 ) )
goto V_310;
break;
case V_65 :
V_24 -> V_32 . V_33 = V_311 ;
V_24 -> V_32 . V_117 = F_20 ;
V_24 -> V_32 . V_119 = F_23 ;
V_24 -> V_32 . V_122 = V_312 ;
V_24 -> V_32 . F_28 = F_28 ;
V_24 -> V_32 . F_34 = F_34 ;
V_24 -> V_32 . F_27 = F_27 ;
V_24 -> V_32 . V_120 = F_51 ( V_312 ) ;
V_24 -> V_32 . V_123 = V_313 ;
V_24 -> V_32 . V_148 = F_51 ( V_313 ) ;
V_24 -> V_32 . V_2 = V_314 ;
V_24 -> V_32 . V_103 = F_30 ;
V_71 -> V_288 = F_106 ( V_18 , L_97 , V_71 -> V_309 ) ;
V_53 = F_87 ( V_71 , V_15 ) ;
if ( F_83 ( V_53 < 0 ) )
goto V_310;
break;
case V_10 :
V_24 -> V_32 . V_117 = F_36 ;
V_24 -> V_32 . V_119 = F_37 ;
V_24 -> V_32 . V_122 = V_306 ;
V_24 -> V_32 . F_28 = F_29 ;
V_24 -> V_32 . F_34 = F_35 ;
V_24 -> V_32 . F_27 = F_38 ;
V_24 -> V_32 . V_120 = F_51 ( V_306 ) ;
V_24 -> V_32 . V_123 = V_307 ;
V_24 -> V_32 . V_148 = F_51 ( V_307 ) ;
V_24 -> V_32 . V_2 = V_308 ;
V_24 -> V_32 . V_103 = F_32 ;
V_71 -> V_288 = F_106 ( V_18 , L_98 , V_71 -> V_309 ) ;
V_53 = F_89 ( V_71 , V_15 ) ;
if ( F_83 ( V_53 < 0 ) )
goto V_310;
break;
case V_11 :
V_24 -> V_32 . V_117 = F_36 ;
V_24 -> V_32 . V_119 = F_37 ;
V_24 -> V_32 . V_122 = V_306 ;
V_24 -> V_32 . F_28 = F_29 ;
V_24 -> V_32 . F_34 = F_35 ;
V_24 -> V_32 . F_27 = F_38 ;
V_24 -> V_32 . V_120 = F_51 ( V_306 ) ;
V_24 -> V_32 . V_123 = V_307 ;
V_24 -> V_32 . V_148 = F_51 ( V_307 ) ;
V_24 -> V_32 . V_2 = V_308 ;
V_24 -> V_32 . V_103 = F_33 ;
V_71 -> V_288 = F_106 ( V_18 , L_99 , V_71 -> V_309 ) ;
V_53 = F_90 ( V_71 , V_15 ) ;
if ( F_83 ( V_53 < 0 ) )
goto V_310;
break;
}
F_46 ( V_71 ) ;
F_55 ( V_71 ) ;
V_71 -> V_19 = & V_19 -> V_287 ;
if ( F_83 ( F_107 ( V_71 ) ) ) {
F_7 ( 0 , L_100 ) ;
V_53 = - V_12 ;
goto V_310;
}
return 0 ;
V_310:
F_16 ( V_71 -> V_288 ) ;
F_102 ( V_71 ) ;
V_15 -> V_71 = NULL ;
return V_53 ;
}
static int F_108 ( struct V_57 * V_19 , const struct V_315 * V_58 )
{
int V_53 = - V_68 ;
T_2 V_85 , V_163 = 0 ;
struct V_15 * V_15 ;
enum type type = V_65 ;
F_109 ( & V_316 ) ;
if ( F_83 ( V_317 >= 1 ) ) {
F_110 ( & V_316 ) ;
return - V_68 ;
}
V_317 ++ ;
switch ( V_19 -> V_174 ) {
case V_63 :
V_53 = F_86 ( & V_163 , V_318 ) ;
type = V_62 ;
break;
case V_178 :
V_53 = F_86 ( & V_163 , V_319 ) ;
type = V_65 ;
break;
case V_206 :
V_53 = F_86 ( & V_163 , V_320 ) ;
type = V_10 ;
break;
case V_226 :
V_53 = F_86 ( & V_163 , V_321 ) ;
type = V_11 ;
break;
}
if ( F_83 ( V_53 < 0 ) ) {
F_7 ( 0 , L_101 , V_19 -> V_174 ) ;
goto V_310;
}
V_85 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_7 ( 0 , L_102 ,
V_85 , V_85 + 1 , V_163 ) ;
V_15 -> V_85 = V_85 ++ ;
V_53 = F_103 ( V_15 , type ) ;
if ( F_83 ( V_53 < 0 ) )
goto V_322;
}
F_44 ( V_171 , L_79 , V_301 ) ;
F_110 ( & V_316 ) ;
return 0 ;
V_322:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_100 ( V_15 ) ;
F_80 () ;
V_310:
F_110 ( & V_316 ) ;
return V_53 ;
}
static void F_111 ( struct V_57 * V_19 )
{
struct V_15 * V_15 ;
F_7 ( 0 , L_54 ) ;
F_109 ( & V_316 ) ;
if ( F_83 ( ! V_317 ) ) {
F_110 ( & V_316 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_100 ( V_15 ) ;
F_80 () ;
V_317 -- ;
F_110 ( & V_316 ) ;
}
static int T_4 F_112 ( void )
{
int V_323 ;
F_7 ( 2 , L_54 ) ;
F_113 () ;
V_323 = F_114 ( & V_324 ) ;
if ( V_323 >= 0 ) {
F_115 ( & V_325 ) ;
if ( F_98 () == V_274 )
F_44 ( V_326 , L_103 ) ;
return 0 ;
}
F_44 ( V_69 , L_104 ,
V_323 ) ;
return V_323 ;
}
static void T_5 F_116 ( void )
{
F_7 ( 2 , L_54 ) ;
F_117 ( & V_324 ) ;
F_118 ( & V_325 ) ;
}
