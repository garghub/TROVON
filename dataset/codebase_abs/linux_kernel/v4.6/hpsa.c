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
if ( ( V_77 -> V_104 == V_106 || V_77 -> V_104 == V_107 ) &&
V_77 -> V_108 ) {
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
static inline T_4 F_43 ( struct V_1 * V_22 , T_1 V_109 )
{
T_4 V_65 ;
struct V_110 * V_111 = & V_22 -> V_112 [ V_109 ] ;
if ( V_22 -> V_63 & V_113 )
return V_22 -> V_114 . V_115 ( V_22 , V_109 ) ;
if ( F_44 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_114 . V_115 ( V_22 , V_109 ) ;
if ( ( V_111 -> V_116 [ V_111 -> V_117 ] & 1 ) == V_111 -> V_118 ) {
V_65 = V_111 -> V_116 [ V_111 -> V_117 ] ;
V_111 -> V_117 ++ ;
F_45 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_119 ;
}
if ( V_111 -> V_117 == V_22 -> V_120 ) {
V_111 -> V_117 = 0 ;
V_111 -> V_118 ^= 1 ;
}
return V_65 ;
}
static void F_46 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_112 )
{
if ( F_47 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_121 |= 1 | ( V_22 -> V_122 [ V_9 -> V_123 . V_124 ] << 1 ) ;
if ( F_44 ( ! V_22 -> V_125 ) )
return;
if ( F_47 ( V_112 == V_126 ) )
V_9 -> V_123 . V_127 =
F_48 () % V_22 -> V_128 ;
else
V_9 -> V_123 . V_127 = V_112 % V_22 -> V_128 ;
}
}
static void F_49 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_129 * V_130 = & V_22 -> V_131 [ V_9 -> V_132 ] ;
if ( F_47 ( V_112 == V_126 ) )
V_130 -> V_127 = F_50 () % V_22 -> V_128 ;
else
V_130 -> V_127 = V_112 % V_22 -> V_128 ;
V_9 -> V_121 |= 1 | ( V_22 -> V_133 [ V_9 -> V_123 . V_124 ] << 1 ) |
V_134 ;
}
static void F_51 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_135 * V_130 = (struct V_135 * )
& V_22 -> V_136 [ V_9 -> V_132 ] ;
if ( F_47 ( V_112 == V_126 ) )
V_130 -> V_112 = F_50 () % V_22 -> V_128 ;
else
V_130 -> V_112 = V_112 % V_22 -> V_128 ;
V_9 -> V_121 |= V_22 -> V_137 [ 0 ] ;
}
static void F_52 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_138 * V_130 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
if ( F_47 ( V_112 == V_126 ) )
V_130 -> V_112 = F_50 () % V_22 -> V_128 ;
else
V_130 -> V_112 = V_112 % V_22 -> V_128 ;
V_9 -> V_121 |= ( V_22 -> V_137 [ V_130 -> V_139 ] ) ;
}
static int F_53 ( T_1 * V_140 )
{
return V_140 [ 0 ] == V_141 && V_140 [ 6 ] == V_142 ;
}
static void F_54 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_53 ( V_9 -> V_143 . V_144 ) )
return;
F_55 ( & V_22 -> V_145 ) ;
V_22 -> V_146 = V_147 ;
}
static void F_56 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_53 ( V_9 -> V_143 . V_144 ) &&
F_57 ( & V_22 -> V_145 ) )
V_22 -> V_146 = V_148 ;
}
static void F_58 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_112 )
{
F_54 ( V_22 , V_9 ) ;
F_55 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_149 ) {
case V_150 :
F_49 ( V_22 , V_9 , V_112 ) ;
F_59 ( V_9 -> V_121 , V_22 -> V_151 + V_152 ) ;
break;
case V_153 :
F_52 ( V_22 , V_9 , V_112 ) ;
F_59 ( V_9 -> V_121 , V_22 -> V_151 + V_154 ) ;
break;
case V_155 :
F_51 ( V_22 , V_9 , V_112 ) ;
F_59 ( V_9 -> V_121 , V_22 -> V_151 + V_154 ) ;
break;
default:
F_46 ( V_22 , V_9 , V_112 ) ;
V_22 -> V_114 . V_156 ( V_22 , V_9 ) ;
}
}
static void F_60 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_44 ( F_5 ( V_9 ) ) )
return F_61 ( V_9 ) ;
F_58 ( V_22 , V_9 , V_126 ) ;
}
static inline int F_62 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_157 , 8 ) == 0 ;
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
int V_68 , V_158 = 0 ;
F_65 ( V_159 , V_160 ) ;
F_66 ( V_159 , V_160 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_101 == V_101 && V_22 -> V_30 [ V_68 ] -> V_102 != - 1 )
F_67 ( V_22 -> V_30 [ V_68 ] -> V_102 , V_159 ) ;
}
V_68 = F_68 ( V_159 , V_160 ) ;
if ( V_68 < V_160 ) {
* V_102 = V_68 ;
* V_103 = 0 ;
V_158 = 1 ;
}
return ! V_158 ;
}
static void F_69 ( const char * V_162 , struct V_1 * V_22 ,
struct V_73 * V_30 , char * V_163 )
{
#define F_70 25
char V_164 [ F_70 ] ;
if ( V_22 == NULL || V_22 -> V_29 == NULL || V_22 -> V_59 == NULL )
return;
switch ( V_30 -> V_104 ) {
case V_105 :
snprintf ( V_164 , F_70 , L_32 ) ;
break;
case V_165 :
snprintf ( V_164 , F_70 , L_33 ) ;
break;
case V_106 :
case V_107 :
if ( V_30 -> V_166 )
snprintf ( V_164 , F_70 , L_34 ) ;
else if ( ! F_31 ( V_30 -> V_72 ) )
snprintf ( V_164 , F_70 , L_35 ,
V_85 [ V_167 ] ) ;
else
snprintf ( V_164 , F_70 , L_36 ,
V_30 -> V_83 > V_84 ? L_37 :
V_85 [ V_30 -> V_83 ] ) ;
break;
case V_168 :
snprintf ( V_164 , F_70 , L_38 ) ;
break;
case V_169 :
snprintf ( V_164 , F_70 , L_39 ) ;
break;
case V_170 :
snprintf ( V_164 , F_70 , L_40 ) ;
break;
default:
snprintf ( V_164 , F_70 , L_41 ) ;
break;
}
F_71 ( V_162 , & V_22 -> V_29 -> V_30 ,
L_42 ,
V_22 -> V_59 -> V_100 , V_30 -> V_101 , V_30 -> V_102 , V_30 -> V_103 ,
V_163 ,
F_42 ( V_30 -> V_104 ) ,
V_30 -> V_171 ,
V_30 -> V_172 ,
V_164 ,
V_30 -> V_173 ? '+' : '-' ,
V_30 -> V_89 ? '+' : '-' ,
V_30 -> V_108 ) ;
}
static int F_72 ( struct V_1 * V_22 ,
struct V_73 * V_42 ,
struct V_73 * V_174 [] , int * V_175 )
{
int V_176 = V_22 -> V_161 ;
int V_68 ;
unsigned char V_177 [ 8 ] , V_178 [ 8 ] ;
struct V_73 * V_179 ;
if ( V_176 >= V_160 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_43
L_44 ) ;
return - 1 ;
}
if ( V_42 -> V_103 != - 1 )
goto V_180;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_64 ( V_22 , V_42 -> V_72 ,
V_42 -> V_101 , & V_42 -> V_102 , & V_42 -> V_103 ) != 0 )
return - 1 ;
goto V_180;
}
memcpy ( V_177 , V_42 -> V_72 , 8 ) ;
V_177 [ 4 ] = 0 ;
V_177 [ 5 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_176 ; V_68 ++ ) {
V_179 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_178 , V_179 -> V_72 , 8 ) ;
V_178 [ 4 ] = 0 ;
V_178 [ 5 ] = 0 ;
if ( memcmp ( V_177 , V_178 , 8 ) == 0 ) {
V_42 -> V_101 = V_179 -> V_101 ;
V_42 -> V_102 = V_179 -> V_102 ;
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
V_180:
V_22 -> V_30 [ V_176 ] = V_42 ;
V_22 -> V_161 ++ ;
V_174 [ * V_175 ] = V_42 ;
( * V_175 ) ++ ;
F_69 ( V_181 , V_22 , V_42 ,
V_42 -> V_108 ? L_48 : L_49 ) ;
V_42 -> V_182 = V_42 -> V_89 ;
V_42 -> V_89 = 0 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_22 ,
int V_183 , struct V_73 * V_184 )
{
int V_89 ;
F_75 ( V_183 < 0 || V_183 >= V_160 ) ;
V_22 -> V_30 [ V_183 ] -> V_83 = V_184 -> V_83 ;
if ( V_184 -> V_173 && V_184 -> V_89 ) {
V_22 -> V_30 [ V_183 ] -> V_185 = V_184 -> V_185 ;
V_22 -> V_30 [ V_183 ] -> V_186 = V_184 -> V_186 ;
}
if ( V_184 -> V_187 ) {
V_22 -> V_30 [ V_183 ] -> V_186 = V_184 -> V_186 ;
F_76 () ;
}
V_22 -> V_30 [ V_183 ] -> V_187 = V_184 -> V_187 ;
V_22 -> V_30 [ V_183 ] -> V_173 = V_184 -> V_173 ;
V_22 -> V_30 [ V_183 ] -> V_188 = V_184 -> V_188 ;
V_22 -> V_30 [ V_183 ] -> V_189 = V_184 -> V_189 ;
V_22 -> V_30 [ V_183 ] -> V_182 = V_184 -> V_89 ;
if ( ! V_184 -> V_89 )
V_22 -> V_30 [ V_183 ] -> V_89 = 0 ;
V_89 = V_22 -> V_30 [ V_183 ] -> V_89 ;
V_22 -> V_30 [ V_183 ] -> V_89 = V_22 -> V_30 [ V_183 ] -> V_182 ;
F_69 ( V_181 , V_22 , V_22 -> V_30 [ V_183 ] , L_50 ) ;
V_22 -> V_30 [ V_183 ] -> V_89 = V_89 ;
}
static void F_77 ( struct V_1 * V_22 ,
int V_183 , struct V_73 * V_184 ,
struct V_73 * V_174 [] , int * V_175 ,
struct V_73 * V_190 [] , int * V_191 )
{
F_75 ( V_183 < 0 || V_183 >= V_160 ) ;
V_190 [ * V_191 ] = V_22 -> V_30 [ V_183 ] ;
( * V_191 ) ++ ;
if ( V_184 -> V_102 == - 1 ) {
V_184 -> V_102 = V_22 -> V_30 [ V_183 ] -> V_102 ;
V_184 -> V_103 = V_22 -> V_30 [ V_183 ] -> V_103 ;
}
V_22 -> V_30 [ V_183 ] = V_184 ;
V_174 [ * V_175 ] = V_184 ;
( * V_175 ) ++ ;
F_69 ( V_181 , V_22 , V_184 , L_51 ) ;
V_184 -> V_182 = V_184 -> V_89 ;
V_184 -> V_89 = 0 ;
}
static void F_78 ( struct V_1 * V_22 , int V_183 ,
struct V_73 * V_190 [] , int * V_191 )
{
int V_68 ;
struct V_73 * V_179 ;
F_75 ( V_183 < 0 || V_183 >= V_160 ) ;
V_179 = V_22 -> V_30 [ V_183 ] ;
V_190 [ * V_191 ] = V_22 -> V_30 [ V_183 ] ;
( * V_191 ) ++ ;
for ( V_68 = V_183 ; V_68 < V_22 -> V_161 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_161 -- ;
F_69 ( V_181 , V_22 , V_179 , L_52 ) ;
}
static void F_79 ( struct V_1 * V_22 ,
struct V_73 * V_174 )
{
unsigned long V_78 ;
int V_68 , V_192 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_174 ) {
for ( V_192 = V_68 ; V_192 < V_22 -> V_161 - 1 ; V_192 ++ )
V_22 -> V_30 [ V_192 ] = V_22 -> V_30 [ V_192 + 1 ] ;
V_22 -> V_161 -- ;
break;
}
}
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_80 ( V_174 ) ;
}
static inline int F_81 ( struct V_73 * V_193 ,
struct V_73 * V_194 )
{
if ( memcmp ( V_193 -> V_72 , V_194 -> V_72 ,
sizeof( V_193 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_193 -> V_88 , V_194 -> V_88 ,
sizeof( V_193 -> V_88 ) ) != 0 )
return 0 ;
if ( memcmp ( V_193 -> V_172 , V_194 -> V_172 , sizeof( V_193 -> V_172 ) ) != 0 )
return 0 ;
if ( memcmp ( V_193 -> V_171 , V_194 -> V_171 , sizeof( V_193 -> V_171 ) ) != 0 )
return 0 ;
if ( V_193 -> V_104 != V_194 -> V_104 )
return 0 ;
if ( V_193 -> V_101 != V_194 -> V_101 )
return 0 ;
return 1 ;
}
static inline int F_82 ( struct V_73 * V_193 ,
struct V_73 * V_194 )
{
if ( V_193 -> V_83 != V_194 -> V_83 )
return 1 ;
if ( V_193 -> V_173 != V_194 -> V_173 )
return 1 ;
if ( V_193 -> V_89 != V_194 -> V_89 )
return 1 ;
if ( ! F_31 ( V_193 -> V_72 ) )
if ( V_193 -> V_189 != V_194 -> V_189 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_73 * V_195 ,
struct V_73 * V_196 [] , int V_197 ,
int * V_198 )
{
int V_68 ;
#define F_84 0
#define F_85 1
#define F_86 2
#define F_87 3
if ( V_195 == NULL )
return F_84 ;
for ( V_68 = 0 ; V_68 < V_197 ; V_68 ++ ) {
if ( V_196 [ V_68 ] == NULL )
continue;
if ( F_88 ( V_195 -> V_72 , V_196 [ V_68 ] -> V_72 ) ) {
* V_198 = V_68 ;
if ( F_81 ( V_195 , V_196 [ V_68 ] ) ) {
if ( F_82 ( V_195 , V_196 [ V_68 ] ) )
return F_87 ;
return F_86 ;
} else {
if ( V_195 -> V_199 )
return F_84 ;
return F_85 ;
}
}
}
* V_198 = - 1 ;
return F_84 ;
}
static void F_89 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_200 * V_42 ;
unsigned long V_78 ;
F_35 ( & V_22 -> V_201 , V_78 ) ;
F_90 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_36 ( & V_22 -> V_201 , V_78 ) ;
return;
}
}
F_36 ( & V_22 -> V_201 , V_78 ) ;
V_42 = F_91 ( sizeof( * V_42 ) , V_202 ) ;
if ( ! V_42 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_53 , V_203 ) ;
return;
}
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_35 ( & V_22 -> V_201 , V_78 ) ;
F_92 ( & V_42 -> V_204 , & V_22 -> V_205 ) ;
F_36 ( & V_22 -> V_201 , V_78 ) ;
}
static void F_93 ( struct V_1 * V_22 ,
struct V_73 * V_179 )
{
if ( V_179 -> V_199 == V_206 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_54 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
switch ( V_179 -> V_199 ) {
case V_207 :
break;
case V_208 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_55 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_209 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_56 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_210 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_57 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_211 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_58 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_212 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_59 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_213 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_60 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_214 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_61 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_215 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_62 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_216 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_63 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_217 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_64 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_218 :
F_94 ( & V_22 -> V_29 -> V_30 ,
L_65 ,
V_22 -> V_59 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
}
}
static void F_95 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_161 ,
struct V_73 * V_219 )
{
struct V_220 * V_221 = & V_219 -> V_185 ;
struct V_222 * V_223 = & V_221 -> V_224 [ 0 ] ;
int V_68 , V_192 ;
int V_225 = F_96 ( V_221 -> V_226 ) +
F_96 ( V_221 -> V_227 ) ;
int V_228 = F_96 ( V_221 -> V_229 ) *
F_96 ( V_221 -> V_230 ) *
V_225 ;
int V_231 = F_96 ( V_221 -> V_230 ) *
V_225 ;
int V_232 ;
if ( V_228 > V_233 )
V_228 = V_233 ;
V_219 -> V_234 = V_228 ;
V_232 = 0 ;
for ( V_68 = 0 ; V_68 < V_228 ; V_68 ++ ) {
V_219 -> V_235 [ V_68 ] = NULL ;
if ( ! V_219 -> V_173 )
continue;
for ( V_192 = 0 ; V_192 < V_161 ; V_192 ++ ) {
if ( V_30 [ V_192 ] == NULL )
continue;
if ( V_30 [ V_192 ] -> V_104 != V_106 )
continue;
if ( V_30 [ V_192 ] -> V_104 != V_107 )
continue;
if ( F_32 ( V_30 [ V_192 ] ) )
continue;
if ( V_30 [ V_192 ] -> V_186 != V_223 [ V_68 ] . V_186 )
continue;
V_219 -> V_235 [ V_68 ] = V_30 [ V_192 ] ;
if ( V_68 < V_231 )
V_232 = F_97 ( V_22 -> V_236 , V_232 +
V_219 -> V_235 [ V_68 ] -> V_189 ) ;
break;
}
if ( ! V_219 -> V_235 [ V_68 ] ) {
V_219 -> V_89 = 0 ;
V_219 -> V_182 = 0 ;
V_219 -> V_189 = 8 ;
}
}
if ( V_228 )
V_219 -> V_189 = V_232 ;
else
V_219 -> V_189 = V_22 -> V_236 ;
}
static void F_98 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_161 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_161 ; V_68 ++ ) {
if ( V_30 [ V_68 ] == NULL )
continue;
if ( V_30 [ V_68 ] -> V_104 != V_106 )
continue;
if ( V_30 [ V_68 ] -> V_104 != V_107 )
continue;
if ( ! F_32 ( V_30 [ V_68 ] ) )
continue;
if ( V_30 [ V_68 ] -> V_89 )
continue;
F_95 ( V_22 , V_30 , V_161 , V_30 [ V_68 ] ) ;
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
V_21 = F_101 ( V_22 -> V_237 , V_42 ) ;
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
F_69 ( V_238 , V_22 , V_42 ,
L_66 ) ;
}
} else
F_106 ( V_42 ) ;
}
static void F_107 ( struct V_1 * V_22 ,
struct V_73 * V_179 [] , int V_239 )
{
int V_68 , V_183 , V_240 , V_241 = 0 ;
struct V_73 * V_242 ;
unsigned long V_78 ;
struct V_73 * * V_174 , * * V_190 ;
int V_175 , V_191 ;
if ( V_22 -> V_243 ) {
V_22 -> V_244 = 1 ;
return;
}
V_174 = F_108 ( sizeof( * V_174 ) * V_160 , V_202 ) ;
V_190 = F_108 ( sizeof( * V_190 ) * V_160 , V_202 ) ;
if ( ! V_174 || ! V_190 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_67
L_68 ) ;
goto V_245;
}
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_68 = 0 ;
V_191 = 0 ;
V_175 = 0 ;
while ( V_68 < V_22 -> V_161 ) {
V_242 = V_22 -> V_30 [ V_68 ] ;
V_240 = F_83 ( V_242 , V_179 , V_239 , & V_183 ) ;
if ( V_240 == F_84 ) {
V_241 ++ ;
F_78 ( V_22 , V_68 , V_190 , & V_191 ) ;
continue;
} else if ( V_240 == F_85 ) {
V_241 ++ ;
F_77 ( V_22 , V_68 , V_179 [ V_183 ] ,
V_174 , & V_175 , V_190 , & V_191 ) ;
V_179 [ V_183 ] = NULL ;
} else if ( V_240 == F_87 ) {
F_74 ( V_22 , V_68 , V_179 [ V_183 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_239 ; V_68 ++ ) {
if ( ! V_179 [ V_68 ] )
continue;
if ( V_179 [ V_68 ] -> V_199 ) {
F_93 ( V_22 , V_179 [ V_68 ] ) ;
F_69 ( V_181 , V_22 , V_179 [ V_68 ] , L_69 ) ;
continue;
}
V_240 = F_83 ( V_179 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_161 , & V_183 ) ;
if ( V_240 == F_84 ) {
V_241 ++ ;
if ( F_72 ( V_22 , V_179 [ V_68 ] , V_174 , & V_175 ) != 0 )
break;
V_179 [ V_68 ] = NULL ;
} else if ( V_240 == F_85 ) {
V_241 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_70 ) ;
}
}
F_98 ( V_22 , V_22 -> V_30 , V_22 -> V_161 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == NULL )
continue;
V_22 -> V_30 [ V_68 ] -> V_89 = V_22 -> V_30 [ V_68 ] -> V_182 ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_239 ; V_68 ++ ) {
if ( ! V_179 [ V_68 ] )
continue;
if ( V_179 [ V_68 ] -> V_199 )
F_89 ( V_22 , V_179 [ V_68 ] -> V_72 ) ;
}
if ( ! V_241 )
goto V_245;
for ( V_68 = 0 ; V_68 < V_191 ; V_68 ++ ) {
if ( V_190 [ V_68 ] == NULL )
continue;
if ( V_190 [ V_68 ] -> V_108 )
F_102 ( V_22 , V_190 [ V_68 ] ) ;
F_80 ( V_190 [ V_68 ] ) ;
V_190 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_175 ; V_68 ++ ) {
int V_21 = 0 ;
if ( V_174 [ V_68 ] == NULL )
continue;
if ( ! ( V_174 [ V_68 ] -> V_108 ) )
continue;
V_21 = F_99 ( V_22 , V_174 [ V_68 ] ) ;
if ( ! V_21 )
continue;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_71 , V_21 ) ;
F_79 ( V_22 , V_174 [ V_68 ] ) ;
V_22 -> V_244 = 1 ;
}
V_245:
F_80 ( V_174 ) ;
F_80 ( V_190 ) ;
}
static struct V_73 * F_109 ( struct V_1 * V_22 ,
int V_101 , int V_102 , int V_103 )
{
int V_68 ;
struct V_73 * V_179 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
V_179 = V_22 -> V_30 [ V_68 ] ;
if ( V_179 -> V_101 == V_101 && V_179 -> V_102 == V_102 && V_179 -> V_103 == V_103 )
return V_179 ;
}
return NULL ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_73 * V_179 ;
unsigned long V_78 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
if ( F_111 ( V_3 ) == V_246 ) {
struct V_247 * V_248 ;
struct V_249 * V_250 ;
V_248 = V_247 ( V_3 ) ;
V_250 = F_112 ( V_248 ) ;
V_179 = F_113 ( V_22 , V_250 ) ;
if ( V_179 ) {
V_179 -> V_102 = F_114 ( V_3 ) ;
V_179 -> V_103 = V_3 -> V_103 ;
}
} else
V_179 = F_109 ( V_22 , F_111 ( V_3 ) ,
F_114 ( V_3 ) , V_3 -> V_103 ) ;
if ( V_179 && V_179 -> V_108 ) {
F_115 ( & V_179 -> V_251 , 0 ) ;
V_3 -> V_80 = V_179 ;
} else
V_3 -> V_80 = NULL ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_73 * V_179 ;
int V_189 ;
V_179 = V_3 -> V_80 ;
V_3 -> V_252 = ! V_179 || ! V_179 -> V_108 ;
if ( V_179 )
V_189 = V_179 -> V_189 != 0 ?
V_179 -> V_189 : V_3 -> V_5 -> V_253 ;
else
V_189 = V_3 -> V_5 -> V_253 ;
F_117 ( V_3 , V_189 ) ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 )
{
}
static void F_119 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_254 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
F_80 ( V_22 -> V_254 [ V_68 ] ) ;
V_22 -> V_254 [ V_68 ] = NULL ;
}
F_80 ( V_22 -> V_254 ) ;
V_22 -> V_254 = NULL ;
}
static int F_120 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_255 <= 0 )
return 0 ;
V_22 -> V_254 =
F_108 ( sizeof( * V_22 -> V_254 ) * V_22 -> V_236 ,
V_202 ) ;
if ( ! V_22 -> V_254 )
return - V_256 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
V_22 -> V_254 [ V_68 ] =
F_91 ( sizeof( * V_22 -> V_254 [ V_68 ] ) *
V_22 -> V_257 , V_202 ) ;
if ( ! V_22 -> V_254 [ V_68 ] )
goto V_258;
}
return 0 ;
V_258:
F_119 ( V_22 ) ;
return - V_256 ;
}
static void F_121 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_259 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
F_80 ( V_22 -> V_259 [ V_68 ] ) ;
V_22 -> V_259 [ V_68 ] = NULL ;
}
F_80 ( V_22 -> V_259 ) ;
V_22 -> V_259 = NULL ;
}
static int F_122 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_255 <= 0 )
return 0 ;
V_22 -> V_259 = F_108 ( sizeof( * V_22 -> V_259 ) * V_22 -> V_236 ,
V_202 ) ;
if ( ! V_22 -> V_259 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_72 ) ;
return - V_256 ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
V_22 -> V_259 [ V_68 ] = F_91 ( sizeof( * V_22 -> V_259 [ V_68 ] ) *
V_22 -> V_255 , V_202 ) ;
if ( ! V_22 -> V_259 [ V_68 ] ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_73 ) ;
goto V_258;
}
}
return 0 ;
V_258:
F_121 ( V_22 ) ;
return - V_256 ;
}
static int F_123 ( struct V_1 * V_22 ,
struct V_138 * V_130 , struct V_8 * V_9 )
{
struct V_260 * V_261 ;
T_5 V_262 ;
T_4 V_263 ;
V_261 = V_22 -> V_254 [ V_9 -> V_132 ] ;
V_263 = F_124 ( V_130 -> V_264 [ 0 ] . V_265 ) ;
V_262 = F_125 ( V_22 -> V_29 , V_261 , V_263 ,
V_266 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , V_262 ) ) {
V_130 -> V_264 -> V_267 = 0 ;
return - 1 ;
}
V_130 -> V_264 -> V_267 = F_127 ( V_262 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_22 ,
struct V_138 * V_130 )
{
struct V_260 * V_268 ;
T_5 V_262 ;
T_4 V_263 ;
V_268 = V_130 -> V_264 ;
V_262 = F_129 ( V_268 -> V_267 ) ;
V_263 = F_124 ( V_130 -> V_264 [ 0 ] . V_265 ) ;
F_130 ( V_22 -> V_29 , V_262 , V_263 , V_266 ) ;
}
static int F_131 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_269 * V_268 , * V_261 ;
T_5 V_262 ;
T_4 V_270 ;
V_268 = & V_9 -> V_271 [ V_22 -> V_272 - 1 ] ;
V_261 = V_22 -> V_259 [ V_9 -> V_132 ] ;
V_268 -> V_273 = F_132 ( V_274 ) ;
V_270 = sizeof( * V_268 ) *
( F_96 ( V_9 -> V_123 . V_275 ) - V_22 -> V_272 ) ;
V_268 -> V_276 = F_132 ( V_270 ) ;
V_262 = F_125 ( V_22 -> V_29 , V_261 , V_270 ,
V_266 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , V_262 ) ) {
V_268 -> V_277 = F_127 ( 0 ) ;
return - 1 ;
}
V_268 -> V_277 = F_127 ( V_262 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_269 * V_268 ;
if ( F_96 ( V_9 -> V_123 . V_275 ) <= V_22 -> V_272 )
return;
V_268 = & V_9 -> V_271 [ V_22 -> V_272 - 1 ] ;
F_130 ( V_22 -> V_29 , F_129 ( V_268 -> V_277 ) ,
F_124 ( V_268 -> V_276 ) , V_266 ) ;
}
static int F_134 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_278 * V_279 ,
struct V_138 * V_280 )
{
int V_281 ;
int V_282 = 0 ;
T_4 V_283 = 0 ;
switch ( V_280 -> V_284 . V_285 ) {
case V_286 :
switch ( V_280 -> V_284 . V_49 ) {
case V_287 :
break;
case V_288 :
V_279 -> V_289 |= V_290 ;
if ( V_280 -> V_284 . V_291 !=
V_292 ) {
memset ( V_279 -> V_293 , 0 ,
V_294 ) ;
break;
}
V_281 = V_280 -> V_284 . V_15 ;
if ( V_281 > V_294 )
V_281 = V_294 ;
if ( V_281 > sizeof( V_280 -> V_284 . V_295 ) )
V_281 =
sizeof( V_280 -> V_284 . V_295 ) ;
memcpy ( V_279 -> V_293 ,
V_280 -> V_284 . V_295 , V_281 ) ;
V_282 = 1 ;
break;
case V_296 :
V_282 = 1 ;
break;
case V_297 :
V_282 = 1 ;
break;
case V_298 :
V_282 = 1 ;
break;
case V_299 :
V_282 = 1 ;
break;
default:
V_282 = 1 ;
break;
}
break;
case V_300 :
switch ( V_280 -> V_284 . V_49 ) {
case V_301 :
case V_302 :
case V_303 :
V_282 = 1 ;
break;
case V_304 :
V_279 -> V_289 = ( V_305 << 16 ) ;
V_279 -> V_289 |= ( V_306 << 8 ) ;
V_283 = F_135 (
& V_280 -> V_284 . V_307 [ 0 ] ) ;
F_136 ( V_279 , V_283 ) ;
break;
case V_308 :
case V_309 :
case V_310 :
V_282 = 1 ;
break;
default:
V_282 = 1 ;
}
break;
case V_311 :
break;
case V_312 :
break;
case V_313 :
V_282 = 1 ;
break;
case V_314 :
break;
default:
V_282 = 1 ;
break;
}
return V_282 ;
}
static void F_137 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_315 = false ;
V_9 -> V_10 = V_11 ;
F_138 () ;
if ( V_9 -> V_12 ) {
V_315 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_78 ;
struct V_73 * V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_57 ( & V_30 -> V_316 ) )
V_315 = true ;
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
if ( V_315 )
F_139 ( & V_22 -> V_317 ) ;
}
static void F_140 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_137 ( V_22 , V_9 ) ;
F_141 ( V_22 , V_9 ) ;
}
static void F_142 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_278 * V_279 )
{
F_140 ( V_22 , V_9 ) ;
V_279 -> V_318 ( V_279 ) ;
}
static void F_143 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_144 ( & V_9 -> V_319 , V_320 ) ;
F_145 ( F_48 () , V_22 -> V_321 , & V_9 -> V_319 ) ;
}
static void F_146 ( struct V_278 * V_279 )
{
V_279 -> V_289 = V_322 << 16 ;
}
static void F_147 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_278 * V_279 )
{
F_146 ( V_279 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_74 ,
V_9 -> V_143 . V_144 , V_9 -> V_24 -> V_38 ) ;
F_140 ( V_22 , V_9 ) ;
}
static void F_148 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_278 * V_279 ,
struct V_73 * V_30 )
{
struct V_138 * V_280 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
if ( F_47 ( V_280 -> V_284 . V_285 == 0 &&
V_280 -> V_284 . V_49 == 0 ) )
return F_142 ( V_22 , V_9 , V_279 ) ;
if ( F_32 ( V_30 ) &&
V_280 -> V_284 . V_285 ==
V_300 ) {
if ( V_280 -> V_284 . V_49 ==
V_310 )
V_30 -> V_89 = 0 ;
return F_143 ( V_22 , V_9 ) ;
}
if ( F_134 ( V_22 , V_9 , V_279 , V_280 ) )
return F_143 ( V_22 , V_9 ) ;
return F_142 ( V_22 , V_9 , V_279 ) ;
}
static int F_149 ( struct V_1 * V_22 ,
struct V_8 * V_130 )
{
T_1 V_323 = V_130 -> V_24 -> V_38 ;
switch ( V_323 ) {
case V_324 :
case V_325 :
return 0 ;
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_75 ,
V_323 ) ;
break;
}
return - V_323 ;
}
static void F_150 ( struct V_8 * V_130 )
{
struct V_278 * V_279 ;
struct V_1 * V_22 ;
struct V_331 * V_332 ;
struct V_73 * V_30 ;
struct V_138 * V_280 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_333 ;
V_332 = V_130 -> V_24 ;
V_279 = V_130 -> V_10 ;
V_22 = V_130 -> V_22 ;
V_30 = V_279 -> V_42 -> V_80 ;
V_280 = & V_22 -> V_136 [ V_130 -> V_132 ] ;
F_151 ( V_279 ) ;
if ( ( V_130 -> V_149 == V_334 ) &&
( F_96 ( V_130 -> V_123 . V_275 ) > V_22 -> V_272 ) )
F_133 ( V_22 , V_130 ) ;
if ( ( V_130 -> V_149 == V_153 ) &&
( V_280 -> V_264 [ 0 ] . V_335 == V_336 ) )
F_128 ( V_22 , V_280 ) ;
V_279 -> V_289 = ( V_305 << 16 ) ;
V_279 -> V_289 |= ( V_306 << 8 ) ;
if ( V_130 -> V_149 == V_153 || V_130 -> V_149 == V_150 )
F_45 ( & V_130 -> V_235 -> V_251 ) ;
if ( F_44 ( V_332 -> V_36 == V_337 ) ) {
V_279 -> V_289 = V_338 << 16 ;
return F_142 ( V_22 , V_130 , V_279 ) ;
}
if ( ( F_44 ( F_5 ( V_130 ) ) ) ) {
if ( V_130 -> V_13 )
return F_140 ( V_22 , V_130 ) ;
if ( V_130 -> V_12 )
return F_147 ( V_22 , V_130 , V_279 ) ;
}
if ( V_130 -> V_149 == V_153 )
return F_148 ( V_22 , V_130 , V_279 , V_30 ) ;
F_136 ( V_279 , V_332 -> V_339 ) ;
if ( V_332 -> V_36 == 0 )
return F_142 ( V_22 , V_130 , V_279 ) ;
if ( V_130 -> V_149 == V_150 ) {
struct V_129 * V_9 = & V_22 -> V_131 [ V_130 -> V_132 ] ;
V_130 -> V_123 . V_124 = F_152 ( V_279 ) ;
V_130 -> V_123 . V_275 = F_153 ( V_130 -> V_123 . V_124 ) ;
V_130 -> V_143 . V_340 = F_96 ( V_9 -> V_341 ) &
V_342 ;
V_130 -> V_123 . V_343 = V_9 -> V_343 ;
memcpy ( V_130 -> V_123 . V_344 . V_345 , V_9 -> V_346 , 8 ) ;
memcpy ( V_130 -> V_143 . V_144 , V_9 -> V_144 , V_130 -> V_143 . V_340 ) ;
if ( F_32 ( V_30 ) ) {
if ( V_332 -> V_36 == V_347 )
V_30 -> V_89 = 0 ;
return F_143 ( V_22 , V_130 ) ;
}
}
switch ( V_332 -> V_36 ) {
case V_37 :
V_279 -> V_289 |= V_332 -> V_38 ;
if ( V_294 < sizeof( V_332 -> V_26 ) )
V_333 = V_294 ;
else
V_333 = sizeof( V_332 -> V_26 ) ;
if ( V_332 -> V_25 < V_333 )
V_333 = V_332 -> V_25 ;
memcpy ( V_279 -> V_293 , V_332 -> V_26 , V_333 ) ;
if ( V_332 -> V_38 )
F_6 ( V_332 -> V_26 , V_333 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_332 -> V_38 == V_290 ) {
if ( V_16 == V_348 ) {
V_279 -> V_289 |= V_349 << 16 ;
break;
}
break;
}
if ( V_332 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_76
L_77
L_78 ,
V_130 , V_332 -> V_38 ,
V_16 , V_17 , V_18 ,
V_279 -> V_289 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_79
L_80 , V_130 ) ,
V_279 -> V_289 = V_338 << 16 ;
}
break;
case V_350 :
break;
case V_351 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_81 , V_130 -> V_143 . V_144 ) ;
break;
case V_352 : {
V_279 -> V_289 = V_338 << 16 ;
}
break;
case V_353 :
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_82 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_355 :
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_83 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_356 :
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_84 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_357 :
return F_147 ( V_22 , V_130 , V_279 ) ;
case V_358 :
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_85 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_359 :
V_279 -> V_289 = V_349 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_86 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_360 :
V_279 -> V_289 = V_361 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_87 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_362 :
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_88 ) ;
break;
case V_363 :
if ( F_149 ( V_22 , V_130 ) )
V_279 -> V_289 = V_354 << 16 ;
break;
case V_347 :
V_279 -> V_289 = V_349 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_89 , V_130 ) ;
break;
default:
V_279 -> V_289 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_90 ,
V_130 , V_332 -> V_36 ) ;
}
return F_142 ( V_22 , V_130 , V_279 ) ;
}
static void F_154 ( struct V_364 * V_29 ,
struct V_8 * V_9 , int V_365 , int V_366 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_365 ; V_68 ++ )
F_130 ( V_29 , ( V_367 ) F_129 ( V_9 -> V_271 [ V_68 ] . V_277 ) ,
F_124 ( V_9 -> V_271 [ V_68 ] . V_276 ) ,
V_366 ) ;
}
static int F_155 ( struct V_364 * V_29 ,
struct V_8 * V_130 ,
unsigned char * V_45 ,
T_3 V_368 ,
int V_366 )
{
T_5 V_369 ;
if ( V_368 == 0 || V_366 == V_370 ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_275 = F_153 ( 0 ) ;
return 0 ;
}
V_369 = F_125 ( V_29 , V_45 , V_368 , V_366 ) ;
if ( F_126 ( & V_29 -> V_30 , V_369 ) ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_275 = F_153 ( 0 ) ;
return - 1 ;
}
V_130 -> V_271 [ 0 ] . V_277 = F_127 ( V_369 ) ;
V_130 -> V_271 [ 0 ] . V_276 = F_132 ( V_368 ) ;
V_130 -> V_271 [ 0 ] . V_273 = F_132 ( V_371 ) ;
V_130 -> V_123 . V_124 = 1 ;
V_130 -> V_123 . V_275 = F_153 ( 1 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_112 , unsigned long V_372 )
{
F_157 ( V_373 ) ;
V_9 -> V_374 = & V_373 ;
F_58 ( V_22 , V_9 , V_112 ) ;
if ( V_372 == V_375 ) {
F_158 ( & V_373 ) ;
return V_376 ;
}
if ( ! F_159 ( & V_373 ,
F_160 ( V_372 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_91 ) ;
return - V_377 ;
}
return V_376 ;
}
static int F_161 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_112 , unsigned long V_372 )
{
if ( F_44 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_337 ;
return V_376 ;
}
return F_156 ( V_22 , V_9 , V_112 , V_372 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_378 ;
T_4 V_21 , * F_13 ;
V_378 = F_162 () ;
F_13 = F_163 ( V_22 -> F_13 , V_378 ) ;
V_21 = * F_13 ;
F_164 () ;
return V_21 ;
}
static int F_165 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_366 , unsigned long V_372 )
{
int V_379 = 10 , V_380 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_161 ( V_22 , V_9 , V_126 ,
V_372 ) ;
if ( V_21 )
break;
V_380 ++ ;
if ( V_380 > 3 ) {
F_166 ( V_379 ) ;
if ( V_379 < 1000 )
V_379 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_380 <= V_381 );
F_154 ( V_22 -> V_29 , V_9 , 1 , V_366 ) ;
if ( V_380 > V_381 )
V_21 = - V_382 ;
return V_21 ;
}
static void F_167 ( struct V_1 * V_22 , char * V_383 ,
struct V_8 * V_9 )
{
const T_1 * V_140 = V_9 -> V_143 . V_144 ;
const T_1 * V_103 = V_9 -> V_123 . V_344 . V_345 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_92
L_93 ,
V_383 , V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_140 [ 0 ] , V_140 [ 1 ] , V_140 [ 2 ] , V_140 [ 3 ] ,
V_140 [ 4 ] , V_140 [ 5 ] , V_140 [ 6 ] , V_140 [ 7 ] ,
V_140 [ 8 ] , V_140 [ 9 ] , V_140 [ 10 ] , V_140 [ 11 ] ,
V_140 [ 12 ] , V_140 [ 13 ] , V_140 [ 14 ] , V_140 [ 15 ] ) ;
}
static void F_168 ( struct V_1 * V_22 ,
struct V_8 * V_130 )
{
const struct V_331 * V_332 = V_130 -> V_24 ;
struct V_42 * V_384 = & V_130 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_332 -> V_36 ) {
case V_37 :
if ( V_332 -> V_25 > sizeof( V_332 -> V_26 ) )
V_23 = sizeof( V_332 -> V_26 ) ;
else
V_23 = V_332 -> V_25 ;
F_6 ( V_332 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_167 ( V_22 , L_94 , V_130 ) ;
if ( V_332 -> V_38 == V_290 )
F_9 ( V_384 , L_95 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_384 , L_96 , V_332 -> V_38 ) ;
if ( V_332 -> V_38 == 0 )
F_9 ( V_384 , L_97
L_98
L_99
L_100 ) ;
break;
case V_350 :
break;
case V_351 :
F_167 ( V_22 , L_101 , V_130 ) ;
break;
case V_352 : {
F_167 ( V_22 , L_102 , V_130 ) ;
F_9 ( V_384 , L_103 ) ;
}
break;
case V_353 :
F_167 ( V_22 , L_104 , V_130 ) ;
break;
case V_355 :
F_167 ( V_22 , L_105 , V_130 ) ;
break;
case V_356 :
F_167 ( V_22 , L_106 , V_130 ) ;
break;
case V_357 :
F_167 ( V_22 , L_107 , V_130 ) ;
break;
case V_358 :
F_167 ( V_22 , L_108 , V_130 ) ;
break;
case V_359 :
F_167 ( V_22 , L_109 , V_130 ) ;
break;
case V_360 :
F_167 ( V_22 , L_110 , V_130 ) ;
break;
case V_362 :
F_167 ( V_22 , L_111 , V_130 ) ;
break;
case V_337 :
F_167 ( V_22 , L_112 , V_130 ) ;
break;
default:
F_167 ( V_22 , L_113 , V_130 ) ;
F_9 ( V_384 , L_114 ,
V_332 -> V_36 ) ;
}
}
static int F_169 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_385 , unsigned char * V_45 ,
unsigned char V_386 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_387 , V_22 , V_45 , V_386 ,
V_385 , V_72 , V_388 ) ) {
V_21 = - 1 ;
goto V_389;
}
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_173 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_391 , int V_112 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_391 , V_22 , NULL , 0 , 0 ,
V_72 , V_392 ) ;
V_21 = F_161 ( V_22 , V_9 , V_112 , V_375 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_115 ) ;
goto V_389;
}
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_174 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_73 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_393 = false ;
struct V_138 * V_280 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_135 * V_394 = (struct V_135 * ) V_280 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_149 ) {
case V_334 :
case V_395 :
V_393 = ! memcmp ( V_72 , & V_9 -> V_123 . V_344 . V_345 ,
sizeof( V_9 -> V_123 . V_344 . V_345 ) ) ;
break;
case V_150 :
case V_153 :
if ( V_9 -> V_235 == V_30 ) {
V_393 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_234 && ! V_393 ; V_68 ++ ) {
V_393 = V_30 -> V_235 [ V_68 ] == V_9 -> V_235 ;
}
}
break;
case V_155 :
for ( V_68 = 0 ; V_68 < V_30 -> V_234 && ! V_393 ; V_68 ++ ) {
V_393 = V_30 -> V_235 [ V_68 ] -> V_186 ==
F_124 ( V_394 -> V_396 ) ;
}
break;
case 0 :
V_393 = false ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_116 ,
V_9 -> V_149 ) ;
F_175 () ;
}
return V_393 ;
}
static int F_176 ( struct V_1 * V_22 , struct V_73 * V_30 ,
unsigned char * V_72 , T_1 V_391 , int V_112 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_177 ( & V_22 -> V_397 ) == - V_398 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_117 ) ;
return - V_398 ;
}
F_75 ( F_21 ( & V_30 -> V_316 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_399 + V_68 ;
int V_400 = F_178 ( & V_9 -> V_400 ) ;
if ( V_400 > 1 && F_174 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_78 ;
V_9 -> V_13 = V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
F_55 ( & V_30 -> V_316 ) ;
else
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_172 ( V_22 , V_9 ) ;
}
V_21 = F_173 ( V_22 , V_72 , V_391 , V_112 ) ;
if ( ! V_21 )
F_179 ( V_22 -> V_317 ,
F_21 ( & V_30 -> V_316 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_44 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_118 ) ;
V_21 = - V_81 ;
}
if ( F_44 ( V_21 ) )
F_115 ( & V_30 -> V_316 , 0 ) ;
F_180 ( & V_22 -> V_397 ) ;
return V_21 ;
}
static void F_181 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_83 )
{
int V_21 ;
unsigned char * V_45 ;
* V_83 = V_84 ;
V_45 = F_108 ( 64 , V_202 ) ;
if ( ! V_45 )
return;
V_21 = F_169 ( V_22 , V_72 , V_401 | 0xC1 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_83 = V_45 [ 8 ] ;
if ( * V_83 > V_84 )
* V_83 = V_84 ;
F_80 ( V_45 ) ;
return;
}
static void F_182 ( struct V_1 * V_22 , int V_21 ,
struct V_220 * V_402 )
{
struct V_222 * V_223 = & V_402 -> V_224 [ 0 ] ;
int V_221 , V_403 , V_404 ;
T_6 V_405 , V_229 , V_406 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_94 ( & V_22 -> V_29 -> V_30 , L_119 ,
F_124 ( V_402 -> V_407 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_120 ,
F_124 ( V_402 -> V_408 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_121 ,
F_129 ( V_402 -> V_409 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_122 ,
V_402 -> V_410 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_123 ,
V_402 -> V_411 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_96 ( V_402 -> V_412 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_125 ,
F_129 ( V_402 -> V_413 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_126 ,
F_129 ( V_402 -> V_414 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_96 ( V_402 -> V_226 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_128 ,
F_96 ( V_402 -> V_227 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_129 ,
F_96 ( V_402 -> V_229 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_130 ,
F_96 ( V_402 -> V_230 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_131 ,
F_96 ( V_402 -> V_78 ) ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_132 ,
F_96 ( V_402 -> V_78 ) &
V_415 ? L_133 : L_134 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_135 ,
F_96 ( V_402 -> V_416 ) ) ;
V_405 = F_96 ( V_402 -> V_230 ) ;
for ( V_221 = 0 ; V_221 < V_405 ; V_221 ++ ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_136 , V_221 ) ;
V_229 = F_96 ( V_402 -> V_229 ) ;
for ( V_403 = 0 ; V_403 < V_229 ; V_403 ++ ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_137 , V_403 ) ;
V_406 =
F_96 ( V_402 -> V_226 ) ;
for ( V_404 = 0 ; V_404 < V_406 ; V_404 ++ , V_223 ++ )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_138 ,
V_404 , V_223 -> V_186 ,
V_223 -> V_417 [ 0 ] , V_223 -> V_417 [ 1 ] ) ;
V_406 =
F_96 ( V_402 -> V_227 ) ;
for ( V_404 = 0 ; V_404 < V_406 ; V_404 ++ , V_223 ++ )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_139 ,
V_404 , V_223 -> V_186 ,
V_223 -> V_417 [ 0 ] , V_223 -> V_417 [ 1 ] ) ;
}
}
}
static int F_183 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_418 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_419 , V_22 , & V_418 -> V_185 ,
sizeof( V_418 -> V_185 ) , 0 ,
V_72 , V_388 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_140 ) ;
F_172 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_389;
}
F_172 ( V_22 , V_9 ) ;
if ( F_124 ( V_418 -> V_185 . V_407 ) >
sizeof( V_418 -> V_185 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_141 ) ;
V_21 = - 1 ;
}
F_182 ( V_22 , V_21 , & V_418 -> V_185 ) ;
return V_21 ;
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_184 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_420 ,
struct V_421 * V_45 , T_3 V_386 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_422 , V_22 , V_45 , V_386 ,
0 , V_157 , V_388 ) ;
if ( V_21 )
goto V_389;
V_9 -> V_143 . V_144 [ 2 ] = V_420 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_420 >> 8 ) & 0xff ;
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_185 ( struct V_1 * V_22 ,
struct V_423 * V_45 , T_3 V_386 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_424 , V_22 , V_45 , V_386 ,
0 , V_157 , V_388 ) ;
if ( V_21 )
goto V_389;
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_186 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_420 ,
struct V_425 * V_45 , T_3 V_386 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_426 , V_22 , V_45 , V_386 ,
0 , V_157 , V_388 ) ;
if ( V_21 )
goto V_389;
V_9 -> V_143 . V_144 [ 2 ] = V_420 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_420 >> 8 ) & 0xff ;
F_165 ( V_22 , V_9 , V_390 ,
V_375 ) ;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static void F_187 ( struct V_1 * V_22 ,
unsigned char * V_72 ,
struct V_427 * V_428 , int V_429 ,
struct V_73 * V_430 )
{
int V_21 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_331 * V_332 = NULL ;
struct V_431 * V_432 = NULL ;
struct V_425 * V_433 = NULL ;
struct V_434 * V_435 = & V_428 -> V_344 [ V_429 ] ;
T_6 V_420 = 0 ;
V_420 = F_188 ( & V_435 -> V_86 [ 0 ] ) ;
if ( V_420 == 0xFF00 || F_189 ( & V_435 -> V_86 [ 0 ] ) ) {
V_21 = V_376 ;
goto V_389;
}
V_432 = F_108 ( sizeof( * V_432 ) , V_202 ) ;
if ( ! V_432 )
goto V_389;
V_433 = F_108 ( sizeof( * V_433 ) , V_202 ) ;
if ( ! V_433 )
goto V_389;
V_21 = F_186 ( V_22 , V_72 , V_420 ,
V_433 , sizeof( * V_433 ) ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_142 ,
V_203 , V_430 -> V_166 , V_420 ) ;
goto V_389;
}
V_9 = F_170 ( V_22 ) ;
V_21 = F_171 ( V_9 , V_436 , V_22 , V_432 ,
sizeof( * V_432 ) , 0 , V_157 , V_388 ) ;
if ( V_21 )
goto V_389;
if ( V_433 -> V_95 [ 1 ] == 'E' )
V_9 -> V_143 . V_144 [ 5 ] = V_433 -> V_437 ;
else
V_9 -> V_143 . V_144 [ 5 ] = 0 ;
V_21 = F_165 ( V_22 , V_9 , V_390 ,
V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 && V_332 -> V_36 != V_350 ) {
V_21 = - 1 ;
goto V_389;
}
V_430 -> V_91 [ V_433 -> V_438 ] = V_432 -> V_439 ;
memcpy ( & V_430 -> V_95 [ V_433 -> V_438 ] ,
V_432 -> V_95 , sizeof( V_432 -> V_95 ) ) ;
V_21 = V_376 ;
V_389:
F_80 ( V_432 ) ;
F_80 ( V_433 ) ;
if ( V_9 )
F_172 ( V_22 , V_9 ) ;
if ( V_21 != V_376 )
F_69 ( V_181 , V_22 , V_430 ,
L_143 ) ;
}
static T_5 F_190 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_427 * V_440 ;
T_4 V_441 ;
T_5 V_442 = 0 ;
int V_68 ;
V_440 = F_108 ( sizeof( * V_440 ) , V_202 ) ;
if ( ! V_440 )
return 0 ;
if ( F_191 ( V_22 , V_440 , sizeof( * V_440 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
F_80 ( V_440 ) ;
return 0 ;
}
V_441 = F_192 ( V_440 -> V_443 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_441 ; V_68 ++ )
if ( ! memcmp ( & V_440 -> V_344 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_442 = F_193 ( & V_440 -> V_344 [ V_68 ] . V_444 [ 0 ] ) ;
break;
}
F_80 ( V_440 ) ;
return V_442 ;
}
static void F_194 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_442 = 0 ;
if ( F_62 ( V_72 ) ) {
struct V_421 * V_445 ;
V_445 = F_108 ( sizeof( * V_445 ) , V_202 ) ;
if ( V_445 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_145 , V_203 ) ;
return;
}
V_21 = F_184 ( V_22 ,
V_72 , 0 , V_445 , sizeof( * V_445 ) ) ;
if ( V_21 == 0 ) {
V_442 = F_193 ( V_445 -> V_446 ) ;
V_22 -> V_447 = V_442 ;
}
F_80 ( V_445 ) ;
} else
V_442 = F_190 ( V_22 , V_72 ) ;
V_30 -> V_447 = V_442 ;
}
static int F_195 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_385 )
{
int V_21 ;
int V_68 ;
int V_448 ;
unsigned char * V_45 , V_386 ;
V_45 = F_108 ( 256 , V_202 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_169 ( V_22 , V_72 ,
V_401 | V_449 ,
V_45 , V_450 ) ;
if ( V_21 != 0 )
goto V_451;
V_448 = V_45 [ 3 ] ;
if ( ( V_448 + V_450 ) <= 255 )
V_386 = V_448 + V_450 ;
else
V_386 = 255 ;
V_21 = F_169 ( V_22 , V_72 ,
V_401 | V_449 ,
V_45 , V_386 ) ;
if ( V_21 != 0 )
goto V_451;
V_448 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_448 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_385 )
goto V_452;
V_451:
F_80 ( V_45 ) ;
return 0 ;
V_452:
F_80 ( V_45 ) ;
return 1 ;
}
static void F_196 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_418 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_453 ;
V_418 -> V_173 = 0 ;
V_418 -> V_89 = 0 ;
V_418 -> V_182 = 0 ;
V_45 = F_108 ( 64 , V_202 ) ;
if ( ! V_45 )
return;
if ( ! F_195 ( V_22 , V_72 , V_454 ) )
goto V_389;
V_21 = F_169 ( V_22 , V_72 ,
V_401 | V_454 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_389;
#define F_197 4
#define F_198 0x01
#define F_199 0x02
V_453 = V_45 [ F_197 ] ;
V_418 -> V_173 =
! ! ( V_453 & F_198 ) ;
if ( V_418 -> V_173 ) {
V_418 -> V_89 =
! ! ( V_453 & F_199 ) ;
if ( F_183 ( V_22 , V_72 , V_418 ) )
V_418 -> V_89 = 0 ;
}
V_418 -> V_182 = V_418 -> V_89 ;
V_389:
F_80 ( V_45 ) ;
return;
}
static int F_200 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_88 , int V_198 , int V_368 )
{
int V_21 ;
unsigned char * V_45 ;
if ( V_368 > 16 )
V_368 = 16 ;
V_45 = F_108 ( 64 , V_202 ) ;
if ( ! V_45 )
return - V_256 ;
V_21 = F_169 ( V_22 , V_72 , V_401 | 0x83 , V_45 , 64 ) ;
if ( V_21 == 0 )
memcpy ( V_88 , & V_45 [ V_198 ] , V_368 ) ;
F_80 ( V_45 ) ;
return V_21 != 0 ;
}
static int F_201 ( struct V_1 * V_22 , int V_455 ,
void * V_45 , int V_386 ,
int V_456 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_331 * V_332 ;
V_9 = F_170 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_171 ( V_9 , V_455 ? V_457 : V_458 , V_22 ,
V_45 , V_386 , 0 , V_72 , V_388 ) ) {
V_21 = - 1 ;
goto V_389;
}
if ( V_456 )
V_9 -> V_143 . V_144 [ 1 ] = V_456 ;
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( V_21 )
goto V_389;
V_332 = V_9 -> V_24 ;
if ( V_332 -> V_36 != 0 &&
V_332 -> V_36 != V_350 ) {
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_459 * V_460 = V_45 ;
if ( V_460 -> V_461 != V_456 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_146 ,
V_456 ,
V_460 -> V_461 ) ;
V_21 = - 1 ;
}
}
V_389:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_191 ( struct V_1 * V_22 ,
struct V_427 * V_45 , int V_386 )
{
return F_201 ( V_22 , 0 , V_45 , V_386 ,
V_462 ) ;
}
static inline int F_202 ( struct V_1 * V_22 ,
struct V_459 * V_45 , int V_386 )
{
return F_201 ( V_22 , 1 , V_45 , V_386 , 0 ) ;
}
static inline void F_203 ( struct V_73 * V_42 ,
int V_101 , int V_102 , int V_103 )
{
V_42 -> V_101 = V_101 ;
V_42 -> V_102 = V_102 ;
V_42 -> V_103 = V_103 ;
}
static int F_204 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_463 ;
unsigned char * V_45 ;
V_45 = F_108 ( 64 , V_202 ) ;
if ( ! V_45 )
return V_206 ;
if ( ! F_195 ( V_22 , V_72 , V_464 ) )
goto V_465;
V_21 = F_169 ( V_22 , V_72 , V_401 | V_464 ,
V_45 , V_450 ) ;
if ( V_21 != 0 )
goto V_465;
V_463 = V_45 [ 3 ] ;
V_21 = F_169 ( V_22 , V_72 , V_401 | V_464 ,
V_45 , V_463 + V_450 ) ;
if ( V_21 != 0 )
goto V_465;
V_49 = V_45 [ 4 ] ;
F_80 ( V_45 ) ;
return V_49 ;
V_465:
F_80 ( V_45 ) ;
return V_206 ;
}
static int F_205 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_466 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_467 = 0 ;
T_6 V_468 ;
T_1 V_469 ;
#define F_206 0x04
#define F_207 0x04
#define F_208 0x02
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_470 , V_22 , NULL , 0 , 0 , V_72 , V_388 ) ;
V_21 = F_161 ( V_22 , V_9 , V_126 , V_375 ) ;
if ( V_21 ) {
F_172 ( V_22 , V_9 ) ;
return 0 ;
}
V_466 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_466 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_468 = V_9 -> V_24 -> V_36 ;
V_469 = V_9 -> V_24 -> V_38 ;
F_172 ( V_22 , V_9 ) ;
if ( V_468 != V_37 ||
V_469 != V_290 ||
V_16 != V_471 ||
V_17 != F_206 ) {
return 0 ;
}
V_467 = F_204 ( V_22 , V_72 ) ;
switch ( V_467 ) {
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
return V_467 ;
case V_206 :
if ( ( V_18 == F_207 ) ||
( V_18 == F_208 ) )
return V_467 ;
break;
default:
break;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_331 * V_332 ;
int V_21 = 0 ;
T_5 V_343 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_472 , V_22 , & V_343 , 0 , 0 , V_72 , V_392 ) ;
( void ) F_161 ( V_22 , V_9 , V_126 , V_375 ) ;
V_332 = V_9 -> V_24 ;
switch ( V_332 -> V_36 ) {
case V_352 :
V_21 = 0 ;
break;
case V_362 :
case V_358 :
V_21 = 1 ;
break;
case V_363 :
V_21 = F_149 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_210 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_73 * V_418 ,
unsigned char * V_473 )
{
#define F_211 43
#define F_212 "$DR-10"
#define F_213 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_214 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_474 ;
unsigned char * V_475 ;
int V_21 = 0 ;
V_474 = F_108 ( F_214 , V_202 ) ;
if ( ! V_474 ) {
V_21 = - V_256 ;
goto V_476;
}
if ( F_169 ( V_22 , V_72 , 0 , V_474 ,
( unsigned char ) F_214 ) != 0 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_147 ) ;
V_21 = - V_382 ;
goto V_476;
}
F_215 ( & V_474 [ 8 ] , 8 ) ;
F_215 ( & V_474 [ 16 ] , 16 ) ;
V_418 -> V_104 = ( V_474 [ 0 ] & 0x1f ) ;
memcpy ( V_418 -> V_72 , V_72 , 8 ) ;
memcpy ( V_418 -> V_171 , & V_474 [ 8 ] ,
sizeof( V_418 -> V_171 ) ) ;
memcpy ( V_418 -> V_172 , & V_474 [ 16 ] ,
sizeof( V_418 -> V_172 ) ) ;
memset ( V_418 -> V_88 , 0 ,
sizeof( V_418 -> V_88 ) ) ;
F_200 ( V_22 , V_72 , V_418 -> V_88 , 8 ,
sizeof( V_418 -> V_88 ) ) ;
if ( ( V_418 -> V_104 == V_106 ||
V_418 -> V_104 == V_107 ) &&
F_31 ( V_72 ) ) {
int V_199 ;
F_181 ( V_22 , V_72 , & V_418 -> V_83 ) ;
if ( V_22 -> V_477 & V_478 )
F_196 ( V_22 , V_72 , V_418 ) ;
V_199 = F_205 ( V_22 , V_72 ) ;
if ( V_199 < 0 || V_199 > 0xff )
V_199 = V_206 ;
V_418 -> V_199 = V_199 & 0xff ;
} else {
V_418 -> V_83 = V_84 ;
V_418 -> V_173 = 0 ;
V_418 -> V_89 = 0 ;
V_418 -> V_182 = 0 ;
V_418 -> V_187 = 0 ;
V_418 -> V_199 = 0 ;
V_418 -> V_189 = V_22 -> V_236 ;
}
if ( V_473 ) {
V_475 = & V_474 [ F_211 ] ;
* V_473 = ( V_418 -> V_104 == V_168 &&
strncmp ( V_475 , F_212 ,
F_213 ) == 0 ) ;
}
F_80 ( V_474 ) ;
return 0 ;
V_476:
F_80 ( V_474 ) ;
return V_21 ;
}
static void F_216 ( struct V_1 * V_22 ,
struct V_73 * V_30 , T_1 * V_72 )
{
unsigned long V_78 ;
int V_21 , V_183 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_21 = F_83 ( V_30 , V_22 -> V_30 , V_22 -> V_161 , & V_183 ) ;
if ( ( V_21 == F_86 || V_21 == F_87 ) &&
V_183 >= 0 && V_183 < V_22 -> V_161 ) {
V_30 -> V_479 = V_22 -> V_30 [ V_183 ] -> V_479 ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_96 , V_78 ) ;
V_30 -> V_479 =
F_209 ( V_22 , V_72 ) ;
if ( V_30 -> V_479 < 0 )
V_30 -> V_479 = 0 ;
}
}
static void F_217 ( struct V_1 * V_22 ,
T_1 * V_480 , struct V_73 * V_42 )
{
T_4 V_86 = F_135 ( V_480 ) ;
if ( ! F_31 ( V_480 ) ) {
if ( F_62 ( V_480 ) )
F_203 ( V_42 ,
V_481 , 0 , V_86 & 0x3fff ) ;
else
F_203 ( V_42 ,
V_246 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_166 ) {
F_203 ( V_42 ,
V_482 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_203 ( V_42 , V_483 ,
0 , V_86 & 0x3fff ) ;
}
static int F_218 ( struct V_1 * V_22 ,
struct V_8 * V_484 , unsigned char * V_72 )
{
struct V_138 * V_280 =
& V_22 -> V_136 [ V_484 -> V_132 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_186 == F_124 ( V_280 -> V_485 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 0 ;
}
static int F_219 ( struct V_1 * V_22 , int V_486 ,
int V_68 , int V_441 , int V_487 )
{
int V_488 = V_441 + ( V_486 == 0 ) ;
if ( V_68 == V_486 )
return 0 ;
if ( V_68 < V_488 )
return 0 ;
if ( ( V_68 - V_441 - ( V_486 == 0 ) ) < V_487 )
return 0 ;
return 1 ;
}
static int F_220 ( struct V_1 * V_22 ,
struct V_427 * V_440 , T_4 * V_441 ,
struct V_459 * V_489 , T_4 * V_490 )
{
if ( F_191 ( V_22 , V_440 , sizeof( * V_440 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
return - 1 ;
}
* V_441 = F_221 ( * ( ( V_491 * ) V_440 -> V_443 ) ) / 24 ;
if ( * V_441 > V_492 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_148 ,
V_492 , * V_441 - V_492 ) ;
* V_441 = V_492 ;
}
if ( F_202 ( V_22 , V_489 , sizeof( * V_489 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_149 ) ;
return - 1 ;
}
* V_490 = F_221 ( * ( ( V_491 * ) V_489 -> V_443 ) ) / 8 ;
if ( * V_490 > V_493 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_150
L_151 , V_493 ,
* V_490 - V_493 ) ;
* V_490 = V_493 ;
}
if ( * V_490 + * V_441 > V_492 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_152
L_151 , V_492 ,
* V_441 + * V_490 - V_492 ) ;
* V_490 = V_492 - * V_441 ;
}
return 0 ;
}
static T_1 * F_222 ( struct V_1 * V_22 , int V_486 ,
int V_68 , int V_441 , int V_490 ,
struct V_427 * V_494 ,
struct V_459 * V_495 )
{
int V_488 = V_441 + ( V_486 == 0 ) ;
int V_496 = V_441 + V_490 + ( V_486 == 0 ) ;
if ( V_68 == V_486 )
return V_157 ;
if ( V_68 < V_488 )
return & V_494 -> V_344 [ V_68 -
( V_486 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_496 )
return & V_495 -> V_344 [ V_68 - V_441 -
( V_486 == 0 ) ] [ 0 ] ;
F_175 () ;
return NULL ;
}
static void F_223 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_427 * V_428 , int V_429 ,
struct V_425 * V_433 )
{
int V_21 ;
struct V_434 * V_435 = & V_428 -> V_344 [ V_429 ] ;
V_30 -> V_186 = V_435 -> V_186 ;
if ( ( V_435 -> V_497 & 0x08 ) && V_30 -> V_186 )
V_30 -> V_187 = 1 ;
memset ( V_433 , 0 , sizeof( * V_433 ) ) ;
V_21 = F_186 ( V_22 , & V_435 -> V_86 [ 0 ] ,
F_188 ( & V_435 -> V_86 [ 0 ] ) , V_433 ,
sizeof( * V_433 ) ) ;
if ( ! V_21 )
#define F_224 2
#define F_225 7
V_30 -> V_189 =
F_96 ( V_433 -> V_498 ) -
F_224 ;
else
V_30 -> V_189 = F_225 ;
}
static void F_226 ( struct V_73 * V_418 ,
struct V_427 * V_428 , int V_429 ,
struct V_425 * V_433 )
{
struct V_434 * V_435 = & V_428 -> V_344 [ V_429 ] ;
if ( ( V_435 -> V_497 & 0x08 ) && V_418 -> V_186 )
V_418 -> V_187 = 1 ;
memcpy ( & V_418 -> V_98 ,
& V_433 -> V_438 ,
sizeof( V_418 -> V_98 ) ) ;
memcpy ( & V_418 -> V_99 ,
& V_433 -> V_499 ,
sizeof( V_418 -> V_99 ) ) ;
memcpy ( & V_418 -> V_91 ,
& V_433 -> V_500 ,
sizeof( V_418 -> V_91 ) ) ;
memcpy ( & V_418 -> V_95 ,
& V_433 -> V_501 ,
sizeof( V_418 -> V_95 ) ) ;
memcpy ( & V_418 -> V_92 ,
& V_433 -> V_502 ,
sizeof( V_418 -> V_92 ) ) ;
}
static int F_227 ( struct V_1 * V_22 ,
struct V_423 * V_503 ,
T_4 * V_504 )
{
int V_21 ;
if ( ! V_503 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_153 ,
V_203 ) ;
return - V_256 ;
}
memset ( V_503 , 0 , sizeof( * V_503 ) ) ;
V_21 = F_185 ( V_22 , V_503 , sizeof( * V_503 ) ) ;
if ( ! V_21 )
if ( V_503 -> V_505 < 256 )
* V_504 = V_503 -> V_505 ;
else
* V_504 = F_96 (
V_503 -> V_506 ) ;
else
* V_504 = - 1 ;
return V_21 ;
}
static void F_228 ( struct V_1 * V_22 )
{
struct V_427 * V_494 = NULL ;
struct V_459 * V_495 = NULL ;
struct V_425 * V_433 = NULL ;
struct V_423 * V_503 = NULL ;
T_4 V_441 = 0 ;
T_4 V_490 = 0 ;
T_4 V_487 = 0 ;
T_4 V_507 = 0 ;
struct V_73 * * V_508 , * V_418 , * V_509 ;
int V_510 = 0 ;
int V_68 , V_511 , V_512 ;
int V_486 ;
bool V_74 ;
F_65 ( V_513 , V_514 ) ;
V_508 = F_108 ( sizeof( * V_508 ) * V_160 , V_202 ) ;
V_494 = F_108 ( sizeof( * V_494 ) , V_202 ) ;
V_495 = F_108 ( sizeof( * V_495 ) , V_202 ) ;
V_509 = F_108 ( sizeof( * V_509 ) , V_202 ) ;
V_433 = F_108 ( sizeof( * V_433 ) , V_202 ) ;
V_503 = F_108 ( sizeof( * V_503 ) , V_202 ) ;
if ( ! V_508 || ! V_494 || ! V_495 ||
! V_509 || ! V_433 || ! V_503 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_154 ) ;
goto V_389;
}
memset ( V_513 , 0 , sizeof( V_513 ) ) ;
V_22 -> V_244 = 0 ;
if ( F_220 ( V_22 , V_494 , & V_441 ,
V_495 , & V_490 ) ) {
V_22 -> V_244 = 1 ;
goto V_389;
}
if ( F_227 ( V_22 , V_503 , & V_487 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_155 ,
V_203 ) ;
}
V_512 = V_441 + V_490 + V_514 + 1 ;
for ( V_68 = 0 ; V_68 < V_512 ; V_68 ++ ) {
if ( V_68 >= V_160 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_156
L_157 , V_160 ,
V_512 - V_160 ) ;
break;
}
V_508 [ V_68 ] = F_108 ( sizeof( * V_508 [ V_68 ] ) , V_202 ) ;
if ( ! V_508 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_158 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_244 = 1 ;
goto V_389;
}
V_507 ++ ;
}
if ( F_63 ( V_22 ) )
V_486 = 0 ;
else
V_486 = V_441 + V_490 ;
V_511 = 0 ;
for ( V_68 = 0 ; V_68 < V_441 + V_490 + 1 ; V_68 ++ ) {
T_1 * V_480 , V_515 = 0 ;
int V_21 = 0 ;
int V_516 = V_68 - ( V_486 == 0 ) ;
V_74 = V_68 < V_441 + ( V_486 == 0 ) ;
V_480 = F_222 ( V_22 , V_486 ,
V_68 , V_441 , V_490 , V_494 , V_495 ) ;
if ( F_189 ( V_480 ) && V_74 &&
( V_494 -> V_344 [ V_516 ] . V_517 != 0x06 ) &&
( V_494 -> V_344 [ V_516 ] . V_497 & 0x01 ) )
continue;
V_21 = F_210 ( V_22 , V_480 , V_509 ,
& V_515 ) ;
if ( V_21 == - V_256 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_159 ) ;
V_22 -> V_244 = 1 ;
goto V_389;
}
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_160 ) ;
continue;
}
V_509 -> V_166 =
F_219 ( V_22 , V_486 , V_68 ,
V_441 , V_487 ) ;
F_217 ( V_22 , V_480 , V_509 ) ;
F_216 ( V_22 , V_509 , V_480 ) ;
V_418 = V_508 [ V_510 ] ;
if ( ! V_22 -> V_518 ) {
if ( V_509 -> V_166 ) {
V_22 -> V_518 = 1 ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_161 ) ;
}
}
* V_418 = * V_509 ;
V_418 -> V_74 = V_74 ;
if ( F_189 ( V_480 ) && V_418 -> V_74 )
V_418 -> V_108 = 0 ;
else
V_418 -> V_108 = 1 ;
if ( V_418 -> V_74 && V_418 -> V_108 )
F_194 ( V_22 , V_480 , V_418 ) ;
switch ( V_418 -> V_104 ) {
case V_168 :
if ( V_515 )
V_510 ++ ;
break;
case V_106 :
case V_107 :
if ( V_418 -> V_74 ) {
V_418 -> V_89 = 0 ;
F_223 ( V_22 , V_418 ,
V_494 , V_516 , V_433 ) ;
F_226 ( V_418 ,
V_494 , V_516 , V_433 ) ;
}
V_510 ++ ;
break;
case V_169 :
case V_170 :
V_510 ++ ;
break;
case V_165 :
if ( ! V_418 -> V_166 )
F_187 ( V_22 , V_480 ,
V_494 , V_516 ,
V_418 ) ;
V_510 ++ ;
break;
case V_105 :
if ( ! F_62 ( V_480 ) )
break;
V_510 ++ ;
break;
default:
break;
}
if ( V_510 >= V_160 )
break;
}
if ( V_22 -> V_237 == NULL ) {
int V_21 = 0 ;
V_21 = F_229 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_162 , V_21 ) ;
goto V_389;
}
}
F_107 ( V_22 , V_508 , V_510 ) ;
V_389:
F_80 ( V_509 ) ;
for ( V_68 = 0 ; V_68 < V_507 ; V_68 ++ )
F_80 ( V_508 [ V_68 ] ) ;
F_80 ( V_508 ) ;
F_80 ( V_494 ) ;
F_80 ( V_495 ) ;
F_80 ( V_503 ) ;
F_80 ( V_433 ) ;
}
static void F_230 ( struct V_269 * V_519 ,
struct V_520 * V_264 )
{
T_5 V_369 = ( T_5 ) F_231 ( V_264 ) ;
unsigned int V_50 = F_232 ( V_264 ) ;
V_519 -> V_277 = F_127 ( V_369 ) ;
V_519 -> V_276 = F_132 ( V_50 ) ;
V_519 -> V_273 = 0 ;
}
static int F_233 ( struct V_1 * V_22 ,
struct V_8 * V_130 ,
struct V_278 * V_279 )
{
struct V_520 * V_264 ;
int V_521 , V_68 , V_522 , V_523 , V_524 ;
struct V_269 * V_525 ;
F_75 ( F_152 ( V_279 ) > V_22 -> V_257 ) ;
V_521 = F_234 ( V_279 ) ;
if ( V_521 < 0 )
return V_521 ;
if ( ! V_521 )
goto V_526;
V_525 = V_130 -> V_271 ;
V_523 = V_521 > V_22 -> V_272 ;
V_522 = V_523 ? V_22 -> V_272 - 1 : V_521 ;
V_524 = F_152 ( V_279 ) - 1 ;
F_235 (cmd, sg, sg_limit, i) {
F_230 ( V_525 , V_264 ) ;
V_525 ++ ;
}
if ( V_523 ) {
V_525 = V_22 -> V_259 [ V_130 -> V_132 ] ;
V_522 = V_521 - V_522 ;
F_236 (sg, sg, sg_limit, i) {
F_230 ( V_525 , V_264 ) ;
V_525 ++ ;
}
}
( V_525 - 1 ) -> V_273 = F_132 ( V_371 ) ;
if ( V_521 + V_523 > V_22 -> V_527 )
V_22 -> V_527 = V_521 + V_523 ;
if ( V_523 ) {
V_130 -> V_123 . V_124 = V_22 -> V_272 ;
V_130 -> V_123 . V_275 = F_153 ( V_521 + 1 ) ;
if ( F_131 ( V_22 , V_130 ) ) {
F_151 ( V_279 ) ;
return - 1 ;
}
return 0 ;
}
V_526:
V_130 -> V_123 . V_124 = ( T_1 ) V_521 ;
V_130 -> V_123 . V_275 = F_153 ( V_521 ) ;
return 0 ;
}
static int F_237 ( T_1 * V_140 , int * V_528 )
{
int V_529 = 0 ;
T_4 V_530 ;
T_4 V_531 ;
switch ( V_140 [ 0 ] ) {
case V_532 :
case V_533 :
V_529 = 1 ;
case V_534 :
case V_535 :
if ( * V_528 == 6 ) {
V_530 = F_238 ( & V_140 [ 2 ] ) ;
V_531 = V_140 [ 4 ] ;
if ( V_531 == 0 )
V_531 = 256 ;
} else {
F_75 ( * V_528 != 12 ) ;
V_530 = F_192 ( & V_140 [ 2 ] ) ;
V_531 = F_192 ( & V_140 [ 6 ] ) ;
}
if ( V_531 > 0xffff )
return V_536 ;
V_140 [ 0 ] = V_529 ? V_537 : V_538 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_530 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_530 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_530 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_530 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_531 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_531 ) ;
V_140 [ 9 ] = 0 ;
* V_528 = 10 ;
break;
}
return 0 ;
}
static int F_239 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_528 ,
T_1 * V_72 , struct V_73 * V_235 )
{
struct V_278 * V_279 = V_9 -> V_10 ;
struct V_129 * V_130 = & V_22 -> V_131 [ V_9 -> V_132 ] ;
unsigned int V_50 ;
unsigned int V_539 = 0 ;
struct V_520 * V_264 ;
T_5 V_369 ;
int V_521 , V_68 ;
struct V_269 * V_525 ;
T_4 V_540 = V_541 ;
if ( F_152 ( V_279 ) > V_22 -> V_542 ) {
F_45 ( & V_235 -> V_251 ) ;
return V_536 ;
}
F_75 ( V_279 -> V_543 > V_544 ) ;
if ( F_237 ( V_140 , & V_528 ) ) {
F_45 ( & V_235 -> V_251 ) ;
return V_536 ;
}
V_9 -> V_149 = V_150 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_545 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
V_521 = F_234 ( V_279 ) ;
if ( V_521 < 0 ) {
F_45 ( & V_235 -> V_251 ) ;
return V_521 ;
}
if ( V_521 ) {
V_525 = V_130 -> V_271 ;
F_235 (cmd, sg, use_sg, i) {
V_369 = ( T_5 ) F_231 ( V_264 ) ;
V_50 = F_232 ( V_264 ) ;
V_539 += V_50 ;
V_525 -> V_277 = F_127 ( V_369 ) ;
V_525 -> V_276 = F_132 ( V_50 ) ;
V_525 -> V_273 = F_132 ( 0 ) ;
V_525 ++ ;
}
( -- V_525 ) -> V_273 = F_132 ( V_371 ) ;
switch ( V_279 -> V_546 ) {
case V_547 :
V_540 |= V_548 ;
break;
case V_549 :
V_540 |= V_550 ;
break;
case V_551 :
V_540 |= V_552 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_279 -> V_546 ) ;
F_175 () ;
break;
}
} else {
V_540 |= V_552 ;
}
V_9 -> V_123 . V_124 = V_521 ;
V_130 -> V_553 = F_153 ( V_186 & 0xFFFF ) ;
V_130 -> V_554 = F_132 ( V_539 ) ;
V_130 -> V_341 = F_153 ( V_555 |
( V_528 & V_342 ) ) ;
V_130 -> V_540 = F_132 ( V_540 ) ;
memcpy ( V_130 -> V_144 , V_140 , V_528 ) ;
memcpy ( V_130 -> V_346 , V_72 , 8 ) ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_278 * V_279 = V_9 -> V_10 ;
struct V_73 * V_30 = V_279 -> V_42 -> V_80 ;
V_9 -> V_235 = V_30 ;
return F_241 ( V_22 , V_9 , V_30 -> V_186 ,
V_279 -> V_556 , V_279 -> V_543 , V_30 -> V_72 , V_30 ) ;
}
static void F_242 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_138 * V_130 )
{
struct V_278 * V_279 = V_9 -> V_10 ;
struct V_73 * V_30 = V_279 -> V_42 -> V_80 ;
struct V_220 * V_221 = & V_30 -> V_185 ;
T_5 V_557 ;
if ( ! ( F_96 ( V_221 -> V_78 ) & V_415 ) )
return;
V_130 -> V_416 = V_221 -> V_416 ;
V_130 -> V_558 |= V_559 ;
switch ( V_279 -> V_556 [ 0 ] ) {
case V_532 :
case V_534 :
V_557 = F_238 ( & V_279 -> V_556 [ 2 ] ) ;
break;
case V_537 :
case V_538 :
case V_533 :
case V_535 :
V_557 = F_192 ( & V_279 -> V_556 [ 2 ] ) ;
break;
case V_560 :
case V_561 :
V_557 = F_193 ( & V_279 -> V_556 [ 2 ] ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_164 ,
V_203 , V_279 -> V_556 [ 0 ] ) ;
F_175 () ;
break;
}
if ( F_124 ( V_221 -> V_408 ) != 512 )
V_557 = V_557 *
F_124 ( V_221 -> V_408 ) / 512 ;
V_130 -> V_562 = F_132 ( V_557 ) ;
V_130 -> V_563 = F_132 ( V_557 >> 32 ) ;
}
static int F_243 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_528 ,
T_1 * V_72 , struct V_73 * V_235 )
{
struct V_278 * V_279 = V_9 -> V_10 ;
struct V_138 * V_130 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_260 * V_525 ;
int V_521 , V_68 ;
struct V_520 * V_264 ;
T_5 V_369 ;
T_4 V_50 ;
T_4 V_539 = 0 ;
F_75 ( F_152 ( V_279 ) > V_22 -> V_257 ) ;
if ( F_237 ( V_140 , & V_528 ) ) {
F_45 ( & V_235 -> V_251 ) ;
return V_536 ;
}
V_9 -> V_149 = V_153 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_564 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_565 = V_566 ;
V_521 = F_234 ( V_279 ) ;
if ( V_521 < 0 ) {
F_45 ( & V_235 -> V_251 ) ;
return V_521 ;
}
if ( V_521 ) {
V_525 = V_130 -> V_264 ;
if ( V_521 > V_22 -> V_542 ) {
V_369 = F_129 (
V_22 -> V_254 [ V_9 -> V_132 ] -> V_267 ) ;
V_525 -> V_267 = F_127 ( V_369 ) ;
V_525 -> V_265 = 0 ;
V_525 -> V_567 [ 0 ] = 0 ;
V_525 -> V_567 [ 1 ] = 0 ;
V_525 -> V_567 [ 2 ] = 0 ;
V_525 -> V_335 = 0x80 ;
V_525 = V_22 -> V_254 [ V_9 -> V_132 ] ;
}
F_235 (cmd, sg, use_sg, i) {
V_369 = ( T_5 ) F_231 ( V_264 ) ;
V_50 = F_232 ( V_264 ) ;
V_539 += V_50 ;
V_525 -> V_267 = F_127 ( V_369 ) ;
V_525 -> V_265 = F_132 ( V_50 ) ;
V_525 -> V_567 [ 0 ] = 0 ;
V_525 -> V_567 [ 1 ] = 0 ;
V_525 -> V_567 [ 2 ] = 0 ;
V_525 -> V_335 = 0 ;
V_525 ++ ;
}
switch ( V_279 -> V_546 ) {
case V_547 :
V_130 -> V_558 &= ~ V_568 ;
V_130 -> V_558 |= V_569 ;
break;
case V_549 :
V_130 -> V_558 &= ~ V_568 ;
V_130 -> V_558 |= V_570 ;
break;
case V_551 :
V_130 -> V_558 &= ~ V_568 ;
V_130 -> V_558 |= V_571 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_279 -> V_546 ) ;
F_175 () ;
break;
}
} else {
V_130 -> V_558 &= ~ V_568 ;
V_130 -> V_558 |= V_571 ;
}
F_242 ( V_22 , V_9 , V_130 ) ;
V_130 -> V_485 = F_132 ( V_186 ) ;
V_130 -> V_572 = F_132 ( V_9 -> V_132 << V_573 ) ;
memcpy ( V_130 -> V_140 , V_140 , sizeof( V_130 -> V_140 ) ) ;
V_130 -> V_281 = F_132 ( V_539 ) ;
V_130 -> V_574 = F_127 ( V_9 -> V_121 +
F_244 ( struct V_138 , V_284 ) ) ;
V_130 -> V_575 = F_132 ( sizeof( V_130 -> V_284 ) ) ;
if ( V_521 > V_22 -> V_542 ) {
V_130 -> V_139 = 1 ;
V_130 -> V_264 [ 0 ] . V_265 = F_132 ( V_521 * sizeof( V_130 -> V_264 [ 0 ] ) ) ;
if ( F_123 ( V_22 , V_130 , V_9 ) ) {
F_45 ( & V_235 -> V_251 ) ;
F_151 ( V_279 ) ;
return - 1 ;
}
} else
V_130 -> V_139 = ( T_1 ) V_521 ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_241 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_528 ,
T_1 * V_72 , struct V_73 * V_235 )
{
if ( F_178 ( & V_235 -> V_251 ) >
V_235 -> V_189 ) {
F_45 ( & V_235 -> V_251 ) ;
return V_536 ;
}
if ( V_22 -> V_63 & V_113 )
return F_239 ( V_22 , V_9 , V_186 ,
V_140 , V_528 , V_72 ,
V_235 ) ;
else
return F_243 ( V_22 , V_9 , V_186 ,
V_140 , V_528 , V_72 ,
V_235 ) ;
}
static void F_245 ( struct V_220 * V_221 ,
int V_188 , T_4 * V_576 , T_4 * V_577 )
{
if ( V_188 == 0 ) {
* V_576 %= F_96 ( V_221 -> V_226 ) ;
return;
}
do {
* V_577 = * V_576 /
F_96 ( V_221 -> V_226 ) ;
if ( V_188 == * V_577 )
continue;
if ( * V_577 < F_96 ( V_221 -> V_230 ) - 1 ) {
* V_576 += F_96 ( V_221 -> V_226 ) ;
( * V_577 ) ++ ;
} else {
* V_576 %= F_96 ( V_221 -> V_226 ) ;
* V_577 = 0 ;
}
} while ( V_188 != * V_577 );
}
static int F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_278 * V_279 = V_9 -> V_10 ;
struct V_73 * V_30 = V_279 -> V_42 -> V_80 ;
struct V_220 * V_221 = & V_30 -> V_185 ;
struct V_222 * V_223 = & V_221 -> V_224 [ 0 ] ;
int V_529 = 0 ;
T_4 V_576 ;
T_5 V_557 , V_578 ;
T_4 V_531 ;
T_4 V_579 ;
T_5 V_580 , V_581 ;
T_4 V_582 , V_583 ;
T_4 V_584 , V_585 ;
T_5 V_586 , V_587 ;
T_4 V_588 ;
T_5 V_589 , V_590 ;
T_4 V_591 , V_592 ;
T_4 V_593 , V_594 ;
T_4 V_225 ;
T_4 V_595 ;
T_4 V_596 , V_597 , V_577 ;
T_4 V_598 ;
T_4 V_599 ;
T_5 V_600 ;
T_4 V_601 ;
T_1 V_140 [ 16 ] ;
T_1 V_528 ;
T_6 V_412 ;
#if V_602 == 32
T_5 V_603 ;
#endif
int V_188 ;
switch ( V_279 -> V_556 [ 0 ] ) {
case V_532 :
V_529 = 1 ;
case V_534 :
V_557 = F_238 ( & V_279 -> V_556 [ 2 ] ) ;
V_531 = V_279 -> V_556 [ 4 ] ;
if ( V_531 == 0 )
V_531 = 256 ;
break;
case V_537 :
V_529 = 1 ;
case V_538 :
V_557 =
( ( ( T_5 ) V_279 -> V_556 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_279 -> V_556 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_279 -> V_556 [ 4 ] ) << 8 ) |
V_279 -> V_556 [ 5 ] ;
V_531 =
( ( ( T_4 ) V_279 -> V_556 [ 7 ] ) << 8 ) |
V_279 -> V_556 [ 8 ] ;
break;
case V_533 :
V_529 = 1 ;
case V_535 :
V_557 =
( ( ( T_5 ) V_279 -> V_556 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_279 -> V_556 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_279 -> V_556 [ 4 ] ) << 8 ) |
V_279 -> V_556 [ 5 ] ;
V_531 =
( ( ( T_4 ) V_279 -> V_556 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_279 -> V_556 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_279 -> V_556 [ 8 ] ) << 8 ) |
V_279 -> V_556 [ 9 ] ;
break;
case V_560 :
V_529 = 1 ;
case V_561 :
V_557 =
( ( ( T_5 ) V_279 -> V_556 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_279 -> V_556 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_279 -> V_556 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_279 -> V_556 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_279 -> V_556 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_279 -> V_556 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_279 -> V_556 [ 8 ] ) << 8 ) |
V_279 -> V_556 [ 9 ] ;
V_531 =
( ( ( T_4 ) V_279 -> V_556 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_279 -> V_556 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_279 -> V_556 [ 12 ] ) << 8 ) |
V_279 -> V_556 [ 13 ] ;
break;
default:
return V_536 ;
}
V_578 = V_557 + V_531 - 1 ;
if ( V_529 && V_30 -> V_83 != 0 )
return V_536 ;
if ( V_578 >= F_129 ( V_221 -> V_409 ) ||
V_578 < V_557 )
return V_536 ;
V_579 = F_96 ( V_221 -> V_226 ) *
F_96 ( V_221 -> V_412 ) ;
V_412 = F_96 ( V_221 -> V_412 ) ;
#if V_602 == 32
V_603 = V_557 ;
( void ) F_247 ( V_603 , V_579 ) ;
V_580 = V_603 ;
V_603 = V_578 ;
( void ) F_247 ( V_603 , V_579 ) ;
V_581 = V_603 ;
V_582 = ( T_4 ) ( V_557 - ( V_580 * V_579 ) ) ;
V_583 = ( T_4 ) ( V_578 - ( V_581 * V_579 ) ) ;
V_603 = V_582 ;
( void ) F_247 ( V_603 , V_412 ) ;
V_584 = V_603 ;
V_603 = V_583 ;
( void ) F_247 ( V_603 , V_412 ) ;
V_585 = V_603 ;
#else
V_580 = V_557 / V_579 ;
V_581 = V_578 / V_579 ;
V_582 = ( T_4 ) ( V_557 - ( V_580 * V_579 ) ) ;
V_583 = ( T_4 ) ( V_578 - ( V_581 * V_579 ) ) ;
V_584 = V_582 / V_412 ;
V_585 = V_583 / V_412 ;
#endif
if ( ( V_580 != V_581 ) || ( V_584 != V_585 ) )
return V_536 ;
V_225 = F_96 ( V_221 -> V_226 ) +
F_96 ( V_221 -> V_227 ) ;
V_598 = ( ( T_4 ) ( V_580 >> V_221 -> V_411 ) ) %
F_96 ( V_221 -> V_229 ) ;
V_576 = ( V_598 * V_225 ) + V_584 ;
switch ( V_30 -> V_83 ) {
case V_604 :
break;
case V_605 :
F_75 ( F_96 ( V_221 -> V_230 ) != 2 ) ;
if ( V_30 -> V_188 )
V_576 += F_96 ( V_221 -> V_226 ) ;
V_30 -> V_188 = ! V_30 -> V_188 ;
break;
case V_606 :
F_75 ( F_96 ( V_221 -> V_230 ) != 3 ) ;
V_188 = V_30 -> V_188 ;
F_245 ( V_221 , V_188 ,
& V_576 , & V_577 ) ;
V_188 =
( V_188 >=
F_96 ( V_221 -> V_230 ) - 1 )
? 0 : V_188 + 1 ;
V_30 -> V_188 = V_188 ;
break;
case V_607 :
case V_608 :
if ( F_96 ( V_221 -> V_230 ) <= 1 )
break;
V_588 =
F_96 ( V_221 -> V_412 ) *
F_96 ( V_221 -> V_226 ) ;
F_75 ( V_588 == 0 ) ;
V_595 = V_588 *
F_96 ( V_221 -> V_230 ) ;
#if V_602 == 32
V_603 = V_557 ;
V_596 = F_247 ( V_603 , V_595 ) ;
V_603 = V_596 ;
( void ) F_247 ( V_603 , V_588 ) ;
V_596 = V_603 ;
V_603 = V_578 ;
V_597 = F_247 ( V_603 , V_595 ) ;
V_603 = V_597 ;
( void ) F_247 ( V_603 , V_588 ) ;
V_597 = V_603 ;
#else
V_596 = ( V_557 % V_595 ) / V_588 ;
V_597 = ( V_578 % V_595 ) / V_588 ;
#endif
if ( V_596 != V_597 )
return V_536 ;
#if V_602 == 32
V_603 = V_557 ;
( void ) F_247 ( V_603 , V_595 ) ;
V_580 = V_589 = V_586 = V_603 ;
V_603 = V_578 ;
( void ) F_247 ( V_603 , V_595 ) ;
V_590 = V_587 = V_603 ;
#else
V_580 = V_589 = V_586 =
V_557 / V_595 ;
V_590 = V_587 = V_578 / V_595 ;
#endif
if ( V_589 != V_590 )
return V_536 ;
#if V_602 == 32
V_603 = V_557 ;
V_582 = F_247 ( V_603 , V_595 ) ;
V_603 = V_582 ;
V_582 = ( T_4 ) F_247 ( V_603 , V_588 ) ;
V_591 = V_582 ;
V_603 = V_578 ;
V_592 = F_247 ( V_603 , V_595 ) ;
V_603 = V_592 ;
V_592 = F_247 ( V_603 , V_588 ) ;
V_603 = V_591 ;
( void ) F_247 ( V_603 , V_221 -> V_412 ) ;
V_584 = V_593 = V_603 ;
V_603 = V_592 ;
( void ) F_247 ( V_603 , V_221 -> V_412 ) ;
V_594 = V_603 ;
#else
V_582 = V_591 =
( T_4 ) ( ( V_557 % V_595 ) %
V_588 ) ;
V_592 =
( T_4 ) ( ( V_578 % V_595 ) %
V_588 ) ;
V_584 = V_593 =
V_591 / F_96 ( V_221 -> V_412 ) ;
V_594 =
V_592 / F_96 ( V_221 -> V_412 ) ;
#endif
if ( V_593 != V_594 )
return V_536 ;
V_598 = ( ( T_4 ) ( V_580 >> V_221 -> V_411 ) ) %
F_96 ( V_221 -> V_229 ) ;
V_576 = ( V_596 *
( F_96 ( V_221 -> V_229 ) * V_225 ) ) +
( V_598 * V_225 ) + V_584 ;
break;
default:
return V_536 ;
}
if ( F_44 ( V_576 >= V_233 ) )
return V_536 ;
V_9 -> V_235 = V_30 -> V_235 [ V_576 ] ;
if ( ! V_9 -> V_235 )
return V_536 ;
V_599 = V_223 [ V_576 ] . V_186 ;
V_600 = F_129 ( V_221 -> V_413 ) +
V_580 * F_96 ( V_221 -> V_412 ) +
( V_582 - V_584 *
F_96 ( V_221 -> V_412 ) ) ;
V_601 = V_531 ;
if ( V_221 -> V_410 ) {
V_600 <<= V_221 -> V_410 ;
V_601 <<= V_221 -> V_410 ;
}
F_75 ( V_601 > 0xffff ) ;
if ( V_600 > 0xffffffff ) {
V_140 [ 0 ] = V_529 ? V_560 : V_561 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_600 >> 56 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_600 >> 48 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_600 >> 40 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_600 >> 32 ) ;
V_140 [ 6 ] = ( T_1 ) ( V_600 >> 24 ) ;
V_140 [ 7 ] = ( T_1 ) ( V_600 >> 16 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_600 >> 8 ) ;
V_140 [ 9 ] = ( T_1 ) ( V_600 ) ;
V_140 [ 10 ] = ( T_1 ) ( V_601 >> 24 ) ;
V_140 [ 11 ] = ( T_1 ) ( V_601 >> 16 ) ;
V_140 [ 12 ] = ( T_1 ) ( V_601 >> 8 ) ;
V_140 [ 13 ] = ( T_1 ) ( V_601 ) ;
V_140 [ 14 ] = 0 ;
V_140 [ 15 ] = 0 ;
V_528 = 16 ;
} else {
V_140 [ 0 ] = V_529 ? V_537 : V_538 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_600 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_600 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_600 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_600 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_601 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_601 ) ;
V_140 [ 9 ] = 0 ;
V_528 = 10 ;
}
return F_241 ( V_22 , V_9 , V_599 , V_140 , V_528 ,
V_30 -> V_72 ,
V_30 -> V_235 [ V_576 ] ) ;
}
static int F_248 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_278 * V_279 ,
unsigned char V_72 [] )
{
V_279 -> V_609 = ( unsigned char * ) V_9 ;
V_9 -> V_149 = V_334 ;
V_9 -> V_10 = V_279 ;
V_9 -> V_123 . V_127 = 0 ;
memcpy ( & V_9 -> V_123 . V_344 . V_345 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_123 . V_343 = F_127 ( ( V_9 -> V_132 << V_573 ) ) ;
V_9 -> V_143 . V_610 = 0 ;
F_75 ( V_279 -> V_543 > sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_340 = V_279 -> V_543 ;
memcpy ( V_9 -> V_143 . V_144 , V_279 -> V_556 , V_279 -> V_543 ) ;
switch ( V_279 -> V_546 ) {
case V_547 :
V_9 -> V_143 . V_611 =
F_249 ( V_388 , V_612 , V_613 ) ;
break;
case V_549 :
V_9 -> V_143 . V_611 =
F_249 ( V_388 , V_612 , V_614 ) ;
break;
case V_551 :
V_9 -> V_143 . V_611 =
F_249 ( V_388 , V_612 , V_615 ) ;
break;
case V_616 :
V_9 -> V_143 . V_611 =
F_249 ( V_388 , V_612 , V_617 ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ,
V_279 -> V_546 ) ;
F_175 () ;
break;
}
if ( F_233 ( V_22 , V_9 , V_279 ) < 0 ) {
F_140 ( V_22 , V_9 ) ;
return V_618 ;
}
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_250 ( struct V_1 * V_22 , int V_198 ,
struct V_8 * V_9 )
{
V_367 V_619 , V_620 ;
memset ( V_9 , 0 , F_244 ( struct V_8 , V_400 ) ) ;
V_9 -> V_123 . V_343 = F_127 ( ( T_5 ) ( V_198 << V_573 ) ) ;
V_619 = V_22 -> V_621 + V_198 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_622 + V_198 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_620 = V_22 -> V_623
+ V_198 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_132 = V_198 ;
V_9 -> V_121 = ( T_4 ) V_619 ;
V_9 -> V_624 . V_277 = F_127 ( ( T_5 ) V_620 ) ;
V_9 -> V_624 . V_276 = F_132 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_251 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_399 + V_68 ;
F_250 ( V_22 , V_68 , V_9 ) ;
F_115 ( & V_9 -> V_400 , 0 ) ;
}
}
static inline void F_252 ( struct V_1 * V_22 , int V_198 ,
struct V_8 * V_9 )
{
V_367 V_619 = V_22 -> V_621 + V_198 * sizeof( * V_9 ) ;
F_75 ( V_9 -> V_132 != V_198 ) ;
memset ( V_9 -> V_143 . V_144 , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_121 = ( T_4 ) V_619 ;
}
static int F_253 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_278 * V_279 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_279 -> V_42 -> V_80 ;
int V_21 = V_536 ;
V_279 -> V_609 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_89 ) {
F_250 ( V_22 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_334 ;
V_9 -> V_10 = V_279 ;
V_21 = F_246 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_618 ;
} else if ( V_30 -> V_187 ) {
F_250 ( V_22 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_334 ;
V_9 -> V_10 = V_279 ;
V_21 = F_240 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_618 ;
}
return V_21 ;
}
static void V_320 ( struct V_625 * V_319 )
{
struct V_278 * V_279 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_254 ( V_319 , struct V_8 , V_319 ) ;
V_279 = V_9 -> V_10 ;
V_30 = V_279 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_279 -> V_289 = V_338 << 16 ;
return F_142 ( V_9 -> V_22 , V_9 , V_279 ) ;
}
if ( V_9 -> V_13 )
return F_140 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_147 ( V_9 -> V_22 , V_9 , V_279 ) ;
if ( V_9 -> V_149 == V_153 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_138 * V_280 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
int V_21 ;
if ( V_280 -> V_284 . V_285 ==
V_298 ) {
V_21 = F_253 ( V_22 , V_9 , V_279 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_618 ) {
V_279 -> V_289 = V_626 << 16 ;
return F_142 ( V_22 , V_9 , V_279 ) ;
}
}
}
F_252 ( V_9 -> V_22 , V_9 -> V_132 , V_9 ) ;
if ( F_248 ( V_9 -> V_22 , V_9 , V_279 , V_30 -> V_72 ) ) {
V_279 -> V_289 = V_626 << 16 ;
V_279 -> V_318 ( V_279 ) ;
}
}
static int F_255 ( struct V_6 * V_7 , struct V_278 * V_279 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_279 -> V_42 ) ;
F_75 ( V_279 -> V_627 -> V_343 < 0 ) ;
V_30 = V_279 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_279 -> V_289 = V_338 << 16 ;
V_279 -> V_318 ( V_279 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_44 ( F_13 ( V_22 ) ) ) {
V_279 -> V_289 = V_338 << 16 ;
V_279 -> V_318 ( V_279 ) ;
return 0 ;
}
V_9 = F_256 ( V_22 , V_279 ) ;
if ( F_47 ( V_279 -> V_628 == 0 &&
V_279 -> V_627 -> V_149 == V_629 &&
V_22 -> V_56 ) ) {
V_21 = F_253 ( V_22 , V_9 , V_279 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_618 ) {
F_140 ( V_22 , V_9 ) ;
return V_618 ;
}
}
return F_248 ( V_22 , V_9 , V_279 , V_72 ) ;
}
static void F_257 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_630 , V_78 ) ;
V_22 -> V_631 = 1 ;
F_139 ( & V_22 -> V_632 ) ;
F_36 ( & V_22 -> V_630 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_257 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_630 , V_78 ) ;
if ( V_22 -> V_631 )
break;
F_36 ( & V_22 -> V_630 , V_78 ) ;
F_179 ( V_22 -> V_632 , V_22 -> V_631 ) ;
}
V_22 -> V_631 = 0 ;
F_36 ( & V_22 -> V_630 , V_78 ) ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_257 ( V_22 ) ;
F_228 ( V_22 ) ;
F_257 ( V_22 ) ;
}
static int F_258 ( struct V_2 * V_3 , int V_232 )
{
struct V_73 * V_219 = V_3 -> V_80 ;
if ( ! V_219 )
return - V_81 ;
if ( V_232 < 1 )
V_232 = 1 ;
else if ( V_232 > V_219 -> V_189 )
V_232 = V_219 -> V_189 ;
return F_117 ( V_3 , V_232 ) ;
}
static int F_259 ( struct V_6 * V_7 ,
unsigned long V_633 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_634 ;
F_35 ( & V_22 -> V_630 , V_78 ) ;
V_634 = V_22 -> V_631 ;
F_36 ( & V_22 -> V_630 , V_78 ) ;
return V_634 ;
}
static int F_260 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_261 ( & V_635 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_165 ) ;
return - V_256 ;
}
V_7 -> V_636 = 0 ;
V_7 -> V_637 = 0 ;
V_7 -> V_638 = - 1 ;
V_7 -> V_639 = 3 ;
V_7 -> V_640 = V_641 ;
V_7 -> V_642 = V_493 ;
V_7 -> V_643 = V_493 ;
V_7 -> V_253 = V_22 -> V_236 - V_644 ;
V_7 -> V_645 = V_7 -> V_253 ;
V_7 -> V_646 = V_22 -> V_257 ;
V_7 -> V_647 = V_648 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_649 = V_22 -> V_650 [ V_22 -> V_651 ] ;
V_7 -> V_652 = V_7 -> V_649 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_262 ( struct V_1 * V_22 )
{
int V_653 ;
V_653 = F_263 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_653 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_166 ) ;
return V_653 ;
}
F_264 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_265 ( struct V_278 * V_654 )
{
int V_655 = V_654 -> V_627 -> V_343 ;
if ( V_655 < 0 )
return V_655 ;
return V_655 += V_644 ;
}
static int F_266 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_656 [] ,
int V_112 )
{
int V_21 ;
( void ) F_171 ( V_9 , V_470 , V_22 ,
NULL , 0 , 0 , V_656 , V_388 ) ;
V_21 = F_161 ( V_22 , V_9 , V_112 , V_375 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_657 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_290 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_658 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_267 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_656 [] , int V_112 )
{
int V_21 ;
int V_48 = 0 ;
int V_659 = 1 ;
for ( V_48 = 0 ; V_48 < V_660 ; V_48 ++ ) {
F_166 ( 1000 * V_659 ) ;
V_21 = F_266 ( V_22 , V_9 , V_656 , V_112 ) ;
if ( ! V_21 )
break;
if ( V_659 < V_661 )
V_659 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_167 ,
V_659 ) ;
}
return V_21 ;
}
static int F_268 ( struct V_1 * V_22 ,
unsigned char V_656 [] ,
int V_112 )
{
int V_662 ;
int V_663 ;
int V_111 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
if ( V_112 == V_126 ) {
V_662 = 0 ;
V_663 = V_22 -> V_128 - 1 ;
} else {
V_662 = V_112 ;
V_663 = V_112 ;
}
for ( V_111 = V_662 ; V_111 <= V_663 ; V_111 ++ ) {
V_21 = F_267 ( V_22 , V_9 , V_656 , V_111 ) ;
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
static int F_269 ( struct V_278 * V_664 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_391 ;
char V_665 [ 48 ] ;
V_22 = F_1 ( V_664 -> V_42 ) ;
if ( V_22 == NULL )
return V_666 ;
if ( F_13 ( V_22 ) )
return V_666 ;
V_30 = V_664 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_170 , V_203 ) ;
return V_666 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_665 , sizeof( V_665 ) ,
L_171 ,
F_265 ( V_664 ) ) ;
F_69 ( V_238 , V_22 , V_30 , V_665 ) ;
return V_666 ;
}
if ( F_270 ( V_22 ) ) {
snprintf ( V_665 , sizeof( V_665 ) ,
L_172 ,
F_265 ( V_664 ) ) ;
F_69 ( V_238 , V_22 , V_30 , V_665 ) ;
return V_666 ;
}
if ( F_62 ( V_30 -> V_72 ) )
return V_667 ;
if ( F_31 ( V_30 -> V_72 ) )
V_391 = V_668 ;
else
V_391 = V_669 ;
sprintf ( V_665 , L_173 ,
V_391 == V_668 ? L_174 : L_175 ) ;
F_69 ( V_238 , V_22 , V_30 , V_665 ) ;
V_22 -> V_243 = 1 ;
V_21 = F_176 ( V_22 , V_30 , V_30 -> V_72 , V_391 ,
V_126 ) ;
sprintf ( V_665 , L_176 ,
V_391 == V_668 ? L_174 : L_175 ,
V_21 == 0 ? L_177 : L_178 ) ;
F_69 ( V_238 , V_22 , V_30 , V_665 ) ;
V_22 -> V_243 = 0 ;
return V_21 == 0 ? V_667 : V_666 ;
}
static void F_271 ( T_1 * V_343 )
{
T_1 V_670 [ 8 ] ;
memcpy ( V_670 , V_343 , 8 ) ;
V_343 [ 0 ] = V_670 [ 3 ] ;
V_343 [ 1 ] = V_670 [ 2 ] ;
V_343 [ 2 ] = V_670 [ 1 ] ;
V_343 [ 3 ] = V_670 [ 0 ] ;
V_343 [ 4 ] = V_670 [ 7 ] ;
V_343 [ 5 ] = V_670 [ 6 ] ;
V_343 [ 6 ] = V_670 [ 5 ] ;
V_343 [ 7 ] = V_670 [ 4 ] ;
}
static void F_272 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_671 , T_7 * V_672 )
{
T_5 V_343 ;
if ( V_9 -> V_149 == V_150 ) {
struct V_129 * V_673 = (struct V_129 * )
& V_22 -> V_131 [ V_9 -> V_132 ] ;
V_343 = F_129 ( V_673 -> V_343 ) ;
* V_672 = F_132 ( V_343 >> 32 ) ;
* V_671 = F_132 ( V_343 ) ;
return;
}
if ( V_9 -> V_149 == V_153 ) {
struct V_138 * V_674 = (struct V_138 * )
& V_22 -> V_136 [ V_9 -> V_132 ] ;
memset ( V_672 , 0 , sizeof( * V_672 ) ) ;
* V_671 = V_674 -> V_572 ;
return;
}
V_343 = F_129 ( V_9 -> V_123 . V_343 ) ;
* V_672 = F_132 ( V_343 >> 32 ) ;
* V_671 = F_132 ( V_343 ) ;
}
static int F_273 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_112 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
struct V_331 * V_332 ;
T_7 V_672 , V_671 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_472 , V_22 , & abort -> V_123 . V_343 ,
0 , 0 , V_72 , V_392 ) ;
if ( V_22 -> V_71 )
F_271 ( & V_9 -> V_143 . V_144 [ 4 ] ) ;
( void ) F_161 ( V_22 , V_9 , V_112 , V_375 ) ;
F_272 ( V_22 , abort , & V_671 , & V_672 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_179 ,
V_203 , V_672 , V_671 ) ;
V_332 = V_9 -> V_24 ;
switch ( V_332 -> V_36 ) {
case V_657 :
break;
case V_363 :
V_21 = F_149 ( V_22 , V_9 ) ;
break;
case V_362 :
V_21 = - 1 ;
break;
default:
F_274 ( & V_22 -> V_29 -> V_30 , L_180 ,
V_203 , V_672 , V_671 ) ;
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_172 ( V_22 , V_9 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_181 ,
V_203 , V_672 , V_671 ) ;
return V_21 ;
}
static void F_275 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_675 , int V_112 )
{
struct V_138 * V_280 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_135 * V_394 = (struct V_135 * ) V_280 ;
struct V_138 * V_676 =
& V_22 -> V_136 [ V_675 -> V_132 ] ;
struct V_278 * V_654 = V_675 -> V_10 ;
struct V_73 * V_30 = V_654 -> V_42 -> V_80 ;
F_276 ( sizeof( struct V_135 ) >
sizeof( struct V_138 ) ) ;
F_75 ( F_244 ( struct V_138 , V_284 ) <
F_244 ( struct V_135 , V_677 ) +
sizeof( V_394 -> V_677 ) ) ;
V_9 -> V_149 = V_155 ;
V_9 -> V_10 = V_678 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_564 +
( V_9 -> V_132 * sizeof( struct V_138 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
memset ( V_394 , 0 , sizeof( * V_280 ) ) ;
V_394 -> V_679 = V_680 ;
V_394 -> V_112 = V_112 ;
V_394 -> V_681 = V_682 ;
V_394 -> V_396 = F_132 ( V_30 -> V_186 ) ;
memset ( V_394 -> V_683 , 0 , sizeof( V_394 -> V_683 ) ) ;
V_394 -> V_343 = F_127 ( V_9 -> V_132 << V_573 ) ;
V_394 -> V_684 = F_127 ( F_124 ( V_676 -> V_572 ) ) ;
V_394 -> V_685 = F_127 ( V_9 -> V_121 +
F_244 ( struct V_138 , V_284 ) ) ;
V_394 -> V_677 = F_132 ( sizeof( V_280 -> V_284 ) ) ;
}
static int F_277 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_112 )
{
int V_21 = V_376 ;
struct V_278 * V_654 ;
struct V_73 * V_30 ;
unsigned char V_686 [ 8 ] ;
unsigned char * V_687 = & V_686 [ 0 ] ;
V_654 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_654 -> V_42 -> V_80 ) ;
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
if ( ! F_218 ( V_22 , abort , V_687 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_186 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_687 [ 0 ] , V_687 [ 1 ] , V_687 [ 2 ] , V_687 [ 3 ] ,
V_687 [ 4 ] , V_687 [ 5 ] , V_687 [ 6 ] , V_687 [ 7 ] ) ;
V_21 = F_176 ( V_22 , V_30 , V_687 , V_688 , V_112 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_188 ,
V_687 [ 0 ] , V_687 [ 1 ] , V_687 [ 2 ] , V_687 [ 3 ] ,
V_687 [ 4 ] , V_687 [ 5 ] , V_687 [ 6 ] , V_687 [ 7 ] ) ;
return V_21 ;
}
if ( F_268 ( V_22 , V_687 , V_112 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_189 ,
V_687 [ 0 ] , V_687 [ 1 ] , V_687 [ 2 ] , V_687 [ 3 ] ,
V_687 [ 4 ] , V_687 [ 5 ] , V_687 [ 6 ] , V_687 [ 7 ] ) ;
return - 1 ;
}
F_94 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_687 [ 0 ] , V_687 [ 1 ] , V_687 [ 2 ] , V_687 [ 3 ] ,
V_687 [ 4 ] , V_687 [ 5 ] , V_687 [ 6 ] , V_687 [ 7 ] ) ;
return V_21 ;
}
static int F_278 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_112 )
{
int V_21 = V_376 ;
struct V_8 * V_9 ;
T_7 V_671 , V_672 ;
struct V_73 * V_30 ;
struct V_138 * V_280 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 -> V_89 && ! V_30 -> V_187 )
return - 1 ;
V_9 = F_170 ( V_22 ) ;
F_275 ( V_9 , V_22 , abort , V_112 ) ;
V_280 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
( void ) F_161 ( V_22 , V_9 , V_112 , V_375 ) ;
F_272 ( V_22 , abort , & V_671 , & V_672 ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_203 , V_672 , V_671 ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_203 , V_672 , V_671 , V_280 -> V_284 . V_285 ) ;
switch ( V_280 -> V_284 . V_285 ) {
case V_311 :
case V_312 :
V_21 = 0 ;
break;
case V_313 :
case V_300 :
case V_314 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_193 ,
V_203 , V_672 , V_671 ,
V_280 -> V_284 . V_285 ) ;
V_21 = - 1 ;
}
F_172 ( V_22 , V_9 ) ;
F_274 ( & V_22 -> V_29 -> V_30 , L_181 , V_203 ,
V_672 , V_671 ) ;
return V_21 ;
}
static int F_279 ( struct V_1 * V_22 ,
struct V_73 * V_30 , struct V_8 * abort , int V_112 )
{
if ( abort -> V_149 == V_153 ) {
if ( ( V_689 & V_22 -> V_690 ) ||
V_30 -> V_74 )
return F_278 ( V_22 , abort ,
V_112 ) ;
else
return F_277 ( V_22 ,
V_30 -> V_72 ,
abort , V_112 ) ;
}
return F_273 ( V_22 , V_30 -> V_72 , abort , V_112 ) ;
}
static int F_280 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_149 == V_153 )
return V_22 -> V_136 [ V_9 -> V_132 ] . V_112 ;
return V_9 -> V_123 . V_127 ;
}
static inline int F_281 ( struct V_1 * V_22 )
{
#define F_282 5000
return ! F_283 ( V_22 -> V_691 ,
F_284 ( & V_22 -> V_692 ) >= 0 ,
F_160 ( F_282 ) ) ;
}
static int F_285 ( struct V_278 * V_693 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_278 * V_694 ;
char V_665 [ 256 ] ;
int V_695 = 0 ;
T_7 V_672 , V_671 ;
int V_400 , V_112 ;
if ( V_693 == NULL )
return V_666 ;
if ( V_693 -> V_42 == NULL )
return V_666 ;
V_22 = F_1 ( V_693 -> V_42 ) ;
if ( V_22 == NULL )
return V_666 ;
V_30 = V_693 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_194 ,
V_665 ) ;
return V_666 ;
}
if ( F_13 ( V_22 ) ) {
F_69 ( V_238 , V_22 , V_30 ,
L_195 ) ;
return V_666 ;
}
if ( F_270 ( V_22 ) ) {
F_69 ( V_238 , V_22 , V_30 ,
L_196 ) ;
return V_666 ;
}
if ( ! ( V_696 & V_22 -> V_690 ) &&
! ( V_697 & V_22 -> V_690 ) )
return V_666 ;
memset ( V_665 , 0 , sizeof( V_665 ) ) ;
V_695 += sprintf ( V_665 + V_695 , L_197 ,
V_22 -> V_59 -> V_100 , V_693 -> V_42 -> V_698 ,
V_693 -> V_42 -> V_699 , V_693 -> V_42 -> V_103 ,
L_198 , V_693 ) ;
abort = (struct V_8 * ) V_693 -> V_609 ;
if ( abort == NULL ) {
return V_667 ;
}
V_400 = F_178 ( & abort -> V_400 ) ;
if ( V_400 == 1 ) {
F_172 ( V_22 , abort ) ;
return V_667 ;
}
if ( abort -> V_149 != V_153 &&
abort -> V_149 != V_150 && ! V_30 -> V_479 ) {
F_172 ( V_22 , abort ) ;
return V_666 ;
}
if ( abort -> V_10 != V_693 ) {
F_172 ( V_22 , abort ) ;
return V_667 ;
}
abort -> V_12 = true ;
F_272 ( V_22 , abort , & V_671 , & V_672 ) ;
V_112 = F_280 ( V_22 , abort ) ;
V_695 += sprintf ( V_665 + V_695 , L_199 , V_672 , V_671 ) ;
V_694 = abort -> V_10 ;
if ( V_694 != NULL )
V_695 += sprintf ( V_665 + V_695 ,
L_200 ,
V_694 -> V_543 , V_694 -> V_556 [ 0 ] , V_694 -> V_556 [ 1 ] ,
V_694 -> V_700 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_201 , V_665 ) ;
F_69 ( V_238 , V_22 , V_30 , L_198 ) ;
if ( F_281 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_202 ,
V_665 ) ;
F_172 ( V_22 , abort ) ;
return V_666 ;
}
V_21 = F_279 ( V_22 , V_30 , abort , V_112 ) ;
F_55 ( & V_22 -> V_692 ) ;
F_139 ( & V_22 -> V_691 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_203 , V_665 ) ;
F_69 ( V_238 , V_22 , V_30 ,
L_204 ) ;
F_172 ( V_22 , abort ) ;
return V_666 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_205 , V_665 ) ;
F_179 ( V_22 -> V_317 ,
abort -> V_10 != V_693 || F_13 ( V_22 ) ) ;
F_172 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_667 : V_666 ;
}
static struct V_8 * F_256 ( struct V_1 * V_22 ,
struct V_278 * V_654 )
{
int V_655 = F_265 ( V_654 ) ;
struct V_8 * V_9 = V_22 -> V_399 + V_655 ;
if ( V_655 < V_644 || V_655 >= V_22 -> V_236 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_206 ,
V_655 , V_644 , V_22 -> V_236 - 1 ) ;
F_175 () ;
}
F_55 ( & V_9 -> V_400 ) ;
if ( F_44 ( ! F_4 ( V_9 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_207 ,
V_655 ) ;
if ( V_9 -> V_10 != NULL )
F_286 ( V_9 -> V_10 ) ;
F_286 ( V_654 ) ;
}
F_252 ( V_22 , V_655 , V_9 ) ;
return V_9 ;
}
static void F_141 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_45 ( & V_9 -> V_400 ) ;
}
static struct V_8 * F_170 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_400 , V_68 ;
int V_701 = 0 ;
for (; ; ) {
V_68 = F_287 ( V_22 -> V_702 ,
V_644 ,
V_701 ) ;
if ( F_44 ( V_68 >= V_644 ) ) {
V_701 = 0 ;
continue;
}
V_9 = V_22 -> V_399 + V_68 ;
V_400 = F_178 ( & V_9 -> V_400 ) ;
if ( F_44 ( V_400 > 1 ) ) {
F_172 ( V_22 , V_9 ) ;
V_701 = ( V_68 + 1 ) % V_644 ;
continue;
}
F_288 ( V_68 & ( V_602 - 1 ) ,
V_22 -> V_702 + ( V_68 / V_602 ) ) ;
break;
}
F_252 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_172 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_57 ( & V_9 -> V_400 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_399 ;
F_289 ( V_68 & ( V_602 - 1 ) ,
V_22 -> V_702 + ( V_68 / V_602 ) ) ;
}
}
static int F_290 ( struct V_2 * V_30 , int V_279 ,
void T_8 * V_703 )
{
T_9 T_8 * V_704 =
( T_9 T_8 * ) V_703 ;
T_10 V_705 ;
T_10 T_8 * V_706 = F_291 ( sizeof( V_705 ) ) ;
int V_707 ;
T_4 V_130 ;
memset ( & V_705 , 0 , sizeof( V_705 ) ) ;
V_707 = 0 ;
V_707 |= F_292 ( & V_705 . V_708 , & V_704 -> V_708 ,
sizeof( V_705 . V_708 ) ) ;
V_707 |= F_292 ( & V_705 . V_143 , & V_704 -> V_143 ,
sizeof( V_705 . V_143 ) ) ;
V_707 |= F_292 ( & V_705 . V_709 , & V_704 -> V_709 ,
sizeof( V_705 . V_709 ) ) ;
V_707 |= F_293 ( V_705 . V_710 , & V_704 -> V_710 ) ;
V_707 |= F_293 ( V_130 , & V_704 -> V_45 ) ;
V_705 . V_45 = F_294 ( V_130 ) ;
V_707 |= F_295 ( V_706 , & V_705 , sizeof( V_705 ) ) ;
if ( V_707 )
return - V_711 ;
V_707 = F_296 ( V_30 , V_712 , V_706 ) ;
if ( V_707 )
return V_707 ;
V_707 |= F_297 ( & V_704 -> V_709 , & V_706 -> V_709 ,
sizeof( V_704 -> V_709 ) ) ;
if ( V_707 )
return - V_711 ;
return V_707 ;
}
static int F_298 ( struct V_2 * V_30 ,
int V_279 , void T_8 * V_703 )
{
T_11 T_8 * V_704 =
( T_11 T_8 * ) V_703 ;
T_12 V_705 ;
T_12 T_8 * V_706 =
F_291 ( sizeof( V_705 ) ) ;
int V_707 ;
T_4 V_130 ;
memset ( & V_705 , 0 , sizeof( V_705 ) ) ;
V_707 = 0 ;
V_707 |= F_292 ( & V_705 . V_708 , & V_704 -> V_708 ,
sizeof( V_705 . V_708 ) ) ;
V_707 |= F_292 ( & V_705 . V_143 , & V_704 -> V_143 ,
sizeof( V_705 . V_143 ) ) ;
V_707 |= F_292 ( & V_705 . V_709 , & V_704 -> V_709 ,
sizeof( V_705 . V_709 ) ) ;
V_707 |= F_293 ( V_705 . V_710 , & V_704 -> V_710 ) ;
V_707 |= F_293 ( V_705 . V_713 , & V_704 -> V_713 ) ;
V_707 |= F_293 ( V_130 , & V_704 -> V_45 ) ;
V_705 . V_45 = F_294 ( V_130 ) ;
V_707 |= F_295 ( V_706 , & V_705 , sizeof( V_705 ) ) ;
if ( V_707 )
return - V_711 ;
V_707 = F_296 ( V_30 , V_714 , V_706 ) ;
if ( V_707 )
return V_707 ;
V_707 |= F_297 ( & V_704 -> V_709 , & V_706 -> V_709 ,
sizeof( V_704 -> V_709 ) ) ;
if ( V_707 )
return - V_711 ;
return V_707 ;
}
static int F_299 ( struct V_2 * V_30 , int V_279 , void T_8 * V_703 )
{
switch ( V_279 ) {
case V_715 :
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
return F_296 ( V_30 , V_279 , V_703 ) ;
case V_730 :
return F_290 ( V_30 , V_279 , V_703 ) ;
case V_731 :
return F_298 ( V_30 , V_279 , V_703 ) ;
default:
return - V_732 ;
}
}
static int F_300 ( struct V_1 * V_22 , void T_8 * V_733 )
{
struct V_734 V_735 ;
if ( ! V_733 )
return - V_55 ;
V_735 . V_736 = F_301 ( V_22 -> V_29 -> V_101 ) ;
V_735 . V_101 = V_22 -> V_29 -> V_101 -> V_737 ;
V_735 . V_738 = V_22 -> V_29 -> V_739 ;
V_735 . V_67 = V_22 -> V_67 ;
if ( F_295 ( V_733 , & V_735 , sizeof( V_735 ) ) )
return - V_711 ;
return 0 ;
}
static int F_302 ( struct V_1 * V_22 , void T_8 * V_733 )
{
T_13 V_740 ;
unsigned char V_741 , V_742 , V_743 ;
int V_21 ;
V_21 = sscanf ( V_744 , L_208 ,
& V_741 , & V_742 , & V_743 ) ;
if ( V_21 != 3 ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_209
L_210 , V_744 ) ;
V_741 = 0 ;
V_742 = 0 ;
V_743 = 0 ;
}
V_740 = ( V_741 << 16 ) | ( V_742 << 8 ) | V_743 ;
if ( ! V_733 )
return - V_55 ;
if ( F_295 ( V_733 , & V_740 , sizeof( T_13 ) ) )
return - V_711 ;
return 0 ;
}
static int F_303 ( struct V_1 * V_22 , void T_8 * V_733 )
{
T_10 V_745 ;
struct V_8 * V_9 ;
char * V_746 = NULL ;
T_5 V_262 ;
int V_21 = 0 ;
if ( ! V_733 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_747 ;
if ( F_292 ( & V_745 , V_733 , sizeof( V_745 ) ) )
return - V_711 ;
if ( ( V_745 . V_710 < 1 ) &&
( V_745 . V_143 . Type . V_748 != V_615 ) ) {
return - V_55 ;
}
if ( V_745 . V_710 > 0 ) {
V_746 = F_91 ( V_745 . V_710 , V_202 ) ;
if ( V_746 == NULL )
return - V_256 ;
if ( V_745 . V_143 . Type . V_748 & V_613 ) {
if ( F_292 ( V_746 , V_745 . V_45 ,
V_745 . V_710 ) ) {
V_21 = - V_711 ;
goto V_749;
}
} else {
memset ( V_746 , 0 , V_745 . V_710 ) ;
}
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_149 = V_395 ;
V_9 -> V_10 = V_678 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_745 . V_710 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_275 = F_153 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_275 = F_153 ( 0 ) ;
}
memcpy ( & V_9 -> V_123 . V_344 , & V_745 . V_708 , sizeof( V_9 -> V_123 . V_344 ) ) ;
memcpy ( & V_9 -> V_143 , & V_745 . V_143 ,
sizeof( V_9 -> V_143 ) ) ;
if ( V_745 . V_710 > 0 ) {
V_262 = F_125 ( V_22 -> V_29 , V_746 ,
V_745 . V_710 , V_750 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , ( V_367 ) V_262 ) ) {
V_9 -> V_271 [ 0 ] . V_277 = F_127 ( 0 ) ;
V_9 -> V_271 [ 0 ] . V_276 = F_132 ( 0 ) ;
V_21 = - V_256 ;
goto V_389;
}
V_9 -> V_271 [ 0 ] . V_277 = F_127 ( V_262 ) ;
V_9 -> V_271 [ 0 ] . V_276 = F_132 ( V_745 . V_710 ) ;
V_9 -> V_271 [ 0 ] . V_273 = F_132 ( V_371 ) ;
}
V_21 = F_161 ( V_22 , V_9 , V_126 , V_375 ) ;
if ( V_745 . V_710 > 0 )
F_154 ( V_22 -> V_29 , V_9 , 1 , V_750 ) ;
F_304 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_382 ;
goto V_389;
}
memcpy ( & V_745 . V_709 , V_9 -> V_24 ,
sizeof( V_745 . V_709 ) ) ;
if ( F_295 ( V_733 , & V_745 , sizeof( V_745 ) ) ) {
V_21 = - V_711 ;
goto V_389;
}
if ( ( V_745 . V_143 . Type . V_748 & V_614 ) &&
V_745 . V_710 > 0 ) {
if ( F_295 ( V_745 . V_45 , V_746 , V_745 . V_710 ) ) {
V_21 = - V_711 ;
goto V_389;
}
}
V_389:
F_172 ( V_22 , V_9 ) ;
V_749:
F_80 ( V_746 ) ;
return V_21 ;
}
static int F_305 ( struct V_1 * V_22 , void T_8 * V_733 )
{
T_12 * V_751 ;
struct V_8 * V_9 ;
unsigned char * * V_746 = NULL ;
int * V_752 = NULL ;
T_5 V_262 ;
T_14 V_365 = 0 ;
int V_49 = 0 ;
T_4 V_753 ;
T_4 V_754 ;
T_14 T_8 * V_755 ;
if ( ! V_733 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_747 ;
V_751 = ( T_12 * )
F_91 ( sizeof( * V_751 ) , V_202 ) ;
if ( ! V_751 ) {
V_49 = - V_256 ;
goto V_756;
}
if ( F_292 ( V_751 , V_733 , sizeof( * V_751 ) ) ) {
V_49 = - V_711 ;
goto V_756;
}
if ( ( V_751 -> V_710 < 1 ) &&
( V_751 -> V_143 . Type . V_748 != V_615 ) ) {
V_49 = - V_55 ;
goto V_756;
}
if ( V_751 -> V_713 > V_757 ) {
V_49 = - V_55 ;
goto V_756;
}
if ( V_751 -> V_710 > V_751 -> V_713 * V_758 ) {
V_49 = - V_55 ;
goto V_756;
}
V_746 = F_108 ( V_758 * sizeof( char * ) , V_202 ) ;
if ( ! V_746 ) {
V_49 = - V_256 ;
goto V_756;
}
V_752 = F_91 ( V_758 * sizeof( int ) , V_202 ) ;
if ( ! V_752 ) {
V_49 = - V_256 ;
goto V_756;
}
V_753 = V_751 -> V_710 ;
V_755 = V_751 -> V_45 ;
while ( V_753 ) {
V_754 = ( V_753 > V_751 -> V_713 ) ? V_751 -> V_713 : V_753 ;
V_752 [ V_365 ] = V_754 ;
V_746 [ V_365 ] = F_91 ( V_754 , V_202 ) ;
if ( V_746 [ V_365 ] == NULL ) {
V_49 = - V_256 ;
goto V_756;
}
if ( V_751 -> V_143 . Type . V_748 & V_613 ) {
if ( F_292 ( V_746 [ V_365 ] , V_755 , V_754 ) ) {
V_49 = - V_711 ;
goto V_756;
}
} else
memset ( V_746 [ V_365 ] , 0 , V_754 ) ;
V_753 -= V_754 ;
V_755 += V_754 ;
V_365 ++ ;
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_149 = V_395 ;
V_9 -> V_10 = V_678 ;
V_9 -> V_123 . V_127 = 0 ;
V_9 -> V_123 . V_124 = ( T_1 ) V_365 ;
V_9 -> V_123 . V_275 = F_153 ( V_365 ) ;
memcpy ( & V_9 -> V_123 . V_344 , & V_751 -> V_708 , sizeof( V_9 -> V_123 . V_344 ) ) ;
memcpy ( & V_9 -> V_143 , & V_751 -> V_143 , sizeof( V_9 -> V_143 ) ) ;
if ( V_751 -> V_710 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_365 ; V_68 ++ ) {
V_262 = F_125 ( V_22 -> V_29 , V_746 [ V_68 ] ,
V_752 [ V_68 ] , V_750 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 ,
( V_367 ) V_262 ) ) {
V_9 -> V_271 [ V_68 ] . V_277 = F_127 ( 0 ) ;
V_9 -> V_271 [ V_68 ] . V_276 = F_132 ( 0 ) ;
F_154 ( V_22 -> V_29 , V_9 , V_68 ,
V_750 ) ;
V_49 = - V_256 ;
goto V_759;
}
V_9 -> V_271 [ V_68 ] . V_277 = F_127 ( V_262 ) ;
V_9 -> V_271 [ V_68 ] . V_276 = F_132 ( V_752 [ V_68 ] ) ;
V_9 -> V_271 [ V_68 ] . V_273 = F_132 ( 0 ) ;
}
V_9 -> V_271 [ -- V_68 ] . V_273 = F_132 ( V_371 ) ;
}
V_49 = F_161 ( V_22 , V_9 , V_126 , V_375 ) ;
if ( V_365 )
F_154 ( V_22 -> V_29 , V_9 , V_365 , V_750 ) ;
F_304 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_382 ;
goto V_759;
}
memcpy ( & V_751 -> V_709 , V_9 -> V_24 , sizeof( V_751 -> V_709 ) ) ;
if ( F_295 ( V_733 , V_751 , sizeof( * V_751 ) ) ) {
V_49 = - V_711 ;
goto V_759;
}
if ( ( V_751 -> V_143 . Type . V_748 & V_614 ) && V_751 -> V_710 > 0 ) {
int V_68 ;
T_14 T_8 * V_760 = V_751 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_365 ; V_68 ++ ) {
if ( F_295 ( V_760 , V_746 [ V_68 ] , V_752 [ V_68 ] ) ) {
V_49 = - V_711 ;
goto V_759;
}
V_760 += V_752 [ V_68 ] ;
}
}
V_49 = 0 ;
V_759:
F_172 ( V_22 , V_9 ) ;
V_756:
if ( V_746 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_365 ; V_68 ++ )
F_80 ( V_746 [ V_68 ] ) ;
F_80 ( V_746 ) ;
}
F_80 ( V_752 ) ;
F_80 ( V_751 ) ;
return V_49 ;
}
static void F_304 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_290 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_296 ( struct V_2 * V_30 , int V_279 , void T_8 * V_703 )
{
struct V_1 * V_22 ;
void T_8 * V_733 = ( void T_8 * ) V_703 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_279 ) {
case V_725 :
case V_726 :
case V_727 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_715 :
return F_300 ( V_22 , V_733 ) ;
case V_723 :
return F_302 ( V_22 , V_733 ) ;
case V_712 :
if ( F_284 ( & V_22 -> V_761 ) < 0 )
return - V_762 ;
V_21 = F_303 ( V_22 , V_733 ) ;
F_55 ( & V_22 -> V_761 ) ;
return V_21 ;
case V_714 :
if ( F_284 ( & V_22 -> V_761 ) < 0 )
return - V_762 ;
V_21 = F_305 ( V_22 , V_733 ) ;
F_55 ( & V_22 -> V_761 ) ;
return V_21 ;
default:
return - V_763 ;
}
}
static void F_306 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_391 )
{
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_668 , V_22 , NULL , 0 , 0 ,
V_157 , V_392 ) ;
V_9 -> V_143 . V_144 [ 1 ] = V_391 ;
V_9 -> V_374 = NULL ;
F_60 ( V_22 , V_9 ) ;
return;
}
static int F_171 ( struct V_8 * V_9 , T_1 V_279 , struct V_1 * V_22 ,
void * V_746 , T_3 V_463 , T_6 V_764 , unsigned char * V_72 ,
int V_149 )
{
int V_765 = V_615 ;
T_5 V_343 ;
V_9 -> V_149 = V_395 ;
V_9 -> V_10 = V_678 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_746 != NULL && V_463 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_275 = F_153 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_275 = F_153 ( 0 ) ;
}
memcpy ( V_9 -> V_123 . V_344 . V_345 , V_72 , 8 ) ;
if ( V_149 == V_388 ) {
switch ( V_279 ) {
case V_387 :
if ( V_764 & V_401 ) {
V_9 -> V_143 . V_144 [ 1 ] = 0x01 ;
V_9 -> V_143 . V_144 [ 2 ] = ( V_764 & 0xff ) ;
}
V_9 -> V_143 . V_340 = 6 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_387 ;
V_9 -> V_143 . V_144 [ 4 ] = V_463 & 0xFF ;
break;
case V_457 :
case V_458 :
V_9 -> V_143 . V_340 = 12 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_279 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_463 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_463 & 0xFF ;
break;
case V_766 :
V_9 -> V_143 . V_340 = 16 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 6 ] = V_766 ;
break;
case V_768 :
V_9 -> V_143 . V_340 = 16 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 ,
V_612 , V_613 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_768 ;
break;
case V_769 :
V_9 -> V_143 . V_340 = 12 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 ,
V_612 , V_613 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_770 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = V_463 & 0xFF ;
break;
case V_470 :
V_9 -> V_143 . V_340 = 6 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_615 ) ;
V_9 -> V_143 . V_610 = 0 ;
break;
case V_419 :
V_9 -> V_143 . V_340 = 12 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_771 ;
V_9 -> V_143 . V_144 [ 1 ] = V_279 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_463 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_463 & 0xFF ;
break;
case V_772 :
V_9 -> V_143 . V_340 = 10 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 6 ] = V_772 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0xFF ;
break;
case V_426 :
V_9 -> V_143 . V_340 = 10 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 6 ] = V_426 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0XFF ;
break;
case V_422 :
V_9 -> V_143 . V_340 = 10 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 6 ] = V_422 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0XFF ;
break;
case V_436 :
V_9 -> V_143 . V_340 = 10 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 6 ] = V_436 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0XFF ;
break;
case V_424 :
V_9 -> V_143 . V_340 = 10 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_614 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 1 ] = 0 ;
V_9 -> V_143 . V_144 [ 2 ] = 0 ;
V_9 -> V_143 . V_144 [ 3 ] = 0 ;
V_9 -> V_143 . V_144 [ 4 ] = 0 ;
V_9 -> V_143 . V_144 [ 5 ] = 0 ;
V_9 -> V_143 . V_144 [ 6 ] = V_424 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_463 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_463 >> 8 ) & 0XFF ;
V_9 -> V_143 . V_144 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_211 , V_279 ) ;
F_175 () ;
return - 1 ;
}
} else if ( V_149 == V_392 ) {
switch ( V_279 ) {
case V_669 :
V_9 -> V_143 . V_340 = 16 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_615 ) ;
V_9 -> V_143 . V_610 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_773 ;
V_9 -> V_143 . V_144 [ 1 ] = V_774 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
case V_668 :
V_9 -> V_143 . V_340 = 16 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 , V_612 , V_615 ) ;
V_9 -> V_143 . V_610 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_279 ;
V_9 -> V_143 . V_144 [ 1 ] = V_775 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
case V_472 :
memcpy ( & V_343 , V_746 , sizeof( V_343 ) ) ;
F_274 ( & V_22 -> V_29 -> V_30 ,
L_212 ,
V_343 , V_9 -> V_123 . V_343 ) ;
V_9 -> V_143 . V_340 = 16 ;
V_9 -> V_143 . V_611 =
F_249 ( V_149 ,
V_612 , V_613 ) ;
V_9 -> V_143 . V_610 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_776 ;
V_9 -> V_143 . V_144 [ 1 ] = V_777 ;
V_9 -> V_143 . V_144 [ 2 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_143 . V_144 [ 4 ] , & V_343 , sizeof( V_343 ) ) ;
V_9 -> V_143 . V_144 [ 12 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 13 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 14 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_213 ,
V_279 ) ;
F_175 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_214 , V_149 ) ;
F_175 () ;
}
switch ( F_307 ( V_9 -> V_143 . V_611 ) ) {
case V_614 :
V_765 = V_390 ;
break;
case V_613 :
V_765 = V_266 ;
break;
case V_615 :
V_765 = V_370 ;
break;
default:
V_765 = V_750 ;
}
if ( F_155 ( V_22 -> V_29 , V_9 , V_746 , V_463 , V_765 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_308 ( T_16 V_778 , T_16 V_463 )
{
T_16 V_779 = ( ( T_16 ) V_778 ) & V_780 ;
T_16 V_781 = ( ( T_16 ) V_778 ) - V_779 ;
void T_15 * V_782 = F_309 ( V_779 ,
V_781 + V_463 ) ;
return V_782 ? ( V_782 + V_781 ) : NULL ;
}
static inline unsigned long F_310 ( struct V_1 * V_22 , T_1 V_109 )
{
return V_22 -> V_114 . V_115 ( V_22 , V_109 ) ;
}
static inline bool F_311 ( struct V_1 * V_22 )
{
return V_22 -> V_114 . V_783 ( V_22 ) ;
}
static inline long F_312 ( struct V_1 * V_22 )
{
return ( V_22 -> V_114 . V_783 ( V_22 ) == 0 ) ||
( V_22 -> V_784 == 0 ) ;
}
static inline int F_313 ( struct V_1 * V_22 , T_4 V_785 ,
T_4 V_786 )
{
if ( F_44 ( V_785 >= V_22 -> V_236 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_215 , V_786 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_61 ( struct V_8 * V_9 )
{
F_56 ( V_9 -> V_22 , V_9 ) ;
if ( F_47 ( V_9 -> V_149 == V_150 || V_9 -> V_149 == V_334
|| V_9 -> V_149 == V_153 ) )
F_150 ( V_9 ) ;
else if ( V_9 -> V_149 == V_395 || V_9 -> V_149 == V_155 )
F_314 ( V_9 -> V_374 ) ;
}
static inline void F_315 ( struct V_1 * V_22 ,
T_4 V_786 )
{
T_4 V_785 ;
struct V_8 * V_9 ;
V_785 = V_786 >> V_573 ;
if ( ! F_313 ( V_22 , V_785 , V_786 ) ) {
V_9 = V_22 -> V_399 + V_785 ;
F_61 ( V_9 ) ;
}
}
static int F_316 ( struct V_1 * V_22 )
{
if ( F_47 ( ! V_787 ) )
return 0 ;
if ( F_47 ( V_22 -> V_784 ) )
return 0 ;
F_94 ( & V_22 -> V_29 -> V_30 , L_216
L_217 ) ;
return 1 ;
}
static struct V_1 * F_317 ( T_1 * V_788 )
{
return F_254 ( ( V_788 - * V_788 ) , struct V_1 , V_109 [ 0 ] ) ;
}
static T_17 F_318 ( int V_649 , void * V_788 )
{
struct V_1 * V_22 = F_317 ( V_788 ) ;
T_1 V_109 = * ( T_1 * ) V_788 ;
T_4 V_786 ;
if ( F_316 ( V_22 ) )
return V_789 ;
if ( F_312 ( V_22 ) )
return V_789 ;
V_22 -> V_790 = F_319 () ;
while ( F_311 ( V_22 ) ) {
V_786 = F_310 ( V_22 , V_109 ) ;
while ( V_786 != V_119 )
V_786 = F_43 ( V_22 , V_109 ) ;
}
return V_791 ;
}
static T_17 F_320 ( int V_649 , void * V_788 )
{
struct V_1 * V_22 = F_317 ( V_788 ) ;
T_4 V_786 ;
T_1 V_109 = * ( T_1 * ) V_788 ;
if ( F_316 ( V_22 ) )
return V_789 ;
V_22 -> V_790 = F_319 () ;
V_786 = F_310 ( V_22 , V_109 ) ;
while ( V_786 != V_119 )
V_786 = F_43 ( V_22 , V_109 ) ;
return V_791 ;
}
static T_17 F_321 ( int V_649 , void * V_788 )
{
struct V_1 * V_22 = F_317 ( ( T_1 * ) V_788 ) ;
T_4 V_786 ;
T_1 V_109 = * ( T_1 * ) V_788 ;
if ( F_312 ( V_22 ) )
return V_789 ;
V_22 -> V_790 = F_319 () ;
while ( F_311 ( V_22 ) ) {
V_786 = F_310 ( V_22 , V_109 ) ;
while ( V_786 != V_119 ) {
F_315 ( V_22 , V_786 ) ;
V_786 = F_43 ( V_22 , V_109 ) ;
}
}
return V_791 ;
}
static T_17 F_322 ( int V_649 , void * V_788 )
{
struct V_1 * V_22 = F_317 ( V_788 ) ;
T_4 V_786 ;
T_1 V_109 = * ( T_1 * ) V_788 ;
V_22 -> V_790 = F_319 () ;
V_786 = F_310 ( V_22 , V_109 ) ;
while ( V_786 != V_119 ) {
F_315 ( V_22 , V_786 ) ;
V_786 = F_43 ( V_22 , V_109 ) ;
}
return V_791 ;
}
static int F_323 ( struct V_364 * V_29 , unsigned char V_792 ,
unsigned char type )
{
struct V_793 {
struct V_794 V_795 ;
struct V_796 V_143 ;
struct V_797 V_798 ;
};
struct V_793 * V_279 ;
static const T_3 V_799 = sizeof( * V_279 ) +
sizeof( V_279 -> V_798 ) ;
V_367 V_800 ;
T_7 V_801 ;
T_4 V_343 ;
void T_15 * V_151 ;
int V_68 , V_707 ;
V_151 = F_324 ( V_29 , 0 ) ;
if ( V_151 == NULL )
return - V_256 ;
V_707 = F_325 ( V_29 , F_326 ( 32 ) ) ;
if ( V_707 ) {
F_327 ( V_151 ) ;
return V_707 ;
}
V_279 = F_328 ( V_29 , V_799 , & V_800 ) ;
if ( V_279 == NULL ) {
F_327 ( V_151 ) ;
return - V_256 ;
}
V_801 = F_132 ( V_800 ) ;
V_279 -> V_795 . V_127 = 0 ;
V_279 -> V_795 . V_124 = 0 ;
V_279 -> V_795 . V_275 = F_153 ( 0 ) ;
V_279 -> V_795 . V_343 = F_127 ( V_800 ) ;
memset ( & V_279 -> V_795 . V_344 . V_345 , 0 , 8 ) ;
V_279 -> V_143 . V_340 = 16 ;
V_279 -> V_143 . V_611 =
F_249 ( V_392 , V_802 , V_615 ) ;
V_279 -> V_143 . V_610 = 0 ;
V_279 -> V_143 . V_144 [ 0 ] = V_792 ;
V_279 -> V_143 . V_144 [ 1 ] = type ;
memset ( & V_279 -> V_143 . V_144 [ 2 ] , 0 , 14 ) ;
V_279 -> V_798 . V_277 =
F_127 ( ( F_124 ( V_801 ) + sizeof( * V_279 ) ) ) ;
V_279 -> V_798 . V_276 = F_132 ( sizeof( struct V_331 ) ) ;
F_59 ( F_124 ( V_801 ) , V_151 + V_152 ) ;
for ( V_68 = 0 ; V_68 < V_803 ; V_68 ++ ) {
V_343 = F_329 ( V_151 + V_804 ) ;
if ( ( V_343 & ~ V_805 ) == V_800 )
break;
F_166 ( V_806 ) ;
}
F_327 ( V_151 ) ;
if ( V_68 == V_803 ) {
F_73 ( & V_29 -> V_30 , L_218 ,
V_792 , type ) ;
return - V_377 ;
}
F_330 ( V_29 , V_799 , V_279 , V_800 ) ;
if ( V_343 & V_807 ) {
F_73 ( & V_29 -> V_30 , L_219 ,
V_792 , type ) ;
return - V_382 ;
}
F_94 ( & V_29 -> V_30 , L_220 ,
V_792 , type ) ;
return 0 ;
}
static int F_331 ( struct V_364 * V_29 ,
void T_15 * V_151 , T_4 V_808 )
{
if ( V_808 ) {
F_94 ( & V_29 -> V_30 , L_221 ) ;
F_59 ( V_808 , V_151 + V_809 ) ;
F_166 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_94 ( & V_29 -> V_30 , L_222 ) ;
V_21 = F_332 ( V_29 , V_810 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
V_21 = F_332 ( V_29 , V_811 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
}
return 0 ;
}
static void F_333 ( char * V_812 , int V_50 )
{
memset ( V_812 , 0 , V_50 ) ;
strncpy ( V_812 , V_41 L_223 V_744 , V_50 - 1 ) ;
}
static int F_334 ( struct V_813 T_15 * V_814 )
{
char * V_812 ;
int V_68 , V_463 = sizeof( V_814 -> V_812 ) ;
V_812 = F_91 ( V_463 , V_202 ) ;
if ( ! V_812 )
return - V_256 ;
F_333 ( V_812 , V_463 ) ;
for ( V_68 = 0 ; V_68 < V_463 ; V_68 ++ )
F_335 ( V_812 [ V_68 ] , & V_814 -> V_812 [ V_68 ] ) ;
F_80 ( V_812 ) ;
return 0 ;
}
static void F_336 ( struct V_813 T_15 * V_814 ,
unsigned char * V_815 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_814 -> V_812 ) ; V_68 ++ )
V_815 [ V_68 ] = F_337 ( & V_814 -> V_812 [ V_68 ] ) ;
}
static int F_338 ( struct V_813 T_15 * V_814 )
{
char * V_815 , * V_816 ;
int V_21 , V_463 = sizeof( V_814 -> V_812 ) ;
V_816 = F_91 ( 2 * V_463 , V_202 ) ;
if ( ! V_816 )
return - V_256 ;
V_815 = V_816 + V_463 ;
F_333 ( V_816 , V_463 ) ;
F_336 ( V_814 , V_815 ) ;
V_21 = ! memcmp ( V_815 , V_816 , V_463 ) ;
F_80 ( V_816 ) ;
return V_21 ;
}
static int F_339 ( struct V_364 * V_29 , T_4 V_67 )
{
T_5 V_817 ;
T_4 V_818 ;
T_5 V_819 ;
void T_15 * V_151 ;
unsigned long V_820 ;
T_4 V_821 ;
int V_21 ;
struct V_813 T_15 * V_814 ;
T_4 V_808 ;
T_6 V_822 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_224 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_823 ;
F_340 ( V_29 , 4 , & V_822 ) ;
F_341 ( V_29 ) ;
V_21 = F_342 ( V_29 , & V_820 ) ;
if ( V_21 )
return V_21 ;
V_151 = F_308 ( V_820 , 0x250 ) ;
if ( ! V_151 )
return - V_256 ;
V_21 = F_343 ( V_29 , V_151 , & V_818 ,
& V_819 , & V_817 ) ;
if ( V_21 )
goto V_824;
V_814 = F_308 ( F_344 ( V_29 ,
V_819 ) + V_817 , sizeof( * V_814 ) ) ;
if ( ! V_814 ) {
V_21 = - V_256 ;
goto V_824;
}
V_21 = F_334 ( V_814 ) ;
if ( V_21 )
goto V_825;
V_821 = F_329 ( & V_814 -> V_821 ) ;
V_808 = V_821 & V_826 ;
if ( V_808 ) {
V_808 = V_827 ;
} else {
V_808 = V_821 & V_828 ;
if ( V_808 ) {
F_9 ( & V_29 -> V_30 ,
L_225 ) ;
V_21 = - V_823 ;
goto V_825;
}
}
V_21 = F_331 ( V_29 , V_151 , V_808 ) ;
if ( V_21 )
goto V_825;
F_345 ( V_29 ) ;
F_346 ( V_29 , 4 , V_822 ) ;
F_166 ( V_829 ) ;
V_21 = F_347 ( V_29 , V_151 , V_830 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_226 ) ;
goto V_825;
}
V_21 = F_338 ( V_151 ) ;
if ( V_21 < 0 )
goto V_825;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_227
L_228 ) ;
V_21 = - V_823 ;
} else {
F_94 ( & V_29 -> V_30 , L_229 ) ;
}
V_825:
F_327 ( V_814 ) ;
V_824:
F_327 ( V_151 ) ;
return V_21 ;
}
static void F_348 ( struct V_42 * V_30 , struct V_813 T_15 * V_831 )
{
#ifdef F_349
int V_68 ;
char V_832 [ 17 ] ;
F_94 ( V_30 , L_230 ) ;
F_94 ( V_30 , L_231 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_832 [ V_68 ] = F_337 ( & ( V_831 -> V_833 [ V_68 ] ) ) ;
V_832 [ 4 ] = '\0' ;
F_94 ( V_30 , L_232 , V_832 ) ;
F_94 ( V_30 , L_233 , F_329 ( & ( V_831 -> V_834 ) ) ) ;
F_94 ( V_30 , L_234 ,
F_329 ( & ( V_831 -> V_835 ) ) ) ;
F_94 ( V_30 , L_235 ,
F_329 ( & ( V_831 -> V_836 ) ) ) ;
F_94 ( V_30 , L_236 ,
F_329 ( & ( V_831 -> V_837 . V_838 ) ) ) ;
F_94 ( V_30 , L_237 ,
F_329 ( & ( V_831 -> V_837 . V_839 ) ) ) ;
F_94 ( V_30 , L_238 ,
F_329 ( & ( V_831 -> V_837 . V_840 ) ) ) ;
F_94 ( V_30 , L_239 ,
F_329 ( & ( V_831 -> V_841 ) ) ) ;
F_94 ( V_30 , L_240 , F_329 ( & ( V_831 -> V_842 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_832 [ V_68 ] = F_337 ( & ( V_831 -> V_843 [ V_68 ] ) ) ;
V_832 [ 16 ] = '\0' ;
F_94 ( V_30 , L_241 , V_832 ) ;
F_94 ( V_30 , L_242 ,
F_329 ( & ( V_831 -> V_844 ) ) ) ;
#endif
}
static int F_350 ( struct V_364 * V_29 , unsigned long V_845 )
{
int V_68 , V_701 , V_846 , V_847 ;
if ( V_845 == V_848 )
return 0 ;
V_701 = 0 ;
for ( V_68 = 0 ; V_68 < V_849 ; V_68 ++ ) {
V_847 = F_351 ( V_29 , V_68 ) & V_850 ;
if ( V_847 == V_851 )
V_701 += 4 ;
else {
V_846 = F_351 ( V_29 , V_68 ) &
V_852 ;
switch ( V_846 ) {
case V_853 :
case V_854 :
V_701 += 4 ;
break;
case V_855 :
V_701 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_243 ) ;
return - 1 ;
break;
}
}
if ( V_701 == V_845 - V_848 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_352 ( struct V_1 * V_22 )
{
if ( V_22 -> V_125 ) {
if ( V_22 -> V_29 -> V_856 )
F_353 ( V_22 -> V_29 ) ;
V_22 -> V_125 = 0 ;
} else if ( V_22 -> V_857 ) {
if ( V_22 -> V_29 -> V_858 )
F_354 ( V_22 -> V_29 ) ;
V_22 -> V_857 = 0 ;
}
}
static void F_355 ( struct V_1 * V_22 )
{
#ifdef F_356
int V_707 , V_68 ;
struct V_859 V_860 [ V_861 ] ;
for ( V_68 = 0 ; V_68 < V_861 ; V_68 ++ ) {
V_860 [ V_68 ] . V_862 = 0 ;
V_860 [ V_68 ] . V_183 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_863;
if ( F_357 ( V_22 -> V_29 , V_864 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_244 ) ;
V_22 -> V_125 = V_861 ;
if ( V_22 -> V_125 > F_358 () )
V_22 -> V_125 = F_358 () ;
V_707 = F_359 ( V_22 -> V_29 , V_860 ,
1 , V_22 -> V_125 ) ;
if ( V_707 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_245 , V_707 ) ;
V_22 -> V_125 = 0 ;
goto V_865;
} else if ( V_707 < V_22 -> V_125 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_246
L_247 , V_707 ) ;
}
V_22 -> V_125 = V_707 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ )
V_22 -> V_650 [ V_68 ] = V_860 [ V_68 ] . V_862 ;
return;
}
V_865:
if ( F_357 ( V_22 -> V_29 , V_866 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_248 ) ;
if ( ! F_360 ( V_22 -> V_29 ) )
V_22 -> V_857 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_249 ) ;
}
V_863:
#endif
V_22 -> V_650 [ V_22 -> V_651 ] = V_22 -> V_29 -> V_649 ;
}
static int F_361 ( struct V_364 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_867 , V_868 ;
V_867 = V_29 -> V_869 ;
V_868 = V_29 -> V_870 ;
* V_67 = ( ( V_868 << 16 ) & 0xffff0000 ) |
V_867 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_871 ) ; V_68 ++ )
if ( * V_67 == V_871 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_867 != V_872 &&
V_867 != V_873 ) ||
! V_874 ) {
F_9 ( & V_29 -> V_30 , L_250
L_251 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_871 ) - 1 ;
}
static int F_342 ( struct V_364 * V_29 ,
unsigned long * V_875 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_849 ; V_68 ++ )
if ( F_351 ( V_29 , V_68 ) & V_876 ) {
* V_875 = F_344 ( V_29 , V_68 ) ;
F_274 ( & V_29 -> V_30 , L_252 ,
* V_875 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_253 ) ;
return - V_81 ;
}
static int F_347 ( struct V_364 * V_29 , void T_15 * V_151 ,
int V_877 )
{
int V_68 , V_878 ;
T_4 V_879 ;
if ( V_877 )
V_878 = V_880 ;
else
V_878 = V_881 ;
for ( V_68 = 0 ; V_68 < V_878 ; V_68 ++ ) {
V_879 = F_329 ( V_151 + V_882 ) ;
if ( V_877 ) {
if ( V_879 == V_883 )
return 0 ;
} else {
if ( V_879 != V_883 )
return 0 ;
}
F_166 ( V_884 ) ;
}
F_9 ( & V_29 -> V_30 , L_254 ) ;
return - V_81 ;
}
static int F_343 ( struct V_364 * V_29 , void T_15 * V_151 ,
T_4 * V_818 , T_5 * V_819 ,
T_5 * V_817 )
{
* V_818 = F_329 ( V_151 + V_885 ) ;
* V_817 = F_329 ( V_151 + V_886 ) ;
* V_818 &= ( T_4 ) 0x0000ffff ;
* V_819 = F_350 ( V_29 , * V_818 ) ;
if ( * V_819 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_255 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_362 ( struct V_1 * V_22 )
{
if ( V_22 -> V_887 ) {
F_327 ( V_22 -> V_887 ) ;
V_22 -> V_887 = NULL ;
}
if ( V_22 -> V_814 ) {
F_327 ( V_22 -> V_814 ) ;
V_22 -> V_814 = NULL ;
}
}
static int F_363 ( struct V_1 * V_22 )
{
T_5 V_817 ;
T_4 V_818 ;
T_5 V_819 ;
T_4 V_888 ;
int V_21 ;
V_21 = F_343 ( V_22 -> V_29 , V_22 -> V_151 , & V_818 ,
& V_819 , & V_817 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_814 = F_308 ( F_344 ( V_22 -> V_29 ,
V_819 ) + V_817 , sizeof( * V_22 -> V_814 ) ) ;
if ( ! V_22 -> V_814 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_256 ) ;
return - V_256 ;
}
V_21 = F_334 ( V_22 -> V_814 ) ;
if ( V_21 )
return V_21 ;
V_888 = F_329 ( & V_22 -> V_814 -> V_889 ) ;
V_22 -> V_887 = F_308 ( F_344 ( V_22 -> V_29 ,
V_819 ) + V_817 + V_888 ,
sizeof( * V_22 -> V_887 ) ) ;
if ( ! V_22 -> V_887 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_257 ) ;
F_362 ( V_22 ) ;
return - V_256 ;
}
return 0 ;
}
static void F_364 ( struct V_1 * V_22 )
{
#define F_365 16
F_276 ( F_365 <= V_644 ) ;
V_22 -> V_120 = F_329 ( & V_22 -> V_814 -> V_890 ) ;
if ( V_787 && V_22 -> V_120 > 32 )
V_22 -> V_120 = 32 ;
if ( V_22 -> V_120 < F_365 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_258 ,
V_22 -> V_120 ,
F_365 ) ;
V_22 -> V_120 = F_365 ;
}
}
static int F_366 ( struct V_1 * V_22 )
{
return V_22 -> V_257 > 512 ;
}
static void F_367 ( struct V_1 * V_22 )
{
F_364 ( V_22 ) ;
V_22 -> V_236 = V_22 -> V_120 ;
V_22 -> V_257 = F_329 ( & ( V_22 -> V_814 -> V_891 ) ) ;
V_22 -> V_477 = F_329 ( & ( V_22 -> V_814 -> V_821 ) ) ;
if ( F_366 ( V_22 ) ) {
V_22 -> V_272 = 32 ;
V_22 -> V_255 = V_22 -> V_257 - V_22 -> V_272 ;
V_22 -> V_257 -- ;
} else {
V_22 -> V_272 = 31 ;
V_22 -> V_257 = 31 ;
V_22 -> V_255 = 0 ;
}
V_22 -> V_690 = F_329 ( & ( V_22 -> V_814 -> V_690 ) ) ;
if ( ! ( V_696 & V_22 -> V_690 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
if ( ! ( V_697 & V_22 -> V_690 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
if ( ! ( V_689 & V_22 -> V_690 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_261 ) ;
}
static inline bool F_368 ( struct V_1 * V_22 )
{
if ( ! F_369 ( V_22 -> V_814 -> V_833 , L_262 , 4 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
return false ;
}
return true ;
}
static inline void F_370 ( struct V_1 * V_22 )
{
T_4 V_892 ;
V_892 = F_329 ( & ( V_22 -> V_814 -> V_892 ) ) ;
#ifdef F_371
V_892 |= V_893 ;
#endif
V_892 |= V_894 ;
F_59 ( V_892 , & ( V_22 -> V_814 -> V_892 ) ) ;
}
static inline void F_372 ( struct V_1 * V_22 )
{
T_4 V_895 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_895 = F_329 ( V_22 -> V_151 + V_896 ) ;
V_895 |= 0x8000 ;
F_59 ( V_895 , V_22 -> V_151 + V_896 ) ;
}
static int F_373 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_897 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_898 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_897 = F_329 ( V_22 -> V_151 + V_809 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_897 & V_899 ) )
goto V_900;
F_166 ( V_901 ) ;
}
return - V_81 ;
V_900:
return 0 ;
}
static int F_374 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_897 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_902 ; V_68 ++ ) {
if ( V_22 -> V_903 )
goto V_900;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_897 = F_329 ( V_22 -> V_151 + V_809 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_897 & V_904 ) )
goto V_900;
F_166 ( V_905 ) ;
}
return - V_81 ;
V_900:
return 0 ;
}
static int F_375 ( struct V_1 * V_22 )
{
T_4 V_906 ;
V_906 = F_329 ( & ( V_22 -> V_814 -> V_835 ) ) ;
if ( ! ( V_906 & V_907 ) )
return - V_823 ;
V_22 -> V_120 = F_329 ( & ( V_22 -> V_814 -> V_841 ) ) ;
F_59 ( V_908 , & ( V_22 -> V_814 -> V_837 . V_838 ) ) ;
F_59 ( 0 , & V_22 -> V_814 -> V_837 . V_909 ) ;
F_59 ( V_904 , V_22 -> V_151 + V_809 ) ;
if ( F_374 ( V_22 ) )
goto error;
F_348 ( & V_22 -> V_29 -> V_30 , V_22 -> V_814 ) ;
if ( ! ( F_329 ( & ( V_22 -> V_814 -> V_836 ) ) & V_908 ) )
goto error;
V_22 -> V_63 = V_908 ;
return 0 ;
error:
F_73 ( & V_22 -> V_29 -> V_30 , L_264 ) ;
return - V_81 ;
}
static void F_376 ( struct V_1 * V_22 )
{
F_362 ( V_22 ) ;
F_327 ( V_22 -> V_151 ) ;
V_22 -> V_151 = NULL ;
F_352 ( V_22 ) ;
F_377 ( V_22 -> V_29 ) ;
F_378 ( V_22 -> V_29 ) ;
}
static int F_379 ( struct V_1 * V_22 )
{
int V_910 , V_707 ;
V_910 = F_361 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_910 < 0 )
return V_910 ;
V_22 -> V_911 = V_871 [ V_910 ] . V_911 ;
V_22 -> V_114 = * ( V_871 [ V_910 ] . V_114 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_380 ( V_22 -> V_29 , V_912 |
V_913 | V_914 ) ;
V_707 = F_381 ( V_22 -> V_29 ) ;
if ( V_707 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_265 ) ;
F_377 ( V_22 -> V_29 ) ;
return V_707 ;
}
V_707 = F_382 ( V_22 -> V_29 , V_41 ) ;
if ( V_707 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_266 ) ;
F_377 ( V_22 -> V_29 ) ;
return V_707 ;
}
F_383 ( V_22 -> V_29 ) ;
F_355 ( V_22 ) ;
V_707 = F_342 ( V_22 -> V_29 , & V_22 -> V_820 ) ;
if ( V_707 )
goto V_915;
V_22 -> V_151 = F_308 ( V_22 -> V_820 , 0x250 ) ;
if ( ! V_22 -> V_151 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
V_707 = - V_256 ;
goto V_915;
}
V_707 = F_347 ( V_22 -> V_29 , V_22 -> V_151 , V_830 ) ;
if ( V_707 )
goto V_916;
V_707 = F_363 ( V_22 ) ;
if ( V_707 )
goto V_916;
F_367 ( V_22 ) ;
if ( ! F_368 ( V_22 ) ) {
V_707 = - V_81 ;
goto V_917;
}
F_370 ( V_22 ) ;
F_372 ( V_22 ) ;
V_707 = F_375 ( V_22 ) ;
if ( V_707 )
goto V_917;
return 0 ;
V_917:
F_362 ( V_22 ) ;
V_916:
F_327 ( V_22 -> V_151 ) ;
V_22 -> V_151 = NULL ;
V_915:
F_352 ( V_22 ) ;
F_377 ( V_22 -> V_29 ) ;
F_378 ( V_22 -> V_29 ) ;
return V_707 ;
}
static void F_384 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_385 64
V_22 -> V_61 = F_91 ( F_385 , V_202 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_169 ( V_22 , V_157 , 0 ,
V_22 -> V_61 , F_385 ) ;
if ( V_21 != 0 ) {
F_80 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_386 ( struct V_364 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_151 ;
if ( ! V_787 )
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
V_151 = F_324 ( V_29 , 0 ) ;
if ( V_151 == NULL ) {
V_21 = - V_256 ;
goto V_918;
}
F_59 ( V_919 , V_151 + V_920 ) ;
F_327 ( V_151 ) ;
V_21 = F_339 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_918;
F_94 ( & V_29 -> V_30 , L_270 ) ;
for ( V_68 = 0 ; V_68 < V_921 ; V_68 ++ ) {
if ( F_387 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_271 ,
( V_68 < 11 ? L_272 : L_273 ) ) ;
}
V_918:
F_377 ( V_29 ) ;
return V_21 ;
}
static void F_388 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_702 ) ;
V_22 -> V_702 = NULL ;
if ( V_22 -> V_399 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( struct V_8 ) ,
V_22 -> V_399 ,
V_22 -> V_621 ) ;
V_22 -> V_399 = NULL ;
V_22 -> V_621 = 0 ;
}
if ( V_22 -> V_622 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( struct V_331 ) ,
V_22 -> V_622 ,
V_22 -> V_623 ) ;
V_22 -> V_622 = NULL ;
V_22 -> V_623 = 0 ;
}
}
static int F_389 ( struct V_1 * V_22 )
{
V_22 -> V_702 = F_108 (
F_390 ( V_22 -> V_236 , V_602 ) *
sizeof( unsigned long ) , V_202 ) ;
V_22 -> V_399 = F_328 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_399 ) ,
& ( V_22 -> V_621 ) ) ;
V_22 -> V_622 = F_328 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_622 ) ,
& ( V_22 -> V_623 ) ) ;
if ( ( V_22 -> V_702 == NULL )
|| ( V_22 -> V_399 == NULL )
|| ( V_22 -> V_622 == NULL ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_274 , V_203 ) ;
goto V_922;
}
F_251 ( V_22 ) ;
return 0 ;
V_922:
F_388 ( V_22 ) ;
return - V_256 ;
}
static void F_391 ( struct V_1 * V_22 )
{
int V_68 , V_378 ;
V_378 = F_392 ( V_923 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
F_393 ( V_22 -> V_650 [ V_68 ] , F_394 ( V_378 ) ) ;
V_378 = F_395 ( V_378 , V_923 ) ;
}
}
static void F_396 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_125 || V_22 -> V_651 != V_924 ) {
V_68 = V_22 -> V_651 ;
F_393 ( V_22 -> V_650 [ V_68 ] , NULL ) ;
F_397 ( V_22 -> V_650 [ V_68 ] , & V_22 -> V_109 [ V_68 ] ) ;
V_22 -> V_109 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
F_393 ( V_22 -> V_650 [ V_68 ] , NULL ) ;
F_397 ( V_22 -> V_650 [ V_68 ] , & V_22 -> V_109 [ V_68 ] ) ;
V_22 -> V_109 [ V_68 ] = 0 ;
}
for (; V_68 < V_861 ; V_68 ++ )
V_22 -> V_109 [ V_68 ] = 0 ;
}
static int F_398 ( struct V_1 * V_22 ,
T_17 (* F_399)( int , void * ) ,
T_17 (* F_400)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_861 ; V_68 ++ )
V_22 -> V_109 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_651 == V_924 && V_22 -> V_125 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
sprintf ( V_22 -> V_925 [ V_68 ] , L_275 , V_22 -> V_31 , V_68 ) ;
V_21 = F_401 ( V_22 -> V_650 [ V_68 ] , F_399 ,
0 , V_22 -> V_925 [ V_68 ] ,
& V_22 -> V_109 [ V_68 ] ) ;
if ( V_21 ) {
int V_192 ;
F_73 ( & V_22 -> V_29 -> V_30 ,
L_276 ,
V_22 -> V_650 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_192 = 0 ; V_192 < V_68 ; V_192 ++ ) {
F_397 ( V_22 -> V_650 [ V_192 ] , & V_22 -> V_109 [ V_192 ] ) ;
V_22 -> V_109 [ V_192 ] = 0 ;
}
for (; V_192 < V_861 ; V_192 ++ )
V_22 -> V_109 [ V_192 ] = 0 ;
return V_21 ;
}
}
F_391 ( V_22 ) ;
} else {
if ( V_22 -> V_125 > 0 || V_22 -> V_857 ) {
if ( V_22 -> V_125 )
sprintf ( V_22 -> V_925 [ V_22 -> V_651 ] ,
L_277 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_925 [ V_22 -> V_651 ] ,
L_278 , V_22 -> V_31 ) ;
V_21 = F_401 ( V_22 -> V_650 [ V_22 -> V_651 ] ,
F_399 , 0 ,
V_22 -> V_925 [ V_22 -> V_651 ] ,
& V_22 -> V_109 [ V_22 -> V_651 ] ) ;
} else {
sprintf ( V_22 -> V_925 [ V_22 -> V_651 ] ,
L_279 , V_22 -> V_31 ) ;
V_21 = F_401 ( V_22 -> V_650 [ V_22 -> V_651 ] ,
F_400 , V_926 ,
V_22 -> V_925 [ V_22 -> V_651 ] ,
& V_22 -> V_109 [ V_22 -> V_651 ] ) ;
}
F_393 ( V_22 -> V_650 [ V_22 -> V_651 ] , NULL ) ;
}
if ( V_21 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_276 ,
V_22 -> V_650 [ V_22 -> V_651 ] , V_22 -> V_31 ) ;
F_396 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_402 ( struct V_1 * V_22 )
{
int V_21 ;
F_306 ( V_22 , V_157 , V_927 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_280 ) ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_151 , V_928 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_281 ) ;
return V_21 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_282 ) ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_151 , V_830 ) ;
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
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
if ( ! V_22 -> V_112 [ V_68 ] . V_116 )
continue;
F_330 ( V_22 -> V_29 ,
V_22 -> V_929 ,
V_22 -> V_112 [ V_68 ] . V_116 ,
V_22 -> V_112 [ V_68 ] . V_121 ) ;
V_22 -> V_112 [ V_68 ] . V_116 = NULL ;
V_22 -> V_112 [ V_68 ] . V_121 = 0 ;
}
V_22 -> V_929 = 0 ;
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
if ( V_22 -> V_321 ) {
F_408 ( V_22 -> V_321 ) ;
V_22 -> V_321 = NULL ;
}
if ( V_22 -> V_930 ) {
F_408 ( V_22 -> V_930 ) ;
V_22 -> V_930 = NULL ;
}
F_80 ( V_22 ) ;
}
static void F_409 ( struct V_1 * V_22 )
{
int V_68 , V_400 ;
struct V_8 * V_9 ;
int V_931 = 0 ;
F_410 ( V_22 -> V_321 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
V_9 = V_22 -> V_399 + V_68 ;
V_400 = F_178 ( & V_9 -> V_400 ) ;
if ( V_400 > 1 ) {
V_9 -> V_24 -> V_36 = V_337 ;
F_61 ( V_9 ) ;
F_45 ( & V_22 -> V_62 ) ;
V_931 ++ ;
}
F_172 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_285 , V_931 ) ;
}
static void F_411 ( struct V_1 * V_22 , T_4 V_932 )
{
int V_378 ;
F_412 (cpu) {
T_4 * F_13 ;
F_13 = F_163 ( V_22 -> F_13 , V_378 ) ;
* F_13 = V_932 ;
}
F_76 () ;
}
static void F_413 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_329 ( V_22 -> V_151 + V_882 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_286 ,
V_22 -> V_146 / V_935 ) ;
F_13 = 0xffffffff ;
}
F_411 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_287 ,
F_13 , V_22 -> V_146 / V_935 ) ;
F_377 ( V_22 -> V_29 ) ;
F_409 ( V_22 ) ;
}
static int F_270 ( struct V_1 * V_22 )
{
T_5 V_936 ;
T_4 V_937 ;
unsigned long V_78 ;
V_936 = F_319 () ;
if ( F_414 ( V_22 -> V_790 +
( V_22 -> V_146 ) , V_936 ) )
return false ;
if ( F_414 ( V_22 -> V_938 +
( V_22 -> V_146 ) , V_936 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_937 = F_329 ( & V_22 -> V_814 -> V_844 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_939 == V_937 ) {
F_413 ( V_22 ) ;
return true ;
}
V_22 -> V_939 = V_937 ;
V_22 -> V_938 = V_936 ;
return false ;
}
static void F_415 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_940 ;
if ( ! ( V_22 -> V_477 & V_941 ) )
return;
if ( ( V_22 -> V_63 & ( V_113
| V_942 ) ) &&
( V_22 -> V_943 & V_944 ||
V_22 -> V_943 & V_945 ) ) {
if ( V_22 -> V_943 & V_944 )
V_940 = L_288 ;
if ( V_22 -> V_943 & V_945 )
V_940 = L_289 ;
F_416 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_89 = 0 ;
F_417 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_290 ,
V_22 -> V_943 , V_940 ) ;
F_59 ( V_22 -> V_943 , & ( V_22 -> V_814 -> V_946 ) ) ;
F_59 ( V_899 , V_22 -> V_151 + V_809 ) ;
F_373 ( V_22 ) ;
F_418 ( V_22 -> V_59 ) ;
} else {
F_59 ( V_22 -> V_943 , & ( V_22 -> V_814 -> V_946 ) ) ;
F_59 ( V_899 , V_22 -> V_151 + V_809 ) ;
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
if ( V_22 -> V_244 ) {
V_22 -> V_244 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_477 & V_941 ) )
return 0 ;
V_22 -> V_943 = F_329 ( & ( V_22 -> V_814 -> V_947 ) ) ;
return V_22 -> V_943 & V_948 ;
}
static int F_420 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_200 * V_384 ;
struct V_949 * V_950 , * V_951 ;
F_35 ( & V_22 -> V_201 , V_78 ) ;
F_421 (this, tmp, &h->offline_device_list) {
V_384 = F_422 ( V_950 , struct V_200 ,
V_204 ) ;
F_36 ( & V_22 -> V_201 , V_78 ) ;
if ( ! F_205 ( V_22 , V_384 -> V_72 ) ) {
F_35 ( & V_22 -> V_201 , V_78 ) ;
F_423 ( & V_384 -> V_204 ) ;
F_36 ( & V_22 -> V_201 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_201 , V_78 ) ;
}
F_36 ( & V_22 -> V_201 , V_78 ) ;
return 0 ;
}
static int F_424 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_459 * V_489 = NULL ;
if ( ! V_22 -> V_952 )
goto V_389;
V_489 = F_108 ( sizeof( * V_489 ) , V_202 ) ;
if ( ! V_489 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_291 ) ;
goto V_389;
}
if ( F_201 ( V_22 , 1 , V_489 , sizeof( * V_489 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_292 ) ;
goto V_389;
}
if ( memcmp ( V_489 , V_22 -> V_952 , sizeof( * V_489 ) ) ) {
F_94 ( & V_22 -> V_29 -> V_30 ,
L_293 ) ;
memcpy ( V_22 -> V_952 , V_489 , sizeof( * V_489 ) ) ;
goto V_389;
} else
V_21 = 0 ;
V_389:
F_80 ( V_489 ) ;
return V_21 ;
}
static void F_425 ( struct V_625 * V_319 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_254 ( F_426 ( V_319 ) ,
struct V_1 , V_953 ) ;
if ( V_22 -> V_903 )
return;
if ( F_419 ( V_22 ) || F_420 ( V_22 ) ) {
F_427 ( V_22 -> V_59 ) ;
F_415 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_406 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_518 ) {
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
if ( ! V_22 -> V_903 )
F_429 ( V_22 -> V_930 , & V_22 -> V_953 ,
V_22 -> V_146 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_430 ( struct V_625 * V_319 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_254 ( F_426 ( V_319 ) ,
struct V_1 , V_954 ) ;
F_270 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_903 )
F_431 ( & V_22 -> V_954 ,
V_22 -> V_146 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_955 * F_432 ( struct V_1 * V_22 ,
char * V_956 )
{
struct V_955 * V_957 = NULL ;
V_957 = F_433 ( L_295 , 0 , V_956 , V_22 -> V_958 ) ;
if ( ! V_957 )
F_73 ( & V_22 -> V_29 -> V_30 , L_296 , V_956 ) ;
return V_957 ;
}
static int F_434 ( struct V_364 * V_29 , const struct V_959 * V_960 )
{
int V_961 , V_21 ;
struct V_1 * V_22 ;
int V_962 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_963 == 0 )
F_435 (KERN_INFO DRIVER_NAME L_297 ) ;
V_21 = F_361 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_298 ) ;
return V_21 ;
}
V_21 = F_386 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_823 )
return V_21 ;
V_962 = 1 ;
V_21 = 0 ;
}
V_964:
F_276 ( sizeof( struct V_8 ) % V_965 ) ;
V_22 = F_108 ( sizeof( * V_22 ) , V_202 ) ;
if ( ! V_22 ) {
F_73 ( & V_29 -> V_30 , L_299 ) ;
return - V_256 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_651 = V_966 ? V_967 : V_924 ;
F_436 ( & V_22 -> V_205 ) ;
F_437 ( & V_22 -> V_79 ) ;
F_437 ( & V_22 -> V_201 ) ;
F_437 ( & V_22 -> V_630 ) ;
F_115 ( & V_22 -> V_761 , V_968 ) ;
F_115 ( & V_22 -> V_692 , V_969 ) ;
V_22 -> F_13 = F_438 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_300 ) ;
V_21 = - V_256 ;
goto V_970;
}
F_411 ( V_22 , 0 ) ;
V_21 = F_379 ( V_22 ) ;
if ( V_21 )
goto V_915;
V_21 = F_260 ( V_22 ) ;
if ( V_21 )
goto V_971;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_100 ) ;
V_22 -> V_958 = V_963 ;
V_963 ++ ;
V_21 = F_439 ( V_29 , F_326 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_961 = 1 ;
} else {
V_21 = F_439 ( V_29 , F_326 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_961 = 0 ;
} else {
F_73 ( & V_29 -> V_30 , L_301 ) ;
goto V_916;
}
}
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
V_21 = F_398 ( V_22 , F_322 , F_321 ) ;
if ( V_21 )
goto V_916;
V_21 = F_389 ( V_22 ) ;
if ( V_21 )
goto V_917;
V_21 = F_122 ( V_22 ) ;
if ( V_21 )
goto V_972;
F_440 ( & V_22 -> V_632 ) ;
F_440 ( & V_22 -> V_691 ) ;
F_440 ( & V_22 -> V_317 ) ;
F_441 ( & V_22 -> V_397 ) ;
V_22 -> V_631 = 1 ;
F_442 ( V_29 , V_22 ) ;
V_22 -> V_161 = 0 ;
F_437 ( & V_22 -> V_96 ) ;
V_21 = F_443 ( V_22 ) ;
if ( V_21 )
goto V_973;
V_21 = F_262 ( V_22 ) ;
if ( V_21 )
goto V_974;
V_22 -> V_930 = F_432 ( V_22 , L_302 ) ;
if ( ! V_22 -> V_930 ) {
V_21 = - V_256 ;
goto V_974;
}
V_22 -> V_321 = F_432 ( V_22 , L_303 ) ;
if ( ! V_22 -> V_321 ) {
V_21 = - V_256 ;
goto V_974;
}
if ( V_962 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
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
goto V_916;
}
V_21 = F_402 ( V_22 ) ;
if ( V_21 )
goto V_974;
F_94 ( & V_22 -> V_29 -> V_30 , L_305 ) ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_306 ) ;
V_22 -> V_114 . V_933 ( V_22 , V_975 ) ;
F_166 ( 10000 ) ;
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
V_21 = F_338 ( V_22 -> V_814 ) ;
if ( V_21 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_307 ) ;
F_404 ( V_22 ) ;
V_962 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_964;
}
V_22 -> V_56 = 1 ;
V_22 -> V_518 = 0 ;
V_22 -> V_114 . V_933 ( V_22 , V_975 ) ;
F_384 ( V_22 ) ;
V_22 -> V_952 = F_108 ( sizeof( * ( V_22 -> V_952 ) ) , V_202 ) ;
if ( ! V_22 -> V_952 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_308 ) ;
V_22 -> V_146 = V_148 ;
F_444 ( & V_22 -> V_954 , F_430 ) ;
F_431 ( & V_22 -> V_954 ,
V_22 -> V_146 ) ;
F_444 ( & V_22 -> V_953 , F_425 ) ;
F_429 ( V_22 -> V_930 , & V_22 -> V_953 ,
V_22 -> V_146 ) ;
return 0 ;
V_974:
F_405 ( V_22 ) ;
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
V_973:
F_121 ( V_22 ) ;
V_972:
F_388 ( V_22 ) ;
V_917:
F_396 ( V_22 ) ;
V_916:
F_406 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_971:
F_376 ( V_22 ) ;
V_915:
if ( V_22 -> F_13 ) {
F_407 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_970:
if ( V_22 -> V_321 ) {
F_408 ( V_22 -> V_321 ) ;
V_22 -> V_321 = NULL ;
}
if ( V_22 -> V_930 ) {
F_408 ( V_22 -> V_930 ) ;
V_22 -> V_930 = NULL ;
}
F_80 ( V_22 ) ;
return V_21 ;
}
static void F_445 ( struct V_1 * V_22 )
{
char * V_976 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return;
V_976 = F_108 ( 4 , V_202 ) ;
if ( ! V_976 )
return;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_769 , V_22 , V_976 , 4 , 0 ,
V_157 , V_388 ) ) {
goto V_389;
}
V_21 = F_165 ( V_22 , V_9 ,
V_266 , V_375 ) ;
if ( V_21 )
goto V_389;
if ( V_9 -> V_24 -> V_36 != 0 )
V_389:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_309 ) ;
F_172 ( V_22 , V_9 ) ;
F_80 ( V_976 ) ;
}
static void F_428 ( struct V_1 * V_22 )
{
T_4 * V_977 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( V_22 -> F_13 ) )
return;
V_977 = F_108 ( sizeof( * V_977 ) , V_202 ) ;
if ( ! V_977 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_310 ) ;
return;
}
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_766 , V_22 , V_977 , 4 , 0 ,
V_157 , V_388 ) )
goto V_978;
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_978;
* V_977 |= V_979 ;
if ( F_171 ( V_9 , V_768 , V_22 , V_977 , 4 , 0 ,
V_157 , V_388 ) )
goto V_978;
V_21 = F_165 ( V_22 , V_9 ,
V_266 , V_375 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_978;
if ( F_171 ( V_9 , V_766 , V_22 , V_977 , 4 , 0 ,
V_157 , V_388 ) )
goto V_978;
V_21 = F_165 ( V_22 , V_9 ,
V_390 , V_375 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_978;
if ( * V_977 & V_979 )
goto V_389;
V_978:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
V_389:
F_172 ( V_22 , V_9 ) ;
F_80 ( V_977 ) ;
}
static void F_446 ( struct V_364 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_447 ( V_29 ) ;
F_445 ( V_22 ) ;
V_22 -> V_114 . V_933 ( V_22 , V_934 ) ;
F_396 ( V_22 ) ;
F_352 ( V_22 ) ;
}
static void F_448 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
F_80 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_449 ( struct V_364 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_447 ( V_29 ) == NULL ) {
F_73 ( & V_29 -> V_30 , L_312 ) ;
return;
}
V_22 = F_447 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_903 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_450 ( & V_22 -> V_954 ) ;
F_450 ( & V_22 -> V_953 ) ;
F_408 ( V_22 -> V_930 ) ;
F_408 ( V_22 -> V_321 ) ;
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
F_80 ( V_22 -> V_952 ) ;
F_406 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_376 ( V_22 ) ;
F_407 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_452 ( V_22 ) ;
F_80 ( V_22 ) ;
}
static void F_453 ( int V_980 [] , int V_981 ,
int V_982 , int V_983 , T_4 * V_984 )
{
int V_68 , V_192 , V_985 , V_463 ;
for ( V_68 = 0 ; V_68 <= V_982 ; V_68 ++ ) {
V_463 = V_68 + V_983 ;
V_985 = V_981 ;
for ( V_192 = 0 ; V_192 < V_981 ; V_192 ++ ) {
if ( V_980 [ V_192 ] >= V_463 ) {
V_985 = V_192 ;
break;
}
}
V_984 [ V_68 ] = V_985 ;
}
}
static int F_454 ( struct V_1 * V_22 , T_4 V_906 )
{
int V_68 ;
unsigned long V_986 ;
unsigned long V_63 = V_64 |
( V_906 & V_987 ) |
V_988 |
( V_906 & ( V_113 |
V_942 ) ) ;
struct V_989 V_114 = V_990 ;
int V_991 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_758 + 4 } ;
#define F_455 5
#define F_456 4
int V_992 [ 16 ] = { F_455 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_456 + V_993 } ;
F_276 ( F_26 ( V_992 ) != 16 ) ;
F_276 ( F_26 ( V_991 ) != 8 ) ;
F_276 ( F_244 ( struct V_138 , V_264 ) >
16 * F_455 ) ;
F_276 ( sizeof( struct V_260 ) != 16 ) ;
F_276 ( 28 > V_758 + 4 ) ;
if ( V_906 & ( V_113 | V_942 ) )
V_114 = V_994 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ )
memset ( V_22 -> V_112 [ V_68 ] . V_116 , 0 , V_22 -> V_929 ) ;
V_991 [ 7 ] = V_758 + 4 ;
F_453 ( V_991 , F_26 ( V_991 ) ,
V_758 , 4 , V_22 -> V_122 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_59 ( V_991 [ V_68 ] , & V_22 -> V_887 -> V_995 [ V_68 ] ) ;
F_59 ( V_22 -> V_120 , & V_22 -> V_887 -> V_996 ) ;
F_59 ( V_22 -> V_128 , & V_22 -> V_887 -> V_997 ) ;
F_59 ( 0 , & V_22 -> V_887 -> V_998 ) ;
F_59 ( 0 , & V_22 -> V_887 -> V_999 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
F_59 ( 0 , & V_22 -> V_887 -> V_1000 [ V_68 ] . V_1001 ) ;
F_59 ( V_22 -> V_112 [ V_68 ] . V_121 ,
& V_22 -> V_887 -> V_1000 [ V_68 ] . V_1002 ) ;
}
F_59 ( 0 , & V_22 -> V_814 -> V_837 . V_909 ) ;
F_59 ( V_63 , & ( V_22 -> V_814 -> V_837 . V_838 ) ) ;
if ( V_906 & V_113 ) {
V_114 = V_1003 ;
F_59 ( 10 , & V_22 -> V_814 -> V_837 . V_839 ) ;
F_59 ( 4 , & V_22 -> V_814 -> V_837 . V_840 ) ;
} else {
if ( V_906 & V_942 ) {
V_114 = V_1004 ;
F_59 ( 10 , & V_22 -> V_814 -> V_837 . V_839 ) ;
F_59 ( 4 , & V_22 -> V_814 -> V_837 . V_840 ) ;
}
}
F_59 ( V_904 , V_22 -> V_151 + V_809 ) ;
if ( F_374 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_313 ) ;
return - V_81 ;
}
V_986 = F_329 ( & ( V_22 -> V_814 -> V_836 ) ) ;
if ( ! ( V_986 & V_64 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_314 ) ;
return - V_81 ;
}
V_22 -> V_114 = V_114 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_906 & V_113 ) ||
( V_906 & V_942 ) ) )
return 0 ;
if ( V_906 & V_113 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
F_59 ( V_68 , V_22 -> V_151 + V_1005 ) ;
V_22 -> V_112 [ V_68 ] . V_117 =
F_329 ( V_22 -> V_151 + V_1006 ) ;
}
V_991 [ 7 ] = V_22 -> V_542 + 8 ;
F_453 ( V_991 , F_26 ( V_991 ) , V_22 -> V_542 , 8 ,
V_22 -> V_133 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ )
memset ( V_22 -> V_112 [ V_68 ] . V_116 ,
( T_1 ) V_1007 ,
V_22 -> V_929 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
struct V_129 * V_130 = & V_22 -> V_131 [ V_68 ] ;
V_130 -> V_1008 = V_1009 ;
V_130 -> V_24 = ( T_4 ) ( V_22 -> V_623 +
( V_68 * sizeof( struct V_331 ) ) ) ;
V_130 -> V_1010 = sizeof( struct V_331 ) ;
V_130 -> V_1011 = V_1012 ;
V_130 -> V_1013 =
F_153 ( V_1014 ) ;
V_130 -> V_1015 = 0 ;
V_130 -> V_127 = 0 ;
V_130 -> V_343 =
F_127 ( ( V_68 << V_573 ) ) ;
V_130 -> V_1016 =
F_127 ( V_22 -> V_545 +
( V_68 * sizeof( struct V_129 ) ) ) ;
}
} else if ( V_906 & V_942 ) {
T_5 V_817 , V_819 ;
T_4 V_1017 , V_818 ;
int V_21 ;
V_21 = F_343 ( V_22 -> V_29 , V_22 -> V_151 , & V_818 ,
& V_819 , & V_817 ) ;
F_276 ( F_244 ( struct V_138 , V_264 ) != 64 ) ;
V_992 [ 15 ] = V_22 -> V_542 + F_456 ;
F_453 ( V_992 , F_26 ( V_992 ) , V_22 -> V_542 ,
4 , V_22 -> V_137 ) ;
V_1017 = F_329 ( & V_22 -> V_814 -> V_1018 ) ;
F_276 ( F_244 ( struct V_813 ,
V_1018 ) != 0xb8 ) ;
V_22 -> V_1019 =
F_308 ( F_344 ( V_22 -> V_29 ,
V_819 ) +
V_817 + V_1017 ,
F_26 ( V_992 ) *
sizeof( * V_22 -> V_1019 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_992 ) ; V_68 ++ )
F_59 ( V_992 [ V_68 ] , & V_22 -> V_1019 [ V_68 ] ) ;
}
F_59 ( V_904 , V_22 -> V_151 + V_809 ) ;
if ( F_374 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_315 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_457 ( struct V_1 * V_22 )
{
if ( V_22 -> V_131 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_131 ) ,
V_22 -> V_131 ,
V_22 -> V_545 ) ;
V_22 -> V_131 = NULL ;
V_22 -> V_545 = 0 ;
}
F_80 ( V_22 -> V_133 ) ;
V_22 -> V_133 = NULL ;
}
static int F_458 ( struct V_1 * V_22 )
{
V_22 -> V_542 =
F_329 ( & ( V_22 -> V_814 -> V_1020 ) ) ;
if ( V_22 -> V_542 > V_1021 )
V_22 -> V_542 = V_1021 ;
F_276 ( sizeof( struct V_129 ) %
V_1022 ) ;
V_22 -> V_131 =
F_328 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_131 ) ,
& ( V_22 -> V_545 ) ) ;
V_22 -> V_133 =
F_91 ( ( ( V_22 -> V_542 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ( V_22 -> V_131 == NULL ) ||
( V_22 -> V_133 == NULL ) )
goto V_922;
memset ( V_22 -> V_131 , 0 ,
V_22 -> V_236 * sizeof( * V_22 -> V_131 ) ) ;
return 0 ;
V_922:
F_457 ( V_22 ) ;
return - V_256 ;
}
static void F_459 ( struct V_1 * V_22 )
{
F_119 ( V_22 ) ;
if ( V_22 -> V_136 ) {
F_330 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_136 ) ,
V_22 -> V_136 ,
V_22 -> V_564 ) ;
V_22 -> V_136 = NULL ;
V_22 -> V_564 = 0 ;
}
F_80 ( V_22 -> V_137 ) ;
V_22 -> V_137 = NULL ;
}
static int F_460 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_542 =
F_329 ( & ( V_22 -> V_814 -> V_1020 ) ) ;
if ( V_22 -> V_542 > V_993 )
V_22 -> V_542 = V_993 ;
F_276 ( sizeof( struct V_138 ) %
V_1023 ) ;
V_22 -> V_136 =
F_328 ( V_22 -> V_29 ,
V_22 -> V_236 * sizeof( * V_22 -> V_136 ) ,
& ( V_22 -> V_564 ) ) ;
V_22 -> V_137 =
F_91 ( ( ( V_22 -> V_542 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ( V_22 -> V_136 == NULL ) ||
( V_22 -> V_137 == NULL ) ) {
V_21 = - V_256 ;
goto V_922;
}
V_21 = F_120 ( V_22 ) ;
if ( V_21 )
goto V_922;
memset ( V_22 -> V_136 , 0 ,
V_22 -> V_236 * sizeof( * V_22 -> V_136 ) ) ;
return 0 ;
V_922:
F_459 ( V_22 ) ;
return V_21 ;
}
static void F_405 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_122 ) ;
V_22 -> V_122 = NULL ;
F_403 ( V_22 ) ;
F_457 ( V_22 ) ;
F_459 ( V_22 ) ;
}
static int F_443 ( struct V_1 * V_22 )
{
T_4 V_906 ;
unsigned long V_63 = V_64 |
V_987 ;
int V_68 , V_21 ;
if ( V_966 )
return 0 ;
V_906 = F_329 ( & ( V_22 -> V_814 -> V_835 ) ) ;
if ( ! ( V_906 & V_1024 ) )
return 0 ;
if ( V_906 & V_113 ) {
V_63 |= V_113 |
V_988 ;
V_21 = F_458 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_906 & V_942 ) {
V_63 |= V_942 |
V_988 ;
V_21 = F_460 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_128 = V_22 -> V_125 > 0 ? V_22 -> V_125 : 1 ;
F_364 ( V_22 ) ;
V_22 -> V_929 = V_22 -> V_120 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
V_22 -> V_112 [ V_68 ] . V_116 = F_328 ( V_22 -> V_29 ,
V_22 -> V_929 ,
& ( V_22 -> V_112 [ V_68 ] . V_121 ) ) ;
if ( ! V_22 -> V_112 [ V_68 ] . V_116 ) {
V_21 = - V_256 ;
goto V_970;
}
V_22 -> V_112 [ V_68 ] . V_463 = V_22 -> V_120 ;
V_22 -> V_112 [ V_68 ] . V_118 = 1 ;
V_22 -> V_112 [ V_68 ] . V_117 = 0 ;
}
V_22 -> V_122 = F_91 ( ( ( V_758 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ! V_22 -> V_122 ) {
V_21 = - V_256 ;
goto V_970;
}
V_21 = F_454 ( V_22 , V_906 ) ;
if ( V_21 )
goto V_915;
return 0 ;
V_915:
F_80 ( V_22 -> V_122 ) ;
V_22 -> V_122 = NULL ;
V_970:
F_403 ( V_22 ) ;
F_457 ( V_22 ) ;
F_459 ( V_22 ) ;
return V_21 ;
}
static int F_461 ( struct V_8 * V_9 )
{
return V_9 -> V_149 == V_150 || V_9 -> V_149 == V_153 ;
}
static void F_417 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1025 ;
int V_400 ;
do {
V_1025 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_236 ; V_68 ++ ) {
V_9 = V_22 -> V_399 + V_68 ;
V_400 = F_178 ( & V_9 -> V_400 ) ;
if ( V_400 > 1 )
V_1025 += F_461 ( V_9 ) ;
F_172 ( V_22 , V_9 ) ;
}
if ( V_1025 <= 0 )
break;
F_166 ( 100 ) ;
} while ( 1 );
}
static struct V_1026 * F_462 (
struct V_1027 * V_1027 )
{
struct V_1026 * V_1026 ;
struct V_1028 * V_1029 ;
V_1026 = F_108 ( sizeof( * V_1026 ) , V_202 ) ;
if ( ! V_1026 )
return NULL ;
V_1029 = F_463 ( V_1027 -> V_1030 -> V_1031 ,
V_1027 -> V_1032 ) ;
if ( ! V_1029 ) {
F_80 ( V_1026 ) ;
return NULL ;
}
V_1027 -> V_1032 ++ ;
V_1026 -> V_1029 = V_1029 ;
V_1026 -> V_1033 = V_1027 ;
return V_1026 ;
}
static void F_464 ( struct V_1026 * V_1026 )
{
struct V_1028 * V_1029 = V_1026 -> V_1029 ;
F_465 ( V_1026 -> V_1033 -> V_1034 , V_1029 ) ;
F_466 ( V_1029 ) ;
if ( V_1026 -> V_1035 )
F_423 ( & V_1026 -> V_1036 ) ;
F_80 ( V_1026 ) ;
}
static int F_467 ( struct V_1026 * V_1026 )
{
int V_21 ;
struct V_1027 * V_1027 ;
struct V_1028 * V_1029 ;
struct V_1037 * V_1038 ;
V_1027 = V_1026 -> V_1033 ;
V_1029 = V_1026 -> V_1029 ;
V_1038 = & V_1029 -> V_1038 ;
memset ( V_1038 , 0 , sizeof( * V_1038 ) ) ;
V_1038 -> V_447 = V_1027 -> V_447 ;
V_1038 -> V_517 = V_1039 ;
V_1038 -> V_1040 = V_1041 ;
V_1038 -> V_1042 = V_1041 ;
V_1029 -> V_1043 = V_1044 ;
V_1029 -> V_1045 = V_1044 ;
V_1029 -> V_1046 = V_1044 ;
V_1029 -> V_1047 = V_1044 ;
V_1029 -> V_1048 = V_1044 ;
V_21 = F_468 ( V_1026 -> V_1029 ) ;
if ( V_21 )
return V_21 ;
F_469 ( V_1027 -> V_1034 , V_1026 -> V_1029 ) ;
F_92 ( & V_1026 -> V_1036 ,
& V_1027 -> V_1049 ) ;
V_1026 -> V_1035 = true ;
return 0 ;
}
static int
F_470 ( struct V_1027 * V_1027 ,
struct V_249 * V_250 )
{
struct V_1037 * V_1038 ;
V_1038 = & V_250 -> V_1038 ;
V_1038 -> V_447 = V_1027 -> V_447 ;
V_1038 -> V_1040 = V_1041 ;
V_1038 -> V_1042 = V_1041 ;
return F_471 ( V_250 ) ;
}
static struct V_1027
* F_472 ( struct V_1050 * V_1050 ,
T_5 V_447 )
{
int V_21 ;
struct V_1027 * V_1027 ;
struct V_1051 * V_1034 ;
V_1027 = F_108 ( sizeof( * V_1027 ) , V_202 ) ;
if ( ! V_1027 )
return NULL ;
F_436 ( & V_1027 -> V_1049 ) ;
V_1027 -> V_1030 = V_1050 ;
V_1034 = F_473 ( V_1050 -> V_1031 ) ;
if ( ! V_1034 )
goto V_1052;
V_21 = F_474 ( V_1034 ) ;
if ( V_21 )
goto V_1053;
V_1027 -> V_1034 = V_1034 ;
V_1027 -> V_447 = V_447 ;
F_92 ( & V_1027 -> V_1054 ,
& V_1050 -> V_1055 ) ;
return V_1027 ;
V_1053:
F_475 ( V_1034 ) ;
V_1052:
F_80 ( V_1027 ) ;
return NULL ;
}
static void F_476 ( struct V_1027 * V_1027 )
{
struct V_1026 * V_1026 ;
struct V_1026 * V_1056 ;
F_477 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_464 ( V_1026 ) ;
F_478 ( V_1027 -> V_1034 ) ;
F_423 ( & V_1027 -> V_1054 ) ;
F_80 ( V_1027 ) ;
}
static struct V_1050 * F_479 ( struct V_42 * V_1031 )
{
struct V_1050 * V_1050 ;
V_1050 = F_108 ( sizeof( * V_1050 ) , V_202 ) ;
if ( V_1050 ) {
V_1050 -> V_1031 = V_1031 ;
F_436 ( & V_1050 -> V_1055 ) ;
}
return V_1050 ;
}
static void F_480 ( struct V_1050 * V_1050 )
{
struct V_1027 * V_1027 ;
struct V_1027 * V_1056 ;
if ( ! V_1050 )
return;
F_477 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_476 ( V_1027 ) ;
F_80 ( V_1050 ) ;
}
static struct V_73
* F_113 ( struct V_1 * V_22 ,
struct V_249 * V_250 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1051 )
continue;
if ( V_42 -> V_1051 -> V_250 == V_250 )
return V_42 ;
}
return NULL ;
}
static int F_229 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1031 ;
struct V_1050 * V_1050 ;
struct V_1027 * V_1027 ;
struct V_1026 * V_1026 ;
V_1031 = & V_22 -> V_59 -> V_1057 ;
V_1050 = F_479 ( V_1031 ) ;
if ( ! V_1050 )
return - V_256 ;
V_1027 = F_472 ( V_1050 , V_22 -> V_447 ) ;
if ( ! V_1027 ) {
V_21 = - V_81 ;
goto V_1058;
}
V_1026 = F_462 ( V_1027 ) ;
if ( ! V_1026 ) {
V_21 = - V_81 ;
goto V_1053;
}
V_21 = F_467 ( V_1026 ) ;
if ( V_21 )
goto V_1059;
V_22 -> V_237 = V_1050 ;
return 0 ;
V_1059:
F_464 ( V_1026 ) ;
V_1053:
F_476 ( V_1027 ) ;
V_1058:
F_480 ( V_1050 ) ;
return V_21 ;
}
static void F_452 ( struct V_1 * V_22 )
{
F_480 ( V_22 -> V_237 ) ;
}
static int F_101 ( struct V_1050 * V_1050 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1027 * V_1027 ;
struct V_249 * V_250 ;
V_1027 = F_472 ( V_1050 , V_42 -> V_447 ) ;
if ( ! V_1027 )
return - V_256 ;
V_250 = F_481 ( V_1027 -> V_1034 ) ;
if ( ! V_250 ) {
V_21 = - V_81 ;
goto V_1053;
}
V_1027 -> V_250 = V_250 ;
V_42 -> V_1051 = V_1027 ;
V_21 = F_470 ( V_1027 , V_250 ) ;
if ( V_21 )
goto V_1053;
return 0 ;
V_1053:
F_476 ( V_1027 ) ;
V_42 -> V_1051 = NULL ;
return V_21 ;
}
static void F_106 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1051 ) {
F_476 ( V_42 -> V_1051 ) ;
V_42 -> V_1051 = NULL ;
}
}
static int
F_482 ( struct V_1028 * V_1029 )
{
return 0 ;
}
static int
F_483 ( struct V_249 * V_250 , T_5 * V_1060 )
{
return 0 ;
}
static int
F_484 ( struct V_249 * V_250 )
{
return - V_1061 ;
}
static int
F_485 ( struct V_1028 * V_1029 , int V_1062 )
{
return 0 ;
}
static int
F_486 ( struct V_1028 * V_1029 , int V_1063 )
{
return 0 ;
}
static int
F_487 ( struct V_1028 * V_1029 )
{
return 0 ;
}
static void
F_488 ( struct V_1028 * V_1029 )
{
}
static int
F_489 ( struct V_1028 * V_1029 , struct V_1064 * V_1065 )
{
return - V_55 ;
}
static int
F_490 ( struct V_6 * V_47 , struct V_249 * V_250 ,
struct V_627 * V_1066 )
{
return - V_55 ;
}
static int T_18 F_491 ( void )
{
int V_21 ;
V_648 =
F_492 ( & V_1067 ) ;
if ( ! V_648 )
return - V_81 ;
V_21 = F_493 ( & V_1068 ) ;
if ( V_21 )
F_494 ( V_648 ) ;
return V_21 ;
}
static void T_19 F_495 ( void )
{
F_496 ( & V_1068 ) ;
F_494 ( V_648 ) ;
}
