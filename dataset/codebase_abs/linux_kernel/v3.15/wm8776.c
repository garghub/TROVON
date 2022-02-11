static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 , V_4 , 0 ) ;
}
static int F_4 ( struct V_7 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
int V_3 , V_10 , V_11 ;
switch ( V_8 -> V_12 -> V_13 ) {
case V_14 :
V_3 = V_15 ;
V_11 = 0x80 ;
break;
case V_16 :
V_3 = V_17 ;
V_11 = 0x100 ;
break;
default:
return - V_18 ;
}
V_10 = 0 ;
switch ( V_9 & V_19 ) {
case V_20 :
break;
case V_21 :
V_11 = 0 ;
break;
default:
return - V_18 ;
}
switch ( V_9 & V_22 ) {
case V_23 :
V_10 |= 0x0002 ;
break;
case V_24 :
break;
case V_25 :
V_10 |= 0x0001 ;
break;
default:
return - V_18 ;
}
switch ( V_9 & V_26 ) {
case V_27 :
break;
case V_28 :
V_10 |= 0x00c ;
break;
case V_29 :
V_10 |= 0x008 ;
break;
case V_30 :
V_10 |= 0x004 ;
break;
default:
return - V_18 ;
}
F_5 ( V_6 , V_3 , 0xf , V_10 ) ;
F_5 ( V_6 , V_31 , 0x180 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_36 * V_37 = F_7 ( V_6 ) ;
int V_38 , V_10 ;
int V_39 , V_11 ;
int V_40 ;
switch ( V_8 -> V_12 -> V_13 ) {
case V_14 :
V_38 = V_15 ;
V_11 = 0x80 ;
V_39 = 4 ;
break;
case V_16 :
V_38 = V_17 ;
V_11 = 0x100 ;
V_39 = 0 ;
break;
default:
return - V_18 ;
}
switch ( F_8 ( F_9 ( V_35 ) ) ) {
case 16 :
V_10 = 0 ;
break;
case 20 :
V_10 = 0x10 ;
break;
case 24 :
V_10 = 0x20 ;
break;
case 32 :
V_10 = 0x30 ;
break;
default:
F_10 ( V_6 -> V_2 , L_1 ,
F_8 ( F_9 ( V_35 ) ) ) ;
return - V_18 ;
}
if ( F_11 ( V_6 , V_31 ) & V_11 ) {
for ( V_40 = 0 ; V_40 < F_12 ( V_41 ) ; V_40 ++ ) {
if ( V_37 -> V_42 [ V_8 -> V_12 -> V_13 ] / F_13 ( V_35 )
== V_41 [ V_40 ] )
break;
}
if ( V_40 == F_12 ( V_41 ) ) {
F_10 ( V_6 -> V_2 ,
L_2 ,
V_37 -> V_42 [ V_8 -> V_12 -> V_13 ] , F_13 ( V_35 ) ) ;
return - V_18 ;
}
F_14 ( V_6 -> V_2 , L_3 , V_41 [ V_40 ] ) ;
F_5 ( V_6 , V_31 ,
0x7 << V_39 , V_40 << V_39 ) ;
} else {
F_14 ( V_6 -> V_2 , L_4 ) ;
}
F_5 ( V_6 , V_38 , 0x30 , V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , int V_43 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
return F_3 ( V_6 , V_44 , ! ! V_43 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
int V_45 , unsigned int V_46 , int V_47 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_36 * V_37 = F_7 ( V_6 ) ;
if ( F_17 ( V_8 -> V_12 -> V_13 >= F_12 ( V_37 -> V_42 ) ) )
return - V_18 ;
V_37 -> V_42 [ V_8 -> V_12 -> V_13 ] = V_46 ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
enum V_48 V_49 )
{
struct V_36 * V_37 = F_7 ( V_6 ) ;
switch ( V_49 ) {
case V_50 :
break;
case V_51 :
break;
case V_52 :
if ( V_6 -> V_53 . V_54 == V_55 ) {
F_19 ( V_37 -> V_56 ) ;
F_5 ( V_6 , V_57 , 1 , 0 ) ;
}
break;
case V_55 :
F_5 ( V_6 , V_57 , 1 , 1 ) ;
break;
}
V_6 -> V_53 . V_54 = V_49 ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
F_18 ( V_6 , V_55 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
F_18 ( V_6 , V_52 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_58 = 0 ;
V_58 = F_2 ( V_6 ) ;
if ( V_58 < 0 ) {
F_10 ( V_6 -> V_2 , L_5 , V_58 ) ;
return V_58 ;
}
F_18 ( V_6 , V_52 ) ;
F_5 ( V_6 , V_59 , 0x100 , 0x100 ) ;
F_5 ( V_6 , V_60 , 0x100 , 0x100 ) ;
return V_58 ;
}
static int F_23 ( struct V_5 * V_6 )
{
F_18 ( V_6 , V_55 ) ;
return 0 ;
}
static int F_24 ( struct V_61 * V_62 )
{
struct V_36 * V_37 ;
int V_58 ;
V_37 = F_25 ( & V_62 -> V_2 , sizeof( struct V_36 ) ,
V_63 ) ;
if ( V_37 == NULL )
return - V_64 ;
V_37 -> V_56 = F_26 ( V_62 , & V_65 ) ;
if ( F_27 ( V_37 -> V_56 ) )
return F_28 ( V_37 -> V_56 ) ;
F_29 ( V_62 , V_37 ) ;
V_58 = F_30 ( & V_62 -> V_2 ,
& V_66 , V_67 , F_12 ( V_67 ) ) ;
return V_58 ;
}
static int F_31 ( struct V_61 * V_62 )
{
F_32 ( & V_62 -> V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_68 * V_69 ,
const struct V_70 * V_13 )
{
struct V_36 * V_37 ;
int V_58 ;
V_37 = F_25 ( & V_69 -> V_2 , sizeof( struct V_36 ) ,
V_63 ) ;
if ( V_37 == NULL )
return - V_64 ;
V_37 -> V_56 = F_34 ( V_69 , & V_65 ) ;
if ( F_27 ( V_37 -> V_56 ) )
return F_28 ( V_37 -> V_56 ) ;
F_35 ( V_69 , V_37 ) ;
V_58 = F_30 ( & V_69 -> V_2 ,
& V_66 , V_67 , F_12 ( V_67 ) ) ;
return V_58 ;
}
static int F_36 ( struct V_68 * V_71 )
{
F_32 ( & V_71 -> V_2 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
int V_58 = 0 ;
#if F_38 ( V_72 )
V_58 = F_39 ( & V_73 ) ;
if ( V_58 != 0 ) {
F_40 ( V_74 L_6 ,
V_58 ) ;
}
#endif
#if F_41 ( V_75 )
V_58 = F_42 ( & V_76 ) ;
if ( V_58 != 0 ) {
F_40 ( V_74 L_7 ,
V_58 ) ;
}
#endif
return V_58 ;
}
static void T_2 F_43 ( void )
{
#if F_38 ( V_72 )
F_44 ( & V_73 ) ;
#endif
#if F_41 ( V_75 )
F_45 ( & V_76 ) ;
#endif
}
