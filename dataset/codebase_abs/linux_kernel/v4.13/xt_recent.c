static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline unsigned int F_3 ( const union V_4 * V_5 )
{
return F_4 ( ( V_6 V_7 ) V_5 -> V_8 , V_9 ) &
( V_10 - 1 ) ;
}
static inline unsigned int F_5 ( const union V_4 * V_5 )
{
return F_6 ( ( V_7 * ) V_5 -> V_11 , F_7 ( V_5 -> V_11 ) , V_9 ) &
( V_10 - 1 ) ;
}
static struct V_12 *
F_8 ( const struct V_13 * V_14 ,
const union V_4 * V_15 , T_1 V_16 ,
T_2 V_17 )
{
struct V_12 * V_18 ;
unsigned int V_19 ;
if ( V_16 == V_20 )
V_19 = F_3 ( V_15 ) ;
else
V_19 = F_5 ( V_15 ) ;
F_9 (e, &table->iphash[h], list)
if ( V_18 -> V_16 == V_16 &&
memcmp ( & V_18 -> V_5 , V_15 , sizeof( V_18 -> V_5 ) ) == 0 &&
( V_17 == V_18 -> V_17 || V_17 == 0 || V_18 -> V_17 == 0 ) )
return V_18 ;
return NULL ;
}
static void F_10 ( struct V_13 * V_21 , struct V_12 * V_18 )
{
F_11 ( & V_18 -> V_22 ) ;
F_11 ( & V_18 -> V_23 ) ;
F_12 ( V_18 ) ;
V_21 -> V_24 -- ;
}
static void F_13 ( struct V_13 * V_21 , unsigned long time )
{
struct V_12 * V_18 ;
V_18 = F_14 ( V_21 -> V_23 . V_25 , struct V_12 , V_23 ) ;
if ( F_15 ( time , V_18 -> V_26 [ V_18 -> V_27 - 1 ] ) )
F_10 ( V_21 , V_18 ) ;
}
static struct V_12 *
F_16 ( struct V_13 * V_21 , const union V_4 * V_5 ,
T_1 V_16 , T_2 V_17 )
{
struct V_12 * V_18 ;
unsigned int V_28 = V_21 -> V_29 ;
if ( V_21 -> V_24 >= V_30 ) {
V_18 = F_14 ( V_21 -> V_23 . V_25 , struct V_12 , V_23 ) ;
F_10 ( V_21 , V_18 ) ;
}
V_28 += 1 ;
V_18 = F_17 ( sizeof( * V_18 ) + sizeof( V_18 -> V_26 [ 0 ] ) * V_28 ,
V_31 ) ;
if ( V_18 == NULL )
return NULL ;
memcpy ( & V_18 -> V_5 , V_5 , sizeof( V_18 -> V_5 ) ) ;
V_18 -> V_17 = V_17 ;
V_18 -> V_26 [ 0 ] = V_32 ;
V_18 -> V_33 = 1 ;
V_18 -> V_27 = 1 ;
V_18 -> V_16 = V_16 ;
if ( V_16 == V_20 )
F_18 ( & V_18 -> V_22 , & V_21 -> V_34 [ F_3 ( V_5 ) ] ) ;
else
F_18 ( & V_18 -> V_22 , & V_21 -> V_34 [ F_5 ( V_5 ) ] ) ;
F_18 ( & V_18 -> V_23 , & V_21 -> V_23 ) ;
V_21 -> V_24 ++ ;
return V_18 ;
}
static void F_19 ( struct V_13 * V_21 , struct V_12 * V_18 )
{
V_18 -> V_27 &= V_21 -> V_29 ;
V_18 -> V_26 [ V_18 -> V_27 ++ ] = V_32 ;
if ( V_18 -> V_27 > V_18 -> V_33 )
V_18 -> V_33 = V_18 -> V_27 ;
F_20 ( & V_18 -> V_23 , & V_21 -> V_23 ) ;
}
static struct V_13 * F_21 ( struct V_1 * V_1 ,
const char * V_35 )
{
struct V_13 * V_21 ;
F_9 (t, &recent_net->tables, list)
if ( ! strcmp ( V_21 -> V_35 , V_35 ) )
return V_21 ;
return NULL ;
}
static void F_22 ( struct V_13 * V_21 )
{
struct V_12 * V_18 , * V_25 ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_10 ; V_36 ++ )
F_23 (e, next, &t->iphash[i], list)
F_10 ( V_21 , V_18 ) ;
}
static bool
F_24 ( const struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_2 * V_2 = F_25 ( V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
const struct V_41 * V_42 = V_40 -> V_43 ;
struct V_13 * V_21 ;
struct V_12 * V_18 ;
union V_4 V_5 = {} , V_44 ;
T_2 V_17 ;
bool V_45 = V_42 -> V_46 ;
if ( F_26 ( V_40 ) == V_20 ) {
const struct V_47 * V_48 = F_27 ( V_38 ) ;
if ( V_42 -> V_49 == V_50 )
V_5 . V_8 = V_48 -> V_51 ;
else
V_5 . V_8 = V_48 -> V_52 ;
V_17 = V_48 -> V_17 ;
} else {
const struct V_53 * V_48 = F_28 ( V_38 ) ;
if ( V_42 -> V_49 == V_50 )
memcpy ( & V_5 . V_54 , & V_48 -> V_51 , sizeof( V_5 . V_54 ) ) ;
else
memcpy ( & V_5 . V_54 , & V_48 -> V_52 , sizeof( V_5 . V_54 ) ) ;
V_17 = V_48 -> V_55 ;
}
if ( F_29 ( V_40 ) != NULL && V_38 -> V_56 == NULL )
V_17 ++ ;
F_30 ( & V_57 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
F_31 ( & V_5 , & V_44 , & V_21 -> V_58 ) ;
V_18 = F_8 ( V_21 , & V_44 , F_26 ( V_40 ) ,
( V_42 -> V_59 & V_60 ) ? V_17 : 0 ) ;
if ( V_18 == NULL ) {
if ( ! ( V_42 -> V_59 & V_61 ) )
goto V_62;
V_18 = F_16 ( V_21 , & V_44 , F_26 ( V_40 ) , V_17 ) ;
if ( V_18 == NULL )
V_40 -> V_63 = true ;
V_45 = ! V_45 ;
goto V_62;
}
if ( V_42 -> V_59 & V_61 )
V_45 = ! V_45 ;
else if ( V_42 -> V_59 & V_64 ) {
F_10 ( V_21 , V_18 ) ;
V_45 = ! V_45 ;
} else if ( V_42 -> V_59 & ( V_65 | V_66 ) ) {
unsigned long time = V_32 - V_42 -> V_67 * V_68 ;
unsigned int V_36 , V_69 = 0 ;
for ( V_36 = 0 ; V_36 < V_18 -> V_33 ; V_36 ++ ) {
if ( V_42 -> V_67 && F_15 ( time , V_18 -> V_26 [ V_36 ] ) )
continue;
if ( ! V_42 -> V_70 || ++ V_69 >= V_42 -> V_70 ) {
V_45 = ! V_45 ;
break;
}
}
if ( V_42 -> V_59 & V_71 )
F_13 ( V_21 , time ) ;
}
if ( V_42 -> V_59 & V_61 ||
( V_42 -> V_59 & V_66 && V_45 ) ) {
F_19 ( V_21 , V_18 ) ;
V_18 -> V_17 = V_17 ;
}
V_62:
F_32 ( & V_57 ) ;
return V_45 ;
}
static void F_33 ( void * V_5 )
{
F_34 ( V_5 ) ;
}
static int F_35 ( const struct V_72 * V_40 ,
const struct V_41 * V_42 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
struct V_13 * V_21 ;
#ifdef F_36
struct V_73 * V_74 ;
T_3 V_75 ;
T_4 V_76 ;
#endif
unsigned int V_77 ;
unsigned int V_36 ;
int V_45 = - V_78 ;
T_5 V_79 ;
F_37 ( & V_9 , sizeof( V_9 ) ) ;
if ( V_42 -> V_59 & ~ V_80 ) {
F_38 ( L_1 ,
V_42 -> V_59 ) ;
return - V_78 ;
}
if ( F_39 ( V_42 -> V_59 &
( V_61 | V_64 |
V_65 | V_66 ) ) != 1 )
return - V_78 ;
if ( ( V_42 -> V_59 & ( V_61 | V_64 ) ) &&
( V_42 -> V_67 || V_42 -> V_70 ||
( V_42 -> V_59 & V_81 ) ) )
return - V_78 ;
if ( ( V_42 -> V_59 & V_71 ) && ! V_42 -> V_67 )
return - V_78 ;
if ( V_42 -> V_70 >= V_82 ) {
F_38 ( L_2 ,
V_42 -> V_70 , V_82 - 1 ) ;
return - V_78 ;
}
if ( V_42 -> V_35 [ 0 ] == '\0' ||
F_40 ( V_42 -> V_35 , V_83 ) == V_83 )
return - V_78 ;
if ( V_84 && V_42 -> V_70 < V_84 )
V_77 = F_41 ( V_84 ) - 1 ;
else if ( V_42 -> V_70 )
V_77 = F_41 ( V_42 -> V_70 ) - 1 ;
else
V_77 = 32 - 1 ;
F_42 ( & V_85 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
if ( V_21 != NULL ) {
if ( V_77 > V_21 -> V_29 ) {
F_30 ( & V_57 ) ;
F_22 ( V_21 ) ;
V_21 -> V_29 = V_77 ;
F_32 ( & V_57 ) ;
}
V_21 -> V_86 ++ ;
V_45 = 0 ;
goto V_62;
}
V_79 = sizeof( * V_21 ) + sizeof( V_21 -> V_34 [ 0 ] ) * V_10 ;
V_21 = F_43 ( V_79 , V_87 ) ;
if ( V_21 == NULL ) {
V_45 = - V_88 ;
goto V_62;
}
V_21 -> V_86 = 1 ;
V_21 -> V_29 = V_77 ;
memcpy ( & V_21 -> V_58 , & V_42 -> V_58 , sizeof( V_21 -> V_58 ) ) ;
strcpy ( V_21 -> V_35 , V_42 -> V_35 ) ;
F_44 ( & V_21 -> V_23 ) ;
for ( V_36 = 0 ; V_36 < V_10 ; V_36 ++ )
F_44 ( & V_21 -> V_34 [ V_36 ] ) ;
#ifdef F_36
V_75 = F_45 ( & V_89 , V_90 ) ;
V_76 = F_46 ( & V_89 , V_91 ) ;
if ( ! F_47 ( V_75 ) || ! F_48 ( V_76 ) ) {
F_33 ( V_21 ) ;
V_45 = - V_78 ;
goto V_62;
}
V_74 = F_49 ( V_21 -> V_35 , V_92 , V_1 -> V_93 ,
& V_94 , V_21 ) ;
if ( V_74 == NULL ) {
F_33 ( V_21 ) ;
V_45 = - V_88 ;
goto V_62;
}
F_50 ( V_74 , V_75 , V_76 ) ;
#endif
F_30 ( & V_57 ) ;
F_18 ( & V_21 -> V_22 , & V_1 -> V_95 ) ;
F_32 ( & V_57 ) ;
V_45 = 0 ;
V_62:
F_51 ( & V_85 ) ;
return V_45 ;
}
static int F_52 ( const struct V_72 * V_40 )
{
const struct V_96 * V_97 = V_40 -> V_43 ;
struct V_41 V_98 ;
memcpy ( & V_98 , V_97 , sizeof( struct V_99 ) ) ;
memset ( V_98 . V_58 . V_100 , 0xFF , sizeof( V_98 . V_58 . V_100 ) ) ;
return F_35 ( V_40 , & V_98 ) ;
}
static int F_53 ( const struct V_72 * V_40 )
{
return F_35 ( V_40 , V_40 -> V_43 ) ;
}
static void F_54 ( const struct V_101 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
const struct V_41 * V_42 = V_40 -> V_43 ;
struct V_13 * V_21 ;
F_42 ( & V_85 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
if ( -- V_21 -> V_86 == 0 ) {
F_30 ( & V_57 ) ;
F_11 ( & V_21 -> V_22 ) ;
F_32 ( & V_57 ) ;
#ifdef F_36
if ( V_1 -> V_93 != NULL )
F_55 ( V_21 -> V_35 , V_1 -> V_93 ) ;
#endif
F_22 ( V_21 ) ;
F_33 ( V_21 ) ;
}
F_51 ( & V_85 ) ;
}
static void * F_56 ( struct V_102 * V_103 , T_6 * V_104 )
__acquires( V_57 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
const struct V_13 * V_21 = V_106 -> V_14 ;
struct V_12 * V_18 ;
T_6 V_108 = * V_104 ;
F_30 ( & V_57 ) ;
for ( V_106 -> V_109 = 0 ; V_106 -> V_109 < V_10 ; V_106 -> V_109 ++ )
F_9 (e, &t->iphash[st->bucket], list)
if ( V_108 -- == 0 )
return V_18 ;
return NULL ;
}
static void * F_57 ( struct V_102 * V_103 , void * V_110 , T_6 * V_104 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
const struct V_13 * V_21 = V_106 -> V_14 ;
const struct V_12 * V_18 = V_110 ;
const struct V_111 * V_112 = V_18 -> V_22 . V_25 ;
while ( V_112 == & V_21 -> V_34 [ V_106 -> V_109 ] ) {
if ( ++ V_106 -> V_109 >= V_10 )
return NULL ;
V_112 = V_21 -> V_34 [ V_106 -> V_109 ] . V_25 ;
}
( * V_104 ) ++ ;
return F_14 ( V_112 , struct V_12 , V_22 ) ;
}
static void F_58 ( struct V_102 * V_113 , void * V_110 )
__releases( V_57 )
{
F_32 ( & V_57 ) ;
}
static int F_59 ( struct V_102 * V_103 , void * V_110 )
{
const struct V_12 * V_18 = V_110 ;
struct V_105 * V_106 = V_103 -> V_107 ;
const struct V_13 * V_21 = V_106 -> V_14 ;
unsigned int V_36 ;
V_36 = ( V_18 -> V_27 - 1 ) & V_21 -> V_29 ;
if ( V_18 -> V_16 == V_20 )
F_60 ( V_103 , L_3 ,
& V_18 -> V_5 . V_8 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
else
F_60 ( V_103 , L_4 ,
& V_18 -> V_5 . V_54 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
for ( V_36 = 0 ; V_36 < V_18 -> V_33 ; V_36 ++ )
F_60 ( V_103 , L_5 , V_36 ? L_6 : L_7 , V_18 -> V_26 [ V_36 ] ) ;
F_61 ( V_103 , '\n' ) ;
return 0 ;
}
static int F_62 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
struct V_105 * V_106 ;
V_106 = F_63 ( V_115 , & V_116 , sizeof( * V_106 ) ) ;
if ( V_106 == NULL )
return - V_88 ;
V_106 -> V_14 = F_64 ( V_114 ) ;
return 0 ;
}
static T_7
F_65 ( struct V_115 * V_115 , const char T_8 * V_117 ,
T_5 V_118 , T_6 * V_119 )
{
struct V_13 * V_21 = F_64 ( F_66 ( V_115 ) ) ;
struct V_12 * V_18 ;
char V_120 [ sizeof( L_8 ) ] ;
const char * V_121 = V_120 ;
union V_4 V_5 = {} ;
T_1 V_16 ;
bool V_122 , V_123 ;
if ( V_118 == 0 )
return 0 ;
if ( V_118 > sizeof( V_120 ) )
V_118 = sizeof( V_120 ) ;
if ( F_67 ( V_120 , V_117 , V_118 ) != 0 )
return - V_124 ;
if ( * V_119 != 0 )
return - V_125 ;
switch ( * V_121 ) {
case '/' :
F_30 ( & V_57 ) ;
F_22 ( V_21 ) ;
F_32 ( & V_57 ) ;
return V_118 ;
case '-' :
V_122 = false ;
break;
case '+' :
V_122 = true ;
break;
default:
F_38 ( L_9 ) ;
return - V_78 ;
}
++ V_121 ;
-- V_118 ;
if ( F_68 ( V_121 , V_118 , ':' ) != NULL ) {
V_16 = V_126 ;
V_123 = F_69 ( V_121 , V_118 , ( void * ) & V_5 , '\n' , NULL ) ;
} else {
V_16 = V_20 ;
V_123 = F_70 ( V_121 , V_118 , ( void * ) & V_5 , '\n' , NULL ) ;
}
if ( ! V_123 ) {
F_38 ( L_10 ) ;
return - V_78 ;
}
F_30 ( & V_57 ) ;
V_18 = F_8 ( V_21 , & V_5 , V_16 , 0 ) ;
if ( V_18 == NULL ) {
if ( V_122 )
F_16 ( V_21 , & V_5 , V_16 , 0 ) ;
} else {
if ( V_122 )
F_19 ( V_21 , V_18 ) ;
else
F_10 ( V_21 , V_18 ) ;
}
F_32 ( & V_57 ) ;
* V_119 += V_118 + 1 ;
return V_118 + 1 ;
}
static int T_9 F_71 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_93 = F_72 ( L_11 , V_2 -> V_127 ) ;
if ( ! V_1 -> V_93 )
return - V_88 ;
return 0 ;
}
static void T_10 F_73 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_13 * V_21 ;
F_30 ( & V_57 ) ;
F_9 (t, &recent_net->tables, list)
F_55 ( V_21 -> V_35 , V_1 -> V_93 ) ;
V_1 -> V_93 = NULL ;
F_32 ( & V_57 ) ;
F_55 ( L_11 , V_2 -> V_127 ) ;
}
static inline int F_71 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_73 ( struct V_2 * V_2 )
{
}
static int T_9 F_74 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_44 ( & V_1 -> V_95 ) ;
return F_71 ( V_2 ) ;
}
static void T_10 F_75 ( struct V_2 * V_2 )
{
F_73 ( V_2 ) ;
}
static int T_11 F_76 ( void )
{
int V_128 ;
F_77 ( V_82 ) ;
if ( ! V_30 || V_84 >= V_82 )
return - V_78 ;
V_10 = 1 << F_78 ( V_30 ) ;
V_128 = F_79 ( & V_129 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_80 ( V_130 , F_7 ( V_130 ) ) ;
if ( V_128 )
F_81 ( & V_129 ) ;
return V_128 ;
}
static void T_12 F_82 ( void )
{
F_83 ( V_130 , F_7 ( V_130 ) ) ;
F_81 ( & V_129 ) ;
}
