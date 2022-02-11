static struct V_1 * F_1 ( unsigned long V_2 , unsigned long V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 , V_9 ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
struct V_1 * V_11 = & V_12 [ V_4 ] ;
struct V_13 * V_14 = V_11 -> V_14 ;
if ( V_2 ) {
V_8 = ( unsigned long ) V_14 -> V_15 ;
V_9 = V_8 + V_14 -> V_16 - 1 ;
if ( ( V_2 >= V_8 ) && ( V_2 <= V_9 ) )
return V_11 ;
}
if ( V_3 )
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_7 = & V_14 -> V_17 [ V_5 ] ;
if ( V_3 >= V_7 -> V_18 && V_3 <= V_7 -> V_19 )
return V_11 ;
}
}
return NULL ;
}
struct V_1 * F_2 ( const T_1 V_20 )
{
unsigned V_21 ;
struct V_1 * V_11 ;
int V_22 ;
V_22 = F_3 ( V_20 ) ;
if ( V_22 && V_22 <= V_10 )
V_11 = & V_12 [ V_22 - 1 ] ;
else {
unsigned long V_2 , V_3 ;
T_2 * V_23 ;
V_2 = ( unsigned long ) F_4 ( V_20 ) ;
if ( V_2 < V_24 || V_2 >= V_25 )
return NULL ;
V_23 = F_5 ( V_26 . V_27 , V_2 ,
& V_21 ) ;
if ( V_23 == NULL )
V_3 = 0 ;
else {
F_6 ( V_21 ) ;
V_3 = F_7 ( * V_23 ) << V_28 ;
}
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 == NULL )
return NULL ;
}
return V_11 ;
}
struct V_1 * F_2 ( const T_1 V_20 )
{
return NULL ;
}
struct V_1 * F_8 ( unsigned long V_29 )
{
unsigned long V_2 = ( unsigned long ) V_30 + V_29 ;
return F_1 ( V_2 , 0 ) ;
}
struct V_1 * F_8 ( unsigned long V_29 )
{
return NULL ;
}
static void T_3 * F_9 ( T_4 V_20 , unsigned long V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_1 * V_11 ;
void T_3 * V_7 = F_10 ( V_20 , V_31 , V_32 , V_33 ) ;
int V_34 ;
V_11 = F_1 ( 0 , ( unsigned long ) V_20 ) ;
if ( V_11 != NULL ) {
V_34 = V_11 - V_12 ;
F_11 ( V_7 , V_34 + 1 ) ;
}
return V_7 ;
}
static void F_12 ( void )
{
static int V_35 ;
if ( V_35 )
return;
V_36 = V_37 ;
V_38 . V_39 = F_9 ;
V_35 = 1 ;
}
void F_13 ( struct V_13 * V_14 , struct V_36 * V_40 ,
int (* F_14)( struct V_1 * , void * ) , void * V_41 )
{
struct V_1 * V_11 ;
struct V_42 * V_43 = V_14 -> V_44 ;
F_12 () ;
if ( V_10 >= V_45 ) {
F_15 ( L_1
L_2 , V_43 -> V_46 ) ;
return;
}
V_11 = & V_12 [ V_10 ] ;
V_11 -> V_14 = V_14 ;
V_11 -> V_40 = V_40 ;
V_11 -> V_47 = V_41 ;
if ( F_14 )
if ( (* F_14)( V_11 , V_41 ) )
return;
V_10 ++ ;
F_16 ( L_3 , V_10 - 1 , V_43 -> V_46 ) ;
}
