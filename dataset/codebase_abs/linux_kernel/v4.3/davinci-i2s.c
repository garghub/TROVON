static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 = V_6 ? V_8 : V_9 ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ^ V_7 ) ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
T_1 V_21 ;
T_1 V_22 = V_6 ? V_23 : V_24 ;
V_21 = F_3 ( V_2 , V_25 ) ;
if ( V_21 & V_22 ) {
F_1 ( V_2 , V_25 ,
V_21 & ~ V_22 ) ;
F_5 ( V_2 , V_6 ) ;
}
if ( V_2 -> V_11 & ( V_26 | V_27 |
V_28 | V_29 ) ) {
V_21 |= V_30 ;
F_1 ( V_2 , V_25 , V_21 ) ;
}
if ( V_6 ) {
if ( V_18 -> V_31 -> V_32 -> V_33 ) {
int V_34 = V_18 -> V_31 -> V_32 -> V_33 ( V_13 ,
V_35 ) ;
if ( V_34 < 0 )
F_7 ( V_36 L_1 ) ;
}
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 |= V_23 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_8 ( 100 ) ;
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 &= ~ V_23 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_5 ( V_2 , V_6 ) ;
if ( V_18 -> V_31 -> V_32 -> V_33 ) {
int V_34 = V_18 -> V_31 -> V_32 -> V_33 ( V_13 ,
V_37 ) ;
if ( V_34 < 0 )
F_7 ( V_36 L_2 ) ;
}
}
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 |= V_22 ;
if ( V_2 -> V_11 & ( V_26 | V_27 ) ) {
V_21 |= V_38 ;
}
F_1 ( V_2 , V_25 , V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_21 ;
V_21 = F_3 ( V_2 , V_25 ) ;
V_21 &= ~ ( V_30 | V_38 ) ;
V_21 &= V_6 ? ~ V_23 : ~ V_24 ;
F_1 ( V_2 , V_25 , V_21 ) ;
F_5 ( V_2 , V_6 ) ;
}
static int F_10 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
unsigned int V_11 ;
unsigned int V_42 ;
bool V_43 = false ;
V_42 = V_44 |
F_12 ( V_45 * 2 - 1 ) |
F_13 ( V_45 - 1 ) ;
V_2 -> V_41 = V_41 ;
switch ( V_41 & V_46 ) {
case V_47 :
V_11 = V_26 |
V_27 |
V_28 |
V_29 ;
break;
case V_48 :
V_11 = V_27 | V_26 ;
switch ( V_2 -> V_49 ) {
case V_50 :
V_11 |= V_28 |
V_29 ;
break;
case V_51 :
V_11 |= V_52 ;
break;
default:
F_14 ( V_2 -> V_2 , L_3 ) ;
return - V_53 ;
}
break;
case V_54 :
V_11 = 0 ;
break;
default:
F_7 ( V_55 L_4 , V_56 ) ;
return - V_53 ;
}
switch ( V_41 & V_57 ) {
case V_58 :
V_43 = true ;
case V_59 :
V_2 -> V_60 = V_61 ;
break;
case V_62 :
V_2 -> V_60 = V_63 ;
break;
default:
F_7 ( V_55 L_5 , V_56 ) ;
return - V_53 ;
}
switch ( V_41 & V_64 ) {
case V_65 :
V_11 |= ( V_8 | V_9 ) ;
break;
case V_66 :
V_11 |= ( V_67 | V_68 ) ;
break;
case V_69 :
V_11 |= ( V_8 | V_9 |
V_67 | V_68 ) ;
break;
case V_70 :
break;
default:
return - V_53 ;
}
if ( V_43 == true )
V_11 ^= ( V_67 | V_68 ) ;
F_1 ( V_2 , V_71 , V_42 ) ;
V_2 -> V_11 = V_11 ;
F_1 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 ,
int V_72 , int div )
{
struct V_1 * V_2 = F_11 ( V_40 ) ;
if ( V_72 != V_73 )
return - V_74 ;
V_2 -> V_75 = div ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_76 * V_77 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
struct V_79 * V_80 = NULL ;
int V_81 , V_82 ;
unsigned int V_83 , V_84 , V_42 , V_75 , V_85 , V_86 ;
T_1 V_21 ;
T_2 V_41 ;
unsigned V_87 = 1 ;
V_21 = F_3 ( V_2 , V_25 ) ;
if ( V_13 -> V_19 == V_88 ) {
V_21 |= F_17 ( 3 ) | V_89 ;
F_1 ( V_2 , V_25 , V_21 ) ;
} else {
V_21 |= F_18 ( 3 ) | V_89 ;
F_1 ( V_2 , V_25 , V_21 ) ;
}
V_82 = V_2 -> V_41 & V_46 ;
V_41 = F_19 ( V_77 ) ;
V_81 = V_90 [ V_41 ] ;
switch ( V_82 ) {
case V_47 :
V_85 = F_20 ( V_2 -> V_91 ) ;
V_42 = V_44 |
V_92 ;
V_42 |= F_13 ( V_81 *
8 - 1 ) ;
if ( V_2 -> V_93 ) {
V_75 = 256 ;
do {
V_86 = ( V_85 / ( -- V_75 ) ) /
V_77 -> V_94 *
V_77 -> V_95 ;
} while ( ( ( V_86 < 33 ) || ( V_86 > 4095 ) ) &&
( V_75 ) );
V_75 -- ;
V_42 |= F_12 ( V_86 - 1 ) ;
} else {
V_75 = V_85 / ( V_81 * 16 ) /
V_77 -> V_94 * V_77 -> V_95 ;
V_42 |= F_12 ( V_81 *
16 - 1 ) ;
}
V_75 &= 0xFF ;
V_42 |= V_75 ;
break;
case V_48 :
V_42 = V_44 ;
V_75 = V_2 -> V_75 - 1 ;
V_42 |= F_13 ( V_81 * 8 - 1 ) ;
V_42 |= F_12 ( V_81 * 16 - 1 ) ;
V_75 &= 0xFF ;
V_42 |= V_75 ;
break;
case V_54 :
V_80 = F_21 ( V_77 , V_96 ) ;
V_42 = V_44 ;
V_42 |= F_13 ( F_22 ( V_80 ) - 1 ) ;
F_23 ( L_6 ,
V_56 , __LINE__ , F_22 ( V_80 ) - 1 ) ;
V_80 = F_21 ( V_77 , V_97 ) ;
V_42 |= F_12 ( F_22 ( V_80 ) - 1 ) ;
break;
default:
return - V_53 ;
}
F_1 ( V_2 , V_71 , V_42 ) ;
V_83 = V_98 ;
V_84 = V_99 ;
if ( V_2 -> V_60 == V_63 ) {
V_83 |= F_24 ( 0 ) ;
V_84 |= F_25 ( 0 ) ;
} else {
V_83 |= F_24 ( 1 ) ;
V_84 |= F_25 ( 1 ) ;
}
V_41 = F_19 ( V_77 ) ;
if ( ( V_41 > V_100 ) || ! V_101 [ V_41 ] ) {
F_7 ( V_102 L_7 ) ;
return - V_53 ;
}
if ( F_26 ( V_77 ) == 2 ) {
V_87 = 2 ;
if ( V_103 [ V_41 ] && V_2 -> V_104 ) {
V_87 = 1 ;
V_41 = V_103 [ V_41 ] ;
}
switch ( V_82 ) {
case V_47 :
case V_105 :
V_83 |= F_27 ( 0 ) ;
V_84 |= F_28 ( 0 ) ;
V_83 |= V_106 ;
V_84 |= V_107 ;
break;
case V_54 :
case V_48 :
V_83 |= F_27 ( V_87 - 1 ) ;
V_84 |= F_28 ( V_87 - 1 ) ;
break;
default:
return - V_53 ;
}
}
V_81 = V_90 [ V_41 ] ;
switch ( V_82 ) {
case V_47 :
case V_105 :
V_83 |= F_29 ( 0 ) ;
V_84 |= F_30 ( 0 ) ;
break;
case V_54 :
case V_48 :
V_83 |= F_29 ( V_87 - 1 ) ;
V_84 |= F_30 ( V_87 - 1 ) ;
break;
default:
return - V_53 ;
}
V_83 |= F_31 ( V_81 ) |
F_32 ( V_81 ) ;
V_84 |= F_33 ( V_81 ) |
F_34 ( V_81 ) ;
if ( V_13 -> V_19 == V_20 )
F_1 ( V_2 , V_108 , V_84 ) ;
else
F_1 ( V_2 , V_109 , V_83 ) ;
F_23 ( L_8 , V_56 , __LINE__ , V_42 ) ;
F_23 ( L_9 , V_56 , __LINE__ , V_84 ) ;
F_23 ( L_10 , V_56 , __LINE__ , V_83 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_13 , int V_110 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_34 = 0 ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
switch ( V_110 ) {
case V_37 :
case V_111 :
case V_112 :
F_6 ( V_2 , V_13 ) ;
break;
case V_35 :
case V_113 :
case V_114 :
F_9 ( V_2 , V_6 ) ;
break;
default:
V_34 = - V_53 ;
}
return V_34 ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
int V_6 = ( V_13 -> V_19 == V_20 ) ;
F_9 ( V_2 , V_6 ) ;
}
static int F_38 ( struct V_39 * V_78 )
{
struct V_1 * V_2 = F_11 ( V_78 ) ;
V_78 -> V_115 = & V_2 -> V_116 [ V_20 ] ;
V_78 -> V_117 = & V_2 -> V_116 [ V_88 ] ;
return 0 ;
}
static int F_39 ( struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_120 * V_121 , * V_122 ;
void T_3 * V_123 ;
int * V_124 ;
int V_34 ;
V_121 = F_40 ( V_119 , V_125 , 0 ) ;
V_123 = F_41 ( & V_119 -> V_2 , V_121 ) ;
if ( F_42 ( V_123 ) )
return F_43 ( V_123 ) ;
V_2 = F_44 ( & V_119 -> V_2 , sizeof( struct V_1 ) ,
V_126 ) ;
if ( ! V_2 )
return - V_127 ;
V_2 -> V_91 = F_45 ( & V_119 -> V_2 , NULL ) ;
if ( F_42 ( V_2 -> V_91 ) )
return - V_74 ;
F_46 ( V_2 -> V_91 ) ;
V_2 -> V_5 = V_123 ;
V_2 -> V_116 [ V_20 ] . V_128 =
( V_129 ) ( V_121 -> V_130 + V_131 ) ;
V_2 -> V_116 [ V_88 ] . V_128 =
( V_129 ) ( V_121 -> V_130 + V_132 ) ;
V_122 = F_40 ( V_119 , V_133 , 0 ) ;
if ( ! V_122 ) {
F_14 ( & V_119 -> V_2 , L_11 ) ;
V_34 = - V_134 ;
goto V_135;
}
V_124 = & V_2 -> V_136 [ V_20 ] ;
* V_124 = V_122 -> V_130 ;
V_2 -> V_116 [ V_20 ] . V_137 = V_124 ;
V_122 = F_40 ( V_119 , V_133 , 1 ) ;
if ( ! V_122 ) {
F_14 ( & V_119 -> V_2 , L_11 ) ;
V_34 = - V_134 ;
goto V_135;
}
V_124 = & V_2 -> V_136 [ V_88 ] ;
* V_124 = V_122 -> V_130 ;
V_2 -> V_116 [ V_88 ] . V_137 = V_124 ;
V_2 -> V_2 = & V_119 -> V_2 ;
F_47 ( & V_119 -> V_2 , V_2 ) ;
V_34 = F_48 ( & V_119 -> V_2 , & V_138 ,
& V_139 , 1 ) ;
if ( V_34 != 0 )
goto V_135;
V_34 = F_49 ( & V_119 -> V_2 ) ;
if ( V_34 ) {
F_14 ( & V_119 -> V_2 , L_12 , V_34 ) ;
goto V_140;
}
return 0 ;
V_140:
F_50 ( & V_119 -> V_2 ) ;
V_135:
F_51 ( V_2 -> V_91 ) ;
F_52 ( V_2 -> V_91 ) ;
return V_34 ;
}
static int F_53 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_54 ( & V_119 -> V_2 ) ;
F_50 ( & V_119 -> V_2 ) ;
F_51 ( V_2 -> V_91 ) ;
F_52 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
return 0 ;
}
