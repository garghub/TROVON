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
case V_23 :
case V_24 :
return F_6 ( V_2 , V_4 , V_5 ) ;
default:
return 0 ;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static int F_8 ( struct V_6 * V_7 , int V_25 , int V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_29 * V_30 = F_9 ( V_7 ) ;
switch ( V_25 ) {
case V_31 :
return F_10 ( & V_30 -> V_32 [ 0 ] , V_26 , V_27 , V_28 ) ;
case V_33 :
return F_10 ( & V_30 -> V_32 [ 1 ] , V_26 , V_27 , V_28 ) ;
case V_34 :
return F_11 ( & V_30 -> V_32 [ 0 ] , V_26 , V_27 ,
V_28 ) ;
case V_35 :
return F_11 ( & V_30 -> V_32 [ 1 ] , V_26 , V_27 ,
V_28 ) ;
default:
return - V_36 ;
}
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_37 * V_8 = F_13 ( V_7 ) ;
struct V_38 * V_39 = F_14 ( V_8 ) ;
struct V_29 * V_40 = F_9 ( V_7 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
F_17 ( V_39 , L_1 ) ;
V_40 -> V_41 . V_9 -> V_8 = V_8 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_29 * V_40 = F_9 ( V_7 ) ;
V_40 -> V_41 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_19 ( struct V_42 * V_10 )
{
struct V_29 * V_40 = F_3 ( V_10 ) ;
return V_40 -> V_41 . V_9 -> V_12 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_9 * V_9 = F_3 ( V_44 -> V_10 . V_11 ) ;
struct V_29 * V_30 ;
int V_15 , V_45 ;
V_30 = F_21 ( & V_44 -> V_10 , sizeof( struct V_29 ) ,
V_46 ) ;
if ( V_30 == NULL )
return - V_47 ;
F_22 ( V_44 , V_30 ) ;
V_30 -> V_41 . V_9 = V_9 ;
V_30 -> V_41 . V_48 = 4 ;
F_23 ( & V_30 -> V_41 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_30 -> V_32 ) ; V_15 ++ )
V_30 -> V_32 [ V_15 ] . V_49 = 1 ;
F_24 ( V_9 , 1 , V_50 - 1 ,
V_51 , V_52 ,
& V_30 -> V_32 [ 0 ] ) ;
F_24 ( V_9 , 2 , V_53 - 1 ,
V_54 , V_55 ,
& V_30 -> V_32 [ 1 ] ) ;
F_25 ( V_9 -> V_12 , V_56 ,
V_57 , 0x11 ) ;
F_25 ( V_9 -> V_12 , V_58 ,
V_59 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_60 ) ; V_15 ++ )
F_26 ( & V_30 -> V_41 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_61 ) ; V_15 ++ )
F_25 ( V_9 -> V_12 , V_61 [ V_15 ] ,
V_62 , V_62 ) ;
F_27 ( & V_44 -> V_10 ) ;
F_28 ( & V_44 -> V_10 ) ;
V_45 = F_29 ( V_9 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_30 ( & V_44 -> V_10 , & V_63 ,
V_60 , F_4 ( V_60 ) ) ;
if ( V_45 < 0 ) {
F_31 ( & V_44 -> V_10 , L_2 , V_45 ) ;
goto V_64;
}
V_64:
F_32 ( V_9 ) ;
return V_45 ;
}
static int F_33 ( struct V_43 * V_44 )
{
struct V_29 * V_30 = F_34 ( V_44 ) ;
struct V_9 * V_9 = V_30 -> V_41 . V_9 ;
F_35 ( & V_44 -> V_10 ) ;
F_36 ( & V_44 -> V_10 ) ;
F_32 ( V_9 ) ;
return 0 ;
}
