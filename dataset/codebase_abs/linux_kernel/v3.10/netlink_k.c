static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
void * V_8 ;
int V_9 ;
if ( V_2 -> V_10 >= V_11 ) {
V_4 = (struct V_3 * ) V_2 -> V_12 ;
if ( V_2 -> V_10 < V_4 -> V_13 ||
V_4 -> V_13 > V_14 ) {
F_2 ( V_2 -> V_6 , L_1 ,
V_2 -> V_10 , V_4 -> V_13 ) ;
return;
}
memcpy ( & V_9 , F_3 ( V_4 ) , V_15 ) ;
V_8 = F_4 ( V_4 ) ;
V_7 = F_5 ( V_4 ) ;
if ( V_16 ) {
V_6 = F_6 ( & V_17 , V_9 ) ;
if ( V_6 ) {
V_16 ( V_6 , V_4 -> V_18 , V_8 , V_7 ) ;
F_7 ( V_6 ) ;
} else
F_2 ( V_2 -> V_6 ,
L_2 ,
V_9 ) ;
} else
F_2 ( V_2 -> V_6 , L_3 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_19 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_19 ) ;
}
struct V_20 * F_11 ( int V_21 , void (* F_12)( struct V_5 * V_6 , T_2 type ,
void * V_8 , int V_10 ) )
{
struct V_20 * V_20 ;
struct V_22 V_23 = {
. V_24 = F_8 ,
} ;
#if ! F_13 ( V_25 )
F_14 ( & V_19 ) ;
#endif
V_20 = F_15 ( & V_17 , V_21 , & V_23 ) ;
if ( V_20 )
V_16 = F_12 ;
return V_20 ;
}
void F_16 ( struct V_20 * V_20 )
{
F_17 ( V_20 ) ;
}
int F_18 ( struct V_20 * V_20 , int V_26 , T_2 type , void * V_8 , int V_10 )
{
static T_1 V_27 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_28 = 0 ;
if ( V_26 > V_29 ) {
F_19 ( L_4 , V_26 ) ;
F_19 ( L_5 , V_29 ) ;
return - V_30 ;
}
V_2 = F_20 ( V_10 , V_31 ) ;
if ( ! V_2 ) {
F_19 ( L_6 , V_28 ) ;
return - V_32 ;
}
V_27 ++ ;
V_4 = F_21 ( V_2 , 0 , V_27 , type , V_10 , 0 ) ;
if ( ! V_4 ) {
F_22 ( V_2 ) ;
return - V_33 ;
}
memcpy ( F_23 ( V_4 ) , V_8 , V_10 ) ;
F_24 ( V_2 ) . V_34 = 0 ;
F_24 ( V_2 ) . V_35 = 0 ;
V_28 = F_25 ( V_20 , V_2 , 0 , V_26 + 1 , V_31 ) ;
if ( ! V_28 )
return V_10 ;
else {
if ( V_28 != - V_36 ) {
F_19 ( L_7 ,
V_26 , type , V_10 , V_28 ) ;
}
V_28 = 0 ;
}
return V_28 ;
}
