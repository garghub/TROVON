static inline unsigned long F_1 ( const struct V_1 * V_2 )
{
#ifndef F_2
return V_2 -> F_1 ;
#else
return ( unsigned long ) V_2 + V_2 -> V_3 ;
#endif
}
static struct V_1 * F_3 ( unsigned long V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 = NULL ;
F_4 () ;
F_5 (mod, &module_bug_list, bug_list) {
unsigned V_7 ;
V_2 = V_6 -> V_8 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_9 ; ++ V_7 , ++ V_2 )
if ( V_4 == F_1 ( V_2 ) )
goto V_10;
}
V_2 = NULL ;
V_10:
F_6 () ;
return V_2 ;
}
void F_7 ( const T_1 * V_11 , const T_2 * V_12 ,
struct V_5 * V_6 )
{
char * V_13 ;
unsigned int V_7 ;
F_8 ( & V_14 ) ;
V_6 -> V_8 = NULL ;
V_6 -> V_9 = 0 ;
V_13 = ( char * ) V_11 + V_12 [ V_11 -> V_15 ] . V_16 ;
for ( V_7 = 1 ; V_7 < V_11 -> V_17 ; V_7 ++ ) {
if ( strcmp ( V_13 + V_12 [ V_7 ] . V_18 , L_1 ) )
continue;
V_6 -> V_8 = ( void * ) V_12 [ V_7 ] . V_19 ;
V_6 -> V_9 = V_12 [ V_7 ] . V_20 / sizeof( struct V_1 ) ;
break;
}
F_9 ( & V_6 -> V_21 , & V_22 ) ;
}
void F_10 ( struct V_5 * V_6 )
{
F_8 ( & V_14 ) ;
F_11 ( & V_6 -> V_21 ) ;
}
static inline struct V_1 * F_3 ( unsigned long V_4 )
{
return NULL ;
}
struct V_1 * F_12 ( unsigned long V_4 )
{
struct V_1 * V_2 ;
for ( V_2 = V_23 ; V_2 < V_24 ; ++ V_2 )
if ( V_4 == F_1 ( V_2 ) )
return V_2 ;
return F_3 ( V_4 ) ;
}
enum V_25 F_13 ( unsigned long V_4 , struct V_26 * V_27 )
{
struct V_1 * V_2 ;
const char * V_28 ;
unsigned line , V_29 , V_30 , V_31 ;
if ( ! F_14 ( V_4 ) )
return V_32 ;
V_2 = F_12 ( V_4 ) ;
V_28 = NULL ;
line = 0 ;
V_29 = 0 ;
if ( V_2 ) {
#ifdef F_15
#ifndef F_2
V_28 = V_2 -> V_28 ;
#else
V_28 = ( const char * ) V_2 + V_2 -> V_33 ;
#endif
line = V_2 -> line ;
#endif
V_29 = ( V_2 -> V_34 & V_35 ) != 0 ;
V_30 = ( V_2 -> V_34 & V_36 ) != 0 ;
V_31 = ( V_2 -> V_34 & V_37 ) != 0 ;
if ( V_29 && V_30 ) {
if ( V_31 )
return V_38 ;
V_2 -> V_34 |= V_37 ;
}
}
if ( V_29 ) {
F_16 ( V_28 , line , ( void * ) V_4 , F_17 ( V_2 ) , V_27 ,
NULL ) ;
return V_38 ;
}
F_18 ( V_39 L_2 ) ;
if ( V_28 )
F_19 ( L_3 , V_28 , line ) ;
else
F_19 ( L_4 ,
( void * ) V_4 ) ;
return V_40 ;
}
