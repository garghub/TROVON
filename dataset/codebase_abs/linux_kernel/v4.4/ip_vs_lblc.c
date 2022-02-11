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
T_2 V_7 , struct V_21 * V_5 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_7 , V_16 , V_20 ) ;
if ( V_4 ) {
if ( V_4 -> V_5 == V_5 )
return V_4 ;
F_5 ( V_4 ) ;
}
V_4 = F_18 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = V_7 ;
F_19 ( V_7 , & V_4 -> V_9 , V_20 ) ;
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
return V_26 -> V_34 -> F_26 ;
#else
return V_35 ;
#endif
}
static inline void F_28 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
unsigned long V_36 = V_24 ;
int V_30 , V_37 ;
for ( V_30 = 0 , V_37 = V_16 -> V_38 ; V_30 < V_33 ; V_30 ++ ) {
V_37 = ( V_37 + 1 ) & V_14 ;
F_29 ( & V_26 -> V_31 ) ;
F_23 (en, next, &tbl->bucket[j], list) {
if ( F_30 ( V_36 ,
V_4 -> V_23 +
F_26 ( V_26 ) ) )
continue;
F_5 ( V_4 ) ;
F_24 ( & V_16 -> V_19 ) ;
}
F_31 ( & V_26 -> V_31 ) ;
}
V_16 -> V_38 = V_37 ;
}
static void F_32 ( unsigned long V_39 )
{
struct V_25 * V_26 = (struct V_25 * ) V_39 ;
struct V_15 * V_16 = V_26 -> V_27 ;
unsigned long V_36 = V_24 ;
int V_40 ;
int V_30 , V_37 ;
struct V_3 * V_4 ;
struct V_28 * V_29 ;
if ( ( V_16 -> V_41 % V_42 ) == 0 ) {
F_28 ( V_26 ) ;
V_16 -> V_41 = 1 ;
goto V_43;
}
if ( F_33 ( & V_16 -> V_19 ) <= V_16 -> V_44 ) {
V_16 -> V_41 ++ ;
goto V_43;
}
V_40 = ( F_33 ( & V_16 -> V_19 ) - V_16 -> V_44 ) * 4 / 3 ;
if ( V_40 > V_16 -> V_44 / 2 )
V_40 = V_16 -> V_44 / 2 ;
for ( V_30 = 0 , V_37 = V_16 -> V_38 ; V_30 < V_33 ; V_30 ++ ) {
V_37 = ( V_37 + 1 ) & V_14 ;
F_29 ( & V_26 -> V_31 ) ;
F_23 (en, next, &tbl->bucket[j], list) {
if ( F_30 ( V_36 , V_4 -> V_23 + V_45 ) )
continue;
F_5 ( V_4 ) ;
F_24 ( & V_16 -> V_19 ) ;
V_40 -- ;
}
F_31 ( & V_26 -> V_31 ) ;
if ( V_40 <= 0 )
break;
}
V_16 -> V_38 = V_37 ;
V_43:
F_34 ( & V_16 -> V_46 , V_24 + V_47 ) ;
}
static int F_35 ( struct V_25 * V_26 )
{
int V_30 ;
struct V_15 * V_16 ;
V_16 = F_18 ( sizeof( * V_16 ) , V_48 ) ;
if ( V_16 == NULL )
return - V_49 ;
V_26 -> V_27 = V_16 ;
F_36 ( 6 , L_1
L_2 , sizeof( * V_16 ) ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
F_37 ( & V_16 -> V_18 [ V_30 ] ) ;
}
V_16 -> V_44 = V_33 * 16 ;
V_16 -> V_38 = 0 ;
V_16 -> V_41 = 1 ;
V_16 -> V_32 = 0 ;
F_38 ( & V_16 -> V_46 , F_32 ,
( unsigned long ) V_26 ) ;
F_34 ( & V_16 -> V_46 , V_24 + V_47 ) ;
return 0 ;
}
static void F_39 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
F_40 ( & V_16 -> V_46 ) ;
F_21 ( V_26 ) ;
F_41 ( V_16 , V_1 ) ;
F_36 ( 6 , L_3 ,
sizeof( * V_16 ) ) ;
}
static inline struct V_21 *
F_42 ( struct V_25 * V_26 )
{
struct V_21 * V_5 , * V_50 ;
int V_51 , V_52 ;
F_43 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_53 & V_54 )
continue;
if ( F_33 ( & V_5 -> V_55 ) > 0 ) {
V_50 = V_5 ;
V_51 = F_44 ( V_50 ) ;
goto V_56;
}
}
return NULL ;
V_56:
F_45 (dest, &svc->destinations, n_list) {
if ( V_5 -> V_53 & V_54 )
continue;
V_52 = F_44 ( V_5 ) ;
if ( ( V_57 ) V_51 * F_33 ( & V_5 -> V_55 ) >
( V_57 ) V_52 * F_33 ( & V_50 -> V_55 ) ) {
V_50 = V_5 ;
V_51 = V_52 ;
}
}
F_46 ( 6 , L_4
L_5 ,
F_47 ( V_50 -> V_7 , & V_50 -> V_9 ) ,
F_48 ( V_50 -> V_58 ) ,
F_33 ( & V_50 -> V_59 ) ,
F_33 ( & V_50 -> V_60 ) ,
F_33 ( & V_50 -> V_55 ) , V_51 ) ;
return V_50 ;
}
static inline int
F_49 ( struct V_21 * V_5 , struct V_25 * V_26 )
{
if ( F_33 ( & V_5 -> V_59 ) > F_33 ( & V_5 -> V_55 ) ) {
struct V_21 * V_61 ;
F_43 (d, &svc->destinations, n_list) {
if ( F_33 ( & V_61 -> V_59 ) * 2
< F_33 ( & V_61 -> V_55 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_21 *
F_50 ( struct V_25 * V_26 , const struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_15 * V_16 = V_26 -> V_27 ;
struct V_21 * V_5 = NULL ;
struct V_3 * V_4 ;
F_36 ( 6 , L_6 , V_66 ) ;
V_4 = F_14 ( V_26 -> V_7 , V_16 , & V_65 -> V_20 ) ;
if ( V_4 ) {
V_4 -> V_23 = V_24 ;
V_5 = V_4 -> V_5 ;
if ( ( V_5 -> V_53 & V_67 ) &&
F_33 ( & V_5 -> V_55 ) > 0 && ! F_49 ( V_5 , V_26 ) )
goto V_43;
}
V_5 = F_42 ( V_26 ) ;
if ( ! V_5 ) {
F_51 ( V_26 , L_7 ) ;
return NULL ;
}
F_22 ( & V_26 -> V_31 ) ;
if ( ! V_16 -> V_32 )
F_17 ( V_16 , & V_65 -> V_20 , V_26 -> V_7 , V_5 ) ;
F_25 ( & V_26 -> V_31 ) ;
V_43:
F_46 ( 6 , L_8 ,
F_47 ( V_26 -> V_7 , & V_65 -> V_20 ) ,
F_47 ( V_5 -> V_7 , & V_5 -> V_9 ) , F_48 ( V_5 -> V_58 ) ) ;
return V_5 ;
}
static int T_3 F_52 ( struct V_68 * V_68 )
{
struct V_69 * V_34 = F_53 ( V_68 ) ;
if ( ! V_34 )
return - V_70 ;
if ( ! F_54 ( V_68 , & V_71 ) ) {
V_34 -> V_72 = F_55 ( V_73 ,
sizeof( V_73 ) ,
V_48 ) ;
if ( V_34 -> V_72 == NULL )
return - V_49 ;
if ( V_68 -> V_74 != & V_75 )
V_34 -> V_72 [ 0 ] . V_76 = NULL ;
} else
V_34 -> V_72 = V_73 ;
V_34 -> F_26 = V_35 ;
V_34 -> V_72 [ 0 ] . V_39 = & V_34 -> F_26 ;
V_34 -> V_77 =
F_56 ( V_68 , L_9 , V_34 -> V_72 ) ;
if ( ! V_34 -> V_77 ) {
if ( ! F_54 ( V_68 , & V_71 ) )
F_4 ( V_34 -> V_72 ) ;
return - V_49 ;
}
return 0 ;
}
static void T_4 F_57 ( struct V_68 * V_68 )
{
struct V_69 * V_34 = F_53 ( V_68 ) ;
F_58 ( V_34 -> V_77 ) ;
if ( ! F_54 ( V_68 , & V_71 ) )
F_4 ( V_34 -> V_72 ) ;
}
static int T_3 F_52 ( struct V_68 * V_68 ) { return 0 ; }
static void T_4 F_57 ( struct V_68 * V_68 ) { }
static int T_5 F_59 ( void )
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
static void T_6 F_63 ( void )
{
F_64 ( & V_80 ) ;
F_62 ( & V_79 ) ;
F_65 () ;
}
