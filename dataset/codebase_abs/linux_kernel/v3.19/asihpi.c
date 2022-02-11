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
V_84 -> V_99 . V_100 = V_101 + V_97 ;
V_84 -> V_102 = 1 ;
F_62 ( & V_84 -> V_99 ) ;
}
static void F_63 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
V_84 -> V_102 = 0 ;
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
F_68 ( & V_86 -> V_103 ) ;
V_86 -> V_104 = V_84 ;
F_69 ( & V_86 -> V_103 ) ;
F_53 ( F_70 ( V_86 -> V_105 -> V_106 -> V_107 ,
V_108 ,
V_86 -> V_109 , 0 ) ) ;
}
static void F_71 ( struct V_36 * V_37 )
{
struct V_83 * V_84 ;
struct V_48 * V_86 ;
F_66 ( ! V_37 ) ;
V_84 = (struct V_83 * ) V_37 -> V_82 -> V_85 ;
V_86 = F_51 ( V_37 ) ;
F_53 ( F_70 ( V_86 -> V_105 -> V_106 -> V_107 ,
V_108 , 0 , 0 ) ) ;
if ( F_67 () )
V_86 -> V_104 = NULL ;
else {
F_68 ( & V_86 -> V_103 ) ;
V_86 -> V_104 = NULL ;
F_69 ( & V_86 -> V_103 ) ;
}
}
static int F_72 ( struct V_36 * V_37 ,
int V_110 )
{
struct V_83 * V_84 = V_37 -> V_82 -> V_85 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_36 * V_111 ;
T_1 V_29 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
switch ( V_110 ) {
case V_112 :
F_29 ( L_10 , V_40 ) ;
F_73 (s, substream) {
struct V_81 * V_82 = V_111 -> V_82 ;
struct V_83 * V_113 = V_82 -> V_85 ;
if ( F_51 ( V_111 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_111 -> V_89 )
continue;
V_113 -> V_114 = 0 ;
if ( V_111 -> V_89 == V_115 ) {
unsigned int V_116 = V_113 -> V_96 * 1 ;
F_74 ( L_11 , V_111 -> V_117 , V_116 ) ;
F_53 ( F_75 (
V_113 -> V_1 ,
& V_82 -> V_118 [ 0 ] ,
V_116 ,
& V_113 -> V_43 ) ) ;
V_113 -> V_119 = V_116 ;
}
if ( V_86 -> V_120 ) {
F_29 ( L_12 , V_111 -> V_117 ) ;
V_29 = F_16 (
V_84 -> V_1 ,
V_113 -> V_1 ) ;
if ( ! V_29 ) {
F_76 ( V_111 , V_37 ) ;
} else {
F_53 ( V_29 ) ;
break;
}
} else
break;
}
V_86 -> V_121 ( V_37 ) ;
if ( ( V_37 -> V_89 == V_90 ) ||
! V_86 -> V_92 )
F_53 ( F_7 ( V_84 -> V_1 ) ) ;
break;
case V_122 :
F_29 ( L_13 , V_40 ) ;
V_86 -> V_123 ( V_37 ) ;
F_73 (s, substream) {
if ( F_51 ( V_111 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_111 -> V_89 )
continue;
V_111 -> V_82 -> V_124 -> V_125 = V_126 ;
if ( V_86 -> V_120 ) {
F_29 ( L_12 , V_111 -> V_117 ) ;
F_76 ( V_111 , V_37 ) ;
} else
break;
}
F_53 ( F_10 ( V_84 -> V_1 ) ) ;
if ( V_37 -> V_89 == V_115 )
F_53 (
F_77 ( V_84 -> V_1 ) ) ;
if ( V_86 -> V_120 )
F_53 ( F_19 ( V_84 -> V_1 ) ) ;
break;
case V_127 :
F_29 ( L_14 , V_40 ) ;
V_86 -> V_121 ( V_37 ) ;
F_53 ( F_7 ( V_84 -> V_1 ) ) ;
break;
case V_128 :
F_29 ( L_15 , V_40 ) ;
V_86 -> V_123 ( V_37 ) ;
F_53 ( F_10 ( V_84 -> V_1 ) ) ;
break;
default:
F_42 ( V_129 L_16 ) ;
return - V_47 ;
}
return 0 ;
}
static inline unsigned int F_78 ( unsigned int V_130 , unsigned int V_131 ,
unsigned long int V_132 )
{
unsigned int V_133 ;
if ( ( ( V_130 - V_131 ) % V_132 ) < ( V_132 / 2 ) )
V_133 = V_131 ;
else
V_133 = V_130 ;
return V_133 ;
}
static void F_79 ( unsigned long V_134 )
{
struct V_83 * V_84 = (struct V_83 * ) V_134 ;
struct V_36 * V_37 = V_84 -> V_37 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_81 * V_82 ;
struct V_36 * V_111 ;
unsigned int V_135 = 0 ;
unsigned int V_136 , V_137 = 0 ;
unsigned int V_138 , V_139 , V_140 ;
int V_141 = 1 ;
int V_142 = 0 ;
T_1 V_125 ;
T_2 V_18 , V_143 , V_144 , V_145 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_73 (s, substream) {
struct V_83 * V_113 = V_111 -> V_82 -> V_85 ;
V_82 = V_111 -> V_82 ;
if ( F_51 ( V_111 ) != V_86 )
continue;
if ( V_37 -> V_89 != V_111 -> V_89 )
continue;
F_53 ( F_13 (
V_113 -> V_1 , & V_125 ,
& V_18 , & V_143 ,
& V_144 , & V_145 ) ) ;
V_82 -> V_146 = V_145 ;
if ( ! V_86 -> V_92 )
V_145 = V_143 ;
if ( V_111 -> V_89 == V_115 ) {
V_136 = V_113 -> V_119 - V_143 ;
if ( V_125 == V_147 ) {
if ( V_143 == 0 ) {
F_53 ( F_7 ( V_113 -> V_1 ) ) ;
F_29 ( L_17 , V_111 -> V_117 ) ;
V_113 -> V_114 = 0 ;
}
} else if ( V_125 == V_148 ) {
F_42 ( V_35 L_18 ,
V_111 -> V_117 ) ;
V_113 -> V_114 ++ ;
if ( V_113 -> V_114 > 20 ) {
F_80 ( V_111 ) ;
continue;
}
} else {
V_113 -> V_114 = 0 ;
}
} else
V_136 = V_143 + V_113 -> V_119 ;
if ( V_141 ) {
V_137 = V_136 ;
V_135 = ( V_136 - V_113 -> V_149 ) % V_113 -> V_95 ;
V_141 = 0 ;
} else {
V_137 =
F_78 ( V_137 , V_136 , V_150 + 1L ) ;
V_135 = F_48 (
( V_136 - V_113 -> V_149 ) % V_113 -> V_95 ,
V_135 ) ;
}
F_74 (
L_19 ,
V_40 , V_111 -> V_117 , V_125 ,
V_113 -> V_149 ,
V_113 -> V_119 ,
V_136 ,
( int ) V_143 ,
( int ) V_145 ,
V_18 - V_143 ,
( unsigned long ) F_81 ( V_82 ,
V_82 -> V_124 -> V_151 ) ,
( unsigned long ) F_81 ( V_82 ,
V_82 -> V_152 -> V_153 )
) ;
V_142 ++ ;
}
V_136 = V_137 ;
V_138 = V_135 % V_84 -> V_96 ;
V_139 = V_135 - V_138 ;
if ( V_139 && ( V_145 > V_84 -> V_96 ) )
V_140 = ( ( V_145 - V_84 -> V_96 ) * V_98 / V_84 -> V_88 ) ;
else
V_140 = ( ( V_84 -> V_96 - V_138 ) * V_98 / V_84 -> V_88 ) ;
V_140 = F_49 ( V_140 , 1U ) ;
V_84 -> V_99 . V_100 = V_101 + V_140 ;
F_74 ( L_20 ,
V_140 , V_136 , V_135 , V_139 ) ;
F_73 (s, substream) {
struct V_83 * V_113 = V_111 -> V_82 -> V_85 ;
V_82 = V_111 -> V_82 ;
if ( V_37 -> V_89 != V_111 -> V_89 )
continue;
V_113 -> V_136 = V_136 ;
if ( V_139 &&
( ( V_145 <= V_113 -> V_96 ) ||
( V_111 -> V_89 == V_90 ) ) )
{
unsigned int V_154 = V_113 -> V_119 % V_113 -> V_95 ;
unsigned int V_155 , V_156 ;
char * V_157 = & V_111 -> V_82 -> V_118 [ V_154 ] ;
if ( V_86 -> V_92 ) {
V_155 = V_139 ;
V_156 = 0 ;
} else {
V_155 = F_48 ( V_139 , V_113 -> V_95 - V_154 ) ;
V_156 = V_139 - V_155 ;
}
if ( V_111 -> V_89 == V_115 ) {
F_74 ( L_21 ,
V_111 -> V_117 , V_155 , V_154 ) ;
F_53 (
F_75 (
V_113 -> V_1 , V_157 , V_155 ,
& V_113 -> V_43 ) ) ;
if ( V_156 ) {
V_157 = V_111 -> V_82 -> V_118 ;
F_74 ( L_22 ,
V_111 -> V_117 ,
V_139 - V_155 , V_154 ) ;
F_53 (
F_75 (
V_113 -> V_1 , V_157 ,
V_139 - V_155 ,
& V_113 -> V_43 ) ) ;
}
} else {
F_74 ( L_23 ,
V_111 -> V_117 , V_155 ) ;
F_53 (
F_82 (
V_113 -> V_1 ,
V_157 , V_155 ) ) ;
if ( V_156 ) {
V_157 = V_111 -> V_82 -> V_118 ;
F_74 ( L_24 ,
V_111 -> V_117 , V_156 ) ;
F_53 (
F_82 (
V_113 -> V_1 ,
V_157 , V_156 ) ) ;
}
}
V_113 -> V_119 += V_139 ;
V_113 -> V_149 += V_139 ;
F_83 ( V_111 ) ;
}
}
if ( ! V_86 -> V_105 -> V_158 && V_84 -> V_102 )
F_62 ( & V_84 -> V_99 ) ;
}
static void F_84 ( unsigned long V_134 )
{
struct V_159 * V_130 = (struct V_159 * ) V_134 ;
struct V_48 * V_49 ;
F_85 ( ! V_130 || ! V_130 -> V_160 || ! V_130 -> V_160 -> V_85 ) ;
V_49 = (struct V_48 * ) V_130 -> V_160 -> V_85 ;
if ( V_49 -> V_104 )
F_79 (
( unsigned long ) V_49 -> V_104 ) ;
}
static void F_86 ( struct V_159 * V_130 )
{
struct V_48 * V_49 ;
F_85 ( ! V_130 || ! V_130 -> V_160 || ! V_130 -> V_160 -> V_85 ) ;
V_49 = (struct V_48 * ) V_130 -> V_160 -> V_85 ;
F_87 ( & V_49 -> V_103 ) ;
}
static int F_88 ( struct V_36 * V_37 ,
unsigned int V_110 , void * V_161 )
{
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_74 ( V_162 L_25 , V_40 , V_110 ) ;
return F_89 ( V_37 , V_110 , V_161 ) ;
}
static int F_90 ( struct V_36 *
V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_29 ( L_26 , V_37 -> V_117 ) ;
F_53 ( F_77 ( V_84 -> V_1 ) ) ;
V_84 -> V_119 = 0 ;
V_84 -> V_136 = 0 ;
V_84 -> V_149 = 0 ;
return 0 ;
}
static T_4
F_91 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
T_4 V_163 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
V_163 = F_92 ( V_82 , V_84 -> V_136 % V_84 -> V_95 ) ;
F_74 ( L_27 , V_40 , ( unsigned long ) V_163 ) ;
return V_163 ;
}
static T_5 F_93 ( struct V_48 * V_49 ,
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
V_33 = F_94 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_164 |= F_95 ( V_46 [ V_43 ] ) ;
}
return V_164 ;
}
static int F_96 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_50 V_166 ;
int V_33 ;
V_84 = F_97 ( sizeof( * V_84 ) , V_167 ) ;
if ( V_84 == NULL )
return - V_94 ;
V_33 = F_98 ( V_86 -> V_105 -> V_106 -> V_107 ,
V_37 -> V_117 , & V_84 -> V_1 ) ;
F_53 ( V_33 ) ;
if ( V_33 )
F_60 ( V_84 ) ;
if ( V_33 == V_168 )
return - V_169 ;
if ( V_33 )
return - V_170 ;
F_99 ( & V_84 -> V_99 ) ;
V_84 -> V_99 . V_134 = ( unsigned long ) V_84 ;
V_84 -> V_99 . V_171 = F_79 ;
V_84 -> V_37 = V_37 ;
V_82 -> V_85 = V_84 ;
V_82 -> V_172 = F_59 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( ! V_86 -> V_105 -> V_158 ) {
V_166 . V_173 = V_174 ;
V_166 . V_175 = V_176 ;
V_166 . V_177 = V_174 / V_178 ;
V_166 . V_179 = V_178 ;
V_166 . V_180 = V_174 / V_176 ;
} else {
T_6 V_181 = V_86 -> V_109 *
V_86 -> V_165 ;
V_166 . V_173 = V_174 ;
V_166 . V_175 = V_181 ;
V_166 . V_177 = V_174 / V_178 ;
V_166 . V_179 = V_178 ;
V_166 . V_180 = V_174 / V_181 ;
}
V_166 . V_182 = V_86 -> V_165 ;
V_166 . V_183 = V_86 -> V_184 ;
V_166 . V_164 =
F_93 ( V_86 , V_84 -> V_1 ) ;
F_43 ( V_86 , & V_166 ) ;
V_166 . V_185 = V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 ;
if ( V_86 -> V_120 ) {
V_166 . V_185 |= V_193 ;
F_100 ( V_37 ) ;
}
V_82 -> V_194 = V_166 ;
if ( V_86 -> V_92 )
V_33 = F_101 ( V_82 , 0 ,
V_195 ) ;
if ( V_33 < 0 )
return V_33 ;
F_102 ( V_82 , 0 , V_196 ,
V_86 -> V_109 ) ;
F_103 ( V_82 , V_196 ,
V_86 -> V_109 , V_150 ) ;
F_29 ( L_28 ) ;
return 0 ;
}
static int F_104 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_53 ( F_105 ( V_84 -> V_1 ) ) ;
F_29 ( L_29 ) ;
return 0 ;
}
static T_4
F_106 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_74 ( L_30 , V_40 , V_84 -> V_136 ) ;
return F_92 ( V_82 , V_84 -> V_136 % V_84 -> V_95 ) ;
}
static int F_107 ( struct V_36 * V_37 ,
unsigned int V_110 , void * V_161 )
{
return F_89 ( V_37 , V_110 , V_161 ) ;
}
static int F_108 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_83 * V_84 = V_82 -> V_85 ;
F_53 ( F_55 ( V_84 -> V_1 ) ) ;
V_84 -> V_119 = 0 ;
V_84 -> V_136 = 0 ;
V_84 -> V_149 = 0 ;
F_29 ( L_31 , V_37 -> V_117 ) ;
return 0 ;
}
static T_5 F_109 ( struct V_48 * V_49 ,
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
V_33 = F_54 ( & V_42 , V_49 -> V_197 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_110 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_164 |= F_95 ( V_46 [ V_43 ] ) ;
}
return V_164 ;
}
static int F_111 ( struct V_36 * V_37 )
{
struct V_81 * V_82 = V_37 -> V_82 ;
struct V_48 * V_86 = F_51 ( V_37 ) ;
struct V_83 * V_84 ;
struct V_50 V_198 ;
int V_33 ;
V_84 = F_97 ( sizeof( * V_84 ) , V_167 ) ;
if ( V_84 == NULL )
return - V_94 ;
F_29 ( L_32 ,
V_86 -> V_105 -> V_106 -> V_107 , V_37 -> V_117 ) ;
V_33 = F_53 (
F_112 ( V_86 -> V_105 -> V_106 -> V_107 ,
V_37 -> V_117 , & V_84 -> V_1 ) ) ;
if ( V_33 )
F_60 ( V_84 ) ;
if ( V_33 == V_168 )
return - V_169 ;
if ( V_33 )
return - V_170 ;
F_99 ( & V_84 -> V_99 ) ;
V_84 -> V_99 . V_134 = ( unsigned long ) V_84 ;
V_84 -> V_99 . V_171 = F_79 ;
V_84 -> V_37 = V_37 ;
V_82 -> V_85 = V_84 ;
V_82 -> V_172 = F_59 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
if ( ! V_86 -> V_105 -> V_158 ) {
V_198 . V_173 = V_174 ;
V_198 . V_175 = V_176 ;
V_198 . V_177 = V_174 / V_178 ;
V_198 . V_179 = V_178 ;
V_198 . V_180 = V_174 / V_176 ;
} else {
T_6 V_181 = V_86 -> V_109 *
V_86 -> V_165 ;
V_198 . V_173 = V_174 ;
V_198 . V_175 = V_181 ;
V_198 . V_177 = V_174 / V_178 ;
V_198 . V_179 = V_178 ;
V_198 . V_180 = V_174 / V_181 ;
}
V_198 . V_182 = V_86 -> V_197 ;
V_198 . V_183 = V_86 -> V_199 ;
V_198 . V_164 =
F_109 ( V_86 , V_84 -> V_1 ) ;
F_43 ( V_86 , & V_198 ) ;
V_198 . V_185 = V_186 |
V_191 |
V_192 ;
if ( V_86 -> V_120 )
V_198 . V_185 |= V_193 ;
V_82 -> V_194 = V_198 ;
if ( V_86 -> V_92 )
V_33 = F_101 ( V_82 , 0 ,
V_195 ) ;
if ( V_33 < 0 )
return V_33 ;
F_102 ( V_82 , 0 , V_196 ,
V_86 -> V_109 ) ;
F_103 ( V_82 , V_196 ,
V_86 -> V_109 , V_150 ) ;
F_100 ( V_37 ) ;
return 0 ;
}
static int F_113 ( struct V_36 * V_37 )
{
struct V_83 * V_84 = V_37 -> V_82 -> V_85 ;
F_53 ( F_114 ( V_84 -> V_1 ) ) ;
return 0 ;
}
static int F_115 ( struct V_48 * V_49 , int V_200 )
{
struct V_201 * V_202 ;
int V_33 ;
T_1 V_203 , V_204 , V_205 ;
T_2 V_206 ;
V_33 = F_116 ( V_49 -> V_105 -> V_106 -> V_107 ,
& V_204 , & V_203 ,
& V_205 , & V_206 , & V_205 ) ;
V_33 = F_117 ( V_49 -> V_86 , L_33 , V_200 ,
V_204 , V_203 , & V_202 ) ;
if ( V_33 < 0 )
return V_33 ;
F_118 ( V_202 , V_115 ,
& V_207 ) ;
F_118 ( V_202 , V_90 ,
& V_208 ) ;
V_202 -> V_85 = V_49 ;
V_202 -> V_209 = 0 ;
strcpy ( V_202 -> V_40 , L_33 ) ;
F_119 ( V_202 , V_210 ,
F_120 ( V_49 -> V_64 ) ,
64 * 1024 , V_174 ) ;
return 0 ;
}
static inline int F_121 ( struct V_160 * V_86 , struct V_211 * V_212 ,
struct V_48 * V_49 )
{
int V_33 ;
V_33 = F_122 ( V_86 , F_123 ( V_212 , V_49 ) ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_213 )
F_124 ( & V_49 -> V_64 -> V_65 , L_34 , V_212 -> V_40 , V_212 -> V_107 ) ;
return 0 ;
}
static void F_125 ( struct V_211 * V_214 ,
struct V_215 * V_216 ,
char * V_40 )
{
char * V_217 ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
V_214 -> V_40 = V_216 -> V_40 ;
V_214 -> V_218 = V_216 -> V_52 ;
V_214 -> V_219 = V_220 ;
V_214 -> V_107 = 0 ;
if ( V_216 -> V_221 + V_222 == V_62 )
V_217 = L_35 ;
else if ( V_216 -> V_223 + V_224 == V_225 )
V_217 = L_36 ;
else if ( ( V_216 -> V_221 + V_222 != V_226 ) &&
( ! V_216 -> V_223 ) )
V_217 = L_36 ;
else if ( V_216 -> V_221 &&
( V_216 -> V_221 + V_222 != V_226 ) &&
( V_216 -> V_223 ) )
V_217 = L_37 ;
else
V_217 = L_38 ;
if ( V_216 -> V_221 && V_216 -> V_223 )
sprintf ( V_216 -> V_40 , L_39 ,
V_227 [ V_216 -> V_221 ] ,
V_216 -> V_228 ,
V_229 [ V_216 -> V_223 ] ,
V_216 -> V_230 ,
V_217 , V_40 ) ;
else if ( V_216 -> V_223 ) {
sprintf ( V_216 -> V_40 , L_40 ,
V_229 [ V_216 -> V_223 ] ,
V_216 -> V_230 ,
V_217 , V_40 ) ;
} else {
sprintf ( V_216 -> V_40 , L_40 ,
V_227 [ V_216 -> V_221 ] ,
V_216 -> V_228 ,
V_217 , V_40 ) ;
}
}
static int F_126 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_235 ;
T_1 V_33 ;
short V_236 ;
short V_237 ;
short V_238 ;
V_33 = F_127 ( V_52 ,
& V_236 , & V_237 , & V_238 ) ;
if ( V_33 ) {
V_237 = 0 ;
V_236 = - 10000 ;
V_238 = V_239 ;
}
V_33 = F_128 ( V_52 , & V_235 ) ;
if ( V_33 )
V_235 = V_240 ;
V_234 -> type = V_241 ;
V_234 -> V_235 = V_235 ;
V_234 -> V_242 . integer . F_48 = V_236 / V_239 ;
V_234 -> V_242 . integer . F_49 = V_237 / V_239 ;
V_234 -> V_242 . integer . V_243 = V_238 / V_239 ;
return 0 ;
}
static int F_129 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
short V_246 [ V_240 ] ;
F_53 ( F_130 ( V_52 , V_246 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] = V_246 [ 0 ] / V_239 ;
V_245 -> V_242 . integer . V_242 [ 1 ] = V_246 [ 1 ] / V_239 ;
return 0 ;
}
static int F_131 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
short V_246 [ V_240 ] ;
V_246 [ 0 ] =
( V_245 -> V_242 . integer . V_242 [ 0 ] ) * V_239 ;
V_246 [ 1 ] =
( V_245 -> V_242 . integer . V_242 [ 1 ] ) * V_239 ;
V_247 = 1 ;
F_53 ( F_132 ( V_52 , V_246 ) ) ;
return V_247 ;
}
static int F_133 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_248 ;
F_53 ( F_134 ( V_52 , & V_248 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] = V_248 ? 0 : 1 ;
return 0 ;
}
static int F_135 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
int V_247 = 1 ;
int V_248 = V_245 -> V_242 . integer . V_242 [ 0 ] ? 0 : V_249 ;
F_53 ( F_136 ( V_52 , V_248 ) ) ;
return V_247 ;
}
static int F_137 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
int V_33 ;
T_2 V_248 ;
F_125 ( & V_214 , V_216 , L_41 ) ;
V_214 . V_250 = V_251 |
V_252 ;
V_214 . V_185 = F_126 ;
V_214 . V_253 = F_129 ;
V_214 . V_254 = F_131 ;
V_214 . V_255 . V_39 = V_256 ;
V_33 = F_121 ( V_86 , & V_214 , V_49 ) ;
if ( V_33 )
return V_33 ;
if ( F_134 ( V_216 -> V_52 , & V_248 ) == 0 ) {
F_125 ( & V_214 , V_216 , L_42 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = V_257 ;
V_214 . V_253 = F_133 ;
V_214 . V_254 = F_135 ;
V_33 = F_121 ( V_86 , & V_214 , V_49 ) ;
}
return V_33 ;
}
static int F_138 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_33 ;
short V_236 ;
short V_237 ;
short V_238 ;
V_33 =
F_139 ( V_52 , & V_236 ,
& V_237 , & V_238 ) ;
if ( V_33 ) {
V_237 = 2400 ;
V_236 = - 1000 ;
V_238 = 100 ;
}
V_234 -> type = V_241 ;
V_234 -> V_235 = 2 ;
V_234 -> V_242 . integer . F_48 = V_236 / V_258 ;
V_234 -> V_242 . integer . F_49 = V_237 / V_258 ;
V_234 -> V_242 . integer . V_243 = V_238 / V_258 ;
return 0 ;
}
static int F_140 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
short V_246 [ V_240 ] ;
F_53 ( F_141 ( V_52 , V_246 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] =
V_246 [ 0 ] / V_258 ;
V_245 -> V_242 . integer . V_242 [ 1 ] =
V_246 [ 1 ] / V_258 ;
return 0 ;
}
static int F_142 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
short V_246 [ V_240 ] ;
V_246 [ 0 ] =
( V_245 -> V_242 . integer . V_242 [ 0 ] ) * V_258 ;
V_246 [ 1 ] =
( V_245 -> V_242 . integer . V_242 [ 1 ] ) * V_258 ;
V_247 = 1 ;
F_53 ( F_143 ( V_52 , V_246 ) ) ;
return V_247 ;
}
static int F_144 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_43 ) ;
V_214 . V_250 = V_251 |
V_252 ;
V_214 . V_185 = F_138 ;
V_214 . V_253 = F_140 ;
V_214 . V_254 = F_142 ;
V_214 . V_255 . V_39 = V_259 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_145 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
return F_146 ( V_234 , 1 , 3 , V_260 ) ;
}
static int F_147 ( struct V_231 * V_232 ,
struct V_244 * V_245 ,
T_1 (* F_148)( T_2 , T_1 * ) )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_261 , V_33 ;
V_33 = F_148 ( V_52 , & V_261 ) ;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = 0 ;
if ( V_33 )
return 0 ;
if ( V_261 == V_264 )
V_245 -> V_242 . V_262 . V_263 [ 0 ] = 1 ;
if ( V_261 == V_265 )
V_245 -> V_242 . V_262 . V_263 [ 0 ] = 2 ;
return 0 ;
}
static int F_149 ( struct V_231 * V_232 ,
struct V_244 * V_245 ,
T_1 (* F_148)( T_2 , T_1 ) )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_261 = V_264 ;
if ( V_245 -> V_242 . V_262 . V_263 [ 0 ] == 1 )
V_261 = V_264 ;
if ( V_245 -> V_242 . V_262 . V_263 [ 0 ] == 2 )
V_261 = V_265 ;
if ( F_148 ( V_52 , V_261 ) != 0 )
return - V_47 ;
return 1 ;
}
static int F_150 ( struct V_231 * V_232 ,
struct V_244 * V_245 ) {
return F_147 ( V_232 , V_245 ,
V_266 ) ;
}
static int F_151 ( struct V_231 * V_232 ,
struct V_244 * V_245 ) {
return F_149 ( V_232 , V_245 ,
V_267 ) ;
}
static int F_152 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
V_234 -> type = V_241 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . integer . F_48 = 0 ;
V_234 -> V_242 . integer . F_49 = 0X1F ;
V_234 -> V_242 . integer . V_243 = 1 ;
return 0 ;
}
static int F_153 ( struct V_231 * V_232 ,
struct V_244 * V_245 ) {
T_2 V_52 = V_232 -> V_218 ;
T_1 V_124 ;
F_53 ( F_154 (
V_52 , & V_124 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] = V_124 ;
return 0 ;
}
static int F_155 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_44 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_145 ;
V_214 . V_253 = F_150 ;
V_214 . V_254 = F_151 ;
if ( F_121 ( V_86 , & V_214 , V_49 ) < 0 )
return - V_47 ;
F_125 ( & V_214 , V_216 , L_45 ) ;
V_214 . V_250 =
V_268 | V_269 ;
V_214 . V_185 = F_152 ;
V_214 . V_253 = F_153 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_156 ( struct V_231 * V_232 ,
struct V_244 * V_245 ) {
return F_147 ( V_232 , V_245 ,
V_270 ) ;
}
static int F_157 ( struct V_231 * V_232 ,
struct V_244 * V_245 ) {
return F_149 ( V_232 , V_245 ,
V_271 ) ;
}
static int F_158 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_44 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_145 ;
V_214 . V_253 = F_156 ;
V_214 . V_254 = F_157 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_159 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_33 ;
short V_54 ;
T_1 V_272 [ 3 ] ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_160 ( V_52 ,
V_54 , & V_272 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_234 -> type = V_241 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . integer . F_48 = ( ( int ) V_272 [ 0 ] ) / V_258 ;
V_234 -> V_242 . integer . F_49 = ( ( int ) V_272 [ 1 ] ) / V_258 ;
V_234 -> V_242 . integer . V_243 = ( ( int ) V_272 [ 2 ] ) / V_258 ;
return 0 ;
}
static int F_161 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
short V_273 ;
F_53 ( F_162 ( V_52 , & V_273 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] = V_273 / V_258 ;
return 0 ;
}
static int F_163 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
short V_273 ;
V_273 = ( V_245 -> V_242 . integer . V_242 [ 0 ] ) * V_258 ;
F_53 ( F_164 ( V_52 , V_273 ) ) ;
return 1 ;
}
static int F_165 ( struct V_231 * V_232 ,
T_1 * V_274 , T_2 V_275 ) {
T_2 V_52 = V_232 -> V_218 ;
T_1 V_33 = 0 ;
T_2 V_276 ;
for ( V_276 = 0 ; V_276 < V_275 ; V_276 ++ ) {
V_33 = F_166 (
V_52 , V_276 , & V_274 [ V_276 ] ) ;
if ( V_33 != 0 )
break;
}
if ( V_33 && ( V_33 != V_277 ) )
return - V_170 ;
return V_276 ;
}
static int F_167 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_1 V_278 [ V_279 ] ;
int V_280 = 0 ;
V_280 = F_165 ( V_232 , V_278 ,
V_279 ) ;
if ( V_280 < 0 )
return V_280 ;
return F_146 ( V_234 , 1 , V_280 , V_281 ) ;
}
static int F_168 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_282 , V_54 ;
T_1 V_278 [ V_279 ] ;
T_2 V_280 = 0 ;
V_280 = F_165 ( V_232 , V_278 ,
V_279 ) ;
F_53 ( F_169 ( V_52 , & V_282 ) ) ;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = - 1 ;
for ( V_54 = 0 ; V_54 < V_279 ; V_54 ++ )
if ( V_278 [ V_54 ] == V_282 ) {
V_245 -> V_242 . V_262 . V_263 [ 0 ] = V_54 ;
break;
}
return 0 ;
}
static int F_170 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
unsigned int V_54 ;
T_1 V_282 ;
T_1 V_278 [ V_279 ] ;
T_2 V_280 = 0 ;
V_280 = F_165 ( V_232 , V_278 ,
V_279 ) ;
V_54 = V_245 -> V_242 . V_262 . V_263 [ 0 ] ;
if ( V_54 >= F_171 ( V_278 ) )
V_54 = F_171 ( V_278 ) - 1 ;
V_282 = V_278 [ V_54 ] ;
F_53 ( F_172 ( V_52 , V_282 ) ) ;
return 1 ;
}
static int F_173 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_33 ;
T_1 V_278 [ V_279 ] ;
T_1 V_280 = 0 , V_283 , V_54 ;
T_2 V_284 [ 3 ] , V_285 [ 3 ] ;
V_280 = F_165 ( V_232 , V_278 ,
V_279 ) ;
V_284 [ 0 ] = V_286 ;
V_284 [ 1 ] = 0 ;
V_284 [ 2 ] = V_286 ;
for ( V_283 = 0 ; V_283 < V_280 ; V_283 ++ ) {
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_174 ( V_52 ,
V_54 , V_278 [ V_283 ] ,
& V_285 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
if ( V_285 [ 2 ] <= 0 )
continue;
if ( V_285 [ 0 ] < V_284 [ 0 ] )
V_284 [ 0 ] = V_285 [ 0 ] ;
if ( V_285 [ 1 ] > V_284 [ 1 ] )
V_284 [ 1 ] = V_285 [ 1 ] ;
if ( V_285 [ 2 ] < V_284 [ 2 ] )
V_284 [ 2 ] = V_285 [ 2 ] ;
}
V_234 -> type = V_241 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . integer . F_48 = ( ( int ) V_284 [ 0 ] ) ;
V_234 -> V_242 . integer . F_49 = ( ( int ) V_284 [ 1 ] ) ;
V_234 -> V_242 . integer . V_243 = ( ( int ) V_284 [ 2 ] ) ;
return 0 ;
}
static int F_175 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_287 ;
F_53 ( F_176 ( V_52 , & V_287 ) ) ;
V_245 -> V_242 . integer . V_242 [ 0 ] = V_287 ;
return 0 ;
}
static int F_177 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_287 ;
V_287 = V_245 -> V_242 . integer . V_242 [ 0 ] ;
F_53 ( F_178 ( V_52 , V_287 ) ) ;
return 1 ;
}
static int F_179 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
V_214 . V_218 = V_216 -> V_52 ;
V_214 . V_250 = V_251 ;
if ( ! F_162 ( V_216 -> V_52 , NULL ) ) {
F_125 ( & V_214 , V_216 , L_46 ) ;
V_214 . V_185 = F_159 ;
V_214 . V_253 = F_161 ;
V_214 . V_254 = F_163 ;
if ( F_121 ( V_86 , & V_214 , V_49 ) < 0 )
return - V_47 ;
}
F_125 ( & V_214 , V_216 , L_47 ) ;
V_214 . V_185 = F_167 ;
V_214 . V_253 = F_168 ;
V_214 . V_254 = F_170 ;
if ( F_121 ( V_86 , & V_214 , V_49 ) < 0 )
return - V_47 ;
F_125 ( & V_214 , V_216 , L_48 ) ;
V_214 . V_185 = F_173 ;
V_214 . V_253 = F_175 ;
V_214 . V_254 = F_177 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_180 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_235 ;
T_1 V_33 ;
V_33 = F_128 ( V_52 , & V_235 ) ;
if ( V_33 )
V_235 = V_240 ;
V_234 -> type = V_241 ;
V_234 -> V_235 = V_235 ;
V_234 -> V_242 . integer . F_48 = 0 ;
V_234 -> V_242 . integer . F_49 = 0x7FFFFFFF ;
return 0 ;
}
static int F_181 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
short V_246 [ V_240 ] , V_276 ;
T_1 V_33 ;
V_33 = F_182 ( V_52 , V_246 ) ;
for ( V_276 = 0 ; V_276 < V_240 ; V_276 ++ ) {
if ( V_33 ) {
V_245 -> V_242 . integer . V_242 [ V_276 ] = 0 ;
} else if ( V_246 [ V_276 ] >= 0 ) {
V_245 -> V_242 . integer . V_242 [ V_276 ] =
V_246 [ V_276 ] << 16 ;
} else {
V_245 -> V_242 . integer . V_242 [ V_276 ] =
V_288 [ V_246 [ V_276 ] / - 1000 ] ;
}
}
return 0 ;
}
static int F_183 ( struct V_48 * V_49 ,
struct V_215 * V_216 , int V_289 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_49 ) ;
V_214 . V_250 =
V_268 | V_269 ;
V_214 . V_185 = F_180 ;
V_214 . V_253 = F_181 ;
V_214 . V_107 = V_289 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_184 ( struct V_231 * V_214 )
{
T_2 V_52 = V_214 -> V_218 ;
struct V_215 V_216 ;
int V_111 , V_33 ;
for ( V_111 = 0 ; V_111 < 32 ; V_111 ++ ) {
V_33 = F_185 ( V_52 , V_111 ,
& V_216 .
V_221 ,
& V_216 .
V_228 ) ;
if ( V_33 )
break;
}
return V_111 ;
}
static int F_186 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
int V_33 ;
T_1 V_221 , V_228 ;
T_2 V_52 = V_232 -> V_218 ;
V_234 -> type = V_290 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . V_262 . V_291 =
F_184 ( V_232 ) ;
if ( V_234 -> V_242 . V_262 . V_263 >= V_234 -> V_242 . V_262 . V_291 )
V_234 -> V_242 . V_262 . V_263 =
V_234 -> V_242 . V_262 . V_291 - 1 ;
V_33 =
F_185 ( V_52 ,
V_234 -> V_242 . V_262 . V_263 ,
& V_221 , & V_228 ) ;
sprintf ( V_234 -> V_242 . V_262 . V_40 , L_50 ,
V_227 [ V_221 - V_222 ] ,
V_228 ) ;
return 0 ;
}
static int F_187 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_292 , V_293 ;
T_1 V_221 , V_228 ;
int V_111 ;
F_53 ( F_188 ( V_52 ,
& V_292 , & V_293 ) ) ;
for ( V_111 = 0 ; V_111 < 256 ; V_111 ++ ) {
if ( F_185 ( V_52 , V_111 ,
& V_221 , & V_228 ) )
break;
if ( ( V_292 == V_221 )
&& ( V_293 == V_228 ) ) {
V_245 -> V_242 . V_262 . V_263 [ 0 ] = V_111 ;
return 0 ;
}
}
F_42 ( V_35
L_51 ,
V_52 , V_292 , V_293 ) ;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = 0 ;
return 0 ;
}
static int F_189 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
T_1 V_292 , V_293 ;
T_1 V_29 ;
V_247 = 1 ;
V_29 = F_185 ( V_52 ,
V_245 -> V_242 . V_262 . V_263 [ 0 ] ,
& V_292 , & V_293 ) ;
if ( ! V_29 )
F_53 (
F_190 ( V_52 ,
V_292 , V_293 ) ) ;
return V_247 ;
}
static int F_191 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_52 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_186 ;
V_214 . V_253 = F_187 ;
V_214 . V_254 = F_189 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_192 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
static const char * const V_294 [ V_295 + 1 ] = {
L_53 ,
L_54 , L_55 ,
L_56 , L_57 ,
L_58 , L_59
} ;
T_2 V_52 = V_232 -> V_218 ;
T_1 V_296 ;
int V_276 ;
const char * V_297 [ 6 ] ;
int V_298 = 0 ;
for ( V_276 = 0 ; V_276 < V_295 ; V_276 ++ )
if ( ! F_193 (
V_52 , V_276 , & V_296 ) ) {
V_297 [ V_298 ] = V_294 [ V_296 ] ;
V_298 ++ ;
}
if ( ! V_298 )
return - V_47 ;
return F_146 ( V_234 , 1 , V_298 , V_297 ) ;
}
static int F_194 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_1 V_296 ;
if ( F_195 ( V_52 , & V_296 ) )
V_296 = 1 ;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = V_296 - 1 ;
return 0 ;
}
static int F_196 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
V_247 = 1 ;
F_53 ( F_197 ( V_52 ,
V_245 -> V_242 . V_262 . V_263 [ 0 ] + 1 ) ) ;
return V_247 ;
}
static int F_198 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 = V_49 -> V_86 ;
struct V_211 V_214 ;
F_125 ( & V_214 , V_216 , L_60 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_192 ;
V_214 . V_253 = F_194 ;
V_214 . V_254 = F_196 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_199 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_232 -> V_85 ) ;
struct V_299 * V_300 = & V_49 -> V_301 ;
V_234 -> type = V_290 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . V_262 . V_291 = V_300 -> V_235 ;
if ( V_234 -> V_242 . V_262 . V_263 >= V_234 -> V_242 . V_262 . V_291 )
V_234 -> V_242 . V_262 . V_263 =
V_234 -> V_242 . V_262 . V_291 - 1 ;
strcpy ( V_234 -> V_242 . V_262 . V_40 ,
V_300 -> V_111 [ V_234 -> V_242 . V_262 . V_263 ] . V_40 ) ;
return 0 ;
}
static int F_200 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_232 -> V_85 ) ;
struct V_299 * V_300 = & V_49 -> V_301 ;
T_2 V_52 = V_232 -> V_218 ;
T_1 V_261 , V_302 = 0 ;
int V_276 ;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = 0 ;
if ( F_201 ( V_52 , & V_261 ) )
V_261 = 0 ;
if ( V_261 == V_303 )
if ( F_202 ( V_52 , & V_302 ) )
V_302 = 0 ;
for ( V_276 = 0 ; V_276 < V_300 -> V_235 ; V_276 ++ )
if ( ( V_300 -> V_111 [ V_276 ] . V_261 == V_261 ) &&
( V_300 -> V_111 [ V_276 ] . V_107 == V_302 ) )
break;
V_245 -> V_242 . V_262 . V_263 [ 0 ] = V_276 ;
return 0 ;
}
static int F_203 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_232 -> V_85 ) ;
struct V_299 * V_300 = & V_49 -> V_301 ;
unsigned int V_263 ;
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
V_247 = 1 ;
V_263 = V_245 -> V_242 . V_262 . V_263 [ 0 ] ;
if ( V_263 >= V_300 -> V_235 )
V_263 = V_300 -> V_235 - 1 ;
F_53 ( F_204 (
V_52 , V_300 -> V_111 [ V_263 ] . V_261 ) ) ;
if ( V_300 -> V_111 [ V_263 ] . V_261 == V_303 )
F_53 ( F_205 (
V_52 , V_300 -> V_111 [ V_263 ] . V_107 ) ) ;
return V_247 ;
}
static int F_206 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
V_234 -> type = V_241 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . integer . F_48 = 8000 ;
V_234 -> V_242 . integer . F_49 = 192000 ;
V_234 -> V_242 . integer . V_243 = 100 ;
return 0 ;
}
static int F_207 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_304 ;
T_1 V_29 ;
V_29 = F_208 ( V_52 , & V_304 ) ;
if ( ! V_29 )
V_245 -> V_242 . integer . V_242 [ 0 ] = V_304 ;
else
V_245 -> V_242 . integer . V_242 [ 0 ] = 0 ;
return 0 ;
}
static int F_209 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
int V_247 ;
T_2 V_52 = V_232 -> V_218 ;
V_247 = 1 ;
F_53 ( F_210 ( V_52 ,
V_245 -> V_242 . integer . V_242 [ 0 ] ) ) ;
return V_247 ;
}
static int F_211 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
V_234 -> type = V_241 ;
V_234 -> V_235 = 1 ;
V_234 -> V_242 . integer . F_48 = 8000 ;
V_234 -> V_242 . integer . F_49 = 192000 ;
V_234 -> V_242 . integer . V_243 = 100 ;
return 0 ;
}
static int F_212 ( struct V_231 * V_232 ,
struct V_244 * V_245 )
{
T_2 V_52 = V_232 -> V_218 ;
T_2 V_304 ;
T_1 V_29 ;
V_29 = F_46 ( V_52 , & V_304 ) ;
if ( ! V_29 )
V_245 -> V_242 . integer . V_242 [ 0 ] = V_304 ;
else
V_245 -> V_242 . integer . V_242 [ 0 ] = 0 ;
return 0 ;
}
static int F_213 ( struct V_48 * V_49 ,
struct V_215 * V_216 )
{
struct V_160 * V_86 ;
struct V_211 V_214 ;
struct V_299 * V_300 ;
T_2 V_305 = V_216 -> V_52 ;
int V_306 = 0 ;
int V_276 , V_307 ;
T_1 V_261 ;
if ( F_214 ( ! V_49 ) )
return - V_47 ;
V_86 = V_49 -> V_86 ;
V_300 = & V_49 -> V_301 ;
V_214 . V_218 = V_216 -> V_52 ;
V_300 -> V_308 = 0 ;
for ( V_276 = 0 ; V_276 <= V_309 ; V_276 ++ ) {
if ( F_215 ( V_305 ,
V_276 , & V_261 ) )
break;
V_300 -> V_111 [ V_276 ] . V_261 = V_261 ;
V_300 -> V_111 [ V_276 ] . V_107 = 0 ;
V_300 -> V_111 [ V_276 ] . V_40 = V_310 [ V_261 ] ;
if ( V_261 == V_303 )
V_306 = 1 ;
if ( V_261 == V_311 )
V_300 -> V_308 = 1 ;
}
if ( V_306 )
for ( V_307 = 1 ; V_307 < 8 ; V_307 ++ ) {
if ( F_216 ( V_305 ,
V_307 , V_303 ,
& V_261 ) )
break;
V_300 -> V_111 [ V_276 ] . V_261 =
V_303 ;
V_300 -> V_111 [ V_276 ] . V_107 = V_307 ;
V_300 -> V_111 [ V_276 ] . V_40 = V_310 [
V_307 + V_309 ] ;
V_276 ++ ;
}
V_300 -> V_235 = V_276 ;
F_125 ( & V_214 , V_216 , L_61 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_199 ;
V_214 . V_253 = F_200 ;
V_214 . V_254 = F_203 ;
if ( F_121 ( V_86 , & V_214 , V_49 ) < 0 )
return - V_47 ;
if ( V_300 -> V_308 ) {
F_125 ( & V_214 , V_216 , L_62 ) ;
V_214 . V_250 = V_251 ;
V_214 . V_185 = F_206 ;
V_214 . V_253 = F_207 ;
V_214 . V_254 = F_209 ;
if ( F_121 ( V_86 , & V_214 , V_49 ) < 0 )
return - V_47 ;
}
F_125 ( & V_214 , V_216 , L_63 ) ;
V_214 . V_250 =
V_268 | V_269 ;
V_214 . V_185 = F_211 ;
V_214 . V_253 = F_212 ;
return F_121 ( V_86 , & V_214 , V_49 ) ;
}
static int F_217 ( struct V_48 * V_49 )
{
struct V_160 * V_86 ;
unsigned int V_54 = 0 ;
unsigned int V_312 = 0 ;
int V_33 ;
struct V_215 V_216 , V_313 ;
if ( F_214 ( ! V_49 ) )
return - V_47 ;
V_86 = V_49 -> V_86 ;
strcpy ( V_86 -> V_314 , L_64 ) ;
V_33 =
F_218 ( V_49 -> V_105 -> V_106 -> V_107 ,
& V_49 -> V_61 ) ;
F_53 ( V_33 ) ;
if ( V_33 )
return - V_33 ;
memset ( & V_313 , 0 , sizeof( V_313 ) ) ;
V_313 . V_315 = - 1 ;
for ( V_54 = 0 ; V_54 < 2000 ; V_54 ++ ) {
V_33 = F_219 (
V_49 -> V_61 ,
V_54 ,
& V_216 . V_221 ,
& V_216 . V_228 ,
& V_216 . V_223 ,
& V_216 . V_230 ,
& V_216 . V_315 ,
& V_216 . V_52 ) ;
if ( V_33 ) {
if ( V_33 == V_316 ) {
if ( V_213 )
F_124 ( & V_49 -> V_64 -> V_65 ,
L_65 ,
V_54 ) ;
continue;
} else
break;
}
V_216 . V_221 -= V_222 ;
V_216 . V_223 -= V_224 ;
if ( ( V_216 . V_315 == V_313 . V_315 ) &&
( V_216 . V_221 == V_313 . V_221 ) &&
( V_216 . V_228 == V_313 . V_228 ) &&
( V_216 . V_223 == V_313 . V_223 ) &&
( V_216 . V_230 == V_313 . V_230 ) )
V_312 ++ ;
else
V_312 = 0 ;
V_313 = V_216 ;
switch ( V_216 . V_315 ) {
case V_317 :
V_33 = F_137 ( V_49 , & V_216 ) ;
break;
case V_318 :
V_33 = F_144 ( V_49 , & V_216 ) ;
break;
case V_319 :
V_33 = F_191 ( V_49 , & V_216 ) ;
break;
case V_320 :
V_33 = F_198 ( V_49 , & V_216 ) ;
break;
case V_321 :
V_33 = F_183 ( V_49 , & V_216 , V_312 ) ;
break;
case V_63 :
V_33 = F_213 (
V_49 , & V_216 ) ;
break;
case V_322 :
continue;
case V_323 :
V_33 = F_179 ( V_49 , & V_216 ) ;
break;
case V_324 :
V_33 = F_158 ( V_49 , & V_216 ) ;
break;
case V_325 :
V_33 = F_155 ( V_49 , & V_216 ) ;
break;
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
default:
if ( V_213 )
F_124 ( & V_49 -> V_64 -> V_65 ,
L_66 ,
V_54 ,
V_216 . V_315 ,
V_216 . V_221 ,
V_216 . V_228 ,
V_216 . V_223 ,
V_216 . V_230 ) ;
continue;
}
if ( V_33 < 0 )
return V_33 ;
}
if ( V_277 != V_33 )
F_53 ( V_33 ) ;
F_124 ( & V_49 -> V_64 -> V_65 , L_67 , V_54 ) ;
return 0 ;
}
static void
F_220 ( struct V_331 * V_332 ,
struct V_333 * V_17 )
{
struct V_48 * V_49 = V_332 -> V_85 ;
T_2 V_52 ;
T_2 V_304 = 0 ;
T_1 V_261 = 0 ;
T_1 V_204 ;
T_1 V_203 ;
T_1 V_334 ;
T_2 V_335 ;
T_1 type ;
int V_33 ;
F_221 ( V_17 , L_68 ) ;
F_53 ( F_116 ( V_49 -> V_105 -> V_106 -> V_107 ,
& V_204 , & V_203 ,
& V_334 , & V_335 , & type ) ) ;
F_221 ( V_17 ,
L_69
L_70 ,
type , V_49 -> V_105 -> V_106 -> V_107 ,
V_204 , V_203 ) ;
F_221 ( V_17 ,
L_71 ,
V_335 , ( ( V_334 >> 3 ) & 0xf ) + 'A' , V_334 & 0x7 ,
( ( V_334 >> 13 ) * 100 ) + ( ( V_334 >> 7 ) & 0x3f ) ) ;
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 ) {
V_33 = F_46 ( V_52 , & V_304 ) ;
V_33 += F_201 ( V_52 , & V_261 ) ;
if ( ! V_33 )
F_221 ( V_17 , L_72 ,
V_304 , V_310 [ V_261 ] ) ;
}
}
static void F_222 ( struct V_48 * V_49 )
{
struct V_331 * V_332 ;
if ( ! F_223 ( V_49 -> V_86 , L_73 , & V_332 ) )
F_224 ( V_332 , V_49 , F_220 ) ;
}
static int F_225 ( struct V_336 * V_194 , struct V_337 * V_337 )
{
if ( V_338 )
return 0 ;
else
return - V_339 ;
}
static int F_226 ( struct V_336 * V_194 , struct V_337 * V_337 )
{
if ( V_338 )
return F_227 ( V_337 ) ;
else
return - V_339 ;
}
static int F_228 ( struct V_336 * V_194 , struct V_337 * V_337 ,
unsigned int V_110 , unsigned long V_161 )
{
if ( V_338 )
return F_229 ( V_337 , V_110 , V_161 ) ;
else
return - V_339 ;
}
static int F_230 ( struct V_48 * V_49 ,
int V_200 , struct V_336 * * V_340 )
{
struct V_336 * V_194 ;
int V_33 ;
if ( V_340 )
* V_340 = NULL ;
V_33 = F_231 ( V_49 -> V_86 , L_74 , V_200 , & V_194 ) ;
if ( V_33 < 0 )
return V_33 ;
strcpy ( V_194 -> V_40 , L_75 ) ;
V_194 -> V_219 = V_341 ;
V_194 -> V_342 . V_343 = F_225 ;
V_194 -> V_342 . V_344 = F_228 ;
V_194 -> V_342 . V_345 = F_226 ;
V_194 -> V_85 = V_49 ;
if ( V_340 )
* V_340 = V_194 ;
return 0 ;
}
static int F_232 ( struct V_346 * V_346 ,
const struct V_347 * V_348 )
{
int V_33 ;
struct V_159 * V_105 ;
struct V_160 * V_86 ;
struct V_48 * V_49 ;
T_2 V_52 ;
T_2 V_1 ;
T_2 V_13 ;
static int V_65 ;
if ( V_65 >= V_349 )
return - V_339 ;
if ( ! V_350 [ V_65 ] ) {
V_65 ++ ;
return - V_351 ;
}
V_33 = F_233 ( V_346 , V_348 ) ;
if ( V_33 < 0 )
return V_33 ;
V_105 = F_234 ( V_346 ) ;
V_13 = V_105 -> V_106 -> V_107 ;
V_33 = F_235 ( & V_346 -> V_65 , V_13 , V_352 [ V_13 ] ,
V_353 , sizeof( struct V_48 ) , & V_86 ) ;
if ( V_33 < 0 ) {
V_33 = F_235 ( & V_346 -> V_65 , V_107 [ V_65 ] , V_352 [ V_65 ] ,
V_353 , sizeof( struct V_48 ) ,
& V_86 ) ;
if ( V_33 < 0 )
return V_33 ;
F_236 ( & V_346 -> V_65 , L_76 ,
V_13 , V_86 -> V_117 ) ;
}
V_49 = V_86 -> V_85 ;
V_49 -> V_86 = V_86 ;
V_49 -> V_64 = V_346 ;
V_49 -> V_105 = V_105 ;
V_105 -> V_160 = V_86 ;
V_33 = F_237 ( V_13 ,
V_354 ,
NULL , & V_49 -> V_120 ) ;
if ( V_33 )
V_49 -> V_120 = 0 ;
V_33 = F_237 ( V_13 ,
V_355 ,
& V_49 -> V_58 , NULL ) ;
if ( V_33 )
V_49 -> V_58 = 0 ;
V_33 = F_237 ( V_13 ,
V_356 ,
NULL , & V_49 -> V_109 ) ;
if ( V_33 )
V_49 -> V_109 = 512 ;
if ( V_105 -> V_158 ) {
V_49 -> V_121 = F_65 ;
V_49 -> V_123 = F_71 ;
F_238 ( & V_49 -> V_103 , F_84 ,
( unsigned long ) V_105 ) ;
V_105 -> V_357 = F_86 ;
} else {
V_49 -> V_121 = F_61 ;
V_49 -> V_123 = F_63 ;
}
F_53 ( F_112 ( V_13 ,
0 , & V_1 ) ) ;
V_33 = F_239 ( V_1 ) ;
V_49 -> V_92 = ( ! V_33 ) ;
F_53 ( F_114 ( V_1 ) ) ;
if ( ! V_49 -> V_92 )
V_49 -> V_109 *= 2 ;
V_33 = F_237 ( V_13 ,
V_358 ,
& V_49 -> V_197 , & V_49 -> V_165 ) ;
if ( V_33 ) {
V_49 -> V_197 = 2 ;
V_49 -> V_165 = 2 ;
}
if ( V_49 -> V_165 > 2 ) {
V_49 -> V_184 = V_49 -> V_165 ;
V_49 -> V_199 = V_49 -> V_197 ;
V_49 -> V_120 = 0 ;
} else {
V_49 -> V_184 = 1 ;
V_49 -> V_199 = 1 ;
}
F_124 ( & V_346 -> V_65 , L_77 ,
V_49 -> V_92 ,
V_49 -> V_120 ,
V_49 -> V_58 ,
V_49 -> V_109
) ;
V_33 = F_115 ( V_49 , 0 ) ;
if ( V_33 < 0 ) {
F_45 ( & V_346 -> V_65 , L_78 ) ;
goto V_359;
}
V_33 = F_217 ( V_49 ) ;
if ( V_33 < 0 ) {
F_45 ( & V_346 -> V_65 , L_79 ) ;
goto V_359;
}
V_33 = F_44 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_210 (
V_52 , V_360 ) ;
F_222 ( V_49 ) ;
F_230 ( V_49 , 0 , NULL ) ;
strcpy ( V_86 -> V_361 , L_80 ) ;
sprintf ( V_86 -> V_362 , L_81 ,
V_49 -> V_105 -> V_106 -> type ) ;
sprintf ( V_86 -> V_363 , L_82 ,
V_86 -> V_362 , V_13 ) ;
V_33 = F_240 ( V_86 ) ;
if ( ! V_33 ) {
V_65 ++ ;
return 0 ;
}
V_359:
F_241 ( V_86 ) ;
F_45 ( & V_346 -> V_65 , L_83 , V_33 ) ;
return V_33 ;
}
static void F_242 ( struct V_346 * V_346 )
{
struct V_159 * V_105 = F_234 ( V_346 ) ;
struct V_48 * V_49 = V_105 -> V_160 -> V_85 ;
if ( V_105 -> V_158 ) {
V_105 -> V_357 = NULL ;
F_53 ( F_70 ( V_105 -> V_106 -> V_107 ,
V_108 , 0 , 0 ) ) ;
F_243 ( & V_49 -> V_103 ) ;
}
F_241 ( V_105 -> V_160 ) ;
V_105 -> V_160 = NULL ;
F_244 ( V_346 ) ;
}
static int T_7 F_245 ( void )
{
F_246 () ;
return F_247 ( & V_361 ) ;
}
static void T_8 F_248 ( void )
{
F_249 ( & V_361 ) ;
F_250 () ;
}
