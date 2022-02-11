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
if ( V_15 -> V_2 > 62 )
return - V_16 ;
if ( V_15 -> V_17 != V_1 -> V_18 ) {
unsigned int V_19 ;
V_19 = F_7 ( V_20 , V_15 -> V_17 ) ;
if ( V_19 >= 64 )
* V_3 |= V_21 ;
else if ( V_19 >= 16 )
* V_3 |= V_22 ;
else
* V_3 |= V_23 ;
V_1 -> V_18 = V_15 -> V_17 ;
}
if ( V_10 -> V_24 & V_25 )
* V_3 |= V_26 ;
else
* V_3 &= ~ V_26 ;
if ( V_10 -> V_24 & V_27 )
* V_3 &= ~ V_28 ;
else
* V_3 |= V_28 ;
if ( V_10 -> V_24 & V_29 )
* V_3 |= V_30 ;
else
* V_3 &= ~ V_30 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 ,
struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_31 ;
if ( V_15 -> V_32 ) {
V_1 -> V_4 [ 0 ] = V_33 ;
memcpy ( V_1 -> V_4 + 1 , V_15 -> V_32 , V_15 -> V_2 ) ;
V_31 = F_3 ( V_1 -> V_8 , V_1 -> V_4 , V_15 -> V_2 + 1 ) ;
if ( V_31 < 0 )
return V_31 ;
else if ( V_31 != V_15 -> V_2 + 1 )
return - V_34 ;
} else if ( V_15 -> V_35 ) {
V_31 = F_9 ( V_1 -> V_8 , V_15 -> V_35 , V_15 -> V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
else if ( V_31 != V_15 -> V_2 )
return - V_34 ;
}
return V_15 -> V_2 ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_1 = F_11 ( V_37 ) ;
unsigned int V_3 = V_1 -> V_3 ;
struct V_9 * V_10 = V_39 -> V_10 ;
unsigned V_40 = 0 ;
struct V_14 * V_15 ;
bool V_41 = true ;
int V_42 = 0 ;
bool V_43 ;
F_4 ( V_1 , V_10 , true ) ;
F_12 (t, &msg->transfers, transfer_list) {
if ( ! V_15 -> V_32 && ! V_15 -> V_35 && V_15 -> V_2 ) {
V_42 = - V_16 ;
break;
}
V_42 = F_6 ( V_1 , V_10 , V_15 , & V_3 ) ;
if ( V_42 < 0 )
break;
V_43 = F_13 ( & V_15 -> V_44 , & V_39 -> V_45 ) ;
V_40 = V_15 -> V_40 ;
if ( V_40 ^ V_43 )
V_3 |= F_5 ( 5 ) ;
else
V_3 &= ~ F_5 ( 5 ) ;
if ( V_15 -> V_35 ) {
V_1 -> V_3 = V_3 ;
V_42 = F_1 ( V_1 , V_15 -> V_2 ) ;
if ( V_42 < 0 )
break;
} else if ( V_3 != V_1 -> V_3 || V_41 ) {
V_1 -> V_3 = V_3 ;
V_42 = F_1 ( V_1 , 0 ) ;
if ( V_42 < 0 )
break;
}
if ( V_15 -> V_2 ) {
V_42 = F_8 ( V_1 , V_10 , V_15 ) ;
if ( V_42 < 0 )
break;
if ( V_42 > 0 )
V_39 -> V_46 += V_42 ;
}
V_42 = 0 ;
if ( V_15 -> V_47 )
F_14 ( V_15 -> V_47 ) ;
V_41 = false ;
}
if ( V_42 != 0 || ! V_40 )
F_4 ( V_1 , V_10 , false ) ;
V_39 -> V_42 = V_42 ;
F_15 ( V_37 ) ;
return V_42 ;
}
static int F_16 ( struct V_48 * V_8 ,
const struct V_49 * V_50 )
{
struct V_1 * V_1 ;
struct V_36 * V_37 ;
int V_31 ;
V_37 = F_17 ( & V_8 -> V_51 , sizeof( * V_1 ) ) ;
if ( ! V_37 )
return - V_52 ;
V_1 = F_11 ( V_37 ) ;
V_1 -> V_8 = V_8 ;
V_37 -> V_53 = 16 ;
V_37 -> V_54 = V_27 | V_25 | V_29 ;
V_37 -> V_55 = F_18 ( 8 ) ;
V_37 -> V_56 = V_57 ;
V_37 -> V_58 = F_10 ;
V_37 -> V_51 . V_59 = V_8 -> V_51 . V_59 ;
F_19 ( V_8 , V_37 ) ;
V_31 = F_20 ( & V_8 -> V_51 , V_37 ) ;
if ( V_31 < 0 )
F_21 ( V_37 ) ;
return V_31 ;
}
