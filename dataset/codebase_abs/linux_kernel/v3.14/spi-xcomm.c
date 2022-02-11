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
if ( V_15 -> V_2 > 62 )
return - V_17 ;
V_16 = V_15 -> V_18 ? V_15 -> V_18 : V_10 -> V_19 ;
if ( V_16 != V_1 -> V_20 ) {
unsigned int V_21 = F_7 ( V_22 , V_16 ) ;
if ( V_21 >= 64 )
* V_3 |= V_23 ;
else if ( V_21 >= 16 )
* V_3 |= V_24 ;
else
* V_3 |= V_25 ;
V_1 -> V_20 = V_16 ;
}
if ( V_10 -> V_26 & V_27 )
* V_3 |= V_28 ;
else
* V_3 &= ~ V_28 ;
if ( V_10 -> V_26 & V_29 )
* V_3 &= ~ V_30 ;
else
* V_3 |= V_30 ;
if ( V_10 -> V_26 & V_31 )
* V_3 |= V_32 ;
else
* V_3 &= ~ V_32 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 ,
struct V_9 * V_10 , struct V_14 * V_15 )
{
int V_33 ;
if ( V_15 -> V_34 ) {
V_1 -> V_4 [ 0 ] = V_35 ;
memcpy ( V_1 -> V_4 + 1 , V_15 -> V_34 , V_15 -> V_2 ) ;
V_33 = F_3 ( V_1 -> V_8 , V_1 -> V_4 , V_15 -> V_2 + 1 ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_33 != V_15 -> V_2 + 1 )
return - V_36 ;
} else if ( V_15 -> V_37 ) {
V_33 = F_9 ( V_1 -> V_8 , V_15 -> V_37 , V_15 -> V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_33 != V_15 -> V_2 )
return - V_36 ;
}
return V_15 -> V_2 ;
}
static int F_10 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_1 = F_11 ( V_39 ) ;
unsigned int V_3 = V_1 -> V_3 ;
struct V_9 * V_10 = V_41 -> V_10 ;
unsigned V_42 = 0 ;
struct V_14 * V_15 ;
bool V_43 = true ;
int V_44 = 0 ;
bool V_45 ;
V_43 = true ;
F_4 ( V_1 , V_10 , true ) ;
F_12 (t, &msg->transfers, transfer_list) {
if ( ! V_15 -> V_34 && ! V_15 -> V_37 && V_15 -> V_2 ) {
V_44 = - V_17 ;
break;
}
V_44 = F_6 ( V_1 , V_10 , V_15 , & V_3 ) ;
if ( V_44 < 0 )
break;
V_45 = F_13 ( & V_15 -> V_46 , & V_41 -> V_47 ) ;
V_42 = V_15 -> V_42 ;
if ( V_42 ^ V_45 )
V_3 |= F_5 ( 5 ) ;
else
V_3 &= ~ F_5 ( 5 ) ;
if ( V_15 -> V_37 ) {
V_1 -> V_3 = V_3 ;
V_44 = F_1 ( V_1 , V_15 -> V_2 ) ;
if ( V_44 < 0 )
break;
} else if ( V_3 != V_1 -> V_3 || V_43 ) {
V_1 -> V_3 = V_3 ;
V_44 = F_1 ( V_1 , 0 ) ;
if ( V_44 < 0 )
break;
}
if ( V_15 -> V_2 ) {
V_44 = F_8 ( V_1 , V_10 , V_15 ) ;
if ( V_44 < 0 )
break;
if ( V_44 > 0 )
V_41 -> V_48 += V_44 ;
}
V_44 = 0 ;
if ( V_15 -> V_49 )
F_14 ( V_15 -> V_49 ) ;
V_43 = false ;
}
if ( V_44 != 0 || ! V_42 )
F_4 ( V_1 , V_10 , false ) ;
V_41 -> V_44 = V_44 ;
F_15 ( V_39 ) ;
return V_44 ;
}
static int F_16 ( struct V_50 * V_8 ,
const struct V_51 * V_52 )
{
struct V_1 * V_1 ;
struct V_38 * V_39 ;
int V_33 ;
V_39 = F_17 ( & V_8 -> V_53 , sizeof( * V_1 ) ) ;
if ( ! V_39 )
return - V_54 ;
V_1 = F_11 ( V_39 ) ;
V_1 -> V_8 = V_8 ;
V_39 -> V_55 = 16 ;
V_39 -> V_56 = V_29 | V_27 | V_31 ;
V_39 -> V_57 = F_18 ( 8 ) ;
V_39 -> V_58 = V_59 ;
V_39 -> V_60 = F_10 ;
V_39 -> V_53 . V_61 = V_8 -> V_53 . V_61 ;
F_19 ( V_8 , V_39 ) ;
V_33 = F_20 ( & V_8 -> V_53 , V_39 ) ;
if ( V_33 < 0 )
F_21 ( V_39 ) ;
return V_33 ;
}
