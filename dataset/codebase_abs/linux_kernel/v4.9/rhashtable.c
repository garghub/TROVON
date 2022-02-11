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
if ( sizeof( T_2 ) != 0 ) {
V_4 -> V_18 = NULL ;
#ifdef F_12
if ( V_14 * sizeof( T_2 ) > V_19 &&
V_12 == V_20 )
V_4 -> V_18 = F_13 ( V_14 * sizeof( T_2 ) ) ;
#endif
if ( V_12 != V_20 )
V_12 |= V_21 | V_22 ;
if ( ! V_4 -> V_18 )
V_4 -> V_18 = F_14 ( V_14 , sizeof( T_2 ) ,
V_12 ) ;
if ( ! V_4 -> V_18 )
return - V_23 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_15 ( & V_4 -> V_18 [ V_13 ] ) ;
}
V_4 -> V_24 = V_14 - 1 ;
return 0 ;
}
static void F_16 ( const struct V_3 * V_4 )
{
if ( V_4 )
F_17 ( V_4 -> V_18 ) ;
F_17 ( V_4 ) ;
}
static void F_18 ( struct V_25 * V_26 )
{
F_16 ( F_19 ( V_26 , struct V_3 , V_27 ) ) ;
}
static struct V_3 * F_20 ( struct V_1 * V_2 ,
T_4 V_28 ,
T_3 V_12 )
{
struct V_3 * V_4 = NULL ;
T_4 V_14 ;
int V_13 ;
V_14 = sizeof( * V_4 ) + V_28 * sizeof( V_4 -> V_29 [ 0 ] ) ;
if ( V_14 <= ( V_19 << V_30 ) ||
V_12 != V_20 )
V_4 = F_21 ( V_14 , V_12 | V_21 | V_22 ) ;
if ( V_4 == NULL && V_12 == V_20 )
V_4 = F_22 ( V_14 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_14 = V_28 ;
if ( F_7 ( V_2 , V_4 , V_12 ) < 0 ) {
F_16 ( V_4 ) ;
return NULL ;
}
F_23 ( & V_4 -> V_31 ) ;
F_24 ( & V_4 -> V_32 , sizeof( V_4 -> V_32 ) ) ;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ )
F_25 ( V_4 -> V_29 [ V_13 ] , V_2 , V_13 ) ;
return V_4 ;
}
static struct V_3 * F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_33 ;
do {
V_33 = V_4 ;
V_4 = F_27 ( V_4 -> V_34 , V_2 ) ;
} while ( V_4 );
return V_33 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_35 )
{
struct V_3 * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_33 = F_26 ( V_2 ,
F_27 ( V_36 -> V_34 , V_2 ) ) ;
struct V_5 T_5 * * V_37 = & V_36 -> V_29 [ V_35 ] ;
int V_38 = - V_39 ;
struct V_5 * V_26 , * V_40 , * V_41 ;
T_2 * V_42 ;
unsigned int V_43 ;
F_30 (entry, old_tbl, old_hash) {
V_38 = 0 ;
V_40 = F_31 ( V_41 -> V_40 , V_36 , V_35 ) ;
if ( F_32 ( V_40 ) )
break;
V_37 = & V_41 -> V_40 ;
}
if ( V_38 )
goto V_44;
V_43 = F_1 ( V_2 , V_33 , V_41 ) ;
V_42 = F_6 ( V_33 , V_43 ) ;
F_33 ( V_42 , V_45 ) ;
V_26 = F_31 ( V_33 -> V_29 [ V_43 ] ,
V_33 , V_43 ) ;
F_34 ( V_41 -> V_40 , V_26 ) ;
F_35 ( V_33 -> V_29 [ V_43 ] , V_41 ) ;
F_36 ( V_42 ) ;
F_35 ( * V_37 , V_40 ) ;
V_44:
return V_38 ;
}
static void F_37 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
struct V_3 * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
T_2 * V_46 ;
V_46 = F_6 ( V_36 , V_35 ) ;
F_38 ( V_46 ) ;
while ( ! F_28 ( V_2 , V_35 ) )
;
V_36 -> V_47 ++ ;
F_39 ( V_46 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_36 ,
struct V_3 * V_33 )
{
F_38 ( V_36 -> V_18 ) ;
if ( F_41 ( V_36 -> V_34 ) ) {
F_39 ( V_36 -> V_18 ) ;
return - V_48 ;
}
F_35 ( V_36 -> V_34 , V_33 ) ;
F_39 ( V_36 -> V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
struct V_3 * V_33 ;
struct V_49 * V_50 ;
unsigned int V_35 ;
V_33 = F_29 ( V_36 -> V_34 , V_2 ) ;
if ( ! V_33 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_36 -> V_14 ; V_35 ++ )
F_37 ( V_2 , V_35 ) ;
F_35 ( V_2 -> V_4 , V_33 ) ;
F_43 ( & V_2 -> V_11 ) ;
F_44 (walker, &old_tbl->walkers, list)
V_50 -> V_4 = NULL ;
F_36 ( & V_2 -> V_11 ) ;
F_45 ( & V_36 -> V_27 , F_18 ) ;
return F_29 ( V_33 -> V_34 , V_2 ) ? - V_51 : 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_33 , * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
int V_38 ;
F_47 ( V_2 ) ;
V_36 = F_26 ( V_2 , V_36 ) ;
V_33 = F_20 ( V_2 , V_36 -> V_14 * 2 , V_20 ) ;
if ( V_33 == NULL )
return - V_23 ;
V_38 = F_40 ( V_2 , V_36 , V_33 ) ;
if ( V_38 )
F_16 ( V_33 ) ;
return V_38 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_33 , * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
unsigned int V_52 = F_49 ( & V_2 -> V_52 ) ;
unsigned int V_14 = 0 ;
int V_38 ;
F_47 ( V_2 ) ;
if ( V_52 )
V_14 = F_11 ( V_52 * 3 / 2 ) ;
if ( V_14 < V_2 -> V_7 . V_53 )
V_14 = V_2 -> V_7 . V_53 ;
if ( V_36 -> V_14 <= V_14 )
return 0 ;
if ( F_29 ( V_36 -> V_34 , V_2 ) )
return - V_48 ;
V_33 = F_20 ( V_2 , V_14 , V_20 ) ;
if ( V_33 == NULL )
return - V_23 ;
V_38 = F_40 ( V_2 , V_36 , V_33 ) ;
if ( V_38 )
F_16 ( V_33 ) ;
return V_38 ;
}
static void F_50 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_38 = 0 ;
V_2 = F_19 ( V_55 , struct V_1 , V_56 ) ;
F_51 ( & V_2 -> V_9 ) ;
V_4 = F_29 ( V_2 -> V_4 , V_2 ) ;
V_4 = F_26 ( V_2 , V_4 ) ;
if ( F_52 ( V_2 , V_4 ) )
F_46 ( V_2 ) ;
else if ( V_2 -> V_7 . V_57 && F_53 ( V_2 , V_4 ) )
F_48 ( V_2 ) ;
V_38 = F_42 ( V_2 ) ;
F_54 ( & V_2 -> V_9 ) ;
if ( V_38 )
F_55 ( & V_2 -> V_56 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_36 ;
struct V_3 * V_33 ;
unsigned int V_14 ;
int V_38 ;
V_36 = F_27 ( V_2 -> V_4 , V_2 ) ;
V_14 = V_4 -> V_14 ;
V_38 = - V_58 ;
if ( F_52 ( V_2 , V_4 ) )
V_14 *= 2 ;
else if ( V_36 != V_4 )
goto V_59;
V_38 = - V_23 ;
V_33 = F_20 ( V_2 , V_14 , V_60 ) ;
if ( V_33 == NULL )
goto V_59;
V_38 = F_40 ( V_2 , V_4 , V_33 ) ;
if ( V_38 ) {
F_16 ( V_33 ) ;
if ( V_38 == - V_48 )
V_38 = 0 ;
} else
F_55 ( & V_2 -> V_56 ) ;
return V_38 ;
V_59:
if ( F_57 ( F_58 ( V_4 -> V_34 ) ) )
return 0 ;
if ( V_38 == - V_23 )
F_55 ( & V_2 -> V_56 ) ;
return V_38 ;
}
static void * F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_10 ,
const void * V_61 , struct V_5 * V_62 )
{
struct V_63 V_64 = {
. V_2 = V_2 ,
. V_61 = V_61 ,
} ;
struct V_5 T_5 * * V_37 ;
struct V_5 * V_26 ;
int V_65 ;
V_65 = V_2 -> V_65 ;
V_37 = & V_4 -> V_29 [ V_10 ] ;
F_30 (head, tbl, hash) {
struct V_66 * V_67 ;
struct V_66 * V_68 ;
V_65 -- ;
if ( ! V_61 ||
( V_2 -> V_7 . V_69 ?
V_2 -> V_7 . V_69 ( & V_64 , F_60 ( V_2 , V_26 ) ) :
F_61 ( & V_64 , F_60 ( V_2 , V_26 ) ) ) )
continue;
if ( ! V_2 -> V_70 )
return F_60 ( V_2 , V_26 ) ;
V_67 = F_19 ( V_62 , struct V_66 , V_71 ) ;
V_68 = F_19 ( V_26 , struct V_66 , V_71 ) ;
F_34 ( V_67 -> V_40 , V_68 ) ;
V_26 = F_31 ( V_26 -> V_40 , V_4 , V_10 ) ;
F_34 ( V_67 -> V_71 . V_40 , V_26 ) ;
F_35 ( * V_37 , V_62 ) ;
return NULL ;
}
if ( V_65 <= 0 )
return F_62 ( - V_51 ) ;
return F_62 ( - V_39 ) ;
}
static struct V_3 * F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 ,
struct V_5 * V_62 ,
void * V_72 )
{
struct V_3 * V_33 ;
struct V_5 * V_26 ;
if ( ! F_64 ( V_72 ) )
return F_62 ( - V_48 ) ;
if ( F_65 ( V_72 ) != - V_51 && F_65 ( V_72 ) != - V_39 )
return F_66 ( V_72 ) ;
V_33 = F_67 ( V_4 -> V_34 ) ;
if ( V_33 )
return V_33 ;
if ( F_65 ( V_72 ) != - V_39 )
return F_66 ( V_72 ) ;
if ( F_68 ( F_69 ( V_2 , V_4 ) ) )
return F_62 ( - V_73 ) ;
if ( F_68 ( F_70 ( V_2 , V_4 ) ) )
return F_62 ( - V_51 ) ;
V_26 = F_31 ( V_4 -> V_29 [ V_10 ] , V_4 , V_10 ) ;
F_34 ( V_62 -> V_40 , V_26 ) ;
if ( V_2 -> V_70 ) {
struct V_66 * V_67 ;
V_67 = F_19 ( V_62 , struct V_66 , V_71 ) ;
F_34 ( V_67 -> V_40 , NULL ) ;
}
F_35 ( V_4 -> V_29 [ V_10 ] , V_62 ) ;
F_71 ( & V_2 -> V_52 ) ;
if ( F_52 ( V_2 , V_4 ) )
F_55 ( & V_2 -> V_56 ) ;
return NULL ;
}
static void * F_72 ( struct V_1 * V_2 , const void * V_61 ,
struct V_5 * V_62 )
{
struct V_3 * V_33 ;
struct V_3 * V_4 ;
unsigned int V_10 ;
T_2 * V_11 ;
void * V_72 ;
V_4 = F_67 ( V_2 -> V_4 ) ;
for (; ; ) {
V_10 = F_2 ( V_2 , V_4 , V_62 , V_2 -> V_7 ) ;
V_11 = F_6 ( V_4 , V_10 ) ;
F_38 ( V_11 ) ;
if ( V_4 -> V_47 <= V_10 )
break;
F_39 ( V_11 ) ;
V_4 = F_67 ( V_4 -> V_34 ) ;
}
V_72 = F_59 ( V_2 , V_4 , V_10 , V_61 , V_62 ) ;
V_33 = F_63 ( V_2 , V_4 , V_10 , V_62 , V_72 ) ;
if ( F_65 ( V_33 ) != - V_48 )
V_72 = F_66 ( V_33 ) ;
while ( ! F_64 ( V_33 ) ) {
V_4 = V_33 ;
V_10 = F_2 ( V_2 , V_4 , V_62 , V_2 -> V_7 ) ;
F_33 ( F_6 ( V_4 , V_10 ) ,
V_45 ) ;
V_72 = F_59 ( V_2 , V_4 , V_10 , V_61 , V_62 ) ;
V_33 = F_63 ( V_2 , V_4 , V_10 , V_62 , V_72 ) ;
if ( F_65 ( V_33 ) != - V_48 )
V_72 = F_66 ( V_33 ) ;
F_36 ( F_6 ( V_4 , V_10 ) ) ;
}
F_39 ( V_11 ) ;
if ( F_65 ( V_72 ) == - V_51 )
V_72 = F_62 ( F_56 ( V_2 , V_4 ) ? :
- V_51 ) ;
return V_72 ;
}
void * F_73 ( struct V_1 * V_2 , const void * V_61 ,
struct V_5 * V_62 )
{
void * V_72 ;
do {
F_74 () ;
V_72 = F_72 ( V_2 , V_61 , V_62 ) ;
F_75 () ;
} while ( F_65 ( V_72 ) == - V_51 );
return V_72 ;
}
void F_76 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
V_75 -> V_2 = V_2 ;
V_75 -> V_7 = NULL ;
V_75 -> V_76 = 0 ;
V_75 -> V_77 = 0 ;
F_43 ( & V_2 -> V_11 ) ;
V_75 -> V_50 . V_4 =
F_77 ( V_2 -> V_4 , F_4 ( & V_2 -> V_11 ) ) ;
F_78 ( & V_75 -> V_50 . V_67 , & V_75 -> V_50 . V_4 -> V_31 ) ;
F_36 ( & V_2 -> V_11 ) ;
}
void F_79 ( struct V_74 * V_75 )
{
F_43 ( & V_75 -> V_2 -> V_11 ) ;
if ( V_75 -> V_50 . V_4 )
F_80 ( & V_75 -> V_50 . V_67 ) ;
F_36 ( & V_75 -> V_2 -> V_11 ) ;
}
int F_81 ( struct V_74 * V_75 )
__acquires( T_6 )
{
struct V_1 * V_2 = V_75 -> V_2 ;
F_74 () ;
F_43 ( & V_2 -> V_11 ) ;
if ( V_75 -> V_50 . V_4 )
F_80 ( & V_75 -> V_50 . V_67 ) ;
F_36 ( & V_2 -> V_11 ) ;
if ( ! V_75 -> V_50 . V_4 ) {
V_75 -> V_50 . V_4 = F_27 ( V_2 -> V_4 , V_2 ) ;
return - V_51 ;
}
return 0 ;
}
void * F_82 ( struct V_74 * V_75 )
{
struct V_3 * V_4 = V_75 -> V_50 . V_4 ;
struct V_66 * V_67 = V_75 -> V_67 ;
struct V_1 * V_2 = V_75 -> V_2 ;
struct V_5 * V_7 = V_75 -> V_7 ;
bool V_70 = V_2 -> V_70 ;
if ( V_7 ) {
if ( ! V_70 || ! ( V_67 = F_67 ( V_67 -> V_40 ) ) ) {
V_7 = F_67 ( V_7 -> V_40 ) ;
V_67 = F_19 ( V_7 , struct V_66 , V_71 ) ;
}
goto V_40;
}
for (; V_75 -> V_76 < V_4 -> V_14 ; V_75 -> V_76 ++ ) {
int V_77 = V_75 -> V_77 ;
F_83 (p, tbl, iter->slot) {
if ( V_70 ) {
V_67 = F_19 ( V_7 , struct V_66 ,
V_71 ) ;
do {
if ( ! V_77 )
goto V_40;
V_77 -- ;
V_67 = F_67 ( V_67 -> V_40 ) ;
} while ( V_67 );
continue;
}
if ( ! V_77 )
break;
V_77 -- ;
}
V_40:
if ( ! F_32 ( V_7 ) ) {
V_75 -> V_77 ++ ;
V_75 -> V_7 = V_7 ;
V_75 -> V_67 = V_67 ;
return F_60 ( V_2 , V_70 ? & V_67 -> V_71 : V_7 ) ;
}
V_75 -> V_77 = 0 ;
}
V_75 -> V_7 = NULL ;
F_84 () ;
V_75 -> V_50 . V_4 = F_27 ( V_4 -> V_34 , V_2 ) ;
if ( V_75 -> V_50 . V_4 ) {
V_75 -> V_76 = 0 ;
V_75 -> V_77 = 0 ;
return F_62 ( - V_51 ) ;
}
return NULL ;
}
void F_85 ( struct V_74 * V_75 )
__releases( T_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_75 -> V_50 . V_4 ;
if ( ! V_4 )
goto V_44;
V_2 = V_75 -> V_2 ;
F_43 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_47 < V_4 -> V_14 )
F_78 ( & V_75 -> V_50 . V_67 , & V_4 -> V_31 ) ;
else
V_75 -> V_50 . V_4 = NULL ;
F_36 ( & V_2 -> V_11 ) ;
V_75 -> V_7 = NULL ;
V_44:
F_75 () ;
}
static T_4 F_86 ( const struct V_78 * V_79 )
{
return F_87 ( F_11 ( V_79 -> V_80 * 4 / 3 ) ,
( unsigned long ) V_79 -> V_53 ) ;
}
static T_1 F_88 ( const void * V_61 , T_1 V_81 , T_1 V_82 )
{
return F_89 ( V_61 , V_81 , V_82 ) ;
}
int F_90 ( struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_3 * V_4 ;
T_4 V_14 ;
V_14 = V_83 ;
if ( ( ! V_79 -> V_84 && ! V_79 -> V_85 ) ||
( V_79 -> V_85 && ! V_79 -> V_69 ) )
return - V_86 ;
if ( V_79 -> V_87 && V_79 -> V_87 < ( 1U << V_88 ) )
return - V_86 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_91 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_11 ) ;
memcpy ( & V_2 -> V_7 , V_79 , sizeof( * V_79 ) ) ;
if ( V_79 -> V_53 )
V_2 -> V_7 . V_53 = F_11 ( V_79 -> V_53 ) ;
if ( V_79 -> V_89 )
V_2 -> V_7 . V_89 = F_92 ( V_79 -> V_89 ) ;
if ( V_79 -> V_90 )
V_2 -> V_7 . V_90 =
F_92 ( V_79 -> V_90 ) ;
else
V_2 -> V_7 . V_90 = V_2 -> V_7 . V_89 * 2 ;
V_2 -> V_7 . V_53 = F_87 ( V_2 -> V_7 . V_53 , V_91 ) ;
if ( V_79 -> V_80 )
V_14 = F_86 ( & V_2 -> V_7 ) ;
if ( ! V_79 -> V_92 )
V_2 -> V_65 = 16 ;
if ( V_79 -> V_17 )
V_2 -> V_7 . V_17 = F_11 ( V_79 -> V_17 ) ;
else
V_2 -> V_7 . V_17 = V_93 ;
V_2 -> V_84 = V_2 -> V_7 . V_84 ;
if ( ! V_79 -> V_94 ) {
V_2 -> V_7 . V_94 = V_95 ;
if ( ! ( V_2 -> V_84 & ( sizeof( T_1 ) - 1 ) ) ) {
V_2 -> V_84 /= sizeof( T_1 ) ;
V_2 -> V_7 . V_94 = F_88 ;
}
}
V_4 = F_20 ( V_2 , V_14 , V_20 ) ;
if ( V_4 == NULL )
return - V_23 ;
F_93 ( & V_2 -> V_52 , 0 ) ;
F_34 ( V_2 -> V_4 , V_4 ) ;
F_94 ( & V_2 -> V_56 , F_50 ) ;
return 0 ;
}
int F_95 ( struct V_96 * V_97 , const struct V_78 * V_79 )
{
int V_38 ;
if ( V_79 -> V_87 )
return - V_86 ;
V_38 = F_90 ( & V_97 -> V_2 , V_79 ) ;
V_97 -> V_2 . V_70 = true ;
return V_38 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_5 * V_62 ,
void (* F_97)( void * V_98 , void * V_64 ) ,
void * V_64 )
{
struct V_66 * V_67 ;
if ( ! V_2 -> V_70 ) {
F_97 ( F_60 ( V_2 , V_62 ) , V_64 ) ;
return;
}
V_67 = F_19 ( V_62 , struct V_66 , V_71 ) ;
do {
V_62 = & V_67 -> V_71 ;
V_67 = F_29 ( V_67 -> V_40 , V_2 ) ;
F_97 ( F_60 ( V_2 , V_62 ) , V_64 ) ;
} while ( V_67 );
}
void F_98 ( struct V_1 * V_2 ,
void (* F_97)( void * V_98 , void * V_64 ) ,
void * V_64 )
{
const struct V_3 * V_4 ;
unsigned int V_13 ;
F_99 ( & V_2 -> V_56 ) ;
F_51 ( & V_2 -> V_9 ) ;
V_4 = F_29 ( V_2 -> V_4 , V_2 ) ;
if ( F_97 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_14 ; V_13 ++ ) {
struct V_5 * V_99 , * V_40 ;
for ( V_99 = F_29 ( V_4 -> V_29 [ V_13 ] , V_2 ) ,
V_40 = ! F_32 ( V_99 ) ?
F_29 ( V_99 -> V_40 , V_2 ) : NULL ;
! F_32 ( V_99 ) ;
V_99 = V_40 ,
V_40 = ! F_32 ( V_99 ) ?
F_29 ( V_99 -> V_40 , V_2 ) : NULL )
F_96 ( V_2 , V_99 , F_97 , V_64 ) ;
}
}
F_16 ( V_4 ) ;
F_54 ( & V_2 -> V_9 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
return F_98 ( V_2 , NULL , NULL ) ;
}
