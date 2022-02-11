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
V_14 = V_19 ;
V_16 = F_4 ( V_19 ) ;
break;
}
switch ( V_5 ) {
case V_20 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_5 ( V_12 , V_14 [ V_15 ] . V_21 ,
V_14 [ V_15 ] . V_22 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_7 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_8 ( & V_9 -> V_25 ) ;
F_9 ( V_9 -> V_26 ,
V_24 -> V_27 . V_28 . V_29 ) ;
F_10 ( & V_9 -> V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_7 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_8 ( & V_9 -> V_25 ) ;
memcpy ( & V_9 -> V_26 , V_24 -> V_27 . V_28 . V_29 ,
sizeof( V_9 -> V_26 ) ) ;
V_9 -> V_26 = F_12 ( V_9 -> V_26 ) ;
F_10 ( & V_9 -> V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_7 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_8 ( & V_9 -> V_25 ) ;
V_24 -> V_27 . integer . V_27 [ 0 ] = V_9 -> V_30 ;
F_10 ( & V_9 -> V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_7 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_8 ( & V_9 -> V_25 ) ;
V_9 -> V_30 = V_24 -> V_27 . integer . V_27 [ 0 ] ;
F_10 ( & V_9 -> V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , int V_31 , int V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
struct V_35 * V_36 = F_16 ( V_7 ) ;
switch ( V_31 ) {
case V_37 :
return F_17 ( & V_36 -> V_38 [ 0 ] , V_32 , V_33 , V_34 ) ;
case V_39 :
return F_17 ( & V_36 -> V_38 [ 1 ] , V_32 , V_33 , V_34 ) ;
case V_40 :
return F_18 ( & V_36 -> V_38 [ 0 ] , V_32 , V_33 ,
V_34 ) ;
case V_41 :
return F_18 ( & V_36 -> V_38 [ 1 ] , V_32 , V_33 ,
V_34 ) ;
default:
return - V_42 ;
}
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_35 * V_43 = F_16 ( V_7 ) ;
int V_44 ;
V_44 = F_20 ( V_7 , V_45 , 2 ) ;
if ( V_44 != 0 )
return V_44 ;
F_21 ( V_7 ) ;
F_22 ( V_7 ) ;
F_23 ( & V_7 -> V_8 , L_1 ) ;
V_43 -> V_46 . V_9 -> V_8 = & V_7 -> V_8 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_35 * V_43 = F_16 ( V_7 ) ;
V_43 -> V_46 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_25 ( struct V_47 * V_10 )
{
struct V_35 * V_43 = F_3 ( V_10 ) ;
return V_43 -> V_46 . V_9 -> V_12 ;
}
static int F_26 ( struct V_48 * V_49 )
{
struct V_9 * V_9 = F_3 ( V_49 -> V_10 . V_11 ) ;
struct V_35 * V_36 ;
int V_15 , V_44 ;
V_36 = F_27 ( & V_49 -> V_10 , sizeof( struct V_35 ) ,
V_50 ) ;
if ( V_36 == NULL )
return - V_51 ;
F_28 ( V_49 , V_36 ) ;
F_29 ( & V_9 -> V_25 ) ;
V_36 -> V_46 . V_9 = V_9 ;
V_36 -> V_46 . V_52 = 6 ;
V_36 -> V_46 . V_53 [ 0 ] . V_54 = L_2 ;
V_36 -> V_46 . V_53 [ 0 ] . V_55 = 1 ;
V_36 -> V_46 . V_53 [ 0 ] . type = V_56 ;
V_36 -> V_46 . V_53 [ 0 ] . V_57 = V_58 ;
V_36 -> V_46 . V_53 [ 0 ] . V_10 = V_9 -> V_10 ;
V_36 -> V_46 . V_53 [ 0 ] . V_12 = V_9 -> V_12 ;
V_36 -> V_46 . V_53 [ 0 ] . V_59 = V_60 ;
V_36 -> V_46 . V_53 [ 0 ] . V_61 = F_4 ( V_60 ) ;
V_44 = F_30 ( & V_36 -> V_46 . V_53 [ 0 ] , true ) ;
if ( V_44 != 0 )
return V_44 ;
for ( V_15 = 0 ; V_15 < F_4 ( V_36 -> V_38 ) ; V_15 ++ )
V_36 -> V_38 [ V_15 ] . V_62 = 1 ;
F_31 ( V_9 , 1 , V_63 - 1 ,
V_64 , V_65 ,
& V_36 -> V_38 [ 0 ] ) ;
F_31 ( V_9 , 2 , V_66 - 1 ,
V_67 , V_68 ,
& V_36 -> V_38 [ 1 ] ) ;
F_32 ( V_9 -> V_12 , V_69 ,
V_70 , 0x11 ) ;
F_32 ( V_9 -> V_12 , V_71 ,
V_72 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_73 ) ; V_15 ++ )
F_33 ( & V_36 -> V_46 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_74 ) ; V_15 ++ )
F_32 ( V_9 -> V_12 , V_74 [ V_15 ] ,
V_75 , V_75 ) ;
F_34 ( & V_49 -> V_10 ) ;
F_35 ( & V_49 -> V_10 ) ;
return F_36 ( & V_49 -> V_10 , & V_76 ,
V_73 , F_4 ( V_73 ) ) ;
}
static int F_37 ( struct V_48 * V_49 )
{
F_38 ( & V_49 -> V_10 ) ;
F_39 ( & V_49 -> V_10 ) ;
return 0 ;
}
