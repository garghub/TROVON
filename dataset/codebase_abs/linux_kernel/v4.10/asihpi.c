static T_1 F_1 (
T_2 V_1 ,
T_2 V_2 ,
T_2 V_3
)
{
struct V_4 V_5 ;
struct V_6 V_7 ;
unsigned int V_8 = F_2 ( V_1 ) ;
if ( ! V_1 )
return V_9 ;
F_3 ( & V_5 , & V_7 , V_8 ,
V_8 == V_10 ?
V_11 :
V_12 ) ;
F_4 ( V_1 , & V_5 . V_13 ,
& V_5 . V_14 ) ;
V_5 . V_15 . V_16 . V_15 . V_17 . V_18 = V_2 ;
V_5 . V_15 . V_16 . V_15 . V_17 . V_3 = V_3 ;
V_5 . V_15 . V_16 . V_15 . V_17 . V_19 = V_20 ;
F_5 ( & V_5 , & V_7 ) ;
return V_7 . error ;
}
static T_1 F_6 ( T_2 V_1 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
unsigned int V_8 = F_2 ( V_1 ) ;
if ( ! V_1 )
return V_9 ;
F_3 ( & V_5 , & V_7 , V_8 ,
V_8 == V_10 ?
V_21 :
V_22 ) ;
F_4 ( V_1 , & V_5 . V_13 ,
& V_5 . V_14 ) ;
V_5 . V_15 . V_16 . V_15 . V_17 . V_19 = V_23 ;
F_5 ( & V_5 , & V_7 ) ;
return V_7 . error ;
}
static inline T_1 F_7 ( T_2 V_1 )
{
if ( F_2 ( V_1 ) == V_10 )
return F_8 ( V_1 ) ;
else
return F_9 ( V_1 ) ;
}
static inline T_1 F_10 ( T_2 V_1 )
{
if ( F_2 ( V_1 ) == V_10 )
return F_11 ( V_1 ) ;
else
return F_12 ( V_1 ) ;
}
static inline T_1 F_13 (
T_2 V_1 ,
T_1 * V_24 ,
T_2 * V_25 ,
T_2 * V_26 ,
T_2 * V_27 ,
T_2 * V_28
)
{
T_1 V_29 ;
if ( F_2 ( V_1 ) == V_10 )
V_29 = F_14 ( V_1 , V_24 ,
V_25 , V_26 ,
V_27 , V_28 ) ;
else
V_29 = F_15 ( V_1 , V_24 ,
V_25 , V_26 ,
V_27 , V_28 ) ;
return V_29 ;
}
static inline T_1 F_16 (
T_2 V_30 ,
T_2 V_1 )
{
if ( F_2 ( V_30 ) == V_10 )
return F_17 ( V_30 , V_1 ) ;
else
return F_18 ( V_30 , V_1 ) ;
}
static inline T_1 F_19 ( T_2 V_1 )
{
if ( F_2 ( V_1 ) == V_10 )
return F_20 ( V_1 ) ;
else
return F_21 ( V_1 ) ;
}
static inline T_1 F_22 (
T_2 V_1 , T_2 * V_31 , T_2 * V_32 )
{
if ( F_2 ( V_1 ) == V_10 )
return F_23 ( V_1 , V_31 , V_32 ) ;
else
return F_24 ( V_1 , V_31 , V_32 ) ;
}
static T_1 F_25 ( T_1 V_33 , int line , char * V_34 )
{
if ( V_33 )
F_26 ( V_35
L_1 ,
V_34 , line , V_33 ) ;
return V_33 ;
}
static void F_27 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_29 ( L_2 , V_40 ) ;
F_29 ( L_3 ,
F_30 ( V_39 ) , F_31 ( V_39 ) ,
F_32 ( V_39 ) , F_33 ( V_39 ) ) ;
F_29 ( L_4 ,
F_34 ( V_39 ) , F_35 ( V_39 ) ,
F_36 ( V_39 ) , F_37 ( V_39 ) ) ;
F_29 ( L_5 ,
F_38 ( V_39 ) , F_39 ( V_39 ) ,
F_30 ( V_39 ) * F_31 ( V_39 ) *
F_40 ( F_32 ( V_39 ) ) / 8 ) ;
}
static int F_41 ( T_3 V_41 ,
T_1 * V_42 )
{
T_1 V_43 ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
if ( V_46 [ V_43 ] == V_41 ) {
* V_42 = V_43 ;
return 0 ;
}
}
F_42 ( V_35 L_6 ,
V_41 ) ;
* V_42 = 0 ;
return - V_47 ;
}
static void F_43 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 ;
int V_54 ;
unsigned int V_55 = 200000 ;
unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
if ( V_49 -> V_58 ) {
V_57 |= V_59 ;
V_57 |= V_60 ;
V_55 = 8000 ;
V_56 = 100000 ;
} else {
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( V_33 ) {
F_45 ( & V_49 -> V_64 -> V_65 ,
L_7 , V_33 ) ;
}
for ( V_54 = - 1 ; V_54 < 100 ; V_54 ++ ) {
if ( V_54 == - 1 ) {
if ( F_46 ( V_52 ,
& V_53 ) )
continue;
} else if ( F_47 ( V_52 ,
V_54 , & V_53 ) ) {
break;
}
V_55 = F_48 ( V_55 , V_53 ) ;
V_56 = F_49 ( V_56 , V_53 ) ;
switch ( V_53 ) {
case 5512 :
V_57 |= V_66 ;
break;
case 8000 :
V_57 |= V_67 ;
break;
case 11025 :
V_57 |= V_68 ;
break;
case 16000 :
V_57 |= V_69 ;
break;
case 22050 :
V_57 |= V_70 ;
break;
case 32000 :
V_57 |= V_71 ;
break;
case 44100 :
V_57 |= V_72 ;
break;
case 48000 :
V_57 |= V_73 ;
break;
case 64000 :
V_57 |= V_74 ;
break;
case 88200 :
V_57 |= V_75 ;
break;
case 96000 :
V_57 |= V_76 ;
break;
case 176400 :
V_57 |= V_77 ;
break;
case 192000 :
V_57 |= V_78 ;
break;
default:
V_57 |= V_79 ;
}
}
}
V_51 -> V_57 = V_57 ;
V_51 -> V_55 = V_55 ;
V_51 -> V_56 = V_56 ;
}
static int F_50 ( struct V_36 * V_37 ,
struct V_38 * V_80 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
int V_33 ;
T_1 V_43 ;
int V_87 ;
unsigned int V_88 ;
F_27 ( V_37 , V_80 ) ;
V_33 = F_52 ( V_37 , F_34 ( V_80 ) ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_41 ( F_32 ( V_80 ) , & V_43 ) ;
if ( V_33 )
return V_33 ;
F_53 ( F_54 ( & V_84 -> V_43 ,
F_31 ( V_80 ) ,
V_43 , F_30 ( V_80 ) , 0 , 0 ) ) ;
if ( V_37 -> V_89 == V_90 ) {
if ( F_55 ( V_84 -> V_1 ) != 0 )
return - V_47 ;
if ( F_56 (
V_84 -> V_1 , & V_84 -> V_43 ) != 0 )
return - V_47 ;
}
V_84 -> V_91 = 0 ;
if ( V_86 -> V_92 ) {
V_33 = F_1 ( V_84 -> V_1 ,
F_34 ( V_80 ) , V_82 -> V_93 ) ;
if ( V_33 == 0 ) {
F_29 (
L_8 ,
F_34 ( V_80 ) ,
( unsigned long ) V_82 -> V_93 ) ;
} else {
F_42 ( L_9 ,
V_33 ) ;
return - V_94 ;
}
V_33 = F_13 ( V_84 -> V_1 , NULL ,
& V_84 -> V_91 , NULL , NULL , NULL ) ;
}
V_88 = F_30 ( V_80 ) * F_31 ( V_80 ) ;
V_87 = F_40 ( F_32 ( V_80 ) ) ;
V_88 *= V_87 ;
V_88 /= 8 ;
if ( V_87 < 0 || V_88 == 0 )
return - V_47 ;
V_84 -> V_88 = V_88 ;
V_84 -> V_95 = F_34 ( V_80 ) ;
V_84 -> V_96 = F_35 ( V_80 ) ;
return 0 ;
}
static int
F_57 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
if ( V_84 -> V_91 )
F_6 ( V_84 -> V_1 ) ;
F_58 ( V_37 ) ;
return 0 ;
}
static void F_59 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
F_60 ( V_84 ) ;
}
static void F_61 ( struct V_36 *
V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
int V_97 ;
V_97 = V_98 / 200 ;
V_97 = F_49 ( V_97 , 1 ) ;
F_62 ( & V_84 -> V_99 , V_100 + V_97 ) ;
V_84 -> V_101 = 1 ;
}
static void F_63 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
V_84 -> V_101 = 0 ;
F_64 ( & V_84 -> V_99 ) ;
}
static void F_65 ( struct V_36 * V_37 )
{
struct V_83 * V_84 ;
struct V_48 * V_86 ;
F_66 ( ! V_37 ) ;
V_84 = (struct V_83 * ) V_37 -> V_82 -> V_85 ;
V_86 = F_51 ( V_37 ) ;
F_66 ( F_67 () ) ;
F_68 ( & V_86 -> V_102 ) ;
V_86 -> V_103 = V_84 ;
F_69 ( & V_86 -> V_102 ) ;
F_53 ( F_70 ( V_86 -> V_104 -> V_105 -> V_106 ,
V_107 ,
V_86 -> V_108 , 0 ) ) ;
}
static void F_71 ( struct V_36 * V_37 )
{
struct V_83 * V_84 ;
struct V_48 * V_86 ;
F_66 ( ! V_37 ) ;
V_84 = (struct V_83 * ) V_37 -> V_82 -> V_85 ;
V_86 = F_51 ( V_37 ) ;
F_53 ( F_70 ( V_86 -> V_104 -> V_105 -> V_106 ,
V_107 , 0 , 0 ) ) ;
if ( F_67 () )
V_86 -> V_103 = NULL ;
else {
F_68 ( & V_86 -> V_102 ) ;
V_86 -> V_103 = NULL ;
F_69 ( & V_86 -> V_102 ) ;
}
}
static int F_72 ( struct V_36 * V_37 ,
int V_109 )
{
struct V_83 * V_84 = V_37 -> V_82 -> V_85 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_36 * V_110 ;
T_1 V_29 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
switch ( V_109 ) {
case V_111 :
F_29 ( L_10 , V_40 ) ;
F_73 (s, substream) {
struct V_81 * V_82 = V_110 -> V_82 ;
struct V_83 * V_112 = V_82 -> V_85 ;
if ( F_51 ( V_110 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_110 -> V_89 )
continue;
V_112 -> V_113 = 0 ;
if ( V_110 -> V_89 == V_114 ) {
unsigned int V_115 = V_112 -> V_96 * 1 ;
F_74 ( L_11 , V_110 -> V_116 , V_115 ) ;
F_53 ( F_75 (
V_112 -> V_1 ,
& V_82 -> V_117 [ 0 ] ,
V_115 ,
& V_112 -> V_43 ) ) ;
V_112 -> V_118 = V_115 ;
}
if ( V_86 -> V_119 ) {
F_29 ( L_12 , V_110 -> V_116 ) ;
V_29 = F_16 (
V_84 -> V_1 ,
V_112 -> V_1 ) ;
if ( ! V_29 ) {
F_76 ( V_110 , V_37 ) ;
} else {
F_53 ( V_29 ) ;
break;
}
} else
break;
}
V_86 -> V_120 ( V_37 ) ;
if ( ( V_37 -> V_89 == V_90 ) ||
! V_86 -> V_92 )
F_53 ( F_7 ( V_84 -> V_1 ) ) ;
break;
case V_121 :
F_29 ( L_13 , V_40 ) ;
V_86 -> V_122 ( V_37 ) ;
F_73 (s, substream) {
if ( F_51 ( V_110 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_110 -> V_89 )
continue;
V_110 -> V_82 -> V_123 -> V_124 = V_125 ;
if ( V_86 -> V_119 ) {
F_29 ( L_12 , V_110 -> V_116 ) ;
F_76 ( V_110 , V_37 ) ;
} else
break;
}
F_53 ( F_10 ( V_84 -> V_1 ) ) ;
if ( V_37 -> V_89 == V_114 )
F_53 (
F_77 ( V_84 -> V_1 ) ) ;
if ( V_86 -> V_119 )
F_53 ( F_19 ( V_84 -> V_1 ) ) ;
break;
case V_126 :
F_29 ( L_14 , V_40 ) ;
V_86 -> V_120 ( V_37 ) ;
F_53 ( F_7 ( V_84 -> V_1 ) ) ;
break;
case V_127 :
F_29 ( L_15 , V_40 ) ;
V_86 -> V_122 ( V_37 ) ;
F_53 ( F_10 ( V_84 -> V_1 ) ) ;
break;
default:
F_42 ( V_128 L_16 ) ;
return - V_47 ;
}
return 0 ;
}
static inline unsigned int F_78 ( unsigned int V_129 , unsigned int V_130 ,
unsigned long int V_131 )
{
unsigned int V_132 ;
if ( ( ( V_129 - V_130 ) % V_131 ) < ( V_131 / 2 ) )
V_132 = V_130 ;
else
V_132 = V_129 ;
return V_132 ;
}
static void F_79 ( unsigned long V_133 )
{
struct V_83 * V_84 = (struct V_83 * ) V_133 ;
struct V_36 * V_37 = V_84 -> V_37 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_81 * V_82 ;
struct V_36 * V_110 ;
unsigned int V_134 = 0 ;
unsigned int V_135 , V_136 = 0 ;
unsigned int V_137 , V_138 , V_139 ;
int V_140 = 1 ;
int V_141 = 0 ;
T_1 V_124 ;
T_2 V_18 , V_142 , V_143 , V_144 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_73 (s, substream) {
struct V_83 * V_112 = V_110 -> V_82 -> V_85 ;
V_82 = V_110 -> V_82 ;
if ( F_51 ( V_110 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_110 -> V_89 )
continue;
F_53 ( F_13 (
V_112 -> V_1 , & V_124 ,
& V_18 , & V_142 ,
& V_143 , & V_144 ) ) ;
V_82 -> V_145 = V_144 ;
if ( ! V_86 -> V_92 )
V_144 = V_142 ;
if ( V_110 -> V_89 == V_114 ) {
V_135 = V_112 -> V_118 - V_142 ;
if ( V_124 == V_146 ) {
if ( V_142 == 0 ) {
F_53 ( F_7 ( V_112 -> V_1 ) ) ;
F_29 ( L_17 , V_110 -> V_116 ) ;
V_112 -> V_113 = 0 ;
}
} else if ( V_124 == V_147 ) {
F_42 ( V_35 L_18 ,
V_110 -> V_116 ) ;
V_112 -> V_113 ++ ;
if ( V_112 -> V_113 > 20 ) {
F_80 ( V_110 ) ;
continue;
}
} else {
V_112 -> V_113 = 0 ;
}
} else
V_135 = V_142 + V_112 -> V_118 ;
if ( V_140 ) {
V_136 = V_135 ;
V_134 = ( V_135 - V_112 -> V_148 ) % V_112 -> V_95 ;
V_140 = 0 ;
} else {
V_136 =
F_78 ( V_136 , V_135 , V_149 + 1L ) ;
V_134 = F_48 (
( V_135 - V_112 -> V_148 ) % V_112 -> V_95 ,
V_134 ) ;
}
F_74 (
L_19 ,
V_40 , V_110 -> V_116 , V_124 ,
V_112 -> V_148 ,
V_112 -> V_118 ,
V_135 ,
( int ) V_142 ,
( int ) V_144 ,
V_18 - V_142 ,
( unsigned long ) F_81 ( V_82 ,
V_82 -> V_123 -> V_150 ) ,
( unsigned long ) F_81 ( V_82 ,
V_82 -> V_151 -> V_152 )
) ;
V_141 ++ ;
}
V_135 = V_136 ;
V_137 = V_134 % V_84 -> V_96 ;
V_138 = V_134 - V_137 ;
if ( V_138 && ( V_144 > V_84 -> V_96 ) )
V_139 = ( ( V_144 - V_84 -> V_96 ) * V_98 / V_84 -> V_88 ) ;
else
V_139 = ( ( V_84 -> V_96 - V_137 ) * V_98 / V_84 -> V_88 ) ;
V_139 = F_49 ( V_139 , 1U ) ;
V_84 -> V_99 . V_153 = V_100 + V_139 ;
F_74 ( L_20 ,
V_139 , V_135 , V_134 , V_138 ) ;
F_73 (s, substream) {
struct V_83 * V_112 = V_110 -> V_82 -> V_85 ;
V_82 = V_110 -> V_82 ;
if ( V_37 -> V_89 != V_110 -> V_89 )
continue;
V_112 -> V_135 = V_135 ;
if ( V_138 &&
( ( V_144 <= V_112 -> V_96 ) ||
( V_110 -> V_89 == V_90 ) ) )
{
unsigned int V_154 = V_112 -> V_118 % V_112 -> V_95 ;
unsigned int V_155 , V_156 ;
char * V_157 = & V_110 -> V_82 -> V_117 [ V_154 ] ;
if ( V_86 -> V_92 ) {
V_155 = V_138 ;
V_156 = 0 ;
} else {
V_155 = F_48 ( V_138 , V_112 -> V_95 - V_154 ) ;
V_156 = V_138 - V_155 ;
}
if ( V_110 -> V_89 == V_114 ) {
F_74 ( L_21 ,
V_110 -> V_116 , V_155 , V_154 ) ;
F_53 (
F_75 (
V_112 -> V_1 , V_157 , V_155 ,
& V_112 -> V_43 ) ) ;
if ( V_156 ) {
V_157 = V_110 -> V_82 -> V_117 ;
F_74 ( L_22 ,
V_110 -> V_116 ,
V_138 - V_155 , V_154 ) ;
F_53 (
F_75 (
V_112 -> V_1 , V_157 ,
V_138 - V_155 ,
& V_112 -> V_43 ) ) ;
}
} else {
F_74 ( L_23 ,
V_110 -> V_116 , V_155 ) ;
F_53 (
F_82 (
V_112 -> V_1 ,
V_157 , V_155 ) ) ;
if ( V_156 ) {
V_157 = V_110 -> V_82 -> V_117 ;
F_74 ( L_24 ,
V_110 -> V_116 , V_156 ) ;
F_53 (
F_82 (
V_112 -> V_1 ,
V_157 , V_156 ) ) ;
}
}
V_112 -> V_118 += V_138 ;
V_112 -> V_148 += V_138 ;
F_83 ( V_110 ) ;
}
}
if ( ! V_86 -> V_104 -> V_158 && V_84 -> V_101 )
F_84 ( & V_84 -> V_99 ) ;
}
static void F_85 ( unsigned long V_133 )
{
struct V_159 * V_129 = (struct V_159 * ) V_133 ;
struct V_48 * V_49 ;
F_86 ( ! V_129 || ! V_129 -> V_160 || ! V_129 -> V_160 -> V_85 ) ;
V_49 = (struct V_48 * ) V_129 -> V_160 -> V_85 ;
if ( V_49 -> V_103 )
F_79 (
( unsigned long ) V_49 -> V_103 ) ;
}
static void F_87 ( struct V_159 * V_129 )
{
struct V_48 * V_49 ;
F_86 ( ! V_129 || ! V_129 -> V_160 || ! V_129 -> V_160 -> V_85 ) ;
V_49 = (struct V_48 * ) V_129 -> V_160 -> V_85 ;
F_88 ( & V_49 -> V_102 ) ;
}
static int F_89 ( struct V_36 * V_37 ,
unsigned int V_109 , void * V_161 )
{
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_74 ( V_162 L_25 , V_40 , V_109 ) ;
return F_90 ( V_37 , V_109 , V_161 ) ;
}
static int F_91 ( struct V_36 *
V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_29 ( L_26 , V_37 -> V_116 ) ;
F_53 ( F_77 ( V_84 -> V_1 ) ) ;
V_84 -> V_118 = 0 ;
V_84 -> V_135 = 0 ;
V_84 -> V_148 = 0 ;
return 0 ;
}
static T_4
F_92 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
T_4 V_163 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
V_163 = F_93 ( V_82 , V_84 -> V_135 % V_84 -> V_95 ) ;
F_74 ( L_27 , V_40 , ( unsigned long ) V_163 ) ;
return V_163 ;
}
static T_5 F_94 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_164 = 0 ;
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_46 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_54 ( & V_42 , V_49 -> V_165 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_95 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_164 |= F_96 ( V_46 [ V_43 ] ) ;
}
return V_164 ;
}
static int F_97 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_50 V_166 ;
int V_33 ;
V_84 = F_98 ( sizeof( * V_84 ) , V_167 ) ;
if ( V_84 == NULL )
return - V_94 ;
V_33 = F_99 ( V_86 -> V_104 -> V_105 -> V_106 ,
V_37 -> V_116 , & V_84 -> V_1 ) ;
F_53 ( V_33 ) ;
if ( V_33 )
F_60 ( V_84 ) ;
if ( V_33 == V_168 )
return - V_169 ;
if ( V_33 )
return - V_170 ;
F_100 ( & V_84 -> V_99 , F_79 ,
( unsigned long ) V_84 ) ;
V_84 -> V_37 = V_37 ;
V_82 -> V_85 = V_84 ;
V_82 -> V_171 = F_59 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( ! V_86 -> V_104 -> V_158 ) {
V_166 . V_172 = V_173 ;
V_166 . V_174 = V_175 ;
V_166 . V_176 = V_173 / V_177 ;
V_166 . V_178 = V_177 ;
V_166 . V_179 = V_173 / V_175 ;
} else {
T_6 V_180 = V_86 -> V_108 *
V_86 -> V_165 ;
V_166 . V_172 = V_173 ;
V_166 . V_174 = V_180 ;
V_166 . V_176 = V_173 / V_177 ;
V_166 . V_178 = V_177 ;
V_166 . V_179 = V_173 / V_180 ;
}
V_166 . V_181 = V_86 -> V_165 ;
V_166 . V_182 = V_86 -> V_183 ;
V_166 . V_164 =
F_94 ( V_86 , V_84 -> V_1 ) ;
F_43 ( V_86 , & V_166 ) ;
V_166 . V_184 = V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 ;
if ( V_86 -> V_119 ) {
V_166 . V_184 |= V_192 ;
F_101 ( V_37 ) ;
}
V_82 -> V_193 = V_166 ;
if ( V_86 -> V_92 )
V_33 = F_102 ( V_82 , 0 ,
V_194 ) ;
if ( V_33 < 0 )
return V_33 ;
F_103 ( V_82 , 0 , V_195 ,
V_86 -> V_108 ) ;
F_104 ( V_82 , V_195 ,
V_86 -> V_108 , V_149 ) ;
F_29 ( L_28 ) ;
return 0 ;
}
static int F_105 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_53 ( F_106 ( V_84 -> V_1 ) ) ;
F_29 ( L_29 ) ;
return 0 ;
}
static T_4
F_107 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_74 ( L_30 , V_40 , V_84 -> V_135 ) ;
return F_93 ( V_82 , V_84 -> V_135 % V_84 -> V_95 ) ;
}
static int F_108 ( struct V_36 * V_37 ,
unsigned int V_109 , void * V_161 )
{
return F_90 ( V_37 , V_109 , V_161 ) ;
}
static int F_109 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_53 ( F_55 ( V_84 -> V_1 ) ) ;
V_84 -> V_118 = 0 ;
V_84 -> V_135 = 0 ;
V_84 -> V_148 = 0 ;
F_29 ( L_31 , V_37 -> V_116 ) ;
return 0 ;
}
static T_5 F_110 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_164 = 0 ;
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_46 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_54 ( & V_42 , V_49 -> V_196 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_111 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_164 |= F_96 ( V_46 [ V_43 ] ) ;
}
return V_164 ;
}
static int F_112 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_83 * V_84 ;
struct V_50 V_197 ;
int V_33 ;
V_84 = F_98 ( sizeof( * V_84 ) , V_167 ) ;
if ( V_84 == NULL )
return - V_94 ;
F_29 ( L_32 ,
V_86 -> V_104 -> V_105 -> V_106 , V_37 -> V_116 ) ;
V_33 = F_53 (
F_113 ( V_86 -> V_104 -> V_105 -> V_106 ,
V_37 -> V_116 , & V_84 -> V_1 ) ) ;
if ( V_33 )
F_60 ( V_84 ) ;
if ( V_33 == V_168 )
return - V_169 ;
if ( V_33 )
return - V_170 ;
F_100 ( & V_84 -> V_99 , F_79 ,
( unsigned long ) V_84 ) ;
V_84 -> V_37 = V_37 ;
V_82 -> V_85 = V_84 ;
V_82 -> V_171 = F_59 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
if ( ! V_86 -> V_104 -> V_158 ) {
V_197 . V_172 = V_173 ;
V_197 . V_174 = V_175 ;
V_197 . V_176 = V_173 / V_177 ;
V_197 . V_178 = V_177 ;
V_197 . V_179 = V_173 / V_175 ;
} else {
T_6 V_180 = V_86 -> V_108 *
V_86 -> V_165 ;
V_197 . V_172 = V_173 ;
V_197 . V_174 = V_180 ;
V_197 . V_176 = V_173 / V_177 ;
V_197 . V_178 = V_177 ;
V_197 . V_179 = V_173 / V_180 ;
}
V_197 . V_181 = V_86 -> V_196 ;
V_197 . V_182 = V_86 -> V_198 ;
V_197 . V_164 =
F_110 ( V_86 , V_84 -> V_1 ) ;
F_43 ( V_86 , & V_197 ) ;
V_197 . V_184 = V_185 |
V_190 |
V_191 ;
if ( V_86 -> V_119 )
V_197 . V_184 |= V_192 ;
V_82 -> V_193 = V_197 ;
if ( V_86 -> V_92 )
V_33 = F_102 ( V_82 , 0 ,
V_194 ) ;
if ( V_33 < 0 )
return V_33 ;
F_103 ( V_82 , 0 , V_195 ,
V_86 -> V_108 ) ;
F_104 ( V_82 , V_195 ,
V_86 -> V_108 , V_149 ) ;
F_101 ( V_37 ) ;
return 0 ;
}
static int F_114 ( struct V_36 * V_37 )
{
struct V_83 * V_84 = V_37 -> V_82 -> V_85 ;
F_53 ( F_115 ( V_84 -> V_1 ) ) ;
return 0 ;
}
static int F_116 ( struct V_48 * V_49 , int V_199 )
{
struct V_200 * V_201 ;
int V_33 ;
T_1 V_202 , V_203 , V_204 ;
T_2 V_205 ;
V_33 = F_117 ( V_49 -> V_104 -> V_105 -> V_106 ,
& V_203 , & V_202 ,
& V_204 , & V_205 , & V_204 ) ;
V_33 = F_118 ( V_49 -> V_86 , L_33 , V_199 ,
V_203 , V_202 , & V_201 ) ;
if ( V_33 < 0 )
return V_33 ;
F_119 ( V_201 , V_114 ,
& V_206 ) ;
F_119 ( V_201 , V_90 ,
& V_207 ) ;
V_201 -> V_85 = V_49 ;
V_201 -> V_208 = 0 ;
strcpy ( V_201 -> V_40 , L_33 ) ;
F_120 ( V_201 , V_209 ,
F_121 ( V_49 -> V_64 ) ,
64 * 1024 , V_173 ) ;
return 0 ;
}
static inline int F_122 ( struct V_160 * V_86 , struct V_210 * V_211 ,
struct V_48 * V_49 )
{
int V_33 ;
V_33 = F_123 ( V_86 , F_124 ( V_211 , V_49 ) ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_212 )
F_125 ( & V_49 -> V_64 -> V_65 , L_34 , V_211 -> V_40 , V_211 -> V_106 ) ;
return 0 ;
}
static void F_126 ( struct V_210 * V_213 ,
struct V_214 * V_215 ,
char * V_40 )
{
char * V_216 ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_40 = V_215 -> V_40 ;
V_213 -> V_217 = V_215 -> V_52 ;
V_213 -> V_218 = V_219 ;
V_213 -> V_106 = 0 ;
if ( V_215 -> V_220 + V_221 == V_62 )
V_216 = L_35 ;
else if ( V_215 -> V_222 + V_223 == V_224 )
V_216 = L_36 ;
else if ( ( V_215 -> V_220 + V_221 != V_225 ) &&
( ! V_215 -> V_222 ) )
V_216 = L_36 ;
else if ( V_215 -> V_220 &&
( V_215 -> V_220 + V_221 != V_225 ) &&
( V_215 -> V_222 ) )
V_216 = L_37 ;
else
V_216 = L_38 ;
if ( V_215 -> V_220 && V_215 -> V_222 )
sprintf ( V_215 -> V_40 , L_39 ,
V_226 [ V_215 -> V_220 ] ,
V_215 -> V_227 ,
V_228 [ V_215 -> V_222 ] ,
V_215 -> V_229 ,
V_216 , V_40 ) ;
else if ( V_215 -> V_222 ) {
sprintf ( V_215 -> V_40 , L_40 ,
V_228 [ V_215 -> V_222 ] ,
V_215 -> V_229 ,
V_216 , V_40 ) ;
} else {
sprintf ( V_215 -> V_40 , L_40 ,
V_226 [ V_215 -> V_220 ] ,
V_215 -> V_227 ,
V_216 , V_40 ) ;
}
}
static int F_127 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_234 ;
T_1 V_33 ;
short V_235 ;
short V_236 ;
short V_237 ;
V_33 = F_128 ( V_52 ,
& V_235 , & V_236 , & V_237 ) ;
if ( V_33 ) {
V_236 = 0 ;
V_235 = - 10000 ;
V_237 = V_238 ;
}
V_33 = F_129 ( V_52 , & V_234 ) ;
if ( V_33 )
V_234 = V_239 ;
V_233 -> type = V_240 ;
V_233 -> V_234 = V_234 ;
V_233 -> V_241 . integer . F_48 = V_235 / V_238 ;
V_233 -> V_241 . integer . F_49 = V_236 / V_238 ;
V_233 -> V_241 . integer . V_242 = V_237 / V_238 ;
return 0 ;
}
static int F_130 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
short V_245 [ V_239 ] ;
F_53 ( F_131 ( V_52 , V_245 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] = V_245 [ 0 ] / V_238 ;
V_244 -> V_241 . integer . V_241 [ 1 ] = V_245 [ 1 ] / V_238 ;
return 0 ;
}
static int F_132 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
short V_245 [ V_239 ] ;
V_245 [ 0 ] =
( V_244 -> V_241 . integer . V_241 [ 0 ] ) * V_238 ;
V_245 [ 1 ] =
( V_244 -> V_241 . integer . V_241 [ 1 ] ) * V_238 ;
V_246 = 1 ;
F_53 ( F_133 ( V_52 , V_245 ) ) ;
return V_246 ;
}
static int F_134 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_247 ;
F_53 ( F_135 ( V_52 , & V_247 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] = V_247 ? 0 : 1 ;
return 0 ;
}
static int F_136 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
int V_246 = 1 ;
int V_247 = V_244 -> V_241 . integer . V_241 [ 0 ] ? 0 : V_248 ;
F_53 ( F_137 ( V_52 , V_247 ) ) ;
return V_246 ;
}
static int F_138 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
int V_33 ;
T_2 V_247 ;
F_126 ( & V_213 , V_215 , L_41 ) ;
V_213 . V_249 = V_250 |
V_251 ;
V_213 . V_184 = F_127 ;
V_213 . V_252 = F_130 ;
V_213 . V_253 = F_132 ;
V_213 . V_254 . V_39 = V_255 ;
V_33 = F_122 ( V_86 , & V_213 , V_49 ) ;
if ( V_33 )
return V_33 ;
if ( F_135 ( V_215 -> V_52 , & V_247 ) == 0 ) {
F_126 ( & V_213 , V_215 , L_42 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = V_256 ;
V_213 . V_252 = F_134 ;
V_213 . V_253 = F_136 ;
V_33 = F_122 ( V_86 , & V_213 , V_49 ) ;
}
return V_33 ;
}
static int F_139 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_33 ;
short V_235 ;
short V_236 ;
short V_237 ;
V_33 =
F_140 ( V_52 , & V_235 ,
& V_236 , & V_237 ) ;
if ( V_33 ) {
V_236 = 2400 ;
V_235 = - 1000 ;
V_237 = 100 ;
}
V_233 -> type = V_240 ;
V_233 -> V_234 = 2 ;
V_233 -> V_241 . integer . F_48 = V_235 / V_257 ;
V_233 -> V_241 . integer . F_49 = V_236 / V_257 ;
V_233 -> V_241 . integer . V_242 = V_237 / V_257 ;
return 0 ;
}
static int F_141 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
short V_245 [ V_239 ] ;
F_53 ( F_142 ( V_52 , V_245 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] =
V_245 [ 0 ] / V_257 ;
V_244 -> V_241 . integer . V_241 [ 1 ] =
V_245 [ 1 ] / V_257 ;
return 0 ;
}
static int F_143 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
short V_245 [ V_239 ] ;
V_245 [ 0 ] =
( V_244 -> V_241 . integer . V_241 [ 0 ] ) * V_257 ;
V_245 [ 1 ] =
( V_244 -> V_241 . integer . V_241 [ 1 ] ) * V_257 ;
V_246 = 1 ;
F_53 ( F_144 ( V_52 , V_245 ) ) ;
return V_246 ;
}
static int F_145 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_43 ) ;
V_213 . V_249 = V_250 |
V_251 ;
V_213 . V_184 = F_139 ;
V_213 . V_252 = F_141 ;
V_213 . V_253 = F_143 ;
V_213 . V_254 . V_39 = V_258 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_146 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
return F_147 ( V_233 , 1 , 3 , V_259 ) ;
}
static int F_148 ( struct V_230 * V_231 ,
struct V_243 * V_244 ,
T_1 (* F_149)( T_2 , T_1 * ) )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_260 , V_33 ;
V_33 = F_149 ( V_52 , & V_260 ) ;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = 0 ;
if ( V_33 )
return 0 ;
if ( V_260 == V_263 )
V_244 -> V_241 . V_261 . V_262 [ 0 ] = 1 ;
if ( V_260 == V_264 )
V_244 -> V_241 . V_261 . V_262 [ 0 ] = 2 ;
return 0 ;
}
static int F_150 ( struct V_230 * V_231 ,
struct V_243 * V_244 ,
T_1 (* F_149)( T_2 , T_1 ) )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_260 = V_263 ;
if ( V_244 -> V_241 . V_261 . V_262 [ 0 ] == 1 )
V_260 = V_263 ;
if ( V_244 -> V_241 . V_261 . V_262 [ 0 ] == 2 )
V_260 = V_264 ;
if ( F_149 ( V_52 , V_260 ) != 0 )
return - V_47 ;
return 1 ;
}
static int F_151 ( struct V_230 * V_231 ,
struct V_243 * V_244 ) {
return F_148 ( V_231 , V_244 ,
V_265 ) ;
}
static int F_152 ( struct V_230 * V_231 ,
struct V_243 * V_244 ) {
return F_150 ( V_231 , V_244 ,
V_266 ) ;
}
static int F_153 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
V_233 -> type = V_240 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . integer . F_48 = 0 ;
V_233 -> V_241 . integer . F_49 = 0X1F ;
V_233 -> V_241 . integer . V_242 = 1 ;
return 0 ;
}
static int F_154 ( struct V_230 * V_231 ,
struct V_243 * V_244 ) {
T_2 V_52 = V_231 -> V_217 ;
T_1 V_123 ;
F_53 ( F_155 (
V_52 , & V_123 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] = V_123 ;
return 0 ;
}
static int F_156 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_44 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_146 ;
V_213 . V_252 = F_151 ;
V_213 . V_253 = F_152 ;
if ( F_122 ( V_86 , & V_213 , V_49 ) < 0 )
return - V_47 ;
F_126 ( & V_213 , V_215 , L_45 ) ;
V_213 . V_249 =
V_267 | V_268 ;
V_213 . V_184 = F_153 ;
V_213 . V_252 = F_154 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_157 ( struct V_230 * V_231 ,
struct V_243 * V_244 ) {
return F_148 ( V_231 , V_244 ,
V_269 ) ;
}
static int F_158 ( struct V_230 * V_231 ,
struct V_243 * V_244 ) {
return F_150 ( V_231 , V_244 ,
V_270 ) ;
}
static int F_159 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_44 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_146 ;
V_213 . V_252 = F_157 ;
V_213 . V_253 = F_158 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_160 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_33 ;
short V_54 ;
T_1 V_271 [ 3 ] ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_161 ( V_52 ,
V_54 , & V_271 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_233 -> type = V_240 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . integer . F_48 = ( ( int ) V_271 [ 0 ] ) / V_257 ;
V_233 -> V_241 . integer . F_49 = ( ( int ) V_271 [ 1 ] ) / V_257 ;
V_233 -> V_241 . integer . V_242 = ( ( int ) V_271 [ 2 ] ) / V_257 ;
return 0 ;
}
static int F_162 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
short V_272 ;
F_53 ( F_163 ( V_52 , & V_272 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] = V_272 / V_257 ;
return 0 ;
}
static int F_164 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
short V_272 ;
V_272 = ( V_244 -> V_241 . integer . V_241 [ 0 ] ) * V_257 ;
F_53 ( F_165 ( V_52 , V_272 ) ) ;
return 1 ;
}
static int F_166 ( struct V_230 * V_231 ,
T_1 * V_273 , T_2 V_274 ) {
T_2 V_52 = V_231 -> V_217 ;
T_1 V_33 = 0 ;
T_2 V_275 ;
for ( V_275 = 0 ; V_275 < V_274 ; V_275 ++ ) {
V_33 = F_167 (
V_52 , V_275 , & V_273 [ V_275 ] ) ;
if ( V_33 != 0 )
break;
}
if ( V_33 && ( V_33 != V_276 ) )
return - V_170 ;
return V_275 ;
}
static int F_168 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_1 V_277 [ V_278 ] ;
int V_279 = 0 ;
V_279 = F_166 ( V_231 , V_277 ,
V_278 ) ;
if ( V_279 < 0 )
return V_279 ;
return F_147 ( V_233 , 1 , V_279 , V_280 ) ;
}
static int F_169 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_281 , V_54 ;
T_1 V_277 [ V_278 ] ;
T_2 V_279 = 0 ;
V_279 = F_166 ( V_231 , V_277 ,
V_278 ) ;
F_53 ( F_170 ( V_52 , & V_281 ) ) ;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = - 1 ;
for ( V_54 = 0 ; V_54 < V_278 ; V_54 ++ )
if ( V_277 [ V_54 ] == V_281 ) {
V_244 -> V_241 . V_261 . V_262 [ 0 ] = V_54 ;
break;
}
return 0 ;
}
static int F_171 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
unsigned int V_54 ;
T_1 V_281 ;
T_1 V_277 [ V_278 ] ;
T_2 V_279 = 0 ;
V_279 = F_166 ( V_231 , V_277 ,
V_278 ) ;
V_54 = V_244 -> V_241 . V_261 . V_262 [ 0 ] ;
if ( V_54 >= F_172 ( V_277 ) )
V_54 = F_172 ( V_277 ) - 1 ;
V_281 = V_277 [ V_54 ] ;
F_53 ( F_173 ( V_52 , V_281 ) ) ;
return 1 ;
}
static int F_174 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_33 ;
T_1 V_277 [ V_278 ] ;
T_1 V_279 = 0 , V_282 , V_54 ;
T_2 V_283 [ 3 ] , V_284 [ 3 ] ;
V_279 = F_166 ( V_231 , V_277 ,
V_278 ) ;
V_283 [ 0 ] = V_285 ;
V_283 [ 1 ] = 0 ;
V_283 [ 2 ] = V_285 ;
for ( V_282 = 0 ; V_282 < V_279 ; V_282 ++ ) {
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_175 ( V_52 ,
V_54 , V_277 [ V_282 ] ,
& V_284 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
if ( V_284 [ 2 ] <= 0 )
continue;
if ( V_284 [ 0 ] < V_283 [ 0 ] )
V_283 [ 0 ] = V_284 [ 0 ] ;
if ( V_284 [ 1 ] > V_283 [ 1 ] )
V_283 [ 1 ] = V_284 [ 1 ] ;
if ( V_284 [ 2 ] < V_283 [ 2 ] )
V_283 [ 2 ] = V_284 [ 2 ] ;
}
V_233 -> type = V_240 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . integer . F_48 = ( ( int ) V_283 [ 0 ] ) ;
V_233 -> V_241 . integer . F_49 = ( ( int ) V_283 [ 1 ] ) ;
V_233 -> V_241 . integer . V_242 = ( ( int ) V_283 [ 2 ] ) ;
return 0 ;
}
static int F_176 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_286 ;
F_53 ( F_177 ( V_52 , & V_286 ) ) ;
V_244 -> V_241 . integer . V_241 [ 0 ] = V_286 ;
return 0 ;
}
static int F_178 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_286 ;
V_286 = V_244 -> V_241 . integer . V_241 [ 0 ] ;
F_53 ( F_179 ( V_52 , V_286 ) ) ;
return 1 ;
}
static int F_180 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
V_213 . V_217 = V_215 -> V_52 ;
V_213 . V_249 = V_250 ;
if ( ! F_163 ( V_215 -> V_52 , NULL ) ) {
F_126 ( & V_213 , V_215 , L_46 ) ;
V_213 . V_184 = F_160 ;
V_213 . V_252 = F_162 ;
V_213 . V_253 = F_164 ;
if ( F_122 ( V_86 , & V_213 , V_49 ) < 0 )
return - V_47 ;
}
F_126 ( & V_213 , V_215 , L_47 ) ;
V_213 . V_184 = F_168 ;
V_213 . V_252 = F_169 ;
V_213 . V_253 = F_171 ;
if ( F_122 ( V_86 , & V_213 , V_49 ) < 0 )
return - V_47 ;
F_126 ( & V_213 , V_215 , L_48 ) ;
V_213 . V_184 = F_174 ;
V_213 . V_252 = F_176 ;
V_213 . V_253 = F_178 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_181 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_234 ;
T_1 V_33 ;
V_33 = F_129 ( V_52 , & V_234 ) ;
if ( V_33 )
V_234 = V_239 ;
V_233 -> type = V_240 ;
V_233 -> V_234 = V_234 ;
V_233 -> V_241 . integer . F_48 = 0 ;
V_233 -> V_241 . integer . F_49 = 0x7FFFFFFF ;
return 0 ;
}
static int F_182 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
short V_245 [ V_239 ] , V_275 ;
T_1 V_33 ;
V_33 = F_183 ( V_52 , V_245 ) ;
for ( V_275 = 0 ; V_275 < V_239 ; V_275 ++ ) {
if ( V_33 ) {
V_244 -> V_241 . integer . V_241 [ V_275 ] = 0 ;
} else if ( V_245 [ V_275 ] >= 0 ) {
V_244 -> V_241 . integer . V_241 [ V_275 ] =
V_245 [ V_275 ] << 16 ;
} else {
V_244 -> V_241 . integer . V_241 [ V_275 ] =
V_287 [ V_245 [ V_275 ] / - 1000 ] ;
}
}
return 0 ;
}
static int F_184 ( struct V_48 * V_49 ,
struct V_214 * V_215 , int V_288 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_49 ) ;
V_213 . V_249 =
V_267 | V_268 ;
V_213 . V_184 = F_181 ;
V_213 . V_252 = F_182 ;
V_213 . V_106 = V_288 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_185 ( struct V_230 * V_213 )
{
T_2 V_52 = V_213 -> V_217 ;
struct V_214 V_215 ;
int V_110 , V_33 ;
for ( V_110 = 0 ; V_110 < 32 ; V_110 ++ ) {
V_33 = F_186 ( V_52 , V_110 ,
& V_215 .
V_220 ,
& V_215 .
V_227 ) ;
if ( V_33 )
break;
}
return V_110 ;
}
static int F_187 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
int V_33 ;
T_1 V_220 , V_227 ;
T_2 V_52 = V_231 -> V_217 ;
V_233 -> type = V_289 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . V_261 . V_290 =
F_185 ( V_231 ) ;
if ( V_233 -> V_241 . V_261 . V_262 >= V_233 -> V_241 . V_261 . V_290 )
V_233 -> V_241 . V_261 . V_262 =
V_233 -> V_241 . V_261 . V_290 - 1 ;
V_33 =
F_186 ( V_52 ,
V_233 -> V_241 . V_261 . V_262 ,
& V_220 , & V_227 ) ;
sprintf ( V_233 -> V_241 . V_261 . V_40 , L_50 ,
V_226 [ V_220 - V_221 ] ,
V_227 ) ;
return 0 ;
}
static int F_188 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_291 , V_292 ;
T_1 V_220 , V_227 ;
int V_110 ;
F_53 ( F_189 ( V_52 ,
& V_291 , & V_292 ) ) ;
for ( V_110 = 0 ; V_110 < 256 ; V_110 ++ ) {
if ( F_186 ( V_52 , V_110 ,
& V_220 , & V_227 ) )
break;
if ( ( V_291 == V_220 )
&& ( V_292 == V_227 ) ) {
V_244 -> V_241 . V_261 . V_262 [ 0 ] = V_110 ;
return 0 ;
}
}
F_42 ( V_35
L_51 ,
V_52 , V_291 , V_292 ) ;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = 0 ;
return 0 ;
}
static int F_190 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
T_1 V_291 , V_292 ;
T_1 V_29 ;
V_246 = 1 ;
V_29 = F_186 ( V_52 ,
V_244 -> V_241 . V_261 . V_262 [ 0 ] ,
& V_291 , & V_292 ) ;
if ( ! V_29 )
F_53 (
F_191 ( V_52 ,
V_291 , V_292 ) ) ;
return V_246 ;
}
static int F_192 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_52 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_187 ;
V_213 . V_252 = F_188 ;
V_213 . V_253 = F_190 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_193 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
static const char * const V_293 [ V_294 + 1 ] = {
L_53 ,
L_54 , L_55 ,
L_56 , L_57 ,
L_58 , L_59
} ;
T_2 V_52 = V_231 -> V_217 ;
T_1 V_295 ;
int V_275 ;
const char * V_296 [ 6 ] ;
int V_297 = 0 ;
for ( V_275 = 0 ; V_275 < V_294 ; V_275 ++ )
if ( ! F_194 (
V_52 , V_275 , & V_295 ) ) {
V_296 [ V_297 ] = V_293 [ V_295 ] ;
V_297 ++ ;
}
if ( ! V_297 )
return - V_47 ;
return F_147 ( V_233 , 1 , V_297 , V_296 ) ;
}
static int F_195 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_1 V_295 ;
if ( F_196 ( V_52 , & V_295 ) )
V_295 = 1 ;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = V_295 - 1 ;
return 0 ;
}
static int F_197 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
V_246 = 1 ;
F_53 ( F_198 ( V_52 ,
V_244 -> V_241 . V_261 . V_262 [ 0 ] + 1 ) ) ;
return V_246 ;
}
static int F_199 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_210 V_213 ;
F_126 ( & V_213 , V_215 , L_60 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_193 ;
V_213 . V_252 = F_195 ;
V_213 . V_253 = F_197 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_200 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_231 -> V_85 ) ;
struct V_298 * V_299 = & V_49 -> V_300 ;
V_233 -> type = V_289 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . V_261 . V_290 = V_299 -> V_234 ;
if ( V_233 -> V_241 . V_261 . V_262 >= V_233 -> V_241 . V_261 . V_290 )
V_233 -> V_241 . V_261 . V_262 =
V_233 -> V_241 . V_261 . V_290 - 1 ;
strcpy ( V_233 -> V_241 . V_261 . V_40 ,
V_299 -> V_110 [ V_233 -> V_241 . V_261 . V_262 ] . V_40 ) ;
return 0 ;
}
static int F_201 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_231 -> V_85 ) ;
struct V_298 * V_299 = & V_49 -> V_300 ;
T_2 V_52 = V_231 -> V_217 ;
T_1 V_260 , V_301 = 0 ;
int V_275 ;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = 0 ;
if ( F_202 ( V_52 , & V_260 ) )
V_260 = 0 ;
if ( V_260 == V_302 )
if ( F_203 ( V_52 , & V_301 ) )
V_301 = 0 ;
for ( V_275 = 0 ; V_275 < V_299 -> V_234 ; V_275 ++ )
if ( ( V_299 -> V_110 [ V_275 ] . V_260 == V_260 ) &&
( V_299 -> V_110 [ V_275 ] . V_106 == V_301 ) )
break;
V_244 -> V_241 . V_261 . V_262 [ 0 ] = V_275 ;
return 0 ;
}
static int F_204 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_231 -> V_85 ) ;
struct V_298 * V_299 = & V_49 -> V_300 ;
unsigned int V_262 ;
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
V_246 = 1 ;
V_262 = V_244 -> V_241 . V_261 . V_262 [ 0 ] ;
if ( V_262 >= V_299 -> V_234 )
V_262 = V_299 -> V_234 - 1 ;
F_53 ( F_205 (
V_52 , V_299 -> V_110 [ V_262 ] . V_260 ) ) ;
if ( V_299 -> V_110 [ V_262 ] . V_260 == V_302 )
F_53 ( F_206 (
V_52 , V_299 -> V_110 [ V_262 ] . V_106 ) ) ;
return V_246 ;
}
static int F_207 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
V_233 -> type = V_240 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . integer . F_48 = 8000 ;
V_233 -> V_241 . integer . F_49 = 192000 ;
V_233 -> V_241 . integer . V_242 = 100 ;
return 0 ;
}
static int F_208 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_303 ;
T_1 V_29 ;
V_29 = F_209 ( V_52 , & V_303 ) ;
if ( ! V_29 )
V_244 -> V_241 . integer . V_241 [ 0 ] = V_303 ;
else
V_244 -> V_241 . integer . V_241 [ 0 ] = 0 ;
return 0 ;
}
static int F_210 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
int V_246 ;
T_2 V_52 = V_231 -> V_217 ;
V_246 = 1 ;
F_53 ( F_211 ( V_52 ,
V_244 -> V_241 . integer . V_241 [ 0 ] ) ) ;
return V_246 ;
}
static int F_212 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
V_233 -> type = V_240 ;
V_233 -> V_234 = 1 ;
V_233 -> V_241 . integer . F_48 = 8000 ;
V_233 -> V_241 . integer . F_49 = 192000 ;
V_233 -> V_241 . integer . V_242 = 100 ;
return 0 ;
}
static int F_213 ( struct V_230 * V_231 ,
struct V_243 * V_244 )
{
T_2 V_52 = V_231 -> V_217 ;
T_2 V_303 ;
T_1 V_29 ;
V_29 = F_46 ( V_52 , & V_303 ) ;
if ( ! V_29 )
V_244 -> V_241 . integer . V_241 [ 0 ] = V_303 ;
else
V_244 -> V_241 . integer . V_241 [ 0 ] = 0 ;
return 0 ;
}
static int F_214 ( struct V_48 * V_49 ,
struct V_214 * V_215 )
{
struct V_160 * V_86 ;
struct V_210 V_213 ;
struct V_298 * V_299 ;
T_2 V_304 = V_215 -> V_52 ;
int V_305 = 0 ;
int V_275 , V_306 ;
T_1 V_260 ;
if ( F_215 ( ! V_49 ) )
return - V_47 ;
V_86 = V_49 -> V_86 ;
V_299 = & V_49 -> V_300 ;
V_213 . V_217 = V_215 -> V_52 ;
V_299 -> V_307 = 0 ;
for ( V_275 = 0 ; V_275 <= V_308 ; V_275 ++ ) {
if ( F_216 ( V_304 ,
V_275 , & V_260 ) )
break;
V_299 -> V_110 [ V_275 ] . V_260 = V_260 ;
V_299 -> V_110 [ V_275 ] . V_106 = 0 ;
V_299 -> V_110 [ V_275 ] . V_40 = V_309 [ V_260 ] ;
if ( V_260 == V_302 )
V_305 = 1 ;
if ( V_260 == V_310 )
V_299 -> V_307 = 1 ;
}
if ( V_305 )
for ( V_306 = 1 ; V_306 < 8 ; V_306 ++ ) {
if ( F_217 ( V_304 ,
V_306 , V_302 ,
& V_260 ) )
break;
V_299 -> V_110 [ V_275 ] . V_260 =
V_302 ;
V_299 -> V_110 [ V_275 ] . V_106 = V_306 ;
V_299 -> V_110 [ V_275 ] . V_40 = V_309 [
V_306 + V_308 ] ;
V_275 ++ ;
}
V_299 -> V_234 = V_275 ;
F_126 ( & V_213 , V_215 , L_61 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_200 ;
V_213 . V_252 = F_201 ;
V_213 . V_253 = F_204 ;
if ( F_122 ( V_86 , & V_213 , V_49 ) < 0 )
return - V_47 ;
if ( V_299 -> V_307 ) {
F_126 ( & V_213 , V_215 , L_62 ) ;
V_213 . V_249 = V_250 ;
V_213 . V_184 = F_207 ;
V_213 . V_252 = F_208 ;
V_213 . V_253 = F_210 ;
if ( F_122 ( V_86 , & V_213 , V_49 ) < 0 )
return - V_47 ;
}
F_126 ( & V_213 , V_215 , L_63 ) ;
V_213 . V_249 =
V_267 | V_268 ;
V_213 . V_184 = F_212 ;
V_213 . V_252 = F_213 ;
return F_122 ( V_86 , & V_213 , V_49 ) ;
}
static int F_218 ( struct V_48 * V_49 )
{
struct V_160 * V_86 ;
unsigned int V_54 = 0 ;
unsigned int V_311 = 0 ;
int V_33 ;
struct V_214 V_215 , V_312 ;
if ( F_215 ( ! V_49 ) )
return - V_47 ;
V_86 = V_49 -> V_86 ;
strcpy ( V_86 -> V_313 , L_64 ) ;
V_33 =
F_219 ( V_49 -> V_104 -> V_105 -> V_106 ,
& V_49 -> V_61 ) ;
F_53 ( V_33 ) ;
if ( V_33 )
return - V_33 ;
memset ( & V_312 , 0 , sizeof( V_312 ) ) ;
V_312 . V_314 = - 1 ;
for ( V_54 = 0 ; V_54 < 2000 ; V_54 ++ ) {
V_33 = F_220 (
V_49 -> V_61 ,
V_54 ,
& V_215 . V_220 ,
& V_215 . V_227 ,
& V_215 . V_222 ,
& V_215 . V_229 ,
& V_215 . V_314 ,
& V_215 . V_52 ) ;
if ( V_33 ) {
if ( V_33 == V_315 ) {
if ( V_212 )
F_125 ( & V_49 -> V_64 -> V_65 ,
L_65 ,
V_54 ) ;
continue;
} else
break;
}
V_215 . V_220 -= V_221 ;
V_215 . V_222 -= V_223 ;
if ( ( V_215 . V_314 == V_312 . V_314 ) &&
( V_215 . V_220 == V_312 . V_220 ) &&
( V_215 . V_227 == V_312 . V_227 ) &&
( V_215 . V_222 == V_312 . V_222 ) &&
( V_215 . V_229 == V_312 . V_229 ) )
V_311 ++ ;
else
V_311 = 0 ;
V_312 = V_215 ;
switch ( V_215 . V_314 ) {
case V_316 :
V_33 = F_138 ( V_49 , & V_215 ) ;
break;
case V_317 :
V_33 = F_145 ( V_49 , & V_215 ) ;
break;
case V_318 :
V_33 = F_192 ( V_49 , & V_215 ) ;
break;
case V_319 :
V_33 = F_199 ( V_49 , & V_215 ) ;
break;
case V_320 :
V_33 = F_184 ( V_49 , & V_215 , V_311 ) ;
break;
case V_63 :
V_33 = F_214 (
V_49 , & V_215 ) ;
break;
case V_321 :
continue;
case V_322 :
V_33 = F_180 ( V_49 , & V_215 ) ;
break;
case V_323 :
V_33 = F_159 ( V_49 , & V_215 ) ;
break;
case V_324 :
V_33 = F_156 ( V_49 , & V_215 ) ;
break;
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
default:
if ( V_212 )
F_125 ( & V_49 -> V_64 -> V_65 ,
L_66 ,
V_54 ,
V_215 . V_314 ,
V_215 . V_220 ,
V_215 . V_227 ,
V_215 . V_222 ,
V_215 . V_229 ) ;
continue;
}
if ( V_33 < 0 )
return V_33 ;
}
if ( V_276 != V_33 )
F_53 ( V_33 ) ;
F_125 ( & V_49 -> V_64 -> V_65 , L_67 , V_54 ) ;
return 0 ;
}
static void
F_221 ( struct V_330 * V_331 ,
struct V_332 * V_17 )
{
struct V_48 * V_49 = V_331 -> V_85 ;
T_2 V_52 ;
T_2 V_303 = 0 ;
T_1 V_260 = 0 ;
T_1 V_203 ;
T_1 V_202 ;
T_1 V_333 ;
T_2 V_334 ;
T_1 type ;
int V_33 ;
F_222 ( V_17 , L_68 ) ;
F_53 ( F_117 ( V_49 -> V_104 -> V_105 -> V_106 ,
& V_203 , & V_202 ,
& V_333 , & V_334 , & type ) ) ;
F_222 ( V_17 ,
L_69
L_70 ,
type , V_49 -> V_104 -> V_105 -> V_106 ,
V_203 , V_202 ) ;
F_222 ( V_17 ,
L_71 ,
V_334 , ( ( V_333 >> 3 ) & 0xf ) + 'A' , V_333 & 0x7 ,
( ( V_333 >> 13 ) * 100 ) + ( ( V_333 >> 7 ) & 0x3f ) ) ;
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 ) {
V_33 = F_46 ( V_52 , & V_303 ) ;
V_33 += F_202 ( V_52 , & V_260 ) ;
if ( ! V_33 )
F_222 ( V_17 , L_72 ,
V_303 , V_309 [ V_260 ] ) ;
}
}
static void F_223 ( struct V_48 * V_49 )
{
struct V_330 * V_331 ;
if ( ! F_224 ( V_49 -> V_86 , L_73 , & V_331 ) )
F_225 ( V_331 , V_49 , F_221 ) ;
}
static int F_226 ( struct V_335 * V_193 , struct V_336 * V_336 )
{
if ( V_337 )
return 0 ;
else
return - V_338 ;
}
static int F_227 ( struct V_335 * V_193 , struct V_336 * V_336 )
{
if ( V_337 )
return F_228 ( V_336 ) ;
else
return - V_338 ;
}
static int F_229 ( struct V_335 * V_193 , struct V_336 * V_336 ,
unsigned int V_109 , unsigned long V_161 )
{
if ( V_337 )
return F_230 ( V_336 , V_109 , V_161 ) ;
else
return - V_338 ;
}
static int F_231 ( struct V_48 * V_49 , int V_199 )
{
struct V_335 * V_193 ;
int V_33 ;
V_33 = F_232 ( V_49 -> V_86 , L_74 , V_199 , & V_193 ) ;
if ( V_33 < 0 )
return V_33 ;
strcpy ( V_193 -> V_40 , L_75 ) ;
V_193 -> V_218 = V_339 ;
V_193 -> V_340 . V_341 = F_226 ;
V_193 -> V_340 . V_342 = F_229 ;
V_193 -> V_340 . V_343 = F_227 ;
V_193 -> V_85 = V_49 ;
return 0 ;
}
static int F_233 ( struct V_344 * V_344 ,
const struct V_345 * V_346 )
{
int V_33 ;
struct V_159 * V_104 ;
struct V_160 * V_86 ;
struct V_48 * V_49 ;
T_2 V_52 ;
T_2 V_1 ;
T_2 V_13 ;
static int V_65 ;
if ( V_65 >= V_347 )
return - V_338 ;
if ( ! V_348 [ V_65 ] ) {
V_65 ++ ;
return - V_349 ;
}
V_33 = F_234 ( V_344 , V_346 ) ;
if ( V_33 < 0 )
return V_33 ;
V_104 = F_235 ( V_344 ) ;
V_13 = V_104 -> V_105 -> V_106 ;
V_33 = F_236 ( & V_344 -> V_65 , V_13 , V_350 [ V_13 ] ,
V_351 , sizeof( struct V_48 ) , & V_86 ) ;
if ( V_33 < 0 ) {
V_33 = F_236 ( & V_344 -> V_65 , V_106 [ V_65 ] , V_350 [ V_65 ] ,
V_351 , sizeof( struct V_48 ) ,
& V_86 ) ;
if ( V_33 < 0 )
return V_33 ;
F_237 ( & V_344 -> V_65 , L_76 ,
V_13 , V_86 -> V_116 ) ;
}
V_49 = V_86 -> V_85 ;
V_49 -> V_86 = V_86 ;
V_49 -> V_64 = V_344 ;
V_49 -> V_104 = V_104 ;
V_104 -> V_160 = V_86 ;
V_33 = F_238 ( V_13 ,
V_352 ,
NULL , & V_49 -> V_119 ) ;
if ( V_33 )
V_49 -> V_119 = 0 ;
V_33 = F_238 ( V_13 ,
V_353 ,
& V_49 -> V_58 , NULL ) ;
if ( V_33 )
V_49 -> V_58 = 0 ;
V_33 = F_238 ( V_13 ,
V_354 ,
NULL , & V_49 -> V_108 ) ;
if ( V_33 )
V_49 -> V_108 = 512 ;
if ( V_104 -> V_158 ) {
V_49 -> V_120 = F_65 ;
V_49 -> V_122 = F_71 ;
F_239 ( & V_49 -> V_102 , F_85 ,
( unsigned long ) V_104 ) ;
V_104 -> V_355 = F_87 ;
} else {
V_49 -> V_120 = F_61 ;
V_49 -> V_122 = F_63 ;
}
F_53 ( F_113 ( V_13 ,
0 , & V_1 ) ) ;
V_33 = F_240 ( V_1 ) ;
V_49 -> V_92 = ( ! V_33 ) ;
F_53 ( F_115 ( V_1 ) ) ;
if ( ! V_49 -> V_92 )
V_49 -> V_108 *= 2 ;
V_33 = F_238 ( V_13 ,
V_356 ,
& V_49 -> V_196 , & V_49 -> V_165 ) ;
if ( V_33 ) {
V_49 -> V_196 = 2 ;
V_49 -> V_165 = 2 ;
}
if ( V_49 -> V_165 > 2 ) {
V_49 -> V_183 = V_49 -> V_165 ;
V_49 -> V_198 = V_49 -> V_196 ;
V_49 -> V_119 = 0 ;
} else {
V_49 -> V_183 = 1 ;
V_49 -> V_198 = 1 ;
}
F_125 ( & V_344 -> V_65 , L_77 ,
V_49 -> V_92 ,
V_49 -> V_119 ,
V_49 -> V_58 ,
V_49 -> V_108
) ;
V_33 = F_116 ( V_49 , 0 ) ;
if ( V_33 < 0 ) {
F_45 ( & V_344 -> V_65 , L_78 ) ;
goto V_357;
}
V_33 = F_218 ( V_49 ) ;
if ( V_33 < 0 ) {
F_45 ( & V_344 -> V_65 , L_79 ) ;
goto V_357;
}
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_211 (
V_52 , V_358 ) ;
F_223 ( V_49 ) ;
F_231 ( V_49 , 0 ) ;
strcpy ( V_86 -> V_359 , L_80 ) ;
sprintf ( V_86 -> V_360 , L_81 ,
V_49 -> V_104 -> V_105 -> type ) ;
sprintf ( V_86 -> V_361 , L_82 ,
V_86 -> V_360 , V_13 ) ;
V_33 = F_241 ( V_86 ) ;
if ( ! V_33 ) {
V_65 ++ ;
return 0 ;
}
V_357:
F_242 ( V_86 ) ;
F_45 ( & V_344 -> V_65 , L_83 , V_33 ) ;
return V_33 ;
}
static void F_243 ( struct V_344 * V_344 )
{
struct V_159 * V_104 = F_235 ( V_344 ) ;
struct V_48 * V_49 = V_104 -> V_160 -> V_85 ;
if ( V_104 -> V_158 ) {
V_104 -> V_355 = NULL ;
F_53 ( F_70 ( V_104 -> V_105 -> V_106 ,
V_107 , 0 , 0 ) ) ;
F_244 ( & V_49 -> V_102 ) ;
}
F_242 ( V_104 -> V_160 ) ;
V_104 -> V_160 = NULL ;
F_245 ( V_344 ) ;
}
static int T_7 F_246 ( void )
{
F_247 () ;
return F_248 ( & V_359 ) ;
}
static void T_8 F_249 ( void )
{
F_250 ( & V_359 ) ;
F_251 () ;
}
