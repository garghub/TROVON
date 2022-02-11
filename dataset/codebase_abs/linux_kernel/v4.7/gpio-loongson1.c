static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = V_2 -> V_5 ( V_2 , V_3 ) ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
F_3 ( F_4 ( V_8 + V_9 ) | V_4 ,
V_8 + V_9 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = V_2 -> V_5 ( V_2 , V_3 ) ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
F_3 ( F_4 ( V_8 + V_9 ) & ~ V_4 ,
V_8 + V_9 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_11 -> V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_16 ;
V_2 = F_8 ( V_13 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_15 = F_9 ( V_11 , V_19 , 0 ) ;
if ( ! V_15 ) {
F_10 ( V_13 , L_1 ) ;
return - V_20 ;
}
V_8 = F_11 ( V_13 , V_15 ) ;
if ( F_12 ( V_8 ) )
return F_13 ( V_8 ) ;
V_16 = F_14 ( V_2 , V_13 , 4 , V_8 + V_21 ,
V_8 + V_22 , NULL ,
NULL , V_8 + V_23 , 0 ) ;
if ( V_16 )
goto V_24;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = F_1 ;
V_2 -> free = F_6 ;
V_2 -> V_28 = V_11 -> V_29 * 32 ;
V_16 = F_15 ( V_13 , V_2 , NULL ) ;
if ( V_16 )
goto V_24;
F_16 ( V_11 , V_2 ) ;
F_17 ( V_13 , L_2 ) ;
return 0 ;
V_24:
F_10 ( V_13 , L_3 ) ;
return V_16 ;
}
