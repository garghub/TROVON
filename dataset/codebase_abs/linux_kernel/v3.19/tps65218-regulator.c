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
int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_18 ,
V_2 -> V_8 -> V_19 , V_2 -> V_8 -> V_19 ,
V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
return F_7 ( V_6 , V_2 -> V_8 -> V_18 ,
V_2 -> V_8 -> V_19 , V_11 ) ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_9 ( V_21 -> V_2 . V_22 ) ;
struct V_23 * V_24 ;
const struct V_25 * V_26 ;
struct V_1 * V_27 ;
const struct V_28 * V_29 ;
struct V_30 V_31 = { } ;
int V_32 ;
V_29 = F_10 ( V_33 , & V_21 -> V_2 ) ;
if ( ! V_29 )
return - V_34 ;
V_26 = V_29 -> V_35 ;
V_32 = V_26 -> V_32 ;
V_24 = F_11 ( & V_21 -> V_2 , V_21 -> V_2 . V_36 ,
& V_37 [ V_32 ] ) ;
F_12 ( V_21 , V_6 ) ;
V_6 -> V_38 [ V_32 ] = & V_39 [ V_32 ] ;
V_31 . V_2 = & V_21 -> V_2 ;
V_31 . V_24 = V_24 ;
V_31 . V_40 = V_6 ;
V_31 . V_41 = V_6 -> V_41 ;
V_31 . V_36 = V_21 -> V_2 . V_36 ;
V_27 = F_13 ( & V_21 -> V_2 , & V_37 [ V_32 ] , & V_31 ) ;
if ( F_14 ( V_27 ) ) {
F_15 ( V_6 -> V_2 , L_1 ,
V_21 -> V_42 ) ;
return F_16 ( V_27 ) ;
}
return 0 ;
}
