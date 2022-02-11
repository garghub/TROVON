static inline int F_1 ( int V_1 )
{
T_1 V_2 = ( ( T_1 ) V_1 ) >> 11 ;
T_2 V_3 = ( ( ( T_1 ) ( V_1 << 5 ) ) >> 5 ) ;
V_2 += 6 ;
return ( V_2 < 0 ? V_3 > > - V_2 : V_3 << V_2 ) ;
}
static int F_2 ( struct V_4 * V_5 , int V_6 ,
int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_12 :
V_11 = F_5 ( V_5 , V_6 , V_13 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) > F_1 ( V_1 -> V_14 ) )
V_1 -> V_14 = V_11 ;
V_11 = V_1 -> V_14 ;
}
break;
case V_15 :
V_11 = F_5 ( V_5 , V_6 , V_16 ) ;
if ( V_11 >= 0 ) {
if ( V_11 > V_1 -> V_17 [ V_6 ] )
V_1 -> V_17 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_17 [ V_6 ] ;
}
break;
case V_18 :
V_11 = F_5 ( V_5 , V_6 ,
V_19 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) > F_1 ( V_1 -> V_20 ) )
V_1 -> V_20 = V_11 ;
V_11 = V_1 -> V_20 ;
}
break;
case V_21 :
case V_22 :
case V_23 :
V_11 = 0 ;
break;
default:
V_11 = - V_24 ;
break;
}
return V_11 ;
}
static int F_6 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_25 :
V_11 = F_5 ( V_5 , V_6 , V_26 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 ) < F_1 ( V_1 -> V_27 ) )
V_1 -> V_27 = V_11 ;
V_11 = V_1 -> V_27 ;
}
break;
case V_28 :
V_11 = F_5 ( V_5 , V_6 , V_29 ) ;
if ( V_11 >= 0 ) {
if ( V_1 -> V_17 [ V_6 ] && V_11 > V_1 -> V_17 [ V_6 ] )
V_11 = V_1 -> V_17 [ V_6 ] ;
if ( V_11 < V_1 -> V_30 [ V_6 ] )
V_1 -> V_30 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_30 [ V_6 ] ;
}
break;
case V_31 :
V_11 = F_5 ( V_5 , V_6 ,
V_32 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
< F_1 ( V_1 -> V_33 ) )
V_1 -> V_33 = V_11 ;
V_11 = V_1 -> V_33 ;
}
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_11 = - V_38 ;
break;
default:
V_11 = F_2 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_7 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_34 :
V_11 = F_5 ( V_5 , V_6 , V_39 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_40 [ V_6 ] ) )
V_1 -> V_40 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_40 [ V_6 ] ;
}
break;
case V_36 :
V_11 = F_5 ( V_5 , V_6 ,
V_41 ) ;
if ( V_11 >= 0 ) {
if ( F_1 ( V_11 )
> F_1 ( V_1 -> V_42 [ V_6 ] ) )
V_1 -> V_42 [ V_6 ] = V_11 ;
V_11 = V_1 -> V_42 [ V_6 ] ;
}
break;
case V_25 :
case V_28 :
case V_31 :
V_11 = - V_38 ;
break;
case V_35 :
case V_37 :
V_11 = 0 ;
break;
default:
V_11 = F_2 ( V_5 , V_6 , V_7 ) ;
break;
}
return V_11 ;
}
static int F_8 ( struct V_4 * V_5 , int V_6 ,
enum V_43 V_44 )
{
int V_11 ;
if ( V_44 == V_45 )
V_11 = F_9 ( V_5 , V_6 , V_46 ) ;
else
V_11 = F_9 ( V_5 , 0 , V_47 ) ;
return V_11 ;
}
static int F_10 ( struct V_4 * V_5 , int V_6 ,
int V_7 , T_3 V_48 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
struct V_10 * V_1 = F_4 ( V_9 ) ;
int V_11 ;
switch ( V_7 ) {
case V_35 :
V_1 -> V_40 [ V_6 ] = 0x7fff ;
V_11 = F_8 ( V_5 , V_6 , V_1 -> V_44 ) ;
break;
case V_37 :
V_1 -> V_42 [ V_6 ] = 0x7fff ;
V_11 = F_8 ( V_5 , V_6 , V_1 -> V_44 ) ;
break;
case V_21 :
V_1 -> V_30 [ V_6 ] = 0xffff ;
V_1 -> V_17 [ V_6 ] = 0 ;
V_11 = F_8 ( V_5 , V_6 , V_1 -> V_44 ) ;
break;
case V_22 :
V_1 -> V_27 = 0x7bff ;
V_1 -> V_14 = 0 ;
V_11 = F_8 ( V_5 , V_6 , V_1 -> V_44 ) ;
break;
case V_23 :
V_1 -> V_33 = 0x7bff ;
V_1 -> V_20 = 0x7fff ;
V_11 = F_8 ( V_5 , V_6 , V_1 -> V_44 ) ;
break;
default:
V_11 = - V_24 ;
break;
}
return V_11 ;
}
static int F_11 ( struct V_4 * V_5 ,
const struct V_49 * V_44 )
{
int V_50 , V_11 , V_51 ;
struct V_10 * V_1 ;
struct V_8 * V_9 ;
if ( ! F_12 ( V_5 -> V_52 ,
V_53 ) )
return - V_54 ;
V_1 = F_13 ( sizeof( struct V_10 ) , V_55 ) ;
if ( ! V_1 )
return - V_56 ;
V_50 = F_14 ( V_5 , V_57 ) ;
if ( V_50 < 0 ) {
V_11 = V_50 ;
goto V_58;
}
if ( V_50 == V_59 || V_50 == V_60 ) {
V_1 -> V_44 = V_45 ;
} else if ( ( V_50 & V_61 ) == V_62 ) {
V_1 -> V_44 = V_63 ;
} else {
F_15 ( & V_5 -> V_64 , L_1 , V_50 ) ;
V_11 = - V_54 ;
goto V_58;
}
if ( V_1 -> V_44 != V_44 -> V_65 )
F_16 ( & V_5 -> V_64 ,
L_2 ,
V_44 -> V_66 ,
V_67 [ V_1 -> V_44 ] . V_66 ) ;
V_9 = & V_1 -> V_9 ;
V_9 -> V_68 = F_10 ;
V_1 -> V_30 [ 0 ] = 0xffff ;
V_1 -> V_27 = 0x7bff ;
V_1 -> V_33 = 0x7bff ;
V_1 -> V_20 = 0x7fff ;
switch ( V_44 -> V_65 ) {
case V_45 :
V_9 -> V_69 = F_6 ;
V_9 -> V_70 = 8 ;
V_9 -> V_71 [ 0 ] = V_72 | V_73
| V_74 | V_75
| V_76 | V_77 ;
for ( V_51 = 1 ; V_51 < 8 ; V_51 ++ ) {
V_9 -> V_71 [ V_51 ] = V_74
| V_75 ;
V_1 -> V_30 [ V_51 ] = 0xffff ;
}
break;
case V_63 :
V_9 -> V_69 = F_7 ;
V_9 -> V_70 = 2 ;
V_9 -> V_71 [ 0 ] = V_72 | V_78
| V_73
| V_74 | V_75
| V_79 | V_80
| V_81 | V_76
| V_82 | V_77 ;
V_9 -> V_71 [ 1 ] = V_74 | V_75
| V_79 | V_80
| V_81
| V_76 | V_77 ;
V_1 -> V_30 [ 1 ] = 0xffff ;
break;
default:
V_11 = - V_54 ;
goto V_58;
}
V_11 = F_17 ( V_5 , V_44 , V_9 ) ;
if ( V_11 )
goto V_58;
return 0 ;
V_58:
F_18 ( V_1 ) ;
return V_11 ;
}
static int F_19 ( struct V_4 * V_5 )
{
const struct V_8 * V_9 = F_3 ( V_5 ) ;
const struct V_10 * V_1 = F_4 ( V_9 ) ;
F_20 ( V_5 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_83 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_83 ) ;
}
