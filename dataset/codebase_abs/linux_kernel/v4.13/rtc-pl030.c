static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( 0 , V_4 -> V_5 + V_6 ) ;
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
F_5 ( F_6 ( V_4 -> V_5 + V_12 ) , & V_11 -> time ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
unsigned long time ;
int V_13 ;
V_13 = F_8 ( & V_11 -> time ) ;
if ( V_13 == 0 )
V_13 = F_9 ( & V_11 -> time , & time ) ;
if ( V_13 == 0 )
F_2 ( time , V_4 -> V_5 + V_12 ) ;
return V_13 ;
}
static int F_10 ( struct V_8 * V_9 , struct V_14 * V_15 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
F_5 ( F_6 ( V_4 -> V_5 + V_16 ) , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , struct V_14 * V_15 )
{
struct V_3 * V_4 = F_4 ( V_9 ) ;
unsigned long time ;
int V_13 ;
V_13 = F_9 ( V_15 , & time ) ;
if ( V_13 == 0 )
F_2 ( time + 1 , V_4 -> V_5 + V_17 ) ;
return V_13 ;
}
static int F_12 ( struct V_18 * V_9 , const struct V_19 * V_20 )
{
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_13 ( V_9 , NULL ) ;
if ( V_13 )
goto V_21;
V_4 = F_14 ( & V_9 -> V_9 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 ) {
V_13 = - V_23 ;
goto V_24;
}
V_4 -> V_5 = F_15 ( V_9 -> V_25 . V_26 , F_16 ( & V_9 -> V_25 ) ) ;
if ( ! V_4 -> V_5 ) {
V_13 = - V_23 ;
goto V_24;
}
F_17 ( 0 , V_4 -> V_5 + V_27 ) ;
F_17 ( 0 , V_4 -> V_5 + V_6 ) ;
F_18 ( V_9 , V_4 ) ;
V_13 = F_19 ( V_9 -> V_1 [ 0 ] , F_1 , 0 ,
L_1 , V_4 ) ;
if ( V_13 )
goto V_28;
V_4 -> V_4 = F_20 ( L_2 , & V_9 -> V_9 , & V_29 ,
V_30 ) ;
if ( F_21 ( V_4 -> V_4 ) ) {
V_13 = F_22 ( V_4 -> V_4 ) ;
goto V_31;
}
return 0 ;
V_31:
F_23 ( V_9 -> V_1 [ 0 ] , V_4 ) ;
V_28:
F_24 ( V_4 -> V_5 ) ;
V_24:
F_25 ( V_9 ) ;
V_21:
return V_13 ;
}
static int F_26 ( struct V_18 * V_9 )
{
struct V_3 * V_4 = F_27 ( V_9 ) ;
F_2 ( 0 , V_4 -> V_5 + V_27 ) ;
F_23 ( V_9 -> V_1 [ 0 ] , V_4 ) ;
F_28 ( V_4 -> V_4 ) ;
F_24 ( V_4 -> V_5 ) ;
F_25 ( V_9 ) ;
return 0 ;
}
