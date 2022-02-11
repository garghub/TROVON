static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( V_4 , V_5 ,
F_3 ( V_5 ) ) ;
F_4 ( V_4 , V_6 , F_3 ( V_6 ) ) ;
return 0 ;
}
static inline int F_5 ( int V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_8 == V_8 && V_10 [ V_9 ] . V_7 == V_7 )
return V_9 ;
}
F_6 ( V_11 L_1 ,
V_7 , V_8 ) ;
return - V_12 ;
}
static int F_7 ( struct V_13 * V_14 ,
int V_15 , unsigned int V_16 , int V_17 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
switch ( V_16 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_19 -> V_20 = V_16 ;
return 0 ;
}
return - V_12 ;
}
static int F_9 ( struct V_13 * V_14 ,
unsigned int V_21 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
T_1 V_22 = 0 ;
switch ( V_21 & V_23 ) {
case V_24 :
V_22 = 0x0040 ;
break;
case V_25 :
break;
default:
return - V_12 ;
}
switch ( V_21 & V_26 ) {
case V_27 :
V_22 |= 0x0002 ;
break;
case V_28 :
break;
case V_29 :
V_22 |= 0x0001 ;
break;
case V_30 :
V_22 |= 0x0003 ;
break;
case V_31 :
V_22 |= 0x0013 ;
break;
default:
return - V_12 ;
}
switch ( V_21 & V_32 ) {
case V_33 :
break;
case V_34 :
V_22 |= 0x0090 ;
break;
case V_35 :
V_22 |= 0x0080 ;
break;
case V_36 :
V_22 |= 0x0010 ;
break;
default:
return - V_12 ;
}
F_10 ( V_2 , V_37 , V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_13 * V_42 )
{
struct V_43 * V_44 = V_39 -> V_45 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
T_1 V_22 = F_12 ( V_2 , V_37 ) & 0x1f3 ;
T_1 V_46 = F_12 ( V_2 , V_47 ) & 0x1c0 ;
int V_48 = F_5 ( V_19 -> V_20 , F_13 ( V_41 ) ) ;
switch ( F_14 ( V_41 ) ) {
case V_49 :
break;
case V_50 :
V_22 |= 0x0004 ;
break;
case V_51 :
V_22 |= 0x0008 ;
break;
case V_52 :
V_22 |= 0x000c ;
break;
}
F_10 ( V_2 , V_37 , V_22 ) ;
if ( V_48 >= 0 )
F_10 ( V_2 , V_47 , V_46 |
( V_10 [ V_48 ] . V_53 << 1 ) | V_10 [ V_48 ] . V_54 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_42 , int V_55 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
T_1 V_56 = F_12 ( V_2 , V_57 ) & 0xfff7 ;
if ( V_55 )
F_10 ( V_2 , V_57 , V_56 | 0x8 ) ;
else
F_10 ( V_2 , V_57 , V_56 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_58 V_59 )
{
T_1 V_60 = F_12 ( V_2 , V_61 ) & 0xfe3e ;
switch ( V_59 ) {
case V_62 :
F_10 ( V_2 , V_61 , V_60 | 0x00c0 ) ;
break;
case V_63 :
break;
case V_64 :
if ( V_2 -> V_4 . V_65 == V_66 ) {
F_10 ( V_2 , V_61 , V_60 | 0x01c1 ) ;
F_17 ( 1000 ) ;
}
F_10 ( V_2 , V_61 , V_60 | 0x0141 ) ;
break;
case V_66 :
F_10 ( V_2 , V_61 , 0x0001 ) ;
break;
}
V_2 -> V_4 . V_65 = V_59 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_67 )
{
F_16 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_9 ;
T_3 V_68 [ 2 ] ;
T_1 * V_69 = V_2 -> V_70 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_71 ) ; V_9 ++ ) {
if ( V_9 == V_72 )
continue;
V_68 [ 0 ] = ( V_9 << 1 ) | ( ( V_69 [ V_9 ] >> 8 ) & 0x0001 ) ;
V_68 [ 1 ] = V_69 [ V_9 ] & 0x00ff ;
V_2 -> V_73 ( V_2 -> V_74 , V_68 , 2 ) ;
}
F_16 ( V_2 , V_64 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_8 ( V_2 ) ;
int V_75 , V_76 ;
V_76 = F_21 ( V_2 , 7 , 9 , V_19 -> V_77 ) ;
if ( V_76 < 0 ) {
F_6 ( V_11 L_2 , V_76 ) ;
return V_76 ;
}
V_76 = F_22 ( V_2 ) ;
if ( V_76 < 0 ) {
F_6 ( V_11 L_3 , V_76 ) ;
return V_76 ;
}
F_16 ( V_2 , V_64 ) ;
V_75 = F_12 ( V_2 , V_78 ) ;
F_10 ( V_2 , V_78 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_79 ) ;
F_10 ( V_2 , V_79 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_80 ) ;
F_10 ( V_2 , V_80 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_81 ) ;
F_10 ( V_2 , V_81 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_82 ) ;
F_10 ( V_2 , V_82 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_83 ) ;
F_10 ( V_2 , V_83 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_84 ) ;
F_10 ( V_2 , V_84 , V_75 | 0x0100 ) ;
V_75 = F_12 ( V_2 , V_85 ) ;
F_10 ( V_2 , V_85 , V_75 | 0x0100 ) ;
F_23 ( V_2 , V_86 ,
F_3 ( V_86 ) ) ;
F_1 ( V_2 ) ;
return V_76 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_66 ) ;
return 0 ;
}
static int T_4 F_25 ( struct V_87 * V_88 )
{
struct V_18 * V_19 ;
int V_76 ;
V_19 = F_26 ( sizeof( struct V_18 ) , V_89 ) ;
if ( V_19 == NULL )
return - V_90 ;
V_19 -> V_77 = V_91 ;
F_27 ( V_88 , V_19 ) ;
V_76 = F_28 ( & V_88 -> V_92 ,
& V_93 , & V_94 , 1 ) ;
if ( V_76 < 0 )
F_29 ( V_19 ) ;
return V_76 ;
}
static int T_5 F_30 ( struct V_87 * V_88 )
{
F_31 ( & V_88 -> V_92 ) ;
F_29 ( F_32 ( V_88 ) ) ;
return 0 ;
}
static T_4 int F_33 ( struct V_95 * V_96 ,
const struct V_97 * V_98 )
{
struct V_18 * V_19 ;
int V_76 ;
V_19 = F_26 ( sizeof( struct V_18 ) , V_89 ) ;
if ( V_19 == NULL )
return - V_90 ;
F_34 ( V_96 , V_19 ) ;
V_19 -> V_77 = V_99 ;
V_76 = F_28 ( & V_96 -> V_92 ,
& V_93 , & V_94 , 1 ) ;
if ( V_76 < 0 )
F_29 ( V_19 ) ;
return V_76 ;
}
static T_5 int F_35 ( struct V_95 * V_100 )
{
F_31 ( & V_100 -> V_92 ) ;
F_29 ( F_36 ( V_100 ) ) ;
return 0 ;
}
static int T_6 F_37 ( void )
{
int V_76 = 0 ;
#if F_38 ( V_101 ) || F_38 ( V_102 )
V_76 = F_39 ( & V_103 ) ;
if ( V_76 != 0 ) {
F_6 ( V_11 L_4 ,
V_76 ) ;
}
#endif
#if F_38 ( V_104 )
V_76 = F_40 ( & V_105 ) ;
if ( V_76 != 0 ) {
F_6 ( V_11 L_5 ,
V_76 ) ;
}
#endif
return V_76 ;
}
static void T_7 F_41 ( void )
{
#if F_38 ( V_101 ) || F_38 ( V_102 )
F_42 ( & V_103 ) ;
#endif
#if F_38 ( V_104 )
F_43 ( & V_105 ) ;
#endif
}
