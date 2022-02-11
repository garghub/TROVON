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
F_27 ( & V_13 -> V_59 . V_61 , F_28 ( 200 ) ) ;
return V_64 ;
}
static int F_29 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = F_30 ( V_45 ) ;
struct V_42 * V_69 = V_68 -> V_70 [ 0 ] ;
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_71 * V_72 = (struct V_71 * ) V_45 -> V_73 ;
unsigned int V_21 ;
V_21 = F_3 ( V_2 , V_72 -> V_3 ) ;
if ( V_21 & V_74 && ! ( V_21 & V_75 ) )
return - V_76 ;
return F_31 ( V_45 , V_66 ) ;
}
static int F_32 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_66 -> V_8 . V_77 . V_78 [ 0 ] = V_13 -> V_50 ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_36 = V_66 -> V_8 . V_77 . V_78 [ 0 ] ;
int V_48 = 0 ;
if ( ! V_13 -> V_49 )
V_48 = F_14 ( V_2 , V_36 ) ;
if ( ! V_48 )
V_13 -> V_50 = V_36 ;
return V_48 ;
}
static int F_34 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_66 -> V_8 . V_77 . V_78 [ 0 ] = V_13 -> V_79 ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
V_13 -> V_79 = V_66 -> V_8 . V_77 . V_78 [ 0 ] ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 ;
if ( F_37 ( V_81 , L_1 ) )
return - 1 ;
if ( F_37 ( V_81 , L_2 ) ||
F_37 ( V_81 , L_3 ) ) {
T_1 V_21 = F_38 ( V_2 , V_14 ) ;
if ( V_21 & V_41 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
return V_13 -> V_79 ;
}
int F_40 ( struct V_1 * V_2 , enum V_82 V_83 )
{
if ( F_41 ( V_83 >= V_84 ) )
return - V_85 ;
return F_1 ( V_2 , V_23 + V_83 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( F_11 ( V_9 ) < V_86 )
return 2 ;
else
return 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_87 V_88 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_48 ;
switch ( V_88 ) {
case V_89 :
break;
case V_90 :
break;
case V_91 :
if ( V_13 -> V_92 )
break;
V_48 = F_44 ( V_9 , 1 ) ;
if ( V_48 )
return V_48 ;
V_13 -> V_92 = 1 ;
F_12 ( V_2 ) ;
F_8 ( V_2 , V_93 , 0x02 ) ;
break;
case V_94 :
if ( ! V_13 -> V_92 )
break;
F_44 ( V_9 , 0 ) ;
V_13 -> V_92 = 0 ;
break;
}
V_2 -> V_81 . V_95 = V_88 ;
return 0 ;
}
static int F_45 ( struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_46 ( V_97 -> V_100 , 0 ,
V_101 ,
& V_102 [ V_13 -> V_79 ] ) ;
return 0 ;
}
static int F_47 ( struct V_96 * V_97 ,
struct V_103 * V_104 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_105 ;
V_105 = F_48 ( V_104 ) ;
switch ( V_105 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_41 ( V_13 -> V_106 == V_107 ) ) {
F_49 ( V_2 -> V_108 , L_4 ,
V_105 ) ;
return - V_85 ;
}
V_13 -> V_109 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_13 -> V_109 = 19200000 ;
break;
default:
F_49 ( V_2 -> V_108 , L_5 , V_105 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_50 ( struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = V_99 -> V_2 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_48 ;
if ( ! V_13 -> V_109 ) {
F_49 ( V_2 -> V_108 ,
L_6 ) ;
return - V_85 ;
}
V_48 = F_51 ( V_9 , V_13 -> V_106 , V_13 -> V_110 , V_13 -> V_109 ) ;
if ( V_48 ) {
F_49 ( V_2 -> V_108 , L_7 , V_48 ) ;
return - V_111 ;
}
return 0 ;
}
static int F_52 ( struct V_98 * V_112 ,
int V_113 , unsigned int V_114 , int V_115 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
switch ( V_113 ) {
case V_116 :
case V_107 :
V_13 -> V_106 = V_113 ;
V_13 -> V_110 = V_114 ;
break;
default:
F_49 ( V_2 -> V_108 , L_8 , V_113 ) ;
return - V_85 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , enum V_117 V_118 ,
int V_119 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_12 * V_13 = F_7 ( V_2 ) ;
int V_37 , V_38 , V_120 ;
int V_121 , V_122 ;
switch ( V_118 ) {
case V_123 :
V_37 = F_1 ( V_2 , V_14 ) ;
V_38 = F_1 ( V_2 , V_15 ) ;
V_120 = F_1 ( V_2 , V_16 ) ;
if ( V_119 ) {
V_120 &= ~ 0x01 ;
V_37 &= ~ ( V_124 | V_47 ) ;
V_38 &= ~ ( V_124 | V_47 ) ;
}
F_9 ( V_9 , V_16 , V_120 ) ;
F_9 ( V_9 , V_14 , V_37 ) ;
F_9 ( V_9 , V_15 , V_38 ) ;
V_13 -> V_17 = ! V_119 ;
break;
case V_125 :
V_121 = F_1 ( V_2 , V_18 ) ;
V_122 = F_1 ( V_2 , V_19 ) ;
if ( V_119 ) {
V_121 &= ~ ( V_126 | V_127 |
V_128 ) ;
V_122 &= ~ ( V_126 | V_127 |
V_128 ) ;
}
F_9 ( V_9 , V_18 , V_121 ) ;
F_9 ( V_9 , V_19 , V_122 ) ;
V_13 -> V_20 = ! V_119 ;
break;
default:
break;
} ;
}
static int F_54 ( struct V_98 * V_99 , int V_119 )
{
switch ( V_99 -> V_118 ) {
case V_129 :
F_53 ( V_99 -> V_2 , V_123 , V_119 ) ;
F_53 ( V_99 -> V_2 , V_125 , V_119 ) ;
break;
case V_123 :
case V_125 :
F_53 ( V_99 -> V_2 , V_99 -> V_118 , V_119 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_130 * V_131 = F_25 ( V_2 -> V_108 ,
struct V_130 , V_108 ) ;
int V_48 = 0 ;
V_13 = F_58 ( V_2 -> V_108 , sizeof( * V_13 ) , V_132 ) ;
if ( V_13 == NULL )
return - V_133 ;
F_59 ( V_2 , V_13 ) ;
V_13 -> V_2 = V_2 ;
V_2 -> V_10 = F_60 ( V_2 -> V_108 -> V_134 ) ;
V_13 -> V_135 = F_61 ( V_131 , 0 ) ;
if ( V_13 -> V_135 < 0 ) {
F_49 ( V_2 -> V_108 , L_9 ) ;
return - V_85 ;
}
F_62 ( & V_13 -> V_59 . V_61 , F_24 ) ;
F_63 ( & V_13 -> V_55 ) ;
V_48 = F_64 ( V_13 -> V_135 , NULL ,
F_26 , V_136 ,
L_10 , V_2 ) ;
if ( V_48 ) {
F_49 ( V_2 -> V_108 , L_11 , V_48 ) ;
return V_48 ;
}
F_10 ( V_2 ) ;
return F_43 ( V_2 , V_91 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_7 ( V_2 ) ;
F_66 ( V_13 -> V_135 , V_2 ) ;
F_43 ( V_2 , V_94 ) ;
return 0 ;
}
static int F_67 ( struct V_130 * V_131 )
{
return F_68 ( & V_131 -> V_108 , & V_137 ,
V_138 , F_13 ( V_138 ) ) ;
}
static int F_69 ( struct V_130 * V_131 )
{
F_70 ( & V_131 -> V_108 ) ;
return 0 ;
}
