static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_1 ,
V_2 -> V_8 -> V_9 , V_3 , V_4 ) ;
return F_3 ( V_6 , F_4 ( V_6 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
V_4 , V_3 , NULL , 0 ,
V_14 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_15 , T_1 V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_3 ( V_6 , F_6 ( V_6 , 0 ) ,
V_17 ,
V_18 | V_12 | V_13 ,
0 , V_3 , V_15 , V_16 ,
V_14 ) ;
}
static inline int F_7 ( T_3 V_19 )
{
return V_19 == 4000000 ;
}
static inline T_2 * F_8 ( T_2 * V_20 , T_2 V_21 )
{
switch( V_21 ) {
case 0x7d :
case 0x7e :
case 0x7f :
* V_20 ++ = 0x7d ;
V_21 ^= V_22 ;
default:
* V_20 ++ = V_21 ;
}
return V_20 ;
}
static unsigned F_9 ( const struct V_23 * V_24 , T_2 * V_25 )
{
T_2 * V_26 = V_25 ;
T_4 V_27 = ~ ( F_10 ( ~ 0 , V_24 -> V_15 , V_24 -> V_28 ) ) ;
T_1 V_29 ;
int V_30 ;
V_25 [ 0 ] = 0x55 ;
V_25 [ 1 ] = 0xAA ;
V_26 = V_25 + V_31 ;
memset ( V_26 , 0x7f , 16 ) ;
V_26 += 16 ;
* V_26 ++ = 0x7e ;
* V_26 ++ = 0x7e ;
for ( V_30 = 0 ; V_30 < V_24 -> V_28 ; V_30 ++ )
V_26 = F_8 ( V_26 , V_24 -> V_15 [ V_30 ] ) ;
V_26 = F_8 ( V_26 , V_27 & 0xff ) ;
V_26 = F_8 ( V_26 , ( V_27 >> 8 ) & 0xff ) ;
V_26 = F_8 ( V_26 , ( V_27 >> 16 ) & 0xff ) ;
V_26 = F_8 ( V_26 , ( V_27 >> 24 ) & 0xff ) ;
* V_26 ++ = 0x7e ;
* V_26 ++ = 0x7e ;
V_29 = ( V_26 - V_25 ) - V_31 ;
V_25 [ 2 ] = V_29 & 0xff ;
V_25 [ 3 ] = ( V_29 >> 8 ) & 0xff ;
return V_29 + V_31 ;
}
static unsigned F_11 ( struct V_23 * V_24 , T_2 * V_25 )
{
T_1 V_29 ;
V_29 = F_12 ( V_24 , V_25 + V_31 ,
V_32 - V_31 ) ;
V_25 [ 0 ] = 0x55 ;
V_25 [ 1 ] = 0xAA ;
V_25 [ 2 ] = V_29 & 0xff ;
V_25 [ 3 ] = ( V_29 >> 8 ) & 0xff ;
return V_29 + V_31 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_5 * V_33 = & V_2 -> V_33 ;
int V_28 = V_33 -> V_28 - 4 ;
struct V_23 * V_24 , * V_34 ;
T_4 V_27 ;
if ( F_14 ( V_28 <= 0 ) ) {
F_2 ( L_2 ,
V_2 -> V_8 -> V_9 , V_28 ) ;
++ V_2 -> V_8 -> V_35 . V_36 ;
++ V_2 -> V_8 -> V_35 . V_37 ;
return;
}
V_27 = ~ ( F_10 ( ~ 0 , V_33 -> V_15 , V_28 ) ) ;
if ( V_27 != F_15 ( V_33 -> V_15 + V_28 ) ) {
F_2 ( L_3 , V_27 , V_28 ) ;
V_2 -> V_8 -> V_35 . V_36 ++ ;
V_2 -> V_8 -> V_35 . V_38 ++ ;
return;
}
if ( V_28 < V_39 ) {
V_34 = F_16 ( V_28 + 1 ) ;
if ( F_14 ( ! V_34 ) ) {
++ V_2 -> V_8 -> V_35 . V_40 ;
return;
}
F_17 ( V_34 , 1 ) ;
V_24 = V_34 ;
F_18 ( V_34 , V_33 -> V_15 , V_28 ) ;
} else {
V_34 = F_16 ( V_33 -> V_41 ) ;
if ( F_14 ( ! V_34 ) ) {
++ V_2 -> V_8 -> V_35 . V_40 ;
return;
}
F_17 ( V_34 , 1 ) ;
V_24 = V_33 -> V_24 ;
V_33 -> V_24 = V_34 ;
V_33 -> V_42 = V_34 -> V_15 ;
}
F_19 ( V_24 , V_28 ) ;
F_20 ( V_24 ) ;
V_24 -> V_43 = F_21 ( V_44 ) ;
V_24 -> V_6 = V_2 -> V_8 ;
F_22 ( V_24 ) ;
V_2 -> V_8 -> V_35 . V_45 ++ ;
V_2 -> V_8 -> V_35 . V_46 += V_28 ;
V_33 -> V_15 = V_33 -> V_42 ;
V_33 -> V_28 = 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
const T_2 * V_47 , int V_28 )
{
T_5 * V_33 = & V_2 -> V_33 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
T_2 V_48 = V_47 [ V_30 ] ;
switch( V_33 -> V_49 ) {
case V_50 :
if ( F_14 ( V_48 != V_51 ) )
continue;
V_33 -> V_49 = V_52 ;
V_33 -> V_15 = V_33 -> V_42 ;
V_33 -> V_28 = 0 ;
continue;
case V_53 :
if ( V_48 == V_51 ) {
F_2 ( L_4 ,
V_2 -> V_8 -> V_9 ) ;
goto V_54;
}
V_33 -> V_49 = V_55 ;
V_48 ^= V_22 ;
break;
case V_52 :
if ( V_48 == V_51 )
continue;
V_33 -> V_49 = V_55 ;
V_33 -> V_56 = TRUE ;
case V_55 :
switch( V_48 ) {
case V_57 :
V_33 -> V_49 = V_53 ;
continue;
case V_58 :
F_2 ( L_5 ,
V_2 -> V_8 -> V_9 ) ;
goto V_54;
case V_51 :
V_33 -> V_49 = V_50 ;
V_33 -> V_56 = FALSE ;
F_13 ( V_2 ) ;
continue;
}
break;
}
if ( F_14 ( V_33 -> V_28 >= V_33 -> V_41 ) ) {
F_2 ( L_6 ,
V_2 -> V_8 -> V_9 , V_33 -> V_41 ) ;
++ V_2 -> V_8 -> V_35 . V_59 ;
goto V_60;
}
V_33 -> V_15 [ V_33 -> V_28 ++ ] = V_48 ;
continue;
V_54:
++ V_2 -> V_8 -> V_35 . V_61 ;
V_60:
++ V_2 -> V_8 -> V_35 . V_36 ;
V_33 -> V_49 = V_50 ;
V_33 -> V_56 = FALSE ;
}
}
static void F_24 ( struct V_1 * V_2 ,
const T_2 * V_47 , int V_28 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
F_25 ( V_2 -> V_8 , & V_2 -> V_8 -> V_35 ,
& V_2 -> V_33 , V_47 [ V_30 ] ) ;
}
static inline void F_26 ( struct V_1 * V_2 ,
const T_2 * V_47 , int V_62 )
{
if ( F_7 ( V_2 -> V_19 ) )
F_23 ( V_2 , V_47 , V_62 ) ;
else
F_24 ( V_2 , V_47 , V_62 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned V_19 )
{
int V_30 , V_63 ;
T_2 V_64 ;
for ( V_30 = 0 ; V_30 < F_28 ( V_65 ) ; ++ V_30 ) {
if ( V_19 == V_65 [ V_30 ] . V_19 )
goto V_66;
}
F_29 ( & V_2 -> V_8 -> V_6 , L_7 , V_19 ) ;
return - V_67 ;
V_66:
F_2 ( L_8 , V_2 -> V_19 , V_19 ) ;
V_63 = F_1 ( V_2 , V_68 , V_69 ) ;
if ( V_63 )
goto V_70;
V_63 = F_1 ( V_2 , V_71 , 0x15 ) ;
if ( V_63 )
goto V_70;
V_63 = F_1 ( V_2 , V_72 , V_65 [ V_30 ] . V_73 ) ;
if ( V_63 )
goto V_70;
V_64 = V_74 | V_75 ;
if ( F_7 ( V_19 ) )
V_64 |= V_76 | V_77 ;
else
V_64 |= V_78 ;
if ( V_19 == 2400 )
V_64 |= V_79 ;
V_63 = F_1 ( V_2 , V_80 , V_64 ) ;
if ( V_63 )
goto V_70;
V_63 = F_1 ( V_2 , V_68 ,
V_81 | ( V_82 & 3 ) << 1 ) ;
if ( V_63 )
goto V_70;
V_63 = F_1 ( V_2 , V_68 , ( V_82 & 3 ) << 1 ) ;
if ( V_63 )
goto V_70;
V_63 = F_1 ( V_2 , V_83 , ( V_84 & 7 ) << 5 ) ;
V_70:
V_2 -> V_19 = V_19 ;
return V_63 ;
}
static T_6 F_30 ( struct V_23 * V_24 ,
struct V_85 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
F_32 ( V_8 ) ;
F_33 ( V_24 ) ;
V_24 = F_34 ( & V_2 -> V_86 , V_24 ) ;
F_35 ( V_2 -> V_87 ) ;
if ( F_14 ( V_24 ) ) {
F_36 ( 1 ) ;
F_37 ( V_24 ) ;
}
return V_88 ;
}
static int F_38 ( struct V_1 * V_2 , int V_89 )
{
int V_63 ;
unsigned long V_16 , V_90 ;
unsigned long V_91 = 0x1fff ;
for (; ; V_91 = V_16 ) {
V_63 = F_5 ( V_2 , V_92 , V_2 -> V_93 ,
V_94 ) ;
if ( F_14 ( V_63 != V_94 ) ) {
F_29 ( & V_2 -> V_8 -> V_6 ,
L_9 , V_63 ) ;
return V_63 ;
}
V_90 = V_2 -> V_93 [ 0 ] ;
V_16 = ( unsigned ) ( V_2 -> V_93 [ 2 ] & 0x1f ) << 8
| V_2 -> V_93 [ 1 ] ;
F_2 ( L_10 , V_90 , V_16 ) ;
if ( ! ( V_90 & V_95 ) ||
( V_90 & V_96 ) )
return 0 ;
if ( F_39 ( V_97 ) )
return - V_98 ;
if ( ! F_40 ( V_2 -> V_8 ) ||
! F_41 ( V_2 -> V_8 ) )
return - V_99 ;
if ( V_89 >= 0 && V_32 - 4 > V_89 + V_16 )
return 0 ;
if ( V_91 < V_16 )
break;
F_42 ( ( V_16 * 8000 ) / V_2 -> V_19 ) ;
}
V_63 = F_1 ( V_2 , V_92 , V_100 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_1 ( V_2 , V_92 , 0 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static void F_43 ( const struct V_1 * V_2 , long V_101 )
{
long V_102 ;
if ( V_101 <= 0 )
return;
V_101 -= F_44 ( F_45 () , V_2 -> V_103 ) ;
if ( V_101 < 10 )
return;
V_102 = V_101 / ( 1000000 / V_104 ) ;
if ( V_102 > 0 )
F_46 ( 1 + V_102 ) ;
else
F_47 ( V_101 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
V_2 -> V_105 = 1 ;
V_2 -> V_33 . V_56 = FALSE ;
V_2 -> V_33 . V_49 = V_50 ;
V_2 -> V_106 -> V_90 = 0 ;
return F_49 ( V_2 -> V_106 , V_107 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_105 = 0 ;
F_51 ( V_2 -> V_106 ) ;
if ( V_2 -> V_33 . V_56 )
V_2 -> V_8 -> V_35 . V_108 ++ ;
}
static void F_52 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
unsigned V_29 ;
int V_109 = 0 ;
if ( V_2 -> V_105 ) {
F_50 ( V_2 ) ;
F_43 ( V_2 , F_53 ( V_24 ) ) ;
V_109 = 1 ;
}
if ( F_7 ( V_2 -> V_19 ) )
V_29 = F_9 ( V_24 , V_2 -> V_110 ) ;
else
V_29 = F_11 ( V_24 , V_2 -> V_110 ) ;
if ( ! V_109 )
F_38 ( V_2 , V_29 ) ;
V_2 -> V_8 -> V_35 . V_111 ++ ;
V_2 -> V_8 -> V_35 . V_112 += V_24 -> V_28 ;
F_54 ( V_2 -> V_8 ) ;
F_2 ( L_11 , V_24 -> V_28 , V_29 ) ;
if ( F_55 ( V_2 -> V_7 , F_56 ( V_2 -> V_7 , 1 ) ,
V_2 -> V_110 , V_29 ,
NULL , V_113 ) )
V_2 -> V_8 -> V_35 . V_114 ++ ;
}
static int F_57 ( void * V_115 )
{
struct V_1 * V_2 = V_115 ;
struct V_85 * V_6 = V_2 -> V_8 ;
struct V_23 * V_24 ;
while ( ! F_58 () ) {
#ifdef F_59
if ( F_14 ( F_60 ( V_97 ) ) ) {
if ( V_2 -> V_105 )
F_50 ( V_2 ) ;
else
F_38 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_68 , V_116 | V_117 ) ;
F_61 () ;
if ( F_27 ( V_2 , V_2 -> V_19 ) )
break;
}
#endif
V_24 = F_34 ( & V_2 -> V_86 , NULL ) ;
if ( V_24 ) {
unsigned V_118 = F_62 ( V_24 ) ;
F_63 ( V_6 ) ;
if ( V_24 -> V_28 > 0 )
F_52 ( V_2 , V_24 ) ;
F_37 ( V_24 ) ;
if ( ( V_118 != - 1 ) && ( V_2 -> V_19 != V_118 ) ) {
if ( F_38 ( V_2 , - 1 ) ||
F_27 ( V_2 , V_118 ) )
break;
}
continue;
}
if ( ! V_2 -> V_105 &&
F_64 ( V_6 ) ) {
if ( F_38 ( V_2 , - 1 ) )
break;
if ( F_14 ( F_48 ( V_2 ) ) ) {
if ( F_65 () )
F_66 ( & V_6 -> V_6 ,
L_12 ,
V_2 -> V_8 -> V_9 ) ;
V_2 -> V_105 = 0 ;
F_42 ( 10 ) ;
continue;
}
}
F_67 ( V_119 ) ;
F_68 () ;
}
return 0 ;
}
static void F_69 ( struct V_120 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_121 ;
int V_63 ;
if ( ! F_40 ( V_2 -> V_8 ) )
return;
if ( V_120 -> V_90 != 0 )
return;
if ( V_120 -> V_122 > 0 ) {
F_2 ( L_13 , V_120 -> V_122 ) ;
F_26 ( V_2 , V_120 -> V_123 ,
V_120 -> V_122 ) ;
V_2 -> V_103 = F_45 () ;
}
if ( ! V_2 -> V_105 )
return;
V_63 = F_49 ( V_120 , V_124 ) ;
if ( V_63 ) {
F_29 ( & V_2 -> V_8 -> V_6 , L_14 ,
V_63 ) ;
V_2 -> V_105 = 0 ;
F_35 ( V_2 -> V_87 ) ;
}
}
static int F_70 ( struct V_85 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
int V_63 ;
char V_125 [ 16 ] ;
V_63 = F_71 ( V_2 -> V_7 , F_56 ( V_2 -> V_7 , 1 ) ) ;
if ( V_63 )
goto V_126;
V_63 = F_71 ( V_2 -> V_7 , F_72 ( V_2 -> V_7 , 2 ) ) ;
if ( V_63 )
goto V_126;
V_63 = F_27 ( V_2 , 9600 ) ;
if ( V_63 )
goto V_126;
V_63 = - V_127 ;
V_2 -> V_105 = 0 ;
V_2 -> V_33 . V_41 = V_128 ;
V_2 -> V_33 . V_24 = F_16 ( V_128 ) ;
if ( ! V_2 -> V_33 . V_24 )
goto V_126;
F_17 ( V_2 -> V_33 . V_24 , 1 ) ;
V_2 -> V_33 . V_42 = V_2 -> V_33 . V_24 -> V_15 ;
V_2 -> V_103 = F_45 () ;
V_2 -> V_106 = F_73 ( 0 , V_107 ) ;
if ( ! V_2 -> V_106 )
goto V_129;
V_2 -> V_110 = F_74 ( V_32 , V_107 ) ;
if ( ! V_2 -> V_110 )
goto V_130;
F_75 ( V_2 -> V_106 , V_2 -> V_7 ,
F_72 ( V_2 -> V_7 , 2 ) ,
V_2 -> V_110 , V_32 ,
F_69 , V_2 ) ;
V_2 -> V_93 = F_74 ( V_94 , V_107 ) ;
if ( ! V_2 -> V_93 )
goto V_131;
sprintf ( V_125 , L_15 , V_2 -> V_7 -> V_132 ) ;
V_2 -> V_133 = F_76 ( V_8 , & V_2 -> V_134 , V_125 ) ;
if ( ! V_2 -> V_133 ) {
F_77 ( & V_2 -> V_7 -> V_6 , L_16 ) ;
goto V_135;
}
V_2 -> V_87 = F_78 ( F_57 , V_2 ,
L_17 , V_2 -> V_8 -> V_9 ) ;
if ( F_79 ( V_2 -> V_87 ) ) {
V_63 = F_80 ( V_2 -> V_87 ) ;
F_77 ( & V_2 -> V_7 -> V_6 , L_18 ) ;
goto V_136;
}
F_81 ( V_8 ) ;
return 0 ;
V_136:
F_82 ( V_2 -> V_133 ) ;
V_135:
F_83 ( V_2 -> V_93 ) ;
V_131:
F_83 ( V_2 -> V_110 ) ;
V_130:
F_84 ( V_2 -> V_106 ) ;
V_129:
F_85 ( V_2 -> V_33 . V_24 ) ;
V_126:
return V_63 ;
}
static int F_86 ( struct V_85 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
F_32 ( V_8 ) ;
F_87 ( V_2 -> V_87 ) ;
F_83 ( V_2 -> V_93 ) ;
F_51 ( V_2 -> V_106 ) ;
F_83 ( V_2 -> V_110 ) ;
F_84 ( V_2 -> V_106 ) ;
F_85 ( V_2 -> V_33 . V_24 ) ;
if ( V_2 -> V_133 )
F_82 ( V_2 -> V_133 ) ;
V_2 -> V_133 = NULL ;
return 0 ;
}
static int F_88 ( struct V_85 * V_8 , struct V_137 * V_138 , int V_139 )
{
struct V_140 * V_141 = (struct V_140 * ) V_138 ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
int V_142 = 0 ;
switch ( V_139 ) {
case V_143 :
if ( ! F_89 ( V_144 ) )
return - V_145 ;
if ( F_41 ( V_2 -> V_8 ) )
V_142 = F_27 ( V_2 , V_141 -> V_146 ) ;
break;
case V_147 :
if ( ! F_89 ( V_144 ) )
return - V_145 ;
if ( F_40 ( V_2 -> V_8 ) )
F_90 ( V_2 -> V_8 , TRUE ) ;
break;
case V_148 :
V_141 -> V_149 = V_2 -> V_105 ;
break;
default:
V_142 = - V_150 ;
}
return V_142 ;
}
static int F_91 ( struct V_151 * V_152 ,
const struct V_153 * V_154 )
{
struct V_5 * V_6 = F_92 ( V_152 ) ;
struct V_1 * V_2 = NULL ;
struct V_85 * V_155 ;
int V_142 = - V_127 ;
V_155 = F_93 ( sizeof( * V_2 ) ) ;
if( ! V_155 )
goto V_126;
F_94 ( V_155 , & V_152 -> V_6 ) ;
V_2 = F_31 ( V_155 ) ;
V_2 -> V_8 = V_155 ;
V_2 -> V_7 = V_6 ;
V_142 = F_95 ( V_6 ) ;
if ( V_142 != 0 ) {
F_77 ( & V_152 -> V_6 , L_19 ) ;
goto V_129;
}
F_96 ( V_156 L_20
L_21 ,
V_6 -> V_132 , F_97 ( V_6 -> V_157 . V_158 ) ,
F_97 ( V_6 -> V_157 . V_159 ) ) ;
F_98 ( & V_2 -> V_134 ) ;
V_2 -> V_134 . V_160 . V_161 &= V_162 | V_163 | V_164 |
V_165 | V_166 | V_167 |
( V_168 << 8 ) ;
V_2 -> V_134 . V_169 . V_161 &= V_170 ;
F_99 ( & V_2 -> V_134 ) ;
V_155 -> V_171 = & V_172 ;
V_142 = F_100 ( V_155 ) ;
if ( V_142 != 0 )
goto V_129;
F_66 ( & V_152 -> V_6 , L_22 ,
V_155 -> V_9 ) ;
F_101 ( V_152 , V_2 ) ;
return 0 ;
V_129:
F_102 ( V_155 ) ;
V_126:
return V_142 ;
}
static void F_103 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_104 ( V_152 ) ;
if ( ! V_2 )
return;
F_105 ( V_2 -> V_8 ) ;
F_102 ( V_2 -> V_8 ) ;
F_101 ( V_152 , NULL ) ;
}
static int F_106 ( struct V_151 * V_152 , T_7 V_173 )
{
struct V_1 * V_2 = F_104 ( V_152 ) ;
F_107 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_108 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_104 ( V_152 ) ;
F_109 ( V_2 -> V_8 ) ;
return 0 ;
}
