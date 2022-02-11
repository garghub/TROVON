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
V_3 -> V_13 = 0 ;
V_8 -> V_3 = V_14 ;
F_4 () ;
for ( V_10 = 0 ; V_10 < sizeof( V_15 ) / sizeof( V_15 [ 0 ] ) ; V_10 ++ ) {
V_12 = & V_15 [ V_10 ] ;
if ( V_12 -> V_16 )
V_12 -> V_16 ( V_3 ) ;
}
}
void
F_5 ( struct V_2 * V_3 )
{
int V_10 ;
struct V_11 * V_12 ;
for ( V_10 = 0 ; V_10 < sizeof( V_15 ) / sizeof( V_15 [ 0 ] ) ; V_10 ++ ) {
V_12 = & V_15 [ V_10 ] ;
if ( V_12 -> V_17 )
V_12 -> V_17 ( V_3 ) ;
}
}
void
F_6 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = & V_3 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_22 . V_21 ;
struct V_23 * V_24 = & V_19 -> V_3 -> V_8 -> V_24 ;
V_21 -> V_25 = V_24 -> V_26 -> V_25 ;
V_21 -> V_27 = V_24 -> V_26 -> V_27 ;
}
void
F_7 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_28 , F_1 , V_3 ) ;
F_9 ( & V_3 -> V_28 ) ;
F_10 ( V_3 ) ;
F_11 ( & V_3 -> V_28 ) ;
}
void
F_12 ( struct V_2 * V_3 )
{
int V_10 , V_29 ;
struct V_30 V_31 [ V_32 ] ;
if ( ! V_3 -> V_9 ) {
V_29 =
F_13 ( V_3 -> V_8 , V_31 ) ;
for ( V_10 = 0 ; V_10 < V_29 ; V_10 ++ )
F_14 ( V_3 -> V_8 -> V_5 , V_31 [ V_10 ] ) ;
}
}
void
F_15 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
V_3 -> V_34 = * V_34 ;
F_16 ( & V_3 -> V_19 ) ;
F_17 ( & V_3 -> V_19 ) ;
}
void
F_18 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
int V_35 , V_10 ;
F_8 ( & V_3 -> V_28 , F_1 , V_3 ) ;
V_35 = sizeof( V_15 ) / sizeof( V_15 [ 0 ] ) ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ ) {
V_12 = & V_15 [ V_10 ] ;
if ( V_12 -> V_36 ) {
F_9 ( & V_3 -> V_28 ) ;
V_12 -> V_36 ( V_3 ) ;
}
}
F_11 ( & V_3 -> V_28 ) ;
}
static void
F_19 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_39 :
F_21 ( V_19 , V_40 ) ;
F_22 ( V_19 ) ;
F_23 ( & V_19 -> V_22 , & V_19 -> V_22 . V_21 ) ;
break;
case V_41 :
case V_42 :
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_40 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_43 :
if ( ! F_25 ( V_19 -> V_3 -> V_8 ) ) {
F_21 ( V_19 , V_44 ) ;
break;
}
if ( F_26 ( V_8 ) ==
V_45 ) {
V_19 -> V_46 = V_47 ;
V_19 -> V_22 . V_48 = F_27 ( V_8 ) ;
V_19 -> V_22 . V_48 = F_28 ( V_19 -> V_22 . V_48 ) ;
F_21 ( V_19 ,
V_49 ) ;
F_29 ( V_19 ) ;
F_30 ( & V_19 -> V_22 ) ;
} else {
F_21 ( V_19 , V_50 ) ;
F_31 ( V_19 ) ;
}
break;
case V_41 :
case V_42 :
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_44 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_41 :
if ( F_26 ( V_8 ) != V_45 ) {
F_21 ( V_19 , V_50 ) ;
F_31 ( V_19 ) ;
break;
}
V_19 -> V_46 = V_47 ;
V_19 -> V_22 . V_48 = F_27 ( V_8 ) ;
V_19 -> V_22 . V_48 = F_28 ( V_19 -> V_22 . V_48 ) ;
F_21 ( V_19 , V_49 ) ;
F_29 ( V_19 ) ;
F_30 ( & V_19 -> V_22 ) ;
break;
case V_53 :
case V_54 :
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
case V_55 :
F_21 ( V_19 , V_56 ) ;
F_33 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_50 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_57 :
F_34 ( V_19 -> V_3 -> V_8 ,
V_19 -> V_58 ) ;
V_19 -> V_46 = V_59 ;
if ( V_19 -> V_60 && V_19 -> V_61 ) {
F_21 ( V_19 , V_62 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
} else {
F_21 ( V_19 , V_49 ) ;
F_35 ( V_19 ) ;
}
break;
case V_53 :
F_21 ( V_19 , V_63 ) ;
F_36 ( V_19 -> V_3 -> V_8 , & V_19 -> V_64 ,
V_65 , V_19 ,
V_66 ) ;
break;
case V_54 :
F_21 ( V_19 , V_67 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
F_29 ( V_19 ) ;
break;
case V_70 :
V_19 -> V_46 = V_71 ;
F_34 ( V_19 -> V_3 -> V_8 ,
V_19 -> V_58 ) ;
F_35 ( V_19 ) ;
F_21 ( V_19 , V_72 ) ;
break;
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_63 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_73 :
F_21 ( V_19 , V_50 ) ;
F_31 ( V_19 ) ;
break;
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_38 ( & V_19 -> V_64 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_38 ( & V_19 -> V_64 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_62 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_74 :
F_21 ( V_19 , V_75 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
break;
case V_76 :
F_21 ( V_19 , V_49 ) ;
F_35 ( V_19 ) ;
break;
case V_77 :
F_21 ( V_19 , V_78 ) ;
break;
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
void
V_75 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_39 ( V_19 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
void
V_67 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_39 ( V_19 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_72 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
F_39 ( V_19 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
case V_70 :
F_20 ( V_19 -> V_3 , V_19 -> V_58 ) ;
F_34 ( V_19 -> V_3 -> V_8 ,
V_19 -> V_58 ) ;
break;
case V_53 :
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
void
V_49 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_42 :
F_21 ( V_19 , V_44 ) ;
if ( F_26 ( V_8 ) == V_45 ) {
F_40 ( & V_19 -> V_22 ) ;
} else {
F_37 ( V_19 -> V_68 , V_69 ) ;
F_39 ( V_19 ) ;
}
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
case V_55 :
F_21 ( V_19 , V_79 ) ;
F_33 ( V_19 ) ;
break;
case V_74 :
F_21 ( V_19 , V_75 ) ;
F_37 ( V_19 -> V_68 , V_69 ) ;
break;
case V_76 :
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_78 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_57 :
F_21 ( V_19 , V_80 ) ;
break;
case V_81 :
F_21 ( V_19 , V_82 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_80 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
}
static void
V_82 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
struct V_4 * V_5 = (struct V_4 * ) V_19 -> V_3 -> V_5 ;
char V_83 [ V_84 ] ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
F_41 ( V_83 , V_19 -> V_22 . V_21 . V_27 ) ;
F_42 ( V_85 , V_5 , V_86 ,
L_1
L_2 ,
V_83 , V_19 -> V_3 -> V_87 ,
V_19 -> V_88 . V_89 ) ;
}
static void
V_52 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_90 :
F_21 ( V_19 , F_19 ) ;
F_43 ( & V_19 -> V_3 -> V_28 ) ;
break;
case V_41 :
break;
case V_42 :
F_39 ( V_19 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_79 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_91 :
if ( F_26 ( V_8 ) == V_45 ) {
F_21 ( V_19 , V_40 ) ;
} else {
F_21 ( V_19 , V_56 ) ;
F_37 ( V_19 -> V_68 , V_92 ) ;
}
break;
case V_41 :
break;
case V_42 :
if ( F_26 ( V_8 ) == V_45 )
F_21 ( V_19 , V_40 ) ;
else
F_21 ( V_19 , V_56 ) ;
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
V_56 ( struct V_18 * V_19 ,
enum V_37 V_38 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
switch ( V_38 ) {
case V_91 :
case V_93 :
F_21 ( V_19 , V_40 ) ;
F_43 ( & ( V_19 -> V_3 ) -> V_28 ) ;
break;
case V_42 :
break;
default:
F_24 ( V_19 -> V_3 , V_38 ) ;
}
}
static void
F_22 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_22 . V_21 ;
V_21 -> V_94 = V_95 ;
V_21 -> V_25 = V_19 -> V_3 -> V_8 -> V_24 . V_26 -> V_25 ;
V_21 -> V_27 = V_19 -> V_3 -> V_8 -> V_24 . V_26 -> V_27 ;
}
void
F_16 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_22 . V_21 ;
char V_96 [ V_97 ] = { 0 } ;
struct V_33 * V_34 = & V_19 -> V_3 -> V_34 ;
F_44 ( & V_19 -> V_3 -> V_8 -> V_24 , V_96 ) ;
strncpy ( ( char * ) & V_21 -> V_98 , V_96 ,
V_99 ) ;
strncat ( ( char * ) & V_21 -> V_98 , V_100 ,
sizeof( V_100 ) ) ;
strncat ( ( char * ) & V_21 -> V_98 , ( char * ) V_34 -> V_101 ,
V_102 ) ;
strncat ( ( char * ) & V_21 -> V_98 , V_100 ,
sizeof( V_100 ) ) ;
strncat ( ( char * ) & V_21 -> V_98 ,
( char * ) V_34 -> V_103 ,
V_104 ) ;
strncat ( ( char * ) & V_21 -> V_98 , V_100 ,
sizeof( V_100 ) ) ;
if ( V_34 -> V_105 [ 0 ] == '\0' ) {
strncat ( ( char * ) & V_21 -> V_98 ,
( char * ) V_34 -> V_106 ,
V_107 ) ;
strncat ( ( char * ) & V_21 -> V_98 ,
V_100 ,
sizeof( V_100 ) ) ;
} else {
strncat ( ( char * ) & V_21 -> V_98 ,
( char * ) V_34 -> V_106 ,
V_108 ) ;
strncat ( ( char * ) & V_21 -> V_98 ,
V_100 ,
sizeof( V_100 ) ) ;
strncat ( ( char * ) & V_21 -> V_98 ,
( char * ) V_34 -> V_105 ,
V_109 ) ;
}
V_21 -> V_98 . V_110 [ V_111 - 1 ] = 0 ;
}
void
F_17 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_22 . V_21 ;
char V_96 [ V_97 ] = { 0 } ;
struct V_33 * V_34 = & V_19 -> V_3 -> V_34 ;
F_44 ( & V_19 -> V_3 -> V_8 -> V_24 , V_96 ) ;
strncpy ( ( char * ) & V_21 -> V_112 , V_96 ,
V_99 ) ;
strncat ( ( char * ) & V_21 -> V_112 ,
V_100 ,
sizeof( V_100 ) ) ;
strncat ( ( char * ) & V_21 -> V_112 , ( char * ) V_34 -> V_101 ,
V_102 ) ;
strncat ( ( char * ) & V_21 -> V_112 ,
V_100 ,
sizeof( V_100 ) ) ;
strncat ( ( char * ) & V_21 -> V_112 ,
( char * ) V_34 -> V_103 ,
V_104 ) ;
strncat ( ( char * ) & V_21 -> V_112 ,
V_100 ,
sizeof( V_100 ) ) ;
V_21 -> V_112 . V_110 [ V_111 - 1 ] = 0 ;
}
void
F_45 ( void * V_5 , void * V_113 , T_2 V_114 )
{
struct V_18 * V_19 = V_113 ;
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_20 ( V_19 -> V_3 , V_114 ) ;
switch ( V_114 ) {
case V_115 :
V_19 -> V_116 . V_117 ++ ;
break;
case V_118 :
V_19 -> V_116 . V_119 ++ ;
F_37 ( V_19 , V_53 ) ;
return;
case V_120 :
switch ( V_19 -> V_68 -> V_121 ) {
case V_122 :
V_19 -> V_116 . V_119 ++ ;
break;
case V_123 :
V_19 -> V_116 . V_124 ++ ;
break;
default:
break;
}
F_37 ( V_19 , V_53 ) ;
return;
case V_125 :
V_19 -> V_116 . V_126 ++ ;
F_37 ( V_19 , V_53 ) ;
return;
default:
V_19 -> V_116 . V_127 ++ ;
F_37 ( V_19 , V_53 ) ;
return;
}
V_19 -> V_58 = V_19 -> V_68 -> V_128 ;
F_20 ( V_19 -> V_3 , V_19 -> V_58 ) ;
if ( ! ( V_19 -> V_68 -> V_129 ) )
V_19 -> V_130 = V_19 -> V_68 -> V_131 ;
if ( V_19 -> V_68 -> V_132 ) {
V_19 -> V_22 . V_48 = V_19 -> V_68 -> V_133 ;
V_19 -> V_134 = V_19 -> V_68 -> V_135 ;
V_19 -> V_61 = V_19 -> V_68 -> V_136 ;
F_37 ( V_19 , V_57 ) ;
} else {
V_19 -> V_22 . V_137 . V_138 . V_139 =
V_19 -> V_68 -> V_140 ;
V_19 -> V_46 = V_71 ;
F_37 ( V_19 , V_70 ) ;
}
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_48 ) ;
F_20 ( V_19 -> V_3 , V_19 -> V_134 ) ;
F_20 ( V_19 -> V_3 , V_19 -> V_61 ) ;
}
static void
F_31 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
struct V_20 * V_141 = & V_19 -> V_22 . V_21 ;
T_3 V_142 = 0 ;
F_46 ( V_19 -> V_68 , V_19 , V_142 , F_47 ( V_8 ) ,
V_141 -> V_27 , V_141 -> V_25 , V_19 -> V_60 ) ;
V_19 -> V_116 . V_143 ++ ;
}
static void
F_35 ( struct V_18 * V_19 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 , * V_148 ;
F_20 ( V_19 -> V_3 , V_19 -> V_130 ) ;
F_29 ( V_19 ) ;
V_19 -> V_116 . V_149 ++ ;
F_30 ( & V_19 -> V_22 ) ;
F_48 (qe, qen, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
F_49 ( V_145 ) ;
}
}
static void
F_39 ( struct V_18 * V_19 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 , * V_148 ;
F_20 ( V_19 -> V_3 , V_19 -> V_130 ) ;
V_19 -> V_116 . V_150 ++ ;
F_48 (qe, qen, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
F_50 ( V_145 ) ;
}
F_40 ( & V_19 -> V_22 ) ;
V_19 -> V_130 = 0 ;
V_19 -> V_151 [ 0 ] = 0 ;
}
static void
V_65 ( void * V_152 )
{
struct V_18 * V_19 = V_152 ;
F_37 ( V_19 , V_73 ) ;
}
static void
F_33 ( struct V_18 * V_19 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 , * V_148 ;
F_8 ( & V_19 -> V_153 , V_154 , V_19 ) ;
F_48 (qe, qen, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
F_9 ( & V_19 -> V_153 ) ;
F_51 ( V_145 ) ;
}
F_9 ( & V_19 -> V_153 ) ;
F_52 ( & V_19 -> V_22 ) ;
F_11 ( & V_19 -> V_153 ) ;
}
static void
F_32 ( struct V_18 * V_19 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 , * V_148 ;
F_48 (qe, qen, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
F_53 ( V_145 ) ;
}
F_54 ( & V_19 -> V_22 ) ;
F_11 ( & V_19 -> V_28 ) ;
}
static void
F_55 ( void * V_152 )
{
struct V_18 * V_19 = V_152 ;
F_37 ( V_19 , V_90 ) ;
}
static void
V_154 ( void * V_152 )
{
struct V_18 * V_19 = V_152 ;
F_37 ( V_19 , V_91 ) ;
}
void
F_56 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
V_19 = & V_3 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 -> V_3 = V_3 ;
F_57 ( & V_19 -> V_155 ) ;
F_57 ( & V_19 -> V_156 ) ;
V_19 -> V_68 = F_58 ( V_3 -> V_8 ) ;
F_59 ( ! V_19 -> V_68 ) ;
F_8 ( & V_19 -> V_28 , F_55 , V_19 ) ;
F_9 ( & V_19 -> V_28 ) ;
F_21 ( V_19 , F_19 ) ;
F_60 ( & V_19 -> V_22 , V_19 -> V_3 , V_157 , NULL ) ;
}
void
F_61 ( struct V_2 * V_3 )
{
F_37 ( & V_3 -> V_19 , V_39 ) ;
F_20 ( V_3 , 0 ) ;
}
void
F_62 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_63 ( V_19 -> V_68 ) ;
F_37 ( V_19 , V_51 ) ;
}
void
F_10 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_37 ( V_19 , V_55 ) ;
}
void
F_64 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_37 ( V_19 , V_43 ) ;
}
void
F_65 ( struct V_18 * V_19 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_37 ( V_19 , V_41 ) ;
}
void
F_66 ( struct V_18 * V_19 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_37 ( V_19 , V_42 ) ;
}
void
F_67 ( struct V_18 * V_19 ,
struct V_144 * V_145 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_158 ) ;
F_68 ( & V_145 -> V_147 , & V_19 -> V_155 ) ;
V_19 -> V_159 ++ ;
F_9 ( & V_19 -> V_28 ) ;
}
void
F_69 ( struct V_18 * V_19 ,
struct V_144 * V_145 )
{
F_70 ( & V_145 -> V_147 ) ;
V_19 -> V_159 -- ;
F_43 ( & V_19 -> V_28 ) ;
}
struct V_144 *
F_71 ( struct V_18 * V_19 , T_4 V_27 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 ;
F_72 (qe, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
if ( F_73 ( & V_145 -> V_160 ) == V_27 )
return V_145 ;
}
return NULL ;
}
T_5
F_74 ( struct V_18 * V_19 )
{
T_4 V_161 ;
T_3 * V_162 ;
T_5 V_163 ;
V_161 = V_19 -> V_68 -> V_131 ;
V_162 = ( T_3 * ) & V_161 ;
V_163 = ( V_162 [ 3 ] << 8 ) | V_162 [ 4 ] ;
return V_163 ;
}
void
F_75 ( struct V_18 * V_19 , struct V_164 * V_165 ,
T_5 V_166 )
{
T_6 V_48 = V_165 -> V_167 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_168 * V_169 = (struct V_168 * ) ( V_165 + 1 ) ;
struct V_170 * V_171 = (struct V_170 * ) V_169 ;
F_20 ( V_19 -> V_3 , V_166 ) ;
F_20 ( V_19 -> V_3 , V_48 ) ;
if ( ( V_48 == F_76 ( V_172 ) ) &&
( V_169 -> V_173 == V_174 ) &&
( V_171 -> V_175 == F_73 ( & V_19 -> V_22 ) ) ) {
F_37 ( V_19 , V_54 ) ;
return;
}
if ( V_165 -> V_167 == F_28 ( V_172 ) ) {
F_20 ( V_19 -> V_3 , V_48 ) ;
F_77 ( V_19 , V_165 , V_166 ) ;
return;
}
if ( V_19 -> V_22 . V_48 == V_48 ) {
F_20 ( V_19 -> V_3 , V_169 -> V_173 ) ;
if ( V_169 -> V_173 == V_176 ) {
F_20 ( V_19 -> V_3 , V_169 -> V_173 ) ;
return;
}
F_20 ( V_19 -> V_3 , * ( T_3 * ) ( ( T_3 * ) V_165 ) ) ;
F_78 ( & V_19 -> V_22 , V_165 , V_166 ) ;
return;
}
F_72 (qe, &fabric->vport_q) {
V_145 = (struct V_144 * ) V_147 ;
if ( V_145 -> V_160 . V_48 == V_48 ) {
F_78 ( & V_145 -> V_160 , V_165 , V_166 ) ;
return;
}
}
if ( ! F_79 ( V_19 ) )
F_78 ( & V_19 -> V_22 , V_165 , V_166 ) ;
F_20 ( V_19 -> V_3 , V_165 -> type ) ;
}
static void
F_77 ( struct V_18 * V_19 , struct V_164 * V_165 ,
T_5 V_166 )
{
struct V_168 * V_169 = (struct V_168 * ) ( V_165 + 1 ) ;
F_20 ( V_19 -> V_3 , V_169 -> V_173 ) ;
switch ( V_169 -> V_173 ) {
case V_174 :
F_80 ( V_19 , V_165 , V_166 ) ;
break;
default:
break;
}
}
static void
F_80 ( struct V_18 * V_19 ,
struct V_164 * V_165 , T_5 V_166 )
{
struct V_170 * V_171 = (struct V_170 * ) ( V_165 + 1 ) ;
struct V_177 * V_22 = & V_19 -> V_22 ;
F_20 ( V_19 -> V_3 , V_165 -> V_178 ) ;
V_19 -> V_116 . V_179 ++ ;
if ( V_171 -> V_180 . V_181 ) {
F_20 ( V_19 -> V_3 , V_171 -> V_175 ) ;
V_19 -> V_116 . V_182 ++ ;
return;
}
V_19 -> V_58 = F_81 ( V_171 -> V_180 . V_183 ) ;
V_22 -> V_137 . V_138 . V_139 = V_171 -> V_175 ;
V_22 -> V_137 . V_138 . V_184 = V_165 -> V_185 ;
F_82 ( V_19 ) ;
F_37 ( V_19 , V_70 ) ;
}
static void
F_82 ( struct V_18 * V_19 )
{
struct V_20 * V_141 = & V_19 -> V_22 . V_21 ;
struct V_186 * V_187 = & V_19 -> V_22 . V_137 . V_138 ;
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
struct V_188 * V_189 ;
T_5 V_190 ;
struct V_164 V_165 ;
V_189 = F_83 ( V_19 -> V_3 , V_191 ) ;
if ( ! V_189 )
return;
V_190 = F_84 ( & V_165 , F_85 ( V_189 ) ,
F_28 ( V_172 ) ,
V_187 -> V_184 , V_141 -> V_27 ,
V_141 -> V_25 ,
F_47 ( V_8 ) ,
F_86 ( V_8 ) , 0 ) ;
F_87 ( V_189 , NULL , V_19 -> V_158 , V_19 -> V_68 -> V_192 ,
V_191 , V_193 ,
V_190 , & V_165 , V_194 , V_19 ,
V_195 , 0 ) ;
}
static void
V_194 ( void * V_196 , struct V_188 * V_189 , void * V_152 ,
T_2 V_114 , T_6 V_197 ,
T_6 V_198 , struct V_164 * V_199 )
{
struct V_18 * V_19 = V_152 ;
F_20 ( V_19 -> V_3 , V_114 ) ;
}
static void
F_88 ( struct V_177 * V_200 ,
enum V_201 V_38 )
{
struct V_4 * V_5 = (struct V_4 * ) V_200 -> V_19 -> V_3 -> V_5 ;
struct V_202 * V_203 ;
F_89 ( V_5 , V_203 ) ;
if ( ! V_203 )
return;
V_203 -> V_204 . V_200 . V_27 = F_73 ( V_200 ) ;
V_203 -> V_204 . V_200 . V_205 = F_90 ( V_200 ) ;
F_91 ( V_203 , V_5 , ++ V_200 -> V_3 -> V_206 ,
V_207 , V_38 ) ;
}
void
F_92 ( struct V_18 * V_19 ,
T_4 V_130 )
{
struct V_4 * V_5 = (struct V_4 * ) V_19 -> V_3 -> V_5 ;
char V_83 [ V_84 ] ;
char V_208 [ V_84 ] ;
F_20 ( V_19 -> V_3 , V_130 ) ;
if ( V_19 -> V_130 == 0 ) {
V_19 -> V_130 = V_130 ;
} else {
V_19 -> V_130 = V_130 ;
F_41 ( V_83 , F_73 ( & V_19 -> V_22 ) ) ;
F_41 ( V_208 ,
F_90 ( & V_19 -> V_22 ) ) ;
F_42 ( V_209 , V_5 , V_86 ,
L_3 ,
V_83 , V_208 ) ;
F_88 ( & V_19 -> V_22 ,
V_210 ) ;
}
}
void
F_93 ( void * V_5 , void * V_113 )
{
struct V_18 * V_19 = V_113 ;
F_37 ( V_19 , V_93 ) ;
}
T_7 *
F_94 ( struct V_2 * V_3 , T_5 V_158 )
{
F_20 ( V_3 , V_158 ) ;
if ( V_158 == V_157 )
return & V_3 -> V_19 ;
return NULL ;
}
void
F_95 ( T_7 * V_211 , T_4 V_212 [] , int * V_213 )
{
struct V_146 * V_147 ;
struct V_144 * V_145 ;
int V_10 = 0 ;
struct V_2 * V_3 ;
if ( V_211 == NULL || V_212 == NULL || * V_213 == 0 )
return;
V_3 = V_211 -> V_3 ;
F_20 ( V_3 , V_211 -> V_158 ) ;
F_20 ( V_3 , ( V_214 ) * V_213 ) ;
V_212 [ V_10 ++ ] = V_211 -> V_22 . V_21 . V_27 ;
F_72 (qe, &vf->vport_q) {
if ( V_10 >= * V_213 )
break;
V_145 = (struct V_144 * ) V_147 ;
V_212 [ V_10 ++ ] = V_145 -> V_160 . V_21 . V_27 ;
}
F_20 ( V_3 , V_10 ) ;
* V_213 = V_10 ;
}
static void
F_96 ( void * V_152 , enum V_215 V_38 )
{
struct V_2 * V_3 = V_152 ;
F_20 ( V_3 , V_38 ) ;
switch ( V_38 ) {
case V_216 :
F_65 ( & V_3 -> V_19 ) ;
break;
case V_217 :
F_66 ( & V_3 -> V_19 ) ;
break;
default:
F_59 ( 1 ) ;
}
}
void
F_97 ( struct V_2 * V_3 )
{
F_98 ( V_3 -> V_8 , F_96 , V_3 ) ;
}
static void
F_99 ( void * V_152 , struct V_218 * V_219 )
{
struct V_2 * V_3 = (struct V_2 * ) V_152 ;
struct V_164 * V_165 = F_100 ( V_219 ) ;
T_5 V_166 = F_101 ( V_219 ) ;
struct V_220 * V_221 ;
struct V_18 * V_19 ;
if ( V_165 -> V_222 == V_223 &&
V_165 -> V_224 == V_225 ) {
F_102 ( V_3 , V_219 . V_226 ) ;
V_221 = F_100 ( V_219 ) ;
if ( V_3 -> V_87 == V_221 -> V_158 )
V_19 = & V_3 -> V_19 ;
else
V_19 = F_94 ( V_3 , ( T_5 ) V_221 -> V_158 ) ;
if ( ! V_19 ) {
F_59 ( 1 ) ;
F_102 ( V_3 , V_219 . V_227 ) ;
F_103 ( V_219 ) ;
return;
}
V_165 = (struct V_164 * ) ( V_221 + 1 ) ;
V_166 -= sizeof( struct V_220 ) ;
F_20 ( V_3 , V_221 -> V_158 ) ;
} else {
F_102 ( V_3 , V_219 . V_228 ) ;
V_19 = & V_3 -> V_19 ;
}
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 0 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 1 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 2 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 3 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 4 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_165 ) [ 5 ] ) ;
F_20 ( V_3 , V_166 ) ;
F_75 ( V_19 , V_165 , V_166 ) ;
F_103 ( V_219 ) ;
}
void
F_104 ( struct V_2 * V_3 )
{
F_105 ( V_3 -> V_8 , F_99 , V_3 ) ;
}
