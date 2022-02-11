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
struct V_2 * V_2 = F_25 ( V_40 -> V_41 ? V_40 -> V_41 : V_40 -> V_42 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
const struct V_43 * V_44 = V_40 -> V_45 ;
struct V_13 * V_21 ;
struct V_12 * V_18 ;
union V_4 V_5 = {} , V_46 ;
T_2 V_17 ;
bool V_47 = V_44 -> V_48 ;
if ( V_40 -> V_16 == V_20 ) {
const struct V_49 * V_50 = F_26 ( V_38 ) ;
if ( V_44 -> V_51 == V_52 )
V_5 . V_8 = V_50 -> V_53 ;
else
V_5 . V_8 = V_50 -> V_54 ;
V_17 = V_50 -> V_17 ;
} else {
const struct V_55 * V_50 = F_27 ( V_38 ) ;
if ( V_44 -> V_51 == V_52 )
memcpy ( & V_5 . V_56 , & V_50 -> V_53 , sizeof( V_5 . V_56 ) ) ;
else
memcpy ( & V_5 . V_56 , & V_50 -> V_54 , sizeof( V_5 . V_56 ) ) ;
V_17 = V_50 -> V_57 ;
}
if ( V_40 -> V_42 != NULL && V_38 -> V_58 == NULL )
V_17 ++ ;
F_28 ( & V_59 ) ;
V_21 = F_21 ( V_1 , V_44 -> V_35 ) ;
F_29 ( & V_5 , & V_46 , & V_21 -> V_60 ) ;
V_18 = F_8 ( V_21 , & V_46 , V_40 -> V_16 ,
( V_44 -> V_61 & V_62 ) ? V_17 : 0 ) ;
if ( V_18 == NULL ) {
if ( ! ( V_44 -> V_61 & V_63 ) )
goto V_42;
V_18 = F_16 ( V_21 , & V_46 , V_40 -> V_16 , V_17 ) ;
if ( V_18 == NULL )
V_40 -> V_64 = true ;
V_47 = ! V_47 ;
goto V_42;
}
if ( V_44 -> V_61 & V_63 )
V_47 = ! V_47 ;
else if ( V_44 -> V_61 & V_65 ) {
F_10 ( V_21 , V_18 ) ;
V_47 = ! V_47 ;
} else if ( V_44 -> V_61 & ( V_66 | V_67 ) ) {
unsigned long time = V_32 - V_44 -> V_68 * V_69 ;
unsigned int V_36 , V_70 = 0 ;
for ( V_36 = 0 ; V_36 < V_18 -> V_33 ; V_36 ++ ) {
if ( V_44 -> V_68 && F_15 ( time , V_18 -> V_26 [ V_36 ] ) )
continue;
if ( ! V_44 -> V_71 || ++ V_70 >= V_44 -> V_71 ) {
V_47 = ! V_47 ;
break;
}
}
if ( V_44 -> V_61 & V_72 )
F_13 ( V_21 , time ) ;
}
if ( V_44 -> V_61 & V_63 ||
( V_44 -> V_61 & V_67 && V_47 ) ) {
F_19 ( V_21 , V_18 ) ;
V_18 -> V_17 = V_17 ;
}
V_42:
F_30 ( & V_59 ) ;
return V_47 ;
}
static void F_31 ( void * V_5 )
{
F_32 ( V_5 ) ;
}
static int F_33 ( const struct V_73 * V_40 ,
const struct V_43 * V_44 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
struct V_13 * V_21 ;
#ifdef F_34
struct V_74 * V_75 ;
T_3 V_76 ;
T_4 V_77 ;
#endif
unsigned int V_78 ;
unsigned int V_36 ;
int V_47 = - V_79 ;
T_5 V_80 ;
if ( F_35 ( ! V_81 ) ) {
F_36 ( & V_9 , sizeof( V_9 ) ) ;
V_81 = true ;
}
if ( V_44 -> V_61 & ~ V_82 ) {
F_37 ( L_1 ,
V_44 -> V_61 ) ;
return - V_79 ;
}
if ( F_38 ( V_44 -> V_61 &
( V_63 | V_65 |
V_66 | V_67 ) ) != 1 )
return - V_79 ;
if ( ( V_44 -> V_61 & ( V_63 | V_65 ) ) &&
( V_44 -> V_68 || V_44 -> V_71 ||
( V_44 -> V_61 & V_83 ) ) )
return - V_79 ;
if ( ( V_44 -> V_61 & V_72 ) && ! V_44 -> V_68 )
return - V_79 ;
if ( V_44 -> V_71 >= V_84 ) {
F_37 ( L_2 ,
V_44 -> V_71 , V_84 - 1 ) ;
return - V_79 ;
}
if ( V_44 -> V_35 [ 0 ] == '\0' ||
F_39 ( V_44 -> V_35 , V_85 ) == V_85 )
return - V_79 ;
if ( V_86 && V_44 -> V_71 < V_86 )
V_78 = F_40 ( V_86 ) - 1 ;
else if ( V_44 -> V_71 )
V_78 = F_40 ( V_44 -> V_71 ) - 1 ;
else
V_78 = 32 - 1 ;
F_41 ( & V_87 ) ;
V_21 = F_21 ( V_1 , V_44 -> V_35 ) ;
if ( V_21 != NULL ) {
if ( V_78 > V_21 -> V_29 ) {
F_28 ( & V_59 ) ;
F_22 ( V_21 ) ;
V_21 -> V_29 = V_78 ;
F_30 ( & V_59 ) ;
}
V_21 -> V_88 ++ ;
V_47 = 0 ;
goto V_42;
}
V_80 = sizeof( * V_21 ) + sizeof( V_21 -> V_34 [ 0 ] ) * V_10 ;
if ( V_80 <= V_89 )
V_21 = F_42 ( V_80 , V_90 ) ;
else
V_21 = F_43 ( V_80 ) ;
if ( V_21 == NULL ) {
V_47 = - V_91 ;
goto V_42;
}
V_21 -> V_88 = 1 ;
V_21 -> V_29 = V_78 ;
memcpy ( & V_21 -> V_60 , & V_44 -> V_60 , sizeof( V_21 -> V_60 ) ) ;
strcpy ( V_21 -> V_35 , V_44 -> V_35 ) ;
F_44 ( & V_21 -> V_23 ) ;
for ( V_36 = 0 ; V_36 < V_10 ; V_36 ++ )
F_44 ( & V_21 -> V_34 [ V_36 ] ) ;
#ifdef F_34
V_76 = F_45 ( & V_92 , V_93 ) ;
V_77 = F_46 ( & V_92 , V_94 ) ;
if ( ! F_47 ( V_76 ) || ! F_48 ( V_77 ) ) {
F_31 ( V_21 ) ;
V_47 = - V_79 ;
goto V_42;
}
V_75 = F_49 ( V_21 -> V_35 , V_95 , V_1 -> V_96 ,
& V_97 , V_21 ) ;
if ( V_75 == NULL ) {
F_31 ( V_21 ) ;
V_47 = - V_91 ;
goto V_42;
}
F_50 ( V_75 , V_76 , V_77 ) ;
#endif
F_28 ( & V_59 ) ;
F_18 ( & V_21 -> V_22 , & V_1 -> V_98 ) ;
F_30 ( & V_59 ) ;
V_47 = 0 ;
V_42:
F_51 ( & V_87 ) ;
return V_47 ;
}
static int F_52 ( const struct V_73 * V_40 )
{
const struct V_99 * V_100 = V_40 -> V_45 ;
struct V_43 V_101 ;
memcpy ( & V_101 , V_100 , sizeof( struct V_102 ) ) ;
memset ( V_101 . V_60 . V_103 , 0xFF , sizeof( V_101 . V_60 . V_103 ) ) ;
return F_33 ( V_40 , & V_101 ) ;
}
static int F_53 ( const struct V_73 * V_40 )
{
return F_33 ( V_40 , V_40 -> V_45 ) ;
}
static void F_54 ( const struct V_104 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
const struct V_43 * V_44 = V_40 -> V_45 ;
struct V_13 * V_21 ;
F_41 ( & V_87 ) ;
V_21 = F_21 ( V_1 , V_44 -> V_35 ) ;
if ( -- V_21 -> V_88 == 0 ) {
F_28 ( & V_59 ) ;
F_11 ( & V_21 -> V_22 ) ;
F_30 ( & V_59 ) ;
#ifdef F_34
if ( V_1 -> V_96 != NULL )
F_55 ( V_21 -> V_35 , V_1 -> V_96 ) ;
#endif
F_22 ( V_21 ) ;
F_31 ( V_21 ) ;
}
F_51 ( & V_87 ) ;
}
static void * F_56 ( struct V_105 * V_106 , T_6 * V_107 )
__acquires( V_59 )
{
struct V_108 * V_109 = V_106 -> V_110 ;
const struct V_13 * V_21 = V_109 -> V_14 ;
struct V_12 * V_18 ;
T_6 V_111 = * V_107 ;
F_28 ( & V_59 ) ;
for ( V_109 -> V_112 = 0 ; V_109 -> V_112 < V_10 ; V_109 -> V_112 ++ )
F_9 (e, &t->iphash[st->bucket], list)
if ( V_111 -- == 0 )
return V_18 ;
return NULL ;
}
static void * F_57 ( struct V_105 * V_106 , void * V_113 , T_6 * V_107 )
{
struct V_108 * V_109 = V_106 -> V_110 ;
const struct V_13 * V_21 = V_109 -> V_14 ;
const struct V_12 * V_18 = V_113 ;
const struct V_114 * V_115 = V_18 -> V_22 . V_25 ;
while ( V_115 == & V_21 -> V_34 [ V_109 -> V_112 ] ) {
if ( ++ V_109 -> V_112 >= V_10 )
return NULL ;
V_115 = V_21 -> V_34 [ V_109 -> V_112 ] . V_25 ;
}
( * V_107 ) ++ ;
return F_14 ( V_115 , struct V_12 , V_22 ) ;
}
static void F_58 ( struct V_105 * V_116 , void * V_113 )
__releases( V_59 )
{
F_30 ( & V_59 ) ;
}
static int F_59 ( struct V_105 * V_106 , void * V_113 )
{
const struct V_12 * V_18 = V_113 ;
struct V_108 * V_109 = V_106 -> V_110 ;
const struct V_13 * V_21 = V_109 -> V_14 ;
unsigned int V_36 ;
V_36 = ( V_18 -> V_27 - 1 ) & V_21 -> V_29 ;
if ( V_18 -> V_16 == V_20 )
F_60 ( V_106 , L_3 ,
& V_18 -> V_5 . V_8 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
else
F_60 ( V_106 , L_4 ,
& V_18 -> V_5 . V_56 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
for ( V_36 = 0 ; V_36 < V_18 -> V_33 ; V_36 ++ )
F_60 ( V_106 , L_5 , V_36 ? L_6 : L_7 , V_18 -> V_26 [ V_36 ] ) ;
F_60 ( V_106 , L_8 ) ;
return 0 ;
}
static int F_61 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
struct V_108 * V_109 ;
V_109 = F_62 ( V_118 , & V_119 , sizeof( * V_109 ) ) ;
if ( V_109 == NULL )
return - V_91 ;
V_109 -> V_14 = F_63 ( V_117 ) ;
return 0 ;
}
static T_7
F_64 ( struct V_118 * V_118 , const char T_8 * V_120 ,
T_5 V_121 , T_6 * V_122 )
{
struct V_13 * V_21 = F_63 ( F_65 ( V_118 ) ) ;
struct V_12 * V_18 ;
char V_123 [ sizeof( L_9 ) ] ;
const char * V_124 = V_123 ;
union V_4 V_5 = {} ;
T_1 V_16 ;
bool V_125 , V_126 ;
if ( V_121 == 0 )
return 0 ;
if ( V_121 > sizeof( V_123 ) )
V_121 = sizeof( V_123 ) ;
if ( F_66 ( V_123 , V_120 , V_121 ) != 0 )
return - V_127 ;
if ( * V_122 != 0 )
return - V_128 ;
switch ( * V_124 ) {
case '/' :
F_28 ( & V_59 ) ;
F_22 ( V_21 ) ;
F_30 ( & V_59 ) ;
return V_121 ;
case '-' :
V_125 = false ;
break;
case '+' :
V_125 = true ;
break;
default:
F_37 ( L_10 ) ;
return - V_79 ;
}
++ V_124 ;
-- V_121 ;
if ( F_67 ( V_124 , V_121 , ':' ) != NULL ) {
V_16 = V_129 ;
V_126 = F_68 ( V_124 , V_121 , ( void * ) & V_5 , '\n' , NULL ) ;
} else {
V_16 = V_20 ;
V_126 = F_69 ( V_124 , V_121 , ( void * ) & V_5 , '\n' , NULL ) ;
}
if ( ! V_126 ) {
F_37 ( L_11 ) ;
return - V_79 ;
}
F_28 ( & V_59 ) ;
V_18 = F_8 ( V_21 , & V_5 , V_16 , 0 ) ;
if ( V_18 == NULL ) {
if ( V_125 )
F_16 ( V_21 , & V_5 , V_16 , 0 ) ;
} else {
if ( V_125 )
F_19 ( V_21 , V_18 ) ;
else
F_10 ( V_21 , V_18 ) ;
}
F_30 ( & V_59 ) ;
* V_122 += V_121 + 1 ;
return V_121 + 1 ;
}
static int T_9 F_70 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_96 = F_71 ( L_12 , V_2 -> V_130 ) ;
if ( ! V_1 -> V_96 )
return - V_91 ;
return 0 ;
}
static void T_10 F_72 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_13 * V_21 ;
F_28 ( & V_59 ) ;
F_9 (t, &recent_net->tables, list)
F_55 ( V_21 -> V_35 , V_1 -> V_96 ) ;
V_1 -> V_96 = NULL ;
F_30 ( & V_59 ) ;
F_55 ( L_12 , V_2 -> V_130 ) ;
}
static inline int F_70 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_72 ( struct V_2 * V_2 )
{
}
static int T_9 F_73 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_44 ( & V_1 -> V_98 ) ;
return F_70 ( V_2 ) ;
}
static void T_10 F_74 ( struct V_2 * V_2 )
{
F_72 ( V_2 ) ;
}
static int T_11 F_75 ( void )
{
int V_131 ;
F_76 ( V_84 ) ;
if ( ! V_30 || V_86 >= V_84 )
return - V_79 ;
V_10 = 1 << F_77 ( V_30 ) ;
V_131 = F_78 ( & V_132 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_79 ( V_133 , F_7 ( V_133 ) ) ;
if ( V_131 )
F_80 ( & V_132 ) ;
return V_131 ;
}
static void T_12 F_81 ( void )
{
F_82 ( V_133 , F_7 ( V_133 ) ) ;
F_80 ( & V_132 ) ;
}
