static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_11 * V_11 = V_7 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_8 -> V_17 ) {
case 3 :
V_14 = V_18 ;
V_16 = F_3 ( V_18 ) ;
break;
default:
return 0 ;
}
switch ( V_5 ) {
case V_19 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_4 ( V_11 , V_14 [ V_15 ] . V_20 ,
V_14 [ V_15 ] . V_21 ) ;
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
V_7 -> V_12 = V_34 -> V_36 . V_8 -> V_11 ;
V_34 -> V_36 . V_8 -> V_37 = & V_7 -> V_37 ;
V_35 = F_10 ( V_7 , 32 , 16 , V_38 ) ;
if ( V_35 != 0 )
return V_35 ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
V_35 = F_13 ( V_7 , V_39 , 8 ) ;
if ( V_35 != 0 )
return V_35 ;
F_14 ( & V_7 -> V_37 , L_1 ) ;
V_34 -> V_36 . V_8 -> V_37 = & V_7 -> V_37 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_6 ( V_7 ) ;
V_34 -> V_36 . V_8 -> V_37 = NULL ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 )
{
struct V_8 * V_8 = F_2 ( V_41 -> V_9 . V_10 ) ;
struct V_26 * V_27 ;
int V_15 , V_35 ;
V_27 = F_17 ( & V_41 -> V_9 , sizeof( struct V_26 ) ,
V_42 ) ;
if ( V_27 == NULL )
return - V_43 ;
F_18 ( V_41 , V_27 ) ;
V_27 -> V_36 . V_8 = V_8 ;
V_27 -> V_36 . V_44 = 8 ;
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
V_27 -> V_36 . V_46 [ V_15 ] . V_47 = L_2 ;
V_27 -> V_36 . V_46 [ V_15 ] . V_48 = V_15 + 1 ;
V_27 -> V_36 . V_46 [ V_15 ] . type = V_49 ;
V_27 -> V_36 . V_46 [ V_15 ] . V_9 = V_8 -> V_9 ;
V_27 -> V_36 . V_46 [ V_15 ] . V_11 = V_8 -> V_11 ;
V_27 -> V_36 . V_46 [ V_15 ] . V_50 = V_51
+ ( 0x100 * V_15 ) ;
V_27 -> V_36 . V_46 [ V_15 ] . V_52 = V_53 [ V_15 ] ;
V_27 -> V_36 . V_46 [ V_15 ] . V_54
= F_3 ( V_55 ) ;
V_35 = F_19 ( & V_27 -> V_36 . V_46 [ V_15 ] , false ) ;
if ( V_35 != 0 )
return V_35 ;
}
for ( V_15 = 0 ; V_15 < F_3 ( V_27 -> V_29 ) ; V_15 ++ )
V_27 -> V_29 [ V_15 ] . V_56 = 3 ;
F_20 ( V_8 , 1 , V_57 - 1 ,
V_58 , V_59 ,
& V_27 -> V_29 [ 0 ] ) ;
F_20 ( V_8 , 2 , V_60 - 1 ,
V_61 , V_62 ,
& V_27 -> V_29 [ 1 ] ) ;
F_21 ( V_8 -> V_11 , V_63 ,
V_64 , 0x11 ) ;
F_21 ( V_8 -> V_11 , V_65 ,
V_66 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_67 ) ; V_15 ++ )
F_22 ( & V_27 -> V_36 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_68 ) ; V_15 ++ )
F_21 ( V_8 -> V_11 , V_68 [ V_15 ] ,
V_69 , V_69 ) ;
F_23 ( & V_41 -> V_9 ) ;
F_24 ( & V_41 -> V_9 ) ;
return F_25 ( & V_41 -> V_9 , & V_70 ,
V_67 , F_3 ( V_67 ) ) ;
}
static int F_26 ( struct V_40 * V_41 )
{
F_27 ( & V_41 -> V_9 ) ;
F_28 ( & V_41 -> V_9 ) ;
return 0 ;
}
