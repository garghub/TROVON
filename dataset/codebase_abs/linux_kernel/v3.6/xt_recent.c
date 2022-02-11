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
union V_4 V_5 = {} , V_45 ;
T_2 V_17 ;
bool V_46 = V_43 -> V_47 ;
if ( V_39 -> V_16 == V_20 ) {
const struct V_48 * V_49 = F_26 ( V_37 ) ;
if ( V_43 -> V_50 == V_51 )
V_5 . V_8 = V_49 -> V_52 ;
else
V_5 . V_8 = V_49 -> V_53 ;
V_17 = V_49 -> V_17 ;
} else {
const struct V_54 * V_49 = F_27 ( V_37 ) ;
if ( V_43 -> V_50 == V_51 )
memcpy ( & V_5 . V_55 , & V_49 -> V_52 , sizeof( V_5 . V_55 ) ) ;
else
memcpy ( & V_5 . V_55 , & V_49 -> V_53 , sizeof( V_5 . V_55 ) ) ;
V_17 = V_49 -> V_56 ;
}
if ( V_39 -> V_41 != NULL && V_37 -> V_57 == NULL )
V_17 ++ ;
F_28 ( & V_58 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
F_29 ( & V_5 , & V_45 , & V_21 -> V_59 ) ;
V_18 = F_8 ( V_21 , & V_45 , V_39 -> V_16 ,
( V_43 -> V_60 & V_61 ) ? V_17 : 0 ) ;
if ( V_18 == NULL ) {
if ( ! ( V_43 -> V_60 & V_62 ) )
goto V_41;
V_18 = F_16 ( V_21 , & V_45 , V_39 -> V_16 , V_17 ) ;
if ( V_18 == NULL )
V_39 -> V_63 = true ;
V_46 = ! V_46 ;
goto V_41;
}
if ( V_43 -> V_60 & V_62 )
V_46 = ! V_46 ;
else if ( V_43 -> V_60 & V_64 ) {
F_10 ( V_21 , V_18 ) ;
V_46 = ! V_46 ;
} else if ( V_43 -> V_60 & ( V_65 | V_66 ) ) {
unsigned long time = V_31 - V_43 -> V_67 * V_68 ;
unsigned int V_35 , V_69 = 0 ;
for ( V_35 = 0 ; V_35 < V_18 -> V_32 ; V_35 ++ ) {
if ( V_43 -> V_67 && F_15 ( time , V_18 -> V_26 [ V_35 ] ) )
continue;
if ( ! V_43 -> V_70 || ++ V_69 >= V_43 -> V_70 ) {
V_46 = ! V_46 ;
break;
}
}
if ( V_43 -> V_60 & V_71 )
F_13 ( V_21 , time ) ;
}
if ( V_43 -> V_60 & V_62 ||
( V_43 -> V_60 & V_66 && V_46 ) ) {
F_19 ( V_21 , V_18 ) ;
V_18 -> V_17 = V_17 ;
}
V_41:
F_30 ( & V_58 ) ;
return V_46 ;
}
static int F_31 ( const struct V_72 * V_39 ,
const struct V_42 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_39 -> V_2 ) ;
struct V_13 * V_21 ;
#ifdef F_32
struct V_73 * V_74 ;
#endif
unsigned int V_35 ;
int V_46 = - V_75 ;
if ( F_33 ( ! V_76 ) ) {
F_34 ( & V_9 , sizeof( V_9 ) ) ;
V_76 = true ;
}
if ( V_43 -> V_60 & ~ V_77 ) {
F_35 ( L_1 ,
V_43 -> V_60 ) ;
return - V_75 ;
}
if ( F_36 ( V_43 -> V_60 &
( V_62 | V_64 |
V_65 | V_66 ) ) != 1 )
return - V_75 ;
if ( ( V_43 -> V_60 & ( V_62 | V_64 ) ) &&
( V_43 -> V_67 || V_43 -> V_70 ||
( V_43 -> V_60 & V_78 ) ) )
return - V_75 ;
if ( ( V_43 -> V_60 & V_71 ) && ! V_43 -> V_67 )
return - V_75 ;
if ( V_43 -> V_70 > V_29 ) {
F_35 ( L_2
L_3 ,
V_43 -> V_70 , V_29 ) ;
return - V_75 ;
}
if ( V_43 -> V_34 [ 0 ] == '\0' ||
F_37 ( V_43 -> V_34 , V_79 ) == V_79 )
return - V_75 ;
F_38 ( & V_80 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
if ( V_21 != NULL ) {
V_21 -> V_81 ++ ;
V_46 = 0 ;
goto V_41;
}
V_21 = F_39 ( sizeof( * V_21 ) + sizeof( V_21 -> V_33 [ 0 ] ) * V_10 ,
V_82 ) ;
if ( V_21 == NULL ) {
V_46 = - V_83 ;
goto V_41;
}
V_21 -> V_81 = 1 ;
memcpy ( & V_21 -> V_59 , & V_43 -> V_59 , sizeof( V_21 -> V_59 ) ) ;
strcpy ( V_21 -> V_34 , V_43 -> V_34 ) ;
F_40 ( & V_21 -> V_23 ) ;
for ( V_35 = 0 ; V_35 < V_10 ; V_35 ++ )
F_40 ( & V_21 -> V_33 [ V_35 ] ) ;
#ifdef F_32
V_74 = F_41 ( V_21 -> V_34 , V_84 , V_1 -> V_85 ,
& V_86 , V_21 ) ;
if ( V_74 == NULL ) {
F_12 ( V_21 ) ;
V_46 = - V_83 ;
goto V_41;
}
V_74 -> V_87 = V_88 ;
V_74 -> V_89 = V_90 ;
#endif
F_28 ( & V_58 ) ;
F_18 ( & V_21 -> V_22 , & V_1 -> V_91 ) ;
F_30 ( & V_58 ) ;
V_46 = 0 ;
V_41:
F_42 ( & V_80 ) ;
return V_46 ;
}
static int F_43 ( const struct V_72 * V_39 )
{
const struct V_92 * V_93 = V_39 -> V_44 ;
struct V_42 V_94 ;
memcpy ( & V_94 , V_93 , sizeof( struct V_95 ) ) ;
memset ( V_94 . V_59 . V_96 , 0xFF , sizeof( V_94 . V_59 . V_96 ) ) ;
return F_31 ( V_39 , & V_94 ) ;
}
static int F_44 ( const struct V_72 * V_39 )
{
return F_31 ( V_39 , V_39 -> V_44 ) ;
}
static void F_45 ( const struct V_97 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_39 -> V_2 ) ;
const struct V_42 * V_43 = V_39 -> V_44 ;
struct V_13 * V_21 ;
F_38 ( & V_80 ) ;
V_21 = F_21 ( V_1 , V_43 -> V_34 ) ;
if ( -- V_21 -> V_81 == 0 ) {
F_28 ( & V_58 ) ;
F_11 ( & V_21 -> V_22 ) ;
F_30 ( & V_58 ) ;
#ifdef F_32
F_46 ( V_21 -> V_34 , V_1 -> V_85 ) ;
#endif
F_22 ( V_21 ) ;
F_12 ( V_21 ) ;
}
F_42 ( & V_80 ) ;
}
static void * F_47 ( struct V_98 * V_99 , T_3 * V_100 )
__acquires( V_58 )
{
struct V_101 * V_102 = V_99 -> V_103 ;
const struct V_13 * V_21 = V_102 -> V_14 ;
struct V_12 * V_18 ;
T_3 V_104 = * V_100 ;
F_28 ( & V_58 ) ;
for ( V_102 -> V_105 = 0 ; V_102 -> V_105 < V_10 ; V_102 -> V_105 ++ )
F_9 (e, &t->iphash[st->bucket], list)
if ( V_104 -- == 0 )
return V_18 ;
return NULL ;
}
static void * F_48 ( struct V_98 * V_99 , void * V_106 , T_3 * V_100 )
{
struct V_101 * V_102 = V_99 -> V_103 ;
const struct V_13 * V_21 = V_102 -> V_14 ;
const struct V_12 * V_18 = V_106 ;
const struct V_107 * V_108 = V_18 -> V_22 . V_25 ;
while ( V_108 == & V_21 -> V_33 [ V_102 -> V_105 ] ) {
if ( ++ V_102 -> V_105 >= V_10 )
return NULL ;
V_108 = V_21 -> V_33 [ V_102 -> V_105 ] . V_25 ;
}
( * V_100 ) ++ ;
return F_14 ( V_108 , struct V_12 , V_22 ) ;
}
static void F_49 ( struct V_98 * V_109 , void * V_106 )
__releases( V_58 )
{
F_30 ( & V_58 ) ;
}
static int F_50 ( struct V_98 * V_99 , void * V_106 )
{
const struct V_12 * V_18 = V_106 ;
unsigned int V_35 ;
V_35 = ( V_18 -> V_27 - 1 ) % V_29 ;
if ( V_18 -> V_16 == V_20 )
F_51 ( V_99 , L_4 ,
& V_18 -> V_5 . V_8 , V_18 -> V_17 , V_18 -> V_26 [ V_35 ] , V_18 -> V_27 ) ;
else
F_51 ( V_99 , L_5 ,
& V_18 -> V_5 . V_55 , V_18 -> V_17 , V_18 -> V_26 [ V_35 ] , V_18 -> V_27 ) ;
for ( V_35 = 0 ; V_35 < V_18 -> V_32 ; V_35 ++ )
F_51 ( V_99 , L_6 , V_35 ? L_7 : L_8 , V_18 -> V_26 [ V_35 ] ) ;
F_51 ( V_99 , L_9 ) ;
return 0 ;
}
static int F_52 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
struct V_73 * V_74 = F_53 ( V_110 ) ;
struct V_101 * V_102 ;
V_102 = F_54 ( V_111 , & V_112 , sizeof( * V_102 ) ) ;
if ( V_102 == NULL )
return - V_83 ;
V_102 -> V_14 = V_74 -> V_113 ;
return 0 ;
}
static T_4
F_55 ( struct V_111 * V_111 , const char T_5 * V_114 ,
T_6 V_115 , T_3 * V_116 )
{
const struct V_73 * V_74 = F_53 ( V_111 -> V_117 . V_118 -> V_119 ) ;
struct V_13 * V_21 = V_74 -> V_113 ;
struct V_12 * V_18 ;
char V_120 [ sizeof( L_10 ) ] ;
const char * V_121 = V_120 ;
union V_4 V_5 = {} ;
T_1 V_16 ;
bool V_122 , V_123 ;
if ( V_115 == 0 )
return 0 ;
if ( V_115 > sizeof( V_120 ) )
V_115 = sizeof( V_120 ) ;
if ( F_56 ( V_120 , V_114 , V_115 ) != 0 )
return - V_124 ;
if ( * V_116 != 0 )
return - V_125 ;
switch ( * V_121 ) {
case '/' :
F_28 ( & V_58 ) ;
F_22 ( V_21 ) ;
F_30 ( & V_58 ) ;
return V_115 ;
case '-' :
V_122 = false ;
break;
case '+' :
V_122 = true ;
break;
default:
F_35 ( L_11 ) ;
return - V_75 ;
}
++ V_121 ;
-- V_115 ;
if ( F_57 ( V_121 , V_115 , ':' ) != NULL ) {
V_16 = V_126 ;
V_123 = F_58 ( V_121 , V_115 , ( void * ) & V_5 , '\n' , NULL ) ;
} else {
V_16 = V_20 ;
V_123 = F_59 ( V_121 , V_115 , ( void * ) & V_5 , '\n' , NULL ) ;
}
if ( ! V_123 ) {
F_35 ( L_12 ) ;
return - V_75 ;
}
F_28 ( & V_58 ) ;
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
F_30 ( & V_58 ) ;
* V_116 += V_115 + 1 ;
return V_115 + 1 ;
}
static int T_7 F_60 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
V_1 -> V_85 = F_61 ( L_13 , V_2 -> V_127 ) ;
if ( ! V_1 -> V_85 )
return - V_83 ;
return 0 ;
}
static void T_8 F_62 ( struct V_2 * V_2 )
{
F_63 ( V_2 , L_13 ) ;
}
static inline int F_60 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_62 ( struct V_2 * V_2 )
{
}
static int T_7 F_64 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_40 ( & V_1 -> V_91 ) ;
return F_60 ( V_2 ) ;
}
static void T_8 F_65 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_66 ( ! F_67 ( & V_1 -> V_91 ) ) ;
F_62 ( V_2 ) ;
}
static int T_9 F_68 ( void )
{
int V_128 ;
if ( ! V_28 || ! V_29 || V_29 > 255 )
return - V_75 ;
V_10 = 1 << F_69 ( V_28 ) ;
V_128 = F_70 ( & V_129 ) ;
if ( V_128 )
return V_128 ;
V_128 = F_71 ( V_130 , F_7 ( V_130 ) ) ;
if ( V_128 )
F_72 ( & V_129 ) ;
return V_128 ;
}
static void T_10 F_73 ( void )
{
F_74 ( V_130 , F_7 ( V_130 ) ) ;
F_72 ( & V_129 ) ;
}
