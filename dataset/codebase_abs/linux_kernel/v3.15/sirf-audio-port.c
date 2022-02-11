static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 , V_5 ) ;
F_3 ( V_2 -> V_3 , V_6 , 0 ) ;
F_3 ( V_2 -> V_3 , V_4 , 0 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
V_7 , V_7 ) ;
F_2 ( V_2 -> V_3 , V_8 ,
V_9 , V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_3 , V_4 , 0 ) ;
F_2 ( V_2 -> V_3 , V_8 ,
V_9 , ~ V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_10 )
{
F_2 ( V_2 -> V_3 , V_11 ,
V_5 , V_5 ) ;
F_3 ( V_2 -> V_3 , V_12 , 0 ) ;
F_3 ( V_2 -> V_3 , V_11 , 0 ) ;
F_2 ( V_2 -> V_3 , V_11 ,
V_7 , V_7 ) ;
if ( V_10 == 1 )
F_2 ( V_2 -> V_3 , V_13 ,
V_14 , V_14 ) ;
else
F_2 ( V_2 -> V_3 , V_13 ,
V_15 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_13 ,
V_15 , ~ V_15 ) ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_9 ( V_17 , & V_2 -> V_18 ,
& V_2 -> V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 , int V_22 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_23 = V_21 -> V_24 == V_25 ;
switch ( V_22 ) {
case V_26 :
case V_27 :
case V_28 :
if ( V_23 )
F_4 ( V_2 ) ;
else
F_6 ( V_2 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
if ( V_23 )
F_1 ( V_2 ) ;
else
F_5 ( V_2 ,
V_21 -> V_32 -> V_10 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_11 ( struct V_34 * V_35 )
{
int V_36 ;
struct V_1 * V_2 ;
void T_1 * V_37 ;
struct V_38 * V_39 ;
V_2 = F_12 ( & V_35 -> V_40 ,
sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_39 = F_13 ( V_35 , V_43 , 0 ) ;
if ( ! V_39 ) {
F_14 ( & V_35 -> V_40 , L_1 ) ;
return - V_44 ;
}
V_37 = F_15 ( & V_35 -> V_40 , V_39 -> V_45 ,
F_16 ( V_39 ) ) ;
if ( V_37 == NULL )
return - V_42 ;
V_2 -> V_3 = F_17 ( & V_35 -> V_40 , V_37 ,
& V_46 ) ;
if ( F_18 ( V_2 -> V_3 ) )
return F_19 ( V_2 -> V_3 ) ;
V_36 = F_20 ( & V_35 -> V_40 ,
& V_47 , & V_48 , 1 ) ;
if ( V_36 )
return V_36 ;
F_21 ( V_35 , V_2 ) ;
return F_22 ( & V_35 -> V_40 , NULL , 0 ) ;
}
