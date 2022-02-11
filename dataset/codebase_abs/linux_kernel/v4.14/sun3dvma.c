static inline void F_1 ( unsigned long V_1 , int V_2 )
{
}
static void F_2 ( void )
{
int V_3 ;
int V_4 = 0 ;
F_3 ( L_1 ) ;
for( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
if( ! V_6 [ V_3 ] )
continue;
V_4 ++ ;
F_3 ( L_2 ,
( V_3 << V_7 ) + V_8 , V_6 [ V_3 ] ) ;
}
F_3 ( L_3 , V_4 ) ;
F_3 ( L_4 , V_9 , V_10 ) ;
F_3 ( L_5 , V_11 ,
V_12 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_13 * V_15 ;
struct V_16 * V_16 ;
F_3 ( L_6 ) ;
F_5 (cur, holes) {
V_16 = F_6 ( V_15 , struct V_16 , V_17 ) ;
if( ( V_16 -> V_18 == 0 ) && ( V_16 -> V_19 == 0 ) && ( V_16 -> V_20 == 0 ) )
continue;
F_3 ( L_7 ,
V_16 -> V_18 , V_16 -> V_19 , V_16 -> V_20 ) ;
}
F_3 ( L_8 ) ;
}
static inline int F_7 ( void )
{
struct V_16 * V_16 ;
struct V_16 * V_21 = NULL ;
struct V_13 * V_15 ;
int V_22 = 0 ;
F_5 (cur, &hole_list) {
V_16 = F_6 ( V_15 , struct V_16 , V_17 ) ;
if( ! V_21 ) {
V_21 = V_16 ;
continue;
}
if( V_16 -> V_19 == V_21 -> V_18 ) {
V_16 -> V_20 += V_21 -> V_20 ;
V_16 -> V_19 = V_21 -> V_19 ;
F_8 ( & ( V_21 -> V_17 ) , & V_23 ) ;
V_22 ++ ;
}
}
return V_22 ;
}
static inline struct V_16 * F_9 ( void )
{
struct V_16 * V_22 ;
if( F_10 ( & V_23 ) ) {
if( ! F_7 () ) {
F_11 ( L_9 ) ;
F_12 () ;
}
}
V_22 = F_6 ( V_23 . V_24 , struct V_16 , V_17 ) ;
F_13 ( & ( V_22 -> V_17 ) ) ;
return V_22 ;
}
static inline unsigned long F_14 ( int V_25 , unsigned long V_26 )
{
struct V_13 * V_15 ;
struct V_16 * V_16 ;
if( F_10 ( & V_27 ) ) {
#ifdef F_15
F_11 ( L_10 ) ;
F_4 ( & V_23 ) ;
F_2 () ;
#endif
F_12 () ;
}
F_5 (cur, &hole_list) {
unsigned long V_28 ;
V_16 = F_6 ( V_15 , struct V_16 , V_17 ) ;
if( V_26 > V_29 )
V_28 = V_25 + ( ( V_16 -> V_19 - V_25 ) & ( V_26 - 1 ) ) ;
else
V_28 = V_25 ;
if( V_16 -> V_20 > V_28 ) {
V_16 -> V_19 -= V_28 ;
V_16 -> V_20 -= V_28 ;
F_16 ( V_16 -> V_19 ) = V_28 ;
#ifdef F_15
V_9 ++ ;
V_11 += V_28 ;
#endif
return V_16 -> V_19 ;
} else if( V_16 -> V_20 == V_28 ) {
F_8 ( & ( V_16 -> V_17 ) , & V_23 ) ;
F_16 ( V_16 -> V_18 ) = V_28 ;
#ifdef F_15
V_9 ++ ;
V_11 += V_28 ;
#endif
return V_16 -> V_18 ;
}
}
F_11 ( L_11 ) ;
F_12 () ;
return 0 ;
}
static inline int F_17 ( unsigned long V_30 )
{
unsigned long V_25 ;
struct V_16 * V_16 ;
struct V_13 * V_15 ;
unsigned long V_31 ;
V_31 = V_30 ;
V_25 = F_16 ( V_30 ) ;
F_16 ( V_30 ) = 0 ;
V_30 &= V_32 ;
F_1 ( V_30 , V_25 ) ;
#ifdef F_15
V_10 ++ ;
V_12 += V_25 ;
#endif
F_5 (cur, &hole_list) {
V_16 = F_6 ( V_15 , struct V_16 , V_17 ) ;
if( V_16 -> V_19 == V_30 ) {
V_16 -> V_19 += V_25 ;
V_16 -> V_20 += V_25 ;
return 0 ;
} else if( V_16 -> V_18 == ( V_30 + V_25 ) ) {
V_16 -> V_18 = V_30 ;
V_16 -> V_20 += V_25 ;
return 0 ;
}
}
V_16 = F_9 () ;
V_16 -> V_18 = V_30 ;
V_16 -> V_19 = V_30 + V_25 ;
V_16 -> V_20 = V_25 ;
F_18 ( & ( V_16 -> V_17 ) , V_15 ) ;
return 0 ;
}
void T_1 F_19 ( void )
{
struct V_16 * V_16 ;
int V_3 ;
F_20 ( & V_27 ) ;
F_20 ( & V_23 ) ;
for( V_3 = 0 ; V_3 < 64 ; V_3 ++ )
F_18 ( & ( V_33 [ V_3 ] . V_17 ) , & V_23 ) ;
V_16 = F_9 () ;
V_16 -> V_18 = V_8 ;
V_16 -> V_19 = V_34 ;
V_16 -> V_20 = V_35 ;
F_18 ( & ( V_16 -> V_17 ) , & V_27 ) ;
V_6 = F_21 ( V_5 * sizeof( unsigned long ) ) ;
F_1 ( V_8 , V_35 ) ;
#ifdef F_22
F_23 () ;
#endif
}
unsigned long F_24 ( unsigned long V_36 , int V_25 , int V_26 )
{
unsigned long V_30 ;
unsigned long V_37 ;
if( ! V_25 )
V_25 = 0x800 ;
if( ! V_36 || ! V_25 ) {
return 0 ;
}
F_25 ( L_12 , V_25 , V_36 ) ;
V_37 = V_36 & ~ V_32 ;
V_36 &= V_38 ;
V_25 += V_37 ;
V_25 = ( ( V_25 + ( V_29 - 1 ) ) & V_32 ) ;
if( V_26 == 0 )
V_26 = V_29 ;
else
V_26 = ( ( V_26 + ( V_29 - 1 ) ) & V_32 ) ;
V_30 = F_14 ( V_25 , V_26 ) ;
if( ! F_26 ( V_36 , V_30 , V_25 ) )
return ( V_30 + V_37 ) ;
F_11 ( L_13 , V_36 , V_30 ,
V_25 ) ;
F_12 () ;
return 0 ;
}
void F_27 ( void * V_30 )
{
unsigned long V_39 ;
V_39 = ( unsigned long ) V_30 ;
if( ! ( V_39 & 0x00f00000 ) )
V_39 |= 0xf00000 ;
F_17 ( V_39 ) ;
return;
}
void * F_28 ( unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_36 ;
unsigned long V_30 ;
unsigned long V_40 ;
if( ! V_25 )
return NULL ;
F_25 ( L_14 , V_25 ) ;
V_25 = ( ( V_25 + ( V_29 - 1 ) ) & V_32 ) ;
if( ( V_36 = F_29 ( V_41 , F_30 ( V_25 ) ) ) == 0 )
return NULL ;
if( ( V_30 = ( unsigned long ) F_24 ( V_36 , V_25 , V_26 ) ) == 0 ) {
F_31 ( V_36 , F_30 ( V_25 ) ) ;
return NULL ;
}
V_40 = F_32 ( V_30 ) ;
if( F_33 ( V_36 , V_40 , V_25 ) < 0 ) {
F_27 ( ( void * ) V_30 ) ;
F_31 ( V_36 , F_30 ( V_25 ) ) ;
return NULL ;
}
F_25 ( L_15 , V_25 , V_36 ,
V_30 ) ;
return ( void * ) V_40 ;
}
void F_34 ( void * V_40 )
{
return;
}
