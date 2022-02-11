static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_11 = V_7 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_8 -> V_17 ) {
case 0 :
V_14 = V_18 ;
V_16 = F_3 ( V_18 ) ;
break;
default:
V_14 = V_19 ;
V_16 = F_3 ( V_19 ) ;
break;
}
switch ( V_5 ) {
case V_20 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_4 ( V_11 , V_14 [ V_15 ] . V_21 ,
V_14 [ V_15 ] . V_22 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , int V_23 , int V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_27 * V_28 = F_6 ( V_7 ) ;
switch ( V_23 ) {
case V_29 :
return F_7 ( & V_28 -> V_30 [ 0 ] , V_24 , V_25 , V_26 ) ;
case V_31 :
return F_7 ( & V_28 -> V_30 [ 1 ] , V_24 , V_25 , V_26 ) ;
case V_32 :
return F_8 ( & V_28 -> V_30 [ 0 ] , V_24 , V_25 ,
V_26 ) ;
case V_33 :
return F_8 ( & V_28 -> V_30 [ 1 ] , V_24 , V_25 ,
V_26 ) ;
default:
return - V_34 ;
}
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_27 * V_35 = F_6 ( V_7 ) ;
int V_36 ;
V_7 -> V_12 = V_35 -> V_37 . V_8 -> V_11 ;
V_36 = F_10 ( V_7 , 32 , 16 , V_38 ) ;
if ( V_36 != 0 )
return V_36 ;
V_36 = F_11 ( V_7 , V_39 , 2 ) ;
if ( V_36 != 0 )
return V_36 ;
F_12 ( V_7 ) ;
F_13 ( & V_7 -> V_40 , L_1 ) ;
V_35 -> V_37 . V_8 -> V_40 = & V_7 -> V_40 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_27 * V_35 = F_6 ( V_7 ) ;
V_35 -> V_37 . V_8 -> V_40 = NULL ;
return 0 ;
}
static int F_15 ( struct V_41 * V_42 )
{
struct V_8 * V_8 = F_2 ( V_42 -> V_9 . V_10 ) ;
struct V_27 * V_28 ;
int V_15 , V_36 ;
V_28 = F_16 ( & V_42 -> V_9 , sizeof( struct V_27 ) ,
V_43 ) ;
if ( V_28 == NULL )
return - V_44 ;
F_17 ( V_42 , V_28 ) ;
V_28 -> V_37 . V_8 = V_8 ;
V_28 -> V_37 . V_45 = 6 ;
V_28 -> V_37 . V_46 [ 0 ] . V_47 = L_2 ;
V_28 -> V_37 . V_46 [ 0 ] . V_48 = 1 ;
V_28 -> V_37 . V_46 [ 0 ] . type = V_49 ;
V_28 -> V_37 . V_46 [ 0 ] . V_50 = V_51 ;
V_28 -> V_37 . V_46 [ 0 ] . V_9 = V_8 -> V_9 ;
V_28 -> V_37 . V_46 [ 0 ] . V_11 = V_8 -> V_11 ;
V_28 -> V_37 . V_46 [ 0 ] . V_52 = V_53 ;
V_28 -> V_37 . V_46 [ 0 ] . V_54 = F_3 ( V_53 ) ;
V_36 = F_18 ( & V_28 -> V_37 . V_46 [ 0 ] , true ) ;
if ( V_36 != 0 )
return V_36 ;
for ( V_15 = 0 ; V_15 < F_3 ( V_28 -> V_30 ) ; V_15 ++ )
V_28 -> V_30 [ V_15 ] . V_55 = 1 ;
F_19 ( V_8 , 1 , V_56 - 1 ,
V_57 , V_58 ,
& V_28 -> V_30 [ 0 ] ) ;
F_19 ( V_8 , 2 , V_59 - 1 ,
V_60 , V_61 ,
& V_28 -> V_30 [ 1 ] ) ;
F_20 ( V_8 -> V_11 , V_62 ,
V_63 , 0x11 ) ;
F_20 ( V_8 -> V_11 , V_64 ,
V_65 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_66 ) ; V_15 ++ )
F_21 ( & V_28 -> V_37 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_67 ) ; V_15 ++ )
F_20 ( V_8 -> V_11 , V_67 [ V_15 ] ,
V_68 , V_68 ) ;
F_22 ( & V_42 -> V_9 ) ;
F_23 ( & V_42 -> V_9 ) ;
return F_24 ( & V_42 -> V_9 , & V_69 ,
V_66 , F_3 ( V_66 ) ) ;
}
static int F_25 ( struct V_41 * V_42 )
{
F_26 ( & V_42 -> V_9 ) ;
F_27 ( & V_42 -> V_9 ) ;
return 0 ;
}
