static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( V_2 ) ;
F_5 ( & V_4 -> V_7 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
F_8 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , & V_10 ) ;
if ( V_10 & V_9 -> V_14 )
return V_15 ;
return V_16 ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
F_8 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 , & V_10 ) ;
if ( V_10 & V_9 -> V_14 )
return V_17 ;
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_19 ;
switch ( V_18 ) {
case V_16 :
V_19 = 0 ;
break;
case V_15 :
V_19 = V_9 -> V_14 ;
break;
default:
return - V_20 ;
}
F_11 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 ,
V_9 -> V_14 , V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_19 ;
switch ( V_18 ) {
case V_16 :
V_19 = 0 ;
break;
case V_17 :
V_19 = V_9 -> V_14 ;
break;
default:
return - V_20 ;
}
F_11 ( V_2 -> V_11 , V_2 -> V_12 -> V_13 ,
V_9 -> V_14 , V_19 ) ;
return 0 ;
}
static unsigned int
F_13 ( struct V_1 * V_2 ,
int V_21 , int V_22 , int V_23 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
if ( V_23 > V_9 -> V_24 )
return V_16 ;
return V_15 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_11 * V_27 ,
struct V_28 * V_29 ,
int V_30 , struct V_31 * V_32 )
{
struct V_8 * V_9 = NULL ;
struct V_33 V_34 = { } ;
struct V_1 * V_2 ;
V_9 = & V_8 [ V_30 ] ;
V_34 . V_5 = & V_26 -> V_5 ;
V_34 . V_29 = V_29 ;
V_34 . V_35 = V_9 ;
V_34 . V_11 = V_27 ;
V_34 . V_36 = V_32 ;
V_2 = F_15 ( & V_26 -> V_5 , & V_9 -> V_12 , & V_34 ) ;
if ( F_16 ( V_2 ) ) {
F_17 ( & V_26 -> V_5 , L_1 ,
V_9 -> V_12 . V_37 ) ;
return F_18 ( V_2 ) ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_38 * V_5 = & V_26 -> V_5 ;
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_3 * V_4 ;
int V_41 , V_42 = 0 ;
V_4 = F_20 ( & V_26 -> V_5 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
F_21 ( & V_4 -> V_7 ) ;
F_22 ( V_26 , V_4 ) ;
V_32 = F_23 ( V_5 -> V_6 -> V_36 , L_2 ) ;
if ( ! V_32 )
return - V_45 ;
V_42 = F_24 ( V_5 , V_32 ,
V_46 ,
F_25 ( V_46 ) ) ;
F_26 ( V_32 ) ;
if ( V_42 < 0 ) {
F_17 ( V_5 , L_3 , V_42 ) ;
return V_42 ;
}
V_40 = F_2 ( V_5 -> V_6 ) ;
for ( V_41 = 0 ; V_41 < F_25 ( V_8 ) ; V_41 ++ ) {
V_42 = F_14 ( V_26 , V_40 -> V_11 ,
V_46 [ V_41 ] . V_29 , V_41 ,
V_46 [ V_41 ] . V_36 ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
