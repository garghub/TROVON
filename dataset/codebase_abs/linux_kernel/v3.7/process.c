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
T_1 F_19 ( int (* F_20)( void * ) , void * V_9 , unsigned long V_10 )
{
return F_21 ( F_20 , V_9 , V_10 ) ;
}
void F_22 ( void )
{
}
void F_23 ( void )
{
}
void F_24 ( struct V_11 * V_12 )
{
}
int F_25 ( struct V_13 * V_14 , T_2 * V_15 )
{
if ( V_14 == NULL )
return 0 ;
memcpy ( V_15 , V_14 -> V_16 , sizeof *V_15 ) ;
return 1 ;
}
int F_26 ( struct V_11 * V_17 , T_2 * V_15 )
{
memcpy ( V_15 , V_17 -> V_18 . V_14 . V_16 , sizeof( * V_15 ) ) ;
return 1 ;
}
int
F_27 ( unsigned long V_19 , unsigned long V_20 ,
struct V_13 * V_14 )
{
int T_3 * V_21 = ( int T_3 * ) V_14 -> V_22 [ 24 ] ;
int T_3 * V_23 = ( int T_3 * ) V_14 -> V_22 [ 22 ] ;
V_20 = F_28 ( V_20 , 4 ) ;
if ( V_20 == 0 )
V_20 = V_14 -> V_22 [ 30 ] ;
return F_29 ( V_19 , V_20 , V_14 , 0 , V_21 , V_23 ) ;
}
int
F_30 ( struct V_13 * V_14 )
{
return F_29 ( V_24 | V_25 | V_26 , V_14 -> V_22 [ 30 ] , V_14 , 0 , NULL , NULL ) ;
}
int
F_31 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_27 ,
struct V_11 * V_28 , struct V_13 * V_29 )
{
struct V_13 * V_30 = & ( V_28 -> V_18 . V_14 ) ;
void * V_31 = F_32 ( V_28 ) ;
extern void * const V_32 ;
extern void * const V_33 ;
#ifdef F_33
extern void * const V_34 ;
#endif
* V_30 = * V_29 ;
V_30 -> V_22 [ 28 ] = 0 ;
if ( V_20 == 1 ) {
V_30 -> V_35 = ( unsigned long ) V_31 + V_36 ;
V_30 -> V_37 = ( unsigned long ) & V_32 ;
#ifdef F_34
V_30 -> V_22 [ 27 ] = V_29 -> V_22 [ 27 ] ;
#endif
V_30 -> V_22 [ 26 ] = V_29 -> V_22 [ 26 ] ;
V_30 -> V_22 [ 25 ] = V_29 -> V_22 [ 25 ] ;
} else {
V_30 -> V_35 = ( unsigned long ) V_31
+ ( V_29 -> V_22 [ 21 ] & ( V_38 - 1 ) ) ;
V_30 -> V_22 [ 30 ] = V_20 ;
if ( F_35 ( V_28 -> F_35 ) == V_39 ) {
#ifdef F_33
V_30 -> V_37 = ( unsigned long ) & V_34 ;
#else
F_36 () ;
#endif
} else {
V_30 -> V_37 = ( unsigned long ) & V_33 ;
}
if ( V_19 & V_40 )
V_30 -> V_41 = V_29 -> V_22 [ 23 ] ;
}
return 0 ;
}
unsigned long F_37 ( struct V_11 * V_42 )
{
return V_42 -> V_18 . V_14 . V_37 ;
}
T_4 int F_38 ( struct V_13 * V_14 )
{
int error ;
struct V_43 * V_43 ;
V_43 = F_39 ( ( const char T_3 * ) V_14 -> V_22 [ 26 ] ) ;
error = F_40 ( V_43 ) ;
if ( F_41 ( V_43 ) )
goto V_44;
error = F_42 ( V_43 -> V_45 ,
( const char T_3 * const T_3 * ) V_14 -> V_22 [ 25 ] ,
( const char T_3 * const T_3 * ) V_14 -> V_22 [ 24 ] ,
V_14 ) ;
F_43 ( V_43 ) ;
V_44:
return error ;
}
int F_44 ( const char * V_43 ,
const char * const V_46 [] ,
const char * const V_47 [] )
{
return F_45 ( V_43 , V_46 , V_47 , V_48 ) ;
}
unsigned long
F_46 ( struct V_11 * V_28 )
{
struct V_49 V_50 ;
unsigned long V_51 ;
int V_52 = 0 ;
if ( ! V_28 || V_28 == V_48 || V_28 -> V_53 == V_54 )
return 0 ;
F_47 ( & V_50 , V_28 ) ;
do {
if ( F_48 ( & V_50 ) < 0 )
return 0 ;
V_51 = V_50 . V_51 ;
if ( ! F_49 ( V_51 ) )
return V_51 ;
} while ( V_52 ++ < 16 );
return 0 ;
}
void * F_50 ( void * V_55 )
{
T_5 * V_56 = V_55 ;
void * V_28 ;
if ( ! F_51 ( & V_56 -> V_57 , V_28 ) )
V_55 = V_28 ;
return V_55 ;
}
