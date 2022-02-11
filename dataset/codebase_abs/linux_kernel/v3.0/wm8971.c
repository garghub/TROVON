static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( V_4 , V_5 ,
F_3 ( V_5 ) ) ;
F_4 ( V_4 , V_6 , F_3 ( V_6 ) ) ;
return 0 ;
}
static int F_5 ( int V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_8 == V_8 && V_10 [ V_9 ] . V_7 == V_7 )
return V_9 ;
}
return - V_11 ;
}
static int F_6 ( struct V_12 * V_13 ,
int V_14 , unsigned int V_15 , int V_16 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_17 * V_18 = F_7 ( V_2 ) ;
switch ( V_15 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_18 -> V_19 = V_15 ;
return 0 ;
}
return - V_11 ;
}
static int F_8 ( struct V_12 * V_13 ,
unsigned int V_20 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_21 = 0 ;
switch ( V_20 & V_22 ) {
case V_23 :
V_21 = 0x0040 ;
break;
case V_24 :
break;
default:
return - V_11 ;
}
switch ( V_20 & V_25 ) {
case V_26 :
V_21 |= 0x0002 ;
break;
case V_27 :
break;
case V_28 :
V_21 |= 0x0001 ;
break;
case V_29 :
V_21 |= 0x0003 ;
break;
case V_30 :
V_21 |= 0x0013 ;
break;
default:
return - V_11 ;
}
switch ( V_20 & V_31 ) {
case V_32 :
break;
case V_33 :
V_21 |= 0x0090 ;
break;
case V_34 :
V_21 |= 0x0080 ;
break;
case V_35 :
V_21 |= 0x0010 ;
break;
default:
return - V_11 ;
}
F_9 ( V_2 , V_36 , V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_12 * V_41 )
{
struct V_42 * V_43 = V_38 -> V_44 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_17 * V_18 = F_7 ( V_2 ) ;
T_1 V_21 = F_11 ( V_2 , V_36 ) & 0x1f3 ;
T_1 V_45 = F_11 ( V_2 , V_46 ) & 0x1c0 ;
int V_47 = F_5 ( V_18 -> V_19 , F_12 ( V_40 ) ) ;
switch ( F_13 ( V_40 ) ) {
case V_48 :
break;
case V_49 :
V_21 |= 0x0004 ;
break;
case V_50 :
V_21 |= 0x0008 ;
break;
case V_51 :
V_21 |= 0x000c ;
break;
}
F_9 ( V_2 , V_36 , V_21 ) ;
if ( V_47 >= 0 )
F_9 ( V_2 , V_46 , V_45 |
( V_10 [ V_47 ] . V_52 << 1 ) | V_10 [ V_47 ] . V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_41 , int V_54 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_55 = F_11 ( V_2 , V_56 ) & 0xfff7 ;
if ( V_54 )
F_9 ( V_2 , V_56 , V_55 | 0x8 ) ;
else
F_9 ( V_2 , V_56 , V_55 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
T_1 V_59 = F_11 ( V_2 , V_60 ) & 0xfe3e ;
switch ( V_58 ) {
case V_61 :
F_9 ( V_2 , V_60 , V_59 | 0x00c1 ) ;
break;
case V_62 :
break;
case V_63 :
F_9 ( V_2 , V_60 , V_59 | 0x0140 ) ;
break;
case V_64 :
F_9 ( V_2 , V_60 , 0x0001 ) ;
break;
}
V_2 -> V_4 . V_65 = V_58 ;
return 0 ;
}
static void F_16 ( struct V_66 * V_67 )
{
struct V_3 * V_4 =
F_17 ( V_67 , struct V_3 ,
V_68 . V_67 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_15 ( V_2 , V_2 -> V_4 . V_65 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_69 )
{
F_15 ( V_2 , V_64 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_9 ;
T_3 V_70 [ 2 ] ;
T_1 * V_71 = V_2 -> V_72 ;
T_1 V_73 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_74 ) ; V_9 ++ ) {
if ( V_9 + 1 == V_75 )
continue;
V_70 [ 0 ] = ( V_9 << 1 ) | ( ( V_71 [ V_9 ] >> 8 ) & 0x0001 ) ;
V_70 [ 1 ] = V_71 [ V_9 ] & 0x00ff ;
V_2 -> V_76 ( V_2 -> V_77 , V_70 , 2 ) ;
}
F_15 ( V_2 , V_63 ) ;
if ( V_2 -> V_4 . V_78 == V_61 ) {
V_73 = F_11 ( V_2 , V_60 ) & 0xfe3e ;
F_9 ( V_2 , V_60 , V_73 | 0x01c0 ) ;
V_2 -> V_4 . V_65 = V_61 ;
F_20 ( V_79 , & V_2 -> V_4 . V_68 ,
F_21 ( 1000 ) ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
int V_80 = 0 ;
T_1 V_73 ;
V_80 = F_23 ( V_2 , 7 , 9 , V_18 -> V_81 ) ;
if ( V_80 < 0 ) {
F_24 ( V_82 L_1 , V_80 ) ;
return V_80 ;
}
F_25 ( & V_2 -> V_4 . V_68 , F_16 ) ;
V_79 = F_26 ( L_2 ) ;
if ( V_79 == NULL )
return - V_83 ;
F_27 ( V_2 ) ;
V_73 = F_11 ( V_2 , V_60 ) & 0xfe3e ;
F_9 ( V_2 , V_60 , V_73 | 0x01c0 ) ;
V_2 -> V_4 . V_65 = V_63 ;
F_20 ( V_79 , & V_2 -> V_4 . V_68 ,
F_21 ( 1000 ) ) ;
V_73 = F_11 ( V_2 , V_84 ) ;
F_9 ( V_2 , V_84 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_85 ) ;
F_9 ( V_2 , V_85 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_86 ) ;
F_9 ( V_2 , V_86 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_87 ) ;
F_9 ( V_2 , V_87 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_88 ) ;
F_9 ( V_2 , V_88 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_89 ) ;
F_9 ( V_2 , V_89 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_90 ) ;
F_9 ( V_2 , V_90 , V_73 | 0x0100 ) ;
V_73 = F_11 ( V_2 , V_91 ) ;
F_9 ( V_2 , V_91 , V_73 | 0x0100 ) ;
F_28 ( V_2 , V_92 ,
F_3 ( V_92 ) ) ;
F_1 ( V_2 ) ;
return V_80 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_64 ) ;
if ( V_79 )
F_30 ( V_79 ) ;
return 0 ;
}
static T_4 int F_31 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
struct V_17 * V_18 ;
int V_80 ;
V_18 = F_32 ( sizeof( struct V_17 ) , V_97 ) ;
if ( V_18 == NULL )
return - V_83 ;
V_18 -> V_81 = V_98 ;
F_33 ( V_94 , V_18 ) ;
V_80 = F_34 ( & V_94 -> V_99 ,
& V_100 , & V_101 , 1 ) ;
if ( V_80 < 0 )
F_35 ( V_18 ) ;
return V_80 ;
}
static T_5 int F_36 ( struct V_93 * V_102 )
{
F_37 ( & V_102 -> V_99 ) ;
F_35 ( F_38 ( V_102 ) ) ;
return 0 ;
}
static int T_6 F_39 ( void )
{
int V_80 = 0 ;
#if F_40 ( V_103 ) || F_40 ( V_104 )
V_80 = F_41 ( & V_105 ) ;
if ( V_80 != 0 ) {
F_24 ( V_82 L_3 ,
V_80 ) ;
}
#endif
return V_80 ;
}
static void T_7 F_42 ( void )
{
#if F_40 ( V_103 ) || F_40 ( V_104 )
F_43 ( & V_105 ) ;
#endif
}
