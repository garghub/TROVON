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
V_31 -> V_39 = F_27 ( V_29 -> V_39 , V_40 ) ;
if ( ! V_31 -> V_39 ) {
F_28 ( V_31 ) ;
return - V_37 ;
}
F_16 ( & V_31 -> V_17 ) ;
V_31 -> V_41 = F_29 ( V_29 -> V_39 , 0 ,
( V_30 == V_42 ) ?
V_1 -> V_43 : V_1 -> V_44 ,
& V_45 , V_31 ) ;
if ( V_31 -> V_41 == NULL ) {
F_30 ( V_31 -> V_39 ) ;
F_28 ( V_31 ) ;
return - V_37 ;
}
V_31 -> V_2 = V_2 ;
F_31 ( & V_31 -> V_46 , V_47 , ( unsigned long ) V_31 ) ;
V_31 -> V_46 . V_48 = V_49 + F_32 ( V_31 -> V_15 . V_50 ) ;
F_33 ( & V_31 -> V_46 ) ;
F_34 ( & V_31 -> V_24 , & V_1 -> V_51 ) ;
return 0 ;
}
static bool F_35 ( const struct V_9 * V_10 ,
const struct V_4 * V_52 )
{
return 1 ;
}
static bool F_36 ( const struct V_9 * V_10 ,
const struct V_4 * V_52 )
{
return F_37 ( V_49 , V_52 -> V_48 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
bool (* F_39)( const struct V_9 * V_10 ,
const struct V_4 * V_52 ) )
{
unsigned int V_32 ;
F_40 ( & V_10 -> V_17 ) ;
for ( V_32 = 0 ; V_32 < V_10 -> V_15 . V_16 ; V_32 ++ ) {
struct V_4 * V_53 ;
struct V_54 * V_55 ;
F_41 (dh, n, &ht->hash[i], node) {
if ( (* F_39)( V_10 , V_53 ) )
F_21 ( V_10 , V_53 ) ;
}
}
F_42 ( & V_10 -> V_17 ) ;
}
static void V_47 ( unsigned long V_56 )
{
struct V_9 * V_10 = (struct V_9 * ) V_56 ;
F_38 ( V_10 , F_36 ) ;
V_10 -> V_46 . V_48 = V_49 + F_32 ( V_10 -> V_15 . V_50 ) ;
F_33 ( & V_10 -> V_46 ) ;
}
static void F_43 ( struct V_9 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_31 -> V_2 ) ;
struct V_57 * V_58 ;
F_44 ( & V_31 -> V_46 ) ;
if ( V_31 -> V_30 == V_42 )
V_58 = V_1 -> V_43 ;
else
V_58 = V_1 -> V_44 ;
if( V_58 != NULL )
F_45 ( V_31 -> V_39 , V_58 ) ;
F_38 ( V_31 , F_35 ) ;
F_30 ( V_31 -> V_39 ) ;
F_28 ( V_31 ) ;
}
static struct V_9 * F_46 ( struct V_2 * V_2 ,
const char * V_39 ,
T_2 V_30 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_31 ;
F_47 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_39 , V_31 -> V_39 ) &&
V_31 -> V_30 == V_30 ) {
V_31 -> V_38 ++ ;
return V_31 ;
}
}
return NULL ;
}
static void F_48 ( struct V_9 * V_31 )
{
F_49 ( & V_59 ) ;
if ( -- V_31 -> V_38 == 0 ) {
F_50 ( & V_31 -> V_24 ) ;
F_43 ( V_31 ) ;
}
F_51 ( & V_59 ) ;
}
static V_12 F_52 ( V_12 V_60 )
{
return ( V_60 >> V_61 ) + 1 ;
}
static V_12 F_53 ( V_12 V_62 )
{
if ( V_62 > 0xFFFFFFFF / ( V_63 * V_64 ) )
return ( V_62 / V_65 ) * V_63 * V_64 ;
return ( V_62 * V_63 * V_64 ) / V_65 ;
}
static V_12 F_54 ( V_12 V_62 )
{
V_14 V_66 = V_62 ;
V_66 *= V_63 * V_67 ;
return ( V_12 ) ( V_66 >> 32 ) ;
}
static void F_55 ( struct V_4 * V_53 , unsigned long V_68 , V_12 V_69 )
{
unsigned long V_70 = V_68 - V_53 -> V_71 . V_72 ;
V_12 V_73 ;
if ( V_70 == 0 )
return;
V_53 -> V_71 . V_72 = V_68 ;
if ( V_69 & V_74 ) {
V_12 V_75 = V_53 -> V_71 . V_76 ;
V_53 -> V_71 . V_76 += V_67 * V_70 ;
V_73 = V_67 * V_63 ;
if ( V_75 >= V_53 -> V_71 . V_76 ) {
V_53 -> V_71 . V_76 = V_73 ;
return;
}
} else {
V_53 -> V_71 . V_76 += V_70 * V_64 ;
V_73 = V_53 -> V_71 . V_77 ;
}
if ( V_53 -> V_71 . V_76 > V_73 )
V_53 -> V_71 . V_76 = V_73 ;
}
static void F_56 ( struct V_4 * V_53 ,
struct V_9 * V_31 )
{
V_53 -> V_71 . V_72 = V_49 ;
if ( V_31 -> V_15 . V_69 & V_74 ) {
V_53 -> V_71 . V_76 = V_67 * V_63 ;
V_53 -> V_71 . V_78 = F_54 ( V_31 -> V_15 . V_79 ) ;
V_53 -> V_71 . V_77 = V_31 -> V_15 . V_80 ;
} else {
V_53 -> V_71 . V_76 = F_53 ( V_31 -> V_15 . V_79 *
V_31 -> V_15 . V_80 ) ;
V_53 -> V_71 . V_78 = F_53 ( V_31 -> V_15 . V_79 ) ;
V_53 -> V_71 . V_77 = V_53 -> V_71 . V_76 ;
}
}
static inline T_3 F_57 ( T_3 V_81 , unsigned int V_82 )
{
return V_82 ? F_58 ( F_59 ( V_81 ) & ~ 0 << ( 32 - V_82 ) ) : 0 ;
}
static void F_60 ( T_3 * V_32 , unsigned int V_83 )
{
switch ( V_83 ) {
case 0 ... 31 :
V_32 [ 0 ] = F_57 ( V_32 [ 0 ] , V_83 ) ;
V_32 [ 1 ] = V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_32 [ 1 ] = F_57 ( V_32 [ 1 ] , V_83 - 32 ) ;
V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_32 [ 2 ] = F_57 ( V_32 [ 2 ] , V_83 - 64 ) ;
V_32 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_32 [ 3 ] = F_57 ( V_32 [ 3 ] , V_83 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_61 ( const struct V_9 * V_31 ,
struct V_6 * V_8 ,
const struct V_84 * V_85 , unsigned int V_86 )
{
T_4 V_87 [ 2 ] , * V_88 ;
T_5 V_89 ;
int V_90 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_31 -> V_30 ) {
case V_42 :
if ( V_31 -> V_15 . V_69 & V_91 )
V_8 -> V_92 . V_8 = F_57 ( F_62 ( V_85 ) -> V_93 ,
V_31 -> V_15 . V_94 ) ;
if ( V_31 -> V_15 . V_69 & V_95 )
V_8 -> V_92 . V_96 = F_57 ( F_62 ( V_85 ) -> V_97 ,
V_31 -> V_15 . V_98 ) ;
if ( ! ( V_31 -> V_15 . V_69 &
( V_99 | V_100 ) ) )
return 0 ;
V_89 = F_62 ( V_85 ) -> V_101 ;
break;
#if F_63 ( V_102 )
case V_103 :
{
T_4 V_104 ;
if ( V_31 -> V_15 . V_69 & V_91 ) {
memcpy ( & V_8 -> V_105 . V_8 , & F_64 ( V_85 ) -> V_93 ,
sizeof( V_8 -> V_105 . V_8 ) ) ;
F_60 ( V_8 -> V_105 . V_8 , V_31 -> V_15 . V_94 ) ;
}
if ( V_31 -> V_15 . V_69 & V_95 ) {
memcpy ( & V_8 -> V_105 . V_96 , & F_64 ( V_85 ) -> V_97 ,
sizeof( V_8 -> V_105 . V_96 ) ) ;
F_60 ( V_8 -> V_105 . V_96 , V_31 -> V_15 . V_98 ) ;
}
if ( ! ( V_31 -> V_15 . V_69 &
( V_99 | V_100 ) ) )
return 0 ;
V_89 = F_64 ( V_85 ) -> V_89 ;
V_86 = F_65 ( V_85 , sizeof( struct V_106 ) , & V_89 , & V_104 ) ;
if ( ( int ) V_86 < 0 )
return - 1 ;
break;
}
#endif
default:
F_66 () ;
return 0 ;
}
V_90 = F_67 ( V_89 ) ;
if ( V_90 >= 0 ) {
V_88 = F_68 ( V_85 , V_86 + V_90 , sizeof( V_87 ) ,
& V_87 ) ;
} else {
V_87 [ 0 ] = V_87 [ 1 ] = 0 ;
V_88 = V_87 ;
}
if ( ! V_88 )
return - 1 ;
if ( V_31 -> V_15 . V_69 & V_100 )
V_8 -> V_107 = V_88 [ 0 ] ;
if ( V_31 -> V_15 . V_69 & V_99 )
V_8 -> V_108 = V_88 [ 1 ] ;
return 0 ;
}
static V_12 F_69 ( unsigned int V_60 , struct V_4 * V_53 )
{
V_14 V_75 = F_52 ( V_60 ) ;
V_75 = V_75 * V_53 -> V_71 . V_78 ;
if ( F_12 ( V_75 > V_67 * V_63 ) )
V_75 = V_67 * V_63 ;
if ( V_53 -> V_71 . V_76 < V_75 && V_53 -> V_71 . V_77 ) {
V_53 -> V_71 . V_77 -- ;
V_53 -> V_71 . V_76 = V_67 * V_63 ;
}
return ( V_12 ) V_75 ;
}
static bool
F_70 ( const struct V_84 * V_85 , struct V_109 * V_110 )
{
const struct V_28 * V_111 = V_110 -> V_112 ;
struct V_9 * V_31 = V_111 -> V_31 ;
unsigned long V_68 = V_49 ;
struct V_4 * V_53 ;
struct V_6 V_8 ;
bool V_18 = false ;
V_12 V_78 ;
if ( F_61 ( V_31 , & V_8 , V_85 , V_110 -> V_113 ) < 0 )
goto V_114;
F_71 () ;
V_53 = F_6 ( V_31 , & V_8 ) ;
if ( V_53 == NULL ) {
V_53 = F_10 ( V_31 , & V_8 , & V_18 ) ;
if ( V_53 == NULL ) {
F_72 () ;
goto V_114;
} else if ( V_18 ) {
V_53 -> V_48 = V_68 + F_32 ( V_31 -> V_15 . V_115 ) ;
F_55 ( V_53 , V_68 , V_31 -> V_15 . V_69 ) ;
} else {
V_53 -> V_48 = V_49 + F_32 ( V_31 -> V_15 . V_115 ) ;
F_56 ( V_53 , V_31 ) ;
}
} else {
V_53 -> V_48 = V_68 + F_32 ( V_31 -> V_15 . V_115 ) ;
F_55 ( V_53 , V_68 , V_31 -> V_15 . V_69 ) ;
}
if ( V_111 -> V_15 . V_69 & V_74 )
V_78 = F_69 ( V_85 -> V_60 , V_53 ) ;
else
V_78 = V_53 -> V_71 . V_78 ;
if ( V_53 -> V_71 . V_76 >= V_78 ) {
V_53 -> V_71 . V_76 -= V_78 ;
F_11 ( & V_53 -> V_17 ) ;
F_72 () ;
return ! ( V_111 -> V_15 . V_69 & V_116 ) ;
}
F_11 ( & V_53 -> V_17 ) ;
F_72 () ;
return V_111 -> V_15 . V_69 & V_116 ;
V_114:
V_110 -> V_114 = true ;
return false ;
}
static int F_73 ( const struct V_117 * V_110 )
{
struct V_2 * V_2 = V_110 -> V_2 ;
struct V_28 * V_111 = V_110 -> V_112 ;
int V_118 ;
if ( V_111 -> V_15 . V_50 == 0 || V_111 -> V_15 . V_115 == 0 )
return - V_119 ;
if ( V_111 -> V_39 [ sizeof( V_111 -> V_39 ) - 1 ] != '\0' )
return - V_119 ;
if ( V_110 -> V_30 == V_42 ) {
if ( V_111 -> V_15 . V_98 > 32 || V_111 -> V_15 . V_94 > 32 )
return - V_119 ;
} else {
if ( V_111 -> V_15 . V_98 > 128 || V_111 -> V_15 . V_94 > 128 )
return - V_119 ;
}
if ( V_111 -> V_15 . V_69 & ~ V_120 ) {
F_74 ( L_2 ,
V_111 -> V_15 . V_69 ) ;
return - V_119 ;
}
if ( V_111 -> V_15 . V_69 & V_74 ) {
if ( F_54 ( V_111 -> V_15 . V_79 ) == 0 ) {
F_74 ( L_3 , V_111 -> V_15 . V_79 ) ;
return - V_119 ;
}
} else if ( V_111 -> V_15 . V_80 == 0 ||
F_53 ( V_111 -> V_15 . V_79 * V_111 -> V_15 . V_80 ) <
F_53 ( V_111 -> V_15 . V_79 ) ) {
F_74 ( L_4 ,
V_111 -> V_15 . V_79 , V_111 -> V_15 . V_80 ) ;
return - V_121 ;
}
F_49 ( & V_59 ) ;
V_111 -> V_31 = F_46 ( V_2 , V_111 -> V_39 , V_110 -> V_30 ) ;
if ( V_111 -> V_31 == NULL ) {
V_118 = F_24 ( V_2 , V_111 , V_110 -> V_30 ) ;
if ( V_118 < 0 ) {
F_51 ( & V_59 ) ;
return V_118 ;
}
}
F_51 ( & V_59 ) ;
return 0 ;
}
static void F_75 ( const struct V_122 * V_110 )
{
const struct V_28 * V_111 = V_110 -> V_112 ;
F_48 ( V_111 -> V_31 ) ;
}
static void * F_76 ( struct V_123 * V_124 , T_6 * V_125 )
__acquires( V_126 -> V_17 )
{
struct V_9 * V_126 = V_124 -> V_127 ;
unsigned int * V_128 ;
F_40 ( & V_126 -> V_17 ) ;
if ( * V_125 >= V_126 -> V_15 . V_16 )
return NULL ;
V_128 = F_77 ( sizeof( unsigned int ) , V_23 ) ;
if ( ! V_128 )
return F_78 ( - V_37 ) ;
* V_128 = * V_125 ;
return V_128 ;
}
static void * F_79 ( struct V_123 * V_124 , void * V_129 , T_6 * V_125 )
{
struct V_9 * V_126 = V_124 -> V_127 ;
unsigned int * V_128 = ( unsigned int * ) V_129 ;
* V_125 = ++ ( * V_128 ) ;
if ( * V_125 >= V_126 -> V_15 . V_16 ) {
F_30 ( V_129 ) ;
return NULL ;
}
return V_128 ;
}
static void F_80 ( struct V_123 * V_124 , void * V_129 )
__releases( V_126 -> V_17 )
{
struct V_9 * V_126 = V_124 -> V_127 ;
unsigned int * V_128 = ( unsigned int * ) V_129 ;
if ( ! F_81 ( V_128 ) )
F_30 ( V_128 ) ;
F_42 ( & V_126 -> V_17 ) ;
}
static int F_82 ( struct V_4 * V_5 , T_2 V_30 ,
struct V_123 * V_124 )
{
int V_130 ;
const struct V_9 * V_10 = V_124 -> V_127 ;
F_9 ( & V_5 -> V_17 ) ;
F_55 ( V_5 , V_49 , V_10 -> V_15 . V_69 ) ;
switch ( V_30 ) {
case V_42 :
V_130 = F_83 ( V_124 , L_5 ,
( long ) ( V_5 -> V_48 - V_49 ) / V_63 ,
& V_5 -> V_8 . V_92 . V_96 ,
F_84 ( V_5 -> V_8 . V_107 ) ,
& V_5 -> V_8 . V_92 . V_8 ,
F_84 ( V_5 -> V_8 . V_108 ) ,
V_5 -> V_71 . V_76 , V_5 -> V_71 . V_77 ,
V_5 -> V_71 . V_78 ) ;
break;
#if F_63 ( V_102 )
case V_103 :
V_130 = F_83 ( V_124 , L_6 ,
( long ) ( V_5 -> V_48 - V_49 ) / V_63 ,
& V_5 -> V_8 . V_105 . V_96 ,
F_84 ( V_5 -> V_8 . V_107 ) ,
& V_5 -> V_8 . V_105 . V_8 ,
F_84 ( V_5 -> V_8 . V_108 ) ,
V_5 -> V_71 . V_76 , V_5 -> V_71 . V_77 ,
V_5 -> V_71 . V_78 ) ;
break;
#endif
default:
F_66 () ;
V_130 = 0 ;
}
F_11 ( & V_5 -> V_17 ) ;
return V_130 ;
}
static int F_85 ( struct V_123 * V_124 , void * V_129 )
{
struct V_9 * V_126 = V_124 -> V_127 ;
unsigned int * V_128 = ( unsigned int * ) V_129 ;
struct V_4 * V_5 ;
if ( ! F_7 ( & V_126 -> V_11 [ * V_128 ] ) ) {
F_47 (ent, &htable->hash[*bucket], node)
if ( F_82 ( V_5 , V_126 -> V_30 , V_124 ) )
return - 1 ;
}
return 0 ;
}
static int F_86 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
int V_118 = F_87 ( V_132 , & V_133 ) ;
if ( ! V_118 ) {
struct V_123 * V_134 = V_132 -> V_135 ;
V_134 -> V_127 = F_88 ( V_131 ) ;
}
return V_118 ;
}
static int T_7 F_89 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_43 = F_90 ( L_7 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_43 )
return - V_37 ;
#if F_63 ( V_102 )
V_1 -> V_44 = F_90 ( L_8 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_44 ) {
F_45 ( L_7 , V_2 -> V_136 ) ;
return - V_37 ;
}
#endif
return 0 ;
}
static void T_8 F_91 ( struct V_2 * V_2 )
{
struct V_9 * V_31 ;
struct V_57 * V_41 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_49 ( & V_59 ) ;
V_41 = V_1 -> V_43 ;
if ( V_41 == NULL )
V_41 = V_1 -> V_44 ;
F_47 (hinfo, &hashlimit_net->htables, node)
F_45 ( V_31 -> V_39 , V_41 ) ;
V_1 -> V_43 = NULL ;
V_1 -> V_44 = NULL ;
F_51 ( & V_59 ) ;
F_45 ( L_7 , V_2 -> V_136 ) ;
#if F_63 ( V_102 )
F_45 ( L_8 , V_2 -> V_136 ) ;
#endif
}
static int T_7 F_92 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_26 ( & V_1 -> V_51 ) ;
return F_89 ( V_2 ) ;
}
static void T_8 F_93 ( struct V_2 * V_2 )
{
F_91 ( V_2 ) ;
}
static int T_9 F_94 ( void )
{
int V_137 ;
V_137 = F_95 ( & V_138 ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_96 ( V_139 ,
F_97 ( V_139 ) ) ;
if ( V_137 < 0 )
goto V_140;
V_137 = - V_37 ;
V_22 = F_98 ( L_9 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_22 ) {
F_99 ( L_10 ) ;
goto V_141;
}
return 0 ;
V_141:
F_100 ( V_139 , F_97 ( V_139 ) ) ;
V_140:
F_101 ( & V_138 ) ;
return V_137 ;
}
static void T_10 F_102 ( void )
{
F_100 ( V_139 , F_97 ( V_139 ) ) ;
F_101 ( & V_138 ) ;
F_103 () ;
F_104 ( V_22 ) ;
}
