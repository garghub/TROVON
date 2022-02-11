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
int F_4 ( T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 ,
T_2 * * V_4 )
{
T_2 * V_5 = * V_4 ;
unsigned long V_6 ;
unsigned long V_7 ;
if ( V_5 == NULL )
* V_4 = V_5 = V_14 . V_9 -> V_6 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_2 ( & V_10 , V_6 , V_14 . V_11 [ V_7 ] ,
F_3 ( V_1 [ V_7 ] , V_12 ) ) ;
V_6 += V_13 ;
}
return 0 ;
}
void F_5 ( void * V_5 , unsigned long V_2 )
{
T_3 * * V_11 ;
unsigned long V_6 ;
unsigned long V_7 ;
if ( V_5 == V_14 . V_9 -> V_6 )
V_11 = V_14 . V_11 ;
else
V_11 = V_8 . V_11 ;
V_6 = ( unsigned long ) V_5 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
F_2 ( & V_10 , V_6 , V_11 [ V_7 ] , F_6 ( 0 ) ) ;
V_6 += V_13 ;
}
}
static int F_7 ( struct V_15 * V_9 , unsigned V_16 )
{
V_9 -> V_11 = F_8 ( sizeof( T_3 * ) * V_16 , V_17 ) ;
if ( V_9 -> V_11 == NULL )
return - V_18 ;
V_9 -> V_9 = F_9 ( V_13 * V_16 , V_9 -> V_11 ) ;
if ( V_9 -> V_9 == NULL ) {
F_10 ( V_9 -> V_11 ) ;
return - V_18 ;
}
return 0 ;
}
static void F_11 ( struct V_15 * V_9 )
{
F_12 ( V_9 -> V_9 ) ;
F_10 ( V_9 -> V_11 ) ;
}
int F_13 ( unsigned long V_19 , unsigned long V_20 )
{
int V_21 ;
if ( ! F_14 () )
return 0 ;
V_21 = F_7 ( & V_8 , V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_7 ( & V_14 , V_20 ) ;
if ( V_21 < 0 )
goto V_22;
return 0 ;
V_22:
F_11 ( & V_8 ) ;
return - V_18 ;
}
static int T_4 F_15 ( void )
{
struct V_23 * * V_24 ;
T_5 * V_25 ;
int V_26 ;
unsigned int V_7 ;
unsigned long V_27 = F_16 () ;
F_17 ( V_27 == 0 ) ;
V_24 = F_18 ( V_27 , sizeof( V_24 [ 0 ] ) , V_17 ) ;
if ( ! V_24 )
return - V_18 ;
V_25 = F_18 ( V_27 , sizeof( V_25 [ 0 ] ) , V_17 ) ;
if ( ! V_25 ) {
F_10 ( V_24 ) ;
return - V_18 ;
}
V_26 = F_19 ( V_27 , V_24 , 0 ) ;
if ( V_26 ) {
F_20 ( L_1 , V_28 ,
V_27 , V_26 ) ;
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
return V_26 ;
}
for ( V_7 = 0 ; V_7 < V_27 ; V_7 ++ )
V_25 [ V_7 ] = F_21 ( V_24 [ V_7 ] ) ;
V_26 = F_1 ( V_25 , V_27 , V_27 ,
& V_29 . V_30 ) ;
if ( V_26 ) {
F_20 ( L_2 , V_28 ,
V_27 , V_26 ) ;
F_22 ( V_27 , V_24 ) ;
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
return V_26 ;
}
F_10 ( V_24 ) ;
V_29 . V_31 = V_25 ;
V_29 . V_32 = V_27 ;
return 0 ;
}
static int T_4 F_23 ( void )
{
if ( ! F_24 () )
return - V_33 ;
return F_15 () ;
}
