static inline unsigned int F_1 ( unsigned int V_1 )
{
return V_1 == V_2 ?
V_3 : V_4 ;
}
static int F_2 ( int V_5 )
{
if ( V_5 == V_6 || ( V_5 >= V_7 &&
V_5 <= V_8 ) )
return 0 ;
if ( V_5 >= V_9 && V_5 <= V_10 )
return V_11 ;
if ( V_5 >= V_12 && V_5 <= V_13 )
return V_14 ;
return - V_15 ;
}
static int F_3 ( struct V_16 * V_17 )
{
unsigned int V_18 = V_19 ;
struct V_20 * V_21 = F_4 ( V_17 ) ;
int V_5 = F_5 ( V_17 ) ;
int V_22 = F_2 ( V_5 ) ;
V_21 -> V_23 [ V_5 ] = V_18 ;
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_17 -> V_25 -> V_27 , V_18 << V_22 ) ;
}
static int F_7 ( struct V_16 * V_17 , unsigned int V_1 )
{
struct V_20 * V_21 = F_4 ( V_17 ) ;
int V_5 = F_5 ( V_17 ) ;
unsigned int V_18 ;
int V_22 = F_2 ( V_5 ) ;
switch ( V_1 ) {
case V_4 :
V_18 = V_28 ;
break;
case V_3 :
V_18 = V_2 ;
break;
default:
F_8 ( & V_17 -> V_29 , L_1 ,
V_17 -> V_25 -> V_30 , V_1 ) ;
return - V_15 ;
}
V_21 -> V_23 [ V_5 ] = V_18 ;
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_17 -> V_25 -> V_27 , V_18 << V_22 ) ;
}
static unsigned F_9 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_4 ( V_17 ) ;
int V_5 = F_5 ( V_17 ) ;
return F_1 ( V_21 -> V_23 [ V_5 ] ) ;
}
static int F_10 ( struct V_16 * V_17 ,
unsigned int V_1 )
{
struct V_20 * V_21 = F_4 ( V_17 ) ;
int V_5 = F_5 ( V_17 ) ;
unsigned int V_18 ;
int V_22 = F_2 ( V_5 ) ;
if ( V_21 -> V_23 [ V_5 ] == V_19 ) {
F_8 ( & V_17 -> V_29 , L_2 ,
V_17 -> V_25 -> V_30 , V_1 ) ;
return 0 ;
}
switch ( V_1 ) {
case V_4 :
if ( V_21 -> V_23 [ V_5 ] == V_2 )
V_18 = V_31 ;
else
return 0 ;
break;
case V_3 :
if ( V_21 -> V_23 [ V_5 ] == V_28 )
F_8 ( & V_17 -> V_29 , L_3 ,
V_17 -> V_25 -> V_30 , V_1 ) ;
return 0 ;
default:
F_8 ( & V_17 -> V_29 , L_1 ,
V_17 -> V_25 -> V_30 , V_1 ) ;
return - V_15 ;
}
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_17 -> V_25 -> V_27 , V_18 << V_22 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_4 ( V_17 ) ;
int V_5 = F_5 ( V_17 ) ;
int V_22 = F_2 ( V_5 ) ;
if ( V_21 -> V_23 [ V_5 ] == V_19 )
V_21 -> V_23 [ V_5 ] = V_2 ;
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_17 -> V_25 -> V_27 ,
V_21 -> V_23 [ V_5 ] << V_22 ) ;
}
static int F_12 ( struct V_16 * V_17 ,
const unsigned int V_32 [] , int V_33 ,
unsigned int V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
if ( V_34 <= V_32 [ V_35 ] )
return V_35 ;
}
F_8 ( & V_17 -> V_29 , L_4 ,
V_17 -> V_25 -> V_30 , V_34 ) ;
return V_33 - 1 ;
}
static int F_13 ( struct V_16 * V_17 ,
int V_34 )
{
int V_5 = F_5 ( V_17 ) ;
unsigned int V_36 ;
if ( V_5 > V_10 ) {
F_8 ( & V_17 -> V_29 ,
L_5 ,
V_17 -> V_25 -> V_30 ) ;
return - V_15 ;
}
V_36 = F_12 ( V_17 , V_37 ,
F_14 ( V_37 ) , V_34 ) ;
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_38 ,
V_36 << V_39 ) ;
}
static int F_15 ( struct V_16 * V_17 ,
int V_34 )
{
unsigned int V_36 ;
V_36 = F_12 ( V_17 , V_40 ,
F_14 ( V_40 ) , V_34 ) ;
return F_6 ( V_17 -> V_24 , V_17 -> V_25 -> V_26 ,
V_41 ,
V_36 << V_42 ) ;
}
static int F_16 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_17 ( V_44 -> V_29 . V_47 ) ;
struct V_20 * V_21 ;
int V_35 , V_18 ;
struct V_48 V_49 = { } ;
V_21 = F_18 ( & V_44 -> V_29 ,
sizeof( struct V_20 ) ,
V_50 ) ;
if ( ! V_21 )
return - V_51 ;
V_49 . V_29 = V_46 -> V_29 ;
V_49 . V_24 = V_46 -> V_24 ;
V_49 . V_52 = V_21 ;
F_19 ( V_44 , V_21 ) ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ ) {
struct V_16 * V_17 ;
int V_5 = V_54 [ V_35 ] . V_5 ;
int V_22 = F_2 ( V_5 ) ;
int V_55 ;
V_55 = F_20 ( V_46 -> V_24 , V_54 [ V_35 ] . V_26 , & V_18 ) ;
if ( V_55 < 0 ) {
F_8 ( & V_44 -> V_29 ,
L_6 , V_35 ) ;
V_18 = V_2 ;
} else {
V_18 = V_18 >> V_22 & V_56 ;
}
if ( V_18 == V_57 )
V_21 -> V_23 [ V_5 ] = V_2 ;
else
V_21 -> V_23 [ V_5 ] = V_18 ;
V_17 = F_21 ( & V_44 -> V_29 ,
& V_54 [ V_35 ] , & V_49 ) ;
if ( F_22 ( V_17 ) ) {
V_55 = F_23 ( V_17 ) ;
F_24 ( & V_44 -> V_29 ,
L_7 , V_35 , V_55 ) ;
return V_55 ;
}
}
return 0 ;
}
