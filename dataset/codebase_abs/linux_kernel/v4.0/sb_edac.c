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
if ( type == V_10 )
V_9 = 8 ;
if ( V_8 > V_9 ) {
F_7 ( 0 , L_5 ,
V_8 , V_9 , ( unsigned int ) F_6 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return V_8 ;
}
static inline int F_8 ( T_1 V_7 )
{
int V_12 = ( F_9 ( V_7 ) + 12 ) ;
if ( V_12 < 13 || V_12 > 18 ) {
F_7 ( 0 , L_6 ,
V_12 , ( unsigned int ) F_9 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return 1 << V_12 ;
}
static inline int F_10 ( T_1 V_7 )
{
int V_13 = ( F_11 ( V_7 ) + 10 ) ;
if ( V_13 > 12 ) {
F_7 ( 0 , L_7 ,
V_13 , ( unsigned int ) F_11 ( V_7 ) , V_7 ) ;
return - V_11 ;
}
return 1 << V_13 ;
}
static struct V_14 * F_12 ( T_2 V_15 )
{
struct V_14 * V_14 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_14 -> V_15 == V_15 )
return V_14 ;
}
return NULL ;
}
static struct V_14 * F_14 ( T_2 V_15 ,
const struct V_16 * V_3 )
{
struct V_14 * V_14 ;
V_14 = F_15 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_18 = F_15 ( sizeof( * V_14 -> V_18 ) * V_3 -> V_19 ,
V_17 ) ;
if ( ! V_14 -> V_18 ) {
F_16 ( V_14 ) ;
return NULL ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_19 = V_3 -> V_19 ;
F_17 ( & V_14 -> V_20 , & V_21 ) ;
return V_14 ;
}
static void F_18 ( struct V_14 * V_14 )
{
F_19 ( & V_14 -> V_20 ) ;
F_16 ( V_14 -> V_18 ) ;
F_16 ( V_14 ) ;
}
static T_3 F_20 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_25 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_23 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_26 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_25 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_27 , V_25 , & V_1 ) ;
return F_22 ( V_1 ) ;
}
static T_3 F_26 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_27 , V_26 , & V_1 ) ;
return F_24 ( V_1 ) ;
}
static T_3 F_27 ( T_1 V_1 )
{
return ( ( T_3 ) F_4 ( V_1 , 1 , 10 ) << 29 ) | 0x1fffffff ;
}
static enum V_28 F_28 ( struct V_22 * V_23 )
{
T_1 V_1 ;
enum V_28 V_29 ;
if ( V_23 -> V_30 ) {
F_21 ( V_23 -> V_30 , V_23 -> V_31 . V_32 ,
& V_1 ) ;
if ( F_4 ( V_1 , 11 , 11 ) )
V_29 = V_33 ;
else
V_29 = V_34 ;
} else
V_29 = V_35 ;
return V_29 ;
}
static enum V_28 F_29 ( struct V_22 * V_23 )
{
T_1 V_1 ;
bool V_36 = false ;
enum V_28 V_29 = V_35 ;
if ( ! V_23 -> V_30 )
goto V_37;
F_21 ( V_23 -> V_30 ,
V_38 , & V_1 ) ;
if ( F_4 ( V_1 , 16 , 16 ) )
V_36 = true ;
F_21 ( V_23 -> V_39 , V_40 , & V_1 ) ;
if ( F_4 ( V_1 , 14 , 14 ) ) {
if ( V_36 )
V_29 = V_41 ;
else
V_29 = V_42 ;
} else {
if ( V_36 )
V_29 = V_33 ;
else
V_29 = V_34 ;
}
V_37:
return V_29 ;
}
static T_2 F_30 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_43 , V_44 , & V_1 ) ;
return F_4 ( V_1 , 0 , 2 ) ;
}
static T_2 F_31 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_24 , V_44 , & V_1 ) ;
return F_4 ( V_1 , 0 , 3 ) ;
}
static T_3 F_32 ( struct V_22 * V_23 )
{
T_1 V_1 ;
F_21 ( V_23 -> V_31 . V_45 , V_46 , & V_1 ) ;
return ( F_4 ( V_1 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_33 ( struct V_22 * V_23 )
{
T_3 V_47 ;
T_1 V_1 ;
F_21 ( V_23 -> V_31 . V_45 , V_48 , & V_1 ) ;
V_47 = F_4 ( V_1 , 26 , 31 ) ;
F_21 ( V_23 -> V_31 . V_45 , V_49 , & V_1 ) ;
V_47 = ( ( V_1 << 6 ) | V_47 ) << 26 ;
return V_47 | 0x1ffffff ;
}
static T_3 F_34 ( T_1 V_1 )
{
return ( ( ( T_3 ) F_4 ( V_1 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_35 ( T_2 V_50 )
{
return ( ( V_50 >> 3 ) << 2 ) | ( V_50 & 0x3 ) ;
}
static inline T_2 F_36 ( T_2 V_50 )
{
return ( V_50 >> 2 ) & 0x1 ;
}
static struct V_51 * F_37 ( T_2 V_15 , T_1 V_52 )
{
struct V_51 * V_18 = NULL ;
do {
V_18 = F_38 ( V_53 , V_52 , V_18 ) ;
if ( V_18 && V_18 -> V_15 -> V_54 == V_15 )
break;
} while ( V_18 );
return V_18 ;
}
static int F_39 ( const T_2 V_15 , enum type type )
{
struct V_51 * V_18 = NULL ;
T_1 V_55 , V_52 ;
switch ( type ) {
case V_56 :
V_52 = V_57 ;
break;
case V_10 :
V_52 = V_58 ;
break;
case V_59 :
V_52 = V_60 ;
break;
case V_61 :
V_52 = V_62 ;
break;
default:
return - V_63 ;
}
V_18 = F_37 ( V_15 , V_52 ) ;
if ( ! V_18 ) {
F_40 ( V_64 , L_8
L_9 ,
V_53 , V_52 , V_15 ) ;
return - V_63 ;
}
F_21 ( V_18 , V_40 , & V_55 ) ;
if ( ! F_41 ( V_55 ) ) {
F_40 ( V_64 , L_10 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_42 ( struct V_65 * V_66 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_68 * V_69 ;
unsigned V_70 , V_71 , V_72 , V_8 , V_12 , V_13 , V_73 ;
T_3 V_74 ;
T_1 V_1 ;
enum V_75 V_76 ;
enum V_28 V_29 ;
if ( V_23 -> V_31 . type == V_10 || V_23 -> V_31 . type == V_61 )
F_21 ( V_23 -> V_24 , V_77 , & V_1 ) ;
else
F_21 ( V_23 -> V_43 , V_77 , & V_1 ) ;
V_23 -> V_14 -> V_78 = F_43 ( V_1 ) ;
V_23 -> V_14 -> V_79 = V_23 -> V_31 . F_30 ( V_23 ) ;
F_7 ( 0 , L_11 ,
V_23 -> V_14 -> V_80 ,
V_23 -> V_14 -> V_79 ,
V_23 -> V_14 -> V_78 ) ;
F_21 ( V_23 -> V_81 , V_82 , & V_1 ) ;
if ( F_44 ( V_1 ) ) {
F_7 ( 0 , L_12 ) ;
V_23 -> V_83 = true ;
} else {
F_7 ( 0 , L_13 ) ;
V_23 -> V_83 = false ;
}
F_21 ( V_23 -> V_39 , V_40 , & V_23 -> V_31 . V_55 ) ;
if ( F_45 ( V_23 -> V_31 . V_55 ) ) {
F_7 ( 0 , L_14 ) ;
V_76 = V_84 ;
V_23 -> V_85 = true ;
} else {
F_7 ( 0 , L_15 ) ;
V_76 = V_86 ;
V_23 -> V_85 = false ;
}
if ( F_46 ( V_23 -> V_31 . V_55 ) ) {
F_7 ( 0 , L_16 ) ;
V_23 -> V_87 = true ;
} else {
F_7 ( 0 , L_17 ) ;
V_23 -> V_87 = false ;
}
V_29 = V_23 -> V_31 . F_28 ( V_23 ) ;
if ( V_29 == V_33 || V_29 == V_41 )
F_7 ( 0 , L_18 ) ;
else if ( V_29 == V_35 )
F_7 ( 0 , L_19 ) ;
else
F_7 ( 0 , L_20 ) ;
if ( V_29 == V_42 || V_29 == V_41 )
V_72 = 16 ;
else
V_72 = 8 ;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
T_1 V_7 ;
for ( V_71 = 0 ; V_71 < F_47 ( V_89 ) ; V_71 ++ ) {
V_69 = F_48 ( V_66 -> V_90 , V_66 -> V_91 , V_66 -> V_92 ,
V_70 , V_71 , 0 ) ;
F_21 ( V_23 -> V_93 [ V_70 ] ,
V_89 [ V_71 ] , & V_7 ) ;
F_7 ( 4 , L_21 , V_70 , V_71 , V_7 ) ;
if ( F_49 ( V_7 ) ) {
V_23 -> V_94 [ V_70 ] . V_91 ++ ;
V_8 = F_5 ( V_23 -> V_31 . type , V_7 ) ;
V_12 = F_8 ( V_7 ) ;
V_13 = F_10 ( V_7 ) ;
V_74 = ( ( T_3 ) V_12 * V_13 * V_72 * V_8 ) >> ( 20 - 3 ) ;
V_73 = F_50 ( V_74 ) ;
F_7 ( 0 , L_22 ,
V_23 -> V_14 -> V_80 , V_70 , V_71 ,
V_74 , V_73 ,
V_72 , V_8 , V_12 , V_13 ) ;
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
V_69 -> V_29 = V_29 ;
V_69 -> V_101 = V_76 ;
snprintf ( V_69 -> V_102 , sizeof( V_69 -> V_102 ) ,
L_23 ,
V_23 -> V_14 -> V_78 , V_70 , V_71 ) ;
}
}
}
return 0 ;
}
static void F_51 ( const struct V_65 * V_66 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
int V_70 , V_71 , V_103 , V_104 , V_105 , V_106 ;
T_1 V_1 ;
T_3 V_107 , V_108 = 0 ;
T_3 V_109 ;
T_1 V_110 , V_111 ;
T_1 V_112 ;
V_23 -> V_113 = V_23 -> V_31 . V_114 ( V_23 ) ;
V_109 = ( 1 + V_23 -> V_113 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_24 ,
V_110 , ( V_111 * 1000 ) / 1024 , ( T_3 ) V_23 -> V_113 ) ;
V_23 -> V_115 = V_23 -> V_31 . V_116 ( V_23 ) ;
V_109 = ( 1 + V_23 -> V_115 ) >> 20 ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_25 ,
V_110 , ( V_111 * 1000 ) / 1024 , ( T_3 ) V_23 -> V_115 ) ;
V_108 = 0 ;
for ( V_104 = 0 ; V_104 < V_23 -> V_31 . V_117 ; V_104 ++ ) {
F_21 ( V_23 -> V_118 , V_23 -> V_31 . V_119 [ V_104 ] ,
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
F_21 ( V_23 -> V_118 , V_23 -> V_31 . V_120 [ V_104 ] ,
& V_1 ) ;
V_106 = F_3 ( V_23 -> V_31 . V_2 , V_1 , 0 ) ;
for ( V_71 = 0 ; V_71 < 8 ; V_71 ++ ) {
T_1 V_50 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_71 ) ;
if ( V_71 > 0 && V_106 == V_50 )
break;
F_7 ( 0 , L_29 ,
V_104 , V_71 , V_50 ) ;
}
}
V_108 = 0 ;
for ( V_105 = 0 ; V_105 < V_121 ; V_105 ++ ) {
F_21 ( V_23 -> V_122 , V_123 [ V_105 ] ,
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
if ( ! V_23 -> V_94 [ V_70 ] . V_91 )
continue;
for ( V_71 = 0 ; V_71 < V_105 ; V_71 ++ ) {
F_21 ( V_23 -> V_93 [ V_70 ] ,
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
if ( ! V_23 -> V_94 [ V_70 ] . V_91 )
continue;
for ( V_71 = 0 ; V_71 < V_125 ; V_71 ++ ) {
F_21 ( V_23 -> V_93 [ V_70 ] ,
V_126 [ V_71 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_109 = V_23 -> V_31 . F_27 ( V_1 ) >> 20 ;
V_112 = 1 << F_65 ( V_1 ) ;
V_110 = F_52 ( V_109 , 1024 , & V_111 ) ;
F_7 ( 0 , L_32 ,
V_70 , V_71 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
( ( T_3 ) V_109 ) << 20L ,
V_112 ,
V_1 ) ;
for ( V_103 = 0 ; V_103 < V_112 ; V_103 ++ ) {
F_21 ( V_23 -> V_93 [ V_70 ] ,
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
struct V_14 * V_14 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_14 -> V_79 == V_79 )
return V_14 -> V_66 ;
}
return NULL ;
}
static int F_69 ( struct V_65 * V_66 ,
T_3 V_128 ,
T_2 * V_129 ,
long * V_130 ,
T_2 * V_131 ,
char * * V_132 , char * V_133 )
{
struct V_65 * V_134 ;
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_51 * V_135 ;
int V_136 , V_104 , V_105 , V_137 , V_138 ;
int V_106 , V_139 , V_140 ;
int V_141 , V_142 = 0 ;
unsigned V_143 [ V_23 -> V_31 . V_144 ] ;
T_1 V_1 , V_119 ;
T_2 V_145 , V_146 , V_50 , V_147 = 0 ;
T_1 V_148 ;
T_1 V_112 ;
T_1 V_111 , V_110 ;
T_3 V_149 , V_150 , V_107 = 0 , V_108 = 0 ;
if ( ( V_128 > ( T_3 ) V_23 -> V_113 ) && ( V_128 < ( 1LL << 32 ) ) ) {
sprintf ( V_133 , L_34 , V_128 ) ;
return - V_11 ;
}
if ( V_128 >= ( T_3 ) V_23 -> V_115 ) {
sprintf ( V_133 , L_35 , V_128 ) ;
return - V_11 ;
}
for ( V_104 = 0 ; V_104 < V_23 -> V_31 . V_117 ; V_104 ++ ) {
F_21 ( V_23 -> V_118 , V_23 -> V_31 . V_119 [ V_104 ] ,
& V_1 ) ;
if ( ! F_54 ( V_1 ) )
continue;
V_107 = F_53 ( V_1 ) ;
if ( V_107 <= V_108 ) {
sprintf ( V_133 , L_36 ) ;
return - V_11 ;
}
if ( V_128 <= V_107 )
break;
V_108 = V_107 ;
}
if ( V_104 == V_23 -> V_31 . V_117 ) {
sprintf ( V_133 , L_36 ) ;
return - V_11 ;
}
V_119 = V_1 ;
* V_132 = F_1 ( V_119 ) ;
V_141 = F_55 ( V_119 ) ;
F_21 ( V_23 -> V_118 , V_23 -> V_31 . V_120 [ V_104 ] ,
& V_1 ) ;
if ( V_23 -> V_31 . type == V_59 ) {
V_106 = F_3 ( V_23 -> V_31 . V_2 , V_1 , 0 ) ;
for ( V_137 = 0 ; V_137 < 8 ; V_137 ++ ) {
T_1 V_50 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_137 ) ;
if ( V_137 > 0 && V_106 == V_50 )
break;
V_143 [ V_137 ] = V_50 ;
F_7 ( 0 , L_37 ,
V_137 , V_143 [ V_137 ] ) ;
}
F_7 ( 0 , L_38 ,
V_23 -> V_14 -> V_80 ,
V_104 ,
V_128 ,
V_107 ,
V_137 + 7 ,
! V_141 ? L_39 : L_40 ) ;
if ( V_141 )
V_139 = ( ( V_128 >> 6 ) ^ ( V_128 >> 16 ) ) & 7 ;
else
V_139 = ( V_128 >> 6 ) & 7 ;
switch ( V_137 ) {
case 1 :
V_139 = 0 ;
break;
case 2 :
V_139 = V_139 & 1 ;
break;
case 4 :
V_139 = V_139 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_133 , L_41 ) ;
return - V_11 ;
}
* V_129 = V_143 [ V_139 ] ;
F_7 ( 0 , L_42 ,
V_139 , V_137 , * V_129 ) ;
} else if ( V_23 -> V_31 . type == V_10 || V_23 -> V_31 . type == V_61 ) {
int V_151 , V_152 = F_70 ( V_119 ) ;
if ( V_152 ) {
V_151 = F_4 ( V_128 , 7 , 8 ) << 1 ;
V_151 |= F_4 ( V_128 , 9 , 9 ) ;
} else
V_151 = F_4 ( V_128 , 7 , 9 ) ;
if ( V_141 ) {
V_139 = F_4 ( V_128 , 16 , 18 ) ;
V_139 ^= V_151 ;
} else
V_139 = V_151 ;
V_50 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_139 ) ;
* V_129 = F_35 ( V_50 ) ;
V_147 = F_36 ( V_50 ) ;
if ( V_152 ) {
F_21 ( V_23 -> V_122 ,
V_153 , & V_1 ) ;
V_142 = F_4 ( V_1 , 22 , 22 ) ;
}
F_7 ( 0 , L_43 ,
V_139 , * V_129 , V_147 , V_142 ) ;
} else {
V_139 = ( V_128 >> 6 ) & 7 ;
V_50 = F_3 ( V_23 -> V_31 . V_2 , V_1 , V_139 ) ;
* V_129 = F_35 ( V_50 ) ;
V_147 = F_36 ( V_50 ) ;
F_7 ( 0 , L_44 ,
V_139 , * V_129 , V_147 ) ;
}
V_134 = F_68 ( * V_129 ) ;
if ( ! V_134 ) {
sprintf ( V_133 , L_45 ,
* V_129 ) ;
return - V_11 ;
}
V_66 = V_134 ;
V_23 = V_66 -> V_67 ;
V_108 = 0 ;
if ( V_23 -> V_31 . type == V_59 )
V_135 = V_23 -> V_122 ;
else {
if ( V_147 )
V_135 = V_23 -> V_154 ;
else
V_135 = V_23 -> V_122 ;
}
for ( V_105 = 0 ; V_105 < V_121 ; V_105 ++ ) {
F_21 ( V_135 , V_123 [ V_105 ] , & V_1 ) ;
V_107 = F_56 ( V_1 ) ;
if ( V_107 <= V_108 ) {
sprintf ( V_133 , L_46 ) ;
return - V_11 ;
}
if ( V_128 <= V_107 )
break;
V_108 = V_107 ;
}
if ( V_105 == V_121 ) {
sprintf ( V_133 , L_46 ) ;
return - V_11 ;
}
V_145 = F_58 ( V_1 ) + 1 ;
V_146 = F_57 ( V_1 ) + 1 ;
if ( V_145 == 3 )
V_139 = V_128 >> 6 ;
else
V_139 = ( V_128 >> ( 6 + V_146 + V_142 ) ) & 0x3 ;
V_139 = V_139 % V_145 ;
switch ( V_139 ) {
case 0 :
V_140 = F_59 ( V_1 ) ;
break;
case 1 :
V_140 = F_60 ( V_1 ) ;
break;
case 2 :
V_140 = F_61 ( V_1 ) ;
break;
case 3 :
V_140 = F_62 ( V_1 ) ;
break;
default:
sprintf ( V_133 , L_47 ) ;
return - V_11 ;
}
* V_130 = 1 << V_140 ;
F_21 ( V_23 -> V_93 [ V_140 ] ,
V_124 [ V_105 ] ,
& V_148 ) ;
if ( V_23 -> V_83 ) {
* V_130 |= 1 << ( ( V_140 + 2 ) % 4 ) ;
switch( V_145 ) {
case 2 :
case 4 :
V_138 = 1 << V_146 * ( V_145 >> 1 ) ;
break;
default:
sprintf ( V_133 , L_48 ) ;
return - V_11 ;
}
} else
V_138 = ( 1 << V_146 ) * V_145 ;
if ( V_23 -> V_85 )
* V_130 |= 1 << ( ( V_140 + 1 ) % 4 ) ;
V_150 = F_63 ( V_148 ) ;
F_7 ( 0 , L_49 ,
V_105 ,
V_128 ,
V_107 ,
( T_1 ) F_57 ( V_1 ) ,
V_145 ,
V_150 ,
V_139 ,
V_140 ,
* V_130 ) ;
if ( V_150 > V_128 ) {
sprintf ( V_133 , L_50 ,
V_150 , V_128 ) ;
return - V_11 ;
}
V_128 -= V_150 ;
V_149 = V_128 & 0x7f ;
V_128 >>= 6 ;
V_128 = F_71 ( V_128 , V_138 ) ;
#if 0
addr = addr / ch_way;
#endif
V_149 |= V_128 << 6 ;
for ( V_136 = 0 ; V_136 < V_125 ; V_136 ++ ) {
F_21 ( V_23 -> V_93 [ V_140 ] ,
V_126 [ V_136 ] ,
& V_1 ) ;
if ( ! F_64 ( V_1 ) )
continue;
V_107 = V_23 -> V_31 . F_27 ( V_1 ) ;
V_110 = F_52 ( V_107 >> 20 , 1024 , & V_111 ) ;
F_7 ( 0 , L_51 ,
V_136 ,
V_110 , ( V_111 * 1000 ) / 1024 ,
V_107 ,
1 << F_65 ( V_1 ) ) ;
if ( V_149 <= V_107 )
break;
}
if ( V_136 == V_125 ) {
sprintf ( V_133 , L_52 ,
V_149 ) ;
return - V_11 ;
}
V_112 = F_65 ( V_1 ) ;
if ( V_23 -> V_87 )
V_139 = ( V_149 >> 6 ) ;
else
V_139 = ( V_149 >> 13 ) ;
V_139 %= 1 << V_112 ;
F_21 ( V_23 -> V_93 [ V_140 ] ,
V_127 [ V_136 ] [ V_139 ] ,
& V_1 ) ;
* V_131 = F_67 ( V_1 ) ;
F_7 ( 0 , L_53 ,
V_136 ,
V_149 ,
V_107 ,
V_112 ,
V_139 ) ;
return 0 ;
}
static void F_72 ( struct V_14 * V_14 )
{
int V_70 ;
F_7 ( 0 , L_54 ) ;
for ( V_70 = 0 ; V_70 < V_14 -> V_19 ; V_70 ++ ) {
struct V_51 * V_18 = V_14 -> V_18 [ V_70 ] ;
if ( ! V_18 )
continue;
F_7 ( 0 , L_55 ,
V_18 -> V_15 -> V_54 ,
F_73 ( V_18 -> V_155 ) , F_74 ( V_18 -> V_155 ) ) ;
F_75 ( V_18 ) ;
}
}
static void F_76 ( void )
{
struct V_14 * V_14 , * V_156 ;
F_77 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_72 ( V_14 ) ;
F_18 ( V_14 ) ;
}
}
static int F_78 ( struct V_51 * * V_157 ,
T_2 * V_158 ,
const struct V_16 * V_3 ,
const unsigned V_159 )
{
struct V_14 * V_14 ;
const struct V_160 * V_161 = & V_3 -> V_162 [ V_159 ] ;
struct V_51 * V_18 = NULL ;
T_2 V_15 = 0 ;
F_40 ( V_163 ,
L_56 ,
V_53 , V_161 -> V_164 ) ;
V_18 = F_38 ( V_53 ,
V_161 -> V_164 , * V_157 ) ;
if ( ! V_18 ) {
if ( * V_157 ) {
* V_157 = V_18 ;
return 0 ;
}
if ( V_161 -> V_165 )
return 0 ;
if ( V_159 == 0 )
return - V_63 ;
F_40 ( V_166 ,
L_57 ,
V_53 , V_161 -> V_164 ) ;
return - V_63 ;
}
V_15 = V_18 -> V_15 -> V_54 ;
V_14 = F_12 ( V_15 ) ;
if ( ! V_14 ) {
V_14 = F_14 ( V_15 , V_3 ) ;
if ( ! V_14 ) {
F_75 ( V_18 ) ;
return - V_167 ;
}
( * V_158 ) ++ ;
}
if ( V_14 -> V_18 [ V_159 ] ) {
F_40 ( V_64 ,
L_58 ,
V_53 , V_161 -> V_164 ) ;
F_75 ( V_18 ) ;
return - V_63 ;
}
V_14 -> V_18 [ V_159 ] = V_18 ;
if ( F_79 ( F_80 ( V_18 ) < 0 ) ) {
F_40 ( V_64 ,
L_59 ,
V_53 , V_161 -> V_164 ) ;
return - V_63 ;
}
F_7 ( 0 , L_60 ,
V_53 , V_161 -> V_164 ) ;
F_81 ( V_18 ) ;
* V_157 = V_18 ;
return 0 ;
}
static int F_82 ( T_2 * V_158 ,
const struct V_16 * V_3 )
{
int V_70 , V_47 ;
struct V_51 * V_18 = NULL ;
while ( V_3 && V_3 -> V_162 ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_19 ; V_70 ++ ) {
V_18 = NULL ;
do {
V_47 = F_78 ( & V_18 , V_158 ,
V_3 , V_70 ) ;
if ( V_47 < 0 ) {
if ( V_70 == 0 ) {
V_70 = V_3 -> V_19 ;
break;
}
F_76 () ;
return - V_63 ;
}
} while ( V_18 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_83 ( struct V_65 * V_66 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_51 * V_18 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_14 -> V_19 ; V_70 ++ ) {
V_18 = V_14 -> V_18 [ V_70 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_168 ) {
case V_169 :
V_23 -> V_118 = V_18 ;
break;
case V_170 :
V_23 -> V_24 = V_18 ;
break;
case V_171 :
V_23 -> V_43 = V_18 ;
break;
case V_172 :
V_23 -> V_122 = V_18 ;
break;
case V_60 :
V_23 -> V_39 = V_18 ;
break;
case V_173 :
V_23 -> V_81 = V_18 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
{
int V_52 = V_18 -> V_168 - V_174 ;
V_23 -> V_93 [ V_52 ] = V_18 ;
}
break;
case V_178 :
V_23 -> V_30 = V_18 ;
break;
default:
goto error;
}
F_7 ( 0 , L_61 ,
V_18 -> V_179 , V_18 -> V_168 ,
V_14 -> V_15 ,
V_18 ) ;
}
if ( ! V_23 -> V_118 || ! V_23 -> V_24 || ! V_23 -> V_122 ||
! V_23 -> V_93 || ! V_23 -> V_81 || ! V_23 -> V_39 )
goto V_180;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_23 -> V_93 [ V_70 ] )
goto V_180;
}
return 0 ;
V_180:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
error:
F_40 ( V_64 , L_63 ,
V_53 , V_18 -> V_168 ) ;
return - V_11 ;
}
static int F_84 ( struct V_65 * V_66 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_51 * V_18 , * V_156 ;
int V_70 ;
bool V_181 = false ;
V_156 = F_38 ( V_53 ,
V_182 , NULL ) ;
if ( V_156 ) {
V_181 = true ;
F_75 ( V_156 ) ;
}
for ( V_70 = 0 ; V_70 < V_14 -> V_19 ; V_70 ++ ) {
V_18 = V_14 -> V_18 [ V_70 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_168 ) {
case V_183 :
V_23 -> V_122 = V_18 ;
break;
case V_57 :
V_23 -> V_39 = V_18 ;
case V_184 :
V_23 -> V_81 = V_18 ;
break;
case V_185 :
case V_186 :
if ( V_181 )
break;
case V_187 :
case V_188 :
{
int V_52 = V_18 -> V_168 - V_187 ;
V_23 -> V_93 [ V_52 ] = V_18 ;
}
break;
case V_189 :
V_23 -> V_30 = V_18 ;
break;
case V_190 :
if ( ! V_181 )
V_23 -> V_30 = V_18 ;
break;
case V_191 :
V_23 -> V_118 = V_18 ;
break;
case V_192 :
V_23 -> V_43 = V_18 ;
break;
case V_193 :
V_23 -> V_27 = V_18 ;
break;
case V_182 :
V_23 -> V_154 = V_18 ;
break;
case V_194 :
case V_195 :
{
int V_52 = V_18 -> V_168 - V_194 + 2 ;
F_85 ( ! V_181 ) ;
V_23 -> V_93 [ V_52 ] = V_18 ;
}
break;
default:
goto error;
}
F_7 ( 0 , L_64 ,
V_14 -> V_15 ,
F_73 ( V_18 -> V_155 ) , F_74 ( V_18 -> V_155 ) ,
V_18 ) ;
}
if ( ! V_23 -> V_118 || ! V_23 -> V_122 || ! V_23 -> V_43 ||
! V_23 -> V_27 || ! V_23 -> V_93 || ! V_23 -> V_81 ||
! V_23 -> V_39 )
goto V_180;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_23 -> V_93 [ V_70 ] )
goto V_180;
}
return 0 ;
V_180:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
error:
F_40 ( V_64 ,
L_63 , V_53 ,
V_18 -> V_168 ) ;
return - V_11 ;
}
static int F_86 ( struct V_65 * V_66 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_51 * V_18 , * V_156 ;
int V_70 ;
bool V_181 = false ;
V_156 = F_38 ( V_53 ,
V_196 , NULL ) ;
if ( V_156 ) {
V_181 = true ;
F_75 ( V_156 ) ;
}
if ( V_23 -> V_31 . V_45 == NULL )
V_23 -> V_31 . V_45 = F_38 ( V_53 ,
V_197 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_14 -> V_19 ; V_70 ++ ) {
V_18 = V_14 -> V_18 [ V_70 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_168 ) {
case V_198 :
V_23 -> V_118 = V_18 ;
break;
case V_199 :
V_23 -> V_24 = V_18 ;
break;
case V_200 :
V_23 -> V_122 = V_18 ;
break;
case V_58 :
V_23 -> V_39 = V_18 ;
break;
case V_201 :
V_23 -> V_81 = V_18 ;
break;
case V_202 :
V_23 -> V_93 [ 0 ] = V_18 ;
break;
case V_203 :
V_23 -> V_93 [ 1 ] = V_18 ;
break;
case V_204 :
if ( ! V_181 )
V_23 -> V_93 [ 2 ] = V_18 ;
break;
case V_205 :
if ( ! V_181 )
V_23 -> V_93 [ 3 ] = V_18 ;
break;
case V_206 :
V_23 -> V_30 = V_18 ;
break;
case V_196 :
V_23 -> V_154 = V_18 ;
break;
case V_207 :
V_23 -> V_208 = V_18 ;
break;
case V_209 :
if ( V_181 )
V_23 -> V_93 [ 2 ] = V_18 ;
break;
case V_210 :
if ( V_181 )
V_23 -> V_93 [ 3 ] = V_18 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_14 -> V_15 ,
F_73 ( V_18 -> V_155 ) , F_74 ( V_18 -> V_155 ) ,
V_18 ) ;
}
if ( ! V_23 -> V_118 || ! V_23 -> V_122 || ! V_23 -> V_24 ||
! V_23 -> V_81 || ! V_23 -> V_39 || ! V_23 -> V_31 . V_45 )
goto V_180;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_23 -> V_93 [ V_70 ] )
goto V_180;
}
return 0 ;
V_180:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
}
static int F_87 ( struct V_65 * V_66 ,
struct V_14 * V_14 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
struct V_51 * V_18 ;
int V_70 ;
if ( V_23 -> V_31 . V_45 == NULL )
V_23 -> V_31 . V_45 = F_38 ( V_53 ,
V_211 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_14 -> V_19 ; V_70 ++ ) {
V_18 = V_14 -> V_18 [ V_70 ] ;
if ( ! V_18 )
continue;
switch ( V_18 -> V_168 ) {
case V_212 :
V_23 -> V_118 = V_18 ;
break;
case V_213 :
V_23 -> V_24 = V_18 ;
break;
case V_214 :
V_23 -> V_122 = V_18 ;
break;
case V_62 :
V_23 -> V_39 = V_18 ;
break;
case V_215 :
V_23 -> V_81 = V_18 ;
break;
case V_216 :
V_23 -> V_93 [ 0 ] = V_18 ;
break;
case V_217 :
V_23 -> V_93 [ 1 ] = V_18 ;
break;
case V_218 :
V_23 -> V_93 [ 2 ] = V_18 ;
break;
case V_219 :
V_23 -> V_93 [ 3 ] = V_18 ;
break;
case V_220 :
V_23 -> V_30 = V_18 ;
break;
default:
break;
}
F_7 ( 0 , L_64 ,
V_14 -> V_15 ,
F_73 ( V_18 -> V_155 ) , F_74 ( V_18 -> V_155 ) ,
V_18 ) ;
}
if ( ! V_23 -> V_118 || ! V_23 -> V_122 || ! V_23 -> V_24 ||
! V_23 -> V_81 || ! V_23 -> V_39 || ! V_23 -> V_31 . V_45 )
goto V_180;
for ( V_70 = 0 ; V_70 < V_88 ; V_70 ++ ) {
if ( ! V_23 -> V_93 [ V_70 ] )
goto V_180;
}
return 0 ;
V_180:
F_40 ( V_64 , L_62 ) ;
return - V_63 ;
}
static void F_88 ( struct V_65 * V_66 ,
const struct V_221 * V_222 )
{
struct V_65 * V_134 ;
struct V_22 * V_23 = V_66 -> V_67 ;
enum V_223 V_224 ;
char * type , * V_225 , V_133 [ 256 ] ;
bool V_226 = F_4 ( V_222 -> V_227 , 0 , 0 ) ;
bool V_228 = F_4 ( V_222 -> V_229 , 62 , 62 ) ;
bool V_230 = F_4 ( V_222 -> V_229 , 61 , 61 ) ;
bool V_231 ;
T_1 V_232 = F_4 ( V_222 -> V_229 , 38 , 52 ) ;
T_1 V_233 = F_4 ( V_222 -> V_229 , 16 , 31 ) ;
T_1 V_234 = F_4 ( V_222 -> V_229 , 0 , 15 ) ;
T_1 V_94 = F_4 ( V_222 -> V_229 , 0 , 3 ) ;
T_1 V_235 = F_4 ( V_222 -> V_229 , 4 , 6 ) ;
long V_130 , V_236 ;
T_2 V_131 , V_129 ;
int V_47 , V_69 ;
char * V_132 = NULL ;
if ( V_23 -> V_31 . type == V_56 )
V_231 = true ;
else
V_231 = F_4 ( V_222 -> V_229 , 56 , 56 ) ;
if ( V_230 ) {
if ( V_226 ) {
type = L_65 ;
V_224 = V_237 ;
} else {
type = L_66 ;
V_224 = V_238 ;
}
} else {
type = L_67 ;
V_224 = V_239 ;
}
if ( ! ( ( V_234 & 0xef80 ) == 0x80 ) ) {
V_225 = L_68 ;
} else {
switch ( V_235 ) {
case 0 :
V_225 = L_69 ;
break;
case 1 :
V_225 = L_70 ;
break;
case 2 :
V_225 = L_71 ;
break;
case 3 :
V_225 = L_72 ;
break;
case 4 :
V_225 = L_73 ;
break;
default:
V_225 = L_74 ;
break;
}
}
if ( ! F_4 ( V_222 -> V_229 , 58 , 58 ) )
return;
V_47 = F_69 ( V_66 , V_222 -> V_128 , & V_129 ,
& V_130 , & V_131 , & V_132 , V_133 ) ;
if ( V_47 < 0 )
goto V_240;
V_134 = F_68 ( V_129 ) ;
if ( ! V_134 ) {
strcpy ( V_133 , L_75 ) ;
goto V_240;
}
V_66 = V_134 ;
V_23 = V_66 -> V_67 ;
V_236 = F_89 ( & V_130 , V_88 ) ;
if ( V_131 < 4 )
V_69 = 0 ;
else if ( V_131 < 8 )
V_69 = 1 ;
else
V_69 = 2 ;
if ( ! V_23 -> V_85 && ! V_23 -> V_83 && ! V_23 -> V_87 )
V_94 = V_236 ;
snprintf ( V_133 , sizeof( V_133 ) ,
L_76 ,
V_228 ? L_77 : L_39 ,
( V_230 && V_231 ) ? L_78 : L_39 ,
V_132 ,
V_233 , V_234 ,
V_129 ,
V_130 ,
V_131 ) ;
F_7 ( 0 , L_79 , V_133 ) ;
if ( V_94 == V_241 )
V_94 = - 1 ;
F_90 ( V_224 , V_66 , V_232 ,
V_222 -> V_128 >> V_242 , V_222 -> V_128 & ~ V_243 , 0 ,
V_94 , V_69 , - 1 ,
V_225 , V_133 ) ;
return;
V_240:
F_90 ( V_224 , V_66 , V_232 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_133 , L_39 ) ;
}
static void F_91 ( struct V_65 * V_66 )
{
struct V_22 * V_23 = V_66 -> V_67 ;
int V_70 ;
unsigned V_244 = 0 ;
struct V_221 * V_222 ;
F_92 () ;
V_244 = ( V_23 -> V_245 + V_246 - V_23 -> V_247 )
% V_246 ;
if ( ! V_244 )
return;
V_222 = V_23 -> V_248 ;
if ( V_23 -> V_247 + V_244 > V_246 ) {
unsigned V_249 = V_246 - V_23 -> V_247 ;
memcpy ( V_222 , & V_23 -> V_250 [ V_23 -> V_247 ] , sizeof( * V_222 ) * V_249 ) ;
F_93 () ;
V_23 -> V_247 = 0 ;
V_244 -= V_249 ;
V_222 += V_249 ;
}
memcpy ( V_222 , & V_23 -> V_250 [ V_23 -> V_247 ] , sizeof( * V_222 ) * V_244 ) ;
F_93 () ;
V_23 -> V_247 += V_244 ;
F_92 () ;
if ( V_23 -> V_251 ) {
F_40 ( V_64 , L_80 ,
V_23 -> V_251 ) ;
F_93 () ;
V_23 -> V_251 = 0 ;
}
for ( V_70 = 0 ; V_70 < V_244 ; V_70 ++ )
F_88 ( V_66 , & V_23 -> V_248 [ V_70 ] ) ;
}
static int F_94 ( struct V_252 * V_253 , unsigned long V_254 ,
void * V_255 )
{
struct V_221 * V_221 = (struct V_221 * ) V_255 ;
struct V_65 * V_66 ;
struct V_22 * V_23 ;
char * type ;
if ( F_95 () == V_256 )
return V_257 ;
V_66 = F_68 ( V_221 -> V_258 ) ;
if ( ! V_66 )
return V_259 ;
V_23 = V_66 -> V_67 ;
if ( ( V_221 -> V_229 & 0xefff ) >> 7 != 1 )
return V_257 ;
if ( V_221 -> V_227 & V_260 )
type = L_81 ;
else
type = L_82 ;
F_96 ( V_66 , V_163 , L_83 ) ;
F_96 ( V_66 , V_163 , L_84
L_85 , V_221 -> V_261 , type ,
V_221 -> V_227 , V_221 -> V_262 , V_221 -> V_229 ) ;
F_96 ( V_66 , V_163 , L_86 , V_221 -> V_263 ) ;
F_96 ( V_66 , V_163 , L_87 , V_221 -> V_128 ) ;
F_96 ( V_66 , V_163 , L_88 , V_221 -> V_264 ) ;
F_96 ( V_66 , V_163 , L_89
L_90 , V_221 -> V_265 , V_221 -> V_266 ,
V_221 -> time , V_221 -> V_258 , V_221 -> V_267 ) ;
F_92 () ;
if ( ( V_23 -> V_245 + 1 ) % V_246 == V_23 -> V_247 ) {
F_93 () ;
V_23 -> V_251 ++ ;
return V_257 ;
}
memcpy ( & V_23 -> V_250 [ V_23 -> V_245 ] , V_221 , sizeof( * V_221 ) ) ;
F_93 () ;
V_23 -> V_245 = ( V_23 -> V_245 + 1 ) % V_246 ;
if ( V_221 -> V_227 & 1 )
F_91 ( V_66 ) ;
return V_268 ;
}
static void F_97 ( struct V_14 * V_14 )
{
struct V_65 * V_66 = V_14 -> V_66 ;
struct V_22 * V_23 ;
if ( F_79 ( ! V_66 || ! V_66 -> V_67 ) ) {
F_7 ( 0 , L_91 , & V_14 -> V_18 [ 0 ] -> V_269 ) ;
F_40 ( V_64 , L_92 ) ;
return;
}
V_23 = V_66 -> V_67 ;
F_7 ( 0 , L_93 ,
V_66 , & V_14 -> V_18 [ 0 ] -> V_269 ) ;
F_98 ( V_66 -> V_18 ) ;
F_7 ( 1 , L_94 , V_66 -> V_270 ) ;
F_16 ( V_66 -> V_270 ) ;
F_99 ( V_66 ) ;
V_14 -> V_66 = NULL ;
}
static int F_100 ( struct V_14 * V_14 , enum type type )
{
struct V_65 * V_66 ;
struct V_271 V_90 [ 2 ] ;
struct V_22 * V_23 ;
struct V_51 * V_18 = V_14 -> V_18 [ 0 ] ;
int V_47 ;
V_47 = F_39 ( V_14 -> V_15 , type ) ;
if ( F_79 ( V_47 < 0 ) )
return V_47 ;
V_90 [ 0 ] . type = V_272 ;
V_90 [ 0 ] . V_74 = V_88 ;
V_90 [ 0 ] . V_273 = false ;
V_90 [ 1 ] . type = V_274 ;
V_90 [ 1 ] . V_74 = V_275 ;
V_90 [ 1 ] . V_273 = true ;
V_66 = F_101 ( V_14 -> V_80 , F_47 ( V_90 ) , V_90 ,
sizeof( * V_23 ) ) ;
if ( F_79 ( ! V_66 ) )
return - V_167 ;
F_7 ( 0 , L_93 ,
V_66 , & V_18 -> V_269 ) ;
V_23 = V_66 -> V_67 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_14 = V_14 ;
V_14 -> V_66 = V_66 ;
V_66 -> V_276 = V_277 ;
V_66 -> V_278 = V_279 ;
V_66 -> V_280 = V_279 ;
V_66 -> V_281 = L_95 ;
V_66 -> V_282 = V_283 ;
V_66 -> V_284 = F_102 ( V_18 ) ;
V_66 -> V_285 = NULL ;
V_66 -> V_286 = F_91 ;
V_23 -> V_31 . type = type ;
switch ( type ) {
case V_56 :
V_23 -> V_31 . V_32 = V_287 ;
V_23 -> V_31 . V_114 = F_25 ;
V_23 -> V_31 . V_116 = F_26 ;
V_23 -> V_31 . V_119 = V_288 ;
V_23 -> V_31 . F_28 = F_28 ;
V_23 -> V_31 . F_30 = F_30 ;
V_23 -> V_31 . F_27 = F_27 ;
V_23 -> V_31 . V_117 = F_47 ( V_288 ) ;
V_23 -> V_31 . V_120 = V_289 ;
V_23 -> V_31 . V_144 = F_47 ( V_289 ) ;
V_23 -> V_31 . V_2 = V_290 ;
V_66 -> V_270 = F_103 ( V_17 , L_96 , V_66 -> V_291 ) ;
V_47 = F_84 ( V_66 , V_14 ) ;
if ( F_79 ( V_47 < 0 ) )
goto V_292;
break;
case V_59 :
V_23 -> V_31 . V_32 = V_293 ;
V_23 -> V_31 . V_114 = F_20 ;
V_23 -> V_31 . V_116 = F_23 ;
V_23 -> V_31 . V_119 = V_294 ;
V_23 -> V_31 . F_28 = F_28 ;
V_23 -> V_31 . F_30 = F_30 ;
V_23 -> V_31 . F_27 = F_27 ;
V_23 -> V_31 . V_117 = F_47 ( V_294 ) ;
V_23 -> V_31 . V_120 = V_295 ;
V_23 -> V_31 . V_144 = F_47 ( V_295 ) ;
V_23 -> V_31 . V_2 = V_296 ;
V_66 -> V_270 = F_103 ( V_17 , L_97 , V_66 -> V_291 ) ;
V_47 = F_83 ( V_66 , V_14 ) ;
if ( F_79 ( V_47 < 0 ) )
goto V_292;
break;
case V_10 :
V_23 -> V_31 . V_114 = F_32 ;
V_23 -> V_31 . V_116 = F_33 ;
V_23 -> V_31 . V_119 = V_288 ;
V_23 -> V_31 . F_28 = F_29 ;
V_23 -> V_31 . F_30 = F_31 ;
V_23 -> V_31 . F_27 = F_34 ;
V_23 -> V_31 . V_117 = F_47 ( V_288 ) ;
V_23 -> V_31 . V_120 = V_289 ;
V_23 -> V_31 . V_144 = F_47 ( V_289 ) ;
V_23 -> V_31 . V_2 = V_290 ;
V_66 -> V_270 = F_103 ( V_17 , L_98 , V_66 -> V_291 ) ;
V_47 = F_86 ( V_66 , V_14 ) ;
if ( F_79 ( V_47 < 0 ) )
goto V_292;
break;
case V_61 :
V_23 -> V_31 . V_114 = F_32 ;
V_23 -> V_31 . V_116 = F_33 ;
V_23 -> V_31 . V_119 = V_288 ;
V_23 -> V_31 . F_28 = F_29 ;
V_23 -> V_31 . F_30 = F_31 ;
V_23 -> V_31 . F_27 = F_34 ;
V_23 -> V_31 . V_117 = F_47 ( V_288 ) ;
V_23 -> V_31 . V_120 = V_289 ;
V_23 -> V_31 . V_144 = F_47 ( V_289 ) ;
V_23 -> V_31 . V_2 = V_290 ;
V_66 -> V_270 = F_103 ( V_17 , L_99 , V_66 -> V_291 ) ;
V_47 = F_87 ( V_66 , V_14 ) ;
if ( F_79 ( V_47 < 0 ) )
goto V_292;
break;
}
F_42 ( V_66 ) ;
F_51 ( V_66 ) ;
V_66 -> V_18 = & V_18 -> V_269 ;
if ( F_79 ( F_104 ( V_66 ) ) ) {
F_7 ( 0 , L_100 ) ;
V_47 = - V_11 ;
goto V_292;
}
return 0 ;
V_292:
F_16 ( V_66 -> V_270 ) ;
F_99 ( V_66 ) ;
V_14 -> V_66 = NULL ;
return V_47 ;
}
static int F_105 ( struct V_51 * V_18 , const struct V_297 * V_52 )
{
int V_47 = - V_63 ;
T_2 V_80 , V_158 = 0 ;
struct V_14 * V_14 ;
enum type type = V_59 ;
F_106 ( & V_298 ) ;
if ( F_79 ( V_299 >= 1 ) ) {
F_107 ( & V_298 ) ;
return - V_63 ;
}
V_299 ++ ;
switch ( V_18 -> V_168 ) {
case V_57 :
V_47 = F_82 ( & V_158 , V_300 ) ;
type = V_56 ;
break;
case V_172 :
V_47 = F_82 ( & V_158 , V_301 ) ;
type = V_59 ;
break;
case V_200 :
V_47 = F_82 ( & V_158 , V_302 ) ;
type = V_10 ;
break;
case V_214 :
V_47 = F_82 ( & V_158 , V_303 ) ;
type = V_61 ;
break;
}
if ( F_79 ( V_47 < 0 ) ) {
F_7 ( 0 , L_101 , V_18 -> V_168 ) ;
goto V_292;
}
V_80 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_7 ( 0 , L_102 ,
V_80 , V_80 + 1 , V_158 ) ;
V_14 -> V_80 = V_80 ++ ;
V_47 = F_100 ( V_14 , type ) ;
if ( F_79 ( V_47 < 0 ) )
goto V_304;
}
F_40 ( V_166 , L_79 , V_283 ) ;
F_107 ( & V_298 ) ;
return 0 ;
V_304:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_97 ( V_14 ) ;
F_76 () ;
V_292:
F_107 ( & V_298 ) ;
return V_47 ;
}
static void F_108 ( struct V_51 * V_18 )
{
struct V_14 * V_14 ;
F_7 ( 0 , L_54 ) ;
F_106 ( & V_298 ) ;
if ( F_79 ( ! V_299 ) ) {
F_107 ( & V_298 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_97 ( V_14 ) ;
F_76 () ;
V_299 -- ;
F_107 ( & V_298 ) ;
}
static int T_4 F_109 ( void )
{
int V_305 ;
F_7 ( 2 , L_54 ) ;
F_110 () ;
V_305 = F_111 ( & V_306 ) ;
if ( V_305 >= 0 ) {
F_112 ( & V_307 ) ;
if ( F_95 () == V_256 )
F_40 ( V_308 , L_103 ) ;
return 0 ;
}
F_40 ( V_64 , L_104 ,
V_305 ) ;
return V_305 ;
}
static void T_5 F_113 ( void )
{
F_7 ( 2 , L_54 ) ;
F_114 ( & V_306 ) ;
F_115 ( & V_307 ) ;
}
