static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
T_2 V_5 = V_3 & 0x10 ? 2 : 1 ;
V_2 -> V_6 = 2 ;
V_2 -> V_7 = V_8 * V_5 ;
V_2 -> V_9 [ 0 ] = V_10 * 64 * V_5 ;
V_2 -> V_9 [ 1 ] = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_4 ( V_2 , V_13 , V_14 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == V_13 )
break;
F_5 ( 1000 , 10000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_8 ( V_2 , V_13 , V_14 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == 0 )
break;
F_5 ( 100 , 1000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_2 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == V_13 )
return true ;
return false ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_18 , V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = 0 ;
F_8 ( V_2 , V_23 , V_14 ) ;
if ( V_21 -> V_24 & V_25 )
V_22 |= V_26 ;
if ( V_21 -> V_24 & V_27 )
V_22 |= V_28 ;
V_22 |= V_29 ;
F_4 ( V_2 , V_22 , V_14 ) ;
V_22 = ( ( V_30 & 0xfff ) << 16 ) |
( V_31 & 0xfff ) ;
F_12 ( V_2 , V_22 , V_32 ) ;
F_12 ( V_2 , V_33 , V_32 + 4 ) ;
V_22 = F_13 ( V_21 -> V_34 ) |
F_14 ( V_21 -> V_35 ) ;
F_12 ( V_2 , V_22 , V_36 + V_37 ) ;
V_22 = F_15 ( V_21 -> V_38 ) |
F_16 ( V_21 -> V_39 ) ;
F_12 ( V_2 , V_22 , V_36 + V_40 ) ;
V_22 = F_17 ( V_21 -> V_41 ) |
F_18 ( V_21 -> V_42 ) ;
F_12 ( V_2 , V_22 , V_36 + V_43 ) ;
V_22 = F_19 ( V_21 -> V_44 ) | F_20 ( V_21 -> V_45 ) ;
F_12 ( V_2 , V_22 , V_36 + V_46 ) ;
if ( V_21 -> V_24 & V_47 )
F_4 ( V_2 , V_48 , V_49 ) ;
else
F_8 ( V_2 , V_48 , V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_3 V_50 , T_3 V_51 , T_1 V_52 )
{
unsigned int V_53 ;
int V_54 ;
if ( ( V_52 == V_55 ) || ( V_52 == V_56 ) )
return - V_57 ;
F_22 ( V_52 , & V_53 , & V_54 ) ;
return V_50 * V_54 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_58 ) ;
T_2 V_59 = ( V_3 >> 4 ) & 0x3 , V_60 ;
V_2 -> V_6 = 2 ;
switch ( V_59 ) {
case 0 :
V_2 -> V_7 = V_8 ;
V_60 = 64 ;
break;
case 1 :
V_2 -> V_7 = V_61 ;
V_60 = 128 ;
break;
case 2 :
V_2 -> V_7 = 1280 ;
V_60 = 40 ;
break;
case 3 :
V_2 -> V_7 = 0 ;
return - V_57 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_60 * V_10 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_4 ( V_2 , V_62 , V_63 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_62 ) == V_62 )
break;
F_5 ( 1000 , 10000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_1 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_8 ( V_2 , V_62 , V_63 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_62 ) == 0 )
break;
F_5 ( 100 , 1000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_2 ) ;
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_62 ) == V_62 )
return true ;
return false ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_18 , V_64 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = V_29 ;
F_12 ( V_2 , V_22 , V_65 ) ;
V_22 = ( ( ( V_31 >> 4 ) & 0xff ) << 16 ) |
( ( ( V_30 >> 4 ) & 0xff ) << 8 ) |
( ( V_33 >> 4 ) & 0xff ) ;
F_12 ( V_2 , V_22 , V_66 ) ;
V_22 = F_13 ( V_21 -> V_34 ) |
F_14 ( V_21 -> V_35 ) ;
F_12 ( V_2 , V_22 , V_67 + V_37 ) ;
V_22 = F_29 ( V_21 -> V_38 ) |
F_16 ( V_21 -> V_39 ) ;
F_12 ( V_2 , V_22 , V_67 + V_40 ) ;
V_22 = F_17 ( V_21 -> V_41 ) |
F_18 ( V_21 -> V_42 ) ;
if ( V_21 -> V_24 & V_25 )
V_22 |= V_68 ;
if ( V_21 -> V_24 & V_27 )
V_22 |= V_69 ;
F_12 ( V_2 , V_22 , V_67 + V_43 ) ;
V_22 = F_19 ( V_21 -> V_44 ) | F_20 ( V_21 -> V_45 ) ;
F_12 ( V_2 , V_22 , V_67 + V_46 ) ;
if ( V_21 -> V_24 & V_47 )
F_4 ( V_2 , V_48 , V_49 ) ;
else
F_8 ( V_2 , V_48 , V_49 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_50 , T_3 V_51 , T_1 V_52 )
{
T_1 V_70 ;
if ( ( V_52 == V_55 ) || ( V_52 == V_56 ) )
return - V_57 ;
switch ( V_52 ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_55 :
case V_56 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_70 = 32 ;
break;
case V_89 :
case V_90 :
V_70 = 24 ;
break;
default:
return - V_57 ;
}
return V_50 * V_70 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_58 ) ;
T_2 V_59 = ( V_3 >> 4 ) & 0x3 , V_60 ;
V_2 -> V_6 = 4 ;
switch ( V_59 ) {
case 0 :
case 2 :
V_2 -> V_7 = 0 ;
return - V_57 ;
case 1 :
V_2 -> V_7 = V_61 ;
V_60 = 128 ;
break;
case 3 :
V_2 -> V_7 = 2560 ;
V_60 = 80 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_60 * V_10 ;
return 0 ;
}
T_2 F_32 ( const struct V_91 * V_15 ,
T_2 V_92 , T_1 V_93 )
{
unsigned int V_94 ;
for ( V_94 = 0 ; V_94 < V_15 -> V_95 ; V_94 ++ ) {
if ( ( ( V_15 -> V_96 [ V_94 ] . V_97 & V_92 ) == V_92 ) &&
( V_15 -> V_96 [ V_94 ] . V_93 == V_93 ) )
return V_15 -> V_96 [ V_94 ] . V_98 ;
}
return V_99 ;
}
static void F_33 ( struct V_1 * V_2 , T_2 V_100 , T_1 V_101 )
{
T_1 V_102 = F_34 ( V_2 , V_100 ) ;
if ( V_2 -> V_15 . V_103 & V_104 )
F_12 ( V_2 , V_101 , V_102 + V_105 ) ;
else
F_12 ( V_2 , V_101 , V_102 + V_17 ) ;
}
static T_4 F_35 ( int V_101 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 ;
const struct V_112 * V_113 ;
T_1 V_11 , V_114 , V_115 ;
T_4 V_116 = V_117 ;
if ( ! V_108 -> V_111 )
return V_118 ;
V_2 = V_110 -> V_119 ;
V_113 = & V_2 -> V_15 . V_120 ;
V_115 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( V_115 & V_2 -> V_15 . V_121 . V_122 ) {
F_36 ( & V_110 -> V_123 , 1 ) ;
F_33 ( V_2 , V_124 , V_115 ) ;
V_116 = V_125 ;
}
V_11 = F_2 ( V_2 , V_17 ) ;
if ( ! ( V_11 & V_113 -> V_126 ) )
return V_116 ;
V_114 = F_2 ( V_2 , V_127 ) ;
V_11 &= V_114 ;
if ( V_11 & V_113 -> V_122 )
F_37 ( & V_110 -> V_128 ) ;
F_33 ( V_2 , V_129 , V_11 ) ;
return ( V_116 == V_117 ) ? V_118 : V_116 ;
}
static T_4 F_38 ( int V_101 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_109 * V_110 = V_108 -> V_111 ;
F_39 ( & V_110 -> V_130 ) ;
return V_118 ;
}
int F_40 ( struct V_107 * V_108 , int V_101 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 = V_110 -> V_119 ;
int V_116 ;
F_41 ( V_2 , V_129 , 0xffffffff ) ;
F_33 ( V_2 , V_129 , 0xffffffff ) ;
F_41 ( V_2 , V_124 , 0xffffffff ) ;
F_33 ( V_2 , V_124 , 0xffffffff ) ;
V_116 = F_42 ( V_108 -> V_119 , V_101 , F_35 ,
F_38 ,
V_131 , L_3 , V_108 ) ;
if ( V_116 < 0 ) {
F_43 ( L_4 ) ;
return V_116 ;
}
F_44 ( V_2 , V_124 ,
V_2 -> V_15 . V_121 . V_126 ) ;
F_44 ( V_2 , V_129 ,
V_2 -> V_15 . V_120 . V_126 ) ;
return 0 ;
}
void F_45 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 = V_110 -> V_119 ;
F_41 ( V_2 , V_129 ,
V_2 -> V_15 . V_120 . V_126 ) ;
F_41 ( V_2 , V_124 ,
V_2 -> V_15 . V_121 . V_126 ) ;
}
static T_4 F_46 ( int V_101 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 = V_110 -> V_119 ;
T_1 V_11 , V_114 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_132 + V_17 ) ;
if ( ! ( V_11 & V_2 -> V_15 . V_133 . V_126 ) )
return V_117 ;
V_114 = F_2 ( V_2 , V_2 -> V_15 . V_132 + V_127 ) ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_132 + V_17 ) ;
V_11 &= V_114 ;
F_33 ( V_2 , V_134 , V_11 ) ;
return V_118 ;
}
static T_4 F_47 ( int V_101 , void * V_106 )
{
return V_118 ;
}
int F_48 ( struct V_107 * V_108 , int V_101 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 = V_110 -> V_119 ;
int V_116 ;
F_41 ( V_2 , V_134 , 0xffffffff ) ;
F_33 ( V_2 , V_134 , 0xffffffff ) ;
V_116 = F_42 ( V_108 -> V_119 , V_101 , F_46 ,
F_47 ,
V_131 , L_5 , V_108 ) ;
if ( V_116 < 0 ) {
F_43 ( L_6 ) ;
return V_116 ;
}
F_44 ( V_2 , V_134 ,
V_2 -> V_15 . V_133 . V_126 ) ;
return 0 ;
}
void F_49 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_1 * V_2 = V_110 -> V_119 ;
F_41 ( V_2 , V_134 ,
V_2 -> V_15 . V_133 . V_126 ) ;
}
