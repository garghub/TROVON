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
struct V_17 * V_18 ;
T_1 V_11 = F_4 ( V_10 , V_8 ) ;
if ( ! F_7 ( & V_10 -> V_11 [ V_11 ] ) ) {
F_8 (ent, pos, &ht->hash[hash], node)
if ( F_3 ( V_5 , V_8 ) ) {
F_9 ( & V_5 -> V_19 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_4 *
F_10 ( struct V_9 * V_10 ,
const struct V_6 * V_8 , bool * V_20 )
{
struct V_4 * V_5 ;
F_9 ( & V_10 -> V_19 ) ;
V_5 = F_6 ( V_10 , V_8 ) ;
if ( V_5 != NULL ) {
F_11 ( & V_10 -> V_19 ) ;
* V_20 = true ;
return V_5 ;
}
if ( F_12 ( ! V_10 -> V_21 ) ) {
F_13 ( & V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
V_10 -> V_21 = true ;
}
if ( V_10 -> V_15 . V_22 && V_10 -> V_23 >= V_10 -> V_15 . V_22 ) {
F_14 ( L_1 , V_10 -> V_15 . V_22 ) ;
V_5 = NULL ;
} else
V_5 = F_15 ( V_24 , V_25 ) ;
if ( V_5 ) {
memcpy ( & V_5 -> V_8 , V_8 , sizeof( V_5 -> V_8 ) ) ;
F_16 ( & V_5 -> V_19 ) ;
F_9 ( & V_5 -> V_19 ) ;
F_17 ( & V_5 -> V_26 , & V_10 -> V_11 [ F_4 ( V_10 , V_8 ) ] ) ;
V_10 -> V_23 ++ ;
}
F_11 ( & V_10 -> V_19 ) ;
return V_5 ;
}
static void F_18 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = F_19 ( V_28 , struct V_4 , V_29 ) ;
F_20 ( V_24 , V_5 ) ;
}
static inline void
F_21 ( struct V_9 * V_10 , struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_26 ) ;
F_23 ( & V_5 -> V_29 , F_18 ) ;
V_10 -> V_23 -- ;
}
static int F_24 ( struct V_2 * V_2 , struct V_30 * V_31 ,
T_2 V_32 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_33 ;
unsigned int V_16 ;
unsigned int V_34 ;
if ( V_31 -> V_15 . V_16 ) {
V_16 = V_31 -> V_15 . V_16 ;
} else {
V_16 = ( V_35 << V_36 ) / 16384 /
sizeof( struct V_37 ) ;
if ( V_35 > 1024 * 1024 * 1024 / V_38 )
V_16 = 8192 ;
if ( V_16 < 16 )
V_16 = 16 ;
}
V_33 = F_25 ( sizeof( struct V_9 ) +
sizeof( struct V_37 ) * V_16 ) ;
if ( V_33 == NULL )
return - V_39 ;
V_31 -> V_33 = V_33 ;
memcpy ( & V_33 -> V_15 , & V_31 -> V_15 , sizeof( V_33 -> V_15 ) ) ;
V_33 -> V_15 . V_16 = V_16 ;
if ( V_33 -> V_15 . V_22 == 0 )
V_33 -> V_15 . V_22 = 8 * V_33 -> V_15 . V_16 ;
else if ( V_33 -> V_15 . V_22 < V_33 -> V_15 . V_16 )
V_33 -> V_15 . V_22 = V_33 -> V_15 . V_16 ;
for ( V_34 = 0 ; V_34 < V_33 -> V_15 . V_16 ; V_34 ++ )
F_26 ( & V_33 -> V_11 [ V_34 ] ) ;
V_33 -> V_40 = 1 ;
V_33 -> V_23 = 0 ;
V_33 -> V_32 = V_32 ;
V_33 -> V_21 = false ;
F_16 ( & V_33 -> V_19 ) ;
V_33 -> V_41 = F_27 ( V_31 -> V_42 , 0 ,
( V_32 == V_43 ) ?
V_1 -> V_44 : V_1 -> V_45 ,
& V_46 , V_33 ) ;
if ( V_33 -> V_41 == NULL ) {
F_28 ( V_33 ) ;
return - V_39 ;
}
V_33 -> V_2 = V_2 ;
F_29 ( & V_33 -> V_47 , V_48 , ( unsigned long ) V_33 ) ;
V_33 -> V_47 . V_49 = V_50 + F_30 ( V_33 -> V_15 . V_51 ) ;
F_31 ( & V_33 -> V_47 ) ;
F_32 ( & V_33 -> V_26 , & V_1 -> V_52 ) ;
return 0 ;
}
static bool F_33 ( const struct V_9 * V_10 ,
const struct V_4 * V_53 )
{
return 1 ;
}
static bool F_34 ( const struct V_9 * V_10 ,
const struct V_4 * V_53 )
{
return F_35 ( V_50 , V_53 -> V_49 ) ;
}
static void F_36 ( struct V_9 * V_10 ,
bool (* F_37)( const struct V_9 * V_10 ,
const struct V_4 * V_53 ) )
{
unsigned int V_34 ;
F_38 ( & V_10 -> V_19 ) ;
for ( V_34 = 0 ; V_34 < V_10 -> V_15 . V_16 ; V_34 ++ ) {
struct V_4 * V_54 ;
struct V_17 * V_18 , * V_55 ;
F_39 (dh, pos, n, &ht->hash[i], node) {
if ( (* F_37)( V_10 , V_54 ) )
F_21 ( V_10 , V_54 ) ;
}
}
F_40 ( & V_10 -> V_19 ) ;
}
static void V_48 ( unsigned long V_56 )
{
struct V_9 * V_10 = (struct V_9 * ) V_56 ;
F_36 ( V_10 , F_34 ) ;
V_10 -> V_47 . V_49 = V_50 + F_30 ( V_10 -> V_15 . V_51 ) ;
F_31 ( & V_10 -> V_47 ) ;
}
static void F_41 ( struct V_9 * V_33 )
{
struct V_1 * V_1 = F_1 ( V_33 -> V_2 ) ;
struct V_57 * V_58 ;
F_42 ( & V_33 -> V_47 ) ;
if ( V_33 -> V_32 == V_43 )
V_58 = V_1 -> V_44 ;
else
V_58 = V_1 -> V_45 ;
if( V_58 != NULL )
F_43 ( V_33 -> V_41 -> V_42 , V_58 ) ;
F_36 ( V_33 , F_33 ) ;
F_28 ( V_33 ) ;
}
static struct V_9 * F_44 ( struct V_2 * V_2 ,
const char * V_42 ,
T_2 V_32 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_33 ;
struct V_17 * V_18 ;
F_45 (hinfo, pos, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_42 , V_33 -> V_41 -> V_42 ) &&
V_33 -> V_32 == V_32 ) {
V_33 -> V_40 ++ ;
return V_33 ;
}
}
return NULL ;
}
static void F_46 ( struct V_9 * V_33 )
{
F_47 ( & V_59 ) ;
if ( -- V_33 -> V_40 == 0 ) {
F_48 ( & V_33 -> V_26 ) ;
F_41 ( V_33 ) ;
}
F_49 ( & V_59 ) ;
}
static V_12 F_50 ( V_12 V_60 )
{
return ( V_60 >> V_61 ) + 1 ;
}
static V_12 F_51 ( V_12 V_62 )
{
if ( V_62 > 0xFFFFFFFF / ( V_63 * V_64 ) )
return ( V_62 / V_65 ) * V_63 * V_64 ;
return ( V_62 * V_63 * V_64 ) / V_65 ;
}
static V_12 F_52 ( V_12 V_62 )
{
V_14 V_66 = V_62 ;
V_66 *= V_63 * V_67 ;
return ( V_12 ) ( V_66 >> 32 ) ;
}
static void F_53 ( struct V_4 * V_54 , unsigned long V_68 , V_12 V_69 )
{
unsigned long V_70 = V_68 - V_54 -> V_71 . V_72 ;
V_12 V_73 ;
if ( V_70 == 0 )
return;
V_54 -> V_71 . V_72 = V_68 ;
if ( V_69 & V_74 ) {
V_12 V_75 = V_54 -> V_71 . V_76 ;
V_54 -> V_71 . V_76 += V_67 * V_70 ;
V_73 = V_67 * V_63 ;
if ( V_75 >= V_54 -> V_71 . V_76 ) {
V_54 -> V_71 . V_76 = V_73 ;
return;
}
} else {
V_54 -> V_71 . V_76 += V_70 * V_64 ;
V_73 = V_54 -> V_71 . V_77 ;
}
if ( V_54 -> V_71 . V_76 > V_73 )
V_54 -> V_71 . V_76 = V_73 ;
}
static void F_54 ( struct V_4 * V_54 ,
struct V_9 * V_33 )
{
V_54 -> V_71 . V_72 = V_50 ;
if ( V_33 -> V_15 . V_69 & V_74 ) {
V_54 -> V_71 . V_76 = V_67 * V_63 ;
V_54 -> V_71 . V_78 = F_52 ( V_33 -> V_15 . V_79 ) ;
V_54 -> V_71 . V_77 = V_33 -> V_15 . V_80 ;
} else {
V_54 -> V_71 . V_76 = F_51 ( V_33 -> V_15 . V_79 *
V_33 -> V_15 . V_80 ) ;
V_54 -> V_71 . V_78 = F_51 ( V_33 -> V_15 . V_79 ) ;
V_54 -> V_71 . V_77 = V_54 -> V_71 . V_76 ;
}
}
static inline T_3 F_55 ( T_3 V_81 , unsigned int V_82 )
{
return V_82 ? F_56 ( F_57 ( V_81 ) & ~ 0 << ( 32 - V_82 ) ) : 0 ;
}
static void F_58 ( T_3 * V_34 , unsigned int V_83 )
{
switch ( V_83 ) {
case 0 ... 31 :
V_34 [ 0 ] = F_55 ( V_34 [ 0 ] , V_83 ) ;
V_34 [ 1 ] = V_34 [ 2 ] = V_34 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_34 [ 1 ] = F_55 ( V_34 [ 1 ] , V_83 - 32 ) ;
V_34 [ 2 ] = V_34 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_34 [ 2 ] = F_55 ( V_34 [ 2 ] , V_83 - 64 ) ;
V_34 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_34 [ 3 ] = F_55 ( V_34 [ 3 ] , V_83 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_59 ( const struct V_9 * V_33 ,
struct V_6 * V_8 ,
const struct V_84 * V_85 , unsigned int V_86 )
{
T_4 V_87 [ 2 ] , * V_88 ;
T_5 V_89 ;
int V_90 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_33 -> V_32 ) {
case V_43 :
if ( V_33 -> V_15 . V_69 & V_91 )
V_8 -> V_92 . V_8 = F_55 ( F_60 ( V_85 ) -> V_93 ,
V_33 -> V_15 . V_94 ) ;
if ( V_33 -> V_15 . V_69 & V_95 )
V_8 -> V_92 . V_96 = F_55 ( F_60 ( V_85 ) -> V_97 ,
V_33 -> V_15 . V_98 ) ;
if ( ! ( V_33 -> V_15 . V_69 &
( V_99 | V_100 ) ) )
return 0 ;
V_89 = F_60 ( V_85 ) -> V_101 ;
break;
#if F_61 ( V_102 )
case V_103 :
{
T_4 V_104 ;
if ( V_33 -> V_15 . V_69 & V_91 ) {
memcpy ( & V_8 -> V_105 . V_8 , & F_62 ( V_85 ) -> V_93 ,
sizeof( V_8 -> V_105 . V_8 ) ) ;
F_58 ( V_8 -> V_105 . V_8 , V_33 -> V_15 . V_94 ) ;
}
if ( V_33 -> V_15 . V_69 & V_95 ) {
memcpy ( & V_8 -> V_105 . V_96 , & F_62 ( V_85 ) -> V_97 ,
sizeof( V_8 -> V_105 . V_96 ) ) ;
F_58 ( V_8 -> V_105 . V_96 , V_33 -> V_15 . V_98 ) ;
}
if ( ! ( V_33 -> V_15 . V_69 &
( V_99 | V_100 ) ) )
return 0 ;
V_89 = F_62 ( V_85 ) -> V_89 ;
V_86 = F_63 ( V_85 , sizeof( struct V_106 ) , & V_89 , & V_104 ) ;
if ( ( int ) V_86 < 0 )
return - 1 ;
break;
}
#endif
default:
F_64 () ;
return 0 ;
}
V_90 = F_65 ( V_89 ) ;
if ( V_90 >= 0 ) {
V_88 = F_66 ( V_85 , V_86 + V_90 , sizeof( V_87 ) ,
& V_87 ) ;
} else {
V_87 [ 0 ] = V_87 [ 1 ] = 0 ;
V_88 = V_87 ;
}
if ( ! V_88 )
return - 1 ;
if ( V_33 -> V_15 . V_69 & V_100 )
V_8 -> V_107 = V_88 [ 0 ] ;
if ( V_33 -> V_15 . V_69 & V_99 )
V_8 -> V_108 = V_88 [ 1 ] ;
return 0 ;
}
static V_12 F_67 ( unsigned int V_60 , struct V_4 * V_54 )
{
V_14 V_75 = F_50 ( V_60 ) ;
V_75 = V_75 * V_54 -> V_71 . V_78 ;
if ( F_12 ( V_75 > V_67 * V_63 ) )
V_75 = V_67 * V_63 ;
if ( V_54 -> V_71 . V_76 < V_75 && V_54 -> V_71 . V_77 ) {
V_54 -> V_71 . V_77 -- ;
V_54 -> V_71 . V_76 = V_67 * V_63 ;
}
return ( V_12 ) V_75 ;
}
static bool
F_68 ( const struct V_84 * V_85 , struct V_109 * V_110 )
{
const struct V_30 * V_111 = V_110 -> V_112 ;
struct V_9 * V_33 = V_111 -> V_33 ;
unsigned long V_68 = V_50 ;
struct V_4 * V_54 ;
struct V_6 V_8 ;
bool V_20 = false ;
V_12 V_78 ;
if ( F_59 ( V_33 , & V_8 , V_85 , V_110 -> V_113 ) < 0 )
goto V_114;
F_69 () ;
V_54 = F_6 ( V_33 , & V_8 ) ;
if ( V_54 == NULL ) {
V_54 = F_10 ( V_33 , & V_8 , & V_20 ) ;
if ( V_54 == NULL ) {
F_70 () ;
goto V_114;
} else if ( V_20 ) {
V_54 -> V_49 = V_68 + F_30 ( V_33 -> V_15 . V_115 ) ;
F_53 ( V_54 , V_68 , V_33 -> V_15 . V_69 ) ;
} else {
V_54 -> V_49 = V_50 + F_30 ( V_33 -> V_15 . V_115 ) ;
F_54 ( V_54 , V_33 ) ;
}
} else {
V_54 -> V_49 = V_68 + F_30 ( V_33 -> V_15 . V_115 ) ;
F_53 ( V_54 , V_68 , V_33 -> V_15 . V_69 ) ;
}
if ( V_111 -> V_15 . V_69 & V_74 )
V_78 = F_67 ( V_85 -> V_60 , V_54 ) ;
else
V_78 = V_54 -> V_71 . V_78 ;
if ( V_54 -> V_71 . V_76 >= V_78 ) {
V_54 -> V_71 . V_76 -= V_78 ;
F_11 ( & V_54 -> V_19 ) ;
F_70 () ;
return ! ( V_111 -> V_15 . V_69 & V_116 ) ;
}
F_11 ( & V_54 -> V_19 ) ;
F_70 () ;
return V_111 -> V_15 . V_69 & V_116 ;
V_114:
V_110 -> V_114 = true ;
return false ;
}
static int F_71 ( const struct V_117 * V_110 )
{
struct V_2 * V_2 = V_110 -> V_2 ;
struct V_30 * V_111 = V_110 -> V_112 ;
int V_118 ;
if ( V_111 -> V_15 . V_51 == 0 || V_111 -> V_15 . V_115 == 0 )
return - V_119 ;
if ( V_111 -> V_42 [ sizeof( V_111 -> V_42 ) - 1 ] != '\0' )
return - V_119 ;
if ( V_110 -> V_32 == V_43 ) {
if ( V_111 -> V_15 . V_98 > 32 || V_111 -> V_15 . V_94 > 32 )
return - V_119 ;
} else {
if ( V_111 -> V_15 . V_98 > 128 || V_111 -> V_15 . V_94 > 128 )
return - V_119 ;
}
if ( V_111 -> V_15 . V_69 & ~ V_120 ) {
F_72 ( L_2 ,
V_111 -> V_15 . V_69 ) ;
return - V_119 ;
}
if ( V_111 -> V_15 . V_69 & V_74 ) {
if ( F_52 ( V_111 -> V_15 . V_79 ) == 0 ) {
F_72 ( L_3 , V_111 -> V_15 . V_79 ) ;
return - V_119 ;
}
} else if ( V_111 -> V_15 . V_80 == 0 ||
F_51 ( V_111 -> V_15 . V_79 * V_111 -> V_15 . V_80 ) <
F_51 ( V_111 -> V_15 . V_79 ) ) {
F_72 ( L_4 ,
V_111 -> V_15 . V_79 , V_111 -> V_15 . V_80 ) ;
return - V_121 ;
}
F_47 ( & V_59 ) ;
V_111 -> V_33 = F_44 ( V_2 , V_111 -> V_42 , V_110 -> V_32 ) ;
if ( V_111 -> V_33 == NULL ) {
V_118 = F_24 ( V_2 , V_111 , V_110 -> V_32 ) ;
if ( V_118 < 0 ) {
F_49 ( & V_59 ) ;
return V_118 ;
}
}
F_49 ( & V_59 ) ;
return 0 ;
}
static void F_73 ( const struct V_122 * V_110 )
{
const struct V_30 * V_111 = V_110 -> V_112 ;
F_46 ( V_111 -> V_33 ) ;
}
static void * F_74 ( struct V_123 * V_124 , T_6 * V_18 )
__acquires( V_125 -> V_19 )
{
struct V_9 * V_125 = V_124 -> V_126 ;
unsigned int * V_127 ;
F_38 ( & V_125 -> V_19 ) ;
if ( * V_18 >= V_125 -> V_15 . V_16 )
return NULL ;
V_127 = F_75 ( sizeof( unsigned int ) , V_25 ) ;
if ( ! V_127 )
return F_76 ( - V_39 ) ;
* V_127 = * V_18 ;
return V_127 ;
}
static void * F_77 ( struct V_123 * V_124 , void * V_128 , T_6 * V_18 )
{
struct V_9 * V_125 = V_124 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
* V_18 = ++ ( * V_127 ) ;
if ( * V_18 >= V_125 -> V_15 . V_16 ) {
F_78 ( V_128 ) ;
return NULL ;
}
return V_127 ;
}
static void F_79 ( struct V_123 * V_124 , void * V_128 )
__releases( V_125 -> V_19 )
{
struct V_9 * V_125 = V_124 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
if ( ! F_80 ( V_127 ) )
F_78 ( V_127 ) ;
F_40 ( & V_125 -> V_19 ) ;
}
static int F_81 ( struct V_4 * V_5 , T_2 V_32 ,
struct V_123 * V_124 )
{
int V_129 ;
const struct V_9 * V_10 = V_124 -> V_126 ;
F_9 ( & V_5 -> V_19 ) ;
F_53 ( V_5 , V_50 , V_10 -> V_15 . V_69 ) ;
switch ( V_32 ) {
case V_43 :
V_129 = F_82 ( V_124 , L_5 ,
( long ) ( V_5 -> V_49 - V_50 ) / V_63 ,
& V_5 -> V_8 . V_92 . V_96 ,
F_83 ( V_5 -> V_8 . V_107 ) ,
& V_5 -> V_8 . V_92 . V_8 ,
F_83 ( V_5 -> V_8 . V_108 ) ,
V_5 -> V_71 . V_76 , V_5 -> V_71 . V_77 ,
V_5 -> V_71 . V_78 ) ;
break;
#if F_61 ( V_102 )
case V_103 :
V_129 = F_82 ( V_124 , L_6 ,
( long ) ( V_5 -> V_49 - V_50 ) / V_63 ,
& V_5 -> V_8 . V_105 . V_96 ,
F_83 ( V_5 -> V_8 . V_107 ) ,
& V_5 -> V_8 . V_105 . V_8 ,
F_83 ( V_5 -> V_8 . V_108 ) ,
V_5 -> V_71 . V_76 , V_5 -> V_71 . V_77 ,
V_5 -> V_71 . V_78 ) ;
break;
#endif
default:
F_64 () ;
V_129 = 0 ;
}
F_11 ( & V_5 -> V_19 ) ;
return V_129 ;
}
static int F_84 ( struct V_123 * V_124 , void * V_128 )
{
struct V_9 * V_125 = V_124 -> V_126 ;
unsigned int * V_127 = ( unsigned int * ) V_128 ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
if ( ! F_7 ( & V_125 -> V_11 [ * V_127 ] ) ) {
F_45 (ent, pos, &htable->hash[*bucket], node)
if ( F_81 ( V_5 , V_125 -> V_32 , V_124 ) )
return - 1 ;
}
return 0 ;
}
static int F_85 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
int V_118 = F_86 ( V_131 , & V_132 ) ;
if ( ! V_118 ) {
struct V_123 * V_133 = V_131 -> V_134 ;
V_133 -> V_126 = F_87 ( V_130 ) -> V_135 ;
}
return V_118 ;
}
static int T_7 F_88 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_44 = F_89 ( L_7 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_44 )
return - V_39 ;
#if F_61 ( V_102 )
V_1 -> V_45 = F_89 ( L_8 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_45 ) {
F_90 ( V_2 , L_7 ) ;
return - V_39 ;
}
#endif
return 0 ;
}
static void T_8 F_91 ( struct V_2 * V_2 )
{
struct V_9 * V_33 ;
struct V_17 * V_18 ;
struct V_57 * V_41 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_47 ( & V_59 ) ;
V_41 = V_1 -> V_44 ;
if ( V_41 == NULL )
V_41 = V_1 -> V_45 ;
F_45 (hinfo, pos, &hashlimit_net->htables, node)
F_43 ( V_33 -> V_41 -> V_42 , V_41 ) ;
V_1 -> V_44 = NULL ;
V_1 -> V_45 = NULL ;
F_49 ( & V_59 ) ;
F_90 ( V_2 , L_7 ) ;
#if F_61 ( V_102 )
F_90 ( V_2 , L_8 ) ;
#endif
}
static int T_7 F_92 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_26 ( & V_1 -> V_52 ) ;
return F_88 ( V_2 ) ;
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
V_137 = - V_39 ;
V_24 = F_98 ( L_9 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_24 ) {
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
F_104 ( V_24 ) ;
}
