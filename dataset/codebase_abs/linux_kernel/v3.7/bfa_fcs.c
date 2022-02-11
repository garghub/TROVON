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
V_19 -> V_58 ,
F_35 ( V_19 ) ) ;
V_19 -> V_46 = V_59 ;
if ( V_19 -> V_60 && V_19 -> V_61 ) {
F_21 ( V_19 , V_62 ) ;
F_20 ( V_19 -> V_3 , V_38 ) ;
} else {
F_21 ( V_19 , V_49 ) ;
F_36 ( V_19 ) ;
}
break;
case V_53 :
F_21 ( V_19 , V_63 ) ;
F_37 ( V_19 -> V_3 -> V_8 , & V_19 -> V_64 ,
V_65 , V_19 ,
V_66 ) ;
break;
case V_54 :
F_21 ( V_19 , V_67 ) ;
F_38 ( V_19 -> V_68 , V_69 ) ;
F_29 ( V_19 ) ;
break;
case V_70 :
V_19 -> V_46 = V_71 ;
F_34 ( V_19 -> V_3 -> V_8 ,
V_19 -> V_58 ,
F_35 ( V_19 ) ) ;
F_36 ( V_19 ) ;
F_21 ( V_19 , V_72 ) ;
break;
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_38 ( V_19 -> V_68 , V_69 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_38 ( V_19 -> V_68 , V_69 ) ;
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
F_39 ( & V_19 -> V_64 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_39 ( & V_19 -> V_64 ) ;
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
F_38 ( V_19 -> V_68 , V_69 ) ;
break;
case V_76 :
F_21 ( V_19 , V_49 ) ;
F_36 ( V_19 ) ;
break;
case V_77 :
F_21 ( V_19 , V_78 ) ;
break;
case V_42 :
F_21 ( V_19 , V_44 ) ;
F_38 ( V_19 -> V_68 , V_69 ) ;
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
F_40 ( V_19 ) ;
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
F_40 ( V_19 ) ;
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
F_38 ( V_19 -> V_68 , V_69 ) ;
F_40 ( V_19 ) ;
break;
case V_51 :
F_21 ( V_19 , V_52 ) ;
F_32 ( V_19 ) ;
break;
case V_70 :
F_20 ( V_19 -> V_3 , V_19 -> V_58 ) ;
F_34 ( V_19 -> V_3 -> V_8 ,
V_19 -> V_58 ,
F_35 ( V_19 ) ) ;
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
F_41 ( & V_19 -> V_22 ) ;
} else {
F_38 ( V_19 -> V_68 , V_69 ) ;
F_40 ( V_19 ) ;
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
F_38 ( V_19 -> V_68 , V_69 ) ;
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
F_42 ( V_83 , V_19 -> V_22 . V_21 . V_27 ) ;
F_43 ( V_85 , V_5 , V_86 ,
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
F_44 ( & V_19 -> V_3 -> V_28 ) ;
break;
case V_41 :
break;
case V_42 :
F_40 ( V_19 ) ;
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
F_38 ( V_19 -> V_68 , V_92 ) ;
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
F_44 ( & ( V_19 -> V_3 ) -> V_28 ) ;
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
F_45 ( & V_19 -> V_3 -> V_8 -> V_24 , V_96 ) ;
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
F_45 ( & V_19 -> V_3 -> V_8 -> V_24 , V_96 ) ;
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
F_46 ( void * V_5 , void * V_113 , T_2 V_114 )
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
F_38 ( V_19 , V_53 ) ;
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
F_38 ( V_19 , V_53 ) ;
return;
case V_125 :
V_19 -> V_116 . V_126 ++ ;
if ( V_19 -> V_68 -> V_127 == V_128 &&
V_19 -> V_68 -> V_129 == V_130 )
V_19 -> V_3 -> V_131 = V_14 ;
F_38 ( V_19 , V_53 ) ;
return;
default:
V_19 -> V_116 . V_132 ++ ;
F_38 ( V_19 , V_53 ) ;
return;
}
V_19 -> V_58 = V_19 -> V_68 -> V_133 ;
F_20 ( V_19 -> V_3 , V_19 -> V_58 ) ;
if ( ! ( V_19 -> V_68 -> V_134 ) )
V_19 -> V_135 = V_19 -> V_68 -> V_136 ;
if ( V_19 -> V_68 -> V_137 ) {
V_19 -> V_22 . V_48 = V_19 -> V_68 -> V_138 ;
V_19 -> V_139 = V_19 -> V_68 -> V_140 ;
V_19 -> V_61 = V_19 -> V_68 -> V_141 ;
F_38 ( V_19 , V_57 ) ;
} else {
V_19 -> V_22 . V_142 . V_143 . V_144 =
V_19 -> V_68 -> V_145 ;
V_19 -> V_46 = V_71 ;
F_38 ( V_19 , V_70 ) ;
}
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_48 ) ;
F_20 ( V_19 -> V_3 , V_19 -> V_139 ) ;
F_20 ( V_19 -> V_3 , V_19 -> V_61 ) ;
}
static void
F_31 ( struct V_18 * V_19 )
{
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
struct V_20 * V_146 = & V_19 -> V_22 . V_21 ;
T_3 V_147 = 0 , V_148 = 0 ;
if ( F_47 ( V_19 ) &&
( ! V_19 -> V_3 -> V_131 ) )
V_148 = V_149 ;
F_48 ( V_19 -> V_68 , V_19 , V_147 , F_49 ( V_8 ) ,
V_146 -> V_27 , V_146 -> V_25 , V_19 -> V_60 , V_148 ) ;
V_19 -> V_116 . V_150 ++ ;
}
static void
F_36 ( struct V_18 * V_19 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 , * V_155 ;
F_20 ( V_19 -> V_3 , V_19 -> V_135 ) ;
F_29 ( V_19 ) ;
V_19 -> V_116 . V_156 ++ ;
F_30 ( & V_19 -> V_22 ) ;
F_50 (qe, qen, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
F_51 ( V_152 ) ;
}
}
static void
F_40 ( struct V_18 * V_19 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 , * V_155 ;
F_20 ( V_19 -> V_3 , V_19 -> V_135 ) ;
V_19 -> V_116 . V_157 ++ ;
F_50 (qe, qen, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
F_52 ( V_152 ) ;
}
F_41 ( & V_19 -> V_22 ) ;
V_19 -> V_135 = 0 ;
V_19 -> V_158 [ 0 ] = 0 ;
}
static void
V_65 ( void * V_159 )
{
struct V_18 * V_19 = V_159 ;
F_38 ( V_19 , V_73 ) ;
}
static void
F_33 ( struct V_18 * V_19 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 , * V_155 ;
F_8 ( & V_19 -> V_160 , V_161 , V_19 ) ;
F_50 (qe, qen, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
F_9 ( & V_19 -> V_160 ) ;
F_53 ( V_152 ) ;
}
F_9 ( & V_19 -> V_160 ) ;
F_54 ( & V_19 -> V_22 ) ;
F_11 ( & V_19 -> V_160 ) ;
}
static T_3
F_35 ( struct V_18 * V_19 )
{
T_3 V_162 = V_19 -> V_68 -> V_162 ;
struct V_163 * V_164 = F_55 ( V_19 -> V_3 -> V_8 ) ;
if ( ! ( V_164 -> V_165 . V_166 && V_162 ) )
return 0 ;
return ( ( V_162 > V_149 ) ?
V_162 : V_149 ) ;
}
static T_1
F_47 ( struct V_18 * V_19 )
{
struct V_163 * V_164 = F_55 ( V_19 -> V_3 -> V_8 ) ;
if ( F_56 ( & V_19 -> V_3 -> V_8 -> V_24 ) &&
V_164 -> V_165 . V_166 &&
! F_57 ( V_19 -> V_3 -> V_8 ) &&
! F_58 ( V_19 -> V_3 -> V_8 ) )
return V_14 ;
else
return V_167 ;
}
static void
F_32 ( struct V_18 * V_19 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 , * V_155 ;
F_50 (qe, qen, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
F_59 ( V_152 ) ;
}
F_60 ( & V_19 -> V_22 ) ;
F_11 ( & V_19 -> V_28 ) ;
}
static void
F_61 ( void * V_159 )
{
struct V_18 * V_19 = V_159 ;
F_38 ( V_19 , V_90 ) ;
}
static void
V_161 ( void * V_159 )
{
struct V_18 * V_19 = V_159 ;
F_38 ( V_19 , V_91 ) ;
}
void
F_62 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
V_19 = & V_3 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 -> V_3 = V_3 ;
F_63 ( & V_19 -> V_168 ) ;
F_63 ( & V_19 -> V_169 ) ;
V_19 -> V_68 = F_64 ( V_3 -> V_8 ) ;
F_65 ( ! V_19 -> V_68 ) ;
F_8 ( & V_19 -> V_28 , F_61 , V_19 ) ;
F_9 ( & V_19 -> V_28 ) ;
F_21 ( V_19 , F_19 ) ;
F_66 ( & V_19 -> V_22 , V_19 -> V_3 , V_170 , NULL ) ;
}
void
F_67 ( struct V_2 * V_3 )
{
F_38 ( & V_3 -> V_19 , V_39 ) ;
F_20 ( V_3 , 0 ) ;
}
void
F_68 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_69 ( V_19 -> V_68 ) ;
F_38 ( V_19 , V_51 ) ;
}
void
F_10 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_38 ( V_19 , V_55 ) ;
}
void
F_70 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
F_20 ( V_3 , 0 ) ;
V_19 = & V_3 -> V_19 ;
F_38 ( V_19 , V_43 ) ;
}
void
F_71 ( struct V_18 * V_19 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
F_38 ( V_19 , V_41 ) ;
}
void
F_72 ( struct V_18 * V_19 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_22 . V_21 . V_27 ) ;
V_19 -> V_3 -> V_131 = V_167 ;
F_38 ( V_19 , V_42 ) ;
}
void
F_73 ( struct V_18 * V_19 ,
struct V_151 * V_152 )
{
F_20 ( V_19 -> V_3 , V_19 -> V_171 ) ;
F_74 ( & V_152 -> V_154 , & V_19 -> V_168 ) ;
V_19 -> V_172 ++ ;
F_9 ( & V_19 -> V_28 ) ;
}
void
F_75 ( struct V_18 * V_19 ,
struct V_151 * V_152 )
{
F_76 ( & V_152 -> V_154 ) ;
V_19 -> V_172 -- ;
F_44 ( & V_19 -> V_28 ) ;
}
struct V_151 *
F_77 ( struct V_18 * V_19 , T_4 V_27 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 ;
F_78 (qe, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
if ( F_79 ( & V_152 -> V_173 ) == V_27 )
return V_152 ;
}
return NULL ;
}
T_5
F_80 ( struct V_18 * V_19 )
{
T_4 V_174 ;
T_3 * V_175 ;
T_5 V_176 ;
V_174 = V_19 -> V_68 -> V_136 ;
V_175 = ( T_3 * ) & V_174 ;
V_176 = ( V_175 [ 3 ] << 8 ) | V_175 [ 4 ] ;
return V_176 ;
}
void
F_81 ( struct V_18 * V_19 , struct V_177 * V_178 ,
T_5 V_179 )
{
T_6 V_48 = V_178 -> V_180 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_181 * V_182 = (struct V_181 * ) ( V_178 + 1 ) ;
struct V_183 * V_184 = (struct V_183 * ) V_182 ;
F_20 ( V_19 -> V_3 , V_179 ) ;
F_20 ( V_19 -> V_3 , V_48 ) ;
if ( ( V_48 == F_82 ( V_185 ) ) &&
( V_182 -> V_186 == V_187 ) &&
( V_184 -> V_188 == F_79 ( & V_19 -> V_22 ) ) ) {
F_38 ( V_19 , V_54 ) ;
return;
}
if ( V_178 -> V_180 == F_28 ( V_185 ) ) {
F_20 ( V_19 -> V_3 , V_48 ) ;
F_83 ( V_19 , V_178 , V_179 ) ;
return;
}
if ( V_19 -> V_22 . V_48 == V_48 ) {
F_20 ( V_19 -> V_3 , V_182 -> V_186 ) ;
if ( V_182 -> V_186 == V_189 ) {
F_20 ( V_19 -> V_3 , V_182 -> V_186 ) ;
return;
}
F_20 ( V_19 -> V_3 , * ( T_3 * ) ( ( T_3 * ) V_178 ) ) ;
F_84 ( & V_19 -> V_22 , V_178 , V_179 ) ;
return;
}
F_78 (qe, &fabric->vport_q) {
V_152 = (struct V_151 * ) V_154 ;
if ( V_152 -> V_173 . V_48 == V_48 ) {
F_84 ( & V_152 -> V_173 , V_178 , V_179 ) ;
return;
}
}
if ( ! F_85 ( V_19 ) )
F_84 ( & V_19 -> V_22 , V_178 , V_179 ) ;
F_20 ( V_19 -> V_3 , V_178 -> type ) ;
}
static void
F_83 ( struct V_18 * V_19 , struct V_177 * V_178 ,
T_5 V_179 )
{
struct V_181 * V_182 = (struct V_181 * ) ( V_178 + 1 ) ;
F_20 ( V_19 -> V_3 , V_182 -> V_186 ) ;
switch ( V_182 -> V_186 ) {
case V_187 :
F_86 ( V_19 , V_178 , V_179 ) ;
break;
default:
break;
}
}
static void
F_86 ( struct V_18 * V_19 ,
struct V_177 * V_178 , T_5 V_179 )
{
struct V_183 * V_184 = (struct V_183 * ) ( V_178 + 1 ) ;
struct V_190 * V_22 = & V_19 -> V_22 ;
F_20 ( V_19 -> V_3 , V_178 -> V_191 ) ;
V_19 -> V_116 . V_192 ++ ;
if ( V_184 -> V_193 . V_194 ) {
F_20 ( V_19 -> V_3 , V_184 -> V_188 ) ;
V_19 -> V_116 . V_195 ++ ;
return;
}
V_19 -> V_58 = F_87 ( V_184 -> V_193 . V_196 ) ;
V_19 -> V_68 -> V_162 = ( F_87 ( V_184 -> V_193 . V_197 ) >> 12 ) ;
V_22 -> V_142 . V_143 . V_144 = V_184 -> V_188 ;
V_22 -> V_142 . V_143 . V_198 = V_178 -> V_199 ;
F_88 ( V_19 ) ;
F_38 ( V_19 , V_70 ) ;
}
static void
F_88 ( struct V_18 * V_19 )
{
struct V_20 * V_146 = & V_19 -> V_22 . V_21 ;
struct V_200 * V_201 = & V_19 -> V_22 . V_142 . V_143 ;
struct V_7 * V_8 = V_19 -> V_3 -> V_8 ;
struct V_202 * V_203 ;
T_5 V_204 ;
struct V_177 V_178 ;
V_203 = F_89 ( V_19 -> V_3 , V_167 ) ;
if ( ! V_203 )
return;
V_204 = F_90 ( & V_178 , F_91 ( V_203 ) ,
F_28 ( V_185 ) ,
V_201 -> V_198 , V_146 -> V_27 ,
V_146 -> V_25 ,
F_49 ( V_8 ) ,
F_92 ( V_8 ) ,
F_35 ( V_19 ) ) ;
F_93 ( V_203 , NULL , V_19 -> V_171 , V_19 -> V_68 -> V_205 ,
V_167 , V_206 ,
V_204 , & V_178 , V_207 , V_19 ,
V_208 , 0 ) ;
}
static void
V_207 ( void * V_209 , struct V_202 * V_203 , void * V_159 ,
T_2 V_114 , T_6 V_210 ,
T_6 V_211 , struct V_177 * V_212 )
{
struct V_18 * V_19 = V_159 ;
F_20 ( V_19 -> V_3 , V_114 ) ;
}
static void
F_94 ( struct V_190 * V_213 ,
enum V_214 V_38 )
{
struct V_4 * V_5 = (struct V_4 * ) V_213 -> V_19 -> V_3 -> V_5 ;
struct V_215 * V_216 ;
F_95 ( V_5 , V_216 ) ;
if ( ! V_216 )
return;
V_216 -> V_217 . V_213 . V_27 = F_79 ( V_213 ) ;
V_216 -> V_217 . V_213 . V_218 = F_96 ( V_213 ) ;
F_97 ( V_216 , V_5 , ++ V_213 -> V_3 -> V_219 ,
V_220 , V_38 ) ;
}
void
F_98 ( struct V_18 * V_19 ,
T_4 V_135 )
{
struct V_4 * V_5 = (struct V_4 * ) V_19 -> V_3 -> V_5 ;
char V_83 [ V_84 ] ;
char V_221 [ V_84 ] ;
F_20 ( V_19 -> V_3 , V_135 ) ;
if ( V_19 -> V_135 == 0 ) {
V_19 -> V_135 = V_135 ;
} else {
V_19 -> V_135 = V_135 ;
F_42 ( V_83 , F_79 ( & V_19 -> V_22 ) ) ;
F_42 ( V_221 ,
F_96 ( & V_19 -> V_22 ) ) ;
F_43 ( V_222 , V_5 , V_86 ,
L_3 ,
V_83 , V_221 ) ;
F_94 ( & V_19 -> V_22 ,
V_223 ) ;
}
}
void
F_99 ( void * V_5 , void * V_113 )
{
struct V_18 * V_19 = V_113 ;
F_38 ( V_19 , V_93 ) ;
}
T_7 *
F_100 ( struct V_2 * V_3 , T_5 V_171 )
{
F_20 ( V_3 , V_171 ) ;
if ( V_171 == V_170 )
return & V_3 -> V_19 ;
return NULL ;
}
void
F_101 ( T_7 * V_224 , T_4 V_225 [] , int * V_226 )
{
struct V_153 * V_154 ;
struct V_151 * V_152 ;
int V_10 = 0 ;
struct V_2 * V_3 ;
if ( V_224 == NULL || V_225 == NULL || * V_226 == 0 )
return;
V_3 = V_224 -> V_3 ;
F_20 ( V_3 , V_224 -> V_171 ) ;
F_20 ( V_3 , ( V_227 ) * V_226 ) ;
V_225 [ V_10 ++ ] = V_224 -> V_22 . V_21 . V_27 ;
F_78 (qe, &vf->vport_q) {
if ( V_10 >= * V_226 )
break;
V_152 = (struct V_151 * ) V_154 ;
V_225 [ V_10 ++ ] = V_152 -> V_173 . V_21 . V_27 ;
}
F_20 ( V_3 , V_10 ) ;
* V_226 = V_10 ;
}
static void
F_102 ( void * V_159 , enum V_228 V_38 )
{
struct V_2 * V_3 = V_159 ;
F_20 ( V_3 , V_38 ) ;
switch ( V_38 ) {
case V_229 :
F_71 ( & V_3 -> V_19 ) ;
break;
case V_230 :
F_72 ( & V_3 -> V_19 ) ;
break;
default:
F_65 ( 1 ) ;
}
}
void
F_103 ( struct V_2 * V_3 )
{
F_104 ( V_3 -> V_8 , F_102 , V_3 ) ;
}
static void
F_105 ( void * V_159 , struct V_231 * V_232 )
{
struct V_2 * V_3 = (struct V_2 * ) V_159 ;
struct V_177 * V_178 = F_106 ( V_232 ) ;
T_5 V_179 = F_107 ( V_232 ) ;
struct V_233 * V_234 ;
struct V_18 * V_19 ;
if ( V_178 -> V_235 == V_236 &&
V_178 -> V_237 == V_238 ) {
F_108 ( V_3 , V_232 . V_239 ) ;
V_234 = F_106 ( V_232 ) ;
if ( V_3 -> V_87 == V_234 -> V_171 )
V_19 = & V_3 -> V_19 ;
else
V_19 = F_100 ( V_3 , ( T_5 ) V_234 -> V_171 ) ;
if ( ! V_19 ) {
F_65 ( 1 ) ;
F_108 ( V_3 , V_232 . V_240 ) ;
F_109 ( V_232 ) ;
return;
}
V_178 = (struct V_177 * ) ( V_234 + 1 ) ;
V_179 -= sizeof( struct V_233 ) ;
F_20 ( V_3 , V_234 -> V_171 ) ;
} else {
F_108 ( V_3 , V_232 . V_241 ) ;
V_19 = & V_3 -> V_19 ;
}
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 0 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 1 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 2 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 3 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 4 ] ) ;
F_20 ( V_3 , ( ( T_6 * ) V_178 ) [ 5 ] ) ;
F_20 ( V_3 , V_179 ) ;
F_81 ( V_19 , V_178 , V_179 ) ;
F_109 ( V_232 ) ;
}
void
F_110 ( struct V_2 * V_3 )
{
F_111 ( V_3 -> V_8 , F_105 , V_3 ) ;
}
