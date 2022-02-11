static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = F_2 ( V_3 ) ;
if ( V_2 -> V_11 == V_8 -> V_12 . V_13 ) {
if ( V_10 > 0 )
return V_14 ;
else
return F_3 ( V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = F_2 ( V_3 ) ;
if ( V_2 -> V_11 == V_8 -> V_12 . V_13 ) {
if ( V_10 > 0 )
return V_14 ;
else
return F_6 ( V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
return F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static void T_2 * F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
void T_2 * V_15 = V_8 -> V_16 ;
if ( V_2 -> V_11 == V_8 -> V_12 . V_13 )
return V_15 + V_4 ;
else
return F_9 ( V_2 , V_3 , V_4 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_17 * V_10 = V_8 -> V_18 ;
struct V_19 * V_20 = F_11 ( V_10 ) ;
struct V_21 * V_22 = F_12 ( V_20 ) ;
struct V_23 * V_24 ;
void T_2 * V_15 ;
int V_25 ;
V_24 = F_13 ( V_10 , sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
V_25 = F_14 ( V_10 , L_1 , V_22 -> V_28 , V_24 ) ;
if ( V_25 ) {
F_15 ( V_10 , L_2 ) ;
return - V_27 ;
}
V_15 = F_16 ( V_10 , V_24 -> V_13 , F_17 ( V_24 ) ) ;
if ( ! V_15 )
return - V_27 ;
V_8 -> V_16 = V_15 ;
return 0 ;
}
static int F_18 ( struct V_29 * V_30 , int V_4 , int V_5 ,
T_1 * V_6 )
{
T_1 V_31 ;
T_1 V_32 ;
void * V_33 = & V_32 ;
V_33 += ( V_4 & 0x3 ) ;
V_31 = V_4 & ~ 0x3 ;
V_32 = F_19 ( V_30 , V_31 ) ;
if ( V_5 == 1 )
* V_6 = * ( V_34 V_35 * ) V_33 ;
else if ( V_5 == 2 )
* V_6 = * ( V_36 V_35 * ) V_33 ;
else if ( V_5 == 4 )
* V_6 = V_32 ;
else
return V_37 ;
return V_38 ;
}
static int F_20 ( struct V_29 * V_30 , int V_4 , int V_5 ,
T_1 V_6 )
{
T_1 V_32 ;
T_1 V_31 ;
void * V_33 = & V_32 ;
V_33 += ( V_4 & 0x3 ) ;
V_31 = V_4 & ~ 0x3 ;
if ( V_5 == 4 )
F_21 ( V_30 , V_31 , V_6 ) ;
else if ( V_5 == 2 ) {
V_32 = F_19 ( V_30 , V_31 ) ;
* ( V_36 V_35 * ) V_33 = V_6 ;
F_21 ( V_30 , V_31 , V_32 ) ;
} else if ( V_5 == 1 ) {
V_32 = F_19 ( V_30 , V_31 ) ;
* ( V_34 V_35 * ) V_33 = V_6 ;
F_21 ( V_30 , V_31 , V_32 ) ;
} else
return V_37 ;
return V_38 ;
}
static int F_22 ( struct V_39 * V_39 )
{
T_1 V_6 ;
F_23 ( V_39 -> V_40 , V_41 +
0x100 * V_39 -> V_42 , & V_6 ) ;
return ( ( V_6 & V_43 ) == V_44 ) ;
}
static int F_24 ( struct V_39 * V_39 )
{
struct V_29 * V_30 = & V_39 -> V_30 ;
T_1 V_6 ;
V_6 = F_19 ( V_30 , V_45 ) ;
return ( ( V_6 & V_43 ) == V_44 ) ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_39 * V_39 = F_26 ( V_30 ) ;
return V_39 -> V_46 -> F_25 ( V_39 ) ;
}
static int F_27 ( struct V_39 * V_39 ,
struct V_47 * V_48 )
{
struct V_29 * V_30 = & V_39 -> V_30 ;
struct V_17 * V_10 = V_30 -> V_10 ;
int V_25 ;
T_1 V_42 ;
if ( F_28 ( V_10 -> V_49 , L_3 , & V_42 ) ) {
F_15 ( V_10 , L_4 ) ;
return - V_50 ;
}
if ( V_42 > 3 ) {
F_15 ( V_10 , L_5 , V_42 ) ;
return - V_50 ;
}
V_39 -> V_42 = V_42 ;
V_30 -> V_51 = & V_52 ;
V_25 = F_29 ( V_30 ) ;
if ( V_25 ) {
F_15 ( V_10 , L_6 ) ;
return V_25 ;
}
return 0 ;
}
static int F_30 ( struct V_47 * V_48 )
{
struct V_17 * V_10 = & V_48 -> V_10 ;
struct V_39 * V_39 ;
struct V_29 * V_30 ;
const struct V_53 * V_54 ;
struct V_23 * V_31 ;
struct V_55 * V_56 ;
int V_25 ;
V_39 = F_13 ( V_10 , sizeof( * V_39 ) , V_26 ) ;
if ( ! V_39 )
return - V_27 ;
V_30 = & V_39 -> V_30 ;
V_30 -> V_10 = V_10 ;
V_56 = V_10 -> V_56 ;
V_54 = F_31 ( V_56 -> V_57 , V_10 ) ;
V_39 -> V_46 = (struct V_58 * ) V_54 -> V_59 ;
V_39 -> V_40 =
F_32 ( L_7 ) ;
if ( F_33 ( V_39 -> V_40 ) ) {
F_15 ( V_10 , L_8 ) ;
return F_34 ( V_39 -> V_40 ) ;
}
V_31 = F_35 ( V_48 , V_60 , L_9 ) ;
V_30 -> V_61 = F_36 ( V_10 , V_31 ) ;
if ( F_33 ( V_30 -> V_61 ) )
return F_34 ( V_30 -> V_61 ) ;
V_25 = F_27 ( V_39 , V_48 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
