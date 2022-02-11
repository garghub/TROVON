static int F_1 ( struct V_1 * V_2 ,
int V_3 , int * V_4 )
{
unsigned char V_5 [ 2 ] ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_3 , 2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_4 = ( ( V_5 [ 0 ] & 0xff ) << 4 ) | ( V_5 [ 1 ] & 0x0f ) ;
* V_4 = ( ( * V_4 & 0xfff ) * 9 * 25 ) >> 9 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_8 ,
int * V_4 )
{
unsigned char V_5 [ 5 ] ;
int V_6 ;
switch ( V_8 ) {
case V_9 :
V_6 = F_1 ( V_2 , V_10 , V_4 ) ;
if ( V_6 )
return V_6 ;
* V_4 *= 3 ;
break;
case V_11 :
V_6 = F_2 ( V_2 -> V_7 , V_12 , 5 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = ( ( V_5 [ 4 ] >> 6 ) << 10 ) | ( ( V_5 [ 3 ] >> 6 ) << 8 )
| ( ( V_5 [ 2 ] >> 6 ) << 6 ) | ( ( V_5 [ 1 ] >> 6 ) << 4 )
| ( V_5 [ 0 ] >> 4 ) ;
* V_4 = ( ( * V_4 & 0xff ) * 27 * 25 ) >> 9 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int * V_4 )
{
unsigned char V_5 [ 2 ] ;
short V_14 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_15 , 2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_14 = ( ( V_5 [ 0 ] & 0xff ) << 8 ) | ( V_5 [ 1 ] & 0xff ) ;
* V_4 = V_14 >> 3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_4 ,
int * V_16 )
{
int V_6 ;
if ( V_4 < 50 || V_4 > 1600 || ! V_16 )
return - V_13 ;
V_4 = ( ( V_4 - 50 ) / 50 ) & 0x1f ;
* V_16 = F_6 ( V_2 -> V_7 , V_17 ) ;
* V_16 = ( * V_16 & 0x1f ) * 50 + 50 ;
V_6 = F_7 ( V_2 -> V_7 , V_17 , 0x1f , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 ,
int * V_18 )
{
unsigned char V_5 [ 2 ] ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_7 , V_19 , 7 , V_3 & 7 ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_2 ( V_2 -> V_7 , V_21 , 2 , V_5 ) ;
if ( V_6 < 0 )
goto V_20;
* V_18 = ( ( V_5 [ 0 ] & 0xff ) << 8 ) | ( V_5 [ 1 ] & 0xff ) ;
return 0 ;
V_20:
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned int V_22 ;
int V_6 ;
int V_4 ;
V_6 = F_8 ( V_2 , V_23 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_22 = V_4 & 0xffff ;
V_6 = F_8 ( V_2 , V_24 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_22 |= ( V_4 & 0xffff ) << 16 ;
V_18 -> V_25 += V_22 ;
V_6 = F_8 ( V_2 , V_26 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_22 = V_4 & 0xffff ;
V_6 = F_8 ( V_2 , V_27 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_22 |= ( V_4 & 0xffff ) << 16 ;
V_22 = ~ V_22 + 1 ;
V_18 -> V_28 += V_22 ;
V_6 = F_8 ( V_2 , V_29 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_18 -> V_30 += V_4 ;
V_6 = F_8 ( V_2 , V_31 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_18 -> V_32 = ( int ) ( ( V_18 -> V_25 * 18236 ) >> 40 ) ;
V_18 -> V_33 = ( int ) ( ( V_18 -> V_28 * 18236 ) >> 40 ) ;
return 0 ;
V_20:
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
int V_4 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
F_8 ( V_2 , V_23 , & V_4 ) ;
F_8 ( V_2 , V_24 , & V_4 ) ;
F_8 ( V_2 , V_26 , & V_4 ) ;
F_8 ( V_2 , V_27 , & V_4 ) ;
F_8 ( V_2 , V_29 , & V_4 ) ;
F_8 ( V_2 , V_31 , & V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_34 )
{
int V_6 ;
int V_35 ;
int V_4 ;
int V_36 ;
int V_37 ;
int V_38 ;
int V_39 ;
if ( ! V_34 )
return - V_13 ;
for ( V_35 = 0 , V_39 = 0 , V_37 = 0 ; V_35 < 10 ; V_35 ++ ) {
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_37 += V_4 ;
V_6 = F_4 ( V_2 , & V_4 ) ;
if ( V_6 )
goto V_20;
V_39 += V_4 ;
}
V_36 = V_37 / 10 ;
V_38 = V_39 / 10 ;
F_12 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_41 )
* V_34 = V_36 - V_38 * V_2 -> V_42 / 1000 ;
else
* V_34 = V_36 ;
F_13 ( & V_2 -> V_40 ) ;
F_14 ( V_2 -> V_43 , L_1 , V_36 , * V_34 ) ;
return 0 ;
V_20:
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , int V_8 , int * V_44 )
{
int V_35 ;
int V_34 ;
int V_45 ;
int V_6 = - V_13 ;
if ( ! V_44 )
return - V_13 ;
switch ( V_8 ) {
case V_9 :
V_6 = F_11 ( V_2 , & V_34 ) ;
break;
case V_11 :
V_6 = F_3 ( V_2 , V_11 , & V_34 ) ;
break;
}
if ( V_6 )
return V_6 ;
V_45 = F_16 ( V_46 ) ;
if ( V_34 < V_46 [ V_45 - 1 ] [ 0 ] ) {
* V_44 = 0 ;
return 0 ;
}
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ ) {
if ( V_34 >= V_46 [ V_35 ] [ 0 ] ) {
* V_44 = V_46 [ V_35 ] [ 1 ] ;
break;
}
}
return 0 ;
}
static T_1 F_17 ( int V_47 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_9 ( V_2 , & V_48 ) ;
return V_49 ;
}
static T_1 F_18 ( int V_47 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
int V_6 ;
F_12 ( & V_2 -> V_40 ) ;
V_6 = F_6 ( V_2 -> V_7 , V_50 ) ;
if ( V_6 & V_51 ) {
V_2 -> V_41 = 1 ;
V_2 -> V_52 = V_53 ;
} else {
V_2 -> V_41 = 0 ;
V_2 -> V_52 = V_54 ;
}
F_13 ( & V_2 -> V_40 ) ;
F_10 ( V_2 , & V_48 ) ;
return V_49 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned char V_5 [ 2 ] ;
int V_6 ;
int V_4 ;
int V_55 ;
int V_44 ;
V_4 = V_56 ;
if ( V_2 -> V_52 == V_54 )
V_4 |= V_57 ;
V_6 = F_7 ( V_2 -> V_7 , V_58 , V_4 , V_4 ) ;
if ( V_6 )
goto V_20;
V_4 = V_59 | V_60 | V_61 ;
V_6 = F_7 ( V_2 -> V_7 , V_62 , V_4 , V_4 ) ;
if ( V_6 )
goto V_20;
V_6 = F_20 ( V_2 -> V_7 , V_63 , 0x82 ) ;
if ( V_6 )
goto V_20;
V_6 = F_20 ( V_2 -> V_7 , V_64 , 0x6c ) ;
if ( V_6 )
goto V_20;
V_6 = F_7 ( V_2 -> V_7 , V_65 ,
V_66 , V_66 ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_7 ( V_2 -> V_7 , V_67 ,
V_68 , V_68 ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_7 ( V_2 -> V_7 , V_19 , 7 << 3 ,
V_69 ) ;
if ( V_6 < 0 )
goto V_20;
V_6 = F_7 ( V_2 -> V_7 , V_70 , 0xF << 4 ,
V_71 ) ;
if ( V_6 < 0 )
goto V_20;
F_12 ( & V_2 -> V_40 ) ;
V_6 = F_6 ( V_2 -> V_7 , V_50 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_2 -> V_40 ) ;
goto V_20;
}
if ( V_6 & V_51 ) {
V_2 -> V_41 = 1 ;
V_2 -> V_52 = V_53 ;
} else {
V_2 -> V_41 = 0 ;
V_2 -> V_52 = V_54 ;
}
F_13 ( & V_2 -> V_40 ) ;
F_15 ( V_2 , V_9 , & V_44 ) ;
V_4 = F_6 ( V_2 -> V_7 , V_72 ) ;
V_55 = V_4 & V_73 ;
F_14 ( V_2 -> V_43 , L_2 ,
V_55 != 0 ? L_3 : L_4 ) ;
if ( V_55 == 0 ) {
V_5 [ 0 ] = F_6 ( V_2 -> V_7 , V_74 ) ;
V_5 [ 1 ] = F_6 ( V_2 -> V_7 , V_75 ) ;
V_4 = ( ( V_5 [ 1 ] & 0x3 ) << 5 ) | ( ( V_5 [ 0 ] >> 3 ) & 0x1F ) ;
if ( V_4 > V_44 + 15 )
V_2 -> V_76 = V_44 ;
else if ( V_4 < V_44 - 15 )
V_2 -> V_76 = V_44 ;
else
V_2 -> V_76 = V_4 ;
F_14 ( V_2 -> V_43 , L_5 , V_4 , V_44 ) ;
} else {
F_7 ( V_2 -> V_7 , V_72 ,
V_73 , V_73 ) ;
V_2 -> V_76 = V_44 ;
}
V_2 -> V_77 = V_2 -> V_76 ;
F_14 ( V_2 -> V_43 , L_6 , V_2 -> V_77 ) ;
V_20:
return;
}
static void F_21 ( struct V_1 * V_2 ,
int V_78 , int V_79 )
{
int V_4 ;
if ( V_78 <= 0 )
V_4 = 0 ;
else
V_4 = ( V_78 << 8 ) / 1800 ;
F_20 ( V_2 -> V_7 , V_80 , V_4 ) ;
F_14 ( V_2 -> V_43 , L_7 , V_78 , V_4 ) ;
if ( V_79 <= 0 )
V_4 = 0xff ;
else
V_4 = ( V_79 << 8 ) / 1800 ;
F_20 ( V_2 -> V_7 , V_81 , V_4 ) ;
F_14 ( V_2 -> V_43 , L_8 , V_79 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 , int * V_4 )
{
int V_6 ;
int V_82 ;
int V_78 ;
int V_79 ;
if ( V_2 -> V_52 == V_54 ) {
V_6 = F_1 ( V_2 , V_83 , V_4 ) ;
if ( V_6 )
return V_6 ;
* V_4 = ( * V_4 - 884 ) * 1000 / 3611 ;
} else {
V_6 = F_1 ( V_2 , V_84 , V_4 ) ;
if ( V_6 )
return V_6 ;
* V_4 = ( * V_4 * 1000 ) / V_85 ;
if ( * V_4 > V_86 ) {
V_82 = - 30 ;
V_79 = V_87 * V_85 / 1000 ;
F_21 ( V_2 , 0 , V_79 ) ;
} else if ( * V_4 > V_87 ) {
V_82 = - 15 ;
V_79 = V_87 * V_85 / 1000 ;
F_21 ( V_2 , 0 , V_79 ) ;
} else if ( * V_4 > V_88 ) {
V_82 = - 5 ;
V_78 = V_87 * V_85 / 1000 ;
V_79 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , V_79 ) ;
} else if ( * V_4 > V_90 ) {
V_82 = 5 ;
V_78 = V_87 * V_85 / 1000 ;
V_79 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , V_79 ) ;
} else if ( * V_4 > V_91 ) {
V_82 = 15 ;
V_78 = V_87 * V_85 / 1000 ;
V_79 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , V_79 ) ;
} else if ( * V_4 > V_92 ) {
V_82 = 25 ;
V_78 = V_87 * V_85 / 1000 ;
V_79 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , V_79 ) ;
} else if ( * V_4 > V_89 ) {
V_82 = 35 ;
V_78 = V_87 * V_85 / 1000 ;
V_79 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , V_79 ) ;
} else {
V_78 = V_89 * V_85 / 1000 ;
F_21 ( V_2 , V_78 , 0 ) ;
V_82 = 45 ;
}
F_14 ( V_2 -> V_43 , L_9 , V_82 , * V_4 ) ;
* V_4 = V_82 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_93 ;
int V_94 ;
int V_95 ;
int V_96 ;
int V_97 ;
int V_4 ;
int V_6 ;
int V_35 ;
V_6 = F_4 ( V_2 , & V_4 ) ;
if ( V_6 || V_4 < 0 )
goto V_20;
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
goto V_20;
if ( V_4 < V_98 || V_4 > V_99 )
goto V_20;
if ( F_5 ( V_2 , 500 , & V_95 ) )
goto V_20;
F_24 ( 500 ) ;
for ( V_35 = 0 , V_93 = 0 , V_96 = 0 ; V_35 < 10 ; V_35 ++ ) {
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
goto V_100;
V_93 += V_4 ;
V_6 = F_4 ( V_2 , & V_4 ) ;
if ( V_6 )
goto V_100;
if ( V_4 < 0 )
V_96 = V_96 - V_4 ;
else
V_96 = V_96 + V_4 ;
}
if ( F_5 ( V_2 , 100 , & V_6 ) )
goto V_100;
F_24 ( 500 ) ;
for ( V_35 = 0 , V_94 = 0 , V_97 = 0 ; V_35 < 10 ; V_35 ++ ) {
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
goto V_100;
V_94 += V_4 ;
V_6 = F_4 ( V_2 , & V_4 ) ;
if ( V_6 )
goto V_100;
if ( V_4 < 0 )
V_97 = V_97 - V_4 ;
else
V_97 = V_97 + V_4 ;
}
if ( F_5 ( V_2 , V_95 , & V_6 ) )
goto V_100;
if ( ( V_93 > V_94 ) && ( V_96 > V_97 ) &&
( V_97 > 0 ) ) {
V_4 = 1000 * ( V_93 - V_94 )
/ ( V_96 - V_97 ) ;
if ( ( V_4 - V_2 -> V_42 > 0 ) &&
( V_4 - V_2 -> V_42 < V_2 -> V_42 ) )
V_2 -> V_42 = V_4 ;
if ( ( V_2 -> V_42 - V_4 > 0 ) &&
( V_2 -> V_42 - V_4 < V_4 ) )
V_2 -> V_42 = V_4 ;
}
return 0 ;
V_100:
F_5 ( V_2 , V_95 , & V_6 ) ;
V_20:
return - V_13 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_101 )
{
int V_6 ;
int V_4 ;
int V_102 ;
int V_103 = 0 ;
int V_104 = 0 ;
V_6 = F_9 ( V_2 , & V_48 ) ;
if ( V_6 )
goto V_20;
V_44:
V_4 = V_2 -> V_105 * V_2 -> V_76 / 100 ;
if ( V_48 . V_33 - V_48 . V_32 <= V_4 ) {
V_104 =
V_4 + V_48 . V_32 - V_48 . V_33 ;
} else {
F_10 ( V_2 , & V_48 ) ;
F_15 ( V_2 , V_9 , & V_2 -> V_76 ) ;
F_14 ( V_2 -> V_43 , L_10 ,
V_2 -> V_76 ) ;
goto V_44;
}
V_104 = V_104 * 100 / V_2 -> V_105 ;
if ( V_104 < 0 )
V_104 = 0 ;
else if ( V_104 > 100 )
V_104 = 100 ;
F_14 ( V_2 -> V_43 , L_11 , V_106 ,
V_2 -> V_77 ) ;
V_6 = F_4 ( V_2 , & V_102 ) ;
if ( V_6 )
goto V_20;
if ( V_102 < 0 ) {
V_6 = F_15 ( V_2 , V_9 , & V_103 ) ;
if ( V_6 )
V_103 = V_2 -> V_77 ;
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
goto V_20;
if ( V_4 <= V_107 ) {
* V_101 = V_78 ( V_103 , V_104 ) ;
} else {
if ( V_104 < 15 && V_103 - V_104 > 10 )
* V_101 = V_103 ;
else
* V_101 = V_104 ;
}
if ( * V_101 > V_2 -> V_77 )
* V_101 = V_2 -> V_77 ;
} else {
* V_101 = V_104 ;
}
V_2 -> V_77 = * V_101 ;
F_14 ( V_2 -> V_43 , L_12 ,
( V_102 < 0 ) ? L_13 : L_14 ,
V_103 , V_104 , * V_101 ) ;
F_7 ( V_2 -> V_7 , V_74 , V_108 ,
( * V_101 & 0x1F ) << 3 ) ;
F_7 ( V_2 -> V_7 , V_75 , V_109 ,
( ( * V_101 >> 5 ) & 0x3 ) ) ;
return 0 ;
V_20:
return V_6 ;
}
static void F_26 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_27 ( V_111 -> V_43 . V_112 ) ;
F_23 ( V_2 ) ;
}
static int F_28 ( struct V_110 * V_111 ,
enum V_113 V_114 ,
union V_115 * V_116 )
{
struct V_1 * V_2 = F_27 ( V_111 -> V_43 . V_112 ) ;
int V_4 ;
int V_6 ;
switch ( V_114 ) {
case V_117 :
V_116 -> V_118 = V_2 -> V_41 ;
break;
case V_119 :
V_6 = F_25 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 < 0 )
V_4 = 0 ;
else if ( V_4 > 100 )
V_4 = 100 ;
if ( ! V_2 -> V_41 )
V_4 = 100 ;
V_116 -> V_118 = V_4 ;
break;
case V_120 :
V_116 -> V_118 = V_121 ;
break;
case V_122 :
V_6 = F_3 ( V_2 , V_9 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_116 -> V_118 = V_4 * 1000 ;
break;
case V_123 :
V_6 = F_11 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_116 -> V_118 = V_4 * 1000 ;
break;
case V_124 :
V_6 = F_4 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_116 -> V_118 = V_4 ;
break;
case V_125 :
if ( V_2 -> V_41 ) {
V_6 = F_22 ( V_2 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_4 *= 10 ;
} else {
V_4 = 250 ;
}
V_116 -> V_118 = V_4 ;
break;
default:
return - V_126 ;
}
return 0 ;
}
static int F_29 ( struct V_110 * V_111 ,
enum V_113 V_114 ,
const union V_115 * V_116 )
{
struct V_1 * V_2 = F_27 ( V_111 -> V_43 . V_112 ) ;
switch ( V_114 ) {
case V_127 :
F_10 ( V_2 , & V_48 ) ;
V_2 -> V_76 = 100 ;
F_14 ( V_2 -> V_43 , L_15 ,
V_2 -> V_76 ) ;
break;
default:
return - V_128 ;
}
return 0 ;
}
static int F_30 ( struct V_129 * V_130 )
{
struct V_131 * V_132 = F_27 ( V_130 -> V_43 . V_112 ) ;
struct V_1 * V_2 ;
struct V_133 * V_134 ;
int V_6 ;
V_2 = F_31 ( & V_130 -> V_43 , sizeof( * V_2 ) , V_135 ) ;
if ( ! V_2 )
return - V_136 ;
V_2 -> V_137 = F_32 ( V_130 , 0 ) ;
if ( V_2 -> V_137 <= 0 ) {
F_33 ( & V_130 -> V_43 , L_16 ) ;
return - V_13 ;
}
V_2 -> V_138 = F_32 ( V_130 , 1 ) ;
if ( V_2 -> V_138 <= 0 ) {
F_33 ( & V_130 -> V_43 , L_16 ) ;
return - V_13 ;
}
V_2 -> V_132 = V_132 ;
V_2 -> V_7 =
( V_132 -> V_139 == V_140 ) ? V_132 -> V_141 : V_132 -> V_142 ;
V_2 -> V_43 = & V_130 -> V_43 ;
V_2 -> V_143 = V_144 ;
V_134 = V_130 -> V_43 . V_145 ;
F_34 ( & V_2 -> V_40 ) ;
F_35 ( V_130 , V_2 ) ;
F_19 ( V_2 ) ;
if ( V_134 && V_134 -> V_105 )
V_2 -> V_105 = V_134 -> V_105 ;
else
V_2 -> V_105 = 1500 ;
if ( V_134 && V_134 -> V_42 )
V_2 -> V_42 = V_134 -> V_42 ;
else
V_2 -> V_42 = 300 ;
V_2 -> V_146 = F_36 ( & V_130 -> V_43 , & V_147 ,
NULL ) ;
if ( F_37 ( V_2 -> V_146 ) )
return F_38 ( V_2 -> V_146 ) ;
V_2 -> V_146 -> V_43 . V_112 = & V_130 -> V_43 ;
V_6 = F_39 ( V_2 -> V_137 , NULL ,
F_17 , V_148 ,
L_17 , V_2 ) ;
if ( V_6 < 0 ) {
F_33 ( V_132 -> V_43 , L_18 ,
V_2 -> V_137 , V_6 ) ;
goto V_149;
}
V_6 = F_39 ( V_2 -> V_138 , NULL , F_18 ,
V_148 , L_19 , V_2 ) ;
if ( V_6 < 0 ) {
F_33 ( V_132 -> V_43 , L_18 ,
V_2 -> V_138 , V_6 ) ;
goto V_150;
}
return 0 ;
V_150:
F_40 ( V_2 -> V_137 , V_2 ) ;
V_149:
F_41 ( V_2 -> V_146 ) ;
return V_6 ;
}
static int F_42 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_43 ( V_130 ) ;
F_40 ( V_2 -> V_138 , V_2 ) ;
F_40 ( V_2 -> V_137 , V_2 ) ;
F_41 ( V_2 -> V_146 ) ;
return 0 ;
}
static int F_44 ( struct V_151 * V_43 )
{
struct V_129 * V_130 = F_45 ( V_43 ) ;
struct V_131 * V_132 = F_27 ( V_130 -> V_43 . V_112 ) ;
if ( F_46 ( V_43 ) )
V_132 -> V_152 |= 1 << V_153 ;
return 0 ;
}
static int F_47 ( struct V_151 * V_43 )
{
struct V_129 * V_130 = F_45 ( V_43 ) ;
struct V_131 * V_132 = F_27 ( V_130 -> V_43 . V_112 ) ;
if ( F_46 ( V_43 ) )
V_132 -> V_152 &= ~ ( 1 << V_153 ) ;
return 0 ;
}
