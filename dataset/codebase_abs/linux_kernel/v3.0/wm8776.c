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
V_8 = 0 ;
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
switch ( F_7 ( V_33 ) ) {
case V_39 :
break;
case V_40 :
V_8 |= 0x10 ;
break;
case V_41 :
V_8 |= 0x20 ;
break;
case V_42 :
V_8 |= 0x30 ;
break;
}
if ( F_8 ( V_2 , V_29 ) & V_9 ) {
for ( V_38 = 0 ; V_38 < F_9 ( V_43 ) ; V_38 ++ ) {
if ( V_35 -> V_44 [ V_5 -> V_10 -> V_11 ] / F_10 ( V_33 )
== V_43 [ V_38 ] )
break;
}
if ( V_38 == F_9 ( V_43 ) ) {
F_11 ( V_2 -> V_45 ,
L_1 ,
V_35 -> V_44 [ V_5 -> V_10 -> V_11 ] , F_10 ( V_33 ) ) ;
return - V_16 ;
}
F_12 ( V_2 -> V_45 , L_2 , V_43 [ V_38 ] ) ;
F_4 ( V_2 , V_29 ,
0x7 << V_37 , V_38 << V_37 ) ;
} else {
F_12 ( V_2 -> V_45 , L_3 ) ;
}
F_4 ( V_2 , V_36 , 0x30 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 , int V_46 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
return F_2 ( V_2 , V_47 , ! ! V_46 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
int V_48 , unsigned int V_49 , int V_50 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_34 * V_35 = F_6 ( V_2 ) ;
F_15 ( V_5 -> V_10 -> V_11 >= F_9 ( V_35 -> V_44 ) ) ;
V_35 -> V_44 [ V_5 -> V_10 -> V_11 ] = V_49 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_51 V_52 )
{
switch ( V_52 ) {
case V_53 :
break;
case V_54 :
break;
case V_55 :
if ( V_2 -> V_56 . V_57 == V_58 ) {
F_4 ( V_2 , V_59 , 1 , 0 ) ;
}
break;
case V_58 :
F_4 ( V_2 , V_59 , 1 , 1 ) ;
break;
}
V_2 -> V_56 . V_57 = V_52 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_60 )
{
F_16 ( V_2 , V_58 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_38 ;
T_2 V_61 [ 2 ] ;
T_3 * V_62 = V_2 -> V_63 ;
for ( V_38 = 0 ; V_38 < F_9 ( V_64 ) ; V_38 ++ ) {
if ( V_62 [ V_38 ] == V_64 [ V_38 ] )
continue;
V_61 [ 0 ] = ( V_38 << 1 ) | ( ( V_62 [ V_38 ] >> 8 ) & 0x0001 ) ;
V_61 [ 1 ] = V_62 [ V_38 ] & 0x00ff ;
V_2 -> V_65 ( V_2 -> V_66 , V_61 , 2 ) ;
}
F_16 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_6 ( V_2 ) ;
struct V_67 * V_56 = & V_2 -> V_56 ;
int V_68 = 0 ;
V_68 = F_20 ( V_2 , 7 , 9 , V_35 -> V_69 ) ;
if ( V_68 < 0 ) {
F_11 ( V_2 -> V_45 , L_4 , V_68 ) ;
return V_68 ;
}
V_68 = F_1 ( V_2 ) ;
if ( V_68 < 0 ) {
F_11 ( V_2 -> V_45 , L_5 , V_68 ) ;
return V_68 ;
}
F_16 ( V_2 , V_55 ) ;
F_4 ( V_2 , V_70 , 0x100 , 0x100 ) ;
F_4 ( V_2 , V_71 , 0x100 , 0x100 ) ;
F_21 ( V_2 , V_72 ,
F_9 ( V_72 ) ) ;
F_22 ( V_56 , V_73 ,
F_9 ( V_73 ) ) ;
F_23 ( V_56 , V_74 , F_9 ( V_74 ) ) ;
return V_68 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_58 ) ;
return 0 ;
}
static int T_4 F_25 ( struct V_75 * V_76 )
{
struct V_34 * V_35 ;
int V_68 ;
V_35 = F_26 ( sizeof( struct V_34 ) , V_77 ) ;
if ( V_35 == NULL )
return - V_78 ;
V_35 -> V_69 = V_79 ;
F_27 ( V_76 , V_35 ) ;
V_68 = F_28 ( & V_76 -> V_45 ,
& V_80 , V_81 , F_9 ( V_81 ) ) ;
if ( V_68 < 0 )
F_29 ( V_35 ) ;
return V_68 ;
}
static int T_5 F_30 ( struct V_75 * V_76 )
{
F_31 ( & V_76 -> V_45 ) ;
F_29 ( F_32 ( V_76 ) ) ;
return 0 ;
}
static T_4 int F_33 ( struct V_82 * V_83 ,
const struct V_84 * V_11 )
{
struct V_34 * V_35 ;
int V_68 ;
V_35 = F_26 ( sizeof( struct V_34 ) , V_77 ) ;
if ( V_35 == NULL )
return - V_78 ;
F_34 ( V_83 , V_35 ) ;
V_35 -> V_69 = V_85 ;
V_68 = F_28 ( & V_83 -> V_45 ,
& V_80 , V_81 , F_9 ( V_81 ) ) ;
if ( V_68 < 0 )
F_29 ( V_35 ) ;
return V_68 ;
}
static T_5 int F_35 ( struct V_82 * V_86 )
{
F_31 ( & V_86 -> V_45 ) ;
F_29 ( F_36 ( V_86 ) ) ;
return 0 ;
}
static int T_6 F_37 ( void )
{
int V_68 = 0 ;
#if F_38 ( V_87 ) || F_38 ( V_88 )
V_68 = F_39 ( & V_89 ) ;
if ( V_68 != 0 ) {
F_40 ( V_90 L_6 ,
V_68 ) ;
}
#endif
#if F_38 ( V_91 )
V_68 = F_41 ( & V_92 ) ;
if ( V_68 != 0 ) {
F_40 ( V_90 L_7 ,
V_68 ) ;
}
#endif
return V_68 ;
}
static void T_7 F_42 ( void )
{
#if F_38 ( V_87 ) || F_38 ( V_88 )
F_43 ( & V_89 ) ;
#endif
#if F_38 ( V_91 )
F_44 ( & V_92 ) ;
#endif
}
