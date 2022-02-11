static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_2 V_7 = F_3 () ;
if ( F_4 ( V_6 -> V_8 ) ) {
V_6 -> V_9 = V_7 ;
F_5 ( & V_6 -> V_10 ) ;
} else {
V_6 -> V_11 = V_7 ;
F_5 ( & V_6 -> V_12 ) ;
}
return V_13 ;
}
static int F_6 ( struct V_5 * V_6 )
{
int V_14 ;
T_2 V_15 ;
T_3 V_16 ;
T_4 V_17 , V_18 ;
F_7 ( & V_6 -> V_19 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_8 ( & V_6 -> V_12 ) ;
F_9 ( V_6 -> V_20 , 1 ) ;
F_10 ( 10 ) ;
F_9 ( V_6 -> V_20 , 0 ) ;
V_14 = F_11 ( & V_6 -> V_10 , V_21 / 50 ) ;
if ( V_14 < 0 ) {
F_12 ( & V_6 -> V_19 ) ;
return V_14 ;
} else if ( V_14 == 0 ) {
F_12 ( & V_6 -> V_19 ) ;
return - V_22 ;
}
V_14 = F_11 ( & V_6 -> V_12 , V_21 / 50 ) ;
if ( V_14 < 0 ) {
F_12 ( & V_6 -> V_19 ) ;
return V_14 ;
} else if ( V_14 == 0 ) {
F_12 ( & V_6 -> V_19 ) ;
return - V_22 ;
}
V_15 = F_13 ( V_6 -> V_11 , V_6 -> V_9 ) ;
F_12 ( & V_6 -> V_19 ) ;
V_16 = F_14 ( V_15 ) ;
if ( V_16 > 9404389 )
return - V_23 ;
V_17 = V_16 ;
V_18 = V_17 * 343 / 2000000 ;
return V_18 ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_24 const * V_25 , int * V_26 ,
int * V_27 , long V_28 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_14 ;
if ( V_25 -> type != V_29 )
return - V_30 ;
switch ( V_28 ) {
case V_31 :
V_14 = F_6 ( V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_26 = V_14 ;
return V_32 ;
case V_33 :
* V_26 = 0 ;
* V_27 = 1000 ;
return V_34 ;
default:
return - V_30 ;
}
}
static int F_16 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_38 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_14 ;
V_4 = F_17 ( V_38 , sizeof( struct V_5 ) ) ;
if ( ! V_4 ) {
F_18 ( V_38 , L_1 ) ;
return - V_39 ;
}
V_6 = F_2 ( V_4 ) ;
V_6 -> V_38 = V_38 ;
F_19 ( & V_6 -> V_19 ) ;
F_20 ( & V_6 -> V_10 ) ;
F_20 ( & V_6 -> V_12 ) ;
V_6 -> V_20 = F_21 ( V_38 , L_2 , V_40 ) ;
if ( F_22 ( V_6 -> V_20 ) ) {
F_18 ( V_38 , L_3 ,
F_23 ( V_6 -> V_20 ) ) ;
return F_23 ( V_6 -> V_20 ) ;
}
V_6 -> V_8 = F_21 ( V_38 , L_4 , V_41 ) ;
if ( F_22 ( V_6 -> V_8 ) ) {
F_18 ( V_38 , L_5 ,
F_23 ( V_6 -> V_8 ) ) ;
return F_23 ( V_6 -> V_8 ) ;
}
if ( F_24 ( V_6 -> V_8 ) ) {
F_18 ( V_6 -> V_38 , L_6 ) ;
return - V_42 ;
}
V_6 -> V_43 = F_25 ( V_6 -> V_8 ) ;
if ( V_6 -> V_43 < 0 ) {
F_18 ( V_6 -> V_38 , L_7 , V_6 -> V_43 ) ;
return V_6 -> V_43 ;
}
V_14 = F_26 ( V_38 , V_6 -> V_43 , F_1 ,
V_44 | V_45 ,
V_36 -> V_46 , V_4 ) ;
if ( V_14 < 0 ) {
F_18 ( V_6 -> V_38 , L_8 , V_14 ) ;
return V_14 ;
}
F_27 ( V_36 , V_4 ) ;
V_4 -> V_46 = L_9 ;
V_4 -> V_38 . V_47 = & V_36 -> V_38 ;
V_4 -> V_28 = & V_48 ;
V_4 -> V_49 = V_50 ;
V_4 -> V_51 = V_52 ;
V_4 -> V_53 = F_28 ( V_52 ) ;
return F_29 ( V_38 , V_4 ) ;
}
