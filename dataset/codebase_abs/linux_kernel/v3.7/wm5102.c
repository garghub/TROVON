static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 ) ;
struct V_10 * V_10 = V_7 -> V_11 ;
const struct V_12 * V_13 = NULL ;
int V_14 , V_15 ;
switch ( V_8 -> V_16 ) {
case 0 :
V_13 = V_17 ;
V_15 = F_3 ( V_17 ) ;
break;
}
switch ( V_5 ) {
case V_18 :
if ( V_13 )
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_4 ( V_10 , V_13 [ V_14 ] . V_19 ,
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
default:
return - V_30 ;
}
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_25 * V_31 = F_6 ( V_7 ) ;
V_7 -> V_11 = V_31 -> V_32 . V_8 -> V_10 ;
return F_9 ( V_7 , 32 , 16 , V_33 ) ;
}
static int T_1 F_10 ( struct V_34 * V_35 )
{
struct V_8 * V_8 = F_2 ( V_35 -> V_9 . V_36 ) ;
struct V_25 * V_26 ;
int V_14 ;
V_26 = F_11 ( & V_35 -> V_9 , sizeof( struct V_25 ) ,
V_37 ) ;
if ( V_26 == NULL )
return - V_38 ;
F_12 ( V_35 , V_26 ) ;
V_26 -> V_32 . V_8 = V_8 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_26 -> V_28 ) ; V_14 ++ )
V_26 -> V_28 [ V_14 ] . V_39 = 1 ;
F_13 ( V_8 , 1 , V_40 - 1 ,
V_41 , V_42 ,
& V_26 -> V_28 [ 0 ] ) ;
F_13 ( V_8 , 2 , V_43 - 1 ,
V_44 , V_45 ,
& V_26 -> V_28 [ 1 ] ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_46 ) ; V_14 ++ )
F_14 ( & V_26 -> V_32 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_47 ) ; V_14 ++ )
F_15 ( V_8 -> V_10 , V_47 [ V_14 ] ,
V_48 , V_48 ) ;
F_16 ( & V_35 -> V_9 ) ;
F_17 ( & V_35 -> V_9 ) ;
return F_18 ( & V_35 -> V_9 , & V_49 ,
V_46 , F_3 ( V_46 ) ) ;
}
static int T_2 F_19 ( struct V_34 * V_35 )
{
F_20 ( & V_35 -> V_9 ) ;
F_21 ( & V_35 -> V_9 ) ;
return 0 ;
}
