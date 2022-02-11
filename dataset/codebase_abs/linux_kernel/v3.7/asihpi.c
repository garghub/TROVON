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
F_73 ( V_103 , V_138 ) ;
continue;
}
} else {
V_105 -> V_106 = 0 ;
}
} else
V_125 = V_132 + V_105 -> V_111 ;
if ( V_130 ) {
V_126 = V_125 ;
V_124 = ( V_125 - V_105 -> V_139 ) % V_105 -> V_94 ;
V_130 = 0 ;
} else {
V_126 =
F_71 ( V_126 , V_125 , V_140 + 1L ) ;
V_124 = F_47 (
( V_125 - V_105 -> V_139 ) % V_105 -> V_94 ,
V_124 ) ;
}
F_56 ( L_30 ,
( unsigned long ) F_74 ( V_81 ,
V_81 -> V_114 -> V_141 ) ,
( unsigned long ) F_74 ( V_81 ,
V_81 -> V_142 -> V_143 ) ) ;
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
unsigned int V_144 = V_105 -> V_111 % V_105 -> V_94 ;
unsigned int V_145 , V_146 ;
char * V_147 = & V_103 -> V_81 -> V_110 [ V_144 ] ;
if ( V_85 -> V_91 ) {
V_145 = V_128 ;
V_146 = 0 ;
} else {
V_145 = F_47 ( V_128 , V_105 -> V_94 - V_144 ) ;
V_146 = V_128 - V_145 ;
}
if ( V_103 -> V_88 == V_107 ) {
F_67 ( L_35 ,
V_103 -> V_109 , V_145 , V_144 ) ;
F_52 (
F_68 (
V_105 -> V_1 , V_147 , V_145 ,
& V_105 -> V_43 ) ) ;
if ( V_146 ) {
V_147 = V_103 -> V_81 -> V_110 ;
F_67 ( L_36 ,
V_103 -> V_109 ,
V_128 - V_145 , V_144 ) ;
F_52 (
F_68 (
V_105 -> V_1 , V_147 ,
V_128 - V_145 ,
& V_105 -> V_43 ) ) ;
}
} else {
F_67 ( L_37 ,
V_103 -> V_109 , V_145 ) ;
F_52 (
F_75 (
V_105 -> V_1 ,
V_147 , V_145 ) ) ;
if ( V_146 ) {
V_147 = V_103 -> V_81 -> V_110 ;
F_67 ( L_38 ,
V_103 -> V_109 , V_146 ) ;
F_52 (
F_75 (
V_105 -> V_1 ,
V_147 , V_146 ) ) ;
}
}
V_105 -> V_111 += V_128 ;
V_105 -> V_139 += V_128 ;
F_76 ( V_103 ) ;
}
}
if ( V_83 -> V_101 )
F_62 ( & V_83 -> V_98 ) ;
}
static int F_77 ( struct V_36 * V_37 ,
unsigned int V_102 , void * V_148 )
{
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
F_67 ( V_149 L_39 , V_40 , V_102 ) ;
return F_78 ( V_37 , V_102 , V_148 ) ;
}
static int F_79 ( struct V_36 *
V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_56 ( L_40 , V_37 -> V_109 ) ;
F_52 ( F_70 ( V_83 -> V_1 ) ) ;
V_83 -> V_111 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_139 = 0 ;
return 0 ;
}
static T_4
F_80 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
T_4 V_150 ;
char V_40 [ 16 ] ;
F_28 ( V_37 , V_40 , sizeof( V_40 ) ) ;
V_150 = F_81 ( V_81 , V_83 -> V_125 % V_83 -> V_94 ) ;
F_67 ( L_41 , V_40 , ( unsigned long ) V_150 ) ;
return V_150 ;
}
static T_5 F_82 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_151 = 0 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 , V_49 -> V_152 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_83 ( V_1 , & V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_151 |= ( 1ULL << V_46 [ V_43 ] ) ;
}
return V_151 ;
}
static int F_84 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_50 V_153 ;
int V_33 ;
V_83 = F_85 ( sizeof( * V_83 ) , V_154 ) ;
if ( V_83 == NULL )
return - V_93 ;
V_33 = F_86 ( V_85 -> V_155 -> V_156 -> V_157 ,
V_37 -> V_109 , & V_83 -> V_1 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_158 )
return - V_159 ;
if ( V_33 )
return - V_160 ;
F_87 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_161 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_162 = F_59 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_163 = V_164 ;
V_153 . V_165 = V_166 ;
V_153 . V_167 = V_164 / V_168 ;
V_153 . V_169 = V_168 ;
V_153 . V_170 = V_164 / V_166 ;
V_153 . V_171 = V_85 -> V_152 ;
V_153 . V_172 = V_85 -> V_173 ;
V_153 . V_151 =
F_82 ( V_85 , V_83 -> V_1 ) ;
F_42 ( V_85 , & V_153 ) ;
V_153 . V_174 = V_175 |
V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 ;
if ( V_85 -> V_112 ) {
V_153 . V_174 |= V_182 ;
F_88 ( V_37 ) ;
}
V_81 -> V_183 = V_153 ;
if ( V_85 -> V_91 )
V_33 = F_89 ( V_81 , 0 ,
V_184 ) ;
if ( V_33 < 0 )
return V_33 ;
F_90 ( V_81 , 0 , V_185 ,
V_85 -> V_186 ) ;
F_91 ( V_81 , V_185 ,
V_85 -> V_186 * 2 , V_140 ) ;
F_56 ( L_42 ) ;
return 0 ;
}
static int F_92 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_52 ( F_93 ( V_83 -> V_1 ) ) ;
F_56 ( L_43 ) ;
return 0 ;
}
static T_4
F_94 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_67 ( L_44 ,
V_37 -> V_109 , V_83 -> V_125 ) ;
return F_81 ( V_81 , V_83 -> V_125 % V_83 -> V_94 ) ;
}
static int F_95 ( struct V_36 * V_37 ,
unsigned int V_102 , void * V_148 )
{
return F_78 ( V_37 , V_102 , V_148 ) ;
}
static int F_96 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 = V_81 -> V_84 ;
F_52 ( F_54 ( V_83 -> V_1 ) ) ;
V_83 -> V_111 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_139 = 0 ;
F_56 ( L_45 , V_37 -> V_109 ) ;
return 0 ;
}
static T_5 F_97 ( struct V_48 * V_49 ,
T_2 V_1 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
T_5 V_151 = 0 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 , V_49 -> V_187 ,
V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_98 ( V_1 , & V_42 ) ;
if ( ! V_33 )
V_151 |= ( 1ULL << V_46 [ V_43 ] ) ;
}
return V_151 ;
}
static int F_99 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_82 * V_83 ;
struct V_50 V_188 ;
int V_33 ;
V_83 = F_85 ( sizeof( * V_83 ) , V_154 ) ;
if ( V_83 == NULL )
return - V_93 ;
F_56 ( L_46 ,
V_85 -> V_155 -> V_156 -> V_157 , V_37 -> V_109 ) ;
V_33 = F_52 (
F_100 ( V_85 -> V_155 -> V_156 -> V_157 ,
V_37 -> V_109 , & V_83 -> V_1 ) ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_158 )
return - V_159 ;
if ( V_33 )
return - V_160 ;
F_87 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_161 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_162 = F_59 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_163 = V_164 ;
V_188 . V_165 = V_166 ;
V_188 . V_167 = V_164 / V_168 ;
V_188 . V_169 = V_168 ;
V_188 . V_170 = V_164 / V_166 ;
V_188 . V_171 = V_85 -> V_187 ;
V_188 . V_172 = V_85 -> V_189 ;
V_188 . V_151 =
F_97 ( V_85 , V_83 -> V_1 ) ;
F_42 ( V_85 , & V_188 ) ;
V_188 . V_174 = V_175 |
V_180 |
V_181 ;
if ( V_85 -> V_112 )
V_188 . V_174 |= V_182 ;
V_81 -> V_183 = V_188 ;
if ( V_85 -> V_91 )
V_33 = F_89 ( V_81 , 0 ,
V_184 ) ;
if ( V_33 < 0 )
return V_33 ;
F_90 ( V_81 , 0 , V_185 ,
V_85 -> V_186 ) ;
F_91 ( V_81 , V_185 ,
V_85 -> V_186 * 2 , V_140 ) ;
F_88 ( V_37 ) ;
return 0 ;
}
static int F_101 ( struct V_36 * V_37 )
{
struct V_82 * V_83 = V_37 -> V_81 -> V_84 ;
F_52 ( F_102 ( V_83 -> V_1 ) ) ;
return 0 ;
}
static int T_6 F_103 (
struct V_48 * V_49 , int V_190 )
{
struct V_191 * V_192 ;
int V_33 ;
T_1 V_193 , V_194 , V_195 ;
T_2 V_196 ;
V_33 = F_104 ( V_49 -> V_155 -> V_156 -> V_157 ,
& V_194 , & V_193 ,
& V_195 , & V_196 , & V_195 ) ;
V_33 = F_105 ( V_49 -> V_85 , L_47 , V_190 ,
V_194 , V_193 , & V_192 ) ;
if ( V_33 < 0 )
return V_33 ;
F_106 ( V_192 , V_107 ,
& V_197 ) ;
F_106 ( V_192 , V_89 ,
& V_198 ) ;
V_192 -> V_84 = V_49 ;
V_192 -> V_199 = 0 ;
strcpy ( V_192 -> V_40 , L_47 ) ;
F_107 ( V_192 , V_200 ,
F_108 ( V_49 -> V_201 ) ,
64 * 1024 , V_164 ) ;
return 0 ;
}
static inline int F_109 ( struct V_202 * V_85 , struct V_203 * V_204 ,
struct V_48 * V_49 )
{
int V_33 ;
V_33 = F_110 ( V_85 , F_111 ( V_204 , V_49 ) ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_205 )
F_44 ( V_149 L_48 , V_204 -> V_40 , V_204 -> V_157 ) ;
return 0 ;
}
static void F_112 ( struct V_203 * V_206 ,
struct V_207 * V_208 ,
char * V_40 )
{
char * V_209 ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_40 = V_208 -> V_40 ;
V_206 -> V_210 = V_208 -> V_52 ;
V_206 -> V_211 = V_212 ;
V_206 -> V_157 = 0 ;
if ( V_208 -> V_213 + V_214 == V_62 )
V_209 = L_49 ;
else if ( V_208 -> V_215 + V_216 == V_217 )
V_209 = L_50 ;
else if ( ( V_208 -> V_213 + V_214 != V_218 ) &&
( ! V_208 -> V_215 ) )
V_209 = L_50 ;
else if ( V_208 -> V_213 &&
( V_208 -> V_213 + V_214 != V_218 ) &&
( V_208 -> V_215 ) )
V_209 = L_51 ;
else
V_209 = L_52 ;
if ( V_208 -> V_213 && V_208 -> V_215 )
sprintf ( V_208 -> V_40 , L_53 ,
V_219 [ V_208 -> V_213 ] ,
V_208 -> V_220 ,
V_221 [ V_208 -> V_215 ] ,
V_208 -> V_222 ,
V_209 , V_40 ) ;
else if ( V_208 -> V_215 ) {
sprintf ( V_208 -> V_40 , L_54 ,
V_221 [ V_208 -> V_215 ] ,
V_208 -> V_222 ,
V_209 , V_40 ) ;
} else {
sprintf ( V_208 -> V_40 , L_54 ,
V_219 [ V_208 -> V_213 ] ,
V_208 -> V_220 ,
V_209 , V_40 ) ;
}
}
static int F_113 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_227 ;
T_1 V_33 ;
short V_228 ;
short V_229 ;
short V_230 ;
V_33 = F_114 ( V_52 ,
& V_228 , & V_229 , & V_230 ) ;
if ( V_33 ) {
V_229 = 0 ;
V_228 = - 10000 ;
V_230 = V_231 ;
}
V_33 = F_115 ( V_52 , & V_227 ) ;
if ( V_33 )
V_227 = V_232 ;
V_226 -> type = V_233 ;
V_226 -> V_227 = V_227 ;
V_226 -> V_234 . integer . F_47 = V_228 / V_231 ;
V_226 -> V_234 . integer . F_48 = V_229 / V_231 ;
V_226 -> V_234 . integer . V_235 = V_230 / V_231 ;
return 0 ;
}
static int F_116 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
short V_238 [ V_232 ] ;
F_52 ( F_117 ( V_52 , V_238 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] = V_238 [ 0 ] / V_231 ;
V_237 -> V_234 . integer . V_234 [ 1 ] = V_238 [ 1 ] / V_231 ;
return 0 ;
}
static int F_118 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
int V_239 ;
T_2 V_52 = V_224 -> V_210 ;
short V_238 [ V_232 ] ;
V_238 [ 0 ] =
( V_237 -> V_234 . integer . V_234 [ 0 ] ) * V_231 ;
V_238 [ 1 ] =
( V_237 -> V_234 . integer . V_234 [ 1 ] ) * V_231 ;
V_239 = 1 ;
F_52 ( F_119 ( V_52 , V_238 ) ) ;
return V_239 ;
}
static int F_120 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_240 ;
F_52 ( F_121 ( V_52 , & V_240 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] = V_240 ? 0 : 1 ;
return 0 ;
}
static int F_122 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
int V_239 = 1 ;
int V_240 = V_237 -> V_234 . integer . V_234 [ 0 ] ? 0 : V_241 ;
F_52 ( F_123 ( V_52 , V_240 ) ) ;
return V_239 ;
}
static int T_6 F_124 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
int V_33 ;
T_2 V_240 ;
F_112 ( & V_206 , V_208 , L_55 ) ;
V_206 . V_242 = V_243 |
V_244 ;
V_206 . V_174 = F_113 ;
V_206 . V_245 = F_116 ;
V_206 . V_246 = F_118 ;
V_206 . V_247 . V_39 = V_248 ;
V_33 = F_109 ( V_85 , & V_206 , V_49 ) ;
if ( V_33 )
return V_33 ;
if ( F_121 ( V_208 -> V_52 , & V_240 ) == 0 ) {
F_112 ( & V_206 , V_208 , L_56 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = V_249 ;
V_206 . V_245 = F_120 ;
V_206 . V_246 = F_122 ;
V_33 = F_109 ( V_85 , & V_206 , V_49 ) ;
}
return V_33 ;
}
static int F_125 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_33 ;
short V_228 ;
short V_229 ;
short V_230 ;
V_33 =
F_126 ( V_52 , & V_228 ,
& V_229 , & V_230 ) ;
if ( V_33 ) {
V_229 = 2400 ;
V_228 = - 1000 ;
V_230 = 100 ;
}
V_226 -> type = V_233 ;
V_226 -> V_227 = 2 ;
V_226 -> V_234 . integer . F_47 = V_228 / V_250 ;
V_226 -> V_234 . integer . F_48 = V_229 / V_250 ;
V_226 -> V_234 . integer . V_235 = V_230 / V_250 ;
return 0 ;
}
static int F_127 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
short V_238 [ V_232 ] ;
F_52 ( F_128 ( V_52 , V_238 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] =
V_238 [ 0 ] / V_250 ;
V_237 -> V_234 . integer . V_234 [ 1 ] =
V_238 [ 1 ] / V_250 ;
return 0 ;
}
static int F_129 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
int V_239 ;
T_2 V_52 = V_224 -> V_210 ;
short V_238 [ V_232 ] ;
V_238 [ 0 ] =
( V_237 -> V_234 . integer . V_234 [ 0 ] ) * V_250 ;
V_238 [ 1 ] =
( V_237 -> V_234 . integer . V_234 [ 1 ] ) * V_250 ;
V_239 = 1 ;
F_52 ( F_130 ( V_52 , V_238 ) ) ;
return V_239 ;
}
static int T_6 F_131 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_57 ) ;
V_206 . V_242 = V_243 |
V_244 ;
V_206 . V_174 = F_125 ;
V_206 . V_245 = F_127 ;
V_206 . V_246 = F_129 ;
V_206 . V_247 . V_39 = V_251 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_132 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_252 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . V_253 . V_254 = 3 ;
if ( V_226 -> V_234 . V_253 . V_255 >= V_226 -> V_234 . V_253 . V_254 )
V_226 -> V_234 . V_253 . V_255 =
V_226 -> V_234 . V_253 . V_254 - 1 ;
strcpy ( V_226 -> V_234 . V_253 . V_40 ,
V_256 [ V_226 -> V_234 . V_253 . V_255 ] ) ;
return 0 ;
}
static int F_133 ( struct V_223 * V_224 ,
struct V_236 * V_237 ,
T_1 (* F_134)( T_2 , T_1 * ) )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_257 , V_33 ;
V_33 = F_134 ( V_52 , & V_257 ) ;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = 0 ;
if ( V_33 )
return 0 ;
if ( V_257 == V_258 )
V_237 -> V_234 . V_253 . V_255 [ 0 ] = 1 ;
if ( V_257 == V_259 )
V_237 -> V_234 . V_253 . V_255 [ 0 ] = 2 ;
return 0 ;
}
static int F_135 ( struct V_223 * V_224 ,
struct V_236 * V_237 ,
T_1 (* F_134)( T_2 , T_1 ) )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_257 = V_258 ;
if ( V_237 -> V_234 . V_253 . V_255 [ 0 ] == 1 )
V_257 = V_258 ;
if ( V_237 -> V_234 . V_253 . V_255 [ 0 ] == 2 )
V_257 = V_259 ;
if ( F_134 ( V_52 , V_257 ) != 0 )
return - V_47 ;
return 1 ;
}
static int F_136 ( struct V_223 * V_224 ,
struct V_236 * V_237 ) {
return F_133 ( V_224 , V_237 ,
V_260 ) ;
}
static int F_137 ( struct V_223 * V_224 ,
struct V_236 * V_237 ) {
return F_135 ( V_224 , V_237 ,
V_261 ) ;
}
static int F_138 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_233 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . integer . F_47 = 0 ;
V_226 -> V_234 . integer . F_48 = 0X1F ;
V_226 -> V_234 . integer . V_235 = 1 ;
return 0 ;
}
static int F_139 ( struct V_223 * V_224 ,
struct V_236 * V_237 ) {
T_2 V_52 = V_224 -> V_210 ;
T_1 V_114 ;
F_52 ( F_140 (
V_52 , & V_114 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] = V_114 ;
return 0 ;
}
static int T_6 F_141 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_58 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_132 ;
V_206 . V_245 = F_136 ;
V_206 . V_246 = F_137 ;
if ( F_109 ( V_85 , & V_206 , V_49 ) < 0 )
return - V_47 ;
F_112 ( & V_206 , V_208 , L_59 ) ;
V_206 . V_242 =
V_262 | V_263 ;
V_206 . V_174 = F_138 ;
V_206 . V_245 = F_139 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_142 ( struct V_223 * V_224 ,
struct V_236 * V_237 ) {
return F_133 ( V_224 , V_237 ,
V_264 ) ;
}
static int F_143 ( struct V_223 * V_224 ,
struct V_236 * V_237 ) {
return F_135 ( V_224 , V_237 ,
V_265 ) ;
}
static int T_6 F_144 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_58 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_132 ;
V_206 . V_245 = F_142 ;
V_206 . V_246 = F_143 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_145 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_33 ;
short V_54 ;
T_1 V_266 [ 3 ] ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_146 ( V_52 ,
V_54 , & V_266 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_226 -> type = V_233 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . integer . F_47 = ( ( int ) V_266 [ 0 ] ) / V_250 ;
V_226 -> V_234 . integer . F_48 = ( ( int ) V_266 [ 1 ] ) / V_250 ;
V_226 -> V_234 . integer . V_235 = ( ( int ) V_266 [ 2 ] ) / V_250 ;
return 0 ;
}
static int F_147 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
short V_267 ;
F_52 ( F_148 ( V_52 , & V_267 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] = V_267 / V_250 ;
return 0 ;
}
static int F_149 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
short V_267 ;
V_267 = ( V_237 -> V_234 . integer . V_234 [ 0 ] ) * V_250 ;
F_52 ( F_150 ( V_52 , V_267 ) ) ;
return 1 ;
}
static int F_151 ( struct V_223 * V_224 ,
T_1 * V_268 , T_2 V_269 ) {
T_2 V_52 = V_224 -> V_210 ;
T_1 V_33 = 0 ;
T_2 V_270 ;
for ( V_270 = 0 ; V_270 < V_269 ; V_270 ++ ) {
V_33 = F_152 (
V_52 , V_270 , & V_268 [ V_270 ] ) ;
if ( V_33 != 0 )
break;
}
if ( V_33 && ( V_33 != V_271 ) )
return - V_160 ;
return V_270 ;
}
static int F_153 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_1 V_272 [ V_273 ] ;
int V_274 = 0 ;
V_274 = F_151 ( V_224 , V_272 ,
V_273 ) ;
if ( V_274 < 0 )
return V_274 ;
V_226 -> type = V_252 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . V_253 . V_254 = V_274 ;
if ( V_274 > 0 ) {
if ( V_226 -> V_234 . V_253 . V_255 >=
V_226 -> V_234 . V_253 . V_254 )
V_226 -> V_234 . V_253 . V_255 =
V_226 -> V_234 . V_253 . V_254 - 1 ;
strcpy ( V_226 -> V_234 . V_253 . V_40 ,
V_275 [
V_272 [ V_226 -> V_234 . V_253 . V_255 ] ] ) ;
}
return 0 ;
}
static int F_154 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_276 , V_54 ;
T_1 V_272 [ V_273 ] ;
T_2 V_274 = 0 ;
V_274 = F_151 ( V_224 , V_272 ,
V_273 ) ;
F_52 ( F_155 ( V_52 , & V_276 ) ) ;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = - 1 ;
for ( V_54 = 0 ; V_54 < V_273 ; V_54 ++ )
if ( V_272 [ V_54 ] == V_276 ) {
V_237 -> V_234 . V_253 . V_255 [ 0 ] = V_54 ;
break;
}
return 0 ;
}
static int F_156 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_276 ;
T_1 V_272 [ V_273 ] ;
T_2 V_274 = 0 ;
V_274 = F_151 ( V_224 , V_272 ,
V_273 ) ;
V_276 = V_272 [ V_237 -> V_234 . V_253 . V_255 [ 0 ] ] ;
F_52 ( F_157 ( V_52 , V_276 ) ) ;
return 1 ;
}
static int F_158 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_33 ;
T_1 V_272 [ V_273 ] ;
T_1 V_274 = 0 , V_277 , V_54 ;
T_2 V_278 [ 3 ] , V_279 [ 3 ] ;
V_274 = F_151 ( V_224 , V_272 ,
V_273 ) ;
V_278 [ 0 ] = V_280 ;
V_278 [ 1 ] = 0 ;
V_278 [ 2 ] = V_280 ;
for ( V_277 = 0 ; V_277 < V_274 ; V_277 ++ ) {
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_159 ( V_52 ,
V_54 , V_272 [ V_277 ] ,
& V_279 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
if ( V_279 [ 2 ] <= 0 )
continue;
if ( V_279 [ 0 ] < V_278 [ 0 ] )
V_278 [ 0 ] = V_279 [ 0 ] ;
if ( V_279 [ 1 ] > V_278 [ 1 ] )
V_278 [ 1 ] = V_279 [ 1 ] ;
if ( V_279 [ 2 ] < V_278 [ 2 ] )
V_278 [ 2 ] = V_279 [ 2 ] ;
}
V_226 -> type = V_233 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . integer . F_47 = ( ( int ) V_278 [ 0 ] ) ;
V_226 -> V_234 . integer . F_48 = ( ( int ) V_278 [ 1 ] ) ;
V_226 -> V_234 . integer . V_235 = ( ( int ) V_278 [ 2 ] ) ;
return 0 ;
}
static int F_160 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_281 ;
F_52 ( F_161 ( V_52 , & V_281 ) ) ;
V_237 -> V_234 . integer . V_234 [ 0 ] = V_281 ;
return 0 ;
}
static int F_162 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_281 ;
V_281 = V_237 -> V_234 . integer . V_234 [ 0 ] ;
F_52 ( F_163 ( V_52 , V_281 ) ) ;
return 1 ;
}
static int T_6 F_164 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
V_206 . V_210 = V_208 -> V_52 ;
V_206 . V_242 = V_243 ;
if ( ! F_148 ( V_208 -> V_52 , NULL ) ) {
F_112 ( & V_206 , V_208 , L_60 ) ;
V_206 . V_174 = F_145 ;
V_206 . V_245 = F_147 ;
V_206 . V_246 = F_149 ;
if ( F_109 ( V_85 , & V_206 , V_49 ) < 0 )
return - V_47 ;
}
F_112 ( & V_206 , V_208 , L_61 ) ;
V_206 . V_174 = F_153 ;
V_206 . V_245 = F_154 ;
V_206 . V_246 = F_156 ;
if ( F_109 ( V_85 , & V_206 , V_49 ) < 0 )
return - V_47 ;
F_112 ( & V_206 , V_208 , L_62 ) ;
V_206 . V_174 = F_158 ;
V_206 . V_245 = F_160 ;
V_206 . V_246 = F_162 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_165 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_227 ;
T_1 V_33 ;
V_33 = F_115 ( V_52 , & V_227 ) ;
if ( V_33 )
V_227 = V_232 ;
V_226 -> type = V_233 ;
V_226 -> V_227 = V_227 ;
V_226 -> V_234 . integer . F_47 = 0 ;
V_226 -> V_234 . integer . F_48 = 0x7FFFFFFF ;
return 0 ;
}
static int F_166 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
short V_238 [ V_232 ] , V_270 ;
T_1 V_33 ;
V_33 = F_167 ( V_52 , V_238 ) ;
for ( V_270 = 0 ; V_270 < V_232 ; V_270 ++ ) {
if ( V_33 ) {
V_237 -> V_234 . integer . V_234 [ V_270 ] = 0 ;
} else if ( V_238 [ V_270 ] >= 0 ) {
V_237 -> V_234 . integer . V_234 [ V_270 ] =
V_238 [ V_270 ] << 16 ;
} else {
V_237 -> V_234 . integer . V_234 [ V_270 ] =
V_282 [ V_238 [ V_270 ] / - 1000 ] ;
}
}
return 0 ;
}
static int T_6 F_168 ( struct V_48 * V_49 ,
struct V_207 * V_208 , int V_283 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_63 ) ;
V_206 . V_242 =
V_262 | V_263 ;
V_206 . V_174 = F_165 ;
V_206 . V_245 = F_166 ;
V_206 . V_157 = V_283 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_169 ( struct V_223 * V_206 )
{
T_2 V_52 = V_206 -> V_210 ;
struct V_207 V_208 ;
int V_103 , V_33 ;
for ( V_103 = 0 ; V_103 < 32 ; V_103 ++ ) {
V_33 = F_170 ( V_52 , V_103 ,
& V_208 .
V_213 ,
& V_208 .
V_220 ) ;
if ( V_33 )
break;
}
return V_103 ;
}
static int F_171 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
int V_33 ;
T_1 V_213 , V_220 ;
T_2 V_52 = V_224 -> V_210 ;
V_226 -> type = V_252 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . V_253 . V_254 =
F_169 ( V_224 ) ;
if ( V_226 -> V_234 . V_253 . V_255 >= V_226 -> V_234 . V_253 . V_254 )
V_226 -> V_234 . V_253 . V_255 =
V_226 -> V_234 . V_253 . V_254 - 1 ;
V_33 =
F_170 ( V_52 ,
V_226 -> V_234 . V_253 . V_255 ,
& V_213 , & V_220 ) ;
sprintf ( V_226 -> V_234 . V_253 . V_40 , L_64 ,
V_219 [ V_213 - V_214 ] ,
V_220 ) ;
return 0 ;
}
static int F_172 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_284 , V_285 ;
T_1 V_213 , V_220 ;
int V_103 ;
F_52 ( F_173 ( V_52 ,
& V_284 , & V_285 ) ) ;
for ( V_103 = 0 ; V_103 < 256 ; V_103 ++ ) {
if ( F_170 ( V_52 , V_103 ,
& V_213 , & V_220 ) )
break;
if ( ( V_284 == V_213 )
&& ( V_285 == V_220 ) ) {
V_237 -> V_234 . V_253 . V_255 [ 0 ] = V_103 ;
return 0 ;
}
}
F_29 ( V_35
L_65 ,
V_52 , V_284 , V_285 ) ;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = 0 ;
return 0 ;
}
static int F_174 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
int V_239 ;
T_2 V_52 = V_224 -> V_210 ;
T_1 V_284 , V_285 ;
T_1 V_29 ;
V_239 = 1 ;
V_29 = F_170 ( V_52 ,
V_237 -> V_234 . V_253 . V_255 [ 0 ] ,
& V_284 , & V_285 ) ;
if ( ! V_29 )
F_52 (
F_175 ( V_52 ,
V_284 , V_285 ) ) ;
return V_239 ;
}
static int T_6 F_176 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_66 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_171 ;
V_206 . V_245 = F_172 ;
V_206 . V_246 = F_174 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_177 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_286 [ V_287 + 1 ] = {
L_67 ,
L_68 , L_69 ,
L_70 , L_71 ,
L_72 , L_73
} ;
T_2 V_52 = V_224 -> V_210 ;
T_1 V_288 ;
int V_270 ;
T_1 V_289 [ 6 ] ;
int V_290 = 0 ;
for ( V_270 = 0 ; V_270 < V_287 ; V_270 ++ )
if ( ! F_178 (
V_52 , V_270 , & V_288 ) ) {
V_289 [ V_290 ] = V_288 ;
V_290 ++ ;
}
if ( ! V_290 )
return - V_47 ;
V_226 -> type = V_252 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . V_253 . V_254 = V_290 ;
if ( V_226 -> V_234 . V_253 . V_255 >= V_290 )
V_226 -> V_234 . V_253 . V_255 = V_290 - 1 ;
strcpy ( V_226 -> V_234 . V_253 . V_40 ,
V_286 [ V_289 [ V_226 -> V_234 . V_253 . V_255 ] ] ) ;
return 0 ;
}
static int F_179 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_1 V_288 ;
if ( F_180 ( V_52 , & V_288 ) )
V_288 = 1 ;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = V_288 - 1 ;
return 0 ;
}
static int F_181 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
int V_239 ;
T_2 V_52 = V_224 -> V_210 ;
V_239 = 1 ;
F_52 ( F_182 ( V_52 ,
V_237 -> V_234 . V_253 . V_255 [ 0 ] + 1 ) ) ;
return V_239 ;
}
static int T_6 F_183 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
F_112 ( & V_206 , V_208 , L_74 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_177 ;
V_206 . V_245 = F_179 ;
V_206 . V_246 = F_181 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int F_184 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_224 -> V_84 ) ;
struct V_291 * V_292 = & V_49 -> V_293 ;
V_226 -> type = V_252 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . V_253 . V_254 = V_292 -> V_227 ;
if ( V_226 -> V_234 . V_253 . V_255 >= V_226 -> V_234 . V_253 . V_254 )
V_226 -> V_234 . V_253 . V_255 =
V_226 -> V_234 . V_253 . V_254 - 1 ;
strcpy ( V_226 -> V_234 . V_253 . V_40 ,
V_292 -> V_103 [ V_226 -> V_234 . V_253 . V_255 ] . V_40 ) ;
return 0 ;
}
static int F_185 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_224 -> V_84 ) ;
struct V_291 * V_292 = & V_49 -> V_293 ;
T_2 V_52 = V_224 -> V_210 ;
T_1 V_257 , V_294 = 0 ;
int V_270 ;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = 0 ;
if ( F_186 ( V_52 , & V_257 ) )
V_257 = 0 ;
if ( V_257 == V_295 )
if ( F_187 ( V_52 , & V_294 ) )
V_294 = 0 ;
for ( V_270 = 0 ; V_270 < V_292 -> V_227 ; V_270 ++ )
if ( ( V_292 -> V_103 [ V_270 ] . V_257 == V_257 ) &&
( V_292 -> V_103 [ V_270 ] . V_157 == V_294 ) )
break;
V_237 -> V_234 . V_253 . V_255 [ 0 ] = V_270 ;
return 0 ;
}
static int F_188 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_224 -> V_84 ) ;
struct V_291 * V_292 = & V_49 -> V_293 ;
int V_239 , V_255 ;
T_2 V_52 = V_224 -> V_210 ;
V_239 = 1 ;
V_255 = V_237 -> V_234 . V_253 . V_255 [ 0 ] ;
if ( V_255 >= V_292 -> V_227 )
V_255 = V_292 -> V_227 - 1 ;
F_52 ( F_189 (
V_52 , V_292 -> V_103 [ V_255 ] . V_257 ) ) ;
if ( V_292 -> V_103 [ V_255 ] . V_257 == V_295 )
F_52 ( F_190 (
V_52 , V_292 -> V_103 [ V_255 ] . V_157 ) ) ;
return V_239 ;
}
static int F_191 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_233 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . integer . F_47 = 8000 ;
V_226 -> V_234 . integer . F_48 = 192000 ;
V_226 -> V_234 . integer . V_235 = 100 ;
return 0 ;
}
static int F_192 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_296 ;
T_1 V_29 ;
V_29 = F_193 ( V_52 , & V_296 ) ;
if ( ! V_29 )
V_237 -> V_234 . integer . V_234 [ 0 ] = V_296 ;
else
V_237 -> V_234 . integer . V_234 [ 0 ] = 0 ;
return 0 ;
}
static int F_194 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
int V_239 ;
T_2 V_52 = V_224 -> V_210 ;
V_239 = 1 ;
F_52 ( F_195 ( V_52 ,
V_237 -> V_234 . integer . V_234 [ 0 ] ) ) ;
return V_239 ;
}
static int F_196 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_233 ;
V_226 -> V_227 = 1 ;
V_226 -> V_234 . integer . F_47 = 8000 ;
V_226 -> V_234 . integer . F_48 = 192000 ;
V_226 -> V_234 . integer . V_235 = 100 ;
return 0 ;
}
static int F_197 ( struct V_223 * V_224 ,
struct V_236 * V_237 )
{
T_2 V_52 = V_224 -> V_210 ;
T_2 V_296 ;
T_1 V_29 ;
V_29 = F_45 ( V_52 , & V_296 ) ;
if ( ! V_29 )
V_237 -> V_234 . integer . V_234 [ 0 ] = V_296 ;
else
V_237 -> V_234 . integer . V_234 [ 0 ] = 0 ;
return 0 ;
}
static int T_6 F_198 ( struct V_48 * V_49 ,
struct V_207 * V_208 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
struct V_203 V_206 ;
struct V_291 * V_292 = & V_49 -> V_293 ;
T_2 V_297 = V_208 -> V_52 ;
int V_298 = 0 ;
int V_270 , V_299 ;
T_1 V_257 ;
V_206 . V_210 = V_208 -> V_52 ;
V_292 -> V_300 = 0 ;
for ( V_270 = 0 ; V_270 <= V_301 ; V_270 ++ ) {
if ( F_199 ( V_297 ,
V_270 , & V_257 ) )
break;
V_292 -> V_103 [ V_270 ] . V_257 = V_257 ;
V_292 -> V_103 [ V_270 ] . V_157 = 0 ;
V_292 -> V_103 [ V_270 ] . V_40 = V_302 [ V_257 ] ;
if ( V_257 == V_295 )
V_298 = 1 ;
if ( V_257 == V_303 )
V_292 -> V_300 = 1 ;
}
if ( V_298 )
for ( V_299 = 1 ; V_299 < 8 ; V_299 ++ ) {
if ( F_200 ( V_297 ,
V_299 , V_295 ,
& V_257 ) )
break;
V_292 -> V_103 [ V_270 ] . V_257 =
V_295 ;
V_292 -> V_103 [ V_270 ] . V_157 = V_299 ;
V_292 -> V_103 [ V_270 ] . V_40 = V_302 [
V_299 + V_301 ] ;
V_270 ++ ;
}
V_292 -> V_227 = V_270 ;
F_112 ( & V_206 , V_208 , L_75 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_184 ;
V_206 . V_245 = F_185 ;
V_206 . V_246 = F_188 ;
if ( F_109 ( V_85 , & V_206 , V_49 ) < 0 )
return - V_47 ;
if ( V_292 -> V_300 ) {
F_112 ( & V_206 , V_208 , L_76 ) ;
V_206 . V_242 = V_243 ;
V_206 . V_174 = F_191 ;
V_206 . V_245 = F_192 ;
V_206 . V_246 = F_194 ;
if ( F_109 ( V_85 , & V_206 , V_49 ) < 0 )
return - V_47 ;
}
F_112 ( & V_206 , V_208 , L_77 ) ;
V_206 . V_242 =
V_262 | V_263 ;
V_206 . V_174 = F_196 ;
V_206 . V_245 = F_197 ;
return F_109 ( V_85 , & V_206 , V_49 ) ;
}
static int T_6 F_201 ( struct V_48 * V_49 )
{
struct V_202 * V_85 = V_49 -> V_85 ;
unsigned int V_54 = 0 ;
unsigned int V_304 = 0 ;
int V_33 ;
struct V_207 V_208 , V_305 ;
if ( F_202 ( ! V_49 ) )
return - V_47 ;
strcpy ( V_85 -> V_306 , L_78 ) ;
V_33 =
F_203 ( V_49 -> V_155 -> V_156 -> V_157 ,
& V_49 -> V_61 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
return - V_33 ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
V_305 . V_307 = - 1 ;
for ( V_54 = 0 ; V_54 < 2000 ; V_54 ++ ) {
V_33 = F_204 (
V_49 -> V_61 ,
V_54 ,
& V_208 . V_213 ,
& V_208 . V_220 ,
& V_208 . V_215 ,
& V_208 . V_222 ,
& V_208 . V_307 ,
& V_208 . V_52 ) ;
if ( V_33 ) {
if ( V_33 == V_308 ) {
if ( V_205 )
F_44 ( V_149
L_79 ,
V_54 ) ;
continue;
} else
break;
}
V_208 . V_213 -= V_214 ;
V_208 . V_215 -= V_216 ;
if ( ( V_208 . V_307 == V_305 . V_307 ) &&
( V_208 . V_213 == V_305 . V_213 ) &&
( V_208 . V_220 == V_305 . V_220 ) &&
( V_208 . V_215 == V_305 . V_215 ) &&
( V_208 . V_222 == V_305 . V_222 ) )
V_304 ++ ;
else
V_304 = 0 ;
V_305 = V_208 ;
switch ( V_208 . V_307 ) {
case V_309 :
V_33 = F_124 ( V_49 , & V_208 ) ;
break;
case V_310 :
V_33 = F_131 ( V_49 , & V_208 ) ;
break;
case V_311 :
V_33 = F_176 ( V_49 , & V_208 ) ;
break;
case V_312 :
V_33 = F_183 ( V_49 , & V_208 ) ;
break;
case V_313 :
V_33 = F_168 ( V_49 , & V_208 , V_304 ) ;
break;
case V_63 :
V_33 = F_198 (
V_49 , & V_208 ) ;
break;
case V_314 :
continue;
case V_315 :
V_33 = F_164 ( V_49 , & V_208 ) ;
break;
case V_316 :
V_33 = F_144 ( V_49 , & V_208 ) ;
break;
case V_317 :
V_33 = F_141 ( V_49 , & V_208 ) ;
break;
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
default:
if ( V_205 )
F_44 ( V_149
L_80
L_81 ,
V_54 ,
V_208 . V_307 ,
V_208 . V_213 ,
V_208 . V_220 ,
V_208 . V_215 ,
V_208 . V_222 ) ;
continue;
}
if ( V_33 < 0 )
return V_33 ;
}
if ( V_271 != V_33 )
F_52 ( V_33 ) ;
F_44 ( V_149 L_82 , V_54 ) ;
return 0 ;
}
static void
F_205 ( struct V_323 * V_324 ,
struct V_325 * V_17 )
{
struct V_48 * V_49 = V_324 -> V_84 ;
T_2 V_52 ;
T_2 V_296 = 0 ;
T_1 V_257 = 0 ;
T_1 V_194 ;
T_1 V_193 ;
T_1 V_326 ;
T_2 V_327 ;
T_1 type ;
int V_33 ;
F_206 ( V_17 , L_83 ) ;
F_52 ( F_104 ( V_49 -> V_155 -> V_156 -> V_157 ,
& V_194 , & V_193 ,
& V_326 , & V_327 , & type ) ) ;
F_206 ( V_17 ,
L_84
L_85 ,
type , V_49 -> V_155 -> V_156 -> V_157 ,
V_194 , V_193 ) ;
F_206 ( V_17 ,
L_86 ,
V_327 , ( ( V_326 >> 3 ) & 0xf ) + 'A' , V_326 & 0x7 ,
( ( V_326 >> 13 ) * 100 ) + ( ( V_326 >> 7 ) & 0x3f ) ) ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 ) {
V_33 = F_45 ( V_52 , & V_296 ) ;
V_33 += F_186 ( V_52 , & V_257 ) ;
if ( ! V_33 )
F_206 ( V_17 , L_87 ,
V_296 , V_302 [ V_257 ] ) ;
}
}
static void T_6 F_207 ( struct V_48 * V_49 )
{
struct V_323 * V_324 ;
if ( ! F_208 ( V_49 -> V_85 , L_88 , & V_324 ) )
F_209 ( V_324 , V_49 , F_205 ) ;
}
static int F_210 ( struct V_328 * V_183 , struct V_329 * V_329 )
{
if ( V_330 )
return 0 ;
else
return - V_331 ;
}
static int F_211 ( struct V_328 * V_183 , struct V_329 * V_329 )
{
if ( V_330 )
return F_212 ( V_329 ) ;
else
return - V_331 ;
}
static int F_213 ( struct V_328 * V_183 , struct V_329 * V_329 ,
unsigned int V_102 , unsigned long V_148 )
{
if ( V_330 )
return F_214 ( V_329 , V_102 , V_148 ) ;
else
return - V_331 ;
}
static int T_6 F_215 ( struct V_48 * V_49 ,
int V_190 , struct V_328 * * V_332 )
{
struct V_328 * V_183 ;
int V_33 ;
if ( V_332 )
* V_332 = NULL ;
V_33 = F_216 ( V_49 -> V_85 , L_89 , V_190 , & V_183 ) ;
if ( V_33 < 0 )
return V_33 ;
strcpy ( V_183 -> V_40 , L_90 ) ;
V_183 -> V_211 = V_333 ;
V_183 -> V_334 . V_335 = F_210 ;
V_183 -> V_334 . V_336 = F_213 ;
V_183 -> V_334 . V_337 = F_211 ;
V_183 -> V_84 = V_49 ;
if ( V_332 )
* V_332 = V_183 ;
return 0 ;
}
static int T_6 F_217 ( struct V_338 * V_338 ,
const struct V_339 * V_340 )
{
int V_33 ;
struct V_341 * V_155 ;
struct V_202 * V_85 ;
struct V_48 * V_49 ;
T_2 V_52 ;
T_2 V_1 ;
T_2 V_13 ;
static int V_342 ;
if ( V_342 >= V_343 )
return - V_331 ;
if ( ! V_344 [ V_342 ] ) {
V_342 ++ ;
return - V_345 ;
}
V_33 = F_218 ( V_338 , V_340 ) ;
if ( V_33 < 0 )
return V_33 ;
V_155 = F_219 ( V_338 ) ;
V_13 = V_155 -> V_156 -> V_157 ;
V_33 = F_220 ( V_13 ,
V_346 [ V_13 ] , V_347 ,
sizeof( struct V_48 ) ,
& V_85 ) ;
if ( V_33 < 0 ) {
V_33 =
F_220 ( V_157 [ V_342 ] , V_346 [ V_342 ] ,
V_347 ,
sizeof( struct V_48 ) ,
& V_85 ) ;
if ( V_33 < 0 )
return V_33 ;
F_44 ( V_35
L_91 ,
V_13 , V_85 -> V_109 ) ;
}
F_221 ( V_85 , & V_338 -> V_342 ) ;
V_49 = V_85 -> V_84 ;
V_49 -> V_85 = V_85 ;
V_49 -> V_201 = V_338 ;
V_49 -> V_155 = V_155 ;
F_44 ( V_149 L_92 ,
V_49 -> V_155 -> V_156 -> type , V_13 ) ;
V_33 = F_222 ( V_13 ,
V_348 ,
NULL , & V_49 -> V_112 ) ;
if ( V_33 )
V_49 -> V_112 = 0 ;
V_33 = F_222 ( V_13 ,
V_349 ,
& V_49 -> V_58 , NULL ) ;
if ( V_33 )
V_49 -> V_58 = 0 ;
V_33 = F_222 ( V_13 ,
V_350 ,
NULL , & V_49 -> V_186 ) ;
if ( V_33 )
V_49 -> V_186 = 512 ;
if ( ! V_49 -> V_91 )
V_49 -> V_186 *= 2 ;
F_52 ( F_100 ( V_13 ,
0 , & V_1 ) ) ;
V_33 = F_223 ( V_1 ) ;
V_49 -> V_91 = ( ! V_33 ) ;
F_52 ( F_102 ( V_1 ) ) ;
V_33 = F_222 ( V_13 ,
V_351 ,
& V_49 -> V_187 , & V_49 -> V_152 ) ;
if ( V_33 ) {
V_49 -> V_187 = 2 ;
V_49 -> V_152 = 2 ;
}
if ( V_49 -> V_152 > 2 ) {
V_49 -> V_173 = V_49 -> V_152 ;
V_49 -> V_189 = V_49 -> V_187 ;
V_49 -> V_112 = 0 ;
} else {
V_49 -> V_173 = 1 ;
V_49 -> V_189 = 1 ;
}
F_44 ( V_149 L_93 ,
V_49 -> V_91 ,
V_49 -> V_112 ,
V_49 -> V_58
) ;
V_33 = F_103 ( V_49 , 0 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_94 ) ;
goto V_352;
}
V_33 = F_201 ( V_49 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_95 ) ;
goto V_352;
}
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_195 (
V_52 , V_353 ) ;
F_207 ( V_49 ) ;
F_215 ( V_49 , 0 , NULL ) ;
strcpy ( V_85 -> V_354 , L_96 ) ;
sprintf ( V_85 -> V_355 , L_97 ,
V_49 -> V_155 -> V_156 -> type ) ;
sprintf ( V_85 -> V_356 , L_98 ,
V_85 -> V_355 , V_13 ) ;
V_33 = F_224 ( V_85 ) ;
if ( ! V_33 ) {
V_155 -> V_202 = V_85 ;
V_342 ++ ;
return 0 ;
}
V_352:
F_225 ( V_85 ) ;
F_44 ( V_64 L_99 , V_33 ) ;
return V_33 ;
}
static void T_7 F_226 ( struct V_338 * V_338 )
{
struct V_341 * V_155 = F_219 ( V_338 ) ;
F_225 ( V_155 -> V_202 ) ;
V_155 -> V_202 = NULL ;
F_227 ( V_338 ) ;
}
static int T_8 F_228 ( void )
{
F_229 () ;
return F_230 ( & V_354 ) ;
}
static void T_9 F_231 ( void )
{
F_232 ( & V_354 ) ;
F_233 () ;
}
