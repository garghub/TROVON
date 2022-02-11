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
F_29 ( L_3 , F_30 ( V_39 ) ) ;
F_29 ( L_4 , F_31 ( V_39 ) ) ;
F_29 ( L_5 , F_32 ( V_39 ) ) ;
F_29 ( L_6 , F_33 ( V_39 ) ) ;
F_29 ( L_7 , F_34 ( V_39 ) ) ;
F_29 ( L_8 , F_35 ( V_39 ) ) ;
F_29 ( L_9 , F_36 ( V_39 ) ) ;
F_29 ( L_10 , F_37 ( V_39 ) ) ;
F_29 ( L_11 , F_38 ( V_39 ) ) ;
F_29 ( L_12 , F_39 ( V_39 ) ) ;
F_29 ( L_13 , F_30 ( V_39 ) *
F_31 ( V_39 ) *
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
F_29 ( V_35 L_14 ,
V_41 ) ;
* V_42 = 0 ;
return - V_47 ;
}
static void F_42 ( struct V_48 * V_49 ,
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
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( V_33 ) {
F_44 ( V_64
L_15 , V_33 ) ;
}
for ( V_54 = - 1 ; V_54 < 100 ; V_54 ++ ) {
if ( V_54 == - 1 ) {
if ( F_45 ( V_52 ,
& V_53 ) )
continue;
} else if ( F_46 ( V_52 ,
V_54 , & V_53 ) ) {
break;
}
V_55 = F_47 ( V_55 , V_53 ) ;
V_56 = F_48 ( V_56 , V_53 ) ;
switch ( V_53 ) {
case 5512 :
V_57 |= V_65 ;
break;
case 8000 :
V_57 |= V_66 ;
break;
case 11025 :
V_57 |= V_67 ;
break;
case 16000 :
V_57 |= V_68 ;
break;
case 22050 :
V_57 |= V_69 ;
break;
case 32000 :
V_57 |= V_70 ;
break;
case 44100 :
V_57 |= V_71 ;
break;
case 48000 :
V_57 |= V_72 ;
break;
case 64000 :
V_57 |= V_73 ;
break;
case 88200 :
V_57 |= V_74 ;
break;
case 96000 :
V_57 |= V_75 ;
break;
case 176400 :
V_57 |= V_76 ;
break;
case 192000 :
V_57 |= V_77 ;
break;
default:
V_57 |= V_78 ;
}
}
}
V_51 -> V_57 = V_57 ;
V_51 -> V_55 = V_55 ;
V_51 -> V_56 = V_56 ;
}
static int F_49 ( struct V_36 * V_37 ,
struct V_38 * V_79 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
int V_33 ;
T_1 V_43 ;
int V_86 ;
unsigned int V_87 ;
F_27 ( V_37 , V_79 ) ;
V_33 = F_51 ( V_37 , F_34 ( V_79 ) ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_41 ( F_32 ( V_79 ) , & V_43 ) ;
if ( V_33 )
return V_33 ;
F_52 ( F_53 ( & V_83 -> V_43 ,
F_31 ( V_79 ) ,
V_43 , F_30 ( V_79 ) , 0 , 0 ) ) ;
if ( V_37 -> V_88 == V_89 ) {
if ( F_54 ( V_83 -> V_1 ) != 0 )
return - V_47 ;
if ( F_55 (
V_83 -> V_1 , & V_83 -> V_43 ) != 0 )
return - V_47 ;
}
V_83 -> V_90 = 0 ;
if ( V_85 -> V_91 ) {
V_33 = F_1 ( V_83 -> V_1 ,
F_34 ( V_79 ) , V_81 -> V_92 ) ;
if ( V_33 == 0 ) {
F_56 (
L_16 ,
F_34 ( V_79 ) ,
( unsigned long ) V_81 -> V_92 ) ;
} else {
F_29 ( L_17 ,
V_33 ) ;
return - V_93 ;
}
V_33 = F_13 ( V_83 -> V_1 , NULL ,
& V_83 -> V_90 ,
NULL , NULL , NULL ) ;
F_56 ( L_18 ,
V_83 -> V_90 ) ;
}
V_87 = F_30 ( V_79 ) * F_31 ( V_79 ) ;
V_86 = F_40 ( F_32 ( V_79 ) ) ;
V_87 *= V_86 ;
V_87 /= 8 ;
if ( V_86 < 0 || V_87 == 0 )
return - V_47 ;
V_83 -> V_87 = V_87 ;
V_83 -> V_94 = F_34 ( V_79 ) ;
V_83 -> V_95 = F_35 ( V_79 ) ;
return 0 ;
}
static int
F_57 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
if ( V_83 -> V_90 )
F_6 ( V_83 -> V_1 ) ;
F_58 ( V_37 ) ;
return 0 ;
}
static void F_59 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = V_81 -> V_84 ;
F_60 ( V_83 ) ;
}
static void F_61 ( struct V_36 *
V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
int V_96 ;
V_96 = V_97 / 200 ;
V_96 = F_48 ( V_96 , 1 ) ;
V_83 -> V_98 . V_99 = V_100 + V_96 ;
V_83 -> V_101 = 1 ;
F_62 ( & V_83 -> V_98 ) ;
}
static void F_63 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
V_83 -> V_101 = 0 ;
F_64 ( & V_83 -> V_98 ) ;
}
static int F_65 ( struct V_36 * V_37 ,
int V_102 )
{
struct V_82 * V_83 = V_37 -> V_81 -> V_84 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_36 * V_103 ;
T_1 V_29 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_56 ( L_19 , V_40 ) ;
switch ( V_102 ) {
case V_104 :
F_66 (s, substream) {
struct V_80 * V_81 = V_103 -> V_81 ;
struct V_82 * V_105 = V_81 -> V_84 ;
if ( F_50 ( V_103 ) != V_85 )
continue;
if ( V_37 -> V_88 != V_103 -> V_88 )
continue;
V_105 -> V_106 = 0 ;
if ( V_103 -> V_88 == V_107 ) {
unsigned int V_108 = V_105 -> V_95 * 1 ;
F_67 ( L_20 , V_103 -> V_109 , V_108 ) ;
F_52 ( F_68 (
V_105 -> V_1 ,
& V_81 -> V_110 [ 0 ] ,
V_108 ,
& V_105 -> V_43 ) ) ;
V_105 -> V_111 = V_108 ;
}
if ( V_85 -> V_112 ) {
F_56 ( L_21 , V_103 -> V_109 ) ;
V_29 = F_16 (
V_83 -> V_1 ,
V_105 -> V_1 ) ;
if ( ! V_29 ) {
F_69 ( V_103 , V_37 ) ;
} else {
F_52 ( V_29 ) ;
break;
}
} else
break;
}
F_56 ( L_22 ) ;
F_61 ( V_37 ) ;
if ( ( V_37 -> V_88 == V_89 ) ||
! V_85 -> V_91 )
F_52 ( F_7 ( V_83 -> V_1 ) ) ;
break;
case V_113 :
F_63 ( V_37 ) ;
F_66 (s, substream) {
if ( F_50 ( V_103 ) != V_85 )
continue;
if ( V_37 -> V_88 != V_103 -> V_88 )
continue;
V_103 -> V_81 -> V_114 -> V_115 = V_116 ;
if ( V_85 -> V_112 ) {
F_56 ( L_21 , V_103 -> V_109 ) ;
F_69 ( V_103 , V_37 ) ;
} else
break;
}
F_56 ( L_23 ) ;
F_52 ( F_10 ( V_83 -> V_1 ) ) ;
if ( V_37 -> V_88 == V_107 )
F_52 (
F_70 ( V_83 -> V_1 ) ) ;
if ( V_85 -> V_112 )
F_52 ( F_19 ( V_83 -> V_1 ) ) ;
break;
case V_117 :
F_56 ( L_24 ) ;
F_52 ( F_7 ( V_83 -> V_1 ) ) ;
F_61 ( V_37 ) ;
break;
case V_118 :
F_56 ( L_25 ) ;
F_63 ( V_37 ) ;
F_52 ( F_10 ( V_83 -> V_1 ) ) ;
break;
default:
F_29 ( V_64 L_26 ) ;
return - V_47 ;
}
return 0 ;
}
static inline unsigned int F_71 ( unsigned int V_119 , unsigned int V_120 ,
unsigned long int V_121 )
{
unsigned int V_122 ;
if ( ( ( V_119 - V_120 ) % V_121 ) < ( V_121 / 2 ) )
V_122 = V_120 ;
else
V_122 = V_119 ;
return V_122 ;
}
static void F_72 ( unsigned long V_123 )
{
struct V_82 * V_83 = (struct V_82 * ) V_123 ;
struct V_36 * V_37 = V_83 -> V_37 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_80 * V_81 ;
struct V_36 * V_103 ;
unsigned int V_124 = 0 ;
unsigned int V_125 , V_126 = 0 ;
unsigned int V_127 , V_128 , V_129 ;
int V_130 = 1 ;
int V_131 = 0 ;
T_1 V_115 ;
T_2 V_18 , V_132 , V_133 , V_134 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_56 ( L_27 , V_40 ) ;
F_66 (s, substream) {
struct V_82 * V_105 = V_103 -> V_81 -> V_84 ;
V_81 = V_103 -> V_81 ;
if ( F_50 ( V_103 ) != V_85 )
continue;
if ( V_37 -> V_88 != V_103 -> V_88 )
continue;
F_52 ( F_13 (
V_105 -> V_1 , & V_115 ,
& V_18 , & V_132 ,
& V_133 , & V_134 ) ) ;
V_81 -> V_135 = V_134 ;
if ( ! V_85 -> V_91 )
V_134 = V_132 ;
if ( V_103 -> V_88 == V_107 ) {
V_125 = V_105 -> V_111 - V_132 ;
if ( V_115 == V_136 ) {
if ( V_132 == 0 ) {
F_52 ( F_7 ( V_105 -> V_1 ) ) ;
F_56 ( L_28 , V_103 -> V_109 ) ;
V_105 -> V_106 = 0 ;
}
} else if ( V_115 == V_137 ) {
F_29 ( V_35 L_29 ,
V_103 -> V_109 ) ;
V_105 -> V_106 ++ ;
if ( V_105 -> V_106 > 20 ) {
unsigned long V_138 ;
F_73 ( V_103 , V_138 ) ;
F_74 ( V_103 , V_139 ) ;
F_75 ( V_103 , V_138 ) ;
continue;
}
} else {
V_105 -> V_106 = 0 ;
}
} else
V_125 = V_132 + V_105 -> V_111 ;
if ( V_130 ) {
V_126 = V_125 ;
V_124 = ( V_125 - V_105 -> V_140 ) % V_105 -> V_94 ;
V_130 = 0 ;
} else {
V_126 =
F_71 ( V_126 , V_125 , V_141 + 1L ) ;
V_124 = F_47 (
( V_125 - V_105 -> V_140 ) % V_105 -> V_94 ,
V_124 ) ;
}
F_56 ( L_30 ,
( unsigned long ) F_76 ( V_81 ,
V_81 -> V_114 -> V_142 ) ,
( unsigned long ) F_76 ( V_81 ,
V_81 -> V_143 -> V_144 ) ) ;
F_56 ( L_31
L_32
L_33 ,
V_103 -> V_109 , V_115 ,
V_105 -> V_111 , V_125 ,
( int ) V_132 ,
( int ) V_134 , V_18 - V_132 ) ;
V_131 ++ ;
}
V_125 = V_126 ;
V_127 = V_124 % V_83 -> V_95 ;
V_128 = V_124 - V_127 ;
if ( V_128 && ( V_134 > V_83 -> V_95 ) )
V_129 = ( ( V_134 - V_83 -> V_95 ) * V_97 / V_83 -> V_87 ) ;
else
V_129 = ( ( V_83 -> V_95 - V_127 ) * V_97 / V_83 -> V_87 ) ;
V_129 = F_48 ( V_129 , 1U ) ;
V_83 -> V_98 . V_99 = V_100 + V_129 ;
F_56 ( L_34 ,
V_129 , V_125 , V_124 , V_128 ) ;
F_66 (s, substream) {
struct V_82 * V_105 = V_103 -> V_81 -> V_84 ;
if ( V_37 -> V_88 != V_103 -> V_88 )
continue;
V_105 -> V_125 = V_125 ;
if ( V_128 &&
( ( V_134 <= V_105 -> V_95 ) ||
( V_103 -> V_88 == V_89 ) ) )
{
unsigned int V_145 = V_105 -> V_111 % V_105 -> V_94 ;
unsigned int V_146 , V_147 ;
char * V_148 = & V_103 -> V_81 -> V_110 [ V_145 ] ;
if ( V_85 -> V_91 ) {
V_146 = V_128 ;
V_147 = 0 ;
} else {
V_146 = F_47 ( V_128 , V_105 -> V_94 - V_145 ) ;
V_147 = V_128 - V_146 ;
}
if ( V_103 -> V_88 == V_107 ) {
F_67 ( L_35 ,
V_103 -> V_109 , V_146 , V_145 ) ;
F_52 (
F_68 (
V_105 -> V_1 , V_148 , V_146 ,
& V_105 -> V_43 ) ) ;
if ( V_147 ) {
V_148 = V_103 -> V_81 -> V_110 ;
F_67 ( L_36 ,
V_103 -> V_109 ,
V_128 - V_146 , V_145 ) ;
F_52 (
F_68 (
V_105 -> V_1 , V_148 ,
V_128 - V_146 ,
& V_105 -> V_43 ) ) ;
}
} else {
F_67 ( L_37 ,
V_103 -> V_109 , V_146 ) ;
F_52 (
F_77 (
V_105 -> V_1 ,
V_148 , V_146 ) ) ;
if ( V_147 ) {
V_148 = V_103 -> V_81 -> V_110 ;
F_67 ( L_38 ,
V_103 -> V_109 , V_147 ) ;
F_52 (
F_77 (
V_105 -> V_1 ,
V_148 , V_147 ) ) ;
}
}
V_105 -> V_111 += V_128 ;
V_105 -> V_140 += V_128 ;
F_78 ( V_103 ) ;
}
}
if ( V_83 -> V_101 )
F_62 ( & V_83 -> V_98 ) ;
}
static int F_79 ( struct V_36 * V_37 ,
unsigned int V_102 , void * V_149 )
{
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_67 ( V_150 L_39 , V_40 , V_102 ) ;
return F_80 ( V_37 , V_102 , V_149 ) ;
}
static int F_81 ( struct V_36 *
V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_56 ( L_40 , V_37 -> V_109 ) ;
F_52 ( F_70 ( V_83 -> V_1 ) ) ;
V_83 -> V_111 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_140 = 0 ;
return 0 ;
}
static T_4
F_82 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
T_4 V_151 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
V_151 = F_83 ( V_81 , V_83 -> V_125 % V_83 -> V_94 ) ;
F_67 ( L_41 , V_40 , ( unsigned long ) V_151 ) ;
return V_151 ;
}
static T_5 F_84 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_152 = 0 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 , V_49 -> V_153 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_85 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_152 |= F_86 ( V_46 [ V_43 ] ) ;
}
return V_152 ;
}
static int F_87 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_50 V_154 ;
int V_33 ;
V_83 = F_88 ( sizeof( * V_83 ) , V_155 ) ;
if ( V_83 == NULL )
return - V_93 ;
V_33 = F_89 ( V_85 -> V_156 -> V_157 -> V_158 ,
V_37 -> V_109 , & V_83 -> V_1 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_159 )
return - V_160 ;
if ( V_33 )
return - V_161 ;
F_90 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_162 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_163 = F_59 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_164 = V_165 ;
V_154 . V_166 = V_167 ;
V_154 . V_168 = V_165 / V_169 ;
V_154 . V_170 = V_169 ;
V_154 . V_171 = V_165 / V_167 ;
V_154 . V_172 = V_85 -> V_153 ;
V_154 . V_173 = V_85 -> V_174 ;
V_154 . V_152 =
F_84 ( V_85 , V_83 -> V_1 ) ;
F_42 ( V_85 , & V_154 ) ;
V_154 . V_175 = V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 ;
if ( V_85 -> V_112 ) {
V_154 . V_175 |= V_183 ;
F_91 ( V_37 ) ;
}
V_81 -> V_184 = V_154 ;
if ( V_85 -> V_91 )
V_33 = F_92 ( V_81 , 0 ,
V_185 ) ;
if ( V_33 < 0 )
return V_33 ;
F_93 ( V_81 , 0 , V_186 ,
V_85 -> V_187 ) ;
F_94 ( V_81 , V_186 ,
V_85 -> V_187 * 2 , V_141 ) ;
F_56 ( L_42 ) ;
return 0 ;
}
static int F_95 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_52 ( F_96 ( V_83 -> V_1 ) ) ;
F_56 ( L_43 ) ;
return 0 ;
}
static T_4
F_97 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_67 ( L_44 ,
V_37 -> V_109 , V_83 -> V_125 ) ;
return F_83 ( V_81 , V_83 -> V_125 % V_83 -> V_94 ) ;
}
static int F_98 ( struct V_36 * V_37 ,
unsigned int V_102 , void * V_149 )
{
return F_80 ( V_37 , V_102 , V_149 ) ;
}
static int F_99 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_52 ( F_54 ( V_83 -> V_1 ) ) ;
V_83 -> V_111 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_140 = 0 ;
F_56 ( L_45 , V_37 -> V_109 ) ;
return 0 ;
}
static T_5 F_100 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_152 = 0 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 , V_49 -> V_188 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_101 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_152 |= F_86 ( V_46 [ V_43 ] ) ;
}
return V_152 ;
}
static int F_102 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_82 * V_83 ;
struct V_50 V_189 ;
int V_33 ;
V_83 = F_88 ( sizeof( * V_83 ) , V_155 ) ;
if ( V_83 == NULL )
return - V_93 ;
F_56 ( L_46 ,
V_85 -> V_156 -> V_157 -> V_158 , V_37 -> V_109 ) ;
V_33 = F_52 (
F_103 ( V_85 -> V_156 -> V_157 -> V_158 ,
V_37 -> V_109 , & V_83 -> V_1 ) ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_159 )
return - V_160 ;
if ( V_33 )
return - V_161 ;
F_90 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_162 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_163 = F_59 ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_164 = V_165 ;
V_189 . V_166 = V_167 ;
V_189 . V_168 = V_165 / V_169 ;
V_189 . V_170 = V_169 ;
V_189 . V_171 = V_165 / V_167 ;
V_189 . V_172 = V_85 -> V_188 ;
V_189 . V_173 = V_85 -> V_190 ;
V_189 . V_152 =
F_100 ( V_85 , V_83 -> V_1 ) ;
F_42 ( V_85 , & V_189 ) ;
V_189 . V_175 = V_176 |
V_181 |
V_182 ;
if ( V_85 -> V_112 )
V_189 . V_175 |= V_183 ;
V_81 -> V_184 = V_189 ;
if ( V_85 -> V_91 )
V_33 = F_92 ( V_81 , 0 ,
V_185 ) ;
if ( V_33 < 0 )
return V_33 ;
F_93 ( V_81 , 0 , V_186 ,
V_85 -> V_187 ) ;
F_94 ( V_81 , V_186 ,
V_85 -> V_187 * 2 , V_141 ) ;
F_91 ( V_37 ) ;
return 0 ;
}
static int F_104 ( struct V_36 * V_37 )
{
struct V_82 * V_83 = V_37 -> V_81 -> V_84 ;
F_52 ( F_105 ( V_83 -> V_1 ) ) ;
return 0 ;
}
static int F_106 ( struct V_48 * V_49 , int V_191 )
{
struct V_192 * V_193 ;
int V_33 ;
T_1 V_194 , V_195 , V_196 ;
T_2 V_197 ;
V_33 = F_107 ( V_49 -> V_156 -> V_157 -> V_158 ,
& V_195 , & V_194 ,
& V_196 , & V_197 , & V_196 ) ;
V_33 = F_108 ( V_49 -> V_85 , L_47 , V_191 ,
V_195 , V_194 , & V_193 ) ;
if ( V_33 < 0 )
return V_33 ;
F_109 ( V_193 , V_107 ,
& V_198 ) ;
F_109 ( V_193 , V_89 ,
& V_199 ) ;
V_193 -> V_84 = V_49 ;
V_193 -> V_200 = 0 ;
strcpy ( V_193 -> V_40 , L_47 ) ;
F_110 ( V_193 , V_201 ,
F_111 ( V_49 -> V_202 ) ,
64 * 1024 , V_165 ) ;
return 0 ;
}
static inline int F_112 ( struct V_203 * V_85 , struct V_204 * V_205 ,
struct V_48 * V_49 )
{
int V_33 ;
V_33 = F_113 ( V_85 , F_114 ( V_205 , V_49 ) ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_206 )
F_44 ( V_150 L_48 , V_205 -> V_40 , V_205 -> V_158 ) ;
return 0 ;
}
static void F_115 ( struct V_204 * V_207 ,
struct V_208 * V_209 ,
char * V_40 )
{
char * V_210 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
V_207 -> V_40 = V_209 -> V_40 ;
V_207 -> V_211 = V_209 -> V_52 ;
V_207 -> V_212 = V_213 ;
V_207 -> V_158 = 0 ;
if ( V_209 -> V_214 + V_215 == V_62 )
V_210 = L_49 ;
else if ( V_209 -> V_216 + V_217 == V_218 )
V_210 = L_50 ;
else if ( ( V_209 -> V_214 + V_215 != V_219 ) &&
( ! V_209 -> V_216 ) )
V_210 = L_50 ;
else if ( V_209 -> V_214 &&
( V_209 -> V_214 + V_215 != V_219 ) &&
( V_209 -> V_216 ) )
V_210 = L_51 ;
else
V_210 = L_52 ;
if ( V_209 -> V_214 && V_209 -> V_216 )
sprintf ( V_209 -> V_40 , L_53 ,
V_220 [ V_209 -> V_214 ] ,
V_209 -> V_221 ,
V_222 [ V_209 -> V_216 ] ,
V_209 -> V_223 ,
V_210 , V_40 ) ;
else if ( V_209 -> V_216 ) {
sprintf ( V_209 -> V_40 , L_54 ,
V_222 [ V_209 -> V_216 ] ,
V_209 -> V_223 ,
V_210 , V_40 ) ;
} else {
sprintf ( V_209 -> V_40 , L_54 ,
V_220 [ V_209 -> V_214 ] ,
V_209 -> V_221 ,
V_210 , V_40 ) ;
}
}
static int F_116 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_228 ;
T_1 V_33 ;
short V_229 ;
short V_230 ;
short V_231 ;
V_33 = F_117 ( V_52 ,
& V_229 , & V_230 , & V_231 ) ;
if ( V_33 ) {
V_230 = 0 ;
V_229 = - 10000 ;
V_231 = V_232 ;
}
V_33 = F_118 ( V_52 , & V_228 ) ;
if ( V_33 )
V_228 = V_233 ;
V_227 -> type = V_234 ;
V_227 -> V_228 = V_228 ;
V_227 -> V_235 . integer . F_47 = V_229 / V_232 ;
V_227 -> V_235 . integer . F_48 = V_230 / V_232 ;
V_227 -> V_235 . integer . V_236 = V_231 / V_232 ;
return 0 ;
}
static int F_119 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
short V_239 [ V_233 ] ;
F_52 ( F_120 ( V_52 , V_239 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] = V_239 [ 0 ] / V_232 ;
V_238 -> V_235 . integer . V_235 [ 1 ] = V_239 [ 1 ] / V_232 ;
return 0 ;
}
static int F_121 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
short V_239 [ V_233 ] ;
V_239 [ 0 ] =
( V_238 -> V_235 . integer . V_235 [ 0 ] ) * V_232 ;
V_239 [ 1 ] =
( V_238 -> V_235 . integer . V_235 [ 1 ] ) * V_232 ;
V_240 = 1 ;
F_52 ( F_122 ( V_52 , V_239 ) ) ;
return V_240 ;
}
static int F_123 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_241 ;
F_52 ( F_124 ( V_52 , & V_241 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] = V_241 ? 0 : 1 ;
return 0 ;
}
static int F_125 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
int V_240 = 1 ;
int V_241 = V_238 -> V_235 . integer . V_235 [ 0 ] ? 0 : V_242 ;
F_52 ( F_126 ( V_52 , V_241 ) ) ;
return V_240 ;
}
static int F_127 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
int V_33 ;
T_2 V_241 ;
F_115 ( & V_207 , V_209 , L_55 ) ;
V_207 . V_243 = V_244 |
V_245 ;
V_207 . V_175 = F_116 ;
V_207 . V_246 = F_119 ;
V_207 . V_247 = F_121 ;
V_207 . V_248 . V_39 = V_249 ;
V_33 = F_112 ( V_85 , & V_207 , V_49 ) ;
if ( V_33 )
return V_33 ;
if ( F_124 ( V_209 -> V_52 , & V_241 ) == 0 ) {
F_115 ( & V_207 , V_209 , L_56 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = V_250 ;
V_207 . V_246 = F_123 ;
V_207 . V_247 = F_125 ;
V_33 = F_112 ( V_85 , & V_207 , V_49 ) ;
}
return V_33 ;
}
static int F_128 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_33 ;
short V_229 ;
short V_230 ;
short V_231 ;
V_33 =
F_129 ( V_52 , & V_229 ,
& V_230 , & V_231 ) ;
if ( V_33 ) {
V_230 = 2400 ;
V_229 = - 1000 ;
V_231 = 100 ;
}
V_227 -> type = V_234 ;
V_227 -> V_228 = 2 ;
V_227 -> V_235 . integer . F_47 = V_229 / V_251 ;
V_227 -> V_235 . integer . F_48 = V_230 / V_251 ;
V_227 -> V_235 . integer . V_236 = V_231 / V_251 ;
return 0 ;
}
static int F_130 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
short V_239 [ V_233 ] ;
F_52 ( F_131 ( V_52 , V_239 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] =
V_239 [ 0 ] / V_251 ;
V_238 -> V_235 . integer . V_235 [ 1 ] =
V_239 [ 1 ] / V_251 ;
return 0 ;
}
static int F_132 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
short V_239 [ V_233 ] ;
V_239 [ 0 ] =
( V_238 -> V_235 . integer . V_235 [ 0 ] ) * V_251 ;
V_239 [ 1 ] =
( V_238 -> V_235 . integer . V_235 [ 1 ] ) * V_251 ;
V_240 = 1 ;
F_52 ( F_133 ( V_52 , V_239 ) ) ;
return V_240 ;
}
static int F_134 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_57 ) ;
V_207 . V_243 = V_244 |
V_245 ;
V_207 . V_175 = F_128 ;
V_207 . V_246 = F_130 ;
V_207 . V_247 = F_132 ;
V_207 . V_248 . V_39 = V_252 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_135 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
V_227 -> type = V_253 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . V_254 . V_255 = 3 ;
if ( V_227 -> V_235 . V_254 . V_256 >= V_227 -> V_235 . V_254 . V_255 )
V_227 -> V_235 . V_254 . V_256 =
V_227 -> V_235 . V_254 . V_255 - 1 ;
strcpy ( V_227 -> V_235 . V_254 . V_40 ,
V_257 [ V_227 -> V_235 . V_254 . V_256 ] ) ;
return 0 ;
}
static int F_136 ( struct V_224 * V_225 ,
struct V_237 * V_238 ,
T_1 (* F_137)( T_2 , T_1 * ) )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_258 , V_33 ;
V_33 = F_137 ( V_52 , & V_258 ) ;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = 0 ;
if ( V_33 )
return 0 ;
if ( V_258 == V_259 )
V_238 -> V_235 . V_254 . V_256 [ 0 ] = 1 ;
if ( V_258 == V_260 )
V_238 -> V_235 . V_254 . V_256 [ 0 ] = 2 ;
return 0 ;
}
static int F_138 ( struct V_224 * V_225 ,
struct V_237 * V_238 ,
T_1 (* F_137)( T_2 , T_1 ) )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_258 = V_259 ;
if ( V_238 -> V_235 . V_254 . V_256 [ 0 ] == 1 )
V_258 = V_259 ;
if ( V_238 -> V_235 . V_254 . V_256 [ 0 ] == 2 )
V_258 = V_260 ;
if ( F_137 ( V_52 , V_258 ) != 0 )
return - V_47 ;
return 1 ;
}
static int F_139 ( struct V_224 * V_225 ,
struct V_237 * V_238 ) {
return F_136 ( V_225 , V_238 ,
V_261 ) ;
}
static int F_140 ( struct V_224 * V_225 ,
struct V_237 * V_238 ) {
return F_138 ( V_225 , V_238 ,
V_262 ) ;
}
static int F_141 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
V_227 -> type = V_234 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . integer . F_47 = 0 ;
V_227 -> V_235 . integer . F_48 = 0X1F ;
V_227 -> V_235 . integer . V_236 = 1 ;
return 0 ;
}
static int F_142 ( struct V_224 * V_225 ,
struct V_237 * V_238 ) {
T_2 V_52 = V_225 -> V_211 ;
T_1 V_114 ;
F_52 ( F_143 (
V_52 , & V_114 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] = V_114 ;
return 0 ;
}
static int F_144 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_58 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_135 ;
V_207 . V_246 = F_139 ;
V_207 . V_247 = F_140 ;
if ( F_112 ( V_85 , & V_207 , V_49 ) < 0 )
return - V_47 ;
F_115 ( & V_207 , V_209 , L_59 ) ;
V_207 . V_243 =
V_263 | V_264 ;
V_207 . V_175 = F_141 ;
V_207 . V_246 = F_142 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_145 ( struct V_224 * V_225 ,
struct V_237 * V_238 ) {
return F_136 ( V_225 , V_238 ,
V_265 ) ;
}
static int F_146 ( struct V_224 * V_225 ,
struct V_237 * V_238 ) {
return F_138 ( V_225 , V_238 ,
V_266 ) ;
}
static int F_147 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_58 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_135 ;
V_207 . V_246 = F_145 ;
V_207 . V_247 = F_146 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_148 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_33 ;
short V_54 ;
T_1 V_267 [ 3 ] ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_149 ( V_52 ,
V_54 , & V_267 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_227 -> type = V_234 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . integer . F_47 = ( ( int ) V_267 [ 0 ] ) / V_251 ;
V_227 -> V_235 . integer . F_48 = ( ( int ) V_267 [ 1 ] ) / V_251 ;
V_227 -> V_235 . integer . V_236 = ( ( int ) V_267 [ 2 ] ) / V_251 ;
return 0 ;
}
static int F_150 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
short V_268 ;
F_52 ( F_151 ( V_52 , & V_268 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] = V_268 / V_251 ;
return 0 ;
}
static int F_152 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
short V_268 ;
V_268 = ( V_238 -> V_235 . integer . V_235 [ 0 ] ) * V_251 ;
F_52 ( F_153 ( V_52 , V_268 ) ) ;
return 1 ;
}
static int F_154 ( struct V_224 * V_225 ,
T_1 * V_269 , T_2 V_270 ) {
T_2 V_52 = V_225 -> V_211 ;
T_1 V_33 = 0 ;
T_2 V_271 ;
for ( V_271 = 0 ; V_271 < V_270 ; V_271 ++ ) {
V_33 = F_155 (
V_52 , V_271 , & V_269 [ V_271 ] ) ;
if ( V_33 != 0 )
break;
}
if ( V_33 && ( V_33 != V_272 ) )
return - V_161 ;
return V_271 ;
}
static int F_156 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_1 V_273 [ V_274 ] ;
int V_275 = 0 ;
V_275 = F_154 ( V_225 , V_273 ,
V_274 ) ;
if ( V_275 < 0 )
return V_275 ;
V_227 -> type = V_253 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . V_254 . V_255 = V_275 ;
if ( V_275 > 0 ) {
if ( V_227 -> V_235 . V_254 . V_256 >=
V_227 -> V_235 . V_254 . V_255 )
V_227 -> V_235 . V_254 . V_256 =
V_227 -> V_235 . V_254 . V_255 - 1 ;
strcpy ( V_227 -> V_235 . V_254 . V_40 ,
V_276 [
V_273 [ V_227 -> V_235 . V_254 . V_256 ] ] ) ;
}
return 0 ;
}
static int F_157 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_277 , V_54 ;
T_1 V_273 [ V_274 ] ;
T_2 V_275 = 0 ;
V_275 = F_154 ( V_225 , V_273 ,
V_274 ) ;
F_52 ( F_158 ( V_52 , & V_277 ) ) ;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = - 1 ;
for ( V_54 = 0 ; V_54 < V_274 ; V_54 ++ )
if ( V_273 [ V_54 ] == V_277 ) {
V_238 -> V_235 . V_254 . V_256 [ 0 ] = V_54 ;
break;
}
return 0 ;
}
static int F_159 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
unsigned int V_54 ;
T_1 V_277 ;
T_1 V_273 [ V_274 ] ;
T_2 V_275 = 0 ;
V_275 = F_154 ( V_225 , V_273 ,
V_274 ) ;
V_54 = V_238 -> V_235 . V_254 . V_256 [ 0 ] ;
if ( V_54 >= F_160 ( V_273 ) )
V_54 = F_160 ( V_273 ) - 1 ;
V_277 = V_273 [ V_54 ] ;
F_52 ( F_161 ( V_52 , V_277 ) ) ;
return 1 ;
}
static int F_162 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_33 ;
T_1 V_273 [ V_274 ] ;
T_1 V_275 = 0 , V_278 , V_54 ;
T_2 V_279 [ 3 ] , V_280 [ 3 ] ;
V_275 = F_154 ( V_225 , V_273 ,
V_274 ) ;
V_279 [ 0 ] = V_281 ;
V_279 [ 1 ] = 0 ;
V_279 [ 2 ] = V_281 ;
for ( V_278 = 0 ; V_278 < V_275 ; V_278 ++ ) {
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_163 ( V_52 ,
V_54 , V_273 [ V_278 ] ,
& V_280 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
if ( V_280 [ 2 ] <= 0 )
continue;
if ( V_280 [ 0 ] < V_279 [ 0 ] )
V_279 [ 0 ] = V_280 [ 0 ] ;
if ( V_280 [ 1 ] > V_279 [ 1 ] )
V_279 [ 1 ] = V_280 [ 1 ] ;
if ( V_280 [ 2 ] < V_279 [ 2 ] )
V_279 [ 2 ] = V_280 [ 2 ] ;
}
V_227 -> type = V_234 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . integer . F_47 = ( ( int ) V_279 [ 0 ] ) ;
V_227 -> V_235 . integer . F_48 = ( ( int ) V_279 [ 1 ] ) ;
V_227 -> V_235 . integer . V_236 = ( ( int ) V_279 [ 2 ] ) ;
return 0 ;
}
static int F_164 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_282 ;
F_52 ( F_165 ( V_52 , & V_282 ) ) ;
V_238 -> V_235 . integer . V_235 [ 0 ] = V_282 ;
return 0 ;
}
static int F_166 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_282 ;
V_282 = V_238 -> V_235 . integer . V_235 [ 0 ] ;
F_52 ( F_167 ( V_52 , V_282 ) ) ;
return 1 ;
}
static int F_168 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
V_207 . V_211 = V_209 -> V_52 ;
V_207 . V_243 = V_244 ;
if ( ! F_151 ( V_209 -> V_52 , NULL ) ) {
F_115 ( & V_207 , V_209 , L_60 ) ;
V_207 . V_175 = F_148 ;
V_207 . V_246 = F_150 ;
V_207 . V_247 = F_152 ;
if ( F_112 ( V_85 , & V_207 , V_49 ) < 0 )
return - V_47 ;
}
F_115 ( & V_207 , V_209 , L_61 ) ;
V_207 . V_175 = F_156 ;
V_207 . V_246 = F_157 ;
V_207 . V_247 = F_159 ;
if ( F_112 ( V_85 , & V_207 , V_49 ) < 0 )
return - V_47 ;
F_115 ( & V_207 , V_209 , L_62 ) ;
V_207 . V_175 = F_162 ;
V_207 . V_246 = F_164 ;
V_207 . V_247 = F_166 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_169 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_228 ;
T_1 V_33 ;
V_33 = F_118 ( V_52 , & V_228 ) ;
if ( V_33 )
V_228 = V_233 ;
V_227 -> type = V_234 ;
V_227 -> V_228 = V_228 ;
V_227 -> V_235 . integer . F_47 = 0 ;
V_227 -> V_235 . integer . F_48 = 0x7FFFFFFF ;
return 0 ;
}
static int F_170 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
short V_239 [ V_233 ] , V_271 ;
T_1 V_33 ;
V_33 = F_171 ( V_52 , V_239 ) ;
for ( V_271 = 0 ; V_271 < V_233 ; V_271 ++ ) {
if ( V_33 ) {
V_238 -> V_235 . integer . V_235 [ V_271 ] = 0 ;
} else if ( V_239 [ V_271 ] >= 0 ) {
V_238 -> V_235 . integer . V_235 [ V_271 ] =
V_239 [ V_271 ] << 16 ;
} else {
V_238 -> V_235 . integer . V_235 [ V_271 ] =
V_283 [ V_239 [ V_271 ] / - 1000 ] ;
}
}
return 0 ;
}
static int F_172 ( struct V_48 * V_49 ,
struct V_208 * V_209 , int V_284 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_63 ) ;
V_207 . V_243 =
V_263 | V_264 ;
V_207 . V_175 = F_169 ;
V_207 . V_246 = F_170 ;
V_207 . V_158 = V_284 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_173 ( struct V_224 * V_207 )
{
T_2 V_52 = V_207 -> V_211 ;
struct V_208 V_209 ;
int V_103 , V_33 ;
for ( V_103 = 0 ; V_103 < 32 ; V_103 ++ ) {
V_33 = F_174 ( V_52 , V_103 ,
& V_209 .
V_214 ,
& V_209 .
V_221 ) ;
if ( V_33 )
break;
}
return V_103 ;
}
static int F_175 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
int V_33 ;
T_1 V_214 , V_221 ;
T_2 V_52 = V_225 -> V_211 ;
V_227 -> type = V_253 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . V_254 . V_255 =
F_173 ( V_225 ) ;
if ( V_227 -> V_235 . V_254 . V_256 >= V_227 -> V_235 . V_254 . V_255 )
V_227 -> V_235 . V_254 . V_256 =
V_227 -> V_235 . V_254 . V_255 - 1 ;
V_33 =
F_174 ( V_52 ,
V_227 -> V_235 . V_254 . V_256 ,
& V_214 , & V_221 ) ;
sprintf ( V_227 -> V_235 . V_254 . V_40 , L_64 ,
V_220 [ V_214 - V_215 ] ,
V_221 ) ;
return 0 ;
}
static int F_176 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_285 , V_286 ;
T_1 V_214 , V_221 ;
int V_103 ;
F_52 ( F_177 ( V_52 ,
& V_285 , & V_286 ) ) ;
for ( V_103 = 0 ; V_103 < 256 ; V_103 ++ ) {
if ( F_174 ( V_52 , V_103 ,
& V_214 , & V_221 ) )
break;
if ( ( V_285 == V_214 )
&& ( V_286 == V_221 ) ) {
V_238 -> V_235 . V_254 . V_256 [ 0 ] = V_103 ;
return 0 ;
}
}
F_29 ( V_35
L_65 ,
V_52 , V_285 , V_286 ) ;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = 0 ;
return 0 ;
}
static int F_178 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
T_1 V_285 , V_286 ;
T_1 V_29 ;
V_240 = 1 ;
V_29 = F_174 ( V_52 ,
V_238 -> V_235 . V_254 . V_256 [ 0 ] ,
& V_285 , & V_286 ) ;
if ( ! V_29 )
F_52 (
F_179 ( V_52 ,
V_285 , V_286 ) ) ;
return V_240 ;
}
static int F_180 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_66 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_175 ;
V_207 . V_246 = F_176 ;
V_207 . V_247 = F_178 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_181 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
static const char * const V_287 [ V_288 + 1 ] = {
L_67 ,
L_68 , L_69 ,
L_70 , L_71 ,
L_72 , L_73
} ;
T_2 V_52 = V_225 -> V_211 ;
T_1 V_289 ;
int V_271 ;
T_1 V_290 [ 6 ] ;
int V_291 = 0 ;
for ( V_271 = 0 ; V_271 < V_288 ; V_271 ++ )
if ( ! F_182 (
V_52 , V_271 , & V_289 ) ) {
V_290 [ V_291 ] = V_289 ;
V_291 ++ ;
}
if ( ! V_291 )
return - V_47 ;
V_227 -> type = V_253 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . V_254 . V_255 = V_291 ;
if ( V_227 -> V_235 . V_254 . V_256 >= V_291 )
V_227 -> V_235 . V_254 . V_256 = V_291 - 1 ;
strcpy ( V_227 -> V_235 . V_254 . V_40 ,
V_287 [ V_290 [ V_227 -> V_235 . V_254 . V_256 ] ] ) ;
return 0 ;
}
static int F_183 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_1 V_289 ;
if ( F_184 ( V_52 , & V_289 ) )
V_289 = 1 ;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = V_289 - 1 ;
return 0 ;
}
static int F_185 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
V_240 = 1 ;
F_52 ( F_186 ( V_52 ,
V_238 -> V_235 . V_254 . V_256 [ 0 ] + 1 ) ) ;
return V_240 ;
}
static int F_187 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
F_115 ( & V_207 , V_209 , L_74 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_181 ;
V_207 . V_246 = F_183 ;
V_207 . V_247 = F_185 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_188 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_225 -> V_84 ) ;
struct V_292 * V_293 = & V_49 -> V_294 ;
V_227 -> type = V_253 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . V_254 . V_255 = V_293 -> V_228 ;
if ( V_227 -> V_235 . V_254 . V_256 >= V_227 -> V_235 . V_254 . V_255 )
V_227 -> V_235 . V_254 . V_256 =
V_227 -> V_235 . V_254 . V_255 - 1 ;
strcpy ( V_227 -> V_235 . V_254 . V_40 ,
V_293 -> V_103 [ V_227 -> V_235 . V_254 . V_256 ] . V_40 ) ;
return 0 ;
}
static int F_189 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_225 -> V_84 ) ;
struct V_292 * V_293 = & V_49 -> V_294 ;
T_2 V_52 = V_225 -> V_211 ;
T_1 V_258 , V_295 = 0 ;
int V_271 ;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = 0 ;
if ( F_190 ( V_52 , & V_258 ) )
V_258 = 0 ;
if ( V_258 == V_296 )
if ( F_191 ( V_52 , & V_295 ) )
V_295 = 0 ;
for ( V_271 = 0 ; V_271 < V_293 -> V_228 ; V_271 ++ )
if ( ( V_293 -> V_103 [ V_271 ] . V_258 == V_258 ) &&
( V_293 -> V_103 [ V_271 ] . V_158 == V_295 ) )
break;
V_238 -> V_235 . V_254 . V_256 [ 0 ] = V_271 ;
return 0 ;
}
static int F_192 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_225 -> V_84 ) ;
struct V_292 * V_293 = & V_49 -> V_294 ;
unsigned int V_256 ;
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
V_240 = 1 ;
V_256 = V_238 -> V_235 . V_254 . V_256 [ 0 ] ;
if ( V_256 >= V_293 -> V_228 )
V_256 = V_293 -> V_228 - 1 ;
F_52 ( F_193 (
V_52 , V_293 -> V_103 [ V_256 ] . V_258 ) ) ;
if ( V_293 -> V_103 [ V_256 ] . V_258 == V_296 )
F_52 ( F_194 (
V_52 , V_293 -> V_103 [ V_256 ] . V_158 ) ) ;
return V_240 ;
}
static int F_195 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
V_227 -> type = V_234 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . integer . F_47 = 8000 ;
V_227 -> V_235 . integer . F_48 = 192000 ;
V_227 -> V_235 . integer . V_236 = 100 ;
return 0 ;
}
static int F_196 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_297 ;
T_1 V_29 ;
V_29 = F_197 ( V_52 , & V_297 ) ;
if ( ! V_29 )
V_238 -> V_235 . integer . V_235 [ 0 ] = V_297 ;
else
V_238 -> V_235 . integer . V_235 [ 0 ] = 0 ;
return 0 ;
}
static int F_198 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
int V_240 ;
T_2 V_52 = V_225 -> V_211 ;
V_240 = 1 ;
F_52 ( F_199 ( V_52 ,
V_238 -> V_235 . integer . V_235 [ 0 ] ) ) ;
return V_240 ;
}
static int F_200 ( struct V_224 * V_225 ,
struct V_226 * V_227 )
{
V_227 -> type = V_234 ;
V_227 -> V_228 = 1 ;
V_227 -> V_235 . integer . F_47 = 8000 ;
V_227 -> V_235 . integer . F_48 = 192000 ;
V_227 -> V_235 . integer . V_236 = 100 ;
return 0 ;
}
static int F_201 ( struct V_224 * V_225 ,
struct V_237 * V_238 )
{
T_2 V_52 = V_225 -> V_211 ;
T_2 V_297 ;
T_1 V_29 ;
V_29 = F_45 ( V_52 , & V_297 ) ;
if ( ! V_29 )
V_238 -> V_235 . integer . V_235 [ 0 ] = V_297 ;
else
V_238 -> V_235 . integer . V_235 [ 0 ] = 0 ;
return 0 ;
}
static int F_202 ( struct V_48 * V_49 ,
struct V_208 * V_209 )
{
struct V_203 * V_85 = V_49 -> V_85 ;
struct V_204 V_207 ;
struct V_292 * V_293 = & V_49 -> V_294 ;
T_2 V_298 = V_209 -> V_52 ;
int V_299 = 0 ;
int V_271 , V_300 ;
T_1 V_258 ;
V_207 . V_211 = V_209 -> V_52 ;
V_293 -> V_301 = 0 ;
for ( V_271 = 0 ; V_271 <= V_302 ; V_271 ++ ) {
if ( F_203 ( V_298 ,
V_271 , & V_258 ) )
break;
V_293 -> V_103 [ V_271 ] . V_258 = V_258 ;
V_293 -> V_103 [ V_271 ] . V_158 = 0 ;
V_293 -> V_103 [ V_271 ] . V_40 = V_303 [ V_258 ] ;
if ( V_258 == V_296 )
V_299 = 1 ;
if ( V_258 == V_304 )
V_293 -> V_301 = 1 ;
}
if ( V_299 )
for ( V_300 = 1 ; V_300 < 8 ; V_300 ++ ) {
if ( F_204 ( V_298 ,
V_300 , V_296 ,
& V_258 ) )
break;
V_293 -> V_103 [ V_271 ] . V_258 =
V_296 ;
V_293 -> V_103 [ V_271 ] . V_158 = V_300 ;
V_293 -> V_103 [ V_271 ] . V_40 = V_303 [
V_300 + V_302 ] ;
V_271 ++ ;
}
V_293 -> V_228 = V_271 ;
F_115 ( & V_207 , V_209 , L_75 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_188 ;
V_207 . V_246 = F_189 ;
V_207 . V_247 = F_192 ;
if ( F_112 ( V_85 , & V_207 , V_49 ) < 0 )
return - V_47 ;
if ( V_293 -> V_301 ) {
F_115 ( & V_207 , V_209 , L_76 ) ;
V_207 . V_243 = V_244 ;
V_207 . V_175 = F_195 ;
V_207 . V_246 = F_196 ;
V_207 . V_247 = F_198 ;
if ( F_112 ( V_85 , & V_207 , V_49 ) < 0 )
return - V_47 ;
}
F_115 ( & V_207 , V_209 , L_77 ) ;
V_207 . V_243 =
V_263 | V_264 ;
V_207 . V_175 = F_200 ;
V_207 . V_246 = F_201 ;
return F_112 ( V_85 , & V_207 , V_49 ) ;
}
static int F_205 ( struct V_48 * V_49 )
{
struct V_203 * V_85 ;
unsigned int V_54 = 0 ;
unsigned int V_305 = 0 ;
int V_33 ;
struct V_208 V_209 , V_306 ;
if ( F_206 ( ! V_49 ) )
return - V_47 ;
V_85 = V_49 -> V_85 ;
strcpy ( V_85 -> V_307 , L_78 ) ;
V_33 =
F_207 ( V_49 -> V_156 -> V_157 -> V_158 ,
& V_49 -> V_61 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
return - V_33 ;
memset ( & V_306 , 0 , sizeof( V_306 ) ) ;
V_306 . V_308 = - 1 ;
for ( V_54 = 0 ; V_54 < 2000 ; V_54 ++ ) {
V_33 = F_208 (
V_49 -> V_61 ,
V_54 ,
& V_209 . V_214 ,
& V_209 . V_221 ,
& V_209 . V_216 ,
& V_209 . V_223 ,
& V_209 . V_308 ,
& V_209 . V_52 ) ;
if ( V_33 ) {
if ( V_33 == V_309 ) {
if ( V_206 )
F_44 ( V_150
L_79 ,
V_54 ) ;
continue;
} else
break;
}
V_209 . V_214 -= V_215 ;
V_209 . V_216 -= V_217 ;
if ( ( V_209 . V_308 == V_306 . V_308 ) &&
( V_209 . V_214 == V_306 . V_214 ) &&
( V_209 . V_221 == V_306 . V_221 ) &&
( V_209 . V_216 == V_306 . V_216 ) &&
( V_209 . V_223 == V_306 . V_223 ) )
V_305 ++ ;
else
V_305 = 0 ;
V_306 = V_209 ;
switch ( V_209 . V_308 ) {
case V_310 :
V_33 = F_127 ( V_49 , & V_209 ) ;
break;
case V_311 :
V_33 = F_134 ( V_49 , & V_209 ) ;
break;
case V_312 :
V_33 = F_180 ( V_49 , & V_209 ) ;
break;
case V_313 :
V_33 = F_187 ( V_49 , & V_209 ) ;
break;
case V_314 :
V_33 = F_172 ( V_49 , & V_209 , V_305 ) ;
break;
case V_63 :
V_33 = F_202 (
V_49 , & V_209 ) ;
break;
case V_315 :
continue;
case V_316 :
V_33 = F_168 ( V_49 , & V_209 ) ;
break;
case V_317 :
V_33 = F_147 ( V_49 , & V_209 ) ;
break;
case V_318 :
V_33 = F_144 ( V_49 , & V_209 ) ;
break;
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
default:
if ( V_206 )
F_44 ( V_150
L_80
L_81 ,
V_54 ,
V_209 . V_308 ,
V_209 . V_214 ,
V_209 . V_221 ,
V_209 . V_216 ,
V_209 . V_223 ) ;
continue;
}
if ( V_33 < 0 )
return V_33 ;
}
if ( V_272 != V_33 )
F_52 ( V_33 ) ;
F_44 ( V_150 L_82 , V_54 ) ;
return 0 ;
}
static void
F_209 ( struct V_324 * V_325 ,
struct V_326 * V_17 )
{
struct V_48 * V_49 = V_325 -> V_84 ;
T_2 V_52 ;
T_2 V_297 = 0 ;
T_1 V_258 = 0 ;
T_1 V_195 ;
T_1 V_194 ;
T_1 V_327 ;
T_2 V_328 ;
T_1 type ;
int V_33 ;
F_210 ( V_17 , L_83 ) ;
F_52 ( F_107 ( V_49 -> V_156 -> V_157 -> V_158 ,
& V_195 , & V_194 ,
& V_327 , & V_328 , & type ) ) ;
F_210 ( V_17 ,
L_84
L_85 ,
type , V_49 -> V_156 -> V_157 -> V_158 ,
V_195 , V_194 ) ;
F_210 ( V_17 ,
L_86 ,
V_328 , ( ( V_327 >> 3 ) & 0xf ) + 'A' , V_327 & 0x7 ,
( ( V_327 >> 13 ) * 100 ) + ( ( V_327 >> 7 ) & 0x3f ) ) ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 ) {
V_33 = F_45 ( V_52 , & V_297 ) ;
V_33 += F_190 ( V_52 , & V_258 ) ;
if ( ! V_33 )
F_210 ( V_17 , L_87 ,
V_297 , V_303 [ V_258 ] ) ;
}
}
static void F_211 ( struct V_48 * V_49 )
{
struct V_324 * V_325 ;
if ( ! F_212 ( V_49 -> V_85 , L_88 , & V_325 ) )
F_213 ( V_325 , V_49 , F_209 ) ;
}
static int F_214 ( struct V_329 * V_184 , struct V_330 * V_330 )
{
if ( V_331 )
return 0 ;
else
return - V_332 ;
}
static int F_215 ( struct V_329 * V_184 , struct V_330 * V_330 )
{
if ( V_331 )
return F_216 ( V_330 ) ;
else
return - V_332 ;
}
static int F_217 ( struct V_329 * V_184 , struct V_330 * V_330 ,
unsigned int V_102 , unsigned long V_149 )
{
if ( V_331 )
return F_218 ( V_330 , V_102 , V_149 ) ;
else
return - V_332 ;
}
static int F_219 ( struct V_48 * V_49 ,
int V_191 , struct V_329 * * V_333 )
{
struct V_329 * V_184 ;
int V_33 ;
if ( V_333 )
* V_333 = NULL ;
V_33 = F_220 ( V_49 -> V_85 , L_89 , V_191 , & V_184 ) ;
if ( V_33 < 0 )
return V_33 ;
strcpy ( V_184 -> V_40 , L_90 ) ;
V_184 -> V_212 = V_334 ;
V_184 -> V_335 . V_336 = F_214 ;
V_184 -> V_335 . V_337 = F_217 ;
V_184 -> V_335 . V_338 = F_215 ;
V_184 -> V_84 = V_49 ;
if ( V_333 )
* V_333 = V_184 ;
return 0 ;
}
static int F_221 ( struct V_339 * V_339 ,
const struct V_340 * V_341 )
{
int V_33 ;
struct V_342 * V_156 ;
struct V_203 * V_85 ;
struct V_48 * V_49 ;
T_2 V_52 ;
T_2 V_1 ;
T_2 V_13 ;
static int V_343 ;
if ( V_343 >= V_344 )
return - V_332 ;
if ( ! V_345 [ V_343 ] ) {
V_343 ++ ;
return - V_346 ;
}
V_33 = F_222 ( V_339 , V_341 ) ;
if ( V_33 < 0 )
return V_33 ;
V_156 = F_223 ( V_339 ) ;
V_13 = V_156 -> V_157 -> V_158 ;
V_33 = F_224 ( & V_339 -> V_343 , V_13 , V_347 [ V_13 ] ,
V_348 , sizeof( struct V_48 ) , & V_85 ) ;
if ( V_33 < 0 ) {
V_33 = F_224 ( & V_339 -> V_343 , V_158 [ V_343 ] , V_347 [ V_343 ] ,
V_348 , sizeof( struct V_48 ) ,
& V_85 ) ;
if ( V_33 < 0 )
return V_33 ;
F_44 ( V_35
L_91 ,
V_13 , V_85 -> V_109 ) ;
}
V_49 = V_85 -> V_84 ;
V_49 -> V_85 = V_85 ;
V_49 -> V_202 = V_339 ;
V_49 -> V_156 = V_156 ;
F_44 ( V_150 L_92 ,
V_49 -> V_156 -> V_157 -> type , V_13 ) ;
V_33 = F_225 ( V_13 ,
V_349 ,
NULL , & V_49 -> V_112 ) ;
if ( V_33 )
V_49 -> V_112 = 0 ;
V_33 = F_225 ( V_13 ,
V_350 ,
& V_49 -> V_58 , NULL ) ;
if ( V_33 )
V_49 -> V_58 = 0 ;
V_33 = F_225 ( V_13 ,
V_351 ,
NULL , & V_49 -> V_187 ) ;
if ( V_33 )
V_49 -> V_187 = 512 ;
if ( ! V_49 -> V_91 )
V_49 -> V_187 *= 2 ;
F_52 ( F_103 ( V_13 ,
0 , & V_1 ) ) ;
V_33 = F_226 ( V_1 ) ;
V_49 -> V_91 = ( ! V_33 ) ;
F_52 ( F_105 ( V_1 ) ) ;
V_33 = F_225 ( V_13 ,
V_352 ,
& V_49 -> V_188 , & V_49 -> V_153 ) ;
if ( V_33 ) {
V_49 -> V_188 = 2 ;
V_49 -> V_153 = 2 ;
}
if ( V_49 -> V_153 > 2 ) {
V_49 -> V_174 = V_49 -> V_153 ;
V_49 -> V_190 = V_49 -> V_188 ;
V_49 -> V_112 = 0 ;
} else {
V_49 -> V_174 = 1 ;
V_49 -> V_190 = 1 ;
}
F_44 ( V_150 L_93 ,
V_49 -> V_91 ,
V_49 -> V_112 ,
V_49 -> V_58
) ;
V_33 = F_106 ( V_49 , 0 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_94 ) ;
goto V_353;
}
V_33 = F_205 ( V_49 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_95 ) ;
goto V_353;
}
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_199 (
V_52 , V_354 ) ;
F_211 ( V_49 ) ;
F_219 ( V_49 , 0 , NULL ) ;
strcpy ( V_85 -> V_355 , L_96 ) ;
sprintf ( V_85 -> V_356 , L_97 ,
V_49 -> V_156 -> V_157 -> type ) ;
sprintf ( V_85 -> V_357 , L_98 ,
V_85 -> V_356 , V_13 ) ;
V_33 = F_227 ( V_85 ) ;
if ( ! V_33 ) {
V_156 -> V_203 = V_85 ;
V_343 ++ ;
return 0 ;
}
V_353:
F_228 ( V_85 ) ;
F_44 ( V_64 L_99 , V_33 ) ;
return V_33 ;
}
static void F_229 ( struct V_339 * V_339 )
{
struct V_342 * V_156 = F_223 ( V_339 ) ;
F_228 ( V_156 -> V_203 ) ;
V_156 -> V_203 = NULL ;
F_230 ( V_339 ) ;
}
static int T_6 F_231 ( void )
{
F_232 () ;
return F_233 ( & V_355 ) ;
}
static void T_7 F_234 ( void )
{
F_235 ( & V_355 ) ;
F_236 () ;
}
