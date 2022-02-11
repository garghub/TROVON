int F_1 ( char * V_1 , char * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = (struct V_4 * ) V_1 ;
V_7 = (struct V_6 * ) V_1 ;
if ( F_2 ( V_1 , V_3 , sizeof( * V_5 ) ) )
return - V_9 ;
if ( V_5 -> V_10 != V_11 ) {
F_3 ( L_1 ) ;
return - V_12 ;
}
if ( V_5 -> V_13 >= V_2 - V_1 ) {
F_3 ( L_2 ) ;
return - V_12 ;
}
if ( V_5 -> V_13 < sizeof( struct V_6 ) ) {
F_3 ( L_3 ) ;
return - V_12 ;
}
V_8 = V_5 -> V_13 ;
if ( F_2 ( V_1 , V_3 , V_5 -> V_13 ) )
return - V_9 ;
if ( V_8 != V_7 -> V_13 )
return - V_12 ;
if ( F_4 ( V_7 ) ) {
F_3 ( L_4 ) ;
return - V_12 ;
}
if ( V_7 -> V_14 )
V_7 -> V_15 = & V_7 -> V_16 [ 0 ] ;
if ( V_7 -> V_17 )
V_7 -> V_18 = & V_7 -> V_16 [ 0 ] +
F_5 ( V_7 -> V_14 ) ;
return 0 ;
}
int F_6 ( void * V_3 , void * V_7 , int V_19 )
{
if ( F_7 ( ( char * ) V_3 , V_7 , V_19 ) )
return - V_9 ;
return 0 ;
}
static int
F_8 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_22 * * V_23 = NULL ;
int V_24 = 0 ;
if ( ! V_20 )
return - V_12 ;
V_23 = (struct V_22 * * ) & V_21 -> V_25 ;
if ( V_26 . V_27 != NULL )
V_24 = V_26 . V_27 ( 0 , ( void * ) V_23 ) ;
else
return - V_28 ;
return V_24 ;
}
static int
F_9 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_22 * V_23 ;
int V_24 = 0 ;
if ( ! V_20 )
return - V_12 ;
V_23 = V_21 -> V_25 ;
if ( V_26 . V_29 != NULL )
V_24 = V_26 . V_29 ( 0 , ( void * ) V_23 ) ;
else
V_24 = - V_28 ;
return V_24 ;
}
static long F_10 ( struct V_21 * V_21 ,
unsigned int V_30 , unsigned long V_3 )
{
struct V_31 V_32 ;
int V_24 = 0 ;
if ( ! F_11 ( V_33 ) )
return - V_34 ;
if ( F_12 ( V_30 ) != V_35 ||
F_13 ( V_30 ) < V_36 ||
F_13 ( V_30 ) > V_37 ) {
F_14 ( V_38 , L_5 ,
F_12 ( V_30 ) , F_13 ( V_30 ) , F_15 ( V_30 ) ) ;
return - V_12 ;
}
switch ( V_30 ) {
case V_39 :
if ( ! F_11 ( V_40 ) )
return - V_28 ;
F_16 ( L_6 ) ;
return 0 ;
case V_41 :
if ( ! F_11 ( V_42 ) )
return - V_28 ;
}
V_32 . V_43 = 0 ;
V_32 . V_25 = V_21 -> V_25 ;
if ( V_26 . V_44 != NULL )
V_24 = V_26 . V_44 ( & V_32 , V_30 , ( void * ) V_3 ) ;
else
V_24 = - V_28 ;
return V_24 ;
}
