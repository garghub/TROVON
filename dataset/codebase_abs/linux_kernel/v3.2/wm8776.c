static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
int V_7 , V_8 , V_9 ;
switch ( V_5 -> V_10 -> V_11 ) {
case V_12 :
V_7 = V_13 ;
V_9 = 0x80 ;
break;
case V_14 :
V_7 = V_15 ;
V_9 = 0x100 ;
break;
default:
return - V_16 ;
}
V_8 = 0 ;
switch ( V_6 & V_17 ) {
case V_18 :
break;
case V_19 :
V_9 = 0 ;
break;
default:
return - V_16 ;
}
switch ( V_6 & V_20 ) {
case V_21 :
V_8 |= 0x0002 ;
break;
case V_22 :
break;
case V_23 :
V_8 |= 0x0001 ;
break;
default:
return - V_16 ;
}
switch ( V_6 & V_24 ) {
case V_25 :
break;
case V_26 :
V_8 |= 0x00c ;
break;
case V_27 :
V_8 |= 0x008 ;
break;
case V_28 :
V_8 |= 0x004 ;
break;
default:
return - V_16 ;
}
F_4 ( V_2 , V_7 , 0xf , V_8 ) ;
F_4 ( V_2 , V_29 , 0x180 , V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_34 * V_35 = F_6 ( V_2 ) ;
int V_36 , V_8 ;
int V_37 , V_9 ;
int V_38 ;
switch ( V_5 -> V_10 -> V_11 ) {
case V_12 :
V_36 = V_13 ;
V_9 = 0x80 ;
V_37 = 4 ;
break;
case V_14 :
V_36 = V_15 ;
V_9 = 0x100 ;
V_37 = 0 ;
break;
default:
return - V_16 ;
}
switch ( F_7 ( F_8 ( V_33 ) ) ) {
case 16 :
V_8 = 0 ;
break;
case 20 :
V_8 = 0x10 ;
break;
case 24 :
V_8 = 0x20 ;
break;
case 32 :
V_8 = 0x30 ;
break;
default:
F_9 ( V_2 -> V_39 , L_1 ,
F_7 ( F_8 ( V_33 ) ) ) ;
return - V_16 ;
}
if ( F_10 ( V_2 , V_29 ) & V_9 ) {
for ( V_38 = 0 ; V_38 < F_11 ( V_40 ) ; V_38 ++ ) {
if ( V_35 -> V_41 [ V_5 -> V_10 -> V_11 ] / F_12 ( V_33 )
== V_40 [ V_38 ] )
break;
}
if ( V_38 == F_11 ( V_40 ) ) {
F_9 ( V_2 -> V_39 ,
L_2 ,
V_35 -> V_41 [ V_5 -> V_10 -> V_11 ] , F_12 ( V_33 ) ) ;
return - V_16 ;
}
F_13 ( V_2 -> V_39 , L_3 , V_40 [ V_38 ] ) ;
F_4 ( V_2 , V_29 ,
0x7 << V_37 , V_38 << V_37 ) ;
} else {
F_13 ( V_2 -> V_39 , L_4 ) ;
}
F_4 ( V_2 , V_36 , 0x30 , V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 , int V_42 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
return F_2 ( V_2 , V_43 , ! ! V_42 ) ;
}
static int F_15 ( struct V_4 * V_5 ,
int V_44 , unsigned int V_45 , int V_46 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_34 * V_35 = F_6 ( V_2 ) ;
F_16 ( V_5 -> V_10 -> V_11 >= F_11 ( V_35 -> V_41 ) ) ;
V_35 -> V_41 [ V_5 -> V_10 -> V_11 ] = V_45 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_47 V_48 )
{
switch ( V_48 ) {
case V_49 :
break;
case V_50 :
break;
case V_51 :
if ( V_2 -> V_52 . V_53 == V_54 ) {
F_18 ( V_2 ) ;
F_4 ( V_2 , V_55 , 1 , 0 ) ;
}
break;
case V_54 :
F_4 ( V_2 , V_55 , 1 , 1 ) ;
break;
}
V_2 -> V_52 . V_53 = V_48 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_56 )
{
F_17 ( V_2 , V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_6 ( V_2 ) ;
struct V_57 * V_52 = & V_2 -> V_52 ;
int V_58 = 0 ;
V_58 = F_22 ( V_2 , 7 , 9 , V_35 -> V_59 ) ;
if ( V_58 < 0 ) {
F_9 ( V_2 -> V_39 , L_5 , V_58 ) ;
return V_58 ;
}
V_58 = F_1 ( V_2 ) ;
if ( V_58 < 0 ) {
F_9 ( V_2 -> V_39 , L_6 , V_58 ) ;
return V_58 ;
}
F_17 ( V_2 , V_51 ) ;
F_4 ( V_2 , V_60 , 0x100 , 0x100 ) ;
F_4 ( V_2 , V_61 , 0x100 , 0x100 ) ;
F_23 ( V_2 , V_62 ,
F_11 ( V_62 ) ) ;
F_24 ( V_52 , V_63 ,
F_11 ( V_63 ) ) ;
F_25 ( V_52 , V_64 , F_11 ( V_64 ) ) ;
return V_58 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_54 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_65 * V_66 )
{
struct V_34 * V_35 ;
int V_58 ;
V_35 = F_28 ( sizeof( struct V_34 ) , V_67 ) ;
if ( V_35 == NULL )
return - V_68 ;
V_35 -> V_59 = V_69 ;
F_29 ( V_66 , V_35 ) ;
V_58 = F_30 ( & V_66 -> V_39 ,
& V_70 , V_71 , F_11 ( V_71 ) ) ;
if ( V_58 < 0 )
F_31 ( V_35 ) ;
return V_58 ;
}
static int T_3 F_32 ( struct V_65 * V_66 )
{
F_33 ( & V_66 -> V_39 ) ;
F_31 ( F_34 ( V_66 ) ) ;
return 0 ;
}
static T_2 int F_35 ( struct V_72 * V_73 ,
const struct V_74 * V_11 )
{
struct V_34 * V_35 ;
int V_58 ;
V_35 = F_28 ( sizeof( struct V_34 ) , V_67 ) ;
if ( V_35 == NULL )
return - V_68 ;
F_36 ( V_73 , V_35 ) ;
V_35 -> V_59 = V_75 ;
V_58 = F_30 ( & V_73 -> V_39 ,
& V_70 , V_71 , F_11 ( V_71 ) ) ;
if ( V_58 < 0 )
F_31 ( V_35 ) ;
return V_58 ;
}
static T_3 int F_37 ( struct V_72 * V_76 )
{
F_33 ( & V_76 -> V_39 ) ;
F_31 ( F_38 ( V_76 ) ) ;
return 0 ;
}
static int T_4 F_39 ( void )
{
int V_58 = 0 ;
#if F_40 ( V_77 ) || F_40 ( V_78 )
V_58 = F_41 ( & V_79 ) ;
if ( V_58 != 0 ) {
F_42 ( V_80 L_7 ,
V_58 ) ;
}
#endif
#if F_40 ( V_81 )
V_58 = F_43 ( & V_82 ) ;
if ( V_58 != 0 ) {
F_42 ( V_80 L_8 ,
V_58 ) ;
}
#endif
return V_58 ;
}
static void T_5 F_44 ( void )
{
#if F_40 ( V_77 ) || F_40 ( V_78 )
F_45 ( & V_79 ) ;
#endif
#if F_40 ( V_81 )
F_46 ( & V_82 ) ;
#endif
}
