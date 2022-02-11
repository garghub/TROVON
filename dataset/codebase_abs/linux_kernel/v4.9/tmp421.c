static int F_1 ( T_1 V_1 )
{
int V_2 = V_1 & ~ 0xf ;
return ( V_2 * 1000 + 128 ) / 256 ;
}
static int F_2 ( T_2 V_1 )
{
int V_2 = V_1 & ~ 0xf ;
V_2 -= 64 * 256 ;
return ( V_2 * 1000 + 128 ) / 256 ;
}
static struct V_3 * F_3 ( struct V_4 * V_5 )
{
struct V_3 * V_6 = F_4 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_5 ( & V_6 -> V_10 ) ;
if ( F_6 ( V_11 , V_6 -> V_12 + 2 * V_13 ) || ! V_6 -> V_14 ) {
V_6 -> V_15 = F_7 ( V_8 ,
V_16 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_17 ; V_9 ++ ) {
V_6 -> V_2 [ V_9 ] = F_7 ( V_8 ,
V_18 [ V_9 ] ) << 8 ;
V_6 -> V_2 [ V_9 ] |= F_7 ( V_8 ,
V_19 [ V_9 ] ) ;
}
V_6 -> V_12 = V_11 ;
V_6 -> V_14 = 1 ;
}
F_8 ( & V_6 -> V_10 ) ;
return V_6 ;
}
static int F_9 ( struct V_4 * V_5 , enum V_20 type ,
T_3 V_21 , int V_22 , long * V_23 )
{
struct V_3 * V_24 = F_3 ( V_5 ) ;
switch ( V_21 ) {
case V_25 :
if ( V_24 -> V_15 & V_26 )
* V_23 = F_2 ( V_24 -> V_2 [ V_22 ] ) ;
else
* V_23 = F_1 ( V_24 -> V_2 [ V_22 ] ) ;
return 0 ;
case V_27 :
* V_23 = V_24 -> V_2 [ V_22 ] & 0x01 ;
return 0 ;
default:
return - V_28 ;
}
}
static T_4 F_10 ( const void * V_6 , enum V_20 type ,
T_3 V_21 , int V_22 )
{
switch ( V_21 ) {
case V_27 :
if ( V_22 == 0 )
return 0 ;
return V_29 ;
case V_25 :
return V_29 ;
default:
return 0 ;
}
}
static int F_11 ( struct V_7 * V_8 )
{
int V_15 , V_30 ;
F_12 ( V_8 , V_31 , 0x05 ) ;
V_15 = F_7 ( V_8 , V_16 ) ;
if ( V_15 < 0 ) {
F_13 ( & V_8 -> V_5 ,
L_1 , V_15 ) ;
return V_15 ;
}
V_30 = V_15 ;
V_15 &= ~ V_32 ;
if ( V_15 != V_30 ) {
F_14 ( & V_8 -> V_5 , L_2 ) ;
F_12 ( V_8 , V_16 , V_15 ) ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_33 * V_34 )
{
enum V_35 V_36 ;
struct V_37 * V_38 = V_8 -> V_38 ;
const char * const V_39 [] = { L_3 , L_4 , L_5 ,
L_6 , L_7 } ;
int V_40 = V_8 -> V_40 ;
T_5 V_1 ;
if ( ! F_16 ( V_38 , V_41 ) )
return - V_42 ;
V_1 = F_7 ( V_8 , V_43 ) ;
if ( V_1 != V_44 )
return - V_42 ;
V_1 = F_7 ( V_8 , V_31 ) ;
if ( V_1 & 0xf8 )
return - V_42 ;
V_1 = F_7 ( V_8 , V_45 ) ;
if ( V_1 & 0x7f )
return - V_42 ;
V_1 = F_7 ( V_8 , V_46 ) ;
switch ( V_1 ) {
case V_47 :
V_36 = V_24 ;
break;
case V_48 :
if ( V_40 == 0x2a )
return - V_42 ;
V_36 = V_49 ;
break;
case V_50 :
if ( V_40 != 0x4c && V_40 != 0x4d )
return - V_42 ;
V_36 = V_51 ;
break;
case V_52 :
V_36 = V_53 ;
break;
case V_54 :
if ( V_40 != 0x4c && V_40 != 0x4d )
return - V_42 ;
V_36 = V_55 ;
break;
default:
return - V_42 ;
}
F_17 ( V_34 -> type , V_56 [ V_36 ] . V_57 , V_58 ) ;
F_14 ( & V_38 -> V_5 , L_8 ,
V_39 [ V_36 ] , V_8 -> V_40 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
const struct V_59 * V_60 )
{
struct V_4 * V_5 = & V_8 -> V_5 ;
struct V_4 * V_61 ;
struct V_3 * V_6 ;
int V_9 , V_62 ;
V_6 = F_19 ( V_5 , sizeof( struct V_3 ) , V_63 ) ;
if ( ! V_6 )
return - V_64 ;
F_20 ( & V_6 -> V_10 ) ;
V_6 -> V_17 = V_60 -> V_65 ;
V_6 -> V_8 = V_8 ;
V_62 = F_11 ( V_8 ) ;
if ( V_62 )
return V_62 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_17 ; V_9 ++ )
V_6 -> V_66 [ V_9 ] = V_67 | V_68 ;
V_6 -> V_69 . V_70 = & V_71 ;
V_6 -> V_69 . V_34 = V_6 -> V_34 ;
V_6 -> V_34 [ 0 ] = & V_6 -> V_72 ;
V_6 -> V_72 . type = V_73 ;
V_6 -> V_72 . V_15 = V_6 -> V_66 ;
V_61 = F_21 ( V_5 , V_8 -> V_57 ,
V_6 ,
& V_6 -> V_69 ,
NULL ) ;
return F_22 ( V_61 ) ;
}
