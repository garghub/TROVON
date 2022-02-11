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
return F_6 ( V_11 , V_10 -> V_14 . V_15 ) ;
}
static struct V_4 *
F_7 ( const struct V_9 * V_10 ,
const struct V_6 * V_8 )
{
struct V_4 * V_5 ;
T_1 V_11 = F_4 ( V_10 , V_8 ) ;
if ( ! F_8 ( & V_10 -> V_11 [ V_11 ] ) ) {
F_9 (ent, &ht->hash[hash], node)
if ( F_3 ( V_5 , V_8 ) ) {
F_10 ( & V_5 -> V_16 ) ;
return V_5 ;
}
}
return NULL ;
}
static struct V_4 *
F_11 ( struct V_9 * V_10 ,
const struct V_6 * V_8 , bool * V_17 )
{
struct V_4 * V_5 ;
F_10 ( & V_10 -> V_16 ) ;
V_5 = F_7 ( V_10 , V_8 ) ;
if ( V_5 != NULL ) {
F_12 ( & V_10 -> V_16 ) ;
* V_17 = true ;
return V_5 ;
}
if ( F_13 ( ! V_10 -> V_18 ) ) {
F_14 ( & V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
V_10 -> V_18 = true ;
}
if ( V_10 -> V_14 . V_19 && V_10 -> V_20 >= V_10 -> V_14 . V_19 ) {
F_15 ( L_1 , V_10 -> V_14 . V_19 ) ;
V_5 = NULL ;
} else
V_5 = F_16 ( V_21 , V_22 ) ;
if ( V_5 ) {
memcpy ( & V_5 -> V_8 , V_8 , sizeof( V_5 -> V_8 ) ) ;
F_17 ( & V_5 -> V_16 ) ;
F_10 ( & V_5 -> V_16 ) ;
F_18 ( & V_5 -> V_23 , & V_10 -> V_11 [ F_4 ( V_10 , V_8 ) ] ) ;
V_10 -> V_20 ++ ;
}
F_12 ( & V_10 -> V_16 ) ;
return V_5 ;
}
static void F_19 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_20 ( V_25 , struct V_4 , V_26 ) ;
F_21 ( V_21 , V_5 ) ;
}
static inline void
F_22 ( struct V_9 * V_10 , struct V_4 * V_5 )
{
F_23 ( & V_5 -> V_23 ) ;
F_24 ( & V_5 -> V_26 , F_19 ) ;
V_10 -> V_20 -- ;
}
static int F_25 ( struct V_2 * V_2 , struct V_27 * V_28 ,
T_2 V_29 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_30 ;
unsigned int V_15 ;
unsigned int V_31 ;
if ( V_28 -> V_14 . V_15 ) {
V_15 = V_28 -> V_14 . V_15 ;
} else {
V_15 = ( V_32 << V_33 ) / 16384 /
sizeof( struct V_34 ) ;
if ( V_32 > 1024 * 1024 * 1024 / V_35 )
V_15 = 8192 ;
if ( V_15 < 16 )
V_15 = 16 ;
}
V_30 = F_26 ( sizeof( struct V_9 ) +
sizeof( struct V_34 ) * V_15 ) ;
if ( V_30 == NULL )
return - V_36 ;
V_28 -> V_30 = V_30 ;
memcpy ( & V_30 -> V_14 , & V_28 -> V_14 , sizeof( V_30 -> V_14 ) ) ;
V_30 -> V_14 . V_15 = V_15 ;
if ( V_30 -> V_14 . V_19 == 0 )
V_30 -> V_14 . V_19 = 8 * V_30 -> V_14 . V_15 ;
else if ( V_30 -> V_14 . V_19 < V_30 -> V_14 . V_15 )
V_30 -> V_14 . V_19 = V_30 -> V_14 . V_15 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_14 . V_15 ; V_31 ++ )
F_27 ( & V_30 -> V_11 [ V_31 ] ) ;
V_30 -> V_37 = 1 ;
V_30 -> V_20 = 0 ;
V_30 -> V_29 = V_29 ;
V_30 -> V_18 = false ;
V_30 -> V_38 = F_28 ( V_28 -> V_38 , V_39 ) ;
if ( ! V_30 -> V_38 ) {
F_29 ( V_30 ) ;
return - V_36 ;
}
F_17 ( & V_30 -> V_16 ) ;
V_30 -> V_40 = F_30 ( V_28 -> V_38 , 0 ,
( V_29 == V_41 ) ?
V_1 -> V_42 : V_1 -> V_43 ,
& V_44 , V_30 ) ;
if ( V_30 -> V_40 == NULL ) {
F_31 ( V_30 -> V_38 ) ;
F_29 ( V_30 ) ;
return - V_36 ;
}
V_30 -> V_2 = V_2 ;
F_32 ( & V_30 -> V_45 , V_46 ) ;
F_33 ( V_47 , & V_30 -> V_45 ,
F_34 ( V_30 -> V_14 . V_48 ) ) ;
F_35 ( & V_30 -> V_23 , & V_1 -> V_49 ) ;
return 0 ;
}
static bool F_36 ( const struct V_9 * V_10 ,
const struct V_4 * V_50 )
{
return 1 ;
}
static bool F_37 ( const struct V_9 * V_10 ,
const struct V_4 * V_50 )
{
return F_38 ( V_51 , V_50 -> V_52 ) ;
}
static void F_39 ( struct V_9 * V_10 ,
bool (* F_40)( const struct V_9 * V_10 ,
const struct V_4 * V_50 ) )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_10 -> V_14 . V_15 ; V_31 ++ ) {
struct V_4 * V_53 ;
struct V_54 * V_55 ;
F_41 ( & V_10 -> V_16 ) ;
F_42 (dh, n, &ht->hash[i], node) {
if ( (* F_40)( V_10 , V_53 ) )
F_22 ( V_10 , V_53 ) ;
}
F_43 ( & V_10 -> V_16 ) ;
F_44 () ;
}
}
static void V_46 ( struct V_56 * V_57 )
{
struct V_9 * V_10 ;
V_10 = F_20 ( V_57 , struct V_9 , V_45 . V_57 ) ;
F_39 ( V_10 , F_37 ) ;
F_33 ( V_47 ,
& V_10 -> V_45 , F_34 ( V_10 -> V_14 . V_48 ) ) ;
}
static void F_45 ( struct V_9 * V_30 )
{
struct V_1 * V_1 = F_1 ( V_30 -> V_2 ) ;
struct V_58 * V_59 ;
if ( V_30 -> V_29 == V_41 )
V_59 = V_1 -> V_42 ;
else
V_59 = V_1 -> V_43 ;
if ( V_59 != NULL )
F_46 ( V_30 -> V_38 , V_59 ) ;
}
static void F_47 ( struct V_9 * V_30 )
{
F_48 ( & V_30 -> V_45 ) ;
F_45 ( V_30 ) ;
F_39 ( V_30 , F_36 ) ;
F_31 ( V_30 -> V_38 ) ;
F_29 ( V_30 ) ;
}
static struct V_9 * F_49 ( struct V_2 * V_2 ,
const char * V_38 ,
T_2 V_29 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_30 ;
F_50 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_38 , V_30 -> V_38 ) &&
V_30 -> V_29 == V_29 ) {
V_30 -> V_37 ++ ;
return V_30 ;
}
}
return NULL ;
}
static void F_51 ( struct V_9 * V_30 )
{
F_52 ( & V_60 ) ;
if ( -- V_30 -> V_37 == 0 ) {
F_53 ( & V_30 -> V_23 ) ;
F_47 ( V_30 ) ;
}
F_54 ( & V_60 ) ;
}
static V_12 F_55 ( V_12 V_61 )
{
return ( V_61 >> V_62 ) + 1 ;
}
static V_12 F_56 ( V_12 V_63 )
{
if ( V_63 > 0xFFFFFFFF / ( V_64 * V_65 ) )
return ( V_63 / V_66 ) * V_64 * V_65 ;
return ( V_63 * V_64 * V_65 ) / V_66 ;
}
static V_12 F_57 ( V_12 V_63 )
{
T_3 V_67 = V_63 ;
V_67 *= V_64 * V_68 ;
return ( V_12 ) ( V_67 >> 32 ) ;
}
static void F_58 ( struct V_4 * V_53 , unsigned long V_69 , V_12 V_70 )
{
unsigned long V_71 = V_69 - V_53 -> V_72 . V_73 ;
V_12 V_74 ;
if ( V_71 == 0 )
return;
V_53 -> V_72 . V_73 = V_69 ;
if ( V_70 & V_75 ) {
V_12 V_76 = V_53 -> V_72 . V_77 ;
V_53 -> V_72 . V_77 += V_68 * V_71 ;
V_74 = V_68 * V_64 ;
if ( V_76 >= V_53 -> V_72 . V_77 ) {
V_53 -> V_72 . V_77 = V_74 ;
return;
}
} else {
V_53 -> V_72 . V_77 += V_71 * V_65 ;
V_74 = V_53 -> V_72 . V_78 ;
}
if ( V_53 -> V_72 . V_77 > V_74 )
V_53 -> V_72 . V_77 = V_74 ;
}
static void F_59 ( struct V_4 * V_53 ,
struct V_9 * V_30 )
{
V_53 -> V_72 . V_73 = V_51 ;
if ( V_30 -> V_14 . V_70 & V_75 ) {
V_53 -> V_72 . V_77 = V_68 * V_64 ;
V_53 -> V_72 . V_79 = F_57 ( V_30 -> V_14 . V_80 ) ;
V_53 -> V_72 . V_78 = V_30 -> V_14 . V_81 ;
} else {
V_53 -> V_72 . V_77 = F_56 ( V_30 -> V_14 . V_80 *
V_30 -> V_14 . V_81 ) ;
V_53 -> V_72 . V_79 = F_56 ( V_30 -> V_14 . V_80 ) ;
V_53 -> V_72 . V_78 = V_53 -> V_72 . V_77 ;
}
}
static inline T_4 F_60 ( T_4 V_82 , unsigned int V_83 )
{
return V_83 ? F_61 ( F_62 ( V_82 ) & ~ 0 << ( 32 - V_83 ) ) : 0 ;
}
static void F_63 ( T_4 * V_31 , unsigned int V_84 )
{
switch ( V_84 ) {
case 0 ... 31 :
V_31 [ 0 ] = F_60 ( V_31 [ 0 ] , V_84 ) ;
V_31 [ 1 ] = V_31 [ 2 ] = V_31 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_31 [ 1 ] = F_60 ( V_31 [ 1 ] , V_84 - 32 ) ;
V_31 [ 2 ] = V_31 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_31 [ 2 ] = F_60 ( V_31 [ 2 ] , V_84 - 64 ) ;
V_31 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_31 [ 3 ] = F_60 ( V_31 [ 3 ] , V_84 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_64 ( const struct V_9 * V_30 ,
struct V_6 * V_8 ,
const struct V_85 * V_86 , unsigned int V_87 )
{
T_5 V_88 [ 2 ] , * V_89 ;
T_6 V_90 ;
int V_91 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_30 -> V_29 ) {
case V_41 :
if ( V_30 -> V_14 . V_70 & V_92 )
V_8 -> V_93 . V_8 = F_60 ( F_65 ( V_86 ) -> V_94 ,
V_30 -> V_14 . V_95 ) ;
if ( V_30 -> V_14 . V_70 & V_96 )
V_8 -> V_93 . V_97 = F_60 ( F_65 ( V_86 ) -> V_98 ,
V_30 -> V_14 . V_99 ) ;
if ( ! ( V_30 -> V_14 . V_70 &
( V_100 | V_101 ) ) )
return 0 ;
V_90 = F_65 ( V_86 ) -> V_102 ;
break;
#if F_66 ( V_103 )
case V_104 :
{
T_5 V_105 ;
if ( V_30 -> V_14 . V_70 & V_92 ) {
memcpy ( & V_8 -> V_106 . V_8 , & F_67 ( V_86 ) -> V_94 ,
sizeof( V_8 -> V_106 . V_8 ) ) ;
F_63 ( V_8 -> V_106 . V_8 , V_30 -> V_14 . V_95 ) ;
}
if ( V_30 -> V_14 . V_70 & V_96 ) {
memcpy ( & V_8 -> V_106 . V_97 , & F_67 ( V_86 ) -> V_98 ,
sizeof( V_8 -> V_106 . V_97 ) ) ;
F_63 ( V_8 -> V_106 . V_97 , V_30 -> V_14 . V_99 ) ;
}
if ( ! ( V_30 -> V_14 . V_70 &
( V_100 | V_101 ) ) )
return 0 ;
V_90 = F_67 ( V_86 ) -> V_90 ;
V_87 = F_68 ( V_86 , sizeof( struct V_107 ) , & V_90 , & V_105 ) ;
if ( ( int ) V_87 < 0 )
return - 1 ;
break;
}
#endif
default:
F_69 () ;
return 0 ;
}
V_91 = F_70 ( V_90 ) ;
if ( V_91 >= 0 ) {
V_89 = F_71 ( V_86 , V_87 + V_91 , sizeof( V_88 ) ,
& V_88 ) ;
} else {
V_88 [ 0 ] = V_88 [ 1 ] = 0 ;
V_89 = V_88 ;
}
if ( ! V_89 )
return - 1 ;
if ( V_30 -> V_14 . V_70 & V_101 )
V_8 -> V_108 = V_89 [ 0 ] ;
if ( V_30 -> V_14 . V_70 & V_100 )
V_8 -> V_109 = V_89 [ 1 ] ;
return 0 ;
}
static V_12 F_72 ( unsigned int V_61 , struct V_4 * V_53 )
{
T_3 V_76 = F_55 ( V_61 ) ;
V_76 = V_76 * V_53 -> V_72 . V_79 ;
if ( F_13 ( V_76 > V_68 * V_64 ) )
V_76 = V_68 * V_64 ;
if ( V_53 -> V_72 . V_77 < V_76 && V_53 -> V_72 . V_78 ) {
V_53 -> V_72 . V_78 -- ;
V_53 -> V_72 . V_77 = V_68 * V_64 ;
}
return ( V_12 ) V_76 ;
}
static bool
F_73 ( const struct V_85 * V_86 , struct V_110 * V_111 )
{
const struct V_27 * V_112 = V_111 -> V_113 ;
struct V_9 * V_30 = V_112 -> V_30 ;
unsigned long V_69 = V_51 ;
struct V_4 * V_53 ;
struct V_6 V_8 ;
bool V_17 = false ;
V_12 V_79 ;
if ( F_64 ( V_30 , & V_8 , V_86 , V_111 -> V_114 ) < 0 )
goto V_115;
F_74 () ;
V_53 = F_7 ( V_30 , & V_8 ) ;
if ( V_53 == NULL ) {
V_53 = F_11 ( V_30 , & V_8 , & V_17 ) ;
if ( V_53 == NULL ) {
F_75 () ;
goto V_115;
} else if ( V_17 ) {
V_53 -> V_52 = V_69 + F_34 ( V_30 -> V_14 . V_116 ) ;
F_58 ( V_53 , V_69 , V_30 -> V_14 . V_70 ) ;
} else {
V_53 -> V_52 = V_51 + F_34 ( V_30 -> V_14 . V_116 ) ;
F_59 ( V_53 , V_30 ) ;
}
} else {
V_53 -> V_52 = V_69 + F_34 ( V_30 -> V_14 . V_116 ) ;
F_58 ( V_53 , V_69 , V_30 -> V_14 . V_70 ) ;
}
if ( V_112 -> V_14 . V_70 & V_75 )
V_79 = F_72 ( V_86 -> V_61 , V_53 ) ;
else
V_79 = V_53 -> V_72 . V_79 ;
if ( V_53 -> V_72 . V_77 >= V_79 ) {
V_53 -> V_72 . V_77 -= V_79 ;
F_12 ( & V_53 -> V_16 ) ;
F_75 () ;
return ! ( V_112 -> V_14 . V_70 & V_117 ) ;
}
F_12 ( & V_53 -> V_16 ) ;
F_75 () ;
return V_112 -> V_14 . V_70 & V_117 ;
V_115:
V_111 -> V_115 = true ;
return false ;
}
static int F_76 ( const struct V_118 * V_111 )
{
struct V_2 * V_2 = V_111 -> V_2 ;
struct V_27 * V_112 = V_111 -> V_113 ;
int V_119 ;
if ( V_112 -> V_14 . V_48 == 0 || V_112 -> V_14 . V_116 == 0 )
return - V_120 ;
if ( V_112 -> V_38 [ sizeof( V_112 -> V_38 ) - 1 ] != '\0' )
return - V_120 ;
if ( V_111 -> V_29 == V_41 ) {
if ( V_112 -> V_14 . V_99 > 32 || V_112 -> V_14 . V_95 > 32 )
return - V_120 ;
} else {
if ( V_112 -> V_14 . V_99 > 128 || V_112 -> V_14 . V_95 > 128 )
return - V_120 ;
}
if ( V_112 -> V_14 . V_70 & ~ V_121 ) {
F_77 ( L_2 ,
V_112 -> V_14 . V_70 ) ;
return - V_120 ;
}
if ( V_112 -> V_14 . V_70 & V_75 ) {
if ( F_57 ( V_112 -> V_14 . V_80 ) == 0 ) {
F_77 ( L_3 , V_112 -> V_14 . V_80 ) ;
return - V_120 ;
}
} else if ( V_112 -> V_14 . V_81 == 0 ||
F_56 ( V_112 -> V_14 . V_80 * V_112 -> V_14 . V_81 ) <
F_56 ( V_112 -> V_14 . V_80 ) ) {
F_77 ( L_4 ,
V_112 -> V_14 . V_80 , V_112 -> V_14 . V_81 ) ;
return - V_122 ;
}
F_52 ( & V_60 ) ;
V_112 -> V_30 = F_49 ( V_2 , V_112 -> V_38 , V_111 -> V_29 ) ;
if ( V_112 -> V_30 == NULL ) {
V_119 = F_25 ( V_2 , V_112 , V_111 -> V_29 ) ;
if ( V_119 < 0 ) {
F_54 ( & V_60 ) ;
return V_119 ;
}
}
F_54 ( & V_60 ) ;
return 0 ;
}
static void F_78 ( const struct V_123 * V_111 )
{
const struct V_27 * V_112 = V_111 -> V_113 ;
F_51 ( V_112 -> V_30 ) ;
}
static void * F_79 ( struct V_124 * V_125 , T_7 * V_126 )
__acquires( V_127 -> V_16 )
{
struct V_9 * V_127 = V_125 -> V_128 ;
unsigned int * V_129 ;
F_41 ( & V_127 -> V_16 ) ;
if ( * V_126 >= V_127 -> V_14 . V_15 )
return NULL ;
V_129 = F_80 ( sizeof( unsigned int ) , V_22 ) ;
if ( ! V_129 )
return F_81 ( - V_36 ) ;
* V_129 = * V_126 ;
return V_129 ;
}
static void * F_82 ( struct V_124 * V_125 , void * V_130 , T_7 * V_126 )
{
struct V_9 * V_127 = V_125 -> V_128 ;
unsigned int * V_129 = ( unsigned int * ) V_130 ;
* V_126 = ++ ( * V_129 ) ;
if ( * V_126 >= V_127 -> V_14 . V_15 ) {
F_31 ( V_130 ) ;
return NULL ;
}
return V_129 ;
}
static void F_83 ( struct V_124 * V_125 , void * V_130 )
__releases( V_127 -> V_16 )
{
struct V_9 * V_127 = V_125 -> V_128 ;
unsigned int * V_129 = ( unsigned int * ) V_130 ;
if ( ! F_84 ( V_129 ) )
F_31 ( V_129 ) ;
F_43 ( & V_127 -> V_16 ) ;
}
static int F_85 ( struct V_4 * V_5 , T_2 V_29 ,
struct V_124 * V_125 )
{
const struct V_9 * V_10 = V_125 -> V_128 ;
F_10 ( & V_5 -> V_16 ) ;
F_58 ( V_5 , V_51 , V_10 -> V_14 . V_70 ) ;
switch ( V_29 ) {
case V_41 :
F_86 ( V_125 , L_5 ,
( long ) ( V_5 -> V_52 - V_51 ) / V_64 ,
& V_5 -> V_8 . V_93 . V_97 ,
F_87 ( V_5 -> V_8 . V_108 ) ,
& V_5 -> V_8 . V_93 . V_8 ,
F_87 ( V_5 -> V_8 . V_109 ) ,
V_5 -> V_72 . V_77 , V_5 -> V_72 . V_78 ,
V_5 -> V_72 . V_79 ) ;
break;
#if F_66 ( V_103 )
case V_104 :
F_86 ( V_125 , L_6 ,
( long ) ( V_5 -> V_52 - V_51 ) / V_64 ,
& V_5 -> V_8 . V_106 . V_97 ,
F_87 ( V_5 -> V_8 . V_108 ) ,
& V_5 -> V_8 . V_106 . V_8 ,
F_87 ( V_5 -> V_8 . V_109 ) ,
V_5 -> V_72 . V_77 , V_5 -> V_72 . V_78 ,
V_5 -> V_72 . V_79 ) ;
break;
#endif
default:
F_69 () ;
}
F_12 ( & V_5 -> V_16 ) ;
return F_88 ( V_125 ) ;
}
static int F_89 ( struct V_124 * V_125 , void * V_130 )
{
struct V_9 * V_127 = V_125 -> V_128 ;
unsigned int * V_129 = ( unsigned int * ) V_130 ;
struct V_4 * V_5 ;
if ( ! F_8 ( & V_127 -> V_11 [ * V_129 ] ) ) {
F_50 (ent, &htable->hash[*bucket], node)
if ( F_85 ( V_5 , V_127 -> V_29 , V_125 ) )
return - 1 ;
}
return 0 ;
}
static int F_90 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
int V_119 = F_91 ( V_132 , & V_133 ) ;
if ( ! V_119 ) {
struct V_124 * V_134 = V_132 -> V_135 ;
V_134 -> V_128 = F_92 ( V_131 ) ;
}
return V_119 ;
}
static int T_8 F_93 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_42 = F_94 ( L_7 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_42 )
return - V_36 ;
#if F_66 ( V_103 )
V_1 -> V_43 = F_94 ( L_8 , V_2 -> V_136 ) ;
if ( ! V_1 -> V_43 ) {
F_46 ( L_7 , V_2 -> V_136 ) ;
return - V_36 ;
}
#endif
return 0 ;
}
static void T_9 F_95 ( struct V_2 * V_2 )
{
struct V_9 * V_30 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_52 ( & V_60 ) ;
F_50 (hinfo, &hashlimit_net->htables, node)
F_45 ( V_30 ) ;
V_1 -> V_42 = NULL ;
V_1 -> V_43 = NULL ;
F_54 ( & V_60 ) ;
F_46 ( L_7 , V_2 -> V_136 ) ;
#if F_66 ( V_103 )
F_46 ( L_8 , V_2 -> V_136 ) ;
#endif
}
static int T_8 F_96 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_27 ( & V_1 -> V_49 ) ;
return F_93 ( V_2 ) ;
}
static void T_9 F_97 ( struct V_2 * V_2 )
{
F_95 ( V_2 ) ;
}
static int T_10 F_98 ( void )
{
int V_137 ;
V_137 = F_99 ( & V_138 ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_100 ( V_139 ,
F_101 ( V_139 ) ) ;
if ( V_137 < 0 )
goto V_140;
V_137 = - V_36 ;
V_21 = F_102 ( L_9 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_21 ) {
F_103 ( L_10 ) ;
goto V_141;
}
return 0 ;
V_141:
F_104 ( V_139 , F_101 ( V_139 ) ) ;
V_140:
F_105 ( & V_138 ) ;
return V_137 ;
}
static void T_11 F_106 ( void )
{
F_104 ( V_139 , F_101 ( V_139 ) ) ;
F_105 ( & V_138 ) ;
F_107 () ;
F_108 ( V_21 ) ;
}
