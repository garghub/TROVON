static void
F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 ;
unsigned int V_3 ;
if ( F_2 ( V_1 == NULL ) )
return;
V_2 = F_3 ( V_1 , V_4 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 += V_6 . V_7 )
F_4 ( V_2 + V_3 ) ;
F_5 ( V_2 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_8 [] ,
unsigned long V_9 )
{
unsigned long V_3 ;
F_7 () ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
F_1 ( * V_8 ++ ) ;
F_7 () ;
}
static void
F_8 ( void * null )
{
F_9 () ;
}
void
F_10 ( struct V_1 * V_8 [] , unsigned long V_9 )
{
#if F_11 ( V_10 )
if ( V_11 ) {
F_6 ( V_8 , V_9 ) ;
return;
}
if ( F_12 ( F_8 , NULL , 1 ) != 0 )
F_13 ( V_12 L_1 ) ;
#elif F_11 ( V_13 )
unsigned long V_3 ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_1 * V_1 = V_8 [ V_3 ] ;
void * V_2 ;
if ( F_2 ( V_1 == NULL ) )
continue;
V_2 = F_3 ( V_1 , V_4 ) ;
F_14 ( ( unsigned long ) V_2 ,
( unsigned long ) V_2 + V_5 ) ;
F_5 ( V_2 , V_4 ) ;
}
#else
F_13 ( V_12 L_2 ) ;
F_15 ( 1 ) ;
#endif
}
