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
static int F_11 ( struct V_4 * V_10 ,
struct V_17 * V_18 )
{
int V_19 ;
V_19 = - V_20 ;
if ( V_18 -> V_21 == 0 ) {
F_12 ( & V_10 -> V_22 ) ;
F_6 ( V_10 ) ;
V_19 = 0 ;
}
return V_19 ;
}
static T_1 F_13 ( T_1 V_2 , T_2 V_23 )
{
T_1 V_24 = ( T_1 ) ( T_2 ) ( V_2 >> 32 ) * V_23 ;
T_1 V_25 = ( T_1 ) ( T_2 ) ( V_2 ) * V_23 ;
return V_25 + ( ( T_1 ) ( T_2 ) V_24 << 32 ) + ( T_2 ) ( V_24 >> 32 ) ;
}
static unsigned long F_14 ( const struct V_26 * V_27 )
{
const unsigned V_28 = V_29 ;
const unsigned long V_30 = V_31 ;
const char * V_11 = V_27 -> V_11 ;
unsigned long V_32 , type ;
T_2 V_33 ;
T_1 V_34 ;
int V_35 , V_36 = V_27 -> V_36 ;
type = ( unsigned long ) V_27 -> type ;
V_34 = F_13 ( type , V_36 + 13 ) ;
V_34 = F_13 ( V_34 , 9207 ) ;
for (; ; ) {
V_35 = V_36 ;
if ( V_35 <= 0 )
break;
if ( V_35 > 4 )
V_35 = 4 ;
V_33 = 0 ;
memcpy ( & V_33 , V_11 , V_35 ) ;
V_11 += V_35 ;
V_36 -= V_35 ;
V_34 = F_13 ( V_34 , V_33 ) ;
V_34 = F_13 ( V_34 , 9207 ) ;
}
V_32 = V_34 ;
if ( V_37 == 32 )
V_32 ^= V_34 >> 32 ;
if ( V_27 -> type != & V_6 && ( V_32 & V_30 ) == 0 )
return V_32 | ( V_32 >> ( V_37 - V_28 ) ) | 1 ;
if ( V_27 -> type == & V_6 && ( V_32 & V_30 ) != 0 )
return ( V_32 + ( V_32 << V_28 ) ) & ~ V_30 ;
return V_32 ;
}
static unsigned long F_15 ( const void * V_38 , int V_39 )
{
const struct V_26 * V_27 = V_38 ;
unsigned long V_40 = 0 ;
long V_41 = 0 ;
int V_36 = V_27 -> V_36 , V_35 = sizeof( V_40 ) ;
V_39 /= V_37 ;
switch ( V_39 ) {
case 0 :
return F_14 ( V_27 ) ;
case 1 :
return ( ( unsigned long ) V_27 -> type << 8 ) | V_36 ;
case 2 :
if ( V_36 == 0 )
return ( V_42 ) ( ( unsigned long ) V_27 -> type >>
( V_37 - 8 ) ) ;
V_35 -- ;
V_41 = 1 ;
default:
V_41 += sizeof( V_40 ) - 1 ;
V_41 += ( V_39 - 3 ) * sizeof( V_40 ) ;
if ( V_41 >= V_36 )
return 0 ;
V_36 -= V_41 ;
if ( V_36 > V_35 )
V_36 = V_35 ;
V_41 += V_36 ;
do {
V_40 <<= 8 ;
V_40 |= ( ( V_42 * ) V_27 -> V_11 ) [ -- V_41 ] ;
} while ( -- V_36 > 0 );
if ( V_39 == 2 ) {
V_40 <<= 8 ;
V_40 |= ( V_42 ) ( ( unsigned long ) V_27 -> type >>
( V_37 - 8 ) ) ;
}
return V_40 ;
}
}
static unsigned long F_16 ( const void * V_5 , int V_39 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return F_15 ( & V_4 -> V_27 , V_39 ) ;
}
static bool F_17 ( const void * V_5 , const void * V_38 )
{
const struct V_26 * V_27 = V_38 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
return V_4 -> V_27 . type == V_27 -> type &&
V_4 -> V_27 . V_36 == V_27 -> V_36 &&
memcmp ( V_4 -> V_27 . V_11 , V_27 -> V_11 ,
V_27 -> V_36 ) == 0 ;
}
static int F_18 ( const void * V_5 , const void * V_38 )
{
const struct V_4 * V_43 = F_2 ( V_5 ) ;
const struct V_26 * V_44 = & V_43 -> V_27 ;
const struct V_26 * V_45 = V_38 ;
unsigned long V_46 , V_47 ;
int V_39 , V_48 ;
V_39 = 0 ;
V_46 = F_14 ( V_44 ) ;
V_47 = F_14 ( V_45 ) ;
if ( ( V_46 ^ V_47 ) != 0 )
goto V_49;
V_39 += V_37 / 8 ;
V_46 = V_44 -> V_36 ;
V_47 = V_45 -> V_36 ;
if ( ( V_46 ^ V_47 ) != 0 )
goto V_49;
V_39 ++ ;
V_46 = ( unsigned long ) V_44 -> type ;
V_47 = ( unsigned long ) V_45 -> type ;
if ( ( V_46 ^ V_47 ) != 0 )
goto V_49;
V_39 += sizeof( unsigned long ) ;
if ( V_44 -> V_36 == 0 )
goto V_50;
V_48 = 0 ;
if ( ( ( unsigned long ) V_44 -> V_11 | ( unsigned long ) V_45 -> V_11 ) &
(sizeof( unsigned long ) - 1 ) ) {
do {
V_46 = * ( unsigned long * ) ( V_44 -> V_11 + V_48 ) ;
V_47 = * ( unsigned long * ) ( V_45 -> V_11 + V_48 ) ;
if ( ( V_46 ^ V_47 ) != 0 )
goto V_51;
V_48 += sizeof( unsigned long ) ;
} while ( V_48 < ( V_44 -> V_36 & (sizeof( unsigned long ) - 1 ) ) );
}
for (; V_48 < V_44 -> V_36 ; V_48 ++ ) {
V_46 = * ( unsigned char * ) ( V_44 -> V_11 + V_48 ) ;
V_47 = * ( unsigned char * ) ( V_45 -> V_11 + V_48 ) ;
if ( ( V_46 ^ V_47 ) != 0 )
goto V_51;
}
V_50:
return - 1 ;
V_51:
V_39 += V_48 ;
V_49:
V_48 = V_39 * 8 + F_19 ( V_46 ^ V_47 ) ;
return V_48 ;
}
static void F_20 ( void * V_5 )
{
F_21 ( F_2 ( V_5 ) ) ;
}
static void F_22 ( struct V_4 * V_10 )
{
if ( V_10 -> V_11 ) {
F_7 ( & V_12 ) ;
if ( V_10 -> V_15 . V_16 . V_14 != NULL &&
! F_23 ( & V_10 -> V_15 . V_16 ) )
F_24 ( & V_10 -> V_15 . V_16 ) ;
F_10 ( & V_12 ) ;
}
F_25 ( & V_10 -> V_22 , & V_52 ) ;
}
static void F_26 ( const struct V_4 * V_10 , struct V_53 * V_54 )
{
if ( V_10 -> V_11 )
F_27 ( V_54 , V_10 -> V_11 ) ;
else
F_27 ( V_54 , L_1 ) ;
if ( F_28 ( V_10 ) ) {
if ( V_10 -> V_22 . V_55 != 0 )
F_29 ( V_54 , L_2 , V_10 -> V_22 . V_55 ) ;
else
F_27 ( V_54 , L_3 ) ;
}
}
static int F_30 ( const void * V_5 , void * V_38 )
{
struct V_56 * V_57 = V_38 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
int V_19 ;
F_31 ( L_4 ,
V_4 -> type -> V_58 , V_4 -> V_59 , V_57 -> V_60 , V_57 -> V_61 ) ;
if ( V_57 -> V_60 >= V_57 -> V_61 )
return 1 ;
V_19 = F_32 ( V_4 -> V_59 , V_57 -> V_62 ) ;
if ( V_19 < 0 )
return V_19 ;
V_57 -> V_62 ++ ;
V_57 -> V_60 += sizeof( V_4 -> V_59 ) ;
return 0 ;
}
static long F_33 ( const struct V_4 * V_10 ,
char T_3 * V_62 , T_4 V_63 )
{
struct V_56 V_57 ;
unsigned long V_64 ;
int V_19 ;
F_31 ( L_5 , F_34 ( V_10 ) , V_63 ) ;
if ( V_63 & ( sizeof( V_65 ) - 1 ) )
return - V_20 ;
V_64 = V_10 -> V_22 . V_55 ;
if ( V_64 == 0 )
return 0 ;
V_57 . V_61 = V_64 * sizeof( V_65 ) ;
if ( ! V_62 || ! V_63 )
return V_57 . V_61 ;
if ( V_63 > V_57 . V_61 )
V_57 . V_61 = V_63 ;
V_57 . V_62 = ( V_65 T_3 * ) V_62 ;
V_57 . V_60 = 0 ;
V_19 = F_35 ( & V_10 -> V_22 , F_30 , & V_57 ) ;
if ( V_19 < 0 ) {
F_36 ( L_6 , V_19 ) ;
return V_19 ;
}
F_36 ( L_7 , V_57 . V_60 ) ;
return V_57 . V_60 ;
}
struct V_4 * F_37 ( const char * V_11 , T_5 V_66 , T_6 V_67 ,
const struct V_68 * V_68 , T_7 V_69 ,
unsigned long V_70 , struct V_4 * V_71 )
{
struct V_4 * V_10 ;
int V_19 ;
V_10 = F_38 ( & V_6 , V_11 ,
V_66 , V_67 , V_68 , V_69 , V_70 ) ;
if ( ! F_39 ( V_10 ) ) {
V_19 = F_40 ( V_10 , NULL , 0 , V_71 , NULL ) ;
if ( V_19 < 0 ) {
F_21 ( V_10 ) ;
V_10 = F_41 ( V_19 ) ;
}
}
return V_10 ;
}
static int F_42 ( const void * V_5 , void * V_72 )
{
struct V_73 * V_57 = V_72 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
unsigned long V_74 = V_4 -> V_70 ;
F_31 ( L_8 , V_4 -> V_59 ) ;
if ( V_4 -> type != V_57 -> V_27 . type ) {
F_36 ( L_9 ) ;
return 0 ;
}
if ( V_57 -> V_70 & V_75 ) {
if ( V_74 & ( ( 1 << V_76 ) |
( 1 << V_77 ) ) ) {
V_57 -> V_78 = F_41 ( - V_79 ) ;
F_36 ( L_10 , V_57 -> V_80 ) ;
goto V_81;
}
if ( V_4 -> V_82 && V_57 -> V_83 . V_84 >= V_4 -> V_82 ) {
V_57 -> V_78 = F_41 ( - V_85 ) ;
F_36 ( L_11 , V_57 -> V_80 ) ;
goto V_81;
}
}
if ( ! V_57 -> V_86 ( V_4 , V_57 -> V_87 ) ) {
F_36 ( L_12 ) ;
return 0 ;
}
if ( ! ( V_57 -> V_70 & V_88 ) &&
F_43 ( F_44 ( V_4 , V_57 -> V_89 ) ,
V_57 -> V_68 , V_90 ) < 0 ) {
V_57 -> V_78 = F_41 ( - V_91 ) ;
F_36 ( L_13 , V_57 -> V_80 ) ;
goto V_81;
}
if ( V_57 -> V_70 & V_75 ) {
if ( V_74 & ( 1 << V_92 ) ) {
F_45 () ;
V_57 -> V_78 = F_41 ( V_4 -> V_15 . V_93 ) ;
F_36 ( L_14 , V_57 -> V_80 ) ;
goto V_81;
}
}
V_57 -> V_78 = F_44 ( V_4 , V_57 -> V_89 ) ;
F_36 ( L_15 ) ;
return 1 ;
V_81:
return V_57 -> V_80 ;
}
static int F_46 ( struct V_4 * V_10 , struct V_73 * V_57 )
{
if ( ( V_57 -> V_70 & V_94 ) ==
V_95 ) {
const void * V_5 ;
V_5 = F_47 ( & V_10 -> V_22 ,
& V_52 ,
& V_57 -> V_27 ) ;
return V_5 ? V_57 -> V_96 ( V_5 , V_57 ) : 0 ;
}
return F_35 ( & V_10 -> V_22 , V_57 -> V_96 , V_57 ) ;
}
static bool F_48 ( struct V_4 * V_10 ,
struct V_73 * V_57 )
{
struct {
struct V_4 * V_10 ;
struct V_97 * V_98 ;
int V_99 ;
} V_100 [ V_101 ] ;
struct V_102 * V_103 ;
struct V_97 * V_98 ;
struct V_1 * V_104 ;
struct V_4 * V_4 ;
int V_105 = 0 , V_99 ;
F_31 ( L_16 ,
V_10 -> V_59 ,
V_57 -> V_27 . type -> V_58 ,
V_57 -> V_27 . V_11 ) ;
if ( V_57 -> V_27 . V_11 )
V_57 -> V_27 . V_36 = strlen ( V_57 -> V_27 . V_11 ) ;
if ( V_57 -> V_70 & V_106 ||
F_17 ( V_10 , & V_57 -> V_27 ) ) {
V_57 -> V_80 = 2 ;
V_57 -> V_70 |= V_75 ;
switch ( V_57 -> V_96 ( F_4 ( V_10 ) , V_57 ) ) {
case 1 :
goto V_107;
case 2 :
return false ;
default:
break;
}
}
V_57 -> V_80 = 0 ;
if ( V_57 -> V_70 & V_108 )
V_57 -> V_70 &= ~ V_75 ;
V_109:
F_49 ( L_17 , V_10 -> V_59 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_76 ) |
( 1 << V_77 ) ) )
goto V_110;
if ( F_46 ( V_10 , V_57 ) )
goto V_107;
V_104 = F_50 ( V_10 -> V_22 . V_111 ) ;
if ( ! V_104 )
goto V_110;
if ( F_51 ( V_104 ) ) {
V_103 = F_52 ( V_104 ) ;
F_53 () ;
if ( ( V_103 -> V_27 [ 0 ] & V_31 ) != 0 )
goto V_110;
V_104 = F_50 ( V_103 -> V_112 ) ;
V_98 = F_54 ( V_104 ) ;
goto V_113;
}
V_98 = F_54 ( V_104 ) ;
F_53 () ;
V_104 = V_98 -> V_114 [ 0 ] ;
if ( ! F_55 ( V_104 ) )
goto V_113;
V_115:
F_49 ( L_18 ) ;
if ( F_51 ( V_104 ) ) {
V_103 = F_52 ( V_104 ) ;
F_53 () ;
V_104 = F_50 ( V_103 -> V_112 ) ;
F_56 ( ! F_57 ( V_104 ) ) ;
}
V_98 = F_54 ( V_104 ) ;
V_113:
F_49 ( L_19 ) ;
F_53 () ;
V_99 = 0 ;
V_116:
for (; V_99 < V_117 ; V_99 ++ ) {
V_104 = F_50 ( V_98 -> V_114 [ V_99 ] ) ;
if ( F_55 ( V_104 ) && V_98 -> V_118 )
goto V_115;
if ( ! F_1 ( V_104 ) )
continue;
V_4 = F_2 ( V_104 ) ;
if ( V_105 >= V_101 ) {
if ( V_57 -> V_70 & V_119 ) {
V_57 -> V_78 = F_41 ( - V_120 ) ;
return false ;
}
goto V_110;
}
if ( ! ( V_57 -> V_70 & V_88 ) &&
F_43 ( F_44 ( V_4 , V_57 -> V_89 ) ,
V_57 -> V_68 , V_90 ) < 0 )
continue;
V_100 [ V_105 ] . V_10 = V_10 ;
V_100 [ V_105 ] . V_98 = V_98 ;
V_100 [ V_105 ] . V_99 = V_99 ;
V_105 ++ ;
V_10 = V_4 ;
goto V_109;
}
V_104 = F_50 ( V_98 -> V_118 ) ;
V_99 = V_98 -> V_121 ;
if ( V_104 && F_51 ( V_104 ) ) {
V_103 = F_52 ( V_104 ) ;
F_53 () ;
V_104 = F_50 ( V_103 -> V_118 ) ;
V_99 = V_103 -> V_121 ;
}
if ( ! V_104 )
goto V_110;
V_98 = F_54 ( V_104 ) ;
F_53 () ;
V_99 ++ ;
if ( V_98 -> V_118 ) {
F_49 ( L_20 , V_99 ) ;
goto V_116;
}
V_110:
F_49 ( L_21 , V_105 ) ;
if ( V_105 <= 0 ) {
F_36 ( L_22 ) ;
return false ;
}
V_105 -- ;
V_10 = V_100 [ V_105 ] . V_10 ;
V_98 = V_100 [ V_105 ] . V_98 ;
V_99 = V_100 [ V_105 ] . V_99 + 1 ;
F_49 ( L_23 , V_10 -> V_59 , V_99 ) ;
goto V_116;
V_107:
V_4 = F_58 ( V_57 -> V_78 ) ;
F_59 ( V_4 ) ;
if ( ! ( V_57 -> V_70 & V_122 ) ) {
V_4 -> V_123 = V_57 -> V_83 . V_84 ;
V_10 -> V_123 = V_57 -> V_83 . V_84 ;
while ( V_105 > 0 )
V_100 [ -- V_105 ] . V_10 -> V_123 = V_57 -> V_83 . V_84 ;
}
F_36 ( L_24 ) ;
return true ;
}
T_8 F_60 ( T_8 V_124 ,
struct V_73 * V_57 )
{
struct V_4 * V_10 ;
long V_125 ;
V_57 -> V_96 = F_42 ;
V_57 -> V_89 = F_61 ( V_124 ) ;
V_57 -> V_78 = F_41 ( - V_126 ) ;
V_10 = F_58 ( V_124 ) ;
F_59 ( V_10 ) ;
if ( V_10 -> type != & V_6 )
return F_41 ( - V_127 ) ;
if ( ! ( V_57 -> V_70 & V_88 ) ) {
V_125 = F_43 ( V_124 , V_57 -> V_68 , V_90 ) ;
if ( V_125 < 0 )
return F_41 ( V_125 ) ;
}
F_62 () ;
V_57 -> V_83 = F_63 () ;
if ( F_48 ( V_10 , V_57 ) )
F_64 ( F_58 ( V_57 -> V_78 ) ) ;
F_65 () ;
return V_57 -> V_78 ;
}
T_8 F_66 ( T_8 V_10 ,
struct V_128 * type ,
const char * V_11 )
{
struct V_73 V_57 = {
. V_27 . type = type ,
. V_27 . V_11 = V_11 ,
. V_68 = F_67 () ,
. V_86 = type -> V_86 ,
. V_87 = V_11 ,
. V_70 = ( type -> V_129 |
V_75 ) ,
} ;
if ( ! V_57 . V_86 )
return F_41 ( - V_130 ) ;
return F_60 ( V_10 , & V_57 ) ;
}
T_8 F_68 ( T_8 V_124 ,
const struct V_26 * V_27 )
{
struct V_4 * V_10 , * V_4 ;
const void * V_5 ;
V_10 = F_58 ( V_124 ) ;
F_31 ( L_16 ,
V_10 -> V_59 , V_27 -> type -> V_58 , V_27 -> V_11 ) ;
V_5 = F_47 ( & V_10 -> V_22 , & V_52 ,
V_27 ) ;
if ( V_5 )
goto V_107;
F_36 ( L_25 ) ;
return NULL ;
V_107:
V_4 = F_2 ( V_5 ) ;
if ( V_4 -> V_70 & ( ( 1 << V_76 ) |
( 1 << V_77 ) ) ) {
F_36 ( L_26 ) ;
return NULL ;
}
F_64 ( V_4 ) ;
F_36 ( L_27 , V_4 -> V_59 ) ;
return F_44 ( V_4 , F_61 ( V_124 ) ) ;
}
struct V_4 * F_69 ( const char * V_58 , bool V_131 )
{
struct V_4 * V_10 ;
int V_8 ;
if ( ! V_58 )
return F_41 ( - V_20 ) ;
V_8 = F_5 ( V_58 ) ;
F_70 ( & V_12 ) ;
if ( V_13 [ V_8 ] . V_14 ) {
F_71 (keyring,
&keyring_name_hash[bucket],
type_data.link
) {
if ( ! F_72 ( F_73 () , V_10 -> V_132 -> V_66 ) )
continue;
if ( F_74 ( V_77 , & V_10 -> V_70 ) )
continue;
if ( strcmp ( V_10 -> V_11 , V_58 ) != 0 )
continue;
if ( ! V_131 &&
F_75 ( F_44 ( V_10 , 0 ) ,
V_90 ) < 0 )
continue;
if ( ! F_76 ( & V_10 -> V_133 ) )
continue;
V_10 -> V_123 = F_63 () . V_84 ;
goto V_134;
}
}
V_10 = F_41 ( - V_130 ) ;
V_134:
F_77 ( & V_12 ) ;
return V_10 ;
}
static int F_78 ( const void * V_5 ,
void * V_72 )
{
struct V_73 * V_57 = V_72 ;
const struct V_4 * V_4 = F_2 ( V_5 ) ;
F_31 ( L_8 , V_4 -> V_59 ) ;
if ( V_4 != V_57 -> V_87 )
return 0 ;
V_57 -> V_78 = F_41 ( - V_135 ) ;
return 1 ;
}
static int F_79 ( struct V_4 * V_136 , struct V_4 * V_137 )
{
struct V_73 V_57 = {
. V_27 = V_136 -> V_27 ,
. V_87 = V_136 ,
. V_96 = F_78 ,
. V_70 = ( V_95 |
V_108 |
V_122 |
V_88 |
V_119 ) ,
} ;
F_62 () ;
F_48 ( V_137 , & V_57 ) ;
F_65 () ;
return F_80 ( V_57 . V_78 ) == - V_126 ? 0 : F_80 ( V_57 . V_78 ) ;
}
int F_81 ( struct V_4 * V_10 ,
const struct V_26 * V_27 ,
struct V_138 * * V_139 )
__acquires( &keyring->sem
int F_82 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
if ( V_4 -> type == & V_6 )
return F_79 ( V_10 , V_4 ) ;
return 0 ;
}
void F_83 ( struct V_4 * V_4 , struct V_138 * * V_139 )
{
F_64 ( V_4 ) ;
F_84 ( * V_139 , F_4 ( V_4 ) ) ;
F_85 ( * V_139 ) ;
* V_139 = NULL ;
}
void F_86 ( struct V_4 * V_10 ,
const struct V_26 * V_27 ,
struct V_138 * V_140 )
__releases( &keyring->sem
int F_87 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_138 * V_140 ;
int V_19 ;
F_31 ( L_28 , V_10 -> V_59 , F_88 ( & V_10 -> V_133 ) ) ;
F_59 ( V_10 ) ;
F_59 ( V_4 ) ;
if ( F_74 ( V_141 , & V_10 -> V_70 ) &&
! F_74 ( V_142 , & V_4 -> V_70 ) )
return - V_143 ;
V_19 = F_81 ( V_10 , & V_4 -> V_27 , & V_140 ) ;
if ( V_19 == 0 ) {
F_49 ( L_29 , V_10 -> V_59 , F_88 ( & V_10 -> V_133 ) ) ;
V_19 = F_82 ( V_10 , V_4 ) ;
if ( V_19 == 0 )
F_83 ( V_4 , & V_140 ) ;
F_86 ( V_10 , & V_4 -> V_27 , V_140 ) ;
}
F_36 ( L_30 , V_19 , V_10 -> V_59 , F_88 ( & V_10 -> V_133 ) ) ;
return V_19 ;
}
int F_89 ( struct V_4 * V_10 , struct V_4 * V_4 )
{
struct V_138 * V_140 ;
int V_19 ;
F_59 ( V_10 ) ;
F_59 ( V_4 ) ;
if ( V_10 -> type != & V_6 )
return - V_127 ;
F_90 ( & V_10 -> V_144 ) ;
V_140 = F_91 ( & V_10 -> V_22 , & V_52 ,
& V_4 -> V_27 ) ;
if ( F_39 ( V_140 ) ) {
V_19 = F_80 ( V_140 ) ;
goto error;
}
V_19 = - V_145 ;
if ( V_140 == NULL )
goto error;
F_85 ( V_140 ) ;
F_92 ( V_10 , V_10 -> V_21 - V_146 ) ;
V_19 = 0 ;
error:
F_93 ( & V_10 -> V_144 ) ;
return V_19 ;
}
int F_94 ( struct V_4 * V_10 )
{
struct V_138 * V_140 ;
int V_19 ;
if ( V_10 -> type != & V_6 )
return - V_127 ;
F_90 ( & V_10 -> V_144 ) ;
V_140 = F_95 ( & V_10 -> V_22 , & V_52 ) ;
if ( F_39 ( V_140 ) ) {
V_19 = F_80 ( V_140 ) ;
} else {
if ( V_140 )
F_85 ( V_140 ) ;
F_92 ( V_10 , 0 ) ;
V_19 = 0 ;
}
F_93 ( & V_10 -> V_144 ) ;
return V_19 ;
}
static void F_96 ( struct V_4 * V_10 )
{
struct V_138 * V_140 ;
V_140 = F_95 ( & V_10 -> V_22 , & V_52 ) ;
if ( ! F_39 ( V_140 ) ) {
if ( V_140 )
F_85 ( V_140 ) ;
F_92 ( V_10 , 0 ) ;
}
}
static bool F_97 ( void * V_5 , void * V_72 )
{
struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_147 = V_72 ;
if ( F_98 ( V_4 , * V_147 ) )
return false ;
F_99 ( V_4 ) ;
return true ;
}
static int F_100 ( const void * V_5 , void * V_72 )
{
const struct V_4 * V_4 = F_2 ( V_5 ) ;
T_9 * V_147 = V_72 ;
F_59 ( V_4 ) ;
return F_98 ( V_4 , * V_147 ) ;
}
void F_101 ( struct V_4 * V_10 , T_9 V_147 )
{
int V_78 ;
F_31 ( L_31 , V_10 -> V_59 , V_10 -> V_11 ? : L_32 ) ;
if ( V_10 -> V_70 & ( ( 1 << V_76 ) |
( 1 << V_77 ) ) )
goto V_148;
F_62 () ;
V_78 = F_35 ( & V_10 -> V_22 ,
F_100 , & V_147 ) ;
F_65 () ;
if ( V_78 == true )
goto V_149;
V_148:
F_36 ( L_33 ) ;
return;
V_149:
F_90 ( & V_10 -> V_144 ) ;
F_102 ( & V_10 -> V_22 , & V_52 ,
F_97 , & V_147 ) ;
F_93 ( & V_10 -> V_144 ) ;
F_36 ( L_34 ) ;
}
