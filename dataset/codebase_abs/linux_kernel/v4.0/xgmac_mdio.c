static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
unsigned int V_5 ;
V_5 = V_6 ;
while ( ( F_2 ( & V_4 -> V_7 ) & V_8 ) && V_5 ) {
F_3 () ;
V_5 -- ;
}
if ( ! V_5 ) {
F_4 ( V_2 , L_1 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
unsigned int V_5 ;
V_5 = V_6 ;
while ( ( F_2 ( & V_4 -> V_10 ) & V_11 ) && V_5 ) {
F_3 () ;
V_5 -- ;
}
if ( ! V_5 ) {
F_4 ( V_2 , L_2 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_12 * V_13 , int V_14 , int V_15 , T_2 V_16 )
{
struct V_3 T_1 * V_4 = V_13 -> V_17 ;
T_3 V_18 ;
T_4 V_19 , V_7 ;
int V_20 ;
V_7 = F_2 ( & V_4 -> V_7 ) ;
if ( V_15 & V_21 ) {
V_18 = ( V_15 >> 16 ) & 0x1f ;
V_7 |= V_22 ;
} else {
V_18 = V_15 & 0x1f ;
V_7 &= ~ V_22 ;
}
F_7 ( V_7 , & V_4 -> V_7 ) ;
V_20 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
V_19 = F_8 ( V_14 ) | F_9 ( V_18 ) ;
F_7 ( V_19 , & V_4 -> V_19 ) ;
if ( V_15 & V_21 ) {
F_7 ( V_15 & 0xffff , & V_4 -> V_23 ) ;
V_20 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
}
F_7 ( F_10 ( V_16 ) , & V_4 -> V_10 ) ;
V_20 = F_5 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , int V_14 , int V_15 )
{
struct V_3 T_1 * V_4 = V_13 -> V_17 ;
T_3 V_18 ;
T_5 V_7 ;
T_5 V_19 ;
T_3 V_16 ;
int V_20 ;
V_7 = F_2 ( & V_4 -> V_7 ) ;
if ( V_15 & V_21 ) {
V_18 = ( V_15 >> 16 ) & 0x1f ;
V_7 |= V_22 ;
} else {
V_18 = V_15 & 0x1f ;
V_7 &= ~ V_22 ;
}
F_7 ( V_7 , & V_4 -> V_7 ) ;
V_20 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
V_19 = F_8 ( V_14 ) | F_9 ( V_18 ) ;
F_7 ( V_19 , & V_4 -> V_19 ) ;
if ( V_15 & V_21 ) {
F_7 ( V_15 & 0xffff , & V_4 -> V_23 ) ;
V_20 = F_1 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
}
F_7 ( V_19 | V_24 , & V_4 -> V_19 ) ;
V_20 = F_5 ( & V_13 -> V_2 , V_4 ) ;
if ( V_20 )
return V_20 ;
if ( F_2 ( & V_4 -> V_7 ) & V_25 ) {
F_4 ( & V_13 -> V_2 ,
L_3 ,
V_14 , V_18 , V_15 ) ;
return 0xffff ;
}
V_16 = F_2 ( & V_4 -> V_10 ) & 0xffff ;
F_12 ( & V_13 -> V_2 , L_4 , V_16 ) ;
return V_16 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_2 . V_30 ;
struct V_12 * V_13 ;
struct V_31 V_32 ;
int V_20 ;
V_20 = F_14 ( V_29 , 0 , & V_32 ) ;
if ( V_20 ) {
F_4 ( & V_27 -> V_2 , L_5 ) ;
return V_20 ;
}
V_13 = F_15 () ;
if ( ! V_13 )
return - V_33 ;
V_13 -> V_34 = L_6 ;
V_13 -> V_35 = F_11 ;
V_13 -> V_36 = F_6 ;
V_13 -> V_37 = & V_27 -> V_2 ;
snprintf ( V_13 -> V_38 , V_39 , L_7 , ( unsigned long long ) V_32 . V_40 ) ;
V_13 -> V_17 = F_16 ( V_29 , 0 ) ;
if ( ! V_13 -> V_17 ) {
V_20 = - V_33 ;
goto V_41;
}
V_20 = F_17 ( V_13 , V_29 ) ;
if ( V_20 ) {
F_4 ( & V_27 -> V_2 , L_8 ) ;
goto V_42;
}
F_18 ( V_27 , V_13 ) ;
return 0 ;
V_42:
F_19 ( V_13 -> V_17 ) ;
V_41:
F_20 ( V_13 ) ;
return V_20 ;
}
static int F_21 ( struct V_26 * V_27 )
{
struct V_12 * V_13 = F_22 ( V_27 ) ;
F_23 ( V_13 ) ;
F_19 ( V_13 -> V_17 ) ;
F_20 ( V_13 ) ;
return 0 ;
}
