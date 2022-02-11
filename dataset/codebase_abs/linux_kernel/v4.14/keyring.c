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
char T_3 * V_64 , T_4 V_63 )
{
struct V_57 V_58 ;
long V_59 ;
F_34 ( L_5 , F_37 ( V_10 ) , V_63 ) ;
if ( V_63 & ( sizeof( V_65 ) - 1 ) )
return - V_19 ;
if ( V_64 && V_63 ) {
V_58 . V_64 = ( V_65 T_3 * ) V_64 ;
V_58 . V_63 = V_63 ;
V_58 . V_62 = 0 ;
V_59 = F_38 ( & V_10 -> V_20 ,
F_33 , & V_58 ) ;
if ( V_59 < 0 ) {
F_39 ( L_6 , V_59 ) ;
return V_59 ;
}
}
V_59 = V_10 -> V_20 . V_56 * sizeof( V_65 ) ;
if ( V_59 <= V_63 )
F_39 ( L_7 , V_59 ) ;
else
F_39 ( L_8 , V_59 ) ;
return V_59 ;
}
struct V_4 * F_40 ( const char * V_11 , T_5 V_66 , T_6 V_67 ,
const struct V_68 * V_68 , T_7 V_69 ,
unsigned long V_70 ,
struct V_51 * V_50 ,
struct V_4 * V_71 )
{
struct V_4 * V_10 ;
int V_59 ;
V_10 = F_41 ( & V_6 , V_11 ,
V_66 , V_67 , V_68 , V_69 , V_70 , V_50 ) ;
if ( ! F_42 ( V_10 ) ) {
V_59 = F_43 ( V_10 , NULL , 0 , V_71 , NULL ) ;
if ( V_59 < 0 ) {
F_23 ( V_10 ) ;
V_10 = F_44 ( V_59 ) ;
}
}
return V_10 ;
}
int F_45 ( struct V_4 * V_10 ,
const struct V_72 * type ,
const union V_73 * V_74 ,
struct V_4 * V_75 )
{
return - V_76 ;
}
bool F_46 ( const struct V_4 * V_4 ,
const struct V_77 * V_78 )
{
return strcmp ( V_4 -> V_11 , V_78 -> V_79 ) == 0 ;
}
static int F_47 ( const void * V_5 , void * V_80 )
{
struct V_81 * V_58 = V_80 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_82 = F_48 ( V_4 -> V_70 ) ;
short V_83 = F_48 ( V_4 -> V_83 ) ;
F_34 ( L_9 , V_4 -> V_61 ) ;
if ( V_4 -> type != V_58 -> V_25 . type ) {
F_39 ( L_10 ) ;
return 0 ;
}
if ( V_58 -> V_70 & V_84 ) {
T_8 V_85 = F_48 ( V_4 -> V_85 ) ;
if ( V_82 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) ) {
V_58 -> V_88 = F_44 ( - V_89 ) ;
F_39 ( L_11 , V_58 -> V_90 ) ;
goto V_91;
}
if ( V_85 && V_58 -> V_92 . V_93 >= V_85 ) {
if ( ! ( V_58 -> V_70 & V_94 ) )
V_58 -> V_88 = F_44 ( - V_95 ) ;
F_39 ( L_12 , V_58 -> V_90 ) ;
goto V_91;
}
}
if ( ! V_58 -> V_78 . V_96 ( V_4 , & V_58 -> V_78 ) ) {
F_39 ( L_13 ) ;
return 0 ;
}
if ( ! ( V_58 -> V_70 & V_97 ) &&
F_49 ( F_50 ( V_4 , V_58 -> V_98 ) ,
V_58 -> V_68 , V_99 ) < 0 ) {
V_58 -> V_88 = F_44 ( - V_100 ) ;
F_39 ( L_14 , V_58 -> V_90 ) ;
goto V_91;
}
if ( V_58 -> V_70 & V_84 ) {
if ( V_83 < 0 ) {
V_58 -> V_88 = F_44 ( V_83 ) ;
F_39 ( L_15 , V_58 -> V_90 ) ;
goto V_91;
}
}
V_58 -> V_88 = F_50 ( V_4 , V_58 -> V_98 ) ;
F_39 ( L_16 ) ;
return 1 ;
V_91:
return V_58 -> V_90 ;
}
static int F_51 ( struct V_4 * V_10 , struct V_81 * V_58 )
{
if ( V_58 -> V_78 . V_101 == V_102 ) {
const void * V_5 ;
V_5 = F_52 ( & V_10 -> V_20 ,
& V_53 ,
& V_58 -> V_25 ) ;
return V_5 ? V_58 -> V_103 ( V_5 , V_58 ) : 0 ;
}
return F_38 ( & V_10 -> V_20 , V_58 -> V_103 , V_58 ) ;
}
static bool F_53 ( struct V_4 * V_10 ,
struct V_81 * V_58 )
{
struct {
struct V_4 * V_10 ;
struct V_104 * V_105 ;
int V_106 ;
} V_107 [ V_108 ] ;
struct V_109 * V_110 ;
struct V_104 * V_105 ;
struct V_1 * V_111 ;
struct V_4 * V_4 ;
int V_112 = 0 , V_106 ;
F_34 ( L_17 ,
V_10 -> V_61 ,
V_58 -> V_25 . type -> V_60 ,
V_58 -> V_25 . V_11 ) ;
#define F_54 (KEYRING_SEARCH_NO_STATE_CHECK | KEYRING_SEARCH_DO_STATE_CHECK)
F_55 ( ( V_58 -> V_70 & F_54 ) == 0 ||
( V_58 -> V_70 & F_54 ) == F_54 ) ;
if ( V_58 -> V_25 . V_11 )
V_58 -> V_25 . V_34 = strlen ( V_58 -> V_25 . V_11 ) ;
if ( V_58 -> V_78 . V_101 == V_113 ||
F_19 ( V_10 , & V_58 -> V_25 ) ) {
V_58 -> V_90 = 2 ;
switch ( V_58 -> V_103 ( F_4 ( V_10 ) , V_58 ) ) {
case 1 :
goto V_114;
case 2 :
return false ;
default:
break;
}
}
V_58 -> V_90 = 0 ;
V_115:
F_56 ( L_18 , V_10 -> V_61 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) )
goto V_116;
if ( F_51 ( V_10 , V_58 ) )
goto V_114;
V_111 = F_48 ( V_10 -> V_20 . V_117 ) ;
if ( ! V_111 )
goto V_116;
if ( F_57 ( V_111 ) ) {
V_110 = F_58 ( V_111 ) ;
F_59 () ;
if ( ( V_110 -> V_25 [ 0 ] & V_29 ) != 0 )
goto V_116;
V_111 = F_48 ( V_110 -> V_118 ) ;
V_105 = F_60 ( V_111 ) ;
goto V_119;
}
V_105 = F_60 ( V_111 ) ;
F_59 () ;
V_111 = V_105 -> V_120 [ 0 ] ;
if ( ! F_61 ( V_111 ) )
goto V_119;
V_121:
F_56 ( L_19 ) ;
if ( F_57 ( V_111 ) ) {
V_110 = F_58 ( V_111 ) ;
F_59 () ;
V_111 = F_48 ( V_110 -> V_118 ) ;
F_55 ( ! F_62 ( V_111 ) ) ;
}
V_105 = F_60 ( V_111 ) ;
V_119:
F_56 ( L_20 ) ;
F_59 () ;
V_106 = 0 ;
V_122:
for (; V_106 < V_123 ; V_106 ++ ) {
V_111 = F_48 ( V_105 -> V_120 [ V_106 ] ) ;
if ( F_61 ( V_111 ) && V_105 -> V_124 )
goto V_121;
if ( ! F_1 ( V_111 ) )
continue;
V_4 = F_2 ( V_111 ) ;
if ( V_112 >= V_108 ) {
if ( V_58 -> V_70 & V_125 ) {
V_58 -> V_88 = F_44 ( - V_126 ) ;
return false ;
}
goto V_116;
}
if ( ! ( V_58 -> V_70 & V_97 ) &&
F_49 ( F_50 ( V_4 , V_58 -> V_98 ) ,
V_58 -> V_68 , V_99 ) < 0 )
continue;
V_107 [ V_112 ] . V_10 = V_10 ;
V_107 [ V_112 ] . V_105 = V_105 ;
V_107 [ V_112 ] . V_106 = V_106 ;
V_112 ++ ;
V_10 = V_4 ;
goto V_115;
}
V_111 = F_48 ( V_105 -> V_124 ) ;
V_106 = V_105 -> V_127 ;
if ( V_111 && F_57 ( V_111 ) ) {
V_110 = F_58 ( V_111 ) ;
F_59 () ;
V_111 = F_48 ( V_110 -> V_124 ) ;
V_106 = V_110 -> V_127 ;
}
if ( ! V_111 )
goto V_116;
V_105 = F_60 ( V_111 ) ;
F_59 () ;
V_106 ++ ;
if ( V_105 -> V_124 ) {
F_56 ( L_21 , V_106 ) ;
goto V_122;
}
V_116:
F_56 ( L_22 , V_112 ) ;
if ( V_112 <= 0 ) {
F_39 ( L_23 ) ;
return false ;
}
V_112 -- ;
V_10 = V_107 [ V_112 ] . V_10 ;
V_105 = V_107 [ V_112 ] . V_105 ;
V_106 = V_107 [ V_112 ] . V_106 + 1 ;
F_56 ( L_24 , V_10 -> V_61 , V_106 ) ;
goto V_122;
V_114:
V_4 = F_63 ( V_58 -> V_88 ) ;
F_64 ( V_4 ) ;
if ( ! ( V_58 -> V_70 & V_128 ) ) {
V_4 -> V_129 = V_58 -> V_92 . V_93 ;
V_10 -> V_129 = V_58 -> V_92 . V_93 ;
while ( V_112 > 0 )
V_107 [ -- V_112 ] . V_10 -> V_129 = V_58 -> V_92 . V_93 ;
}
F_39 ( L_25 ) ;
return true ;
}
T_9 F_65 ( T_9 V_130 ,
struct V_81 * V_58 )
{
struct V_4 * V_10 ;
long V_131 ;
V_58 -> V_103 = F_47 ;
V_58 -> V_98 = F_66 ( V_130 ) ;
V_58 -> V_88 = F_44 ( - V_132 ) ;
V_10 = F_63 ( V_130 ) ;
F_64 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_44 ( - V_133 ) ;
if ( ! ( V_58 -> V_70 & V_97 ) ) {
V_131 = F_49 ( V_130 , V_58 -> V_68 , V_99 ) ;
if ( V_131 < 0 )
return F_44 ( V_131 ) ;
}
F_67 () ;
V_58 -> V_92 = F_68 () ;
if ( F_53 ( V_10 , V_58 ) )
F_69 ( F_63 ( V_58 -> V_88 ) ) ;
F_70 () ;
return V_58 -> V_88 ;
}
T_9 F_71 ( T_9 V_10 ,
struct V_72 * type ,
const char * V_11 )
{
struct V_81 V_58 = {
. V_25 . type = type ,
. V_25 . V_11 = V_11 ,
. V_68 = F_72 () ,
. V_78 . V_96 = F_46 ,
. V_78 . V_79 = V_11 ,
. V_78 . V_101 = V_102 ,
. V_70 = V_84 ,
} ;
T_9 V_4 ;
int V_59 ;
if ( type -> V_134 ) {
V_59 = type -> V_134 ( & V_58 . V_78 ) ;
if ( V_59 < 0 )
return F_44 ( V_59 ) ;
}
V_4 = F_65 ( V_10 , & V_58 ) ;
if ( type -> V_135 )
type -> V_135 ( & V_58 . V_78 ) ;
return V_4 ;
}
static struct V_51 * F_73 (
T_10 V_136 )
{
struct V_51 * V_52 =
F_74 ( sizeof( struct V_51 ) , V_137 ) ;
if ( ! V_52 )
return F_44 ( - V_138 ) ;
V_52 -> V_136 = V_136 ;
return V_52 ;
}
static bool F_75 ( const struct V_4 * V_139 ,
struct V_51 * V_52 )
{
while ( V_52 && V_52 -> V_4 &&
V_52 -> V_4 -> type == & V_6 ) {
if ( V_52 -> V_4 == V_139 )
return true ;
V_52 = V_52 -> V_4 -> V_50 ;
}
return false ;
}
int F_76 ( T_9 V_130 , const char * type ,
const char * V_140 )
{
struct V_4 * V_10 ;
struct V_72 * V_141 = NULL ;
struct V_51 * V_50 ;
int V_59 = 0 ;
V_10 = F_63 ( V_130 ) ;
F_64 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return - V_133 ;
if ( ! type ) {
V_50 = F_73 ( F_45 ) ;
} else {
V_141 = F_77 ( type ) ;
if ( F_42 ( V_141 ) )
return F_78 ( V_141 ) ;
if ( ! V_141 -> V_142 ) {
V_59 = - V_143 ;
goto error;
}
V_50 = V_141 -> V_142 ( V_140 ) ;
}
if ( F_42 ( V_50 ) ) {
V_59 = F_78 ( V_50 ) ;
goto error;
}
F_79 ( & V_10 -> V_144 ) ;
F_79 ( & V_145 ) ;
if ( V_10 -> V_50 )
V_59 = - V_146 ;
else if ( F_75 ( V_10 , V_50 ) )
V_59 = - V_147 ;
else
V_10 -> V_50 = V_50 ;
F_80 ( & V_145 ) ;
F_80 ( & V_10 -> V_144 ) ;
if ( V_59 < 0 ) {
F_23 ( V_50 -> V_4 ) ;
F_27 ( V_50 ) ;
}
error:
if ( V_141 )
F_81 ( V_141 ) ;
return V_59 ;
}
T_9 F_82 ( T_9 V_130 ,
const struct V_24 * V_25 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_63 ( V_130 ) ;
F_34 ( L_17 ,
V_10 -> V_61 , V_25 -> type -> V_60 , V_25 -> V_11 ) ;
V_5 = F_52 ( & V_10 -> V_20 , & V_53 ,
V_25 ) ;
if ( V_5 )
goto V_114;
F_39 ( L_26 ) ;
return NULL ;
V_114:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_70 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) ) {
F_39 ( L_27 ) ;
return NULL ;
}
F_69 ( V_4 ) ;
F_39 ( L_28 , V_4 -> V_61 ) ;
return F_50 ( V_4 , F_66 ( V_130 ) ) ;
}
struct V_4 * F_83 ( const char * V_60 , bool V_148 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_60 )
return F_44 ( - V_19 ) ;
V_8 = F_5 ( V_60 ) ;
F_84 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_85 (keyring,
&keyring_name_hash[bucket],
name_link
) {
if ( ! F_86 ( F_87 () , V_10 -> V_149 -> V_66 ) )
continue;
if ( F_88 ( V_87 , & V_10 -> V_70 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_60 ) != 0 )
continue;
if ( V_148 ) {
if ( ! F_88 ( V_150 ,
& V_10 -> V_70 ) )
continue;
} else {
if ( F_89 ( F_50 ( V_10 , 0 ) ,
V_99 ) < 0 )
continue;
}
if ( ! F_90 ( & V_10 -> V_151 ) )
continue;
V_10 -> V_129 = F_68 () . V_93 ;
goto V_152;
}
}
V_10 = F_44 ( - V_153 ) ;
V_152:
F_91 ( & V_12 ) ;
return V_10 ;
}
static int F_92 ( const void * V_5 ,
void * V_80 )
{
struct V_81 * V_58 = V_80 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_34 ( L_9 , V_4 -> V_61 ) ;
if ( V_4 != V_58 -> V_78 . V_79 )
return 0 ;
V_58 -> V_88 = F_44 ( - V_147 ) ;
return 1 ;
}
static int F_93 ( struct V_4 * V_154 , struct V_4 * V_155 )
{
struct V_81 V_58 = {
. V_25 = V_154 -> V_25 ,
. V_78 . V_79 = V_154 ,
. V_78 . V_101 = V_102 ,
. V_103 = F_92 ,
. V_70 = ( V_156 |
V_128 |
V_97 |
V_125 ) ,
} ;
F_67 () ;
F_53 ( V_155 , & V_58 ) ;
F_70 () ;
return F_78 ( V_58 . V_88 ) == - V_132 ? 0 : F_78 ( V_58 . V_88 ) ;
}
int F_94 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_157 * * V_158 )
__acquires( &keyring->sem
int F_95 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_93 ( V_10 , V_4 ) ;
return 0 ;
}
void F_96 ( struct V_4 * V_4 , struct V_157 * * V_158 )
{
F_69 ( V_4 ) ;
F_97 ( * V_158 , F_4 ( V_4 ) ) ;
F_98 ( * V_158 ) ;
* V_158 = NULL ;
}
void F_99 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_157 * V_159 )
__releases( &keyring->sem
static int F_100 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( ! V_10 -> V_50 || ! V_10 -> V_50 -> V_136 )
return 0 ;
return V_10 -> V_50 -> V_136 ( V_10 , V_4 -> type , & V_4 -> V_74 ,
V_10 -> V_50 -> V_4 ) ;
}
int F_101 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_157 * V_159 ;
int V_59 ;
F_34 ( L_29 , V_10 -> V_61 , F_102 ( & V_10 -> V_151 ) ) ;
F_64 ( V_10 ) ;
F_64 ( V_4 ) ;
V_59 = F_94 ( V_10 , & V_4 -> V_25 , & V_159 ) ;
if ( V_59 == 0 ) {
F_56 ( L_30 , V_10 -> V_61 , F_102 ( & V_10 -> V_151 ) ) ;
V_59 = F_100 ( V_10 , V_4 ) ;
if ( V_59 == 0 )
V_59 = F_95 ( V_10 , V_4 ) ;
if ( V_59 == 0 )
F_96 ( V_4 , & V_159 ) ;
F_99 ( V_10 , & V_4 -> V_25 , V_159 ) ;
}
F_39 ( L_31 , V_59 , V_10 -> V_61 , F_102 ( & V_10 -> V_151 ) ) ;
return V_59 ;
}
int F_103 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_157 * V_159 ;
int V_59 ;
F_64 ( V_10 ) ;
F_64 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_133 ;
F_79 ( & V_10 -> V_144 ) ;
V_159 = F_104 ( & V_10 -> V_20 , & V_53 ,
& V_4 -> V_25 ) ;
if ( F_42 ( V_159 ) ) {
V_59 = F_78 ( V_159 ) ;
goto error;
}
V_59 = - V_143 ;
if ( V_159 == NULL )
goto error;
F_98 ( V_159 ) ;
F_105 ( V_10 , V_10 -> V_18 - V_160 ) ;
V_59 = 0 ;
error:
F_80 ( & V_10 -> V_144 ) ;
return V_59 ;
}
int F_106 ( struct V_4 * V_10 )
{
struct V_157 * V_159 ;
int V_59 ;
if ( V_10 -> type != & V_6 )
return - V_133 ;
F_79 ( & V_10 -> V_144 ) ;
V_159 = F_107 ( & V_10 -> V_20 , & V_53 ) ;
if ( F_42 ( V_159 ) ) {
V_59 = F_78 ( V_159 ) ;
} else {
if ( V_159 )
F_98 ( V_159 ) ;
F_105 ( V_10 , 0 ) ;
V_59 = 0 ;
}
F_80 ( & V_10 -> V_144 ) ;
return V_59 ;
}
static void F_108 ( struct V_4 * V_10 )
{
struct V_157 * V_159 ;
V_159 = F_107 ( & V_10 -> V_20 , & V_53 ) ;
if ( ! F_42 ( V_159 ) ) {
if ( V_159 )
F_98 ( V_159 ) ;
F_105 ( V_10 , 0 ) ;
}
}
static bool F_109 ( void * V_5 , void * V_80 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_8 * V_161 = V_80 ;
if ( F_110 ( V_4 , * V_161 ) )
return false ;
F_111 ( V_4 ) ;
return true ;
}
static int F_112 ( const void * V_5 , void * V_80 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_8 * V_161 = V_80 ;
F_64 ( V_4 ) ;
return F_110 ( V_4 , * V_161 ) ;
}
void F_113 ( struct V_4 * V_10 , T_8 V_161 )
{
int V_88 ;
F_34 ( L_32 , V_10 -> V_61 , V_10 -> V_11 ? : L_33 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_86 ) |
( 1 << V_87 ) ) )
goto V_162;
F_67 () ;
V_88 = F_38 ( & V_10 -> V_20 ,
F_112 , & V_161 ) ;
F_70 () ;
if ( V_88 == true )
goto V_163;
V_162:
F_39 ( L_34 ) ;
return;
V_163:
F_79 ( & V_10 -> V_144 ) ;
F_114 ( & V_10 -> V_20 , & V_53 ,
F_109 , & V_161 ) ;
F_80 ( & V_10 -> V_144 ) ;
F_39 ( L_35 ) ;
}
void F_115 ( struct V_4 * V_10 , struct V_72 * V_164 )
{
struct V_51 * V_52 ;
F_34 ( L_32 , V_10 -> V_61 , V_10 -> V_11 ? : L_33 ) ;
if ( ! V_164 || ! V_10 -> V_50 ||
V_10 -> V_50 -> V_165 != V_164 ) {
F_39 ( L_36 ) ;
return;
}
F_79 ( & V_10 -> V_144 ) ;
V_52 = V_10 -> V_50 ;
V_52 -> V_136 = F_45 ;
F_23 ( V_52 -> V_4 ) ;
V_52 -> V_4 = NULL ;
V_52 -> V_165 = NULL ;
F_80 ( & V_10 -> V_144 ) ;
F_39 ( L_37 ) ;
}
