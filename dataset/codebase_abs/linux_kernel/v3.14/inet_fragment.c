static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
unsigned long V_4 = V_5 ;
int V_6 ;
F_2 ( & V_3 -> V_7 ) ;
F_3 ( & V_3 -> V_8 , sizeof( V_9 ) ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_12 = & V_3 -> V_17 [ V_6 ] ;
F_4 (q, n, &hb->chain, list) {
unsigned int V_18 = V_3 -> V_19 ( V_14 ) ;
if ( V_18 != V_6 ) {
struct V_11 * V_20 ;
F_5 ( & V_14 -> V_21 ) ;
V_20 = & V_3 -> V_17 [ V_18 ] ;
F_6 ( & V_14 -> V_21 , & V_20 -> V_22 ) ;
}
}
}
F_7 ( & V_3 -> V_7 ) ;
F_8 ( & V_3 -> V_23 , V_4 + V_3 -> V_24 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
struct V_11 * V_12 = & V_3 -> V_17 [ V_6 ] ;
F_10 ( & V_12 -> V_25 ) ;
F_11 ( & V_12 -> V_22 ) ;
}
F_12 ( & V_3 -> V_7 ) ;
F_13 ( & V_3 -> V_23 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_23 . V_26 = V_5 + V_3 -> V_24 ;
F_14 ( & V_3 -> V_23 ) ;
}
void F_15 ( struct V_27 * V_28 )
{
V_28 -> V_29 = 0 ;
F_16 ( V_28 ) ;
F_17 ( & V_28 -> V_30 ) ;
F_10 ( & V_28 -> V_31 ) ;
}
void F_18 ( struct V_2 * V_3 )
{
F_19 ( & V_3 -> V_23 ) ;
}
void F_20 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
V_28 -> V_32 = 0 ;
F_21 () ;
F_22 ( V_28 , V_3 , true ) ;
F_23 () ;
F_24 ( & V_28 -> V_33 ) ;
}
static inline void F_25 ( struct V_13 * V_34 , struct V_2 * V_3 )
{
struct V_11 * V_12 ;
unsigned int V_17 ;
F_26 ( & V_3 -> V_7 ) ;
V_17 = V_3 -> V_19 ( V_34 ) ;
V_12 = & V_3 -> V_17 [ V_17 ] ;
F_27 ( & V_12 -> V_25 ) ;
F_5 ( & V_34 -> V_21 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
F_30 ( V_34 ) ;
}
void F_31 ( struct V_13 * V_34 , struct V_2 * V_3 )
{
if ( F_19 ( & V_34 -> V_35 ) )
F_32 ( & V_34 -> V_36 ) ;
if ( ! ( V_34 -> V_37 & V_38 ) ) {
F_25 ( V_34 , V_3 ) ;
F_32 ( & V_34 -> V_36 ) ;
V_34 -> V_37 |= V_38 ;
}
}
static inline void F_33 ( struct V_27 * V_28 , struct V_2 * V_3 ,
struct V_39 * V_40 )
{
if ( V_3 -> V_41 )
V_3 -> V_41 ( V_40 ) ;
F_34 ( V_40 ) ;
}
void F_35 ( struct V_13 * V_14 , struct V_2 * V_3 ,
int * V_42 )
{
struct V_39 * V_43 ;
struct V_27 * V_28 ;
unsigned int V_44 , V_45 = 0 ;
F_36 ( ! ( V_14 -> V_37 & V_38 ) ) ;
F_36 ( F_19 ( & V_14 -> V_35 ) != 0 ) ;
V_43 = V_14 -> V_46 ;
V_28 = V_14 -> V_47 ;
while ( V_43 ) {
struct V_39 * V_48 = V_43 -> V_49 ;
V_45 += V_43 -> V_50 ;
F_33 ( V_28 , V_3 , V_43 ) ;
V_43 = V_48 ;
}
V_44 = V_45 + V_3 -> V_51 ;
if ( V_42 )
* V_42 -= V_44 ;
F_37 ( V_14 , V_44 ) ;
if ( V_3 -> V_52 )
V_3 -> V_52 ( V_14 ) ;
F_38 ( V_14 ) ;
}
int F_22 ( struct V_27 * V_28 , struct V_2 * V_3 , bool V_53 )
{
struct V_13 * V_14 ;
int V_42 , V_54 = 0 ;
if ( ! V_53 ) {
if ( F_39 ( V_28 ) <= V_28 -> V_55 )
return 0 ;
}
V_42 = F_39 ( V_28 ) - V_28 -> V_32 ;
while ( V_42 > 0 || V_53 ) {
F_27 ( & V_28 -> V_31 ) ;
if ( F_40 ( & V_28 -> V_30 ) ) {
F_28 ( & V_28 -> V_31 ) ;
break;
}
V_14 = F_41 ( & V_28 -> V_30 ,
struct V_13 , V_30 ) ;
F_42 ( & V_14 -> V_36 ) ;
F_43 ( & V_14 -> V_30 ) ;
F_28 ( & V_28 -> V_31 ) ;
F_27 ( & V_14 -> V_7 ) ;
if ( ! ( V_14 -> V_37 & V_38 ) )
F_31 ( V_14 , V_3 ) ;
F_28 ( & V_14 -> V_7 ) ;
if ( F_44 ( & V_14 -> V_36 ) )
F_35 ( V_14 , V_3 , & V_42 ) ;
V_54 ++ ;
}
return V_54 ;
}
static struct V_13 * F_45 ( struct V_27 * V_28 ,
struct V_13 * V_56 , struct V_2 * V_3 ,
void * V_57 )
{
struct V_11 * V_12 ;
struct V_13 * V_58 ;
unsigned int V_17 ;
F_26 ( & V_3 -> V_7 ) ;
V_17 = V_3 -> V_19 ( V_56 ) ;
V_12 = & V_3 -> V_17 [ V_17 ] ;
F_27 ( & V_12 -> V_25 ) ;
#ifdef F_46
F_47 (qp, &hb->chain, list) {
if ( V_58 -> V_47 == V_28 && V_3 -> V_59 ( V_58 , V_57 ) ) {
F_42 ( & V_58 -> V_36 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
V_56 -> V_37 |= V_38 ;
F_48 ( V_56 , V_3 ) ;
return V_58 ;
}
}
#endif
V_58 = V_56 ;
if ( ! F_8 ( & V_58 -> V_35 , V_5 + V_28 -> V_60 ) )
F_42 ( & V_58 -> V_36 ) ;
F_42 ( & V_58 -> V_36 ) ;
F_6 ( & V_58 -> V_21 , & V_12 -> V_22 ) ;
F_49 ( V_28 , V_58 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
return V_58 ;
}
static struct V_13 * F_50 ( struct V_27 * V_28 ,
struct V_2 * V_3 , void * V_57 )
{
struct V_13 * V_14 ;
V_14 = F_51 ( V_3 -> V_51 , V_61 ) ;
if ( V_14 == NULL )
return NULL ;
V_14 -> V_47 = V_28 ;
V_3 -> V_62 ( V_14 , V_57 ) ;
F_52 ( V_14 , V_3 -> V_51 ) ;
F_13 ( & V_14 -> V_35 , V_3 -> V_63 , ( unsigned long ) V_14 ) ;
F_10 ( & V_14 -> V_7 ) ;
F_53 ( & V_14 -> V_36 , 1 ) ;
F_17 ( & V_14 -> V_30 ) ;
return V_14 ;
}
static struct V_13 * F_54 ( struct V_27 * V_28 ,
struct V_2 * V_3 , void * V_57 )
{
struct V_13 * V_14 ;
V_14 = F_50 ( V_28 , V_3 , V_57 ) ;
if ( V_14 == NULL )
return NULL ;
return F_45 ( V_28 , V_14 , V_3 , V_57 ) ;
}
struct V_13 * F_55 ( struct V_27 * V_28 ,
struct V_2 * V_3 , void * V_64 , unsigned int V_17 )
__releases( &f->lock
void F_56 ( struct V_13 * V_14 ,
const char * V_65 )
{
static const char V_66 [] = L_1
L_2 F_57 ( V_67 )
L_3 ;
if ( F_58 ( V_14 ) == - V_68 )
F_59 ( V_69 L_4 , V_65 , V_66 ) ;
}
