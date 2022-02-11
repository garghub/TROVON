int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
T_1 V_5 = 3 ;
T_1 V_6 = 3 ;
int V_7 = 0 ;
int V_8 = 0 ;
T_1 V_9 = 0 ;
T_1 V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
if ( ! V_12 )
return - V_13 ;
switch ( V_4 ) {
case V_14 :
V_9 = ( 3 << 6 ) ;
V_9 |= ( 3 << 3 ) ;
break;
case V_15 :
V_9 = ( 2 << 6 ) ;
V_9 |= ( 2 << 3 ) ;
break;
case V_16 :
V_9 = ( 1 << 6 ) ;
V_9 |= ( 1 << 3 ) ;
break;
case V_17 :
break;
case V_18 :
F_3 ( L_1 ) ;
V_7 = 1 ;
default:
V_7 = 1 ;
}
V_10 = V_9 ;
if ( ! V_7 )
V_9 |= V_6 ;
V_8 = F_4 ( V_12 , V_19 , V_9 ) ;
if ( V_8 )
goto V_20;
if ( ! V_7 )
V_10 |= V_5 ;
V_8 = F_4 ( V_12 , V_21 , V_10 ) ;
if ( V_8 )
goto V_20;
V_8 = F_4 ( V_12 , V_22 , V_10 ) ;
if ( V_8 )
goto V_20;
return V_8 ;
V_20:
F_3 ( L_2 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_23 )
{
if ( V_23 & ( V_24 & ~ V_25 ) )
return F_1 ( V_2 , V_17 ) ;
else
return F_1 ( V_2 , V_18 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_3 V_28 = V_27 -> V_29 . V_28 ;
int V_30 = V_27 -> V_29 . V_30 ;
int V_31 = 0 ;
if ( V_28 == 1080 && ! V_30 )
V_31 = F_1 ( V_2 , V_14 ) ;
else if ( ( V_28 == 720 && ! V_30 ) ||
( V_28 == 1080 && V_30 ) )
V_31 = F_1 ( V_2 , V_15 ) ;
else if ( ( V_28 == 480 || V_28 == 576 ) && ! V_30 )
V_31 = F_1 ( V_2 , V_16 ) ;
else
V_31 = F_1 ( V_2 , V_18 ) ;
return V_31 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
return F_8 ( V_12 , V_33 , V_34 , 0 ) ;
}
static int F_9 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 ;
T_2 V_37 = V_38 ;
if ( ! F_10 ( V_12 -> V_39 , V_40 ) )
return - V_41 ;
F_11 ( V_12 , L_3 ,
V_12 -> V_42 << 1 , V_12 -> V_39 -> V_43 ) ;
V_2 = F_12 ( & V_12 -> V_44 , sizeof( struct V_1 ) , V_45 ) ;
if ( V_2 == NULL )
return - V_46 ;
F_13 ( V_2 , V_12 , & V_47 ) ;
return F_5 ( V_2 , V_37 ) ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
