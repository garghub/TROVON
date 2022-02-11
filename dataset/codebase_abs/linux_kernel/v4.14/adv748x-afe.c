static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 ,
V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 , T_2 * signal ,
T_3 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_10 ;
V_10 = F_1 ( V_2 , V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( signal )
* signal = V_10 & V_12 ?
0 : V_13 ;
if ( ! V_9 )
return 0 ;
if ( ! ( V_10 & V_12 ) ) {
* V_9 = V_14 ;
return 0 ;
}
switch ( V_10 & 0x70 ) {
case 0x00 :
* V_9 = V_15 ;
break;
case 0x10 :
* V_9 = V_16 ;
break;
case 0x20 :
* V_9 = V_17 ;
break;
case 0x30 :
* V_9 = V_18 ;
break;
case 0x40 :
* V_9 = V_19 ;
break;
case 0x50 :
* V_9 = V_20 ;
break;
case 0x60 :
* V_9 = V_21 | V_22 ;
break;
case 0x70 :
* V_9 = V_20 ;
break;
default:
* V_9 = V_14 ;
break;
}
return 0 ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_23 * V_24 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_25 = V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_30 ;
V_24 -> V_31 = 720 ;
V_24 -> V_32 = V_8 -> V_33 & V_34 ? 480 : 576 ;
V_24 -> V_32 /= 2 ;
}
static int F_7 ( T_3 V_9 )
{
if ( V_9 == V_18 )
return V_35 ;
if ( V_9 == V_16 )
return V_36 ;
if ( V_9 == V_22 )
return V_37 ;
if ( V_9 == V_17 )
return V_38 ;
if ( V_9 == V_21 )
return V_39 ;
if ( V_9 & V_15 )
return V_40 ;
if ( V_9 & V_19 )
return V_41 ;
if ( V_9 & V_20 )
return V_42 ;
return - V_43 ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_44 )
{
F_9 ( V_2 , V_45 , V_46 ,
( V_44 & 0xf ) << V_47 ) ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_48 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
return F_2 ( V_2 , V_49 , V_48 ) ;
}
static int F_11 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
if ( V_8 -> V_33 & V_34 ) {
V_53 -> V_54 = 11 ;
V_53 -> V_55 = 10 ;
} else {
V_53 -> V_54 = 54 ;
V_53 -> V_55 = 59 ;
}
return 0 ;
}
static int F_13 ( struct V_50 * V_51 , T_3 * V_56 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
* V_56 = V_8 -> V_33 ;
return 0 ;
}
static int F_14 ( struct V_50 * V_51 , T_3 V_9 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_57 = F_7 ( V_9 ) ;
if ( V_57 < 0 )
return V_57 ;
F_15 ( & V_2 -> V_58 ) ;
F_8 ( V_2 , V_57 ) ;
V_8 -> V_33 = V_9 ;
F_16 ( & V_2 -> V_58 ) ;
return 0 ;
}
static int F_17 ( struct V_50 * V_51 , T_3 * V_9 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_4 ;
F_15 ( & V_2 -> V_58 ) ;
if ( V_8 -> V_59 ) {
V_4 = - V_60 ;
goto V_61;
}
F_8 ( V_2 ,
V_62 ) ;
F_18 ( 100 ) ;
V_4 = F_4 ( V_8 , NULL , V_9 ) ;
F_8 ( V_2 , V_8 -> V_33 ) ;
V_61:
F_16 ( & V_2 -> V_58 ) ;
return V_4 ;
}
static int F_19 ( struct V_50 * V_51 , T_3 * V_56 )
{
* V_56 = V_63 ;
return 0 ;
}
static int F_20 ( struct V_50 * V_51 , T_2 * V_64 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_4 ;
F_15 ( & V_2 -> V_58 ) ;
V_4 = F_4 ( V_8 , V_64 , NULL ) ;
F_16 ( & V_2 -> V_58 ) ;
return V_4 ;
}
static int F_21 ( struct V_50 * V_51 , int V_65 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_4 , signal = V_13 ;
F_15 ( & V_2 -> V_58 ) ;
if ( V_65 ) {
V_4 = F_10 ( V_8 , V_8 -> V_48 ) ;
if ( V_4 )
goto V_61;
}
V_4 = F_22 ( V_2 , V_65 ) ;
if ( V_4 )
goto V_61;
V_8 -> V_59 = V_65 ;
F_4 ( V_8 , & signal , NULL ) ;
if ( signal != V_13 )
F_23 ( V_2 , L_1 ) ;
else
F_23 ( V_2 , L_2 ) ;
V_61:
F_16 ( & V_2 -> V_58 ) ;
return V_4 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_50 * V_66 ;
unsigned int V_31 , V_32 , V_67 ;
V_66 = F_25 ( & V_8 -> V_68 [ V_69 ] ) ;
if ( ! V_66 )
return - V_70 ;
V_31 = 720 ;
V_32 = V_8 -> V_33 & V_34 ? 480 : 576 ;
V_67 = V_8 -> V_33 & V_34 ? 30 : 25 ;
return F_26 ( V_66 , V_31 * V_32 * V_67 ) ;
}
static int F_27 ( struct V_50 * V_51 ,
struct V_71 * V_72 ,
struct V_73 * V_25 )
{
if ( V_25 -> V_74 != 0 )
return - V_43 ;
V_25 -> V_25 = V_26 ;
return 0 ;
}
static int F_28 ( struct V_50 * V_51 ,
struct V_71 * V_72 ,
struct V_75 * V_76 )
{
struct V_7 * V_8 = F_12 ( V_51 ) ;
struct V_23 * V_77 ;
if ( V_76 -> V_78 != V_69 )
return - V_43 ;
if ( V_76 -> V_79 == V_80 ) {
V_77 = F_29 ( V_51 , V_72 , V_76 -> V_78 ) ;
V_76 -> V_81 = * V_77 ;
} else {
F_6 ( V_8 , & V_76 -> V_81 ) ;
F_24 ( V_8 ) ;
}
return 0 ;
}
static int F_30 ( struct V_50 * V_51 ,
struct V_71 * V_72 ,
struct V_75 * V_76 )
{
struct V_23 * V_77 ;
if ( V_76 -> V_78 != V_69 )
return - V_43 ;
if ( V_76 -> V_79 == V_82 )
return F_28 ( V_51 , V_72 , V_76 ) ;
V_77 = F_29 ( V_51 , V_72 , V_76 -> V_78 ) ;
* V_77 = V_76 -> V_81 ;
return 0 ;
}
static int F_31 ( struct V_83 * V_84 )
{
struct V_7 * V_8 = F_32 ( V_84 ) ;
struct V_1 * V_2 = F_5 ( V_8 ) ;
bool V_65 ;
int V_4 ;
V_4 = F_2 ( V_2 , 0x0e , 0x00 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_84 -> V_85 ) {
case V_86 :
V_4 = F_2 ( V_2 , V_87 , V_84 -> V_88 ) ;
break;
case V_89 :
V_4 = F_2 ( V_2 , V_90 , - V_84 -> V_88 ) ;
break;
case V_91 :
V_4 = F_2 ( V_2 , V_92 , V_84 -> V_88 ) ;
break;
case V_93 :
V_4 = F_2 ( V_2 , V_94 , V_84 -> V_88 ) ;
if ( V_4 )
break;
V_4 = F_2 ( V_2 , V_95 , V_84 -> V_88 ) ;
break;
case V_96 :
V_65 = ! ! V_84 -> V_88 ;
V_4 = F_9 ( V_2 , V_97 , V_98 ,
V_65 ) ;
if ( V_4 )
break;
V_4 = F_9 ( V_2 , V_99 , V_100 ,
V_65 ? V_84 -> V_88 - 1 : 0 ) ;
break;
default:
return - V_43 ;
}
return V_4 ;
}
static int F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
F_34 ( & V_8 -> V_101 , 5 ) ;
V_8 -> V_101 . V_102 = & V_2 -> V_58 ;
F_35 ( & V_8 -> V_101 , & V_103 ,
V_86 , V_104 ,
V_105 , 1 , V_106 ) ;
F_35 ( & V_8 -> V_101 , & V_103 ,
V_91 , V_107 ,
V_108 , 1 , V_109 ) ;
F_35 ( & V_8 -> V_101 , & V_103 ,
V_93 , V_110 ,
V_111 , 1 , V_112 ) ;
F_35 ( & V_8 -> V_101 , & V_103 ,
V_89 , V_113 ,
V_114 , 1 , V_115 ) ;
F_36 ( & V_8 -> V_101 , & V_103 ,
V_96 ,
F_37 ( V_116 ) - 1 ,
0 , 0 , V_116 ) ;
V_8 -> V_51 . V_117 = & V_8 -> V_101 ;
if ( V_8 -> V_101 . error ) {
F_38 ( & V_8 -> V_101 ) ;
return V_8 -> V_101 . error ;
}
return F_39 ( & V_8 -> V_101 ) ;
}
int F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
int V_4 ;
unsigned int V_118 ;
V_8 -> V_48 = 0 ;
V_8 -> V_59 = false ;
V_8 -> V_33 = V_119 ;
F_41 ( & V_8 -> V_51 , V_2 , & V_120 ,
V_121 , L_3 ) ;
for ( V_118 = V_122 ; V_118 <= V_123 ; V_118 ++ ) {
if ( V_2 -> V_124 [ V_118 ] ) {
V_8 -> V_48 = V_118 ;
break;
}
}
F_10 ( V_8 , V_8 -> V_48 ) ;
F_23 ( V_2 , L_4 , V_8 -> V_48 ) ;
for ( V_118 = V_125 ; V_118 <= V_126 ; V_118 ++ )
V_8 -> V_68 [ V_118 ] . V_127 = V_128 ;
V_8 -> V_68 [ V_69 ] . V_127 = V_129 ;
V_4 = F_42 ( & V_8 -> V_51 . V_130 , V_131 ,
V_8 -> V_68 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_33 ( V_8 ) ;
if ( V_4 )
goto error;
return 0 ;
error:
F_43 ( & V_8 -> V_51 . V_130 ) ;
return V_4 ;
}
void F_44 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_51 ) ;
F_43 ( & V_8 -> V_51 . V_130 ) ;
F_38 ( & V_8 -> V_101 ) ;
}
