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
if ( V_21 -> V_24 >= V_28 ) {
V_18 = F_14 ( V_21 -> V_23 . V_25 , struct V_12 , V_23 ) ;
F_10 ( V_21 , V_18 ) ;
}
V_18 = F_17 ( sizeof( * V_18 ) + sizeof( V_18 -> V_26 [ 0 ] ) * V_29 ,
V_30 ) ;
if ( V_18 == NULL )
return NULL ;
memcpy ( & V_18 -> V_5 , V_5 , sizeof( V_18 -> V_5 ) ) ;
V_18 -> V_17 = V_17 ;
V_18 -> V_26 [ 0 ] = V_31 ;
V_18 -> V_32 = 1 ;
V_18 -> V_27 = 1 ;
V_18 -> V_16 = V_16 ;
if ( V_16 == V_20 )
F_18 ( & V_18 -> V_22 , & V_21 -> V_33 [ F_3 ( V_5 ) ] ) ;
else
F_18 ( & V_18 -> V_22 , & V_21 -> V_33 [ F_5 ( V_5 ) ] ) ;
F_18 ( & V_18 -> V_23 , & V_21 -> V_23 ) ;
V_21 -> V_24 ++ ;
return V_18 ;
}
static void F_19 ( struct V_13 * V_21 , struct V_12 * V_18 )
{
V_18 -> V_27 %= V_29 ;
V_18 -> V_26 [ V_18 -> V_27 ++ ] = V_31 ;
if ( V_18 -> V_27 > V_18 -> V_32 )
V_18 -> V_32 = V_18 -> V_27 ;
F_20 ( & V_18 -> V_23 , & V_21 -> V_23 ) ;
}
static struct V_13 * F_21 ( struct V_1 * V_1 ,
const char * V_34 )
{
struct V_13 * V_21 ;
F_9 (t, &recent_net->tables, list)
if ( ! strcmp ( V_21 -> V_34 , V_34 ) )
return V_21 ;
return NULL ;
}
static void F_22 ( struct V_13 * V_21 )
{
struct V_12 * V_18 , * V_25 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_10 ; V_35 ++ )
F_23 (e, next, &t->iphash[i], list)
F_10 ( V_21 , V_18 ) ;
}
static bool
F_24 ( const struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_2 * V_2 = F_25 ( V_39 -> V_40 ? V_39 -> V_40 : V_39 -> V_41 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
const struct V_42 * V_43 = V_39 -> V_44 ;
struct V_13 * V_21 ;
struct V_12 * V_18 ;
union V_4 V_5 = {} ;
T_2 V_17 ;
bool V_45 = V_43 -> V_46 ;
if ( V_39 -> V_16 == V_20 ) {
const struct V_47 * V_48 = F_26 ( V_37 ) ;
if ( V_43 -> V_49 == V_50 )
V_5 . V_8 = V_48 -> V_51 ;
else
V_5 . V_8 = V_48 -> V_52 ;
V_17 = V_48 -> V_17 ;
} else {
const struct V_53 * V_48 = F_27 ( V_37 ) ;
if ( V_43 -> V_49 == V_50 )
memcpy ( & V_5 . V_54 , & V_48 -> V_51 , sizeof( V_5 . V_54 ) ) ;
else
memcpy ( & V_5 . V_54 , & V_48 -> V_52 , sizeof( V_5 . V_54 ) ) ;
V_17 = V_48 -> V_55 ;
}
if ( V_39 -> V_41 != NULL && V_37 -> V_56 == NULL )
V_17 ++ ;
F_28 ( & V_57 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
V_18 = F_8 ( V_21 , & V_5 , V_39 -> V_16 ,
( V_43 -> V_58 & V_59 ) ? V_17 : 0 ) ;
if ( V_18 == NULL ) {
if ( ! ( V_43 -> V_58 & V_60 ) )
goto V_41;
V_18 = F_16 ( V_21 , & V_5 , V_39 -> V_16 , V_17 ) ;
if ( V_18 == NULL )
V_39 -> V_61 = true ;
V_45 = ! V_45 ;
goto V_41;
}
if ( V_43 -> V_58 & V_60 )
V_45 = ! V_45 ;
else if ( V_43 -> V_58 & V_62 ) {
F_10 ( V_21 , V_18 ) ;
V_45 = ! V_45 ;
} else if ( V_43 -> V_58 & ( V_63 | V_64 ) ) {
unsigned long time = V_31 - V_43 -> V_65 * V_66 ;
unsigned int V_35 , V_67 = 0 ;
for ( V_35 = 0 ; V_35 < V_18 -> V_32 ; V_35 ++ ) {
if ( V_43 -> V_65 && F_15 ( time , V_18 -> V_26 [ V_35 ] ) )
continue;
if ( ! V_43 -> V_68 || ++ V_67 >= V_43 -> V_68 ) {
V_45 = ! V_45 ;
break;
}
}
if ( V_43 -> V_58 & V_69 )
F_13 ( V_21 , time ) ;
}
if ( V_43 -> V_58 & V_60 ||
( V_43 -> V_58 & V_64 && V_45 ) ) {
F_19 ( V_21 , V_18 ) ;
V_18 -> V_17 = V_17 ;
}
V_41:
F_29 ( & V_57 ) ;
return V_45 ;
}
static int F_30 ( const struct V_70 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_39 -> V_2 ) ;
const struct V_42 * V_43 = V_39 -> V_44 ;
struct V_13 * V_21 ;
#ifdef F_31
struct V_71 * V_72 ;
#endif
unsigned int V_35 ;
int V_45 = - V_73 ;
if ( F_32 ( ! V_74 ) ) {
F_33 ( & V_9 , sizeof( V_9 ) ) ;
V_74 = true ;
}
if ( V_43 -> V_58 & ~ V_75 ) {
F_34 ( L_1 ,
V_43 -> V_58 ) ;
return - V_73 ;
}
if ( F_35 ( V_43 -> V_58 &
( V_60 | V_62 |
V_63 | V_64 ) ) != 1 )
return - V_73 ;
if ( ( V_43 -> V_58 & ( V_60 | V_62 ) ) &&
( V_43 -> V_65 || V_43 -> V_68 ||
( V_43 -> V_58 & V_76 ) ) )
return - V_73 ;
if ( ( V_43 -> V_58 & V_69 ) && ! V_43 -> V_65 )
return - V_73 ;
if ( V_43 -> V_68 > V_29 ) {
F_34 ( L_2
L_3 ,
V_43 -> V_68 , V_29 ) ;
return - V_73 ;
}
if ( V_43 -> V_34 [ 0 ] == '\0' ||
F_36 ( V_43 -> V_34 , V_77 ) == V_77 )
return - V_73 ;
F_37 ( & V_78 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
if ( V_21 != NULL ) {
V_21 -> V_79 ++ ;
V_45 = 0 ;
goto V_41;
}
V_21 = F_38 ( sizeof( * V_21 ) + sizeof( V_21 -> V_33 [ 0 ] ) * V_10 ,
V_80 ) ;
if ( V_21 == NULL ) {
V_45 = - V_81 ;
goto V_41;
}
V_21 -> V_79 = 1 ;
strcpy ( V_21 -> V_34 , V_43 -> V_34 ) ;
F_39 ( & V_21 -> V_23 ) ;
for ( V_35 = 0 ; V_35 < V_10 ; V_35 ++ )
F_39 ( & V_21 -> V_33 [ V_35 ] ) ;
#ifdef F_31
V_72 = F_40 ( V_21 -> V_34 , V_82 , V_1 -> V_83 ,
& V_84 , V_21 ) ;
if ( V_72 == NULL ) {
F_12 ( V_21 ) ;
V_45 = - V_81 ;
goto V_41;
}
V_72 -> V_85 = V_86 ;
V_72 -> V_87 = V_88 ;
#endif
F_28 ( & V_57 ) ;
F_18 ( & V_21 -> V_22 , & V_1 -> V_89 ) ;
F_29 ( & V_57 ) ;
V_45 = 0 ;
V_41:
F_41 ( & V_78 ) ;
return V_45 ;
}
static void F_42 ( const struct V_90 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_39 -> V_2 ) ;
const struct V_42 * V_43 = V_39 -> V_44 ;
struct V_13 * V_21 ;
F_37 ( & V_78 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
if ( -- V_21 -> V_79 == 0 ) {
F_28 ( & V_57 ) ;
F_11 ( & V_21 -> V_22 ) ;
F_29 ( & V_57 ) ;
#ifdef F_31
F_43 ( V_21 -> V_34 , V_1 -> V_83 ) ;
#endif
F_22 ( V_21 ) ;
F_12 ( V_21 ) ;
}
F_41 ( & V_78 ) ;
}
static void * F_44 ( struct V_91 * V_92 , T_3 * V_93 )
__acquires( V_57 )
{
struct V_94 * V_95 = V_92 -> V_96 ;
const struct V_13 * V_21 = V_95 -> V_14 ;
struct V_12 * V_18 ;
T_3 V_97 = * V_93 ;
F_28 ( & V_57 ) ;
for ( V_95 -> V_98 = 0 ; V_95 -> V_98 < V_10 ; V_95 -> V_98 ++ )
F_9 (e, &t->iphash[st->bucket], list)
if ( V_97 -- == 0 )
return V_18 ;
return NULL ;
}
static void * F_45 ( struct V_91 * V_92 , void * V_99 , T_3 * V_93 )
{
struct V_94 * V_95 = V_92 -> V_96 ;
const struct V_13 * V_21 = V_95 -> V_14 ;
const struct V_12 * V_18 = V_99 ;
const struct V_100 * V_101 = V_18 -> V_22 . V_25 ;
while ( V_101 == & V_21 -> V_33 [ V_95 -> V_98 ] ) {
if ( ++ V_95 -> V_98 >= V_10 )
return NULL ;
V_101 = V_21 -> V_33 [ V_95 -> V_98 ] . V_25 ;
}
( * V_93 ) ++ ;
return F_14 ( V_101 , struct V_12 , V_22 ) ;
}
static void F_46 ( struct V_91 * V_102 , void * V_99 )
__releases( V_57 )
{
F_29 ( & V_57 ) ;
}
static int F_47 ( struct V_91 * V_92 , void * V_99 )
{
const struct V_12 * V_18 = V_99 ;
unsigned int V_35 ;
V_35 = ( V_18 -> V_27 - 1 ) % V_29 ;
if ( V_18 -> V_16 == V_20 )
F_48 ( V_92 , L_4 ,
& V_18 -> V_5 . V_8 , V_18 -> V_17 , V_18 -> V_26 [ V_35 ] , V_18 -> V_27 ) ;
else
F_48 ( V_92 , L_5 ,
& V_18 -> V_5 . V_54 , V_18 -> V_17 , V_18 -> V_26 [ V_35 ] , V_18 -> V_27 ) ;
for ( V_35 = 0 ; V_35 < V_18 -> V_32 ; V_35 ++ )
F_48 ( V_92 , L_6 , V_35 ? L_7 : L_8 , V_18 -> V_26 [ V_35 ] ) ;
F_48 ( V_92 , L_9 ) ;
return 0 ;
}
static int F_49 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
struct V_71 * V_72 = F_50 ( V_103 ) ;
struct V_94 * V_95 ;
V_95 = F_51 ( V_104 , & V_105 , sizeof( * V_95 ) ) ;
if ( V_95 == NULL )
return - V_81 ;
V_95 -> V_14 = V_72 -> V_106 ;
return 0 ;
}
static T_4
F_52 ( struct V_104 * V_104 , const char T_5 * V_107 ,
T_6 V_108 , T_3 * V_109 )
{
const struct V_71 * V_72 = F_50 ( V_104 -> V_110 . V_111 -> V_112 ) ;
struct V_13 * V_21 = V_72 -> V_106 ;
struct V_12 * V_18 ;
char V_113 [ sizeof( L_10 ) ] ;
const char * V_114 = V_113 ;
union V_4 V_5 = {} ;
T_1 V_16 ;
bool V_115 , V_116 ;
if ( V_108 == 0 )
return 0 ;
if ( V_108 > sizeof( V_113 ) )
V_108 = sizeof( V_113 ) ;
if ( F_53 ( V_113 , V_107 , V_108 ) != 0 )
return - V_117 ;
if ( * V_109 != 0 )
return - V_118 ;
switch ( * V_114 ) {
case '/' :
F_28 ( & V_57 ) ;
F_22 ( V_21 ) ;
F_29 ( & V_57 ) ;
return V_108 ;
case '-' :
V_115 = false ;
break;
case '+' :
V_115 = true ;
break;
default:
F_34 ( L_11 ) ;
return - V_73 ;
}
++ V_114 ;
-- V_108 ;
if ( F_54 ( V_114 , V_108 , ':' ) != NULL ) {
V_16 = V_119 ;
V_116 = F_55 ( V_114 , V_108 , ( void * ) & V_5 , '\n' , NULL ) ;
} else {
V_16 = V_20 ;
V_116 = F_56 ( V_114 , V_108 , ( void * ) & V_5 , '\n' , NULL ) ;
}
if ( ! V_116 ) {
F_34 ( L_12 ) ;
return - V_73 ;
}
F_28 ( & V_57 ) ;
V_18 = F_8 ( V_21 , & V_5 , V_16 , 0 ) ;
if ( V_18 == NULL ) {
if ( V_115 )
F_16 ( V_21 , & V_5 , V_16 , 0 ) ;
} else {
if ( V_115 )
F_19 ( V_21 , V_18 ) ;
else
F_10 ( V_21 , V_18 ) ;
}
F_29 ( & V_57 ) ;
* V_109 += V_108 + 1 ;
return V_108 + 1 ;
}
static int T_7 F_57 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_83 = F_58 ( L_13 , V_2 -> V_120 ) ;
if ( ! V_1 -> V_83 )
return - V_81 ;
return 0 ;
}
static void T_8 F_59 ( struct V_2 * V_2 )
{
F_60 ( V_2 , L_13 ) ;
}
static inline int F_57 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_59 ( struct V_2 * V_2 )
{
}
static int T_7 F_61 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_39 ( & V_1 -> V_89 ) ;
return F_57 ( V_2 ) ;
}
static void T_8 F_62 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_63 ( ! F_64 ( & V_1 -> V_89 ) ) ;
F_59 ( V_2 ) ;
}
static int T_9 F_65 ( void )
{
int V_121 ;
if ( ! V_28 || ! V_29 || V_29 > 255 )
return - V_73 ;
V_10 = 1 << F_66 ( V_28 ) ;
V_121 = F_67 ( & V_122 ) ;
if ( V_121 )
return V_121 ;
V_121 = F_68 ( V_123 , F_7 ( V_123 ) ) ;
if ( V_121 )
F_69 ( & V_122 ) ;
return V_121 ;
}
static void T_10 F_70 ( void )
{
F_71 ( V_123 , F_7 ( V_123 ) ) ;
F_69 ( & V_122 ) ;
}
