static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 && V_4 [ V_3 ] . V_1 == V_1 )
return V_3 ;
}
F_3 ( V_5 L_1 ,
V_1 , V_2 ) ;
return - V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
switch ( V_10 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_15 -> V_16 = V_10 ;
return 0 ;
}
return - V_6 ;
}
static int F_6 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 V_18 = 0 ;
switch ( V_17 & V_19 ) {
case V_20 :
V_18 = 0x0040 ;
break;
case V_21 :
break;
default:
return - V_6 ;
}
switch ( V_17 & V_22 ) {
case V_23 :
V_18 |= 0x0002 ;
break;
case V_24 :
break;
case V_25 :
V_18 |= 0x0001 ;
break;
case V_26 :
V_18 |= 0x0003 ;
break;
case V_27 :
V_18 |= 0x0013 ;
break;
default:
return - V_6 ;
}
switch ( V_17 & V_28 ) {
case V_29 :
break;
case V_30 :
V_18 |= 0x0090 ;
break;
case V_31 :
V_18 |= 0x0080 ;
break;
case V_32 :
V_18 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_7 ( V_13 , V_33 , V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_7 * V_38 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
struct V_12 * V_13 = V_40 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_1 V_18 = F_9 ( V_13 , V_33 ) & 0x1f3 ;
T_1 V_42 = F_9 ( V_13 , V_43 ) & 0x1c0 ;
int V_44 = F_1 ( V_15 -> V_16 , F_10 ( V_37 ) ) ;
switch ( F_11 ( V_37 ) ) {
case V_45 :
break;
case V_46 :
V_18 |= 0x0004 ;
break;
case V_47 :
V_18 |= 0x0008 ;
break;
case V_48 :
V_18 |= 0x000c ;
break;
}
F_7 ( V_13 , V_33 , V_18 ) ;
if ( V_44 >= 0 )
F_7 ( V_13 , V_43 , V_42 |
( V_4 [ V_44 ] . V_49 << 1 ) | V_4 [ V_44 ] . V_50 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_38 , int V_51 )
{
struct V_12 * V_13 = V_38 -> V_13 ;
T_1 V_52 = F_9 ( V_13 , V_53 ) & 0xfff7 ;
if ( V_51 )
F_7 ( V_13 , V_53 , V_52 | 0x8 ) ;
else
F_7 ( V_13 , V_53 , V_52 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
enum V_54 V_55 )
{
T_1 V_56 = F_9 ( V_13 , V_57 ) & 0xfe3e ;
switch ( V_55 ) {
case V_58 :
F_7 ( V_13 , V_57 , V_56 | 0x00c0 ) ;
break;
case V_59 :
break;
case V_60 :
if ( V_13 -> V_61 . V_62 == V_63 ) {
F_14 ( V_13 ) ;
F_7 ( V_13 , V_57 , V_56 | 0x01c1 ) ;
F_15 ( 1000 ) ;
}
F_7 ( V_13 , V_57 , V_56 | 0x0141 ) ;
break;
case V_63 :
F_7 ( V_13 , V_57 , 0x0001 ) ;
break;
}
V_13 -> V_61 . V_62 = V_55 ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_63 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_60 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_64 ;
V_64 = F_19 ( V_13 , 7 , 9 , V_15 -> V_65 ) ;
if ( V_64 < 0 ) {
F_3 ( V_5 L_2 , V_64 ) ;
return V_64 ;
}
V_64 = F_20 ( V_13 ) ;
if ( V_64 < 0 ) {
F_3 ( V_5 L_3 , V_64 ) ;
return V_64 ;
}
F_13 ( V_13 , V_60 ) ;
F_21 ( V_13 , V_66 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_67 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_68 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_69 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_70 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_71 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_72 , 0x0100 , 0x0100 ) ;
F_21 ( V_13 , V_73 , 0x0100 , 0x0100 ) ;
return V_64 ;
}
static int F_22 ( struct V_12 * V_13 )
{
F_13 ( V_13 , V_63 ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_74 * V_75 )
{
struct V_14 * V_15 ;
int V_64 ;
V_15 = F_24 ( & V_75 -> V_76 , sizeof( struct V_14 ) ,
V_77 ) ;
if ( V_15 == NULL )
return - V_78 ;
V_15 -> V_65 = V_79 ;
F_25 ( V_75 , V_15 ) ;
V_64 = F_26 ( & V_75 -> V_76 ,
& V_80 , & V_81 , 1 ) ;
return V_64 ;
}
static int T_3 F_27 ( struct V_74 * V_75 )
{
F_28 ( & V_75 -> V_76 ) ;
return 0 ;
}
static T_2 int F_29 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_14 * V_15 ;
int V_64 ;
V_15 = F_24 ( & V_83 -> V_76 , sizeof( struct V_14 ) ,
V_77 ) ;
if ( V_15 == NULL )
return - V_78 ;
F_30 ( V_83 , V_15 ) ;
V_15 -> V_65 = V_86 ;
V_64 = F_26 ( & V_83 -> V_76 ,
& V_80 , & V_81 , 1 ) ;
return V_64 ;
}
static T_3 int F_31 ( struct V_82 * V_87 )
{
F_28 ( & V_87 -> V_76 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
int V_64 = 0 ;
#if F_33 ( V_88 ) || F_33 ( V_89 )
V_64 = F_34 ( & V_90 ) ;
if ( V_64 != 0 ) {
F_3 ( V_5 L_4 ,
V_64 ) ;
}
#endif
#if F_33 ( V_91 )
V_64 = F_35 ( & V_92 ) ;
if ( V_64 != 0 ) {
F_3 ( V_5 L_5 ,
V_64 ) ;
}
#endif
return V_64 ;
}
static void T_5 F_36 ( void )
{
#if F_33 ( V_88 ) || F_33 ( V_89 )
F_37 ( & V_90 ) ;
#endif
#if F_33 ( V_91 )
F_38 ( & V_92 ) ;
#endif
}
