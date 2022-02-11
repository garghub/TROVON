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
if ( V_37 -> V_38 & V_39 )
return V_35 ? - V_21 : V_37 -> V_40 ;
return ( ( V_35 < V_37 -> V_41 ) ?
V_37 -> V_42 [ V_35 ] : - V_21 ) ;
}
static int F_20 ( struct V_33 * V_34 , unsigned V_35 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_38 & V_39 )
return - V_21 ;
return F_16 ( V_2 , & V_37 -> V_43 , V_35 ) ;
}
static int F_21 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_38 & V_39 )
return 0 ;
V_22 = F_15 ( V_2 , & V_37 -> V_43 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_22 ( V_22 >= V_37 -> V_41 ) )
return - V_19 ;
return V_22 ;
}
static int F_23 ( struct V_33 * V_34 , int V_44 ,
int V_45 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_38 & V_47 )
return - V_21 ;
for ( V_46 = 0 ; V_46 < V_37 -> V_48 ; V_46 ++ )
if ( V_44 <= V_37 -> V_49 [ V_46 ] &&
V_45 >= V_37 -> V_49 [ V_46 ] )
break;
if ( V_46 >= V_37 -> V_48 )
return - V_21 ;
return F_16 ( V_2 , & V_37 -> V_50 , V_46 ) ;
}
static int F_24 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
if ( V_37 -> V_38 & V_47 )
return V_37 -> V_51 ;
V_22 = F_15 ( V_2 , & V_37 -> V_50 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( F_22 ( V_22 >= V_37 -> V_48 ) )
return - V_19 ;
return V_37 -> V_49 [ V_22 ] ;
}
static int F_25 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_16 ( V_2 , & V_37 -> V_52 , 1 ) ;
}
static int F_26 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_16 ( V_2 , & V_37 -> V_52 , 0 ) ;
}
static int F_27 ( struct V_33 * V_34 )
{
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
V_2 = F_18 ( V_34 ) ;
V_37 = & V_36 [ F_19 ( V_34 ) ] ;
return F_15 ( V_2 , & V_37 -> V_52 ) ;
}
static int F_28 ( struct V_53 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_15 ) ;
int V_46 ;
if ( ! V_2 )
return 0 ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
if ( V_2 -> V_34 [ V_46 ] )
F_30 ( V_2 -> V_34 [ V_46 ] ) ;
V_2 -> V_34 [ V_46 ] = NULL ;
}
F_31 ( V_15 , NULL ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_53 * V_15 )
{
struct V_1 * V_2 ;
struct V_55 * V_16 = & V_15 -> V_16 ;
const struct V_36 * V_37 = V_36 ;
struct V_56 * V_57 ;
struct V_58 V_59 = { } ;
int V_22 = 0 , V_46 ;
V_57 = V_16 -> V_60 ;
if ( ! V_57 ) {
F_14 ( V_16 , L_6 ) ;
return - V_21 ;
}
V_2 = F_33 ( & V_15 -> V_16 , sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_2 ) {
F_14 ( V_16 , L_7 ) ;
return - V_62 ;
}
F_31 ( V_15 , V_2 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_15 = F_34 ( V_15 ) ;
F_35 ( & V_2 -> V_23 ) ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ , V_37 ++ , V_57 ++ ) {
V_2 -> V_63 [ V_46 ] . V_64 = V_37 -> V_64 ;
V_2 -> V_63 [ V_46 ] . V_65 = V_46 ;
V_2 -> V_63 [ V_46 ] . V_41 = V_37 -> V_41 ;
V_2 -> V_63 [ V_46 ] . V_66 = & V_67 ;
V_2 -> V_63 [ V_46 ] . type = V_68 ;
V_2 -> V_63 [ V_46 ] . V_69 = V_70 ;
if ( V_37 -> V_38 & V_39 )
V_2 -> V_63 [ V_46 ] . V_41 = 1 ;
V_59 . V_16 = V_16 ;
V_59 . V_57 = V_57 ;
V_59 . V_71 = V_2 ;
V_2 -> V_34 [ V_46 ] = F_36 ( & V_2 -> V_63 [ V_46 ] , & V_59 ) ;
if ( F_37 ( V_2 -> V_34 [ V_46 ] ) ) {
V_22 = F_38 ( V_2 -> V_34 [ V_46 ] ) ;
V_2 -> V_34 [ V_46 ] = NULL ;
goto V_72;
}
}
return 0 ;
V_72:
F_28 ( V_15 ) ;
return V_22 ;
}
