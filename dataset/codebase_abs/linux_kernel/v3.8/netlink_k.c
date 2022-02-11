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
F_3 ( V_2 -> V_6 , L_1 ,
V_2 -> V_10 , V_4 -> V_12 ) ;
return;
}
memcpy ( & V_9 , F_4 ( V_4 ) , V_14 ) ;
V_8 = F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 ) ;
if ( V_15 ) {
V_6 = F_7 ( & V_16 , V_9 ) ;
if ( V_6 ) {
V_15 ( V_6 , V_4 -> V_17 , V_8 , V_7 ) ;
F_8 ( V_6 ) ;
} else
F_3 ( V_2 -> V_6 ,
L_2 ,
V_9 ) ;
} else
F_3 ( V_2 -> V_6 , L_3 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_18 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_18 ) ;
}
struct V_19 * F_12 ( int V_20 , void (* F_13)( struct V_5 * V_6 , T_2 type ,
void * V_8 , int V_10 ) )
{
struct V_19 * V_19 ;
struct V_21 V_22 = {
. V_23 = F_9 ,
} ;
#if ! F_14 ( V_24 )
F_15 ( & V_18 ) ;
#endif
V_19 = F_16 ( & V_16 , V_20 , & V_22 ) ;
if ( V_19 )
V_15 = F_13 ;
return V_19 ;
}
void F_17 ( struct V_19 * V_19 )
{
F_18 ( V_19 ) ;
}
int F_19 ( struct V_19 * V_19 , int V_25 , T_2 type , void * V_8 , int V_10 )
{
static T_1 V_26 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( V_25 > V_28 ) {
F_20 ( L_4 , V_25 ) ;
F_20 ( L_5 , V_28 ) ;
return - V_29 ;
}
V_2 = F_21 ( F_2 ( V_10 ) , V_30 ) ;
if ( ! V_2 ) {
F_20 ( L_6 , V_27 ) ;
return - V_31 ;
}
V_26 ++ ;
V_4 = F_22 ( V_2 , 0 , V_26 , type , V_10 , 0 ) ;
if ( ! V_4 ) {
F_23 ( V_2 ) ;
return - V_32 ;
}
memcpy ( F_24 ( V_4 ) , V_8 , V_10 ) ;
F_25 ( V_2 ) . V_33 = 0 ;
F_25 ( V_2 ) . V_34 = 0 ;
V_27 = F_26 ( V_19 , V_2 , 0 , V_25 + 1 , V_30 ) ;
if ( ! V_27 )
return V_10 ;
else {
if ( V_27 != - V_35 ) {
F_20 ( L_7 ,
V_25 , type , V_10 , V_27 ) ;
}
V_27 = 0 ;
}
return V_27 ;
}
