static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
void * V_8 ;
int V_9 ;
if ( V_2 -> V_10 >= F_2 ( 0 ) ) {
V_4 = (struct V_3 * ) V_2 -> V_11 ;
if ( V_2 -> V_10 < V_4 -> V_12 ||
V_4 -> V_12 > V_13 ) {
F_3 ( V_14 L_1 , V_2 -> V_10 ,
V_4 -> V_12 ) ;
return;
}
memcpy ( & V_9 , F_4 ( V_4 ) , V_15 ) ;
V_8 = F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 ) ;
if ( V_16 ) {
V_6 = F_7 ( & V_17 , V_9 ) ;
if ( V_6 ) {
V_16 ( V_6 , V_4 -> V_18 , V_8 , V_7 ) ;
F_8 ( V_6 ) ;
} else
F_3 ( V_14 L_2
L_3 , V_9 ) ;
} else
F_3 ( V_14 L_4 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_19 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_19 ) ;
}
struct V_20 * F_12 ( int V_21 , void (* F_13)( struct V_5 * V_6 , T_2 type ,
void * V_8 , int V_10 ) )
{
struct V_20 * V_20 ;
struct V_22 V_23 = {
. V_24 = F_9 ,
} ;
#if ! F_14 ( V_25 )
F_15 ( & V_19 ) ;
#endif
V_20 = F_16 ( & V_17 , V_21 , V_26 , & V_23 ) ;
if ( V_20 )
V_16 = F_13 ;
return V_20 ;
}
void F_17 ( struct V_20 * V_20 )
{
F_18 ( V_20 ) ;
}
int F_19 ( struct V_20 * V_20 , int V_27 , T_2 type , void * V_8 , int V_10 )
{
static T_1 V_28 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_29 = 0 ;
if ( V_27 > V_30 ) {
F_3 ( V_14 L_5 , V_27 ) ;
F_3 ( V_14 L_6 , V_30 ) ;
return - V_31 ;
}
V_2 = F_20 ( F_2 ( V_10 ) , V_32 ) ;
if ( ! V_2 ) {
F_3 ( V_14 L_7 , V_29 ) ;
return - V_33 ;
}
V_28 ++ ;
V_4 = F_21 ( V_2 , 0 , V_28 , type , V_10 , 0 ) ;
if ( ! V_4 ) {
F_22 ( V_2 ) ;
return - V_34 ;
}
memcpy ( F_23 ( V_4 ) , V_8 , V_10 ) ;
F_24 ( V_2 ) . V_35 = 0 ;
F_24 ( V_2 ) . V_36 = 0 ;
V_29 = F_25 ( V_20 , V_2 , 0 , V_27 + 1 , V_32 ) ;
if ( ! V_29 )
return V_10 ;
else {
if ( V_29 != - V_37 ) {
F_3 ( V_14 L_8 ,
V_27 , type , V_10 , V_29 ) ;
}
V_29 = 0 ;
}
return V_29 ;
}
