static T_1 F_1 ( int V_1 , void * V_2 )
{
static T_2 V_3 ;
struct V_4 * V_5 = V_2 ;
const struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 ;
T_2 V_10 ;
for (; ; ) {
V_9 = F_2 ( V_11 ) ;
if ( V_9 < 0 ) {
F_3 ( V_5 -> V_12 , L_1 ,
V_9 ) ;
break;
}
V_10 = V_9 << 8 ;
V_9 = F_2 ( V_13 ) ;
if ( V_9 < 0 ) {
F_3 ( V_5 -> V_12 , L_2 ,
V_9 ) ;
break;
}
V_10 |= V_9 ;
if ( V_10 == 0xdead )
break;
if ( V_10 == V_3 ) {
V_3 = 0 ;
continue;
}
V_3 = V_10 ;
V_10 &= ~ 0x0800 ;
V_7 = F_4 ( V_5 -> V_14 , V_10 ) ;
V_8 = V_7 ? V_7 -> V_8 : V_15 ;
F_3 ( V_5 -> V_12 ,
L_3 ,
V_10 , V_8 ) ;
F_5 ( V_5 -> V_14 , V_8 , 1 ) ;
F_6 ( V_5 -> V_14 ) ;
F_5 ( V_5 -> V_14 , V_8 , 0 ) ;
F_6 ( V_5 -> V_14 ) ;
}
return V_16 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_4 * V_5 ;
struct V_19 * V_14 ;
int V_9 ;
V_5 = F_8 ( sizeof *V_5 , V_20 ) ;
V_14 = F_9 () ;
if ( ! V_5 || ! V_14 ) {
V_9 = - V_21 ;
goto V_22;
}
V_5 -> V_12 = & V_18 -> V_12 ;
V_5 -> V_14 = V_14 ;
V_9 = F_10 ( V_18 , 0 ) ;
if ( V_9 < 0 )
goto V_22;
V_5 -> V_1 = V_9 ;
V_14 -> V_23 = L_4 ;
V_14 -> V_24 = L_5 ;
V_14 -> V_12 . V_25 = & V_18 -> V_12 ;
V_14 -> V_26 . V_27 = V_28 ;
V_14 -> V_26 . V_29 = 0x0355 ;
V_14 -> V_26 . V_30 = F_2 ( V_31 ) ;
V_9 = F_11 ( V_14 , V_4 , NULL ) ;
if ( V_9 )
goto V_22;
V_9 = F_12 ( V_5 -> V_1 , NULL , F_1 ,
V_32 | V_33 ,
F_13 ( & V_18 -> V_12 ) , V_5 ) ;
if ( V_9 < 0 )
goto V_34;
V_9 = F_14 ( V_14 ) ;
if ( V_9 < 0 )
goto V_35;
F_15 ( V_18 , V_5 ) ;
return 0 ;
V_35:
F_16 ( V_5 -> V_1 , V_5 ) ;
V_34:
F_17 ( V_14 ) ;
V_22:
F_18 ( V_14 ) ;
F_19 ( V_5 ) ;
F_20 ( & V_18 -> V_12 , L_6 , V_9 ) ;
return V_9 ;
}
static int F_21 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = F_22 ( V_18 ) ;
F_16 ( V_5 -> V_1 , V_5 ) ;
F_17 ( V_5 -> V_14 ) ;
F_23 ( V_5 -> V_14 ) ;
F_19 ( V_5 ) ;
return 0 ;
}
