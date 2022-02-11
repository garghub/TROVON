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
struct V_21 * V_25 = F_13 ( NULL , L_3 ) ;
T_1 V_26 , V_27 = 0xffffffff , V_28 ;
int V_29 , V_30 = 0 ;
V_26 = F_14 ( V_25 ) ;
F_15 ( V_25 ) ;
for ( V_29 = 0 ;
V_24 [ V_29 ] . V_31 != V_32 ;
V_29 ++ ) {
T_1 V_33 = V_24 [ V_29 ] . V_31 ;
if ( V_33 == V_34 )
continue;
if ( V_33 > V_26 )
continue;
V_28 = V_33 % V_35 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_30 = V_29 ;
}
}
return V_24 [ V_30 ] . V_31 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_21 * V_21 ;
struct V_14 * V_15 = & V_2 -> V_16 -> V_15 ;
T_1 V_37 ;
T_2 V_38 , V_39 ;
T_2 V_40 , V_41 ;
T_1 V_27 , V_42 , V_28 ;
int V_29 ;
T_1 V_43 [] = {
0 , 625 , 1250 , 1875 ,
2500 , 3125 , 3750 , 4375 ,
5000 , 5625 , 6250 , 6875 ,
7500 , 8125 , 8750 , 9375 ,
} ;
switch ( V_36 ) {
case 9600 :
break;
default:
F_11 ( V_15 , L_4 , V_36 ) ;
return - V_18 ;
}
V_21 = F_13 ( NULL , L_5 ) ;
if ( ! V_21 ) {
F_11 ( V_15 , L_6 ) ;
return - V_18 ;
}
F_17 ( V_21 , F_12 ( V_21 ) ) ;
V_37 = F_14 ( V_21 ) ;
F_15 ( V_21 ) ;
F_18 ( V_15 , L_7 , V_37 ) ;
V_41 = V_37 / V_35 ;
V_28 = V_37 - ( V_35 * V_41 ) ;
V_28 *= 10000 ;
V_42 = V_28 / V_35 ;
V_27 = 0xffffffff ;
V_40 = 0 ;
for ( V_29 = 0 ; V_29 < F_19 ( V_43 ) ; V_29 ++ ) {
V_28 = abs ( V_43 [ V_29 ] - V_42 ) ;
if ( V_27 > V_28 ) {
V_27 = V_28 ;
V_40 = V_29 ;
}
}
V_28 = V_37 / ( V_41 + F_20 ( V_43 [ V_40 ] ) ) ;
if ( ( V_35 / 100 ) < abs ( V_28 - V_35 ) )
F_21 ( V_15 , L_8 , V_28 ) ;
F_18 ( V_15 , L_9 ,
V_35 , V_28 , V_41 , V_43 [ V_40 ] ) ;
V_40 = ( V_40 & 0xF ) << 4 ;
V_41 = ( V_41 - 1 ) & 0xF ;
if ( ! V_41 ) {
F_11 ( V_15 , L_10 ) ;
return - V_18 ;
}
F_1 ( V_2 , V_44 , V_45 | V_46 ) ;
F_1 ( V_2 , V_47 , V_40 ) ;
F_1 ( V_2 , V_48 , V_41 ) ;
V_39 = V_37 / V_36 ;
V_39 = ( V_39 / 16 ) - 1 ;
V_39 = ( V_39 + 1 ) * 16 ;
V_28 = V_37 - ( V_39 * V_36 ) ;
V_28 *= 10000 ;
V_42 = V_28 / V_36 ;
V_27 = 0xffffffff ;
V_38 = 0 ;
for ( V_29 = 0 ; V_29 < F_19 ( V_43 ) ; V_29 ++ ) {
V_28 = abs ( V_43 [ V_29 ] - V_42 ) ;
if ( V_27 > V_28 ) {
V_27 = V_28 ;
V_38 = V_29 ;
}
}
V_28 = V_37 / ( V_39 + F_20 ( V_43 [ V_38 ] ) ) ;
if ( ( V_36 / 100 ) < abs ( V_28 - V_36 ) )
F_21 ( V_15 , L_11 , V_28 ) ;
F_18 ( V_15 , L_12 ,
V_36 , V_28 ,
V_39 , V_43 [ V_38 ] ) ;
V_38 = ( V_38 & 0xF ) << 4 ;
V_39 = ( V_39 / 16 ) - 1 ;
F_1 ( V_2 , V_49 , V_38 ) ;
F_1 ( V_2 , V_50 , V_39 ) ;
return 0 ;
}
static int F_22 ( T_4 * V_51 , int V_52 )
{
V_51 -> V_53 = F_23 ( V_52 , V_54 ) ;
if ( ! V_51 -> V_53 )
return - V_55 ;
V_51 -> V_56 = V_52 ;
V_51 -> V_57 = FALSE ;
V_51 -> V_58 = V_59 ;
V_51 -> V_4 = V_51 -> V_53 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_60 . V_53 ) ;
F_25 ( V_2 -> V_61 . V_53 ) ;
V_2 -> V_60 . V_53 = NULL ;
V_2 -> V_61 . V_53 = NULL ;
}
static int F_26 ( struct V_1 * V_2 , int V_62 , int V_63 )
{
int V_64 = - V_55 ;
if ( V_2 -> V_60 . V_53 ||
V_2 -> V_61 . V_53 ) {
F_11 ( & V_2 -> V_16 -> V_15 , L_13 ) ;
return V_64 ;
}
V_64 = F_22 ( & V_2 -> V_60 , V_62 ) ;
if ( V_64 )
goto V_65;
V_64 = F_22 ( & V_2 -> V_61 , V_63 ) ;
V_65:
if ( V_64 )
F_24 ( V_2 ) ;
return V_64 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_44 , V_46 , V_46 ) ;
F_1 ( V_2 , V_66 , 0xffff ) ;
F_1 ( V_2 , V_67 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_68 )
{
T_2 V_69 = 0 ;
T_2 V_70 = 0 ;
switch ( V_68 ) {
case V_71 :
V_69 = V_72 ;
V_70 = V_73 | V_74 ;
break;
case V_75 :
V_69 = V_76 ;
V_70 = V_74 ;
break;
case V_77 :
V_69 = V_78 ;
V_70 = V_79 ;
break;
default:
break;
}
F_1 ( V_2 , V_80 , V_69 ) ;
F_1 ( V_2 , V_81 , V_70 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_19 = F_3 ( V_2 , V_80 ) ;
if ( V_19 & V_72 )
return V_71 ;
if ( V_19 & V_76 )
return V_75 ;
if ( V_19 & V_78 )
return V_77 ;
return V_82 ;
}
static void F_30 ( struct V_1 * V_2 , int V_68 )
{
switch ( V_68 ) {
case V_71 :
if ( 0 >= V_2 -> V_61 . V_83 ) {
F_28 ( V_2 , V_75 ) ;
} else {
F_1 ( V_2 , V_84 , V_2 -> V_61 . V_4 [ 0 ] ) ;
V_2 -> V_61 . V_83 -- ;
V_2 -> V_61 . V_4 ++ ;
}
break;
case V_75 :
F_28 ( V_2 , V_77 ) ;
F_31 ( V_2 -> V_16 ) ;
break;
default:
F_11 ( & V_2 -> V_16 -> V_15 , L_14 ) ;
break;
}
}
static int F_32 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
int V_85 = 1024 ;
while ( V_85 -- ) {
V_19 = F_3 ( V_2 , V_86 ) ;
if ( V_19 & V_87 ) {
if ( V_19 & ( V_88 | V_89 | V_90 | V_91 ) )
break;
return ( int ) F_3 ( V_2 , V_92 ) ;
}
F_33 ( 1 ) ;
}
F_11 ( & V_2 -> V_16 -> V_15 , L_15 ,
V_19 , F_3 ( V_2 , V_67 ) ) ;
F_3 ( V_2 , V_92 ) ;
return - 1 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_85 = 1024 ;
int V_4 ;
while ( V_85 -- ) {
V_4 = F_32 ( V_2 ) ;
if ( V_4 < 0 )
break;
F_35 ( V_2 -> V_16 , & V_2 -> V_16 -> V_93 ,
& V_2 -> V_60 , ( T_3 ) V_4 ) ;
V_2 -> V_16 -> V_94 = V_95 ;
if ( V_96 & F_3 ( V_2 , V_97 ) )
continue;
break;
}
}
static T_5 F_36 ( int V_98 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
struct V_14 * V_15 = & V_2 -> V_16 -> V_15 ;
int V_68 = F_29 ( V_2 ) ;
switch ( V_68 ) {
case V_75 :
case V_71 :
F_30 ( V_2 , V_68 ) ;
break;
case V_77 :
if ( F_3 ( V_2 , V_100 ) )
F_11 ( V_15 , L_16 ) ;
F_34 ( V_2 ) ;
F_27 ( V_2 ) ;
break;
default:
F_11 ( V_15 , L_17 ) ;
}
return V_101 ;
}
static int F_37 ( struct V_102 * V_103 , struct V_104 * V_16 )
{
struct V_1 * V_2 = F_38 ( V_16 ) ;
int V_105 = F_39 ( V_103 ) ;
if ( ( 0 < V_105 ) &&
( 9600 != V_105 ) ) {
F_11 ( & V_16 -> V_15 , L_18 , V_105 ) ;
return - V_18 ;
}
F_40 ( V_16 ) ;
V_2 -> V_61 . V_4 = V_2 -> V_61 . V_53 ;
V_2 -> V_61 . V_83 = 0 ;
if ( V_103 -> V_83 )
V_2 -> V_61 . V_83 = F_41 ( V_103 , V_2 -> V_61 . V_4 ,
V_2 -> V_61 . V_56 ) ;
F_28 ( V_2 , V_71 ) ;
F_42 ( V_103 ) ;
return 0 ;
}
static int F_43 ( struct V_104 * V_16 , struct V_106 * V_106 , int V_107 )
{
return 0 ;
}
static struct V_108 * F_44 ( struct V_104 * V_16 )
{
struct V_1 * V_2 = F_38 ( V_16 ) ;
return & V_2 -> V_16 -> V_93 ;
}
static int F_45 ( struct V_104 * V_16 )
{
struct V_1 * V_2 = F_38 ( V_16 ) ;
int V_64 ;
F_46 ( V_2 -> V_21 ) ;
V_64 = F_10 ( V_2 ) ;
if ( V_64 )
goto V_109;
F_16 ( V_2 , 9600 ) ;
V_2 -> V_110 = F_47 ( V_16 , & V_2 -> V_111 , V_112 ) ;
if ( ! V_2 -> V_110 ) {
V_64 = - V_113 ;
goto V_109;
}
F_5 ( V_2 , V_97 , V_114 , V_114 ) ;
F_3 ( V_2 , V_86 ) ;
F_3 ( V_2 , V_92 ) ;
F_28 ( V_2 , V_77 ) ;
F_48 ( V_16 ) ;
F_49 ( & V_2 -> V_16 -> V_15 , L_19 ) ;
return 0 ;
V_109:
F_50 ( V_2 -> V_21 ) ;
return V_64 ;
}
static int F_51 ( struct V_104 * V_16 )
{
struct V_1 * V_2 = F_38 ( V_16 ) ;
if ( V_2 -> V_110 ) {
F_52 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
}
F_40 ( V_16 ) ;
F_49 ( & V_16 -> V_15 , L_20 ) ;
return 0 ;
}
static int T_6 F_53 ( struct V_115 * V_116 )
{
struct V_104 * V_16 ;
struct V_1 * V_2 ;
struct V_117 * V_118 ;
char V_119 [ 8 ] ;
int V_98 ;
int V_64 = - V_55 ;
V_118 = F_54 ( V_116 , V_120 , 0 ) ;
V_98 = F_55 ( V_116 , 0 ) ;
if ( ! V_118 || V_98 < 0 ) {
F_11 ( & V_116 -> V_15 , L_21 ) ;
goto exit;
}
V_16 = F_56 ( sizeof( * V_2 ) ) ;
if ( ! V_16 )
goto exit;
V_2 = F_38 ( V_16 ) ;
V_2 -> V_5 = F_57 ( V_118 -> V_121 , F_58 ( V_118 ) ) ;
if ( ! V_2 -> V_5 ) {
V_64 = - V_122 ;
F_11 ( & V_116 -> V_15 , L_22 ) ;
goto V_123;
}
V_64 = F_26 ( V_2 , V_124 , V_125 ) ;
if ( V_64 )
goto V_126;
snprintf ( V_119 , sizeof( V_119 ) , L_23 , V_116 -> V_127 ) ;
V_2 -> V_21 = F_13 ( & V_116 -> V_15 , V_119 ) ;
if ( F_59 ( V_2 -> V_21 ) ) {
F_11 ( & V_116 -> V_15 , L_24 , V_119 ) ;
goto V_128;
}
F_60 ( & V_2 -> V_111 ) ;
V_16 -> V_129 = & V_130 ;
V_16 -> V_98 = V_98 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_111 . V_131 . V_132 &= V_133 ;
V_2 -> V_111 . V_134 . V_132 = 1 ;
F_61 ( & V_2 -> V_111 ) ;
V_64 = F_62 ( V_16 ) ;
if ( V_64 )
goto V_135;
F_63 ( V_116 , V_16 ) ;
if ( F_64 ( V_98 , F_36 , V_136 , L_25 , V_2 ) ) {
F_21 ( & V_116 -> V_15 , L_26 ) ;
goto V_135;
}
F_49 ( & V_116 -> V_15 , L_27 ) ;
goto exit;
V_135:
F_15 ( V_2 -> V_21 ) ;
V_128:
F_24 ( V_2 ) ;
V_126:
F_65 ( V_2 -> V_5 ) ;
V_123:
F_66 ( V_16 ) ;
exit:
return V_64 ;
}
static int T_7 F_67 ( struct V_115 * V_116 )
{
struct V_104 * V_16 = F_68 ( V_116 ) ;
struct V_1 * V_2 = F_38 ( V_16 ) ;
if ( ! V_2 )
return 0 ;
F_69 ( V_16 ) ;
F_15 ( V_2 -> V_21 ) ;
F_24 ( V_2 ) ;
F_65 ( V_2 -> V_5 ) ;
F_66 ( V_16 ) ;
F_63 ( V_116 , NULL ) ;
return 0 ;
}
