static void F_1 ( int V_1 )
{
if ( V_1 ) {
F_2 ( V_2 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 0 ) ;
F_5 ( - V_3 , V_4 , NULL , NULL ) ;
}
else {
F_2 ( F_4 ( 1 ) , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_2 , 0 ) ;
F_5 ( - V_3 , V_5 , NULL , NULL ) ;
}
}
static int F_6 ( void * V_6 , bool V_7 )
{
F_1 ( ! V_7 ) ;
return 0 ;
}
static int T_1 F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_12 = 0 ;
V_12 = F_8 ( F_4 ( 1 ) , F_9 ( & V_9 -> V_13 ) ) ;
if ( V_12 ) {
F_10 ( & V_9 -> V_13 , L_1 ) ;
return V_12 ;
}
V_12 = F_8 ( V_2 , F_9 ( & V_9 -> V_13 ) ) ;
if ( V_12 ) {
F_11 ( F_4 ( 1 ) ) ;
F_10 ( & V_9 -> V_13 , L_2 ) ;
return V_12 ;
}
F_12 ( F_4 ( 0 ) , V_14 ) ;
F_13 ( F_4 ( 0 ) , V_15 ) ;
F_12 ( F_4 ( 1 ) , V_16 ) ;
F_13 ( F_4 ( 1 ) , V_15 ) ;
F_12 ( F_4 ( 2 ) , V_17 ) ;
F_13 ( F_4 ( 2 ) , V_15 ) ;
F_12 ( F_4 ( 3 ) , V_18 ) ;
F_13 ( F_4 ( 3 ) , V_15 ) ;
V_11 = F_14 ( V_19 , & V_9 -> V_13 , V_20 ,
& V_21 , NULL ) ;
if ( ! V_11 ) {
V_12 = - V_22 ;
goto V_23;
}
V_12 = F_15 ( V_11 ) ;
if ( V_12 )
goto V_24;
F_16 ( V_9 , V_11 ) ;
return 0 ;
V_24:
F_17 ( V_11 ) ;
V_23:
return V_12 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_19 ( V_9 ) ;
F_16 ( V_9 , NULL ) ;
F_11 ( F_4 ( 1 ) ) ;
if ( V_11 ) {
F_20 ( V_11 ) ;
F_17 ( V_11 ) ;
}
V_11 = NULL ;
F_1 ( 0 ) ;
return 0 ;
}
