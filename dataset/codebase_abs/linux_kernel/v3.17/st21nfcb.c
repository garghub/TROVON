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
int F_12 ( struct V_13 * V_8 , int V_14 ,
int V_15 )
{
struct V_3 * V_4 ;
int V_5 ;
T_1 V_16 ;
V_4 = F_13 ( V_8 -> V_11 ,
sizeof( struct V_3 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_16 = V_19
| V_20
| V_21
| V_22
| V_23
| V_24 ;
V_8 -> V_2 = F_14 ( & V_25 , V_16 ,
V_14 , V_15 ) ;
if ( ! V_8 -> V_2 ) {
F_15 ( L_1 ) ;
V_5 = - V_18 ;
goto V_26;
}
V_4 -> V_8 = V_8 ;
F_16 ( V_8 -> V_2 , V_4 ) ;
V_5 = F_17 ( V_8 -> V_2 ) ;
if ( V_5 )
goto V_27;
return V_5 ;
V_27:
F_18 ( V_8 -> V_2 ) ;
V_26:
F_19 ( V_4 ) ;
return V_5 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_4 ) ;
}
