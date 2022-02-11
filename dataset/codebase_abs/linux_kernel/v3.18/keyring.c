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
F_9 ( & V_10 -> V_15 . V_16 ,
& V_13 [ V_8 ] ) ;
F_10 ( & V_12 ) ;
}
}
static int F_11 ( struct V_17 * V_18 )
{
return V_18 -> V_19 != 0 ? - V_20 : 0 ;
}
static void F_12 ( struct V_17 * V_18 )
{
}
static int F_13 ( struct V_4 * V_10 ,
struct V_17 * V_18 )
{
F_14 ( & V_10 -> V_21 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
static T_1 F_15 ( T_1 V_2 , T_2 V_22 )
{
T_1 V_23 = ( T_1 ) ( T_2 ) ( V_2 >> 32 ) * V_22 ;
T_1 V_24 = ( T_1 ) ( T_2 ) ( V_2 ) * V_22 ;
return V_24 + ( ( T_1 ) ( T_2 ) V_23 << 32 ) + ( T_2 ) ( V_23 >> 32 ) ;
}
static unsigned long F_16 ( const struct V_25 * V_26 )
{
const unsigned V_27 = V_28 ;
const unsigned long V_29 = V_30 ;
const char * V_11 = V_26 -> V_11 ;
unsigned long V_31 , type ;
T_2 V_32 ;
T_1 V_33 ;
int V_34 , V_35 = V_26 -> V_35 ;
type = ( unsigned long ) V_26 -> type ;
V_33 = F_15 ( type , V_35 + 13 ) ;
V_33 = F_15 ( V_33 , 9207 ) ;
for (; ; ) {
V_34 = V_35 ;
if ( V_34 <= 0 )
break;
if ( V_34 > 4 )
V_34 = 4 ;
V_32 = 0 ;
memcpy ( & V_32 , V_11 , V_34 ) ;
V_11 += V_34 ;
V_35 -= V_34 ;
V_33 = F_15 ( V_33 , V_32 ) ;
V_33 = F_15 ( V_33 , 9207 ) ;
}
V_31 = V_33 ;
if ( V_36 == 32 )
V_31 ^= V_33 >> 32 ;
if ( V_26 -> type != & V_6 && ( V_31 & V_29 ) == 0 )
return V_31 | ( V_31 >> ( V_36 - V_27 ) ) | 1 ;
if ( V_26 -> type == & V_6 && ( V_31 & V_29 ) != 0 )
return ( V_31 + ( V_31 << V_27 ) ) & ~ V_29 ;
return V_31 ;
}
static unsigned long F_17 ( const void * V_37 , int V_38 )
{
const struct V_25 * V_26 = V_37 ;
unsigned long V_39 = 0 ;
long V_40 = 0 ;
int V_35 = V_26 -> V_35 , V_34 = sizeof( V_39 ) ;
V_38 /= V_36 ;
switch ( V_38 ) {
case 0 :
return F_16 ( V_26 ) ;
case 1 :
return ( ( unsigned long ) V_26 -> type << 8 ) | V_35 ;
case 2 :
if ( V_35 == 0 )
return ( V_41 ) ( ( unsigned long ) V_26 -> type >>
( V_36 - 8 ) ) ;
V_34 -- ;
V_40 = 1 ;
default:
V_40 += sizeof( V_39 ) - 1 ;
V_40 += ( V_38 - 3 ) * sizeof( V_39 ) ;
if ( V_40 >= V_35 )
return 0 ;
V_35 -= V_40 ;
if ( V_35 > V_34 )
V_35 = V_34 ;
V_40 += V_35 ;
do {
V_39 <<= 8 ;
V_39 |= ( ( V_41 * ) V_26 -> V_11 ) [ -- V_40 ] ;
} while ( -- V_35 > 0 );
if ( V_38 == 2 ) {
V_39 <<= 8 ;
V_39 |= ( V_41 ) ( ( unsigned long ) V_26 -> type >>
( V_36 - 8 ) ) ;
}
return V_39 ;
}
}
static unsigned long F_18 ( const void * V_5 , int V_38 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return F_17 ( & V_4 -> V_26 , V_38 ) ;
}
static bool F_19 ( const void * V_5 , const void * V_37 )
{
const struct V_25 * V_26 = V_37 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return V_4 -> V_26 . type == V_26 -> type &&
V_4 -> V_26 . V_35 == V_26 -> V_35 &&
memcmp ( V_4 -> V_26 . V_11 , V_26 -> V_11 ,
V_26 -> V_35 ) == 0 ;
}
static int F_20 ( const void * V_5 , const void * V_37 )
{
const struct V_4 * V_42 = F_2 ( V_5 ) ;
const struct V_25 * V_43 = & V_42 -> V_26 ;
const struct V_25 * V_44 = V_37 ;
unsigned long V_45 , V_46 ;
int V_38 , V_47 ;
V_38 = 0 ;
V_45 = F_16 ( V_43 ) ;
V_46 = F_16 ( V_44 ) ;
if ( ( V_45 ^ V_46 ) != 0 )
goto V_48;
V_38 += V_36 / 8 ;
V_45 = V_43 -> V_35 ;
V_46 = V_44 -> V_35 ;
if ( ( V_45 ^ V_46 ) != 0 )
goto V_48;
V_38 ++ ;
V_45 = ( unsigned long ) V_43 -> type ;
V_46 = ( unsigned long ) V_44 -> type ;
if ( ( V_45 ^ V_46 ) != 0 )
goto V_48;
V_38 += sizeof( unsigned long ) ;
if ( V_43 -> V_35 == 0 )
goto V_49;
V_47 = 0 ;
if ( ( ( unsigned long ) V_43 -> V_11 | ( unsigned long ) V_44 -> V_11 ) &
(sizeof( unsigned long ) - 1 ) ) {
do {
V_45 = * ( unsigned long * ) ( V_43 -> V_11 + V_47 ) ;
V_46 = * ( unsigned long * ) ( V_44 -> V_11 + V_47 ) ;
if ( ( V_45 ^ V_46 ) != 0 )
goto V_50;
V_47 += sizeof( unsigned long ) ;
} while ( V_47 < ( V_43 -> V_35 & (sizeof( unsigned long ) - 1 ) ) );
}
for (; V_47 < V_43 -> V_35 ; V_47 ++ ) {
V_45 = * ( unsigned char * ) ( V_43 -> V_11 + V_47 ) ;
V_46 = * ( unsigned char * ) ( V_44 -> V_11 + V_47 ) ;
if ( ( V_45 ^ V_46 ) != 0 )
goto V_50;
}
V_49:
return - 1 ;
V_50:
V_38 += V_47 ;
V_48:
V_47 = V_38 * 8 + F_21 ( V_45 ^ V_46 ) ;
return V_47 ;
}
static void F_22 ( void * V_5 )
{
F_23 ( F_2 ( V_5 ) ) ;
}
static void F_24 ( struct V_4 * V_10 )
{
if ( V_10 -> V_11 ) {
F_7 ( & V_12 ) ;
if ( V_10 -> V_15 . V_16 . V_14 != NULL &&
! F_25 ( & V_10 -> V_15 . V_16 ) )
F_26 ( & V_10 -> V_15 . V_16 ) ;
F_10 ( & V_12 ) ;
}
F_27 ( & V_10 -> V_21 , & V_51 ) ;
}
static void F_28 ( const struct V_4 * V_10 , struct V_52 * V_53 )
{
if ( V_10 -> V_11 )
F_29 ( V_53 , V_10 -> V_11 ) ;
else
F_29 ( V_53 , L_1 ) ;
if ( F_30 ( V_10 ) ) {
if ( V_10 -> V_21 . V_54 != 0 )
F_31 ( V_53 , L_2 , V_10 -> V_21 . V_54 ) ;
else
F_29 ( V_53 , L_3 ) ;
}
}
static int F_32 ( const void * V_5 , void * V_37 )
{
struct V_55 * V_56 = V_37 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
int V_57 ;
F_33 ( L_4 ,
V_4 -> type -> V_58 , V_4 -> V_59 , V_56 -> V_60 , V_56 -> V_61 ) ;
if ( V_56 -> V_60 >= V_56 -> V_61 )
return 1 ;
V_57 = F_34 ( V_4 -> V_59 , V_56 -> V_62 ) ;
if ( V_57 < 0 )
return V_57 ;
V_56 -> V_62 ++ ;
V_56 -> V_60 += sizeof( V_4 -> V_59 ) ;
return 0 ;
}
static long F_35 ( const struct V_4 * V_10 ,
char T_3 * V_62 , T_4 V_63 )
{
struct V_55 V_56 ;
unsigned long V_64 ;
int V_57 ;
F_33 ( L_5 , F_36 ( V_10 ) , V_63 ) ;
if ( V_63 & ( sizeof( V_65 ) - 1 ) )
return - V_20 ;
V_64 = V_10 -> V_21 . V_54 ;
if ( V_64 == 0 )
return 0 ;
V_56 . V_61 = V_64 * sizeof( V_65 ) ;
if ( ! V_62 || ! V_63 )
return V_56 . V_61 ;
if ( V_63 > V_56 . V_61 )
V_56 . V_61 = V_63 ;
V_56 . V_62 = ( V_65 T_3 * ) V_62 ;
V_56 . V_60 = 0 ;
V_57 = F_37 ( & V_10 -> V_21 , F_32 , & V_56 ) ;
if ( V_57 < 0 ) {
F_38 ( L_6 , V_57 ) ;
return V_57 ;
}
F_38 ( L_7 , V_56 . V_60 ) ;
return V_56 . V_60 ;
}
struct V_4 * F_39 ( const char * V_11 , T_5 V_66 , T_6 V_67 ,
const struct V_68 * V_68 , T_7 V_69 ,
unsigned long V_70 , struct V_4 * V_71 )
{
struct V_4 * V_10 ;
int V_57 ;
V_10 = F_40 ( & V_6 , V_11 ,
V_66 , V_67 , V_68 , V_69 , V_70 ) ;
if ( ! F_41 ( V_10 ) ) {
V_57 = F_42 ( V_10 , NULL , 0 , V_71 , NULL ) ;
if ( V_57 < 0 ) {
F_23 ( V_10 ) ;
V_10 = F_43 ( V_57 ) ;
}
}
return V_10 ;
}
bool F_44 ( const struct V_4 * V_4 ,
const struct V_72 * V_73 )
{
return strcmp ( V_4 -> V_11 , V_73 -> V_74 ) == 0 ;
}
static int F_45 ( const void * V_5 , void * V_75 )
{
struct V_76 * V_56 = V_75 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_77 = V_4 -> V_70 ;
F_33 ( L_8 , V_4 -> V_59 ) ;
if ( V_4 -> type != V_56 -> V_26 . type ) {
F_38 ( L_9 ) ;
return 0 ;
}
if ( V_56 -> V_70 & V_78 ) {
if ( V_77 & ( ( 1 << V_79 ) |
( 1 << V_80 ) ) ) {
V_56 -> V_81 = F_43 ( - V_82 ) ;
F_38 ( L_10 , V_56 -> V_83 ) ;
goto V_84;
}
if ( V_4 -> V_85 && V_56 -> V_86 . V_87 >= V_4 -> V_85 ) {
if ( ! ( V_56 -> V_70 & V_88 ) )
V_56 -> V_81 = F_43 ( - V_89 ) ;
F_38 ( L_11 , V_56 -> V_83 ) ;
goto V_84;
}
}
if ( ! V_56 -> V_73 . V_90 ( V_4 , & V_56 -> V_73 ) ) {
F_38 ( L_12 ) ;
return 0 ;
}
if ( ! ( V_56 -> V_70 & V_91 ) &&
F_46 ( F_47 ( V_4 , V_56 -> V_92 ) ,
V_56 -> V_68 , V_93 ) < 0 ) {
V_56 -> V_81 = F_43 ( - V_94 ) ;
F_38 ( L_13 , V_56 -> V_83 ) ;
goto V_84;
}
if ( V_56 -> V_70 & V_78 ) {
if ( V_77 & ( 1 << V_95 ) ) {
F_48 () ;
V_56 -> V_81 = F_43 ( V_4 -> V_15 . V_96 ) ;
F_38 ( L_14 , V_56 -> V_83 ) ;
goto V_84;
}
}
V_56 -> V_81 = F_47 ( V_4 , V_56 -> V_92 ) ;
F_38 ( L_15 ) ;
return 1 ;
V_84:
return V_56 -> V_83 ;
}
static int F_49 ( struct V_4 * V_10 , struct V_76 * V_56 )
{
if ( V_56 -> V_73 . V_97 == V_98 ) {
const void * V_5 ;
V_5 = F_50 ( & V_10 -> V_21 ,
& V_51 ,
& V_56 -> V_26 ) ;
return V_5 ? V_56 -> V_99 ( V_5 , V_56 ) : 0 ;
}
return F_37 ( & V_10 -> V_21 , V_56 -> V_99 , V_56 ) ;
}
static bool F_51 ( struct V_4 * V_10 ,
struct V_76 * V_56 )
{
struct {
struct V_4 * V_10 ;
struct V_100 * V_101 ;
int V_102 ;
} V_103 [ V_104 ] ;
struct V_105 * V_106 ;
struct V_100 * V_101 ;
struct V_1 * V_107 ;
struct V_4 * V_4 ;
int V_108 = 0 , V_102 ;
F_33 ( L_16 ,
V_10 -> V_59 ,
V_56 -> V_26 . type -> V_58 ,
V_56 -> V_26 . V_11 ) ;
#define F_52 (KEYRING_SEARCH_NO_STATE_CHECK | KEYRING_SEARCH_DO_STATE_CHECK)
F_53 ( ( V_56 -> V_70 & F_52 ) == 0 ||
( V_56 -> V_70 & F_52 ) == F_52 ) ;
if ( V_56 -> V_26 . V_11 )
V_56 -> V_26 . V_35 = strlen ( V_56 -> V_26 . V_11 ) ;
if ( V_56 -> V_73 . V_97 == V_109 ||
F_19 ( V_10 , & V_56 -> V_26 ) ) {
V_56 -> V_83 = 2 ;
switch ( V_56 -> V_99 ( F_4 ( V_10 ) , V_56 ) ) {
case 1 :
goto V_110;
case 2 :
return false ;
default:
break;
}
}
V_56 -> V_83 = 0 ;
V_111:
F_54 ( L_17 , V_10 -> V_59 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_79 ) |
( 1 << V_80 ) ) )
goto V_112;
if ( F_49 ( V_10 , V_56 ) )
goto V_110;
V_107 = F_55 ( V_10 -> V_21 . V_113 ) ;
if ( ! V_107 )
goto V_112;
if ( F_56 ( V_107 ) ) {
V_106 = F_57 ( V_107 ) ;
F_58 () ;
if ( ( V_106 -> V_26 [ 0 ] & V_30 ) != 0 )
goto V_112;
V_107 = F_55 ( V_106 -> V_114 ) ;
V_101 = F_59 ( V_107 ) ;
goto V_115;
}
V_101 = F_59 ( V_107 ) ;
F_58 () ;
V_107 = V_101 -> V_116 [ 0 ] ;
if ( ! F_60 ( V_107 ) )
goto V_115;
V_117:
F_54 ( L_18 ) ;
if ( F_56 ( V_107 ) ) {
V_106 = F_57 ( V_107 ) ;
F_58 () ;
V_107 = F_55 ( V_106 -> V_114 ) ;
F_53 ( ! F_61 ( V_107 ) ) ;
}
V_101 = F_59 ( V_107 ) ;
V_115:
F_54 ( L_19 ) ;
F_58 () ;
V_102 = 0 ;
V_118:
for (; V_102 < V_119 ; V_102 ++ ) {
V_107 = F_55 ( V_101 -> V_116 [ V_102 ] ) ;
if ( F_60 ( V_107 ) && V_101 -> V_120 )
goto V_117;
if ( ! F_1 ( V_107 ) )
continue;
V_4 = F_2 ( V_107 ) ;
if ( V_108 >= V_104 ) {
if ( V_56 -> V_70 & V_121 ) {
V_56 -> V_81 = F_43 ( - V_122 ) ;
return false ;
}
goto V_112;
}
if ( ! ( V_56 -> V_70 & V_91 ) &&
F_46 ( F_47 ( V_4 , V_56 -> V_92 ) ,
V_56 -> V_68 , V_93 ) < 0 )
continue;
V_103 [ V_108 ] . V_10 = V_10 ;
V_103 [ V_108 ] . V_101 = V_101 ;
V_103 [ V_108 ] . V_102 = V_102 ;
V_108 ++ ;
V_10 = V_4 ;
goto V_111;
}
V_107 = F_55 ( V_101 -> V_120 ) ;
V_102 = V_101 -> V_123 ;
if ( V_107 && F_56 ( V_107 ) ) {
V_106 = F_57 ( V_107 ) ;
F_58 () ;
V_107 = F_55 ( V_106 -> V_120 ) ;
V_102 = V_106 -> V_123 ;
}
if ( ! V_107 )
goto V_112;
V_101 = F_59 ( V_107 ) ;
F_58 () ;
V_102 ++ ;
if ( V_101 -> V_120 ) {
F_54 ( L_20 , V_102 ) ;
goto V_118;
}
V_112:
F_54 ( L_21 , V_108 ) ;
if ( V_108 <= 0 ) {
F_38 ( L_22 ) ;
return false ;
}
V_108 -- ;
V_10 = V_103 [ V_108 ] . V_10 ;
V_101 = V_103 [ V_108 ] . V_101 ;
V_102 = V_103 [ V_108 ] . V_102 + 1 ;
F_54 ( L_23 , V_10 -> V_59 , V_102 ) ;
goto V_118;
V_110:
V_4 = F_62 ( V_56 -> V_81 ) ;
F_63 ( V_4 ) ;
if ( ! ( V_56 -> V_70 & V_124 ) ) {
V_4 -> V_125 = V_56 -> V_86 . V_87 ;
V_10 -> V_125 = V_56 -> V_86 . V_87 ;
while ( V_108 > 0 )
V_103 [ -- V_108 ] . V_10 -> V_125 = V_56 -> V_86 . V_87 ;
}
F_38 ( L_24 ) ;
return true ;
}
T_8 F_64 ( T_8 V_126 ,
struct V_76 * V_56 )
{
struct V_4 * V_10 ;
long V_127 ;
V_56 -> V_99 = F_45 ;
V_56 -> V_92 = F_65 ( V_126 ) ;
V_56 -> V_81 = F_43 ( - V_128 ) ;
V_10 = F_62 ( V_126 ) ;
F_63 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_43 ( - V_129 ) ;
if ( ! ( V_56 -> V_70 & V_91 ) ) {
V_127 = F_46 ( V_126 , V_56 -> V_68 , V_93 ) ;
if ( V_127 < 0 )
return F_43 ( V_127 ) ;
}
F_66 () ;
V_56 -> V_86 = F_67 () ;
if ( F_51 ( V_10 , V_56 ) )
F_68 ( F_62 ( V_56 -> V_81 ) ) ;
F_69 () ;
return V_56 -> V_81 ;
}
T_8 F_70 ( T_8 V_10 ,
struct V_130 * type ,
const char * V_11 )
{
struct V_76 V_56 = {
. V_26 . type = type ,
. V_26 . V_11 = V_11 ,
. V_68 = F_71 () ,
. V_73 . V_90 = F_44 ,
. V_73 . V_74 = V_11 ,
. V_73 . V_97 = V_98 ,
. V_70 = V_78 ,
} ;
T_8 V_4 ;
int V_57 ;
if ( type -> V_131 ) {
V_57 = type -> V_131 ( & V_56 . V_73 ) ;
if ( V_57 < 0 )
return F_43 ( V_57 ) ;
}
V_4 = F_64 ( V_10 , & V_56 ) ;
if ( type -> V_132 )
type -> V_132 ( & V_56 . V_73 ) ;
return V_4 ;
}
T_8 F_72 ( T_8 V_126 ,
const struct V_25 * V_26 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_62 ( V_126 ) ;
F_33 ( L_16 ,
V_10 -> V_59 , V_26 -> type -> V_58 , V_26 -> V_11 ) ;
V_5 = F_50 ( & V_10 -> V_21 , & V_51 ,
V_26 ) ;
if ( V_5 )
goto V_110;
F_38 ( L_25 ) ;
return NULL ;
V_110:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_70 & ( ( 1 << V_79 ) |
( 1 << V_80 ) ) ) {
F_38 ( L_26 ) ;
return NULL ;
}
F_68 ( V_4 ) ;
F_38 ( L_27 , V_4 -> V_59 ) ;
return F_47 ( V_4 , F_65 ( V_126 ) ) ;
}
struct V_4 * F_73 ( const char * V_58 , bool V_133 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_58 )
return F_43 ( - V_20 ) ;
V_8 = F_5 ( V_58 ) ;
F_74 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_75 (keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if ( ! F_76 ( F_77 () , V_10 -> V_134 -> V_66 ) )
continue;
if ( F_78 ( V_80 , & V_10 -> V_70 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_58 ) != 0 )
continue;
if ( ! V_133 &&
F_79 ( F_47 ( V_10 , 0 ) ,
V_93 ) < 0 )
continue;
if ( ! F_80 ( & V_10 -> V_135 ) )
continue;
V_10 -> V_125 = F_67 () . V_87 ;
goto V_136;
}
}
V_10 = F_43 ( - V_137 ) ;
V_136:
F_81 ( & V_12 ) ;
return V_10 ;
}
static int F_82 ( const void * V_5 ,
void * V_75 )
{
struct V_76 * V_56 = V_75 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_33 ( L_8 , V_4 -> V_59 ) ;
if ( V_4 != V_56 -> V_73 . V_74 )
return 0 ;
V_56 -> V_81 = F_43 ( - V_138 ) ;
return 1 ;
}
static int F_83 ( struct V_4 * V_139 , struct V_4 * V_140 )
{
struct V_76 V_56 = {
. V_26 = V_139 -> V_26 ,
. V_73 . V_74 = V_139 ,
. V_73 . V_97 = V_98 ,
. V_99 = F_82 ,
. V_70 = ( V_141 |
V_124 |
V_91 |
V_121 ) ,
} ;
F_66 () ;
F_51 ( V_140 , & V_56 ) ;
F_69 () ;
return F_84 ( V_56 . V_81 ) == - V_128 ? 0 : F_84 ( V_56 . V_81 ) ;
}
int F_85 ( struct V_4 * V_10 ,
const struct V_25 * V_26 ,
struct V_142 * * V_143 )
__acquires( &keyring->sem
int F_86 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_83 ( V_10 , V_4 ) ;
return 0 ;
}
void F_87 ( struct V_4 * V_4 , struct V_142 * * V_143 )
{
F_68 ( V_4 ) ;
F_88 ( * V_143 , F_4 ( V_4 ) ) ;
F_89 ( * V_143 ) ;
* V_143 = NULL ;
}
void F_90 ( struct V_4 * V_10 ,
const struct V_25 * V_26 ,
struct V_142 * V_144 )
__releases( &keyring->sem
int F_91 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_142 * V_144 ;
int V_57 ;
F_33 ( L_28 , V_10 -> V_59 , F_92 ( & V_10 -> V_135 ) ) ;
F_63 ( V_10 ) ;
F_63 ( V_4 ) ;
if ( F_78 ( V_145 , & V_10 -> V_70 ) &&
! F_78 ( V_146 , & V_4 -> V_70 ) )
return - V_147 ;
V_57 = F_85 ( V_10 , & V_4 -> V_26 , & V_144 ) ;
if ( V_57 == 0 ) {
F_54 ( L_29 , V_10 -> V_59 , F_92 ( & V_10 -> V_135 ) ) ;
V_57 = F_86 ( V_10 , V_4 ) ;
if ( V_57 == 0 )
F_87 ( V_4 , & V_144 ) ;
F_90 ( V_10 , & V_4 -> V_26 , V_144 ) ;
}
F_38 ( L_30 , V_57 , V_10 -> V_59 , F_92 ( & V_10 -> V_135 ) ) ;
return V_57 ;
}
int F_93 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_142 * V_144 ;
int V_57 ;
F_63 ( V_10 ) ;
F_63 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_129 ;
F_94 ( & V_10 -> V_148 ) ;
V_144 = F_95 ( & V_10 -> V_21 , & V_51 ,
& V_4 -> V_26 ) ;
if ( F_41 ( V_144 ) ) {
V_57 = F_84 ( V_144 ) ;
goto error;
}
V_57 = - V_149 ;
if ( V_144 == NULL )
goto error;
F_89 ( V_144 ) ;
F_96 ( V_10 , V_10 -> V_19 - V_150 ) ;
V_57 = 0 ;
error:
F_97 ( & V_10 -> V_148 ) ;
return V_57 ;
}
int F_98 ( struct V_4 * V_10 )
{
struct V_142 * V_144 ;
int V_57 ;
if ( V_10 -> type != & V_6 )
return - V_129 ;
F_94 ( & V_10 -> V_148 ) ;
V_144 = F_99 ( & V_10 -> V_21 , & V_51 ) ;
if ( F_41 ( V_144 ) ) {
V_57 = F_84 ( V_144 ) ;
} else {
if ( V_144 )
F_89 ( V_144 ) ;
F_96 ( V_10 , 0 ) ;
V_57 = 0 ;
}
F_97 ( & V_10 -> V_148 ) ;
return V_57 ;
}
static void F_100 ( struct V_4 * V_10 )
{
struct V_142 * V_144 ;
V_144 = F_99 ( & V_10 -> V_21 , & V_51 ) ;
if ( ! F_41 ( V_144 ) ) {
if ( V_144 )
F_89 ( V_144 ) ;
F_96 ( V_10 , 0 ) ;
}
}
static bool F_101 ( void * V_5 , void * V_75 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_151 = V_75 ;
if ( F_102 ( V_4 , * V_151 ) )
return false ;
F_103 ( V_4 ) ;
return true ;
}
static int F_104 ( const void * V_5 , void * V_75 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_151 = V_75 ;
F_63 ( V_4 ) ;
return F_102 ( V_4 , * V_151 ) ;
}
void F_105 ( struct V_4 * V_10 , T_9 V_151 )
{
int V_81 ;
F_33 ( L_31 , V_10 -> V_59 , V_10 -> V_11 ? : L_32 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_79 ) |
( 1 << V_80 ) ) )
goto V_152;
F_66 () ;
V_81 = F_37 ( & V_10 -> V_21 ,
F_104 , & V_151 ) ;
F_69 () ;
if ( V_81 == true )
goto V_153;
V_152:
F_38 ( L_33 ) ;
return;
V_153:
F_94 ( & V_10 -> V_148 ) ;
F_106 ( & V_10 -> V_21 , & V_51 ,
F_101 , & V_151 ) ;
F_97 ( & V_10 -> V_148 ) ;
F_38 ( L_34 ) ;
}
