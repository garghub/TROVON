static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
struct V_6 * V_7 ;
if ( V_5 ) {
F_2 (e, &set->list, list) {
struct V_3 * V_8 ;
V_8 = F_3 ( V_7 -> V_4 , 1 ) ;
if ( V_8 == V_4 )
return;
}
}
V_7 = F_4 ( sizeof( * V_7 ) , V_9 ) ;
if ( V_7 == NULL )
return;
F_5 ( V_4 ) ;
F_6 ( V_7 -> V_4 , V_4 ) ;
F_7 ( & V_7 -> V_10 , & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_11 ) ;
V_2 -> V_12 = V_13 ;
}
static void
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
F_2 (e, &set->list, list) {
struct V_3 * V_8 ;
V_8 = F_3 ( V_7 -> V_4 , 1 ) ;
if ( V_8 == V_4 ) {
F_10 ( & V_2 -> V_11 ) ;
V_2 -> V_12 = V_13 ;
F_11 ( V_4 ) ;
F_12 ( & V_7 -> V_10 ) ;
F_13 ( V_7 , V_14 ) ;
break;
}
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_15 ;
F_15 (e, ep, &set->list, list) {
struct V_3 * V_8 ;
V_8 = F_3 ( V_7 -> V_4 , 1 ) ;
F_11 ( V_8 ) ;
F_12 ( & V_7 -> V_10 ) ;
F_13 ( V_7 , V_14 ) ;
}
}
static inline struct V_3 * F_16 ( struct V_1 * V_2 )
{
register struct V_6 * V_7 ;
struct V_3 * V_4 , * V_16 ;
int V_17 , V_18 ;
if ( V_2 == NULL )
return NULL ;
F_17 (e, &set->list, list) {
V_16 = F_18 ( V_7 -> V_4 ) ;
if ( V_16 -> V_19 & V_20 )
continue;
if ( ( F_19 ( & V_16 -> V_21 ) > 0 )
&& ( V_16 -> V_19 & V_22 ) ) {
V_17 = F_20 ( V_16 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_21 (e, &set->list, list) {
V_4 = F_18 ( V_7 -> V_4 ) ;
if ( V_4 -> V_19 & V_20 )
continue;
V_18 = F_20 ( V_4 ) ;
if ( ( V_17 * F_19 ( & V_4 -> V_21 ) >
V_18 * F_19 ( & V_16 -> V_21 ) )
&& ( V_4 -> V_19 & V_22 ) ) {
V_16 = V_4 ;
V_17 = V_18 ;
}
}
F_22 ( 6 , L_1
L_2 ,
V_24 ,
F_23 ( V_16 -> V_25 , & V_16 -> V_26 ) ,
F_24 ( V_16 -> V_27 ) ,
F_19 ( & V_16 -> V_28 ) ,
F_19 ( & V_16 -> V_29 ) ,
F_19 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline struct V_3 * F_25 ( struct V_1 * V_2 )
{
register struct V_6 * V_7 ;
struct V_3 * V_4 , * V_30 ;
int V_31 , V_18 ;
if ( V_2 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_30 = F_3 ( V_7 -> V_4 , 1 ) ;
if ( F_19 ( & V_30 -> V_21 ) > 0 ) {
V_31 = F_20 ( V_30 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_26 (e, &set->list, list) {
V_4 = F_3 ( V_7 -> V_4 , 1 ) ;
V_18 = F_20 ( V_4 ) ;
if ( ( V_31 * F_19 ( & V_4 -> V_21 ) <
V_18 * F_19 ( & V_30 -> V_21 ) )
&& ( F_19 ( & V_4 -> V_21 ) > 0 ) ) {
V_30 = V_4 ;
V_31 = V_18 ;
}
}
F_22 ( 6 , L_1
L_2 ,
V_24 ,
F_23 ( V_30 -> V_25 , & V_30 -> V_26 ) , F_24 ( V_30 -> V_27 ) ,
F_19 ( & V_30 -> V_28 ) ,
F_19 ( & V_30 -> V_29 ) ,
F_19 ( & V_30 -> V_21 ) , V_31 ) ;
return V_30 ;
}
static inline void F_27 ( struct V_32 * V_33 )
{
F_28 ( & V_33 -> V_10 ) ;
F_14 ( & V_33 -> V_2 ) ;
F_13 ( V_33 , V_14 ) ;
}
static inline unsigned int
F_29 ( int V_25 , const union V_34 * V_26 )
{
T_1 V_35 = V_26 -> V_36 ;
#ifdef F_30
if ( V_25 == V_37 )
V_35 = V_26 -> V_38 [ 0 ] ^ V_26 -> V_38 [ 1 ] ^
V_26 -> V_38 [ 2 ] ^ V_26 -> V_38 [ 3 ] ;
#endif
return ( F_31 ( V_35 ) * 2654435761UL ) & V_39 ;
}
static void
F_32 ( struct V_40 * V_41 , struct V_32 * V_33 )
{
unsigned int V_42 = F_29 ( V_33 -> V_25 , & V_33 -> V_26 ) ;
F_33 ( & V_33 -> V_10 , & V_41 -> V_43 [ V_42 ] ) ;
F_8 ( & V_41 -> V_44 ) ;
}
static inline struct V_32 *
F_34 ( int V_25 , struct V_40 * V_41 ,
const union V_34 * V_26 )
{
unsigned int V_42 = F_29 ( V_25 , V_26 ) ;
struct V_32 * V_33 ;
F_35 (en, &tbl->bucket[hash], list)
if ( F_36 ( V_25 , & V_33 -> V_26 , V_26 ) )
return V_33 ;
return NULL ;
}
static inline struct V_32 *
F_37 ( struct V_40 * V_41 , const union V_34 * V_45 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 ;
V_33 = F_34 ( V_4 -> V_25 , V_41 , V_45 ) ;
if ( ! V_33 ) {
V_33 = F_4 ( sizeof( * V_33 ) , V_9 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_25 = V_4 -> V_25 ;
F_38 ( V_4 -> V_25 , & V_33 -> V_26 , V_45 ) ;
V_33 -> V_46 = V_13 ;
F_39 ( & ( V_33 -> V_2 . V_11 ) , 0 ) ;
F_40 ( & V_33 -> V_2 . V_10 ) ;
F_1 ( & V_33 -> V_2 , V_4 , false ) ;
F_32 ( V_41 , V_33 ) ;
return V_33 ;
}
F_1 ( & V_33 -> V_2 , V_4 , true ) ;
return V_33 ;
}
static void F_41 ( struct V_47 * V_48 )
{
struct V_40 * V_41 = V_48 -> V_49 ;
int V_50 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
F_42 ( & V_48 -> V_53 ) ;
V_41 -> V_54 = 1 ;
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ ) {
F_43 (en, next, &tbl->bucket[i], list) {
F_27 ( V_33 ) ;
}
}
F_44 ( & V_48 -> V_53 ) ;
}
static int F_45 ( struct V_47 * V_48 )
{
#ifdef F_46
struct V_56 * V_57 = F_47 ( V_48 -> V_58 ) ;
return V_57 -> F_45 ;
#else
return V_59 ;
#endif
}
static inline void F_48 ( struct V_47 * V_48 )
{
struct V_40 * V_41 = V_48 -> V_49 ;
unsigned long V_60 = V_13 ;
int V_50 , V_61 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
for ( V_50 = 0 , V_61 = V_41 -> V_62 ; V_50 < V_55 ; V_50 ++ ) {
V_61 = ( V_61 + 1 ) & V_39 ;
F_49 ( & V_48 -> V_53 ) ;
F_43 (en, next, &tbl->bucket[j], list) {
if ( F_50 ( V_33 -> V_46 +
F_45 ( V_48 ) , V_60 ) )
continue;
F_27 ( V_33 ) ;
F_10 ( & V_41 -> V_44 ) ;
}
F_51 ( & V_48 -> V_53 ) ;
}
V_41 -> V_62 = V_61 ;
}
static void F_52 ( unsigned long V_63 )
{
struct V_47 * V_48 = (struct V_47 * ) V_63 ;
struct V_40 * V_41 = V_48 -> V_49 ;
unsigned long V_60 = V_13 ;
int V_64 ;
int V_50 , V_61 ;
struct V_32 * V_33 ;
struct V_51 * V_52 ;
if ( ( V_41 -> V_65 % V_66 ) == 0 ) {
F_48 ( V_48 ) ;
V_41 -> V_65 = 1 ;
goto V_67;
}
if ( F_19 ( & V_41 -> V_44 ) <= V_41 -> V_68 ) {
V_41 -> V_65 ++ ;
goto V_67;
}
V_64 = ( F_19 ( & V_41 -> V_44 ) - V_41 -> V_68 ) * 4 / 3 ;
if ( V_64 > V_41 -> V_68 / 2 )
V_64 = V_41 -> V_68 / 2 ;
for ( V_50 = 0 , V_61 = V_41 -> V_62 ; V_50 < V_55 ; V_50 ++ ) {
V_61 = ( V_61 + 1 ) & V_39 ;
F_49 ( & V_48 -> V_53 ) ;
F_43 (en, next, &tbl->bucket[j], list) {
if ( F_53 ( V_60 , V_33 -> V_46 + V_69 ) )
continue;
F_27 ( V_33 ) ;
F_10 ( & V_41 -> V_44 ) ;
V_64 -- ;
}
F_51 ( & V_48 -> V_53 ) ;
if ( V_64 <= 0 )
break;
}
V_41 -> V_62 = V_61 ;
V_67:
F_54 ( & V_41 -> V_70 , V_13 + V_71 ) ;
}
static int F_55 ( struct V_47 * V_48 )
{
int V_50 ;
struct V_40 * V_41 ;
V_41 = F_4 ( sizeof( * V_41 ) , V_72 ) ;
if ( V_41 == NULL )
return - V_73 ;
V_48 -> V_49 = V_41 ;
F_56 ( 6 , L_3
L_4 , sizeof( * V_41 ) ) ;
for ( V_50 = 0 ; V_50 < V_55 ; V_50 ++ ) {
F_57 ( & V_41 -> V_43 [ V_50 ] ) ;
}
V_41 -> V_68 = V_55 * 16 ;
V_41 -> V_62 = 0 ;
V_41 -> V_65 = 1 ;
V_41 -> V_54 = 0 ;
F_58 ( & V_41 -> V_70 , F_52 ,
( unsigned long ) V_48 ) ;
F_54 ( & V_41 -> V_70 , V_13 + V_71 ) ;
return 0 ;
}
static void F_59 ( struct V_47 * V_48 )
{
struct V_40 * V_41 = V_48 -> V_49 ;
F_60 ( & V_41 -> V_70 ) ;
F_41 ( V_48 ) ;
F_13 ( V_41 , V_14 ) ;
F_56 ( 6 , L_5 ,
sizeof( * V_41 ) ) ;
}
static inline struct V_3 *
F_61 ( struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_16 ;
int V_17 , V_18 ;
F_17 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_19 & V_20 )
continue;
if ( F_19 ( & V_4 -> V_21 ) > 0 ) {
V_16 = V_4 ;
V_17 = F_20 ( V_16 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_21 (dest, &svc->destinations, n_list) {
if ( V_4 -> V_19 & V_20 )
continue;
V_18 = F_20 ( V_4 ) ;
if ( V_17 * F_19 ( & V_4 -> V_21 ) >
V_18 * F_19 ( & V_16 -> V_21 ) ) {
V_16 = V_4 ;
V_17 = V_18 ;
}
}
F_22 ( 6 , L_6
L_2 ,
F_23 ( V_16 -> V_25 , & V_16 -> V_26 ) ,
F_24 ( V_16 -> V_27 ) ,
F_19 ( & V_16 -> V_28 ) ,
F_19 ( & V_16 -> V_29 ) ,
F_19 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline int
F_62 ( struct V_3 * V_4 , struct V_47 * V_48 )
{
if ( F_19 ( & V_4 -> V_28 ) > F_19 ( & V_4 -> V_21 ) ) {
struct V_3 * V_8 ;
F_17 (d, &svc->destinations, n_list) {
if ( F_19 ( & V_8 -> V_28 ) * 2
< F_19 ( & V_8 -> V_21 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_3 *
F_63 ( struct V_47 * V_48 , const struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_40 * V_41 = V_48 -> V_49 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
F_56 ( 6 , L_7 , V_24 ) ;
V_33 = F_34 ( V_48 -> V_25 , V_41 , & V_77 -> V_45 ) ;
if ( V_33 ) {
V_33 -> V_46 = V_13 ;
V_4 = F_16 ( & V_33 -> V_2 ) ;
if ( F_19 ( & V_33 -> V_2 . V_11 ) > 1 &&
F_50 ( V_13 , V_33 -> V_2 . V_12 +
F_45 ( V_48 ) ) ) {
F_42 ( & V_48 -> V_53 ) ;
if ( F_19 ( & V_33 -> V_2 . V_11 ) > 1 ) {
struct V_3 * V_78 ;
V_78 = F_25 ( & V_33 -> V_2 ) ;
if ( V_78 )
F_9 ( & V_33 -> V_2 , V_78 ) ;
}
F_44 ( & V_48 -> V_53 ) ;
}
if ( V_4 && ! F_62 ( V_4 , V_48 ) )
goto V_67;
V_4 = F_61 ( V_48 ) ;
if ( ! V_4 ) {
F_64 ( V_48 , L_8 ) ;
return NULL ;
}
F_42 ( & V_48 -> V_53 ) ;
if ( ! V_41 -> V_54 )
F_1 ( & V_33 -> V_2 , V_4 , true ) ;
F_44 ( & V_48 -> V_53 ) ;
goto V_67;
}
V_4 = F_61 ( V_48 ) ;
if ( ! V_4 ) {
F_56 ( 1 , L_9 ) ;
return NULL ;
}
F_42 ( & V_48 -> V_53 ) ;
if ( ! V_41 -> V_54 )
F_37 ( V_41 , & V_77 -> V_45 , V_4 ) ;
F_44 ( & V_48 -> V_53 ) ;
V_67:
F_22 ( 6 , L_10 ,
F_23 ( V_48 -> V_25 , & V_77 -> V_45 ) ,
F_23 ( V_48 -> V_25 , & V_4 -> V_26 ) , F_24 ( V_4 -> V_27 ) ) ;
return V_4 ;
}
static int T_2 F_65 ( struct V_58 * V_58 )
{
struct V_56 * V_57 = F_47 ( V_58 ) ;
if ( ! V_57 )
return - V_79 ;
if ( ! F_66 ( V_58 , & V_80 ) ) {
V_57 -> V_81 = F_67 ( V_82 ,
sizeof( V_82 ) ,
V_72 ) ;
if ( V_57 -> V_81 == NULL )
return - V_73 ;
if ( V_58 -> V_83 != & V_84 )
V_57 -> V_81 [ 0 ] . V_85 = NULL ;
} else
V_57 -> V_81 = V_82 ;
V_57 -> F_45 = V_59 ;
V_57 -> V_81 [ 0 ] . V_63 = & V_57 -> F_45 ;
V_57 -> V_86 =
F_68 ( V_58 , L_11 , V_57 -> V_81 ) ;
if ( ! V_57 -> V_86 ) {
if ( ! F_66 ( V_58 , & V_80 ) )
F_69 ( V_57 -> V_81 ) ;
return - V_73 ;
}
return 0 ;
}
static void T_3 F_70 ( struct V_58 * V_58 )
{
struct V_56 * V_57 = F_47 ( V_58 ) ;
F_71 ( V_57 -> V_86 ) ;
if ( ! F_66 ( V_58 , & V_80 ) )
F_69 ( V_57 -> V_81 ) ;
}
static int T_2 F_65 ( struct V_58 * V_58 ) { return 0 ; }
static void T_3 F_70 ( struct V_58 * V_58 ) { }
static int T_4 F_72 ( void )
{
int V_87 ;
V_87 = F_73 ( & V_88 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_74 ( & V_89 ) ;
if ( V_87 )
F_75 ( & V_88 ) ;
return V_87 ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_89 ) ;
F_75 ( & V_88 ) ;
F_78 () ;
}
