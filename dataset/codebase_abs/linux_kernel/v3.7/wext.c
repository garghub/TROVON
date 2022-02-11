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
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( F_16 ( V_52 -> V_56 ) ||
F_17 ( V_52 -> V_56 ) ) {
V_2 -> V_57 = 0 ;
memset ( V_2 -> V_58 , 0 , V_59 ) ;
if ( V_52 -> V_56 [ 0 ] == 0 ) {
F_18 ( V_2 ) ;
V_29 = 0 ;
}
goto V_60;
}
if ( V_2 -> V_61 == V_62 ) {
F_8 ( V_31 L_2
L_3 ,
V_25 -> V_32 ) ;
V_29 = - V_63 ;
goto V_60;
}
if ( V_2 -> V_34 != V_64 ) {
F_8 ( V_31 L_4
L_5 , V_25 -> V_32 ) ;
V_29 = - V_63 ;
goto V_60;
}
if ( V_2 -> V_61 == V_65 &&
strlen ( V_2 -> V_66 ) == 0 ) {
F_8 ( V_31 L_6
L_7 , V_25 -> V_32 ) ;
V_29 = - V_63 ;
goto V_60;
}
V_2 -> V_57 = 1 ;
memcpy ( V_2 -> V_58 , & V_52 -> V_56 , V_59 ) ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_19 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_52 -> V_67 = V_68 ;
V_29 = F_20 ( V_2 , V_52 -> V_56 ) ;
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_69 * V_70 ,
char * V_71 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_70 -> V_30 & V_72 ) - 1 ;
int V_73 = V_2 -> V_74 ;
enum V_4 V_75 = V_2 -> V_75 ;
int V_76 = V_2 -> V_77 ;
int V_29 = - V_54 ;
unsigned long V_30 ;
if ( ! V_2 -> V_78 )
return - V_63 ;
if ( V_70 -> V_79 ) {
if ( V_70 -> V_80 > V_81 )
return - V_82 ;
if ( ( V_70 -> V_80 > V_18 ) && ! V_2 -> V_83 )
return - V_82 ;
}
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( ( V_2 -> V_84 ) && ( V_2 -> V_75 == V_14 ) )
( void ) F_22 ( V_2 , V_73 ) ;
if ( V_70 -> V_80 > 0 ) {
if ( ( V_3 < 0 ) || ( V_3 >= V_85 ) )
V_3 = V_2 -> V_74 ;
if ( V_75 != V_17 ) {
V_73 = V_3 ;
V_75 = V_17 ;
}
} else {
if ( ( V_3 < 0 ) || ( V_3 >= V_85 ) ) {
if ( ( V_3 != - 1 ) || ( V_70 -> V_30 == 0 ) ) {
V_29 = - V_86 ;
goto V_60;
}
} else {
if ( V_2 -> V_10 [ V_3 ] . V_7 == 0 ) {
V_29 = - V_86 ;
goto V_60;
}
V_73 = V_3 ;
}
}
if ( V_70 -> V_30 & V_87 )
V_75 = V_21 ;
if ( V_70 -> V_30 & V_88 )
V_76 = 0 ;
if ( V_70 -> V_30 & V_89 )
V_76 = 1 ;
if ( V_70 -> V_79 && V_70 -> V_80 > 0 ) {
V_29 = F_1 ( V_2 , V_3 , V_17 , V_71 ,
V_70 -> V_80 , NULL , 0 ) ;
}
V_2 -> V_74 = V_73 ;
if ( ( V_2 -> V_75 == V_75 ) &&
( V_2 -> V_77 == V_76 ) &&
F_23 ( V_25 ) ) {
V_29 = F_24 ( V_2 ) ;
goto V_60;
}
V_2 -> V_75 = V_75 ;
V_2 -> V_77 = V_76 ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_69 * V_70 ,
char * V_71 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_3 = ( V_70 -> V_30 & V_72 ) - 1 ;
unsigned long V_30 ;
if ( ! V_2 -> V_78 )
return - V_63 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( ( V_3 < 0 ) || ( V_3 >= V_85 ) )
V_3 = V_2 -> V_74 ;
V_70 -> V_30 = 0 ;
if ( ! V_2 -> V_75 )
V_70 -> V_30 |= V_87 ;
V_70 -> V_30 |= V_3 + 1 ;
if ( V_2 -> V_77 )
V_70 -> V_30 |= V_89 ;
else
V_70 -> V_30 |= V_88 ;
V_70 -> V_80 = V_2 -> V_10 [ V_3 ] . V_7 ;
memcpy ( V_71 , V_2 -> V_10 [ V_3 ] . V_6 , V_70 -> V_80 ) ;
F_14 ( V_2 , & V_30 ) ;
return 0 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_69 * V_70 ,
char * V_90 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
if ( V_70 -> V_80 > V_91 )
return - V_82 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
memset ( V_2 -> V_66 , 0 , sizeof( V_2 -> V_66 ) ) ;
if ( V_70 -> V_30 )
memcpy ( V_2 -> V_66 , V_90 , V_70 -> V_80 ) ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_27 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_69 * V_70 ,
char * V_90 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_92 ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_28 ( V_25 ) ) {
V_29 = F_29 ( V_2 , & V_92 , V_90 ) ;
if ( V_29 < 0 )
return V_29 ;
V_70 -> V_80 = V_29 ;
} else {
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
memcpy ( V_90 , V_2 -> V_66 , V_91 ) ;
V_70 -> V_80 = strlen ( V_2 -> V_66 ) ;
F_14 ( V_2 , & V_30 ) ;
}
V_70 -> V_30 = 1 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_93 * V_94 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_95 = - 1 ;
unsigned long V_30 ;
int V_29 = - V_54 ;
if ( V_2 -> V_34 == V_64 )
return - V_55 ;
if ( ( V_94 -> V_96 == 0 ) && ( V_94 -> V_97 <= 1000 ) ) {
V_95 = V_94 -> V_97 ;
} else {
int V_98 = 1 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < ( 6 - V_94 -> V_96 ) ; V_99 ++ )
V_98 *= 10 ;
V_95 = F_31 ( V_94 -> V_97 / V_98 ) ;
}
if ( ( V_95 < 1 ) || ( V_95 > V_100 ) ||
! ( V_2 -> V_101 & ( 1 << ( V_95 - 1 ) ) ) )
return - V_86 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_2 -> V_102 = V_95 ;
if ( V_2 -> V_34 == V_103 ) {
struct V_26 * V_27 = & V_2 -> V_27 ;
V_29 = V_27 -> V_104 -> V_105 ( V_27 , V_106 |
V_107 ,
V_95 , NULL ) ;
}
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_93 * V_94 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_108 ;
V_108 = F_33 ( V_2 ) ;
if ( V_108 < 0 )
return V_108 ;
V_94 -> V_97 = V_108 * 100000 ;
V_94 -> V_96 = 1 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_110 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
T_3 V_111 ;
int V_29 ;
unsigned long V_30 ;
if ( ! V_2 -> V_112 )
return - V_63 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_29 = F_35 ( V_27 , V_45 ,
V_113 , & V_111 ) ;
F_14 ( V_2 , & V_30 ) ;
if ( V_29 )
return V_29 ;
V_110 -> V_114 = V_111 ;
V_110 -> V_115 = 0 ;
return 0 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_110 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_111 = V_110 -> V_114 ;
unsigned long V_30 ;
if ( ! V_2 -> V_112 )
return - V_63 ;
if ( ( V_111 < 1 ) || ( V_111 > 3 ) )
return - V_86 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_2 -> V_116 = V_111 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_117 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_118 ;
int V_119 ;
unsigned long V_30 ;
if ( V_117 -> V_114 == - 1 )
V_119 = 110 ;
else {
if ( V_117 -> V_114 % 100000 )
return - V_86 ;
V_119 = V_117 -> V_114 / 100000 ;
}
V_118 = F_38 ( V_119 , ! V_117 -> V_115 ) ;
if ( V_118 == - 1 )
return - V_86 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_2 -> V_120 = V_118 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_117 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = 0 ;
int V_119 , V_121 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
F_40 ( V_2 -> V_120 , & V_119 , & V_121 ) ;
if ( F_28 ( V_25 ) ) {
int V_122 ;
int V_123 ;
V_123 = F_41 ( V_2 , & V_122 ) ;
if ( ! V_123 )
V_119 = V_122 ;
}
F_14 ( V_2 , & V_30 ) ;
V_117 -> V_114 = V_119 ;
V_117 -> V_115 = ! V_121 ;
V_117 -> V_124 = 0 ;
return V_29 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_125 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_29 = - V_54 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( V_125 -> V_124 ) {
V_2 -> V_126 = 0 ;
} else {
switch ( V_125 -> V_30 & V_127 ) {
case V_128 :
V_2 -> V_129 = 0 ;
V_2 -> V_126 = 1 ;
break;
case V_130 :
V_2 -> V_129 = 1 ;
V_2 -> V_126 = 1 ;
break;
case V_131 :
break;
default:
V_29 = - V_86 ;
goto V_60;
}
if ( V_125 -> V_30 & V_132 ) {
V_2 -> V_126 = 1 ;
V_2 -> V_133 = V_125 -> V_114 / 1000 ;
}
if ( V_125 -> V_30 & V_134 ) {
V_2 -> V_126 = 1 ;
V_2 -> V_135 = V_125 -> V_114 / 1000 ;
}
if ( ! V_2 -> V_126 ) {
V_29 = - V_86 ;
goto V_60;
}
}
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_109 * V_125 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
int V_29 = 0 ;
T_3 V_136 , V_137 , V_138 , V_139 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_29 = F_35 ( V_27 , V_45 ,
V_140 , & V_136 ) ;
if ( V_29 )
goto V_60;
V_29 = F_35 ( V_27 , V_45 ,
V_141 , & V_137 ) ;
if ( V_29 )
goto V_60;
V_29 = F_35 ( V_27 , V_45 ,
V_142 , & V_138 ) ;
if ( V_29 )
goto V_60;
V_29 = F_35 ( V_27 , V_45 ,
V_143 , & V_139 ) ;
if ( V_29 )
goto V_60;
V_125 -> V_124 = ! V_136 ;
if ( ( V_125 -> V_30 & V_144 ) == V_132 ) {
V_125 -> V_30 = V_132 ;
V_125 -> V_114 = V_138 * 1000 ;
} else {
V_125 -> V_30 = V_134 ;
V_125 -> V_114 = V_137 * 1000 ;
}
if ( V_139 )
V_125 -> V_30 |= V_130 ;
else
V_125 -> V_30 |= V_128 ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_69 * V_147 = & V_146 -> V_147 ;
struct V_148 * V_149 = (struct V_148 * ) V_53 ;
int V_150 , V_5 = V_149 -> V_5 , V_151 = 1 ;
unsigned long V_30 ;
int V_29 = - V_86 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_150 = V_147 -> V_30 & V_72 ;
if ( V_150 ) {
if ( ( V_150 < 1 ) || ( V_150 > 4 ) )
goto V_60;
V_150 -- ;
} else
V_150 = V_2 -> V_74 ;
if ( V_147 -> V_30 & V_87 )
V_5 = V_152 ;
if ( V_2 -> V_84 && ( V_5 != V_153 ) ) {
( void ) F_22 ( V_2 , V_2 -> V_74 ) ;
}
if ( V_149 -> V_154 & V_155 ) {
V_2 -> V_74 = V_150 ;
V_151 = ( ( V_5 == V_153 ) ||
( V_149 -> V_7 > 0 ) ) ? 1 : 0 ;
}
if ( V_151 ) {
switch ( V_5 ) {
case V_152 :
V_2 -> V_75 = V_21 ;
V_29 = F_1 ( V_2 , V_150 , V_21 ,
NULL , 0 , NULL , 0 ) ;
break;
case V_156 :
if ( V_149 -> V_7 <= 0 )
goto V_60;
V_2 -> V_75 = V_17 ;
V_29 = F_1 ( V_2 , V_150 , V_17 ,
V_149 -> V_6 , V_149 -> V_7 , NULL , 0 ) ;
break;
case V_153 :
{
T_1 * V_157 = NULL ;
if ( ! V_2 -> V_84 ||
( V_149 -> V_7 > sizeof( struct V_158 ) ) )
goto V_60;
V_2 -> V_75 = V_14 ;
if ( V_149 -> V_154 & V_159 )
V_157 = & V_149 -> V_160 [ 0 ] ;
V_29 = F_1 ( V_2 , V_150 , V_14 ,
V_149 -> V_6 , V_149 -> V_7 , V_157 ,
V_161 ) ;
V_29 = F_45 ( V_2 , V_150 ,
V_149 -> V_154 & V_155 ,
V_2 -> V_10 [ V_150 ] . V_6 ,
V_157 , V_161 , NULL , 0 ) ;
if ( V_29 )
F_8 ( V_162 L_8
L_9 , V_25 -> V_32 , V_29 ) ;
goto V_60;
}
default:
goto V_60;
}
}
V_29 = - V_54 ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_46 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_69 * V_147 = & V_146 -> V_147 ;
struct V_148 * V_149 = (struct V_148 * ) V_53 ;
int V_150 , V_163 ;
unsigned long V_30 ;
int V_29 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_29 = - V_86 ;
V_163 = V_147 -> V_80 - sizeof( * V_149 ) ;
if ( V_163 < 0 )
goto V_60;
V_150 = V_147 -> V_30 & V_72 ;
if ( V_150 ) {
if ( ( V_150 < 1 ) || ( V_150 > 4 ) )
goto V_60;
V_150 -- ;
} else
V_150 = V_2 -> V_74 ;
V_147 -> V_30 = V_150 + 1 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
switch ( V_2 -> V_75 ) {
case V_21 :
V_149 -> V_5 = V_152 ;
V_149 -> V_7 = 0 ;
V_147 -> V_30 |= V_87 ;
break;
case V_17 :
V_149 -> V_5 = V_156 ;
V_149 -> V_7 = F_47 ( V_2 -> V_10 [ V_150 ] . V_7 , V_163 ) ;
memcpy ( V_149 -> V_6 , V_2 -> V_10 [ V_150 ] . V_6 , V_149 -> V_7 ) ;
V_147 -> V_30 |= V_164 ;
break;
case V_14 :
V_149 -> V_5 = V_153 ;
V_149 -> V_7 = F_47 ( V_2 -> V_10 [ V_150 ] . V_7 , V_163 ) ;
memcpy ( V_149 -> V_6 , V_2 -> V_10 [ V_150 ] . V_6 , V_149 -> V_7 ) ;
V_147 -> V_30 |= V_164 ;
break;
}
V_29 = 0 ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_48 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_109 * V_165 = & V_146 -> V_165 ;
unsigned long V_30 ;
int V_166 = - V_54 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
switch ( V_165 -> V_30 & V_167 ) {
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
break;
case V_174 :
if ( V_165 -> V_114 == V_175 )
V_166 = - V_86 ;
break;
case V_176 :
V_2 -> V_177 = V_165 -> V_114 ;
break;
case V_178 :
if ( V_165 -> V_114 ) {
V_2 -> V_179 = 1 ;
V_166 = F_49 ( V_27 , 0 ) ;
} else {
V_2 -> V_179 = 0 ;
V_166 = F_50 ( V_27 , 0 ) ;
}
break;
case V_180 :
if ( V_165 -> V_114 & V_181 )
V_2 -> V_77 = 1 ;
else if ( V_165 -> V_114 & V_182 )
V_2 -> V_77 = 0 ;
else
V_166 = - V_86 ;
break;
case V_183 :
if ( V_2 -> V_84 ) {
V_2 -> V_184 = V_165 -> V_114 ? 1 : 0 ;
} else {
if ( V_165 -> V_114 )
V_166 = - V_63 ;
V_2 -> V_184 = 0 ;
}
break;
default:
V_166 = - V_63 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_166 ;
}
static int F_51 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_109 * V_165 = & V_146 -> V_165 ;
unsigned long V_30 ;
int V_166 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
switch ( V_165 -> V_30 & V_167 ) {
case V_176 :
V_165 -> V_114 = V_2 -> V_177 ;
break;
case V_178 :
V_165 -> V_114 = V_2 -> V_179 ;
break;
case V_180 :
if ( V_2 -> V_77 )
V_165 -> V_114 = V_181 ;
else
V_165 -> V_114 = V_182 ;
break;
case V_183 :
V_165 -> V_114 = V_2 -> V_184 ;
break;
default:
V_166 = - V_63 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_166 ;
}
static int F_52 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
T_1 * V_185 ;
unsigned long V_30 ;
if ( ( V_146 -> V_186 . V_80 > V_187 ) ||
( V_146 -> V_186 . V_80 && ( V_53 == NULL ) ) )
return - V_86 ;
if ( V_146 -> V_186 . V_80 ) {
V_185 = F_53 ( V_53 , V_146 -> V_186 . V_80 , V_188 ) ;
if ( V_185 == NULL )
return - V_22 ;
} else
V_185 = NULL ;
if ( F_9 ( V_2 , & V_30 ) != 0 ) {
F_4 ( V_185 ) ;
return - V_55 ;
}
F_4 ( V_2 -> V_189 ) ;
V_2 -> V_189 = V_185 ;
V_2 -> V_190 = V_146 -> V_186 . V_80 ;
if ( V_2 -> V_189 ) {
}
F_14 ( V_2 , & V_30 ) ;
return 0 ;
}
static int F_54 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_29 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( ( V_2 -> V_190 == 0 ) || ( V_2 -> V_189 == NULL ) ) {
V_146 -> V_186 . V_80 = 0 ;
goto V_60;
}
if ( V_146 -> V_186 . V_80 < V_2 -> V_190 ) {
V_29 = - V_82 ;
goto V_60;
}
V_146 -> V_186 . V_80 = V_2 -> V_190 ;
memcpy ( V_53 , V_2 -> V_189 , V_2 -> V_190 ) ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_55 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
union V_145 * V_146 , char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_191 * V_192 = (struct V_191 * ) V_53 ;
unsigned long V_30 ;
int V_166 = 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
switch ( V_192 -> V_193 ) {
case V_194 :
break;
case V_195 :
V_166 = F_56 ( V_2 , V_192 -> V_196 . V_56 ,
V_192 -> V_197 ) ;
break;
default:
V_166 = - V_63 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_166 ;
}
static int F_57 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
if ( ! F_58 ( V_198 ) )
return - V_199 ;
if ( V_50 -> V_193 == ( V_200 + 0x1 ) ) {
F_8 ( V_201 L_10 , V_25 -> V_32 ) ;
F_59 ( & V_2 -> V_202 ) ;
} else {
F_8 ( V_201 L_11 , V_25 -> V_32 ) ;
F_60 ( & V_2 -> V_202 ) ;
}
return 0 ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_111 = * ( ( int * ) V_53 ) ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_2 -> V_203 = V_111 ;
F_62 ( V_2 ) ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_63 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_111 = ( int * ) V_53 ;
* V_111 = V_2 -> V_203 ;
return 0 ;
}
static int F_64 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_111 = * ( ( int * ) V_53 ) ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
switch ( V_111 ) {
case 0 :
if ( ! V_2 -> V_204 ) {
V_29 = - V_86 ;
break;
}
V_2 -> V_205 = 0 ;
break;
case 1 :
if ( ! V_2 -> V_206 ) {
V_29 = - V_86 ;
break;
}
V_2 -> V_205 = 1 ;
break;
default:
V_29 = - V_86 ;
}
if ( ! V_29 ) {
F_62 ( V_2 ) ;
V_29 = - V_54 ;
}
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_111 = ( int * ) V_53 ;
* V_111 = V_2 -> V_205 ;
return 0 ;
}
static int F_66 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_111 ;
if ( ! V_2 -> V_207 )
return - V_63 ;
V_111 = * ( ( int * ) V_53 ) ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
if ( V_111 )
V_2 -> V_208 = 1 ;
else
V_2 -> V_208 = 0 ;
F_14 ( V_2 , & V_30 ) ;
return - V_54 ;
}
static int F_67 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int * V_111 = ( int * ) V_53 ;
if ( ! V_2 -> V_207 )
return - V_63 ;
* V_111 = V_2 -> V_208 ;
return 0 ;
}
static int F_68 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_69 * V_186 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
struct V_26 * V_27 = & V_2 -> V_27 ;
int V_209 = V_186 -> V_30 ;
T_3 V_80 ;
int V_29 ;
unsigned long V_30 ;
if ( ! F_58 ( V_198 ) )
return - V_199 ;
if ( V_209 < 0xfc00 || V_209 > 0xffff )
return - V_86 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return - V_55 ;
V_29 = V_27 -> V_104 -> V_210 ( V_27 , V_45 , V_209 , V_211 , & V_80 ,
V_53 ) ;
if ( V_29 )
goto V_60;
V_186 -> V_80 = F_69 ( T_3 , F_70 ( V_80 ) ,
V_211 ) ;
V_60:
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
static int F_71 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
void * V_146 ,
char * V_53 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned long V_30 ;
int V_29 = 0 ;
if ( ! V_2 -> V_212 )
return 0 ;
if ( F_9 ( V_2 , & V_30 ) != 0 )
return V_29 ;
V_29 = F_72 ( V_2 ) ;
F_14 ( V_2 , & V_30 ) ;
return V_29 ;
}
