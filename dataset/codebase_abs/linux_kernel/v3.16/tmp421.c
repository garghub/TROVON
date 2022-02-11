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
static T_3 F_9 ( struct V_4 * V_5 ,
struct V_20 * V_21 , char * V_22 )
{
int V_23 = F_10 ( V_21 ) -> V_23 ;
struct V_3 * V_6 = F_3 ( V_5 ) ;
int V_2 ;
F_5 ( & V_6 -> V_10 ) ;
if ( V_6 -> V_15 & V_24 )
V_2 = F_2 ( V_6 -> V_2 [ V_23 ] ) ;
else
V_2 = F_1 ( V_6 -> V_2 [ V_23 ] ) ;
F_8 ( & V_6 -> V_10 ) ;
return sprintf ( V_22 , L_1 , V_2 ) ;
}
static T_3 F_11 ( struct V_4 * V_5 ,
struct V_20 * V_21 , char * V_22 )
{
int V_23 = F_10 ( V_21 ) -> V_23 ;
struct V_3 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_2 [ V_23 ] & 0x01 )
return sprintf ( V_22 , L_2 ) ;
else
return sprintf ( V_22 , L_3 ) ;
}
static T_4 F_12 ( struct V_25 * V_26 , struct V_27 * V_28 ,
int V_29 )
{
struct V_4 * V_5 = F_13 ( V_26 , struct V_4 , V_26 ) ;
struct V_3 * V_6 = F_4 ( V_5 ) ;
struct V_20 * V_21 ;
unsigned int V_23 ;
V_21 = F_13 ( V_28 , struct V_20 , V_30 ) ;
V_23 = F_10 ( V_21 ) -> V_23 ;
if ( V_23 < V_6 -> V_17 )
return V_28 -> V_31 ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 )
{
int V_15 , V_32 ;
F_15 ( V_8 , V_33 , 0x05 ) ;
V_15 = F_7 ( V_8 , V_16 ) ;
if ( V_15 < 0 ) {
F_16 ( & V_8 -> V_5 ,
L_4 , V_15 ) ;
return V_15 ;
}
V_32 = V_15 ;
V_15 &= ~ V_34 ;
if ( V_15 != V_32 ) {
F_17 ( & V_8 -> V_5 , L_5 ) ;
F_15 ( V_8 , V_16 , V_15 ) ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
struct V_35 * V_36 )
{
enum V_37 V_38 ;
struct V_39 * V_40 = V_8 -> V_40 ;
const char * V_41 [] = { L_6 , L_7 , L_8 } ;
T_5 V_1 ;
if ( ! F_19 ( V_40 , V_42 ) )
return - V_43 ;
V_1 = F_7 ( V_8 , V_44 ) ;
if ( V_1 != V_45 )
return - V_43 ;
V_1 = F_7 ( V_8 , V_46 ) ;
switch ( V_1 ) {
case V_47 :
V_38 = V_48 ;
break;
case V_49 :
V_38 = V_50 ;
break;
case V_51 :
V_38 = V_52 ;
break;
default:
return - V_43 ;
}
F_20 ( V_36 -> type , V_53 [ V_38 ] . V_54 , V_55 ) ;
F_17 ( & V_40 -> V_5 , L_9 ,
V_41 [ V_38 ] , V_8 -> V_56 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
const struct V_57 * V_58 )
{
struct V_4 * V_5 = & V_8 -> V_5 ;
struct V_4 * V_59 ;
struct V_3 * V_6 ;
int V_60 ;
V_6 = F_22 ( V_5 , sizeof( struct V_3 ) , V_61 ) ;
if ( ! V_6 )
return - V_62 ;
F_23 ( & V_6 -> V_10 ) ;
V_6 -> V_17 = V_58 -> V_63 ;
V_6 -> V_8 = V_8 ;
V_60 = F_14 ( V_8 ) ;
if ( V_60 )
return V_60 ;
V_59 = F_24 ( V_5 , V_8 -> V_54 ,
V_6 , V_64 ) ;
return F_25 ( V_59 ) ;
}
