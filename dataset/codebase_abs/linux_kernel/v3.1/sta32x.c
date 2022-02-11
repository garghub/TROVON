static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 >> 16 ;
V_4 -> type = V_7 ;
V_4 -> V_8 = 3 * V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x04 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x08 ) ;
else
return - V_18 ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
V_10 -> V_19 . V_20 . V_21 [ V_15 ] =
F_4 ( V_12 , V_22 + V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
F_5 ( V_12 , V_22 + V_15 ,
V_10 -> V_19 . V_20 . V_21 [ V_15 ] ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x01 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x02 ) ;
else
return - V_18 ;
return 0 ;
}
static int F_7 ( struct V_23 * V_24 ,
int V_25 , unsigned int V_26 , int V_27 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_28 * V_29 = F_8 ( V_12 ) ;
int V_15 , V_30 , V_31 , V_32 ;
unsigned int V_33 = 0 ;
unsigned int V_34 = - 1 ;
unsigned int V_35 = 0 ;
F_9 ( L_1 , V_26 ) ;
V_29 -> V_36 = V_26 ;
if ( V_29 -> V_36 ) {
for ( V_15 = 0 ; V_15 < F_10 ( V_37 ) ; V_15 ++ ) {
V_31 = V_37 [ V_15 ] . V_31 ;
V_32 = V_37 [ V_15 ] . V_32 ;
for ( V_30 = 0 ; V_38 [ V_31 ] [ V_30 ] . V_39 ; V_30 ++ ) {
if ( V_38 [ V_31 ] [ V_30 ] . V_39 * V_32 == V_26 ) {
V_33 |= F_11 ( V_32 ) ;
if ( V_32 < V_34 )
V_34 = V_32 ;
if ( V_32 > V_35 )
V_35 = V_32 ;
}
}
}
V_33 &= ~ V_40 ;
if ( ! V_33 ) {
F_12 ( V_12 -> V_41 , L_2 ) ;
return - V_18 ;
}
} else {
V_33 = V_42 ;
V_34 = 32000 ;
V_35 = 192000 ;
}
V_24 -> V_43 -> V_44 . V_33 = V_33 ;
V_24 -> V_43 -> V_44 . V_34 = V_34 ;
V_24 -> V_43 -> V_44 . V_35 = V_35 ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 ,
unsigned int V_45 )
{
struct V_11 * V_12 = V_24 -> V_12 ;
struct V_28 * V_29 = F_8 ( V_12 ) ;
T_1 V_46 = F_4 ( V_12 , V_47 ) ;
F_9 ( L_3 ) ;
V_46 &= ~ ( V_48 | V_49 ) ;
switch ( V_45 & V_50 ) {
case V_51 :
break;
default:
return - V_18 ;
}
switch ( V_45 & V_52 ) {
case V_53 :
case V_54 :
case V_55 :
V_29 -> V_56 = V_45 & V_52 ;
break;
default:
return - V_18 ;
}
switch ( V_45 & V_57 ) {
case V_58 :
V_46 |= V_49 ;
break;
case V_59 :
V_46 |= V_48 ;
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_47 , V_46 ) ;
return 0 ;
}
static int F_14 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
struct V_23 * V_64 )
{
struct V_65 * V_66 = V_61 -> V_67 ;
struct V_11 * V_12 = V_66 -> V_12 ;
struct V_28 * V_29 = F_8 ( V_12 ) ;
unsigned int V_68 ;
int V_15 , V_69 = - 1 , V_31 = - 1 ;
T_1 V_70 , V_46 ;
V_68 = F_15 ( V_63 ) ;
F_9 ( L_4 , V_68 ) ;
for ( V_15 = 0 ; V_15 < F_10 ( V_37 ) ; V_15 ++ )
if ( V_37 [ V_15 ] . V_32 == V_68 )
V_31 = V_37 [ V_15 ] . V_31 ;
if ( V_31 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_38 [ V_31 ] [ V_15 ] . V_39 ; V_15 ++ )
if ( V_38 [ V_31 ] [ V_15 ] . V_39 * V_68 == V_29 -> V_36 )
V_69 = V_38 [ V_31 ] [ V_15 ] . V_69 ;
if ( V_69 < 0 )
return - V_18 ;
V_70 = F_4 ( V_12 , V_71 ) ;
V_70 &= ~ ( V_72 | V_73 ) ;
V_70 |= ( V_31 << V_74 ) | ( V_69 << V_75 ) ;
V_46 = F_4 ( V_12 , V_47 ) ;
V_46 &= ~ ( V_76 | V_77 ) ;
switch ( F_16 ( V_63 ) ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
F_9 ( L_5 ) ;
case V_82 :
case V_83 :
F_9 ( L_6 ) ;
switch ( V_29 -> V_56 ) {
case V_53 :
V_46 |= 0x0 ;
break;
case V_55 :
V_46 |= 0x1 ;
break;
case V_54 :
V_46 |= 0x2 ;
break;
}
break;
case V_84 :
case V_85 :
F_9 ( L_7 ) ;
switch ( V_29 -> V_56 ) {
case V_53 :
V_46 |= 0x4 ;
break;
case V_55 :
V_46 |= 0x5 ;
break;
case V_54 :
V_46 |= 0x6 ;
break;
}
break;
case V_86 :
case V_87 :
F_9 ( L_8 ) ;
switch ( V_29 -> V_56 ) {
case V_53 :
V_46 |= 0x8 ;
break;
case V_55 :
V_46 |= 0x9 ;
break;
case V_54 :
V_46 |= 0xa ;
break;
}
break;
case V_88 :
case V_89 :
F_9 ( L_9 ) ;
switch ( V_29 -> V_56 ) {
case V_53 :
V_46 |= 0x0 ;
break;
case V_55 :
V_46 |= 0xd ;
break;
case V_54 :
V_46 |= 0xe ;
break;
}
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_71 , V_70 ) ;
F_5 ( V_12 , V_47 , V_46 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
enum V_90 V_91 )
{
int V_92 ;
struct V_28 * V_29 = F_8 ( V_12 ) ;
F_9 ( L_10 , V_91 ) ;
switch ( V_91 ) {
case V_93 :
break;
case V_94 :
F_18 ( V_12 , V_95 ,
V_96 | V_97 ,
V_96 | V_97 ) ;
break;
case V_98 :
if ( V_12 -> V_99 . V_100 == V_101 ) {
V_92 = F_19 ( F_10 ( V_29 -> V_102 ) ,
V_29 -> V_102 ) ;
if ( V_92 != 0 ) {
F_12 ( V_12 -> V_41 ,
L_11 , V_92 ) ;
return V_92 ;
}
F_20 ( V_12 ) ;
}
F_18 ( V_12 , V_95 ,
V_96 | V_97 ,
V_96 | V_97 ) ;
break;
case V_101 :
F_18 ( V_12 , V_95 ,
V_96 | V_97 ,
V_96 ) ;
F_21 ( 300 ) ;
F_22 ( F_10 ( V_29 -> V_102 ) ,
V_29 -> V_102 ) ;
break;
}
V_12 -> V_99 . V_100 = V_91 ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 , T_2 V_103 )
{
F_17 ( V_12 , V_101 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_12 )
{
F_17 ( V_12 , V_98 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_8 ( V_12 ) ;
int V_15 , V_92 = 0 ;
V_29 -> V_12 = V_12 ;
for ( V_15 = 0 ; V_15 < F_10 ( V_29 -> V_102 ) ; V_15 ++ )
V_29 -> V_102 [ V_15 ] . V_104 = V_105 [ V_15 ] ;
V_92 = F_26 ( V_12 -> V_41 , F_10 ( V_29 -> V_102 ) ,
V_29 -> V_102 ) ;
if ( V_92 != 0 ) {
F_12 ( V_12 -> V_41 , L_12 , V_92 ) ;
goto V_106;
}
V_92 = F_19 ( F_10 ( V_29 -> V_102 ) ,
V_29 -> V_102 ) ;
if ( V_92 != 0 ) {
F_12 ( V_12 -> V_41 , L_11 , V_92 ) ;
goto V_107;
}
V_92 = F_27 ( V_12 , 8 , 8 , V_108 ) ;
if ( V_92 < 0 ) {
F_12 ( V_12 -> V_41 , L_13 , V_92 ) ;
return V_92 ;
}
for ( V_15 = 0 ; V_15 < V_109 ; V_15 ++ )
F_28 ( V_12 , V_15 , V_110 [ V_15 ] ) ;
F_28 ( V_12 , V_111 ,
V_12 -> V_112 ( V_12 , V_111 ) ) ;
F_28 ( V_12 , V_113 ,
V_12 -> V_112 ( V_12 , V_113 ) ) ;
F_28 ( V_12 , V_95 ,
V_12 -> V_112 ( V_12 , V_95 ) ) ;
F_28 ( V_12 , V_114 ,
V_12 -> V_112 ( V_12 , V_114 ) ) ;
F_28 ( V_12 , V_115 ,
V_12 -> V_112 ( V_12 , V_115 ) ) ;
F_28 ( V_12 , V_116 ,
V_12 -> V_112 ( V_12 , V_116 ) ) ;
F_28 ( V_12 , V_117 ,
V_12 -> V_112 ( V_12 , V_117 ) ) ;
F_18 ( V_12 , V_71 ,
V_118 | V_119 , 0 ) ;
F_18 ( V_12 , V_95 ,
V_120 ,
1 << V_121 ) ;
F_18 ( V_12 , V_122 ,
V_123 ,
0 << V_124 ) ;
F_18 ( V_12 , V_125 ,
V_123 ,
1 << V_124 ) ;
F_18 ( V_12 , V_117 ,
V_123 ,
2 << V_124 ) ;
F_17 ( V_12 , V_98 ) ;
F_22 ( F_10 ( V_29 -> V_102 ) , V_29 -> V_102 ) ;
return 0 ;
V_107:
F_29 ( F_10 ( V_29 -> V_102 ) , V_29 -> V_102 ) ;
V_106:
return V_92 ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_28 * V_29 = F_8 ( V_12 ) ;
F_22 ( F_10 ( V_29 -> V_102 ) , V_29 -> V_102 ) ;
F_29 ( F_10 ( V_29 -> V_102 ) , V_29 -> V_102 ) ;
return 0 ;
}
static int F_31 ( struct V_11 * V_12 ,
unsigned int V_126 )
{
switch ( V_126 ) {
case V_71 ... V_127 :
case V_128 ... V_129 :
return 0 ;
}
return 1 ;
}
static T_3 int F_32 ( struct V_130 * V_131 ,
const struct V_132 * V_133 )
{
struct V_28 * V_29 ;
int V_92 ;
V_29 = F_33 ( sizeof( struct V_28 ) , V_134 ) ;
if ( ! V_29 )
return - V_135 ;
F_34 ( V_131 , V_29 ) ;
V_92 = F_35 ( & V_131 -> V_41 , & V_136 , & V_137 , 1 ) ;
if ( V_92 != 0 ) {
F_12 ( & V_131 -> V_41 , L_14 , V_92 ) ;
F_36 ( V_29 ) ;
return V_92 ;
}
return 0 ;
}
static T_4 int F_37 ( struct V_130 * V_138 )
{
struct V_28 * V_29 = F_38 ( V_138 ) ;
struct V_11 * V_12 = V_29 -> V_12 ;
if ( V_12 )
F_17 ( V_12 , V_101 ) ;
F_29 ( F_10 ( V_29 -> V_102 ) , V_29 -> V_102 ) ;
if ( V_12 ) {
F_39 ( & V_138 -> V_41 ) ;
F_40 ( V_12 , NULL ) ;
}
F_36 ( V_29 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_139 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_139 ) ;
}
