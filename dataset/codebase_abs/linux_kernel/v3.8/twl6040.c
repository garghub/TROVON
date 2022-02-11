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
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
if ( F_4 ( V_3 < V_11 ) )
return F_7 ( V_9 , V_3 , V_8 ) ;
else
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
T_1 V_12 ;
V_12 = F_9 ( V_9 ) ;
F_2 ( V_2 , V_13 , V_12 ) ;
F_3 ( V_2 , V_14 ) ;
F_3 ( V_2 , V_15 ) ;
F_3 ( V_2 , V_16 ) ;
F_3 ( V_2 , V_17 ) ;
F_3 ( V_2 , V_18 ) ;
F_2 ( V_2 , V_19 , 0x18 ) ;
F_2 ( V_2 , V_20 , 0x18 ) ;
F_2 ( V_2 , V_21 , 0xff ) ;
F_2 ( V_2 , V_22 , 0x1e ) ;
F_2 ( V_2 , V_23 , 0x1d ) ;
F_2 ( V_2 , V_24 , 0x1d ) ;
F_2 ( V_2 , V_25 , 0 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_26 ;
for ( V_26 = 0 ; V_26 < F_11 ( V_27 ) ; V_26 ++ ) {
V_3 = V_27 [ V_26 ] ;
F_6 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static int F_12 ( struct V_1 * V_2 , int V_28 )
{
int V_29 , V_30 ;
int V_31 = V_32 | V_33 ;
V_29 = F_1 ( V_2 , V_34 ) ;
V_30 = F_1 ( V_2 , V_35 ) ;
if ( V_28 ) {
V_29 &= ~ V_31 ;
V_30 &= ~ V_31 ;
} else {
V_29 |= V_31 ;
V_30 |= V_31 ;
}
F_6 ( V_2 , V_34 , V_29 ) ;
F_6 ( V_2 , V_35 , V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_29 , V_30 ;
V_29 = F_1 ( V_2 , V_34 ) ;
V_30 = F_1 ( V_2 , V_35 ) ;
if ( F_14 ( V_40 ) ) {
V_29 |= V_41 ;
V_30 |= V_41 ;
} else {
V_29 &= ~ V_41 ;
V_30 &= ~ V_41 ;
}
F_6 ( V_2 , V_34 , V_29 ) ;
F_6 ( V_2 , V_35 , V_30 ) ;
F_15 ( 1 ) ;
return 0 ;
}
static int F_16 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_44 = 0 ;
if ( F_14 ( V_40 ) ) {
V_43 -> V_45 = 1 ;
V_44 = F_12 ( V_2 , 1 ) ;
} else {
V_43 -> V_45 = 0 ;
V_44 = F_12 ( V_2 , V_43 -> V_46 ) ;
}
F_15 ( 1 ) ;
return V_44 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_47 * V_48 , int V_49 )
{
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_50 ;
F_19 ( & V_43 -> V_51 ) ;
V_50 = F_3 ( V_2 , V_52 ) ;
if ( V_50 & V_53 )
F_20 ( V_48 , V_49 , V_49 ) ;
else
F_20 ( V_48 , 0 , V_49 ) ;
F_21 ( & V_43 -> V_51 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_47 * V_48 , int V_49 )
{
struct V_42 * V_43 = F_17 ( V_2 ) ;
struct V_54 * V_55 = & V_43 -> V_55 ;
V_55 -> V_48 = V_48 ;
V_55 -> V_49 = V_49 ;
F_18 ( V_2 , V_55 -> V_48 , V_55 -> V_49 ) ;
}
static void F_23 ( struct V_56 * V_57 )
{
struct V_42 * V_43 = F_24 ( V_57 ,
struct V_42 , V_55 . V_57 . V_57 ) ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_54 * V_55 = & V_43 -> V_55 ;
F_18 ( V_2 , V_55 -> V_48 , V_55 -> V_49 ) ;
}
static T_2 F_25 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
F_26 ( V_43 -> V_60 , & V_43 -> V_55 . V_57 ,
F_27 ( 200 ) ) ;
return V_61 ;
}
static int F_28 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = F_29 ( V_39 ) ;
struct V_36 * V_66 = V_65 -> V_67 [ 0 ] ;
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_68 * V_69 = (struct V_68 * ) V_39 -> V_70 ;
unsigned int V_12 ;
V_12 = F_3 ( V_2 , V_69 -> V_3 ) ;
if ( V_12 & V_71 && ! ( V_12 & V_72 ) )
return - V_73 ;
return F_30 ( V_39 , V_63 ) ;
}
static int F_31 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
V_63 -> V_8 . V_74 . V_75 [ 0 ] = V_43 -> V_46 ;
return 0 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_28 = V_63 -> V_8 . V_74 . V_75 [ 0 ] ;
int V_44 = 0 ;
if ( ! V_43 -> V_45 )
V_44 = F_12 ( V_2 , V_28 ) ;
if ( ! V_44 )
V_43 -> V_46 = V_28 ;
return V_44 ;
}
static int F_33 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
V_63 -> V_8 . V_74 . V_75 [ 0 ] = V_43 -> V_76 ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_29 ( V_39 ) ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
V_43 -> V_76 = V_63 -> V_8 . V_74 . V_75 [ 0 ] ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_78 ;
if ( F_36 ( V_78 , L_1 ) )
return - 1 ;
if ( F_36 ( V_78 , L_2 ) ||
F_36 ( V_78 , L_3 ) ) {
T_1 V_12 = F_37 ( V_2 , V_34 ) ;
if ( V_12 & V_33 )
return - 8 ;
else
return - 1 ;
}
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_17 ( V_2 ) ;
return V_43 -> V_76 ;
}
int F_39 ( struct V_1 * V_2 , enum V_79 V_80 )
{
if ( F_40 ( V_80 >= V_81 ) )
return - V_82 ;
return F_1 ( V_2 , V_14 + V_80 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( F_9 ( V_9 ) < V_83 )
return 2 ;
else
return 1 ;
}
static int F_42 ( struct V_1 * V_2 ,
enum V_84 V_85 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_44 ;
switch ( V_85 ) {
case V_86 :
break;
case V_87 :
break;
case V_88 :
if ( V_43 -> V_89 )
break;
V_44 = F_43 ( V_9 , 1 ) ;
if ( V_44 )
return V_44 ;
V_43 -> V_89 = 1 ;
F_10 ( V_2 ) ;
F_6 ( V_2 , V_90 , 0x02 ) ;
break;
case V_91 :
if ( ! V_43 -> V_89 )
break;
F_43 ( V_9 , 0 ) ;
V_43 -> V_89 = 0 ;
break;
}
V_2 -> V_78 . V_92 = V_85 ;
return 0 ;
}
static int F_44 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
F_45 ( V_94 -> V_97 , 0 ,
V_98 ,
& V_99 [ V_43 -> V_76 ] ) ;
return 0 ;
}
static int F_46 ( struct V_93 * V_94 ,
struct V_100 * V_101 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_102 ;
V_102 = F_47 ( V_101 ) ;
switch ( V_102 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_40 ( V_43 -> V_103 == V_104 ) ) {
F_48 ( V_2 -> V_105 , L_4 ,
V_102 ) ;
return - V_82 ;
}
V_43 -> V_106 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_43 -> V_106 = 19200000 ;
break;
default:
F_48 ( V_2 -> V_105 , L_5 , V_102 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_49 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_2 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
int V_44 ;
if ( ! V_43 -> V_106 ) {
F_48 ( V_2 -> V_105 ,
L_6 ) ;
return - V_82 ;
}
V_44 = F_50 ( V_9 , V_43 -> V_103 , V_43 -> V_107 , V_43 -> V_106 ) ;
if ( V_44 ) {
F_48 ( V_2 -> V_105 , L_7 , V_44 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_51 ( struct V_95 * V_109 ,
int V_110 , unsigned int V_111 , int V_112 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
struct V_42 * V_43 = F_17 ( V_2 ) ;
switch ( V_110 ) {
case V_113 :
case V_104 :
V_43 -> V_103 = V_110 ;
V_43 -> V_107 = V_111 ;
break;
default:
F_48 ( V_2 -> V_105 , L_8 , V_110 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
F_42 ( V_2 , V_88 ) ;
F_42 ( V_2 , V_2 -> V_78 . V_114 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_115 * V_116 = F_55 ( V_2 -> V_105 ) ;
struct V_117 * V_118 = F_24 ( V_2 -> V_105 ,
struct V_117 , V_105 ) ;
int V_44 = 0 ;
V_43 = F_56 ( sizeof( struct V_42 ) , V_119 ) ;
if ( V_43 == NULL )
return - V_120 ;
F_57 ( V_2 , V_43 ) ;
V_43 -> V_2 = V_2 ;
V_2 -> V_10 = F_58 ( V_2 -> V_105 -> V_121 ) ;
if ( V_116 && V_116 -> V_122 && V_116 -> V_123 ) {
V_43 -> V_122 = V_116 -> V_122 ;
V_43 -> V_123 = V_116 -> V_123 ;
} else {
V_43 -> V_122 = 1 ;
V_43 -> V_123 = 1 ;
}
if ( V_116 && V_116 -> V_124 && V_116 -> V_125 ) {
V_43 -> V_124 = V_116 -> V_124 ;
V_43 -> V_125 = V_116 -> V_125 ;
} else {
V_43 -> V_124 = 1 ;
V_43 -> V_125 = 1 ;
}
V_43 -> V_126 = F_59 ( V_118 , 0 ) ;
if ( V_43 -> V_126 < 0 ) {
F_48 ( V_2 -> V_105 , L_9 ) ;
V_44 = - V_82 ;
goto V_127;
}
V_43 -> V_60 = F_60 ( L_10 , 0 , 0 ) ;
if ( ! V_43 -> V_60 ) {
V_44 = - V_120 ;
goto V_127;
}
F_61 ( & V_43 -> V_55 . V_57 , F_23 ) ;
F_62 ( & V_43 -> V_51 ) ;
V_44 = F_63 ( V_43 -> V_126 , NULL , F_25 ,
0 , L_11 , V_2 ) ;
if ( V_44 ) {
F_48 ( V_2 -> V_105 , L_12 , V_44 ) ;
goto V_128;
}
F_8 ( V_2 ) ;
V_44 = F_42 ( V_2 , V_88 ) ;
if ( ! V_44 )
return 0 ;
F_64 ( V_43 -> V_126 , V_2 ) ;
V_128:
F_65 ( V_43 -> V_60 ) ;
V_127:
F_66 ( V_43 ) ;
return V_44 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_17 ( V_2 ) ;
F_42 ( V_2 , V_91 ) ;
F_64 ( V_43 -> V_126 , V_2 ) ;
F_65 ( V_43 -> V_60 ) ;
F_66 ( V_43 ) ;
return 0 ;
}
static int F_68 ( struct V_117 * V_118 )
{
return F_69 ( & V_118 -> V_105 , & V_129 ,
V_130 , F_11 ( V_130 ) ) ;
}
static int F_70 ( struct V_117 * V_118 )
{
F_71 ( & V_118 -> V_105 ) ;
return 0 ;
}
