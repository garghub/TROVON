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
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
return F_7 ( V_6 , V_2 -> V_8 -> V_20 ,
V_2 -> V_8 -> V_21 ,
V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_12 || V_7 > V_16 )
return - V_17 ;
if ( ! V_6 -> V_22 [ V_7 ] -> V_23 ) {
if ( V_7 == V_24 )
V_6 -> V_22 [ V_7 ] -> V_23 = 3 ;
else
return - V_17 ;
}
return F_4 ( V_6 , V_2 -> V_8 -> V_20 ,
V_2 -> V_8 -> V_21 ,
V_6 -> V_22 [ V_7 ] -> V_23 ,
V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_25 )
{
unsigned int V_26 = 0 ;
unsigned int V_27 = F_11 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_26 < V_27 && V_28 [ V_26 ] != V_25 )
V_26 ++ ;
if ( V_26 == V_27 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_29 , V_2 -> V_8 -> V_30 ,
V_26 << 2 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_31 , int V_32 )
{
int V_26 = 0 ;
unsigned int V_27 = F_11 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_26 < V_27 && V_28 [ V_26 ] < V_32 )
V_26 ++ ;
V_26 -- ;
if ( V_26 < 0 || V_28 [ V_26 ] < V_31 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_29 , V_2 -> V_8 -> V_30 ,
V_26 << 2 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_33 ;
unsigned int V_26 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_33 = F_14 ( V_6 , V_2 -> V_8 -> V_29 , & V_26 ) ;
if ( V_33 < 0 )
return V_33 ;
V_26 = ( V_26 & V_2 -> V_8 -> V_30 ) >> 2 ;
return V_28 [ V_26 ] ;
}
static int F_15 ( struct V_34 * V_35 )
{
struct V_5 * V_6 = F_16 ( V_35 -> V_2 . V_36 ) ;
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
struct V_1 * V_41 ;
const struct V_42 * V_43 ;
struct V_44 V_45 = { } ;
int V_46 , V_4 ;
unsigned int V_47 ;
V_43 = F_17 ( V_48 , & V_35 -> V_2 ) ;
if ( ! V_43 )
return - V_49 ;
V_40 = V_43 -> V_50 ;
V_46 = V_40 -> V_46 ;
V_38 = F_18 ( & V_35 -> V_2 , V_35 -> V_2 . V_51 ,
& V_52 [ V_46 ] ) ;
F_19 ( V_35 , V_6 ) ;
V_6 -> V_22 [ V_46 ] = & V_53 [ V_46 ] ;
V_45 . V_2 = & V_35 -> V_2 ;
V_45 . V_38 = V_38 ;
V_45 . V_54 = V_6 ;
V_45 . V_55 = V_6 -> V_55 ;
V_45 . V_51 = V_35 -> V_2 . V_51 ;
V_41 = F_20 ( & V_35 -> V_2 , & V_52 [ V_46 ] , & V_45 ) ;
if ( F_21 ( V_41 ) ) {
F_22 ( V_6 -> V_2 , L_1 ,
V_35 -> V_56 ) ;
return F_23 ( V_41 ) ;
}
V_4 = F_14 ( V_6 , V_52 [ V_46 ] . V_20 , & V_47 ) ;
if ( V_4 )
return V_4 ;
V_6 -> V_22 [ V_46 ] -> V_23 = V_47 & V_52 [ V_46 ] . V_21 ;
return 0 ;
}
