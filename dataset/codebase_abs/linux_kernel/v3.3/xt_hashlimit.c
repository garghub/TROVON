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
const struct V_6 * V_8 )
{
struct V_4 * V_5 ;
F_9 ( & V_10 -> V_19 ) ;
if ( F_11 ( ! V_10 -> V_20 ) ) {
F_12 ( & V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
V_10 -> V_20 = true ;
}
if ( V_10 -> V_15 . V_21 && V_10 -> V_22 >= V_10 -> V_15 . V_21 ) {
if ( F_13 () )
F_14 ( L_1 , V_10 -> V_15 . V_21 ) ;
V_5 = NULL ;
} else
V_5 = F_15 ( V_23 , V_24 ) ;
if ( V_5 ) {
memcpy ( & V_5 -> V_8 , V_8 , sizeof( V_5 -> V_8 ) ) ;
F_16 ( & V_5 -> V_19 ) ;
F_9 ( & V_5 -> V_19 ) ;
F_17 ( & V_5 -> V_25 , & V_10 -> V_11 [ F_4 ( V_10 , V_8 ) ] ) ;
V_10 -> V_22 ++ ;
}
F_18 ( & V_10 -> V_19 ) ;
return V_5 ;
}
static void F_19 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_20 ( V_27 , struct V_4 , V_28 ) ;
F_21 ( V_23 , V_5 ) ;
}
static inline void
F_22 ( struct V_9 * V_10 , struct V_4 * V_5 )
{
F_23 ( & V_5 -> V_25 ) ;
F_24 ( & V_5 -> V_28 , F_19 ) ;
V_10 -> V_22 -- ;
}
static int F_25 ( struct V_2 * V_2 , struct V_29 * V_30 ,
T_2 V_31 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_32 ;
unsigned int V_16 ;
unsigned int V_33 ;
if ( V_30 -> V_15 . V_16 ) {
V_16 = V_30 -> V_15 . V_16 ;
} else {
V_16 = ( V_34 << V_35 ) / 16384 /
sizeof( struct V_36 ) ;
if ( V_34 > 1024 * 1024 * 1024 / V_37 )
V_16 = 8192 ;
if ( V_16 < 16 )
V_16 = 16 ;
}
V_32 = F_26 ( sizeof( struct V_9 ) +
sizeof( struct V_36 ) * V_16 ) ;
if ( V_32 == NULL )
return - V_38 ;
V_30 -> V_32 = V_32 ;
memcpy ( & V_32 -> V_15 , & V_30 -> V_15 , sizeof( V_32 -> V_15 ) ) ;
V_32 -> V_15 . V_16 = V_16 ;
if ( V_32 -> V_15 . V_21 == 0 )
V_32 -> V_15 . V_21 = 8 * V_32 -> V_15 . V_16 ;
else if ( V_32 -> V_15 . V_21 < V_32 -> V_15 . V_16 )
V_32 -> V_15 . V_21 = V_32 -> V_15 . V_16 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_15 . V_16 ; V_33 ++ )
F_27 ( & V_32 -> V_11 [ V_33 ] ) ;
V_32 -> V_39 = 1 ;
V_32 -> V_22 = 0 ;
V_32 -> V_31 = V_31 ;
V_32 -> V_20 = false ;
F_16 ( & V_32 -> V_19 ) ;
V_32 -> V_40 = F_28 ( V_30 -> V_41 , 0 ,
( V_31 == V_42 ) ?
V_1 -> V_43 : V_1 -> V_44 ,
& V_45 , V_32 ) ;
if ( V_32 -> V_40 == NULL ) {
F_29 ( V_32 ) ;
return - V_38 ;
}
V_32 -> V_2 = V_2 ;
F_30 ( & V_32 -> V_46 , V_47 , ( unsigned long ) V_32 ) ;
V_32 -> V_46 . V_48 = V_49 + F_31 ( V_32 -> V_15 . V_50 ) ;
F_32 ( & V_32 -> V_46 ) ;
F_33 ( & V_32 -> V_25 , & V_1 -> V_51 ) ;
return 0 ;
}
static bool F_34 ( const struct V_9 * V_10 ,
const struct V_4 * V_52 )
{
return 1 ;
}
static bool F_35 ( const struct V_9 * V_10 ,
const struct V_4 * V_52 )
{
return F_36 ( V_49 , V_52 -> V_48 ) ;
}
static void F_37 ( struct V_9 * V_10 ,
bool (* F_38)( const struct V_9 * V_10 ,
const struct V_4 * V_52 ) )
{
unsigned int V_33 ;
F_39 ( & V_10 -> V_19 ) ;
for ( V_33 = 0 ; V_33 < V_10 -> V_15 . V_16 ; V_33 ++ ) {
struct V_4 * V_53 ;
struct V_17 * V_18 , * V_54 ;
F_40 (dh, pos, n, &ht->hash[i], node) {
if ( (* F_38)( V_10 , V_53 ) )
F_22 ( V_10 , V_53 ) ;
}
}
F_41 ( & V_10 -> V_19 ) ;
}
static void V_47 ( unsigned long V_55 )
{
struct V_9 * V_10 = (struct V_9 * ) V_55 ;
F_37 ( V_10 , F_35 ) ;
V_10 -> V_46 . V_48 = V_49 + F_31 ( V_10 -> V_15 . V_50 ) ;
F_32 ( & V_10 -> V_46 ) ;
}
static void F_42 ( struct V_9 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_32 -> V_2 ) ;
struct V_56 * V_57 ;
F_43 ( & V_32 -> V_46 ) ;
if ( V_32 -> V_31 == V_42 )
V_57 = V_1 -> V_43 ;
else
V_57 = V_1 -> V_44 ;
F_44 ( V_32 -> V_40 -> V_41 , V_57 ) ;
F_37 ( V_32 , F_34 ) ;
F_29 ( V_32 ) ;
}
static struct V_9 * F_45 ( struct V_2 * V_2 ,
const char * V_41 ,
T_2 V_31 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_9 * V_32 ;
struct V_17 * V_18 ;
F_46 (hinfo, pos, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_41 , V_32 -> V_40 -> V_41 ) &&
V_32 -> V_31 == V_31 ) {
V_32 -> V_39 ++ ;
return V_32 ;
}
}
return NULL ;
}
static void F_47 ( struct V_9 * V_32 )
{
F_48 ( & V_58 ) ;
if ( -- V_32 -> V_39 == 0 ) {
F_49 ( & V_32 -> V_25 ) ;
F_42 ( V_32 ) ;
}
F_50 ( & V_58 ) ;
}
static inline T_1
F_51 ( T_1 V_59 )
{
if ( V_59 > 0xFFFFFFFF / ( V_60 * V_61 ) )
return ( V_59 / V_62 ) * V_60 * V_61 ;
return ( V_59 * V_60 * V_61 ) / V_62 ;
}
static inline void F_52 ( struct V_4 * V_53 , unsigned long V_63 )
{
V_53 -> V_64 . V_65 += ( V_63 - V_53 -> V_64 . V_66 ) * V_61 ;
if ( V_53 -> V_64 . V_65 > V_53 -> V_64 . V_67 )
V_53 -> V_64 . V_65 = V_53 -> V_64 . V_67 ;
V_53 -> V_64 . V_66 = V_63 ;
}
static inline T_3 F_53 ( T_3 V_68 , unsigned int V_69 )
{
return V_69 ? F_54 ( F_55 ( V_68 ) & ~ 0 << ( 32 - V_69 ) ) : 0 ;
}
static void F_56 ( T_3 * V_33 , unsigned int V_70 )
{
switch ( V_70 ) {
case 0 ... 31 :
V_33 [ 0 ] = F_53 ( V_33 [ 0 ] , V_70 ) ;
V_33 [ 1 ] = V_33 [ 2 ] = V_33 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_33 [ 1 ] = F_53 ( V_33 [ 1 ] , V_70 - 32 ) ;
V_33 [ 2 ] = V_33 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_33 [ 2 ] = F_53 ( V_33 [ 2 ] , V_70 - 64 ) ;
V_33 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_33 [ 3 ] = F_53 ( V_33 [ 3 ] , V_70 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_57 ( const struct V_9 * V_32 ,
struct V_6 * V_8 ,
const struct V_71 * V_72 , unsigned int V_73 )
{
T_4 V_74 [ 2 ] , * V_75 ;
T_5 V_76 ;
int V_77 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
switch ( V_32 -> V_31 ) {
case V_42 :
if ( V_32 -> V_15 . V_78 & V_79 )
V_8 -> V_80 . V_8 = F_53 ( F_58 ( V_72 ) -> V_81 ,
V_32 -> V_15 . V_82 ) ;
if ( V_32 -> V_15 . V_78 & V_83 )
V_8 -> V_80 . V_84 = F_53 ( F_58 ( V_72 ) -> V_85 ,
V_32 -> V_15 . V_86 ) ;
if ( ! ( V_32 -> V_15 . V_78 &
( V_87 | V_88 ) ) )
return 0 ;
V_76 = F_58 ( V_72 ) -> V_89 ;
break;
#if F_59 ( V_90 )
case V_91 :
{
T_4 V_92 ;
if ( V_32 -> V_15 . V_78 & V_79 ) {
memcpy ( & V_8 -> V_93 . V_8 , & F_60 ( V_72 ) -> V_81 ,
sizeof( V_8 -> V_93 . V_8 ) ) ;
F_56 ( V_8 -> V_93 . V_8 , V_32 -> V_15 . V_82 ) ;
}
if ( V_32 -> V_15 . V_78 & V_83 ) {
memcpy ( & V_8 -> V_93 . V_84 , & F_60 ( V_72 ) -> V_85 ,
sizeof( V_8 -> V_93 . V_84 ) ) ;
F_56 ( V_8 -> V_93 . V_84 , V_32 -> V_15 . V_86 ) ;
}
if ( ! ( V_32 -> V_15 . V_78 &
( V_87 | V_88 ) ) )
return 0 ;
V_76 = F_60 ( V_72 ) -> V_76 ;
V_73 = F_61 ( V_72 , sizeof( struct V_94 ) , & V_76 , & V_92 ) ;
if ( ( int ) V_73 < 0 )
return - 1 ;
break;
}
#endif
default:
F_62 () ;
return 0 ;
}
V_77 = F_63 ( V_76 ) ;
if ( V_77 >= 0 ) {
V_75 = F_64 ( V_72 , V_73 + V_77 , sizeof( V_74 ) ,
& V_74 ) ;
} else {
V_74 [ 0 ] = V_74 [ 1 ] = 0 ;
V_75 = V_74 ;
}
if ( ! V_75 )
return - 1 ;
if ( V_32 -> V_15 . V_78 & V_88 )
V_8 -> V_95 = V_75 [ 0 ] ;
if ( V_32 -> V_15 . V_78 & V_87 )
V_8 -> V_96 = V_75 [ 1 ] ;
return 0 ;
}
static bool
F_65 ( const struct V_71 * V_72 , struct V_97 * V_98 )
{
const struct V_29 * V_99 = V_98 -> V_100 ;
struct V_9 * V_32 = V_99 -> V_32 ;
unsigned long V_63 = V_49 ;
struct V_4 * V_53 ;
struct V_6 V_8 ;
if ( F_57 ( V_32 , & V_8 , V_72 , V_98 -> V_101 ) < 0 )
goto V_102;
F_66 () ;
V_53 = F_6 ( V_32 , & V_8 ) ;
if ( V_53 == NULL ) {
V_53 = F_10 ( V_32 , & V_8 ) ;
if ( V_53 == NULL ) {
F_67 () ;
goto V_102;
}
V_53 -> V_48 = V_49 + F_31 ( V_32 -> V_15 . V_103 ) ;
V_53 -> V_64 . V_66 = V_49 ;
V_53 -> V_64 . V_65 = F_51 ( V_32 -> V_15 . V_104 *
V_32 -> V_15 . V_105 ) ;
V_53 -> V_64 . V_67 = F_51 ( V_32 -> V_15 . V_104 *
V_32 -> V_15 . V_105 ) ;
V_53 -> V_64 . V_106 = F_51 ( V_32 -> V_15 . V_104 ) ;
} else {
V_53 -> V_48 = V_63 + F_31 ( V_32 -> V_15 . V_103 ) ;
F_52 ( V_53 , V_63 ) ;
}
if ( V_53 -> V_64 . V_65 >= V_53 -> V_64 . V_106 ) {
V_53 -> V_64 . V_65 -= V_53 -> V_64 . V_106 ;
F_18 ( & V_53 -> V_19 ) ;
F_67 () ;
return ! ( V_99 -> V_15 . V_78 & V_107 ) ;
}
F_18 ( & V_53 -> V_19 ) ;
F_67 () ;
return V_99 -> V_15 . V_78 & V_107 ;
V_102:
V_98 -> V_102 = true ;
return false ;
}
static int F_68 ( const struct V_108 * V_98 )
{
struct V_2 * V_2 = V_98 -> V_2 ;
struct V_29 * V_99 = V_98 -> V_100 ;
int V_109 ;
if ( V_99 -> V_15 . V_105 == 0 ||
F_51 ( V_99 -> V_15 . V_104 * V_99 -> V_15 . V_105 ) <
F_51 ( V_99 -> V_15 . V_104 ) ) {
F_69 ( L_2 ,
V_99 -> V_15 . V_104 , V_99 -> V_15 . V_105 ) ;
return - V_110 ;
}
if ( V_99 -> V_15 . V_50 == 0 || V_99 -> V_15 . V_103 == 0 )
return - V_111 ;
if ( V_99 -> V_41 [ sizeof( V_99 -> V_41 ) - 1 ] != '\0' )
return - V_111 ;
if ( V_98 -> V_31 == V_42 ) {
if ( V_99 -> V_15 . V_86 > 32 || V_99 -> V_15 . V_82 > 32 )
return - V_111 ;
} else {
if ( V_99 -> V_15 . V_86 > 128 || V_99 -> V_15 . V_82 > 128 )
return - V_111 ;
}
F_48 ( & V_58 ) ;
V_99 -> V_32 = F_45 ( V_2 , V_99 -> V_41 , V_98 -> V_31 ) ;
if ( V_99 -> V_32 == NULL ) {
V_109 = F_25 ( V_2 , V_99 , V_98 -> V_31 ) ;
if ( V_109 < 0 ) {
F_50 ( & V_58 ) ;
return V_109 ;
}
}
F_50 ( & V_58 ) ;
return 0 ;
}
static void F_70 ( const struct V_112 * V_98 )
{
const struct V_29 * V_99 = V_98 -> V_100 ;
F_47 ( V_99 -> V_32 ) ;
}
static void * F_71 ( struct V_113 * V_114 , T_6 * V_18 )
__acquires( V_115 -> V_19 )
{
struct V_9 * V_115 = V_114 -> V_116 ;
unsigned int * V_117 ;
F_39 ( & V_115 -> V_19 ) ;
if ( * V_18 >= V_115 -> V_15 . V_16 )
return NULL ;
V_117 = F_72 ( sizeof( unsigned int ) , V_24 ) ;
if ( ! V_117 )
return F_73 ( - V_38 ) ;
* V_117 = * V_18 ;
return V_117 ;
}
static void * F_74 ( struct V_113 * V_114 , void * V_118 , T_6 * V_18 )
{
struct V_9 * V_115 = V_114 -> V_116 ;
unsigned int * V_117 = ( unsigned int * ) V_118 ;
* V_18 = ++ ( * V_117 ) ;
if ( * V_18 >= V_115 -> V_15 . V_16 ) {
F_75 ( V_118 ) ;
return NULL ;
}
return V_117 ;
}
static void F_76 ( struct V_113 * V_114 , void * V_118 )
__releases( V_115 -> V_19 )
{
struct V_9 * V_115 = V_114 -> V_116 ;
unsigned int * V_117 = ( unsigned int * ) V_118 ;
if ( ! F_77 ( V_117 ) )
F_75 ( V_117 ) ;
F_41 ( & V_115 -> V_19 ) ;
}
static int F_78 ( struct V_4 * V_5 , T_2 V_31 ,
struct V_113 * V_114 )
{
int V_119 ;
F_9 ( & V_5 -> V_19 ) ;
F_52 ( V_5 , V_49 ) ;
switch ( V_31 ) {
case V_42 :
V_119 = F_79 ( V_114 , L_3 ,
( long ) ( V_5 -> V_48 - V_49 ) / V_60 ,
& V_5 -> V_8 . V_80 . V_84 ,
F_80 ( V_5 -> V_8 . V_95 ) ,
& V_5 -> V_8 . V_80 . V_8 ,
F_80 ( V_5 -> V_8 . V_96 ) ,
V_5 -> V_64 . V_65 , V_5 -> V_64 . V_67 ,
V_5 -> V_64 . V_106 ) ;
break;
#if F_59 ( V_90 )
case V_91 :
V_119 = F_79 ( V_114 , L_4 ,
( long ) ( V_5 -> V_48 - V_49 ) / V_60 ,
& V_5 -> V_8 . V_93 . V_84 ,
F_80 ( V_5 -> V_8 . V_95 ) ,
& V_5 -> V_8 . V_93 . V_8 ,
F_80 ( V_5 -> V_8 . V_96 ) ,
V_5 -> V_64 . V_65 , V_5 -> V_64 . V_67 ,
V_5 -> V_64 . V_106 ) ;
break;
#endif
default:
F_62 () ;
V_119 = 0 ;
}
F_18 ( & V_5 -> V_19 ) ;
return V_119 ;
}
static int F_81 ( struct V_113 * V_114 , void * V_118 )
{
struct V_9 * V_115 = V_114 -> V_116 ;
unsigned int * V_117 = ( unsigned int * ) V_118 ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
if ( ! F_7 ( & V_115 -> V_11 [ * V_117 ] ) ) {
F_46 (ent, pos, &htable->hash[*bucket], node)
if ( F_78 ( V_5 , V_115 -> V_31 , V_114 ) )
return - 1 ;
}
return 0 ;
}
static int F_82 ( struct V_120 * V_120 , struct V_121 * V_121 )
{
int V_109 = F_83 ( V_121 , & V_122 ) ;
if ( ! V_109 ) {
struct V_113 * V_123 = V_121 -> V_124 ;
V_123 -> V_116 = F_84 ( V_120 ) -> V_125 ;
}
return V_109 ;
}
static int T_7 F_85 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_43 = F_86 ( L_5 , V_2 -> V_126 ) ;
if ( ! V_1 -> V_43 )
return - V_38 ;
#if F_59 ( V_90 )
V_1 -> V_44 = F_86 ( L_6 , V_2 -> V_126 ) ;
if ( ! V_1 -> V_44 ) {
F_87 ( V_2 , L_5 ) ;
return - V_38 ;
}
#endif
return 0 ;
}
static void T_8 F_88 ( struct V_2 * V_2 )
{
F_87 ( V_2 , L_5 ) ;
#if F_59 ( V_90 )
F_87 ( V_2 , L_6 ) ;
#endif
}
static int T_7 F_89 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_27 ( & V_1 -> V_51 ) ;
return F_85 ( V_2 ) ;
}
static void T_8 F_90 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_91 ( ! F_7 ( & V_1 -> V_51 ) ) ;
F_88 ( V_2 ) ;
}
static int T_9 F_92 ( void )
{
int V_127 ;
V_127 = F_93 ( & V_128 ) ;
if ( V_127 < 0 )
return V_127 ;
V_127 = F_94 ( V_129 ,
F_95 ( V_129 ) ) ;
if ( V_127 < 0 )
goto V_130;
V_127 = - V_38 ;
V_23 = F_96 ( L_7 ,
sizeof( struct V_4 ) , 0 , 0 ,
NULL ) ;
if ( ! V_23 ) {
F_97 ( L_8 ) ;
goto V_131;
}
return 0 ;
V_131:
F_98 ( V_129 , F_95 ( V_129 ) ) ;
V_130:
F_99 ( & V_128 ) ;
return V_127 ;
}
static void T_10 F_100 ( void )
{
F_98 ( V_129 , F_95 ( V_129 ) ) ;
F_99 ( & V_128 ) ;
F_101 () ;
F_102 ( V_23 ) ;
}
