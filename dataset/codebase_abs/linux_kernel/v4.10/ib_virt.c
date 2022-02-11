static inline T_1 F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
default:
return V_9 ;
}
}
int F_2 ( struct V_10 * V_11 , int V_12 , T_2 V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_21 = F_4 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
V_22 = F_5 ( V_19 , 1 , 1 , V_12 + 1 , V_21 ) ;
if ( V_22 ) {
F_6 ( V_17 , L_1 ,
V_12 , V_22 ) ;
goto free;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_25 = F_1 ( V_21 -> V_26 ) ;
if ( V_15 -> V_25 == V_9 )
V_22 = - V_27 ;
free:
F_7 ( V_21 ) ;
return V_22 ;
}
static inline enum V_1 F_8 ( int V_26 )
{
switch ( V_26 ) {
case V_4 :
return V_3 ;
case V_6 :
return V_5 ;
case V_8 :
return V_7 ;
default:
return V_28 ;
}
}
int F_9 ( struct V_10 * V_11 , int V_12 ,
T_2 V_13 , int V_29 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_30 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_26 = F_8 ( V_29 ) ;
if ( V_30 -> V_26 == V_28 ) {
V_22 = - V_27 ;
goto V_31;
}
V_30 -> V_32 = V_33 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
V_31:
F_7 ( V_30 ) ;
return V_22 ;
}
int F_11 ( struct V_10 * V_11 , int V_12 ,
T_2 V_13 , struct V_34 * V_35 )
{
int V_36 = F_12 ( V_37 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
void * V_31 ;
int V_22 ;
V_17 = F_3 ( V_11 ) ;
V_19 = V_17 -> V_19 ;
V_31 = F_4 ( V_36 , V_23 ) ;
if ( ! V_31 )
return - V_24 ;
V_22 = F_13 ( V_19 , true , V_12 , V_13 , V_31 , V_36 ) ;
if ( V_22 )
goto V_38;
V_35 -> V_39 = F_14 ( V_37 , V_31 , V_40 . V_41 ) ;
V_35 -> V_42 = F_14 ( V_37 , V_31 , V_43 . V_41 ) ;
V_35 -> V_44 = F_14 ( V_37 , V_31 , V_40 . V_45 ) ;
V_35 -> V_46 = F_14 ( V_37 , V_31 , V_43 . V_45 ) ;
V_35 -> V_47 = F_14 ( V_37 , V_31 , V_48 . V_41 ) ;
V_38:
F_7 ( V_31 ) ;
return V_22 ;
}
static int F_15 ( struct V_10 * V_11 , int V_12 , T_2 V_13 , T_3 V_49 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_30 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_32 = V_50 ;
V_30 -> V_51 = V_49 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
F_7 ( V_30 ) ;
return V_22 ;
}
static int F_16 ( struct V_10 * V_11 , int V_12 , T_2 V_13 , T_3 V_49 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_30 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_32 = V_52 ;
V_30 -> V_53 = V_49 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
F_7 ( V_30 ) ;
return V_22 ;
}
int F_17 ( struct V_10 * V_11 , int V_12 , T_2 V_13 ,
T_3 V_49 , int type )
{
if ( type == V_54 )
return F_15 ( V_11 , V_12 , V_13 , V_49 ) ;
else if ( type == V_55 )
return F_16 ( V_11 , V_12 , V_13 , V_49 ) ;
return - V_27 ;
}
