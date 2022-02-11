static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int error = 0 ;
T_1 V_4 = F_2 ( V_3 ) , V_5 ;
T_2 V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 [ 3 ] ;
F_3 ( & V_8 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 0 ] . V_11 = & V_4 ;
V_10 [ 0 ] . V_12 = 2 ;
V_10 [ 0 ] . V_13 = 12 ;
F_4 ( & V_10 [ 0 ] , & V_8 ) ;
V_10 [ 1 ] . V_14 = & V_5 ;
V_10 [ 1 ] . V_12 = 2 ;
V_10 [ 1 ] . V_13 = 16 ;
F_4 ( & V_10 [ 1 ] , & V_8 ) ;
V_10 [ 2 ] . V_14 = & V_6 ;
V_10 [ 2 ] . V_12 = 1 ;
V_10 [ 2 ] . V_13 = 4 ;
F_4 ( & V_10 [ 2 ] , & V_8 ) ;
error = F_5 ( V_2 -> V_15 , & V_8 ) ;
if ( error < 0 )
return error ;
F_6 ( V_2 -> V_16 , L_1 ,
V_3 , V_5 , V_6 ) ;
if ( ! ( V_6 & V_17 ) || ( V_6 & V_18 ) )
return - V_19 ;
if ( V_6 & V_20 )
return - V_21 ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
int V_22 ;
F_8 ( & V_2 -> V_23 ) ;
V_22 = F_1 ( V_2 , V_3 ) ;
F_9 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_24 )
{
int error = 0 ;
T_1 V_4 = F_11 ( V_3 ) , V_25 = V_24 ;
T_2 V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 [ 3 ] ;
F_3 ( & V_8 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 0 ] . V_11 = & V_4 ;
V_10 [ 0 ] . V_12 = 2 ;
V_10 [ 0 ] . V_13 = 12 ;
F_4 ( & V_10 [ 0 ] , & V_8 ) ;
V_10 [ 1 ] . V_11 = & V_25 ;
V_10 [ 1 ] . V_12 = 2 ;
V_10 [ 1 ] . V_13 = 16 ;
F_4 ( & V_10 [ 1 ] , & V_8 ) ;
V_10 [ 2 ] . V_14 = & V_6 ;
V_10 [ 2 ] . V_12 = 1 ;
V_10 [ 2 ] . V_13 = 4 ;
F_4 ( & V_10 [ 2 ] , & V_8 ) ;
error = F_5 ( V_2 -> V_15 , & V_8 ) ;
if ( error < 0 )
return error ;
F_6 ( V_2 -> V_16 , L_2 ,
V_3 , V_25 , V_6 ) ;
if ( ! ( V_6 & V_17 ) || ! ( V_6 & V_18 ) )
return - V_19 ;
if ( V_6 & ( V_20 | V_26 ) )
return - V_21 ;
return error ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 , int V_27 , int V_24 )
{
int V_22 ;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 &= ~ V_27 ;
V_22 |= V_24 ;
V_22 = F_10 ( V_2 , V_3 , V_22 ) ;
return ( V_22 < 0 ) ? V_22 : 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 , int V_27 , int V_24 )
{
int V_22 ;
F_8 ( & V_2 -> V_23 ) ;
V_22 = F_10 ( V_2 , V_28 , 1 ) ;
if ( V_22 ) {
F_14 ( V_2 -> V_16 , L_3 ) ;
goto error;
}
V_22 = F_12 ( V_2 , V_3 , V_27 , V_24 ) ;
if ( V_22 )
F_14 ( V_2 -> V_16 , L_4 , V_3 ) ;
V_22 = F_10 ( V_2 , V_28 , 0 ) ;
if ( V_22 ) {
F_14 ( V_2 -> V_16 , L_5 ) ;
goto error;
}
error:
F_9 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_29 * V_29 )
{
int V_30 ;
V_30 = F_7 ( V_2 , V_29 -> V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return ( V_30 >> V_29 -> V_31 ) & V_29 -> V_27 ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_29 * V_29 ,
int V_24 )
{
if ( V_24 & ~ V_29 -> V_27 )
return - V_32 ;
return F_13 ( V_2 , V_29 -> V_3 ,
V_29 -> V_27 << V_29 -> V_31 ,
V_24 << V_29 -> V_31 ) ;
}
static int F_17 ( struct V_33 * V_34 , unsigned V_35 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_34 -> V_38 -> V_39 == 1 )
return - V_21 ;
return F_16 ( V_2 , & V_37 -> V_40 , V_35 ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_34 -> V_38 -> V_39 == 1 )
return 0 ;
V_22 = F_15 ( V_2 , & V_37 -> V_40 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_21 ( V_22 >= V_37 -> V_39 ) )
return - V_19 ;
return V_22 ;
}
static int F_22 ( struct V_33 * V_34 , int V_41 ,
int V_42 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_44 == 1 )
return - V_21 ;
for ( V_43 = V_37 -> V_44 - 1 ; V_43 >= 0 ; V_43 -- ) {
if ( V_41 <= V_37 -> V_45 [ V_43 ] &&
V_42 >= V_37 -> V_45 [ V_43 ] )
return F_16 ( V_2 , & V_37 -> V_46 , V_43 ) ;
}
return - V_21 ;
}
static int F_23 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_44 == 1 )
return V_37 -> V_45 [ 0 ] ;
V_22 = F_15 ( V_2 , & V_37 -> V_46 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_21 ( V_22 >= V_37 -> V_44 ) )
return - V_19 ;
return V_37 -> V_45 [ V_22 ] ;
}
static int F_24 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_16 ( V_2 , & V_37 -> V_47 , 1 ) ;
}
static int F_25 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_16 ( V_2 , & V_37 -> V_47 , 0 ) ;
}
static int F_26 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_15 ( V_2 , & V_37 -> V_47 ) ;
}
static int F_27 ( struct V_48 * V_15 )
{
struct V_1 * V_2 ;
struct V_49 * V_16 = & V_15 -> V_16 ;
const struct V_36 * V_37 = V_36 ;
struct V_50 * V_51 ;
struct V_52 V_53 = { } ;
int V_43 ;
V_51 = F_28 ( V_16 ) ;
if ( ! V_51 ) {
F_14 ( V_16 , L_6 ) ;
return - V_21 ;
}
V_2 = F_29 ( & V_15 -> V_16 , sizeof( struct V_1 ) , V_54 ) ;
if ( ! V_2 ) {
F_14 ( V_16 , L_7 ) ;
return - V_55 ;
}
F_30 ( V_15 , V_2 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_15 = F_31 ( V_15 ) ;
F_32 ( & V_2 -> V_23 ) ;
for ( V_43 = 0 ; V_43 < V_56 ; V_43 ++ , V_37 ++ , V_51 ++ ) {
V_2 -> V_38 [ V_43 ] . V_57 = V_37 -> V_57 ;
V_2 -> V_38 [ V_43 ] . V_58 = V_43 ;
V_2 -> V_38 [ V_43 ] . V_39 = V_37 -> V_39 ;
V_2 -> V_38 [ V_43 ] . V_59 = V_37 -> V_60 ;
V_2 -> V_38 [ V_43 ] . V_61 = & V_62 ;
V_2 -> V_38 [ V_43 ] . type = V_63 ;
V_2 -> V_38 [ V_43 ] . V_64 = V_65 ;
V_53 . V_16 = V_16 ;
V_53 . V_51 = V_51 ;
V_53 . V_66 = V_2 ;
V_2 -> V_34 [ V_43 ] = F_33 ( V_16 , & V_2 -> V_38 [ V_43 ] ,
& V_53 ) ;
if ( F_34 ( V_2 -> V_34 [ V_43 ] ) )
return F_35 ( V_2 -> V_34 [ V_43 ] ) ;
}
return 0 ;
}
