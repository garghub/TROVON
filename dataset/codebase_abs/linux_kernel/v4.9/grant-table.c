int F_1 ( unsigned long * V_1 , unsigned long V_2 ,
unsigned long V_3 ,
void * * V_4 )
{
void * V_5 = * V_4 ;
unsigned long V_6 ;
unsigned long V_7 ;
if ( V_5 == NULL )
* V_4 = V_5 = V_8 . V_9 -> V_6 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_2 ( & V_10 , V_6 , V_8 . V_11 [ V_7 ] ,
F_3 ( V_1 [ V_7 ] , V_12 ) ) ;
V_6 += V_13 ;
}
return 0 ;
}
void F_4 ( void * V_5 , unsigned long V_2 )
{
unsigned long V_6 ;
unsigned long V_7 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_2 ( & V_10 , V_6 , V_8 . V_11 [ V_7 ] ,
F_5 ( 0 ) ) ;
V_6 += V_13 ;
}
}
static int F_6 ( struct V_14 * V_9 , unsigned V_15 )
{
V_9 -> V_11 = F_7 ( V_15 , sizeof( * V_9 -> V_11 ) , V_16 ) ;
if ( V_9 -> V_11 == NULL )
return - V_17 ;
V_9 -> V_9 = F_8 ( V_13 * V_15 , V_9 -> V_11 ) ;
if ( V_9 -> V_9 == NULL ) {
F_9 ( V_9 -> V_11 ) ;
return - V_17 ;
}
return 0 ;
}
int F_10 ( unsigned long V_18 )
{
if ( ! F_11 () )
return 0 ;
return F_6 ( & V_8 , V_18 ) ;
}
static int T_1 F_12 ( void )
{
if ( ! F_13 () )
return - V_19 ;
V_20 . V_21 = F_14 () ;
return F_15 ( & V_20 . V_22 ,
& V_20 . V_23 ,
V_20 . V_21 ) ;
}
