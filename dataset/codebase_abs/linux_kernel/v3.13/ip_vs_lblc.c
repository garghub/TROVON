static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_1 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
static inline void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_6 ) ;
F_7 ( & V_4 -> V_1 , F_1 ) ;
}
static inline unsigned int
F_8 ( int V_7 , const union V_8 * V_9 )
{
T_1 V_10 = V_9 -> V_11 ;
#ifdef F_9
if ( V_7 == V_12 )
V_10 = V_9 -> V_13 [ 0 ] ^ V_9 -> V_13 [ 1 ] ^
V_9 -> V_13 [ 2 ] ^ V_9 -> V_13 [ 3 ] ;
#endif
return ( F_10 ( V_10 ) * 2654435761UL ) & V_14 ;
}
static void
F_11 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
unsigned int V_17 = F_8 ( V_4 -> V_7 , & V_4 -> V_9 ) ;
F_12 ( & V_4 -> V_6 , & V_16 -> V_18 [ V_17 ] ) ;
F_13 ( & V_16 -> V_19 ) ;
}
static inline struct V_3 *
F_14 ( int V_7 , struct V_15 * V_16 ,
const union V_8 * V_9 )
{
unsigned int V_17 = F_8 ( V_7 , V_9 ) ;
struct V_3 * V_4 ;
F_15 (en, &tbl->bucket[hash], list)
if ( F_16 ( V_7 , & V_4 -> V_9 , V_9 ) )
return V_4 ;
return NULL ;
}
static inline struct V_3 *
F_17 ( struct V_15 * V_16 , const union V_8 * V_20 ,
struct V_21 * V_5 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_5 -> V_7 , V_16 , V_20 ) ;
if ( V_4 ) {
if ( V_4 -> V_5 == V_5 )
return V_4 ;
F_5 ( V_4 ) ;
}
V_4 = F_18 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = V_5 -> V_7 ;
F_19 ( V_5 -> V_7 , & V_4 -> V_9 , V_20 ) ;
V_4 -> V_23 = V_24 ;
F_20 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
F_11 ( V_16 , V_4 ) ;
return V_4 ;
}
static void F_21 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
int V_30 ;
F_22 ( & V_26 -> V_31 ) ;
V_16 -> V_32 = 1 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
F_23 (en, next, &tbl->bucket[i], list) {
F_5 ( V_4 ) ;
F_24 ( & V_16 -> V_19 ) ;
}
}
F_25 ( & V_26 -> V_31 ) ;
}
static int F_26 ( struct V_25 * V_26 )
{
#ifdef F_27
struct V_34 * V_35 = F_28 ( V_26 -> V_36 ) ;
return V_35 -> F_26 ;
#else
return V_37 ;
#endif
}
static inline void F_29 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
unsigned long V_38 = V_24 ;
int V_30 , V_39 ;
for ( V_30 = 0 , V_39 = V_16 -> V_40 ; V_30 < V_33 ; V_30 ++ ) {
V_39 = ( V_39 + 1 ) & V_14 ;
F_30 ( & V_26 -> V_31 ) ;
F_23 (en, next, &tbl->bucket[j], list) {
if ( F_31 ( V_38 ,
V_4 -> V_23 +
F_26 ( V_26 ) ) )
continue;
F_5 ( V_4 ) ;
F_24 ( & V_16 -> V_19 ) ;
}
F_32 ( & V_26 -> V_31 ) ;
}
V_16 -> V_40 = V_39 ;
}
static void F_33 ( unsigned long V_41 )
{
struct V_25 * V_26 = (struct V_25 * ) V_41 ;
struct V_15 * V_16 = V_26 -> V_27 ;
unsigned long V_38 = V_24 ;
int V_42 ;
int V_30 , V_39 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
if ( ( V_16 -> V_43 % V_44 ) == 0 ) {
F_29 ( V_26 ) ;
V_16 -> V_43 = 1 ;
goto V_45;
}
if ( F_34 ( & V_16 -> V_19 ) <= V_16 -> V_46 ) {
V_16 -> V_43 ++ ;
goto V_45;
}
V_42 = ( F_34 ( & V_16 -> V_19 ) - V_16 -> V_46 ) * 4 / 3 ;
if ( V_42 > V_16 -> V_46 / 2 )
V_42 = V_16 -> V_46 / 2 ;
for ( V_30 = 0 , V_39 = V_16 -> V_40 ; V_30 < V_33 ; V_30 ++ ) {
V_39 = ( V_39 + 1 ) & V_14 ;
F_30 ( & V_26 -> V_31 ) ;
F_23 (en, next, &tbl->bucket[j], list) {
if ( F_31 ( V_38 , V_4 -> V_23 + V_47 ) )
continue;
F_5 ( V_4 ) ;
F_24 ( & V_16 -> V_19 ) ;
V_42 -- ;
}
F_32 ( & V_26 -> V_31 ) ;
if ( V_42 <= 0 )
break;
}
V_16 -> V_40 = V_39 ;
V_45:
F_35 ( & V_16 -> V_48 , V_24 + V_49 ) ;
}
static int F_36 ( struct V_25 * V_26 )
{
int V_30 ;
struct V_15 * V_16 ;
V_16 = F_18 ( sizeof( * V_16 ) , V_50 ) ;
if ( V_16 == NULL )
return - V_51 ;
V_26 -> V_27 = V_16 ;
F_37 ( 6 , L_1
L_2 , sizeof( * V_16 ) ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
F_38 ( & V_16 -> V_18 [ V_30 ] ) ;
}
V_16 -> V_46 = V_33 * 16 ;
V_16 -> V_40 = 0 ;
V_16 -> V_43 = 1 ;
V_16 -> V_32 = 0 ;
F_39 ( & V_16 -> V_48 , F_33 ,
( unsigned long ) V_26 ) ;
F_35 ( & V_16 -> V_48 , V_24 + V_49 ) ;
return 0 ;
}
static void F_40 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
F_41 ( & V_16 -> V_48 ) ;
F_21 ( V_26 ) ;
F_42 ( V_16 , V_1 ) ;
F_37 ( 6 , L_3 ,
sizeof( * V_16 ) ) ;
}
static inline struct V_21 *
F_43 ( struct V_25 * V_26 )
{
struct V_21 * V_5 , * V_52 ;
int V_53 , V_54 ;
F_44 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_55 & V_56 )
continue;
if ( F_34 ( & V_5 -> V_57 ) > 0 ) {
V_52 = V_5 ;
V_53 = F_45 ( V_52 ) ;
goto V_58;
}
}
return NULL ;
V_58:
F_46 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_55 & V_56 )
continue;
V_54 = F_45 ( V_5 ) ;
if ( ( V_59 ) V_53 * F_34 ( & V_5 -> V_57 ) >
( V_59 ) V_54 * F_34 ( & V_52 -> V_57 ) ) {
V_52 = V_5 ;
V_53 = V_54 ;
}
}
F_47 ( 6 , L_4
L_5 ,
F_48 ( V_52 -> V_7 , & V_52 -> V_9 ) ,
F_49 ( V_52 -> V_60 ) ,
F_34 ( & V_52 -> V_61 ) ,
F_34 ( & V_52 -> V_62 ) ,
F_34 ( & V_52 -> V_57 ) , V_53 ) ;
return V_52 ;
}
static inline int
F_50 ( struct V_21 * V_5 , struct V_25 * V_26 )
{
if ( F_34 ( & V_5 -> V_61 ) > F_34 ( & V_5 -> V_57 ) ) {
struct V_21 * V_63 ;
F_44 (d, &svc->destinations, n_list) {
if ( F_34 ( & V_63 -> V_61 ) * 2
< F_34 ( & V_63 -> V_57 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_21 *
F_51 ( struct V_25 * V_26 , const struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_21 * V_5 = NULL ;
struct V_3 * V_4 ;
F_37 ( 6 , L_6 , V_68 ) ;
V_4 = F_14 ( V_26 -> V_7 , V_16 , & V_67 -> V_20 ) ;
if ( V_4 ) {
V_4 -> V_23 = V_24 ;
V_5 = V_4 -> V_5 ;
if ( ( V_5 -> V_55 & V_69 ) &&
F_34 ( & V_5 -> V_57 ) > 0 && ! F_50 ( V_5 , V_26 ) )
goto V_45;
}
V_5 = F_43 ( V_26 ) ;
if ( ! V_5 ) {
F_52 ( V_26 , L_7 ) ;
return NULL ;
}
F_22 ( & V_26 -> V_31 ) ;
if ( ! V_16 -> V_32 )
F_17 ( V_16 , & V_67 -> V_20 , V_5 ) ;
F_25 ( & V_26 -> V_31 ) ;
V_45:
F_47 ( 6 , L_8 ,
F_48 ( V_26 -> V_7 , & V_67 -> V_20 ) ,
F_48 ( V_26 -> V_7 , & V_5 -> V_9 ) , F_49 ( V_5 -> V_60 ) ) ;
return V_5 ;
}
static int T_2 F_53 ( struct V_36 * V_36 )
{
struct V_34 * V_35 = F_28 ( V_36 ) ;
if ( ! V_35 )
return - V_70 ;
if ( ! F_54 ( V_36 , & V_71 ) ) {
V_35 -> V_72 = F_55 ( V_73 ,
sizeof( V_73 ) ,
V_50 ) ;
if ( V_35 -> V_72 == NULL )
return - V_51 ;
if ( V_36 -> V_74 != & V_75 )
V_35 -> V_72 [ 0 ] . V_76 = NULL ;
} else
V_35 -> V_72 = V_73 ;
V_35 -> F_26 = V_37 ;
V_35 -> V_72 [ 0 ] . V_41 = & V_35 -> F_26 ;
V_35 -> V_77 =
F_56 ( V_36 , L_9 , V_35 -> V_72 ) ;
if ( ! V_35 -> V_77 ) {
if ( ! F_54 ( V_36 , & V_71 ) )
F_4 ( V_35 -> V_72 ) ;
return - V_51 ;
}
return 0 ;
}
static void T_3 F_57 ( struct V_36 * V_36 )
{
struct V_34 * V_35 = F_28 ( V_36 ) ;
F_58 ( V_35 -> V_77 ) ;
if ( ! F_54 ( V_36 , & V_71 ) )
F_4 ( V_35 -> V_72 ) ;
}
static int T_2 F_53 ( struct V_36 * V_36 ) { return 0 ; }
static void T_3 F_57 ( struct V_36 * V_36 ) { }
static int T_4 F_59 ( void )
{
int V_78 ;
V_78 = F_60 ( & V_79 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_61 ( & V_80 ) ;
if ( V_78 )
F_62 ( & V_79 ) ;
return V_78 ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_80 ) ;
F_62 ( & V_79 ) ;
F_65 () ;
}
