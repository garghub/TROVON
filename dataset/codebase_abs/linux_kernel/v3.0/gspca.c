static void F_1 ( char * V_1 , T_1 V_2 , int V_3 , int V_4 )
{
if ( ( V_2 >> 24 ) >= '0' && ( V_2 >> 24 ) <= 'z' ) {
F_2 ( V_5 | V_6 , L_1 ,
V_1 ,
V_2 & 0xff ,
( V_2 >> 8 ) & 0xff ,
( V_2 >> 16 ) & 0xff ,
V_2 >> 24 ,
V_3 , V_4 ) ;
} else {
F_2 ( V_5 | V_6 , L_2 ,
V_1 ,
V_2 ,
V_3 , V_4 ) ;
}
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_12 ++ ;
V_10 -> V_13 . V_14 |= V_15 ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
if ( -- V_10 -> V_12 <= 0 )
V_10 -> V_13 . V_14 &= ~ V_15 ;
}
static void F_5 ( struct V_16 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
int V_19 ;
V_19 = V_16 -> V_20 ;
switch ( V_19 ) {
case 0 :
if ( V_17 -> V_21 -> V_22 ( V_17 ,
V_16 -> V_23 , V_16 -> V_24 ) < 0 ) {
F_2 ( V_25 , L_3 ) ;
}
break;
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
break;
default:
F_2 ( V_25 , L_4 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
V_19 = 0 ;
}
if ( V_19 == 0 ) {
V_19 = F_6 ( V_16 , V_30 ) ;
if ( V_19 < 0 )
F_7 ( L_5 , V_19 ) ;
}
}
static int F_8 ( struct V_17 * V_31 )
{
struct V_32 * V_32 ;
int F_7 = 0 ;
V_31 -> V_32 = NULL ;
if ( V_31 -> V_21 -> V_22 || V_31 -> V_21 -> V_33 ) {
V_32 = F_9 () ;
if ( ! V_32 )
return - V_34 ;
F_10 ( V_31 -> V_31 , V_31 -> V_35 , sizeof( V_31 -> V_35 ) ) ;
F_11 ( V_31 -> V_35 , L_6 , sizeof( V_31 -> V_35 ) ) ;
V_32 -> V_36 = V_31 -> V_21 -> V_36 ;
V_32 -> V_35 = V_31 -> V_35 ;
F_12 ( V_31 -> V_31 , & V_32 -> V_37 ) ;
V_32 -> V_38 [ 0 ] = F_13 ( V_39 ) ;
V_32 -> V_40 [ F_14 ( V_41 ) ] = F_13 ( V_41 ) ;
V_32 -> V_31 . V_42 = & V_31 -> V_31 -> V_31 ;
F_7 = F_15 ( V_32 ) ;
if ( F_7 ) {
F_7 ( L_7 ,
F_7 ) ;
V_32 -> V_31 . V_42 = NULL ;
F_16 ( V_32 ) ;
} else {
V_31 -> V_32 = V_32 ;
}
}
return F_7 ;
}
static int F_17 ( struct V_17 * V_17 ,
struct V_43 * V_44 )
{
unsigned int V_45 ;
int V_46 ;
struct V_16 * V_16 ;
struct V_47 * V_31 ;
void * V_48 = NULL ;
int V_19 = - V_49 ;
V_45 = F_18 ( V_44 -> V_50 ) ;
V_46 = V_44 -> V_51 ;
F_2 ( V_5 , L_8
L_9 ,
V_44 -> V_52 , V_45 , V_46 ) ;
V_31 = V_17 -> V_31 ;
V_16 = F_19 ( 0 , V_53 ) ;
if ( ! V_16 ) {
V_19 = - V_34 ;
goto error;
}
V_48 = F_20 ( V_31 , V_45 ,
V_53 , & V_16 -> V_54 ) ;
if ( ! V_48 ) {
V_19 = - V_34 ;
goto V_55;
}
F_21 ( V_16 , V_31 ,
F_22 ( V_31 , V_44 -> V_52 ) ,
V_48 , V_45 ,
F_5 , ( void * ) V_17 , V_46 ) ;
V_16 -> V_56 |= V_57 ;
V_19 = F_6 ( V_16 , V_53 ) ;
if ( V_19 < 0 ) {
F_2 ( V_25 , L_10 , V_19 ) ;
goto V_58;
}
V_17 -> V_59 = V_16 ;
return V_19 ;
V_58:
F_23 ( V_31 ,
V_16 -> V_60 ,
V_16 -> V_23 ,
V_16 -> V_54 ) ;
V_55:
F_24 ( V_16 ) ;
error:
return V_19 ;
}
static void F_25 ( struct V_17 * V_17 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_43 * V_44 ;
int V_65 ;
if ( V_17 -> V_21 -> V_22 ) {
V_62 = F_26 ( V_17 -> V_31 , V_17 -> V_66 ) ;
V_64 = V_62 -> V_67 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_68 . V_69 ; V_65 ++ ) {
V_44 = & V_64 -> V_70 [ V_65 ] . V_68 ;
if ( F_27 ( V_44 ) &&
F_28 ( V_44 ) ) {
F_17 ( V_17 , V_44 ) ;
break;
}
}
}
}
static void F_29 ( struct V_17 * V_17 )
{
struct V_16 * V_16 ;
V_16 = V_17 -> V_59 ;
if ( V_16 ) {
V_17 -> V_59 = NULL ;
F_30 ( V_16 ) ;
F_23 ( V_17 -> V_31 ,
V_16 -> V_60 ,
V_16 -> V_23 ,
V_16 -> V_54 ) ;
F_24 ( V_16 ) ;
}
}
static inline void F_29 ( struct V_17 * V_17 )
{
}
static inline void F_25 ( struct V_17 * V_17 )
{
}
static inline int F_8 ( struct V_17 * V_31 )
{
return 0 ;
}
static void F_31 ( struct V_17 * V_17 ,
struct V_16 * V_16 )
{
T_2 * V_71 ;
int V_65 , V_72 , V_73 ;
T_3 V_74 ;
if ( V_16 -> V_20 != 0 ) {
if ( V_16 -> V_20 == - V_29 )
return;
#ifdef F_32
if ( V_17 -> V_75 )
return;
#endif
F_2 ( V_25 | V_76 , L_11 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
goto V_77;
}
V_74 = V_17 -> V_21 -> V_74 ;
for ( V_65 = 0 ; V_65 < V_16 -> V_78 ; V_65 ++ ) {
V_72 = V_16 -> V_79 [ V_65 ] . V_24 ;
V_73 = V_16 -> V_79 [ V_65 ] . V_20 ;
if ( V_73 ) {
F_7 ( L_12 ,
V_65 , V_72 , V_73 ) ;
V_17 -> V_80 = V_81 ;
continue;
}
if ( V_72 == 0 ) {
if ( V_17 -> V_82 == 0 )
V_17 -> V_82 = 1 ;
continue;
}
F_2 ( V_76 , L_13 ,
V_65 , V_16 -> V_79 [ V_65 ] . V_83 , V_72 ) ;
V_71 = ( T_2 * ) V_16 -> V_23
+ V_16 -> V_79 [ V_65 ] . V_83 ;
V_74 ( V_17 , V_71 , V_72 ) ;
}
V_77:
V_73 = F_6 ( V_16 , V_30 ) ;
if ( V_73 < 0 )
F_7 ( L_14 , V_73 ) ;
}
static void F_33 ( struct V_16 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
F_2 ( V_76 , L_15 ) ;
if ( ! V_17 -> V_84 )
return;
F_31 ( V_17 , V_16 ) ;
}
static void F_34 ( struct V_16 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
int V_73 ;
F_2 ( V_76 , L_16 ) ;
if ( ! V_17 -> V_84 )
return;
switch ( V_16 -> V_20 ) {
case 0 :
break;
case - V_29 :
return;
default:
#ifdef F_32
if ( V_17 -> V_75 )
return;
#endif
F_2 ( V_25 | V_76 , L_11 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
goto V_77;
}
F_2 ( V_76 , L_17 , V_16 -> V_24 ) ;
V_17 -> V_21 -> V_74 ( V_17 ,
V_16 -> V_23 ,
V_16 -> V_24 ) ;
V_77:
if ( V_17 -> V_85 . V_86 != 0 ) {
V_73 = F_6 ( V_16 , V_30 ) ;
if ( V_73 < 0 )
F_7 ( L_14 , V_73 ) ;
}
}
void F_35 ( struct V_17 * V_17 ,
enum V_87 V_88 ,
const T_2 * V_71 ,
int V_72 )
{
struct V_9 * V_10 ;
int V_65 , V_89 ;
F_2 ( V_76 , L_18 , V_88 , V_72 ) ;
if ( V_88 == V_90 ) {
V_65 = F_36 ( & V_17 -> V_91 ) ;
if ( V_65 == F_36 ( & V_17 -> V_92 ) ) {
V_17 -> V_80 = V_81 ;
V_17 -> V_93 ++ ;
return;
}
V_89 = V_17 -> V_94 [ V_65 ] ;
V_10 = & V_17 -> V_10 [ V_89 ] ;
V_10 -> V_13 . V_95 = F_37 ( F_38 () ) ;
V_10 -> V_13 . V_93 = V_17 -> V_93 ++ ;
V_17 -> V_96 = V_10 -> V_71 ;
V_17 -> V_97 = 0 ;
} else {
switch ( V_17 -> V_80 ) {
case V_81 :
if ( V_88 == V_98 )
V_17 -> V_80 = V_88 ;
return;
case V_98 :
return;
}
}
if ( V_72 > 0 ) {
if ( V_17 -> V_97 + V_72 > V_17 -> V_99 ) {
F_2 ( V_25 | V_76 , L_19 ,
V_17 -> V_97 + V_72 ,
V_17 -> V_99 ) ;
V_88 = V_81 ;
} else {
memcpy ( V_17 -> V_96 + V_17 -> V_97 ,
V_71 , V_72 ) ;
V_17 -> V_97 += V_72 ;
}
}
V_17 -> V_80 = V_88 ;
if ( V_88 == V_98 ) {
V_65 = F_36 ( & V_17 -> V_91 ) ;
V_89 = V_17 -> V_94 [ V_65 ] ;
V_10 = & V_17 -> V_10 [ V_89 ] ;
V_10 -> V_13 . V_100 = V_17 -> V_97 ;
V_10 -> V_13 . V_14 = ( V_10 -> V_13 . V_14
| V_101 )
& ~ V_102 ;
V_65 = ( V_65 + 1 ) % V_103 ;
F_39 ( & V_17 -> V_91 , V_65 ) ;
F_40 ( & V_17 -> V_104 ) ;
F_2 ( V_105 , L_20 ,
V_10 -> V_13 . V_100 ) ;
V_17 -> V_96 = NULL ;
V_17 -> V_97 = 0 ;
}
}
static int F_41 ( T_1 V_106 )
{
switch ( V_106 ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_17 * V_17 , struct V_112 * V_112 ,
enum V_113 V_114 , unsigned int V_115 )
{
struct V_9 * V_10 ;
unsigned int V_99 ;
int V_65 ;
V_65 = V_17 -> V_116 ;
V_99 = V_17 -> V_85 . V_117 [ V_65 ] . V_118 ;
F_2 ( V_6 , L_21 , V_99 ) ;
V_99 = F_43 ( V_99 ) ;
if ( V_115 >= V_103 )
V_115 = V_103 - 1 ;
V_17 -> V_119 = F_44 ( V_99 * V_115 ) ;
if ( ! V_17 -> V_119 ) {
F_7 ( L_22 ) ;
return - V_34 ;
}
V_17 -> V_120 = V_112 ;
V_17 -> V_114 = V_114 ;
V_17 -> V_99 = V_99 ;
V_17 -> V_121 = V_115 ;
for ( V_65 = 0 ; V_65 < V_115 ; V_65 ++ ) {
V_10 = & V_17 -> V_10 [ V_65 ] ;
V_10 -> V_13 . V_122 = V_65 ;
V_10 -> V_13 . type = V_123 ;
V_10 -> V_13 . V_14 = 0 ;
V_10 -> V_13 . V_124 = V_125 ;
V_10 -> V_13 . V_126 = V_99 ;
V_10 -> V_13 . V_114 = V_114 ;
V_10 -> V_13 . V_93 = 0 ;
V_10 -> V_71 = V_17 -> V_119 + V_65 * V_99 ;
V_10 -> V_13 . V_127 . V_83 = V_65 * V_99 ;
}
F_39 ( & V_17 -> V_92 , 0 ) ;
F_39 ( & V_17 -> V_91 , 0 ) ;
V_17 -> V_128 = 0 ;
return 0 ;
}
static void F_45 ( struct V_17 * V_17 )
{
int V_65 ;
F_2 ( V_6 , L_23 ) ;
if ( V_17 -> V_119 != NULL ) {
F_46 ( V_17 -> V_119 ) ;
V_17 -> V_119 = NULL ;
for ( V_65 = 0 ; V_65 < V_17 -> V_121 ; V_65 ++ )
V_17 -> V_10 [ V_65 ] . V_71 = NULL ;
}
V_17 -> V_121 = 0 ;
V_17 -> V_99 = 0 ;
V_17 -> V_120 = NULL ;
V_17 -> V_114 = V_129 ;
}
static void F_47 ( struct V_17 * V_17 )
{
struct V_16 * V_16 ;
unsigned int V_65 ;
F_2 ( V_6 , L_24 ) ;
for ( V_65 = 0 ; V_65 < V_130 ; V_65 ++ ) {
V_16 = V_17 -> V_16 [ V_65 ] ;
if ( V_16 == NULL )
break;
V_17 -> V_16 [ V_65 ] = NULL ;
F_30 ( V_16 ) ;
if ( V_16 -> V_23 != NULL )
F_23 ( V_17 -> V_31 ,
V_16 -> V_60 ,
V_16 -> V_23 ,
V_16 -> V_54 ) ;
F_24 ( V_16 ) ;
}
}
static int F_48 ( struct V_17 * V_17 )
{
int V_19 ;
if ( V_17 -> V_131 == 0 )
return 0 ;
V_19 = F_49 ( V_17 -> V_31 , V_17 -> V_66 , 0 ) ;
if ( V_19 < 0 )
F_7 ( L_25 , V_19 ) ;
return V_19 ;
}
static void F_50 ( struct V_17 * V_17 )
{
V_17 -> V_84 = 0 ;
if ( V_17 -> V_132 ) {
if ( V_17 -> V_21 -> V_133 )
V_17 -> V_21 -> V_133 ( V_17 ) ;
F_47 ( V_17 ) ;
F_29 ( V_17 ) ;
F_48 ( V_17 ) ;
F_25 ( V_17 ) ;
}
if ( V_17 -> V_21 -> V_134 )
V_17 -> V_21 -> V_134 ( V_17 ) ;
F_2 ( V_6 , L_26 ) ;
}
static struct V_135 * F_51 ( struct V_63 * V_131 ,
int V_136 )
{
struct V_135 * V_44 ;
int V_65 , V_137 ;
for ( V_65 = 0 ; V_65 < V_131 -> V_68 . V_69 ; V_65 ++ ) {
V_44 = & V_131 -> V_70 [ V_65 ] ;
V_137 = V_44 -> V_68 . V_138 & V_139 ;
if ( V_137 == V_136
&& V_44 -> V_68 . V_50 != 0
&& F_27 ( & V_44 -> V_68 ) )
return V_44 ;
}
return NULL ;
}
static struct V_135 * F_52 ( struct V_17 * V_17 )
{
struct V_61 * V_62 ;
struct V_135 * V_44 ;
int V_136 , V_65 , V_19 ;
V_62 = F_26 ( V_17 -> V_31 , V_17 -> V_66 ) ;
V_44 = NULL ;
V_136 = V_17 -> V_85 . V_140 ? V_141
: V_142 ;
V_65 = V_17 -> V_131 ;
if ( V_17 -> V_85 . V_143 ) {
while ( ++ V_65 < V_17 -> V_144 ) {
V_44 = F_51 ( & V_62 -> V_145 [ V_65 ] , V_136 ) ;
if ( V_44 )
break;
}
} else {
while ( -- V_65 >= 0 ) {
V_44 = F_51 ( & V_62 -> V_145 [ V_65 ] , V_136 ) ;
if ( V_44 )
break;
}
}
if ( V_44 == NULL ) {
F_7 ( L_27 ) ;
return NULL ;
}
F_2 ( V_6 , L_28 ,
V_65 , V_44 -> V_68 . V_52 ) ;
V_17 -> V_131 = V_65 ;
if ( V_17 -> V_144 > 1 ) {
V_19 = F_49 ( V_17 -> V_31 , V_17 -> V_66 , V_65 ) ;
if ( V_19 < 0 ) {
F_7 ( L_29 , V_65 , V_19 ) ;
V_44 = NULL ;
}
}
return V_44 ;
}
static int F_53 ( struct V_17 * V_17 ,
struct V_135 * V_44 )
{
struct V_16 * V_16 ;
int V_146 , V_147 , V_65 , V_148 , V_149 , V_150 ;
V_148 = F_18 ( V_44 -> V_68 . V_50 ) ;
if ( ! V_17 -> V_85 . V_140 ) {
if ( V_17 -> V_151 == 0 )
V_148 = ( V_148 & 0x07ff ) * ( 1 + ( ( V_148 >> 11 ) & 3 ) ) ;
else
V_148 = V_17 -> V_151 ;
V_149 = V_17 -> V_85 . V_149 ;
if ( V_149 == 0 )
V_149 = 32 ;
V_150 = V_148 * V_149 ;
F_2 ( V_6 ,
L_30 ,
V_149 , V_148 , V_150 ) ;
V_147 = V_152 ;
} else {
V_149 = 0 ;
V_150 = V_17 -> V_85 . V_153 ;
if ( V_150 == 0 )
V_150 = V_148 ;
F_2 ( V_6 , L_31 , V_150 ) ;
if ( V_17 -> V_85 . V_86 != 0 )
V_147 = V_17 -> V_85 . V_86 ;
else
V_147 = 1 ;
}
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
V_16 = F_19 ( V_149 , V_53 ) ;
if ( ! V_16 ) {
F_7 ( L_32 ) ;
return - V_34 ;
}
V_17 -> V_16 [ V_146 ] = V_16 ;
V_16 -> V_23 = F_20 ( V_17 -> V_31 ,
V_150 ,
V_53 ,
& V_16 -> V_54 ) ;
if ( V_16 -> V_23 == NULL ) {
F_7 ( L_33 ) ;
return - V_34 ;
}
V_16 -> V_31 = V_17 -> V_31 ;
V_16 -> V_18 = V_17 ;
V_16 -> V_60 = V_150 ;
if ( V_149 != 0 ) {
V_16 -> V_154 = F_54 ( V_17 -> V_31 ,
V_44 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_155
| V_57 ;
V_16 -> V_46 = V_44 -> V_68 . V_51 ;
V_16 -> V_156 = F_33 ;
V_16 -> V_78 = V_149 ;
for ( V_65 = 0 ; V_65 < V_149 ; V_65 ++ ) {
V_16 -> V_79 [ V_65 ] . V_126 = V_148 ;
V_16 -> V_79 [ V_65 ] . V_83 = V_148 * V_65 ;
}
} else {
V_16 -> V_154 = F_55 ( V_17 -> V_31 ,
V_44 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_57 ;
V_16 -> V_156 = F_34 ;
}
}
return 0 ;
}
static int F_56 ( struct V_17 * V_17 )
{
struct V_135 * V_44 ;
struct V_16 * V_16 ;
int V_146 , V_19 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( ! V_17 -> V_132 ) {
V_19 = - V_28 ;
goto V_159;
}
V_17 -> V_96 = NULL ;
V_17 -> V_97 = 0 ;
V_17 -> V_80 = V_81 ;
V_17 -> V_93 = 0 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_85 . V_143 )
V_17 -> V_131 = 0 ;
else
V_17 -> V_131 = V_17 -> V_144 ;
if ( V_17 -> V_21 -> V_161 ) {
V_19 = V_17 -> V_21 -> V_161 ( V_17 ) ;
if ( V_19 < 0 )
goto V_159;
}
F_29 ( V_17 ) ;
V_44 = F_52 ( V_17 ) ;
if ( V_44 == NULL ) {
V_19 = - V_162 ;
goto V_163;
}
for (; ; ) {
if ( ! V_17 -> V_85 . V_164 ) {
F_2 ( V_6 , L_34 ,
V_17 -> V_131 ) ;
V_19 = F_53 ( V_17 , V_44 ) ;
if ( V_19 < 0 ) {
F_47 ( V_17 ) ;
goto V_163;
}
}
if ( V_17 -> V_85 . V_140 )
F_58 ( V_17 -> V_31 ,
V_17 -> V_16 [ 0 ] -> V_154 ) ;
V_19 = V_17 -> V_21 -> V_165 ( V_17 ) ;
if ( V_19 < 0 ) {
F_47 ( V_17 ) ;
goto V_163;
}
V_17 -> V_84 = 1 ;
if ( V_17 -> V_85 . V_140 && V_17 -> V_85 . V_86 == 0 )
break;
for ( V_146 = 0 ; V_146 < V_130 ; V_146 ++ ) {
V_16 = V_17 -> V_16 [ V_146 ] ;
if ( V_16 == NULL )
break;
V_19 = F_6 ( V_16 , V_53 ) ;
if ( V_19 < 0 )
break;
}
if ( V_19 >= 0 )
break;
F_50 ( V_17 ) ;
if ( V_19 != - V_166 ) {
F_7 ( L_35 ,
V_17 -> V_131 , V_19 ) ;
goto V_163;
}
F_2 ( V_25 | V_6 ,
L_36 ) ;
F_59 ( 20 ) ;
if ( V_17 -> V_21 -> V_167 ) {
V_19 = V_17 -> V_21 -> V_167 ( V_17 ) ;
if ( V_19 < 0 )
goto V_163;
} else {
V_44 = F_52 ( V_17 ) ;
if ( V_44 == NULL ) {
V_19 = - V_162 ;
goto V_163;
}
}
}
V_163:
F_25 ( V_17 ) ;
V_159:
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static void F_61 ( struct V_17 * V_17 )
{
struct V_168 * V_169 ;
int V_65 ;
V_65 = V_17 -> V_85 . V_170 - 1 ;
V_17 -> V_116 = V_65 ;
V_17 -> V_171 = V_17 -> V_85 . V_117 [ V_65 ] . V_171 ;
V_17 -> V_172 = V_17 -> V_85 . V_117 [ V_65 ] . V_172 ;
V_17 -> V_2 = V_17 -> V_85 . V_117 [ V_65 ] . V_173 ;
V_169 = V_17 -> V_85 . V_174 ;
if ( V_169 != NULL ) {
for ( V_65 = 0 ;
V_65 < V_17 -> V_21 -> V_175 ;
V_65 ++ , V_169 ++ )
V_169 -> V_176 = V_169 -> V_177 ;
}
}
static int F_62 ( struct V_17 * V_17 ,
int V_171 , int V_172 )
{
int V_65 ;
for ( V_65 = V_17 -> V_85 . V_170 ; -- V_65 > 0 ; ) {
if ( V_171 >= V_17 -> V_85 . V_117 [ V_65 ] . V_171
&& V_172 >= V_17 -> V_85 . V_117 [ V_65 ] . V_172 )
break;
}
return V_65 ;
}
static int F_63 ( struct V_17 * V_17 ,
int V_178 ,
int V_2 )
{
int V_179 , V_180 ;
V_179 = V_180 = V_178 ;
while ( ( V_179 < V_17 -> V_85 . V_170 ) || V_180 >= 0 ) {
if ( -- V_180 >= 0 ) {
if ( V_17 -> V_85 . V_117 [ V_180 ] . V_173
== V_2 )
return V_180 ;
}
if ( ++ V_179 < V_17 -> V_85 . V_170 ) {
if ( V_17 -> V_85 . V_117 [ V_179 ] . V_173
== V_2 )
return V_179 ;
}
}
return - V_49 ;
}
static int F_64 ( struct V_112 * V_112 , void * V_181 ,
struct V_182 * V_183 )
{
int V_19 ;
struct V_17 * V_17 = V_181 ;
if ( ! V_17 -> V_21 -> V_184 )
return - V_49 ;
if ( ! V_17 -> V_21 -> V_185 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_19 = V_17 -> V_21 -> V_185 ( V_17 , V_183 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_65 ( struct V_112 * V_112 , void * V_181 ,
struct V_182 * V_183 )
{
int V_19 ;
struct V_17 * V_17 = V_181 ;
if ( ! V_17 -> V_21 -> V_184 )
return - V_49 ;
if ( ! V_17 -> V_21 -> V_186 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_19 = V_17 -> V_21 -> V_186 ( V_17 , V_183 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_66 ( struct V_112 * V_112 , void * V_181 ,
struct V_187 * V_188 )
{
int V_19 ;
struct V_17 * V_17 = V_181 ;
if ( ! V_17 -> V_21 -> V_184 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_19 = V_17 -> V_21 -> V_184 ( V_17 , V_188 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_67 ( struct V_112 * V_112 , void * V_181 ,
struct V_189 * V_190 )
{
struct V_17 * V_17 = V_181 ;
int V_65 , V_89 , V_122 ;
T_1 V_191 [ 8 ] ;
V_122 = 0 ;
V_89 = 0 ;
for ( V_65 = V_17 -> V_85 . V_170 ; -- V_65 >= 0 ; ) {
V_191 [ V_122 ] = V_17 -> V_85 . V_117 [ V_65 ] . V_173 ;
V_89 = 0 ;
for (; ; ) {
if ( V_191 [ V_89 ] == V_191 [ V_122 ] )
break;
V_89 ++ ;
}
if ( V_89 == V_122 ) {
if ( V_190 -> V_122 == V_122 )
break;
V_122 ++ ;
if ( V_122 >= F_68 ( V_191 ) )
return - V_49 ;
}
}
if ( V_65 < 0 )
return - V_49 ;
V_190 -> V_173 = V_191 [ V_122 ] ;
if ( F_41 ( V_191 [ V_122 ] ) )
V_190 -> V_14 = V_192 ;
V_190 -> V_193 [ 0 ] = V_190 -> V_173 & 0xff ;
V_190 -> V_193 [ 1 ] = ( V_190 -> V_173 >> 8 ) & 0xff ;
V_190 -> V_193 [ 2 ] = ( V_190 -> V_173 >> 16 ) & 0xff ;
V_190 -> V_193 [ 3 ] = V_190 -> V_173 >> 24 ;
V_190 -> V_193 [ 4 ] = '\0' ;
return 0 ;
}
static int F_69 ( struct V_112 * V_112 , void * V_181 ,
struct V_194 * V_195 )
{
struct V_17 * V_17 = V_181 ;
int V_178 ;
V_178 = V_17 -> V_116 ;
memcpy ( & V_195 -> V_195 . V_196 , & V_17 -> V_85 . V_117 [ V_178 ] ,
sizeof V_195 -> V_195 . V_196 ) ;
return 0 ;
}
static int F_70 ( struct V_17 * V_17 ,
struct V_194 * V_195 )
{
int V_3 , V_4 , V_178 , V_197 ;
V_3 = V_195 -> V_195 . V_196 . V_171 ;
V_4 = V_195 -> V_195 . V_196 . V_172 ;
#ifdef F_71
if ( V_198 & V_5 )
F_1 ( L_37 , V_195 -> V_195 . V_196 . V_173 , V_3 , V_4 ) ;
#endif
V_178 = F_62 ( V_17 , V_3 , V_4 ) ;
if ( V_17 -> V_85 . V_117 [ V_178 ] . V_173
!= V_195 -> V_195 . V_196 . V_173 ) {
V_197 = F_63 ( V_17 , V_178 ,
V_195 -> V_195 . V_196 . V_173 ) ;
if ( V_197 >= 0 )
V_178 = V_197 ;
}
memcpy ( & V_195 -> V_195 . V_196 , & V_17 -> V_85 . V_117 [ V_178 ] ,
sizeof V_195 -> V_195 . V_196 ) ;
return V_178 ;
}
static int F_72 ( struct V_112 * V_112 ,
void * V_181 ,
struct V_194 * V_195 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
V_19 = F_70 ( V_17 , V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_73 ( struct V_112 * V_112 , void * V_181 ,
struct V_194 * V_195 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
V_19 = F_70 ( V_17 , V_195 ) ;
if ( V_19 < 0 )
goto V_163;
if ( V_17 -> V_121 != 0
&& V_195 -> V_195 . V_196 . V_118 > V_17 -> V_99 ) {
V_19 = - V_49 ;
goto V_163;
}
if ( V_19 == V_17 -> V_116 ) {
V_19 = 0 ;
goto V_163;
}
if ( V_17 -> V_84 ) {
V_19 = - V_200 ;
goto V_163;
}
V_17 -> V_171 = V_195 -> V_195 . V_196 . V_171 ;
V_17 -> V_172 = V_195 -> V_195 . V_196 . V_172 ;
V_17 -> V_2 = V_195 -> V_195 . V_196 . V_173 ;
V_17 -> V_116 = V_19 ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_74 ( struct V_112 * V_112 , void * V_181 ,
struct V_201 * V_202 )
{
struct V_17 * V_17 = V_181 ;
int V_65 ;
T_1 V_122 = 0 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_85 . V_170 ; V_65 ++ ) {
if ( V_202 -> V_203 !=
V_17 -> V_85 . V_117 [ V_65 ] . V_173 )
continue;
if ( V_202 -> V_122 == V_122 ) {
V_202 -> type = V_204 ;
V_202 -> V_205 . V_171 =
V_17 -> V_85 . V_117 [ V_65 ] . V_171 ;
V_202 -> V_205 . V_172 =
V_17 -> V_85 . V_117 [ V_65 ] . V_172 ;
return 0 ;
}
V_122 ++ ;
}
return - V_49 ;
}
static int F_75 ( struct V_112 * V_206 , void * V_181 ,
struct V_207 * V_208 )
{
struct V_17 * V_17 = V_181 ;
int V_178 = F_62 ( V_17 , V_208 -> V_171 , V_208 -> V_172 ) ;
T_1 V_65 ;
if ( V_17 -> V_85 . V_209 == NULL ||
V_17 -> V_85 . V_209 [ V_178 ] . V_210 == 0 )
return - V_49 ;
if ( V_208 -> V_203 !=
V_17 -> V_85 . V_117 [ V_178 ] . V_173 )
return - V_49 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_85 . V_209 [ V_178 ] . V_210 ; V_65 ++ ) {
if ( V_208 -> V_122 == V_65 ) {
V_208 -> type = V_204 ;
V_208 -> V_205 . V_211 = 1 ;
V_208 -> V_205 . V_212 =
V_17 -> V_85 . V_209 [ V_178 ] . V_213 [ V_65 ] ;
return 0 ;
}
}
return - V_49 ;
}
static void F_76 ( struct V_214 * V_215 )
{
struct V_17 * V_17 = F_77 ( V_215 , struct V_17 , V_216 ) ;
F_2 ( V_217 , L_38 ,
F_78 ( & V_17 -> V_216 ) ) ;
F_79 ( V_17 -> V_218 ) ;
F_79 ( V_17 ) ;
}
static int F_80 ( struct V_112 * V_112 )
{
struct V_17 * V_17 ;
F_2 ( V_6 , L_39 , V_219 -> V_220 ) ;
V_17 = (struct V_17 * ) F_81 ( V_112 ) ;
if ( ! V_17 -> V_132 )
return - V_28 ;
if ( ! F_82 ( V_17 -> V_221 ) )
return - V_28 ;
V_112 -> V_222 = V_17 ;
#ifdef F_71
if ( V_198 & V_223 )
V_17 -> V_216 . V_224 |= V_225
| V_226 ;
else
V_17 -> V_216 . V_224 &= ~ ( V_225
| V_226 ) ;
#endif
return 0 ;
}
static int F_83 ( struct V_112 * V_112 )
{
struct V_17 * V_17 = V_112 -> V_222 ;
F_2 ( V_6 , L_40 , V_219 -> V_220 ) ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
if ( V_17 -> V_120 == V_112 ) {
if ( V_17 -> V_84 ) {
F_84 ( & V_17 -> V_157 ) ;
V_17 -> V_160 = 0 ;
F_50 ( V_17 ) ;
F_60 ( & V_17 -> V_157 ) ;
}
F_45 ( V_17 ) ;
}
V_112 -> V_222 = NULL ;
F_85 ( V_17 -> V_221 ) ;
F_60 ( & V_17 -> V_199 ) ;
F_2 ( V_6 , L_41 ) ;
return 0 ;
}
static int F_86 ( struct V_112 * V_112 , void * V_181 ,
struct V_227 * V_228 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( ! V_17 -> V_132 ) {
V_19 = - V_28 ;
goto V_163;
}
strncpy ( ( char * ) V_228 -> V_229 , V_17 -> V_21 -> V_36 ,
sizeof V_228 -> V_229 ) ;
if ( V_17 -> V_31 -> V_230 != NULL ) {
strncpy ( ( char * ) V_228 -> V_231 , V_17 -> V_31 -> V_230 ,
sizeof V_228 -> V_231 ) ;
} else {
snprintf ( ( char * ) V_228 -> V_231 , sizeof V_228 -> V_231 ,
L_42 ,
F_18 ( V_17 -> V_31 -> V_232 . V_233 ) ,
F_18 ( V_17 -> V_31 -> V_232 . V_234 ) ) ;
}
F_10 ( V_17 -> V_31 , ( char * ) V_228 -> V_235 ,
sizeof( V_228 -> V_235 ) ) ;
V_228 -> V_236 = V_237 ;
V_228 -> V_238 = V_239
| V_240
| V_241 ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_87 ( struct V_17 * V_17 ,
int V_37 )
{
const struct V_169 * V_174 ;
int V_65 ;
for ( V_65 = 0 , V_174 = V_17 -> V_21 -> V_174 ;
V_65 < V_17 -> V_21 -> V_175 ;
V_65 ++ , V_174 ++ ) {
if ( V_17 -> V_242 & ( 1 << V_65 ) )
continue;
if ( V_37 == V_174 -> V_243 . V_37 )
return V_65 ;
}
return - 1 ;
}
static int F_88 ( struct V_112 * V_112 , void * V_181 ,
struct V_244 * V_245 )
{
struct V_17 * V_17 = V_181 ;
const struct V_169 * V_174 ;
struct V_168 * V_168 ;
int V_65 , V_246 ;
T_4 V_37 ;
V_37 = V_245 -> V_37 ;
if ( V_37 & V_247 ) {
V_37 &= V_248 ;
V_37 ++ ;
V_246 = - 1 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_21 -> V_175 ; V_65 ++ ) {
if ( V_17 -> V_242 & ( 1 << V_65 ) )
continue;
if ( V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_37 < V_37 )
continue;
if ( V_246 >= 0
&& V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_37
> V_17 -> V_21 -> V_174 [ V_246 ] . V_243 . V_37 )
continue;
V_246 = V_65 ;
}
} else {
V_246 = F_87 ( V_17 , V_37 ) ;
}
if ( V_246 < 0 )
return - V_49 ;
V_174 = & V_17 -> V_21 -> V_174 [ V_246 ] ;
memcpy ( V_245 , & V_174 -> V_243 , sizeof *V_245 ) ;
if ( V_17 -> V_85 . V_174 != NULL ) {
V_168 = & V_17 -> V_85 . V_174 [ V_246 ] ;
V_245 -> V_249 = V_168 -> V_177 ;
V_245 -> V_250 = V_168 -> V_251 ;
V_245 -> V_252 = V_168 -> V_253 ;
}
if ( V_17 -> V_254 & ( 1 << V_246 ) )
V_245 -> V_14 |= V_255 ;
return 0 ;
}
static int F_89 ( struct V_112 * V_112 , void * V_181 ,
struct V_256 * V_169 )
{
struct V_17 * V_17 = V_181 ;
const struct V_169 * V_174 ;
struct V_168 * V_168 ;
int V_246 , V_19 ;
V_246 = F_87 ( V_17 , V_169 -> V_37 ) ;
if ( V_246 < 0 )
return - V_49 ;
if ( V_17 -> V_254 & ( 1 << V_246 ) )
return - V_49 ;
V_174 = & V_17 -> V_21 -> V_174 [ V_246 ] ;
if ( V_17 -> V_85 . V_174 != NULL ) {
V_168 = & V_17 -> V_85 . V_174 [ V_246 ] ;
if ( V_169 -> V_257 < V_168 -> V_251
|| V_169 -> V_257 > V_168 -> V_253 )
return - V_258 ;
} else {
V_168 = NULL ;
if ( V_169 -> V_257 < V_174 -> V_243 . V_250
|| V_169 -> V_257 > V_174 -> V_243 . V_252 )
return - V_258 ;
}
F_2 ( V_5 , L_43 , V_169 -> V_37 , V_169 -> V_257 ) ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( ! V_17 -> V_132 ) {
V_19 = - V_28 ;
goto V_163;
}
V_17 -> V_160 = 0 ;
if ( V_174 -> V_259 != NULL ) {
V_19 = V_174 -> V_259 ( V_17 , V_169 -> V_257 ) ;
goto V_163;
}
if ( V_168 != NULL ) {
V_168 -> V_176 = V_169 -> V_257 ;
if ( V_174 -> V_260 != NULL
&& V_17 -> V_84 )
V_174 -> V_260 ( V_17 ) ;
}
V_19 = V_17 -> V_160 ;
V_163:
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_90 ( struct V_112 * V_112 , void * V_181 ,
struct V_256 * V_169 )
{
struct V_17 * V_17 = V_181 ;
const struct V_169 * V_174 ;
int V_246 , V_19 ;
V_246 = F_87 ( V_17 , V_169 -> V_37 ) ;
if ( V_246 < 0 )
return - V_49 ;
V_174 = & V_17 -> V_21 -> V_174 [ V_246 ] ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( ! V_17 -> V_132 ) {
V_19 = - V_28 ;
goto V_163;
}
V_17 -> V_160 = 0 ;
if ( V_174 -> V_261 != NULL ) {
V_19 = V_174 -> V_261 ( V_17 , & V_169 -> V_257 ) ;
goto V_163;
}
if ( V_17 -> V_85 . V_174 != NULL )
V_169 -> V_257 = V_17 -> V_85 . V_174 [ V_246 ] . V_176 ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_91 ( struct V_112 * V_112 , void * V_181 ,
struct V_262 * V_263 )
{
struct V_17 * V_17 = V_181 ;
if ( ! V_17 -> V_21 -> V_264 )
return - V_49 ;
return V_17 -> V_21 -> V_264 ( V_17 , V_263 ) ;
}
static int F_92 ( struct V_112 * V_112 , void * V_181 ,
struct V_265 * V_266 )
{
struct V_17 * V_17 = V_181 ;
if ( V_266 -> V_122 != 0 )
return - V_49 ;
V_266 -> type = V_267 ;
V_266 -> V_20 = V_17 -> V_85 . V_268 ;
strncpy ( V_266 -> V_36 , V_17 -> V_21 -> V_36 ,
sizeof V_266 -> V_36 ) ;
return 0 ;
}
static int F_93 ( struct V_112 * V_112 , void * V_181 , unsigned int * V_65 )
{
* V_65 = 0 ;
return 0 ;
}
static int F_94 ( struct V_112 * V_112 , void * V_181 , unsigned int V_65 )
{
if ( V_65 > 0 )
return - V_49 ;
return ( 0 ) ;
}
static int F_95 ( struct V_112 * V_112 , void * V_181 ,
struct V_269 * V_270 )
{
struct V_17 * V_17 = V_181 ;
int V_65 , V_19 = 0 , V_84 ;
V_65 = V_270 -> V_114 ;
switch ( V_65 ) {
case V_271 :
case V_272 :
case V_273 :
break;
default:
return - V_49 ;
}
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
if ( V_17 -> V_114 != V_129
&& V_17 -> V_114 != V_271
&& V_17 -> V_114 != V_270 -> V_114 ) {
V_19 = - V_200 ;
goto V_163;
}
if ( V_17 -> V_120 != NULL
&& V_17 -> V_120 != V_112 ) {
V_19 = - V_200 ;
goto V_163;
}
for ( V_65 = 0 ; V_65 < V_17 -> V_121 ; V_65 ++ ) {
if ( V_17 -> V_10 [ V_65 ] . V_12 ) {
V_19 = - V_200 ;
goto V_163;
}
}
V_84 = V_17 -> V_84 ;
if ( V_84 ) {
F_84 ( & V_17 -> V_157 ) ;
V_17 -> V_160 = 0 ;
F_50 ( V_17 ) ;
F_60 ( & V_17 -> V_157 ) ;
if ( V_17 -> V_114 == V_271 )
V_84 = 0 ;
}
if ( V_17 -> V_121 != 0 )
F_45 ( V_17 ) ;
if ( V_270 -> V_115 == 0 )
goto V_163;
V_19 = F_42 ( V_17 , V_112 , V_270 -> V_114 , V_270 -> V_115 ) ;
if ( V_19 == 0 ) {
V_270 -> V_115 = V_17 -> V_121 ;
if ( V_84 )
V_19 = F_56 ( V_17 ) ;
}
V_163:
F_60 ( & V_17 -> V_199 ) ;
F_2 ( V_6 , L_44 , V_19 , V_270 -> V_115 ) ;
return V_19 ;
}
static int F_96 ( struct V_112 * V_112 , void * V_181 ,
struct V_274 * V_13 )
{
struct V_17 * V_17 = V_181 ;
struct V_9 * V_10 ;
if ( V_13 -> V_122 < 0
|| V_13 -> V_122 >= V_17 -> V_121 )
return - V_49 ;
V_10 = & V_17 -> V_10 [ V_13 -> V_122 ] ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
return 0 ;
}
static int F_97 ( struct V_112 * V_112 , void * V_181 ,
enum V_275 V_276 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( V_276 != V_123 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
if ( V_17 -> V_120 != V_112 ) {
V_19 = - V_200 ;
goto V_163;
}
if ( V_17 -> V_121 == 0
|| ! ( V_17 -> V_10 [ 0 ] . V_13 . V_14 & V_102 ) ) {
V_19 = - V_49 ;
goto V_163;
}
if ( ! V_17 -> V_84 ) {
V_19 = F_56 ( V_17 ) ;
if ( V_19 < 0 )
goto V_163;
}
#ifdef F_71
if ( V_198 & V_6 ) {
F_1 ( L_45 ,
V_17 -> V_2 ,
V_17 -> V_171 ,
V_17 -> V_172 ) ;
}
#endif
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_98 ( struct V_112 * V_112 , void * V_181 ,
enum V_275 V_276 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( V_276 != V_123 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
if ( ! V_17 -> V_84 ) {
V_19 = 0 ;
goto V_163;
}
if ( V_17 -> V_120 != V_112 ) {
V_19 = - V_200 ;
goto V_163;
}
if ( F_57 ( & V_17 -> V_157 ) ) {
V_19 = - V_158 ;
goto V_163;
}
V_17 -> V_160 = 0 ;
F_50 ( V_17 ) ;
F_60 ( & V_17 -> V_157 ) ;
F_40 ( & V_17 -> V_104 ) ;
F_39 ( & V_17 -> V_92 , 0 ) ;
F_39 ( & V_17 -> V_91 , 0 ) ;
V_17 -> V_128 = 0 ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_99 ( struct V_112 * V_112 , void * V_181 ,
struct V_277 * V_278 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( ! V_17 -> V_21 -> V_279 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_19 = V_17 -> V_21 -> V_279 ( V_17 , V_278 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_100 ( struct V_112 * V_112 , void * V_181 ,
struct V_277 * V_278 )
{
struct V_17 * V_17 = V_181 ;
int V_19 ;
if ( ! V_17 -> V_21 -> V_280 )
return - V_49 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_19 = V_17 -> V_21 -> V_280 ( V_17 , V_278 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
static int F_101 ( struct V_112 * V_206 , void * V_181 ,
struct V_281 * V_282 )
{
struct V_17 * V_17 = V_181 ;
V_282 -> V_282 . V_283 . V_284 = V_17 -> V_285 ;
if ( V_17 -> V_21 -> V_286 ) {
int V_19 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( V_17 -> V_132 ) {
V_17 -> V_160 = 0 ;
V_17 -> V_21 -> V_286 ( V_17 , V_282 ) ;
V_19 = V_17 -> V_160 ;
} else {
V_19 = - V_28 ;
}
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
return 0 ;
}
static int F_102 ( struct V_112 * V_206 , void * V_181 ,
struct V_281 * V_282 )
{
struct V_17 * V_17 = V_181 ;
int V_146 ;
V_146 = V_282 -> V_282 . V_283 . V_284 ;
if ( V_146 == 0 || V_146 >= V_103 )
V_282 -> V_282 . V_283 . V_284 = V_17 -> V_285 ;
else
V_17 -> V_285 = V_146 ;
if ( V_17 -> V_21 -> V_287 ) {
int V_19 ;
if ( F_57 ( & V_17 -> V_157 ) )
return - V_158 ;
if ( V_17 -> V_132 ) {
V_17 -> V_160 = 0 ;
V_17 -> V_21 -> V_287 ( V_17 , V_282 ) ;
V_19 = V_17 -> V_160 ;
} else {
V_19 = - V_28 ;
}
F_60 ( & V_17 -> V_157 ) ;
return V_19 ;
}
return 0 ;
}
static int F_103 ( struct V_112 * V_112 , struct V_7 * V_8 )
{
struct V_17 * V_17 = V_112 -> V_222 ;
struct V_9 * V_10 ;
struct V_288 * V_288 ;
unsigned long V_289 , V_165 , V_290 ;
int V_65 , V_19 ;
V_165 = V_8 -> V_291 ;
V_290 = V_8 -> V_292 - V_8 -> V_291 ;
F_2 ( V_6 , L_46 , ( int ) V_165 , ( int ) V_290 ) ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
if ( ! V_17 -> V_132 ) {
V_19 = - V_28 ;
goto V_163;
}
if ( V_17 -> V_120 != V_112 ) {
V_19 = - V_49 ;
goto V_163;
}
V_10 = NULL ;
for ( V_65 = 0 ; V_65 < V_17 -> V_121 ; ++ V_65 ) {
if ( V_17 -> V_10 [ V_65 ] . V_13 . V_114 != V_272 ) {
F_2 ( V_6 , L_47 ) ;
break;
}
if ( ( V_17 -> V_10 [ V_65 ] . V_13 . V_127 . V_83 >> V_293 )
== V_8 -> V_294 ) {
V_10 = & V_17 -> V_10 [ V_65 ] ;
break;
}
}
if ( V_10 == NULL ) {
F_2 ( V_6 , L_48 ) ;
V_19 = - V_49 ;
goto V_163;
}
if ( V_290 != V_10 -> V_13 . V_126 ) {
F_2 ( V_6 , L_49 ) ;
V_19 = - V_49 ;
goto V_163;
}
V_8 -> V_295 |= V_296 ;
V_289 = ( unsigned long ) V_10 -> V_71 ;
while ( V_290 > 0 ) {
V_288 = F_104 ( ( void * ) V_289 ) ;
V_19 = F_105 ( V_8 , V_165 , V_288 ) ;
if ( V_19 < 0 )
goto V_163;
V_165 += V_297 ;
V_289 += V_297 ;
V_290 -= V_297 ;
}
V_8 -> V_298 = & V_299 ;
V_8 -> V_11 = V_10 ;
F_3 ( V_8 ) ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_106 ( struct V_17 * V_17 , struct V_112 * V_112 ,
enum V_113 V_114 )
{
if ( ! V_17 -> V_132 )
return - V_28 ;
if ( V_17 -> V_120 != V_112 || V_17 -> V_114 != V_114 ||
! V_17 -> V_84 )
return - V_49 ;
return V_17 -> V_128 != F_36 ( & V_17 -> V_91 ) ;
}
static int F_107 ( struct V_17 * V_17 , struct V_112 * V_112 ,
enum V_113 V_114 )
{
int V_19 ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
V_19 = F_106 ( V_17 , V_112 , V_114 ) ;
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_108 ( struct V_112 * V_112 , void * V_181 ,
struct V_274 * V_13 )
{
struct V_17 * V_17 = V_181 ;
struct V_9 * V_10 ;
int V_65 , V_89 , V_19 ;
F_2 ( V_105 , L_50 ) ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
for (; ; ) {
V_19 = F_106 ( V_17 , V_112 , V_13 -> V_114 ) ;
if ( V_19 < 0 )
goto V_163;
if ( V_19 > 0 )
break;
F_60 ( & V_17 -> V_199 ) ;
if ( V_112 -> V_300 & V_301 )
return - V_302 ;
V_19 = F_109 ( V_17 -> V_104 ,
F_107 ( V_17 , V_112 , V_13 -> V_114 ) ,
F_110 ( 3000 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 == 0 )
return - V_162 ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
}
V_65 = V_17 -> V_128 ;
V_89 = V_17 -> V_94 [ V_65 ] ;
V_10 = & V_17 -> V_10 [ V_89 ] ;
V_17 -> V_128 = ( V_65 + 1 ) % V_103 ;
if ( V_17 -> V_21 -> V_303 ) {
F_84 ( & V_17 -> V_157 ) ;
V_17 -> V_160 = 0 ;
if ( V_17 -> V_132 )
V_17 -> V_21 -> V_303 ( V_17 ) ;
F_60 ( & V_17 -> V_157 ) ;
}
V_10 -> V_13 . V_14 &= ~ V_101 ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
F_2 ( V_105 , L_51 , V_89 ) ;
V_19 = 0 ;
if ( V_17 -> V_114 == V_273 ) {
if ( F_111 ( ( V_304 V_305 * ) V_10 -> V_13 . V_127 . V_306 ,
V_10 -> V_71 ,
V_10 -> V_13 . V_100 ) ) {
F_2 ( V_25 | V_6 ,
L_52 ) ;
V_19 = - V_307 ;
}
}
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_112 ( struct V_112 * V_112 , void * V_181 ,
struct V_274 * V_13 )
{
struct V_17 * V_17 = V_181 ;
struct V_9 * V_10 ;
int V_65 , V_122 , V_19 ;
F_2 ( V_105 , L_53 , V_13 -> V_122 ) ;
if ( F_57 ( & V_17 -> V_199 ) )
return - V_158 ;
V_122 = V_13 -> V_122 ;
if ( ( unsigned ) V_122 >= V_17 -> V_121 ) {
F_2 ( V_105 ,
L_54 , V_122 , V_17 -> V_121 ) ;
V_19 = - V_49 ;
goto V_163;
}
if ( V_13 -> V_114 != V_17 -> V_114 ) {
F_2 ( V_105 , L_55 ) ;
V_19 = - V_49 ;
goto V_163;
}
V_10 = & V_17 -> V_10 [ V_122 ] ;
if ( V_10 -> V_13 . V_14 & V_308 ) {
F_2 ( V_105 , L_56 ) ;
V_19 = - V_49 ;
goto V_163;
}
V_10 -> V_13 . V_14 |= V_102 ;
if ( V_10 -> V_13 . V_114 == V_273 ) {
V_10 -> V_13 . V_127 . V_306 = V_13 -> V_127 . V_306 ;
V_10 -> V_13 . V_126 = V_13 -> V_126 ;
}
V_65 = F_36 ( & V_17 -> V_92 ) ;
V_17 -> V_94 [ V_65 ] = V_122 ;
F_39 ( & V_17 -> V_92 , ( V_65 + 1 ) % V_103 ) ;
V_13 -> V_14 |= V_102 ;
V_13 -> V_14 &= ~ V_101 ;
V_19 = 0 ;
V_163:
F_60 ( & V_17 -> V_199 ) ;
return V_19 ;
}
static int F_113 ( struct V_17 * V_17 ,
struct V_112 * V_112 )
{
struct V_274 V_13 ;
int V_65 , V_19 ;
F_2 ( V_6 , L_57 ) ;
if ( V_17 -> V_121 == 0 ) {
struct V_269 V_270 ;
memset ( & V_270 , 0 , sizeof V_270 ) ;
V_270 . V_115 = V_17 -> V_285 ;
V_270 . type = V_123 ;
V_270 . V_114 = V_271 ;
V_19 = F_95 ( V_112 , V_17 , & V_270 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_58 , V_19 ) ;
return V_19 ;
}
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_123 ;
V_13 . V_114 = V_271 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_285 ; V_65 ++ ) {
V_13 . V_122 = V_65 ;
V_19 = F_112 ( V_112 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_59 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_114 = V_271 ;
}
V_19 = F_97 ( V_112 , V_17 , V_123 ) ;
if ( V_19 != 0 )
F_2 ( V_6 , L_60 , V_19 ) ;
return V_19 ;
}
static unsigned int F_114 ( struct V_112 * V_112 , T_5 * V_309 )
{
struct V_17 * V_17 = V_112 -> V_222 ;
int V_19 ;
F_2 ( V_105 , L_61 ) ;
F_115 ( V_112 , & V_17 -> V_104 , V_309 ) ;
if ( V_17 -> V_114 == V_129 ) {
V_19 = F_113 ( V_17 , V_112 ) ;
if ( V_19 != 0 )
return V_310 ;
}
if ( F_57 ( & V_17 -> V_199 ) != 0 )
return V_310 ;
if ( V_17 -> V_128 != F_36 ( & V_17 -> V_91 ) )
V_19 = V_311 | V_312 ;
else
V_19 = 0 ;
F_60 ( & V_17 -> V_199 ) ;
if ( ! V_17 -> V_132 )
return V_313 ;
return V_19 ;
}
static T_6 F_116 ( struct V_112 * V_112 , char V_305 * V_71 ,
T_7 V_115 , T_8 * V_314 )
{
struct V_17 * V_17 = V_112 -> V_222 ;
struct V_9 * V_10 ;
struct V_274 V_13 ;
struct V_315 V_95 ;
int V_146 , V_19 , V_316 ;
F_2 ( V_105 , L_62 , V_115 ) ;
if ( ! V_17 -> V_132 )
return - V_28 ;
if ( V_17 -> V_114 == V_129 ) {
V_19 = F_113 ( V_17 , V_112 ) ;
if ( V_19 != 0 )
return V_19 ;
}
V_95 = F_37 ( F_38 () ) ;
V_95 . V_317 -- ;
V_146 = 2 ;
for (; ; ) {
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_123 ;
V_13 . V_114 = V_271 ;
V_19 = F_108 ( V_112 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_63 , V_19 ) ;
return V_19 ;
}
V_10 = & V_17 -> V_10 [ V_13 . V_122 ] ;
if ( -- V_146 < 0 )
break;
if ( V_10 -> V_13 . V_95 . V_317 >= V_95 . V_317 )
break;
V_19 = F_112 ( V_112 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_64 , V_19 ) ;
return V_19 ;
}
}
if ( V_115 > V_10 -> V_13 . V_100 )
V_115 = V_10 -> V_13 . V_100 ;
V_19 = F_111 ( V_71 , V_10 -> V_71 , V_115 ) ;
if ( V_19 != 0 ) {
F_2 ( V_25 | V_6 ,
L_65 , V_19 , V_115 ) ;
V_19 = - V_307 ;
goto V_163;
}
V_19 = V_115 ;
V_163:
V_316 = F_112 ( V_112 , V_17 , & V_13 ) ;
if ( V_316 != 0 )
return V_316 ;
return V_19 ;
}
static void F_117 ( struct V_17 * V_17 )
{
struct V_168 * V_169 ;
int V_65 ;
for ( V_65 = 0 , V_169 = V_17 -> V_85 . V_174 ;
V_65 < V_17 -> V_21 -> V_175 ;
V_65 ++ , V_169 ++ ) {
V_169 -> V_177 = V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_249 ;
V_169 -> V_176 = V_169 -> V_177 ;
V_169 -> V_251 = V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_250 ;
V_169 -> V_253 = V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_252 ;
}
}
int F_118 ( struct V_61 * V_62 ,
const struct V_318 * V_37 ,
const struct V_21 * V_21 ,
int V_319 ,
struct V_221 * V_221 )
{
struct V_17 * V_17 ;
struct V_47 * V_31 = F_119 ( V_62 ) ;
int V_19 ;
F_2 ( V_217 , L_66 , V_37 -> V_233 , V_37 -> V_234 ) ;
if ( V_319 < sizeof *V_17 )
V_319 = sizeof *V_17 ;
V_17 = F_120 ( V_319 , V_53 ) ;
if ( ! V_17 ) {
F_7 ( L_67 ) ;
return - V_34 ;
}
V_17 -> V_218 = F_121 ( V_320 , V_53 ) ;
if ( ! V_17 -> V_218 ) {
F_7 ( L_68 ) ;
V_19 = - V_34 ;
goto V_163;
}
V_17 -> V_31 = V_31 ;
V_17 -> V_66 = V_62 -> V_67 -> V_68 . V_321 ;
V_17 -> V_144 = V_62 -> V_322 ;
if ( V_31 -> V_323 -> V_68 . V_324 != 1 ) {
int V_65 ;
struct V_61 * V_325 ;
for ( V_65 = 0 ; V_65 < V_31 -> V_323 -> V_68 . V_324 ; V_65 ++ ) {
V_325 = V_31 -> V_323 -> V_326 [ V_65 ] ;
if ( V_325 != NULL
&& V_325 -> V_145 != NULL
&& V_325 -> V_145 -> V_68 . V_327 ==
V_328 ) {
V_17 -> V_329 = 1 ;
break;
}
}
}
V_17 -> V_21 = V_21 ;
V_17 -> V_285 = 2 ;
V_17 -> V_82 = - 1 ;
V_19 = V_21 -> V_323 ( V_17 , V_37 ) ;
if ( V_19 < 0 )
goto V_163;
if ( V_17 -> V_85 . V_174 != NULL )
F_117 ( V_17 ) ;
V_19 = V_21 -> V_330 ( V_17 ) ;
if ( V_19 < 0 )
goto V_163;
F_61 ( V_17 ) ;
V_19 = F_8 ( V_17 ) ;
if ( V_19 )
goto V_163;
F_122 ( & V_17 -> V_157 ) ;
F_122 ( & V_17 -> V_199 ) ;
F_123 ( & V_17 -> V_104 ) ;
memcpy ( & V_17 -> V_216 , & V_331 , sizeof V_331 ) ;
V_17 -> V_216 . V_42 = & V_62 -> V_31 ;
V_17 -> V_221 = V_221 ;
V_17 -> V_132 = 1 ;
V_19 = F_124 ( & V_17 -> V_216 ,
V_332 ,
- 1 ) ;
if ( V_19 < 0 ) {
F_7 ( L_69 , V_19 ) ;
goto V_163;
}
F_125 ( V_62 , V_17 ) ;
F_2 ( V_217 , L_70 , F_78 ( & V_17 -> V_216 ) ) ;
F_25 ( V_17 ) ;
return 0 ;
V_163:
#if F_126 ( V_333 ) || F_126 ( V_334 )
if ( V_17 -> V_32 )
F_127 ( V_17 -> V_32 ) ;
#endif
F_79 ( V_17 -> V_218 ) ;
F_79 ( V_17 ) ;
return V_19 ;
}
int F_128 ( struct V_61 * V_62 ,
const struct V_318 * V_37 ,
const struct V_21 * V_21 ,
int V_319 ,
struct V_221 * V_221 )
{
struct V_47 * V_31 = F_119 ( V_62 ) ;
if ( V_31 -> V_232 . V_335 != 1 ) {
F_7 ( L_71 ,
V_37 -> V_233 , V_37 -> V_234 ) ;
return - V_28 ;
}
if ( V_31 -> V_323 -> V_68 . V_324 != 1
&& V_62 -> V_67 -> V_68 . V_321 != 0 )
return - V_28 ;
return F_118 ( V_62 , V_37 , V_21 , V_319 , V_221 ) ;
}
void F_129 ( struct V_61 * V_62 )
{
struct V_17 * V_17 = F_130 ( V_62 ) ;
#if F_126 ( V_333 ) || F_126 ( V_334 )
struct V_32 * V_32 ;
#endif
F_2 ( V_217 , L_72 ,
F_78 ( & V_17 -> V_216 ) ) ;
F_84 ( & V_17 -> V_157 ) ;
V_17 -> V_132 = 0 ;
F_40 ( & V_17 -> V_104 ) ;
F_47 ( V_17 ) ;
#if F_126 ( V_333 ) || F_126 ( V_334 )
F_29 ( V_17 ) ;
V_32 = V_17 -> V_32 ;
if ( V_32 ) {
V_17 -> V_32 = NULL ;
F_127 ( V_32 ) ;
}
#endif
V_17 -> V_31 = NULL ;
F_60 ( & V_17 -> V_157 ) ;
F_125 ( V_62 , NULL ) ;
F_131 ( & V_17 -> V_216 ) ;
}
int F_132 ( struct V_61 * V_62 , T_9 V_336 )
{
struct V_17 * V_17 = F_130 ( V_62 ) ;
if ( ! V_17 -> V_84 )
return 0 ;
V_17 -> V_75 = 1 ;
if ( V_17 -> V_21 -> V_133 )
V_17 -> V_21 -> V_133 ( V_17 ) ;
F_47 ( V_17 ) ;
F_29 ( V_17 ) ;
F_48 ( V_17 ) ;
if ( V_17 -> V_21 -> V_134 )
V_17 -> V_21 -> V_134 ( V_17 ) ;
return 0 ;
}
int F_133 ( struct V_61 * V_62 )
{
struct V_17 * V_17 = F_130 ( V_62 ) ;
V_17 -> V_75 = 0 ;
V_17 -> V_21 -> V_330 ( V_17 ) ;
F_25 ( V_17 ) ;
if ( V_17 -> V_84 )
return F_56 ( V_17 ) ;
return 0 ;
}
int F_134 ( struct V_17 * V_17 , int V_337 ,
int V_338 , int V_339 , int V_340 , int V_341 )
{
int V_65 , V_342 , V_343 , V_344 , V_345 , V_346 , V_347 ;
const struct V_169 * V_348 = NULL ;
const struct V_169 * V_349 = NULL ;
const struct V_169 * V_350 = NULL ;
int V_351 = 0 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_21 -> V_175 ; V_65 ++ ) {
if ( V_17 -> V_242 & ( 1 << V_65 ) )
continue;
if ( V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_37 == V_352 )
V_348 = & V_17 -> V_21 -> V_174 [ V_65 ] ;
if ( V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_37 == V_353 )
V_349 = & V_17 -> V_21 -> V_174 [ V_65 ] ;
if ( V_17 -> V_21 -> V_174 [ V_65 ] . V_243 . V_37 == V_354 )
V_350 = & V_17 -> V_21 -> V_174 [ V_65 ] ;
}
if ( ! V_348 || ! V_349 || ! V_350 ) {
F_2 ( V_25 , L_73
L_74 ) ;
return 0 ;
}
if ( V_348 -> V_261 ( V_17 , & V_343 ) ||
V_349 -> V_261 ( V_17 , & V_345 ) ||
V_350 -> V_261 ( V_17 , & V_347 ) || ! V_347 )
return 0 ;
V_344 = V_343 ;
V_346 = V_345 ;
V_342 = abs ( V_338 - V_337 ) / V_339 ;
F_2 ( V_105 , L_75 ,
V_337 , V_338 , V_342 ) ;
for ( V_65 = 0 ; V_65 < V_342 ; V_65 ++ ) {
if ( V_337 > V_338 ) {
if ( V_343 > V_340 )
V_343 -- ;
else if ( V_345 > V_341 )
V_345 -- ;
else if ( V_343 > V_348 -> V_243 . V_249 )
V_343 -- ;
else if ( V_345 > V_349 -> V_243 . V_250 )
V_345 -- ;
else if ( V_343 > V_348 -> V_243 . V_250 )
V_343 -- ;
else
break;
} else {
if ( V_343 < V_348 -> V_243 . V_249 )
V_343 ++ ;
else if ( V_345 < V_341 )
V_345 ++ ;
else if ( V_343 < V_340 )
V_343 ++ ;
else if ( V_345 < V_349 -> V_243 . V_252 )
V_345 ++ ;
else if ( V_343 < V_348 -> V_243 . V_252 )
V_343 ++ ;
else
break;
}
}
if ( V_343 != V_344 ) {
V_348 -> V_259 ( V_17 , V_343 ) ;
V_351 = 1 ;
}
if ( V_345 != V_346 ) {
V_349 -> V_259 ( V_17 , V_345 ) ;
V_351 = 1 ;
}
return V_351 ;
}
static int T_10 F_135 ( void )
{
F_136 ( L_76 ,
( V_237 >> 16 ) & 0xff ,
( V_237 >> 8 ) & 0xff ,
V_237 & 0xff ) ;
return 0 ;
}
static void T_11 F_137 ( void )
{
}
