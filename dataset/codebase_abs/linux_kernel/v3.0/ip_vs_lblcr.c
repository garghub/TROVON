static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (e, &set->list, list) {
if ( V_6 -> V_5 == V_5 )
return NULL ;
}
V_6 = F_3 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL ) {
F_4 ( L_1 , V_8 ) ;
return NULL ;
}
F_5 ( & V_5 -> V_9 ) ;
V_6 -> V_5 = V_5 ;
F_6 ( & V_6 -> V_10 , & V_3 -> V_10 ) ;
F_5 ( & V_3 -> V_11 ) ;
V_3 -> V_12 = V_13 ;
return V_6 ;
}
static void
F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (e, &set->list, list) {
if ( V_6 -> V_5 == V_5 ) {
F_8 ( & V_3 -> V_11 ) ;
V_3 -> V_12 = V_13 ;
F_8 ( & V_6 -> V_5 -> V_9 ) ;
F_9 ( & V_6 -> V_10 ) ;
F_10 ( V_6 ) ;
break;
}
}
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 , * V_14 ;
F_12 ( & V_3 -> V_15 ) ;
F_13 (e, ep, &set->list, list) {
F_8 ( & V_6 -> V_5 -> V_9 ) ;
F_9 ( & V_6 -> V_10 ) ;
F_10 ( V_6 ) ;
}
F_14 ( & V_3 -> V_15 ) ;
}
static inline struct V_4 * F_15 ( struct V_2 * V_3 )
{
register struct V_1 * V_6 ;
struct V_4 * V_5 , * V_16 ;
int V_17 , V_18 ;
if ( V_3 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_16 = V_6 -> V_5 ;
if ( V_16 -> V_19 & V_20 )
continue;
if ( ( F_16 ( & V_16 -> V_21 ) > 0 )
&& ( V_16 -> V_19 & V_22 ) ) {
V_17 = F_17 ( V_16 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_2 (e, &set->list, list) {
V_5 = V_6 -> V_5 ;
if ( V_5 -> V_19 & V_20 )
continue;
V_18 = F_17 ( V_5 ) ;
if ( ( V_17 * F_16 ( & V_5 -> V_21 ) >
V_18 * F_16 ( & V_16 -> V_21 ) )
&& ( V_5 -> V_19 & V_22 ) ) {
V_16 = V_5 ;
V_17 = V_18 ;
}
}
F_18 ( 6 , L_2
L_3 ,
V_8 ,
F_19 ( V_16 -> V_24 , & V_16 -> V_25 ) ,
F_20 ( V_16 -> V_26 ) ,
F_16 ( & V_16 -> V_27 ) ,
F_16 ( & V_16 -> V_9 ) ,
F_16 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline struct V_4 * F_21 ( struct V_2 * V_3 )
{
register struct V_1 * V_6 ;
struct V_4 * V_5 , * V_28 ;
int V_29 , V_18 ;
if ( V_3 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_28 = V_6 -> V_5 ;
if ( F_16 ( & V_28 -> V_21 ) > 0 ) {
V_29 = F_17 ( V_28 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_2 (e, &set->list, list) {
V_5 = V_6 -> V_5 ;
V_18 = F_17 ( V_5 ) ;
if ( ( V_29 * F_16 ( & V_5 -> V_21 ) <
V_18 * F_16 ( & V_28 -> V_21 ) )
&& ( F_16 ( & V_5 -> V_21 ) > 0 ) ) {
V_28 = V_5 ;
V_29 = V_18 ;
}
}
F_18 ( 6 , L_2
L_3 ,
V_8 ,
F_19 ( V_28 -> V_24 , & V_28 -> V_25 ) , F_20 ( V_28 -> V_26 ) ,
F_16 ( & V_28 -> V_27 ) ,
F_16 ( & V_28 -> V_9 ) ,
F_16 ( & V_28 -> V_21 ) , V_29 ) ;
return V_28 ;
}
static inline void F_22 ( struct V_30 * V_31 )
{
F_9 ( & V_31 -> V_10 ) ;
F_11 ( & V_31 -> V_3 ) ;
F_10 ( V_31 ) ;
}
static inline unsigned
F_23 ( int V_24 , const union V_32 * V_25 )
{
T_1 V_33 = V_25 -> V_34 ;
#ifdef F_24
if ( V_24 == V_35 )
V_33 = V_25 -> V_36 [ 0 ] ^ V_25 -> V_36 [ 1 ] ^
V_25 -> V_36 [ 2 ] ^ V_25 -> V_36 [ 3 ] ;
#endif
return ( F_25 ( V_33 ) * 2654435761UL ) & V_37 ;
}
static void
F_26 ( struct V_38 * V_39 , struct V_30 * V_31 )
{
unsigned V_40 = F_23 ( V_31 -> V_24 , & V_31 -> V_25 ) ;
F_6 ( & V_31 -> V_10 , & V_39 -> V_41 [ V_40 ] ) ;
F_5 ( & V_39 -> V_42 ) ;
}
static inline struct V_30 *
F_27 ( int V_24 , struct V_38 * V_39 ,
const union V_32 * V_25 )
{
unsigned V_40 = F_23 ( V_24 , V_25 ) ;
struct V_30 * V_31 ;
F_2 (en, &tbl->bucket[hash], list)
if ( F_28 ( V_24 , & V_31 -> V_25 , V_25 ) )
return V_31 ;
return NULL ;
}
static inline struct V_30 *
F_29 ( struct V_38 * V_39 , const union V_32 * V_43 ,
struct V_4 * V_5 )
{
struct V_30 * V_31 ;
V_31 = F_27 ( V_5 -> V_24 , V_39 , V_43 ) ;
if ( ! V_31 ) {
V_31 = F_3 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 ) {
F_4 ( L_1 , V_8 ) ;
return NULL ;
}
V_31 -> V_24 = V_5 -> V_24 ;
F_30 ( V_5 -> V_24 , & V_31 -> V_25 , V_43 ) ;
V_31 -> V_44 = V_13 ;
F_31 ( & ( V_31 -> V_3 . V_11 ) , 0 ) ;
F_32 ( & V_31 -> V_3 . V_10 ) ;
F_33 ( & V_31 -> V_3 . V_15 ) ;
F_26 ( V_39 , V_31 ) ;
}
F_12 ( & V_31 -> V_3 . V_15 ) ;
F_1 ( & V_31 -> V_3 , V_5 ) ;
F_14 ( & V_31 -> V_3 . V_15 ) ;
return V_31 ;
}
static void F_34 ( struct V_38 * V_39 )
{
int V_45 ;
struct V_30 * V_31 , * V_46 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
F_13 (en, nxt, &tbl->bucket[i], list) {
F_22 ( V_31 ) ;
}
}
}
static int F_35 ( struct V_48 * V_49 )
{
#ifdef F_36
struct V_50 * V_51 = F_37 ( V_49 -> V_52 ) ;
return V_51 -> F_35 ;
#else
return V_53 ;
#endif
}
static inline void F_38 ( struct V_48 * V_49 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
unsigned long V_55 = V_13 ;
int V_45 , V_56 ;
struct V_30 * V_31 , * V_46 ;
for ( V_45 = 0 , V_56 = V_39 -> V_57 ; V_45 < V_47 ; V_45 ++ ) {
V_56 = ( V_56 + 1 ) & V_37 ;
F_12 ( & V_49 -> V_58 ) ;
F_13 (en, nxt, &tbl->bucket[j], list) {
if ( F_39 ( V_31 -> V_44 +
F_35 ( V_49 ) , V_55 ) )
continue;
F_22 ( V_31 ) ;
F_8 ( & V_39 -> V_42 ) ;
}
F_14 ( & V_49 -> V_58 ) ;
}
V_39 -> V_57 = V_56 ;
}
static void F_40 ( unsigned long V_59 )
{
struct V_48 * V_49 = (struct V_48 * ) V_59 ;
struct V_38 * V_39 = V_49 -> V_54 ;
unsigned long V_55 = V_13 ;
int V_60 ;
int V_45 , V_56 ;
struct V_30 * V_31 , * V_46 ;
if ( ( V_39 -> V_61 % V_62 ) == 0 ) {
F_38 ( V_49 ) ;
V_39 -> V_61 = 1 ;
goto V_63;
}
if ( F_16 ( & V_39 -> V_42 ) <= V_39 -> V_64 ) {
V_39 -> V_61 ++ ;
goto V_63;
}
V_60 = ( F_16 ( & V_39 -> V_42 ) - V_39 -> V_64 ) * 4 / 3 ;
if ( V_60 > V_39 -> V_64 / 2 )
V_60 = V_39 -> V_64 / 2 ;
for ( V_45 = 0 , V_56 = V_39 -> V_57 ; V_45 < V_47 ; V_45 ++ ) {
V_56 = ( V_56 + 1 ) & V_37 ;
F_12 ( & V_49 -> V_58 ) ;
F_13 (en, nxt, &tbl->bucket[j], list) {
if ( F_41 ( V_55 , V_31 -> V_44 + V_65 ) )
continue;
F_22 ( V_31 ) ;
F_8 ( & V_39 -> V_42 ) ;
V_60 -- ;
}
F_14 ( & V_49 -> V_58 ) ;
if ( V_60 <= 0 )
break;
}
V_39 -> V_57 = V_56 ;
V_63:
F_42 ( & V_39 -> V_66 , V_13 + V_67 ) ;
}
static int F_43 ( struct V_48 * V_49 )
{
int V_45 ;
struct V_38 * V_39 ;
V_39 = F_3 ( sizeof( * V_39 ) , V_7 ) ;
if ( V_39 == NULL ) {
F_4 ( L_1 , V_8 ) ;
return - V_68 ;
}
V_49 -> V_54 = V_39 ;
F_44 ( 6 , L_4
L_5 , sizeof( * V_39 ) ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
F_32 ( & V_39 -> V_41 [ V_45 ] ) ;
}
V_39 -> V_64 = V_47 * 16 ;
V_39 -> V_57 = 0 ;
V_39 -> V_61 = 1 ;
F_45 ( & V_39 -> V_66 , F_40 ,
( unsigned long ) V_49 ) ;
F_42 ( & V_39 -> V_66 , V_13 + V_67 ) ;
return 0 ;
}
static int F_46 ( struct V_48 * V_49 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
F_47 ( & V_39 -> V_66 ) ;
F_34 ( V_39 ) ;
F_10 ( V_39 ) ;
F_44 ( 6 , L_6 ,
sizeof( * V_39 ) ) ;
return 0 ;
}
static inline struct V_4 *
F_48 ( struct V_48 * V_49 )
{
struct V_4 * V_5 , * V_16 ;
int V_17 , V_18 ;
F_2 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_19 & V_20 )
continue;
if ( F_16 ( & V_5 -> V_21 ) > 0 ) {
V_16 = V_5 ;
V_17 = F_17 ( V_16 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_49 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_19 & V_20 )
continue;
V_18 = F_17 ( V_5 ) ;
if ( V_17 * F_16 ( & V_5 -> V_21 ) >
V_18 * F_16 ( & V_16 -> V_21 ) ) {
V_16 = V_5 ;
V_17 = V_18 ;
}
}
F_18 ( 6 , L_7
L_3 ,
F_19 ( V_16 -> V_24 , & V_16 -> V_25 ) ,
F_20 ( V_16 -> V_26 ) ,
F_16 ( & V_16 -> V_27 ) ,
F_16 ( & V_16 -> V_9 ) ,
F_16 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline int
F_50 ( struct V_4 * V_5 , struct V_48 * V_49 )
{
if ( F_16 ( & V_5 -> V_27 ) > F_16 ( & V_5 -> V_21 ) ) {
struct V_4 * V_69 ;
F_2 (d, &svc->destinations, n_list) {
if ( F_16 ( & V_69 -> V_27 ) * 2
< F_16 ( & V_69 -> V_21 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_4 *
F_51 ( struct V_48 * V_49 , const struct V_70 * V_71 )
{
struct V_38 * V_39 = V_49 -> V_54 ;
struct V_72 V_73 ;
struct V_4 * V_5 = NULL ;
struct V_30 * V_31 ;
F_52 ( V_49 -> V_24 , F_53 ( V_71 ) , & V_73 ) ;
F_44 ( 6 , L_8 , V_8 ) ;
F_54 ( & V_49 -> V_58 ) ;
V_31 = F_27 ( V_49 -> V_24 , V_39 , & V_73 . V_43 ) ;
if ( V_31 ) {
V_31 -> V_44 = V_13 ;
F_54 ( & V_31 -> V_3 . V_15 ) ;
V_5 = F_15 ( & V_31 -> V_3 ) ;
F_55 ( & V_31 -> V_3 . V_15 ) ;
if ( F_16 ( & V_31 -> V_3 . V_11 ) > 1 &&
F_39 ( V_13 , V_31 -> V_3 . V_12 +
F_35 ( V_49 ) ) ) {
struct V_4 * V_74 ;
F_12 ( & V_31 -> V_3 . V_15 ) ;
V_74 = F_21 ( & V_31 -> V_3 ) ;
if ( V_74 )
F_7 ( & V_31 -> V_3 , V_74 ) ;
F_14 ( & V_31 -> V_3 . V_15 ) ;
}
if ( V_5 && ! F_50 ( V_5 , V_49 ) ) {
F_55 ( & V_49 -> V_58 ) ;
goto V_63;
}
V_5 = F_48 ( V_49 ) ;
if ( ! V_5 ) {
F_56 ( V_49 , L_9 ) ;
F_55 ( & V_49 -> V_58 ) ;
return NULL ;
}
F_12 ( & V_31 -> V_3 . V_15 ) ;
F_1 ( & V_31 -> V_3 , V_5 ) ;
F_14 ( & V_31 -> V_3 . V_15 ) ;
}
F_55 ( & V_49 -> V_58 ) ;
if ( V_5 )
goto V_63;
V_5 = F_48 ( V_49 ) ;
if ( ! V_5 ) {
F_44 ( 1 , L_10 ) ;
return NULL ;
}
F_12 ( & V_49 -> V_58 ) ;
F_29 ( V_39 , & V_73 . V_43 , V_5 ) ;
F_14 ( & V_49 -> V_58 ) ;
V_63:
F_18 ( 6 , L_11 ,
F_19 ( V_49 -> V_24 , & V_73 . V_43 ) ,
F_19 ( V_49 -> V_24 , & V_5 -> V_25 ) , F_20 ( V_5 -> V_26 ) ) ;
return V_5 ;
}
static int T_2 F_57 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = F_37 ( V_52 ) ;
if ( ! F_58 ( V_52 , & V_75 ) ) {
V_51 -> V_76 = F_59 ( V_77 ,
sizeof( V_77 ) ,
V_78 ) ;
if ( V_51 -> V_76 == NULL )
return - V_68 ;
} else
V_51 -> V_76 = V_77 ;
V_51 -> F_35 = V_53 ;
V_51 -> V_76 [ 0 ] . V_59 = & V_51 -> F_35 ;
V_51 -> V_79 =
F_60 ( V_52 , V_80 ,
V_51 -> V_76 ) ;
if ( ! V_51 -> V_79 ) {
if ( ! F_58 ( V_52 , & V_75 ) )
F_10 ( V_51 -> V_76 ) ;
return - V_68 ;
}
return 0 ;
}
static void T_3 F_61 ( struct V_52 * V_52 )
{
struct V_50 * V_51 = F_37 ( V_52 ) ;
F_62 ( V_51 -> V_79 ) ;
if ( ! F_58 ( V_52 , & V_75 ) )
F_10 ( V_51 -> V_76 ) ;
}
static int T_2 F_57 ( struct V_52 * V_52 ) { return 0 ; }
static void T_3 F_61 ( struct V_52 * V_52 ) { }
static int T_4 F_63 ( void )
{
int V_81 ;
V_81 = F_64 ( & V_82 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_65 ( & V_83 ) ;
if ( V_81 )
F_66 ( & V_82 ) ;
return V_81 ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_83 ) ;
F_66 ( & V_82 ) ;
}
