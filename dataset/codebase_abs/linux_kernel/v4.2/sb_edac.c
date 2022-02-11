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
static T_2 F_30 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_44 , V_45 , & V_1 ) ;
return F_4 ( V_1 , 0 , 2 ) ;
}
static T_2 F_31 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_25 , V_45 , & V_1 ) ;
return F_4 ( V_1 , 0 , 3 ) ;
}
static T_3 F_32 ( struct V_23 * V_24 )
{
T_1 V_1 ;
F_21 ( V_24 -> V_32 . V_46 , V_47 , & V_1 ) ;
return ( F_4 ( V_1 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_33 ( struct V_23 * V_24 )
{
T_3 V_48 ;
T_1 V_1 ;
F_21 ( V_24 -> V_32 . V_46 , V_49 , & V_1 ) ;
V_48 = F_4 ( V_1 , 26 , 31 ) ;
F_21 ( V_24 -> V_32 . V_46 , V_50 , & V_1 ) ;
V_48 = ( ( V_1 << 6 ) | V_48 ) << 26 ;
return V_48 | 0x1ffffff ;
}
static T_3 F_34 ( T_1 V_1 )
{
return ( ( ( T_3 ) F_4 ( V_1 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_35 ( T_2 V_51 )
{
return ( ( V_51 >> 3 ) << 2 ) | ( V_51 & 0x3 ) ;
}
static inline T_2 F_36 ( T_2 V_51 )
{
return ( V_51 >> 2 ) & 0x1 ;
}
static struct V_52 * F_37 ( T_2 V_16 , T_1 V_53 )
{
struct V_52 * V_19 = NULL ;
do {
V_19 = F_38 ( V_54 , V_53 , V_19 ) ;
if ( V_19 && V_19 -> V_16 -> V_55 == V_16 )
break;
} while ( V_19 );
return V_19 ;
}
static int F_39 ( const T_2 V_16 , enum type type )
{
struct V_52 * V_19 = NULL ;
T_1 V_56 , V_53 ;
switch ( type ) {
case V_57 :
V_53 = V_58 ;
break;
case V_10 :
V_53 = V_59 ;
break;
case V_60 :
V_53 = V_61 ;
break;
case V_11 :
V_53 = V_62 ;
break;
default:
return - V_63 ;
}
V_19 = F_37 ( V_16 , V_53 ) ;
if ( ! V_19 ) {
F_40 ( V_64 , L_8
L_9 ,
V_54 , V_53 , V_16 ) ;
return - V_63 ;
}
F_21 ( V_19 , V_41 , & V_56 ) ;
if ( ! F_41 ( V_56 ) ) {
F_40 ( V_64 , L_10 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_42 ( struct V_65 * V_66 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_68 * V_69 ;
unsigned V_70 , V_71 , V_72 , V_8 , V_13 , V_14 , V_73 ;
T_3 V_74 ;
T_1 V_1 ;
enum V_75 V_76 ;
enum V_29 V_30 ;
if ( V_24 -> V_32 . type == V_10 || V_24 -> V_32 . type == V_11 )
F_21 ( V_24 -> V_25 , V_77 , & V_1 ) ;
else
F_21 ( V_24 -> V_44 , V_77 , & V_1 ) ;
V_24 -> V_15 -> V_78 = F_43 ( V_1 ) ;
V_24 -> V_15 -> V_79 = V_24 -> V_32 . F_30 ( V_24 ) ;
F_7 ( 0 , L_11 ,
V_24 -> V_15 -> V_80 ,
V_24 -> V_15 -> V_79 ,
V_24 -> V_15 -> V_78 ) ;
F_21 ( V_24 -> V_81 , V_82 , & V_1 ) ;
if ( F_44 ( V_1 ) ) {
F_7 ( 0 , L_12 ) ;
V_24 -> V_83 = true ;
} else {
F_7 ( 0 , L_13 ) ;
V_24 -> V_83 = false ;
}
F_21 ( V_24 -> V_40 , V_41 , & V_24 -> V_32 . V_56 ) ;
if ( F_45 ( V_24 -> V_32 . V_56 ) ) {
F_7 ( 0 , L_14 ) ;
V_76 = V_84 ;
V_24 -> V_85 = true ;
} else {
F_7 ( 0 , L_15 ) ;
V_76 = V_86 ;
V_24 -> V_85 = false ;
}
if ( F_46 ( V_24 -> V_32 . V_56 ) ) {
F_7 ( 0 , L_16 ) ;
V_24 -> V_87 = true ;
} else {
F_7 ( 0 , L_17 ) ;
V_24 -> V_87 = false ;
}
V_30 = V_24 -> V_32 . F_28 ( V_24 ) ;
if ( V_30 == V_34 || V_30 == V_42 )
F_7 ( 0 , L_18 ) ;
else if ( V_30 == V_36 )
F_7 ( 0 , L_19 ) ;
else
F_7 ( 0 , L_20 ) ;
if ( V_30 == V_43 || V_30 == V_42 )
V_72 = 16 ;
else
V_72 = 8 ;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
T_1 V_7 ;
if ( ! V_24 -> V_89 [ V_70 ] )
continue;
for ( V_71 = 0 ; V_71 < F_47 ( V_90 ) ; V_71 ++ ) {
V_69 = F_48 ( V_66 -> V_91 , V_66 -> V_92 , V_66 -> V_93 ,
V_70 , V_71 , 0 ) ;
F_21 ( V_24 -> V_89 [ V_70 ] ,
V_90 [ V_71 ] , & V_7 ) ;
F_7 ( 4 , L_21 , V_70 , V_71 , V_7 ) ;
if ( F_49 ( V_7 ) ) {
V_24 -> V_94 [ V_70 ] . V_92 ++ ;
V_8 = F_5 ( V_24 -> V_32 . type , V_7 ) ;
V_13 = F_8 ( V_7 ) ;
V_14 = F_10 ( V_7 ) ;
V_74 = ( ( T_3 ) V_13 * V_14 * V_72 * V_8 ) >> ( 20 - 3 ) ;
V_73 = F_50 ( V_74 ) ;
F_7 ( 0 , L_22 ,
V_24 -> V_15 -> V_80 , V_70 / 4 , V_70 % 4 , V_71 ,
V_74 , V_73 ,
V_72 , V_8 , V_13 , V_14 ) ;
V_69 -> V_95 = V_73 ;
V_69 -> V_96 = 32 ;
switch ( V_72 ) {
case 16 :
V_69 -> V_97 = V_98 ;
break;
case 8 :
V_69 -> V_97 = V_99 ;
break;
case 4 :
V_69 -> V_97 = V_100 ;
break;
}
V_69 -> V_30 = V_30 ;
V_69 -> V_101 = V_76 ;
snprintf ( V_69 -> V_102 , sizeof( V_69 -> V_102 ) ,
L_23 ,
V_24 -> V_15 -> V_78 , V_70 / 4 , V_70 % 4 , V_71 ) ;
}
}
}
return 0 ;
}
static void F_51 ( const struct V_65 * V_66 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
int V_70 , V_71 , V_103 , V_104 , V_105 , V_106 ;
T_1 V_1 ;
T_3 V_107 , V_108 = 0 ;
T_3 V_109 ;
T_1 V_110 , V_111 ;
T_1 V_112 ;
V_24 -> V_113 = V_24 -> V_32 . V_114 ( V_24 ) ;
V_109 = ( 1 + V_24 -> V_113 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_24 ,
V_110 , ( V_111 * 1000 ) / 1024 , ( T_3 ) V_24 -> V_113 ) ;
V_24 -> V_115 = V_24 -> V_32 . V_116 ( V_24 ) ;
V_109 = ( 1 + V_24 -> V_115 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_25 ,
V_110 , ( V_111 * 1000 ) / 1024 , ( T_3 ) V_24 -> V_115 ) ;
V_108 = 0 ;
for ( V_104 = 0 ; V_104 < V_24 -> V_32 . V_117 ; V_104 ++ ) {
F_21 ( V_24 -> V_118 , V_24 -> V_32 . V_119 [ V_104 ] ,
& V_1 ) ;
V_107 = F_53 ( V_1 ) ;
if ( ! F_54 ( V_1 ) )
continue;
if ( V_107 <= V_108 )
break;
V_109 = ( V_107 + 1 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_26 ,
V_104 ,
F_1 ( V_1 ) ,
V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
F_55 ( V_1 ) ? L_27 : L_28 ,
V_1 ) ;
V_108 = V_107 ;
F_21 ( V_24 -> V_118 , V_24 -> V_32 . V_120 [ V_104 ] ,
& V_1 ) ;
V_106 = F_3 ( V_24 -> V_32 . V_2 , V_1 , 0 ) ;
for ( V_71 = 0 ; V_71 < 8 ; V_71 ++ ) {
T_1 V_51 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_71 ) ;
if ( V_71 > 0 && V_106 == V_51 )
break;
F_7 ( 0 , L_29 ,
V_104 , V_71 , V_51 ) ;
}
}
V_108 = 0 ;
for ( V_105 = 0 ; V_105 < V_121 ; V_105 ++ ) {
F_21 ( V_24 -> V_122 , V_123 [ V_105 ] ,
& V_1 ) ;
V_107 = F_56 ( V_1 ) ;
if ( V_107 <= V_108 )
break;
V_109 = ( V_107 + 1 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_30 ,
V_105 , V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
( T_1 ) F_57 ( V_1 ) ,
( T_1 ) F_58 ( V_1 ) ,
( T_1 ) F_59 ( V_1 ) ,
( T_1 ) F_60 ( V_1 ) ,
( T_1 ) F_61 ( V_1 ) ,
( T_1 ) F_62 ( V_1 ) ,
V_1 ) ;
V_108 = V_107 ;
}
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_24 -> V_94 [ V_70 ] . V_92 )
continue;
for ( V_71 = 0 ; V_71 < V_105 ; V_71 ++ ) {
F_21 ( V_24 -> V_89 [ V_70 ] ,
V_124 [ V_71 ] ,
& V_1 ) ;
V_109 = F_63 ( V_1 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_31 ,
V_70 , V_71 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
V_1 ) ;
}
}
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_24 -> V_94 [ V_70 ] . V_92 )
continue;
for ( V_71 = 0 ; V_71 < V_125 ; V_71 ++ ) {
F_21 ( V_24 -> V_89 [ V_70 ] ,
V_126 [ V_71 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_109 = V_24 -> V_32 . F_27 ( V_1 ) >> 20 ;
V_112 = 1 << F_65 ( V_1 ) ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_32 ,
V_70 , V_71 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
V_112 ,
V_1 ) ;
for ( V_103 = 0 ; V_103 < V_112 ; V_103 ++ ) {
F_21 ( V_24 -> V_89 [ V_70 ] ,
V_127 [ V_71 ] [ V_103 ] ,
& V_1 ) ;
V_109 = F_66 ( V_1 ) << 6 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_33 ,
V_70 , V_71 , V_103 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
( T_1 ) F_67 ( V_1 ) ,
V_1 ) ;
}
}
}
}
static struct V_65 * F_68 ( T_2 V_79 )
{
struct V_15 * V_15 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_15 -> V_79 == V_79 )
return V_15 -> V_66 ;
}
return NULL ;
}
static int F_69 ( struct V_65 * V_66 ,
T_3 V_128 ,
T_2 * V_129 , T_2 * V_130 ,
long * V_131 ,
T_2 * V_132 ,
char * * V_133 , char * V_134 )
{
struct V_65 * V_135 ;
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_52 * V_136 ;
int V_137 , V_104 , V_105 , V_138 , V_139 ;
int V_106 , V_140 , V_141 ;
int V_142 , V_143 = 0 ;
unsigned V_144 [ V_24 -> V_32 . V_145 ] ;
T_1 V_1 , V_119 ;
T_2 V_146 , V_147 , V_51 , V_148 = 0 , V_149 = 0 ;
T_1 V_150 ;
T_1 V_112 ;
T_1 V_111 , V_110 ;
T_3 V_151 , V_152 , V_107 = 0 , V_108 = 0 ;
if ( ( V_128 > ( T_3 ) V_24 -> V_113 ) && ( V_128 < ( 1LL << 32 ) ) ) {
sprintf ( V_134 , L_34 , V_128 ) ;
return - V_12 ;
}
if ( V_128 >= ( T_3 ) V_24 -> V_115 ) {
sprintf ( V_134 , L_35 , V_128 ) ;
return - V_12 ;
}
for ( V_104 = 0 ; V_104 < V_24 -> V_32 . V_117 ; V_104 ++ ) {
F_21 ( V_24 -> V_118 , V_24 -> V_32 . V_119 [ V_104 ] ,
& V_1 ) ;
if ( ! F_54 ( V_1 ) )
continue;
V_107 = F_53 ( V_1 ) ;
if ( V_107 <= V_108 ) {
sprintf ( V_134 , L_36 ) ;
return - V_12 ;
}
if ( V_128 <= V_107 )
break;
V_108 = V_107 ;
}
if ( V_104 == V_24 -> V_32 . V_117 ) {
sprintf ( V_134 , L_36 ) ;
return - V_12 ;
}
V_119 = V_1 ;
* V_133 = F_1 ( V_119 ) ;
V_142 = F_55 ( V_119 ) ;
F_21 ( V_24 -> V_118 , V_24 -> V_32 . V_120 [ V_104 ] ,
& V_1 ) ;
if ( V_24 -> V_32 . type == V_60 ) {
V_106 = F_3 ( V_24 -> V_32 . V_2 , V_1 , 0 ) ;
for ( V_138 = 0 ; V_138 < 8 ; V_138 ++ ) {
T_1 V_51 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_138 ) ;
if ( V_138 > 0 && V_106 == V_51 )
break;
V_144 [ V_138 ] = V_51 ;
F_7 ( 0 , L_37 ,
V_138 , V_144 [ V_138 ] ) ;
}
F_7 ( 0 , L_38 ,
V_24 -> V_15 -> V_80 ,
V_104 ,
V_128 ,
V_107 ,
V_138 + 7 ,
! V_142 ? L_39 : L_40 ) ;
if ( V_142 )
V_140 = ( ( V_128 >> 6 ) ^ ( V_128 >> 16 ) ) & 7 ;
else
V_140 = ( V_128 >> 6 ) & 7 ;
switch ( V_138 ) {
case 1 :
V_140 = 0 ;
break;
case 2 :
V_140 = V_140 & 1 ;
break;
case 4 :
V_140 = V_140 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_134 , L_41 ) ;
return - V_12 ;
}
* V_129 = V_144 [ V_140 ] ;
F_7 ( 0 , L_42 ,
V_140 , V_138 , * V_129 ) ;
} else if ( V_24 -> V_32 . type == V_10 || V_24 -> V_32 . type == V_11 ) {
int V_153 , V_154 = F_70 ( V_119 ) ;
if ( V_154 ) {
V_153 = F_4 ( V_128 , 7 , 8 ) << 1 ;
V_153 |= F_4 ( V_128 , 9 , 9 ) ;
} else
V_153 = F_4 ( V_128 , 6 , 8 ) ;
if ( V_142 == 0 ) {
V_140 = F_4 ( V_128 , 16 , 18 ) ;
V_140 ^= V_153 ;
} else
V_140 = V_153 ;
V_51 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_140 ) ;
* V_129 = F_35 ( V_51 ) ;
V_148 = F_36 ( V_51 ) ;
if ( V_148 )
V_149 = 4 ;
if ( V_154 ) {
F_21 ( V_24 -> V_122 ,
V_155 , & V_1 ) ;
V_143 = F_4 ( V_1 , 22 , 22 ) ;
}
F_7 ( 0 , L_43 ,
V_140 , * V_129 , V_148 , V_143 ) ;
} else {
V_140 = ( V_128 >> 6 ) & 7 ;
V_51 = F_3 ( V_24 -> V_32 . V_2 , V_1 , V_140 ) ;
* V_129 = F_35 ( V_51 ) ;
V_148 = F_36 ( V_51 ) ;
if ( V_148 )
V_149 = 4 ;
F_7 ( 0 , L_44 ,
V_140 , * V_129 , V_148 ) ;
}
* V_130 = V_148 ;
V_135 = F_68 ( * V_129 ) ;
if ( ! V_135 ) {
sprintf ( V_134 , L_45 ,
* V_129 ) ;
return - V_12 ;
}
V_66 = V_135 ;
V_24 = V_66 -> V_67 ;
V_108 = 0 ;
if ( V_24 -> V_32 . type == V_60 )
V_136 = V_24 -> V_122 ;
else {
if ( V_148 )
V_136 = V_24 -> V_156 ;
else
V_136 = V_24 -> V_122 ;
}
for ( V_105 = 0 ; V_105 < V_121 ; V_105 ++ ) {
F_21 ( V_136 , V_123 [ V_105 ] , & V_1 ) ;
V_107 = F_56 ( V_1 ) ;
if ( V_107 <= V_108 ) {
sprintf ( V_134 , L_46 ) ;
return - V_12 ;
}
if ( V_128 <= V_107 )
break;
V_108 = V_107 ;
}
if ( V_105 == V_121 ) {
sprintf ( V_134 , L_46 ) ;
return - V_12 ;
}
V_146 = F_58 ( V_1 ) + 1 ;
V_147 = F_57 ( V_1 ) + 1 ;
if ( V_146 == 3 )
V_140 = V_128 >> 6 ;
else
V_140 = ( V_128 >> ( 6 + V_147 + V_143 ) ) & 0x3 ;
V_140 = V_140 % V_146 ;
switch ( V_140 ) {
case 0 :
V_141 = F_59 ( V_1 ) ;
break;
case 1 :
V_141 = F_60 ( V_1 ) ;
break;
case 2 :
V_141 = F_61 ( V_1 ) ;
break;
case 3 :
V_141 = F_62 ( V_1 ) ;
break;
default:
sprintf ( V_134 , L_47 ) ;
return - V_12 ;
}
* V_131 = 1 << V_141 ;
F_21 ( V_24 -> V_89 [ V_149 + V_141 ] ,
V_124 [ V_105 ] ,
& V_150 ) ;
if ( V_24 -> V_83 ) {
* V_131 |= 1 << ( ( V_141 + 2 ) % 4 ) ;
switch( V_146 ) {
case 2 :
case 4 :
V_139 = 1 << V_147 * ( V_146 >> 1 ) ;
break;
default:
sprintf ( V_134 , L_48 ) ;
return - V_12 ;
}
} else
V_139 = ( 1 << V_147 ) * V_146 ;
if ( V_24 -> V_85 )
* V_131 |= 1 << ( ( V_141 + 1 ) % 4 ) ;
V_152 = F_63 ( V_150 ) ;
F_7 ( 0 , L_49 ,
V_105 ,
V_128 ,
V_107 ,
( T_1 ) F_57 ( V_1 ) ,
V_146 ,
V_152 ,
V_140 ,
V_141 ,
* V_131 ) ;
if ( V_152 > V_128 ) {
sprintf ( V_134 , L_50 ,
V_152 , V_128 ) ;
return - V_12 ;
}
V_128 -= V_152 ;
V_151 = V_128 & 0x7f ;
V_128 >>= 6 ;
V_128 = F_71 ( V_128 , V_139 ) ;
#if 0
addr = addr / ch_way;
#endif
V_151 |= V_128 << 6 ;
for ( V_137 = 0 ; V_137 < V_125 ; V_137 ++ ) {
F_21 ( V_24 -> V_89 [ V_149 + V_141 ] ,
V_126 [ V_137 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_107 = V_24 -> V_32 . F_27 ( V_1 ) ;
V_110 = F_52 ( V_107 >> 20 , 1024 , & V_111 ) ;
F_7 ( 0 , L_51 ,
V_137 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
V_107 ,
1 << F_65 ( V_1 ) ) ;
if ( V_151 <= V_107 )
break;
}
if ( V_137 == V_125 ) {
sprintf ( V_134 , L_52 ,
V_151 ) ;
return - V_12 ;
}
V_112 = F_65 ( V_1 ) ;
if ( V_24 -> V_87 )
V_140 = ( V_151 >> 6 ) ;
else
V_140 = ( V_151 >> 13 ) ;
V_140 %= 1 << V_112 ;
F_21 ( V_24 -> V_89 [ V_149 + V_141 ] ,
V_127 [ V_137 ] [ V_140 ] ,
& V_1 ) ;
* V_132 = F_67 ( V_1 ) ;
F_7 ( 0 , L_53 ,
V_137 ,
V_151 ,
V_107 ,
V_112 ,
V_140 ) ;
return 0 ;
}
static void F_72 ( struct V_15 * V_15 )
{
int V_70 ;
F_7 ( 0 , L_54 ) ;
for ( V_70 = 0 ; V_70 < V_15 -> V_20 ; V_70 ++ ) {
struct V_52 * V_19 = V_15 -> V_19 [ V_70 ] ;
if ( ! V_19 )
continue;
F_7 ( 0 , L_55 ,
V_19 -> V_16 -> V_55 ,
F_73 ( V_19 -> V_157 ) , F_74 ( V_19 -> V_157 ) ) ;
F_75 ( V_19 ) ;
}
}
static void F_76 ( void )
{
struct V_15 * V_15 , * V_158 ;
F_77 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_72 ( V_15 ) ;
F_18 ( V_15 ) ;
}
}
static int F_78 ( struct V_52 * * V_159 ,
T_2 * V_160 ,
const struct V_17 * V_3 ,
const unsigned V_161 )
{
struct V_15 * V_15 ;
const struct V_162 * V_163 = & V_3 -> V_164 [ V_161 ] ;
struct V_52 * V_19 = NULL ;
T_2 V_16 = 0 ;
F_40 ( V_165 ,
L_56 ,
V_54 , V_163 -> V_166 ) ;
V_19 = F_38 ( V_54 ,
V_163 -> V_166 , * V_159 ) ;
if ( ! V_19 ) {
if ( * V_159 ) {
* V_159 = V_19 ;
return 0 ;
}
if ( V_163 -> V_167 )
return 0 ;
if ( V_161 == 0 )
return - V_63 ;
F_40 ( V_168 ,
L_57 ,
V_54 , V_163 -> V_166 ) ;
return - V_63 ;
}
V_16 = V_19 -> V_16 -> V_55 ;
V_15 = F_12 ( V_16 ) ;
if ( ! V_15 ) {
V_15 = F_14 ( V_16 , V_3 ) ;
if ( ! V_15 ) {
F_75 ( V_19 ) ;
return - V_169 ;
}
( * V_160 ) ++ ;
}
if ( V_15 -> V_19 [ V_161 ] ) {
F_40 ( V_64 ,
L_58 ,
V_54 , V_163 -> V_166 ) ;
F_75 ( V_19 ) ;
return - V_63 ;
}
V_15 -> V_19 [ V_161 ] = V_19 ;
if ( F_79 ( F_80 ( V_19 ) < 0 ) ) {
F_40 ( V_64 ,
L_59 ,
V_54 , V_163 -> V_166 ) ;
return - V_63 ;
}
F_7 ( 0 , L_60 ,
V_54 , V_163 -> V_166 ) ;
F_81 ( V_19 ) ;
* V_159 = V_19 ;
return 0 ;
}
static int F_82 ( T_2 * V_160 ,
const struct V_17 * V_3 )
{
int V_70 , V_48 ;
struct V_52 * V_19 = NULL ;
while ( V_3 && V_3 -> V_164 ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_20 ; V_70 ++ ) {
V_19 = NULL ;
do {
V_48 = F_78 ( & V_19 , V_160 ,
V_3 , V_70 ) ;
if ( V_48 < 0 ) {
if ( V_70 == 0 ) {
V_70 = V_3 -> V_20 ;
break;
}
F_76 () ;
return - V_63 ;
}
} while ( V_19 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_83 ( struct V_65 * V_66 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_52 * V_19 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_15 -> V_20 ; V_70 ++ ) {
V_19 = V_15 -> V_19 [ V_70 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_170 ) {
case V_171 :
V_24 -> V_118 = V_19 ;
break;
case V_172 :
V_24 -> V_25 = V_19 ;
break;
case V_173 :
V_24 -> V_44 = V_19 ;
break;
case V_174 :
V_24 -> V_122 = V_19 ;
break;
case V_61 :
V_24 -> V_40 = V_19 ;
break;
case V_175 :
V_24 -> V_81 = V_19 ;
break;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
{
int V_53 = V_19 -> V_170 - V_176 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
}
break;
case V_180 :
V_24 -> V_31 = V_19 ;
break;
default:
goto error;
}
F_7 ( 0 , L_61 ,
V_19 -> V_181 , V_19 -> V_170 ,
V_15 -> V_16 ,
V_19 ) ;
}
if ( ! V_24 -> V_118 || ! V_24 -> V_25 || ! V_24 -> V_122 ||
! V_24 -> V_89 || ! V_24 -> V_81 || ! V_24 -> V_40 )
goto V_182;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_24 -> V_89 [ V_70 ] )
goto V_182;
}
return 0 ;
V_182:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
error:
F_40 ( V_64 , L_63 ,
V_54 , V_19 -> V_170 ) ;
return - V_12 ;
}
static int F_84 ( struct V_65 * V_66 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_52 * V_19 ;
T_2 V_183 = 0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_15 -> V_20 ; V_70 ++ ) {
V_19 = V_15 -> V_19 [ V_70 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_170 ) {
case V_184 :
V_24 -> V_122 = V_19 ;
break;
case V_58 :
V_24 -> V_40 = V_19 ;
case V_185 :
V_24 -> V_81 = V_19 ;
break;
case V_186 :
case V_187 :
case V_188 :
case V_189 :
{
int V_53 = V_19 -> V_170 - V_186 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
case V_190 :
V_24 -> V_31 = V_19 ;
break;
case V_191 :
V_24 -> V_31 = V_19 ;
break;
case V_192 :
V_24 -> V_118 = V_19 ;
break;
case V_193 :
V_24 -> V_44 = V_19 ;
break;
case V_194 :
V_24 -> V_28 = V_19 ;
break;
case V_195 :
V_24 -> V_156 = V_19 ;
break;
case V_196 :
case V_197 :
case V_198 :
case V_199 :
{
int V_53 = V_19 -> V_170 - V_196 + 4 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_73 ( V_19 -> V_157 ) , F_74 ( V_19 -> V_157 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_118 || ! V_24 -> V_122 || ! V_24 -> V_44 ||
! V_24 -> V_28 || ! V_24 -> V_89 || ! V_24 -> V_81 ||
! V_24 -> V_40 )
goto V_182;
if ( V_183 != 0x0f &&
V_183 != 0x33 &&
V_183 != 0xff )
goto V_182;
return 0 ;
V_182:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
error:
F_40 ( V_64 ,
L_63 , V_54 ,
V_19 -> V_170 ) ;
return - V_12 ;
}
static int F_85 ( struct V_65 * V_66 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_52 * V_19 ;
T_2 V_183 = 0 ;
int V_70 ;
if ( V_24 -> V_32 . V_46 == NULL )
V_24 -> V_32 . V_46 = F_38 ( V_54 ,
V_200 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_15 -> V_20 ; V_70 ++ ) {
V_19 = V_15 -> V_19 [ V_70 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_170 ) {
case V_201 :
V_24 -> V_118 = V_19 ;
break;
case V_202 :
V_24 -> V_25 = V_19 ;
break;
case V_203 :
V_24 -> V_122 = V_19 ;
break;
case V_59 :
V_24 -> V_40 = V_19 ;
break;
case V_204 :
V_24 -> V_81 = V_19 ;
break;
case V_205 :
case V_206 :
case V_207 :
case V_208 :
{
int V_53 = V_19 -> V_170 - V_205 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
{
int V_53 = V_19 -> V_170 - V_209 + 4 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
case V_213 :
V_24 -> V_31 = V_19 ;
break;
case V_214 :
V_24 -> V_156 = V_19 ;
break;
case V_215 :
V_24 -> V_216 = V_19 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_73 ( V_19 -> V_157 ) , F_74 ( V_19 -> V_157 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_118 || ! V_24 -> V_122 || ! V_24 -> V_25 ||
! V_24 -> V_81 || ! V_24 -> V_40 || ! V_24 -> V_32 . V_46 )
goto V_182;
if ( V_183 != 0x0f &&
V_183 != 0x33 &&
V_183 != 0xff )
goto V_182;
return 0 ;
V_182:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
}
static int F_86 ( struct V_65 * V_66 ,
struct V_15 * V_15 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
struct V_52 * V_19 ;
T_2 V_183 = 0 ;
int V_70 ;
if ( V_24 -> V_32 . V_46 == NULL )
V_24 -> V_32 . V_46 = F_38 ( V_54 ,
V_217 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_15 -> V_20 ; V_70 ++ ) {
V_19 = V_15 -> V_19 [ V_70 ] ;
if ( ! V_19 )
continue;
switch ( V_19 -> V_170 ) {
case V_218 :
V_24 -> V_118 = V_19 ;
break;
case V_219 :
V_24 -> V_25 = V_19 ;
break;
case V_220 :
V_24 -> V_122 = V_19 ;
break;
case V_62 :
V_24 -> V_40 = V_19 ;
break;
case V_221 :
V_24 -> V_81 = V_19 ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
{
int V_53 = V_19 -> V_170 - V_222 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
{
int V_53 = V_19 -> V_170 - V_226 + 4 ;
V_24 -> V_89 [ V_53 ] = V_19 ;
V_183 |= 1 << V_53 ;
}
break;
case V_230 :
V_24 -> V_31 = V_19 ;
break;
case V_231 :
V_24 -> V_156 = V_19 ;
break;
case V_232 :
V_24 -> V_216 = V_19 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_15 -> V_16 ,
F_73 ( V_19 -> V_157 ) , F_74 ( V_19 -> V_157 ) ,
V_19 ) ;
}
if ( ! V_24 -> V_118 || ! V_24 -> V_122 || ! V_24 -> V_25 ||
! V_24 -> V_81 || ! V_24 -> V_40 || ! V_24 -> V_32 . V_46 )
goto V_182;
if ( V_183 != 0x0f &&
V_183 != 0x33 &&
V_183 != 0xff )
goto V_182;
return 0 ;
V_182:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
}
static void F_87 ( struct V_65 * V_66 ,
const struct V_233 * V_234 )
{
struct V_65 * V_135 ;
struct V_23 * V_24 = V_66 -> V_67 ;
enum V_235 V_236 ;
char * type , * V_237 , V_134 [ 256 ] ;
bool V_238 = F_4 ( V_234 -> V_239 , 0 , 0 ) ;
bool V_240 = F_4 ( V_234 -> V_241 , 62 , 62 ) ;
bool V_242 = F_4 ( V_234 -> V_241 , 61 , 61 ) ;
bool V_243 ;
T_1 V_244 = F_4 ( V_234 -> V_241 , 38 , 52 ) ;
T_1 V_245 = F_4 ( V_234 -> V_241 , 16 , 31 ) ;
T_1 V_246 = F_4 ( V_234 -> V_241 , 0 , 15 ) ;
T_1 V_94 = F_4 ( V_234 -> V_241 , 0 , 3 ) ;
T_1 V_247 = F_4 ( V_234 -> V_241 , 4 , 6 ) ;
long V_131 , V_248 ;
T_2 V_132 , V_129 , V_130 ;
int V_48 , V_69 ;
char * V_133 = NULL ;
if ( V_24 -> V_32 . type != V_60 )
V_243 = true ;
else
V_243 = F_4 ( V_234 -> V_241 , 56 , 56 ) ;
if ( V_242 ) {
if ( V_238 ) {
type = L_65 ;
V_236 = V_249 ;
} else {
type = L_66 ;
V_236 = V_250 ;
}
} else {
type = L_67 ;
V_236 = V_251 ;
}
if ( ! ( ( V_246 & 0xef80 ) == 0x80 ) ) {
V_237 = L_68 ;
} else {
switch ( V_247 ) {
case 0 :
V_237 = L_69 ;
break;
case 1 :
V_237 = L_70 ;
break;
case 2 :
V_237 = L_71 ;
break;
case 3 :
V_237 = L_72 ;
break;
case 4 :
V_237 = L_73 ;
break;
default:
V_237 = L_74 ;
break;
}
}
if ( ! F_4 ( V_234 -> V_241 , 58 , 58 ) )
return;
V_48 = F_69 ( V_66 , V_234 -> V_128 , & V_129 , & V_130 ,
& V_131 , & V_132 , & V_133 , V_134 ) ;
if ( V_48 < 0 )
goto V_252;
V_135 = F_68 ( V_129 ) ;
if ( ! V_135 ) {
strcpy ( V_134 , L_75 ) ;
goto V_252;
}
V_66 = V_135 ;
V_24 = V_66 -> V_67 ;
V_248 = F_88 ( & V_131 , V_88 ) ;
if ( V_132 < 4 )
V_69 = 0 ;
else if ( V_132 < 8 )
V_69 = 1 ;
else
V_69 = 2 ;
if ( ! V_24 -> V_85 && ! V_24 -> V_83 && ! V_24 -> V_87 )
V_94 = V_248 ;
snprintf ( V_134 , sizeof( V_134 ) ,
L_76 ,
V_240 ? L_77 : L_39 ,
( V_242 && V_243 ) ? L_78 : L_39 ,
V_133 ,
V_245 , V_246 ,
V_129 , V_130 ,
V_131 ,
V_132 ) ;
F_7 ( 0 , L_79 , V_134 ) ;
if ( V_94 == V_253 )
V_94 = - 1 ;
F_89 ( V_236 , V_66 , V_244 ,
V_234 -> V_128 >> V_254 , V_234 -> V_128 & ~ V_255 , 0 ,
4 * V_130 + V_94 , V_69 , - 1 ,
V_237 , V_134 ) ;
return;
V_252:
F_89 ( V_236 , V_66 , V_244 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_134 , L_39 ) ;
}
static void F_90 ( struct V_65 * V_66 )
{
struct V_23 * V_24 = V_66 -> V_67 ;
int V_70 ;
unsigned V_256 = 0 ;
struct V_233 * V_234 ;
F_91 () ;
V_256 = ( V_24 -> V_257 + V_258 - V_24 -> V_259 )
% V_258 ;
if ( ! V_256 )
return;
V_234 = V_24 -> V_260 ;
if ( V_24 -> V_259 + V_256 > V_258 ) {
unsigned V_261 = V_258 - V_24 -> V_259 ;
memcpy ( V_234 , & V_24 -> V_262 [ V_24 -> V_259 ] , sizeof( * V_234 ) * V_261 ) ;
F_92 () ;
V_24 -> V_259 = 0 ;
V_256 -= V_261 ;
V_234 += V_261 ;
}
memcpy ( V_234 , & V_24 -> V_262 [ V_24 -> V_259 ] , sizeof( * V_234 ) * V_256 ) ;
F_92 () ;
V_24 -> V_259 += V_256 ;
F_91 () ;
if ( V_24 -> V_263 ) {
F_40 ( V_64 , L_80 ,
V_24 -> V_263 ) ;
F_92 () ;
V_24 -> V_263 = 0 ;
}
for ( V_70 = 0 ; V_70 < V_256 ; V_70 ++ )
F_87 ( V_66 , & V_24 -> V_260 [ V_70 ] ) ;
}
static int F_93 ( struct V_264 * V_265 , unsigned long V_266 ,
void * V_267 )
{
struct V_233 * V_233 = (struct V_233 * ) V_267 ;
struct V_65 * V_66 ;
struct V_23 * V_24 ;
char * type ;
if ( F_94 () == V_268 )
return V_269 ;
V_66 = F_68 ( V_233 -> V_270 ) ;
if ( ! V_66 )
return V_271 ;
V_24 = V_66 -> V_67 ;
if ( ( V_233 -> V_241 & 0xefff ) >> 7 != 1 )
return V_269 ;
if ( V_233 -> V_239 & V_272 )
type = L_81 ;
else
type = L_82 ;
F_95 ( V_66 , V_165 , L_83 ) ;
F_95 ( V_66 , V_165 , L_84
L_85 , V_233 -> V_273 , type ,
V_233 -> V_239 , V_233 -> V_274 , V_233 -> V_241 ) ;
F_95 ( V_66 , V_165 , L_86 , V_233 -> V_275 ) ;
F_95 ( V_66 , V_165 , L_87 , V_233 -> V_128 ) ;
F_95 ( V_66 , V_165 , L_88 , V_233 -> V_276 ) ;
F_95 ( V_66 , V_165 , L_89
L_90 , V_233 -> V_277 , V_233 -> V_278 ,
V_233 -> time , V_233 -> V_270 , V_233 -> V_279 ) ;
F_91 () ;
if ( ( V_24 -> V_257 + 1 ) % V_258 == V_24 -> V_259 ) {
F_92 () ;
V_24 -> V_263 ++ ;
return V_269 ;
}
memcpy ( & V_24 -> V_262 [ V_24 -> V_257 ] , V_233 , sizeof( * V_233 ) ) ;
F_92 () ;
V_24 -> V_257 = ( V_24 -> V_257 + 1 ) % V_258 ;
if ( V_233 -> V_239 & 1 )
F_90 ( V_66 ) ;
return V_280 ;
}
static void F_96 ( struct V_15 * V_15 )
{
struct V_65 * V_66 = V_15 -> V_66 ;
struct V_23 * V_24 ;
if ( F_79 ( ! V_66 || ! V_66 -> V_67 ) ) {
F_7 ( 0 , L_91 , & V_15 -> V_19 [ 0 ] -> V_281 ) ;
F_40 ( V_64 , L_92 ) ;
return;
}
V_24 = V_66 -> V_67 ;
F_7 ( 0 , L_93 ,
V_66 , & V_15 -> V_19 [ 0 ] -> V_281 ) ;
F_97 ( V_66 -> V_19 ) ;
F_7 ( 1 , L_94 , V_66 -> V_282 ) ;
F_16 ( V_66 -> V_282 ) ;
F_98 ( V_66 ) ;
V_15 -> V_66 = NULL ;
}
static int F_99 ( struct V_15 * V_15 , enum type type )
{
struct V_65 * V_66 ;
struct V_283 V_91 [ 2 ] ;
struct V_23 * V_24 ;
struct V_52 * V_19 = V_15 -> V_19 [ 0 ] ;
int V_48 ;
V_48 = F_39 ( V_15 -> V_16 , type ) ;
if ( F_79 ( V_48 < 0 ) )
return V_48 ;
V_91 [ 0 ] . type = V_284 ;
V_91 [ 0 ] . V_74 = V_88 ;
V_91 [ 0 ] . V_285 = false ;
V_91 [ 1 ] . type = V_286 ;
V_91 [ 1 ] . V_74 = V_287 ;
V_91 [ 1 ] . V_285 = true ;
V_66 = F_100 ( V_15 -> V_80 , F_47 ( V_91 ) , V_91 ,
sizeof( * V_24 ) ) ;
if ( F_79 ( ! V_66 ) )
return - V_169 ;
F_7 ( 0 , L_93 ,
V_66 , & V_19 -> V_281 ) ;
V_24 = V_66 -> V_67 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_15 = V_15 ;
V_15 -> V_66 = V_66 ;
V_66 -> V_288 = V_289 ;
V_66 -> V_290 = V_291 ;
V_66 -> V_292 = V_291 ;
V_66 -> V_293 = L_95 ;
V_66 -> V_294 = V_295 ;
V_66 -> V_296 = F_101 ( V_19 ) ;
V_66 -> V_297 = NULL ;
V_66 -> V_298 = F_90 ;
V_24 -> V_32 . type = type ;
switch ( type ) {
case V_57 :
V_24 -> V_32 . V_33 = V_299 ;
V_24 -> V_32 . V_114 = F_25 ;
V_24 -> V_32 . V_116 = F_26 ;
V_24 -> V_32 . V_119 = V_300 ;
V_24 -> V_32 . F_28 = F_28 ;
V_24 -> V_32 . F_30 = F_30 ;
V_24 -> V_32 . F_27 = F_27 ;
V_24 -> V_32 . V_117 = F_47 ( V_300 ) ;
V_24 -> V_32 . V_120 = V_301 ;
V_24 -> V_32 . V_145 = F_47 ( V_301 ) ;
V_24 -> V_32 . V_2 = V_302 ;
V_66 -> V_282 = F_102 ( V_18 , L_96 , V_66 -> V_303 ) ;
V_48 = F_84 ( V_66 , V_15 ) ;
if ( F_79 ( V_48 < 0 ) )
goto V_304;
break;
case V_60 :
V_24 -> V_32 . V_33 = V_305 ;
V_24 -> V_32 . V_114 = F_20 ;
V_24 -> V_32 . V_116 = F_23 ;
V_24 -> V_32 . V_119 = V_306 ;
V_24 -> V_32 . F_28 = F_28 ;
V_24 -> V_32 . F_30 = F_30 ;
V_24 -> V_32 . F_27 = F_27 ;
V_24 -> V_32 . V_117 = F_47 ( V_306 ) ;
V_24 -> V_32 . V_120 = V_307 ;
V_24 -> V_32 . V_145 = F_47 ( V_307 ) ;
V_24 -> V_32 . V_2 = V_308 ;
V_66 -> V_282 = F_102 ( V_18 , L_97 , V_66 -> V_303 ) ;
V_48 = F_83 ( V_66 , V_15 ) ;
if ( F_79 ( V_48 < 0 ) )
goto V_304;
break;
case V_10 :
V_24 -> V_32 . V_114 = F_32 ;
V_24 -> V_32 . V_116 = F_33 ;
V_24 -> V_32 . V_119 = V_300 ;
V_24 -> V_32 . F_28 = F_29 ;
V_24 -> V_32 . F_30 = F_31 ;
V_24 -> V_32 . F_27 = F_34 ;
V_24 -> V_32 . V_117 = F_47 ( V_300 ) ;
V_24 -> V_32 . V_120 = V_301 ;
V_24 -> V_32 . V_145 = F_47 ( V_301 ) ;
V_24 -> V_32 . V_2 = V_302 ;
V_66 -> V_282 = F_102 ( V_18 , L_98 , V_66 -> V_303 ) ;
V_48 = F_85 ( V_66 , V_15 ) ;
if ( F_79 ( V_48 < 0 ) )
goto V_304;
break;
case V_11 :
V_24 -> V_32 . V_114 = F_32 ;
V_24 -> V_32 . V_116 = F_33 ;
V_24 -> V_32 . V_119 = V_300 ;
V_24 -> V_32 . F_28 = F_29 ;
V_24 -> V_32 . F_30 = F_31 ;
V_24 -> V_32 . F_27 = F_34 ;
V_24 -> V_32 . V_117 = F_47 ( V_300 ) ;
V_24 -> V_32 . V_120 = V_301 ;
V_24 -> V_32 . V_145 = F_47 ( V_301 ) ;
V_24 -> V_32 . V_2 = V_302 ;
V_66 -> V_282 = F_102 ( V_18 , L_99 , V_66 -> V_303 ) ;
V_48 = F_86 ( V_66 , V_15 ) ;
if ( F_79 ( V_48 < 0 ) )
goto V_304;
break;
}
F_42 ( V_66 ) ;
F_51 ( V_66 ) ;
V_66 -> V_19 = & V_19 -> V_281 ;
if ( F_79 ( F_103 ( V_66 ) ) ) {
F_7 ( 0 , L_100 ) ;
V_48 = - V_12 ;
goto V_304;
}
return 0 ;
V_304:
F_16 ( V_66 -> V_282 ) ;
F_98 ( V_66 ) ;
V_15 -> V_66 = NULL ;
return V_48 ;
}
static int F_104 ( struct V_52 * V_19 , const struct V_309 * V_53 )
{
int V_48 = - V_63 ;
T_2 V_80 , V_160 = 0 ;
struct V_15 * V_15 ;
enum type type = V_60 ;
F_105 ( & V_310 ) ;
if ( F_79 ( V_311 >= 1 ) ) {
F_106 ( & V_310 ) ;
return - V_63 ;
}
V_311 ++ ;
switch ( V_19 -> V_170 ) {
case V_58 :
V_48 = F_82 ( & V_160 , V_312 ) ;
type = V_57 ;
break;
case V_174 :
V_48 = F_82 ( & V_160 , V_313 ) ;
type = V_60 ;
break;
case V_203 :
V_48 = F_82 ( & V_160 , V_314 ) ;
type = V_10 ;
break;
case V_220 :
V_48 = F_82 ( & V_160 , V_315 ) ;
type = V_11 ;
break;
}
if ( F_79 ( V_48 < 0 ) ) {
F_7 ( 0 , L_101 , V_19 -> V_170 ) ;
goto V_304;
}
V_80 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_7 ( 0 , L_102 ,
V_80 , V_80 + 1 , V_160 ) ;
V_15 -> V_80 = V_80 ++ ;
V_48 = F_99 ( V_15 , type ) ;
if ( F_79 ( V_48 < 0 ) )
goto V_316;
}
F_40 ( V_168 , L_79 , V_295 ) ;
F_106 ( & V_310 ) ;
return 0 ;
V_316:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_96 ( V_15 ) ;
F_76 () ;
V_304:
F_106 ( & V_310 ) ;
return V_48 ;
}
static void F_107 ( struct V_52 * V_19 )
{
struct V_15 * V_15 ;
F_7 ( 0 , L_54 ) ;
F_105 ( & V_310 ) ;
if ( F_79 ( ! V_311 ) ) {
F_106 ( & V_310 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_96 ( V_15 ) ;
F_76 () ;
V_311 -- ;
F_106 ( & V_310 ) ;
}
static int T_4 F_108 ( void )
{
int V_317 ;
F_7 ( 2 , L_54 ) ;
F_109 () ;
V_317 = F_110 ( & V_318 ) ;
if ( V_317 >= 0 ) {
F_111 ( & V_319 ) ;
if ( F_94 () == V_268 )
F_40 ( V_320 , L_103 ) ;
return 0 ;
}
F_40 ( V_64 , L_104 ,
V_317 ) ;
return V_317 ;
}
static void T_5 F_112 ( void )
{
F_7 ( 2 , L_54 ) ;
F_113 ( & V_318 ) ;
F_114 ( & V_319 ) ;
}
