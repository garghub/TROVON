static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (e, &set->list, list) {
if ( V_6 -> V_5 == V_5 )
return NULL ;
}
V_6 = F_3 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
F_4 ( & V_5 -> V_8 ) ;
V_6 -> V_5 = V_5 ;
F_5 ( & V_6 -> V_9 , & V_3 -> V_9 ) ;
F_4 ( & V_3 -> V_10 ) ;
V_3 -> V_11 = V_12 ;
return V_6 ;
}
static void
F_6 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (e, &set->list, list) {
if ( V_6 -> V_5 == V_5 ) {
F_7 ( & V_3 -> V_10 ) ;
V_3 -> V_11 = V_12 ;
F_7 ( & V_6 -> V_5 -> V_8 ) ;
F_8 ( & V_6 -> V_9 ) ;
F_9 ( V_6 ) ;
break;
}
}
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_6 , * V_13 ;
F_11 ( & V_3 -> V_14 ) ;
F_12 (e, ep, &set->list, list) {
F_7 ( & V_6 -> V_5 -> V_8 ) ;
F_8 ( & V_6 -> V_9 ) ;
F_9 ( V_6 ) ;
}
F_13 ( & V_3 -> V_14 ) ;
}
static inline struct V_4 * F_14 ( struct V_2 * V_3 )
{
register struct V_1 * V_6 ;
struct V_4 * V_5 , * V_15 ;
int V_16 , V_17 ;
if ( V_3 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_15 = V_6 -> V_5 ;
if ( V_15 -> V_18 & V_19 )
continue;
if ( ( F_15 ( & V_15 -> V_20 ) > 0 )
&& ( V_15 -> V_18 & V_21 ) ) {
V_16 = F_16 ( V_15 ) ;
goto V_22;
}
}
return NULL ;
V_22:
F_2 (e, &set->list, list) {
V_5 = V_6 -> V_5 ;
if ( V_5 -> V_18 & V_19 )
continue;
V_17 = F_16 ( V_5 ) ;
if ( ( V_16 * F_15 ( & V_5 -> V_20 ) >
V_17 * F_15 ( & V_15 -> V_20 ) )
&& ( V_5 -> V_18 & V_21 ) ) {
V_15 = V_5 ;
V_16 = V_17 ;
}
}
F_17 ( 6 , L_1
L_2 ,
V_23 ,
F_18 ( V_15 -> V_24 , & V_15 -> V_25 ) ,
F_19 ( V_15 -> V_26 ) ,
F_15 ( & V_15 -> V_27 ) ,
F_15 ( & V_15 -> V_8 ) ,
F_15 ( & V_15 -> V_20 ) , V_16 ) ;
return V_15 ;
}
static inline struct V_4 * F_20 ( struct V_2 * V_3 )
{
register struct V_1 * V_6 ;
struct V_4 * V_5 , * V_28 ;
int V_29 , V_17 ;
if ( V_3 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_28 = V_6 -> V_5 ;
if ( F_15 ( & V_28 -> V_20 ) > 0 ) {
V_29 = F_16 ( V_28 ) ;
goto V_22;
}
}
return NULL ;
V_22:
F_2 (e, &set->list, list) {
V_5 = V_6 -> V_5 ;
V_17 = F_16 ( V_5 ) ;
if ( ( V_29 * F_15 ( & V_5 -> V_20 ) <
V_17 * F_15 ( & V_28 -> V_20 ) )
&& ( F_15 ( & V_5 -> V_20 ) > 0 ) ) {
V_28 = V_5 ;
V_29 = V_17 ;
}
}
F_17 ( 6 , L_1
L_2 ,
V_23 ,
F_18 ( V_28 -> V_24 , & V_28 -> V_25 ) , F_19 ( V_28 -> V_26 ) ,
F_15 ( & V_28 -> V_27 ) ,
F_15 ( & V_28 -> V_8 ) ,
F_15 ( & V_28 -> V_20 ) , V_29 ) ;
return V_28 ;
}
static inline void F_21 ( struct V_30 * V_31 )
{
F_8 ( & V_31 -> V_9 ) ;
F_10 ( & V_31 -> V_3 ) ;
F_9 ( V_31 ) ;
}
static inline unsigned
F_22 ( int V_24 , const union V_32 * V_25 )
{
T_1 V_33 = V_25 -> V_34 ;
#ifdef F_23
if ( V_24 == V_35 )
V_33 = V_25 -> V_36 [ 0 ] ^ V_25 -> V_36 [ 1 ] ^
V_25 -> V_36 [ 2 ] ^ V_25 -> V_36 [ 3 ] ;
#endif
return ( F_24 ( V_33 ) * 2654435761UL ) & V_37 ;
}
static void
F_25 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned V_40 = F_22 ( V_31 -> V_24 , & V_31 -> V_25 ) ;
F_5 ( & V_31 -> V_9 , & V_39 -> V_41 [ V_40 ] ) ;
F_4 ( & V_39 -> V_42 ) ;
}
static inline struct V_30 *
F_26 ( int V_24 , struct V_38 * V_39 ,
const union V_32 * V_25 )
{
unsigned V_40 = F_22 ( V_24 , V_25 ) ;
struct V_30 * V_31 ;
F_2 (en, &tbl->bucket[hash], list)
if ( F_27 ( V_24 , & V_31 -> V_25 , V_25 ) )
return V_31 ;
return NULL ;
}
static inline struct V_30 *
F_28 ( struct V_38 * V_39 , const union V_32 * V_43 ,
struct V_4 * V_5 )
{
struct V_30 * V_31 ;
V_31 = F_26 ( V_5 -> V_24 , V_39 , V_43 ) ;
if ( ! V_31 ) {
V_31 = F_3 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_24 = V_5 -> V_24 ;
F_29 ( V_5 -> V_24 , & V_31 -> V_25 , V_43 ) ;
V_31 -> V_44 = V_12 ;
F_30 ( & ( V_31 -> V_3 . V_10 ) , 0 ) ;
F_31 ( & V_31 -> V_3 . V_9 ) ;
F_32 ( & V_31 -> V_3 . V_14 ) ;
F_25 ( V_39 , V_31 ) ;
}
F_11 ( & V_31 -> V_3 . V_14 ) ;
F_1 ( & V_31 -> V_3 , V_5 ) ;
F_13 ( & V_31 -> V_3 . V_14 ) ;
return V_31 ;
}
static void F_33 ( struct V_38 * V_39 )
{
int V_45 ;
struct V_30 * V_31 , * V_46 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
F_12 (en, nxt, &tbl->bucket[i], list) {
F_21 ( V_31 ) ;
}
}
}
static int F_34 ( struct V_48 * V_49 )
{
#ifdef F_35
struct V_50 * V_51 = F_36 ( V_49 -> V_52 ) ;
return V_51 -> F_34 ;
#else
return V_53 ;
#endif
}
static inline void F_37 ( struct V_48 * V_49 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
unsigned long V_55 = V_12 ;
int V_45 , V_56 ;
struct V_30 * V_31 , * V_46 ;
for ( V_45 = 0 , V_56 = V_39 -> V_57 ; V_45 < V_47 ; V_45 ++ ) {
V_56 = ( V_56 + 1 ) & V_37 ;
F_11 ( & V_49 -> V_58 ) ;
F_12 (en, nxt, &tbl->bucket[j], list) {
if ( F_38 ( V_31 -> V_44 +
F_34 ( V_49 ) , V_55 ) )
continue;
F_21 ( V_31 ) ;
F_7 ( & V_39 -> V_42 ) ;
}
F_13 ( & V_49 -> V_58 ) ;
}
V_39 -> V_57 = V_56 ;
}
static void F_39 ( unsigned long V_59 )
{
struct V_48 * V_49 = (struct V_48 * ) V_59 ;
struct V_38 * V_39 = V_49 -> V_54 ;
unsigned long V_55 = V_12 ;
int V_60 ;
int V_45 , V_56 ;
struct V_30 * V_31 , * V_46 ;
if ( ( V_39 -> V_61 % V_62 ) == 0 ) {
F_37 ( V_49 ) ;
V_39 -> V_61 = 1 ;
goto V_63;
}
if ( F_15 ( & V_39 -> V_42 ) <= V_39 -> V_64 ) {
V_39 -> V_61 ++ ;
goto V_63;
}
V_60 = ( F_15 ( & V_39 -> V_42 ) - V_39 -> V_64 ) * 4 / 3 ;
if ( V_60 > V_39 -> V_64 / 2 )
V_60 = V_39 -> V_64 / 2 ;
for ( V_45 = 0 , V_56 = V_39 -> V_57 ; V_45 < V_47 ; V_45 ++ ) {
V_56 = ( V_56 + 1 ) & V_37 ;
F_11 ( & V_49 -> V_58 ) ;
F_12 (en, nxt, &tbl->bucket[j], list) {
if ( F_40 ( V_55 , V_31 -> V_44 + V_65 ) )
continue;
F_21 ( V_31 ) ;
F_7 ( & V_39 -> V_42 ) ;
V_60 -- ;
}
F_13 ( & V_49 -> V_58 ) ;
if ( V_60 <= 0 )
break;
}
V_39 -> V_57 = V_56 ;
V_63:
F_41 ( & V_39 -> V_66 , V_12 + V_67 ) ;
}
static int F_42 ( struct V_48 * V_49 )
{
int V_45 ;
struct V_38 * V_39 ;
V_39 = F_3 ( sizeof( * V_39 ) , V_7 ) ;
if ( V_39 == NULL )
return - V_68 ;
V_49 -> V_54 = V_39 ;
F_43 ( 6 , L_3
L_4 , sizeof( * V_39 ) ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
F_31 ( & V_39 -> V_41 [ V_45 ] ) ;
}
V_39 -> V_64 = V_47 * 16 ;
V_39 -> V_57 = 0 ;
V_39 -> V_61 = 1 ;
F_44 ( & V_39 -> V_66 , F_39 ,
( unsigned long ) V_49 ) ;
F_41 ( & V_39 -> V_66 , V_12 + V_67 ) ;
return 0 ;
}
static int F_45 ( struct V_48 * V_49 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
F_46 ( & V_39 -> V_66 ) ;
F_33 ( V_39 ) ;
F_9 ( V_39 ) ;
F_43 ( 6 , L_5 ,
sizeof( * V_39 ) ) ;
return 0 ;
}
static inline struct V_4 *
F_47 ( struct V_48 * V_49 )
{
struct V_4 * V_5 , * V_15 ;
int V_16 , V_17 ;
F_2 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_18 & V_19 )
continue;
if ( F_15 ( & V_5 -> V_20 ) > 0 ) {
V_15 = V_5 ;
V_16 = F_16 ( V_15 ) ;
goto V_22;
}
}
return NULL ;
V_22:
F_48 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_18 & V_19 )
continue;
V_17 = F_16 ( V_5 ) ;
if ( V_16 * F_15 ( & V_5 -> V_20 ) >
V_17 * F_15 ( & V_15 -> V_20 ) ) {
V_15 = V_5 ;
V_16 = V_17 ;
}
}
F_17 ( 6 , L_6
L_2 ,
F_18 ( V_15 -> V_24 , & V_15 -> V_25 ) ,
F_19 ( V_15 -> V_26 ) ,
F_15 ( & V_15 -> V_27 ) ,
F_15 ( & V_15 -> V_8 ) ,
F_15 ( & V_15 -> V_20 ) , V_16 ) ;
return V_15 ;
}
static inline int
F_49 ( struct V_4 * V_5 , struct V_48 * V_49 )
{
if ( F_15 ( & V_5 -> V_27 ) > F_15 ( & V_5 -> V_20 ) ) {
struct V_4 * V_69 ;
F_2 (d, &svc->destinations, n_list) {
if ( F_15 ( & V_69 -> V_27 ) * 2
< F_15 ( & V_69 -> V_20 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_4 *
F_50 ( struct V_48 * V_49 , const struct V_70 * V_71 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
struct V_72 V_73 ;
struct V_4 * V_5 = NULL ;
struct V_30 * V_31 ;
F_51 ( V_49 -> V_24 , F_52 ( V_71 ) , & V_73 ) ;
F_43 ( 6 , L_7 , V_23 ) ;
F_53 ( & V_49 -> V_58 ) ;
V_31 = F_26 ( V_49 -> V_24 , V_39 , & V_73 . V_43 ) ;
if ( V_31 ) {
V_31 -> V_44 = V_12 ;
F_53 ( & V_31 -> V_3 . V_14 ) ;
V_5 = F_14 ( & V_31 -> V_3 ) ;
F_54 ( & V_31 -> V_3 . V_14 ) ;
if ( F_15 ( & V_31 -> V_3 . V_10 ) > 1 &&
F_38 ( V_12 , V_31 -> V_3 . V_11 +
F_34 ( V_49 ) ) ) {
struct V_4 * V_74 ;
F_11 ( & V_31 -> V_3 . V_14 ) ;
V_74 = F_20 ( & V_31 -> V_3 ) ;
if ( V_74 )
F_6 ( & V_31 -> V_3 , V_74 ) ;
F_13 ( & V_31 -> V_3 . V_14 ) ;
}
if ( V_5 && ! F_49 ( V_5 , V_49 ) ) {
F_54 ( & V_49 -> V_58 ) ;
goto V_63;
}
V_5 = F_47 ( V_49 ) ;
if ( ! V_5 ) {
F_55 ( V_49 , L_8 ) ;
F_54 ( & V_49 -> V_58 ) ;
return NULL ;
}
F_11 ( & V_31 -> V_3 . V_14 ) ;
F_1 ( & V_31 -> V_3 , V_5 ) ;
F_13 ( & V_31 -> V_3 . V_14 ) ;
}
F_54 ( & V_49 -> V_58 ) ;
if ( V_5 )
goto V_63;
V_5 = F_47 ( V_49 ) ;
if ( ! V_5 ) {
F_43 ( 1 , L_9 ) ;
return NULL ;
}
F_11 ( & V_49 -> V_58 ) ;
F_28 ( V_39 , & V_73 . V_43 , V_5 ) ;
F_13 ( & V_49 -> V_58 ) ;
V_63:
F_17 ( 6 , L_10 ,
F_18 ( V_49 -> V_24 , & V_73 . V_43 ) ,
F_18 ( V_49 -> V_24 , & V_5 -> V_25 ) , F_19 ( V_5 -> V_26 ) ) ;
return V_5 ;
}
static int T_2 F_56 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = F_36 ( V_52 ) ;
if ( ! V_51 )
return - V_75 ;
if ( ! F_57 ( V_52 , & V_76 ) ) {
V_51 -> V_77 = F_58 ( V_78 ,
sizeof( V_78 ) ,
V_79 ) ;
if ( V_51 -> V_77 == NULL )
return - V_68 ;
} else
V_51 -> V_77 = V_78 ;
V_51 -> F_34 = V_53 ;
V_51 -> V_77 [ 0 ] . V_59 = & V_51 -> F_34 ;
V_51 -> V_80 =
F_59 ( V_52 , V_81 ,
V_51 -> V_77 ) ;
if ( ! V_51 -> V_80 ) {
if ( ! F_57 ( V_52 , & V_76 ) )
F_9 ( V_51 -> V_77 ) ;
return - V_68 ;
}
return 0 ;
}
static void T_3 F_60 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = F_36 ( V_52 ) ;
F_61 ( V_51 -> V_80 ) ;
if ( ! F_57 ( V_52 , & V_76 ) )
F_9 ( V_51 -> V_77 ) ;
}
static int T_2 F_56 ( struct V_52 * V_52 ) { return 0 ; }
static void T_3 F_60 ( struct V_52 * V_52 ) { }
static int T_4 F_62 ( void )
{
int V_82 ;
V_82 = F_63 ( & V_83 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_64 ( & V_84 ) ;
if ( V_82 )
F_65 ( & V_83 ) ;
return V_82 ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_84 ) ;
F_65 ( & V_83 ) ;
}
