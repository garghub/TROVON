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
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_21 ) ;
struct V_22 * V_23 = F_6 ( V_7 ) ;
if ( V_8 -> V_16 < 1 )
return 0 ;
switch ( V_5 ) {
case V_24 :
if ( ! V_23 -> V_25 ) {
F_7 ( V_7 , 0x4f5 , 0x25a ) ;
V_23 -> V_26 = true ;
}
break;
case V_18 :
if ( V_23 -> V_26 ) {
F_8 ( 75 ) ;
F_7 ( V_7 , 0x4f5 , 0xda ) ;
V_23 -> V_26 = false ;
V_23 -> V_25 ++ ;
}
break;
case V_27 :
V_23 -> V_25 -- ;
if ( ! V_23 -> V_25 )
F_7 ( V_7 , 0x4f5 , 0x25a ) ;
break;
case V_28 :
if ( ! V_23 -> V_25 )
F_7 ( V_7 , 0x4f5 , 0x0da ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , int V_29 , int V_30 ,
unsigned int V_31 , unsigned int V_32 )
{
struct V_22 * V_23 = F_6 ( V_7 ) ;
switch ( V_29 ) {
case V_33 :
return F_10 ( & V_23 -> V_34 [ 0 ] , V_30 , V_31 , V_32 ) ;
case V_35 :
return F_10 ( & V_23 -> V_34 [ 1 ] , V_30 , V_31 , V_32 ) ;
default:
return - V_36 ;
}
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_22 * V_37 = F_6 ( V_7 ) ;
int V_38 ;
V_7 -> V_11 = V_37 -> V_39 . V_8 -> V_10 ;
V_38 = F_12 ( V_7 , 32 , 16 , V_40 ) ;
if ( V_38 != 0 )
return V_38 ;
F_13 ( & V_7 -> V_41 , L_1 ) ;
V_37 -> V_39 . V_8 -> V_41 = & V_7 -> V_41 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_22 * V_37 = F_6 ( V_7 ) ;
V_37 -> V_39 . V_8 -> V_41 = NULL ;
return 0 ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_8 * V_8 = F_2 ( V_43 -> V_9 . V_21 ) ;
struct V_22 * V_23 ;
int V_14 , V_38 ;
V_23 = F_16 ( & V_43 -> V_9 , sizeof( struct V_22 ) ,
V_44 ) ;
if ( V_23 == NULL )
return - V_45 ;
F_17 ( V_43 , V_23 ) ;
V_23 -> V_39 . V_8 = V_8 ;
V_23 -> V_39 . V_46 [ 0 ] . V_47 = L_2 ;
V_23 -> V_39 . V_46 [ 0 ] . V_48 = 1 ;
V_23 -> V_39 . V_46 [ 0 ] . type = V_49 ;
V_23 -> V_39 . V_46 [ 0 ] . V_50 = V_51 ;
V_23 -> V_39 . V_46 [ 0 ] . V_9 = V_8 -> V_9 ;
V_23 -> V_39 . V_46 [ 0 ] . V_10 = V_8 -> V_10 ;
V_23 -> V_39 . V_46 [ 0 ] . V_52 = V_53 ;
V_23 -> V_39 . V_46 [ 0 ] . V_54 = F_3 ( V_53 ) ;
V_38 = F_18 ( & V_23 -> V_39 . V_46 [ 0 ] , true ) ;
if ( V_38 != 0 )
return V_38 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_23 -> V_34 ) ; V_14 ++ )
V_23 -> V_34 [ V_14 ] . V_55 = 1 ;
F_19 ( V_8 , 1 , V_56 - 1 ,
V_57 , V_58 ,
& V_23 -> V_34 [ 0 ] ) ;
F_19 ( V_8 , 2 , V_59 - 1 ,
V_60 , V_61 ,
& V_23 -> V_34 [ 1 ] ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_62 ) ; V_14 ++ )
F_20 ( & V_23 -> V_39 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_63 ) ; V_14 ++ )
F_21 ( V_8 -> V_10 , V_63 [ V_14 ] ,
V_64 , V_64 ) ;
F_22 ( & V_43 -> V_9 ) ;
F_23 ( & V_43 -> V_9 ) ;
return F_24 ( & V_43 -> V_9 , & V_65 ,
V_62 , F_3 ( V_62 ) ) ;
}
static int F_25 ( struct V_42 * V_43 )
{
F_26 ( & V_43 -> V_9 ) ;
F_27 ( & V_43 -> V_9 ) ;
return 0 ;
}
