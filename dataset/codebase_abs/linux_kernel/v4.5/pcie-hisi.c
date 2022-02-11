static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_1 * V_3 )
{
T_1 V_4 ;
T_1 V_10 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
void * V_11 = & V_10 ;
V_11 += ( V_8 & 0x3 ) ;
V_4 = V_8 & ~ 0x3 ;
V_10 = F_3 ( V_2 , V_4 ) ;
if ( V_9 == 1 )
* V_3 = * ( V_12 V_13 * ) V_11 ;
else if ( V_9 == 2 )
* V_3 = * ( V_14 V_13 * ) V_11 ;
else if ( V_9 == 4 )
* V_3 = V_10 ;
else
return V_15 ;
return V_16 ;
}
static int F_7 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_1 V_3 )
{
T_1 V_10 ;
T_1 V_4 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
void * V_11 = & V_10 ;
V_11 += ( V_8 & 0x3 ) ;
V_4 = V_8 & ~ 0x3 ;
if ( V_9 == 4 )
F_1 ( V_2 , V_3 , V_4 ) ;
else if ( V_9 == 2 ) {
V_10 = F_3 ( V_2 , V_4 ) ;
* ( V_14 V_13 * ) V_11 = V_3 ;
F_1 ( V_2 , V_10 , V_4 ) ;
} else if ( V_9 == 1 ) {
V_10 = F_3 ( V_2 , V_4 ) ;
* ( V_12 V_13 * ) V_11 = V_3 ;
F_1 ( V_2 , V_10 , V_4 ) ;
} else
return V_15 ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_1 )
{
T_1 V_3 ;
F_9 ( V_1 -> V_17 , V_18 +
0x100 * V_1 -> V_19 , & V_3 ) ;
return ( ( V_3 & V_20 ) == V_21 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
T_1 V_3 ;
V_3 = F_3 ( V_1 , V_22 +
V_23 ) ;
return ( ( V_3 & V_20 ) == V_21 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
return V_1 -> V_24 -> F_11 ( V_1 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
int V_27 ;
T_1 V_19 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( F_13 ( V_26 -> V_28 . V_29 , L_1 , & V_19 ) ) {
F_14 ( & V_26 -> V_28 , L_2 ) ;
return - V_30 ;
}
if ( V_19 > 3 ) {
F_14 ( & V_26 -> V_28 , L_3 , V_19 ) ;
return - V_30 ;
}
V_1 -> V_19 = V_19 ;
V_7 -> V_31 = & V_32 ;
V_27 = F_15 ( V_7 ) ;
if ( V_27 ) {
F_14 ( & V_26 -> V_28 , L_4 ) ;
return V_27 ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_1 * V_1 ;
struct V_6 * V_7 ;
const struct V_33 * V_34 ;
struct V_35 * V_4 ;
struct V_36 * V_37 ;
int V_27 ;
V_1 = F_17 ( & V_26 -> V_28 , sizeof( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return - V_39 ;
V_7 = & V_1 -> V_7 ;
V_7 -> V_28 = & V_26 -> V_28 ;
V_37 = ( V_26 -> V_28 ) . V_37 ;
V_34 = F_18 ( V_37 -> V_40 , & V_26 -> V_28 ) ;
V_1 -> V_24 = (struct V_41 * ) V_34 -> V_42 ;
V_1 -> V_17 =
F_19 ( L_5 ) ;
if ( F_20 ( V_1 -> V_17 ) ) {
F_14 ( V_7 -> V_28 , L_6 ) ;
return F_21 ( V_1 -> V_17 ) ;
}
V_4 = F_22 ( V_26 , V_43 , L_7 ) ;
V_1 -> V_5 = F_23 ( & V_26 -> V_28 , V_4 ) ;
if ( F_20 ( V_1 -> V_5 ) ) {
F_14 ( V_7 -> V_28 , L_8 ) ;
return F_21 ( V_1 -> V_5 ) ;
}
V_1 -> V_7 . V_44 = V_1 -> V_5 ;
V_27 = F_12 ( V_7 , V_26 ) ;
if ( V_27 )
return V_27 ;
F_24 ( V_26 , V_1 ) ;
F_25 ( V_7 -> V_28 , L_9 ) ;
return 0 ;
}
