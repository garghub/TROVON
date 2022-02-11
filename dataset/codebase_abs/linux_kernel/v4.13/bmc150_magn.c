static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
return false ;
} ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_21 * V_22 ,
enum V_23 V_24 ,
bool V_25 )
{
int V_26 ;
switch ( V_24 ) {
case V_27 :
V_26 = F_4 ( V_22 -> V_28 , V_4 ,
V_29 , ! V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
F_5 ( V_30 * 1000 , 20000 ) ;
return 0 ;
case V_31 :
return F_4 ( V_22 -> V_28 ,
V_5 ,
V_32 ,
V_33 <<
V_34 ) ;
case V_35 :
return F_4 ( V_22 -> V_28 ,
V_5 ,
V_32 ,
V_36 <<
V_34 ) ;
}
return - V_37 ;
}
static int F_6 ( struct V_21 * V_22 , bool V_38 )
{
#ifdef F_7
int V_26 ;
if ( V_38 ) {
V_26 = F_8 ( V_22 -> V_2 ) ;
} else {
F_9 ( V_22 -> V_2 ) ;
V_26 = F_10 ( V_22 -> V_2 ) ;
}
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 ,
L_1 , V_38 ) ;
if ( V_38 )
F_12 ( V_22 -> V_2 ) ;
return V_26 ;
}
#endif
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , int * V_39 )
{
int V_26 , V_40 ;
T_1 V_41 , V_42 ;
V_26 = F_14 ( V_22 -> V_28 , V_5 , & V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_42 = ( V_40 & V_43 ) >> V_44 ;
for ( V_41 = 0 ; V_41 < F_15 ( V_45 ) ; V_41 ++ )
if ( V_45 [ V_41 ] . V_40 == V_42 ) {
* V_39 = V_45 [ V_41 ] . V_46 ;
return 0 ;
}
return - V_37 ;
}
static int F_16 ( struct V_21 * V_22 , int V_39 )
{
int V_26 ;
T_1 V_41 ;
for ( V_41 = 0 ; V_41 < F_15 ( V_45 ) ; V_41 ++ ) {
if ( V_45 [ V_41 ] . V_46 == V_39 ) {
V_26 = F_4 ( V_22 -> V_28 ,
V_5 ,
V_43 ,
V_45 [ V_41 ] .
V_40 <<
V_44 ) ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
}
return - V_37 ;
}
static int F_17 ( struct V_21 * V_22 , int V_47 ,
int V_48 , int V_49 )
{
int V_26 , V_40 , V_50 ;
if ( V_47 <= 0 ) {
V_26 = F_14 ( V_22 -> V_28 , V_10 ,
& V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_47 = F_18 ( V_40 ) ;
}
if ( V_48 <= 0 ) {
V_26 = F_14 ( V_22 -> V_28 , V_11 ,
& V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_48 = F_19 ( V_40 ) ;
}
if ( V_49 <= 0 ) {
V_26 = F_13 ( V_22 , & V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_50 = 1000000 / ( 145 * V_47 + 500 * V_48 + 980 ) ;
if ( V_49 > V_50 ) {
F_11 ( V_22 -> V_2 ,
L_2 ,
V_49 ) ;
return - V_37 ;
}
V_22 -> V_50 = V_50 ;
return 0 ;
}
static T_2 F_20 ( struct V_51 * V_52 , T_3 V_53 ,
T_4 V_54 )
{
T_3 V_39 ;
T_4 V_55 = F_21 ( V_52 -> V_55 ) ;
if ( V_53 == V_56 )
return V_57 ;
if ( ! V_54 )
V_54 = V_55 ;
V_39 = ( ( T_3 ) ( ( ( T_4 ) ( ( ( ( T_2 ) V_55 ) << 14 ) / V_54 ) ) - ( ( T_4 ) 0x4000 ) ) ) ;
V_39 = ( ( T_3 ) ( ( ( ( T_2 ) V_53 ) * ( ( ( ( ( ( ( ( T_2 ) V_52 -> V_58 ) * ( ( ( ( T_2 ) V_39 ) *
( ( T_2 ) V_39 ) ) >> 7 ) ) + ( ( ( T_2 ) V_39 ) *
( ( T_2 ) ( ( ( T_3 ) V_52 -> V_59 ) << 7 ) ) ) ) >> 9 ) + ( ( T_2 ) 0x100000 ) ) *
( ( T_2 ) ( ( ( T_3 ) V_52 -> V_60 ) + ( ( T_3 ) 0xA0 ) ) ) ) >> 12 ) ) >> 13 ) ) +
( ( ( T_3 ) V_52 -> V_61 ) << 3 ) ;
return ( T_2 ) V_39 ;
}
static T_2 F_22 ( struct V_51 * V_52 , T_3 V_62 ,
T_4 V_54 )
{
T_3 V_39 ;
T_4 V_55 = F_21 ( V_52 -> V_55 ) ;
if ( V_62 == V_56 )
return V_57 ;
if ( ! V_54 )
V_54 = V_55 ;
V_39 = ( ( T_3 ) ( ( ( T_4 ) ( ( ( ( T_2 ) V_55 ) << 14 ) / V_54 ) ) - ( ( T_4 ) 0x4000 ) ) ) ;
V_39 = ( ( T_3 ) ( ( ( ( T_2 ) V_62 ) * ( ( ( ( ( ( ( ( T_2 ) V_52 -> V_58 ) * ( ( ( ( T_2 ) V_39 ) *
( ( T_2 ) V_39 ) ) >> 7 ) ) + ( ( ( T_2 ) V_39 ) *
( ( T_2 ) ( ( ( T_3 ) V_52 -> V_59 ) << 7 ) ) ) ) >> 9 ) + ( ( T_2 ) 0x100000 ) ) *
( ( T_2 ) ( ( ( T_3 ) V_52 -> V_63 ) + ( ( T_3 ) 0xA0 ) ) ) ) >> 12 ) ) >> 13 ) ) +
( ( ( T_3 ) V_52 -> y1 ) << 3 ) ;
return ( T_2 ) V_39 ;
}
static T_2 F_23 ( struct V_51 * V_52 , T_3 V_64 ,
T_4 V_54 )
{
T_2 V_39 ;
T_4 V_55 = F_21 ( V_52 -> V_55 ) ;
T_4 V_65 = F_21 ( V_52 -> V_65 ) ;
T_3 V_66 = F_21 ( V_52 -> V_66 ) ;
T_3 V_67 = F_21 ( V_52 -> V_67 ) ;
T_3 V_68 = F_21 ( V_52 -> V_68 ) ;
if ( V_64 == V_69 )
return V_57 ;
V_39 = ( ( ( ( ( T_2 ) ( V_64 - V_68 ) ) << 15 ) - ( ( ( ( T_2 ) V_67 ) * ( ( T_2 ) ( ( ( T_3 ) V_54 ) -
( ( T_3 ) V_55 ) ) ) ) >> 2 ) ) / ( V_66 + ( ( T_3 ) ( ( ( ( ( T_2 ) V_65 ) *
( ( ( ( T_3 ) V_54 ) << 1 ) ) ) + ( 1 << 15 ) ) >> 16 ) ) ) ) ;
return V_39 ;
}
static int F_24 ( struct V_21 * V_22 , T_2 * V_70 )
{
int V_26 ;
T_5 V_71 [ V_72 ] ;
T_3 V_73 , V_74 , V_75 ;
T_4 V_54 ;
struct V_51 V_52 ;
V_26 = F_25 ( V_22 -> V_28 , V_12 ,
V_71 , sizeof( V_71 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_73 = ( T_3 ) F_21 ( V_71 [ V_76 ] ) >> V_77 ;
V_74 = ( T_3 ) F_21 ( V_71 [ V_78 ] ) >> V_77 ;
V_75 = ( T_3 ) F_21 ( V_71 [ V_79 ] ) >> V_80 ;
V_54 = F_21 ( V_71 [ V_81 ] ) >> V_82 ;
V_26 = F_25 ( V_22 -> V_28 , V_83 ,
& V_52 , sizeof( V_52 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_70 [ V_76 ] = F_20 ( & V_52 , V_73 , V_54 ) ;
V_70 [ V_78 ] = F_22 ( & V_52 , V_74 , V_54 ) ;
V_70 [ V_79 ] = F_23 ( & V_52 , V_75 , V_54 ) ;
return 0 ;
}
static int F_26 ( struct V_84 * V_85 ,
struct V_86 const * V_87 ,
int * V_39 , int * V_88 , long V_89 )
{
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 , V_90 ;
T_2 V_71 [ V_91 ] ;
switch ( V_89 ) {
case V_92 :
if ( F_28 ( V_85 ) )
return - V_93 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_6 ( V_22 , true ) ;
if ( V_26 < 0 ) {
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
V_26 = F_24 ( V_22 , V_71 ) ;
if ( V_26 < 0 ) {
F_6 ( V_22 , false ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
* V_39 = V_71 [ V_87 -> V_95 ] ;
V_26 = F_6 ( V_22 , false ) ;
if ( V_26 < 0 ) {
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
F_30 ( & V_22 -> V_94 ) ;
return V_96 ;
case V_97 :
* V_39 = 0 ;
* V_88 = 625 ;
return V_98 ;
case V_99 :
V_26 = F_13 ( V_22 , V_39 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_96 ;
case V_100 :
switch ( V_87 -> V_101 ) {
case V_102 :
case V_103 :
V_26 = F_14 ( V_22 -> V_28 , V_10 ,
& V_90 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_39 = F_18 ( V_90 ) ;
return V_96 ;
case V_104 :
V_26 = F_14 ( V_22 -> V_28 , V_11 ,
& V_90 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_39 = F_19 ( V_90 ) ;
return V_96 ;
default:
return - V_37 ;
}
default:
return - V_37 ;
}
}
static int F_31 ( struct V_84 * V_85 ,
struct V_86 const * V_87 ,
int V_39 , int V_88 , long V_89 )
{
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
switch ( V_89 ) {
case V_99 :
if ( V_39 > V_22 -> V_50 )
return - V_37 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_16 ( V_22 , V_39 ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
case V_100 :
switch ( V_87 -> V_101 ) {
case V_102 :
case V_103 :
if ( V_39 < 1 || V_39 > 511 )
return - V_37 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_17 ( V_22 , V_39 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
V_26 = F_4 ( V_22 -> V_28 ,
V_10 ,
V_105 ,
F_32
( V_39 ) ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
case V_104 :
if ( V_39 < 1 || V_39 > 256 )
return - V_37 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_17 ( V_22 , 0 , V_39 , 0 ) ;
if ( V_26 < 0 ) {
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
V_26 = F_4 ( V_22 -> V_28 ,
V_11 ,
V_105 ,
F_33
( V_39 ) ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
default:
return - V_37 ;
}
default:
return - V_37 ;
}
}
static T_6 F_34 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
char * V_108 )
{
struct V_84 * V_85 = F_35 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
T_7 V_109 = 0 ;
T_1 V_41 ;
for ( V_41 = 0 ; V_41 < F_15 ( V_45 ) ; V_41 ++ ) {
if ( V_45 [ V_41 ] . V_46 > V_22 -> V_50 )
break;
V_109 += F_36 ( V_108 + V_109 , V_110 - V_109 , L_3 ,
V_45 [ V_41 ] . V_46 ) ;
}
V_108 [ V_109 - 1 ] = '\n' ;
return V_109 ;
}
static T_8 F_37 ( int V_111 , void * V_112 )
{
struct V_113 * V_114 = V_112 ;
struct V_84 * V_85 = V_114 -> V_85 ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_24 ( V_22 , V_22 -> V_70 ) ;
if ( V_26 < 0 )
goto V_115;
F_38 ( V_85 , V_22 -> V_70 ,
V_114 -> V_116 ) ;
V_115:
F_30 ( & V_22 -> V_94 ) ;
F_39 ( V_85 -> V_117 ) ;
return V_118 ;
}
static int F_40 ( struct V_21 * V_22 )
{
int V_26 , V_119 ;
struct V_120 V_121 ;
V_26 = F_3 ( V_22 , V_27 ,
false ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 ,
L_4 ) ;
return V_26 ;
}
V_26 = F_14 ( V_22 -> V_28 , V_122 , & V_119 ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 , L_5 ) ;
goto V_123;
}
if ( V_119 != V_124 ) {
F_11 ( V_22 -> V_2 , L_6 , V_119 ) ;
V_26 = - V_125 ;
goto V_123;
}
F_41 ( V_22 -> V_2 , L_7 , V_119 ) ;
V_121 = V_126 [ V_127 ] ;
V_26 = F_16 ( V_22 , V_121 . V_49 ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 , L_8 ,
V_121 . V_49 ) ;
goto V_123;
}
V_26 = F_42 ( V_22 -> V_28 , V_10 ,
F_32 ( V_121 . V_47 ) ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 , L_9 ,
V_121 . V_47 ) ;
goto V_123;
}
V_26 = F_42 ( V_22 -> V_28 , V_11 ,
F_33 ( V_121 . V_48 ) ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 , L_10 ,
V_121 . V_48 ) ;
goto V_123;
}
V_26 = F_17 ( V_22 , V_121 . V_47 , V_121 . V_48 ,
V_121 . V_49 ) ;
if ( V_26 < 0 )
goto V_123;
V_26 = F_3 ( V_22 , V_35 ,
true ) ;
if ( V_26 < 0 ) {
F_11 ( V_22 -> V_2 , L_11 ) ;
goto V_123;
}
return 0 ;
V_123:
F_3 ( V_22 , V_27 , true ) ;
return V_26 ;
}
static int F_43 ( struct V_21 * V_22 )
{
int V_90 ;
return F_14 ( V_22 -> V_28 , V_12 , & V_90 ) ;
}
static int F_44 ( struct V_128 * V_117 )
{
struct V_84 * V_85 = F_45 ( V_117 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
if ( ! V_22 -> V_129 )
return 0 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_43 ( V_22 ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
static int F_46 ( struct V_128 * V_117 ,
bool V_25 )
{
struct V_84 * V_85 = F_45 ( V_117 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 = 0 ;
F_29 ( & V_22 -> V_94 ) ;
if ( V_25 == V_22 -> V_129 )
goto V_130;
V_26 = F_4 ( V_22 -> V_28 , V_7 ,
V_131 ,
V_25 << V_132 ) ;
if ( V_26 < 0 )
goto V_130;
V_22 -> V_129 = V_25 ;
if ( V_25 ) {
V_26 = F_43 ( V_22 ) ;
if ( V_26 < 0 )
goto V_130;
}
F_30 ( & V_22 -> V_94 ) ;
return 0 ;
V_130:
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
static int F_47 ( struct V_84 * V_85 )
{
struct V_21 * V_22 = F_27 ( V_85 ) ;
return F_6 ( V_22 , true ) ;
}
static int F_48 ( struct V_84 * V_85 )
{
struct V_21 * V_22 = F_27 ( V_85 ) ;
return F_6 ( V_22 , false ) ;
}
static const char * F_49 ( struct V_1 * V_2 )
{
const struct V_133 * V_134 ;
V_134 = F_50 ( V_2 -> V_135 -> V_136 , V_2 ) ;
if ( ! V_134 )
return NULL ;
return F_51 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_28 * V_28 ,
int V_111 , const char * V_137 )
{
struct V_21 * V_22 ;
struct V_84 * V_85 ;
int V_26 ;
V_85 = F_53 ( V_2 , sizeof( * V_22 ) ) ;
if ( ! V_85 )
return - V_138 ;
V_22 = F_27 ( V_85 ) ;
F_54 ( V_2 , V_85 ) ;
V_22 -> V_28 = V_28 ;
V_22 -> V_111 = V_111 ;
V_22 -> V_2 = V_2 ;
if ( ! V_137 && F_55 ( V_2 ) )
V_137 = F_49 ( V_2 ) ;
F_56 ( & V_22 -> V_94 ) ;
V_26 = F_40 ( V_22 ) ;
if ( V_26 < 0 )
return V_26 ;
V_85 -> V_2 . V_139 = V_2 ;
V_85 -> V_140 = V_141 ;
V_85 -> V_142 = F_15 ( V_141 ) ;
V_85 -> V_143 = V_144 ;
V_85 -> V_137 = V_137 ;
V_85 -> V_145 = V_146 ;
V_85 -> V_147 = & V_148 ;
if ( V_111 > 0 ) {
V_22 -> V_149 = F_57 ( V_2 ,
L_12 ,
V_85 -> V_137 ,
V_85 -> V_134 ) ;
if ( ! V_22 -> V_149 ) {
V_26 = - V_138 ;
F_11 ( V_2 , L_13 ) ;
goto V_123;
}
V_22 -> V_149 -> V_2 . V_139 = V_2 ;
V_22 -> V_149 -> V_150 = & V_151 ;
F_58 ( V_22 -> V_149 , V_85 ) ;
V_26 = F_59 ( V_22 -> V_149 ) ;
if ( V_26 ) {
F_11 ( V_2 , L_14 ) ;
goto V_123;
}
V_26 = F_60 ( V_111 ,
V_152 ,
NULL ,
V_153 | V_154 ,
V_155 ,
V_22 -> V_149 ) ;
if ( V_26 < 0 ) {
F_11 ( V_2 , L_15 , V_111 ) ;
goto V_156;
}
}
V_26 = F_61 ( V_85 ,
V_157 ,
F_37 ,
& V_158 ) ;
if ( V_26 < 0 ) {
F_11 ( V_2 , L_16 ) ;
goto V_159;
}
V_26 = F_62 ( V_2 ) ;
if ( V_26 )
goto V_160;
F_63 ( V_2 ) ;
F_64 ( V_2 ,
V_161 ) ;
F_65 ( V_2 ) ;
V_26 = F_66 ( V_85 ) ;
if ( V_26 < 0 ) {
F_11 ( V_2 , L_17 ) ;
goto V_160;
}
F_41 ( V_2 , L_18 , V_137 ) ;
return 0 ;
V_160:
F_67 ( V_85 ) ;
V_159:
if ( V_111 > 0 )
F_68 ( V_111 , V_22 -> V_149 ) ;
V_156:
if ( V_22 -> V_149 )
F_69 ( V_22 -> V_149 ) ;
V_123:
F_3 ( V_22 , V_27 , true ) ;
return V_26 ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_71 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
F_72 ( V_85 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_12 ( V_2 ) ;
F_67 ( V_85 ) ;
if ( V_22 -> V_111 > 0 )
F_68 ( V_22 -> V_111 , V_22 -> V_149 ) ;
if ( V_22 -> V_149 )
F_69 ( V_22 -> V_149 ) ;
F_29 ( & V_22 -> V_94 ) ;
F_3 ( V_22 , V_27 , true ) ;
F_30 ( & V_22 -> V_94 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_71 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_3 ( V_22 , V_31 ,
true ) ;
F_30 ( & V_22 -> V_94 ) ;
if ( V_26 < 0 ) {
F_11 ( V_2 , L_19 ) ;
return V_26 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_71 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
return F_3 ( V_22 , V_35 ,
true ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_71 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_3 ( V_22 , V_31 ,
true ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_71 ( V_2 ) ;
struct V_21 * V_22 = F_27 ( V_85 ) ;
int V_26 ;
F_29 ( & V_22 -> V_94 ) ;
V_26 = F_3 ( V_22 , V_35 ,
true ) ;
F_30 ( & V_22 -> V_94 ) ;
return V_26 ;
}
