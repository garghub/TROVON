void F_1 ( char * V_1 )
{
#ifdef F_2
if ( V_2 ) {
F_3 ( V_2 ) ;
}
#endif
F_4 ( V_3 ) ;
F_5 () ;
F_6 ( V_4 , V_5 ) ;
while ( 1 ) ;
}
void F_7 ( void )
{
}
void F_8 ( void )
{
if ( V_6 )
V_6 () ;
F_9 ( 0 ) ;
F_4 ( V_3 ) ;
F_10 ( V_7 L_1
L_2 ) ;
}
void F_11 ( void )
{
}
void F_12 ( struct V_8 * V_9 )
{
}
int F_13 ( struct V_10 * V_11 , T_1 * V_12 )
{
if ( V_11 == NULL )
return 0 ;
memcpy ( V_12 , V_11 -> V_13 , sizeof *V_12 ) ;
return 1 ;
}
int F_14 ( struct V_8 * V_14 , T_1 * V_12 )
{
memcpy ( V_12 , V_14 -> V_15 . V_11 . V_13 , sizeof( * V_12 ) ) ;
return 1 ;
}
int
F_15 ( unsigned long V_16 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * V_19 )
{
struct V_10 * V_20 = & ( V_19 -> V_15 . V_11 ) ;
void * V_21 = F_16 ( V_19 ) ;
extern void * const V_22 ;
extern void * const V_23 ;
if ( F_17 ( V_19 -> V_24 & V_25 ) ) {
memset ( V_20 , 0 , sizeof( struct V_10 ) ) ;
if ( ! V_17 )
return 0 ;
V_20 -> V_26 = ( unsigned long ) V_21 + V_27 + V_28 ;
V_20 -> V_29 = ( unsigned long ) & V_22 ;
#ifdef F_18
V_20 -> V_30 [ 27 ] = ( ( unsigned long * ) V_17 ) [ 3 ] ;
V_20 -> V_30 [ 26 ] = ( ( unsigned long * ) V_17 ) [ 2 ] ;
#else
V_20 -> V_30 [ 26 ] = V_17 ;
#endif
V_20 -> V_30 [ 25 ] = V_18 ;
} else {
if ( V_17 ) {
V_17 = F_19 ( V_17 , 4 ) ;
if ( F_20 ( V_17 ) )
V_20 -> V_30 [ 30 ] = V_17 ;
}
V_20 -> V_26 = ( unsigned long ) V_21 + V_27 + V_28 ;
V_20 -> V_29 = ( unsigned long ) & V_23 ;
if ( V_16 & V_31 )
V_20 -> V_32 = V_20 -> V_30 [ 23 ] ;
}
return 0 ;
}
unsigned long F_21 ( struct V_8 * V_33 )
{
return V_33 -> V_15 . V_11 . V_29 ;
}
unsigned long
F_22 ( struct V_8 * V_19 )
{
struct V_34 V_35 ;
unsigned long V_36 ;
int V_37 = 0 ;
if ( ! V_19 || V_19 == V_38 || V_19 -> V_39 == V_40 )
return 0 ;
F_23 ( & V_35 , V_19 ) ;
do {
if ( F_24 ( & V_35 ) < 0 )
return 0 ;
V_36 = V_35 . V_36 ;
if ( ! F_25 ( V_36 ) )
return V_36 ;
} while ( V_37 ++ < 16 );
return 0 ;
}
void * F_26 ( void * V_41 )
{
T_2 * V_42 = V_41 ;
void * V_19 ;
if ( ! F_27 ( & V_42 -> V_43 , V_19 ) )
V_41 = V_19 ;
return V_41 ;
}
static inline unsigned long F_28 ( void )
{
if ( F_29 () )
return ( F_30 () & 0x7ffUL ) << V_44 ;
else
return ( F_30 () & 0x3ffffUL ) << V_44 ;
}
unsigned long F_31 ( struct V_45 * V_46 )
{
unsigned long V_47 = F_32 ( V_46 -> V_48 + F_28 () ) ;
if ( V_47 < V_46 -> V_48 )
return V_46 -> V_48 ;
return V_47 ;
}
