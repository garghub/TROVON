static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_4 , 1 ) ;
F_4 ( V_4 ) ;
F_5 ( V_2 , V_6 ) ;
}
static inline unsigned int
F_6 ( int V_7 , const union V_8 * V_9 )
{
T_1 V_10 = V_9 -> V_11 ;
#ifdef F_7
if ( V_7 == V_12 )
V_10 = V_9 -> V_13 [ 0 ] ^ V_9 -> V_13 [ 1 ] ^
V_9 -> V_13 [ 2 ] ^ V_9 -> V_13 [ 3 ] ;
#endif
return ( F_8 ( V_10 ) * 2654435761UL ) & V_14 ;
}
static void
F_9 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
unsigned int V_17 = F_6 ( V_2 -> V_7 , & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_5 , & V_16 -> V_18 [ V_17 ] ) ;
F_11 ( & V_16 -> V_19 ) ;
}
static inline struct V_1 *
F_12 ( int V_7 , struct V_15 * V_16 ,
const union V_8 * V_9 )
{
unsigned int V_17 = F_6 ( V_7 , V_9 ) ;
struct V_1 * V_2 ;
F_13 (en, &tbl->bucket[hash], list)
if ( F_14 ( V_7 , & V_2 -> V_9 , V_9 ) )
return V_2 ;
return NULL ;
}
static inline struct V_1 *
F_15 ( struct V_15 * V_16 , const union V_8 * V_20 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_4 -> V_7 , V_16 , V_20 ) ;
if ( ! V_2 ) {
V_2 = F_16 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_4 -> V_7 ;
F_17 ( V_4 -> V_7 , & V_2 -> V_9 , V_20 ) ;
V_2 -> V_22 = V_23 ;
F_18 ( V_4 ) ;
F_19 ( V_2 -> V_4 , V_4 ) ;
F_9 ( V_16 , V_2 ) ;
} else {
struct V_3 * V_24 ;
V_24 = F_3 ( V_2 -> V_4 , 1 ) ;
if ( V_24 != V_4 ) {
F_4 ( V_24 ) ;
F_18 ( V_4 ) ;
F_19 ( V_2 -> V_4 , V_4 ) ;
}
}
return V_2 ;
}
static void F_20 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_30 ;
F_21 ( & V_26 -> V_31 ) ;
V_16 -> V_32 = 1 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
F_22 (en, next, &tbl->bucket[i], list) {
F_1 ( V_2 ) ;
F_23 ( & V_16 -> V_19 ) ;
}
}
F_24 ( & V_26 -> V_31 ) ;
}
static int F_25 ( struct V_25 * V_26 )
{
#ifdef F_26
struct V_34 * V_35 = F_27 ( V_26 -> V_36 ) ;
return V_35 -> F_25 ;
#else
return V_37 ;
#endif
}
static inline void F_28 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
unsigned long V_38 = V_23 ;
int V_30 , V_39 ;
for ( V_30 = 0 , V_39 = V_16 -> V_40 ; V_30 < V_33 ; V_30 ++ ) {
V_39 = ( V_39 + 1 ) & V_14 ;
F_29 ( & V_26 -> V_31 ) ;
F_22 (en, next, &tbl->bucket[j], list) {
if ( F_30 ( V_38 ,
V_2 -> V_22 +
F_25 ( V_26 ) ) )
continue;
F_1 ( V_2 ) ;
F_23 ( & V_16 -> V_19 ) ;
}
F_31 ( & V_26 -> V_31 ) ;
}
V_16 -> V_40 = V_39 ;
}
static void F_32 ( unsigned long V_41 )
{
struct V_25 * V_26 = (struct V_25 * ) V_41 ;
struct V_15 * V_16 = V_26 -> V_27 ;
unsigned long V_38 = V_23 ;
int V_42 ;
int V_30 , V_39 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
if ( ( V_16 -> V_43 % V_44 ) == 0 ) {
F_28 ( V_26 ) ;
V_16 -> V_43 = 1 ;
goto V_45;
}
if ( F_33 ( & V_16 -> V_19 ) <= V_16 -> V_46 ) {
V_16 -> V_43 ++ ;
goto V_45;
}
V_42 = ( F_33 ( & V_16 -> V_19 ) - V_16 -> V_46 ) * 4 / 3 ;
if ( V_42 > V_16 -> V_46 / 2 )
V_42 = V_16 -> V_46 / 2 ;
for ( V_30 = 0 , V_39 = V_16 -> V_40 ; V_30 < V_33 ; V_30 ++ ) {
V_39 = ( V_39 + 1 ) & V_14 ;
F_29 ( & V_26 -> V_31 ) ;
F_22 (en, next, &tbl->bucket[j], list) {
if ( F_30 ( V_38 , V_2 -> V_22 + V_47 ) )
continue;
F_1 ( V_2 ) ;
F_23 ( & V_16 -> V_19 ) ;
V_42 -- ;
}
F_31 ( & V_26 -> V_31 ) ;
if ( V_42 <= 0 )
break;
}
V_16 -> V_40 = V_39 ;
V_45:
F_34 ( & V_16 -> V_48 , V_23 + V_49 ) ;
}
static int F_35 ( struct V_25 * V_26 )
{
int V_30 ;
struct V_15 * V_16 ;
V_16 = F_16 ( sizeof( * V_16 ) , V_50 ) ;
if ( V_16 == NULL )
return - V_51 ;
V_26 -> V_27 = V_16 ;
F_36 ( 6 , L_1
L_2 , sizeof( * V_16 ) ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
F_37 ( & V_16 -> V_18 [ V_30 ] ) ;
}
V_16 -> V_46 = V_33 * 16 ;
V_16 -> V_40 = 0 ;
V_16 -> V_43 = 1 ;
V_16 -> V_32 = 0 ;
F_38 ( & V_16 -> V_48 , F_32 ,
( unsigned long ) V_26 ) ;
F_34 ( & V_16 -> V_48 , V_23 + V_49 ) ;
return 0 ;
}
static void F_39 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
F_40 ( & V_16 -> V_48 ) ;
F_20 ( V_26 ) ;
F_5 ( V_16 , V_6 ) ;
F_36 ( 6 , L_3 ,
sizeof( * V_16 ) ) ;
}
static inline struct V_3 *
F_41 ( struct V_25 * V_26 )
{
struct V_3 * V_4 , * V_52 ;
int V_53 , V_54 ;
F_42 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_55 & V_56 )
continue;
if ( F_33 ( & V_4 -> V_57 ) > 0 ) {
V_52 = V_4 ;
V_53 = F_43 ( V_52 ) ;
goto V_58;
}
}
return NULL ;
V_58:
F_44 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_55 & V_56 )
continue;
V_54 = F_43 ( V_4 ) ;
if ( V_53 * F_33 ( & V_4 -> V_57 ) >
V_54 * F_33 ( & V_52 -> V_57 ) ) {
V_52 = V_4 ;
V_53 = V_54 ;
}
}
F_45 ( 6 , L_4
L_5 ,
F_46 ( V_52 -> V_7 , & V_52 -> V_9 ) ,
F_47 ( V_52 -> V_59 ) ,
F_33 ( & V_52 -> V_60 ) ,
F_33 ( & V_52 -> V_61 ) ,
F_33 ( & V_52 -> V_57 ) , V_53 ) ;
return V_52 ;
}
static inline int
F_48 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
if ( F_33 ( & V_4 -> V_60 ) > F_33 ( & V_4 -> V_57 ) ) {
struct V_3 * V_62 ;
F_42 (d, &svc->destinations, n_list) {
if ( F_33 ( & V_62 -> V_60 ) * 2
< F_33 ( & V_62 -> V_57 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_3 *
F_49 ( struct V_25 * V_26 , const struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 ;
F_36 ( 6 , L_6 , V_67 ) ;
V_2 = F_12 ( V_26 -> V_7 , V_16 , & V_66 -> V_20 ) ;
if ( V_2 ) {
V_2 -> V_22 = V_23 ;
V_4 = F_50 ( V_2 -> V_4 ) ;
if ( ( V_4 -> V_55 & V_68 ) &&
F_33 ( & V_4 -> V_57 ) > 0 && ! F_48 ( V_4 , V_26 ) )
goto V_45;
}
V_4 = F_41 ( V_26 ) ;
if ( ! V_4 ) {
F_51 ( V_26 , L_7 ) ;
return NULL ;
}
F_21 ( & V_26 -> V_31 ) ;
if ( ! V_16 -> V_32 )
F_15 ( V_16 , & V_66 -> V_20 , V_4 ) ;
F_24 ( & V_26 -> V_31 ) ;
V_45:
F_45 ( 6 , L_8 ,
F_46 ( V_26 -> V_7 , & V_66 -> V_20 ) ,
F_46 ( V_26 -> V_7 , & V_4 -> V_9 ) , F_47 ( V_4 -> V_59 ) ) ;
return V_4 ;
}
static int T_2 F_52 ( struct V_36 * V_36 )
{
struct V_34 * V_35 = F_27 ( V_36 ) ;
if ( ! V_35 )
return - V_69 ;
if ( ! F_53 ( V_36 , & V_70 ) ) {
V_35 -> V_71 = F_54 ( V_72 ,
sizeof( V_72 ) ,
V_50 ) ;
if ( V_35 -> V_71 == NULL )
return - V_51 ;
if ( V_36 -> V_73 != & V_74 )
V_35 -> V_71 [ 0 ] . V_75 = NULL ;
} else
V_35 -> V_71 = V_72 ;
V_35 -> F_25 = V_37 ;
V_35 -> V_71 [ 0 ] . V_41 = & V_35 -> F_25 ;
V_35 -> V_76 =
F_55 ( V_36 , L_9 , V_35 -> V_71 ) ;
if ( ! V_35 -> V_76 ) {
if ( ! F_53 ( V_36 , & V_70 ) )
F_56 ( V_35 -> V_71 ) ;
return - V_51 ;
}
return 0 ;
}
static void T_3 F_57 ( struct V_36 * V_36 )
{
struct V_34 * V_35 = F_27 ( V_36 ) ;
F_58 ( V_35 -> V_76 ) ;
if ( ! F_53 ( V_36 , & V_70 ) )
F_56 ( V_35 -> V_71 ) ;
}
static int T_2 F_52 ( struct V_36 * V_36 ) { return 0 ; }
static void T_3 F_57 ( struct V_36 * V_36 ) { }
static int T_4 F_59 ( void )
{
int V_77 ;
V_77 = F_60 ( & V_78 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_61 ( & V_79 ) ;
if ( V_77 )
F_62 ( & V_78 ) ;
return V_77 ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_79 ) ;
F_62 ( & V_78 ) ;
F_65 () ;
}
