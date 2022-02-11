static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_7 = F_8 ( V_3 ) ;
T_1 V_8 = F_9 ( V_3 ) ;
F_3 ( V_2 , V_7 , V_9 ) ;
return F_1 ( V_2 , V_10 + V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned int V_3 )
{
T_1 V_7 = F_8 ( V_3 ) ;
T_1 V_8 = F_9 ( V_3 ) ;
F_3 ( V_2 , V_7 , V_9 ) ;
F_3 ( V_2 , V_5 , V_10 + V_8 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
unsigned long V_12 , V_13 ;
struct V_14 * V_14 = V_2 -> V_15 ;
unsigned int div ;
int V_16 ;
if ( F_12 ( V_14 ) == V_11 )
return 0 ;
switch ( V_11 ) {
case V_17 :
V_13 = F_12 ( F_13 ( V_14 ) ) ;
V_12 = F_12 ( V_2 -> V_18 ) ;
div = V_12 / V_11 ;
V_16 = F_14 ( V_14 , V_13 / div ) ;
if ( V_16 )
return V_16 ;
V_16 = F_15 ( V_14 , V_2 -> V_18 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_14 ( V_14 , V_11 ) ;
if ( V_16 )
return V_16 ;
break;
case V_19 :
V_16 = F_15 ( V_14 , V_2 -> V_20 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_14 ( V_14 , V_11 ) ;
if ( V_16 )
return V_16 ;
break;
default:
F_16 ( V_2 -> V_21 , L_1 , V_11 ) ;
return - V_22 ;
}
if ( F_12 ( V_14 ) != V_11 ) {
F_16 ( V_2 -> V_21 , L_2 ) ;
return - V_22 ;
}
return 0 ;
}
static unsigned long F_17 ( T_1 V_5 , unsigned int V_23 ,
unsigned int V_24 )
{
return ( V_5 >> V_23 ) & ( ( 1 << V_24 ) - 1 ) ;
}
static inline T_1 F_18 ( const struct V_25 * V_26 )
{
return ( V_26 -> V_27 & V_28 ) << V_29 |
( V_26 -> V_30 & V_31 ) << V_32 ;
}
static inline void F_19 ( struct V_25 * V_26 ,
T_1 V_5 )
{
V_26 -> V_27 = ( V_5 >> V_29 ) & V_28 ;
V_26 -> V_30 = ( V_5 >> V_32 ) & V_31 ;
}
static bool F_20 ( enum V_33 V_27 )
{
switch ( V_27 ) {
case V_34 :
case V_35 :
case V_36 :
return false ;
default:
return true ;
}
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
bool V_37 = false ;
T_1 V_5 ;
if ( ! ( V_26 -> V_27 == V_35 || V_26 -> V_27 == V_36 ) ) {
V_5 = F_1 ( V_2 , V_38 ) ;
if ( V_5 != V_39 ) {
F_16 ( V_2 -> V_21 , L_3 ) ;
return - V_40 ;
}
F_3 ( V_2 , V_41 , V_38 ) ;
V_5 = F_1 ( V_2 , V_38 ) ;
if ( V_5 != V_41 ) {
F_16 ( V_2 -> V_21 , L_4 ) ;
return - V_40 ;
}
V_37 = true ;
}
V_5 = F_18 ( V_26 ) ;
F_3 ( V_2 , V_5 , V_42 ) ;
V_5 = F_1 ( V_2 , V_43 ) ;
V_5 |= V_44 | V_45 ;
F_3 ( V_2 , V_5 , V_43 ) ;
if ( V_37 ) {
unsigned long V_46 = V_47 + F_22 ( 250 ) ;
while ( F_23 ( V_47 , V_46 ) ) {
V_5 = F_1 ( V_2 , V_38 ) ;
if ( V_5 == V_39 )
break;
F_24 ( 10 , 20 ) ;
}
if ( F_25 ( V_47 , V_46 ) )
V_5 = F_1 ( V_2 , V_38 ) ;
if ( V_5 != V_39 )
return - V_48 ;
}
return 0 ;
}
static T_2 F_26 ( int V_49 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_50 ) ;
F_3 ( V_2 , V_5 , V_50 ) ;
if ( V_5 & V_51 )
F_16 ( V_2 -> V_21 , L_5 ) ;
return V_52 ;
}
static void F_27 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
const struct V_55 * V_56 = V_2 -> V_56 ;
struct V_57 * V_21 = V_2 -> V_21 ;
struct V_25 V_58 ;
unsigned long V_59 ;
unsigned int V_60 ;
bool V_61 , V_62 ;
int V_16 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
switch ( V_26 -> V_27 ) {
case V_63 :
case V_64 :
V_58 . V_30 = F_12 ( V_2 -> V_65 ) / 1000 ;
if ( V_58 . V_30 != V_26 -> V_30 )
V_58 . V_27 = V_36 ;
else
V_58 . V_27 = V_35 ;
break;
case V_66 :
case V_67 :
if ( V_2 -> V_56 -> V_68 ) {
V_16 = F_11 ( V_2 , V_26 -> V_30 * 1000 ) ;
if ( V_16 < 0 )
V_58 . V_27 = V_36 ;
else
V_58 . V_27 = V_35 ;
V_58 . V_30 = F_12 ( V_2 -> V_15 ) / 1000 ;
} else {
V_58 . V_27 = V_35 ;
V_58 . V_30 = V_26 -> V_30 ;
}
break;
case V_34 :
break;
case V_69 :
V_16 = F_28 ( V_54 , V_26 -> V_30 ) ;
if ( V_16 < 0 ) {
F_16 ( V_21 , L_6 ,
V_26 -> V_30 , V_16 ) ;
V_58 . V_27 = V_36 ;
} else {
V_58 . V_27 = V_35 ;
}
V_58 . V_30 = V_26 -> V_30 ;
break;
case V_70 :
case V_71 :
if ( V_26 -> V_27 == V_71 )
V_61 = false ;
else
V_61 = true ;
V_59 = F_17 ( V_26 -> V_30 , 1 + V_56 -> V_72 . V_73 . V_3 ,
V_56 -> V_72 . V_73 . V_24 ) ;
F_29 (port, &mask, 32 ) {
V_16 = F_30 ( V_54 , V_60 ,
V_61 ) ;
if ( V_16 < 0 )
break;
}
if ( V_16 < 0 ) {
F_16 ( V_21 , L_7 , V_60 ,
V_61 ? L_8 : L_9 , V_16 ) ;
V_58 . V_27 = V_36 ;
} else {
V_58 . V_27 = V_35 ;
}
V_58 . V_30 = V_26 -> V_30 ;
break;
case V_74 :
case V_75 :
if ( V_26 -> V_27 == V_74 )
V_62 = false ;
else
V_62 = true ;
V_59 = F_17 ( V_26 -> V_30 , 1 + V_56 -> V_72 . V_76 . V_3 ,
V_56 -> V_72 . V_76 . V_24 ) ;
F_29 (port, &mask, soc->ports.usb3.count) {
V_16 = F_31 ( V_54 ,
V_60 ,
V_62 ) ;
if ( V_16 < 0 )
break;
}
if ( V_16 < 0 ) {
F_16 ( V_21 ,
L_10 ,
V_62 ? L_11 : L_12 , V_60 , V_16 ) ;
V_58 . V_27 = V_36 ;
} else {
V_58 . V_27 = V_35 ;
}
V_58 . V_30 = V_26 -> V_30 ;
break;
default:
F_32 ( V_21 , L_13 , V_26 -> V_27 ) ;
break;
}
if ( V_58 . V_27 ) {
const char * V_27 = ( V_58 . V_27 == V_35 ) ? L_14 : L_15 ;
V_16 = F_21 ( V_2 , & V_58 ) ;
if ( V_16 < 0 )
F_16 ( V_21 , L_16 , V_27 , V_16 ) ;
}
}
static T_2 F_33 ( int V_49 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_25 V_26 ;
T_1 V_5 ;
F_34 ( & V_2 -> V_77 ) ;
V_5 = F_1 ( V_2 , V_78 ) ;
F_19 ( & V_26 , V_5 ) ;
V_5 = F_1 ( V_2 , V_43 ) ;
V_5 &= ~ V_79 ;
F_3 ( V_2 , V_5 , V_43 ) ;
if ( ! F_20 ( V_26 . V_27 ) )
F_3 ( V_2 , V_39 , V_38 ) ;
F_27 ( V_2 , & V_26 ) ;
F_35 ( & V_2 -> V_77 ) ;
return V_80 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
T_1 V_5 ;
V_5 = F_5 ( V_2 , V_83 ) ;
V_5 |= V_84 ;
F_6 ( V_2 , V_5 , V_83 ) ;
F_24 ( 10 , 20 ) ;
V_5 = F_1 ( V_2 , V_85 ) ;
V_5 &= ~ ( V_86 << V_87 ) ;
V_5 |= V_82 -> V_23 & ( V_86 << V_87 ) ;
F_3 ( V_2 , V_5 , V_85 ) ;
F_24 ( 100 , 200 ) ;
V_5 = F_1 ( V_2 , V_88 ) ;
V_5 |= V_89 | V_90 | V_91 ;
F_3 ( V_2 , V_5 , V_88 ) ;
V_5 = F_5 ( V_2 , V_92 ) ;
V_5 |= V_93 ;
F_6 ( V_2 , V_5 , V_92 ) ;
F_6 ( V_2 , 0x80 , V_94 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_38 ( V_2 -> V_95 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_38 ( V_2 -> V_96 ) ;
if ( V_16 < 0 )
goto V_97;
V_16 = F_38 ( V_2 -> V_98 ) ;
if ( V_16 < 0 )
goto V_99;
V_16 = F_38 ( V_2 -> V_65 ) ;
if ( V_16 < 0 )
goto V_100;
V_16 = F_38 ( V_2 -> V_101 ) ;
if ( V_16 < 0 )
goto V_102;
V_16 = F_38 ( V_2 -> V_103 ) ;
if ( V_16 < 0 )
goto V_104;
if ( V_2 -> V_56 -> V_68 ) {
V_16 = F_11 ( V_2 , V_17 ) ;
if ( V_16 < 0 )
goto V_105;
}
return 0 ;
V_105:
F_39 ( V_2 -> V_103 ) ;
V_104:
F_39 ( V_2 -> V_101 ) ;
V_102:
F_39 ( V_2 -> V_65 ) ;
V_100:
F_39 ( V_2 -> V_98 ) ;
V_99:
F_39 ( V_2 -> V_96 ) ;
V_97:
F_39 ( V_2 -> V_95 ) ;
return V_16 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_95 ) ;
F_39 ( V_2 -> V_96 ) ;
F_39 ( V_2 -> V_98 ) ;
F_39 ( V_2 -> V_65 ) ;
F_39 ( V_2 -> V_101 ) ;
F_39 ( V_2 -> V_103 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned int V_106 ;
int V_16 ;
for ( V_106 = 0 ; V_106 < V_2 -> V_107 ; V_106 ++ ) {
V_16 = F_42 ( V_2 -> V_108 [ V_106 ] ) ;
if ( V_16 )
goto V_109;
V_16 = F_43 ( V_2 -> V_108 [ V_106 ] ) ;
if ( V_16 ) {
F_44 ( V_2 -> V_108 [ V_106 ] ) ;
goto V_109;
}
}
return 0 ;
V_109:
while ( V_106 -- ) {
F_45 ( V_2 -> V_108 [ V_106 ] ) ;
F_44 ( V_2 -> V_108 [ V_106 ] ) ;
}
return V_16 ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < V_2 -> V_107 ; V_106 ++ ) {
F_45 ( V_2 -> V_108 [ V_106 ] ) ;
F_44 ( V_2 -> V_108 [ V_106 ] ) ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned int V_110 , V_111 , V_112 ;
struct V_113 * V_114 ;
struct V_57 * V_21 = V_2 -> V_21 ;
const struct V_115 * V_116 ;
unsigned long V_46 ;
T_3 V_117 ;
struct V_118 time ;
T_4 V_119 ;
T_1 V_5 ;
int V_16 ;
V_16 = F_48 ( & V_116 , V_2 -> V_56 -> V_115 , V_2 -> V_21 ) ;
if ( V_16 < 0 ) {
F_16 ( V_2 -> V_21 , L_17 , V_16 ) ;
return V_16 ;
}
V_114 = (struct V_113 * ) V_116 -> V_30 ;
V_2 -> V_116 . V_120 = F_49 ( V_114 -> V_121 ) ;
V_2 -> V_116 . V_122 = F_50 ( V_2 -> V_21 , V_2 -> V_116 . V_120 ,
& V_2 -> V_116 . V_108 , V_123 ) ;
if ( ! V_2 -> V_116 . V_122 ) {
F_16 ( V_2 -> V_21 , L_18 ) ;
F_51 ( V_116 ) ;
return - V_124 ;
}
V_114 = (struct V_113 * ) V_2 -> V_116 . V_122 ;
memcpy ( V_2 -> V_116 . V_122 , V_116 -> V_30 , V_2 -> V_116 . V_120 ) ;
F_51 ( V_116 ) ;
if ( F_7 ( V_2 , V_125 ) != 0 ) {
F_52 ( V_21 , L_19 ,
F_7 ( V_2 , V_126 ) ) ;
return 0 ;
}
F_10 ( V_2 , V_2 -> V_116 . V_120 , V_127 ) ;
V_119 = V_2 -> V_116 . V_108 + sizeof( * V_114 ) ;
F_10 ( V_2 , V_119 >> 32 , V_128 ) ;
F_10 ( V_2 , V_119 , V_125 ) ;
F_10 ( V_2 , V_129 , V_130 ) ;
F_10 ( V_2 , V_131 , V_132 ) ;
V_110 = F_53 ( F_49 ( V_114 -> V_133 ) ,
V_134 ) ;
V_111 = F_53 ( F_49 ( V_114 -> V_135 ) ,
V_134 ) ;
V_112 = V_110 + V_111 ;
V_5 = ( ( V_110 & V_136 ) <<
V_137 ) |
( ( V_111 & V_138 ) <<
V_139 ) ;
F_10 ( V_2 , V_5 , V_140 ) ;
F_10 ( V_2 , V_141 ,
V_132 ) ;
F_10 ( V_2 , V_111 , V_142 ) ;
V_5 = ( ( V_110 & V_143 ) <<
V_144 ) |
( ( V_112 & V_143 ) <<
V_145 ) ;
F_10 ( V_2 , V_5 , V_146 ) ;
F_10 ( V_2 , 0 , V_147 ) ;
F_54 ( 50 ) ;
F_10 ( V_2 , F_49 ( V_114 -> V_133 ) ,
V_148 ) ;
V_46 = V_47 + F_22 ( 5 ) ;
F_10 ( V_2 , V_149 , V_126 ) ;
while ( F_23 ( V_47 , V_46 ) ) {
if ( F_7 ( V_2 , V_126 ) == V_150 )
break;
F_24 ( 100 , 200 ) ;
}
if ( F_7 ( V_2 , V_126 ) != V_150 ) {
F_16 ( V_21 , L_20 ,
F_7 ( V_2 , V_126 ) ) ;
return - V_151 ;
}
V_117 = F_49 ( V_114 -> V_152 ) ;
F_55 ( V_117 , 0 , & time ) ;
F_52 ( V_21 , L_21 ,
time . V_153 + 1900 , time . V_154 + 1 , time . V_155 ,
time . V_156 , time . V_157 , time . V_158 ) ;
return 0 ;
}
static int F_56 ( struct V_159 * V_160 )
{
struct V_25 V_26 ;
struct V_81 * V_161 , * V_82 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
unsigned int V_106 , V_164 , V_165 ;
struct V_166 * V_166 ;
int V_16 ;
F_57 ( sizeof( struct V_113 ) != 256 ) ;
V_2 = F_58 ( & V_160 -> V_21 , sizeof( * V_2 ) , V_123 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_56 = F_59 ( & V_160 -> V_21 ) ;
F_60 ( & V_2 -> V_77 ) ;
V_2 -> V_21 = & V_160 -> V_21 ;
V_82 = F_61 ( V_160 , V_167 , 0 ) ;
V_2 -> V_82 = F_62 ( & V_160 -> V_21 , V_82 ) ;
if ( F_63 ( V_2 -> V_82 ) )
return F_64 ( V_2 -> V_82 ) ;
V_161 = F_61 ( V_160 , V_167 , 1 ) ;
V_2 -> V_4 = F_62 ( & V_160 -> V_21 , V_161 ) ;
if ( F_63 ( V_2 -> V_4 ) )
return F_64 ( V_2 -> V_4 ) ;
V_161 = F_61 ( V_160 , V_167 , 2 ) ;
V_2 -> V_6 = F_62 ( & V_160 -> V_21 , V_161 ) ;
if ( F_63 ( V_2 -> V_6 ) )
return F_64 ( V_2 -> V_6 ) ;
V_2 -> V_168 = F_65 ( V_160 , 0 ) ;
if ( V_2 -> V_168 < 0 )
return V_2 -> V_168 ;
V_2 -> V_169 = F_65 ( V_160 , 1 ) ;
if ( V_2 -> V_169 < 0 )
return V_2 -> V_169 ;
V_2 -> V_54 = F_66 ( & V_160 -> V_21 ) ;
if ( F_63 ( V_2 -> V_54 ) )
return F_64 ( V_2 -> V_54 ) ;
V_2 -> V_170 = F_67 ( & V_160 -> V_21 , L_22 ) ;
if ( F_63 ( V_2 -> V_170 ) ) {
V_16 = F_64 ( V_2 -> V_170 ) ;
F_16 ( & V_160 -> V_21 , L_23 , V_16 ) ;
goto V_171;
}
V_2 -> V_172 = F_67 ( & V_160 -> V_21 , L_24 ) ;
if ( F_63 ( V_2 -> V_172 ) ) {
V_16 = F_64 ( V_2 -> V_172 ) ;
F_16 ( & V_160 -> V_21 , L_25 , V_16 ) ;
goto V_171;
}
V_2 -> V_96 = F_68 ( & V_160 -> V_21 , L_22 ) ;
if ( F_63 ( V_2 -> V_96 ) ) {
V_16 = F_64 ( V_2 -> V_96 ) ;
F_16 ( & V_160 -> V_21 , L_26 , V_16 ) ;
goto V_171;
}
V_2 -> V_65 = F_68 ( & V_160 -> V_21 , L_27 ) ;
if ( F_63 ( V_2 -> V_65 ) ) {
V_16 = F_64 ( V_2 -> V_65 ) ;
F_16 ( & V_160 -> V_21 , L_28 , V_16 ) ;
goto V_171;
}
V_2 -> V_98 = F_68 ( & V_160 -> V_21 , L_24 ) ;
if ( F_63 ( V_2 -> V_98 ) ) {
V_16 = F_64 ( V_2 -> V_98 ) ;
F_16 ( & V_160 -> V_21 , L_29 , V_16 ) ;
goto V_171;
}
V_2 -> V_15 = F_68 ( & V_160 -> V_21 , L_30 ) ;
if ( F_63 ( V_2 -> V_15 ) ) {
V_16 = F_64 ( V_2 -> V_15 ) ;
F_16 ( & V_160 -> V_21 , L_31 , V_16 ) ;
goto V_171;
}
V_2 -> V_103 = F_68 ( & V_160 -> V_21 , L_32 ) ;
if ( F_63 ( V_2 -> V_103 ) ) {
V_16 = F_64 ( V_2 -> V_103 ) ;
F_16 ( & V_160 -> V_21 , L_33 , V_16 ) ;
goto V_171;
}
V_2 -> V_101 = F_68 ( & V_160 -> V_21 , L_34 ) ;
if ( F_63 ( V_2 -> V_101 ) ) {
V_16 = F_64 ( V_2 -> V_101 ) ;
F_16 ( & V_160 -> V_21 , L_35 , V_16 ) ;
goto V_171;
}
V_2 -> V_18 = F_68 ( & V_160 -> V_21 , L_36 ) ;
if ( F_63 ( V_2 -> V_18 ) ) {
V_16 = F_64 ( V_2 -> V_18 ) ;
F_16 ( & V_160 -> V_21 , L_37 , V_16 ) ;
goto V_171;
}
V_2 -> V_20 = F_68 ( & V_160 -> V_21 , L_38 ) ;
if ( F_63 ( V_2 -> V_20 ) ) {
V_16 = F_64 ( V_2 -> V_20 ) ;
F_16 ( & V_160 -> V_21 , L_39 , V_16 ) ;
goto V_171;
}
V_2 -> V_95 = F_68 ( & V_160 -> V_21 , L_40 ) ;
if ( F_63 ( V_2 -> V_95 ) ) {
V_16 = F_64 ( V_2 -> V_95 ) ;
F_16 ( & V_160 -> V_21 , L_41 , V_16 ) ;
goto V_171;
}
V_2 -> V_173 = F_69 ( & V_160 -> V_21 , V_2 -> V_56 -> V_174 ,
sizeof( * V_2 -> V_173 ) , V_123 ) ;
if ( ! V_2 -> V_173 ) {
V_16 = - V_124 ;
goto V_171;
}
for ( V_106 = 0 ; V_106 < V_2 -> V_56 -> V_174 ; V_106 ++ )
V_2 -> V_173 [ V_106 ] . V_175 = V_2 -> V_56 -> V_176 [ V_106 ] ;
V_16 = F_70 ( & V_160 -> V_21 , V_2 -> V_56 -> V_174 ,
V_2 -> V_173 ) ;
if ( V_16 ) {
F_16 ( & V_160 -> V_21 , L_42 , V_16 ) ;
goto V_171;
}
for ( V_106 = 0 ; V_106 < V_2 -> V_56 -> V_177 ; V_106 ++ )
V_2 -> V_107 += V_2 -> V_56 -> V_178 [ V_106 ] . V_179 ;
V_2 -> V_108 = F_69 ( & V_160 -> V_21 , V_2 -> V_107 ,
sizeof( * V_2 -> V_108 ) , V_123 ) ;
if ( ! V_2 -> V_108 ) {
V_16 = - V_124 ;
goto V_171;
}
for ( V_106 = 0 , V_165 = 0 ; V_106 < V_2 -> V_56 -> V_177 ; V_106 ++ ) {
char V_180 [ 8 ] ;
for ( V_164 = 0 ; V_164 < V_2 -> V_56 -> V_178 [ V_106 ] . V_179 ; V_164 ++ ) {
snprintf ( V_180 , sizeof( V_180 ) , L_43 ,
V_2 -> V_56 -> V_178 [ V_106 ] . V_181 , V_164 ) ;
V_166 = F_71 ( & V_160 -> V_21 , V_180 ) ;
if ( F_63 ( V_166 ) ) {
F_16 ( & V_160 -> V_21 ,
L_44 , V_180 ,
F_64 ( V_166 ) ) ;
V_16 = F_64 ( V_166 ) ;
goto V_171;
}
V_2 -> V_108 [ V_165 ++ ] = V_166 ;
}
}
V_16 = F_37 ( V_2 ) ;
if ( V_16 ) {
F_16 ( & V_160 -> V_21 , L_45 , V_16 ) ;
goto V_171;
}
V_16 = F_72 ( V_2 -> V_56 -> V_174 , V_2 -> V_173 ) ;
if ( V_16 ) {
F_16 ( & V_160 -> V_21 , L_46 , V_16 ) ;
goto V_182;
}
V_16 = F_41 ( V_2 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_47 , V_16 ) ;
goto V_183;
}
F_36 ( V_2 , V_82 ) ;
V_16 = F_47 ( V_2 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_48 , V_16 ) ;
goto V_109;
}
V_2 -> V_184 = F_73 ( & V_185 , & V_160 -> V_21 ,
F_74 ( & V_160 -> V_21 ) ) ;
if ( ! V_2 -> V_184 ) {
V_16 = - V_124 ;
goto V_109;
}
F_75 ( V_160 , V_2 ) ;
V_2 -> V_184 -> V_82 = V_2 -> V_82 ;
V_2 -> V_184 -> V_186 = V_82 -> V_23 ;
V_2 -> V_184 -> V_187 = F_76 ( V_82 ) ;
V_16 = F_77 ( V_2 -> V_184 , V_2 -> V_168 , V_188 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_49 , V_16 ) ;
goto V_189;
}
F_78 ( V_2 -> V_184 -> V_190 . V_191 ) ;
V_163 = F_79 ( V_2 -> V_184 ) ;
V_163 -> V_192 = F_80 ( & V_185 ,
& V_160 -> V_21 ,
F_74 ( & V_160 -> V_21 ) ,
V_2 -> V_184 ) ;
if ( ! V_163 -> V_192 ) {
F_16 ( & V_160 -> V_21 , L_50 ) ;
V_16 = - V_124 ;
goto V_193;
}
V_16 = F_77 ( V_163 -> V_192 , V_2 -> V_168 , V_188 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_51 , V_16 ) ;
goto V_194;
}
F_34 ( & V_2 -> V_77 ) ;
V_26 . V_27 = V_195 ;
V_26 . V_30 = 0 ;
V_16 = F_21 ( V_2 , & V_26 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_52 , V_16 ) ;
F_35 ( & V_2 -> V_77 ) ;
goto V_196;
}
F_35 ( & V_2 -> V_77 ) ;
V_16 = F_81 ( & V_160 -> V_21 , V_2 -> V_169 ,
F_26 ,
F_33 , 0 ,
F_74 ( & V_160 -> V_21 ) , V_2 ) ;
if ( V_16 < 0 ) {
F_16 ( & V_160 -> V_21 , L_53 , V_16 ) ;
goto V_196;
}
return 0 ;
V_196:
F_82 ( V_163 -> V_192 ) ;
V_194:
F_83 ( V_163 -> V_192 ) ;
V_193:
F_82 ( V_2 -> V_184 ) ;
V_189:
F_83 ( V_2 -> V_184 ) ;
V_109:
F_46 ( V_2 ) ;
V_183:
F_84 ( V_2 -> V_56 -> V_174 , V_2 -> V_173 ) ;
V_182:
F_40 ( V_2 ) ;
V_171:
F_85 ( V_2 -> V_54 ) ;
return V_16 ;
}
static int F_86 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_87 ( V_160 ) ;
struct V_162 * V_163 = F_79 ( V_2 -> V_184 ) ;
F_82 ( V_163 -> V_192 ) ;
F_83 ( V_163 -> V_192 ) ;
F_82 ( V_2 -> V_184 ) ;
F_83 ( V_2 -> V_184 ) ;
F_88 ( & V_160 -> V_21 , V_2 -> V_116 . V_120 , V_2 -> V_116 . V_122 ,
V_2 -> V_116 . V_108 ) ;
F_46 ( V_2 ) ;
F_84 ( V_2 -> V_56 -> V_174 , V_2 -> V_173 ) ;
F_40 ( V_2 ) ;
F_85 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_89 ( struct V_57 * V_21 )
{
struct V_1 * V_2 = F_90 ( V_21 ) ;
struct V_162 * V_163 = F_79 ( V_2 -> V_184 ) ;
bool V_197 = F_91 ( V_21 ) ;
return F_92 ( V_163 , V_197 ) ;
}
static int F_93 ( struct V_57 * V_21 )
{
struct V_1 * V_2 = F_90 ( V_21 ) ;
struct V_162 * V_163 = F_79 ( V_2 -> V_184 ) ;
return F_94 ( V_163 , 0 ) ;
}
static void F_95 ( struct V_57 * V_21 , struct V_162 * V_163 )
{
V_163 -> V_198 |= V_199 ;
}
static int F_96 ( struct V_200 * V_184 )
{
return F_97 ( V_184 , F_95 ) ;
}
static int T_5 F_98 ( void )
{
F_99 ( & V_185 , & V_201 ) ;
return F_100 ( & V_202 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_202 ) ;
}
