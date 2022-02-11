static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned int V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_4 = F_2 ( V_2 -> V_8 , V_3 , & V_6 ) ;
if ( V_4 == - V_9 )
continue;
else
break;
}
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_1 , V_4 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
int V_4 ;
V_4 = F_5 ( V_2 -> V_8 , V_3 , ( unsigned int ) V_6 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_2 , V_4 ) ;
return V_4 ;
}
static int F_6 ( const char * V_12 , int * V_13 ,
struct V_1 * V_2 )
{
int V_4 , V_6 = 0 ;
struct V_14 * V_15 ;
V_15 = F_7 ( NULL , V_12 ) ;
if ( F_8 ( V_15 ) ) {
V_4 = F_9 ( V_15 ) ;
goto exit;
}
V_4 = F_10 ( V_15 , & V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_3 , V_4 , V_6 ) ;
goto V_16;
}
F_11 ( & V_2 -> V_10 -> V_11 , L_4 , V_6 ) ;
* V_13 = V_6 ;
V_16:
F_12 ( V_15 ) ;
exit:
return V_4 ;
}
static int F_13 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_13 , V_4 ;
F_14 ( V_18 , L_5 ,
V_21 ,
F_1 ( V_2 , V_21 ) ) ;
F_14 ( V_18 , L_6 ,
V_22 ,
F_1 ( V_2 , V_22 ) ) ;
F_14 ( V_18 , L_7 ,
V_23 ,
F_1 ( V_2 , V_23 ) ) ;
F_14 ( V_18 , L_8 ,
V_24 ,
F_1 ( V_2 , V_24 ) ) ;
F_14 ( V_18 , L_9 ,
V_25 ,
F_1 ( V_2 , V_25 ) ) ;
F_14 ( V_18 , L_10 ,
V_26 ,
F_1 ( V_2 , V_26 ) ) ;
F_14 ( V_18 , L_11 ,
V_27 ,
F_1 ( V_2 , V_27 ) ) ;
F_14 ( V_18 , L_12 ,
V_28 ,
F_1 ( V_2 , V_28 ) ) ;
F_14 ( V_18 , L_13 ,
V_29 ,
F_1 ( V_2 , V_29 ) ) ;
F_14 ( V_18 , L_14 ,
V_30 ,
F_1 ( V_2 , V_30 ) ) ;
F_14 ( V_18 , L_15 ,
V_31 ,
F_1 ( V_2 , V_31 ) ) ;
F_14 ( V_18 , L_16 ,
V_32 ,
F_1 ( V_2 , V_32 ) ) ;
F_14 ( V_18 , L_17 ,
V_33 ,
F_1 ( V_2 , V_33 ) ) ;
F_14 ( V_18 , L_18 ,
V_34 ,
F_1 ( V_2 , V_34 ) ) ;
F_14 ( V_18 , L_19 ,
V_35 ,
F_1 ( V_2 , V_35 ) ) ;
F_14 ( V_18 , L_20 ,
V_36 ,
F_1 ( V_2 , V_36 ) ) ;
F_14 ( V_18 , L_21 ,
V_37 ,
F_1 ( V_2 , V_37 ) ) ;
F_14 ( V_18 , L_22 ,
V_38 ,
F_1 ( V_2 , V_38 ) ) ;
F_14 ( V_18 , L_23 ,
V_39 ,
F_1 ( V_2 , V_39 ) ) ;
F_14 ( V_18 , L_24 ,
V_40 ,
F_1 ( V_2 , V_40 ) ) ;
F_14 ( V_18 , L_25 ,
V_41 ,
F_1 ( V_2 , V_41 ) ) ;
F_14 ( V_18 , L_26 ,
V_42 ,
F_1 ( V_2 , V_42 ) ) ;
F_14 ( V_18 , L_27 ,
V_43 ,
F_1 ( V_2 , V_43 ) ) ;
F_14 ( V_18 , L_28 ,
V_44 ,
F_1 ( V_2 , V_44 ) ) ;
V_4 = F_6 ( L_29 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_30 , V_13 ) ;
V_4 = F_6 ( L_31 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_32 , V_13 ) ;
V_4 = F_6 ( L_33 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_34 , V_13 ) ;
V_4 = F_6 ( L_35 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_36 , V_13 ) ;
V_4 = F_6 ( L_37 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_38 , V_13 ) ;
V_4 = F_6 ( L_39 , & V_13 , V_2 ) ;
if ( V_4 >= 0 )
F_14 ( V_18 , L_40 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_16 ( V_46 , F_13 , V_45 -> V_47 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_48 = F_18 ( L_41 , 0666 , NULL ,
V_2 , & V_49 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_48 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
}
static inline void F_19 ( struct V_1 * V_2 )
{
}
static void F_21 ( struct V_1 * V_2 )
{
int V_50 , V_4 ;
int V_51 , V_52 ;
V_50 = F_1 ( V_2 , V_21 ) ;
if ( V_50 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_42 , V_50 ) ;
return;
}
V_4 = F_6 ( L_35 , & V_51 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_43 , V_4 ) ;
return;
}
V_4 = F_6 ( L_37 , & V_52 , V_2 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_44 , V_4 ) ;
return;
}
if ( V_51 > 0 )
V_2 -> V_53 = V_54 ;
else if ( V_52 > 0 )
V_2 -> V_53 = V_55 ;
else {
if ( V_50 & V_56 )
V_2 -> V_53 = V_57 ;
else
V_2 -> V_53 = V_58 ;
}
}
static int F_22 ( struct V_1 * V_2 , int * V_59 )
{
int V_4 = 0 , V_13 ;
V_4 = F_6 ( L_39 , & V_13 , V_2 ) ;
if ( V_4 < 0 )
goto V_60;
* V_59 = F_23 ( V_13 ) ;
V_60:
return V_4 ;
}
static int F_24 ( struct V_1 * V_2 , int * V_61 )
{
int V_4 , V_62 = 0 ;
int V_51 , V_52 ;
V_4 = F_6 ( L_35 , & V_51 , V_2 ) ;
if ( V_4 < 0 )
goto V_63;
V_4 = F_6 ( L_37 , & V_52 , V_2 ) ;
if ( V_4 < 0 )
goto V_63;
if ( V_51 > 0 )
V_62 = V_51 ;
else if ( V_52 > 0 )
V_62 = - 1 * V_52 ;
* V_61 = V_62 ;
V_63:
return V_4 ;
}
static int F_25 ( struct V_1 * V_2 , int V_64 )
{
int V_65 = 0 , V_5 , V_4 , V_66 ;
int V_67 , V_68 , V_69 , V_70 ;
int V_71 = V_2 -> V_72 -> V_71 ;
if ( V_64 > V_2 -> V_72 -> V_73 [ 0 ] [ 1 ] ) {
V_65 = V_2 -> V_72 -> V_73 [ 0 ] [ 0 ] ;
} else if ( V_64 <= V_2 -> V_72 -> V_73 [ V_71 - 1 ] [ 1 ] ) {
V_65 = V_2 -> V_72 -> V_73 [ V_71 - 1 ] [ 0 ] ;
} else {
for ( V_5 = 1 ; V_5 < V_71 ; V_5 ++ ) {
if ( V_64 > V_2 -> V_72 -> V_73 [ V_5 ] [ 1 ] ) {
V_67 = V_2 -> V_72 -> V_73 [ V_5 - 1 ] [ 0 ] ;
V_68 = V_2 -> V_72 -> V_73 [ V_5 ] [ 0 ] ;
V_69 = V_2 -> V_72 -> V_73 [ V_5 - 1 ] [ 1 ] ;
V_70 = V_2 -> V_72 -> V_73 [ V_5 ] [ 1 ] ;
V_65 = V_67 + ( ( V_68 - V_67 ) *
( V_64 - V_69 ) / ( V_70 - V_69 ) ) ;
break;
}
}
}
V_4 = F_1 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_45 , V_75 , V_4 ) ;
V_4 = 0x30 ;
}
V_66 = V_65 * ( 20 + ( 20 * ( ( V_4 >> 4 ) & 0x3 ) ) ) / 800 ;
return V_66 ;
}
static int F_26 ( struct V_1 * V_2 , int V_66 )
{
int V_4 , V_76 , V_5 , V_64 = 0 ;
int V_67 , V_68 , V_69 , V_70 ;
int V_71 = V_2 -> V_72 -> V_71 ;
V_4 = F_1 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_45 , V_75 , V_4 ) ;
V_4 = 0x30 ;
}
V_76 = V_66 * 800 / ( 20 + ( 20 * ( ( V_4 >> 4 ) & 0x3 ) ) ) ;
if ( V_76 < V_2 -> V_72 -> V_73 [ 0 ] [ 0 ] ) {
V_64 = V_2 -> V_72 -> V_73 [ 0 ] [ 1 ] ;
} else if ( V_76 >= V_2 -> V_72 -> V_73 [ V_71 - 1 ] [ 0 ] ) {
V_64 = V_2 -> V_72 -> V_73 [ V_71 - 1 ] [ 1 ] ;
} else {
for ( V_5 = 1 ; V_5 < V_71 ; V_5 ++ ) {
if ( V_76 < V_2 -> V_72 -> V_73 [ V_5 ] [ 0 ] ) {
V_67 = V_2 -> V_72 -> V_73 [ V_5 - 1 ] [ 0 ] ;
V_68 = V_2 -> V_72 -> V_73 [ V_5 ] [ 0 ] ;
V_69 = V_2 -> V_72 -> V_73 [ V_5 - 1 ] [ 1 ] ;
V_70 = V_2 -> V_72 -> V_73 [ V_5 ] [ 1 ] ;
V_64 = V_69 + ( ( V_70 - V_69 ) *
( V_76 - V_67 ) / ( V_68 - V_67 ) ) ;
break;
}
}
}
return V_64 ;
}
static int F_27 ( struct V_1 * V_2 , int * V_77 )
{
int V_4 , V_13 = 0 ;
V_4 = F_6 ( L_29 , & V_13 , V_2 ) ;
if ( V_4 < 0 )
goto V_78;
* V_77 = F_26 ( V_2 , V_13 ) ;
V_78:
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 , int * V_79 )
{
int V_4 , V_62 ;
V_4 = F_1 ( V_2 , V_30 ) ;
if ( V_4 < 0 )
goto V_80;
V_62 = V_4 << 4 ;
V_4 = F_1 ( V_2 , V_31 ) ;
if ( V_4 < 0 )
goto V_80;
V_62 |= ( V_4 & 0xf ) ;
* V_79 = F_23 ( V_62 ) ;
V_80:
return V_4 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_81 , V_79 ;
int V_4 , V_82 = V_83 ;
V_4 = F_27 ( V_2 , & V_81 ) ;
if ( V_4 < 0 )
goto V_84;
V_4 = F_28 ( V_2 , & V_79 ) ;
if ( V_4 < 0 )
goto V_84;
if ( V_79 > V_2 -> V_72 -> V_85 )
V_82 = V_86 ;
else if ( V_81 > V_2 -> V_72 -> V_87 )
V_82 = V_88 ;
else if ( V_81 < V_2 -> V_72 -> V_89 )
V_82 = V_90 ;
else if ( V_79 < V_2 -> V_72 -> V_91 )
V_82 = V_92 ;
else
V_82 = V_93 ;
V_84:
return V_82 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_4 , V_66 ;
V_66 = F_25 ( V_2 , V_2 -> V_72 -> V_87 ) ;
V_4 = F_4 ( V_2 , V_25 , V_66 >> 4 ) ;
return V_4 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_4 , V_66 ;
V_66 = F_25 ( V_2 , V_2 -> V_72 -> V_89 ) ;
V_4 = F_4 ( V_2 , V_24 , V_66 >> 4 ) ;
return V_4 ;
}
static int F_32 ( struct V_94 * V_95 ,
enum V_96 V_97 ,
union V_98 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_95 ) ;
int V_4 = 0 , V_62 ;
F_34 ( & V_2 -> V_99 ) ;
switch ( V_97 ) {
case V_100 :
F_21 ( V_2 ) ;
V_6 -> V_101 = V_2 -> V_53 ;
break;
case V_102 :
V_6 -> V_101 = F_29 ( V_2 ) ;
break;
case V_103 :
V_4 = F_22 ( V_2 , & V_62 ) ;
if ( V_4 < 0 )
goto V_104;
V_6 -> V_101 = F_35 ( V_62 ) ;
break;
case V_105 :
V_4 = F_28 ( V_2 , & V_62 ) ;
if ( V_4 < 0 )
goto V_104;
V_6 -> V_101 = F_35 ( V_62 ) ;
break;
case V_106 :
V_4 = F_24 ( V_2 , & V_62 ) ;
if ( V_4 < 0 )
goto V_104;
V_6 -> V_101 = F_36 ( V_62 ) ;
break;
case V_107 :
V_4 = F_1 ( V_2 , V_22 ) ;
if ( V_4 < 0 )
goto V_104;
if ( V_4 & V_56 )
V_6 -> V_101 = 1 ;
else
V_6 -> V_101 = 0 ;
break;
case V_108 :
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
goto V_104;
if ( ! ( V_4 & V_109 ) )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_46 ) ;
V_6 -> V_101 = ( V_4 & V_110 ) ;
break;
case V_111 :
V_4 = F_1 ( V_2 , V_38 ) ;
if ( V_4 < 0 )
goto V_104;
V_6 -> V_101 = ( V_4 & 0x0f ) ;
break;
case V_112 :
V_4 = F_27 ( V_2 , & V_62 ) ;
if ( V_4 < 0 )
goto V_104;
V_6 -> V_101 = F_37 ( V_62 ) ;
break;
case V_113 :
case V_114 :
V_6 -> V_101 = F_37 ( V_2 -> V_72 -> V_87 ) ;
break;
case V_115 :
case V_116 :
V_6 -> V_101 = F_37 ( V_2 -> V_72 -> V_89 ) ;
break;
case V_117 :
V_6 -> V_101 = V_118 ;
break;
case V_119 :
V_4 = F_1 ( V_2 , V_34 ) ;
if ( V_4 < 0 )
goto V_104;
V_62 = ( V_4 & V_120 ) << 8 ;
V_4 = F_1 ( V_2 , V_35 ) ;
if ( V_4 < 0 )
goto V_104;
V_62 |= ( V_4 & V_121 ) ;
V_6 -> V_101 = V_62 * V_122 ;
break;
case V_123 :
V_4 = F_1 ( V_2 , V_32 ) ;
if ( V_4 < 0 )
goto V_104;
V_62 = ( V_4 & V_124 ) << 8 ;
V_4 = F_1 ( V_2 , V_33 ) ;
if ( V_4 < 0 )
goto V_104;
V_62 |= ( V_4 & V_125 ) ;
V_6 -> V_101 = V_62 * V_122 ;
break;
case V_126 :
V_6 -> V_101 = F_36 ( V_2 -> V_72 -> V_127 ) ;
break;
case V_128 :
V_6 -> V_101 = F_35 ( V_2 -> V_72 -> V_85 ) ;
break;
case V_129 :
V_6 -> V_101 = F_35 ( V_2 -> V_72 -> V_91 ) ;
break;
case V_130 :
V_6 -> V_131 = V_2 -> V_72 -> V_132 ;
break;
default:
F_38 ( & V_2 -> V_99 ) ;
return - V_133 ;
}
F_38 ( & V_2 -> V_99 ) ;
return 0 ;
V_104:
F_38 ( & V_2 -> V_99 ) ;
return V_4 ;
}
static int F_39 ( struct V_94 * V_95 ,
enum V_96 V_97 ,
const union V_98 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_95 ) ;
int V_4 = 0 ;
F_34 ( & V_2 -> V_99 ) ;
switch ( V_97 ) {
case V_100 :
V_2 -> V_53 = V_6 -> V_101 ;
break;
case V_115 :
case V_116 :
if ( ( V_6 -> V_101 < V_134 ) ||
( V_6 -> V_101 > V_135 ) ) {
V_4 = - V_133 ;
break;
}
V_2 -> V_72 -> V_89 = F_40 ( V_6 -> V_101 ) ;
V_4 = F_31 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_47 , V_4 ) ;
break;
case V_113 :
case V_114 :
if ( ( V_6 -> V_101 < V_134 ) ||
( V_6 -> V_101 > V_135 ) ) {
V_4 = - V_133 ;
break;
}
V_2 -> V_72 -> V_87 = F_40 ( V_6 -> V_101 ) ;
V_4 = F_30 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 ,
L_48 , V_4 ) ;
break;
case V_111 :
if ( ( V_6 -> V_101 < 0 ) || ( V_6 -> V_101 > 15 ) ) {
V_4 = - V_133 ;
break;
}
V_4 = F_1 ( V_2 , V_38 ) ;
if ( V_4 < 0 )
break;
V_4 &= 0xf0 ;
V_4 |= ( V_6 -> V_101 & 0xf ) ;
V_4 = F_4 ( V_2 , V_38 , V_4 ) ;
break;
default:
V_4 = - V_133 ;
break;
}
F_38 ( & V_2 -> V_99 ) ;
return V_4 ;
}
static int F_41 ( struct V_94 * V_136 ,
enum V_96 V_137 )
{
int V_4 ;
switch ( V_137 ) {
case V_100 :
case V_115 :
case V_116 :
case V_113 :
case V_114 :
case V_111 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
}
return V_4 ;
}
static void F_42 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_43 ( V_139 ,
struct V_1 , V_140 . V_139 ) ;
F_21 ( V_2 ) ;
F_44 ( V_2 -> V_141 ) ;
F_45 ( & V_2 -> V_140 , V_142 ) ;
}
static T_2 F_46 ( int V_143 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_144 ; V_5 ++ ) {
if ( V_2 -> V_143 [ V_5 ] == V_143 )
break;
}
if ( V_5 >= V_144 ) {
F_47 ( & V_2 -> V_10 -> V_11 , L_49 ) ;
return V_145 ;
}
switch ( V_5 ) {
case V_146 :
F_48 ( & V_2 -> V_10 -> V_11 ,
L_50 ) ;
break;
case V_147 :
F_48 ( & V_2 -> V_10 -> V_11 ,
L_51 ) ;
break;
case V_148 :
F_48 ( & V_2 -> V_10 -> V_11 ,
L_52 ) ;
break;
case V_149 :
F_48 ( & V_2 -> V_10 -> V_11 ,
L_53 ) ;
break;
case V_150 :
F_48 ( & V_2 -> V_10 -> V_11 , L_54 ) ;
break;
case V_151 :
F_48 ( & V_2 -> V_10 -> V_11 , L_55 ) ;
break;
default:
F_47 ( & V_2 -> V_10 -> V_11 , L_56 ) ;
}
F_44 ( V_2 -> V_141 ) ;
return V_152 ;
}
static void F_49 ( struct V_94 * V_136 )
{
struct V_1 * V_2 = F_33 ( V_136 ) ;
F_44 ( V_2 -> V_141 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_153 ;
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_45 , V_75 , V_4 ) ;
return V_4 ;
}
V_4 = ( V_4 & V_110 ) ;
if ( V_4 > V_154 )
V_153 = V_154 ;
else if ( V_4 > V_155 )
V_153 = V_155 ;
else
V_153 = V_156 ;
V_153 |= V_157 ;
V_4 = F_4 ( V_2 , V_38 , V_153 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_57 , V_75 , V_4 ) ;
return V_4 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_6 ;
V_4 = F_1 ( V_2 , V_23 ) ;
if ( V_4 < 0 )
goto V_158;
else
V_6 = ( V_4 & ~ V_159 ) ;
switch ( V_2 -> V_72 -> V_85 ) {
case V_160 :
V_6 |= ( V_161 << V_162 ) ;
break;
case V_163 :
V_6 |= ( V_164 << V_162 ) ;
break;
case V_165 :
V_6 |= ( V_166 << V_162 ) ;
break;
case V_167 :
V_6 |= ( V_168 << V_162 ) ;
break;
default:
V_6 |= ( V_166 << V_162 ) ;
break;
}
V_4 = F_4 ( V_2 , V_23 , V_6 ) ;
V_158:
return V_4 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_4 ( V_2 ,
V_32 , V_2 -> V_72 -> V_169 ) ;
if ( V_4 < 0 )
goto V_170;
V_4 = F_4 ( V_2 ,
V_33 , V_2 -> V_72 -> V_171 ) ;
V_170:
return V_4 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_4 = 0 , V_5 ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
V_4 = F_4 ( V_2 ,
V_173 + V_5 , V_2 -> V_72 -> V_174 [ V_5 ] ) ;
if ( V_4 < 0 )
goto V_158;
}
V_158:
return V_4 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_4 ( V_2 ,
V_28 , V_2 -> V_72 -> V_175 ) ;
if ( V_4 < 0 )
goto V_158;
V_4 = F_4 ( V_2 ,
V_29 , V_2 -> V_72 -> V_176 ) ;
V_158:
return V_4 ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_1 ( V_2 , V_32 ) ;
if ( V_4 < 0 ) {
F_47 ( & V_2 -> V_10 -> V_11 , L_58 ) ;
} else if ( ! ( V_4 & V_177 ) ) {
F_48 ( & V_2 -> V_10 -> V_11 , L_59 ) ;
} else {
F_48 ( & V_2 -> V_10 -> V_11 , L_60 ) ;
return;
}
V_4 = F_51 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_61 , V_4 ) ;
V_4 = F_52 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_62 , V_4 ) ;
V_4 = F_54 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_63 , V_4 ) ;
V_4 = F_53 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_64 , V_4 ) ;
V_4 = F_50 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_65 , V_4 ) ;
V_4 = F_4 ( V_2 , V_26 , 0xef ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_66 , V_4 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_4 , V_5 , V_178 ;
for ( V_5 = 0 ; V_5 < V_144 ; V_5 ++ ) {
V_178 = F_57 ( V_2 -> V_10 , V_5 ) ;
V_2 -> V_143 [ V_5 ] = F_58 ( V_2 -> V_179 , V_178 ) ;
if ( V_2 -> V_143 [ V_5 ] < 0 ) {
F_47 ( & V_2 -> V_10 -> V_11 ,
L_67 ,
V_178 , V_2 -> V_143 [ V_5 ] ) ;
V_2 -> V_143 [ V_5 ] = - 1 ;
goto V_180;
}
V_4 = F_59 ( V_2 -> V_143 [ V_5 ] ,
NULL , F_46 ,
V_181 , V_182 , V_2 ) ;
if ( V_4 ) {
F_47 ( & V_2 -> V_10 -> V_11 ,
L_68 ,
V_178 , V_2 -> V_143 [ V_5 ] ) ;
V_2 -> V_143 [ V_5 ] = - 1 ;
goto V_180;
} else {
F_48 ( & V_2 -> V_10 -> V_11 , L_69 ,
V_178 , V_2 -> V_143 [ V_5 ] ) ;
}
}
return;
V_180:
for (; V_5 > 0 ; V_5 -- ) {
F_60 ( V_2 -> V_143 [ V_5 - 1 ] , V_2 ) ;
V_2 -> V_143 [ V_5 - 1 ] = - 1 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned int V_6 ;
V_4 = F_30 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_70 , V_4 ) ;
V_4 = F_31 ( V_2 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_10 -> V_11 , L_71 , V_4 ) ;
V_6 = F_1 ( V_2 , V_183 ) ;
V_6 |= V_184 ;
F_4 ( V_2 , V_183 , V_6 ) ;
V_6 = F_1 ( V_2 , V_185 ) ;
V_6 |= V_186 ;
V_6 = F_4 ( V_2 , V_185 , V_6 ) ;
}
static int F_62 ( struct V_187 * V_10 )
{
int V_4 = 0 ;
struct V_1 * V_2 ;
struct V_188 * V_189 = F_63 ( V_10 -> V_11 . V_190 ) ;
struct V_191 V_192 = {} ;
V_2 = F_64 ( & V_10 -> V_11 , sizeof( * V_2 ) , V_193 ) ;
if ( ! V_2 )
return - V_194 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_8 = V_189 -> V_8 ;
V_2 -> V_179 = V_189 -> V_179 ;
V_2 -> V_53 = V_195 ;
V_2 -> V_72 = V_10 -> V_11 . V_196 ;
if ( ! V_2 -> V_72 )
return - V_197 ;
F_65 ( V_10 , V_2 ) ;
F_66 ( & V_2 -> V_99 ) ;
F_67 ( & V_2 -> V_140 , F_42 ) ;
V_192 . V_198 = V_2 ;
V_2 -> V_141 = F_68 ( & V_10 -> V_11 , & V_199 , & V_192 ) ;
if ( F_69 ( V_2 -> V_141 ) ) {
V_4 = F_9 ( V_2 -> V_141 ) ;
F_3 ( & V_10 -> V_11 , L_72 , V_4 ) ;
return V_4 ;
}
F_17 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_61 ( V_2 ) ;
F_45 ( & V_2 -> V_140 , V_142 ) ;
return V_4 ;
}
static int F_70 ( struct V_187 * V_10 )
{
struct V_1 * V_2 = F_71 ( V_10 ) ;
int V_5 ;
F_72 ( & V_2 -> V_140 ) ;
F_73 ( V_2 -> V_141 ) ;
F_19 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_144 ; V_5 ++ )
if ( V_2 -> V_143 [ V_5 ] >= 0 )
F_60 ( V_2 -> V_143 [ V_5 ] , V_2 ) ;
return 0 ;
}
