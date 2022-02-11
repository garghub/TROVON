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
case V_22 :
break;
default:
return 0 ;
}
return F_6 ( V_2 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , int V_23 , int V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_27 * V_28 = F_8 ( V_7 ) ;
switch ( V_23 ) {
case V_29 :
return F_9 ( & V_28 -> V_30 [ 0 ] , V_24 , V_25 , V_26 ) ;
case V_31 :
return F_9 ( & V_28 -> V_30 [ 1 ] , V_24 , V_25 , V_26 ) ;
case V_32 :
return F_10 ( & V_28 -> V_30 [ 0 ] , V_24 , V_25 ,
V_26 ) ;
case V_33 :
return F_10 ( & V_28 -> V_30 [ 1 ] , V_24 , V_25 ,
V_26 ) ;
default:
return - V_34 ;
}
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_35 * V_8 = F_12 ( V_7 ) ;
struct V_27 * V_36 = F_8 ( V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( V_8 , L_1 ) ;
V_36 -> V_37 . V_9 -> V_8 = V_8 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_27 * V_36 = F_8 ( V_7 ) ;
V_36 -> V_37 . V_9 -> V_8 = NULL ;
F_16 ( V_7 ) ;
return 0 ;
}
static struct V_12 * F_17 ( struct V_38 * V_10 )
{
struct V_27 * V_36 = F_3 ( V_10 ) ;
return V_36 -> V_37 . V_9 -> V_12 ;
}
static int F_18 ( struct V_39 * V_40 )
{
struct V_9 * V_9 = F_3 ( V_40 -> V_10 . V_11 ) ;
struct V_27 * V_28 ;
int V_15 ;
V_28 = F_19 ( & V_40 -> V_10 , sizeof( struct V_27 ) ,
V_41 ) ;
if ( V_28 == NULL )
return - V_42 ;
F_20 ( V_40 , V_28 ) ;
V_28 -> V_37 . V_9 = V_9 ;
V_28 -> V_37 . V_43 = 4 ;
F_21 ( & V_28 -> V_37 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_28 -> V_30 ) ; V_15 ++ )
V_28 -> V_30 [ V_15 ] . V_44 = 1 ;
F_22 ( V_9 , 1 , V_45 - 1 ,
V_46 , V_47 ,
& V_28 -> V_30 [ 0 ] ) ;
F_22 ( V_9 , 2 , V_48 - 1 ,
V_49 , V_50 ,
& V_28 -> V_30 [ 1 ] ) ;
F_23 ( V_9 -> V_12 , V_51 ,
V_52 , 0x11 ) ;
F_23 ( V_9 -> V_12 , V_53 ,
V_54 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_55 ) ; V_15 ++ )
F_24 ( & V_28 -> V_37 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_56 ) ; V_15 ++ )
F_23 ( V_9 -> V_12 , V_56 [ V_15 ] ,
V_57 , V_57 ) ;
F_25 ( & V_40 -> V_10 ) ;
F_26 ( & V_40 -> V_10 ) ;
return F_27 ( & V_40 -> V_10 , & V_58 ,
V_55 , F_4 ( V_55 ) ) ;
}
static int F_28 ( struct V_39 * V_40 )
{
F_29 ( & V_40 -> V_10 ) ;
F_30 ( & V_40 -> V_10 ) ;
return 0 ;
}
