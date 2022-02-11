static unsigned int
F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
return V_2 -> V_5 ( V_4 ) & ( V_6 - 1 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_7 ,
V_2 -> V_8 + V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_10 ;
F_5 ( & V_2 -> V_11 ) ;
if ( ! F_2 ( V_2 ) )
goto V_12;
F_6 ( & V_2 -> V_13 , sizeof( V_14 ) ) ;
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ ) {
struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_17 * V_18 ;
V_16 = & V_2 -> V_19 [ V_10 ] ;
F_7 ( & V_16 -> V_20 ) ;
F_8 (q, n, &hb->chain, list) {
unsigned int V_21 = F_1 ( V_2 , V_4 ) ;
if ( V_21 != V_10 ) {
struct V_15 * V_22 ;
F_9 ( & V_4 -> V_23 ) ;
V_22 = & V_2 -> V_19 [ V_21 ] ;
F_10 ( & V_22 -> V_20 ,
V_24 ) ;
F_11 ( & V_4 -> V_23 , & V_22 -> V_25 ) ;
F_12 ( & V_22 -> V_20 ) ;
}
}
F_12 ( & V_16 -> V_20 ) ;
}
V_2 -> V_26 = false ;
V_2 -> V_8 = V_7 ;
V_12:
F_13 ( & V_2 -> V_11 ) ;
}
static bool F_14 ( const struct V_3 * V_4 )
{
return V_4 -> V_27 -> V_28 == 0 ||
F_15 ( V_4 -> V_27 ) >= V_4 -> V_27 -> V_28 ;
}
static unsigned int
F_16 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_29 ;
struct V_17 * V_18 ;
unsigned int V_30 = 0 ;
F_17 ( V_31 ) ;
F_7 ( & V_16 -> V_20 ) ;
F_8 (fq, n, &hb->chain, list) {
if ( ! F_14 ( V_29 ) )
continue;
if ( ! F_18 ( & V_29 -> V_32 ) )
continue;
F_11 ( & V_29 -> V_33 , & V_31 ) ;
++ V_30 ;
}
F_12 ( & V_16 -> V_20 ) ;
F_8 (fq, n, &expired, list_evictor)
V_2 -> V_34 ( ( unsigned long ) V_29 ) ;
return V_30 ;
}
static void F_19 ( struct V_35 * V_36 )
{
unsigned int V_37 = V_38 ;
unsigned int V_10 , V_30 = 0 ;
struct V_1 * V_2 ;
V_2 = F_20 ( V_36 , struct V_1 , V_39 ) ;
F_21 ( V_38 >= V_6 ) ;
F_22 () ;
for ( V_10 = F_23 ( V_2 -> V_40 ) ; V_37 ; -- V_37 ) {
V_30 += F_16 ( V_2 , & V_2 -> V_19 [ V_10 ] ) ;
V_10 = ( V_10 + 1 ) & ( V_6 - 1 ) ;
if ( V_30 > V_41 )
break;
}
V_2 -> V_40 = V_10 ;
F_24 () ;
if ( V_2 -> V_26 && F_2 ( V_2 ) )
F_4 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_26 ( ! F_27 ( & V_2 -> V_39 ) ) )
F_28 ( & V_2 -> V_39 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
F_30 ( & V_2 -> V_39 , F_19 ) ;
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ ) {
struct V_15 * V_16 = & V_2 -> V_19 [ V_10 ] ;
F_31 ( & V_16 -> V_20 ) ;
F_32 ( & V_16 -> V_25 ) ;
}
F_33 ( & V_2 -> V_11 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_42 = F_34 ( V_2 -> V_43 , V_2 -> V_44 , 0 , 0 ,
NULL ) ;
if ( ! V_2 -> V_42 )
return - V_45 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_39 ) ;
F_37 ( V_2 -> V_42 ) ;
}
void F_38 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
unsigned int V_48 ;
int V_10 ;
V_47 -> V_28 = 0 ;
V_49:
F_22 () ;
V_48 = F_39 ( & V_2 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ )
F_16 ( V_2 , & V_2 -> V_19 [ V_10 ] ) ;
F_24 () ;
F_40 () ;
if ( F_41 ( & V_2 -> V_11 , V_48 ) ||
F_42 ( & V_47 -> V_50 ) )
goto V_49;
F_43 ( & V_47 -> V_50 ) ;
}
static struct V_15 *
F_44 ( struct V_3 * V_29 , struct V_1 * V_2 )
__acquires( V_16 -> V_20 )
{
struct V_15 * V_16 ;
unsigned int V_48 , V_19 ;
V_51:
V_48 = F_39 ( & V_2 -> V_11 ) ;
V_19 = F_1 ( V_2 , V_29 ) ;
V_16 = & V_2 -> V_19 [ V_19 ] ;
F_7 ( & V_16 -> V_20 ) ;
if ( F_41 ( & V_2 -> V_11 , V_48 ) ) {
F_12 ( & V_16 -> V_20 ) ;
goto V_51;
}
return V_16 ;
}
static inline void F_45 ( struct V_3 * V_29 , struct V_1 * V_2 )
{
struct V_15 * V_16 ;
V_16 = F_44 ( V_29 , V_2 ) ;
F_9 ( & V_29 -> V_23 ) ;
V_29 -> V_52 |= V_53 ;
F_12 ( & V_16 -> V_20 ) ;
}
void F_46 ( struct V_3 * V_29 , struct V_1 * V_2 )
{
if ( F_18 ( & V_29 -> V_32 ) )
F_47 ( & V_29 -> V_54 ) ;
if ( ! ( V_29 -> V_52 & V_53 ) ) {
F_45 ( V_29 , V_2 ) ;
F_47 ( & V_29 -> V_54 ) ;
}
}
static inline void F_48 ( struct V_46 * V_47 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
if ( V_2 -> V_57 )
V_2 -> V_57 ( V_56 ) ;
F_49 ( V_56 ) ;
}
void F_50 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_55 * V_58 ;
struct V_46 * V_47 ;
unsigned int V_59 , V_60 = 0 ;
F_51 ( ! ( V_4 -> V_52 & V_53 ) ) ;
F_51 ( F_18 ( & V_4 -> V_32 ) != 0 ) ;
V_58 = V_4 -> V_61 ;
V_47 = V_4 -> V_27 ;
while ( V_58 ) {
struct V_55 * V_62 = V_58 -> V_63 ;
V_60 += V_58 -> V_64 ;
F_48 ( V_47 , V_2 , V_58 ) ;
V_58 = V_62 ;
}
V_59 = V_60 + V_2 -> V_44 ;
if ( V_2 -> V_65 )
V_2 -> V_65 ( V_4 ) ;
F_52 ( V_2 -> V_42 , V_4 ) ;
F_53 ( V_47 , V_59 ) ;
}
static struct V_3 * F_54 ( struct V_46 * V_47 ,
struct V_3 * V_66 ,
struct V_1 * V_2 ,
void * V_67 )
{
struct V_15 * V_16 = F_44 ( V_66 , V_2 ) ;
struct V_3 * V_68 ;
#ifdef F_55
F_56 (qp, &hb->chain, list) {
if ( V_68 -> V_27 == V_47 && V_2 -> V_69 ( V_68 , V_67 ) ) {
F_57 ( & V_68 -> V_54 ) ;
F_12 ( & V_16 -> V_20 ) ;
V_66 -> V_52 |= V_53 ;
F_58 ( V_66 , V_2 ) ;
return V_68 ;
}
}
#endif
V_68 = V_66 ;
if ( ! F_59 ( & V_68 -> V_32 , V_7 + V_47 -> V_70 ) )
F_57 ( & V_68 -> V_54 ) ;
F_57 ( & V_68 -> V_54 ) ;
F_11 ( & V_68 -> V_23 , & V_16 -> V_25 ) ;
F_12 ( & V_16 -> V_20 ) ;
return V_68 ;
}
static struct V_3 * F_60 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
void * V_67 )
{
struct V_3 * V_4 ;
if ( F_15 ( V_47 ) > V_47 -> V_71 ) {
F_25 ( V_2 ) ;
return NULL ;
}
V_4 = F_61 ( V_2 -> V_42 , V_72 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_27 = V_47 ;
V_2 -> V_73 ( V_4 , V_67 ) ;
F_62 ( V_47 , V_2 -> V_44 ) ;
F_63 ( & V_4 -> V_32 , V_2 -> V_34 , ( unsigned long ) V_4 ) ;
F_31 ( & V_4 -> V_74 ) ;
F_64 ( & V_4 -> V_54 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_65 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
void * V_67 )
{
struct V_3 * V_4 ;
V_4 = F_60 ( V_47 , V_2 , V_67 ) ;
if ( ! V_4 )
return NULL ;
return F_54 ( V_47 , V_4 , V_2 , V_67 ) ;
}
struct V_3 * F_66 ( struct V_46 * V_47 ,
struct V_1 * V_2 , void * V_75 ,
unsigned int V_19 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_76 = 0 ;
if ( F_15 ( V_47 ) > V_47 -> V_28 )
F_25 ( V_2 ) ;
V_19 &= ( V_6 - 1 ) ;
V_16 = & V_2 -> V_19 [ V_19 ] ;
F_7 ( & V_16 -> V_20 ) ;
F_56 (q, &hb->chain, list) {
if ( V_4 -> V_27 == V_47 && V_2 -> V_69 ( V_4 , V_75 ) ) {
F_57 ( & V_4 -> V_54 ) ;
F_12 ( & V_16 -> V_20 ) ;
return V_4 ;
}
V_76 ++ ;
}
F_12 ( & V_16 -> V_20 ) ;
if ( V_76 <= V_77 )
return F_65 ( V_47 , V_2 , V_75 ) ;
if ( F_2 ( V_2 ) ) {
if ( ! V_2 -> V_26 )
V_2 -> V_26 = true ;
F_25 ( V_2 ) ;
}
return F_67 ( - V_78 ) ;
}
void F_68 ( struct V_3 * V_4 ,
const char * V_79 )
{
static const char V_80 [] = L_1
L_2 F_69 ( V_77 )
L_3 ;
if ( F_70 ( V_4 ) == - V_78 )
F_71 ( L_4 , V_79 , V_80 ) ;
}
