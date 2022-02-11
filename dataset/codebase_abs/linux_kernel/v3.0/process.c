void F_1 ( void )
{
F_2 ( V_1 ) ;
while ( 1 ) {
while ( ! F_3 () )
F_4 () ;
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
F_24 ( V_11 ) ;
}
void F_25 ( struct V_12 * V_13 )
{
}
int F_26 ( struct V_14 * V_15 , T_2 * V_16 )
{
if ( V_15 == NULL )
return 0 ;
memcpy ( V_16 , V_15 -> V_17 , sizeof *V_16 ) ;
return 1 ;
}
int F_27 ( struct V_12 * V_18 , T_2 * V_16 )
{
memcpy ( V_16 , V_18 -> V_19 . V_15 . V_17 , sizeof( * V_16 ) ) ;
return 1 ;
}
int
F_28 ( unsigned long V_20 , unsigned long V_21 ,
struct V_14 * V_15 )
{
int T_3 * V_22 = ( int T_3 * ) V_15 -> V_23 [ 24 ] ;
int T_3 * V_24 = ( int T_3 * ) V_15 -> V_23 [ 22 ] ;
V_21 = F_29 ( V_21 , 4 ) ;
if ( V_21 == 0 )
V_21 = V_15 -> V_23 [ 30 ] ;
return F_30 ( V_20 , V_21 , V_15 , 0 , V_22 , V_24 ) ;
}
int
F_31 ( struct V_14 * V_15 )
{
return F_30 ( V_25 | V_26 | V_27 , V_15 -> V_23 [ 30 ] , V_15 , 0 , NULL , NULL ) ;
}
int
F_32 ( unsigned long V_20 , unsigned long V_21 ,
unsigned long V_28 ,
struct V_12 * V_29 , struct V_14 * V_30 )
{
struct V_14 * V_31 = & ( V_29 -> V_19 . V_15 ) ;
void * V_32 = F_33 ( V_29 ) ;
extern void * const V_33 ;
extern void * const V_34 ;
#ifdef F_34
extern void * const V_35 ;
#endif
* V_31 = * V_30 ;
V_31 -> V_23 [ 28 ] = 0 ;
if ( V_21 == 1 ) {
V_31 -> V_36 = ( unsigned long ) V_32 + V_37 ;
V_31 -> V_38 = ( unsigned long ) & V_33 ;
#ifdef F_35
V_31 -> V_23 [ 27 ] = V_30 -> V_23 [ 27 ] ;
#endif
V_31 -> V_23 [ 26 ] = V_30 -> V_23 [ 26 ] ;
V_31 -> V_23 [ 25 ] = V_30 -> V_23 [ 25 ] ;
} else {
V_31 -> V_36 = ( unsigned long ) V_32
+ ( V_30 -> V_23 [ 21 ] & ( V_39 - 1 ) ) ;
V_31 -> V_23 [ 30 ] = V_21 ;
if ( V_29 -> V_40 == V_41 ) {
#ifdef F_34
V_31 -> V_38 = ( unsigned long ) & V_35 ;
#else
F_36 () ;
#endif
} else {
V_31 -> V_38 = ( unsigned long ) & V_34 ;
}
if ( V_20 & V_42 )
V_31 -> V_43 = V_30 -> V_23 [ 23 ] ;
}
return 0 ;
}
unsigned long F_37 ( struct V_12 * V_44 )
{
return V_44 -> V_19 . V_15 . V_38 ;
}
T_4 int F_38 ( struct V_14 * V_15 )
{
int error ;
char * V_45 ;
V_45 = F_39 ( ( const char T_3 * ) V_15 -> V_23 [ 26 ] ) ;
error = F_40 ( V_45 ) ;
if ( F_41 ( V_45 ) )
goto V_46;
error = F_42 ( V_45 ,
( const char T_3 * const T_3 * ) V_15 -> V_23 [ 25 ] ,
( const char T_3 * const T_3 * ) V_15 -> V_23 [ 24 ] ,
V_15 ) ;
F_43 ( V_45 ) ;
V_46:
return error ;
}
int F_44 ( const char * V_45 ,
const char * const V_47 [] ,
const char * const V_48 [] )
{
return F_45 ( V_45 , V_47 , V_48 , V_49 ) ;
}
unsigned long
F_46 ( struct V_12 * V_29 )
{
struct V_50 V_51 ;
unsigned long V_52 ;
int V_53 = 0 ;
if ( ! V_29 || V_29 == V_49 || V_29 -> V_54 == V_55 )
return 0 ;
F_47 ( & V_51 , V_29 ) ;
do {
if ( F_48 ( & V_51 ) < 0 )
return 0 ;
V_52 = V_51 . V_52 ;
if ( ! F_49 ( V_52 ) )
return V_52 ;
} while ( V_53 ++ < 16 );
return 0 ;
}
void * F_50 ( void * V_56 )
{
T_5 * V_57 = V_56 ;
void * V_29 ;
if ( ! F_51 ( & V_57 -> V_58 , V_29 ) )
V_56 = V_29 ;
return V_56 ;
}
