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
F_11 () ;
F_12 () ;
for (; ; ) ;
}
void F_13 ( void )
{
}
void F_14 ( struct V_8 * V_9 )
{
}
int F_15 ( struct V_10 * V_11 , T_1 * V_12 )
{
if ( V_11 == NULL )
return 0 ;
memcpy ( V_12 , V_11 -> V_13 , sizeof *V_12 ) ;
return 1 ;
}
int F_16 ( struct V_8 * V_14 , T_1 * V_12 )
{
memcpy ( V_12 , V_14 -> V_15 . V_11 . V_13 , sizeof( * V_12 ) ) ;
return 1 ;
}
int
F_17 ( unsigned long V_16 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * V_19 )
{
struct V_10 * V_20 = & ( V_19 -> V_15 . V_11 ) ;
void * V_21 = F_18 ( V_19 ) ;
extern void * const V_22 ;
extern void * const V_23 ;
if ( F_19 ( V_19 -> V_24 & V_25 ) ) {
memset ( V_20 , 0 , sizeof( struct V_10 ) ) ;
if ( ! V_17 )
return 0 ;
V_20 -> V_26 = ( unsigned long ) V_21 + V_27 + V_28 ;
V_20 -> V_29 = ( unsigned long ) & V_22 ;
#ifdef F_20
V_20 -> V_30 [ 27 ] = ( ( unsigned long * ) V_17 ) [ 3 ] ;
V_20 -> V_30 [ 26 ] = ( ( unsigned long * ) V_17 ) [ 2 ] ;
#else
V_20 -> V_30 [ 26 ] = V_17 ;
#endif
V_20 -> V_30 [ 25 ] = V_18 ;
} else {
if ( V_17 ) {
V_17 = F_21 ( V_17 , 4 ) ;
if ( F_22 ( V_17 ) )
V_20 -> V_30 [ 30 ] = V_17 ;
}
V_20 -> V_26 = ( unsigned long ) V_21 + V_27 + V_28 ;
V_20 -> V_29 = ( unsigned long ) & V_23 ;
if ( V_16 & V_31 )
V_20 -> V_32 = V_20 -> V_30 [ 23 ] ;
}
return 0 ;
}
unsigned long
F_23 ( struct V_8 * V_19 )
{
struct V_33 V_34 ;
unsigned long V_35 ;
int V_36 = 0 ;
if ( ! V_19 || V_19 == V_37 || V_19 -> V_38 == V_39 )
return 0 ;
F_24 ( & V_34 , V_19 ) ;
do {
if ( F_25 ( & V_34 ) < 0 )
return 0 ;
V_35 = V_34 . V_35 ;
if ( ! F_26 ( V_35 ) )
return V_35 ;
} while ( V_36 ++ < 16 );
return 0 ;
}
void * F_27 ( void * V_40 )
{
T_2 * V_41 = V_40 ;
void * V_19 ;
if ( ! F_28 ( & V_41 -> V_42 , V_19 ) )
V_40 = V_19 ;
return V_40 ;
}
static inline unsigned long F_29 ( void )
{
return ( F_30 () & V_43 ) << V_44 ;
}
unsigned long F_31 ( struct V_45 * V_46 )
{
unsigned long V_47 = F_32 ( V_46 -> V_48 + F_29 () ) ;
if ( V_47 < V_46 -> V_48 )
return V_46 -> V_48 ;
return V_47 ;
}
