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
V_3 -> V_8 = ( V_9 ) ( ( V_26 ^ ( V_26 >> 7 ) ) ^
( V_5 ^ ( V_5 >> 6 ) ) ) ;
F_13 ( & V_3 -> V_23 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_23 . V_27 = V_5 + V_3 -> V_24 ;
F_14 ( & V_3 -> V_23 ) ;
}
void F_15 ( struct V_28 * V_29 )
{
V_29 -> V_30 = 0 ;
F_16 ( V_29 ) ;
F_17 ( & V_29 -> V_31 ) ;
F_10 ( & V_29 -> V_32 ) ;
}
void F_18 ( struct V_2 * V_3 )
{
F_19 ( & V_3 -> V_23 ) ;
}
void F_20 ( struct V_28 * V_29 , struct V_2 * V_3 )
{
V_29 -> V_33 = 0 ;
F_21 () ;
F_22 ( V_29 , V_3 , true ) ;
F_23 () ;
F_24 ( & V_29 -> V_34 ) ;
}
static inline void F_25 ( struct V_13 * V_35 , struct V_2 * V_3 )
{
struct V_11 * V_12 ;
unsigned int V_17 ;
F_26 ( & V_3 -> V_7 ) ;
V_17 = V_3 -> V_19 ( V_35 ) ;
V_12 = & V_3 -> V_17 [ V_17 ] ;
F_27 ( & V_12 -> V_25 ) ;
F_5 ( & V_35 -> V_21 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
F_30 ( V_35 ) ;
}
void F_31 ( struct V_13 * V_35 , struct V_2 * V_3 )
{
if ( F_19 ( & V_35 -> V_36 ) )
F_32 ( & V_35 -> V_37 ) ;
if ( ! ( V_35 -> V_38 & V_39 ) ) {
F_25 ( V_35 , V_3 ) ;
F_32 ( & V_35 -> V_37 ) ;
V_35 -> V_38 |= V_39 ;
}
}
static inline void F_33 ( struct V_28 * V_29 , struct V_2 * V_3 ,
struct V_40 * V_41 )
{
if ( V_3 -> V_42 )
V_3 -> V_42 ( V_41 ) ;
F_34 ( V_41 ) ;
}
void F_35 ( struct V_13 * V_14 , struct V_2 * V_3 ,
int * V_43 )
{
struct V_40 * V_44 ;
struct V_28 * V_29 ;
unsigned int V_45 , V_46 = 0 ;
F_36 ( ! ( V_14 -> V_38 & V_39 ) ) ;
F_36 ( F_19 ( & V_14 -> V_36 ) != 0 ) ;
V_44 = V_14 -> V_47 ;
V_29 = V_14 -> V_48 ;
while ( V_44 ) {
struct V_40 * V_49 = V_44 -> V_50 ;
V_46 += V_44 -> V_51 ;
F_33 ( V_29 , V_3 , V_44 ) ;
V_44 = V_49 ;
}
V_45 = V_46 + V_3 -> V_52 ;
if ( V_43 )
* V_43 -= V_45 ;
F_37 ( V_14 , V_45 ) ;
if ( V_3 -> V_53 )
V_3 -> V_53 ( V_14 ) ;
F_38 ( V_14 ) ;
}
int F_22 ( struct V_28 * V_29 , struct V_2 * V_3 , bool V_54 )
{
struct V_13 * V_14 ;
int V_43 , V_55 = 0 ;
if ( ! V_54 ) {
if ( F_39 ( V_29 ) <= V_29 -> V_56 )
return 0 ;
}
V_43 = F_39 ( V_29 ) - V_29 -> V_33 ;
while ( V_43 > 0 ) {
F_27 ( & V_29 -> V_32 ) ;
if ( F_40 ( & V_29 -> V_31 ) ) {
F_28 ( & V_29 -> V_32 ) ;
break;
}
V_14 = F_41 ( & V_29 -> V_31 ,
struct V_13 , V_31 ) ;
F_42 ( & V_14 -> V_37 ) ;
F_43 ( & V_14 -> V_31 ) ;
F_28 ( & V_29 -> V_32 ) ;
F_27 ( & V_14 -> V_7 ) ;
if ( ! ( V_14 -> V_38 & V_39 ) )
F_31 ( V_14 , V_3 ) ;
F_28 ( & V_14 -> V_7 ) ;
if ( F_44 ( & V_14 -> V_37 ) )
F_35 ( V_14 , V_3 , & V_43 ) ;
V_55 ++ ;
}
return V_55 ;
}
static struct V_13 * F_45 ( struct V_28 * V_29 ,
struct V_13 * V_57 , struct V_2 * V_3 ,
void * V_58 )
{
struct V_11 * V_12 ;
struct V_13 * V_59 ;
#ifdef F_46
#endif
unsigned int V_17 ;
F_26 ( & V_3 -> V_7 ) ;
V_17 = V_3 -> V_19 ( V_57 ) ;
V_12 = & V_3 -> V_17 [ V_17 ] ;
F_27 ( & V_12 -> V_25 ) ;
#ifdef F_46
F_47 (qp, &hb->chain, list) {
if ( V_59 -> V_48 == V_29 && V_3 -> V_60 ( V_59 , V_58 ) ) {
F_42 ( & V_59 -> V_37 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
V_57 -> V_38 |= V_39 ;
F_48 ( V_57 , V_3 ) ;
return V_59 ;
}
}
#endif
V_59 = V_57 ;
if ( ! F_8 ( & V_59 -> V_36 , V_5 + V_29 -> V_61 ) )
F_42 ( & V_59 -> V_37 ) ;
F_42 ( & V_59 -> V_37 ) ;
F_6 ( & V_59 -> V_21 , & V_12 -> V_22 ) ;
F_28 ( & V_12 -> V_25 ) ;
F_29 ( & V_3 -> V_7 ) ;
F_49 ( V_29 , V_59 ) ;
return V_59 ;
}
static struct V_13 * F_50 ( struct V_28 * V_29 ,
struct V_2 * V_3 , void * V_58 )
{
struct V_13 * V_14 ;
V_14 = F_51 ( V_3 -> V_52 , V_62 ) ;
if ( V_14 == NULL )
return NULL ;
V_14 -> V_48 = V_29 ;
V_3 -> V_63 ( V_14 , V_58 ) ;
F_52 ( V_14 , V_3 -> V_52 ) ;
F_13 ( & V_14 -> V_36 , V_3 -> V_64 , ( unsigned long ) V_14 ) ;
F_10 ( & V_14 -> V_7 ) ;
F_53 ( & V_14 -> V_37 , 1 ) ;
F_17 ( & V_14 -> V_31 ) ;
return V_14 ;
}
static struct V_13 * F_54 ( struct V_28 * V_29 ,
struct V_2 * V_3 , void * V_58 )
{
struct V_13 * V_14 ;
V_14 = F_50 ( V_29 , V_3 , V_58 ) ;
if ( V_14 == NULL )
return NULL ;
return F_45 ( V_29 , V_14 , V_3 , V_58 ) ;
}
struct V_13 * F_55 ( struct V_28 * V_29 ,
struct V_2 * V_3 , void * V_65 , unsigned int V_17 )
__releases( &f->lock
void F_56 ( struct V_13 * V_14 ,
const char * V_66 )
{
static const char V_67 [] = L_1
L_2 F_57 ( V_68 )
L_3 ;
if ( F_58 ( V_14 ) == - V_69 )
F_59 ( V_70 L_4 , V_66 , V_67 ) ;
}
