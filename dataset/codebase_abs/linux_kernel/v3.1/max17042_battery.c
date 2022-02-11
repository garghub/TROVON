static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_1 ( V_2 , V_9 [ V_11 ] . V_12 , V_9 [ V_11 ] . V_9 ) ;
}
static int F_7 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
union V_17 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_14 ,
struct V_19 , V_21 ) ;
switch ( V_16 ) {
case V_22 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_24 ) ;
if ( V_18 -> V_23 & V_25 )
V_18 -> V_23 = 0 ;
else
V_18 -> V_23 = 1 ;
break;
case V_26 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_27 ) ;
break;
case V_28 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_29 ) ;
V_18 -> V_23 >>= 8 ;
V_18 -> V_23 *= 20000 ;
break;
case V_30 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_31 ) ;
V_18 -> V_23 >>= 7 ;
V_18 -> V_23 *= 10000 ;
break;
case V_32 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_33 ) * 83 ;
break;
case V_34 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_35 ) * 83 ;
break;
case V_36 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_37 ) / 256 ;
break;
case V_38 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_39 ) ;
if ( ( V_18 -> V_23 / 256 ) >= V_40 )
V_18 -> V_23 = 1 ;
else if ( V_18 -> V_23 >= 0 )
V_18 -> V_23 = 0 ;
break;
case V_41 :
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_42 ) ;
if ( V_18 -> V_23 & 0x8000 ) {
V_18 -> V_23 = ( 0x7fff & ~ V_18 -> V_23 ) + 1 ;
V_18 -> V_23 *= - 1 ;
}
V_18 -> V_23 = V_18 -> V_23 * 10 / 256 ;
break;
case V_43 :
if ( V_20 -> V_44 -> V_45 ) {
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_46 ) ;
if ( V_18 -> V_23 & 0x8000 ) {
V_18 -> V_23 = ~ V_18 -> V_23 & 0x7fff ;
V_18 -> V_23 ++ ;
V_18 -> V_23 *= - 1 ;
}
V_18 -> V_23 >>= 4 ;
V_18 -> V_23 *= 1000000 * 25 / V_20 -> V_44 -> V_47 ;
} else {
return - V_48 ;
}
break;
case V_49 :
if ( V_20 -> V_44 -> V_45 ) {
V_18 -> V_23 = F_4 ( V_20 -> V_2 ,
V_50 ) ;
if ( V_18 -> V_23 & 0x8000 ) {
V_18 -> V_23 = ~ V_18 -> V_23 & 0x7fff ;
V_18 -> V_23 ++ ;
V_18 -> V_23 *= - 1 ;
}
V_18 -> V_23 *= 1562500 / V_20 -> V_44 -> V_47 ;
} else {
return - V_48 ;
}
break;
default:
return - V_48 ;
}
return 0 ;
}
static int T_3 F_9 ( struct V_1 * V_2 ,
const struct V_51 * V_52 )
{
struct V_53 * V_54 = F_10 ( V_2 -> V_6 . V_55 ) ;
struct V_19 * V_20 ;
int V_5 ;
if ( ! F_11 ( V_54 , V_56 ) )
return - V_57 ;
V_20 = F_12 ( sizeof( * V_20 ) , V_58 ) ;
if ( ! V_20 )
return - V_59 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_44 = V_2 -> V_6 . V_60 ;
F_13 ( V_2 , V_20 ) ;
V_20 -> V_21 . V_61 = L_2 ;
V_20 -> V_21 . type = V_62 ;
V_20 -> V_21 . V_63 = F_7 ;
V_20 -> V_21 . V_64 = V_65 ;
V_20 -> V_21 . V_66 = F_14 ( V_65 ) ;
if ( ! V_20 -> V_44 -> V_45 )
V_20 -> V_21 . V_66 -= 2 ;
V_5 = F_15 ( & V_2 -> V_6 , & V_20 -> V_21 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
F_16 ( V_20 ) ;
return V_5 ;
}
if ( V_20 -> V_44 -> V_67 )
F_6 ( V_2 , V_20 -> V_44 -> V_67 ,
V_20 -> V_44 -> V_68 ) ;
if ( ! V_20 -> V_44 -> V_45 ) {
F_1 ( V_2 , V_69 , 0x0000 ) ;
F_1 ( V_2 , V_70 , 0x0003 ) ;
F_1 ( V_2 , V_71 , 0x0007 ) ;
} else {
if ( V_20 -> V_44 -> V_47 == 0 )
V_20 -> V_44 -> V_47 = V_72 ;
}
return 0 ;
}
static int T_4 F_17 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_18 ( V_2 ) ;
F_19 ( & V_20 -> V_21 ) ;
F_16 ( V_20 ) ;
return 0 ;
}
static int T_5 F_20 ( void )
{
return F_21 ( & V_73 ) ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_73 ) ;
}
