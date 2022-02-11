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
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_3 * V_8 = F_5 ( V_7 ) ;
int V_9 ;
F_6 ( & V_8 -> V_10 ) ;
if ( F_7 ( V_11 , V_8 -> V_12 + 2 * V_13 ) || ! V_8 -> V_14 ) {
V_8 -> V_15 = F_8 ( V_7 ,
V_16 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_17 ; V_9 ++ ) {
V_8 -> V_2 [ V_9 ] = F_8 ( V_7 ,
V_18 [ V_9 ] ) << 8 ;
V_8 -> V_2 [ V_9 ] |= F_8 ( V_7 ,
V_19 [ V_9 ] ) ;
}
V_8 -> V_12 = V_11 ;
V_8 -> V_14 = 1 ;
}
F_9 ( & V_8 -> V_10 ) ;
return V_8 ;
}
static T_3 F_10 ( struct V_4 * V_5 ,
struct V_20 * V_21 , char * V_22 )
{
int V_23 = F_11 ( V_21 ) -> V_23 ;
struct V_3 * V_8 = F_3 ( V_5 ) ;
int V_2 ;
F_6 ( & V_8 -> V_10 ) ;
if ( V_8 -> V_15 & V_24 )
V_2 = F_2 ( V_8 -> V_2 [ V_23 ] ) ;
else
V_2 = F_1 ( V_8 -> V_2 [ V_23 ] ) ;
F_9 ( & V_8 -> V_10 ) ;
return sprintf ( V_22 , L_1 , V_2 ) ;
}
static T_3 F_12 ( struct V_4 * V_5 ,
struct V_20 * V_21 , char * V_22 )
{
int V_23 = F_11 ( V_21 ) -> V_23 ;
struct V_3 * V_8 = F_3 ( V_5 ) ;
if ( V_8 -> V_2 [ V_23 ] & 0x01 )
return sprintf ( V_22 , L_2 ) ;
else
return sprintf ( V_22 , L_3 ) ;
}
static T_4 F_13 ( struct V_25 * V_26 , struct V_27 * V_28 ,
int V_29 )
{
struct V_4 * V_5 = F_14 ( V_26 , struct V_4 , V_26 ) ;
struct V_3 * V_8 = F_15 ( V_5 ) ;
struct V_20 * V_21 ;
unsigned int V_23 ;
V_21 = F_14 ( V_28 , struct V_20 , V_30 ) ;
V_23 = F_11 ( V_21 ) -> V_23 ;
if ( V_23 < V_8 -> V_17 )
return V_28 -> V_31 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_15 , V_32 ;
F_17 ( V_7 , V_33 , 0x05 ) ;
V_15 = F_8 ( V_7 , V_16 ) ;
if ( V_15 < 0 ) {
F_18 ( & V_7 -> V_5 , L_4
L_5 , V_15 ) ;
return - V_34 ;
}
V_32 = V_15 ;
V_15 &= ~ V_35 ;
if ( V_15 != V_32 ) {
F_19 ( & V_7 -> V_5 , L_6 ) ;
F_17 ( V_7 , V_16 , V_15 ) ;
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
enum V_38 V_39 ;
struct V_40 * V_41 = V_7 -> V_41 ;
const char * V_42 [] = { L_7 , L_8 , L_9 } ;
T_5 V_1 ;
if ( ! F_21 ( V_41 , V_43 ) )
return - V_34 ;
V_1 = F_8 ( V_7 , V_44 ) ;
if ( V_1 != V_45 )
return - V_34 ;
V_1 = F_8 ( V_7 , V_46 ) ;
switch ( V_1 ) {
case V_47 :
V_39 = V_48 ;
break;
case V_49 :
V_39 = V_50 ;
break;
case V_51 :
V_39 = V_52 ;
break;
default:
return - V_34 ;
}
F_22 ( V_37 -> type , V_53 [ V_39 ] . V_54 , V_55 ) ;
F_19 ( & V_41 -> V_5 , L_10 ,
V_42 [ V_39 ] , V_7 -> V_56 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
const struct V_57 * V_58 )
{
struct V_3 * V_8 ;
int V_59 ;
V_8 = F_24 ( sizeof( struct V_3 ) , V_60 ) ;
if ( ! V_8 )
return - V_61 ;
F_25 ( V_7 , V_8 ) ;
F_26 ( & V_8 -> V_10 ) ;
V_8 -> V_17 = V_58 -> V_62 ;
V_59 = F_16 ( V_7 ) ;
if ( V_59 )
goto V_63;
V_59 = F_27 ( & V_7 -> V_5 . V_26 , & V_64 ) ;
if ( V_59 )
goto V_63;
V_8 -> V_65 = F_28 ( & V_7 -> V_5 ) ;
if ( F_29 ( V_8 -> V_65 ) ) {
V_59 = F_30 ( V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
goto V_66;
}
return 0 ;
V_66:
F_31 ( & V_7 -> V_5 . V_26 , & V_64 ) ;
V_63:
F_32 ( V_8 ) ;
return V_59 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_3 * V_8 = F_5 ( V_7 ) ;
F_34 ( V_8 -> V_65 ) ;
F_31 ( & V_7 -> V_5 . V_26 , & V_64 ) ;
F_32 ( V_8 ) ;
return 0 ;
}
