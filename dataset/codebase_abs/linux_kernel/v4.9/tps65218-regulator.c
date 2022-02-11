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
if ( V_7 == V_22 && V_6 -> V_23 == V_24 )
return 0 ;
if ( ! V_6 -> V_25 [ V_7 ] -> V_26 ) {
if ( V_7 == V_22 )
V_6 -> V_25 [ V_7 ] -> V_26 = 3 ;
else
return - V_17 ;
}
return F_4 ( V_6 , V_2 -> V_8 -> V_20 ,
V_2 -> V_8 -> V_21 ,
V_6 -> V_25 [ V_7 ] -> V_26 ,
V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_27 )
{
unsigned int V_28 = 0 ;
unsigned int V_29 = F_11 ( V_30 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_28 < V_29 && V_30 [ V_28 ] != V_27 )
V_28 ++ ;
if ( V_28 == V_29 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_31 , V_2 -> V_8 -> V_32 ,
V_28 << 2 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_33 , int V_34 )
{
int V_28 = 0 ;
unsigned int V_29 = F_11 ( V_30 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_28 < V_29 && V_30 [ V_28 ] < V_34 )
V_28 ++ ;
V_28 -- ;
if ( V_28 < 0 || V_30 [ V_28 ] < V_33 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_31 , V_2 -> V_8 -> V_32 ,
V_28 << 2 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_35 ;
unsigned int V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_35 = F_14 ( V_6 , V_2 -> V_8 -> V_31 , & V_28 ) ;
if ( V_35 < 0 )
return V_35 ;
V_28 = ( V_28 & V_2 -> V_8 -> V_32 ) >> 2 ;
return V_30 [ V_28 ] ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = F_16 ( V_37 -> V_2 . V_38 ) ;
struct V_39 * V_40 ;
const struct V_41 * V_42 ;
struct V_1 * V_43 ;
const struct V_44 * V_45 ;
struct V_46 V_47 = { } ;
int V_48 , V_4 ;
unsigned int V_49 ;
V_45 = F_17 ( V_50 , & V_37 -> V_2 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_45 -> V_52 ;
V_48 = V_42 -> V_48 ;
V_40 = F_18 ( & V_37 -> V_2 , V_37 -> V_2 . V_53 ,
& V_54 [ V_48 ] ) ;
F_19 ( V_37 , V_6 ) ;
V_6 -> V_25 [ V_48 ] = & V_55 [ V_48 ] ;
V_47 . V_2 = & V_37 -> V_2 ;
V_47 . V_40 = V_40 ;
V_47 . V_56 = V_6 ;
V_47 . V_57 = V_6 -> V_57 ;
V_47 . V_53 = V_37 -> V_2 . V_53 ;
V_43 = F_20 ( & V_37 -> V_2 , & V_54 [ V_48 ] , & V_47 ) ;
if ( F_21 ( V_43 ) ) {
F_22 ( V_6 -> V_2 , L_1 ,
V_37 -> V_58 ) ;
return F_23 ( V_43 ) ;
}
V_4 = F_14 ( V_6 , V_54 [ V_48 ] . V_20 , & V_49 ) ;
if ( V_4 )
return V_4 ;
V_6 -> V_25 [ V_48 ] -> V_26 = V_49 & V_54 [ V_48 ] . V_21 ;
return 0 ;
}
