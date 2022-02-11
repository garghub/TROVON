static char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
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
static inline int F_2 ( const struct V_2 * V_3 , T_1 V_4 ,
int V_5 )
{
return F_3 ( V_4 , V_3 [ V_5 ] . V_6 ,
V_3 [ V_5 ] . V_7 ) ;
}
static inline int F_4 ( enum type type , T_1 V_8 )
{
int V_9 = ( 1 << F_5 ( V_8 ) ) ;
int V_10 = 4 ;
if ( type == V_11 || type == V_12 || type == V_13 )
V_10 = 8 ;
if ( V_9 > V_10 ) {
F_6 ( 0 , L_5 ,
V_9 , V_10 , ( unsigned int ) F_5 ( V_8 ) , V_8 ) ;
return - V_14 ;
}
return V_9 ;
}
static inline int F_7 ( T_1 V_8 )
{
int V_15 = ( F_8 ( V_8 ) + 12 ) ;
if ( V_15 < 13 || V_15 > 18 ) {
F_6 ( 0 , L_6 ,
V_15 , ( unsigned int ) F_8 ( V_8 ) , V_8 ) ;
return - V_14 ;
}
return 1 << V_15 ;
}
static inline int F_9 ( T_1 V_8 )
{
int V_16 = ( F_10 ( V_8 ) + 10 ) ;
if ( V_16 > 12 ) {
F_6 ( 0 , L_7 ,
V_16 , ( unsigned int ) F_10 ( V_8 ) , V_8 ) ;
return - V_14 ;
}
return 1 << V_16 ;
}
static struct V_17 * F_11 ( T_2 V_18 , int V_19 )
{
struct V_17 * V_17 ;
if ( V_19 ) {
return F_12 ( & V_20 ,
struct V_17 , V_21 ) ;
}
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_17 -> V_18 == V_18 )
return V_17 ;
}
return NULL ;
}
static struct V_17 * F_14 ( T_2 V_18 ,
const struct V_22 * V_3 )
{
struct V_17 * V_17 ;
V_17 = F_15 ( sizeof( * V_17 ) , V_23 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_24 = F_15 ( sizeof( * V_17 -> V_24 ) * V_3 -> V_25 ,
V_23 ) ;
if ( ! V_17 -> V_24 ) {
F_16 ( V_17 ) ;
return NULL ;
}
V_17 -> V_18 = V_18 ;
V_17 -> V_25 = V_3 -> V_25 ;
F_17 ( & V_17 -> V_21 , & V_20 ) ;
return V_17 ;
}
static void F_18 ( struct V_17 * V_17 )
{
F_19 ( & V_17 -> V_21 ) ;
F_16 ( V_17 -> V_24 ) ;
F_16 ( V_17 ) ;
}
static T_3 F_20 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_29 , & V_4 ) ;
return F_22 ( V_4 ) ;
}
static T_3 F_23 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_30 , & V_4 ) ;
return F_24 ( V_4 ) ;
}
static T_3 F_25 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_31 , V_29 , & V_4 ) ;
return F_22 ( V_4 ) ;
}
static T_3 F_26 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_31 , V_30 , & V_4 ) ;
return F_24 ( V_4 ) ;
}
static T_3 F_27 ( T_1 V_4 )
{
return ( ( T_3 ) F_3 ( V_4 , 1 , 10 ) << 29 ) | 0x1fffffff ;
}
static T_3 F_28 ( T_1 V_4 )
{
return ( F_3 ( V_4 , 6 , 25 ) << 26 ) | 0x3ffffff ;
}
static T_1 F_29 ( T_1 V_4 )
{
return F_3 ( V_4 , 1 , 1 ) ;
}
static T_1 F_30 ( T_1 V_4 )
{
return F_3 ( V_4 , 2 , 3 ) ;
}
static T_3 F_31 ( T_1 V_4 )
{
return ( F_3 ( V_4 , 7 , 26 ) << 26 ) | 0x3ffffff ;
}
static T_1 F_32 ( T_1 V_4 )
{
return F_3 ( V_4 , 1 , 2 ) ;
}
static const char * F_33 ( T_1 V_4 , enum type V_32 )
{
if ( V_32 == V_13 )
return V_33 [ F_32 ( V_4 ) ] ;
else
return F_29 ( V_4 ) ? L_8 : L_9 ;
}
static T_1 F_34 ( T_1 V_4 )
{
return F_3 ( V_4 , 3 , 4 ) ;
}
static enum V_34 F_35 ( struct V_26 * V_27 )
{
T_1 V_4 ;
enum V_34 V_35 ;
if ( V_27 -> V_36 ) {
F_21 ( V_27 -> V_36 , V_27 -> V_37 . V_38 ,
& V_4 ) ;
if ( F_3 ( V_4 , 11 , 11 ) )
V_35 = V_39 ;
else
V_35 = V_40 ;
} else
V_35 = V_41 ;
return V_35 ;
}
static enum V_34 F_36 ( struct V_26 * V_27 )
{
T_1 V_4 ;
bool V_42 = false ;
enum V_34 V_35 = V_41 ;
if ( ! V_27 -> V_36 )
goto V_43;
F_21 ( V_27 -> V_36 ,
V_44 , & V_4 ) ;
if ( F_3 ( V_4 , 16 , 16 ) )
V_42 = true ;
F_21 ( V_27 -> V_45 , V_46 , & V_4 ) ;
if ( F_3 ( V_4 , 14 , 14 ) ) {
if ( V_42 )
V_35 = V_47 ;
else
V_35 = V_48 ;
} else {
if ( V_42 )
V_35 = V_39 ;
else
V_35 = V_40 ;
}
V_43:
return V_35 ;
}
static enum V_49 F_37 ( struct V_26 * V_27 , T_1 V_8 )
{
return V_50 ;
}
static enum V_49 F_38 ( struct V_26 * V_27 , T_1 V_8 )
{
return V_51 ;
}
static enum V_49 F_39 ( T_1 V_8 )
{
enum V_49 type ;
switch ( V_8 ) {
case 3 :
type = V_51 ;
break;
case 2 :
type = V_50 ;
break;
case 1 :
type = V_52 ;
break;
case 0 :
type = V_53 ;
break;
}
return type ;
}
static enum V_49 F_40 ( struct V_26 * V_27 , T_1 V_8 )
{
return F_39 ( F_3 ( V_8 , 7 , 8 ) ) ;
}
static enum V_49 F_41 ( struct V_26 * V_27 , T_1 V_8 )
{
return F_39 ( F_3 ( V_8 , 8 , 9 ) ) ;
}
static enum V_34 F_42 ( struct V_26 * V_27 )
{
return V_47 ;
}
static T_2 F_43 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_54 , V_55 , & V_4 ) ;
return F_3 ( V_4 , 0 , 2 ) ;
}
static T_2 F_44 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_55 , & V_4 ) ;
return F_3 ( V_4 , 0 , 3 ) ;
}
static T_2 F_45 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_55 , & V_4 ) ;
return F_3 ( V_4 , 0 , 2 ) ;
}
static T_3 F_46 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_37 . V_56 , V_57 , & V_4 ) ;
return ( F_3 ( V_4 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_47 ( struct V_26 * V_27 )
{
T_3 V_58 ;
T_1 V_4 ;
F_21 ( V_27 -> V_37 . V_56 , V_59 , & V_4 ) ;
V_58 = F_3 ( V_4 , 26 , 31 ) ;
F_21 ( V_27 -> V_37 . V_56 , V_60 , & V_4 ) ;
V_58 = ( ( V_4 << 6 ) | V_58 ) << 26 ;
return V_58 | 0x1ffffff ;
}
static T_3 F_48 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_61 . V_62 , V_63 , & V_4 ) ;
return ( F_3 ( V_4 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_49 ( struct V_26 * V_27 )
{
T_3 V_58 ;
T_1 V_64 , V_65 ;
F_21 ( V_27 -> V_61 . V_62 , V_66 , & V_64 ) ;
F_21 ( V_27 -> V_61 . V_62 , V_67 , & V_65 ) ;
V_58 = ( ( T_3 ) V_65 << 32 ) | V_64 ;
return V_58 | 0x3ffffff ;
}
static T_3 F_50 ( T_1 V_4 )
{
return ( ( ( T_3 ) F_3 ( V_4 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_51 ( T_2 V_68 )
{
return ( ( V_68 >> 3 ) << 2 ) | ( V_68 & 0x3 ) ;
}
static inline T_2 F_52 ( T_2 V_68 )
{
return ( V_68 >> 2 ) & 0x1 ;
}
static int F_53 ( int V_69 , T_3 V_70 )
{
int V_71 ;
for ( V_71 = 12 ; V_71 < 28 ; V_71 += 2 )
V_69 ^= ( V_70 >> V_71 ) & 3 ;
return V_69 ;
}
static struct V_72 * F_54 ( T_2 V_18 , T_1 V_73 )
{
struct V_72 * V_24 = NULL ;
do {
V_24 = F_55 ( V_74 , V_73 , V_24 ) ;
if ( V_24 && V_24 -> V_18 -> V_75 == V_18 )
break;
} while ( V_24 );
return V_24 ;
}
static int F_56 ( const T_2 V_18 , enum type type )
{
struct V_72 * V_24 = NULL ;
T_1 V_76 , V_73 ;
switch ( type ) {
case V_77 :
V_73 = V_78 ;
break;
case V_11 :
V_73 = V_79 ;
break;
case V_80 :
V_73 = V_81 ;
break;
case V_12 :
V_73 = V_82 ;
break;
case V_13 :
V_73 = V_83 ;
break;
default:
return - V_84 ;
}
if ( type != V_13 )
V_24 = F_54 ( V_18 , V_73 ) ;
else
V_24 = F_55 ( V_74 , V_73 , 0 ) ;
if ( ! V_24 ) {
F_57 ( V_85 , L_10
L_11 ,
V_74 , V_73 , V_18 ) ;
return - V_84 ;
}
F_21 ( V_24 ,
type == V_13 ? V_86 : V_46 , & V_76 ) ;
if ( ! F_58 ( V_76 ) ) {
F_57 ( V_85 , L_12 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_59 ( const struct V_26 * V_27 ,
const int V_87 ,
const int V_88 ,
T_3 * V_89 ,
T_3 * V_90 ,
int * V_91 )
{
T_1 V_92 , V_93 , V_65 ;
struct V_72 * V_94 ;
int V_95 ;
switch ( V_88 ) {
case 0 :
V_94 = V_27 -> V_61 . V_96 ;
break;
case 1 :
V_94 = V_27 -> V_61 . V_97 ;
break;
default:
F_60 ( 1 ) ;
return - V_14 ;
}
F_21 ( V_94 ,
V_98 [ V_87 ] , & V_92 ) ;
F_21 ( V_94 ,
V_99 [ V_87 ] , & V_93 ) ;
F_21 ( V_94 ,
V_100 [ V_87 ] , & V_65 ) ;
if ( ! F_3 ( V_92 , 0 , 0 ) )
return - V_84 ;
V_95 = F_3 ( V_92 , 3 , 5 ) ;
if ( V_95 < F_61 ( V_101 ) ) {
* V_91 = V_101 [ V_95 ] ;
} else {
* V_91 = 0 ;
F_57 ( V_85 ,
L_13 ,
V_95 ) ;
return - V_84 ;
}
* V_89 = ( ( T_3 ) F_3 ( V_93 , 6 , 31 ) << 6 ) |
( ( T_3 ) F_3 ( V_65 , 0 , 15 ) << 32 ) ;
* V_90 = ( ( T_3 ) F_3 ( V_92 , 6 , 31 ) << 6 ) | 63 |
( ( T_3 ) F_3 ( V_65 , 16 , 31 ) << 32 ) ;
return 0 ;
}
static int F_62 ( int V_102 )
{
F_60 ( V_102 < 0 || V_102 >= 6 ) ;
return V_102 < 3 ? 1 : 0 ;
}
static T_1 F_63 ( int V_87 , T_1 V_4 )
{
F_60 ( V_87 >= V_103 ) ;
return F_3 ( V_4 , V_87 * 3 , ( V_87 * 3 ) + 2 ) ;
}
static T_1 F_64 ( int V_87 , T_1 V_4 )
{
int V_88 , V_104 ;
F_60 ( V_87 >= V_105 ) ;
V_88 = F_3 ( V_4 , V_87 * 3 , ( V_87 * 3 ) + 2 ) ;
V_104 = F_3 ( V_4 , ( V_87 * 2 ) + 18 , ( V_87 * 2 ) + 18 + 1 ) ;
return F_65 ( V_88 , V_104 ) ;
}
static void F_66 ( T_1 V_4 , char * V_106 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_103 ; V_71 ++ ) {
V_106 [ V_71 * 2 ] = F_63 ( V_71 , V_4 ) + '0' ;
V_106 [ V_71 * 2 + 1 ] = '-' ;
}
V_106 [ V_103 * 2 - 1 ] = '\0' ;
}
static void F_67 ( T_1 V_4 , char * V_106 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_105 ; V_71 ++ ) {
V_106 [ V_71 * 2 ] = F_64 ( V_71 , V_4 ) + '0' ;
V_106 [ V_71 * 2 + 1 ] = '-' ;
}
V_106 [ V_105 * 2 - 1 ] = '\0' ;
}
static int F_68 ( struct V_26 * V_27 , T_3 * V_107 )
{
T_3 V_108 , V_109 , F_28 = 0 ;
T_3 V_110 , V_111 , V_112 , V_113 , V_114 ;
int V_115 = 0 ;
int V_116 = 0 ;
int V_117 , V_118 ;
T_1 V_119 , V_68 ;
int V_71 ;
T_3 V_120 [ 2 ] ;
T_1 V_121 , V_122 ;
T_1 V_123 [ V_124 ] ;
T_1 V_125 [ V_124 ] ;
int V_126 ;
char V_127 [ V_103 * 2 ] ;
char V_128 [ V_105 * 2 ] ;
int V_129 ;
int V_88 ;
int V_102 ;
int V_130 ;
int V_131 [ V_105 ] ;
int V_132 = 0 ;
for ( V_71 = 0 ; V_71 < V_105 ; V_71 ++ )
V_107 [ V_71 ] = 0 ;
V_129 = 0 ;
for ( V_71 = 0 ; V_71 < V_124 ; V_71 ++ ) {
F_21 ( V_27 -> V_61 . V_133 [ V_71 ] ,
V_134 , & V_125 [ V_71 ] ) ;
if ( V_71 > 0 && V_125 [ V_71 ] != V_125 [ V_71 - 1 ] ) {
F_66 ( V_125 [ V_71 - 1 ] ,
V_127 ) ;
if ( V_129 == V_71 - 1 )
F_6 ( 0 , L_14 ,
V_129 , V_127 ) ;
else
F_6 ( 0 , L_15 ,
V_129 , V_71 - 1 , V_127 ) ;
V_129 = V_71 ;
}
}
F_66 ( V_125 [ V_71 - 1 ] , V_127 ) ;
if ( V_129 == V_71 - 1 )
F_6 ( 0 , L_14 ,
V_129 , V_127 ) ;
else
F_6 ( 0 , L_15 ,
V_129 , V_71 - 1 , V_127 ) ;
V_129 = 0 ;
for ( V_71 = 0 ; V_71 < V_124 ; V_71 ++ ) {
F_21 ( V_27 -> V_61 . V_133 [ V_71 ] ,
V_135 , & V_123 [ V_71 ] ) ;
if ( V_71 > 0 && V_123 [ V_71 ] != V_123 [ V_71 - 1 ] ) {
F_67 ( V_123 [ V_71 - 1 ] , V_128 ) ;
if ( V_129 == V_71 - 1 )
F_6 ( 0 , L_16 ,
V_129 , V_128 ) ;
else
F_6 ( 0 , L_17 ,
V_129 , V_71 - 1 , V_128 ) ;
V_129 = V_71 ;
}
}
F_67 ( V_123 [ V_71 - 1 ] , V_128 ) ;
if ( V_129 == V_71 - 1 )
F_6 ( 0 , L_16 ,
V_129 , V_128 ) ;
else
F_6 ( 0 , L_17 ,
V_129 , V_71 - 1 , V_128 ) ;
for ( V_115 = 0 ; V_115 < V_27 -> V_37 . V_136 ; V_115 ++ ) {
V_108 = F_28 ;
F_21 ( V_27 -> V_137 ,
V_27 -> V_37 . V_121 [ V_115 ] , & V_121 ) ;
if ( ! F_69 ( V_121 ) )
break;
V_126 = F_70 ( V_121 ) ;
F_28 = V_27 -> V_37 . F_28 ( V_121 ) + 1 ;
V_109 = F_28 - V_108 ;
F_21 ( V_27 -> V_137 ,
V_27 -> V_37 . V_138 [ V_115 ] , & V_122 ) ;
V_119 = F_2 ( V_27 -> V_37 . V_2 ,
V_122 , 0 ) ;
for ( V_117 = 1 ; V_117 < 8 ; V_117 ++ ) {
V_68 = F_2 ( V_27 -> V_37 . V_2 ,
V_122 , V_117 ) ;
if ( ( V_68 & 0x8 ) == 0 ) {
F_6 ( 0 , L_18 ,
V_68 ) ;
return - 1 ;
}
if ( V_68 == V_119 )
break;
}
if ( F_71 ( V_121 ) )
V_117 *= 3 ;
F_6 ( 3 , L_19 ,
V_115 ,
V_108 ,
F_28 ,
V_117 ,
V_126 ? L_20 : L_21 ) ;
for ( V_88 = 0 ; V_88 < 2 ; V_88 ++ ) {
V_120 [ V_88 ] = 0 ;
V_114 = 0 ;
for ( V_116 = 0 ;
V_116 < F_61 (
V_98 ) ;
V_116 ++ ) {
if ( F_59 ( V_27 ,
V_116 ,
V_88 ,
& V_113 ,
& V_112 ,
& V_118 ) )
break;
V_111 = ( V_112 + 1 ) -
( V_114 + V_113 ) ;
V_114 += V_111 ;
V_110 = ( V_112 + 1 ) - V_111 ;
if ( V_110 < V_108 ) {
if ( V_112 > V_108 )
F_6 ( 0 , L_22 ) ;
} else if ( V_110 < F_28 ) {
if ( V_112 + 1 > F_28 ) {
F_6 ( 0 , L_23 ) ;
} else {
F_6 ( 3 , L_24 ,
V_116 , V_110 ,
V_112 , V_111 ,
V_88 ) ;
V_120 [ V_88 ] += V_111 ;
}
}
V_110 = V_112 + 1 ;
}
}
for ( V_88 = 0 ; V_88 < 2 ; V_88 ++ ) {
F_6 ( 3 , L_25 ,
V_88 , V_120 [ V_88 ] , V_120 [ V_88 ] ) ;
}
if ( V_126 )
continue;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ )
V_131 [ V_102 ] = 0 ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
for ( V_130 = 0 ; V_130 < V_117 ; V_130 ++ ) {
int V_139 ;
int V_140 ;
if ( F_71 ( V_121 ) )
V_139 = V_130 ;
else
V_139 = 0x7 & F_2 (
V_27 -> V_37 . V_2 , V_122 , V_130 ) ;
for ( V_140 = 0 ; V_140 < V_124 ; V_140 ++ ) {
if ( F_64 ( V_139 ,
V_123 [ V_140 ] ) == V_102
&& ! V_131 [ V_102 ] ) {
V_132 ++ ;
V_131 [ V_102 ] = 1 ;
break;
}
}
}
}
if ( V_132 != V_117 )
F_6 ( 0 , L_26 ,
V_132 , V_117 ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
V_88 = F_62 ( V_102 ) ;
if ( V_131 [ V_102 ] ) {
F_6 ( 4 , L_27 ,
V_102 ,
V_120 [ V_88 ] / V_117 ,
V_115 ) ;
V_107 [ V_102 ] +=
V_120 [ V_88 ] / V_117 ;
}
}
}
return 0 ;
}
static int F_72 ( struct V_141 * V_142 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_144 * V_145 ;
unsigned V_71 , V_146 , V_147 , V_9 , V_15 , V_16 , V_148 ;
T_3 V_149 ;
T_1 V_4 ;
enum V_150 V_151 ;
enum V_34 V_35 ;
int V_152 = V_27 -> V_37 . type == V_13 ?
V_105 : V_153 ;
T_3 V_154 [ V_105 ] ;
if ( V_27 -> V_37 . type == V_11 || V_27 -> V_37 . type == V_12 ) {
F_21 ( V_27 -> V_155 , V_156 , & V_4 ) ;
V_27 -> V_157 = F_3 ( V_4 , 21 , 21 ) ;
}
if ( V_27 -> V_37 . type == V_11 || V_27 -> V_37 . type == V_12 ||
V_27 -> V_37 . type == V_13 )
F_21 ( V_27 -> V_28 , V_158 , & V_4 ) ;
else
F_21 ( V_27 -> V_54 , V_158 , & V_4 ) ;
if ( V_27 -> V_37 . type == V_13 )
V_27 -> V_17 -> V_159 = F_73 ( V_4 ) ;
else
V_27 -> V_17 -> V_159 = F_74 ( V_4 ) ;
V_27 -> V_17 -> V_160 = V_27 -> V_37 . F_43 ( V_27 ) ;
F_6 ( 0 , L_28 ,
V_27 -> V_17 -> V_88 ,
V_27 -> V_17 -> V_160 ,
V_27 -> V_17 -> V_159 ) ;
if ( V_27 -> V_37 . type == V_13 ) {
V_151 = V_161 ;
V_27 -> V_162 = false ;
if ( F_68 ( V_27 , V_154 ) != 0 )
return - 1 ;
} else {
F_21 ( V_27 -> V_163 , V_164 , & V_4 ) ;
if ( F_75 ( V_4 ) ) {
F_6 ( 0 , L_29 ) ;
V_27 -> V_162 = true ;
} else {
F_6 ( 0 , L_30 ) ;
V_27 -> V_162 = false ;
}
F_21 ( V_27 -> V_45 , V_46 , & V_27 -> V_37 . V_76 ) ;
if ( F_76 ( V_27 -> V_37 . V_76 ) ) {
F_6 ( 0 , L_31 ) ;
V_151 = V_165 ;
V_27 -> V_166 = true ;
} else {
F_6 ( 0 , L_32 ) ;
V_151 = V_161 ;
V_27 -> V_166 = false ;
}
if ( F_77 ( V_27 -> V_37 . V_76 ) ) {
F_6 ( 0 , L_33 ) ;
V_27 -> V_167 = true ;
} else {
F_6 ( 0 , L_34 ) ;
V_27 -> V_167 = false ;
}
}
V_35 = V_27 -> V_37 . F_35 ( V_27 ) ;
if ( V_35 == V_39 || V_35 == V_47 )
F_6 ( 0 , L_35 ) ;
else if ( V_35 == V_41 )
F_6 ( 0 , L_36 ) ;
else
F_6 ( 0 , L_37 ) ;
if ( V_35 == V_48 || V_35 == V_47 )
V_147 = 16 ;
else
V_147 = 8 ;
for ( V_71 = 0 ; V_71 < V_152 ; V_71 ++ ) {
T_1 V_8 ;
int V_168 ;
if ( V_27 -> V_37 . type == V_13 ) {
V_168 = 1 ;
if ( ! V_27 -> V_61 . V_169 [ V_71 ] )
continue;
} else {
V_168 = F_61 ( V_170 ) ;
if ( ! V_27 -> V_171 [ V_71 ] )
continue;
}
for ( V_146 = 0 ; V_146 < V_168 ; V_146 ++ ) {
V_145 = F_78 ( V_142 -> V_172 , V_142 -> V_173 , V_142 -> V_174 ,
V_71 , V_146 , 0 ) ;
if ( V_27 -> V_37 . type == V_13 ) {
F_21 ( V_27 -> V_61 . V_169 [ V_71 ] ,
V_175 , & V_8 ) ;
} else {
F_21 ( V_27 -> V_171 [ V_71 ] ,
V_170 [ V_146 ] , & V_8 ) ;
}
F_6 ( 4 , L_38 , V_71 , V_146 , V_8 ) ;
if ( F_79 ( V_8 ) ) {
V_27 -> V_102 [ V_71 ] . V_173 ++ ;
V_9 = F_4 ( V_27 -> V_37 . type , V_8 ) ;
if ( V_27 -> V_37 . type == V_13 ) {
V_16 = 1 << 10 ;
V_15 = V_154 [ V_71 ] /
( ( T_3 ) V_16 * V_9 * V_147 * 8 ) ;
} else {
V_15 = F_7 ( V_8 ) ;
V_16 = F_9 ( V_8 ) ;
}
V_149 = ( ( T_3 ) V_15 * V_16 * V_147 * V_9 ) >> ( 20 - 3 ) ;
V_148 = F_80 ( V_149 ) ;
F_6 ( 0 , L_39 ,
V_27 -> V_17 -> V_88 , V_71 / 4 , V_71 % 4 , V_146 ,
V_149 , V_148 ,
V_147 , V_9 , V_15 , V_16 ) ;
V_145 -> V_176 = V_148 ;
V_145 -> V_177 = 32 ;
V_145 -> V_178 = V_27 -> V_37 . V_179 ( V_27 , V_8 ) ;
V_145 -> V_35 = V_35 ;
V_145 -> V_180 = V_151 ;
snprintf ( V_145 -> V_181 , sizeof( V_145 -> V_181 ) ,
L_40 ,
V_27 -> V_17 -> V_159 , V_71 / 4 , V_71 % 4 , V_146 ) ;
}
}
}
return 0 ;
}
static void F_81 ( const struct V_141 * V_142 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
int V_71 , V_146 , V_182 , V_183 , V_184 , V_185 ;
T_1 V_4 ;
T_3 V_90 , V_186 = 0 ;
T_3 V_187 ;
T_1 V_188 , V_189 ;
T_1 V_190 ;
V_27 -> V_191 = V_27 -> V_37 . V_192 ( V_27 ) ;
V_187 = ( 1 + V_27 -> V_191 ) >> 20 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_41 ,
V_188 , ( V_189 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_191 ) ;
V_27 -> V_193 = V_27 -> V_37 . V_194 ( V_27 ) ;
V_187 = ( 1 + V_27 -> V_193 ) >> 20 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_42 ,
V_188 , ( V_189 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_193 ) ;
V_186 = 0 ;
for ( V_183 = 0 ; V_183 < V_27 -> V_37 . V_136 ; V_183 ++ ) {
F_21 ( V_27 -> V_137 , V_27 -> V_37 . V_121 [ V_183 ] ,
& V_4 ) ;
V_90 = V_27 -> V_37 . F_28 ( V_4 ) ;
if ( ! F_69 ( V_4 ) )
continue;
if ( V_90 <= V_186 )
break;
V_187 = ( V_90 + 1 ) >> 20 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_43 ,
V_183 ,
F_1 ( V_27 -> V_37 . F_30 ( V_4 ) ) ,
V_188 , ( V_189 * 1000 ) / 1024 ,
( ( T_3 ) V_187 ) << 20L ,
F_33 ( V_4 , V_27 -> V_37 . type ) ,
V_4 ) ;
V_186 = V_90 ;
F_21 ( V_27 -> V_137 , V_27 -> V_37 . V_138 [ V_183 ] ,
& V_4 ) ;
V_185 = F_2 ( V_27 -> V_37 . V_2 , V_4 , 0 ) ;
for ( V_146 = 0 ; V_146 < 8 ; V_146 ++ ) {
T_1 V_68 = F_2 ( V_27 -> V_37 . V_2 , V_4 , V_146 ) ;
if ( V_146 > 0 && V_185 == V_68 )
break;
F_6 ( 0 , L_44 ,
V_183 , V_146 , V_68 ) ;
}
}
if ( V_27 -> V_37 . type == V_13 )
return;
V_186 = 0 ;
for ( V_184 = 0 ; V_184 < V_195 ; V_184 ++ ) {
F_21 ( V_27 -> V_155 , V_196 [ V_184 ] ,
& V_4 ) ;
V_90 = F_83 ( V_4 ) ;
if ( V_90 <= V_186 )
break;
V_187 = ( V_90 + 1 ) >> 20 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_45 ,
V_184 , V_188 , ( V_189 * 1000 ) / 1024 ,
( ( T_3 ) V_187 ) << 20L ,
( T_1 ) ( 1 << F_84 ( V_4 ) ) ,
( T_1 ) F_85 ( V_4 ) + 1 ,
( T_1 ) F_86 ( V_4 ) ,
( T_1 ) F_87 ( V_4 ) ,
( T_1 ) F_88 ( V_4 ) ,
( T_1 ) F_89 ( V_4 ) ,
V_4 ) ;
V_186 = V_90 ;
}
for ( V_71 = 0 ; V_71 < V_153 ; V_71 ++ ) {
if ( ! V_27 -> V_102 [ V_71 ] . V_173 )
continue;
for ( V_146 = 0 ; V_146 < V_184 ; V_146 ++ ) {
F_21 ( V_27 -> V_171 [ V_71 ] ,
V_197 [ V_146 ] ,
& V_4 ) ;
V_187 = F_90 ( V_4 ) >> 20 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_46 ,
V_71 , V_146 ,
V_188 , ( V_189 * 1000 ) / 1024 ,
( ( T_3 ) V_187 ) << 20L ,
V_4 ) ;
}
}
for ( V_71 = 0 ; V_71 < V_153 ; V_71 ++ ) {
if ( ! V_27 -> V_102 [ V_71 ] . V_173 )
continue;
for ( V_146 = 0 ; V_146 < V_198 ; V_146 ++ ) {
F_21 ( V_27 -> V_171 [ V_71 ] ,
V_199 [ V_146 ] ,
& V_4 ) ;
if ( ! F_91 ( V_4 ) )
continue;
V_187 = V_27 -> V_37 . F_27 ( V_4 ) >> 20 ;
V_190 = 1 << F_92 ( V_4 ) ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_47 ,
V_71 , V_146 ,
V_188 , ( V_189 * 1000 ) / 1024 ,
( ( T_3 ) V_187 ) << 20L ,
V_190 ,
V_4 ) ;
for ( V_182 = 0 ; V_182 < V_190 ; V_182 ++ ) {
F_21 ( V_27 -> V_171 [ V_71 ] ,
V_200 [ V_146 ] [ V_182 ] ,
& V_4 ) ;
V_187 = F_93 ( V_27 -> V_37 . type , V_4 ) << 6 ;
V_188 = F_82 ( V_187 , 1024 , & V_189 ) ;
F_6 ( 0 , L_48 ,
V_71 , V_146 , V_182 ,
V_188 , ( V_189 * 1000 ) / 1024 ,
( ( T_3 ) V_187 ) << 20L ,
( T_1 ) F_94 ( V_27 -> V_37 . type , V_4 ) ,
V_4 ) ;
}
}
}
}
static struct V_141 * F_95 ( T_2 V_160 )
{
struct V_17 * V_17 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_17 -> V_160 == V_160 )
return V_17 -> V_142 ;
}
return NULL ;
}
static int F_96 ( struct V_141 * V_142 ,
T_3 V_70 ,
T_2 * V_201 , T_2 * V_202 ,
long * V_203 ,
T_2 * V_204 ,
char * * V_205 , char * V_206 )
{
struct V_141 * V_207 ;
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_208 ;
int V_209 , V_183 , V_184 , V_210 , V_211 ;
int V_185 , V_69 , V_212 ;
int F_29 , V_213 = 0 ;
unsigned V_214 [ V_27 -> V_37 . V_215 ] ;
T_1 V_4 , V_121 ;
T_2 V_216 , V_217 , V_68 , V_218 = 0 , V_219 = 0 ;
T_1 V_220 ;
T_1 V_190 ;
T_1 V_189 , V_188 ;
T_3 V_221 , V_89 , V_90 = 0 , V_186 = 0 ;
if ( ( V_70 > ( T_3 ) V_27 -> V_191 ) && ( V_70 < ( 1LL << 32 ) ) ) {
sprintf ( V_206 , L_49 , V_70 ) ;
return - V_14 ;
}
if ( V_70 >= ( T_3 ) V_27 -> V_193 ) {
sprintf ( V_206 , L_50 , V_70 ) ;
return - V_14 ;
}
for ( V_183 = 0 ; V_183 < V_27 -> V_37 . V_136 ; V_183 ++ ) {
F_21 ( V_27 -> V_137 , V_27 -> V_37 . V_121 [ V_183 ] ,
& V_4 ) ;
if ( ! F_69 ( V_4 ) )
continue;
V_90 = V_27 -> V_37 . F_28 ( V_4 ) ;
if ( V_90 <= V_186 ) {
sprintf ( V_206 , L_51 ) ;
return - V_14 ;
}
if ( V_70 <= V_90 )
break;
V_186 = V_90 ;
}
if ( V_183 == V_27 -> V_37 . V_136 ) {
sprintf ( V_206 , L_51 ) ;
return - V_14 ;
}
V_121 = V_4 ;
* V_205 = F_1 ( V_27 -> V_37 . F_30 ( V_121 ) ) ;
F_29 = V_27 -> V_37 . F_29 ( V_121 ) ;
F_21 ( V_27 -> V_137 , V_27 -> V_37 . V_138 [ V_183 ] ,
& V_4 ) ;
if ( V_27 -> V_37 . type == V_80 ) {
V_185 = F_2 ( V_27 -> V_37 . V_2 , V_4 , 0 ) ;
for ( V_210 = 0 ; V_210 < 8 ; V_210 ++ ) {
T_1 V_68 = F_2 ( V_27 -> V_37 . V_2 , V_4 , V_210 ) ;
if ( V_210 > 0 && V_185 == V_68 )
break;
V_214 [ V_210 ] = V_68 ;
F_6 ( 0 , L_52 ,
V_210 , V_214 [ V_210 ] ) ;
}
F_6 ( 0 , L_53 ,
V_27 -> V_17 -> V_88 ,
V_183 ,
V_70 ,
V_90 ,
V_210 + 7 ,
! F_29 ? L_21 : L_54 ) ;
if ( F_29 )
V_69 = ( ( V_70 >> 6 ) ^ ( V_70 >> 16 ) ) & 7 ;
else
V_69 = ( V_70 >> 6 ) & 7 ;
switch ( V_210 ) {
case 1 :
V_69 = 0 ;
break;
case 2 :
V_69 = V_69 & 1 ;
break;
case 4 :
V_69 = V_69 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_206 , L_55 ) ;
return - V_14 ;
}
* V_201 = V_214 [ V_69 ] ;
F_6 ( 0 , L_56 ,
V_69 , V_210 , * V_201 ) ;
} else if ( V_27 -> V_37 . type == V_11 || V_27 -> V_37 . type == V_12 ) {
int V_222 , V_223 = F_97 ( V_121 ) ;
if ( V_223 ) {
V_222 = F_3 ( V_70 , 7 , 8 ) << 1 ;
V_222 |= F_3 ( V_70 , 9 , 9 ) ;
} else
V_222 = F_3 ( V_70 , 6 , 8 ) ;
if ( F_29 == 0 ) {
V_69 = F_3 ( V_70 , 16 , 18 ) ;
V_69 ^= V_222 ;
} else
V_69 = V_222 ;
V_68 = F_2 ( V_27 -> V_37 . V_2 , V_4 , V_69 ) ;
* V_201 = F_51 ( V_68 ) ;
V_218 = F_52 ( V_68 ) ;
if ( V_218 )
V_219 = 4 ;
if ( V_223 ) {
F_21 ( V_27 -> V_155 ,
V_156 , & V_4 ) ;
V_213 = F_3 ( V_4 , 22 , 22 ) ;
}
F_6 ( 0 , L_57 ,
V_69 , * V_201 , V_218 , V_213 ) ;
} else {
V_69 = ( V_70 >> 6 ) & 7 ;
V_68 = F_2 ( V_27 -> V_37 . V_2 , V_4 , V_69 ) ;
* V_201 = F_51 ( V_68 ) ;
V_218 = F_52 ( V_68 ) ;
if ( V_218 )
V_219 = 4 ;
F_6 ( 0 , L_58 ,
V_69 , * V_201 , V_218 ) ;
}
* V_202 = V_218 ;
V_207 = F_95 ( * V_201 ) ;
if ( ! V_207 ) {
sprintf ( V_206 , L_59 ,
* V_201 ) ;
return - V_14 ;
}
V_142 = V_207 ;
V_27 = V_142 -> V_143 ;
V_186 = 0 ;
if ( V_27 -> V_37 . type == V_80 )
V_208 = V_27 -> V_155 ;
else {
if ( V_218 )
V_208 = V_27 -> V_224 ;
else
V_208 = V_27 -> V_155 ;
}
for ( V_184 = 0 ; V_184 < V_195 ; V_184 ++ ) {
F_21 ( V_208 , V_196 [ V_184 ] , & V_4 ) ;
V_90 = F_83 ( V_4 ) ;
if ( V_90 <= V_186 ) {
sprintf ( V_206 , L_60 ) ;
return - V_14 ;
}
if ( V_70 <= V_90 )
break;
V_186 = V_90 ;
}
if ( V_184 == V_195 ) {
sprintf ( V_206 , L_60 ) ;
return - V_14 ;
}
V_216 = F_85 ( V_4 ) + 1 ;
V_217 = F_84 ( V_4 ) ;
if ( V_216 == 3 )
V_69 = V_70 >> 6 ;
else {
V_69 = ( V_70 >> ( 6 + V_217 + V_213 ) ) & 0x3 ;
if ( V_27 -> V_157 )
V_69 = F_53 ( V_69 , V_70 ) ;
}
V_69 = V_69 % V_216 ;
switch ( V_69 ) {
case 0 :
V_212 = F_86 ( V_4 ) ;
break;
case 1 :
V_212 = F_87 ( V_4 ) ;
break;
case 2 :
V_212 = F_88 ( V_4 ) ;
break;
case 3 :
V_212 = F_89 ( V_4 ) ;
break;
default:
sprintf ( V_206 , L_61 ) ;
return - V_14 ;
}
* V_203 = 1 << V_212 ;
F_21 ( V_27 -> V_171 [ V_219 + V_212 ] ,
V_197 [ V_184 ] ,
& V_220 ) ;
if ( V_27 -> V_162 ) {
* V_203 |= 1 << ( ( V_212 + 2 ) % 4 ) ;
switch( V_216 ) {
case 2 :
case 4 :
V_211 = ( 1 << V_217 ) * ( V_216 >> 1 ) ;
break;
default:
sprintf ( V_206 , L_62 ) ;
return - V_14 ;
}
} else
V_211 = ( 1 << V_217 ) * V_216 ;
if ( V_27 -> V_166 )
* V_203 |= 1 << ( ( V_212 + 1 ) % 4 ) ;
V_89 = F_90 ( V_220 ) ;
F_6 ( 0 , L_63 ,
V_184 ,
V_70 ,
V_90 ,
V_217 ,
V_216 ,
V_89 ,
V_69 ,
V_212 ,
* V_203 ) ;
if ( V_89 > V_70 ) {
sprintf ( V_206 , L_64 ,
V_89 , V_70 ) ;
return - V_14 ;
}
V_221 = V_70 - V_89 ;
V_221 >>= ( 6 + V_213 ) ;
V_221 /= V_211 ;
V_221 <<= ( 6 + V_213 ) ;
V_221 |= V_70 & ( ( 1 << ( 6 + V_213 ) ) - 1 ) ;
for ( V_209 = 0 ; V_209 < V_198 ; V_209 ++ ) {
F_21 ( V_27 -> V_171 [ V_219 + V_212 ] ,
V_199 [ V_209 ] ,
& V_4 ) ;
if ( ! F_91 ( V_4 ) )
continue;
V_90 = V_27 -> V_37 . F_27 ( V_4 ) ;
V_188 = F_82 ( V_90 >> 20 , 1024 , & V_189 ) ;
F_6 ( 0 , L_65 ,
V_209 ,
V_188 , ( V_189 * 1000 ) / 1024 ,
V_90 ,
1 << F_92 ( V_4 ) ) ;
if ( V_221 <= V_90 )
break;
}
if ( V_209 == V_198 ) {
sprintf ( V_206 , L_66 ,
V_221 ) ;
return - V_14 ;
}
V_190 = F_92 ( V_4 ) ;
if ( V_27 -> V_167 )
V_69 = ( V_221 >> 6 ) ;
else
V_69 = ( V_221 >> 13 ) ;
V_69 %= 1 << V_190 ;
F_21 ( V_27 -> V_171 [ V_219 + V_212 ] ,
V_200 [ V_209 ] [ V_69 ] ,
& V_4 ) ;
* V_204 = F_94 ( V_27 -> V_37 . type , V_4 ) ;
F_6 ( 0 , L_67 ,
V_209 ,
V_221 ,
V_90 ,
V_190 ,
V_69 ) ;
return 0 ;
}
static void F_98 ( struct V_17 * V_17 )
{
int V_71 ;
F_6 ( 0 , L_68 ) ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
struct V_72 * V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
F_6 ( 0 , L_69 ,
V_24 -> V_18 -> V_75 ,
F_99 ( V_24 -> V_225 ) , F_100 ( V_24 -> V_225 ) ) ;
F_101 ( V_24 ) ;
}
}
static void F_102 ( void )
{
struct V_17 * V_17 , * V_226 ;
F_103 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_98 ( V_17 ) ;
F_18 ( V_17 ) ;
}
}
static int F_104 ( struct V_72 * * V_227 ,
T_2 * V_228 ,
const struct V_22 * V_3 ,
const unsigned V_229 ,
const int V_19 )
{
struct V_17 * V_17 ;
const struct V_230 * V_231 = & V_3 -> V_232 [ V_229 ] ;
struct V_72 * V_24 = NULL ;
T_2 V_18 = 0 ;
F_57 ( V_233 ,
L_70 ,
V_74 , V_231 -> V_234 ) ;
V_24 = F_55 ( V_74 ,
V_231 -> V_234 , * V_227 ) ;
if ( ! V_24 ) {
if ( * V_227 ) {
* V_227 = V_24 ;
return 0 ;
}
if ( V_231 -> V_235 )
return 0 ;
if ( V_229 == 0 )
return - V_84 ;
F_57 ( V_236 ,
L_71 ,
V_74 , V_231 -> V_234 ) ;
return - V_84 ;
}
V_18 = V_24 -> V_18 -> V_75 ;
V_17 = F_11 ( V_18 , V_19 ) ;
if ( ! V_17 ) {
V_17 = F_14 ( V_18 , V_3 ) ;
if ( ! V_17 ) {
F_101 ( V_24 ) ;
return - V_237 ;
}
( * V_228 ) ++ ;
}
if ( V_17 -> V_24 [ V_229 ] ) {
F_57 ( V_85 ,
L_72 ,
V_74 , V_231 -> V_234 ) ;
F_101 ( V_24 ) ;
return - V_84 ;
}
V_17 -> V_24 [ V_229 ] = V_24 ;
if ( F_105 ( F_106 ( V_24 ) < 0 ) ) {
F_57 ( V_85 ,
L_73 ,
V_74 , V_231 -> V_234 ) ;
return - V_84 ;
}
F_6 ( 0 , L_74 ,
V_74 , V_231 -> V_234 ) ;
F_107 ( V_24 ) ;
* V_227 = V_24 ;
return 0 ;
}
static int F_108 ( T_2 * V_228 ,
const struct V_22 * V_3 )
{
int V_71 , V_58 ;
struct V_72 * V_24 = NULL ;
int V_238 = 0 ;
int V_19 = 0 ;
if ( V_3 -> type == V_13 )
V_238 = V_19 = 1 ;
while ( V_3 && V_3 -> V_232 ) {
for ( V_71 = 0 ; V_71 < V_3 -> V_25 ; V_71 ++ ) {
if ( ! V_238 || V_71 == 0 ||
V_3 -> V_232 [ V_71 ] . V_234 !=
V_3 -> V_232 [ V_71 - 1 ] . V_234 ) {
V_24 = NULL ;
}
do {
V_58 = F_104 ( & V_24 , V_228 ,
V_3 , V_71 , V_19 ) ;
if ( V_58 < 0 ) {
if ( V_71 == 0 ) {
V_71 = V_3 -> V_25 ;
break;
}
F_102 () ;
return - V_84 ;
}
} while ( V_24 && ! V_238 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_109 ( struct V_141 * V_142 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_24 ;
T_2 V_239 = 0 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_240 ) {
case V_241 :
V_27 -> V_137 = V_24 ;
break;
case V_242 :
V_27 -> V_28 = V_24 ;
break;
case V_243 :
V_27 -> V_54 = V_24 ;
break;
case V_244 :
V_27 -> V_155 = V_24 ;
break;
case V_81 :
V_27 -> V_45 = V_24 ;
break;
case V_245 :
V_27 -> V_163 = V_24 ;
break;
case V_246 :
case V_247 :
case V_248 :
case V_249 :
{
int V_73 = V_24 -> V_240 - V_246 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_250 :
V_27 -> V_36 = V_24 ;
break;
default:
goto error;
}
F_6 ( 0 , L_75 ,
V_24 -> V_251 , V_24 -> V_240 ,
V_17 -> V_18 ,
V_24 ) ;
}
if ( ! V_27 -> V_137 || ! V_27 -> V_28 || ! V_27 -> V_155 ||
! V_27 -> V_163 || ! V_27 -> V_45 )
goto V_252;
if ( V_239 != 0x0f )
goto V_252;
return 0 ;
V_252:
F_57 ( V_85 , L_76 ) ;
return - V_84 ;
error:
F_57 ( V_85 , L_77 ,
V_74 , V_24 -> V_240 ) ;
return - V_14 ;
}
static int F_110 ( struct V_141 * V_142 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_24 ;
T_2 V_239 = 0 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_240 ) {
case V_253 :
V_27 -> V_155 = V_24 ;
break;
case V_78 :
V_27 -> V_45 = V_24 ;
case V_254 :
V_27 -> V_163 = V_24 ;
break;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
{
int V_73 = V_24 -> V_240 - V_255 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_259 :
V_27 -> V_36 = V_24 ;
break;
case V_260 :
V_27 -> V_36 = V_24 ;
break;
case V_261 :
V_27 -> V_137 = V_24 ;
break;
case V_262 :
V_27 -> V_54 = V_24 ;
break;
case V_263 :
V_27 -> V_31 = V_24 ;
break;
case V_264 :
V_27 -> V_224 = V_24 ;
break;
case V_265 :
case V_266 :
case V_267 :
case V_268 :
{
int V_73 = V_24 -> V_240 - V_265 + 4 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
default:
goto error;
}
F_6 ( 0 , L_78 ,
V_17 -> V_18 ,
F_99 ( V_24 -> V_225 ) , F_100 ( V_24 -> V_225 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_137 || ! V_27 -> V_155 || ! V_27 -> V_54 ||
! V_27 -> V_31 || ! V_27 -> V_163 || ! V_27 -> V_45 )
goto V_252;
if ( V_239 != 0x0f &&
V_239 != 0x33 &&
V_239 != 0xff )
goto V_252;
return 0 ;
V_252:
F_57 ( V_85 , L_76 ) ;
return - V_84 ;
error:
F_57 ( V_85 ,
L_77 , V_74 ,
V_24 -> V_240 ) ;
return - V_14 ;
}
static int F_111 ( struct V_141 * V_142 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_24 ;
T_2 V_239 = 0 ;
int V_71 ;
if ( V_27 -> V_37 . V_56 == NULL )
V_27 -> V_37 . V_56 = F_55 ( V_74 ,
V_269 ,
NULL ) ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_240 ) {
case V_270 :
V_27 -> V_137 = V_24 ;
break;
case V_271 :
V_27 -> V_28 = V_24 ;
break;
case V_272 :
V_27 -> V_155 = V_24 ;
break;
case V_79 :
V_27 -> V_45 = V_24 ;
break;
case V_273 :
V_27 -> V_163 = V_24 ;
break;
case V_274 :
case V_275 :
case V_276 :
case V_277 :
{
int V_73 = V_24 -> V_240 - V_274 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_278 :
case V_279 :
case V_280 :
case V_281 :
{
int V_73 = V_24 -> V_240 - V_278 + 4 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_282 :
case V_283 :
case V_284 :
case V_285 :
if ( ! V_27 -> V_36 )
V_27 -> V_36 = V_24 ;
break;
case V_286 :
V_27 -> V_224 = V_24 ;
break;
case V_287 :
V_27 -> V_288 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_78 ,
V_17 -> V_18 ,
F_99 ( V_24 -> V_225 ) , F_100 ( V_24 -> V_225 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_137 || ! V_27 -> V_155 || ! V_27 -> V_28 ||
! V_27 -> V_163 || ! V_27 -> V_45 || ! V_27 -> V_37 . V_56 )
goto V_252;
if ( V_239 != 0x0f &&
V_239 != 0x33 &&
V_239 != 0xff )
goto V_252;
return 0 ;
V_252:
F_57 ( V_85 , L_76 ) ;
return - V_84 ;
}
static int F_112 ( struct V_141 * V_142 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_24 ;
T_2 V_239 = 0 ;
int V_71 ;
if ( V_27 -> V_37 . V_56 == NULL )
V_27 -> V_37 . V_56 = F_55 ( V_74 ,
V_289 ,
NULL ) ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_240 ) {
case V_290 :
V_27 -> V_137 = V_24 ;
break;
case V_291 :
V_27 -> V_28 = V_24 ;
break;
case V_292 :
V_27 -> V_155 = V_24 ;
break;
case V_82 :
V_27 -> V_45 = V_24 ;
break;
case V_293 :
V_27 -> V_163 = V_24 ;
break;
case V_294 :
case V_295 :
case V_296 :
case V_297 :
{
int V_73 = V_24 -> V_240 - V_294 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_298 :
case V_299 :
case V_300 :
case V_301 :
{
int V_73 = V_24 -> V_240 - V_298 + 4 ;
V_27 -> V_171 [ V_73 ] = V_24 ;
V_239 |= 1 << V_73 ;
}
break;
case V_302 :
V_27 -> V_36 = V_24 ;
break;
case V_303 :
V_27 -> V_224 = V_24 ;
break;
case V_304 :
V_27 -> V_288 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_78 ,
V_17 -> V_18 ,
F_99 ( V_24 -> V_225 ) , F_100 ( V_24 -> V_225 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_137 || ! V_27 -> V_155 || ! V_27 -> V_28 ||
! V_27 -> V_163 || ! V_27 -> V_45 || ! V_27 -> V_37 . V_56 )
goto V_252;
if ( V_239 != 0x0f &&
V_239 != 0x33 &&
V_239 != 0xff )
goto V_252;
return 0 ;
V_252:
F_57 ( V_85 , L_76 ) ;
return - V_84 ;
}
static int F_113 ( struct V_141 * V_142 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_142 -> V_143 ;
struct V_72 * V_24 ;
int V_305 , V_306 ;
int V_71 ;
int V_307 ;
for ( V_71 = 0 ; V_71 < V_17 -> V_25 ; V_71 ++ ) {
V_24 = V_17 -> V_24 [ V_71 ] ;
if ( ! V_24 )
continue;
V_305 = ( V_24 -> V_225 >> 3 ) & 0x1f ;
V_306 = V_24 -> V_225 & 0x7 ;
switch ( V_24 -> V_240 ) {
case V_308 :
if ( V_305 == 8 )
V_27 -> V_61 . V_96 = V_24 ;
else if ( V_305 == 9 )
V_27 -> V_61 . V_97 = V_24 ;
else {
F_57 ( V_85 ,
L_79 ,
V_305 , V_306 ) ;
continue;
}
break;
case V_309 :
V_27 -> V_137 = V_24 ;
break;
case V_310 :
V_27 -> V_28 = V_24 ;
break;
case V_311 :
V_307 = ( ( V_305 - 14 ) * 8 ) + V_306 ;
if ( V_307 < 0 || V_307 >= V_124 ) {
F_57 ( V_85 ,
L_80 ,
V_305 , V_306 ) ;
continue;
}
F_60 ( V_27 -> V_61 . V_133 [ V_307 ] != NULL ) ;
V_27 -> V_61 . V_133 [ V_307 ] = V_24 ;
break;
case V_312 :
V_307 = - 1 ;
if ( V_305 == 9 )
V_307 = V_306 - 2 ;
else if ( V_305 == 8 )
V_307 = 3 + ( V_306 - 2 ) ;
if ( V_307 < 0 || V_307 >= V_105 ) {
F_57 ( V_85 ,
L_81 ,
V_305 , V_306 ) ;
continue;
}
F_60 ( V_27 -> V_61 . V_169 [ V_307 ] != NULL ) ;
V_27 -> V_61 . V_169 [ V_307 ] = V_24 ;
break;
case V_313 :
V_27 -> V_61 . V_62 = V_24 ;
break;
case V_83 :
V_27 -> V_45 = V_24 ;
break;
default:
F_57 ( V_85 , L_82 ,
V_24 -> V_240 ) ;
break;
}
}
if ( ! V_27 -> V_61 . V_96 || ! V_27 -> V_61 . V_97 ||
! V_27 -> V_137 || ! V_27 -> V_28 ||
! V_27 -> V_45 ) {
goto V_252;
}
for ( V_71 = 0 ; V_71 < V_105 ; V_71 ++ ) {
if ( ! V_27 -> V_61 . V_169 [ V_71 ] ) {
F_57 ( V_85 , L_83 , V_71 ) ;
goto V_252;
}
}
for ( V_71 = 0 ; V_71 < V_124 ; V_71 ++ ) {
if ( ! V_27 -> V_61 . V_133 [ V_71 ] ) {
F_57 ( V_85 , L_84 , V_71 ) ;
goto V_252;
}
}
return 0 ;
V_252:
F_57 ( V_85 , L_76 ) ;
return - V_84 ;
}
static void F_114 ( struct V_141 * V_142 ,
const struct V_314 * V_315 )
{
struct V_141 * V_207 ;
struct V_26 * V_27 = V_142 -> V_143 ;
enum V_316 V_317 ;
char * type , * V_318 , V_206 [ 256 ] ;
bool V_319 = F_3 ( V_315 -> V_320 , 0 , 0 ) ;
bool V_321 = F_3 ( V_315 -> V_322 , 62 , 62 ) ;
bool V_323 = F_3 ( V_315 -> V_322 , 61 , 61 ) ;
bool V_324 ;
T_1 V_325 = F_3 ( V_315 -> V_322 , 38 , 52 ) ;
T_1 V_326 = F_3 ( V_315 -> V_322 , 16 , 31 ) ;
T_1 V_327 = F_3 ( V_315 -> V_322 , 0 , 15 ) ;
T_1 V_102 = F_3 ( V_315 -> V_322 , 0 , 3 ) ;
T_1 V_328 = F_3 ( V_315 -> V_322 , 4 , 6 ) ;
long V_203 , V_329 ;
T_2 V_204 , V_201 , V_202 ;
int V_58 , V_145 ;
char * V_205 = NULL ;
if ( V_27 -> V_37 . type != V_80 )
V_324 = true ;
else
V_324 = F_3 ( V_315 -> V_322 , 56 , 56 ) ;
if ( V_323 ) {
if ( V_319 ) {
type = L_85 ;
V_317 = V_330 ;
} else {
type = L_86 ;
V_317 = V_331 ;
}
} else {
type = L_87 ;
V_317 = V_332 ;
}
if ( ! ( ( V_327 & 0xef80 ) == 0x80 ) ) {
V_318 = L_88 ;
} else {
switch ( V_328 ) {
case 0 :
V_318 = L_89 ;
break;
case 1 :
V_318 = L_90 ;
break;
case 2 :
V_318 = L_91 ;
break;
case 3 :
V_318 = L_92 ;
break;
case 4 :
V_318 = L_93 ;
break;
default:
V_318 = L_94 ;
break;
}
}
if ( ! F_3 ( V_315 -> V_322 , 58 , 58 ) )
return;
if ( V_27 -> V_37 . type == V_13 ) {
if ( V_102 == 14 ) {
F_6 ( 0 , L_95 ,
V_321 ? L_96 : L_21 ,
( V_323 && V_324 )
? L_97 : L_21 ,
V_326 , V_327 ,
V_315 -> V_333 ) ;
} else {
char V_334 = * ( L_98 ) ;
V_102 = F_65 ( V_315 -> V_333 == 16 , V_102 ) ;
V_203 = 1 << V_102 ;
snprintf ( V_206 , sizeof( V_206 ) ,
L_99 ,
V_321 ? L_96 : L_21 ,
( V_323 && V_324 )
? L_97 : L_100 ,
V_326 , V_327 , V_102 , V_334 + V_102 ) ;
F_115 ( V_317 , V_142 , V_325 ,
V_315 -> V_70 >> V_335 , V_315 -> V_70 & ~ V_336 , 0 ,
V_102 , 0 , - 1 ,
V_318 , V_206 ) ;
}
return;
} else {
V_58 = F_96 ( V_142 , V_315 -> V_70 , & V_201 , & V_202 ,
& V_203 , & V_204 , & V_205 , V_206 ) ;
}
if ( V_58 < 0 )
goto V_337;
V_207 = F_95 ( V_201 ) ;
if ( ! V_207 ) {
strcpy ( V_206 , L_101 ) ;
goto V_337;
}
V_142 = V_207 ;
V_27 = V_142 -> V_143 ;
V_329 = F_116 ( & V_203 , V_153 ) ;
if ( V_204 < 4 )
V_145 = 0 ;
else if ( V_204 < 8 )
V_145 = 1 ;
else
V_145 = 2 ;
if ( ! V_27 -> V_166 && ! V_27 -> V_162 && ! V_27 -> V_167 )
V_102 = V_329 ;
snprintf ( V_206 , sizeof( V_206 ) ,
L_102 ,
V_321 ? L_96 : L_21 ,
( V_323 && V_324 ) ? L_97 : L_21 ,
V_205 ,
V_326 , V_327 ,
V_201 , V_202 ,
V_203 ,
V_204 ) ;
F_6 ( 0 , L_103 , V_206 ) ;
if ( V_102 == V_338 )
V_102 = - 1 ;
F_115 ( V_317 , V_142 , V_325 ,
V_315 -> V_70 >> V_335 , V_315 -> V_70 & ~ V_336 , 0 ,
4 * V_202 + V_102 , V_145 , - 1 ,
V_318 , V_206 ) ;
return;
V_337:
F_115 ( V_317 , V_142 , V_325 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_206 , L_21 ) ;
}
static int F_117 ( struct V_339 * V_340 , unsigned long V_341 ,
void * V_342 )
{
struct V_314 * V_314 = (struct V_314 * ) V_342 ;
struct V_141 * V_142 ;
struct V_26 * V_27 ;
char * type ;
if ( F_118 () == V_343 )
return V_344 ;
V_142 = F_95 ( V_314 -> V_345 ) ;
if ( ! V_142 )
return V_344 ;
V_27 = V_142 -> V_143 ;
if ( ( V_314 -> V_322 & 0xefff ) >> 7 != 1 )
return V_344 ;
if ( V_314 -> V_320 & V_346 )
type = L_104 ;
else
type = L_105 ;
F_119 ( V_142 , V_233 , L_106 ) ;
F_119 ( V_142 , V_233 , L_107
L_108 , V_314 -> V_347 , type ,
V_314 -> V_320 , V_314 -> V_333 , V_314 -> V_322 ) ;
F_119 ( V_142 , V_233 , L_109 , V_314 -> V_348 ) ;
F_119 ( V_142 , V_233 , L_110 , V_314 -> V_70 ) ;
F_119 ( V_142 , V_233 , L_111 , V_314 -> V_349 ) ;
F_119 ( V_142 , V_233 , L_112
L_113 , V_314 -> V_350 , V_314 -> V_351 ,
V_314 -> time , V_314 -> V_345 , V_314 -> V_352 ) ;
F_114 ( V_142 , V_314 ) ;
return V_353 ;
}
static void F_120 ( struct V_17 * V_17 )
{
struct V_141 * V_142 = V_17 -> V_142 ;
struct V_26 * V_27 ;
if ( F_105 ( ! V_142 || ! V_142 -> V_143 ) ) {
F_6 ( 0 , L_114 , & V_17 -> V_24 [ 0 ] -> V_305 ) ;
F_57 ( V_85 , L_115 ) ;
return;
}
V_27 = V_142 -> V_143 ;
F_6 ( 0 , L_116 ,
V_142 , & V_17 -> V_24 [ 0 ] -> V_305 ) ;
F_121 ( V_142 -> V_24 ) ;
F_6 ( 1 , L_117 , V_142 -> V_354 ) ;
F_16 ( V_142 -> V_354 ) ;
F_122 ( V_142 ) ;
V_17 -> V_142 = NULL ;
}
static int F_123 ( struct V_17 * V_17 , enum type type )
{
struct V_141 * V_142 ;
struct V_355 V_172 [ 2 ] ;
struct V_26 * V_27 ;
struct V_72 * V_24 = V_17 -> V_24 [ 0 ] ;
int V_58 ;
V_58 = F_56 ( V_17 -> V_18 , type ) ;
if ( F_105 ( V_58 < 0 ) )
return V_58 ;
V_172 [ 0 ] . type = V_356 ;
V_172 [ 0 ] . V_149 = type == V_13 ?
V_105 : V_153 ;
V_172 [ 0 ] . V_357 = false ;
V_172 [ 1 ] . type = V_358 ;
V_172 [ 1 ] . V_149 = type == V_13 ? 1 : V_359 ;
V_172 [ 1 ] . V_357 = true ;
V_142 = F_124 ( V_17 -> V_88 , F_61 ( V_172 ) , V_172 ,
sizeof( * V_27 ) ) ;
if ( F_105 ( ! V_142 ) )
return - V_237 ;
F_6 ( 0 , L_116 ,
V_142 , & V_24 -> V_305 ) ;
V_27 = V_142 -> V_143 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_17 = V_17 ;
V_17 -> V_142 = V_142 ;
V_142 -> V_360 = type == V_13 ?
V_361 : V_362 ;
V_142 -> V_363 = V_364 ;
V_142 -> V_365 = V_364 ;
V_142 -> V_366 = L_118 ;
V_142 -> V_367 = V_368 ;
V_142 -> V_369 = F_125 ( V_24 ) ;
V_142 -> V_370 = NULL ;
V_27 -> V_37 . type = type ;
switch ( type ) {
case V_77 :
V_27 -> V_37 . V_38 = V_371 ;
V_27 -> V_37 . V_192 = F_25 ;
V_27 -> V_37 . V_194 = F_26 ;
V_27 -> V_37 . V_121 = V_372 ;
V_27 -> V_37 . F_35 = F_35 ;
V_27 -> V_37 . F_43 = F_43 ;
V_27 -> V_37 . F_27 = F_27 ;
V_27 -> V_37 . F_28 = F_28 ;
V_27 -> V_37 . F_29 = F_29 ;
V_27 -> V_37 . F_30 = F_30 ;
V_27 -> V_37 . V_136 = F_61 ( V_372 ) ;
V_27 -> V_37 . V_138 = V_373 ;
V_27 -> V_37 . V_215 = F_61 ( V_373 ) ;
V_27 -> V_37 . V_2 = V_374 ;
V_27 -> V_37 . V_179 = F_40 ;
V_142 -> V_354 = F_126 ( V_23 , L_119 , V_142 -> V_375 ) ;
V_58 = F_110 ( V_142 , V_17 ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_376;
break;
case V_80 :
V_27 -> V_37 . V_38 = V_377 ;
V_27 -> V_37 . V_192 = F_20 ;
V_27 -> V_37 . V_194 = F_23 ;
V_27 -> V_37 . V_121 = V_378 ;
V_27 -> V_37 . F_35 = F_35 ;
V_27 -> V_37 . F_43 = F_43 ;
V_27 -> V_37 . F_27 = F_27 ;
V_27 -> V_37 . F_28 = F_28 ;
V_27 -> V_37 . F_29 = F_29 ;
V_27 -> V_37 . F_30 = F_30 ;
V_27 -> V_37 . V_136 = F_61 ( V_378 ) ;
V_27 -> V_37 . V_138 = V_379 ;
V_27 -> V_37 . V_215 = F_61 ( V_379 ) ;
V_27 -> V_37 . V_2 = V_380 ;
V_27 -> V_37 . V_179 = F_38 ;
V_142 -> V_354 = F_126 ( V_23 , L_120 , V_142 -> V_375 ) ;
V_58 = F_109 ( V_142 , V_17 ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_376;
break;
case V_11 :
V_27 -> V_37 . V_192 = F_46 ;
V_27 -> V_37 . V_194 = F_47 ;
V_27 -> V_37 . V_121 = V_372 ;
V_27 -> V_37 . F_35 = F_36 ;
V_27 -> V_37 . F_43 = F_44 ;
V_27 -> V_37 . F_27 = F_50 ;
V_27 -> V_37 . F_28 = F_28 ;
V_27 -> V_37 . F_29 = F_29 ;
V_27 -> V_37 . F_30 = F_30 ;
V_27 -> V_37 . V_136 = F_61 ( V_372 ) ;
V_27 -> V_37 . V_138 = V_373 ;
V_27 -> V_37 . V_215 = F_61 ( V_373 ) ;
V_27 -> V_37 . V_2 = V_374 ;
V_27 -> V_37 . V_179 = F_40 ;
V_142 -> V_354 = F_126 ( V_23 , L_121 , V_142 -> V_375 ) ;
V_58 = F_111 ( V_142 , V_17 ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_376;
break;
case V_12 :
V_27 -> V_37 . V_192 = F_46 ;
V_27 -> V_37 . V_194 = F_47 ;
V_27 -> V_37 . V_121 = V_372 ;
V_27 -> V_37 . F_35 = F_36 ;
V_27 -> V_37 . F_43 = F_44 ;
V_27 -> V_37 . F_27 = F_50 ;
V_27 -> V_37 . F_28 = F_28 ;
V_27 -> V_37 . F_29 = F_29 ;
V_27 -> V_37 . F_30 = F_30 ;
V_27 -> V_37 . V_136 = F_61 ( V_372 ) ;
V_27 -> V_37 . V_138 = V_373 ;
V_27 -> V_37 . V_215 = F_61 ( V_373 ) ;
V_27 -> V_37 . V_2 = V_374 ;
V_27 -> V_37 . V_179 = F_41 ;
V_142 -> V_354 = F_126 ( V_23 , L_122 , V_142 -> V_375 ) ;
V_58 = F_112 ( V_142 , V_17 ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_376;
break;
case V_13 :
V_27 -> V_37 . V_192 = F_48 ;
V_27 -> V_37 . V_194 = F_49 ;
V_27 -> V_37 . V_121 = V_381 ;
V_27 -> V_37 . F_35 = F_42 ;
V_27 -> V_37 . F_43 = F_45 ;
V_27 -> V_37 . F_27 = NULL ;
V_27 -> V_37 . F_28 = F_31 ;
V_27 -> V_37 . F_29 = F_32 ;
V_27 -> V_37 . F_30 = F_34 ;
V_27 -> V_37 . V_136 = F_61 ( V_381 ) ;
V_27 -> V_37 . V_138 = V_382 ;
V_27 -> V_37 . V_215 = F_61 ( V_382 ) ;
V_27 -> V_37 . V_2 = V_374 ;
V_27 -> V_37 . V_179 = F_37 ;
V_142 -> V_354 = F_126 ( V_23 ,
L_123 , V_142 -> V_375 ) ;
V_58 = F_113 ( V_142 , V_17 ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_376;
break;
}
F_72 ( V_142 ) ;
F_81 ( V_142 ) ;
V_142 -> V_24 = & V_24 -> V_305 ;
if ( F_105 ( F_127 ( V_142 ) ) ) {
F_6 ( 0 , L_124 ) ;
V_58 = - V_14 ;
goto V_376;
}
return 0 ;
V_376:
F_16 ( V_142 -> V_354 ) ;
F_122 ( V_142 ) ;
V_17 -> V_142 = NULL ;
return V_58 ;
}
static int F_128 ( const struct V_383 * V_73 )
{
int V_58 = - V_84 ;
T_2 V_88 , V_228 = 0 ;
struct V_17 * V_17 ;
struct V_22 * V_384 = (struct V_22 * ) V_73 -> V_385 ;
V_58 = F_108 ( & V_228 , V_384 ) ;
if ( F_105 ( V_58 < 0 ) ) {
F_6 ( 0 , L_125 ) ;
goto V_376;
}
V_88 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_6 ( 0 , L_126 ,
V_88 , V_88 + 1 , V_228 ) ;
V_17 -> V_88 = V_88 ++ ;
V_58 = F_123 ( V_17 , V_384 -> type ) ;
if ( F_105 ( V_58 < 0 ) )
goto V_386;
}
F_57 ( V_236 , L_103 , V_368 ) ;
return 0 ;
V_386:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_120 ( V_17 ) ;
F_102 () ;
V_376:
return V_58 ;
}
static void F_129 ( void )
{
struct V_17 * V_17 ;
F_6 ( 0 , L_68 ) ;
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_120 ( V_17 ) ;
F_102 () ;
}
static int T_4 F_130 ( void )
{
const struct V_383 * V_73 ;
int V_58 ;
F_6 ( 2 , L_68 ) ;
V_73 = F_131 ( V_387 ) ;
if ( ! V_73 )
return - V_84 ;
F_132 () ;
V_58 = F_128 ( V_73 ) ;
if ( V_58 >= 0 ) {
F_133 ( & V_388 ) ;
if ( F_118 () == V_343 )
F_57 ( V_389 , L_127 ) ;
return 0 ;
}
F_57 ( V_85 , L_128 ,
V_58 ) ;
return V_58 ;
}
static void T_5 F_134 ( void )
{
F_6 ( 2 , L_68 ) ;
F_129 () ;
F_135 ( & V_388 ) ;
}
