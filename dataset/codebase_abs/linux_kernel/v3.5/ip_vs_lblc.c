static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static inline unsigned int
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
unsigned int V_16 = F_5 ( V_2 -> V_6 , & V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_3 , & V_15 -> V_17 [ V_16 ] ) ;
F_10 ( & V_15 -> V_18 ) ;
}
static inline struct V_1 *
F_11 ( int V_6 , struct V_14 * V_15 ,
const union V_7 * V_8 )
{
unsigned int V_16 = F_5 ( V_6 , V_8 ) ;
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
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_4 -> V_6 ;
F_16 ( V_4 -> V_6 , & V_2 -> V_8 , V_19 ) ;
V_2 -> V_22 = V_23 ;
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
static void F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
F_18 (en, nxt, &tbl->bucket[i], list) {
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
}
}
}
static int F_19 ( struct V_27 * V_28 )
{
#ifdef F_20
struct V_29 * V_30 = F_21 ( V_28 -> V_31 ) ;
return V_30 -> F_19 ;
#else
return V_32 ;
#endif
}
static inline void F_22 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_33 ;
struct V_1 * V_2 , * V_24 ;
unsigned long V_34 = V_23 ;
int V_25 , V_35 ;
for ( V_25 = 0 , V_35 = V_15 -> V_36 ; V_25 < V_26 ; V_25 ++ ) {
V_35 = ( V_35 + 1 ) & V_13 ;
F_23 ( & V_28 -> V_37 ) ;
F_18 (en, nxt, &tbl->bucket[j], list) {
if ( F_24 ( V_34 ,
V_2 -> V_22 +
F_19 ( V_28 ) ) )
continue;
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
}
F_25 ( & V_28 -> V_37 ) ;
}
V_15 -> V_36 = V_35 ;
}
static void F_26 ( unsigned long V_38 )
{
struct V_27 * V_28 = (struct V_27 * ) V_38 ;
struct V_14 * V_15 = V_28 -> V_33 ;
unsigned long V_34 = V_23 ;
int V_39 ;
int V_25 , V_35 ;
struct V_1 * V_2 , * V_24 ;
if ( ( V_15 -> V_40 % V_41 ) == 0 ) {
F_22 ( V_28 ) ;
V_15 -> V_40 = 1 ;
goto V_42;
}
if ( F_27 ( & V_15 -> V_18 ) <= V_15 -> V_43 ) {
V_15 -> V_40 ++ ;
goto V_42;
}
V_39 = ( F_27 ( & V_15 -> V_18 ) - V_15 -> V_43 ) * 4 / 3 ;
if ( V_39 > V_15 -> V_43 / 2 )
V_39 = V_15 -> V_43 / 2 ;
for ( V_25 = 0 , V_35 = V_15 -> V_36 ; V_25 < V_26 ; V_25 ++ ) {
V_35 = ( V_35 + 1 ) & V_13 ;
F_23 ( & V_28 -> V_37 ) ;
F_18 (en, nxt, &tbl->bucket[j], list) {
if ( F_24 ( V_34 , V_2 -> V_22 + V_44 ) )
continue;
F_1 ( V_2 ) ;
F_3 ( & V_15 -> V_18 ) ;
V_39 -- ;
}
F_25 ( & V_28 -> V_37 ) ;
if ( V_39 <= 0 )
break;
}
V_15 -> V_36 = V_35 ;
V_42:
F_28 ( & V_15 -> V_45 , V_23 + V_46 ) ;
}
static int F_29 ( struct V_27 * V_28 )
{
int V_25 ;
struct V_14 * V_15 ;
V_15 = F_15 ( sizeof( * V_15 ) , V_47 ) ;
if ( V_15 == NULL )
return - V_48 ;
V_28 -> V_33 = V_15 ;
F_30 ( 6 , L_1
L_2 , sizeof( * V_15 ) ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
F_31 ( & V_15 -> V_17 [ V_25 ] ) ;
}
V_15 -> V_43 = V_26 * 16 ;
V_15 -> V_36 = 0 ;
V_15 -> V_40 = 1 ;
F_32 ( & V_15 -> V_45 , F_26 ,
( unsigned long ) V_28 ) ;
F_28 ( & V_15 -> V_45 , V_23 + V_46 ) ;
return 0 ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_33 ;
F_34 ( & V_15 -> V_45 ) ;
F_17 ( V_15 ) ;
F_4 ( V_15 ) ;
F_30 ( 6 , L_3 ,
sizeof( * V_15 ) ) ;
return 0 ;
}
static inline struct V_20 *
F_35 ( struct V_27 * V_28 )
{
struct V_20 * V_4 , * V_49 ;
int V_50 , V_51 ;
F_12 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_52 & V_53 )
continue;
if ( F_27 ( & V_4 -> V_54 ) > 0 ) {
V_49 = V_4 ;
V_50 = F_36 ( V_49 ) ;
goto V_55;
}
}
return NULL ;
V_55:
F_37 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_52 & V_53 )
continue;
V_51 = F_36 ( V_4 ) ;
if ( V_50 * F_27 ( & V_4 -> V_54 ) >
V_51 * F_27 ( & V_49 -> V_54 ) ) {
V_49 = V_4 ;
V_50 = V_51 ;
}
}
F_38 ( 6 , L_4
L_5 ,
F_39 ( V_49 -> V_6 , & V_49 -> V_8 ) ,
F_40 ( V_49 -> V_56 ) ,
F_27 ( & V_49 -> V_57 ) ,
F_27 ( & V_49 -> V_5 ) ,
F_27 ( & V_49 -> V_54 ) , V_50 ) ;
return V_49 ;
}
static inline int
F_41 ( struct V_20 * V_4 , struct V_27 * V_28 )
{
if ( F_27 ( & V_4 -> V_57 ) > F_27 ( & V_4 -> V_54 ) ) {
struct V_20 * V_58 ;
F_12 (d, &svc->destinations, n_list) {
if ( F_27 ( & V_58 -> V_57 ) * 2
< F_27 ( & V_58 -> V_54 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_20 *
F_42 ( struct V_27 * V_28 , const struct V_59 * V_60 )
{
struct V_14 * V_15 = V_28 -> V_33 ;
struct V_61 V_62 ;
struct V_20 * V_4 = NULL ;
struct V_1 * V_2 ;
F_43 ( V_28 -> V_6 , F_44 ( V_60 ) , & V_62 ) ;
F_30 ( 6 , L_6 , V_63 ) ;
F_45 ( & V_28 -> V_37 ) ;
V_2 = F_11 ( V_28 -> V_6 , V_15 , & V_62 . V_19 ) ;
if ( V_2 ) {
V_2 -> V_22 = V_23 ;
if ( V_2 -> V_4 -> V_52 & V_64 )
V_4 = V_2 -> V_4 ;
}
F_46 ( & V_28 -> V_37 ) ;
if ( V_4 && F_27 ( & V_4 -> V_54 ) > 0 && ! F_41 ( V_4 , V_28 ) )
goto V_42;
V_4 = F_35 ( V_28 ) ;
if ( ! V_4 ) {
F_47 ( V_28 , L_7 ) ;
return NULL ;
}
F_23 ( & V_28 -> V_37 ) ;
F_14 ( V_15 , & V_62 . V_19 , V_4 ) ;
F_25 ( & V_28 -> V_37 ) ;
V_42:
F_38 ( 6 , L_8 ,
F_39 ( V_28 -> V_6 , & V_62 . V_19 ) ,
F_39 ( V_28 -> V_6 , & V_4 -> V_8 ) , F_40 ( V_4 -> V_56 ) ) ;
return V_4 ;
}
static int T_2 F_48 ( struct V_31 * V_31 )
{
struct V_29 * V_30 = F_21 ( V_31 ) ;
if ( ! V_30 )
return - V_65 ;
if ( ! F_49 ( V_31 , & V_66 ) ) {
V_30 -> V_67 = F_50 ( V_68 ,
sizeof( V_68 ) ,
V_47 ) ;
if ( V_30 -> V_67 == NULL )
return - V_48 ;
} else
V_30 -> V_67 = V_68 ;
V_30 -> F_19 = V_32 ;
V_30 -> V_67 [ 0 ] . V_38 = & V_30 -> F_19 ;
V_30 -> V_69 =
F_51 ( V_31 , L_9 , V_30 -> V_67 ) ;
if ( ! V_30 -> V_69 ) {
if ( ! F_49 ( V_31 , & V_66 ) )
F_4 ( V_30 -> V_67 ) ;
return - V_48 ;
}
return 0 ;
}
static void T_3 F_52 ( struct V_31 * V_31 )
{
struct V_29 * V_30 = F_21 ( V_31 ) ;
F_53 ( V_30 -> V_69 ) ;
if ( ! F_49 ( V_31 , & V_66 ) )
F_4 ( V_30 -> V_67 ) ;
}
static int T_2 F_48 ( struct V_31 * V_31 ) { return 0 ; }
static void T_3 F_52 ( struct V_31 * V_31 ) { }
static int T_4 F_54 ( void )
{
int V_70 ;
V_70 = F_55 ( & V_71 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_56 ( & V_72 ) ;
if ( V_70 )
F_57 ( & V_71 ) ;
return V_70 ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_72 ) ;
F_57 ( & V_71 ) ;
}
