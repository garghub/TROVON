static T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_2 ( V_2 , V_4 , V_6 , V_2 -> V_7 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return ( V_8 ) ? F_4 ( & V_2 -> V_9 ) : 1 ;
}
int F_5 ( const struct V_3 * V_4 , T_1 V_10 )
{
T_2 * V_11 = F_6 ( V_4 , V_10 ) ;
return ( V_8 ) ? F_4 ( V_11 ) : 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_3 V_12 )
{
unsigned int V_13 , V_14 ;
#if F_8 ( V_15 )
unsigned int V_16 = 2 ;
#else
unsigned int V_16 = F_9 () ;
#endif
V_16 = F_10 (unsigned int, nr_pcpus, 64UL ) ;
V_14 = F_11 ( V_16 * V_2 -> V_7 . V_17 ) ;
V_14 = F_10 (unsigned int, size, tbl->size >> 1 ) ;
if ( V_4 -> V_18 )
V_14 = F_12 ( V_14 , 1U << V_4 -> V_18 ) ;
if ( sizeof( T_2 ) != 0 ) {
if ( F_13 ( V_12 ) )
V_4 -> V_19 = F_14 ( V_14 * sizeof( T_2 ) , V_12 ) ;
else
V_4 -> V_19 = F_15 ( V_14 , sizeof( T_2 ) ,
V_12 ) ;
if ( ! V_4 -> V_19 )
return - V_20 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_16 ( & V_4 -> V_19 [ V_13 ] ) ;
}
V_4 -> V_21 = V_14 - 1 ;
return 0 ;
}
static void F_17 ( union V_22 * V_23 , unsigned int V_14 )
{
const unsigned int V_24 = V_25 - F_18 ( sizeof( void * ) ) ;
const unsigned int V_26 = 1 << V_24 ;
unsigned int V_13 ;
V_23 = F_19 ( V_23 -> V_27 ) ;
if ( ! V_23 )
return;
if ( V_14 > V_26 ) {
V_14 >>= V_24 ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ )
F_17 ( V_23 + V_13 , V_14 ) ;
}
F_20 ( V_23 ) ;
}
static void F_21 ( const struct V_3 * V_4 )
{
unsigned int V_14 = V_4 -> V_14 >> V_4 -> V_18 ;
unsigned int V_26 = 1 << V_4 -> V_18 ;
union V_22 * V_23 ;
unsigned int V_13 ;
V_23 = (union V_22 * ) F_19 ( V_4 -> V_28 [ 0 ] ) ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ )
F_17 ( V_23 + V_13 , V_14 ) ;
F_20 ( V_23 ) ;
}
static void F_22 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_18 )
F_21 ( V_4 ) ;
F_23 ( V_4 -> V_19 ) ;
F_23 ( V_4 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
F_22 ( F_25 ( V_30 , struct V_3 , V_31 ) ) ;
}
static union V_22 * F_26 ( struct V_1 * V_2 ,
union V_22 T_4 * * V_32 ,
unsigned int V_33 ,
unsigned int V_34 )
{
union V_22 * V_23 ;
int V_13 ;
V_23 = F_27 ( * V_32 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_28 ( V_35 , V_36 ) ;
if ( V_23 && V_33 ) {
for ( V_13 = 0 ; V_13 < V_35 / sizeof( V_23 [ 0 ] . V_37 ) ; V_13 ++ )
F_29 ( V_23 [ V_13 ] . V_37 , V_2 ,
( V_13 << V_33 ) | V_34 ) ;
}
F_30 ( * V_32 , V_23 ) ;
return V_23 ;
}
static struct V_3 * F_31 ( struct V_1 * V_2 ,
T_5 V_38 ,
T_3 V_12 )
{
const unsigned int V_24 = V_25 - F_18 ( sizeof( void * ) ) ;
struct V_3 * V_4 ;
T_5 V_14 ;
if ( V_38 < ( 1 << ( V_24 + 1 ) ) )
return NULL ;
V_14 = sizeof( * V_4 ) + sizeof( V_4 -> V_28 [ 0 ] ) ;
V_4 = F_28 ( V_14 , V_12 ) ;
if ( ! V_4 )
return NULL ;
if ( ! F_26 ( V_2 , (union V_22 T_4 * * ) V_4 -> V_28 ,
0 , 0 ) ) {
F_20 ( V_4 ) ;
return NULL ;
}
V_4 -> V_18 = ( F_18 ( V_38 ) - 1 ) % V_24 + 1 ;
return V_4 ;
}
static struct V_3 * F_32 ( struct V_1 * V_2 ,
T_5 V_38 ,
T_3 V_12 )
{
struct V_3 * V_4 = NULL ;
T_5 V_14 ;
int V_13 ;
V_14 = sizeof( * V_4 ) + V_38 * sizeof( V_4 -> V_28 [ 0 ] ) ;
if ( V_14 <= ( V_35 << V_39 ) ||
V_12 != V_40 )
V_4 = F_28 ( V_14 , V_12 | V_41 | V_42 ) ;
if ( V_4 == NULL && V_12 == V_40 )
V_4 = F_33 ( V_14 ) ;
V_14 = V_38 ;
if ( V_4 == NULL && V_12 != V_40 ) {
V_4 = F_31 ( V_2 , V_38 , V_12 ) ;
V_38 = 0 ;
}
if ( V_4 == NULL )
return NULL ;
V_4 -> V_14 = V_14 ;
if ( F_7 ( V_2 , V_4 , V_12 ) < 0 ) {
F_22 ( V_4 ) ;
return NULL ;
}
F_34 ( & V_4 -> V_43 ) ;
F_35 ( & V_4 -> V_44 , sizeof( V_4 -> V_44 ) ) ;
for ( V_13 = 0 ; V_13 < V_38 ; V_13 ++ )
F_29 ( V_4 -> V_28 [ V_13 ] , V_2 , V_13 ) ;
return V_4 ;
}
static struct V_3 * F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_45 ;
do {
V_45 = V_4 ;
V_4 = F_37 ( V_4 -> V_46 , V_2 ) ;
} while ( V_4 );
return V_45 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_47 )
{
struct V_3 * V_48 = F_39 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_45 = F_36 ( V_2 ,
F_37 ( V_48 -> V_46 , V_2 ) ) ;
struct V_5 T_4 * * V_49 = F_40 ( V_48 , V_47 ) ;
int V_50 = - V_51 ;
struct V_5 * V_30 , * V_52 , * V_53 ;
T_2 * V_54 ;
unsigned int V_55 ;
if ( V_45 -> V_18 )
goto V_56;
V_50 = - V_57 ;
F_41 (entry, old_tbl, old_hash) {
V_50 = 0 ;
V_52 = F_42 ( V_53 -> V_52 , V_48 , V_47 ) ;
if ( F_43 ( V_52 ) )
break;
V_49 = & V_53 -> V_52 ;
}
if ( V_50 )
goto V_56;
V_55 = F_1 ( V_2 , V_45 , V_53 ) ;
V_54 = F_6 ( V_45 , V_55 ) ;
F_44 ( V_54 , V_58 ) ;
V_30 = F_42 ( V_45 -> V_28 [ V_55 ] ,
V_45 , V_55 ) ;
F_45 ( V_53 -> V_52 , V_30 ) ;
F_30 ( V_45 -> V_28 [ V_55 ] , V_53 ) ;
F_46 ( V_54 ) ;
F_30 ( * V_49 , V_52 ) ;
V_56:
return V_50 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_47 )
{
struct V_3 * V_48 = F_39 ( V_2 -> V_4 , V_2 ) ;
T_2 * V_59 ;
int V_50 ;
V_59 = F_6 ( V_48 , V_47 ) ;
F_48 ( V_59 ) ;
while ( ! ( V_50 = F_38 ( V_2 , V_47 ) ) )
;
if ( V_50 == - V_57 ) {
V_48 -> V_60 ++ ;
V_50 = 0 ;
}
F_49 ( V_59 ) ;
return V_50 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_48 ,
struct V_3 * V_45 )
{
F_48 ( V_48 -> V_19 ) ;
if ( F_51 ( V_48 -> V_46 ) ) {
F_49 ( V_48 -> V_19 ) ;
return - V_61 ;
}
F_30 ( V_48 -> V_46 , V_45 ) ;
F_49 ( V_48 -> V_19 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_48 = F_39 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_45 ;
struct V_62 * V_63 ;
unsigned int V_47 ;
int V_50 ;
V_45 = F_39 ( V_48 -> V_46 , V_2 ) ;
if ( ! V_45 )
return 0 ;
for ( V_47 = 0 ; V_47 < V_48 -> V_14 ; V_47 ++ ) {
V_50 = F_47 ( V_2 , V_47 ) ;
if ( V_50 )
return V_50 ;
}
F_30 ( V_2 -> V_4 , V_45 ) ;
F_53 ( & V_2 -> V_11 ) ;
F_54 (walker, &old_tbl->walkers, list)
V_63 -> V_4 = NULL ;
F_46 ( & V_2 -> V_11 ) ;
F_55 ( & V_48 -> V_31 , F_24 ) ;
return F_39 ( V_45 -> V_46 , V_2 ) ? - V_51 : 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_48 ,
unsigned int V_14 )
{
struct V_3 * V_45 ;
int V_50 ;
F_57 ( V_2 ) ;
V_45 = F_32 ( V_2 , V_14 , V_40 ) ;
if ( V_45 == NULL )
return - V_20 ;
V_50 = F_50 ( V_2 , V_48 , V_45 ) ;
if ( V_50 )
F_22 ( V_45 ) ;
return V_50 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_48 = F_39 ( V_2 -> V_4 , V_2 ) ;
unsigned int V_64 = F_59 ( & V_2 -> V_64 ) ;
unsigned int V_14 = 0 ;
if ( V_64 )
V_14 = F_11 ( V_64 * 3 / 2 ) ;
if ( V_14 < V_2 -> V_7 . V_65 )
V_14 = V_2 -> V_7 . V_65 ;
if ( V_48 -> V_14 <= V_14 )
return 0 ;
if ( F_39 ( V_48 -> V_46 , V_2 ) )
return - V_61 ;
return F_56 ( V_2 , V_48 , V_14 ) ;
}
static void F_60 ( struct V_66 * V_67 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_50 = 0 ;
V_2 = F_25 ( V_67 , struct V_1 , V_68 ) ;
F_61 ( & V_2 -> V_9 ) ;
V_4 = F_39 ( V_2 -> V_4 , V_2 ) ;
V_4 = F_36 ( V_2 , V_4 ) ;
if ( F_62 ( V_2 , V_4 ) )
V_50 = F_56 ( V_2 , V_4 , V_4 -> V_14 * 2 ) ;
else if ( V_2 -> V_7 . V_69 && F_63 ( V_2 , V_4 ) )
V_50 = F_58 ( V_2 ) ;
else if ( V_4 -> V_18 )
V_50 = F_56 ( V_2 , V_4 , V_4 -> V_14 ) ;
if ( ! V_50 )
V_50 = F_52 ( V_2 ) ;
F_64 ( & V_2 -> V_9 ) ;
if ( V_50 )
F_65 ( & V_2 -> V_68 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_48 ;
struct V_3 * V_45 ;
unsigned int V_14 ;
int V_50 ;
V_48 = F_37 ( V_2 -> V_4 , V_2 ) ;
V_14 = V_4 -> V_14 ;
V_50 = - V_70 ;
if ( F_62 ( V_2 , V_4 ) )
V_14 *= 2 ;
else if ( V_48 != V_4 )
goto V_71;
V_50 = - V_20 ;
V_45 = F_32 ( V_2 , V_14 , V_36 ) ;
if ( V_45 == NULL )
goto V_71;
V_50 = F_50 ( V_2 , V_4 , V_45 ) ;
if ( V_50 ) {
F_22 ( V_45 ) ;
if ( V_50 == - V_61 )
V_50 = 0 ;
} else
F_65 ( & V_2 -> V_68 ) ;
return V_50 ;
V_71:
if ( F_67 ( F_19 ( V_4 -> V_46 ) ) )
return 0 ;
if ( V_50 == - V_20 )
F_65 ( & V_2 -> V_68 ) ;
return V_50 ;
}
static void * F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_10 ,
const void * V_72 , struct V_5 * V_73 )
{
struct V_74 V_75 = {
. V_2 = V_2 ,
. V_72 = V_72 ,
} ;
struct V_5 T_4 * * V_49 ;
struct V_5 * V_30 ;
int V_76 ;
V_76 = V_77 ;
V_49 = F_40 ( V_4 , V_10 ) ;
F_69 (head, *pprev, tbl, hash) {
struct V_78 * V_79 ;
struct V_78 * V_80 ;
V_76 -- ;
if ( ! V_72 ||
( V_2 -> V_7 . V_81 ?
V_2 -> V_7 . V_81 ( & V_75 , F_70 ( V_2 , V_30 ) ) :
F_71 ( & V_75 , F_70 ( V_2 , V_30 ) ) ) )
continue;
if ( ! V_2 -> V_82 )
return F_70 ( V_2 , V_30 ) ;
V_79 = F_25 ( V_73 , struct V_78 , V_83 ) ;
V_80 = F_25 ( V_30 , struct V_78 , V_83 ) ;
F_45 ( V_79 -> V_52 , V_80 ) ;
V_30 = F_42 ( V_30 -> V_52 , V_4 , V_10 ) ;
F_45 ( V_79 -> V_83 . V_52 , V_30 ) ;
F_30 ( * V_49 , V_73 ) ;
return NULL ;
}
if ( V_76 <= 0 )
return F_72 ( - V_51 ) ;
return F_72 ( - V_57 ) ;
}
static struct V_3 * F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
struct V_5 * V_73 ,
void * V_84 )
{
struct V_5 T_4 * * V_49 ;
struct V_3 * V_45 ;
struct V_5 * V_30 ;
if ( ! F_74 ( V_84 ) )
return F_72 ( - V_61 ) ;
if ( F_75 ( V_84 ) != - V_51 && F_75 ( V_84 ) != - V_57 )
return F_76 ( V_84 ) ;
V_45 = F_27 ( V_4 -> V_46 ) ;
if ( V_45 )
return V_45 ;
if ( F_75 ( V_84 ) != - V_57 )
return F_76 ( V_84 ) ;
if ( F_77 ( F_78 ( V_2 , V_4 ) ) )
return F_72 ( - V_85 ) ;
if ( F_77 ( F_79 ( V_2 , V_4 ) ) )
return F_72 ( - V_51 ) ;
V_49 = F_80 ( V_2 , V_4 , V_10 ) ;
if ( ! V_49 )
return F_72 ( - V_20 ) ;
V_30 = F_42 ( * V_49 , V_4 , V_10 ) ;
F_45 ( V_73 -> V_52 , V_30 ) ;
if ( V_2 -> V_82 ) {
struct V_78 * V_79 ;
V_79 = F_25 ( V_73 , struct V_78 , V_83 ) ;
F_45 ( V_79 -> V_52 , NULL ) ;
}
F_30 ( * V_49 , V_73 ) ;
F_81 ( & V_2 -> V_64 ) ;
if ( F_62 ( V_2 , V_4 ) )
F_65 ( & V_2 -> V_68 ) ;
return NULL ;
}
static void * F_82 ( struct V_1 * V_2 , const void * V_72 ,
struct V_5 * V_73 )
{
struct V_3 * V_45 ;
struct V_3 * V_4 ;
unsigned int V_10 ;
T_2 * V_11 ;
void * V_84 ;
V_4 = F_27 ( V_2 -> V_4 ) ;
for (; ; ) {
V_10 = F_2 ( V_2 , V_4 , V_73 , V_2 -> V_7 ) ;
V_11 = F_6 ( V_4 , V_10 ) ;
F_48 ( V_11 ) ;
if ( V_4 -> V_60 <= V_10 )
break;
F_49 ( V_11 ) ;
V_4 = F_27 ( V_4 -> V_46 ) ;
}
V_84 = F_68 ( V_2 , V_4 , V_10 , V_72 , V_73 ) ;
V_45 = F_73 ( V_2 , V_4 , V_10 , V_73 , V_84 ) ;
if ( F_75 ( V_45 ) != - V_61 )
V_84 = F_76 ( V_45 ) ;
while ( ! F_74 ( V_45 ) ) {
V_4 = V_45 ;
V_10 = F_2 ( V_2 , V_4 , V_73 , V_2 -> V_7 ) ;
F_44 ( F_6 ( V_4 , V_10 ) ,
V_58 ) ;
V_84 = F_68 ( V_2 , V_4 , V_10 , V_72 , V_73 ) ;
V_45 = F_73 ( V_2 , V_4 , V_10 , V_73 , V_84 ) ;
if ( F_75 ( V_45 ) != - V_61 )
V_84 = F_76 ( V_45 ) ;
F_46 ( F_6 ( V_4 , V_10 ) ) ;
}
F_49 ( V_11 ) ;
if ( F_75 ( V_84 ) == - V_51 )
V_84 = F_72 ( F_66 ( V_2 , V_4 ) ? :
- V_51 ) ;
return V_84 ;
}
void * F_83 ( struct V_1 * V_2 , const void * V_72 ,
struct V_5 * V_73 )
{
void * V_84 ;
do {
F_84 () ;
V_84 = F_82 ( V_2 , V_72 , V_73 ) ;
F_85 () ;
} while ( F_75 ( V_84 ) == - V_51 );
return V_84 ;
}
void F_86 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
V_87 -> V_2 = V_2 ;
V_87 -> V_7 = NULL ;
V_87 -> V_88 = 0 ;
V_87 -> V_89 = 0 ;
F_53 ( & V_2 -> V_11 ) ;
V_87 -> V_63 . V_4 =
F_87 ( V_2 -> V_4 , F_4 ( & V_2 -> V_11 ) ) ;
F_88 ( & V_87 -> V_63 . V_79 , & V_87 -> V_63 . V_4 -> V_43 ) ;
F_46 ( & V_2 -> V_11 ) ;
}
void F_89 ( struct V_86 * V_87 )
{
F_53 ( & V_87 -> V_2 -> V_11 ) ;
if ( V_87 -> V_63 . V_4 )
F_90 ( & V_87 -> V_63 . V_79 ) ;
F_46 ( & V_87 -> V_2 -> V_11 ) ;
}
int F_91 ( struct V_86 * V_87 )
__acquires( T_6 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
F_84 () ;
F_53 ( & V_2 -> V_11 ) ;
if ( V_87 -> V_63 . V_4 )
F_90 ( & V_87 -> V_63 . V_79 ) ;
F_46 ( & V_2 -> V_11 ) ;
if ( ! V_87 -> V_63 . V_4 ) {
V_87 -> V_63 . V_4 = F_37 ( V_2 -> V_4 , V_2 ) ;
return - V_51 ;
}
return 0 ;
}
void * F_92 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = V_87 -> V_63 . V_4 ;
struct V_78 * V_79 = V_87 -> V_79 ;
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_5 * V_7 = V_87 -> V_7 ;
bool V_82 = V_2 -> V_82 ;
if ( V_7 ) {
if ( ! V_82 || ! ( V_79 = F_27 ( V_79 -> V_52 ) ) ) {
V_7 = F_27 ( V_7 -> V_52 ) ;
V_79 = F_25 ( V_7 , struct V_78 , V_83 ) ;
}
goto V_52;
}
for (; V_87 -> V_88 < V_4 -> V_14 ; V_87 -> V_88 ++ ) {
int V_89 = V_87 -> V_89 ;
F_93 (p, tbl, iter->slot) {
if ( V_82 ) {
V_79 = F_25 ( V_7 , struct V_78 ,
V_83 ) ;
do {
if ( ! V_89 )
goto V_52;
V_89 -- ;
V_79 = F_27 ( V_79 -> V_52 ) ;
} while ( V_79 );
continue;
}
if ( ! V_89 )
break;
V_89 -- ;
}
V_52:
if ( ! F_43 ( V_7 ) ) {
V_87 -> V_89 ++ ;
V_87 -> V_7 = V_7 ;
V_87 -> V_79 = V_79 ;
return F_70 ( V_2 , V_82 ? & V_79 -> V_83 : V_7 ) ;
}
V_87 -> V_89 = 0 ;
}
V_87 -> V_7 = NULL ;
F_94 () ;
V_87 -> V_63 . V_4 = F_37 ( V_4 -> V_46 , V_2 ) ;
if ( V_87 -> V_63 . V_4 ) {
V_87 -> V_88 = 0 ;
V_87 -> V_89 = 0 ;
return F_72 ( - V_51 ) ;
}
return NULL ;
}
void F_95 ( struct V_86 * V_87 )
__releases( T_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_87 -> V_63 . V_4 ;
if ( ! V_4 )
goto V_56;
V_2 = V_87 -> V_2 ;
F_53 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_60 < V_4 -> V_14 )
F_88 ( & V_87 -> V_63 . V_79 , & V_4 -> V_43 ) ;
else
V_87 -> V_63 . V_4 = NULL ;
F_46 ( & V_2 -> V_11 ) ;
V_87 -> V_7 = NULL ;
V_56:
F_85 () ;
}
static T_5 F_96 ( const struct V_90 * V_91 )
{
return F_97 ( F_11 ( V_91 -> V_92 * 4 / 3 ) ,
( unsigned long ) V_91 -> V_65 ) ;
}
static T_1 F_98 ( const void * V_72 , T_1 V_93 , T_1 V_94 )
{
return F_99 ( V_72 , V_93 , V_94 ) ;
}
int F_100 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_3 * V_4 ;
T_5 V_14 ;
V_14 = V_95 ;
if ( ( ! V_91 -> V_96 && ! V_91 -> V_97 ) ||
( V_91 -> V_97 && ! V_91 -> V_81 ) )
return - V_98 ;
if ( V_91 -> V_99 && V_91 -> V_99 < ( 1U << V_100 ) )
return - V_98 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_101 ( & V_2 -> V_9 ) ;
F_16 ( & V_2 -> V_11 ) ;
memcpy ( & V_2 -> V_7 , V_91 , sizeof( * V_91 ) ) ;
if ( V_91 -> V_65 )
V_2 -> V_7 . V_65 = F_11 ( V_91 -> V_65 ) ;
V_2 -> V_101 = 1u << 31 ;
if ( V_91 -> V_102 ) {
V_2 -> V_7 . V_102 = F_102 ( V_91 -> V_102 ) ;
if ( V_2 -> V_7 . V_102 < V_2 -> V_101 / 2 )
V_2 -> V_101 = V_2 -> V_7 . V_102 * 2 ;
}
V_2 -> V_7 . V_65 = F_103 ( V_103 , V_2 -> V_7 . V_65 , V_104 ) ;
if ( V_91 -> V_92 )
V_14 = F_96 ( & V_2 -> V_7 ) ;
if ( V_91 -> V_17 )
V_2 -> V_7 . V_17 = F_11 ( V_91 -> V_17 ) ;
else
V_2 -> V_7 . V_17 = V_105 ;
V_2 -> V_96 = V_2 -> V_7 . V_96 ;
if ( ! V_91 -> V_106 ) {
V_2 -> V_7 . V_106 = V_107 ;
if ( ! ( V_2 -> V_96 & ( sizeof( T_1 ) - 1 ) ) ) {
V_2 -> V_96 /= sizeof( T_1 ) ;
V_2 -> V_7 . V_106 = F_98 ;
}
}
V_4 = F_32 ( V_2 , V_14 , V_40 ) ;
if ( V_4 == NULL )
return - V_20 ;
F_104 ( & V_2 -> V_64 , 0 ) ;
F_45 ( V_2 -> V_4 , V_4 ) ;
F_105 ( & V_2 -> V_68 , F_60 ) ;
return 0 ;
}
int F_106 ( struct V_108 * V_109 , const struct V_90 * V_91 )
{
int V_50 ;
if ( V_91 -> V_99 )
return - V_98 ;
V_50 = F_100 ( & V_109 -> V_2 , V_91 ) ;
V_109 -> V_2 . V_82 = true ;
return V_50 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_5 * V_73 ,
void (* F_108)( void * V_110 , void * V_75 ) ,
void * V_75 )
{
struct V_78 * V_79 ;
if ( ! V_2 -> V_82 ) {
F_108 ( F_70 ( V_2 , V_73 ) , V_75 ) ;
return;
}
V_79 = F_25 ( V_73 , struct V_78 , V_83 ) ;
do {
V_73 = & V_79 -> V_83 ;
V_79 = F_39 ( V_79 -> V_52 , V_2 ) ;
F_108 ( F_70 ( V_2 , V_73 ) , V_75 ) ;
} while ( V_79 );
}
void F_109 ( struct V_1 * V_2 ,
void (* F_108)( void * V_110 , void * V_75 ) ,
void * V_75 )
{
struct V_3 * V_4 ;
unsigned int V_13 ;
F_110 ( & V_2 -> V_68 ) ;
F_61 ( & V_2 -> V_9 ) ;
V_4 = F_39 ( V_2 -> V_4 , V_2 ) ;
if ( F_108 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_14 ; V_13 ++ ) {
struct V_5 * V_111 , * V_52 ;
for ( V_111 = F_39 ( * F_111 ( V_4 , V_13 ) , V_2 ) ,
V_52 = ! F_43 ( V_111 ) ?
F_39 ( V_111 -> V_52 , V_2 ) : NULL ;
! F_43 ( V_111 ) ;
V_111 = V_52 ,
V_52 = ! F_43 ( V_111 ) ?
F_39 ( V_111 -> V_52 , V_2 ) : NULL )
F_107 ( V_2 , V_111 , F_108 , V_75 ) ;
}
}
F_22 ( V_4 ) ;
F_64 ( & V_2 -> V_9 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
return F_109 ( V_2 , NULL , NULL ) ;
}
struct V_5 T_4 * * F_113 ( const struct V_3 * V_4 ,
unsigned int V_10 )
{
const unsigned int V_24 = V_25 - F_18 ( sizeof( void * ) ) ;
static struct V_5 T_4 * V_112 =
(struct V_5 T_4 * ) F_114 ( 0 ) ;
unsigned int V_113 = V_10 & ( ( 1 << V_4 -> V_18 ) - 1 ) ;
unsigned int V_14 = V_4 -> V_14 >> V_4 -> V_18 ;
unsigned int V_114 = V_10 ;
union V_22 * V_23 ;
V_23 = (union V_22 * ) F_19 ( V_4 -> V_28 [ 0 ] ) ;
V_23 = F_115 ( V_23 [ V_113 ] . V_27 , V_4 , V_10 ) ;
V_114 >>= V_4 -> V_18 ;
while ( V_23 && V_14 > ( 1 << V_24 ) ) {
V_113 = V_114 & ( ( 1 << V_24 ) - 1 ) ;
V_23 = F_115 ( V_23 [ V_113 ] . V_27 ,
V_4 , V_10 ) ;
V_14 >>= V_24 ;
V_114 >>= V_24 ;
}
if ( ! V_23 )
return & V_112 ;
return & V_23 [ V_114 ] . V_37 ;
}
struct V_5 T_4 * * F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 )
{
const unsigned int V_24 = V_25 - F_18 ( sizeof( void * ) ) ;
unsigned int V_113 = V_10 & ( ( 1 << V_4 -> V_18 ) - 1 ) ;
unsigned int V_14 = V_4 -> V_14 >> V_4 -> V_18 ;
union V_22 * V_23 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_23 = (union V_22 * ) F_19 ( V_4 -> V_28 [ 0 ] ) ;
V_10 >>= V_4 -> V_18 ;
V_34 = V_113 ;
V_33 = V_4 -> V_18 ;
V_23 = F_26 ( V_2 , & V_23 [ V_113 ] . V_27 ,
V_14 <= ( 1 << V_24 ) ? V_33 : 0 , V_34 ) ;
while ( V_23 && V_14 > ( 1 << V_24 ) ) {
V_113 = V_10 & ( ( 1 << V_24 ) - 1 ) ;
V_14 >>= V_24 ;
V_10 >>= V_24 ;
V_34 |= V_113 << V_33 ;
V_33 += V_24 ;
V_23 = F_26 ( V_2 , & V_23 [ V_113 ] . V_27 ,
V_14 <= ( 1 << V_24 ) ? V_33 : 0 ,
V_34 ) ;
}
if ( ! V_23 )
return NULL ;
return & V_23 [ V_10 ] . V_37 ;
}
