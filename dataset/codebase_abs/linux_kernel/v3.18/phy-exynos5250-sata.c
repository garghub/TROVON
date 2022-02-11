static int F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 )
{
unsigned long V_5 = V_6 + V_7 ;
while ( F_2 ( V_6 , V_5 ) ) {
if ( ( F_3 ( V_1 + V_2 ) & V_3 ) == V_4 )
return 0 ;
}
return - V_8 ;
}
static int F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
return F_6 ( V_11 -> V_12 , V_13 ,
V_14 , true ) ;
}
static int F_7 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
return F_6 ( V_11 -> V_12 , V_13 ,
V_14 , false ) ;
}
static int F_8 ( struct V_9 * V_9 )
{
T_2 V_15 = 0 ;
int V_16 = 0 ;
T_3 V_17 [] = { 0x3a , 0x0b } ;
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_16 = F_6 ( V_11 -> V_12 , V_13 ,
V_14 , true ) ;
if ( V_16 != 0 )
F_9 ( & V_11 -> V_9 -> V_18 , L_1 ) ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_20 ) ;
V_15 |= V_21 | V_22 | V_23
| V_24 | V_25
| V_26 | V_27 ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_20 ) ;
V_15 |= V_28 ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_20 ) ;
V_15 |= V_22 ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_29 ) ;
V_15 &= ~ V_30 ;
F_10 ( V_15 , V_11 -> V_19 + V_29 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_29 ) ;
V_15 |= V_31 ;
F_10 ( V_15 , V_11 -> V_19 + V_29 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_32 ) ;
V_15 |= V_33 | V_34 ;
F_10 ( V_15 , V_11 -> V_19 + V_32 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_35 ) ;
V_15 |= V_36 ;
F_10 ( V_15 , V_11 -> V_19 + V_35 ) ;
V_16 = F_11 ( V_11 -> V_37 , V_17 , sizeof( V_17 ) ) ;
if ( V_16 < 0 )
return V_16 ;
V_15 = F_3 ( V_11 -> V_19 + V_20 ) ;
V_15 &= ~ V_22 ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_15 = F_3 ( V_11 -> V_19 + V_20 ) ;
V_15 |= V_22 ;
F_10 ( V_15 , V_11 -> V_19 + V_20 ) ;
V_16 = F_1 ( V_11 -> V_19 ,
V_38 ,
V_39 , 1 ) ;
if ( V_16 < 0 )
F_9 ( & V_11 -> V_9 -> V_18 ,
L_2 ) ;
return V_16 ;
}
static int F_12 ( struct V_40 * V_41 )
{
struct V_10 * V_11 ;
struct V_42 * V_18 = & V_41 -> V_18 ;
struct V_43 * V_44 ;
struct V_45 * V_45 ;
struct V_46 * V_47 ;
int V_16 = 0 ;
V_11 = F_13 ( V_18 , sizeof( * V_11 ) , V_48 ) ;
if ( ! V_11 )
return - V_49 ;
V_44 = F_14 ( V_41 , V_50 , 0 ) ;
V_11 -> V_19 = F_15 ( V_18 , V_44 ) ;
if ( F_16 ( V_11 -> V_19 ) )
return F_17 ( V_11 -> V_19 ) ;
V_11 -> V_12 = F_18 ( V_18 -> V_51 ,
L_3 ) ;
if ( F_16 ( V_11 -> V_12 ) ) {
F_9 ( V_18 , L_4 ) ;
return F_17 ( V_11 -> V_12 ) ;
}
V_47 = F_19 ( V_18 -> V_51 ,
L_5 , 0 ) ;
if ( ! V_47 )
return - V_52 ;
V_11 -> V_37 = F_20 ( V_47 ) ;
if ( ! V_11 -> V_37 )
return - V_53 ;
F_21 ( V_18 , V_11 ) ;
V_11 -> V_54 = F_22 ( V_18 , L_6 ) ;
if ( F_16 ( V_11 -> V_54 ) ) {
F_9 ( V_18 , L_7 ) ;
return F_17 ( V_11 -> V_54 ) ;
}
V_16 = F_23 ( V_11 -> V_54 ) ;
if ( V_16 < 0 ) {
F_9 ( V_18 , L_8 ) ;
return V_16 ;
}
V_11 -> V_9 = F_24 ( V_18 , NULL , & V_55 , NULL ) ;
if ( F_16 ( V_11 -> V_9 ) ) {
F_25 ( V_11 -> V_54 ) ;
F_9 ( V_18 , L_9 ) ;
return F_17 ( V_11 -> V_9 ) ;
}
F_26 ( V_11 -> V_9 , V_11 ) ;
V_45 = F_27 ( V_18 ,
V_56 ) ;
if ( F_16 ( V_45 ) ) {
F_25 ( V_11 -> V_54 ) ;
return F_17 ( V_45 ) ;
}
return 0 ;
}
