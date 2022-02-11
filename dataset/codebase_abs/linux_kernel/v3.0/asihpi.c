static void F_1 ( struct V_1 * V_2 ,
char * V_3 , T_1 V_4 )
{
snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_5 -> V_6 -> V_7 ,
V_2 -> V_5 -> V_8 ,
V_2 -> V_9 ? 'c' : 'p' ,
V_2 -> V_7 ) ;
}
static T_2 F_2 (
T_3 V_10 ,
T_3 V_11 ,
T_3 V_12
)
{
struct V_13 V_14 ;
struct V_15 V_16 ;
unsigned int V_17 = F_3 ( V_10 ) ;
if ( ! V_10 )
return V_18 ;
F_4 ( & V_14 , & V_16 , V_17 ,
V_17 == V_19 ?
V_20 :
V_21 ) ;
F_5 ( V_10 , & V_14 . V_22 ,
& V_14 . V_23 ) ;
V_14 . V_24 . V_25 . V_24 . V_26 . V_27 = V_11 ;
V_14 . V_24 . V_25 . V_24 . V_26 . V_12 = V_12 ;
V_14 . V_24 . V_25 . V_24 . V_26 . V_28 = V_29 ;
F_6 ( & V_14 , & V_16 ) ;
return V_16 . error ;
}
static T_2 F_7 ( T_3 V_10 )
{
struct V_13 V_14 ;
struct V_15 V_16 ;
unsigned int V_17 = F_3 ( V_10 ) ;
if ( ! V_10 )
return V_18 ;
F_4 ( & V_14 , & V_16 , V_17 ,
V_17 == V_19 ?
V_30 :
V_31 ) ;
F_5 ( V_10 , & V_14 . V_22 ,
& V_14 . V_23 ) ;
V_14 . V_24 . V_25 . V_24 . V_26 . V_28 = V_32 ;
F_6 ( & V_14 , & V_16 ) ;
return V_16 . error ;
}
static inline T_2 F_8 ( T_3 V_10 )
{
if ( F_3 ( V_10 ) == V_19 )
return F_9 ( V_10 ) ;
else
return F_10 ( V_10 ) ;
}
static inline T_2 F_11 ( T_3 V_10 )
{
if ( F_3 ( V_10 ) == V_19 )
return F_12 ( V_10 ) ;
else
return F_13 ( V_10 ) ;
}
static inline T_2 F_14 (
T_3 V_10 ,
T_2 * V_33 ,
T_3 * V_34 ,
T_3 * V_35 ,
T_3 * V_36 ,
T_3 * V_37
)
{
T_2 V_38 ;
if ( F_3 ( V_10 ) == V_19 )
V_38 = F_15 ( V_10 , V_33 ,
V_34 , V_35 ,
V_36 , V_37 ) ;
else
V_38 = F_16 ( V_10 , V_33 ,
V_34 , V_35 ,
V_36 , V_37 ) ;
return V_38 ;
}
static inline T_2 F_17 (
T_3 V_39 ,
T_3 V_10 )
{
if ( F_3 ( V_39 ) == V_19 )
return F_18 ( V_39 , V_10 ) ;
else
return F_19 ( V_39 , V_10 ) ;
}
static inline T_2 F_20 ( T_3 V_10 )
{
if ( F_3 ( V_10 ) == V_19 )
return F_21 ( V_10 ) ;
else
return F_22 ( V_10 ) ;
}
static inline T_2 F_23 (
T_3 V_10 , T_3 * V_40 , T_3 * V_41 )
{
if ( F_3 ( V_10 ) == V_19 )
return F_24 ( V_10 , V_40 , V_41 ) ;
else
return F_25 ( V_10 , V_40 , V_41 ) ;
}
static T_2 F_26 ( T_2 V_42 , int line , char * V_43 )
{
if ( V_42 )
F_27 ( V_44
L_2 ,
V_43 , line , V_42 ) ;
return V_42 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
F_29 ( V_2 , V_3 ) ;
F_30 ( L_3 , V_3 ) ;
F_30 ( L_4 , F_31 ( V_46 ) ) ;
F_30 ( L_5 , F_32 ( V_46 ) ) ;
F_30 ( L_6 , F_33 ( V_46 ) ) ;
F_30 ( L_7 , F_34 ( V_46 ) ) ;
F_30 ( L_8 , F_35 ( V_46 ) ) ;
F_30 ( L_9 , F_36 ( V_46 ) ) ;
F_30 ( L_10 , F_37 ( V_46 ) ) ;
F_30 ( L_11 , F_38 ( V_46 ) ) ;
F_30 ( L_12 , F_39 ( V_46 ) ) ;
F_30 ( L_13 , F_40 ( V_46 ) ) ;
F_30 ( L_14 , F_31 ( V_46 ) *
F_32 ( V_46 ) *
F_41 ( F_33 ( V_46 ) ) / 8 ) ;
}
static int F_42 ( T_4 V_47 ,
T_2 * V_48 )
{
T_2 V_49 ;
for ( V_49 = V_50 ;
V_49 <= V_51 ; V_49 ++ ) {
if ( V_52 [ V_49 ] == V_47 ) {
* V_48 = V_49 ;
return 0 ;
}
}
F_30 ( V_44 L_15 ,
V_47 ) ;
* V_48 = 0 ;
return - V_53 ;
}
static void F_43 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
T_2 V_42 ;
T_3 V_58 ;
T_3 V_59 ;
int V_60 ;
unsigned int V_61 = 200000 ;
unsigned int V_62 = 0 ;
unsigned int V_63 = 0 ;
if ( V_55 -> V_64 ) {
V_63 |= V_65 ;
V_63 |= V_66 ;
V_61 = 8000 ;
V_62 = 100000 ;
} else {
V_42 = F_44 ( V_55 -> V_67 ,
V_68 , 0 , 0 , 0 ,
V_69 , & V_58 ) ;
if ( V_42 ) {
F_45 ( V_70
L_16 , V_42 ) ;
}
for ( V_60 = - 1 ; V_60 < 100 ; V_60 ++ ) {
if ( V_60 == - 1 ) {
if ( F_46 ( V_58 ,
& V_59 ) )
continue;
} else if ( F_47 ( V_58 ,
V_60 , & V_59 ) ) {
break;
}
V_61 = F_48 ( V_61 , V_59 ) ;
V_62 = F_49 ( V_62 , V_59 ) ;
switch ( V_59 ) {
case 5512 :
V_63 |= V_71 ;
break;
case 8000 :
V_63 |= V_72 ;
break;
case 11025 :
V_63 |= V_73 ;
break;
case 16000 :
V_63 |= V_74 ;
break;
case 22050 :
V_63 |= V_75 ;
break;
case 32000 :
V_63 |= V_76 ;
break;
case 44100 :
V_63 |= V_77 ;
break;
case 48000 :
V_63 |= V_78 ;
break;
case 64000 :
V_63 |= V_79 ;
break;
case 88200 :
V_63 |= V_80 ;
break;
case 96000 :
V_63 |= V_81 ;
break;
case 176400 :
V_63 |= V_82 ;
break;
case 192000 :
V_63 |= V_83 ;
break;
default:
V_63 |= V_84 ;
}
}
}
V_57 -> V_63 = V_63 ;
V_57 -> V_61 = V_61 ;
V_57 -> V_62 = V_62 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_45 * V_85 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
struct V_54 * V_6 = F_51 ( V_2 ) ;
int V_42 ;
T_2 V_49 ;
int V_91 ;
unsigned int V_92 ;
F_28 ( V_2 , V_85 ) ;
V_42 = F_52 ( V_2 , F_35 ( V_85 ) ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_42 ( F_33 ( V_85 ) , & V_49 ) ;
if ( V_42 )
return V_42 ;
F_53 ( F_54 ( & V_89 -> V_49 ,
F_32 ( V_85 ) ,
V_49 , F_31 ( V_85 ) , 0 , 0 ) ) ;
if ( V_2 -> V_9 == V_93 ) {
if ( F_55 ( V_89 -> V_10 ) != 0 )
return - V_53 ;
if ( F_56 (
V_89 -> V_10 , & V_89 -> V_49 ) != 0 )
return - V_53 ;
}
V_89 -> V_94 = 0 ;
if ( V_6 -> V_95 ) {
V_42 = F_2 ( V_89 -> V_10 ,
F_35 ( V_85 ) , V_87 -> V_96 ) ;
if ( V_42 == 0 ) {
F_57 (
L_17 ,
F_35 ( V_85 ) ,
( unsigned long ) V_87 -> V_96 ) ;
} else {
F_30 ( L_18 ,
V_42 ) ;
return - V_97 ;
}
V_42 = F_14 ( V_89 -> V_10 , NULL ,
& V_89 -> V_94 ,
NULL , NULL , NULL ) ;
F_57 ( L_19 ,
V_89 -> V_94 ) ;
}
V_92 = F_31 ( V_85 ) * F_32 ( V_85 ) ;
V_91 = F_41 ( F_33 ( V_85 ) ) ;
V_92 *= V_91 ;
V_92 /= 8 ;
if ( V_91 < 0 || V_92 == 0 )
return - V_53 ;
V_89 -> V_92 = V_92 ;
V_89 -> V_98 = F_35 ( V_85 ) ;
V_89 -> V_99 = F_36 ( V_85 ) ;
return 0 ;
}
static int
F_58 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
if ( V_89 -> V_94 )
F_7 ( V_89 -> V_10 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_86 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_90 ;
F_61 ( V_89 ) ;
}
static void F_62 ( struct V_1 *
V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
int V_100 ;
V_100 = V_101 / 200 ;
V_100 = F_49 ( V_100 , 1 ) ;
V_89 -> V_102 . V_103 = V_104 + V_100 ;
V_89 -> V_105 = 1 ;
F_63 ( & V_89 -> V_102 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
V_89 -> V_105 = 0 ;
F_65 ( & V_89 -> V_102 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
int V_106 )
{
struct V_88 * V_89 = V_2 -> V_87 -> V_90 ;
struct V_54 * V_6 = F_51 ( V_2 ) ;
struct V_1 * V_107 ;
T_2 V_38 ;
F_29 ( V_2 , V_3 ) ;
F_57 ( L_20 , V_3 ) ;
switch ( V_106 ) {
case V_108 :
F_67 (s, substream) {
struct V_86 * V_87 = V_107 -> V_87 ;
struct V_88 * V_109 = V_87 -> V_90 ;
if ( F_51 ( V_107 ) != V_6 )
continue;
if ( V_2 -> V_9 != V_107 -> V_9 )
continue;
V_109 -> V_110 = 0 ;
if ( V_107 -> V_9 == V_111 ) {
unsigned int V_112 = V_109 -> V_99 * 1 ;
F_68 ( L_21 , V_107 -> V_7 , V_112 ) ;
F_53 ( F_69 (
V_109 -> V_10 ,
& V_87 -> V_113 [ 0 ] ,
V_112 ,
& V_109 -> V_49 ) ) ;
V_109 -> V_114 = V_112 ;
}
if ( V_6 -> V_115 ) {
F_57 ( L_22 , V_107 -> V_7 ) ;
V_38 = F_17 (
V_89 -> V_10 ,
V_109 -> V_10 ) ;
if ( ! V_38 ) {
F_70 ( V_107 , V_2 ) ;
} else {
F_53 ( V_38 ) ;
break;
}
} else
break;
}
F_57 ( L_23 ) ;
F_62 ( V_2 ) ;
if ( ( V_2 -> V_9 == V_93 ) ||
! V_6 -> V_95 )
F_53 ( F_8 ( V_89 -> V_10 ) ) ;
break;
case V_116 :
F_64 ( V_2 ) ;
F_67 (s, substream) {
if ( F_51 ( V_107 ) != V_6 )
continue;
if ( V_2 -> V_9 != V_107 -> V_9 )
continue;
V_107 -> V_87 -> V_117 -> V_118 = V_119 ;
if ( V_6 -> V_115 ) {
F_57 ( L_22 , V_107 -> V_7 ) ;
F_70 ( V_107 , V_2 ) ;
} else
break;
}
F_57 ( L_24 ) ;
F_53 ( F_11 ( V_89 -> V_10 ) ) ;
if ( V_2 -> V_9 == V_111 )
F_53 (
F_71 ( V_89 -> V_10 ) ) ;
if ( V_6 -> V_115 )
F_53 ( F_20 ( V_89 -> V_10 ) ) ;
break;
case V_120 :
F_57 ( L_25 ) ;
F_53 ( F_8 ( V_89 -> V_10 ) ) ;
F_62 ( V_2 ) ;
break;
case V_121 :
F_57 ( L_26 ) ;
F_64 ( V_2 ) ;
F_53 ( F_11 ( V_89 -> V_10 ) ) ;
break;
default:
F_30 ( V_70 L_27 ) ;
return - V_53 ;
}
return 0 ;
}
static inline unsigned int F_72 ( unsigned int V_122 , unsigned int V_123 ,
unsigned long int V_124 )
{
unsigned int V_125 ;
if ( ( ( V_122 - V_123 ) % V_124 ) < ( V_124 / 2 ) )
V_125 = V_123 ;
else
V_125 = V_122 ;
return V_125 ;
}
static void F_73 ( unsigned long V_126 )
{
struct V_88 * V_89 = (struct V_88 * ) V_126 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_54 * V_6 = F_51 ( V_2 ) ;
struct V_86 * V_87 ;
struct V_1 * V_107 ;
unsigned int V_127 = 0 ;
unsigned int V_128 , V_129 = 0 ;
unsigned int V_130 , V_131 , V_132 ;
int V_133 = 1 ;
int V_134 = 0 ;
T_2 V_118 ;
T_3 V_27 , V_135 , V_136 , V_137 ;
F_29 ( V_2 , V_3 ) ;
F_57 ( L_28 , V_3 ) ;
F_67 (s, substream) {
struct V_88 * V_109 = V_107 -> V_87 -> V_90 ;
V_87 = V_107 -> V_87 ;
if ( F_51 ( V_107 ) != V_6 )
continue;
if ( V_2 -> V_9 != V_107 -> V_9 )
continue;
F_53 ( F_14 (
V_109 -> V_10 , & V_118 ,
& V_27 , & V_135 ,
& V_136 , & V_137 ) ) ;
V_87 -> V_138 = V_137 ;
if ( ! V_6 -> V_95 )
V_137 = V_135 ;
if ( V_107 -> V_9 == V_111 ) {
V_128 = V_109 -> V_114 - V_135 ;
if ( V_118 == V_139 ) {
if ( ( V_135 == 0 ) &&
( V_137 < V_109 -> V_114 ) ) {
F_53 ( F_8 ( V_109 -> V_10 ) ) ;
F_57 ( L_29 , V_107 -> V_7 ) ;
V_109 -> V_110 = 0 ;
}
} else if ( V_118 == V_140 ) {
F_30 ( V_44 L_30 ,
V_107 -> V_7 ) ;
V_109 -> V_110 ++ ;
if ( V_109 -> V_110 > 2 ) {
F_74 ( V_107 , V_141 ) ;
continue;
}
} else {
V_109 -> V_110 = 0 ;
}
} else
V_128 = V_135 + V_109 -> V_114 ;
if ( V_133 ) {
V_129 = V_128 ;
V_127 = ( V_128 - V_109 -> V_142 ) % V_109 -> V_98 ;
V_133 = 0 ;
} else {
V_129 =
F_72 ( V_129 , V_128 , V_143 + 1L ) ;
V_127 = F_48 (
( V_128 - V_109 -> V_142 ) % V_109 -> V_98 ,
V_127 ) ;
}
F_57 ( L_31 ,
( unsigned long ) F_75 ( V_87 ,
V_87 -> V_117 -> V_144 ) ,
( unsigned long ) F_75 ( V_87 ,
V_87 -> V_145 -> V_146 ) ) ;
F_57 ( L_32
L_33
L_34 ,
V_107 -> V_7 , V_118 ,
V_109 -> V_114 , V_128 ,
( int ) V_135 ,
( int ) V_137 , V_27 - V_135 ) ;
V_134 ++ ;
}
V_128 = V_129 ;
V_130 = V_127 % V_89 -> V_99 ;
V_131 = V_127 - V_130 ;
if ( V_131 && ( V_137 > V_89 -> V_99 ) )
V_132 = ( ( V_137 - V_89 -> V_99 ) * V_101 / V_89 -> V_92 ) ;
else
V_132 = ( ( V_89 -> V_99 - V_130 ) * V_101 / V_89 -> V_92 ) ;
V_132 = F_49 ( V_132 , 1U ) ;
V_89 -> V_102 . V_103 = V_104 + V_132 ;
F_57 ( L_35 ,
V_132 , V_128 , V_127 , V_131 ) ;
F_67 (s, substream) {
struct V_88 * V_109 = V_107 -> V_87 -> V_90 ;
if ( V_2 -> V_9 != V_107 -> V_9 )
continue;
V_109 -> V_128 = V_128 ;
if ( V_131 &&
( ( V_137 <= V_109 -> V_99 ) ||
( V_107 -> V_9 == V_93 ) ) )
{
unsigned int V_147 = V_109 -> V_114 % V_109 -> V_98 ;
unsigned int V_148 , V_149 ;
char * V_150 = & V_107 -> V_87 -> V_113 [ V_147 ] ;
if ( V_6 -> V_95 ) {
V_148 = V_131 ;
V_149 = 0 ;
} else {
V_148 = F_48 ( V_131 , V_109 -> V_98 - V_147 ) ;
V_149 = V_131 - V_148 ;
}
if ( V_107 -> V_9 == V_111 ) {
F_68 ( L_36 ,
V_107 -> V_7 , V_148 , V_147 ) ;
F_53 (
F_69 (
V_109 -> V_10 , V_150 , V_148 ,
& V_109 -> V_49 ) ) ;
if ( V_149 ) {
V_150 = V_107 -> V_87 -> V_113 ;
F_68 ( L_37 ,
V_107 -> V_7 ,
V_131 - V_148 , V_147 ) ;
F_53 (
F_69 (
V_109 -> V_10 , V_150 ,
V_131 - V_148 ,
& V_109 -> V_49 ) ) ;
}
} else {
F_68 ( L_38 ,
V_107 -> V_7 , V_148 ) ;
F_53 (
F_76 (
V_109 -> V_10 ,
V_150 , V_148 ) ) ;
if ( V_149 ) {
V_150 = V_107 -> V_87 -> V_113 ;
F_68 ( L_39 ,
V_107 -> V_7 , V_149 ) ;
F_53 (
F_76 (
V_109 -> V_10 ,
V_150 , V_149 ) ) ;
}
}
V_109 -> V_114 = V_109 -> V_114 + V_131 ;
V_109 -> V_142 = V_128 ;
F_77 ( V_107 ) ;
}
}
if ( V_89 -> V_105 )
F_63 ( & V_89 -> V_102 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
unsigned int V_106 , void * V_151 )
{
F_68 ( V_152 L_40 , V_2 -> V_7 , V_106 ) ;
return F_79 ( V_2 , V_106 , V_151 ) ;
}
static int F_80 ( struct V_1 *
V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
F_57 ( L_41 , V_2 -> V_7 ) ;
F_53 ( F_71 ( V_89 -> V_10 ) ) ;
V_89 -> V_114 = 0 ;
V_89 -> V_128 = 0 ;
V_89 -> V_142 = 0 ;
return 0 ;
}
static T_5
F_81 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
T_5 V_153 ;
V_153 = F_82 ( V_87 , V_89 -> V_128 % V_89 -> V_98 ) ;
F_68 ( L_42 , V_2 -> V_7 , ( unsigned long ) V_153 ) ;
return V_153 ;
}
static void F_83 ( struct V_54 * V_55 ,
T_3 V_10 ,
struct V_56 * V_57 )
{
struct V_48 V_48 ;
T_2 V_49 ;
T_2 V_42 ;
T_3 V_58 ;
T_3 V_59 = 48000 ;
V_42 = F_44 ( V_55 -> V_67 ,
V_68 , 0 , 0 , 0 ,
V_69 , & V_58 ) ;
if ( ! V_42 )
V_42 = F_46 ( V_58 ,
& V_59 ) ;
for ( V_49 = V_50 ;
V_49 <= V_51 ; V_49 ++ ) {
V_42 = F_54 ( & V_48 ,
2 , V_49 , V_59 , 128000 , 0 ) ;
if ( ! V_42 )
V_42 = F_84 ( V_10 ,
& V_48 ) ;
if ( ! V_42 && ( V_52 [ V_49 ] != - 1 ) )
V_57 -> V_154 |=
( 1ULL << V_52 [ V_49 ] ) ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 ;
struct V_54 * V_6 = F_51 ( V_2 ) ;
int V_42 ;
V_89 = F_86 ( sizeof( * V_89 ) , V_155 ) ;
if ( V_89 == NULL )
return - V_97 ;
V_42 =
F_87 ( V_6 -> V_22 ,
V_2 -> V_7 , & V_89 -> V_10 ) ;
F_53 ( V_42 ) ;
if ( V_42 )
F_61 ( V_89 ) ;
if ( V_42 == V_156 )
return - V_157 ;
if ( V_42 )
return - V_158 ;
F_88 ( & V_89 -> V_102 ) ;
V_89 -> V_102 . V_126 = ( unsigned long ) V_89 ;
V_89 -> V_102 . V_159 = F_73 ;
V_89 -> V_2 = V_2 ;
V_87 -> V_90 = V_89 ;
V_87 -> V_160 = F_60 ;
V_161 . V_162 = V_6 -> V_163 ;
F_83 ( V_6 , V_89 -> V_10 ,
& V_161 ) ;
F_43 ( V_6 , & V_161 ) ;
V_161 . V_164 = V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 ;
if ( V_6 -> V_115 )
V_161 . V_164 |= V_172 ;
V_87 -> V_173 = V_161 ;
if ( V_6 -> V_95 )
V_42 = F_89 ( V_87 , 0 ,
V_174 ) ;
if ( V_42 < 0 )
return V_42 ;
F_90 ( V_87 , 0 , V_175 ,
V_6 -> V_176 ) ;
F_91 ( V_87 , V_175 ,
V_6 -> V_176 * 2 , V_143 ) ;
F_92 ( V_2 ) ;
F_57 ( L_43 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
F_53 ( F_94 ( V_89 -> V_10 ) ) ;
F_57 ( L_44 ) ;
return 0 ;
}
static T_5
F_95 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
F_68 ( L_45 ,
V_2 -> V_7 , V_89 -> V_128 ) ;
return F_82 ( V_87 , V_89 -> V_128 % V_89 -> V_98 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
unsigned int V_106 , void * V_151 )
{
return F_79 ( V_2 , V_106 , V_151 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_88 * V_89 = V_87 -> V_90 ;
F_53 ( F_55 ( V_89 -> V_10 ) ) ;
V_89 -> V_114 = 0 ;
V_89 -> V_128 = 0 ;
V_89 -> V_142 = 0 ;
F_57 ( L_46 , V_2 -> V_7 ) ;
return 0 ;
}
static void F_98 ( struct V_54 * V_55 ,
T_3 V_10 ,
struct V_56 * V_57 )
{
struct V_48 V_48 ;
T_2 V_49 ;
T_2 V_42 ;
T_3 V_58 ;
T_3 V_59 = 48000 ;
V_42 = F_44 ( V_55 -> V_67 ,
V_68 , 0 , 0 , 0 ,
V_69 , & V_58 ) ;
if ( ! V_42 )
V_42 = F_46 ( V_58 ,
& V_59 ) ;
for ( V_49 = V_50 ;
V_49 <= V_51 ; V_49 ++ ) {
V_42 = F_54 ( & V_48 , 2 , V_49 ,
V_59 , 128000 , 0 ) ;
if ( ! V_42 )
V_42 = F_99 ( V_10 ,
& V_48 ) ;
if ( ! V_42 )
V_57 -> V_154 |=
( 1ULL << V_52 [ V_49 ] ) ;
}
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_54 * V_6 = F_51 ( V_2 ) ;
struct V_88 * V_89 ;
int V_42 ;
V_89 = F_86 ( sizeof( * V_89 ) , V_155 ) ;
if ( V_89 == NULL )
return - V_97 ;
F_57 ( L_47 ,
V_6 -> V_22 , V_2 -> V_7 ) ;
V_42 = F_53 (
F_101 ( V_6 -> V_22 ,
V_2 -> V_7 , & V_89 -> V_10 ) ) ;
if ( V_42 )
F_61 ( V_89 ) ;
if ( V_42 == V_156 )
return - V_157 ;
if ( V_42 )
return - V_158 ;
F_88 ( & V_89 -> V_102 ) ;
V_89 -> V_102 . V_126 = ( unsigned long ) V_89 ;
V_89 -> V_102 . V_159 = F_73 ;
V_89 -> V_2 = V_2 ;
V_87 -> V_90 = V_89 ;
V_87 -> V_160 = F_60 ;
V_177 . V_162 = V_6 -> V_178 ;
F_98 ( V_6 , V_89 -> V_10 ,
& V_177 ) ;
F_43 ( V_6 , & V_177 ) ;
V_177 . V_164 = V_165 |
V_170 |
V_171 ;
if ( V_6 -> V_115 )
V_177 . V_164 |= V_172 ;
V_87 -> V_173 = V_177 ;
if ( V_6 -> V_95 )
V_42 = F_89 ( V_87 , 0 ,
V_174 ) ;
if ( V_42 < 0 )
return V_42 ;
F_90 ( V_87 , 0 , V_175 ,
V_6 -> V_176 ) ;
F_91 ( V_87 , V_175 ,
V_6 -> V_176 * 2 , V_143 ) ;
F_92 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_87 -> V_90 ;
F_53 ( F_103 ( V_89 -> V_10 ) ) ;
return 0 ;
}
static int T_6 F_104 ( struct V_54 * V_55 ,
int V_8 , int V_179 )
{
struct V_180 * V_5 ;
int V_42 ;
V_42 = F_105 ( V_55 -> V_6 , L_48 , V_8 ,
V_55 -> V_181 , V_55 -> V_182 ,
& V_5 ) ;
if ( V_42 < 0 )
return V_42 ;
F_106 ( V_5 , V_111 ,
& V_183 ) ;
F_106 ( V_5 , V_93 ,
& V_184 ) ;
V_5 -> V_90 = V_55 ;
V_5 -> V_185 = 0 ;
strcpy ( V_5 -> V_3 , L_48 ) ;
F_107 ( V_5 , V_186 ,
F_108 ( V_55 -> V_187 ) ,
64 * 1024 , V_188 ) ;
return 0 ;
}
static inline int F_109 ( struct V_189 * V_6 , struct V_190 * V_191 ,
struct V_54 * V_55 )
{
int V_42 ;
V_42 = F_110 ( V_6 , F_111 ( V_191 , V_55 ) ) ;
if ( V_42 < 0 )
return V_42 ;
else if ( V_192 )
F_45 ( V_152 L_49 , V_191 -> V_3 , V_191 -> V_193 ) ;
return 0 ;
}
static void F_112 ( struct V_190 * V_194 ,
struct V_195 * V_196 ,
char * V_3 )
{
char * V_197 ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_3 = V_196 -> V_3 ;
V_194 -> V_198 = V_196 -> V_58 ;
V_194 -> V_199 = V_200 ;
V_194 -> V_193 = 0 ;
if ( V_196 -> V_201 + V_202 == V_68 )
V_197 = L_50 ;
else if ( V_196 -> V_203 + V_204 == V_205 )
V_197 = L_51 ;
else if ( ( V_196 -> V_201 + V_202 != V_206 ) &&
( ! V_196 -> V_203 ) )
V_197 = L_51 ;
else if ( V_196 -> V_201 &&
( V_196 -> V_201 + V_202 != V_206 ) &&
( V_196 -> V_203 ) )
V_197 = L_52 ;
else
V_197 = L_53 ;
if ( V_196 -> V_201 && V_196 -> V_203 )
sprintf ( V_196 -> V_3 , L_54 ,
V_207 [ V_196 -> V_201 ] ,
V_196 -> V_208 ,
V_209 [ V_196 -> V_203 ] ,
V_196 -> V_210 ,
V_197 , V_3 ) ;
else if ( V_196 -> V_203 ) {
sprintf ( V_196 -> V_3 , L_55 ,
V_209 [ V_196 -> V_203 ] ,
V_196 -> V_210 ,
V_197 , V_3 ) ;
} else {
sprintf ( V_196 -> V_3 , L_55 ,
V_207 [ V_196 -> V_201 ] ,
V_196 -> V_208 ,
V_197 , V_3 ) ;
}
}
static int F_113 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_42 ;
short V_215 ;
short V_216 ;
short V_217 ;
V_42 = F_114 ( V_58 ,
& V_215 , & V_216 , & V_217 ) ;
if ( V_42 ) {
V_216 = 0 ;
V_215 = - 10000 ;
V_217 = V_218 ;
}
V_214 -> type = V_219 ;
V_214 -> V_220 = 2 ;
V_214 -> V_221 . integer . F_48 = V_215 / V_218 ;
V_214 -> V_221 . integer . F_49 = V_216 / V_218 ;
V_214 -> V_221 . integer . V_222 = V_217 / V_218 ;
return 0 ;
}
static int F_115 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
short V_225 [ V_226 ] ;
F_53 ( F_116 ( V_58 , V_225 ) ) ;
V_224 -> V_221 . integer . V_221 [ 0 ] = V_225 [ 0 ] / V_218 ;
V_224 -> V_221 . integer . V_221 [ 1 ] = V_225 [ 1 ] / V_218 ;
return 0 ;
}
static int F_117 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
int V_227 ;
T_3 V_58 = V_212 -> V_198 ;
short V_225 [ V_226 ] ;
V_225 [ 0 ] =
( V_224 -> V_221 . integer . V_221 [ 0 ] ) * V_218 ;
V_225 [ 1 ] =
( V_224 -> V_221 . integer . V_221 [ 1 ] ) * V_218 ;
V_227 = 1 ;
F_53 ( F_118 ( V_58 , V_225 ) ) ;
return V_227 ;
}
static int T_6 F_119 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_56 ) ;
V_194 . V_228 = V_229 |
V_230 ;
V_194 . V_164 = F_113 ;
V_194 . V_231 = F_115 ;
V_194 . V_232 = F_117 ;
V_194 . V_233 . V_46 = V_234 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_120 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_42 ;
short V_215 ;
short V_216 ;
short V_217 ;
V_42 =
F_121 ( V_58 , & V_215 ,
& V_216 , & V_217 ) ;
if ( V_42 ) {
V_216 = 2400 ;
V_215 = - 1000 ;
V_217 = 100 ;
}
V_214 -> type = V_219 ;
V_214 -> V_220 = 2 ;
V_214 -> V_221 . integer . F_48 = V_215 / V_235 ;
V_214 -> V_221 . integer . F_49 = V_216 / V_235 ;
V_214 -> V_221 . integer . V_222 = V_217 / V_235 ;
return 0 ;
}
static int F_122 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
short V_225 [ V_226 ] ;
F_53 ( F_123 ( V_58 , V_225 ) ) ;
V_224 -> V_221 . integer . V_221 [ 0 ] =
V_225 [ 0 ] / V_235 ;
V_224 -> V_221 . integer . V_221 [ 1 ] =
V_225 [ 1 ] / V_235 ;
return 0 ;
}
static int F_124 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
int V_227 ;
T_3 V_58 = V_212 -> V_198 ;
short V_225 [ V_226 ] ;
V_225 [ 0 ] =
( V_224 -> V_221 . integer . V_221 [ 0 ] ) * V_235 ;
V_225 [ 1 ] =
( V_224 -> V_221 . integer . V_221 [ 1 ] ) * V_235 ;
V_227 = 1 ;
F_53 ( F_125 ( V_58 , V_225 ) ) ;
return V_227 ;
}
static int T_6 F_126 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_57 ) ;
V_194 . V_228 = V_229 |
V_230 ;
V_194 . V_164 = F_120 ;
V_194 . V_231 = F_122 ;
V_194 . V_232 = F_124 ;
V_194 . V_233 . V_46 = V_236 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_127 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_237 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . V_238 . V_239 = 3 ;
if ( V_214 -> V_221 . V_238 . V_240 >= V_214 -> V_221 . V_238 . V_239 )
V_214 -> V_221 . V_238 . V_240 =
V_214 -> V_221 . V_238 . V_239 - 1 ;
strcpy ( V_214 -> V_221 . V_238 . V_3 ,
V_241 [ V_214 -> V_221 . V_238 . V_240 ] ) ;
return 0 ;
}
static int F_128 ( struct V_211 * V_212 ,
struct V_223 * V_224 ,
T_2 (* F_129)( T_3 , T_2 * ) )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_242 , V_42 ;
V_42 = F_129 ( V_58 , & V_242 ) ;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = 0 ;
if ( V_42 )
return 0 ;
if ( V_242 == V_243 )
V_224 -> V_221 . V_238 . V_240 [ 0 ] = 1 ;
if ( V_242 == V_244 )
V_224 -> V_221 . V_238 . V_240 [ 0 ] = 2 ;
return 0 ;
}
static int F_130 ( struct V_211 * V_212 ,
struct V_223 * V_224 ,
T_2 (* F_129)( T_3 , T_2 ) )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_242 = V_243 ;
if ( V_224 -> V_221 . V_238 . V_240 [ 0 ] == 1 )
V_242 = V_243 ;
if ( V_224 -> V_221 . V_238 . V_240 [ 0 ] == 2 )
V_242 = V_244 ;
if ( F_129 ( V_58 , V_242 ) != 0 )
return - V_53 ;
return 1 ;
}
static int F_131 ( struct V_211 * V_212 ,
struct V_223 * V_224 ) {
return F_128 ( V_212 , V_224 ,
V_245 ) ;
}
static int F_132 ( struct V_211 * V_212 ,
struct V_223 * V_224 ) {
return F_130 ( V_212 , V_224 ,
V_246 ) ;
}
static int F_133 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_219 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . integer . F_48 = 0 ;
V_214 -> V_221 . integer . F_49 = 0X1F ;
V_214 -> V_221 . integer . V_222 = 1 ;
return 0 ;
}
static int F_134 ( struct V_211 * V_212 ,
struct V_223 * V_224 ) {
T_3 V_58 = V_212 -> V_198 ;
T_2 V_117 ;
F_53 ( F_135 (
V_58 , & V_117 ) ) ;
V_224 -> V_221 . integer . V_221 [ 0 ] = V_117 ;
return 0 ;
}
static int T_6 F_136 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_58 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_127 ;
V_194 . V_231 = F_131 ;
V_194 . V_232 = F_132 ;
if ( F_109 ( V_6 , & V_194 , V_55 ) < 0 )
return - V_53 ;
F_112 ( & V_194 , V_196 , L_59 ) ;
V_194 . V_228 =
V_247 | V_248 ;
V_194 . V_164 = F_133 ;
V_194 . V_231 = F_134 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_137 ( struct V_211 * V_212 ,
struct V_223 * V_224 ) {
return F_128 ( V_212 , V_224 ,
V_249 ) ;
}
static int F_138 ( struct V_211 * V_212 ,
struct V_223 * V_224 ) {
return F_130 ( V_212 , V_224 ,
V_250 ) ;
}
static int T_6 F_139 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_58 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_127 ;
V_194 . V_231 = F_137 ;
V_194 . V_232 = F_138 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_140 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_42 ;
short V_60 ;
T_2 V_251 [ 3 ] ;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
V_42 = F_141 ( V_58 ,
V_60 , & V_251 [ V_60 ] ) ;
if ( V_42 != 0 )
return V_42 ;
}
V_214 -> type = V_219 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . integer . F_48 = ( ( int ) V_251 [ 0 ] ) / V_235 ;
V_214 -> V_221 . integer . F_49 = ( ( int ) V_251 [ 1 ] ) / V_235 ;
V_214 -> V_221 . integer . V_222 = ( ( int ) V_251 [ 2 ] ) / V_235 ;
return 0 ;
}
static int F_142 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
short V_252 ;
F_53 ( F_143 ( V_58 , & V_252 ) ) ;
V_224 -> V_221 . integer . V_221 [ 0 ] = V_252 / V_235 ;
return 0 ;
}
static int F_144 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
short V_252 ;
V_252 = ( V_224 -> V_221 . integer . V_221 [ 0 ] ) * V_235 ;
F_53 ( F_145 ( V_58 , V_252 ) ) ;
return 1 ;
}
static int F_146 ( struct V_211 * V_212 ,
T_2 * V_253 , T_3 V_4 ) {
T_3 V_58 = V_212 -> V_198 ;
T_2 V_42 = 0 ;
T_3 V_254 ;
for ( V_254 = 0 ; V_254 < V_4 ; V_254 ++ ) {
V_42 = F_147 (
V_58 , V_254 , & V_253 [ V_254 ] ) ;
if ( V_42 != 0 )
break;
}
if ( V_42 && ( V_42 != V_255 ) )
return - V_158 ;
return V_254 ;
}
static int F_148 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
T_2 V_256 [ V_257 ] ;
int V_258 = 0 ;
V_258 = F_146 ( V_212 , V_256 ,
V_257 ) ;
if ( V_258 < 0 )
return V_258 ;
V_214 -> type = V_237 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . V_238 . V_239 = V_258 ;
if ( V_258 > 0 ) {
if ( V_214 -> V_221 . V_238 . V_240 >=
V_214 -> V_221 . V_238 . V_239 )
V_214 -> V_221 . V_238 . V_240 =
V_214 -> V_221 . V_238 . V_239 - 1 ;
strcpy ( V_214 -> V_221 . V_238 . V_3 ,
V_259 [
V_256 [ V_214 -> V_221 . V_238 . V_240 ] ] ) ;
}
return 0 ;
}
static int F_149 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_260 , V_60 ;
T_2 V_256 [ V_257 ] ;
T_3 V_258 = 0 ;
V_258 = F_146 ( V_212 , V_256 ,
V_257 ) ;
F_53 ( F_150 ( V_58 , & V_260 ) ) ;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = - 1 ;
for ( V_60 = 0 ; V_60 < V_257 ; V_60 ++ )
if ( V_256 [ V_60 ] == V_260 ) {
V_224 -> V_221 . V_238 . V_240 [ 0 ] = V_60 ;
break;
}
return 0 ;
}
static int F_151 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_260 ;
T_2 V_256 [ V_257 ] ;
T_3 V_258 = 0 ;
V_258 = F_146 ( V_212 , V_256 ,
V_257 ) ;
V_260 = V_256 [ V_224 -> V_221 . V_238 . V_240 [ 0 ] ] ;
F_53 ( F_152 ( V_58 , V_260 ) ) ;
return 1 ;
}
static int F_153 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_42 ;
T_2 V_256 [ V_257 ] ;
T_2 V_258 = 0 , V_261 , V_60 ;
T_3 V_262 [ 3 ] , V_263 [ 3 ] ;
V_258 = F_146 ( V_212 , V_256 ,
V_257 ) ;
V_262 [ 0 ] = V_264 ;
V_262 [ 1 ] = 0 ;
V_262 [ 2 ] = V_264 ;
for ( V_261 = 0 ; V_261 < V_258 ; V_261 ++ ) {
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
V_42 = F_154 ( V_58 ,
V_60 , V_256 [ V_261 ] ,
& V_263 [ V_60 ] ) ;
if ( V_42 != 0 )
return V_42 ;
}
if ( V_263 [ 2 ] <= 0 )
continue;
if ( V_263 [ 0 ] < V_262 [ 0 ] )
V_262 [ 0 ] = V_263 [ 0 ] ;
if ( V_263 [ 1 ] > V_262 [ 1 ] )
V_262 [ 1 ] = V_263 [ 1 ] ;
if ( V_263 [ 2 ] < V_262 [ 2 ] )
V_262 [ 2 ] = V_263 [ 2 ] ;
}
V_214 -> type = V_219 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . integer . F_48 = ( ( int ) V_262 [ 0 ] ) ;
V_214 -> V_221 . integer . F_49 = ( ( int ) V_262 [ 1 ] ) ;
V_214 -> V_221 . integer . V_222 = ( ( int ) V_262 [ 2 ] ) ;
return 0 ;
}
static int F_155 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_3 V_265 ;
F_53 ( F_156 ( V_58 , & V_265 ) ) ;
V_224 -> V_221 . integer . V_221 [ 0 ] = V_265 ;
return 0 ;
}
static int F_157 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_3 V_265 ;
V_265 = V_224 -> V_221 . integer . V_221 [ 0 ] ;
F_53 ( F_158 ( V_58 , V_265 ) ) ;
return 1 ;
}
static int T_6 F_159 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
V_194 . V_198 = V_196 -> V_58 ;
V_194 . V_228 = V_229 ;
if ( ! F_143 ( V_196 -> V_58 , NULL ) ) {
F_112 ( & V_194 , V_196 , L_60 ) ;
V_194 . V_164 = F_140 ;
V_194 . V_231 = F_142 ;
V_194 . V_232 = F_144 ;
if ( F_109 ( V_6 , & V_194 , V_55 ) < 0 )
return - V_53 ;
}
F_112 ( & V_194 , V_196 , L_61 ) ;
V_194 . V_164 = F_148 ;
V_194 . V_231 = F_149 ;
V_194 . V_232 = F_151 ;
if ( F_109 ( V_6 , & V_194 , V_55 ) < 0 )
return - V_53 ;
F_112 ( & V_194 , V_196 , L_62 ) ;
V_194 . V_164 = F_153 ;
V_194 . V_231 = F_155 ;
V_194 . V_232 = F_157 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_160 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_219 ;
V_214 -> V_220 = V_226 ;
V_214 -> V_221 . integer . F_48 = 0 ;
V_214 -> V_221 . integer . F_49 = 0x7FFFFFFF ;
return 0 ;
}
static int F_161 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
short V_225 [ V_226 ] , V_254 ;
T_2 V_42 ;
V_42 = F_162 ( V_58 , V_225 ) ;
for ( V_254 = 0 ; V_254 < V_226 ; V_254 ++ ) {
if ( V_42 ) {
V_224 -> V_221 . integer . V_221 [ V_254 ] = 0 ;
} else if ( V_225 [ V_254 ] >= 0 ) {
V_224 -> V_221 . integer . V_221 [ V_254 ] =
V_225 [ V_254 ] << 16 ;
} else {
V_224 -> V_221 . integer . V_221 [ V_254 ] =
V_266 [ V_225 [ V_254 ] / - 1000 ] ;
}
}
return 0 ;
}
static int T_6 F_163 ( struct V_54 * V_55 ,
struct V_195 * V_196 , int V_267 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_63 ) ;
V_194 . V_228 =
V_247 | V_248 ;
V_194 . V_164 = F_160 ;
V_194 . V_231 = F_161 ;
V_194 . V_193 = V_267 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_164 ( struct V_211 * V_194 )
{
T_3 V_58 = V_194 -> V_198 ;
struct V_195 V_196 ;
int V_107 , V_42 ;
for ( V_107 = 0 ; V_107 < 32 ; V_107 ++ ) {
V_42 = F_165 ( V_58 , V_107 ,
& V_196 .
V_201 ,
& V_196 .
V_208 ) ;
if ( V_42 )
break;
}
return V_107 ;
}
static int F_166 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
int V_42 ;
T_2 V_201 , V_208 ;
T_3 V_58 = V_212 -> V_198 ;
V_214 -> type = V_237 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . V_238 . V_239 =
F_164 ( V_212 ) ;
if ( V_214 -> V_221 . V_238 . V_240 >= V_214 -> V_221 . V_238 . V_239 )
V_214 -> V_221 . V_238 . V_240 =
V_214 -> V_221 . V_238 . V_239 - 1 ;
V_42 =
F_165 ( V_58 ,
V_214 -> V_221 . V_238 . V_240 ,
& V_201 , & V_208 ) ;
sprintf ( V_214 -> V_221 . V_238 . V_3 , L_64 ,
V_207 [ V_201 - V_202 ] ,
V_208 ) ;
return 0 ;
}
static int F_167 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_268 , V_269 ;
T_2 V_201 , V_208 ;
int V_107 ;
F_53 ( F_168 ( V_58 ,
& V_268 , & V_269 ) ) ;
for ( V_107 = 0 ; V_107 < 256 ; V_107 ++ ) {
if ( F_165 ( V_58 , V_107 ,
& V_201 , & V_208 ) )
break;
if ( ( V_268 == V_201 )
&& ( V_269 == V_208 ) ) {
V_224 -> V_221 . V_238 . V_240 [ 0 ] = V_107 ;
return 0 ;
}
}
F_30 ( V_44
L_65 ,
V_58 , V_268 , V_269 ) ;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = 0 ;
return 0 ;
}
static int F_169 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
int V_227 ;
T_3 V_58 = V_212 -> V_198 ;
T_2 V_268 , V_269 ;
T_2 V_38 ;
V_227 = 1 ;
V_38 = F_165 ( V_58 ,
V_224 -> V_221 . V_238 . V_240 [ 0 ] ,
& V_268 , & V_269 ) ;
if ( ! V_38 )
F_53 (
F_170 ( V_58 ,
V_268 , V_269 ) ) ;
return V_227 ;
}
static int T_6 F_171 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_66 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_166 ;
V_194 . V_231 = F_167 ;
V_194 . V_232 = F_169 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_172 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static const char * const V_270 [ V_271 + 1 ] = {
L_67 ,
L_68 , L_69 ,
L_70 , L_71 ,
L_72 , L_73
} ;
T_3 V_58 = V_212 -> V_198 ;
T_2 V_272 ;
int V_254 ;
T_2 V_273 [ 6 ] ;
int V_274 = 0 ;
for ( V_254 = 0 ; V_254 < V_271 ; V_254 ++ )
if ( ! F_173 (
V_58 , V_254 , & V_272 ) ) {
V_273 [ V_274 ] = V_272 ;
V_274 ++ ;
}
V_214 -> type = V_237 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . V_238 . V_239 = V_274 ;
if ( V_214 -> V_221 . V_238 . V_240 >= V_274 )
V_214 -> V_221 . V_238 . V_240 = V_274 - 1 ;
strcpy ( V_214 -> V_221 . V_238 . V_3 ,
V_270 [ V_273 [ V_214 -> V_221 . V_238 . V_240 ] ] ) ;
return 0 ;
}
static int F_174 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_2 V_272 ;
if ( F_175 ( V_58 , & V_272 ) )
V_272 = 1 ;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = V_272 - 1 ;
return 0 ;
}
static int F_176 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
int V_227 ;
T_3 V_58 = V_212 -> V_198 ;
V_227 = 1 ;
F_53 ( F_177 ( V_58 ,
V_224 -> V_221 . V_238 . V_240 [ 0 ] + 1 ) ) ;
return V_227 ;
}
static int T_6 F_178 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
F_112 ( & V_194 , V_196 , L_74 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_172 ;
V_194 . V_231 = F_174 ;
V_194 . V_232 = F_176 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int F_179 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_54 * V_55 =
(struct V_54 * ) ( V_212 -> V_90 ) ;
struct V_275 * V_276 = & V_55 -> V_277 ;
V_214 -> type = V_237 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . V_238 . V_239 = V_276 -> V_220 ;
if ( V_214 -> V_221 . V_238 . V_240 >= V_214 -> V_221 . V_238 . V_239 )
V_214 -> V_221 . V_238 . V_240 =
V_214 -> V_221 . V_238 . V_239 - 1 ;
strcpy ( V_214 -> V_221 . V_238 . V_3 ,
V_276 -> V_107 [ V_214 -> V_221 . V_238 . V_240 ] . V_3 ) ;
return 0 ;
}
static int F_180 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
struct V_54 * V_55 =
(struct V_54 * ) ( V_212 -> V_90 ) ;
struct V_275 * V_276 = & V_55 -> V_277 ;
T_3 V_58 = V_212 -> V_198 ;
T_2 V_242 , V_278 = 0 ;
int V_254 ;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = 0 ;
if ( F_181 ( V_58 , & V_242 ) )
V_242 = 0 ;
if ( V_242 == V_279 )
if ( F_182 ( V_58 , & V_278 ) )
V_278 = 0 ;
for ( V_254 = 0 ; V_254 < V_276 -> V_220 ; V_254 ++ )
if ( ( V_276 -> V_107 [ V_254 ] . V_242 == V_242 ) &&
( V_276 -> V_107 [ V_254 ] . V_193 == V_278 ) )
break;
V_224 -> V_221 . V_238 . V_240 [ 0 ] = V_254 ;
return 0 ;
}
static int F_183 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
struct V_54 * V_55 =
(struct V_54 * ) ( V_212 -> V_90 ) ;
struct V_275 * V_276 = & V_55 -> V_277 ;
int V_227 , V_240 ;
T_3 V_58 = V_212 -> V_198 ;
V_227 = 1 ;
V_240 = V_224 -> V_221 . V_238 . V_240 [ 0 ] ;
if ( V_240 >= V_276 -> V_220 )
V_240 = V_276 -> V_220 - 1 ;
F_53 ( F_184 (
V_58 , V_276 -> V_107 [ V_240 ] . V_242 ) ) ;
if ( V_276 -> V_107 [ V_240 ] . V_242 == V_279 )
F_53 ( F_185 (
V_58 , V_276 -> V_107 [ V_240 ] . V_193 ) ) ;
return V_227 ;
}
static int F_186 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_219 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . integer . F_48 = 8000 ;
V_214 -> V_221 . integer . F_49 = 192000 ;
V_214 -> V_221 . integer . V_222 = 100 ;
return 0 ;
}
static int F_187 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_3 V_280 ;
T_2 V_38 ;
V_38 = F_188 ( V_58 , & V_280 ) ;
if ( ! V_38 )
V_224 -> V_221 . integer . V_221 [ 0 ] = V_280 ;
else
V_224 -> V_221 . integer . V_221 [ 0 ] = 0 ;
return 0 ;
}
static int F_189 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
int V_227 ;
T_3 V_58 = V_212 -> V_198 ;
V_227 = 1 ;
F_53 ( F_190 ( V_58 ,
V_224 -> V_221 . integer . V_221 [ 0 ] ) ) ;
return V_227 ;
}
static int F_191 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_219 ;
V_214 -> V_220 = 1 ;
V_214 -> V_221 . integer . F_48 = 8000 ;
V_214 -> V_221 . integer . F_49 = 192000 ;
V_214 -> V_221 . integer . V_222 = 100 ;
return 0 ;
}
static int F_192 ( struct V_211 * V_212 ,
struct V_223 * V_224 )
{
T_3 V_58 = V_212 -> V_198 ;
T_3 V_280 ;
T_2 V_38 ;
V_38 = F_46 ( V_58 , & V_280 ) ;
if ( ! V_38 )
V_224 -> V_221 . integer . V_221 [ 0 ] = V_280 ;
else
V_224 -> V_221 . integer . V_221 [ 0 ] = 0 ;
return 0 ;
}
static int T_6 F_193 ( struct V_54 * V_55 ,
struct V_195 * V_196 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
struct V_190 V_194 ;
struct V_275 * V_276 = & V_55 -> V_277 ;
T_3 V_281 = V_196 -> V_58 ;
int V_282 = 0 ;
int V_254 , V_283 ;
T_2 V_242 ;
V_194 . V_198 = V_196 -> V_58 ;
V_276 -> V_284 = 0 ;
for ( V_254 = 0 ; V_254 <= V_285 ; V_254 ++ ) {
if ( F_194 ( V_281 ,
V_254 , & V_242 ) )
break;
V_276 -> V_107 [ V_254 ] . V_242 = V_242 ;
V_276 -> V_107 [ V_254 ] . V_193 = 0 ;
V_276 -> V_107 [ V_254 ] . V_3 = V_286 [ V_242 ] ;
if ( V_242 == V_279 )
V_282 = 1 ;
if ( V_242 == V_287 )
V_276 -> V_284 = 1 ;
}
if ( V_282 )
for ( V_283 = 1 ; V_283 < 8 ; V_283 ++ ) {
if ( F_195 ( V_281 ,
V_283 , V_279 ,
& V_242 ) )
break;
V_276 -> V_107 [ V_254 ] . V_242 =
V_279 ;
V_276 -> V_107 [ V_254 ] . V_193 = V_283 ;
V_276 -> V_107 [ V_254 ] . V_3 = V_286 [
V_283 + V_285 ] ;
V_254 ++ ;
}
V_276 -> V_220 = V_254 ;
F_112 ( & V_194 , V_196 , L_75 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_179 ;
V_194 . V_231 = F_180 ;
V_194 . V_232 = F_183 ;
if ( F_109 ( V_6 , & V_194 , V_55 ) < 0 )
return - V_53 ;
if ( V_276 -> V_284 ) {
F_112 ( & V_194 , V_196 , L_76 ) ;
V_194 . V_228 = V_229 ;
V_194 . V_164 = F_186 ;
V_194 . V_231 = F_187 ;
V_194 . V_232 = F_189 ;
if ( F_109 ( V_6 , & V_194 , V_55 ) < 0 )
return - V_53 ;
}
F_112 ( & V_194 , V_196 , L_77 ) ;
V_194 . V_228 =
V_247 | V_248 ;
V_194 . V_164 = F_191 ;
V_194 . V_231 = F_192 ;
return F_109 ( V_6 , & V_194 , V_55 ) ;
}
static int T_6 F_196 ( struct V_54 * V_55 )
{
struct V_189 * V_6 = V_55 -> V_6 ;
unsigned int V_60 = 0 ;
unsigned int V_288 = 0 ;
int V_42 ;
struct V_195 V_196 , V_289 ;
if ( F_197 ( ! V_55 ) )
return - V_53 ;
strcpy ( V_6 -> V_290 , L_78 ) ;
V_42 =
F_198 ( V_55 -> V_22 ,
& V_55 -> V_67 ) ;
F_53 ( V_42 ) ;
if ( V_42 )
return - V_42 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
V_289 . V_291 = - 1 ;
for ( V_60 = 0 ; V_60 < 2000 ; V_60 ++ ) {
V_42 = F_199 (
V_55 -> V_67 ,
V_60 ,
& V_196 . V_201 ,
& V_196 . V_208 ,
& V_196 . V_203 ,
& V_196 . V_210 ,
& V_196 . V_291 ,
& V_196 . V_58 ) ;
if ( V_42 ) {
if ( V_42 == V_292 ) {
if ( V_192 )
F_45 ( V_152
L_79 ,
V_60 ) ;
continue;
} else
break;
}
V_196 . V_201 -= V_202 ;
V_196 . V_203 -= V_204 ;
if ( ( V_196 . V_291 == V_289 . V_291 ) &&
( V_196 . V_201 == V_289 . V_201 ) &&
( V_196 . V_208 == V_289 . V_208 ) &&
( V_196 . V_203 == V_289 . V_203 ) &&
( V_196 . V_210 == V_289 . V_210 ) )
V_288 ++ ;
else
V_288 = 0 ;
V_289 = V_196 ;
switch ( V_196 . V_291 ) {
case V_293 :
V_42 = F_119 ( V_55 , & V_196 ) ;
break;
case V_294 :
V_42 = F_126 ( V_55 , & V_196 ) ;
break;
case V_295 :
V_42 = F_171 ( V_55 , & V_196 ) ;
break;
case V_296 :
V_42 = F_178 ( V_55 , & V_196 ) ;
break;
case V_297 :
V_42 = F_163 ( V_55 , & V_196 , V_288 ) ;
break;
case V_69 :
V_42 = F_193 (
V_55 , & V_196 ) ;
break;
case V_298 :
continue;
case V_299 :
V_42 = F_159 ( V_55 , & V_196 ) ;
break;
case V_300 :
V_42 = F_139 ( V_55 , & V_196 ) ;
break;
case V_301 :
V_42 = F_136 ( V_55 , & V_196 ) ;
break;
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
default:
if ( V_192 )
F_45 ( V_152
L_80
L_81 ,
V_60 ,
V_196 . V_291 ,
V_196 . V_201 ,
V_196 . V_208 ,
V_196 . V_203 ,
V_196 . V_210 ) ;
continue;
} ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_255 != V_42 )
F_53 ( V_42 ) ;
F_45 ( V_152 L_82 , V_60 ) ;
return 0 ;
}
static void
F_200 ( struct V_307 * V_308 ,
struct V_309 * V_26 )
{
struct V_54 * V_55 = V_308 -> V_90 ;
T_2 V_310 ;
T_3 V_58 ;
T_3 V_280 = 0 ;
T_2 V_242 = 0 ;
int V_42 ;
F_201 ( V_26 , L_83 ) ;
F_201 ( V_26 ,
L_84
L_85 ,
V_55 -> type , V_55 -> V_22 ,
V_55 -> V_181 , V_55 -> V_182 ) ;
V_310 = V_55 -> V_310 ;
F_201 ( V_26 ,
L_86 ,
V_55 -> V_311 , ( ( V_310 >> 3 ) & 0xf ) + 'A' ,
V_310 & 0x7 ,
( ( V_310 >> 13 ) * 100 ) + ( ( V_310 >> 7 ) & 0x3f ) ) ;
V_42 = F_44 ( V_55 -> V_67 ,
V_68 , 0 , 0 , 0 ,
V_69 , & V_58 ) ;
if ( ! V_42 ) {
V_42 = F_46 (
V_58 , & V_280 ) ;
V_42 += F_181 ( V_58 , & V_242 ) ;
if ( ! V_42 )
F_201 ( V_26 , L_87 ,
V_280 , V_286 [ V_242 ] ) ;
}
}
static void T_6 F_202 ( struct V_54 * V_55 )
{
struct V_307 * V_308 ;
if ( ! F_203 ( V_55 -> V_6 , L_88 , & V_308 ) )
F_204 ( V_308 , V_55 , F_200 ) ;
}
static int F_205 ( struct V_312 * V_173 , struct V_313 * V_313 )
{
if ( V_314 )
return 0 ;
else
return - V_315 ;
}
static int F_206 ( struct V_312 * V_173 , struct V_313 * V_313 )
{
if ( V_314 )
return F_207 ( V_313 ) ;
else
return - V_315 ;
}
static int F_208 ( struct V_312 * V_173 , struct V_313 * V_313 ,
unsigned int V_106 , unsigned long V_151 )
{
if ( V_314 )
return F_209 ( V_313 , V_106 , V_151 ) ;
else
return - V_315 ;
}
static int T_6 F_210 ( struct V_54 * V_55 ,
int V_8 , struct V_312 * * V_316 )
{
struct V_312 * V_173 ;
int V_42 ;
if ( V_316 )
* V_316 = NULL ;
V_42 = F_211 ( V_55 -> V_6 , L_89 , V_8 , & V_173 ) ;
if ( V_42 < 0 )
return V_42 ;
strcpy ( V_173 -> V_3 , L_90 ) ;
V_173 -> V_199 = V_317 ;
V_173 -> V_318 . V_319 = F_205 ;
V_173 -> V_318 . V_320 = F_208 ;
V_173 -> V_318 . V_321 = F_206 ;
V_173 -> V_90 = V_55 ;
if ( V_316 )
* V_316 = V_173 ;
return 0 ;
}
static int T_6 F_212 ( struct V_322 * V_322 ,
const struct V_323 * V_324 )
{
int V_42 ;
T_2 V_310 ;
int V_325 ;
struct V_326 * V_327 ;
struct V_189 * V_6 ;
struct V_54 * V_55 ;
T_3 V_58 ;
T_3 V_10 ;
static int V_328 ;
if ( V_328 >= V_329 )
return - V_315 ;
if ( ! V_330 [ V_328 ] ) {
V_328 ++ ;
return - V_331 ;
}
V_42 = F_213 ( V_322 , V_324 ) ;
if ( V_42 < 0 )
return V_42 ;
V_327 = F_214 ( V_322 ) ;
V_42 = F_215 ( V_327 -> V_193 ,
V_332 [ V_327 -> V_193 ] , V_333 ,
sizeof( struct V_54 ) ,
& V_6 ) ;
if ( V_42 < 0 ) {
V_42 =
F_215 ( V_193 [ V_328 ] , V_332 [ V_328 ] ,
V_333 ,
sizeof( struct V_54 ) ,
& V_6 ) ;
if ( V_42 < 0 )
return V_42 ;
F_45 ( V_44
L_91 ,
V_327 -> V_193 , V_6 -> V_7 ) ;
}
F_216 ( V_6 , & V_322 -> V_328 ) ;
V_55 = (struct V_54 * ) V_6 -> V_90 ;
V_55 -> V_6 = V_6 ;
V_55 -> V_187 = V_322 ;
V_55 -> V_22 = V_327 -> V_193 ;
F_53 ( F_217 (
V_55 -> V_22 ,
& V_55 -> V_181 ,
& V_55 -> V_182 ,
& V_55 -> V_310 ,
& V_55 -> V_311 , & V_55 -> type ) ) ;
V_310 = V_55 -> V_310 ;
F_45 ( V_152 L_92
L_93
L_94 ,
V_55 -> type , V_55 -> V_22 ,
V_55 -> V_181 ,
V_55 -> V_182 , V_55 -> V_311 ,
( ( V_310 >> 3 ) & 0xf ) + 'A' ,
V_310 & 0x7 ,
( ( V_310 >> 13 ) * 100 ) + ( ( V_310 >> 7 ) & 0x3f ) ) ;
V_325 = V_55 -> V_181 ;
if ( V_325 < V_55 -> V_182 )
V_325 = V_55 -> V_182 ;
V_42 = F_218 ( V_55 -> V_22 ,
V_334 ,
NULL , & V_55 -> V_115 ) ;
if ( V_42 )
V_55 -> V_115 = 0 ;
V_42 = F_218 ( V_55 -> V_22 ,
V_335 ,
& V_55 -> V_64 , NULL ) ;
if ( V_42 )
V_55 -> V_64 = 0 ;
V_42 = F_218 ( V_55 -> V_22 ,
V_336 ,
NULL , & V_55 -> V_176 ) ;
if ( V_42 )
V_55 -> V_176 = 512 ;
if ( ! V_55 -> V_95 )
V_55 -> V_176 *= 2 ;
F_53 ( F_101 ( V_55 -> V_22 ,
0 , & V_10 ) ) ;
V_42 = F_219 ( V_10 ) ;
V_55 -> V_95 = ( ! V_42 ) ;
F_53 ( F_103 ( V_10 ) ) ;
V_42 = F_218 ( V_55 -> V_22 ,
V_337 ,
& V_55 -> V_178 , & V_55 -> V_163 ) ;
if ( V_42 ) {
V_55 -> V_178 = 2 ;
V_55 -> V_163 = 2 ;
}
F_45 ( V_152 L_95 ,
V_55 -> V_95 ,
V_55 -> V_115 ,
V_55 -> V_64
) ;
V_42 = F_104 ( V_55 , 0 , V_325 ) ;
if ( V_42 < 0 ) {
F_45 ( V_70 L_96 ) ;
goto V_338;
}
V_42 = F_196 ( V_55 ) ;
if ( V_42 < 0 ) {
F_45 ( V_70 L_97 ) ;
goto V_338;
}
V_42 = F_44 ( V_55 -> V_67 ,
V_68 , 0 , 0 , 0 ,
V_69 , & V_58 ) ;
if ( ! V_42 )
V_42 = F_190 (
V_58 , V_339 ) ;
F_202 ( V_55 ) ;
F_210 ( V_55 , 0 , NULL ) ;
strcpy ( V_6 -> V_340 , L_98 ) ;
sprintf ( V_6 -> V_341 , L_99 , V_55 -> type ) ;
sprintf ( V_6 -> V_342 , L_100 ,
V_6 -> V_341 , V_55 -> V_22 ) ;
V_42 = F_220 ( V_6 ) ;
if ( ! V_42 ) {
V_327 -> V_54 = V_6 ;
V_328 ++ ;
return 0 ;
}
V_338:
F_221 ( V_6 ) ;
F_45 ( V_70 L_101 , V_42 ) ;
return V_42 ;
}
static void T_7 F_222 ( struct V_322 * V_322 )
{
struct V_326 * V_327 = F_214 ( V_322 ) ;
F_221 ( V_327 -> V_54 ) ;
V_327 -> V_54 = NULL ;
F_223 ( V_322 ) ;
}
static int T_8 F_224 ( void )
{
F_225 () ;
return F_226 ( & V_340 ) ;
}
static void T_9 F_227 ( void )
{
F_228 ( & V_340 ) ;
F_229 () ;
}
