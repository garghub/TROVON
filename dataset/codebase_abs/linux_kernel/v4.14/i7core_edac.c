static inline int F_1 ( T_1 V_1 )
{
return ( V_1 & 0x3 ) + 1 ;
}
static inline int F_2 ( T_1 V_2 )
{
static const int V_3 [] = { 1 , 2 , 4 , - V_4 } ;
return V_3 [ V_2 & 0x3 ] ;
}
static inline int F_3 ( T_1 V_5 )
{
static const int V_6 [] = { 4 , 8 , 16 , - V_4 } ;
return V_6 [ V_5 & 0x3 ] ;
}
static inline int F_4 ( T_1 V_7 )
{
static const int V_8 [] = {
1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , - V_4 , - V_4 , - V_4 ,
} ;
return V_8 [ V_7 & 0x7 ] ;
}
static inline int F_5 ( T_1 V_9 )
{
static const int V_10 [] = {
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
F_16 ( 0 , L_1 ,
V_23 -> V_11 -> V_12 , V_23 -> V_37 . V_38 ,
V_23 -> V_37 . V_40 , V_23 -> V_37 . V_42 , V_23 -> V_37 . V_44 ) ;
if ( F_17 ( V_23 ) ) {
F_16 ( 0 , L_2 , F_18 ( V_23 ) ? 8 : 4 ) ;
if ( F_18 ( V_23 ) )
V_29 = V_45 ;
else
V_29 = V_46 ;
} else {
F_16 ( 0 , L_3 ) ;
V_29 = V_47 ;
}
F_16 ( 0 , L_4 ,
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
F_16 ( 0 , L_5 , V_26 ) ;
continue;
}
if ( F_20 ( V_23 , V_26 ) ) {
F_16 ( 0 , L_6 , V_26 ) ;
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
F_16 ( 0 , L_7 ,
V_26 ,
F_21 ( V_23 -> V_37 . V_44 , V_26 ) , F_22 ( V_23 -> V_37 . V_44 , V_26 ) ,
V_49 ,
V_23 -> V_55 [ V_26 ] . V_56 ? L_8 : L_9 ,
V_23 -> V_55 [ V_26 ] . V_56 ? L_10 : L_9 ,
V_23 -> V_55 [ V_26 ] . V_60 ? L_11 : L_9 ,
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
F_16 ( 0 , L_12 ,
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
L_13 ,
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
F_16 ( 1 , L_14 , V_26 ) ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
F_16 ( 1 , L_15 ,
( V_51 [ V_27 ] >> 27 ) & 0x1 ,
( V_51 [ V_27 ] >> 24 ) & 0x7 ,
( V_51 [ V_27 ] & ( ( 1 << 24 ) - 1 ) ) ) ;
}
return 0 ;
}
static int F_31 ( const struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
V_23 -> V_88 . V_89 = 0 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return - V_35 ;
F_32 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , 0 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_49 , T_4 V_95 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_96 ;
if ( V_23 -> V_88 . V_89 )
F_31 ( V_21 ) ;
V_96 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( ( V_96 < 0 ) || ( V_51 > 3 ) )
return - V_97 ;
V_23 -> V_88 . V_98 = ( T_1 ) V_51 ;
return V_95 ;
}
static T_3 F_36 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_49 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_16 , V_23 -> V_88 . V_98 ) ;
}
static T_3 F_37 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_49 , T_4 V_95 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_96 ;
if ( V_23 -> V_88 . V_89 )
F_31 ( V_21 ) ;
V_96 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( ( V_96 < 0 ) || ( V_51 > 7 ) )
return - V_97 ;
V_23 -> V_88 . type = ( T_1 ) V_51 ;
return V_95 ;
}
static T_3 F_38 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_49 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_16 , V_23 -> V_88 . type ) ;
}
static T_3 F_39 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_49 , T_4 V_95 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
unsigned long V_51 ;
int V_96 ;
if ( V_23 -> V_88 . V_89 )
F_31 ( V_21 ) ;
V_96 = F_35 ( V_49 , 10 , & V_51 ) ;
if ( V_96 < 0 )
return - V_97 ;
V_23 -> V_88 . V_99 = ( T_1 ) V_51 ;
return V_95 ;
}
static T_3 F_40 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_49 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
return sprintf ( V_49 , L_16 , V_23 -> V_88 . V_99 ) ;
}
static int F_41 ( struct V_25 * V_92 , const int V_100 , const T_1 V_101 )
{
T_1 V_102 ;
int V_95 ;
F_16 ( 0 , L_17 ,
V_92 -> V_103 -> V_104 , F_42 ( V_92 -> V_105 ) , F_43 ( V_92 -> V_105 ) ,
V_100 , V_101 ) ;
for ( V_95 = 0 ; V_95 < 10 ; V_95 ++ ) {
if ( V_95 )
F_44 ( 100 ) ;
F_32 ( V_92 , V_100 , V_101 ) ;
F_15 ( V_92 , V_100 , & V_102 ) ;
if ( V_102 == V_101 )
return 0 ;
}
F_45 ( V_106 , L_18
L_19 ,
V_92 -> V_103 -> V_104 , F_42 ( V_92 -> V_105 ) , F_43 ( V_92 -> V_105 ) ,
V_100 , V_101 , V_102 ) ;
return - V_4 ;
}
static T_3 F_46 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
const char * V_49 , T_4 V_95 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_107 ;
T_5 V_108 = 0 ;
int V_96 ;
long V_89 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return 0 ;
V_96 = F_35 ( V_49 , 10 , & V_89 ) ;
if ( ( V_96 < 0 ) )
return 0 ;
if ( V_89 ) {
V_23 -> V_88 . V_89 = 1 ;
} else {
F_31 ( V_21 ) ;
return V_95 ;
}
if ( V_23 -> V_88 . V_33 < 0 )
V_108 |= 1LL << 41 ;
else {
if ( V_23 -> V_55 [ V_23 -> V_88 . V_55 ] . V_1 > 2 )
V_108 |= ( V_23 -> V_88 . V_33 & 0x3LL ) << 35 ;
else
V_108 |= ( V_23 -> V_88 . V_33 & 0x1LL ) << 36 ;
}
if ( V_23 -> V_88 . V_2 < 0 )
V_108 |= 1LL << 40 ;
else {
if ( V_23 -> V_55 [ V_23 -> V_88 . V_55 ] . V_1 > 2 )
V_108 |= ( V_23 -> V_88 . V_2 & 0x1LL ) << 34 ;
else
V_108 |= ( V_23 -> V_88 . V_2 & 0x3LL ) << 34 ;
}
if ( V_23 -> V_88 . V_5 < 0 )
V_108 |= 1LL << 39 ;
else
V_108 |= ( V_23 -> V_88 . V_5 & 0x15LL ) << 30 ;
if ( V_23 -> V_88 . V_109 < 0 )
V_108 |= 1LL << 38 ;
else
V_108 |= ( V_23 -> V_88 . V_109 & 0xffff ) << 14 ;
if ( V_23 -> V_88 . V_9 < 0 )
V_108 |= 1LL << 37 ;
else
V_108 |= ( V_23 -> V_88 . V_9 & 0x3fff ) ;
V_107 = ( V_23 -> V_88 . type & 1 ) |
( V_23 -> V_88 . V_98 & 0x3 ) << 1 |
( V_23 -> V_88 . type & 0x6 ) << ( 3 - 1 ) ;
F_32 ( V_23 -> V_110 ,
V_111 , 0x2 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_112 , V_108 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_112 + 4 , V_108 >> 32L ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_113 , V_23 -> V_88 . V_99 ) ;
F_41 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , V_107 ) ;
F_32 ( V_23 -> V_110 ,
V_111 , 8 ) ;
F_16 ( 0 , L_20 ,
V_108 , V_23 -> V_88 . V_99 , V_107 ) ;
return V_95 ;
}
static T_3 F_47 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_49 )
{
struct V_20 * V_21 = F_34 ( V_92 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_107 ;
if ( ! V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] )
return 0 ;
F_15 ( V_23 -> V_52 [ V_23 -> V_88 . V_55 ] [ 0 ] ,
V_90 , & V_107 ) ;
F_16 ( 0 , L_21 , V_107 ) ;
if ( V_107 & 0x0c )
V_23 -> V_88 . V_89 = 1 ;
return sprintf ( V_49 , L_22 , V_23 -> V_88 . V_89 ) ;
}
static void F_48 ( struct V_91 * V_91 )
{
F_16 ( 1 , L_23 , F_49 ( V_91 ) ) ;
F_10 ( V_91 ) ;
}
static void F_50 ( struct V_91 * V_91 )
{
F_16 ( 1 , L_23 , F_49 ( V_91 ) ) ;
F_10 ( V_91 ) ;
}
static int F_51 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
int V_96 ;
V_23 -> V_114 = F_9 ( sizeof( * V_23 -> V_114 ) , V_15 ) ;
if ( ! V_23 -> V_114 )
return - V_115 ;
V_23 -> V_114 -> type = & V_116 ;
V_23 -> V_114 -> V_103 = V_21 -> V_92 . V_103 ;
F_52 ( V_23 -> V_114 ) ;
V_23 -> V_114 -> V_117 = & V_21 -> V_92 ;
F_53 ( V_23 -> V_114 , L_24 ) ;
F_54 ( V_23 -> V_114 , V_21 ) ;
F_16 ( 1 , L_25 , F_49 ( V_23 -> V_114 ) ) ;
V_96 = F_55 ( V_23 -> V_114 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! V_23 -> V_118 ) {
V_23 -> V_119 = F_9 ( sizeof( * V_23 -> V_119 ) ,
V_15 ) ;
if ( ! V_23 -> V_119 ) {
F_56 ( V_23 -> V_114 ) ;
F_57 ( V_23 -> V_114 ) ;
return - V_115 ;
}
V_23 -> V_119 -> type = & V_120 ;
V_23 -> V_119 -> V_103 = V_21 -> V_92 . V_103 ;
F_52 ( V_23 -> V_119 ) ;
V_23 -> V_119 -> V_117 = & V_21 -> V_92 ;
F_53 ( V_23 -> V_119 , L_26 ) ;
F_54 ( V_23 -> V_119 , V_21 ) ;
F_16 ( 1 , L_25 , F_49 ( V_23 -> V_119 ) ) ;
V_96 = F_55 ( V_23 -> V_119 ) ;
if ( V_96 < 0 )
return V_96 ;
}
return 0 ;
}
static void F_58 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
F_16 ( 1 , L_27 ) ;
if ( ! V_23 -> V_118 ) {
F_56 ( V_23 -> V_119 ) ;
F_57 ( V_23 -> V_119 ) ;
}
F_56 ( V_23 -> V_114 ) ;
F_57 ( V_23 -> V_114 ) ;
}
static void F_59 ( struct V_11 * V_11 )
{
int V_26 ;
F_16 ( 0 , L_27 ) ;
for ( V_26 = 0 ; V_26 < V_11 -> V_17 ; V_26 ++ ) {
struct V_25 * V_16 = V_11 -> V_16 [ V_26 ] ;
if ( ! V_16 )
continue;
F_16 ( 0 , L_28 ,
V_16 -> V_103 -> V_104 ,
F_42 ( V_16 -> V_105 ) , F_43 ( V_16 -> V_105 ) ) ;
F_60 ( V_16 ) ;
}
}
static void F_61 ( void )
{
struct V_11 * V_11 , * V_121 ;
F_62 (i7core_dev, tmp, &i7core_edac_list, list) {
F_59 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
static void T_6 F_63 ( const struct V_13 * V_14 )
{
struct V_25 * V_16 = NULL ;
int V_26 ;
while ( V_14 && V_14 -> V_122 ) {
V_16 = F_64 ( V_123 , V_14 -> V_122 [ 0 ] . V_124 , NULL ) ;
if ( F_65 ( ! V_16 ) ) {
for ( V_26 = 0 ; V_26 < V_125 ; V_26 ++ )
F_66 ( 255 - V_26 ) ;
}
F_60 ( V_16 ) ;
V_14 ++ ;
}
}
static unsigned F_67 ( void )
{
int V_126 = 0 , V_103 ;
struct V_127 * V_128 = NULL ;
while ( ( V_128 = F_68 ( V_128 ) ) != NULL ) {
V_103 = V_128 -> V_104 ;
F_16 ( 0 , L_29 , V_103 ) ;
if ( V_103 > V_126 )
V_126 = V_103 ;
}
F_16 ( 0 , L_30 , V_126 ) ;
return V_126 ;
}
static int F_69 ( struct V_25 * * V_129 ,
const struct V_13 * V_14 ,
const unsigned V_130 ,
const unsigned V_126 )
{
struct V_11 * V_11 ;
const struct V_131 * V_132 = & V_14 -> V_122 [ V_130 ] ;
struct V_25 * V_16 = NULL ;
T_2 V_103 = 0 ;
T_2 V_12 = 0 ;
V_16 = F_64 ( V_123 ,
V_132 -> V_124 , * V_129 ) ;
if ( V_132 -> V_124 == V_133 && ! V_16 ) {
F_70 ( * V_129 ) ;
V_16 = F_64 ( V_123 ,
V_134 , * V_129 ) ;
}
if ( V_132 -> V_124 == V_135 &&
! V_16 ) {
F_70 ( * V_129 ) ;
V_16 = F_64 ( V_123 ,
V_136 ,
* V_129 ) ;
}
if ( ! V_16 ) {
if ( * V_129 ) {
* V_129 = V_16 ;
return 0 ;
}
if ( V_132 -> V_137 )
return 0 ;
if ( V_130 == 0 )
return - V_35 ;
F_45 ( V_138 ,
L_31 ,
V_132 -> V_92 , V_132 -> V_139 ,
V_123 , V_132 -> V_124 ) ;
return - V_35 ;
}
V_103 = V_16 -> V_103 -> V_104 ;
V_12 = V_126 - V_103 ;
V_11 = F_6 ( V_12 ) ;
if ( ! V_11 ) {
V_11 = F_8 ( V_12 , V_14 ) ;
if ( ! V_11 ) {
F_60 ( V_16 ) ;
return - V_115 ;
}
}
if ( V_11 -> V_16 [ V_130 ] ) {
F_45 ( V_106 ,
L_32
L_33 ,
V_103 , V_132 -> V_92 , V_132 -> V_139 ,
V_123 , V_132 -> V_124 ) ;
F_60 ( V_16 ) ;
return - V_35 ;
}
V_11 -> V_16 [ V_130 ] = V_16 ;
if ( F_65 ( F_42 ( V_16 -> V_105 ) != V_132 -> V_92 ||
F_43 ( V_16 -> V_105 ) != V_132 -> V_139 ) ) {
F_45 ( V_106 ,
L_34
L_35 ,
V_123 , V_132 -> V_124 ,
V_103 , F_42 ( V_16 -> V_105 ) , F_43 ( V_16 -> V_105 ) ,
V_103 , V_132 -> V_92 , V_132 -> V_139 ) ;
return - V_35 ;
}
if ( F_65 ( F_71 ( V_16 ) < 0 ) ) {
F_45 ( V_106 ,
L_36
L_33 ,
V_103 , V_132 -> V_92 , V_132 -> V_139 ,
V_123 , V_132 -> V_124 ) ;
return - V_35 ;
}
F_16 ( 0 , L_37 ,
V_12 , V_103 , V_132 -> V_92 ,
V_132 -> V_139 ,
V_123 , V_132 -> V_124 ) ;
F_70 ( V_16 ) ;
* V_129 = V_16 ;
return 0 ;
}
static int F_72 ( void )
{
int V_26 , V_96 , V_126 ;
struct V_25 * V_16 = NULL ;
const struct V_13 * V_14 = V_140 ;
V_126 = F_67 () ;
while ( V_14 && V_14 -> V_122 ) {
for ( V_26 = 0 ; V_26 < V_14 -> V_17 ; V_26 ++ ) {
V_16 = NULL ;
do {
V_96 = F_69 ( & V_16 , V_14 , V_26 ,
V_126 ) ;
if ( V_96 < 0 ) {
if ( V_26 == 0 ) {
V_26 = V_14 -> V_17 ;
break;
}
F_61 () ;
return - V_35 ;
}
} while ( V_16 );
}
V_14 ++ ;
}
return 0 ;
}
static int F_73 ( struct V_20 * V_21 ,
struct V_11 * V_11 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
int V_26 , V_139 , V_141 ;
char * V_142 ;
V_23 -> V_118 = false ;
V_23 -> V_143 = false ;
for ( V_26 = 0 ; V_26 < V_11 -> V_17 ; V_26 ++ ) {
V_16 = V_11 -> V_16 [ V_26 ] ;
if ( ! V_16 )
continue;
V_139 = F_43 ( V_16 -> V_105 ) ;
V_141 = F_42 ( V_16 -> V_105 ) ;
if ( V_141 == 3 ) {
if ( F_65 ( V_139 > V_144 ) )
goto error;
V_23 -> V_34 [ V_139 ] = V_16 ;
} else if ( F_74 ( V_141 >= 4 && V_141 < 4 + V_48 ) ) {
if ( F_65 ( V_139 > V_145 ) )
goto error;
V_23 -> V_52 [ V_141 - 4 ] [ V_139 ] = V_16 ;
} else if ( ! V_141 && ! V_139 ) {
V_23 -> V_110 = V_16 ;
switch ( V_16 -> V_91 ) {
case V_133 :
V_142 = L_38 ;
V_23 -> V_143 = false ;
break;
case V_136 :
V_142 = L_39 ;
V_23 -> V_143 = false ;
break;
case V_135 :
V_142 = L_40 ;
V_23 -> V_143 = false ;
break;
case V_134 :
V_142 = L_41 ;
V_23 -> V_143 = true ;
break;
case V_146 :
V_142 = L_42 ;
V_23 -> V_143 = true ;
break;
default:
V_142 = L_43 ;
V_23 -> V_143 = false ;
}
F_16 ( 0 , L_44 , V_142 ) ;
} else
goto error;
F_16 ( 0 , L_45 ,
F_42 ( V_16 -> V_105 ) , F_43 ( V_16 -> V_105 ) ,
V_16 , V_11 -> V_12 ) ;
if ( F_42 ( V_16 -> V_105 ) == 3 &&
F_43 ( V_16 -> V_105 ) == 2 )
V_23 -> V_118 = true ;
}
return 0 ;
error:
F_45 ( V_106 , L_46
L_47 ,
V_141 , V_139 ) ;
return - V_4 ;
}
static void F_75 ( struct V_20 * V_21 ,
const int V_147 ,
const int V_148 ,
const int V_149 ,
const int V_150 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
int V_151 = 0 , V_152 = 0 , V_153 = 0 ;
if ( V_23 -> V_154 ) {
V_153 = V_150 - V_23 -> V_155 [ V_147 ] [ 2 ] ;
V_152 = V_149 - V_23 -> V_155 [ V_147 ] [ 1 ] ;
V_151 = V_148 - V_23 -> V_155 [ V_147 ] [ 0 ] ;
if ( V_153 < 0 )
V_153 += 0x7fff ;
V_23 -> V_156 [ V_147 ] [ 2 ] += V_153 ;
if ( V_152 < 0 )
V_152 += 0x7fff ;
V_23 -> V_156 [ V_147 ] [ 1 ] += V_152 ;
if ( V_151 < 0 )
V_151 += 0x7fff ;
V_23 -> V_156 [ V_147 ] [ 0 ] += V_151 ;
} else
V_23 -> V_154 = 1 ;
V_23 -> V_155 [ V_147 ] [ 2 ] = V_150 ;
V_23 -> V_155 [ V_147 ] [ 1 ] = V_149 ;
V_23 -> V_155 [ V_147 ] [ 0 ] = V_148 ;
if ( V_151 != 0 )
F_76 ( V_157 , V_21 , V_151 ,
0 , 0 , 0 ,
V_147 , 0 , - 1 , L_48 , L_9 ) ;
if ( V_152 != 0 )
F_76 ( V_157 , V_21 , V_152 ,
0 , 0 , 0 ,
V_147 , 1 , - 1 , L_48 , L_9 ) ;
if ( V_153 != 0 )
F_76 ( V_157 , V_21 , V_153 ,
0 , 0 , 0 ,
V_147 , 2 , - 1 , L_48 , L_9 ) ;
}
static void F_77 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_158 [ 3 ] [ 2 ] ;
int V_26 , V_148 , V_149 , V_150 ;
F_15 ( V_23 -> V_34 [ 2 ] , V_159 ,
& V_158 [ 0 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_160 ,
& V_158 [ 0 ] [ 1 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_161 ,
& V_158 [ 1 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_162 ,
& V_158 [ 1 ] [ 1 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_163 ,
& V_158 [ 2 ] [ 0 ] ) ;
F_15 ( V_23 -> V_34 [ 2 ] , V_164 ,
& V_158 [ 2 ] [ 1 ] ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
F_16 ( 3 , L_49 ,
( V_26 * 2 ) , V_158 [ V_26 ] [ 0 ] , ( V_26 * 2 ) + 1 , V_158 [ V_26 ] [ 1 ] ) ;
if ( V_23 -> V_55 [ V_26 ] . V_1 > 2 ) {
V_148 = F_78 ( V_158 [ V_26 ] [ 0 ] ) ;
V_149 = F_79 ( V_158 [ V_26 ] [ 0 ] ) ;
V_150 = F_78 ( V_158 [ V_26 ] [ 1 ] ) ;
} else {
V_148 = F_79 ( V_158 [ V_26 ] [ 0 ] ) +
F_78 ( V_158 [ V_26 ] [ 0 ] ) ;
V_149 = F_79 ( V_158 [ V_26 ] [ 1 ] ) +
F_78 ( V_158 [ V_26 ] [ 1 ] ) ;
V_150 = 0 ;
}
F_75 ( V_21 , V_26 , V_148 , V_149 , V_150 ) ;
}
}
static void F_80 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_165 , V_166 ;
int V_148 , V_149 , V_150 ;
if ( ! V_23 -> V_34 [ 4 ] ) {
F_16 ( 0 , L_50 ) ;
return;
}
F_15 ( V_23 -> V_34 [ 4 ] , V_167 , & V_165 ) ;
F_15 ( V_23 -> V_34 [ 4 ] , V_168 , & V_166 ) ;
V_150 = F_81 ( V_165 ) ;
V_149 = F_82 ( V_166 ) ;
V_148 = F_83 ( V_166 ) ;
if ( V_23 -> V_154 ) {
int V_151 , V_152 , V_153 ;
V_153 = V_150 - V_23 -> V_169 [ 2 ] ;
V_152 = V_149 - V_23 -> V_169 [ 1 ] ;
V_151 = V_148 - V_23 -> V_169 [ 0 ] ;
if ( V_153 < 0 )
V_153 += 0x7fff ;
V_23 -> V_170 [ 2 ] += V_153 ;
if ( V_152 < 0 )
V_152 += 0x7fff ;
V_23 -> V_170 [ 1 ] += V_152 ;
if ( V_151 < 0 )
V_151 += 0x7fff ;
V_23 -> V_170 [ 0 ] += V_151 ;
if ( V_151 | V_152 | V_153 )
F_45 ( V_106 , L_51
L_52 ,
V_151 , V_152 , V_153 ) ;
} else
V_23 -> V_154 = 1 ;
V_23 -> V_169 [ 2 ] = V_150 ;
V_23 -> V_169 [ 1 ] = V_149 ;
V_23 -> V_169 [ 0 ] = V_148 ;
}
static void F_84 ( struct V_20 * V_21 ,
const struct V_171 * V_172 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
char * V_173 , * V_174 ;
enum V_175 V_176 ;
unsigned long error = V_172 -> V_177 & 0x1ff0000l ;
bool V_178 = V_172 -> V_179 & 1ll << 61 ;
bool V_180 = V_172 -> V_179 & 1 ;
T_1 V_181 = ( V_172 -> V_177 >> 4 ) & 0x07 ;
T_1 V_182 = ( V_172 -> V_177 >> 38 ) & 0x7fff ;
T_1 V_33 = ( V_172 -> V_183 >> 16 ) & 0x3 ;
T_1 V_55 = ( V_172 -> V_183 >> 18 ) & 0x3 ;
T_1 V_184 = V_172 -> V_183 >> 32 ;
T_1 V_185 = F_85 ( & error , 32 ) ;
if ( V_178 ) {
if ( V_180 )
V_176 = V_186 ;
else
V_176 = V_187 ;
} else {
V_176 = V_157 ;
}
switch ( V_181 ) {
case 0 :
V_173 = L_53 ;
break;
case 1 :
V_173 = L_54 ;
break;
case 2 :
V_173 = L_55 ;
break;
case 3 :
V_173 = L_56 ;
break;
case 4 :
V_173 = L_57 ;
break;
default:
V_173 = L_58 ;
break;
}
switch ( V_185 ) {
case 16 :
V_174 = L_59 ;
break;
case 17 :
V_174 = L_60 ;
break;
case 18 :
V_174 = L_61 ;
break;
case 19 :
V_174 = L_62 ;
break;
case 20 :
V_174 = L_58 ;
break;
case 21 :
V_174 = L_63 ;
break;
case 22 :
V_174 = L_64 ;
break;
case 23 :
V_174 = L_65 ;
break;
case 24 :
V_174 = L_66 ;
break;
default:
V_174 = L_43 ;
}
if ( V_178 || ! V_23 -> V_118 )
F_76 ( V_176 , V_21 , V_182 ,
V_172 -> V_188 >> V_189 ,
V_172 -> V_188 & ~ V_190 ,
V_184 ,
V_55 , V_33 , - 1 ,
V_174 , V_173 ) ;
}
static void F_86 ( struct V_20 * V_21 , struct V_171 * V_172 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
F_84 ( V_21 , V_172 ) ;
if ( ! V_23 -> V_118 )
F_80 ( V_21 ) ;
else
F_77 ( V_21 ) ;
}
static int F_87 ( struct V_191 * V_192 , unsigned long V_101 ,
void * V_49 )
{
struct V_171 * V_171 = (struct V_171 * ) V_49 ;
struct V_11 * V_193 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_193 = F_6 ( V_171 -> V_194 ) ;
if ( ! V_193 )
return V_195 ;
V_21 = V_193 -> V_21 ;
V_23 = V_21 -> V_24 ;
if ( ( ( V_171 -> V_177 & 0xffff ) >> 7 ) != 1 )
return V_195 ;
if ( V_171 -> V_5 != 8 )
return V_195 ;
F_86 ( V_21 , V_171 ) ;
return V_196 ;
}
static void F_88 ( const struct V_197 * V_198 , void * V_199 )
{
int * V_200 = V_199 ;
T_7 V_201 ;
if ( * V_200 == - 1 )
return;
if ( V_198 -> type == V_202 ) {
struct V_203 * V_203 =
(struct V_203 * ) V_198 ;
unsigned long V_204 =
( unsigned long ) & V_203 -> V_205 -
( unsigned long ) & V_203 -> type ;
unsigned long V_206 =
( unsigned long ) & V_203 -> V_207 -
( unsigned long ) & V_203 -> type ;
if ( V_203 -> V_67 == 0 )
return;
if ( V_203 -> V_208 > V_204 ) {
V_201 =
V_203 -> V_205 ;
} else if ( V_203 -> V_208 > V_206 ) {
V_201 = V_203 -> V_207 ;
} else {
* V_200 = - 1 ;
return;
}
if ( * V_200 == 0 ) {
if ( V_201 > 0 ) {
* V_200 = V_201 ;
} else {
* V_200 = - 1 ;
}
} else if ( * V_200 > 0 &&
* V_200 != V_201 ) {
* V_200 = - 1 ;
}
}
}
static int F_89 ( void )
{
int V_200 = 0 ;
F_90 ( F_88 , ( void * ) & V_200 ) ;
if ( V_200 < 1 )
return V_209 ;
return V_200 ;
}
static int F_91 ( struct V_20 * V_21 , T_1 V_210 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
T_1 V_211 ;
T_1 V_212 ;
V_16 = V_23 -> V_34 [ 2 ] ;
if ( ! V_16 )
return - V_35 ;
F_15 ( V_16 , V_213 , & V_211 ) ;
if ( V_210 == 0 ) {
V_211 &= ~ V_214 ;
F_41 ( V_16 , V_213 ,
V_211 & ~ V_215 ) ;
F_15 ( V_16 , V_216 , & V_212 ) ;
V_212 &= ~ V_217 ;
V_212 |= V_218 ;
} else {
const int V_219 = 64 ;
const T_1 V_220 = V_23 -> V_200 ;
unsigned long long V_221 ;
V_221 = ( unsigned long long ) V_220 *
V_219 * 1000000 ;
F_92 ( V_221 , V_210 ) ;
if ( ! V_221 || V_221 > V_215 )
return - V_4 ;
V_211 = V_215 & V_221 ;
F_32 ( V_16 , V_213 ,
V_214 | V_211 ) ;
F_15 ( V_16 , V_216 , & V_212 ) ;
V_212 &= ~ V_217 ;
V_212 |= V_222 ;
}
F_32 ( V_16 , V_216 , V_212 ) ;
return V_210 ;
}
static int F_93 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_25 * V_16 ;
const T_1 V_219 = 64 ;
const T_1 V_220 = V_23 -> V_200 ;
unsigned long long V_223 ;
T_1 V_224 ;
V_16 = V_23 -> V_34 [ 2 ] ;
if ( ! V_16 )
return - V_35 ;
F_15 ( V_16 , V_213 , & V_224 ) ;
V_224 &= V_215 ;
if ( ! V_224 )
return 0 ;
V_223 = ( unsigned long long ) V_220 *
1000000 * V_219 ;
F_92 ( V_223 , V_224 ) ;
return ( int ) V_223 ;
}
static void F_94 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_225 ;
F_15 ( V_23 -> V_110 , V_111 , & V_225 ) ;
V_225 &= ~ 0x3 ;
F_32 ( V_23 -> V_110 , V_111 ,
V_225 | V_226 ) ;
V_21 -> F_91 = F_91 ;
V_21 -> F_93 = F_93 ;
}
static void F_95 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
T_1 V_225 ;
F_15 ( V_23 -> V_110 , V_111 , & V_225 ) ;
V_225 &= ~ 0x3 ;
F_32 ( V_23 -> V_110 , V_111 ,
V_225 | V_227 ) ;
}
static void F_96 ( struct V_22 * V_23 )
{
V_23 -> V_228 = F_97 (
& V_23 -> V_11 -> V_16 [ 0 ] -> V_92 ,
V_229 ) ;
if ( F_65 ( ! V_23 -> V_228 ) )
F_45 ( V_230 ,
L_67 ) ;
}
static void F_98 ( struct V_22 * V_23 )
{
if ( F_74 ( V_23 -> V_228 ) )
F_99 ( V_23 -> V_228 ) ;
else
F_45 ( V_106 ,
L_68 ,
V_23 -> V_11 -> V_12 ) ;
V_23 -> V_228 = NULL ;
}
static void F_100 ( struct V_11 * V_11 )
{
struct V_20 * V_21 = V_11 -> V_21 ;
struct V_22 * V_23 ;
if ( F_65 ( ! V_21 || ! V_21 -> V_24 ) ) {
F_16 ( 0 , L_69 , & V_11 -> V_16 [ 0 ] -> V_92 ) ;
F_45 ( V_106 , L_70 ) ;
return;
}
V_23 = V_21 -> V_24 ;
F_16 ( 0 , L_71 , V_21 , & V_11 -> V_16 [ 0 ] -> V_92 ) ;
if ( V_23 -> V_143 )
F_95 ( V_21 ) ;
F_98 ( V_23 ) ;
F_58 ( V_21 ) ;
F_101 ( V_21 -> V_16 ) ;
F_16 ( 1 , L_72 , V_21 -> V_231 ) ;
F_10 ( V_21 -> V_231 ) ;
F_102 ( V_21 ) ;
V_11 -> V_21 = NULL ;
}
static int F_103 ( struct V_11 * V_11 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_96 ;
struct V_232 V_69 [ 2 ] ;
V_69 [ 0 ] . type = V_233 ;
V_69 [ 0 ] . V_67 = V_48 ;
V_69 [ 0 ] . V_234 = false ;
V_69 [ 1 ] . type = V_235 ;
V_69 [ 1 ] . V_67 = V_236 ;
V_69 [ 1 ] . V_234 = true ;
V_21 = F_104 ( V_11 -> V_12 , F_105 ( V_69 ) , V_69 ,
sizeof( * V_23 ) ) ;
if ( F_65 ( ! V_21 ) )
return - V_115 ;
F_16 ( 0 , L_71 , V_21 , & V_11 -> V_16 [ 0 ] -> V_92 ) ;
V_23 = V_21 -> V_24 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_11 = V_11 ;
V_11 -> V_21 = V_21 ;
V_21 -> V_237 = V_238 ;
V_21 -> V_239 = V_240 ;
V_21 -> V_241 = V_240 ;
V_21 -> V_242 = L_73 ;
V_21 -> V_231 = F_106 ( V_15 , L_74 ,
V_11 -> V_12 ) ;
V_21 -> F_49 = F_107 ( V_11 -> V_16 [ 0 ] ) ;
V_21 -> V_243 = NULL ;
V_96 = F_73 ( V_21 , V_11 ) ;
if ( F_65 ( V_96 < 0 ) )
goto V_244;
F_14 ( V_21 ) ;
V_21 -> V_16 = & V_11 -> V_16 [ 0 ] -> V_92 ;
if ( V_23 -> V_143 )
F_94 ( V_21 ) ;
if ( F_65 ( F_108 ( V_21 , V_245 ) ) ) {
F_16 ( 0 , L_75 ) ;
V_96 = - V_4 ;
goto V_244;
}
if ( F_51 ( V_21 ) ) {
F_16 ( 0 , L_76 ) ;
F_101 ( V_21 -> V_16 ) ;
V_96 = - V_4 ;
goto V_244;
}
V_23 -> V_88 . V_55 = 0 ;
V_23 -> V_88 . V_33 = - 1 ;
V_23 -> V_88 . V_2 = - 1 ;
V_23 -> V_88 . V_5 = - 1 ;
V_23 -> V_88 . V_109 = - 1 ;
V_23 -> V_88 . V_9 = - 1 ;
F_96 ( V_23 ) ;
V_23 -> V_200 = F_89 () ;
return 0 ;
V_244:
F_10 ( V_21 -> V_231 ) ;
F_102 ( V_21 ) ;
V_11 -> V_21 = NULL ;
return V_96 ;
}
static int F_109 ( struct V_25 * V_16 , const struct V_246 * V_247 )
{
int V_96 , V_95 = 0 ;
struct V_11 * V_11 ;
F_110 ( & V_248 ) ;
if ( F_65 ( V_249 >= 1 ) ) {
F_111 ( & V_248 ) ;
return - V_35 ;
}
V_249 ++ ;
V_96 = F_72 () ;
if ( F_65 ( V_96 < 0 ) )
goto V_244;
F_7 (i7core_dev, &i7core_edac_list, list) {
V_95 ++ ;
V_96 = F_103 ( V_11 ) ;
if ( F_65 ( V_96 < 0 ) )
goto V_250;
}
if ( ! V_95 ) {
V_96 = - V_35 ;
goto V_250;
}
F_45 ( V_138 ,
L_77 ,
V_95 ) ;
F_111 ( & V_248 ) ;
return 0 ;
V_250:
F_7 (i7core_dev, &i7core_edac_list, list)
F_100 ( V_11 ) ;
F_61 () ;
V_244:
F_111 ( & V_248 ) ;
return V_96 ;
}
static void F_112 ( struct V_25 * V_16 )
{
struct V_11 * V_11 ;
F_16 ( 0 , L_27 ) ;
F_110 ( & V_248 ) ;
if ( F_65 ( ! V_249 ) ) {
F_111 ( & V_248 ) ;
return;
}
F_7 (i7core_dev, &i7core_edac_list, list)
F_100 ( V_11 ) ;
F_61 () ;
V_249 -- ;
F_111 ( & V_248 ) ;
}
static int T_6 F_113 ( void )
{
int V_251 ;
F_16 ( 2 , L_27 ) ;
F_114 () ;
if ( V_252 )
F_63 ( V_140 ) ;
V_251 = F_115 ( & V_253 ) ;
if ( V_251 >= 0 ) {
F_116 ( & V_254 ) ;
return 0 ;
}
F_45 ( V_106 , L_78 ,
V_251 ) ;
return V_251 ;
}
static void T_8 F_117 ( void )
{
F_16 ( 2 , L_27 ) ;
F_118 ( & V_253 ) ;
F_119 ( & V_254 ) ;
}
