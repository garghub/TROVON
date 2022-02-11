static int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 V_5 , const T_1 * V_6 , int V_7 ,
const T_1 * V_8 , int V_9 )
{
F_2 ( V_2 -> V_10 [ V_3 ] . V_6 ) ;
F_2 ( V_2 -> V_10 [ V_3 ] . V_8 ) ;
if ( V_7 ) {
V_2 -> V_10 [ V_3 ] . V_6 = F_3 ( V_7 , V_11 ) ;
if ( ! V_2 -> V_10 [ V_3 ] . V_6 )
goto V_12;
} else
V_2 -> V_10 [ V_3 ] . V_6 = NULL ;
if ( V_9 ) {
V_2 -> V_10 [ V_3 ] . V_8 = F_3 ( V_9 , V_11 ) ;
if ( ! V_2 -> V_10 [ V_3 ] . V_8 )
goto V_13;
} else
V_2 -> V_10 [ V_3 ] . V_8 = NULL ;
V_2 -> V_10 [ V_3 ] . V_7 = V_7 ;
V_2 -> V_10 [ V_3 ] . V_9 = V_9 ;
if ( V_7 )
memcpy ( V_2 -> V_10 [ V_3 ] . V_6 , V_6 , V_7 ) ;
if ( V_9 )
memcpy ( V_2 -> V_10 [ V_3 ] . V_8 , V_8 , V_9 ) ;
switch ( V_5 ) {
case V_14 :
V_2 -> V_10 [ V_3 ] . V_15 = V_16 ;
break;
case V_17 :
V_2 -> V_10 [ V_3 ] . V_15 = ( V_7 > V_18 ) ?
V_19 : V_20 ;
break;
case V_21 :
default:
V_2 -> V_10 [ V_3 ] . V_15 = 0 ;
break;
}
return 0 ;
V_13:
F_4 ( V_2 -> V_10 [ V_3 ] . V_6 ) ;
V_2 -> V_10 [ V_3 ] . V_6 = NULL ;
V_12:
V_2 -> V_10 [ V_3 ] . V_7 = 0 ;
V_2 -> V_10 [ V_3 ] . V_9 = 0 ;
V_2 -> V_10 [ V_3 ] . V_15 = 0 ;
return - V_22 ;
}
static struct V_23 * F_5 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 * V_26 = & V_2 -> V_26 ;
struct V_23 * V_27 = & V_2 -> V_27 ;
int V_28 ;
unsigned long V_29 ;
if ( ! F_7 ( V_25 ) ) {
F_8 ( V_30 L_1 ,
V_25 -> V_31 ) ;
return NULL ;
}
if ( F_9 ( V_2 , & V_29 ) != 0 )
return V_27 ;
F_10 ( V_26 , V_32 ) ;
if ( V_2 -> V_33 == V_34 ) {
memset ( & V_27 -> V_35 , 0 , sizeof( V_27 -> V_35 ) ) ;
if ( F_11 ( V_2 ) ) {
V_27 -> V_35 . V_35 = V_2 -> V_36 . V_37 [ 0 ] . V_35 ;
V_27 -> V_35 . V_38 = V_2 -> V_36 . V_37 [ 0 ] . V_38 ;
V_27 -> V_35 . V_39 = V_2 -> V_36 . V_37 [ 0 ] . V_39 ;
V_27 -> V_35 . V_40 =
V_2 -> V_36 . V_37 [ 0 ] . V_40 ;
}
} else {
struct {
T_3 V_35 , signal , V_39 , V_41 ;
} V_42 V_43 ;
V_28 = F_12 ( V_26 , V_44 ,
V_45 , & V_43 ) ;
if ( ! V_28 ) {
V_27 -> V_35 . V_35 = ( int ) F_13 ( V_43 . V_35 ) ;
V_27 -> V_35 . V_38 = ( int ) F_13 ( V_43 . signal ) - 0x95 ;
V_27 -> V_35 . V_39 = ( int ) F_13 ( V_43 . V_39 ) - 0x95 ;
V_27 -> V_35 . V_40 =
V_46 | V_47 ;
}
}
F_14 ( V_2 , & V_29 ) ;
return V_27 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_28 = - V_53 ;
unsigned long V_29 ;
static const T_1 V_54 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const T_1 V_55 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( memcmp ( & V_51 -> V_57 , V_54 , V_58 ) == 0 ||
memcmp ( & V_51 -> V_57 , V_55 , V_58 ) == 0 ) {
V_2 -> V_59 = 0 ;
memset ( V_2 -> V_60 , 0 , V_58 ) ;
if ( V_51 -> V_57 [ 0 ] == 0 ) {
F_16 ( V_2 ) ;
V_28 = 0 ;
}
goto V_61;
}
if ( V_2 -> V_62 == V_63 ) {
F_8 ( V_30 L_2
L_3 ,
V_25 -> V_31 ) ;
V_28 = - V_64 ;
goto V_61;
}
if ( V_2 -> V_33 != V_65 ) {
F_8 ( V_30 L_4
L_5 , V_25 -> V_31 ) ;
V_28 = - V_64 ;
goto V_61;
}
if ( V_2 -> V_62 == V_66 &&
strlen ( V_2 -> V_67 ) == 0 ) {
F_8 ( V_30 L_6
L_7 , V_25 -> V_31 ) ;
V_28 = - V_64 ;
goto V_61;
}
V_2 -> V_59 = 1 ;
memcpy ( V_2 -> V_60 , & V_51 -> V_57 , V_58 ) ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_17 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_28 = 0 ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_51 -> V_68 = V_69 ;
V_28 = F_18 ( V_2 , V_51 -> V_57 ) ;
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_19 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_70 * V_71 ,
char * V_72 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_71 -> V_29 & V_73 ) - 1 ;
int V_74 = V_2 -> V_75 ;
enum V_4 V_76 = V_2 -> V_76 ;
int V_77 = V_2 -> V_78 ;
int V_28 = - V_53 ;
unsigned long V_29 ;
if ( ! V_2 -> V_79 )
return - V_64 ;
if ( V_71 -> V_80 ) {
if ( V_71 -> V_81 > V_82 )
return - V_83 ;
if ( ( V_71 -> V_81 > V_18 ) && ! V_2 -> V_84 )
return - V_83 ;
}
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( ( V_2 -> V_85 ) && ( V_2 -> V_76 == V_14 ) )
( void ) F_20 ( V_2 , V_74 ) ;
if ( V_71 -> V_81 > 0 ) {
if ( ( V_3 < 0 ) || ( V_3 >= V_86 ) )
V_3 = V_2 -> V_75 ;
if ( V_76 != V_17 ) {
V_74 = V_3 ;
V_76 = V_17 ;
}
} else {
if ( ( V_3 < 0 ) || ( V_3 >= V_86 ) ) {
if ( ( V_3 != - 1 ) || ( V_71 -> V_29 == 0 ) ) {
V_28 = - V_87 ;
goto V_61;
}
} else {
if ( V_2 -> V_10 [ V_3 ] . V_7 == 0 ) {
V_28 = - V_87 ;
goto V_61;
}
V_74 = V_3 ;
}
}
if ( V_71 -> V_29 & V_88 )
V_76 = V_21 ;
if ( V_71 -> V_29 & V_89 )
V_77 = 0 ;
if ( V_71 -> V_29 & V_90 )
V_77 = 1 ;
if ( V_71 -> V_80 && V_71 -> V_81 > 0 ) {
V_28 = F_1 ( V_2 , V_3 , V_17 , V_72 ,
V_71 -> V_81 , NULL , 0 ) ;
}
V_2 -> V_75 = V_74 ;
if ( ( V_2 -> V_76 == V_76 ) &&
( V_2 -> V_78 == V_77 ) &&
F_21 ( V_25 ) ) {
V_28 = F_22 ( V_2 ) ;
goto V_61;
}
V_2 -> V_76 = V_76 ;
V_2 -> V_78 = V_77 ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_70 * V_71 ,
char * V_72 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_71 -> V_29 & V_73 ) - 1 ;
unsigned long V_29 ;
if ( ! V_2 -> V_79 )
return - V_64 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( ( V_3 < 0 ) || ( V_3 >= V_86 ) )
V_3 = V_2 -> V_75 ;
V_71 -> V_29 = 0 ;
if ( ! V_2 -> V_76 )
V_71 -> V_29 |= V_88 ;
V_71 -> V_29 |= V_3 + 1 ;
if ( V_2 -> V_78 )
V_71 -> V_29 |= V_90 ;
else
V_71 -> V_29 |= V_89 ;
V_71 -> V_81 = V_2 -> V_10 [ V_3 ] . V_7 ;
memcpy ( V_72 , V_2 -> V_10 [ V_3 ] . V_6 , V_71 -> V_81 ) ;
F_14 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_70 * V_71 ,
char * V_91 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_29 ;
if ( V_71 -> V_81 > V_92 )
return - V_83 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
memset ( V_2 -> V_67 , 0 , sizeof( V_2 -> V_67 ) ) ;
if ( V_71 -> V_29 )
memcpy ( V_2 -> V_67 , V_91 , V_71 -> V_81 ) ;
F_14 ( V_2 , & V_29 ) ;
return - V_53 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_70 * V_71 ,
char * V_91 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_93 ;
int V_28 = 0 ;
unsigned long V_29 ;
if ( F_26 ( V_25 ) ) {
V_28 = F_27 ( V_2 , & V_93 , V_91 ) ;
if ( V_28 < 0 )
return V_28 ;
V_71 -> V_81 = V_28 ;
} else {
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
memcpy ( V_91 , V_2 -> V_67 , V_92 ) ;
V_71 -> V_81 = strlen ( V_2 -> V_67 ) ;
F_14 ( V_2 , & V_29 ) ;
}
V_71 -> V_29 = 1 ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_94 * V_95 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_96 = - 1 ;
unsigned long V_29 ;
int V_28 = - V_53 ;
if ( V_2 -> V_33 == V_65 )
return - V_56 ;
if ( ( V_95 -> V_97 == 0 ) && ( V_95 -> V_98 <= 1000 ) ) {
V_96 = V_95 -> V_98 ;
} else {
int V_99 = 1 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < ( 6 - V_95 -> V_97 ) ; V_100 ++ )
V_99 *= 10 ;
V_96 = F_29 ( V_95 -> V_98 / V_99 ) ;
}
if ( ( V_96 < 1 ) || ( V_96 > V_101 ) ||
! ( V_2 -> V_102 & ( 1 << ( V_96 - 1 ) ) ) )
return - V_87 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_2 -> V_103 = V_96 ;
if ( V_2 -> V_33 == V_104 ) {
T_2 * V_26 = & V_2 -> V_26 ;
V_28 = V_26 -> V_105 -> V_106 ( V_26 , V_107 |
V_108 ,
V_96 , NULL ) ;
}
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_94 * V_95 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_109 ;
V_109 = F_31 ( V_2 ) ;
if ( V_109 < 0 )
return V_109 ;
V_95 -> V_98 = V_109 * 100000 ;
V_95 -> V_97 = 1 ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_111 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 * V_26 = & V_2 -> V_26 ;
T_4 V_112 ;
int V_28 ;
unsigned long V_29 ;
if ( ! V_2 -> V_113 )
return - V_64 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_28 = F_33 ( V_26 , V_44 ,
V_114 , & V_112 ) ;
F_14 ( V_2 , & V_29 ) ;
if ( V_28 )
return V_28 ;
V_111 -> V_115 = V_112 ;
V_111 -> V_116 = 0 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_111 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_112 = V_111 -> V_115 ;
unsigned long V_29 ;
if ( ! V_2 -> V_113 )
return - V_64 ;
if ( ( V_112 < 1 ) || ( V_112 > 3 ) )
return - V_87 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_2 -> V_117 = V_112 ;
F_14 ( V_2 , & V_29 ) ;
return - V_53 ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_118 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_119 ;
int V_120 ;
unsigned long V_29 ;
if ( V_118 -> V_115 == - 1 )
V_120 = 110 ;
else {
if ( V_118 -> V_115 % 100000 )
return - V_87 ;
V_120 = V_118 -> V_115 / 100000 ;
}
V_119 = F_36 ( V_120 , ! V_118 -> V_116 ) ;
if ( V_119 == - 1 )
return - V_87 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_2 -> V_121 = V_119 ;
F_14 ( V_2 , & V_29 ) ;
return - V_53 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_118 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_28 = 0 ;
int V_120 , V_122 ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
F_38 ( V_2 -> V_121 , & V_120 , & V_122 ) ;
if ( F_26 ( V_25 ) ) {
int V_123 ;
int V_124 ;
V_124 = F_39 ( V_2 , & V_123 ) ;
if ( ! V_124 )
V_120 = V_123 ;
}
F_14 ( V_2 , & V_29 ) ;
V_118 -> V_115 = V_120 ;
V_118 -> V_116 = ! V_122 ;
V_118 -> V_125 = 0 ;
return V_28 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_126 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_28 = - V_53 ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( V_126 -> V_125 ) {
V_2 -> V_127 = 0 ;
} else {
switch ( V_126 -> V_29 & V_128 ) {
case V_129 :
V_2 -> V_130 = 0 ;
V_2 -> V_127 = 1 ;
break;
case V_131 :
V_2 -> V_130 = 1 ;
V_2 -> V_127 = 1 ;
break;
case V_132 :
break;
default:
V_28 = - V_87 ;
goto V_61;
}
if ( V_126 -> V_29 & V_133 ) {
V_2 -> V_127 = 1 ;
V_2 -> V_134 = V_126 -> V_115 / 1000 ;
}
if ( V_126 -> V_29 & V_135 ) {
V_2 -> V_127 = 1 ;
V_2 -> V_136 = V_126 -> V_115 / 1000 ;
}
if ( ! V_2 -> V_127 ) {
V_28 = - V_87 ;
goto V_61;
}
}
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_110 * V_126 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 * V_26 = & V_2 -> V_26 ;
int V_28 = 0 ;
T_4 V_137 , V_138 , V_139 , V_140 ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_28 = F_33 ( V_26 , V_44 ,
V_141 , & V_137 ) ;
if ( V_28 )
goto V_61;
V_28 = F_33 ( V_26 , V_44 ,
V_142 , & V_138 ) ;
if ( V_28 )
goto V_61;
V_28 = F_33 ( V_26 , V_44 ,
V_143 , & V_139 ) ;
if ( V_28 )
goto V_61;
V_28 = F_33 ( V_26 , V_44 ,
V_144 , & V_140 ) ;
if ( V_28 )
goto V_61;
V_126 -> V_125 = ! V_137 ;
if ( ( V_126 -> V_29 & V_145 ) == V_133 ) {
V_126 -> V_29 = V_133 ;
V_126 -> V_115 = V_139 * 1000 ;
} else {
V_126 -> V_29 = V_135 ;
V_126 -> V_115 = V_138 * 1000 ;
}
if ( V_140 )
V_126 -> V_29 |= V_131 ;
else
V_126 -> V_29 |= V_129 ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_70 * V_148 = & V_147 -> V_148 ;
struct V_149 * V_150 = (struct V_149 * ) V_52 ;
int V_151 , V_5 = V_150 -> V_5 , V_152 = 1 ;
unsigned long V_29 ;
int V_28 = - V_87 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_151 = V_148 -> V_29 & V_73 ;
if ( V_151 ) {
if ( ( V_151 < 1 ) || ( V_151 > 4 ) )
goto V_61;
V_151 -- ;
} else
V_151 = V_2 -> V_75 ;
if ( V_148 -> V_29 & V_88 )
V_5 = V_153 ;
if ( V_2 -> V_85 && ( V_5 != V_154 ) ) {
( void ) F_20 ( V_2 , V_2 -> V_75 ) ;
}
if ( V_150 -> V_155 & V_156 ) {
V_2 -> V_75 = V_151 ;
V_152 = ( ( V_5 == V_154 ) ||
( V_150 -> V_7 > 0 ) ) ? 1 : 0 ;
}
if ( V_152 ) {
switch ( V_5 ) {
case V_153 :
V_2 -> V_76 = V_21 ;
V_28 = F_1 ( V_2 , V_151 , V_21 ,
NULL , 0 , NULL , 0 ) ;
break;
case V_157 :
if ( V_150 -> V_7 <= 0 )
goto V_61;
V_2 -> V_76 = V_17 ;
V_28 = F_1 ( V_2 , V_151 , V_17 ,
V_150 -> V_6 , V_150 -> V_7 , NULL , 0 ) ;
break;
case V_154 :
{
T_1 * V_158 = NULL ;
if ( ! V_2 -> V_85 ||
( V_150 -> V_7 > sizeof( struct V_159 ) ) )
goto V_61;
V_2 -> V_76 = V_14 ;
if ( V_150 -> V_155 & V_160 )
V_158 = & V_150 -> V_161 [ 0 ] ;
V_28 = F_1 ( V_2 , V_151 , V_14 ,
V_150 -> V_6 , V_150 -> V_7 , V_158 ,
V_162 ) ;
V_28 = F_43 ( V_2 , V_151 ,
V_150 -> V_155 & V_156 ,
V_2 -> V_10 [ V_151 ] . V_6 ,
V_158 , V_162 , NULL , 0 ) ;
if ( V_28 )
F_8 ( V_163 L_8
L_9 , V_25 -> V_31 , V_28 ) ;
goto V_61;
}
default:
goto V_61;
}
}
V_28 = - V_53 ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_70 * V_148 = & V_147 -> V_148 ;
struct V_149 * V_150 = (struct V_149 * ) V_52 ;
int V_151 , V_164 ;
unsigned long V_29 ;
int V_28 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_28 = - V_87 ;
V_164 = V_148 -> V_81 - sizeof( * V_150 ) ;
if ( V_164 < 0 )
goto V_61;
V_151 = V_148 -> V_29 & V_73 ;
if ( V_151 ) {
if ( ( V_151 < 1 ) || ( V_151 > 4 ) )
goto V_61;
V_151 -- ;
} else
V_151 = V_2 -> V_75 ;
V_148 -> V_29 = V_151 + 1 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
switch ( V_2 -> V_76 ) {
case V_21 :
V_150 -> V_5 = V_153 ;
V_150 -> V_7 = 0 ;
V_148 -> V_29 |= V_88 ;
break;
case V_17 :
V_150 -> V_5 = V_157 ;
V_150 -> V_7 = F_45 ( V_2 -> V_10 [ V_151 ] . V_7 , V_164 ) ;
memcpy ( V_150 -> V_6 , V_2 -> V_10 [ V_151 ] . V_6 , V_150 -> V_7 ) ;
V_148 -> V_29 |= V_165 ;
break;
case V_14 :
V_150 -> V_5 = V_154 ;
V_150 -> V_7 = F_45 ( V_2 -> V_10 [ V_151 ] . V_7 , V_164 ) ;
memcpy ( V_150 -> V_6 , V_2 -> V_10 [ V_151 ] . V_6 , V_150 -> V_7 ) ;
V_148 -> V_29 |= V_165 ;
break;
}
V_28 = 0 ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_46 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 , char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 * V_26 = & V_2 -> V_26 ;
struct V_110 * V_166 = & V_147 -> V_166 ;
unsigned long V_29 ;
int V_167 = - V_53 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
switch ( V_166 -> V_29 & V_168 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
break;
case V_175 :
if ( V_166 -> V_115 == V_176 )
V_167 = - V_87 ;
break;
case V_177 :
V_2 -> V_178 = V_166 -> V_115 ;
break;
case V_179 :
if ( V_166 -> V_115 ) {
V_2 -> V_180 = 1 ;
V_167 = F_47 ( V_26 , 0 ) ;
} else {
V_2 -> V_180 = 0 ;
V_167 = F_48 ( V_26 , 0 ) ;
}
break;
case V_181 :
if ( V_166 -> V_115 & V_182 )
V_2 -> V_78 = 1 ;
else if ( V_166 -> V_115 & V_183 )
V_2 -> V_78 = 0 ;
else
V_167 = - V_87 ;
break;
case V_184 :
if ( V_2 -> V_85 ) {
V_2 -> V_185 = V_166 -> V_115 ? 1 : 0 ;
} else {
if ( V_166 -> V_115 )
V_167 = - V_64 ;
V_2 -> V_185 = 0 ;
}
break;
default:
V_167 = - V_64 ;
}
F_14 ( V_2 , & V_29 ) ;
return V_167 ;
}
static int F_49 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 , char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_110 * V_166 = & V_147 -> V_166 ;
unsigned long V_29 ;
int V_167 = 0 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
switch ( V_166 -> V_29 & V_168 ) {
case V_177 :
V_166 -> V_115 = V_2 -> V_178 ;
break;
case V_179 :
V_166 -> V_115 = V_2 -> V_180 ;
break;
case V_181 :
if ( V_2 -> V_78 )
V_166 -> V_115 = V_182 ;
else
V_166 -> V_115 = V_183 ;
break;
case V_184 :
V_166 -> V_115 = V_2 -> V_185 ;
break;
default:
V_167 = - V_64 ;
}
F_14 ( V_2 , & V_29 ) ;
return V_167 ;
}
static int F_50 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 , char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 * V_186 ;
unsigned long V_29 ;
if ( ( V_147 -> V_187 . V_81 > V_188 ) ||
( V_147 -> V_187 . V_81 && ( V_52 == NULL ) ) )
return - V_87 ;
if ( V_147 -> V_187 . V_81 ) {
V_186 = F_51 ( V_52 , V_147 -> V_187 . V_81 , V_189 ) ;
if ( V_186 == NULL )
return - V_22 ;
} else
V_186 = NULL ;
if ( F_9 ( V_2 , & V_29 ) != 0 ) {
F_4 ( V_186 ) ;
return - V_56 ;
}
F_4 ( V_2 -> V_190 ) ;
V_2 -> V_190 = V_186 ;
V_2 -> V_191 = V_147 -> V_187 . V_81 ;
if ( V_2 -> V_190 ) {
}
F_14 ( V_2 , & V_29 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 , char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_29 ;
int V_28 = 0 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( ( V_2 -> V_191 == 0 ) || ( V_2 -> V_190 == NULL ) ) {
V_147 -> V_187 . V_81 = 0 ;
goto V_61;
}
if ( V_147 -> V_187 . V_81 < V_2 -> V_191 ) {
V_28 = - V_83 ;
goto V_61;
}
V_147 -> V_187 . V_81 = V_2 -> V_191 ;
memcpy ( V_52 , V_2 -> V_190 , V_2 -> V_191 ) ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_53 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
union V_146 * V_147 , char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_192 * V_193 = (struct V_192 * ) V_52 ;
unsigned long V_29 ;
int V_167 = 0 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
switch ( V_193 -> V_194 ) {
case V_195 :
break;
case V_196 :
V_167 = F_54 ( V_2 , V_193 -> V_197 . V_57 ,
V_193 -> V_198 ) ;
break;
default:
V_167 = - V_64 ;
}
F_14 ( V_2 , & V_29 ) ;
return V_167 ;
}
static int F_55 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_56 ( V_199 ) )
return - V_200 ;
if ( V_49 -> V_194 == ( V_201 + 0x1 ) ) {
F_8 ( V_202 L_10 , V_25 -> V_31 ) ;
F_57 ( & V_2 -> V_203 ) ;
} else {
F_8 ( V_202 L_11 , V_25 -> V_31 ) ;
F_58 ( & V_2 -> V_203 ) ;
}
return 0 ;
}
static int F_59 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_112 = * ( ( int * ) V_52 ) ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_2 -> V_204 = V_112 ;
F_60 ( V_2 ) ;
F_14 ( V_2 , & V_29 ) ;
return - V_53 ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_112 = ( int * ) V_52 ;
* V_112 = V_2 -> V_204 ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_112 = * ( ( int * ) V_52 ) ;
int V_28 = 0 ;
unsigned long V_29 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
switch ( V_112 ) {
case 0 :
if ( ! V_2 -> V_205 ) {
V_28 = - V_87 ;
break;
}
V_2 -> V_206 = 0 ;
break;
case 1 :
if ( ! V_2 -> V_207 ) {
V_28 = - V_87 ;
break;
}
V_2 -> V_206 = 1 ;
break;
default:
V_28 = - V_87 ;
}
if ( ! V_28 ) {
F_60 ( V_2 ) ;
V_28 = - V_53 ;
}
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_63 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_112 = ( int * ) V_52 ;
* V_112 = V_2 -> V_206 ;
return 0 ;
}
static int F_64 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_29 ;
int V_112 ;
if ( ! V_2 -> V_208 )
return - V_64 ;
V_112 = * ( ( int * ) V_52 ) ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
if ( V_112 )
V_2 -> V_209 = 1 ;
else
V_2 -> V_209 = 0 ;
F_14 ( V_2 , & V_29 ) ;
return - V_53 ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_112 = ( int * ) V_52 ;
if ( ! V_2 -> V_208 )
return - V_64 ;
* V_112 = V_2 -> V_209 ;
return 0 ;
}
static int F_66 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
struct V_70 * V_187 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_2 * V_26 = & V_2 -> V_26 ;
int V_210 = V_187 -> V_29 ;
T_4 V_81 ;
int V_28 ;
unsigned long V_29 ;
if ( ! F_56 ( V_199 ) )
return - V_200 ;
if ( V_210 < 0xfc00 || V_210 > 0xffff )
return - V_87 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return - V_56 ;
V_28 = V_26 -> V_105 -> V_211 ( V_26 , V_44 , V_210 , V_212 , & V_81 ,
V_52 ) ;
if ( V_28 )
goto V_61;
V_187 -> V_81 = F_67 ( T_4 , F_68 ( V_81 ) ,
V_212 ) ;
V_61:
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
static int F_69 ( struct V_24 * V_25 ,
struct V_48 * V_49 ,
void * V_147 ,
char * V_52 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_29 ;
int V_28 = 0 ;
if ( ! V_2 -> V_213 )
return 0 ;
if ( F_9 ( V_2 , & V_29 ) != 0 )
return V_28 ;
V_28 = F_70 ( V_2 ) ;
F_14 ( V_2 , & V_29 ) ;
return V_28 ;
}
