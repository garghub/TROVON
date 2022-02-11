void F_1 ( void )
{
F_2 ( V_1 ) ;
while ( 1 ) {
F_3 () ;
while ( ! F_4 () )
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
}
}
void F_9 ( char * V_2 )
{
#ifdef F_10
if ( V_3 ) {
F_11 ( V_3 ) ;
}
#endif
F_12 ( V_4 ) ;
F_13 () ;
F_14 ( V_5 , V_6 ) ;
while ( 1 ) ;
}
void F_15 ( void )
{
}
void F_16 ( void )
{
if ( V_7 )
V_7 () ;
F_17 ( 0 ) ;
F_12 ( V_4 ) ;
F_18 ( V_8 L_1
L_2 ) ;
}
void F_19 ( void )
{
}
void F_20 ( void )
{
}
void F_21 ( struct V_9 * V_10 )
{
}
int F_22 ( struct V_11 * V_12 , T_1 * V_13 )
{
if ( V_12 == NULL )
return 0 ;
memcpy ( V_13 , V_12 -> V_14 , sizeof *V_13 ) ;
return 1 ;
}
int F_23 ( struct V_9 * V_15 , T_1 * V_13 )
{
memcpy ( V_13 , V_15 -> V_16 . V_12 . V_14 , sizeof( * V_13 ) ) ;
return 1 ;
}
int
F_24 ( unsigned long V_17 , unsigned long V_18 ,
unsigned long V_19 , struct V_9 * V_20 )
{
struct V_11 * V_21 = & ( V_20 -> V_16 . V_12 ) ;
void * V_22 = F_25 ( V_20 ) ;
extern void * const V_23 ;
extern void * const V_24 ;
#ifdef F_26
extern void * const V_25 ;
#endif
if ( F_27 ( V_20 -> V_26 & V_27 ) ) {
memset ( V_21 , 0 , sizeof( struct V_11 ) ) ;
if ( ! V_18 )
return 0 ;
V_21 -> V_28 = ( unsigned long ) V_22 + V_29 + V_30 ;
V_21 -> V_31 = ( unsigned long ) & V_23 ;
#ifdef F_28
V_21 -> V_32 [ 27 ] = ( ( unsigned long * ) V_18 ) [ 3 ] ;
V_21 -> V_32 [ 26 ] = ( ( unsigned long * ) V_18 ) [ 2 ] ;
#else
V_21 -> V_32 [ 26 ] = V_18 ;
#endif
V_21 -> V_32 [ 25 ] = V_19 ;
} else {
if ( V_18 ) {
V_18 = F_29 ( V_18 , 4 ) ;
if ( F_30 ( V_18 ) )
V_21 -> V_32 [ 30 ] = V_18 ;
}
V_21 -> V_28 = ( unsigned long ) V_22 + V_29 + V_30 ;
if ( F_31 ( V_20 -> F_31 ) == V_33 ) {
#ifdef F_26
V_21 -> V_31 = ( unsigned long ) & V_25 ;
#else
F_32 () ;
#endif
} else {
V_21 -> V_31 = ( unsigned long ) & V_24 ;
}
if ( V_17 & V_34 )
V_21 -> V_35 = V_21 -> V_32 [ 23 ] ;
}
return 0 ;
}
unsigned long F_33 ( struct V_9 * V_36 )
{
return V_36 -> V_16 . V_12 . V_31 ;
}
unsigned long
F_34 ( struct V_9 * V_20 )
{
struct V_37 V_38 ;
unsigned long V_39 ;
int V_40 = 0 ;
if ( ! V_20 || V_20 == V_41 || V_20 -> V_42 == V_43 )
return 0 ;
F_35 ( & V_38 , V_20 ) ;
do {
if ( F_36 ( & V_38 ) < 0 )
return 0 ;
V_39 = V_38 . V_39 ;
if ( ! F_37 ( V_39 ) )
return V_39 ;
} while ( V_40 ++ < 16 );
return 0 ;
}
void * F_38 ( void * V_44 )
{
T_2 * V_45 = V_44 ;
void * V_20 ;
if ( ! F_39 ( & V_45 -> V_46 , V_20 ) )
V_44 = V_20 ;
return V_44 ;
}
