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
F_31 ( & V_31 -> V_46 , V_47 ) ;
F_32 ( V_48 , & V_31 -> V_46 ,
F_33 ( V_31 -> V_15 . V_49 ) ) ;
F_34 ( & V_31 -> V_24 , & V_1 -> V_50 ) ;
return 0 ;
}
static bool F_35 ( const struct V_9 * V_10 ,
const struct V_4 * V_51 )
{
return 1 ;
}
static bool F_36 ( const struct V_9 * V_10 ,
const struct V_4 * V_51 )
{
return F_37 ( V_52 , V_51 -> V_53 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
bool (* F_39)( const struct V_9 * V_10 ,
const struct V_4 * V_51 ) )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_15 . V_16 ; V_32 ++ ) {
struct V_4 * V_54 ;
struct V_55 * V_56 ;
F_40 ( & V_10 -> V_17 ) ;
F_41 (dh, n, &ht->hash[i], node) {
if ( (* F_39)( V_10 , V_54 ) )
F_21 ( V_10 , V_54 ) ;
}
F_42 ( & V_10 -> V_17 ) ;
F_43 () ;
}
}
static void V_47 ( struct V_57 * V_58 )
{
struct V_9 * V_10 ;
V_10 = F_19 ( V_58 , struct V_9 , V_46 . V_58 ) ;
F_38 ( V_10 , F_36 ) ;
F_32 ( V_48 ,
& V_10 -> V_46 , F_33 ( V_10 -> V_15 . V_49 ) ) ;
}
static void F_44 ( struct V_9 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_31 -> V_2 ) ;
struct V_59 * V_60 ;
if ( V_31 -> V_30 == V_42 )
V_60 = V_1 -> V_43 ;
else
V_60 = V_1 -> V_44 ;
if ( V_60 != NULL )
F_45 ( V_31 -> V_39 , V_60 ) ;
}
static void F_46 ( struct V_9 * V_31 )
{
F_47 ( & V_31 -> V_46 ) ;
F_44 ( V_31 ) ;
F_38 ( V_31 , F_35 ) ;
F_30 ( V_31 -> V_39 ) ;
F_28 ( V_31 ) ;
}
static struct V_9 * F_48 ( struct V_2 * V_2 ,
const char * V_39 ,
T_2 V_30 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_31 ;
F_49 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_39 , V_31 -> V_39 ) &&
V_31 -> V_30 == V_30 ) {
V_31 -> V_38 ++ ;
return V_31 ;
}
}
return NULL ;
}
static void F_50 ( struct V_9 * V_31 )
{
F_51 ( & V_61 ) ;
if ( -- V_31 -> V_38 == 0 ) {
F_52 ( & V_31 -> V_24 ) ;
F_46 ( V_31 ) ;
}
F_53 ( & V_61 ) ;
}
static V_12 F_54 ( V_12 V_62 )
{
return ( V_62 >> V_63 ) + 1 ;
}
static V_12 F_55 ( V_12 V_64 )
{
if ( V_64 > 0xFFFFFFFF / ( V_65 * V_66 ) )
return ( V_64 / V_67 ) * V_65 * V_66 ;
return ( V_64 * V_65 * V_66 ) / V_67 ;
}
static V_12 F_56 ( V_12 V_64 )
{
V_14 V_68 = V_64 ;
V_68 *= V_65 * V_69 ;
return ( V_12 ) ( V_68 >> 32 ) ;
}
static void F_57 ( struct V_4 * V_54 , unsigned long V_70 , V_12 V_71 )
{
unsigned long V_72 = V_70 - V_54 -> V_73 . V_74 ;
V_12 V_75 ;
if ( V_72 == 0 )
return;
V_54 -> V_73 . V_74 = V_70 ;
if ( V_71 & V_76 ) {
V_12 V_77 = V_54 -> V_73 . V_78 ;
V_54 -> V_73 . V_78 += V_69 * V_72 ;
V_75 = V_69 * V_65 ;
if ( V_77 >= V_54 -> V_73 . V_78 ) {
V_54 -> V_73 . V_78 = V_75 ;
return;
}
} else {
V_54 -> V_73 . V_78 += V_72 * V_66 ;
V_75 = V_54 -> V_73 . V_79 ;
}
if ( V_54 -> V_73 . V_78 > V_75 )
V_54 -> V_73 . V_78 = V_75 ;
}
static void F_58 ( struct V_4 * V_54 ,
struct V_9 * V_31 )
{
V_54 -> V_73 . V_74 = V_52 ;
if ( V_31 -> V_15 . V_71 & V_76 ) {
V_54 -> V_73 . V_78 = V_69 * V_65 ;
V_54 -> V_73 . V_80 = F_56 ( V_31 -> V_15 . V_81 ) ;
V_54 -> V_73 . V_79 = V_31 -> V_15 . V_82 ;
} else {
V_54 -> V_73 . V_78 = F_55 ( V_31 -> V_15 . V_81 *
V_31 -> V_15 . V_82 ) ;
V_54 -> V_73 . V_80 = F_55 ( V_31 -> V_15 . V_81 ) ;
V_54 -> V_73 . V_79 = V_54 -> V_73 . V_78 ;
}
}
static inline T_3 F_59 ( T_3 V_83 , unsigned int V_84 )
{
return V_84 ? F_60 ( F_61 ( V_83 ) & ~ 0 << ( 32 - V_84 ) ) : 0 ;
}
static void F_62 ( T_3 * V_32 , unsigned int V_85 )
{
switch ( V_85 ) {
case 0 ... 31 :
V_32 [ 0 ] = F_59 ( V_32 [ 0 ] , V_85 ) ;
V_32 [ 1 ] = V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_32 [ 1 ] = F_59 ( V_32 [ 1 ] , V_85 - 32 ) ;
V_32 [ 2 ] = V_32 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_32 [ 2 ] = F_59 ( V_32 [ 2 ] , V_85 - 64 ) ;
V_32 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_32 [ 3 ] = F_59 ( V_32 [ 3 ] , V_85 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_63 ( const struct V_9 * V_31 ,
struct V_6 * V_8 ,
const struct V_86 * V_87 , unsigned int V_88 )
{
T_4 V_89 [ 2 ] , * V_90 ;
T_5 V_91 ;
int V_92 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_31 -> V_30 ) {
case V_42 :
if ( V_31 -> V_15 . V_71 & V_93 )
V_8 -> V_94 . V_8 = F_59 ( F_64 ( V_87 ) -> V_95 ,
V_31 -> V_15 . V_96 ) ;
if ( V_31 -> V_15 . V_71 & V_97 )
V_8 -> V_94 . V_98 = F_59 ( F_64 ( V_87 ) -> V_99 ,
V_31 -> V_15 . V_100 ) ;
if ( ! ( V_31 -> V_15 . V_71 &
( V_101 | V_102 ) ) )
return 0 ;
V_91 = F_64 ( V_87 ) -> V_103 ;
break;
#if F_65 ( V_104 )
case V_105 :
{
T_4 V_106 ;
if ( V_31 -> V_15 . V_71 & V_93 ) {
memcpy ( & V_8 -> V_107 . V_8 , & F_66 ( V_87 ) -> V_95 ,
sizeof( V_8 -> V_107 . V_8 ) ) ;
F_62 ( V_8 -> V_107 . V_8 , V_31 -> V_15 . V_96 ) ;
}
if ( V_31 -> V_15 . V_71 & V_97 ) {
memcpy ( & V_8 -> V_107 . V_98 , & F_66 ( V_87 ) -> V_99 ,
sizeof( V_8 -> V_107 . V_98 ) ) ;
F_62 ( V_8 -> V_107 . V_98 , V_31 -> V_15 . V_100 ) ;
}
if ( ! ( V_31 -> V_15 . V_71 &
( V_101 | V_102 ) ) )
return 0 ;
V_91 = F_66 ( V_87 ) -> V_91 ;
V_88 = F_67 ( V_87 , sizeof( struct V_108 ) , & V_91 , & V_106 ) ;
if ( ( int ) V_88 < 0 )
return - 1 ;
break;
}
#endif
default:
F_68 () ;
return 0 ;
}
V_92 = F_69 ( V_91 ) ;
if ( V_92 >= 0 ) {
V_90 = F_70 ( V_87 , V_88 + V_92 , sizeof( V_89 ) ,
& V_89 ) ;
} else {
V_89 [ 0 ] = V_89 [ 1 ] = 0 ;
V_90 = V_89 ;
}
if ( ! V_90 )
return - 1 ;
if ( V_31 -> V_15 . V_71 & V_102 )
V_8 -> V_109 = V_90 [ 0 ] ;
if ( V_31 -> V_15 . V_71 & V_101 )
V_8 -> V_110 = V_90 [ 1 ] ;
return 0 ;
}
static V_12 F_71 ( unsigned int V_62 , struct V_4 * V_54 )
{
V_14 V_77 = F_54 ( V_62 ) ;
V_77 = V_77 * V_54 -> V_73 . V_80 ;
if ( F_12 ( V_77 > V_69 * V_65 ) )
V_77 = V_69 * V_65 ;
if ( V_54 -> V_73 . V_78 < V_77 && V_54 -> V_73 . V_79 ) {
V_54 -> V_73 . V_79 -- ;
V_54 -> V_73 . V_78 = V_69 * V_65 ;
}
return ( V_12 ) V_77 ;
}
static bool
F_72 ( const struct V_86 * V_87 , struct V_111 * V_112 )
{
const struct V_28 * V_113 = V_112 -> V_114 ;
struct V_9 * V_31 = V_113 -> V_31 ;
unsigned long V_70 = V_52 ;
struct V_4 * V_54 ;
struct V_6 V_8 ;
bool V_18 = false ;
V_12 V_80 ;
if ( F_63 ( V_31 , & V_8 , V_87 , V_112 -> V_115 ) < 0 )
goto V_116;
F_73 () ;
V_54 = F_6 ( V_31 , & V_8 ) ;
if ( V_54 == NULL ) {
V_54 = F_10 ( V_31 , & V_8 , & V_18 ) ;
if ( V_54 == NULL ) {
F_74 () ;
goto V_116;
} else if ( V_18 ) {
V_54 -> V_53 = V_70 + F_33 ( V_31 -> V_15 . V_117 ) ;
F_57 ( V_54 , V_70 , V_31 -> V_15 . V_71 ) ;
} else {
V_54 -> V_53 = V_52 + F_33 ( V_31 -> V_15 . V_117 ) ;
F_58 ( V_54 , V_31 ) ;
}
} else {
V_54 -> V_53 = V_70 + F_33 ( V_31 -> V_15 . V_117 ) ;
F_57 ( V_54 , V_70 , V_31 -> V_15 . V_71 ) ;
}
if ( V_113 -> V_15 . V_71 & V_76 )
V_80 = F_71 ( V_87 -> V_62 , V_54 ) ;
else
V_80 = V_54 -> V_73 . V_80 ;
if ( V_54 -> V_73 . V_78 >= V_80 ) {
V_54 -> V_73 . V_78 -= V_80 ;
F_11 ( & V_54 -> V_17 ) ;
F_74 () ;
return ! ( V_113 -> V_15 . V_71 & V_118 ) ;
}
F_11 ( & V_54 -> V_17 ) ;
F_74 () ;
return V_113 -> V_15 . V_71 & V_118 ;
V_116:
V_112 -> V_116 = true ;
return false ;
}
static int F_75 ( const struct V_119 * V_112 )
{
struct V_2 * V_2 = V_112 -> V_2 ;
struct V_28 * V_113 = V_112 -> V_114 ;
int V_120 ;
if ( V_113 -> V_15 . V_49 == 0 || V_113 -> V_15 . V_117 == 0 )
return - V_121 ;
if ( V_113 -> V_39 [ sizeof( V_113 -> V_39 ) - 1 ] != '\0' )
return - V_121 ;
if ( V_112 -> V_30 == V_42 ) {
if ( V_113 -> V_15 . V_100 > 32 || V_113 -> V_15 . V_96 > 32 )
return - V_121 ;
} else {
if ( V_113 -> V_15 . V_100 > 128 || V_113 -> V_15 . V_96 > 128 )
return - V_121 ;
}
if ( V_113 -> V_15 . V_71 & ~ V_122 ) {
F_76 ( L_2 ,
V_113 -> V_15 . V_71 ) ;
return - V_121 ;
}
if ( V_113 -> V_15 . V_71 & V_76 ) {
if ( F_56 ( V_113 -> V_15 . V_81 ) == 0 ) {
F_76 ( L_3 , V_113 -> V_15 . V_81 ) ;
return - V_121 ;
}
} else if ( V_113 -> V_15 . V_82 == 0 ||
F_55 ( V_113 -> V_15 . V_81 * V_113 -> V_15 . V_82 ) <
F_55 ( V_113 -> V_15 . V_81 ) ) {
F_76 ( L_4 ,
V_113 -> V_15 . V_81 , V_113 -> V_15 . V_82 ) ;
return - V_123 ;
}
F_51 ( & V_61 ) ;
V_113 -> V_31 = F_48 ( V_2 , V_113 -> V_39 , V_112 -> V_30 ) ;
if ( V_113 -> V_31 == NULL ) {
V_120 = F_24 ( V_2 , V_113 , V_112 -> V_30 ) ;
if ( V_120 < 0 ) {
F_53 ( & V_61 ) ;
return V_120 ;
}
}
F_53 ( & V_61 ) ;
return 0 ;
}
static void F_77 ( const struct V_124 * V_112 )
{
const struct V_28 * V_113 = V_112 -> V_114 ;
F_50 ( V_113 -> V_31 ) ;
}
static void * F_78 ( struct V_125 * V_126 , T_6 * V_127 )
__acquires( V_128 -> V_17 )
{
struct V_9 * V_128 = V_126 -> V_129 ;
unsigned int * V_130 ;
F_40 ( & V_128 -> V_17 ) ;
if ( * V_127 >= V_128 -> V_15 . V_16 )
return NULL ;
V_130 = F_79 ( sizeof( unsigned int ) , V_23 ) ;
if ( ! V_130 )
return F_80 ( - V_37 ) ;
* V_130 = * V_127 ;
return V_130 ;
}
static void * F_81 ( struct V_125 * V_126 , void * V_131 , T_6 * V_127 )
{
struct V_9 * V_128 = V_126 -> V_129 ;
unsigned int * V_130 = ( unsigned int * ) V_131 ;
* V_127 = ++ ( * V_130 ) ;
if ( * V_127 >= V_128 -> V_15 . V_16 ) {
F_30 ( V_131 ) ;
return NULL ;
}
return V_130 ;
}
static void F_82 ( struct V_125 * V_126 , void * V_131 )
__releases( V_128 -> V_17 )
{
struct V_9 * V_128 = V_126 -> V_129 ;
unsigned int * V_130 = ( unsigned int * ) V_131 ;
if ( ! F_83 ( V_130 ) )
F_30 ( V_130 ) ;
F_42 ( & V_128 -> V_17 ) ;
}
static int F_84 ( struct V_4 * V_5 , T_2 V_30 ,
struct V_125 * V_126 )
{
int V_132 ;
const struct V_9 * V_10 = V_126 -> V_129 ;
F_9 ( & V_5 -> V_17 ) ;
F_57 ( V_5 , V_52 , V_10 -> V_15 . V_71 ) ;
switch ( V_30 ) {
case V_42 :
V_132 = F_85 ( V_126 , L_5 ,
( long ) ( V_5 -> V_53 - V_52 ) / V_65 ,
& V_5 -> V_8 . V_94 . V_98 ,
F_86 ( V_5 -> V_8 . V_109 ) ,
& V_5 -> V_8 . V_94 . V_8 ,
F_86 ( V_5 -> V_8 . V_110 ) ,
V_5 -> V_73 . V_78 , V_5 -> V_73 . V_79 ,
V_5 -> V_73 . V_80 ) ;
break;
#if F_65 ( V_104 )
case V_105 :
V_132 = F_85 ( V_126 , L_6 ,
( long ) ( V_5 -> V_53 - V_52 ) / V_65 ,
& V_5 -> V_8 . V_107 . V_98 ,
F_86 ( V_5 -> V_8 . V_109 ) ,
& V_5 -> V_8 . V_107 . V_8 ,
F_86 ( V_5 -> V_8 . V_110 ) ,
V_5 -> V_73 . V_78 , V_5 -> V_73 . V_79 ,
V_5 -> V_73 . V_80 ) ;
break;
#endif
default:
F_68 () ;
V_132 = 0 ;
}
F_11 ( & V_5 -> V_17 ) ;
return V_132 ;
}
static int F_87 ( struct V_125 * V_126 , void * V_131 )
{
struct V_9 * V_128 = V_126 -> V_129 ;
unsigned int * V_130 = ( unsigned int * ) V_131 ;
struct V_4 * V_5 ;
if ( ! F_7 ( & V_128 -> V_11 [ * V_130 ] ) ) {
F_49 (ent, &htable->hash[*bucket], node)
if ( F_84 ( V_5 , V_128 -> V_30 , V_126 ) )
return - 1 ;
}
return 0 ;
}
static int F_88 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
int V_120 = F_89 ( V_134 , & V_135 ) ;
if ( ! V_120 ) {
struct V_125 * V_136 = V_134 -> V_137 ;
V_136 -> V_129 = F_90 ( V_133 ) ;
}
return V_120 ;
}
static int T_7 F_91 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_43 = F_92 ( L_7 , V_2 -> V_138 ) ;
if ( ! V_1 -> V_43 )
return - V_37 ;
#if F_65 ( V_104 )
V_1 -> V_44 = F_92 ( L_8 , V_2 -> V_138 ) ;
if ( ! V_1 -> V_44 ) {
F_45 ( L_7 , V_2 -> V_138 ) ;
return - V_37 ;
}
#endif
return 0 ;
}
static void T_8 F_93 ( struct V_2 * V_2 )
{
struct V_9 * V_31 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_51 ( & V_61 ) ;
F_49 (hinfo, &hashlimit_net->htables, node)
F_44 ( V_31 ) ;
V_1 -> V_43 = NULL ;
V_1 -> V_44 = NULL ;
F_53 ( & V_61 ) ;
F_45 ( L_7 , V_2 -> V_138 ) ;
#if F_65 ( V_104 )
F_45 ( L_8 , V_2 -> V_138 ) ;
#endif
}
static int T_7 F_94 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_26 ( & V_1 -> V_50 ) ;
return F_91 ( V_2 ) ;
}
static void T_8 F_95 ( struct V_2 * V_2 )
{
F_93 ( V_2 ) ;
}
static int T_9 F_96 ( void )
{
int V_139 ;
V_139 = F_97 ( & V_140 ) ;
if ( V_139 < 0 )
return V_139 ;
V_139 = F_98 ( V_141 ,
F_99 ( V_141 ) ) ;
if ( V_139 < 0 )
goto V_142;
V_139 = - V_37 ;
V_22 = F_100 ( L_9 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_22 ) {
F_101 ( L_10 ) ;
goto V_143;
}
return 0 ;
V_143:
F_102 ( V_141 , F_99 ( V_141 ) ) ;
V_142:
F_103 ( & V_140 ) ;
return V_139 ;
}
static void T_10 F_104 ( void )
{
F_102 ( V_141 , F_99 ( V_141 ) ) ;
F_103 ( & V_140 ) ;
F_105 () ;
F_106 ( V_22 ) ;
}
