static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_9 -> V_17 ) {
case 3 :
V_14 = V_18 ;
V_16 = F_4 ( V_18 ) ;
break;
default:
return 0 ;
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
int V_35 ;
V_34 -> V_36 . V_9 -> V_8 = & V_7 -> V_8 ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
F_13 ( V_7 ) ;
V_35 = F_14 ( V_7 , V_37 , 8 ) ;
if ( V_35 != 0 )
return V_35 ;
F_15 ( & V_7 -> V_8 , L_1 ) ;
V_34 -> V_36 . V_9 -> V_8 = & V_7 -> V_8 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_26 * V_34 = F_7 ( V_7 ) ;
V_34 -> V_36 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_17 ( struct V_38 * V_10 )
{
struct V_26 * V_34 = F_3 ( V_10 ) ;
return V_34 -> V_36 . V_9 -> V_12 ;
}
static int F_18 ( struct V_39 * V_40 )
{
struct V_9 * V_9 = F_3 ( V_40 -> V_10 . V_11 ) ;
struct V_26 * V_27 ;
int V_15 , V_35 ;
V_27 = F_19 ( & V_40 -> V_10 , sizeof( struct V_26 ) ,
V_41 ) ;
if ( V_27 == NULL )
return - V_42 ;
F_20 ( V_40 , V_27 ) ;
V_27 -> V_36 . V_9 = V_9 ;
V_27 -> V_36 . V_43 = 8 ;
for ( V_15 = 0 ; V_15 < V_44 ; V_15 ++ ) {
V_27 -> V_36 . V_45 [ V_15 ] . V_46 = L_2 ;
V_27 -> V_36 . V_45 [ V_15 ] . V_47 = V_15 + 1 ;
V_27 -> V_36 . V_45 [ V_15 ] . type = V_48 ;
V_27 -> V_36 . V_45 [ V_15 ] . V_10 = V_9 -> V_10 ;
V_27 -> V_36 . V_45 [ V_15 ] . V_12 = V_9 -> V_12 ;
V_27 -> V_36 . V_45 [ V_15 ] . V_49 = V_50
+ ( 0x100 * V_15 ) ;
V_27 -> V_36 . V_45 [ V_15 ] . V_51 = V_52 [ V_15 ] ;
V_27 -> V_36 . V_45 [ V_15 ] . V_53
= F_4 ( V_54 ) ;
V_35 = F_21 ( & V_27 -> V_36 . V_45 [ V_15 ] , false ) ;
if ( V_35 != 0 )
return V_35 ;
}
for ( V_15 = 0 ; V_15 < F_4 ( V_27 -> V_29 ) ; V_15 ++ )
V_27 -> V_29 [ V_15 ] . V_55 = 3 ;
F_22 ( V_9 , 1 , V_56 - 1 ,
V_57 , V_58 ,
& V_27 -> V_29 [ 0 ] ) ;
F_22 ( V_9 , 2 , V_59 - 1 ,
V_60 , V_61 ,
& V_27 -> V_29 [ 1 ] ) ;
F_23 ( V_9 -> V_12 , V_62 ,
V_63 , 0x11 ) ;
F_23 ( V_9 -> V_12 , V_64 ,
V_65 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_66 ) ; V_15 ++ )
F_24 ( & V_27 -> V_36 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_67 ) ; V_15 ++ )
F_23 ( V_9 -> V_12 , V_67 [ V_15 ] ,
V_68 , V_68 ) ;
F_25 ( & V_40 -> V_10 ) ;
F_26 ( & V_40 -> V_10 ) ;
return F_27 ( & V_40 -> V_10 , & V_69 ,
V_66 , F_4 ( V_66 ) ) ;
}
static int F_28 ( struct V_39 * V_40 )
{
F_29 ( & V_40 -> V_10 ) ;
F_30 ( & V_40 -> V_10 ) ;
return 0 ;
}
