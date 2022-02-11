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
static int F_8 ( struct V_1 * V_2 ,
int V_20 )
{
unsigned int V_21 = 0 ;
unsigned int V_22 = F_9 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_21 < V_22 && V_23 [ V_21 ] != V_20 )
V_21 ++ ;
if ( V_21 == V_22 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_24 , V_2 -> V_8 -> V_25 ,
V_21 << 2 , V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
int V_21 = 0 ;
unsigned int V_22 = F_9 ( V_23 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_21 < V_22 && V_23 [ V_21 ] < V_27 )
V_21 ++ ;
V_21 -- ;
if ( V_21 < 0 || V_23 [ V_21 ] < V_26 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_24 , V_2 -> V_8 -> V_25 ,
V_21 << 2 , V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_28 ;
unsigned int V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_28 = F_12 ( V_6 , V_2 -> V_8 -> V_24 , & V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
V_21 = ( V_21 & V_2 -> V_8 -> V_25 ) >> 2 ;
return V_23 [ V_21 ] ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 -> V_2 . V_31 ) ;
struct V_32 * V_33 ;
const struct V_34 * V_35 ;
struct V_1 * V_36 ;
const struct V_37 * V_38 ;
struct V_39 V_40 = { } ;
int V_41 ;
V_38 = F_15 ( V_42 , & V_30 -> V_2 ) ;
if ( ! V_38 )
return - V_43 ;
V_35 = V_38 -> V_44 ;
V_41 = V_35 -> V_41 ;
V_33 = F_16 ( & V_30 -> V_2 , V_30 -> V_2 . V_45 ,
& V_46 [ V_41 ] ) ;
F_17 ( V_30 , V_6 ) ;
V_6 -> V_47 [ V_41 ] = & V_48 [ V_41 ] ;
V_40 . V_2 = & V_30 -> V_2 ;
V_40 . V_33 = V_33 ;
V_40 . V_49 = V_6 ;
V_40 . V_50 = V_6 -> V_50 ;
V_40 . V_45 = V_30 -> V_2 . V_45 ;
V_36 = F_18 ( & V_30 -> V_2 , & V_46 [ V_41 ] , & V_40 ) ;
if ( F_19 ( V_36 ) ) {
F_20 ( V_6 -> V_2 , L_1 ,
V_30 -> V_51 ) ;
return F_21 ( V_36 ) ;
}
return 0 ;
}
