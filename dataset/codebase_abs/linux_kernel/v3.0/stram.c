void T_1 F_1 ( void )
{
int V_1 ;
for( V_1 = 0 ; V_1 < V_2 ; ++ V_1 )
V_3 [ V_1 ] . V_4 = V_5 ;
V_6 = F_2 ( 0 ) ;
V_7 = ( V_6 == 0 ) ;
for( V_1 = 0 ; V_1 < V_8 ; ++ V_1 ) {
if ( V_9 [ V_1 ] . V_10 == 0 ) {
V_11 = V_6 + V_9 [ V_1 ] . V_12 ;
return;
}
}
F_3 ( L_1 ) ;
}
void T_1 F_4 ( void * V_13 )
{
if ( ! V_7 )
F_5 ( 0 , V_14 , V_15 ) ;
}
void F_6 ( void )
{
V_16 = 1 ;
}
void * F_7 ( long V_12 , const char * V_17 )
{
void * V_10 = NULL ;
T_2 * V_18 ;
int V_4 ;
F_8 ( L_2 , V_12 , V_17 ) ;
if ( ! V_16 )
return F_9 ( V_12 ) ;
else {
V_10 = ( void * ) F_10 ( V_19 , F_11 ( V_12 ) ) ;
V_4 = V_20 ;
F_8 ( L_3
L_4 , V_10 ) ;
}
if ( V_10 ) {
if ( ! ( V_18 = F_12 ( V_10 , V_12 ) ) ) {
F_8 ( L_5
L_6 ) ;
F_13 ( ( unsigned long ) V_10 , F_11 ( V_12 ) ) ;
return ( NULL ) ;
}
V_18 -> V_17 = V_17 ;
V_18 -> V_4 |= V_4 ;
}
return ( V_10 ) ;
}
void F_14 ( void * V_10 )
{
T_2 * V_18 ;
F_8 ( L_7 , V_10 ) ;
if ( ! ( V_18 = F_15 ( V_10 ) ) ) {
F_16 ( V_21 L_8
L_9 , V_10 , F_17 ( 0 ) ) ;
return;
}
F_8 ( L_10
L_11 , V_18 , V_18 -> V_12 , V_18 -> V_17 , V_18 -> V_4 ) ;
if ( ! ( V_18 -> V_4 & V_20 ) )
goto V_22;
F_8 ( L_12 ,
F_11 ( V_18 -> V_12 ) ) ;
F_13 ( ( unsigned long ) V_10 , F_11 ( V_18 -> V_12 ) ) ;
F_18 ( V_18 ) ;
return;
V_22:
F_16 ( V_21 L_13
L_14 , V_10 , F_17 ( 0 ) ) ;
}
static T_2 * F_12 ( void * V_10 , unsigned long V_12 )
{
T_2 * * V_23 , * V_24 = NULL ;
int V_1 ;
for( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 & V_5 ) {
V_24 = & V_3 [ V_1 ] ;
V_24 -> V_4 = 0 ;
break;
}
}
if ( ! V_24 && V_16 ) {
V_24 = F_19 ( sizeof( T_2 ) , V_19 ) ;
if ( V_24 )
V_24 -> V_4 = V_25 ;
}
if ( ! V_24 ) {
F_16 ( V_21 L_15 ) ;
return ( NULL ) ;
}
V_24 -> V_26 = V_10 ;
V_24 -> V_12 = V_12 ;
for( V_23 = & V_27 ; * V_23 ; V_23 = & ( ( * V_23 ) -> V_28 ) )
if ( ( * V_23 ) -> V_26 > V_10 ) break;
V_24 -> V_28 = * V_23 ;
* V_23 = V_24 ;
return ( V_24 ) ;
}
static T_2 * F_15 ( void * V_10 )
{
T_2 * V_23 ;
for( V_23 = V_27 ; V_23 ; V_23 = V_23 -> V_28 ) {
if ( V_23 -> V_26 == V_10 )
return ( V_23 ) ;
if ( V_23 -> V_26 > V_10 )
break;
}
return ( NULL ) ;
}
static int F_18 ( T_2 * V_18 )
{
T_2 * * V_23 ;
for( V_23 = & V_27 ; * V_23 ; V_23 = & ( ( * V_23 ) -> V_28 ) )
if ( * V_23 == V_18 ) break;
if ( ! * V_23 )
return ( 0 ) ;
* V_23 = V_18 -> V_28 ;
if ( V_18 -> V_4 & V_25 )
F_20 ( V_18 ) ;
else
V_18 -> V_4 |= V_5 ;
return ( 1 ) ;
}
static int F_21 ( struct V_29 * V_30 , void * V_31 )
{
T_2 * V_23 ;
F_22 ( L_16 ,
( V_11 - V_6 ) >> 10 ) ;
F_22 ( L_17 ) ;
for( V_23 = V_27 ; V_23 ; V_23 = V_23 -> V_28 ) {
F_22 ( L_18 ,
F_23 ( V_23 -> V_26 ) ,
F_23 ( V_23 -> V_26 + V_23 -> V_12 - 1 ) ,
V_23 -> V_17 ) ;
if ( V_23 -> V_4 & V_20 )
F_22 ( L_19 ) ;
else
F_22 ( L_20 ) ;
}
return 0 ;
}
static int F_24 ( struct V_32 * V_32 , struct V_33 * V_33 )
{
return F_25 ( V_33 , F_21 , NULL ) ;
}
static int T_1 F_26 ( void )
{
F_27 ( L_21 , 0 , NULL , & V_34 ) ;
return 0 ;
}
