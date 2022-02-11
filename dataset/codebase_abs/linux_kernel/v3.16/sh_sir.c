static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_6 , T_2 V_4 )
{
T_2 V_7 , V_8 ;
V_7 = F_3 ( V_2 , V_3 ) ;
V_8 = ( V_7 & ~ V_6 ) | V_4 ;
if ( V_7 != V_8 )
F_1 ( V_2 , V_3 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_3 V_4 )
{
F_1 ( V_2 , V_11 , ( T_2 ) V_4 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
return V_12 & F_3 ( V_2 , V_9 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 -> V_15 ;
int V_17 = - V_18 ;
T_2 V_19 ;
F_6 ( V_2 ) ;
F_7 ( V_2 , 0xCC ) ;
F_7 ( V_2 , 0xF5 ) ;
F_7 ( V_2 , 0xF1 ) ;
F_7 ( V_2 , 0xA7 ) ;
V_19 = F_8 ( V_2 ) ;
if ( 4 != V_19 ) {
F_11 ( V_15 , L_1 , V_19 ) ;
goto V_20;
}
V_19 = F_9 ( V_2 ) ;
if ( 0x51DF != V_19 ) {
F_11 ( V_15 , L_2 , V_19 ) ;
goto V_20;
}
V_17 = 0 ;
V_20:
F_6 ( V_2 ) ;
return V_17 ;
}
static T_1 F_12 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_23 * V_25 ;
struct V_21 * V_26 = F_13 ( NULL , L_3 ) ;
T_1 V_27 , V_28 = 0xffffffff , V_29 ;
int V_30 = 0 ;
V_27 = F_14 ( V_26 ) ;
F_15 ( V_26 ) ;
F_16 (pos, freq_table) {
T_1 V_31 = V_25 -> V_32 ;
if ( V_31 > V_27 )
continue;
V_29 = V_31 % V_33 ;
if ( V_29 < V_28 ) {
V_28 = V_29 ;
V_30 = V_25 - V_24 ;
}
}
return V_24 [ V_30 ] . V_32 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_34 )
{
struct V_21 * V_21 ;
struct V_14 * V_15 = & V_2 -> V_16 -> V_15 ;
T_1 V_35 ;
T_2 V_36 , V_37 ;
T_2 V_38 , V_39 ;
T_1 V_28 , V_40 , V_29 ;
int V_41 ;
T_1 V_42 [] = {
0 , 625 , 1250 , 1875 ,
2500 , 3125 , 3750 , 4375 ,
5000 , 5625 , 6250 , 6875 ,
7500 , 8125 , 8750 , 9375 ,
} ;
switch ( V_34 ) {
case 9600 :
break;
default:
F_11 ( V_15 , L_4 , V_34 ) ;
return - V_18 ;
}
V_21 = F_13 ( NULL , L_5 ) ;
if ( F_18 ( V_21 ) ) {
F_11 ( V_15 , L_6 ) ;
return - V_18 ;
}
F_19 ( V_21 , F_12 ( V_21 ) ) ;
V_35 = F_14 ( V_21 ) ;
F_15 ( V_21 ) ;
F_20 ( V_15 , L_7 , V_35 ) ;
V_39 = V_35 / V_33 ;
V_29 = V_35 - ( V_33 * V_39 ) ;
V_29 *= 10000 ;
V_40 = V_29 / V_33 ;
V_28 = 0xffffffff ;
V_38 = 0 ;
for ( V_41 = 0 ; V_41 < F_21 ( V_42 ) ; V_41 ++ ) {
V_29 = abs ( V_42 [ V_41 ] - V_40 ) ;
if ( V_28 > V_29 ) {
V_28 = V_29 ;
V_38 = V_41 ;
}
}
V_29 = V_35 / ( V_39 + F_22 ( V_42 [ V_38 ] ) ) ;
if ( ( V_33 / 100 ) < abs ( V_29 - V_33 ) )
F_23 ( V_15 , L_8 , V_29 ) ;
F_20 ( V_15 , L_9 ,
V_33 , V_29 , V_39 , V_42 [ V_38 ] ) ;
V_38 = ( V_38 & 0xF ) << 4 ;
V_39 = ( V_39 - 1 ) & 0xF ;
if ( ! V_39 ) {
F_11 ( V_15 , L_10 ) ;
return - V_18 ;
}
F_1 ( V_2 , V_43 , V_44 | V_45 ) ;
F_1 ( V_2 , V_46 , V_38 ) ;
F_1 ( V_2 , V_47 , V_39 ) ;
V_37 = V_35 / V_34 ;
V_37 = ( V_37 / 16 ) - 1 ;
V_37 = ( V_37 + 1 ) * 16 ;
V_29 = V_35 - ( V_37 * V_34 ) ;
V_29 *= 10000 ;
V_40 = V_29 / V_34 ;
V_28 = 0xffffffff ;
V_36 = 0 ;
for ( V_41 = 0 ; V_41 < F_21 ( V_42 ) ; V_41 ++ ) {
V_29 = abs ( V_42 [ V_41 ] - V_40 ) ;
if ( V_28 > V_29 ) {
V_28 = V_29 ;
V_36 = V_41 ;
}
}
V_29 = V_35 / ( V_37 + F_22 ( V_42 [ V_36 ] ) ) ;
if ( ( V_34 / 100 ) < abs ( V_29 - V_34 ) )
F_23 ( V_15 , L_11 , V_29 ) ;
F_20 ( V_15 , L_12 ,
V_34 , V_29 ,
V_37 , V_42 [ V_36 ] ) ;
V_36 = ( V_36 & 0xF ) << 4 ;
V_37 = ( V_37 / 16 ) - 1 ;
F_1 ( V_2 , V_48 , V_36 ) ;
F_1 ( V_2 , V_49 , V_37 ) ;
return 0 ;
}
static int F_24 ( T_4 * V_50 , int V_51 )
{
V_50 -> V_52 = F_25 ( V_51 , V_53 ) ;
if ( ! V_50 -> V_52 )
return - V_54 ;
V_50 -> V_55 = V_51 ;
V_50 -> V_56 = FALSE ;
V_50 -> V_57 = V_58 ;
V_50 -> V_4 = V_50 -> V_52 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_59 . V_52 ) ;
F_27 ( V_2 -> V_60 . V_52 ) ;
V_2 -> V_59 . V_52 = NULL ;
V_2 -> V_60 . V_52 = NULL ;
}
static int F_28 ( struct V_1 * V_2 , int V_61 , int V_62 )
{
int V_63 = - V_54 ;
if ( V_2 -> V_59 . V_52 ||
V_2 -> V_60 . V_52 ) {
F_11 ( & V_2 -> V_16 -> V_15 , L_13 ) ;
return V_63 ;
}
V_63 = F_24 ( & V_2 -> V_59 , V_61 ) ;
if ( V_63 )
goto V_64;
V_63 = F_24 ( & V_2 -> V_60 , V_62 ) ;
V_64:
if ( V_63 )
F_26 ( V_2 ) ;
return V_63 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_43 , V_45 , V_45 ) ;
F_1 ( V_2 , V_65 , 0xffff ) ;
F_1 ( V_2 , V_66 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_67 )
{
T_2 V_68 = 0 ;
T_2 V_69 = 0 ;
switch ( V_67 ) {
case V_70 :
V_68 = V_71 ;
V_69 = V_72 | V_73 ;
break;
case V_74 :
V_68 = V_75 ;
V_69 = V_73 ;
break;
case V_76 :
V_68 = V_77 ;
V_69 = V_78 ;
break;
default:
break;
}
F_1 ( V_2 , V_79 , V_68 ) ;
F_1 ( V_2 , V_80 , V_69 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_2 V_19 = F_3 ( V_2 , V_79 ) ;
if ( V_19 & V_71 )
return V_70 ;
if ( V_19 & V_75 )
return V_74 ;
if ( V_19 & V_77 )
return V_76 ;
return V_81 ;
}
static void F_32 ( struct V_1 * V_2 , int V_67 )
{
switch ( V_67 ) {
case V_70 :
if ( 0 >= V_2 -> V_60 . V_82 ) {
F_30 ( V_2 , V_74 ) ;
} else {
F_1 ( V_2 , V_83 , V_2 -> V_60 . V_4 [ 0 ] ) ;
V_2 -> V_60 . V_82 -- ;
V_2 -> V_60 . V_4 ++ ;
}
break;
case V_74 :
F_30 ( V_2 , V_76 ) ;
F_33 ( V_2 -> V_16 ) ;
break;
default:
F_11 ( & V_2 -> V_16 -> V_15 , L_14 ) ;
break;
}
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
int V_84 = 1024 ;
while ( V_84 -- ) {
V_19 = F_3 ( V_2 , V_85 ) ;
if ( V_19 & V_86 ) {
if ( V_19 & ( V_87 | V_88 | V_89 | V_90 ) )
break;
return ( int ) F_3 ( V_2 , V_91 ) ;
}
F_35 ( 1 ) ;
}
F_11 ( & V_2 -> V_16 -> V_15 , L_15 ,
V_19 , F_3 ( V_2 , V_66 ) ) ;
F_3 ( V_2 , V_91 ) ;
return - 1 ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_84 = 1024 ;
int V_4 ;
while ( V_84 -- ) {
V_4 = F_34 ( V_2 ) ;
if ( V_4 < 0 )
break;
F_37 ( V_2 -> V_16 , & V_2 -> V_16 -> V_92 ,
& V_2 -> V_59 , ( T_3 ) V_4 ) ;
V_2 -> V_16 -> V_93 = V_94 ;
if ( V_95 & F_3 ( V_2 , V_96 ) )
continue;
break;
}
}
static T_5 F_38 ( int V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_14 * V_15 = & V_2 -> V_16 -> V_15 ;
int V_67 = F_31 ( V_2 ) ;
switch ( V_67 ) {
case V_74 :
case V_70 :
F_32 ( V_2 , V_67 ) ;
break;
case V_76 :
if ( F_3 ( V_2 , V_99 ) )
F_11 ( V_15 , L_16 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
break;
default:
F_11 ( V_15 , L_17 ) ;
}
return V_100 ;
}
static int F_39 ( struct V_101 * V_102 , struct V_103 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
int V_104 = F_41 ( V_102 ) ;
if ( ( 0 < V_104 ) &&
( 9600 != V_104 ) ) {
F_11 ( & V_16 -> V_15 , L_18 , V_104 ) ;
return - V_18 ;
}
F_42 ( V_16 ) ;
V_2 -> V_60 . V_4 = V_2 -> V_60 . V_52 ;
V_2 -> V_60 . V_82 = 0 ;
if ( V_102 -> V_82 )
V_2 -> V_60 . V_82 = F_43 ( V_102 , V_2 -> V_60 . V_4 ,
V_2 -> V_60 . V_55 ) ;
F_30 ( V_2 , V_70 ) ;
F_44 ( V_102 ) ;
return 0 ;
}
static int F_45 ( struct V_103 * V_16 , struct V_105 * V_105 , int V_106 )
{
return 0 ;
}
static struct V_107 * F_46 ( struct V_103 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
return & V_2 -> V_16 -> V_92 ;
}
static int F_47 ( struct V_103 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
int V_63 ;
F_48 ( V_2 -> V_21 ) ;
V_63 = F_10 ( V_2 ) ;
if ( V_63 )
goto V_108;
F_17 ( V_2 , 9600 ) ;
V_2 -> V_109 = F_49 ( V_16 , & V_2 -> V_110 , V_111 ) ;
if ( ! V_2 -> V_109 ) {
V_63 = - V_112 ;
goto V_108;
}
F_5 ( V_2 , V_96 , V_113 , V_113 ) ;
F_3 ( V_2 , V_85 ) ;
F_3 ( V_2 , V_91 ) ;
F_30 ( V_2 , V_76 ) ;
F_50 ( V_16 ) ;
F_51 ( & V_2 -> V_16 -> V_15 , L_19 ) ;
return 0 ;
V_108:
F_52 ( V_2 -> V_21 ) ;
return V_63 ;
}
static int F_53 ( struct V_103 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
if ( V_2 -> V_109 ) {
F_54 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
}
F_42 ( V_16 ) ;
F_51 ( & V_16 -> V_15 , L_20 ) ;
return 0 ;
}
static int F_55 ( struct V_114 * V_115 )
{
struct V_103 * V_16 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
char V_118 [ 8 ] ;
int V_97 ;
int V_63 = - V_54 ;
V_117 = F_56 ( V_115 , V_119 , 0 ) ;
V_97 = F_57 ( V_115 , 0 ) ;
if ( ! V_117 || V_97 < 0 ) {
F_11 ( & V_115 -> V_15 , L_21 ) ;
goto exit;
}
V_16 = F_58 ( sizeof( * V_2 ) ) ;
if ( ! V_16 )
goto exit;
V_2 = F_40 ( V_16 ) ;
V_2 -> V_5 = F_59 ( V_117 -> V_120 , F_60 ( V_117 ) ) ;
if ( ! V_2 -> V_5 ) {
V_63 = - V_121 ;
F_11 ( & V_115 -> V_15 , L_22 ) ;
goto V_122;
}
V_63 = F_28 ( V_2 , V_123 , V_124 ) ;
if ( V_63 )
goto V_125;
snprintf ( V_118 , sizeof( V_118 ) , L_23 , V_115 -> V_126 ) ;
V_2 -> V_21 = F_13 ( & V_115 -> V_15 , V_118 ) ;
if ( F_18 ( V_2 -> V_21 ) ) {
F_11 ( & V_115 -> V_15 , L_24 , V_118 ) ;
V_63 = - V_112 ;
goto V_127;
}
F_61 ( & V_2 -> V_110 ) ;
V_16 -> V_128 = & V_129 ;
V_16 -> V_97 = V_97 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_110 . V_130 . V_131 &= V_132 ;
V_2 -> V_110 . V_133 . V_131 = 1 ;
F_62 ( & V_2 -> V_110 ) ;
V_63 = F_63 ( V_16 ) ;
if ( V_63 )
goto V_134;
F_64 ( V_115 , V_16 ) ;
V_63 = F_65 ( & V_115 -> V_15 , V_97 , F_38 , 0 , L_25 , V_2 ) ;
if ( V_63 ) {
F_23 ( & V_115 -> V_15 , L_26 ) ;
goto V_134;
}
F_51 ( & V_115 -> V_15 , L_27 ) ;
goto exit;
V_134:
F_15 ( V_2 -> V_21 ) ;
V_127:
F_26 ( V_2 ) ;
V_125:
F_66 ( V_2 -> V_5 ) ;
V_122:
F_67 ( V_16 ) ;
exit:
return V_63 ;
}
static int F_68 ( struct V_114 * V_115 )
{
struct V_103 * V_16 = F_69 ( V_115 ) ;
struct V_1 * V_2 = F_40 ( V_16 ) ;
if ( ! V_2 )
return 0 ;
F_70 ( V_16 ) ;
F_15 ( V_2 -> V_21 ) ;
F_26 ( V_2 ) ;
F_66 ( V_2 -> V_5 ) ;
F_67 ( V_16 ) ;
return 0 ;
}
