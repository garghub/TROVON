static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 &&
V_4 [ V_3 ] . V_1 == V_1 )
return V_4 [ V_3 ] . V_5 ;
}
return - V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
T_1 V_20 = F_5 ( V_17 , V_21 ) & 0xfff3 ;
int V_5 = F_1 ( V_19 -> V_22 , F_6 ( V_10 ) ) ;
if ( V_8 == V_19 -> V_23 ) {
F_7 ( V_17 -> V_24 , L_1 ) ;
return 0 ;
}
if ( V_5 < 0 )
return V_5 ;
F_8 ( V_17 , V_25 , V_5 ) ;
switch ( F_9 ( V_10 ) ) {
case V_26 :
break;
case V_27 :
V_20 |= 0x0004 ;
break;
case V_28 :
V_20 |= 0x0008 ;
break;
case V_29 :
V_20 |= 0x000c ;
break;
}
F_8 ( V_17 , V_21 , V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
struct V_30 * V_31 = V_17 -> V_32 ;
struct V_33 * V_34 ;
if ( V_19 -> V_35 ) {
V_34 = V_19 -> V_35 -> V_36 ;
F_7 ( & V_31 -> V_24 , L_2 ,
V_34 -> V_37 ,
V_34 -> V_2 ) ;
if ( V_34 -> V_2 != 0 )
F_11 ( V_8 -> V_36 ,
V_38 ,
V_34 -> V_2 ,
V_34 -> V_2 ) ;
if ( V_34 -> V_37 != 0 )
F_11 ( V_8 -> V_36 ,
V_39 ,
V_34 -> V_37 ,
V_34 -> V_37 ) ;
V_19 -> V_23 = V_8 ;
} else
V_19 -> V_35 = V_8 ;
return 0 ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
if ( V_19 -> V_35 == V_8 )
V_19 -> V_35 = V_19 -> V_23 ;
V_19 -> V_23 = NULL ;
}
static int F_13 ( struct V_11 * V_12 , int V_40 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
T_1 V_41 = F_5 ( V_17 , V_42 ) & ~ V_43 ;
if ( V_40 )
F_8 ( V_17 , V_42 ,
V_41 | V_43 ) ;
else
F_8 ( V_17 , V_42 , V_41 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_44 ,
int V_45 , unsigned int V_46 , int V_47 )
{
struct V_16 * V_17 = V_44 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
switch ( V_46 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_19 -> V_22 = V_46 ;
return 0 ;
}
return - V_6 ;
}
static int F_15 ( struct V_11 * V_44 ,
unsigned int V_48 )
{
struct V_16 * V_17 = V_44 -> V_17 ;
T_1 V_20 = 0 ;
switch ( V_48 & V_49 ) {
case V_50 :
V_20 |= 0x0040 ;
break;
case V_51 :
break;
default:
return - V_6 ;
}
switch ( V_48 & V_52 ) {
case V_53 :
V_20 |= 0x0002 ;
break;
case V_54 :
break;
case V_55 :
V_20 |= 0x0001 ;
break;
case V_56 :
V_20 |= 0x0013 ;
break;
case V_57 :
V_20 |= 0x0003 ;
break;
default:
return - V_6 ;
}
switch ( V_48 & V_58 ) {
case V_59 :
break;
case V_60 :
V_20 |= 0x0090 ;
break;
case V_61 :
V_20 |= 0x0080 ;
break;
case V_62 :
V_20 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_8 ( V_17 , V_21 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
enum V_63 V_64 )
{
T_1 V_65 = F_5 ( V_17 , V_66 ) & 0xff7f ;
switch ( V_64 ) {
case V_67 :
F_8 ( V_17 , V_66 , V_65 ) ;
break;
case V_68 :
break;
case V_69 :
F_8 ( V_17 , V_66 , V_65 | V_70 ) ;
break;
case V_71 :
F_8 ( V_17 , V_66 , 0xffff ) ;
break;
}
V_17 -> V_72 . V_73 = V_64 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , T_2 V_74 )
{
F_16 ( V_17 , V_71 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 )
{
F_19 ( V_17 ) ;
F_16 ( V_17 , V_69 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_75 * V_72 = & V_17 -> V_72 ;
int V_76 , V_65 ;
V_65 = F_5 ( V_17 , V_77 ) ;
F_8 ( V_17 , V_77 , V_65 | V_78 ) ;
V_65 = F_5 ( V_17 , V_79 ) ;
F_8 ( V_17 , V_79 , V_65 | V_80 ) ;
V_76 = F_21 ( V_17 , V_81 ,
F_2 ( V_81 ) ) ;
if ( V_76 )
return V_76 ;
V_76 = F_22 ( V_72 , V_82 ,
F_2 ( V_82 ) ) ;
if ( V_76 )
return V_76 ;
return F_23 ( V_72 , V_83 ,
F_2 ( V_83 ) ) ;
}
static int F_24 ( struct V_16 * V_17 )
{
struct V_75 * V_72 = & V_17 -> V_72 ;
int V_76 ;
V_76 = F_22 ( V_72 , V_84 ,
F_2 ( V_84 ) ) ;
if ( V_76 )
return V_76 ;
return F_23 ( V_72 , V_85 ,
F_2 ( V_85 ) ) ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_4 ( V_17 ) ;
int V_76 , V_65 ;
F_26 ( L_3 , V_86 ) ;
V_76 = F_27 ( V_17 , 7 , 9 , V_19 -> V_87 ) ;
if ( V_76 < 0 ) {
F_28 ( V_17 -> V_24 , L_4 , V_76 ) ;
return V_76 ;
}
V_76 = F_29 ( V_17 ) ;
if ( V_76 < 0 ) {
F_28 ( V_17 -> V_24 , L_5 , V_76 ) ;
return V_76 ;
}
V_65 = F_5 ( V_17 , V_88 ) ;
F_8 ( V_17 , V_88 , V_65 | V_89 ) ;
V_65 = F_5 ( V_17 , V_90 ) ;
F_8 ( V_17 , V_90 , V_65 | V_91 ) ;
F_8 ( V_17 , V_92 , V_93 |
V_94 ) ;
switch ( V_19 -> type ) {
case V_95 :
V_76 = F_20 ( V_17 ) ;
break;
case V_96 :
V_76 = F_24 ( V_17 ) ;
break;
}
return V_76 ;
}
static int F_30 ( struct V_16 * V_17 )
{
F_16 ( V_17 , V_71 ) ;
return 0 ;
}
static int T_3 F_31 ( struct V_97 * V_98 )
{
struct V_18 * V_19 ;
int V_76 ;
V_19 = F_32 ( sizeof( struct V_18 ) , V_99 ) ;
if ( V_19 == NULL )
return - V_100 ;
F_33 ( V_98 , V_19 ) ;
V_19 -> V_87 = V_101 ;
V_19 -> type = V_95 ;
V_76 = F_34 ( & V_98 -> V_24 ,
& V_102 , & V_103 , 1 ) ;
if ( V_76 < 0 )
F_35 ( V_19 ) ;
return V_76 ;
}
static int T_4 F_36 ( struct V_97 * V_98 )
{
F_37 ( & V_98 -> V_24 ) ;
F_35 ( F_38 ( V_98 ) ) ;
return 0 ;
}
static int T_3 F_39 ( struct V_30 * V_31 ,
const struct V_104 * V_105 )
{
struct V_18 * V_19 ;
int V_76 ;
V_19 = F_32 ( sizeof( struct V_18 ) , V_99 ) ;
if ( V_19 == NULL )
return - V_100 ;
F_40 ( V_31 , V_19 ) ;
V_19 -> V_87 = V_106 ;
V_19 -> type = V_105 -> V_107 ;
V_76 = F_34 ( & V_31 -> V_24 ,
& V_102 , & V_103 , 1 ) ;
if ( V_76 < 0 )
F_35 ( V_19 ) ;
return V_76 ;
}
static int T_4 F_41 ( struct V_30 * V_108 )
{
F_37 ( & V_108 -> V_24 ) ;
F_35 ( F_42 ( V_108 ) ) ;
return 0 ;
}
static int T_5 F_43 ( void )
{
int V_76 = 0 ;
#if F_44 ( V_109 )
V_76 = F_45 ( & V_110 ) ;
if ( V_76 )
return V_76 ;
#endif
#if F_44 ( V_111 ) || F_44 ( V_112 )
V_76 = F_46 ( & V_113 ) ;
if ( V_76 )
return V_76 ;
#endif
return V_76 ;
}
static void T_6 F_47 ( void )
{
#if F_44 ( V_109 )
F_48 ( & V_110 ) ;
#endif
#if F_44 ( V_111 ) || F_44 ( V_112 )
F_49 ( & V_113 ) ;
#endif
}
