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
static int F_5 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
T_1 V_24 ;
F_7 ( & V_8 -> V_25 ) ;
V_24 = F_8 ( V_8 -> V_26 ) ;
memcpy ( V_23 -> V_27 . V_28 . V_24 , & V_24 , sizeof( V_24 ) ) ;
F_9 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
F_7 ( & V_8 -> V_25 ) ;
memcpy ( & V_8 -> V_26 , V_23 -> V_27 . V_28 . V_24 ,
sizeof( V_8 -> V_26 ) ) ;
V_8 -> V_26 = F_11 ( V_8 -> V_26 ) ;
F_9 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
F_7 ( & V_8 -> V_25 ) ;
V_23 -> V_27 . integer . V_27 [ 0 ] = V_8 -> V_29 ;
F_9 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_8 = F_2 ( V_7 -> V_9 -> V_10 ) ;
F_7 ( & V_8 -> V_25 ) ;
V_8 -> V_29 = V_23 -> V_27 . integer . V_27 [ 0 ] ;
F_9 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , int V_30 , int V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_34 * V_35 = F_15 ( V_7 ) ;
switch ( V_30 ) {
case V_36 :
return F_16 ( & V_35 -> V_37 [ 0 ] , V_31 , V_32 , V_33 ) ;
case V_38 :
return F_16 ( & V_35 -> V_37 [ 1 ] , V_31 , V_32 , V_33 ) ;
case V_39 :
return F_17 ( & V_35 -> V_37 [ 0 ] , V_31 , V_32 ,
V_33 ) ;
case V_40 :
return F_17 ( & V_35 -> V_37 [ 1 ] , V_31 , V_32 ,
V_33 ) ;
default:
return - V_41 ;
}
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_34 * V_42 = F_15 ( V_7 ) ;
int V_43 ;
V_43 = F_19 ( V_7 , V_44 , 2 ) ;
if ( V_43 != 0 )
return V_43 ;
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
F_22 ( & V_7 -> V_45 , L_1 ) ;
V_42 -> V_46 . V_8 -> V_45 = & V_7 -> V_45 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_34 * V_42 = F_15 ( V_7 ) ;
V_42 -> V_46 . V_8 -> V_45 = NULL ;
return 0 ;
}
static struct V_11 * F_24 ( struct V_47 * V_9 )
{
struct V_34 * V_42 = F_2 ( V_9 ) ;
return V_42 -> V_46 . V_8 -> V_11 ;
}
static int F_25 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_2 ( V_49 -> V_9 . V_10 ) ;
struct V_34 * V_35 ;
int V_14 , V_43 ;
V_35 = F_26 ( & V_49 -> V_9 , sizeof( struct V_34 ) ,
V_50 ) ;
if ( V_35 == NULL )
return - V_51 ;
F_27 ( V_49 , V_35 ) ;
F_28 ( & V_8 -> V_25 ) ;
V_35 -> V_46 . V_8 = V_8 ;
V_35 -> V_46 . V_52 = 6 ;
V_35 -> V_46 . V_53 [ 0 ] . V_54 = L_2 ;
V_35 -> V_46 . V_53 [ 0 ] . V_55 = 1 ;
V_35 -> V_46 . V_53 [ 0 ] . type = V_56 ;
V_35 -> V_46 . V_53 [ 0 ] . V_57 = V_58 ;
V_35 -> V_46 . V_53 [ 0 ] . V_9 = V_8 -> V_9 ;
V_35 -> V_46 . V_53 [ 0 ] . V_11 = V_8 -> V_11 ;
V_35 -> V_46 . V_53 [ 0 ] . V_59 = V_60 ;
V_35 -> V_46 . V_53 [ 0 ] . V_61 = F_3 ( V_60 ) ;
V_43 = F_29 ( & V_35 -> V_46 . V_53 [ 0 ] , true ) ;
if ( V_43 != 0 )
return V_43 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_35 -> V_37 ) ; V_14 ++ )
V_35 -> V_37 [ V_14 ] . V_62 = 1 ;
F_30 ( V_8 , 1 , V_63 - 1 ,
V_64 , V_65 ,
& V_35 -> V_37 [ 0 ] ) ;
F_30 ( V_8 , 2 , V_66 - 1 ,
V_67 , V_68 ,
& V_35 -> V_37 [ 1 ] ) ;
F_31 ( V_8 -> V_11 , V_69 ,
V_70 , 0x11 ) ;
F_31 ( V_8 -> V_11 , V_71 ,
V_72 , 0x12 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_73 ) ; V_14 ++ )
F_32 ( & V_35 -> V_46 , V_14 ) ;
for ( V_14 = 0 ; V_14 < F_3 ( V_74 ) ; V_14 ++ )
F_31 ( V_8 -> V_11 , V_74 [ V_14 ] ,
V_75 , V_75 ) ;
F_33 ( & V_49 -> V_9 ) ;
F_34 ( & V_49 -> V_9 ) ;
return F_35 ( & V_49 -> V_9 , & V_76 ,
V_73 , F_3 ( V_73 ) ) ;
}
static int F_36 ( struct V_48 * V_49 )
{
F_37 ( & V_49 -> V_9 ) ;
F_38 ( & V_49 -> V_9 ) ;
return 0 ;
}
