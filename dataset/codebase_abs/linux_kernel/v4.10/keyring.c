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
unsigned long V_69 ,
int (* F_40)( struct V_4 * ,
const struct V_70 * ,
const union V_71 * ) ,
struct V_4 * V_72 )
{
struct V_4 * V_10 ;
int V_56 ;
V_10 = F_41 ( & V_6 , V_11 ,
V_65 , V_66 , V_67 , V_68 , V_69 , F_40 ) ;
if ( ! F_42 ( V_10 ) ) {
V_56 = F_43 ( V_10 , NULL , 0 , V_72 , NULL ) ;
if ( V_56 < 0 ) {
F_23 ( V_10 ) ;
V_10 = F_44 ( V_56 ) ;
}
}
return V_10 ;
}
int F_45 ( struct V_4 * V_10 ,
const struct V_70 * type ,
const union V_71 * V_73 )
{
return - V_74 ;
}
bool F_46 ( const struct V_4 * V_4 ,
const struct V_75 * V_76 )
{
return strcmp ( V_4 -> V_11 , V_76 -> V_77 ) == 0 ;
}
static int F_47 ( const void * V_5 , void * V_78 )
{
struct V_79 * V_55 = V_78 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_80 = V_4 -> V_69 ;
F_33 ( L_8 , V_4 -> V_58 ) ;
if ( V_4 -> type != V_55 -> V_25 . type ) {
F_38 ( L_9 ) ;
return 0 ;
}
if ( V_55 -> V_69 & V_81 ) {
if ( V_80 & ( ( 1 << V_82 ) |
( 1 << V_83 ) ) ) {
V_55 -> V_84 = F_44 ( - V_85 ) ;
F_38 ( L_10 , V_55 -> V_86 ) ;
goto V_87;
}
if ( V_4 -> V_88 && V_55 -> V_89 . V_90 >= V_4 -> V_88 ) {
if ( ! ( V_55 -> V_69 & V_91 ) )
V_55 -> V_84 = F_44 ( - V_92 ) ;
F_38 ( L_11 , V_55 -> V_86 ) ;
goto V_87;
}
}
if ( ! V_55 -> V_76 . V_93 ( V_4 , & V_55 -> V_76 ) ) {
F_38 ( L_12 ) ;
return 0 ;
}
if ( ! ( V_55 -> V_69 & V_94 ) &&
F_48 ( F_49 ( V_4 , V_55 -> V_95 ) ,
V_55 -> V_67 , V_96 ) < 0 ) {
V_55 -> V_84 = F_44 ( - V_97 ) ;
F_38 ( L_13 , V_55 -> V_86 ) ;
goto V_87;
}
if ( V_55 -> V_69 & V_81 ) {
if ( V_80 & ( 1 << V_98 ) ) {
F_50 () ;
V_55 -> V_84 = F_44 ( V_4 -> V_99 ) ;
F_38 ( L_14 , V_55 -> V_86 ) ;
goto V_87;
}
}
V_55 -> V_84 = F_49 ( V_4 , V_55 -> V_95 ) ;
F_38 ( L_15 ) ;
return 1 ;
V_87:
return V_55 -> V_86 ;
}
static int F_51 ( struct V_4 * V_10 , struct V_79 * V_55 )
{
if ( V_55 -> V_76 . V_100 == V_101 ) {
const void * V_5 ;
V_5 = F_52 ( & V_10 -> V_20 ,
& V_50 ,
& V_55 -> V_25 ) ;
return V_5 ? V_55 -> V_102 ( V_5 , V_55 ) : 0 ;
}
return F_37 ( & V_10 -> V_20 , V_55 -> V_102 , V_55 ) ;
}
static bool F_53 ( struct V_4 * V_10 ,
struct V_79 * V_55 )
{
struct {
struct V_4 * V_10 ;
struct V_103 * V_104 ;
int V_105 ;
} V_106 [ V_107 ] ;
struct V_108 * V_109 ;
struct V_103 * V_104 ;
struct V_1 * V_110 ;
struct V_4 * V_4 ;
int V_111 = 0 , V_105 ;
F_33 ( L_16 ,
V_10 -> V_58 ,
V_55 -> V_25 . type -> V_57 ,
V_55 -> V_25 . V_11 ) ;
#define F_54 (KEYRING_SEARCH_NO_STATE_CHECK | KEYRING_SEARCH_DO_STATE_CHECK)
F_55 ( ( V_55 -> V_69 & F_54 ) == 0 ||
( V_55 -> V_69 & F_54 ) == F_54 ) ;
if ( V_55 -> V_25 . V_11 )
V_55 -> V_25 . V_34 = strlen ( V_55 -> V_25 . V_11 ) ;
if ( V_55 -> V_76 . V_100 == V_112 ||
F_19 ( V_10 , & V_55 -> V_25 ) ) {
V_55 -> V_86 = 2 ;
switch ( V_55 -> V_102 ( F_4 ( V_10 ) , V_55 ) ) {
case 1 :
goto V_113;
case 2 :
return false ;
default:
break;
}
}
V_55 -> V_86 = 0 ;
V_114:
F_56 ( L_17 , V_10 -> V_58 ) ;
if ( V_10 -> V_69 & ( ( 1 << V_82 ) |
( 1 << V_83 ) ) )
goto V_115;
if ( F_51 ( V_10 , V_55 ) )
goto V_113;
V_110 = F_57 ( V_10 -> V_20 . V_116 ) ;
if ( ! V_110 )
goto V_115;
if ( F_58 ( V_110 ) ) {
V_109 = F_59 ( V_110 ) ;
F_60 () ;
if ( ( V_109 -> V_25 [ 0 ] & V_29 ) != 0 )
goto V_115;
V_110 = F_57 ( V_109 -> V_117 ) ;
V_104 = F_61 ( V_110 ) ;
goto V_118;
}
V_104 = F_61 ( V_110 ) ;
F_60 () ;
V_110 = V_104 -> V_119 [ 0 ] ;
if ( ! F_62 ( V_110 ) )
goto V_118;
V_120:
F_56 ( L_18 ) ;
if ( F_58 ( V_110 ) ) {
V_109 = F_59 ( V_110 ) ;
F_60 () ;
V_110 = F_57 ( V_109 -> V_117 ) ;
F_55 ( ! F_63 ( V_110 ) ) ;
}
V_104 = F_61 ( V_110 ) ;
V_118:
F_56 ( L_19 ) ;
F_60 () ;
V_105 = 0 ;
V_121:
for (; V_105 < V_122 ; V_105 ++ ) {
V_110 = F_57 ( V_104 -> V_119 [ V_105 ] ) ;
if ( F_62 ( V_110 ) && V_104 -> V_123 )
goto V_120;
if ( ! F_1 ( V_110 ) )
continue;
V_4 = F_2 ( V_110 ) ;
if ( V_111 >= V_107 ) {
if ( V_55 -> V_69 & V_124 ) {
V_55 -> V_84 = F_44 ( - V_125 ) ;
return false ;
}
goto V_115;
}
if ( ! ( V_55 -> V_69 & V_94 ) &&
F_48 ( F_49 ( V_4 , V_55 -> V_95 ) ,
V_55 -> V_67 , V_96 ) < 0 )
continue;
V_106 [ V_111 ] . V_10 = V_10 ;
V_106 [ V_111 ] . V_104 = V_104 ;
V_106 [ V_111 ] . V_105 = V_105 ;
V_111 ++ ;
V_10 = V_4 ;
goto V_114;
}
V_110 = F_57 ( V_104 -> V_123 ) ;
V_105 = V_104 -> V_126 ;
if ( V_110 && F_58 ( V_110 ) ) {
V_109 = F_59 ( V_110 ) ;
F_60 () ;
V_110 = F_57 ( V_109 -> V_123 ) ;
V_105 = V_109 -> V_126 ;
}
if ( ! V_110 )
goto V_115;
V_104 = F_61 ( V_110 ) ;
F_60 () ;
V_105 ++ ;
if ( V_104 -> V_123 ) {
F_56 ( L_20 , V_105 ) ;
goto V_121;
}
V_115:
F_56 ( L_21 , V_111 ) ;
if ( V_111 <= 0 ) {
F_38 ( L_22 ) ;
return false ;
}
V_111 -- ;
V_10 = V_106 [ V_111 ] . V_10 ;
V_104 = V_106 [ V_111 ] . V_104 ;
V_105 = V_106 [ V_111 ] . V_105 + 1 ;
F_56 ( L_23 , V_10 -> V_58 , V_105 ) ;
goto V_121;
V_113:
V_4 = F_64 ( V_55 -> V_84 ) ;
F_65 ( V_4 ) ;
if ( ! ( V_55 -> V_69 & V_127 ) ) {
V_4 -> V_128 = V_55 -> V_89 . V_90 ;
V_10 -> V_128 = V_55 -> V_89 . V_90 ;
while ( V_111 > 0 )
V_106 [ -- V_111 ] . V_10 -> V_128 = V_55 -> V_89 . V_90 ;
}
F_38 ( L_24 ) ;
return true ;
}
T_8 F_66 ( T_8 V_129 ,
struct V_79 * V_55 )
{
struct V_4 * V_10 ;
long V_130 ;
V_55 -> V_102 = F_47 ;
V_55 -> V_95 = F_67 ( V_129 ) ;
V_55 -> V_84 = F_44 ( - V_131 ) ;
V_10 = F_64 ( V_129 ) ;
F_65 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_44 ( - V_132 ) ;
if ( ! ( V_55 -> V_69 & V_94 ) ) {
V_130 = F_48 ( V_129 , V_55 -> V_67 , V_96 ) ;
if ( V_130 < 0 )
return F_44 ( V_130 ) ;
}
F_68 () ;
V_55 -> V_89 = F_69 () ;
if ( F_53 ( V_10 , V_55 ) )
F_70 ( F_64 ( V_55 -> V_84 ) ) ;
F_71 () ;
return V_55 -> V_84 ;
}
T_8 F_72 ( T_8 V_10 ,
struct V_70 * type ,
const char * V_11 )
{
struct V_79 V_55 = {
. V_25 . type = type ,
. V_25 . V_11 = V_11 ,
. V_67 = F_73 () ,
. V_76 . V_93 = F_46 ,
. V_76 . V_77 = V_11 ,
. V_76 . V_100 = V_101 ,
. V_69 = V_81 ,
} ;
T_8 V_4 ;
int V_56 ;
if ( type -> V_133 ) {
V_56 = type -> V_133 ( & V_55 . V_76 ) ;
if ( V_56 < 0 )
return F_44 ( V_56 ) ;
}
V_4 = F_66 ( V_10 , & V_55 ) ;
if ( type -> V_134 )
type -> V_134 ( & V_55 . V_76 ) ;
return V_4 ;
}
T_8 F_74 ( T_8 V_129 ,
const struct V_24 * V_25 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_64 ( V_129 ) ;
F_33 ( L_16 ,
V_10 -> V_58 , V_25 -> type -> V_57 , V_25 -> V_11 ) ;
V_5 = F_52 ( & V_10 -> V_20 , & V_50 ,
V_25 ) ;
if ( V_5 )
goto V_113;
F_38 ( L_25 ) ;
return NULL ;
V_113:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_69 & ( ( 1 << V_82 ) |
( 1 << V_83 ) ) ) {
F_38 ( L_26 ) ;
return NULL ;
}
F_70 ( V_4 ) ;
F_38 ( L_27 , V_4 -> V_58 ) ;
return F_49 ( V_4 , F_67 ( V_129 ) ) ;
}
struct V_4 * F_75 ( const char * V_57 , bool V_135 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_57 )
return F_44 ( - V_19 ) ;
V_8 = F_5 ( V_57 ) ;
F_76 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_77 (keyring,
&keyring_name_hash[bucket],
name_link
) {
if ( ! F_78 ( F_79 () , V_10 -> V_136 -> V_65 ) )
continue;
if ( F_80 ( V_83 , & V_10 -> V_69 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_57 ) != 0 )
continue;
if ( ! V_135 &&
F_81 ( F_49 ( V_10 , 0 ) ,
V_96 ) < 0 )
continue;
if ( ! F_82 ( & V_10 -> V_137 ) )
continue;
V_10 -> V_128 = F_69 () . V_90 ;
goto V_138;
}
}
V_10 = F_44 ( - V_139 ) ;
V_138:
F_83 ( & V_12 ) ;
return V_10 ;
}
static int F_84 ( const void * V_5 ,
void * V_78 )
{
struct V_79 * V_55 = V_78 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_33 ( L_8 , V_4 -> V_58 ) ;
if ( V_4 != V_55 -> V_76 . V_77 )
return 0 ;
V_55 -> V_84 = F_44 ( - V_140 ) ;
return 1 ;
}
static int F_85 ( struct V_4 * V_141 , struct V_4 * V_142 )
{
struct V_79 V_55 = {
. V_25 = V_141 -> V_25 ,
. V_76 . V_77 = V_141 ,
. V_76 . V_100 = V_101 ,
. V_102 = F_84 ,
. V_69 = ( V_143 |
V_127 |
V_94 |
V_124 ) ,
} ;
F_68 () ;
F_53 ( V_142 , & V_55 ) ;
F_71 () ;
return F_86 ( V_55 . V_84 ) == - V_131 ? 0 : F_86 ( V_55 . V_84 ) ;
}
int F_87 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_144 * * V_145 )
__acquires( &keyring->sem
int F_88 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_85 ( V_10 , V_4 ) ;
return 0 ;
}
void F_89 ( struct V_4 * V_4 , struct V_144 * * V_145 )
{
F_70 ( V_4 ) ;
F_90 ( * V_145 , F_4 ( V_4 ) ) ;
F_91 ( * V_145 ) ;
* V_145 = NULL ;
}
void F_92 ( struct V_4 * V_10 ,
const struct V_24 * V_25 ,
struct V_144 * V_146 )
__releases( &keyring->sem
static int F_93 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( ! V_10 -> F_40 )
return 0 ;
return V_10 -> F_40 ( V_10 , V_4 -> type , & V_4 -> V_73 ) ;
}
int F_94 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_144 * V_146 ;
int V_56 ;
F_33 ( L_28 , V_10 -> V_58 , F_95 ( & V_10 -> V_137 ) ) ;
F_65 ( V_10 ) ;
F_65 ( V_4 ) ;
V_56 = F_87 ( V_10 , & V_4 -> V_25 , & V_146 ) ;
if ( V_56 == 0 ) {
F_56 ( L_29 , V_10 -> V_58 , F_95 ( & V_10 -> V_137 ) ) ;
V_56 = F_93 ( V_10 , V_4 ) ;
if ( V_56 == 0 )
V_56 = F_88 ( V_10 , V_4 ) ;
if ( V_56 == 0 )
F_89 ( V_4 , & V_146 ) ;
F_92 ( V_10 , & V_4 -> V_25 , V_146 ) ;
}
F_38 ( L_30 , V_56 , V_10 -> V_58 , F_95 ( & V_10 -> V_137 ) ) ;
return V_56 ;
}
int F_96 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_144 * V_146 ;
int V_56 ;
F_65 ( V_10 ) ;
F_65 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_132 ;
F_97 ( & V_10 -> V_147 ) ;
V_146 = F_98 ( & V_10 -> V_20 , & V_50 ,
& V_4 -> V_25 ) ;
if ( F_42 ( V_146 ) ) {
V_56 = F_86 ( V_146 ) ;
goto error;
}
V_56 = - V_148 ;
if ( V_146 == NULL )
goto error;
F_91 ( V_146 ) ;
F_99 ( V_10 , V_10 -> V_18 - V_149 ) ;
V_56 = 0 ;
error:
F_100 ( & V_10 -> V_147 ) ;
return V_56 ;
}
int F_101 ( struct V_4 * V_10 )
{
struct V_144 * V_146 ;
int V_56 ;
if ( V_10 -> type != & V_6 )
return - V_132 ;
F_97 ( & V_10 -> V_147 ) ;
V_146 = F_102 ( & V_10 -> V_20 , & V_50 ) ;
if ( F_42 ( V_146 ) ) {
V_56 = F_86 ( V_146 ) ;
} else {
if ( V_146 )
F_91 ( V_146 ) ;
F_99 ( V_10 , 0 ) ;
V_56 = 0 ;
}
F_100 ( & V_10 -> V_147 ) ;
return V_56 ;
}
static void F_103 ( struct V_4 * V_10 )
{
struct V_144 * V_146 ;
V_146 = F_102 ( & V_10 -> V_20 , & V_50 ) ;
if ( ! F_42 ( V_146 ) ) {
if ( V_146 )
F_91 ( V_146 ) ;
F_99 ( V_10 , 0 ) ;
}
}
static bool F_104 ( void * V_5 , void * V_78 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_150 = V_78 ;
if ( F_105 ( V_4 , * V_150 ) )
return false ;
F_106 ( V_4 ) ;
return true ;
}
static int F_107 ( const void * V_5 , void * V_78 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_150 = V_78 ;
F_65 ( V_4 ) ;
return F_105 ( V_4 , * V_150 ) ;
}
void F_108 ( struct V_4 * V_10 , T_9 V_150 )
{
int V_84 ;
F_33 ( L_31 , V_10 -> V_58 , V_10 -> V_11 ? : L_32 ) ;
if ( V_10 -> V_69 & ( ( 1 << V_82 ) |
( 1 << V_83 ) ) )
goto V_151;
F_68 () ;
V_84 = F_37 ( & V_10 -> V_20 ,
F_107 , & V_150 ) ;
F_71 () ;
if ( V_84 == true )
goto V_152;
V_151:
F_38 ( L_33 ) ;
return;
V_152:
F_97 ( & V_10 -> V_147 ) ;
F_109 ( & V_10 -> V_20 , & V_50 ,
F_104 , & V_150 ) ;
F_100 ( & V_10 -> V_147 ) ;
F_38 ( L_34 ) ;
}
