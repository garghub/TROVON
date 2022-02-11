static int F_1 ( int V_1 )
{
if ( V_1 == V_2 || ( V_1 >= V_3 &&
V_1 <= V_4 ) )
return 0 ;
if ( V_1 >= V_5 && V_1 <= V_6 )
return V_7 ;
if ( V_1 >= V_8 && V_1 <= V_9 )
return V_10 ;
return - V_11 ;
}
static int F_2 ( struct V_12 * V_13 )
{
unsigned int V_14 = V_15 ;
struct V_16 * V_17 = F_3 ( V_13 ) ;
int V_1 = F_4 ( V_13 ) ;
int V_18 = F_1 ( V_1 ) ;
V_17 -> V_19 [ V_1 ] = V_14 ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_13 -> V_21 -> V_23 , V_14 << V_18 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
unsigned int V_24 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
int V_1 = F_4 ( V_13 ) ;
unsigned int V_14 ;
int V_18 = F_1 ( V_1 ) ;
switch ( V_24 ) {
case V_25 :
V_14 = V_26 ;
break;
case V_27 :
V_14 = V_28 ;
break;
case V_29 :
V_14 = V_15 ;
break;
default:
F_7 ( & V_13 -> V_30 , L_1 ,
V_13 -> V_21 -> V_31 , V_24 ) ;
return - V_11 ;
}
V_17 -> V_19 [ V_1 ] = V_14 ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_13 -> V_21 -> V_23 , V_14 << V_18 ) ;
}
static int F_8 ( struct V_12 * V_13 ,
unsigned int V_24 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
int V_1 = F_4 ( V_13 ) ;
unsigned int V_14 ;
int V_18 = F_1 ( V_1 ) ;
switch ( V_24 ) {
case V_25 :
V_14 = V_26 ;
break;
case V_27 :
V_14 = V_28 ;
break;
default:
F_7 ( & V_13 -> V_30 , L_1 ,
V_13 -> V_21 -> V_31 , V_24 ) ;
return - V_11 ;
}
V_17 -> V_19 [ V_1 ] = V_14 ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_13 -> V_21 -> V_23 , V_14 << V_18 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_3 ( V_13 ) ;
int V_1 = F_4 ( V_13 ) ;
int V_18 = F_1 ( V_1 ) ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_13 -> V_21 -> V_23 ,
V_17 -> V_19 [ V_1 ] << V_18 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
const unsigned int V_32 [] , int V_33 ,
unsigned int V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
if ( V_34 <= V_32 [ V_35 ] )
return V_35 ;
}
F_7 ( & V_13 -> V_30 , L_2 ,
V_13 -> V_21 -> V_31 , V_34 ) ;
return V_33 - 1 ;
}
static int F_11 ( struct V_12 * V_13 ,
int V_34 )
{
int V_1 = F_4 ( V_13 ) ;
unsigned int V_36 ;
if ( V_1 > V_6 ) {
F_7 ( & V_13 -> V_30 ,
L_3 ,
V_13 -> V_21 -> V_31 ) ;
return - V_11 ;
}
V_36 = F_10 ( V_13 , V_37 ,
F_12 ( V_37 ) , V_34 ) ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_38 ,
V_36 << V_39 ) ;
}
static int F_13 ( struct V_12 * V_13 ,
int V_34 )
{
unsigned int V_36 ;
V_36 = F_10 ( V_13 , V_40 ,
F_12 ( V_40 ) , V_34 ) ;
return F_5 ( V_13 -> V_20 , V_13 -> V_21 -> V_22 ,
V_41 ,
V_36 << V_42 ) ;
}
static int F_14 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = F_15 ( V_44 -> V_30 . V_49 ) ;
struct V_50 * V_51 , * V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 = { } ;
unsigned int V_35 ;
V_51 = V_48 -> V_30 -> V_57 ;
V_52 = F_16 ( V_51 , L_4 ) ;
if ( ! V_52 ) {
F_17 ( & V_44 -> V_30 , L_5 ) ;
return - V_11 ;
}
V_46 -> V_58 = F_12 ( V_59 ) ;
V_54 = F_18 ( & V_44 -> V_30 , sizeof( * V_54 ) *
V_46 -> V_58 , V_60 ) ;
if ( ! V_54 ) {
F_19 ( V_52 ) ;
return - V_61 ;
}
for ( V_35 = 0 ; V_35 < V_46 -> V_58 ; V_35 ++ ) {
V_56 . V_31 = V_59 [ V_35 ] . V_31 ;
V_56 . V_62 = NULL ;
V_56 . V_57 = NULL ;
if ( V_55 ( & V_44 -> V_30 , V_52 , & V_56 ,
1 ) != 1 ) {
F_7 ( & V_44 -> V_30 , L_6 ,
V_56 . V_31 ) ;
continue;
}
V_54 [ V_35 ] . V_63 = V_56 . V_62 ;
V_54 [ V_35 ] . V_57 = V_56 . V_57 ;
V_54 [ V_35 ] . V_1 = V_59 [ V_35 ] . V_1 ;
}
V_46 -> V_59 = V_54 ;
F_19 ( V_52 ) ;
return 0 ;
}
static int F_14 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
return 0 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_47 * V_48 = F_15 ( V_44 -> V_30 . V_49 ) ;
struct V_45 * V_46 = F_21 ( V_48 -> V_30 ) ;
struct V_16 * V_17 ;
int V_35 , V_64 = 0 , V_14 ;
struct V_65 V_66 = { } ;
if ( ! V_46 ) {
F_17 ( & V_44 -> V_30 , L_7 ) ;
return - V_67 ;
}
V_17 = F_18 ( & V_44 -> V_30 ,
sizeof( struct V_16 ) ,
V_60 ) ;
if ( ! V_17 )
return - V_61 ;
if ( V_48 -> V_30 -> V_57 ) {
V_64 = F_14 ( V_44 , V_46 ) ;
if ( V_64 )
return V_64 ;
}
V_66 . V_30 = V_48 -> V_30 ;
V_66 . V_20 = V_48 -> V_20 ;
V_66 . V_68 = V_17 ;
F_22 ( V_44 , V_17 ) ;
for ( V_35 = 0 ; V_35 < V_69 ; V_35 ++ ) {
struct V_12 * V_13 ;
int V_1 = V_46 -> V_59 [ V_35 ] . V_1 ;
int V_18 = F_1 ( V_1 ) ;
V_66 . V_62 = V_46 -> V_59 [ V_35 ] . V_63 ;
V_66 . V_57 = V_46 -> V_59 [ V_35 ] . V_57 ;
V_64 = F_23 ( V_48 -> V_20 , V_59 [ V_35 ] . V_22 , & V_14 ) ;
V_14 = V_14 >> V_18 & V_70 ;
if ( V_14 == V_71 )
V_17 -> V_19 [ V_1 ] = V_28 ;
else
V_17 -> V_19 [ V_1 ] = V_14 ;
V_13 = F_24 ( & V_44 -> V_30 ,
& V_59 [ V_35 ] , & V_66 ) ;
if ( F_25 ( V_13 ) ) {
F_17 ( & V_44 -> V_30 ,
L_8 , V_35 ) ;
return F_26 ( V_13 ) ;
}
}
return 0 ;
}
