static int F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
V_3 &= ~ V_6 ;
V_3 |= ( 0x1 << V_7 ) ;
V_3 &= ~ V_8 ;
V_3 |= ( 0x0F1 << V_9 ) ;
V_3 &= ~ V_10 ;
V_3 |= ( 0x2 << V_11 ) ;
F_3 ( V_3 , V_2 -> V_5 ) ;
V_3 = F_2 ( V_2 -> V_5 ) ;
F_3 ( ( V_3 | V_12 ) , V_2 -> V_5 ) ;
F_3 ( V_3 , V_2 -> V_5 ) ;
V_3 = F_2 ( V_2 -> V_13 ) ;
V_3 &= ~ V_14 ;
F_3 ( V_3 , V_2 -> V_13 ) ;
for ( V_4 = 0 ; V_4 < 1000000 ; V_4 ++ ) {
V_3 = F_2 ( V_2 -> V_13 ) ;
if ( V_3 & V_15 )
break;
}
if ( V_4 == 1000000 )
return - V_16 ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 ,
unsigned long * V_19 )
{
unsigned long V_3 ;
struct V_1 * V_2 = V_18 -> V_20 ;
V_3 = F_2 ( V_2 -> V_5 + V_21 ) ;
if ( ( V_3 & V_22 ) == 0x0 ) {
F_5 ( & V_18 -> V_23 ,
L_1 ) ;
return - V_16 ;
}
V_3 = F_2 ( V_2 -> V_13 ) ;
V_3 = ( V_3 >> V_24 ) & V_15 ;
* V_19 = ( ( 3220000000UL - ( 10000000UL * V_3 ) ) / 13625 ) ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 )
{
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_29 ;
V_28 = F_7 ( V_26 , V_30 , 0 ) ;
if ( ! V_28 ) {
F_5 ( & V_26 -> V_31 , L_2 ) ;
return - V_32 ;
}
V_2 = F_8 ( & V_26 -> V_31 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_13 = F_9 ( & V_26 -> V_31 , V_28 ) ;
if ( F_10 ( V_2 -> V_13 ) )
return F_11 ( V_2 -> V_13 ) ;
V_28 = F_7 ( V_26 , V_30 , 1 ) ;
V_2 -> V_5 = F_9 ( & V_26 -> V_31 , V_28 ) ;
if ( F_10 ( V_2 -> V_5 ) )
return F_11 ( V_2 -> V_5 ) ;
V_29 = F_1 ( V_2 ) ;
if ( V_29 ) {
F_5 ( & V_26 -> V_31 , L_3 ) ;
return V_29 ;
}
V_18 = F_12 ( L_4 , 0 , 0 ,
V_2 , & V_35 , NULL , 0 , 0 ) ;
if ( F_10 ( V_18 ) ) {
F_5 ( & V_26 -> V_31 ,
L_5 ) ;
return F_11 ( V_18 ) ;
}
F_13 ( V_26 , V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_17 * V_36 =
F_15 ( V_26 ) ;
F_16 ( V_36 ) ;
F_13 ( V_26 , NULL ) ;
return 0 ;
}
