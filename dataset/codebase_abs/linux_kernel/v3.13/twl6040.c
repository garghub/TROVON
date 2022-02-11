static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
T_1 V_8 ;
if ( V_3 >= V_6 )
return - V_7 ;
V_8 = F_4 ( V_9 , V_3 ) ;
F_2 ( V_2 , V_3 , V_8 ) ;
return V_8 ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
switch ( V_3 ) {
case V_13 :
case V_14 :
case V_15 :
return V_12 -> V_16 ;
case V_17 :
case V_18 :
return V_12 -> V_19 ;
default:
return 1 ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
if ( F_5 ( V_2 , V_3 ) )
return F_8 ( V_9 , V_3 , V_8 ) ;
else
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
T_1 V_20 ;
V_20 = F_10 ( V_9 ) ;
F_2 ( V_2 , V_21 , V_20 ) ;
F_3 ( V_2 , V_22 ) ;
F_3 ( V_2 , V_23 ) ;
F_3 ( V_2 , V_24 ) ;
F_3 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_26 ) ;
F_2 ( V_2 , V_27 , 0x18 ) ;
F_2 ( V_2 , V_28 , 0x18 ) ;
F_2 ( V_2 , V_29 , 0xff ) ;
F_2 ( V_2 , V_15 , 0x1e ) ;
F_2 ( V_2 , V_30 , 0x1d ) ;
F_2 ( V_2 , V_31 , 0x1d ) ;
F_2 ( V_2 , V_32 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_33 ;
for ( V_33 = 0 ; V_33 < F_12 ( V_34 ) ; V_33 ++ ) {
V_3 = V_34 [ V_33 ] ;
F_7 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_35 )
{
int V_36 , V_37 ;
int V_38 = V_39 | V_40 ;
V_36 = F_1 ( V_2 , V_13 ) ;
V_37 = F_1 ( V_2 , V_14 ) ;
if ( V_35 ) {
V_36 &= ~ V_38 ;
V_37 &= ~ V_38 ;
} else {
V_36 |= V_38 ;
V_37 |= V_38 ;
}
F_7 ( V_2 , V_13 , V_36 ) ;
F_7 ( V_2 , V_14 , V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
T_1 V_36 , V_37 ;
V_36 = F_1 ( V_2 , V_13 ) ;
V_37 = F_1 ( V_2 , V_14 ) ;
if ( F_15 ( V_45 ) ) {
V_36 |= V_46 ;
V_37 |= V_46 ;
} else {
V_36 &= ~ V_46 ;
V_37 &= ~ V_46 ;
}
F_7 ( V_2 , V_13 , V_36 ) ;
F_7 ( V_2 , V_14 , V_37 ) ;
F_16 ( 1 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_47 = 0 ;
if ( F_15 ( V_45 ) ) {
V_12 -> V_48 = 1 ;
V_47 = F_13 ( V_2 , 1 ) ;
} else {
V_12 -> V_48 = 0 ;
V_47 = F_13 ( V_2 , V_12 -> V_49 ) ;
}
F_16 ( 1 ) ;
return V_47 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_50 * V_51 , int V_52 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_53 ;
F_19 ( & V_12 -> V_54 ) ;
V_53 = F_3 ( V_2 , V_55 ) ;
if ( V_53 & V_56 )
F_20 ( V_51 , V_52 , V_52 ) ;
else
F_20 ( V_51 , 0 , V_52 ) ;
F_21 ( & V_12 -> V_54 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_50 * V_51 , int V_52 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
struct V_57 * V_58 = & V_12 -> V_58 ;
V_58 -> V_51 = V_51 ;
V_58 -> V_52 = V_52 ;
F_18 ( V_2 , V_58 -> V_51 , V_58 -> V_52 ) ;
}
static void F_23 ( struct V_59 * V_60 )
{
struct V_11 * V_12 = F_24 ( V_60 ,
struct V_11 , V_58 . V_60 . V_60 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_57 * V_58 = & V_12 -> V_58 ;
F_18 ( V_2 , V_58 -> V_51 , V_58 -> V_52 ) ;
}
static T_2 F_25 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
F_26 ( V_63 ,
& V_12 -> V_58 . V_60 , F_27 ( 200 ) ) ;
return V_64 ;
}
static int F_28 ( struct V_43 * V_44 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_44 ) ;
struct V_67 * V_68 = (struct V_67 * ) V_44 -> V_69 ;
unsigned int V_20 ;
V_20 = F_3 ( V_2 , V_68 -> V_3 ) ;
if ( V_20 & V_70 && ! ( V_20 & V_71 ) )
return - V_72 ;
return F_30 ( V_44 , V_66 ) ;
}
static int F_31 ( struct V_43 * V_44 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
V_66 -> V_8 . V_73 . V_74 [ 0 ] = V_12 -> V_49 ;
return 0 ;
}
static int F_33 ( struct V_43 * V_44 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_35 = V_66 -> V_8 . V_73 . V_74 [ 0 ] ;
int V_47 = 0 ;
if ( ! V_12 -> V_48 )
V_47 = F_13 ( V_2 , V_35 ) ;
if ( ! V_47 )
V_12 -> V_49 = V_35 ;
return V_47 ;
}
static int F_34 ( struct V_43 * V_44 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
V_66 -> V_8 . V_73 . V_74 [ 0 ] = V_12 -> V_75 ;
return 0 ;
}
static int F_35 ( struct V_43 * V_44 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
V_12 -> V_75 = V_66 -> V_8 . V_73 . V_74 [ 0 ] ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = & V_2 -> V_77 ;
if ( F_37 ( V_77 , L_1 ) )
return - 1 ;
if ( F_37 ( V_77 , L_2 ) ||
F_37 ( V_77 , L_3 ) ) {
T_1 V_20 = F_38 ( V_2 , V_13 ) ;
if ( V_20 & V_40 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
return V_12 -> V_75 ;
}
int F_40 ( struct V_1 * V_2 , enum V_78 V_79 )
{
if ( F_41 ( V_79 >= V_80 ) )
return - V_81 ;
return F_1 ( V_2 , V_22 + V_79 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( F_10 ( V_9 ) < V_82 )
return 2 ;
else
return 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_47 ;
switch ( V_84 ) {
case V_85 :
break;
case V_86 :
break;
case V_87 :
if ( V_12 -> V_88 )
break;
V_47 = F_44 ( V_9 , 1 ) ;
if ( V_47 )
return V_47 ;
V_12 -> V_88 = 1 ;
F_11 ( V_2 ) ;
F_7 ( V_2 , V_89 , 0x02 ) ;
break;
case V_90 :
if ( ! V_12 -> V_88 )
break;
F_44 ( V_9 , 0 ) ;
V_12 -> V_88 = 0 ;
break;
}
V_2 -> V_77 . V_91 = V_84 ;
return 0 ;
}
static int F_45 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
F_46 ( V_93 -> V_96 , 0 ,
V_97 ,
& V_98 [ V_12 -> V_75 ] ) ;
return 0 ;
}
static int F_47 ( struct V_92 * V_93 ,
struct V_99 * V_100 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_101 ;
V_101 = F_48 ( V_100 ) ;
switch ( V_101 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_41 ( V_12 -> V_102 == V_103 ) ) {
F_49 ( V_2 -> V_104 , L_4 ,
V_101 ) ;
return - V_81 ;
}
V_12 -> V_105 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_12 -> V_105 = 19200000 ;
break;
default:
F_49 ( V_2 -> V_104 , L_5 , V_101 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_50 ( struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_2 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_47 ;
if ( ! V_12 -> V_105 ) {
F_49 ( V_2 -> V_104 ,
L_6 ) ;
return - V_81 ;
}
V_47 = F_51 ( V_9 , V_12 -> V_102 , V_12 -> V_106 , V_12 -> V_105 ) ;
if ( V_47 ) {
F_49 ( V_2 -> V_104 , L_7 , V_47 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_52 ( struct V_94 * V_108 ,
int V_109 , unsigned int V_110 , int V_111 )
{
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
switch ( V_109 ) {
case V_112 :
case V_103 :
V_12 -> V_102 = V_109 ;
V_12 -> V_106 = V_110 ;
break;
default:
F_49 ( V_2 -> V_104 , L_8 , V_109 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , enum V_113 V_114 ,
int V_115 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_6 ( V_2 ) ;
int V_36 , V_37 , V_116 ;
int V_117 , V_118 ;
switch ( V_114 ) {
case V_119 :
V_36 = F_1 ( V_2 , V_13 ) ;
V_37 = F_1 ( V_2 , V_14 ) ;
V_116 = F_1 ( V_2 , V_15 ) ;
if ( V_115 ) {
V_116 &= ~ 0x01 ;
V_36 &= ~ ( V_120 | V_46 ) ;
V_37 &= ~ ( V_120 | V_46 ) ;
}
F_8 ( V_9 , V_15 , V_116 ) ;
F_8 ( V_9 , V_13 , V_36 ) ;
F_8 ( V_9 , V_14 , V_37 ) ;
V_12 -> V_16 = ! V_115 ;
break;
case V_121 :
V_117 = F_1 ( V_2 , V_17 ) ;
V_118 = F_1 ( V_2 , V_18 ) ;
if ( V_115 ) {
V_117 &= ~ ( V_122 | V_123 |
V_124 ) ;
V_118 &= ~ ( V_122 | V_123 |
V_124 ) ;
}
F_8 ( V_9 , V_17 , V_117 ) ;
F_8 ( V_9 , V_18 , V_118 ) ;
V_12 -> V_19 = ! V_115 ;
break;
default:
break;
}
}
static int F_54 ( struct V_94 * V_95 , int V_115 )
{
switch ( V_95 -> V_114 ) {
case V_125 :
F_53 ( V_95 -> V_2 , V_119 , V_115 ) ;
F_53 ( V_95 -> V_2 , V_121 , V_115 ) ;
break;
case V_119 :
case V_121 :
F_53 ( V_95 -> V_2 , V_95 -> V_114 , V_115 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_90 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_87 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_126 * V_127 = F_24 ( V_2 -> V_104 ,
struct V_126 , V_104 ) ;
int V_47 = 0 ;
V_12 = F_58 ( V_2 -> V_104 , sizeof( * V_12 ) , V_128 ) ;
if ( V_12 == NULL )
return - V_129 ;
F_59 ( V_2 , V_12 ) ;
V_12 -> V_2 = V_2 ;
V_2 -> V_10 = F_60 ( V_2 -> V_104 -> V_130 ) ;
V_12 -> V_131 = F_61 ( V_127 , 0 ) ;
if ( V_12 -> V_131 < 0 ) {
F_49 ( V_2 -> V_104 , L_9 ) ;
return - V_81 ;
}
F_62 ( & V_12 -> V_58 . V_60 , F_23 ) ;
F_63 ( & V_12 -> V_54 ) ;
V_47 = F_64 ( V_12 -> V_131 , NULL ,
F_25 , V_132 ,
L_10 , V_2 ) ;
if ( V_47 ) {
F_49 ( V_2 -> V_104 , L_11 , V_47 ) ;
return V_47 ;
}
F_9 ( V_2 ) ;
return F_43 ( V_2 , V_87 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
F_66 ( V_12 -> V_131 , V_2 ) ;
F_43 ( V_2 , V_90 ) ;
return 0 ;
}
static int F_67 ( struct V_126 * V_127 )
{
return F_68 ( & V_127 -> V_104 , & V_133 ,
V_134 , F_12 ( V_134 ) ) ;
}
static int F_69 ( struct V_126 * V_127 )
{
F_70 ( & V_127 -> V_104 ) ;
return 0 ;
}
