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
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_23 * V_28 = & V_2 -> V_28 ;
int V_29 ;
unsigned long V_30 ;
if ( ! F_7 ( V_25 ) ) {
F_8 ( V_31 L_1 ,
V_25 -> V_32 ) ;
return NULL ;
}
if ( F_9 ( V_2 , & V_30 ) != 0 )
return V_28 ;
F_10 ( V_27 , V_33 ) ;
if ( V_2 -> V_34 == V_35 ) {
memset ( & V_28 -> V_36 , 0 , sizeof( V_28 -> V_36 ) ) ;
if ( F_11 ( V_2 ) ) {
V_28 -> V_36 . V_36 = V_2 -> V_37 . V_38 [ 0 ] . V_36 ;
V_28 -> V_36 . V_39 = V_2 -> V_37 . V_38 [ 0 ] . V_39 ;
V_28 -> V_36 . V_40 = V_2 -> V_37 . V_38 [ 0 ] . V_40 ;
V_28 -> V_36 . V_41 =
V_2 -> V_37 . V_38 [ 0 ] . V_41 ;
}
} else {
struct {
T_2 V_36 , signal , V_40 , V_42 ;
} V_43 V_44 ;
V_29 = F_12 ( V_27 , V_45 ,
V_46 , & V_44 ) ;
if ( ! V_29 ) {
V_28 -> V_36 . V_36 = ( int ) F_13 ( V_44 . V_36 ) ;
V_28 -> V_36 . V_39 = ( int ) F_13 ( V_44 . signal ) - 0x95 ;
V_28 -> V_36 . V_40 = ( int ) F_13 ( V_44 . V_40 ) - 0x95 ;
V_28 -> V_36 . V_41 =
V_47 | V_48 ;
}
}
F_14 ( V_2 , & V_30 ) ;
return V_28 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = - V_54 ;
unsigned long V_30 ;
static const T_1 V_55 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const T_1 V_56 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( memcmp ( & V_52 -> V_58 , V_55 , V_59 ) == 0 ||
memcmp ( & V_52 -> V_58 , V_56 , V_59 ) == 0 ) {
V_2 -> V_60 = 0 ;
memset ( V_2 -> V_61 , 0 , V_59 ) ;
if ( V_52 -> V_58 [ 0 ] == 0 ) {
F_16 ( V_2 ) ;
V_29 = 0 ;
}
goto V_62;
}
if ( V_2 -> V_63 == V_64 ) {
F_8 ( V_31 L_2
L_3 ,
V_25 -> V_32 ) ;
V_29 = - V_65 ;
goto V_62;
}
if ( V_2 -> V_34 != V_66 ) {
F_8 ( V_31 L_4
L_5 , V_25 -> V_32 ) ;
V_29 = - V_65 ;
goto V_62;
}
if ( V_2 -> V_63 == V_67 &&
strlen ( V_2 -> V_68 ) == 0 ) {
F_8 ( V_31 L_6
L_7 , V_25 -> V_32 ) ;
V_29 = - V_65 ;
goto V_62;
}
V_2 -> V_60 = 1 ;
memcpy ( V_2 -> V_61 , & V_52 -> V_58 , V_59 ) ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_17 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_52 -> V_69 = V_70 ;
V_29 = F_18 ( V_2 , V_52 -> V_58 ) ;
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_19 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_72 -> V_30 & V_74 ) - 1 ;
int V_75 = V_2 -> V_76 ;
enum V_4 V_77 = V_2 -> V_77 ;
int V_78 = V_2 -> V_79 ;
int V_29 = - V_54 ;
unsigned long V_30 ;
if ( ! V_2 -> V_80 )
return - V_65 ;
if ( V_72 -> V_81 ) {
if ( V_72 -> V_82 > V_83 )
return - V_84 ;
if ( ( V_72 -> V_82 > V_18 ) && ! V_2 -> V_85 )
return - V_84 ;
}
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( ( V_2 -> V_86 ) && ( V_2 -> V_77 == V_14 ) )
( void ) F_20 ( V_2 , V_75 ) ;
if ( V_72 -> V_82 > 0 ) {
if ( ( V_3 < 0 ) || ( V_3 >= V_87 ) )
V_3 = V_2 -> V_76 ;
if ( V_77 != V_17 ) {
V_75 = V_3 ;
V_77 = V_17 ;
}
} else {
if ( ( V_3 < 0 ) || ( V_3 >= V_87 ) ) {
if ( ( V_3 != - 1 ) || ( V_72 -> V_30 == 0 ) ) {
V_29 = - V_88 ;
goto V_62;
}
} else {
if ( V_2 -> V_10 [ V_3 ] . V_7 == 0 ) {
V_29 = - V_88 ;
goto V_62;
}
V_75 = V_3 ;
}
}
if ( V_72 -> V_30 & V_89 )
V_77 = V_21 ;
if ( V_72 -> V_30 & V_90 )
V_78 = 0 ;
if ( V_72 -> V_30 & V_91 )
V_78 = 1 ;
if ( V_72 -> V_81 && V_72 -> V_82 > 0 ) {
V_29 = F_1 ( V_2 , V_3 , V_17 , V_73 ,
V_72 -> V_82 , NULL , 0 ) ;
}
V_2 -> V_76 = V_75 ;
if ( ( V_2 -> V_77 == V_77 ) &&
( V_2 -> V_79 == V_78 ) &&
F_21 ( V_25 ) ) {
V_29 = F_22 ( V_2 ) ;
goto V_62;
}
V_2 -> V_77 = V_77 ;
V_2 -> V_79 = V_78 ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_71 * V_72 ,
char * V_73 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_72 -> V_30 & V_74 ) - 1 ;
unsigned long V_30 ;
if ( ! V_2 -> V_80 )
return - V_65 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( ( V_3 < 0 ) || ( V_3 >= V_87 ) )
V_3 = V_2 -> V_76 ;
V_72 -> V_30 = 0 ;
if ( ! V_2 -> V_77 )
V_72 -> V_30 |= V_89 ;
V_72 -> V_30 |= V_3 + 1 ;
if ( V_2 -> V_79 )
V_72 -> V_30 |= V_91 ;
else
V_72 -> V_30 |= V_90 ;
V_72 -> V_82 = V_2 -> V_10 [ V_3 ] . V_7 ;
memcpy ( V_73 , V_2 -> V_10 [ V_3 ] . V_6 , V_72 -> V_82 ) ;
F_14 ( V_2 , & V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_71 * V_72 ,
char * V_92 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
if ( V_72 -> V_82 > V_93 )
return - V_84 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
memset ( V_2 -> V_68 , 0 , sizeof( V_2 -> V_68 ) ) ;
if ( V_72 -> V_30 )
memcpy ( V_2 -> V_68 , V_92 , V_72 -> V_82 ) ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_71 * V_72 ,
char * V_92 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_94 ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_26 ( V_25 ) ) {
V_29 = F_27 ( V_2 , & V_94 , V_92 ) ;
if ( V_29 < 0 )
return V_29 ;
V_72 -> V_82 = V_29 ;
} else {
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
memcpy ( V_92 , V_2 -> V_68 , V_93 ) ;
V_72 -> V_82 = strlen ( V_2 -> V_68 ) ;
F_14 ( V_2 , & V_30 ) ;
}
V_72 -> V_30 = 1 ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_95 * V_96 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_97 = - 1 ;
unsigned long V_30 ;
int V_29 = - V_54 ;
if ( V_2 -> V_34 == V_66 )
return - V_57 ;
if ( ( V_96 -> V_98 == 0 ) && ( V_96 -> V_99 <= 1000 ) ) {
V_97 = V_96 -> V_99 ;
} else {
int V_100 = 1 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < ( 6 - V_96 -> V_98 ) ; V_101 ++ )
V_100 *= 10 ;
V_97 = F_29 ( V_96 -> V_99 / V_100 ) ;
}
if ( ( V_97 < 1 ) || ( V_97 > V_102 ) ||
! ( V_2 -> V_103 & ( 1 << ( V_97 - 1 ) ) ) )
return - V_88 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_2 -> V_104 = V_97 ;
if ( V_2 -> V_34 == V_105 ) {
struct V_26 * V_27 = & V_2 -> V_27 ;
V_29 = V_27 -> V_106 -> V_107 ( V_27 , V_108 |
V_109 ,
V_97 , NULL ) ;
}
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_95 * V_96 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_110 ;
V_110 = F_31 ( V_2 ) ;
if ( V_110 < 0 )
return V_110 ;
V_96 -> V_99 = V_110 * 100000 ;
V_96 -> V_98 = 1 ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_112 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
T_3 V_113 ;
int V_29 ;
unsigned long V_30 ;
if ( ! V_2 -> V_114 )
return - V_65 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_29 = F_33 ( V_27 , V_45 ,
V_115 , & V_113 ) ;
F_14 ( V_2 , & V_30 ) ;
if ( V_29 )
return V_29 ;
V_112 -> V_116 = V_113 ;
V_112 -> V_117 = 0 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_112 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_113 = V_112 -> V_116 ;
unsigned long V_30 ;
if ( ! V_2 -> V_114 )
return - V_65 ;
if ( ( V_113 < 1 ) || ( V_113 > 3 ) )
return - V_88 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_2 -> V_118 = V_113 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_119 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_120 ;
int V_121 ;
unsigned long V_30 ;
if ( V_119 -> V_116 == - 1 )
V_121 = 110 ;
else {
if ( V_119 -> V_116 % 100000 )
return - V_88 ;
V_121 = V_119 -> V_116 / 100000 ;
}
V_120 = F_36 ( V_121 , ! V_119 -> V_117 ) ;
if ( V_120 == - 1 )
return - V_88 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_2 -> V_122 = V_120 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_119 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = 0 ;
int V_121 , V_123 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
F_38 ( V_2 -> V_122 , & V_121 , & V_123 ) ;
if ( F_26 ( V_25 ) ) {
int V_124 ;
int V_125 ;
V_125 = F_39 ( V_2 , & V_124 ) ;
if ( ! V_125 )
V_121 = V_124 ;
}
F_14 ( V_2 , & V_30 ) ;
V_119 -> V_116 = V_121 ;
V_119 -> V_117 = ! V_123 ;
V_119 -> V_126 = 0 ;
return V_29 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_127 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = - V_54 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( V_127 -> V_126 ) {
V_2 -> V_128 = 0 ;
} else {
switch ( V_127 -> V_30 & V_129 ) {
case V_130 :
V_2 -> V_131 = 0 ;
V_2 -> V_128 = 1 ;
break;
case V_132 :
V_2 -> V_131 = 1 ;
V_2 -> V_128 = 1 ;
break;
case V_133 :
break;
default:
V_29 = - V_88 ;
goto V_62;
}
if ( V_127 -> V_30 & V_134 ) {
V_2 -> V_128 = 1 ;
V_2 -> V_135 = V_127 -> V_116 / 1000 ;
}
if ( V_127 -> V_30 & V_136 ) {
V_2 -> V_128 = 1 ;
V_2 -> V_137 = V_127 -> V_116 / 1000 ;
}
if ( ! V_2 -> V_128 ) {
V_29 = - V_88 ;
goto V_62;
}
}
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_111 * V_127 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
int V_29 = 0 ;
T_3 V_138 , V_139 , V_140 , V_141 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_29 = F_33 ( V_27 , V_45 ,
V_142 , & V_138 ) ;
if ( V_29 )
goto V_62;
V_29 = F_33 ( V_27 , V_45 ,
V_143 , & V_139 ) ;
if ( V_29 )
goto V_62;
V_29 = F_33 ( V_27 , V_45 ,
V_144 , & V_140 ) ;
if ( V_29 )
goto V_62;
V_29 = F_33 ( V_27 , V_45 ,
V_145 , & V_141 ) ;
if ( V_29 )
goto V_62;
V_127 -> V_126 = ! V_138 ;
if ( ( V_127 -> V_30 & V_146 ) == V_134 ) {
V_127 -> V_30 = V_134 ;
V_127 -> V_116 = V_140 * 1000 ;
} else {
V_127 -> V_30 = V_136 ;
V_127 -> V_116 = V_139 * 1000 ;
}
if ( V_141 )
V_127 -> V_30 |= V_132 ;
else
V_127 -> V_30 |= V_130 ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_71 * V_149 = & V_148 -> V_149 ;
struct V_150 * V_151 = (struct V_150 * ) V_53 ;
int V_152 , V_5 = V_151 -> V_5 , V_153 = 1 ;
unsigned long V_30 ;
int V_29 = - V_88 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_152 = V_149 -> V_30 & V_74 ;
if ( V_152 ) {
if ( ( V_152 < 1 ) || ( V_152 > 4 ) )
goto V_62;
V_152 -- ;
} else
V_152 = V_2 -> V_76 ;
if ( V_149 -> V_30 & V_89 )
V_5 = V_154 ;
if ( V_2 -> V_86 && ( V_5 != V_155 ) ) {
( void ) F_20 ( V_2 , V_2 -> V_76 ) ;
}
if ( V_151 -> V_156 & V_157 ) {
V_2 -> V_76 = V_152 ;
V_153 = ( ( V_5 == V_155 ) ||
( V_151 -> V_7 > 0 ) ) ? 1 : 0 ;
}
if ( V_153 ) {
switch ( V_5 ) {
case V_154 :
V_2 -> V_77 = V_21 ;
V_29 = F_1 ( V_2 , V_152 , V_21 ,
NULL , 0 , NULL , 0 ) ;
break;
case V_158 :
if ( V_151 -> V_7 <= 0 )
goto V_62;
V_2 -> V_77 = V_17 ;
V_29 = F_1 ( V_2 , V_152 , V_17 ,
V_151 -> V_6 , V_151 -> V_7 , NULL , 0 ) ;
break;
case V_155 :
{
T_1 * V_159 = NULL ;
if ( ! V_2 -> V_86 ||
( V_151 -> V_7 > sizeof( struct V_160 ) ) )
goto V_62;
V_2 -> V_77 = V_14 ;
if ( V_151 -> V_156 & V_161 )
V_159 = & V_151 -> V_162 [ 0 ] ;
V_29 = F_1 ( V_2 , V_152 , V_14 ,
V_151 -> V_6 , V_151 -> V_7 , V_159 ,
V_163 ) ;
V_29 = F_43 ( V_2 , V_152 ,
V_151 -> V_156 & V_157 ,
V_2 -> V_10 [ V_152 ] . V_6 ,
V_159 , V_163 , NULL , 0 ) ;
if ( V_29 )
F_8 ( V_164 L_8
L_9 , V_25 -> V_32 , V_29 ) ;
goto V_62;
}
default:
goto V_62;
}
}
V_29 = - V_54 ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_71 * V_149 = & V_148 -> V_149 ;
struct V_150 * V_151 = (struct V_150 * ) V_53 ;
int V_152 , V_165 ;
unsigned long V_30 ;
int V_29 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_29 = - V_88 ;
V_165 = V_149 -> V_82 - sizeof( * V_151 ) ;
if ( V_165 < 0 )
goto V_62;
V_152 = V_149 -> V_30 & V_74 ;
if ( V_152 ) {
if ( ( V_152 < 1 ) || ( V_152 > 4 ) )
goto V_62;
V_152 -- ;
} else
V_152 = V_2 -> V_76 ;
V_149 -> V_30 = V_152 + 1 ;
memset ( V_151 , 0 , sizeof( * V_151 ) ) ;
switch ( V_2 -> V_77 ) {
case V_21 :
V_151 -> V_5 = V_154 ;
V_151 -> V_7 = 0 ;
V_149 -> V_30 |= V_89 ;
break;
case V_17 :
V_151 -> V_5 = V_158 ;
V_151 -> V_7 = F_45 ( V_2 -> V_10 [ V_152 ] . V_7 , V_165 ) ;
memcpy ( V_151 -> V_6 , V_2 -> V_10 [ V_152 ] . V_6 , V_151 -> V_7 ) ;
V_149 -> V_30 |= V_166 ;
break;
case V_14 :
V_151 -> V_5 = V_155 ;
V_151 -> V_7 = F_45 ( V_2 -> V_10 [ V_152 ] . V_7 , V_165 ) ;
memcpy ( V_151 -> V_6 , V_2 -> V_10 [ V_152 ] . V_6 , V_151 -> V_7 ) ;
V_149 -> V_30 |= V_166 ;
break;
}
V_29 = 0 ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_46 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_111 * V_167 = & V_148 -> V_167 ;
unsigned long V_30 ;
int V_168 = - V_54 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
switch ( V_167 -> V_30 & V_169 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
break;
case V_176 :
if ( V_167 -> V_116 == V_177 )
V_168 = - V_88 ;
break;
case V_178 :
V_2 -> V_179 = V_167 -> V_116 ;
break;
case V_180 :
if ( V_167 -> V_116 ) {
V_2 -> V_181 = 1 ;
V_168 = F_47 ( V_27 , 0 ) ;
} else {
V_2 -> V_181 = 0 ;
V_168 = F_48 ( V_27 , 0 ) ;
}
break;
case V_182 :
if ( V_167 -> V_116 & V_183 )
V_2 -> V_79 = 1 ;
else if ( V_167 -> V_116 & V_184 )
V_2 -> V_79 = 0 ;
else
V_168 = - V_88 ;
break;
case V_185 :
if ( V_2 -> V_86 ) {
V_2 -> V_186 = V_167 -> V_116 ? 1 : 0 ;
} else {
if ( V_167 -> V_116 )
V_168 = - V_65 ;
V_2 -> V_186 = 0 ;
}
break;
default:
V_168 = - V_65 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_168 ;
}
static int F_49 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_111 * V_167 = & V_148 -> V_167 ;
unsigned long V_30 ;
int V_168 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
switch ( V_167 -> V_30 & V_169 ) {
case V_178 :
V_167 -> V_116 = V_2 -> V_179 ;
break;
case V_180 :
V_167 -> V_116 = V_2 -> V_181 ;
break;
case V_182 :
if ( V_2 -> V_79 )
V_167 -> V_116 = V_183 ;
else
V_167 -> V_116 = V_184 ;
break;
case V_185 :
V_167 -> V_116 = V_2 -> V_186 ;
break;
default:
V_168 = - V_65 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_168 ;
}
static int F_50 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 * V_187 ;
unsigned long V_30 ;
if ( ( V_148 -> V_188 . V_82 > V_189 ) ||
( V_148 -> V_188 . V_82 && ( V_53 == NULL ) ) )
return - V_88 ;
if ( V_148 -> V_188 . V_82 ) {
V_187 = F_51 ( V_53 , V_148 -> V_188 . V_82 , V_190 ) ;
if ( V_187 == NULL )
return - V_22 ;
} else
V_187 = NULL ;
if ( F_9 ( V_2 , & V_30 ) != 0 ) {
F_4 ( V_187 ) ;
return - V_57 ;
}
F_4 ( V_2 -> V_191 ) ;
V_2 -> V_191 = V_187 ;
V_2 -> V_192 = V_148 -> V_188 . V_82 ;
if ( V_2 -> V_191 ) {
}
F_14 ( V_2 , & V_30 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_29 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( ( V_2 -> V_192 == 0 ) || ( V_2 -> V_191 == NULL ) ) {
V_148 -> V_188 . V_82 = 0 ;
goto V_62;
}
if ( V_148 -> V_188 . V_82 < V_2 -> V_192 ) {
V_29 = - V_84 ;
goto V_62;
}
V_148 -> V_188 . V_82 = V_2 -> V_192 ;
memcpy ( V_53 , V_2 -> V_191 , V_2 -> V_192 ) ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_53 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_147 * V_148 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_193 * V_194 = (struct V_193 * ) V_53 ;
unsigned long V_30 ;
int V_168 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
switch ( V_194 -> V_195 ) {
case V_196 :
break;
case V_197 :
V_168 = F_54 ( V_2 , V_194 -> V_198 . V_58 ,
V_194 -> V_199 ) ;
break;
default:
V_168 = - V_65 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_168 ;
}
static int F_55 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_56 ( V_200 ) )
return - V_201 ;
if ( V_50 -> V_195 == ( V_202 + 0x1 ) ) {
F_8 ( V_203 L_10 , V_25 -> V_32 ) ;
F_57 ( & V_2 -> V_204 ) ;
} else {
F_8 ( V_203 L_11 , V_25 -> V_32 ) ;
F_58 ( & V_2 -> V_204 ) ;
}
return 0 ;
}
static int F_59 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_113 = * ( ( int * ) V_53 ) ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_2 -> V_205 = V_113 ;
F_60 ( V_2 ) ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_113 = ( int * ) V_53 ;
* V_113 = V_2 -> V_205 ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_113 = * ( ( int * ) V_53 ) ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
switch ( V_113 ) {
case 0 :
if ( ! V_2 -> V_206 ) {
V_29 = - V_88 ;
break;
}
V_2 -> V_207 = 0 ;
break;
case 1 :
if ( ! V_2 -> V_208 ) {
V_29 = - V_88 ;
break;
}
V_2 -> V_207 = 1 ;
break;
default:
V_29 = - V_88 ;
}
if ( ! V_29 ) {
F_60 ( V_2 ) ;
V_29 = - V_54 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_63 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_113 = ( int * ) V_53 ;
* V_113 = V_2 -> V_207 ;
return 0 ;
}
static int F_64 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_113 ;
if ( ! V_2 -> V_209 )
return - V_65 ;
V_113 = * ( ( int * ) V_53 ) ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
if ( V_113 )
V_2 -> V_210 = 1 ;
else
V_2 -> V_210 = 0 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_113 = ( int * ) V_53 ;
if ( ! V_2 -> V_209 )
return - V_65 ;
* V_113 = V_2 -> V_210 ;
return 0 ;
}
static int F_66 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_71 * V_188 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
int V_211 = V_188 -> V_30 ;
T_3 V_82 ;
int V_29 ;
unsigned long V_30 ;
if ( ! F_56 ( V_200 ) )
return - V_201 ;
if ( V_211 < 0xfc00 || V_211 > 0xffff )
return - V_88 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_57 ;
V_29 = V_27 -> V_106 -> V_212 ( V_27 , V_45 , V_211 , V_213 , & V_82 ,
V_53 ) ;
if ( V_29 )
goto V_62;
V_188 -> V_82 = F_67 ( T_3 , F_68 ( V_82 ) ,
V_213 ) ;
V_62:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_69 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_148 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_29 = 0 ;
if ( ! V_2 -> V_214 )
return 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return V_29 ;
V_29 = F_70 ( V_2 ) ;
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
