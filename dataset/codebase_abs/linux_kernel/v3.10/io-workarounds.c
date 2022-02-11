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
struct V_1 * V_11 ;
int V_21 ;
V_21 = F_3 ( V_20 ) ;
if ( V_21 && V_21 <= V_10 )
V_11 = & V_12 [ V_21 - 1 ] ;
else {
unsigned long V_2 , V_3 ;
T_2 * V_22 ;
V_2 = ( unsigned long ) F_4 ( V_20 ) ;
if ( V_2 < V_23 || V_2 >= V_24 )
return NULL ;
V_22 = F_5 ( V_25 . V_26 , V_2 ) ;
if ( V_22 == NULL )
V_3 = 0 ;
else
V_3 = F_6 ( * V_22 ) << V_27 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 == NULL )
return NULL ;
}
return V_11 ;
}
struct V_1 * F_7 ( unsigned long V_28 )
{
unsigned long V_2 = ( unsigned long ) V_29 + V_28 ;
return F_1 ( V_2 , 0 ) ;
}
static void T_3 * F_8 ( T_4 V_20 , unsigned long V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_1 * V_11 ;
void T_3 * V_7 = F_9 ( V_20 , V_30 , V_31 , V_32 ) ;
int V_33 ;
V_11 = F_1 ( 0 , ( unsigned long ) V_20 ) ;
if ( V_11 != NULL ) {
V_33 = V_11 - V_12 ;
F_10 ( V_7 , V_33 + 1 ) ;
}
return V_7 ;
}
static void F_11 ( void )
{
static int V_34 ;
if ( V_34 )
return;
V_35 = V_36 ;
V_37 . V_38 = F_8 ;
V_34 = 1 ;
}
void F_12 ( struct V_13 * V_14 , struct V_35 * V_39 ,
int (* F_13)( struct V_1 * , void * ) , void * V_40 )
{
struct V_1 * V_11 ;
struct V_41 * V_42 = V_14 -> V_43 ;
F_11 () ;
if ( V_10 >= V_44 ) {
F_14 ( L_1
L_2 , V_42 -> V_45 ) ;
return;
}
V_11 = & V_12 [ V_10 ] ;
V_11 -> V_14 = V_14 ;
V_11 -> V_39 = V_39 ;
V_11 -> V_46 = V_40 ;
if ( F_13 )
if ( (* F_13)( V_11 , V_40 ) )
return;
V_10 ++ ;
F_15 ( L_3 , V_10 - 1 , V_42 -> V_45 ) ;
}
