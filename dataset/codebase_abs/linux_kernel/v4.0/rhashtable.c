static T_1 * F_1 ( const struct V_1 * V_2 , T_2 V_3 )
{
return & V_2 -> V_4 [ V_3 & V_2 -> V_5 ] ;
}
static void * F_2 ( const struct V_6 * V_7 , const struct V_8 * V_9 )
{
return ( void * ) V_9 - V_7 -> V_10 . V_11 ;
}
static T_2 F_3 ( const struct V_1 * V_2 , T_2 V_3 )
{
return V_3 & ( V_2 -> V_12 - 1 ) ;
}
static T_2 F_4 ( const struct V_6 * V_7 , const void * V_13 )
{
T_2 V_3 ;
if ( F_5 ( ! V_7 -> V_10 . V_14 ) )
V_3 = V_7 -> V_10 . V_15 ( V_13 , V_7 -> V_10 . V_16 ) ;
else
V_3 = V_7 -> V_10 . V_17 ( V_13 + V_7 -> V_10 . V_18 , V_7 -> V_10 . V_14 ,
V_7 -> V_10 . V_16 ) ;
return V_3 >> V_19 ;
}
static T_2 F_6 ( struct V_6 * V_7 , const void * V_20 , T_2 V_21 )
{
return V_7 -> V_10 . V_17 ( V_20 , V_21 , V_7 -> V_10 . V_16 ) >> V_19 ;
}
static T_2 F_7 ( const struct V_6 * V_7 ,
const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
return F_3 ( V_2 , F_4 ( V_7 , F_2 ( V_7 , V_9 ) ) ) ;
}
static void F_8 ( const struct V_6 * V_7 ,
const struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_22 , V_3 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_12 ; V_22 ++ ) {
F_9 ( L_1 , V_22 ) ;
F_10 (he, tbl, i) {
V_3 = F_7 ( V_7 , V_2 , V_9 ) ;
F_11 ( L_2 ,
V_3 , F_1 ( V_2 , V_3 ) ) ;
}
F_11 ( L_3 ) ;
}
}
static void F_12 ( struct V_6 * V_7 ,
const struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_1 * V_23 , * V_24 ;
F_13 ( L_4 ,
V_3 , V_2 ) ;
F_14 () ;
V_24 = F_15 ( V_7 -> V_24 , V_7 ) ;
V_23 = F_15 ( V_7 -> V_2 , V_7 ) ;
if ( V_24 != V_23 ) {
F_9 ( L_5 ,
V_24 , V_24 -> V_12 ) ;
F_8 ( V_7 , V_24 ) ;
}
F_9 ( L_6 , V_23 , V_23 -> V_12 ) ;
F_8 ( V_7 , V_23 ) ;
F_16 () ;
}
int F_17 ( struct V_6 * V_7 )
{
return ( V_25 ) ? F_18 ( & V_7 -> V_26 ) : 1 ;
}
int F_19 ( const struct V_1 * V_2 , T_2 V_3 )
{
T_1 * V_27 = F_1 ( V_2 , V_3 ) ;
return ( V_25 ) ? F_18 ( V_27 ) : 1 ;
}
static struct V_8 T_3 * * F_20 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_8 T_3 * * V_29 ;
for ( V_29 = & V_2 -> V_30 [ V_28 ] ;
! F_21 ( F_22 ( * V_29 , V_2 , V_28 ) ) ;
V_29 = & F_22 ( * V_29 , V_2 , V_28 ) -> V_31 )
;
return V_29 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
unsigned int V_22 , V_12 ;
#if F_24 ( V_32 )
unsigned int V_33 = 2 ;
#else
unsigned int V_33 = F_25 () ;
#endif
V_33 = F_26 (unsigned int, nr_pcpus, 32UL ) ;
V_12 = F_27 ( V_33 * V_7 -> V_10 . V_34 ) ;
V_12 = F_26 (unsigned int, size, tbl->size >> 1 ) ;
if ( sizeof( T_1 ) != 0 ) {
#ifdef F_28
if ( V_12 * sizeof( T_1 ) > V_35 )
V_2 -> V_4 = F_29 ( V_12 * sizeof( T_1 ) ) ;
else
#endif
V_2 -> V_4 = F_30 ( V_12 , sizeof( T_1 ) ,
V_36 ) ;
if ( ! V_2 -> V_4 )
return - V_37 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
F_31 ( & V_2 -> V_4 [ V_22 ] ) ;
}
V_2 -> V_5 = V_12 - 1 ;
return 0 ;
}
static void F_32 ( const struct V_1 * V_2 )
{
if ( V_2 )
F_33 ( V_2 -> V_4 ) ;
F_33 ( V_2 ) ;
}
static struct V_1 * F_34 ( struct V_6 * V_7 ,
T_4 V_38 )
{
struct V_1 * V_2 = NULL ;
T_4 V_12 ;
int V_22 ;
V_12 = sizeof( * V_2 ) + V_38 * sizeof( V_2 -> V_30 [ 0 ] ) ;
if ( V_12 <= ( V_35 << V_39 ) )
V_2 = F_35 ( V_12 , V_36 | V_40 | V_41 ) ;
if ( V_2 == NULL )
V_2 = F_36 ( V_12 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_12 = V_38 ;
if ( F_23 ( V_7 , V_2 ) < 0 ) {
F_32 ( V_2 ) ;
return NULL ;
}
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ )
F_37 ( V_2 -> V_30 [ V_22 ] , V_7 , V_22 ) ;
return V_2 ;
}
static bool F_38 ( const struct V_6 * V_7 , T_4 V_42 )
{
return F_39 ( & V_7 -> V_43 ) > ( V_42 / 4 * 3 ) &&
( ! V_7 -> V_10 . V_44 || F_39 ( & V_7 -> V_45 ) < V_7 -> V_10 . V_44 ) ;
}
static bool F_40 ( const struct V_6 * V_7 , T_4 V_42 )
{
return F_39 ( & V_7 -> V_43 ) < ( V_42 * 3 / 10 ) &&
( F_39 ( & V_7 -> V_45 ) > V_7 -> V_10 . V_46 ) ;
}
static void F_41 ( struct V_1 * V_47 ,
struct V_1 * V_23 , unsigned int V_3 )
__acquires( T_5 )
{
F_42 ( F_1 ( V_23 , V_3 ) ) ;
if ( V_47 != V_23 )
F_43 ( F_1 ( V_47 , V_3 ) ,
V_48 ) ;
}
static void F_44 ( struct V_1 * V_47 ,
struct V_1 * V_23 , unsigned int V_3 )
__releases( T_5 )
{
if ( V_47 != V_23 )
F_45 ( F_1 ( V_47 , V_3 ) ) ;
F_45 ( F_1 ( V_23 , V_3 ) ) ;
}
static bool F_46 ( struct V_6 * V_7 ,
const struct V_1 * V_47 ,
struct V_1 * V_23 ,
T_4 V_49 )
{
struct V_8 * V_9 , * V_10 , * V_31 ;
unsigned int V_50 , V_51 ;
F_47 ( V_7 , V_23 , V_49 ) ;
V_10 = F_22 ( V_23 -> V_30 [ V_49 ] , V_23 ,
V_49 ) ;
if ( F_21 ( V_10 ) )
return false ;
V_50 = F_7 ( V_7 , V_47 , V_10 ) ;
F_47 ( V_7 , V_47 , V_50 ) ;
F_48 (he, p->next, old_tbl, old_hash) {
V_51 = F_7 ( V_7 , V_47 , V_9 ) ;
F_47 ( V_7 , V_47 , V_51 ) ;
if ( V_50 != V_51 )
break;
V_10 = V_9 ;
}
F_49 ( V_23 -> V_30 [ V_49 ] , V_10 -> V_31 ) ;
F_37 ( V_31 , V_7 , V_49 ) ;
if ( ! F_21 ( V_9 ) ) {
F_48 (he, he->next, old_tbl, old_hash) {
if ( F_7 ( V_7 , V_47 , V_9 ) == V_50 ) {
V_31 = V_9 ;
break;
}
}
}
F_49 ( V_10 -> V_31 , V_31 ) ;
V_10 = F_22 ( V_23 -> V_30 [ V_49 ] , V_23 ,
V_49 ) ;
return ! F_21 ( V_10 ) ;
}
static void F_50 ( struct V_6 * V_7 , struct V_1 * V_47 ,
unsigned int V_50 , struct V_8 * V_52 )
{
F_47 ( V_7 , V_47 , V_50 ) ;
F_49 ( * F_20 ( V_47 , V_50 ) , V_52 ) ;
}
int F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_47 , * V_23 = F_52 ( V_7 -> V_2 , V_7 ) ;
struct V_8 * V_9 ;
unsigned int V_50 , V_49 ;
bool V_53 = false ;
F_53 ( V_7 ) ;
V_47 = F_34 ( V_7 , V_23 -> V_12 * 2 ) ;
if ( V_47 == NULL )
return - V_37 ;
F_54 ( & V_7 -> V_45 ) ;
F_49 ( V_7 -> V_24 , V_47 ) ;
F_55 () ;
for ( V_50 = 0 ; V_50 < V_47 -> V_12 ; V_50 ++ ) {
V_49 = F_3 ( V_23 , V_50 ) ;
F_41 ( V_47 , V_23 , V_50 ) ;
F_56 (he, old_tbl, old_hash) {
if ( F_7 ( V_7 , V_47 , V_9 ) == V_50 ) {
F_50 ( V_7 , V_47 , V_50 , V_9 ) ;
break;
}
}
F_44 ( V_47 , V_23 , V_50 ) ;
F_57 () ;
}
while ( ! V_53 && ! V_7 -> V_54 ) {
F_55 () ;
V_53 = true ;
for ( V_49 = 0 ; V_49 < V_23 -> V_12 ; V_49 ++ ) {
F_41 ( V_47 , V_23 , V_49 ) ;
if ( F_46 ( V_7 , V_47 , V_23 ,
V_49 ) )
V_53 = false ;
F_44 ( V_47 , V_23 , V_49 ) ;
F_57 () ;
}
}
F_49 ( V_7 -> V_2 , V_47 ) ;
F_55 () ;
F_32 ( V_23 ) ;
return 0 ;
}
int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_47 , * V_2 = F_52 ( V_7 -> V_2 , V_7 ) ;
unsigned int V_50 ;
F_53 ( V_7 ) ;
V_47 = F_34 ( V_7 , V_2 -> V_12 / 2 ) ;
if ( V_47 == NULL )
return - V_37 ;
F_49 ( V_7 -> V_24 , V_47 ) ;
F_55 () ;
for ( V_50 = 0 ; V_50 < V_47 -> V_12 ; V_50 ++ ) {
F_41 ( V_47 , V_2 , V_50 ) ;
F_49 ( * F_20 ( V_47 , V_50 ) ,
V_2 -> V_30 [ V_50 ] ) ;
F_47 ( V_7 , V_2 , V_50 + V_47 -> V_12 ) ;
F_49 ( * F_20 ( V_47 , V_50 ) ,
V_2 -> V_30 [ V_50 + V_47 -> V_12 ] ) ;
F_44 ( V_47 , V_2 , V_50 ) ;
F_57 () ;
}
F_49 ( V_7 -> V_2 , V_47 ) ;
F_59 ( & V_7 -> V_45 ) ;
F_55 () ;
F_32 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_55 * V_56 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_57 * V_58 ;
V_7 = F_61 ( V_56 , struct V_6 , V_59 ) ;
F_62 ( & V_7 -> V_26 ) ;
if ( V_7 -> V_54 )
goto V_60;
V_2 = F_52 ( V_7 -> V_2 , V_7 ) ;
F_63 (walker, &ht->walkers, list)
V_58 -> V_61 = true ;
if ( F_38 ( V_7 , V_2 -> V_12 ) )
F_51 ( V_7 ) ;
else if ( F_40 ( V_7 , V_2 -> V_12 ) )
F_58 ( V_7 ) ;
V_60:
F_64 ( & V_7 -> V_26 ) ;
}
static void F_65 ( struct V_6 * V_7 , struct V_8 * V_62 ,
struct V_1 * V_2 ,
const struct V_1 * V_23 , T_2 V_3 )
{
bool V_63 = V_2 == V_23 ;
struct V_8 * V_64 ;
V_3 = F_3 ( V_2 , V_3 ) ;
V_64 = F_22 ( V_2 -> V_30 [ V_3 ] , V_2 , V_3 ) ;
F_47 ( V_7 , V_2 , V_3 ) ;
if ( F_21 ( V_64 ) )
F_37 ( V_62 -> V_31 , V_7 , V_3 ) ;
else
F_66 ( V_62 -> V_31 , V_64 ) ;
F_49 ( V_2 -> V_30 [ V_3 ] , V_62 ) ;
F_54 ( & V_7 -> V_43 ) ;
if ( V_63 && F_38 ( V_7 , V_2 -> V_12 ) )
F_67 ( & V_7 -> V_59 ) ;
}
void F_68 ( struct V_6 * V_7 , struct V_8 * V_62 )
{
struct V_1 * V_2 , * V_23 ;
unsigned V_3 ;
F_14 () ;
V_2 = F_15 ( V_7 -> V_24 , V_7 ) ;
V_23 = F_15 ( V_7 -> V_2 , V_7 ) ;
V_3 = F_4 ( V_7 , F_2 ( V_7 , V_62 ) ) ;
F_41 ( V_2 , V_23 , V_3 ) ;
F_65 ( V_7 , V_62 , V_2 , V_23 , V_3 ) ;
F_44 ( V_2 , V_23 , V_3 ) ;
F_16 () ;
}
bool F_69 ( struct V_6 * V_7 , struct V_8 * V_62 )
{
struct V_1 * V_2 , * V_47 , * V_23 ;
struct V_8 T_3 * * V_29 ;
struct V_8 * V_9 , * V_65 ;
unsigned int V_3 , V_50 ;
bool V_66 = false ;
F_14 () ;
V_23 = F_15 ( V_7 -> V_2 , V_7 ) ;
V_2 = V_47 = F_15 ( V_7 -> V_24 , V_7 ) ;
V_50 = F_4 ( V_7 , F_2 ( V_7 , V_62 ) ) ;
F_41 ( V_47 , V_23 , V_50 ) ;
V_67:
V_3 = F_3 ( V_2 , V_50 ) ;
V_29 = & V_2 -> V_30 [ V_3 ] ;
F_56 (he, tbl, hash) {
if ( V_9 != V_62 ) {
V_29 = & V_9 -> V_31 ;
continue;
}
F_47 ( V_7 , V_2 , V_3 ) ;
if ( V_23 -> V_12 > V_47 -> V_12 && V_2 == V_23 &&
! F_21 ( V_62 -> V_31 ) &&
F_7 ( V_7 , V_2 , V_62 -> V_31 ) != V_3 ) {
F_49 ( * V_29 , (struct V_8 * ) F_70 ( V_7 , V_3 ) ) ;
} else if ( F_5 ( V_23 -> V_12 < V_47 -> V_12 && V_2 == V_47 ) ) {
F_48 (he2, obj->next, tbl, hash) {
if ( F_7 ( V_7 , V_2 , V_65 ) == V_3 ) {
F_49 ( * V_29 , V_65 ) ;
goto V_68;
}
}
F_49 ( * V_29 , (struct V_8 * ) F_70 ( V_7 , V_3 ) ) ;
} else {
F_49 ( * V_29 , V_62 -> V_31 ) ;
}
V_68:
V_66 = true ;
break;
}
if ( V_2 != V_23 ) {
V_2 = V_23 ;
goto V_67;
}
F_44 ( V_47 , V_23 , V_50 ) ;
if ( V_66 ) {
bool V_63 = V_47 == V_23 ;
F_59 ( & V_7 -> V_43 ) ;
if ( V_63 && F_40 ( V_7 , V_47 -> V_12 ) )
F_67 ( & V_7 -> V_59 ) ;
}
F_16 () ;
return V_66 ;
}
static bool F_71 ( void * V_13 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
struct V_6 * V_7 = V_71 -> V_7 ;
return ! memcmp ( V_13 + V_7 -> V_10 . V_18 , V_71 -> V_20 , V_7 -> V_10 . V_14 ) ;
}
void * F_72 ( struct V_6 * V_7 , const void * V_20 )
{
struct V_70 V_69 = {
. V_7 = V_7 ,
. V_20 = V_20 ,
} ;
F_73 ( ! V_7 -> V_10 . V_14 ) ;
return F_74 ( V_7 , V_20 , & F_71 , & V_69 ) ;
}
void * F_74 ( struct V_6 * V_7 , const void * V_20 ,
bool (* F_75)( void * , void * ) , void * V_69 )
{
const struct V_1 * V_2 , * V_23 ;
struct V_8 * V_9 ;
T_2 V_3 ;
F_14 () ;
V_23 = F_15 ( V_7 -> V_2 , V_7 ) ;
V_2 = F_15 ( V_7 -> V_24 , V_7 ) ;
V_3 = F_6 ( V_7 , V_20 , V_7 -> V_10 . V_14 ) ;
V_67:
F_10 (he, tbl, rht_bucket_index(tbl, hash)) {
if ( ! F_75 ( F_2 ( V_7 , V_9 ) , V_69 ) )
continue;
F_16 () ;
return F_2 ( V_7 , V_9 ) ;
}
if ( F_5 ( V_2 != V_23 ) ) {
V_2 = V_23 ;
goto V_67;
}
F_16 () ;
return NULL ;
}
bool F_76 ( struct V_6 * V_7 , struct V_8 * V_62 )
{
struct V_70 V_69 = {
. V_7 = V_7 ,
. V_20 = F_2 ( V_7 , V_62 ) + V_7 -> V_10 . V_18 ,
} ;
F_73 ( ! V_7 -> V_10 . V_14 ) ;
return F_77 ( V_7 , V_62 , & F_71 ,
& V_69 ) ;
}
bool F_77 ( struct V_6 * V_7 ,
struct V_8 * V_62 ,
bool (* F_75)( void * , void * ) ,
void * V_69 )
{
struct V_1 * V_47 , * V_23 ;
T_2 V_50 ;
bool V_72 = true ;
F_73 ( ! V_7 -> V_10 . V_14 ) ;
F_14 () ;
V_23 = F_15 ( V_7 -> V_2 , V_7 ) ;
V_47 = F_15 ( V_7 -> V_24 , V_7 ) ;
V_50 = F_4 ( V_7 , F_2 ( V_7 , V_62 ) ) ;
F_41 ( V_47 , V_23 , V_50 ) ;
if ( F_74 ( V_7 , F_2 ( V_7 , V_62 ) + V_7 -> V_10 . V_18 ,
F_75 , V_69 ) ) {
V_72 = false ;
goto exit;
}
F_65 ( V_7 , V_62 , V_47 , V_23 , V_50 ) ;
exit:
F_44 ( V_47 , V_23 , V_50 ) ;
F_16 () ;
return V_72 ;
}
int F_78 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
V_74 -> V_7 = V_7 ;
V_74 -> V_10 = NULL ;
V_74 -> V_75 = 0 ;
V_74 -> V_76 = 0 ;
V_74 -> V_58 = F_79 ( sizeof( * V_74 -> V_58 ) , V_36 ) ;
if ( ! V_74 -> V_58 )
return - V_37 ;
F_80 ( & V_74 -> V_58 -> V_77 ) ;
V_74 -> V_58 -> V_61 = false ;
F_62 ( & V_7 -> V_26 ) ;
F_81 ( & V_74 -> V_58 -> V_77 , & V_7 -> V_78 ) ;
F_64 ( & V_7 -> V_26 ) ;
return 0 ;
}
void F_82 ( struct V_73 * V_74 )
{
F_62 ( & V_74 -> V_7 -> V_26 ) ;
F_83 ( & V_74 -> V_58 -> V_77 ) ;
F_64 ( & V_74 -> V_7 -> V_26 ) ;
F_84 ( V_74 -> V_58 ) ;
}
int F_85 ( struct V_73 * V_74 )
{
F_14 () ;
if ( V_74 -> V_58 -> V_61 ) {
V_74 -> V_75 = 0 ;
V_74 -> V_76 = 0 ;
V_74 -> V_58 -> V_61 = false ;
return - V_79 ;
}
return 0 ;
}
void * F_86 ( struct V_73 * V_74 )
{
const struct V_1 * V_2 ;
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_8 * V_10 = V_74 -> V_10 ;
void * V_62 = NULL ;
V_2 = F_15 ( V_7 -> V_2 , V_7 ) ;
if ( V_10 ) {
V_10 = F_87 ( V_10 -> V_31 , V_2 , V_74 -> V_75 ) ;
goto V_31;
}
for (; V_74 -> V_75 < V_2 -> V_12 ; V_74 -> V_75 ++ ) {
int V_76 = V_74 -> V_76 ;
F_10 (p, tbl, iter->slot) {
if ( ! V_76 )
break;
V_76 -- ;
}
V_31:
if ( ! F_21 ( V_10 ) ) {
V_74 -> V_76 ++ ;
V_74 -> V_10 = V_10 ;
V_62 = F_2 ( V_7 , V_10 ) ;
goto V_80;
}
V_74 -> V_76 = 0 ;
}
V_74 -> V_10 = NULL ;
V_80:
if ( V_74 -> V_58 -> V_61 ) {
V_74 -> V_10 = NULL ;
V_74 -> V_75 = 0 ;
V_74 -> V_76 = 0 ;
V_74 -> V_58 -> V_61 = false ;
return F_88 ( - V_79 ) ;
}
return V_62 ;
}
void F_89 ( struct V_73 * V_74 )
{
F_16 () ;
V_74 -> V_10 = NULL ;
}
static T_4 F_90 ( struct V_81 * V_82 )
{
return F_91 ( F_27 ( V_82 -> V_83 * 4 / 3 ) ,
1UL << V_82 -> V_46 ) ;
}
int F_92 ( struct V_6 * V_7 , struct V_81 * V_82 )
{
struct V_1 * V_2 ;
T_4 V_12 ;
V_12 = V_84 ;
if ( ( V_82 -> V_14 && ! V_82 -> V_17 ) ||
( ! V_82 -> V_14 && ! V_82 -> V_15 ) )
return - V_85 ;
if ( V_82 -> V_86 && V_82 -> V_86 < ( 1U << V_87 ) )
return - V_85 ;
V_82 -> V_46 = F_93 ( T_4 , V_82 -> V_46 ,
F_94 ( V_88 ) ) ;
if ( V_82 -> V_83 )
V_12 = F_90 ( V_82 ) ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_95 ( & V_7 -> V_26 ) ;
memcpy ( & V_7 -> V_10 , V_82 , sizeof( * V_82 ) ) ;
F_80 ( & V_7 -> V_78 ) ;
if ( V_82 -> V_34 )
V_7 -> V_10 . V_34 = F_27 ( V_82 -> V_34 ) ;
else
V_7 -> V_10 . V_34 = V_89 ;
V_2 = F_34 ( V_7 , V_12 ) ;
if ( V_2 == NULL )
return - V_37 ;
F_96 ( & V_7 -> V_43 , 0 ) ;
F_96 ( & V_7 -> V_45 , F_94 ( V_2 -> V_12 ) ) ;
F_66 ( V_7 -> V_2 , V_2 ) ;
F_66 ( V_7 -> V_24 , V_2 ) ;
if ( ! V_7 -> V_10 . V_16 )
F_97 ( & V_7 -> V_10 . V_16 , sizeof( V_7 -> V_10 . V_16 ) ) ;
F_98 ( & V_7 -> V_59 , F_60 ) ;
return 0 ;
}
void F_99 ( struct V_6 * V_7 )
{
V_7 -> V_54 = true ;
F_100 ( & V_7 -> V_59 ) ;
F_62 ( & V_7 -> V_26 ) ;
F_32 ( F_52 ( V_7 -> V_2 , V_7 ) ) ;
F_64 ( & V_7 -> V_26 ) ;
}
