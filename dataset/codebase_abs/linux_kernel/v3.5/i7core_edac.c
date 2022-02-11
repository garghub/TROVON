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
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
int V_26 , V_27 ;
enum V_28 V_29 ;
enum V_30 V_31 ;
struct V_32 * V_33 ;
V_16 = V_23 -> V_34 [ 0 ] ;
if ( ! V_16 )
return - V_35 ;
F_15 ( V_16 , V_36 , & V_23 -> V_37 . V_38 ) ;
F_15 ( V_16 , V_39 , & V_23 -> V_37 . V_40 ) ;
F_15 ( V_16 , V_41 , & V_23 -> V_37 . V_42 ) ;
F_15 ( V_16 , V_43 , & V_23 -> V_37 . V_44 ) ;
F_16 ( L_1 ,
V_23 -> V_11 -> V_12 , V_23 -> V_37 . V_38 , V_23 -> V_37 . V_40 ,
V_23 -> V_37 . V_42 , V_23 -> V_37 . V_44 ) ;
if ( F_17 ( V_23 ) ) {
F_16 ( L_2 , F_18 ( V_23 ) ? 8 : 4 ) ;
if ( F_18 ( V_23 ) )
V_29 = V_45 ;
else
V_29 = V_46 ;
} else {
F_16 ( L_3 ) ;
V_29 = V_47 ;
}
F_16 ( L_4
L_5 ,
F_1 ( V_23 -> V_37 . V_42 ) ,
F_2 ( V_23 -> V_37 . V_42 >> 2 ) ,
F_3 ( V_23 -> V_37 . V_42 >> 4 ) ,
F_4 ( V_23 -> V_37 . V_42 >> 6 ) ,
F_5 ( V_23 -> V_37 . V_42 >> 9 ) ) ;
for ( V_26 = 0 ; V_26 < V_48 ; V_26 ++ ) {
T_1 V_49 , V_50 [ 3 ] , V_51 [ 8 ] ;
if ( ! V_23 -> V_52 [ V_26 ] [ 0 ] )
continue;
if ( ! F_19 ( V_23 , V_26 ) ) {
F_16 ( L_6 , V_26 ) ;
continue;
}
if ( F_20 ( V_23 , V_26 ) ) {
F_16 ( L_7 , V_26 ) ;
continue;
}
F_15 ( V_23 -> V_52 [ V_26 ] [ 0 ] ,
V_53 , & V_49 ) ;
if ( V_49 & V_54 )
V_23 -> V_55 [ V_26 ] . V_56 = true ;
if ( V_49 & V_57 )
V_23 -> V_55 [ V_26 ] . V_58 = true ;
if ( V_49 & V_59 )
V_23 -> V_55 [ V_26 ] . V_60 = true ;
if ( V_49 & V_61 )
V_31 = V_62 ;
else
V_31 = V_63 ;
F_15 ( V_23 -> V_52 [ V_26 ] [ 1 ] ,
V_64 , & V_50 [ 0 ] ) ;
F_15 ( V_23 -> V_52 [ V_26 ] [ 1 ] ,
V_65 , & V_50 [ 1 ] ) ;
F_15 ( V_23 -> V_52 [ V_26 ] [ 1 ] ,
V_66 , & V_50 [ 2 ] ) ;
F_16 ( L_8
L_9 ,
V_26 ,
F_21 ( V_23 -> V_37 . V_44 , V_26 ) , F_22 ( V_23 -> V_37 . V_44 , V_26 ) ,
V_49 ,
V_23 -> V_55 [ V_26 ] . V_56 ? L_10 : L_11 ,
V_23 -> V_55 [ V_26 ] . V_56 ? L_12 : L_11 ,
V_23 -> V_55 [ V_26 ] . V_60 ? L_13 : L_11 ,
( V_49 & V_61 ) ? 'R' : 'U' ) ;
for ( V_27 = 0 ; V_27 < 3 ; V_27 ++ ) {
T_1 V_6 , V_3 , V_8 , V_10 ;
T_1 V_67 , V_68 ;
if ( ! F_23 ( V_50 [ V_27 ] ) )
continue;
V_33 = F_24 ( V_21 -> V_69 , V_21 -> V_1 , V_21 -> V_70 ,
V_26 , V_27 , 0 ) ;
V_6 = F_3 ( F_25 ( V_50 [ V_27 ] ) ) ;
V_3 = F_2 ( F_26 ( V_50 [ V_27 ] ) ) ;
V_8 = F_4 ( F_27 ( V_50 [ V_27 ] ) ) ;
V_10 = F_5 ( F_28 ( V_50 [ V_27 ] ) ) ;
V_67 = ( V_8 * V_10 * V_6 * V_3 ) >> ( 20 - 3 ) ;
F_16 ( L_14
L_15 ,
V_27 , V_67 ,
F_29 ( V_50 [ V_27 ] ) ,
V_6 , V_3 , V_8 , V_10 ) ;
V_68 = F_30 ( V_67 ) ;
V_33 -> V_71 = V_68 ;
switch ( V_6 ) {
case 4 :
V_33 -> V_72 = V_73 ;
break;
case 8 :
V_33 -> V_72 = V_74 ;
break;
case 16 :
V_33 -> V_72 = V_75 ;
break;
default:
V_33 -> V_72 = V_76 ;
}
snprintf ( V_33 -> V_77 , sizeof( V_33 -> V_77 ) ,
L_16 ,
V_23 -> V_11 -> V_12 , V_26 , V_27 ) ;
V_33 -> V_78 = 8 ;
V_33 -> V_79 = V_29 ;
V_33 -> V_31 = V_31 ;
}
F_15 ( V_16 , V_80 , & V_51 [ 0 ] ) ;
F_15 ( V_16 , V_81 , & V_51 [ 1 ] ) ;
F_15 ( V_16 , V_82 , & V_51 [ 2 ] ) ;
F_15 ( V_16 , V_83 , & V_51 [ 3 ] ) ;
F_15 ( V_16 , V_84 , & V_51 [ 4 ] ) ;
F_15 ( V_16 , V_85 , & V_51 [ 5 ] ) ;
F_15 ( V_16 , V_86 , & V_51 [ 6 ] ) ;
F_15 ( V_16 , V_87 , & V_51 [ 7 ] ) ;
F_31 ( L_17 , V_26 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_31 ( L_18 ,
( V_51 [ V_27 ] >> 27 ) & 0x1 ,
( V_51 [ V_27 ] >> 24 ) & 0x7 ,
( V_51 [ V_27 ] & ( ( 1 << 24 ) - 1 ) ) ) ;
}
return 0 ;
}
static int F_32 ( const struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
V_23 -> V_88 . V_89 = 0 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return - V_35 ;
F_33 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , 0 ) ;
return 0 ;
}
static T_3 F_34 ( struct V_20 * V_21 ,
const char * V_49 , T_4 V_91 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_92 ;
if ( V_23 -> V_88 . V_89 )
F_32 ( V_21 ) ;
V_92 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( ( V_92 < 0 ) || ( V_51 > 3 ) )
return - V_93 ;
V_23 -> V_88 . V_94 = ( T_1 ) V_51 ;
return V_91 ;
}
static T_3 F_36 ( struct V_20 * V_21 ,
char * V_49 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_19 , V_23 -> V_88 . V_94 ) ;
}
static T_3 F_37 ( struct V_20 * V_21 ,
const char * V_49 , T_4 V_91 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_92 ;
if ( V_23 -> V_88 . V_89 )
F_32 ( V_21 ) ;
V_92 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( ( V_92 < 0 ) || ( V_51 > 7 ) )
return - V_93 ;
V_23 -> V_88 . type = ( T_1 ) V_51 ;
return V_91 ;
}
static T_3 F_38 ( struct V_20 * V_21 ,
char * V_49 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_19 , V_23 -> V_88 . type ) ;
}
static T_3 F_39 ( struct V_20 * V_21 ,
const char * V_49 , T_4 V_91 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_92 ;
if ( V_23 -> V_88 . V_89 )
F_32 ( V_21 ) ;
V_92 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( V_92 < 0 )
return - V_93 ;
V_23 -> V_88 . V_95 = ( T_1 ) V_51 ;
return V_91 ;
}
static T_3 F_40 ( struct V_20 * V_21 ,
char * V_49 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_19 , V_23 -> V_88 . V_95 ) ;
}
static int F_41 ( struct V_25 * V_96 , const int V_97 , const T_1 V_98 )
{
T_1 V_99 ;
int V_91 ;
F_16 ( L_20 ,
V_96 -> V_100 -> V_101 , F_42 ( V_96 -> V_102 ) , F_43 ( V_96 -> V_102 ) ,
V_97 , V_98 ) ;
for ( V_91 = 0 ; V_91 < 10 ; V_91 ++ ) {
if ( V_91 )
F_44 ( 100 ) ;
F_33 ( V_96 , V_97 , V_98 ) ;
F_15 ( V_96 , V_97 , & V_99 ) ;
if ( V_99 == V_98 )
return 0 ;
}
F_45 ( V_103 , L_21
L_22 ,
V_96 -> V_100 -> V_101 , F_42 ( V_96 -> V_102 ) , F_43 ( V_96 -> V_102 ) ,
V_97 , V_98 , V_99 ) ;
return - V_4 ;
}
static T_3 F_46 ( struct V_20 * V_21 ,
const char * V_49 , T_4 V_91 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_104 ;
T_5 V_105 = 0 ;
int V_92 ;
long V_89 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return 0 ;
V_92 = F_35 ( V_49 , 10 , & V_89 ) ;
if ( ( V_92 < 0 ) )
return 0 ;
if ( V_89 ) {
V_23 -> V_88 . V_89 = 1 ;
} else {
F_32 ( V_21 ) ;
return V_91 ;
}
if ( V_23 -> V_88 . V_33 < 0 )
V_105 |= 1LL << 41 ;
else {
if ( V_23 -> V_55 [ V_23 -> V_88 . V_55 ] . V_1 > 2 )
V_105 |= ( V_23 -> V_88 . V_33 & 0x3LL ) << 35 ;
else
V_105 |= ( V_23 -> V_88 . V_33 & 0x1LL ) << 36 ;
}
if ( V_23 -> V_88 . V_2 < 0 )
V_105 |= 1LL << 40 ;
else {
if ( V_23 -> V_55 [ V_23 -> V_88 . V_55 ] . V_1 > 2 )
V_105 |= ( V_23 -> V_88 . V_2 & 0x1LL ) << 34 ;
else
V_105 |= ( V_23 -> V_88 . V_2 & 0x3LL ) << 34 ;
}
if ( V_23 -> V_88 . V_5 < 0 )
V_105 |= 1LL << 39 ;
else
V_105 |= ( V_23 -> V_88 . V_5 & 0x15LL ) << 30 ;
if ( V_23 -> V_88 . V_106 < 0 )
V_105 |= 1LL << 38 ;
else
V_105 |= ( V_23 -> V_88 . V_106 & 0xffff ) << 14 ;
if ( V_23 -> V_88 . V_9 < 0 )
V_105 |= 1LL << 37 ;
else
V_105 |= ( V_23 -> V_88 . V_9 & 0x3fff ) ;
V_104 = ( V_23 -> V_88 . type & 1 ) |
( V_23 -> V_88 . V_94 & 0x3 ) << 1 |
( V_23 -> V_88 . type & 0x6 ) << ( 3 - 1 ) ;
F_33 ( V_23 -> V_107 ,
V_108 , 0x2 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_109 , V_105 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_109 + 4 , V_105 >> 32L ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_110 , V_23 -> V_88 . V_95 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , V_104 ) ;
F_33 ( V_23 -> V_107 ,
V_108 , 8 ) ;
F_16 ( L_23
L_24 ,
V_105 , V_23 -> V_88 . V_95 , V_104 ) ;
return V_91 ;
}
static T_3 F_47 ( struct V_20 * V_21 ,
char * V_49 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_104 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return 0 ;
F_15 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , & V_104 ) ;
F_16 ( L_25 , V_104 ) ;
if ( V_104 & 0x0c )
V_23 -> V_88 . V_89 = 1 ;
return sprintf ( V_49 , L_26 , V_23 -> V_88 . V_89 ) ;
}
static void F_48 ( struct V_11 * V_11 )
{
int V_26 ;
F_16 ( __FILE__ L_27 , V_111 ) ;
for ( V_26 = 0 ; V_26 < V_11 -> V_17 ; V_26 ++ ) {
struct V_25 * V_16 = V_11 -> V_16 [ V_26 ] ;
if ( ! V_16 )
continue;
F_16 ( L_28 ,
V_16 -> V_100 -> V_101 ,
F_42 ( V_16 -> V_102 ) , F_43 ( V_16 -> V_102 ) ) ;
F_49 ( V_16 ) ;
}
}
static void F_50 ( void )
{
struct V_11 * V_11 , * V_112 ;
F_51 (i7core_dev, tmp, &i7core_edac_list, list) {
F_48 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
static void T_6 F_52 ( const struct V_13 * V_14 )
{
struct V_25 * V_16 = NULL ;
int V_26 ;
while ( V_14 && V_14 -> V_113 ) {
V_16 = F_53 ( V_114 , V_14 -> V_113 [ 0 ] . V_115 , NULL ) ;
if ( F_54 ( ! V_16 ) ) {
for ( V_26 = 0 ; V_26 < V_116 ; V_26 ++ )
F_55 ( 255 - V_26 ) ;
}
F_49 ( V_16 ) ;
V_14 ++ ;
}
}
static unsigned F_56 ( void )
{
int V_117 = 0 , V_100 ;
struct V_118 * V_119 = NULL ;
while ( ( V_119 = F_57 ( V_119 ) ) != NULL ) {
V_100 = V_119 -> V_101 ;
F_16 ( L_29 , V_100 ) ;
if ( V_100 > V_117 )
V_117 = V_100 ;
}
F_16 ( L_30 , V_117 ) ;
return V_117 ;
}
static int F_58 ( struct V_25 * * V_120 ,
const struct V_13 * V_14 ,
const unsigned V_121 ,
const unsigned V_117 )
{
struct V_11 * V_11 ;
const struct V_122 * V_123 = & V_14 -> V_113 [ V_121 ] ;
struct V_25 * V_16 = NULL ;
T_2 V_100 = 0 ;
T_2 V_12 = 0 ;
V_16 = F_53 ( V_114 ,
V_123 -> V_115 , * V_120 ) ;
if ( V_123 -> V_115 == V_124 && ! V_16 )
V_16 = F_53 ( V_114 ,
V_125 , * V_120 ) ;
if ( V_123 -> V_115 == V_126 && ! V_16 )
V_16 = F_53 ( V_114 ,
V_127 ,
* V_120 ) ;
if ( ! V_16 ) {
if ( * V_120 ) {
* V_120 = V_16 ;
return 0 ;
}
if ( V_123 -> V_128 )
return 0 ;
if ( V_121 == 0 )
return - V_35 ;
F_45 ( V_129 ,
L_31 ,
V_123 -> V_96 , V_123 -> V_130 ,
V_114 , V_123 -> V_115 ) ;
return - V_35 ;
}
V_100 = V_16 -> V_100 -> V_101 ;
V_12 = V_117 - V_100 ;
V_11 = F_6 ( V_12 ) ;
if ( ! V_11 ) {
V_11 = F_8 ( V_12 , V_14 ) ;
if ( ! V_11 ) {
F_49 ( V_16 ) ;
return - V_131 ;
}
}
if ( V_11 -> V_16 [ V_121 ] ) {
F_45 ( V_103 ,
L_32
L_33 ,
V_100 , V_123 -> V_96 , V_123 -> V_130 ,
V_114 , V_123 -> V_115 ) ;
F_49 ( V_16 ) ;
return - V_35 ;
}
V_11 -> V_16 [ V_121 ] = V_16 ;
if ( F_54 ( F_42 ( V_16 -> V_102 ) != V_123 -> V_96 ||
F_43 ( V_16 -> V_102 ) != V_123 -> V_130 ) ) {
F_45 ( V_103 ,
L_34
L_35 ,
V_114 , V_123 -> V_115 ,
V_100 , F_42 ( V_16 -> V_102 ) , F_43 ( V_16 -> V_102 ) ,
V_100 , V_123 -> V_96 , V_123 -> V_130 ) ;
return - V_35 ;
}
if ( F_54 ( F_59 ( V_16 ) < 0 ) ) {
F_45 ( V_103 ,
L_36
L_33 ,
V_100 , V_123 -> V_96 , V_123 -> V_130 ,
V_114 , V_123 -> V_115 ) ;
return - V_35 ;
}
F_16 ( L_37 ,
V_12 , V_100 , V_123 -> V_96 ,
V_123 -> V_130 ,
V_114 , V_123 -> V_115 ) ;
F_60 ( V_16 ) ;
* V_120 = V_16 ;
return 0 ;
}
static int F_61 ( void )
{
int V_26 , V_92 , V_117 ;
struct V_25 * V_16 = NULL ;
const struct V_13 * V_14 = V_132 ;
V_117 = F_56 () ;
while ( V_14 && V_14 -> V_113 ) {
for ( V_26 = 0 ; V_26 < V_14 -> V_17 ; V_26 ++ ) {
V_16 = NULL ;
do {
V_92 = F_58 ( & V_16 , V_14 , V_26 ,
V_117 ) ;
if ( V_92 < 0 ) {
if ( V_26 == 0 ) {
V_26 = V_14 -> V_17 ;
break;
}
F_50 () ;
return - V_35 ;
}
} while ( V_16 );
}
V_14 ++ ;
}
return 0 ;
}
static int F_62 ( struct V_20 * V_21 ,
struct V_11 * V_11 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
int V_26 , V_130 , V_133 ;
char * V_134 ;
V_23 -> V_135 = false ;
V_23 -> V_136 = false ;
for ( V_26 = 0 ; V_26 < V_11 -> V_17 ; V_26 ++ ) {
V_16 = V_11 -> V_16 [ V_26 ] ;
if ( ! V_16 )
continue;
V_130 = F_43 ( V_16 -> V_102 ) ;
V_133 = F_42 ( V_16 -> V_102 ) ;
if ( V_133 == 3 ) {
if ( F_54 ( V_130 > V_137 ) )
goto error;
V_23 -> V_34 [ V_130 ] = V_16 ;
} else if ( F_63 ( V_133 >= 4 && V_133 < 4 + V_48 ) ) {
if ( F_54 ( V_130 > V_138 ) )
goto error;
V_23 -> V_52 [ V_133 - 4 ] [ V_130 ] = V_16 ;
} else if ( ! V_133 && ! V_130 ) {
V_23 -> V_107 = V_16 ;
switch ( V_16 -> V_139 ) {
case V_124 :
V_134 = L_38 ;
V_23 -> V_136 = false ;
break;
case V_127 :
V_134 = L_39 ;
V_23 -> V_136 = false ;
break;
case V_126 :
V_134 = L_40 ;
V_23 -> V_136 = false ;
break;
case V_125 :
V_134 = L_41 ;
V_23 -> V_136 = true ;
break;
case V_140 :
V_134 = L_42 ;
V_23 -> V_136 = true ;
break;
default:
V_134 = L_43 ;
V_23 -> V_136 = false ;
}
F_16 ( L_44 , V_134 ) ;
} else
goto error;
F_16 ( L_45 ,
F_42 ( V_16 -> V_102 ) , F_43 ( V_16 -> V_102 ) ,
V_16 , V_11 -> V_12 ) ;
if ( F_42 ( V_16 -> V_102 ) == 3 &&
F_43 ( V_16 -> V_102 ) == 2 )
V_23 -> V_135 = true ;
}
return 0 ;
error:
F_45 ( V_103 , L_46
L_47 ,
V_133 , V_130 ) ;
return - V_4 ;
}
static void F_64 ( struct V_20 * V_21 ,
const int V_141 ,
const int V_33 ,
const int V_142 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_142 ; V_26 ++ ) {
F_65 ( V_143 , V_21 , 0 , 0 , 0 ,
V_141 , V_33 , - 1 , L_48 , L_11 , NULL ) ;
}
}
static void F_66 ( struct V_20 * V_21 ,
const int V_141 ,
const int V_144 ,
const int V_145 ,
const int V_146 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
int V_147 = 0 , V_148 = 0 , V_149 = 0 ;
if ( V_23 -> V_150 ) {
V_149 = V_146 - V_23 -> V_151 [ V_141 ] [ 2 ] ;
V_148 = V_145 - V_23 -> V_151 [ V_141 ] [ 1 ] ;
V_147 = V_144 - V_23 -> V_151 [ V_141 ] [ 0 ] ;
if ( V_149 < 0 )
V_149 += 0x7fff ;
V_23 -> V_152 [ V_141 ] [ 2 ] += V_149 ;
if ( V_148 < 0 )
V_148 += 0x7fff ;
V_23 -> V_152 [ V_141 ] [ 1 ] += V_148 ;
if ( V_147 < 0 )
V_147 += 0x7fff ;
V_23 -> V_152 [ V_141 ] [ 0 ] += V_147 ;
} else
V_23 -> V_150 = 1 ;
V_23 -> V_151 [ V_141 ] [ 2 ] = V_146 ;
V_23 -> V_151 [ V_141 ] [ 1 ] = V_145 ;
V_23 -> V_151 [ V_141 ] [ 0 ] = V_144 ;
if ( V_147 != 0 )
F_64 ( V_21 , V_141 , 0 , V_147 ) ;
if ( V_148 != 0 )
F_64 ( V_21 , V_141 , 1 , V_148 ) ;
if ( V_149 != 0 )
F_64 ( V_21 , V_141 , 2 , V_149 ) ;
}
static void F_67 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_153 [ 3 ] [ 2 ] ;
int V_26 , V_144 , V_145 , V_146 ;
F_15 ( V_23 -> V_34 [ 2 ] , V_154 ,
& V_153 [ 0 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_155 ,
& V_153 [ 0 ] [ 1 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_156 ,
& V_153 [ 1 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_157 ,
& V_153 [ 1 ] [ 1 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_158 ,
& V_153 [ 2 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_159 ,
& V_153 [ 2 ] [ 1 ] ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
F_68 ( L_49 ,
( V_26 * 2 ) , V_153 [ V_26 ] [ 0 ] , ( V_26 * 2 ) + 1 , V_153 [ V_26 ] [ 1 ] ) ;
if ( V_23 -> V_55 [ V_26 ] . V_1 > 2 ) {
V_144 = F_69 ( V_153 [ V_26 ] [ 0 ] ) ;
V_145 = F_70 ( V_153 [ V_26 ] [ 0 ] ) ;
V_146 = F_69 ( V_153 [ V_26 ] [ 1 ] ) ;
} else {
V_144 = F_70 ( V_153 [ V_26 ] [ 0 ] ) +
F_69 ( V_153 [ V_26 ] [ 0 ] ) ;
V_145 = F_70 ( V_153 [ V_26 ] [ 1 ] ) +
F_69 ( V_153 [ V_26 ] [ 1 ] ) ;
V_146 = 0 ;
}
F_66 ( V_21 , V_26 , V_144 , V_145 , V_146 ) ;
}
}
static void F_71 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_160 , V_161 ;
int V_144 , V_145 , V_146 ;
if ( ! V_23 -> V_34 [ 4 ] ) {
F_16 ( L_50 , V_111 ) ;
return;
}
F_15 ( V_23 -> V_34 [ 4 ] , V_162 , & V_160 ) ;
F_15 ( V_23 -> V_34 [ 4 ] , V_163 , & V_161 ) ;
V_146 = F_72 ( V_160 ) ;
V_145 = F_73 ( V_161 ) ;
V_144 = F_74 ( V_161 ) ;
if ( V_23 -> V_150 ) {
int V_147 , V_148 , V_149 ;
V_149 = V_146 - V_23 -> V_164 [ 2 ] ;
V_148 = V_145 - V_23 -> V_164 [ 1 ] ;
V_147 = V_144 - V_23 -> V_164 [ 0 ] ;
if ( V_149 < 0 )
V_149 += 0x7fff ;
V_23 -> V_165 [ 2 ] += V_149 ;
if ( V_148 < 0 )
V_148 += 0x7fff ;
V_23 -> V_165 [ 1 ] += V_148 ;
if ( V_147 < 0 )
V_147 += 0x7fff ;
V_23 -> V_165 [ 0 ] += V_147 ;
if ( V_147 | V_148 | V_149 )
F_45 ( V_103 , L_51
L_52 ,
V_147 , V_148 , V_149 ) ;
} else
V_23 -> V_150 = 1 ;
V_23 -> V_164 [ 2 ] = V_146 ;
V_23 -> V_164 [ 1 ] = V_145 ;
V_23 -> V_164 [ 0 ] = V_144 ;
}
static void F_75 ( struct V_20 * V_21 ,
const struct V_166 * V_167 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
char * type , * V_168 , * V_169 , V_170 [ 80 ] ;
enum V_171 V_172 ;
unsigned long error = V_167 -> V_173 & 0x1ff0000l ;
bool V_174 = V_167 -> V_175 & 1ll << 61 ;
bool V_176 = V_167 -> V_175 & 1 ;
T_1 V_177 = ( V_167 -> V_173 >> 4 ) & 0x07 ;
T_1 V_178 = ( V_167 -> V_173 >> 38 ) & 0x7fff ;
T_1 V_33 = ( V_167 -> V_179 >> 16 ) & 0x3 ;
T_1 V_55 = ( V_167 -> V_179 >> 18 ) & 0x3 ;
T_1 V_180 = V_167 -> V_179 >> 32 ;
T_1 V_181 = F_76 ( & error , 32 ) ;
if ( V_174 ) {
if ( V_176 ) {
type = L_53 ;
V_172 = V_182 ;
} else {
type = L_54 ;
V_172 = V_183 ;
}
} else {
type = L_55 ;
V_172 = V_143 ;
}
switch ( V_177 ) {
case 0 :
V_168 = L_56 ;
break;
case 1 :
V_168 = L_57 ;
break;
case 2 :
V_168 = L_58 ;
break;
case 3 :
V_168 = L_59 ;
break;
case 4 :
V_168 = L_60 ;
break;
default:
V_168 = L_61 ;
break;
}
switch ( V_181 ) {
case 16 :
V_169 = L_62 ;
break;
case 17 :
V_169 = L_63 ;
break;
case 18 :
V_169 = L_64 ;
break;
case 19 :
V_169 = L_65 ;
break;
case 20 :
V_169 = L_61 ;
break;
case 21 :
V_169 = L_66 ;
break;
case 22 :
V_169 = L_67 ;
break;
case 23 :
V_169 = L_68 ;
break;
case 24 :
V_169 = L_69 ;
break;
default:
V_169 = L_43 ;
}
snprintf ( V_170 , sizeof( V_170 ) , L_70 , V_178 , V_168 ) ;
if ( V_174 || ! V_23 -> V_135 )
F_65 ( V_172 , V_21 ,
V_167 -> V_184 >> V_185 ,
V_167 -> V_184 & ~ V_186 ,
V_180 ,
V_55 , V_33 , - 1 ,
V_169 , V_170 , V_167 ) ;
}
static void F_77 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
int V_26 ;
unsigned V_91 = 0 ;
struct V_166 * V_167 ;
F_78 () ;
V_91 = ( V_23 -> V_187 + V_188 - V_23 -> V_189 )
% V_188 ;
if ( ! V_91 )
goto V_190;
V_167 = V_23 -> V_191 ;
if ( V_23 -> V_189 + V_91 > V_188 ) {
unsigned V_192 = V_188 - V_23 -> V_189 ;
memcpy ( V_167 , & V_23 -> V_193 [ V_23 -> V_189 ] , sizeof( * V_167 ) * V_192 ) ;
F_79 () ;
V_23 -> V_189 = 0 ;
V_91 -= V_192 ;
V_167 += V_192 ;
}
memcpy ( V_167 , & V_23 -> V_193 [ V_23 -> V_189 ] , sizeof( * V_167 ) * V_91 ) ;
F_79 () ;
V_23 -> V_189 += V_91 ;
F_78 () ;
if ( V_23 -> V_194 ) {
F_45 ( V_103 , L_71 ,
V_23 -> V_194 ) ;
F_79 () ;
V_23 -> V_194 = 0 ;
}
for ( V_26 = 0 ; V_26 < V_91 ; V_26 ++ )
F_75 ( V_21 , & V_23 -> V_191 [ V_26 ] ) ;
V_190:
if ( ! V_23 -> V_135 )
F_71 ( V_21 ) ;
else
F_67 ( V_21 ) ;
}
static int F_80 ( struct V_195 * V_196 , unsigned long V_98 ,
void * V_49 )
{
struct V_166 * V_166 = (struct V_166 * ) V_49 ;
struct V_11 * V_197 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_197 = F_6 ( V_166 -> V_198 ) ;
if ( ! V_197 )
return V_199 ;
V_21 = V_197 -> V_21 ;
V_23 = V_21 -> V_24 ;
if ( ( ( V_166 -> V_173 & 0xffff ) >> 7 ) != 1 )
return V_200 ;
if ( V_166 -> V_5 != 8 )
return V_200 ;
F_78 () ;
if ( ( V_23 -> V_187 + 1 ) % V_188 == V_23 -> V_189 ) {
F_79 () ;
V_23 -> V_194 ++ ;
return V_200 ;
}
memcpy ( & V_23 -> V_193 [ V_23 -> V_187 ] , V_166 , sizeof( * V_166 ) ) ;
F_79 () ;
V_23 -> V_187 = ( V_23 -> V_187 + 1 ) % V_188 ;
if ( V_166 -> V_175 & 1 )
F_77 ( V_21 ) ;
return V_201 ;
}
static void F_81 ( const struct V_202 * V_203 , void * V_204 )
{
int * V_205 = V_204 ;
T_7 V_206 ;
if ( * V_205 == - 1 )
return;
if ( V_203 -> type == V_207 ) {
struct V_208 * V_208 =
(struct V_208 * ) V_203 ;
unsigned long V_209 =
( unsigned long ) & V_208 -> V_210 -
( unsigned long ) & V_208 -> type ;
unsigned long V_211 =
( unsigned long ) & V_208 -> V_212 -
( unsigned long ) & V_208 -> type ;
if ( V_208 -> V_67 == 0 )
return;
if ( V_208 -> V_213 > V_209 ) {
V_206 =
V_208 -> V_210 ;
} else if ( V_208 -> V_213 > V_211 ) {
V_206 = V_208 -> V_212 ;
} else {
* V_205 = - 1 ;
return;
}
if ( * V_205 == 0 ) {
if ( V_206 > 0 ) {
* V_205 = V_206 ;
} else {
* V_205 = - 1 ;
}
} else if ( * V_205 > 0 &&
* V_205 != V_206 ) {
* V_205 = - 1 ;
}
}
}
static int F_82 ( void )
{
int V_205 = 0 ;
F_83 ( F_81 , ( void * ) & V_205 ) ;
if ( V_205 < 1 )
return V_214 ;
return V_205 ;
}
static int F_84 ( struct V_20 * V_21 , T_1 V_215 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
T_1 V_216 ;
T_1 V_217 ;
V_16 = V_23 -> V_34 [ 2 ] ;
if ( ! V_16 )
return - V_35 ;
F_15 ( V_16 , V_218 , & V_216 ) ;
if ( V_215 == 0 ) {
V_216 &= ~ V_219 ;
F_41 ( V_16 , V_218 ,
V_216 & ~ V_220 ) ;
F_15 ( V_16 , V_221 , & V_217 ) ;
V_217 &= ~ V_222 ;
V_217 |= V_223 ;
} else {
const int V_224 = 64 ;
const T_1 V_225 = V_23 -> V_205 ;
unsigned long long V_226 ;
V_226 = ( unsigned long long ) V_225 *
V_224 * 1000000 ;
F_85 ( V_226 , V_215 ) ;
if ( ! V_226 || V_226 > V_220 )
return - V_4 ;
V_216 = V_220 & V_226 ;
F_33 ( V_16 , V_218 ,
V_219 | V_216 ) ;
F_15 ( V_16 , V_221 , & V_217 ) ;
V_217 &= ~ V_222 ;
V_217 |= V_227 ;
}
F_33 ( V_16 , V_221 , V_217 ) ;
return V_215 ;
}
static int F_86 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
const T_1 V_224 = 64 ;
const T_1 V_225 = V_23 -> V_205 ;
unsigned long long V_228 ;
T_1 V_229 ;
V_16 = V_23 -> V_34 [ 2 ] ;
if ( ! V_16 )
return - V_35 ;
F_15 ( V_16 , V_218 , & V_229 ) ;
V_229 &= V_220 ;
if ( ! V_229 )
return 0 ;
V_228 = ( unsigned long long ) V_225 *
1000000 * V_224 ;
F_85 ( V_228 , V_229 ) ;
return ( int ) V_228 ;
}
static void F_87 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_230 ;
F_15 ( V_23 -> V_107 , V_108 , & V_230 ) ;
V_230 &= ~ 0x3 ;
F_33 ( V_23 -> V_107 , V_108 ,
V_230 | V_231 ) ;
V_21 -> F_84 = F_84 ;
V_21 -> F_86 = F_86 ;
}
static void F_88 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_230 ;
F_15 ( V_23 -> V_107 , V_108 , & V_230 ) ;
V_230 &= ~ 0x3 ;
F_33 ( V_23 -> V_107 , V_108 ,
V_230 | V_232 ) ;
}
static void F_89 ( struct V_22 * V_23 )
{
V_23 -> V_233 = F_90 (
& V_23 -> V_11 -> V_16 [ 0 ] -> V_96 ,
V_234 ) ;
if ( F_54 ( ! V_23 -> V_233 ) )
F_45 ( V_235 ,
L_72 ) ;
}
static void F_91 ( struct V_22 * V_23 )
{
if ( F_63 ( V_23 -> V_233 ) )
F_92 ( V_23 -> V_233 ) ;
else
F_45 ( V_103 ,
L_73 ,
V_23 -> V_11 -> V_12 ) ;
V_23 -> V_233 = NULL ;
}
static void F_93 ( struct V_11 * V_11 )
{
struct V_20 * V_21 = V_11 -> V_21 ;
struct V_22 * V_23 ;
if ( F_54 ( ! V_21 || ! V_21 -> V_24 ) ) {
F_16 ( L_74 __FILE__ L_75 ,
V_111 , & V_11 -> V_16 [ 0 ] -> V_96 ) ;
F_45 ( V_103 , L_76 ) ;
return;
}
V_23 = V_21 -> V_24 ;
F_16 ( L_74 __FILE__ L_77 ,
V_111 , V_21 , & V_11 -> V_16 [ 0 ] -> V_96 ) ;
if ( V_23 -> V_136 )
F_88 ( V_21 ) ;
F_91 ( V_23 ) ;
F_94 ( V_21 -> V_96 ) ;
F_31 ( L_78 , V_21 -> V_236 ) ;
F_10 ( V_21 -> V_236 ) ;
F_95 ( V_21 ) ;
V_11 -> V_21 = NULL ;
}
static int F_96 ( struct V_11 * V_11 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_92 ;
struct V_237 V_69 [ 2 ] ;
V_69 [ 0 ] . type = V_238 ;
V_69 [ 0 ] . V_67 = V_48 ;
V_69 [ 0 ] . V_239 = false ;
V_69 [ 1 ] . type = V_240 ;
V_69 [ 1 ] . V_67 = V_241 ;
V_69 [ 1 ] . V_239 = true ;
V_21 = F_97 ( V_11 -> V_12 , F_98 ( V_69 ) , V_69 ,
sizeof( * V_23 ) ) ;
if ( F_54 ( ! V_21 ) )
return - V_131 ;
F_16 ( L_74 __FILE__ L_77 ,
V_111 , V_21 , & V_11 -> V_16 [ 0 ] -> V_96 ) ;
V_23 = V_21 -> V_24 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_11 = V_11 ;
V_11 -> V_21 = V_21 ;
V_21 -> V_242 = V_243 ;
V_21 -> V_244 = V_245 ;
V_21 -> V_246 = V_245 ;
V_21 -> V_247 = L_79 ;
V_21 -> V_248 = V_249 ;
V_21 -> V_236 = F_99 ( V_15 , L_80 ,
V_11 -> V_12 ) ;
V_21 -> V_250 = F_100 ( V_11 -> V_16 [ 0 ] ) ;
V_21 -> V_251 = NULL ;
V_92 = F_62 ( V_21 , V_11 ) ;
if ( F_54 ( V_92 < 0 ) )
goto V_252;
if ( V_23 -> V_135 )
V_21 -> V_253 = V_254 ;
else
V_21 -> V_253 = V_255 ;
F_14 ( V_21 ) ;
V_21 -> V_96 = & V_11 -> V_16 [ 0 ] -> V_96 ;
V_21 -> V_256 = F_77 ;
if ( V_23 -> V_136 )
F_87 ( V_21 ) ;
if ( F_54 ( F_101 ( V_21 ) ) ) {
F_16 ( L_74 __FILE__
L_81 , V_111 ) ;
V_92 = - V_4 ;
goto V_252;
}
V_23 -> V_88 . V_55 = 0 ;
V_23 -> V_88 . V_33 = - 1 ;
V_23 -> V_88 . V_2 = - 1 ;
V_23 -> V_88 . V_5 = - 1 ;
V_23 -> V_88 . V_106 = - 1 ;
V_23 -> V_88 . V_9 = - 1 ;
F_89 ( V_23 ) ;
V_23 -> V_205 = F_82 () ;
return 0 ;
V_252:
F_10 ( V_21 -> V_236 ) ;
F_95 ( V_21 ) ;
V_11 -> V_21 = NULL ;
return V_92 ;
}
static int T_8 F_102 ( struct V_25 * V_16 ,
const struct V_257 * V_258 )
{
int V_92 , V_91 = 0 ;
struct V_11 * V_11 ;
F_103 ( & V_259 ) ;
if ( F_54 ( V_260 >= 1 ) ) {
F_104 ( & V_259 ) ;
return - V_35 ;
}
V_260 ++ ;
V_92 = F_61 () ;
if ( F_54 ( V_92 < 0 ) )
goto V_252;
F_7 (i7core_dev, &i7core_edac_list, list) {
V_91 ++ ;
V_92 = F_96 ( V_11 ) ;
if ( F_54 ( V_92 < 0 ) )
goto V_261;
}
if ( ! V_91 ) {
V_92 = - V_35 ;
goto V_261;
}
F_45 ( V_129 ,
L_82 ,
V_91 ) ;
F_104 ( & V_259 ) ;
return 0 ;
V_261:
F_7 (i7core_dev, &i7core_edac_list, list)
F_93 ( V_11 ) ;
F_50 () ;
V_252:
F_104 ( & V_259 ) ;
return V_92 ;
}
static void T_9 F_105 ( struct V_25 * V_16 )
{
struct V_11 * V_11 ;
F_16 ( __FILE__ L_27 , V_111 ) ;
F_103 ( & V_259 ) ;
if ( F_54 ( ! V_260 ) ) {
F_104 ( & V_259 ) ;
return;
}
F_7 (i7core_dev, &i7core_edac_list, list)
F_93 ( V_11 ) ;
F_50 () ;
V_260 -- ;
F_104 ( & V_259 ) ;
}
static int T_6 F_106 ( void )
{
int V_262 ;
F_107 ( L_74 __FILE__ L_27 , V_111 ) ;
F_108 () ;
if ( V_263 )
F_52 ( V_132 ) ;
V_262 = F_109 ( & V_264 ) ;
if ( V_262 >= 0 ) {
F_110 ( & V_265 ) ;
return 0 ;
}
F_45 ( V_103 , L_83 ,
V_262 ) ;
return V_262 ;
}
static void T_10 F_111 ( void )
{
F_107 ( L_74 __FILE__ L_27 , V_111 ) ;
F_112 ( & V_264 ) ;
F_113 ( & V_265 ) ;
}
