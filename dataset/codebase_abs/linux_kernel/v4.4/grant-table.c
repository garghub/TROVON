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
V_9 -> V_11 = F_7 ( sizeof( V_16 * ) * V_15 , V_17 ) ;
if ( V_9 -> V_11 == NULL )
return - V_18 ;
V_9 -> V_9 = F_8 ( V_13 * V_15 , V_9 -> V_11 ) ;
if ( V_9 -> V_9 == NULL ) {
F_9 ( V_9 -> V_11 ) ;
return - V_18 ;
}
return 0 ;
}
int F_10 ( unsigned long V_19 )
{
if ( ! F_11 () )
return 0 ;
return F_6 ( & V_8 , V_19 ) ;
}
static int T_1 F_12 ( void )
{
struct V_20 * * V_21 ;
T_2 * V_22 ;
void * V_23 ;
int V_24 ;
unsigned int V_7 ;
unsigned long V_25 = F_13 () ;
F_14 ( V_25 == 0 ) ;
V_21 = F_15 ( V_25 , sizeof( V_21 [ 0 ] ) , V_17 ) ;
if ( ! V_21 )
return - V_18 ;
V_22 = F_15 ( V_25 , sizeof( V_22 [ 0 ] ) , V_17 ) ;
if ( ! V_22 ) {
F_9 ( V_21 ) ;
return - V_18 ;
}
V_24 = F_16 ( V_25 , V_21 ) ;
if ( V_24 ) {
F_17 ( L_1 , V_26 ,
V_25 , V_24 ) ;
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
return V_24 ;
}
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ )
V_22 [ V_7 ] = F_18 ( V_21 [ V_7 ] ) ;
V_23 = F_19 ( V_21 , V_25 , 0 , V_12 ) ;
if ( ! V_23 ) {
F_17 ( L_2 , V_26 ,
V_25 , V_24 ) ;
F_20 ( V_25 , V_21 ) ;
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
return - V_18 ;
}
F_9 ( V_21 ) ;
V_27 . V_28 = V_22 ;
V_27 . V_29 = V_25 ;
V_27 . V_23 = V_23 ;
return 0 ;
}
static int T_1 F_21 ( void )
{
if ( ! F_22 () )
return - V_30 ;
return F_12 () ;
}
