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
V_16 = F_10 (unsigned int, nr_pcpus, 32UL ) ;
V_14 = F_11 ( V_16 * V_2 -> V_7 . V_17 ) ;
V_14 = F_10 (unsigned int, size, tbl->size >> 1 ) ;
if ( sizeof( T_2 ) != 0 ) {
#ifdef F_12
if ( V_14 * sizeof( T_2 ) > V_18 &&
V_12 == V_19 )
V_4 -> V_20 = F_13 ( V_14 * sizeof( T_2 ) ) ;
else
#endif
V_4 -> V_20 = F_14 ( V_14 , sizeof( T_2 ) ,
V_12 ) ;
if ( ! V_4 -> V_20 )
return - V_21 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_15 ( & V_4 -> V_20 [ V_13 ] ) ;
}
V_4 -> V_22 = V_14 - 1 ;
return 0 ;
}
static void F_16 ( const struct V_3 * V_4 )
{
if ( V_4 )
F_17 ( V_4 -> V_20 ) ;
F_17 ( V_4 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
F_16 ( F_19 ( V_24 , struct V_3 , V_25 ) ) ;
}
static struct V_3 * F_20 ( struct V_1 * V_2 ,
T_4 V_26 ,
T_3 V_12 )
{
struct V_3 * V_4 = NULL ;
T_4 V_14 ;
int V_13 ;
V_14 = sizeof( * V_4 ) + V_26 * sizeof( V_4 -> V_27 [ 0 ] ) ;
if ( V_14 <= ( V_18 << V_28 ) ||
V_12 != V_19 )
V_4 = F_21 ( V_14 , V_12 | V_29 | V_30 ) ;
if ( V_4 == NULL && V_12 == V_19 )
V_4 = F_22 ( V_14 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_14 = V_26 ;
if ( F_7 ( V_2 , V_4 , V_12 ) < 0 ) {
F_16 ( V_4 ) ;
return NULL ;
}
F_23 ( & V_4 -> V_31 ) ;
F_24 ( & V_4 -> V_32 , sizeof( V_4 -> V_32 ) ) ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ )
F_25 ( V_4 -> V_27 [ V_13 ] , V_2 , V_13 ) ;
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
struct V_5 T_5 * * V_37 = & V_36 -> V_27 [ V_35 ] ;
int V_38 = - V_39 ;
struct V_5 * V_24 , * V_40 , * V_41 ;
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
V_24 = F_31 ( V_33 -> V_27 [ V_43 ] ,
V_33 , V_43 ) ;
if ( F_32 ( V_24 ) )
F_25 ( V_41 -> V_40 , V_2 , V_43 ) ;
else
F_34 ( V_41 -> V_40 , V_24 ) ;
F_35 ( V_33 -> V_27 [ V_43 ] , V_41 ) ;
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
F_38 ( V_36 -> V_20 ) ;
if ( F_41 ( V_36 -> V_34 ) ) {
F_39 ( V_36 -> V_20 ) ;
return - V_48 ;
}
F_35 ( V_36 -> V_34 , V_33 ) ;
F_42 () ;
F_39 ( V_36 -> V_20 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
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
F_44 ( & V_2 -> V_11 ) ;
F_45 (walker, &old_tbl->walkers, list)
V_50 -> V_4 = NULL ;
F_36 ( & V_2 -> V_11 ) ;
F_46 ( & V_36 -> V_25 , F_18 ) ;
return F_29 ( V_33 -> V_34 , V_2 ) ? - V_51 : 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_33 , * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
int V_38 ;
F_48 ( V_2 ) ;
V_36 = F_26 ( V_2 , V_36 ) ;
V_33 = F_20 ( V_2 , V_36 -> V_14 * 2 , V_19 ) ;
if ( V_33 == NULL )
return - V_21 ;
V_38 = F_40 ( V_2 , V_36 , V_33 ) ;
if ( V_38 )
F_16 ( V_33 ) ;
return V_38 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_33 , * V_36 = F_29 ( V_2 -> V_4 , V_2 ) ;
unsigned int V_14 ;
int V_38 ;
F_48 ( V_2 ) ;
V_14 = F_11 ( F_50 ( & V_2 -> V_52 ) * 3 / 2 ) ;
if ( V_14 < V_2 -> V_7 . V_53 )
V_14 = V_2 -> V_7 . V_53 ;
if ( V_36 -> V_14 <= V_14 )
return 0 ;
if ( F_29 ( V_36 -> V_34 , V_2 ) )
return - V_48 ;
V_33 = F_20 ( V_2 , V_14 , V_19 ) ;
if ( V_33 == NULL )
return - V_21 ;
V_38 = F_40 ( V_2 , V_36 , V_33 ) ;
if ( V_38 )
F_16 ( V_33 ) ;
return V_38 ;
}
static void F_51 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_38 = 0 ;
V_2 = F_19 ( V_55 , struct V_1 , V_56 ) ;
F_52 ( & V_2 -> V_9 ) ;
V_4 = F_29 ( V_2 -> V_4 , V_2 ) ;
V_4 = F_26 ( V_2 , V_4 ) ;
if ( F_53 ( V_2 , V_4 ) )
F_47 ( V_2 ) ;
else if ( V_2 -> V_7 . V_57 && F_54 ( V_2 , V_4 ) )
F_49 ( V_2 ) ;
V_38 = F_43 ( V_2 ) ;
F_55 ( & V_2 -> V_9 ) ;
if ( V_38 )
F_56 ( & V_2 -> V_56 ) ;
}
static bool F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 )
{
unsigned int V_58 = V_2 -> V_58 ;
struct V_5 * V_24 ;
F_30 (head, tbl, hash)
if ( ! -- V_58 )
return true ;
return false ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_36 ;
struct V_3 * V_33 ;
struct V_3 * V_4 ;
unsigned int V_14 ;
int V_38 ;
V_36 = F_27 ( V_2 -> V_4 , V_2 ) ;
V_4 = F_26 ( V_2 , V_36 ) ;
V_14 = V_4 -> V_14 ;
if ( F_53 ( V_2 , V_4 ) )
V_14 *= 2 ;
else if ( V_36 != V_4 )
return - V_59 ;
V_33 = F_20 ( V_2 , V_14 , V_60 ) ;
if ( V_33 == NULL ) {
F_56 ( & V_2 -> V_56 ) ;
return - V_21 ;
}
V_38 = F_40 ( V_2 , V_4 , V_33 ) ;
if ( V_38 ) {
F_16 ( V_33 ) ;
if ( V_38 == - V_48 )
V_38 = 0 ;
} else
F_56 ( & V_2 -> V_56 ) ;
return V_38 ;
}
int F_59 ( struct V_1 * V_2 , const void * V_61 ,
struct V_5 * V_62 ,
struct V_3 * V_4 )
{
struct V_5 * V_24 ;
unsigned int V_10 ;
int V_38 ;
V_4 = F_26 ( V_2 , V_4 ) ;
V_10 = F_1 ( V_2 , V_4 , V_62 ) ;
F_33 ( F_6 ( V_4 , V_10 ) , V_45 ) ;
V_38 = - V_48 ;
if ( V_61 && F_60 ( V_2 , V_61 , V_2 -> V_7 ) )
goto exit;
V_38 = - V_63 ;
if ( F_61 ( F_62 ( V_2 , V_4 ) ) )
goto exit;
V_38 = - V_51 ;
if ( F_57 ( V_2 , V_4 , V_10 ) ||
F_63 ( V_2 , V_4 ) )
goto exit;
V_38 = 0 ;
V_24 = F_31 ( V_4 -> V_27 [ V_10 ] , V_4 , V_10 ) ;
F_34 ( V_62 -> V_40 , V_24 ) ;
F_35 ( V_4 -> V_27 [ V_10 ] , V_62 ) ;
F_64 ( & V_2 -> V_52 ) ;
exit:
F_36 ( F_6 ( V_4 , V_10 ) ) ;
return V_38 ;
}
int F_65 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
V_65 -> V_2 = V_2 ;
V_65 -> V_7 = NULL ;
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
V_65 -> V_50 = F_66 ( sizeof( * V_65 -> V_50 ) , V_19 ) ;
if ( ! V_65 -> V_50 )
return - V_21 ;
F_52 ( & V_2 -> V_9 ) ;
V_65 -> V_50 -> V_4 = F_29 ( V_2 -> V_4 , V_2 ) ;
F_67 ( & V_65 -> V_50 -> V_68 , & V_65 -> V_50 -> V_4 -> V_31 ) ;
F_55 ( & V_2 -> V_9 ) ;
return 0 ;
}
void F_68 ( struct V_64 * V_65 )
{
F_52 ( & V_65 -> V_2 -> V_9 ) ;
if ( V_65 -> V_50 -> V_4 )
F_69 ( & V_65 -> V_50 -> V_68 ) ;
F_55 ( & V_65 -> V_2 -> V_9 ) ;
F_70 ( V_65 -> V_50 ) ;
}
int F_71 ( struct V_64 * V_65 )
__acquires( T_6 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
F_52 ( & V_2 -> V_9 ) ;
if ( V_65 -> V_50 -> V_4 )
F_69 ( & V_65 -> V_50 -> V_68 ) ;
F_72 () ;
F_55 ( & V_2 -> V_9 ) ;
if ( ! V_65 -> V_50 -> V_4 ) {
V_65 -> V_50 -> V_4 = F_27 ( V_2 -> V_4 , V_2 ) ;
return - V_51 ;
}
return 0 ;
}
void * F_73 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = V_65 -> V_50 -> V_4 ;
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_5 * V_7 = V_65 -> V_7 ;
void * V_62 = NULL ;
if ( V_7 ) {
V_7 = F_74 ( V_7 -> V_40 , V_4 , V_65 -> V_66 ) ;
goto V_40;
}
for (; V_65 -> V_66 < V_4 -> V_14 ; V_65 -> V_66 ++ ) {
int V_67 = V_65 -> V_67 ;
F_75 (p, tbl, iter->slot) {
if ( ! V_67 )
break;
V_67 -- ;
}
V_40:
if ( ! F_32 ( V_7 ) ) {
V_65 -> V_67 ++ ;
V_65 -> V_7 = V_7 ;
V_62 = F_76 ( V_2 , V_7 ) ;
goto V_44;
}
V_65 -> V_67 = 0 ;
}
F_77 () ;
V_65 -> V_50 -> V_4 = F_27 ( V_4 -> V_34 , V_2 ) ;
if ( V_65 -> V_50 -> V_4 ) {
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
return F_78 ( - V_51 ) ;
}
V_65 -> V_7 = NULL ;
V_44:
return V_62 ;
}
void F_79 ( struct V_64 * V_65 )
__releases( T_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = V_65 -> V_50 -> V_4 ;
if ( ! V_4 )
goto V_44;
V_2 = V_65 -> V_2 ;
F_44 ( & V_2 -> V_11 ) ;
if ( V_4 -> V_47 < V_4 -> V_14 )
F_67 ( & V_65 -> V_50 -> V_68 , & V_4 -> V_31 ) ;
else
V_65 -> V_50 -> V_4 = NULL ;
F_36 ( & V_2 -> V_11 ) ;
V_65 -> V_7 = NULL ;
V_44:
F_80 () ;
}
static T_4 F_81 ( const struct V_69 * V_70 )
{
return F_82 ( F_11 ( V_70 -> V_71 * 4 / 3 ) ,
( unsigned long ) V_70 -> V_53 ) ;
}
static T_1 F_83 ( const void * V_61 , T_1 V_72 , T_1 V_73 )
{
return F_84 ( V_61 , V_72 , V_73 ) ;
}
int F_85 ( struct V_1 * V_2 ,
const struct V_69 * V_70 )
{
struct V_3 * V_4 ;
T_4 V_14 ;
V_14 = V_74 ;
if ( ( ! V_70 -> V_75 && ! V_70 -> V_76 ) ||
( V_70 -> V_76 && ! V_70 -> V_77 ) )
return - V_78 ;
if ( V_70 -> V_79 && V_70 -> V_79 < ( 1U << V_80 ) )
return - V_78 ;
if ( V_70 -> V_71 )
V_14 = F_81 ( V_70 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_86 ( & V_2 -> V_9 ) ;
F_15 ( & V_2 -> V_11 ) ;
memcpy ( & V_2 -> V_7 , V_70 , sizeof( * V_70 ) ) ;
if ( V_70 -> V_53 )
V_2 -> V_7 . V_53 = F_11 ( V_70 -> V_53 ) ;
if ( V_70 -> V_81 )
V_2 -> V_7 . V_81 = F_87 ( V_70 -> V_81 ) ;
if ( V_70 -> V_82 )
V_2 -> V_7 . V_82 =
F_87 ( V_70 -> V_82 ) ;
else
V_2 -> V_7 . V_82 = V_2 -> V_7 . V_81 * 2 ;
V_2 -> V_7 . V_53 = F_82 ( V_2 -> V_7 . V_53 , V_83 ) ;
if ( ! V_70 -> V_84 )
V_2 -> V_58 = 16 ;
if ( V_70 -> V_17 )
V_2 -> V_7 . V_17 = F_11 ( V_70 -> V_17 ) ;
else
V_2 -> V_7 . V_17 = V_85 ;
V_2 -> V_75 = V_2 -> V_7 . V_75 ;
if ( ! V_70 -> V_86 ) {
V_2 -> V_7 . V_86 = V_87 ;
if ( ! ( V_2 -> V_75 & ( sizeof( T_1 ) - 1 ) ) ) {
V_2 -> V_75 /= sizeof( T_1 ) ;
V_2 -> V_7 . V_86 = F_83 ;
}
}
V_4 = F_20 ( V_2 , V_14 , V_19 ) ;
if ( V_4 == NULL )
return - V_21 ;
F_88 ( & V_2 -> V_52 , 0 ) ;
F_34 ( V_2 -> V_4 , V_4 ) ;
F_89 ( & V_2 -> V_56 , F_51 ) ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 ,
void (* F_91)( void * V_88 , void * V_89 ) ,
void * V_89 )
{
const struct V_3 * V_4 ;
unsigned int V_13 ;
F_92 ( & V_2 -> V_56 ) ;
F_52 ( & V_2 -> V_9 ) ;
V_4 = F_29 ( V_2 -> V_4 , V_2 ) ;
if ( F_91 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_14 ; V_13 ++ ) {
struct V_5 * V_90 , * V_40 ;
for ( V_90 = F_29 ( V_4 -> V_27 [ V_13 ] , V_2 ) ,
V_40 = ! F_32 ( V_90 ) ?
F_29 ( V_90 -> V_40 , V_2 ) : NULL ;
! F_32 ( V_90 ) ;
V_90 = V_40 ,
V_40 = ! F_32 ( V_90 ) ?
F_29 ( V_90 -> V_40 , V_2 ) : NULL )
F_91 ( F_76 ( V_2 , V_90 ) , V_89 ) ;
}
}
F_16 ( V_4 ) ;
F_55 ( & V_2 -> V_9 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
return F_90 ( V_2 , NULL , NULL ) ;
}
