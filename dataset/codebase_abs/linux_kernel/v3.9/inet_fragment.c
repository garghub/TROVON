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
F_4 (q, n, &f->hash[i], list) {
unsigned int V_15 = V_3 -> V_16 ( V_12 ) ;
if ( V_15 != V_6 ) {
F_5 ( & V_12 -> V_17 ) ;
F_6 ( & V_12 -> V_17 , & V_3 -> V_18 [ V_15 ] ) ;
}
}
}
F_7 ( & V_3 -> V_7 ) ;
F_8 ( & V_3 -> V_19 , V_4 + V_3 -> V_20 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
F_10 ( & V_3 -> V_18 [ V_6 ] ) ;
F_11 ( & V_3 -> V_7 ) ;
V_3 -> V_8 = ( V_9 ) ( ( V_21 ^ ( V_21 >> 7 ) ) ^
( V_5 ^ ( V_5 >> 6 ) ) ) ;
F_12 ( & V_3 -> V_19 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_19 . V_22 = V_5 + V_3 -> V_20 ;
F_13 ( & V_3 -> V_19 ) ;
}
void F_14 ( struct V_23 * V_24 )
{
V_24 -> V_25 = 0 ;
F_15 ( V_24 ) ;
F_16 ( & V_24 -> V_26 ) ;
F_17 ( & V_24 -> V_27 ) ;
}
void F_18 ( struct V_2 * V_3 )
{
F_19 ( & V_3 -> V_19 ) ;
}
void F_20 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
V_24 -> V_28 = 0 ;
F_21 () ;
F_22 ( V_24 , V_3 , true ) ;
F_23 () ;
F_24 ( & V_24 -> V_29 ) ;
}
static inline void F_25 ( struct V_11 * V_30 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_7 ) ;
F_5 ( & V_30 -> V_17 ) ;
V_30 -> V_31 -> V_25 -- ;
F_7 ( & V_3 -> V_7 ) ;
F_26 ( V_30 ) ;
}
void F_27 ( struct V_11 * V_30 , struct V_2 * V_3 )
{
if ( F_19 ( & V_30 -> V_32 ) )
F_28 ( & V_30 -> V_33 ) ;
if ( ! ( V_30 -> V_34 & V_35 ) ) {
F_25 ( V_30 , V_3 ) ;
F_28 ( & V_30 -> V_33 ) ;
V_30 -> V_34 |= V_35 ;
}
}
static inline void F_29 ( struct V_23 * V_24 , struct V_2 * V_3 ,
struct V_36 * V_37 )
{
if ( V_3 -> V_38 )
V_3 -> V_38 ( V_37 ) ;
F_30 ( V_37 ) ;
}
void F_31 ( struct V_11 * V_12 , struct V_2 * V_3 ,
int * V_39 )
{
struct V_36 * V_40 ;
struct V_23 * V_24 ;
unsigned int V_41 , V_42 = 0 ;
F_32 ( ! ( V_12 -> V_34 & V_35 ) ) ;
F_32 ( F_19 ( & V_12 -> V_32 ) != 0 ) ;
V_40 = V_12 -> V_43 ;
V_24 = V_12 -> V_31 ;
while ( V_40 ) {
struct V_36 * V_44 = V_40 -> V_45 ;
V_42 += V_40 -> V_46 ;
F_29 ( V_24 , V_3 , V_40 ) ;
V_40 = V_44 ;
}
V_41 = V_42 + V_3 -> V_47 ;
if ( V_39 )
* V_39 -= V_41 ;
F_33 ( V_12 , V_41 ) ;
if ( V_3 -> V_48 )
V_3 -> V_48 ( V_12 ) ;
F_34 ( V_12 ) ;
}
int F_22 ( struct V_23 * V_24 , struct V_2 * V_3 , bool V_49 )
{
struct V_11 * V_12 ;
int V_39 , V_50 = 0 ;
if ( ! V_49 ) {
if ( F_35 ( V_24 ) <= V_24 -> V_51 )
return 0 ;
}
V_39 = F_35 ( V_24 ) - V_24 -> V_28 ;
while ( V_39 > 0 ) {
F_36 ( & V_24 -> V_27 ) ;
if ( F_37 ( & V_24 -> V_26 ) ) {
F_38 ( & V_24 -> V_27 ) ;
break;
}
V_12 = F_39 ( & V_24 -> V_26 ,
struct V_11 , V_26 ) ;
F_40 ( & V_12 -> V_33 ) ;
F_38 ( & V_24 -> V_27 ) ;
F_36 ( & V_12 -> V_7 ) ;
if ( ! ( V_12 -> V_34 & V_35 ) )
F_27 ( V_12 , V_3 ) ;
F_38 ( & V_12 -> V_7 ) ;
if ( F_41 ( & V_12 -> V_33 ) )
F_31 ( V_12 , V_3 , & V_39 ) ;
V_50 ++ ;
}
return V_50 ;
}
static struct V_11 * F_42 ( struct V_23 * V_24 ,
struct V_11 * V_52 , struct V_2 * V_3 ,
void * V_53 )
{
struct V_11 * V_54 ;
#ifdef F_43
#endif
unsigned int V_18 ;
F_2 ( & V_3 -> V_7 ) ;
V_18 = V_3 -> V_16 ( V_52 ) ;
#ifdef F_43
F_44 (qp, &f->hash[hash], list) {
if ( V_54 -> V_31 == V_24 && V_3 -> V_55 ( V_54 , V_53 ) ) {
F_40 ( & V_54 -> V_33 ) ;
F_7 ( & V_3 -> V_7 ) ;
V_52 -> V_34 |= V_35 ;
F_45 ( V_52 , V_3 ) ;
return V_54 ;
}
}
#endif
V_54 = V_52 ;
if ( ! F_8 ( & V_54 -> V_32 , V_5 + V_24 -> V_56 ) )
F_40 ( & V_54 -> V_33 ) ;
F_40 ( & V_54 -> V_33 ) ;
F_6 ( & V_54 -> V_17 , & V_3 -> V_18 [ V_18 ] ) ;
V_24 -> V_25 ++ ;
F_7 ( & V_3 -> V_7 ) ;
F_46 ( V_24 , V_54 ) ;
return V_54 ;
}
static struct V_11 * F_47 ( struct V_23 * V_24 ,
struct V_2 * V_3 , void * V_53 )
{
struct V_11 * V_12 ;
V_12 = F_48 ( V_3 -> V_47 , V_57 ) ;
if ( V_12 == NULL )
return NULL ;
V_12 -> V_31 = V_24 ;
V_3 -> V_58 ( V_12 , V_53 ) ;
F_49 ( V_12 , V_3 -> V_47 ) ;
F_12 ( & V_12 -> V_32 , V_3 -> V_59 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_7 ) ;
F_50 ( & V_12 -> V_33 , 1 ) ;
return V_12 ;
}
static struct V_11 * F_51 ( struct V_23 * V_24 ,
struct V_2 * V_3 , void * V_53 )
{
struct V_11 * V_12 ;
V_12 = F_47 ( V_24 , V_3 , V_53 ) ;
if ( V_12 == NULL )
return NULL ;
return F_42 ( V_24 , V_12 , V_3 , V_53 ) ;
}
struct V_11 * F_52 ( struct V_23 * V_24 ,
struct V_2 * V_3 , void * V_60 , unsigned int V_18 )
__releases( &f->lock
void F_53 ( struct V_11 * V_12 ,
const char * V_61 )
{
static const char V_62 [] = L_1
L_2 F_54 ( V_63 )
L_3 ;
if ( F_55 ( V_12 ) == - V_64 )
F_56 ( V_65 L_4 , V_61 , V_62 ) ;
}
