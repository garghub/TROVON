static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 -> V_4 , V_1 , V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 ;
F_4 ( V_3 -> V_4 , V_1 , & V_2 ) ;
return V_2 ;
}
static inline void F_5 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 -> V_5 , V_1 , V_2 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
F_7 ( V_3 -> V_4 , true ) ;
F_7 ( V_3 -> V_5 , true ) ;
F_8 ( V_3 -> V_8 ) ;
F_8 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_10 ;
V_10 = F_10 ( V_3 -> V_9 ) ;
if ( V_10 ) {
F_11 ( V_7 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 ( V_3 -> V_8 ) ;
if ( V_10 ) {
F_11 ( V_7 , L_2 , V_10 ) ;
F_12 ( V_3 -> V_9 ) ;
return V_10 ;
}
F_7 ( V_3 -> V_4 , false ) ;
F_7 ( V_3 -> V_5 , false ) ;
return 0 ;
}
int F_13 ( enum V_11 * V_12 ,
char * V_13 , int V_14 ,
T_2 * V_15 )
{
int V_16 ;
T_1 V_1 , V_2 ;
struct V_17 V_18 ;
V_16 = F_14 ( V_3 -> V_19 ,
V_20 ) ;
if ( V_16 >= V_20 )
return - V_21 ;
F_15 ( V_16 , V_3 -> V_19 ) ;
* V_12 = V_22 + V_16 ;
snprintf ( V_13 , V_14 , L_3 , V_16 ) ;
* V_15 = V_3 -> V_23 + V_24 +
( V_16 * V_25 ) ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ ( V_28 |
V_29 ) ;
V_2 |= ( 7 << V_30 ) |
V_31 |
V_32 ;
F_1 ( V_1 , V_2 ) ;
V_18 . V_33 = 0 ;
V_18 . V_34 = 2 ;
V_18 . V_35 = 2 ;
V_18 . V_36 = V_37 ;
V_18 . V_38 = V_37 ;
V_18 . V_39 = 0 ;
V_18 . V_40 = 0 ;
V_18 . V_41 = 0 ;
V_18 . V_42 = V_43 ;
V_18 . V_44 = 0 ;
V_18 . V_45 = 0 ;
V_1 = V_46 +
( V_16 * V_47 ) ;
V_3 -> V_48 -> V_49 ( V_3 -> V_4 , V_1 , & V_18 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_18 ( enum V_11 V_12 )
{
int V_16 = V_12 - V_22 ;
int V_1 , V_2 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 |= V_50 ;
F_1 ( V_1 , V_2 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_19 ( enum V_11 V_12 )
{
int V_16 = V_12 - V_22 ;
int V_1 , V_2 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ V_50 ;
F_1 ( V_1 , V_2 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_20 ( enum V_11 V_12 )
{
int V_16 = V_12 - V_22 ;
F_21 ( V_16 , V_3 -> V_19 ) ;
return 0 ;
}
int F_22 ( enum V_51 * V_52 ,
char * V_13 , int V_14 ,
T_2 * V_15 )
{
int V_16 ;
T_1 V_1 , V_2 ;
struct V_17 V_18 ;
V_16 = F_14 ( V_3 -> V_53 ,
V_20 ) ;
if ( V_16 >= V_20 )
return - V_21 ;
F_15 ( V_16 , V_3 -> V_53 ) ;
* V_52 = V_54 + V_16 ;
snprintf ( V_13 , V_14 , L_4 , V_16 ) ;
* V_15 = V_3 -> V_23 + V_55 +
( V_16 * V_56 ) ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ ( V_57 |
V_58 ) ;
V_2 |= ( 7 << V_59 ) |
V_60 |
V_61 ;
F_1 ( V_1 , V_2 ) ;
V_18 . V_33 = 0 ;
V_18 . V_34 = 2 ;
V_18 . V_35 = 2 ;
V_18 . V_36 = V_37 ;
V_18 . V_38 = V_37 ;
V_18 . V_39 = 0 ;
V_18 . V_40 = 0 ;
V_18 . V_41 = 0 ;
V_18 . V_42 = V_62 ;
V_18 . V_44 = 0 ;
V_18 . V_45 = 0 ;
V_1 = V_63 +
( V_16 * V_64 ) ;
V_3 -> V_48 -> V_49 ( V_3 -> V_4 , V_1 , & V_18 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_23 ( enum V_51 V_52 )
{
int V_16 = V_52 - V_54 ;
int V_1 , V_2 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 |= V_65 ;
F_1 ( V_1 , V_2 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_24 ( enum V_51 V_52 )
{
int V_16 = V_52 - V_54 ;
int V_1 , V_2 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_26 +
( V_16 * V_27 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ V_65 ;
F_1 ( V_1 , V_2 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_25 ( enum V_51 V_52 )
{
int V_16 = V_52 - V_54 ;
F_21 ( V_16 , V_3 -> V_53 ) ;
return 0 ;
}
int F_26 ( enum V_11 V_12 ,
enum V_51 V_52 )
{
int V_16 = V_12 - V_22 ;
int V_1 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_66 +
( V_16 * V_67 ) ;
F_5 ( V_1 , 1 << V_52 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
int F_27 ( enum V_11 V_12 )
{
int V_16 = V_12 - V_22 ;
int V_1 ;
F_16 ( V_3 -> V_7 ) ;
V_1 = V_66 +
( V_16 * V_67 ) ;
F_5 ( V_1 , 0 ) ;
F_17 ( V_3 -> V_7 ) ;
return 0 ;
}
static bool F_28 ( struct V_6 * V_7 , unsigned int V_1 )
{
switch ( V_1 ) {
case V_68 :
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
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
return true ;
default:
break;
}
if ( F_29 ( V_1 , V_89 ) ||
F_29 ( V_1 , V_90 ) ||
F_29 ( V_1 , V_91 ) ||
F_29 ( V_1 , V_92 ) ||
F_29 ( V_1 , V_93 ) ||
F_29 ( V_1 , V_94 ) ||
F_29 ( V_1 , V_95 ) ||
F_29 ( V_1 , V_96 ) )
return true ;
return false ;
}
static bool F_30 ( struct V_6 * V_7 ,
unsigned int V_1 )
{
switch ( V_1 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
return true ;
default:
break;
}
if ( F_29 ( V_1 , V_90 ) ||
F_29 ( V_1 , V_91 ) ||
F_29 ( V_1 , V_92 ) ||
F_29 ( V_1 , V_93 ) ||
F_29 ( V_1 , V_96 ) )
return true ;
return false ;
}
static bool F_31 ( struct V_6 * V_7 ,
unsigned int V_1 )
{
if ( F_29 ( V_1 , V_92 ) ||
F_29 ( V_1 , V_93 ) )
return true ;
return false ;
}
static bool F_32 ( struct V_6 * V_7 , unsigned int V_1 )
{
if ( F_29 ( V_1 , V_97 ) )
return true ;
return false ;
}
static int F_33 ( struct V_98 * V_99 )
{
const struct V_100 * V_101 ;
const struct V_102 * V_48 ;
struct V_103 * V_104 ;
int V_105 ;
struct V_106 * V_107 , * V_108 , * V_109 ;
void T_3 * V_110 , * V_111 ;
int V_10 = 0 ;
if ( V_3 )
return - V_112 ;
V_101 = F_34 ( V_113 , & V_99 -> V_7 ) ;
if ( ! V_101 )
return - V_114 ;
V_48 = V_101 -> V_115 ;
for ( V_105 = 0 ; V_105 < F_35 ( V_116 ) ; V_105 ++ ) {
if ( ! ( V_116 [ V_105 ] . V_117 &
V_48 -> V_117 ) )
continue;
V_104 = F_36 ( & V_99 -> V_7 ,
V_116 [ V_105 ] . V_118 ) ;
if ( F_37 ( V_104 ) ) {
F_11 ( & V_99 -> V_7 , L_5 ,
V_116 [ V_105 ] . V_118 ) ;
V_10 = F_38 ( V_104 ) ;
goto V_119;
}
V_10 = F_39 ( V_104 ) ;
F_40 ( V_104 ) ;
if ( V_10 )
goto V_119;
}
V_3 = F_41 ( & V_99 -> V_7 , sizeof( struct V_120 ) ,
V_121 ) ;
if ( ! V_3 ) {
F_11 ( & V_99 -> V_7 , L_6 ) ;
V_10 = - V_122 ;
goto V_119;
}
F_42 ( & V_99 -> V_7 , V_3 ) ;
V_3 -> V_48 = V_48 ;
V_3 -> V_7 = & V_99 -> V_7 ;
V_3 -> V_9 = F_43 ( & V_99 -> V_7 , L_7 ) ;
if ( F_37 ( V_3 -> V_9 ) ) {
F_11 ( & V_99 -> V_7 , L_8 ) ;
V_10 = F_38 ( V_3 -> V_9 ) ;
goto V_119;
}
V_3 -> V_8 = F_43 ( & V_99 -> V_7 , L_9 ) ;
if ( F_37 ( V_3 -> V_8 ) ) {
F_11 ( & V_99 -> V_7 , L_10 ) ;
V_10 = F_38 ( V_3 -> V_8 ) ;
goto V_123;
}
V_107 = F_44 ( V_99 , V_124 , 0 ) ;
if ( ! V_107 ) {
F_11 ( & V_99 -> V_7 , L_11 ) ;
V_10 = - V_112 ;
goto V_125;
}
V_109 = F_45 ( & V_99 -> V_7 , V_107 -> V_126 ,
F_46 ( V_107 ) , V_127 ) ;
if ( ! V_109 ) {
F_11 ( & V_99 -> V_7 , L_12 ) ;
V_10 = - V_21 ;
goto V_125;
}
V_3 -> V_23 = V_107 -> V_126 ;
V_110 = F_47 ( & V_99 -> V_7 , V_107 -> V_126 ,
F_46 ( V_107 ) ) ;
if ( ! V_110 ) {
F_11 ( & V_99 -> V_7 , L_13 ) ;
V_10 = - V_122 ;
goto V_125;
}
V_3 -> V_4 = F_48 ( & V_99 -> V_7 , V_110 ,
& V_128 ) ;
if ( F_37 ( V_3 -> V_4 ) ) {
F_11 ( & V_99 -> V_7 , L_14 ) ;
V_10 = F_38 ( V_3 -> V_4 ) ;
goto V_125;
}
F_7 ( V_3 -> V_4 , true ) ;
V_108 = F_44 ( V_99 , V_124 , 1 ) ;
if ( ! V_108 ) {
F_11 ( & V_99 -> V_7 , L_15 ) ;
V_10 = - V_112 ;
goto V_125;
}
V_109 = F_45 ( & V_99 -> V_7 , V_108 -> V_126 ,
F_46 ( V_108 ) , V_127 ) ;
if ( ! V_109 ) {
F_11 ( & V_99 -> V_7 , L_16 ) ;
V_10 = - V_21 ;
goto V_125;
}
V_111 = F_47 ( & V_99 -> V_7 , V_108 -> V_126 ,
F_46 ( V_108 ) ) ;
if ( ! V_111 ) {
F_11 ( & V_99 -> V_7 , L_17 ) ;
V_10 = - V_122 ;
goto V_125;
}
V_3 -> V_5 = F_48 ( & V_99 -> V_7 , V_111 ,
& V_129 ) ;
if ( F_37 ( V_3 -> V_5 ) ) {
F_11 ( & V_99 -> V_7 , L_18 ) ;
V_10 = F_38 ( V_3 -> V_5 ) ;
goto V_125;
}
F_7 ( V_3 -> V_5 , true ) ;
F_49 ( & V_99 -> V_7 ) ;
if ( ! F_50 ( & V_99 -> V_7 ) ) {
V_10 = F_9 ( & V_99 -> V_7 ) ;
if ( V_10 )
goto V_130;
}
F_51 ( V_99 -> V_7 . V_131 , NULL , NULL , & V_99 -> V_7 ) ;
return 0 ;
V_130:
F_52 ( & V_99 -> V_7 ) ;
V_125:
F_53 ( V_3 -> V_8 ) ;
V_123:
F_53 ( V_3 -> V_9 ) ;
V_3 = NULL ;
V_119:
return V_10 ;
}
static int F_54 ( struct V_98 * V_99 )
{
if ( ! V_3 )
return - V_112 ;
F_52 ( & V_99 -> V_7 ) ;
if ( ! F_55 ( & V_99 -> V_7 ) )
F_6 ( & V_99 -> V_7 ) ;
F_53 ( V_3 -> V_8 ) ;
F_53 ( V_3 -> V_9 ) ;
V_3 = NULL ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 )
{
F_57 ( V_3 -> V_5 ) ;
F_57 ( V_3 -> V_4 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 )
{
int V_10 ;
V_10 = F_16 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_59 ( V_3 -> V_5 ) ;
V_10 |= F_59 ( V_3 -> V_4 ) ;
F_17 ( V_7 ) ;
return V_10 ;
}
void F_60 ( struct V_132 * V_132 , unsigned int V_1 ,
struct V_17 * V_133 )
{
unsigned int V_134 ;
V_134 = ( V_133 -> V_33 <<
V_135 ) |
( ( V_133 -> V_34 - 1 ) <<
V_136 ) |
( ( V_133 -> V_35 - 1 ) <<
V_137 ) |
( V_133 -> V_36 <<
V_138 ) |
( V_133 -> V_38 <<
V_139 ) |
( V_133 -> V_39 <<
V_140 ) |
( V_133 -> V_40 <<
V_141 ) |
( V_133 -> V_41 <<
V_142 ) |
( V_133 -> V_42 <<
V_143 ) |
( V_133 -> V_44 <<
V_144 ) |
( V_133 -> V_45 <<
V_145 ) ;
F_2 ( V_132 , V_1 , V_134 ) ;
}
void F_61 ( struct V_132 * V_132 , unsigned int V_1 ,
struct V_17 * V_133 )
{
unsigned int V_134 ;
V_134 = ( V_133 -> V_33 <<
V_146 ) |
( ( V_133 -> V_34 - 1 ) <<
V_147 ) |
( ( V_133 -> V_35 - 1 ) <<
V_148 ) |
( V_133 -> V_36 <<
V_138 ) |
( V_133 -> V_38 <<
V_139 ) |
( V_133 -> V_39 <<
V_140 ) |
( V_133 -> V_40 <<
V_141 ) |
( V_133 -> V_41 <<
V_142 ) |
( V_133 -> V_42 <<
V_143 ) |
( V_133 -> V_44 <<
V_144 ) |
( V_133 -> V_45 <<
V_145 ) ;
F_2 ( V_132 , V_1 , V_134 ) ;
}
