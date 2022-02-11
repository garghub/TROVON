static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_9 -> V_17 ) {
case 0 :
V_14 = V_18 ;
V_16 = F_4 ( V_18 ) ;
break;
default:
break;
}
switch ( V_5 ) {
case V_19 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_5 ( V_12 , V_14 [ V_15 ] . V_20 ,
V_14 [ V_15 ] . V_21 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_6 * V_7 , int V_22 , int V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_26 * V_27 = F_7 ( V_7 ) ;
switch ( V_22 ) {
case V_28 :
return F_8 ( & V_27 -> V_29 [ 0 ] , V_23 , V_24 , V_25 ) ;
case V_30 :
return F_8 ( & V_27 -> V_29 [ 1 ] , V_23 , V_24 , V_25 ) ;
case V_31 :
return F_9 ( & V_27 -> V_29 [ 0 ] , V_23 , V_24 ,
V_25 ) ;
case V_32 :
return F_9 ( & V_27 -> V_29 [ 1 ] , V_23 , V_24 ,
V_25 ) ;
default:
return - V_33 ;
}
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_7 ( V_7 ) ;
F_11 ( V_7 ) ;
F_12 ( & V_7 -> V_8 , L_1 ) ;
V_34 -> V_35 . V_9 -> V_8 = & V_7 -> V_8 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_7 ( V_7 ) ;
V_34 -> V_35 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_14 ( struct V_36 * V_10 )
{
struct V_26 * V_34 = F_3 ( V_10 ) ;
return V_34 -> V_35 . V_9 -> V_12 ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_9 * V_9 = F_3 ( V_38 -> V_10 . V_11 ) ;
struct V_26 * V_27 ;
int V_15 ;
V_27 = F_16 ( & V_38 -> V_10 , sizeof( struct V_26 ) ,
V_39 ) ;
if ( V_27 == NULL )
return - V_40 ;
F_17 ( V_38 , V_27 ) ;
V_27 -> V_35 . V_9 = V_9 ;
V_27 -> V_35 . V_41 = 4 ;
for ( V_15 = 0 ; V_15 < F_4 ( V_27 -> V_29 ) ; V_15 ++ )
V_27 -> V_29 [ V_15 ] . V_42 = 1 ;
F_18 ( V_9 , 1 , V_43 - 1 ,
V_44 , V_45 ,
& V_27 -> V_29 [ 0 ] ) ;
F_18 ( V_9 , 2 , V_46 - 1 ,
V_47 , V_48 ,
& V_27 -> V_29 [ 1 ] ) ;
F_19 ( V_9 -> V_12 , V_49 ,
V_50 , 0x11 ) ;
F_19 ( V_9 -> V_12 , V_51 ,
V_52 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_53 ) ; V_15 ++ )
F_20 ( & V_27 -> V_35 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_54 ) ; V_15 ++ )
F_19 ( V_9 -> V_12 , V_54 [ V_15 ] ,
V_55 , V_55 ) ;
F_21 ( & V_38 -> V_10 ) ;
F_22 ( & V_38 -> V_10 ) ;
return F_23 ( & V_38 -> V_10 , & V_56 ,
V_53 , F_4 ( V_53 ) ) ;
}
static int F_24 ( struct V_37 * V_38 )
{
F_25 ( & V_38 -> V_10 ) ;
F_26 ( & V_38 -> V_10 ) ;
return 0 ;
}
