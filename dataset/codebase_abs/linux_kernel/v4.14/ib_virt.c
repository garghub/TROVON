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
struct V_31 * V_32 = V_19 -> V_33 . V_34 . V_32 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_26 = F_8 ( V_29 ) ;
if ( V_30 -> V_26 == V_28 ) {
V_22 = - V_27 ;
goto V_35;
}
V_30 -> V_36 = V_37 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
if ( ! V_22 )
V_32 [ V_12 ] . V_26 = V_30 -> V_26 ;
V_35:
F_7 ( V_30 ) ;
return V_22 ;
}
int F_11 ( struct V_10 * V_11 , int V_12 ,
T_2 V_13 , struct V_38 * V_39 )
{
int V_40 = F_12 ( V_41 ) ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
void * V_35 ;
int V_22 ;
V_17 = F_3 ( V_11 ) ;
V_19 = V_17 -> V_19 ;
V_35 = F_4 ( V_40 , V_23 ) ;
if ( ! V_35 )
return - V_24 ;
V_22 = F_13 ( V_19 , true , V_12 , V_13 , V_35 , V_40 ) ;
if ( V_22 )
goto V_42;
V_39 -> V_43 = F_14 ( V_41 , V_35 , V_44 . V_45 ) ;
V_39 -> V_46 = F_14 ( V_41 , V_35 , V_47 . V_45 ) ;
V_39 -> V_48 = F_14 ( V_41 , V_35 , V_44 . V_49 ) ;
V_39 -> V_50 = F_14 ( V_41 , V_35 , V_47 . V_49 ) ;
V_39 -> V_51 = F_14 ( V_41 , V_35 , V_52 . V_45 ) ;
V_42:
F_7 ( V_35 ) ;
return V_22 ;
}
static int F_15 ( struct V_10 * V_11 , int V_12 , T_2 V_13 , T_3 V_53 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_30 ;
struct V_31 * V_32 = V_19 -> V_33 . V_34 . V_32 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_36 = V_54 ;
V_30 -> V_55 = V_53 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
if ( ! V_22 )
V_32 [ V_12 ] . V_55 = V_53 ;
F_7 ( V_30 ) ;
return V_22 ;
}
static int F_16 ( struct V_10 * V_11 , int V_12 , T_2 V_13 , T_3 V_53 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_30 ;
struct V_31 * V_32 = V_19 -> V_33 . V_34 . V_32 ;
int V_22 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_36 = V_56 ;
V_30 -> V_57 = V_53 ;
V_22 = F_10 ( V_19 , 1 , 1 , V_12 + 1 , V_30 ) ;
if ( ! V_22 )
V_32 [ V_12 ] . V_57 = V_53 ;
F_7 ( V_30 ) ;
return V_22 ;
}
int F_17 ( struct V_10 * V_11 , int V_12 , T_2 V_13 ,
T_3 V_53 , int type )
{
if ( type == V_58 )
return F_15 ( V_11 , V_12 , V_13 , V_53 ) ;
else if ( type == V_59 )
return F_16 ( V_11 , V_12 , V_13 , V_53 ) ;
return - V_27 ;
}
