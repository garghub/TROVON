static void
F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 ;
unsigned int V_3 ;
const int V_4 = V_5 . V_6 ;
if ( F_2 ( V_1 == NULL ) )
return;
V_2 = F_3 ( V_1 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 += V_4 )
F_4 ( V_2 + V_3 ) ;
F_5 ( V_2 ) ;
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
V_2 = F_3 ( V_1 ) ;
F_14 ( ( unsigned long ) V_2 ,
( unsigned long ) V_2 + V_7 ) ;
F_5 ( V_2 ) ;
}
#else
F_13 ( V_12 L_2 ) ;
F_15 ( 1 ) ;
#endif
}
void
F_16 ( struct V_14 * V_15 )
{
#if F_11 ( V_10 )
if ( V_11 ) {
struct V_16 V_17 ;
F_7 () ;
F_17 (st->sgl, &sg_iter, st->nents, 0 )
F_1 ( F_18 ( & V_17 ) ) ;
F_7 () ;
return;
}
if ( F_12 ( F_8 , NULL , 1 ) != 0 )
F_13 ( V_12 L_1 ) ;
#else
F_13 ( V_12 L_2 ) ;
F_15 ( 1 ) ;
#endif
}
void
F_19 ( void * V_18 , unsigned long V_19 )
{
#if F_11 ( V_10 )
if ( V_11 ) {
void * V_20 = V_18 + V_19 ;
F_7 () ;
for (; V_18 < V_20 ; V_18 += V_5 . V_6 )
F_4 ( V_18 ) ;
F_4 ( V_20 - 1 ) ;
F_7 () ;
return;
}
if ( F_12 ( F_8 , NULL , 1 ) != 0 )
F_13 ( V_12 L_1 ) ;
#else
F_13 ( V_12 L_2 ) ;
F_15 ( 1 ) ;
#endif
}
