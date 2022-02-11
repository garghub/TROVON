int F_1 ( struct V_1 * V_2 ,
T_1 (* F_2)( int V_3 , void * V_4 ) ,
T_1 (* F_3)( int V_3 , void * V_4 ) ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_4 () ;
if ( ! V_8 ) {
V_9 = - V_10 ;
goto V_11;
}
F_5 ( V_2 , V_8 ) ;
V_2 -> V_12 = F_6 ( F_2 ,
F_3 ,
V_13 ,
V_2 ,
L_1 ,
V_2 -> V_14 ,
V_2 -> V_15 ) ;
if ( V_2 -> V_12 == NULL ) {
V_9 = - V_10 ;
goto V_16;
}
if ( V_6 )
V_2 -> V_6 = V_6 ;
else
V_2 -> V_6 = & V_17 ;
V_2 -> V_18 |= V_19 ;
return 0 ;
V_16:
F_7 ( V_2 -> V_8 ) ;
V_11:
return V_9 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
F_7 ( V_2 -> V_8 ) ;
}
static void F_10 ( struct V_20 * V_21 , void * V_22 )
{
F_8 ( * (struct V_1 * * ) V_22 ) ;
}
int F_11 ( struct V_20 * V_21 ,
struct V_1 * V_2 ,
T_1 (* F_2)( int V_3 , void * V_4 ) ,
T_1 (* F_3)( int V_3 , void * V_4 ) ,
const struct V_5 * V_23 )
{
struct V_1 * * V_24 ;
int V_9 ;
V_24 = F_12 ( F_10 , sizeof( * V_24 ) ,
V_25 ) ;
if ( ! V_24 )
return - V_10 ;
* V_24 = V_2 ;
V_9 = F_1 ( V_2 , F_2 , F_3 , V_23 ) ;
if ( ! V_9 )
F_13 ( V_21 , V_24 ) ;
else
F_14 ( V_24 ) ;
return V_9 ;
}
void F_15 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_16 ( V_21 , F_10 ,
V_27 , V_2 ) ;
F_17 ( V_26 ) ;
}
