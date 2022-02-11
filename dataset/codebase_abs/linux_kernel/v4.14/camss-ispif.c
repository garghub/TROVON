static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 , V_6 , V_7 ;
V_5 = F_2 ( V_4 -> V_8 + F_3 ( 0 ) ) ;
V_6 = F_2 ( V_4 -> V_8 + F_4 ( 0 ) ) ;
V_7 = F_2 ( V_4 -> V_8 + F_5 ( 0 ) ) ;
F_6 ( V_5 , V_4 -> V_8 + F_7 ( 0 ) ) ;
F_6 ( V_6 , V_4 -> V_8 + F_8 ( 0 ) ) ;
F_6 ( V_7 , V_4 -> V_8 + F_9 ( 0 ) ) ;
F_10 ( 0x1 , V_4 -> V_8 + V_9 ) ;
if ( ( V_5 >> 27 ) & 0x1 )
F_11 ( & V_4 -> V_10 ) ;
if ( F_12 ( V_5 & V_11 ) )
F_13 ( F_14 ( V_4 ) , L_1 ) ;
if ( F_12 ( V_5 & V_12 ) )
F_13 ( F_14 ( V_4 ) , L_2 ) ;
if ( F_12 ( V_6 & V_13 ) )
F_13 ( F_14 ( V_4 ) , L_3 ) ;
if ( F_12 ( V_6 & V_14 ) )
F_13 ( F_14 ( V_4 ) , L_4 ) ;
if ( F_12 ( V_7 & V_15 ) )
F_13 ( F_14 ( V_4 ) , L_5 ) ;
return V_16 ;
}
static int F_15 ( struct V_3 * V_4 )
{
unsigned long time ;
T_2 V_17 ;
int V_18 ;
V_18 = F_16 ( V_4 -> V_19 ,
V_4 -> V_20 ,
F_14 ( V_4 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_17 ( & V_4 -> V_10 ) ;
V_17 = V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 ;
F_6 ( V_17 , V_4 -> V_8 + V_38 ) ;
time = F_18 ( & V_4 -> V_10 ,
F_19 ( V_39 ) ) ;
if ( ! time ) {
F_20 ( F_14 ( V_4 ) , L_6 ) ;
return - V_40 ;
}
F_21 ( V_4 -> V_19 , V_4 -> V_20 ) ;
return 0 ;
}
static int F_22 ( struct V_41 * V_42 , int V_43 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_3 * V_4 = F_24 ( line ) ;
struct V_45 * V_2 = F_14 ( V_4 ) ;
int V_18 = 0 ;
F_25 ( & V_4 -> V_46 ) ;
if ( V_43 ) {
if ( V_4 -> V_47 ) {
V_4 -> V_47 ++ ;
goto exit;
}
V_18 = F_16 ( V_4 -> V_48 , V_4 -> clock , V_2 ) ;
if ( V_18 < 0 )
goto exit;
V_18 = F_15 ( V_4 ) ;
if ( V_18 < 0 ) {
F_21 ( V_4 -> V_48 , V_4 -> clock ) ;
goto exit;
}
V_4 -> V_49 [ line -> V_50 ] . V_51 = V_52 ;
V_4 -> V_49 [ line -> V_50 ] . V_53 = V_52 ;
V_4 -> V_47 ++ ;
} else {
if ( V_4 -> V_47 == 0 ) {
F_20 ( V_2 , L_7 ) ;
goto exit;
} else if ( V_4 -> V_47 == 1 ) {
F_21 ( V_4 -> V_48 , V_4 -> clock ) ;
}
V_4 -> V_47 -- ;
}
exit:
F_26 ( & V_4 -> V_46 ) ;
return V_18 ;
}
static void F_27 ( struct V_3 * V_4 ,
enum V_54 V_55 , T_3 V_56 ,
T_3 V_57 , T_3 V_58 )
{
T_2 V_17 ;
switch ( V_55 ) {
case V_59 :
V_17 = F_2 ( V_4 -> V_60 + V_61 ) ;
V_17 &= ~ ( 0xf << ( V_57 * 8 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << ( V_57 * 8 ) ) ;
F_6 ( V_17 , V_4 -> V_60 + V_61 ) ;
break;
case V_62 :
V_17 = F_2 ( V_4 -> V_60 + V_63 ) ;
V_17 &= ~ ( 0xf << ( V_57 * 12 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << ( V_57 * 12 ) ) ;
F_6 ( V_17 , V_4 -> V_60 + V_63 ) ;
break;
case V_64 :
V_17 = F_2 ( V_4 -> V_60 + V_61 ) ;
V_17 &= ~ ( 0xf << ( 4 + ( V_57 * 8 ) ) ) ;
if ( V_58 )
V_17 |= ( V_56 << ( 4 + ( V_57 * 8 ) ) ) ;
F_6 ( V_17 , V_4 -> V_60 + V_61 ) ;
break;
case V_65 :
V_17 = F_2 ( V_4 -> V_60 + V_63 ) ;
V_17 &= ~ ( 0xf << ( 4 + ( V_57 * 12 ) ) ) ;
if ( V_58 )
V_17 |= ( V_56 << ( 4 + ( V_57 * 12 ) ) ) ;
F_6 ( V_17 , V_4 -> V_60 + V_63 ) ;
break;
case V_66 :
V_17 = F_2 ( V_4 -> V_60 + V_63 ) ;
V_17 &= ~ ( 0xf << ( 8 + ( V_57 * 12 ) ) ) ;
if ( V_58 )
V_17 |= ( V_56 << ( 8 + ( V_57 * 12 ) ) ) ;
F_6 ( V_17 , V_4 -> V_60 + V_63 ) ;
break;
}
F_28 () ;
}
static int F_29 ( struct V_3 * V_4 ,
enum V_54 V_55 , T_3 V_57 )
{
int V_18 = 0 ;
T_2 V_17 = 0 ;
switch ( V_55 ) {
case V_59 :
V_17 = F_2 ( V_4 -> V_8 +
F_30 ( V_57 , 0 ) ) ;
break;
case V_62 :
V_17 = F_2 ( V_4 -> V_8 +
F_31 ( V_57 , 0 ) ) ;
break;
case V_64 :
V_17 = F_2 ( V_4 -> V_8 +
F_30 ( V_57 , 1 ) ) ;
break;
case V_65 :
V_17 = F_2 ( V_4 -> V_8 +
F_31 ( V_57 , 1 ) ) ;
break;
case V_66 :
V_17 = F_2 ( V_4 -> V_8 +
F_31 ( V_57 , 2 ) ) ;
break;
}
if ( ( V_17 & 0xf ) != 0xf ) {
F_20 ( F_14 ( V_4 ) , L_8 ,
V_67 , V_17 ) ;
V_18 = - V_68 ;
}
return V_18 ;
}
static int F_32 ( struct V_3 * V_4 ,
enum V_54 V_55 , T_3 V_57 )
{
T_2 V_69 = 0 ;
T_2 V_70 = 0 ;
int V_18 ;
switch ( V_55 ) {
case V_59 :
V_69 = F_30 ( V_57 , 0 ) ;
break;
case V_62 :
V_69 = F_31 ( V_57 , 0 ) ;
break;
case V_64 :
V_69 = F_30 ( V_57 , 1 ) ;
break;
case V_65 :
V_69 = F_31 ( V_57 , 1 ) ;
break;
case V_66 :
V_69 = F_31 ( V_57 , 2 ) ;
break;
}
V_18 = F_33 ( V_4 -> V_8 + V_69 ,
V_70 ,
( V_70 & 0xf ) == 0xf ,
V_71 ,
V_72 ) ;
if ( V_18 < 0 )
F_20 ( F_14 ( V_4 ) , L_9 ,
V_67 ) ;
return V_18 ;
}
static void F_34 ( struct V_3 * V_4 , enum V_54 V_55 ,
T_3 V_56 , T_3 V_57 , T_3 V_58 )
{
T_2 V_17 ;
V_17 = F_2 ( V_4 -> V_8 + F_35 ( V_57 ) ) ;
switch ( V_55 ) {
case V_59 :
V_17 &= ~ ( F_36 ( 1 ) | F_36 ( 0 ) ) ;
if ( V_58 )
V_17 |= V_56 ;
break;
case V_62 :
V_17 &= ~ ( F_36 ( 5 ) | F_36 ( 4 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << 4 ) ;
break;
case V_64 :
V_17 &= ~ ( F_36 ( 9 ) | F_36 ( 8 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << 8 ) ;
break;
case V_65 :
V_17 &= ~ ( F_36 ( 13 ) | F_36 ( 12 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << 12 ) ;
break;
case V_66 :
V_17 &= ~ ( F_36 ( 21 ) | F_36 ( 20 ) ) ;
if ( V_58 )
V_17 |= ( V_56 << 20 ) ;
break;
}
F_10 ( V_17 , V_4 -> V_8 + F_35 ( V_57 ) ) ;
}
static void F_37 ( struct V_3 * V_4 , enum V_54 V_55 ,
T_3 V_73 , T_3 V_57 , T_3 V_58 )
{
T_2 V_74 = 1 << V_73 ;
T_2 V_69 = 0 ;
T_2 V_17 ;
switch ( V_55 ) {
case V_59 :
V_69 = F_38 ( V_57 , 0 ) ;
break;
case V_62 :
V_69 = F_39 ( V_57 , 0 ) ;
break;
case V_64 :
V_69 = F_38 ( V_57 , 1 ) ;
break;
case V_65 :
V_69 = F_39 ( V_57 , 1 ) ;
break;
case V_66 :
V_69 = F_39 ( V_57 , 2 ) ;
break;
}
V_17 = F_2 ( V_4 -> V_8 + V_69 ) ;
if ( V_58 )
V_17 |= V_74 ;
else
V_17 &= ~ V_74 ;
F_10 ( V_17 , V_4 -> V_8 + V_69 ) ;
}
static void F_40 ( struct V_3 * V_4 , enum V_54 V_55 ,
T_3 V_57 , T_3 V_58 )
{
T_2 V_17 ;
switch ( V_55 ) {
case V_59 :
V_17 = F_2 ( V_4 -> V_8 + F_41 ( V_57 ) ) ;
V_17 &= ~ V_75 ;
if ( V_58 )
V_17 |= V_76 ;
F_6 ( V_17 , V_4 -> V_8 + F_41 ( V_57 ) ) ;
F_6 ( V_76 ,
V_4 -> V_8 + F_7 ( V_57 ) ) ;
break;
case V_62 :
V_17 = F_2 ( V_4 -> V_8 + F_41 ( V_57 ) ) ;
V_17 &= ~ V_77 ;
if ( V_58 )
V_17 |= V_78 ;
F_6 ( V_17 , V_4 -> V_8 + F_41 ( V_57 ) ) ;
F_6 ( V_78 ,
V_4 -> V_8 + F_7 ( V_57 ) ) ;
break;
case V_64 :
V_17 = F_2 ( V_4 -> V_8 + F_42 ( V_57 ) ) ;
V_17 &= ~ V_79 ;
if ( V_58 )
V_17 |= V_80 ;
F_6 ( V_17 , V_4 -> V_8 + F_42 ( V_57 ) ) ;
F_6 ( V_80 ,
V_4 -> V_8 + F_8 ( V_57 ) ) ;
break;
case V_65 :
V_17 = F_2 ( V_4 -> V_8 + F_42 ( V_57 ) ) ;
V_17 &= ~ V_81 ;
if ( V_58 )
V_17 |= V_82 ;
F_6 ( V_17 , V_4 -> V_8 + F_42 ( V_57 ) ) ;
F_6 ( V_82 ,
V_4 -> V_8 + F_8 ( V_57 ) ) ;
break;
case V_66 :
V_17 = F_2 ( V_4 -> V_8 + F_43 ( V_57 ) ) ;
V_17 &= ~ V_83 ;
if ( V_58 )
V_17 |= V_84 ;
F_6 ( V_17 , V_4 -> V_8 + F_43 ( V_57 ) ) ;
F_6 ( V_84 ,
V_4 -> V_8 + F_9 ( V_57 ) ) ;
break;
}
F_10 ( 0x1 , V_4 -> V_8 + V_9 ) ;
}
static void F_44 ( struct V_3 * V_4 , T_3 V_85 ,
enum V_54 V_55 , T_3 V_57 , T_3 V_86 )
{
T_2 * V_17 ;
if ( V_55 == V_66 ) {
V_17 = & V_4 -> V_49 [ V_57 ] . V_53 ;
* V_17 &= ~ ( 0x3 << ( V_86 * 2 + 8 ) ) ;
* V_17 |= ( V_85 << ( V_86 * 2 + 8 ) ) ;
F_45 () ;
F_6 ( * V_17 , V_4 -> V_8 + F_46 ( V_57 ) ) ;
F_45 () ;
} else {
V_17 = & V_4 -> V_49 [ V_57 ] . V_51 ;
* V_17 &= ~ ( 0x3 << ( V_86 * 2 + V_55 * 8 ) ) ;
* V_17 |= ( V_85 << ( V_86 * 2 + V_55 * 8 ) ) ;
F_45 () ;
F_6 ( * V_17 , V_4 -> V_8 + F_47 ( V_57 ) ) ;
F_45 () ;
}
}
static int F_48 ( struct V_41 * V_42 , int V_58 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_3 * V_4 = F_24 ( line ) ;
enum V_54 V_55 = line -> V_87 ;
T_3 V_56 = line -> V_88 ;
T_3 V_57 = line -> V_50 ;
T_3 V_86 = 0 ;
T_3 V_73 = V_86 * 4 ;
int V_18 ;
if ( V_58 ) {
if ( ! F_49 ( & line -> V_89 [ V_90 ] ) )
return - V_91 ;
F_25 ( & V_4 -> V_92 ) ;
F_27 ( V_4 , V_55 , V_56 , V_57 , 1 ) ;
V_18 = F_29 ( V_4 , V_55 , V_57 ) ;
if ( V_18 < 0 ) {
F_26 ( & V_4 -> V_92 ) ;
return V_18 ;
}
F_34 ( V_4 , V_55 , V_56 , V_57 , 1 ) ;
F_37 ( V_4 , V_55 , V_73 , V_57 , 1 ) ;
F_40 ( V_4 , V_55 , V_57 , 1 ) ;
F_44 ( V_4 , V_93 ,
V_55 , V_57 , V_86 ) ;
} else {
F_25 ( & V_4 -> V_92 ) ;
F_44 ( V_4 , V_94 ,
V_55 , V_57 , V_86 ) ;
F_26 ( & V_4 -> V_92 ) ;
V_18 = F_32 ( V_4 , V_55 , V_57 ) ;
if ( V_18 < 0 )
return V_18 ;
F_25 ( & V_4 -> V_92 ) ;
F_40 ( V_4 , V_55 , V_57 , 0 ) ;
F_37 ( V_4 , V_55 , V_73 , V_57 , 0 ) ;
F_34 ( V_4 , V_55 , V_56 , V_57 , 0 ) ;
F_27 ( V_4 , V_55 , V_56 , V_57 , 0 ) ;
}
F_26 ( & V_4 -> V_92 ) ;
return 0 ;
}
static struct V_95 *
F_50 ( struct V_44 * line ,
struct V_96 * V_97 ,
unsigned int V_98 ,
enum V_99 V_100 )
{
if ( V_100 == V_101 )
return F_51 ( & line -> V_102 , V_97 , V_98 ) ;
return & line -> V_103 [ V_98 ] ;
}
static void F_52 ( struct V_44 * line ,
struct V_96 * V_97 ,
unsigned int V_98 ,
struct V_95 * V_103 ,
enum V_99 V_100 )
{
unsigned int V_104 ;
switch ( V_98 ) {
case V_90 :
for ( V_104 = 0 ; V_104 < F_53 ( V_105 ) ; V_104 ++ )
if ( V_103 -> V_106 == V_105 [ V_104 ] )
break;
if ( V_104 >= F_53 ( V_105 ) )
V_103 -> V_106 = V_107 ;
V_103 -> V_108 = F_54 ( T_2 , V_103 -> V_108 , 1 , 8191 ) ;
V_103 -> V_109 = F_54 ( T_2 , V_103 -> V_109 , 1 , 8191 ) ;
V_103 -> V_110 = V_111 ;
V_103 -> V_112 = V_113 ;
break;
case V_114 :
* V_103 = * F_50 ( line , V_97 , V_90 ,
V_100 ) ;
break;
}
V_103 -> V_112 = V_113 ;
}
static int F_55 ( struct V_41 * V_42 ,
struct V_96 * V_97 ,
struct V_115 * V_106 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_95 * V_116 ;
if ( V_106 -> V_98 == V_90 ) {
if ( V_106 -> V_117 >= F_53 ( V_105 ) )
return - V_118 ;
V_106 -> V_106 = V_105 [ V_106 -> V_117 ] ;
} else {
if ( V_106 -> V_117 > 0 )
return - V_118 ;
V_116 = F_50 ( line , V_97 , V_90 ,
V_106 -> V_100 ) ;
V_106 -> V_106 = V_116 -> V_106 ;
}
return 0 ;
}
static int F_56 ( struct V_41 * V_42 ,
struct V_96 * V_97 ,
struct V_119 * V_120 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_95 V_116 ;
if ( V_120 -> V_117 != 0 )
return - V_118 ;
V_116 . V_106 = V_120 -> V_106 ;
V_116 . V_108 = 1 ;
V_116 . V_109 = 1 ;
F_52 ( line , V_97 , V_120 -> V_98 , & V_116 , V_120 -> V_100 ) ;
V_120 -> V_121 = V_116 . V_108 ;
V_120 -> V_122 = V_116 . V_109 ;
if ( V_116 . V_106 != V_120 -> V_106 )
return - V_118 ;
V_116 . V_106 = V_120 -> V_106 ;
V_116 . V_108 = - 1 ;
V_116 . V_109 = - 1 ;
F_52 ( line , V_97 , V_120 -> V_98 , & V_116 , V_120 -> V_100 ) ;
V_120 -> V_123 = V_116 . V_108 ;
V_120 -> V_124 = V_116 . V_109 ;
return 0 ;
}
static int F_57 ( struct V_41 * V_42 ,
struct V_96 * V_97 ,
struct V_125 * V_103 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_95 * V_116 ;
V_116 = F_50 ( line , V_97 , V_103 -> V_98 , V_103 -> V_100 ) ;
if ( V_116 == NULL )
return - V_118 ;
V_103 -> V_116 = * V_116 ;
return 0 ;
}
static int F_58 ( struct V_41 * V_42 ,
struct V_96 * V_97 ,
struct V_125 * V_103 )
{
struct V_44 * line = F_23 ( V_42 ) ;
struct V_95 * V_116 ;
V_116 = F_50 ( line , V_97 , V_103 -> V_98 , V_103 -> V_100 ) ;
if ( V_116 == NULL )
return - V_118 ;
F_52 ( line , V_97 , V_103 -> V_98 , & V_103 -> V_116 , V_103 -> V_100 ) ;
* V_116 = V_103 -> V_116 ;
if ( V_103 -> V_98 == V_90 ) {
V_116 = F_50 ( line , V_97 , V_114 ,
V_103 -> V_100 ) ;
* V_116 = V_103 -> V_116 ;
F_52 ( line , V_97 , V_114 , V_116 ,
V_103 -> V_100 ) ;
}
return 0 ;
}
static int F_59 ( struct V_41 * V_42 , struct V_126 * V_127 )
{
struct V_125 V_116 = {
. V_98 = V_90 ,
. V_100 = V_127 ? V_101 :
V_128 ,
. V_116 = {
. V_106 = V_107 ,
. V_108 = 1920 ,
. V_109 = 1080
}
} ;
return F_58 ( V_42 , V_127 ? V_127 -> V_98 : NULL , & V_116 ) ;
}
int F_60 ( struct V_3 * V_4 ,
const struct V_129 * V_130 )
{
struct V_45 * V_2 = F_14 ( V_4 ) ;
struct V_131 * V_132 = F_61 ( V_2 ) ;
struct V_133 * V_134 ;
int V_104 ;
int V_18 ;
V_134 = F_62 ( V_132 , V_135 , V_130 -> V_136 [ 0 ] ) ;
V_4 -> V_8 = F_63 ( V_2 , V_134 ) ;
if ( F_64 ( V_4 -> V_8 ) ) {
F_20 ( V_2 , L_10 ) ;
return F_65 ( V_4 -> V_8 ) ;
}
V_134 = F_62 ( V_132 , V_135 , V_130 -> V_136 [ 1 ] ) ;
V_4 -> V_60 = F_63 ( V_2 , V_134 ) ;
if ( F_64 ( V_4 -> V_60 ) ) {
F_20 ( V_2 , L_10 ) ;
return F_65 ( V_4 -> V_60 ) ;
}
V_134 = F_62 ( V_132 , V_137 , V_130 -> V_138 ) ;
if ( ! V_134 ) {
F_20 ( V_2 , L_11 ) ;
return - V_118 ;
}
V_4 -> V_1 = V_134 -> V_139 ;
snprintf ( V_4 -> V_140 , sizeof( V_4 -> V_140 ) , L_12 ,
F_66 ( V_2 ) , V_141 ) ;
V_18 = F_67 ( V_2 , V_4 -> V_1 , F_1 ,
V_142 , V_4 -> V_140 , V_4 ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , L_13 , V_18 ) ;
return V_18 ;
}
V_4 -> V_48 = 0 ;
while ( V_130 -> clock [ V_4 -> V_48 ] )
V_4 -> V_48 ++ ;
V_4 -> clock = F_68 ( V_2 , V_4 -> V_48 * sizeof( * V_4 -> clock ) ,
V_143 ) ;
if ( ! V_4 -> clock )
return - V_144 ;
for ( V_104 = 0 ; V_104 < V_4 -> V_48 ; V_104 ++ ) {
struct V_145 * clock = & V_4 -> clock [ V_104 ] ;
clock -> V_146 = F_69 ( V_2 , V_130 -> clock [ V_104 ] ) ;
if ( F_64 ( clock -> V_146 ) )
return F_65 ( clock -> V_146 ) ;
clock -> V_147 = NULL ;
clock -> V_148 = 0 ;
}
V_4 -> V_19 = 0 ;
while ( V_130 -> V_20 [ V_4 -> V_19 ] )
V_4 -> V_19 ++ ;
V_4 -> V_20 = F_68 ( V_2 , V_4 -> V_19 *
sizeof( * V_4 -> V_20 ) , V_143 ) ;
if ( ! V_4 -> V_20 )
return - V_144 ;
for ( V_104 = 0 ; V_104 < V_4 -> V_19 ; V_104 ++ ) {
struct V_145 * clock = & V_4 -> V_20 [ V_104 ] ;
clock -> V_146 = F_69 ( V_2 , V_130 -> V_20 [ V_104 ] ) ;
if ( F_64 ( clock -> V_146 ) )
return F_65 ( clock -> V_146 ) ;
clock -> V_147 = NULL ;
clock -> V_148 = 0 ;
}
for ( V_104 = 0 ; V_104 < F_53 ( V_4 -> line ) ; V_104 ++ )
V_4 -> line [ V_104 ] . V_149 = V_104 ;
F_70 ( & V_4 -> V_46 ) ;
V_4 -> V_47 = 0 ;
F_70 ( & V_4 -> V_92 ) ;
F_71 ( & V_4 -> V_10 ) ;
return 0 ;
}
static enum V_54 F_72 ( enum V_150 V_151 )
{
switch ( V_151 ) {
case ( V_152 ) :
return V_62 ;
case ( V_153 ) :
return V_65 ;
case ( V_154 ) :
return V_66 ;
case ( V_155 ) :
return V_59 ;
default:
return V_62 ;
}
}
static int F_73 ( struct V_156 * V_157 ,
const struct V_158 * V_159 ,
const struct V_158 * V_160 , T_2 V_161 )
{
if ( V_161 & V_162 ) {
if ( F_49 ( V_159 ) )
return - V_68 ;
if ( V_159 -> V_161 & V_163 ) {
struct V_41 * V_42 ;
struct V_44 * line ;
V_42 = F_74 ( V_157 ) ;
line = F_23 ( V_42 ) ;
F_75 ( V_160 -> V_157 , & line -> V_88 ) ;
} else {
struct V_41 * V_42 ;
struct V_44 * line ;
enum V_150 V_149 ;
V_42 = F_74 ( V_157 ) ;
line = F_23 ( V_42 ) ;
F_76 ( V_160 -> V_157 , & line -> V_50 ) ;
F_77 ( V_160 -> V_157 , & V_149 ) ;
line -> V_87 = F_72 ( V_149 ) ;
}
}
return 0 ;
}
int F_78 ( struct V_3 * V_4 ,
struct V_164 * V_165 )
{
struct V_45 * V_2 = F_14 ( V_4 ) ;
int V_18 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < F_53 ( V_4 -> line ) ; V_104 ++ ) {
struct V_41 * V_42 = & V_4 -> line [ V_104 ] . V_102 ;
struct V_158 * V_89 = V_4 -> line [ V_104 ] . V_89 ;
F_79 ( V_42 , & V_166 ) ;
V_42 -> V_167 = & V_168 ;
V_42 -> V_161 |= V_169 ;
snprintf ( V_42 -> V_170 , F_53 ( V_42 -> V_170 ) , L_14 ,
V_141 , V_104 ) ;
F_80 ( V_42 , & V_4 -> line [ V_104 ] ) ;
V_18 = F_59 ( V_42 , NULL ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , L_15 , V_18 ) ;
goto error;
}
V_89 [ V_90 ] . V_161 = V_163 ;
V_89 [ V_114 ] . V_161 = V_171 ;
V_42 -> V_157 . V_172 = V_173 ;
V_42 -> V_157 . V_174 = & V_175 ;
V_18 = F_81 ( & V_42 -> V_157 , V_176 ,
V_89 ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , L_16 , V_18 ) ;
goto error;
}
V_18 = F_82 ( V_165 , V_42 ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , L_17 , V_18 ) ;
F_83 ( & V_42 -> V_157 ) ;
goto error;
}
}
return 0 ;
error:
for ( V_104 -- ; V_104 >= 0 ; V_104 -- ) {
struct V_41 * V_42 = & V_4 -> line [ V_104 ] . V_102 ;
F_84 ( V_42 ) ;
F_83 ( & V_42 -> V_157 ) ;
}
return V_18 ;
}
void F_85 ( struct V_3 * V_4 )
{
int V_104 ;
F_86 ( & V_4 -> V_46 ) ;
F_86 ( & V_4 -> V_92 ) ;
for ( V_104 = 0 ; V_104 < F_53 ( V_4 -> line ) ; V_104 ++ ) {
struct V_41 * V_42 = & V_4 -> line [ V_104 ] . V_102 ;
F_84 ( V_42 ) ;
F_83 ( & V_42 -> V_157 ) ;
}
}
