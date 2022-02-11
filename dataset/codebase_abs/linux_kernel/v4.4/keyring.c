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
F_27 ( & V_10 -> V_20 , & V_50 ) ;
}
static void F_28 ( const struct V_4 * V_10 , struct V_51 * V_52 )
{
if ( V_10 -> V_11 )
F_29 ( V_52 , V_10 -> V_11 ) ;
else
F_29 ( V_52 , L_1 ) ;
if ( F_30 ( V_10 ) ) {
if ( V_10 -> V_20 . V_53 != 0 )
F_31 ( V_52 , L_2 , V_10 -> V_20 . V_53 ) ;
else
F_29 ( V_52 , L_3 ) ;
}
}
static int F_32 ( const void * V_5 , void * V_36 )
{
struct V_54 * V_55 = V_36 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
int V_56 ;
F_33 ( L_4 ,
V_4 -> type -> V_57 , V_4 -> V_58 , V_55 -> V_59 , V_55 -> V_60 ) ;
if ( V_55 -> V_59 >= V_55 -> V_60 )
return 1 ;
V_56 = F_34 ( V_4 -> V_58 , V_55 -> V_61 ) ;
if ( V_56 < 0 )
return V_56 ;
V_55 -> V_61 ++ ;
V_55 -> V_59 += sizeof( V_4 -> V_58 ) ;
return 0 ;
}
static long F_35 ( const struct V_4 * V_10 ,
char T_3 * V_61 , T_4 V_62 )
{
struct V_54 V_55 ;
unsigned long V_63 ;
int V_56 ;
F_33 ( L_5 , F_36 ( V_10 ) , V_62 ) ;
if ( V_62 & ( sizeof( V_64 ) - 1 ) )
return - V_19 ;
V_63 = V_10 -> V_20 . V_53 ;
if ( V_63 == 0 )
return 0 ;
V_55 . V_60 = V_63 * sizeof( V_64 ) ;
if ( ! V_61 || ! V_62 )
return V_55 . V_60 ;
if ( V_62 > V_55 . V_60 )
V_55 . V_60 = V_62 ;
V_55 . V_61 = ( V_64 T_3 * ) V_61 ;
V_55 . V_59 = 0 ;
V_56 = F_37 ( & V_10 -> V_20 , F_32 , & V_55 ) ;
if ( V_56 < 0 ) {
F_38 ( L_6 , V_56 ) ;
return V_56 ;
}
F_38 ( L_7 , V_55 . V_59 ) ;
return V_55 . V_59 ;
}
struct V_4 * F_39 ( const char * V_11 , T_5 V_65 , T_6 V_66 ,
const struct V_67 * V_67 , T_7 V_68 ,
unsigned long V_69 , struct V_4 * V_70 )
{
struct V_4 * V_10 ;
int V_56 ;
V_10 = F_40 ( & V_6 , V_11 ,
V_65 , V_66 , V_67 , V_68 , V_69 ) ;
if ( ! F_41 ( V_10 ) ) {
V_56 = F_42 ( V_10 , NULL , 0 , V_70 , NULL ) ;
if ( V_56 < 0 ) {
F_23 ( V_10 ) ;
V_10 = F_43 ( V_56 ) ;
}
}
return V_10 ;
}
bool F_44 ( const struct V_4 * V_4 ,
const struct V_71 * V_72 )
{
return strcmp ( V_4 -> V_11 , V_72 -> V_73 ) == 0 ;
}
static int F_45 ( const void * V_5 , void * V_74 )
{
struct V_75 * V_55 = V_74 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_76 = V_4 -> V_69 ;
F_33 ( L_8 , V_4 -> V_58 ) ;
if ( V_4 -> type != V_55 -> V_25 . type ) {
F_38 ( L_9 ) ;
return 0 ;
}
if ( V_55 -> V_69 & V_77 ) {
if ( V_76 & ( ( 1 << V_78 ) |
( 1 << V_79 ) ) ) {
V_55 -> V_80 = F_43 ( - V_81 ) ;
F_38 ( L_10 , V_55 -> V_82 ) ;
goto V_83;
}
if ( V_4 -> V_84 && V_55 -> V_85 . V_86 >= V_4 -> V_84 ) {
if ( ! ( V_55 -> V_69 & V_87 ) )
V_55 -> V_80 = F_43 ( - V_88 ) ;
F_38 ( L_11 , V_55 -> V_82 ) ;
goto V_83;
}
}
if ( ! V_55 -> V_72 . V_89 ( V_4 , & V_55 -> V_72 ) ) {
F_38 ( L_12 ) ;
return 0 ;
}
if ( ! ( V_55 -> V_69 & V_90 ) &&
F_46 ( F_47 ( V_4 , V_55 -> V_91 ) ,
V_55 -> V_67 , V_92 ) < 0 ) {
V_55 -> V_80 = F_43 ( - V_93 ) ;
F_38 ( L_13 , V_55 -> V_82 ) ;
goto V_83;
}
if ( V_55 -> V_69 & V_77 ) {
if ( V_76 & ( 1 << V_94 ) ) {
F_48 () ;
V_55 -> V_80 = F_43 ( V_4 -> V_95 ) ;
F_38 ( L_14 , V_55 -> V_82 ) ;
goto V_83;
}
}
V_55 -> V_80 = F_47 ( V_4 , V_55 -> V_91 ) ;
F_38 ( L_15 ) ;
return 1 ;
V_83:
return V_55 -> V_82 ;
}
static int F_49 ( struct V_4 * V_10 , struct V_75 * V_55 )
{
if ( V_55 -> V_72 . V_96 == V_97 ) {
const void * V_5 ;
V_5 = F_50 ( & V_10 -> V_20 ,
& V_50 ,
& V_55 -> V_25 ) ;
return V_5 ? V_55 -> V_98 ( V_5 , V_55 ) : 0 ;
}
return F_37 ( & V_10 -> V_20 , V_55 -> V_98 , V_55 ) ;
}
static bool F_51 ( struct V_4 * V_10 ,
struct V_75 * V_55 )
{
struct {
struct V_4 * V_10 ;
struct V_99 * V_100 ;
int V_101 ;
} V_102 [ V_103 ] ;
struct V_104 * V_105 ;
struct V_99 * V_100 ;
struct V_1 * V_106 ;
struct V_4 * V_4 ;
int V_107 = 0 , V_101 ;
F_33 ( L_16 ,
V_10 -> V_58 ,
V_55 -> V_25 . type -> V_57 ,
V_55 -> V_25 . V_11 ) ;
#define F_52 (KEYRING_SEARCH_NO_STATE_CHECK | KEYRING_SEARCH_DO_STATE_CHECK)
F_53 ( ( V_55 -> V_69 & F_52 ) == 0 ||
( V_55 -> V_69 & F_52 ) == F_52 ) ;
if ( V_55 -> V_25 . V_11 )
V_55 -> V_25 . V_34 = strlen ( V_55 -> V_25 . V_11 ) ;
if ( V_55 -> V_72 . V_96 == V_108 ||
F_19 ( V_10 , & V_55 -> V_25 ) ) {
V_55 -> V_82 = 2 ;
switch ( V_55 -> V_98 ( F_4 ( V_10 ) , V_55 ) ) {
case 1 :
goto V_109;
case 2 :
return false ;
default:
break;
}
}
V_55 -> V_82 = 0 ;
V_110:
F_54 ( L_17 , V_10 -> V_58 ) ;
if ( V_10 -> V_69 & ( ( 1 << V_78 ) |
( 1 << V_79 ) ) )
goto V_111;
if ( F_49 ( V_10 , V_55 ) )
goto V_109;
V_106 = F_55 ( V_10 -> V_20 . V_112 ) ;
if ( ! V_106 )
goto V_111;
if ( F_56 ( V_106 ) ) {
V_105 = F_57 ( V_106 ) ;
F_58 () ;
if ( ( V_105 -> V_25 [ 0 ] & V_29 ) != 0 )
goto V_111;
V_106 = F_55 ( V_105 -> V_113 ) ;
V_100 = F_59 ( V_106 ) ;
goto V_114;
}
V_100 = F_59 ( V_106 ) ;
F_58 () ;
V_106 = V_100 -> V_115 [ 0 ] ;
if ( ! F_60 ( V_106 ) )
goto V_114;
V_116:
F_54 ( L_18 ) ;
if ( F_56 ( V_106 ) ) {
V_105 = F_57 ( V_106 ) ;
F_58 () ;
V_106 = F_55 ( V_105 -> V_113 ) ;
F_53 ( ! F_61 ( V_106 ) ) ;
}
V_100 = F_59 ( V_106 ) ;
V_114:
F_54 ( L_19 ) ;
F_58 () ;
V_101 = 0 ;
V_117:
for (; V_101 < V_118 ; V_101 ++ ) {
V_106 = F_55 ( V_100 -> V_115 [ V_101 ] ) ;
if ( F_60 ( V_106 ) && V_100 -> V_119 )
goto V_116;
if ( ! F_1 ( V_106 ) )
continue;
V_4 = F_2 ( V_106 ) ;
if ( V_107 >= V_103 ) {
if ( V_55 -> V_69 & V_120 ) {
V_55 -> V_80 = F_43 ( - V_121 ) ;
return false ;
}
goto V_111;
}
if ( ! ( V_55 -> V_69 & V_90 ) &&
F_46 ( F_47 ( V_4 , V_55 -> V_91 ) ,
V_55 -> V_67 , V_92 ) < 0 )
continue;
V_102 [ V_107 ] . V_10 = V_10 ;
V_102 [ V_107 ] . V_100 = V_100 ;
V_102 [ V_107 ] . V_101 = V_101 ;
V_107 ++ ;
V_10 = V_4 ;
goto V_110;
}
V_106 = F_55 ( V_100 -> V_119 ) ;
V_101 = V_100 -> V_122 ;
if ( V_106 && F_56 ( V_106 ) ) {
V_105 = F_57 ( V_106 ) ;
F_58 () ;
V_106 = F_55 ( V_105 -> V_119 ) ;
V_101 = V_105 -> V_122 ;
}
if ( ! V_106 )
goto V_111;
V_100 = F_59 ( V_106 ) ;
F_58 () ;
V_101 ++ ;
if ( V_100 -> V_119 ) {
F_54 ( L_20 , V_101 ) ;
goto V_117;
}
V_111:
F_54 ( L_21 , V_107 ) ;
if ( V_107 <= 0 ) {
F_38 ( L_22 ) ;
return false ;
}
V_107 -- ;
V_10 = V_102 [ V_107 ] . V_10 ;
V_100 = V_102 [ V_107 ] . V_100 ;
V_101 = V_102 [ V_107 ] . V_101 + 1 ;
F_54 ( L_23 , V_10 -> V_58 , V_101 ) ;
goto V_117;
V_109:
V_4 = F_62 ( V_55 -> V_80 ) ;
F_63 ( V_4 ) ;
if ( ! ( V_55 -> V_69 & V_123 ) ) {
V_4 -> V_124 = V_55 -> V_85 . V_86 ;
V_10 -> V_124 = V_55 -> V_85 . V_86 ;
while ( V_107 > 0 )
V_102 [ -- V_107 ] . V_10 -> V_124 = V_55 -> V_85 . V_86 ;
}
F_38 ( L_24 ) ;
return true ;
}
T_8 F_64 ( T_8 V_125 ,
struct V_75 * V_55 )
{
struct V_4 * V_10 ;
long V_126 ;
V_55 -> V_98 = F_45 ;
V_55 -> V_91 = F_65 ( V_125 ) ;
V_55 -> V_80 = F_43 ( - V_127 ) ;
V_10 = F_62 ( V_125 ) ;
F_63 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_43 ( - V_128 ) ;
if ( ! ( V_55 -> V_69 & V_90 ) ) {
V_126 = F_46 ( V_125 , V_55 -> V_67 , V_92 ) ;
if ( V_126 < 0 )
return F_43 ( V_126 ) ;
}
F_66 () ;
V_55 -> V_85 = F_67 () ;
if ( F_51 ( V_10 , V_55 ) )
F_68 ( F_62 ( V_55 -> V_80 ) ) ;
F_69 () ;
return V_55 -> V_80 ;
}
T_8 F_70 ( T_8 V_10 ,
struct V_129 * type ,
const char * V_11 )
{
struct V_75 V_55 = {
. V_25 . type = type ,
. V_25 . V_11 = V_11 ,
. V_67 = F_71 () ,
. V_72 . V_89 = F_44 ,
. V_72 . V_73 = V_11 ,
. V_72 . V_96 = V_97 ,
. V_69 = V_77 ,
} ;
T_8 V_4 ;
int V_56 ;
if ( type -> V_130 ) {
V_56 = type -> V_130 ( & V_55 . V_72 ) ;
if ( V_56 < 0 )
return F_43 ( V_56 ) ;
}
V_4 = F_64 ( V_10 , & V_55 ) ;
if ( type -> V_131 )
type -> V_131 ( & V_55 . V_72 ) ;
return V_4 ;
}
T_8 F_72 ( T_8 V_125 ,
const struct V_24 * V_25 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_62 ( V_125 ) ;
F_33 ( L_16 ,
V_10 -> V_58 , V_25 -> type -> V_57 , V_25 -> V_11 ) ;
V_5 = F_50 ( & V_10 -> V_20 , & V_50 ,
V_25 ) ;
if ( V_5 )
goto V_109;
F_38 ( L_25 ) ;
return NULL ;
V_109:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_69 & ( ( 1 << V_78 ) |
( 1 << V_79 ) ) ) {
F_38 ( L_26 ) ;
return NULL ;
}
F_68 ( V_4 ) ;
F_38 ( L_27 , V_4 -> V_58 ) ;
return F_47 ( V_4 , F_65 ( V_125 ) ) ;
}
struct V_4 * F_73 ( const char * V_57 , bool V_132 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_57 )
return F_43 ( - V_19 ) ;
V_8 = F_5 ( V_57 ) ;
F_74 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_75 (keyring,
&keyring_name_hash[bucket],
name_link
) {
if ( ! F_76 ( F_77 () , V_10 -> V_133 -> V_65 ) )
continue;
if ( F_78 ( V_79 , & V_10 -> V_69 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_57 ) != 0 )
continue;
if ( ! V_132 &&
F_79 ( F_47 ( V_10 , 0 ) ,
V_92 ) < 0 )
continue;
if ( ! F_80 ( & V_10 -> V_134 ) )
continue;
V_10 -> V_124 = F_67 () . V_86 ;
goto V_135;
}
}
V_10 = F_43 ( - V_136 ) ;
V_135:
F_81 ( & V_12 ) ;
return V_10 ;
}
static int F_82 ( const void * V_5 ,
void * V_74 )
{
struct V_75 * V_55 = V_74 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_33 ( L_8 , V_4 -> V_58 ) ;
if ( V_4 != V_55 -> V_72 . V_73 )
return 0 ;
V_55 -> V_80 = F_43 ( - V_137 ) ;
return 1 ;
}
static int F_83 ( struct V_4 * V_138 , struct V_4 * V_139 )
{
struct V_75 V_55 = {
. V_25 = V_138 -> V_25 ,
. V_72 . V_73 = V_138 ,
. V_72 . V_96 = V_97 ,
. V_98 = F_82 ,
. V_69 = ( V_140 |
V_123 |
V_90 |
V_120 ) ,
} ;
F_66 () ;
F_51 ( V_139 , & V_55 ) ;
F_69 () ;
return F_84 ( V_55 . V_80 ) == - V_127 ? 0 : F_84 ( V_55 . V_80 ) ;
}
int F_85 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_141 * * V_142 )
__acquires( &keyring->sem
int F_86 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_83 ( V_10 , V_4 ) ;
return 0 ;
}
void F_87 ( struct V_4 * V_4 , struct V_141 * * V_142 )
{
F_68 ( V_4 ) ;
F_88 ( * V_142 , F_4 ( V_4 ) ) ;
F_89 ( * V_142 ) ;
* V_142 = NULL ;
}
void F_90 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_141 * V_143 )
__releases( &keyring->sem
int F_91 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_141 * V_143 ;
int V_56 ;
F_33 ( L_28 , V_10 -> V_58 , F_92 ( & V_10 -> V_134 ) ) ;
F_63 ( V_10 ) ;
F_63 ( V_4 ) ;
if ( F_78 ( V_144 , & V_10 -> V_69 ) &&
! F_78 ( V_145 , & V_4 -> V_69 ) )
return - V_146 ;
V_56 = F_85 ( V_10 , & V_4 -> V_25 , & V_143 ) ;
if ( V_56 == 0 ) {
F_54 ( L_29 , V_10 -> V_58 , F_92 ( & V_10 -> V_134 ) ) ;
V_56 = F_86 ( V_10 , V_4 ) ;
if ( V_56 == 0 )
F_87 ( V_4 , & V_143 ) ;
F_90 ( V_10 , & V_4 -> V_25 , V_143 ) ;
}
F_38 ( L_30 , V_56 , V_10 -> V_58 , F_92 ( & V_10 -> V_134 ) ) ;
return V_56 ;
}
int F_93 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_141 * V_143 ;
int V_56 ;
F_63 ( V_10 ) ;
F_63 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_128 ;
F_94 ( & V_10 -> V_147 ) ;
V_143 = F_95 ( & V_10 -> V_20 , & V_50 ,
& V_4 -> V_25 ) ;
if ( F_41 ( V_143 ) ) {
V_56 = F_84 ( V_143 ) ;
goto error;
}
V_56 = - V_148 ;
if ( V_143 == NULL )
goto error;
F_89 ( V_143 ) ;
F_96 ( V_10 , V_10 -> V_18 - V_149 ) ;
V_56 = 0 ;
error:
F_97 ( & V_10 -> V_147 ) ;
return V_56 ;
}
int F_98 ( struct V_4 * V_10 )
{
struct V_141 * V_143 ;
int V_56 ;
if ( V_10 -> type != & V_6 )
return - V_128 ;
F_94 ( & V_10 -> V_147 ) ;
V_143 = F_99 ( & V_10 -> V_20 , & V_50 ) ;
if ( F_41 ( V_143 ) ) {
V_56 = F_84 ( V_143 ) ;
} else {
if ( V_143 )
F_89 ( V_143 ) ;
F_96 ( V_10 , 0 ) ;
V_56 = 0 ;
}
F_97 ( & V_10 -> V_147 ) ;
return V_56 ;
}
static void F_100 ( struct V_4 * V_10 )
{
struct V_141 * V_143 ;
V_143 = F_99 ( & V_10 -> V_20 , & V_50 ) ;
if ( ! F_41 ( V_143 ) ) {
if ( V_143 )
F_89 ( V_143 ) ;
F_96 ( V_10 , 0 ) ;
}
}
static bool F_101 ( void * V_5 , void * V_74 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_150 = V_74 ;
if ( F_102 ( V_4 , * V_150 ) )
return false ;
F_103 ( V_4 ) ;
return true ;
}
static int F_104 ( const void * V_5 , void * V_74 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_150 = V_74 ;
F_63 ( V_4 ) ;
return F_102 ( V_4 , * V_150 ) ;
}
void F_105 ( struct V_4 * V_10 , T_9 V_150 )
{
int V_80 ;
F_33 ( L_31 , V_10 -> V_58 , V_10 -> V_11 ? : L_32 ) ;
if ( V_10 -> V_69 & ( ( 1 << V_78 ) |
( 1 << V_79 ) ) )
goto V_151;
F_66 () ;
V_80 = F_37 ( & V_10 -> V_20 ,
F_104 , & V_150 ) ;
F_69 () ;
if ( V_80 == true )
goto V_152;
V_151:
F_38 ( L_33 ) ;
return;
V_152:
F_94 ( & V_10 -> V_147 ) ;
F_106 ( & V_10 -> V_20 , & V_50 ,
F_101 , & V_150 ) ;
F_97 ( & V_10 -> V_147 ) ;
F_38 ( L_34 ) ;
}
