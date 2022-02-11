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
struct V_103 V_104 ;
if ( V_101 <= 0 )
return;
F_44 ( & V_104 ) ;
if ( V_104 . V_105 - V_2 -> V_106 . V_105 > 0 )
V_101 -= V_107 ;
V_101 -= V_104 . V_108 - V_2 -> V_106 . V_108 ;
if ( V_101 < 10 )
return;
V_102 = V_101 / ( 1000000 / V_109 ) ;
if ( V_102 > 0 )
F_45 ( 1 + V_102 ) ;
else
F_46 ( V_101 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_110 = 1 ;
V_2 -> V_33 . V_56 = FALSE ;
V_2 -> V_33 . V_49 = V_50 ;
V_2 -> V_111 -> V_90 = 0 ;
return F_48 ( V_2 -> V_111 , V_112 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_110 = 0 ;
F_50 ( V_2 -> V_111 ) ;
if ( V_2 -> V_33 . V_56 )
V_2 -> V_8 -> V_35 . V_113 ++ ;
}
static void F_51 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
unsigned V_29 ;
int V_114 = 0 ;
if ( V_2 -> V_110 ) {
F_49 ( V_2 ) ;
F_43 ( V_2 , F_52 ( V_24 ) ) ;
V_114 = 1 ;
}
if ( F_7 ( V_2 -> V_19 ) )
V_29 = F_9 ( V_24 , V_2 -> V_115 ) ;
else
V_29 = F_11 ( V_24 , V_2 -> V_115 ) ;
if ( ! V_114 )
F_38 ( V_2 , V_29 ) ;
V_2 -> V_8 -> V_35 . V_116 ++ ;
V_2 -> V_8 -> V_35 . V_117 += V_24 -> V_28 ;
V_2 -> V_8 -> V_118 = V_119 ;
F_2 ( L_11 , V_24 -> V_28 , V_29 ) ;
if ( F_53 ( V_2 -> V_7 , F_54 ( V_2 -> V_7 , 1 ) ,
V_2 -> V_115 , V_29 ,
NULL , V_120 ) )
V_2 -> V_8 -> V_35 . V_121 ++ ;
}
static int F_55 ( void * V_122 )
{
struct V_1 * V_2 = V_122 ;
struct V_85 * V_6 = V_2 -> V_8 ;
struct V_23 * V_24 ;
while ( ! F_56 () ) {
#ifdef F_57
if ( F_14 ( F_58 ( V_97 ) ) ) {
if ( V_2 -> V_110 )
F_49 ( V_2 ) ;
else
F_38 ( V_2 , - 1 ) ;
F_1 ( V_2 , V_68 , V_123 | V_124 ) ;
F_59 () ;
if ( F_27 ( V_2 , V_2 -> V_19 ) )
break;
}
#endif
V_24 = F_34 ( & V_2 -> V_86 , NULL ) ;
if ( V_24 ) {
unsigned V_125 = F_60 ( V_24 ) ;
F_61 ( V_6 ) ;
if ( V_24 -> V_28 > 0 )
F_51 ( V_2 , V_24 ) ;
F_37 ( V_24 ) ;
if ( ( V_125 != - 1 ) && ( V_2 -> V_19 != V_125 ) ) {
if ( F_38 ( V_2 , - 1 ) ||
F_27 ( V_2 , V_125 ) )
break;
}
continue;
}
if ( ! V_2 -> V_110 &&
F_62 ( V_6 ) ) {
if ( F_38 ( V_2 , - 1 ) )
break;
if ( F_14 ( F_47 ( V_2 ) ) ) {
if ( F_63 () )
F_64 ( & V_6 -> V_6 ,
L_12 ,
V_2 -> V_8 -> V_9 ) ;
V_2 -> V_110 = 0 ;
F_42 ( 10 ) ;
continue;
}
}
F_65 ( V_126 ) ;
F_66 () ;
}
return 0 ;
}
static void F_67 ( struct V_127 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_128 ;
int V_63 ;
if ( ! F_40 ( V_2 -> V_8 ) )
return;
if ( V_127 -> V_90 != 0 )
return;
if ( V_127 -> V_129 > 0 ) {
F_2 ( L_13 , V_127 -> V_129 ) ;
F_26 ( V_2 , V_127 -> V_130 ,
V_127 -> V_129 ) ;
F_44 ( & V_2 -> V_106 ) ;
}
if ( ! V_2 -> V_110 )
return;
V_63 = F_48 ( V_127 , V_131 ) ;
if ( V_63 ) {
F_29 ( & V_2 -> V_8 -> V_6 , L_14 ,
V_63 ) ;
V_2 -> V_110 = 0 ;
F_35 ( V_2 -> V_87 ) ;
}
}
static int F_68 ( struct V_85 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
int V_63 ;
char V_132 [ 16 ] ;
V_63 = F_69 ( V_2 -> V_7 , F_54 ( V_2 -> V_7 , 1 ) ) ;
if ( V_63 )
goto V_133;
V_63 = F_69 ( V_2 -> V_7 , F_70 ( V_2 -> V_7 , 2 ) ) ;
if ( V_63 )
goto V_133;
V_63 = F_27 ( V_2 , 9600 ) ;
if ( V_63 )
goto V_133;
V_63 = - V_134 ;
V_2 -> V_110 = 0 ;
V_2 -> V_33 . V_41 = V_135 ;
V_2 -> V_33 . V_24 = F_16 ( V_135 ) ;
if ( ! V_2 -> V_33 . V_24 )
goto V_133;
F_17 ( V_2 -> V_33 . V_24 , 1 ) ;
V_2 -> V_33 . V_42 = V_2 -> V_33 . V_24 -> V_15 ;
F_44 ( & V_2 -> V_106 ) ;
V_2 -> V_111 = F_71 ( 0 , V_112 ) ;
if ( ! V_2 -> V_111 )
goto V_136;
V_2 -> V_115 = F_72 ( V_32 , V_112 ) ;
if ( ! V_2 -> V_115 )
goto V_137;
F_73 ( V_2 -> V_111 , V_2 -> V_7 ,
F_70 ( V_2 -> V_7 , 2 ) ,
V_2 -> V_115 , V_32 ,
F_67 , V_2 ) ;
V_2 -> V_93 = F_72 ( V_94 , V_112 ) ;
if ( ! V_2 -> V_93 )
goto V_138;
sprintf ( V_132 , L_15 , V_2 -> V_7 -> V_139 ) ;
V_2 -> V_140 = F_74 ( V_8 , & V_2 -> V_141 , V_132 ) ;
if ( ! V_2 -> V_140 ) {
V_63 ( L_16 ) ;
goto V_142;
}
V_2 -> V_87 = F_75 ( F_55 , V_2 ,
L_17 , V_2 -> V_8 -> V_9 ) ;
if ( F_76 ( V_2 -> V_87 ) ) {
V_63 = F_77 ( V_2 -> V_87 ) ;
V_63 ( L_18 ) ;
goto V_143;
}
F_78 ( V_8 ) ;
return 0 ;
V_143:
F_79 ( V_2 -> V_140 ) ;
V_142:
F_80 ( V_2 -> V_93 ) ;
V_138:
F_80 ( V_2 -> V_115 ) ;
V_137:
F_81 ( V_2 -> V_111 ) ;
V_136:
F_82 ( V_2 -> V_33 . V_24 ) ;
V_133:
return V_63 ;
}
static int F_83 ( struct V_85 * V_8 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
F_32 ( V_8 ) ;
F_84 ( V_2 -> V_87 ) ;
F_80 ( V_2 -> V_93 ) ;
F_50 ( V_2 -> V_111 ) ;
F_80 ( V_2 -> V_115 ) ;
F_81 ( V_2 -> V_111 ) ;
F_82 ( V_2 -> V_33 . V_24 ) ;
if ( V_2 -> V_140 )
F_79 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
return 0 ;
}
static int F_85 ( struct V_85 * V_8 , struct V_144 * V_145 , int V_146 )
{
struct V_147 * V_148 = (struct V_147 * ) V_145 ;
struct V_1 * V_2 = F_31 ( V_8 ) ;
int V_149 = 0 ;
switch ( V_146 ) {
case V_150 :
if ( ! F_86 ( V_151 ) )
return - V_152 ;
if ( F_41 ( V_2 -> V_8 ) )
V_149 = F_27 ( V_2 , V_148 -> V_153 ) ;
break;
case V_154 :
if ( ! F_86 ( V_151 ) )
return - V_152 ;
if ( F_40 ( V_2 -> V_8 ) )
F_87 ( V_2 -> V_8 , TRUE ) ;
break;
case V_155 :
V_148 -> V_156 = V_2 -> V_110 ;
break;
default:
V_149 = - V_157 ;
}
return V_149 ;
}
static int F_88 ( struct V_158 * V_159 ,
const struct V_160 * V_161 )
{
struct V_5 * V_6 = F_89 ( V_159 ) ;
struct V_1 * V_2 = NULL ;
struct V_85 * V_162 ;
int V_149 = - V_134 ;
V_162 = F_90 ( sizeof( * V_2 ) ) ;
if( ! V_162 )
goto V_133;
F_91 ( V_162 , & V_159 -> V_6 ) ;
V_2 = F_31 ( V_162 ) ;
V_2 -> V_8 = V_162 ;
V_2 -> V_7 = V_6 ;
V_149 = F_92 ( V_6 ) ;
if ( V_149 != 0 ) {
V_63 ( L_19 ) ;
goto V_136;
}
F_93 ( V_163 L_20
L_21 ,
V_6 -> V_139 , F_94 ( V_6 -> V_164 . V_165 ) ,
F_94 ( V_6 -> V_164 . V_166 ) ) ;
F_95 ( & V_2 -> V_141 ) ;
V_2 -> V_141 . V_167 . V_168 &= V_169 | V_170 | V_171 |
V_172 | V_173 | V_174 |
( V_175 << 8 ) ;
V_2 -> V_141 . V_176 . V_168 &= V_177 ;
F_96 ( & V_2 -> V_141 ) ;
V_162 -> V_178 = & V_179 ;
V_149 = F_97 ( V_162 ) ;
if ( V_149 != 0 )
goto V_136;
F_64 ( & V_159 -> V_6 , L_22 ,
V_162 -> V_9 ) ;
F_98 ( V_159 , V_2 ) ;
return 0 ;
V_136:
F_99 ( V_162 ) ;
V_133:
return V_149 ;
}
static void F_100 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_101 ( V_159 ) ;
if ( ! V_2 )
return;
F_102 ( V_2 -> V_8 ) ;
F_99 ( V_2 -> V_8 ) ;
F_98 ( V_159 , NULL ) ;
}
static int F_103 ( struct V_158 * V_159 , T_7 V_180 )
{
struct V_1 * V_2 = F_101 ( V_159 ) ;
F_104 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_105 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_101 ( V_159 ) ;
F_106 ( V_2 -> V_8 ) ;
return 0 ;
}
static int T_8 F_107 ( void )
{
return F_108 ( & V_181 ) ;
}
static void T_9 F_109 ( void )
{
F_110 ( & V_181 ) ;
}
