static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
void * V_8 ;
int V_9 ;
if ( ! V_10 ) {
F_2 ( L_1 ) ;
return;
}
if ( V_2 -> V_11 < F_3 ( 0 ) ) {
F_2 ( L_2 ) ;
return;
}
V_4 = (struct V_3 * ) V_2 -> V_12 ;
if ( V_2 -> V_11 < V_4 -> V_13 || V_4 -> V_13 > V_14 ) {
F_2 ( L_3 ,
V_2 -> V_11 , V_4 -> V_13 ) ;
return;
}
memcpy ( & V_9 , F_4 ( V_4 ) , V_15 ) ;
V_8 = F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 ) ;
V_6 = F_7 ( & V_16 , V_9 ) ;
if ( V_6 ) {
V_10 ( V_6 , V_4 -> V_17 , V_8 , V_7 ) ;
F_8 ( V_6 ) ;
} else {
F_2 ( L_4 , V_9 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_18 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_18 ) ;
}
struct V_19 * F_12 ( int V_20 ,
void (* F_13)( struct V_5 * V_6 , T_2 type , void * V_8 , int V_11 ) )
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
V_10 = F_13 ;
return V_19 ;
}
void F_17 ( struct V_19 * V_19 )
{
F_18 ( V_19 -> V_25 ) ;
}
int F_19 ( struct V_19 * V_19 , int V_26 , T_2 type , void * V_8 , int V_11 )
{
static T_1 V_27 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_28 = 0 ;
if ( V_26 > V_29 )
return - V_30 ;
if ( ! F_20 ( V_19 , V_26 + 1 ) )
return - V_31 ;
V_2 = F_21 ( F_3 ( V_11 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_27 ++ ;
V_4 = F_22 ( V_2 , 0 , V_27 , type , V_11 , 0 ) ;
memcpy ( F_23 ( V_4 ) , V_8 , V_11 ) ;
F_24 ( V_2 ) . V_34 = 0 ;
F_24 ( V_2 ) . V_35 = 0 ;
V_28 = F_25 ( V_19 , V_2 , 0 , V_26 + 1 , V_32 ) ;
if ( ! V_28 )
return V_11 ;
if ( V_28 != - V_31 )
F_2 ( L_5 ,
V_26 , type , V_11 , V_28 ) ;
else if ( F_20 ( V_19 , V_26 + 1 ) )
return - V_36 ;
return V_28 ;
}
