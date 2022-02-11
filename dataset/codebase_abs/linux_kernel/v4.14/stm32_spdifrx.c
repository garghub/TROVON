static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 * V_6 = ( T_1 * ) V_3 -> V_7 -> V_8 ;
T_1 * V_9 = V_6 + ( 2 * V_10 ) - 1 ;
T_1 * V_11 = V_6 ;
T_2 * V_12 = ( short * ) V_3 -> V_13 ;
int V_14 = 0 ;
F_2 ( V_3 -> V_15 , V_16 ,
V_17 ,
( unsigned int ) ~ V_17 ) ;
if ( ! V_3 -> V_7 -> V_8 )
return;
while ( V_11 <= V_9 ) {
if ( * V_11 & V_18 )
break;
V_11 ++ ;
}
if ( V_11 > V_9 ) {
F_3 ( & V_5 -> V_19 , L_1 ) ;
return;
}
while ( V_14 < V_10 ) {
V_3 -> V_20 [ V_14 ] = ( unsigned char ) F_4 ( * V_11 ) ;
* V_12 ++ = F_5 ( * V_11 ++ ) ;
if ( V_11 > V_9 ) {
F_3 ( & V_5 -> V_19 , L_2 ) ;
return;
}
V_14 ++ ;
}
F_6 ( & V_3 -> V_21 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
T_3 V_22 ;
int V_23 ;
V_3 -> V_24 = F_8 ( V_3 -> V_25 ,
V_3 -> V_7 -> V_26 ,
V_27 ,
V_28 ,
V_29 ) ;
if ( ! V_3 -> V_24 )
return - V_30 ;
V_3 -> V_24 -> V_31 = F_1 ;
V_3 -> V_24 -> V_32 = V_3 ;
V_22 = F_9 ( V_3 -> V_24 ) ;
V_23 = F_10 ( V_22 ) ;
if ( V_23 )
return - V_30 ;
F_11 ( V_3 -> V_25 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_25 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
int V_33 , V_34 , V_35 , V_36 ;
V_35 = V_37 | V_38 | V_39 ;
V_36 = F_2 ( V_3 -> V_15 , V_40 , V_35 , V_35 ) ;
if ( V_36 )
return V_36 ;
F_15 ( & V_3 -> V_41 ) ;
V_3 -> V_42 ++ ;
F_16 ( V_3 -> V_15 , V_16 , & V_33 ) ;
if ( ! ( V_33 & V_43 ) ) {
F_17 ( & V_3 -> V_5 -> V_19 , L_3 ) ;
V_33 = V_44 | V_45 | V_46 |
V_47 | V_48 | V_49 ;
V_34 = V_33 ;
V_33 |= F_18 ( V_50 ) ;
V_34 |= V_43 ;
V_36 = F_2 ( V_3 -> V_15 , V_16 ,
V_34 , V_33 ) ;
if ( V_36 < 0 )
F_3 ( & V_3 -> V_5 -> V_19 ,
L_4 ) ;
}
F_19 ( & V_3 -> V_41 ) ;
return V_36 ;
}
static void F_20 ( struct V_2 * V_3 )
{
int V_33 , V_34 , V_51 ;
F_15 ( & V_3 -> V_41 ) ;
if ( -- V_3 -> V_42 ) {
F_19 ( & V_3 -> V_41 ) ;
return;
}
V_33 = F_18 ( V_52 ) ;
V_34 = V_43 | V_53 ;
F_2 ( V_3 -> V_15 , V_16 , V_34 , V_33 ) ;
F_2 ( V_3 -> V_15 , V_40 ,
V_54 , 0 ) ;
F_2 ( V_3 -> V_15 , V_55 ,
V_56 , V_56 ) ;
F_16 ( V_3 -> V_15 , V_57 , & V_51 ) ;
F_16 ( V_3 -> V_15 , V_58 , & V_51 ) ;
F_19 ( & V_3 -> V_41 ) ;
}
static int F_21 ( struct V_59 * V_19 ,
struct V_2 * V_3 )
{
int V_36 ;
V_3 -> V_7 = F_22 ( V_19 , sizeof( struct V_60 ) ,
V_61 ) ;
if ( ! V_3 -> V_7 )
return - V_62 ;
V_3 -> V_7 -> V_19 . type = V_63 ;
V_3 -> V_7 -> V_19 . V_19 = V_19 ;
V_36 = F_23 ( V_3 -> V_7 -> V_19 . type , V_19 ,
V_27 , V_3 -> V_7 ) ;
if ( V_36 < 0 ) {
F_3 ( V_19 , L_5 , V_36 ) ;
return V_36 ;
}
V_3 -> V_25 = F_24 ( V_19 , L_6 ) ;
if ( ! V_3 -> V_25 ) {
F_3 ( V_19 , L_7 ) ;
return - V_30 ;
}
V_3 -> V_64 . V_65 = V_28 ;
V_3 -> V_64 . V_66 = ( V_67 ) ( V_3 -> V_68 +
V_58 ) ;
V_3 -> V_64 . V_69 = V_3 -> V_7 -> V_26 ;
V_3 -> V_64 . V_70 = V_71 ;
V_3 -> V_64 . V_72 = 1 ;
V_36 = F_25 ( V_3 -> V_25 ,
& V_3 -> V_64 ) ;
if ( V_36 < 0 ) {
F_3 ( V_19 , L_8 , V_36 ) ;
F_26 ( V_3 -> V_25 ) ;
V_3 -> V_25 = NULL ;
}
return V_36 ;
}
static int F_27 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_78 = 1 ;
return 0 ;
}
static int F_28 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_78 = 1 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_36 = 0 ;
memset ( V_3 -> V_20 , 0 , V_10 ) ;
memset ( V_3 -> V_13 , 0 , V_79 ) ;
V_36 = F_7 ( V_3 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_30 ( V_3 -> V_80 ) ;
if ( V_36 ) {
F_3 ( & V_3 -> V_5 -> V_19 , L_9 , V_36 ) ;
return V_36 ;
}
V_36 = F_2 ( V_3 -> V_15 , V_16 ,
V_17 , V_17 ) ;
if ( V_36 < 0 )
goto V_81;
V_36 = F_14 ( V_3 ) ;
if ( V_36 < 0 )
goto V_81;
if ( F_31 ( & V_3 -> V_21 ,
F_32 ( 100 ) )
<= 0 ) {
F_3 ( & V_3 -> V_5 -> V_19 , L_10 ) ;
V_36 = - V_82 ;
}
F_20 ( V_3 ) ;
F_12 ( V_3 ) ;
V_81:
F_33 ( V_3 -> V_80 ) ;
return V_36 ;
}
static int F_34 ( struct V_73 * V_74 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 = F_35 ( V_74 ) ;
struct V_2 * V_3 = F_36 ( V_86 ) ;
F_29 ( V_3 ) ;
V_84 -> V_87 . V_88 . V_89 [ 0 ] = V_3 -> V_20 [ 0 ] ;
V_84 -> V_87 . V_88 . V_89 [ 1 ] = V_3 -> V_20 [ 1 ] ;
V_84 -> V_87 . V_88 . V_89 [ 2 ] = V_3 -> V_20 [ 2 ] ;
V_84 -> V_87 . V_88 . V_89 [ 3 ] = V_3 -> V_20 [ 3 ] ;
V_84 -> V_87 . V_88 . V_89 [ 4 ] = V_3 -> V_20 [ 4 ] ;
return 0 ;
}
static int F_37 ( struct V_73 * V_74 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 = F_35 ( V_74 ) ;
struct V_2 * V_3 = F_36 ( V_86 ) ;
F_29 ( V_3 ) ;
V_84 -> V_87 . V_88 . V_89 [ 0 ] = V_3 -> V_13 [ 0 ] ;
V_84 -> V_87 . V_88 . V_89 [ 1 ] = V_3 -> V_13 [ 1 ] ;
V_84 -> V_87 . V_88 . V_89 [ 2 ] = V_3 -> V_13 [ 2 ] ;
V_84 -> V_87 . V_88 . V_89 [ 3 ] = V_3 -> V_13 [ 3 ] ;
V_84 -> V_87 . V_88 . V_89 [ 4 ] = V_3 -> V_13 [ 4 ] ;
return 0 ;
}
static int F_38 ( struct V_85 * V_86 )
{
int V_36 ;
V_36 = F_39 ( V_86 , V_90 ,
F_40 ( V_90 ) ) ;
if ( V_36 < 0 )
return V_36 ;
return F_41 ( V_86 -> V_91 ,
V_92 ,
F_40 ( V_92 ) ) ;
}
static int F_42 ( struct V_85 * V_86 )
{
struct V_2 * V_3 = F_43 ( V_86 -> V_19 ) ;
V_3 -> V_93 . V_26 = ( V_67 ) ( V_3 -> V_68 +
V_57 ) ;
V_3 -> V_93 . V_94 = 1 ;
F_44 ( V_86 , NULL , & V_3 -> V_93 ) ;
return F_38 ( V_86 ) ;
}
static bool F_45 ( struct V_59 * V_19 , unsigned int V_51 )
{
switch ( V_51 ) {
case V_16 :
case V_40 :
case V_95 :
case V_55 :
case V_57 :
case V_58 :
case V_96 :
return true ;
default:
return false ;
}
}
static bool F_46 ( struct V_59 * V_19 , unsigned int V_51 )
{
if ( V_51 == V_57 )
return true ;
return false ;
}
static bool F_47 ( struct V_59 * V_19 , unsigned int V_51 )
{
switch ( V_51 ) {
case V_16 :
case V_40 :
case V_55 :
return true ;
default:
return false ;
}
}
static T_4 F_48 ( int V_97 , void * V_98 )
{
struct V_2 * V_3 = (struct V_2 * ) V_98 ;
struct V_99 * V_100 = V_3 -> V_100 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned int V_33 , V_101 , V_102 , V_35 ;
unsigned int V_103 ;
int V_23 = 0 , V_104 = 0 ;
F_16 ( V_3 -> V_15 , V_95 , & V_102 ) ;
F_16 ( V_3 -> V_15 , V_40 , & V_35 ) ;
V_101 = V_35 & V_54 ;
if ( V_101 & V_37 )
V_101 |= ( V_37 << 1 ) | ( V_37 << 2 ) ;
V_103 = V_102 & V_101 ;
if ( ! V_103 ) {
F_3 ( & V_5 -> V_19 , L_11 ,
V_102 , V_35 ) ;
return V_105 ;
}
F_2 ( V_3 -> V_15 , V_55 ,
V_56 , V_103 ) ;
if ( V_103 & V_106 ) {
F_17 ( & V_5 -> V_19 , L_12 ) ;
V_104 = 1 ;
}
if ( V_103 & V_107 ) {
F_17 ( & V_5 -> V_19 , L_13 ) ;
V_104 = 1 ;
}
if ( V_103 & V_108 )
F_17 ( & V_5 -> V_19 , L_14 ) ;
if ( V_103 & V_109 ) {
F_17 ( & V_5 -> V_19 , L_15 ) ;
V_33 = F_18 ( V_110 ) ;
F_2 ( V_3 -> V_15 , V_16 ,
V_43 , V_33 ) ;
}
if ( V_103 & V_111 ) {
F_17 ( & V_5 -> V_19 , L_16 ) ;
V_23 = 1 ;
}
if ( V_103 & V_112 ) {
F_17 ( & V_5 -> V_19 , L_17 ) ;
V_23 = 1 ;
}
if ( V_103 & V_113 ) {
F_17 ( & V_5 -> V_19 , L_18 ) ;
V_23 = 1 ;
}
if ( V_23 ) {
V_33 = F_18 ( V_52 ) ;
F_2 ( V_3 -> V_15 , V_16 ,
V_43 , V_33 ) ;
if ( V_100 )
F_49 ( V_100 , V_114 ) ;
return V_115 ;
}
if ( V_104 && V_100 )
F_50 ( V_100 ) ;
return V_115 ;
}
static int F_51 ( struct V_99 * V_100 ,
struct V_85 * V_86 )
{
struct V_2 * V_3 = F_36 ( V_86 ) ;
int V_36 ;
V_3 -> V_100 = V_100 ;
V_36 = F_30 ( V_3 -> V_80 ) ;
if ( V_36 )
F_3 ( & V_3 -> V_5 -> V_19 , L_9 , V_36 ) ;
return V_36 ;
}
static int F_52 ( struct V_99 * V_100 ,
struct V_116 * V_117 ,
struct V_85 * V_86 )
{
struct V_2 * V_3 = F_36 ( V_86 ) ;
int V_118 = F_53 ( V_117 ) ;
int V_119 ;
switch ( V_118 ) {
case 16 :
V_119 = V_120 ;
V_3 -> V_93 . V_121 = V_122 ;
break;
case 32 :
V_119 = V_123 ;
V_3 -> V_93 . V_121 = V_71 ;
break;
default:
F_3 ( & V_3 -> V_5 -> V_19 , L_19 ) ;
return - V_30 ;
}
F_44 ( V_86 , NULL , & V_3 -> V_93 ) ;
return F_2 ( V_3 -> V_15 , V_16 ,
V_124 ,
F_54 ( V_119 ) ) ;
}
static int F_55 ( struct V_99 * V_100 , int V_125 ,
struct V_85 * V_86 )
{
struct V_2 * V_3 = F_36 ( V_86 ) ;
int V_36 = 0 ;
switch ( V_125 ) {
case V_126 :
case V_127 :
case V_128 :
F_2 ( V_3 -> V_15 , V_40 ,
V_129 , V_129 ) ;
F_2 ( V_3 -> V_15 , V_16 ,
V_53 , V_53 ) ;
V_36 = F_14 ( V_3 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
F_20 ( V_3 ) ;
break;
default:
return - V_30 ;
}
return V_36 ;
}
static void F_56 ( struct V_99 * V_100 ,
struct V_85 * V_86 )
{
struct V_2 * V_3 = F_36 ( V_86 ) ;
V_3 -> V_100 = NULL ;
F_33 ( V_3 -> V_80 ) ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_133 * V_134 = V_5 -> V_19 . V_135 ;
const struct V_136 * V_137 ;
struct V_138 * V_139 ;
if ( ! V_134 )
return - V_140 ;
V_137 = F_58 ( V_141 , & V_5 -> V_19 ) ;
if ( V_137 )
V_3 -> V_142 =
( const struct V_143 * ) V_137 -> V_1 ;
else
return - V_30 ;
V_139 = F_59 ( V_5 , V_144 , 0 ) ;
V_3 -> V_145 = F_60 ( & V_5 -> V_19 , V_139 ) ;
if ( F_61 ( V_3 -> V_145 ) )
return F_62 ( V_3 -> V_145 ) ;
V_3 -> V_68 = V_139 -> V_146 ;
V_3 -> V_80 = F_63 ( & V_5 -> V_19 , L_20 ) ;
if ( F_61 ( V_3 -> V_80 ) ) {
F_3 ( & V_5 -> V_19 , L_21 ) ;
return F_62 ( V_3 -> V_80 ) ;
}
V_3 -> V_97 = F_64 ( V_5 , 0 ) ;
if ( V_3 -> V_97 < 0 ) {
F_3 ( & V_5 -> V_19 , L_22 , V_5 -> V_147 ) ;
return V_3 -> V_97 ;
}
return 0 ;
}
static int F_65 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_148 * V_149 ;
const struct V_150 * V_151 = NULL ;
int V_36 ;
V_3 = F_22 ( & V_5 -> V_19 , sizeof( * V_3 ) , V_61 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_5 = V_5 ;
F_66 ( & V_3 -> V_21 ) ;
F_67 ( & V_3 -> V_41 ) ;
F_68 ( V_5 , V_3 ) ;
V_36 = F_57 ( V_5 , V_3 ) ;
if ( V_36 )
return V_36 ;
V_3 -> V_15 = F_69 ( & V_5 -> V_19 , L_20 ,
V_3 -> V_145 ,
V_3 -> V_142 ) ;
if ( F_61 ( V_3 -> V_15 ) ) {
F_3 ( & V_5 -> V_19 , L_23 ) ;
return F_62 ( V_3 -> V_15 ) ;
}
V_36 = F_70 ( & V_5 -> V_19 , V_3 -> V_97 , F_48 , 0 ,
F_71 ( & V_5 -> V_19 ) , V_3 ) ;
if ( V_36 ) {
F_3 ( & V_5 -> V_19 , L_24 , V_36 ) ;
return V_36 ;
}
V_149 = F_72 ( & V_5 -> V_19 , NULL ) ;
if ( ! F_61 ( V_149 ) ) {
F_73 ( V_149 ) ;
F_74 ( 2 ) ;
F_75 ( V_149 ) ;
}
V_36 = F_76 ( & V_5 -> V_19 ,
& V_152 ,
V_153 ,
F_40 ( V_153 ) ) ;
if ( V_36 )
return V_36 ;
V_36 = F_21 ( & V_5 -> V_19 , V_3 ) ;
if ( V_36 )
goto error;
V_151 = & V_154 ;
V_36 = F_77 ( & V_5 -> V_19 , V_151 , 0 ) ;
if ( V_36 ) {
F_3 ( & V_5 -> V_19 , L_25 , V_36 ) ;
goto error;
}
return 0 ;
error:
if ( V_3 -> V_25 )
F_26 ( V_3 -> V_25 ) ;
if ( V_3 -> V_7 )
F_78 ( V_3 -> V_7 ) ;
return V_36 ;
}
static int F_79 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_80 ( V_5 ) ;
if ( V_3 -> V_25 )
F_26 ( V_3 -> V_25 ) ;
if ( V_3 -> V_7 )
F_78 ( V_3 -> V_7 ) ;
return 0 ;
}
