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
if ( V_77 -> V_105 ||
V_77 -> V_104 == V_106 ||
F_32 ( V_77 ) ) {
V_90 += snprintf ( V_45 + V_90 ,
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
if ( V_77 -> V_95 [ V_68 ] > 0 )
V_90 += snprintf ( V_45 + V_90 ,
V_82 - V_90 ,
L_28 ,
V_95 ) ;
if ( V_77 -> V_104 == V_107 && V_77 -> V_108 ) {
if ( V_91 == 0 || V_91 == 0xFF ) {
V_90 += snprintf ( V_45 + V_90 ,
V_82 - V_90 ,
L_29 ,
V_92 , V_94 ) ;
} else {
V_90 += snprintf ( V_45 + V_90 ,
V_82 - V_90 ,
L_30 ,
V_91 , V_92 , V_94 ) ;
}
} else if ( V_91 != 0 && V_91 != 0xFF ) {
V_90 += snprintf ( V_45 + V_90 ,
V_82 - V_90 , L_31 ,
V_91 , V_94 ) ;
} else
V_90 += snprintf ( V_45 + V_90 ,
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
case V_106 :
snprintf ( V_164 , F_70 , L_32 ) ;
break;
case V_165 :
snprintf ( V_164 , F_70 , L_33 ) ;
break;
case V_107 :
if ( V_30 -> V_105 )
snprintf ( V_164 , F_70 , L_34 ) ;
else if ( ! F_31 ( V_30 -> V_72 ) )
snprintf ( V_164 , F_70 , L_35 ,
V_85 [ V_166 ] ) ;
else
snprintf ( V_164 , F_70 , L_36 ,
V_30 -> V_83 > V_84 ? L_37 :
V_85 [ V_30 -> V_83 ] ) ;
break;
case V_167 :
snprintf ( V_164 , F_70 , L_38 ) ;
break;
case V_168 :
snprintf ( V_164 , F_70 , L_39 ) ;
break;
case V_169 :
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
V_30 -> V_170 ,
V_30 -> V_171 ,
V_164 ,
V_30 -> V_172 ? '+' : '-' ,
V_30 -> V_89 ? '+' : '-' ,
V_30 -> V_108 ) ;
}
static int F_72 ( struct V_1 * V_22 ,
struct V_73 * V_42 ,
struct V_73 * V_173 [] , int * V_174 )
{
int V_175 = V_22 -> V_161 ;
int V_68 ;
unsigned char V_176 [ 8 ] , V_177 [ 8 ] ;
struct V_73 * V_178 ;
if ( V_175 >= V_160 ) {
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
V_22 -> V_161 ++ ;
V_173 [ * V_174 ] = V_42 ;
( * V_174 ) ++ ;
F_69 ( V_180 , V_22 , V_42 ,
V_42 -> V_108 ? L_48 : L_49 ) ;
V_42 -> V_181 = V_42 -> V_89 ;
V_42 -> V_89 = 0 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_22 ,
int V_182 , struct V_73 * V_183 )
{
int V_89 ;
F_75 ( V_182 < 0 || V_182 >= V_160 ) ;
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
F_75 ( V_182 < 0 || V_182 >= V_160 ) ;
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
F_75 ( V_182 < 0 || V_182 >= V_160 ) ;
V_178 = V_22 -> V_30 [ V_182 ] ;
V_189 [ * V_190 ] = V_22 -> V_30 [ V_182 ] ;
( * V_190 ) ++ ;
for ( V_68 = V_182 ; V_68 < V_22 -> V_161 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_161 -- ;
F_69 ( V_180 , V_22 , V_178 , L_52 ) ;
}
static void F_79 ( struct V_1 * V_22 ,
struct V_73 * V_173 )
{
unsigned long V_78 ;
int V_68 , V_191 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_173 ) {
for ( V_191 = V_68 ; V_191 < V_22 -> V_161 - 1 ; V_191 ++ )
V_22 -> V_30 [ V_191 ] = V_22 -> V_30 [ V_191 + 1 ] ;
V_22 -> V_161 -- ;
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
struct V_73 * V_30 [] , int V_161 ,
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
for ( V_191 = 0 ; V_191 < V_161 ; V_191 ++ ) {
if ( V_30 [ V_191 ] == NULL )
continue;
if ( V_30 [ V_191 ] -> V_104 != V_107 )
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
struct V_73 * V_30 [] , int V_161 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_161 ; V_68 ++ ) {
if ( V_30 [ V_68 ] == NULL )
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
V_173 = F_108 ( sizeof( * V_173 ) * V_160 , V_201 ) ;
V_189 = F_108 ( sizeof( * V_189 ) * V_160 , V_201 ) ;
if ( ! V_173 || ! V_189 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_67
L_68 ) ;
goto V_244;
}
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_68 = 0 ;
V_190 = 0 ;
V_174 = 0 ;
while ( V_68 < V_22 -> V_161 ) {
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
V_22 -> V_161 , & V_182 ) ;
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
F_98 ( V_22 , V_22 -> V_30 , V_22 -> V_161 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
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
if ( V_189 [ V_68 ] -> V_108 )
F_102 ( V_22 , V_189 [ V_68 ] ) ;
F_80 ( V_189 [ V_68 ] ) ;
V_189 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_174 ; V_68 ++ ) {
int V_21 = 0 ;
if ( V_173 [ V_68 ] == NULL )
continue;
if ( ! ( V_173 [ V_68 ] -> V_108 ) )
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
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
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
if ( V_178 && V_178 -> V_108 ) {
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
V_3 -> V_251 = ! V_178 || ! V_178 -> V_108 ;
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
struct V_138 * V_130 , struct V_8 * V_9 )
{
struct V_259 * V_260 ;
T_5 V_261 ;
T_4 V_262 ;
V_260 = V_22 -> V_253 [ V_9 -> V_132 ] ;
V_262 = F_124 ( V_130 -> V_263 [ 0 ] . V_264 ) ;
V_261 = F_125 ( V_22 -> V_29 , V_260 , V_262 ,
V_265 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , V_261 ) ) {
V_130 -> V_263 -> V_266 = 0 ;
return - 1 ;
}
V_130 -> V_263 -> V_266 = F_127 ( V_261 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_22 ,
struct V_138 * V_130 )
{
struct V_259 * V_267 ;
T_5 V_261 ;
T_4 V_262 ;
V_267 = V_130 -> V_263 ;
V_261 = F_129 ( V_267 -> V_266 ) ;
V_262 = F_124 ( V_130 -> V_263 [ 0 ] . V_264 ) ;
F_130 ( V_22 -> V_29 , V_261 , V_262 , V_265 ) ;
}
static int F_131 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_268 * V_267 , * V_260 ;
T_5 V_261 ;
T_4 V_269 ;
V_267 = & V_9 -> V_270 [ V_22 -> V_271 - 1 ] ;
V_260 = V_22 -> V_258 [ V_9 -> V_132 ] ;
V_267 -> V_272 = F_132 ( V_273 ) ;
V_269 = sizeof( * V_267 ) *
( F_96 ( V_9 -> V_123 . V_274 ) - V_22 -> V_271 ) ;
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
if ( F_96 ( V_9 -> V_123 . V_274 ) <= V_22 -> V_271 )
return;
V_267 = & V_9 -> V_270 [ V_22 -> V_271 - 1 ] ;
F_130 ( V_22 -> V_29 , F_129 ( V_267 -> V_276 ) ,
F_124 ( V_267 -> V_275 ) , V_265 ) ;
}
static int F_134 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_277 * V_278 ,
struct V_138 * V_279 )
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
V_9 -> V_143 . V_144 , V_9 -> V_24 -> V_38 ) ;
F_140 ( V_22 , V_9 ) ;
}
static void F_148 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
struct V_73 * V_30 )
{
struct V_138 * V_279 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
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
struct V_8 * V_130 )
{
T_1 V_322 = V_130 -> V_24 -> V_38 ;
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
static void F_150 ( struct V_8 * V_130 )
{
struct V_277 * V_278 ;
struct V_1 * V_22 ;
struct V_330 * V_331 ;
struct V_73 * V_30 ;
struct V_138 * V_279 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_332 ;
V_331 = V_130 -> V_24 ;
V_278 = V_130 -> V_10 ;
V_22 = V_130 -> V_22 ;
V_30 = V_278 -> V_42 -> V_80 ;
V_279 = & V_22 -> V_136 [ V_130 -> V_132 ] ;
F_151 ( V_278 ) ;
if ( ( V_130 -> V_149 == V_333 ) &&
( F_96 ( V_130 -> V_123 . V_274 ) > V_22 -> V_271 ) )
F_133 ( V_22 , V_130 ) ;
if ( ( V_130 -> V_149 == V_153 ) &&
( V_279 -> V_263 [ 0 ] . V_334 == V_335 ) )
F_128 ( V_22 , V_279 ) ;
V_278 -> V_288 = ( V_304 << 16 ) ;
V_278 -> V_288 |= ( V_305 << 8 ) ;
if ( V_130 -> V_149 == V_153 || V_130 -> V_149 == V_150 )
F_45 ( & V_130 -> V_234 -> V_250 ) ;
if ( F_44 ( V_331 -> V_36 == V_336 ) ) {
V_278 -> V_288 = V_337 << 16 ;
return F_142 ( V_22 , V_130 , V_278 ) ;
}
if ( ( F_44 ( F_5 ( V_130 ) ) ) ) {
if ( V_130 -> V_13 )
return F_140 ( V_22 , V_130 ) ;
if ( V_130 -> V_12 )
return F_147 ( V_22 , V_130 , V_278 ) ;
}
if ( V_130 -> V_149 == V_153 )
return F_148 ( V_22 , V_130 , V_278 , V_30 ) ;
F_136 ( V_278 , V_331 -> V_338 ) ;
if ( V_331 -> V_36 == 0 )
return F_142 ( V_22 , V_130 , V_278 ) ;
if ( V_130 -> V_149 == V_150 ) {
struct V_129 * V_9 = & V_22 -> V_131 [ V_130 -> V_132 ] ;
V_130 -> V_123 . V_124 = F_152 ( V_278 ) ;
V_130 -> V_123 . V_274 = F_153 ( V_130 -> V_123 . V_124 ) ;
V_130 -> V_143 . V_339 = F_96 ( V_9 -> V_340 ) &
V_341 ;
V_130 -> V_123 . V_342 = V_9 -> V_342 ;
memcpy ( V_130 -> V_123 . V_343 . V_344 , V_9 -> V_345 , 8 ) ;
memcpy ( V_130 -> V_143 . V_144 , V_9 -> V_144 , V_130 -> V_143 . V_339 ) ;
if ( F_32 ( V_30 ) ) {
if ( V_331 -> V_36 == V_346 )
V_30 -> V_89 = 0 ;
return F_143 ( V_22 , V_130 ) ;
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
V_130 , V_331 -> V_38 ,
V_16 , V_17 , V_18 ,
V_278 -> V_288 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_79
L_80 , V_130 ) ,
V_278 -> V_288 = V_337 << 16 ;
}
break;
case V_349 :
break;
case V_350 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_81 , V_130 -> V_143 . V_144 ) ;
break;
case V_351 : {
V_278 -> V_288 = V_337 << 16 ;
}
break;
case V_352 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_82 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_354 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_83 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_355 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_84 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_356 :
return F_147 ( V_22 , V_130 , V_278 ) ;
case V_357 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_85 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_358 :
V_278 -> V_288 = V_348 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_86 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_359 :
V_278 -> V_288 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_87 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_361 :
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_88 ) ;
break;
case V_362 :
if ( F_149 ( V_22 , V_130 ) )
V_278 -> V_288 = V_353 << 16 ;
break;
case V_346 :
V_278 -> V_288 = V_348 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_89 , V_130 ) ;
break;
default:
V_278 -> V_288 = V_353 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_90 ,
V_130 , V_331 -> V_36 ) ;
}
return F_142 ( V_22 , V_130 , V_278 ) ;
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
struct V_8 * V_130 ,
unsigned char * V_45 ,
T_3 V_367 ,
int V_365 )
{
T_5 V_368 ;
if ( V_367 == 0 || V_365 == V_369 ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_274 = F_153 ( 0 ) ;
return 0 ;
}
V_368 = F_125 ( V_29 , V_45 , V_367 , V_365 ) ;
if ( F_126 ( & V_29 -> V_30 , V_368 ) ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_274 = F_153 ( 0 ) ;
return - 1 ;
}
V_130 -> V_270 [ 0 ] . V_276 = F_127 ( V_368 ) ;
V_130 -> V_270 [ 0 ] . V_275 = F_132 ( V_367 ) ;
V_130 -> V_270 [ 0 ] . V_272 = F_132 ( V_370 ) ;
V_130 -> V_123 . V_124 = 1 ;
V_130 -> V_123 . V_274 = F_153 ( 1 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_112 , unsigned long V_371 )
{
F_157 ( V_372 ) ;
V_9 -> V_373 = & V_372 ;
F_58 ( V_22 , V_9 , V_112 ) ;
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
int V_112 , unsigned long V_371 )
{
if ( F_44 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_336 ;
return V_375 ;
}
return F_156 ( V_22 , V_9 , V_112 , V_371 ) ;
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
V_21 = F_161 ( V_22 , V_9 , V_126 ,
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
const T_1 * V_140 = V_9 -> V_143 . V_144 ;
const T_1 * V_103 = V_9 -> V_123 . V_343 . V_344 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_92
L_93 ,
V_382 , V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_140 [ 0 ] , V_140 [ 1 ] , V_140 [ 2 ] , V_140 [ 3 ] ,
V_140 [ 4 ] , V_140 [ 5 ] , V_140 [ 6 ] , V_140 [ 7 ] ,
V_140 [ 8 ] , V_140 [ 9 ] , V_140 [ 10 ] , V_140 [ 11 ] ,
V_140 [ 12 ] , V_140 [ 13 ] , V_140 [ 14 ] , V_140 [ 15 ] ) ;
}
static void F_168 ( struct V_1 * V_22 ,
struct V_8 * V_130 )
{
const struct V_330 * V_331 = V_130 -> V_24 ;
struct V_42 * V_383 = & V_130 -> V_22 -> V_29 -> V_30 ;
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
F_167 ( V_22 , L_94 , V_130 ) ;
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
F_167 ( V_22 , L_101 , V_130 ) ;
break;
case V_351 : {
F_167 ( V_22 , L_102 , V_130 ) ;
F_9 ( V_383 , L_103 ) ;
}
break;
case V_352 :
F_167 ( V_22 , L_104 , V_130 ) ;
break;
case V_354 :
F_167 ( V_22 , L_105 , V_130 ) ;
break;
case V_355 :
F_167 ( V_22 , L_106 , V_130 ) ;
break;
case V_356 :
F_167 ( V_22 , L_107 , V_130 ) ;
break;
case V_357 :
F_167 ( V_22 , L_108 , V_130 ) ;
break;
case V_358 :
F_167 ( V_22 , L_109 , V_130 ) ;
break;
case V_359 :
F_167 ( V_22 , L_110 , V_130 ) ;
break;
case V_361 :
F_167 ( V_22 , L_111 , V_130 ) ;
break;
case V_336 :
F_167 ( V_22 , L_112 , V_130 ) ;
break;
default:
F_167 ( V_22 , L_113 , V_130 ) ;
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
T_1 V_390 , int V_112 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_390 , V_22 , NULL , 0 , 0 ,
V_72 , V_391 ) ;
V_21 = F_161 ( V_22 , V_9 , V_112 , V_374 ) ;
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
struct V_138 * V_279 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_135 * V_393 = (struct V_135 * ) V_279 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_149 ) {
case V_333 :
case V_394 :
V_392 = ! memcmp ( V_72 , & V_9 -> V_123 . V_343 . V_344 ,
sizeof( V_9 -> V_123 . V_343 . V_344 ) ) ;
break;
case V_150 :
case V_153 :
if ( V_9 -> V_234 == V_30 ) {
V_392 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_233 && ! V_392 ; V_68 ++ ) {
V_392 = V_30 -> V_234 [ V_68 ] == V_9 -> V_234 ;
}
}
break;
case V_155 :
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
V_9 -> V_149 ) ;
F_175 () ;
}
return V_392 ;
}
static int F_176 ( struct V_1 * V_22 , struct V_73 * V_30 ,
unsigned char * V_72 , T_1 V_390 , int V_112 )
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
V_21 = F_173 ( V_22 , V_72 , V_390 , V_112 ) ;
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
0 , V_157 , V_387 ) ;
if ( V_21 )
goto V_388;
V_9 -> V_143 . V_144 [ 2 ] = V_419 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_419 >> 8 ) & 0xff ;
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
0 , V_157 , V_387 ) ;
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
0 , V_157 , V_387 ) ;
if ( V_21 )
goto V_388;
V_9 -> V_143 . V_144 [ 2 ] = V_419 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_419 >> 8 ) & 0xff ;
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
static T_5 F_187 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_426 * V_427 ;
T_4 V_428 ;
T_5 V_429 = 0 ;
int V_68 ;
V_427 = F_108 ( sizeof( * V_427 ) , V_201 ) ;
if ( ! V_427 )
return 0 ;
if ( F_188 ( V_22 , V_427 , sizeof( * V_427 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_142 ) ;
F_80 ( V_427 ) ;
return 0 ;
}
V_428 = F_189 ( V_427 -> V_430 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_428 ; V_68 ++ )
if ( ! memcmp ( & V_427 -> V_343 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_429 = F_190 ( & V_427 -> V_343 [ V_68 ] . V_431 [ 0 ] ) ;
break;
}
F_80 ( V_427 ) ;
return V_429 ;
}
static void F_191 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_429 = 0 ;
if ( F_62 ( V_72 ) ) {
struct V_420 * V_432 ;
V_432 = F_108 ( sizeof( * V_432 ) , V_201 ) ;
if ( V_432 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_143 , V_202 ) ;
return;
}
V_21 = F_184 ( V_22 ,
V_72 , 0 , V_432 , sizeof( * V_432 ) ) ;
if ( V_21 == 0 ) {
V_429 = F_190 ( V_432 -> V_433 ) ;
V_22 -> V_434 = V_429 ;
}
F_80 ( V_432 ) ;
} else
V_429 = F_187 ( V_22 , V_72 ) ;
V_30 -> V_434 = V_429 ;
}
static int F_192 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_384 )
{
int V_21 ;
int V_68 ;
int V_435 ;
unsigned char * V_45 , V_385 ;
V_45 = F_108 ( 256 , V_201 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_436 ,
V_45 , V_437 ) ;
if ( V_21 != 0 )
goto V_438;
V_435 = V_45 [ 3 ] ;
if ( ( V_435 + V_437 ) <= 255 )
V_385 = V_435 + V_437 ;
else
V_385 = 255 ;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_436 ,
V_45 , V_385 ) ;
if ( V_21 != 0 )
goto V_438;
V_435 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_435 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_384 )
goto V_439;
V_438:
F_80 ( V_45 ) ;
return 0 ;
V_439:
F_80 ( V_45 ) ;
return 1 ;
}
static void F_193 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_417 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_440 ;
V_417 -> V_172 = 0 ;
V_417 -> V_89 = 0 ;
V_417 -> V_181 = 0 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return;
if ( ! F_192 ( V_22 , V_72 , V_441 ) )
goto V_388;
V_21 = F_169 ( V_22 , V_72 ,
V_400 | V_441 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_388;
#define F_194 4
#define F_195 0x01
#define F_196 0x02
V_440 = V_45 [ F_194 ] ;
V_417 -> V_172 =
! ! ( V_440 & F_195 ) ;
if ( V_417 -> V_172 ) {
V_417 -> V_89 =
! ! ( V_440 & F_196 ) ;
if ( F_183 ( V_22 , V_72 , V_417 ) )
V_417 -> V_89 = 0 ;
}
V_417 -> V_181 = V_417 -> V_89 ;
V_388:
F_80 ( V_45 ) ;
return;
}
static int F_197 ( struct V_1 * V_22 , unsigned char * V_72 ,
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
static int F_198 ( struct V_1 * V_22 , int V_442 ,
void * V_45 , int V_385 ,
int V_443 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_330 * V_331 ;
V_9 = F_170 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_171 ( V_9 , V_442 ? V_444 : V_445 , V_22 ,
V_45 , V_385 , 0 , V_72 , V_387 ) ) {
V_21 = - 1 ;
goto V_388;
}
if ( V_443 )
V_9 -> V_143 . V_144 [ 1 ] = V_443 ;
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
struct V_446 * V_447 = V_45 ;
if ( V_447 -> V_448 != V_443 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_144 ,
V_443 ,
V_447 -> V_448 ) ;
V_21 = - 1 ;
}
}
V_388:
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_188 ( struct V_1 * V_22 ,
struct V_426 * V_45 , int V_385 )
{
return F_198 ( V_22 , 0 , V_45 , V_385 ,
V_449 ) ;
}
static inline int F_199 ( struct V_1 * V_22 ,
struct V_446 * V_45 , int V_385 )
{
return F_198 ( V_22 , 1 , V_45 , V_385 , 0 ) ;
}
static inline void F_200 ( struct V_73 * V_42 ,
int V_101 , int V_102 , int V_103 )
{
V_42 -> V_101 = V_101 ;
V_42 -> V_102 = V_102 ;
V_42 -> V_103 = V_103 ;
}
static int F_201 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_450 ;
unsigned char * V_45 ;
V_45 = F_108 ( 64 , V_201 ) ;
if ( ! V_45 )
return V_205 ;
if ( ! F_192 ( V_22 , V_72 , V_451 ) )
goto V_452;
V_21 = F_169 ( V_22 , V_72 , V_400 | V_451 ,
V_45 , V_437 ) ;
if ( V_21 != 0 )
goto V_452;
V_450 = V_45 [ 3 ] ;
V_21 = F_169 ( V_22 , V_72 , V_400 | V_451 ,
V_45 , V_450 + V_437 ) ;
if ( V_21 != 0 )
goto V_452;
V_49 = V_45 [ 4 ] ;
F_80 ( V_45 ) ;
return V_49 ;
V_452:
F_80 ( V_45 ) ;
return V_205 ;
}
static int F_202 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_453 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_454 = 0 ;
T_6 V_455 ;
T_1 V_456 ;
#define F_203 0x04
#define F_204 0x04
#define F_205 0x02
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_457 , V_22 , NULL , 0 , 0 , V_72 , V_387 ) ;
V_21 = F_161 ( V_22 , V_9 , V_126 , V_374 ) ;
if ( V_21 ) {
F_172 ( V_22 , V_9 ) ;
return 0 ;
}
V_453 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_453 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_455 = V_9 -> V_24 -> V_36 ;
V_456 = V_9 -> V_24 -> V_38 ;
F_172 ( V_22 , V_9 ) ;
if ( V_455 != V_37 ||
V_456 != V_289 ||
V_16 != V_458 ||
V_17 != F_203 ) {
return 0 ;
}
V_454 = F_201 ( V_22 , V_72 ) ;
switch ( V_454 ) {
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
return V_454 ;
case V_205 :
if ( ( V_18 == F_204 ) ||
( V_18 == F_205 ) )
return V_454 ;
break;
default:
break;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_330 * V_331 ;
int V_21 = 0 ;
T_5 V_342 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_459 , V_22 , & V_342 , 0 , 0 , V_72 , V_391 ) ;
( void ) F_161 ( V_22 , V_9 , V_126 , V_374 ) ;
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
static void F_207 ( unsigned char * V_460 , int V_50 )
{
bool V_461 = false ;
for (; V_50 > 0 ; ( -- V_50 , ++ V_460 ) ) {
if ( * V_460 == 0 )
V_461 = true ;
if ( V_461 || * V_460 < 0x20 || * V_460 > 0x7e )
* V_460 = ' ' ;
}
}
static int F_208 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_73 * V_417 ,
unsigned char * V_462 )
{
#define F_209 43
#define F_210 "$DR-10"
#define F_211 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_212 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_463 ;
unsigned char * V_464 ;
int V_21 = 0 ;
V_463 = F_108 ( F_212 , V_201 ) ;
if ( ! V_463 ) {
V_21 = - V_255 ;
goto V_465;
}
if ( F_169 ( V_22 , V_72 , 0 , V_463 ,
( unsigned char ) F_212 ) != 0 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_145 ) ;
V_21 = - V_381 ;
goto V_465;
}
F_207 ( & V_463 [ 8 ] , 8 ) ;
F_207 ( & V_463 [ 16 ] , 16 ) ;
V_417 -> V_104 = ( V_463 [ 0 ] & 0x1f ) ;
memcpy ( V_417 -> V_72 , V_72 , 8 ) ;
memcpy ( V_417 -> V_170 , & V_463 [ 8 ] ,
sizeof( V_417 -> V_170 ) ) ;
memcpy ( V_417 -> V_171 , & V_463 [ 16 ] ,
sizeof( V_417 -> V_171 ) ) ;
memset ( V_417 -> V_88 , 0 ,
sizeof( V_417 -> V_88 ) ) ;
F_197 ( V_22 , V_72 , V_417 -> V_88 , 8 ,
sizeof( V_417 -> V_88 ) ) ;
if ( V_417 -> V_104 == V_107 &&
F_31 ( V_72 ) ) {
int V_198 ;
F_181 ( V_22 , V_72 , & V_417 -> V_83 ) ;
if ( V_22 -> V_466 & V_467 )
F_193 ( V_22 , V_72 , V_417 ) ;
V_198 = F_202 ( V_22 , V_72 ) ;
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
if ( V_462 ) {
V_464 = & V_463 [ F_209 ] ;
* V_462 = ( V_417 -> V_104 == V_167 &&
strncmp ( V_464 , F_210 ,
F_211 ) == 0 ) ;
}
F_80 ( V_463 ) ;
return 0 ;
V_465:
F_80 ( V_463 ) ;
return V_21 ;
}
static void F_213 ( struct V_1 * V_22 ,
struct V_73 * V_30 , T_1 * V_72 )
{
unsigned long V_78 ;
int V_21 , V_182 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
V_21 = F_83 ( V_30 , V_22 -> V_30 , V_22 -> V_161 , & V_182 ) ;
if ( ( V_21 == F_86 || V_21 == F_87 ) &&
V_182 >= 0 && V_182 < V_22 -> V_161 ) {
V_30 -> V_468 = V_22 -> V_30 [ V_182 ] -> V_468 ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_96 , V_78 ) ;
V_30 -> V_468 =
F_206 ( V_22 , V_72 ) ;
if ( V_30 -> V_468 < 0 )
V_30 -> V_468 = 0 ;
}
}
static void F_214 ( struct V_1 * V_22 ,
T_1 * V_469 , struct V_73 * V_42 )
{
T_4 V_86 = F_135 ( V_469 ) ;
if ( ! F_31 ( V_469 ) ) {
if ( F_62 ( V_469 ) )
F_200 ( V_42 ,
V_470 , 0 , V_86 & 0x3fff ) ;
else
F_200 ( V_42 ,
V_245 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_105 ) {
F_200 ( V_42 ,
V_471 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_200 ( V_42 , V_472 ,
0 , V_86 & 0x3fff ) ;
}
static int F_215 ( struct V_1 * V_22 ,
struct V_8 * V_473 , unsigned char * V_72 )
{
struct V_138 * V_279 =
& V_22 -> V_136 [ V_473 -> V_132 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_96 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_185 == F_124 ( V_279 -> V_474 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_96 , V_78 ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_22 , int V_475 ,
int V_68 , int V_428 , int V_476 )
{
int V_477 = V_428 + ( V_475 == 0 ) ;
if ( V_68 == V_475 )
return 0 ;
if ( V_68 < V_477 )
return 0 ;
if ( ( V_68 - V_428 - ( V_475 == 0 ) ) < V_476 )
return 0 ;
return 1 ;
}
static int F_217 ( struct V_1 * V_22 ,
struct V_426 * V_427 , T_4 * V_428 ,
struct V_446 * V_478 , T_4 * V_479 )
{
if ( F_188 ( V_22 , V_427 , sizeof( * V_427 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_142 ) ;
return - 1 ;
}
* V_428 = F_218 ( * ( ( V_480 * ) V_427 -> V_430 ) ) / 24 ;
if ( * V_428 > V_481 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_146 ,
V_481 , * V_428 - V_481 ) ;
* V_428 = V_481 ;
}
if ( F_199 ( V_22 , V_478 , sizeof( * V_478 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
return - 1 ;
}
* V_479 = F_218 ( * ( ( V_480 * ) V_478 -> V_430 ) ) / 8 ;
if ( * V_479 > V_482 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_148
L_149 , V_482 ,
* V_479 - V_482 ) ;
* V_479 = V_482 ;
}
if ( * V_479 + * V_428 > V_481 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_150
L_149 , V_481 ,
* V_428 + * V_479 - V_481 ) ;
* V_479 = V_481 - * V_428 ;
}
return 0 ;
}
static T_1 * F_219 ( struct V_1 * V_22 , int V_475 ,
int V_68 , int V_428 , int V_479 ,
struct V_426 * V_483 ,
struct V_446 * V_484 )
{
int V_477 = V_428 + ( V_475 == 0 ) ;
int V_485 = V_428 + V_479 + ( V_475 == 0 ) ;
if ( V_68 == V_475 )
return V_157 ;
if ( V_68 < V_477 )
return & V_483 -> V_343 [ V_68 -
( V_475 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_485 )
return & V_484 -> V_343 [ V_68 - V_428 -
( V_475 == 0 ) ] [ 0 ] ;
F_175 () ;
return NULL ;
}
static void F_220 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_426 * V_486 , int V_487 ,
struct V_424 * V_488 )
{
int V_21 ;
struct V_489 * V_490 = & V_486 -> V_343 [ V_487 ] ;
V_30 -> V_185 = V_490 -> V_185 ;
if ( ( V_490 -> V_491 & 0x08 ) && V_30 -> V_185 )
V_30 -> V_186 = 1 ;
memset ( V_488 , 0 , sizeof( * V_488 ) ) ;
V_21 = F_186 ( V_22 , & V_490 -> V_86 [ 0 ] ,
F_221 ( & V_490 -> V_86 [ 0 ] ) , V_488 ,
sizeof( * V_488 ) ) ;
if ( ! V_21 )
#define F_222 2
#define F_223 7
V_30 -> V_188 =
F_96 ( V_488 -> V_492 ) -
F_222 ;
else
V_30 -> V_188 = F_223 ;
}
static void F_224 ( struct V_73 * V_417 ,
struct V_426 * V_486 , int V_487 ,
struct V_424 * V_488 )
{
struct V_489 * V_490 = & V_486 -> V_343 [ V_487 ] ;
if ( ( V_490 -> V_491 & 0x08 ) && V_417 -> V_185 )
V_417 -> V_186 = 1 ;
memcpy ( & V_417 -> V_98 ,
& V_488 -> V_493 ,
sizeof( V_417 -> V_98 ) ) ;
memcpy ( & V_417 -> V_99 ,
& V_488 -> V_494 ,
sizeof( V_417 -> V_99 ) ) ;
memcpy ( & V_417 -> V_91 ,
& V_488 -> V_495 ,
sizeof( V_417 -> V_91 ) ) ;
memcpy ( & V_417 -> V_95 ,
& V_488 -> V_496 ,
sizeof( V_417 -> V_95 ) ) ;
memcpy ( & V_417 -> V_92 ,
& V_488 -> V_497 ,
sizeof( V_417 -> V_92 ) ) ;
}
static int F_225 ( struct V_1 * V_22 ,
struct V_422 * V_498 ,
T_4 * V_499 )
{
int V_21 ;
if ( ! V_498 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_151 ,
V_202 ) ;
return - V_255 ;
}
memset ( V_498 , 0 , sizeof( * V_498 ) ) ;
V_21 = F_185 ( V_22 , V_498 , sizeof( * V_498 ) ) ;
if ( ! V_21 )
if ( V_498 -> V_500 < 256 )
* V_499 = V_498 -> V_500 ;
else
* V_499 = F_96 (
V_498 -> V_501 ) ;
else
* V_499 = - 1 ;
return V_21 ;
}
static void F_226 ( struct V_1 * V_22 )
{
struct V_426 * V_483 = NULL ;
struct V_446 * V_484 = NULL ;
struct V_424 * V_488 = NULL ;
struct V_422 * V_498 = NULL ;
T_4 V_428 = 0 ;
T_4 V_479 = 0 ;
T_4 V_476 = 0 ;
T_4 V_502 = 0 ;
struct V_73 * * V_503 , * V_417 , * V_504 ;
int V_505 = 0 ;
int V_68 , V_506 , V_507 ;
int V_475 ;
bool V_74 ;
F_65 ( V_508 , V_509 ) ;
V_503 = F_108 ( sizeof( * V_503 ) * V_160 , V_201 ) ;
V_483 = F_108 ( sizeof( * V_483 ) , V_201 ) ;
V_484 = F_108 ( sizeof( * V_484 ) , V_201 ) ;
V_504 = F_108 ( sizeof( * V_504 ) , V_201 ) ;
V_488 = F_108 ( sizeof( * V_488 ) , V_201 ) ;
V_498 = F_108 ( sizeof( * V_498 ) , V_201 ) ;
if ( ! V_503 || ! V_483 || ! V_484 ||
! V_504 || ! V_488 || ! V_498 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_152 ) ;
goto V_388;
}
memset ( V_508 , 0 , sizeof( V_508 ) ) ;
V_22 -> V_243 = 0 ;
if ( F_217 ( V_22 , V_483 , & V_428 ,
V_484 , & V_479 ) ) {
V_22 -> V_243 = 1 ;
goto V_388;
}
if ( F_225 ( V_22 , V_498 , & V_476 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_153 ,
V_202 ) ;
}
V_507 = V_428 + V_479 + V_509 + 1 ;
for ( V_68 = 0 ; V_68 < V_507 ; V_68 ++ ) {
if ( V_68 >= V_160 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_154
L_155 , V_160 ,
V_507 - V_160 ) ;
break;
}
V_503 [ V_68 ] = F_108 ( sizeof( * V_503 [ V_68 ] ) , V_201 ) ;
if ( ! V_503 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_156 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_243 = 1 ;
goto V_388;
}
V_502 ++ ;
}
if ( F_63 ( V_22 ) )
V_475 = 0 ;
else
V_475 = V_428 + V_479 ;
V_506 = 0 ;
for ( V_68 = 0 ; V_68 < V_428 + V_479 + 1 ; V_68 ++ ) {
T_1 * V_469 , V_510 = 0 ;
int V_21 = 0 ;
int V_511 = V_68 - ( V_475 == 0 ) ;
V_74 = V_68 < V_428 + ( V_475 == 0 ) ;
V_469 = F_219 ( V_22 , V_475 ,
V_68 , V_428 , V_479 , V_483 , V_484 ) ;
if ( F_227 ( V_469 ) && V_74 &&
( V_483 -> V_343 [ V_511 ] . V_491 & 0x01 ) )
continue;
V_21 = F_208 ( V_22 , V_469 , V_504 ,
& V_510 ) ;
if ( V_21 == - V_255 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_157 ) ;
V_22 -> V_243 = 1 ;
goto V_388;
}
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_158 ) ;
continue;
}
V_504 -> V_105 =
F_216 ( V_22 , V_475 , V_68 ,
V_428 , V_476 ) ;
F_214 ( V_22 , V_469 , V_504 ) ;
F_213 ( V_22 , V_504 , V_469 ) ;
V_417 = V_503 [ V_505 ] ;
if ( ! V_22 -> V_512 ) {
if ( V_504 -> V_105 ) {
V_22 -> V_512 = 1 ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_159 ) ;
}
}
* V_417 = * V_504 ;
V_417 -> V_74 = V_74 ;
if ( F_227 ( V_469 ) && V_417 -> V_74 )
V_417 -> V_108 = 0 ;
else
V_417 -> V_108 = 1 ;
if ( V_417 -> V_74 && V_417 -> V_108 )
F_191 ( V_22 , V_469 , V_417 ) ;
switch ( V_417 -> V_104 ) {
case V_167 :
if ( V_510 )
V_505 ++ ;
break;
case V_107 :
if ( V_417 -> V_74 ) {
V_417 -> V_89 = 0 ;
F_220 ( V_22 , V_417 ,
V_483 , V_511 , V_488 ) ;
F_224 ( V_417 ,
V_483 , V_511 , V_488 ) ;
}
V_505 ++ ;
break;
case V_168 :
case V_169 :
case V_165 :
V_505 ++ ;
break;
case V_106 :
if ( ! F_62 ( V_469 ) )
break;
V_505 ++ ;
break;
default:
break;
}
if ( V_505 >= V_160 )
break;
}
if ( V_22 -> V_236 == NULL ) {
int V_21 = 0 ;
V_21 = F_228 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_160 , V_21 ) ;
goto V_388;
}
}
F_107 ( V_22 , V_503 , V_505 ) ;
V_388:
F_80 ( V_504 ) ;
for ( V_68 = 0 ; V_68 < V_502 ; V_68 ++ )
F_80 ( V_503 [ V_68 ] ) ;
F_80 ( V_503 ) ;
F_80 ( V_483 ) ;
F_80 ( V_484 ) ;
F_80 ( V_498 ) ;
F_80 ( V_488 ) ;
}
static void F_229 ( struct V_268 * V_513 ,
struct V_514 * V_263 )
{
T_5 V_368 = ( T_5 ) F_230 ( V_263 ) ;
unsigned int V_50 = F_231 ( V_263 ) ;
V_513 -> V_276 = F_127 ( V_368 ) ;
V_513 -> V_275 = F_132 ( V_50 ) ;
V_513 -> V_272 = 0 ;
}
static int F_232 ( struct V_1 * V_22 ,
struct V_8 * V_130 ,
struct V_277 * V_278 )
{
struct V_514 * V_263 ;
int V_515 , V_68 , V_516 , V_517 , V_518 ;
struct V_268 * V_519 ;
F_75 ( F_152 ( V_278 ) > V_22 -> V_256 ) ;
V_515 = F_233 ( V_278 ) ;
if ( V_515 < 0 )
return V_515 ;
if ( ! V_515 )
goto V_520;
V_519 = V_130 -> V_270 ;
V_517 = V_515 > V_22 -> V_271 ;
V_516 = V_517 ? V_22 -> V_271 - 1 : V_515 ;
V_518 = F_152 ( V_278 ) - 1 ;
F_234 (cmd, sg, sg_limit, i) {
F_229 ( V_519 , V_263 ) ;
V_519 ++ ;
}
if ( V_517 ) {
V_519 = V_22 -> V_258 [ V_130 -> V_132 ] ;
V_516 = V_515 - V_516 ;
F_235 (sg, sg, sg_limit, i) {
F_229 ( V_519 , V_263 ) ;
V_519 ++ ;
}
}
( V_519 - 1 ) -> V_272 = F_132 ( V_370 ) ;
if ( V_515 + V_517 > V_22 -> V_521 )
V_22 -> V_521 = V_515 + V_517 ;
if ( V_517 ) {
V_130 -> V_123 . V_124 = V_22 -> V_271 ;
V_130 -> V_123 . V_274 = F_153 ( V_515 + 1 ) ;
if ( F_131 ( V_22 , V_130 ) ) {
F_151 ( V_278 ) ;
return - 1 ;
}
return 0 ;
}
V_520:
V_130 -> V_123 . V_124 = ( T_1 ) V_515 ;
V_130 -> V_123 . V_274 = F_153 ( V_515 ) ;
return 0 ;
}
static int F_236 ( T_1 * V_140 , int * V_522 )
{
int V_523 = 0 ;
T_4 V_524 ;
T_4 V_525 ;
switch ( V_140 [ 0 ] ) {
case V_526 :
case V_527 :
V_523 = 1 ;
case V_528 :
case V_529 :
if ( * V_522 == 6 ) {
V_524 = F_237 ( & V_140 [ 2 ] ) ;
V_525 = V_140 [ 4 ] ;
if ( V_525 == 0 )
V_525 = 256 ;
} else {
F_75 ( * V_522 != 12 ) ;
V_524 = F_189 ( & V_140 [ 2 ] ) ;
V_525 = F_189 ( & V_140 [ 6 ] ) ;
}
if ( V_525 > 0xffff )
return V_530 ;
V_140 [ 0 ] = V_523 ? V_531 : V_532 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_524 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_524 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_524 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_524 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_525 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_525 ) ;
V_140 [ 9 ] = 0 ;
* V_522 = 10 ;
break;
}
return 0 ;
}
static int F_238 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_140 , int V_522 ,
T_1 * V_72 , struct V_73 * V_234 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_129 * V_130 = & V_22 -> V_131 [ V_9 -> V_132 ] ;
unsigned int V_50 ;
unsigned int V_533 = 0 ;
struct V_514 * V_263 ;
T_5 V_368 ;
int V_515 , V_68 ;
struct V_268 * V_519 ;
T_4 V_534 = V_535 ;
if ( F_152 ( V_278 ) > V_22 -> V_536 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_530 ;
}
F_75 ( V_278 -> V_537 > V_538 ) ;
if ( F_236 ( V_140 , & V_522 ) ) {
F_45 ( & V_234 -> V_250 ) ;
return V_530 ;
}
V_9 -> V_149 = V_150 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_539 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
V_515 = F_233 ( V_278 ) ;
if ( V_515 < 0 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_515 ;
}
if ( V_515 ) {
V_519 = V_130 -> V_270 ;
F_234 (cmd, sg, use_sg, i) {
V_368 = ( T_5 ) F_230 ( V_263 ) ;
V_50 = F_231 ( V_263 ) ;
V_533 += V_50 ;
V_519 -> V_276 = F_127 ( V_368 ) ;
V_519 -> V_275 = F_132 ( V_50 ) ;
V_519 -> V_272 = F_132 ( 0 ) ;
V_519 ++ ;
}
( -- V_519 ) -> V_272 = F_132 ( V_370 ) ;
switch ( V_278 -> V_540 ) {
case V_541 :
V_534 |= V_542 ;
break;
case V_543 :
V_534 |= V_544 ;
break;
case V_545 :
V_534 |= V_546 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_278 -> V_540 ) ;
F_175 () ;
break;
}
} else {
V_534 |= V_546 ;
}
V_9 -> V_123 . V_124 = V_515 ;
V_130 -> V_547 = F_153 ( V_185 & 0xFFFF ) ;
V_130 -> V_548 = F_132 ( V_533 ) ;
V_130 -> V_340 = F_153 ( V_549 |
( V_522 & V_341 ) ) ;
V_130 -> V_534 = F_132 ( V_534 ) ;
memcpy ( V_130 -> V_144 , V_140 , V_522 ) ;
memcpy ( V_130 -> V_345 , V_72 , 8 ) ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_239 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
V_9 -> V_234 = V_30 ;
return F_240 ( V_22 , V_9 , V_30 -> V_185 ,
V_278 -> V_550 , V_278 -> V_537 , V_30 -> V_72 , V_30 ) ;
}
static void F_241 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_138 * V_130 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
struct V_219 * V_220 = & V_30 -> V_184 ;
T_5 V_551 ;
if ( ! ( F_96 ( V_220 -> V_78 ) & V_414 ) )
return;
V_130 -> V_415 = V_220 -> V_415 ;
V_130 -> V_552 |= V_553 ;
switch ( V_278 -> V_550 [ 0 ] ) {
case V_526 :
case V_528 :
V_551 = F_237 ( & V_278 -> V_550 [ 2 ] ) ;
break;
case V_531 :
case V_532 :
case V_527 :
case V_529 :
V_551 = F_189 ( & V_278 -> V_550 [ 2 ] ) ;
break;
case V_554 :
case V_555 :
V_551 = F_190 ( & V_278 -> V_550 [ 2 ] ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_162 ,
V_202 , V_278 -> V_550 [ 0 ] ) ;
F_175 () ;
break;
}
if ( F_124 ( V_220 -> V_407 ) != 512 )
V_551 = V_551 *
F_124 ( V_220 -> V_407 ) / 512 ;
V_130 -> V_556 = F_132 ( V_551 ) ;
V_130 -> V_557 = F_132 ( V_551 >> 32 ) ;
}
static int F_242 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_140 , int V_522 ,
T_1 * V_72 , struct V_73 * V_234 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_138 * V_130 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_259 * V_519 ;
int V_515 , V_68 ;
struct V_514 * V_263 ;
T_5 V_368 ;
T_4 V_50 ;
T_4 V_533 = 0 ;
F_75 ( F_152 ( V_278 ) > V_22 -> V_256 ) ;
if ( F_236 ( V_140 , & V_522 ) ) {
F_45 ( & V_234 -> V_250 ) ;
return V_530 ;
}
V_9 -> V_149 = V_153 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_558 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_559 = V_560 ;
V_515 = F_233 ( V_278 ) ;
if ( V_515 < 0 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_515 ;
}
if ( V_515 ) {
V_519 = V_130 -> V_263 ;
if ( V_515 > V_22 -> V_536 ) {
V_368 = F_129 (
V_22 -> V_253 [ V_9 -> V_132 ] -> V_266 ) ;
V_519 -> V_266 = F_127 ( V_368 ) ;
V_519 -> V_264 = 0 ;
V_519 -> V_561 [ 0 ] = 0 ;
V_519 -> V_561 [ 1 ] = 0 ;
V_519 -> V_561 [ 2 ] = 0 ;
V_519 -> V_334 = 0x80 ;
V_519 = V_22 -> V_253 [ V_9 -> V_132 ] ;
}
F_234 (cmd, sg, use_sg, i) {
V_368 = ( T_5 ) F_230 ( V_263 ) ;
V_50 = F_231 ( V_263 ) ;
V_533 += V_50 ;
V_519 -> V_266 = F_127 ( V_368 ) ;
V_519 -> V_264 = F_132 ( V_50 ) ;
V_519 -> V_561 [ 0 ] = 0 ;
V_519 -> V_561 [ 1 ] = 0 ;
V_519 -> V_561 [ 2 ] = 0 ;
V_519 -> V_334 = 0 ;
V_519 ++ ;
}
switch ( V_278 -> V_540 ) {
case V_541 :
V_130 -> V_552 &= ~ V_562 ;
V_130 -> V_552 |= V_563 ;
break;
case V_543 :
V_130 -> V_552 &= ~ V_562 ;
V_130 -> V_552 |= V_564 ;
break;
case V_545 :
V_130 -> V_552 &= ~ V_562 ;
V_130 -> V_552 |= V_565 ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_278 -> V_540 ) ;
F_175 () ;
break;
}
} else {
V_130 -> V_552 &= ~ V_562 ;
V_130 -> V_552 |= V_565 ;
}
F_241 ( V_22 , V_9 , V_130 ) ;
V_130 -> V_474 = F_132 ( V_185 ) ;
V_130 -> V_566 = F_132 ( V_9 -> V_132 << V_567 ) ;
memcpy ( V_130 -> V_140 , V_140 , sizeof( V_130 -> V_140 ) ) ;
V_130 -> V_280 = F_132 ( V_533 ) ;
V_130 -> V_568 = F_127 ( V_9 -> V_121 +
F_243 ( struct V_138 , V_283 ) ) ;
V_130 -> V_569 = F_132 ( sizeof( V_130 -> V_283 ) ) ;
if ( V_515 > V_22 -> V_536 ) {
V_130 -> V_139 = 1 ;
V_130 -> V_263 [ 0 ] . V_264 = F_132 ( V_515 * sizeof( V_130 -> V_263 [ 0 ] ) ) ;
if ( F_123 ( V_22 , V_130 , V_9 ) ) {
F_45 ( & V_234 -> V_250 ) ;
F_151 ( V_278 ) ;
return - 1 ;
}
} else
V_130 -> V_139 = ( T_1 ) V_515 ;
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_185 , T_1 * V_140 , int V_522 ,
T_1 * V_72 , struct V_73 * V_234 )
{
if ( F_178 ( & V_234 -> V_250 ) >
V_234 -> V_188 ) {
F_45 ( & V_234 -> V_250 ) ;
return V_530 ;
}
if ( V_22 -> V_63 & V_113 )
return F_238 ( V_22 , V_9 , V_185 ,
V_140 , V_522 , V_72 ,
V_234 ) ;
else
return F_242 ( V_22 , V_9 , V_185 ,
V_140 , V_522 , V_72 ,
V_234 ) ;
}
static void F_244 ( struct V_219 * V_220 ,
int V_187 , T_4 * V_570 , T_4 * V_571 )
{
if ( V_187 == 0 ) {
* V_570 %= F_96 ( V_220 -> V_225 ) ;
return;
}
do {
* V_571 = * V_570 /
F_96 ( V_220 -> V_225 ) ;
if ( V_187 == * V_571 )
continue;
if ( * V_571 < F_96 ( V_220 -> V_229 ) - 1 ) {
* V_570 += F_96 ( V_220 -> V_225 ) ;
( * V_571 ) ++ ;
} else {
* V_570 %= F_96 ( V_220 -> V_225 ) ;
* V_571 = 0 ;
}
} while ( V_187 != * V_571 );
}
static int F_245 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_277 * V_278 = V_9 -> V_10 ;
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
struct V_219 * V_220 = & V_30 -> V_184 ;
struct V_221 * V_222 = & V_220 -> V_223 [ 0 ] ;
int V_523 = 0 ;
T_4 V_570 ;
T_5 V_551 , V_572 ;
T_4 V_525 ;
T_4 V_573 ;
T_5 V_574 , V_575 ;
T_4 V_576 , V_577 ;
T_4 V_578 , V_579 ;
T_5 V_580 , V_581 ;
T_4 V_582 ;
T_5 V_583 , V_584 ;
T_4 V_585 , V_586 ;
T_4 V_587 , V_588 ;
T_4 V_224 ;
T_4 V_589 ;
T_4 V_590 , V_591 , V_571 ;
T_4 V_592 ;
T_4 V_593 ;
T_5 V_594 ;
T_4 V_595 ;
T_1 V_140 [ 16 ] ;
T_1 V_522 ;
T_6 V_411 ;
#if V_596 == 32
T_5 V_597 ;
#endif
int V_187 ;
switch ( V_278 -> V_550 [ 0 ] ) {
case V_526 :
V_523 = 1 ;
case V_528 :
V_551 = F_237 ( & V_278 -> V_550 [ 2 ] ) ;
V_525 = V_278 -> V_550 [ 4 ] ;
if ( V_525 == 0 )
V_525 = 256 ;
break;
case V_531 :
V_523 = 1 ;
case V_532 :
V_551 =
( ( ( T_5 ) V_278 -> V_550 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_550 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_550 [ 4 ] ) << 8 ) |
V_278 -> V_550 [ 5 ] ;
V_525 =
( ( ( T_4 ) V_278 -> V_550 [ 7 ] ) << 8 ) |
V_278 -> V_550 [ 8 ] ;
break;
case V_527 :
V_523 = 1 ;
case V_529 :
V_551 =
( ( ( T_5 ) V_278 -> V_550 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_550 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_550 [ 4 ] ) << 8 ) |
V_278 -> V_550 [ 5 ] ;
V_525 =
( ( ( T_4 ) V_278 -> V_550 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_278 -> V_550 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_278 -> V_550 [ 8 ] ) << 8 ) |
V_278 -> V_550 [ 9 ] ;
break;
case V_554 :
V_523 = 1 ;
case V_555 :
V_551 =
( ( ( T_5 ) V_278 -> V_550 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_278 -> V_550 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_278 -> V_550 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_278 -> V_550 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_278 -> V_550 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_278 -> V_550 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_278 -> V_550 [ 8 ] ) << 8 ) |
V_278 -> V_550 [ 9 ] ;
V_525 =
( ( ( T_4 ) V_278 -> V_550 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_278 -> V_550 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_278 -> V_550 [ 12 ] ) << 8 ) |
V_278 -> V_550 [ 13 ] ;
break;
default:
return V_530 ;
}
V_572 = V_551 + V_525 - 1 ;
if ( V_523 && V_30 -> V_83 != 0 )
return V_530 ;
if ( V_572 >= F_129 ( V_220 -> V_408 ) ||
V_572 < V_551 )
return V_530 ;
V_573 = F_96 ( V_220 -> V_225 ) *
F_96 ( V_220 -> V_411 ) ;
V_411 = F_96 ( V_220 -> V_411 ) ;
#if V_596 == 32
V_597 = V_551 ;
( void ) F_246 ( V_597 , V_573 ) ;
V_574 = V_597 ;
V_597 = V_572 ;
( void ) F_246 ( V_597 , V_573 ) ;
V_575 = V_597 ;
V_576 = ( T_4 ) ( V_551 - ( V_574 * V_573 ) ) ;
V_577 = ( T_4 ) ( V_572 - ( V_575 * V_573 ) ) ;
V_597 = V_576 ;
( void ) F_246 ( V_597 , V_411 ) ;
V_578 = V_597 ;
V_597 = V_577 ;
( void ) F_246 ( V_597 , V_411 ) ;
V_579 = V_597 ;
#else
V_574 = V_551 / V_573 ;
V_575 = V_572 / V_573 ;
V_576 = ( T_4 ) ( V_551 - ( V_574 * V_573 ) ) ;
V_577 = ( T_4 ) ( V_572 - ( V_575 * V_573 ) ) ;
V_578 = V_576 / V_411 ;
V_579 = V_577 / V_411 ;
#endif
if ( ( V_574 != V_575 ) || ( V_578 != V_579 ) )
return V_530 ;
V_224 = F_96 ( V_220 -> V_225 ) +
F_96 ( V_220 -> V_226 ) ;
V_592 = ( ( T_4 ) ( V_574 >> V_220 -> V_410 ) ) %
F_96 ( V_220 -> V_228 ) ;
V_570 = ( V_592 * V_224 ) + V_578 ;
switch ( V_30 -> V_83 ) {
case V_598 :
break;
case V_599 :
F_75 ( F_96 ( V_220 -> V_229 ) != 2 ) ;
if ( V_30 -> V_187 )
V_570 += F_96 ( V_220 -> V_225 ) ;
V_30 -> V_187 = ! V_30 -> V_187 ;
break;
case V_600 :
F_75 ( F_96 ( V_220 -> V_229 ) != 3 ) ;
V_187 = V_30 -> V_187 ;
F_244 ( V_220 , V_187 ,
& V_570 , & V_571 ) ;
V_187 =
( V_187 >=
F_96 ( V_220 -> V_229 ) - 1 )
? 0 : V_187 + 1 ;
V_30 -> V_187 = V_187 ;
break;
case V_601 :
case V_602 :
if ( F_96 ( V_220 -> V_229 ) <= 1 )
break;
V_582 =
F_96 ( V_220 -> V_411 ) *
F_96 ( V_220 -> V_225 ) ;
F_75 ( V_582 == 0 ) ;
V_589 = V_582 *
F_96 ( V_220 -> V_229 ) ;
#if V_596 == 32
V_597 = V_551 ;
V_590 = F_246 ( V_597 , V_589 ) ;
V_597 = V_590 ;
( void ) F_246 ( V_597 , V_582 ) ;
V_590 = V_597 ;
V_597 = V_572 ;
V_591 = F_246 ( V_597 , V_589 ) ;
V_597 = V_591 ;
( void ) F_246 ( V_597 , V_582 ) ;
V_591 = V_597 ;
#else
V_590 = ( V_551 % V_589 ) / V_582 ;
V_591 = ( V_572 % V_589 ) / V_582 ;
#endif
if ( V_590 != V_591 )
return V_530 ;
#if V_596 == 32
V_597 = V_551 ;
( void ) F_246 ( V_597 , V_589 ) ;
V_574 = V_583 = V_580 = V_597 ;
V_597 = V_572 ;
( void ) F_246 ( V_597 , V_589 ) ;
V_584 = V_581 = V_597 ;
#else
V_574 = V_583 = V_580 =
V_551 / V_589 ;
V_584 = V_581 = V_572 / V_589 ;
#endif
if ( V_583 != V_584 )
return V_530 ;
#if V_596 == 32
V_597 = V_551 ;
V_576 = F_246 ( V_597 , V_589 ) ;
V_597 = V_576 ;
V_576 = ( T_4 ) F_246 ( V_597 , V_582 ) ;
V_585 = V_576 ;
V_597 = V_572 ;
V_586 = F_246 ( V_597 , V_589 ) ;
V_597 = V_586 ;
V_586 = F_246 ( V_597 , V_582 ) ;
V_597 = V_585 ;
( void ) F_246 ( V_597 , V_220 -> V_411 ) ;
V_578 = V_587 = V_597 ;
V_597 = V_586 ;
( void ) F_246 ( V_597 , V_220 -> V_411 ) ;
V_588 = V_597 ;
#else
V_576 = V_585 =
( T_4 ) ( ( V_551 % V_589 ) %
V_582 ) ;
V_586 =
( T_4 ) ( ( V_572 % V_589 ) %
V_582 ) ;
V_578 = V_587 =
V_585 / F_96 ( V_220 -> V_411 ) ;
V_588 =
V_586 / F_96 ( V_220 -> V_411 ) ;
#endif
if ( V_587 != V_588 )
return V_530 ;
V_592 = ( ( T_4 ) ( V_574 >> V_220 -> V_410 ) ) %
F_96 ( V_220 -> V_228 ) ;
V_570 = ( V_590 *
( F_96 ( V_220 -> V_228 ) * V_224 ) ) +
( V_592 * V_224 ) + V_578 ;
break;
default:
return V_530 ;
}
if ( F_44 ( V_570 >= V_232 ) )
return V_530 ;
V_9 -> V_234 = V_30 -> V_234 [ V_570 ] ;
V_593 = V_222 [ V_570 ] . V_185 ;
V_594 = F_129 ( V_220 -> V_412 ) +
V_574 * F_96 ( V_220 -> V_411 ) +
( V_576 - V_578 *
F_96 ( V_220 -> V_411 ) ) ;
V_595 = V_525 ;
if ( V_220 -> V_409 ) {
V_594 <<= V_220 -> V_409 ;
V_595 <<= V_220 -> V_409 ;
}
F_75 ( V_595 > 0xffff ) ;
if ( V_594 > 0xffffffff ) {
V_140 [ 0 ] = V_523 ? V_554 : V_555 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_594 >> 56 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_594 >> 48 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_594 >> 40 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_594 >> 32 ) ;
V_140 [ 6 ] = ( T_1 ) ( V_594 >> 24 ) ;
V_140 [ 7 ] = ( T_1 ) ( V_594 >> 16 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_594 >> 8 ) ;
V_140 [ 9 ] = ( T_1 ) ( V_594 ) ;
V_140 [ 10 ] = ( T_1 ) ( V_595 >> 24 ) ;
V_140 [ 11 ] = ( T_1 ) ( V_595 >> 16 ) ;
V_140 [ 12 ] = ( T_1 ) ( V_595 >> 8 ) ;
V_140 [ 13 ] = ( T_1 ) ( V_595 ) ;
V_140 [ 14 ] = 0 ;
V_140 [ 15 ] = 0 ;
V_522 = 16 ;
} else {
V_140 [ 0 ] = V_523 ? V_531 : V_532 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_594 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_594 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_594 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_594 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_595 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_595 ) ;
V_140 [ 9 ] = 0 ;
V_522 = 10 ;
}
return F_240 ( V_22 , V_9 , V_593 , V_140 , V_522 ,
V_30 -> V_72 ,
V_30 -> V_234 [ V_570 ] ) ;
}
static int F_247 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
unsigned char V_72 [] )
{
V_278 -> V_603 = ( unsigned char * ) V_9 ;
V_9 -> V_149 = V_333 ;
V_9 -> V_10 = V_278 ;
V_9 -> V_123 . V_127 = 0 ;
memcpy ( & V_9 -> V_123 . V_343 . V_344 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_123 . V_342 = F_127 ( ( V_9 -> V_132 << V_567 ) ) ;
V_9 -> V_143 . V_604 = 0 ;
F_75 ( V_278 -> V_537 > sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_339 = V_278 -> V_537 ;
memcpy ( V_9 -> V_143 . V_144 , V_278 -> V_550 , V_278 -> V_537 ) ;
switch ( V_278 -> V_540 ) {
case V_541 :
V_9 -> V_143 . V_605 =
F_248 ( V_387 , V_606 , V_607 ) ;
break;
case V_543 :
V_9 -> V_143 . V_605 =
F_248 ( V_387 , V_606 , V_608 ) ;
break;
case V_545 :
V_9 -> V_143 . V_605 =
F_248 ( V_387 , V_606 , V_609 ) ;
break;
case V_610 :
V_9 -> V_143 . V_605 =
F_248 ( V_387 , V_606 , V_611 ) ;
break;
default:
F_73 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_278 -> V_540 ) ;
F_175 () ;
break;
}
if ( F_232 ( V_22 , V_9 , V_278 ) < 0 ) {
F_140 ( V_22 , V_9 ) ;
return V_612 ;
}
F_60 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_249 ( struct V_1 * V_22 , int V_197 ,
struct V_8 * V_9 )
{
V_366 V_613 , V_614 ;
memset ( V_9 , 0 , F_243 ( struct V_8 , V_399 ) ) ;
V_9 -> V_123 . V_342 = F_127 ( ( T_5 ) ( V_197 << V_567 ) ) ;
V_613 = V_22 -> V_615 + V_197 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_616 + V_197 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_614 = V_22 -> V_617
+ V_197 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_132 = V_197 ;
V_9 -> V_121 = ( T_4 ) V_613 ;
V_9 -> V_618 . V_276 = F_127 ( ( T_5 ) V_614 ) ;
V_9 -> V_618 . V_275 = F_132 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_250 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_398 + V_68 ;
F_249 ( V_22 , V_68 , V_9 ) ;
F_115 ( & V_9 -> V_399 , 0 ) ;
}
}
static inline void F_251 ( struct V_1 * V_22 , int V_197 ,
struct V_8 * V_9 )
{
V_366 V_613 = V_22 -> V_615 + V_197 * sizeof( * V_9 ) ;
F_75 ( V_9 -> V_132 != V_197 ) ;
memset ( V_9 -> V_143 . V_144 , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_121 = ( T_4 ) V_613 ;
}
static int F_252 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_277 * V_278 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_278 -> V_42 -> V_80 ;
int V_21 = V_530 ;
V_278 -> V_603 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_89 ) {
F_249 ( V_22 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_333 ;
V_9 -> V_10 = V_278 ;
V_21 = F_245 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_612 ;
} else if ( V_30 -> V_186 ) {
F_249 ( V_22 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_333 ;
V_9 -> V_10 = V_278 ;
V_21 = F_239 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_612 ;
}
return V_21 ;
}
static void V_319 ( struct V_619 * V_318 )
{
struct V_277 * V_278 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_253 ( V_318 , struct V_8 , V_318 ) ;
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
if ( V_9 -> V_149 == V_153 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_138 * V_279 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
int V_21 ;
if ( V_279 -> V_283 . V_284 ==
V_297 ) {
V_21 = F_252 ( V_22 , V_9 , V_278 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_612 ) {
V_278 -> V_288 = V_620 << 16 ;
return F_142 ( V_22 , V_9 , V_278 ) ;
}
}
}
F_251 ( V_9 -> V_22 , V_9 -> V_132 , V_9 ) ;
if ( F_247 ( V_9 -> V_22 , V_9 , V_278 , V_30 -> V_72 ) ) {
V_278 -> V_288 = V_620 << 16 ;
V_278 -> V_317 ( V_278 ) ;
}
}
static int F_254 ( struct V_6 * V_7 , struct V_277 * V_278 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_278 -> V_42 ) ;
F_75 ( V_278 -> V_621 -> V_342 < 0 ) ;
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
V_9 = F_255 ( V_22 , V_278 ) ;
if ( F_47 ( V_278 -> V_622 == 0 &&
V_278 -> V_621 -> V_149 == V_623 &&
V_22 -> V_56 ) ) {
V_21 = F_252 ( V_22 , V_9 , V_278 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_612 ) {
F_140 ( V_22 , V_9 ) ;
return V_612 ;
}
}
return F_247 ( V_22 , V_9 , V_278 , V_72 ) ;
}
static void F_256 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_624 , V_78 ) ;
V_22 -> V_625 = 1 ;
F_139 ( & V_22 -> V_626 ) ;
F_36 ( & V_22 -> V_624 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_256 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_624 , V_78 ) ;
if ( V_22 -> V_625 )
break;
F_36 ( & V_22 -> V_624 , V_78 ) ;
F_179 ( V_22 -> V_626 , V_22 -> V_625 ) ;
}
V_22 -> V_625 = 0 ;
F_36 ( & V_22 -> V_624 , V_78 ) ;
if ( F_44 ( F_13 ( V_22 ) ) )
return F_256 ( V_22 ) ;
F_226 ( V_22 ) ;
F_256 ( V_22 ) ;
}
static int F_257 ( struct V_2 * V_3 , int V_231 )
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
static int F_258 ( struct V_6 * V_7 ,
unsigned long V_627 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_628 ;
F_35 ( & V_22 -> V_624 , V_78 ) ;
V_628 = V_22 -> V_625 ;
F_36 ( & V_22 -> V_624 , V_78 ) ;
return V_628 ;
}
static int F_259 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_260 ( & V_629 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_163 ) ;
return - V_255 ;
}
V_7 -> V_630 = 0 ;
V_7 -> V_631 = 0 ;
V_7 -> V_632 = - 1 ;
V_7 -> V_633 = 3 ;
V_7 -> V_634 = V_635 ;
V_7 -> V_636 = V_482 ;
V_7 -> V_637 = V_482 ;
V_7 -> V_252 = V_22 -> V_235 - V_638 ;
V_7 -> V_639 = V_7 -> V_252 ;
V_7 -> V_640 = V_22 -> V_256 ;
V_7 -> V_641 = V_642 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_643 = V_22 -> V_644 [ V_22 -> V_645 ] ;
V_7 -> V_646 = V_7 -> V_643 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_261 ( struct V_1 * V_22 )
{
int V_647 ;
V_647 = F_262 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_647 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_164 ) ;
return V_647 ;
}
F_263 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_264 ( struct V_277 * V_648 )
{
int V_649 = V_648 -> V_621 -> V_342 ;
if ( V_649 < 0 )
return V_649 ;
return V_649 += V_638 ;
}
static int F_265 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_650 [] ,
int V_112 )
{
int V_21 ;
( void ) F_171 ( V_9 , V_457 , V_22 ,
NULL , 0 , 0 , V_650 , V_387 ) ;
V_21 = F_161 ( V_22 , V_9 , V_112 , V_374 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_651 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_289 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_652 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_266 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_650 [] , int V_112 )
{
int V_21 ;
int V_48 = 0 ;
int V_653 = 1 ;
for ( V_48 = 0 ; V_48 < V_654 ; V_48 ++ ) {
F_166 ( 1000 * V_653 ) ;
V_21 = F_265 ( V_22 , V_9 , V_650 , V_112 ) ;
if ( ! V_21 )
break;
if ( V_653 < V_655 )
V_653 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_165 ,
V_653 ) ;
}
return V_21 ;
}
static int F_267 ( struct V_1 * V_22 ,
unsigned char V_650 [] ,
int V_112 )
{
int V_656 ;
int V_657 ;
int V_111 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
if ( V_112 == V_126 ) {
V_656 = 0 ;
V_657 = V_22 -> V_128 - 1 ;
} else {
V_656 = V_112 ;
V_657 = V_112 ;
}
for ( V_111 = V_656 ; V_111 <= V_657 ; V_111 ++ ) {
V_21 = F_266 ( V_22 , V_9 , V_650 , V_111 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_166 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_167 ) ;
F_172 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_268 ( struct V_277 * V_658 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_390 ;
char V_659 [ 48 ] ;
V_22 = F_1 ( V_658 -> V_42 ) ;
if ( V_22 == NULL )
return V_660 ;
if ( F_13 ( V_22 ) )
return V_660 ;
V_30 = V_658 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_168 , V_202 ) ;
return V_660 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_659 , sizeof( V_659 ) ,
L_169 ,
F_264 ( V_658 ) ) ;
F_69 ( V_237 , V_22 , V_30 , V_659 ) ;
return V_660 ;
}
if ( F_269 ( V_22 ) ) {
snprintf ( V_659 , sizeof( V_659 ) ,
L_170 ,
F_264 ( V_658 ) ) ;
F_69 ( V_237 , V_22 , V_30 , V_659 ) ;
return V_660 ;
}
if ( F_62 ( V_30 -> V_72 ) )
return V_661 ;
if ( F_31 ( V_30 -> V_72 ) )
V_390 = V_662 ;
else
V_390 = V_663 ;
sprintf ( V_659 , L_171 ,
V_390 == V_662 ? L_172 : L_173 ) ;
F_69 ( V_237 , V_22 , V_30 , V_659 ) ;
V_22 -> V_242 = 1 ;
V_21 = F_176 ( V_22 , V_30 , V_30 -> V_72 , V_390 ,
V_126 ) ;
sprintf ( V_659 , L_174 ,
V_390 == V_662 ? L_172 : L_173 ,
V_21 == 0 ? L_175 : L_176 ) ;
F_69 ( V_237 , V_22 , V_30 , V_659 ) ;
V_22 -> V_242 = 0 ;
return V_21 == 0 ? V_661 : V_660 ;
}
static void F_270 ( T_1 * V_342 )
{
T_1 V_664 [ 8 ] ;
memcpy ( V_664 , V_342 , 8 ) ;
V_342 [ 0 ] = V_664 [ 3 ] ;
V_342 [ 1 ] = V_664 [ 2 ] ;
V_342 [ 2 ] = V_664 [ 1 ] ;
V_342 [ 3 ] = V_664 [ 0 ] ;
V_342 [ 4 ] = V_664 [ 7 ] ;
V_342 [ 5 ] = V_664 [ 6 ] ;
V_342 [ 6 ] = V_664 [ 5 ] ;
V_342 [ 7 ] = V_664 [ 4 ] ;
}
static void F_271 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_665 , T_7 * V_666 )
{
T_5 V_342 ;
if ( V_9 -> V_149 == V_150 ) {
struct V_129 * V_667 = (struct V_129 * )
& V_22 -> V_131 [ V_9 -> V_132 ] ;
V_342 = F_129 ( V_667 -> V_342 ) ;
* V_666 = F_132 ( V_342 >> 32 ) ;
* V_665 = F_132 ( V_342 ) ;
return;
}
if ( V_9 -> V_149 == V_153 ) {
struct V_138 * V_668 = (struct V_138 * )
& V_22 -> V_136 [ V_9 -> V_132 ] ;
memset ( V_666 , 0 , sizeof( * V_666 ) ) ;
* V_665 = V_668 -> V_566 ;
return;
}
V_342 = F_129 ( V_9 -> V_123 . V_342 ) ;
* V_666 = F_132 ( V_342 >> 32 ) ;
* V_665 = F_132 ( V_342 ) ;
}
static int F_272 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_112 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
struct V_330 * V_331 ;
T_7 V_666 , V_665 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_459 , V_22 , & abort -> V_123 . V_342 ,
0 , 0 , V_72 , V_391 ) ;
if ( V_22 -> V_71 )
F_270 ( & V_9 -> V_143 . V_144 [ 4 ] ) ;
( void ) F_161 ( V_22 , V_9 , V_112 , V_374 ) ;
F_271 ( V_22 , abort , & V_665 , & V_666 ) ;
F_273 ( & V_22 -> V_29 -> V_30 , L_177 ,
V_202 , V_666 , V_665 ) ;
V_331 = V_9 -> V_24 ;
switch ( V_331 -> V_36 ) {
case V_651 :
break;
case V_362 :
V_21 = F_149 ( V_22 , V_9 ) ;
break;
case V_361 :
V_21 = - 1 ;
break;
default:
F_273 ( & V_22 -> V_29 -> V_30 , L_178 ,
V_202 , V_666 , V_665 ) ;
F_168 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_172 ( V_22 , V_9 ) ;
F_273 ( & V_22 -> V_29 -> V_30 , L_179 ,
V_202 , V_666 , V_665 ) ;
return V_21 ;
}
static void F_274 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_669 , int V_112 )
{
struct V_138 * V_279 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
struct V_135 * V_393 = (struct V_135 * ) V_279 ;
struct V_138 * V_670 =
& V_22 -> V_136 [ V_669 -> V_132 ] ;
struct V_277 * V_648 = V_669 -> V_10 ;
struct V_73 * V_30 = V_648 -> V_42 -> V_80 ;
F_275 ( sizeof( struct V_135 ) >
sizeof( struct V_138 ) ) ;
F_75 ( F_243 ( struct V_138 , V_283 ) <
F_243 ( struct V_135 , V_671 ) +
sizeof( V_393 -> V_671 ) ) ;
V_9 -> V_149 = V_155 ;
V_9 -> V_10 = V_672 ;
V_9 -> V_121 = ( T_4 ) V_22 -> V_558 +
( V_9 -> V_132 * sizeof( struct V_138 ) ) ;
F_75 ( V_9 -> V_121 & 0x0000007F ) ;
memset ( V_393 , 0 , sizeof( * V_279 ) ) ;
V_393 -> V_673 = V_674 ;
V_393 -> V_112 = V_112 ;
V_393 -> V_675 = V_676 ;
V_393 -> V_395 = F_132 ( V_30 -> V_185 ) ;
memset ( V_393 -> V_677 , 0 , sizeof( V_393 -> V_677 ) ) ;
V_393 -> V_342 = F_127 ( V_9 -> V_132 << V_567 ) ;
V_393 -> V_678 = F_127 ( F_124 ( V_670 -> V_566 ) ) ;
V_393 -> V_679 = F_127 ( V_9 -> V_121 +
F_243 ( struct V_138 , V_283 ) ) ;
V_393 -> V_671 = F_132 ( sizeof( V_279 -> V_283 ) ) ;
}
static int F_276 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_112 )
{
int V_21 = V_375 ;
struct V_277 * V_648 ;
struct V_73 * V_30 ;
unsigned char V_680 [ 8 ] ;
unsigned char * V_681 = & V_680 [ 0 ] ;
V_648 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_648 -> V_42 -> V_80 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_180 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_181 ,
V_22 -> V_59 -> V_100 , V_30 -> V_101 , V_30 -> V_102 , V_30 -> V_103 ,
L_182 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_89 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_183 ) ;
return - 1 ;
}
if ( ! F_215 ( V_22 , abort , V_681 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_184 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_185 ,
V_681 [ 0 ] , V_681 [ 1 ] , V_681 [ 2 ] , V_681 [ 3 ] ,
V_681 [ 4 ] , V_681 [ 5 ] , V_681 [ 6 ] , V_681 [ 7 ] ) ;
V_21 = F_176 ( V_22 , V_30 , V_681 , V_682 , V_112 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_186 ,
V_681 [ 0 ] , V_681 [ 1 ] , V_681 [ 2 ] , V_681 [ 3 ] ,
V_681 [ 4 ] , V_681 [ 5 ] , V_681 [ 6 ] , V_681 [ 7 ] ) ;
return V_21 ;
}
if ( F_267 ( V_22 , V_681 , V_112 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_681 [ 0 ] , V_681 [ 1 ] , V_681 [ 2 ] , V_681 [ 3 ] ,
V_681 [ 4 ] , V_681 [ 5 ] , V_681 [ 6 ] , V_681 [ 7 ] ) ;
return - 1 ;
}
F_94 ( & V_22 -> V_29 -> V_30 ,
L_188 ,
V_681 [ 0 ] , V_681 [ 1 ] , V_681 [ 2 ] , V_681 [ 3 ] ,
V_681 [ 4 ] , V_681 [ 5 ] , V_681 [ 6 ] , V_681 [ 7 ] ) ;
return V_21 ;
}
static int F_277 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_112 )
{
int V_21 = V_375 ;
struct V_8 * V_9 ;
T_7 V_665 , V_666 ;
struct V_73 * V_30 ;
struct V_138 * V_279 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 -> V_89 && ! V_30 -> V_186 )
return - 1 ;
V_9 = F_170 ( V_22 ) ;
F_274 ( V_9 , V_22 , abort , V_112 ) ;
V_279 = & V_22 -> V_136 [ V_9 -> V_132 ] ;
( void ) F_161 ( V_22 , V_9 , V_112 , V_374 ) ;
F_271 ( V_22 , abort , & V_665 , & V_666 ) ;
F_273 ( & V_22 -> V_29 -> V_30 ,
L_189 ,
V_202 , V_666 , V_665 ) ;
F_273 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_202 , V_666 , V_665 , V_279 -> V_283 . V_284 ) ;
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
L_191 ,
V_202 , V_666 , V_665 ,
V_279 -> V_283 . V_284 ) ;
V_21 = - 1 ;
}
F_172 ( V_22 , V_9 ) ;
F_273 ( & V_22 -> V_29 -> V_30 , L_179 , V_202 ,
V_666 , V_665 ) ;
return V_21 ;
}
static int F_278 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_112 )
{
if ( abort -> V_149 == V_153 ) {
if ( V_683 & V_22 -> V_684 )
return F_277 ( V_22 , abort ,
V_112 ) ;
else
return F_276 ( V_22 , V_72 ,
abort , V_112 ) ;
}
return F_272 ( V_22 , V_72 , abort , V_112 ) ;
}
static int F_279 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_149 == V_153 )
return V_22 -> V_136 [ V_9 -> V_132 ] . V_112 ;
return V_9 -> V_123 . V_127 ;
}
static inline int F_280 ( struct V_1 * V_22 )
{
#define F_281 5000
return ! F_282 ( V_22 -> V_685 ,
F_283 ( & V_22 -> V_686 ) >= 0 ,
F_160 ( F_281 ) ) ;
}
static int F_284 ( struct V_277 * V_687 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_277 * V_688 ;
char V_659 [ 256 ] ;
int V_689 = 0 ;
T_7 V_666 , V_665 ;
int V_399 , V_112 ;
if ( V_687 == NULL )
return V_660 ;
if ( V_687 -> V_42 == NULL )
return V_660 ;
V_22 = F_1 ( V_687 -> V_42 ) ;
if ( V_22 == NULL )
return V_660 ;
V_30 = V_687 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_192 ,
V_659 ) ;
return V_660 ;
}
if ( F_13 ( V_22 ) ) {
F_69 ( V_237 , V_22 , V_30 ,
L_193 ) ;
return V_660 ;
}
if ( F_269 ( V_22 ) ) {
F_69 ( V_237 , V_22 , V_30 ,
L_194 ) ;
return V_660 ;
}
if ( ! ( V_690 & V_22 -> V_684 ) &&
! ( V_691 & V_22 -> V_684 ) )
return V_660 ;
memset ( V_659 , 0 , sizeof( V_659 ) ) ;
V_689 += sprintf ( V_659 + V_689 , L_195 ,
V_22 -> V_59 -> V_100 , V_687 -> V_42 -> V_692 ,
V_687 -> V_42 -> V_693 , V_687 -> V_42 -> V_103 ,
L_196 , V_687 ) ;
abort = (struct V_8 * ) V_687 -> V_603 ;
if ( abort == NULL ) {
return V_661 ;
}
V_399 = F_178 ( & abort -> V_399 ) ;
if ( V_399 == 1 ) {
F_172 ( V_22 , abort ) ;
return V_661 ;
}
if ( abort -> V_149 != V_153 &&
abort -> V_149 != V_150 && ! V_30 -> V_468 ) {
F_172 ( V_22 , abort ) ;
return V_660 ;
}
if ( abort -> V_10 != V_687 ) {
F_172 ( V_22 , abort ) ;
return V_661 ;
}
abort -> V_12 = true ;
F_271 ( V_22 , abort , & V_665 , & V_666 ) ;
V_112 = F_279 ( V_22 , abort ) ;
V_689 += sprintf ( V_659 + V_689 , L_197 , V_666 , V_665 ) ;
V_688 = abort -> V_10 ;
if ( V_688 != NULL )
V_689 += sprintf ( V_659 + V_689 ,
L_198 ,
V_688 -> V_537 , V_688 -> V_550 [ 0 ] , V_688 -> V_550 [ 1 ] ,
V_688 -> V_694 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_199 , V_659 ) ;
F_69 ( V_237 , V_22 , V_30 , L_196 ) ;
if ( F_280 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_200 ,
V_659 ) ;
F_172 ( V_22 , abort ) ;
return V_660 ;
}
V_21 = F_278 ( V_22 , V_30 -> V_72 , abort , V_112 ) ;
F_55 ( & V_22 -> V_686 ) ;
F_139 ( & V_22 -> V_685 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_201 , V_659 ) ;
F_69 ( V_237 , V_22 , V_30 ,
L_202 ) ;
F_172 ( V_22 , abort ) ;
return V_660 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_203 , V_659 ) ;
F_179 ( V_22 -> V_316 ,
abort -> V_10 != V_687 || F_13 ( V_22 ) ) ;
F_172 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_661 : V_660 ;
}
static struct V_8 * F_255 ( struct V_1 * V_22 ,
struct V_277 * V_648 )
{
int V_649 = F_264 ( V_648 ) ;
struct V_8 * V_9 = V_22 -> V_398 + V_649 ;
if ( V_649 < V_638 || V_649 >= V_22 -> V_235 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_204 ,
V_649 , V_638 , V_22 -> V_235 - 1 ) ;
F_175 () ;
}
F_55 ( & V_9 -> V_399 ) ;
if ( F_44 ( ! F_4 ( V_9 ) ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_205 ,
V_649 ) ;
if ( V_9 -> V_10 != NULL )
F_285 ( V_9 -> V_10 ) ;
F_285 ( V_648 ) ;
}
F_251 ( V_22 , V_649 , V_9 ) ;
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
int V_695 = 0 ;
for (; ; ) {
V_68 = F_286 ( V_22 -> V_696 ,
V_638 ,
V_695 ) ;
if ( F_44 ( V_68 >= V_638 ) ) {
V_695 = 0 ;
continue;
}
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( F_44 ( V_399 > 1 ) ) {
F_172 ( V_22 , V_9 ) ;
V_695 = ( V_68 + 1 ) % V_638 ;
continue;
}
F_287 ( V_68 & ( V_596 - 1 ) ,
V_22 -> V_696 + ( V_68 / V_596 ) ) ;
break;
}
F_251 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_172 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_57 ( & V_9 -> V_399 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_398 ;
F_288 ( V_68 & ( V_596 - 1 ) ,
V_22 -> V_696 + ( V_68 / V_596 ) ) ;
}
}
static int F_289 ( struct V_2 * V_30 , int V_278 ,
void T_8 * V_697 )
{
T_9 T_8 * V_698 =
( T_9 T_8 * ) V_697 ;
T_10 V_699 ;
T_10 T_8 * V_700 = F_290 ( sizeof( V_699 ) ) ;
int V_701 ;
T_4 V_130 ;
memset ( & V_699 , 0 , sizeof( V_699 ) ) ;
V_701 = 0 ;
V_701 |= F_291 ( & V_699 . V_702 , & V_698 -> V_702 ,
sizeof( V_699 . V_702 ) ) ;
V_701 |= F_291 ( & V_699 . V_143 , & V_698 -> V_143 ,
sizeof( V_699 . V_143 ) ) ;
V_701 |= F_291 ( & V_699 . V_703 , & V_698 -> V_703 ,
sizeof( V_699 . V_703 ) ) ;
V_701 |= F_292 ( V_699 . V_704 , & V_698 -> V_704 ) ;
V_701 |= F_292 ( V_130 , & V_698 -> V_45 ) ;
V_699 . V_45 = F_293 ( V_130 ) ;
V_701 |= F_294 ( V_700 , & V_699 , sizeof( V_699 ) ) ;
if ( V_701 )
return - V_705 ;
V_701 = F_295 ( V_30 , V_706 , V_700 ) ;
if ( V_701 )
return V_701 ;
V_701 |= F_296 ( & V_698 -> V_703 , & V_700 -> V_703 ,
sizeof( V_698 -> V_703 ) ) ;
if ( V_701 )
return - V_705 ;
return V_701 ;
}
static int F_297 ( struct V_2 * V_30 ,
int V_278 , void T_8 * V_697 )
{
T_11 T_8 * V_698 =
( T_11 T_8 * ) V_697 ;
T_12 V_699 ;
T_12 T_8 * V_700 =
F_290 ( sizeof( V_699 ) ) ;
int V_701 ;
T_4 V_130 ;
memset ( & V_699 , 0 , sizeof( V_699 ) ) ;
V_701 = 0 ;
V_701 |= F_291 ( & V_699 . V_702 , & V_698 -> V_702 ,
sizeof( V_699 . V_702 ) ) ;
V_701 |= F_291 ( & V_699 . V_143 , & V_698 -> V_143 ,
sizeof( V_699 . V_143 ) ) ;
V_701 |= F_291 ( & V_699 . V_703 , & V_698 -> V_703 ,
sizeof( V_699 . V_703 ) ) ;
V_701 |= F_292 ( V_699 . V_704 , & V_698 -> V_704 ) ;
V_701 |= F_292 ( V_699 . V_707 , & V_698 -> V_707 ) ;
V_701 |= F_292 ( V_130 , & V_698 -> V_45 ) ;
V_699 . V_45 = F_293 ( V_130 ) ;
V_701 |= F_294 ( V_700 , & V_699 , sizeof( V_699 ) ) ;
if ( V_701 )
return - V_705 ;
V_701 = F_295 ( V_30 , V_708 , V_700 ) ;
if ( V_701 )
return V_701 ;
V_701 |= F_296 ( & V_698 -> V_703 , & V_700 -> V_703 ,
sizeof( V_698 -> V_703 ) ) ;
if ( V_701 )
return - V_705 ;
return V_701 ;
}
static int F_298 ( struct V_2 * V_30 , int V_278 , void T_8 * V_697 )
{
switch ( V_278 ) {
case V_709 :
case V_710 :
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
case V_716 :
case V_717 :
case V_718 :
case V_719 :
case V_720 :
case V_721 :
case V_722 :
case V_723 :
return F_295 ( V_30 , V_278 , V_697 ) ;
case V_724 :
return F_289 ( V_30 , V_278 , V_697 ) ;
case V_725 :
return F_297 ( V_30 , V_278 , V_697 ) ;
default:
return - V_726 ;
}
}
static int F_299 ( struct V_1 * V_22 , void T_8 * V_727 )
{
struct V_728 V_729 ;
if ( ! V_727 )
return - V_55 ;
V_729 . V_730 = F_300 ( V_22 -> V_29 -> V_101 ) ;
V_729 . V_101 = V_22 -> V_29 -> V_101 -> V_731 ;
V_729 . V_732 = V_22 -> V_29 -> V_733 ;
V_729 . V_67 = V_22 -> V_67 ;
if ( F_294 ( V_727 , & V_729 , sizeof( V_729 ) ) )
return - V_705 ;
return 0 ;
}
static int F_301 ( struct V_1 * V_22 , void T_8 * V_727 )
{
T_13 V_734 ;
unsigned char V_735 , V_736 , V_737 ;
int V_21 ;
V_21 = sscanf ( V_738 , L_206 ,
& V_735 , & V_736 , & V_737 ) ;
if ( V_21 != 3 ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_207
L_208 , V_738 ) ;
V_735 = 0 ;
V_736 = 0 ;
V_737 = 0 ;
}
V_734 = ( V_735 << 16 ) | ( V_736 << 8 ) | V_737 ;
if ( ! V_727 )
return - V_55 ;
if ( F_294 ( V_727 , & V_734 , sizeof( T_13 ) ) )
return - V_705 ;
return 0 ;
}
static int F_302 ( struct V_1 * V_22 , void T_8 * V_727 )
{
T_10 V_739 ;
struct V_8 * V_9 ;
char * V_740 = NULL ;
T_5 V_261 ;
int V_21 = 0 ;
if ( ! V_727 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_741 ;
if ( F_291 ( & V_739 , V_727 , sizeof( V_739 ) ) )
return - V_705 ;
if ( ( V_739 . V_704 < 1 ) &&
( V_739 . V_143 . Type . V_742 != V_609 ) ) {
return - V_55 ;
}
if ( V_739 . V_704 > 0 ) {
V_740 = F_91 ( V_739 . V_704 , V_201 ) ;
if ( V_740 == NULL )
return - V_255 ;
if ( V_739 . V_143 . Type . V_742 & V_607 ) {
if ( F_291 ( V_740 , V_739 . V_45 ,
V_739 . V_704 ) ) {
V_21 = - V_705 ;
goto V_743;
}
} else {
memset ( V_740 , 0 , V_739 . V_704 ) ;
}
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_149 = V_394 ;
V_9 -> V_10 = V_672 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_739 . V_704 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_274 = F_153 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_274 = F_153 ( 0 ) ;
}
memcpy ( & V_9 -> V_123 . V_343 , & V_739 . V_702 , sizeof( V_9 -> V_123 . V_343 ) ) ;
memcpy ( & V_9 -> V_143 , & V_739 . V_143 ,
sizeof( V_9 -> V_143 ) ) ;
if ( V_739 . V_704 > 0 ) {
V_261 = F_125 ( V_22 -> V_29 , V_740 ,
V_739 . V_704 , V_744 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 , ( V_366 ) V_261 ) ) {
V_9 -> V_270 [ 0 ] . V_276 = F_127 ( 0 ) ;
V_9 -> V_270 [ 0 ] . V_275 = F_132 ( 0 ) ;
V_21 = - V_255 ;
goto V_388;
}
V_9 -> V_270 [ 0 ] . V_276 = F_127 ( V_261 ) ;
V_9 -> V_270 [ 0 ] . V_275 = F_132 ( V_739 . V_704 ) ;
V_9 -> V_270 [ 0 ] . V_272 = F_132 ( V_370 ) ;
}
V_21 = F_161 ( V_22 , V_9 , V_126 , V_374 ) ;
if ( V_739 . V_704 > 0 )
F_154 ( V_22 -> V_29 , V_9 , 1 , V_744 ) ;
F_303 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_381 ;
goto V_388;
}
memcpy ( & V_739 . V_703 , V_9 -> V_24 ,
sizeof( V_739 . V_703 ) ) ;
if ( F_294 ( V_727 , & V_739 , sizeof( V_739 ) ) ) {
V_21 = - V_705 ;
goto V_388;
}
if ( ( V_739 . V_143 . Type . V_742 & V_608 ) &&
V_739 . V_704 > 0 ) {
if ( F_294 ( V_739 . V_45 , V_740 , V_739 . V_704 ) ) {
V_21 = - V_705 ;
goto V_388;
}
}
V_388:
F_172 ( V_22 , V_9 ) ;
V_743:
F_80 ( V_740 ) ;
return V_21 ;
}
static int F_304 ( struct V_1 * V_22 , void T_8 * V_727 )
{
T_12 * V_745 ;
struct V_8 * V_9 ;
unsigned char * * V_740 = NULL ;
int * V_746 = NULL ;
T_5 V_261 ;
T_14 V_364 = 0 ;
int V_49 = 0 ;
T_4 V_747 ;
T_4 V_748 ;
T_14 T_8 * V_749 ;
if ( ! V_727 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_741 ;
V_745 = ( T_12 * )
F_91 ( sizeof( * V_745 ) , V_201 ) ;
if ( ! V_745 ) {
V_49 = - V_255 ;
goto V_750;
}
if ( F_291 ( V_745 , V_727 , sizeof( * V_745 ) ) ) {
V_49 = - V_705 ;
goto V_750;
}
if ( ( V_745 -> V_704 < 1 ) &&
( V_745 -> V_143 . Type . V_742 != V_609 ) ) {
V_49 = - V_55 ;
goto V_750;
}
if ( V_745 -> V_707 > V_751 ) {
V_49 = - V_55 ;
goto V_750;
}
if ( V_745 -> V_704 > V_745 -> V_707 * V_752 ) {
V_49 = - V_55 ;
goto V_750;
}
V_740 = F_108 ( V_752 * sizeof( char * ) , V_201 ) ;
if ( ! V_740 ) {
V_49 = - V_255 ;
goto V_750;
}
V_746 = F_91 ( V_752 * sizeof( int ) , V_201 ) ;
if ( ! V_746 ) {
V_49 = - V_255 ;
goto V_750;
}
V_747 = V_745 -> V_704 ;
V_749 = V_745 -> V_45 ;
while ( V_747 ) {
V_748 = ( V_747 > V_745 -> V_707 ) ? V_745 -> V_707 : V_747 ;
V_746 [ V_364 ] = V_748 ;
V_740 [ V_364 ] = F_91 ( V_748 , V_201 ) ;
if ( V_740 [ V_364 ] == NULL ) {
V_49 = - V_255 ;
goto V_750;
}
if ( V_745 -> V_143 . Type . V_742 & V_607 ) {
if ( F_291 ( V_740 [ V_364 ] , V_749 , V_748 ) ) {
V_49 = - V_705 ;
goto V_750;
}
} else
memset ( V_740 [ V_364 ] , 0 , V_748 ) ;
V_747 -= V_748 ;
V_749 += V_748 ;
V_364 ++ ;
}
V_9 = F_170 ( V_22 ) ;
V_9 -> V_149 = V_394 ;
V_9 -> V_10 = V_672 ;
V_9 -> V_123 . V_127 = 0 ;
V_9 -> V_123 . V_124 = ( T_1 ) V_364 ;
V_9 -> V_123 . V_274 = F_153 ( V_364 ) ;
memcpy ( & V_9 -> V_123 . V_343 , & V_745 -> V_702 , sizeof( V_9 -> V_123 . V_343 ) ) ;
memcpy ( & V_9 -> V_143 , & V_745 -> V_143 , sizeof( V_9 -> V_143 ) ) ;
if ( V_745 -> V_704 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ ) {
V_261 = F_125 ( V_22 -> V_29 , V_740 [ V_68 ] ,
V_746 [ V_68 ] , V_744 ) ;
if ( F_126 ( & V_22 -> V_29 -> V_30 ,
( V_366 ) V_261 ) ) {
V_9 -> V_270 [ V_68 ] . V_276 = F_127 ( 0 ) ;
V_9 -> V_270 [ V_68 ] . V_275 = F_132 ( 0 ) ;
F_154 ( V_22 -> V_29 , V_9 , V_68 ,
V_744 ) ;
V_49 = - V_255 ;
goto V_753;
}
V_9 -> V_270 [ V_68 ] . V_276 = F_127 ( V_261 ) ;
V_9 -> V_270 [ V_68 ] . V_275 = F_132 ( V_746 [ V_68 ] ) ;
V_9 -> V_270 [ V_68 ] . V_272 = F_132 ( 0 ) ;
}
V_9 -> V_270 [ -- V_68 ] . V_272 = F_132 ( V_370 ) ;
}
V_49 = F_161 ( V_22 , V_9 , V_126 , V_374 ) ;
if ( V_364 )
F_154 ( V_22 -> V_29 , V_9 , V_364 , V_744 ) ;
F_303 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_381 ;
goto V_753;
}
memcpy ( & V_745 -> V_703 , V_9 -> V_24 , sizeof( V_745 -> V_703 ) ) ;
if ( F_294 ( V_727 , V_745 , sizeof( * V_745 ) ) ) {
V_49 = - V_705 ;
goto V_753;
}
if ( ( V_745 -> V_143 . Type . V_742 & V_608 ) && V_745 -> V_704 > 0 ) {
int V_68 ;
T_14 T_8 * V_754 = V_745 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ ) {
if ( F_294 ( V_754 , V_740 [ V_68 ] , V_746 [ V_68 ] ) ) {
V_49 = - V_705 ;
goto V_753;
}
V_754 += V_746 [ V_68 ] ;
}
}
V_49 = 0 ;
V_753:
F_172 ( V_22 , V_9 ) ;
V_750:
if ( V_740 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_364 ; V_68 ++ )
F_80 ( V_740 [ V_68 ] ) ;
F_80 ( V_740 ) ;
}
F_80 ( V_746 ) ;
F_80 ( V_745 ) ;
return V_49 ;
}
static void F_303 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_289 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_295 ( struct V_2 * V_30 , int V_278 , void T_8 * V_697 )
{
struct V_1 * V_22 ;
void T_8 * V_727 = ( void T_8 * ) V_697 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_278 ) {
case V_719 :
case V_720 :
case V_721 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_709 :
return F_299 ( V_22 , V_727 ) ;
case V_717 :
return F_301 ( V_22 , V_727 ) ;
case V_706 :
if ( F_283 ( & V_22 -> V_755 ) < 0 )
return - V_756 ;
V_21 = F_302 ( V_22 , V_727 ) ;
F_55 ( & V_22 -> V_755 ) ;
return V_21 ;
case V_708 :
if ( F_283 ( & V_22 -> V_755 ) < 0 )
return - V_756 ;
V_21 = F_304 ( V_22 , V_727 ) ;
F_55 ( & V_22 -> V_755 ) ;
return V_21 ;
default:
return - V_757 ;
}
}
static void F_305 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_390 )
{
struct V_8 * V_9 ;
V_9 = F_170 ( V_22 ) ;
( void ) F_171 ( V_9 , V_662 , V_22 , NULL , 0 , 0 ,
V_157 , V_391 ) ;
V_9 -> V_143 . V_144 [ 1 ] = V_390 ;
V_9 -> V_373 = NULL ;
F_60 ( V_22 , V_9 ) ;
return;
}
static int F_171 ( struct V_8 * V_9 , T_1 V_278 , struct V_1 * V_22 ,
void * V_740 , T_3 V_450 , T_6 V_758 , unsigned char * V_72 ,
int V_149 )
{
int V_759 = V_609 ;
T_5 V_342 ;
V_9 -> V_149 = V_394 ;
V_9 -> V_10 = V_672 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_740 != NULL && V_450 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_274 = F_153 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_274 = F_153 ( 0 ) ;
}
memcpy ( V_9 -> V_123 . V_343 . V_344 , V_72 , 8 ) ;
if ( V_149 == V_387 ) {
switch ( V_278 ) {
case V_386 :
if ( V_758 & V_400 ) {
V_9 -> V_143 . V_144 [ 1 ] = 0x01 ;
V_9 -> V_143 . V_144 [ 2 ] = ( V_758 & 0xff ) ;
}
V_9 -> V_143 . V_339 = 6 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_386 ;
V_9 -> V_143 . V_144 [ 4 ] = V_450 & 0xFF ;
break;
case V_444 :
case V_445 :
V_9 -> V_143 . V_339 = 12 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_278 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_450 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_450 & 0xFF ;
break;
case V_760 :
V_9 -> V_143 . V_339 = 16 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_761 ;
V_9 -> V_143 . V_144 [ 6 ] = V_760 ;
break;
case V_762 :
V_9 -> V_143 . V_339 = 16 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 ,
V_606 , V_607 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_762 ;
break;
case V_763 :
V_9 -> V_143 . V_339 = 12 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 ,
V_606 , V_607 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_764 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = V_450 & 0xFF ;
break;
case V_457 :
V_9 -> V_143 . V_339 = 6 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_609 ) ;
V_9 -> V_143 . V_604 = 0 ;
break;
case V_418 :
V_9 -> V_143 . V_339 = 12 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_765 ;
V_9 -> V_143 . V_144 [ 1 ] = V_278 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_450 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_450 & 0xFF ;
break;
case V_766 :
V_9 -> V_143 . V_339 = 10 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_761 ;
V_9 -> V_143 . V_144 [ 6 ] = V_766 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0xFF ;
break;
case V_425 :
V_9 -> V_143 . V_339 = 10 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_761 ;
V_9 -> V_143 . V_144 [ 6 ] = V_425 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0XFF ;
break;
case V_421 :
V_9 -> V_143 . V_339 = 10 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_761 ;
V_9 -> V_143 . V_144 [ 6 ] = V_421 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0XFF ;
break;
case V_423 :
V_9 -> V_143 . V_339 = 10 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_608 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_761 ;
V_9 -> V_143 . V_144 [ 1 ] = 0 ;
V_9 -> V_143 . V_144 [ 2 ] = 0 ;
V_9 -> V_143 . V_144 [ 3 ] = 0 ;
V_9 -> V_143 . V_144 [ 4 ] = 0 ;
V_9 -> V_143 . V_144 [ 5 ] = 0 ;
V_9 -> V_143 . V_144 [ 6 ] = V_423 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_450 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_450 >> 8 ) & 0XFF ;
V_9 -> V_143 . V_144 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_209 , V_278 ) ;
F_175 () ;
return - 1 ;
}
} else if ( V_149 == V_391 ) {
switch ( V_278 ) {
case V_663 :
V_9 -> V_143 . V_339 = 16 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_609 ) ;
V_9 -> V_143 . V_604 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_767 ;
V_9 -> V_143 . V_144 [ 1 ] = V_768 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
case V_662 :
V_9 -> V_143 . V_339 = 16 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 , V_606 , V_609 ) ;
V_9 -> V_143 . V_604 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_278 ;
V_9 -> V_143 . V_144 [ 1 ] = V_769 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
case V_459 :
memcpy ( & V_342 , V_740 , sizeof( V_342 ) ) ;
F_273 ( & V_22 -> V_29 -> V_30 ,
L_210 ,
V_342 , V_9 -> V_123 . V_342 ) ;
V_9 -> V_143 . V_339 = 16 ;
V_9 -> V_143 . V_605 =
F_248 ( V_149 ,
V_606 , V_607 ) ;
V_9 -> V_143 . V_604 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_770 ;
V_9 -> V_143 . V_144 [ 1 ] = V_771 ;
V_9 -> V_143 . V_144 [ 2 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_143 . V_144 [ 4 ] , & V_342 , sizeof( V_342 ) ) ;
V_9 -> V_143 . V_144 [ 12 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 13 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 14 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_211 ,
V_278 ) ;
F_175 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_212 , V_149 ) ;
F_175 () ;
}
switch ( F_306 ( V_9 -> V_143 . V_605 ) ) {
case V_608 :
V_759 = V_389 ;
break;
case V_607 :
V_759 = V_265 ;
break;
case V_609 :
V_759 = V_369 ;
break;
default:
V_759 = V_744 ;
}
if ( F_155 ( V_22 -> V_29 , V_9 , V_740 , V_450 , V_759 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_307 ( T_16 V_772 , T_16 V_450 )
{
T_16 V_773 = ( ( T_16 ) V_772 ) & V_774 ;
T_16 V_775 = ( ( T_16 ) V_772 ) - V_773 ;
void T_15 * V_776 = F_308 ( V_773 ,
V_775 + V_450 ) ;
return V_776 ? ( V_776 + V_775 ) : NULL ;
}
static inline unsigned long F_309 ( struct V_1 * V_22 , T_1 V_109 )
{
return V_22 -> V_114 . V_115 ( V_22 , V_109 ) ;
}
static inline bool F_310 ( struct V_1 * V_22 )
{
return V_22 -> V_114 . V_777 ( V_22 ) ;
}
static inline long F_311 ( struct V_1 * V_22 )
{
return ( V_22 -> V_114 . V_777 ( V_22 ) == 0 ) ||
( V_22 -> V_778 == 0 ) ;
}
static inline int F_312 ( struct V_1 * V_22 , T_4 V_779 ,
T_4 V_780 )
{
if ( F_44 ( V_779 >= V_22 -> V_235 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_213 , V_780 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_61 ( struct V_8 * V_9 )
{
F_56 ( V_9 -> V_22 , V_9 ) ;
if ( F_47 ( V_9 -> V_149 == V_150 || V_9 -> V_149 == V_333
|| V_9 -> V_149 == V_153 ) )
F_150 ( V_9 ) ;
else if ( V_9 -> V_149 == V_394 || V_9 -> V_149 == V_155 )
F_313 ( V_9 -> V_373 ) ;
}
static inline void F_314 ( struct V_1 * V_22 ,
T_4 V_780 )
{
T_4 V_779 ;
struct V_8 * V_9 ;
V_779 = V_780 >> V_567 ;
if ( ! F_312 ( V_22 , V_779 , V_780 ) ) {
V_9 = V_22 -> V_398 + V_779 ;
F_61 ( V_9 ) ;
}
}
static int F_315 ( struct V_1 * V_22 )
{
if ( F_47 ( ! V_781 ) )
return 0 ;
if ( F_47 ( V_22 -> V_778 ) )
return 0 ;
F_94 ( & V_22 -> V_29 -> V_30 , L_214
L_215 ) ;
return 1 ;
}
static struct V_1 * F_316 ( T_1 * V_782 )
{
return F_253 ( ( V_782 - * V_782 ) , struct V_1 , V_109 [ 0 ] ) ;
}
static T_17 F_317 ( int V_643 , void * V_782 )
{
struct V_1 * V_22 = F_316 ( V_782 ) ;
T_1 V_109 = * ( T_1 * ) V_782 ;
T_4 V_780 ;
if ( F_315 ( V_22 ) )
return V_783 ;
if ( F_311 ( V_22 ) )
return V_783 ;
V_22 -> V_784 = F_318 () ;
while ( F_310 ( V_22 ) ) {
V_780 = F_309 ( V_22 , V_109 ) ;
while ( V_780 != V_119 )
V_780 = F_43 ( V_22 , V_109 ) ;
}
return V_785 ;
}
static T_17 F_319 ( int V_643 , void * V_782 )
{
struct V_1 * V_22 = F_316 ( V_782 ) ;
T_4 V_780 ;
T_1 V_109 = * ( T_1 * ) V_782 ;
if ( F_315 ( V_22 ) )
return V_783 ;
V_22 -> V_784 = F_318 () ;
V_780 = F_309 ( V_22 , V_109 ) ;
while ( V_780 != V_119 )
V_780 = F_43 ( V_22 , V_109 ) ;
return V_785 ;
}
static T_17 F_320 ( int V_643 , void * V_782 )
{
struct V_1 * V_22 = F_316 ( ( T_1 * ) V_782 ) ;
T_4 V_780 ;
T_1 V_109 = * ( T_1 * ) V_782 ;
if ( F_311 ( V_22 ) )
return V_783 ;
V_22 -> V_784 = F_318 () ;
while ( F_310 ( V_22 ) ) {
V_780 = F_309 ( V_22 , V_109 ) ;
while ( V_780 != V_119 ) {
F_314 ( V_22 , V_780 ) ;
V_780 = F_43 ( V_22 , V_109 ) ;
}
}
return V_785 ;
}
static T_17 F_321 ( int V_643 , void * V_782 )
{
struct V_1 * V_22 = F_316 ( V_782 ) ;
T_4 V_780 ;
T_1 V_109 = * ( T_1 * ) V_782 ;
V_22 -> V_784 = F_318 () ;
V_780 = F_309 ( V_22 , V_109 ) ;
while ( V_780 != V_119 ) {
F_314 ( V_22 , V_780 ) ;
V_780 = F_43 ( V_22 , V_109 ) ;
}
return V_785 ;
}
static int F_322 ( struct V_363 * V_29 , unsigned char V_786 ,
unsigned char type )
{
struct V_787 {
struct V_788 V_789 ;
struct V_790 V_143 ;
struct V_791 V_792 ;
};
struct V_787 * V_278 ;
static const T_3 V_793 = sizeof( * V_278 ) +
sizeof( V_278 -> V_792 ) ;
V_366 V_794 ;
T_7 V_795 ;
T_4 V_342 ;
void T_15 * V_151 ;
int V_68 , V_701 ;
V_151 = F_323 ( V_29 , 0 ) ;
if ( V_151 == NULL )
return - V_255 ;
V_701 = F_324 ( V_29 , F_325 ( 32 ) ) ;
if ( V_701 ) {
F_326 ( V_151 ) ;
return V_701 ;
}
V_278 = F_327 ( V_29 , V_793 , & V_794 ) ;
if ( V_278 == NULL ) {
F_326 ( V_151 ) ;
return - V_255 ;
}
V_795 = F_132 ( V_794 ) ;
V_278 -> V_789 . V_127 = 0 ;
V_278 -> V_789 . V_124 = 0 ;
V_278 -> V_789 . V_274 = F_153 ( 0 ) ;
V_278 -> V_789 . V_342 = F_127 ( V_794 ) ;
memset ( & V_278 -> V_789 . V_343 . V_344 , 0 , 8 ) ;
V_278 -> V_143 . V_339 = 16 ;
V_278 -> V_143 . V_605 =
F_248 ( V_391 , V_796 , V_609 ) ;
V_278 -> V_143 . V_604 = 0 ;
V_278 -> V_143 . V_144 [ 0 ] = V_786 ;
V_278 -> V_143 . V_144 [ 1 ] = type ;
memset ( & V_278 -> V_143 . V_144 [ 2 ] , 0 , 14 ) ;
V_278 -> V_792 . V_276 =
F_127 ( ( F_124 ( V_795 ) + sizeof( * V_278 ) ) ) ;
V_278 -> V_792 . V_275 = F_132 ( sizeof( struct V_330 ) ) ;
F_59 ( F_124 ( V_795 ) , V_151 + V_152 ) ;
for ( V_68 = 0 ; V_68 < V_797 ; V_68 ++ ) {
V_342 = F_328 ( V_151 + V_798 ) ;
if ( ( V_342 & ~ V_799 ) == V_794 )
break;
F_166 ( V_800 ) ;
}
F_326 ( V_151 ) ;
if ( V_68 == V_797 ) {
F_73 ( & V_29 -> V_30 , L_216 ,
V_786 , type ) ;
return - V_376 ;
}
F_329 ( V_29 , V_793 , V_278 , V_794 ) ;
if ( V_342 & V_801 ) {
F_73 ( & V_29 -> V_30 , L_217 ,
V_786 , type ) ;
return - V_381 ;
}
F_94 ( & V_29 -> V_30 , L_218 ,
V_786 , type ) ;
return 0 ;
}
static int F_330 ( struct V_363 * V_29 ,
void T_15 * V_151 , T_4 V_802 )
{
if ( V_802 ) {
F_94 ( & V_29 -> V_30 , L_219 ) ;
F_59 ( V_802 , V_151 + V_803 ) ;
F_166 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_94 ( & V_29 -> V_30 , L_220 ) ;
V_21 = F_331 ( V_29 , V_804 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
V_21 = F_331 ( V_29 , V_805 ) ;
if ( V_21 )
return V_21 ;
F_166 ( 500 ) ;
}
return 0 ;
}
static void F_332 ( char * V_806 , int V_50 )
{
memset ( V_806 , 0 , V_50 ) ;
strncpy ( V_806 , V_41 L_221 V_738 , V_50 - 1 ) ;
}
static int F_333 ( struct V_807 T_15 * V_808 )
{
char * V_806 ;
int V_68 , V_450 = sizeof( V_808 -> V_806 ) ;
V_806 = F_91 ( V_450 , V_201 ) ;
if ( ! V_806 )
return - V_255 ;
F_332 ( V_806 , V_450 ) ;
for ( V_68 = 0 ; V_68 < V_450 ; V_68 ++ )
F_334 ( V_806 [ V_68 ] , & V_808 -> V_806 [ V_68 ] ) ;
F_80 ( V_806 ) ;
return 0 ;
}
static void F_335 ( struct V_807 T_15 * V_808 ,
unsigned char * V_809 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_808 -> V_806 ) ; V_68 ++ )
V_809 [ V_68 ] = F_336 ( & V_808 -> V_806 [ V_68 ] ) ;
}
static int F_337 ( struct V_807 T_15 * V_808 )
{
char * V_809 , * V_810 ;
int V_21 , V_450 = sizeof( V_808 -> V_806 ) ;
V_810 = F_91 ( 2 * V_450 , V_201 ) ;
if ( ! V_810 )
return - V_255 ;
V_809 = V_810 + V_450 ;
F_332 ( V_810 , V_450 ) ;
F_335 ( V_808 , V_809 ) ;
V_21 = ! memcmp ( V_809 , V_810 , V_450 ) ;
F_80 ( V_810 ) ;
return V_21 ;
}
static int F_338 ( struct V_363 * V_29 , T_4 V_67 )
{
T_5 V_811 ;
T_4 V_812 ;
T_5 V_813 ;
void T_15 * V_151 ;
unsigned long V_814 ;
T_4 V_815 ;
int V_21 ;
struct V_807 T_15 * V_808 ;
T_4 V_802 ;
T_6 V_816 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_222 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_817 ;
F_339 ( V_29 , 4 , & V_816 ) ;
F_340 ( V_29 ) ;
V_21 = F_341 ( V_29 , & V_814 ) ;
if ( V_21 )
return V_21 ;
V_151 = F_307 ( V_814 , 0x250 ) ;
if ( ! V_151 )
return - V_255 ;
V_21 = F_342 ( V_29 , V_151 , & V_812 ,
& V_813 , & V_811 ) ;
if ( V_21 )
goto V_818;
V_808 = F_307 ( F_343 ( V_29 ,
V_813 ) + V_811 , sizeof( * V_808 ) ) ;
if ( ! V_808 ) {
V_21 = - V_255 ;
goto V_818;
}
V_21 = F_333 ( V_808 ) ;
if ( V_21 )
goto V_819;
V_815 = F_328 ( & V_808 -> V_815 ) ;
V_802 = V_815 & V_820 ;
if ( V_802 ) {
V_802 = V_821 ;
} else {
V_802 = V_815 & V_822 ;
if ( V_802 ) {
F_9 ( & V_29 -> V_30 ,
L_223 ) ;
V_21 = - V_817 ;
goto V_819;
}
}
V_21 = F_330 ( V_29 , V_151 , V_802 ) ;
if ( V_21 )
goto V_819;
F_344 ( V_29 ) ;
F_345 ( V_29 , 4 , V_816 ) ;
F_166 ( V_823 ) ;
V_21 = F_346 ( V_29 , V_151 , V_824 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_224 ) ;
goto V_819;
}
V_21 = F_337 ( V_151 ) ;
if ( V_21 < 0 )
goto V_819;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_225
L_226 ) ;
V_21 = - V_817 ;
} else {
F_94 ( & V_29 -> V_30 , L_227 ) ;
}
V_819:
F_326 ( V_808 ) ;
V_818:
F_326 ( V_151 ) ;
return V_21 ;
}
static void F_347 ( struct V_42 * V_30 , struct V_807 T_15 * V_825 )
{
#ifdef F_348
int V_68 ;
char V_826 [ 17 ] ;
F_94 ( V_30 , L_228 ) ;
F_94 ( V_30 , L_229 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_826 [ V_68 ] = F_336 ( & ( V_825 -> V_827 [ V_68 ] ) ) ;
V_826 [ 4 ] = '\0' ;
F_94 ( V_30 , L_230 , V_826 ) ;
F_94 ( V_30 , L_231 , F_328 ( & ( V_825 -> V_828 ) ) ) ;
F_94 ( V_30 , L_232 ,
F_328 ( & ( V_825 -> V_829 ) ) ) ;
F_94 ( V_30 , L_233 ,
F_328 ( & ( V_825 -> V_830 ) ) ) ;
F_94 ( V_30 , L_234 ,
F_328 ( & ( V_825 -> V_831 . V_832 ) ) ) ;
F_94 ( V_30 , L_235 ,
F_328 ( & ( V_825 -> V_831 . V_833 ) ) ) ;
F_94 ( V_30 , L_236 ,
F_328 ( & ( V_825 -> V_831 . V_834 ) ) ) ;
F_94 ( V_30 , L_237 ,
F_328 ( & ( V_825 -> V_835 ) ) ) ;
F_94 ( V_30 , L_238 , F_328 ( & ( V_825 -> V_836 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_826 [ V_68 ] = F_336 ( & ( V_825 -> V_837 [ V_68 ] ) ) ;
V_826 [ 16 ] = '\0' ;
F_94 ( V_30 , L_239 , V_826 ) ;
F_94 ( V_30 , L_240 ,
F_328 ( & ( V_825 -> V_838 ) ) ) ;
#endif
}
static int F_349 ( struct V_363 * V_29 , unsigned long V_839 )
{
int V_68 , V_695 , V_840 , V_841 ;
if ( V_839 == V_842 )
return 0 ;
V_695 = 0 ;
for ( V_68 = 0 ; V_68 < V_843 ; V_68 ++ ) {
V_841 = F_350 ( V_29 , V_68 ) & V_844 ;
if ( V_841 == V_845 )
V_695 += 4 ;
else {
V_840 = F_350 ( V_29 , V_68 ) &
V_846 ;
switch ( V_840 ) {
case V_847 :
case V_848 :
V_695 += 4 ;
break;
case V_849 :
V_695 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_241 ) ;
return - 1 ;
break;
}
}
if ( V_695 == V_839 - V_842 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_351 ( struct V_1 * V_22 )
{
if ( V_22 -> V_125 ) {
if ( V_22 -> V_29 -> V_850 )
F_352 ( V_22 -> V_29 ) ;
V_22 -> V_125 = 0 ;
} else if ( V_22 -> V_851 ) {
if ( V_22 -> V_29 -> V_852 )
F_353 ( V_22 -> V_29 ) ;
V_22 -> V_851 = 0 ;
}
}
static void F_354 ( struct V_1 * V_22 )
{
#ifdef F_355
int V_701 , V_68 ;
struct V_853 V_854 [ V_855 ] ;
for ( V_68 = 0 ; V_68 < V_855 ; V_68 ++ ) {
V_854 [ V_68 ] . V_856 = 0 ;
V_854 [ V_68 ] . V_182 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_857;
if ( F_356 ( V_22 -> V_29 , V_858 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_242 ) ;
V_22 -> V_125 = V_855 ;
if ( V_22 -> V_125 > F_357 () )
V_22 -> V_125 = F_357 () ;
V_701 = F_358 ( V_22 -> V_29 , V_854 ,
1 , V_22 -> V_125 ) ;
if ( V_701 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_243 , V_701 ) ;
V_22 -> V_125 = 0 ;
goto V_859;
} else if ( V_701 < V_22 -> V_125 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_244
L_245 , V_701 ) ;
}
V_22 -> V_125 = V_701 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ )
V_22 -> V_644 [ V_68 ] = V_854 [ V_68 ] . V_856 ;
return;
}
V_859:
if ( F_356 ( V_22 -> V_29 , V_860 ) ) {
F_94 ( & V_22 -> V_29 -> V_30 , L_246 ) ;
if ( ! F_359 ( V_22 -> V_29 ) )
V_22 -> V_851 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_247 ) ;
}
V_857:
#endif
V_22 -> V_644 [ V_22 -> V_645 ] = V_22 -> V_29 -> V_643 ;
}
static int F_360 ( struct V_363 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_861 , V_862 ;
V_861 = V_29 -> V_863 ;
V_862 = V_29 -> V_864 ;
* V_67 = ( ( V_862 << 16 ) & 0xffff0000 ) |
V_861 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_865 ) ; V_68 ++ )
if ( * V_67 == V_865 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_861 != V_866 &&
V_861 != V_867 ) ||
! V_868 ) {
F_9 ( & V_29 -> V_30 , L_248
L_249 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_865 ) - 1 ;
}
static int F_341 ( struct V_363 * V_29 ,
unsigned long * V_869 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_843 ; V_68 ++ )
if ( F_350 ( V_29 , V_68 ) & V_870 ) {
* V_869 = F_343 ( V_29 , V_68 ) ;
F_273 ( & V_29 -> V_30 , L_250 ,
* V_869 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_251 ) ;
return - V_81 ;
}
static int F_346 ( struct V_363 * V_29 , void T_15 * V_151 ,
int V_871 )
{
int V_68 , V_872 ;
T_4 V_873 ;
if ( V_871 )
V_872 = V_874 ;
else
V_872 = V_875 ;
for ( V_68 = 0 ; V_68 < V_872 ; V_68 ++ ) {
V_873 = F_328 ( V_151 + V_876 ) ;
if ( V_871 ) {
if ( V_873 == V_877 )
return 0 ;
} else {
if ( V_873 != V_877 )
return 0 ;
}
F_166 ( V_878 ) ;
}
F_9 ( & V_29 -> V_30 , L_252 ) ;
return - V_81 ;
}
static int F_342 ( struct V_363 * V_29 , void T_15 * V_151 ,
T_4 * V_812 , T_5 * V_813 ,
T_5 * V_811 )
{
* V_812 = F_328 ( V_151 + V_879 ) ;
* V_811 = F_328 ( V_151 + V_880 ) ;
* V_812 &= ( T_4 ) 0x0000ffff ;
* V_813 = F_349 ( V_29 , * V_812 ) ;
if ( * V_813 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_253 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_361 ( struct V_1 * V_22 )
{
if ( V_22 -> V_881 ) {
F_326 ( V_22 -> V_881 ) ;
V_22 -> V_881 = NULL ;
}
if ( V_22 -> V_808 ) {
F_326 ( V_22 -> V_808 ) ;
V_22 -> V_808 = NULL ;
}
}
static int F_362 ( struct V_1 * V_22 )
{
T_5 V_811 ;
T_4 V_812 ;
T_5 V_813 ;
T_4 V_882 ;
int V_21 ;
V_21 = F_342 ( V_22 -> V_29 , V_22 -> V_151 , & V_812 ,
& V_813 , & V_811 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_808 = F_307 ( F_343 ( V_22 -> V_29 ,
V_813 ) + V_811 , sizeof( * V_22 -> V_808 ) ) ;
if ( ! V_22 -> V_808 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_254 ) ;
return - V_255 ;
}
V_21 = F_333 ( V_22 -> V_808 ) ;
if ( V_21 )
return V_21 ;
V_882 = F_328 ( & V_22 -> V_808 -> V_883 ) ;
V_22 -> V_881 = F_307 ( F_343 ( V_22 -> V_29 ,
V_813 ) + V_811 + V_882 ,
sizeof( * V_22 -> V_881 ) ) ;
if ( ! V_22 -> V_881 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_255 ) ;
F_361 ( V_22 ) ;
return - V_255 ;
}
return 0 ;
}
static void F_363 ( struct V_1 * V_22 )
{
#define F_364 16
F_275 ( F_364 <= V_638 ) ;
V_22 -> V_120 = F_328 ( & V_22 -> V_808 -> V_884 ) ;
if ( V_781 && V_22 -> V_120 > 32 )
V_22 -> V_120 = 32 ;
if ( V_22 -> V_120 < F_364 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_256 ,
V_22 -> V_120 ,
F_364 ) ;
V_22 -> V_120 = F_364 ;
}
}
static int F_365 ( struct V_1 * V_22 )
{
return V_22 -> V_256 > 512 ;
}
static void F_366 ( struct V_1 * V_22 )
{
F_363 ( V_22 ) ;
V_22 -> V_235 = V_22 -> V_120 ;
V_22 -> V_256 = F_328 ( & ( V_22 -> V_808 -> V_885 ) ) ;
V_22 -> V_466 = F_328 ( & ( V_22 -> V_808 -> V_815 ) ) ;
if ( F_365 ( V_22 ) ) {
V_22 -> V_271 = 32 ;
V_22 -> V_254 = V_22 -> V_256 - V_22 -> V_271 ;
V_22 -> V_256 -- ;
} else {
V_22 -> V_271 = 31 ;
V_22 -> V_256 = 31 ;
V_22 -> V_254 = 0 ;
}
V_22 -> V_684 = F_328 ( & ( V_22 -> V_808 -> V_684 ) ) ;
if ( ! ( V_690 & V_22 -> V_684 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_257 ) ;
if ( ! ( V_691 & V_22 -> V_684 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_258 ) ;
if ( ! ( V_683 & V_22 -> V_684 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
}
static inline bool F_367 ( struct V_1 * V_22 )
{
if ( ! F_368 ( V_22 -> V_808 -> V_827 , L_260 , 4 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_261 ) ;
return false ;
}
return true ;
}
static inline void F_369 ( struct V_1 * V_22 )
{
T_4 V_886 ;
V_886 = F_328 ( & ( V_22 -> V_808 -> V_886 ) ) ;
#ifdef F_370
V_886 |= V_887 ;
#endif
V_886 |= V_888 ;
F_59 ( V_886 , & ( V_22 -> V_808 -> V_886 ) ) ;
}
static inline void F_371 ( struct V_1 * V_22 )
{
T_4 V_889 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_889 = F_328 ( V_22 -> V_151 + V_890 ) ;
V_889 |= 0x8000 ;
F_59 ( V_889 , V_22 -> V_151 + V_890 ) ;
}
static int F_372 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_891 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_892 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_891 = F_328 ( V_22 -> V_151 + V_803 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_891 & V_893 ) )
goto V_894;
F_166 ( V_895 ) ;
}
return - V_81 ;
V_894:
return 0 ;
}
static int F_373 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_891 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_896 ; V_68 ++ ) {
if ( V_22 -> V_897 )
goto V_894;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_891 = F_328 ( V_22 -> V_151 + V_803 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_891 & V_898 ) )
goto V_894;
F_166 ( V_899 ) ;
}
return - V_81 ;
V_894:
return 0 ;
}
static int F_374 ( struct V_1 * V_22 )
{
T_4 V_900 ;
V_900 = F_328 ( & ( V_22 -> V_808 -> V_829 ) ) ;
if ( ! ( V_900 & V_901 ) )
return - V_817 ;
V_22 -> V_120 = F_328 ( & ( V_22 -> V_808 -> V_835 ) ) ;
F_59 ( V_902 , & ( V_22 -> V_808 -> V_831 . V_832 ) ) ;
F_59 ( 0 , & V_22 -> V_808 -> V_831 . V_903 ) ;
F_59 ( V_898 , V_22 -> V_151 + V_803 ) ;
if ( F_373 ( V_22 ) )
goto error;
F_347 ( & V_22 -> V_29 -> V_30 , V_22 -> V_808 ) ;
if ( ! ( F_328 ( & ( V_22 -> V_808 -> V_830 ) ) & V_902 ) )
goto error;
V_22 -> V_63 = V_902 ;
return 0 ;
error:
F_73 ( & V_22 -> V_29 -> V_30 , L_262 ) ;
return - V_81 ;
}
static void F_375 ( struct V_1 * V_22 )
{
F_361 ( V_22 ) ;
F_326 ( V_22 -> V_151 ) ;
V_22 -> V_151 = NULL ;
F_351 ( V_22 ) ;
F_376 ( V_22 -> V_29 ) ;
F_377 ( V_22 -> V_29 ) ;
}
static int F_378 ( struct V_1 * V_22 )
{
int V_904 , V_701 ;
V_904 = F_360 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_904 < 0 )
return V_904 ;
V_22 -> V_905 = V_865 [ V_904 ] . V_905 ;
V_22 -> V_114 = * ( V_865 [ V_904 ] . V_114 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_379 ( V_22 -> V_29 , V_906 |
V_907 | V_908 ) ;
V_701 = F_380 ( V_22 -> V_29 ) ;
if ( V_701 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
F_376 ( V_22 -> V_29 ) ;
return V_701 ;
}
V_701 = F_381 ( V_22 -> V_29 , V_41 ) ;
if ( V_701 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_264 ) ;
F_376 ( V_22 -> V_29 ) ;
return V_701 ;
}
F_382 ( V_22 -> V_29 ) ;
F_354 ( V_22 ) ;
V_701 = F_341 ( V_22 -> V_29 , & V_22 -> V_814 ) ;
if ( V_701 )
goto V_909;
V_22 -> V_151 = F_307 ( V_22 -> V_814 , 0x250 ) ;
if ( ! V_22 -> V_151 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_265 ) ;
V_701 = - V_255 ;
goto V_909;
}
V_701 = F_346 ( V_22 -> V_29 , V_22 -> V_151 , V_824 ) ;
if ( V_701 )
goto V_910;
V_701 = F_362 ( V_22 ) ;
if ( V_701 )
goto V_910;
F_366 ( V_22 ) ;
if ( ! F_367 ( V_22 ) ) {
V_701 = - V_81 ;
goto V_911;
}
F_369 ( V_22 ) ;
F_371 ( V_22 ) ;
V_701 = F_374 ( V_22 ) ;
if ( V_701 )
goto V_911;
return 0 ;
V_911:
F_361 ( V_22 ) ;
V_910:
F_326 ( V_22 -> V_151 ) ;
V_22 -> V_151 = NULL ;
V_909:
F_351 ( V_22 ) ;
F_376 ( V_22 -> V_29 ) ;
F_377 ( V_22 -> V_29 ) ;
return V_701 ;
}
static void F_383 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_384 64
V_22 -> V_61 = F_91 ( F_384 , V_201 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_169 ( V_22 , V_157 , 0 ,
V_22 -> V_61 , F_384 ) ;
if ( V_21 != 0 ) {
F_80 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_385 ( struct V_363 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_151 ;
if ( ! V_781 )
return 0 ;
V_21 = F_380 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_266 ) ;
return - V_81 ;
}
F_376 ( V_29 ) ;
F_166 ( 260 ) ;
V_21 = F_380 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_267 ) ;
return - V_81 ;
}
F_382 ( V_29 ) ;
V_151 = F_323 ( V_29 , 0 ) ;
if ( V_151 == NULL ) {
V_21 = - V_255 ;
goto V_912;
}
F_59 ( V_913 , V_151 + V_914 ) ;
F_326 ( V_151 ) ;
V_21 = F_338 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_912;
F_94 ( & V_29 -> V_30 , L_268 ) ;
for ( V_68 = 0 ; V_68 < V_915 ; V_68 ++ ) {
if ( F_386 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_269 ,
( V_68 < 11 ? L_270 : L_271 ) ) ;
}
V_912:
F_376 ( V_29 ) ;
return V_21 ;
}
static void F_387 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_696 ) ;
V_22 -> V_696 = NULL ;
if ( V_22 -> V_398 ) {
F_329 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( struct V_8 ) ,
V_22 -> V_398 ,
V_22 -> V_615 ) ;
V_22 -> V_398 = NULL ;
V_22 -> V_615 = 0 ;
}
if ( V_22 -> V_616 ) {
F_329 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( struct V_330 ) ,
V_22 -> V_616 ,
V_22 -> V_617 ) ;
V_22 -> V_616 = NULL ;
V_22 -> V_617 = 0 ;
}
}
static int F_388 ( struct V_1 * V_22 )
{
V_22 -> V_696 = F_108 (
F_389 ( V_22 -> V_235 , V_596 ) *
sizeof( unsigned long ) , V_201 ) ;
V_22 -> V_398 = F_327 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_398 ) ,
& ( V_22 -> V_615 ) ) ;
V_22 -> V_616 = F_327 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_616 ) ,
& ( V_22 -> V_617 ) ) ;
if ( ( V_22 -> V_696 == NULL )
|| ( V_22 -> V_398 == NULL )
|| ( V_22 -> V_616 == NULL ) ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_272 , V_202 ) ;
goto V_916;
}
F_250 ( V_22 ) ;
return 0 ;
V_916:
F_387 ( V_22 ) ;
return - V_255 ;
}
static void F_390 ( struct V_1 * V_22 )
{
int V_68 , V_377 ;
V_377 = F_391 ( V_917 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
F_392 ( V_22 -> V_644 [ V_68 ] , F_393 ( V_377 ) ) ;
V_377 = F_394 ( V_377 , V_917 ) ;
}
}
static void F_395 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_125 || V_22 -> V_645 != V_918 ) {
V_68 = V_22 -> V_645 ;
F_392 ( V_22 -> V_644 [ V_68 ] , NULL ) ;
F_396 ( V_22 -> V_644 [ V_68 ] , & V_22 -> V_109 [ V_68 ] ) ;
V_22 -> V_109 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
F_392 ( V_22 -> V_644 [ V_68 ] , NULL ) ;
F_396 ( V_22 -> V_644 [ V_68 ] , & V_22 -> V_109 [ V_68 ] ) ;
V_22 -> V_109 [ V_68 ] = 0 ;
}
for (; V_68 < V_855 ; V_68 ++ )
V_22 -> V_109 [ V_68 ] = 0 ;
}
static int F_397 ( struct V_1 * V_22 ,
T_17 (* F_398)( int , void * ) ,
T_17 (* F_399)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_855 ; V_68 ++ )
V_22 -> V_109 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_645 == V_918 && V_22 -> V_125 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_125 ; V_68 ++ ) {
sprintf ( V_22 -> V_919 [ V_68 ] , L_273 , V_22 -> V_31 , V_68 ) ;
V_21 = F_400 ( V_22 -> V_644 [ V_68 ] , F_398 ,
0 , V_22 -> V_919 [ V_68 ] ,
& V_22 -> V_109 [ V_68 ] ) ;
if ( V_21 ) {
int V_191 ;
F_73 ( & V_22 -> V_29 -> V_30 ,
L_274 ,
V_22 -> V_644 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_191 = 0 ; V_191 < V_68 ; V_191 ++ ) {
F_396 ( V_22 -> V_644 [ V_191 ] , & V_22 -> V_109 [ V_191 ] ) ;
V_22 -> V_109 [ V_191 ] = 0 ;
}
for (; V_191 < V_855 ; V_191 ++ )
V_22 -> V_109 [ V_191 ] = 0 ;
return V_21 ;
}
}
F_390 ( V_22 ) ;
} else {
if ( V_22 -> V_125 > 0 || V_22 -> V_851 ) {
if ( V_22 -> V_125 )
sprintf ( V_22 -> V_919 [ V_22 -> V_645 ] ,
L_275 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_919 [ V_22 -> V_645 ] ,
L_276 , V_22 -> V_31 ) ;
V_21 = F_400 ( V_22 -> V_644 [ V_22 -> V_645 ] ,
F_398 , 0 ,
V_22 -> V_919 [ V_22 -> V_645 ] ,
& V_22 -> V_109 [ V_22 -> V_645 ] ) ;
} else {
sprintf ( V_22 -> V_919 [ V_22 -> V_645 ] ,
L_277 , V_22 -> V_31 ) ;
V_21 = F_400 ( V_22 -> V_644 [ V_22 -> V_645 ] ,
F_399 , V_920 ,
V_22 -> V_919 [ V_22 -> V_645 ] ,
& V_22 -> V_109 [ V_22 -> V_645 ] ) ;
}
F_392 ( V_22 -> V_644 [ V_22 -> V_645 ] , NULL ) ;
}
if ( V_21 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_274 ,
V_22 -> V_644 [ V_22 -> V_645 ] , V_22 -> V_31 ) ;
F_395 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_401 ( struct V_1 * V_22 )
{
int V_21 ;
F_305 ( V_22 , V_157 , V_921 ) ;
F_94 ( & V_22 -> V_29 -> V_30 , L_278 ) ;
V_21 = F_346 ( V_22 -> V_29 , V_22 -> V_151 , V_922 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_279 ) ;
return V_21 ;
}
F_94 ( & V_22 -> V_29 -> V_30 , L_280 ) ;
V_21 = F_346 ( V_22 -> V_29 , V_22 -> V_151 , V_824 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_281
L_282 ) ;
return V_21 ;
}
return 0 ;
}
static void F_402 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
if ( ! V_22 -> V_112 [ V_68 ] . V_116 )
continue;
F_329 ( V_22 -> V_29 ,
V_22 -> V_923 ,
V_22 -> V_112 [ V_68 ] . V_116 ,
V_22 -> V_112 [ V_68 ] . V_121 ) ;
V_22 -> V_112 [ V_68 ] . V_116 = NULL ;
V_22 -> V_112 [ V_68 ] . V_121 = 0 ;
}
V_22 -> V_923 = 0 ;
}
static void F_403 ( struct V_1 * V_22 )
{
F_404 ( V_22 ) ;
F_121 ( V_22 ) ;
F_387 ( V_22 ) ;
F_395 ( V_22 ) ;
F_405 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_375 ( V_22 ) ;
F_406 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_320 ) {
F_407 ( V_22 -> V_320 ) ;
V_22 -> V_320 = NULL ;
}
if ( V_22 -> V_924 ) {
F_407 ( V_22 -> V_924 ) ;
V_22 -> V_924 = NULL ;
}
F_80 ( V_22 ) ;
}
static void F_408 ( struct V_1 * V_22 )
{
int V_68 , V_399 ;
struct V_8 * V_9 ;
int V_925 = 0 ;
F_409 ( V_22 -> V_320 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( V_399 > 1 ) {
V_9 -> V_24 -> V_36 = V_336 ;
F_61 ( V_9 ) ;
F_45 ( & V_22 -> V_62 ) ;
V_925 ++ ;
}
F_172 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_283 , V_925 ) ;
}
static void F_410 ( struct V_1 * V_22 , T_4 V_926 )
{
int V_377 ;
F_411 (cpu) {
T_4 * F_13 ;
F_13 = F_163 ( V_22 -> F_13 , V_377 ) ;
* F_13 = V_926 ;
}
F_76 () ;
}
static void F_412 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_328 ( V_22 -> V_151 + V_876 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_284 ,
V_22 -> V_146 / V_929 ) ;
F_13 = 0xffffffff ;
}
F_410 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_285 ,
F_13 , V_22 -> V_146 / V_929 ) ;
F_376 ( V_22 -> V_29 ) ;
F_408 ( V_22 ) ;
}
static int F_269 ( struct V_1 * V_22 )
{
T_5 V_930 ;
T_4 V_931 ;
unsigned long V_78 ;
V_930 = F_318 () ;
if ( F_413 ( V_22 -> V_784 +
( V_22 -> V_146 ) , V_930 ) )
return false ;
if ( F_413 ( V_22 -> V_932 +
( V_22 -> V_146 ) , V_930 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_931 = F_328 ( & V_22 -> V_808 -> V_838 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_933 == V_931 ) {
F_412 ( V_22 ) ;
return true ;
}
V_22 -> V_933 = V_931 ;
V_22 -> V_932 = V_930 ;
return false ;
}
static void F_414 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_934 ;
if ( ! ( V_22 -> V_466 & V_935 ) )
return;
if ( ( V_22 -> V_63 & ( V_113
| V_936 ) ) &&
( V_22 -> V_937 & V_938 ||
V_22 -> V_937 & V_939 ) ) {
if ( V_22 -> V_937 & V_938 )
V_934 = L_286 ;
if ( V_22 -> V_937 & V_939 )
V_934 = L_287 ;
F_415 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_89 = 0 ;
F_416 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_288 ,
V_22 -> V_937 , V_934 ) ;
F_59 ( V_22 -> V_937 , & ( V_22 -> V_808 -> V_940 ) ) ;
F_59 ( V_893 , V_22 -> V_151 + V_803 ) ;
F_372 ( V_22 ) ;
F_417 ( V_22 -> V_59 ) ;
} else {
F_59 ( V_22 -> V_937 , & ( V_22 -> V_808 -> V_940 ) ) ;
F_59 ( V_893 , V_22 -> V_151 + V_803 ) ;
F_372 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_418 ( struct V_1 * V_22 )
{
if ( V_22 -> V_243 ) {
V_22 -> V_243 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_466 & V_935 ) )
return 0 ;
V_22 -> V_937 = F_328 ( & ( V_22 -> V_808 -> V_941 ) ) ;
return V_22 -> V_937 & V_942 ;
}
static int F_419 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_199 * V_383 ;
struct V_943 * V_944 , * V_945 ;
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_420 (this, tmp, &h->offline_device_list) {
V_383 = F_421 ( V_944 , struct V_199 ,
V_203 ) ;
F_36 ( & V_22 -> V_200 , V_78 ) ;
if ( ! F_202 ( V_22 , V_383 -> V_72 ) ) {
F_35 ( & V_22 -> V_200 , V_78 ) ;
F_422 ( & V_383 -> V_203 ) ;
F_36 ( & V_22 -> V_200 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_200 , V_78 ) ;
}
F_36 ( & V_22 -> V_200 , V_78 ) ;
return 0 ;
}
static int F_423 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_446 * V_478 = NULL ;
if ( ! V_22 -> V_946 )
goto V_388;
V_478 = F_108 ( sizeof( * V_478 ) , V_201 ) ;
if ( ! V_478 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_289 ) ;
goto V_388;
}
if ( F_198 ( V_22 , 1 , V_478 , sizeof( * V_478 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_290 ) ;
goto V_388;
}
if ( memcmp ( V_478 , V_22 -> V_946 , sizeof( * V_478 ) ) ) {
F_94 ( & V_22 -> V_29 -> V_30 ,
L_291 ) ;
memcpy ( V_22 -> V_946 , V_478 , sizeof( * V_478 ) ) ;
goto V_388;
} else
V_21 = 0 ;
V_388:
F_80 ( V_478 ) ;
return V_21 ;
}
static void F_424 ( struct V_619 * V_318 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_253 ( F_425 ( V_318 ) ,
struct V_1 , V_947 ) ;
if ( V_22 -> V_897 )
return;
if ( F_418 ( V_22 ) || F_419 ( V_22 ) ) {
F_426 ( V_22 -> V_59 ) ;
F_414 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_405 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_512 ) {
F_427 ( V_22 ) ;
if ( F_423 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_292 ) ;
V_7 = F_426 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_405 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_897 )
F_428 ( V_22 -> V_924 , & V_22 -> V_947 ,
V_22 -> V_146 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_429 ( struct V_619 * V_318 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_253 ( F_425 ( V_318 ) ,
struct V_1 , V_948 ) ;
F_269 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_897 )
F_430 ( & V_22 -> V_948 ,
V_22 -> V_146 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_949 * F_431 ( struct V_1 * V_22 ,
char * V_950 )
{
struct V_949 * V_951 = NULL ;
V_951 = F_432 ( L_293 , 0 , V_950 , V_22 -> V_952 ) ;
if ( ! V_951 )
F_73 ( & V_22 -> V_29 -> V_30 , L_294 , V_950 ) ;
return V_951 ;
}
static int F_433 ( struct V_363 * V_29 , const struct V_953 * V_954 )
{
int V_955 , V_21 ;
struct V_1 * V_22 ;
int V_956 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_957 == 0 )
F_434 (KERN_INFO DRIVER_NAME L_295 ) ;
V_21 = F_360 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_296 ) ;
return V_21 ;
}
V_21 = F_385 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_817 )
return V_21 ;
V_956 = 1 ;
V_21 = 0 ;
}
V_958:
F_275 ( sizeof( struct V_8 ) % V_959 ) ;
V_22 = F_108 ( sizeof( * V_22 ) , V_201 ) ;
if ( ! V_22 ) {
F_73 ( & V_29 -> V_30 , L_297 ) ;
return - V_255 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_645 = V_960 ? V_961 : V_918 ;
F_435 ( & V_22 -> V_204 ) ;
F_436 ( & V_22 -> V_79 ) ;
F_436 ( & V_22 -> V_200 ) ;
F_436 ( & V_22 -> V_624 ) ;
F_115 ( & V_22 -> V_755 , V_962 ) ;
F_115 ( & V_22 -> V_686 , V_963 ) ;
V_22 -> F_13 = F_437 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_73 ( & V_22 -> V_29 -> V_30 , L_298 ) ;
V_21 = - V_255 ;
goto V_964;
}
F_410 ( V_22 , 0 ) ;
V_21 = F_378 ( V_22 ) ;
if ( V_21 )
goto V_909;
V_21 = F_259 ( V_22 ) ;
if ( V_21 )
goto V_965;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_100 ) ;
V_22 -> V_952 = V_957 ;
V_957 ++ ;
V_21 = F_438 ( V_29 , F_325 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_955 = 1 ;
} else {
V_21 = F_438 ( V_29 , F_325 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_955 = 0 ;
} else {
F_73 ( & V_29 -> V_30 , L_299 ) ;
goto V_910;
}
}
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
V_21 = F_397 ( V_22 , F_321 , F_320 ) ;
if ( V_21 )
goto V_910;
V_21 = F_388 ( V_22 ) ;
if ( V_21 )
goto V_911;
V_21 = F_122 ( V_22 ) ;
if ( V_21 )
goto V_966;
F_439 ( & V_22 -> V_626 ) ;
F_439 ( & V_22 -> V_685 ) ;
F_439 ( & V_22 -> V_316 ) ;
F_440 ( & V_22 -> V_396 ) ;
V_22 -> V_625 = 1 ;
F_441 ( V_29 , V_22 ) ;
V_22 -> V_161 = 0 ;
F_436 ( & V_22 -> V_96 ) ;
V_21 = F_442 ( V_22 ) ;
if ( V_21 )
goto V_967;
V_21 = F_261 ( V_22 ) ;
if ( V_21 )
goto V_968;
V_22 -> V_924 = F_431 ( V_22 , L_300 ) ;
if ( ! V_22 -> V_924 ) {
V_21 = - V_255 ;
goto V_968;
}
V_22 -> V_320 = F_431 ( V_22 , L_301 ) ;
if ( ! V_22 -> V_320 ) {
V_21 = - V_255 ;
goto V_968;
}
if ( V_956 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_395 ( V_22 ) ;
V_21 = F_397 ( V_22 , F_319 ,
F_317 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_302 ) ;
F_404 ( V_22 ) ;
F_121 ( V_22 ) ;
F_387 ( V_22 ) ;
goto V_910;
}
V_21 = F_401 ( V_22 ) ;
if ( V_21 )
goto V_968;
F_94 ( & V_22 -> V_29 -> V_30 , L_303 ) ;
F_94 ( & V_22 -> V_29 -> V_30 ,
L_304 ) ;
V_22 -> V_114 . V_927 ( V_22 , V_969 ) ;
F_166 ( 10000 ) ;
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
V_21 = F_337 ( V_22 -> V_808 ) ;
if ( V_21 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_305 ) ;
F_403 ( V_22 ) ;
V_956 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_958;
}
V_22 -> V_56 = 1 ;
V_22 -> V_512 = 0 ;
V_22 -> V_114 . V_927 ( V_22 , V_969 ) ;
F_383 ( V_22 ) ;
V_22 -> V_946 = F_108 ( sizeof( * ( V_22 -> V_946 ) ) , V_201 ) ;
if ( ! V_22 -> V_946 )
F_94 ( & V_22 -> V_29 -> V_30 ,
L_306 ) ;
V_22 -> V_146 = V_148 ;
F_443 ( & V_22 -> V_948 , F_429 ) ;
F_430 ( & V_22 -> V_948 ,
V_22 -> V_146 ) ;
F_443 ( & V_22 -> V_947 , F_424 ) ;
F_428 ( V_22 -> V_924 , & V_22 -> V_947 ,
V_22 -> V_146 ) ;
return 0 ;
V_968:
F_404 ( V_22 ) ;
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
V_967:
F_121 ( V_22 ) ;
V_966:
F_387 ( V_22 ) ;
V_911:
F_395 ( V_22 ) ;
V_910:
F_405 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_965:
F_375 ( V_22 ) ;
V_909:
if ( V_22 -> F_13 ) {
F_406 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_964:
if ( V_22 -> V_320 ) {
F_407 ( V_22 -> V_320 ) ;
V_22 -> V_320 = NULL ;
}
if ( V_22 -> V_924 ) {
F_407 ( V_22 -> V_924 ) ;
V_22 -> V_924 = NULL ;
}
F_80 ( V_22 ) ;
return V_21 ;
}
static void F_444 ( struct V_1 * V_22 )
{
char * V_970 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( F_13 ( V_22 ) ) )
return;
V_970 = F_108 ( 4 , V_201 ) ;
if ( ! V_970 )
return;
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_763 , V_22 , V_970 , 4 , 0 ,
V_157 , V_387 ) ) {
goto V_388;
}
V_21 = F_165 ( V_22 , V_9 ,
V_265 , V_374 ) ;
if ( V_21 )
goto V_388;
if ( V_9 -> V_24 -> V_36 != 0 )
V_388:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_307 ) ;
F_172 ( V_22 , V_9 ) ;
F_80 ( V_970 ) ;
}
static void F_427 ( struct V_1 * V_22 )
{
T_4 * V_971 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_44 ( V_22 -> F_13 ) )
return;
V_971 = F_108 ( sizeof( * V_971 ) , V_201 ) ;
if ( ! V_971 ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_308 ) ;
return;
}
V_9 = F_170 ( V_22 ) ;
if ( F_171 ( V_9 , V_760 , V_22 , V_971 , 4 , 0 ,
V_157 , V_387 ) )
goto V_972;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_972;
* V_971 |= V_973 ;
if ( F_171 ( V_9 , V_762 , V_22 , V_971 , 4 , 0 ,
V_157 , V_387 ) )
goto V_972;
V_21 = F_165 ( V_22 , V_9 ,
V_265 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_972;
if ( F_171 ( V_9 , V_760 , V_22 , V_971 , 4 , 0 ,
V_157 , V_387 ) )
goto V_972;
V_21 = F_165 ( V_22 , V_9 ,
V_389 , V_374 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_972;
if ( * V_971 & V_973 )
goto V_388;
V_972:
F_73 ( & V_22 -> V_29 -> V_30 ,
L_309 ) ;
V_388:
F_172 ( V_22 , V_9 ) ;
F_80 ( V_971 ) ;
}
static void F_445 ( struct V_363 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_446 ( V_29 ) ;
F_444 ( V_22 ) ;
V_22 -> V_114 . V_927 ( V_22 , V_928 ) ;
F_395 ( V_22 ) ;
F_351 ( V_22 ) ;
}
static void F_447 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
F_80 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_448 ( struct V_363 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_446 ( V_29 ) == NULL ) {
F_73 ( & V_29 -> V_30 , L_310 ) ;
return;
}
V_22 = F_446 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_897 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_449 ( & V_22 -> V_948 ) ;
F_449 ( & V_22 -> V_947 ) ;
F_407 ( V_22 -> V_924 ) ;
F_407 ( V_22 -> V_320 ) ;
if ( V_22 -> V_59 )
F_450 ( V_22 -> V_59 ) ;
F_445 ( V_29 ) ;
F_447 ( V_22 ) ;
F_80 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_119 ( V_22 ) ;
F_404 ( V_22 ) ;
F_121 ( V_22 ) ;
F_387 ( V_22 ) ;
F_80 ( V_22 -> V_946 ) ;
F_405 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_375 ( V_22 ) ;
F_406 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_451 ( V_22 ) ;
F_80 ( V_22 ) ;
}
static void F_452 ( int V_974 [] , int V_975 ,
int V_976 , int V_977 , T_4 * V_978 )
{
int V_68 , V_191 , V_979 , V_450 ;
for ( V_68 = 0 ; V_68 <= V_976 ; V_68 ++ ) {
V_450 = V_68 + V_977 ;
V_979 = V_975 ;
for ( V_191 = 0 ; V_191 < V_975 ; V_191 ++ ) {
if ( V_974 [ V_191 ] >= V_450 ) {
V_979 = V_191 ;
break;
}
}
V_978 [ V_68 ] = V_979 ;
}
}
static int F_453 ( struct V_1 * V_22 , T_4 V_900 )
{
int V_68 ;
unsigned long V_980 ;
unsigned long V_63 = V_64 |
( V_900 & V_981 ) |
V_982 |
( V_900 & ( V_113 |
V_936 ) ) ;
struct V_983 V_114 = V_984 ;
int V_985 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_752 + 4 } ;
#define F_454 5
#define F_455 4
int V_986 [ 16 ] = { F_454 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_455 + V_987 } ;
F_275 ( F_26 ( V_986 ) != 16 ) ;
F_275 ( F_26 ( V_985 ) != 8 ) ;
F_275 ( F_243 ( struct V_138 , V_263 ) >
16 * F_454 ) ;
F_275 ( sizeof( struct V_259 ) != 16 ) ;
F_275 ( 28 > V_752 + 4 ) ;
if ( V_900 & ( V_113 | V_936 ) )
V_114 = V_988 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ )
memset ( V_22 -> V_112 [ V_68 ] . V_116 , 0 , V_22 -> V_923 ) ;
V_985 [ 7 ] = V_752 + 4 ;
F_452 ( V_985 , F_26 ( V_985 ) ,
V_752 , 4 , V_22 -> V_122 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_59 ( V_985 [ V_68 ] , & V_22 -> V_881 -> V_989 [ V_68 ] ) ;
F_59 ( V_22 -> V_120 , & V_22 -> V_881 -> V_990 ) ;
F_59 ( V_22 -> V_128 , & V_22 -> V_881 -> V_991 ) ;
F_59 ( 0 , & V_22 -> V_881 -> V_992 ) ;
F_59 ( 0 , & V_22 -> V_881 -> V_993 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
F_59 ( 0 , & V_22 -> V_881 -> V_994 [ V_68 ] . V_995 ) ;
F_59 ( V_22 -> V_112 [ V_68 ] . V_121 ,
& V_22 -> V_881 -> V_994 [ V_68 ] . V_996 ) ;
}
F_59 ( 0 , & V_22 -> V_808 -> V_831 . V_903 ) ;
F_59 ( V_63 , & ( V_22 -> V_808 -> V_831 . V_832 ) ) ;
if ( V_900 & V_113 ) {
V_114 = V_997 ;
F_59 ( 10 , & V_22 -> V_808 -> V_831 . V_833 ) ;
F_59 ( 4 , & V_22 -> V_808 -> V_831 . V_834 ) ;
} else {
if ( V_900 & V_936 ) {
V_114 = V_998 ;
F_59 ( 10 , & V_22 -> V_808 -> V_831 . V_833 ) ;
F_59 ( 4 , & V_22 -> V_808 -> V_831 . V_834 ) ;
}
}
F_59 ( V_898 , V_22 -> V_151 + V_803 ) ;
if ( F_373 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
return - V_81 ;
}
V_980 = F_328 ( & ( V_22 -> V_808 -> V_830 ) ) ;
if ( ! ( V_980 & V_64 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_312 ) ;
return - V_81 ;
}
V_22 -> V_114 = V_114 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_900 & V_113 ) ||
( V_900 & V_936 ) ) )
return 0 ;
if ( V_900 & V_113 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
F_59 ( V_68 , V_22 -> V_151 + V_999 ) ;
V_22 -> V_112 [ V_68 ] . V_117 =
F_328 ( V_22 -> V_151 + V_1000 ) ;
}
V_985 [ 7 ] = V_22 -> V_536 + 8 ;
F_452 ( V_985 , F_26 ( V_985 ) , V_22 -> V_536 , 8 ,
V_22 -> V_133 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ )
memset ( V_22 -> V_112 [ V_68 ] . V_116 ,
( T_1 ) V_1001 ,
V_22 -> V_923 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
struct V_129 * V_130 = & V_22 -> V_131 [ V_68 ] ;
V_130 -> V_1002 = V_1003 ;
V_130 -> V_24 = ( T_4 ) ( V_22 -> V_617 +
( V_68 * sizeof( struct V_330 ) ) ) ;
V_130 -> V_1004 = sizeof( struct V_330 ) ;
V_130 -> V_1005 = V_1006 ;
V_130 -> V_1007 =
F_153 ( V_1008 ) ;
V_130 -> V_1009 = 0 ;
V_130 -> V_127 = 0 ;
V_130 -> V_342 =
F_127 ( ( V_68 << V_567 ) ) ;
V_130 -> V_1010 =
F_127 ( V_22 -> V_539 +
( V_68 * sizeof( struct V_129 ) ) ) ;
}
} else if ( V_900 & V_936 ) {
T_5 V_811 , V_813 ;
T_4 V_1011 , V_812 ;
int V_21 ;
V_21 = F_342 ( V_22 -> V_29 , V_22 -> V_151 , & V_812 ,
& V_813 , & V_811 ) ;
F_275 ( F_243 ( struct V_138 , V_263 ) != 64 ) ;
V_986 [ 15 ] = V_22 -> V_536 + F_455 ;
F_452 ( V_986 , F_26 ( V_986 ) , V_22 -> V_536 ,
4 , V_22 -> V_137 ) ;
V_1011 = F_328 ( & V_22 -> V_808 -> V_1012 ) ;
F_275 ( F_243 ( struct V_807 ,
V_1012 ) != 0xb8 ) ;
V_22 -> V_1013 =
F_307 ( F_343 ( V_22 -> V_29 ,
V_813 ) +
V_811 + V_1011 ,
F_26 ( V_986 ) *
sizeof( * V_22 -> V_1013 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_986 ) ; V_68 ++ )
F_59 ( V_986 [ V_68 ] , & V_22 -> V_1013 [ V_68 ] ) ;
}
F_59 ( V_898 , V_22 -> V_151 + V_803 ) ;
if ( F_373 ( V_22 ) ) {
F_73 ( & V_22 -> V_29 -> V_30 ,
L_313 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_456 ( struct V_1 * V_22 )
{
if ( V_22 -> V_131 ) {
F_329 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_131 ) ,
V_22 -> V_131 ,
V_22 -> V_539 ) ;
V_22 -> V_131 = NULL ;
V_22 -> V_539 = 0 ;
}
F_80 ( V_22 -> V_133 ) ;
V_22 -> V_133 = NULL ;
}
static int F_457 ( struct V_1 * V_22 )
{
V_22 -> V_536 =
F_328 ( & ( V_22 -> V_808 -> V_1014 ) ) ;
if ( V_22 -> V_536 > V_1015 )
V_22 -> V_536 = V_1015 ;
F_275 ( sizeof( struct V_129 ) %
V_1016 ) ;
V_22 -> V_131 =
F_327 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_131 ) ,
& ( V_22 -> V_539 ) ) ;
V_22 -> V_133 =
F_91 ( ( ( V_22 -> V_536 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ( V_22 -> V_131 == NULL ) ||
( V_22 -> V_133 == NULL ) )
goto V_916;
memset ( V_22 -> V_131 , 0 ,
V_22 -> V_235 * sizeof( * V_22 -> V_131 ) ) ;
return 0 ;
V_916:
F_456 ( V_22 ) ;
return - V_255 ;
}
static void F_458 ( struct V_1 * V_22 )
{
F_119 ( V_22 ) ;
if ( V_22 -> V_136 ) {
F_329 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_136 ) ,
V_22 -> V_136 ,
V_22 -> V_558 ) ;
V_22 -> V_136 = NULL ;
V_22 -> V_558 = 0 ;
}
F_80 ( V_22 -> V_137 ) ;
V_22 -> V_137 = NULL ;
}
static int F_459 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_536 =
F_328 ( & ( V_22 -> V_808 -> V_1014 ) ) ;
if ( V_22 -> V_536 > V_987 )
V_22 -> V_536 = V_987 ;
F_275 ( sizeof( struct V_138 ) %
V_1017 ) ;
V_22 -> V_136 =
F_327 ( V_22 -> V_29 ,
V_22 -> V_235 * sizeof( * V_22 -> V_136 ) ,
& ( V_22 -> V_558 ) ) ;
V_22 -> V_137 =
F_91 ( ( ( V_22 -> V_536 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ( V_22 -> V_136 == NULL ) ||
( V_22 -> V_137 == NULL ) ) {
V_21 = - V_255 ;
goto V_916;
}
V_21 = F_120 ( V_22 ) ;
if ( V_21 )
goto V_916;
memset ( V_22 -> V_136 , 0 ,
V_22 -> V_235 * sizeof( * V_22 -> V_136 ) ) ;
return 0 ;
V_916:
F_458 ( V_22 ) ;
return V_21 ;
}
static void F_404 ( struct V_1 * V_22 )
{
F_80 ( V_22 -> V_122 ) ;
V_22 -> V_122 = NULL ;
F_402 ( V_22 ) ;
F_456 ( V_22 ) ;
F_458 ( V_22 ) ;
}
static int F_442 ( struct V_1 * V_22 )
{
T_4 V_900 ;
unsigned long V_63 = V_64 |
V_981 ;
int V_68 , V_21 ;
if ( V_960 )
return 0 ;
V_900 = F_328 ( & ( V_22 -> V_808 -> V_829 ) ) ;
if ( ! ( V_900 & V_1018 ) )
return 0 ;
if ( V_900 & V_113 ) {
V_63 |= V_113 |
V_982 ;
V_21 = F_457 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_900 & V_936 ) {
V_63 |= V_936 |
V_982 ;
V_21 = F_459 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_128 = V_22 -> V_125 > 0 ? V_22 -> V_125 : 1 ;
F_363 ( V_22 ) ;
V_22 -> V_923 = V_22 -> V_120 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_128 ; V_68 ++ ) {
V_22 -> V_112 [ V_68 ] . V_116 = F_327 ( V_22 -> V_29 ,
V_22 -> V_923 ,
& ( V_22 -> V_112 [ V_68 ] . V_121 ) ) ;
if ( ! V_22 -> V_112 [ V_68 ] . V_116 ) {
V_21 = - V_255 ;
goto V_964;
}
V_22 -> V_112 [ V_68 ] . V_450 = V_22 -> V_120 ;
V_22 -> V_112 [ V_68 ] . V_118 = 1 ;
V_22 -> V_112 [ V_68 ] . V_117 = 0 ;
}
V_22 -> V_122 = F_91 ( ( ( V_752 + 1 ) *
sizeof( T_4 ) ) , V_201 ) ;
if ( ! V_22 -> V_122 ) {
V_21 = - V_255 ;
goto V_964;
}
V_21 = F_453 ( V_22 , V_900 ) ;
if ( V_21 )
goto V_909;
return 0 ;
V_909:
F_80 ( V_22 -> V_122 ) ;
V_22 -> V_122 = NULL ;
V_964:
F_402 ( V_22 ) ;
F_456 ( V_22 ) ;
F_458 ( V_22 ) ;
return V_21 ;
}
static int F_460 ( struct V_8 * V_9 )
{
return V_9 -> V_149 == V_150 || V_9 -> V_149 == V_153 ;
}
static void F_416 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1019 ;
int V_399 ;
do {
V_1019 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_235 ; V_68 ++ ) {
V_9 = V_22 -> V_398 + V_68 ;
V_399 = F_178 ( & V_9 -> V_399 ) ;
if ( V_399 > 1 )
V_1019 += F_460 ( V_9 ) ;
F_172 ( V_22 , V_9 ) ;
}
if ( V_1019 <= 0 )
break;
F_166 ( 100 ) ;
} while ( 1 );
}
static struct V_1020 * F_461 (
struct V_1021 * V_1021 )
{
struct V_1020 * V_1020 ;
struct V_1022 * V_1023 ;
V_1020 = F_108 ( sizeof( * V_1020 ) , V_201 ) ;
if ( ! V_1020 )
return NULL ;
V_1023 = F_462 ( V_1021 -> V_1024 -> V_1025 ,
V_1021 -> V_1026 ) ;
if ( ! V_1023 ) {
F_80 ( V_1020 ) ;
return NULL ;
}
V_1021 -> V_1026 ++ ;
V_1020 -> V_1023 = V_1023 ;
V_1020 -> V_1027 = V_1021 ;
return V_1020 ;
}
static void F_463 ( struct V_1020 * V_1020 )
{
struct V_1022 * V_1023 = V_1020 -> V_1023 ;
F_464 ( V_1020 -> V_1027 -> V_1028 , V_1023 ) ;
F_465 ( V_1023 ) ;
if ( V_1020 -> V_1029 )
F_422 ( & V_1020 -> V_1030 ) ;
F_80 ( V_1020 ) ;
}
static int F_466 ( struct V_1020 * V_1020 )
{
int V_21 ;
struct V_1021 * V_1021 ;
struct V_1022 * V_1023 ;
struct V_1031 * V_1032 ;
V_1021 = V_1020 -> V_1027 ;
V_1023 = V_1020 -> V_1023 ;
V_1032 = & V_1023 -> V_1032 ;
memset ( V_1032 , 0 , sizeof( * V_1032 ) ) ;
V_1032 -> V_434 = V_1021 -> V_434 ;
V_1032 -> V_1033 = V_1034 ;
V_1032 -> V_1035 = V_1036 ;
V_1032 -> V_1037 = V_1036 ;
V_1023 -> V_1038 = V_1039 ;
V_1023 -> V_1040 = V_1039 ;
V_1023 -> V_1041 = V_1039 ;
V_1023 -> V_1042 = V_1039 ;
V_1023 -> V_1043 = V_1039 ;
V_21 = F_467 ( V_1020 -> V_1023 ) ;
if ( V_21 )
return V_21 ;
F_468 ( V_1021 -> V_1028 , V_1020 -> V_1023 ) ;
F_92 ( & V_1020 -> V_1030 ,
& V_1021 -> V_1044 ) ;
V_1020 -> V_1029 = true ;
return 0 ;
}
static int
F_469 ( struct V_1021 * V_1021 ,
struct V_248 * V_249 )
{
struct V_1031 * V_1032 ;
V_1032 = & V_249 -> V_1032 ;
V_1032 -> V_434 = V_1021 -> V_434 ;
V_1032 -> V_1035 = V_1036 ;
V_1032 -> V_1037 = V_1036 ;
return F_470 ( V_249 ) ;
}
static struct V_1021
* F_471 ( struct V_1045 * V_1045 ,
T_5 V_434 )
{
int V_21 ;
struct V_1021 * V_1021 ;
struct V_1046 * V_1028 ;
V_1021 = F_108 ( sizeof( * V_1021 ) , V_201 ) ;
if ( ! V_1021 )
return NULL ;
F_435 ( & V_1021 -> V_1044 ) ;
V_1021 -> V_1024 = V_1045 ;
V_1028 = F_472 ( V_1045 -> V_1025 ) ;
if ( ! V_1028 )
goto V_1047;
V_21 = F_473 ( V_1028 ) ;
if ( V_21 )
goto V_1048;
V_1021 -> V_1028 = V_1028 ;
V_1021 -> V_434 = V_434 ;
F_92 ( & V_1021 -> V_1049 ,
& V_1045 -> V_1050 ) ;
return V_1021 ;
V_1048:
F_474 ( V_1028 ) ;
V_1047:
F_80 ( V_1021 ) ;
return NULL ;
}
static void F_475 ( struct V_1021 * V_1021 )
{
struct V_1020 * V_1020 ;
struct V_1020 * V_1051 ;
F_476 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_463 ( V_1020 ) ;
F_477 ( V_1021 -> V_1028 ) ;
F_422 ( & V_1021 -> V_1049 ) ;
F_80 ( V_1021 ) ;
}
static struct V_1045 * F_478 ( struct V_42 * V_1025 )
{
struct V_1045 * V_1045 ;
V_1045 = F_108 ( sizeof( * V_1045 ) , V_201 ) ;
if ( V_1045 ) {
V_1045 -> V_1025 = V_1025 ;
F_435 ( & V_1045 -> V_1050 ) ;
}
return V_1045 ;
}
static void F_479 ( struct V_1045 * V_1045 )
{
struct V_1021 * V_1021 ;
struct V_1021 * V_1051 ;
if ( ! V_1045 )
return;
F_476 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_475 ( V_1021 ) ;
F_80 ( V_1045 ) ;
}
static struct V_73
* F_113 ( struct V_1 * V_22 ,
struct V_248 * V_249 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_161 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1046 )
continue;
if ( V_42 -> V_1046 -> V_249 == V_249 )
return V_42 ;
}
return NULL ;
}
static int F_228 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1025 ;
struct V_1045 * V_1045 ;
struct V_1021 * V_1021 ;
struct V_1020 * V_1020 ;
V_1025 = & V_22 -> V_59 -> V_1052 ;
V_1045 = F_478 ( V_1025 ) ;
if ( ! V_1045 )
return - V_255 ;
V_1021 = F_471 ( V_1045 , V_22 -> V_434 ) ;
if ( ! V_1021 ) {
V_21 = - V_81 ;
goto V_1053;
}
V_1020 = F_461 ( V_1021 ) ;
if ( ! V_1020 ) {
V_21 = - V_81 ;
goto V_1048;
}
V_21 = F_466 ( V_1020 ) ;
if ( V_21 )
goto V_1054;
V_22 -> V_236 = V_1045 ;
return 0 ;
V_1054:
F_463 ( V_1020 ) ;
V_1048:
F_475 ( V_1021 ) ;
V_1053:
F_479 ( V_1045 ) ;
return V_21 ;
}
static void F_451 ( struct V_1 * V_22 )
{
F_479 ( V_22 -> V_236 ) ;
}
static int F_101 ( struct V_1045 * V_1045 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1021 * V_1021 ;
struct V_248 * V_249 ;
V_1021 = F_471 ( V_1045 , V_42 -> V_434 ) ;
if ( ! V_1021 )
return - V_255 ;
V_249 = F_480 ( V_1021 -> V_1028 ) ;
if ( ! V_249 ) {
V_21 = - V_81 ;
goto V_1048;
}
V_1021 -> V_249 = V_249 ;
V_42 -> V_1046 = V_1021 ;
V_21 = F_469 ( V_1021 , V_249 ) ;
if ( V_21 )
goto V_1048;
return 0 ;
V_1048:
F_475 ( V_1021 ) ;
V_42 -> V_1046 = NULL ;
return V_21 ;
}
static void F_106 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1046 ) {
F_475 ( V_42 -> V_1046 ) ;
V_42 -> V_1046 = NULL ;
}
}
static int
F_481 ( struct V_1022 * V_1023 )
{
return 0 ;
}
static int
F_482 ( struct V_248 * V_249 , T_5 * V_1055 )
{
return 0 ;
}
static int
F_483 ( struct V_248 * V_249 )
{
return - V_1056 ;
}
static int
F_484 ( struct V_1022 * V_1023 , int V_1057 )
{
return 0 ;
}
static int
F_485 ( struct V_1022 * V_1023 , int V_1058 )
{
return 0 ;
}
static int
F_486 ( struct V_1022 * V_1023 )
{
return 0 ;
}
static void
F_487 ( struct V_1022 * V_1023 )
{
}
static int
F_488 ( struct V_1022 * V_1023 , struct V_1059 * V_1060 )
{
return - V_55 ;
}
static int
F_489 ( struct V_6 * V_47 , struct V_248 * V_249 ,
struct V_621 * V_1061 )
{
return - V_55 ;
}
static int T_18 F_490 ( void )
{
int V_21 ;
V_642 =
F_491 ( & V_1062 ) ;
if ( ! V_642 )
return - V_81 ;
V_21 = F_492 ( & V_1063 ) ;
if ( V_21 )
F_493 ( V_642 ) ;
return V_21 ;
}
static void T_19 F_494 ( void )
{
F_495 ( & V_1063 ) ;
F_493 ( V_642 ) ;
}
