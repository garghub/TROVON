static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_9 :
case V_7 :
case V_6 :
return false ;
default:
return true ;
}
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 -> V_17 ) ;
struct V_18 * V_19 = F_5 ( V_16 ) ;
switch ( V_14 ) {
case V_20 :
F_6 ( V_19 -> V_21 , V_22 ,
V_19 -> V_23 ) ;
break;
case V_24 :
F_6 ( V_19 -> V_21 , V_22 , 0 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_5 ( V_16 ) ;
struct V_21 * V_25 = V_19 -> V_21 ;
int V_26 ;
V_26 = F_8 ( V_27 , V_19 -> V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
F_6 ( V_25 , V_9 , 0x1 ) ;
F_9 ( 20 ) ;
if ( ! V_19 -> V_29 )
return 0 ;
F_6 ( V_25 , V_30 , 0x1 ) ;
F_6 ( V_25 , V_31 ,
( V_19 -> V_32 & 0x1f ) << 3 |
( V_19 -> V_33 & 0x3 ) ) ;
F_6 ( V_25 , V_34 ,
V_19 -> V_35 & 0xff ) ;
F_6 ( V_25 , V_36 ,
V_19 -> V_37 & 0xff ) ;
F_6 ( V_25 , V_38 ,
V_19 -> V_39 & 0xff ) ;
return 0 ;
}
static void F_10 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_5 ( V_16 ) ;
F_11 ( V_27 , V_19 -> V_28 ) ;
}
static int F_12 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 ,
int V_44 , int V_45 )
{
struct V_18 * V_19 = F_13 ( V_41 ) ;
struct V_21 * V_25 = V_19 -> V_21 ;
switch ( V_41 -> V_46 ) {
case V_47 :
F_6 ( V_25 , V_48 , V_42 ) ;
V_19 -> V_23 = V_43 ;
break;
case V_49 :
F_6 ( V_25 , V_50 , V_42 ) ;
break;
default:
F_14 ( 1 ) ;
}
return 0 ;
}
static int F_15 ( struct V_40 * V_41 ,
unsigned int V_51 , unsigned int * V_52 ,
unsigned int V_53 , unsigned int * V_54 )
{
struct V_18 * V_19 = F_13 ( V_41 ) ;
struct V_21 * V_25 = V_19 -> V_21 ;
unsigned int V_55 , V_56 = 0 ;
for ( V_55 = 0 ; V_55 < V_51 ; V_55 ++ )
if ( V_52 [ V_55 ] )
V_56 |= ( 1 << V_55 ) ;
switch ( V_41 -> V_46 ) {
case V_47 :
F_6 ( V_25 , V_57 ,
V_56 ) ;
break;
case V_49 :
F_6 ( V_25 , V_58 , V_56 ) ;
break;
default:
F_14 ( 1 ) ;
}
F_6 ( V_25 , V_59 , V_56 ? 0x3 : 0x01 ) ;
return 0 ;
}
static int F_16 ( struct V_60 * V_61 ,
const struct V_62 * V_46 )
{
struct V_1 * V_2 = & V_61 -> V_2 ;
struct V_63 * V_64 = V_2 -> V_65 ;
struct V_18 * V_19 ;
int V_55 , V_26 ;
V_19 = F_17 ( V_2 , sizeof( * V_19 ) , V_66 ) ;
if ( ! V_19 )
return - V_67 ;
if ( V_64 ) {
if ( ! F_18 ( V_64 , L_1 ,
& V_19 -> V_32 ) )
V_19 -> V_29 = true ;
F_18 ( V_64 , L_2 ,
& V_19 -> V_33 ) ;
F_18 ( V_64 , L_3 ,
& V_19 -> V_35 ) ;
F_18 ( V_64 , L_4 ,
& V_19 -> V_37 ) ;
F_18 ( V_64 , L_5 ,
& V_19 -> V_39 ) ;
}
V_19 -> V_21 = F_19 ( V_61 , & V_68 ) ;
if ( F_20 ( V_19 -> V_21 ) ) {
V_26 = F_21 ( V_19 -> V_21 ) ;
F_22 ( & V_61 -> V_2 , L_6 , V_26 ) ;
return V_26 ;
}
for ( V_55 = 0 ; V_55 < V_27 ; V_55 ++ )
V_19 -> V_28 [ V_55 ] . V_69 = V_70 [ V_55 ] ;
V_26 = F_23 ( V_2 , V_27 ,
V_19 -> V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
F_24 ( V_61 , V_19 ) ;
return F_25 ( V_2 , & V_71 ,
V_72 , F_26 ( V_72 ) ) ;
}
