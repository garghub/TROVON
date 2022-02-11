static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static inline unsigned
F_5 ( int V_6 , const union V_7 * V_8 )
{
T_1 V_9 = V_8 -> V_10 ;
#ifdef F_6
if ( V_6 == V_11 )
V_9 = V_8 -> V_12 [ 0 ] ^ V_8 -> V_12 [ 1 ] ^
V_8 -> V_12 [ 2 ] ^ V_8 -> V_12 [ 3 ] ;
#endif
return ( F_7 ( V_9 ) * 2654435761UL ) & V_13 ;
}
static void
F_8 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned V_16 = F_5 ( V_2 -> V_6 , & V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_3 , & V_15 -> V_17 [ V_16 ] ) ;
F_10 ( & V_15 -> V_18 ) ;
}
static inline struct V_1 *
F_11 ( int V_6 , struct V_14 * V_15 ,
const union V_7 * V_8 )
{
unsigned V_16 = F_5 ( V_6 , V_8 ) ;
struct V_1 * V_2 ;
F_12 (en, &tbl->bucket[hash], list)
if ( F_13 ( V_6 , & V_2 -> V_8 , V_8 ) )
return V_2 ;
return NULL ;
}
static inline struct V_1 *
F_14 ( struct V_14 * V_15 , const union V_7 * V_19 ,
struct V_20 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_4 -> V_6 , V_15 , V_19 ) ;
if ( ! V_2 ) {
V_2 = F_15 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 ) {
F_16 ( L_1 , V_22 ) ;
return NULL ;
}
V_2 -> V_6 = V_4 -> V_6 ;
F_17 ( V_4 -> V_6 , & V_2 -> V_8 , V_19 ) ;
V_2 -> V_23 = V_24 ;
F_10 ( & V_4 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
F_8 ( V_15 , V_2 ) ;
} else if ( V_2 -> V_4 != V_4 ) {
F_3 ( & V_2 -> V_4 -> V_5 ) ;
F_10 ( & V_4 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
}
return V_2 ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
F_19 (en, nxt, &tbl->bucket[i], list) {
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
}
}
}
static int F_20 ( struct V_28 * V_29 )
{
#ifdef F_21
struct V_30 * V_31 = F_22 ( V_29 -> V_32 ) ;
return V_31 -> F_20 ;
#else
return V_33 ;
#endif
}
static inline void F_23 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_34 ;
struct V_1 * V_2 , * V_25 ;
unsigned long V_35 = V_24 ;
int V_26 , V_36 ;
for ( V_26 = 0 , V_36 = V_15 -> V_37 ; V_26 < V_27 ; V_26 ++ ) {
V_36 = ( V_36 + 1 ) & V_13 ;
F_24 ( & V_29 -> V_38 ) ;
F_19 (en, nxt, &tbl->bucket[j], list) {
if ( F_25 ( V_35 ,
V_2 -> V_23 +
F_20 ( V_29 ) ) )
continue;
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
}
F_26 ( & V_29 -> V_38 ) ;
}
V_15 -> V_37 = V_36 ;
}
static void F_27 ( unsigned long V_39 )
{
struct V_28 * V_29 = (struct V_28 * ) V_39 ;
struct V_14 * V_15 = V_29 -> V_34 ;
unsigned long V_35 = V_24 ;
int V_40 ;
int V_26 , V_36 ;
struct V_1 * V_2 , * V_25 ;
if ( ( V_15 -> V_41 % V_42 ) == 0 ) {
F_23 ( V_29 ) ;
V_15 -> V_41 = 1 ;
goto V_43;
}
if ( F_28 ( & V_15 -> V_18 ) <= V_15 -> V_44 ) {
V_15 -> V_41 ++ ;
goto V_43;
}
V_40 = ( F_28 ( & V_15 -> V_18 ) - V_15 -> V_44 ) * 4 / 3 ;
if ( V_40 > V_15 -> V_44 / 2 )
V_40 = V_15 -> V_44 / 2 ;
for ( V_26 = 0 , V_36 = V_15 -> V_37 ; V_26 < V_27 ; V_26 ++ ) {
V_36 = ( V_36 + 1 ) & V_13 ;
F_24 ( & V_29 -> V_38 ) ;
F_19 (en, nxt, &tbl->bucket[j], list) {
if ( F_25 ( V_35 , V_2 -> V_23 + V_45 ) )
continue;
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
V_40 -- ;
}
F_26 ( & V_29 -> V_38 ) ;
if ( V_40 <= 0 )
break;
}
V_15 -> V_37 = V_36 ;
V_43:
F_29 ( & V_15 -> V_46 , V_24 + V_47 ) ;
}
static int F_30 ( struct V_28 * V_29 )
{
int V_26 ;
struct V_14 * V_15 ;
V_15 = F_15 ( sizeof( * V_15 ) , V_21 ) ;
if ( V_15 == NULL ) {
F_16 ( L_1 , V_22 ) ;
return - V_48 ;
}
V_29 -> V_34 = V_15 ;
F_31 ( 6 , L_2
L_3 , sizeof( * V_15 ) ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
F_32 ( & V_15 -> V_17 [ V_26 ] ) ;
}
V_15 -> V_44 = V_27 * 16 ;
V_15 -> V_37 = 0 ;
V_15 -> V_41 = 1 ;
F_33 ( & V_15 -> V_46 , F_27 ,
( unsigned long ) V_29 ) ;
F_29 ( & V_15 -> V_46 , V_24 + V_47 ) ;
return 0 ;
}
static int F_34 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_34 ;
F_35 ( & V_15 -> V_46 ) ;
F_18 ( V_15 ) ;
F_4 ( V_15 ) ;
F_31 ( 6 , L_4 ,
sizeof( * V_15 ) ) ;
return 0 ;
}
static inline struct V_20 *
F_36 ( struct V_28 * V_29 )
{
struct V_20 * V_4 , * V_49 ;
int V_50 , V_51 ;
F_12 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_52 & V_53 )
continue;
if ( F_28 ( & V_4 -> V_54 ) > 0 ) {
V_49 = V_4 ;
V_50 = F_37 ( V_49 ) ;
goto V_55;
}
}
return NULL ;
V_55:
F_38 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_52 & V_53 )
continue;
V_51 = F_37 ( V_4 ) ;
if ( V_50 * F_28 ( & V_4 -> V_54 ) >
V_51 * F_28 ( & V_49 -> V_54 ) ) {
V_49 = V_4 ;
V_50 = V_51 ;
}
}
F_39 ( 6 , L_5
L_6 ,
F_40 ( V_49 -> V_6 , & V_49 -> V_8 ) ,
F_41 ( V_49 -> V_56 ) ,
F_28 ( & V_49 -> V_57 ) ,
F_28 ( & V_49 -> V_5 ) ,
F_28 ( & V_49 -> V_54 ) , V_50 ) ;
return V_49 ;
}
static inline int
F_42 ( struct V_20 * V_4 , struct V_28 * V_29 )
{
if ( F_28 ( & V_4 -> V_57 ) > F_28 ( & V_4 -> V_54 ) ) {
struct V_20 * V_58 ;
F_12 (d, &svc->destinations, n_list) {
if ( F_28 ( & V_58 -> V_57 ) * 2
< F_28 ( & V_58 -> V_54 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_20 *
F_43 ( struct V_28 * V_29 , const struct V_59 * V_60 )
{
struct V_14 * V_15 = V_29 -> V_34 ;
struct V_61 V_62 ;
struct V_20 * V_4 = NULL ;
struct V_1 * V_2 ;
F_44 ( V_29 -> V_6 , F_45 ( V_60 ) , & V_62 ) ;
F_31 ( 6 , L_7 , V_22 ) ;
F_46 ( & V_29 -> V_38 ) ;
V_2 = F_11 ( V_29 -> V_6 , V_15 , & V_62 . V_19 ) ;
if ( V_2 ) {
V_2 -> V_23 = V_24 ;
if ( V_2 -> V_4 -> V_52 & V_63 )
V_4 = V_2 -> V_4 ;
}
F_47 ( & V_29 -> V_38 ) ;
if ( V_4 && F_28 ( & V_4 -> V_54 ) > 0 && ! F_42 ( V_4 , V_29 ) )
goto V_43;
V_4 = F_36 ( V_29 ) ;
if ( ! V_4 ) {
F_48 ( V_29 , L_8 ) ;
return NULL ;
}
F_24 ( & V_29 -> V_38 ) ;
F_14 ( V_15 , & V_62 . V_19 , V_4 ) ;
F_26 ( & V_29 -> V_38 ) ;
V_43:
F_39 ( 6 , L_9 ,
F_40 ( V_29 -> V_6 , & V_62 . V_19 ) ,
F_40 ( V_29 -> V_6 , & V_4 -> V_8 ) , F_41 ( V_4 -> V_56 ) ) ;
return V_4 ;
}
static int T_2 F_49 ( struct V_32 * V_32 )
{
struct V_30 * V_31 = F_22 ( V_32 ) ;
if ( ! F_50 ( V_32 , & V_64 ) ) {
V_31 -> V_65 = F_51 ( V_66 ,
sizeof( V_66 ) ,
V_67 ) ;
if ( V_31 -> V_65 == NULL )
return - V_48 ;
} else
V_31 -> V_65 = V_66 ;
V_31 -> F_20 = V_33 ;
V_31 -> V_65 [ 0 ] . V_39 = & V_31 -> F_20 ;
V_31 -> V_68 =
F_52 ( V_32 , V_69 ,
V_31 -> V_65 ) ;
if ( ! V_31 -> V_68 ) {
if ( ! F_50 ( V_32 , & V_64 ) )
F_4 ( V_31 -> V_65 ) ;
return - V_48 ;
}
return 0 ;
}
static void T_3 F_53 ( struct V_32 * V_32 )
{
struct V_30 * V_31 = F_22 ( V_32 ) ;
F_54 ( V_31 -> V_68 ) ;
if ( ! F_50 ( V_32 , & V_64 ) )
F_4 ( V_31 -> V_65 ) ;
}
static int T_2 F_49 ( struct V_32 * V_32 ) { return 0 ; }
static void T_3 F_53 ( struct V_32 * V_32 ) { }
static int T_4 F_55 ( void )
{
int V_70 ;
V_70 = F_56 ( & V_71 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_57 ( & V_72 ) ;
if ( V_70 )
F_58 ( & V_71 ) ;
return V_70 ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_72 ) ;
F_58 ( & V_71 ) ;
}
