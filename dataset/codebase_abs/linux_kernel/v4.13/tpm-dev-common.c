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
void F_10 ( struct V_10 * V_10 , struct V_11 * V_12 ,
struct V_2 * V_3 )
{
V_3 -> V_12 = V_12 ;
F_8 ( & V_3 -> V_8 , 0 ) ;
F_11 ( & V_3 -> V_7 ) ;
F_12 ( & V_3 -> V_13 , F_1 ,
( unsigned long ) V_3 ) ;
F_13 ( & V_3 -> V_5 , F_5 ) ;
V_10 -> V_14 = V_3 ;
}
T_1 F_14 ( struct V_10 * V_10 , char T_2 * V_15 ,
T_3 V_16 , T_4 * V_17 )
{
struct V_2 * V_3 = V_10 -> V_14 ;
T_1 V_18 ;
T_1 V_19 ;
int V_20 ;
F_15 ( & V_3 -> V_13 ) ;
F_16 ( & V_3 -> V_5 ) ;
V_18 = F_17 ( & V_3 -> V_8 ) ;
if ( V_18 > 0 ) {
V_19 = V_18 ;
if ( V_16 < V_18 )
V_18 = V_16 ;
F_7 ( & V_3 -> V_7 ) ;
V_20 = F_18 ( V_15 , V_3 -> V_9 , V_18 ) ;
memset ( V_3 -> V_9 , 0 , V_19 ) ;
if ( V_20 )
V_18 = - V_21 ;
F_9 ( & V_3 -> V_7 ) ;
}
F_8 ( & V_3 -> V_8 , 0 ) ;
return V_18 ;
}
T_1 F_19 ( struct V_10 * V_10 , const char T_2 * V_15 ,
T_3 V_16 , T_4 * V_17 , struct V_22 * V_23 )
{
struct V_2 * V_3 = V_10 -> V_14 ;
T_3 V_24 = V_16 ;
T_1 V_25 ;
if ( F_17 ( & V_3 -> V_8 ) != 0 )
return - V_26 ;
if ( V_24 > V_27 )
return - V_28 ;
F_7 ( & V_3 -> V_7 ) ;
if ( F_20
( V_3 -> V_9 , ( void T_2 * ) V_15 , V_24 ) ) {
F_9 ( & V_3 -> V_7 ) ;
return - V_21 ;
}
if ( F_21 ( V_3 -> V_12 ) ) {
F_9 ( & V_3 -> V_7 ) ;
return - V_29 ;
}
V_25 = F_22 ( V_3 -> V_12 , V_23 , V_3 -> V_9 ,
sizeof( V_3 -> V_9 ) , 0 ) ;
F_23 ( V_3 -> V_12 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_3 -> V_7 ) ;
return V_25 ;
}
F_8 ( & V_3 -> V_8 , V_25 ) ;
F_9 ( & V_3 -> V_7 ) ;
F_24 ( & V_3 -> V_13 , V_30 + ( 120 * V_31 ) ) ;
return V_24 ;
}
void F_25 ( struct V_10 * V_10 , struct V_2 * V_3 )
{
F_15 ( & V_3 -> V_13 ) ;
F_16 ( & V_3 -> V_5 ) ;
V_10 -> V_14 = NULL ;
F_8 ( & V_3 -> V_8 , 0 ) ;
}
