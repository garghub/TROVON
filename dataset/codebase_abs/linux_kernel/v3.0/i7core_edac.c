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
V_46 ++ ;
}
F_19 ( V_16 , V_89 , & V_64 [ 0 ] ) ;
F_19 ( V_16 , V_90 , & V_64 [ 1 ] ) ;
F_19 ( V_16 , V_91 , & V_64 [ 2 ] ) ;
F_19 ( V_16 , V_92 , & V_64 [ 3 ] ) ;
F_19 ( V_16 , V_93 , & V_64 [ 4 ] ) ;
F_19 ( V_16 , V_94 , & V_64 [ 5 ] ) ;
F_19 ( V_16 , V_95 , & V_64 [ 6 ] ) ;
F_19 ( V_16 , V_96 , & V_64 [ 7 ] ) ;
F_35 ( L_16 , V_23 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_35 ( L_17 ,
( V_64 [ V_27 ] >> 27 ) & 0x1 ,
( V_64 [ V_27 ] >> 24 ) & 0x7 ,
( V_64 [ V_27 ] && ( ( 1 << 24 ) - 1 ) ) ) ;
}
return 0 ;
}
static int F_36 ( const struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
V_42 -> V_97 . V_98 = 0 ;
if ( ! V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] )
return - V_31 ;
F_37 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_99 , 0 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_100 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_101 ;
if ( V_42 -> V_97 . V_98 )
F_36 ( V_40 ) ;
V_101 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( ( V_101 < 0 ) || ( V_64 > 3 ) )
return - V_102 ;
V_42 -> V_97 . V_103 = ( T_1 ) V_64 ;
return V_100 ;
}
static T_3 F_40 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_18 , V_42 -> V_97 . V_103 ) ;
}
static T_3 F_41 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_100 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_101 ;
if ( V_42 -> V_97 . V_98 )
F_36 ( V_40 ) ;
V_101 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( ( V_101 < 0 ) || ( V_64 > 7 ) )
return - V_102 ;
V_42 -> V_97 . type = ( T_1 ) V_64 ;
return V_100 ;
}
static T_3 F_42 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_18 , V_42 -> V_97 . type ) ;
}
static T_3 F_43 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_100 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned long V_64 ;
int V_101 ;
if ( V_42 -> V_97 . V_98 )
F_36 ( V_40 ) ;
V_101 = F_39 ( V_63 , 10 , & V_64 ) ;
if ( V_101 < 0 )
return - V_102 ;
V_42 -> V_97 . V_104 = ( T_1 ) V_64 ;
return V_100 ;
}
static T_3 F_44 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
return sprintf ( V_63 , L_18 , V_42 -> V_97 . V_104 ) ;
}
static int F_45 ( struct V_20 * V_105 , const int V_106 , const T_1 V_107 )
{
T_1 V_108 ;
int V_100 ;
F_21 ( L_19 ,
V_105 -> V_109 -> V_110 , F_15 ( V_105 -> V_24 ) , F_16 ( V_105 -> V_24 ) ,
V_106 , V_107 ) ;
for ( V_100 = 0 ; V_100 < 10 ; V_100 ++ ) {
if ( V_100 )
F_46 ( 100 ) ;
F_37 ( V_105 , V_106 , V_107 ) ;
F_19 ( V_105 , V_106 , & V_108 ) ;
if ( V_108 == V_107 )
return 0 ;
}
F_18 ( V_30 , L_20
L_21 ,
V_105 -> V_109 -> V_110 , F_15 ( V_105 -> V_24 ) , F_16 ( V_105 -> V_24 ) ,
V_106 , V_107 , V_108 ) ;
return - V_4 ;
}
static T_3 F_47 ( struct V_39 * V_40 ,
const char * V_63 , T_4 V_100 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_111 ;
T_5 V_112 = 0 ;
int V_101 ;
long V_98 ;
if ( ! V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] )
return 0 ;
V_101 = F_39 ( V_63 , 10 , & V_98 ) ;
if ( ( V_101 < 0 ) )
return 0 ;
if ( V_98 ) {
V_42 -> V_97 . V_98 = 1 ;
} else {
F_36 ( V_40 ) ;
return V_100 ;
}
if ( V_42 -> V_97 . V_113 < 0 )
V_112 |= 1LL << 41 ;
else {
if ( V_42 -> V_67 [ V_42 -> V_97 . V_67 ] . V_1 > 2 )
V_112 |= ( V_42 -> V_97 . V_113 & 0x3LL ) << 35 ;
else
V_112 |= ( V_42 -> V_97 . V_113 & 0x1LL ) << 36 ;
}
if ( V_42 -> V_97 . V_2 < 0 )
V_112 |= 1LL << 40 ;
else {
if ( V_42 -> V_67 [ V_42 -> V_97 . V_67 ] . V_1 > 2 )
V_112 |= ( V_42 -> V_97 . V_2 & 0x1LL ) << 34 ;
else
V_112 |= ( V_42 -> V_97 . V_2 & 0x3LL ) << 34 ;
}
if ( V_42 -> V_97 . V_5 < 0 )
V_112 |= 1LL << 39 ;
else
V_112 |= ( V_42 -> V_97 . V_5 & 0x15LL ) << 30 ;
if ( V_42 -> V_97 . V_114 < 0 )
V_112 |= 1LL << 38 ;
else
V_112 |= ( V_42 -> V_97 . V_114 & 0xffff ) << 14 ;
if ( V_42 -> V_97 . V_9 < 0 )
V_112 |= 1LL << 37 ;
else
V_112 |= ( V_42 -> V_97 . V_9 & 0x3fff ) ;
V_111 = ( V_42 -> V_97 . type & 1 ) |
( V_42 -> V_97 . V_103 & 0x3 ) << 1 |
( V_42 -> V_97 . type & 0x6 ) << ( 3 - 1 ) ;
F_37 ( V_42 -> V_115 ,
V_116 , 0x2 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_117 , V_112 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_117 + 4 , V_112 >> 32L ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_118 , V_42 -> V_97 . V_104 ) ;
F_45 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_99 , V_111 ) ;
F_37 ( V_42 -> V_115 ,
V_116 , 8 ) ;
F_21 ( L_22
L_23 ,
V_112 , V_42 -> V_97 . V_104 , V_111 ) ;
return V_100 ;
}
static T_3 F_48 ( struct V_39 * V_40 ,
char * V_63 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_111 ;
if ( ! V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] )
return 0 ;
F_19 ( V_42 -> V_65 [ V_42 -> V_97 . V_67 ] [ 0 ] ,
V_99 , & V_111 ) ;
F_21 ( L_24 , V_111 ) ;
if ( V_111 & 0x0c )
V_42 -> V_97 . V_98 = 1 ;
return sprintf ( V_63 , L_25 , V_42 -> V_97 . V_98 ) ;
}
static void F_49 ( struct V_11 * V_11 )
{
int V_23 ;
F_21 ( __FILE__ L_26 , V_119 ) ;
for ( V_23 = 0 ; V_23 < V_11 -> V_17 ; V_23 ++ ) {
struct V_20 * V_16 = V_11 -> V_16 [ V_23 ] ;
if ( ! V_16 )
continue;
F_21 ( L_27 ,
V_16 -> V_109 -> V_110 ,
F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ) ;
F_50 ( V_16 ) ;
}
}
static void F_51 ( void )
{
struct V_11 * V_11 , * V_120 ;
F_52 (i7core_dev, tmp, &i7core_edac_list, list) {
F_49 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
static void T_6 F_53 ( const struct V_13 * V_14 )
{
struct V_20 * V_16 = NULL ;
int V_23 ;
while ( V_14 && V_14 -> V_121 ) {
V_16 = F_54 ( V_122 , V_14 -> V_121 [ 0 ] . V_123 , NULL ) ;
if ( F_55 ( ! V_16 ) ) {
for ( V_23 = 0 ; V_23 < V_124 ; V_23 ++ )
F_56 ( 255 - V_23 ) ;
}
F_50 ( V_16 ) ;
V_14 ++ ;
}
}
static unsigned F_57 ( void )
{
int V_125 = 0 , V_109 ;
struct V_126 * V_127 = NULL ;
while ( ( V_127 = F_58 ( V_127 ) ) != NULL ) {
V_109 = V_127 -> V_110 ;
F_21 ( L_28 , V_109 ) ;
if ( V_109 > V_125 )
V_125 = V_109 ;
}
F_21 ( L_29 , V_125 ) ;
return V_125 ;
}
static int F_59 ( struct V_20 * * V_128 ,
const struct V_13 * V_14 ,
const unsigned V_129 ,
const unsigned V_125 )
{
struct V_11 * V_11 ;
const struct V_130 * V_131 = & V_14 -> V_121 [ V_129 ] ;
struct V_20 * V_16 = NULL ;
T_2 V_109 = 0 ;
T_2 V_12 = 0 ;
V_16 = F_54 ( V_122 ,
V_131 -> V_123 , * V_128 ) ;
if ( ! V_16 ) {
if ( * V_128 ) {
* V_128 = V_16 ;
return 0 ;
}
if ( V_131 -> V_132 )
return 0 ;
if ( V_129 == 0 )
return - V_31 ;
F_18 ( V_133 ,
L_30 ,
V_131 -> V_105 , V_131 -> V_22 ,
V_122 , V_131 -> V_123 ) ;
return - V_31 ;
}
V_109 = V_16 -> V_109 -> V_110 ;
V_12 = V_125 - V_109 ;
V_11 = F_6 ( V_12 ) ;
if ( ! V_11 ) {
V_11 = F_8 ( V_12 , V_14 ) ;
if ( ! V_11 ) {
F_50 ( V_16 ) ;
return - V_134 ;
}
}
if ( V_11 -> V_16 [ V_129 ] ) {
F_18 ( V_30 ,
L_31
L_32 ,
V_109 , V_131 -> V_105 , V_131 -> V_22 ,
V_122 , V_131 -> V_123 ) ;
F_50 ( V_16 ) ;
return - V_31 ;
}
V_11 -> V_16 [ V_129 ] = V_16 ;
if ( F_55 ( F_15 ( V_16 -> V_24 ) != V_131 -> V_105 ||
F_16 ( V_16 -> V_24 ) != V_131 -> V_22 ) ) {
F_18 ( V_30 ,
L_33
L_34 ,
V_122 , V_131 -> V_123 ,
V_109 , F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ,
V_109 , V_131 -> V_105 , V_131 -> V_22 ) ;
return - V_31 ;
}
if ( F_55 ( F_60 ( V_16 ) < 0 ) ) {
F_18 ( V_30 ,
L_35
L_32 ,
V_109 , V_131 -> V_105 , V_131 -> V_22 ,
V_122 , V_131 -> V_123 ) ;
return - V_31 ;
}
F_21 ( L_36 ,
V_12 , V_109 , V_131 -> V_105 ,
V_131 -> V_22 ,
V_122 , V_131 -> V_123 ) ;
F_61 ( V_16 ) ;
* V_128 = V_16 ;
return 0 ;
}
static int F_62 ( void )
{
int V_23 , V_101 , V_125 ;
struct V_20 * V_16 = NULL ;
const struct V_13 * V_14 = V_135 ;
V_125 = F_57 () ;
while ( V_14 && V_14 -> V_121 ) {
for ( V_23 = 0 ; V_23 < V_14 -> V_17 ; V_23 ++ ) {
V_16 = NULL ;
do {
V_101 = F_59 ( & V_16 , V_14 , V_23 ,
V_125 ) ;
if ( V_101 < 0 ) {
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
V_42 -> V_136 = 0 ;
for ( V_23 = 0 ; V_23 < V_11 -> V_17 ; V_23 ++ ) {
V_16 = V_11 -> V_16 [ V_23 ] ;
if ( ! V_16 )
continue;
V_22 = F_16 ( V_16 -> V_24 ) ;
V_21 = F_15 ( V_16 -> V_24 ) ;
if ( V_21 == 3 ) {
if ( F_55 ( V_22 > V_137 ) )
goto error;
V_42 -> V_52 [ V_22 ] = V_16 ;
} else if ( F_64 ( V_21 >= 4 && V_21 < 4 + V_34 ) ) {
if ( F_55 ( V_22 > V_138 ) )
goto error;
V_42 -> V_65 [ V_21 - 4 ] [ V_22 ] = V_16 ;
} else if ( ! V_21 && ! V_22 )
V_42 -> V_115 = V_16 ;
else
goto error;
F_21 ( L_37 ,
F_15 ( V_16 -> V_24 ) , F_16 ( V_16 -> V_24 ) ,
V_16 , V_11 -> V_12 ) ;
if ( F_15 ( V_16 -> V_24 ) == 3 &&
F_16 ( V_16 -> V_24 ) == 2 )
V_42 -> V_136 = 1 ;
}
return 0 ;
error:
F_18 ( V_30 , L_38
L_39 ,
V_21 , V_22 ) ;
return - V_4 ;
}
static void F_65 ( struct V_39 * V_40 ,
const int V_139 ,
const int V_113 ,
const int V_140 )
{
char * V_141 ;
struct V_41 * V_42 = V_40 -> V_43 ;
int V_7 = V_42 -> V_82 [ V_139 ] [ V_113 ] , V_23 ;
for ( V_23 = 0 ; V_23 < V_140 ; V_23 ++ ) {
V_141 = F_66 ( V_15 , L_40
L_41 ,
V_42 -> V_11 -> V_12 , V_139 , V_113 ) ;
F_67 ( V_40 , V_7 , 0 , V_141 ) ;
F_10 ( V_141 ) ;
}
}
static void F_68 ( struct V_39 * V_40 ,
const int V_139 ,
const int V_142 ,
const int V_143 ,
const int V_144 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
int V_145 = 0 , V_146 = 0 , V_147 = 0 ;
if ( V_42 -> V_148 ) {
V_147 = V_144 - V_42 -> V_149 [ V_139 ] [ 2 ] ;
V_146 = V_143 - V_42 -> V_149 [ V_139 ] [ 1 ] ;
V_145 = V_142 - V_42 -> V_149 [ V_139 ] [ 0 ] ;
if ( V_147 < 0 )
V_147 += 0x7fff ;
V_42 -> V_150 [ V_139 ] [ 2 ] += V_147 ;
if ( V_146 < 0 )
V_146 += 0x7fff ;
V_42 -> V_150 [ V_139 ] [ 1 ] += V_146 ;
if ( V_145 < 0 )
V_145 += 0x7fff ;
V_42 -> V_150 [ V_139 ] [ 0 ] += V_145 ;
} else
V_42 -> V_148 = 1 ;
V_42 -> V_149 [ V_139 ] [ 2 ] = V_144 ;
V_42 -> V_149 [ V_139 ] [ 1 ] = V_143 ;
V_42 -> V_149 [ V_139 ] [ 0 ] = V_142 ;
if ( V_145 != 0 )
F_65 ( V_40 , V_139 , 0 , V_145 ) ;
if ( V_146 != 0 )
F_65 ( V_40 , V_139 , 1 , V_146 ) ;
if ( V_147 != 0 )
F_65 ( V_40 , V_139 , 2 , V_147 ) ;
}
static void F_69 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_151 [ 3 ] [ 2 ] ;
int V_23 , V_142 , V_143 , V_144 ;
F_19 ( V_42 -> V_52 [ 2 ] , V_152 ,
& V_151 [ 0 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_153 ,
& V_151 [ 0 ] [ 1 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_154 ,
& V_151 [ 1 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_155 ,
& V_151 [ 1 ] [ 1 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_156 ,
& V_151 [ 2 ] [ 0 ] ) ;
F_19 ( V_42 -> V_52 [ 2 ] , V_157 ,
& V_151 [ 2 ] [ 1 ] ) ;
for ( V_23 = 0 ; V_23 < 3 ; V_23 ++ ) {
F_70 ( L_42 ,
( V_23 * 2 ) , V_151 [ V_23 ] [ 0 ] , ( V_23 * 2 ) + 1 , V_151 [ V_23 ] [ 1 ] ) ;
if ( V_42 -> V_67 [ V_23 ] . V_1 > 2 ) {
V_142 = F_71 ( V_151 [ V_23 ] [ 0 ] ) ;
V_143 = F_72 ( V_151 [ V_23 ] [ 0 ] ) ;
V_144 = F_71 ( V_151 [ V_23 ] [ 1 ] ) ;
} else {
V_142 = F_72 ( V_151 [ V_23 ] [ 0 ] ) +
F_71 ( V_151 [ V_23 ] [ 0 ] ) ;
V_143 = F_72 ( V_151 [ V_23 ] [ 1 ] ) +
F_71 ( V_151 [ V_23 ] [ 1 ] ) ;
V_144 = 0 ;
}
F_68 ( V_40 , V_23 , V_142 , V_143 , V_144 ) ;
}
}
static void F_73 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
T_1 V_158 , V_159 ;
int V_142 , V_143 , V_144 ;
if ( ! V_42 -> V_52 [ 4 ] ) {
F_21 ( L_43 , V_119 ) ;
return;
}
F_19 ( V_42 -> V_52 [ 4 ] , V_160 , & V_158 ) ;
F_19 ( V_42 -> V_52 [ 4 ] , V_161 , & V_159 ) ;
V_144 = F_74 ( V_158 ) ;
V_143 = F_75 ( V_159 ) ;
V_142 = F_76 ( V_159 ) ;
if ( V_42 -> V_148 ) {
int V_145 , V_146 , V_147 ;
V_147 = V_144 - V_42 -> V_162 [ 2 ] ;
V_146 = V_143 - V_42 -> V_162 [ 1 ] ;
V_145 = V_142 - V_42 -> V_162 [ 0 ] ;
if ( V_147 < 0 )
V_147 += 0x7fff ;
V_42 -> V_163 [ 2 ] += V_147 ;
if ( V_146 < 0 )
V_146 += 0x7fff ;
V_42 -> V_163 [ 1 ] += V_146 ;
if ( V_145 < 0 )
V_145 += 0x7fff ;
V_42 -> V_163 [ 0 ] += V_145 ;
if ( V_145 | V_146 | V_147 )
F_18 ( V_30 , L_44
L_45 ,
V_145 , V_146 , V_147 ) ;
} else
V_42 -> V_148 = 1 ;
V_42 -> V_162 [ 2 ] = V_144 ;
V_42 -> V_162 [ 1 ] = V_143 ;
V_42 -> V_162 [ 0 ] = V_142 ;
}
static void F_77 ( struct V_39 * V_40 ,
const struct V_164 * V_165 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
char * type , * V_166 , * V_167 , * V_141 ;
unsigned long error = V_165 -> V_28 & 0x1ff0000l ;
T_1 V_168 = ( V_165 -> V_28 >> 4 ) & 0x07 ;
T_1 V_169 = ( V_165 -> V_28 >> 38 ) && 0x7fff ;
T_1 V_113 = ( V_165 -> V_170 >> 16 ) & 0x3 ;
T_1 V_67 = ( V_165 -> V_170 >> 18 ) & 0x3 ;
T_1 V_171 = V_165 -> V_170 >> 32 ;
T_1 V_172 = F_78 ( & error , 32 ) ;
int V_46 ;
if ( V_165 -> V_173 & 1 )
type = L_46 ;
else
type = L_47 ;
switch ( V_168 ) {
case 0 :
V_166 = L_48 ;
break;
case 1 :
V_166 = L_49 ;
break;
case 2 :
V_166 = L_50 ;
break;
case 3 :
V_166 = L_51 ;
break;
case 4 :
V_166 = L_52 ;
break;
default:
V_166 = L_53 ;
break;
}
switch ( V_172 ) {
case 16 :
V_167 = L_54 ;
break;
case 17 :
V_167 = L_55 ;
break;
case 18 :
V_167 = L_56 ;
break;
case 19 :
V_167 = L_57 ;
break;
case 20 :
V_167 = L_53 ;
break;
case 21 :
V_167 = L_58 ;
break;
case 22 :
V_167 = L_59 ;
break;
case 23 :
V_167 = L_60 ;
break;
case 24 :
V_167 = L_61 ;
break;
default:
V_167 = L_62 ;
}
V_141 = F_66 ( V_174 ,
L_63
L_64 ,
type , ( long long ) V_165 -> V_175 , V_165 -> V_176 , V_113 , V_67 ,
V_171 , V_169 , ( long long ) V_165 -> V_28 ,
( long long ) V_165 -> V_170 , V_166 , V_167 ) ;
F_21 ( L_65 , V_141 ) ;
V_46 = V_42 -> V_82 [ V_67 ] [ V_113 ] ;
if ( V_165 -> V_173 & 1 )
F_79 ( V_40 , V_46 , 0 ,
0 , V_141 ) ;
else if ( ! V_42 -> V_136 )
F_67 ( V_40 , V_46 ,
0 , V_141 ) ;
F_10 ( V_141 ) ;
}
static void F_80 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
int V_23 ;
unsigned V_100 = 0 ;
struct V_164 * V_165 ;
F_81 () ;
V_100 = ( V_42 -> V_177 + V_178 - V_42 -> V_179 )
% V_178 ;
if ( ! V_100 )
goto V_180;
V_165 = V_42 -> V_181 ;
if ( V_42 -> V_179 + V_100 > V_178 ) {
unsigned V_182 = V_178 - V_42 -> V_179 ;
memcpy ( V_165 , & V_42 -> V_183 [ V_42 -> V_179 ] , sizeof( * V_165 ) * V_182 ) ;
F_82 () ;
V_42 -> V_179 = 0 ;
V_100 -= V_182 ;
V_165 += V_182 ;
}
memcpy ( V_165 , & V_42 -> V_183 [ V_42 -> V_179 ] , sizeof( * V_165 ) * V_100 ) ;
F_82 () ;
V_42 -> V_179 += V_100 ;
F_81 () ;
if ( V_42 -> V_184 ) {
F_18 ( V_30 , L_66 ,
V_42 -> V_184 ) ;
F_82 () ;
V_42 -> V_184 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_100 ; V_23 ++ )
F_77 ( V_40 , & V_42 -> V_181 [ V_23 ] ) ;
V_180:
if ( ! V_42 -> V_136 )
F_73 ( V_40 ) ;
else
F_69 ( V_40 ) ;
}
static int F_83 ( void * V_185 , struct V_164 * V_164 )
{
struct V_39 * V_40 = V_185 ;
struct V_41 * V_42 = V_40 -> V_43 ;
if ( ( ( V_164 -> V_28 & 0xffff ) >> 7 ) != 1 )
return 0 ;
if ( V_164 -> V_5 != 8 )
return 0 ;
#ifdef F_84
if ( F_85 ( V_164 -> V_176 ) . V_186 != V_42 -> V_11 -> V_12 )
return 0 ;
#endif
F_81 () ;
if ( ( V_42 -> V_177 + 1 ) % V_178 == V_42 -> V_179 ) {
F_82 () ;
V_42 -> V_184 ++ ;
return 0 ;
}
memcpy ( & V_42 -> V_183 [ V_42 -> V_177 ] , V_164 , sizeof( * V_164 ) ) ;
F_82 () ;
V_42 -> V_177 = ( V_42 -> V_177 + 1 ) % V_178 ;
if ( V_164 -> V_173 & 1 )
F_80 ( V_40 ) ;
return 1 ;
}
static void F_86 ( struct V_41 * V_42 )
{
V_42 -> V_187 = F_87 (
& V_42 -> V_11 -> V_16 [ 0 ] -> V_105 ,
V_188 ) ;
if ( F_55 ( ! V_42 -> V_187 ) )
F_88 ( L_67 ) ;
}
static void F_89 ( struct V_41 * V_42 )
{
if ( F_64 ( V_42 -> V_187 ) )
F_90 ( V_42 -> V_187 ) ;
else
F_18 ( V_30 ,
L_68 ,
V_42 -> V_11 -> V_12 ) ;
V_42 -> V_187 = NULL ;
}
static void F_91 ( struct V_11 * V_11 )
{
struct V_39 * V_40 = V_11 -> V_40 ;
struct V_41 * V_42 ;
if ( F_55 ( ! V_40 || ! V_40 -> V_43 ) ) {
F_21 ( L_69 __FILE__ L_70 ,
V_119 , & V_11 -> V_16 [ 0 ] -> V_105 ) ;
F_18 ( V_30 , L_71 ) ;
return;
}
V_42 = V_40 -> V_43 ;
F_21 ( L_69 __FILE__ L_72 ,
V_119 , V_40 , & V_11 -> V_16 [ 0 ] -> V_105 ) ;
F_92 ( & V_42 -> V_189 ) ;
F_89 ( V_42 ) ;
F_93 ( V_40 -> V_105 ) ;
F_35 ( L_73 , V_40 -> V_190 ) ;
F_10 ( V_40 -> V_190 ) ;
F_94 ( V_40 ) ;
V_11 -> V_40 = NULL ;
}
static int F_95 ( struct V_11 * V_11 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_101 , V_25 , V_26 ;
V_101 = F_17 ( V_11 -> V_12 , & V_25 , & V_26 ) ;
if ( F_55 ( V_101 < 0 ) )
return V_101 ;
V_40 = F_96 ( sizeof( * V_42 ) , V_26 , V_25 , V_11 -> V_12 ) ;
if ( F_55 ( ! V_40 ) )
return - V_134 ;
F_21 ( L_69 __FILE__ L_72 ,
V_119 , V_40 , & V_11 -> V_16 [ 0 ] -> V_105 ) ;
V_42 = V_40 -> V_43 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_11 = V_11 ;
V_11 -> V_40 = V_40 ;
V_40 -> V_191 = V_192 ;
V_40 -> V_193 = V_194 ;
V_40 -> V_195 = V_194 ;
V_40 -> V_196 = L_74 ;
V_40 -> V_197 = V_198 ;
V_40 -> V_190 = F_66 ( V_15 , L_75 ,
V_11 -> V_12 ) ;
V_40 -> V_199 = F_97 ( V_11 -> V_16 [ 0 ] ) ;
V_40 -> V_200 = NULL ;
V_101 = F_63 ( V_40 , V_11 ) ;
if ( F_55 ( V_101 < 0 ) )
goto V_201;
if ( V_42 -> V_136 )
V_40 -> V_202 = V_203 ;
else
V_40 -> V_202 = V_204 ;
F_22 ( V_40 ) ;
V_40 -> V_105 = & V_11 -> V_16 [ 0 ] -> V_105 ;
V_40 -> V_205 = F_80 ;
if ( F_55 ( F_98 ( V_40 ) ) ) {
F_21 ( L_69 __FILE__
L_76 , V_119 ) ;
V_101 = - V_4 ;
goto V_201;
}
V_42 -> V_97 . V_67 = 0 ;
V_42 -> V_97 . V_113 = - 1 ;
V_42 -> V_97 . V_2 = - 1 ;
V_42 -> V_97 . V_5 = - 1 ;
V_42 -> V_97 . V_114 = - 1 ;
V_42 -> V_97 . V_9 = - 1 ;
F_86 ( V_42 ) ;
V_42 -> V_189 . V_185 = V_40 ;
V_42 -> V_189 . V_206 = F_83 ;
V_101 = F_99 ( & V_42 -> V_189 ) ;
if ( F_55 ( V_101 < 0 ) ) {
F_21 ( L_69 __FILE__
L_77 , V_119 ) ;
goto V_207;
}
return 0 ;
V_207:
F_89 ( V_42 ) ;
F_93 ( V_40 -> V_105 ) ;
V_201:
F_10 ( V_40 -> V_190 ) ;
F_94 ( V_40 ) ;
V_11 -> V_40 = NULL ;
return V_101 ;
}
static int T_7 F_100 ( struct V_20 * V_16 ,
const struct V_208 * V_209 )
{
int V_101 ;
struct V_11 * V_11 ;
F_101 ( & V_210 ) ;
if ( F_55 ( V_211 >= 1 ) ) {
F_102 ( & V_210 ) ;
return - V_31 ;
}
V_211 ++ ;
V_101 = F_62 () ;
if ( F_55 ( V_101 < 0 ) )
goto V_201;
F_7 (i7core_dev, &i7core_edac_list, list) {
V_101 = F_95 ( V_11 ) ;
if ( F_55 ( V_101 < 0 ) )
goto V_207;
}
F_18 ( V_133 , L_78 ) ;
F_102 ( & V_210 ) ;
return 0 ;
V_207:
F_7 (i7core_dev, &i7core_edac_list, list)
F_91 ( V_11 ) ;
F_51 () ;
V_201:
F_102 ( & V_210 ) ;
return V_101 ;
}
static void T_8 F_103 ( struct V_20 * V_16 )
{
struct V_11 * V_11 ;
F_21 ( __FILE__ L_26 , V_119 ) ;
F_101 ( & V_210 ) ;
if ( F_55 ( ! V_211 ) ) {
F_102 ( & V_210 ) ;
return;
}
F_7 (i7core_dev, &i7core_edac_list, list)
F_91 ( V_11 ) ;
F_51 () ;
V_211 -- ;
F_102 ( & V_210 ) ;
}
static int T_6 F_104 ( void )
{
int V_212 ;
F_105 ( L_69 __FILE__ L_26 , V_119 ) ;
F_106 () ;
if ( V_213 )
F_53 ( V_135 ) ;
V_212 = F_107 ( & V_214 ) ;
if ( V_212 >= 0 )
return 0 ;
F_18 ( V_30 , L_79 ,
V_212 ) ;
return V_212 ;
}
static void T_9 F_108 ( void )
{
F_105 ( L_69 __FILE__ L_26 , V_119 ) ;
F_109 ( & V_214 ) ;
}
