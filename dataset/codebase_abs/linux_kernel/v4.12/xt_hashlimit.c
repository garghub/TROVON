static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_4 * V_5 , void * V_6 , int V_7 )
{
if ( V_7 == 1 ) {
struct V_8 * V_9 = V_6 ;
V_5 -> V_10 = V_9 -> V_10 ;
V_5 -> V_11 = V_9 -> V_11 ;
V_5 -> V_12 = V_9 -> V_12 ;
V_5 -> V_13 = V_9 -> V_13 ;
V_5 -> V_14 = V_9 -> V_14 ;
V_5 -> V_15 = V_9 -> V_15 ;
V_5 -> V_16 = V_9 -> V_16 ;
V_5 -> V_17 = V_9 -> V_17 ;
V_5 -> V_18 = V_9 -> V_18 ;
} else if ( V_7 == 2 ) {
memcpy ( V_5 , V_6 , sizeof( struct V_4 ) ) ;
} else {
return - V_19 ;
}
return 0 ;
}
static inline bool F_4 ( const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
return ! memcmp ( & V_21 -> V_24 , V_23 , sizeof( V_21 -> V_24 ) ) ;
}
static T_1
F_5 ( const struct V_25 * V_26 , const struct V_22 * V_24 )
{
T_1 V_27 = F_6 ( ( const V_28 * ) V_24 ,
sizeof( * V_24 ) / sizeof( V_28 ) ,
V_26 -> V_29 ) ;
return F_7 ( V_27 , V_26 -> V_9 . V_13 ) ;
}
static struct V_20 *
F_8 ( const struct V_25 * V_26 ,
const struct V_22 * V_24 )
{
struct V_20 * V_21 ;
T_1 V_27 = F_5 ( V_26 , V_24 ) ;
if ( ! F_9 ( & V_26 -> V_27 [ V_27 ] ) ) {
F_10 (ent, &ht->hash[hash], node)
if ( F_4 ( V_21 , V_24 ) ) {
F_11 ( & V_21 -> V_30 ) ;
return V_21 ;
}
}
return NULL ;
}
static struct V_20 *
F_12 ( struct V_25 * V_26 ,
const struct V_22 * V_24 , bool * V_31 )
{
struct V_20 * V_21 ;
F_11 ( & V_26 -> V_30 ) ;
V_21 = F_8 ( V_26 , V_24 ) ;
if ( V_21 != NULL ) {
F_13 ( & V_26 -> V_30 ) ;
* V_31 = true ;
return V_21 ;
}
if ( F_14 ( ! V_26 -> V_32 ) ) {
F_15 ( & V_26 -> V_29 , sizeof( V_26 -> V_29 ) ) ;
V_26 -> V_32 = true ;
}
if ( V_26 -> V_9 . V_14 && V_26 -> V_33 >= V_26 -> V_9 . V_14 ) {
F_16 ( L_1 , V_26 -> V_9 . V_14 ) ;
V_21 = NULL ;
} else
V_21 = F_17 ( V_34 , V_35 ) ;
if ( V_21 ) {
memcpy ( & V_21 -> V_24 , V_24 , sizeof( V_21 -> V_24 ) ) ;
F_18 ( & V_21 -> V_30 ) ;
F_11 ( & V_21 -> V_30 ) ;
F_19 ( & V_21 -> V_36 , & V_26 -> V_27 [ F_5 ( V_26 , V_24 ) ] ) ;
V_26 -> V_33 ++ ;
}
F_13 ( & V_26 -> V_30 ) ;
return V_21 ;
}
static void F_20 ( struct V_37 * V_38 )
{
struct V_20 * V_21 = F_21 ( V_38 , struct V_20 , V_39 ) ;
F_22 ( V_34 , V_21 ) ;
}
static inline void
F_23 ( struct V_25 * V_26 , struct V_20 * V_21 )
{
F_24 ( & V_21 -> V_36 ) ;
F_25 ( & V_21 -> V_39 , F_20 ) ;
V_26 -> V_33 -- ;
}
static int F_26 ( struct V_2 * V_2 , struct V_4 * V_9 ,
const char * V_40 , T_2 V_41 ,
struct V_25 * * V_42 ,
int V_7 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_25 * V_43 ;
unsigned int V_13 , V_44 ;
int V_45 ;
if ( V_9 -> V_13 ) {
V_13 = V_9 -> V_13 ;
} else {
V_13 = ( V_46 << V_47 ) / 16384 /
sizeof( struct V_48 ) ;
if ( V_46 > 1024 * 1024 * 1024 / V_49 )
V_13 = 8192 ;
if ( V_13 < 16 )
V_13 = 16 ;
}
V_43 = F_27 ( sizeof( struct V_25 ) +
sizeof( struct V_48 ) * V_13 ) ;
if ( V_43 == NULL )
return - V_50 ;
* V_42 = V_43 ;
V_45 = F_3 ( & V_43 -> V_9 , ( void * ) V_9 , 2 ) ;
if ( V_45 )
return V_45 ;
V_43 -> V_9 . V_13 = V_13 ;
if ( V_43 -> V_9 . V_14 == 0 )
V_43 -> V_9 . V_14 = 8 * V_43 -> V_9 . V_13 ;
else if ( V_43 -> V_9 . V_14 < V_43 -> V_9 . V_13 )
V_43 -> V_9 . V_14 = V_43 -> V_9 . V_13 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_9 . V_13 ; V_44 ++ )
F_28 ( & V_43 -> V_27 [ V_44 ] ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_33 = 0 ;
V_43 -> V_41 = V_41 ;
V_43 -> V_32 = false ;
V_43 -> V_40 = F_29 ( V_40 , V_52 ) ;
if ( ! V_43 -> V_40 ) {
F_30 ( V_43 ) ;
return - V_50 ;
}
F_18 ( & V_43 -> V_30 ) ;
V_43 -> V_53 = F_31 ( V_40 , 0 ,
( V_41 == V_54 ) ?
V_1 -> V_55 : V_1 -> V_56 ,
( V_7 == 1 ) ? & V_57 : & V_58 ,
V_43 ) ;
if ( V_43 -> V_53 == NULL ) {
F_32 ( V_43 -> V_40 ) ;
F_30 ( V_43 ) ;
return - V_50 ;
}
V_43 -> V_2 = V_2 ;
F_33 ( & V_43 -> V_59 , V_60 ) ;
F_34 ( V_61 , & V_43 -> V_59 ,
F_35 ( V_43 -> V_9 . V_15 ) ) ;
F_36 ( & V_43 -> V_36 , & V_1 -> V_62 ) ;
return 0 ;
}
static bool F_37 ( const struct V_25 * V_26 ,
const struct V_20 * V_63 )
{
return 1 ;
}
static bool F_38 ( const struct V_25 * V_26 ,
const struct V_20 * V_63 )
{
return F_39 ( V_64 , V_63 -> V_65 ) ;
}
static void F_40 ( struct V_25 * V_26 ,
bool (* F_41)( const struct V_25 * V_26 ,
const struct V_20 * V_63 ) )
{
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_26 -> V_9 . V_13 ; V_44 ++ ) {
struct V_20 * V_66 ;
struct V_67 * V_68 ;
F_42 ( & V_26 -> V_30 ) ;
F_43 (dh, n, &ht->hash[i], node) {
if ( (* F_41)( V_26 , V_66 ) )
F_23 ( V_26 , V_66 ) ;
}
F_44 ( & V_26 -> V_30 ) ;
F_45 () ;
}
}
static void V_60 ( struct V_69 * V_70 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_70 , struct V_25 , V_59 . V_70 ) ;
F_40 ( V_26 , F_38 ) ;
F_34 ( V_61 ,
& V_26 -> V_59 , F_35 ( V_26 -> V_9 . V_15 ) ) ;
}
static void F_46 ( struct V_25 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_43 -> V_2 ) ;
struct V_71 * V_72 ;
if ( V_43 -> V_41 == V_54 )
V_72 = V_1 -> V_55 ;
else
V_72 = V_1 -> V_56 ;
if ( V_72 != NULL )
F_47 ( V_43 -> V_40 , V_72 ) ;
}
static void F_48 ( struct V_25 * V_43 )
{
F_49 ( & V_43 -> V_59 ) ;
F_46 ( V_43 ) ;
F_40 ( V_43 , F_37 ) ;
F_32 ( V_43 -> V_40 ) ;
F_30 ( V_43 ) ;
}
static struct V_25 * F_50 ( struct V_2 * V_2 ,
const char * V_40 ,
T_2 V_41 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_25 * V_43 ;
F_51 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_40 , V_43 -> V_40 ) &&
V_43 -> V_41 == V_41 ) {
V_43 -> V_51 ++ ;
return V_43 ;
}
}
return NULL ;
}
static void F_52 ( struct V_25 * V_43 )
{
F_53 ( & V_73 ) ;
if ( -- V_43 -> V_51 == 0 ) {
F_54 ( & V_43 -> V_36 ) ;
F_48 ( V_43 ) ;
}
F_55 ( & V_73 ) ;
}
static V_28 F_56 ( V_28 V_74 )
{
return ( V_74 >> V_75 ) + 1 ;
}
static T_3 F_57 ( T_3 V_76 , int V_7 )
{
T_3 V_77 = ( V_7 == 1 ) ?
V_78 : V_79 ;
T_3 V_80 = ( V_7 == 1 ) ?
V_81 : V_82 ;
if ( V_77 >= V_83 * V_80 )
return F_58 ( V_76 , F_58 ( V_77 , V_83 * V_80 ) ) ;
return V_76 * F_58 ( V_83 * V_80 , V_77 ) ;
}
static V_28 F_59 ( V_28 V_76 )
{
T_3 V_84 = V_76 ;
V_84 *= V_83 * V_85 ;
return ( V_28 ) ( V_84 >> 32 ) ;
}
static void F_60 ( struct V_20 * V_66 , unsigned long V_86 ,
V_28 V_10 , int V_7 )
{
unsigned long V_87 = V_86 - V_66 -> V_88 . V_89 ;
T_3 V_90 , V_80 ;
if ( V_87 == 0 )
return;
V_66 -> V_88 . V_89 = V_86 ;
if ( V_10 & V_91 ) {
T_3 V_92 = V_66 -> V_88 . V_93 ;
V_66 -> V_88 . V_93 += V_85 * V_87 ;
V_90 = V_85 * V_83 ;
if ( V_92 >= V_66 -> V_88 . V_93 ) {
V_66 -> V_88 . V_93 = V_90 ;
return;
}
} else {
V_80 = ( V_7 == 1 ) ?
V_81 : V_82 ;
V_66 -> V_88 . V_93 += V_87 * V_80 ;
V_90 = V_66 -> V_88 . V_94 ;
}
if ( V_66 -> V_88 . V_93 > V_90 )
V_66 -> V_88 . V_93 = V_90 ;
}
static void F_61 ( struct V_20 * V_66 ,
struct V_25 * V_43 , int V_7 )
{
V_66 -> V_88 . V_89 = V_64 ;
if ( V_43 -> V_9 . V_10 & V_91 ) {
V_66 -> V_88 . V_93 = V_85 * V_83 ;
V_66 -> V_88 . V_95 = F_59 ( V_43 -> V_9 . V_11 ) ;
V_66 -> V_88 . V_94 = V_43 -> V_9 . V_12 ;
} else {
V_66 -> V_88 . V_93 = F_57 ( V_43 -> V_9 . V_11 *
V_43 -> V_9 . V_12 , V_7 ) ;
V_66 -> V_88 . V_95 = F_57 ( V_43 -> V_9 . V_11 , V_7 ) ;
V_66 -> V_88 . V_94 = V_66 -> V_88 . V_93 ;
}
}
static inline T_4 F_62 ( T_4 V_96 , unsigned int V_97 )
{
return V_97 ? F_63 ( F_64 ( V_96 ) & ~ 0 << ( 32 - V_97 ) ) : 0 ;
}
static void F_65 ( T_4 * V_44 , unsigned int V_98 )
{
switch ( V_98 ) {
case 0 ... 31 :
V_44 [ 0 ] = F_62 ( V_44 [ 0 ] , V_98 ) ;
V_44 [ 1 ] = V_44 [ 2 ] = V_44 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_44 [ 1 ] = F_62 ( V_44 [ 1 ] , V_98 - 32 ) ;
V_44 [ 2 ] = V_44 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_44 [ 2 ] = F_62 ( V_44 [ 2 ] , V_98 - 64 ) ;
V_44 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_44 [ 3 ] = F_62 ( V_44 [ 3 ] , V_98 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_66 ( const struct V_25 * V_43 ,
struct V_22 * V_24 ,
const struct V_99 * V_100 , unsigned int V_101 )
{
T_5 V_102 [ 2 ] , * V_103 ;
T_6 V_104 ;
int V_105 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
switch ( V_43 -> V_41 ) {
case V_54 :
if ( V_43 -> V_9 . V_10 & V_106 )
V_24 -> V_107 . V_24 = F_62 ( F_67 ( V_100 ) -> V_108 ,
V_43 -> V_9 . V_18 ) ;
if ( V_43 -> V_9 . V_10 & V_109 )
V_24 -> V_107 . V_110 = F_62 ( F_67 ( V_100 ) -> V_111 ,
V_43 -> V_9 . V_17 ) ;
if ( ! ( V_43 -> V_9 . V_10 &
( V_112 | V_113 ) ) )
return 0 ;
V_104 = F_67 ( V_100 ) -> V_114 ;
break;
#if F_68 ( V_115 )
case V_116 :
{
T_5 V_117 ;
if ( V_43 -> V_9 . V_10 & V_106 ) {
memcpy ( & V_24 -> V_118 . V_24 , & F_69 ( V_100 ) -> V_108 ,
sizeof( V_24 -> V_118 . V_24 ) ) ;
F_65 ( V_24 -> V_118 . V_24 , V_43 -> V_9 . V_18 ) ;
}
if ( V_43 -> V_9 . V_10 & V_109 ) {
memcpy ( & V_24 -> V_118 . V_110 , & F_69 ( V_100 ) -> V_111 ,
sizeof( V_24 -> V_118 . V_110 ) ) ;
F_65 ( V_24 -> V_118 . V_110 , V_43 -> V_9 . V_17 ) ;
}
if ( ! ( V_43 -> V_9 . V_10 &
( V_112 | V_113 ) ) )
return 0 ;
V_104 = F_69 ( V_100 ) -> V_104 ;
V_101 = F_70 ( V_100 , sizeof( struct V_119 ) , & V_104 , & V_117 ) ;
if ( ( int ) V_101 < 0 )
return - 1 ;
break;
}
#endif
default:
F_71 () ;
return 0 ;
}
V_105 = F_72 ( V_104 ) ;
if ( V_105 >= 0 ) {
V_103 = F_73 ( V_100 , V_101 + V_105 , sizeof( V_102 ) ,
& V_102 ) ;
} else {
V_102 [ 0 ] = V_102 [ 1 ] = 0 ;
V_103 = V_102 ;
}
if ( ! V_103 )
return - 1 ;
if ( V_43 -> V_9 . V_10 & V_113 )
V_24 -> V_120 = V_103 [ 0 ] ;
if ( V_43 -> V_9 . V_10 & V_112 )
V_24 -> V_121 = V_103 [ 1 ] ;
return 0 ;
}
static V_28 F_74 ( unsigned int V_74 , struct V_20 * V_66 )
{
T_3 V_92 = F_56 ( V_74 ) ;
V_92 = V_92 * V_66 -> V_88 . V_95 ;
if ( F_14 ( V_92 > V_85 * V_83 ) )
V_92 = V_85 * V_83 ;
if ( V_66 -> V_88 . V_93 < V_92 && V_66 -> V_88 . V_94 ) {
V_66 -> V_88 . V_94 -- ;
V_66 -> V_88 . V_93 = V_85 * V_83 ;
}
return ( V_28 ) V_92 ;
}
static bool
F_75 ( const struct V_99 * V_100 , struct V_122 * V_123 ,
struct V_25 * V_43 ,
const struct V_4 * V_9 , int V_7 )
{
unsigned long V_86 = V_64 ;
struct V_20 * V_66 ;
struct V_22 V_24 ;
bool V_31 = false ;
T_3 V_95 ;
if ( F_66 ( V_43 , & V_24 , V_100 , V_123 -> V_124 ) < 0 )
goto V_125;
F_76 () ;
V_66 = F_8 ( V_43 , & V_24 ) ;
if ( V_66 == NULL ) {
V_66 = F_12 ( V_43 , & V_24 , & V_31 ) ;
if ( V_66 == NULL ) {
F_77 () ;
goto V_125;
} else if ( V_31 ) {
V_66 -> V_65 = V_86 + F_35 ( V_43 -> V_9 . V_16 ) ;
F_60 ( V_66 , V_86 , V_43 -> V_9 . V_10 , V_7 ) ;
} else {
V_66 -> V_65 = V_64 + F_35 ( V_43 -> V_9 . V_16 ) ;
F_61 ( V_66 , V_43 , V_7 ) ;
}
} else {
V_66 -> V_65 = V_86 + F_35 ( V_43 -> V_9 . V_16 ) ;
F_60 ( V_66 , V_86 , V_43 -> V_9 . V_10 , V_7 ) ;
}
if ( V_9 -> V_10 & V_91 )
V_95 = F_74 ( V_100 -> V_74 , V_66 ) ;
else
V_95 = V_66 -> V_88 . V_95 ;
if ( V_66 -> V_88 . V_93 >= V_95 ) {
V_66 -> V_88 . V_93 -= V_95 ;
F_13 ( & V_66 -> V_30 ) ;
F_77 () ;
return ! ( V_9 -> V_10 & V_126 ) ;
}
F_13 ( & V_66 -> V_30 ) ;
F_77 () ;
return V_9 -> V_10 & V_126 ;
V_125:
V_123 -> V_125 = true ;
return false ;
}
static bool
F_78 ( const struct V_99 * V_100 , struct V_122 * V_123 )
{
const struct V_127 * V_128 = V_123 -> V_129 ;
struct V_25 * V_43 = V_128 -> V_43 ;
struct V_4 V_9 = {} ;
int V_45 ;
V_45 = F_3 ( & V_9 , ( void * ) & V_128 -> V_9 , 1 ) ;
if ( V_45 )
return V_45 ;
return F_75 ( V_100 , V_123 , V_43 , & V_9 , 1 ) ;
}
static bool
F_79 ( const struct V_99 * V_100 , struct V_122 * V_123 )
{
const struct V_130 * V_128 = V_123 -> V_129 ;
struct V_25 * V_43 = V_128 -> V_43 ;
return F_75 ( V_100 , V_123 , V_43 , & V_128 -> V_9 , 2 ) ;
}
static int F_80 ( const struct V_131 * V_123 ,
struct V_25 * * V_43 ,
struct V_4 * V_9 ,
const char * V_40 , int V_7 )
{
struct V_2 * V_2 = V_123 -> V_2 ;
int V_45 ;
if ( V_9 -> V_15 == 0 || V_9 -> V_16 == 0 )
return - V_19 ;
if ( V_123 -> V_41 == V_54 ) {
if ( V_9 -> V_17 > 32 || V_9 -> V_18 > 32 )
return - V_19 ;
} else {
if ( V_9 -> V_17 > 128 || V_9 -> V_18 > 128 )
return - V_19 ;
}
if ( V_9 -> V_10 & ~ V_132 ) {
F_81 ( L_2 ,
V_9 -> V_10 ) ;
return - V_19 ;
}
if ( V_9 -> V_10 & V_91 ) {
if ( F_59 ( V_9 -> V_11 ) == 0 ) {
F_81 ( L_3 , V_9 -> V_11 ) ;
return - V_19 ;
}
} else if ( V_9 -> V_12 == 0 ||
F_57 ( V_9 -> V_11 * V_9 -> V_12 , V_7 ) <
F_57 ( V_9 -> V_11 , V_7 ) ) {
F_81 ( L_4 ,
V_9 -> V_11 , V_9 -> V_12 ) ;
return - V_133 ;
}
F_53 ( & V_73 ) ;
* V_43 = F_50 ( V_2 , V_40 , V_123 -> V_41 ) ;
if ( * V_43 == NULL ) {
V_45 = F_26 ( V_2 , V_9 , V_40 , V_123 -> V_41 ,
V_43 , V_7 ) ;
if ( V_45 < 0 ) {
F_55 ( & V_73 ) ;
return V_45 ;
}
}
F_55 ( & V_73 ) ;
return 0 ;
}
static int F_82 ( const struct V_131 * V_123 )
{
struct V_127 * V_128 = V_123 -> V_129 ;
struct V_4 V_9 = {} ;
int V_45 ;
if ( V_128 -> V_40 [ sizeof( V_128 -> V_40 ) - 1 ] != '\0' )
return - V_19 ;
V_45 = F_3 ( & V_9 , ( void * ) & V_128 -> V_9 , 1 ) ;
if ( V_45 )
return V_45 ;
return F_80 ( V_123 , & V_128 -> V_43 ,
& V_9 , V_128 -> V_40 , 1 ) ;
}
static int F_83 ( const struct V_131 * V_123 )
{
struct V_130 * V_128 = V_123 -> V_129 ;
if ( V_128 -> V_40 [ sizeof( V_128 -> V_40 ) - 1 ] != '\0' )
return - V_19 ;
return F_80 ( V_123 , & V_128 -> V_43 , & V_128 -> V_9 ,
V_128 -> V_40 , 2 ) ;
}
static void F_84 ( const struct V_134 * V_123 )
{
const struct V_127 * V_128 = V_123 -> V_129 ;
F_52 ( V_128 -> V_43 ) ;
}
static void F_85 ( const struct V_134 * V_123 )
{
const struct V_130 * V_128 = V_123 -> V_129 ;
F_52 ( V_128 -> V_43 ) ;
}
static void * F_86 ( struct V_135 * V_136 , T_7 * V_137 )
__acquires( V_138 -> V_30 )
{
struct V_25 * V_138 = V_136 -> V_139 ;
unsigned int * V_140 ;
F_42 ( & V_138 -> V_30 ) ;
if ( * V_137 >= V_138 -> V_9 . V_13 )
return NULL ;
V_140 = F_87 ( sizeof( unsigned int ) , V_35 ) ;
if ( ! V_140 )
return F_88 ( - V_50 ) ;
* V_140 = * V_137 ;
return V_140 ;
}
static void * F_89 ( struct V_135 * V_136 , void * V_141 , T_7 * V_137 )
{
struct V_25 * V_138 = V_136 -> V_139 ;
unsigned int * V_140 = V_141 ;
* V_137 = ++ ( * V_140 ) ;
if ( * V_137 >= V_138 -> V_9 . V_13 ) {
F_32 ( V_141 ) ;
return NULL ;
}
return V_140 ;
}
static void F_90 ( struct V_135 * V_136 , void * V_141 )
__releases( V_138 -> V_30 )
{
struct V_25 * V_138 = V_136 -> V_139 ;
unsigned int * V_140 = V_141 ;
if ( ! F_91 ( V_140 ) )
F_32 ( V_140 ) ;
F_44 ( & V_138 -> V_30 ) ;
}
static void F_92 ( struct V_20 * V_21 , T_2 V_41 ,
struct V_135 * V_136 )
{
switch ( V_41 ) {
case V_54 :
F_93 ( V_136 , L_5 ,
( long ) ( V_21 -> V_65 - V_64 ) / V_83 ,
& V_21 -> V_24 . V_107 . V_110 ,
F_94 ( V_21 -> V_24 . V_120 ) ,
& V_21 -> V_24 . V_107 . V_24 ,
F_94 ( V_21 -> V_24 . V_121 ) ,
V_21 -> V_88 . V_93 , V_21 -> V_88 . V_94 ,
V_21 -> V_88 . V_95 ) ;
break;
#if F_68 ( V_115 )
case V_116 :
F_93 ( V_136 , L_6 ,
( long ) ( V_21 -> V_65 - V_64 ) / V_83 ,
& V_21 -> V_24 . V_118 . V_110 ,
F_94 ( V_21 -> V_24 . V_120 ) ,
& V_21 -> V_24 . V_118 . V_24 ,
F_94 ( V_21 -> V_24 . V_121 ) ,
V_21 -> V_88 . V_93 , V_21 -> V_88 . V_94 ,
V_21 -> V_88 . V_95 ) ;
break;
#endif
default:
F_71 () ;
}
}
static int F_95 ( struct V_20 * V_21 , T_2 V_41 ,
struct V_135 * V_136 )
{
const struct V_25 * V_26 = V_136 -> V_139 ;
F_11 ( & V_21 -> V_30 ) ;
F_60 ( V_21 , V_64 , V_26 -> V_9 . V_10 , 1 ) ;
F_92 ( V_21 , V_41 , V_136 ) ;
F_13 ( & V_21 -> V_30 ) ;
return F_96 ( V_136 ) ;
}
static int F_97 ( struct V_20 * V_21 , T_2 V_41 ,
struct V_135 * V_136 )
{
const struct V_25 * V_26 = V_136 -> V_139 ;
F_11 ( & V_21 -> V_30 ) ;
F_60 ( V_21 , V_64 , V_26 -> V_9 . V_10 , 2 ) ;
F_92 ( V_21 , V_41 , V_136 ) ;
F_13 ( & V_21 -> V_30 ) ;
return F_96 ( V_136 ) ;
}
static int F_98 ( struct V_135 * V_136 , void * V_141 )
{
struct V_25 * V_138 = V_136 -> V_139 ;
unsigned int * V_140 = V_141 ;
struct V_20 * V_21 ;
if ( ! F_9 ( & V_138 -> V_27 [ * V_140 ] ) ) {
F_51 (ent, &htable->hash[*bucket], node)
if ( F_95 ( V_21 , V_138 -> V_41 , V_136 ) )
return - 1 ;
}
return 0 ;
}
static int F_99 ( struct V_135 * V_136 , void * V_141 )
{
struct V_25 * V_138 = V_136 -> V_139 ;
unsigned int * V_140 = V_141 ;
struct V_20 * V_21 ;
if ( ! F_9 ( & V_138 -> V_27 [ * V_140 ] ) ) {
F_51 (ent, &htable->hash[*bucket], node)
if ( F_97 ( V_21 , V_138 -> V_41 , V_136 ) )
return - 1 ;
}
return 0 ;
}
static int F_100 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
int V_45 = F_101 ( V_143 , & V_144 ) ;
if ( ! V_45 ) {
struct V_135 * V_145 = V_143 -> V_146 ;
V_145 -> V_139 = F_102 ( V_142 ) ;
}
return V_45 ;
}
static int F_103 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
int V_45 = F_101 ( V_143 , & V_147 ) ;
if ( ! V_45 ) {
struct V_135 * V_145 = V_143 -> V_146 ;
V_145 -> V_139 = F_102 ( V_142 ) ;
}
return V_45 ;
}
static int T_8 F_104 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_55 = F_105 ( L_7 , V_2 -> V_148 ) ;
if ( ! V_1 -> V_55 )
return - V_50 ;
#if F_68 ( V_115 )
V_1 -> V_56 = F_105 ( L_8 , V_2 -> V_148 ) ;
if ( ! V_1 -> V_56 ) {
F_47 ( L_7 , V_2 -> V_148 ) ;
return - V_50 ;
}
#endif
return 0 ;
}
static void T_9 F_106 ( struct V_2 * V_2 )
{
struct V_25 * V_43 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_53 ( & V_73 ) ;
F_51 (hinfo, &hashlimit_net->htables, node)
F_46 ( V_43 ) ;
V_1 -> V_55 = NULL ;
V_1 -> V_56 = NULL ;
F_55 ( & V_73 ) ;
F_47 ( L_7 , V_2 -> V_148 ) ;
#if F_68 ( V_115 )
F_47 ( L_8 , V_2 -> V_148 ) ;
#endif
}
static int T_8 F_107 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_28 ( & V_1 -> V_62 ) ;
return F_104 ( V_2 ) ;
}
static void T_9 F_108 ( struct V_2 * V_2 )
{
F_106 ( V_2 ) ;
}
static int T_10 F_109 ( void )
{
int V_149 ;
V_149 = F_110 ( & V_150 ) ;
if ( V_149 < 0 )
return V_149 ;
V_149 = F_111 ( V_151 ,
F_112 ( V_151 ) ) ;
if ( V_149 < 0 )
goto V_152;
V_149 = - V_50 ;
V_34 = F_113 ( L_9 ,
sizeof( struct V_20 ) , 0 , 0 ,
NULL ) ;
if ( ! V_34 ) {
F_114 ( L_10 ) ;
goto V_153;
}
return 0 ;
V_153:
F_115 ( V_151 , F_112 ( V_151 ) ) ;
V_152:
F_116 ( & V_150 ) ;
return V_149 ;
}
static void T_11 F_117 ( void )
{
F_115 ( V_151 , F_112 ( V_151 ) ) ;
F_116 ( & V_150 ) ;
F_118 () ;
F_119 ( V_34 ) ;
}
