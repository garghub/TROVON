static void F_1 ( int V_1 )
{
if ( V_1 ) {
F_2 ( V_2 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 0 ) ;
F_5 ( NULL , V_3 , NULL , NULL ) ;
}
else {
F_2 ( F_4 ( 1 ) , 1 ) ;
F_3 ( 10 ) ;
F_2 ( F_4 ( 1 ) , 0 ) ;
F_3 ( 10 ) ;
F_2 ( V_2 , 0 ) ;
F_5 ( NULL , V_4 , NULL , NULL ) ;
}
}
static int F_6 ( void * V_5 , bool V_6 )
{
F_1 ( ! V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 = 0 ;
V_11 = F_8 ( F_4 ( 1 ) , F_9 ( & V_8 -> V_12 ) ) ;
if ( V_11 ) {
F_10 ( & V_8 -> V_12 , L_1 ) ;
return V_11 ;
}
V_11 = F_8 ( V_2 , F_9 ( & V_8 -> V_12 ) ) ;
if ( V_11 ) {
F_11 ( F_4 ( 1 ) ) ;
F_10 ( & V_8 -> V_12 , L_2 ) ;
return V_11 ;
}
F_12 ( F_4 ( 0 ) , V_13 ) ;
F_13 ( F_4 ( 0 ) , V_14 ) ;
F_12 ( F_4 ( 1 ) , V_15 ) ;
F_13 ( F_4 ( 1 ) , V_14 ) ;
F_12 ( F_4 ( 2 ) , V_16 ) ;
F_13 ( F_4 ( 2 ) , V_14 ) ;
F_12 ( F_4 ( 3 ) , V_17 ) ;
F_13 ( F_4 ( 3 ) , V_14 ) ;
V_10 = F_14 ( V_18 , & V_8 -> V_12 , V_19 ,
& V_20 , NULL ) ;
if ( ! V_10 ) {
V_11 = - V_21 ;
goto V_22;
}
V_11 = F_15 ( V_10 ) ;
if ( V_11 )
goto V_23;
F_16 ( V_8 , V_10 ) ;
return 0 ;
V_23:
F_17 ( V_10 ) ;
V_22:
return V_11 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_19 ( V_8 ) ;
F_16 ( V_8 , NULL ) ;
F_11 ( F_4 ( 1 ) ) ;
if ( V_10 ) {
F_20 ( V_10 ) ;
F_17 ( V_10 ) ;
}
V_10 = NULL ;
F_1 ( 0 ) ;
return 0 ;
}
