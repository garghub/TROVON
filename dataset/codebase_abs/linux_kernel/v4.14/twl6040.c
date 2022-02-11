static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
if ( V_3 >= V_9 )
return - V_10 ;
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_8 = V_5 -> V_16 [ V_3 - V_11 ] ;
break;
default:
V_8 = F_3 ( V_6 , V_3 ) ;
break;
}
return V_8 ;
}
static bool F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
return V_5 -> V_17 ;
case V_14 :
case V_15 :
return V_5 -> V_18 ;
default:
return 1 ;
}
}
static inline void F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_5 -> V_16 [ V_3 - V_11 ] = V_8 ;
break;
default:
break;
}
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
if ( V_3 >= V_9 )
return - V_10 ;
F_5 ( V_2 , V_3 , V_8 ) ;
if ( F_4 ( V_2 , V_3 ) )
return F_7 ( V_6 , V_3 , V_8 ) ;
else
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ) ;
F_1 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_21 ) ;
F_1 ( V_2 , V_22 ) ;
F_1 ( V_2 , V_23 ) ;
F_6 ( V_2 , V_24 , 0x18 ) ;
F_6 ( V_2 , V_25 , 0x18 ) ;
F_6 ( V_2 , V_26 , 0xff ) ;
F_6 ( V_2 , V_13 , 0x1e ) ;
F_6 ( V_2 , V_27 , 0x1d ) ;
F_6 ( V_2 , V_28 , 0x1d ) ;
F_6 ( V_2 , V_29 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_30 )
{
int V_31 , V_32 ;
int V_33 = V_34 | V_35 ;
V_31 = F_1 ( V_2 , V_11 ) ;
V_32 = F_1 ( V_2 , V_12 ) ;
if ( V_30 ) {
V_31 &= ~ V_33 ;
V_32 &= ~ V_33 ;
} else {
V_31 |= V_33 ;
V_32 |= V_33 ;
}
F_6 ( V_2 , V_11 , V_31 ) ;
F_6 ( V_2 , V_12 , V_32 ) ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = F_11 ( V_37 -> V_41 ) ;
T_1 V_31 , V_32 ;
V_31 = F_1 ( V_2 , V_11 ) ;
V_32 = F_1 ( V_2 , V_12 ) ;
if ( F_12 ( V_40 ) ) {
V_31 |= V_42 ;
V_32 |= V_42 ;
} else {
V_31 &= ~ V_42 ;
V_32 &= ~ V_42 ;
}
F_6 ( V_2 , V_11 , V_31 ) ;
F_6 ( V_2 , V_12 , V_32 ) ;
F_13 ( 1 ) ;
return 0 ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = F_11 ( V_37 -> V_41 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_43 = 0 ;
if ( F_12 ( V_40 ) ) {
V_5 -> V_44 = 1 ;
V_43 = F_9 ( V_2 , 1 ) ;
} else {
V_5 -> V_44 = 0 ;
V_43 = F_9 ( V_2 , V_5 -> V_45 ) ;
}
F_13 ( 1 ) ;
return V_43 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_46 * V_47 , int V_48 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_49 ;
F_16 ( & V_5 -> V_50 ) ;
V_49 = F_1 ( V_2 , V_51 ) ;
if ( V_49 & V_52 )
F_17 ( V_47 , V_48 , V_48 ) ;
else
F_17 ( V_47 , 0 , V_48 ) ;
F_18 ( & V_5 -> V_50 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_46 * V_47 , int V_48 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_53 * V_54 = & V_5 -> V_54 ;
V_54 -> V_47 = V_47 ;
V_54 -> V_48 = V_48 ;
F_15 ( V_2 , V_54 -> V_47 , V_54 -> V_48 ) ;
}
static void F_20 ( struct V_55 * V_56 )
{
struct V_4 * V_5 = F_21 ( V_56 ,
struct V_4 , V_54 . V_56 . V_56 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_54 = & V_5 -> V_54 ;
F_15 ( V_2 , V_54 -> V_47 , V_54 -> V_48 ) ;
}
static T_2 F_22 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_23 ( V_59 ,
& V_5 -> V_54 . V_56 , F_24 ( 200 ) ) ;
return V_60 ;
}
static int F_25 ( struct V_38 * V_39 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
struct V_63 * V_64 = (struct V_63 * ) V_39 -> V_65 ;
unsigned int V_66 ;
V_66 = F_1 ( V_2 , V_64 -> V_3 ) ;
if ( V_66 & V_67 && ! ( V_66 & V_68 ) )
return - V_69 ;
return F_27 ( V_39 , V_62 ) ;
}
static int F_28 ( struct V_38 * V_39 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_62 -> V_8 . V_70 . V_71 [ 0 ] = V_5 -> V_45 ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_30 = V_62 -> V_8 . V_70 . V_71 [ 0 ] ;
int V_43 = 0 ;
if ( ! V_5 -> V_44 )
V_43 = F_9 ( V_2 , V_30 ) ;
if ( ! V_43 )
V_5 -> V_45 = V_30 ;
return V_43 ;
}
static int F_31 ( struct V_38 * V_39 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_62 -> V_8 . V_70 . V_71 [ 0 ] = V_5 -> V_72 ;
return 0 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_72 = V_62 -> V_8 . V_70 . V_71 [ 0 ] ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_73 * V_41 = F_34 ( V_2 ) ;
if ( F_35 ( V_41 , L_1 ) )
return - 1 ;
if ( F_35 ( V_41 , L_2 ) ||
F_35 ( V_41 , L_3 ) ) {
T_1 V_66 = F_36 ( V_2 , V_11 ) ;
if ( V_66 & V_35 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_72 ;
}
int F_38 ( struct V_1 * V_2 , enum V_74 V_75 )
{
if ( F_39 ( V_75 >= V_76 ) )
return - V_77 ;
return F_1 ( V_2 , V_19 + V_75 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
if ( F_41 ( V_6 ) < V_78 )
return 2 ;
else
return 1 ;
}
static int F_42 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_43 = 0 ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
break;
case V_83 :
if ( V_5 -> V_84 ) {
V_43 = F_43 ( V_6 , V_85 ,
32768 , 19200000 ) ;
break;
}
V_43 = F_44 ( V_6 , 1 ) ;
if ( V_43 )
break;
V_5 -> V_84 = 1 ;
F_6 ( V_2 , V_86 , 0x02 ) ;
break;
case V_87 :
if ( ! V_5 -> V_84 )
break;
F_44 ( V_6 , 0 ) ;
V_5 -> V_84 = 0 ;
break;
}
return V_43 ;
}
static int F_45 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_46 ( V_89 -> V_92 , 0 ,
V_93 ,
& V_94 [ V_5 -> V_72 ] ) ;
return 0 ;
}
static int F_47 ( struct V_88 * V_89 ,
struct V_95 * V_96 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_97 ;
V_97 = F_48 ( V_96 ) ;
switch ( V_97 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_39 ( V_5 -> V_98 == V_99 ) ) {
F_49 ( V_2 -> V_100 , L_4 ,
V_97 ) ;
return - V_77 ;
}
V_5 -> V_101 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_5 -> V_101 = 19200000 ;
break;
default:
F_49 ( V_2 -> V_100 , L_5 , V_97 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_50 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_43 ;
if ( ! V_5 -> V_101 ) {
F_49 ( V_2 -> V_100 ,
L_6 ) ;
return - V_77 ;
}
V_43 = F_43 ( V_6 , V_5 -> V_98 , V_5 -> V_102 , V_5 -> V_101 ) ;
if ( V_43 ) {
F_49 ( V_2 -> V_100 , L_7 , V_43 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_51 ( struct V_90 * V_104 ,
int V_105 , unsigned int V_106 , int V_107 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_105 ) {
case V_85 :
case V_99 :
V_5 -> V_98 = V_105 ;
V_5 -> V_102 = V_106 ;
break;
default:
F_49 ( V_2 -> V_100 , L_8 , V_105 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , enum V_108 V_109 ,
int V_110 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_31 , V_32 , V_111 ;
int V_112 , V_113 ;
switch ( V_109 ) {
case V_114 :
V_31 = F_1 ( V_2 , V_11 ) ;
V_32 = F_1 ( V_2 , V_12 ) ;
V_111 = F_1 ( V_2 , V_13 ) ;
if ( V_110 ) {
V_111 &= ~ 0x01 ;
V_31 &= ~ ( V_115 | V_42 ) ;
V_32 &= ~ ( V_115 | V_42 ) ;
}
F_7 ( V_6 , V_13 , V_111 ) ;
F_7 ( V_6 , V_11 , V_31 ) ;
F_7 ( V_6 , V_12 , V_32 ) ;
V_5 -> V_17 = ! V_110 ;
break;
case V_116 :
V_112 = F_1 ( V_2 , V_14 ) ;
V_113 = F_1 ( V_2 , V_15 ) ;
if ( V_110 ) {
V_112 &= ~ ( V_117 | V_118 |
V_119 | V_120 ) ;
V_113 &= ~ ( V_117 | V_118 |
V_119 | V_120 ) ;
}
F_7 ( V_6 , V_14 , V_112 ) ;
F_7 ( V_6 , V_15 , V_113 ) ;
V_5 -> V_18 = ! V_110 ;
break;
default:
break;
}
}
static int F_53 ( struct V_90 * V_91 , int V_110 )
{
switch ( V_91 -> V_109 ) {
case V_121 :
F_52 ( V_91 -> V_2 , V_114 , V_110 ) ;
F_52 ( V_91 -> V_2 , V_116 , V_110 ) ;
break;
case V_114 :
case V_116 :
F_52 ( V_91 -> V_2 , V_91 -> V_109 , V_110 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = F_55 ( V_2 -> V_100 -> V_122 ) ;
struct V_123 * V_124 = F_56 ( V_2 -> V_100 ) ;
int V_43 = 0 ;
V_5 = F_57 ( V_2 -> V_100 , sizeof( * V_5 ) , V_125 ) ;
if ( V_5 == NULL )
return - V_126 ;
F_58 ( V_2 , V_5 ) ;
V_5 -> V_2 = V_2 ;
V_2 -> V_7 = V_6 ;
V_5 -> V_127 = F_59 ( V_124 , 0 ) ;
if ( V_5 -> V_127 < 0 ) {
F_49 ( V_2 -> V_100 , L_9 , V_5 -> V_127 ) ;
return V_5 -> V_127 ;
}
F_60 ( & V_5 -> V_54 . V_56 , F_20 ) ;
F_61 ( & V_5 -> V_50 ) ;
V_43 = F_62 ( V_5 -> V_127 , NULL ,
F_22 ,
V_128 | V_129 ,
L_10 , V_2 ) ;
if ( V_43 ) {
F_49 ( V_2 -> V_100 , L_11 , V_43 ) ;
return V_43 ;
}
F_63 ( V_2 , V_83 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_65 ( V_5 -> V_127 , V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_123 * V_124 )
{
return F_67 ( & V_124 -> V_100 , & V_130 ,
V_131 , F_68 ( V_131 ) ) ;
}
static int F_69 ( struct V_123 * V_124 )
{
F_70 ( & V_124 -> V_100 ) ;
return 0 ;
}
