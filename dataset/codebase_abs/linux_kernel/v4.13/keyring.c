static inline bool F_1 ( const struct V_1 * V_2 )
{
return ( unsigned long ) V_2 & V_3 ;
}
static inline struct V_4 * F_2 ( const struct V_1 * V_2 )
{
void * V_5 = F_3 ( V_2 ) ;
return (struct V_4 * ) ( ( unsigned long ) V_5 & ~ V_3 ) ;
}
static inline void * F_4 ( struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return ( void * ) ( ( unsigned long ) V_4 | V_3 ) ;
return V_4 ;
}
static inline unsigned F_5 ( const char * V_7 )
{
unsigned V_8 = 0 ;
for (; * V_7 ; V_7 ++ )
V_8 += ( unsigned char ) * V_7 ;
return V_8 & ( V_9 - 1 ) ;
}
static void F_6 ( struct V_4 * V_10 )
{
int V_8 ;
if ( V_10 -> V_11 ) {
V_8 = F_5 ( V_10 -> V_11 ) ;
F_7 ( & V_12 ) ;
if ( ! V_13 [ V_8 ] . V_14 )
F_8 ( & V_13 [ V_8 ] ) ;
F_9 ( & V_10 -> V_15 ,
& V_13 [ V_8 ] ) ;
F_10 ( & V_12 ) ;
}
}
static int F_11 ( struct V_16 * V_17 )
{
return V_17 -> V_18 != 0 ? - V_19 : 0 ;
}
static void F_12 ( struct V_16 * V_17 )
{
}
static int F_13 ( struct V_4 * V_10 ,
struct V_16 * V_17 )
{
F_14 ( & V_10 -> V_20 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
static T_1 F_15 ( T_1 V_2 , T_2 V_21 )
{
T_1 V_22 = ( T_1 ) ( T_2 ) ( V_2 >> 32 ) * V_21 ;
T_1 V_23 = ( T_1 ) ( T_2 ) ( V_2 ) * V_21 ;
return V_23 + ( ( T_1 ) ( T_2 ) V_22 << 32 ) + ( T_2 ) ( V_22 >> 32 ) ;
}
static unsigned long F_16 ( const struct V_24 * V_25 )
{
const unsigned V_26 = V_27 ;
const unsigned long V_28 = V_29 ;
const char * V_11 = V_25 -> V_11 ;
unsigned long V_30 , type ;
T_2 V_31 ;
T_1 V_32 ;
int V_33 , V_34 = V_25 -> V_34 ;
type = ( unsigned long ) V_25 -> type ;
V_32 = F_15 ( type , V_34 + 13 ) ;
V_32 = F_15 ( V_32 , 9207 ) ;
for (; ; ) {
V_33 = V_34 ;
if ( V_33 <= 0 )
break;
if ( V_33 > 4 )
V_33 = 4 ;
V_31 = 0 ;
memcpy ( & V_31 , V_11 , V_33 ) ;
V_11 += V_33 ;
V_34 -= V_33 ;
V_32 = F_15 ( V_32 , V_31 ) ;
V_32 = F_15 ( V_32 , 9207 ) ;
}
V_30 = V_32 ;
if ( V_35 == 32 )
V_30 ^= V_32 >> 32 ;
if ( V_25 -> type != & V_6 && ( V_30 & V_28 ) == 0 )
return V_30 | ( V_30 >> ( V_35 - V_26 ) ) | 1 ;
if ( V_25 -> type == & V_6 && ( V_30 & V_28 ) != 0 )
return ( V_30 + ( V_30 << V_26 ) ) & ~ V_28 ;
return V_30 ;
}
static unsigned long F_17 ( const void * V_36 , int V_37 )
{
const struct V_24 * V_25 = V_36 ;
unsigned long V_38 = 0 ;
long V_39 = 0 ;
int V_34 = V_25 -> V_34 , V_33 = sizeof( V_38 ) ;
V_37 /= V_35 ;
switch ( V_37 ) {
case 0 :
return F_16 ( V_25 ) ;
case 1 :
return ( ( unsigned long ) V_25 -> type << 8 ) | V_34 ;
case 2 :
if ( V_34 == 0 )
return ( V_40 ) ( ( unsigned long ) V_25 -> type >>
( V_35 - 8 ) ) ;
V_33 -- ;
V_39 = 1 ;
default:
V_39 += sizeof( V_38 ) - 1 ;
V_39 += ( V_37 - 3 ) * sizeof( V_38 ) ;
if ( V_39 >= V_34 )
return 0 ;
V_34 -= V_39 ;
if ( V_34 > V_33 )
V_34 = V_33 ;
V_39 += V_34 ;
do {
V_38 <<= 8 ;
V_38 |= ( ( V_40 * ) V_25 -> V_11 ) [ -- V_39 ] ;
} while ( -- V_34 > 0 );
if ( V_37 == 2 ) {
V_38 <<= 8 ;
V_38 |= ( V_40 ) ( ( unsigned long ) V_25 -> type >>
( V_35 - 8 ) ) ;
}
return V_38 ;
}
}
static unsigned long F_18 ( const void * V_5 , int V_37 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return F_17 ( & V_4 -> V_25 , V_37 ) ;
}
static bool F_19 ( const void * V_5 , const void * V_36 )
{
const struct V_24 * V_25 = V_36 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return V_4 -> V_25 . type == V_25 -> type &&
V_4 -> V_25 . V_34 == V_25 -> V_34 &&
memcmp ( V_4 -> V_25 . V_11 , V_25 -> V_11 ,
V_25 -> V_34 ) == 0 ;
}
static int F_20 ( const void * V_5 , const void * V_36 )
{
const struct V_4 * V_41 = F_2 ( V_5 ) ;
const struct V_24 * V_42 = & V_41 -> V_25 ;
const struct V_24 * V_43 = V_36 ;
unsigned long V_44 , V_45 ;
int V_37 , V_46 ;
V_37 = 0 ;
V_44 = F_16 ( V_42 ) ;
V_45 = F_16 ( V_43 ) ;
if ( ( V_44 ^ V_45 ) != 0 )
goto V_47;
V_37 += V_35 / 8 ;
V_44 = V_42 -> V_34 ;
V_45 = V_43 -> V_34 ;
if ( ( V_44 ^ V_45 ) != 0 )
goto V_47;
V_37 ++ ;
V_44 = ( unsigned long ) V_42 -> type ;
V_45 = ( unsigned long ) V_43 -> type ;
if ( ( V_44 ^ V_45 ) != 0 )
goto V_47;
V_37 += sizeof( unsigned long ) ;
if ( V_42 -> V_34 == 0 )
goto V_48;
V_46 = 0 ;
if ( ( ( unsigned long ) V_42 -> V_11 | ( unsigned long ) V_43 -> V_11 ) &
(sizeof( unsigned long ) - 1 ) ) {
do {
V_44 = * ( unsigned long * ) ( V_42 -> V_11 + V_46 ) ;
V_45 = * ( unsigned long * ) ( V_43 -> V_11 + V_46 ) ;
if ( ( V_44 ^ V_45 ) != 0 )
goto V_49;
V_46 += sizeof( unsigned long ) ;
} while ( V_46 < ( V_42 -> V_34 & (sizeof( unsigned long ) - 1 ) ) );
}
for (; V_46 < V_42 -> V_34 ; V_46 ++ ) {
V_44 = * ( unsigned char * ) ( V_42 -> V_11 + V_46 ) ;
V_45 = * ( unsigned char * ) ( V_43 -> V_11 + V_46 ) ;
if ( ( V_44 ^ V_45 ) != 0 )
goto V_49;
}
V_48:
return - 1 ;
V_49:
V_37 += V_46 ;
V_47:
V_46 = V_37 * 8 + F_21 ( V_44 ^ V_45 ) ;
return V_46 ;
}
static void F_22 ( void * V_5 )
{
F_23 ( F_2 ( V_5 ) ) ;
}
static void F_24 ( struct V_4 * V_10 )
{
if ( V_10 -> V_11 ) {
F_7 ( & V_12 ) ;
if ( V_10 -> V_15 . V_14 != NULL &&
! F_25 ( & V_10 -> V_15 ) )
F_26 ( & V_10 -> V_15 ) ;
F_10 ( & V_12 ) ;
}
if ( V_10 -> V_50 ) {
struct V_51 * V_52 = V_10 -> V_50 ;
F_23 ( V_52 -> V_4 ) ;
F_27 ( V_52 ) ;
}
F_28 ( & V_10 -> V_20 , & V_53 ) ;
}
static void F_29 ( const struct V_4 * V_10 , struct V_54 * V_55 )
{
if ( V_10 -> V_11 )
F_30 ( V_55 , V_10 -> V_11 ) ;
else
F_30 ( V_55 , L_1 ) ;
if ( F_31 ( V_10 ) ) {
if ( V_10 -> V_20 . V_56 != 0 )
F_32 ( V_55 , L_2 , V_10 -> V_20 . V_56 ) ;
else
F_30 ( V_55 , L_3 ) ;
}
}
static int F_33 ( const void * V_5 , void * V_36 )
{
struct V_57 * V_58 = V_36 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
int V_59 ;
F_34 ( L_4 ,
V_4 -> type -> V_60 , V_4 -> V_61 , V_58 -> V_62 , V_58 -> V_63 ) ;
if ( V_58 -> V_62 >= V_58 -> V_63 )
return 1 ;
V_59 = F_35 ( V_4 -> V_61 , V_58 -> V_64 ) ;
if ( V_59 < 0 )
return V_59 ;
V_58 -> V_64 ++ ;
V_58 -> V_62 += sizeof( V_4 -> V_61 ) ;
return 0 ;
}
static long F_36 ( const struct V_4 * V_10 ,
char T_3 * V_64 , T_4 V_65 )
{
struct V_57 V_58 ;
unsigned long V_66 ;
int V_59 ;
F_34 ( L_5 , F_37 ( V_10 ) , V_65 ) ;
if ( V_65 & ( sizeof( V_67 ) - 1 ) )
return - V_19 ;
V_66 = V_10 -> V_20 . V_56 ;
if ( V_66 == 0 )
return 0 ;
V_58 . V_63 = V_66 * sizeof( V_67 ) ;
if ( ! V_64 || ! V_65 )
return V_58 . V_63 ;
if ( V_65 > V_58 . V_63 )
V_58 . V_63 = V_65 ;
V_58 . V_64 = ( V_67 T_3 * ) V_64 ;
V_58 . V_62 = 0 ;
V_59 = F_38 ( & V_10 -> V_20 , F_33 , & V_58 ) ;
if ( V_59 < 0 ) {
F_39 ( L_6 , V_59 ) ;
return V_59 ;
}
F_39 ( L_7 , V_58 . V_62 ) ;
return V_58 . V_62 ;
}
struct V_4 * F_40 ( const char * V_11 , T_5 V_68 , T_6 V_69 ,
const struct V_70 * V_70 , T_7 V_71 ,
unsigned long V_72 ,
struct V_51 * V_50 ,
struct V_4 * V_73 )
{
struct V_4 * V_10 ;
int V_59 ;
V_10 = F_41 ( & V_6 , V_11 ,
V_68 , V_69 , V_70 , V_71 , V_72 , V_50 ) ;
if ( ! F_42 ( V_10 ) ) {
V_59 = F_43 ( V_10 , NULL , 0 , V_73 , NULL ) ;
if ( V_59 < 0 ) {
F_23 ( V_10 ) ;
V_10 = F_44 ( V_59 ) ;
}
}
return V_10 ;
}
int F_45 ( struct V_4 * V_10 ,
const struct V_74 * type ,
const union V_75 * V_76 ,
struct V_4 * V_77 )
{
return - V_78 ;
}
bool F_46 ( const struct V_4 * V_4 ,
const struct V_79 * V_80 )
{
return strcmp ( V_4 -> V_11 , V_80 -> V_81 ) == 0 ;
}
static int F_47 ( const void * V_5 , void * V_82 )
{
struct V_83 * V_58 = V_82 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_84 = V_4 -> V_72 ;
F_34 ( L_8 , V_4 -> V_61 ) ;
if ( V_4 -> type != V_58 -> V_25 . type ) {
F_39 ( L_9 ) ;
return 0 ;
}
if ( V_58 -> V_72 & V_85 ) {
if ( V_84 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) ) {
V_58 -> V_88 = F_44 ( - V_89 ) ;
F_39 ( L_10 , V_58 -> V_90 ) ;
goto V_91;
}
if ( V_4 -> V_92 && V_58 -> V_93 . V_94 >= V_4 -> V_92 ) {
if ( ! ( V_58 -> V_72 & V_95 ) )
V_58 -> V_88 = F_44 ( - V_96 ) ;
F_39 ( L_11 , V_58 -> V_90 ) ;
goto V_91;
}
}
if ( ! V_58 -> V_80 . V_97 ( V_4 , & V_58 -> V_80 ) ) {
F_39 ( L_12 ) ;
return 0 ;
}
if ( ! ( V_58 -> V_72 & V_98 ) &&
F_48 ( F_49 ( V_4 , V_58 -> V_99 ) ,
V_58 -> V_70 , V_100 ) < 0 ) {
V_58 -> V_88 = F_44 ( - V_101 ) ;
F_39 ( L_13 , V_58 -> V_90 ) ;
goto V_91;
}
if ( V_58 -> V_72 & V_85 ) {
if ( V_84 & ( 1 << V_102 ) ) {
F_50 () ;
V_58 -> V_88 = F_44 ( V_4 -> V_103 ) ;
F_39 ( L_14 , V_58 -> V_90 ) ;
goto V_91;
}
}
V_58 -> V_88 = F_49 ( V_4 , V_58 -> V_99 ) ;
F_39 ( L_15 ) ;
return 1 ;
V_91:
return V_58 -> V_90 ;
}
static int F_51 ( struct V_4 * V_10 , struct V_83 * V_58 )
{
if ( V_58 -> V_80 . V_104 == V_105 ) {
const void * V_5 ;
V_5 = F_52 ( & V_10 -> V_20 ,
& V_53 ,
& V_58 -> V_25 ) ;
return V_5 ? V_58 -> V_106 ( V_5 , V_58 ) : 0 ;
}
return F_38 ( & V_10 -> V_20 , V_58 -> V_106 , V_58 ) ;
}
static bool F_53 ( struct V_4 * V_10 ,
struct V_83 * V_58 )
{
struct {
struct V_4 * V_10 ;
struct V_107 * V_108 ;
int V_109 ;
} V_110 [ V_111 ] ;
struct V_112 * V_113 ;
struct V_107 * V_108 ;
struct V_1 * V_114 ;
struct V_4 * V_4 ;
int V_115 = 0 , V_109 ;
F_34 ( L_16 ,
V_10 -> V_61 ,
V_58 -> V_25 . type -> V_60 ,
V_58 -> V_25 . V_11 ) ;
#define F_54 (KEYRING_SEARCH_NO_STATE_CHECK | KEYRING_SEARCH_DO_STATE_CHECK)
F_55 ( ( V_58 -> V_72 & F_54 ) == 0 ||
( V_58 -> V_72 & F_54 ) == F_54 ) ;
if ( V_58 -> V_25 . V_11 )
V_58 -> V_25 . V_34 = strlen ( V_58 -> V_25 . V_11 ) ;
if ( V_58 -> V_80 . V_104 == V_116 ||
F_19 ( V_10 , & V_58 -> V_25 ) ) {
V_58 -> V_90 = 2 ;
switch ( V_58 -> V_106 ( F_4 ( V_10 ) , V_58 ) ) {
case 1 :
goto V_117;
case 2 :
return false ;
default:
break;
}
}
V_58 -> V_90 = 0 ;
V_118:
F_56 ( L_17 , V_10 -> V_61 ) ;
if ( V_10 -> V_72 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) )
goto V_119;
if ( F_51 ( V_10 , V_58 ) )
goto V_117;
V_114 = F_57 ( V_10 -> V_20 . V_120 ) ;
if ( ! V_114 )
goto V_119;
if ( F_58 ( V_114 ) ) {
V_113 = F_59 ( V_114 ) ;
F_60 () ;
if ( ( V_113 -> V_25 [ 0 ] & V_29 ) != 0 )
goto V_119;
V_114 = F_57 ( V_113 -> V_121 ) ;
V_108 = F_61 ( V_114 ) ;
goto V_122;
}
V_108 = F_61 ( V_114 ) ;
F_60 () ;
V_114 = V_108 -> V_123 [ 0 ] ;
if ( ! F_62 ( V_114 ) )
goto V_122;
V_124:
F_56 ( L_18 ) ;
if ( F_58 ( V_114 ) ) {
V_113 = F_59 ( V_114 ) ;
F_60 () ;
V_114 = F_57 ( V_113 -> V_121 ) ;
F_55 ( ! F_63 ( V_114 ) ) ;
}
V_108 = F_61 ( V_114 ) ;
V_122:
F_56 ( L_19 ) ;
F_60 () ;
V_109 = 0 ;
V_125:
for (; V_109 < V_126 ; V_109 ++ ) {
V_114 = F_57 ( V_108 -> V_123 [ V_109 ] ) ;
if ( F_62 ( V_114 ) && V_108 -> V_127 )
goto V_124;
if ( ! F_1 ( V_114 ) )
continue;
V_4 = F_2 ( V_114 ) ;
if ( V_115 >= V_111 ) {
if ( V_58 -> V_72 & V_128 ) {
V_58 -> V_88 = F_44 ( - V_129 ) ;
return false ;
}
goto V_119;
}
if ( ! ( V_58 -> V_72 & V_98 ) &&
F_48 ( F_49 ( V_4 , V_58 -> V_99 ) ,
V_58 -> V_70 , V_100 ) < 0 )
continue;
V_110 [ V_115 ] . V_10 = V_10 ;
V_110 [ V_115 ] . V_108 = V_108 ;
V_110 [ V_115 ] . V_109 = V_109 ;
V_115 ++ ;
V_10 = V_4 ;
goto V_118;
}
V_114 = F_57 ( V_108 -> V_127 ) ;
V_109 = V_108 -> V_130 ;
if ( V_114 && F_58 ( V_114 ) ) {
V_113 = F_59 ( V_114 ) ;
F_60 () ;
V_114 = F_57 ( V_113 -> V_127 ) ;
V_109 = V_113 -> V_130 ;
}
if ( ! V_114 )
goto V_119;
V_108 = F_61 ( V_114 ) ;
F_60 () ;
V_109 ++ ;
if ( V_108 -> V_127 ) {
F_56 ( L_20 , V_109 ) ;
goto V_125;
}
V_119:
F_56 ( L_21 , V_115 ) ;
if ( V_115 <= 0 ) {
F_39 ( L_22 ) ;
return false ;
}
V_115 -- ;
V_10 = V_110 [ V_115 ] . V_10 ;
V_108 = V_110 [ V_115 ] . V_108 ;
V_109 = V_110 [ V_115 ] . V_109 + 1 ;
F_56 ( L_23 , V_10 -> V_61 , V_109 ) ;
goto V_125;
V_117:
V_4 = F_64 ( V_58 -> V_88 ) ;
F_65 ( V_4 ) ;
if ( ! ( V_58 -> V_72 & V_131 ) ) {
V_4 -> V_132 = V_58 -> V_93 . V_94 ;
V_10 -> V_132 = V_58 -> V_93 . V_94 ;
while ( V_115 > 0 )
V_110 [ -- V_115 ] . V_10 -> V_132 = V_58 -> V_93 . V_94 ;
}
F_39 ( L_24 ) ;
return true ;
}
T_8 F_66 ( T_8 V_133 ,
struct V_83 * V_58 )
{
struct V_4 * V_10 ;
long V_134 ;
V_58 -> V_106 = F_47 ;
V_58 -> V_99 = F_67 ( V_133 ) ;
V_58 -> V_88 = F_44 ( - V_135 ) ;
V_10 = F_64 ( V_133 ) ;
F_65 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_44 ( - V_136 ) ;
if ( ! ( V_58 -> V_72 & V_98 ) ) {
V_134 = F_48 ( V_133 , V_58 -> V_70 , V_100 ) ;
if ( V_134 < 0 )
return F_44 ( V_134 ) ;
}
F_68 () ;
V_58 -> V_93 = F_69 () ;
if ( F_53 ( V_10 , V_58 ) )
F_70 ( F_64 ( V_58 -> V_88 ) ) ;
F_71 () ;
return V_58 -> V_88 ;
}
T_8 F_72 ( T_8 V_10 ,
struct V_74 * type ,
const char * V_11 )
{
struct V_83 V_58 = {
. V_25 . type = type ,
. V_25 . V_11 = V_11 ,
. V_70 = F_73 () ,
. V_80 . V_97 = F_46 ,
. V_80 . V_81 = V_11 ,
. V_80 . V_104 = V_105 ,
. V_72 = V_85 ,
} ;
T_8 V_4 ;
int V_59 ;
if ( type -> V_137 ) {
V_59 = type -> V_137 ( & V_58 . V_80 ) ;
if ( V_59 < 0 )
return F_44 ( V_59 ) ;
}
V_4 = F_66 ( V_10 , & V_58 ) ;
if ( type -> V_138 )
type -> V_138 ( & V_58 . V_80 ) ;
return V_4 ;
}
static struct V_51 * F_74 (
T_9 V_139 )
{
struct V_51 * V_52 =
F_75 ( sizeof( struct V_51 ) , V_140 ) ;
if ( ! V_52 )
return F_44 ( - V_141 ) ;
V_52 -> V_139 = V_139 ;
return V_52 ;
}
static bool F_76 ( const struct V_4 * V_142 ,
struct V_51 * V_52 )
{
while ( V_52 && V_52 -> V_4 &&
V_52 -> V_4 -> type == & V_6 ) {
if ( V_52 -> V_4 == V_142 )
return true ;
V_52 = V_52 -> V_4 -> V_50 ;
}
return false ;
}
int F_77 ( T_8 V_133 , const char * type ,
const char * V_143 )
{
struct V_4 * V_10 ;
struct V_74 * V_144 = NULL ;
struct V_51 * V_50 ;
int V_59 = 0 ;
V_10 = F_64 ( V_133 ) ;
F_65 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return - V_136 ;
if ( ! type ) {
V_50 = F_74 ( F_45 ) ;
} else {
V_144 = F_78 ( type ) ;
if ( F_42 ( V_144 ) )
return F_79 ( V_144 ) ;
if ( ! V_144 -> V_145 ) {
V_59 = - V_146 ;
goto error;
}
V_50 = V_144 -> V_145 ( V_143 ) ;
}
if ( F_42 ( V_50 ) ) {
V_59 = F_79 ( V_50 ) ;
goto error;
}
F_80 ( & V_10 -> V_147 ) ;
F_80 ( & V_148 ) ;
if ( V_10 -> V_50 )
V_59 = - V_149 ;
else if ( F_76 ( V_10 , V_50 ) )
V_59 = - V_150 ;
else
V_10 -> V_50 = V_50 ;
F_81 ( & V_148 ) ;
F_81 ( & V_10 -> V_147 ) ;
if ( V_59 < 0 ) {
F_23 ( V_50 -> V_4 ) ;
F_27 ( V_50 ) ;
}
error:
if ( V_144 )
F_82 ( V_144 ) ;
return V_59 ;
}
T_8 F_83 ( T_8 V_133 ,
const struct V_24 * V_25 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_64 ( V_133 ) ;
F_34 ( L_16 ,
V_10 -> V_61 , V_25 -> type -> V_60 , V_25 -> V_11 ) ;
V_5 = F_52 ( & V_10 -> V_20 , & V_53 ,
V_25 ) ;
if ( V_5 )
goto V_117;
F_39 ( L_25 ) ;
return NULL ;
V_117:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_72 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) ) {
F_39 ( L_26 ) ;
return NULL ;
}
F_70 ( V_4 ) ;
F_39 ( L_27 , V_4 -> V_61 ) ;
return F_49 ( V_4 , F_67 ( V_133 ) ) ;
}
struct V_4 * F_84 ( const char * V_60 , bool V_151 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_60 )
return F_44 ( - V_19 ) ;
V_8 = F_5 ( V_60 ) ;
F_85 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_86 (keyring,
&keyring_name_hash[bucket],
name_link
) {
if ( ! F_87 ( F_88 () , V_10 -> V_152 -> V_68 ) )
continue;
if ( F_89 ( V_87 , & V_10 -> V_72 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_60 ) != 0 )
continue;
if ( ! V_151 &&
F_90 ( F_49 ( V_10 , 0 ) ,
V_100 ) < 0 )
continue;
if ( ! F_91 ( & V_10 -> V_153 ) )
continue;
V_10 -> V_132 = F_69 () . V_94 ;
goto V_154;
}
}
V_10 = F_44 ( - V_155 ) ;
V_154:
F_92 ( & V_12 ) ;
return V_10 ;
}
static int F_93 ( const void * V_5 ,
void * V_82 )
{
struct V_83 * V_58 = V_82 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_34 ( L_8 , V_4 -> V_61 ) ;
if ( V_4 != V_58 -> V_80 . V_81 )
return 0 ;
V_58 -> V_88 = F_44 ( - V_150 ) ;
return 1 ;
}
static int F_94 ( struct V_4 * V_156 , struct V_4 * V_157 )
{
struct V_83 V_58 = {
. V_25 = V_156 -> V_25 ,
. V_80 . V_81 = V_156 ,
. V_80 . V_104 = V_105 ,
. V_106 = F_93 ,
. V_72 = ( V_158 |
V_131 |
V_98 |
V_128 ) ,
} ;
F_68 () ;
F_53 ( V_157 , & V_58 ) ;
F_71 () ;
return F_79 ( V_58 . V_88 ) == - V_135 ? 0 : F_79 ( V_58 . V_88 ) ;
}
int F_95 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_159 * * V_160 )
__acquires( &keyring->sem
int F_96 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_94 ( V_10 , V_4 ) ;
return 0 ;
}
void F_97 ( struct V_4 * V_4 , struct V_159 * * V_160 )
{
F_70 ( V_4 ) ;
F_98 ( * V_160 , F_4 ( V_4 ) ) ;
F_99 ( * V_160 ) ;
* V_160 = NULL ;
}
void F_100 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_159 * V_161 )
__releases( &keyring->sem
static int F_101 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( ! V_10 -> V_50 || ! V_10 -> V_50 -> V_139 )
return 0 ;
return V_10 -> V_50 -> V_139 ( V_10 , V_4 -> type , & V_4 -> V_76 ,
V_10 -> V_50 -> V_4 ) ;
}
int F_102 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_159 * V_161 ;
int V_59 ;
F_34 ( L_28 , V_10 -> V_61 , F_103 ( & V_10 -> V_153 ) ) ;
F_65 ( V_10 ) ;
F_65 ( V_4 ) ;
V_59 = F_95 ( V_10 , & V_4 -> V_25 , & V_161 ) ;
if ( V_59 == 0 ) {
F_56 ( L_29 , V_10 -> V_61 , F_103 ( & V_10 -> V_153 ) ) ;
V_59 = F_101 ( V_10 , V_4 ) ;
if ( V_59 == 0 )
V_59 = F_96 ( V_10 , V_4 ) ;
if ( V_59 == 0 )
F_97 ( V_4 , & V_161 ) ;
F_100 ( V_10 , & V_4 -> V_25 , V_161 ) ;
}
F_39 ( L_30 , V_59 , V_10 -> V_61 , F_103 ( & V_10 -> V_153 ) ) ;
return V_59 ;
}
int F_104 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_159 * V_161 ;
int V_59 ;
F_65 ( V_10 ) ;
F_65 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_136 ;
F_80 ( & V_10 -> V_147 ) ;
V_161 = F_105 ( & V_10 -> V_20 , & V_53 ,
& V_4 -> V_25 ) ;
if ( F_42 ( V_161 ) ) {
V_59 = F_79 ( V_161 ) ;
goto error;
}
V_59 = - V_146 ;
if ( V_161 == NULL )
goto error;
F_99 ( V_161 ) ;
F_106 ( V_10 , V_10 -> V_18 - V_162 ) ;
V_59 = 0 ;
error:
F_81 ( & V_10 -> V_147 ) ;
return V_59 ;
}
int F_107 ( struct V_4 * V_10 )
{
struct V_159 * V_161 ;
int V_59 ;
if ( V_10 -> type != & V_6 )
return - V_136 ;
F_80 ( & V_10 -> V_147 ) ;
V_161 = F_108 ( & V_10 -> V_20 , & V_53 ) ;
if ( F_42 ( V_161 ) ) {
V_59 = F_79 ( V_161 ) ;
} else {
if ( V_161 )
F_99 ( V_161 ) ;
F_106 ( V_10 , 0 ) ;
V_59 = 0 ;
}
F_81 ( & V_10 -> V_147 ) ;
return V_59 ;
}
static void F_109 ( struct V_4 * V_10 )
{
struct V_159 * V_161 ;
V_161 = F_108 ( & V_10 -> V_20 , & V_53 ) ;
if ( ! F_42 ( V_161 ) ) {
if ( V_161 )
F_99 ( V_161 ) ;
F_106 ( V_10 , 0 ) ;
}
}
static bool F_110 ( void * V_5 , void * V_82 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_10 * V_163 = V_82 ;
if ( F_111 ( V_4 , * V_163 ) )
return false ;
F_112 ( V_4 ) ;
return true ;
}
static int F_113 ( const void * V_5 , void * V_82 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_10 * V_163 = V_82 ;
F_65 ( V_4 ) ;
return F_111 ( V_4 , * V_163 ) ;
}
void F_114 ( struct V_4 * V_10 , T_10 V_163 )
{
int V_88 ;
F_34 ( L_31 , V_10 -> V_61 , V_10 -> V_11 ? : L_32 ) ;
if ( V_10 -> V_72 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) )
goto V_164;
F_68 () ;
V_88 = F_38 ( & V_10 -> V_20 ,
F_113 , & V_163 ) ;
F_71 () ;
if ( V_88 == true )
goto V_165;
V_164:
F_39 ( L_33 ) ;
return;
V_165:
F_80 ( & V_10 -> V_147 ) ;
F_115 ( & V_10 -> V_20 , & V_53 ,
F_110 , & V_163 ) ;
F_81 ( & V_10 -> V_147 ) ;
F_39 ( L_34 ) ;
}
void F_116 ( struct V_4 * V_10 , struct V_74 * V_166 )
{
struct V_51 * V_52 ;
F_34 ( L_31 , V_10 -> V_61 , V_10 -> V_11 ? : L_32 ) ;
if ( ! V_166 || ! V_10 -> V_50 ||
V_10 -> V_50 -> V_167 != V_166 ) {
F_39 ( L_35 ) ;
return;
}
F_80 ( & V_10 -> V_147 ) ;
V_52 = V_10 -> V_50 ;
V_52 -> V_139 = F_45 ;
F_23 ( V_52 -> V_4 ) ;
V_52 -> V_4 = NULL ;
V_52 -> V_167 = NULL ;
F_81 ( & V_10 -> V_147 ) ;
F_39 ( L_36 ) ;
}
