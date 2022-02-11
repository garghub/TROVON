static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
struct V_6 * V_7 ;
if ( V_5 ) {
F_2 (e, &set->list, list) {
if ( V_7 -> V_4 == V_4 )
return;
}
}
V_7 = F_3 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL )
return;
F_4 ( V_4 ) ;
V_7 -> V_4 = V_4 ;
F_5 ( & V_7 -> V_9 , & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = V_12 ;
}
static void F_7 ( struct V_13 * V_14 )
{
struct V_6 * V_7 ;
V_7 = F_8 ( V_14 , struct V_6 , V_13 ) ;
F_9 ( V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
F_2 (e, &set->list, list) {
if ( V_7 -> V_4 == V_4 ) {
F_12 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = V_12 ;
F_13 ( & V_7 -> V_9 ) ;
F_14 ( & V_7 -> V_13 , F_7 ) ;
break;
}
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_15 ;
F_16 (e, ep, &set->list, list) {
F_13 ( & V_7 -> V_9 ) ;
F_14 ( & V_7 -> V_13 , F_7 ) ;
}
}
static inline struct V_3 * F_17 ( struct V_1 * V_2 )
{
register struct V_6 * V_7 ;
struct V_3 * V_4 , * V_16 ;
int V_17 , V_18 ;
F_18 (e, &set->list, list) {
V_16 = V_7 -> V_4 ;
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
V_4 = V_7 -> V_4 ;
if ( V_4 -> V_19 & V_20 )
continue;
V_18 = F_20 ( V_4 ) ;
if ( ( ( V_24 ) V_17 * F_19 ( & V_4 -> V_21 ) >
( V_24 ) V_18 * F_19 ( & V_16 -> V_21 ) )
&& ( V_4 -> V_19 & V_22 ) ) {
V_16 = V_4 ;
V_17 = V_18 ;
}
}
F_22 ( 6 , L_1
L_2 ,
V_25 ,
F_23 ( V_16 -> V_26 , & V_16 -> V_27 ) ,
F_24 ( V_16 -> V_28 ) ,
F_19 ( & V_16 -> V_29 ) ,
F_19 ( & V_16 -> V_30 ) ,
F_19 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline struct V_3 * F_25 ( struct V_1 * V_2 )
{
register struct V_6 * V_7 ;
struct V_3 * V_4 , * V_31 ;
int V_32 , V_18 ;
if ( V_2 == NULL )
return NULL ;
F_2 (e, &set->list, list) {
V_31 = V_7 -> V_4 ;
if ( F_19 ( & V_31 -> V_21 ) > 0 ) {
V_32 = F_20 ( V_31 ) ;
goto V_23;
}
}
return NULL ;
V_23:
F_26 (e, &set->list, list) {
V_4 = V_7 -> V_4 ;
V_18 = F_20 ( V_4 ) ;
if ( ( ( V_24 ) V_32 * F_19 ( & V_4 -> V_21 ) <
( V_24 ) V_18 * F_19 ( & V_31 -> V_21 ) )
&& ( F_19 ( & V_4 -> V_21 ) > 0 ) ) {
V_31 = V_4 ;
V_32 = V_18 ;
}
}
F_22 ( 6 , L_1
L_2 ,
V_25 ,
F_23 ( V_31 -> V_26 , & V_31 -> V_27 ) , F_24 ( V_31 -> V_28 ) ,
F_19 ( & V_31 -> V_29 ) ,
F_19 ( & V_31 -> V_30 ) ,
F_19 ( & V_31 -> V_21 ) , V_32 ) ;
return V_31 ;
}
static inline void F_27 ( struct V_33 * V_34 )
{
F_28 ( & V_34 -> V_9 ) ;
F_15 ( & V_34 -> V_2 ) ;
F_29 ( V_34 , V_13 ) ;
}
static inline unsigned int
F_30 ( int V_26 , const union V_35 * V_27 )
{
T_1 V_36 = V_27 -> V_37 ;
#ifdef F_31
if ( V_26 == V_38 )
V_36 = V_27 -> V_39 [ 0 ] ^ V_27 -> V_39 [ 1 ] ^
V_27 -> V_39 [ 2 ] ^ V_27 -> V_39 [ 3 ] ;
#endif
return ( F_32 ( V_36 ) * 2654435761UL ) & V_40 ;
}
static void
F_33 ( struct V_41 * V_42 , struct V_33 * V_34 )
{
unsigned int V_43 = F_30 ( V_34 -> V_26 , & V_34 -> V_27 ) ;
F_34 ( & V_34 -> V_9 , & V_42 -> V_44 [ V_43 ] ) ;
F_6 ( & V_42 -> V_45 ) ;
}
static inline struct V_33 *
F_35 ( int V_26 , struct V_41 * V_42 ,
const union V_35 * V_27 )
{
unsigned int V_43 = F_30 ( V_26 , V_27 ) ;
struct V_33 * V_34 ;
F_36 (en, &tbl->bucket[hash], list)
if ( F_37 ( V_26 , & V_34 -> V_27 , V_27 ) )
return V_34 ;
return NULL ;
}
static inline struct V_33 *
F_38 ( struct V_41 * V_42 , const union V_35 * V_46 ,
T_2 V_26 , struct V_3 * V_4 )
{
struct V_33 * V_34 ;
V_34 = F_35 ( V_26 , V_42 , V_46 ) ;
if ( ! V_34 ) {
V_34 = F_3 ( sizeof( * V_34 ) , V_8 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_26 = V_26 ;
F_39 ( V_26 , & V_34 -> V_27 , V_46 ) ;
V_34 -> V_47 = V_12 ;
F_40 ( & ( V_34 -> V_2 . V_10 ) , 0 ) ;
F_41 ( & V_34 -> V_2 . V_9 ) ;
F_1 ( & V_34 -> V_2 , V_4 , false ) ;
F_33 ( V_42 , V_34 ) ;
return V_34 ;
}
F_1 ( & V_34 -> V_2 , V_4 , true ) ;
return V_34 ;
}
static void F_42 ( struct V_48 * V_49 )
{
struct V_41 * V_42 = V_49 -> V_50 ;
int V_51 ;
struct V_33 * V_34 ;
struct V_52 * V_53 ;
F_43 ( & V_49 -> V_54 ) ;
V_42 -> V_55 = 1 ;
for ( V_51 = 0 ; V_51 < V_56 ; V_51 ++ ) {
F_44 (en, next, &tbl->bucket[i], list) {
F_27 ( V_34 ) ;
}
}
F_45 ( & V_49 -> V_54 ) ;
}
static int F_46 ( struct V_48 * V_49 )
{
#ifdef F_47
return V_49 -> V_57 -> F_46 ;
#else
return V_58 ;
#endif
}
static inline void F_48 ( struct V_48 * V_49 )
{
struct V_41 * V_42 = V_49 -> V_50 ;
unsigned long V_59 = V_12 ;
int V_51 , V_60 ;
struct V_33 * V_34 ;
struct V_52 * V_53 ;
for ( V_51 = 0 , V_60 = V_42 -> V_61 ; V_51 < V_56 ; V_51 ++ ) {
V_60 = ( V_60 + 1 ) & V_40 ;
F_49 ( & V_49 -> V_54 ) ;
F_44 (en, next, &tbl->bucket[j], list) {
if ( F_50 ( V_34 -> V_47 +
F_46 ( V_49 ) , V_59 ) )
continue;
F_27 ( V_34 ) ;
F_12 ( & V_42 -> V_45 ) ;
}
F_51 ( & V_49 -> V_54 ) ;
}
V_42 -> V_61 = V_60 ;
}
static void F_52 ( unsigned long V_62 )
{
struct V_48 * V_49 = (struct V_48 * ) V_62 ;
struct V_41 * V_42 = V_49 -> V_50 ;
unsigned long V_59 = V_12 ;
int V_63 ;
int V_51 , V_60 ;
struct V_33 * V_34 ;
struct V_52 * V_53 ;
if ( ( V_42 -> V_64 % V_65 ) == 0 ) {
F_48 ( V_49 ) ;
V_42 -> V_64 = 1 ;
goto V_66;
}
if ( F_19 ( & V_42 -> V_45 ) <= V_42 -> V_67 ) {
V_42 -> V_64 ++ ;
goto V_66;
}
V_63 = ( F_19 ( & V_42 -> V_45 ) - V_42 -> V_67 ) * 4 / 3 ;
if ( V_63 > V_42 -> V_67 / 2 )
V_63 = V_42 -> V_67 / 2 ;
for ( V_51 = 0 , V_60 = V_42 -> V_61 ; V_51 < V_56 ; V_51 ++ ) {
V_60 = ( V_60 + 1 ) & V_40 ;
F_49 ( & V_49 -> V_54 ) ;
F_44 (en, next, &tbl->bucket[j], list) {
if ( F_53 ( V_59 , V_34 -> V_47 + V_68 ) )
continue;
F_27 ( V_34 ) ;
F_12 ( & V_42 -> V_45 ) ;
V_63 -- ;
}
F_51 ( & V_49 -> V_54 ) ;
if ( V_63 <= 0 )
break;
}
V_42 -> V_61 = V_60 ;
V_66:
F_54 ( & V_42 -> V_69 , V_12 + V_70 ) ;
}
static int F_55 ( struct V_48 * V_49 )
{
int V_51 ;
struct V_41 * V_42 ;
V_42 = F_3 ( sizeof( * V_42 ) , V_71 ) ;
if ( V_42 == NULL )
return - V_72 ;
V_49 -> V_50 = V_42 ;
F_56 ( 6 , L_3
L_4 , sizeof( * V_42 ) ) ;
for ( V_51 = 0 ; V_51 < V_56 ; V_51 ++ ) {
F_57 ( & V_42 -> V_44 [ V_51 ] ) ;
}
V_42 -> V_67 = V_56 * 16 ;
V_42 -> V_61 = 0 ;
V_42 -> V_64 = 1 ;
V_42 -> V_55 = 0 ;
F_58 ( & V_42 -> V_69 , F_52 ,
( unsigned long ) V_49 ) ;
F_54 ( & V_42 -> V_69 , V_12 + V_70 ) ;
return 0 ;
}
static void F_59 ( struct V_48 * V_49 )
{
struct V_41 * V_42 = V_49 -> V_50 ;
F_60 ( & V_42 -> V_69 ) ;
F_42 ( V_49 ) ;
F_29 ( V_42 , V_13 ) ;
F_56 ( 6 , L_5 ,
sizeof( * V_42 ) ) ;
}
static inline struct V_3 *
F_61 ( struct V_48 * V_49 )
{
struct V_3 * V_4 , * V_16 ;
int V_17 , V_18 ;
F_18 (dest, &svc->destinations, n_list) {
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
if ( ( V_24 ) V_17 * F_19 ( & V_4 -> V_21 ) >
( V_24 ) V_18 * F_19 ( & V_16 -> V_21 ) ) {
V_16 = V_4 ;
V_17 = V_18 ;
}
}
F_22 ( 6 , L_6
L_2 ,
F_23 ( V_16 -> V_26 , & V_16 -> V_27 ) ,
F_24 ( V_16 -> V_28 ) ,
F_19 ( & V_16 -> V_29 ) ,
F_19 ( & V_16 -> V_30 ) ,
F_19 ( & V_16 -> V_21 ) , V_17 ) ;
return V_16 ;
}
static inline int
F_62 ( struct V_3 * V_4 , struct V_48 * V_49 )
{
if ( F_19 ( & V_4 -> V_29 ) > F_19 ( & V_4 -> V_21 ) ) {
struct V_3 * V_73 ;
F_18 (d, &svc->destinations, n_list) {
if ( F_19 ( & V_73 -> V_29 ) * 2
< F_19 ( & V_73 -> V_21 ) ) {
return 1 ;
}
}
}
return 0 ;
}
static struct V_3 *
F_63 ( struct V_48 * V_49 , const struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_41 * V_42 = V_49 -> V_50 ;
struct V_3 * V_4 ;
struct V_33 * V_34 ;
F_56 ( 6 , L_7 , V_25 ) ;
V_34 = F_35 ( V_49 -> V_26 , V_42 , & V_77 -> V_46 ) ;
if ( V_34 ) {
V_34 -> V_47 = V_12 ;
V_4 = F_17 ( & V_34 -> V_2 ) ;
if ( F_19 ( & V_34 -> V_2 . V_10 ) > 1 &&
F_50 ( V_12 , V_34 -> V_2 . V_11 +
F_46 ( V_49 ) ) ) {
F_43 ( & V_49 -> V_54 ) ;
if ( F_19 ( & V_34 -> V_2 . V_10 ) > 1 ) {
struct V_3 * V_78 ;
V_78 = F_25 ( & V_34 -> V_2 ) ;
if ( V_78 )
F_11 ( & V_34 -> V_2 , V_78 ) ;
}
F_45 ( & V_49 -> V_54 ) ;
}
if ( V_4 && ! F_62 ( V_4 , V_49 ) )
goto V_66;
V_4 = F_61 ( V_49 ) ;
if ( ! V_4 ) {
F_64 ( V_49 , L_8 ) ;
return NULL ;
}
F_43 ( & V_49 -> V_54 ) ;
if ( ! V_42 -> V_55 )
F_1 ( & V_34 -> V_2 , V_4 , true ) ;
F_45 ( & V_49 -> V_54 ) ;
goto V_66;
}
V_4 = F_61 ( V_49 ) ;
if ( ! V_4 ) {
F_56 ( 1 , L_9 ) ;
return NULL ;
}
F_43 ( & V_49 -> V_54 ) ;
if ( ! V_42 -> V_55 )
F_38 ( V_42 , & V_77 -> V_46 , V_49 -> V_26 , V_4 ) ;
F_45 ( & V_49 -> V_54 ) ;
V_66:
F_22 ( 6 , L_10 ,
F_23 ( V_49 -> V_26 , & V_77 -> V_46 ) ,
F_23 ( V_4 -> V_26 , & V_4 -> V_27 ) , F_24 ( V_4 -> V_28 ) ) ;
return V_4 ;
}
static int T_3 F_65 ( struct V_79 * V_79 )
{
struct V_80 * V_57 = F_66 ( V_79 ) ;
if ( ! V_57 )
return - V_81 ;
if ( ! F_67 ( V_79 , & V_82 ) ) {
V_57 -> V_83 = F_68 ( V_84 ,
sizeof( V_84 ) ,
V_71 ) ;
if ( V_57 -> V_83 == NULL )
return - V_72 ;
if ( V_79 -> V_85 != & V_86 )
V_57 -> V_83 [ 0 ] . V_87 = NULL ;
} else
V_57 -> V_83 = V_84 ;
V_57 -> F_46 = V_58 ;
V_57 -> V_83 [ 0 ] . V_62 = & V_57 -> F_46 ;
V_57 -> V_88 =
F_69 ( V_79 , L_11 , V_57 -> V_83 ) ;
if ( ! V_57 -> V_88 ) {
if ( ! F_67 ( V_79 , & V_82 ) )
F_10 ( V_57 -> V_83 ) ;
return - V_72 ;
}
return 0 ;
}
static void T_4 F_70 ( struct V_79 * V_79 )
{
struct V_80 * V_57 = F_66 ( V_79 ) ;
F_71 ( V_57 -> V_88 ) ;
if ( ! F_67 ( V_79 , & V_82 ) )
F_10 ( V_57 -> V_83 ) ;
}
static int T_3 F_65 ( struct V_79 * V_79 ) { return 0 ; }
static void T_4 F_70 ( struct V_79 * V_79 ) { }
static int T_5 F_72 ( void )
{
int V_89 ;
V_89 = F_73 ( & V_90 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_74 ( & V_91 ) ;
if ( V_89 )
F_75 ( & V_90 ) ;
return V_89 ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_91 ) ;
F_75 ( & V_90 ) ;
F_78 () ;
}
