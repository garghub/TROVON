static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long long V_11 ;
T_1 V_12 ;
int V_13 ;
V_12 = F_2 ( F_3 ( V_6 ) , L_1 , NULL , & V_11 ) ;
if ( F_4 ( V_12 ) ) {
F_5 ( V_6 , L_2 ) ;
return - V_14 ;
}
switch ( V_11 ) {
case V_15 :
V_8 = & V_16 ;
break;
case V_17 :
V_8 = & V_18 ;
break;
default:
F_6 ( V_6 , L_3 , V_11 ) ;
V_8 = & V_16 ;
}
V_10 = F_7 ( V_6 , sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
F_8 ( V_6 , V_10 ) ;
V_10 -> V_21 = F_9 ( V_2 , V_8 -> V_22 ) ;
if ( F_10 ( V_10 -> V_21 ) )
return F_11 ( V_10 -> V_21 ) ;
V_10 -> V_23 = V_2 -> V_23 ;
V_13 = F_12 ( V_10 -> V_21 , V_10 -> V_23 ,
V_8 -> V_24 | V_25 ,
0 , V_8 -> V_26 ,
& V_10 -> V_27 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_13 ( V_10 -> V_23 ) ;
if ( V_13 )
F_6 ( V_6 , L_4 , V_13 ) ;
F_14 ( & V_28 ) ;
F_15 ( V_29 , F_16 ( V_29 ) ) ;
V_13 = F_17 ( V_6 , - 1 , V_8 -> V_30 ,
V_8 -> V_31 , NULL , 0 ,
F_18 ( V_10 -> V_27 ) ) ;
if ( V_13 )
goto V_32;
return 0 ;
V_32:
F_19 ( V_10 -> V_23 , V_10 -> V_27 ) ;
return V_13 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_21 ( & V_2 -> V_6 ) ;
F_19 ( V_10 -> V_23 , V_10 -> V_27 ) ;
F_22 ( & V_28 ) ;
F_23 ( V_29 , F_16 ( V_29 ) ) ;
F_24 ( & V_2 -> V_6 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_21 ( & V_2 -> V_6 ) ;
F_26 ( V_10 -> V_23 ) ;
return;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
F_26 ( V_10 -> V_23 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_21 ( V_6 ) ;
F_29 ( V_10 -> V_23 ) ;
return 0 ;
}
