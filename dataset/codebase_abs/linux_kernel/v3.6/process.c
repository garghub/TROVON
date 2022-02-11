void F_1 ( void )
{
F_2 ( V_1 ) ;
while ( 1 ) {
while ( ! F_3 () )
F_4 () ;
F_5 () ;
F_6 () ;
}
}
void F_7 ( char * V_2 )
{
#ifdef F_8
if ( V_3 ) {
F_9 ( V_3 ) ;
}
#endif
F_10 ( V_4 ) ;
F_11 () ;
F_12 ( V_5 , V_6 ) ;
while ( 1 ) ;
}
void F_13 ( void )
{
}
void F_14 ( void )
{
if ( V_7 )
V_7 () ;
F_15 ( 0 ) ;
F_10 ( V_4 ) ;
F_16 ( V_8 L_1
L_2 ) ;
}
T_1 F_17 ( int (* F_18)( void * ) , void * V_9 , unsigned long V_10 )
{
return F_19 ( F_18 , V_9 , V_10 ) ;
}
void F_20 ( void )
{
}
void F_21 ( void )
{
}
void F_22 ( struct V_11 * V_12 )
{
}
int F_23 ( struct V_13 * V_14 , T_2 * V_15 )
{
if ( V_14 == NULL )
return 0 ;
memcpy ( V_15 , V_14 -> V_16 , sizeof *V_15 ) ;
return 1 ;
}
int F_24 ( struct V_11 * V_17 , T_2 * V_15 )
{
memcpy ( V_15 , V_17 -> V_18 . V_14 . V_16 , sizeof( * V_15 ) ) ;
return 1 ;
}
int
F_25 ( unsigned long V_19 , unsigned long V_20 ,
struct V_13 * V_14 )
{
int T_3 * V_21 = ( int T_3 * ) V_14 -> V_22 [ 24 ] ;
int T_3 * V_23 = ( int T_3 * ) V_14 -> V_22 [ 22 ] ;
V_20 = F_26 ( V_20 , 4 ) ;
if ( V_20 == 0 )
V_20 = V_14 -> V_22 [ 30 ] ;
return F_27 ( V_19 , V_20 , V_14 , 0 , V_21 , V_23 ) ;
}
int
F_28 ( struct V_13 * V_14 )
{
return F_27 ( V_24 | V_25 | V_26 , V_14 -> V_22 [ 30 ] , V_14 , 0 , NULL , NULL ) ;
}
int
F_29 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_27 ,
struct V_11 * V_28 , struct V_13 * V_29 )
{
struct V_13 * V_30 = & ( V_28 -> V_18 . V_14 ) ;
void * V_31 = F_30 ( V_28 ) ;
extern void * const V_32 ;
extern void * const V_33 ;
#ifdef F_31
extern void * const V_34 ;
#endif
* V_30 = * V_29 ;
V_30 -> V_22 [ 28 ] = 0 ;
if ( V_20 == 1 ) {
V_30 -> V_35 = ( unsigned long ) V_31 + V_36 ;
V_30 -> V_37 = ( unsigned long ) & V_32 ;
#ifdef F_32
V_30 -> V_22 [ 27 ] = V_29 -> V_22 [ 27 ] ;
#endif
V_30 -> V_22 [ 26 ] = V_29 -> V_22 [ 26 ] ;
V_30 -> V_22 [ 25 ] = V_29 -> V_22 [ 25 ] ;
} else {
V_30 -> V_35 = ( unsigned long ) V_31
+ ( V_29 -> V_22 [ 21 ] & ( V_38 - 1 ) ) ;
V_30 -> V_22 [ 30 ] = V_20 ;
if ( F_33 ( V_28 -> F_33 ) == V_39 ) {
#ifdef F_31
V_30 -> V_37 = ( unsigned long ) & V_34 ;
#else
F_34 () ;
#endif
} else {
V_30 -> V_37 = ( unsigned long ) & V_33 ;
}
if ( V_19 & V_40 )
V_30 -> V_41 = V_29 -> V_22 [ 23 ] ;
}
return 0 ;
}
unsigned long F_35 ( struct V_11 * V_42 )
{
return V_42 -> V_18 . V_14 . V_37 ;
}
T_4 int F_36 ( struct V_13 * V_14 )
{
int error ;
char * V_43 ;
V_43 = F_37 ( ( const char T_3 * ) V_14 -> V_22 [ 26 ] ) ;
error = F_38 ( V_43 ) ;
if ( F_39 ( V_43 ) )
goto V_44;
error = F_40 ( V_43 ,
( const char T_3 * const T_3 * ) V_14 -> V_22 [ 25 ] ,
( const char T_3 * const T_3 * ) V_14 -> V_22 [ 24 ] ,
V_14 ) ;
F_41 ( V_43 ) ;
V_44:
return error ;
}
int F_42 ( const char * V_43 ,
const char * const V_45 [] ,
const char * const V_46 [] )
{
return F_43 ( V_43 , V_45 , V_46 , V_47 ) ;
}
unsigned long
F_44 ( struct V_11 * V_28 )
{
struct V_48 V_49 ;
unsigned long V_50 ;
int V_51 = 0 ;
if ( ! V_28 || V_28 == V_47 || V_28 -> V_52 == V_53 )
return 0 ;
F_45 ( & V_49 , V_28 ) ;
do {
if ( F_46 ( & V_49 ) < 0 )
return 0 ;
V_50 = V_49 . V_50 ;
if ( ! F_47 ( V_50 ) )
return V_50 ;
} while ( V_51 ++ < 16 );
return 0 ;
}
void * F_48 ( void * V_54 )
{
T_5 * V_55 = V_54 ;
void * V_28 ;
if ( ! F_49 ( & V_55 -> V_56 , V_28 ) )
V_54 = V_28 ;
return V_54 ;
}
