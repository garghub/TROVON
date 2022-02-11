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
if ( F_4 ( V_3 < V_11 ) ) {
V_8 = F_5 ( V_9 , V_3 ) ;
F_2 ( V_2 , V_3 , V_8 ) ;
} else {
V_8 = F_1 ( V_2 , V_3 ) ;
}
return V_8 ;
}
static bool F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
switch ( V_3 ) {
case V_14 :
case V_15 :
case V_16 :
return V_13 -> V_17 ;
case V_18 :
case V_19 :
return V_13 -> V_20 ;
default:
return 1 ;
} ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
if ( F_4 ( V_3 < V_11 ) &&
F_6 ( V_2 , V_3 ) )
return F_9 ( V_9 , V_3 , V_8 ) ;
else
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
T_1 V_21 ;
V_21 = F_11 ( V_9 ) ;
F_2 ( V_2 , V_22 , V_21 ) ;
F_3 ( V_2 , V_23 ) ;
F_3 ( V_2 , V_24 ) ;
F_3 ( V_2 , V_25 ) ;
F_3 ( V_2 , V_26 ) ;
F_3 ( V_2 , V_27 ) ;
F_2 ( V_2 , V_28 , 0x18 ) ;
F_2 ( V_2 , V_29 , 0x18 ) ;
F_2 ( V_2 , V_30 , 0xff ) ;
F_2 ( V_2 , V_16 , 0x1e ) ;
F_2 ( V_2 , V_31 , 0x1d ) ;
F_2 ( V_2 , V_32 , 0x1d ) ;
F_2 ( V_2 , V_33 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_34 ;
for ( V_34 = 0 ; V_34 < F_13 ( V_35 ) ; V_34 ++ ) {
V_3 = V_35 [ V_34 ] ;
F_8 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_36 )
{
int V_37 , V_38 ;
int V_39 = V_40 | V_41 ;
V_37 = F_1 ( V_2 , V_14 ) ;
V_38 = F_1 ( V_2 , V_15 ) ;
if ( V_36 ) {
V_37 &= ~ V_39 ;
V_38 &= ~ V_39 ;
} else {
V_37 |= V_39 ;
V_38 |= V_39 ;
}
F_8 ( V_2 , V_14 , V_37 ) ;
F_8 ( V_2 , V_15 , V_38 ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_43 ,
struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
T_1 V_37 , V_38 ;
V_37 = F_1 ( V_2 , V_14 ) ;
V_38 = F_1 ( V_2 , V_15 ) ;
if ( F_16 ( V_46 ) ) {
V_37 |= V_47 ;
V_38 |= V_47 ;
} else {
V_37 &= ~ V_47 ;
V_38 &= ~ V_47 ;
}
F_8 ( V_2 , V_14 , V_37 ) ;
F_8 ( V_2 , V_15 , V_38 ) ;
F_17 ( 1 ) ;
return 0 ;
}
static int F_18 ( struct V_42 * V_43 ,
struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_48 = 0 ;
if ( F_16 ( V_46 ) ) {
V_13 -> V_49 = 1 ;
V_48 = F_14 ( V_2 , 1 ) ;
} else {
V_13 -> V_49 = 0 ;
V_48 = F_14 ( V_2 , V_13 -> V_50 ) ;
}
F_17 ( 1 ) ;
return V_48 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_51 * V_52 , int V_53 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_54 ;
F_20 ( & V_13 -> V_55 ) ;
V_54 = F_3 ( V_2 , V_56 ) ;
if ( V_54 & V_57 )
F_21 ( V_52 , V_53 , V_53 ) ;
else
F_21 ( V_52 , 0 , V_53 ) ;
F_22 ( & V_13 -> V_55 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_51 * V_52 , int V_53 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
struct V_58 * V_59 = & V_13 -> V_59 ;
V_59 -> V_52 = V_52 ;
V_59 -> V_53 = V_53 ;
F_19 ( V_2 , V_59 -> V_52 , V_59 -> V_53 ) ;
}
static void F_24 ( struct V_60 * V_61 )
{
struct V_12 * V_13 = F_25 ( V_61 ,
struct V_12 , V_59 . V_61 . V_61 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_58 * V_59 = & V_13 -> V_59 ;
F_19 ( V_2 , V_59 -> V_52 , V_59 -> V_53 ) ;
}
static T_2 F_26 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_27 ( V_64 ,
& V_13 -> V_59 . V_61 , F_28 ( 200 ) ) ;
return V_65 ;
}
static int F_29 ( struct V_44 * V_45 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_68 * V_69 = (struct V_68 * ) V_45 -> V_70 ;
unsigned int V_21 ;
V_21 = F_3 ( V_2 , V_69 -> V_3 ) ;
if ( V_21 & V_71 && ! ( V_21 & V_72 ) )
return - V_73 ;
return F_31 ( V_45 , V_67 ) ;
}
static int F_32 ( struct V_44 * V_45 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_67 -> V_8 . V_74 . V_75 [ 0 ] = V_13 -> V_50 ;
return 0 ;
}
static int F_34 ( struct V_44 * V_45 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_36 = V_67 -> V_8 . V_74 . V_75 [ 0 ] ;
int V_48 = 0 ;
if ( ! V_13 -> V_49 )
V_48 = F_14 ( V_2 , V_36 ) ;
if ( ! V_48 )
V_13 -> V_50 = V_36 ;
return V_48 ;
}
static int F_35 ( struct V_44 * V_45 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_67 -> V_8 . V_74 . V_75 [ 0 ] = V_13 -> V_76 ;
return 0 ;
}
static int F_36 ( struct V_44 * V_45 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_13 -> V_76 = V_67 -> V_8 . V_74 . V_75 [ 0 ] ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_78 ;
if ( F_38 ( V_78 , L_1 ) )
return - 1 ;
if ( F_38 ( V_78 , L_2 ) ||
F_38 ( V_78 , L_3 ) ) {
T_1 V_21 = F_39 ( V_2 , V_14 ) ;
if ( V_21 & V_41 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
return V_13 -> V_76 ;
}
int F_41 ( struct V_1 * V_2 , enum V_79 V_80 )
{
if ( F_42 ( V_80 >= V_81 ) )
return - V_82 ;
return F_1 ( V_2 , V_23 + V_80 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( F_11 ( V_9 ) < V_83 )
return 2 ;
else
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
enum V_84 V_85 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_48 ;
switch ( V_85 ) {
case V_86 :
break;
case V_87 :
break;
case V_88 :
if ( V_13 -> V_89 )
break;
V_48 = F_45 ( V_9 , 1 ) ;
if ( V_48 )
return V_48 ;
V_13 -> V_89 = 1 ;
F_12 ( V_2 ) ;
F_8 ( V_2 , V_90 , 0x02 ) ;
break;
case V_91 :
if ( ! V_13 -> V_89 )
break;
F_45 ( V_9 , 0 ) ;
V_13 -> V_89 = 0 ;
break;
}
V_2 -> V_78 . V_92 = V_85 ;
return 0 ;
}
static int F_46 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_47 ( V_94 -> V_97 , 0 ,
V_98 ,
& V_99 [ V_13 -> V_76 ] ) ;
return 0 ;
}
static int F_48 ( struct V_93 * V_94 ,
struct V_100 * V_101 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_102 ;
V_102 = F_49 ( V_101 ) ;
switch ( V_102 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_42 ( V_13 -> V_103 == V_104 ) ) {
F_50 ( V_2 -> V_105 , L_4 ,
V_102 ) ;
return - V_82 ;
}
V_13 -> V_106 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_13 -> V_106 = 19200000 ;
break;
default:
F_50 ( V_2 -> V_105 , L_5 , V_102 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_51 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_48 ;
if ( ! V_13 -> V_106 ) {
F_50 ( V_2 -> V_105 ,
L_6 ) ;
return - V_82 ;
}
V_48 = F_52 ( V_9 , V_13 -> V_103 , V_13 -> V_107 , V_13 -> V_106 ) ;
if ( V_48 ) {
F_50 ( V_2 -> V_105 , L_7 , V_48 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_53 ( struct V_95 * V_109 ,
int V_110 , unsigned int V_111 , int V_112 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
switch ( V_110 ) {
case V_113 :
case V_104 :
V_13 -> V_103 = V_110 ;
V_13 -> V_107 = V_111 ;
break;
default:
F_50 ( V_2 -> V_105 , L_8 , V_110 ) ;
return - V_82 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , enum V_114 V_115 ,
int V_116 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_37 , V_38 , V_117 ;
int V_118 , V_119 ;
switch ( V_115 ) {
case V_120 :
V_37 = F_1 ( V_2 , V_14 ) ;
V_38 = F_1 ( V_2 , V_15 ) ;
V_117 = F_1 ( V_2 , V_16 ) ;
if ( V_116 ) {
V_117 &= ~ 0x01 ;
V_37 &= ~ ( V_121 | V_47 ) ;
V_38 &= ~ ( V_121 | V_47 ) ;
}
F_9 ( V_9 , V_16 , V_117 ) ;
F_9 ( V_9 , V_14 , V_37 ) ;
F_9 ( V_9 , V_15 , V_38 ) ;
V_13 -> V_17 = ! V_116 ;
break;
case V_122 :
V_118 = F_1 ( V_2 , V_18 ) ;
V_119 = F_1 ( V_2 , V_19 ) ;
if ( V_116 ) {
V_118 &= ~ ( V_123 | V_124 |
V_125 ) ;
V_119 &= ~ ( V_123 | V_124 |
V_125 ) ;
}
F_9 ( V_9 , V_18 , V_118 ) ;
F_9 ( V_9 , V_19 , V_119 ) ;
V_13 -> V_20 = ! V_116 ;
break;
default:
break;
} ;
}
static int F_55 ( struct V_95 * V_96 , int V_116 )
{
switch ( V_96 -> V_115 ) {
case V_126 :
F_54 ( V_96 -> V_2 , V_120 , V_116 ) ;
F_54 ( V_96 -> V_2 , V_122 , V_116 ) ;
break;
case V_120 :
case V_122 :
F_54 ( V_96 -> V_2 , V_96 -> V_115 , V_116 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_44 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_44 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_127 * V_128 = F_25 ( V_2 -> V_105 ,
struct V_127 , V_105 ) ;
int V_48 = 0 ;
V_13 = F_59 ( V_2 -> V_105 , sizeof( * V_13 ) , V_129 ) ;
if ( V_13 == NULL )
return - V_130 ;
F_60 ( V_2 , V_13 ) ;
V_13 -> V_2 = V_2 ;
V_2 -> V_10 = F_61 ( V_2 -> V_105 -> V_131 ) ;
V_13 -> V_132 = F_62 ( V_128 , 0 ) ;
if ( V_13 -> V_132 < 0 ) {
F_50 ( V_2 -> V_105 , L_9 ) ;
return - V_82 ;
}
F_63 ( & V_13 -> V_59 . V_61 , F_24 ) ;
F_64 ( & V_13 -> V_55 ) ;
V_48 = F_65 ( V_13 -> V_132 , NULL ,
F_26 , V_133 ,
L_10 , V_2 ) ;
if ( V_48 ) {
F_50 ( V_2 -> V_105 , L_11 , V_48 ) ;
return V_48 ;
}
F_10 ( V_2 ) ;
return F_44 ( V_2 , V_88 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_67 ( V_13 -> V_132 , V_2 ) ;
F_44 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_68 ( struct V_127 * V_128 )
{
return F_69 ( & V_128 -> V_105 , & V_134 ,
V_135 , F_13 ( V_135 ) ) ;
}
static int F_70 ( struct V_127 * V_128 )
{
F_71 ( & V_128 -> V_105 ) ;
return 0 ;
}
