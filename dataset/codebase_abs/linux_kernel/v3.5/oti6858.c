static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_11 ;
V_9 = F_3 ( V_12 , V_13 ) ;
if ( V_9 == NULL ) {
F_4 ( & V_7 -> V_14 , L_1 , V_15 ) ;
F_5 ( & V_4 -> V_5 ,
F_6 ( 2 ) ) ;
return;
}
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_8 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_17 ,
V_18 ,
0 , 0 ,
V_9 , V_12 ,
100 ) ;
if ( V_11 != V_12 ) {
F_4 ( & V_7 -> V_14 , L_2 , V_15 ) ;
F_9 ( V_9 ) ;
F_5 ( & V_4 -> V_5 ,
F_6 ( 2 ) ) ;
return;
}
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( ! F_11 ( V_9 , V_4 ) ) {
V_9 -> V_20 = V_4 -> V_21 . V_20 ;
V_9 -> V_22 = V_4 -> V_21 . V_22 ;
V_9 -> V_23 = V_4 -> V_21 . V_23 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_13 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_24 ,
V_25 ,
0 , 0 ,
V_9 , V_12 ,
100 ) ;
} else {
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_11 = 0 ;
}
F_9 ( V_9 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_11 != V_12 )
V_4 -> V_26 = 0 ;
V_4 -> V_27 = 1 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_14 ( L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_13 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4
L_5 , V_15 , V_11 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_29 . V_2 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_30 = 0 , V_11 ;
unsigned long V_10 ;
T_1 * V_31 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_4 -> V_10 . V_32 ) {
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_5 ( & V_4 -> V_29 ,
F_6 ( 2 ) ) ;
return;
}
V_4 -> V_10 . V_32 = 1 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_30 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
if ( V_30 > V_7 -> V_34 )
V_30 = V_7 -> V_34 ;
if ( V_30 != 0 ) {
V_31 = F_3 ( 1 , V_13 ) ;
if ( ! V_31 ) {
F_18 ( V_7 , L_6 ,
V_15 ) ;
return;
}
V_11 = F_7 ( V_7 -> V_16 -> V_14 ,
F_8 ( V_7 -> V_16 -> V_14 , 0 ) ,
V_35 ,
V_36 ,
V_30 , 0 , V_31 , 1 , 100 ) ;
if ( V_11 != 1 || * V_31 != 0 )
V_30 = 0 ;
F_9 ( V_31 ) ;
}
if ( V_30 == 0 ) {
V_4 -> V_10 . V_32 = 0 ;
F_14 ( L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_37 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4
L_5 , V_15 , V_11 ) ;
}
return;
}
V_30 = F_19 ( & V_7 -> V_33 ,
V_7 -> V_38 -> V_39 ,
V_30 , & V_7 -> V_19 ) ;
V_7 -> V_38 -> V_40 = V_30 ;
V_11 = F_15 ( V_7 -> V_38 , V_37 ) ;
if ( V_11 != 0 ) {
F_18 ( V_7 , L_4
L_5 , V_15 , V_11 ) ;
V_4 -> V_10 . V_32 = 0 ;
}
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_41 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_7 [ 0 ] ;
struct V_3 * V_4 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_16 -> V_43 ; ++ V_42 ) {
V_4 = F_22 ( sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
break;
F_23 ( & V_4 -> V_19 ) ;
F_24 ( & V_4 -> V_44 ) ;
V_4 -> V_7 = V_7 ;
F_25 ( & V_4 -> V_5 , F_1 ) ;
F_25 ( & V_4 -> V_29 , F_16 ) ;
F_26 ( V_16 -> V_7 [ V_42 ] , V_4 ) ;
}
if ( V_42 == V_16 -> V_43 )
return 0 ;
for ( -- V_42 ; V_42 >= 0 ; -- V_42 ) {
V_4 = F_27 ( V_16 -> V_7 [ V_42 ] ) ;
F_9 ( V_4 ) ;
F_26 ( V_16 -> V_7 [ V_42 ] , NULL ) ;
}
return - V_45 ;
}
static int F_28 ( struct V_46 * V_47 , struct V_6 * V_7 ,
const unsigned char * V_48 , int V_30 )
{
if ( ! V_30 )
return V_30 ;
V_30 = F_29 ( & V_7 -> V_33 , V_48 , V_30 , & V_7 -> V_19 ) ;
return V_30 ;
}
static int F_30 ( struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_49 ;
int V_50 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_50 = F_31 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_50 ;
}
static int F_32 ( struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_49 ;
int V_51 = 0 ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_51 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
return V_51 ;
}
static void F_33 ( struct V_46 * V_47 )
{
* ( V_47 -> V_52 ) = V_53 ;
V_47 -> V_52 -> V_54 = V_55 | V_56 | V_57 | V_58 | V_59 ;
V_47 -> V_52 -> V_60 = 38400 ;
V_47 -> V_52 -> V_61 = 38400 ;
}
static void F_34 ( struct V_46 * V_47 ,
struct V_6 * V_7 , struct V_62 * V_63 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_64 ;
T_1 V_23 , V_22 ;
T_2 V_20 ;
int V_65 ;
if ( ! V_47 ) {
F_14 ( L_7 , V_15 ) ;
return;
}
V_64 = V_47 -> V_52 -> V_54 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_20 = V_4 -> V_21 . V_20 ;
V_23 = V_4 -> V_21 . V_23 ;
V_22 = V_4 -> V_21 . V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_23 &= ~ V_66 ;
switch ( V_64 & V_67 ) {
case V_68 :
V_23 |= V_69 ;
break;
case V_70 :
V_23 |= V_71 ;
break;
case V_72 :
V_23 |= V_73 ;
break;
default:
case V_56 :
V_23 |= V_74 ;
break;
}
V_65 = F_35 ( V_47 ) ;
if ( V_65 == 0 ) {
V_20 = 0 ;
} else {
int V_75 ;
int V_76 ;
V_65 = F_36 ( V_65 , V_77 ) ;
V_76 = ( 96000000 + 8 * V_65 ) / ( 16 * V_65 ) ;
V_75 = 96000000 / ( 16 * V_76 ) ;
V_20 = F_37 ( V_76 ) ;
F_38 ( V_47 , V_75 , V_75 ) ;
}
V_23 &= ~ V_78 ;
if ( ( V_64 & V_79 ) != 0 )
V_23 |= V_80 ;
else
V_23 |= V_81 ;
V_23 &= ~ V_82 ;
if ( ( V_64 & V_83 ) != 0 ) {
if ( ( V_64 & V_84 ) != 0 )
V_23 |= V_85 ;
else
V_23 |= V_86 ;
} else {
V_23 |= V_87 ;
}
V_22 &= ~ V_88 ;
if ( ( V_64 & V_89 ) != 0 )
V_22 |= ( V_90 | V_91 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_20 != V_4 -> V_21 . V_20
|| V_22 != V_4 -> V_21 . V_22
|| V_23 != V_4 -> V_21 . V_23 ) {
V_4 -> V_21 . V_20 = V_20 ;
V_4 -> V_21 . V_22 = V_22 ;
V_4 -> V_21 . V_23 = V_23 ;
}
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
static int F_39 ( struct V_46 * V_47 , struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
struct V_62 V_92 ;
struct V_41 * V_16 = V_7 -> V_16 ;
struct V_8 * V_48 ;
unsigned long V_10 ;
int V_11 ;
F_40 ( V_16 -> V_14 , V_7 -> V_38 -> V_93 ) ;
F_40 ( V_16 -> V_14 , V_7 -> V_94 -> V_93 ) ;
V_48 = F_3 ( V_12 , V_13 ) ;
if ( V_48 == NULL ) {
F_4 ( & V_7 -> V_14 , L_1 , V_15 ) ;
return - V_45 ;
}
V_11 = F_7 ( V_16 -> V_14 , F_8 ( V_16 -> V_14 , 0 ) ,
V_17 ,
V_18 ,
0 , 0 ,
V_48 , V_12 ,
100 ) ;
if ( V_11 != V_12 ) {
V_48 -> V_20 = F_37 ( 0x009c ) ;
V_48 -> V_23 = 0x03 ;
V_48 -> V_95 = 0x43 ;
V_48 -> V_22 = 0x4c ;
V_48 -> V_96 = 0x00 ;
V_48 -> V_97 = 0x5b ;
V_48 -> V_98 = 0x00 ;
}
F_10 ( & V_4 -> V_19 , V_10 ) ;
memcpy ( & V_4 -> V_99 , V_48 , V_12 ) ;
V_4 -> V_21 . V_20 = V_48 -> V_20 ;
V_4 -> V_21 . V_23 = V_48 -> V_23 ;
V_4 -> V_21 . V_22 = V_48 -> V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
F_9 ( V_48 ) ;
F_14 ( L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_13 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_4
L_5 , V_15 , V_11 ) ;
F_41 ( V_7 ) ;
return V_11 ;
}
if ( V_47 )
F_34 ( V_47 , V_7 , & V_92 ) ;
V_7 -> V_7 . V_100 = 256 ;
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
F_42 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
F_14 ( L_8 , V_15 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_43 ( & V_4 -> V_29 ) ;
F_14 ( L_9 , V_15 ) ;
F_44 ( V_7 -> V_38 ) ;
F_44 ( V_7 -> V_94 ) ;
F_44 ( V_7 -> V_28 ) ;
}
static int F_45 ( struct V_46 * V_47 ,
unsigned int V_101 , unsigned int V_102 )
{
struct V_6 * V_7 = V_47 -> V_49 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
T_1 V_22 ;
F_14 ( L_10 ,
V_15 , V_7 -> V_103 , V_101 , V_102 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_22 = V_4 -> V_21 . V_22 ;
if ( ( V_101 & V_104 ) != 0 )
V_22 |= V_91 ;
if ( ( V_101 & V_105 ) != 0 )
V_22 |= V_90 ;
if ( ( V_102 & V_104 ) != 0 )
V_22 &= ~ V_91 ;
if ( ( V_102 & V_105 ) != 0 )
V_22 &= ~ V_90 ;
if ( V_22 != V_4 -> V_21 . V_22 )
V_4 -> V_21 . V_22 = V_22 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
return 0 ;
}
static int F_46 ( struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_49 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned V_97 ;
unsigned V_11 = 0 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_97 = V_4 -> V_99 . V_97 & V_106 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( ( V_97 & V_107 ) != 0 )
V_11 |= V_104 ;
if ( ( V_97 & V_108 ) != 0 )
V_11 |= V_109 ;
if ( ( V_97 & V_110 ) != 0 )
V_11 |= V_111 ;
if ( ( V_97 & V_112 ) != 0 )
V_11 |= V_105 ;
if ( ( V_97 & V_113 ) != 0 )
V_11 |= V_114 ;
if ( ( V_97 & V_115 ) != 0 )
V_11 |= V_116 ;
F_14 ( L_11 , V_15 , V_11 ) ;
return V_11 ;
}
static int F_47 ( struct V_6 * V_7 , unsigned int V_117 )
{
struct V_3 * V_4 = F_27 ( V_7 ) ;
unsigned long V_10 ;
unsigned int V_118 , V_99 ;
unsigned int V_119 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_118 = V_4 -> V_99 . V_97 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
while ( 1 ) {
F_48 ( V_4 -> V_44 ,
V_4 -> V_99 . V_97 != V_118 ) ;
if ( F_49 ( V_120 ) )
return - V_121 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_99 = V_4 -> V_99 . V_97 & V_106 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
V_119 = V_118 ^ V_99 ;
if ( ( ( V_117 & V_122 ) && ( V_119 & V_113 ) ) ||
( ( V_117 & V_111 ) && ( V_119 & V_110 ) ) ||
( ( V_117 & V_116 ) && ( V_119 & V_115 ) ) ||
( ( V_117 & V_109 ) && ( V_119 & V_108 ) ) )
return 0 ;
V_118 = V_99 ;
}
return 0 ;
}
static int F_50 ( struct V_46 * V_47 ,
unsigned int V_123 , unsigned long V_117 )
{
struct V_6 * V_7 = V_47 -> V_49 ;
F_14 ( L_12 ,
V_15 , V_7 -> V_103 , V_123 , V_117 ) ;
switch ( V_123 ) {
case V_124 :
F_14 ( L_13 , V_15 ) ;
return F_47 ( V_7 , V_117 ) ;
default:
F_14 ( L_14 , V_15 , V_123 ) ;
break;
}
return - V_125 ;
}
static void F_51 ( struct V_41 * V_16 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_16 -> V_43 ; ++ V_42 )
F_9 ( F_27 ( V_16 -> V_7 [ V_42 ] ) ) ;
}
static void F_52 ( struct V_126 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_127 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_26 = 0 , V_128 = 0 , V_129 = 1 ;
int V_99 = V_126 -> V_99 ;
switch ( V_99 ) {
case 0 :
break;
case - V_130 :
case - V_131 :
case - V_132 :
F_14 ( L_15 ,
V_15 , V_99 ) ;
return;
default:
F_14 ( L_16 ,
V_15 , V_99 ) ;
break;
}
if ( V_99 == 0 && V_126 -> V_133 == V_12 ) {
struct V_8 * V_134 = V_126 -> V_39 ;
unsigned long V_10 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( ! V_4 -> V_26 ) {
if ( ! F_11 ( V_134 , V_4 ) ) {
if ( V_134 -> V_98 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_129 = 0 ;
F_14 ( L_17 ,
V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
} else {
if ( F_11 ( V_134 , V_4 ) ) {
V_4 -> V_26 = 0 ;
} else if ( ! V_4 -> V_27 ) {
V_129 = 0 ;
} else if ( -- V_4 -> V_26 == 0 ) {
if ( V_134 -> V_98 == 0 ) {
V_4 -> V_26 = 4 ;
V_4 -> V_27 = 0 ;
V_129 = 0 ;
F_14 ( L_17 ,
V_15 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
}
}
if ( ! V_4 -> V_26 ) {
if ( V_134 -> V_97 != V_4 -> V_99 . V_97 )
F_53 ( & V_4 -> V_44 ) ;
memcpy ( & V_4 -> V_99 , V_134 , V_12 ) ;
}
if ( ! V_4 -> V_26 && V_134 -> V_98 != 0 ) {
V_128 = V_134 -> V_98 ;
V_4 -> V_10 . V_135 = 1 ;
}
V_26 = V_4 -> V_26 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_128 ) {
int V_11 ;
V_11 = F_15 ( V_7 -> V_94 , V_136 ) ;
if ( V_11 != 0 ) {
V_4 -> V_10 . V_135 = 0 ;
F_4 ( & V_7 -> V_14 , L_18
L_19 , V_15 , V_11 ) ;
} else {
V_129 = 0 ;
}
} else if ( ! V_26 ) {
unsigned long V_10 ;
int V_30 ;
F_10 ( & V_7 -> V_19 , V_10 ) ;
V_30 = F_17 ( & V_7 -> V_33 ) ;
F_12 ( & V_7 -> V_19 , V_10 ) ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
if ( V_4 -> V_10 . V_32 == 0 && V_30 != 0 ) {
F_5 ( & V_4 -> V_29 , 0 ) ;
V_129 = 0 ;
}
F_12 ( & V_4 -> V_19 , V_10 ) ;
}
if ( V_129 ) {
int V_11 ;
V_11 = F_15 ( V_126 , V_136 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_126 -> V_14 -> V_14 ,
L_20
L_19 , V_15 , V_11 ) ;
}
}
}
static void F_54 ( struct V_126 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_127 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
struct V_46 * V_47 ;
unsigned char * V_137 = V_126 -> V_39 ;
unsigned long V_10 ;
int V_99 = V_126 -> V_99 ;
int V_11 ;
F_10 ( & V_4 -> V_19 , V_10 ) ;
V_4 -> V_10 . V_135 = 0 ;
F_12 ( & V_4 -> V_19 , V_10 ) ;
if ( V_99 != 0 ) {
F_14 ( L_21 , V_15 ) ;
return;
}
V_47 = F_55 ( & V_7 -> V_7 ) ;
if ( V_47 != NULL && V_126 -> V_133 > 0 ) {
F_56 ( V_47 , V_137 , V_126 -> V_133 ) ;
F_57 ( V_47 ) ;
}
F_58 ( V_47 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_136 ) ;
if ( V_11 != 0 && V_11 != - V_138 ) {
F_4 ( & V_7 -> V_14 , L_18
L_19 , V_15 , V_11 ) ;
}
}
static void F_59 ( struct V_126 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_127 ;
struct V_3 * V_4 = F_27 ( V_7 ) ;
int V_99 = V_126 -> V_99 ;
int V_11 ;
switch ( V_99 ) {
case 0 :
break;
case - V_130 :
case - V_131 :
case - V_132 :
F_14 ( L_15 ,
V_15 , V_99 ) ;
V_4 -> V_10 . V_32 = 0 ;
return;
default:
F_14 ( L_22 ,
V_15 , V_99 ) ;
F_14 ( L_23 , V_15 ) ;
V_7 -> V_38 -> V_40 = 1 ;
V_11 = F_15 ( V_7 -> V_38 , V_136 ) ;
if ( V_11 ) {
F_18 ( V_7 , L_18
L_19 , V_15 , V_11 ) ;
} else {
return;
}
}
V_4 -> V_10 . V_32 = 0 ;
F_14 ( L_3 , V_15 ) ;
V_11 = F_15 ( V_7 -> V_28 , V_136 ) ;
if ( V_11 != 0 ) {
F_4 ( & V_7 -> V_14 , L_24
L_19 , V_15 , V_11 ) ;
}
}
