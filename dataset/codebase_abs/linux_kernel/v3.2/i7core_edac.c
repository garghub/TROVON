static inline int F_1 ( T_1 V_1 )
{
return ( V_1 & 0x3 ) + 1 ;
}
static inline int F_2 ( T_1 V_2 )
{
static int V_3 [ 4 ] = { 1 , 2 , 4 , - V_4 } ;
return V_3 [ V_2 & 0x3 ] ;
}
static inline int F_3 ( T_1 V_5 )
{
static int V_6 [ 4 ] = { 4 , 8 , 16 , - V_4 } ;
return V_6 [ V_5 & 0x3 ] ;
}
static inline int F_4 ( T_1 V_7 )
{
static int V_8 [ 8 ] = {
1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , - V_4 , - V_4 , - V_4 ,
} ;
return V_8 [ V_7 & 0x7 ] ;
}
static inline int F_5 ( T_1 V_9 )
{
static int V_10 [ 8 ] = {
1 << 10 , 1 << 11 , 1 << 12 , - V_4 ,
} ;
return V_10 [ V_9 & 0x3 ] ;
}
static struct V_11 * F_6 ( T_2 V_12 )
{
struct V_11 * V_11 ;
F_7 (i7core_dev, &i7core_edac_list, list) {
if ( V_11 -> V_12 == V_12 )
return V_11 ;
}
return NULL ;
}
static struct V_11 * F_8 ( T_2 V_12 ,
const struct V_13 * V_14 )
{
struct V_11 * V_11 ;
V_11 = F_9 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_16 = F_9 ( sizeof( * V_11 -> V_16 ) * V_14 -> V_17 ,
V_15 ) ;
if ( ! V_11 -> V_16 ) {
F_10 ( V_11 ) ;
return NULL ;
}
V_11 -> V_12 = V_12 ;
V_11 -> V_17 = V_14 -> V_17 ;
F_11 ( & V_11 -> V_18 , & V_19 ) ;
return V_11 ;
}
static void F_12 ( struct V_11 * V_11 )
{
F_13 ( & V_11 -> V_18 ) ;
F_10 ( V_11 -> V_16 ) ;
F_10 ( V_11 ) ;
}
static struct V_20 * F_14 ( T_2 V_12 , unsigned V_21 ,
unsigned V_22 )
{
struct V_11 * V_11 = F_6 ( V_12 ) ;
int V_23 ;
if ( ! V_11 )
return NULL ;
for ( V_23 = 0 ; V_23 < V_11 -> V_17 ; V_23 ++ ) {
if ( ! V_11 -> V_16 [ V_23 ] )
continue;
if ( F_15 ( V_11 -> V_16 [ V_23 ] -> V_24 ) == V_21 &&
F_16 ( V_11 -> V_16 [ V_23 ] -> V_24 ) == V_22 ) {
return V_11 -> V_16 [ V_23 ] ;
}
}
return NULL ;
}
static int F_17 ( const T_2 V_12 , unsigned * V_25 ,
unsigned * V_26 )
{
struct V_20 * V_16 = NULL ;
int V_23 , V_27 ;
T_1 V_28 , V_29 ;
* V_25 = 0 ;
* V_26 = 0 ;
V_16 = F_14 ( V_12 , 3 , 0 ) ;
if ( ! V_16 ) {
F_18 ( V_30 , L_1 ,
V_12 ) ;
return - V_31 ;
}
F_19 ( V_16 , V_32 , & V_28 ) ;
F_19 ( V_16 , V_33 , & V_29 ) ;
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
T_1 V_35 [ 3 ] ;
if ( ! ( V_29 & ( 1 << ( 8 + V_23 ) ) ) )
continue;
if ( V_28 & ( 1 << V_23 ) )
continue;
V_16 = F_14 ( V_12 , V_23 + 4 , 1 ) ;
if ( ! V_16 ) {
F_18 ( V_30 , L_2
L_3 ,
V_12 , V_23 + 4 , 1 ) ;
return - V_31 ;
}
F_19 ( V_16 ,
V_36 , & V_35 [ 0 ] ) ;
F_19 ( V_16 ,
V_37 , & V_35 [ 1 ] ) ;
F_19 ( V_16 ,
V_38 , & V_35 [ 2 ] ) ;
( * V_25 ) ++ ;
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ ) {
if ( ! F_20 ( V_35 [ V_27 ] ) )
continue;
( * V_26 ) ++ ;
}
}
F_21 ( L_4 ,
V_12 , * V_25 ) ;
return 0 ;
}
static int F_22 ( const struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_44 * V_45 ;
struct V_20 * V_16 ;
int V_23 , V_27 ;
int V_46 = 0 ;
unsigned long V_47 = 0 ;
enum V_48 V_49 ;
enum V_50 V_51 ;
V_16 = V_42 -> V_52 [ 0 ] ;
if ( ! V_16 )
return - V_31 ;
F_19 ( V_16 , V_33 , & V_42 -> V_53 . V_54 ) ;
F_19 ( V_16 , V_32 , & V_42 -> V_53 . V_55 ) ;
F_19 ( V_16 , V_56 , & V_42 -> V_53 . V_57 ) ;
F_19 ( V_16 , V_58 , & V_42 -> V_53 . V_59 ) ;
F_21 ( L_5 ,
V_42 -> V_11 -> V_12 , V_42 -> V_53 . V_54 , V_42 -> V_53 . V_55 ,
V_42 -> V_53 . V_57 , V_42 -> V_53 . V_59 ) ;
if ( F_23 ( V_42 ) ) {
F_21 ( L_6 , F_24 ( V_42 ) ? 8 : 4 ) ;
if ( F_24 ( V_42 ) )
V_49 = V_60 ;
else
V_49 = V_61 ;
} else {
F_21 ( L_7 ) ;
V_49 = V_62 ;
}
F_21 ( L_8
L_9 ,
F_1 ( V_42 -> V_53 . V_57 ) ,
F_2 ( V_42 -> V_53 . V_57 >> 2 ) ,
F_3 ( V_42 -> V_53 . V_57 >> 4 ) ,
F_4 ( V_42 -> V_53 . V_57 >> 6 ) ,
F_5 ( V_42 -> V_53 . V_57 >> 9 ) ) ;
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
T_1 V_63 , V_35 [ 3 ] , V_64 [ 8 ] ;
if ( ! V_42 -> V_65 [ V_23 ] [ 0 ] )
continue;
if ( ! F_25 ( V_42 , V_23 ) ) {
F_21 ( L_10 , V_23 ) ;
continue;
}
if ( F_26 ( V_42 , V_23 ) ) {
F_21 ( L_11 , V_23 ) ;
continue;
}
F_19 ( V_42 -> V_65 [ V_23 ] [ 0 ] ,
V_66 , & V_63 ) ;
V_42 -> V_67 [ V_23 ] . V_3 = ( V_63 & V_68 ) ?
4 : 2 ;
if ( V_63 & V_69 )
V_51 = V_70 ;
else
V_51 = V_71 ;
#if 0
if (data & THREE_DIMMS_PRESENT)
pvt->channel[i].dimms = 3;
else if (data & SINGLE_QUAD_RANK_PRESENT)
pvt->channel[i].dimms = 1;
else
pvt->channel[i].dimms = 2;
#endif
F_19 ( V_42 -> V_65 [ V_23 ] [ 1 ] ,
V_36 , & V_35 [ 0 ] ) ;
F_19 ( V_42 -> V_65 [ V_23 ] [ 1 ] ,
V_37 , & V_35 [ 1 ] ) ;
F_19 ( V_42 -> V_65 [ V_23 ] [ 1 ] ,
V_38 , & V_35 [ 2 ] ) ;
F_21 ( L_12
L_13 ,
V_23 ,
F_27 ( V_42 -> V_53 . V_59 , V_23 ) , F_28 ( V_42 -> V_53 . V_59 , V_23 ) ,
V_63 ,
V_42 -> V_67 [ V_23 ] . V_3 ,
( V_63 & V_69 ) ? 'R' : 'U' ) ;
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ ) {
T_1 V_6 , V_3 , V_8 , V_10 ;
T_1 V_72 , V_73 ;
if ( ! F_20 ( V_35 [ V_27 ] ) )
continue;
V_6 = F_3 ( F_29 ( V_35 [ V_27 ] ) ) ;
V_3 = F_2 ( F_30 ( V_35 [ V_27 ] ) ) ;
V_8 = F_4 ( F_31 ( V_35 [ V_27 ] ) ) ;
V_10 = F_5 ( F_32 ( V_35 [ V_27 ] ) ) ;
V_72 = ( V_8 * V_10 * V_6 * V_3 ) >> ( 20 - 3 ) ;
V_42 -> V_67 [ V_23 ] . V_1 ++ ;
F_21 ( L_14
L_15 ,
V_27 , V_72 ,
F_33 ( V_35 [ V_27 ] ) ,
V_6 , V_3 , V_8 , V_10 ) ;
V_73 = F_34 ( V_72 ) ;
V_45 = & V_40 -> V_26 [ V_46 ] ;
V_45 -> V_74 = V_47 + 1 ;
V_47 += V_73 ;
V_45 -> V_47 = V_47 ;
V_45 -> V_75 = V_73 ;
V_45 -> V_76 = 0 ;
V_45 -> V_77 = 8 ;
V_45 -> V_78 = V_46 ;
V_45 -> V_79 = 1 ;
V_45 -> V_25 [ 0 ] . V_80 = V_23 ;
V_45 -> V_25 [ 0 ] . V_81 = 0 ;
V_42 -> V_82 [ V_23 ] [ V_27 ] = V_46 ;
switch ( V_6 ) {
case 4 :
V_45 -> V_83 = V_84 ;
break;
case 8 :
V_45 -> V_83 = V_85 ;
break;
case 16 :
V_45 -> V_83 = V_86 ;
break;
default:
V_45 -> V_83 = V_87 ;
}
V_45 -> V_88 = V_49 ;
V_45 -> V_51 = V_51 ;
snprintf ( V_45 -> V_25 [ 0 ] . V_89 ,
sizeof( V_45 -> V_25 [ 0 ] . V_89 ) ,
L_16 ,
V_42 -> V_11 -> V_12 , V_23 , V_27 ) ;
V_46 ++ ;
}
F_19 ( V_16 , V_90 , & V_64 [ 0 ] ) ;
F_19 ( V_16 , V_91 , & V_64 [ 1 ] ) ;
F_19 ( V_16 , V_92 , & V_64 [ 2 ] ) ;
F_19 ( V_16 , V_93 , & V_64 [ 3 ] ) ;
F_19 ( V_16 , V_94 , & V_64 [ 4 ] ) ;
F_19 ( V_16 , V_95 , & V_64 [ 5 ] ) ;
F_19 ( V_16 , V_96 , & V_64 [ 6 ] ) ;
F_19 ( V_16 , V_97 , & V_64 [ 7 ] ) ;
F_35 ( L_17 , V_23 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_35 ( L_18 ,
( V_64 [ V_27 ] >> 27 ) & 0x1 ,
( V_64 [ V_27 ] >> 24 ) & 0x7 ,
( V_64 [ V_27 ] & ( ( 1 << 24 ) - 1 ) ) ) ;
}
return 0 ;
}
static int F_36 ( const struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
V_42 -> V_98 . V_99 = 0 ;
if ( ! V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] )
return - V_31 ;
F_37 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_100 , 0 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_101 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_102 ;
if ( V_42 -> V_98 . V_99 )
F_36 ( V_40 ) ;
V_102 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( ( V_102 < 0 ) || ( V_64 > 3 ) )
return - V_103 ;
V_42 -> V_98 . V_104 = ( T_1 ) V_64 ;
return V_101 ;
}
static T_3 F_40 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_19 , V_42 -> V_98 . V_104 ) ;
}
static T_3 F_41 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_101 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_102 ;
if ( V_42 -> V_98 . V_99 )
F_36 ( V_40 ) ;
V_102 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( ( V_102 < 0 ) || ( V_64 > 7 ) )
return - V_103 ;
V_42 -> V_98 . type = ( T_1 ) V_64 ;
return V_101 ;
}
static T_3 F_42 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_19 , V_42 -> V_98 . type ) ;
}
static T_3 F_43 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_101 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_102 ;
if ( V_42 -> V_98 . V_99 )
F_36 ( V_40 ) ;
V_102 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( V_102 < 0 )
return - V_103 ;
V_42 -> V_98 . V_105 = ( T_1 ) V_64 ;
return V_101 ;
}
static T_3 F_44 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_19 , V_42 -> V_98 . V_105 ) ;
}
static int F_45 ( struct V_20 * V_106 , const int V_107 , const T_1 V_108 )
{
T_1 V_109 ;
int V_101 ;
F_21 ( L_20 ,
V_106 -> V_110 -> V_111 , F_15 ( V_106 -> V_24 ) , F_16 ( V_106 -> V_24 ) ,
V_107 , V_108 ) ;
for ( V_101 = 0 ; V_101 < 10 ; V_101 ++ ) {
if ( V_101 )
F_46 ( 100 ) ;
F_37 ( V_106 , V_107 , V_108 ) ;
F_19 ( V_106 , V_107 , & V_109 ) ;
if ( V_109 == V_108 )
return 0 ;
}
F_18 ( V_30 , L_21
L_22 ,
V_106 -> V_110 -> V_111 , F_15 ( V_106 -> V_24 ) , F_16 ( V_106 -> V_24 ) ,
V_107 , V_108 , V_109 ) ;
return - V_4 ;
}
static T_3 F_47 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_101 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_112 ;
T_5 V_113 = 0 ;
int V_102 ;
long V_99 ;
if ( ! V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] )
return 0 ;
V_102 = F_39 ( V_63 , 10 , & V_99 ) ;
if ( ( V_102 < 0 ) )
return 0 ;
if ( V_99 ) {
V_42 -> V_98 . V_99 = 1 ;
} else {
F_36 ( V_40 ) ;
return V_101 ;
}
if ( V_42 -> V_98 . V_114 < 0 )
V_113 |= 1LL << 41 ;
else {
if ( V_42 -> V_67 [ V_42 -> V_98 . V_67 ] . V_1 > 2 )
V_113 |= ( V_42 -> V_98 . V_114 & 0x3LL ) << 35 ;
else
V_113 |= ( V_42 -> V_98 . V_114 & 0x1LL ) << 36 ;
}
if ( V_42 -> V_98 . V_2 < 0 )
V_113 |= 1LL << 40 ;
else {
if ( V_42 -> V_67 [ V_42 -> V_98 . V_67 ] . V_1 > 2 )
V_113 |= ( V_42 -> V_98 . V_2 & 0x1LL ) << 34 ;
else
V_113 |= ( V_42 -> V_98 . V_2 & 0x3LL ) << 34 ;
}
if ( V_42 -> V_98 . V_5 < 0 )
V_113 |= 1LL << 39 ;
else
V_113 |= ( V_42 -> V_98 . V_5 & 0x15LL ) << 30 ;
if ( V_42 -> V_98 . V_115 < 0 )
V_113 |= 1LL << 38 ;
else
V_113 |= ( V_42 -> V_98 . V_115 & 0xffff ) << 14 ;
if ( V_42 -> V_98 . V_9 < 0 )
V_113 |= 1LL << 37 ;
else
V_113 |= ( V_42 -> V_98 . V_9 & 0x3fff ) ;
V_112 = ( V_42 -> V_98 . type & 1 ) |
( V_42 -> V_98 . V_104 & 0x3 ) << 1 |
( V_42 -> V_98 . type & 0x6 ) << ( 3 - 1 ) ;
F_37 ( V_42 -> V_116 ,
V_117 , 0x2 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_118 , V_113 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_118 + 4 , V_113 >> 32L ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_119 , V_42 -> V_98 . V_105 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_100 , V_112 ) ;
F_37 ( V_42 -> V_116 ,
V_117 , 8 ) ;
F_21 ( L_23
L_24 ,
V_113 , V_42 -> V_98 . V_105 , V_112 ) ;
return V_101 ;
}
static T_3 F_48 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_112 ;
if ( ! V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] )
return 0 ;
F_19 ( V_42 -> V_65 [ V_42 -> V_98 . V_67 ] [ 0 ] ,
V_100 , & V_112 ) ;
F_21 ( L_25 , V_112 ) ;
if ( V_112 & 0x0c )
V_42 -> V_98 . V_99 = 1 ;
return sprintf ( V_63 , L_26 , V_42 -> V_98 . V_99 ) ;
}
static void F_49 ( struct V_11 * V_11 )
{
int V_23 ;
F_21 ( __FILE__ L_27 , V_120 ) ;
for ( V_23 = 0 ; V_23 < V_11 -> V_17 ; V_23 ++ ) {
struct V_20 * V_16 = V_11 -> V_16 [ V_23 ] ;
if ( ! V_16 )
continue;
F_21 ( L_28 ,
V_16 -> V_110 -> V_111 ,
F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ) ;
F_50 ( V_16 ) ;
}
}
static void F_51 ( void )
{
struct V_11 * V_11 , * V_121 ;
F_52 (i7core_dev, tmp, &i7core_edac_list, list) {
F_49 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
static void T_6 F_53 ( const struct V_13 * V_14 )
{
struct V_20 * V_16 = NULL ;
int V_23 ;
while ( V_14 && V_14 -> V_122 ) {
V_16 = F_54 ( V_123 , V_14 -> V_122 [ 0 ] . V_124 , NULL ) ;
if ( F_55 ( ! V_16 ) ) {
for ( V_23 = 0 ; V_23 < V_125 ; V_23 ++ )
F_56 ( 255 - V_23 ) ;
}
F_50 ( V_16 ) ;
V_14 ++ ;
}
}
static unsigned F_57 ( void )
{
int V_126 = 0 , V_110 ;
struct V_127 * V_128 = NULL ;
while ( ( V_128 = F_58 ( V_128 ) ) != NULL ) {
V_110 = V_128 -> V_111 ;
F_21 ( L_29 , V_110 ) ;
if ( V_110 > V_126 )
V_126 = V_110 ;
}
F_21 ( L_30 , V_126 ) ;
return V_126 ;
}
static int F_59 ( struct V_20 * * V_129 ,
const struct V_13 * V_14 ,
const unsigned V_130 ,
const unsigned V_126 )
{
struct V_11 * V_11 ;
const struct V_131 * V_132 = & V_14 -> V_122 [ V_130 ] ;
struct V_20 * V_16 = NULL ;
T_2 V_110 = 0 ;
T_2 V_12 = 0 ;
V_16 = F_54 ( V_123 ,
V_132 -> V_124 , * V_129 ) ;
if ( V_132 -> V_124 == V_133 && ! V_16 )
V_16 = F_54 ( V_123 ,
V_134 , * V_129 ) ;
if ( V_132 -> V_124 == V_135 && ! V_16 )
V_16 = F_54 ( V_123 ,
V_136 ,
* V_129 ) ;
if ( ! V_16 ) {
if ( * V_129 ) {
* V_129 = V_16 ;
return 0 ;
}
if ( V_132 -> V_137 )
return 0 ;
if ( V_130 == 0 )
return - V_31 ;
F_18 ( V_138 ,
L_31 ,
V_132 -> V_106 , V_132 -> V_22 ,
V_123 , V_132 -> V_124 ) ;
return - V_31 ;
}
V_110 = V_16 -> V_110 -> V_111 ;
V_12 = V_126 - V_110 ;
V_11 = F_6 ( V_12 ) ;
if ( ! V_11 ) {
V_11 = F_8 ( V_12 , V_14 ) ;
if ( ! V_11 ) {
F_50 ( V_16 ) ;
return - V_139 ;
}
}
if ( V_11 -> V_16 [ V_130 ] ) {
F_18 ( V_30 ,
L_32
L_33 ,
V_110 , V_132 -> V_106 , V_132 -> V_22 ,
V_123 , V_132 -> V_124 ) ;
F_50 ( V_16 ) ;
return - V_31 ;
}
V_11 -> V_16 [ V_130 ] = V_16 ;
if ( F_55 ( F_15 ( V_16 -> V_24 ) != V_132 -> V_106 ||
F_16 ( V_16 -> V_24 ) != V_132 -> V_22 ) ) {
F_18 ( V_30 ,
L_34
L_35 ,
V_123 , V_132 -> V_124 ,
V_110 , F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ,
V_110 , V_132 -> V_106 , V_132 -> V_22 ) ;
return - V_31 ;
}
if ( F_55 ( F_60 ( V_16 ) < 0 ) ) {
F_18 ( V_30 ,
L_36
L_33 ,
V_110 , V_132 -> V_106 , V_132 -> V_22 ,
V_123 , V_132 -> V_124 ) ;
return - V_31 ;
}
F_21 ( L_37 ,
V_12 , V_110 , V_132 -> V_106 ,
V_132 -> V_22 ,
V_123 , V_132 -> V_124 ) ;
F_61 ( V_16 ) ;
* V_129 = V_16 ;
return 0 ;
}
static int F_62 ( void )
{
int V_23 , V_102 , V_126 ;
struct V_20 * V_16 = NULL ;
const struct V_13 * V_14 = V_140 ;
V_126 = F_57 () ;
while ( V_14 && V_14 -> V_122 ) {
for ( V_23 = 0 ; V_23 < V_14 -> V_17 ; V_23 ++ ) {
V_16 = NULL ;
do {
V_102 = F_59 ( & V_16 , V_14 , V_23 ,
V_126 ) ;
if ( V_102 < 0 ) {
if ( V_23 == 0 ) {
V_23 = V_14 -> V_17 ;
break;
}
F_51 () ;
return - V_31 ;
}
} while ( V_16 );
}
V_14 ++ ;
}
return 0 ;
}
static int F_63 ( struct V_39 * V_40 ,
struct V_11 * V_11 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_20 * V_16 ;
int V_23 , V_22 , V_21 ;
char * V_141 ;
V_42 -> V_142 = false ;
V_42 -> V_143 = false ;
for ( V_23 = 0 ; V_23 < V_11 -> V_17 ; V_23 ++ ) {
V_16 = V_11 -> V_16 [ V_23 ] ;
if ( ! V_16 )
continue;
V_22 = F_16 ( V_16 -> V_24 ) ;
V_21 = F_15 ( V_16 -> V_24 ) ;
if ( V_21 == 3 ) {
if ( F_55 ( V_22 > V_144 ) )
goto error;
V_42 -> V_52 [ V_22 ] = V_16 ;
} else if ( F_64 ( V_21 >= 4 && V_21 < 4 + V_34 ) ) {
if ( F_55 ( V_22 > V_145 ) )
goto error;
V_42 -> V_65 [ V_21 - 4 ] [ V_22 ] = V_16 ;
} else if ( ! V_21 && ! V_22 ) {
V_42 -> V_116 = V_16 ;
switch ( V_16 -> V_146 ) {
case V_133 :
V_141 = L_38 ;
V_42 -> V_143 = false ;
break;
case V_136 :
V_141 = L_39 ;
V_42 -> V_143 = false ;
break;
case V_135 :
V_141 = L_40 ;
V_42 -> V_143 = false ;
break;
case V_134 :
V_141 = L_41 ;
V_42 -> V_143 = true ;
break;
case V_147 :
V_141 = L_42 ;
V_42 -> V_143 = true ;
break;
default:
V_141 = L_43 ;
V_42 -> V_143 = false ;
}
F_21 ( L_44 , V_141 ) ;
} else
goto error;
F_21 ( L_45 ,
F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ,
V_16 , V_11 -> V_12 ) ;
if ( F_15 ( V_16 -> V_24 ) == 3 &&
F_16 ( V_16 -> V_24 ) == 2 )
V_42 -> V_142 = true ;
}
return 0 ;
error:
F_18 ( V_30 , L_46
L_47 ,
V_21 , V_22 ) ;
return - V_4 ;
}
static void F_65 ( struct V_39 * V_40 ,
const int V_148 ,
const int V_114 ,
const int V_149 )
{
char * V_150 ;
struct V_41 * V_42 = V_40 -> V_43 ;
int V_7 = V_42 -> V_82 [ V_148 ] [ V_114 ] , V_23 ;
for ( V_23 = 0 ; V_23 < V_149 ; V_23 ++ ) {
V_150 = F_66 ( V_15 , L_48
L_49 ,
V_42 -> V_11 -> V_12 , V_148 , V_114 ) ;
F_67 ( V_40 , V_7 , 0 , V_150 ) ;
F_10 ( V_150 ) ;
}
}
static void F_68 ( struct V_39 * V_40 ,
const int V_148 ,
const int V_151 ,
const int V_152 ,
const int V_153 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
int V_154 = 0 , V_155 = 0 , V_156 = 0 ;
if ( V_42 -> V_157 ) {
V_156 = V_153 - V_42 -> V_158 [ V_148 ] [ 2 ] ;
V_155 = V_152 - V_42 -> V_158 [ V_148 ] [ 1 ] ;
V_154 = V_151 - V_42 -> V_158 [ V_148 ] [ 0 ] ;
if ( V_156 < 0 )
V_156 += 0x7fff ;
V_42 -> V_159 [ V_148 ] [ 2 ] += V_156 ;
if ( V_155 < 0 )
V_155 += 0x7fff ;
V_42 -> V_159 [ V_148 ] [ 1 ] += V_155 ;
if ( V_154 < 0 )
V_154 += 0x7fff ;
V_42 -> V_159 [ V_148 ] [ 0 ] += V_154 ;
} else
V_42 -> V_157 = 1 ;
V_42 -> V_158 [ V_148 ] [ 2 ] = V_153 ;
V_42 -> V_158 [ V_148 ] [ 1 ] = V_152 ;
V_42 -> V_158 [ V_148 ] [ 0 ] = V_151 ;
if ( V_154 != 0 )
F_65 ( V_40 , V_148 , 0 , V_154 ) ;
if ( V_155 != 0 )
F_65 ( V_40 , V_148 , 1 , V_155 ) ;
if ( V_156 != 0 )
F_65 ( V_40 , V_148 , 2 , V_156 ) ;
}
static void F_69 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_160 [ 3 ] [ 2 ] ;
int V_23 , V_151 , V_152 , V_153 ;
F_19 ( V_42 -> V_52 [ 2 ] , V_161 ,
& V_160 [ 0 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_162 ,
& V_160 [ 0 ] [ 1 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_163 ,
& V_160 [ 1 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_164 ,
& V_160 [ 1 ] [ 1 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_165 ,
& V_160 [ 2 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_166 ,
& V_160 [ 2 ] [ 1 ] ) ;
for ( V_23 = 0 ; V_23 < 3 ; V_23 ++ ) {
F_70 ( L_50 ,
( V_23 * 2 ) , V_160 [ V_23 ] [ 0 ] , ( V_23 * 2 ) + 1 , V_160 [ V_23 ] [ 1 ] ) ;
if ( V_42 -> V_67 [ V_23 ] . V_1 > 2 ) {
V_151 = F_71 ( V_160 [ V_23 ] [ 0 ] ) ;
V_152 = F_72 ( V_160 [ V_23 ] [ 0 ] ) ;
V_153 = F_71 ( V_160 [ V_23 ] [ 1 ] ) ;
} else {
V_151 = F_72 ( V_160 [ V_23 ] [ 0 ] ) +
F_71 ( V_160 [ V_23 ] [ 0 ] ) ;
V_152 = F_72 ( V_160 [ V_23 ] [ 1 ] ) +
F_71 ( V_160 [ V_23 ] [ 1 ] ) ;
V_153 = 0 ;
}
F_68 ( V_40 , V_23 , V_151 , V_152 , V_153 ) ;
}
}
static void F_73 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_167 , V_168 ;
int V_151 , V_152 , V_153 ;
if ( ! V_42 -> V_52 [ 4 ] ) {
F_21 ( L_51 , V_120 ) ;
return;
}
F_19 ( V_42 -> V_52 [ 4 ] , V_169 , & V_167 ) ;
F_19 ( V_42 -> V_52 [ 4 ] , V_170 , & V_168 ) ;
V_153 = F_74 ( V_167 ) ;
V_152 = F_75 ( V_168 ) ;
V_151 = F_76 ( V_168 ) ;
if ( V_42 -> V_157 ) {
int V_154 , V_155 , V_156 ;
V_156 = V_153 - V_42 -> V_171 [ 2 ] ;
V_155 = V_152 - V_42 -> V_171 [ 1 ] ;
V_154 = V_151 - V_42 -> V_171 [ 0 ] ;
if ( V_156 < 0 )
V_156 += 0x7fff ;
V_42 -> V_172 [ 2 ] += V_156 ;
if ( V_155 < 0 )
V_155 += 0x7fff ;
V_42 -> V_172 [ 1 ] += V_155 ;
if ( V_154 < 0 )
V_154 += 0x7fff ;
V_42 -> V_172 [ 0 ] += V_154 ;
if ( V_154 | V_155 | V_156 )
F_18 ( V_30 , L_52
L_53 ,
V_154 , V_155 , V_156 ) ;
} else
V_42 -> V_157 = 1 ;
V_42 -> V_171 [ 2 ] = V_153 ;
V_42 -> V_171 [ 1 ] = V_152 ;
V_42 -> V_171 [ 0 ] = V_151 ;
}
static void F_77 ( struct V_39 * V_40 ,
const struct V_173 * V_174 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
char * type , * V_175 , * V_176 , * V_150 ;
unsigned long error = V_174 -> V_28 & 0x1ff0000l ;
T_1 V_177 = ( V_174 -> V_28 >> 4 ) & 0x07 ;
T_1 V_178 = ( V_174 -> V_28 >> 38 ) & 0x7fff ;
T_1 V_114 = ( V_174 -> V_179 >> 16 ) & 0x3 ;
T_1 V_67 = ( V_174 -> V_179 >> 18 ) & 0x3 ;
T_1 V_180 = V_174 -> V_179 >> 32 ;
T_1 V_181 = F_78 ( & error , 32 ) ;
int V_46 ;
if ( V_174 -> V_182 & 1 )
type = L_54 ;
else
type = L_55 ;
switch ( V_177 ) {
case 0 :
V_175 = L_56 ;
break;
case 1 :
V_175 = L_57 ;
break;
case 2 :
V_175 = L_58 ;
break;
case 3 :
V_175 = L_59 ;
break;
case 4 :
V_175 = L_60 ;
break;
default:
V_175 = L_61 ;
break;
}
switch ( V_181 ) {
case 16 :
V_176 = L_62 ;
break;
case 17 :
V_176 = L_63 ;
break;
case 18 :
V_176 = L_64 ;
break;
case 19 :
V_176 = L_65 ;
break;
case 20 :
V_176 = L_61 ;
break;
case 21 :
V_176 = L_66 ;
break;
case 22 :
V_176 = L_67 ;
break;
case 23 :
V_176 = L_68 ;
break;
case 24 :
V_176 = L_69 ;
break;
default:
V_176 = L_43 ;
}
V_150 = F_66 ( V_183 ,
L_70
L_71 ,
type , ( long long ) V_174 -> V_184 , V_174 -> V_185 , V_114 , V_67 ,
V_180 , V_178 , ( long long ) V_174 -> V_28 ,
( long long ) V_174 -> V_179 , V_175 , V_176 ) ;
F_21 ( L_72 , V_150 ) ;
V_46 = V_42 -> V_82 [ V_67 ] [ V_114 ] ;
if ( V_174 -> V_182 & 1 )
F_79 ( V_40 , V_46 , 0 ,
0 , V_150 ) ;
else if ( ! V_42 -> V_142 )
F_67 ( V_40 , V_46 ,
0 , V_150 ) ;
F_10 ( V_150 ) ;
}
static void F_80 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
int V_23 ;
unsigned V_101 = 0 ;
struct V_173 * V_174 ;
F_81 () ;
V_101 = ( V_42 -> V_186 + V_187 - V_42 -> V_188 )
% V_187 ;
if ( ! V_101 )
goto V_189;
V_174 = V_42 -> V_190 ;
if ( V_42 -> V_188 + V_101 > V_187 ) {
unsigned V_191 = V_187 - V_42 -> V_188 ;
memcpy ( V_174 , & V_42 -> V_192 [ V_42 -> V_188 ] , sizeof( * V_174 ) * V_191 ) ;
F_82 () ;
V_42 -> V_188 = 0 ;
V_101 -= V_191 ;
V_174 += V_191 ;
}
memcpy ( V_174 , & V_42 -> V_192 [ V_42 -> V_188 ] , sizeof( * V_174 ) * V_101 ) ;
F_82 () ;
V_42 -> V_188 += V_101 ;
F_81 () ;
if ( V_42 -> V_193 ) {
F_18 ( V_30 , L_73 ,
V_42 -> V_193 ) ;
F_82 () ;
V_42 -> V_193 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_101 ; V_23 ++ )
F_77 ( V_40 , & V_42 -> V_190 [ V_23 ] ) ;
V_189:
if ( ! V_42 -> V_142 )
F_73 ( V_40 ) ;
else
F_69 ( V_40 ) ;
}
static int F_83 ( struct V_194 * V_195 , unsigned long V_108 ,
void * V_63 )
{
struct V_173 * V_173 = (struct V_173 * ) V_63 ;
struct V_11 * V_196 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_196 = F_6 ( V_173 -> V_197 ) ;
if ( ! V_196 )
return V_198 ;
V_40 = V_196 -> V_40 ;
V_42 = V_40 -> V_43 ;
if ( ( ( V_173 -> V_28 & 0xffff ) >> 7 ) != 1 )
return V_199 ;
if ( V_173 -> V_5 != 8 )
return V_199 ;
#ifdef F_84
if ( V_173 -> V_197 != V_42 -> V_11 -> V_12 )
return V_199 ;
#endif
F_81 () ;
if ( ( V_42 -> V_186 + 1 ) % V_187 == V_42 -> V_188 ) {
F_82 () ;
V_42 -> V_193 ++ ;
return V_199 ;
}
memcpy ( & V_42 -> V_192 [ V_42 -> V_186 ] , V_173 , sizeof( * V_173 ) ) ;
F_82 () ;
V_42 -> V_186 = ( V_42 -> V_186 + 1 ) % V_187 ;
if ( V_173 -> V_182 & 1 )
F_80 ( V_40 ) ;
return V_200 ;
}
static void F_85 ( const struct V_201 * V_202 , void * V_203 )
{
int * V_204 = V_203 ;
T_7 V_205 ;
if ( * V_204 == - 1 )
return;
if ( V_202 -> type == V_206 ) {
struct V_207 * V_207 =
(struct V_207 * ) V_202 ;
unsigned long V_208 =
( unsigned long ) & V_207 -> V_209 -
( unsigned long ) & V_207 -> type ;
unsigned long V_210 =
( unsigned long ) & V_207 -> V_211 -
( unsigned long ) & V_207 -> type ;
if ( V_207 -> V_72 == 0 )
return;
if ( V_207 -> V_212 > V_208 ) {
V_205 =
V_207 -> V_209 ;
} else if ( V_207 -> V_212 > V_210 ) {
V_205 = V_207 -> V_211 ;
} else {
* V_204 = - 1 ;
return;
}
if ( * V_204 == 0 ) {
if ( V_205 > 0 ) {
* V_204 = V_205 ;
} else {
* V_204 = - 1 ;
}
} else if ( * V_204 > 0 &&
* V_204 != V_205 ) {
* V_204 = - 1 ;
}
}
}
static int F_86 ( void )
{
int V_204 = 0 ;
F_87 ( F_85 , ( void * ) & V_204 ) ;
if ( V_204 < 1 )
return V_213 ;
return V_204 ;
}
static int F_88 ( struct V_39 * V_40 , T_1 V_214 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_20 * V_16 ;
T_1 V_215 ;
T_1 V_216 ;
V_16 = V_42 -> V_52 [ 2 ] ;
if ( ! V_16 )
return - V_31 ;
F_19 ( V_16 , V_217 , & V_215 ) ;
if ( V_214 == 0 ) {
V_215 &= ~ V_218 ;
F_45 ( V_16 , V_217 ,
V_215 & ~ V_219 ) ;
F_19 ( V_16 , V_220 , & V_216 ) ;
V_216 &= ~ V_221 ;
V_216 |= V_222 ;
} else {
const int V_223 = 64 ;
const T_1 V_224 = V_42 -> V_204 ;
unsigned long long V_225 ;
V_225 = ( unsigned long long ) V_224 *
V_223 * 1000000 ;
F_89 ( V_225 , V_214 ) ;
if ( ! V_225 || V_225 > V_219 )
return - V_4 ;
V_215 = V_219 & V_225 ;
F_37 ( V_16 , V_217 ,
V_218 | V_215 ) ;
F_19 ( V_16 , V_220 , & V_216 ) ;
V_216 &= ~ V_221 ;
V_216 |= V_226 ;
}
F_37 ( V_16 , V_220 , V_216 ) ;
return V_214 ;
}
static int F_90 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_20 * V_16 ;
const T_1 V_223 = 64 ;
const T_1 V_224 = V_42 -> V_204 ;
unsigned long long V_227 ;
T_1 V_228 ;
V_16 = V_42 -> V_52 [ 2 ] ;
if ( ! V_16 )
return - V_31 ;
F_19 ( V_16 , V_217 , & V_228 ) ;
V_228 &= V_219 ;
if ( ! V_228 )
return 0 ;
V_227 = ( unsigned long long ) V_224 *
1000000 * V_223 ;
F_89 ( V_227 , V_228 ) ;
return ( int ) V_227 ;
}
static void F_91 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_229 ;
F_19 ( V_42 -> V_116 , V_117 , & V_229 ) ;
V_229 &= ~ 0x3 ;
F_37 ( V_42 -> V_116 , V_117 ,
V_229 | V_230 ) ;
V_40 -> F_88 = F_88 ;
V_40 -> F_90 = F_90 ;
}
static void F_92 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_229 ;
F_19 ( V_42 -> V_116 , V_117 , & V_229 ) ;
V_229 &= ~ 0x3 ;
F_37 ( V_42 -> V_116 , V_117 ,
V_229 | V_231 ) ;
}
static void F_93 ( struct V_41 * V_42 )
{
V_42 -> V_232 = F_94 (
& V_42 -> V_11 -> V_16 [ 0 ] -> V_106 ,
V_233 ) ;
if ( F_55 ( ! V_42 -> V_232 ) )
F_18 ( V_234 ,
L_74 ) ;
}
static void F_95 ( struct V_41 * V_42 )
{
if ( F_64 ( V_42 -> V_232 ) )
F_96 ( V_42 -> V_232 ) ;
else
F_18 ( V_30 ,
L_75 ,
V_42 -> V_11 -> V_12 ) ;
V_42 -> V_232 = NULL ;
}
static void F_97 ( struct V_11 * V_11 )
{
struct V_39 * V_40 = V_11 -> V_40 ;
struct V_41 * V_42 ;
if ( F_55 ( ! V_40 || ! V_40 -> V_43 ) ) {
F_21 ( L_76 __FILE__ L_77 ,
V_120 , & V_11 -> V_16 [ 0 ] -> V_106 ) ;
F_18 ( V_30 , L_78 ) ;
return;
}
V_42 = V_40 -> V_43 ;
F_21 ( L_76 __FILE__ L_79 ,
V_120 , V_40 , & V_11 -> V_16 [ 0 ] -> V_106 ) ;
if ( V_42 -> V_143 )
F_92 ( V_40 ) ;
F_98 ( & V_235 , & V_236 ) ;
F_95 ( V_42 ) ;
F_99 ( V_40 -> V_106 ) ;
F_35 ( L_80 , V_40 -> V_237 ) ;
F_10 ( V_40 -> V_237 ) ;
F_100 ( V_40 ) ;
V_11 -> V_40 = NULL ;
}
static int F_101 ( struct V_11 * V_11 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_102 , V_25 , V_26 ;
V_102 = F_17 ( V_11 -> V_12 , & V_25 , & V_26 ) ;
if ( F_55 ( V_102 < 0 ) )
return V_102 ;
V_40 = F_102 ( sizeof( * V_42 ) , V_26 , V_25 , V_11 -> V_12 ) ;
if ( F_55 ( ! V_40 ) )
return - V_139 ;
F_21 ( L_76 __FILE__ L_79 ,
V_120 , V_40 , & V_11 -> V_16 [ 0 ] -> V_106 ) ;
V_42 = V_40 -> V_43 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_11 = V_11 ;
V_11 -> V_40 = V_40 ;
V_40 -> V_238 = V_239 ;
V_40 -> V_240 = V_241 ;
V_40 -> V_242 = V_241 ;
V_40 -> V_243 = L_81 ;
V_40 -> V_244 = V_245 ;
V_40 -> V_237 = F_66 ( V_15 , L_82 ,
V_11 -> V_12 ) ;
V_40 -> V_246 = F_103 ( V_11 -> V_16 [ 0 ] ) ;
V_40 -> V_247 = NULL ;
V_102 = F_63 ( V_40 , V_11 ) ;
if ( F_55 ( V_102 < 0 ) )
goto V_248;
if ( V_42 -> V_142 )
V_40 -> V_249 = V_250 ;
else
V_40 -> V_249 = V_251 ;
F_22 ( V_40 ) ;
V_40 -> V_106 = & V_11 -> V_16 [ 0 ] -> V_106 ;
V_40 -> V_252 = F_80 ;
if ( V_42 -> V_143 )
F_91 ( V_40 ) ;
if ( F_55 ( F_104 ( V_40 ) ) ) {
F_21 ( L_76 __FILE__
L_83 , V_120 ) ;
V_102 = - V_4 ;
goto V_248;
}
V_42 -> V_98 . V_67 = 0 ;
V_42 -> V_98 . V_114 = - 1 ;
V_42 -> V_98 . V_2 = - 1 ;
V_42 -> V_98 . V_5 = - 1 ;
V_42 -> V_98 . V_115 = - 1 ;
V_42 -> V_98 . V_9 = - 1 ;
F_93 ( V_42 ) ;
V_42 -> V_204 = F_86 () ;
F_105 ( & V_235 , & V_236 ) ;
return 0 ;
V_248:
F_10 ( V_40 -> V_237 ) ;
F_100 ( V_40 ) ;
V_11 -> V_40 = NULL ;
return V_102 ;
}
static int T_8 F_106 ( struct V_20 * V_16 ,
const struct V_253 * V_254 )
{
int V_102 , V_101 = 0 ;
struct V_11 * V_11 ;
F_107 ( & V_255 ) ;
if ( F_55 ( V_256 >= 1 ) ) {
F_108 ( & V_255 ) ;
return - V_31 ;
}
V_256 ++ ;
V_102 = F_62 () ;
if ( F_55 ( V_102 < 0 ) )
goto V_248;
F_7 (i7core_dev, &i7core_edac_list, list) {
V_101 ++ ;
V_102 = F_101 ( V_11 ) ;
if ( F_55 ( V_102 < 0 ) )
goto V_257;
}
if ( ! V_101 ) {
V_102 = - V_31 ;
goto V_257;
}
F_18 ( V_138 ,
L_84 ,
V_101 ) ;
F_108 ( & V_255 ) ;
return 0 ;
V_257:
F_7 (i7core_dev, &i7core_edac_list, list)
F_97 ( V_11 ) ;
F_51 () ;
V_248:
F_108 ( & V_255 ) ;
return V_102 ;
}
static void T_9 F_109 ( struct V_20 * V_16 )
{
struct V_11 * V_11 ;
F_21 ( __FILE__ L_27 , V_120 ) ;
F_107 ( & V_255 ) ;
if ( F_55 ( ! V_256 ) ) {
F_108 ( & V_255 ) ;
return;
}
F_7 (i7core_dev, &i7core_edac_list, list)
F_97 ( V_11 ) ;
F_51 () ;
V_256 -- ;
F_108 ( & V_255 ) ;
}
static int T_6 F_110 ( void )
{
int V_258 ;
F_111 ( L_76 __FILE__ L_27 , V_120 ) ;
F_112 () ;
if ( V_259 )
F_53 ( V_140 ) ;
V_258 = F_113 ( & V_260 ) ;
if ( V_258 >= 0 )
return 0 ;
F_18 ( V_30 , L_85 ,
V_258 ) ;
return V_258 ;
}
static void T_10 F_114 ( void )
{
F_111 ( L_76 __FILE__ L_27 , V_120 ) ;
F_115 ( & V_260 ) ;
}
