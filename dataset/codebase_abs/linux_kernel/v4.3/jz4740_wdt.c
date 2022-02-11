static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x0 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned short V_10 = V_11 ;
V_8 = F_5 ( V_4 -> V_12 ) ;
V_9 = V_8 * V_7 ;
while ( V_9 > 0xffff ) {
if ( V_10 == V_13 ) {
V_9 = 0xffff ;
break;
}
V_9 >>= 2 ;
V_10 += ( 1 << V_14 ) ;
}
F_6 ( 0x0 , V_4 -> V_5 + V_15 ) ;
F_3 ( V_10 , V_4 -> V_5 + V_16 ) ;
F_3 ( ( V_17 ) V_9 , V_4 -> V_5 + V_18 ) ;
F_3 ( 0x0 , V_4 -> V_5 + V_6 ) ;
F_3 ( V_10 | V_19 ,
V_4 -> V_5 + V_16 ) ;
F_6 ( 0x1 , V_4 -> V_5 + V_15 ) ;
V_2 -> V_20 = V_7 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 () ;
F_4 ( V_2 , V_2 -> V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 () ;
F_6 ( 0x0 , V_4 -> V_5 + V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_1 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
V_4 = F_12 ( & V_22 -> V_27 , sizeof( struct V_3 ) ,
V_28 ) ;
if ( ! V_4 ) {
F_13 ( & V_22 -> V_27 , L_1 ) ;
return - V_29 ;
}
if ( V_30 < 1 || V_30 > V_31 )
V_30 = V_32 ;
V_23 = & V_4 -> V_33 ;
V_23 -> V_34 = & V_35 ;
V_23 -> V_36 = & V_37 ;
V_23 -> V_20 = V_30 ;
V_23 -> V_38 = 1 ;
V_23 -> V_39 = V_31 ;
V_23 -> V_40 = & V_22 -> V_27 ;
F_14 ( V_23 , V_41 ) ;
F_15 ( V_23 , V_4 ) ;
V_25 = F_16 ( V_22 , V_42 , 0 ) ;
V_4 -> V_5 = F_17 ( & V_22 -> V_27 , V_25 ) ;
if ( F_18 ( V_4 -> V_5 ) ) {
V_26 = F_19 ( V_4 -> V_5 ) ;
goto V_43;
}
V_4 -> V_12 = F_20 ( & V_22 -> V_27 , L_2 ) ;
if ( F_18 ( V_4 -> V_12 ) ) {
F_13 ( & V_22 -> V_27 , L_3 ) ;
V_26 = F_19 ( V_4 -> V_12 ) ;
goto V_43;
}
V_26 = F_21 ( & V_4 -> V_33 ) ;
if ( V_26 < 0 )
goto V_44;
F_22 ( V_22 , V_4 ) ;
return 0 ;
V_44:
F_23 ( V_4 -> V_12 ) ;
V_43:
return V_26 ;
}
static int F_24 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_25 ( V_22 ) ;
F_9 ( & V_4 -> V_33 ) ;
F_26 ( & V_4 -> V_33 ) ;
F_23 ( V_4 -> V_12 ) ;
return 0 ;
}
