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
struct V_2 * V_2 = V_40 -> V_2 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
const struct V_41 * V_42 = V_40 -> V_43 ;
struct V_13 * V_21 ;
struct V_12 * V_18 ;
union V_4 V_5 = {} , V_44 ;
T_2 V_17 ;
bool V_45 = V_42 -> V_46 ;
if ( V_40 -> V_16 == V_20 ) {
const struct V_47 * V_48 = F_25 ( V_38 ) ;
if ( V_42 -> V_49 == V_50 )
V_5 . V_8 = V_48 -> V_51 ;
else
V_5 . V_8 = V_48 -> V_52 ;
V_17 = V_48 -> V_17 ;
} else {
const struct V_53 * V_48 = F_26 ( V_38 ) ;
if ( V_42 -> V_49 == V_50 )
memcpy ( & V_5 . V_54 , & V_48 -> V_51 , sizeof( V_5 . V_54 ) ) ;
else
memcpy ( & V_5 . V_54 , & V_48 -> V_52 , sizeof( V_5 . V_54 ) ) ;
V_17 = V_48 -> V_55 ;
}
if ( V_40 -> V_56 != NULL && V_38 -> V_57 == NULL )
V_17 ++ ;
F_27 ( & V_58 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
F_28 ( & V_5 , & V_44 , & V_21 -> V_59 ) ;
V_18 = F_8 ( V_21 , & V_44 , V_40 -> V_16 ,
( V_42 -> V_60 & V_61 ) ? V_17 : 0 ) ;
if ( V_18 == NULL ) {
if ( ! ( V_42 -> V_60 & V_62 ) )
goto V_56;
V_18 = F_16 ( V_21 , & V_44 , V_40 -> V_16 , V_17 ) ;
if ( V_18 == NULL )
V_40 -> V_63 = true ;
V_45 = ! V_45 ;
goto V_56;
}
if ( V_42 -> V_60 & V_62 )
V_45 = ! V_45 ;
else if ( V_42 -> V_60 & V_64 ) {
F_10 ( V_21 , V_18 ) ;
V_45 = ! V_45 ;
} else if ( V_42 -> V_60 & ( V_65 | V_66 ) ) {
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
if ( V_42 -> V_60 & V_71 )
F_13 ( V_21 , time ) ;
}
if ( V_42 -> V_60 & V_62 ||
( V_42 -> V_60 & V_66 && V_45 ) ) {
F_19 ( V_21 , V_18 ) ;
V_18 -> V_17 = V_17 ;
}
V_56:
F_29 ( & V_58 ) ;
return V_45 ;
}
static void F_30 ( void * V_5 )
{
F_31 ( V_5 ) ;
}
static int F_32 ( const struct V_72 * V_40 ,
const struct V_41 * V_42 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
struct V_13 * V_21 ;
#ifdef F_33
struct V_73 * V_74 ;
T_3 V_75 ;
T_4 V_76 ;
#endif
unsigned int V_77 ;
unsigned int V_36 ;
int V_45 = - V_78 ;
T_5 V_79 ;
F_34 ( & V_9 , sizeof( V_9 ) ) ;
if ( V_42 -> V_60 & ~ V_80 ) {
F_35 ( L_1 ,
V_42 -> V_60 ) ;
return - V_78 ;
}
if ( F_36 ( V_42 -> V_60 &
( V_62 | V_64 |
V_65 | V_66 ) ) != 1 )
return - V_78 ;
if ( ( V_42 -> V_60 & ( V_62 | V_64 ) ) &&
( V_42 -> V_67 || V_42 -> V_70 ||
( V_42 -> V_60 & V_81 ) ) )
return - V_78 ;
if ( ( V_42 -> V_60 & V_71 ) && ! V_42 -> V_67 )
return - V_78 ;
if ( V_42 -> V_70 >= V_82 ) {
F_35 ( L_2 ,
V_42 -> V_70 , V_82 - 1 ) ;
return - V_78 ;
}
if ( V_42 -> V_35 [ 0 ] == '\0' ||
F_37 ( V_42 -> V_35 , V_83 ) == V_83 )
return - V_78 ;
if ( V_84 && V_42 -> V_70 < V_84 )
V_77 = F_38 ( V_84 ) - 1 ;
else if ( V_42 -> V_70 )
V_77 = F_38 ( V_42 -> V_70 ) - 1 ;
else
V_77 = 32 - 1 ;
F_39 ( & V_85 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
if ( V_21 != NULL ) {
if ( V_77 > V_21 -> V_29 ) {
F_27 ( & V_58 ) ;
F_22 ( V_21 ) ;
V_21 -> V_29 = V_77 ;
F_29 ( & V_58 ) ;
}
V_21 -> V_86 ++ ;
V_45 = 0 ;
goto V_56;
}
V_79 = sizeof( * V_21 ) + sizeof( V_21 -> V_34 [ 0 ] ) * V_10 ;
if ( V_79 <= V_87 )
V_21 = F_40 ( V_79 , V_88 ) ;
else
V_21 = F_41 ( V_79 ) ;
if ( V_21 == NULL ) {
V_45 = - V_89 ;
goto V_56;
}
V_21 -> V_86 = 1 ;
V_21 -> V_29 = V_77 ;
memcpy ( & V_21 -> V_59 , & V_42 -> V_59 , sizeof( V_21 -> V_59 ) ) ;
strcpy ( V_21 -> V_35 , V_42 -> V_35 ) ;
F_42 ( & V_21 -> V_23 ) ;
for ( V_36 = 0 ; V_36 < V_10 ; V_36 ++ )
F_42 ( & V_21 -> V_34 [ V_36 ] ) ;
#ifdef F_33
V_75 = F_43 ( & V_90 , V_91 ) ;
V_76 = F_44 ( & V_90 , V_92 ) ;
if ( ! F_45 ( V_75 ) || ! F_46 ( V_76 ) ) {
F_30 ( V_21 ) ;
V_45 = - V_78 ;
goto V_56;
}
V_74 = F_47 ( V_21 -> V_35 , V_93 , V_1 -> V_94 ,
& V_95 , V_21 ) ;
if ( V_74 == NULL ) {
F_30 ( V_21 ) ;
V_45 = - V_89 ;
goto V_56;
}
F_48 ( V_74 , V_75 , V_76 ) ;
#endif
F_27 ( & V_58 ) ;
F_18 ( & V_21 -> V_22 , & V_1 -> V_96 ) ;
F_29 ( & V_58 ) ;
V_45 = 0 ;
V_56:
F_49 ( & V_85 ) ;
return V_45 ;
}
static int F_50 ( const struct V_72 * V_40 )
{
const struct V_97 * V_98 = V_40 -> V_43 ;
struct V_41 V_99 ;
memcpy ( & V_99 , V_98 , sizeof( struct V_100 ) ) ;
memset ( V_99 . V_59 . V_101 , 0xFF , sizeof( V_99 . V_59 . V_101 ) ) ;
return F_32 ( V_40 , & V_99 ) ;
}
static int F_51 ( const struct V_72 * V_40 )
{
return F_32 ( V_40 , V_40 -> V_43 ) ;
}
static void F_52 ( const struct V_102 * V_40 )
{
struct V_1 * V_1 = F_1 ( V_40 -> V_2 ) ;
const struct V_41 * V_42 = V_40 -> V_43 ;
struct V_13 * V_21 ;
F_39 ( & V_85 ) ;
V_21 = F_21 ( V_1 , V_42 -> V_35 ) ;
if ( -- V_21 -> V_86 == 0 ) {
F_27 ( & V_58 ) ;
F_11 ( & V_21 -> V_22 ) ;
F_29 ( & V_58 ) ;
#ifdef F_33
if ( V_1 -> V_94 != NULL )
F_53 ( V_21 -> V_35 , V_1 -> V_94 ) ;
#endif
F_22 ( V_21 ) ;
F_30 ( V_21 ) ;
}
F_49 ( & V_85 ) ;
}
static void * F_54 ( struct V_103 * V_104 , T_6 * V_105 )
__acquires( V_58 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
const struct V_13 * V_21 = V_107 -> V_14 ;
struct V_12 * V_18 ;
T_6 V_109 = * V_105 ;
F_27 ( & V_58 ) ;
for ( V_107 -> V_110 = 0 ; V_107 -> V_110 < V_10 ; V_107 -> V_110 ++ )
F_9 (e, &t->iphash[st->bucket], list)
if ( V_109 -- == 0 )
return V_18 ;
return NULL ;
}
static void * F_55 ( struct V_103 * V_104 , void * V_111 , T_6 * V_105 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
const struct V_13 * V_21 = V_107 -> V_14 ;
const struct V_12 * V_18 = V_111 ;
const struct V_112 * V_113 = V_18 -> V_22 . V_25 ;
while ( V_113 == & V_21 -> V_34 [ V_107 -> V_110 ] ) {
if ( ++ V_107 -> V_110 >= V_10 )
return NULL ;
V_113 = V_21 -> V_34 [ V_107 -> V_110 ] . V_25 ;
}
( * V_105 ) ++ ;
return F_14 ( V_113 , struct V_12 , V_22 ) ;
}
static void F_56 ( struct V_103 * V_114 , void * V_111 )
__releases( V_58 )
{
F_29 ( & V_58 ) ;
}
static int F_57 ( struct V_103 * V_104 , void * V_111 )
{
const struct V_12 * V_18 = V_111 ;
struct V_106 * V_107 = V_104 -> V_108 ;
const struct V_13 * V_21 = V_107 -> V_14 ;
unsigned int V_36 ;
V_36 = ( V_18 -> V_27 - 1 ) & V_21 -> V_29 ;
if ( V_18 -> V_16 == V_20 )
F_58 ( V_104 , L_3 ,
& V_18 -> V_5 . V_8 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
else
F_58 ( V_104 , L_4 ,
& V_18 -> V_5 . V_54 , V_18 -> V_17 , V_18 -> V_26 [ V_36 ] , V_18 -> V_27 ) ;
for ( V_36 = 0 ; V_36 < V_18 -> V_33 ; V_36 ++ )
F_58 ( V_104 , L_5 , V_36 ? L_6 : L_7 , V_18 -> V_26 [ V_36 ] ) ;
F_58 ( V_104 , L_8 ) ;
return 0 ;
}
static int F_59 ( struct V_115 * V_115 , struct V_116 * V_116 )
{
struct V_106 * V_107 ;
V_107 = F_60 ( V_116 , & V_117 , sizeof( * V_107 ) ) ;
if ( V_107 == NULL )
return - V_89 ;
V_107 -> V_14 = F_61 ( V_115 ) ;
return 0 ;
}
static T_7
F_62 ( struct V_116 * V_116 , const char T_8 * V_118 ,
T_5 V_119 , T_6 * V_120 )
{
struct V_13 * V_21 = F_61 ( F_63 ( V_116 ) ) ;
struct V_12 * V_18 ;
char V_121 [ sizeof( L_9 ) ] ;
const char * V_122 = V_121 ;
union V_4 V_5 = {} ;
T_1 V_16 ;
bool V_123 , V_124 ;
if ( V_119 == 0 )
return 0 ;
if ( V_119 > sizeof( V_121 ) )
V_119 = sizeof( V_121 ) ;
if ( F_64 ( V_121 , V_118 , V_119 ) != 0 )
return - V_125 ;
if ( * V_120 != 0 )
return - V_126 ;
switch ( * V_122 ) {
case '/' :
F_27 ( & V_58 ) ;
F_22 ( V_21 ) ;
F_29 ( & V_58 ) ;
return V_119 ;
case '-' :
V_123 = false ;
break;
case '+' :
V_123 = true ;
break;
default:
F_35 ( L_10 ) ;
return - V_78 ;
}
++ V_122 ;
-- V_119 ;
if ( F_65 ( V_122 , V_119 , ':' ) != NULL ) {
V_16 = V_127 ;
V_124 = F_66 ( V_122 , V_119 , ( void * ) & V_5 , '\n' , NULL ) ;
} else {
V_16 = V_20 ;
V_124 = F_67 ( V_122 , V_119 , ( void * ) & V_5 , '\n' , NULL ) ;
}
if ( ! V_124 ) {
F_35 ( L_11 ) ;
return - V_78 ;
}
F_27 ( & V_58 ) ;
V_18 = F_8 ( V_21 , & V_5 , V_16 , 0 ) ;
if ( V_18 == NULL ) {
if ( V_123 )
F_16 ( V_21 , & V_5 , V_16 , 0 ) ;
} else {
if ( V_123 )
F_19 ( V_21 , V_18 ) ;
else
F_10 ( V_21 , V_18 ) ;
}
F_29 ( & V_58 ) ;
* V_120 += V_119 + 1 ;
return V_119 + 1 ;
}
static int T_9 F_68 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_94 = F_69 ( L_12 , V_2 -> V_128 ) ;
if ( ! V_1 -> V_94 )
return - V_89 ;
return 0 ;
}
static void T_10 F_70 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_13 * V_21 ;
F_27 ( & V_58 ) ;
F_9 (t, &recent_net->tables, list)
F_53 ( V_21 -> V_35 , V_1 -> V_94 ) ;
V_1 -> V_94 = NULL ;
F_29 ( & V_58 ) ;
F_53 ( L_12 , V_2 -> V_128 ) ;
}
static inline int F_68 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_70 ( struct V_2 * V_2 )
{
}
static int T_9 F_71 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_42 ( & V_1 -> V_96 ) ;
return F_68 ( V_2 ) ;
}
static void T_10 F_72 ( struct V_2 * V_2 )
{
F_70 ( V_2 ) ;
}
static int T_11 F_73 ( void )
{
int V_129 ;
F_74 ( V_82 ) ;
if ( ! V_30 || V_84 >= V_82 )
return - V_78 ;
V_10 = 1 << F_75 ( V_30 ) ;
V_129 = F_76 ( & V_130 ) ;
if ( V_129 )
return V_129 ;
V_129 = F_77 ( V_131 , F_7 ( V_131 ) ) ;
if ( V_129 )
F_78 ( & V_130 ) ;
return V_129 ;
}
static void T_12 F_79 ( void )
{
F_80 ( V_131 , F_7 ( V_131 ) ) ;
F_78 ( & V_130 ) ;
}
