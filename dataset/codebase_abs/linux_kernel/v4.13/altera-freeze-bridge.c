static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
void T_2 * V_7 = V_2 -> V_8 +
V_9 ;
T_1 V_10 , V_11 , V_12 ;
int V_13 = - V_14 ;
do {
V_11 = F_2 ( V_7 ) ;
if ( V_11 ) {
F_3 ( V_6 , L_1 , V_11 ) ;
F_4 ( 1 , V_7 ) ;
V_11 = F_2 ( V_7 ) ;
if ( V_11 )
F_3 ( V_6 , L_2 ,
V_11 ) ;
V_13 = - V_15 ;
break;
}
V_10 = F_2 ( V_2 -> V_8 + V_16 ) ;
F_5 ( V_6 , L_3 , V_17 , V_10 , V_4 ) ;
V_10 &= V_4 ;
if ( V_10 ) {
V_12 = F_2 ( V_2 -> V_8 + V_18 ) ;
F_5 ( V_6 , L_4 ,
V_17 , V_4 , V_10 , V_12 ) ;
V_13 = 0 ;
break;
}
F_6 ( 1 ) ;
} while ( V_3 -- );
if ( V_13 == - V_14 )
F_3 ( V_6 , L_5 ,
V_17 , V_4 ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
void T_2 * V_19 = V_2 -> V_8 +
V_18 ;
T_1 V_10 ;
int V_13 ;
V_10 = F_2 ( V_2 -> V_8 + V_16 ) ;
F_5 ( V_6 , L_6 , V_17 , V_10 , F_2 ( V_19 ) ) ;
if ( V_10 & V_20 ) {
F_5 ( V_6 , L_7 ,
V_17 , V_10 ) ;
return 0 ;
} else if ( ! ( V_10 & V_21 ) ) {
F_3 ( V_6 , L_8 , V_17 , V_10 ) ;
return - V_15 ;
}
F_4 ( V_22 , V_19 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_20 ) ;
if ( V_13 )
F_4 ( 0 , V_19 ) ;
else
F_4 ( V_23 , V_19 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
void T_2 * V_19 = V_2 -> V_8 +
V_18 ;
T_1 V_10 ;
int V_13 ;
F_4 ( 0 , V_19 ) ;
V_10 = F_2 ( V_2 -> V_8 + V_16 ) ;
F_5 ( V_6 , L_6 , V_17 , V_10 , F_2 ( V_19 ) ) ;
if ( V_10 & V_21 ) {
F_5 ( V_6 , L_9 ,
V_17 , V_10 ) ;
return 0 ;
} else if ( ! ( V_10 & V_20 ) ) {
F_3 ( V_6 , L_10 , V_17 , V_10 ) ;
return - V_15 ;
}
F_4 ( V_24 , V_19 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_21 ) ;
V_10 = F_2 ( V_2 -> V_8 + V_16 ) ;
F_5 ( V_6 , L_6 , V_17 , V_10 , F_2 ( V_19 ) ) ;
F_4 ( 0 , V_19 ) ;
return V_13 ;
}
static int F_9 ( struct V_25 * V_26 ,
bool V_27 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_28 * V_29 = V_26 -> V_29 ;
T_1 V_3 = 0 ;
int V_13 ;
if ( V_27 ) {
if ( V_29 )
V_3 = V_29 -> V_30 ;
V_13 = F_8 ( V_26 -> V_2 , V_3 ) ;
} else {
if ( V_29 )
V_3 = V_29 -> V_31 ;
V_13 = F_7 ( V_26 -> V_2 , V_3 ) ;
}
if ( ! V_13 )
V_2 -> V_27 = V_27 ;
return V_13 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
return V_2 -> V_27 ;
}
static int F_11 ( struct V_32 * V_33 )
{
struct V_5 * V_6 = & V_33 -> V_6 ;
struct V_34 * V_35 = V_33 -> V_6 . V_36 ;
void T_2 * V_8 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
T_1 V_10 , V_39 ;
if ( ! V_35 )
return - V_40 ;
V_38 = F_12 ( V_33 , V_41 , 0 ) ;
V_8 = F_13 ( V_6 , V_38 ) ;
if ( F_14 ( V_8 ) )
return F_15 ( V_8 ) ;
V_39 = F_2 ( V_8 + V_42 ) ;
if ( ( V_39 != V_43 ) &&
( V_39 != V_44 ) ) {
F_3 ( V_6 ,
L_11 ,
V_17 , V_39 , V_43 ,
V_44 ) ;
return - V_15 ;
}
V_2 = F_16 ( V_6 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_6 = V_6 ;
V_10 = F_2 ( V_8 + V_16 ) ;
if ( V_10 & V_21 )
V_2 -> V_27 = 1 ;
V_2 -> V_8 = V_8 ;
return F_17 ( V_6 , V_47 ,
& V_48 , V_2 ) ;
}
static int F_18 ( struct V_32 * V_33 )
{
F_19 ( & V_33 -> V_6 ) ;
return 0 ;
}
