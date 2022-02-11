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
static int F_55 ( int V_68 , T_3 V_69 )
{
int V_70 ;
for ( V_70 = 12 ; V_70 < 28 ; V_70 += 2 )
V_68 ^= ( V_69 >> V_70 ) & 3 ;
return V_68 ;
}
static struct V_71 * F_56 ( T_2 V_18 , T_1 V_72 )
{
struct V_71 * V_24 = NULL ;
do {
V_24 = F_57 ( V_73 , V_72 , V_24 ) ;
if ( V_24 && V_24 -> V_18 -> V_74 == V_18 )
break;
} while ( V_24 );
return V_24 ;
}
static int F_58 ( const T_2 V_18 , enum type type )
{
struct V_71 * V_24 = NULL ;
T_1 V_75 , V_72 ;
switch ( type ) {
case V_76 :
V_72 = V_77 ;
break;
case V_11 :
V_72 = V_78 ;
break;
case V_79 :
V_72 = V_80 ;
break;
case V_12 :
V_72 = V_81 ;
break;
case V_13 :
V_72 = V_82 ;
break;
default:
return - V_83 ;
}
if ( type != V_13 )
V_24 = F_56 ( V_18 , V_72 ) ;
else
V_24 = F_57 ( V_73 , V_72 , 0 ) ;
if ( ! V_24 ) {
F_59 ( V_84 , L_14
L_15 ,
V_73 , V_72 , V_18 ) ;
return - V_83 ;
}
F_21 ( V_24 ,
type == V_13 ? V_85 : V_45 , & V_75 ) ;
if ( ! F_60 ( V_75 ) ) {
F_59 ( V_84 , L_16 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_61 ( const struct V_26 * V_27 ,
const int V_86 ,
const int V_87 ,
T_3 * V_88 ,
T_3 * V_89 ,
int * V_90 )
{
T_1 V_91 , V_92 , V_64 ;
struct V_71 * V_93 ;
int V_94 ;
switch ( V_87 ) {
case 0 :
V_93 = V_27 -> V_60 . V_95 ;
break;
case 1 :
V_93 = V_27 -> V_60 . V_96 ;
break;
default:
F_35 ( 1 ) ;
return - V_14 ;
}
F_21 ( V_93 ,
V_97 [ V_86 ] , & V_91 ) ;
F_21 ( V_93 ,
V_98 [ V_86 ] , & V_92 ) ;
F_21 ( V_93 ,
V_99 [ V_86 ] , & V_64 ) ;
if ( ! F_3 ( V_91 , 0 , 0 ) )
return - V_83 ;
V_94 = F_3 ( V_91 , 3 , 5 ) ;
if ( V_94 < F_62 ( V_100 ) ) {
* V_90 = V_100 [ V_94 ] ;
} else {
* V_90 = 0 ;
F_59 ( V_84 ,
L_17 ,
V_94 ) ;
return - V_83 ;
}
* V_88 = ( ( T_3 ) F_3 ( V_92 , 6 , 31 ) << 6 ) |
( ( T_3 ) F_3 ( V_64 , 0 , 15 ) << 32 ) ;
* V_89 = ( ( T_3 ) F_3 ( V_91 , 6 , 31 ) << 6 ) | 63 |
( ( T_3 ) F_3 ( V_64 , 16 , 31 ) << 32 ) ;
return 0 ;
}
static int F_63 ( int V_101 )
{
F_35 ( V_101 < 0 || V_101 >= 6 ) ;
return V_101 < 3 ? 1 : 0 ;
}
static T_1 F_64 ( int V_86 , T_1 V_4 )
{
F_35 ( V_86 >= V_102 ) ;
return F_3 ( V_4 , V_86 * 3 , ( V_86 * 3 ) + 2 ) ;
}
static T_1 F_65 ( int V_86 , T_1 V_4 )
{
int V_87 , V_103 ;
F_35 ( V_86 >= V_104 ) ;
V_87 = F_3 ( V_4 , V_86 * 3 , ( V_86 * 3 ) + 2 ) ;
V_103 = F_3 ( V_4 , ( V_86 * 2 ) + 18 , ( V_86 * 2 ) + 18 + 1 ) ;
return F_66 ( V_87 * 3 + V_103 ) ;
}
static void F_67 ( T_1 V_4 , char * V_32 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_102 ; V_70 ++ ) {
V_32 [ V_70 * 2 ] = F_64 ( V_70 , V_4 ) + '0' ;
V_32 [ V_70 * 2 + 1 ] = '-' ;
}
V_32 [ V_102 * 2 - 1 ] = '\0' ;
}
static void F_68 ( T_1 V_4 , char * V_32 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_104 ; V_70 ++ ) {
V_32 [ V_70 * 2 ] = F_65 ( V_70 , V_4 ) + '0' ;
V_32 [ V_70 * 2 + 1 ] = '-' ;
}
V_32 [ V_104 * 2 - 1 ] = '\0' ;
}
static int F_69 ( struct V_26 * V_27 , T_3 * V_105 )
{
T_3 V_106 , V_107 , F_28 = 0 ;
T_3 V_108 , V_109 , V_110 , V_111 , V_112 ;
int V_113 = 0 ;
int V_114 = 0 ;
int V_115 , V_116 ;
T_1 V_117 , V_67 ;
int V_70 ;
T_3 V_118 [ 2 ] ;
T_1 V_119 , V_120 ;
T_1 V_121 [ V_122 ] ;
T_1 V_123 [ V_122 ] ;
int V_124 ;
char V_125 [ V_102 * 2 ] ;
char V_126 [ V_104 * 2 ] ;
int V_127 ;
int V_87 ;
int V_101 ;
int V_128 ;
int V_129 [ V_104 ] ;
int V_130 = 0 ;
for ( V_70 = 0 ; V_70 < V_104 ; V_70 ++ )
V_105 [ V_70 ] = 0 ;
V_127 = 0 ;
for ( V_70 = 0 ; V_70 < V_122 ; V_70 ++ ) {
F_21 ( V_27 -> V_60 . V_131 [ V_70 ] ,
V_132 , & V_123 [ V_70 ] ) ;
if ( V_70 > 0 && V_123 [ V_70 ] != V_123 [ V_70 - 1 ] ) {
F_67 ( V_123 [ V_70 - 1 ] ,
V_125 ) ;
if ( V_127 == V_70 - 1 )
F_6 ( 0 , L_18 ,
V_127 , V_125 ) ;
else
F_6 ( 0 , L_19 ,
V_127 , V_70 - 1 , V_125 ) ;
V_127 = V_70 ;
}
}
F_67 ( V_123 [ V_70 - 1 ] , V_125 ) ;
if ( V_127 == V_70 - 1 )
F_6 ( 0 , L_18 ,
V_127 , V_125 ) ;
else
F_6 ( 0 , L_19 ,
V_127 , V_70 - 1 , V_125 ) ;
V_127 = 0 ;
for ( V_70 = 0 ; V_70 < V_122 ; V_70 ++ ) {
F_21 ( V_27 -> V_60 . V_131 [ V_70 ] ,
V_133 , & V_121 [ V_70 ] ) ;
if ( V_70 > 0 && V_121 [ V_70 ] != V_121 [ V_70 - 1 ] ) {
F_68 ( V_121 [ V_70 - 1 ] , V_126 ) ;
if ( V_127 == V_70 - 1 )
F_6 ( 0 , L_20 ,
V_127 , V_126 ) ;
else
F_6 ( 0 , L_21 ,
V_127 , V_70 - 1 , V_126 ) ;
V_127 = V_70 ;
}
}
F_68 ( V_121 [ V_70 - 1 ] , V_126 ) ;
if ( V_127 == V_70 - 1 )
F_6 ( 0 , L_20 ,
V_127 , V_126 ) ;
else
F_6 ( 0 , L_21 ,
V_127 , V_70 - 1 , V_126 ) ;
for ( V_113 = 0 ; V_113 < V_27 -> V_36 . V_134 ; V_113 ++ ) {
V_106 = F_28 ;
F_21 ( V_27 -> V_135 ,
V_27 -> V_36 . V_119 [ V_113 ] , & V_119 ) ;
if ( ! F_70 ( V_119 ) )
break;
V_124 = F_71 ( V_119 ) ;
F_28 = V_27 -> V_36 . F_28 ( V_119 ) + 1 ;
V_107 = F_28 - V_106 ;
F_21 ( V_27 -> V_135 ,
V_27 -> V_36 . V_136 [ V_113 ] , & V_120 ) ;
V_117 = F_2 ( V_27 -> V_36 . V_2 ,
V_120 , 0 ) ;
for ( V_115 = 1 ; V_115 < 8 ; V_115 ++ ) {
V_67 = F_2 ( V_27 -> V_36 . V_2 ,
V_120 , V_115 ) ;
if ( ( V_67 & 0x8 ) == 0 ) {
F_6 ( 0 , L_22 ,
V_67 ) ;
return - 1 ;
}
if ( V_67 == V_117 )
break;
}
if ( F_72 ( V_119 ) )
V_115 *= 3 ;
F_6 ( 3 , L_23 ,
V_113 ,
V_106 ,
F_28 ,
V_115 ,
V_124 ? L_24 : L_25 ) ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
V_118 [ V_87 ] = 0 ;
V_112 = 0 ;
for ( V_114 = 0 ;
V_114 < F_62 (
V_97 ) ;
V_114 ++ ) {
if ( F_61 ( V_27 ,
V_114 ,
V_87 ,
& V_111 ,
& V_110 ,
& V_116 ) )
break;
V_109 = ( V_110 + 1 ) -
( V_112 + V_111 ) ;
V_112 += V_109 ;
V_108 = ( V_110 + 1 ) - V_109 ;
if ( V_108 < V_106 ) {
if ( V_110 > V_106 )
F_6 ( 0 , L_26 ) ;
} else if ( V_108 < F_28 ) {
if ( V_110 + 1 > F_28 ) {
F_6 ( 0 , L_27 ) ;
} else {
F_6 ( 3 , L_28 ,
V_114 , V_108 ,
V_110 , V_109 ,
V_87 ) ;
V_118 [ V_87 ] += V_109 ;
}
}
V_108 = V_110 + 1 ;
}
}
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
F_6 ( 3 , L_29 ,
V_87 , V_118 [ V_87 ] , V_118 [ V_87 ] ) ;
}
if ( V_124 )
continue;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ )
V_129 [ V_101 ] = 0 ;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
for ( V_128 = 0 ; V_128 < V_115 ; V_128 ++ ) {
int V_137 ;
int V_138 ;
if ( F_72 ( V_119 ) )
V_137 = V_128 ;
else
V_137 = 0x7 & F_2 (
V_27 -> V_36 . V_2 , V_120 , V_128 ) ;
for ( V_138 = 0 ; V_138 < V_122 ; V_138 ++ ) {
if ( F_65 ( V_137 ,
V_121 [ V_138 ] ) == V_101
&& ! V_129 [ V_101 ] ) {
V_130 ++ ;
V_129 [ V_101 ] = 1 ;
break;
}
}
}
}
if ( V_130 != V_115 )
F_6 ( 0 , L_30 ,
V_130 , V_115 ) ;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
V_87 = F_63 ( V_101 ) ;
if ( V_129 [ V_101 ] ) {
F_6 ( 4 , L_31 ,
V_101 ,
V_118 [ V_87 ] / V_115 ,
V_113 ) ;
V_105 [ V_101 ] +=
V_118 [ V_87 ] / V_115 ;
}
}
}
return 0 ;
}
static int F_73 ( struct V_139 * V_140 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_142 * V_143 ;
unsigned V_70 , V_144 , V_145 , V_9 , V_15 , V_16 , V_146 ;
T_3 V_147 ;
T_1 V_4 ;
enum V_148 V_149 ;
enum V_33 V_34 ;
int V_150 = V_27 -> V_36 . type == V_13 ?
V_104 : V_151 ;
T_3 V_152 [ V_104 ] ;
if ( V_27 -> V_36 . type == V_11 || V_27 -> V_36 . type == V_12 ) {
F_21 ( V_27 -> V_153 , V_154 , & V_4 ) ;
V_27 -> V_155 = F_3 ( V_4 , 21 , 21 ) ;
}
if ( V_27 -> V_36 . type == V_11 || V_27 -> V_36 . type == V_12 ||
V_27 -> V_36 . type == V_13 )
F_21 ( V_27 -> V_28 , V_156 , & V_4 ) ;
else
F_21 ( V_27 -> V_53 , V_156 , & V_4 ) ;
if ( V_27 -> V_36 . type == V_13 )
V_27 -> V_17 -> V_157 = F_74 ( V_4 ) ;
else
V_27 -> V_17 -> V_157 = F_75 ( V_4 ) ;
V_27 -> V_17 -> V_158 = V_27 -> V_36 . F_45 ( V_27 ) ;
F_6 ( 0 , L_32 ,
V_27 -> V_17 -> V_87 ,
V_27 -> V_17 -> V_158 ,
V_27 -> V_17 -> V_157 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
V_149 = V_159 ;
V_27 -> V_160 = false ;
if ( F_69 ( V_27 , V_152 ) != 0 )
return - 1 ;
} else {
F_21 ( V_27 -> V_161 , V_162 , & V_4 ) ;
if ( F_76 ( V_4 ) ) {
F_6 ( 0 , L_33 ) ;
V_27 -> V_160 = true ;
} else {
F_6 ( 0 , L_34 ) ;
V_27 -> V_160 = false ;
}
F_21 ( V_27 -> V_44 , V_45 , & V_27 -> V_36 . V_75 ) ;
if ( F_77 ( V_27 -> V_36 . V_75 ) ) {
F_6 ( 0 , L_35 ) ;
V_149 = V_163 ;
V_27 -> V_164 = true ;
} else {
F_6 ( 0 , L_36 ) ;
V_149 = V_159 ;
V_27 -> V_164 = false ;
}
if ( F_78 ( V_27 -> V_36 . V_75 ) ) {
F_6 ( 0 , L_37 ) ;
V_27 -> V_165 = true ;
} else {
F_6 ( 0 , L_38 ) ;
V_27 -> V_165 = false ;
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
V_145 = 16 ;
else
V_145 = 8 ;
for ( V_70 = 0 ; V_70 < V_150 ; V_70 ++ ) {
T_1 V_8 ;
int V_166 ;
if ( V_27 -> V_36 . type == V_13 ) {
V_166 = 1 ;
if ( ! V_27 -> V_60 . V_167 [ V_70 ] )
continue;
} else {
V_166 = F_62 ( V_168 ) ;
if ( ! V_27 -> V_169 [ V_70 ] )
continue;
}
for ( V_144 = 0 ; V_144 < V_166 ; V_144 ++ ) {
V_143 = F_79 ( V_140 -> V_170 , V_140 -> V_171 , V_140 -> V_172 ,
V_70 , V_144 , 0 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
F_21 ( V_27 -> V_60 . V_167 [ V_70 ] ,
V_173 , & V_8 ) ;
} else {
F_21 ( V_27 -> V_169 [ V_70 ] ,
V_168 [ V_144 ] , & V_8 ) ;
}
F_6 ( 4 , L_42 , V_70 , V_144 , V_8 ) ;
if ( F_80 ( V_8 ) ) {
V_27 -> V_101 [ V_70 ] . V_171 ++ ;
V_9 = F_4 ( V_27 -> V_36 . type , V_8 ) ;
if ( V_27 -> V_36 . type == V_13 ) {
V_16 = 1 << 10 ;
V_15 = V_152 [ V_70 ] /
( ( T_3 ) V_16 * V_9 * V_145 * 8 ) ;
} else {
V_15 = F_7 ( V_8 ) ;
V_16 = F_9 ( V_8 ) ;
}
V_147 = ( ( T_3 ) V_15 * V_16 * V_145 * V_9 ) >> ( 20 - 3 ) ;
V_146 = F_81 ( V_147 ) ;
F_6 ( 0 , L_43 ,
V_27 -> V_17 -> V_87 , V_70 / 4 , V_70 % 4 , V_144 ,
V_147 , V_146 ,
V_145 , V_9 , V_15 , V_16 ) ;
V_143 -> V_174 = V_146 ;
V_143 -> V_175 = 32 ;
V_143 -> V_176 = V_27 -> V_36 . V_177 ( V_27 , V_8 ) ;
V_143 -> V_34 = V_34 ;
V_143 -> V_178 = V_149 ;
snprintf ( V_143 -> V_179 , sizeof( V_143 -> V_179 ) ,
L_44 ,
V_27 -> V_17 -> V_157 , V_70 / 4 , V_70 % 4 , V_144 ) ;
}
}
}
return 0 ;
}
static void F_82 ( const struct V_139 * V_140 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
int V_70 , V_144 , V_180 , V_181 , V_182 , V_183 ;
T_1 V_4 ;
T_3 V_89 , V_184 = 0 ;
T_3 V_185 ;
T_1 V_186 , V_187 ;
T_1 V_188 ;
V_27 -> V_189 = V_27 -> V_36 . V_190 ( V_27 ) ;
V_185 = ( 1 + V_27 -> V_189 ) >> 20 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_45 ,
V_186 , ( V_187 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_189 ) ;
V_27 -> V_191 = V_27 -> V_36 . V_192 ( V_27 ) ;
V_185 = ( 1 + V_27 -> V_191 ) >> 20 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_46 ,
V_186 , ( V_187 * 1000 ) / 1024 , ( T_3 ) V_27 -> V_191 ) ;
V_184 = 0 ;
for ( V_181 = 0 ; V_181 < V_27 -> V_36 . V_134 ; V_181 ++ ) {
F_21 ( V_27 -> V_135 , V_27 -> V_36 . V_119 [ V_181 ] ,
& V_4 ) ;
V_89 = V_27 -> V_36 . F_28 ( V_4 ) ;
if ( ! F_70 ( V_4 ) )
continue;
if ( V_89 <= V_184 )
break;
V_185 = ( V_89 + 1 ) >> 20 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_47 ,
V_181 ,
F_1 ( V_27 -> V_36 . F_31 ( V_4 ) ) ,
V_186 , ( V_187 * 1000 ) / 1024 ,
( ( T_3 ) V_185 ) << 20L ,
V_27 -> V_36 . F_30 ( V_4 ) ,
V_4 ) ;
V_184 = V_89 ;
F_21 ( V_27 -> V_135 , V_27 -> V_36 . V_136 [ V_181 ] ,
& V_4 ) ;
V_183 = F_2 ( V_27 -> V_36 . V_2 , V_4 , 0 ) ;
for ( V_144 = 0 ; V_144 < 8 ; V_144 ++ ) {
T_1 V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_144 ) ;
if ( V_144 > 0 && V_183 == V_67 )
break;
F_6 ( 0 , L_48 ,
V_181 , V_144 , V_67 ) ;
}
}
if ( V_27 -> V_36 . type == V_13 )
return;
V_184 = 0 ;
for ( V_182 = 0 ; V_182 < V_193 ; V_182 ++ ) {
F_21 ( V_27 -> V_153 , V_194 [ V_182 ] ,
& V_4 ) ;
V_89 = F_84 ( V_4 ) ;
if ( V_89 <= V_184 )
break;
V_185 = ( V_89 + 1 ) >> 20 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_49 ,
V_182 , V_186 , ( V_187 * 1000 ) / 1024 ,
( ( T_3 ) V_185 ) << 20L ,
( T_1 ) ( 1 << F_85 ( V_4 ) ) ,
( T_1 ) F_86 ( V_4 ) + 1 ,
( T_1 ) F_87 ( V_4 ) ,
( T_1 ) F_88 ( V_4 ) ,
( T_1 ) F_89 ( V_4 ) ,
( T_1 ) F_90 ( V_4 ) ,
V_4 ) ;
V_184 = V_89 ;
}
for ( V_70 = 0 ; V_70 < V_151 ; V_70 ++ ) {
if ( ! V_27 -> V_101 [ V_70 ] . V_171 )
continue;
for ( V_144 = 0 ; V_144 < V_182 ; V_144 ++ ) {
F_21 ( V_27 -> V_169 [ V_70 ] ,
V_195 [ V_144 ] ,
& V_4 ) ;
V_185 = F_91 ( V_4 ) >> 20 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_50 ,
V_70 , V_144 ,
V_186 , ( V_187 * 1000 ) / 1024 ,
( ( T_3 ) V_185 ) << 20L ,
V_4 ) ;
}
}
for ( V_70 = 0 ; V_70 < V_151 ; V_70 ++ ) {
if ( ! V_27 -> V_101 [ V_70 ] . V_171 )
continue;
for ( V_144 = 0 ; V_144 < V_196 ; V_144 ++ ) {
F_21 ( V_27 -> V_169 [ V_70 ] ,
V_197 [ V_144 ] ,
& V_4 ) ;
if ( ! F_92 ( V_4 ) )
continue;
V_185 = V_27 -> V_36 . F_27 ( V_4 ) >> 20 ;
V_188 = 1 << F_93 ( V_4 ) ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_51 ,
V_70 , V_144 ,
V_186 , ( V_187 * 1000 ) / 1024 ,
( ( T_3 ) V_185 ) << 20L ,
V_188 ,
V_4 ) ;
for ( V_180 = 0 ; V_180 < V_188 ; V_180 ++ ) {
F_21 ( V_27 -> V_169 [ V_70 ] ,
V_198 [ V_144 ] [ V_180 ] ,
& V_4 ) ;
V_185 = F_94 ( V_4 ) << 6 ;
V_186 = F_83 ( V_185 , 1024 , & V_187 ) ;
F_6 ( 0 , L_52 ,
V_70 , V_144 , V_180 ,
V_186 , ( V_187 * 1000 ) / 1024 ,
( ( T_3 ) V_185 ) << 20L ,
( T_1 ) F_95 ( V_4 ) ,
V_4 ) ;
}
}
}
}
static struct V_139 * F_96 ( T_2 V_158 )
{
struct V_17 * V_17 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
if ( V_17 -> V_158 == V_158 )
return V_17 -> V_140 ;
}
return NULL ;
}
static int F_97 ( struct V_139 * V_140 ,
T_3 V_69 ,
T_2 * V_199 , T_2 * V_200 ,
long * V_201 ,
T_2 * V_202 ,
char * * V_203 , char * V_204 )
{
struct V_139 * V_205 ;
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_206 ;
int V_207 , V_181 , V_182 , V_208 , V_209 ;
int V_183 , V_68 , V_210 ;
int F_29 , V_211 = 0 ;
unsigned V_212 [ V_27 -> V_36 . V_213 ] ;
T_1 V_4 , V_119 ;
T_2 V_214 , V_215 , V_67 , V_216 = 0 , V_217 = 0 ;
T_1 V_218 ;
T_1 V_188 ;
T_1 V_187 , V_186 ;
T_3 V_219 , V_88 , V_89 = 0 , V_184 = 0 ;
if ( ( V_69 > ( T_3 ) V_27 -> V_189 ) && ( V_69 < ( 1LL << 32 ) ) ) {
sprintf ( V_204 , L_53 , V_69 ) ;
return - V_14 ;
}
if ( V_69 >= ( T_3 ) V_27 -> V_191 ) {
sprintf ( V_204 , L_54 , V_69 ) ;
return - V_14 ;
}
for ( V_181 = 0 ; V_181 < V_27 -> V_36 . V_134 ; V_181 ++ ) {
F_21 ( V_27 -> V_135 , V_27 -> V_36 . V_119 [ V_181 ] ,
& V_4 ) ;
if ( ! F_70 ( V_4 ) )
continue;
V_89 = V_27 -> V_36 . F_28 ( V_4 ) ;
if ( V_89 <= V_184 ) {
sprintf ( V_204 , L_55 ) ;
return - V_14 ;
}
if ( V_69 <= V_89 )
break;
V_184 = V_89 ;
}
if ( V_181 == V_27 -> V_36 . V_134 ) {
sprintf ( V_204 , L_55 ) ;
return - V_14 ;
}
V_119 = V_4 ;
* V_203 = F_1 ( V_27 -> V_36 . F_31 ( V_119 ) ) ;
F_29 = V_27 -> V_36 . F_29 ( V_119 ) ;
F_21 ( V_27 -> V_135 , V_27 -> V_36 . V_136 [ V_181 ] ,
& V_4 ) ;
if ( V_27 -> V_36 . type == V_79 ) {
V_183 = F_2 ( V_27 -> V_36 . V_2 , V_4 , 0 ) ;
for ( V_208 = 0 ; V_208 < 8 ; V_208 ++ ) {
T_1 V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_208 ) ;
if ( V_208 > 0 && V_183 == V_67 )
break;
V_212 [ V_208 ] = V_67 ;
F_6 ( 0 , L_56 ,
V_208 , V_212 [ V_208 ] ) ;
}
F_6 ( 0 , L_57 ,
V_27 -> V_17 -> V_87 ,
V_181 ,
V_69 ,
V_89 ,
V_208 + 7 ,
! F_29 ? L_25 : L_58 ) ;
if ( F_29 )
V_68 = ( ( V_69 >> 6 ) ^ ( V_69 >> 16 ) ) & 7 ;
else
V_68 = ( V_69 >> 6 ) & 7 ;
switch ( V_208 ) {
case 1 :
V_68 = 0 ;
break;
case 2 :
V_68 = V_68 & 1 ;
break;
case 4 :
V_68 = V_68 & 3 ;
break;
case 8 :
break;
default:
sprintf ( V_204 , L_59 ) ;
return - V_14 ;
}
* V_199 = V_212 [ V_68 ] ;
F_6 ( 0 , L_60 ,
V_68 , V_208 , * V_199 ) ;
} else if ( V_27 -> V_36 . type == V_11 || V_27 -> V_36 . type == V_12 ) {
int V_220 , V_221 = F_98 ( V_119 ) ;
if ( V_221 ) {
V_220 = F_3 ( V_69 , 7 , 8 ) << 1 ;
V_220 |= F_3 ( V_69 , 9 , 9 ) ;
} else
V_220 = F_3 ( V_69 , 6 , 8 ) ;
if ( F_29 == 0 ) {
V_68 = F_3 ( V_69 , 16 , 18 ) ;
V_68 ^= V_220 ;
} else
V_68 = V_220 ;
V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_68 ) ;
* V_199 = F_53 ( V_67 ) ;
V_216 = F_54 ( V_67 ) ;
if ( V_216 )
V_217 = 4 ;
if ( V_221 ) {
F_21 ( V_27 -> V_153 ,
V_154 , & V_4 ) ;
V_211 = F_3 ( V_4 , 22 , 22 ) ;
}
F_6 ( 0 , L_61 ,
V_68 , * V_199 , V_216 , V_211 ) ;
} else {
V_68 = ( V_69 >> 6 ) & 7 ;
V_67 = F_2 ( V_27 -> V_36 . V_2 , V_4 , V_68 ) ;
* V_199 = F_53 ( V_67 ) ;
V_216 = F_54 ( V_67 ) ;
if ( V_216 )
V_217 = 4 ;
F_6 ( 0 , L_62 ,
V_68 , * V_199 , V_216 ) ;
}
* V_200 = V_216 ;
V_205 = F_96 ( * V_199 ) ;
if ( ! V_205 ) {
sprintf ( V_204 , L_63 ,
* V_199 ) ;
return - V_14 ;
}
V_140 = V_205 ;
V_27 = V_140 -> V_141 ;
V_184 = 0 ;
if ( V_27 -> V_36 . type == V_79 )
V_206 = V_27 -> V_153 ;
else {
if ( V_216 )
V_206 = V_27 -> V_222 ;
else
V_206 = V_27 -> V_153 ;
}
for ( V_182 = 0 ; V_182 < V_193 ; V_182 ++ ) {
F_21 ( V_206 , V_194 [ V_182 ] , & V_4 ) ;
V_89 = F_84 ( V_4 ) ;
if ( V_89 <= V_184 ) {
sprintf ( V_204 , L_64 ) ;
return - V_14 ;
}
if ( V_69 <= V_89 )
break;
V_184 = V_89 ;
}
if ( V_182 == V_193 ) {
sprintf ( V_204 , L_64 ) ;
return - V_14 ;
}
V_214 = F_86 ( V_4 ) + 1 ;
V_215 = F_85 ( V_4 ) ;
if ( V_214 == 3 )
V_68 = V_69 >> 6 ;
else {
V_68 = ( V_69 >> ( 6 + V_215 + V_211 ) ) & 0x3 ;
if ( V_27 -> V_155 )
V_68 = F_55 ( V_68 , V_69 ) ;
}
V_68 = V_68 % V_214 ;
switch ( V_68 ) {
case 0 :
V_210 = F_87 ( V_4 ) ;
break;
case 1 :
V_210 = F_88 ( V_4 ) ;
break;
case 2 :
V_210 = F_89 ( V_4 ) ;
break;
case 3 :
V_210 = F_90 ( V_4 ) ;
break;
default:
sprintf ( V_204 , L_65 ) ;
return - V_14 ;
}
* V_201 = 1 << V_210 ;
F_21 ( V_27 -> V_169 [ V_217 + V_210 ] ,
V_195 [ V_182 ] ,
& V_218 ) ;
if ( V_27 -> V_160 ) {
* V_201 |= 1 << ( ( V_210 + 2 ) % 4 ) ;
switch( V_214 ) {
case 2 :
case 4 :
V_209 = ( 1 << V_215 ) * ( V_214 >> 1 ) ;
break;
default:
sprintf ( V_204 , L_66 ) ;
return - V_14 ;
}
} else
V_209 = ( 1 << V_215 ) * V_214 ;
if ( V_27 -> V_164 )
* V_201 |= 1 << ( ( V_210 + 1 ) % 4 ) ;
V_88 = F_91 ( V_218 ) ;
F_6 ( 0 , L_67 ,
V_182 ,
V_69 ,
V_89 ,
V_215 ,
V_214 ,
V_88 ,
V_68 ,
V_210 ,
* V_201 ) ;
if ( V_88 > V_69 ) {
sprintf ( V_204 , L_68 ,
V_88 , V_69 ) ;
return - V_14 ;
}
V_219 = V_69 - V_88 ;
V_219 >>= ( 6 + V_211 ) ;
V_219 /= V_209 ;
V_219 <<= ( 6 + V_211 ) ;
V_219 |= V_69 & ( ( 1 << ( 6 + V_211 ) ) - 1 ) ;
for ( V_207 = 0 ; V_207 < V_196 ; V_207 ++ ) {
F_21 ( V_27 -> V_169 [ V_217 + V_210 ] ,
V_197 [ V_207 ] ,
& V_4 ) ;
if ( ! F_92 ( V_4 ) )
continue;
V_89 = V_27 -> V_36 . F_27 ( V_4 ) ;
V_186 = F_83 ( V_89 >> 20 , 1024 , & V_187 ) ;
F_6 ( 0 , L_69 ,
V_207 ,
V_186 , ( V_187 * 1000 ) / 1024 ,
V_89 ,
1 << F_93 ( V_4 ) ) ;
if ( V_219 <= V_89 )
break;
}
if ( V_207 == V_196 ) {
sprintf ( V_204 , L_70 ,
V_219 ) ;
return - V_14 ;
}
V_188 = F_93 ( V_4 ) ;
if ( V_27 -> V_165 )
V_68 = ( V_219 >> 6 ) ;
else
V_68 = ( V_219 >> 13 ) ;
V_68 %= 1 << V_188 ;
F_21 ( V_27 -> V_169 [ V_217 + V_210 ] ,
V_198 [ V_207 ] [ V_68 ] ,
& V_4 ) ;
* V_202 = F_95 ( V_4 ) ;
F_6 ( 0 , L_71 ,
V_207 ,
V_219 ,
V_89 ,
V_188 ,
V_68 ) ;
return 0 ;
}
static void F_99 ( struct V_17 * V_17 )
{
int V_70 ;
F_6 ( 0 , L_72 ) ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
struct V_71 * V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
F_6 ( 0 , L_73 ,
V_24 -> V_18 -> V_74 ,
F_100 ( V_24 -> V_223 ) , F_101 ( V_24 -> V_223 ) ) ;
F_102 ( V_24 ) ;
}
}
static void F_103 ( void )
{
struct V_17 * V_17 , * V_224 ;
F_104 (sbridge_dev, tmp, &sbridge_edac_list, list) {
F_99 ( V_17 ) ;
F_18 ( V_17 ) ;
}
}
static int F_105 ( struct V_71 * * V_225 ,
T_2 * V_226 ,
const struct V_22 * V_3 ,
const unsigned V_227 ,
const int V_19 )
{
struct V_17 * V_17 ;
const struct V_228 * V_229 = & V_3 -> V_230 [ V_227 ] ;
struct V_71 * V_24 = NULL ;
T_2 V_18 = 0 ;
F_59 ( V_231 ,
L_74 ,
V_73 , V_229 -> V_232 ) ;
V_24 = F_57 ( V_73 ,
V_229 -> V_232 , * V_225 ) ;
if ( ! V_24 ) {
if ( * V_225 ) {
* V_225 = V_24 ;
return 0 ;
}
if ( V_229 -> V_233 )
return 0 ;
if ( V_227 == 0 )
return - V_83 ;
F_59 ( V_234 ,
L_75 ,
V_73 , V_229 -> V_232 ) ;
return - V_83 ;
}
V_18 = V_24 -> V_18 -> V_74 ;
V_17 = F_11 ( V_18 , V_19 ) ;
if ( ! V_17 ) {
V_17 = F_14 ( V_18 , V_3 ) ;
if ( ! V_17 ) {
F_102 ( V_24 ) ;
return - V_235 ;
}
( * V_226 ) ++ ;
}
if ( V_17 -> V_24 [ V_227 ] ) {
F_59 ( V_84 ,
L_76 ,
V_73 , V_229 -> V_232 ) ;
F_102 ( V_24 ) ;
return - V_83 ;
}
V_17 -> V_24 [ V_227 ] = V_24 ;
if ( F_106 ( F_107 ( V_24 ) < 0 ) ) {
F_59 ( V_84 ,
L_77 ,
V_73 , V_229 -> V_232 ) ;
return - V_83 ;
}
F_6 ( 0 , L_78 ,
V_73 , V_229 -> V_232 ) ;
F_108 ( V_24 ) ;
* V_225 = V_24 ;
return 0 ;
}
static int F_109 ( T_2 * V_226 ,
const struct V_22 * V_3 ,
int V_236 ,
int V_19 )
{
int V_70 , V_57 ;
struct V_71 * V_24 = NULL ;
while ( V_3 && V_3 -> V_230 ) {
for ( V_70 = 0 ; V_70 < V_3 -> V_25 ; V_70 ++ ) {
if ( ! V_236 || V_70 == 0 ||
V_3 -> V_230 [ V_70 ] . V_232 !=
V_3 -> V_230 [ V_70 - 1 ] . V_232 ) {
V_24 = NULL ;
}
do {
V_57 = F_105 ( & V_24 , V_226 ,
V_3 , V_70 , V_19 ) ;
if ( V_57 < 0 ) {
if ( V_70 == 0 ) {
V_70 = V_3 -> V_25 ;
break;
}
F_103 () ;
return - V_83 ;
}
} while ( V_24 && ! V_236 );
}
V_3 ++ ;
}
return 0 ;
}
static int F_110 ( struct V_139 * V_140 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_24 ;
T_2 V_237 = 0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_238 ) {
case V_239 :
V_27 -> V_135 = V_24 ;
break;
case V_240 :
V_27 -> V_28 = V_24 ;
break;
case V_241 :
V_27 -> V_53 = V_24 ;
break;
case V_242 :
V_27 -> V_153 = V_24 ;
break;
case V_80 :
V_27 -> V_44 = V_24 ;
break;
case V_243 :
V_27 -> V_161 = V_24 ;
break;
case V_244 :
case V_245 :
case V_246 :
case V_247 :
{
int V_72 = V_24 -> V_238 - V_244 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_248 :
V_27 -> V_35 = V_24 ;
break;
default:
goto error;
}
F_6 ( 0 , L_79 ,
V_24 -> V_249 , V_24 -> V_238 ,
V_17 -> V_18 ,
V_24 ) ;
}
if ( ! V_27 -> V_135 || ! V_27 -> V_28 || ! V_27 -> V_153 ||
! V_27 -> V_169 || ! V_27 -> V_161 || ! V_27 -> V_44 )
goto V_250;
if ( V_237 != 0x0f )
goto V_250;
return 0 ;
V_250:
F_59 ( V_84 , L_80 ) ;
return - V_83 ;
error:
F_59 ( V_84 , L_81 ,
V_73 , V_24 -> V_238 ) ;
return - V_14 ;
}
static int F_111 ( struct V_139 * V_140 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_24 ;
T_2 V_237 = 0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_238 ) {
case V_251 :
V_27 -> V_153 = V_24 ;
break;
case V_77 :
V_27 -> V_44 = V_24 ;
case V_252 :
V_27 -> V_161 = V_24 ;
break;
case V_253 :
case V_254 :
case V_255 :
case V_256 :
{
int V_72 = V_24 -> V_238 - V_253 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_257 :
V_27 -> V_35 = V_24 ;
break;
case V_258 :
V_27 -> V_35 = V_24 ;
break;
case V_259 :
V_27 -> V_135 = V_24 ;
break;
case V_260 :
V_27 -> V_53 = V_24 ;
break;
case V_261 :
V_27 -> V_31 = V_24 ;
break;
case V_262 :
V_27 -> V_222 = V_24 ;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
{
int V_72 = V_24 -> V_238 - V_263 + 4 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
default:
goto error;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_223 ) , F_101 ( V_24 -> V_223 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_135 || ! V_27 -> V_153 || ! V_27 -> V_53 ||
! V_27 -> V_31 || ! V_27 -> V_169 || ! V_27 -> V_161 ||
! V_27 -> V_44 )
goto V_250;
if ( V_237 != 0x0f &&
V_237 != 0x33 &&
V_237 != 0xff )
goto V_250;
return 0 ;
V_250:
F_59 ( V_84 , L_80 ) ;
return - V_83 ;
error:
F_59 ( V_84 ,
L_81 , V_73 ,
V_24 -> V_238 ) ;
return - V_14 ;
}
static int F_112 ( struct V_139 * V_140 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_24 ;
T_2 V_237 = 0 ;
int V_70 ;
if ( V_27 -> V_36 . V_55 == NULL )
V_27 -> V_36 . V_55 = F_57 ( V_73 ,
V_267 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_238 ) {
case V_268 :
V_27 -> V_135 = V_24 ;
break;
case V_269 :
V_27 -> V_28 = V_24 ;
break;
case V_270 :
V_27 -> V_153 = V_24 ;
break;
case V_78 :
V_27 -> V_44 = V_24 ;
break;
case V_271 :
V_27 -> V_161 = V_24 ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
{
int V_72 = V_24 -> V_238 - V_272 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_276 :
case V_277 :
case V_278 :
case V_279 :
{
int V_72 = V_24 -> V_238 - V_276 + 4 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
if ( ! V_27 -> V_35 )
V_27 -> V_35 = V_24 ;
break;
case V_284 :
V_27 -> V_222 = V_24 ;
break;
case V_285 :
V_27 -> V_286 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_223 ) , F_101 ( V_24 -> V_223 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_135 || ! V_27 -> V_153 || ! V_27 -> V_28 ||
! V_27 -> V_161 || ! V_27 -> V_44 || ! V_27 -> V_36 . V_55 )
goto V_250;
if ( V_237 != 0x0f &&
V_237 != 0x33 &&
V_237 != 0xff )
goto V_250;
return 0 ;
V_250:
F_59 ( V_84 , L_80 ) ;
return - V_83 ;
}
static int F_113 ( struct V_139 * V_140 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_24 ;
T_2 V_237 = 0 ;
int V_70 ;
if ( V_27 -> V_36 . V_55 == NULL )
V_27 -> V_36 . V_55 = F_57 ( V_73 ,
V_287 ,
NULL ) ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
switch ( V_24 -> V_238 ) {
case V_288 :
V_27 -> V_135 = V_24 ;
break;
case V_289 :
V_27 -> V_28 = V_24 ;
break;
case V_290 :
V_27 -> V_153 = V_24 ;
break;
case V_81 :
V_27 -> V_44 = V_24 ;
break;
case V_291 :
V_27 -> V_161 = V_24 ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
{
int V_72 = V_24 -> V_238 - V_292 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
{
int V_72 = V_24 -> V_238 - V_296 + 4 ;
V_27 -> V_169 [ V_72 ] = V_24 ;
V_237 |= 1 << V_72 ;
}
break;
case V_300 :
V_27 -> V_35 = V_24 ;
break;
case V_301 :
V_27 -> V_222 = V_24 ;
break;
case V_302 :
V_27 -> V_286 = V_24 ;
break;
default:
break;
}
F_6 ( 0 , L_82 ,
V_17 -> V_18 ,
F_100 ( V_24 -> V_223 ) , F_101 ( V_24 -> V_223 ) ,
V_24 ) ;
}
if ( ! V_27 -> V_135 || ! V_27 -> V_153 || ! V_27 -> V_28 ||
! V_27 -> V_161 || ! V_27 -> V_44 || ! V_27 -> V_36 . V_55 )
goto V_250;
if ( V_237 != 0x0f &&
V_237 != 0x33 &&
V_237 != 0xff )
goto V_250;
return 0 ;
V_250:
F_59 ( V_84 , L_80 ) ;
return - V_83 ;
}
static int F_114 ( struct V_139 * V_140 ,
struct V_17 * V_17 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
struct V_71 * V_24 ;
int V_303 , V_304 ;
int V_70 ;
int V_305 ;
for ( V_70 = 0 ; V_70 < V_17 -> V_25 ; V_70 ++ ) {
V_24 = V_17 -> V_24 [ V_70 ] ;
if ( ! V_24 )
continue;
V_303 = ( V_24 -> V_223 >> 3 ) & 0x1f ;
V_304 = V_24 -> V_223 & 0x7 ;
switch ( V_24 -> V_238 ) {
case V_306 :
if ( V_303 == 8 )
V_27 -> V_60 . V_95 = V_24 ;
else if ( V_303 == 9 )
V_27 -> V_60 . V_96 = V_24 ;
else {
F_59 ( V_84 ,
L_83 ,
V_303 , V_304 ) ;
continue;
}
break;
case V_307 :
V_27 -> V_135 = V_24 ;
break;
case V_308 :
V_27 -> V_28 = V_24 ;
break;
case V_309 :
V_305 = ( ( V_303 - 14 ) * 8 ) + V_304 ;
if ( V_305 < 0 || V_305 >= V_122 ) {
F_59 ( V_84 ,
L_84 ,
V_303 , V_304 ) ;
continue;
}
F_35 ( V_27 -> V_60 . V_131 [ V_305 ] != NULL ) ;
V_27 -> V_60 . V_131 [ V_305 ] = V_24 ;
break;
case V_310 :
V_305 = - 1 ;
if ( V_303 == 9 )
V_305 = V_304 - 2 ;
else if ( V_303 == 8 )
V_305 = 3 + ( V_304 - 2 ) ;
if ( V_305 < 0 || V_305 >= V_104 ) {
F_59 ( V_84 ,
L_85 ,
V_303 , V_304 ) ;
continue;
}
F_35 ( V_27 -> V_60 . V_167 [ V_305 ] != NULL ) ;
V_27 -> V_60 . V_167 [ V_305 ] = V_24 ;
break;
case V_311 :
V_27 -> V_60 . V_61 = V_24 ;
break;
case V_82 :
V_27 -> V_44 = V_24 ;
break;
default:
F_59 ( V_84 , L_86 ,
V_24 -> V_238 ) ;
break;
}
}
if ( ! V_27 -> V_60 . V_95 || ! V_27 -> V_60 . V_96 ||
! V_27 -> V_135 || ! V_27 -> V_28 ||
! V_27 -> V_44 ) {
goto V_250;
}
for ( V_70 = 0 ; V_70 < V_104 ; V_70 ++ ) {
if ( ! V_27 -> V_60 . V_167 [ V_70 ] ) {
F_59 ( V_84 , L_87 , V_70 ) ;
goto V_250;
}
}
for ( V_70 = 0 ; V_70 < V_122 ; V_70 ++ ) {
if ( ! V_27 -> V_60 . V_131 [ V_70 ] ) {
F_59 ( V_84 , L_88 , V_70 ) ;
goto V_250;
}
}
return 0 ;
V_250:
F_59 ( V_84 , L_80 ) ;
return - V_83 ;
}
static void F_115 ( struct V_139 * V_140 ,
const struct V_312 * V_313 )
{
struct V_139 * V_205 ;
struct V_26 * V_27 = V_140 -> V_141 ;
enum V_314 V_315 ;
char * type , * V_316 , V_204 [ 256 ] ;
bool V_317 = F_3 ( V_313 -> V_318 , 0 , 0 ) ;
bool V_319 = F_3 ( V_313 -> V_320 , 62 , 62 ) ;
bool V_321 = F_3 ( V_313 -> V_320 , 61 , 61 ) ;
bool V_322 ;
T_1 V_323 = F_3 ( V_313 -> V_320 , 38 , 52 ) ;
T_1 V_324 = F_3 ( V_313 -> V_320 , 16 , 31 ) ;
T_1 V_325 = F_3 ( V_313 -> V_320 , 0 , 15 ) ;
T_1 V_101 = F_3 ( V_313 -> V_320 , 0 , 3 ) ;
T_1 V_326 = F_3 ( V_313 -> V_320 , 4 , 6 ) ;
long V_201 , V_327 ;
T_2 V_202 , V_199 , V_200 ;
int V_57 , V_143 ;
char * V_203 = NULL ;
if ( V_27 -> V_36 . type != V_79 )
V_322 = true ;
else
V_322 = F_3 ( V_313 -> V_320 , 56 , 56 ) ;
if ( V_321 ) {
if ( V_317 ) {
type = L_89 ;
V_315 = V_328 ;
} else {
type = L_90 ;
V_315 = V_329 ;
}
} else {
type = L_91 ;
V_315 = V_330 ;
}
if ( ! ( ( V_325 & 0xef80 ) == 0x80 ) ) {
V_316 = L_92 ;
} else {
switch ( V_326 ) {
case 0 :
V_316 = L_93 ;
break;
case 1 :
V_316 = L_94 ;
break;
case 2 :
V_316 = L_95 ;
break;
case 3 :
V_316 = L_96 ;
break;
case 4 :
V_316 = L_97 ;
break;
default:
V_316 = L_98 ;
break;
}
}
if ( ! F_3 ( V_313 -> V_320 , 58 , 58 ) )
return;
if ( V_27 -> V_36 . type == V_13 ) {
if ( V_101 == 14 ) {
F_6 ( 0 , L_99 ,
V_319 ? L_100 : L_25 ,
( V_321 && V_322 )
? L_101 : L_25 ,
V_324 , V_325 ,
V_313 -> V_331 ) ;
} else {
char V_332 = * ( L_102 ) ;
V_101 = F_66 ( V_101 ) ;
V_201 = 1 << V_101 ;
snprintf ( V_204 , sizeof( V_204 ) ,
L_103 ,
V_319 ? L_100 : L_25 ,
( V_321 && V_322 )
? L_101 : L_104 ,
V_324 , V_325 , V_101 , V_332 + V_101 ) ;
F_116 ( V_315 , V_140 , V_323 ,
V_313 -> V_69 >> V_333 , V_313 -> V_69 & ~ V_334 , 0 ,
V_101 , 0 , - 1 ,
V_316 , V_204 ) ;
}
return;
} else {
V_57 = F_97 ( V_140 , V_313 -> V_69 , & V_199 , & V_200 ,
& V_201 , & V_202 , & V_203 , V_204 ) ;
}
if ( V_57 < 0 )
goto V_335;
V_205 = F_96 ( V_199 ) ;
if ( ! V_205 ) {
strcpy ( V_204 , L_105 ) ;
goto V_335;
}
V_140 = V_205 ;
V_27 = V_140 -> V_141 ;
V_327 = F_117 ( & V_201 , V_151 ) ;
if ( V_202 < 4 )
V_143 = 0 ;
else if ( V_202 < 8 )
V_143 = 1 ;
else
V_143 = 2 ;
if ( ! V_27 -> V_164 && ! V_27 -> V_160 && ! V_27 -> V_165 )
V_101 = V_327 ;
snprintf ( V_204 , sizeof( V_204 ) ,
L_106 ,
V_319 ? L_100 : L_25 ,
( V_321 && V_322 ) ? L_101 : L_25 ,
V_203 ,
V_324 , V_325 ,
V_199 , V_200 ,
V_201 ,
V_202 ) ;
F_6 ( 0 , L_107 , V_204 ) ;
if ( V_101 == V_336 )
V_101 = - 1 ;
F_116 ( V_315 , V_140 , V_323 ,
V_313 -> V_69 >> V_333 , V_313 -> V_69 & ~ V_334 , 0 ,
4 * V_200 + V_101 , V_143 , - 1 ,
V_316 , V_204 ) ;
return;
V_335:
F_116 ( V_315 , V_140 , V_323 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
V_204 , L_25 ) ;
}
static void F_118 ( struct V_139 * V_140 )
{
struct V_26 * V_27 = V_140 -> V_141 ;
int V_70 ;
unsigned V_337 = 0 ;
struct V_312 * V_313 ;
F_119 () ;
V_337 = ( V_27 -> V_338 + V_339 - V_27 -> V_340 )
% V_339 ;
if ( ! V_337 )
return;
V_313 = V_27 -> V_341 ;
if ( V_27 -> V_340 + V_337 > V_339 ) {
unsigned V_342 = V_339 - V_27 -> V_340 ;
memcpy ( V_313 , & V_27 -> V_343 [ V_27 -> V_340 ] , sizeof( * V_313 ) * V_342 ) ;
F_120 () ;
V_27 -> V_340 = 0 ;
V_337 -= V_342 ;
V_313 += V_342 ;
}
memcpy ( V_313 , & V_27 -> V_343 [ V_27 -> V_340 ] , sizeof( * V_313 ) * V_337 ) ;
F_120 () ;
V_27 -> V_340 += V_337 ;
F_119 () ;
if ( V_27 -> V_344 ) {
F_59 ( V_84 , L_108 ,
V_27 -> V_344 ) ;
F_120 () ;
V_27 -> V_344 = 0 ;
}
for ( V_70 = 0 ; V_70 < V_337 ; V_70 ++ )
F_115 ( V_140 , & V_27 -> V_341 [ V_70 ] ) ;
}
static int F_121 ( struct V_345 * V_346 , unsigned long V_347 ,
void * V_348 )
{
struct V_312 * V_312 = (struct V_312 * ) V_348 ;
struct V_139 * V_140 ;
struct V_26 * V_27 ;
char * type ;
if ( F_122 () == V_349 )
return V_350 ;
V_140 = F_96 ( V_312 -> V_351 ) ;
if ( ! V_140 )
return V_350 ;
V_27 = V_140 -> V_141 ;
if ( ( V_312 -> V_320 & 0xefff ) >> 7 != 1 )
return V_350 ;
if ( V_312 -> V_318 & V_352 )
type = L_109 ;
else
type = L_110 ;
F_123 ( V_140 , V_231 , L_111 ) ;
F_123 ( V_140 , V_231 , L_112
L_113 , V_312 -> V_353 , type ,
V_312 -> V_318 , V_312 -> V_331 , V_312 -> V_320 ) ;
F_123 ( V_140 , V_231 , L_114 , V_312 -> V_354 ) ;
F_123 ( V_140 , V_231 , L_115 , V_312 -> V_69 ) ;
F_123 ( V_140 , V_231 , L_116 , V_312 -> V_355 ) ;
F_123 ( V_140 , V_231 , L_117
L_118 , V_312 -> V_356 , V_312 -> V_357 ,
V_312 -> time , V_312 -> V_351 , V_312 -> V_358 ) ;
F_119 () ;
if ( ( V_27 -> V_338 + 1 ) % V_339 == V_27 -> V_340 ) {
F_120 () ;
V_27 -> V_344 ++ ;
return V_350 ;
}
memcpy ( & V_27 -> V_343 [ V_27 -> V_338 ] , V_312 , sizeof( * V_312 ) ) ;
F_120 () ;
V_27 -> V_338 = ( V_27 -> V_338 + 1 ) % V_339 ;
if ( V_312 -> V_318 & 1 )
F_118 ( V_140 ) ;
return V_359 ;
}
static void F_124 ( struct V_17 * V_17 )
{
struct V_139 * V_140 = V_17 -> V_140 ;
struct V_26 * V_27 ;
if ( F_106 ( ! V_140 || ! V_140 -> V_141 ) ) {
F_6 ( 0 , L_119 , & V_17 -> V_24 [ 0 ] -> V_303 ) ;
F_59 ( V_84 , L_120 ) ;
return;
}
V_27 = V_140 -> V_141 ;
F_6 ( 0 , L_121 ,
V_140 , & V_17 -> V_24 [ 0 ] -> V_303 ) ;
F_125 ( V_140 -> V_24 ) ;
F_6 ( 1 , L_122 , V_140 -> V_360 ) ;
F_16 ( V_140 -> V_360 ) ;
F_126 ( V_140 ) ;
V_17 -> V_140 = NULL ;
}
static int F_127 ( struct V_17 * V_17 , enum type type )
{
struct V_139 * V_140 ;
struct V_361 V_170 [ 2 ] ;
struct V_26 * V_27 ;
struct V_71 * V_24 = V_17 -> V_24 [ 0 ] ;
int V_57 ;
V_57 = F_58 ( V_17 -> V_18 , type ) ;
if ( F_106 ( V_57 < 0 ) )
return V_57 ;
V_170 [ 0 ] . type = V_362 ;
V_170 [ 0 ] . V_147 = type == V_13 ?
V_104 : V_151 ;
V_170 [ 0 ] . V_363 = false ;
V_170 [ 1 ] . type = V_364 ;
V_170 [ 1 ] . V_147 = type == V_13 ? 1 : V_365 ;
V_170 [ 1 ] . V_363 = true ;
V_140 = F_128 ( V_17 -> V_87 , F_62 ( V_170 ) , V_170 ,
sizeof( * V_27 ) ) ;
if ( F_106 ( ! V_140 ) )
return - V_235 ;
F_6 ( 0 , L_121 ,
V_140 , & V_24 -> V_303 ) ;
V_27 = V_140 -> V_141 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_17 = V_17 ;
V_17 -> V_140 = V_140 ;
V_140 -> V_366 = type == V_13 ?
V_367 : V_368 ;
V_140 -> V_369 = V_370 ;
V_140 -> V_371 = V_370 ;
V_140 -> V_372 = L_123 ;
V_140 -> V_373 = V_374 ;
V_140 -> V_375 = F_129 ( V_24 ) ;
V_140 -> V_376 = NULL ;
V_140 -> V_377 = F_118 ;
V_27 -> V_36 . type = type ;
switch ( type ) {
case V_76 :
V_27 -> V_36 . V_37 = V_378 ;
V_27 -> V_36 . V_190 = F_25 ;
V_27 -> V_36 . V_192 = F_26 ;
V_27 -> V_36 . V_119 = V_379 ;
V_27 -> V_36 . F_37 = F_37 ;
V_27 -> V_36 . F_45 = F_45 ;
V_27 -> V_36 . F_27 = F_27 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_134 = F_62 ( V_379 ) ;
V_27 -> V_36 . V_136 = V_380 ;
V_27 -> V_36 . V_213 = F_62 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_177 = F_42 ;
V_140 -> V_360 = F_130 ( V_23 , L_124 , V_140 -> V_382 ) ;
V_57 = F_111 ( V_140 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_79 :
V_27 -> V_36 . V_37 = V_384 ;
V_27 -> V_36 . V_190 = F_20 ;
V_27 -> V_36 . V_192 = F_23 ;
V_27 -> V_36 . V_119 = V_385 ;
V_27 -> V_36 . F_37 = F_37 ;
V_27 -> V_36 . F_45 = F_45 ;
V_27 -> V_36 . F_27 = F_27 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_134 = F_62 ( V_385 ) ;
V_27 -> V_36 . V_136 = V_386 ;
V_27 -> V_36 . V_213 = F_62 ( V_386 ) ;
V_27 -> V_36 . V_2 = V_387 ;
V_27 -> V_36 . V_177 = F_40 ;
V_140 -> V_360 = F_130 ( V_23 , L_125 , V_140 -> V_382 ) ;
V_57 = F_110 ( V_140 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_11 :
V_27 -> V_36 . V_190 = F_48 ;
V_27 -> V_36 . V_192 = F_49 ;
V_27 -> V_36 . V_119 = V_379 ;
V_27 -> V_36 . F_37 = F_38 ;
V_27 -> V_36 . F_45 = F_46 ;
V_27 -> V_36 . F_27 = F_52 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_134 = F_62 ( V_379 ) ;
V_27 -> V_36 . V_136 = V_380 ;
V_27 -> V_36 . V_213 = F_62 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_177 = F_42 ;
V_140 -> V_360 = F_130 ( V_23 , L_126 , V_140 -> V_382 ) ;
V_57 = F_112 ( V_140 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_12 :
V_27 -> V_36 . V_190 = F_48 ;
V_27 -> V_36 . V_192 = F_49 ;
V_27 -> V_36 . V_119 = V_379 ;
V_27 -> V_36 . F_37 = F_38 ;
V_27 -> V_36 . F_45 = F_46 ;
V_27 -> V_36 . F_27 = F_52 ;
V_27 -> V_36 . F_28 = F_28 ;
V_27 -> V_36 . F_29 = F_29 ;
V_27 -> V_36 . F_30 = F_30 ;
V_27 -> V_36 . F_31 = F_31 ;
V_27 -> V_36 . V_134 = F_62 ( V_379 ) ;
V_27 -> V_36 . V_136 = V_380 ;
V_27 -> V_36 . V_213 = F_62 ( V_380 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_177 = F_43 ;
V_140 -> V_360 = F_130 ( V_23 , L_127 , V_140 -> V_382 ) ;
V_57 = F_113 ( V_140 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
case V_13 :
V_27 -> V_36 . V_190 = F_50 ;
V_27 -> V_36 . V_192 = F_51 ;
V_27 -> V_36 . V_119 = V_388 ;
V_27 -> V_36 . F_37 = F_44 ;
V_27 -> V_36 . F_45 = F_47 ;
V_27 -> V_36 . F_27 = NULL ;
V_27 -> V_36 . F_28 = F_32 ;
V_27 -> V_36 . F_29 = F_33 ;
V_27 -> V_36 . F_30 = F_34 ;
V_27 -> V_36 . F_31 = F_36 ;
V_27 -> V_36 . V_134 = F_62 ( V_388 ) ;
V_27 -> V_36 . V_136 = V_389 ;
V_27 -> V_36 . V_213 = F_62 ( V_389 ) ;
V_27 -> V_36 . V_2 = V_381 ;
V_27 -> V_36 . V_177 = F_39 ;
V_140 -> V_360 = F_130 ( V_23 ,
L_128 , V_140 -> V_382 ) ;
V_57 = F_114 ( V_140 , V_17 ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_383;
break;
}
F_73 ( V_140 ) ;
F_82 ( V_140 ) ;
V_140 -> V_24 = & V_24 -> V_303 ;
if ( F_106 ( F_131 ( V_140 ) ) ) {
F_6 ( 0 , L_129 ) ;
V_57 = - V_14 ;
goto V_383;
}
return 0 ;
V_383:
F_16 ( V_140 -> V_360 ) ;
F_126 ( V_140 ) ;
V_17 -> V_140 = NULL ;
return V_57 ;
}
static int F_132 ( struct V_71 * V_24 , const struct V_390 * V_72 )
{
int V_57 = - V_83 ;
T_2 V_87 , V_226 = 0 ;
struct V_17 * V_17 ;
enum type type = V_79 ;
F_133 ( & V_391 ) ;
if ( F_106 ( V_392 >= 1 ) ) {
F_134 ( & V_391 ) ;
return - V_83 ;
}
V_392 ++ ;
switch ( V_24 -> V_238 ) {
case V_77 :
V_57 = F_135 ( & V_226 ,
V_393 ) ;
type = V_76 ;
break;
case V_242 :
V_57 = F_135 ( & V_226 ,
V_394 ) ;
type = V_79 ;
break;
case V_270 :
V_57 = F_135 ( & V_226 ,
V_395 ) ;
type = V_11 ;
break;
case V_290 :
V_57 = F_135 ( & V_226 ,
V_396 ) ;
type = V_12 ;
break;
case V_307 :
V_57 = F_136 ( & V_226 ,
V_397 ) ;
type = V_13 ;
break;
}
if ( F_106 ( V_57 < 0 ) ) {
F_6 ( 0 , L_130 , V_24 -> V_238 ) ;
goto V_383;
}
V_87 = 0 ;
F_13 (sbridge_dev, &sbridge_edac_list, list) {
F_6 ( 0 , L_131 ,
V_87 , V_87 + 1 , V_226 ) ;
V_17 -> V_87 = V_87 ++ ;
V_57 = F_127 ( V_17 , type ) ;
if ( F_106 ( V_57 < 0 ) )
goto V_398;
}
F_59 ( V_234 , L_107 , V_374 ) ;
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
static void F_137 ( struct V_71 * V_24 )
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
if ( F_122 () == V_349 )
F_59 ( V_402 , L_132 ) ;
return 0 ;
}
F_59 ( V_84 , L_133 ,
V_399 ) ;
return V_399 ;
}
static void T_5 F_142 ( void )
{
F_6 ( 2 , L_72 ) ;
F_143 ( & V_400 ) ;
F_144 ( & V_401 ) ;
}
