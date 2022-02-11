static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 == 0 )
return 1 ;
if ( ! V_3 || V_5 -> V_6 )
return V_5 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_8 )
{
unsigned long V_9 ;
T_2 V_10 ;
* V_8 = F_4 ( V_5 -> V_11 ) ;
if ( V_2 -> V_4 != 0 ) {
V_9 = V_12 ;
V_10 = V_9 - V_13 . V_14 ;
V_10 = V_2 -> V_4 - ( V_10 % V_2 -> V_4 ) ;
V_13 . V_14 = V_9 + V_10 ;
V_5 -> V_6 = 0 ;
F_5 ( & V_5 -> V_7 ) ;
F_6 ( & V_13 ) ;
}
return 4 ;
}
static void F_7 ( unsigned long V_15 )
{
V_5 -> V_6 = 1 ;
F_8 ( & V_5 -> V_7 ) ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_10 ( V_17 , V_21 , 0 ) ;
if ( ! V_19 )
return - V_22 ;
V_5 = V_17 -> V_23 . V_24 ;
V_5 -> V_11 = F_11 ( V_19 -> V_25 , F_12 ( V_19 ) ) ;
if ( ! V_5 -> V_11 )
return - V_26 ;
if ( V_5 -> V_27 != 0
&& F_13 ( V_5 -> V_27 ) > 0 ) {
V_13 . V_14 = V_12 ;
V_28 . V_4 = F_13 (
V_5 -> V_27 ) ;
}
V_5 -> V_6 = 1 ;
V_20 = F_14 ( & V_28 ) ;
if ( V_20 )
goto V_29;
F_15 ( & V_17 -> V_23 , L_1 ,
V_5 -> V_11 ,
V_5 -> V_27 ) ;
return 0 ;
V_29:
F_16 ( & V_17 -> V_23 , L_2 ) ;
F_17 ( V_5 -> V_11 ) ;
return V_20 ;
}
static int F_18 ( struct V_16 * V_17 )
{
F_19 ( & V_13 ) ;
F_20 ( & V_28 ) ;
F_17 ( V_5 -> V_11 ) ;
return 0 ;
}
