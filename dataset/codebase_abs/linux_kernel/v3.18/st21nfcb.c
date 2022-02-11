static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( F_3 ( V_6 , & V_4 -> V_7 ) )
return 0 ;
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( V_5 )
F_5 ( V_6 , & V_4 -> V_7 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_6 , & V_4 -> V_7 ) )
return 0 ;
F_8 ( V_4 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_10 -> V_11 = ( void * ) V_2 ;
if ( ! F_10 ( V_6 , & V_4 -> V_7 ) )
return - V_12 ;
return F_11 ( V_4 -> V_8 , V_10 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
T_2 V_13 )
{
return V_13 == V_14 ?
V_15 : 0 ;
}
int F_13 ( struct V_16 * V_8 , int V_17 ,
int V_18 )
{
struct V_3 * V_4 ;
int V_5 ;
T_3 V_19 ;
V_4 = F_14 ( V_8 -> V_11 ,
sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_19 = V_22
| V_23
| V_24
| V_25
| V_26
| V_15
| V_27 ;
V_8 -> V_2 = F_15 ( & V_28 , V_19 ,
V_17 , V_18 ) ;
if ( ! V_8 -> V_2 ) {
F_16 ( L_1 ) ;
return - V_21 ;
}
V_4 -> V_8 = V_8 ;
F_17 ( V_8 -> V_2 , V_4 ) ;
V_5 = F_18 ( V_8 -> V_2 ) ;
if ( V_5 ) {
F_16 ( L_2 ) ;
F_19 ( V_8 -> V_2 ) ;
}
return V_5 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_19 ( V_2 ) ;
F_22 ( V_4 ) ;
}
