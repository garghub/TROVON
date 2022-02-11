static inline T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
return V_1 * V_2 - V_1 / 2 ;
}
static const struct V_3 * F_2 ( T_1 V_4 ,
T_2 * V_2 )
{
const struct V_3 * V_5 ;
T_2 V_6 ;
if ( V_4 < 30 && V_4 != 16 ) {
V_5 = & V_7 [ 0 ] ;
V_6 = V_4 / 2 + 1 ;
} else {
V_5 = & V_7 [ 1 ] ;
V_6 = F_3 ( V_4 + 16 , 32 ) ;
if ( V_6 > V_8 )
V_6 = V_8 ;
}
* V_2 = V_6 ;
return V_5 ;
}
static int F_4 ( struct V_9 * V_10 ,
unsigned int V_4 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
const struct V_3 * V_5 ;
T_2 V_2 ;
V_5 = F_2 ( V_4 , & V_2 ) ;
F_6 ( V_2 << 4 | V_5 -> V_13 ,
V_12 -> V_14 + V_15 ) ;
V_10 -> V_4 = F_1 ( V_5 -> V_1 , V_2 ) ;
V_12 -> V_1 = V_5 -> V_1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
T_2 V_16 ;
F_4 ( V_10 , V_10 -> V_4 ) ;
V_16 = F_8 ( V_12 -> V_14 + V_17 ) ;
F_6 ( V_16 | V_18 , V_12 -> V_14 + V_17 ) ;
F_6 ( 1 , V_12 -> V_14 + V_19 ) ;
V_16 = F_8 ( V_12 -> V_14 + V_20 ) ;
F_6 ( V_16 | V_21 , V_12 -> V_14 + V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_6 ( 0 , V_12 -> V_14 + V_20 ) ;
F_6 ( 0 , V_12 -> V_14 + V_17 ) ;
F_6 ( 0xF0 , V_12 -> V_14 + V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_6 ( 1 , V_12 -> V_14 + V_19 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
T_2 V_6 ;
V_6 = F_8 ( V_12 -> V_14 + V_22 ) & 0xF ;
if ( ! V_6 )
return 0 ;
return F_1 ( V_12 -> V_1 , V_6 ) ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_26 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_27 * V_28 ;
int V_29 ;
V_12 = F_13 ( V_26 , sizeof( * V_12 ) , V_30 ) ;
if ( ! V_12 )
return - V_31 ;
F_14 ( V_24 , V_12 ) ;
V_28 = F_15 ( V_24 , V_32 , 0 ) ;
if ( ! V_28 ) {
F_16 ( V_26 , L_1 ) ;
return - V_33 ;
}
if ( ! F_17 ( V_26 , V_28 -> V_34 , F_18 ( V_28 ) ,
V_35 ) ) {
F_16 ( V_26 , L_2 ) ;
return - V_36 ;
}
V_12 -> V_14 = V_28 -> V_34 ;
V_10 = & V_12 -> V_10 ;
V_10 -> V_37 = & V_38 ;
V_10 -> V_39 = & V_40 ;
V_10 -> V_41 = V_42 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_4 = V_45 ;
V_10 -> V_46 = V_26 ;
F_19 ( V_10 , V_12 ) ;
F_20 ( V_10 , V_47 ) ;
V_29 = F_21 ( V_10 , V_4 , V_26 ) ;
if ( V_29 )
F_22 ( V_26 , L_3 ) ;
F_6 ( V_48 , V_12 -> V_14 + V_49 ) ;
V_29 = F_23 ( V_10 ) ;
if ( V_29 ) {
F_6 ( V_50 , V_12 -> V_14 + V_49 ) ;
F_16 ( V_26 , L_4 ) ;
return V_29 ;
}
F_24 ( V_26 , L_5 ,
V_12 -> V_14 , V_4 , V_47 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_11 * V_12 = F_26 ( V_24 ) ;
F_27 ( & V_12 -> V_10 ) ;
F_6 ( V_50 , V_12 -> V_14 + V_49 ) ;
return 0 ;
}
