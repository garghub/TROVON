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
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
struct V_23 * V_24 = F_6 ( V_7 ) ;
if ( V_8 -> V_17 < 1 )
return 0 ;
switch ( V_5 ) {
case V_25 :
if ( ! V_24 -> V_26 ) {
F_7 ( V_7 , 0x4f5 , 0x25a ) ;
V_24 -> V_27 = true ;
}
break;
case V_20 :
if ( V_24 -> V_27 ) {
F_8 ( 75 ) ;
F_7 ( V_7 , 0x4f5 , 0xda ) ;
V_24 -> V_27 = false ;
V_24 -> V_26 ++ ;
}
break;
case V_28 :
V_24 -> V_26 -- ;
if ( ! V_24 -> V_26 )
F_7 ( V_7 , 0x4f5 , 0x25a ) ;
break;
case V_29 :
if ( ! V_24 -> V_26 )
F_7 ( V_7 , 0x4f5 , 0x0da ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_23 * V_24 = F_6 ( V_7 ) ;
switch ( V_30 ) {
case V_34 :
return F_10 ( & V_24 -> V_35 [ 0 ] , V_31 , V_32 , V_33 ) ;
case V_36 :
return F_10 ( & V_24 -> V_35 [ 1 ] , V_31 , V_32 , V_33 ) ;
default:
return - V_37 ;
}
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_23 * V_38 = F_6 ( V_7 ) ;
int V_39 ;
V_7 -> V_12 = V_38 -> V_40 . V_8 -> V_11 ;
V_39 = F_12 ( V_7 , 32 , 16 , V_41 ) ;
if ( V_39 != 0 )
return V_39 ;
V_39 = F_13 ( V_7 , V_42 , 1 ) ;
if ( V_39 != 0 )
return V_39 ;
F_14 ( & V_7 -> V_43 , L_1 ) ;
V_38 -> V_40 . V_8 -> V_43 = & V_7 -> V_43 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_23 * V_38 = F_6 ( V_7 ) ;
V_38 -> V_40 . V_8 -> V_43 = NULL ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 )
{
struct V_8 * V_8 = F_2 ( V_45 -> V_9 . V_10 ) ;
struct V_23 * V_24 ;
int V_15 , V_39 ;
V_24 = F_17 ( & V_45 -> V_9 , sizeof( struct V_23 ) ,
V_46 ) ;
if ( V_24 == NULL )
return - V_47 ;
F_18 ( V_45 , V_24 ) ;
V_24 -> V_40 . V_8 = V_8 ;
V_24 -> V_40 . V_48 [ 0 ] . V_49 = L_2 ;
V_24 -> V_40 . V_48 [ 0 ] . V_50 = 1 ;
V_24 -> V_40 . V_48 [ 0 ] . type = V_51 ;
V_24 -> V_40 . V_48 [ 0 ] . V_52 = V_53 ;
V_24 -> V_40 . V_48 [ 0 ] . V_9 = V_8 -> V_9 ;
V_24 -> V_40 . V_48 [ 0 ] . V_11 = V_8 -> V_11 ;
V_24 -> V_40 . V_48 [ 0 ] . V_54 = V_55 ;
V_24 -> V_40 . V_48 [ 0 ] . V_56 = F_3 ( V_55 ) ;
V_39 = F_19 ( & V_24 -> V_40 . V_48 [ 0 ] , true ) ;
if ( V_39 != 0 )
return V_39 ;
for ( V_15 = 0 ; V_15 < F_3 ( V_24 -> V_35 ) ; V_15 ++ )
V_24 -> V_35 [ V_15 ] . V_57 = 1 ;
F_20 ( V_8 , 1 , V_58 - 1 ,
V_59 , V_60 ,
& V_24 -> V_35 [ 0 ] ) ;
F_20 ( V_8 , 2 , V_61 - 1 ,
V_62 , V_63 ,
& V_24 -> V_35 [ 1 ] ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_64 ) ; V_15 ++ )
F_21 ( & V_24 -> V_40 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_65 ) ; V_15 ++ )
F_22 ( V_8 -> V_11 , V_65 [ V_15 ] ,
V_66 , V_66 ) ;
F_23 ( & V_45 -> V_9 ) ;
F_24 ( & V_45 -> V_9 ) ;
return F_25 ( & V_45 -> V_9 , & V_67 ,
V_64 , F_3 ( V_64 ) ) ;
}
static int F_26 ( struct V_44 * V_45 )
{
F_27 ( & V_45 -> V_9 ) ;
F_28 ( & V_45 -> V_9 ) ;
return 0 ;
}
