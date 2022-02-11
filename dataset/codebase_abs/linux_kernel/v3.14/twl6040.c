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
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_31 , V_32 ;
V_31 = F_1 ( V_2 , V_11 ) ;
V_32 = F_1 ( V_2 , V_12 ) ;
if ( F_11 ( V_40 ) ) {
V_31 |= V_41 ;
V_32 |= V_41 ;
} else {
V_31 &= ~ V_41 ;
V_32 &= ~ V_41 ;
}
F_6 ( V_2 , V_11 , V_31 ) ;
F_6 ( V_2 , V_12 , V_32 ) ;
F_12 ( 1 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_42 = 0 ;
if ( F_11 ( V_40 ) ) {
V_5 -> V_43 = 1 ;
V_42 = F_9 ( V_2 , 1 ) ;
} else {
V_5 -> V_43 = 0 ;
V_42 = F_9 ( V_2 , V_5 -> V_44 ) ;
}
F_12 ( 1 ) ;
return V_42 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_45 * V_46 , int V_47 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_48 ;
F_15 ( & V_5 -> V_49 ) ;
V_48 = F_1 ( V_2 , V_50 ) ;
if ( V_48 & V_51 )
F_16 ( V_46 , V_47 , V_47 ) ;
else
F_16 ( V_46 , 0 , V_47 ) ;
F_17 ( & V_5 -> V_49 ) ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_45 * V_46 , int V_47 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_52 * V_53 = & V_5 -> V_53 ;
V_53 -> V_46 = V_46 ;
V_53 -> V_47 = V_47 ;
F_14 ( V_2 , V_53 -> V_46 , V_53 -> V_47 ) ;
}
static void F_19 ( struct V_54 * V_55 )
{
struct V_4 * V_5 = F_20 ( V_55 ,
struct V_4 , V_53 . V_55 . V_55 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_52 * V_53 = & V_5 -> V_53 ;
F_14 ( V_2 , V_53 -> V_46 , V_53 -> V_47 ) ;
}
static T_2 F_21 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_22 ( V_58 ,
& V_5 -> V_53 . V_55 , F_23 ( 200 ) ) ;
return V_59 ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_25 ( V_39 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_39 -> V_64 ;
unsigned int V_65 ;
V_65 = F_1 ( V_2 , V_63 -> V_3 ) ;
if ( V_65 & V_66 && ! ( V_65 & V_67 ) )
return - V_68 ;
return F_26 ( V_39 , V_61 ) ;
}
static int F_27 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_61 -> V_8 . V_69 . V_70 [ 0 ] = V_5 -> V_44 ;
return 0 ;
}
static int F_29 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_30 = V_61 -> V_8 . V_69 . V_70 [ 0 ] ;
int V_42 = 0 ;
if ( ! V_5 -> V_43 )
V_42 = F_9 ( V_2 , V_30 ) ;
if ( ! V_42 )
V_5 -> V_44 = V_30 ;
return V_42 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_61 -> V_8 . V_69 . V_70 [ 0 ] = V_5 -> V_71 ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_71 = V_61 -> V_8 . V_69 . V_70 [ 0 ] ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = & V_2 -> V_73 ;
if ( F_33 ( V_73 , L_1 ) )
return - 1 ;
if ( F_33 ( V_73 , L_2 ) ||
F_33 ( V_73 , L_3 ) ) {
T_1 V_65 = F_34 ( V_2 , V_11 ) ;
if ( V_65 & V_35 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_71 ;
}
int F_36 ( struct V_1 * V_2 , enum V_74 V_75 )
{
if ( F_37 ( V_75 >= V_76 ) )
return - V_77 ;
return F_1 ( V_2 , V_19 + V_75 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
if ( F_39 ( V_6 ) < V_78 )
return 2 ;
else
return 1 ;
}
static int F_40 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_42 ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
break;
case V_83 :
if ( V_5 -> V_84 )
break;
V_42 = F_41 ( V_6 , 1 ) ;
if ( V_42 )
return V_42 ;
V_5 -> V_84 = 1 ;
F_6 ( V_2 , V_85 , 0x02 ) ;
break;
case V_86 :
if ( ! V_5 -> V_84 )
break;
F_41 ( V_6 , 0 ) ;
V_5 -> V_84 = 0 ;
break;
}
V_2 -> V_73 . V_87 = V_80 ;
return 0 ;
}
static int F_42 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_43 ( V_89 -> V_92 , 0 ,
V_93 ,
& V_94 [ V_5 -> V_71 ] ) ;
return 0 ;
}
static int F_44 ( struct V_88 * V_89 ,
struct V_95 * V_96 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_97 ;
V_97 = F_45 ( V_96 ) ;
switch ( V_97 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_37 ( V_5 -> V_98 == V_99 ) ) {
F_46 ( V_2 -> V_100 , L_4 ,
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
F_46 ( V_2 -> V_100 , L_5 , V_97 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_47 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_42 ;
if ( ! V_5 -> V_101 ) {
F_46 ( V_2 -> V_100 ,
L_6 ) ;
return - V_77 ;
}
V_42 = F_48 ( V_6 , V_5 -> V_98 , V_5 -> V_102 , V_5 -> V_101 ) ;
if ( V_42 ) {
F_46 ( V_2 -> V_100 , L_7 , V_42 ) ;
return - V_103 ;
}
return 0 ;
}
static int F_49 ( struct V_90 * V_104 ,
int V_105 , unsigned int V_106 , int V_107 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_105 ) {
case V_108 :
case V_99 :
V_5 -> V_98 = V_105 ;
V_5 -> V_102 = V_106 ;
break;
default:
F_46 ( V_2 -> V_100 , L_8 , V_105 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , enum V_109 V_110 ,
int V_111 )
{
struct V_6 * V_6 = V_2 -> V_7 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_31 , V_32 , V_112 ;
int V_113 , V_114 ;
switch ( V_110 ) {
case V_115 :
V_31 = F_1 ( V_2 , V_11 ) ;
V_32 = F_1 ( V_2 , V_12 ) ;
V_112 = F_1 ( V_2 , V_13 ) ;
if ( V_111 ) {
V_112 &= ~ 0x01 ;
V_31 &= ~ ( V_116 | V_41 ) ;
V_32 &= ~ ( V_116 | V_41 ) ;
}
F_7 ( V_6 , V_13 , V_112 ) ;
F_7 ( V_6 , V_11 , V_31 ) ;
F_7 ( V_6 , V_12 , V_32 ) ;
V_5 -> V_17 = ! V_111 ;
break;
case V_117 :
V_113 = F_1 ( V_2 , V_14 ) ;
V_114 = F_1 ( V_2 , V_15 ) ;
if ( V_111 ) {
V_113 &= ~ ( V_118 | V_119 |
V_120 ) ;
V_114 &= ~ ( V_118 | V_119 |
V_120 ) ;
}
F_7 ( V_6 , V_14 , V_113 ) ;
F_7 ( V_6 , V_15 , V_114 ) ;
V_5 -> V_18 = ! V_111 ;
break;
default:
break;
}
}
static int F_51 ( struct V_90 * V_91 , int V_111 )
{
switch ( V_91 -> V_110 ) {
case V_121 :
F_50 ( V_91 -> V_2 , V_115 , V_111 ) ;
F_50 ( V_91 -> V_2 , V_117 , V_111 ) ;
break;
case V_115 :
case V_117 :
F_50 ( V_91 -> V_2 , V_91 -> V_110 , V_111 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
F_40 ( V_2 , V_86 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
F_40 ( V_2 , V_83 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = F_55 ( V_2 -> V_100 -> V_122 ) ;
struct V_123 * V_124 = F_20 ( V_2 -> V_100 ,
struct V_123 , V_100 ) ;
int V_42 = 0 ;
V_5 = F_56 ( V_2 -> V_100 , sizeof( * V_5 ) , V_125 ) ;
if ( V_5 == NULL )
return - V_126 ;
F_57 ( V_2 , V_5 ) ;
V_5 -> V_2 = V_2 ;
V_2 -> V_7 = V_6 ;
V_5 -> V_127 = F_58 ( V_124 , 0 ) ;
if ( V_5 -> V_127 < 0 ) {
F_46 ( V_2 -> V_100 , L_9 ) ;
return - V_77 ;
}
F_59 ( & V_5 -> V_53 . V_55 , F_19 ) ;
F_60 ( & V_5 -> V_49 ) ;
V_42 = F_61 ( V_5 -> V_127 , NULL ,
F_21 , V_128 ,
L_10 , V_2 ) ;
if ( V_42 ) {
F_46 ( V_2 -> V_100 , L_11 , V_42 ) ;
return V_42 ;
}
F_40 ( V_2 , V_83 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_63 ( V_5 -> V_127 , V_2 ) ;
F_40 ( V_2 , V_86 ) ;
return 0 ;
}
static int F_64 ( struct V_123 * V_124 )
{
return F_65 ( & V_124 -> V_100 , & V_129 ,
V_130 , F_66 ( V_130 ) ) ;
}
static int F_67 ( struct V_123 * V_124 )
{
F_68 ( & V_124 -> V_100 ) ;
return 0 ;
}
