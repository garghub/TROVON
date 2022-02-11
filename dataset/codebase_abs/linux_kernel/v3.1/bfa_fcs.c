static void
F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_2 ( & V_5 -> V_6 ) ;
}
void
F_3 ( struct V_2 * V_3 , struct V_7 * V_8 , struct V_4 * V_5 ,
T_1 V_9 )
{
int V_10 ;
struct V_11 * V_12 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_9 = V_9 ;
V_8 -> V_3 = V_13 ;
F_4 () ;
for ( V_10 = 0 ; V_10 < sizeof( V_14 ) / sizeof( V_14 [ 0 ] ) ; V_10 ++ ) {
V_12 = & V_14 [ V_10 ] ;
if ( V_12 -> V_15 )
V_12 -> V_15 ( V_3 ) ;
}
}
void
F_5 ( struct V_2 * V_3 )
{
int V_10 ;
struct V_11 * V_12 ;
for ( V_10 = 0 ; V_10 < sizeof( V_14 ) / sizeof( V_14 [ 0 ] ) ; V_10 ++ ) {
V_12 = & V_14 [ V_10 ] ;
if ( V_12 -> V_16 )
V_12 -> V_16 ( V_3 ) ;
}
}
void
F_6 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_21 . V_20 ;
struct V_22 * V_23 = & V_18 -> V_3 -> V_8 -> V_23 ;
V_20 -> V_24 = V_23 -> V_25 -> V_24 ;
V_20 -> V_26 = V_23 -> V_25 -> V_26 ;
}
void
F_7 ( struct V_2 * V_3 )
{
int V_10 , V_27 ;
struct V_28 V_29 [ V_30 ] ;
if ( ! V_3 -> V_9 ) {
V_27 =
F_8 ( V_3 -> V_8 , V_29 ) ;
for ( V_10 = 0 ; V_10 < V_27 ; V_10 ++ )
F_9 ( V_3 -> V_8 -> V_5 , V_29 [ V_10 ] ) ;
}
}
void
F_10 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
V_3 -> V_32 = * V_32 ;
F_11 ( & V_3 -> V_18 ) ;
}
void
F_12 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
int V_33 , V_10 ;
F_13 ( & V_3 -> V_34 , F_1 , V_3 ) ;
V_33 = sizeof( V_14 ) / sizeof( V_14 [ 0 ] ) ;
for ( V_10 = 0 ; V_10 < V_33 ; V_10 ++ ) {
V_12 = & V_14 [ V_10 ] ;
if ( V_12 -> V_35 ) {
F_14 ( & V_3 -> V_34 ) ;
V_12 -> V_35 ( V_3 ) ;
}
}
F_15 ( & V_3 -> V_34 ) ;
}
static void
F_16 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_38 :
F_18 ( V_18 , V_39 ) ;
F_19 ( V_18 ) ;
F_20 ( & V_18 -> V_21 , & V_18 -> V_21 . V_20 ) ;
break;
case V_40 :
case V_41 :
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_39 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_42 :
if ( F_22 ( V_18 -> V_3 -> V_8 ) ) {
F_18 ( V_18 , V_43 ) ;
F_23 ( V_18 ) ;
} else
F_18 ( V_18 , V_44 ) ;
break;
case V_40 :
case V_41 :
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_44 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_40 :
F_18 ( V_18 , V_43 ) ;
F_23 ( V_18 ) ;
break;
case V_47 :
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_43 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_48 :
F_25 ( V_18 -> V_3 -> V_8 ,
V_18 -> V_49 ,
F_26 ( V_18 ) ) ;
V_18 -> V_50 = V_51 ;
if ( V_18 -> V_52 && V_18 -> V_53 ) {
F_18 ( V_18 , V_54 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
} else {
F_18 ( V_18 , V_55 ) ;
F_27 ( V_18 ) ;
}
break;
case V_47 :
F_18 ( V_18 , V_56 ) ;
F_28 ( V_18 -> V_3 -> V_8 , & V_18 -> V_57 ,
V_58 , V_18 ,
V_59 ) ;
break;
case V_60 :
F_18 ( V_18 , V_61 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
F_30 ( V_18 ) ;
break;
case V_64 :
V_18 -> V_50 = V_65 ;
F_25 ( V_18 -> V_3 -> V_8 ,
V_18 -> V_49 ,
F_26 ( V_18 ) ) ;
F_27 ( V_18 ) ;
F_18 ( V_18 , V_66 ) ;
break;
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_56 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_67 :
F_18 ( V_18 , V_43 ) ;
F_23 ( V_18 ) ;
break;
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_31 ( & V_18 -> V_57 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_31 ( & V_18 -> V_57 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_54 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_68 :
F_18 ( V_18 , V_69 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
break;
case V_70 :
F_18 ( V_18 , V_55 ) ;
F_27 ( V_18 ) ;
break;
case V_71 :
F_18 ( V_18 , V_72 ) ;
break;
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
void
V_69 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_32 ( V_18 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
void
V_61 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_32 ( V_18 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_66 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
F_32 ( V_18 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
case V_64 :
F_17 ( V_18 -> V_3 , V_18 -> V_49 ) ;
F_25 ( V_18 -> V_3 -> V_8 ,
V_18 -> V_49 ,
F_26 ( V_18 ) ) ;
break;
case V_47 :
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
void
V_55 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_41 :
F_18 ( V_18 , V_44 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
F_32 ( V_18 ) ;
break;
case V_45 :
F_18 ( V_18 , V_46 ) ;
F_24 ( V_18 ) ;
break;
case V_68 :
F_18 ( V_18 , V_69 ) ;
F_29 ( V_18 -> V_62 , V_63 ) ;
break;
case V_70 :
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_72 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_48 :
F_18 ( V_18 , V_73 ) ;
break;
case V_74 :
F_18 ( V_18 , V_75 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
V_73 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
}
static void
V_75 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
struct V_4 * V_5 = (struct V_4 * ) V_18 -> V_3 -> V_5 ;
char V_76 [ V_77 ] ;
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
F_33 ( V_76 , V_18 -> V_21 . V_20 . V_26 ) ;
F_34 ( V_78 , V_5 , V_79 ,
L_1
L_2 ,
V_76 , V_18 -> V_3 -> V_80 ,
V_18 -> V_81 . V_82 ) ;
}
static void
V_46 ( struct V_17 * V_18 ,
enum V_36 V_37 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_37 ) ;
switch ( V_37 ) {
case V_83 :
F_18 ( V_18 , F_16 ) ;
F_35 ( & V_18 -> V_3 -> V_34 ) ;
break;
case V_40 :
break;
case V_41 :
F_32 ( V_18 ) ;
break;
default:
F_21 ( V_18 -> V_3 , V_37 ) ;
}
}
static void
F_19 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 . V_20 ;
V_20 -> V_84 = V_85 ;
V_20 -> V_24 = V_18 -> V_3 -> V_8 -> V_23 . V_25 -> V_24 ;
V_20 -> V_26 = V_18 -> V_3 -> V_8 -> V_23 . V_25 -> V_26 ;
}
void
F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 . V_20 ;
char V_86 [ V_87 ] = { 0 } ;
struct V_31 * V_32 = & V_18 -> V_3 -> V_32 ;
F_36 ( & V_18 -> V_3 -> V_8 -> V_23 , V_86 ) ;
strncpy ( ( char * ) & V_20 -> V_88 , V_86 ,
V_89 ) ;
strncat ( ( char * ) & V_20 -> V_88 , V_90 ,
sizeof( V_90 ) ) ;
strncat ( ( char * ) & V_20 -> V_88 , ( char * ) V_32 -> V_91 ,
V_92 ) ;
strncat ( ( char * ) & V_20 -> V_88 , V_90 ,
sizeof( V_90 ) ) ;
strncat ( ( char * ) & V_20 -> V_88 ,
( char * ) V_32 -> V_93 ,
V_94 ) ;
strncat ( ( char * ) & V_20 -> V_88 , V_90 ,
sizeof( V_90 ) ) ;
if ( V_32 -> V_95 [ 0 ] == '\0' ) {
strncat ( ( char * ) & V_20 -> V_88 ,
( char * ) V_32 -> V_96 ,
V_97 ) ;
strncat ( ( char * ) & V_20 -> V_88 ,
V_90 ,
sizeof( V_90 ) ) ;
} else {
strncat ( ( char * ) & V_20 -> V_88 ,
( char * ) V_32 -> V_96 ,
V_98 ) ;
strncat ( ( char * ) & V_20 -> V_88 ,
V_90 ,
sizeof( V_90 ) ) ;
strncat ( ( char * ) & V_20 -> V_88 ,
( char * ) V_32 -> V_95 ,
V_99 ) ;
}
V_20 -> V_88 . V_100 [ V_101 - 1 ] = 0 ;
}
void
F_37 ( void * V_5 , void * V_102 , T_2 V_103 )
{
struct V_17 * V_18 = V_102 ;
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_17 ( V_18 -> V_3 , V_103 ) ;
switch ( V_103 ) {
case V_104 :
V_18 -> V_105 . V_106 ++ ;
break;
case V_107 :
V_18 -> V_105 . V_108 ++ ;
F_29 ( V_18 , V_47 ) ;
return;
case V_109 :
switch ( V_18 -> V_62 -> V_110 ) {
case V_111 :
V_18 -> V_105 . V_108 ++ ;
break;
case V_112 :
V_18 -> V_105 . V_113 ++ ;
break;
default:
break;
}
F_29 ( V_18 , V_47 ) ;
return;
case V_114 :
V_18 -> V_105 . V_115 ++ ;
if ( V_18 -> V_62 -> V_116 == V_117 &&
V_18 -> V_62 -> V_118 == V_119 )
V_18 -> V_3 -> V_120 = V_13 ;
F_29 ( V_18 , V_47 ) ;
return;
default:
V_18 -> V_105 . V_121 ++ ;
F_29 ( V_18 , V_47 ) ;
return;
}
V_18 -> V_49 = V_18 -> V_62 -> V_122 ;
F_17 ( V_18 -> V_3 , V_18 -> V_49 ) ;
if ( ! ( V_18 -> V_62 -> V_123 ) )
V_18 -> V_124 = V_18 -> V_62 -> V_125 ;
if ( V_18 -> V_62 -> V_126 ) {
V_18 -> V_21 . V_127 = V_18 -> V_62 -> V_128 ;
V_18 -> V_129 = V_18 -> V_62 -> V_130 ;
V_18 -> V_53 = V_18 -> V_62 -> V_131 ;
F_29 ( V_18 , V_48 ) ;
} else {
V_18 -> V_21 . V_132 . V_133 . V_134 =
V_18 -> V_62 -> V_135 ;
V_18 -> V_50 = V_65 ;
F_29 ( V_18 , V_64 ) ;
}
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_127 ) ;
F_17 ( V_18 -> V_3 , V_18 -> V_129 ) ;
F_17 ( V_18 -> V_3 , V_18 -> V_53 ) ;
}
static void
F_23 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = V_18 -> V_3 -> V_8 ;
struct V_19 * V_136 = & V_18 -> V_21 . V_20 ;
T_3 V_137 = 0 , V_138 = 0 ;
if ( F_38 ( V_8 ) == V_139 )
V_137 = F_39 ( V_8 ) ;
if ( F_40 ( V_18 ) &&
( ! V_18 -> V_3 -> V_120 ) )
V_138 = V_140 ;
F_41 ( V_18 -> V_62 , V_18 , V_137 , F_42 ( V_8 ) ,
V_136 -> V_26 , V_136 -> V_24 , V_18 -> V_52 , V_138 ) ;
V_18 -> V_105 . V_141 ++ ;
}
static void
F_27 ( struct V_17 * V_18 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 , * V_146 ;
F_17 ( V_18 -> V_3 , V_18 -> V_124 ) ;
F_30 ( V_18 ) ;
V_18 -> V_105 . V_147 ++ ;
F_43 ( & V_18 -> V_21 ) ;
F_44 (qe, qen, &fabric->vport_q) {
V_143 = (struct V_142 * ) V_145 ;
F_45 ( V_143 ) ;
}
}
static void
F_32 ( struct V_17 * V_18 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 , * V_146 ;
F_17 ( V_18 -> V_3 , V_18 -> V_124 ) ;
V_18 -> V_105 . V_148 ++ ;
F_44 (qe, qen, &fabric->vport_q) {
V_143 = (struct V_142 * ) V_145 ;
F_46 ( V_143 ) ;
}
F_47 ( & V_18 -> V_21 ) ;
V_18 -> V_124 = 0 ;
V_18 -> V_149 [ 0 ] = 0 ;
}
static void
V_58 ( void * V_150 )
{
struct V_17 * V_18 = V_150 ;
F_29 ( V_18 , V_67 ) ;
}
static T_3
F_26 ( struct V_17 * V_18 )
{
T_3 V_151 = V_18 -> V_62 -> V_151 ;
struct V_152 * V_153 = F_48 ( V_18 -> V_3 -> V_8 ) ;
if ( ! ( V_153 -> V_154 . V_155 && V_151 ) )
return 0 ;
return ( ( V_151 > V_140 ) ?
V_151 : V_140 ) ;
}
static T_1
F_40 ( struct V_17 * V_18 )
{
struct V_152 * V_153 = F_48 ( V_18 -> V_3 -> V_8 ) ;
if ( F_49 ( & V_18 -> V_3 -> V_8 -> V_23 ) &&
V_153 -> V_154 . V_155 &&
! F_50 ( V_18 -> V_3 -> V_8 ) &&
! F_51 ( V_18 -> V_3 -> V_8 ) )
return V_13 ;
else
return V_156 ;
}
static void
F_24 ( struct V_17 * V_18 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 , * V_146 ;
F_44 (qe, qen, &fabric->vport_q) {
V_143 = (struct V_142 * ) V_145 ;
F_52 ( V_143 ) ;
}
F_53 ( & V_18 -> V_21 ) ;
F_15 ( & V_18 -> V_34 ) ;
}
static void
F_54 ( void * V_150 )
{
struct V_17 * V_18 = V_150 ;
F_29 ( V_18 , V_83 ) ;
}
void
F_55 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
V_18 = & V_3 -> V_18 ;
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 -> V_3 = V_3 ;
F_56 ( & V_18 -> V_157 ) ;
F_56 ( & V_18 -> V_158 ) ;
V_18 -> V_62 = F_57 ( V_3 -> V_8 ) ;
F_58 ( ! V_18 -> V_62 ) ;
F_13 ( & V_18 -> V_34 , F_54 , V_18 ) ;
F_14 ( & V_18 -> V_34 ) ;
F_18 ( V_18 , F_16 ) ;
F_59 ( & V_18 -> V_21 , V_18 -> V_3 , V_159 , NULL ) ;
}
void
F_60 ( struct V_2 * V_3 )
{
F_29 ( & V_3 -> V_18 , V_38 ) ;
F_17 ( V_3 , 0 ) ;
}
void
F_61 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
F_17 ( V_3 , 0 ) ;
V_18 = & V_3 -> V_18 ;
F_62 ( V_18 -> V_62 ) ;
F_29 ( V_18 , V_45 ) ;
}
void
F_63 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
F_17 ( V_3 , 0 ) ;
V_18 = & V_3 -> V_18 ;
F_29 ( V_18 , V_42 ) ;
}
void
F_64 ( struct V_17 * V_18 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
F_29 ( V_18 , V_40 ) ;
}
void
F_65 ( struct V_17 * V_18 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_21 . V_20 . V_26 ) ;
V_18 -> V_3 -> V_120 = V_156 ;
F_29 ( V_18 , V_41 ) ;
}
void
F_66 ( struct V_17 * V_18 ,
struct V_142 * V_143 )
{
F_17 ( V_18 -> V_3 , V_18 -> V_160 ) ;
F_67 ( & V_143 -> V_145 , & V_18 -> V_157 ) ;
V_18 -> V_161 ++ ;
F_14 ( & V_18 -> V_34 ) ;
}
void
F_68 ( struct V_17 * V_18 ,
struct V_142 * V_143 )
{
F_69 ( & V_143 -> V_145 ) ;
V_18 -> V_161 -- ;
F_35 ( & V_18 -> V_34 ) ;
}
struct V_142 *
F_70 ( struct V_17 * V_18 , T_4 V_26 )
{
struct V_142 * V_143 ;
struct V_144 * V_145 ;
F_71 (qe, &fabric->vport_q) {
V_143 = (struct V_142 * ) V_145 ;
if ( F_72 ( & V_143 -> V_162 ) == V_26 )
return V_143 ;
}
return NULL ;
}
T_5
F_73 ( struct V_17 * V_18 )
{
T_4 V_163 ;
T_3 * V_164 ;
T_5 V_165 ;
V_163 = V_18 -> V_62 -> V_125 ;
V_164 = ( T_3 * ) & V_163 ;
V_165 = ( V_164 [ 3 ] << 8 ) | V_164 [ 4 ] ;
return V_165 ;
}
void
F_74 ( struct V_17 * V_18 , struct V_166 * V_167 ,
T_5 V_168 )
{
T_6 V_127 = V_167 -> V_169 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_170 * V_171 = (struct V_170 * ) ( V_167 + 1 ) ;
struct V_172 * V_173 = (struct V_172 * ) V_171 ;
F_17 ( V_18 -> V_3 , V_168 ) ;
F_17 ( V_18 -> V_3 , V_127 ) ;
if ( ( V_127 == F_75 ( V_174 ) ) &&
( V_171 -> V_175 == V_176 ) &&
( V_173 -> V_177 == F_72 ( & V_18 -> V_21 ) ) ) {
F_29 ( V_18 , V_60 ) ;
return;
}
if ( V_167 -> V_169 == F_76 ( V_174 ) ) {
F_17 ( V_18 -> V_3 , V_127 ) ;
F_77 ( V_18 , V_167 , V_168 ) ;
return;
}
if ( V_18 -> V_21 . V_127 == V_127 ) {
F_17 ( V_18 -> V_3 , V_171 -> V_175 ) ;
if ( V_171 -> V_175 == V_178 ) {
F_17 ( V_18 -> V_3 , V_171 -> V_175 ) ;
return;
}
F_17 ( V_18 -> V_3 , * ( T_3 * ) ( ( T_3 * ) V_167 ) ) ;
F_78 ( & V_18 -> V_21 , V_167 , V_168 ) ;
return;
}
F_71 (qe, &fabric->vport_q) {
V_143 = (struct V_142 * ) V_145 ;
if ( V_143 -> V_162 . V_127 == V_127 ) {
F_78 ( & V_143 -> V_162 , V_167 , V_168 ) ;
return;
}
}
F_17 ( V_18 -> V_3 , V_171 -> V_175 ) ;
F_78 ( & V_18 -> V_21 , V_167 , V_168 ) ;
}
static void
F_77 ( struct V_17 * V_18 , struct V_166 * V_167 ,
T_5 V_168 )
{
struct V_170 * V_171 = (struct V_170 * ) ( V_167 + 1 ) ;
F_17 ( V_18 -> V_3 , V_171 -> V_175 ) ;
switch ( V_171 -> V_175 ) {
case V_176 :
F_79 ( V_18 , V_167 , V_168 ) ;
break;
default:
break;
}
}
static void
F_79 ( struct V_17 * V_18 ,
struct V_166 * V_167 , T_5 V_168 )
{
struct V_172 * V_173 = (struct V_172 * ) ( V_167 + 1 ) ;
struct V_179 * V_21 = & V_18 -> V_21 ;
F_17 ( V_18 -> V_3 , V_167 -> V_180 ) ;
V_18 -> V_105 . V_181 ++ ;
if ( V_173 -> V_182 . V_183 ) {
F_17 ( V_18 -> V_3 , V_173 -> V_177 ) ;
V_18 -> V_105 . V_184 ++ ;
return;
}
V_18 -> V_49 = F_80 ( V_173 -> V_182 . V_185 ) ;
V_18 -> V_62 -> V_151 = ( F_80 ( V_173 -> V_182 . V_186 ) >> 12 ) ;
V_21 -> V_132 . V_133 . V_134 = V_173 -> V_177 ;
V_21 -> V_132 . V_133 . V_187 = V_167 -> V_188 ;
F_81 ( V_18 ) ;
F_29 ( V_18 , V_64 ) ;
}
static void
F_81 ( struct V_17 * V_18 )
{
struct V_19 * V_136 = & V_18 -> V_21 . V_20 ;
struct V_189 * V_190 = & V_18 -> V_21 . V_132 . V_133 ;
struct V_7 * V_8 = V_18 -> V_3 -> V_8 ;
struct V_191 * V_192 ;
T_5 V_193 ;
struct V_166 V_167 ;
V_192 = F_82 ( V_18 -> V_3 ) ;
if ( ! V_192 )
return;
V_193 = F_83 ( & V_167 , F_84 ( V_192 ) ,
F_76 ( V_174 ) ,
V_190 -> V_187 , V_136 -> V_26 ,
V_136 -> V_24 ,
F_42 ( V_8 ) ,
F_85 ( V_8 ) ,
F_26 ( V_18 ) ) ;
F_86 ( V_192 , NULL , V_18 -> V_160 , V_18 -> V_62 -> V_194 ,
V_156 , V_195 ,
V_193 , & V_167 , V_196 , V_18 ,
V_197 , 0 ) ;
}
static void
V_196 ( void * V_198 , struct V_191 * V_192 , void * V_150 ,
T_2 V_103 , T_6 V_199 ,
T_6 V_200 , struct V_166 * V_201 )
{
struct V_17 * V_18 = V_150 ;
F_17 ( V_18 -> V_3 , V_103 ) ;
}
static void
F_87 ( struct V_179 * V_202 ,
enum V_203 V_37 )
{
struct V_4 * V_5 = (struct V_4 * ) V_202 -> V_18 -> V_3 -> V_5 ;
struct V_204 * V_205 ;
F_88 ( V_5 , V_205 ) ;
if ( ! V_205 )
return;
V_205 -> V_206 . V_202 . V_26 = F_72 ( V_202 ) ;
V_205 -> V_206 . V_202 . V_207 = F_89 ( V_202 ) ;
F_90 ( V_205 , V_5 , ++ V_202 -> V_3 -> V_208 ,
V_209 , V_37 ) ;
}
void
F_91 ( struct V_17 * V_18 ,
T_4 V_124 )
{
struct V_4 * V_5 = (struct V_4 * ) V_18 -> V_3 -> V_5 ;
char V_76 [ V_77 ] ;
char V_210 [ V_77 ] ;
F_17 ( V_18 -> V_3 , V_124 ) ;
if ( V_18 -> V_124 == 0 ) {
V_18 -> V_124 = V_124 ;
} else {
V_18 -> V_124 = V_124 ;
F_33 ( V_76 , F_72 ( & V_18 -> V_21 ) ) ;
F_33 ( V_210 ,
F_89 ( & V_18 -> V_21 ) ) ;
F_34 ( V_211 , V_5 , V_79 ,
L_3 ,
V_76 , V_210 ) ;
F_87 ( & V_18 -> V_21 ,
V_212 ) ;
}
}
T_7 *
F_92 ( struct V_2 * V_3 , T_5 V_160 )
{
F_17 ( V_3 , V_160 ) ;
if ( V_160 == V_159 )
return & V_3 -> V_18 ;
return NULL ;
}
void
F_93 ( T_7 * V_213 , T_4 V_214 [] , int * V_215 )
{
struct V_144 * V_145 ;
struct V_142 * V_143 ;
int V_10 = 0 ;
struct V_2 * V_3 ;
if ( V_213 == NULL || V_214 == NULL || * V_215 == 0 )
return;
V_3 = V_213 -> V_3 ;
F_17 ( V_3 , V_213 -> V_160 ) ;
F_17 ( V_3 , ( V_216 ) * V_215 ) ;
V_214 [ V_10 ++ ] = V_213 -> V_21 . V_20 . V_26 ;
F_71 (qe, &vf->vport_q) {
if ( V_10 >= * V_215 )
break;
V_143 = (struct V_142 * ) V_145 ;
V_214 [ V_10 ++ ] = V_143 -> V_162 . V_20 . V_26 ;
}
F_17 ( V_3 , V_10 ) ;
* V_215 = V_10 ;
}
static void
F_94 ( void * V_150 , enum V_217 V_37 )
{
struct V_2 * V_3 = V_150 ;
F_17 ( V_3 , V_37 ) ;
switch ( V_37 ) {
case V_218 :
F_64 ( & V_3 -> V_18 ) ;
break;
case V_219 :
F_65 ( & V_3 -> V_18 ) ;
break;
default:
F_58 ( 1 ) ;
}
}
void
F_95 ( struct V_2 * V_3 )
{
F_96 ( V_3 -> V_8 , F_94 , V_3 ) ;
}
static void
F_97 ( void * V_150 , struct V_220 * V_221 )
{
struct V_2 * V_3 = (struct V_2 * ) V_150 ;
struct V_166 * V_167 = F_98 ( V_221 ) ;
T_5 V_168 = F_99 ( V_221 ) ;
struct V_222 * V_223 ;
struct V_17 * V_18 ;
if ( V_167 -> V_224 == V_225 &&
V_167 -> V_226 == V_227 ) {
F_100 ( V_3 , V_221 . V_228 ) ;
V_223 = F_98 ( V_221 ) ;
if ( V_3 -> V_80 == V_223 -> V_160 )
V_18 = & V_3 -> V_18 ;
else
V_18 = F_92 ( V_3 , ( T_5 ) V_223 -> V_160 ) ;
if ( ! V_18 ) {
F_58 ( 1 ) ;
F_100 ( V_3 , V_221 . V_229 ) ;
F_101 ( V_221 ) ;
return;
}
V_167 = (struct V_166 * ) ( V_223 + 1 ) ;
V_168 -= sizeof( struct V_222 ) ;
F_17 ( V_3 , V_223 -> V_160 ) ;
} else {
F_100 ( V_3 , V_221 . V_230 ) ;
V_18 = & V_3 -> V_18 ;
}
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 0 ] ) ;
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 1 ] ) ;
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 2 ] ) ;
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 3 ] ) ;
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 4 ] ) ;
F_17 ( V_3 , ( ( T_6 * ) V_167 ) [ 5 ] ) ;
F_17 ( V_3 , V_168 ) ;
F_74 ( V_18 , V_167 , V_168 ) ;
F_101 ( V_221 ) ;
}
void
F_102 ( struct V_2 * V_3 )
{
F_103 ( V_3 -> V_8 , F_97 , V_3 ) ;
}
