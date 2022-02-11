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
if ( V_2 -> V_11 < V_12 ) {
F_2 ( L_2 ) ;
return;
}
V_4 = (struct V_3 * ) V_2 -> V_13 ;
if ( V_2 -> V_11 < V_4 -> V_14 || V_4 -> V_14 > V_15 ) {
F_2 ( L_3 ,
V_2 -> V_11 , V_4 -> V_14 ) ;
return;
}
memcpy ( & V_9 , F_3 ( V_4 ) , V_16 ) ;
V_8 = F_4 ( V_4 ) ;
V_7 = F_5 ( V_4 ) ;
V_6 = F_6 ( & V_17 , V_9 ) ;
if ( V_6 ) {
V_10 ( V_6 , V_4 -> V_18 , V_8 , V_7 ) ;
F_7 ( V_6 ) ;
} else {
F_2 ( L_4 , V_9 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_19 ) ;
F_1 ( V_2 ) ;
F_10 ( & V_19 ) ;
}
struct V_20 * F_11 ( int V_21 ,
void (* F_12)( struct V_5 * V_6 , T_2 type , void * V_8 , int V_11 ) )
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
V_10 = F_12 ;
return V_20 ;
}
void F_16 ( struct V_20 * V_20 )
{
F_17 ( V_20 -> V_26 ) ;
}
int F_18 ( struct V_20 * V_20 , int V_27 , T_2 type , void * V_8 , int V_11 )
{
static T_1 V_28 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_29 = 0 ;
if ( V_27 > V_30 )
return - V_31 ;
if ( ! F_19 ( V_20 , V_27 + 1 ) )
return - V_32 ;
V_2 = F_20 ( F_21 ( V_11 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_28 ++ ;
V_4 = F_22 ( V_2 , 0 , V_28 , type , V_11 , 0 ) ;
memcpy ( F_23 ( V_4 ) , V_8 , V_11 ) ;
F_24 ( V_2 ) . V_35 = 0 ;
F_24 ( V_2 ) . V_36 = 0 ;
V_29 = F_25 ( V_20 , V_2 , 0 , V_27 + 1 , V_33 ) ;
if ( ! V_29 )
return V_11 ;
if ( V_29 != - V_32 )
F_2 ( L_5 ,
V_27 , type , V_11 , V_29 ) ;
else if ( F_19 ( V_20 , V_27 + 1 ) )
return - V_37 ;
return V_29 ;
}
