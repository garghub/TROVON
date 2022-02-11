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
void F_12 ( void )
{
}
void F_13 ( struct V_8 * V_9 )
{
}
int F_14 ( struct V_10 * V_11 , T_1 * V_12 )
{
if ( V_11 == NULL )
return 0 ;
memcpy ( V_12 , V_11 -> V_13 , sizeof *V_12 ) ;
return 1 ;
}
int F_15 ( struct V_8 * V_14 , T_1 * V_12 )
{
memcpy ( V_12 , V_14 -> V_15 . V_11 . V_13 , sizeof( * V_12 ) ) ;
return 1 ;
}
int
F_16 ( unsigned long V_16 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * V_19 )
{
struct V_10 * V_20 = & ( V_19 -> V_15 . V_11 ) ;
void * V_21 = F_17 ( V_19 ) ;
extern void * const V_22 ;
extern void * const V_23 ;
#ifdef F_18
extern void * const V_24 ;
#endif
if ( F_19 ( V_19 -> V_25 & V_26 ) ) {
memset ( V_20 , 0 , sizeof( struct V_10 ) ) ;
if ( ! V_17 )
return 0 ;
V_20 -> V_27 = ( unsigned long ) V_21 + V_28 + V_29 ;
V_20 -> V_30 = ( unsigned long ) & V_22 ;
#ifdef F_20
V_20 -> V_31 [ 27 ] = ( ( unsigned long * ) V_17 ) [ 3 ] ;
V_20 -> V_31 [ 26 ] = ( ( unsigned long * ) V_17 ) [ 2 ] ;
#else
V_20 -> V_31 [ 26 ] = V_17 ;
#endif
V_20 -> V_31 [ 25 ] = V_18 ;
} else {
if ( V_17 ) {
V_17 = F_21 ( V_17 , 4 ) ;
if ( F_22 ( V_17 ) )
V_20 -> V_31 [ 30 ] = V_17 ;
}
V_20 -> V_27 = ( unsigned long ) V_21 + V_28 + V_29 ;
if ( F_23 ( V_19 -> F_23 ) == V_32 ) {
#ifdef F_18
V_20 -> V_30 = ( unsigned long ) & V_24 ;
#else
F_24 () ;
#endif
} else {
V_20 -> V_30 = ( unsigned long ) & V_23 ;
}
if ( V_16 & V_33 )
V_20 -> V_34 = V_20 -> V_31 [ 23 ] ;
}
return 0 ;
}
unsigned long F_25 ( struct V_8 * V_35 )
{
return V_35 -> V_15 . V_11 . V_30 ;
}
unsigned long
F_26 ( struct V_8 * V_19 )
{
struct V_36 V_37 ;
unsigned long V_38 ;
int V_39 = 0 ;
if ( ! V_19 || V_19 == V_40 || V_19 -> V_41 == V_42 )
return 0 ;
F_27 ( & V_37 , V_19 ) ;
do {
if ( F_28 ( & V_37 ) < 0 )
return 0 ;
V_38 = V_37 . V_38 ;
if ( ! F_29 ( V_38 ) )
return V_38 ;
} while ( V_39 ++ < 16 );
return 0 ;
}
void * F_30 ( void * V_43 )
{
T_2 * V_44 = V_43 ;
void * V_19 ;
if ( ! F_31 ( & V_44 -> V_45 , V_19 ) )
V_43 = V_19 ;
return V_43 ;
}
static inline unsigned long F_32 ( void )
{
if ( F_33 () )
return ( F_34 () & 0x7ffUL ) << V_46 ;
else
return ( F_34 () & 0x3ffffUL ) << V_46 ;
}
unsigned long F_35 ( struct V_47 * V_48 )
{
unsigned long V_49 = F_36 ( V_48 -> V_50 + F_32 () ) ;
if ( V_49 < V_48 -> V_50 )
return V_48 -> V_50 ;
return V_49 ;
}
