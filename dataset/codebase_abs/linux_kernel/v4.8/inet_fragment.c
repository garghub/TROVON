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
void F_48 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_55 * V_56 ;
struct V_46 * V_47 ;
unsigned int V_57 , V_58 = 0 ;
F_49 ( ! ( V_4 -> V_52 & V_53 ) ) ;
F_49 ( F_18 ( & V_4 -> V_32 ) != 0 ) ;
V_56 = V_4 -> V_59 ;
V_47 = V_4 -> V_27 ;
while ( V_56 ) {
struct V_55 * V_60 = V_56 -> V_61 ;
V_58 += V_56 -> V_62 ;
F_50 ( V_56 ) ;
V_56 = V_60 ;
}
V_57 = V_58 + V_2 -> V_44 ;
if ( V_2 -> V_63 )
V_2 -> V_63 ( V_4 ) ;
F_51 ( V_2 -> V_42 , V_4 ) ;
F_52 ( V_47 , V_57 ) ;
}
static struct V_3 * F_53 ( struct V_46 * V_47 ,
struct V_3 * V_64 ,
struct V_1 * V_2 ,
void * V_65 )
{
struct V_15 * V_16 = F_44 ( V_64 , V_2 ) ;
struct V_3 * V_66 ;
#ifdef F_54
F_55 (qp, &hb->chain, list) {
if ( V_66 -> V_27 == V_47 && V_2 -> V_67 ( V_66 , V_65 ) ) {
F_56 ( & V_66 -> V_54 ) ;
F_12 ( & V_16 -> V_20 ) ;
V_64 -> V_52 |= V_53 ;
F_57 ( V_64 , V_2 ) ;
return V_66 ;
}
}
#endif
V_66 = V_64 ;
if ( ! F_58 ( & V_66 -> V_32 , V_7 + V_47 -> V_68 ) )
F_56 ( & V_66 -> V_54 ) ;
F_56 ( & V_66 -> V_54 ) ;
F_11 ( & V_66 -> V_23 , & V_16 -> V_25 ) ;
F_12 ( & V_16 -> V_20 ) ;
return V_66 ;
}
static struct V_3 * F_59 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
void * V_65 )
{
struct V_3 * V_4 ;
if ( ! V_47 -> V_69 || F_15 ( V_47 ) > V_47 -> V_69 ) {
F_25 ( V_2 ) ;
return NULL ;
}
V_4 = F_60 ( V_2 -> V_42 , V_70 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_27 = V_47 ;
V_2 -> V_71 ( V_4 , V_65 ) ;
F_61 ( V_47 , V_2 -> V_44 ) ;
F_62 ( & V_4 -> V_32 , V_2 -> V_34 , ( unsigned long ) V_4 ) ;
F_31 ( & V_4 -> V_72 ) ;
F_63 ( & V_4 -> V_54 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_64 ( struct V_46 * V_47 ,
struct V_1 * V_2 ,
void * V_65 )
{
struct V_3 * V_4 ;
V_4 = F_59 ( V_47 , V_2 , V_65 ) ;
if ( ! V_4 )
return NULL ;
return F_53 ( V_47 , V_4 , V_2 , V_65 ) ;
}
struct V_3 * F_65 ( struct V_46 * V_47 ,
struct V_1 * V_2 , void * V_73 ,
unsigned int V_19 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_74 = 0 ;
if ( F_15 ( V_47 ) > V_47 -> V_28 )
F_25 ( V_2 ) ;
V_19 &= ( V_6 - 1 ) ;
V_16 = & V_2 -> V_19 [ V_19 ] ;
F_7 ( & V_16 -> V_20 ) ;
F_55 (q, &hb->chain, list) {
if ( V_4 -> V_27 == V_47 && V_2 -> V_67 ( V_4 , V_73 ) ) {
F_56 ( & V_4 -> V_54 ) ;
F_12 ( & V_16 -> V_20 ) ;
return V_4 ;
}
V_74 ++ ;
}
F_12 ( & V_16 -> V_20 ) ;
if ( V_74 <= V_75 )
return F_64 ( V_47 , V_2 , V_73 ) ;
if ( F_2 ( V_2 ) ) {
if ( ! V_2 -> V_26 )
V_2 -> V_26 = true ;
F_25 ( V_2 ) ;
}
return F_66 ( - V_76 ) ;
}
void F_67 ( struct V_3 * V_4 ,
const char * V_77 )
{
static const char V_78 [] = L_1
L_2 F_68 ( V_75 )
L_3 ;
if ( F_69 ( V_4 ) == - V_76 )
F_70 ( L_4 , V_77 , V_78 ) ;
}
