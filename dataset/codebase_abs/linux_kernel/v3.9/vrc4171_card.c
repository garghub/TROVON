static inline T_1 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_2 V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ V_5 ;
switch ( V_2 ) {
case V_6 :
V_3 |= V_7 ;
break;
case V_8 :
V_3 |= V_9 ;
break;
case V_10 :
V_3 |= V_11 ;
break;
case V_12 :
V_3 |= V_13 ;
break;
default:
break;
}
F_4 ( V_3 , V_4 ) ;
}
static inline T_3 F_5 ( int V_14 , T_3 V_15 )
{
if ( V_14 == V_16 )
V_15 += V_17 ;
F_6 ( V_15 , V_18 ) ;
return F_7 ( V_19 ) ;
}
static inline T_1 F_8 ( int V_14 , T_3 V_15 )
{
T_1 V_20 ;
if ( V_14 == V_16 )
V_15 += V_17 ;
F_6 ( V_15 ++ , V_18 ) ;
V_20 = F_7 ( V_19 ) ;
F_6 ( V_15 , V_18 ) ;
V_20 |= ( ( T_1 ) F_7 ( V_19 ) ) << 8 ;
return V_20 ;
}
static inline T_3 F_9 ( int V_14 , T_3 V_15 , T_3 V_20 )
{
if ( V_14 == V_16 )
V_15 += V_17 ;
F_6 ( V_15 , V_18 ) ;
F_6 ( V_20 , V_19 ) ;
return V_20 ;
}
static inline T_1 F_10 ( int V_14 , T_3 V_15 , T_1 V_20 )
{
if ( V_14 == V_16 )
V_15 += V_17 ;
F_6 ( V_15 ++ , V_18 ) ;
F_6 ( V_20 , V_19 ) ;
F_6 ( V_15 , V_18 ) ;
F_6 ( ( T_3 ) ( V_20 >> 8 ) , V_19 ) ;
return V_20 ;
}
static inline int F_11 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
if ( V_22 & ( 1 << V_21 ) ) {
V_22 &= ~ ( 1 << V_21 ) ;
return V_21 ;
}
}
return - 1 ;
}
static int F_12 ( struct V_23 * V_24 )
{
T_4 * V_25 ;
unsigned int V_14 ;
V_24 -> V_26 |= V_27 | V_28 ;
V_24 -> V_29 = 0 ;
V_24 -> V_30 = 0x1000 ;
V_24 -> V_31 = V_32 ;
V_14 = V_24 -> V_24 ;
V_25 = & V_33 [ V_14 ] ;
V_25 -> V_34 = F_11 () ;
V_25 -> V_35 = F_11 () ;
F_13 ( & V_25 -> V_36 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 , T_5 * V_37 )
{
unsigned int V_14 ;
T_3 V_38 , V_39 ;
T_5 V_40 = 0 ;
if ( V_24 == NULL || V_24 -> V_24 >= V_41 || V_37 == NULL )
return - V_42 ;
V_14 = V_24 -> V_24 ;
V_38 = F_5 ( V_14 , V_43 ) ;
if ( F_5 ( V_14 , V_44 ) & V_45 ) {
if ( V_38 & V_46 )
V_40 |= V_47 ;
} else {
if ( ! ( V_38 & V_48 ) )
V_40 |= V_49 ;
else if ( ( V_38 & ( V_48 | V_50 ) ) == V_48 )
V_40 |= V_51 ;
}
if ( ( V_38 & V_52 ) == V_52 )
V_40 |= V_53 ;
if ( V_38 & V_54 )
V_40 |= V_55 ;
if ( V_38 & V_56 )
V_40 |= V_57 ;
if ( V_38 & V_58 )
V_40 |= V_59 ;
V_39 = F_5 ( V_14 , V_60 ) ;
switch ( V_39 ) {
case V_61 :
V_40 |= V_62 | V_63 ;
break;
case V_64 :
V_40 |= V_63 ;
break;
case V_65 :
V_40 |= V_62 ;
break;
default:
break;
}
* V_37 = V_40 ;
return 0 ;
}
static inline T_3 F_15 ( T_6 V_66 )
{
switch ( V_66 ) {
case 33 :
return V_67 ;
case 50 :
return V_68 ;
}
return V_67 ;
}
static int F_16 ( struct V_23 * V_24 , T_7 * V_69 )
{
T_4 * V_25 ;
unsigned int V_14 ;
T_3 V_70 , V_71 , V_72 , V_73 ;
if ( V_24 == NULL || V_24 -> V_24 >= V_41 ||
( V_69 -> V_74 != V_69 -> V_66 && V_69 -> V_74 != 0 ) ||
( V_69 -> V_66 != 50 && V_69 -> V_66 != 33 && V_69 -> V_66 != 0 ) )
return - V_42 ;
V_14 = V_24 -> V_24 ;
V_25 = & V_33 [ V_14 ] ;
F_17 ( & V_25 -> V_36 ) ;
V_70 = F_15 ( V_69 -> V_66 ) ;
F_9 ( V_14 , V_75 , V_70 ) ;
V_71 = V_76 ;
if ( V_69 -> V_74 == V_69 -> V_66 )
V_71 |= V_77 ;
if ( V_69 -> V_78 & V_79 )
V_71 |= V_80 ;
F_9 ( V_14 , V_81 , V_71 ) ;
V_72 = 0 ;
if ( V_69 -> V_35 != 0 )
V_72 |= V_25 -> V_35 ;
if ( V_69 -> V_78 & V_82 )
V_72 |= V_45 ;
if ( V_69 -> V_78 & V_83 )
V_72 &= ~ V_84 ;
else
V_72 |= V_84 ;
F_9 ( V_14 , V_44 , V_72 ) ;
V_73 = 0 ;
F_9 ( V_14 , V_85 , V_73 ) ;
F_5 ( V_14 , V_86 ) ;
if ( V_69 -> V_87 != 0 )
V_73 |= V_25 -> V_34 << 8 ;
if ( V_69 -> V_78 & V_82 ) {
if ( V_69 -> V_87 & V_47 )
V_73 |= V_88 ;
} else {
if ( V_69 -> V_87 & V_49 )
V_73 |= V_89 ;
if ( V_69 -> V_87 & V_51 )
V_73 |= V_90 ;
}
if ( V_69 -> V_87 & V_57 )
V_73 |= V_91 ;
if ( V_69 -> V_87 & V_53 )
V_73 |= V_92 ;
F_9 ( V_14 , V_85 , V_73 ) ;
F_18 ( & V_25 -> V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 , struct V_93 * V_94 )
{
unsigned int V_14 ;
T_3 V_95 , V_96 ;
T_6 V_97 ;
if ( V_24 == NULL || V_24 -> V_24 >= V_41 ||
V_94 == NULL || V_94 -> V_97 >= V_98 ||
V_94 -> V_99 > 0xffff || V_94 -> V_100 > 0xffff || V_94 -> V_99 > V_94 -> V_100 )
return - V_42 ;
V_14 = V_24 -> V_24 ;
V_97 = V_94 -> V_97 ;
V_96 = F_5 ( V_14 , V_101 ) ;
if ( V_96 & F_20 ( V_97 ) ) {
V_96 &= ~ F_20 ( V_97 ) ;
F_9 ( V_14 , V_101 , V_96 ) ;
}
F_10 ( V_14 , F_21 ( V_97 ) + V_102 , V_94 -> V_99 ) ;
F_10 ( V_14 , F_21 ( V_97 ) + V_103 , V_94 -> V_100 ) ;
V_95 = 0 ;
if ( V_94 -> V_104 > 0 )
V_95 |= F_22 ( V_97 ) ;
if ( V_94 -> V_78 & V_105 )
V_95 |= F_23 ( V_97 ) ;
if ( V_94 -> V_78 & V_106 )
V_95 |= F_24 ( V_97 ) ;
if ( V_94 -> V_78 & V_107 )
V_95 |= F_25 ( V_97 ) ;
F_9 ( V_14 , V_108 , V_95 ) ;
if ( V_94 -> V_78 & V_109 ) {
V_96 |= F_20 ( V_97 ) ;
F_9 ( V_14 , V_101 , V_96 ) ;
}
return 0 ;
}
static int F_26 ( struct V_23 * V_24 , struct V_110 * V_111 )
{
unsigned int V_14 ;
T_1 V_99 , V_100 , V_112 ;
T_3 V_96 ;
T_6 V_97 ;
if ( V_24 == NULL || V_24 -> V_24 >= V_41 ||
V_111 == NULL || V_111 -> V_97 >= V_113 ||
V_111 -> V_114 -> V_99 < V_115 || V_111 -> V_114 -> V_99 > V_116 ||
V_111 -> V_114 -> V_117 < V_115 || V_111 -> V_114 -> V_117 > V_116 ||
V_111 -> V_114 -> V_99 > V_111 -> V_114 -> V_117 ||
V_111 -> V_118 > V_119 ||
V_111 -> V_104 > V_120 )
return - V_42 ;
V_14 = V_24 -> V_24 ;
V_97 = V_111 -> V_97 ;
V_96 = F_5 ( V_14 , V_101 ) ;
if ( V_96 & F_27 ( V_97 ) ) {
V_96 &= ~ F_27 ( V_97 ) ;
F_9 ( V_14 , V_101 , V_96 ) ;
}
V_99 = ( V_111 -> V_114 -> V_99 >> 12 ) & 0x3fff ;
if ( V_111 -> V_78 & V_105 )
V_99 |= V_121 ;
F_10 ( V_14 , F_28 ( V_97 ) + V_102 , V_99 ) ;
V_100 = ( V_111 -> V_114 -> V_117 >> 12 ) & 0x3fff ;
switch ( V_111 -> V_104 ) {
case 0 :
break;
case 1 :
V_100 |= V_122 ;
break;
case 2 :
V_100 |= V_123 ;
break;
default:
V_100 |= V_122 | V_123 ;
break;
}
F_10 ( V_14 , F_28 ( V_97 ) + V_103 , V_100 ) ;
V_112 = ( V_111 -> V_118 >> 12 ) & 0x3fff ;
if ( V_111 -> V_78 & V_124 )
V_112 |= V_125 ;
if ( V_111 -> V_78 & V_126 )
V_112 |= V_127 ;
F_10 ( V_14 , F_28 ( V_97 ) + V_128 , V_112 ) ;
if ( V_111 -> V_78 & V_109 ) {
V_96 |= F_27 ( V_97 ) ;
F_9 ( V_14 , V_101 , V_96 ) ;
}
return 0 ;
}
static inline unsigned int F_29 ( int V_14 )
{
unsigned int V_129 = 0 ;
T_3 V_38 , V_130 ;
V_38 = F_5 ( V_14 , V_43 ) ;
V_130 = F_5 ( V_14 , V_86 ) ;
if ( F_5 ( V_14 , V_44 ) & V_45 ) {
if ( ( V_130 & V_88 ) && ( V_38 & V_46 ) )
V_129 |= V_47 ;
} else {
if ( V_130 & ( V_89 | V_90 ) ) {
if ( ! ( V_38 & V_48 ) )
V_129 |= V_49 ;
else if ( ( V_38 & ( V_48 | V_50 ) ) == V_48 )
V_129 |= V_51 ;
}
}
if ( ( V_130 & V_91 ) && ( V_38 & V_56 ) )
V_129 |= V_57 ;
if ( ( V_130 & V_92 ) && ( ( V_38 & V_52 ) == V_52 ) )
V_129 |= V_53 ;
return V_129 ;
}
static T_8 F_30 ( int V_131 , void * V_132 )
{
T_4 * V_25 ;
unsigned int V_129 ;
T_8 V_133 = V_134 ;
T_1 V_38 ;
V_38 = F_1 () ;
if ( V_38 & V_135 ) {
V_25 = & V_33 [ V_136 ] ;
if ( V_25 -> V_14 == V_137 ) {
if ( V_38 & ( 1 << V_25 -> V_34 ) ) {
V_129 = F_29 ( V_136 ) ;
if ( V_129 != 0 ) {
F_31 ( & V_25 -> V_23 , V_129 ) ;
V_133 = V_138 ;
}
}
}
}
if ( V_38 & V_139 ) {
V_25 = & V_33 [ V_16 ] ;
if ( V_25 -> V_14 == V_137 ) {
if ( V_38 & ( 1 << V_25 -> V_34 ) ) {
V_129 = F_29 ( V_16 ) ;
if ( V_129 != 0 ) {
F_31 ( & V_25 -> V_23 , V_129 ) ;
V_133 = V_138 ;
}
}
}
}
return V_133 ;
}
static inline void F_32 ( int V_14 )
{
unsigned int V_131 ;
V_131 = F_5 ( V_14 , V_44 ) ;
V_131 &= 0x0f ;
V_22 &= ~ ( 1 << V_131 ) ;
V_131 = F_5 ( V_14 , V_85 ) ;
V_131 = ( V_131 & 0xf0 ) >> 4 ;
V_22 &= ~ ( 1 << V_131 ) ;
}
static int F_33 ( void )
{
T_4 * V_25 ;
int V_14 , V_133 ;
for ( V_14 = 0 ; V_14 < V_41 ; V_14 ++ ) {
if ( V_14 == V_16 && V_140 == V_6 )
continue;
V_25 = & V_33 [ V_14 ] ;
if ( V_25 -> V_14 != V_141 ) {
T_3 V_96 ;
switch ( V_25 -> V_14 ) {
case V_142 :
V_96 = F_5 ( V_14 , V_101 ) ;
V_96 &= 0x1f ;
F_9 ( V_14 , V_101 , V_96 ) ;
break;
case V_143 :
V_96 = F_5 ( V_14 , V_101 ) ;
V_96 &= 0xc0 ;
F_9 ( V_14 , V_101 , V_96 ) ;
break;
default:
break;
}
F_32 ( V_14 ) ;
continue;
}
sprintf ( V_25 -> V_144 , L_1 , 'A' + V_14 ) ;
V_25 -> V_23 . V_145 . V_146 = & V_147 . V_145 ;
V_25 -> V_23 . V_148 = & V_149 ;
V_25 -> V_23 . V_150 = V_151 ;
V_133 = F_34 ( & V_25 -> V_23 ) ;
if ( V_133 < 0 )
return V_133 ;
F_9 ( V_14 , V_101 , 0 ) ;
F_9 ( V_14 , V_152 , 0 ) ;
V_25 -> V_14 = V_137 ;
}
return 0 ;
}
static void F_35 ( void )
{
T_4 * V_25 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_41 ; V_14 ++ ) {
if ( V_14 == V_16 && V_140 == V_6 )
continue;
V_25 = & V_33 [ V_14 ] ;
if ( V_25 -> V_14 == V_137 )
F_36 ( & V_25 -> V_23 ) ;
V_25 -> V_14 = V_141 ;
}
}
static int F_37 ( char * V_153 )
{
if ( V_153 == NULL || * V_153 == '\0' )
return 1 ;
if ( strncmp ( V_153 , L_2 , 4 ) == 0 ) {
int V_131 ;
V_153 += 4 ;
V_131 = F_38 ( V_153 , & V_153 , 0 ) ;
if ( V_131 >= 0 && V_131 < V_154 )
V_32 = V_131 ;
if ( * V_153 != ',' )
return 1 ;
V_153 ++ ;
}
if ( strncmp ( V_153 , L_3 , 6 ) == 0 ) {
V_153 += 6 ;
if ( * V_153 != '\0' ) {
if ( strncmp ( V_153 , L_4 , 10 ) == 0 ) {
V_33 [ V_136 ] . V_14 = V_142 ;
V_153 += 10 ;
} else if ( strncmp ( V_153 , L_5 , 9 ) == 0 ) {
V_33 [ V_136 ] . V_14 = V_143 ;
V_153 += 9 ;
} else if ( strncmp ( V_153 , L_6 , 7 ) == 0 ) {
V_33 [ V_136 ] . V_14 = V_155 ;
V_153 += 7 ;
}
if ( * V_153 != ',' )
return 1 ;
V_153 ++ ;
} else
return 1 ;
}
if ( strncmp ( V_153 , L_7 , 6 ) == 0 ) {
V_153 += 6 ;
if ( * V_153 != '\0' ) {
if ( strncmp ( V_153 , L_8 , 6 ) == 0 ) {
V_140 = V_8 ;
V_153 += 6 ;
} else if ( strncmp ( V_153 , L_9 , 2 ) == 0 ) {
V_140 = V_10 ;
V_153 += 2 ;
} else if ( strncmp ( V_153 , L_10 , 8 ) == 0 ) {
V_140 = V_12 ;
V_153 += 8 ;
} else if ( strncmp ( V_153 , L_11 , 4 ) == 0 ) {
V_140 = V_6 ;
V_153 += 4 ;
}
if ( * V_153 != ',' )
return 1 ;
V_153 ++ ;
if ( strncmp ( V_153 , L_4 , 10 ) == 0 )
V_33 [ V_16 ] . V_14 = V_142 ;
if ( strncmp ( V_153 , L_5 , 9 ) == 0 )
V_33 [ V_16 ] . V_14 = V_143 ;
if ( strncmp ( V_153 , L_6 , 7 ) == 0 )
V_33 [ V_16 ] . V_14 = V_155 ;
}
}
return 1 ;
}
static int F_39 ( void )
{
int V_133 ;
V_133 = F_40 ( & V_156 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_41 ( & V_147 ) ;
if ( V_133 < 0 ) {
F_42 ( & V_156 ) ;
return V_133 ;
}
F_3 ( V_140 ) ;
V_133 = F_33 () ;
if ( V_133 == 0 )
V_133 = F_43 ( V_32 , F_30 , V_157 ,
V_158 , V_33 ) ;
if ( V_133 < 0 ) {
F_35 () ;
F_44 ( & V_147 ) ;
F_42 ( & V_156 ) ;
return V_133 ;
}
F_45 ( V_159 L_12 ,
V_156 . V_160 . V_144 , V_32 ) ;
return 0 ;
}
static void F_46 ( void )
{
F_47 ( V_32 , V_33 ) ;
F_35 () ;
F_44 ( & V_147 ) ;
F_42 ( & V_156 ) ;
}
