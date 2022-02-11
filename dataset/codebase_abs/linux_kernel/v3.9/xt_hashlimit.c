static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline bool F_3 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return ! memcmp ( & V_5 -> V_8 , V_7 , sizeof( V_5 -> V_8 ) ) ;
}
static T_1
F_4 ( const struct V_9 * V_10 , const struct V_6 * V_8 )
{
T_1 V_11 = F_5 ( ( const V_12 * ) V_8 ,
sizeof( * V_8 ) / sizeof( V_12 ) ,
V_10 -> V_13 ) ;
return ( ( V_14 ) V_11 * V_10 -> V_15 . V_16 ) >> 32 ;
}
static struct V_4 *
F_6 ( const struct V_9 * V_10 ,
const struct V_6 * V_8 )
{
struct V_4 * V_5 ;
T_1 V_11 = F_4 ( V_10 , V_8 ) ;
if ( ! F_7 ( & V_10 -> V_11 [ V_11 ] ) ) {
F_8 (ent, &ht->hash[hash], node)
if ( F_3 ( V_5 , V_8 ) ) {
F_9 ( & V_5 -> V_17 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_4 *
F_10 ( struct V_9 * V_10 ,
const struct V_6 * V_8 , bool * V_18 )
{
struct V_4 * V_5 ;
F_9 ( & V_10 -> V_17 ) ;
V_5 = F_6 ( V_10 , V_8 ) ;
if ( V_5 != NULL ) {
F_11 ( & V_10 -> V_17 ) ;
* V_18 = true ;
return V_5 ;
}
if ( F_12 ( ! V_10 -> V_19 ) ) {
F_13 ( & V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
V_10 -> V_19 = true ;
}
if ( V_10 -> V_15 . V_20 && V_10 -> V_21 >= V_10 -> V_15 . V_20 ) {
F_14 ( L_1 , V_10 -> V_15 . V_20 ) ;
V_5 = NULL ;
} else
V_5 = F_15 ( V_22 , V_23 ) ;
if ( V_5 ) {
memcpy ( & V_5 -> V_8 , V_8 , sizeof( V_5 -> V_8 ) ) ;
F_16 ( & V_5 -> V_17 ) ;
F_9 ( & V_5 -> V_17 ) ;
F_17 ( & V_5 -> V_24 , & V_10 -> V_11 [ F_4 ( V_10 , V_8 ) ] ) ;
V_10 -> V_21 ++ ;
}
F_11 ( & V_10 -> V_17 ) ;
return V_5 ;
}
static void F_18 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_19 ( V_26 , struct V_4 , V_27 ) ;
F_20 ( V_22 , V_5 ) ;
}
static inline void
F_21 ( struct V_9 * V_10 , struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_24 ) ;
F_23 ( & V_5 -> V_27 , F_18 ) ;
V_10 -> V_21 -- ;
}
static int F_24 ( struct V_2 * V_2 , struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_31 ;
unsigned int V_16 ;
unsigned int V_32 ;
if ( V_29 -> V_15 . V_16 ) {
V_16 = V_29 -> V_15 . V_16 ;
} else {
V_16 = ( V_33 << V_34 ) / 16384 /
sizeof( struct V_35 ) ;
if ( V_33 > 1024 * 1024 * 1024 / V_36 )
V_16 = 8192 ;
if ( V_16 < 16 )
V_16 = 16 ;
}
V_31 = F_25 ( sizeof( struct V_9 ) +
sizeof( struct V_35 ) * V_16 ) ;
if ( V_31 == NULL )
return - V_37 ;
V_29 -> V_31 = V_31 ;
memcpy ( & V_31 -> V_15 , & V_29 -> V_15 , sizeof( V_31 -> V_15 ) ) ;
V_31 -> V_15 . V_16 = V_16 ;
if ( V_31 -> V_15 . V_20 == 0 )
V_31 -> V_15 . V_20 = 8 * V_31 -> V_15 . V_16 ;
else if ( V_31 -> V_15 . V_20 < V_31 -> V_15 . V_16 )
V_31 -> V_15 . V_20 = V_31 -> V_15 . V_16 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_15 . V_16 ; V_32 ++ )
F_26 ( & V_31 -> V_11 [ V_32 ] ) ;
V_31 -> V_38 = 1 ;
V_31 -> V_21 = 0 ;
V_31 -> V_30 = V_30 ;
V_31 -> V_19 = false ;
F_16 ( & V_31 -> V_17 ) ;
V_31 -> V_39 = F_27 ( V_29 -> V_40 , 0 ,
( V_30 == V_41 ) ?
V_1 -> V_42 : V_1 -> V_43 ,
& V_44 , V_31 ) ;
if ( V_31 -> V_39 == NULL ) {
F_28 ( V_31 ) ;
return - V_37 ;
}
V_31 -> V_2 = V_2 ;
F_29 ( & V_31 -> V_45 , V_46 , ( unsigned long ) V_31 ) ;
V_31 -> V_45 . V_47 = V_48 + F_30 ( V_31 -> V_15 . V_49 ) ;
F_31 ( & V_31 -> V_45 ) ;
F_32 ( & V_31 -> V_24 , & V_1 -> V_50 ) ;
return 0 ;
}
static bool F_33 ( const struct V_9 * V_10 ,
const struct V_4 * V_51 )
{
return 1 ;
}
static bool F_34 ( const struct V_9 * V_10 ,
const struct V_4 * V_51 )
{
return F_35 ( V_48 , V_51 -> V_47 ) ;
}
static void F_36 ( struct V_9 * V_10 ,
bool (* F_37)( const struct V_9 * V_10 ,
const struct V_4 * V_51 ) )
{
unsigned int V_32 ;
F_38 ( & V_10 -> V_17 ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_15 . V_16 ; V_32 ++ ) {
struct V_4 * V_52 ;
struct V_53 * V_54 ;
F_39 (dh, n, &ht->hash[i], node) {
if ( (* F_37)( V_10 , V_52 ) )
F_21 ( V_10 , V_52 ) ;
}
}
F_40 ( & V_10 -> V_17 ) ;
}
static void V_46 ( unsigned long V_55 )
{
struct V_9 * V_10 = (struct V_9 * ) V_55 ;
F_36 ( V_10 , F_34 ) ;
V_10 -> V_45 . V_47 = V_48 + F_30 ( V_10 -> V_15 . V_49 ) ;
F_31 ( & V_10 -> V_45 ) ;
}
static void F_41 ( struct V_9 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_31 -> V_2 ) ;
struct V_56 * V_57 ;
F_42 ( & V_31 -> V_45 ) ;
if ( V_31 -> V_30 == V_41 )
V_57 = V_1 -> V_42 ;
else
V_57 = V_1 -> V_43 ;
if( V_57 != NULL )
F_43 ( V_31 -> V_39 -> V_40 , V_57 ) ;
F_36 ( V_31 , F_33 ) ;
F_28 ( V_31 ) ;
}
static struct V_9 * F_44 ( struct V_2 * V_2 ,
const char * V_40 ,
T_2 V_30 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_31 ;
F_45 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_40 , V_31 -> V_39 -> V_40 ) &&
V_31 -> V_30 == V_30 ) {
V_31 -> V_38 ++ ;
return V_31 ;
}
}
return NULL ;
}
static void F_46 ( struct V_9 * V_31 )
{
F_47 ( & V_58 ) ;
if ( -- V_31 -> V_38 == 0 ) {
F_48 ( & V_31 -> V_24 ) ;
F_41 ( V_31 ) ;
}
F_49 ( & V_58 ) ;
}
static V_12 F_50 ( V_12 V_59 )
{
return ( V_59 >> V_60 ) + 1 ;
}
static V_12 F_51 ( V_12 V_61 )
{
if ( V_61 > 0xFFFFFFFF / ( V_62 * V_63 ) )
return ( V_61 / V_64 ) * V_62 * V_63 ;
return ( V_61 * V_62 * V_63 ) / V_64 ;
}
static V_12 F_52 ( V_12 V_61 )
{
V_14 V_65 = V_61 ;
V_65 *= V_62 * V_66 ;
return ( V_12 ) ( V_65 >> 32 ) ;
}
static void F_53 ( struct V_4 * V_52 , unsigned long V_67 , V_12 V_68 )
{
unsigned long V_69 = V_67 - V_52 -> V_70 . V_71 ;
V_12 V_72 ;
if ( V_69 == 0 )
return;
V_52 -> V_70 . V_71 = V_67 ;
if ( V_68 & V_73 ) {
V_12 V_74 = V_52 -> V_70 . V_75 ;
V_52 -> V_70 . V_75 += V_66 * V_69 ;
V_72 = V_66 * V_62 ;
if ( V_74 >= V_52 -> V_70 . V_75 ) {
V_52 -> V_70 . V_75 = V_72 ;
return;
}
} else {
V_52 -> V_70 . V_75 += V_69 * V_63 ;
V_72 = V_52 -> V_70 . V_76 ;
}
if ( V_52 -> V_70 . V_75 > V_72 )
V_52 -> V_70 . V_75 = V_72 ;
}
static void F_54 ( struct V_4 * V_52 ,
struct V_9 * V_31 )
{
V_52 -> V_70 . V_71 = V_48 ;
if ( V_31 -> V_15 . V_68 & V_73 ) {
V_52 -> V_70 . V_75 = V_66 * V_62 ;
V_52 -> V_70 . V_77 = F_52 ( V_31 -> V_15 . V_78 ) ;
V_52 -> V_70 . V_76 = V_31 -> V_15 . V_79 ;
} else {
V_52 -> V_70 . V_75 = F_51 ( V_31 -> V_15 . V_78 *
V_31 -> V_15 . V_79 ) ;
V_52 -> V_70 . V_77 = F_51 ( V_31 -> V_15 . V_78 ) ;
V_52 -> V_70 . V_76 = V_52 -> V_70 . V_75 ;
}
}
static inline T_3 F_55 ( T_3 V_80 , unsigned int V_81 )
{
return V_81 ? F_56 ( F_57 ( V_80 ) & ~ 0 << ( 32 - V_81 ) ) : 0 ;
}
static void F_58 ( T_3 * V_32 , unsigned int V_82 )
{
switch ( V_82 ) {
case 0 ... 31 :
V_32 [ 0 ] = F_55 ( V_32 [ 0 ] , V_82 ) ;
V_32 [ 1 ] = V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_32 [ 1 ] = F_55 ( V_32 [ 1 ] , V_82 - 32 ) ;
V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_32 [ 2 ] = F_55 ( V_32 [ 2 ] , V_82 - 64 ) ;
V_32 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_32 [ 3 ] = F_55 ( V_32 [ 3 ] , V_82 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_59 ( const struct V_9 * V_31 ,
struct V_6 * V_8 ,
const struct V_83 * V_84 , unsigned int V_85 )
{
T_4 V_86 [ 2 ] , * V_87 ;
T_5 V_88 ;
int V_89 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_31 -> V_30 ) {
case V_41 :
if ( V_31 -> V_15 . V_68 & V_90 )
V_8 -> V_91 . V_8 = F_55 ( F_60 ( V_84 ) -> V_92 ,
V_31 -> V_15 . V_93 ) ;
if ( V_31 -> V_15 . V_68 & V_94 )
V_8 -> V_91 . V_95 = F_55 ( F_60 ( V_84 ) -> V_96 ,
V_31 -> V_15 . V_97 ) ;
if ( ! ( V_31 -> V_15 . V_68 &
( V_98 | V_99 ) ) )
return 0 ;
V_88 = F_60 ( V_84 ) -> V_100 ;
break;
#if F_61 ( V_101 )
case V_102 :
{
T_4 V_103 ;
if ( V_31 -> V_15 . V_68 & V_90 ) {
memcpy ( & V_8 -> V_104 . V_8 , & F_62 ( V_84 ) -> V_92 ,
sizeof( V_8 -> V_104 . V_8 ) ) ;
F_58 ( V_8 -> V_104 . V_8 , V_31 -> V_15 . V_93 ) ;
}
if ( V_31 -> V_15 . V_68 & V_94 ) {
memcpy ( & V_8 -> V_104 . V_95 , & F_62 ( V_84 ) -> V_96 ,
sizeof( V_8 -> V_104 . V_95 ) ) ;
F_58 ( V_8 -> V_104 . V_95 , V_31 -> V_15 . V_97 ) ;
}
if ( ! ( V_31 -> V_15 . V_68 &
( V_98 | V_99 ) ) )
return 0 ;
V_88 = F_62 ( V_84 ) -> V_88 ;
V_85 = F_63 ( V_84 , sizeof( struct V_105 ) , & V_88 , & V_103 ) ;
if ( ( int ) V_85 < 0 )
return - 1 ;
break;
}
#endif
default:
F_64 () ;
return 0 ;
}
V_89 = F_65 ( V_88 ) ;
if ( V_89 >= 0 ) {
V_87 = F_66 ( V_84 , V_85 + V_89 , sizeof( V_86 ) ,
& V_86 ) ;
} else {
V_86 [ 0 ] = V_86 [ 1 ] = 0 ;
V_87 = V_86 ;
}
if ( ! V_87 )
return - 1 ;
if ( V_31 -> V_15 . V_68 & V_99 )
V_8 -> V_106 = V_87 [ 0 ] ;
if ( V_31 -> V_15 . V_68 & V_98 )
V_8 -> V_107 = V_87 [ 1 ] ;
return 0 ;
}
static V_12 F_67 ( unsigned int V_59 , struct V_4 * V_52 )
{
V_14 V_74 = F_50 ( V_59 ) ;
V_74 = V_74 * V_52 -> V_70 . V_77 ;
if ( F_12 ( V_74 > V_66 * V_62 ) )
V_74 = V_66 * V_62 ;
if ( V_52 -> V_70 . V_75 < V_74 && V_52 -> V_70 . V_76 ) {
V_52 -> V_70 . V_76 -- ;
V_52 -> V_70 . V_75 = V_66 * V_62 ;
}
return ( V_12 ) V_74 ;
}
static bool
F_68 ( const struct V_83 * V_84 , struct V_108 * V_109 )
{
const struct V_28 * V_110 = V_109 -> V_111 ;
struct V_9 * V_31 = V_110 -> V_31 ;
unsigned long V_67 = V_48 ;
struct V_4 * V_52 ;
struct V_6 V_8 ;
bool V_18 = false ;
V_12 V_77 ;
if ( F_59 ( V_31 , & V_8 , V_84 , V_109 -> V_112 ) < 0 )
goto V_113;
F_69 () ;
V_52 = F_6 ( V_31 , & V_8 ) ;
if ( V_52 == NULL ) {
V_52 = F_10 ( V_31 , & V_8 , & V_18 ) ;
if ( V_52 == NULL ) {
F_70 () ;
goto V_113;
} else if ( V_18 ) {
V_52 -> V_47 = V_67 + F_30 ( V_31 -> V_15 . V_114 ) ;
F_53 ( V_52 , V_67 , V_31 -> V_15 . V_68 ) ;
} else {
V_52 -> V_47 = V_48 + F_30 ( V_31 -> V_15 . V_114 ) ;
F_54 ( V_52 , V_31 ) ;
}
} else {
V_52 -> V_47 = V_67 + F_30 ( V_31 -> V_15 . V_114 ) ;
F_53 ( V_52 , V_67 , V_31 -> V_15 . V_68 ) ;
}
if ( V_110 -> V_15 . V_68 & V_73 )
V_77 = F_67 ( V_84 -> V_59 , V_52 ) ;
else
V_77 = V_52 -> V_70 . V_77 ;
if ( V_52 -> V_70 . V_75 >= V_77 ) {
V_52 -> V_70 . V_75 -= V_77 ;
F_11 ( & V_52 -> V_17 ) ;
F_70 () ;
return ! ( V_110 -> V_15 . V_68 & V_115 ) ;
}
F_11 ( & V_52 -> V_17 ) ;
F_70 () ;
return V_110 -> V_15 . V_68 & V_115 ;
V_113:
V_109 -> V_113 = true ;
return false ;
}
static int F_71 ( const struct V_116 * V_109 )
{
struct V_2 * V_2 = V_109 -> V_2 ;
struct V_28 * V_110 = V_109 -> V_111 ;
int V_117 ;
if ( V_110 -> V_15 . V_49 == 0 || V_110 -> V_15 . V_114 == 0 )
return - V_118 ;
if ( V_110 -> V_40 [ sizeof( V_110 -> V_40 ) - 1 ] != '\0' )
return - V_118 ;
if ( V_109 -> V_30 == V_41 ) {
if ( V_110 -> V_15 . V_97 > 32 || V_110 -> V_15 . V_93 > 32 )
return - V_118 ;
} else {
if ( V_110 -> V_15 . V_97 > 128 || V_110 -> V_15 . V_93 > 128 )
return - V_118 ;
}
if ( V_110 -> V_15 . V_68 & ~ V_119 ) {
F_72 ( L_2 ,
V_110 -> V_15 . V_68 ) ;
return - V_118 ;
}
if ( V_110 -> V_15 . V_68 & V_73 ) {
if ( F_52 ( V_110 -> V_15 . V_78 ) == 0 ) {
F_72 ( L_3 , V_110 -> V_15 . V_78 ) ;
return - V_118 ;
}
} else if ( V_110 -> V_15 . V_79 == 0 ||
F_51 ( V_110 -> V_15 . V_78 * V_110 -> V_15 . V_79 ) <
F_51 ( V_110 -> V_15 . V_78 ) ) {
F_72 ( L_4 ,
V_110 -> V_15 . V_78 , V_110 -> V_15 . V_79 ) ;
return - V_120 ;
}
F_47 ( & V_58 ) ;
V_110 -> V_31 = F_44 ( V_2 , V_110 -> V_40 , V_109 -> V_30 ) ;
if ( V_110 -> V_31 == NULL ) {
V_117 = F_24 ( V_2 , V_110 , V_109 -> V_30 ) ;
if ( V_117 < 0 ) {
F_49 ( & V_58 ) ;
return V_117 ;
}
}
F_49 ( & V_58 ) ;
return 0 ;
}
static void F_73 ( const struct V_121 * V_109 )
{
const struct V_28 * V_110 = V_109 -> V_111 ;
F_46 ( V_110 -> V_31 ) ;
}
static void * F_74 ( struct V_122 * V_123 , T_6 * V_124 )
__acquires( V_125 -> V_17 )
{
struct V_9 * V_125 = V_123 -> V_126 ;
unsigned int * V_127 ;
F_38 ( & V_125 -> V_17 ) ;
if ( * V_124 >= V_125 -> V_15 . V_16 )
return NULL ;
V_127 = F_75 ( sizeof( unsigned int ) , V_23 ) ;
if ( ! V_127 )
return F_76 ( - V_37 ) ;
* V_127 = * V_124 ;
return V_127 ;
}
static void * F_77 ( struct V_122 * V_123 , void * V_128 , T_6 * V_124 )
{
struct V_9 * V_125 = V_123 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
* V_124 = ++ ( * V_127 ) ;
if ( * V_124 >= V_125 -> V_15 . V_16 ) {
F_78 ( V_128 ) ;
return NULL ;
}
return V_127 ;
}
static void F_79 ( struct V_122 * V_123 , void * V_128 )
__releases( V_125 -> V_17 )
{
struct V_9 * V_125 = V_123 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
if ( ! F_80 ( V_127 ) )
F_78 ( V_127 ) ;
F_40 ( & V_125 -> V_17 ) ;
}
static int F_81 ( struct V_4 * V_5 , T_2 V_30 ,
struct V_122 * V_123 )
{
int V_129 ;
const struct V_9 * V_10 = V_123 -> V_126 ;
F_9 ( & V_5 -> V_17 ) ;
F_53 ( V_5 , V_48 , V_10 -> V_15 . V_68 ) ;
switch ( V_30 ) {
case V_41 :
V_129 = F_82 ( V_123 , L_5 ,
( long ) ( V_5 -> V_47 - V_48 ) / V_62 ,
& V_5 -> V_8 . V_91 . V_95 ,
F_83 ( V_5 -> V_8 . V_106 ) ,
& V_5 -> V_8 . V_91 . V_8 ,
F_83 ( V_5 -> V_8 . V_107 ) ,
V_5 -> V_70 . V_75 , V_5 -> V_70 . V_76 ,
V_5 -> V_70 . V_77 ) ;
break;
#if F_61 ( V_101 )
case V_102 :
V_129 = F_82 ( V_123 , L_6 ,
( long ) ( V_5 -> V_47 - V_48 ) / V_62 ,
& V_5 -> V_8 . V_104 . V_95 ,
F_83 ( V_5 -> V_8 . V_106 ) ,
& V_5 -> V_8 . V_104 . V_8 ,
F_83 ( V_5 -> V_8 . V_107 ) ,
V_5 -> V_70 . V_75 , V_5 -> V_70 . V_76 ,
V_5 -> V_70 . V_77 ) ;
break;
#endif
default:
F_64 () ;
V_129 = 0 ;
}
F_11 ( & V_5 -> V_17 ) ;
return V_129 ;
}
static int F_84 ( struct V_122 * V_123 , void * V_128 )
{
struct V_9 * V_125 = V_123 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
struct V_4 * V_5 ;
if ( ! F_7 ( & V_125 -> V_11 [ * V_127 ] ) ) {
F_45 (ent, &htable->hash[*bucket], node)
if ( F_81 ( V_5 , V_125 -> V_30 , V_123 ) )
return - 1 ;
}
return 0 ;
}
static int F_85 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
int V_117 = F_86 ( V_131 , & V_132 ) ;
if ( ! V_117 ) {
struct V_122 * V_133 = V_131 -> V_134 ;
V_133 -> V_126 = F_87 ( V_130 ) -> V_135 ;
}
return V_117 ;
}
static int T_7 F_88 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_42 = F_89 ( L_7 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_42 )
return - V_37 ;
#if F_61 ( V_101 )
V_1 -> V_43 = F_89 ( L_8 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_43 ) {
F_43 ( L_7 , V_2 -> V_136 ) ;
return - V_37 ;
}
#endif
return 0 ;
}
static void T_8 F_90 ( struct V_2 * V_2 )
{
struct V_9 * V_31 ;
struct V_56 * V_39 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_47 ( & V_58 ) ;
V_39 = V_1 -> V_42 ;
if ( V_39 == NULL )
V_39 = V_1 -> V_43 ;
F_45 (hinfo, &hashlimit_net->htables, node)
F_43 ( V_31 -> V_39 -> V_40 , V_39 ) ;
V_1 -> V_42 = NULL ;
V_1 -> V_43 = NULL ;
F_49 ( & V_58 ) ;
F_43 ( L_7 , V_2 -> V_136 ) ;
#if F_61 ( V_101 )
F_43 ( L_8 , V_2 -> V_136 ) ;
#endif
}
static int T_7 F_91 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_26 ( & V_1 -> V_50 ) ;
return F_88 ( V_2 ) ;
}
static void T_8 F_92 ( struct V_2 * V_2 )
{
F_90 ( V_2 ) ;
}
static int T_9 F_93 ( void )
{
int V_137 ;
V_137 = F_94 ( & V_138 ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_95 ( V_139 ,
F_96 ( V_139 ) ) ;
if ( V_137 < 0 )
goto V_140;
V_137 = - V_37 ;
V_22 = F_97 ( L_9 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_22 ) {
F_98 ( L_10 ) ;
goto V_141;
}
return 0 ;
V_141:
F_99 ( V_139 , F_96 ( V_139 ) ) ;
V_140:
F_100 ( & V_138 ) ;
return V_137 ;
}
static void T_10 F_101 ( void )
{
F_99 ( V_139 , F_96 ( V_139 ) ) ;
F_100 ( & V_138 ) ;
F_102 () ;
F_103 ( V_22 ) ;
}
