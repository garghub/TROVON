static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_11 = V_8 -> V_11 ;
const struct V_12 * V_13 = NULL ;
int V_14 , V_15 ;
switch ( V_8 -> V_16 ) {
case 3 :
V_13 = V_17 ;
V_15 = F_3 ( V_17 ) ;
break;
default:
return 0 ;
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
int V_34 ;
V_33 -> V_35 . V_8 -> V_36 = & V_7 -> V_36 ;
V_34 = F_10 ( V_7 , V_33 -> V_35 . V_8 -> V_11 ) ;
if ( V_34 != 0 )
return V_34 ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
V_34 = F_13 ( V_7 , V_37 , 8 ) ;
if ( V_34 != 0 )
return V_34 ;
F_14 ( & V_7 -> V_36 , L_1 ) ;
V_33 -> V_35 . V_8 -> V_36 = & V_7 -> V_36 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_25 * V_33 = F_6 ( V_7 ) ;
V_33 -> V_35 . V_8 -> V_36 = NULL ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 )
{
struct V_8 * V_8 = F_2 ( V_39 -> V_9 . V_10 ) ;
struct V_25 * V_26 ;
int V_14 , V_34 ;
V_26 = F_17 ( & V_39 -> V_9 , sizeof( struct V_25 ) ,
V_40 ) ;
if ( V_26 == NULL )
return - V_41 ;
F_18 ( V_39 , V_26 ) ;
V_26 -> V_35 . V_8 = V_8 ;
V_26 -> V_35 . V_42 = 8 ;
for ( V_14 = 0 ; V_14 < V_43 ; V_14 ++ ) {
V_26 -> V_35 . V_44 [ V_14 ] . V_45 = L_2 ;
V_26 -> V_35 . V_44 [ V_14 ] . V_46 = V_14 + 1 ;
V_26 -> V_35 . V_44 [ V_14 ] . type = V_47 ;
V_26 -> V_35 . V_44 [ V_14 ] . V_9 = V_8 -> V_9 ;
V_26 -> V_35 . V_44 [ V_14 ] . V_11 = V_8 -> V_11 ;
V_26 -> V_35 . V_44 [ V_14 ] . V_48 = V_49
+ ( 0x100 * V_14 ) ;
V_26 -> V_35 . V_44 [ V_14 ] . V_50 = V_51 [ V_14 ] ;
V_26 -> V_35 . V_44 [ V_14 ] . V_52
= F_3 ( V_53 ) ;
V_34 = F_19 ( & V_26 -> V_35 . V_44 [ V_14 ] , false ) ;
if ( V_34 != 0 )
return V_34 ;
}
for ( V_14 = 0 ; V_14 < F_3 ( V_26 -> V_28 ) ; V_14 ++ )
V_26 -> V_28 [ V_14 ] . V_54 = 3 ;
F_20 ( V_8 , 1 , V_55 - 1 ,
V_56 , V_57 ,
& V_26 -> V_28 [ 0 ] ) ;
F_20 ( V_8 , 2 , V_58 - 1 ,
V_59 , V_60 ,
& V_26 -> V_28 [ 1 ] ) ;
F_21 ( V_8 -> V_11 , V_61 ,
V_62 , 0x11 ) ;
F_21 ( V_8 -> V_11 , V_63 ,
V_64 , 0x12 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_65 ) ; V_14 ++ )
F_22 ( & V_26 -> V_35 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_66 ) ; V_14 ++ )
F_21 ( V_8 -> V_11 , V_66 [ V_14 ] ,
V_67 , V_67 ) ;
F_23 ( & V_39 -> V_9 ) ;
F_24 ( & V_39 -> V_9 ) ;
return F_25 ( & V_39 -> V_9 , & V_68 ,
V_65 , F_3 ( V_65 ) ) ;
}
static int F_26 ( struct V_38 * V_39 )
{
F_27 ( & V_39 -> V_9 ) ;
F_28 ( & V_39 -> V_9 ) ;
return 0 ;
}
