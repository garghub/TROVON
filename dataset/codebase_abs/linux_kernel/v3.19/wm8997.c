static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_11 = V_8 -> V_11 ;
const struct V_12 * V_13 = NULL ;
int V_14 , V_15 ;
switch ( V_8 -> V_16 ) {
case 0 :
V_13 = V_17 ;
V_15 = F_3 ( V_17 ) ;
break;
default:
break;
}
switch ( V_5 ) {
case V_18 :
if ( V_13 )
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_4 ( V_11 , V_13 [ V_14 ] . V_19 ,
V_13 [ V_14 ] . V_20 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , int V_21 , int V_22 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_25 * V_26 = F_6 ( V_7 ) ;
switch ( V_21 ) {
case V_27 :
return F_7 ( & V_26 -> V_28 [ 0 ] , V_22 , V_23 , V_24 ) ;
case V_29 :
return F_7 ( & V_26 -> V_28 [ 1 ] , V_22 , V_23 , V_24 ) ;
case V_30 :
return F_8 ( & V_26 -> V_28 [ 0 ] , V_22 , V_23 ,
V_24 ) ;
case V_31 :
return F_8 ( & V_26 -> V_28 [ 1 ] , V_22 , V_23 ,
V_24 ) ;
default:
return - V_32 ;
}
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_25 * V_33 = F_6 ( V_7 ) ;
F_10 ( V_7 ) ;
F_11 ( & V_7 -> V_34 , L_1 ) ;
V_33 -> V_35 . V_8 -> V_34 = & V_7 -> V_34 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_25 * V_33 = F_6 ( V_7 ) ;
V_33 -> V_35 . V_8 -> V_34 = NULL ;
return 0 ;
}
static struct V_11 * F_13 ( struct V_36 * V_9 )
{
struct V_25 * V_33 = F_2 ( V_9 ) ;
return V_33 -> V_35 . V_8 -> V_11 ;
}
static int F_14 ( struct V_37 * V_38 )
{
struct V_8 * V_8 = F_2 ( V_38 -> V_9 . V_10 ) ;
struct V_25 * V_26 ;
int V_14 ;
V_26 = F_15 ( & V_38 -> V_9 , sizeof( struct V_25 ) ,
V_39 ) ;
if ( V_26 == NULL )
return - V_40 ;
F_16 ( V_38 , V_26 ) ;
V_26 -> V_35 . V_8 = V_8 ;
V_26 -> V_35 . V_41 = 4 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_26 -> V_28 ) ; V_14 ++ )
V_26 -> V_28 [ V_14 ] . V_42 = 1 ;
F_17 ( V_8 , 1 , V_43 - 1 ,
V_44 , V_45 ,
& V_26 -> V_28 [ 0 ] ) ;
F_17 ( V_8 , 2 , V_46 - 1 ,
V_47 , V_48 ,
& V_26 -> V_28 [ 1 ] ) ;
F_18 ( V_8 -> V_11 , V_49 ,
V_50 , 0x11 ) ;
F_18 ( V_8 -> V_11 , V_51 ,
V_52 , 0x12 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_53 ) ; V_14 ++ )
F_19 ( & V_26 -> V_35 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_54 ) ; V_14 ++ )
F_18 ( V_8 -> V_11 , V_54 [ V_14 ] ,
V_55 , V_55 ) ;
F_20 ( & V_38 -> V_9 ) ;
F_21 ( & V_38 -> V_9 ) ;
return F_22 ( & V_38 -> V_9 , & V_56 ,
V_53 , F_3 ( V_53 ) ) ;
}
static int F_23 ( struct V_37 * V_38 )
{
F_24 ( & V_38 -> V_9 ) ;
F_25 ( & V_38 -> V_9 ) ;
return 0 ;
}
