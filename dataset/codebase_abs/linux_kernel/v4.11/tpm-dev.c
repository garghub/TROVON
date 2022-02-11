static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_1 ,
F_3 ( V_4 ) ) ;
F_4 ( & V_3 -> V_5 ) ;
}
static void F_5 ( struct V_6 * V_5 )
{
struct V_2 * V_3 = F_6 ( V_5 , struct V_2 , V_5 ) ;
F_7 ( & V_3 -> V_7 ) ;
F_8 ( & V_3 -> V_8 , 0 ) ;
memset ( V_3 -> V_9 , 0 , sizeof( V_3 -> V_9 ) ) ;
F_9 ( & V_3 -> V_7 ) ;
}
static int F_10 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
struct V_12 * V_13 =
F_6 ( V_10 -> V_14 , struct V_12 , V_15 ) ;
struct V_2 * V_3 ;
if ( F_11 ( 0 , & V_13 -> V_16 ) ) {
F_12 ( & V_13 -> V_17 , L_2 ) ;
return - V_18 ;
}
V_3 = F_13 ( sizeof( * V_3 ) , V_19 ) ;
if ( V_3 == NULL ) {
F_14 ( 0 , & V_13 -> V_16 ) ;
return - V_20 ;
}
V_3 -> V_13 = V_13 ;
F_8 ( & V_3 -> V_8 , 0 ) ;
F_15 ( & V_3 -> V_7 ) ;
F_16 ( & V_3 -> V_21 , F_1 ,
( unsigned long ) V_3 ) ;
F_17 ( & V_3 -> V_5 , F_5 ) ;
V_11 -> V_22 = V_3 ;
return 0 ;
}
static T_1 F_18 ( struct V_11 * V_11 , char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
struct V_2 * V_3 = V_11 -> V_22 ;
T_1 V_26 ;
int V_27 ;
F_19 ( & V_3 -> V_21 ) ;
F_20 ( & V_3 -> V_5 ) ;
V_26 = F_21 ( & V_3 -> V_8 ) ;
if ( V_26 > 0 ) {
T_1 V_28 = V_26 ;
if ( V_24 < V_26 )
V_26 = V_24 ;
F_7 ( & V_3 -> V_7 ) ;
V_27 = F_22 ( V_23 , V_3 -> V_9 , V_26 ) ;
memset ( V_3 -> V_9 , 0 , V_28 ) ;
if ( V_27 )
V_26 = - V_29 ;
F_9 ( & V_3 -> V_7 ) ;
}
F_8 ( & V_3 -> V_8 , 0 ) ;
return V_26 ;
}
static T_1 F_23 ( struct V_11 * V_11 , const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
struct V_2 * V_3 = V_11 -> V_22 ;
T_3 V_30 = V_24 ;
T_1 V_31 ;
if ( F_21 ( & V_3 -> V_8 ) != 0 )
return - V_18 ;
if ( V_30 > V_32 )
return - V_33 ;
F_7 ( & V_3 -> V_7 ) ;
if ( F_24
( V_3 -> V_9 , ( void T_2 * ) V_23 , V_30 ) ) {
F_9 ( & V_3 -> V_7 ) ;
return - V_29 ;
}
if ( F_25 ( V_3 -> V_13 ) ) {
F_9 ( & V_3 -> V_7 ) ;
return - V_34 ;
}
V_31 = F_26 ( V_3 -> V_13 , V_3 -> V_9 ,
sizeof( V_3 -> V_9 ) , 0 ) ;
F_27 ( V_3 -> V_13 ) ;
if ( V_31 < 0 ) {
F_9 ( & V_3 -> V_7 ) ;
return V_31 ;
}
F_8 ( & V_3 -> V_8 , V_31 ) ;
F_9 ( & V_3 -> V_7 ) ;
F_28 ( & V_3 -> V_21 , V_35 + ( 120 * V_36 ) ) ;
return V_30 ;
}
static int F_29 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_22 ;
F_19 ( & V_3 -> V_21 ) ;
F_20 ( & V_3 -> V_5 ) ;
V_11 -> V_22 = NULL ;
F_8 ( & V_3 -> V_8 , 0 ) ;
F_14 ( 0 , & V_3 -> V_13 -> V_16 ) ;
F_30 ( V_3 ) ;
return 0 ;
}
