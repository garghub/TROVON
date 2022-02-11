struct V_1 *
F_1 ( void )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_5 = NULL ;
unsigned long V_6 ;
F_2 ( & V_3 -> V_7 , V_6 ) ;
V_5 = & V_3 -> V_8 [ V_3 -> V_9 ] ;
V_3 -> V_9 ++ ;
if ( V_3 -> V_9 == V_3 -> V_10 )
V_3 -> V_9 = 0 ;
if ( V_3 -> V_9 != V_3 -> V_11 ) {
F_3 ( & V_3 -> V_7 , V_6 ) ;
goto V_12;
}
V_3 -> V_11 ++ ;
if ( V_3 -> V_11 == V_3 -> V_10 )
V_3 -> V_11 = 0 ;
V_5 -> V_13 = 0 ;
F_3 ( & V_3 -> V_7 , V_6 ) ;
V_12:
return V_5 ;
}
static int
F_4 ( struct V_1 * V_5 , char * V_8 , int V_14 )
{
int V_15 = 0 ;
struct V_16 V_17 ;
F_5 ( V_5 -> V_13 , & V_17 ) ;
V_15 += snprintf ( V_8 , V_14 ,
L_1 ,
V_17 . V_18 ,
V_17 . V_19 ,
V_5 -> V_20 ,
V_5 -> V_21 ,
V_5 -> V_22 ,
V_5 -> V_23 [ 0 ] , V_5 -> V_23 [ 1 ] , V_5 -> V_23 [ 2 ] , V_5 -> V_23 [ 3 ] ,
V_5 -> V_23 [ 4 ] ) ;
return V_15 ;
}
int
F_6 ( char * V_8 , int V_14 )
{
struct V_1 * V_5 = NULL ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_6 ;
F_2 ( & V_3 -> V_7 , V_6 ) ;
if ( V_3 -> V_11 == V_3 -> V_9 ) {
F_3 ( & V_3 -> V_7 , V_6 ) ;
return - 1 ;
}
V_5 = & V_3 -> V_8 [ V_3 -> V_11 ] ;
if ( V_5 -> V_13 == 0 ) {
F_3 ( & V_3 -> V_7 , V_6 ) ;
return - 1 ;
}
V_3 -> V_11 ++ ;
if ( V_3 -> V_11 == V_3 -> V_10 )
V_3 -> V_11 = 0 ;
F_3 ( & V_3 -> V_7 , V_6 ) ;
return F_4 ( V_5 , V_8 , V_14 ) ;
}
int
F_7 ( void )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
void * V_24 = NULL ;
int V_25 = 0 , V_26 ;
V_25 = ( V_27 * V_28 ) ;
V_24 = F_8 ( V_25 ) ;
if ( ! V_24 ) {
F_9 ( L_2 , V_25 ) ;
F_9 ( L_3 ) ;
V_26 = - V_29 ;
return V_26 ;
}
memset ( V_24 , 0 , V_25 ) ;
V_3 -> V_8 = (struct V_1 * ) V_24 ;
F_10 ( & V_3 -> V_7 ) ;
V_26 = F_11 () ;
if ( V_26 ) {
F_9 ( L_4 ) ;
goto error;
}
V_3 -> V_10 = ( V_25 / V_30 ) ;
V_3 -> V_11 = V_3 -> V_9 = 0 ;
V_3 -> V_31 = true ;
F_12 ( L_5 ,
V_25 / V_28 ) ;
V_26 = 0 ;
return V_26 ;
error:
F_13 () ;
return V_26 ;
}
void
F_13 ( void )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
V_3 -> V_31 = false ;
F_14 () ;
if ( V_3 -> V_8 ) {
F_15 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
F_12 ( L_6 ) ;
}
