static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_4 ;
if ( V_1 == F_2 ( V_3 -> V_5 , V_6 ) )
V_4 = V_7 | V_8 ;
else if ( V_1 == F_2 ( V_3 -> V_5 , V_9 ) )
V_4 = V_7 | V_10 ;
else
V_4 = 0 ;
F_3 ( V_3 -> V_11 , 1 , V_4 ) ;
return V_12 ;
}
static int F_4 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_14 ) ;
struct V_3 * V_3 = F_6 ( V_18 ) ;
struct V_19 * V_20 = & V_16 -> time ;
unsigned long V_21 ;
T_2 V_22 ;
T_2 V_23 ;
F_7 ( V_3 -> V_5 , V_24 , & V_22 ) ;
V_21 = V_22 & V_25 ;
F_7 ( V_3 -> V_5 , V_26 , & V_23 ) ;
V_21 += ( V_23 & V_27 ) * V_28 ;
F_8 ( V_21 , V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_14 ) ;
struct V_3 * V_3 = F_6 ( V_18 ) ;
struct V_19 * V_20 = & V_16 -> time ;
unsigned long V_21 ;
T_2 V_22 , V_23 ;
F_10 ( V_20 , & V_21 ) ;
V_22 = V_21 % V_28 ;
F_11 ( V_3 -> V_5 , V_24 , V_22 ) ;
V_23 = V_21 / V_28 ;
F_11 ( V_3 -> V_5 , V_26 , V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , struct V_19 * V_20 )
{
struct V_17 * V_18 = F_5 ( V_14 ) ;
struct V_3 * V_3 = F_6 ( V_18 ) ;
unsigned long V_21 ;
T_2 V_22 , V_23 ;
F_7 ( V_3 -> V_5 , V_29 , & V_22 ) ;
V_21 = V_22 & V_25 ;
F_7 ( V_3 -> V_5 , V_30 , & V_23 ) ;
V_21 += ( V_23 & V_27 ) * V_28 ;
F_8 ( V_21 , V_20 ) ;
return F_13 ( V_20 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned long V_21 )
{
struct V_17 * V_18 = F_5 ( V_14 ) ;
struct V_3 * V_3 = F_6 ( V_18 ) ;
T_2 V_22 , V_23 ;
V_22 = V_21 % V_28 ;
F_11 ( V_3 -> V_5 , V_29 , V_22 ) ;
V_23 = V_21 / V_28 ;
F_11 ( V_3 -> V_5 , V_30 , V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , int V_31 , unsigned int V_32 )
{
struct V_17 * V_18 = F_5 ( V_14 ) ;
struct V_3 * V_3 = F_6 ( V_18 ) ;
if ( V_32 )
F_16 ( F_2 ( V_3 -> V_5 , V_31 ) ) ;
else
F_17 ( F_2 ( V_3 -> V_5 , V_31 ) ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 , unsigned int V_32 )
{
return F_15 ( V_14 , V_9 , V_32 ) ;
}
static int T_3 F_19 ( struct V_17 * V_18 )
{
struct V_3 * V_3 ;
int V_33 , V_34 ;
int V_35 = - V_36 ;
V_3 = F_20 ( & V_18 -> V_14 , sizeof( struct V_3 ) ,
V_37 ) ;
if ( ! V_3 )
return V_35 ;
V_3 -> V_5 = F_21 ( V_18 -> V_14 . V_38 ) ;
F_22 ( V_18 , V_3 ) ;
V_3 -> V_11 = F_23 ( & V_18 -> V_14 , L_1 ,
& V_39 , V_40 ) ;
if ( F_24 ( V_3 -> V_11 ) ) {
V_35 = F_25 ( V_3 -> V_11 ) ;
goto V_41;
}
V_33 = F_2 ( V_3 -> V_5 , V_6 ) ;
V_34 = F_2 ( V_3 -> V_5 , V_9 ) ;
V_35 = F_26 ( & V_18 -> V_14 , V_33 , F_1 , 0 ,
L_2 , V_3 ) ;
if ( V_35 )
goto V_41;
V_35 = F_26 ( & V_18 -> V_14 , V_34 , F_1 , 0 ,
L_3 , V_3 ) ;
if ( V_35 )
goto V_41;
return 0 ;
V_41:
F_22 ( V_18 , NULL ) ;
return V_35 ;
}
static int T_4 F_27 ( struct V_17 * V_18 )
{
return 0 ;
}
