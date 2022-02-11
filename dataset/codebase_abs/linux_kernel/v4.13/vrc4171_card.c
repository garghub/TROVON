static inline T_1 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( enum V_2 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_5 ) ;
V_4 &= ~ V_6 ;
switch ( V_3 ) {
case V_7 :
V_4 |= V_8 ;
break;
case V_9 :
V_4 |= V_10 ;
break;
case V_11 :
V_4 |= V_12 ;
break;
case V_13 :
V_4 |= V_14 ;
break;
default:
break;
}
F_4 ( V_4 , V_5 ) ;
}
static inline T_2 F_5 ( int V_15 , T_2 V_16 )
{
if ( V_15 == V_17 )
V_16 += V_18 ;
F_6 ( V_16 , V_19 ) ;
return F_7 ( V_20 ) ;
}
static inline T_1 F_8 ( int V_15 , T_2 V_16 )
{
T_1 V_21 ;
if ( V_15 == V_17 )
V_16 += V_18 ;
F_6 ( V_16 ++ , V_19 ) ;
V_21 = F_7 ( V_20 ) ;
F_6 ( V_16 , V_19 ) ;
V_21 |= ( ( T_1 ) F_7 ( V_20 ) ) << 8 ;
return V_21 ;
}
static inline T_2 F_9 ( int V_15 , T_2 V_16 , T_2 V_21 )
{
if ( V_15 == V_17 )
V_16 += V_18 ;
F_6 ( V_16 , V_19 ) ;
F_6 ( V_21 , V_20 ) ;
return V_21 ;
}
static inline T_1 F_10 ( int V_15 , T_2 V_16 , T_1 V_21 )
{
if ( V_15 == V_17 )
V_16 += V_18 ;
F_6 ( V_16 ++ , V_19 ) ;
F_6 ( V_21 , V_20 ) ;
F_6 ( V_16 , V_19 ) ;
F_6 ( ( T_2 ) ( V_21 >> 8 ) , V_20 ) ;
return V_21 ;
}
static inline int F_11 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
if ( V_23 & ( 1 << V_22 ) ) {
V_23 &= ~ ( 1 << V_22 ) ;
return V_22 ;
}
}
return - 1 ;
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
unsigned int V_15 ;
V_25 -> V_28 |= V_29 | V_30 ;
V_25 -> V_31 = 0 ;
V_25 -> V_32 = 0x1000 ;
V_25 -> V_33 = V_34 ;
V_15 = V_25 -> V_25 ;
V_27 = & V_35 [ V_15 ] ;
V_27 -> V_36 = F_11 () ;
V_27 -> V_37 = F_11 () ;
F_13 ( & V_27 -> V_38 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 , T_3 * V_39 )
{
unsigned int V_15 ;
T_2 V_40 , V_41 ;
T_3 V_42 = 0 ;
if ( V_25 == NULL || V_25 -> V_25 >= V_43 || V_39 == NULL )
return - V_44 ;
V_15 = V_25 -> V_25 ;
V_40 = F_5 ( V_15 , V_45 ) ;
if ( F_5 ( V_15 , V_46 ) & V_47 ) {
if ( V_40 & V_48 )
V_42 |= V_49 ;
} else {
if ( ! ( V_40 & V_50 ) )
V_42 |= V_51 ;
else if ( ( V_40 & ( V_50 | V_52 ) ) == V_50 )
V_42 |= V_53 ;
}
if ( ( V_40 & V_54 ) == V_54 )
V_42 |= V_55 ;
if ( V_40 & V_56 )
V_42 |= V_57 ;
if ( V_40 & V_58 )
V_42 |= V_59 ;
if ( V_40 & V_60 )
V_42 |= V_61 ;
V_41 = F_5 ( V_15 , V_62 ) ;
switch ( V_41 ) {
case V_63 :
V_42 |= V_64 | V_65 ;
break;
case V_66 :
V_42 |= V_65 ;
break;
case V_67 :
V_42 |= V_64 ;
break;
default:
break;
}
* V_39 = V_42 ;
return 0 ;
}
static inline T_2 F_15 ( T_4 V_68 )
{
switch ( V_68 ) {
case 33 :
return V_69 ;
case 50 :
return V_70 ;
}
return V_69 ;
}
static int F_16 ( struct V_24 * V_25 , T_5 * V_71 )
{
struct V_26 * V_27 ;
unsigned int V_15 ;
T_2 V_72 , V_73 , V_74 , V_75 ;
if ( V_25 == NULL || V_25 -> V_25 >= V_43 ||
( V_71 -> V_76 != V_71 -> V_68 && V_71 -> V_76 != 0 ) ||
( V_71 -> V_68 != 50 && V_71 -> V_68 != 33 && V_71 -> V_68 != 0 ) )
return - V_44 ;
V_15 = V_25 -> V_25 ;
V_27 = & V_35 [ V_15 ] ;
F_17 ( & V_27 -> V_38 ) ;
V_72 = F_15 ( V_71 -> V_68 ) ;
F_9 ( V_15 , V_77 , V_72 ) ;
V_73 = V_78 ;
if ( V_71 -> V_76 == V_71 -> V_68 )
V_73 |= V_79 ;
if ( V_71 -> V_80 & V_81 )
V_73 |= V_82 ;
F_9 ( V_15 , V_83 , V_73 ) ;
V_74 = 0 ;
if ( V_71 -> V_37 != 0 )
V_74 |= V_27 -> V_37 ;
if ( V_71 -> V_80 & V_84 )
V_74 |= V_47 ;
if ( V_71 -> V_80 & V_85 )
V_74 &= ~ V_86 ;
else
V_74 |= V_86 ;
F_9 ( V_15 , V_46 , V_74 ) ;
V_75 = 0 ;
F_9 ( V_15 , V_87 , V_75 ) ;
F_5 ( V_15 , V_88 ) ;
if ( V_71 -> V_89 != 0 )
V_75 |= V_27 -> V_36 << 8 ;
if ( V_71 -> V_80 & V_84 ) {
if ( V_71 -> V_89 & V_49 )
V_75 |= V_90 ;
} else {
if ( V_71 -> V_89 & V_51 )
V_75 |= V_91 ;
if ( V_71 -> V_89 & V_53 )
V_75 |= V_92 ;
}
if ( V_71 -> V_89 & V_59 )
V_75 |= V_93 ;
if ( V_71 -> V_89 & V_55 )
V_75 |= V_94 ;
F_9 ( V_15 , V_87 , V_75 ) ;
F_18 ( & V_27 -> V_38 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 , struct V_95 * V_96 )
{
unsigned int V_15 ;
T_2 V_97 , V_98 ;
T_4 V_99 ;
if ( V_25 == NULL || V_25 -> V_25 >= V_43 ||
V_96 == NULL || V_96 -> V_99 >= V_100 ||
V_96 -> V_101 > 0xffff || V_96 -> V_102 > 0xffff || V_96 -> V_101 > V_96 -> V_102 )
return - V_44 ;
V_15 = V_25 -> V_25 ;
V_99 = V_96 -> V_99 ;
V_98 = F_5 ( V_15 , V_103 ) ;
if ( V_98 & F_20 ( V_99 ) ) {
V_98 &= ~ F_20 ( V_99 ) ;
F_9 ( V_15 , V_103 , V_98 ) ;
}
F_10 ( V_15 , F_21 ( V_99 ) + V_104 , V_96 -> V_101 ) ;
F_10 ( V_15 , F_21 ( V_99 ) + V_105 , V_96 -> V_102 ) ;
V_97 = 0 ;
if ( V_96 -> V_106 > 0 )
V_97 |= F_22 ( V_99 ) ;
if ( V_96 -> V_80 & V_107 )
V_97 |= F_23 ( V_99 ) ;
if ( V_96 -> V_80 & V_108 )
V_97 |= F_24 ( V_99 ) ;
if ( V_96 -> V_80 & V_109 )
V_97 |= F_25 ( V_99 ) ;
F_9 ( V_15 , V_110 , V_97 ) ;
if ( V_96 -> V_80 & V_111 ) {
V_98 |= F_20 ( V_99 ) ;
F_9 ( V_15 , V_103 , V_98 ) ;
}
return 0 ;
}
static int F_26 ( struct V_24 * V_25 , struct V_112 * V_113 )
{
unsigned int V_15 ;
T_1 V_101 , V_102 , V_114 ;
T_2 V_98 ;
T_4 V_99 ;
if ( V_25 == NULL || V_25 -> V_25 >= V_43 ||
V_113 == NULL || V_113 -> V_99 >= V_115 ||
V_113 -> V_116 -> V_101 < V_117 || V_113 -> V_116 -> V_101 > V_118 ||
V_113 -> V_116 -> V_119 < V_117 || V_113 -> V_116 -> V_119 > V_118 ||
V_113 -> V_116 -> V_101 > V_113 -> V_116 -> V_119 ||
V_113 -> V_120 > V_121 ||
V_113 -> V_106 > V_122 )
return - V_44 ;
V_15 = V_25 -> V_25 ;
V_99 = V_113 -> V_99 ;
V_98 = F_5 ( V_15 , V_103 ) ;
if ( V_98 & F_27 ( V_99 ) ) {
V_98 &= ~ F_27 ( V_99 ) ;
F_9 ( V_15 , V_103 , V_98 ) ;
}
V_101 = ( V_113 -> V_116 -> V_101 >> 12 ) & 0x3fff ;
if ( V_113 -> V_80 & V_107 )
V_101 |= V_123 ;
F_10 ( V_15 , F_28 ( V_99 ) + V_104 , V_101 ) ;
V_102 = ( V_113 -> V_116 -> V_119 >> 12 ) & 0x3fff ;
switch ( V_113 -> V_106 ) {
case 0 :
break;
case 1 :
V_102 |= V_124 ;
break;
case 2 :
V_102 |= V_125 ;
break;
default:
V_102 |= V_124 | V_125 ;
break;
}
F_10 ( V_15 , F_28 ( V_99 ) + V_105 , V_102 ) ;
V_114 = ( V_113 -> V_120 >> 12 ) & 0x3fff ;
if ( V_113 -> V_80 & V_126 )
V_114 |= V_127 ;
if ( V_113 -> V_80 & V_128 )
V_114 |= V_129 ;
F_10 ( V_15 , F_28 ( V_99 ) + V_130 , V_114 ) ;
if ( V_113 -> V_80 & V_111 ) {
V_98 |= F_27 ( V_99 ) ;
F_9 ( V_15 , V_103 , V_98 ) ;
}
return 0 ;
}
static inline unsigned int F_29 ( int V_15 )
{
unsigned int V_131 = 0 ;
T_2 V_40 , V_132 ;
V_40 = F_5 ( V_15 , V_45 ) ;
V_132 = F_5 ( V_15 , V_88 ) ;
if ( F_5 ( V_15 , V_46 ) & V_47 ) {
if ( ( V_132 & V_90 ) && ( V_40 & V_48 ) )
V_131 |= V_49 ;
} else {
if ( V_132 & ( V_91 | V_92 ) ) {
if ( ! ( V_40 & V_50 ) )
V_131 |= V_51 ;
else if ( ( V_40 & ( V_50 | V_52 ) ) == V_50 )
V_131 |= V_53 ;
}
}
if ( ( V_132 & V_93 ) && ( V_40 & V_58 ) )
V_131 |= V_59 ;
if ( ( V_132 & V_94 ) && ( ( V_40 & V_54 ) == V_54 ) )
V_131 |= V_55 ;
return V_131 ;
}
static T_6 F_30 ( int V_133 , void * V_134 )
{
struct V_26 * V_27 ;
unsigned int V_131 ;
T_6 V_135 = V_136 ;
T_1 V_40 ;
V_40 = F_1 () ;
if ( V_40 & V_137 ) {
V_27 = & V_35 [ V_138 ] ;
if ( V_27 -> V_15 == V_139 ) {
if ( V_40 & ( 1 << V_27 -> V_36 ) ) {
V_131 = F_29 ( V_138 ) ;
if ( V_131 != 0 ) {
F_31 ( & V_27 -> V_24 , V_131 ) ;
V_135 = V_140 ;
}
}
}
}
if ( V_40 & V_141 ) {
V_27 = & V_35 [ V_17 ] ;
if ( V_27 -> V_15 == V_139 ) {
if ( V_40 & ( 1 << V_27 -> V_36 ) ) {
V_131 = F_29 ( V_17 ) ;
if ( V_131 != 0 ) {
F_31 ( & V_27 -> V_24 , V_131 ) ;
V_135 = V_140 ;
}
}
}
}
return V_135 ;
}
static inline void F_32 ( int V_15 )
{
unsigned int V_133 ;
V_133 = F_5 ( V_15 , V_46 ) ;
V_133 &= 0x0f ;
V_23 &= ~ ( 1 << V_133 ) ;
V_133 = F_5 ( V_15 , V_87 ) ;
V_133 = ( V_133 & 0xf0 ) >> 4 ;
V_23 &= ~ ( 1 << V_133 ) ;
}
static int F_33 ( void )
{
struct V_26 * V_27 ;
int V_15 , V_135 ;
for ( V_15 = 0 ; V_15 < V_43 ; V_15 ++ ) {
if ( V_15 == V_17 && V_2 == V_7 )
continue;
V_27 = & V_35 [ V_15 ] ;
if ( V_27 -> V_15 != V_142 ) {
T_2 V_98 ;
switch ( V_27 -> V_15 ) {
case V_143 :
V_98 = F_5 ( V_15 , V_103 ) ;
V_98 &= 0x1f ;
F_9 ( V_15 , V_103 , V_98 ) ;
break;
case V_144 :
V_98 = F_5 ( V_15 , V_103 ) ;
V_98 &= 0xc0 ;
F_9 ( V_15 , V_103 , V_98 ) ;
break;
default:
break;
}
F_32 ( V_15 ) ;
continue;
}
sprintf ( V_27 -> V_145 , L_1 , 'A' + V_15 ) ;
V_27 -> V_24 . V_146 . V_147 = & V_148 . V_146 ;
V_27 -> V_24 . V_149 = & V_150 ;
V_27 -> V_24 . V_151 = V_152 ;
V_135 = F_34 ( & V_27 -> V_24 ) ;
if ( V_135 < 0 )
return V_135 ;
F_9 ( V_15 , V_103 , 0 ) ;
F_9 ( V_15 , V_153 , 0 ) ;
V_27 -> V_15 = V_139 ;
}
return 0 ;
}
static void F_35 ( void )
{
struct V_26 * V_27 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_43 ; V_15 ++ ) {
if ( V_15 == V_17 && V_2 == V_7 )
continue;
V_27 = & V_35 [ V_15 ] ;
if ( V_27 -> V_15 == V_139 )
F_36 ( & V_27 -> V_24 ) ;
V_27 -> V_15 = V_142 ;
}
}
static int F_37 ( char * V_154 )
{
if ( V_154 == NULL || * V_154 == '\0' )
return 1 ;
if ( strncmp ( V_154 , L_2 , 4 ) == 0 ) {
int V_133 ;
V_154 += 4 ;
V_133 = F_38 ( V_154 , & V_154 , 0 ) ;
if ( V_133 >= 0 && V_133 < V_155 )
V_34 = V_133 ;
if ( * V_154 != ',' )
return 1 ;
V_154 ++ ;
}
if ( strncmp ( V_154 , L_3 , 6 ) == 0 ) {
V_154 += 6 ;
if ( * V_154 != '\0' ) {
if ( strncmp ( V_154 , L_4 , 10 ) == 0 ) {
V_35 [ V_138 ] . V_15 = V_143 ;
V_154 += 10 ;
} else if ( strncmp ( V_154 , L_5 , 9 ) == 0 ) {
V_35 [ V_138 ] . V_15 = V_144 ;
V_154 += 9 ;
} else if ( strncmp ( V_154 , L_6 , 7 ) == 0 ) {
V_35 [ V_138 ] . V_15 = V_156 ;
V_154 += 7 ;
}
if ( * V_154 != ',' )
return 1 ;
V_154 ++ ;
} else
return 1 ;
}
if ( strncmp ( V_154 , L_7 , 6 ) == 0 ) {
V_154 += 6 ;
if ( * V_154 != '\0' ) {
if ( strncmp ( V_154 , L_8 , 6 ) == 0 ) {
V_2 = V_9 ;
V_154 += 6 ;
} else if ( strncmp ( V_154 , L_9 , 2 ) == 0 ) {
V_2 = V_11 ;
V_154 += 2 ;
} else if ( strncmp ( V_154 , L_10 , 8 ) == 0 ) {
V_2 = V_13 ;
V_154 += 8 ;
} else if ( strncmp ( V_154 , L_11 , 4 ) == 0 ) {
V_2 = V_7 ;
V_154 += 4 ;
}
if ( * V_154 != ',' )
return 1 ;
V_154 ++ ;
if ( strncmp ( V_154 , L_4 , 10 ) == 0 )
V_35 [ V_17 ] . V_15 = V_143 ;
if ( strncmp ( V_154 , L_5 , 9 ) == 0 )
V_35 [ V_17 ] . V_15 = V_144 ;
if ( strncmp ( V_154 , L_6 , 7 ) == 0 )
V_35 [ V_17 ] . V_15 = V_156 ;
}
}
return 1 ;
}
static int F_39 ( void )
{
int V_135 ;
V_135 = F_40 ( & V_157 ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_41 ( & V_148 ) ;
if ( V_135 < 0 ) {
F_42 ( & V_157 ) ;
return V_135 ;
}
F_3 ( V_2 ) ;
V_135 = F_33 () ;
if ( V_135 == 0 )
V_135 = F_43 ( V_34 , F_30 , V_158 ,
V_159 , V_35 ) ;
if ( V_135 < 0 ) {
F_35 () ;
F_44 ( & V_148 ) ;
F_42 ( & V_157 ) ;
return V_135 ;
}
F_45 ( V_160 L_12 ,
V_157 . V_161 . V_145 , V_34 ) ;
return 0 ;
}
static void F_46 ( void )
{
F_47 ( V_34 , V_35 ) ;
F_35 () ;
F_44 ( & V_148 ) ;
F_42 ( & V_157 ) ;
}
