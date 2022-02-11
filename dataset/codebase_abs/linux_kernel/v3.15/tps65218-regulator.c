static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 ) ;
V_4 = F_4 ( V_6 , V_2 -> V_8 -> V_9 , V_2 -> V_8 -> V_10 ,
V_3 , V_11 ) ;
switch ( V_7 ) {
case V_12 :
case V_13 :
V_4 = F_4 ( V_6 , V_14 ,
V_15 ,
V_15 ,
V_11 ) ;
break;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_18 ,
V_2 -> V_8 -> V_19 , V_2 -> V_8 -> V_19 ,
V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
return F_7 ( V_6 , V_2 -> V_8 -> V_18 ,
V_2 -> V_8 -> V_19 , V_11 ) ;
}
static int F_8 ( struct V_1 * V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
int V_23 , V_24 ;
V_23 = F_9 ( V_20 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
V_24 = F_9 ( V_20 , V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_10 ( abs ( V_23 - V_24 ) , V_25 ) ;
}
static int F_11 ( struct V_26 * V_27 )
{
struct V_5 * V_6 = F_12 ( V_27 -> V_2 . V_28 ) ;
struct V_29 * V_30 ;
const struct V_31 * V_32 ;
struct V_1 * V_20 ;
const struct V_33 * V_34 ;
struct V_35 V_36 = { } ;
int V_37 ;
V_34 = F_13 ( V_38 , & V_27 -> V_2 ) ;
if ( ! V_34 )
return - V_39 ;
V_32 = V_34 -> V_40 ;
V_37 = V_32 -> V_37 ;
V_30 = F_14 ( & V_27 -> V_2 , V_27 -> V_2 . V_41 ) ;
F_15 ( V_27 , V_6 ) ;
V_6 -> V_42 [ V_37 ] = & V_43 [ V_37 ] ;
V_36 . V_2 = & V_27 -> V_2 ;
V_36 . V_30 = V_30 ;
V_36 . V_44 = V_6 ;
V_36 . V_45 = V_6 -> V_45 ;
V_20 = F_16 ( & V_27 -> V_2 , & V_46 [ V_37 ] , & V_36 ) ;
if ( F_17 ( V_20 ) ) {
F_18 ( V_6 -> V_2 , L_1 ,
V_27 -> V_47 ) ;
return F_19 ( V_20 ) ;
}
return 0 ;
}
