static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
T_1 V_3 ;
T_2 * V_4 = V_1 -> V_4 ;
V_3 = V_1 -> V_3 ;
V_3 |= V_2 << V_5 ;
V_4 [ 0 ] = V_6 ;
F_2 ( V_3 , & V_4 [ 1 ] ) ;
F_2 ( V_1 -> V_7 , & V_4 [ 3 ] ) ;
return F_3 ( V_1 -> V_8 , V_4 , 5 ) ;
}
static void F_4 ( struct V_1 * V_1 ,
struct V_9 * V_10 , int V_11 )
{
unsigned long V_12 = V_10 -> V_13 ;
T_1 V_7 = V_1 -> V_7 ;
if ( V_11 )
V_7 |= F_5 ( V_12 ) ;
else
V_7 &= ~ F_5 ( V_12 ) ;
V_1 -> V_7 = V_7 ;
}
static int F_6 ( struct V_1 * V_1 ,
struct V_9 * V_10 , struct V_14 * V_15 , unsigned int * V_3 )
{
unsigned int V_16 ;
if ( ( V_15 -> V_17 && V_15 -> V_17 != 8 ) || V_15 -> V_2 > 62 )
return - V_18 ;
V_16 = V_15 -> V_19 ? V_15 -> V_19 : V_10 -> V_20 ;
if ( V_16 != V_1 -> V_21 ) {
unsigned int V_22 = F_7 ( V_23 , V_16 ) ;
if ( V_22 >= 64 )
* V_3 |= V_24 ;
else if ( V_22 >= 16 )
* V_3 |= V_25 ;
else
* V_3 |= V_26 ;
V_1 -> V_21 = V_16 ;
}
if ( V_10 -> V_27 & V_28 )
* V_3 |= V_29 ;
else
* V_3 &= ~ V_29 ;
if ( V_10 -> V_27 & V_30 )
* V_3 &= ~ V_31 ;
else
* V_3 |= V_31 ;
if ( V_10 -> V_27 & V_32 )
* V_3 |= V_33 ;
else
* V_3 &= ~ V_33 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 ,
struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_34 ;
if ( V_15 -> V_35 ) {
V_1 -> V_4 [ 0 ] = V_36 ;
memcpy ( V_1 -> V_4 + 1 , V_15 -> V_35 , V_15 -> V_2 ) ;
V_34 = F_3 ( V_1 -> V_8 , V_1 -> V_4 , V_15 -> V_2 + 1 ) ;
if ( V_34 < 0 )
return V_34 ;
else if ( V_34 != V_15 -> V_2 + 1 )
return - V_37 ;
} else if ( V_15 -> V_38 ) {
V_34 = F_9 ( V_1 -> V_8 , V_15 -> V_38 , V_15 -> V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
else if ( V_34 != V_15 -> V_2 )
return - V_37 ;
}
return V_15 -> V_2 ;
}
static int F_10 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_1 = F_11 ( V_40 ) ;
unsigned int V_3 = V_1 -> V_3 ;
struct V_9 * V_10 = V_42 -> V_10 ;
unsigned V_43 = 0 ;
struct V_14 * V_15 ;
bool V_44 = true ;
int V_45 = 0 ;
bool V_46 ;
V_44 = true ;
F_4 ( V_1 , V_10 , true ) ;
F_12 (t, &msg->transfers, transfer_list) {
if ( ! V_15 -> V_35 && ! V_15 -> V_38 && V_15 -> V_2 ) {
V_45 = - V_18 ;
break;
}
V_45 = F_6 ( V_1 , V_10 , V_15 , & V_3 ) ;
if ( V_45 < 0 )
break;
V_46 = F_13 ( & V_15 -> V_47 , & V_42 -> V_48 ) ;
V_43 = V_15 -> V_43 ;
if ( V_43 ^ V_46 )
V_3 |= F_5 ( 5 ) ;
else
V_3 &= ~ F_5 ( 5 ) ;
if ( V_15 -> V_38 ) {
V_1 -> V_3 = V_3 ;
V_45 = F_1 ( V_1 , V_15 -> V_2 ) ;
if ( V_45 < 0 )
break;
} else if ( V_3 != V_1 -> V_3 || V_44 ) {
V_1 -> V_3 = V_3 ;
V_45 = F_1 ( V_1 , 0 ) ;
if ( V_45 < 0 )
break;
}
if ( V_15 -> V_2 ) {
V_45 = F_8 ( V_1 , V_10 , V_15 ) ;
if ( V_45 < 0 )
break;
if ( V_45 > 0 )
V_42 -> V_49 += V_45 ;
}
V_45 = 0 ;
if ( V_15 -> V_50 )
F_14 ( V_15 -> V_50 ) ;
V_44 = false ;
}
if ( V_45 != 0 || ! V_43 )
F_4 ( V_1 , V_10 , false ) ;
V_42 -> V_45 = V_45 ;
F_15 ( V_40 ) ;
return V_45 ;
}
static int F_16 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 != 8 )
return - V_18 ;
return 0 ;
}
static int T_3 F_17 ( struct V_51 * V_8 ,
const struct V_52 * V_53 )
{
struct V_1 * V_1 ;
struct V_39 * V_40 ;
int V_34 ;
V_40 = F_18 ( & V_8 -> V_54 , sizeof( * V_1 ) ) ;
if ( ! V_40 )
return - V_55 ;
V_1 = F_11 ( V_40 ) ;
V_1 -> V_8 = V_8 ;
V_40 -> V_56 = 16 ;
V_40 -> V_57 = V_30 | V_28 | V_32 ;
V_40 -> V_58 = V_59 ;
V_40 -> V_60 = F_16 ;
V_40 -> V_61 = F_10 ;
V_40 -> V_54 . V_62 = V_8 -> V_54 . V_62 ;
F_19 ( V_8 , V_40 ) ;
V_34 = F_20 ( V_40 ) ;
if ( V_34 < 0 )
F_21 ( V_40 ) ;
return V_34 ;
}
static int T_4 F_22 ( struct V_51 * V_8 )
{
struct V_39 * V_40 = F_23 ( V_8 ) ;
F_24 ( V_40 ) ;
return 0 ;
}
