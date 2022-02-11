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
char * F_30 ( T_1 V_4 )
{
return F_29 ( V_4 ) ? L_8 : L_9 ;
}
static T_1 F_31 ( T_1 V_4 )
{
return F_3 ( V_4 , 2 , 3 ) ;
}
static T_3 F_32 ( T_1 V_4 )
{
return ( F_3 ( V_4 , 7 , 26 ) << 26 ) | 0x3ffffff ;
}
static T_1 F_33 ( T_1 V_4 )
{
return F_3 ( V_4 , 1 , 2 ) ;
}
static char * F_34 ( T_1 V_4 )
{
char * V_32 ;
switch ( F_33 ( V_4 ) ) {
case 0 :
V_32 = L_10 ;
break;
case 1 :
V_32 = L_11 ;
break;
case 2 :
V_32 = L_12 ;
break;
case 3 :
V_32 = L_13 ;
break;
default:
F_35 ( 1 ) ;
break;
}
return V_32 ;
}
static T_1 F_36 ( T_1 V_4 )
{
return F_3 ( V_4 , 3 , 4 ) ;
}
static enum V_33 F_37 ( struct V_26 * V_27 )
{
T_1 V_4 ;
enum V_33 V_34 ;
if ( V_27 -> V_35 ) {
F_21 ( V_27 -> V_35 , V_27 -> V_36 . V_37 ,
& V_4 ) ;
if ( F_3 ( V_4 , 11 , 11 ) )
V_34 = V_38 ;
else
V_34 = V_39 ;
} else
V_34 = V_40 ;
return V_34 ;
}
static enum V_33 F_38 ( struct V_26 * V_27 )
{
T_1 V_4 ;
bool V_41 = false ;
enum V_33 V_34 = V_40 ;
if ( ! V_27 -> V_35 )
goto V_42;
F_21 ( V_27 -> V_35 ,
V_43 , & V_4 ) ;
if ( F_3 ( V_4 , 16 , 16 ) )
V_41 = true ;
F_21 ( V_27 -> V_44 , V_45 , & V_4 ) ;
if ( F_3 ( V_4 , 14 , 14 ) ) {
if ( V_41 )
V_34 = V_46 ;
else
V_34 = V_47 ;
} else {
if ( V_41 )
V_34 = V_38 ;
else
V_34 = V_39 ;
}
V_42:
return V_34 ;
}
static enum V_48 F_39 ( struct V_26 * V_27 , T_1 V_8 )
{
return V_49 ;
}
static enum V_48 F_40 ( struct V_26 * V_27 , T_1 V_8 )
{
return V_50 ;
}
static enum V_48 F_41 ( T_1 V_8 )
{
enum V_48 type ;
switch ( V_8 ) {
case 3 :
type = V_50 ;
break;
case 2 :
type = V_49 ;
break;
case 1 :
type = V_51 ;
break;
case 0 :
type = V_52 ;
break;
}
return type ;
}
static enum V_48 F_42 ( struct V_26 * V_27 , T_1 V_8 )
{
return F_41 ( F_3 ( V_8 , 7 , 8 ) ) ;
}
static enum V_48 F_43 ( struct V_26 * V_27 , T_1 V_8 )
{
return F_41 ( F_3 ( V_8 , 8 , 9 ) ) ;
}
static enum V_33 F_44 ( struct V_26 * V_27 )
{
return V_46 ;
}
static T_2 F_45 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_53 , V_54 , & V_4 ) ;
return F_3 ( V_4 , 0 , 2 ) ;
}
static T_2 F_46 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_54 , & V_4 ) ;
return F_3 ( V_4 , 0 , 3 ) ;
}
static T_2 F_47 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_28 , V_54 , & V_4 ) ;
return F_3 ( V_4 , 0 , 2 ) ;
}
static T_3 F_48 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_36 . V_55 , V_56 , & V_4 ) ;
return ( F_3 ( V_4 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_49 ( struct V_26 * V_27 )
{
T_3 V_57 ;
T_1 V_4 ;
F_21 ( V_27 -> V_36 . V_55 , V_58 , & V_4 ) ;
V_57 = F_3 ( V_4 , 26 , 31 ) ;
F_21 ( V_27 -> V_36 . V_55 , V_59 , & V_4 ) ;
V_57 = ( ( V_4 << 6 ) | V_57 ) << 26 ;
return V_57 | 0x1ffffff ;
}
static T_3 F_50 ( struct V_26 * V_27 )
{
T_1 V_4 ;
F_21 ( V_27 -> V_60 . V_61 , V_62 , & V_4 ) ;
return ( F_3 ( V_4 , 26 , 31 ) << 26 ) | 0x3ffffff ;
}
static T_3 F_51 ( struct V_26 * V_27 )
{
T_3 V_57 ;
T_1 V_63 , V_64 ;
F_21 ( V_27 -> V_60 . V_61 , V_65 , & V_63 ) ;
F_21 ( V_27 -> V_60 . V_61 , V_66 , & V_64 ) ;
V_57 = ( ( T_3 ) V_64 << 32 ) | V_63 ;
return V_57 | 0x3ffffff ;
}
static T_3 F_52 ( T_1 V_4 )
{
return ( ( ( T_3 ) F_3 ( V_4 , 1 , 11 ) + 1 ) << 29 ) - 1 ;
}
static inline T_2 F_53 ( T_2 V_67 )
{
return ( ( V_67 >> 3 ) << 2 ) | ( V_67 & 0x3 ) ;
}
static inline T_2 F_54 ( T_2 V_67 )
{
return ( V_67 >> 2 ) & 0x1 ;
}
static struct V_68 * F_55 ( T_2 V_18 , T_1 V_69 )
{
struct V_68 * V_24 = NULL ;
do {
V_24 = F_56 ( V_70 , V_69 , V_24 ) ;
if ( V_24 && V_24 -> V_18 -> V_71 == V_18 )
break;
} while ( V_24 );
return V_24 ;
}
static int F_57 ( const T_2 V_18 , enum type type )
{
struct V_68 * V_24 = NULL ;
T_1 V_72 , V_69 ;
switch ( type ) {
case V_73 :
V_69 = V_74 ;
break;
case V_11 :
V_69 = V_75 ;
break;
case V_76 :
V_69 = V_77 ;
break;
case V_12 :
V_69 = V_78 ;
break;
case V_13 :
V_69 = V_79 ;
break;
default:
return - V_80 ;
}
if ( type != V_13 )
V_24 = F_55 ( V_18 , V_69 ) ;
else
V_24 = F_56 ( V_70 , V_69 , 0 ) ;
if ( ! V_24 ) {
F_58 ( V_81 , L_14
L_15 ,
V_70 , V_69 , V_18 ) ;
return - V_80 ;
}
F_21 ( V_24 ,
type == V_13 ? V_82 : V_45 , & V_72 ) ;
if ( ! F_59 ( V_72 ) ) {
F_58 ( V_81 , L_16 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_60 ( const struct V_26 * V_27 ,
const int V_83 ,
const int V_84 ,
T_3 * V_85 ,
T_3 * V_86 ,
int * V_87 )
{
T_1 V_88 , V_89 , V_64 ;
struct V_68 * V_90 ;
int V_91 ;
switch ( V_84 ) {
case 0 :
V_90 = V_27 -> V_60 . V_92 ;
break;
case 1 :
V_90 = V_27 -> V_60 . V_93 ;
break;
default:
F_35 ( 1 ) ;
return - V_14 ;
}
F_21 ( V_90 ,
V_94 [ V_83 ] , & V_88 ) ;
F_21 ( V_90 ,
V_95 [ V_83 ] , & V_89 ) ;
F_21 ( V_90 ,
V_96 [ V_83 ] , & V_64 ) ;
if ( ! F_3 ( V_88 , 0 , 0 ) )
return - V_80 ;
V_91 = F_3 ( V_88 , 3 , 5 ) ;
if ( V_91 < F_61 ( V_97 ) ) {
* V_87 = V_97 [ V_91 ] ;
} else {
* V_87 = 0 ;
F_58 ( V_81 ,
L_17 ,
V_91 ) ;
return - V_80 ;
}
* V_85 = ( ( T_3 ) F_3 ( V_89 , 6 , 31 ) << 6 ) |
( ( T_3 ) F_3 ( V_64 , 0 , 15 ) << 32 ) ;
* V_86 = ( ( T_3 ) F_3 ( V_88 , 6 , 31 ) << 6 ) | 63 |
( ( T_3 ) F_3 ( V_64 , 16 , 31 ) << 32 ) ;
return 0 ;
}
static int F_62 ( int V_98 )
{
F_35 ( V_98 < 0 || V_98 >= 6 ) ;
return V_98 < 3 ? 1 : 0 ;
}
static T_1 F_63 ( int V_83 , T_1 V_4 )
{
F_35 ( V_83 >= V_99 ) ;
return F_3 ( V_4 , V_83 * 3 , ( V_83 * 3 ) + 2 ) ;
}
static T_1 F_64 ( int V_83 , T_1 V_4 )
{
int V_84 , V_100 ;
F_35 ( V_83 >= V_101 ) ;
V_84 = F_3 ( V_4 , V_83 * 3 , ( V_83 * 3 ) + 2 ) ;
V_100 = F_3 ( V_4 , ( V_83 * 2 ) + 18 , ( V_83 * 2 ) + 18 + 1 ) ;
return F_65 ( V_84 * 3 + V_100 ) ;
}
static void F_66 ( T_1 V_4 , char * V_32 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_99 ; V_102 ++ ) {
V_32 [ V_102 * 2 ] = F_63 ( V_102 , V_4 ) + '0' ;
V_32 [ V_102 * 2 + 1 ] = '-' ;
}
V_32 [ V_99 * 2 - 1 ] = '\0' ;
}
static void F_67 ( T_1 V_4 , char * V_32 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ ) {
V_32 [ V_102 * 2 ] = F_64 ( V_102 , V_4 ) + '0' ;
V_32 [ V_102 * 2 + 1 ] = '-' ;
}
V_32 [ V_101 * 2 - 1 ] = '\0' ;
}
static int F_68 ( struct V_26 * V_27 , T_3 * V_103 )
{
T_3 V_104 , V_105 , F_28 = 0 ;
T_3 V_106 , V_107 , V_108 , V_109 , V_110 ;
int V_111 = 0 ;
int V_112 = 0 ;
int V_113 , V_114 ;
T_1 V_115 , V_67 ;
int V_102 ;
T_3 V_116 [ 2 ] ;
T_1 V_117 , V_118 ;
T_1 V_119 [ V_120 ] ;
T_1 V_121 [ V_120 ] ;
int V_122 ;
char V_123 [ V_99 * 2 ] ;
char V_124 [ V_101 * 2 ] ;
int V_125 ;
int V_84 ;
int V_98 ;
int V_126 ;
int V_127 [ V_101 ] ;
int V_128 = 0 ;
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ )
V_103 [ V_102 ] = 0 ;
V_125 = 0 ;
for ( V_102 = 0 ; V_102 < V_120 ; V_102 ++ ) {
F_21 ( V_27 -> V_60 . V_129 [ V_102 ] ,
V_130 , & V_121 [ V_102 ] ) ;
if ( V_102 > 0 && V_121 [ V_102 ] != V_121 [ V_102 - 1 ] ) {
F_66 ( V_121 [ V_102 - 1 ] ,
V_123 ) ;
if ( V_125 == V_102 - 1 )
F_6 ( 0 , L_18 ,
V_125 , V_123 ) ;
else
F_6 ( 0 , L_19 ,
V_125 , V_102 - 1 , V_123 ) ;
V_125 = V_102 ;
}
}
F_66 ( V_121 [ V_102 - 1 ] , V_123 ) ;
if ( V_125 == V_102 - 1 )
F_6 ( 0 , L_18 ,
V_125 , V_123 ) ;
else
F_6 ( 0 , L_19 ,
V_125 , V_102 - 1 , V_123 ) ;
V_125 = 0 ;
for ( V_102 = 0 ; V_102 < V_120 ; V_102 ++ ) {
F_21 ( V_27 -> V_60 . V_129 [ V_102 ] ,
V_131 , & V_119 [ V_102 ] ) ;
if ( V_102 > 0 && V_119 [ V_102 ] != V_119 [ V_102 - 1 ] ) {
F_67 ( V_119 [ V_102 - 1 ] , V_124 ) ;
if ( V_125 == V_102 - 1 )
F_6 ( 0 , L_20 ,
V_125 , V_124 ) ;
else
F_6 ( 0 , L_21 ,
V_125 , V_102 - 1 , V_124 ) ;
V_125 = V_102 ;
}
}
F_67 ( V_119 [ V_102 - 1 ] , V_124 ) ;
if ( V_125 == V_102 - 1 )
F_6 ( 0 , L_20 ,
V_125 , V_124 ) ;
else
F_6 ( 0 , L_21 ,
V_125 , V_102 - 1 , V_124 ) ;
for ( V_111 = 0 ; V_111 < V_27 -> V_36 . V_132 ; V_111 ++ ) {
V_104 = F_28 ;
F_21 ( V_27 -> V_133 ,
V_27 -> V_36 . V_117 [ V_111 ] , & V_117 ) ;
if ( ! F_69 ( V_117 ) )
break;
V_122 = F_70 ( V_117 ) ;
F_28 = V_27 -> V_36 . F_28 ( V_117 ) + 1 ;
V_105 = F_28 - V_104 ;
F_21 ( V_27 -> V_133 ,
V_27 -> V_36 . V_134 [ V_111 ] , & V_118 ) ;
V_115 = F_2 ( V_27 -> V_36 . V_2 ,
V_118 , 0 ) ;
for ( V_113 = 1 ; V_113 < 8 ; V_113 ++ ) {
V_67 = F_2 ( V_27 -> V_36 . V_2 ,
V_118 , V_113 ) ;
if ( ( V_67 & 0x8 ) == 0 ) {
F_6 ( 0 , L_22 ,
V_67 ) ;
return - 1 ;
}
if ( V_67 == V_115 )
break;
}
if ( F_71 ( V_117 ) )
V_113 *= 3 ;
F_6 ( 3 , L_23 ,
V_111 ,
V_104 ,
F_28 ,
V_113 ,
V_122 ? L_24 : L_25 ) ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
V_116 [ V_84 ] = 0 ;
V_110 = 0 ;
for ( V_112 = 0 ;
V_112 < F_61 (
V_94 ) ;
V_112 ++ ) {
if ( F_60 ( V_27 ,
V_112 ,
V_84 ,
& V_109 ,
& V_108 ,
& V_114 ) )
break;
V_107 = ( V_108 + 1 ) -
( V_110 + V_109 ) ;
V_110 += V_107 ;
V_106 = ( V_108 + 1 ) - V_107 ;
if ( V_106 < V_104 ) {
if ( V_108 > V_104 )
F_6 ( 0 , L_26 ) ;
} else if ( V_106 < F_28 ) {
if ( V_108 + 1 > F_28 ) {
F_6 ( 0 , L_27 ) ;
} else {
F_6 ( 3 , L_28 ,
V_112 , V_106 ,
V_108 , V_107 ,
V_84 ) ;
V_116 [ V_84 ] += V_107 ;
}
}
V_106 = V_108 + 1 ;
}
}
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
F_6 ( 3 , L_29 ,
V_84 , V_116 [ V_84 ] , V_116 [ V_84 ] ) ;
}
if ( V_122 )
continue;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ )
V_127 [ V_98 ] = 0 ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ ) {
for ( V_126 = 0 ; V_126 < V_113 ; V_126 ++ ) {
int V_135 ;
int V_136 ;
if ( F_71 ( V_117 ) )
V_135 = V_126 ;
else
V_135 = 0x7 & F_2 (
V_27 -> V_36 . V_2 , V_118 , V_126 ) ;
for ( V_136 = 0 ; V_136 < V_120 ; V_136 ++ ) {
if ( F_64 ( V_135 ,
V_119 [ V_136 ] ) == V_98
&& ! V_127 [ V_98 ] ) {
V_128 ++ ;
V_127 [ V_98 ] = 1 ;
break;
}
}
}
}
if ( V_128 != V_113 )
F_6 ( 0 , L_30 ,
V_128 , V_113 ) ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ ) {
V_84 = F_62 ( V_98 ) ;
if ( V_127 [ V_98 ] ) {
F_6 ( 4 , L_31 ,
V_98 ,
V_116 [ V_84 ] / V_113 ,
V_111 ) ;
V_103 [ V_98 ] +=
V_116 [ V_84 ] / V_113 ;
}
}
}
return 0 ;
}
static int F_72 ( struct V_137 * V_138 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_140 * V_141 ;
unsigned V_102 , V_142 , V_143 , V_9 , V_15 , V_16 , V_144 ;
T_3 V_145 ;
T_1 V_4 ;
enum V_146 V_147 ;
enum V_33 V_34 ;
int V_148 = V_27 -> V_36 . type == V_13 ?
V_101 : V_149 ;
T_3 V_150 [ V_101 ] ;
if ( V_27 -> V_36 . type == V_11 || V_27 -> V_36 . type == V_12 ||
V_27 -> V_36 . type == V_13 )
F_21 ( V_27 -> V_28 , V_151 , & V_4 ) ;
else
F_21 ( V_27 -> V_53 , V_151 , & V_4 ) ;
if ( V_27 -> V_36 . type == V_13 )
V_27 -> V_17 -> V_152 = F_73 ( V_4 ) ;
else
V_27 -> V_17 -> V_152 = F_74 ( V_4 ) ;
V_27 -> V_17 -> V_153 = V_27 -> V_36 . F_45 ( V_27 ) ;
F_6 ( 0 , L_32 ,
V_27 -> V_17 -> V_84 ,
V_27 -> V_17 -> V_153 ,
V_27 -> V_17 -> V_152 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
V_147 = V_154 ;
V_27 -> V_155 = false ;
if ( F_68 ( V_27 , V_150 ) != 0 )
return - 1 ;
} else {
F_21 ( V_27 -> V_156 , V_157 , & V_4 ) ;
if ( F_75 ( V_4 ) ) {
F_6 ( 0 , L_33 ) ;
V_27 -> V_155 = true ;
} else {
F_6 ( 0 , L_34 ) ;
V_27 -> V_155 = false ;
}
F_21 ( V_27 -> V_44 , V_45 , & V_27 -> V_36 . V_72 ) ;
if ( F_76 ( V_27 -> V_36 . V_72 ) ) {
F_6 ( 0 , L_35 ) ;
V_147 = V_158 ;
V_27 -> V_159 = true ;
} else {
F_6 ( 0 , L_36 ) ;
V_147 = V_154 ;
V_27 -> V_159 = false ;
}
if ( F_77 ( V_27 -> V_36 . V_72 ) ) {
F_6 ( 0 , L_37 ) ;
V_27 -> V_160 = true ;
} else {
F_6 ( 0 , L_38 ) ;
V_27 -> V_160 = false ;
}
}
V_34 = V_27 -> V_36 . F_37 ( V_27 ) ;
if ( V_34 == V_38 || V_34 == V_46 )
F_6 ( 0 , L_39 ) ;
else if ( V_34 == V_40 )
F_6 ( 0 , L_40 ) ;
else
F_6 ( 0 , L_41 ) ;
if ( V_34 == V_47 || V_34 == V_46 )
V_143 = 16 ;
else
V_143 = 8 ;
for ( V_102 = 0 ; V_102 < V_148 ; V_102 ++ ) {
T_1 V_8 ;
int V_161 ;
if ( V_27 -> V_36 . type == V_13 ) {
V_161 = 1 ;
if ( ! V_27 -> V_60 . V_162 [ V_102 ] )
continue;
} else {
V_161 = F_61 ( V_163 ) ;
if ( ! V_27 -> V_164 [ V_102 ] )
continue;
}
for ( V_142 = 0 ; V_142 < V_161 ; V_142 ++ ) {
V_141 = F_78 ( V_138 -> V_165 , V_138 -> V_166 , V_138 -> V_167 ,
V_102 , V_142 , 0 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
F_21 ( V_27 -> V_60 . V_162 [ V_102 ] ,
V_168 , & V_8 ) ;
} else {
F_21 ( V_27 -> V_164 [ V_102 ] ,
V_163 [ V_142 ] , & V_8 ) ;
}
F_6 ( 4 , L_42 , V_102 , V_142 , V_8 ) ;
if ( F_79 ( V_8 ) ) {
V_27 -> V_98 [ V_102 ] . V_166 ++ ;
V_9 = F_4 ( V_27 -> V_36 . type , V_8 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
V_16 = 1 << 10 ;
V_15 = V_150 [ V_102 ] /
( ( T_3 ) V_16 * V_9 * V_143 * 8 ) ;
} else {
V_15 = F_7 ( V_8 ) ;
V_16 = F_9 ( V_8 ) ;
}
V_145 = ( ( T_3 ) V_15 * V_16 * V_143 * V_9 ) >> ( 20 - 3 ) ;
V_144 = F_80 ( V_145 ) ;
F_6 ( 0 , L_43 ,
V_27 -> V_17 -> V_84 , V_102 / 4 , V_102 % 4 , V_142 ,
V_145 , V_144 ,
V_143 , V_9 , V_15 , V_16 ) ;
V_141 -> V_169 = V_144 ;
V_141 -> V_170 = 32 ;
V_141 -> V_171 = V_27 -> V_36 . V_172 ( V_27 , V_8 ) ;
V_141 -> V_34 = V_34 ;
V_141 -> V_173 = V_147 ;
snprintf ( V_141 -> V_174 , sizeof( V_141 -> V_174 ) ,
L_44 ,
V_27 -> V_17 -> V_152 , V_102 / 4 , V_102 % 4 , V_142 ) ;
}
}
}
return 0 ;
}
static void F_81 ( const struct V_137 * V_138 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
int V_102 , V_142 , V_175 , V_176 , V_177 , V_178 ;
T_1 V_4 ;
T_3 V_86 , V_179 = 0 ;
T_3 V_180 ;
T_1 V_181 , V_182 ;
T_1 V_183 ;
V_27 -> V_184 = V_27 -> V_36 . V_185 ( V_27 ) ;
V_180 = ( 1 + V_27 -> V_184 ) >> 20 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_45 ,
V_181 , ( V_182 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_184 ) ;
V_27 -> V_186 = V_27 -> V_36 . V_187 ( V_27 ) ;
V_180 = ( 1 + V_27 -> V_186 ) >> 20 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_46 ,
V_181 , ( V_182 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_186 ) ;
V_179 = 0 ;
for ( V_176 = 0 ; V_176 < V_27 -> V_36 . V_132 ; V_176 ++ ) {
F_21 ( V_27 -> V_133 , V_27 -> V_36 . V_117 [ V_176 ] ,
& V_4 ) ;
V_86 = V_27 -> V_36 . F_28 ( V_4 ) ;
if ( ! F_69 ( V_4 ) )
continue;
if ( V_86 <= V_179 )
break;
V_180 = ( V_86 + 1 ) >> 20 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_47 ,
V_176 ,
F_1 ( V_27 -> V_36 . F_31 ( V_4 ) ) ,
V_181 , ( V_182 * 1000 ) / 1024 ,
( ( T_3 ) V_180 ) << 20L ,
V_27 -> V_36 . F_30 ( V_4 ) ,
V_4 ) ;
V_179 = V_86 ;
F_21 ( V_27 -> V_133 , V_27 -> V_36 . V_134 [ V_176 ] ,
& V_4 ) ;
V_178 = F_2 ( V_27 -> V_36 . V_2 , V_4 , 0 ) ;
for ( V_142 = 0 ; V_142 < 8 ; V_142 ++ ) {
T_1 V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_142 ) ;
if ( V_142 > 0 && V_178 == V_67 )
break;
F_6 ( 0 , L_48 ,
V_176 , V_142 , V_67 ) ;
}
}
if ( V_27 -> V_36 . type == V_13 )
return;
V_179 = 0 ;
for ( V_177 = 0 ; V_177 < V_188 ; V_177 ++ ) {
F_21 ( V_27 -> V_189 , V_190 [ V_177 ] ,
& V_4 ) ;
V_86 = F_83 ( V_4 ) ;
if ( V_86 <= V_179 )
break;
V_180 = ( V_86 + 1 ) >> 20 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_49 ,
V_177 , V_181 , ( V_182 * 1000 ) / 1024 ,
( ( T_3 ) V_180 ) << 20L ,
( T_1 ) F_84 ( V_4 ) ,
( T_1 ) F_85 ( V_4 ) ,
( T_1 ) F_86 ( V_4 ) ,
( T_1 ) F_87 ( V_4 ) ,
( T_1 ) F_88 ( V_4 ) ,
( T_1 ) F_89 ( V_4 ) ,
V_4 ) ;
V_179 = V_86 ;
}
for ( V_102 = 0 ; V_102 < V_149 ; V_102 ++ ) {
if ( ! V_27 -> V_98 [ V_102 ] . V_166 )
continue;
for ( V_142 = 0 ; V_142 < V_177 ; V_142 ++ ) {
F_21 ( V_27 -> V_164 [ V_102 ] ,
V_191 [ V_142 ] ,
& V_4 ) ;
V_180 = F_90 ( V_4 ) >> 20 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_50 ,
V_102 , V_142 ,
V_181 , ( V_182 * 1000 ) / 1024 ,
( ( T_3 ) V_180 ) << 20L ,
V_4 ) ;
}
}
for ( V_102 = 0 ; V_102 < V_149 ; V_102 ++ ) {
if ( ! V_27 -> V_98 [ V_102 ] . V_166 )
continue;
for ( V_142 = 0 ; V_142 < V_192 ; V_142 ++ ) {
F_21 ( V_27 -> V_164 [ V_102 ] ,
V_193 [ V_142 ] ,
& V_4 ) ;
if ( ! F_91 ( V_4 ) )
continue;
V_180 = V_27 -> V_36 . F_27 ( V_4 ) >> 20 ;
V_183 = 1 << F_92 ( V_4 ) ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_51 ,
V_102 , V_142 ,
V_181 , ( V_182 * 1000 ) / 1024 ,
( ( T_3 ) V_180 ) << 20L ,
V_183 ,
V_4 ) ;
for ( V_175 = 0 ; V_175 < V_183 ; V_175 ++ ) {
F_21 ( V_27 -> V_164 [ V_102 ] ,
V_194 [ V_142 ] [ V_175 ] ,
& V_4 ) ;
V_180 = F_93 ( V_4 ) << 6 ;
V_181 = F_82 ( V_180 , 1024 , & V_182 ) ;
F_6 ( 0 , L_52 ,
V_102 , V_142 , V_175 ,
V_181 , ( V_182 * 1000 ) / 1024 ,
( ( T_3 ) V_180 ) << 20L ,
( T_1 ) F_94 ( V_4 ) ,
V_4 ) ;
}
}
}
}
static struct V_137 * F_95 ( T_2 V_153 )
{
struct V_17 * V_17 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_17 -> V_153 == V_153 )
return V_17 -> V_138 ;
}
return NULL ;
}
static int F_96 ( struct V_137 * V_138 ,
T_3 V_195 ,
T_2 * V_196 , T_2 * V_197 ,
long * V_198 ,
T_2 * V_199 ,
char * * V_200 , char * V_201 )
{
struct V_137 * V_202 ;
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_203 ;
int V_204 , V_176 , V_177 , V_205 , V_206 ;
int V_178 , V_207 , V_208 ;
int F_29 , V_209 = 0 ;
unsigned V_210 [ V_27 -> V_36 . V_211 ] ;
T_1 V_4 , V_117 ;
T_2 V_212 , V_213 , V_67 , V_214 = 0 , V_215 = 0 ;
T_1 V_216 ;
T_1 V_183 ;
T_1 V_182 , V_181 ;
T_3 V_217 , V_85 , V_86 = 0 , V_179 = 0 ;
if ( ( V_195 > ( T_3 ) V_27 -> V_184 ) && ( V_195 < ( 1LL << 32 ) ) ) {
sprintf ( V_201 , L_53 , V_195 ) ;
return - V_14 ;
}
if ( V_195 >= ( T_3 ) V_27 -> V_186 ) {
sprintf ( V_201 , L_54 , V_195 ) ;
return - V_14 ;
}
for ( V_176 = 0 ; V_176 < V_27 -> V_36 . V_132 ; V_176 ++ ) {
F_21 ( V_27 -> V_133 , V_27 -> V_36 . V_117 [ V_176 ] ,
& V_4 ) ;
if ( ! F_69 ( V_4 ) )
continue;
V_86 = V_27 -> V_36 . F_28 ( V_4 ) ;
if ( V_86 <= V_179 ) {
sprintf ( V_201 , L_55 ) ;
return - V_14 ;
}
if ( V_195 <= V_86 )
break;
V_179 = V_86 ;
}
if ( V_176 == V_27 -> V_36 . V_132 ) {
sprintf ( V_201 , L_55 ) ;
return - V_14 ;
}
V_117 = V_4 ;
* V_200 = F_1 ( V_27 -> V_36 . F_31 ( V_117 ) ) ;
F_29 = V_27 -> V_36 . F_29 ( V_117 ) ;
F_21 ( V_27 -> V_133 , V_27 -> V_36 . V_134 [ V_176 ] ,
& V_4 ) ;
if ( V_27 -> V_36 . type == V_76 ) {
V_178 = F_2 ( V_27 -> V_36 . V_2 , V_4 , 0 ) ;
for ( V_205 = 0 ; V_205 < 8 ; V_205 ++ ) {
T_1 V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_205 ) ;
if ( V_205 > 0 && V_178 == V_67 )
break;
V_210 [ V_205 ] = V_67 ;
F_6 ( 0 , L_56 ,
V_205 , V_210 [ V_205 ] ) ;
}
F_6 ( 0 , L_57 ,
V_27 -> V_17 -> V_84 ,
V_176 ,
V_195 ,
V_86 ,
V_205 + 7 ,
! F_29 ? L_25 : L_58 ) ;
if ( F_29 )
V_207 = ( ( V_195 >> 6 ) ^ ( V_195 >> 16 ) ) & 7 ;
else
V_207 = ( V_195 >> 6 ) & 7 ;
switch ( V_205 ) {
case 1 :
V_207 = 0 ;
break;
case 2 :
V_207 = V_207 & 1 ;
break;
case 4 :
V_207 = V_207 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_201 , L_59 ) ;
return - V_14 ;
}
* V_196 = V_210 [ V_207 ] ;
F_6 ( 0 , L_60 ,
V_207 , V_205 , * V_196 ) ;
} else if ( V_27 -> V_36 . type == V_11 || V_27 -> V_36 . type == V_12 ) {
int V_218 , V_219 = F_97 ( V_117 ) ;
if ( V_219 ) {
V_218 = F_3 ( V_195 , 7 , 8 ) << 1 ;
V_218 |= F_3 ( V_195 , 9 , 9 ) ;
} else
V_218 = F_3 ( V_195 , 6 , 8 ) ;
if ( F_29 == 0 ) {
V_207 = F_3 ( V_195 , 16 , 18 ) ;
V_207 ^= V_218 ;
} else
V_207 = V_218 ;
V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_207 ) ;
* V_196 = F_53 ( V_67 ) ;
V_214 = F_54 ( V_67 ) ;
if ( V_214 )
V_215 = 4 ;
if ( V_219 ) {
F_21 ( V_27 -> V_189 ,
V_220 , & V_4 ) ;
V_209 = F_3 ( V_4 , 22 , 22 ) ;
}
F_6 ( 0 , L_61 ,
V_207 , * V_196 , V_214 , V_209 ) ;
} else {
V_207 = ( V_195 >> 6 ) & 7 ;
V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_207 ) ;
* V_196 = F_53 ( V_67 ) ;
V_214 = F_54 ( V_67 ) ;
if ( V_214 )
V_215 = 4 ;
F_6 ( 0 , L_62 ,
V_207 , * V_196 , V_214 ) ;
}
* V_197 = V_214 ;
V_202 = F_95 ( * V_196 ) ;
if ( ! V_202 ) {
sprintf ( V_201 , L_63 ,
* V_196 ) ;
return - V_14 ;
}
V_138 = V_202 ;
V_27 = V_138 -> V_139 ;
V_179 = 0 ;
if ( V_27 -> V_36 . type == V_76 )
V_203 = V_27 -> V_189 ;
else {
if ( V_214 )
V_203 = V_27 -> V_221 ;
else
V_203 = V_27 -> V_189 ;
}
for ( V_177 = 0 ; V_177 < V_188 ; V_177 ++ ) {
F_21 ( V_203 , V_190 [ V_177 ] , & V_4 ) ;
V_86 = F_83 ( V_4 ) ;
if ( V_86 <= V_179 ) {
sprintf ( V_201 , L_64 ) ;
return - V_14 ;
}
if ( V_195 <= V_86 )
break;
V_179 = V_86 ;
}
if ( V_177 == V_188 ) {
sprintf ( V_201 , L_64 ) ;
return - V_14 ;
}
V_212 = F_85 ( V_4 ) + 1 ;
V_213 = F_84 ( V_4 ) + 1 ;
if ( V_212 == 3 )
V_207 = V_195 >> 6 ;
else
V_207 = ( V_195 >> ( 6 + V_213 + V_209 ) ) & 0x3 ;
V_207 = V_207 % V_212 ;
switch ( V_207 ) {
case 0 :
V_208 = F_86 ( V_4 ) ;
break;
case 1 :
V_208 = F_87 ( V_4 ) ;
break;
case 2 :
V_208 = F_88 ( V_4 ) ;
break;
case 3 :
V_208 = F_89 ( V_4 ) ;
break;
default:
sprintf ( V_201 , L_65 ) ;
return - V_14 ;
}
* V_198 = 1 << V_208 ;
F_21 ( V_27 -> V_164 [ V_215 + V_208 ] ,
V_191 [ V_177 ] ,
& V_216 ) ;
if ( V_27 -> V_155 ) {
* V_198 |= 1 << ( ( V_208 + 2 ) % 4 ) ;
switch( V_212 ) {
case 2 :
case 4 :
V_206 = 1 << V_213 * ( V_212 >> 1 ) ;
break;
default:
sprintf ( V_201 , L_66 ) ;
return - V_14 ;
}
} else
V_206 = ( 1 << V_213 ) * V_212 ;
if ( V_27 -> V_159 )
* V_198 |= 1 << ( ( V_208 + 1 ) % 4 ) ;
V_85 = F_90 ( V_216 ) ;
F_6 ( 0 , L_67 ,
V_177 ,
V_195 ,
V_86 ,
( T_1 ) F_84 ( V_4 ) ,
V_212 ,
V_85 ,
V_207 ,
V_208 ,
* V_198 ) ;
if ( V_85 > V_195 ) {
sprintf ( V_201 , L_68 ,
V_85 , V_195 ) ;
return - V_14 ;
}
V_195 -= V_85 ;
V_217 = V_195 & 0x7f ;
V_195 >>= 6 ;
V_195 = F_98 ( V_195 , V_206 ) ;
#if 0
addr = addr / ch_way;
#endif
V_217 |= V_195 << 6 ;
for ( V_204 = 0 ; V_204 < V_192 ; V_204 ++ ) {
F_21 ( V_27 -> V_164 [ V_215 + V_208 ] ,
V_193 [ V_204 ] ,
& V_4 ) ;
if ( ! F_91 ( V_4 ) )
continue;
V_86 = V_27 -> V_36 . F_27 ( V_4 ) ;
V_181 = F_82 ( V_86 >> 20 , 1024 , & V_182 ) ;
F_6 ( 0 , L_69 ,
V_204 ,
V_181 , ( V_182 * 1000 ) / 1024 ,
V_86 ,
1 << F_92 ( V_4 ) ) ;
if ( V_217 <= V_86 )
break;
}
if ( V_204 == V_192 ) {
sprintf ( V_201 , L_70 ,
V_217 ) ;
return - V_14 ;
}
V_183 = F_92 ( V_4 ) ;
if ( V_27 -> V_160 )
V_207 = ( V_217 >> 6 ) ;
else
V_207 = ( V_217 >> 13 ) ;
V_207 %= 1 << V_183 ;
F_21 ( V_27 -> V_164 [ V_215 + V_208 ] ,
V_194 [ V_204 ] [ V_207 ] ,
& V_4 ) ;
* V_199 = F_94 ( V_4 ) ;
F_6 ( 0 , L_71 ,
V_204 ,
V_217 ,
V_86 ,
V_183 ,
V_207 ) ;
return 0 ;
}
static void F_99 ( struct V_17 * V_17 )
{
int V_102 ;
F_6 ( 0 , L_72 ) ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
struct V_68 * V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
F_6 ( 0 , L_73 ,
V_24 -> V_18 -> V_71 ,
F_100 ( V_24 -> V_222 ) , F_101 ( V_24 -> V_222 ) ) ;
F_102 ( V_24 ) ;
}
}
static void F_103 ( void )
{
struct V_17 * V_17 , * V_223 ;
F_104 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_99 ( V_17 ) ;
F_18 ( V_17 ) ;
}
}
static int F_105 ( struct V_68 * * V_224 ,
T_2 * V_225 ,
const struct V_22 * V_3 ,
const unsigned V_226 ,
const int V_19 )
{
struct V_17 * V_17 ;
const struct V_227 * V_228 = & V_3 -> V_229 [ V_226 ] ;
struct V_68 * V_24 = NULL ;
T_2 V_18 = 0 ;
F_58 ( V_230 ,
L_74 ,
V_70 , V_228 -> V_231 ) ;
V_24 = F_56 ( V_70 ,
V_228 -> V_231 , * V_224 ) ;
if ( ! V_24 ) {
if ( * V_224 ) {
* V_224 = V_24 ;
return 0 ;
}
if ( V_228 -> V_232 )
return 0 ;
if ( V_226 == 0 )
return - V_80 ;
F_58 ( V_233 ,
L_75 ,
V_70 , V_228 -> V_231 ) ;
return - V_80 ;
}
V_18 = V_24 -> V_18 -> V_71 ;
V_17 = F_11 ( V_18 , V_19 ) ;
if ( ! V_17 ) {
V_17 = F_14 ( V_18 , V_3 ) ;
if ( ! V_17 ) {
F_102 ( V_24 ) ;
return - V_234 ;
}
( * V_225 ) ++ ;
}
if ( V_17 -> V_24 [ V_226 ] ) {
F_58 ( V_81 ,
L_76 ,
V_70 , V_228 -> V_231 ) ;
F_102 ( V_24 ) ;
return - V_80 ;
}
V_17 -> V_24 [ V_226 ] = V_24 ;
if ( F_106 ( F_107 ( V_24 ) < 0 ) ) {
F_58 ( V_81 ,
L_77 ,
V_70 , V_228 -> V_231 ) ;
return - V_80 ;
}
F_6 ( 0 , L_78 ,
V_70 , V_228 -> V_231 ) ;
F_108 ( V_24 ) ;
* V_224 = V_24 ;
return 0 ;
}
static int F_109 ( T_2 * V_225 ,
const struct V_22 * V_3 ,
int V_235 ,
int V_19 )
{
int V_102 , V_57 ;
struct V_68 * V_24 = NULL ;
while ( V_3 && V_3 -> V_229 ) {
for ( V_102 = 0 ; V_102 < V_3 -> V_25 ; V_102 ++ ) {
if ( ! V_235 || V_102 == 0 ||
V_3 -> V_229 [ V_102 ] . V_231 !=
V_3 -> V_229 [ V_102 - 1 ] . V_231 ) {
V_24 = NULL ;
}
do {
V_57 = F_105 ( & V_24 , V_225 ,
V_3 , V_102 , V_19 ) ;
if ( V_57 < 0 ) {
if ( V_102 == 0 ) {
V_102 = V_3 -> V_25 ;
break;
}
F_103 () ;
return - V_80 ;
}
} while ( V_24 && ! V_235 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_110 ( struct V_137 * V_138 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_24 ;
T_2 V_236 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_237 ) {
case V_238 :
V_27 -> V_133 = V_24 ;
break;
case V_239 :
V_27 -> V_28 = V_24 ;
break;
case V_240 :
V_27 -> V_53 = V_24 ;
break;
case V_241 :
V_27 -> V_189 = V_24 ;
break;
case V_77 :
V_27 -> V_44 = V_24 ;
break;
case V_242 :
V_27 -> V_156 = V_24 ;
break;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
{
int V_69 = V_24 -> V_237 - V_243 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_247 :
V_27 -> V_35 = V_24 ;
break;
default:
goto error;
}
F_6 ( 0 , L_79 ,
V_24 -> V_248 , V_24 -> V_237 ,
V_17 -> V_18 ,
V_24 ) ;
}
if ( ! V_27 -> V_133 || ! V_27 -> V_28 || ! V_27 -> V_189 ||
! V_27 -> V_164 || ! V_27 -> V_156 || ! V_27 -> V_44 )
goto V_249;
if ( V_236 != 0x0f )
goto V_249;
return 0 ;
V_249:
F_58 ( V_81 , L_80 ) ;
return - V_80 ;
error:
F_58 ( V_81 , L_81 ,
V_70 , V_24 -> V_237 ) ;
return - V_14 ;
}
static int F_111 ( struct V_137 * V_138 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_24 ;
T_2 V_236 = 0 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_237 ) {
case V_250 :
V_27 -> V_189 = V_24 ;
break;
case V_74 :
V_27 -> V_44 = V_24 ;
case V_251 :
V_27 -> V_156 = V_24 ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
{
int V_69 = V_24 -> V_237 - V_252 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_256 :
V_27 -> V_35 = V_24 ;
break;
case V_257 :
V_27 -> V_35 = V_24 ;
break;
case V_258 :
V_27 -> V_133 = V_24 ;
break;
case V_259 :
V_27 -> V_53 = V_24 ;
break;
case V_260 :
V_27 -> V_31 = V_24 ;
break;
case V_261 :
V_27 -> V_221 = V_24 ;
break;
case V_262 :
case V_263 :
case V_264 :
case V_265 :
{
int V_69 = V_24 -> V_237 - V_262 + 4 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
default:
goto error;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_222 ) , F_101 ( V_24 -> V_222 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_133 || ! V_27 -> V_189 || ! V_27 -> V_53 ||
! V_27 -> V_31 || ! V_27 -> V_164 || ! V_27 -> V_156 ||
! V_27 -> V_44 )
goto V_249;
if ( V_236 != 0x0f &&
V_236 != 0x33 &&
V_236 != 0xff )
goto V_249;
return 0 ;
V_249:
F_58 ( V_81 , L_80 ) ;
return - V_80 ;
error:
F_58 ( V_81 ,
L_81 , V_70 ,
V_24 -> V_237 ) ;
return - V_14 ;
}
static int F_112 ( struct V_137 * V_138 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_24 ;
T_2 V_236 = 0 ;
int V_102 ;
if ( V_27 -> V_36 . V_55 == NULL )
V_27 -> V_36 . V_55 = F_56 ( V_70 ,
V_266 ,
NULL ) ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_237 ) {
case V_267 :
V_27 -> V_133 = V_24 ;
break;
case V_268 :
V_27 -> V_28 = V_24 ;
break;
case V_269 :
V_27 -> V_189 = V_24 ;
break;
case V_75 :
V_27 -> V_44 = V_24 ;
break;
case V_270 :
V_27 -> V_156 = V_24 ;
break;
case V_271 :
case V_272 :
case V_273 :
case V_274 :
{
int V_69 = V_24 -> V_237 - V_271 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
{
int V_69 = V_24 -> V_237 - V_275 + 4 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
if ( ! V_27 -> V_35 )
V_27 -> V_35 = V_24 ;
break;
case V_283 :
V_27 -> V_221 = V_24 ;
break;
case V_284 :
V_27 -> V_285 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_222 ) , F_101 ( V_24 -> V_222 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_133 || ! V_27 -> V_189 || ! V_27 -> V_28 ||
! V_27 -> V_156 || ! V_27 -> V_44 || ! V_27 -> V_36 . V_55 )
goto V_249;
if ( V_236 != 0x0f &&
V_236 != 0x33 &&
V_236 != 0xff )
goto V_249;
return 0 ;
V_249:
F_58 ( V_81 , L_80 ) ;
return - V_80 ;
}
static int F_113 ( struct V_137 * V_138 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_24 ;
T_2 V_236 = 0 ;
int V_102 ;
if ( V_27 -> V_36 . V_55 == NULL )
V_27 -> V_36 . V_55 = F_56 ( V_70 ,
V_286 ,
NULL ) ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_237 ) {
case V_287 :
V_27 -> V_133 = V_24 ;
break;
case V_288 :
V_27 -> V_28 = V_24 ;
break;
case V_289 :
V_27 -> V_189 = V_24 ;
break;
case V_78 :
V_27 -> V_44 = V_24 ;
break;
case V_290 :
V_27 -> V_156 = V_24 ;
break;
case V_291 :
case V_292 :
case V_293 :
case V_294 :
{
int V_69 = V_24 -> V_237 - V_291 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
{
int V_69 = V_24 -> V_237 - V_295 + 4 ;
V_27 -> V_164 [ V_69 ] = V_24 ;
V_236 |= 1 << V_69 ;
}
break;
case V_299 :
V_27 -> V_35 = V_24 ;
break;
case V_300 :
V_27 -> V_221 = V_24 ;
break;
case V_301 :
V_27 -> V_285 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_222 ) , F_101 ( V_24 -> V_222 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_133 || ! V_27 -> V_189 || ! V_27 -> V_28 ||
! V_27 -> V_156 || ! V_27 -> V_44 || ! V_27 -> V_36 . V_55 )
goto V_249;
if ( V_236 != 0x0f &&
V_236 != 0x33 &&
V_236 != 0xff )
goto V_249;
return 0 ;
V_249:
F_58 ( V_81 , L_80 ) ;
return - V_80 ;
}
static int F_114 ( struct V_137 * V_138 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
struct V_68 * V_24 ;
int V_302 , V_303 ;
int V_102 ;
int V_304 ;
for ( V_102 = 0 ; V_102 < V_17 -> V_25 ; V_102 ++ ) {
V_24 = V_17 -> V_24 [ V_102 ] ;
if ( ! V_24 )
continue;
V_302 = ( V_24 -> V_222 >> 3 ) & 0x1f ;
V_303 = V_24 -> V_222 & 0x7 ;
switch ( V_24 -> V_237 ) {
case V_305 :
if ( V_302 == 8 )
V_27 -> V_60 . V_92 = V_24 ;
else if ( V_302 == 9 )
V_27 -> V_60 . V_93 = V_24 ;
else {
F_58 ( V_81 ,
L_83 ,
V_302 , V_303 ) ;
continue;
}
break;
case V_306 :
V_27 -> V_133 = V_24 ;
break;
case V_307 :
V_27 -> V_28 = V_24 ;
break;
case V_308 :
V_304 = ( ( V_302 - 14 ) * 8 ) + V_303 ;
if ( V_304 < 0 || V_304 >= V_120 ) {
F_58 ( V_81 ,
L_84 ,
V_302 , V_303 ) ;
continue;
}
F_35 ( V_27 -> V_60 . V_129 [ V_304 ] != NULL ) ;
V_27 -> V_60 . V_129 [ V_304 ] = V_24 ;
break;
case V_309 :
V_304 = - 1 ;
if ( V_302 == 9 )
V_304 = V_303 - 2 ;
else if ( V_302 == 8 )
V_304 = 3 + ( V_303 - 2 ) ;
if ( V_304 < 0 || V_304 >= V_101 ) {
F_58 ( V_81 ,
L_85 ,
V_302 , V_303 ) ;
continue;
}
F_35 ( V_27 -> V_60 . V_162 [ V_304 ] != NULL ) ;
V_27 -> V_60 . V_162 [ V_304 ] = V_24 ;
break;
case V_310 :
V_27 -> V_60 . V_61 = V_24 ;
break;
case V_79 :
V_27 -> V_44 = V_24 ;
break;
default:
F_58 ( V_81 , L_86 ,
V_24 -> V_237 ) ;
break;
}
}
if ( ! V_27 -> V_60 . V_92 || ! V_27 -> V_60 . V_93 ||
! V_27 -> V_133 || ! V_27 -> V_28 ||
! V_27 -> V_44 ) {
goto V_249;
}
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ ) {
if ( ! V_27 -> V_60 . V_162 [ V_102 ] ) {
F_58 ( V_81 , L_87 , V_102 ) ;
goto V_249;
}
}
for ( V_102 = 0 ; V_102 < V_120 ; V_102 ++ ) {
if ( ! V_27 -> V_60 . V_129 [ V_102 ] ) {
F_58 ( V_81 , L_88 , V_102 ) ;
goto V_249;
}
}
return 0 ;
V_249:
F_58 ( V_81 , L_80 ) ;
return - V_80 ;
}
static void F_115 ( struct V_137 * V_138 ,
const struct V_311 * V_312 )
{
struct V_137 * V_202 ;
struct V_26 * V_27 = V_138 -> V_139 ;
enum V_313 V_314 ;
char * type , * V_315 , V_201 [ 256 ] ;
bool V_316 = F_3 ( V_312 -> V_317 , 0 , 0 ) ;
bool V_318 = F_3 ( V_312 -> V_319 , 62 , 62 ) ;
bool V_320 = F_3 ( V_312 -> V_319 , 61 , 61 ) ;
bool V_321 ;
T_1 V_322 = F_3 ( V_312 -> V_319 , 38 , 52 ) ;
T_1 V_323 = F_3 ( V_312 -> V_319 , 16 , 31 ) ;
T_1 V_324 = F_3 ( V_312 -> V_319 , 0 , 15 ) ;
T_1 V_98 = F_3 ( V_312 -> V_319 , 0 , 3 ) ;
T_1 V_325 = F_3 ( V_312 -> V_319 , 4 , 6 ) ;
long V_198 , V_326 ;
T_2 V_199 , V_196 , V_197 ;
int V_57 , V_141 ;
char * V_200 = NULL ;
if ( V_27 -> V_36 . type != V_76 )
V_321 = true ;
else
V_321 = F_3 ( V_312 -> V_319 , 56 , 56 ) ;
if ( V_320 ) {
if ( V_316 ) {
type = L_89 ;
V_314 = V_327 ;
} else {
type = L_90 ;
V_314 = V_328 ;
}
} else {
type = L_91 ;
V_314 = V_329 ;
}
if ( ! ( ( V_324 & 0xef80 ) == 0x80 ) ) {
V_315 = L_92 ;
} else {
switch ( V_325 ) {
case 0 :
V_315 = L_93 ;
break;
case 1 :
V_315 = L_94 ;
break;
case 2 :
V_315 = L_95 ;
break;
case 3 :
V_315 = L_96 ;
break;
case 4 :
V_315 = L_97 ;
break;
default:
V_315 = L_98 ;
break;
}
}
if ( ! F_3 ( V_312 -> V_319 , 58 , 58 ) )
return;
if ( V_27 -> V_36 . type == V_13 ) {
if ( V_98 == 14 ) {
F_6 ( 0 , L_99 ,
V_318 ? L_100 : L_25 ,
( V_320 && V_321 )
? L_101 : L_25 ,
V_323 , V_324 ,
V_312 -> V_330 ) ;
} else {
char V_331 = * ( L_102 ) ;
V_98 = F_65 ( V_98 ) ;
V_198 = 1 << V_98 ;
snprintf ( V_201 , sizeof( V_201 ) ,
L_103 ,
V_318 ? L_100 : L_25 ,
( V_320 && V_321 )
? L_101 : L_104 ,
V_323 , V_324 , V_98 , V_331 + V_98 ) ;
F_116 ( V_314 , V_138 , V_322 ,
V_312 -> V_195 >> V_332 , V_312 -> V_195 & ~ V_333 , 0 ,
V_98 , 0 , - 1 ,
V_315 , V_201 ) ;
}
return;
} else {
V_57 = F_96 ( V_138 , V_312 -> V_195 , & V_196 , & V_197 ,
& V_198 , & V_199 , & V_200 , V_201 ) ;
}
if ( V_57 < 0 )
goto V_334;
V_202 = F_95 ( V_196 ) ;
if ( ! V_202 ) {
strcpy ( V_201 , L_105 ) ;
goto V_334;
}
V_138 = V_202 ;
V_27 = V_138 -> V_139 ;
V_326 = F_117 ( & V_198 , V_149 ) ;
if ( V_199 < 4 )
V_141 = 0 ;
else if ( V_199 < 8 )
V_141 = 1 ;
else
V_141 = 2 ;
if ( ! V_27 -> V_159 && ! V_27 -> V_155 && ! V_27 -> V_160 )
V_98 = V_326 ;
snprintf ( V_201 , sizeof( V_201 ) ,
L_106 ,
V_318 ? L_100 : L_25 ,
( V_320 && V_321 ) ? L_101 : L_25 ,
V_200 ,
V_323 , V_324 ,
V_196 , V_197 ,
V_198 ,
V_199 ) ;
F_6 ( 0 , L_107 , V_201 ) ;
if ( V_98 == V_335 )
V_98 = - 1 ;
F_116 ( V_314 , V_138 , V_322 ,
V_312 -> V_195 >> V_332 , V_312 -> V_195 & ~ V_333 , 0 ,
4 * V_197 + V_98 , V_141 , - 1 ,
V_315 , V_201 ) ;
return;
V_334:
F_116 ( V_314 , V_138 , V_322 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_201 , L_25 ) ;
}
static void F_118 ( struct V_137 * V_138 )
{
struct V_26 * V_27 = V_138 -> V_139 ;
int V_102 ;
unsigned V_336 = 0 ;
struct V_311 * V_312 ;
F_119 () ;
V_336 = ( V_27 -> V_337 + V_338 - V_27 -> V_339 )
% V_338 ;
if ( ! V_336 )
return;
V_312 = V_27 -> V_340 ;
if ( V_27 -> V_339 + V_336 > V_338 ) {
unsigned V_341 = V_338 - V_27 -> V_339 ;
memcpy ( V_312 , & V_27 -> V_342 [ V_27 -> V_339 ] , sizeof( * V_312 ) * V_341 ) ;
F_120 () ;
V_27 -> V_339 = 0 ;
V_336 -= V_341 ;
V_312 += V_341 ;
}
memcpy ( V_312 , & V_27 -> V_342 [ V_27 -> V_339 ] , sizeof( * V_312 ) * V_336 ) ;
F_120 () ;
V_27 -> V_339 += V_336 ;
F_119 () ;
if ( V_27 -> V_343 ) {
F_58 ( V_81 , L_108 ,
V_27 -> V_343 ) ;
F_120 () ;
V_27 -> V_343 = 0 ;
}
for ( V_102 = 0 ; V_102 < V_336 ; V_102 ++ )
F_115 ( V_138 , & V_27 -> V_340 [ V_102 ] ) ;
}
static int F_121 ( struct V_344 * V_345 , unsigned long V_346 ,
void * V_347 )
{
struct V_311 * V_311 = (struct V_311 * ) V_347 ;
struct V_137 * V_138 ;
struct V_26 * V_27 ;
char * type ;
if ( F_122 () == V_348 )
return V_349 ;
V_138 = F_95 ( V_311 -> V_350 ) ;
if ( ! V_138 )
return V_351 ;
V_27 = V_138 -> V_139 ;
if ( ( V_311 -> V_319 & 0xefff ) >> 7 != 1 )
return V_349 ;
if ( V_311 -> V_317 & V_352 )
type = L_109 ;
else
type = L_110 ;
F_123 ( V_138 , V_230 , L_111 ) ;
F_123 ( V_138 , V_230 , L_112
L_113 , V_311 -> V_353 , type ,
V_311 -> V_317 , V_311 -> V_330 , V_311 -> V_319 ) ;
F_123 ( V_138 , V_230 , L_114 , V_311 -> V_354 ) ;
F_123 ( V_138 , V_230 , L_115 , V_311 -> V_195 ) ;
F_123 ( V_138 , V_230 , L_116 , V_311 -> V_355 ) ;
F_123 ( V_138 , V_230 , L_117
L_118 , V_311 -> V_356 , V_311 -> V_357 ,
V_311 -> time , V_311 -> V_350 , V_311 -> V_358 ) ;
F_119 () ;
if ( ( V_27 -> V_337 + 1 ) % V_338 == V_27 -> V_339 ) {
F_120 () ;
V_27 -> V_343 ++ ;
return V_349 ;
}
memcpy ( & V_27 -> V_342 [ V_27 -> V_337 ] , V_311 , sizeof( * V_311 ) ) ;
F_120 () ;
V_27 -> V_337 = ( V_27 -> V_337 + 1 ) % V_338 ;
if ( V_311 -> V_317 & 1 )
F_118 ( V_138 ) ;
return V_359 ;
}
static void F_124 ( struct V_17 * V_17 )
{
struct V_137 * V_138 = V_17 -> V_138 ;
struct V_26 * V_27 ;
if ( F_106 ( ! V_138 || ! V_138 -> V_139 ) ) {
F_6 ( 0 , L_119 , & V_17 -> V_24 [ 0 ] -> V_302 ) ;
F_58 ( V_81 , L_120 ) ;
return;
}
V_27 = V_138 -> V_139 ;
F_6 ( 0 , L_121 ,
V_138 , & V_17 -> V_24 [ 0 ] -> V_302 ) ;
F_125 ( V_138 -> V_24 ) ;
F_6 ( 1 , L_122 , V_138 -> V_360 ) ;
F_16 ( V_138 -> V_360 ) ;
F_126 ( V_138 ) ;
V_17 -> V_138 = NULL ;
}
static int F_127 ( struct V_17 * V_17 , enum type type )
{
struct V_137 * V_138 ;
struct V_361 V_165 [ 2 ] ;
struct V_26 * V_27 ;
struct V_68 * V_24 = V_17 -> V_24 [ 0 ] ;
int V_57 ;
V_57 = F_57 ( V_17 -> V_18 , type ) ;
if ( F_106 ( V_57 < 0 ) )
return V_57 ;
V_165 [ 0 ] . type = V_362 ;
V_165 [ 0 ] . V_145 = type == V_13 ?
V_101 : V_149 ;
V_165 [ 0 ] . V_363 = false ;
V_165 [ 1 ] . type = V_364 ;
V_165 [ 1 ] . V_145 = type == V_13 ? 1 : V_365 ;
V_165 [ 1 ] . V_363 = true ;
V_138 = F_128 ( V_17 -> V_84 , F_61 ( V_165 ) , V_165 ,
sizeof( * V_27 ) ) ;
if ( F_106 ( ! V_138 ) )
return - V_234 ;
F_6 ( 0 , L_121 ,
V_138 , & V_24 -> V_302 ) ;
V_27 = V_138 -> V_139 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_17 = V_17 ;
V_17 -> V_138 = V_138 ;
V_138 -> V_366 = type == V_13 ?
V_367 : V_368 ;
V_138 -> V_369 = V_370 ;
V_138 -> V_371 = V_370 ;
V_138 -> V_372 = L_123 ;
V_138 -> V_373 = V_374 ;
V_138 -> V_375 = F_129 ( V_24 ) ;
V_138 -> V_376 = NULL ;
V_138 -> V_377 = F_118 ;
V_27 -> V_36 . type = type ;
switch ( type ) {
case V_73 :
V_27 -> V_36 . V_37 = V_378 ;
V_27 -> V_36 . V_185 = F_25 ;
V_27 -> V_36 . V_187 = F_26 ;
V_27 -> V_36 . V_117 = V_379 ;
V_27 -> V_36 . F_37 = F_37 ;
V_27 -> V_36 . F_45 = F_45 ;
V_27 -> V_36 . F_27 = F_27 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_132 = F_61 ( V_379 ) ;
V_27 -> V_36 . V_134 = V_380 ;
V_27 -> V_36 . V_211 = F_61 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_172 = F_42 ;
V_138 -> V_360 = F_130 ( V_23 , L_124 , V_138 -> V_382 ) ;
V_57 = F_111 ( V_138 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_76 :
V_27 -> V_36 . V_37 = V_384 ;
V_27 -> V_36 . V_185 = F_20 ;
V_27 -> V_36 . V_187 = F_23 ;
V_27 -> V_36 . V_117 = V_385 ;
V_27 -> V_36 . F_37 = F_37 ;
V_27 -> V_36 . F_45 = F_45 ;
V_27 -> V_36 . F_27 = F_27 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_132 = F_61 ( V_385 ) ;
V_27 -> V_36 . V_134 = V_386 ;
V_27 -> V_36 . V_211 = F_61 ( V_386 ) ;
V_27 -> V_36 . V_2 = V_387 ;
V_27 -> V_36 . V_172 = F_40 ;
V_138 -> V_360 = F_130 ( V_23 , L_125 , V_138 -> V_382 ) ;
V_57 = F_110 ( V_138 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_11 :
V_27 -> V_36 . V_185 = F_48 ;
V_27 -> V_36 . V_187 = F_49 ;
V_27 -> V_36 . V_117 = V_379 ;
V_27 -> V_36 . F_37 = F_38 ;
V_27 -> V_36 . F_45 = F_46 ;
V_27 -> V_36 . F_27 = F_52 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_132 = F_61 ( V_379 ) ;
V_27 -> V_36 . V_134 = V_380 ;
V_27 -> V_36 . V_211 = F_61 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_172 = F_42 ;
V_138 -> V_360 = F_130 ( V_23 , L_126 , V_138 -> V_382 ) ;
V_57 = F_112 ( V_138 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_12 :
V_27 -> V_36 . V_185 = F_48 ;
V_27 -> V_36 . V_187 = F_49 ;
V_27 -> V_36 . V_117 = V_379 ;
V_27 -> V_36 . F_37 = F_38 ;
V_27 -> V_36 . F_45 = F_46 ;
V_27 -> V_36 . F_27 = F_52 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_132 = F_61 ( V_379 ) ;
V_27 -> V_36 . V_134 = V_380 ;
V_27 -> V_36 . V_211 = F_61 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_172 = F_43 ;
V_138 -> V_360 = F_130 ( V_23 , L_127 , V_138 -> V_382 ) ;
V_57 = F_113 ( V_138 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_13 :
V_27 -> V_36 . V_185 = F_50 ;
V_27 -> V_36 . V_187 = F_51 ;
V_27 -> V_36 . V_117 = V_388 ;
V_27 -> V_36 . F_37 = F_44 ;
V_27 -> V_36 . F_45 = F_47 ;
V_27 -> V_36 . F_27 = NULL ;
V_27 -> V_36 . F_28 = F_32 ;
V_27 -> V_36 . F_29 = F_33 ;
V_27 -> V_36 . F_30 = F_34 ;
V_27 -> V_36 . F_31 = F_36 ;
V_27 -> V_36 . V_132 = F_61 ( V_388 ) ;
V_27 -> V_36 . V_134 = V_389 ;
V_27 -> V_36 . V_211 = F_61 ( V_389 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_172 = F_39 ;
V_138 -> V_360 = F_130 ( V_23 ,
L_128 , V_138 -> V_382 ) ;
V_57 = F_114 ( V_138 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
}
F_72 ( V_138 ) ;
F_81 ( V_138 ) ;
V_138 -> V_24 = & V_24 -> V_302 ;
if ( F_106 ( F_131 ( V_138 ) ) ) {
F_6 ( 0 , L_129 ) ;
V_57 = - V_14 ;
goto V_383;
}
return 0 ;
V_383:
F_16 ( V_138 -> V_360 ) ;
F_126 ( V_138 ) ;
V_17 -> V_138 = NULL ;
return V_57 ;
}
static int F_132 ( struct V_68 * V_24 , const struct V_390 * V_69 )
{
int V_57 = - V_80 ;
T_2 V_84 , V_225 = 0 ;
struct V_17 * V_17 ;
enum type type = V_76 ;
F_133 ( & V_391 ) ;
if ( F_106 ( V_392 >= 1 ) ) {
F_134 ( & V_391 ) ;
return - V_80 ;
}
V_392 ++ ;
switch ( V_24 -> V_237 ) {
case V_74 :
V_57 = F_135 ( & V_225 ,
V_393 ) ;
type = V_73 ;
break;
case V_241 :
V_57 = F_135 ( & V_225 ,
V_394 ) ;
type = V_76 ;
break;
case V_269 :
V_57 = F_135 ( & V_225 ,
V_395 ) ;
type = V_11 ;
break;
case V_289 :
V_57 = F_135 ( & V_225 ,
V_396 ) ;
type = V_12 ;
break;
case V_306 :
V_57 = F_136 ( & V_225 ,
V_397 ) ;
type = V_13 ;
break;
}
if ( F_106 ( V_57 < 0 ) ) {
F_6 ( 0 , L_130 , V_24 -> V_237 ) ;
goto V_383;
}
V_84 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_6 ( 0 , L_131 ,
V_84 , V_84 + 1 , V_225 ) ;
V_17 -> V_84 = V_84 ++ ;
V_57 = F_127 ( V_17 , type ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_398;
}
F_58 ( V_233 , L_107 , V_374 ) ;
F_134 ( & V_391 ) ;
return 0 ;
V_398:
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_124 ( V_17 ) ;
F_103 () ;
V_383:
F_134 ( & V_391 ) ;
return V_57 ;
}
static void F_137 ( struct V_68 * V_24 )
{
struct V_17 * V_17 ;
F_6 ( 0 , L_72 ) ;
F_133 ( & V_391 ) ;
if ( F_106 ( ! V_392 ) ) {
F_134 ( & V_391 ) ;
return;
}
F_13 (sbridge_dev, &sbridge_edac_list, list)
F_124 ( V_17 ) ;
F_103 () ;
V_392 -- ;
F_134 ( & V_391 ) ;
}
static int T_4 F_138 ( void )
{
int V_399 ;
F_6 ( 2 , L_72 ) ;
F_139 () ;
V_399 = F_140 ( & V_400 ) ;
if ( V_399 >= 0 ) {
F_141 ( & V_401 ) ;
if ( F_122 () == V_348 )
F_58 ( V_402 , L_132 ) ;
return 0 ;
}
F_58 ( V_81 , L_133 ,
V_399 ) ;
return V_399 ;
}
static void T_5 F_142 ( void )
{
F_6 ( 2 , L_72 ) ;
F_143 ( & V_400 ) ;
F_144 ( & V_401 ) ;
}
