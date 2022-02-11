static void
F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_2 ( & V_5 -> V_6 ) ;
}
void
F_3 ( struct V_2 * V_3 )
{
F_4 ( & V_3 -> V_7 , V_8 ) ;
F_5 ( V_3 , 0 ) ;
}
void
F_6 ( struct V_2 * V_3 )
{
struct V_9 * V_7 = & V_3 -> V_7 ;
struct V_10 * V_11 = & V_7 -> V_12 . V_11 ;
struct V_13 * V_14 = & V_7 -> V_3 -> V_15 -> V_14 ;
V_11 -> V_16 = V_14 -> V_17 -> V_16 ;
V_11 -> V_18 = V_14 -> V_17 -> V_18 ;
}
void
F_7 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_19 , F_1 , V_3 ) ;
F_9 ( & V_3 -> V_19 ) ;
F_10 ( V_3 ) ;
F_11 ( & V_3 -> V_19 ) ;
}
void
F_12 ( struct V_2 * V_3 )
{
int V_20 , V_21 ;
struct V_22 V_23 [ V_24 ] ;
if ( ! V_3 -> V_25 ) {
V_21 =
F_13 ( V_3 -> V_15 , V_23 ) ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
F_14 ( V_3 -> V_15 -> V_5 , V_23 [ V_20 ] ) ;
}
}
void
F_15 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
V_3 -> V_27 = * V_27 ;
F_16 ( & V_3 -> V_7 ) ;
F_17 ( & V_3 -> V_7 ) ;
}
void
F_18 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_19 , F_1 , V_3 ) ;
F_9 ( & V_3 -> V_19 ) ;
F_5 ( V_3 , 0 ) ;
F_19 ( V_3 -> V_7 . V_28 ) ;
F_4 ( & V_3 -> V_7 , V_29 ) ;
F_11 ( & V_3 -> V_19 ) ;
}
static void
F_20 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_8 :
F_21 ( V_7 , V_32 ) ;
F_22 ( V_7 ) ;
F_23 ( & V_7 -> V_12 , & V_7 -> V_12 . V_11 ) ;
break;
case V_33 :
case V_34 :
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_32 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_36 :
if ( ! F_25 ( V_7 -> V_3 -> V_15 ) ) {
F_21 ( V_7 , V_37 ) ;
break;
}
if ( F_26 ( V_15 ) ==
V_38 ) {
V_7 -> V_39 = V_40 ;
V_7 -> V_12 . V_41 = F_27 ( V_15 ) ;
V_7 -> V_12 . V_41 = F_28 ( V_7 -> V_12 . V_41 ) ;
F_21 ( V_7 ,
V_42 ) ;
F_29 ( V_7 ) ;
F_30 ( & V_7 -> V_12 ) ;
} else {
F_21 ( V_7 , V_43 ) ;
F_31 ( V_7 ) ;
}
break;
case V_33 :
case V_34 :
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_37 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_33 :
if ( F_26 ( V_15 ) != V_38 ) {
F_21 ( V_7 , V_43 ) ;
F_31 ( V_7 ) ;
break;
}
V_7 -> V_39 = V_40 ;
V_7 -> V_12 . V_41 = F_27 ( V_15 ) ;
V_7 -> V_12 . V_41 = F_28 ( V_7 -> V_12 . V_41 ) ;
F_21 ( V_7 , V_42 ) ;
F_29 ( V_7 ) ;
F_30 ( & V_7 -> V_12 ) ;
break;
case V_45 :
case V_46 :
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
case V_47 :
F_21 ( V_7 , V_48 ) ;
F_33 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_43 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_49 :
F_34 ( V_7 -> V_3 -> V_15 ,
V_7 -> V_50 ) ;
V_7 -> V_39 = V_51 ;
if ( V_7 -> V_52 && V_7 -> V_53 ) {
F_21 ( V_7 , V_54 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
} else {
F_21 ( V_7 , V_42 ) ;
F_35 ( V_7 ) ;
}
break;
case V_45 :
F_21 ( V_7 , V_55 ) ;
F_36 ( V_7 -> V_3 -> V_15 , & V_7 -> V_56 ,
V_57 , V_7 ,
V_58 ) ;
break;
case V_46 :
F_21 ( V_7 , V_59 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
F_29 ( V_7 ) ;
break;
case V_61 :
V_7 -> V_39 = V_62 ;
F_34 ( V_7 -> V_3 -> V_15 ,
V_7 -> V_50 ) ;
F_35 ( V_7 ) ;
F_21 ( V_7 , V_63 ) ;
break;
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_55 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_64 :
F_21 ( V_7 , V_43 ) ;
F_31 ( V_7 ) ;
break;
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_37 ( & V_7 -> V_56 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_37 ( & V_7 -> V_56 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_54 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_65 :
F_21 ( V_7 , V_66 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
break;
case V_67 :
F_21 ( V_7 , V_42 ) ;
F_35 ( V_7 ) ;
break;
case V_68 :
F_21 ( V_7 , V_69 ) ;
break;
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
void
V_66 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_38 ( V_7 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
void
V_59 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_38 ( V_7 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_63 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_34 :
F_21 ( V_7 , V_37 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
F_38 ( V_7 ) ;
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
case V_61 :
F_5 ( V_7 -> V_3 , V_7 -> V_50 ) ;
F_34 ( V_7 -> V_3 -> V_15 ,
V_7 -> V_50 ) ;
break;
case V_45 :
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
void
V_42 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_34 :
F_21 ( V_7 , V_37 ) ;
if ( F_26 ( V_15 ) == V_38 ) {
F_39 ( & V_7 -> V_12 ) ;
} else {
F_4 ( V_7 -> V_28 , V_60 ) ;
F_38 ( V_7 ) ;
}
break;
case V_29 :
F_21 ( V_7 , V_44 ) ;
F_32 ( V_7 ) ;
break;
case V_47 :
F_21 ( V_7 , V_70 ) ;
F_33 ( V_7 ) ;
break;
case V_65 :
F_21 ( V_7 , V_66 ) ;
F_4 ( V_7 -> V_28 , V_60 ) ;
break;
case V_67 :
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_69 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_49 :
F_21 ( V_7 , V_71 ) ;
break;
case V_72 :
F_21 ( V_7 , V_73 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_71 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
}
static void
V_73 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
struct V_4 * V_5 = (struct V_4 * ) V_7 -> V_3 -> V_5 ;
char V_74 [ V_75 ] ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
F_40 ( V_74 , V_7 -> V_12 . V_11 . V_18 ) ;
F_41 ( V_76 , V_5 , V_77 ,
L_1
L_2 ,
V_74 , V_7 -> V_3 -> V_78 ,
V_7 -> V_79 . V_80 ) ;
}
static void
V_44 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_81 :
F_21 ( V_7 , F_20 ) ;
F_42 ( & V_7 -> V_3 -> V_19 ) ;
break;
case V_33 :
break;
case V_34 :
F_38 ( V_7 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_70 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_82 :
if ( F_26 ( V_15 ) == V_38 ) {
F_21 ( V_7 , V_32 ) ;
} else {
F_21 ( V_7 , V_48 ) ;
F_4 ( V_7 -> V_28 , V_83 ) ;
}
break;
case V_33 :
break;
case V_34 :
if ( F_26 ( V_15 ) == V_38 )
F_21 ( V_7 , V_32 ) ;
else
F_21 ( V_7 , V_48 ) ;
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
V_48 ( struct V_9 * V_7 ,
enum V_30 V_31 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_31 ) ;
switch ( V_31 ) {
case V_82 :
case V_84 :
F_21 ( V_7 , V_32 ) ;
F_42 ( & ( V_7 -> V_3 ) -> V_19 ) ;
break;
case V_34 :
break;
default:
F_24 ( V_7 -> V_3 , V_31 ) ;
}
}
static void
F_22 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_11 ;
V_11 -> V_85 = V_86 ;
V_11 -> V_16 = V_7 -> V_3 -> V_15 -> V_14 . V_17 -> V_16 ;
V_11 -> V_18 = V_7 -> V_3 -> V_15 -> V_14 . V_17 -> V_18 ;
}
void
F_16 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_11 ;
char V_87 [ V_88 ] = { 0 } ;
struct V_26 * V_27 = & V_7 -> V_3 -> V_27 ;
F_43 ( & V_7 -> V_3 -> V_15 -> V_14 , V_87 ) ;
strncpy ( ( char * ) & V_11 -> V_89 , V_87 ,
V_90 ) ;
strncat ( ( char * ) & V_11 -> V_89 , V_91 ,
sizeof( V_91 ) ) ;
strncat ( ( char * ) & V_11 -> V_89 , ( char * ) V_27 -> V_92 ,
V_93 ) ;
strncat ( ( char * ) & V_11 -> V_89 , V_91 ,
sizeof( V_91 ) ) ;
strncat ( ( char * ) & V_11 -> V_89 ,
( char * ) V_27 -> V_94 ,
V_95 ) ;
strncat ( ( char * ) & V_11 -> V_89 , V_91 ,
sizeof( V_91 ) ) ;
if ( V_27 -> V_96 [ 0 ] == '\0' ) {
strncat ( ( char * ) & V_11 -> V_89 ,
( char * ) V_27 -> V_97 ,
V_98 ) ;
strncat ( ( char * ) & V_11 -> V_89 ,
V_91 ,
sizeof( V_91 ) ) ;
} else {
strncat ( ( char * ) & V_11 -> V_89 ,
( char * ) V_27 -> V_97 ,
V_99 ) ;
strncat ( ( char * ) & V_11 -> V_89 ,
V_91 ,
sizeof( V_91 ) ) ;
strncat ( ( char * ) & V_11 -> V_89 ,
( char * ) V_27 -> V_96 ,
V_100 ) ;
}
V_11 -> V_89 . V_101 [ V_102 - 1 ] = 0 ;
}
void
F_17 ( struct V_9 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_11 ;
char V_87 [ V_88 ] = { 0 } ;
struct V_26 * V_27 = & V_7 -> V_3 -> V_27 ;
F_43 ( & V_7 -> V_3 -> V_15 -> V_14 , V_87 ) ;
strncpy ( ( char * ) & V_11 -> V_103 , V_87 ,
V_90 ) ;
strncat ( ( char * ) & V_11 -> V_103 ,
V_91 ,
sizeof( V_91 ) ) ;
strncat ( ( char * ) & V_11 -> V_103 , ( char * ) V_27 -> V_92 ,
V_93 ) ;
strncat ( ( char * ) & V_11 -> V_103 ,
V_91 ,
sizeof( V_91 ) ) ;
strncat ( ( char * ) & V_11 -> V_103 ,
( char * ) V_27 -> V_94 ,
V_95 ) ;
strncat ( ( char * ) & V_11 -> V_103 ,
V_91 ,
sizeof( V_91 ) ) ;
V_11 -> V_103 . V_101 [ V_102 - 1 ] = 0 ;
}
void
F_44 ( void * V_5 , void * V_104 , T_1 V_105 )
{
struct V_9 * V_7 = V_104 ;
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_5 ( V_7 -> V_3 , V_105 ) ;
switch ( V_105 ) {
case V_106 :
V_7 -> V_107 . V_108 ++ ;
break;
case V_109 :
V_7 -> V_107 . V_110 ++ ;
F_4 ( V_7 , V_45 ) ;
return;
case V_111 :
switch ( V_7 -> V_28 -> V_112 ) {
case V_113 :
V_7 -> V_107 . V_110 ++ ;
break;
case V_114 :
V_7 -> V_107 . V_115 ++ ;
break;
default:
break;
}
F_4 ( V_7 , V_45 ) ;
return;
case V_116 :
V_7 -> V_107 . V_117 ++ ;
F_4 ( V_7 , V_45 ) ;
return;
default:
V_7 -> V_107 . V_118 ++ ;
F_4 ( V_7 , V_45 ) ;
return;
}
V_7 -> V_50 = V_7 -> V_28 -> V_119 ;
F_5 ( V_7 -> V_3 , V_7 -> V_50 ) ;
if ( ! ( V_7 -> V_28 -> V_120 ) )
V_7 -> V_121 = V_7 -> V_28 -> V_122 ;
if ( V_7 -> V_28 -> V_123 ) {
V_7 -> V_12 . V_41 = V_7 -> V_28 -> V_124 ;
V_7 -> V_125 = V_7 -> V_28 -> V_126 ;
V_7 -> V_53 = V_7 -> V_28 -> V_127 ;
F_4 ( V_7 , V_49 ) ;
} else {
V_7 -> V_12 . V_128 . V_129 . V_130 =
V_7 -> V_28 -> V_131 ;
V_7 -> V_39 = V_62 ;
F_4 ( V_7 , V_61 ) ;
}
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_41 ) ;
F_5 ( V_7 -> V_3 , V_7 -> V_125 ) ;
F_5 ( V_7 -> V_3 , V_7 -> V_53 ) ;
}
static void
F_31 ( struct V_9 * V_7 )
{
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
struct V_10 * V_132 = & V_7 -> V_12 . V_11 ;
T_2 V_133 = 0 ;
F_45 ( V_7 -> V_28 , V_7 , V_133 , F_46 ( V_15 ) ,
V_132 -> V_18 , V_132 -> V_16 , V_7 -> V_52 ) ;
V_7 -> V_107 . V_134 ++ ;
}
static void
F_35 ( struct V_9 * V_7 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 , * V_139 ;
F_5 ( V_7 -> V_3 , V_7 -> V_121 ) ;
F_29 ( V_7 ) ;
V_7 -> V_107 . V_140 ++ ;
F_30 ( & V_7 -> V_12 ) ;
F_47 (qe, qen, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
F_48 ( V_136 ) ;
}
}
static void
F_38 ( struct V_9 * V_7 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 , * V_139 ;
F_5 ( V_7 -> V_3 , V_7 -> V_121 ) ;
V_7 -> V_107 . V_141 ++ ;
F_47 (qe, qen, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
F_49 ( V_136 ) ;
}
F_39 ( & V_7 -> V_12 ) ;
V_7 -> V_121 = 0 ;
V_7 -> V_142 [ 0 ] = 0 ;
}
static void
V_57 ( void * V_143 )
{
struct V_9 * V_7 = V_143 ;
F_4 ( V_7 , V_64 ) ;
}
static void
F_33 ( struct V_9 * V_7 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 , * V_139 ;
F_8 ( & V_7 -> V_144 , V_145 , V_7 ) ;
F_47 (qe, qen, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
F_9 ( & V_7 -> V_144 ) ;
F_50 ( V_136 ) ;
}
F_9 ( & V_7 -> V_144 ) ;
F_51 ( & V_7 -> V_12 ) ;
F_11 ( & V_7 -> V_144 ) ;
}
static void
F_32 ( struct V_9 * V_7 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 , * V_139 ;
F_47 (qe, qen, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
F_52 ( V_136 ) ;
}
F_53 ( & V_7 -> V_12 ) ;
F_11 ( & V_7 -> V_19 ) ;
}
static void
F_54 ( void * V_143 )
{
struct V_9 * V_7 = V_143 ;
F_4 ( V_7 , V_81 ) ;
}
static void
V_145 ( void * V_143 )
{
struct V_9 * V_7 = V_143 ;
F_4 ( V_7 , V_82 ) ;
}
void
F_10 ( struct V_2 * V_3 )
{
struct V_9 * V_7 ;
F_5 ( V_3 , 0 ) ;
V_7 = & V_3 -> V_7 ;
F_4 ( V_7 , V_47 ) ;
}
void
F_55 ( struct V_2 * V_3 )
{
struct V_9 * V_7 ;
F_5 ( V_3 , 0 ) ;
V_7 = & V_3 -> V_7 ;
F_4 ( V_7 , V_36 ) ;
}
void
F_56 ( struct V_9 * V_7 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_4 ( V_7 , V_33 ) ;
}
void
F_57 ( struct V_9 * V_7 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_12 . V_11 . V_18 ) ;
F_4 ( V_7 , V_34 ) ;
}
void
F_58 ( struct V_9 * V_7 ,
struct V_135 * V_136 )
{
F_5 ( V_7 -> V_3 , V_7 -> V_146 ) ;
F_59 ( & V_136 -> V_138 , & V_7 -> V_147 ) ;
V_7 -> V_148 ++ ;
F_9 ( & V_7 -> V_19 ) ;
}
void
F_60 ( struct V_9 * V_7 ,
struct V_135 * V_136 )
{
F_61 ( & V_136 -> V_138 ) ;
V_7 -> V_148 -- ;
F_42 ( & V_7 -> V_19 ) ;
}
struct V_135 *
F_62 ( struct V_9 * V_7 , T_3 V_18 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 ;
F_63 (qe, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
if ( F_64 ( & V_136 -> V_149 ) == V_18 )
return V_136 ;
}
return NULL ;
}
T_4
F_65 ( struct V_9 * V_7 )
{
T_3 V_150 ;
T_2 * V_151 ;
T_4 V_152 ;
V_150 = V_7 -> V_28 -> V_122 ;
V_151 = ( T_2 * ) & V_150 ;
V_152 = ( V_151 [ 3 ] << 8 ) | V_151 [ 4 ] ;
return V_152 ;
}
void
F_66 ( struct V_9 * V_7 , struct V_153 * V_154 ,
T_4 V_155 )
{
T_5 V_41 = V_154 -> V_156 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_157 * V_158 = (struct V_157 * ) ( V_154 + 1 ) ;
struct V_159 * V_160 = (struct V_159 * ) V_158 ;
F_5 ( V_7 -> V_3 , V_155 ) ;
F_5 ( V_7 -> V_3 , V_41 ) ;
if ( ( V_41 == F_67 ( V_161 ) ) &&
( V_158 -> V_162 == V_163 ) &&
( V_160 -> V_164 == F_64 ( & V_7 -> V_12 ) ) ) {
F_4 ( V_7 , V_46 ) ;
return;
}
if ( V_154 -> V_156 == F_28 ( V_161 ) ) {
F_5 ( V_7 -> V_3 , V_41 ) ;
F_68 ( V_7 , V_154 , V_155 ) ;
return;
}
if ( V_7 -> V_12 . V_41 == V_41 ) {
F_5 ( V_7 -> V_3 , V_158 -> V_162 ) ;
if ( V_158 -> V_162 == V_165 ) {
F_5 ( V_7 -> V_3 , V_158 -> V_162 ) ;
return;
}
F_5 ( V_7 -> V_3 , * ( T_2 * ) ( ( T_2 * ) V_154 ) ) ;
F_69 ( & V_7 -> V_12 , V_154 , V_155 ) ;
return;
}
F_63 (qe, &fabric->vport_q) {
V_136 = (struct V_135 * ) V_138 ;
if ( V_136 -> V_149 . V_41 == V_41 ) {
F_69 ( & V_136 -> V_149 , V_154 , V_155 ) ;
return;
}
}
if ( ! F_70 ( V_7 ) )
F_69 ( & V_7 -> V_12 , V_154 , V_155 ) ;
F_5 ( V_7 -> V_3 , V_154 -> type ) ;
}
static void
F_68 ( struct V_9 * V_7 , struct V_153 * V_154 ,
T_4 V_155 )
{
struct V_157 * V_158 = (struct V_157 * ) ( V_154 + 1 ) ;
F_5 ( V_7 -> V_3 , V_158 -> V_162 ) ;
switch ( V_158 -> V_162 ) {
case V_163 :
F_71 ( V_7 , V_154 , V_155 ) ;
break;
default:
break;
}
}
static void
F_71 ( struct V_9 * V_7 ,
struct V_153 * V_154 , T_4 V_155 )
{
struct V_159 * V_160 = (struct V_159 * ) ( V_154 + 1 ) ;
struct V_166 * V_12 = & V_7 -> V_12 ;
F_5 ( V_7 -> V_3 , V_154 -> V_167 ) ;
V_7 -> V_107 . V_168 ++ ;
if ( V_160 -> V_169 . V_170 ) {
F_5 ( V_7 -> V_3 , V_160 -> V_164 ) ;
V_7 -> V_107 . V_171 ++ ;
return;
}
V_7 -> V_50 = F_72 ( V_160 -> V_169 . V_172 ) ;
V_12 -> V_128 . V_129 . V_130 = V_160 -> V_164 ;
V_12 -> V_128 . V_129 . V_173 = V_154 -> V_174 ;
F_73 ( V_7 ) ;
F_4 ( V_7 , V_61 ) ;
}
static void
F_73 ( struct V_9 * V_7 )
{
struct V_10 * V_132 = & V_7 -> V_12 . V_11 ;
struct V_175 * V_176 = & V_7 -> V_12 . V_128 . V_129 ;
struct V_35 * V_15 = V_7 -> V_3 -> V_15 ;
struct V_177 * V_178 ;
T_4 V_179 ;
struct V_153 V_154 ;
V_178 = F_74 ( V_7 -> V_3 , V_180 ) ;
if ( ! V_178 )
return;
V_179 = F_75 ( & V_154 , F_76 ( V_178 ) ,
F_28 ( V_161 ) ,
V_176 -> V_173 , V_132 -> V_18 ,
V_132 -> V_16 ,
F_46 ( V_15 ) ,
F_77 ( V_15 ) , 0 ) ;
F_78 ( V_178 , NULL , V_7 -> V_146 , V_7 -> V_28 -> V_181 ,
V_180 , V_182 ,
V_179 , & V_154 , V_183 , V_7 ,
V_184 , 0 ) ;
}
static void
V_183 ( void * V_185 , struct V_177 * V_178 , void * V_143 ,
T_1 V_105 , T_5 V_186 ,
T_5 V_187 , struct V_153 * V_188 )
{
struct V_9 * V_7 = V_143 ;
F_5 ( V_7 -> V_3 , V_105 ) ;
}
static void
F_79 ( struct V_166 * V_189 ,
enum V_190 V_31 )
{
struct V_4 * V_5 = (struct V_4 * ) V_189 -> V_7 -> V_3 -> V_5 ;
struct V_191 * V_192 ;
F_80 ( V_5 , V_192 ) ;
if ( ! V_192 )
return;
V_192 -> V_193 . V_189 . V_18 = F_64 ( V_189 ) ;
V_192 -> V_193 . V_189 . V_194 = F_81 ( V_189 ) ;
F_82 ( V_192 , V_5 , ++ V_189 -> V_3 -> V_195 ,
V_196 , V_31 ) ;
}
void
F_83 ( struct V_9 * V_7 ,
T_3 V_121 )
{
struct V_4 * V_5 = (struct V_4 * ) V_7 -> V_3 -> V_5 ;
char V_74 [ V_75 ] ;
char V_197 [ V_75 ] ;
F_5 ( V_7 -> V_3 , V_121 ) ;
if ( V_7 -> V_121 == 0 ) {
V_7 -> V_121 = V_121 ;
} else {
V_7 -> V_121 = V_121 ;
F_40 ( V_74 , F_64 ( & V_7 -> V_12 ) ) ;
F_40 ( V_197 ,
F_81 ( & V_7 -> V_12 ) ) ;
F_41 ( V_198 , V_5 , V_77 ,
L_3 ,
V_74 , V_197 ) ;
F_79 ( & V_7 -> V_12 ,
V_199 ) ;
}
}
void
F_84 ( void * V_5 , void * V_104 )
{
struct V_9 * V_7 = V_104 ;
F_4 ( V_7 , V_84 ) ;
}
T_6 *
F_85 ( struct V_2 * V_3 , T_4 V_146 )
{
F_5 ( V_3 , V_146 ) ;
if ( V_146 == V_200 )
return & V_3 -> V_7 ;
return NULL ;
}
void
F_86 ( T_6 * V_201 , T_3 V_202 [] , int * V_203 )
{
struct V_137 * V_138 ;
struct V_135 * V_136 ;
int V_20 = 0 ;
struct V_2 * V_3 ;
if ( V_201 == NULL || V_202 == NULL || * V_203 == 0 )
return;
V_3 = V_201 -> V_3 ;
F_5 ( V_3 , V_201 -> V_146 ) ;
F_5 ( V_3 , ( V_204 ) * V_203 ) ;
V_202 [ V_20 ++ ] = V_201 -> V_12 . V_11 . V_18 ;
F_63 (qe, &vf->vport_q) {
if ( V_20 >= * V_203 )
break;
V_136 = (struct V_135 * ) V_138 ;
V_202 [ V_20 ++ ] = V_136 -> V_149 . V_11 . V_18 ;
}
F_5 ( V_3 , V_20 ) ;
* V_203 = V_20 ;
}
static void
F_87 ( void * V_143 , enum V_205 V_31 )
{
struct V_2 * V_3 = V_143 ;
F_5 ( V_3 , V_31 ) ;
switch ( V_31 ) {
case V_206 :
F_56 ( & V_3 -> V_7 ) ;
break;
case V_207 :
F_57 ( & V_3 -> V_7 ) ;
break;
default:
F_88 ( 1 ) ;
}
}
static void
F_89 ( void * V_143 , struct V_208 * V_209 )
{
struct V_2 * V_3 = (struct V_2 * ) V_143 ;
struct V_153 * V_154 = F_90 ( V_209 ) ;
T_4 V_155 = F_91 ( V_209 ) ;
struct V_210 * V_211 ;
struct V_9 * V_7 ;
if ( V_154 -> V_212 == V_213 &&
V_154 -> V_214 == V_215 ) {
F_92 ( V_3 , V_209 . V_216 ) ;
V_211 = F_90 ( V_209 ) ;
if ( V_3 -> V_78 == V_211 -> V_146 )
V_7 = & V_3 -> V_7 ;
else
V_7 = F_85 ( V_3 , ( T_4 ) V_211 -> V_146 ) ;
if ( ! V_7 ) {
F_88 ( 1 ) ;
F_92 ( V_3 , V_209 . V_217 ) ;
F_93 ( V_209 ) ;
return;
}
V_154 = (struct V_153 * ) ( V_211 + 1 ) ;
V_155 -= sizeof( struct V_210 ) ;
F_5 ( V_3 , V_211 -> V_146 ) ;
} else {
F_92 ( V_3 , V_209 . V_218 ) ;
V_7 = & V_3 -> V_7 ;
}
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 0 ] ) ;
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 1 ] ) ;
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 2 ] ) ;
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 3 ] ) ;
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 4 ] ) ;
F_5 ( V_3 , ( ( T_5 * ) V_154 ) [ 5 ] ) ;
F_5 ( V_3 , V_155 ) ;
F_66 ( V_7 , V_154 , V_155 ) ;
F_93 ( V_209 ) ;
}
void
F_94 ( struct V_2 * V_3 , struct V_35 * V_15 , struct V_4 * V_5 ,
T_7 V_25 )
{
struct V_9 * V_7 = & V_3 -> V_7 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_25 = V_25 ;
V_3 -> V_219 = 0 ;
V_15 -> V_3 = V_220 ;
F_95 () ;
F_96 ( V_3 -> V_15 , F_87 , V_3 ) ;
F_97 ( V_3 -> V_15 , F_89 , V_3 ) ;
memset ( V_7 , 0 , sizeof( struct V_9 ) ) ;
V_7 -> V_3 = V_3 ;
F_98 ( & V_7 -> V_147 ) ;
F_98 ( & V_7 -> V_221 ) ;
V_7 -> V_28 = F_99 ( V_3 -> V_15 ) ;
F_88 ( ! V_7 -> V_28 ) ;
F_8 ( & V_7 -> V_19 , F_54 , V_7 ) ;
F_9 ( & V_7 -> V_19 ) ;
F_21 ( V_7 , F_20 ) ;
F_100 ( & V_7 -> V_12 , V_7 -> V_3 , V_200 , NULL ) ;
}
