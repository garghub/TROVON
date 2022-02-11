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
struct V_30 * V_31 ;
if ( V_19 -> V_32 ) {
V_31 = V_19 -> V_32 -> V_33 ;
F_7 ( V_17 -> V_24 , L_2 ,
V_31 -> V_34 ,
V_31 -> V_2 ) ;
if ( V_31 -> V_2 != 0 )
F_11 ( V_8 -> V_33 ,
V_35 ,
V_31 -> V_2 ,
V_31 -> V_2 ) ;
if ( V_31 -> V_34 != 0 )
F_11 ( V_8 -> V_33 ,
V_36 ,
V_31 -> V_34 ,
V_31 -> V_34 ) ;
V_19 -> V_23 = V_8 ;
} else
V_19 -> V_32 = V_8 ;
return 0 ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
if ( V_19 -> V_32 == V_8 )
V_19 -> V_32 = V_19 -> V_23 ;
V_19 -> V_23 = NULL ;
}
static int F_13 ( struct V_11 * V_12 , int V_37 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
if ( V_37 )
F_14 ( V_17 , V_38 ,
V_39 ,
V_39 ) ;
else
F_14 ( V_17 , V_38 ,
V_39 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_40 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_16 * V_17 = V_40 -> V_17 ;
struct V_18 * V_19 = F_4 ( V_17 ) ;
if ( V_43 == V_44 ) {
if ( V_41 != V_45 )
return - V_6 ;
switch ( V_42 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_19 -> V_22 = V_42 ;
break;
default:
return - V_6 ;
}
} else {
unsigned int V_46 ;
switch ( V_41 ) {
case V_47 :
V_46 = V_48 ;
break;
case V_49 :
V_46 = V_50 ;
break;
default:
return - V_6 ;
}
if ( V_42 == 0 )
V_19 -> V_51 |= V_46 ;
else
V_19 -> V_51 &= ~ V_46 ;
F_14 ( V_17 , V_52 ,
V_48 | V_50 , V_19 -> V_51 ) ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_40 ,
unsigned int V_53 )
{
struct V_16 * V_17 = V_40 -> V_17 ;
T_1 V_20 = 0 ;
switch ( V_53 & V_54 ) {
case V_55 :
V_20 |= 0x0040 ;
break;
case V_56 :
break;
default:
return - V_6 ;
}
switch ( V_53 & V_57 ) {
case V_58 :
V_20 |= 0x0002 ;
break;
case V_59 :
break;
case V_60 :
V_20 |= 0x0001 ;
break;
case V_61 :
V_20 |= 0x0013 ;
break;
case V_62 :
V_20 |= 0x0003 ;
break;
default:
return - V_6 ;
}
switch ( V_53 & V_63 ) {
case V_64 :
break;
case V_65 :
V_20 |= 0x0090 ;
break;
case V_66 :
V_20 |= 0x0080 ;
break;
case V_67 :
V_20 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_8 ( V_17 , V_21 , V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
enum V_68 V_69 )
{
struct V_18 * V_19 = F_4 ( V_17 ) ;
switch ( V_69 ) {
case V_70 :
F_14 ( V_17 , V_52 ,
V_71 | V_48 | V_50 ,
V_19 -> V_51 ) ;
break;
case V_72 :
break;
case V_73 :
F_14 ( V_17 , V_52 ,
V_71 | V_48 | V_50 ,
V_48 | V_50 ) ;
break;
case V_74 :
F_14 ( V_17 , V_52 ,
V_71 , V_71 ) ;
break;
}
V_17 -> V_75 . V_76 = V_69 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , T_2 V_77 )
{
F_17 ( V_17 , V_74 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 )
{
F_20 ( V_17 ) ;
F_17 ( V_17 , V_73 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_78 * V_75 = & V_17 -> V_75 ;
int V_79 ;
F_14 ( V_17 , V_80 ,
V_81 , V_81 ) ;
F_14 ( V_17 , V_82 ,
V_83 , V_83 ) ;
V_79 = F_22 ( V_17 , V_84 ,
F_2 ( V_84 ) ) ;
if ( V_79 )
return V_79 ;
V_79 = F_23 ( V_75 , V_85 ,
F_2 ( V_85 ) ) ;
if ( V_79 )
return V_79 ;
return F_24 ( V_75 , V_86 ,
F_2 ( V_86 ) ) ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_78 * V_75 = & V_17 -> V_75 ;
int V_79 ;
V_79 = F_23 ( V_75 , V_87 ,
F_2 ( V_87 ) ) ;
if ( V_79 )
return V_79 ;
return F_24 ( V_75 , V_88 ,
F_2 ( V_88 ) ) ;
}
static int F_26 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_4 ( V_17 ) ;
int V_79 ;
F_27 ( L_3 , V_89 ) ;
V_79 = F_28 ( V_17 , 7 , 9 , V_19 -> V_90 ) ;
if ( V_79 < 0 ) {
F_29 ( V_17 -> V_24 , L_4 , V_79 ) ;
return V_79 ;
}
V_79 = F_30 ( V_17 ) ;
if ( V_79 < 0 ) {
F_29 ( V_17 -> V_24 , L_5 , V_79 ) ;
return V_79 ;
}
F_14 ( V_17 , V_91 ,
V_92 , V_92 ) ;
F_14 ( V_17 , V_93 ,
V_94 , V_94 ) ;
F_8 ( V_17 , V_95 , V_96 |
V_97 ) ;
switch ( V_19 -> type ) {
case V_98 :
V_79 = F_21 ( V_17 ) ;
break;
case V_99 :
V_79 = F_25 ( V_17 ) ;
break;
}
if ( V_79 )
return V_79 ;
F_17 ( V_17 , V_73 ) ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 )
{
F_17 ( V_17 , V_74 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_100 * V_101 )
{
struct V_18 * V_19 ;
int V_79 ;
V_19 = F_33 ( sizeof( struct V_18 ) , V_102 ) ;
if ( V_19 == NULL )
return - V_103 ;
F_34 ( V_101 , V_19 ) ;
V_19 -> V_90 = V_104 ;
V_19 -> type = V_98 ;
V_79 = F_35 ( & V_101 -> V_24 ,
& V_105 , & V_106 , 1 ) ;
if ( V_79 < 0 )
F_36 ( V_19 ) ;
return V_79 ;
}
static int T_4 F_37 ( struct V_100 * V_101 )
{
F_38 ( & V_101 -> V_24 ) ;
F_36 ( F_39 ( V_101 ) ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_107 * V_108 ,
const struct V_109 * V_110 )
{
struct V_18 * V_19 ;
int V_79 ;
V_19 = F_33 ( sizeof( struct V_18 ) , V_102 ) ;
if ( V_19 == NULL )
return - V_103 ;
F_41 ( V_108 , V_19 ) ;
V_19 -> V_90 = V_111 ;
V_19 -> type = V_110 -> V_112 ;
V_79 = F_35 ( & V_108 -> V_24 ,
& V_105 , & V_106 , 1 ) ;
if ( V_79 < 0 )
F_36 ( V_19 ) ;
return V_79 ;
}
static int T_4 F_42 ( struct V_107 * V_113 )
{
F_38 ( & V_113 -> V_24 ) ;
F_36 ( F_43 ( V_113 ) ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
int V_79 = 0 ;
#if F_45 ( V_114 )
V_79 = F_46 ( & V_115 ) ;
if ( V_79 )
return V_79 ;
#endif
#if F_45 ( V_116 ) || F_45 ( V_117 )
V_79 = F_47 ( & V_118 ) ;
if ( V_79 )
return V_79 ;
#endif
return V_79 ;
}
static void T_6 F_48 ( void )
{
#if F_45 ( V_114 )
F_49 ( & V_115 ) ;
#endif
#if F_45 ( V_116 ) || F_45 ( V_117 )
F_50 ( & V_118 ) ;
#endif
}
