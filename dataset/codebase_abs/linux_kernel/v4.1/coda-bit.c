static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) != 0 ;
}
static inline unsigned long F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_6 + F_5 ( 1000 ) ;
while ( F_3 ( V_2 ) ) {
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
}
return 0 ;
}
static void F_7 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( V_2 -> V_11 -> V_12 == V_13 ||
V_2 -> V_11 -> V_12 == V_14 ) {
F_8 ( V_2 , V_9 -> V_15 ,
V_16 ) ;
F_8 ( V_2 , V_9 -> V_17 ,
F_9 ( V_9 -> V_18 ) ) ;
F_8 ( V_2 , V_9 -> V_19 ,
V_20 ) ;
F_8 ( V_2 , V_9 -> V_21 . V_22 , V_23 ) ;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
F_8 ( V_2 , 1 , V_24 ) ;
F_8 ( V_2 , 0 , V_25 ) ;
}
F_8 ( V_2 , V_26 , V_4 ) ;
F_8 ( V_2 , V_9 -> V_27 , V_28 ) ;
F_8 ( V_2 , V_9 -> V_29 . V_30 , V_31 ) ;
F_8 ( V_2 , V_9 -> V_29 . V_32 , V_33 ) ;
F_10 ( V_9 , V_10 ) ;
F_8 ( V_2 , V_10 , V_34 ) ;
}
static int F_11 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_35 ;
F_7 ( V_9 , V_10 ) ;
V_35 = F_4 ( V_2 ) ;
F_12 ( V_9 ) ;
return V_35 ;
}
int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_5 ;
unsigned int V_27 ;
int V_35 ;
if ( ! V_2 -> V_36 )
return - V_37 ;
V_27 = F_2 ( V_2 , V_28 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 ) {
V_5 = V_6 + F_5 ( 100 ) ;
F_8 ( V_2 , 0x11 , V_38 ) ;
while ( F_2 ( V_2 , V_39 ) != 0x77 ) {
if ( F_6 ( V_6 , V_5 ) )
return - V_40 ;
F_14 () ;
}
}
V_35 = F_15 ( V_2 -> V_36 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_2 -> V_11 -> V_12 == V_13 )
F_8 ( V_2 , 0x00 , V_38 ) ;
F_8 ( V_2 , V_26 , V_4 ) ;
F_8 ( V_2 , V_41 , V_42 ) ;
V_35 = F_4 ( V_2 ) ;
F_8 ( V_2 , V_27 , V_28 ) ;
return V_35 ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = & V_9 -> V_45 . V_44 ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_46 ;
V_46 = F_2 ( V_2 , F_17 ( V_9 -> V_18 ) ) ;
V_44 -> V_47 = ( V_44 -> V_48 & ~ V_44 -> V_49 ) |
( V_46 - V_9 -> V_50 . V_22 ) ;
if ( V_44 -> V_47 > V_44 -> V_48 )
V_44 -> V_47 -= V_44 -> V_49 + 1 ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = & V_9 -> V_45 . V_44 ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_46 , V_51 ;
V_46 = V_9 -> V_50 . V_22 + ( V_44 -> V_47 & V_44 -> V_49 ) ;
F_8 ( V_2 , V_46 , F_17 ( V_9 -> V_18 ) ) ;
V_51 = V_9 -> V_50 . V_22 + ( V_44 -> V_48 & V_44 -> V_49 ) ;
F_8 ( V_2 , V_51 , F_19 ( V_9 -> V_18 ) ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = & V_9 -> V_45 . V_44 ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_51 ;
V_51 = V_9 -> V_50 . V_22 + ( V_44 -> V_48 & V_44 -> V_49 ) ;
F_8 ( V_2 , V_51 , F_19 ( V_9 -> V_18 ) ) ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_52 * V_53 )
{
T_1 V_54 = F_22 ( V_53 , 0 ) ;
T_1 V_55 ;
V_55 = F_23 ( & V_9 -> V_45 , F_24 ( V_53 , 0 ) ,
V_54 ) ;
if ( V_55 < V_54 )
return - V_56 ;
V_53 -> V_57 . V_58 = V_9 -> V_59 ++ ;
return 0 ;
}
static bool F_25 ( struct V_8 * V_9 ,
struct V_52 * V_53 )
{
int V_35 ;
if ( F_26 ( V_9 ) +
F_22 ( V_53 , 0 ) + 512 >= V_9 -> V_50 . V_60 )
return false ;
if ( F_24 ( V_53 , 0 ) == NULL ) {
F_27 ( & V_9 -> V_2 -> V_61 , L_1 ) ;
return true ;
}
V_35 = F_21 ( V_9 , V_53 ) ;
if ( V_35 < 0 ) {
F_27 ( & V_9 -> V_2 -> V_61 , L_2 ) ;
return false ;
}
if ( V_9 == F_28 ( V_9 -> V_2 -> V_62 ) )
F_20 ( V_9 ) ;
V_9 -> V_63 = false ;
return true ;
}
void F_29 ( struct V_8 * V_9 , bool V_64 )
{
struct V_52 * V_53 ;
struct V_65 * V_66 ;
T_1 V_67 ;
while ( F_30 ( V_9 -> V_68 . V_69 ) > 0 ) {
if ( V_9 -> V_70 -> V_71 == V_72 &&
( F_26 ( V_9 ) >= 512 ) && ! V_9 -> V_63 )
break;
V_53 = F_31 ( V_9 -> V_68 . V_69 ) ;
if ( V_9 -> V_70 -> V_71 == V_72 &&
! F_32 ( V_9 , V_53 ) ) {
F_27 ( & V_9 -> V_2 -> V_61 ,
L_3 ,
V_9 -> V_59 ) ;
V_53 = F_33 ( V_9 -> V_68 . V_69 ) ;
F_34 ( V_53 , V_64 ?
V_73 :
V_74 ) ;
continue;
}
V_67 = V_9 -> V_45 . V_44 . V_48 &
V_9 -> V_45 . V_44 . V_49 ;
if ( F_25 ( V_9 , V_53 ) ) {
V_53 = F_33 ( V_9 -> V_68 . V_69 ) ;
V_66 = F_35 ( sizeof( * V_66 ) , V_75 ) ;
if ( V_66 ) {
V_66 -> V_58 = V_53 -> V_57 . V_58 ;
V_66 -> V_76 = V_53 -> V_57 . V_76 ;
V_66 -> V_77 = V_53 -> V_57 . V_77 ;
V_66 -> V_67 = V_67 ;
V_66 -> V_78 = V_9 -> V_45 . V_44 . V_48 &
V_9 -> V_45 . V_44 . V_49 ;
F_36 ( & V_66 -> V_79 ,
& V_9 -> V_80 ) ;
F_37 ( V_9 , V_53 , V_66 ) ;
}
F_34 ( V_53 , V_81 ) ;
} else {
break;
}
}
}
void F_38 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
V_9 -> V_15 |= V_82 ;
if ( ( V_2 -> V_11 -> V_12 == V_13 ) &&
F_3 ( V_2 ) &&
( V_9 -> V_27 == F_2 ( V_2 , V_28 ) ) ) {
F_8 ( V_2 , V_9 -> V_15 ,
V_16 ) ;
}
}
static void F_39 ( struct V_8 * V_9 , int V_83 , T_1 V_84 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_85 = V_9 -> V_86 . V_87 ;
if ( V_2 -> V_11 -> V_12 == V_88 )
V_85 [ V_83 ] = V_84 ;
else
V_85 [ V_83 ^ 1 ] = V_84 ;
}
static inline int F_40 ( struct V_8 * V_9 ,
struct V_89 * V_90 , T_2 V_60 ,
const char * V_91 )
{
return F_41 ( V_9 -> V_2 , V_90 , V_60 , V_91 , V_9 -> V_92 ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ )
F_43 ( V_9 -> V_2 , & V_9 -> V_95 [ V_93 ] ) ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_96 * V_97 , T_1 V_98 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_99 , V_100 ;
T_3 V_22 ;
int V_101 ;
int V_35 ;
int V_93 ;
if ( V_9 -> V_70 && ( V_9 -> V_70 -> V_71 == V_102 ||
V_9 -> V_70 -> V_103 == V_102 ) ) {
V_99 = F_45 ( V_97 -> V_99 , 16 ) ;
V_100 = F_45 ( V_97 -> V_100 , 16 ) ;
} else {
V_99 = F_45 ( V_97 -> V_99 , 8 ) ;
V_100 = V_97 -> V_100 ;
}
V_101 = V_99 * V_100 ;
for ( V_93 = 0 ; V_93 < V_9 -> V_104 ; V_93 ++ ) {
T_2 V_60 ;
char * V_91 ;
V_60 = V_101 + V_101 / 2 ;
if ( V_9 -> V_70 -> V_71 == V_102 &&
V_2 -> V_11 -> V_12 != V_88 )
V_60 += V_101 / 4 ;
V_91 = F_46 ( V_75 , L_4 , V_93 ) ;
V_35 = F_40 ( V_9 , & V_9 -> V_95 [ V_93 ] ,
V_60 , V_91 ) ;
F_47 ( V_91 ) ;
if ( V_35 < 0 ) {
F_42 ( V_9 ) ;
return V_35 ;
}
}
for ( V_93 = 0 ; V_93 < V_9 -> V_104 ; V_93 ++ ) {
V_22 = V_9 -> V_95 [ V_93 ] . V_22 ;
F_39 ( V_9 , V_93 * 3 + 0 , V_22 ) ;
F_39 ( V_9 , V_93 * 3 + 1 , V_22 + V_101 ) ;
F_39 ( V_9 , V_93 * 3 + 2 , V_22 + V_101 + V_101 / 4 ) ;
if ( V_9 -> V_70 -> V_71 == V_102 &&
V_2 -> V_11 -> V_12 != V_88 )
F_39 ( V_9 , 96 + V_93 ,
V_9 -> V_95 [ V_93 ] . V_22 +
V_101 + V_101 / 4 + V_101 / 4 ) ;
}
if ( ( V_2 -> V_11 -> V_12 != V_88 ) &&
( V_9 -> V_70 -> V_71 == V_105 ) )
F_39 ( V_9 , 97 , V_9 -> V_95 [ V_93 ] . V_22 +
V_101 + V_101 / 4 + V_101 / 4 ) ;
return 0 ;
}
static void F_48 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
F_43 ( V_2 , & V_9 -> V_106 ) ;
F_43 ( V_2 , & V_9 -> V_107 ) ;
if ( V_2 -> V_11 -> V_12 != V_88 )
F_43 ( V_2 , & V_9 -> V_21 ) ;
F_43 ( V_2 , & V_9 -> V_86 ) ;
}
static int F_49 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_2 V_60 ;
int V_35 ;
if ( ! V_9 -> V_86 . V_87 ) {
V_35 = F_40 ( V_9 , & V_9 -> V_86 ,
V_108 , L_5 ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( V_2 -> V_11 -> V_12 == V_88 )
return 0 ;
if ( ! V_9 -> V_106 . V_87 && V_97 -> V_98 == V_102 ) {
V_60 = ( F_50 ( V_97 -> V_99 , 16 ) *
F_50 ( V_97 -> V_100 , 16 ) ) * 3200 / 8 + 512 ;
V_35 = F_40 ( V_9 , & V_9 -> V_106 , V_60 ,
L_6 ) ;
if ( V_35 < 0 )
goto V_109;
}
if ( ! V_9 -> V_107 . V_87 && V_2 -> V_11 -> V_12 == V_14 ) {
V_35 = F_40 ( V_9 , & V_9 -> V_107 ,
V_110 , L_7 ) ;
if ( V_35 < 0 )
goto V_109;
}
if ( ! V_9 -> V_21 . V_87 ) {
V_60 = V_2 -> V_11 -> V_111 ;
if ( V_2 -> V_11 -> V_12 == V_13 &&
V_97 -> V_98 == V_102 )
V_60 += V_112 ;
V_35 = F_40 ( V_9 , & V_9 -> V_21 , V_60 ,
L_8 ) ;
if ( V_35 < 0 )
goto V_109;
}
return 0 ;
V_109:
F_48 ( V_9 ) ;
return V_35 ;
}
static int F_51 ( struct V_8 * V_9 , struct V_52 * V_90 ,
int V_113 , T_4 * V_114 , int * V_60 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_2 V_115 ;
int V_35 ;
int V_93 ;
if ( V_2 -> V_11 -> V_12 == V_13 )
memset ( F_24 ( V_90 , 0 ) , 0 , 64 ) ;
F_8 ( V_2 , F_52 ( V_90 , 0 ) ,
V_116 ) ;
V_115 = F_53 ( V_90 , 0 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 )
V_115 /= 1024 ;
F_8 ( V_2 , V_115 , V_117 ) ;
F_8 ( V_2 , V_113 , V_118 ) ;
V_35 = F_11 ( V_9 , V_119 ) ;
if ( V_35 < 0 ) {
F_27 ( & V_2 -> V_61 , L_9 ) ;
return V_35 ;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
for ( V_93 = 63 ; V_93 > 0 ; V_93 -- )
if ( ( ( char * ) F_24 ( V_90 , 0 ) ) [ V_93 ] != 0 )
break;
* V_60 = V_93 + 1 ;
} else {
* V_60 = F_2 ( V_2 , F_19 ( V_9 -> V_18 ) ) -
F_2 ( V_2 , V_116 ) ;
}
memcpy ( V_114 , F_24 ( V_90 , 0 ) , * V_60 ) ;
return 0 ;
}
static T_5 F_54 ( struct V_120 * V_121 , T_2 V_60 )
{
T_5 V_35 ;
V_60 = F_45 ( V_60 , 1024 ) ;
if ( V_60 > V_121 -> V_122 )
return 0 ;
V_121 -> V_122 -= V_60 ;
V_35 = V_121 -> V_123 ;
V_121 -> V_123 += V_60 ;
return V_35 ;
}
static void F_55 ( struct V_8 * V_9 )
{
struct V_120 * V_124 = & V_9 -> V_124 ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_125 , V_126 ;
int V_127 ;
int V_128 ;
int V_129 ;
int V_130 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_123 = V_2 -> V_121 . V_22 ;
V_124 -> V_122 = V_2 -> V_121 . V_60 ;
if ( ! V_2 -> V_121 . V_87 )
return;
switch ( V_2 -> V_11 -> V_12 ) {
case V_14 :
V_128 = V_131 | V_132 ;
V_129 = V_133 | V_134 ;
V_130 = V_135 | V_136 ;
break;
case V_13 :
V_128 = V_137 | V_138 ;
V_129 = V_139 | V_134 ;
V_130 = V_140 | V_136 ;
break;
default:
return;
}
if ( V_9 -> V_141 == V_142 ) {
struct V_96 * V_143 ;
V_143 = F_56 ( V_9 , V_144 ) ;
V_127 = F_50 ( V_143 -> V_99 , 16 ) ;
V_126 = V_127 * 128 ;
V_125 = V_127 * 64 ;
if ( V_2 -> V_11 -> V_12 == V_14 ) {
V_124 -> V_145 = F_45 ( V_127 * 16 *
36 + 2048 , 1024 ) ;
V_124 -> V_146 = F_54 ( V_124 ,
V_124 -> V_145 ) ;
if ( ! V_124 -> V_146 ) {
F_57 ( L_10 ) ;
goto V_47;
}
V_124 -> V_147 |= V_148 |
V_149 ;
}
V_124 -> V_150 = F_54 ( V_124 , V_125 ) ;
V_124 -> V_151 = F_54 ( V_124 , V_125 ) ;
if ( ! V_124 -> V_151 )
goto V_47;
V_124 -> V_147 |= V_128 ;
V_124 -> V_152 = F_54 ( V_124 , V_126 ) ;
if ( ! V_124 -> V_152 )
goto V_47;
V_124 -> V_147 |= V_129 ;
V_124 -> V_153 = F_54 ( V_124 , V_126 ) ;
if ( ! V_124 -> V_153 )
goto V_47;
V_124 -> V_147 |= V_130 ;
} else if ( V_9 -> V_141 == V_154 ) {
struct V_96 * V_155 ;
V_155 = F_56 ( V_9 , V_156 ) ;
V_127 = F_50 ( V_155 -> V_99 , 16 ) ;
V_126 = V_127 * 128 ;
V_124 -> V_150 = F_54 ( V_124 , V_126 ) ;
V_124 -> V_151 = F_54 ( V_124 , V_126 ) ;
if ( ! V_124 -> V_151 )
goto V_47;
V_124 -> V_147 |= V_128 ;
V_124 -> V_152 = F_54 ( V_124 , V_126 ) ;
if ( ! V_124 -> V_152 )
goto V_47;
V_124 -> V_147 |= V_129 ;
V_124 -> V_153 = F_54 ( V_124 , V_126 ) ;
if ( ! V_124 -> V_153 )
goto V_47;
V_124 -> V_147 |= V_130 ;
}
V_47:
if ( ! ( V_124 -> V_147 & V_135 ) )
F_58 ( 1 , V_157 , & V_9 -> V_2 -> V_61 ,
L_11 ) ;
if ( V_2 -> V_11 -> V_12 == V_14 ) {
if ( V_9 -> V_141 == V_154 ) {
V_124 -> V_147 &= ~ ( V_135 |
V_136 ) ;
} else {
V_124 -> V_147 &= ~ ( V_135 |
V_131 |
V_136 |
V_132 ) ;
}
}
}
static bool F_59 ( T_1 V_158 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < F_60 ( V_159 ) ; V_93 ++ )
if ( V_158 == V_159 [ V_93 ] )
return true ;
return false ;
}
int F_61 ( struct V_1 * V_2 )
{
T_6 V_12 , V_160 , V_161 , V_162 ;
T_1 V_163 ;
int V_35 ;
V_35 = F_62 ( V_2 -> V_164 ) ;
if ( V_35 )
goto V_165;
V_35 = F_62 ( V_2 -> V_166 ) ;
if ( V_35 )
goto V_167;
F_8 ( V_2 , 0 , V_168 ) ;
F_8 ( V_2 , V_26 , V_4 ) ;
F_8 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , 0 , V_31 ) ;
F_8 ( V_2 , V_169 , V_34 ) ;
if ( F_4 ( V_2 ) ) {
F_27 ( & V_2 -> V_61 , L_12 ) ;
V_35 = - V_170 ;
goto V_171;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
V_163 = F_2 ( V_2 , V_172 ) ;
F_63 ( & V_2 -> V_61 , L_13 ,
V_163 ) ;
}
V_163 = F_2 ( V_2 , V_168 ) ;
V_12 = F_64 ( V_163 ) ;
V_160 = F_65 ( V_163 ) ;
V_161 = F_66 ( V_163 ) ;
V_162 = F_67 ( V_163 ) ;
F_68 ( V_2 -> V_164 ) ;
F_68 ( V_2 -> V_166 ) ;
if ( V_12 != V_2 -> V_11 -> V_12 ) {
F_27 ( & V_2 -> V_61 ,
L_14 ,
F_69 ( V_2 -> V_11 -> V_12 ) ,
F_69 ( V_12 ) , V_160 , V_161 , V_162 ) ;
return - V_173 ;
}
F_63 ( & V_2 -> V_61 , L_15 ,
F_69 ( V_12 ) ) ;
if ( F_59 ( V_163 ) ) {
F_63 ( & V_2 -> V_61 , L_16 ,
V_160 , V_161 , V_162 ) ;
} else {
F_70 ( & V_2 -> V_61 ,
L_17 ,
V_160 , V_161 , V_162 ) ;
}
return 0 ;
V_171:
F_68 ( V_2 -> V_166 ) ;
V_167:
F_68 ( V_2 -> V_164 ) ;
V_165:
return V_35 ;
}
static int F_71 ( struct V_8 * V_9 ,
struct V_174 * V_175 )
{
struct V_96 * V_143 ;
int V_35 ;
if ( V_175 -> type != V_144 )
return 0 ;
if ( V_175 -> V_176 ) {
V_143 = F_56 ( V_9 , V_144 ) ;
V_35 = F_49 ( V_9 , V_143 ) ;
if ( V_35 < 0 )
return V_35 ;
} else {
F_48 ( V_9 ) ;
}
return 0 ;
}
static int F_72 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_177 * V_61 = & V_2 -> V_61 ;
struct V_96 * V_143 , * V_155 ;
T_1 V_178 , V_179 ;
struct V_52 * V_90 ;
int gamma , V_35 , V_84 ;
T_1 V_103 ;
int V_180 ;
T_1 V_181 ;
V_143 = F_56 ( V_9 , V_144 ) ;
V_155 = F_56 ( V_9 , V_156 ) ;
V_103 = V_155 -> V_98 ;
V_90 = F_73 ( V_9 -> V_68 . V_69 ) ;
V_178 = F_52 ( V_90 , 0 ) ;
V_179 = V_155 -> V_182 ;
if ( ! F_1 ( V_2 ) ) {
F_27 ( V_61 , L_18 ) ;
return - V_183 ;
}
if ( V_103 == V_72 ) {
if ( ! V_9 -> V_29 . V_184 [ 0 ] )
V_9 -> V_29 . V_184 [ 0 ] = F_35 ( 64 , V_75 ) ;
if ( ! V_9 -> V_29 . V_184 [ 1 ] )
V_9 -> V_29 . V_184 [ 1 ] = F_35 ( 64 , V_75 ) ;
F_74 ( V_9 , V_9 -> V_29 . V_185 ) ;
}
F_75 ( & V_2 -> V_186 ) ;
F_8 ( V_2 , V_9 -> V_86 . V_22 , V_187 ) ;
F_8 ( V_2 , V_178 , F_17 ( V_9 -> V_18 ) ) ;
F_8 ( V_2 , V_178 , F_19 ( V_9 -> V_18 ) ) ;
switch ( V_2 -> V_11 -> V_12 ) {
case V_88 :
F_8 ( V_2 , V_188 |
V_189 , V_190 ) ;
break;
case V_13 :
F_8 ( V_2 , 0 , V_25 ) ;
case V_14 :
F_8 ( V_2 , V_191 |
V_192 , V_190 ) ;
break;
}
V_9 -> V_19 &= ~ V_193 ;
if ( V_143 -> V_98 == V_194 )
V_9 -> V_19 |= V_193 ;
F_8 ( V_2 , V_9 -> V_19 , V_20 ) ;
if ( V_2 -> V_11 -> V_12 == V_88 ) {
F_8 ( V_2 , V_2 -> V_121 . V_22 ,
V_195 ) ;
}
V_84 = 0 ;
switch ( V_2 -> V_11 -> V_12 ) {
case V_88 :
V_84 = ( V_143 -> V_99 & V_196 )
<< V_197 ;
V_84 |= ( V_143 -> V_100 & V_198 )
<< V_199 ;
break;
case V_14 :
if ( V_103 == V_102 ) {
V_84 = ( F_45 ( V_143 -> V_99 , 16 ) &
V_200 ) << V_201 ;
V_84 |= ( F_45 ( V_143 -> V_100 , 16 ) &
V_202 ) << V_199 ;
break;
}
case V_13 :
V_84 = ( V_143 -> V_99 & V_200 )
<< V_201 ;
V_84 |= ( V_143 -> V_100 & V_202 )
<< V_199 ;
}
F_8 ( V_2 , V_84 , V_203 ) ;
if ( V_103 == V_72 )
V_9 -> V_29 . V_204 = 0 ;
F_8 ( V_2 , V_9 -> V_29 . V_204 ,
V_205 ) ;
V_9 -> V_29 . V_30 = V_9 -> V_70 -> V_206 ;
switch ( V_103 ) {
case V_105 :
if ( V_2 -> V_11 -> V_12 == V_13 )
F_8 ( V_2 , V_207 ,
V_208 ) ;
else
F_8 ( V_2 , V_209 ,
V_208 ) ;
F_8 ( V_2 , 0 , V_210 ) ;
break;
case V_102 :
if ( V_2 -> V_11 -> V_12 == V_13 )
F_8 ( V_2 , V_211 ,
V_208 ) ;
else
F_8 ( V_2 , V_212 ,
V_208 ) ;
if ( V_9 -> V_29 . V_213 ) {
V_84 = ( ( V_9 -> V_29 . V_214 &
V_215 ) <<
V_216 ) |
( ( V_9 -> V_29 . V_217 &
V_218 ) <<
V_219 ) ;
} else {
V_84 = 1 << V_220 ;
}
F_8 ( V_2 , V_84 , V_221 ) ;
break;
case V_72 :
F_8 ( V_2 , 0 , V_222 ) ;
F_8 ( V_2 , V_9 -> V_29 . V_223 ,
V_224 ) ;
F_8 ( V_2 , 0 , V_225 ) ;
F_8 ( V_2 , 0 , V_226 ) ;
F_8 ( V_2 , 0 , V_227 ) ;
F_76 ( V_9 ) ;
break;
default:
F_27 ( V_61 ,
L_19 , V_103 ) ;
V_35 = - V_173 ;
goto V_47;
}
if ( V_103 != V_72 ) {
switch ( V_9 -> V_29 . V_228 ) {
case V_229 :
V_84 = 0 ;
break;
case V_230 :
V_84 = ( V_9 -> V_29 . V_231 &
V_232 )
<< V_233 ;
V_84 |= ( 1 & V_234 )
<< V_235 ;
V_84 |= 1 & V_236 ;
break;
case V_237 :
V_84 = ( V_9 -> V_29 . V_238 &
V_232 )
<< V_233 ;
V_84 |= ( 0 & V_234 )
<< V_235 ;
V_84 |= 1 & V_236 ;
break;
}
F_8 ( V_2 , V_84 , V_239 ) ;
V_84 = V_9 -> V_29 . V_240 & V_241 ;
F_8 ( V_2 , V_84 , V_242 ) ;
}
if ( V_9 -> V_29 . V_243 ) {
V_84 = ( V_9 -> V_29 . V_243 & V_244 )
<< V_245 ;
V_84 |= 1 & V_246 ;
if ( V_2 -> V_11 -> V_12 == V_13 )
V_84 |= F_77 ( 31 ) ;
} else {
V_84 = 0 ;
}
F_8 ( V_2 , V_84 , V_247 ) ;
F_8 ( V_2 , 0 , V_248 ) ;
F_8 ( V_2 , V_9 -> V_29 . V_249 ,
V_250 ) ;
F_8 ( V_2 , V_178 , V_251 ) ;
F_8 ( V_2 , V_179 / 1024 , V_252 ) ;
V_84 = 0 ;
if ( V_2 -> V_11 -> V_12 == V_13 )
gamma = V_253 ;
else
gamma = V_254 ;
if ( gamma > 0 ) {
F_8 ( V_2 , ( gamma & V_255 ) << V_256 ,
V_257 ) ;
}
if ( V_9 -> V_29 . V_258 || V_9 -> V_29 . V_259 ) {
F_8 ( V_2 ,
V_9 -> V_29 . V_258 << V_260 |
V_9 -> V_29 . V_259 << V_261 ,
V_262 ) ;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
if ( V_9 -> V_29 . V_259 )
V_84 |= 1 << V_263 ;
if ( V_254 > 0 )
V_84 |= 1 << V_264 ;
} else {
if ( V_254 > 0 ) {
if ( V_2 -> V_11 -> V_12 == V_88 )
V_84 |= 1 << V_265 ;
else
V_84 |= 1 << V_266 ;
}
if ( V_9 -> V_29 . V_258 )
V_84 |= 1 << V_267 ;
if ( V_9 -> V_29 . V_259 )
V_84 |= 1 << V_268 ;
}
F_8 ( V_2 , V_84 , V_269 ) ;
F_8 ( V_2 , 0 , V_270 ) ;
F_55 ( V_9 ) ;
if ( V_103 == V_102 ) {
switch ( V_2 -> V_11 -> V_12 ) {
case V_88 :
V_84 = V_271 << 7 ;
F_8 ( V_2 , V_84 , V_272 ) ;
break;
case V_14 :
F_8 ( V_2 , V_9 -> V_124 . V_146 ,
V_273 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_145 ,
V_274 ) ;
break;
case V_13 :
F_8 ( V_2 , 0 , V_275 ) ;
F_8 ( V_2 , 0 , V_276 ) ;
}
}
V_35 = F_11 ( V_9 , V_277 ) ;
if ( V_35 < 0 ) {
F_27 ( V_61 , L_20 ) ;
goto V_47;
}
if ( F_2 ( V_2 , V_278 ) == 0 ) {
F_27 ( V_61 , L_21 ) ;
V_35 = - V_183 ;
goto V_47;
}
if ( V_103 != V_72 ) {
if ( V_2 -> V_11 -> V_12 == V_13 )
V_9 -> V_104 = 4 ;
else
V_9 -> V_104 = 2 ;
V_35 = F_44 ( V_9 , V_143 , V_103 ) ;
if ( V_35 < 0 ) {
F_27 ( V_61 , L_22 ) ;
goto V_47;
}
V_180 = 2 ;
V_181 = V_143 -> V_279 ;
} else {
V_9 -> V_104 = 0 ;
V_180 = 0 ;
V_181 = 0 ;
}
F_8 ( V_2 , V_180 , V_280 ) ;
F_8 ( V_2 , V_181 , V_281 ) ;
if ( V_2 -> V_11 -> V_12 == V_14 ) {
F_8 ( V_2 , V_143 -> V_279 ,
V_282 ) ;
}
if ( V_2 -> V_11 -> V_12 != V_88 ) {
F_8 ( V_2 , V_9 -> V_124 . V_152 ,
V_283 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_153 ,
V_284 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_150 ,
V_285 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_151 ,
V_286 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_287 ,
V_288 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 ) {
F_8 ( V_2 , V_9 -> V_124 . V_289 ,
V_290 ) ;
F_8 ( V_2 , V_9 -> V_95 [ 2 ] . V_22 ,
V_291 ) ;
F_8 ( V_2 , V_9 -> V_95 [ 3 ] . V_22 ,
V_292 ) ;
}
}
V_35 = F_11 ( V_9 , V_293 ) ;
if ( V_35 < 0 ) {
F_27 ( V_61 , L_23 ) ;
goto V_47;
}
V_90 = F_73 ( V_9 -> V_68 . V_69 ) ;
switch ( V_103 ) {
case V_102 :
V_35 = F_51 ( V_9 , V_90 , V_294 ,
& V_9 -> V_295 [ 0 ] [ 0 ] ,
& V_9 -> V_296 [ 0 ] ) ;
if ( V_35 < 0 )
goto V_47;
V_35 = F_51 ( V_9 , V_90 , V_297 ,
& V_9 -> V_295 [ 1 ] [ 0 ] ,
& V_9 -> V_296 [ 1 ] ) ;
if ( V_35 < 0 )
goto V_47;
V_9 -> V_296 [ 2 ] = F_78 (
( V_9 -> V_296 [ 0 ] +
V_9 -> V_296 [ 1 ] ) ,
V_9 -> V_295 [ 2 ] ) ;
break;
case V_105 :
V_35 = F_51 ( V_9 , V_90 , V_298 ,
& V_9 -> V_295 [ 0 ] [ 0 ] ,
& V_9 -> V_296 [ 0 ] ) ;
if ( V_35 < 0 )
goto V_47;
V_35 = F_51 ( V_9 , V_90 , V_299 ,
& V_9 -> V_295 [ 1 ] [ 0 ] ,
& V_9 -> V_296 [ 1 ] ) ;
if ( V_35 < 0 )
goto V_47;
V_35 = F_51 ( V_9 , V_90 , V_300 ,
& V_9 -> V_295 [ 2 ] [ 0 ] ,
& V_9 -> V_296 [ 2 ] ) ;
if ( V_35 < 0 )
goto V_47;
break;
default:
break;
}
V_47:
F_79 ( & V_2 -> V_186 ) ;
return V_35 ;
}
static int F_80 ( struct V_8 * V_9 )
{
struct V_96 * V_143 , * V_155 ;
struct V_52 * V_53 , * V_301 ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_302 ;
int V_303 = 0 ;
T_1 V_304 , V_305 ;
T_1 V_306 = 0 ;
T_1 V_103 ;
T_1 V_307 ;
V_53 = F_31 ( V_9 -> V_68 . V_69 ) ;
V_301 = F_73 ( V_9 -> V_68 . V_69 ) ;
V_143 = F_56 ( V_9 , V_144 ) ;
V_155 = F_56 ( V_9 , V_156 ) ;
V_103 = V_155 -> V_98 ;
V_53 -> V_57 . V_58 = V_9 -> V_308 ;
V_301 -> V_57 . V_58 = V_9 -> V_308 ;
V_9 -> V_308 ++ ;
if ( V_53 -> V_57 . V_58 % V_9 -> V_29 . V_240 ) {
V_53 -> V_57 . V_309 |= V_310 ;
V_53 -> V_57 . V_309 &= ~ V_311 ;
} else {
V_53 -> V_57 . V_309 |= V_311 ;
V_53 -> V_57 . V_309 &= ~ V_310 ;
}
if ( V_2 -> V_11 -> V_12 == V_13 )
F_81 ( V_9 ) ;
if ( V_53 -> V_57 . V_58 == 0 ) {
V_304 =
F_52 ( V_301 , 0 ) +
V_9 -> V_296 [ 0 ] +
V_9 -> V_296 [ 1 ] +
V_9 -> V_296 [ 2 ] ;
V_305 = V_155 -> V_182 -
V_9 -> V_296 [ 0 ] -
V_9 -> V_296 [ 1 ] -
V_9 -> V_296 [ 2 ] ;
memcpy ( F_24 ( V_301 , 0 ) ,
& V_9 -> V_295 [ 0 ] [ 0 ] , V_9 -> V_296 [ 0 ] ) ;
memcpy ( F_24 ( V_301 , 0 ) + V_9 -> V_296 [ 0 ] ,
& V_9 -> V_295 [ 1 ] [ 0 ] , V_9 -> V_296 [ 1 ] ) ;
memcpy ( F_24 ( V_301 , 0 ) + V_9 -> V_296 [ 0 ] +
V_9 -> V_296 [ 1 ] , & V_9 -> V_295 [ 2 ] [ 0 ] ,
V_9 -> V_296 [ 2 ] ) ;
} else {
V_304 =
F_52 ( V_301 , 0 ) ;
V_305 = V_155 -> V_182 ;
}
if ( V_53 -> V_57 . V_309 & V_311 ) {
V_302 = 1 ;
switch ( V_103 ) {
case V_102 :
V_303 = V_9 -> V_29 . V_312 ;
break;
case V_105 :
V_303 = V_9 -> V_29 . V_313 ;
break;
case V_72 :
V_303 = 30 ;
break;
default:
F_70 ( & V_9 -> V_2 -> V_61 ,
L_24 ) ;
break;
}
} else {
V_302 = 0 ;
switch ( V_103 ) {
case V_102 :
V_303 = V_9 -> V_29 . V_314 ;
break;
case V_105 :
V_303 = V_9 -> V_29 . V_315 ;
break;
default:
F_70 ( & V_9 -> V_2 -> V_61 ,
L_25 ) ;
break;
}
}
if ( V_9 -> V_29 . V_306 )
V_306 = V_316 | V_9 -> V_29 . V_306 ;
F_8 ( V_2 , V_306 , V_317 ) ;
F_8 ( V_2 , V_303 , V_318 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 ) {
F_8 ( V_2 , 4 , V_319 ) ;
F_8 ( V_2 , V_143 -> V_99 , V_320 ) ;
F_8 ( V_2 , 0 , V_321 ) ;
V_307 = V_322 ;
} else {
V_307 = V_323 ;
}
F_82 ( V_9 , V_143 , V_53 , V_307 ) ;
F_8 ( V_2 , V_302 << 1 & 0x2 ,
V_324 ) ;
F_8 ( V_2 , V_304 , V_325 ) ;
F_8 ( V_2 , V_305 / 1024 ,
V_326 ) ;
if ( ! V_9 -> V_327 ) {
V_9 -> V_15 |= V_82 ;
F_8 ( V_2 , V_9 -> V_15 ,
V_16 ) ;
}
if ( V_2 -> V_11 -> V_12 != V_88 )
F_8 ( V_2 , V_9 -> V_124 . V_147 ,
V_328 ) ;
F_83 ( V_9 , V_53 ) ;
F_7 ( V_9 , V_329 ) ;
return 0 ;
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_52 * V_53 , * V_301 ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_51 , V_330 ;
V_53 = F_33 ( V_9 -> V_68 . V_69 ) ;
V_301 = F_73 ( V_9 -> V_68 . V_69 ) ;
F_85 ( V_9 , V_301 ) ;
V_330 = F_2 ( V_2 , V_325 ) ;
V_51 = F_2 ( V_2 , F_19 ( V_9 -> V_18 ) ) ;
if ( V_301 -> V_57 . V_58 == 0 ) {
F_86 ( V_301 , 0 , V_51 - V_330 +
V_9 -> V_296 [ 0 ] +
V_9 -> V_296 [ 1 ] +
V_9 -> V_296 [ 2 ] ) ;
} else {
F_86 ( V_301 , 0 , V_51 - V_330 ) ;
}
F_58 ( 1 , V_157 , & V_9 -> V_2 -> V_61 , L_26 ,
V_51 - V_330 ) ;
F_2 ( V_2 , V_331 ) ;
F_2 ( V_2 , V_332 ) ;
if ( F_2 ( V_2 , V_333 ) == 0 ) {
V_301 -> V_57 . V_309 |= V_311 ;
V_301 -> V_57 . V_309 &= ~ V_310 ;
} else {
V_301 -> V_57 . V_309 |= V_310 ;
V_301 -> V_57 . V_309 &= ~ V_311 ;
}
V_301 -> V_57 . V_77 = V_53 -> V_57 . V_77 ;
V_301 -> V_57 . V_309 &= ~ V_334 ;
V_301 -> V_57 . V_309 |=
V_53 -> V_57 . V_309 & V_334 ;
V_301 -> V_57 . V_76 = V_53 -> V_57 . V_76 ;
F_34 ( V_53 , V_81 ) ;
V_301 = F_87 ( V_9 -> V_68 . V_69 ) ;
F_34 ( V_301 , V_81 ) ;
V_9 -> V_335 -- ;
if ( V_9 -> V_335 < 0 )
V_9 -> V_335 = V_9 -> V_29 . V_240 - 1 ;
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_27 ,
V_301 -> V_57 . V_58 ,
( V_301 -> V_57 . V_309 & V_311 ) ?
L_28 : L_29 ) ;
}
static void F_88 ( struct V_336 * V_337 )
{
struct V_8 * V_9 = F_89 ( V_337 , struct V_8 , V_338 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
F_75 ( & V_9 -> V_339 ) ;
F_75 ( & V_2 -> V_186 ) ;
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_30 , V_9 -> V_27 ,
V_340 ) ;
if ( F_11 ( V_9 , V_341 ) ) {
F_27 ( & V_2 -> V_61 ,
L_31 ) ;
}
F_90 ( & V_9 -> V_45 ,
V_9 -> V_50 . V_87 , V_9 -> V_50 . V_60 ) ;
F_42 ( V_9 ) ;
F_79 ( & V_2 -> V_186 ) ;
F_79 ( & V_9 -> V_339 ) ;
}
static void F_91 ( struct V_8 * V_9 )
{
F_75 ( & V_9 -> V_339 ) ;
F_42 ( V_9 ) ;
F_48 ( V_9 ) ;
F_92 ( V_9 ) ;
F_79 ( & V_9 -> V_339 ) ;
}
static int F_93 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
if ( V_9 -> V_50 . V_87 )
return 0 ;
V_9 -> V_50 . V_60 = F_94 ( V_97 -> V_182 * 2 ) ;
V_9 -> V_50 . V_87 = F_95 (
& V_9 -> V_2 -> V_342 -> V_2 , V_9 -> V_50 . V_60 ,
& V_9 -> V_50 . V_22 , V_75 ) ;
if ( ! V_9 -> V_50 . V_87 ) {
F_27 ( & V_9 -> V_2 -> V_61 ,
L_32 ) ;
return - V_343 ;
}
F_90 ( & V_9 -> V_45 ,
V_9 -> V_50 . V_87 , V_9 -> V_50 . V_60 ) ;
return 0 ;
}
static void F_92 ( struct V_8 * V_9 )
{
if ( V_9 -> V_50 . V_87 == NULL )
return;
F_96 ( & V_9 -> V_2 -> V_342 -> V_2 , V_9 -> V_50 . V_60 ,
V_9 -> V_50 . V_87 , V_9 -> V_50 . V_22 ) ;
V_9 -> V_50 . V_87 = NULL ;
F_90 ( & V_9 -> V_45 , NULL , 0 ) ;
}
static int F_97 ( struct V_8 * V_9 ,
struct V_174 * V_175 )
{
struct V_96 * V_143 ;
int V_35 ;
if ( V_175 -> type != V_144 )
return 0 ;
if ( V_175 -> V_176 ) {
V_143 = F_56 ( V_9 , V_144 ) ;
V_35 = F_49 ( V_9 , V_143 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_93 ( V_9 , V_143 ) ;
if ( V_35 < 0 ) {
F_48 ( V_9 ) ;
return V_35 ;
}
} else {
F_92 ( V_9 ) ;
F_48 ( V_9 ) ;
}
return 0 ;
}
static int F_98 ( struct V_8 * V_9 )
{
struct V_96 * V_143 , * V_155 ;
T_1 V_178 , V_179 ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_99 , V_100 ;
T_1 V_71 , V_103 ;
T_1 V_344 ;
int V_35 ;
V_143 = F_56 ( V_9 , V_144 ) ;
V_155 = F_56 ( V_9 , V_156 ) ;
V_178 = V_9 -> V_50 . V_22 ;
V_179 = V_9 -> V_50 . V_60 ;
V_71 = V_143 -> V_98 ;
V_103 = V_155 -> V_98 ;
F_8 ( V_2 , V_9 -> V_86 . V_22 , V_187 ) ;
F_18 ( V_9 ) ;
V_9 -> V_19 &= ~ V_193 ;
if ( V_103 == V_194 )
V_9 -> V_19 |= V_193 ;
F_8 ( V_2 , V_9 -> V_19 , V_20 ) ;
V_9 -> V_345 = - 1 ;
V_9 -> V_17 = 0 ;
F_8 ( V_2 , 0 , F_9 ( V_9 -> V_18 ) ) ;
F_8 ( V_2 , V_346 ,
V_16 ) ;
F_8 ( V_2 , V_178 , V_347 ) ;
F_8 ( V_2 , V_179 / 1024 , V_348 ) ;
V_344 = 0 ;
if ( ( V_2 -> V_11 -> V_12 == V_14 ) ||
( V_2 -> V_11 -> V_12 == V_13 ) )
V_344 |= V_349 ;
if ( V_9 -> V_70 -> V_71 == V_72 )
V_344 |= V_350 ;
F_8 ( V_2 , V_344 , V_351 ) ;
V_9 -> V_29 . V_30 = V_9 -> V_70 -> V_206 ;
if ( V_2 -> V_11 -> V_12 == V_13 &&
V_71 == V_105 )
V_9 -> V_29 . V_32 = V_352 ;
else
V_9 -> V_29 . V_32 = 0 ;
if ( V_71 == V_102 ) {
if ( V_2 -> V_11 -> V_12 == V_14 ) {
F_8 ( V_2 , V_9 -> V_107 . V_22 ,
V_353 ) ;
F_8 ( V_2 , ( V_110 / 1024 ) ,
V_354 ) ;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
F_8 ( V_2 , 0 , V_355 ) ;
F_8 ( V_2 , 512 , V_356 ) ;
}
}
if ( V_2 -> V_11 -> V_12 != V_13 )
F_8 ( V_2 , 0 , V_357 ) ;
if ( F_11 ( V_9 , V_277 ) ) {
F_27 ( & V_2 -> V_61 , L_20 ) ;
F_8 ( V_2 , 0 , V_16 ) ;
return - V_7 ;
}
F_16 ( V_9 ) ;
F_8 ( V_2 , 0 , V_16 ) ;
if ( F_2 ( V_2 , V_358 ) == 0 ) {
F_27 ( & V_2 -> V_61 ,
L_33 ,
F_2 ( V_2 , V_359 ) ) ;
return - V_360 ;
}
V_344 = F_2 ( V_2 , V_361 ) ;
if ( V_2 -> V_11 -> V_12 == V_88 ) {
V_99 = ( V_344 >> V_197 ) & V_196 ;
V_100 = V_344 & V_198 ;
} else {
V_99 = ( V_344 >> V_201 ) & V_200 ;
V_100 = V_344 & V_202 ;
}
if ( V_99 > V_155 -> V_279 || V_100 > V_155 -> V_100 ) {
F_27 ( & V_2 -> V_61 , L_34 ,
V_99 , V_100 , V_155 -> V_279 ,
V_155 -> V_100 ) ;
return - V_173 ;
}
V_99 = F_45 ( V_99 , 16 ) ;
V_100 = F_45 ( V_100 , 16 ) ;
F_58 ( 1 , V_157 , & V_2 -> V_61 , L_35 ,
V_340 , V_9 -> V_27 , V_99 , V_100 ) ;
V_9 -> V_104 = F_2 ( V_2 , V_362 ) ;
if ( V_9 -> V_104 > V_94 ) {
F_27 ( & V_2 -> V_61 ,
L_36 ,
V_94 , V_9 -> V_104 ) ;
return - V_173 ;
}
if ( V_71 == V_102 ) {
T_1 V_363 ;
T_1 V_364 ;
V_363 = F_2 ( V_2 , V_365 ) ;
V_364 = F_2 ( V_2 , V_366 ) ;
V_155 -> V_367 . V_368 = ( V_363 >> 10 ) & 0x3ff ;
V_155 -> V_367 . V_369 = ( V_364 >> 10 ) & 0x3ff ;
V_155 -> V_367 . V_99 = V_99 - V_155 -> V_367 . V_368 -
( V_363 & 0x3ff ) ;
V_155 -> V_367 . V_100 = V_100 - V_155 -> V_367 . V_369 -
( V_364 & 0x3ff ) ;
}
V_35 = F_44 ( V_9 , V_155 , V_71 ) ;
if ( V_35 < 0 ) {
F_27 ( & V_2 -> V_61 , L_22 ) ;
return V_35 ;
}
F_8 ( V_2 , V_9 -> V_104 , V_280 ) ;
F_8 ( V_2 , V_99 , V_281 ) ;
if ( V_2 -> V_11 -> V_12 != V_88 ) {
F_55 ( V_9 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_152 ,
V_283 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_153 ,
V_284 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_150 ,
V_285 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_151 ,
V_286 ) ;
F_8 ( V_2 , V_9 -> V_124 . V_287 ,
V_288 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 )
F_8 ( V_2 , V_9 -> V_124 . V_289 ,
V_290 ) ;
}
if ( V_2 -> V_11 -> V_12 == V_13 ) {
int V_370 , V_371 ;
F_8 ( V_2 , - 1 , V_372 ) ;
F_8 ( V_2 , 0x20262024 , V_373 ) ;
if ( V_103 == V_194 ) {
V_370 = 0 ;
V_371 = 16 ;
} else {
V_370 = 8 ;
V_371 = 8 ;
}
F_8 ( V_2 , 2 << V_374 |
32 << V_375 |
V_370 << V_376 |
V_371 << V_377 ,
V_378 ) ;
}
if ( V_71 == V_102 ) {
F_8 ( V_2 , V_9 -> V_106 . V_22 ,
V_379 ) ;
F_8 ( V_2 , V_9 -> V_106 . V_60 / 1024 ,
V_380 ) ;
}
if ( V_2 -> V_11 -> V_12 == V_14 ) {
int V_381 = 1920 / 16 ;
int V_382 = 1088 / 16 ;
int V_383 = V_381 * V_382 ;
F_8 ( V_2 , V_383 << 16 | V_381 << 8 | V_382 ,
V_384 ) ;
} else if ( V_2 -> V_11 -> V_12 == V_13 ) {
int V_381 = 1920 / 16 ;
int V_382 = 1088 / 16 ;
int V_383 = V_381 * V_382 ;
F_8 ( V_2 , V_383 << 16 | V_381 << 8 | V_382 ,
V_385 ) ;
}
if ( F_11 ( V_9 , V_293 ) ) {
F_27 ( & V_9 -> V_2 -> V_61 ,
L_23 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_99 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_35 ;
F_75 ( & V_2 -> V_186 ) ;
V_35 = F_98 ( V_9 ) ;
F_79 ( & V_2 -> V_186 ) ;
return V_35 ;
}
static int F_100 ( struct V_8 * V_9 )
{
struct V_52 * V_301 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_96 * V_155 ;
struct V_65 * V_66 ;
T_1 V_386 , V_387 ;
V_301 = F_73 ( V_9 -> V_68 . V_69 ) ;
V_155 = F_56 ( V_9 , V_156 ) ;
F_75 ( & V_9 -> V_388 ) ;
F_29 ( V_9 , true ) ;
F_79 ( & V_9 -> V_388 ) ;
if ( F_26 ( V_9 ) < 512 &&
( ! ( V_9 -> V_15 & V_82 ) ) ) {
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_37 ,
F_26 ( V_9 ) ) ;
F_101 ( V_9 -> V_2 -> V_62 , V_9 -> V_68 . V_69 ) ;
return - V_360 ;
}
if ( ! V_9 -> V_389 ) {
int V_35 = F_98 ( V_9 ) ;
if ( V_35 < 0 ) {
F_27 ( & V_2 -> V_61 , L_38 ) ;
F_101 ( V_9 -> V_2 -> V_62 , V_9 -> V_68 . V_69 ) ;
return - V_360 ;
} else {
V_9 -> V_389 = 1 ;
}
}
if ( V_2 -> V_11 -> V_12 == V_13 )
F_81 ( V_9 ) ;
if ( V_2 -> V_11 -> V_12 == V_13 ) {
F_8 ( V_2 , V_94 + V_301 -> V_57 . V_83 ,
V_390 ) ;
V_386 = V_391 ;
V_387 = V_392 ;
} else {
V_386 = V_393 ;
V_387 = V_394 ;
}
F_82 ( V_9 , V_155 , V_301 , V_386 ) ;
F_8 ( V_2 , V_155 -> V_279 , V_387 ) ;
F_8 ( V_2 , V_316 | V_9 -> V_29 . V_306 ,
V_395 ) ;
switch ( V_2 -> V_11 -> V_12 ) {
case V_88 :
case V_14 :
F_8 ( V_2 , V_396 , V_397 ) ;
break;
case V_13 :
F_8 ( V_2 , ( 1 << 10 ) , V_397 ) ;
break;
}
F_8 ( V_2 , 0 , V_398 ) ;
F_8 ( V_2 , 0 , V_399 ) ;
F_8 ( V_2 , 0 , V_400 ) ;
if ( V_2 -> V_11 -> V_12 != V_88 )
F_8 ( V_2 , V_9 -> V_124 . V_147 ,
V_328 ) ;
V_66 = F_102 ( & V_9 -> V_80 ,
struct V_65 , V_79 ) ;
if ( V_66 && V_9 -> V_70 -> V_71 == V_72 ) {
if ( V_66 -> V_78 == ( V_9 -> V_45 . V_44 . V_48 &
V_9 -> V_45 . V_44 . V_49 ) ) {
static unsigned char V_90 [ 512 ] ;
unsigned int V_401 ;
V_401 = ( ( 0 - V_66 -> V_78 ) & 0xff ) + 256 ;
memset ( V_90 , 0xff , sizeof( V_90 ) ) ;
F_23 ( & V_9 -> V_45 , V_90 , V_401 ) ;
}
}
F_18 ( V_9 ) ;
F_8 ( V_2 , 0 , V_402 ) ;
F_103 ( V_9 , V_66 ) ;
F_7 ( V_9 , V_329 ) ;
return 0 ;
}
static void F_104 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_96 * V_143 ;
struct V_96 * V_155 ;
struct V_52 * V_301 ;
struct V_65 * V_66 ;
unsigned long V_403 ;
int V_99 , V_100 ;
int V_404 ;
int V_345 ;
T_1 V_71 ;
int V_405 ;
T_1 V_406 ;
T_1 V_344 ;
F_16 ( V_9 ) ;
if ( V_9 -> V_15 & V_82 ) {
if ( F_26 ( V_9 ) >= V_9 -> V_50 . V_60 - 512 )
F_90 ( & V_9 -> V_45 ,
V_9 -> V_50 . V_87 , V_9 -> V_50 . V_60 ) ;
}
V_143 = F_56 ( V_9 , V_144 ) ;
V_71 = V_143 -> V_98 ;
V_344 = F_2 ( V_2 , V_402 ) ;
if ( V_344 != 1 )
F_57 ( L_39 , V_344 ) ;
V_405 = V_344 & 0x1 ;
if ( ! V_405 )
F_27 ( & V_2 -> V_61 , L_40 ) ;
if ( V_71 == V_102 ) {
if ( V_344 & ( 1 << 3 ) )
F_27 ( & V_2 -> V_61 ,
L_41 ,
V_9 -> V_107 . V_60 ) ;
if ( V_344 & ( 1 << 2 ) )
F_27 ( & V_2 -> V_61 ,
L_42 ,
V_9 -> V_106 . V_60 ) ;
}
V_344 = F_2 ( V_2 , V_407 ) ;
V_99 = ( V_344 >> 16 ) & 0xffff ;
V_100 = V_344 & 0xffff ;
V_155 = F_56 ( V_9 , V_156 ) ;
if ( V_71 == V_102 ) {
T_1 V_363 ;
T_1 V_364 ;
V_363 = F_2 ( V_2 , V_408 ) ;
V_364 = F_2 ( V_2 , V_409 ) ;
if ( V_363 == 0xffffffff && V_364 == 0xffffffff ) {
} else {
struct V_410 * V_367 = & V_155 -> V_367 ;
V_367 -> V_368 = V_363 >> 16 & 0xffff ;
V_367 -> V_369 = V_364 >> 16 & 0xffff ;
V_367 -> V_99 = V_99 - V_367 -> V_368 -
( V_363 & 0xffff ) ;
V_367 -> V_100 = V_100 - V_367 -> V_369 -
( V_364 & 0xffff ) ;
}
} else {
}
V_406 = F_2 ( V_2 , V_411 ) ;
if ( V_406 > 0 )
F_27 ( & V_2 -> V_61 ,
L_43 , V_406 ) ;
if ( V_2 -> V_11 -> V_12 == V_14 ) {
V_344 = F_2 ( V_2 , V_412 ) ;
if ( V_344 == 0 ) {
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_44 , V_344 ) ;
V_9 -> V_63 = true ;
return;
}
}
V_9 -> V_17 = F_2 ( V_2 ,
F_9 ( V_9 -> V_18 ) ) ;
if ( V_9 -> V_345 >= 0 &&
V_9 -> V_345 < V_9 -> V_104 ) {
V_9 -> V_17 &= ~ ( 1 << V_9 -> V_345 ) ;
F_8 ( V_2 , V_9 -> V_17 ,
F_9 ( V_9 -> V_18 ) ) ;
}
V_404 = F_2 ( V_2 , V_413 ) ;
V_345 = F_2 ( V_2 , V_414 ) ;
if ( V_404 == - 1 ) {
if ( V_345 >= 0 && V_345 < V_9 -> V_104 )
V_9 -> V_415 ++ ;
else if ( V_9 -> V_345 < 0 )
V_9 -> V_63 = true ;
} else if ( V_404 == - 2 ) {
} else if ( V_404 < 0 || V_404 >= V_9 -> V_104 ) {
F_27 ( & V_2 -> V_61 ,
L_45 , V_404 ) ;
} else {
V_344 = F_2 ( V_2 , V_416 ) - 1 ;
V_344 -= V_9 -> V_415 ;
F_75 ( & V_9 -> V_388 ) ;
if ( ! F_105 ( & V_9 -> V_80 ) ) {
V_66 = F_106 ( & V_9 -> V_80 ,
struct V_65 , V_79 ) ;
F_107 ( & V_66 -> V_79 ) ;
if ( V_344 != ( V_66 -> V_58 & 0xffff ) ) {
F_27 ( & V_2 -> V_61 ,
L_46 ,
V_344 , V_9 -> V_415 ,
V_66 -> V_58 ) ;
}
V_9 -> V_417 [ V_404 ] = * V_66 ;
F_47 ( V_66 ) ;
} else {
F_27 ( & V_2 -> V_61 , L_47 ) ;
memset ( & V_9 -> V_417 [ V_404 ] , 0 ,
sizeof( struct V_65 ) ) ;
V_9 -> V_417 [ V_404 ] . V_58 = V_344 ;
V_9 -> V_415 ++ ;
}
F_79 ( & V_9 -> V_388 ) ;
F_108 ( V_9 , & V_9 -> V_417 [ V_404 ] ) ;
V_344 = F_2 ( V_2 , V_418 ) & 0x7 ;
if ( V_344 == 0 )
V_9 -> V_419 [ V_404 ] = V_311 ;
else if ( V_344 == 1 )
V_9 -> V_419 [ V_404 ] = V_310 ;
else
V_9 -> V_419 [ V_404 ] = V_420 ;
V_9 -> V_421 [ V_404 ] = V_406 ;
}
if ( V_345 == - 1 ) {
V_9 -> V_63 = true ;
} else if ( V_345 == - 3 ) {
} else if ( V_345 < 0 || V_345 >= V_9 -> V_104 ) {
F_27 ( & V_2 -> V_61 ,
L_48 ,
V_345 ) ;
}
if ( V_9 -> V_345 >= 0 &&
V_9 -> V_345 < V_9 -> V_104 ) {
V_301 = F_87 ( V_9 -> V_68 . V_69 ) ;
V_301 -> V_57 . V_58 = V_9 -> V_308 ++ ;
V_301 -> V_57 . V_309 &= ~ ( V_311 |
V_310 |
V_420 ) ;
V_301 -> V_57 . V_309 |= V_9 -> V_419 [ V_9 -> V_345 ] ;
V_66 = & V_9 -> V_417 [ V_9 -> V_345 ] ;
V_301 -> V_57 . V_76 = V_66 -> V_76 ;
V_301 -> V_57 . V_77 = V_66 -> V_77 ;
F_109 ( V_9 , V_66 , V_301 ) ;
switch ( V_155 -> V_98 ) {
case V_422 :
case V_423 :
case V_194 :
default:
V_403 = V_99 * V_100 * 3 / 2 ;
break;
case V_424 :
V_403 = V_99 * V_100 * 2 ;
break;
}
F_86 ( V_301 , 0 , V_403 ) ;
F_34 ( V_301 , V_9 -> V_421 [ V_345 ] ?
V_73 : V_81 ) ;
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_49 ,
V_301 -> V_57 . V_58 ,
( V_301 -> V_57 . V_309 & V_311 ) ?
L_28 : L_29 ) ;
} else {
F_58 ( 1 , V_157 , & V_2 -> V_61 ,
L_50 ) ;
}
V_9 -> V_345 = V_345 ;
}
T_7 F_110 ( int V_425 , void * V_163 )
{
struct V_1 * V_2 = V_163 ;
struct V_8 * V_9 ;
F_2 ( V_2 , V_426 ) ;
F_8 ( V_2 , V_427 ,
V_428 ) ;
V_9 = F_28 ( V_2 -> V_62 ) ;
if ( V_9 == NULL ) {
F_27 ( & V_2 -> V_61 ,
L_51 ) ;
F_79 ( & V_2 -> V_186 ) ;
return V_429 ;
}
F_12 ( V_9 ) ;
if ( V_9 -> V_430 ) {
F_58 ( 1 , V_157 , & V_9 -> V_2 -> V_61 ,
L_52 ) ;
}
if ( F_3 ( V_9 -> V_2 ) ) {
F_58 ( 1 , V_157 , & V_9 -> V_2 -> V_61 ,
L_53 ) ;
return V_431 ;
}
F_111 ( & V_9 -> V_432 ) ;
return V_429 ;
}
