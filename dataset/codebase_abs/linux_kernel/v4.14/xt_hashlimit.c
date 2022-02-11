static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_4 * V_5 , const void * V_6 , int V_7 )
{
if ( V_7 == 1 ) {
struct V_8 * V_9 = (struct V_8 * ) V_6 ;
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
struct V_19 * V_9 = (struct V_19 * ) V_6 ;
V_5 -> V_10 = V_9 -> V_10 ;
V_5 -> V_11 = V_9 -> V_11 ;
V_5 -> V_12 = V_9 -> V_12 ;
V_5 -> V_13 = V_9 -> V_13 ;
V_5 -> V_14 = V_9 -> V_14 ;
V_5 -> V_15 = V_9 -> V_15 ;
V_5 -> V_16 = V_9 -> V_16 ;
V_5 -> V_17 = V_9 -> V_17 ;
V_5 -> V_18 = V_9 -> V_18 ;
} else if ( V_7 == 3 ) {
memcpy ( V_5 , V_6 , sizeof( struct V_4 ) ) ;
} else {
return - V_20 ;
}
return 0 ;
}
static inline bool F_4 ( const struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
return ! memcmp ( & V_22 -> V_25 , V_24 , sizeof( V_22 -> V_25 ) ) ;
}
static T_1
F_5 ( const struct V_26 * V_27 , const struct V_23 * V_25 )
{
T_1 V_28 = F_6 ( ( const V_29 * ) V_25 ,
sizeof( * V_25 ) / sizeof( V_29 ) ,
V_27 -> V_30 ) ;
return F_7 ( V_28 , V_27 -> V_9 . V_13 ) ;
}
static struct V_21 *
F_8 ( const struct V_26 * V_27 ,
const struct V_23 * V_25 )
{
struct V_21 * V_22 ;
T_1 V_28 = F_5 ( V_27 , V_25 ) ;
if ( ! F_9 ( & V_27 -> V_28 [ V_28 ] ) ) {
F_10 (ent, &ht->hash[hash], node)
if ( F_4 ( V_22 , V_25 ) ) {
F_11 ( & V_22 -> V_31 ) ;
return V_22 ;
}
}
return NULL ;
}
static struct V_21 *
F_12 ( struct V_26 * V_27 ,
const struct V_23 * V_25 , bool * V_32 )
{
struct V_21 * V_22 ;
F_11 ( & V_27 -> V_31 ) ;
V_22 = F_8 ( V_27 , V_25 ) ;
if ( V_22 != NULL ) {
F_13 ( & V_27 -> V_31 ) ;
* V_32 = true ;
return V_22 ;
}
if ( F_14 ( ! V_27 -> V_33 ) ) {
F_15 ( & V_27 -> V_30 , sizeof( V_27 -> V_30 ) ) ;
V_27 -> V_33 = true ;
}
if ( V_27 -> V_9 . V_14 && V_27 -> V_34 >= V_27 -> V_9 . V_14 ) {
F_16 ( L_1 , V_27 -> V_9 . V_14 ) ;
V_22 = NULL ;
} else
V_22 = F_17 ( V_35 , V_36 ) ;
if ( V_22 ) {
memcpy ( & V_22 -> V_25 , V_25 , sizeof( V_22 -> V_25 ) ) ;
F_18 ( & V_22 -> V_31 ) ;
F_11 ( & V_22 -> V_31 ) ;
F_19 ( & V_22 -> V_37 , & V_27 -> V_28 [ F_5 ( V_27 , V_25 ) ] ) ;
V_27 -> V_34 ++ ;
}
F_13 ( & V_27 -> V_31 ) ;
return V_22 ;
}
static void F_20 ( struct V_38 * V_39 )
{
struct V_21 * V_22 = F_21 ( V_39 , struct V_21 , V_40 ) ;
F_22 ( V_35 , V_22 ) ;
}
static inline void
F_23 ( struct V_26 * V_27 , struct V_21 * V_22 )
{
F_24 ( & V_22 -> V_37 ) ;
F_25 ( & V_22 -> V_40 , F_20 ) ;
V_27 -> V_34 -- ;
}
static int F_26 ( struct V_2 * V_2 , struct V_4 * V_9 ,
const char * V_41 , T_2 V_42 ,
struct V_26 * * V_43 ,
int V_7 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_26 * V_44 ;
const struct V_45 * V_46 ;
unsigned int V_13 , V_47 ;
int V_48 ;
if ( V_9 -> V_13 ) {
V_13 = V_9 -> V_13 ;
} else {
V_13 = ( V_49 << V_50 ) / 16384 /
sizeof( struct V_51 ) ;
if ( V_49 > 1024 * 1024 * 1024 / V_52 )
V_13 = 8192 ;
if ( V_13 < 16 )
V_13 = 16 ;
}
V_44 = F_27 ( sizeof( struct V_26 ) +
sizeof( struct V_51 ) * V_13 ) ;
if ( V_44 == NULL )
return - V_53 ;
* V_43 = V_44 ;
V_48 = F_3 ( & V_44 -> V_9 , ( void * ) V_9 , 3 ) ;
if ( V_48 )
return V_48 ;
V_44 -> V_9 . V_13 = V_13 ;
if ( V_44 -> V_9 . V_14 == 0 )
V_44 -> V_9 . V_14 = 8 * V_44 -> V_9 . V_13 ;
else if ( V_44 -> V_9 . V_14 < V_44 -> V_9 . V_13 )
V_44 -> V_9 . V_14 = V_44 -> V_9 . V_13 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_9 . V_13 ; V_47 ++ )
F_28 ( & V_44 -> V_28 [ V_47 ] ) ;
V_44 -> V_54 = 1 ;
V_44 -> V_34 = 0 ;
V_44 -> V_42 = V_42 ;
V_44 -> V_33 = false ;
V_44 -> V_41 = F_29 ( V_41 , V_55 ) ;
if ( ! V_44 -> V_41 ) {
F_30 ( V_44 ) ;
return - V_53 ;
}
F_18 ( & V_44 -> V_31 ) ;
switch ( V_7 ) {
case 1 :
V_46 = & V_56 ;
break;
case 2 :
V_46 = & V_57 ;
break;
default:
V_46 = & V_58 ;
}
V_44 -> V_59 = F_31 ( V_41 , 0 ,
( V_42 == V_60 ) ?
V_1 -> V_61 : V_1 -> V_62 ,
V_46 , V_44 ) ;
if ( V_44 -> V_59 == NULL ) {
F_32 ( V_44 -> V_41 ) ;
F_30 ( V_44 ) ;
return - V_53 ;
}
V_44 -> V_2 = V_2 ;
F_33 ( & V_44 -> V_63 , V_64 ) ;
F_34 ( V_65 , & V_44 -> V_63 ,
F_35 ( V_44 -> V_9 . V_15 ) ) ;
F_36 ( & V_44 -> V_37 , & V_1 -> V_66 ) ;
return 0 ;
}
static bool F_37 ( const struct V_26 * V_27 ,
const struct V_21 * V_67 )
{
return 1 ;
}
static bool F_38 ( const struct V_26 * V_27 ,
const struct V_21 * V_67 )
{
return F_39 ( V_68 , V_67 -> V_69 ) ;
}
static void F_40 ( struct V_26 * V_27 ,
bool (* F_41)( const struct V_26 * V_27 ,
const struct V_21 * V_67 ) )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_27 -> V_9 . V_13 ; V_47 ++ ) {
struct V_21 * V_70 ;
struct V_71 * V_72 ;
F_42 ( & V_27 -> V_31 ) ;
F_43 (dh, n, &ht->hash[i], node) {
if ( (* F_41)( V_27 , V_70 ) )
F_23 ( V_27 , V_70 ) ;
}
F_44 ( & V_27 -> V_31 ) ;
F_45 () ;
}
}
static void V_64 ( struct V_73 * V_74 )
{
struct V_26 * V_27 ;
V_27 = F_21 ( V_74 , struct V_26 , V_63 . V_74 ) ;
F_40 ( V_27 , F_38 ) ;
F_34 ( V_65 ,
& V_27 -> V_63 , F_35 ( V_27 -> V_9 . V_15 ) ) ;
}
static void F_46 ( struct V_26 * V_44 )
{
struct V_1 * V_1 = F_1 ( V_44 -> V_2 ) ;
struct V_75 * V_76 ;
if ( V_44 -> V_42 == V_60 )
V_76 = V_1 -> V_61 ;
else
V_76 = V_1 -> V_62 ;
if ( V_76 != NULL )
F_47 ( V_44 -> V_41 , V_76 ) ;
}
static void F_48 ( struct V_26 * V_44 )
{
F_49 ( & V_44 -> V_63 ) ;
F_46 ( V_44 ) ;
F_40 ( V_44 , F_37 ) ;
F_32 ( V_44 -> V_41 ) ;
F_30 ( V_44 ) ;
}
static struct V_26 * F_50 ( struct V_2 * V_2 ,
const char * V_41 ,
T_2 V_42 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_26 * V_44 ;
F_51 (hinfo, &hashlimit_net->htables, node) {
if ( ! strcmp ( V_41 , V_44 -> V_41 ) &&
V_44 -> V_42 == V_42 ) {
V_44 -> V_54 ++ ;
return V_44 ;
}
}
return NULL ;
}
static void F_52 ( struct V_26 * V_44 )
{
F_53 ( & V_77 ) ;
if ( -- V_44 -> V_54 == 0 ) {
F_54 ( & V_44 -> V_37 ) ;
F_48 ( V_44 ) ;
}
F_55 ( & V_77 ) ;
}
static V_29 F_56 ( V_29 V_78 )
{
return ( V_78 >> V_79 ) + 1 ;
}
static T_3 F_57 ( T_3 V_80 , int V_7 )
{
T_3 V_81 = ( V_7 == 1 ) ?
V_82 : V_83 ;
T_3 V_84 = ( V_7 == 1 ) ?
V_85 : V_86 ;
if ( V_81 >= V_87 * V_84 )
return F_58 ( V_80 , F_58 ( V_81 , V_87 * V_84 ) ) ;
return V_80 * F_58 ( V_87 * V_84 , V_81 ) ;
}
static V_29 F_59 ( V_29 V_80 )
{
T_3 V_88 = V_80 ;
V_88 *= V_87 * V_89 ;
return ( V_29 ) ( V_88 >> 32 ) ;
}
static T_3 F_60 ( T_3 V_80 )
{
if ( V_80 != 0 ) {
return F_58 ( V_83 , V_80 ) ;
} else {
F_61 ( L_2 , V_80 ) ;
return 0 ;
}
}
static T_3 F_62 ( V_29 V_80 )
{
T_3 V_90 ;
V_90 = V_80 ? V_91 / V_80 : V_91 ;
V_90 = ( V_90 - 1 ) << V_79 ;
return V_90 ;
}
static void F_63 ( struct V_21 * V_70 , unsigned long V_92 ,
V_29 V_10 , int V_7 )
{
unsigned long V_93 = V_92 - V_70 -> V_94 . V_95 ;
T_3 V_96 , V_84 ;
if ( V_93 == 0 )
return;
if ( V_7 >= 3 && V_10 & V_97 ) {
T_3 V_98 = V_70 -> V_94 . V_98 * V_87 ;
if ( V_93 < V_98 )
return;
V_70 -> V_94 . V_95 = V_92 ;
V_70 -> V_94 . V_99 =
( ( V_70 -> V_94 . V_100 * V_98 ) >
( V_93 * V_70 -> V_94 . V_101 ) ) ;
V_70 -> V_94 . V_100 = 0 ;
return;
}
V_70 -> V_94 . V_95 = V_92 ;
if ( V_10 & V_102 ) {
T_3 V_103 = V_70 -> V_94 . V_104 ;
V_70 -> V_94 . V_104 += V_89 * V_93 ;
V_96 = V_89 * V_87 ;
if ( V_103 >= V_70 -> V_94 . V_104 ) {
V_70 -> V_94 . V_104 = V_96 ;
return;
}
} else {
V_84 = ( V_7 == 1 ) ?
V_85 : V_86 ;
V_70 -> V_94 . V_104 += V_93 * V_84 ;
V_96 = V_70 -> V_94 . V_105 ;
}
if ( V_70 -> V_94 . V_104 > V_96 )
V_70 -> V_94 . V_104 = V_96 ;
}
static void F_64 ( struct V_21 * V_70 ,
struct V_26 * V_44 , int V_7 )
{
V_70 -> V_94 . V_95 = V_68 ;
if ( V_7 >= 3 && V_44 -> V_9 . V_10 & V_97 ) {
V_70 -> V_94 . V_99 = 0 ;
V_70 -> V_94 . V_100 = 0 ;
if ( V_44 -> V_9 . V_10 & V_102 ) {
V_70 -> V_94 . V_101 =
F_62 ( ( V_29 ) V_44 -> V_9 . V_11 ) ;
if ( V_44 -> V_9 . V_12 )
V_70 -> V_94 . V_12 =
V_44 -> V_9 . V_12 * V_70 -> V_94 . V_101 ;
else
V_70 -> V_94 . V_12 = V_70 -> V_94 . V_101 ;
} else {
V_70 -> V_94 . V_101 = F_60 ( V_44 -> V_9 . V_11 ) ;
V_70 -> V_94 . V_12 =
V_44 -> V_9 . V_12 + V_70 -> V_94 . V_101 ;
}
V_70 -> V_94 . V_98 = V_44 -> V_9 . V_98 ;
} else if ( V_44 -> V_9 . V_10 & V_102 ) {
V_70 -> V_94 . V_104 = V_89 * V_87 ;
V_70 -> V_94 . V_106 = F_59 ( V_44 -> V_9 . V_11 ) ;
V_70 -> V_94 . V_105 = V_44 -> V_9 . V_12 ;
} else {
V_70 -> V_94 . V_104 = F_57 ( V_44 -> V_9 . V_11 *
V_44 -> V_9 . V_12 , V_7 ) ;
V_70 -> V_94 . V_106 = F_57 ( V_44 -> V_9 . V_11 , V_7 ) ;
V_70 -> V_94 . V_105 = V_70 -> V_94 . V_104 ;
}
}
static inline T_4 F_65 ( T_4 V_107 , unsigned int V_108 )
{
return V_108 ? F_66 ( F_67 ( V_107 ) & ~ 0 << ( 32 - V_108 ) ) : 0 ;
}
static void F_68 ( T_4 * V_47 , unsigned int V_109 )
{
switch ( V_109 ) {
case 0 ... 31 :
V_47 [ 0 ] = F_65 ( V_47 [ 0 ] , V_109 ) ;
V_47 [ 1 ] = V_47 [ 2 ] = V_47 [ 3 ] = 0 ;
break;
case 32 ... 63 :
V_47 [ 1 ] = F_65 ( V_47 [ 1 ] , V_109 - 32 ) ;
V_47 [ 2 ] = V_47 [ 3 ] = 0 ;
break;
case 64 ... 95 :
V_47 [ 2 ] = F_65 ( V_47 [ 2 ] , V_109 - 64 ) ;
V_47 [ 3 ] = 0 ;
break;
case 96 ... 127 :
V_47 [ 3 ] = F_65 ( V_47 [ 3 ] , V_109 - 96 ) ;
break;
case 128 :
break;
}
}
static int
F_69 ( const struct V_26 * V_44 ,
struct V_23 * V_25 ,
const struct V_110 * V_111 , unsigned int V_112 )
{
T_5 V_113 [ 2 ] , * V_114 ;
T_6 V_115 ;
int V_116 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
switch ( V_44 -> V_42 ) {
case V_60 :
if ( V_44 -> V_9 . V_10 & V_117 )
V_25 -> V_118 . V_25 = F_65 ( F_70 ( V_111 ) -> V_119 ,
V_44 -> V_9 . V_18 ) ;
if ( V_44 -> V_9 . V_10 & V_120 )
V_25 -> V_118 . V_121 = F_65 ( F_70 ( V_111 ) -> V_122 ,
V_44 -> V_9 . V_17 ) ;
if ( ! ( V_44 -> V_9 . V_10 &
( V_123 | V_124 ) ) )
return 0 ;
V_115 = F_70 ( V_111 ) -> V_125 ;
break;
#if F_71 ( V_126 )
case V_127 :
{
T_5 V_128 ;
if ( V_44 -> V_9 . V_10 & V_117 ) {
memcpy ( & V_25 -> V_129 . V_25 , & F_72 ( V_111 ) -> V_119 ,
sizeof( V_25 -> V_129 . V_25 ) ) ;
F_68 ( V_25 -> V_129 . V_25 , V_44 -> V_9 . V_18 ) ;
}
if ( V_44 -> V_9 . V_10 & V_120 ) {
memcpy ( & V_25 -> V_129 . V_121 , & F_72 ( V_111 ) -> V_122 ,
sizeof( V_25 -> V_129 . V_121 ) ) ;
F_68 ( V_25 -> V_129 . V_121 , V_44 -> V_9 . V_17 ) ;
}
if ( ! ( V_44 -> V_9 . V_10 &
( V_123 | V_124 ) ) )
return 0 ;
V_115 = F_72 ( V_111 ) -> V_115 ;
V_112 = F_73 ( V_111 , sizeof( struct V_130 ) , & V_115 , & V_128 ) ;
if ( ( int ) V_112 < 0 )
return - 1 ;
break;
}
#endif
default:
F_74 () ;
return 0 ;
}
V_116 = F_75 ( V_115 ) ;
if ( V_116 >= 0 ) {
V_114 = F_76 ( V_111 , V_112 + V_116 , sizeof( V_113 ) ,
& V_113 ) ;
} else {
V_113 [ 0 ] = V_113 [ 1 ] = 0 ;
V_114 = V_113 ;
}
if ( ! V_114 )
return - 1 ;
if ( V_44 -> V_9 . V_10 & V_124 )
V_25 -> V_131 = V_114 [ 0 ] ;
if ( V_44 -> V_9 . V_10 & V_123 )
V_25 -> V_132 = V_114 [ 1 ] ;
return 0 ;
}
static V_29 F_77 ( unsigned int V_78 , struct V_21 * V_70 )
{
T_3 V_103 = F_56 ( V_78 ) ;
V_103 = V_103 * V_70 -> V_94 . V_106 ;
if ( F_14 ( V_103 > V_89 * V_87 ) )
V_103 = V_89 * V_87 ;
if ( V_70 -> V_94 . V_104 < V_103 && V_70 -> V_94 . V_105 ) {
V_70 -> V_94 . V_105 -- ;
V_70 -> V_94 . V_104 = V_89 * V_87 ;
}
return ( V_29 ) V_103 ;
}
static bool
F_78 ( const struct V_110 * V_111 , struct V_133 * V_134 ,
struct V_26 * V_44 ,
const struct V_4 * V_9 , int V_7 )
{
unsigned long V_92 = V_68 ;
struct V_21 * V_70 ;
struct V_23 V_25 ;
bool V_32 = false ;
T_3 V_106 ;
if ( F_69 ( V_44 , & V_25 , V_111 , V_134 -> V_135 ) < 0 )
goto V_136;
F_79 () ;
V_70 = F_8 ( V_44 , & V_25 ) ;
if ( V_70 == NULL ) {
V_70 = F_12 ( V_44 , & V_25 , & V_32 ) ;
if ( V_70 == NULL ) {
F_80 () ;
goto V_136;
} else if ( V_32 ) {
V_70 -> V_69 = V_92 + F_35 ( V_44 -> V_9 . V_16 ) ;
F_63 ( V_70 , V_92 , V_44 -> V_9 . V_10 , V_7 ) ;
} else {
V_70 -> V_69 = V_68 + F_35 ( V_44 -> V_9 . V_16 ) ;
F_64 ( V_70 , V_44 , V_7 ) ;
}
} else {
V_70 -> V_69 = V_92 + F_35 ( V_44 -> V_9 . V_16 ) ;
F_63 ( V_70 , V_92 , V_44 -> V_9 . V_10 , V_7 ) ;
}
if ( V_9 -> V_10 & V_97 ) {
V_106 = ( V_9 -> V_10 & V_102 ) ? V_111 -> V_78 : 1 ;
V_70 -> V_94 . V_100 += V_106 ;
if ( ! V_70 -> V_94 . V_99 &&
( V_70 -> V_94 . V_100 <= V_70 -> V_94 . V_12 ) ) {
F_13 ( & V_70 -> V_31 ) ;
F_81 () ;
return ! ( V_9 -> V_10 & V_137 ) ;
} else {
goto V_138;
}
}
if ( V_9 -> V_10 & V_102 )
V_106 = F_77 ( V_111 -> V_78 , V_70 ) ;
else
V_106 = V_70 -> V_94 . V_106 ;
if ( V_70 -> V_94 . V_104 >= V_106 ) {
V_70 -> V_94 . V_104 -= V_106 ;
F_13 ( & V_70 -> V_31 ) ;
F_80 () ;
return ! ( V_9 -> V_10 & V_137 ) ;
}
V_138:
F_13 ( & V_70 -> V_31 ) ;
F_80 () ;
return V_9 -> V_10 & V_137 ;
V_136:
V_134 -> V_136 = true ;
return false ;
}
static bool
F_82 ( const struct V_110 * V_111 , struct V_133 * V_134 )
{
const struct V_139 * V_140 = V_134 -> V_141 ;
struct V_26 * V_44 = V_140 -> V_44 ;
struct V_4 V_9 = {} ;
int V_48 ;
V_48 = F_3 ( & V_9 , ( void * ) & V_140 -> V_9 , 1 ) ;
if ( V_48 )
return V_48 ;
return F_78 ( V_111 , V_134 , V_44 , & V_9 , 1 ) ;
}
static bool
F_83 ( const struct V_110 * V_111 , struct V_133 * V_134 )
{
const struct V_142 * V_140 = V_134 -> V_141 ;
struct V_26 * V_44 = V_140 -> V_44 ;
struct V_4 V_9 = {} ;
int V_48 ;
V_48 = F_3 ( & V_9 , ( void * ) & V_140 -> V_9 , 2 ) ;
if ( V_48 )
return V_48 ;
return F_78 ( V_111 , V_134 , V_44 , & V_9 , 2 ) ;
}
static bool
F_84 ( const struct V_110 * V_111 , struct V_133 * V_134 )
{
const struct V_143 * V_140 = V_134 -> V_141 ;
struct V_26 * V_44 = V_140 -> V_44 ;
return F_78 ( V_111 , V_134 , V_44 , & V_140 -> V_9 , 3 ) ;
}
static int F_85 ( const struct V_144 * V_134 ,
struct V_26 * * V_44 ,
struct V_4 * V_9 ,
const char * V_41 , int V_7 )
{
struct V_2 * V_2 = V_134 -> V_2 ;
int V_48 ;
if ( V_9 -> V_15 == 0 || V_9 -> V_16 == 0 )
return - V_20 ;
if ( V_134 -> V_42 == V_60 ) {
if ( V_9 -> V_17 > 32 || V_9 -> V_18 > 32 )
return - V_20 ;
} else {
if ( V_9 -> V_17 > 128 || V_9 -> V_18 > 128 )
return - V_20 ;
}
if ( V_9 -> V_10 & ~ V_145 ) {
F_86 ( L_3 ,
V_9 -> V_10 ) ;
return - V_20 ;
}
if ( V_7 >= 3 && V_9 -> V_10 & V_97 ) {
if ( V_9 -> V_11 == 0 || V_9 -> V_11 > V_91 ) {
F_86 ( L_4 ) ;
return - V_146 ;
}
if ( V_9 -> V_98 == 0 ) {
F_86 ( L_5 ) ;
return - V_20 ;
}
} else if ( V_9 -> V_10 & V_102 ) {
if ( F_59 ( V_9 -> V_11 ) == 0 ) {
F_86 ( L_6 , V_9 -> V_11 ) ;
return - V_20 ;
}
} else if ( V_9 -> V_12 == 0 ||
F_57 ( V_9 -> V_11 * V_9 -> V_12 , V_7 ) <
F_57 ( V_9 -> V_11 , V_7 ) ) {
F_86 ( L_7 ,
V_9 -> V_11 , V_9 -> V_12 ) ;
return - V_146 ;
}
F_53 ( & V_77 ) ;
* V_44 = F_50 ( V_2 , V_41 , V_134 -> V_42 ) ;
if ( * V_44 == NULL ) {
V_48 = F_26 ( V_2 , V_9 , V_41 , V_134 -> V_42 ,
V_44 , V_7 ) ;
if ( V_48 < 0 ) {
F_55 ( & V_77 ) ;
return V_48 ;
}
}
F_55 ( & V_77 ) ;
return 0 ;
}
static int F_87 ( const struct V_144 * V_134 )
{
struct V_139 * V_140 = V_134 -> V_141 ;
struct V_4 V_9 = {} ;
int V_48 ;
if ( V_140 -> V_41 [ sizeof( V_140 -> V_41 ) - 1 ] != '\0' )
return - V_20 ;
V_48 = F_3 ( & V_9 , ( void * ) & V_140 -> V_9 , 1 ) ;
if ( V_48 )
return V_48 ;
return F_85 ( V_134 , & V_140 -> V_44 ,
& V_9 , V_140 -> V_41 , 1 ) ;
}
static int F_88 ( const struct V_144 * V_134 )
{
struct V_142 * V_140 = V_134 -> V_141 ;
struct V_4 V_9 = {} ;
int V_48 ;
if ( V_140 -> V_41 [ sizeof( V_140 -> V_41 ) - 1 ] != '\0' )
return - V_20 ;
V_48 = F_3 ( & V_9 , ( void * ) & V_140 -> V_9 , 2 ) ;
if ( V_48 )
return V_48 ;
return F_85 ( V_134 , & V_140 -> V_44 ,
& V_9 , V_140 -> V_41 , 2 ) ;
}
static int F_89 ( const struct V_144 * V_134 )
{
struct V_143 * V_140 = V_134 -> V_141 ;
if ( V_140 -> V_41 [ sizeof( V_140 -> V_41 ) - 1 ] != '\0' )
return - V_20 ;
return F_85 ( V_134 , & V_140 -> V_44 , & V_140 -> V_9 ,
V_140 -> V_41 , 3 ) ;
}
static void F_90 ( const struct V_147 * V_134 )
{
const struct V_142 * V_140 = V_134 -> V_141 ;
F_52 ( V_140 -> V_44 ) ;
}
static void F_91 ( const struct V_147 * V_134 )
{
const struct V_139 * V_140 = V_134 -> V_141 ;
F_52 ( V_140 -> V_44 ) ;
}
static void F_92 ( const struct V_147 * V_134 )
{
const struct V_143 * V_140 = V_134 -> V_141 ;
F_52 ( V_140 -> V_44 ) ;
}
static void * F_93 ( struct V_148 * V_149 , T_7 * V_150 )
__acquires( V_151 -> V_31 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 ;
F_42 ( & V_151 -> V_31 ) ;
if ( * V_150 >= V_151 -> V_9 . V_13 )
return NULL ;
V_153 = F_94 ( sizeof( unsigned int ) , V_36 ) ;
if ( ! V_153 )
return F_95 ( - V_53 ) ;
* V_153 = * V_150 ;
return V_153 ;
}
static void * F_96 ( struct V_148 * V_149 , void * V_154 , T_7 * V_150 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 = V_154 ;
* V_150 = ++ ( * V_153 ) ;
if ( * V_150 >= V_151 -> V_9 . V_13 ) {
F_32 ( V_154 ) ;
return NULL ;
}
return V_153 ;
}
static void F_97 ( struct V_148 * V_149 , void * V_154 )
__releases( V_151 -> V_31 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 = V_154 ;
if ( ! F_98 ( V_153 ) )
F_32 ( V_153 ) ;
F_44 ( & V_151 -> V_31 ) ;
}
static void F_99 ( struct V_21 * V_22 , T_2 V_42 ,
struct V_148 * V_149 )
{
switch ( V_42 ) {
case V_60 :
F_100 ( V_149 , L_8 ,
( long ) ( V_22 -> V_69 - V_68 ) / V_87 ,
& V_22 -> V_25 . V_118 . V_121 ,
F_101 ( V_22 -> V_25 . V_131 ) ,
& V_22 -> V_25 . V_118 . V_25 ,
F_101 ( V_22 -> V_25 . V_132 ) ,
V_22 -> V_94 . V_104 , V_22 -> V_94 . V_105 ,
V_22 -> V_94 . V_106 ) ;
break;
#if F_71 ( V_126 )
case V_127 :
F_100 ( V_149 , L_9 ,
( long ) ( V_22 -> V_69 - V_68 ) / V_87 ,
& V_22 -> V_25 . V_129 . V_121 ,
F_101 ( V_22 -> V_25 . V_131 ) ,
& V_22 -> V_25 . V_129 . V_25 ,
F_101 ( V_22 -> V_25 . V_132 ) ,
V_22 -> V_94 . V_104 , V_22 -> V_94 . V_105 ,
V_22 -> V_94 . V_106 ) ;
break;
#endif
default:
F_74 () ;
}
}
static int F_102 ( struct V_21 * V_22 , T_2 V_42 ,
struct V_148 * V_149 )
{
const struct V_26 * V_27 = V_149 -> V_152 ;
F_11 ( & V_22 -> V_31 ) ;
F_63 ( V_22 , V_68 , V_27 -> V_9 . V_10 , 2 ) ;
F_99 ( V_22 , V_42 , V_149 ) ;
F_13 ( & V_22 -> V_31 ) ;
return F_103 ( V_149 ) ;
}
static int F_104 ( struct V_21 * V_22 , T_2 V_42 ,
struct V_148 * V_149 )
{
const struct V_26 * V_27 = V_149 -> V_152 ;
F_11 ( & V_22 -> V_31 ) ;
F_63 ( V_22 , V_68 , V_27 -> V_9 . V_10 , 1 ) ;
F_99 ( V_22 , V_42 , V_149 ) ;
F_13 ( & V_22 -> V_31 ) ;
return F_103 ( V_149 ) ;
}
static int F_105 ( struct V_21 * V_22 , T_2 V_42 ,
struct V_148 * V_149 )
{
const struct V_26 * V_27 = V_149 -> V_152 ;
F_11 ( & V_22 -> V_31 ) ;
F_63 ( V_22 , V_68 , V_27 -> V_9 . V_10 , 3 ) ;
F_99 ( V_22 , V_42 , V_149 ) ;
F_13 ( & V_22 -> V_31 ) ;
return F_103 ( V_149 ) ;
}
static int F_106 ( struct V_148 * V_149 , void * V_154 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 = ( unsigned int * ) V_154 ;
struct V_21 * V_22 ;
if ( ! F_9 ( & V_151 -> V_28 [ * V_153 ] ) ) {
F_51 (ent, &htable->hash[*bucket], node)
if ( F_102 ( V_22 , V_151 -> V_42 , V_149 ) )
return - 1 ;
}
return 0 ;
}
static int F_107 ( struct V_148 * V_149 , void * V_154 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 = V_154 ;
struct V_21 * V_22 ;
if ( ! F_9 ( & V_151 -> V_28 [ * V_153 ] ) ) {
F_51 (ent, &htable->hash[*bucket], node)
if ( F_104 ( V_22 , V_151 -> V_42 , V_149 ) )
return - 1 ;
}
return 0 ;
}
static int F_108 ( struct V_148 * V_149 , void * V_154 )
{
struct V_26 * V_151 = V_149 -> V_152 ;
unsigned int * V_153 = V_154 ;
struct V_21 * V_22 ;
if ( ! F_9 ( & V_151 -> V_28 [ * V_153 ] ) ) {
F_51 (ent, &htable->hash[*bucket], node)
if ( F_105 ( V_22 , V_151 -> V_42 , V_149 ) )
return - 1 ;
}
return 0 ;
}
static int F_109 ( struct V_155 * V_155 , struct V_156 * V_156 )
{
int V_48 = F_110 ( V_156 , & V_157 ) ;
if ( ! V_48 ) {
struct V_148 * V_158 = V_156 -> V_159 ;
V_158 -> V_152 = F_111 ( V_155 ) ;
}
return V_48 ;
}
static int F_112 ( struct V_155 * V_155 , struct V_156 * V_156 )
{
int V_48 = F_110 ( V_156 , & V_160 ) ;
if ( ! V_48 ) {
struct V_148 * V_158 = V_156 -> V_159 ;
V_158 -> V_152 = F_111 ( V_155 ) ;
}
return V_48 ;
}
static int F_113 ( struct V_155 * V_155 , struct V_156 * V_156 )
{
int V_48 = F_110 ( V_156 , & V_161 ) ;
if ( ! V_48 ) {
struct V_148 * V_158 = V_156 -> V_159 ;
V_158 -> V_152 = F_111 ( V_155 ) ;
}
return V_48 ;
}
static int T_8 F_114 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_61 = F_115 ( L_10 , V_2 -> V_162 ) ;
if ( ! V_1 -> V_61 )
return - V_53 ;
#if F_71 ( V_126 )
V_1 -> V_62 = F_115 ( L_11 , V_2 -> V_162 ) ;
if ( ! V_1 -> V_62 ) {
F_47 ( L_10 , V_2 -> V_162 ) ;
return - V_53 ;
}
#endif
return 0 ;
}
static void T_9 F_116 ( struct V_2 * V_2 )
{
struct V_26 * V_44 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_53 ( & V_77 ) ;
F_51 (hinfo, &hashlimit_net->htables, node)
F_46 ( V_44 ) ;
V_1 -> V_61 = NULL ;
V_1 -> V_62 = NULL ;
F_55 ( & V_77 ) ;
F_47 ( L_10 , V_2 -> V_162 ) ;
#if F_71 ( V_126 )
F_47 ( L_11 , V_2 -> V_162 ) ;
#endif
}
static int T_8 F_117 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_28 ( & V_1 -> V_66 ) ;
return F_114 ( V_2 ) ;
}
static void T_9 F_118 ( struct V_2 * V_2 )
{
F_116 ( V_2 ) ;
}
static int T_10 F_119 ( void )
{
int V_163 ;
V_163 = F_120 ( & V_164 ) ;
if ( V_163 < 0 )
return V_163 ;
V_163 = F_121 ( V_165 ,
F_122 ( V_165 ) ) ;
if ( V_163 < 0 )
goto V_166;
V_163 = - V_53 ;
V_35 = F_123 ( L_12 ,
sizeof( struct V_21 ) , 0 , 0 ,
NULL ) ;
if ( ! V_35 ) {
F_61 ( L_13 ) ;
goto V_167;
}
return 0 ;
V_167:
F_124 ( V_165 , F_122 ( V_165 ) ) ;
V_166:
F_125 ( & V_164 ) ;
return V_163 ;
}
static void T_11 F_126 ( void )
{
F_124 ( V_165 , F_122 ( V_165 ) ) ;
F_125 ( & V_164 ) ;
F_127 () ;
F_128 ( V_35 ) ;
}
