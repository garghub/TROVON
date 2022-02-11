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
F_8 ( V_2 , V_18 , V_19 ) ;
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
if ( ( V_52 == V_53 ) || ( V_52 == V_54 ) )
return - V_55 ;
return V_50 * F_22 ( V_52 , 0 ) * 8 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_56 ) ;
T_2 V_57 = ( V_3 >> 4 ) & 0x3 , V_58 ;
V_2 -> V_6 = 2 ;
switch ( V_57 ) {
case 0 :
V_2 -> V_7 = V_8 ;
V_58 = 64 ;
break;
case 1 :
V_2 -> V_7 = V_59 ;
V_58 = 128 ;
break;
case 2 :
V_2 -> V_7 = 1280 ;
V_58 = 40 ;
break;
case 3 :
V_2 -> V_7 = 0 ;
return - V_55 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_58 * V_10 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_4 ( V_2 , V_60 , V_61 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_60 ) == V_60 )
break;
F_5 ( 1000 , 10000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_1 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_8 ( V_2 , V_18 , V_62 ) ;
F_8 ( V_2 , V_60 , V_61 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_60 ) == 0 )
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
if ( ( V_11 & V_60 ) == V_60 )
return true ;
return false ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_18 , V_62 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = V_29 ;
F_12 ( V_2 , V_22 , V_63 ) ;
V_22 = ( ( ( V_31 >> 4 ) & 0xff ) << 16 ) |
( ( ( V_30 >> 4 ) & 0xff ) << 8 ) |
( ( V_33 >> 4 ) & 0xff ) ;
F_12 ( V_2 , V_22 , V_64 ) ;
V_22 = F_13 ( V_21 -> V_34 ) |
F_14 ( V_21 -> V_35 ) ;
F_12 ( V_2 , V_22 , V_65 + V_37 ) ;
V_22 = F_29 ( V_21 -> V_38 ) |
F_16 ( V_21 -> V_39 ) ;
F_12 ( V_2 , V_22 , V_65 + V_40 ) ;
V_22 = F_17 ( V_21 -> V_41 ) |
F_18 ( V_21 -> V_42 ) ;
if ( V_21 -> V_24 & V_25 )
V_22 |= V_66 ;
if ( V_21 -> V_24 & V_27 )
V_22 |= V_67 ;
F_12 ( V_2 , V_22 , V_65 + V_43 ) ;
V_22 = F_19 ( V_21 -> V_44 ) | F_20 ( V_21 -> V_45 ) ;
F_12 ( V_2 , V_22 , V_65 + V_46 ) ;
if ( V_21 -> V_24 & V_47 )
F_4 ( V_2 , V_48 , V_49 ) ;
else
F_8 ( V_2 , V_48 , V_49 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_50 , T_3 V_51 , T_1 V_52 )
{
T_1 V_68 ;
if ( ( V_52 == V_53 ) || ( V_52 == V_54 ) )
return - V_55 ;
switch ( V_52 ) {
case V_69 :
case V_70 :
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
case V_53 :
case V_54 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_68 = 32 ;
break;
case V_87 :
case V_88 :
V_68 = 24 ;
break;
default:
return - V_55 ;
}
return V_50 * V_68 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_56 ) ;
T_2 V_57 = ( V_3 >> 4 ) & 0x3 , V_58 ;
V_2 -> V_6 = 4 ;
switch ( V_57 ) {
case 0 :
case 2 :
V_2 -> V_7 = 0 ;
return - V_55 ;
case 1 :
V_2 -> V_7 = V_59 ;
V_58 = 128 ;
break;
case 3 :
V_2 -> V_7 = 2560 ;
V_58 = 80 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_58 * V_10 ;
return 0 ;
}
T_2 F_32 ( const struct V_89 * V_15 ,
T_2 V_90 , T_1 V_91 )
{
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < V_15 -> V_93 ; V_92 ++ ) {
if ( ( ( V_15 -> V_94 [ V_92 ] . V_95 & V_90 ) == V_90 ) &&
( V_15 -> V_94 [ V_92 ] . V_91 == V_91 ) )
return V_15 -> V_94 [ V_92 ] . V_96 ;
}
return V_97 ;
}
static void F_33 ( struct V_1 * V_2 , T_2 V_98 , T_1 V_99 )
{
T_1 V_100 = F_34 ( V_2 , V_98 ) ;
if ( V_2 -> V_15 . V_101 & V_102 )
F_12 ( V_2 , V_99 , V_100 + V_103 ) ;
else
F_12 ( V_2 , V_99 , V_100 + V_17 ) ;
}
static T_4 F_35 ( int V_99 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 ;
const struct V_110 * V_111 ;
T_1 V_11 , V_112 , V_113 ;
T_4 V_114 = V_115 ;
if ( ! V_106 -> V_109 )
return V_116 ;
V_2 = V_108 -> V_117 ;
V_111 = & V_2 -> V_15 . V_118 ;
V_113 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( V_113 & V_2 -> V_15 . V_119 . V_120 ) {
F_36 ( & V_108 -> V_121 , 1 ) ;
F_33 ( V_2 , V_122 , V_113 ) ;
V_114 = V_123 ;
}
V_11 = F_2 ( V_2 , V_17 ) ;
if ( ! ( V_11 & V_111 -> V_124 ) )
return V_114 ;
V_112 = F_2 ( V_2 , V_125 ) ;
V_11 &= V_112 ;
if ( V_11 & V_111 -> V_120 )
F_37 ( & V_108 -> V_126 ) ;
F_33 ( V_2 , V_127 , V_11 ) ;
return ( V_114 == V_115 ) ? V_116 : V_114 ;
}
static T_4 F_38 ( int V_99 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_107 * V_108 = V_106 -> V_109 ;
F_39 ( & V_108 -> V_128 ) ;
return V_116 ;
}
int F_40 ( struct V_105 * V_106 , int V_99 )
{
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_117 ;
int V_114 ;
F_41 ( V_2 , V_127 , 0xffffffff ) ;
F_33 ( V_2 , V_127 , 0xffffffff ) ;
F_41 ( V_2 , V_122 , 0xffffffff ) ;
F_33 ( V_2 , V_122 , 0xffffffff ) ;
V_114 = F_42 ( V_106 -> V_117 , V_99 , F_35 ,
F_38 ,
V_129 , L_3 , V_106 ) ;
if ( V_114 < 0 ) {
F_43 ( L_4 ) ;
return V_114 ;
}
F_44 ( V_2 , V_122 ,
V_2 -> V_15 . V_119 . V_124 ) ;
F_44 ( V_2 , V_127 ,
V_2 -> V_15 . V_118 . V_124 ) ;
return 0 ;
}
void F_45 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_117 ;
F_41 ( V_2 , V_127 ,
V_2 -> V_15 . V_118 . V_124 ) ;
F_41 ( V_2 , V_122 ,
V_2 -> V_15 . V_119 . V_124 ) ;
}
static T_4 F_46 ( int V_99 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_117 ;
T_1 V_11 , V_112 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_130 + V_17 ) ;
if ( ! ( V_11 & V_2 -> V_15 . V_131 . V_124 ) )
return V_115 ;
V_112 = F_2 ( V_2 , V_2 -> V_15 . V_130 + V_125 ) ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_130 + V_17 ) ;
V_11 &= V_112 ;
F_33 ( V_2 , V_132 , V_11 ) ;
return V_116 ;
}
static T_4 F_47 ( int V_99 , void * V_104 )
{
return V_116 ;
}
int F_48 ( struct V_105 * V_106 , int V_99 )
{
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_117 ;
int V_114 ;
F_41 ( V_2 , V_132 , 0xffffffff ) ;
F_33 ( V_2 , V_132 , 0xffffffff ) ;
V_114 = F_42 ( V_106 -> V_117 , V_99 , F_46 ,
F_47 ,
V_129 , L_5 , V_106 ) ;
if ( V_114 < 0 ) {
F_43 ( L_6 ) ;
return V_114 ;
}
F_44 ( V_2 , V_132 ,
V_2 -> V_15 . V_131 . V_124 ) ;
return 0 ;
}
void F_49 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_109 ;
struct V_1 * V_2 = V_108 -> V_117 ;
F_41 ( V_2 , V_132 ,
V_2 -> V_15 . V_131 . V_124 ) ;
}
