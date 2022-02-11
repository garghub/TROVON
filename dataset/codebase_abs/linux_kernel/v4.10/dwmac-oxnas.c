static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_2 ( V_5 -> V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_5 -> V_9 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_4 ( V_5 -> V_10 , V_11 , & V_6 ) ;
if ( V_7 < 0 ) {
F_5 ( V_5 -> V_9 ) ;
return V_7 ;
}
V_6 |= F_6 ( V_12 ) |
F_6 ( V_13 ) |
F_6 ( V_14 ) |
F_6 ( V_15 ) |
F_6 ( V_16 ) |
F_6 ( V_17 ) |
F_6 ( V_18 ) |
F_6 ( V_19 ) |
F_6 ( V_20 ) ;
F_7 ( V_5 -> V_10 , V_11 , V_6 ) ;
V_6 = F_8 ( 4 ) |
F_9 ( 2 ) |
F_10 ( 10 ) |
F_11 ( 8 ) ;
F_7 ( V_5 -> V_10 , V_21 , V_6 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_5 ( V_5 -> V_9 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_24 V_25 ;
struct V_4 * V_5 ;
int V_7 ;
V_7 = F_14 ( V_2 , & V_25 ) ;
if ( V_7 )
return V_7 ;
V_23 = F_15 ( V_2 , & V_25 . V_26 ) ;
if ( F_16 ( V_23 ) )
return F_17 ( V_23 ) ;
V_5 = F_18 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 ) {
V_7 = - V_28 ;
goto V_29;
}
V_5 -> V_8 = & V_2 -> V_8 ;
V_23 -> V_30 = V_5 ;
V_23 -> V_31 = F_1 ;
V_23 -> exit = F_12 ;
V_5 -> V_10 = F_19 ( V_2 -> V_8 . V_32 ,
L_1 ) ;
if ( F_16 ( V_5 -> V_10 ) ) {
F_20 ( & V_2 -> V_8 , L_2 ) ;
V_7 = F_17 ( V_5 -> V_10 ) ;
goto V_29;
}
V_5 -> V_9 = F_21 ( & V_2 -> V_8 , L_3 ) ;
if ( F_16 ( V_5 -> V_9 ) ) {
V_7 = F_17 ( V_5 -> V_9 ) ;
goto V_29;
}
V_7 = F_1 ( V_2 , V_23 -> V_30 ) ;
if ( V_7 )
goto V_29;
V_7 = F_22 ( & V_2 -> V_8 , V_23 , & V_25 ) ;
if ( V_7 )
goto V_33;
return 0 ;
V_33:
F_12 ( V_2 , V_23 -> V_30 ) ;
V_29:
F_23 ( V_2 , V_23 ) ;
return V_7 ;
}
