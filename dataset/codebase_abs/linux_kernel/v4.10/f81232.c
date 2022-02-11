static int F_1 ( T_1 V_1 )
{
return F_2 ( V_2 , V_1 ) ;
}
static int F_3 ( struct V_3 * V_4 , T_2 V_5 , T_3 * V_6 )
{
int V_7 ;
T_3 * V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_10 ;
V_8 = F_4 ( sizeof( * V_6 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_7 = F_5 ( V_10 ,
F_6 ( V_10 , 0 ) ,
V_14 ,
V_15 ,
V_5 ,
0 ,
V_8 ,
sizeof( * V_6 ) ,
V_16 ) ;
if ( V_7 != sizeof( * V_6 ) ) {
F_7 ( & V_4 -> V_10 , L_1 , V_17 , V_7 ) ;
if ( V_7 < 0 )
V_7 = F_8 ( V_7 ) ;
else
V_7 = - V_18 ;
} else {
V_7 = 0 ;
* V_6 = * V_8 ;
}
F_9 ( V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_3 * V_4 , T_2 V_5 , T_3 V_6 )
{
int V_7 ;
T_3 * V_8 ;
struct V_9 * V_10 = V_4 -> V_11 -> V_10 ;
V_8 = F_4 ( sizeof( V_6 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
* V_8 = V_6 ;
V_7 = F_5 ( V_10 ,
F_11 ( V_10 , 0 ) ,
V_14 ,
V_19 ,
V_5 ,
0 ,
V_8 ,
sizeof( V_6 ) ,
V_20 ) ;
if ( V_7 != sizeof( V_6 ) ) {
F_7 ( & V_4 -> V_10 , L_1 , V_17 , V_7 ) ;
if ( V_7 < 0 )
V_7 = F_8 ( V_7 ) ;
else
V_7 = - V_18 ;
} else {
V_7 = 0 ;
}
F_9 ( V_8 ) ;
return V_7 ;
}
static void F_12 ( struct V_3 * V_4 )
{
int V_7 ;
T_3 V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = F_13 ( V_4 ) ;
F_14 ( & V_25 -> V_26 ) ;
V_7 = F_3 ( V_4 , V_27 ,
& V_21 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_2 , V_17 , V_7 ) ;
F_15 ( & V_25 -> V_26 ) ;
return;
}
if ( ! ( V_21 & V_28 ) ) {
F_15 ( & V_25 -> V_26 ) ;
return;
}
V_25 -> V_29 = V_21 ;
if ( V_21 & V_30 )
V_4 -> V_31 . V_32 ++ ;
if ( V_21 & V_33 )
V_4 -> V_31 . V_34 ++ ;
if ( V_21 & V_35 )
V_4 -> V_31 . V_36 ++ ;
if ( V_21 & V_37 ) {
V_4 -> V_31 . V_38 ++ ;
V_23 = F_16 ( & V_4 -> V_4 ) ;
if ( V_23 ) {
F_17 ( V_4 , V_23 ,
V_21 & V_39 ) ;
F_18 ( V_23 ) ;
}
}
F_19 ( & V_4 -> V_4 . V_40 ) ;
F_15 ( & V_25 -> V_26 ) ;
}
static int F_20 ( struct V_3 * V_4 ,
unsigned int V_41 , unsigned int V_42 )
{
T_3 V_6 ;
int V_7 ;
struct V_24 * V_25 = F_13 ( V_4 ) ;
if ( ( ( V_41 | V_42 ) & ( V_43 | V_44 ) ) == 0 )
return 0 ;
V_42 &= ~ V_41 ;
F_14 ( & V_25 -> V_26 ) ;
V_6 = V_45 | V_25 -> V_46 ;
if ( V_42 & V_43 )
V_6 &= ~ V_47 ;
if ( V_42 & V_44 )
V_6 &= ~ V_48 ;
if ( V_41 & V_43 )
V_6 |= V_47 ;
if ( V_41 & V_44 )
V_6 |= V_48 ;
F_21 ( & V_4 -> V_10 , L_3 , V_17 ,
V_6 , V_25 -> V_46 ) ;
V_7 = F_10 ( V_4 , V_49 , V_6 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_4 , V_17 ) ;
F_15 ( & V_25 -> V_26 ) ;
return V_7 ;
}
V_25 -> V_46 = V_6 ;
F_15 ( & V_25 -> V_26 ) ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 ,
unsigned char * V_50 ,
T_4 V_51 )
{
struct V_24 * V_25 = F_13 ( V_4 ) ;
if ( ! V_51 )
return;
switch ( V_50 [ 0 ] & 0x07 ) {
case 0x00 :
F_21 ( & V_4 -> V_10 , L_5 , V_50 [ 0 ] ) ;
F_23 ( & V_25 -> V_52 ) ;
break;
case 0x02 :
break;
case 0x04 :
break;
case 0x06 :
F_21 ( & V_4 -> V_10 , L_6 , V_50 [ 0 ] ) ;
break;
}
}
static void F_24 ( struct V_53 * V_53 )
{
struct V_3 * V_4 = V_53 -> V_54 ;
unsigned char * V_50 = V_53 -> V_55 ;
unsigned int V_51 = V_53 -> V_51 ;
int V_7 = V_53 -> V_7 ;
int V_56 ;
switch ( V_7 ) {
case 0 :
break;
case - V_57 :
case - V_58 :
case - V_59 :
F_21 ( & V_4 -> V_10 , L_7 ,
V_17 , V_7 ) ;
return;
default:
F_21 ( & V_4 -> V_10 , L_8 ,
V_17 , V_7 ) ;
goto exit;
}
F_25 ( & V_4 -> V_10 , V_17 ,
V_53 -> V_51 , V_53 -> V_55 ) ;
F_22 ( V_4 , V_50 , V_51 ) ;
exit:
V_56 = F_26 ( V_53 , V_60 ) ;
if ( V_56 )
F_7 ( & V_53 -> V_10 -> V_10 ,
L_9 ,
V_17 , V_56 ) ;
}
static void F_27 ( struct V_53 * V_53 )
{
struct V_3 * V_4 = V_53 -> V_54 ;
unsigned char * V_50 = V_53 -> V_55 ;
char V_61 ;
unsigned int V_62 ;
T_3 V_63 ;
if ( ( V_53 -> V_51 < 2 ) || ( V_53 -> V_51 % 2 ) )
return;
for ( V_62 = 0 ; V_62 < V_53 -> V_51 ; V_62 += 2 ) {
V_61 = V_64 ;
V_63 = V_50 [ V_62 ] ;
if ( V_63 & V_65 ) {
if ( V_63 & V_66 ) {
V_61 = V_67 ;
V_4 -> V_31 . V_68 ++ ;
F_28 ( V_4 ) ;
} else if ( V_63 & V_69 ) {
V_61 = V_70 ;
V_4 -> V_31 . V_71 ++ ;
} else if ( V_63 & V_72 ) {
V_61 = V_73 ;
V_4 -> V_31 . V_74 ++ ;
}
if ( V_63 & V_75 ) {
V_4 -> V_31 . V_76 ++ ;
F_29 ( & V_4 -> V_4 , 0 ,
V_77 ) ;
}
}
if ( V_4 -> V_4 . V_78 && V_4 -> V_79 ) {
if ( F_30 ( V_4 , V_50 [ V_62 + 1 ] ) )
continue;
}
F_29 ( & V_4 -> V_4 , V_50 [ V_62 + 1 ] , V_61 ) ;
}
F_31 ( & V_4 -> V_4 ) ;
}
static void F_32 ( struct V_22 * V_23 , int V_80 )
{
}
static void F_33 ( struct V_3 * V_4 , T_1 V_1 )
{
T_3 V_81 ;
int V_82 ;
int V_7 = 0 ;
V_82 = F_1 ( V_1 ) ;
V_7 = F_3 ( V_4 , V_83 ,
& V_81 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_10 ,
V_17 , V_7 ) ;
return;
}
V_7 = F_10 ( V_4 , V_83 ,
V_81 | V_84 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_11 ,
V_17 , V_7 ) ;
return;
}
V_7 = F_10 ( V_4 , V_85 ,
V_82 & 0x00ff ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_12 ,
V_17 , V_7 ) ;
goto V_86;
}
V_7 = F_10 ( V_4 , V_87 ,
( V_82 & 0xff00 ) >> 8 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_13 ,
V_17 , V_7 ) ;
}
V_86:
V_7 = F_10 ( V_4 , V_83 ,
V_81 & ~ V_84 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_11 ,
V_17 , V_7 ) ;
}
}
static int F_34 ( struct V_3 * V_4 )
{
T_3 V_6 ;
int V_7 ;
V_6 = V_88 | V_89 | V_90 |
V_91 ;
V_7 = F_10 ( V_4 , V_92 , V_6 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_14 ,
V_17 , V_7 ) ;
return V_7 ;
}
V_7 = F_10 ( V_4 , V_87 ,
V_93 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_15 ,
V_17 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
int V_7 ;
V_7 = F_10 ( V_4 , V_87 , 0 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_15 ,
V_17 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static void F_36 ( struct V_22 * V_23 ,
struct V_3 * V_4 , struct V_94 * V_95 )
{
T_3 V_96 = 0 ;
int V_7 = 0 ;
T_1 V_1 ;
if ( V_95 && ! F_37 ( & V_23 -> V_97 , V_95 ) )
return;
if ( F_38 ( V_23 ) == V_98 )
F_20 ( V_4 , 0 , V_43 | V_44 ) ;
else if ( V_95 && ( V_95 -> V_99 & V_100 ) == V_98 )
F_20 ( V_4 , V_43 | V_44 , 0 ) ;
V_1 = F_39 ( V_23 ) ;
if ( V_1 > 0 ) {
if ( V_1 > V_2 ) {
V_1 = V_2 ;
F_40 ( V_23 , V_1 , V_1 ) ;
}
F_33 ( V_4 , V_1 ) ;
}
if ( F_41 ( V_23 ) ) {
V_96 |= V_101 ;
if ( ! F_42 ( V_23 ) )
V_96 |= V_102 ;
if ( F_43 ( V_23 ) )
V_96 |= V_103 ;
}
if ( F_44 ( V_23 ) )
V_96 |= V_104 ;
switch ( F_45 ( V_23 ) ) {
case V_105 :
V_96 |= V_106 ;
break;
case V_107 :
V_96 |= V_108 ;
break;
case V_109 :
V_96 |= V_110 ;
break;
default:
case V_111 :
V_96 |= V_112 ;
break;
}
V_7 = F_10 ( V_4 , V_83 , V_96 ) ;
if ( V_7 ) {
F_7 ( & V_4 -> V_10 , L_16 ,
V_17 , V_7 ) ;
}
}
static int F_46 ( struct V_22 * V_23 )
{
int V_113 ;
struct V_3 * V_4 = V_23 -> V_114 ;
struct V_24 * V_115 = F_13 ( V_4 ) ;
T_3 V_116 , V_117 ;
F_12 ( V_4 ) ;
F_14 ( & V_115 -> V_26 ) ;
V_116 = V_115 -> V_46 ;
V_117 = V_115 -> V_29 ;
F_15 ( & V_115 -> V_26 ) ;
V_113 = ( V_116 & V_47 ? V_43 : 0 ) |
( V_116 & V_48 ? V_44 : 0 ) |
( V_117 & V_118 ? V_119 : 0 ) |
( V_117 & V_39 ? V_120 : 0 ) |
( V_117 & V_121 ? V_122 : 0 ) |
( V_117 & V_123 ? V_124 : 0 ) ;
return V_113 ;
}
static int F_47 ( struct V_22 * V_23 ,
unsigned int V_41 , unsigned int V_42 )
{
struct V_3 * V_4 = V_23 -> V_114 ;
return F_20 ( V_4 , V_41 , V_42 ) ;
}
static int F_48 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
int V_125 ;
V_125 = F_34 ( V_4 ) ;
if ( V_125 )
return V_125 ;
if ( V_23 )
F_36 ( V_23 , V_4 , NULL ) ;
V_125 = F_26 ( V_4 -> V_126 , V_12 ) ;
if ( V_125 ) {
F_7 ( & V_4 -> V_10 , L_17
L_18 , V_17 , V_125 ) ;
return V_125 ;
}
V_125 = F_49 ( V_23 , V_4 ) ;
if ( V_125 ) {
F_50 ( V_4 -> V_126 ) ;
return V_125 ;
}
return 0 ;
}
static void F_51 ( struct V_3 * V_4 )
{
F_35 ( V_4 ) ;
F_52 ( V_4 ) ;
F_50 ( V_4 -> V_126 ) ;
}
static void F_53 ( struct V_3 * V_4 , int V_127 )
{
if ( V_127 )
F_20 ( V_4 , V_43 | V_44 , 0 ) ;
else
F_20 ( V_4 , 0 , V_43 | V_44 ) ;
}
static int F_54 ( struct V_3 * V_4 )
{
T_3 V_117 ;
struct V_24 * V_25 = F_13 ( V_4 ) ;
F_14 ( & V_25 -> V_26 ) ;
V_117 = V_25 -> V_29 ;
F_15 ( & V_25 -> V_26 ) ;
if ( V_117 & V_39 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
unsigned long V_128 )
{
struct V_129 V_130 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . type = V_131 ;
V_130 . line = V_4 -> V_132 ;
V_130 . V_4 = V_4 -> V_133 ;
V_130 . V_134 = V_2 ;
if ( F_56 ( ( void V_135 * ) V_128 , & V_130 , sizeof( V_130 ) ) )
return - V_136 ;
return 0 ;
}
static int F_57 ( struct V_22 * V_23 ,
unsigned int V_137 , unsigned long V_128 )
{
struct V_3 * V_4 = V_23 -> V_114 ;
switch ( V_137 ) {
case V_138 :
return F_55 ( V_4 , V_128 ) ;
default:
break;
}
return - V_139 ;
}
static void F_58 ( struct V_140 * V_141 )
{
struct V_24 * V_25 =
F_59 ( V_141 , struct V_24 , V_52 ) ;
F_12 ( V_25 -> V_4 ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
V_25 = F_61 ( sizeof( * V_25 ) , V_12 ) ;
if ( ! V_25 )
return - V_13 ;
F_62 ( & V_25 -> V_26 ) ;
F_63 ( & V_25 -> V_52 , F_58 ) ;
F_64 ( V_4 , V_25 ) ;
V_4 -> V_4 . V_142 = 256 ;
V_25 -> V_4 = V_4 ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
V_25 = F_13 ( V_4 ) ;
F_9 ( V_25 ) ;
return 0 ;
}
