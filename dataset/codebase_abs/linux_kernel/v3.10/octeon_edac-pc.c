static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
unsigned int V_8 = F_3 () ;
unsigned int V_9 = F_4 () ;
T_1 V_10 = F_5 () ;
T_1 V_11 ;
if ( V_3 ) {
V_11 = V_12 [ V_8 ] ;
V_12 [ V_8 ] = 0 ;
} else {
V_11 = F_6 () ;
}
if ( V_10 & 1 ) {
F_7 ( V_6 -> V_13 , V_14 ,
L_1 ,
( unsigned long long ) V_10 , V_8 , V_9 ,
F_8 () ) ;
F_9 ( 0 ) ;
F_10 ( V_6 -> V_13 , V_9 , 1 , L_2 ) ;
}
if ( V_11 & 1 ) {
F_7 ( V_6 -> V_13 , V_14 ,
L_3 ,
( unsigned long long ) V_11 , V_8 , V_9 ,
F_8 () ) ;
if ( V_3 )
F_11 ( V_6 -> V_13 , V_9 , 0 , L_4 ) ;
else
F_10 ( V_6 -> V_13 , V_9 , 0 , L_4 ) ;
if ( F_12 ( V_15 ) )
F_13 ( 1 ) ;
else
F_13 ( 0 ) ;
}
return V_16 ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_15 ( & V_18 -> V_19 , sizeof( * V_6 ) ,
V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_7 . V_22 = F_1 ;
F_16 ( V_18 , V_6 ) ;
V_6 -> V_13 = F_17 ( 0 , L_5 , F_18 () ,
L_6 , 2 , 0 , NULL , 0 ,
F_19 () ) ;
if ( ! V_6 -> V_13 )
goto V_23;
V_6 -> V_13 -> V_19 = & V_18 -> V_19 ;
V_6 -> V_13 -> V_24 = V_24 ( & V_18 -> V_19 ) ;
V_6 -> V_13 -> V_25 = L_7 ;
V_6 -> V_13 -> V_26 = L_6 ;
if ( F_20 ( V_6 -> V_13 ) ) {
F_21 ( L_8 , V_27 ) ;
goto V_28;
}
F_22 ( & V_6 -> V_7 ) ;
return 0 ;
V_28:
F_23 ( V_6 -> V_13 ) ;
V_23:
return - V_29 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_25 ( V_18 ) ;
F_26 ( & V_6 -> V_7 ) ;
F_27 ( & V_18 -> V_19 ) ;
F_23 ( V_6 -> V_13 ) ;
return 0 ;
}
