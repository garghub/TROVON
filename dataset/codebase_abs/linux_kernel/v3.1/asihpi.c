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
if ( ( V_132 == 0 ) &&
( V_134 < V_105 -> V_111 ) ) {
F_52 ( F_7 ( V_105 -> V_1 ) ) ;
F_56 ( L_28 , V_103 -> V_109 ) ;
V_105 -> V_106 = 0 ;
}
} else if ( V_115 == V_137 ) {
F_29 ( V_35 L_29 ,
V_103 -> V_109 ) ;
V_105 -> V_106 ++ ;
if ( V_105 -> V_106 > 2 ) {
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
V_105 -> V_111 = V_105 -> V_111 + V_128 ;
V_105 -> V_139 = V_125 ;
F_76 ( V_103 ) ;
}
}
if ( V_83 -> V_101 )
F_62 ( & V_83 -> V_98 ) ;
}
static int F_77 ( struct V_36 * V_37 ,
unsigned int V_102 , void * V_148 )
{
F_67 ( V_149 L_39 , V_37 -> V_109 , V_102 ) ;
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
V_150 = F_81 ( V_81 , V_83 -> V_125 % V_83 -> V_94 ) ;
F_67 ( L_41 , V_37 -> V_109 , ( unsigned long ) V_150 ) ;
return V_150 ;
}
static void F_82 ( struct V_48 * V_49 ,
T_2 V_1 ,
struct V_50 * V_51 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 ,
2 , V_43 , V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_83 ( V_1 ,
& V_42 ) ;
if ( ! V_33 && ( V_46 [ V_43 ] != - 1 ) )
V_51 -> V_151 |=
( 1ULL << V_46 [ V_43 ] ) ;
}
}
static int F_84 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_82 * V_83 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
int V_33 ;
V_83 = F_85 ( sizeof( * V_83 ) , V_152 ) ;
if ( V_83 == NULL )
return - V_93 ;
V_33 =
F_86 ( V_85 -> V_13 ,
V_37 -> V_109 , & V_83 -> V_1 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_153 )
return - V_154 ;
if ( V_33 )
return - V_155 ;
F_87 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_156 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_157 = F_59 ;
V_158 . V_159 = V_85 -> V_160 ;
F_82 ( V_85 , V_83 -> V_1 ,
& V_158 ) ;
F_42 ( V_85 , & V_158 ) ;
V_158 . V_161 = V_162 |
V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 ;
if ( V_85 -> V_112 )
V_158 . V_161 |= V_169 ;
V_81 -> V_170 = V_158 ;
if ( V_85 -> V_91 )
V_33 = F_88 ( V_81 , 0 ,
V_171 ) ;
if ( V_33 < 0 )
return V_33 ;
F_89 ( V_81 , 0 , V_172 ,
V_85 -> V_173 ) ;
F_90 ( V_81 , V_172 ,
V_85 -> V_173 * 2 , V_140 ) ;
F_91 ( V_37 ) ;
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
static void F_97 ( struct V_48 * V_49 ,
T_2 V_1 ,
struct V_50 * V_51 )
{
struct V_42 V_42 ;
T_1 V_43 ;
T_1 V_33 ;
T_2 V_52 ;
T_2 V_53 = 48000 ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_45 ( V_52 ,
& V_53 ) ;
for ( V_43 = V_44 ;
V_43 <= V_45 ; V_43 ++ ) {
V_33 = F_53 ( & V_42 , 2 , V_43 ,
V_53 , 128000 , 0 ) ;
if ( ! V_33 )
V_33 = F_98 ( V_1 ,
& V_42 ) ;
if ( ! V_33 )
V_51 -> V_151 |=
( 1ULL << V_46 [ V_43 ] ) ;
}
}
static int F_99 ( struct V_36 * V_37 )
{
struct V_80 * V_81 = V_37 -> V_81 ;
struct V_48 * V_85 = F_50 ( V_37 ) ;
struct V_82 * V_83 ;
int V_33 ;
V_83 = F_85 ( sizeof( * V_83 ) , V_152 ) ;
if ( V_83 == NULL )
return - V_93 ;
F_56 ( L_46 ,
V_85 -> V_13 , V_37 -> V_109 ) ;
V_33 = F_52 (
F_100 ( V_85 -> V_13 ,
V_37 -> V_109 , & V_83 -> V_1 ) ) ;
if ( V_33 )
F_60 ( V_83 ) ;
if ( V_33 == V_153 )
return - V_154 ;
if ( V_33 )
return - V_155 ;
F_87 ( & V_83 -> V_98 ) ;
V_83 -> V_98 . V_123 = ( unsigned long ) V_83 ;
V_83 -> V_98 . V_156 = F_72 ;
V_83 -> V_37 = V_37 ;
V_81 -> V_84 = V_83 ;
V_81 -> V_157 = F_59 ;
V_174 . V_159 = V_85 -> V_175 ;
F_97 ( V_85 , V_83 -> V_1 ,
& V_174 ) ;
F_42 ( V_85 , & V_174 ) ;
V_174 . V_161 = V_162 |
V_167 |
V_168 ;
if ( V_85 -> V_112 )
V_174 . V_161 |= V_169 ;
V_81 -> V_170 = V_174 ;
if ( V_85 -> V_91 )
V_33 = F_88 ( V_81 , 0 ,
V_171 ) ;
if ( V_33 < 0 )
return V_33 ;
F_89 ( V_81 , 0 , V_172 ,
V_85 -> V_173 ) ;
F_90 ( V_81 , V_172 ,
V_85 -> V_173 * 2 , V_140 ) ;
F_91 ( V_37 ) ;
return 0 ;
}
static int F_101 ( struct V_36 * V_37 )
{
struct V_82 * V_83 = V_37 -> V_81 -> V_84 ;
F_52 ( F_102 ( V_83 -> V_1 ) ) ;
return 0 ;
}
static int T_5 F_103 ( struct V_48 * V_49 ,
int V_176 , int V_177 )
{
struct V_178 * V_179 ;
int V_33 ;
V_33 = F_104 ( V_49 -> V_85 , L_47 , V_176 ,
V_49 -> V_180 , V_49 -> V_181 ,
& V_179 ) ;
if ( V_33 < 0 )
return V_33 ;
F_105 ( V_179 , V_107 ,
& V_182 ) ;
F_105 ( V_179 , V_89 ,
& V_183 ) ;
V_179 -> V_84 = V_49 ;
V_179 -> V_184 = 0 ;
strcpy ( V_179 -> V_40 , L_47 ) ;
F_106 ( V_179 , V_185 ,
F_107 ( V_49 -> V_186 ) ,
64 * 1024 , V_187 ) ;
return 0 ;
}
static inline int F_108 ( struct V_188 * V_85 , struct V_189 * V_190 ,
struct V_48 * V_49 )
{
int V_33 ;
V_33 = F_109 ( V_85 , F_110 ( V_190 , V_49 ) ) ;
if ( V_33 < 0 )
return V_33 ;
else if ( V_191 )
F_44 ( V_149 L_48 , V_190 -> V_40 , V_190 -> V_192 ) ;
return 0 ;
}
static void F_111 ( struct V_189 * V_193 ,
struct V_194 * V_195 ,
char * V_40 )
{
char * V_196 ;
memset ( V_193 , 0 , sizeof( * V_193 ) ) ;
V_193 -> V_40 = V_195 -> V_40 ;
V_193 -> V_197 = V_195 -> V_52 ;
V_193 -> V_198 = V_199 ;
V_193 -> V_192 = 0 ;
if ( V_195 -> V_200 + V_201 == V_62 )
V_196 = L_49 ;
else if ( V_195 -> V_202 + V_203 == V_204 )
V_196 = L_50 ;
else if ( ( V_195 -> V_200 + V_201 != V_205 ) &&
( ! V_195 -> V_202 ) )
V_196 = L_50 ;
else if ( V_195 -> V_200 &&
( V_195 -> V_200 + V_201 != V_205 ) &&
( V_195 -> V_202 ) )
V_196 = L_51 ;
else
V_196 = L_52 ;
if ( V_195 -> V_200 && V_195 -> V_202 )
sprintf ( V_195 -> V_40 , L_53 ,
V_206 [ V_195 -> V_200 ] ,
V_195 -> V_207 ,
V_208 [ V_195 -> V_202 ] ,
V_195 -> V_209 ,
V_196 , V_40 ) ;
else if ( V_195 -> V_202 ) {
sprintf ( V_195 -> V_40 , L_54 ,
V_208 [ V_195 -> V_202 ] ,
V_195 -> V_209 ,
V_196 , V_40 ) ;
} else {
sprintf ( V_195 -> V_40 , L_54 ,
V_206 [ V_195 -> V_200 ] ,
V_195 -> V_207 ,
V_196 , V_40 ) ;
}
}
static int F_112 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_33 ;
short V_214 ;
short V_215 ;
short V_216 ;
V_33 = F_113 ( V_52 ,
& V_214 , & V_215 , & V_216 ) ;
if ( V_33 ) {
V_215 = 0 ;
V_214 = - 10000 ;
V_216 = V_217 ;
}
V_213 -> type = V_218 ;
V_213 -> V_219 = 2 ;
V_213 -> V_220 . integer . F_47 = V_214 / V_217 ;
V_213 -> V_220 . integer . F_48 = V_215 / V_217 ;
V_213 -> V_220 . integer . V_221 = V_216 / V_217 ;
return 0 ;
}
static int F_114 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
short V_224 [ V_225 ] ;
F_52 ( F_115 ( V_52 , V_224 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] = V_224 [ 0 ] / V_217 ;
V_223 -> V_220 . integer . V_220 [ 1 ] = V_224 [ 1 ] / V_217 ;
return 0 ;
}
static int F_116 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
int V_226 ;
T_2 V_52 = V_211 -> V_197 ;
short V_224 [ V_225 ] ;
V_224 [ 0 ] =
( V_223 -> V_220 . integer . V_220 [ 0 ] ) * V_217 ;
V_224 [ 1 ] =
( V_223 -> V_220 . integer . V_220 [ 1 ] ) * V_217 ;
V_226 = 1 ;
F_52 ( F_117 ( V_52 , V_224 ) ) ;
return V_226 ;
}
static int F_118 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_2 V_227 ;
F_52 ( F_119 ( V_52 , & V_227 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] = V_227 ? 0 : 1 ;
return 0 ;
}
static int F_120 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
int V_226 = 1 ;
int V_227 = V_223 -> V_220 . integer . V_220 [ 0 ] ? 0 : V_228 ;
F_52 ( F_121 ( V_52 , V_227 ) ) ;
return V_226 ;
}
static int T_5 F_122 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
int V_33 ;
T_2 V_227 ;
F_111 ( & V_193 , V_195 , L_55 ) ;
V_193 . V_229 = V_230 |
V_231 ;
V_193 . V_161 = F_112 ;
V_193 . V_232 = F_114 ;
V_193 . V_233 = F_116 ;
V_193 . V_234 . V_39 = V_235 ;
V_33 = F_108 ( V_85 , & V_193 , V_49 ) ;
if ( V_33 )
return V_33 ;
if ( F_119 ( V_195 -> V_52 , & V_227 ) == 0 ) {
F_111 ( & V_193 , V_195 , L_56 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = V_236 ;
V_193 . V_232 = F_118 ;
V_193 . V_233 = F_120 ;
V_33 = F_108 ( V_85 , & V_193 , V_49 ) ;
}
return V_33 ;
}
static int F_123 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_33 ;
short V_214 ;
short V_215 ;
short V_216 ;
V_33 =
F_124 ( V_52 , & V_214 ,
& V_215 , & V_216 ) ;
if ( V_33 ) {
V_215 = 2400 ;
V_214 = - 1000 ;
V_216 = 100 ;
}
V_213 -> type = V_218 ;
V_213 -> V_219 = 2 ;
V_213 -> V_220 . integer . F_47 = V_214 / V_237 ;
V_213 -> V_220 . integer . F_48 = V_215 / V_237 ;
V_213 -> V_220 . integer . V_221 = V_216 / V_237 ;
return 0 ;
}
static int F_125 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
short V_224 [ V_225 ] ;
F_52 ( F_126 ( V_52 , V_224 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] =
V_224 [ 0 ] / V_237 ;
V_223 -> V_220 . integer . V_220 [ 1 ] =
V_224 [ 1 ] / V_237 ;
return 0 ;
}
static int F_127 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
int V_226 ;
T_2 V_52 = V_211 -> V_197 ;
short V_224 [ V_225 ] ;
V_224 [ 0 ] =
( V_223 -> V_220 . integer . V_220 [ 0 ] ) * V_237 ;
V_224 [ 1 ] =
( V_223 -> V_220 . integer . V_220 [ 1 ] ) * V_237 ;
V_226 = 1 ;
F_52 ( F_128 ( V_52 , V_224 ) ) ;
return V_226 ;
}
static int T_5 F_129 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_57 ) ;
V_193 . V_229 = V_230 |
V_231 ;
V_193 . V_161 = F_123 ;
V_193 . V_232 = F_125 ;
V_193 . V_233 = F_127 ;
V_193 . V_234 . V_39 = V_238 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_130 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
V_213 -> type = V_239 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . V_240 . V_241 = 3 ;
if ( V_213 -> V_220 . V_240 . V_242 >= V_213 -> V_220 . V_240 . V_241 )
V_213 -> V_220 . V_240 . V_242 =
V_213 -> V_220 . V_240 . V_241 - 1 ;
strcpy ( V_213 -> V_220 . V_240 . V_40 ,
V_243 [ V_213 -> V_220 . V_240 . V_242 ] ) ;
return 0 ;
}
static int F_131 ( struct V_210 * V_211 ,
struct V_222 * V_223 ,
T_1 (* F_132)( T_2 , T_1 * ) )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_244 , V_33 ;
V_33 = F_132 ( V_52 , & V_244 ) ;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = 0 ;
if ( V_33 )
return 0 ;
if ( V_244 == V_245 )
V_223 -> V_220 . V_240 . V_242 [ 0 ] = 1 ;
if ( V_244 == V_246 )
V_223 -> V_220 . V_240 . V_242 [ 0 ] = 2 ;
return 0 ;
}
static int F_133 ( struct V_210 * V_211 ,
struct V_222 * V_223 ,
T_1 (* F_132)( T_2 , T_1 ) )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_244 = V_245 ;
if ( V_223 -> V_220 . V_240 . V_242 [ 0 ] == 1 )
V_244 = V_245 ;
if ( V_223 -> V_220 . V_240 . V_242 [ 0 ] == 2 )
V_244 = V_246 ;
if ( F_132 ( V_52 , V_244 ) != 0 )
return - V_47 ;
return 1 ;
}
static int F_134 ( struct V_210 * V_211 ,
struct V_222 * V_223 ) {
return F_131 ( V_211 , V_223 ,
V_247 ) ;
}
static int F_135 ( struct V_210 * V_211 ,
struct V_222 * V_223 ) {
return F_133 ( V_211 , V_223 ,
V_248 ) ;
}
static int F_136 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
V_213 -> type = V_218 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . integer . F_47 = 0 ;
V_213 -> V_220 . integer . F_48 = 0X1F ;
V_213 -> V_220 . integer . V_221 = 1 ;
return 0 ;
}
static int F_137 ( struct V_210 * V_211 ,
struct V_222 * V_223 ) {
T_2 V_52 = V_211 -> V_197 ;
T_1 V_114 ;
F_52 ( F_138 (
V_52 , & V_114 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] = V_114 ;
return 0 ;
}
static int T_5 F_139 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_58 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_130 ;
V_193 . V_232 = F_134 ;
V_193 . V_233 = F_135 ;
if ( F_108 ( V_85 , & V_193 , V_49 ) < 0 )
return - V_47 ;
F_111 ( & V_193 , V_195 , L_59 ) ;
V_193 . V_229 =
V_249 | V_250 ;
V_193 . V_161 = F_136 ;
V_193 . V_232 = F_137 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_140 ( struct V_210 * V_211 ,
struct V_222 * V_223 ) {
return F_131 ( V_211 , V_223 ,
V_251 ) ;
}
static int F_141 ( struct V_210 * V_211 ,
struct V_222 * V_223 ) {
return F_133 ( V_211 , V_223 ,
V_252 ) ;
}
static int T_5 F_142 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_58 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_130 ;
V_193 . V_232 = F_140 ;
V_193 . V_233 = F_141 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_143 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_33 ;
short V_54 ;
T_1 V_253 [ 3 ] ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_144 ( V_52 ,
V_54 , & V_253 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_213 -> type = V_218 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . integer . F_47 = ( ( int ) V_253 [ 0 ] ) / V_237 ;
V_213 -> V_220 . integer . F_48 = ( ( int ) V_253 [ 1 ] ) / V_237 ;
V_213 -> V_220 . integer . V_221 = ( ( int ) V_253 [ 2 ] ) / V_237 ;
return 0 ;
}
static int F_145 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
short V_254 ;
F_52 ( F_146 ( V_52 , & V_254 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] = V_254 / V_237 ;
return 0 ;
}
static int F_147 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
short V_254 ;
V_254 = ( V_223 -> V_220 . integer . V_220 [ 0 ] ) * V_237 ;
F_52 ( F_148 ( V_52 , V_254 ) ) ;
return 1 ;
}
static int F_149 ( struct V_210 * V_211 ,
T_1 * V_255 , T_2 V_256 ) {
T_2 V_52 = V_211 -> V_197 ;
T_1 V_33 = 0 ;
T_2 V_257 ;
for ( V_257 = 0 ; V_257 < V_256 ; V_257 ++ ) {
V_33 = F_150 (
V_52 , V_257 , & V_255 [ V_257 ] ) ;
if ( V_33 != 0 )
break;
}
if ( V_33 && ( V_33 != V_258 ) )
return - V_155 ;
return V_257 ;
}
static int F_151 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
T_1 V_259 [ V_260 ] ;
int V_261 = 0 ;
V_261 = F_149 ( V_211 , V_259 ,
V_260 ) ;
if ( V_261 < 0 )
return V_261 ;
V_213 -> type = V_239 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . V_240 . V_241 = V_261 ;
if ( V_261 > 0 ) {
if ( V_213 -> V_220 . V_240 . V_242 >=
V_213 -> V_220 . V_240 . V_241 )
V_213 -> V_220 . V_240 . V_242 =
V_213 -> V_220 . V_240 . V_241 - 1 ;
strcpy ( V_213 -> V_220 . V_240 . V_40 ,
V_262 [
V_259 [ V_213 -> V_220 . V_240 . V_242 ] ] ) ;
}
return 0 ;
}
static int F_152 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_263 , V_54 ;
T_1 V_259 [ V_260 ] ;
T_2 V_261 = 0 ;
V_261 = F_149 ( V_211 , V_259 ,
V_260 ) ;
F_52 ( F_153 ( V_52 , & V_263 ) ) ;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = - 1 ;
for ( V_54 = 0 ; V_54 < V_260 ; V_54 ++ )
if ( V_259 [ V_54 ] == V_263 ) {
V_223 -> V_220 . V_240 . V_242 [ 0 ] = V_54 ;
break;
}
return 0 ;
}
static int F_154 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_263 ;
T_1 V_259 [ V_260 ] ;
T_2 V_261 = 0 ;
V_261 = F_149 ( V_211 , V_259 ,
V_260 ) ;
V_263 = V_259 [ V_223 -> V_220 . V_240 . V_242 [ 0 ] ] ;
F_52 ( F_155 ( V_52 , V_263 ) ) ;
return 1 ;
}
static int F_156 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_33 ;
T_1 V_259 [ V_260 ] ;
T_1 V_261 = 0 , V_264 , V_54 ;
T_2 V_265 [ 3 ] , V_266 [ 3 ] ;
V_261 = F_149 ( V_211 , V_259 ,
V_260 ) ;
V_265 [ 0 ] = V_267 ;
V_265 [ 1 ] = 0 ;
V_265 [ 2 ] = V_267 ;
for ( V_264 = 0 ; V_264 < V_261 ; V_264 ++ ) {
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_33 = F_157 ( V_52 ,
V_54 , V_259 [ V_264 ] ,
& V_266 [ V_54 ] ) ;
if ( V_33 != 0 )
return V_33 ;
}
if ( V_266 [ 2 ] <= 0 )
continue;
if ( V_266 [ 0 ] < V_265 [ 0 ] )
V_265 [ 0 ] = V_266 [ 0 ] ;
if ( V_266 [ 1 ] > V_265 [ 1 ] )
V_265 [ 1 ] = V_266 [ 1 ] ;
if ( V_266 [ 2 ] < V_265 [ 2 ] )
V_265 [ 2 ] = V_266 [ 2 ] ;
}
V_213 -> type = V_218 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . integer . F_47 = ( ( int ) V_265 [ 0 ] ) ;
V_213 -> V_220 . integer . F_48 = ( ( int ) V_265 [ 1 ] ) ;
V_213 -> V_220 . integer . V_221 = ( ( int ) V_265 [ 2 ] ) ;
return 0 ;
}
static int F_158 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_2 V_268 ;
F_52 ( F_159 ( V_52 , & V_268 ) ) ;
V_223 -> V_220 . integer . V_220 [ 0 ] = V_268 ;
return 0 ;
}
static int F_160 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_2 V_268 ;
V_268 = V_223 -> V_220 . integer . V_220 [ 0 ] ;
F_52 ( F_161 ( V_52 , V_268 ) ) ;
return 1 ;
}
static int T_5 F_162 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
V_193 . V_197 = V_195 -> V_52 ;
V_193 . V_229 = V_230 ;
if ( ! F_146 ( V_195 -> V_52 , NULL ) ) {
F_111 ( & V_193 , V_195 , L_60 ) ;
V_193 . V_161 = F_143 ;
V_193 . V_232 = F_145 ;
V_193 . V_233 = F_147 ;
if ( F_108 ( V_85 , & V_193 , V_49 ) < 0 )
return - V_47 ;
}
F_111 ( & V_193 , V_195 , L_61 ) ;
V_193 . V_161 = F_151 ;
V_193 . V_232 = F_152 ;
V_193 . V_233 = F_154 ;
if ( F_108 ( V_85 , & V_193 , V_49 ) < 0 )
return - V_47 ;
F_111 ( & V_193 , V_195 , L_62 ) ;
V_193 . V_161 = F_156 ;
V_193 . V_232 = F_158 ;
V_193 . V_233 = F_160 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_163 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
V_213 -> type = V_218 ;
V_213 -> V_219 = V_225 ;
V_213 -> V_220 . integer . F_47 = 0 ;
V_213 -> V_220 . integer . F_48 = 0x7FFFFFFF ;
return 0 ;
}
static int F_164 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
short V_224 [ V_225 ] , V_257 ;
T_1 V_33 ;
V_33 = F_165 ( V_52 , V_224 ) ;
for ( V_257 = 0 ; V_257 < V_225 ; V_257 ++ ) {
if ( V_33 ) {
V_223 -> V_220 . integer . V_220 [ V_257 ] = 0 ;
} else if ( V_224 [ V_257 ] >= 0 ) {
V_223 -> V_220 . integer . V_220 [ V_257 ] =
V_224 [ V_257 ] << 16 ;
} else {
V_223 -> V_220 . integer . V_220 [ V_257 ] =
V_269 [ V_224 [ V_257 ] / - 1000 ] ;
}
}
return 0 ;
}
static int T_5 F_166 ( struct V_48 * V_49 ,
struct V_194 * V_195 , int V_270 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_63 ) ;
V_193 . V_229 =
V_249 | V_250 ;
V_193 . V_161 = F_163 ;
V_193 . V_232 = F_164 ;
V_193 . V_192 = V_270 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_167 ( struct V_210 * V_193 )
{
T_2 V_52 = V_193 -> V_197 ;
struct V_194 V_195 ;
int V_103 , V_33 ;
for ( V_103 = 0 ; V_103 < 32 ; V_103 ++ ) {
V_33 = F_168 ( V_52 , V_103 ,
& V_195 .
V_200 ,
& V_195 .
V_207 ) ;
if ( V_33 )
break;
}
return V_103 ;
}
static int F_169 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
int V_33 ;
T_1 V_200 , V_207 ;
T_2 V_52 = V_211 -> V_197 ;
V_213 -> type = V_239 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . V_240 . V_241 =
F_167 ( V_211 ) ;
if ( V_213 -> V_220 . V_240 . V_242 >= V_213 -> V_220 . V_240 . V_241 )
V_213 -> V_220 . V_240 . V_242 =
V_213 -> V_220 . V_240 . V_241 - 1 ;
V_33 =
F_168 ( V_52 ,
V_213 -> V_220 . V_240 . V_242 ,
& V_200 , & V_207 ) ;
sprintf ( V_213 -> V_220 . V_240 . V_40 , L_64 ,
V_206 [ V_200 - V_201 ] ,
V_207 ) ;
return 0 ;
}
static int F_170 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_271 , V_272 ;
T_1 V_200 , V_207 ;
int V_103 ;
F_52 ( F_171 ( V_52 ,
& V_271 , & V_272 ) ) ;
for ( V_103 = 0 ; V_103 < 256 ; V_103 ++ ) {
if ( F_168 ( V_52 , V_103 ,
& V_200 , & V_207 ) )
break;
if ( ( V_271 == V_200 )
&& ( V_272 == V_207 ) ) {
V_223 -> V_220 . V_240 . V_242 [ 0 ] = V_103 ;
return 0 ;
}
}
F_29 ( V_35
L_65 ,
V_52 , V_271 , V_272 ) ;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = 0 ;
return 0 ;
}
static int F_172 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
int V_226 ;
T_2 V_52 = V_211 -> V_197 ;
T_1 V_271 , V_272 ;
T_1 V_29 ;
V_226 = 1 ;
V_29 = F_168 ( V_52 ,
V_223 -> V_220 . V_240 . V_242 [ 0 ] ,
& V_271 , & V_272 ) ;
if ( ! V_29 )
F_52 (
F_173 ( V_52 ,
V_271 , V_272 ) ) ;
return V_226 ;
}
static int T_5 F_174 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_66 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_169 ;
V_193 . V_232 = F_170 ;
V_193 . V_233 = F_172 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_175 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
static const char * const V_273 [ V_274 + 1 ] = {
L_67 ,
L_68 , L_69 ,
L_70 , L_71 ,
L_72 , L_73
} ;
T_2 V_52 = V_211 -> V_197 ;
T_1 V_275 ;
int V_257 ;
T_1 V_276 [ 6 ] ;
int V_277 = 0 ;
for ( V_257 = 0 ; V_257 < V_274 ; V_257 ++ )
if ( ! F_176 (
V_52 , V_257 , & V_275 ) ) {
V_276 [ V_277 ] = V_275 ;
V_277 ++ ;
}
V_213 -> type = V_239 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . V_240 . V_241 = V_277 ;
if ( V_213 -> V_220 . V_240 . V_242 >= V_277 )
V_213 -> V_220 . V_240 . V_242 = V_277 - 1 ;
strcpy ( V_213 -> V_220 . V_240 . V_40 ,
V_273 [ V_276 [ V_213 -> V_220 . V_240 . V_242 ] ] ) ;
return 0 ;
}
static int F_177 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_1 V_275 ;
if ( F_178 ( V_52 , & V_275 ) )
V_275 = 1 ;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = V_275 - 1 ;
return 0 ;
}
static int F_179 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
int V_226 ;
T_2 V_52 = V_211 -> V_197 ;
V_226 = 1 ;
F_52 ( F_180 ( V_52 ,
V_223 -> V_220 . V_240 . V_242 [ 0 ] + 1 ) ) ;
return V_226 ;
}
static int T_5 F_181 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
F_111 ( & V_193 , V_195 , L_74 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_175 ;
V_193 . V_232 = F_177 ;
V_193 . V_233 = F_179 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int F_182 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_211 -> V_84 ) ;
struct V_278 * V_279 = & V_49 -> V_280 ;
V_213 -> type = V_239 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . V_240 . V_241 = V_279 -> V_219 ;
if ( V_213 -> V_220 . V_240 . V_242 >= V_213 -> V_220 . V_240 . V_241 )
V_213 -> V_220 . V_240 . V_242 =
V_213 -> V_220 . V_240 . V_241 - 1 ;
strcpy ( V_213 -> V_220 . V_240 . V_40 ,
V_279 -> V_103 [ V_213 -> V_220 . V_240 . V_242 ] . V_40 ) ;
return 0 ;
}
static int F_183 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_211 -> V_84 ) ;
struct V_278 * V_279 = & V_49 -> V_280 ;
T_2 V_52 = V_211 -> V_197 ;
T_1 V_244 , V_281 = 0 ;
int V_257 ;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = 0 ;
if ( F_184 ( V_52 , & V_244 ) )
V_244 = 0 ;
if ( V_244 == V_282 )
if ( F_185 ( V_52 , & V_281 ) )
V_281 = 0 ;
for ( V_257 = 0 ; V_257 < V_279 -> V_219 ; V_257 ++ )
if ( ( V_279 -> V_103 [ V_257 ] . V_244 == V_244 ) &&
( V_279 -> V_103 [ V_257 ] . V_192 == V_281 ) )
break;
V_223 -> V_220 . V_240 . V_242 [ 0 ] = V_257 ;
return 0 ;
}
static int F_186 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
struct V_48 * V_49 =
(struct V_48 * ) ( V_211 -> V_84 ) ;
struct V_278 * V_279 = & V_49 -> V_280 ;
int V_226 , V_242 ;
T_2 V_52 = V_211 -> V_197 ;
V_226 = 1 ;
V_242 = V_223 -> V_220 . V_240 . V_242 [ 0 ] ;
if ( V_242 >= V_279 -> V_219 )
V_242 = V_279 -> V_219 - 1 ;
F_52 ( F_187 (
V_52 , V_279 -> V_103 [ V_242 ] . V_244 ) ) ;
if ( V_279 -> V_103 [ V_242 ] . V_244 == V_282 )
F_52 ( F_188 (
V_52 , V_279 -> V_103 [ V_242 ] . V_192 ) ) ;
return V_226 ;
}
static int F_189 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
V_213 -> type = V_218 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . integer . F_47 = 8000 ;
V_213 -> V_220 . integer . F_48 = 192000 ;
V_213 -> V_220 . integer . V_221 = 100 ;
return 0 ;
}
static int F_190 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_2 V_283 ;
T_1 V_29 ;
V_29 = F_191 ( V_52 , & V_283 ) ;
if ( ! V_29 )
V_223 -> V_220 . integer . V_220 [ 0 ] = V_283 ;
else
V_223 -> V_220 . integer . V_220 [ 0 ] = 0 ;
return 0 ;
}
static int F_192 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
int V_226 ;
T_2 V_52 = V_211 -> V_197 ;
V_226 = 1 ;
F_52 ( F_193 ( V_52 ,
V_223 -> V_220 . integer . V_220 [ 0 ] ) ) ;
return V_226 ;
}
static int F_194 ( struct V_210 * V_211 ,
struct V_212 * V_213 )
{
V_213 -> type = V_218 ;
V_213 -> V_219 = 1 ;
V_213 -> V_220 . integer . F_47 = 8000 ;
V_213 -> V_220 . integer . F_48 = 192000 ;
V_213 -> V_220 . integer . V_221 = 100 ;
return 0 ;
}
static int F_195 ( struct V_210 * V_211 ,
struct V_222 * V_223 )
{
T_2 V_52 = V_211 -> V_197 ;
T_2 V_283 ;
T_1 V_29 ;
V_29 = F_45 ( V_52 , & V_283 ) ;
if ( ! V_29 )
V_223 -> V_220 . integer . V_220 [ 0 ] = V_283 ;
else
V_223 -> V_220 . integer . V_220 [ 0 ] = 0 ;
return 0 ;
}
static int T_5 F_196 ( struct V_48 * V_49 ,
struct V_194 * V_195 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
struct V_189 V_193 ;
struct V_278 * V_279 = & V_49 -> V_280 ;
T_2 V_284 = V_195 -> V_52 ;
int V_285 = 0 ;
int V_257 , V_286 ;
T_1 V_244 ;
V_193 . V_197 = V_195 -> V_52 ;
V_279 -> V_287 = 0 ;
for ( V_257 = 0 ; V_257 <= V_288 ; V_257 ++ ) {
if ( F_197 ( V_284 ,
V_257 , & V_244 ) )
break;
V_279 -> V_103 [ V_257 ] . V_244 = V_244 ;
V_279 -> V_103 [ V_257 ] . V_192 = 0 ;
V_279 -> V_103 [ V_257 ] . V_40 = V_289 [ V_244 ] ;
if ( V_244 == V_282 )
V_285 = 1 ;
if ( V_244 == V_290 )
V_279 -> V_287 = 1 ;
}
if ( V_285 )
for ( V_286 = 1 ; V_286 < 8 ; V_286 ++ ) {
if ( F_198 ( V_284 ,
V_286 , V_282 ,
& V_244 ) )
break;
V_279 -> V_103 [ V_257 ] . V_244 =
V_282 ;
V_279 -> V_103 [ V_257 ] . V_192 = V_286 ;
V_279 -> V_103 [ V_257 ] . V_40 = V_289 [
V_286 + V_288 ] ;
V_257 ++ ;
}
V_279 -> V_219 = V_257 ;
F_111 ( & V_193 , V_195 , L_75 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_182 ;
V_193 . V_232 = F_183 ;
V_193 . V_233 = F_186 ;
if ( F_108 ( V_85 , & V_193 , V_49 ) < 0 )
return - V_47 ;
if ( V_279 -> V_287 ) {
F_111 ( & V_193 , V_195 , L_76 ) ;
V_193 . V_229 = V_230 ;
V_193 . V_161 = F_189 ;
V_193 . V_232 = F_190 ;
V_193 . V_233 = F_192 ;
if ( F_108 ( V_85 , & V_193 , V_49 ) < 0 )
return - V_47 ;
}
F_111 ( & V_193 , V_195 , L_77 ) ;
V_193 . V_229 =
V_249 | V_250 ;
V_193 . V_161 = F_194 ;
V_193 . V_232 = F_195 ;
return F_108 ( V_85 , & V_193 , V_49 ) ;
}
static int T_5 F_199 ( struct V_48 * V_49 )
{
struct V_188 * V_85 = V_49 -> V_85 ;
unsigned int V_54 = 0 ;
unsigned int V_291 = 0 ;
int V_33 ;
struct V_194 V_195 , V_292 ;
if ( F_200 ( ! V_49 ) )
return - V_47 ;
strcpy ( V_85 -> V_293 , L_78 ) ;
V_33 =
F_201 ( V_49 -> V_13 ,
& V_49 -> V_61 ) ;
F_52 ( V_33 ) ;
if ( V_33 )
return - V_33 ;
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
V_292 . V_294 = - 1 ;
for ( V_54 = 0 ; V_54 < 2000 ; V_54 ++ ) {
V_33 = F_202 (
V_49 -> V_61 ,
V_54 ,
& V_195 . V_200 ,
& V_195 . V_207 ,
& V_195 . V_202 ,
& V_195 . V_209 ,
& V_195 . V_294 ,
& V_195 . V_52 ) ;
if ( V_33 ) {
if ( V_33 == V_295 ) {
if ( V_191 )
F_44 ( V_149
L_79 ,
V_54 ) ;
continue;
} else
break;
}
V_195 . V_200 -= V_201 ;
V_195 . V_202 -= V_203 ;
if ( ( V_195 . V_294 == V_292 . V_294 ) &&
( V_195 . V_200 == V_292 . V_200 ) &&
( V_195 . V_207 == V_292 . V_207 ) &&
( V_195 . V_202 == V_292 . V_202 ) &&
( V_195 . V_209 == V_292 . V_209 ) )
V_291 ++ ;
else
V_291 = 0 ;
V_292 = V_195 ;
switch ( V_195 . V_294 ) {
case V_296 :
V_33 = F_122 ( V_49 , & V_195 ) ;
break;
case V_297 :
V_33 = F_129 ( V_49 , & V_195 ) ;
break;
case V_298 :
V_33 = F_174 ( V_49 , & V_195 ) ;
break;
case V_299 :
V_33 = F_181 ( V_49 , & V_195 ) ;
break;
case V_300 :
V_33 = F_166 ( V_49 , & V_195 , V_291 ) ;
break;
case V_63 :
V_33 = F_196 (
V_49 , & V_195 ) ;
break;
case V_301 :
continue;
case V_302 :
V_33 = F_162 ( V_49 , & V_195 ) ;
break;
case V_303 :
V_33 = F_142 ( V_49 , & V_195 ) ;
break;
case V_304 :
V_33 = F_139 ( V_49 , & V_195 ) ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
default:
if ( V_191 )
F_44 ( V_149
L_80
L_81 ,
V_54 ,
V_195 . V_294 ,
V_195 . V_200 ,
V_195 . V_207 ,
V_195 . V_202 ,
V_195 . V_209 ) ;
continue;
} ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_258 != V_33 )
F_52 ( V_33 ) ;
F_44 ( V_149 L_82 , V_54 ) ;
return 0 ;
}
static void
F_203 ( struct V_310 * V_311 ,
struct V_312 * V_17 )
{
struct V_48 * V_49 = V_311 -> V_84 ;
T_1 V_313 ;
T_2 V_52 ;
T_2 V_283 = 0 ;
T_1 V_244 = 0 ;
int V_33 ;
F_204 ( V_17 , L_83 ) ;
F_204 ( V_17 ,
L_84
L_85 ,
V_49 -> type , V_49 -> V_13 ,
V_49 -> V_180 , V_49 -> V_181 ) ;
V_313 = V_49 -> V_313 ;
F_204 ( V_17 ,
L_86 ,
V_49 -> V_314 , ( ( V_313 >> 3 ) & 0xf ) + 'A' ,
V_313 & 0x7 ,
( ( V_313 >> 13 ) * 100 ) + ( ( V_313 >> 7 ) & 0x3f ) ) ;
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 ) {
V_33 = F_45 (
V_52 , & V_283 ) ;
V_33 += F_184 ( V_52 , & V_244 ) ;
if ( ! V_33 )
F_204 ( V_17 , L_87 ,
V_283 , V_289 [ V_244 ] ) ;
}
}
static void T_5 F_205 ( struct V_48 * V_49 )
{
struct V_310 * V_311 ;
if ( ! F_206 ( V_49 -> V_85 , L_88 , & V_311 ) )
F_207 ( V_311 , V_49 , F_203 ) ;
}
static int F_208 ( struct V_315 * V_170 , struct V_316 * V_316 )
{
if ( V_317 )
return 0 ;
else
return - V_318 ;
}
static int F_209 ( struct V_315 * V_170 , struct V_316 * V_316 )
{
if ( V_317 )
return F_210 ( V_316 ) ;
else
return - V_318 ;
}
static int F_211 ( struct V_315 * V_170 , struct V_316 * V_316 ,
unsigned int V_102 , unsigned long V_148 )
{
if ( V_317 )
return F_212 ( V_316 , V_102 , V_148 ) ;
else
return - V_318 ;
}
static int T_5 F_213 ( struct V_48 * V_49 ,
int V_176 , struct V_315 * * V_319 )
{
struct V_315 * V_170 ;
int V_33 ;
if ( V_319 )
* V_319 = NULL ;
V_33 = F_214 ( V_49 -> V_85 , L_89 , V_176 , & V_170 ) ;
if ( V_33 < 0 )
return V_33 ;
strcpy ( V_170 -> V_40 , L_90 ) ;
V_170 -> V_198 = V_320 ;
V_170 -> V_321 . V_322 = F_208 ;
V_170 -> V_321 . V_323 = F_211 ;
V_170 -> V_321 . V_324 = F_209 ;
V_170 -> V_84 = V_49 ;
if ( V_319 )
* V_319 = V_170 ;
return 0 ;
}
static int T_5 F_215 ( struct V_325 * V_325 ,
const struct V_326 * V_327 )
{
int V_33 ;
T_1 V_313 ;
int V_328 ;
struct V_329 * V_330 ;
struct V_188 * V_85 ;
struct V_48 * V_49 ;
T_2 V_52 ;
T_2 V_1 ;
static int V_331 ;
if ( V_331 >= V_332 )
return - V_318 ;
if ( ! V_333 [ V_331 ] ) {
V_331 ++ ;
return - V_334 ;
}
V_33 = F_216 ( V_325 , V_327 ) ;
if ( V_33 < 0 )
return V_33 ;
V_330 = F_217 ( V_325 ) ;
V_33 = F_218 ( V_330 -> V_192 ,
V_335 [ V_330 -> V_192 ] , V_336 ,
sizeof( struct V_48 ) ,
& V_85 ) ;
if ( V_33 < 0 ) {
V_33 =
F_218 ( V_192 [ V_331 ] , V_335 [ V_331 ] ,
V_336 ,
sizeof( struct V_48 ) ,
& V_85 ) ;
if ( V_33 < 0 )
return V_33 ;
F_44 ( V_35
L_91 ,
V_330 -> V_192 , V_85 -> V_109 ) ;
}
F_219 ( V_85 , & V_325 -> V_331 ) ;
V_49 = (struct V_48 * ) V_85 -> V_84 ;
V_49 -> V_85 = V_85 ;
V_49 -> V_186 = V_325 ;
V_49 -> V_13 = V_330 -> V_192 ;
F_52 ( F_220 (
V_49 -> V_13 ,
& V_49 -> V_180 ,
& V_49 -> V_181 ,
& V_49 -> V_313 ,
& V_49 -> V_314 , & V_49 -> type ) ) ;
V_313 = V_49 -> V_313 ;
F_44 ( V_149 L_92
L_93
L_94 ,
V_49 -> type , V_49 -> V_13 ,
V_49 -> V_180 ,
V_49 -> V_181 , V_49 -> V_314 ,
( ( V_313 >> 3 ) & 0xf ) + 'A' ,
V_313 & 0x7 ,
( ( V_313 >> 13 ) * 100 ) + ( ( V_313 >> 7 ) & 0x3f ) ) ;
V_328 = V_49 -> V_180 ;
if ( V_328 < V_49 -> V_181 )
V_328 = V_49 -> V_181 ;
V_33 = F_221 ( V_49 -> V_13 ,
V_337 ,
NULL , & V_49 -> V_112 ) ;
if ( V_33 )
V_49 -> V_112 = 0 ;
V_33 = F_221 ( V_49 -> V_13 ,
V_338 ,
& V_49 -> V_58 , NULL ) ;
if ( V_33 )
V_49 -> V_58 = 0 ;
V_33 = F_221 ( V_49 -> V_13 ,
V_339 ,
NULL , & V_49 -> V_173 ) ;
if ( V_33 )
V_49 -> V_173 = 512 ;
if ( ! V_49 -> V_91 )
V_49 -> V_173 *= 2 ;
F_52 ( F_100 ( V_49 -> V_13 ,
0 , & V_1 ) ) ;
V_33 = F_222 ( V_1 ) ;
V_49 -> V_91 = ( ! V_33 ) ;
F_52 ( F_102 ( V_1 ) ) ;
V_33 = F_221 ( V_49 -> V_13 ,
V_340 ,
& V_49 -> V_175 , & V_49 -> V_160 ) ;
if ( V_33 ) {
V_49 -> V_175 = 2 ;
V_49 -> V_160 = 2 ;
}
F_44 ( V_149 L_95 ,
V_49 -> V_91 ,
V_49 -> V_112 ,
V_49 -> V_58
) ;
V_33 = F_103 ( V_49 , 0 , V_328 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_96 ) ;
goto V_341;
}
V_33 = F_199 ( V_49 ) ;
if ( V_33 < 0 ) {
F_44 ( V_64 L_97 ) ;
goto V_341;
}
V_33 = F_43 ( V_49 -> V_61 ,
V_62 , 0 , 0 , 0 ,
V_63 , & V_52 ) ;
if ( ! V_33 )
V_33 = F_193 (
V_52 , V_342 ) ;
F_205 ( V_49 ) ;
F_213 ( V_49 , 0 , NULL ) ;
strcpy ( V_85 -> V_343 , L_98 ) ;
sprintf ( V_85 -> V_344 , L_99 , V_49 -> type ) ;
sprintf ( V_85 -> V_345 , L_100 ,
V_85 -> V_344 , V_49 -> V_13 ) ;
V_33 = F_223 ( V_85 ) ;
if ( ! V_33 ) {
V_330 -> V_48 = V_85 ;
V_331 ++ ;
return 0 ;
}
V_341:
F_224 ( V_85 ) ;
F_44 ( V_64 L_101 , V_33 ) ;
return V_33 ;
}
static void T_6 F_225 ( struct V_325 * V_325 )
{
struct V_329 * V_330 = F_217 ( V_325 ) ;
F_224 ( V_330 -> V_48 ) ;
V_330 -> V_48 = NULL ;
F_226 ( V_325 ) ;
}
static int T_7 F_227 ( void )
{
F_228 () ;
return F_229 ( & V_343 ) ;
}
static void T_8 F_230 ( void )
{
F_231 ( & V_343 ) ;
F_232 () ;
}
