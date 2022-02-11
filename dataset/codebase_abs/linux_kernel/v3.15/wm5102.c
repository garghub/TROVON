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
V_13 = V_18 ;
V_15 = F_3 ( V_18 ) ;
break;
}
switch ( V_5 ) {
case V_19 :
if ( V_13 )
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_4 ( V_11 , V_13 [ V_14 ] . V_20 ,
V_13 [ V_14 ] . V_21 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , int V_22 , int V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_26 * V_27 = F_6 ( V_7 ) ;
switch ( V_22 ) {
case V_28 :
return F_7 ( & V_27 -> V_29 [ 0 ] , V_23 , V_24 , V_25 ) ;
case V_30 :
return F_7 ( & V_27 -> V_29 [ 1 ] , V_23 , V_24 , V_25 ) ;
case V_31 :
return F_8 ( & V_27 -> V_29 [ 0 ] , V_23 , V_24 ,
V_25 ) ;
case V_32 :
return F_8 ( & V_27 -> V_29 [ 1 ] , V_23 , V_24 ,
V_25 ) ;
default:
return - V_33 ;
}
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_6 ( V_7 ) ;
int V_35 ;
V_35 = F_10 ( V_7 , V_34 -> V_36 . V_8 -> V_11 ) ;
if ( V_35 != 0 )
return V_35 ;
V_35 = F_11 ( V_7 , V_37 , 2 ) ;
if ( V_35 != 0 )
return V_35 ;
F_12 ( V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( & V_7 -> V_38 , L_1 ) ;
V_34 -> V_36 . V_8 -> V_38 = & V_7 -> V_38 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_6 ( V_7 ) ;
V_34 -> V_36 . V_8 -> V_38 = NULL ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 )
{
struct V_8 * V_8 = F_2 ( V_40 -> V_9 . V_10 ) ;
struct V_26 * V_27 ;
int V_14 , V_35 ;
V_27 = F_17 ( & V_40 -> V_9 , sizeof( struct V_26 ) ,
V_41 ) ;
if ( V_27 == NULL )
return - V_42 ;
F_18 ( V_40 , V_27 ) ;
V_27 -> V_36 . V_8 = V_8 ;
V_27 -> V_36 . V_43 = 6 ;
V_27 -> V_36 . V_44 [ 0 ] . V_45 = L_2 ;
V_27 -> V_36 . V_44 [ 0 ] . V_46 = 1 ;
V_27 -> V_36 . V_44 [ 0 ] . type = V_47 ;
V_27 -> V_36 . V_44 [ 0 ] . V_48 = V_49 ;
V_27 -> V_36 . V_44 [ 0 ] . V_9 = V_8 -> V_9 ;
V_27 -> V_36 . V_44 [ 0 ] . V_11 = V_8 -> V_11 ;
V_27 -> V_36 . V_44 [ 0 ] . V_50 = V_51 ;
V_27 -> V_36 . V_44 [ 0 ] . V_52 = F_3 ( V_51 ) ;
V_35 = F_19 ( & V_27 -> V_36 . V_44 [ 0 ] , true ) ;
if ( V_35 != 0 )
return V_35 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_27 -> V_29 ) ; V_14 ++ )
V_27 -> V_29 [ V_14 ] . V_53 = 1 ;
F_20 ( V_8 , 1 , V_54 - 1 ,
V_55 , V_56 ,
& V_27 -> V_29 [ 0 ] ) ;
F_20 ( V_8 , 2 , V_57 - 1 ,
V_58 , V_59 ,
& V_27 -> V_29 [ 1 ] ) ;
F_21 ( V_8 -> V_11 , V_60 ,
V_61 , 0x11 ) ;
F_21 ( V_8 -> V_11 , V_62 ,
V_63 , 0x12 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_64 ) ; V_14 ++ )
F_22 ( & V_27 -> V_36 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_65 ) ; V_14 ++ )
F_21 ( V_8 -> V_11 , V_65 [ V_14 ] ,
V_66 , V_66 ) ;
F_23 ( & V_40 -> V_9 ) ;
F_24 ( & V_40 -> V_9 ) ;
return F_25 ( & V_40 -> V_9 , & V_67 ,
V_64 , F_3 ( V_64 ) ) ;
}
static int F_26 ( struct V_39 * V_40 )
{
F_27 ( & V_40 -> V_9 ) ;
F_28 ( & V_40 -> V_9 ) ;
return 0 ;
}
