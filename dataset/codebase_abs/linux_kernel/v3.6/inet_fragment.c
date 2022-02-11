static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
unsigned long V_4 = V_5 ;
int V_6 ;
F_2 ( & V_3 -> V_7 ) ;
F_3 ( & V_3 -> V_8 , sizeof( V_9 ) ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
struct V_11 * V_12 ;
struct V_13 * V_14 , * V_15 ;
F_4 (q, p, n, &f->hash[i], list) {
unsigned int V_16 = V_3 -> V_17 ( V_12 ) ;
if ( V_16 != V_6 ) {
F_5 ( & V_12 -> V_18 ) ;
F_6 ( & V_12 -> V_18 , & V_3 -> V_19 [ V_16 ] ) ;
}
}
}
F_7 ( & V_3 -> V_7 ) ;
F_8 ( & V_3 -> V_20 , V_4 + V_3 -> V_21 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
F_10 ( & V_3 -> V_19 [ V_6 ] ) ;
F_11 ( & V_3 -> V_7 ) ;
V_3 -> V_8 = ( V_9 ) ( ( V_22 ^ ( V_22 >> 7 ) ) ^
( V_5 ^ ( V_5 >> 6 ) ) ) ;
F_12 ( & V_3 -> V_20 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_20 . V_23 = V_5 + V_3 -> V_21 ;
F_13 ( & V_3 -> V_20 ) ;
}
void F_14 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
F_15 ( & V_25 -> V_27 , 0 ) ;
F_16 ( & V_25 -> V_28 ) ;
}
void F_17 ( struct V_2 * V_3 )
{
F_18 ( & V_3 -> V_20 ) ;
}
void F_19 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
V_25 -> V_29 = 0 ;
F_20 () ;
F_21 ( V_25 , V_3 ) ;
F_22 () ;
}
static inline void F_23 ( struct V_11 * V_30 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_7 ) ;
F_5 ( & V_30 -> V_18 ) ;
F_24 ( & V_30 -> V_28 ) ;
V_30 -> V_31 -> V_26 -- ;
F_7 ( & V_3 -> V_7 ) ;
}
void F_25 ( struct V_11 * V_30 , struct V_2 * V_3 )
{
if ( F_18 ( & V_30 -> V_32 ) )
F_26 ( & V_30 -> V_33 ) ;
if ( ! ( V_30 -> V_34 & V_35 ) ) {
F_23 ( V_30 , V_3 ) ;
F_26 ( & V_30 -> V_33 ) ;
V_30 -> V_34 |= V_35 ;
}
}
static inline void F_27 ( struct V_24 * V_25 , struct V_2 * V_3 ,
struct V_36 * V_37 , int * V_38 )
{
if ( V_38 )
* V_38 -= V_37 -> V_39 ;
F_28 ( V_37 -> V_39 , & V_25 -> V_27 ) ;
if ( V_3 -> V_40 )
V_3 -> V_40 ( V_37 ) ;
F_29 ( V_37 ) ;
}
void F_30 ( struct V_11 * V_12 , struct V_2 * V_3 ,
int * V_38 )
{
struct V_36 * V_41 ;
struct V_24 * V_25 ;
F_31 ( ! ( V_12 -> V_34 & V_35 ) ) ;
F_31 ( F_18 ( & V_12 -> V_32 ) != 0 ) ;
V_41 = V_12 -> V_42 ;
V_25 = V_12 -> V_31 ;
while ( V_41 ) {
struct V_36 * V_43 = V_41 -> V_44 ;
F_27 ( V_25 , V_3 , V_41 , V_38 ) ;
V_41 = V_43 ;
}
if ( V_38 )
* V_38 -= V_3 -> V_45 ;
F_28 ( V_3 -> V_45 , & V_25 -> V_27 ) ;
if ( V_3 -> V_46 )
V_3 -> V_46 ( V_12 ) ;
F_32 ( V_12 ) ;
}
int F_21 ( struct V_24 * V_25 , struct V_2 * V_3 )
{
struct V_11 * V_12 ;
int V_38 , V_47 = 0 ;
V_38 = F_33 ( & V_25 -> V_27 ) - V_25 -> V_29 ;
while ( V_38 > 0 ) {
F_34 ( & V_3 -> V_7 ) ;
if ( F_35 ( & V_25 -> V_28 ) ) {
F_36 ( & V_3 -> V_7 ) ;
break;
}
V_12 = F_37 ( & V_25 -> V_28 ,
struct V_11 , V_28 ) ;
F_38 ( & V_12 -> V_33 ) ;
F_36 ( & V_3 -> V_7 ) ;
F_39 ( & V_12 -> V_7 ) ;
if ( ! ( V_12 -> V_34 & V_35 ) )
F_25 ( V_12 , V_3 ) ;
F_40 ( & V_12 -> V_7 ) ;
if ( F_41 ( & V_12 -> V_33 ) )
F_30 ( V_12 , V_3 , & V_38 ) ;
V_47 ++ ;
}
return V_47 ;
}
static struct V_11 * F_42 ( struct V_24 * V_25 ,
struct V_11 * V_48 , struct V_2 * V_3 ,
void * V_49 )
{
struct V_11 * V_50 ;
#ifdef F_43
struct V_13 * V_15 ;
#endif
unsigned int V_19 ;
F_2 ( & V_3 -> V_7 ) ;
V_19 = V_3 -> V_17 ( V_48 ) ;
#ifdef F_43
F_44 (qp, n, &f->hash[hash], list) {
if ( V_50 -> V_31 == V_25 && V_3 -> V_51 ( V_50 , V_49 ) ) {
F_38 ( & V_50 -> V_33 ) ;
F_7 ( & V_3 -> V_7 ) ;
V_48 -> V_34 |= V_35 ;
F_45 ( V_48 , V_3 ) ;
return V_50 ;
}
}
#endif
V_50 = V_48 ;
if ( ! F_8 ( & V_50 -> V_32 , V_5 + V_25 -> V_52 ) )
F_38 ( & V_50 -> V_33 ) ;
F_38 ( & V_50 -> V_33 ) ;
F_6 ( & V_50 -> V_18 , & V_3 -> V_19 [ V_19 ] ) ;
F_46 ( & V_50 -> V_28 , & V_25 -> V_28 ) ;
V_25 -> V_26 ++ ;
F_7 ( & V_3 -> V_7 ) ;
return V_50 ;
}
static struct V_11 * F_47 ( struct V_24 * V_25 ,
struct V_2 * V_3 , void * V_49 )
{
struct V_11 * V_12 ;
V_12 = F_48 ( V_3 -> V_45 , V_53 ) ;
if ( V_12 == NULL )
return NULL ;
V_12 -> V_31 = V_25 ;
V_3 -> V_54 ( V_12 , V_49 ) ;
F_49 ( V_3 -> V_45 , & V_25 -> V_27 ) ;
F_12 ( & V_12 -> V_32 , V_3 -> V_55 , ( unsigned long ) V_12 ) ;
F_50 ( & V_12 -> V_7 ) ;
F_15 ( & V_12 -> V_33 , 1 ) ;
return V_12 ;
}
static struct V_11 * F_51 ( struct V_24 * V_25 ,
struct V_2 * V_3 , void * V_49 )
{
struct V_11 * V_12 ;
V_12 = F_47 ( V_25 , V_3 , V_49 ) ;
if ( V_12 == NULL )
return NULL ;
return F_42 ( V_25 , V_12 , V_3 , V_49 ) ;
}
struct V_11 * F_52 ( struct V_24 * V_25 ,
struct V_2 * V_3 , void * V_56 , unsigned int V_19 )
__releases( &f->lock
