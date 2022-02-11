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
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
int V_5 = F_1 ( V_16 -> V_17 , F_5 ( V_10 ) ) ;
unsigned int V_18 ;
if ( V_8 == V_16 -> V_19 ) {
F_6 ( V_14 -> V_20 , L_1 ) ;
return 0 ;
}
if ( V_5 < 0 )
return V_5 ;
F_7 ( V_16 -> V_21 , V_22 , V_5 ) ;
switch ( F_8 ( V_10 ) ) {
case V_23 :
V_18 = 0x0 ;
break;
case V_24 :
V_18 = 0x4 ;
break;
case V_25 :
V_18 = 0x8 ;
break;
case V_26 :
V_18 = 0xc ;
break;
default:
return - V_6 ;
}
F_9 ( V_16 -> V_21 , V_27 ,
V_28 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_29 * V_30 ;
if ( V_16 -> V_31 ) {
V_30 = V_16 -> V_31 -> V_32 ;
F_6 ( V_14 -> V_20 , L_2 ,
V_30 -> V_33 ,
V_30 -> V_2 ) ;
if ( V_30 -> V_2 != 0 )
F_11 ( V_8 -> V_32 ,
V_34 ,
V_30 -> V_2 ,
V_30 -> V_2 ) ;
if ( V_30 -> V_33 != 0 )
F_11 ( V_8 -> V_32 ,
V_35 ,
V_30 -> V_33 ,
V_30 -> V_33 ) ;
V_16 -> V_19 = V_8 ;
} else
V_16 -> V_31 = V_8 ;
if ( V_16 -> V_36 ) {
F_12 ( V_8 -> V_32 , 0 ,
V_34 ,
V_16 -> V_36 ) ;
}
return 0 ;
}
static void F_13 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_16 -> V_31 == V_8 )
V_16 -> V_31 = V_16 -> V_19 ;
V_16 -> V_19 = NULL ;
}
static int F_14 ( struct V_11 * V_12 , int V_37 )
{
struct V_15 * V_16 = F_4 ( V_12 -> V_14 ) ;
if ( V_37 )
F_9 ( V_16 -> V_21 , V_38 ,
V_39 ,
V_39 ) ;
else
F_9 ( V_16 -> V_21 , V_38 ,
V_39 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_13 * V_14 = V_40 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_43 == V_44 ) {
if ( V_41 != V_45 )
return - V_6 ;
switch ( V_42 ) {
case 12288000 :
case 18432000 :
V_16 -> V_36 = & V_46 ;
break;
case 11289600 :
case 16934400 :
V_16 -> V_36 = & V_47 ;
break;
case 12000000 :
V_16 -> V_36 = NULL ;
break;
default:
return - V_6 ;
}
V_16 -> V_17 = V_42 ;
} else {
unsigned int V_48 ;
switch ( V_41 ) {
case V_49 :
V_48 = V_50 ;
break;
case V_51 :
V_48 = V_52 ;
break;
default:
return - V_6 ;
}
if ( V_42 == 0 )
V_16 -> V_53 |= V_48 ;
else
V_16 -> V_53 &= ~ V_48 ;
F_9 ( V_16 -> V_21 , V_54 ,
V_50 | V_52 , V_16 -> V_53 ) ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_40 ,
unsigned int V_55 )
{
struct V_15 * V_16 = F_4 ( V_40 -> V_14 ) ;
unsigned int V_18 = 0 ;
switch ( V_55 & V_56 ) {
case V_57 :
V_18 |= 0x0040 ;
break;
case V_58 :
break;
default:
return - V_6 ;
}
switch ( V_55 & V_59 ) {
case V_60 :
V_18 |= 0x0002 ;
break;
case V_61 :
break;
case V_62 :
V_18 |= 0x0001 ;
break;
case V_63 :
V_18 |= 0x0013 ;
break;
case V_64 :
V_18 |= 0x0003 ;
break;
default:
return - V_6 ;
}
switch ( V_55 & V_65 ) {
case V_66 :
break;
case V_67 :
V_18 |= 0x0090 ;
break;
case V_68 :
V_18 |= 0x0080 ;
break;
case V_69 :
V_18 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_7 ( V_16 -> V_21 , V_27 , V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
enum V_70 V_71 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
switch ( V_71 ) {
case V_72 :
F_9 ( V_16 -> V_21 , V_54 ,
V_73 | V_50 | V_52 ,
V_16 -> V_53 ) ;
break;
case V_74 :
break;
case V_75 :
F_9 ( V_16 -> V_21 , V_54 ,
V_73 | V_50 | V_52 ,
V_50 | V_52 ) ;
break;
case V_76 :
F_9 ( V_16 -> V_21 , V_54 ,
V_73 , V_73 ) ;
break;
}
V_14 -> V_77 . V_78 = V_71 ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
F_17 ( V_14 , V_76 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
F_20 ( V_16 -> V_21 ) ;
F_17 ( V_14 , V_75 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_79 * V_77 = & V_14 -> V_77 ;
int V_80 ;
F_9 ( V_16 -> V_21 , V_81 ,
V_82 , V_82 ) ;
F_9 ( V_16 -> V_21 , V_83 ,
V_84 , V_84 ) ;
V_80 = F_22 ( V_14 , V_85 ,
F_2 ( V_85 ) ) ;
if ( V_80 )
return V_80 ;
V_80 = F_23 ( V_77 , V_86 ,
F_2 ( V_86 ) ) ;
if ( V_80 )
return V_80 ;
return F_24 ( V_77 , V_87 ,
F_2 ( V_87 ) ) ;
}
static int F_25 ( struct V_13 * V_14 )
{
struct V_79 * V_77 = & V_14 -> V_77 ;
int V_80 ;
V_80 = F_23 ( V_77 , V_88 ,
F_2 ( V_88 ) ) ;
if ( V_80 )
return V_80 ;
return F_24 ( V_77 , V_89 ,
F_2 ( V_89 ) ) ;
}
static int F_26 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
int V_80 ;
V_14 -> V_90 = V_16 -> V_21 ;
V_80 = F_27 ( V_14 , 0 , 0 , V_91 ) ;
if ( V_80 < 0 ) {
F_28 ( V_14 -> V_20 , L_3 , V_80 ) ;
return V_80 ;
}
V_80 = F_7 ( V_16 -> V_21 , V_92 , 0 ) ;
if ( V_80 < 0 ) {
F_28 ( V_14 -> V_20 , L_4 , V_80 ) ;
return V_80 ;
}
F_9 ( V_16 -> V_21 , V_93 ,
V_94 , V_94 ) ;
F_9 ( V_16 -> V_21 , V_95 ,
V_96 , V_96 ) ;
F_7 ( V_16 -> V_21 , V_97 , V_98 |
V_99 ) ;
switch ( V_16 -> type ) {
case V_100 :
V_80 = F_21 ( V_14 ) ;
break;
case V_101 :
V_80 = F_25 ( V_14 ) ;
break;
}
if ( V_80 )
return V_80 ;
F_17 ( V_14 , V_75 ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 )
{
F_17 ( V_14 , V_76 ) ;
return 0 ;
}
static bool F_30 ( struct V_102 * V_20 , unsigned int V_103 )
{
return V_103 == V_92 ;
}
static int F_31 ( struct V_104 * V_105 )
{
struct V_15 * V_16 ;
int V_80 ;
V_16 = F_32 ( & V_105 -> V_20 , sizeof( struct V_15 ) ,
V_106 ) ;
if ( V_16 == NULL )
return - V_107 ;
F_33 ( V_105 , V_16 ) ;
V_16 -> type = V_100 ;
V_16 -> V_21 = F_34 ( V_105 , & V_108 ) ;
if ( F_35 ( V_16 -> V_21 ) )
return F_36 ( V_16 -> V_21 ) ;
V_80 = F_37 ( & V_105 -> V_20 ,
& V_109 , & V_110 , 1 ) ;
return V_80 ;
}
static int F_38 ( struct V_104 * V_105 )
{
F_39 ( & V_105 -> V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_111 * V_112 ,
const struct V_113 * V_114 )
{
struct V_15 * V_16 ;
int V_80 ;
V_16 = F_32 ( & V_112 -> V_20 , sizeof( struct V_15 ) ,
V_106 ) ;
if ( V_16 == NULL )
return - V_107 ;
F_41 ( V_112 , V_16 ) ;
V_16 -> type = V_114 -> V_115 ;
V_16 -> V_21 = F_42 ( V_112 , & V_108 ) ;
if ( F_35 ( V_16 -> V_21 ) )
return F_36 ( V_16 -> V_21 ) ;
V_80 = F_37 ( & V_112 -> V_20 ,
& V_109 , & V_110 , 1 ) ;
return V_80 ;
}
static int F_43 ( struct V_111 * V_116 )
{
F_39 ( & V_116 -> V_20 ) ;
return 0 ;
}
static int T_1 F_44 ( void )
{
int V_80 = 0 ;
#if F_45 ( V_117 )
V_80 = F_46 ( & V_118 ) ;
if ( V_80 )
return V_80 ;
#endif
#if F_45 ( V_119 ) || F_45 ( V_120 )
V_80 = F_47 ( & V_121 ) ;
if ( V_80 )
return V_80 ;
#endif
return V_80 ;
}
static void T_2 F_48 ( void )
{
#if F_45 ( V_117 )
F_49 ( & V_118 ) ;
#endif
#if F_45 ( V_119 ) || F_45 ( V_120 )
F_50 ( & V_121 ) ;
#endif
}
