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
if ( V_12 != V_39 )
V_4 = F_28 ( V_14 , V_12 | V_40 | V_41 ) ;
else
V_4 = F_33 ( V_14 , V_12 ) ;
V_14 = V_38 ;
if ( V_4 == NULL && V_12 != V_39 ) {
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
F_34 ( & V_4 -> V_42 ) ;
V_4 -> V_43 = F_35 () ;
for ( V_13 = 0 ; V_13 < V_38 ; V_13 ++ )
F_29 ( V_4 -> V_28 [ V_13 ] , V_2 , V_13 ) ;
return V_4 ;
}
static struct V_3 * F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_44 ;
do {
V_44 = V_4 ;
V_4 = F_37 ( V_4 -> V_45 , V_2 ) ;
} while ( V_4 );
return V_44 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_46 )
{
struct V_3 * V_47 = F_39 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_44 = F_36 ( V_2 ,
F_37 ( V_47 -> V_45 , V_2 ) ) ;
struct V_5 T_4 * * V_48 = F_40 ( V_47 , V_46 ) ;
int V_49 = - V_50 ;
struct V_5 * V_30 , * V_51 , * V_52 ;
T_2 * V_53 ;
unsigned int V_54 ;
if ( V_44 -> V_18 )
goto V_55;
V_49 = - V_56 ;
F_41 (entry, old_tbl, old_hash) {
V_49 = 0 ;
V_51 = F_42 ( V_52 -> V_51 , V_47 , V_46 ) ;
if ( F_43 ( V_51 ) )
break;
V_48 = & V_52 -> V_51 ;
}
if ( V_49 )
goto V_55;
V_54 = F_1 ( V_2 , V_44 , V_52 ) ;
V_53 = F_6 ( V_44 , V_54 ) ;
F_44 ( V_53 , V_57 ) ;
V_30 = F_42 ( V_44 -> V_28 [ V_54 ] ,
V_44 , V_54 ) ;
F_45 ( V_52 -> V_51 , V_30 ) ;
F_30 ( V_44 -> V_28 [ V_54 ] , V_52 ) ;
F_46 ( V_53 ) ;
F_30 ( * V_48 , V_51 ) ;
V_55:
return V_49 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_46 )
{
struct V_3 * V_47 = F_39 ( V_2 -> V_4 , V_2 ) ;
T_2 * V_58 ;
int V_49 ;
V_58 = F_6 ( V_47 , V_46 ) ;
F_48 ( V_58 ) ;
while ( ! ( V_49 = F_38 ( V_2 , V_46 ) ) )
;
if ( V_49 == - V_56 ) {
V_47 -> V_59 ++ ;
V_49 = 0 ;
}
F_49 ( V_58 ) ;
return V_49 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_47 ,
struct V_3 * V_44 )
{
F_48 ( V_47 -> V_19 ) ;
if ( F_51 ( V_47 -> V_45 ) ) {
F_49 ( V_47 -> V_19 ) ;
return - V_60 ;
}
F_30 ( V_47 -> V_45 , V_44 ) ;
F_49 ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_47 = F_39 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_44 ;
struct V_61 * V_62 ;
unsigned int V_46 ;
int V_49 ;
V_44 = F_39 ( V_47 -> V_45 , V_2 ) ;
if ( ! V_44 )
return 0 ;
for ( V_46 = 0 ; V_46 < V_47 -> V_14 ; V_46 ++ ) {
V_49 = F_47 ( V_2 , V_46 ) ;
if ( V_49 )
return V_49 ;
}
F_30 ( V_2 -> V_4 , V_44 ) ;
F_53 ( & V_2 -> V_11 ) ;
F_54 (walker, &old_tbl->walkers, list)
V_62 -> V_4 = NULL ;
F_46 ( & V_2 -> V_11 ) ;
F_55 ( & V_47 -> V_31 , F_24 ) ;
return F_39 ( V_44 -> V_45 , V_2 ) ? - V_50 : 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_47 ,
unsigned int V_14 )
{
struct V_3 * V_44 ;
int V_49 ;
F_57 ( V_2 ) ;
V_44 = F_32 ( V_2 , V_14 , V_39 ) ;
if ( V_44 == NULL )
return - V_20 ;
V_49 = F_50 ( V_2 , V_47 , V_44 ) ;
if ( V_49 )
F_22 ( V_44 ) ;
return V_49 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_47 = F_39 ( V_2 -> V_4 , V_2 ) ;
unsigned int V_63 = F_59 ( & V_2 -> V_63 ) ;
unsigned int V_14 = 0 ;
if ( V_63 )
V_14 = F_11 ( V_63 * 3 / 2 ) ;
if ( V_14 < V_2 -> V_7 . V_64 )
V_14 = V_2 -> V_7 . V_64 ;
if ( V_47 -> V_14 <= V_14 )
return 0 ;
if ( F_39 ( V_47 -> V_45 , V_2 ) )
return - V_60 ;
return F_56 ( V_2 , V_47 , V_14 ) ;
}
static void F_60 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_49 = 0 ;
V_2 = F_25 ( V_66 , struct V_1 , V_67 ) ;
F_61 ( & V_2 -> V_9 ) ;
V_4 = F_39 ( V_2 -> V_4 , V_2 ) ;
V_4 = F_36 ( V_2 , V_4 ) ;
if ( F_62 ( V_2 , V_4 ) )
V_49 = F_56 ( V_2 , V_4 , V_4 -> V_14 * 2 ) ;
else if ( V_2 -> V_7 . V_68 && F_63 ( V_2 , V_4 ) )
V_49 = F_58 ( V_2 ) ;
else if ( V_4 -> V_18 )
V_49 = F_56 ( V_2 , V_4 , V_4 -> V_14 ) ;
if ( ! V_49 )
V_49 = F_52 ( V_2 ) ;
F_64 ( & V_2 -> V_9 ) ;
if ( V_49 )
F_65 ( & V_2 -> V_67 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_47 ;
struct V_3 * V_44 ;
unsigned int V_14 ;
int V_49 ;
V_47 = F_37 ( V_2 -> V_4 , V_2 ) ;
V_14 = V_4 -> V_14 ;
V_49 = - V_69 ;
if ( F_62 ( V_2 , V_4 ) )
V_14 *= 2 ;
else if ( V_47 != V_4 )
goto V_70;
V_49 = - V_20 ;
V_44 = F_32 ( V_2 , V_14 , V_36 ) ;
if ( V_44 == NULL )
goto V_70;
V_49 = F_50 ( V_2 , V_4 , V_44 ) ;
if ( V_49 ) {
F_22 ( V_44 ) ;
if ( V_49 == - V_60 )
V_49 = 0 ;
} else
F_65 ( & V_2 -> V_67 ) ;
return V_49 ;
V_70:
if ( F_67 ( F_19 ( V_4 -> V_45 ) ) )
return 0 ;
if ( V_49 == - V_20 )
F_65 ( & V_2 -> V_67 ) ;
return V_49 ;
}
static void * F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_10 ,
const void * V_71 , struct V_5 * V_72 )
{
struct V_73 V_74 = {
. V_2 = V_2 ,
. V_71 = V_71 ,
} ;
struct V_5 T_4 * * V_48 ;
struct V_5 * V_30 ;
int V_75 ;
V_75 = V_76 ;
V_48 = F_40 ( V_4 , V_10 ) ;
F_69 (head, *pprev, tbl, hash) {
struct V_77 * V_78 ;
struct V_77 * V_79 ;
V_75 -- ;
if ( ! V_71 ||
( V_2 -> V_7 . V_80 ?
V_2 -> V_7 . V_80 ( & V_74 , F_70 ( V_2 , V_30 ) ) :
F_71 ( & V_74 , F_70 ( V_2 , V_30 ) ) ) )
continue;
if ( ! V_2 -> V_81 )
return F_70 ( V_2 , V_30 ) ;
V_78 = F_25 ( V_72 , struct V_77 , V_82 ) ;
V_79 = F_25 ( V_30 , struct V_77 , V_82 ) ;
F_45 ( V_78 -> V_51 , V_79 ) ;
V_30 = F_42 ( V_30 -> V_51 , V_4 , V_10 ) ;
F_45 ( V_78 -> V_82 . V_51 , V_30 ) ;
F_30 ( * V_48 , V_72 ) ;
return NULL ;
}
if ( V_75 <= 0 )
return F_72 ( - V_50 ) ;
return F_72 ( - V_56 ) ;
}
static struct V_3 * F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
struct V_5 * V_72 ,
void * V_83 )
{
struct V_5 T_4 * * V_48 ;
struct V_3 * V_44 ;
struct V_5 * V_30 ;
if ( ! F_74 ( V_83 ) )
return F_72 ( - V_60 ) ;
if ( F_75 ( V_83 ) != - V_50 && F_75 ( V_83 ) != - V_56 )
return F_76 ( V_83 ) ;
V_44 = F_27 ( V_4 -> V_45 ) ;
if ( V_44 )
return V_44 ;
if ( F_75 ( V_83 ) != - V_56 )
return F_76 ( V_83 ) ;
if ( F_77 ( F_78 ( V_2 , V_4 ) ) )
return F_72 ( - V_84 ) ;
if ( F_77 ( F_79 ( V_2 , V_4 ) ) )
return F_72 ( - V_50 ) ;
V_48 = F_80 ( V_2 , V_4 , V_10 ) ;
if ( ! V_48 )
return F_72 ( - V_20 ) ;
V_30 = F_42 ( * V_48 , V_4 , V_10 ) ;
F_45 ( V_72 -> V_51 , V_30 ) ;
if ( V_2 -> V_81 ) {
struct V_77 * V_78 ;
V_78 = F_25 ( V_72 , struct V_77 , V_82 ) ;
F_45 ( V_78 -> V_51 , NULL ) ;
}
F_30 ( * V_48 , V_72 ) ;
F_81 ( & V_2 -> V_63 ) ;
if ( F_62 ( V_2 , V_4 ) )
F_65 ( & V_2 -> V_67 ) ;
return NULL ;
}
static void * F_82 ( struct V_1 * V_2 , const void * V_71 ,
struct V_5 * V_72 )
{
struct V_3 * V_44 ;
struct V_3 * V_4 ;
unsigned int V_10 ;
T_2 * V_11 ;
void * V_83 ;
V_4 = F_27 ( V_2 -> V_4 ) ;
for (; ; ) {
V_10 = F_2 ( V_2 , V_4 , V_72 , V_2 -> V_7 ) ;
V_11 = F_6 ( V_4 , V_10 ) ;
F_48 ( V_11 ) ;
if ( V_4 -> V_59 <= V_10 )
break;
F_49 ( V_11 ) ;
V_4 = F_27 ( V_4 -> V_45 ) ;
}
V_83 = F_68 ( V_2 , V_4 , V_10 , V_71 , V_72 ) ;
V_44 = F_73 ( V_2 , V_4 , V_10 , V_72 , V_83 ) ;
if ( F_75 ( V_44 ) != - V_60 )
V_83 = F_76 ( V_44 ) ;
while ( ! F_74 ( V_44 ) ) {
V_4 = V_44 ;
V_10 = F_2 ( V_2 , V_4 , V_72 , V_2 -> V_7 ) ;
F_44 ( F_6 ( V_4 , V_10 ) ,
V_57 ) ;
V_83 = F_68 ( V_2 , V_4 , V_10 , V_71 , V_72 ) ;
V_44 = F_73 ( V_2 , V_4 , V_10 , V_72 , V_83 ) ;
if ( F_75 ( V_44 ) != - V_60 )
V_83 = F_76 ( V_44 ) ;
F_46 ( F_6 ( V_4 , V_10 ) ) ;
}
F_49 ( V_11 ) ;
if ( F_75 ( V_83 ) == - V_50 )
V_83 = F_72 ( F_66 ( V_2 , V_4 ) ? :
- V_50 ) ;
return V_83 ;
}
void * F_83 ( struct V_1 * V_2 , const void * V_71 ,
struct V_5 * V_72 )
{
void * V_83 ;
do {
F_84 () ;
V_83 = F_82 ( V_2 , V_71 , V_72 ) ;
F_85 () ;
} while ( F_75 ( V_83 ) == - V_50 );
return V_83 ;
}
void F_86 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
V_86 -> V_2 = V_2 ;
V_86 -> V_7 = NULL ;
V_86 -> V_87 = 0 ;
V_86 -> V_88 = 0 ;
F_53 ( & V_2 -> V_11 ) ;
V_86 -> V_62 . V_4 =
F_87 ( V_2 -> V_4 , F_4 ( & V_2 -> V_11 ) ) ;
F_88 ( & V_86 -> V_62 . V_78 , & V_86 -> V_62 . V_4 -> V_42 ) ;
F_46 ( & V_2 -> V_11 ) ;
}
void F_89 ( struct V_85 * V_86 )
{
F_53 ( & V_86 -> V_2 -> V_11 ) ;
if ( V_86 -> V_62 . V_4 )
F_90 ( & V_86 -> V_62 . V_78 ) ;
F_46 ( & V_86 -> V_2 -> V_11 ) ;
}
int F_91 ( struct V_85 * V_86 )
__acquires( T_6 )
{
struct V_1 * V_2 = V_86 -> V_2 ;
F_84 () ;
F_53 ( & V_2 -> V_11 ) ;
if ( V_86 -> V_62 . V_4 )
F_90 ( & V_86 -> V_62 . V_78 ) ;
F_46 ( & V_2 -> V_11 ) ;
if ( ! V_86 -> V_62 . V_4 ) {
V_86 -> V_62 . V_4 = F_37 ( V_2 -> V_4 , V_2 ) ;
return - V_50 ;
}
return 0 ;
}
void * F_92 ( struct V_85 * V_86 )
{
struct V_3 * V_4 = V_86 -> V_62 . V_4 ;
struct V_77 * V_78 = V_86 -> V_78 ;
struct V_1 * V_2 = V_86 -> V_2 ;
struct V_5 * V_7 = V_86 -> V_7 ;
bool V_81 = V_2 -> V_81 ;
if ( V_7 ) {
if ( ! V_81 || ! ( V_78 = F_27 ( V_78 -> V_51 ) ) ) {
V_7 = F_27 ( V_7 -> V_51 ) ;
V_78 = F_25 ( V_7 , struct V_77 , V_82 ) ;
}
goto V_51;
}
for (; V_86 -> V_87 < V_4 -> V_14 ; V_86 -> V_87 ++ ) {
int V_88 = V_86 -> V_88 ;
F_93 (p, tbl, iter->slot) {
if ( V_81 ) {
V_78 = F_25 ( V_7 , struct V_77 ,
V_82 ) ;
do {
if ( ! V_88 )
goto V_51;
V_88 -- ;
V_78 = F_27 ( V_78 -> V_51 ) ;
} while ( V_78 );
continue;
}
if ( ! V_88 )
break;
V_88 -- ;
}
V_51:
if ( ! F_43 ( V_7 ) ) {
V_86 -> V_88 ++ ;
V_86 -> V_7 = V_7 ;
V_86 -> V_78 = V_78 ;
return F_70 ( V_2 , V_81 ? & V_78 -> V_82 : V_7 ) ;
}
V_86 -> V_88 = 0 ;
}
V_86 -> V_7 = NULL ;
F_94 () ;
V_86 -> V_62 . V_4 = F_37 ( V_4 -> V_45 , V_2 ) ;
if ( V_86 -> V_62 . V_4 ) {
V_86 -> V_87 = 0 ;
V_86 -> V_88 = 0 ;
return F_72 ( - V_50 ) ;
}
return NULL ;
}
void F_95 ( struct V_85 * V_86 )
__releases( T_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_86 -> V_62 . V_4 ;
if ( ! V_4 )
goto V_55;
V_2 = V_86 -> V_2 ;
F_53 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_59 < V_4 -> V_14 )
F_88 ( & V_86 -> V_62 . V_78 , & V_4 -> V_42 ) ;
else
V_86 -> V_62 . V_4 = NULL ;
F_46 ( & V_2 -> V_11 ) ;
V_86 -> V_7 = NULL ;
V_55:
F_85 () ;
}
static T_5 F_96 ( const struct V_89 * V_90 )
{
return F_97 ( F_11 ( V_90 -> V_91 * 4 / 3 ) ,
( unsigned long ) V_90 -> V_64 ) ;
}
static T_1 F_98 ( const void * V_71 , T_1 V_92 , T_1 V_93 )
{
return F_99 ( V_71 , V_92 , V_93 ) ;
}
int F_100 ( struct V_1 * V_2 ,
const struct V_89 * V_90 )
{
struct V_3 * V_4 ;
T_5 V_14 ;
V_14 = V_94 ;
if ( ( ! V_90 -> V_95 && ! V_90 -> V_96 ) ||
( V_90 -> V_96 && ! V_90 -> V_80 ) )
return - V_97 ;
if ( V_90 -> V_98 && V_90 -> V_98 < ( 1U << V_99 ) )
return - V_97 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_101 ( & V_2 -> V_9 ) ;
F_16 ( & V_2 -> V_11 ) ;
memcpy ( & V_2 -> V_7 , V_90 , sizeof( * V_90 ) ) ;
if ( V_90 -> V_64 )
V_2 -> V_7 . V_64 = F_11 ( V_90 -> V_64 ) ;
V_2 -> V_100 = 1u << 31 ;
if ( V_90 -> V_101 ) {
V_2 -> V_7 . V_101 = F_102 ( V_90 -> V_101 ) ;
if ( V_2 -> V_7 . V_101 < V_2 -> V_100 / 2 )
V_2 -> V_100 = V_2 -> V_7 . V_101 * 2 ;
}
V_2 -> V_7 . V_64 = F_103 ( V_102 , V_2 -> V_7 . V_64 , V_103 ) ;
if ( V_90 -> V_91 )
V_14 = F_96 ( & V_2 -> V_7 ) ;
if ( V_90 -> V_17 )
V_2 -> V_7 . V_17 = F_11 ( V_90 -> V_17 ) ;
else
V_2 -> V_7 . V_17 = V_104 ;
V_2 -> V_95 = V_2 -> V_7 . V_95 ;
if ( ! V_90 -> V_105 ) {
V_2 -> V_7 . V_105 = V_106 ;
if ( ! ( V_2 -> V_95 & ( sizeof( T_1 ) - 1 ) ) ) {
V_2 -> V_95 /= sizeof( T_1 ) ;
V_2 -> V_7 . V_105 = F_98 ;
}
}
V_4 = F_32 ( V_2 , V_14 , V_39 ) ;
if ( V_4 == NULL )
return - V_20 ;
F_104 ( & V_2 -> V_63 , 0 ) ;
F_45 ( V_2 -> V_4 , V_4 ) ;
F_105 ( & V_2 -> V_67 , F_60 ) ;
return 0 ;
}
int F_106 ( struct V_107 * V_108 , const struct V_89 * V_90 )
{
int V_49 ;
if ( V_90 -> V_98 )
return - V_97 ;
V_49 = F_100 ( & V_108 -> V_2 , V_90 ) ;
V_108 -> V_2 . V_81 = true ;
return V_49 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_5 * V_72 ,
void (* F_108)( void * V_109 , void * V_74 ) ,
void * V_74 )
{
struct V_77 * V_78 ;
if ( ! V_2 -> V_81 ) {
F_108 ( F_70 ( V_2 , V_72 ) , V_74 ) ;
return;
}
V_78 = F_25 ( V_72 , struct V_77 , V_82 ) ;
do {
V_72 = & V_78 -> V_82 ;
V_78 = F_39 ( V_78 -> V_51 , V_2 ) ;
F_108 ( F_70 ( V_2 , V_72 ) , V_74 ) ;
} while ( V_78 );
}
void F_109 ( struct V_1 * V_2 ,
void (* F_108)( void * V_109 , void * V_74 ) ,
void * V_74 )
{
struct V_3 * V_4 ;
unsigned int V_13 ;
F_110 ( & V_2 -> V_67 ) ;
F_61 ( & V_2 -> V_9 ) ;
V_4 = F_39 ( V_2 -> V_4 , V_2 ) ;
if ( F_108 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_14 ; V_13 ++ ) {
struct V_5 * V_110 , * V_51 ;
for ( V_110 = F_39 ( * F_111 ( V_4 , V_13 ) , V_2 ) ,
V_51 = ! F_43 ( V_110 ) ?
F_39 ( V_110 -> V_51 , V_2 ) : NULL ;
! F_43 ( V_110 ) ;
V_110 = V_51 ,
V_51 = ! F_43 ( V_110 ) ?
F_39 ( V_110 -> V_51 , V_2 ) : NULL )
F_107 ( V_2 , V_110 , F_108 , V_74 ) ;
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
static struct V_5 T_4 * V_111 =
(struct V_5 T_4 * ) F_114 ( 0 ) ;
unsigned int V_112 = V_10 & ( ( 1 << V_4 -> V_18 ) - 1 ) ;
unsigned int V_14 = V_4 -> V_14 >> V_4 -> V_18 ;
unsigned int V_113 = V_10 ;
union V_22 * V_23 ;
V_23 = (union V_22 * ) F_19 ( V_4 -> V_28 [ 0 ] ) ;
V_23 = F_115 ( V_23 [ V_112 ] . V_27 , V_4 , V_10 ) ;
V_113 >>= V_4 -> V_18 ;
while ( V_23 && V_14 > ( 1 << V_24 ) ) {
V_112 = V_113 & ( ( 1 << V_24 ) - 1 ) ;
V_23 = F_115 ( V_23 [ V_112 ] . V_27 ,
V_4 , V_10 ) ;
V_14 >>= V_24 ;
V_113 >>= V_24 ;
}
if ( ! V_23 )
return & V_111 ;
return & V_23 [ V_113 ] . V_37 ;
}
struct V_5 T_4 * * F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 )
{
const unsigned int V_24 = V_25 - F_18 ( sizeof( void * ) ) ;
unsigned int V_112 = V_10 & ( ( 1 << V_4 -> V_18 ) - 1 ) ;
unsigned int V_14 = V_4 -> V_14 >> V_4 -> V_18 ;
union V_22 * V_23 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_23 = (union V_22 * ) F_19 ( V_4 -> V_28 [ 0 ] ) ;
V_10 >>= V_4 -> V_18 ;
V_34 = V_112 ;
V_33 = V_4 -> V_18 ;
V_23 = F_26 ( V_2 , & V_23 [ V_112 ] . V_27 ,
V_14 <= ( 1 << V_24 ) ? V_33 : 0 , V_34 ) ;
while ( V_23 && V_14 > ( 1 << V_24 ) ) {
V_112 = V_10 & ( ( 1 << V_24 ) - 1 ) ;
V_14 >>= V_24 ;
V_10 >>= V_24 ;
V_34 |= V_112 << V_33 ;
V_33 += V_24 ;
V_23 = F_26 ( V_2 , & V_23 [ V_112 ] . V_27 ,
V_14 <= ( 1 << V_24 ) ? V_33 : 0 ,
V_34 ) ;
}
if ( ! V_23 )
return NULL ;
return & V_23 [ V_10 ] . V_37 ;
}
