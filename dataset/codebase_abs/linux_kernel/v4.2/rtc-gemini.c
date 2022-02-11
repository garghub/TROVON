static T_1 F_1 ( int V_1 , void * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_4 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
unsigned long V_13 , time ;
V_12 = F_4 ( V_8 -> V_14 + V_15 ) ;
V_11 = F_4 ( V_8 -> V_14 + V_16 ) ;
V_10 = F_4 ( V_8 -> V_14 + V_17 ) ;
V_9 = F_4 ( V_8 -> V_14 + V_18 ) ;
V_13 = F_4 ( V_8 -> V_14 + V_19 ) ;
time = V_13 + V_9 * 86400 + V_10 * 3600 + V_11 * 60 + V_12 ;
F_5 ( time , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
unsigned int V_12 , V_11 , V_10 , V_20 ;
unsigned long V_13 , time ;
if ( V_6 -> V_21 >= 2148 )
return - V_22 ;
F_7 ( V_6 , & time ) ;
V_12 = F_4 ( V_8 -> V_14 + V_15 ) ;
V_11 = F_4 ( V_8 -> V_14 + V_16 ) ;
V_10 = F_4 ( V_8 -> V_14 + V_17 ) ;
V_20 = F_4 ( V_8 -> V_14 + V_18 ) ;
V_13 = time - ( V_20 * 86400 + V_10 * 3600 + V_11 * 60 + V_12 ) ;
F_8 ( V_13 , V_8 -> V_14 + V_19 ) ;
F_8 ( 0x01 , V_8 -> V_14 + V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
struct V_4 * V_2 = & V_25 -> V_2 ;
struct V_26 * V_27 ;
int V_28 ;
V_8 = F_10 ( & V_25 -> V_2 , sizeof( * V_8 ) , V_29 ) ;
if ( F_11 ( ! V_8 ) )
return - V_30 ;
F_12 ( V_25 , V_8 ) ;
V_27 = F_13 ( V_25 , V_31 , 0 ) ;
if ( ! V_27 )
return - V_32 ;
V_8 -> V_33 = V_27 -> V_34 ;
V_27 = F_13 ( V_25 , V_35 , 0 ) ;
if ( ! V_27 )
return - V_32 ;
V_8 -> V_14 = F_14 ( V_2 , V_27 -> V_34 ,
F_15 ( V_27 ) ) ;
V_28 = F_16 ( V_2 , V_8 -> V_33 , F_1 ,
V_36 , V_25 -> V_37 , V_2 ) ;
if ( F_11 ( V_28 ) )
return V_28 ;
V_8 -> V_38 = F_17 ( V_25 -> V_37 , V_2 ,
& V_39 , V_40 ) ;
if ( F_18 ( F_19 ( V_8 -> V_38 ) ) )
return F_20 ( V_8 -> V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_7 * V_8 = F_22 ( V_25 ) ;
F_23 ( V_8 -> V_38 ) ;
F_12 ( V_25 , NULL ) ;
return 0 ;
}
