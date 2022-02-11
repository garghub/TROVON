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
if ( ! V_6 -> V_25 [ V_7 ] ) {
if ( V_7 == V_22 )
V_6 -> V_26 [ V_7 ] -> V_27 = 3 ;
else
return - V_17 ;
}
return F_4 ( V_6 , V_2 -> V_8 -> V_20 ,
V_2 -> V_8 -> V_21 ,
V_6 -> V_25 [ V_7 ] , V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_28 )
{
unsigned int V_29 = 0 ;
unsigned int V_30 = F_11 ( V_31 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_29 < V_30 && V_31 [ V_29 ] != V_28 )
V_29 ++ ;
if ( V_29 == V_30 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_32 , V_2 -> V_8 -> V_33 ,
V_29 << 2 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_34 , int V_35 )
{
int V_29 = 0 ;
unsigned int V_30 = F_11 ( V_31 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_29 < V_30 && V_31 [ V_29 ] < V_35 )
V_29 ++ ;
V_29 -- ;
if ( V_29 < 0 || V_31 [ V_29 ] < V_34 )
return - V_17 ;
return F_4 ( V_6 , V_2 -> V_8 -> V_32 , V_2 -> V_8 -> V_33 ,
V_29 << 2 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_36 ;
unsigned int V_29 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_36 = F_14 ( V_6 -> V_37 , V_2 -> V_8 -> V_32 , & V_29 ) ;
if ( V_36 < 0 )
return V_36 ;
V_29 = ( V_29 & V_2 -> V_8 -> V_33 ) >> 2 ;
return V_31 [ V_29 ] ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_16 ( V_39 -> V_2 . V_40 ) ;
struct V_1 * V_41 ;
struct V_42 V_43 = { } ;
int V_44 , V_4 ;
unsigned int V_45 ;
V_43 . V_2 = & V_39 -> V_2 ;
V_43 . V_2 -> V_46 = V_6 -> V_2 -> V_46 ;
V_43 . V_47 = V_6 ;
V_43 . V_37 = V_6 -> V_37 ;
V_6 -> V_25 = F_17 ( & V_39 -> V_2 , sizeof( V_48 ) *
V_49 , V_50 ) ;
for ( V_44 = 0 ; V_44 < F_11 ( V_51 ) ; V_44 ++ ) {
V_41 = F_18 ( & V_39 -> V_2 , & V_51 [ V_44 ] ,
& V_43 ) ;
if ( F_19 ( V_41 ) ) {
F_20 ( V_6 -> V_2 , L_1 ,
V_39 -> V_52 ) ;
return F_21 ( V_41 ) ;
}
V_4 = F_14 ( V_6 -> V_37 , V_51 [ V_44 ] . V_20 , & V_45 ) ;
if ( V_4 )
return V_4 ;
V_6 -> V_25 [ V_44 ] = V_45 & V_51 [ V_44 ] . V_21 ;
}
return 0 ;
}
