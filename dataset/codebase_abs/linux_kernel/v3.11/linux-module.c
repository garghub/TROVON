int F_1 ( char * V_1 , char * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_9 ;
V_5 = (struct V_4 * ) V_1 ;
V_7 = (struct V_6 * ) V_1 ;
V_8 = F_2 ( V_1 , ( void * ) V_3 , sizeof( * V_5 ) ) ;
if ( V_8 )
RETURN ( V_8 ) ;
if ( V_5 -> V_10 != V_11 ) {
F_3 ( L_1 ) ;
RETURN ( - V_12 ) ;
}
if ( V_5 -> V_13 + V_1 >= V_2 ) {
F_3 ( L_2 ) ;
RETURN ( - V_12 ) ;
}
if ( V_5 -> V_13 < sizeof( struct V_6 ) ) {
F_3 ( L_3 ) ;
RETURN ( - V_12 ) ;
}
V_8 = F_2 ( V_1 , ( void * ) V_3 , V_5 -> V_13 ) ;
if ( V_8 )
RETURN ( V_8 ) ;
if ( F_4 ( V_7 ) ) {
F_3 ( L_4 ) ;
RETURN ( - V_12 ) ;
}
if ( V_7 -> V_14 )
V_7 -> V_15 = & V_7 -> V_16 [ 0 ] ;
if ( V_7 -> V_17 )
V_7 -> V_18 = & V_7 -> V_16 [ 0 ] +
F_5 ( V_7 -> V_14 ) ;
RETURN ( 0 ) ;
}
int F_6 ( void * V_3 , void * V_7 , int V_19 )
{
if ( F_7 ( ( char * ) V_3 , V_7 , V_19 ) )
return - V_20 ;
return 0 ;
}
static int
F_8 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_23 * * V_24 = NULL ;
int V_25 = 0 ;
if ( ! V_21 )
return ( - V_12 ) ;
V_24 = (struct V_23 * * ) & V_22 -> V_26 ;
if ( V_27 . V_28 != NULL )
V_25 = V_27 . V_28 ( 0 , ( void * ) V_24 ) ;
else
return ( - V_29 ) ;
return V_25 ;
}
static int
F_9 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_23 * V_24 ;
int V_25 = 0 ;
if ( ! V_21 )
return ( - V_12 ) ;
V_24 = V_22 -> V_26 ;
if ( V_27 . V_30 != NULL )
V_25 = V_27 . V_30 ( 0 , ( void * ) V_24 ) ;
else
V_25 = - V_29 ;
return V_25 ;
}
static long F_10 ( struct V_22 * V_22 ,
unsigned int V_31 , unsigned long V_3 )
{
struct V_32 V_33 ;
int V_25 = 0 ;
if ( F_11 () != 0 )
return - V_34 ;
if ( F_12 ( V_31 ) != V_35 ||
F_13 ( V_31 ) < V_36 ||
F_13 ( V_31 ) > V_37 ) {
F_14 ( V_38 , L_5 ,
F_12 ( V_31 ) , F_13 ( V_31 ) , F_15 ( V_31 ) ) ;
return ( - V_12 ) ;
}
switch ( V_31 ) {
case V_39 :
if ( ! F_16 ( V_40 ) )
return ( - V_29 ) ;
F_17 ( L_6 ) ;
return ( 0 ) ;
case V_41 :
if ( ! F_16 ( V_42 ) )
return - V_29 ;
}
V_33 . V_43 = 0 ;
V_33 . V_26 = V_22 -> V_26 ;
if ( V_27 . V_44 != NULL )
V_25 = V_27 . V_44 ( & V_33 , V_31 , ( void * ) V_3 ) ;
else
V_25 = - V_29 ;
return ( V_25 ) ;
}
