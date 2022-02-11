static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long * V_4 = F_2 ( V_3 -> V_5 ) ;
return (struct V_1 * ) * V_4 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
unsigned long * V_4 = F_2 ( V_7 ) ;
return (struct V_1 * ) * V_4 ;
}
static inline bool F_4 ( struct V_8 * V_9 )
{
return V_9 -> V_10 == V_11 ;
}
static inline bool F_5 ( struct V_8 * V_9 )
{
return V_9 -> V_12 || V_9 -> V_13 ;
}
static void F_6 ( const T_1 * V_14 , int V_15 ,
T_1 * V_16 , T_1 * V_17 , T_1 * V_18 )
{
struct V_19 V_20 ;
bool V_21 ;
* V_16 = - 1 ;
* V_17 = - 1 ;
* V_18 = - 1 ;
if ( V_15 < 1 )
return;
V_21 = F_7 ( V_14 , V_15 , & V_20 ) ;
if ( V_21 ) {
* V_16 = V_20 . V_16 ;
* V_17 = V_20 . V_17 ;
* V_18 = V_20 . V_18 ;
}
}
static int F_8 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_9 -> V_24 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_16 != V_27 || V_17 == 0xff )
return 0 ;
switch ( V_17 ) {
case V_28 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_1 ,
V_22 -> V_31 ) ;
break;
case V_32 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_2 , V_22 -> V_31 ) ;
break;
case V_33 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_3 , V_22 -> V_31 ) ;
break;
case V_34 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_4 ,
V_22 -> V_31 ) ;
break;
case V_35 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_5 ,
V_22 -> V_31 ) ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_6 ,
V_22 -> V_31 ) ;
break;
}
return 1 ;
}
static int F_10 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 != V_37 ||
( V_9 -> V_24 -> V_38 != V_39 &&
V_9 -> V_24 -> V_38 != V_40 ) )
return 0 ;
F_9 ( & V_22 -> V_29 -> V_30 , V_41 L_7 ) ;
return 1 ;
}
static T_2 F_11 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
int V_46 ;
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
V_46 = F_13 ( V_22 ) ;
return sprintf ( V_45 , L_8 , V_46 ) ;
}
static T_2 F_14 ( struct V_42 * V_30 ,
struct V_43 * V_44 ,
const char * V_45 , T_3 V_48 )
{
int V_49 , V_50 ;
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
char V_51 [ 10 ] ;
if ( ! F_15 ( V_52 ) || ! F_15 ( V_53 ) )
return - V_54 ;
V_50 = V_48 > sizeof( V_51 ) - 1 ? sizeof( V_51 ) - 1 : V_48 ;
strncpy ( V_51 , V_45 , V_50 ) ;
V_51 [ V_50 ] = '\0' ;
if ( sscanf ( V_51 , L_9 , & V_49 ) != 1 )
return - V_55 ;
V_22 = F_3 ( V_47 ) ;
V_22 -> V_56 = ! ! V_49 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_10 ,
V_22 -> V_56 ? L_11 : L_12 ) ;
return V_48 ;
}
static T_2 F_16 ( struct V_42 * V_30 ,
struct V_43 * V_44 ,
const char * V_45 , T_3 V_48 )
{
int V_57 , V_50 ;
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
char V_51 [ 10 ] ;
if ( ! F_15 ( V_52 ) || ! F_15 ( V_53 ) )
return - V_54 ;
V_50 = V_48 > sizeof( V_51 ) - 1 ? sizeof( V_51 ) - 1 : V_48 ;
strncpy ( V_51 , V_45 , V_50 ) ;
V_51 [ V_50 ] = '\0' ;
if ( sscanf ( V_51 , L_9 , & V_57 ) != 1 )
return - V_55 ;
if ( V_57 < 0 )
V_57 = 0 ;
V_22 = F_3 ( V_47 ) ;
V_22 -> V_58 = V_57 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_13 ,
V_22 -> V_58 ) ;
return V_48 ;
}
static T_2 F_17 ( struct V_42 * V_30 ,
struct V_43 * V_44 ,
const char * V_45 , T_3 V_48 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
F_18 ( V_22 -> V_59 ) ;
return V_48 ;
}
static T_2 F_19 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
unsigned char * V_60 ;
V_22 = F_3 ( V_47 ) ;
if ( ! V_22 -> V_61 )
return 0 ;
V_60 = & V_22 -> V_61 [ 32 ] ;
return snprintf ( V_45 , 20 , L_14 ,
V_60 [ 0 ] , V_60 [ 1 ] , V_60 [ 2 ] , V_60 [ 3 ] ) ;
}
static T_2 F_20 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_6 * V_47 = F_12 ( V_30 ) ;
struct V_1 * V_22 = F_3 ( V_47 ) ;
return snprintf ( V_45 , 20 , L_15 ,
F_21 ( & V_22 -> V_62 ) ) ;
}
static T_2 F_22 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
return snprintf ( V_45 , 20 , L_16 ,
V_22 -> V_63 & V_64 ?
L_17 : L_18 ) ;
}
static T_2 F_23 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
return snprintf ( V_45 , 30 , L_19 ,
( V_22 -> V_56 == 1 ) ? L_11 : L_12 ) ;
}
static int F_24 ( T_4 V_65 [] , int V_66 , T_4 V_67 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ )
if ( V_65 [ V_68 ] == V_67 )
return 1 ;
return 0 ;
}
static int F_25 ( T_4 V_67 )
{
return ! F_24 ( V_69 ,
F_26 ( V_69 ) , V_67 ) ;
}
static int F_27 ( T_4 V_67 )
{
return ! F_24 ( V_70 ,
F_26 ( V_70 ) , V_67 ) ;
}
static int F_28 ( T_4 V_67 )
{
return F_25 ( V_67 ) ||
F_27 ( V_67 ) ;
}
static int F_29 ( T_4 V_67 )
{
return F_24 ( V_71 ,
F_26 ( V_71 ) , V_67 ) ;
}
static T_2 F_30 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
return snprintf ( V_45 , 20 , L_15 , F_28 ( V_22 -> V_67 ) ) ;
}
static inline int F_31 ( unsigned char V_72 [] )
{
return ( V_72 [ 3 ] & 0xC0 ) == 0x40 ;
}
static inline bool F_32 ( struct V_73 * V_42 )
{
return ! V_42 -> V_74 ;
}
static T_2 F_33 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
T_2 V_75 = 0 ;
unsigned char V_76 ;
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
if ( ! F_32 ( V_77 ) ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
V_75 = snprintf ( V_45 , V_82 , L_20 ) ;
return V_75 ;
}
V_76 = V_77 -> V_83 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_76 > V_84 )
V_76 = V_84 ;
V_75 = snprintf ( V_45 , V_82 , L_21 , V_85 [ V_76 ] ) ;
return V_75 ;
}
static T_2 F_37 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
unsigned char V_86 [ 8 ] ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
memcpy ( V_86 , V_77 -> V_72 , sizeof( V_86 ) ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
return snprintf ( V_45 , 20 , L_22 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] , V_86 [ 3 ] ,
V_86 [ 4 ] , V_86 [ 5 ] , V_86 [ 6 ] , V_86 [ 7 ] ) ;
}
static T_2 F_38 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
unsigned char V_87 [ 16 ] ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
memcpy ( V_87 , V_77 -> V_88 , sizeof( V_87 ) ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
return snprintf ( V_45 , 16 * 2 + 2 ,
L_23
L_24 ,
V_87 [ 0 ] , V_87 [ 1 ] , V_87 [ 2 ] , V_87 [ 3 ] ,
V_87 [ 4 ] , V_87 [ 5 ] , V_87 [ 6 ] , V_87 [ 7 ] ,
V_87 [ 8 ] , V_87 [ 9 ] , V_87 [ 10 ] , V_87 [ 11 ] ,
V_87 [ 12 ] , V_87 [ 13 ] , V_87 [ 14 ] , V_87 [ 15 ] ) ;
}
static T_2 F_39 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
int V_89 ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
V_89 = V_77 -> V_89 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
return snprintf ( V_45 , 20 , L_15 , V_89 ) ;
}
static T_2 F_40 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
int V_68 ;
int V_90 = 0 ;
T_1 V_91 ;
T_1 V_92 ;
T_1 V_93 = 0 ;
char * V_94 ;
unsigned char V_95 [ 2 ] ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_96 , V_78 ) ;
return - V_81 ;
}
V_92 = V_77 -> V_92 ;
for ( V_68 = 0 ; V_68 < V_97 ; V_68 ++ ) {
V_93 = 1 << V_68 ;
if ( V_68 == V_77 -> V_98 )
V_94 = L_25 ;
else if ( V_77 -> V_99 & V_93 )
V_94 = L_26 ;
else
continue;
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 ,
L_27 ,
V_22 -> V_59 -> V_100 ,
V_77 -> V_101 , V_77 -> V_102 , V_77 -> V_103 ,
F_42 ( V_77 -> V_104 ) ) ;
if ( V_77 -> V_104 == V_105 || F_32 ( V_77 ) ) {
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 ,
L_16 , V_94 ) ;
continue;
}
V_91 = V_77 -> V_91 [ V_68 ] ;
memcpy ( & V_95 , & V_77 -> V_95 [ V_68 ] ,
sizeof( V_95 ) ) ;
if ( V_95 [ 0 ] < '0' )
V_95 [ 0 ] = '0' ;
if ( V_95 [ 1 ] < '0' )
V_95 [ 1 ] = '0' ;
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 ,
L_28 ,
V_95 ) ;
if ( V_77 -> V_104 == V_106 && V_77 -> V_107 ) {
if ( V_91 == 0 || V_91 == 0xFF ) {
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 ,
L_29 ,
V_92 , V_94 ) ;
} else {
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 ,
L_30 ,
V_91 , V_92 , V_94 ) ;
}
} else if ( V_91 != 0 && V_91 != 0xFF ) {
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 , L_31 ,
V_91 , V_94 ) ;
} else
V_90 += F_41 ( V_45 + V_90 ,
V_82 - V_90 , L_16 , V_94 ) ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
return V_90 ;
}
static inline T_4 F_43 ( struct V_1 * V_22 , T_1 V_108 )
{
T_4 V_65 ;
struct V_109 * V_110 = & V_22 -> V_111 [ V_108 ] ;
if ( V_22 -> V_63 & V_112 )
return V_22 -> V_113 . V_114 ( V_22 , V_108 ) ;
if ( F_44 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_113 . V_114 ( V_22 , V_108 ) ;
if ( ( V_110 -> V_115 [ V_110 -> V_116 ] & 1 ) == V_110 -> V_117 ) {
V_65 = V_110 -> V_115 [ V_110 -> V_116 ] ;
V_110 -> V_116 ++ ;
F_45 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_118 ;
}
if ( V_110 -> V_116 == V_22 -> V_119 ) {
V_110 -> V_116 = 0 ;
V_110 -> V_117 ^= 1 ;
}
return V_65 ;
}
static void F_46 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_111 )
{
if ( F_47 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_120 |= 1 | ( V_22 -> V_121 [ V_9 -> V_122 . V_123 ] << 1 ) ;
if ( F_44 ( ! V_22 -> V_124 ) )
return;
if ( F_47 ( V_111 == V_125 ) )
V_9 -> V_122 . V_126 =
F_48 () % V_22 -> V_127 ;
else
V_9 -> V_122 . V_126 = V_111 % V_22 -> V_127 ;
}
}
static void F_49 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_111 )
{
struct V_128 * V_129 = & V_22 -> V_130 [ V_9 -> V_131 ] ;
if ( F_47 ( V_111 == V_125 ) )
V_129 -> V_126 = F_50 () % V_22 -> V_127 ;
else
V_129 -> V_126 = V_111 % V_22 -> V_127 ;
V_9 -> V_120 |= 1 | ( V_22 -> V_132 [ V_9 -> V_122 . V_123 ] << 1 ) |
V_133 ;
}
static void F_51 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_111 )
{
struct V_134 * V_129 = (struct V_134 * )
& V_22 -> V_135 [ V_9 -> V_131 ] ;
if ( F_47 ( V_111 == V_125 ) )
V_129 -> V_111 = F_50 () % V_22 -> V_127 ;
else
V_129 -> V_111 = V_111 % V_22 -> V_127 ;
V_9 -> V_120 |= V_22 -> V_136 [ 0 ] ;
}
static void F_52 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_111 )
{
struct V_137 * V_129 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
if ( F_47 ( V_111 == V_125 ) )
V_129 -> V_111 = F_50 () % V_22 -> V_127 ;
else
V_129 -> V_111 = V_111 % V_22 -> V_127 ;
V_9 -> V_120 |= ( V_22 -> V_136 [ V_129 -> V_138 ] ) ;
}
static int F_53 ( T_1 * V_139 )
{
return V_139 [ 0 ] == V_140 && V_139 [ 6 ] == V_141 ;
}
static void F_54 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_53 ( V_9 -> V_142 . V_143 ) )
return;
F_55 ( & V_22 -> V_144 ) ;
V_22 -> V_145 = V_146 ;
}
static void F_56 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_53 ( V_9 -> V_142 . V_143 ) &&
F_57 ( & V_22 -> V_144 ) )
V_22 -> V_145 = V_147 ;
}
static void F_58 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_111 )
{
F_54 ( V_22 , V_9 ) ;
F_55 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_148 ) {
case V_149 :
F_49 ( V_22 , V_9 , V_111 ) ;
F_59 ( V_9 -> V_120 , V_22 -> V_150 + V_151 ) ;
break;
case V_152 :
F_52 ( V_22 , V_9 , V_111 ) ;
F_59 ( V_9 -> V_120 , V_22 -> V_150 + V_153 ) ;
break;
case V_154 :
F_51 ( V_22 , V_9 , V_111 ) ;
F_59 ( V_9 -> V_120 , V_22 -> V_150 + V_153 ) ;
break;
default:
F_46 ( V_22 , V_9 , V_111 ) ;
V_22 -> V_113 . V_155 ( V_22 , V_9 ) ;
}
}
static void F_60 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_44 ( F_5 ( V_9 ) ) )
return F_61 ( V_9 ) ;
F_58 ( V_22 , V_9 , V_125 ) ;
}
static inline int F_62 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_156 , 8 ) == 0 ;
}
static inline int F_63 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_61 )
return 0 ;
if ( ( V_22 -> V_61 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_22 ,
unsigned char V_72 [] , int V_101 , int * V_102 , int * V_103 )
{
int V_68 , V_157 = 0 ;
F_65 ( V_158 , V_159 ) ;
F_66 ( V_158 , V_159 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_101 == V_101 && V_22 -> V_30 [ V_68 ] -> V_102 != - 1 )
F_67 ( V_22 -> V_30 [ V_68 ] -> V_102 , V_158 ) ;
}
V_68 = F_68 ( V_158 , V_159 ) ;
if ( V_68 < V_159 ) {
* V_102 = V_68 ;
* V_103 = 0 ;
V_157 = 1 ;
}
return ! V_157 ;
}
static void F_69 ( const char * V_161 , struct V_1 * V_22 ,
struct V_73 * V_30 , char * V_162 )
{
#define F_70 25
char V_163 [ F_70 ] ;
if ( V_22 == NULL || V_22 -> V_29 == NULL || V_22 -> V_59 == NULL )
return;
switch ( V_30 -> V_104 ) {
case V_105 :
snprintf ( V_163 , F_70 , L_32 ) ;
break;
case V_164 :
snprintf ( V_163 , F_70 , L_33 ) ;
break;
case V_106 :
if ( V_30 -> V_165 )
snprintf ( V_163 , F_70 , L_34 ) ;
else if ( ! F_31 ( V_30 -> V_72 ) )
snprintf ( V_163 , F_70 , L_35 ,
V_85 [ V_166 ] ) ;
else
snprintf ( V_163 , F_70 , L_36 ,
V_30 -> V_83 > V_84 ? L_37 :
V_85 [ V_30 -> V_83 ] ) ;
break;
case V_167 :
snprintf ( V_163 , F_70 , L_38 ) ;
break;
case V_168 :
snprintf ( V_163 , F_70 , L_39 ) ;
break;
case V_169 :
snprintf ( V_163 , F_70 , L_40 ) ;
break;
default:
snprintf ( V_163 , F_70 , L_41 ) ;
break;
}
F_71 ( V_161 , & V_22 -> V_29 -> V_30 ,
L_42 ,
V_22 -> V_59 -> V_100 , V_30 -> V_101 , V_30 -> V_102 , V_30 -> V_103 ,
V_162 ,
F_42 ( V_30 -> V_104 ) ,
V_30 -> V_170 ,
V_30 -> V_171 ,
V_163 ,
V_30 -> V_172 ? '+' : '-' ,
V_30 -> V_89 ? '+' : '-' ,
V_30 -> V_107 ) ;
}
static int F_72 ( struct V_1 * V_22 ,
struct V_73 * V_42 ,
struct V_73 * V_173 [] , int * V_174 )
{
int V_175 = V_22 -> V_160 ;
int V_68 ;
unsigned char V_176 [ 8 ] , V_177 [ 8 ] ;
struct V_73 * V_178 ;
if ( V_175 >= V_159 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_43
L_44 ) ;
return - 1 ;
}
if ( V_42 -> V_103 != - 1 )
goto V_179;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_64 ( V_22 , V_42 -> V_72 ,
V_42 -> V_101 , & V_42 -> V_102 , & V_42 -> V_103 ) != 0 )
return - 1 ;
goto V_179;
}
memcpy ( V_176 , V_42 -> V_72 , 8 ) ;
V_176 [ 4 ] = 0 ;
V_176 [ 5 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_175 ; V_68 ++ ) {
V_178 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_177 , V_178 -> V_72 , 8 ) ;
V_177 [ 4 ] = 0 ;
V_177 [ 5 ] = 0 ;
if ( memcmp ( V_176 , V_177 , 8 ) == 0 ) {
V_42 -> V_101 = V_178 -> V_101 ;
V_42 -> V_102 = V_178 -> V_102 ;
V_42 -> V_103 = V_42 -> V_72 [ 4 ] ;
break;
}
}
if ( V_42 -> V_103 == - 1 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_45
L_46
L_47 ) ;
return - 1 ;
}
V_179:
V_22 -> V_30 [ V_175 ] = V_42 ;
V_22 -> V_160 ++ ;
V_173 [ * V_174 ] = V_42 ;
( * V_174 ) ++ ;
F_69 ( V_180 , V_22 , V_42 ,
V_42 -> V_107 ? L_48 : L_49 ) ;
V_42 -> V_181 = V_42 -> V_89 ;
V_42 -> V_89 = 0 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_22 ,
int V_182 , struct V_73 * V_183 )
{
int V_89 ;
F_75 ( V_182 < 0 || V_182 >= V_159 ) ;
V_22 -> V_30 [ V_182 ] -> V_83 = V_183 -> V_83 ;
if ( V_183 -> V_172 && V_183 -> V_89 ) {
V_22 -> V_30 [ V_182 ] -> V_184 = V_183 -> V_184 ;
V_22 -> V_30 [ V_182 ] -> V_185 = V_183 -> V_185 ;
}
if ( V_183 -> V_186 ) {
V_22 -> V_30 [ V_182 ] -> V_185 = V_183 -> V_185 ;
F_76 () ;
}
V_22 -> V_30 [ V_182 ] -> V_186 = V_183 -> V_186 ;
V_22 -> V_30 [ V_182 ] -> V_172 = V_183 -> V_172 ;
V_22 -> V_30 [ V_182 ] -> V_187 = V_183 -> V_187 ;
V_22 -> V_30 [ V_182 ] -> V_188 = V_183 -> V_188 ;
V_22 -> V_30 [ V_182 ] -> V_181 = V_183 -> V_89 ;
if ( ! V_183 -> V_89 )
V_22 -> V_30 [ V_182 ] -> V_89 = 0 ;
V_89 = V_22 -> V_30 [ V_182 ] -> V_89 ;
V_22 -> V_30 [ V_182 ] -> V_89 = V_22 -> V_30 [ V_182 ] -> V_181 ;
F_69 ( V_180 , V_22 , V_22 -> V_30 [ V_182 ] , L_50 ) ;
V_22 -> V_30 [ V_182 ] -> V_89 = V_89 ;
}
static void F_77 ( struct V_1 * V_22 ,
int V_182 , struct V_73 * V_183 ,
struct V_73 * V_173 [] , int * V_174 ,
struct V_73 * V_189 [] , int * V_190 )
{
F_75 ( V_182 < 0 || V_182 >= V_159 ) ;
V_189 [ * V_190 ] = V_22 -> V_30 [ V_182 ] ;
( * V_190 ) ++ ;
if ( V_183 -> V_102 == - 1 ) {
V_183 -> V_102 = V_22 -> V_30 [ V_182 ] -> V_102 ;
V_183 -> V_103 = V_22 -> V_30 [ V_182 ] -> V_103 ;
}
V_22 -> V_30 [ V_182 ] = V_183 ;
V_173 [ * V_174 ] = V_183 ;
( * V_174 ) ++ ;
F_69 ( V_180 , V_22 , V_183 , L_51 ) ;
V_183 -> V_181 = V_183 -> V_89 ;
V_183 -> V_89 = 0 ;
}
static void F_78 ( struct V_1 * V_22 , int V_182 ,
struct V_73 * V_189 [] , int * V_190 )
{
int V_68 ;
struct V_73 * V_178 ;
F_75 ( V_182 < 0 || V_182 >= V_159 ) ;
V_178 = V_22 -> V_30 [ V_182 ] ;
V_189 [ * V_190 ] = V_22 -> V_30 [ V_182 ] ;
( * V_190 ) ++ ;
for ( V_68 = V_182 ; V_68 < V_22 -> V_160 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_160 -- ;
F_69 ( V_180 , V_22 , V_178 , L_52 ) ;
}
static void F_79 ( struct V_1 * V_22 ,
struct V_73 * V_173 )
{
unsigned long V_78 ;
int V_68 , V_191 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_173 ) {
for ( V_191 = V_68 ; V_191 < V_22 -> V_160 - 1 ; V_191 ++ )
V_22 -> V_30 [ V_191 ] = V_22 -> V_30 [ V_191 + 1 ] ;
V_22 -> V_160 -- ;
break;
}
}
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_80 ( V_173 ) ;
}
static inline int F_81 ( struct V_73 * V_192 ,
struct V_73 * V_193 )
{
if ( memcmp ( V_192 -> V_72 , V_193 -> V_72 ,
sizeof( V_192 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_192 -> V_88 , V_193 -> V_88 ,
sizeof( V_192 -> V_88 ) ) != 0 )
return 0 ;
if ( memcmp ( V_192 -> V_171 , V_193 -> V_171 , sizeof( V_192 -> V_171 ) ) != 0 )
return 0 ;
if ( memcmp ( V_192 -> V_170 , V_193 -> V_170 , sizeof( V_192 -> V_170 ) ) != 0 )
return 0 ;
if ( V_192 -> V_104 != V_193 -> V_104 )
return 0 ;
if ( V_192 -> V_101 != V_193 -> V_101 )
return 0 ;
return 1 ;
}
static inline int F_82 ( struct V_73 * V_192 ,
struct V_73 * V_193 )
{
if ( V_192 -> V_83 != V_193 -> V_83 )
return 1 ;
if ( V_192 -> V_172 != V_193 -> V_172 )
return 1 ;
if ( V_192 -> V_89 != V_193 -> V_89 )
return 1 ;
if ( ! F_31 ( V_192 -> V_72 ) )
if ( V_192 -> V_188 != V_193 -> V_188 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_73 * V_194 ,
struct V_73 * V_195 [] , int V_196 ,
int * V_197 )
{
int V_68 ;
#define F_84 0
#define F_85 1
#define F_86 2
#define F_87 3
if ( V_194 == NULL )
return F_84 ;
for ( V_68 = 0 ; V_68 < V_196 ; V_68 ++ ) {
if ( V_195 [ V_68 ] == NULL )
continue;
if ( F_88 ( V_194 -> V_72 , V_195 [ V_68 ] -> V_72 ) ) {
* V_197 = V_68 ;
if ( F_81 ( V_194 , V_195 [ V_68 ] ) ) {
if ( F_82 ( V_194 , V_195 [ V_68 ] ) )
return F_87 ;
return F_86 ;
} else {
if ( V_194 -> V_198 )
return F_84 ;
return F_85 ;
}
}
}
* V_197 = - 1 ;
return F_84 ;
}
static void F_89 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_199 * V_42 ;
unsigned long V_78 ;
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_90 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_36 ( & V_22 -> V_200 , V_78 ) ;
return;
}
}
F_36 ( & V_22 -> V_200 , V_78 ) ;
V_42 = F_91 ( sizeof( * V_42 ) , V_201 ) ;
if ( ! V_42 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_53 , V_202 ) ;
return;
}
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_92 ( & V_42 -> V_203 , & V_22 -> V_204 ) ;
F_36 ( & V_22 -> V_200 , V_78 ) ;
}
static void F_93 ( struct V_1 * V_22 ,
struct V_73 * V_178 )
{
if ( V_178 -> V_198 == V_205 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_54 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
switch ( V_178 -> V_198 ) {
case V_206 :
break;
case V_207 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_55 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_208 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_56 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_209 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_57 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_210 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_58 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_211 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_59 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_212 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_60 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_213 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_61 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_214 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_62 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_215 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_63 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_216 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_64 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
case V_217 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_65 ,
V_22 -> V_59 -> V_100 ,
V_178 -> V_101 , V_178 -> V_102 , V_178 -> V_103 ) ;
break;
}
}
static void F_95 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_160 ,
struct V_73 * V_218 )
{
struct V_219 * V_220 = & V_218 -> V_184 ;
struct V_221 * V_222 = & V_220 -> V_223 [ 0 ] ;
int V_68 , V_191 ;
int V_224 = F_96 ( V_220 -> V_225 ) +
F_96 ( V_220 -> V_226 ) ;
int V_227 = F_96 ( V_220 -> V_228 ) *
F_96 ( V_220 -> V_229 ) *
V_224 ;
int V_230 = F_96 ( V_220 -> V_229 ) *
V_224 ;
int V_231 ;
if ( V_227 > V_232 )
V_227 = V_232 ;
V_218 -> V_233 = V_227 ;
V_231 = 0 ;
for ( V_68 = 0 ; V_68 < V_227 ; V_68 ++ ) {
V_218 -> V_234 [ V_68 ] = NULL ;
if ( ! V_218 -> V_172 )
continue;
for ( V_191 = 0 ; V_191 < V_160 ; V_191 ++ ) {
if ( V_30 [ V_191 ] == NULL )
continue;
if ( V_30 [ V_191 ] -> V_104 != V_106 )
continue;
if ( F_32 ( V_30 [ V_191 ] ) )
continue;
if ( V_30 [ V_191 ] -> V_185 != V_222 [ V_68 ] . V_185 )
continue;
V_218 -> V_234 [ V_68 ] = V_30 [ V_191 ] ;
if ( V_68 < V_230 )
V_231 = F_97 ( V_22 -> V_235 , V_231 +
V_218 -> V_234 [ V_68 ] -> V_188 ) ;
break;
}
if ( ! V_218 -> V_234 [ V_68 ] ) {
V_218 -> V_89 = 0 ;
V_218 -> V_181 = 0 ;
V_218 -> V_188 = 8 ;
}
}
if ( V_227 )
V_218 -> V_188 = V_231 ;
else
V_218 -> V_188 = V_22 -> V_235 ;
}
static void F_98 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_160 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_160 ; V_68 ++ ) {
if ( V_30 [ V_68 ] == NULL )
continue;
if ( V_30 [ V_68 ] -> V_104 != V_106 )
continue;
if ( ! F_32 ( V_30 [ V_68 ] ) )
continue;
if ( V_30 [ V_68 ] -> V_89 )
continue;
F_95 ( V_22 , V_30 , V_160 , V_30 [ V_68 ] ) ;
}
}
static int F_99 ( struct V_1 * V_22 , struct V_73 * V_42 )
{
int V_21 = 0 ;
if ( ! V_22 -> V_59 )
return 1 ;
if ( F_32 ( V_42 ) )
V_21 = F_100 ( V_22 -> V_59 , V_42 -> V_101 ,
V_42 -> V_102 , V_42 -> V_103 ) ;
else
V_21 = F_101 ( V_22 -> V_236 , V_42 ) ;
return V_21 ;
}
static void F_102 ( struct V_1 * V_22 ,
struct V_73 * V_42 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_22 -> V_59 )
return;
if ( F_32 ( V_42 ) ) {
V_3 = F_103 ( V_22 -> V_59 , V_42 -> V_101 ,
V_42 -> V_102 , V_42 -> V_103 ) ;
if ( V_3 ) {
F_104 ( V_3 ) ;
F_105 ( V_3 ) ;
} else {
F_69 ( V_237 , V_22 , V_42 ,
L_66 ) ;
}
} else
F_106 ( V_42 ) ;
}
static void F_107 ( struct V_1 * V_22 ,
struct V_73 * V_178 [] , int V_238 )
{
int V_68 , V_182 , V_239 , V_240 = 0 ;
struct V_73 * V_241 ;
unsigned long V_78 ;
struct V_73 * * V_173 , * * V_189 ;
int V_174 , V_190 ;
if ( V_22 -> V_242 ) {
V_22 -> V_243 = 1 ;
return;
}
V_173 = F_108 ( sizeof( * V_173 ) * V_159 , V_201 ) ;
V_189 = F_108 ( sizeof( * V_189 ) * V_159 , V_201 ) ;
if ( ! V_173 || ! V_189 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_67
L_68 ) ;
goto V_244;
}
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_68 = 0 ;
V_190 = 0 ;
V_174 = 0 ;
while ( V_68 < V_22 -> V_160 ) {
V_241 = V_22 -> V_30 [ V_68 ] ;
V_239 = F_83 ( V_241 , V_178 , V_238 , & V_182 ) ;
if ( V_239 == F_84 ) {
V_240 ++ ;
F_78 ( V_22 , V_68 , V_189 , & V_190 ) ;
continue;
} else if ( V_239 == F_85 ) {
V_240 ++ ;
F_77 ( V_22 , V_68 , V_178 [ V_182 ] ,
V_173 , & V_174 , V_189 , & V_190 ) ;
V_178 [ V_182 ] = NULL ;
} else if ( V_239 == F_87 ) {
F_74 ( V_22 , V_68 , V_178 [ V_182 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_238 ; V_68 ++ ) {
if ( ! V_178 [ V_68 ] )
continue;
if ( V_178 [ V_68 ] -> V_198 ) {
F_93 ( V_22 , V_178 [ V_68 ] ) ;
F_69 ( V_180 , V_22 , V_178 [ V_68 ] , L_69 ) ;
continue;
}
V_239 = F_83 ( V_178 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_160 , & V_182 ) ;
if ( V_239 == F_84 ) {
V_240 ++ ;
if ( F_72 ( V_22 , V_178 [ V_68 ] , V_173 , & V_174 ) != 0 )
break;
V_178 [ V_68 ] = NULL ;
} else if ( V_239 == F_85 ) {
V_240 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_70 ) ;
}
}
F_98 ( V_22 , V_22 -> V_30 , V_22 -> V_160 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == NULL )
continue;
V_22 -> V_30 [ V_68 ] -> V_89 = V_22 -> V_30 [ V_68 ] -> V_181 ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_238 ; V_68 ++ ) {
if ( ! V_178 [ V_68 ] )
continue;
if ( V_178 [ V_68 ] -> V_198 )
F_89 ( V_22 , V_178 [ V_68 ] -> V_72 ) ;
}
if ( ! V_240 )
goto V_244;
for ( V_68 = 0 ; V_68 < V_190 ; V_68 ++ ) {
if ( V_189 [ V_68 ] == NULL )
continue;
if ( V_189 [ V_68 ] -> V_107 )
F_102 ( V_22 , V_189 [ V_68 ] ) ;
F_80 ( V_189 [ V_68 ] ) ;
V_189 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_174 ; V_68 ++ ) {
int V_21 = 0 ;
if ( V_173 [ V_68 ] == NULL )
continue;
if ( ! ( V_173 [ V_68 ] -> V_107 ) )
continue;
V_21 = F_99 ( V_22 , V_173 [ V_68 ] ) ;
if ( ! V_21 )
continue;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_71 , V_21 ) ;
F_79 ( V_22 , V_173 [ V_68 ] ) ;
V_22 -> V_243 = 1 ;
}
V_244:
F_80 ( V_173 ) ;
F_80 ( V_189 ) ;
}
static struct V_73 * F_109 ( struct V_1 * V_22 ,
int V_101 , int V_102 , int V_103 )
{
int V_68 ;
struct V_73 * V_178 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
V_178 = V_22 -> V_30 [ V_68 ] ;
if ( V_178 -> V_101 == V_101 && V_178 -> V_102 == V_102 && V_178 -> V_103 == V_103 )
return V_178 ;
}
return NULL ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_73 * V_178 ;
unsigned long V_78 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
if ( F_111 ( V_3 ) == V_245 ) {
struct V_246 * V_247 ;
struct V_248 * V_249 ;
V_247 = V_246 ( V_3 ) ;
V_249 = F_112 ( V_247 ) ;
V_178 = F_113 ( V_22 , V_249 ) ;
if ( V_178 ) {
V_178 -> V_102 = F_114 ( V_3 ) ;
V_178 -> V_103 = V_3 -> V_103 ;
}
} else
V_178 = F_109 ( V_22 , F_111 ( V_3 ) ,
F_114 ( V_3 ) , V_3 -> V_103 ) ;
if ( V_178 && V_178 -> V_107 ) {
F_115 ( & V_178 -> V_250 , 0 ) ;
V_3 -> V_80 = V_178 ;
} else
V_3 -> V_80 = NULL ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_73 * V_178 ;
int V_188 ;
V_178 = V_3 -> V_80 ;
V_3 -> V_251 = ! V_178 || ! V_178 -> V_107 ;
if ( V_178 )
V_188 = V_178 -> V_188 != 0 ?
V_178 -> V_188 : V_3 -> V_5 -> V_252 ;
else
V_188 = V_3 -> V_5 -> V_252 ;
F_117 ( V_3 , V_188 ) ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 )
{
}
static void F_119 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_253 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
F_80 ( V_22 -> V_253 [ V_68 ] ) ;
V_22 -> V_253 [ V_68 ] = NULL ;
}
F_80 ( V_22 -> V_253 ) ;
V_22 -> V_253 = NULL ;
}
static int F_120 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_254 <= 0 )
return 0 ;
V_22 -> V_253 =
F_108 ( sizeof( * V_22 -> V_253 ) * V_22 -> V_235 ,
V_201 ) ;
if ( ! V_22 -> V_253 )
return - V_255 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_22 -> V_253 [ V_68 ] =
F_91 ( sizeof( * V_22 -> V_253 [ V_68 ] ) *
V_22 -> V_256 , V_201 ) ;
if ( ! V_22 -> V_253 [ V_68 ] )
goto V_257;
}
return 0 ;
V_257:
F_119 ( V_22 ) ;
return - V_255 ;
}
static void F_121 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_258 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
F_80 ( V_22 -> V_258 [ V_68 ] ) ;
V_22 -> V_258 [ V_68 ] = NULL ;
}
F_80 ( V_22 -> V_258 ) ;
V_22 -> V_258 = NULL ;
}
static int F_122 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_254 <= 0 )
return 0 ;
V_22 -> V_258 = F_108 ( sizeof( * V_22 -> V_258 ) * V_22 -> V_235 ,
V_201 ) ;
if ( ! V_22 -> V_258 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_72 ) ;
return - V_255 ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_22 -> V_258 [ V_68 ] = F_91 ( sizeof( * V_22 -> V_258 [ V_68 ] ) *
V_22 -> V_254 , V_201 ) ;
if ( ! V_22 -> V_258 [ V_68 ] ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_73 ) ;
goto V_257;
}
}
return 0 ;
V_257:
F_121 ( V_22 ) ;
return - V_255 ;
}
static int F_123 ( struct V_1 * V_22 ,
struct V_137 * V_129 , struct V_8 * V_9 )
{
struct V_259 * V_260 ;
T_5 V_261 ;
T_4 V_262 ;
V_260 = V_22 -> V_253 [ V_9 -> V_131 ] ;
V_262 = F_124 ( V_129 -> V_263 [ 0 ] . V_264 ) ;
V_261 = F_125 ( V_22 -> V_29 , V_260 , V_262 ,
V_265 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , V_261 ) ) {
V_129 -> V_263 -> V_266 = 0 ;
return - 1 ;
}
V_129 -> V_263 -> V_266 = F_127 ( V_261 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_22 ,
struct V_137 * V_129 )
{
struct V_259 * V_267 ;
T_5 V_261 ;
T_4 V_262 ;
V_267 = V_129 -> V_263 ;
V_261 = F_129 ( V_267 -> V_266 ) ;
V_262 = F_124 ( V_129 -> V_263 [ 0 ] . V_264 ) ;
F_130 ( V_22 -> V_29 , V_261 , V_262 , V_265 ) ;
}
static int F_131 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_268 * V_267 , * V_260 ;
T_5 V_261 ;
T_4 V_269 ;
V_267 = & V_9 -> V_270 [ V_22 -> V_271 - 1 ] ;
V_260 = V_22 -> V_258 [ V_9 -> V_131 ] ;
V_267 -> V_272 = F_132 ( V_273 ) ;
V_269 = sizeof( * V_267 ) *
( F_96 ( V_9 -> V_122 . V_274 ) - V_22 -> V_271 ) ;
V_267 -> V_275 = F_132 ( V_269 ) ;
V_261 = F_125 ( V_22 -> V_29 , V_260 , V_269 ,
V_265 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , V_261 ) ) {
V_267 -> V_276 = F_127 ( 0 ) ;
return - 1 ;
}
V_267 -> V_276 = F_127 ( V_261 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_268 * V_267 ;
if ( F_96 ( V_9 -> V_122 . V_274 ) <= V_22 -> V_271 )
return;
V_267 = & V_9 -> V_270 [ V_22 -> V_271 - 1 ] ;
F_130 ( V_22 -> V_29 , F_129 ( V_267 -> V_276 ) ,
F_124 ( V_267 -> V_275 ) , V_265 ) ;
}
static int F_134 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_277 * V_278 ,
struct V_137 * V_279 )
{
int V_280 ;
int V_281 = 0 ;
T_4 V_282 = 0 ;
switch ( V_279 -> V_283 . V_284 ) {
case V_285 :
switch ( V_279 -> V_283 . V_49 ) {
case V_286 :
break;
case V_287 :
V_278 -> V_288 |= V_289 ;
if ( V_279 -> V_283 . V_290 !=
V_291 ) {
memset ( V_278 -> V_292 , 0 ,
V_293 ) ;
break;
}
V_280 = V_279 -> V_283 . V_15 ;
if ( V_280 > V_293 )
V_280 = V_293 ;
if ( V_280 > sizeof( V_279 -> V_283 . V_294 ) )
V_280 =
sizeof( V_279 -> V_283 . V_294 ) ;
memcpy ( V_278 -> V_292 ,
V_279 -> V_283 . V_294 , V_280 ) ;
V_281 = 1 ;
break;
case V_295 :
V_281 = 1 ;
break;
case V_296 :
V_281 = 1 ;
break;
case V_297 :
V_281 = 1 ;
break;
case V_298 :
V_281 = 1 ;
break;
default:
V_281 = 1 ;
break;
}
break;
case V_299 :
switch ( V_279 -> V_283 . V_49 ) {
case V_300 :
case V_301 :
case V_302 :
V_281 = 1 ;
break;
case V_303 :
V_278 -> V_288 = ( V_304 << 16 ) ;
V_278 -> V_288 |= ( V_305 << 8 ) ;
V_282 = F_135 (
& V_279 -> V_283 . V_306 [ 0 ] ) ;
F_136 ( V_278 , V_282 ) ;
break;
case V_307 :
case V_308 :
case V_309 :
V_281 = 1 ;
break;
default:
V_281 = 1 ;
}
break;
case V_310 :
break;
case V_311 :
break;
case V_312 :
V_281 = 1 ;
break;
case V_313 :
break;
default:
V_281 = 1 ;
break;
}
return V_281 ;
}
static void F_137 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_314 = false ;
V_9 -> V_10 = V_11 ;
F_138 () ;
if ( V_9 -> V_12 ) {
V_314 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_78 ;
struct V_73 * V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_57 ( & V_30 -> V_315 ) )
V_314 = true ;
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
if ( V_314 )
F_139 ( & V_22 -> V_316 ) ;
}
static void F_140 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_137 ( V_22 , V_9 ) ;
F_141 ( V_22 , V_9 ) ;
}
static void F_142 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 )
{
F_140 ( V_22 , V_9 ) ;
V_278 -> V_317 ( V_278 ) ;
}
static void F_143 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_144 ( & V_9 -> V_318 , V_319 ) ;
F_145 ( F_48 () , V_22 -> V_320 , & V_9 -> V_318 ) ;
}
static void F_146 ( struct V_277 * V_278 )
{
V_278 -> V_288 = V_321 << 16 ;
}
static void F_147 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_277 * V_278 )
{
F_146 ( V_278 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_74 ,
V_9 -> V_142 . V_143 , V_9 -> V_24 -> V_38 ) ;
F_140 ( V_22 , V_9 ) ;
}
static void F_148 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
struct V_73 * V_30 )
{
struct V_137 * V_279 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
if ( F_47 ( V_279 -> V_283 . V_284 == 0 &&
V_279 -> V_283 . V_49 == 0 ) )
return F_142 ( V_22 , V_9 , V_278 ) ;
if ( F_32 ( V_30 ) &&
V_279 -> V_283 . V_284 ==
V_299 ) {
if ( V_279 -> V_283 . V_49 ==
V_309 )
V_30 -> V_89 = 0 ;
return F_143 ( V_22 , V_9 ) ;
}
if ( F_134 ( V_22 , V_9 , V_278 , V_279 ) )
return F_143 ( V_22 , V_9 ) ;
return F_142 ( V_22 , V_9 , V_278 ) ;
}
static int F_149 ( struct V_1 * V_22 ,
struct V_8 * V_129 )
{
T_1 V_322 = V_129 -> V_24 -> V_38 ;
switch ( V_322 ) {
case V_323 :
case V_324 :
return 0 ;
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_75 ,
V_322 ) ;
break;
}
return - V_322 ;
}
static void F_150 ( struct V_8 * V_129 )
{
struct V_277 * V_278 ;
struct V_1 * V_22 ;
struct V_330 * V_331 ;
struct V_73 * V_30 ;
struct V_137 * V_279 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_332 ;
V_331 = V_129 -> V_24 ;
V_278 = V_129 -> V_10 ;
V_22 = V_129 -> V_22 ;
V_30 = V_278 -> V_42 -> V_80 ;
V_279 = & V_22 -> V_135 [ V_129 -> V_131 ] ;
F_151 ( V_278 ) ;
if ( ( V_129 -> V_148 == V_333 ) &&
( F_96 ( V_129 -> V_122 . V_274 ) > V_22 -> V_271 ) )
F_133 ( V_22 , V_129 ) ;
if ( ( V_129 -> V_148 == V_152 ) &&
( V_279 -> V_263 [ 0 ] . V_334 == V_335 ) )
F_128 ( V_22 , V_279 ) ;
V_278 -> V_288 = ( V_304 << 16 ) ;
V_278 -> V_288 |= ( V_305 << 8 ) ;
if ( V_129 -> V_148 == V_152 || V_129 -> V_148 == V_149 )
F_45 ( & V_129 -> V_234 -> V_250 ) ;
if ( F_44 ( V_331 -> V_36 == V_336 ) ) {
V_278 -> V_288 = V_337 << 16 ;
return F_142 ( V_22 , V_129 , V_278 ) ;
}
if ( ( F_44 ( F_5 ( V_129 ) ) ) ) {
if ( V_129 -> V_13 )
return F_140 ( V_22 , V_129 ) ;
if ( V_129 -> V_12 )
return F_147 ( V_22 , V_129 , V_278 ) ;
}
if ( V_129 -> V_148 == V_152 )
return F_148 ( V_22 , V_129 , V_278 , V_30 ) ;
F_136 ( V_278 , V_331 -> V_338 ) ;
if ( V_331 -> V_36 == 0 )
return F_142 ( V_22 , V_129 , V_278 ) ;
if ( V_129 -> V_148 == V_149 ) {
struct V_128 * V_9 = & V_22 -> V_130 [ V_129 -> V_131 ] ;
V_129 -> V_122 . V_123 = F_152 ( V_278 ) ;
V_129 -> V_122 . V_274 = F_153 ( V_129 -> V_122 . V_123 ) ;
V_129 -> V_142 . V_339 = F_96 ( V_9 -> V_340 ) &
V_341 ;
V_129 -> V_122 . V_342 = V_9 -> V_342 ;
memcpy ( V_129 -> V_122 . V_343 . V_344 , V_9 -> V_345 , 8 ) ;
memcpy ( V_129 -> V_142 . V_143 , V_9 -> V_143 , V_129 -> V_142 . V_339 ) ;
if ( F_32 ( V_30 ) ) {
if ( V_331 -> V_36 == V_346 )
V_30 -> V_89 = 0 ;
return F_143 ( V_22 , V_129 ) ;
}
}
switch ( V_331 -> V_36 ) {
case V_37 :
V_278 -> V_288 |= V_331 -> V_38 ;
if ( V_293 < sizeof( V_331 -> V_26 ) )
V_332 = V_293 ;
else
V_332 = sizeof( V_331 -> V_26 ) ;
if ( V_331 -> V_25 < V_332 )
V_332 = V_331 -> V_25 ;
memcpy ( V_278 -> V_292 , V_331 -> V_26 , V_332 ) ;
if ( V_331 -> V_38 )
F_6 ( V_331 -> V_26 , V_332 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_331 -> V_38 == V_289 ) {
if ( V_16 == V_347 ) {
V_278 -> V_288 |= V_348 << 16 ;
break;
}
break;
}
if ( V_331 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_76
L_77
L_78 ,
V_129 , V_331 -> V_38 ,
V_16 , V_17 , V_18 ,
V_278 -> V_288 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_79
L_80 , V_129 ) ,
V_278 -> V_288 = V_337 << 16 ;
}
break;
case V_349 :
break;
case V_350 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_81 , V_129 -> V_142 . V_143 ) ;
break;
case V_351 : {
V_278 -> V_288 = V_337 << 16 ;
}
break;
case V_352 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_82 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_354 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_83 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_355 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_84 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_356 :
return F_147 ( V_22 , V_129 , V_278 ) ;
case V_357 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_85 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_358 :
V_278 -> V_288 = V_348 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_86 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_359 :
V_278 -> V_288 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_87 ,
V_129 -> V_142 . V_143 ) ;
break;
case V_361 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_88 ) ;
break;
case V_362 :
if ( F_149 ( V_22 , V_129 ) )
V_278 -> V_288 = V_353 << 16 ;
break;
case V_346 :
V_278 -> V_288 = V_348 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_89 , V_129 ) ;
break;
default:
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_90 ,
V_129 , V_331 -> V_36 ) ;
}
return F_142 ( V_22 , V_129 , V_278 ) ;
}
static void F_154 ( struct V_363 * V_29 ,
struct V_8 * V_9 , int V_364 , int V_365 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ )
F_130 ( V_29 , ( V_366 ) F_129 ( V_9 -> V_270 [ V_68 ] . V_276 ) ,
F_124 ( V_9 -> V_270 [ V_68 ] . V_275 ) ,
V_365 ) ;
}
static int F_155 ( struct V_363 * V_29 ,
struct V_8 * V_129 ,
unsigned char * V_45 ,
T_3 V_367 ,
int V_365 )
{
T_5 V_368 ;
if ( V_367 == 0 || V_365 == V_369 ) {
V_129 -> V_122 . V_123 = 0 ;
V_129 -> V_122 . V_274 = F_153 ( 0 ) ;
return 0 ;
}
V_368 = F_125 ( V_29 , V_45 , V_367 , V_365 ) ;
if ( F_126 ( & V_29 -> V_30 , V_368 ) ) {
V_129 -> V_122 . V_123 = 0 ;
V_129 -> V_122 . V_274 = F_153 ( 0 ) ;
return - 1 ;
}
V_129 -> V_270 [ 0 ] . V_276 = F_127 ( V_368 ) ;
V_129 -> V_270 [ 0 ] . V_275 = F_132 ( V_367 ) ;
V_129 -> V_270 [ 0 ] . V_272 = F_132 ( V_370 ) ;
V_129 -> V_122 . V_123 = 1 ;
V_129 -> V_122 . V_274 = F_153 ( 1 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_111 , unsigned long V_371 )
{
F_157 ( V_372 ) ;
V_9 -> V_373 = & V_372 ;
F_58 ( V_22 , V_9 , V_111 ) ;
if ( V_371 == V_374 ) {
F_158 ( & V_372 ) ;
return V_375 ;
}
if ( ! F_159 ( & V_372 ,
F_160 ( V_371 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_91 ) ;
return - V_376 ;
}
return V_375 ;
}
static int F_161 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_111 , unsigned long V_371 )
{
if ( F_44 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_336 ;
return V_375 ;
}
return F_156 ( V_22 , V_9 , V_111 , V_371 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_377 ;
T_4 V_21 , * F_13 ;
V_377 = F_162 () ;
F_13 = F_163 ( V_22 -> F_13 , V_377 ) ;
V_21 = * F_13 ;
F_164 () ;
return V_21 ;
}
static int F_165 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_365 , unsigned long V_371 )
{
int V_378 = 10 , V_379 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_161 ( V_22 , V_9 , V_125 ,
V_371 ) ;
if ( V_21 )
break;
V_379 ++ ;
if ( V_379 > 3 ) {
F_166 ( V_378 ) ;
if ( V_378 < 1000 )
V_378 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_379 <= V_380 );
F_154 ( V_22 -> V_29 , V_9 , 1 , V_365 ) ;
if ( V_379 > V_380 )
V_21 = - V_381 ;
return V_21 ;
}
static void F_167 ( struct V_1 * V_22 , char * V_382 ,
struct V_8 * V_9 )
{
const T_1 * V_139 = V_9 -> V_142 . V_143 ;
const T_1 * V_103 = V_9 -> V_122 . V_343 . V_344 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_92
L_93 ,
V_382 , V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_139 [ 0 ] , V_139 [ 1 ] , V_139 [ 2 ] , V_139 [ 3 ] ,
V_139 [ 4 ] , V_139 [ 5 ] , V_139 [ 6 ] , V_139 [ 7 ] ,
V_139 [ 8 ] , V_139 [ 9 ] , V_139 [ 10 ] , V_139 [ 11 ] ,
V_139 [ 12 ] , V_139 [ 13 ] , V_139 [ 14 ] , V_139 [ 15 ] ) ;
}
static void F_168 ( struct V_1 * V_22 ,
struct V_8 * V_129 )
{
const struct V_330 * V_331 = V_129 -> V_24 ;
struct V_42 * V_383 = & V_129 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_331 -> V_36 ) {
case V_37 :
if ( V_331 -> V_25 > sizeof( V_331 -> V_26 ) )
V_23 = sizeof( V_331 -> V_26 ) ;
else
V_23 = V_331 -> V_25 ;
F_6 ( V_331 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_167 ( V_22 , L_94 , V_129 ) ;
if ( V_331 -> V_38 == V_289 )
F_9 ( V_383 , L_95 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_383 , L_96 , V_331 -> V_38 ) ;
if ( V_331 -> V_38 == 0 )
F_9 ( V_383 , L_97
L_98
L_99
L_100 ) ;
break;
case V_349 :
break;
case V_350 :
F_167 ( V_22 , L_101 , V_129 ) ;
break;
case V_351 : {
F_167 ( V_22 , L_102 , V_129 ) ;
F_9 ( V_383 , L_103 ) ;
}
break;
case V_352 :
F_167 ( V_22 , L_104 , V_129 ) ;
break;
case V_354 :
F_167 ( V_22 , L_105 , V_129 ) ;
break;
case V_355 :
F_167 ( V_22 , L_106 , V_129 ) ;
break;
case V_356 :
F_167 ( V_22 , L_107 , V_129 ) ;
break;
case V_357 :
F_167 ( V_22 , L_108 , V_129 ) ;
break;
case V_358 :
F_167 ( V_22 , L_109 , V_129 ) ;
break;
case V_359 :
F_167 ( V_22 , L_110 , V_129 ) ;
break;
case V_361 :
F_167 ( V_22 , L_111 , V_129 ) ;
break;
case V_336 :
F_167 ( V_22 , L_112 , V_129 ) ;
break;
default:
F_167 ( V_22 , L_113 , V_129 ) ;
F_9 ( V_383 , L_114 ,
V_331 -> V_36 ) ;
}
}
static int F_169 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_384 , unsigned char * V_45 ,
unsigned char V_385 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_386 , V_22 , V_45 , V_385 ,
V_384 , V_72 , V_387 ) ) {
V_21 = - 1 ;
goto V_388;
}
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_173 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_390 , int V_111 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_390 , V_22 , NULL , 0 , 0 ,
V_72 , V_391 ) ;
V_21 = F_161 ( V_22 , V_9 , V_111 , V_374 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_115 ) ;
goto V_388;
}
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_174 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_73 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_392 = false ;
struct V_137 * V_279 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
struct V_134 * V_393 = (struct V_134 * ) V_279 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_148 ) {
case V_333 :
case V_394 :
V_392 = ! memcmp ( V_72 , & V_9 -> V_122 . V_343 . V_344 ,
sizeof( V_9 -> V_122 . V_343 . V_344 ) ) ;
break;
case V_149 :
case V_152 :
if ( V_9 -> V_234 == V_30 ) {
V_392 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_233 && ! V_392 ; V_68 ++ ) {
V_392 = V_30 -> V_234 [ V_68 ] == V_9 -> V_234 ;
}
}
break;
case V_154 :
for ( V_68 = 0 ; V_68 < V_30 -> V_233 && ! V_392 ; V_68 ++ ) {
V_392 = V_30 -> V_234 [ V_68 ] -> V_185 ==
F_124 ( V_393 -> V_395 ) ;
}
break;
case 0 :
V_392 = false ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_116 ,
V_9 -> V_148 ) ;
F_175 () ;
}
return V_392 ;
}
static int F_176 ( struct V_1 * V_22 , struct V_73 * V_30 ,
unsigned char * V_72 , T_1 V_390 , int V_111 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_177 ( & V_22 -> V_396 ) == - V_397 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_117 ) ;
return - V_397 ;
}
F_75 ( F_21 ( & V_30 -> V_315 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_398 + V_68 ;
int V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( V_399 > 1 && F_174 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_78 ;
V_9 -> V_13 = V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
F_55 ( & V_30 -> V_315 ) ;
else
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_172 ( V_22 , V_9 ) ;
}
V_21 = F_173 ( V_22 , V_72 , V_390 , V_111 ) ;
if ( ! V_21 )
F_179 ( V_22 -> V_316 ,
F_21 ( & V_30 -> V_315 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_44 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_118 ) ;
V_21 = - V_81 ;
}
if ( F_44 ( V_21 ) )
F_115 ( & V_30 -> V_315 , 0 ) ;
F_180 ( & V_22 -> V_396 ) ;
return V_21 ;
}
static void F_181 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_83 )
{
int V_21 ;
unsigned char * V_45 ;
* V_83 = V_84 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return;
V_21 = F_169 ( V_22 , V_72 , V_400 | 0xC1 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_83 = V_45 [ 8 ] ;
if ( * V_83 > V_84 )
* V_83 = V_84 ;
F_80 ( V_45 ) ;
return;
}
static void F_182 ( struct V_1 * V_22 , int V_21 ,
struct V_219 * V_401 )
{
struct V_221 * V_222 = & V_401 -> V_223 [ 0 ] ;
int V_220 , V_402 , V_403 ;
T_6 V_404 , V_228 , V_405 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_94 ( & V_22 -> V_29 -> V_30 , L_119 ,
F_124 ( V_401 -> V_406 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_120 ,
F_124 ( V_401 -> V_407 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_121 ,
F_129 ( V_401 -> V_408 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_122 ,
V_401 -> V_409 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_123 ,
V_401 -> V_410 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_96 ( V_401 -> V_411 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_125 ,
F_129 ( V_401 -> V_412 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_126 ,
F_129 ( V_401 -> V_413 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_96 ( V_401 -> V_225 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_128 ,
F_96 ( V_401 -> V_226 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_129 ,
F_96 ( V_401 -> V_228 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_130 ,
F_96 ( V_401 -> V_229 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_131 ,
F_96 ( V_401 -> V_78 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_132 ,
F_96 ( V_401 -> V_78 ) &
V_414 ? L_133 : L_134 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_135 ,
F_96 ( V_401 -> V_415 ) ) ;
V_404 = F_96 ( V_401 -> V_229 ) ;
for ( V_220 = 0 ; V_220 < V_404 ; V_220 ++ ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_136 , V_220 ) ;
V_228 = F_96 ( V_401 -> V_228 ) ;
for ( V_402 = 0 ; V_402 < V_228 ; V_402 ++ ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_137 , V_402 ) ;
V_405 =
F_96 ( V_401 -> V_225 ) ;
for ( V_403 = 0 ; V_403 < V_405 ; V_403 ++ , V_222 ++ )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_138 ,
V_403 , V_222 -> V_185 ,
V_222 -> V_416 [ 0 ] , V_222 -> V_416 [ 1 ] ) ;
V_405 =
F_96 ( V_401 -> V_226 ) ;
for ( V_403 = 0 ; V_403 < V_405 ; V_403 ++ , V_222 ++ )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_139 ,
V_403 , V_222 -> V_185 ,
V_222 -> V_416 [ 0 ] , V_222 -> V_416 [ 1 ] ) ;
}
}
}
static int F_183 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_417 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_418 , V_22 , & V_417 -> V_184 ,
sizeof( V_417 -> V_184 ) , 0 ,
V_72 , V_387 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_140 ) ;
F_172 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_388;
}
F_172 ( V_22 , V_9 ) ;
if ( F_124 ( V_417 -> V_184 . V_406 ) >
sizeof( V_417 -> V_184 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_141 ) ;
V_21 = - 1 ;
}
F_182 ( V_22 , V_21 , & V_417 -> V_184 ) ;
return V_21 ;
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_184 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_419 ,
struct V_420 * V_45 , T_3 V_385 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_421 , V_22 , V_45 , V_385 ,
0 , V_156 , V_387 ) ;
if ( V_21 )
goto V_388;
V_9 -> V_142 . V_143 [ 2 ] = V_419 & 0xff ;
V_9 -> V_142 . V_143 [ 9 ] = ( V_419 >> 8 ) & 0xff ;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_185 ( struct V_1 * V_22 ,
struct V_422 * V_45 , T_3 V_385 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_423 , V_22 , V_45 , V_385 ,
0 , V_156 , V_387 ) ;
if ( V_21 )
goto V_388;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_186 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_419 ,
struct V_424 * V_45 , T_3 V_385 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_425 , V_22 , V_45 , V_385 ,
0 , V_156 , V_387 ) ;
if ( V_21 )
goto V_388;
V_9 -> V_142 . V_143 [ 2 ] = V_419 & 0xff ;
V_9 -> V_142 . V_143 [ 9 ] = ( V_419 >> 8 ) & 0xff ;
F_165 ( V_22 , V_9 , V_389 ,
V_374 ) ;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static void F_187 ( struct V_1 * V_22 ,
unsigned char * V_72 ,
struct V_426 * V_427 , int V_428 ,
struct V_73 * V_429 )
{
int V_21 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_330 * V_331 = NULL ;
struct V_430 * V_431 = NULL ;
struct V_424 * V_432 = NULL ;
struct V_433 * V_434 = & V_427 -> V_343 [ V_428 ] ;
T_6 V_419 = 0 ;
V_419 = F_188 ( & V_434 -> V_86 [ 0 ] ) ;
if ( V_419 == 0xFF00 )
goto V_388;
V_431 = F_108 ( sizeof( * V_431 ) , V_201 ) ;
if ( ! V_431 )
goto V_388;
V_432 = F_108 ( sizeof( * V_432 ) , V_201 ) ;
if ( ! V_432 )
goto V_388;
V_21 = F_186 ( V_22 , V_72 , V_419 ,
V_432 , sizeof( * V_432 ) ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_142 ,
V_202 , V_429 -> V_165 , V_419 ) ;
goto V_388;
}
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_435 , V_22 , V_431 ,
sizeof( * V_431 ) , 0 , V_156 , V_387 ) ;
if ( V_21 )
goto V_388;
if ( V_432 -> V_95 [ 1 ] == 'E' )
V_9 -> V_142 . V_143 [ 5 ] = V_432 -> V_436 ;
else
V_9 -> V_142 . V_143 [ 5 ] = 0 ;
V_21 = F_165 ( V_22 , V_9 , V_389 ,
V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 && V_331 -> V_36 != V_349 ) {
V_21 = - 1 ;
goto V_388;
}
V_429 -> V_91 [ V_432 -> V_437 ] = V_431 -> V_438 ;
memcpy ( & V_429 -> V_95 [ V_432 -> V_437 ] ,
V_431 -> V_95 , sizeof( V_431 -> V_95 ) ) ;
V_21 = V_375 ;
V_388:
F_80 ( V_431 ) ;
F_80 ( V_432 ) ;
if ( V_9 )
F_172 ( V_22 , V_9 ) ;
if ( V_21 != V_375 )
F_69 ( V_180 , V_22 , V_429 ,
L_143 ) ;
}
static T_5 F_189 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_426 * V_439 ;
T_4 V_440 ;
T_5 V_441 = 0 ;
int V_68 ;
V_439 = F_108 ( sizeof( * V_439 ) , V_201 ) ;
if ( ! V_439 )
return 0 ;
if ( F_190 ( V_22 , V_439 , sizeof( * V_439 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
F_80 ( V_439 ) ;
return 0 ;
}
V_440 = F_191 ( V_439 -> V_442 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_440 ; V_68 ++ )
if ( ! memcmp ( & V_439 -> V_343 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_441 = F_192 ( & V_439 -> V_343 [ V_68 ] . V_443 [ 0 ] ) ;
break;
}
F_80 ( V_439 ) ;
return V_441 ;
}
static void F_193 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_441 = 0 ;
if ( F_62 ( V_72 ) ) {
struct V_420 * V_444 ;
V_444 = F_108 ( sizeof( * V_444 ) , V_201 ) ;
if ( V_444 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_145 , V_202 ) ;
return;
}
V_21 = F_184 ( V_22 ,
V_72 , 0 , V_444 , sizeof( * V_444 ) ) ;
if ( V_21 == 0 ) {
V_441 = F_192 ( V_444 -> V_445 ) ;
V_22 -> V_446 = V_441 ;
}
F_80 ( V_444 ) ;
} else
V_441 = F_189 ( V_22 , V_72 ) ;
V_30 -> V_446 = V_441 ;
}
static int F_194 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_384 )
{
int V_21 ;
int V_68 ;
int V_447 ;
unsigned char * V_45 , V_385 ;
V_45 = F_108 ( 256 , V_201 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_448 ,
V_45 , V_449 ) ;
if ( V_21 != 0 )
goto V_450;
V_447 = V_45 [ 3 ] ;
if ( ( V_447 + V_449 ) <= 255 )
V_385 = V_447 + V_449 ;
else
V_385 = 255 ;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_448 ,
V_45 , V_385 ) ;
if ( V_21 != 0 )
goto V_450;
V_447 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_447 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_384 )
goto V_451;
V_450:
F_80 ( V_45 ) ;
return 0 ;
V_451:
F_80 ( V_45 ) ;
return 1 ;
}
static void F_195 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_417 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_452 ;
V_417 -> V_172 = 0 ;
V_417 -> V_89 = 0 ;
V_417 -> V_181 = 0 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return;
if ( ! F_194 ( V_22 , V_72 , V_453 ) )
goto V_388;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_453 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_388;
#define F_196 4
#define F_197 0x01
#define F_198 0x02
V_452 = V_45 [ F_196 ] ;
V_417 -> V_172 =
! ! ( V_452 & F_197 ) ;
if ( V_417 -> V_172 ) {
V_417 -> V_89 =
! ! ( V_452 & F_198 ) ;
if ( F_183 ( V_22 , V_72 , V_417 ) )
V_417 -> V_89 = 0 ;
}
V_417 -> V_181 = V_417 -> V_89 ;
V_388:
F_80 ( V_45 ) ;
return;
}
static int F_199 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_88 , int V_197 , int V_367 )
{
int V_21 ;
unsigned char * V_45 ;
if ( V_367 > 16 )
V_367 = 16 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return - V_255 ;
V_21 = F_169 ( V_22 , V_72 , V_400 | 0x83 , V_45 , 64 ) ;
if ( V_21 == 0 )
memcpy ( V_88 , & V_45 [ V_197 ] , V_367 ) ;
F_80 ( V_45 ) ;
return V_21 != 0 ;
}
static int F_200 ( struct V_1 * V_22 , int V_454 ,
void * V_45 , int V_385 ,
int V_455 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_171 ( V_9 , V_454 ? V_456 : V_457 , V_22 ,
V_45 , V_385 , 0 , V_72 , V_387 ) ) {
V_21 = - 1 ;
goto V_388;
}
if ( V_455 )
V_9 -> V_142 . V_143 [ 1 ] = V_455 ;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( V_21 )
goto V_388;
V_331 = V_9 -> V_24 ;
if ( V_331 -> V_36 != 0 &&
V_331 -> V_36 != V_349 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_458 * V_459 = V_45 ;
if ( V_459 -> V_460 != V_455 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_146 ,
V_455 ,
V_459 -> V_460 ) ;
V_21 = - 1 ;
}
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_190 ( struct V_1 * V_22 ,
struct V_426 * V_45 , int V_385 )
{
return F_200 ( V_22 , 0 , V_45 , V_385 ,
V_461 ) ;
}
static inline int F_201 ( struct V_1 * V_22 ,
struct V_458 * V_45 , int V_385 )
{
return F_200 ( V_22 , 1 , V_45 , V_385 , 0 ) ;
}
static inline void F_202 ( struct V_73 * V_42 ,
int V_101 , int V_102 , int V_103 )
{
V_42 -> V_101 = V_101 ;
V_42 -> V_102 = V_102 ;
V_42 -> V_103 = V_103 ;
}
static int F_203 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_462 ;
unsigned char * V_45 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return V_205 ;
if ( ! F_194 ( V_22 , V_72 , V_463 ) )
goto V_464;
V_21 = F_169 ( V_22 , V_72 , V_400 | V_463 ,
V_45 , V_449 ) ;
if ( V_21 != 0 )
goto V_464;
V_462 = V_45 [ 3 ] ;
V_21 = F_169 ( V_22 , V_72 , V_400 | V_463 ,
V_45 , V_462 + V_449 ) ;
if ( V_21 != 0 )
goto V_464;
V_49 = V_45 [ 4 ] ;
F_80 ( V_45 ) ;
return V_49 ;
V_464:
F_80 ( V_45 ) ;
return V_205 ;
}
static int F_204 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_465 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_466 = 0 ;
T_6 V_467 ;
T_1 V_468 ;
#define F_205 0x04
#define F_206 0x04
#define F_207 0x02
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_469 , V_22 , NULL , 0 , 0 , V_72 , V_387 ) ;
V_21 = F_161 ( V_22 , V_9 , V_125 , V_374 ) ;
if ( V_21 ) {
F_172 ( V_22 , V_9 ) ;
return 0 ;
}
V_465 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_465 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_467 = V_9 -> V_24 -> V_36 ;
V_468 = V_9 -> V_24 -> V_38 ;
F_172 ( V_22 , V_9 ) ;
if ( V_467 != V_37 ||
V_468 != V_289 ||
V_16 != V_470 ||
V_17 != F_205 ) {
return 0 ;
}
V_466 = F_203 ( V_22 , V_72 ) ;
switch ( V_466 ) {
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
return V_466 ;
case V_205 :
if ( ( V_18 == F_206 ) ||
( V_18 == F_207 ) )
return V_466 ;
break;
default:
break;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_330 * V_331 ;
int V_21 = 0 ;
T_5 V_342 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_471 , V_22 , & V_342 , 0 , 0 , V_72 , V_391 ) ;
( void ) F_161 ( V_22 , V_9 , V_125 , V_374 ) ;
V_331 = V_9 -> V_24 ;
switch ( V_331 -> V_36 ) {
case V_351 :
V_21 = 0 ;
break;
case V_361 :
case V_357 :
V_21 = 1 ;
break;
case V_362 :
V_21 = F_149 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static void F_209 ( unsigned char * V_472 , int V_50 )
{
bool V_473 = false ;
for (; V_50 > 0 ; ( -- V_50 , ++ V_472 ) ) {
if ( * V_472 == 0 )
V_473 = true ;
if ( V_473 || * V_472 < 0x20 || * V_472 > 0x7e )
* V_472 = ' ' ;
}
}
static int F_210 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_73 * V_417 ,
unsigned char * V_474 )
{
#define F_211 43
#define F_212 "$DR-10"
#define F_213 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_214 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_475 ;
unsigned char * V_476 ;
int V_21 = 0 ;
V_475 = F_108 ( F_214 , V_201 ) ;
if ( ! V_475 ) {
V_21 = - V_255 ;
goto V_477;
}
if ( F_169 ( V_22 , V_72 , 0 , V_475 ,
( unsigned char ) F_214 ) != 0 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_147 ) ;
V_21 = - V_381 ;
goto V_477;
}
F_209 ( & V_475 [ 8 ] , 8 ) ;
F_209 ( & V_475 [ 16 ] , 16 ) ;
V_417 -> V_104 = ( V_475 [ 0 ] & 0x1f ) ;
memcpy ( V_417 -> V_72 , V_72 , 8 ) ;
memcpy ( V_417 -> V_170 , & V_475 [ 8 ] ,
sizeof( V_417 -> V_170 ) ) ;
memcpy ( V_417 -> V_171 , & V_475 [ 16 ] ,
sizeof( V_417 -> V_171 ) ) ;
memset ( V_417 -> V_88 , 0 ,
sizeof( V_417 -> V_88 ) ) ;
F_199 ( V_22 , V_72 , V_417 -> V_88 , 8 ,
sizeof( V_417 -> V_88 ) ) ;
if ( V_417 -> V_104 == V_106 &&
F_31 ( V_72 ) ) {
int V_198 ;
F_181 ( V_22 , V_72 , & V_417 -> V_83 ) ;
if ( V_22 -> V_478 & V_479 )
F_195 ( V_22 , V_72 , V_417 ) ;
V_198 = F_204 ( V_22 , V_72 ) ;
if ( V_198 < 0 || V_198 > 0xff )
V_198 = V_205 ;
V_417 -> V_198 = V_198 & 0xff ;
} else {
V_417 -> V_83 = V_84 ;
V_417 -> V_172 = 0 ;
V_417 -> V_89 = 0 ;
V_417 -> V_181 = 0 ;
V_417 -> V_186 = 0 ;
V_417 -> V_198 = 0 ;
V_417 -> V_188 = V_22 -> V_235 ;
}
if ( V_474 ) {
V_476 = & V_475 [ F_211 ] ;
* V_474 = ( V_417 -> V_104 == V_167 &&
strncmp ( V_476 , F_212 ,
F_213 ) == 0 ) ;
}
F_80 ( V_475 ) ;
return 0 ;
V_477:
F_80 ( V_475 ) ;
return V_21 ;
}
static void F_215 ( struct V_1 * V_22 ,
struct V_73 * V_30 , T_1 * V_72 )
{
unsigned long V_78 ;
int V_21 , V_182 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_21 = F_83 ( V_30 , V_22 -> V_30 , V_22 -> V_160 , & V_182 ) ;
if ( ( V_21 == F_86 || V_21 == F_87 ) &&
V_182 >= 0 && V_182 < V_22 -> V_160 ) {
V_30 -> V_480 = V_22 -> V_30 [ V_182 ] -> V_480 ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_96 , V_78 ) ;
V_30 -> V_480 =
F_208 ( V_22 , V_72 ) ;
if ( V_30 -> V_480 < 0 )
V_30 -> V_480 = 0 ;
}
}
static void F_216 ( struct V_1 * V_22 ,
T_1 * V_481 , struct V_73 * V_42 )
{
T_4 V_86 = F_135 ( V_481 ) ;
if ( ! F_31 ( V_481 ) ) {
if ( F_62 ( V_481 ) )
F_202 ( V_42 ,
V_482 , 0 , V_86 & 0x3fff ) ;
else
F_202 ( V_42 ,
V_245 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_165 ) {
F_202 ( V_42 ,
V_483 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_202 ( V_42 , V_484 ,
0 , V_86 & 0x3fff ) ;
}
static int F_217 ( struct V_1 * V_22 ,
struct V_8 * V_485 , unsigned char * V_72 )
{
struct V_137 * V_279 =
& V_22 -> V_135 [ V_485 -> V_131 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_185 == F_124 ( V_279 -> V_486 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 0 ;
}
static int F_218 ( struct V_1 * V_22 , int V_487 ,
int V_68 , int V_440 , int V_488 )
{
int V_489 = V_440 + ( V_487 == 0 ) ;
if ( V_68 == V_487 )
return 0 ;
if ( V_68 < V_489 )
return 0 ;
if ( ( V_68 - V_440 - ( V_487 == 0 ) ) < V_488 )
return 0 ;
return 1 ;
}
static int F_219 ( struct V_1 * V_22 ,
struct V_426 * V_439 , T_4 * V_440 ,
struct V_458 * V_490 , T_4 * V_491 )
{
if ( F_190 ( V_22 , V_439 , sizeof( * V_439 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
return - 1 ;
}
* V_440 = F_220 ( * ( ( V_492 * ) V_439 -> V_442 ) ) / 24 ;
if ( * V_440 > V_493 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_148 ,
V_493 , * V_440 - V_493 ) ;
* V_440 = V_493 ;
}
if ( F_201 ( V_22 , V_490 , sizeof( * V_490 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_149 ) ;
return - 1 ;
}
* V_491 = F_220 ( * ( ( V_492 * ) V_490 -> V_442 ) ) / 8 ;
if ( * V_491 > V_494 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_150
L_151 , V_494 ,
* V_491 - V_494 ) ;
* V_491 = V_494 ;
}
if ( * V_491 + * V_440 > V_493 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_152
L_151 , V_493 ,
* V_440 + * V_491 - V_493 ) ;
* V_491 = V_493 - * V_440 ;
}
return 0 ;
}
static T_1 * F_221 ( struct V_1 * V_22 , int V_487 ,
int V_68 , int V_440 , int V_491 ,
struct V_426 * V_495 ,
struct V_458 * V_496 )
{
int V_489 = V_440 + ( V_487 == 0 ) ;
int V_497 = V_440 + V_491 + ( V_487 == 0 ) ;
if ( V_68 == V_487 )
return V_156 ;
if ( V_68 < V_489 )
return & V_495 -> V_343 [ V_68 -
( V_487 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_497 )
return & V_496 -> V_343 [ V_68 - V_440 -
( V_487 == 0 ) ] [ 0 ] ;
F_175 () ;
return NULL ;
}
static void F_222 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_426 * V_427 , int V_428 ,
struct V_424 * V_432 )
{
int V_21 ;
struct V_433 * V_434 = & V_427 -> V_343 [ V_428 ] ;
V_30 -> V_185 = V_434 -> V_185 ;
if ( ( V_434 -> V_498 & 0x08 ) && V_30 -> V_185 )
V_30 -> V_186 = 1 ;
memset ( V_432 , 0 , sizeof( * V_432 ) ) ;
V_21 = F_186 ( V_22 , & V_434 -> V_86 [ 0 ] ,
F_188 ( & V_434 -> V_86 [ 0 ] ) , V_432 ,
sizeof( * V_432 ) ) ;
if ( ! V_21 )
#define F_223 2
#define F_224 7
V_30 -> V_188 =
F_96 ( V_432 -> V_499 ) -
F_223 ;
else
V_30 -> V_188 = F_224 ;
}
static void F_225 ( struct V_73 * V_417 ,
struct V_426 * V_427 , int V_428 ,
struct V_424 * V_432 )
{
struct V_433 * V_434 = & V_427 -> V_343 [ V_428 ] ;
if ( ( V_434 -> V_498 & 0x08 ) && V_417 -> V_185 )
V_417 -> V_186 = 1 ;
memcpy ( & V_417 -> V_98 ,
& V_432 -> V_437 ,
sizeof( V_417 -> V_98 ) ) ;
memcpy ( & V_417 -> V_99 ,
& V_432 -> V_500 ,
sizeof( V_417 -> V_99 ) ) ;
memcpy ( & V_417 -> V_91 ,
& V_432 -> V_501 ,
sizeof( V_417 -> V_91 ) ) ;
memcpy ( & V_417 -> V_95 ,
& V_432 -> V_502 ,
sizeof( V_417 -> V_95 ) ) ;
memcpy ( & V_417 -> V_92 ,
& V_432 -> V_503 ,
sizeof( V_417 -> V_92 ) ) ;
}
static int F_226 ( struct V_1 * V_22 ,
struct V_422 * V_504 ,
T_4 * V_505 )
{
int V_21 ;
if ( ! V_504 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_153 ,
V_202 ) ;
return - V_255 ;
}
memset ( V_504 , 0 , sizeof( * V_504 ) ) ;
V_21 = F_185 ( V_22 , V_504 , sizeof( * V_504 ) ) ;
if ( ! V_21 )
if ( V_504 -> V_506 < 256 )
* V_505 = V_504 -> V_506 ;
else
* V_505 = F_96 (
V_504 -> V_507 ) ;
else
* V_505 = - 1 ;
return V_21 ;
}
static void F_227 ( struct V_1 * V_22 )
{
struct V_426 * V_495 = NULL ;
struct V_458 * V_496 = NULL ;
struct V_424 * V_432 = NULL ;
struct V_422 * V_504 = NULL ;
T_4 V_440 = 0 ;
T_4 V_491 = 0 ;
T_4 V_488 = 0 ;
T_4 V_508 = 0 ;
struct V_73 * * V_509 , * V_417 , * V_510 ;
int V_511 = 0 ;
int V_68 , V_512 , V_513 ;
int V_487 ;
bool V_74 ;
F_65 ( V_514 , V_515 ) ;
V_509 = F_108 ( sizeof( * V_509 ) * V_159 , V_201 ) ;
V_495 = F_108 ( sizeof( * V_495 ) , V_201 ) ;
V_496 = F_108 ( sizeof( * V_496 ) , V_201 ) ;
V_510 = F_108 ( sizeof( * V_510 ) , V_201 ) ;
V_432 = F_108 ( sizeof( * V_432 ) , V_201 ) ;
V_504 = F_108 ( sizeof( * V_504 ) , V_201 ) ;
if ( ! V_509 || ! V_495 || ! V_496 ||
! V_510 || ! V_432 || ! V_504 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_154 ) ;
goto V_388;
}
memset ( V_514 , 0 , sizeof( V_514 ) ) ;
V_22 -> V_243 = 0 ;
if ( F_219 ( V_22 , V_495 , & V_440 ,
V_496 , & V_491 ) ) {
V_22 -> V_243 = 1 ;
goto V_388;
}
if ( F_226 ( V_22 , V_504 , & V_488 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_155 ,
V_202 ) ;
}
V_513 = V_440 + V_491 + V_515 + 1 ;
for ( V_68 = 0 ; V_68 < V_513 ; V_68 ++ ) {
if ( V_68 >= V_159 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_156
L_157 , V_159 ,
V_513 - V_159 ) ;
break;
}
V_509 [ V_68 ] = F_108 ( sizeof( * V_509 [ V_68 ] ) , V_201 ) ;
if ( ! V_509 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_158 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_243 = 1 ;
goto V_388;
}
V_508 ++ ;
}
if ( F_63 ( V_22 ) )
V_487 = 0 ;
else
V_487 = V_440 + V_491 ;
V_512 = 0 ;
for ( V_68 = 0 ; V_68 < V_440 + V_491 + 1 ; V_68 ++ ) {
T_1 * V_481 , V_516 = 0 ;
int V_21 = 0 ;
int V_517 = V_68 - ( V_487 == 0 ) ;
V_74 = V_68 < V_440 + ( V_487 == 0 ) ;
V_481 = F_221 ( V_22 , V_487 ,
V_68 , V_440 , V_491 , V_495 , V_496 ) ;
if ( F_228 ( V_481 ) && V_74 &&
( V_495 -> V_343 [ V_517 ] . V_518 != 0x06 ) &&
( V_495 -> V_343 [ V_517 ] . V_498 & 0x01 ) )
continue;
V_21 = F_210 ( V_22 , V_481 , V_510 ,
& V_516 ) ;
if ( V_21 == - V_255 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_159 ) ;
V_22 -> V_243 = 1 ;
goto V_388;
}
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_160 ) ;
continue;
}
V_510 -> V_165 =
F_218 ( V_22 , V_487 , V_68 ,
V_440 , V_488 ) ;
F_216 ( V_22 , V_481 , V_510 ) ;
F_215 ( V_22 , V_510 , V_481 ) ;
V_417 = V_509 [ V_511 ] ;
if ( ! V_22 -> V_519 ) {
if ( V_510 -> V_165 ) {
V_22 -> V_519 = 1 ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_161 ) ;
}
}
* V_417 = * V_510 ;
V_417 -> V_74 = V_74 ;
if ( F_228 ( V_481 ) && V_417 -> V_74 )
V_417 -> V_107 = 0 ;
else
V_417 -> V_107 = 1 ;
if ( V_417 -> V_74 && V_417 -> V_107 )
F_193 ( V_22 , V_481 , V_417 ) ;
switch ( V_417 -> V_104 ) {
case V_167 :
if ( V_516 )
V_511 ++ ;
break;
case V_106 :
if ( V_417 -> V_74 ) {
V_417 -> V_89 = 0 ;
F_222 ( V_22 , V_417 ,
V_495 , V_517 , V_432 ) ;
F_225 ( V_417 ,
V_495 , V_517 , V_432 ) ;
}
V_511 ++ ;
break;
case V_168 :
case V_169 :
V_511 ++ ;
break;
case V_164 :
F_187 ( V_22 , V_481 ,
V_495 , V_517 ,
V_417 ) ;
V_511 ++ ;
break;
case V_105 :
if ( ! F_62 ( V_481 ) )
break;
V_511 ++ ;
break;
default:
break;
}
if ( V_511 >= V_159 )
break;
}
if ( V_22 -> V_236 == NULL ) {
int V_21 = 0 ;
V_21 = F_229 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_162 , V_21 ) ;
goto V_388;
}
}
F_107 ( V_22 , V_509 , V_511 ) ;
V_388:
F_80 ( V_510 ) ;
for ( V_68 = 0 ; V_68 < V_508 ; V_68 ++ )
F_80 ( V_509 [ V_68 ] ) ;
F_80 ( V_509 ) ;
F_80 ( V_495 ) ;
F_80 ( V_496 ) ;
F_80 ( V_504 ) ;
F_80 ( V_432 ) ;
}
static void F_230 ( struct V_268 * V_520 ,
struct V_521 * V_263 )
{
T_5 V_368 = ( T_5 ) F_231 ( V_263 ) ;
unsigned int V_50 = F_232 ( V_263 ) ;
V_520 -> V_276 = F_127 ( V_368 ) ;
V_520 -> V_275 = F_132 ( V_50 ) ;
V_520 -> V_272 = 0 ;
}
static int F_233 ( struct V_1 * V_22 ,
struct V_8 * V_129 ,
struct V_277 * V_278 )
{
struct V_521 * V_263 ;
int V_522 , V_68 , V_523 , V_524 , V_525 ;
struct V_268 * V_526 ;
F_75 ( F_152 ( V_278 ) > V_22 -> V_256 ) ;
V_522 = F_234 ( V_278 ) ;
if ( V_522 < 0 )
return V_522 ;
if ( ! V_522 )
goto V_527;
V_526 = V_129 -> V_270 ;
V_524 = V_522 > V_22 -> V_271 ;
V_523 = V_524 ? V_22 -> V_271 - 1 : V_522 ;
V_525 = F_152 ( V_278 ) - 1 ;
F_235 (cmd, sg, sg_limit, i) {
F_230 ( V_526 , V_263 ) ;
V_526 ++ ;
}
if ( V_524 ) {
V_526 = V_22 -> V_258 [ V_129 -> V_131 ] ;
V_523 = V_522 - V_523 ;
F_236 (sg, sg, sg_limit, i) {
F_230 ( V_526 , V_263 ) ;
V_526 ++ ;
}
}
( V_526 - 1 ) -> V_272 = F_132 ( V_370 ) ;
if ( V_522 + V_524 > V_22 -> V_528 )
V_22 -> V_528 = V_522 + V_524 ;
if ( V_524 ) {
V_129 -> V_122 . V_123 = V_22 -> V_271 ;
V_129 -> V_122 . V_274 = F_153 ( V_522 + 1 ) ;
if ( F_131 ( V_22 , V_129 ) ) {
F_151 ( V_278 ) ;
return - 1 ;
}
return 0 ;
}
V_527:
V_129 -> V_122 . V_123 = ( T_1 ) V_522 ;
V_129 -> V_122 . V_274 = F_153 ( V_522 ) ;
return 0 ;
}
static int F_237 ( T_1 * V_139 , int * V_529 )
{
int V_530 = 0 ;
T_4 V_531 ;
T_4 V_532 ;
switch ( V_139 [ 0 ] ) {
case V_533 :
case V_534 :
V_530 = 1 ;
case V_535 :
case V_536 :
if ( * V_529 == 6 ) {
V_531 = F_238 ( & V_139 [ 2 ] ) ;
V_532 = V_139 [ 4 ] ;
if ( V_532 == 0 )
V_532 = 256 ;
} else {
F_75 ( * V_529 != 12 ) ;
V_531 = F_191 ( & V_139 [ 2 ] ) ;
V_532 = F_191 ( & V_139 [ 6 ] ) ;
}
if ( V_532 > 0xffff )
return V_537 ;
V_139 [ 0 ] = V_530 ? V_538 : V_539 ;
V_139 [ 1 ] = 0 ;
V_139 [ 2 ] = ( T_1 ) ( V_531 >> 24 ) ;
V_139 [ 3 ] = ( T_1 ) ( V_531 >> 16 ) ;
V_139 [ 4 ] = ( T_1 ) ( V_531 >> 8 ) ;
V_139 [ 5 ] = ( T_1 ) ( V_531 ) ;
V_139 [ 6 ] = 0 ;
V_139 [ 7 ] = ( T_1 ) ( V_532 >> 8 ) ;
V_139 [ 8 ] = ( T_1 ) ( V_532 ) ;
V_139 [ 9 ] = 0 ;
* V_529 = 10 ;
break;
}
return 0 ;
}
static int F_239 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_139 , int V_529 ,
T_1 * V_72 , struct V_73 * V_234 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_128 * V_129 = & V_22 -> V_130 [ V_9 -> V_131 ] ;
unsigned int V_50 ;
unsigned int V_540 = 0 ;
struct V_521 * V_263 ;
T_5 V_368 ;
int V_522 , V_68 ;
struct V_268 * V_526 ;
T_4 V_541 = V_542 ;
if ( F_152 ( V_278 ) > V_22 -> V_543 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_537 ;
}
F_75 ( V_278 -> V_544 > V_545 ) ;
if ( F_237 ( V_139 , & V_529 ) ) {
F_45 ( & V_234 -> V_250 ) ;
return V_537 ;
}
V_9 -> V_148 = V_149 ;
V_9 -> V_120 = ( T_4 ) V_22 -> V_546 +
( V_9 -> V_131 * sizeof( * V_129 ) ) ;
F_75 ( V_9 -> V_120 & 0x0000007F ) ;
V_522 = F_234 ( V_278 ) ;
if ( V_522 < 0 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_522 ;
}
if ( V_522 ) {
V_526 = V_129 -> V_270 ;
F_235 (cmd, sg, use_sg, i) {
V_368 = ( T_5 ) F_231 ( V_263 ) ;
V_50 = F_232 ( V_263 ) ;
V_540 += V_50 ;
V_526 -> V_276 = F_127 ( V_368 ) ;
V_526 -> V_275 = F_132 ( V_50 ) ;
V_526 -> V_272 = F_132 ( 0 ) ;
V_526 ++ ;
}
( -- V_526 ) -> V_272 = F_132 ( V_370 ) ;
switch ( V_278 -> V_547 ) {
case V_548 :
V_541 |= V_549 ;
break;
case V_550 :
V_541 |= V_551 ;
break;
case V_552 :
V_541 |= V_553 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_278 -> V_547 ) ;
F_175 () ;
break;
}
} else {
V_541 |= V_553 ;
}
V_9 -> V_122 . V_123 = V_522 ;
V_129 -> V_554 = F_153 ( V_185 & 0xFFFF ) ;
V_129 -> V_555 = F_132 ( V_540 ) ;
V_129 -> V_340 = F_153 ( V_556 |
( V_529 & V_341 ) ) ;
V_129 -> V_541 = F_132 ( V_541 ) ;
memcpy ( V_129 -> V_143 , V_139 , V_529 ) ;
memcpy ( V_129 -> V_345 , V_72 , 8 ) ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
V_9 -> V_234 = V_30 ;
return F_241 ( V_22 , V_9 , V_30 -> V_185 ,
V_278 -> V_557 , V_278 -> V_544 , V_30 -> V_72 , V_30 ) ;
}
static void F_242 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_137 * V_129 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
struct V_219 * V_220 = & V_30 -> V_184 ;
T_5 V_558 ;
if ( ! ( F_96 ( V_220 -> V_78 ) & V_414 ) )
return;
V_129 -> V_415 = V_220 -> V_415 ;
V_129 -> V_559 |= V_560 ;
switch ( V_278 -> V_557 [ 0 ] ) {
case V_533 :
case V_535 :
V_558 = F_238 ( & V_278 -> V_557 [ 2 ] ) ;
break;
case V_538 :
case V_539 :
case V_534 :
case V_536 :
V_558 = F_191 ( & V_278 -> V_557 [ 2 ] ) ;
break;
case V_561 :
case V_562 :
V_558 = F_192 ( & V_278 -> V_557 [ 2 ] ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_164 ,
V_202 , V_278 -> V_557 [ 0 ] ) ;
F_175 () ;
break;
}
if ( F_124 ( V_220 -> V_407 ) != 512 )
V_558 = V_558 *
F_124 ( V_220 -> V_407 ) / 512 ;
V_129 -> V_563 = F_132 ( V_558 ) ;
V_129 -> V_564 = F_132 ( V_558 >> 32 ) ;
}
static int F_243 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_139 , int V_529 ,
T_1 * V_72 , struct V_73 * V_234 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_137 * V_129 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
struct V_259 * V_526 ;
int V_522 , V_68 ;
struct V_521 * V_263 ;
T_5 V_368 ;
T_4 V_50 ;
T_4 V_540 = 0 ;
F_75 ( F_152 ( V_278 ) > V_22 -> V_256 ) ;
if ( F_237 ( V_139 , & V_529 ) ) {
F_45 ( & V_234 -> V_250 ) ;
return V_537 ;
}
V_9 -> V_148 = V_152 ;
V_9 -> V_120 = ( T_4 ) V_22 -> V_565 +
( V_9 -> V_131 * sizeof( * V_129 ) ) ;
F_75 ( V_9 -> V_120 & 0x0000007F ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_566 = V_567 ;
V_522 = F_234 ( V_278 ) ;
if ( V_522 < 0 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_522 ;
}
if ( V_522 ) {
V_526 = V_129 -> V_263 ;
if ( V_522 > V_22 -> V_543 ) {
V_368 = F_129 (
V_22 -> V_253 [ V_9 -> V_131 ] -> V_266 ) ;
V_526 -> V_266 = F_127 ( V_368 ) ;
V_526 -> V_264 = 0 ;
V_526 -> V_568 [ 0 ] = 0 ;
V_526 -> V_568 [ 1 ] = 0 ;
V_526 -> V_568 [ 2 ] = 0 ;
V_526 -> V_334 = 0x80 ;
V_526 = V_22 -> V_253 [ V_9 -> V_131 ] ;
}
F_235 (cmd, sg, use_sg, i) {
V_368 = ( T_5 ) F_231 ( V_263 ) ;
V_50 = F_232 ( V_263 ) ;
V_540 += V_50 ;
V_526 -> V_266 = F_127 ( V_368 ) ;
V_526 -> V_264 = F_132 ( V_50 ) ;
V_526 -> V_568 [ 0 ] = 0 ;
V_526 -> V_568 [ 1 ] = 0 ;
V_526 -> V_568 [ 2 ] = 0 ;
V_526 -> V_334 = 0 ;
V_526 ++ ;
}
switch ( V_278 -> V_547 ) {
case V_548 :
V_129 -> V_559 &= ~ V_569 ;
V_129 -> V_559 |= V_570 ;
break;
case V_550 :
V_129 -> V_559 &= ~ V_569 ;
V_129 -> V_559 |= V_571 ;
break;
case V_552 :
V_129 -> V_559 &= ~ V_569 ;
V_129 -> V_559 |= V_572 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_278 -> V_547 ) ;
F_175 () ;
break;
}
} else {
V_129 -> V_559 &= ~ V_569 ;
V_129 -> V_559 |= V_572 ;
}
F_242 ( V_22 , V_9 , V_129 ) ;
V_129 -> V_486 = F_132 ( V_185 ) ;
V_129 -> V_573 = F_132 ( V_9 -> V_131 << V_574 ) ;
memcpy ( V_129 -> V_139 , V_139 , sizeof( V_129 -> V_139 ) ) ;
V_129 -> V_280 = F_132 ( V_540 ) ;
V_129 -> V_575 = F_127 ( V_9 -> V_120 +
F_244 ( struct V_137 , V_283 ) ) ;
V_129 -> V_576 = F_132 ( sizeof( V_129 -> V_283 ) ) ;
if ( V_522 > V_22 -> V_543 ) {
V_129 -> V_138 = 1 ;
V_129 -> V_263 [ 0 ] . V_264 = F_132 ( V_522 * sizeof( V_129 -> V_263 [ 0 ] ) ) ;
if ( F_123 ( V_22 , V_129 , V_9 ) ) {
F_45 ( & V_234 -> V_250 ) ;
F_151 ( V_278 ) ;
return - 1 ;
}
} else
V_129 -> V_138 = ( T_1 ) V_522 ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_241 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_139 , int V_529 ,
T_1 * V_72 , struct V_73 * V_234 )
{
if ( F_178 ( & V_234 -> V_250 ) >
V_234 -> V_188 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_537 ;
}
if ( V_22 -> V_63 & V_112 )
return F_239 ( V_22 , V_9 , V_185 ,
V_139 , V_529 , V_72 ,
V_234 ) ;
else
return F_243 ( V_22 , V_9 , V_185 ,
V_139 , V_529 , V_72 ,
V_234 ) ;
}
static void F_245 ( struct V_219 * V_220 ,
int V_187 , T_4 * V_577 , T_4 * V_578 )
{
if ( V_187 == 0 ) {
* V_577 %= F_96 ( V_220 -> V_225 ) ;
return;
}
do {
* V_578 = * V_577 /
F_96 ( V_220 -> V_225 ) ;
if ( V_187 == * V_578 )
continue;
if ( * V_578 < F_96 ( V_220 -> V_229 ) - 1 ) {
* V_577 += F_96 ( V_220 -> V_225 ) ;
( * V_578 ) ++ ;
} else {
* V_577 %= F_96 ( V_220 -> V_225 ) ;
* V_578 = 0 ;
}
} while ( V_187 != * V_578 );
}
static int F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
struct V_219 * V_220 = & V_30 -> V_184 ;
struct V_221 * V_222 = & V_220 -> V_223 [ 0 ] ;
int V_530 = 0 ;
T_4 V_577 ;
T_5 V_558 , V_579 ;
T_4 V_532 ;
T_4 V_580 ;
T_5 V_581 , V_582 ;
T_4 V_583 , V_584 ;
T_4 V_585 , V_586 ;
T_5 V_587 , V_588 ;
T_4 V_589 ;
T_5 V_590 , V_591 ;
T_4 V_592 , V_593 ;
T_4 V_594 , V_595 ;
T_4 V_224 ;
T_4 V_596 ;
T_4 V_597 , V_598 , V_578 ;
T_4 V_599 ;
T_4 V_600 ;
T_5 V_601 ;
T_4 V_602 ;
T_1 V_139 [ 16 ] ;
T_1 V_529 ;
T_6 V_411 ;
#if V_603 == 32
T_5 V_604 ;
#endif
int V_187 ;
switch ( V_278 -> V_557 [ 0 ] ) {
case V_533 :
V_530 = 1 ;
case V_535 :
V_558 = F_238 ( & V_278 -> V_557 [ 2 ] ) ;
V_532 = V_278 -> V_557 [ 4 ] ;
if ( V_532 == 0 )
V_532 = 256 ;
break;
case V_538 :
V_530 = 1 ;
case V_539 :
V_558 =
( ( ( T_5 ) V_278 -> V_557 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_557 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_557 [ 4 ] ) << 8 ) |
V_278 -> V_557 [ 5 ] ;
V_532 =
( ( ( T_4 ) V_278 -> V_557 [ 7 ] ) << 8 ) |
V_278 -> V_557 [ 8 ] ;
break;
case V_534 :
V_530 = 1 ;
case V_536 :
V_558 =
( ( ( T_5 ) V_278 -> V_557 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_557 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_557 [ 4 ] ) << 8 ) |
V_278 -> V_557 [ 5 ] ;
V_532 =
( ( ( T_4 ) V_278 -> V_557 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_278 -> V_557 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_278 -> V_557 [ 8 ] ) << 8 ) |
V_278 -> V_557 [ 9 ] ;
break;
case V_561 :
V_530 = 1 ;
case V_562 :
V_558 =
( ( ( T_5 ) V_278 -> V_557 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_278 -> V_557 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_278 -> V_557 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_278 -> V_557 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_278 -> V_557 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_557 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_557 [ 8 ] ) << 8 ) |
V_278 -> V_557 [ 9 ] ;
V_532 =
( ( ( T_4 ) V_278 -> V_557 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_278 -> V_557 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_278 -> V_557 [ 12 ] ) << 8 ) |
V_278 -> V_557 [ 13 ] ;
break;
default:
return V_537 ;
}
V_579 = V_558 + V_532 - 1 ;
if ( V_530 && V_30 -> V_83 != 0 )
return V_537 ;
if ( V_579 >= F_129 ( V_220 -> V_408 ) ||
V_579 < V_558 )
return V_537 ;
V_580 = F_96 ( V_220 -> V_225 ) *
F_96 ( V_220 -> V_411 ) ;
V_411 = F_96 ( V_220 -> V_411 ) ;
#if V_603 == 32
V_604 = V_558 ;
( void ) F_247 ( V_604 , V_580 ) ;
V_581 = V_604 ;
V_604 = V_579 ;
( void ) F_247 ( V_604 , V_580 ) ;
V_582 = V_604 ;
V_583 = ( T_4 ) ( V_558 - ( V_581 * V_580 ) ) ;
V_584 = ( T_4 ) ( V_579 - ( V_582 * V_580 ) ) ;
V_604 = V_583 ;
( void ) F_247 ( V_604 , V_411 ) ;
V_585 = V_604 ;
V_604 = V_584 ;
( void ) F_247 ( V_604 , V_411 ) ;
V_586 = V_604 ;
#else
V_581 = V_558 / V_580 ;
V_582 = V_579 / V_580 ;
V_583 = ( T_4 ) ( V_558 - ( V_581 * V_580 ) ) ;
V_584 = ( T_4 ) ( V_579 - ( V_582 * V_580 ) ) ;
V_585 = V_583 / V_411 ;
V_586 = V_584 / V_411 ;
#endif
if ( ( V_581 != V_582 ) || ( V_585 != V_586 ) )
return V_537 ;
V_224 = F_96 ( V_220 -> V_225 ) +
F_96 ( V_220 -> V_226 ) ;
V_599 = ( ( T_4 ) ( V_581 >> V_220 -> V_410 ) ) %
F_96 ( V_220 -> V_228 ) ;
V_577 = ( V_599 * V_224 ) + V_585 ;
switch ( V_30 -> V_83 ) {
case V_605 :
break;
case V_606 :
F_75 ( F_96 ( V_220 -> V_229 ) != 2 ) ;
if ( V_30 -> V_187 )
V_577 += F_96 ( V_220 -> V_225 ) ;
V_30 -> V_187 = ! V_30 -> V_187 ;
break;
case V_607 :
F_75 ( F_96 ( V_220 -> V_229 ) != 3 ) ;
V_187 = V_30 -> V_187 ;
F_245 ( V_220 , V_187 ,
& V_577 , & V_578 ) ;
V_187 =
( V_187 >=
F_96 ( V_220 -> V_229 ) - 1 )
? 0 : V_187 + 1 ;
V_30 -> V_187 = V_187 ;
break;
case V_608 :
case V_609 :
if ( F_96 ( V_220 -> V_229 ) <= 1 )
break;
V_589 =
F_96 ( V_220 -> V_411 ) *
F_96 ( V_220 -> V_225 ) ;
F_75 ( V_589 == 0 ) ;
V_596 = V_589 *
F_96 ( V_220 -> V_229 ) ;
#if V_603 == 32
V_604 = V_558 ;
V_597 = F_247 ( V_604 , V_596 ) ;
V_604 = V_597 ;
( void ) F_247 ( V_604 , V_589 ) ;
V_597 = V_604 ;
V_604 = V_579 ;
V_598 = F_247 ( V_604 , V_596 ) ;
V_604 = V_598 ;
( void ) F_247 ( V_604 , V_589 ) ;
V_598 = V_604 ;
#else
V_597 = ( V_558 % V_596 ) / V_589 ;
V_598 = ( V_579 % V_596 ) / V_589 ;
#endif
if ( V_597 != V_598 )
return V_537 ;
#if V_603 == 32
V_604 = V_558 ;
( void ) F_247 ( V_604 , V_596 ) ;
V_581 = V_590 = V_587 = V_604 ;
V_604 = V_579 ;
( void ) F_247 ( V_604 , V_596 ) ;
V_591 = V_588 = V_604 ;
#else
V_581 = V_590 = V_587 =
V_558 / V_596 ;
V_591 = V_588 = V_579 / V_596 ;
#endif
if ( V_590 != V_591 )
return V_537 ;
#if V_603 == 32
V_604 = V_558 ;
V_583 = F_247 ( V_604 , V_596 ) ;
V_604 = V_583 ;
V_583 = ( T_4 ) F_247 ( V_604 , V_589 ) ;
V_592 = V_583 ;
V_604 = V_579 ;
V_593 = F_247 ( V_604 , V_596 ) ;
V_604 = V_593 ;
V_593 = F_247 ( V_604 , V_589 ) ;
V_604 = V_592 ;
( void ) F_247 ( V_604 , V_220 -> V_411 ) ;
V_585 = V_594 = V_604 ;
V_604 = V_593 ;
( void ) F_247 ( V_604 , V_220 -> V_411 ) ;
V_595 = V_604 ;
#else
V_583 = V_592 =
( T_4 ) ( ( V_558 % V_596 ) %
V_589 ) ;
V_593 =
( T_4 ) ( ( V_579 % V_596 ) %
V_589 ) ;
V_585 = V_594 =
V_592 / F_96 ( V_220 -> V_411 ) ;
V_595 =
V_593 / F_96 ( V_220 -> V_411 ) ;
#endif
if ( V_594 != V_595 )
return V_537 ;
V_599 = ( ( T_4 ) ( V_581 >> V_220 -> V_410 ) ) %
F_96 ( V_220 -> V_228 ) ;
V_577 = ( V_597 *
( F_96 ( V_220 -> V_228 ) * V_224 ) ) +
( V_599 * V_224 ) + V_585 ;
break;
default:
return V_537 ;
}
if ( F_44 ( V_577 >= V_232 ) )
return V_537 ;
V_9 -> V_234 = V_30 -> V_234 [ V_577 ] ;
V_600 = V_222 [ V_577 ] . V_185 ;
V_601 = F_129 ( V_220 -> V_412 ) +
V_581 * F_96 ( V_220 -> V_411 ) +
( V_583 - V_585 *
F_96 ( V_220 -> V_411 ) ) ;
V_602 = V_532 ;
if ( V_220 -> V_409 ) {
V_601 <<= V_220 -> V_409 ;
V_602 <<= V_220 -> V_409 ;
}
F_75 ( V_602 > 0xffff ) ;
if ( V_601 > 0xffffffff ) {
V_139 [ 0 ] = V_530 ? V_561 : V_562 ;
V_139 [ 1 ] = 0 ;
V_139 [ 2 ] = ( T_1 ) ( V_601 >> 56 ) ;
V_139 [ 3 ] = ( T_1 ) ( V_601 >> 48 ) ;
V_139 [ 4 ] = ( T_1 ) ( V_601 >> 40 ) ;
V_139 [ 5 ] = ( T_1 ) ( V_601 >> 32 ) ;
V_139 [ 6 ] = ( T_1 ) ( V_601 >> 24 ) ;
V_139 [ 7 ] = ( T_1 ) ( V_601 >> 16 ) ;
V_139 [ 8 ] = ( T_1 ) ( V_601 >> 8 ) ;
V_139 [ 9 ] = ( T_1 ) ( V_601 ) ;
V_139 [ 10 ] = ( T_1 ) ( V_602 >> 24 ) ;
V_139 [ 11 ] = ( T_1 ) ( V_602 >> 16 ) ;
V_139 [ 12 ] = ( T_1 ) ( V_602 >> 8 ) ;
V_139 [ 13 ] = ( T_1 ) ( V_602 ) ;
V_139 [ 14 ] = 0 ;
V_139 [ 15 ] = 0 ;
V_529 = 16 ;
} else {
V_139 [ 0 ] = V_530 ? V_538 : V_539 ;
V_139 [ 1 ] = 0 ;
V_139 [ 2 ] = ( T_1 ) ( V_601 >> 24 ) ;
V_139 [ 3 ] = ( T_1 ) ( V_601 >> 16 ) ;
V_139 [ 4 ] = ( T_1 ) ( V_601 >> 8 ) ;
V_139 [ 5 ] = ( T_1 ) ( V_601 ) ;
V_139 [ 6 ] = 0 ;
V_139 [ 7 ] = ( T_1 ) ( V_602 >> 8 ) ;
V_139 [ 8 ] = ( T_1 ) ( V_602 ) ;
V_139 [ 9 ] = 0 ;
V_529 = 10 ;
}
return F_241 ( V_22 , V_9 , V_600 , V_139 , V_529 ,
V_30 -> V_72 ,
V_30 -> V_234 [ V_577 ] ) ;
}
static int F_248 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
unsigned char V_72 [] )
{
V_278 -> V_610 = ( unsigned char * ) V_9 ;
V_9 -> V_148 = V_333 ;
V_9 -> V_10 = V_278 ;
V_9 -> V_122 . V_126 = 0 ;
memcpy ( & V_9 -> V_122 . V_343 . V_344 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_122 . V_342 = F_127 ( ( V_9 -> V_131 << V_574 ) ) ;
V_9 -> V_142 . V_611 = 0 ;
F_75 ( V_278 -> V_544 > sizeof( V_9 -> V_142 . V_143 ) ) ;
V_9 -> V_142 . V_339 = V_278 -> V_544 ;
memcpy ( V_9 -> V_142 . V_143 , V_278 -> V_557 , V_278 -> V_544 ) ;
switch ( V_278 -> V_547 ) {
case V_548 :
V_9 -> V_142 . V_612 =
F_249 ( V_387 , V_613 , V_614 ) ;
break;
case V_550 :
V_9 -> V_142 . V_612 =
F_249 ( V_387 , V_613 , V_615 ) ;
break;
case V_552 :
V_9 -> V_142 . V_612 =
F_249 ( V_387 , V_613 , V_616 ) ;
break;
case V_617 :
V_9 -> V_142 . V_612 =
F_249 ( V_387 , V_613 , V_618 ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_278 -> V_547 ) ;
F_175 () ;
break;
}
if ( F_233 ( V_22 , V_9 , V_278 ) < 0 ) {
F_140 ( V_22 , V_9 ) ;
return V_619 ;
}
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_250 ( struct V_1 * V_22 , int V_197 ,
struct V_8 * V_9 )
{
V_366 V_620 , V_621 ;
memset ( V_9 , 0 , F_244 ( struct V_8 , V_399 ) ) ;
V_9 -> V_122 . V_342 = F_127 ( ( T_5 ) ( V_197 << V_574 ) ) ;
V_620 = V_22 -> V_622 + V_197 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_623 + V_197 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_621 = V_22 -> V_624
+ V_197 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_131 = V_197 ;
V_9 -> V_120 = ( T_4 ) V_620 ;
V_9 -> V_625 . V_276 = F_127 ( ( T_5 ) V_621 ) ;
V_9 -> V_625 . V_275 = F_132 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_251 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_398 + V_68 ;
F_250 ( V_22 , V_68 , V_9 ) ;
F_115 ( & V_9 -> V_399 , 0 ) ;
}
}
static inline void F_252 ( struct V_1 * V_22 , int V_197 ,
struct V_8 * V_9 )
{
V_366 V_620 = V_22 -> V_622 + V_197 * sizeof( * V_9 ) ;
F_75 ( V_9 -> V_131 != V_197 ) ;
memset ( V_9 -> V_142 . V_143 , 0 , sizeof( V_9 -> V_142 . V_143 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_120 = ( T_4 ) V_620 ;
}
static int F_253 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
int V_21 = V_537 ;
V_278 -> V_610 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_89 ) {
F_250 ( V_22 , V_9 -> V_131 , V_9 ) ;
V_9 -> V_148 = V_333 ;
V_9 -> V_10 = V_278 ;
V_21 = F_246 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_619 ;
} else if ( V_30 -> V_186 ) {
F_250 ( V_22 , V_9 -> V_131 , V_9 ) ;
V_9 -> V_148 = V_333 ;
V_9 -> V_10 = V_278 ;
V_21 = F_240 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_619 ;
}
return V_21 ;
}
static void V_319 ( struct V_626 * V_318 )
{
struct V_277 * V_278 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_254 ( V_318 , struct V_8 , V_318 ) ;
V_278 = V_9 -> V_10 ;
V_30 = V_278 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_278 -> V_288 = V_337 << 16 ;
return F_142 ( V_9 -> V_22 , V_9 , V_278 ) ;
}
if ( V_9 -> V_13 )
return F_140 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_147 ( V_9 -> V_22 , V_9 , V_278 ) ;
if ( V_9 -> V_148 == V_152 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_137 * V_279 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
int V_21 ;
if ( V_279 -> V_283 . V_284 ==
V_297 ) {
V_21 = F_253 ( V_22 , V_9 , V_278 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_619 ) {
V_278 -> V_288 = V_627 << 16 ;
return F_142 ( V_22 , V_9 , V_278 ) ;
}
}
}
F_252 ( V_9 -> V_22 , V_9 -> V_131 , V_9 ) ;
if ( F_248 ( V_9 -> V_22 , V_9 , V_278 , V_30 -> V_72 ) ) {
V_278 -> V_288 = V_627 << 16 ;
V_278 -> V_317 ( V_278 ) ;
}
}
static int F_255 ( struct V_6 * V_7 , struct V_277 * V_278 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_278 -> V_42 ) ;
F_75 ( V_278 -> V_628 -> V_342 < 0 ) ;
V_30 = V_278 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_278 -> V_288 = V_337 << 16 ;
V_278 -> V_317 ( V_278 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_44 ( F_13 ( V_22 ) ) ) {
V_278 -> V_288 = V_337 << 16 ;
V_278 -> V_317 ( V_278 ) ;
return 0 ;
}
V_9 = F_256 ( V_22 , V_278 ) ;
if ( F_47 ( V_278 -> V_629 == 0 &&
V_278 -> V_628 -> V_148 == V_630 &&
V_22 -> V_56 ) ) {
V_21 = F_253 ( V_22 , V_9 , V_278 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_619 ) {
F_140 ( V_22 , V_9 ) ;
return V_619 ;
}
}
return F_248 ( V_22 , V_9 , V_278 , V_72 ) ;
}
static void F_257 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_631 , V_78 ) ;
V_22 -> V_632 = 1 ;
F_139 ( & V_22 -> V_633 ) ;
F_36 ( & V_22 -> V_631 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_257 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_631 , V_78 ) ;
if ( V_22 -> V_632 )
break;
F_36 ( & V_22 -> V_631 , V_78 ) ;
F_179 ( V_22 -> V_633 , V_22 -> V_632 ) ;
}
V_22 -> V_632 = 0 ;
F_36 ( & V_22 -> V_631 , V_78 ) ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_257 ( V_22 ) ;
F_227 ( V_22 ) ;
F_257 ( V_22 ) ;
}
static int F_258 ( struct V_2 * V_3 , int V_231 )
{
struct V_73 * V_218 = V_3 -> V_80 ;
if ( ! V_218 )
return - V_81 ;
if ( V_231 < 1 )
V_231 = 1 ;
else if ( V_231 > V_218 -> V_188 )
V_231 = V_218 -> V_188 ;
return F_117 ( V_3 , V_231 ) ;
}
static int F_259 ( struct V_6 * V_7 ,
unsigned long V_634 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_635 ;
F_35 ( & V_22 -> V_631 , V_78 ) ;
V_635 = V_22 -> V_632 ;
F_36 ( & V_22 -> V_631 , V_78 ) ;
return V_635 ;
}
static int F_260 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_261 ( & V_636 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_165 ) ;
return - V_255 ;
}
V_7 -> V_637 = 0 ;
V_7 -> V_638 = 0 ;
V_7 -> V_639 = - 1 ;
V_7 -> V_640 = 3 ;
V_7 -> V_641 = V_642 ;
V_7 -> V_643 = V_494 ;
V_7 -> V_644 = V_494 ;
V_7 -> V_252 = V_22 -> V_235 - V_645 ;
V_7 -> V_646 = V_7 -> V_252 ;
V_7 -> V_647 = V_22 -> V_256 ;
V_7 -> V_648 = V_649 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_650 = V_22 -> V_651 [ V_22 -> V_652 ] ;
V_7 -> V_653 = V_7 -> V_650 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_262 ( struct V_1 * V_22 )
{
int V_654 ;
V_654 = F_263 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_654 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_166 ) ;
return V_654 ;
}
F_264 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_265 ( struct V_277 * V_655 )
{
int V_656 = V_655 -> V_628 -> V_342 ;
if ( V_656 < 0 )
return V_656 ;
return V_656 += V_645 ;
}
static int F_266 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_657 [] ,
int V_111 )
{
int V_21 ;
( void ) F_171 ( V_9 , V_469 , V_22 ,
NULL , 0 , 0 , V_657 , V_387 ) ;
V_21 = F_161 ( V_22 , V_9 , V_111 , V_374 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_658 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_289 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_659 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_267 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_657 [] , int V_111 )
{
int V_21 ;
int V_48 = 0 ;
int V_660 = 1 ;
for ( V_48 = 0 ; V_48 < V_661 ; V_48 ++ ) {
F_166 ( 1000 * V_660 ) ;
V_21 = F_266 ( V_22 , V_9 , V_657 , V_111 ) ;
if ( ! V_21 )
break;
if ( V_660 < V_662 )
V_660 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_167 ,
V_660 ) ;
}
return V_21 ;
}
static int F_268 ( struct V_1 * V_22 ,
unsigned char V_657 [] ,
int V_111 )
{
int V_663 ;
int V_664 ;
int V_110 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
if ( V_111 == V_125 ) {
V_663 = 0 ;
V_664 = V_22 -> V_127 - 1 ;
} else {
V_663 = V_111 ;
V_664 = V_111 ;
}
for ( V_110 = V_663 ; V_110 <= V_664 ; V_110 ++ ) {
V_21 = F_267 ( V_22 , V_9 , V_657 , V_110 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_168 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_169 ) ;
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_269 ( struct V_277 * V_665 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_390 ;
char V_666 [ 48 ] ;
V_22 = F_1 ( V_665 -> V_42 ) ;
if ( V_22 == NULL )
return V_667 ;
if ( F_13 ( V_22 ) )
return V_667 ;
V_30 = V_665 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_170 , V_202 ) ;
return V_667 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_666 , sizeof( V_666 ) ,
L_171 ,
F_265 ( V_665 ) ) ;
F_69 ( V_237 , V_22 , V_30 , V_666 ) ;
return V_667 ;
}
if ( F_270 ( V_22 ) ) {
snprintf ( V_666 , sizeof( V_666 ) ,
L_172 ,
F_265 ( V_665 ) ) ;
F_69 ( V_237 , V_22 , V_30 , V_666 ) ;
return V_667 ;
}
if ( F_62 ( V_30 -> V_72 ) )
return V_668 ;
if ( F_31 ( V_30 -> V_72 ) )
V_390 = V_669 ;
else
V_390 = V_670 ;
sprintf ( V_666 , L_173 ,
V_390 == V_669 ? L_174 : L_175 ) ;
F_69 ( V_237 , V_22 , V_30 , V_666 ) ;
V_22 -> V_242 = 1 ;
V_21 = F_176 ( V_22 , V_30 , V_30 -> V_72 , V_390 ,
V_125 ) ;
sprintf ( V_666 , L_176 ,
V_390 == V_669 ? L_174 : L_175 ,
V_21 == 0 ? L_177 : L_178 ) ;
F_69 ( V_237 , V_22 , V_30 , V_666 ) ;
V_22 -> V_242 = 0 ;
return V_21 == 0 ? V_668 : V_667 ;
}
static void F_271 ( T_1 * V_342 )
{
T_1 V_671 [ 8 ] ;
memcpy ( V_671 , V_342 , 8 ) ;
V_342 [ 0 ] = V_671 [ 3 ] ;
V_342 [ 1 ] = V_671 [ 2 ] ;
V_342 [ 2 ] = V_671 [ 1 ] ;
V_342 [ 3 ] = V_671 [ 0 ] ;
V_342 [ 4 ] = V_671 [ 7 ] ;
V_342 [ 5 ] = V_671 [ 6 ] ;
V_342 [ 6 ] = V_671 [ 5 ] ;
V_342 [ 7 ] = V_671 [ 4 ] ;
}
static void F_272 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_672 , T_7 * V_673 )
{
T_5 V_342 ;
if ( V_9 -> V_148 == V_149 ) {
struct V_128 * V_674 = (struct V_128 * )
& V_22 -> V_130 [ V_9 -> V_131 ] ;
V_342 = F_129 ( V_674 -> V_342 ) ;
* V_673 = F_132 ( V_342 >> 32 ) ;
* V_672 = F_132 ( V_342 ) ;
return;
}
if ( V_9 -> V_148 == V_152 ) {
struct V_137 * V_675 = (struct V_137 * )
& V_22 -> V_135 [ V_9 -> V_131 ] ;
memset ( V_673 , 0 , sizeof( * V_673 ) ) ;
* V_672 = V_675 -> V_573 ;
return;
}
V_342 = F_129 ( V_9 -> V_122 . V_342 ) ;
* V_673 = F_132 ( V_342 >> 32 ) ;
* V_672 = F_132 ( V_342 ) ;
}
static int F_273 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_111 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
T_7 V_673 , V_672 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_471 , V_22 , & abort -> V_122 . V_342 ,
0 , 0 , V_72 , V_391 ) ;
if ( V_22 -> V_71 )
F_271 ( & V_9 -> V_142 . V_143 [ 4 ] ) ;
( void ) F_161 ( V_22 , V_9 , V_111 , V_374 ) ;
F_272 ( V_22 , abort , & V_672 , & V_673 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_179 ,
V_202 , V_673 , V_672 ) ;
V_331 = V_9 -> V_24 ;
switch ( V_331 -> V_36 ) {
case V_658 :
break;
case V_362 :
V_21 = F_149 ( V_22 , V_9 ) ;
break;
case V_361 :
V_21 = - 1 ;
break;
default:
F_274 ( & V_22 -> V_29 -> V_30 , L_180 ,
V_202 , V_673 , V_672 ) ;
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_172 ( V_22 , V_9 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_181 ,
V_202 , V_673 , V_672 ) ;
return V_21 ;
}
static void F_275 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_676 , int V_111 )
{
struct V_137 * V_279 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
struct V_134 * V_393 = (struct V_134 * ) V_279 ;
struct V_137 * V_677 =
& V_22 -> V_135 [ V_676 -> V_131 ] ;
struct V_277 * V_655 = V_676 -> V_10 ;
struct V_73 * V_30 = V_655 -> V_42 -> V_80 ;
F_276 ( sizeof( struct V_134 ) >
sizeof( struct V_137 ) ) ;
F_75 ( F_244 ( struct V_137 , V_283 ) <
F_244 ( struct V_134 , V_678 ) +
sizeof( V_393 -> V_678 ) ) ;
V_9 -> V_148 = V_154 ;
V_9 -> V_10 = V_679 ;
V_9 -> V_120 = ( T_4 ) V_22 -> V_565 +
( V_9 -> V_131 * sizeof( struct V_137 ) ) ;
F_75 ( V_9 -> V_120 & 0x0000007F ) ;
memset ( V_393 , 0 , sizeof( * V_279 ) ) ;
V_393 -> V_680 = V_681 ;
V_393 -> V_111 = V_111 ;
V_393 -> V_682 = V_683 ;
V_393 -> V_395 = F_132 ( V_30 -> V_185 ) ;
memset ( V_393 -> V_684 , 0 , sizeof( V_393 -> V_684 ) ) ;
V_393 -> V_342 = F_127 ( V_9 -> V_131 << V_574 ) ;
V_393 -> V_685 = F_127 ( F_124 ( V_677 -> V_573 ) ) ;
V_393 -> V_686 = F_127 ( V_9 -> V_120 +
F_244 ( struct V_137 , V_283 ) ) ;
V_393 -> V_678 = F_132 ( sizeof( V_279 -> V_283 ) ) ;
}
static int F_277 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_111 )
{
int V_21 = V_375 ;
struct V_277 * V_655 ;
struct V_73 * V_30 ;
unsigned char V_687 [ 8 ] ;
unsigned char * V_688 = & V_687 [ 0 ] ;
V_655 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_655 -> V_42 -> V_80 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_182 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_183 ,
V_22 -> V_59 -> V_100 , V_30 -> V_101 , V_30 -> V_102 , V_30 -> V_103 ,
L_184 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_89 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_185 ) ;
return - 1 ;
}
if ( ! F_217 ( V_22 , abort , V_688 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_186 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_688 [ 0 ] , V_688 [ 1 ] , V_688 [ 2 ] , V_688 [ 3 ] ,
V_688 [ 4 ] , V_688 [ 5 ] , V_688 [ 6 ] , V_688 [ 7 ] ) ;
V_21 = F_176 ( V_22 , V_30 , V_688 , V_689 , V_111 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_188 ,
V_688 [ 0 ] , V_688 [ 1 ] , V_688 [ 2 ] , V_688 [ 3 ] ,
V_688 [ 4 ] , V_688 [ 5 ] , V_688 [ 6 ] , V_688 [ 7 ] ) ;
return V_21 ;
}
if ( F_268 ( V_22 , V_688 , V_111 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_189 ,
V_688 [ 0 ] , V_688 [ 1 ] , V_688 [ 2 ] , V_688 [ 3 ] ,
V_688 [ 4 ] , V_688 [ 5 ] , V_688 [ 6 ] , V_688 [ 7 ] ) ;
return - 1 ;
}
F_94 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_688 [ 0 ] , V_688 [ 1 ] , V_688 [ 2 ] , V_688 [ 3 ] ,
V_688 [ 4 ] , V_688 [ 5 ] , V_688 [ 6 ] , V_688 [ 7 ] ) ;
return V_21 ;
}
static int F_278 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_111 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
T_7 V_672 , V_673 ;
struct V_73 * V_30 ;
struct V_137 * V_279 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 -> V_89 && ! V_30 -> V_186 )
return - 1 ;
V_9 = F_170 ( V_22 ) ;
F_275 ( V_9 , V_22 , abort , V_111 ) ;
V_279 = & V_22 -> V_135 [ V_9 -> V_131 ] ;
( void ) F_161 ( V_22 , V_9 , V_111 , V_374 ) ;
F_272 ( V_22 , abort , & V_672 , & V_673 ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_202 , V_673 , V_672 ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_202 , V_673 , V_672 , V_279 -> V_283 . V_284 ) ;
switch ( V_279 -> V_283 . V_284 ) {
case V_310 :
case V_311 :
V_21 = 0 ;
break;
case V_312 :
case V_299 :
case V_313 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_193 ,
V_202 , V_673 , V_672 ,
V_279 -> V_283 . V_284 ) ;
V_21 = - 1 ;
}
F_172 ( V_22 , V_9 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_181 , V_202 ,
V_673 , V_672 ) ;
return V_21 ;
}
static int F_279 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_111 )
{
if ( abort -> V_148 == V_152 ) {
if ( V_690 & V_22 -> V_691 )
return F_278 ( V_22 , abort ,
V_111 ) ;
else
return F_277 ( V_22 , V_72 ,
abort , V_111 ) ;
}
return F_273 ( V_22 , V_72 , abort , V_111 ) ;
}
static int F_280 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_148 == V_152 )
return V_22 -> V_135 [ V_9 -> V_131 ] . V_111 ;
return V_9 -> V_122 . V_126 ;
}
static inline int F_281 ( struct V_1 * V_22 )
{
#define F_282 5000
return ! F_283 ( V_22 -> V_692 ,
F_284 ( & V_22 -> V_693 ) >= 0 ,
F_160 ( F_282 ) ) ;
}
static int F_285 ( struct V_277 * V_694 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_277 * V_695 ;
char V_666 [ 256 ] ;
int V_696 = 0 ;
T_7 V_673 , V_672 ;
int V_399 , V_111 ;
if ( V_694 == NULL )
return V_667 ;
if ( V_694 -> V_42 == NULL )
return V_667 ;
V_22 = F_1 ( V_694 -> V_42 ) ;
if ( V_22 == NULL )
return V_667 ;
V_30 = V_694 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_194 ,
V_666 ) ;
return V_667 ;
}
if ( F_13 ( V_22 ) ) {
F_69 ( V_237 , V_22 , V_30 ,
L_195 ) ;
return V_667 ;
}
if ( F_270 ( V_22 ) ) {
F_69 ( V_237 , V_22 , V_30 ,
L_196 ) ;
return V_667 ;
}
if ( ! ( V_697 & V_22 -> V_691 ) &&
! ( V_698 & V_22 -> V_691 ) )
return V_667 ;
memset ( V_666 , 0 , sizeof( V_666 ) ) ;
V_696 += sprintf ( V_666 + V_696 , L_197 ,
V_22 -> V_59 -> V_100 , V_694 -> V_42 -> V_699 ,
V_694 -> V_42 -> V_700 , V_694 -> V_42 -> V_103 ,
L_198 , V_694 ) ;
abort = (struct V_8 * ) V_694 -> V_610 ;
if ( abort == NULL ) {
return V_668 ;
}
V_399 = F_178 ( & abort -> V_399 ) ;
if ( V_399 == 1 ) {
F_172 ( V_22 , abort ) ;
return V_668 ;
}
if ( abort -> V_148 != V_152 &&
abort -> V_148 != V_149 && ! V_30 -> V_480 ) {
F_172 ( V_22 , abort ) ;
return V_667 ;
}
if ( abort -> V_10 != V_694 ) {
F_172 ( V_22 , abort ) ;
return V_668 ;
}
abort -> V_12 = true ;
F_272 ( V_22 , abort , & V_672 , & V_673 ) ;
V_111 = F_280 ( V_22 , abort ) ;
V_696 += sprintf ( V_666 + V_696 , L_199 , V_673 , V_672 ) ;
V_695 = abort -> V_10 ;
if ( V_695 != NULL )
V_696 += sprintf ( V_666 + V_696 ,
L_200 ,
V_695 -> V_544 , V_695 -> V_557 [ 0 ] , V_695 -> V_557 [ 1 ] ,
V_695 -> V_701 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_201 , V_666 ) ;
F_69 ( V_237 , V_22 , V_30 , L_198 ) ;
if ( F_281 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_202 ,
V_666 ) ;
F_172 ( V_22 , abort ) ;
return V_667 ;
}
V_21 = F_279 ( V_22 , V_30 -> V_72 , abort , V_111 ) ;
F_55 ( & V_22 -> V_693 ) ;
F_139 ( & V_22 -> V_692 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_203 , V_666 ) ;
F_69 ( V_237 , V_22 , V_30 ,
L_204 ) ;
F_172 ( V_22 , abort ) ;
return V_667 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_205 , V_666 ) ;
F_179 ( V_22 -> V_316 ,
abort -> V_10 != V_694 || F_13 ( V_22 ) ) ;
F_172 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_668 : V_667 ;
}
static struct V_8 * F_256 ( struct V_1 * V_22 ,
struct V_277 * V_655 )
{
int V_656 = F_265 ( V_655 ) ;
struct V_8 * V_9 = V_22 -> V_398 + V_656 ;
if ( V_656 < V_645 || V_656 >= V_22 -> V_235 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_206 ,
V_656 , V_645 , V_22 -> V_235 - 1 ) ;
F_175 () ;
}
F_55 ( & V_9 -> V_399 ) ;
if ( F_44 ( ! F_4 ( V_9 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_207 ,
V_656 ) ;
if ( V_9 -> V_10 != NULL )
F_286 ( V_9 -> V_10 ) ;
F_286 ( V_655 ) ;
}
F_252 ( V_22 , V_656 , V_9 ) ;
return V_9 ;
}
static void F_141 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_45 ( & V_9 -> V_399 ) ;
}
static struct V_8 * F_170 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_399 , V_68 ;
int V_702 = 0 ;
for (; ; ) {
V_68 = F_287 ( V_22 -> V_703 ,
V_645 ,
V_702 ) ;
if ( F_44 ( V_68 >= V_645 ) ) {
V_702 = 0 ;
continue;
}
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( F_44 ( V_399 > 1 ) ) {
F_172 ( V_22 , V_9 ) ;
V_702 = ( V_68 + 1 ) % V_645 ;
continue;
}
F_288 ( V_68 & ( V_603 - 1 ) ,
V_22 -> V_703 + ( V_68 / V_603 ) ) ;
break;
}
F_252 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_172 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_57 ( & V_9 -> V_399 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_398 ;
F_289 ( V_68 & ( V_603 - 1 ) ,
V_22 -> V_703 + ( V_68 / V_603 ) ) ;
}
}
static int F_290 ( struct V_2 * V_30 , int V_278 ,
void T_8 * V_704 )
{
T_9 T_8 * V_705 =
( T_9 T_8 * ) V_704 ;
T_10 V_706 ;
T_10 T_8 * V_707 = F_291 ( sizeof( V_706 ) ) ;
int V_708 ;
T_4 V_129 ;
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_708 = 0 ;
V_708 |= F_292 ( & V_706 . V_709 , & V_705 -> V_709 ,
sizeof( V_706 . V_709 ) ) ;
V_708 |= F_292 ( & V_706 . V_142 , & V_705 -> V_142 ,
sizeof( V_706 . V_142 ) ) ;
V_708 |= F_292 ( & V_706 . V_710 , & V_705 -> V_710 ,
sizeof( V_706 . V_710 ) ) ;
V_708 |= F_293 ( V_706 . V_711 , & V_705 -> V_711 ) ;
V_708 |= F_293 ( V_129 , & V_705 -> V_45 ) ;
V_706 . V_45 = F_294 ( V_129 ) ;
V_708 |= F_295 ( V_707 , & V_706 , sizeof( V_706 ) ) ;
if ( V_708 )
return - V_712 ;
V_708 = F_296 ( V_30 , V_713 , V_707 ) ;
if ( V_708 )
return V_708 ;
V_708 |= F_297 ( & V_705 -> V_710 , & V_707 -> V_710 ,
sizeof( V_705 -> V_710 ) ) ;
if ( V_708 )
return - V_712 ;
return V_708 ;
}
static int F_298 ( struct V_2 * V_30 ,
int V_278 , void T_8 * V_704 )
{
T_11 T_8 * V_705 =
( T_11 T_8 * ) V_704 ;
T_12 V_706 ;
T_12 T_8 * V_707 =
F_291 ( sizeof( V_706 ) ) ;
int V_708 ;
T_4 V_129 ;
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_708 = 0 ;
V_708 |= F_292 ( & V_706 . V_709 , & V_705 -> V_709 ,
sizeof( V_706 . V_709 ) ) ;
V_708 |= F_292 ( & V_706 . V_142 , & V_705 -> V_142 ,
sizeof( V_706 . V_142 ) ) ;
V_708 |= F_292 ( & V_706 . V_710 , & V_705 -> V_710 ,
sizeof( V_706 . V_710 ) ) ;
V_708 |= F_293 ( V_706 . V_711 , & V_705 -> V_711 ) ;
V_708 |= F_293 ( V_706 . V_714 , & V_705 -> V_714 ) ;
V_708 |= F_293 ( V_129 , & V_705 -> V_45 ) ;
V_706 . V_45 = F_294 ( V_129 ) ;
V_708 |= F_295 ( V_707 , & V_706 , sizeof( V_706 ) ) ;
if ( V_708 )
return - V_712 ;
V_708 = F_296 ( V_30 , V_715 , V_707 ) ;
if ( V_708 )
return V_708 ;
V_708 |= F_297 ( & V_705 -> V_710 , & V_707 -> V_710 ,
sizeof( V_705 -> V_710 ) ) ;
if ( V_708 )
return - V_712 ;
return V_708 ;
}
static int F_299 ( struct V_2 * V_30 , int V_278 , void T_8 * V_704 )
{
switch ( V_278 ) {
case V_716 :
case V_717 :
case V_718 :
case V_719 :
case V_720 :
case V_721 :
case V_722 :
case V_723 :
case V_724 :
case V_725 :
case V_726 :
case V_727 :
case V_728 :
case V_729 :
case V_730 :
return F_296 ( V_30 , V_278 , V_704 ) ;
case V_731 :
return F_290 ( V_30 , V_278 , V_704 ) ;
case V_732 :
return F_298 ( V_30 , V_278 , V_704 ) ;
default:
return - V_733 ;
}
}
static int F_300 ( struct V_1 * V_22 , void T_8 * V_734 )
{
struct V_735 V_736 ;
if ( ! V_734 )
return - V_55 ;
V_736 . V_737 = F_301 ( V_22 -> V_29 -> V_101 ) ;
V_736 . V_101 = V_22 -> V_29 -> V_101 -> V_738 ;
V_736 . V_739 = V_22 -> V_29 -> V_740 ;
V_736 . V_67 = V_22 -> V_67 ;
if ( F_295 ( V_734 , & V_736 , sizeof( V_736 ) ) )
return - V_712 ;
return 0 ;
}
static int F_302 ( struct V_1 * V_22 , void T_8 * V_734 )
{
T_13 V_741 ;
unsigned char V_742 , V_743 , V_744 ;
int V_21 ;
V_21 = sscanf ( V_745 , L_208 ,
& V_742 , & V_743 , & V_744 ) ;
if ( V_21 != 3 ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_209
L_210 , V_745 ) ;
V_742 = 0 ;
V_743 = 0 ;
V_744 = 0 ;
}
V_741 = ( V_742 << 16 ) | ( V_743 << 8 ) | V_744 ;
if ( ! V_734 )
return - V_55 ;
if ( F_295 ( V_734 , & V_741 , sizeof( T_13 ) ) )
return - V_712 ;
return 0 ;
}
static int F_303 ( struct V_1 * V_22 , void T_8 * V_734 )
{
T_10 V_746 ;
struct V_8 * V_9 ;
char * V_747 = NULL ;
T_5 V_261 ;
int V_21 = 0 ;
if ( ! V_734 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_748 ;
if ( F_292 ( & V_746 , V_734 , sizeof( V_746 ) ) )
return - V_712 ;
if ( ( V_746 . V_711 < 1 ) &&
( V_746 . V_142 . Type . V_749 != V_616 ) ) {
return - V_55 ;
}
if ( V_746 . V_711 > 0 ) {
V_747 = F_91 ( V_746 . V_711 , V_201 ) ;
if ( V_747 == NULL )
return - V_255 ;
if ( V_746 . V_142 . Type . V_749 & V_614 ) {
if ( F_292 ( V_747 , V_746 . V_45 ,
V_746 . V_711 ) ) {
V_21 = - V_712 ;
goto V_750;
}
} else {
memset ( V_747 , 0 , V_746 . V_711 ) ;
}
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_148 = V_394 ;
V_9 -> V_10 = V_679 ;
V_9 -> V_122 . V_126 = 0 ;
if ( V_746 . V_711 > 0 ) {
V_9 -> V_122 . V_123 = 1 ;
V_9 -> V_122 . V_274 = F_153 ( 1 ) ;
} else {
V_9 -> V_122 . V_123 = 0 ;
V_9 -> V_122 . V_274 = F_153 ( 0 ) ;
}
memcpy ( & V_9 -> V_122 . V_343 , & V_746 . V_709 , sizeof( V_9 -> V_122 . V_343 ) ) ;
memcpy ( & V_9 -> V_142 , & V_746 . V_142 ,
sizeof( V_9 -> V_142 ) ) ;
if ( V_746 . V_711 > 0 ) {
V_261 = F_125 ( V_22 -> V_29 , V_747 ,
V_746 . V_711 , V_751 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , ( V_366 ) V_261 ) ) {
V_9 -> V_270 [ 0 ] . V_276 = F_127 ( 0 ) ;
V_9 -> V_270 [ 0 ] . V_275 = F_132 ( 0 ) ;
V_21 = - V_255 ;
goto V_388;
}
V_9 -> V_270 [ 0 ] . V_276 = F_127 ( V_261 ) ;
V_9 -> V_270 [ 0 ] . V_275 = F_132 ( V_746 . V_711 ) ;
V_9 -> V_270 [ 0 ] . V_272 = F_132 ( V_370 ) ;
}
V_21 = F_161 ( V_22 , V_9 , V_125 , V_374 ) ;
if ( V_746 . V_711 > 0 )
F_154 ( V_22 -> V_29 , V_9 , 1 , V_751 ) ;
F_304 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_381 ;
goto V_388;
}
memcpy ( & V_746 . V_710 , V_9 -> V_24 ,
sizeof( V_746 . V_710 ) ) ;
if ( F_295 ( V_734 , & V_746 , sizeof( V_746 ) ) ) {
V_21 = - V_712 ;
goto V_388;
}
if ( ( V_746 . V_142 . Type . V_749 & V_615 ) &&
V_746 . V_711 > 0 ) {
if ( F_295 ( V_746 . V_45 , V_747 , V_746 . V_711 ) ) {
V_21 = - V_712 ;
goto V_388;
}
}
V_388:
F_172 ( V_22 , V_9 ) ;
V_750:
F_80 ( V_747 ) ;
return V_21 ;
}
static int F_305 ( struct V_1 * V_22 , void T_8 * V_734 )
{
T_12 * V_752 ;
struct V_8 * V_9 ;
unsigned char * * V_747 = NULL ;
int * V_753 = NULL ;
T_5 V_261 ;
T_14 V_364 = 0 ;
int V_49 = 0 ;
T_4 V_754 ;
T_4 V_755 ;
T_14 T_8 * V_756 ;
if ( ! V_734 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_748 ;
V_752 = ( T_12 * )
F_91 ( sizeof( * V_752 ) , V_201 ) ;
if ( ! V_752 ) {
V_49 = - V_255 ;
goto V_757;
}
if ( F_292 ( V_752 , V_734 , sizeof( * V_752 ) ) ) {
V_49 = - V_712 ;
goto V_757;
}
if ( ( V_752 -> V_711 < 1 ) &&
( V_752 -> V_142 . Type . V_749 != V_616 ) ) {
V_49 = - V_55 ;
goto V_757;
}
if ( V_752 -> V_714 > V_758 ) {
V_49 = - V_55 ;
goto V_757;
}
if ( V_752 -> V_711 > V_752 -> V_714 * V_759 ) {
V_49 = - V_55 ;
goto V_757;
}
V_747 = F_108 ( V_759 * sizeof( char * ) , V_201 ) ;
if ( ! V_747 ) {
V_49 = - V_255 ;
goto V_757;
}
V_753 = F_91 ( V_759 * sizeof( int ) , V_201 ) ;
if ( ! V_753 ) {
V_49 = - V_255 ;
goto V_757;
}
V_754 = V_752 -> V_711 ;
V_756 = V_752 -> V_45 ;
while ( V_754 ) {
V_755 = ( V_754 > V_752 -> V_714 ) ? V_752 -> V_714 : V_754 ;
V_753 [ V_364 ] = V_755 ;
V_747 [ V_364 ] = F_91 ( V_755 , V_201 ) ;
if ( V_747 [ V_364 ] == NULL ) {
V_49 = - V_255 ;
goto V_757;
}
if ( V_752 -> V_142 . Type . V_749 & V_614 ) {
if ( F_292 ( V_747 [ V_364 ] , V_756 , V_755 ) ) {
V_49 = - V_712 ;
goto V_757;
}
} else
memset ( V_747 [ V_364 ] , 0 , V_755 ) ;
V_754 -= V_755 ;
V_756 += V_755 ;
V_364 ++ ;
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_148 = V_394 ;
V_9 -> V_10 = V_679 ;
V_9 -> V_122 . V_126 = 0 ;
V_9 -> V_122 . V_123 = ( T_1 ) V_364 ;
V_9 -> V_122 . V_274 = F_153 ( V_364 ) ;
memcpy ( & V_9 -> V_122 . V_343 , & V_752 -> V_709 , sizeof( V_9 -> V_122 . V_343 ) ) ;
memcpy ( & V_9 -> V_142 , & V_752 -> V_142 , sizeof( V_9 -> V_142 ) ) ;
if ( V_752 -> V_711 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ ) {
V_261 = F_125 ( V_22 -> V_29 , V_747 [ V_68 ] ,
V_753 [ V_68 ] , V_751 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 ,
( V_366 ) V_261 ) ) {
V_9 -> V_270 [ V_68 ] . V_276 = F_127 ( 0 ) ;
V_9 -> V_270 [ V_68 ] . V_275 = F_132 ( 0 ) ;
F_154 ( V_22 -> V_29 , V_9 , V_68 ,
V_751 ) ;
V_49 = - V_255 ;
goto V_760;
}
V_9 -> V_270 [ V_68 ] . V_276 = F_127 ( V_261 ) ;
V_9 -> V_270 [ V_68 ] . V_275 = F_132 ( V_753 [ V_68 ] ) ;
V_9 -> V_270 [ V_68 ] . V_272 = F_132 ( 0 ) ;
}
V_9 -> V_270 [ -- V_68 ] . V_272 = F_132 ( V_370 ) ;
}
V_49 = F_161 ( V_22 , V_9 , V_125 , V_374 ) ;
if ( V_364 )
F_154 ( V_22 -> V_29 , V_9 , V_364 , V_751 ) ;
F_304 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_381 ;
goto V_760;
}
memcpy ( & V_752 -> V_710 , V_9 -> V_24 , sizeof( V_752 -> V_710 ) ) ;
if ( F_295 ( V_734 , V_752 , sizeof( * V_752 ) ) ) {
V_49 = - V_712 ;
goto V_760;
}
if ( ( V_752 -> V_142 . Type . V_749 & V_615 ) && V_752 -> V_711 > 0 ) {
int V_68 ;
T_14 T_8 * V_761 = V_752 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ ) {
if ( F_295 ( V_761 , V_747 [ V_68 ] , V_753 [ V_68 ] ) ) {
V_49 = - V_712 ;
goto V_760;
}
V_761 += V_753 [ V_68 ] ;
}
}
V_49 = 0 ;
V_760:
F_172 ( V_22 , V_9 ) ;
V_757:
if ( V_747 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ )
F_80 ( V_747 [ V_68 ] ) ;
F_80 ( V_747 ) ;
}
F_80 ( V_753 ) ;
F_80 ( V_752 ) ;
return V_49 ;
}
static void F_304 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_289 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_296 ( struct V_2 * V_30 , int V_278 , void T_8 * V_704 )
{
struct V_1 * V_22 ;
void T_8 * V_734 = ( void T_8 * ) V_704 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_278 ) {
case V_726 :
case V_727 :
case V_728 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_716 :
return F_300 ( V_22 , V_734 ) ;
case V_724 :
return F_302 ( V_22 , V_734 ) ;
case V_713 :
if ( F_284 ( & V_22 -> V_762 ) < 0 )
return - V_763 ;
V_21 = F_303 ( V_22 , V_734 ) ;
F_55 ( & V_22 -> V_762 ) ;
return V_21 ;
case V_715 :
if ( F_284 ( & V_22 -> V_762 ) < 0 )
return - V_763 ;
V_21 = F_305 ( V_22 , V_734 ) ;
F_55 ( & V_22 -> V_762 ) ;
return V_21 ;
default:
return - V_764 ;
}
}
static void F_306 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_390 )
{
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_669 , V_22 , NULL , 0 , 0 ,
V_156 , V_391 ) ;
V_9 -> V_142 . V_143 [ 1 ] = V_390 ;
V_9 -> V_373 = NULL ;
F_60 ( V_22 , V_9 ) ;
return;
}
static int F_171 ( struct V_8 * V_9 , T_1 V_278 , struct V_1 * V_22 ,
void * V_747 , T_3 V_462 , T_6 V_765 , unsigned char * V_72 ,
int V_148 )
{
int V_766 = V_616 ;
T_5 V_342 ;
V_9 -> V_148 = V_394 ;
V_9 -> V_10 = V_679 ;
V_9 -> V_122 . V_126 = 0 ;
if ( V_747 != NULL && V_462 > 0 ) {
V_9 -> V_122 . V_123 = 1 ;
V_9 -> V_122 . V_274 = F_153 ( 1 ) ;
} else {
V_9 -> V_122 . V_123 = 0 ;
V_9 -> V_122 . V_274 = F_153 ( 0 ) ;
}
memcpy ( V_9 -> V_122 . V_343 . V_344 , V_72 , 8 ) ;
if ( V_148 == V_387 ) {
switch ( V_278 ) {
case V_386 :
if ( V_765 & V_400 ) {
V_9 -> V_142 . V_143 [ 1 ] = 0x01 ;
V_9 -> V_142 . V_143 [ 2 ] = ( V_765 & 0xff ) ;
}
V_9 -> V_142 . V_339 = 6 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_386 ;
V_9 -> V_142 . V_143 [ 4 ] = V_462 & 0xFF ;
break;
case V_456 :
case V_457 :
V_9 -> V_142 . V_339 = 12 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_278 ;
V_9 -> V_142 . V_143 [ 6 ] = ( V_462 >> 24 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 9 ] = V_462 & 0xFF ;
break;
case V_767 :
V_9 -> V_142 . V_339 = 16 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 6 ] = V_767 ;
break;
case V_769 :
V_9 -> V_142 . V_339 = 16 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 ,
V_613 , V_614 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_140 ;
V_9 -> V_142 . V_143 [ 6 ] = V_769 ;
break;
case V_770 :
V_9 -> V_142 . V_339 = 12 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 ,
V_613 , V_614 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_140 ;
V_9 -> V_142 . V_143 [ 6 ] = V_771 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 8 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = V_462 & 0xFF ;
break;
case V_469 :
V_9 -> V_142 . V_339 = 6 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_616 ) ;
V_9 -> V_142 . V_611 = 0 ;
break;
case V_418 :
V_9 -> V_142 . V_339 = 12 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_772 ;
V_9 -> V_142 . V_143 [ 1 ] = V_278 ;
V_9 -> V_142 . V_143 [ 6 ] = ( V_462 >> 24 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 9 ] = V_462 & 0xFF ;
break;
case V_773 :
V_9 -> V_142 . V_339 = 10 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 6 ] = V_773 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0xFF ;
break;
case V_425 :
V_9 -> V_142 . V_339 = 10 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 6 ] = V_425 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0XFF ;
break;
case V_421 :
V_9 -> V_142 . V_339 = 10 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 6 ] = V_421 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0XFF ;
break;
case V_435 :
V_9 -> V_142 . V_339 = 10 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 6 ] = V_435 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0XFF ;
break;
case V_423 :
V_9 -> V_142 . V_339 = 10 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_615 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_768 ;
V_9 -> V_142 . V_143 [ 1 ] = 0 ;
V_9 -> V_142 . V_143 [ 2 ] = 0 ;
V_9 -> V_142 . V_143 [ 3 ] = 0 ;
V_9 -> V_142 . V_143 [ 4 ] = 0 ;
V_9 -> V_142 . V_143 [ 5 ] = 0 ;
V_9 -> V_142 . V_143 [ 6 ] = V_423 ;
V_9 -> V_142 . V_143 [ 7 ] = ( V_462 >> 16 ) & 0xFF ;
V_9 -> V_142 . V_143 [ 8 ] = ( V_462 >> 8 ) & 0XFF ;
V_9 -> V_142 . V_143 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_211 , V_278 ) ;
F_175 () ;
return - 1 ;
}
} else if ( V_148 == V_391 ) {
switch ( V_278 ) {
case V_670 :
V_9 -> V_142 . V_339 = 16 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_616 ) ;
V_9 -> V_142 . V_611 = 0 ;
memset ( & V_9 -> V_142 . V_143 [ 0 ] , 0 , sizeof( V_9 -> V_142 . V_143 ) ) ;
V_9 -> V_142 . V_143 [ 0 ] = V_774 ;
V_9 -> V_142 . V_143 [ 1 ] = V_775 ;
V_9 -> V_142 . V_143 [ 4 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 5 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 6 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 7 ] = 0x00 ;
break;
case V_669 :
V_9 -> V_142 . V_339 = 16 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 , V_613 , V_616 ) ;
V_9 -> V_142 . V_611 = 0 ;
memset ( & V_9 -> V_142 . V_143 [ 0 ] , 0 , sizeof( V_9 -> V_142 . V_143 ) ) ;
V_9 -> V_142 . V_143 [ 0 ] = V_278 ;
V_9 -> V_142 . V_143 [ 1 ] = V_776 ;
V_9 -> V_142 . V_143 [ 4 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 5 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 6 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 7 ] = 0x00 ;
break;
case V_471 :
memcpy ( & V_342 , V_747 , sizeof( V_342 ) ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_212 ,
V_342 , V_9 -> V_122 . V_342 ) ;
V_9 -> V_142 . V_339 = 16 ;
V_9 -> V_142 . V_612 =
F_249 ( V_148 ,
V_613 , V_614 ) ;
V_9 -> V_142 . V_611 = 0 ;
V_9 -> V_142 . V_143 [ 0 ] = V_777 ;
V_9 -> V_142 . V_143 [ 1 ] = V_778 ;
V_9 -> V_142 . V_143 [ 2 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_142 . V_143 [ 4 ] , & V_342 , sizeof( V_342 ) ) ;
V_9 -> V_142 . V_143 [ 12 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 13 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 14 ] = 0x00 ;
V_9 -> V_142 . V_143 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_213 ,
V_278 ) ;
F_175 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_214 , V_148 ) ;
F_175 () ;
}
switch ( F_307 ( V_9 -> V_142 . V_612 ) ) {
case V_615 :
V_766 = V_389 ;
break;
case V_614 :
V_766 = V_265 ;
break;
case V_616 :
V_766 = V_369 ;
break;
default:
V_766 = V_751 ;
}
if ( F_155 ( V_22 -> V_29 , V_9 , V_747 , V_462 , V_766 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_308 ( T_16 V_779 , T_16 V_462 )
{
T_16 V_780 = ( ( T_16 ) V_779 ) & V_781 ;
T_16 V_782 = ( ( T_16 ) V_779 ) - V_780 ;
void T_15 * V_783 = F_309 ( V_780 ,
V_782 + V_462 ) ;
return V_783 ? ( V_783 + V_782 ) : NULL ;
}
static inline unsigned long F_310 ( struct V_1 * V_22 , T_1 V_108 )
{
return V_22 -> V_113 . V_114 ( V_22 , V_108 ) ;
}
static inline bool F_311 ( struct V_1 * V_22 )
{
return V_22 -> V_113 . V_784 ( V_22 ) ;
}
static inline long F_312 ( struct V_1 * V_22 )
{
return ( V_22 -> V_113 . V_784 ( V_22 ) == 0 ) ||
( V_22 -> V_785 == 0 ) ;
}
static inline int F_313 ( struct V_1 * V_22 , T_4 V_786 ,
T_4 V_787 )
{
if ( F_44 ( V_786 >= V_22 -> V_235 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_215 , V_787 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_61 ( struct V_8 * V_9 )
{
F_56 ( V_9 -> V_22 , V_9 ) ;
if ( F_47 ( V_9 -> V_148 == V_149 || V_9 -> V_148 == V_333
|| V_9 -> V_148 == V_152 ) )
F_150 ( V_9 ) ;
else if ( V_9 -> V_148 == V_394 || V_9 -> V_148 == V_154 )
F_314 ( V_9 -> V_373 ) ;
}
static inline void F_315 ( struct V_1 * V_22 ,
T_4 V_787 )
{
T_4 V_786 ;
struct V_8 * V_9 ;
V_786 = V_787 >> V_574 ;
if ( ! F_313 ( V_22 , V_786 , V_787 ) ) {
V_9 = V_22 -> V_398 + V_786 ;
F_61 ( V_9 ) ;
}
}
static int F_316 ( struct V_1 * V_22 )
{
if ( F_47 ( ! V_788 ) )
return 0 ;
if ( F_47 ( V_22 -> V_785 ) )
return 0 ;
F_94 ( & V_22 -> V_29 -> V_30 , L_216
L_217 ) ;
return 1 ;
}
static struct V_1 * F_317 ( T_1 * V_789 )
{
return F_254 ( ( V_789 - * V_789 ) , struct V_1 , V_108 [ 0 ] ) ;
}
static T_17 F_318 ( int V_650 , void * V_789 )
{
struct V_1 * V_22 = F_317 ( V_789 ) ;
T_1 V_108 = * ( T_1 * ) V_789 ;
T_4 V_787 ;
if ( F_316 ( V_22 ) )
return V_790 ;
if ( F_312 ( V_22 ) )
return V_790 ;
V_22 -> V_791 = F_319 () ;
while ( F_311 ( V_22 ) ) {
V_787 = F_310 ( V_22 , V_108 ) ;
while ( V_787 != V_118 )
V_787 = F_43 ( V_22 , V_108 ) ;
}
return V_792 ;
}
static T_17 F_320 ( int V_650 , void * V_789 )
{
struct V_1 * V_22 = F_317 ( V_789 ) ;
T_4 V_787 ;
T_1 V_108 = * ( T_1 * ) V_789 ;
if ( F_316 ( V_22 ) )
return V_790 ;
V_22 -> V_791 = F_319 () ;
V_787 = F_310 ( V_22 , V_108 ) ;
while ( V_787 != V_118 )
V_787 = F_43 ( V_22 , V_108 ) ;
return V_792 ;
}
static T_17 F_321 ( int V_650 , void * V_789 )
{
struct V_1 * V_22 = F_317 ( ( T_1 * ) V_789 ) ;
T_4 V_787 ;
T_1 V_108 = * ( T_1 * ) V_789 ;
if ( F_312 ( V_22 ) )
return V_790 ;
V_22 -> V_791 = F_319 () ;
while ( F_311 ( V_22 ) ) {
V_787 = F_310 ( V_22 , V_108 ) ;
while ( V_787 != V_118 ) {
F_315 ( V_22 , V_787 ) ;
V_787 = F_43 ( V_22 , V_108 ) ;
}
}
return V_792 ;
}
static T_17 F_322 ( int V_650 , void * V_789 )
{
struct V_1 * V_22 = F_317 ( V_789 ) ;
T_4 V_787 ;
T_1 V_108 = * ( T_1 * ) V_789 ;
V_22 -> V_791 = F_319 () ;
V_787 = F_310 ( V_22 , V_108 ) ;
while ( V_787 != V_118 ) {
F_315 ( V_22 , V_787 ) ;
V_787 = F_43 ( V_22 , V_108 ) ;
}
return V_792 ;
}
static int F_323 ( struct V_363 * V_29 , unsigned char V_793 ,
unsigned char type )
{
struct V_794 {
struct V_795 V_796 ;
struct V_797 V_142 ;
struct V_798 V_799 ;
};
struct V_794 * V_278 ;
static const T_3 V_800 = sizeof( * V_278 ) +
sizeof( V_278 -> V_799 ) ;
V_366 V_801 ;
T_7 V_802 ;
T_4 V_342 ;
void T_15 * V_150 ;
int V_68 , V_708 ;
V_150 = F_324 ( V_29 , 0 ) ;
if ( V_150 == NULL )
return - V_255 ;
V_708 = F_325 ( V_29 , F_326 ( 32 ) ) ;
if ( V_708 ) {
F_327 ( V_150 ) ;
return V_708 ;
}
V_278 = F_328 ( V_29 , V_800 , & V_801 ) ;
if ( V_278 == NULL ) {
F_327 ( V_150 ) ;
return - V_255 ;
}
V_802 = F_132 ( V_801 ) ;
V_278 -> V_796 . V_126 = 0 ;
V_278 -> V_796 . V_123 = 0 ;
V_278 -> V_796 . V_274 = F_153 ( 0 ) ;
V_278 -> V_796 . V_342 = F_127 ( V_801 ) ;
memset ( & V_278 -> V_796 . V_343 . V_344 , 0 , 8 ) ;
V_278 -> V_142 . V_339 = 16 ;
V_278 -> V_142 . V_612 =
F_249 ( V_391 , V_803 , V_616 ) ;
V_278 -> V_142 . V_611 = 0 ;
V_278 -> V_142 . V_143 [ 0 ] = V_793 ;
V_278 -> V_142 . V_143 [ 1 ] = type ;
memset ( & V_278 -> V_142 . V_143 [ 2 ] , 0 , 14 ) ;
V_278 -> V_799 . V_276 =
F_127 ( ( F_124 ( V_802 ) + sizeof( * V_278 ) ) ) ;
V_278 -> V_799 . V_275 = F_132 ( sizeof( struct V_330 ) ) ;
F_59 ( F_124 ( V_802 ) , V_150 + V_151 ) ;
for ( V_68 = 0 ; V_68 < V_804 ; V_68 ++ ) {
V_342 = F_329 ( V_150 + V_805 ) ;
if ( ( V_342 & ~ V_806 ) == V_801 )
break;
F_166 ( V_807 ) ;
}
F_327 ( V_150 ) ;
if ( V_68 == V_804 ) {
F_73 ( & V_29 -> V_30 , L_218 ,
V_793 , type ) ;
return - V_376 ;
}
F_330 ( V_29 , V_800 , V_278 , V_801 ) ;
if ( V_342 & V_808 ) {
F_73 ( & V_29 -> V_30 , L_219 ,
V_793 , type ) ;
return - V_381 ;
}
F_94 ( & V_29 -> V_30 , L_220 ,
V_793 , type ) ;
return 0 ;
}
static int F_331 ( struct V_363 * V_29 ,
void T_15 * V_150 , T_4 V_809 )
{
if ( V_809 ) {
F_94 ( & V_29 -> V_30 , L_221 ) ;
F_59 ( V_809 , V_150 + V_810 ) ;
F_166 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_94 ( & V_29 -> V_30 , L_222 ) ;
V_21 = F_332 ( V_29 , V_811 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
V_21 = F_332 ( V_29 , V_812 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
}
return 0 ;
}
static void F_333 ( char * V_813 , int V_50 )
{
memset ( V_813 , 0 , V_50 ) ;
strncpy ( V_813 , V_41 L_223 V_745 , V_50 - 1 ) ;
}
static int F_334 ( struct V_814 T_15 * V_815 )
{
char * V_813 ;
int V_68 , V_462 = sizeof( V_815 -> V_813 ) ;
V_813 = F_91 ( V_462 , V_201 ) ;
if ( ! V_813 )
return - V_255 ;
F_333 ( V_813 , V_462 ) ;
for ( V_68 = 0 ; V_68 < V_462 ; V_68 ++ )
F_335 ( V_813 [ V_68 ] , & V_815 -> V_813 [ V_68 ] ) ;
F_80 ( V_813 ) ;
return 0 ;
}
static void F_336 ( struct V_814 T_15 * V_815 ,
unsigned char * V_816 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_815 -> V_813 ) ; V_68 ++ )
V_816 [ V_68 ] = F_337 ( & V_815 -> V_813 [ V_68 ] ) ;
}
static int F_338 ( struct V_814 T_15 * V_815 )
{
char * V_816 , * V_817 ;
int V_21 , V_462 = sizeof( V_815 -> V_813 ) ;
V_817 = F_91 ( 2 * V_462 , V_201 ) ;
if ( ! V_817 )
return - V_255 ;
V_816 = V_817 + V_462 ;
F_333 ( V_817 , V_462 ) ;
F_336 ( V_815 , V_816 ) ;
V_21 = ! memcmp ( V_816 , V_817 , V_462 ) ;
F_80 ( V_817 ) ;
return V_21 ;
}
static int F_339 ( struct V_363 * V_29 , T_4 V_67 )
{
T_5 V_818 ;
T_4 V_819 ;
T_5 V_820 ;
void T_15 * V_150 ;
unsigned long V_821 ;
T_4 V_822 ;
int V_21 ;
struct V_814 T_15 * V_815 ;
T_4 V_809 ;
T_6 V_823 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_224 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_824 ;
F_340 ( V_29 , 4 , & V_823 ) ;
F_341 ( V_29 ) ;
V_21 = F_342 ( V_29 , & V_821 ) ;
if ( V_21 )
return V_21 ;
V_150 = F_308 ( V_821 , 0x250 ) ;
if ( ! V_150 )
return - V_255 ;
V_21 = F_343 ( V_29 , V_150 , & V_819 ,
& V_820 , & V_818 ) ;
if ( V_21 )
goto V_825;
V_815 = F_308 ( F_344 ( V_29 ,
V_820 ) + V_818 , sizeof( * V_815 ) ) ;
if ( ! V_815 ) {
V_21 = - V_255 ;
goto V_825;
}
V_21 = F_334 ( V_815 ) ;
if ( V_21 )
goto V_826;
V_822 = F_329 ( & V_815 -> V_822 ) ;
V_809 = V_822 & V_827 ;
if ( V_809 ) {
V_809 = V_828 ;
} else {
V_809 = V_822 & V_829 ;
if ( V_809 ) {
F_9 ( & V_29 -> V_30 ,
L_225 ) ;
V_21 = - V_824 ;
goto V_826;
}
}
V_21 = F_331 ( V_29 , V_150 , V_809 ) ;
if ( V_21 )
goto V_826;
F_345 ( V_29 ) ;
F_346 ( V_29 , 4 , V_823 ) ;
F_166 ( V_830 ) ;
V_21 = F_347 ( V_29 , V_150 , V_831 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_226 ) ;
goto V_826;
}
V_21 = F_338 ( V_150 ) ;
if ( V_21 < 0 )
goto V_826;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_227
L_228 ) ;
V_21 = - V_824 ;
} else {
F_94 ( & V_29 -> V_30 , L_229 ) ;
}
V_826:
F_327 ( V_815 ) ;
V_825:
F_327 ( V_150 ) ;
return V_21 ;
}
static void F_348 ( struct V_42 * V_30 , struct V_814 T_15 * V_832 )
{
#ifdef F_349
int V_68 ;
char V_833 [ 17 ] ;
F_94 ( V_30 , L_230 ) ;
F_94 ( V_30 , L_231 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_833 [ V_68 ] = F_337 ( & ( V_832 -> V_834 [ V_68 ] ) ) ;
V_833 [ 4 ] = '\0' ;
F_94 ( V_30 , L_232 , V_833 ) ;
F_94 ( V_30 , L_233 , F_329 ( & ( V_832 -> V_835 ) ) ) ;
F_94 ( V_30 , L_234 ,
F_329 ( & ( V_832 -> V_836 ) ) ) ;
F_94 ( V_30 , L_235 ,
F_329 ( & ( V_832 -> V_837 ) ) ) ;
F_94 ( V_30 , L_236 ,
F_329 ( & ( V_832 -> V_838 . V_839 ) ) ) ;
F_94 ( V_30 , L_237 ,
F_329 ( & ( V_832 -> V_838 . V_840 ) ) ) ;
F_94 ( V_30 , L_238 ,
F_329 ( & ( V_832 -> V_838 . V_841 ) ) ) ;
F_94 ( V_30 , L_239 ,
F_329 ( & ( V_832 -> V_842 ) ) ) ;
F_94 ( V_30 , L_240 , F_329 ( & ( V_832 -> V_843 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_833 [ V_68 ] = F_337 ( & ( V_832 -> V_844 [ V_68 ] ) ) ;
V_833 [ 16 ] = '\0' ;
F_94 ( V_30 , L_241 , V_833 ) ;
F_94 ( V_30 , L_242 ,
F_329 ( & ( V_832 -> V_845 ) ) ) ;
#endif
}
static int F_350 ( struct V_363 * V_29 , unsigned long V_846 )
{
int V_68 , V_702 , V_847 , V_848 ;
if ( V_846 == V_849 )
return 0 ;
V_702 = 0 ;
for ( V_68 = 0 ; V_68 < V_850 ; V_68 ++ ) {
V_848 = F_351 ( V_29 , V_68 ) & V_851 ;
if ( V_848 == V_852 )
V_702 += 4 ;
else {
V_847 = F_351 ( V_29 , V_68 ) &
V_853 ;
switch ( V_847 ) {
case V_854 :
case V_855 :
V_702 += 4 ;
break;
case V_856 :
V_702 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_243 ) ;
return - 1 ;
break;
}
}
if ( V_702 == V_846 - V_849 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_352 ( struct V_1 * V_22 )
{
if ( V_22 -> V_124 ) {
if ( V_22 -> V_29 -> V_857 )
F_353 ( V_22 -> V_29 ) ;
V_22 -> V_124 = 0 ;
} else if ( V_22 -> V_858 ) {
if ( V_22 -> V_29 -> V_859 )
F_354 ( V_22 -> V_29 ) ;
V_22 -> V_858 = 0 ;
}
}
static void F_355 ( struct V_1 * V_22 )
{
#ifdef F_356
int V_708 , V_68 ;
struct V_860 V_861 [ V_862 ] ;
for ( V_68 = 0 ; V_68 < V_862 ; V_68 ++ ) {
V_861 [ V_68 ] . V_863 = 0 ;
V_861 [ V_68 ] . V_182 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_864;
if ( F_357 ( V_22 -> V_29 , V_865 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_244 ) ;
V_22 -> V_124 = V_862 ;
if ( V_22 -> V_124 > F_358 () )
V_22 -> V_124 = F_358 () ;
V_708 = F_359 ( V_22 -> V_29 , V_861 ,
1 , V_22 -> V_124 ) ;
if ( V_708 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_245 , V_708 ) ;
V_22 -> V_124 = 0 ;
goto V_866;
} else if ( V_708 < V_22 -> V_124 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_246
L_247 , V_708 ) ;
}
V_22 -> V_124 = V_708 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_124 ; V_68 ++ )
V_22 -> V_651 [ V_68 ] = V_861 [ V_68 ] . V_863 ;
return;
}
V_866:
if ( F_357 ( V_22 -> V_29 , V_867 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_248 ) ;
if ( ! F_360 ( V_22 -> V_29 ) )
V_22 -> V_858 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_249 ) ;
}
V_864:
#endif
V_22 -> V_651 [ V_22 -> V_652 ] = V_22 -> V_29 -> V_650 ;
}
static int F_361 ( struct V_363 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_868 , V_869 ;
V_868 = V_29 -> V_870 ;
V_869 = V_29 -> V_871 ;
* V_67 = ( ( V_869 << 16 ) & 0xffff0000 ) |
V_868 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_872 ) ; V_68 ++ )
if ( * V_67 == V_872 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_868 != V_873 &&
V_868 != V_874 ) ||
! V_875 ) {
F_9 ( & V_29 -> V_30 , L_250
L_251 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_872 ) - 1 ;
}
static int F_342 ( struct V_363 * V_29 ,
unsigned long * V_876 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_850 ; V_68 ++ )
if ( F_351 ( V_29 , V_68 ) & V_877 ) {
* V_876 = F_344 ( V_29 , V_68 ) ;
F_274 ( & V_29 -> V_30 , L_252 ,
* V_876 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_253 ) ;
return - V_81 ;
}
static int F_347 ( struct V_363 * V_29 , void T_15 * V_150 ,
int V_878 )
{
int V_68 , V_879 ;
T_4 V_880 ;
if ( V_878 )
V_879 = V_881 ;
else
V_879 = V_882 ;
for ( V_68 = 0 ; V_68 < V_879 ; V_68 ++ ) {
V_880 = F_329 ( V_150 + V_883 ) ;
if ( V_878 ) {
if ( V_880 == V_884 )
return 0 ;
} else {
if ( V_880 != V_884 )
return 0 ;
}
F_166 ( V_885 ) ;
}
F_9 ( & V_29 -> V_30 , L_254 ) ;
return - V_81 ;
}
static int F_343 ( struct V_363 * V_29 , void T_15 * V_150 ,
T_4 * V_819 , T_5 * V_820 ,
T_5 * V_818 )
{
* V_819 = F_329 ( V_150 + V_886 ) ;
* V_818 = F_329 ( V_150 + V_887 ) ;
* V_819 &= ( T_4 ) 0x0000ffff ;
* V_820 = F_350 ( V_29 , * V_819 ) ;
if ( * V_820 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_255 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_362 ( struct V_1 * V_22 )
{
if ( V_22 -> V_888 ) {
F_327 ( V_22 -> V_888 ) ;
V_22 -> V_888 = NULL ;
}
if ( V_22 -> V_815 ) {
F_327 ( V_22 -> V_815 ) ;
V_22 -> V_815 = NULL ;
}
}
static int F_363 ( struct V_1 * V_22 )
{
T_5 V_818 ;
T_4 V_819 ;
T_5 V_820 ;
T_4 V_889 ;
int V_21 ;
V_21 = F_343 ( V_22 -> V_29 , V_22 -> V_150 , & V_819 ,
& V_820 , & V_818 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_815 = F_308 ( F_344 ( V_22 -> V_29 ,
V_820 ) + V_818 , sizeof( * V_22 -> V_815 ) ) ;
if ( ! V_22 -> V_815 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_256 ) ;
return - V_255 ;
}
V_21 = F_334 ( V_22 -> V_815 ) ;
if ( V_21 )
return V_21 ;
V_889 = F_329 ( & V_22 -> V_815 -> V_890 ) ;
V_22 -> V_888 = F_308 ( F_344 ( V_22 -> V_29 ,
V_820 ) + V_818 + V_889 ,
sizeof( * V_22 -> V_888 ) ) ;
if ( ! V_22 -> V_888 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_257 ) ;
F_362 ( V_22 ) ;
return - V_255 ;
}
return 0 ;
}
static void F_364 ( struct V_1 * V_22 )
{
#define F_365 16
F_276 ( F_365 <= V_645 ) ;
V_22 -> V_119 = F_329 ( & V_22 -> V_815 -> V_891 ) ;
if ( V_788 && V_22 -> V_119 > 32 )
V_22 -> V_119 = 32 ;
if ( V_22 -> V_119 < F_365 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_258 ,
V_22 -> V_119 ,
F_365 ) ;
V_22 -> V_119 = F_365 ;
}
}
static int F_366 ( struct V_1 * V_22 )
{
return V_22 -> V_256 > 512 ;
}
static void F_367 ( struct V_1 * V_22 )
{
F_364 ( V_22 ) ;
V_22 -> V_235 = V_22 -> V_119 ;
V_22 -> V_256 = F_329 ( & ( V_22 -> V_815 -> V_892 ) ) ;
V_22 -> V_478 = F_329 ( & ( V_22 -> V_815 -> V_822 ) ) ;
if ( F_366 ( V_22 ) ) {
V_22 -> V_271 = 32 ;
V_22 -> V_254 = V_22 -> V_256 - V_22 -> V_271 ;
V_22 -> V_256 -- ;
} else {
V_22 -> V_271 = 31 ;
V_22 -> V_256 = 31 ;
V_22 -> V_254 = 0 ;
}
V_22 -> V_691 = F_329 ( & ( V_22 -> V_815 -> V_691 ) ) ;
if ( ! ( V_697 & V_22 -> V_691 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
if ( ! ( V_698 & V_22 -> V_691 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
if ( ! ( V_690 & V_22 -> V_691 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_261 ) ;
}
static inline bool F_368 ( struct V_1 * V_22 )
{
if ( ! F_369 ( V_22 -> V_815 -> V_834 , L_262 , 4 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
return false ;
}
return true ;
}
static inline void F_370 ( struct V_1 * V_22 )
{
T_4 V_893 ;
V_893 = F_329 ( & ( V_22 -> V_815 -> V_893 ) ) ;
#ifdef F_371
V_893 |= V_894 ;
#endif
V_893 |= V_895 ;
F_59 ( V_893 , & ( V_22 -> V_815 -> V_893 ) ) ;
}
static inline void F_372 ( struct V_1 * V_22 )
{
T_4 V_896 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_896 = F_329 ( V_22 -> V_150 + V_897 ) ;
V_896 |= 0x8000 ;
F_59 ( V_896 , V_22 -> V_150 + V_897 ) ;
}
static int F_373 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_898 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_899 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_898 = F_329 ( V_22 -> V_150 + V_810 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_898 & V_900 ) )
goto V_901;
F_166 ( V_902 ) ;
}
return - V_81 ;
V_901:
return 0 ;
}
static int F_374 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_898 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_903 ; V_68 ++ ) {
if ( V_22 -> V_904 )
goto V_901;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_898 = F_329 ( V_22 -> V_150 + V_810 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_898 & V_905 ) )
goto V_901;
F_166 ( V_906 ) ;
}
return - V_81 ;
V_901:
return 0 ;
}
static int F_375 ( struct V_1 * V_22 )
{
T_4 V_907 ;
V_907 = F_329 ( & ( V_22 -> V_815 -> V_836 ) ) ;
if ( ! ( V_907 & V_908 ) )
return - V_824 ;
V_22 -> V_119 = F_329 ( & ( V_22 -> V_815 -> V_842 ) ) ;
F_59 ( V_909 , & ( V_22 -> V_815 -> V_838 . V_839 ) ) ;
F_59 ( 0 , & V_22 -> V_815 -> V_838 . V_910 ) ;
F_59 ( V_905 , V_22 -> V_150 + V_810 ) ;
if ( F_374 ( V_22 ) )
goto error;
F_348 ( & V_22 -> V_29 -> V_30 , V_22 -> V_815 ) ;
if ( ! ( F_329 ( & ( V_22 -> V_815 -> V_837 ) ) & V_909 ) )
goto error;
V_22 -> V_63 = V_909 ;
return 0 ;
error:
F_73 ( & V_22 -> V_29 -> V_30 , L_264 ) ;
return - V_81 ;
}
static void F_376 ( struct V_1 * V_22 )
{
F_362 ( V_22 ) ;
F_327 ( V_22 -> V_150 ) ;
V_22 -> V_150 = NULL ;
F_352 ( V_22 ) ;
F_377 ( V_22 -> V_29 ) ;
F_378 ( V_22 -> V_29 ) ;
}
static int F_379 ( struct V_1 * V_22 )
{
int V_911 , V_708 ;
V_911 = F_361 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_911 < 0 )
return V_911 ;
V_22 -> V_912 = V_872 [ V_911 ] . V_912 ;
V_22 -> V_113 = * ( V_872 [ V_911 ] . V_113 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_380 ( V_22 -> V_29 , V_913 |
V_914 | V_915 ) ;
V_708 = F_381 ( V_22 -> V_29 ) ;
if ( V_708 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_265 ) ;
F_377 ( V_22 -> V_29 ) ;
return V_708 ;
}
V_708 = F_382 ( V_22 -> V_29 , V_41 ) ;
if ( V_708 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_266 ) ;
F_377 ( V_22 -> V_29 ) ;
return V_708 ;
}
F_383 ( V_22 -> V_29 ) ;
F_355 ( V_22 ) ;
V_708 = F_342 ( V_22 -> V_29 , & V_22 -> V_821 ) ;
if ( V_708 )
goto V_916;
V_22 -> V_150 = F_308 ( V_22 -> V_821 , 0x250 ) ;
if ( ! V_22 -> V_150 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
V_708 = - V_255 ;
goto V_916;
}
V_708 = F_347 ( V_22 -> V_29 , V_22 -> V_150 , V_831 ) ;
if ( V_708 )
goto V_917;
V_708 = F_363 ( V_22 ) ;
if ( V_708 )
goto V_917;
F_367 ( V_22 ) ;
if ( ! F_368 ( V_22 ) ) {
V_708 = - V_81 ;
goto V_918;
}
F_370 ( V_22 ) ;
F_372 ( V_22 ) ;
V_708 = F_375 ( V_22 ) ;
if ( V_708 )
goto V_918;
return 0 ;
V_918:
F_362 ( V_22 ) ;
V_917:
F_327 ( V_22 -> V_150 ) ;
V_22 -> V_150 = NULL ;
V_916:
F_352 ( V_22 ) ;
F_377 ( V_22 -> V_29 ) ;
F_378 ( V_22 -> V_29 ) ;
return V_708 ;
}
static void F_384 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_385 64
V_22 -> V_61 = F_91 ( F_385 , V_201 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_169 ( V_22 , V_156 , 0 ,
V_22 -> V_61 , F_385 ) ;
if ( V_21 != 0 ) {
F_80 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_386 ( struct V_363 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_150 ;
if ( ! V_788 )
return 0 ;
V_21 = F_381 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_268 ) ;
return - V_81 ;
}
F_377 ( V_29 ) ;
F_166 ( 260 ) ;
V_21 = F_381 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_269 ) ;
return - V_81 ;
}
F_383 ( V_29 ) ;
V_150 = F_324 ( V_29 , 0 ) ;
if ( V_150 == NULL ) {
V_21 = - V_255 ;
goto V_919;
}
F_59 ( V_920 , V_150 + V_921 ) ;
F_327 ( V_150 ) ;
V_21 = F_339 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_919;
F_94 ( & V_29 -> V_30 , L_270 ) ;
for ( V_68 = 0 ; V_68 < V_922 ; V_68 ++ ) {
if ( F_387 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_271 ,
( V_68 < 11 ? L_272 : L_273 ) ) ;
}
V_919:
F_377 ( V_29 ) ;
return V_21 ;
}
static void F_388 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_703 ) ;
V_22 -> V_703 = NULL ;
if ( V_22 -> V_398 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( struct V_8 ) ,
V_22 -> V_398 ,
V_22 -> V_622 ) ;
V_22 -> V_398 = NULL ;
V_22 -> V_622 = 0 ;
}
if ( V_22 -> V_623 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( struct V_330 ) ,
V_22 -> V_623 ,
V_22 -> V_624 ) ;
V_22 -> V_623 = NULL ;
V_22 -> V_624 = 0 ;
}
}
static int F_389 ( struct V_1 * V_22 )
{
V_22 -> V_703 = F_108 (
F_390 ( V_22 -> V_235 , V_603 ) *
sizeof( unsigned long ) , V_201 ) ;
V_22 -> V_398 = F_328 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_398 ) ,
& ( V_22 -> V_622 ) ) ;
V_22 -> V_623 = F_328 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_623 ) ,
& ( V_22 -> V_624 ) ) ;
if ( ( V_22 -> V_703 == NULL )
|| ( V_22 -> V_398 == NULL )
|| ( V_22 -> V_623 == NULL ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_274 , V_202 ) ;
goto V_923;
}
F_251 ( V_22 ) ;
return 0 ;
V_923:
F_388 ( V_22 ) ;
return - V_255 ;
}
static void F_391 ( struct V_1 * V_22 )
{
int V_68 , V_377 ;
V_377 = F_392 ( V_924 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_124 ; V_68 ++ ) {
F_393 ( V_22 -> V_651 [ V_68 ] , F_394 ( V_377 ) ) ;
V_377 = F_395 ( V_377 , V_924 ) ;
}
}
static void F_396 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_124 || V_22 -> V_652 != V_925 ) {
V_68 = V_22 -> V_652 ;
F_393 ( V_22 -> V_651 [ V_68 ] , NULL ) ;
F_397 ( V_22 -> V_651 [ V_68 ] , & V_22 -> V_108 [ V_68 ] ) ;
V_22 -> V_108 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_124 ; V_68 ++ ) {
F_393 ( V_22 -> V_651 [ V_68 ] , NULL ) ;
F_397 ( V_22 -> V_651 [ V_68 ] , & V_22 -> V_108 [ V_68 ] ) ;
V_22 -> V_108 [ V_68 ] = 0 ;
}
for (; V_68 < V_862 ; V_68 ++ )
V_22 -> V_108 [ V_68 ] = 0 ;
}
static int F_398 ( struct V_1 * V_22 ,
T_17 (* F_399)( int , void * ) ,
T_17 (* F_400)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_862 ; V_68 ++ )
V_22 -> V_108 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_652 == V_925 && V_22 -> V_124 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_124 ; V_68 ++ ) {
sprintf ( V_22 -> V_926 [ V_68 ] , L_275 , V_22 -> V_31 , V_68 ) ;
V_21 = F_401 ( V_22 -> V_651 [ V_68 ] , F_399 ,
0 , V_22 -> V_926 [ V_68 ] ,
& V_22 -> V_108 [ V_68 ] ) ;
if ( V_21 ) {
int V_191 ;
F_73 ( & V_22 -> V_29 -> V_30 ,
L_276 ,
V_22 -> V_651 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_191 = 0 ; V_191 < V_68 ; V_191 ++ ) {
F_397 ( V_22 -> V_651 [ V_191 ] , & V_22 -> V_108 [ V_191 ] ) ;
V_22 -> V_108 [ V_191 ] = 0 ;
}
for (; V_191 < V_862 ; V_191 ++ )
V_22 -> V_108 [ V_191 ] = 0 ;
return V_21 ;
}
}
F_391 ( V_22 ) ;
} else {
if ( V_22 -> V_124 > 0 || V_22 -> V_858 ) {
if ( V_22 -> V_124 )
sprintf ( V_22 -> V_926 [ V_22 -> V_652 ] ,
L_277 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_926 [ V_22 -> V_652 ] ,
L_278 , V_22 -> V_31 ) ;
V_21 = F_401 ( V_22 -> V_651 [ V_22 -> V_652 ] ,
F_399 , 0 ,
V_22 -> V_926 [ V_22 -> V_652 ] ,
& V_22 -> V_108 [ V_22 -> V_652 ] ) ;
} else {
sprintf ( V_22 -> V_926 [ V_22 -> V_652 ] ,
L_279 , V_22 -> V_31 ) ;
V_21 = F_401 ( V_22 -> V_651 [ V_22 -> V_652 ] ,
F_400 , V_927 ,
V_22 -> V_926 [ V_22 -> V_652 ] ,
& V_22 -> V_108 [ V_22 -> V_652 ] ) ;
}
F_393 ( V_22 -> V_651 [ V_22 -> V_652 ] , NULL ) ;
}
if ( V_21 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_276 ,
V_22 -> V_651 [ V_22 -> V_652 ] , V_22 -> V_31 ) ;
F_396 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_402 ( struct V_1 * V_22 )
{
int V_21 ;
F_306 ( V_22 , V_156 , V_928 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_280 ) ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_150 , V_929 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_281 ) ;
return V_21 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_282 ) ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_150 , V_831 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_283
L_284 ) ;
return V_21 ;
}
return 0 ;
}
static void F_403 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
if ( ! V_22 -> V_111 [ V_68 ] . V_115 )
continue;
F_330 ( V_22 -> V_29 ,
V_22 -> V_930 ,
V_22 -> V_111 [ V_68 ] . V_115 ,
V_22 -> V_111 [ V_68 ] . V_120 ) ;
V_22 -> V_111 [ V_68 ] . V_115 = NULL ;
V_22 -> V_111 [ V_68 ] . V_120 = 0 ;
}
V_22 -> V_930 = 0 ;
}
static void F_404 ( struct V_1 * V_22 )
{
F_405 ( V_22 ) ;
F_121 ( V_22 ) ;
F_388 ( V_22 ) ;
F_396 ( V_22 ) ;
F_406 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_376 ( V_22 ) ;
F_407 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_320 ) {
F_408 ( V_22 -> V_320 ) ;
V_22 -> V_320 = NULL ;
}
if ( V_22 -> V_931 ) {
F_408 ( V_22 -> V_931 ) ;
V_22 -> V_931 = NULL ;
}
F_80 ( V_22 ) ;
}
static void F_409 ( struct V_1 * V_22 )
{
int V_68 , V_399 ;
struct V_8 * V_9 ;
int V_932 = 0 ;
F_410 ( V_22 -> V_320 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( V_399 > 1 ) {
V_9 -> V_24 -> V_36 = V_336 ;
F_61 ( V_9 ) ;
F_45 ( & V_22 -> V_62 ) ;
V_932 ++ ;
}
F_172 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_285 , V_932 ) ;
}
static void F_411 ( struct V_1 * V_22 , T_4 V_933 )
{
int V_377 ;
F_412 (cpu) {
T_4 * F_13 ;
F_13 = F_163 ( V_22 -> F_13 , V_377 ) ;
* F_13 = V_933 ;
}
F_76 () ;
}
static void F_413 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_329 ( V_22 -> V_150 + V_883 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_286 ,
V_22 -> V_145 / V_936 ) ;
F_13 = 0xffffffff ;
}
F_411 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_287 ,
F_13 , V_22 -> V_145 / V_936 ) ;
F_377 ( V_22 -> V_29 ) ;
F_409 ( V_22 ) ;
}
static int F_270 ( struct V_1 * V_22 )
{
T_5 V_937 ;
T_4 V_938 ;
unsigned long V_78 ;
V_937 = F_319 () ;
if ( F_414 ( V_22 -> V_791 +
( V_22 -> V_145 ) , V_937 ) )
return false ;
if ( F_414 ( V_22 -> V_939 +
( V_22 -> V_145 ) , V_937 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_938 = F_329 ( & V_22 -> V_815 -> V_845 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_940 == V_938 ) {
F_413 ( V_22 ) ;
return true ;
}
V_22 -> V_940 = V_938 ;
V_22 -> V_939 = V_937 ;
return false ;
}
static void F_415 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_941 ;
if ( ! ( V_22 -> V_478 & V_942 ) )
return;
if ( ( V_22 -> V_63 & ( V_112
| V_943 ) ) &&
( V_22 -> V_944 & V_945 ||
V_22 -> V_944 & V_946 ) ) {
if ( V_22 -> V_944 & V_945 )
V_941 = L_288 ;
if ( V_22 -> V_944 & V_946 )
V_941 = L_289 ;
F_416 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_89 = 0 ;
F_417 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_290 ,
V_22 -> V_944 , V_941 ) ;
F_59 ( V_22 -> V_944 , & ( V_22 -> V_815 -> V_947 ) ) ;
F_59 ( V_900 , V_22 -> V_150 + V_810 ) ;
F_373 ( V_22 ) ;
F_418 ( V_22 -> V_59 ) ;
} else {
F_59 ( V_22 -> V_944 , & ( V_22 -> V_815 -> V_947 ) ) ;
F_59 ( V_900 , V_22 -> V_150 + V_810 ) ;
F_373 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_419 ( struct V_1 * V_22 )
{
if ( V_22 -> V_243 ) {
V_22 -> V_243 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_478 & V_942 ) )
return 0 ;
V_22 -> V_944 = F_329 ( & ( V_22 -> V_815 -> V_948 ) ) ;
return V_22 -> V_944 & V_949 ;
}
static int F_420 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_199 * V_383 ;
struct V_950 * V_951 , * V_952 ;
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_421 (this, tmp, &h->offline_device_list) {
V_383 = F_422 ( V_951 , struct V_199 ,
V_203 ) ;
F_36 ( & V_22 -> V_200 , V_78 ) ;
if ( ! F_204 ( V_22 , V_383 -> V_72 ) ) {
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_423 ( & V_383 -> V_203 ) ;
F_36 ( & V_22 -> V_200 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_200 , V_78 ) ;
}
F_36 ( & V_22 -> V_200 , V_78 ) ;
return 0 ;
}
static int F_424 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_458 * V_490 = NULL ;
if ( ! V_22 -> V_953 )
goto V_388;
V_490 = F_108 ( sizeof( * V_490 ) , V_201 ) ;
if ( ! V_490 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_291 ) ;
goto V_388;
}
if ( F_200 ( V_22 , 1 , V_490 , sizeof( * V_490 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_292 ) ;
goto V_388;
}
if ( memcmp ( V_490 , V_22 -> V_953 , sizeof( * V_490 ) ) ) {
F_94 ( & V_22 -> V_29 -> V_30 ,
L_293 ) ;
memcpy ( V_22 -> V_953 , V_490 , sizeof( * V_490 ) ) ;
goto V_388;
} else
V_21 = 0 ;
V_388:
F_80 ( V_490 ) ;
return V_21 ;
}
static void F_425 ( struct V_626 * V_318 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_254 ( F_426 ( V_318 ) ,
struct V_1 , V_954 ) ;
if ( V_22 -> V_904 )
return;
if ( F_419 ( V_22 ) || F_420 ( V_22 ) ) {
F_427 ( V_22 -> V_59 ) ;
F_415 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_406 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_519 ) {
F_428 ( V_22 ) ;
if ( F_424 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_294 ) ;
V_7 = F_427 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_406 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_904 )
F_429 ( V_22 -> V_931 , & V_22 -> V_954 ,
V_22 -> V_145 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_430 ( struct V_626 * V_318 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_254 ( F_426 ( V_318 ) ,
struct V_1 , V_955 ) ;
F_270 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_904 )
F_431 ( & V_22 -> V_955 ,
V_22 -> V_145 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_956 * F_432 ( struct V_1 * V_22 ,
char * V_957 )
{
struct V_956 * V_958 = NULL ;
V_958 = F_433 ( L_295 , 0 , V_957 , V_22 -> V_959 ) ;
if ( ! V_958 )
F_73 ( & V_22 -> V_29 -> V_30 , L_296 , V_957 ) ;
return V_958 ;
}
static int F_434 ( struct V_363 * V_29 , const struct V_960 * V_961 )
{
int V_962 , V_21 ;
struct V_1 * V_22 ;
int V_963 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_964 == 0 )
F_435 (KERN_INFO DRIVER_NAME L_297 ) ;
V_21 = F_361 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_298 ) ;
return V_21 ;
}
V_21 = F_386 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_824 )
return V_21 ;
V_963 = 1 ;
V_21 = 0 ;
}
V_965:
F_276 ( sizeof( struct V_8 ) % V_966 ) ;
V_22 = F_108 ( sizeof( * V_22 ) , V_201 ) ;
if ( ! V_22 ) {
F_73 ( & V_29 -> V_30 , L_299 ) ;
return - V_255 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_652 = V_967 ? V_968 : V_925 ;
F_436 ( & V_22 -> V_204 ) ;
F_437 ( & V_22 -> V_79 ) ;
F_437 ( & V_22 -> V_200 ) ;
F_437 ( & V_22 -> V_631 ) ;
F_115 ( & V_22 -> V_762 , V_969 ) ;
F_115 ( & V_22 -> V_693 , V_970 ) ;
V_22 -> F_13 = F_438 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_300 ) ;
V_21 = - V_255 ;
goto V_971;
}
F_411 ( V_22 , 0 ) ;
V_21 = F_379 ( V_22 ) ;
if ( V_21 )
goto V_916;
V_21 = F_260 ( V_22 ) ;
if ( V_21 )
goto V_972;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_100 ) ;
V_22 -> V_959 = V_964 ;
V_964 ++ ;
V_21 = F_439 ( V_29 , F_326 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_962 = 1 ;
} else {
V_21 = F_439 ( V_29 , F_326 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_962 = 0 ;
} else {
F_73 ( & V_29 -> V_30 , L_301 ) ;
goto V_917;
}
}
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
V_21 = F_398 ( V_22 , F_322 , F_321 ) ;
if ( V_21 )
goto V_917;
V_21 = F_389 ( V_22 ) ;
if ( V_21 )
goto V_918;
V_21 = F_122 ( V_22 ) ;
if ( V_21 )
goto V_973;
F_440 ( & V_22 -> V_633 ) ;
F_440 ( & V_22 -> V_692 ) ;
F_440 ( & V_22 -> V_316 ) ;
F_441 ( & V_22 -> V_396 ) ;
V_22 -> V_632 = 1 ;
F_442 ( V_29 , V_22 ) ;
V_22 -> V_160 = 0 ;
F_437 ( & V_22 -> V_96 ) ;
V_21 = F_443 ( V_22 ) ;
if ( V_21 )
goto V_974;
V_21 = F_262 ( V_22 ) ;
if ( V_21 )
goto V_975;
V_22 -> V_931 = F_432 ( V_22 , L_302 ) ;
if ( ! V_22 -> V_931 ) {
V_21 = - V_255 ;
goto V_975;
}
V_22 -> V_320 = F_432 ( V_22 , L_303 ) ;
if ( ! V_22 -> V_320 ) {
V_21 = - V_255 ;
goto V_975;
}
if ( V_963 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_396 ( V_22 ) ;
V_21 = F_398 ( V_22 , F_320 ,
F_318 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_304 ) ;
F_405 ( V_22 ) ;
F_121 ( V_22 ) ;
F_388 ( V_22 ) ;
goto V_917;
}
V_21 = F_402 ( V_22 ) ;
if ( V_21 )
goto V_975;
F_94 ( & V_22 -> V_29 -> V_30 , L_305 ) ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_306 ) ;
V_22 -> V_113 . V_934 ( V_22 , V_976 ) ;
F_166 ( 10000 ) ;
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
V_21 = F_338 ( V_22 -> V_815 ) ;
if ( V_21 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_307 ) ;
F_404 ( V_22 ) ;
V_963 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_965;
}
V_22 -> V_56 = 1 ;
V_22 -> V_519 = 0 ;
V_22 -> V_113 . V_934 ( V_22 , V_976 ) ;
F_384 ( V_22 ) ;
V_22 -> V_953 = F_108 ( sizeof( * ( V_22 -> V_953 ) ) , V_201 ) ;
if ( ! V_22 -> V_953 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_308 ) ;
V_22 -> V_145 = V_147 ;
F_444 ( & V_22 -> V_955 , F_430 ) ;
F_431 ( & V_22 -> V_955 ,
V_22 -> V_145 ) ;
F_444 ( & V_22 -> V_954 , F_425 ) ;
F_429 ( V_22 -> V_931 , & V_22 -> V_954 ,
V_22 -> V_145 ) ;
return 0 ;
V_975:
F_405 ( V_22 ) ;
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
V_974:
F_121 ( V_22 ) ;
V_973:
F_388 ( V_22 ) ;
V_918:
F_396 ( V_22 ) ;
V_917:
F_406 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_972:
F_376 ( V_22 ) ;
V_916:
if ( V_22 -> F_13 ) {
F_407 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_971:
if ( V_22 -> V_320 ) {
F_408 ( V_22 -> V_320 ) ;
V_22 -> V_320 = NULL ;
}
if ( V_22 -> V_931 ) {
F_408 ( V_22 -> V_931 ) ;
V_22 -> V_931 = NULL ;
}
F_80 ( V_22 ) ;
return V_21 ;
}
static void F_445 ( struct V_1 * V_22 )
{
char * V_977 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return;
V_977 = F_108 ( 4 , V_201 ) ;
if ( ! V_977 )
return;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_770 , V_22 , V_977 , 4 , 0 ,
V_156 , V_387 ) ) {
goto V_388;
}
V_21 = F_165 ( V_22 , V_9 ,
V_265 , V_374 ) ;
if ( V_21 )
goto V_388;
if ( V_9 -> V_24 -> V_36 != 0 )
V_388:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_309 ) ;
F_172 ( V_22 , V_9 ) ;
F_80 ( V_977 ) ;
}
static void F_428 ( struct V_1 * V_22 )
{
T_4 * V_978 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( V_22 -> F_13 ) )
return;
V_978 = F_108 ( sizeof( * V_978 ) , V_201 ) ;
if ( ! V_978 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_310 ) ;
return;
}
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_767 , V_22 , V_978 , 4 , 0 ,
V_156 , V_387 ) )
goto V_979;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_979;
* V_978 |= V_980 ;
if ( F_171 ( V_9 , V_769 , V_22 , V_978 , 4 , 0 ,
V_156 , V_387 ) )
goto V_979;
V_21 = F_165 ( V_22 , V_9 ,
V_265 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_979;
if ( F_171 ( V_9 , V_767 , V_22 , V_978 , 4 , 0 ,
V_156 , V_387 ) )
goto V_979;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_979;
if ( * V_978 & V_980 )
goto V_388;
V_979:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
V_388:
F_172 ( V_22 , V_9 ) ;
F_80 ( V_978 ) ;
}
static void F_446 ( struct V_363 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_447 ( V_29 ) ;
F_445 ( V_22 ) ;
V_22 -> V_113 . V_934 ( V_22 , V_935 ) ;
F_396 ( V_22 ) ;
F_352 ( V_22 ) ;
}
static void F_448 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
F_80 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_449 ( struct V_363 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_447 ( V_29 ) == NULL ) {
F_73 ( & V_29 -> V_30 , L_312 ) ;
return;
}
V_22 = F_447 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_904 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_450 ( & V_22 -> V_955 ) ;
F_450 ( & V_22 -> V_954 ) ;
F_408 ( V_22 -> V_931 ) ;
F_408 ( V_22 -> V_320 ) ;
if ( V_22 -> V_59 )
F_451 ( V_22 -> V_59 ) ;
F_446 ( V_29 ) ;
F_448 ( V_22 ) ;
F_80 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_119 ( V_22 ) ;
F_405 ( V_22 ) ;
F_121 ( V_22 ) ;
F_388 ( V_22 ) ;
F_80 ( V_22 -> V_953 ) ;
F_406 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_376 ( V_22 ) ;
F_407 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_452 ( V_22 ) ;
F_80 ( V_22 ) ;
}
static void F_453 ( int V_981 [] , int V_982 ,
int V_983 , int V_984 , T_4 * V_985 )
{
int V_68 , V_191 , V_986 , V_462 ;
for ( V_68 = 0 ; V_68 <= V_983 ; V_68 ++ ) {
V_462 = V_68 + V_984 ;
V_986 = V_982 ;
for ( V_191 = 0 ; V_191 < V_982 ; V_191 ++ ) {
if ( V_981 [ V_191 ] >= V_462 ) {
V_986 = V_191 ;
break;
}
}
V_985 [ V_68 ] = V_986 ;
}
}
static int F_454 ( struct V_1 * V_22 , T_4 V_907 )
{
int V_68 ;
unsigned long V_987 ;
unsigned long V_63 = V_64 |
( V_907 & V_988 ) |
V_989 |
( V_907 & ( V_112 |
V_943 ) ) ;
struct V_990 V_113 = V_991 ;
int V_992 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_759 + 4 } ;
#define F_455 5
#define F_456 4
int V_993 [ 16 ] = { F_455 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_456 + V_994 } ;
F_276 ( F_26 ( V_993 ) != 16 ) ;
F_276 ( F_26 ( V_992 ) != 8 ) ;
F_276 ( F_244 ( struct V_137 , V_263 ) >
16 * F_455 ) ;
F_276 ( sizeof( struct V_259 ) != 16 ) ;
F_276 ( 28 > V_759 + 4 ) ;
if ( V_907 & ( V_112 | V_943 ) )
V_113 = V_995 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ )
memset ( V_22 -> V_111 [ V_68 ] . V_115 , 0 , V_22 -> V_930 ) ;
V_992 [ 7 ] = V_759 + 4 ;
F_453 ( V_992 , F_26 ( V_992 ) ,
V_759 , 4 , V_22 -> V_121 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_59 ( V_992 [ V_68 ] , & V_22 -> V_888 -> V_996 [ V_68 ] ) ;
F_59 ( V_22 -> V_119 , & V_22 -> V_888 -> V_997 ) ;
F_59 ( V_22 -> V_127 , & V_22 -> V_888 -> V_998 ) ;
F_59 ( 0 , & V_22 -> V_888 -> V_999 ) ;
F_59 ( 0 , & V_22 -> V_888 -> V_1000 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
F_59 ( 0 , & V_22 -> V_888 -> V_1001 [ V_68 ] . V_1002 ) ;
F_59 ( V_22 -> V_111 [ V_68 ] . V_120 ,
& V_22 -> V_888 -> V_1001 [ V_68 ] . V_1003 ) ;
}
F_59 ( 0 , & V_22 -> V_815 -> V_838 . V_910 ) ;
F_59 ( V_63 , & ( V_22 -> V_815 -> V_838 . V_839 ) ) ;
if ( V_907 & V_112 ) {
V_113 = V_1004 ;
F_59 ( 10 , & V_22 -> V_815 -> V_838 . V_840 ) ;
F_59 ( 4 , & V_22 -> V_815 -> V_838 . V_841 ) ;
} else {
if ( V_907 & V_943 ) {
V_113 = V_1005 ;
F_59 ( 10 , & V_22 -> V_815 -> V_838 . V_840 ) ;
F_59 ( 4 , & V_22 -> V_815 -> V_838 . V_841 ) ;
}
}
F_59 ( V_905 , V_22 -> V_150 + V_810 ) ;
if ( F_374 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_313 ) ;
return - V_81 ;
}
V_987 = F_329 ( & ( V_22 -> V_815 -> V_837 ) ) ;
if ( ! ( V_987 & V_64 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_314 ) ;
return - V_81 ;
}
V_22 -> V_113 = V_113 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_907 & V_112 ) ||
( V_907 & V_943 ) ) )
return 0 ;
if ( V_907 & V_112 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
F_59 ( V_68 , V_22 -> V_150 + V_1006 ) ;
V_22 -> V_111 [ V_68 ] . V_116 =
F_329 ( V_22 -> V_150 + V_1007 ) ;
}
V_992 [ 7 ] = V_22 -> V_543 + 8 ;
F_453 ( V_992 , F_26 ( V_992 ) , V_22 -> V_543 , 8 ,
V_22 -> V_132 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ )
memset ( V_22 -> V_111 [ V_68 ] . V_115 ,
( T_1 ) V_1008 ,
V_22 -> V_930 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
struct V_128 * V_129 = & V_22 -> V_130 [ V_68 ] ;
V_129 -> V_1009 = V_1010 ;
V_129 -> V_24 = ( T_4 ) ( V_22 -> V_624 +
( V_68 * sizeof( struct V_330 ) ) ) ;
V_129 -> V_1011 = sizeof( struct V_330 ) ;
V_129 -> V_1012 = V_1013 ;
V_129 -> V_1014 =
F_153 ( V_1015 ) ;
V_129 -> V_1016 = 0 ;
V_129 -> V_126 = 0 ;
V_129 -> V_342 =
F_127 ( ( V_68 << V_574 ) ) ;
V_129 -> V_1017 =
F_127 ( V_22 -> V_546 +
( V_68 * sizeof( struct V_128 ) ) ) ;
}
} else if ( V_907 & V_943 ) {
T_5 V_818 , V_820 ;
T_4 V_1018 , V_819 ;
int V_21 ;
V_21 = F_343 ( V_22 -> V_29 , V_22 -> V_150 , & V_819 ,
& V_820 , & V_818 ) ;
F_276 ( F_244 ( struct V_137 , V_263 ) != 64 ) ;
V_993 [ 15 ] = V_22 -> V_543 + F_456 ;
F_453 ( V_993 , F_26 ( V_993 ) , V_22 -> V_543 ,
4 , V_22 -> V_136 ) ;
V_1018 = F_329 ( & V_22 -> V_815 -> V_1019 ) ;
F_276 ( F_244 ( struct V_814 ,
V_1019 ) != 0xb8 ) ;
V_22 -> V_1020 =
F_308 ( F_344 ( V_22 -> V_29 ,
V_820 ) +
V_818 + V_1018 ,
F_26 ( V_993 ) *
sizeof( * V_22 -> V_1020 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_993 ) ; V_68 ++ )
F_59 ( V_993 [ V_68 ] , & V_22 -> V_1020 [ V_68 ] ) ;
}
F_59 ( V_905 , V_22 -> V_150 + V_810 ) ;
if ( F_374 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_315 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_457 ( struct V_1 * V_22 )
{
if ( V_22 -> V_130 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_130 ) ,
V_22 -> V_130 ,
V_22 -> V_546 ) ;
V_22 -> V_130 = NULL ;
V_22 -> V_546 = 0 ;
}
F_80 ( V_22 -> V_132 ) ;
V_22 -> V_132 = NULL ;
}
static int F_458 ( struct V_1 * V_22 )
{
V_22 -> V_543 =
F_329 ( & ( V_22 -> V_815 -> V_1021 ) ) ;
if ( V_22 -> V_543 > V_1022 )
V_22 -> V_543 = V_1022 ;
F_276 ( sizeof( struct V_128 ) %
V_1023 ) ;
V_22 -> V_130 =
F_328 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_130 ) ,
& ( V_22 -> V_546 ) ) ;
V_22 -> V_132 =
F_91 ( ( ( V_22 -> V_543 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ( V_22 -> V_130 == NULL ) ||
( V_22 -> V_132 == NULL ) )
goto V_923;
memset ( V_22 -> V_130 , 0 ,
V_22 -> V_235 * sizeof( * V_22 -> V_130 ) ) ;
return 0 ;
V_923:
F_457 ( V_22 ) ;
return - V_255 ;
}
static void F_459 ( struct V_1 * V_22 )
{
F_119 ( V_22 ) ;
if ( V_22 -> V_135 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_135 ) ,
V_22 -> V_135 ,
V_22 -> V_565 ) ;
V_22 -> V_135 = NULL ;
V_22 -> V_565 = 0 ;
}
F_80 ( V_22 -> V_136 ) ;
V_22 -> V_136 = NULL ;
}
static int F_460 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_543 =
F_329 ( & ( V_22 -> V_815 -> V_1021 ) ) ;
if ( V_22 -> V_543 > V_994 )
V_22 -> V_543 = V_994 ;
F_276 ( sizeof( struct V_137 ) %
V_1024 ) ;
V_22 -> V_135 =
F_328 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_135 ) ,
& ( V_22 -> V_565 ) ) ;
V_22 -> V_136 =
F_91 ( ( ( V_22 -> V_543 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ( V_22 -> V_135 == NULL ) ||
( V_22 -> V_136 == NULL ) ) {
V_21 = - V_255 ;
goto V_923;
}
V_21 = F_120 ( V_22 ) ;
if ( V_21 )
goto V_923;
memset ( V_22 -> V_135 , 0 ,
V_22 -> V_235 * sizeof( * V_22 -> V_135 ) ) ;
return 0 ;
V_923:
F_459 ( V_22 ) ;
return V_21 ;
}
static void F_405 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_121 ) ;
V_22 -> V_121 = NULL ;
F_403 ( V_22 ) ;
F_457 ( V_22 ) ;
F_459 ( V_22 ) ;
}
static int F_443 ( struct V_1 * V_22 )
{
T_4 V_907 ;
unsigned long V_63 = V_64 |
V_988 ;
int V_68 , V_21 ;
if ( V_967 )
return 0 ;
V_907 = F_329 ( & ( V_22 -> V_815 -> V_836 ) ) ;
if ( ! ( V_907 & V_1025 ) )
return 0 ;
if ( V_907 & V_112 ) {
V_63 |= V_112 |
V_989 ;
V_21 = F_458 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_907 & V_943 ) {
V_63 |= V_943 |
V_989 ;
V_21 = F_460 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_127 = V_22 -> V_124 > 0 ? V_22 -> V_124 : 1 ;
F_364 ( V_22 ) ;
V_22 -> V_930 = V_22 -> V_119 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
V_22 -> V_111 [ V_68 ] . V_115 = F_328 ( V_22 -> V_29 ,
V_22 -> V_930 ,
& ( V_22 -> V_111 [ V_68 ] . V_120 ) ) ;
if ( ! V_22 -> V_111 [ V_68 ] . V_115 ) {
V_21 = - V_255 ;
goto V_971;
}
V_22 -> V_111 [ V_68 ] . V_462 = V_22 -> V_119 ;
V_22 -> V_111 [ V_68 ] . V_117 = 1 ;
V_22 -> V_111 [ V_68 ] . V_116 = 0 ;
}
V_22 -> V_121 = F_91 ( ( ( V_759 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ! V_22 -> V_121 ) {
V_21 = - V_255 ;
goto V_971;
}
V_21 = F_454 ( V_22 , V_907 ) ;
if ( V_21 )
goto V_916;
return 0 ;
V_916:
F_80 ( V_22 -> V_121 ) ;
V_22 -> V_121 = NULL ;
V_971:
F_403 ( V_22 ) ;
F_457 ( V_22 ) ;
F_459 ( V_22 ) ;
return V_21 ;
}
static int F_461 ( struct V_8 * V_9 )
{
return V_9 -> V_148 == V_149 || V_9 -> V_148 == V_152 ;
}
static void F_417 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1026 ;
int V_399 ;
do {
V_1026 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( V_399 > 1 )
V_1026 += F_461 ( V_9 ) ;
F_172 ( V_22 , V_9 ) ;
}
if ( V_1026 <= 0 )
break;
F_166 ( 100 ) ;
} while ( 1 );
}
static struct V_1027 * F_462 (
struct V_1028 * V_1028 )
{
struct V_1027 * V_1027 ;
struct V_1029 * V_1030 ;
V_1027 = F_108 ( sizeof( * V_1027 ) , V_201 ) ;
if ( ! V_1027 )
return NULL ;
V_1030 = F_463 ( V_1028 -> V_1031 -> V_1032 ,
V_1028 -> V_1033 ) ;
if ( ! V_1030 ) {
F_80 ( V_1027 ) ;
return NULL ;
}
V_1028 -> V_1033 ++ ;
V_1027 -> V_1030 = V_1030 ;
V_1027 -> V_1034 = V_1028 ;
return V_1027 ;
}
static void F_464 ( struct V_1027 * V_1027 )
{
struct V_1029 * V_1030 = V_1027 -> V_1030 ;
F_465 ( V_1027 -> V_1034 -> V_1035 , V_1030 ) ;
F_466 ( V_1030 ) ;
if ( V_1027 -> V_1036 )
F_423 ( & V_1027 -> V_1037 ) ;
F_80 ( V_1027 ) ;
}
static int F_467 ( struct V_1027 * V_1027 )
{
int V_21 ;
struct V_1028 * V_1028 ;
struct V_1029 * V_1030 ;
struct V_1038 * V_1039 ;
V_1028 = V_1027 -> V_1034 ;
V_1030 = V_1027 -> V_1030 ;
V_1039 = & V_1030 -> V_1039 ;
memset ( V_1039 , 0 , sizeof( * V_1039 ) ) ;
V_1039 -> V_446 = V_1028 -> V_446 ;
V_1039 -> V_518 = V_1040 ;
V_1039 -> V_1041 = V_1042 ;
V_1039 -> V_1043 = V_1042 ;
V_1030 -> V_1044 = V_1045 ;
V_1030 -> V_1046 = V_1045 ;
V_1030 -> V_1047 = V_1045 ;
V_1030 -> V_1048 = V_1045 ;
V_1030 -> V_1049 = V_1045 ;
V_21 = F_468 ( V_1027 -> V_1030 ) ;
if ( V_21 )
return V_21 ;
F_469 ( V_1028 -> V_1035 , V_1027 -> V_1030 ) ;
F_92 ( & V_1027 -> V_1037 ,
& V_1028 -> V_1050 ) ;
V_1027 -> V_1036 = true ;
return 0 ;
}
static int
F_470 ( struct V_1028 * V_1028 ,
struct V_248 * V_249 )
{
struct V_1038 * V_1039 ;
V_1039 = & V_249 -> V_1039 ;
V_1039 -> V_446 = V_1028 -> V_446 ;
V_1039 -> V_1041 = V_1042 ;
V_1039 -> V_1043 = V_1042 ;
return F_471 ( V_249 ) ;
}
static struct V_1028
* F_472 ( struct V_1051 * V_1051 ,
T_5 V_446 )
{
int V_21 ;
struct V_1028 * V_1028 ;
struct V_1052 * V_1035 ;
V_1028 = F_108 ( sizeof( * V_1028 ) , V_201 ) ;
if ( ! V_1028 )
return NULL ;
F_436 ( & V_1028 -> V_1050 ) ;
V_1028 -> V_1031 = V_1051 ;
V_1035 = F_473 ( V_1051 -> V_1032 ) ;
if ( ! V_1035 )
goto V_1053;
V_21 = F_474 ( V_1035 ) ;
if ( V_21 )
goto V_1054;
V_1028 -> V_1035 = V_1035 ;
V_1028 -> V_446 = V_446 ;
F_92 ( & V_1028 -> V_1055 ,
& V_1051 -> V_1056 ) ;
return V_1028 ;
V_1054:
F_475 ( V_1035 ) ;
V_1053:
F_80 ( V_1028 ) ;
return NULL ;
}
static void F_476 ( struct V_1028 * V_1028 )
{
struct V_1027 * V_1027 ;
struct V_1027 * V_1057 ;
F_477 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_464 ( V_1027 ) ;
F_478 ( V_1028 -> V_1035 ) ;
F_423 ( & V_1028 -> V_1055 ) ;
F_80 ( V_1028 ) ;
}
static struct V_1051 * F_479 ( struct V_42 * V_1032 )
{
struct V_1051 * V_1051 ;
V_1051 = F_108 ( sizeof( * V_1051 ) , V_201 ) ;
if ( V_1051 ) {
V_1051 -> V_1032 = V_1032 ;
F_436 ( & V_1051 -> V_1056 ) ;
}
return V_1051 ;
}
static void F_480 ( struct V_1051 * V_1051 )
{
struct V_1028 * V_1028 ;
struct V_1028 * V_1057 ;
if ( ! V_1051 )
return;
F_477 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_476 ( V_1028 ) ;
F_80 ( V_1051 ) ;
}
static struct V_73
* F_113 ( struct V_1 * V_22 ,
struct V_248 * V_249 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_160 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1052 )
continue;
if ( V_42 -> V_1052 -> V_249 == V_249 )
return V_42 ;
}
return NULL ;
}
static int F_229 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1032 ;
struct V_1051 * V_1051 ;
struct V_1028 * V_1028 ;
struct V_1027 * V_1027 ;
V_1032 = & V_22 -> V_59 -> V_1058 ;
V_1051 = F_479 ( V_1032 ) ;
if ( ! V_1051 )
return - V_255 ;
V_1028 = F_472 ( V_1051 , V_22 -> V_446 ) ;
if ( ! V_1028 ) {
V_21 = - V_81 ;
goto V_1059;
}
V_1027 = F_462 ( V_1028 ) ;
if ( ! V_1027 ) {
V_21 = - V_81 ;
goto V_1054;
}
V_21 = F_467 ( V_1027 ) ;
if ( V_21 )
goto V_1060;
V_22 -> V_236 = V_1051 ;
return 0 ;
V_1060:
F_464 ( V_1027 ) ;
V_1054:
F_476 ( V_1028 ) ;
V_1059:
F_480 ( V_1051 ) ;
return V_21 ;
}
static void F_452 ( struct V_1 * V_22 )
{
F_480 ( V_22 -> V_236 ) ;
}
static int F_101 ( struct V_1051 * V_1051 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1028 * V_1028 ;
struct V_248 * V_249 ;
V_1028 = F_472 ( V_1051 , V_42 -> V_446 ) ;
if ( ! V_1028 )
return - V_255 ;
V_249 = F_481 ( V_1028 -> V_1035 ) ;
if ( ! V_249 ) {
V_21 = - V_81 ;
goto V_1054;
}
V_1028 -> V_249 = V_249 ;
V_42 -> V_1052 = V_1028 ;
V_21 = F_470 ( V_1028 , V_249 ) ;
if ( V_21 )
goto V_1054;
return 0 ;
V_1054:
F_476 ( V_1028 ) ;
V_42 -> V_1052 = NULL ;
return V_21 ;
}
static void F_106 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1052 ) {
F_476 ( V_42 -> V_1052 ) ;
V_42 -> V_1052 = NULL ;
}
}
static int
F_482 ( struct V_1029 * V_1030 )
{
return 0 ;
}
static int
F_483 ( struct V_248 * V_249 , T_5 * V_1061 )
{
return 0 ;
}
static int
F_484 ( struct V_248 * V_249 )
{
return - V_1062 ;
}
static int
F_485 ( struct V_1029 * V_1030 , int V_1063 )
{
return 0 ;
}
static int
F_486 ( struct V_1029 * V_1030 , int V_1064 )
{
return 0 ;
}
static int
F_487 ( struct V_1029 * V_1030 )
{
return 0 ;
}
static void
F_488 ( struct V_1029 * V_1030 )
{
}
static int
F_489 ( struct V_1029 * V_1030 , struct V_1065 * V_1066 )
{
return - V_55 ;
}
static int
F_490 ( struct V_6 * V_47 , struct V_248 * V_249 ,
struct V_628 * V_1067 )
{
return - V_55 ;
}
static int T_18 F_491 ( void )
{
int V_21 ;
V_649 =
F_492 ( & V_1068 ) ;
if ( ! V_649 )
return - V_81 ;
V_21 = F_493 ( & V_1069 ) ;
if ( V_21 )
F_494 ( V_649 ) ;
return V_21 ;
}
static void T_19 F_495 ( void )
{
F_496 ( & V_1069 ) ;
F_494 ( V_649 ) ;
}
