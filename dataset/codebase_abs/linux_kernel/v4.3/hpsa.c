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
static T_2 F_32 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
T_2 V_73 = 0 ;
unsigned char V_74 ;
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
V_3 = F_33 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_76 = V_3 -> V_79 ;
if ( ! V_76 ) {
F_35 ( & V_22 -> V_78 , V_77 ) ;
return - V_80 ;
}
if ( ! F_31 ( V_76 -> V_72 ) ) {
F_35 ( & V_22 -> V_78 , V_77 ) ;
V_73 = snprintf ( V_45 , V_81 , L_20 ) ;
return V_73 ;
}
V_74 = V_76 -> V_82 ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( V_74 > V_83 )
V_74 = V_83 ;
V_73 = snprintf ( V_45 , V_81 , L_21 , V_84 [ V_74 ] ) ;
return V_73 ;
}
static T_2 F_36 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
unsigned char V_85 [ 8 ] ;
V_3 = F_33 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_76 = V_3 -> V_79 ;
if ( ! V_76 ) {
F_35 ( & V_22 -> V_78 , V_77 ) ;
return - V_80 ;
}
memcpy ( V_85 , V_76 -> V_72 , sizeof( V_85 ) ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
return snprintf ( V_45 , 20 , L_22 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] ,
V_85 [ 4 ] , V_85 [ 5 ] , V_85 [ 6 ] , V_85 [ 7 ] ) ;
}
static T_2 F_37 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
unsigned char V_86 [ 16 ] ;
V_3 = F_33 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_76 = V_3 -> V_79 ;
if ( ! V_76 ) {
F_35 ( & V_22 -> V_78 , V_77 ) ;
return - V_80 ;
}
memcpy ( V_86 , V_76 -> V_87 , sizeof( V_86 ) ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
return snprintf ( V_45 , 16 * 2 + 2 ,
L_23
L_24 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] , V_86 [ 3 ] ,
V_86 [ 4 ] , V_86 [ 5 ] , V_86 [ 6 ] , V_86 [ 7 ] ,
V_86 [ 8 ] , V_86 [ 9 ] , V_86 [ 10 ] , V_86 [ 11 ] ,
V_86 [ 12 ] , V_86 [ 13 ] , V_86 [ 14 ] , V_86 [ 15 ] ) ;
}
static T_2 F_38 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
int V_88 ;
V_3 = F_33 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_76 = V_3 -> V_79 ;
if ( ! V_76 ) {
F_35 ( & V_22 -> V_78 , V_77 ) ;
return - V_80 ;
}
V_88 = V_76 -> V_88 ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
return snprintf ( V_45 , 20 , L_15 , V_88 ) ;
}
static T_2 F_39 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
unsigned long V_77 ;
int V_68 ;
int V_89 = 0 ;
T_1 V_90 ;
T_1 V_91 ;
T_1 V_92 = 0 ;
char * V_93 ;
unsigned char V_94 [ 2 ] ;
unsigned char V_95 [ V_96 ] [ V_97 ] ;
memset ( V_95 , 0 , V_96 * V_97 ) ;
V_3 = F_33 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_98 , V_77 ) ;
V_76 = V_3 -> V_79 ;
if ( ! V_76 ) {
F_35 ( & V_22 -> V_98 , V_77 ) ;
return - V_80 ;
}
V_91 = V_76 -> V_91 ;
for ( V_68 = 0 ; V_68 < V_96 ; V_68 ++ ) {
V_92 = 1 << V_68 ;
if ( V_68 == V_76 -> V_99 )
V_93 = L_25 ;
else if ( V_76 -> V_100 & V_92 )
V_93 = L_26 ;
else
continue;
V_89 = snprintf ( V_95 [ V_68 ] ,
V_97 , L_27 ,
V_22 -> V_59 -> V_101 ,
V_76 -> V_102 , V_76 -> V_103 , V_76 -> V_104 ,
F_40 ( V_76 -> V_105 ) ) ;
if ( F_41 ( V_22 , V_76 ) ||
( V_76 -> V_105 == V_106 ) ||
F_31 ( V_76 -> V_72 ) ) {
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 , L_16 ,
V_93 ) ;
continue;
}
V_90 = V_76 -> V_90 [ V_68 ] ;
memcpy ( & V_94 , & V_76 -> V_94 [ V_68 ] ,
sizeof( V_94 ) ) ;
if ( V_94 [ 0 ] < '0' )
V_94 [ 0 ] = '0' ;
if ( V_94 [ 1 ] < '0' )
V_94 [ 1 ] = '0' ;
if ( V_76 -> V_94 [ V_68 ] > 0 )
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 ,
L_28 ,
V_94 ) ;
if ( V_76 -> V_105 == V_107 &&
V_76 -> V_108 != V_109 ) {
if ( V_90 == 0 || V_90 == 0xFF ) {
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 ,
L_29 ,
V_91 , V_93 ) ;
} else {
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 ,
L_30 ,
V_90 , V_91 , V_93 ) ;
}
} else if ( V_90 != 0 && V_90 != 0xFF ) {
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 , L_31 ,
V_90 , V_93 ) ;
} else
V_89 += snprintf ( V_95 [ V_68 ] + V_89 ,
V_97 , L_16 , V_93 ) ;
}
F_35 ( & V_22 -> V_98 , V_77 ) ;
return snprintf ( V_45 , V_89 + 1 , L_32 ,
V_95 [ 0 ] , V_95 [ 1 ] , V_95 [ 2 ] , V_95 [ 3 ] ,
V_95 [ 4 ] , V_95 [ 5 ] , V_95 [ 6 ] , V_95 [ 7 ] ) ;
}
static inline T_4 F_42 ( struct V_1 * V_22 , T_1 V_110 )
{
T_4 V_65 ;
struct V_111 * V_112 = & V_22 -> V_113 [ V_110 ] ;
if ( V_22 -> V_63 & V_114 )
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
if ( F_43 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
if ( ( V_112 -> V_117 [ V_112 -> V_118 ] & 1 ) == V_112 -> V_119 ) {
V_65 = V_112 -> V_117 [ V_112 -> V_118 ] ;
V_112 -> V_118 ++ ;
F_44 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_120 ;
}
if ( V_112 -> V_118 == V_22 -> V_121 ) {
V_112 -> V_118 = 0 ;
V_112 -> V_119 ^= 1 ;
}
return V_65 ;
}
static void F_45 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_113 )
{
if ( F_46 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_122 |= 1 | ( V_22 -> V_123 [ V_9 -> V_124 . V_125 ] << 1 ) ;
if ( F_43 ( ! V_22 -> V_126 ) )
return;
if ( F_46 ( V_113 == V_127 ) )
V_9 -> V_124 . V_128 =
F_47 () % V_22 -> V_129 ;
else
V_9 -> V_124 . V_128 = V_113 % V_22 -> V_129 ;
}
}
static void F_48 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
if ( F_46 ( V_113 == V_127 ) )
V_131 -> V_128 = F_49 () % V_22 -> V_129 ;
else
V_131 -> V_128 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= 1 | ( V_22 -> V_134 [ V_9 -> V_124 . V_125 ] << 1 ) |
V_135 ;
}
static void F_50 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_136 * V_131 = (struct V_136 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_46 ( V_113 == V_127 ) )
V_131 -> V_113 = F_49 () % V_22 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= V_22 -> V_138 [ 0 ] ;
}
static void F_51 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_46 ( V_113 == V_127 ) )
V_131 -> V_113 = F_49 () % V_22 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= ( V_22 -> V_138 [ V_131 -> V_140 ] ) ;
}
static int F_52 ( T_1 * V_141 )
{
return V_141 [ 0 ] == V_142 && V_141 [ 6 ] == V_143 ;
}
static void F_53 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_52 ( V_9 -> V_144 . V_145 ) )
return;
F_54 ( & V_22 -> V_146 ) ;
V_22 -> V_147 = V_148 ;
}
static void F_55 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_52 ( V_9 -> V_144 . V_145 ) &&
F_56 ( & V_22 -> V_146 ) )
V_22 -> V_147 = V_149 ;
}
static void F_57 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_113 )
{
F_53 ( V_22 , V_9 ) ;
F_54 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_150 ) {
case V_151 :
F_48 ( V_22 , V_9 , V_113 ) ;
F_58 ( V_9 -> V_122 , V_22 -> V_152 + V_153 ) ;
break;
case V_154 :
F_51 ( V_22 , V_9 , V_113 ) ;
F_58 ( V_9 -> V_122 , V_22 -> V_152 + V_155 ) ;
break;
case V_156 :
F_50 ( V_22 , V_9 , V_113 ) ;
F_58 ( V_9 -> V_122 , V_22 -> V_152 + V_155 ) ;
break;
default:
F_45 ( V_22 , V_9 , V_113 ) ;
V_22 -> V_115 . V_157 ( V_22 , V_9 ) ;
}
}
static void F_59 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_43 ( F_5 ( V_9 ) ) )
return F_60 ( V_9 ) ;
F_57 ( V_22 , V_9 , V_127 ) ;
}
static inline int F_61 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_158 , 8 ) == 0 ;
}
static inline int F_62 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_61 )
return 0 ;
if ( ( V_22 -> V_61 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_22 ,
unsigned char V_72 [] , int V_102 , int * V_103 , int * V_104 )
{
int V_68 , V_159 = 0 ;
F_64 ( V_160 , V_161 ) ;
F_65 ( V_160 , V_161 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_102 == V_102 && V_22 -> V_30 [ V_68 ] -> V_103 != - 1 )
F_66 ( V_22 -> V_30 [ V_68 ] -> V_103 , V_160 ) ;
}
V_68 = F_67 ( V_160 , V_161 ) ;
if ( V_68 < V_161 ) {
* V_103 = V_68 ;
* V_104 = 0 ;
V_159 = 1 ;
}
return ! V_159 ;
}
static inline void F_68 ( const char * V_163 , struct V_1 * V_22 ,
struct V_75 * V_30 , char * V_164 )
{
F_69 ( V_163 , & V_22 -> V_29 -> V_30 ,
L_33 ,
V_22 -> V_59 -> V_101 , V_30 -> V_102 , V_30 -> V_103 , V_30 -> V_104 ,
V_164 ,
F_40 ( V_30 -> V_105 ) ,
V_30 -> V_165 ,
V_30 -> V_166 ,
V_30 -> V_82 > V_83 ?
L_34 : V_84 [ V_30 -> V_82 ] ,
V_30 -> V_167 ? '+' : '-' ,
V_30 -> V_88 ? '+' : '-' ,
V_30 -> V_108 ) ;
}
static int F_70 ( struct V_1 * V_22 , int V_168 ,
struct V_75 * V_42 ,
struct V_75 * V_169 [] , int * V_170 )
{
int V_171 = V_22 -> V_162 ;
int V_68 ;
unsigned char V_172 [ 8 ] , V_173 [ 8 ] ;
struct V_75 * V_174 ;
if ( V_171 >= V_161 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_35
L_36 ) ;
return - 1 ;
}
if ( V_42 -> V_104 != - 1 )
goto V_175;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_63 ( V_22 , V_42 -> V_72 ,
V_42 -> V_102 , & V_42 -> V_103 , & V_42 -> V_104 ) != 0 )
return - 1 ;
goto V_175;
}
memcpy ( V_172 , V_42 -> V_72 , 8 ) ;
V_172 [ 4 ] = 0 ;
V_172 [ 5 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_171 ; V_68 ++ ) {
V_174 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_173 , V_174 -> V_72 , 8 ) ;
V_173 [ 4 ] = 0 ;
V_173 [ 5 ] = 0 ;
if ( memcmp ( V_172 , V_173 , 8 ) == 0 ) {
V_42 -> V_102 = V_174 -> V_102 ;
V_42 -> V_103 = V_174 -> V_103 ;
V_42 -> V_104 = V_42 -> V_72 [ 4 ] ;
break;
}
}
if ( V_42 -> V_104 == - 1 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_37
L_38
L_39 ) ;
return - 1 ;
}
V_175:
V_22 -> V_30 [ V_171 ] = V_42 ;
V_22 -> V_162 ++ ;
V_169 [ * V_170 ] = V_42 ;
( * V_170 ) ++ ;
F_68 ( V_176 , V_22 , V_42 ,
V_42 -> V_108 & V_177 ? L_40 : L_41 ) ;
V_42 -> V_178 = V_42 -> V_88 ;
V_42 -> V_88 = 0 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_22 , int V_168 ,
int V_179 , struct V_75 * V_180 )
{
int V_88 ;
F_73 ( V_179 < 0 || V_179 >= V_161 ) ;
V_22 -> V_30 [ V_179 ] -> V_82 = V_180 -> V_82 ;
if ( V_180 -> V_167 && V_180 -> V_88 ) {
V_22 -> V_30 [ V_179 ] -> V_181 = V_180 -> V_181 ;
V_22 -> V_30 [ V_179 ] -> V_182 = V_180 -> V_182 ;
}
if ( V_180 -> V_183 ) {
V_22 -> V_30 [ V_179 ] -> V_182 = V_180 -> V_182 ;
F_74 () ;
}
V_22 -> V_30 [ V_179 ] -> V_183 = V_180 -> V_183 ;
V_22 -> V_30 [ V_179 ] -> V_167 = V_180 -> V_167 ;
V_22 -> V_30 [ V_179 ] -> V_184 = V_180 -> V_184 ;
V_22 -> V_30 [ V_179 ] -> V_185 = V_180 -> V_185 ;
V_22 -> V_30 [ V_179 ] -> V_178 = V_180 -> V_88 ;
if ( ! V_180 -> V_88 )
V_22 -> V_30 [ V_179 ] -> V_88 = 0 ;
V_88 = V_22 -> V_30 [ V_179 ] -> V_88 ;
V_22 -> V_30 [ V_179 ] -> V_88 = V_22 -> V_30 [ V_179 ] -> V_178 ;
F_68 ( V_176 , V_22 , V_22 -> V_30 [ V_179 ] , L_42 ) ;
V_22 -> V_30 [ V_179 ] -> V_88 = V_88 ;
}
static void F_75 ( struct V_1 * V_22 , int V_168 ,
int V_179 , struct V_75 * V_180 ,
struct V_75 * V_169 [] , int * V_170 ,
struct V_75 * V_186 [] , int * V_187 )
{
F_73 ( V_179 < 0 || V_179 >= V_161 ) ;
V_186 [ * V_187 ] = V_22 -> V_30 [ V_179 ] ;
( * V_187 ) ++ ;
if ( V_180 -> V_103 == - 1 ) {
V_180 -> V_103 = V_22 -> V_30 [ V_179 ] -> V_103 ;
V_180 -> V_104 = V_22 -> V_30 [ V_179 ] -> V_104 ;
}
V_22 -> V_30 [ V_179 ] = V_180 ;
V_169 [ * V_170 ] = V_180 ;
( * V_170 ) ++ ;
F_68 ( V_176 , V_22 , V_180 , L_43 ) ;
V_180 -> V_178 = V_180 -> V_88 ;
V_180 -> V_88 = 0 ;
}
static void F_76 ( struct V_1 * V_22 , int V_168 , int V_179 ,
struct V_75 * V_186 [] , int * V_187 )
{
int V_68 ;
struct V_75 * V_174 ;
F_73 ( V_179 < 0 || V_179 >= V_161 ) ;
V_174 = V_22 -> V_30 [ V_179 ] ;
V_186 [ * V_187 ] = V_22 -> V_30 [ V_179 ] ;
( * V_187 ) ++ ;
for ( V_68 = V_179 ; V_68 < V_22 -> V_162 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_162 -- ;
F_68 ( V_176 , V_22 , V_174 , L_44 ) ;
}
static void F_77 ( struct V_1 * V_22 ,
struct V_75 * V_169 )
{
unsigned long V_77 ;
int V_68 , V_188 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_169 ) {
for ( V_188 = V_68 ; V_188 < V_22 -> V_162 - 1 ; V_188 ++ )
V_22 -> V_30 [ V_188 ] = V_22 -> V_30 [ V_188 + 1 ] ;
V_22 -> V_162 -- ;
break;
}
}
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_78 ( V_169 ) ;
}
static inline int F_79 ( struct V_75 * V_189 ,
struct V_75 * V_190 )
{
if ( memcmp ( V_189 -> V_72 , V_190 -> V_72 ,
sizeof( V_189 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_189 -> V_87 , V_190 -> V_87 ,
sizeof( V_189 -> V_87 ) ) != 0 )
return 0 ;
if ( memcmp ( V_189 -> V_166 , V_190 -> V_166 , sizeof( V_189 -> V_166 ) ) != 0 )
return 0 ;
if ( memcmp ( V_189 -> V_165 , V_190 -> V_165 , sizeof( V_189 -> V_165 ) ) != 0 )
return 0 ;
if ( V_189 -> V_105 != V_190 -> V_105 )
return 0 ;
if ( V_189 -> V_102 != V_190 -> V_102 )
return 0 ;
return 1 ;
}
static inline int F_80 ( struct V_75 * V_189 ,
struct V_75 * V_190 )
{
if ( V_189 -> V_82 != V_190 -> V_82 )
return 1 ;
if ( V_189 -> V_167 != V_190 -> V_167 )
return 1 ;
if ( V_189 -> V_88 != V_190 -> V_88 )
return 1 ;
if ( ! F_31 ( V_189 -> V_72 ) )
if ( V_189 -> V_185 != V_190 -> V_185 )
return 1 ;
return 0 ;
}
static int F_81 ( struct V_75 * V_191 ,
struct V_75 * V_192 [] , int V_193 ,
int * V_194 )
{
int V_68 ;
#define F_82 0
#define F_83 1
#define F_84 2
#define F_85 3
for ( V_68 = 0 ; V_68 < V_193 ; V_68 ++ ) {
if ( V_192 [ V_68 ] == NULL )
continue;
if ( F_86 ( V_191 -> V_72 , V_192 [ V_68 ] -> V_72 ) ) {
* V_194 = V_68 ;
if ( F_79 ( V_191 , V_192 [ V_68 ] ) ) {
if ( F_80 ( V_191 , V_192 [ V_68 ] ) )
return F_85 ;
return F_84 ;
} else {
if ( V_191 -> V_195 )
return F_82 ;
return F_83 ;
}
}
}
* V_194 = - 1 ;
return F_82 ;
}
static void F_87 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_196 * V_42 ;
unsigned long V_77 ;
F_34 ( & V_22 -> V_197 , V_77 ) ;
F_88 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_35 ( & V_22 -> V_197 , V_77 ) ;
return;
}
}
F_35 ( & V_22 -> V_197 , V_77 ) ;
V_42 = F_89 ( sizeof( * V_42 ) , V_198 ) ;
if ( ! V_42 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_45 , V_199 ) ;
return;
}
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_34 ( & V_22 -> V_197 , V_77 ) ;
F_90 ( & V_42 -> V_200 , & V_22 -> V_201 ) ;
F_35 ( & V_22 -> V_197 , V_77 ) ;
}
static void F_91 ( struct V_1 * V_22 ,
struct V_75 * V_174 )
{
if ( V_174 -> V_195 == V_202 )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_46 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
switch ( V_174 -> V_195 ) {
case V_203 :
break;
case V_204 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_47 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_205 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_48 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_206 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_49 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_207 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_50 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_208 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_51 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_209 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_52 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_210 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_53 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_211 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_54 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_212 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_55 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_213 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_56 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
case V_214 :
F_92 ( & V_22 -> V_29 -> V_30 ,
L_57 ,
V_22 -> V_59 -> V_101 ,
V_174 -> V_102 , V_174 -> V_103 , V_174 -> V_104 ) ;
break;
}
}
static void F_93 ( struct V_1 * V_22 ,
struct V_75 * V_30 [] , int V_162 ,
struct V_75 * V_215 )
{
struct V_216 * V_217 = & V_215 -> V_181 ;
struct V_218 * V_219 = & V_217 -> V_220 [ 0 ] ;
int V_68 , V_188 ;
int V_221 = F_94 ( V_217 -> V_222 ) +
F_94 ( V_217 -> V_223 ) ;
int V_224 = F_94 ( V_217 -> V_225 ) *
F_94 ( V_217 -> V_226 ) *
V_221 ;
int V_227 = F_94 ( V_217 -> V_226 ) *
V_221 ;
int V_228 ;
if ( V_224 > V_229 )
V_224 = V_229 ;
V_215 -> V_230 = V_224 ;
V_228 = 0 ;
for ( V_68 = 0 ; V_68 < V_224 ; V_68 ++ ) {
V_215 -> V_231 [ V_68 ] = NULL ;
if ( ! V_215 -> V_167 )
continue;
for ( V_188 = 0 ; V_188 < V_162 ; V_188 ++ ) {
if ( V_30 [ V_188 ] -> V_105 != V_107 )
continue;
if ( F_31 ( V_30 [ V_188 ] -> V_72 ) )
continue;
if ( V_30 [ V_188 ] -> V_182 != V_219 [ V_68 ] . V_182 )
continue;
V_215 -> V_231 [ V_68 ] = V_30 [ V_188 ] ;
if ( V_68 < V_227 )
V_228 = F_95 ( V_22 -> V_232 , V_228 +
V_215 -> V_231 [ V_68 ] -> V_185 ) ;
break;
}
if ( ! V_215 -> V_231 [ V_68 ] ) {
V_215 -> V_88 = 0 ;
V_215 -> V_178 = 0 ;
V_215 -> V_185 = 8 ;
}
}
if ( V_224 )
V_215 -> V_185 = V_228 ;
else
V_215 -> V_185 = V_22 -> V_232 ;
}
static void F_96 ( struct V_1 * V_22 ,
struct V_75 * V_30 [] , int V_162 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_162 ; V_68 ++ ) {
if ( V_30 [ V_68 ] -> V_105 != V_107 )
continue;
if ( ! F_31 ( V_30 [ V_68 ] -> V_72 ) )
continue;
if ( V_30 [ V_68 ] -> V_88 )
continue;
F_93 ( V_22 , V_30 , V_162 , V_30 [ V_68 ] ) ;
}
}
static void F_97 ( struct V_1 * V_22 , int V_168 ,
struct V_75 * V_174 [] , int V_233 )
{
int V_68 , V_179 , V_234 , V_235 = 0 ;
struct V_75 * V_236 ;
unsigned long V_77 ;
struct V_75 * * V_169 , * * V_186 ;
int V_170 , V_187 ;
struct V_6 * V_7 = NULL ;
V_169 = F_98 ( sizeof( * V_169 ) * V_161 , V_198 ) ;
V_186 = F_98 ( sizeof( * V_186 ) * V_161 , V_198 ) ;
if ( ! V_169 || ! V_186 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_58
L_59 ) ;
goto V_237;
}
F_34 ( & V_22 -> V_98 , V_77 ) ;
V_68 = 0 ;
V_187 = 0 ;
V_170 = 0 ;
while ( V_68 < V_22 -> V_162 ) {
V_236 = V_22 -> V_30 [ V_68 ] ;
V_234 = F_81 ( V_236 , V_174 , V_233 , & V_179 ) ;
if ( V_234 == F_82 ) {
V_235 ++ ;
F_76 ( V_22 , V_168 , V_68 ,
V_186 , & V_187 ) ;
continue;
} else if ( V_234 == F_83 ) {
V_235 ++ ;
F_75 ( V_22 , V_168 , V_68 , V_174 [ V_179 ] ,
V_169 , & V_170 , V_186 , & V_187 ) ;
V_174 [ V_179 ] = NULL ;
} else if ( V_234 == F_85 ) {
F_72 ( V_22 , V_168 , V_68 , V_174 [ V_179 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_233 ; V_68 ++ ) {
if ( ! V_174 [ V_68 ] )
continue;
if ( V_174 [ V_68 ] -> V_195 ) {
F_91 ( V_22 , V_174 [ V_68 ] ) ;
F_68 ( V_176 , V_22 , V_174 [ V_68 ] , L_60 ) ;
continue;
}
V_234 = F_81 ( V_174 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_162 , & V_179 ) ;
if ( V_234 == F_82 ) {
V_235 ++ ;
if ( F_70 ( V_22 , V_168 , V_174 [ V_68 ] ,
V_169 , & V_170 ) != 0 )
break;
V_174 [ V_68 ] = NULL ;
} else if ( V_234 == F_83 ) {
V_235 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_61 ) ;
}
}
F_96 ( V_22 , V_22 -> V_30 , V_22 -> V_162 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_88 = V_22 -> V_30 [ V_68 ] -> V_178 ;
F_35 ( & V_22 -> V_98 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_233 ; V_68 ++ ) {
if ( ! V_174 [ V_68 ] )
continue;
if ( V_174 [ V_68 ] -> V_195 )
F_87 ( V_22 , V_174 [ V_68 ] -> V_72 ) ;
}
if ( V_168 == - 1 || ! V_235 )
goto V_237;
V_7 = V_22 -> V_59 ;
for ( V_68 = 0 ; V_68 < V_187 ; V_68 ++ ) {
if ( V_186 [ V_68 ] -> V_108 & V_177 ) {
struct V_2 * V_3 =
F_99 ( V_7 , V_186 [ V_68 ] -> V_102 ,
V_186 [ V_68 ] -> V_103 , V_186 [ V_68 ] -> V_104 ) ;
if ( V_3 != NULL ) {
F_100 ( V_3 ) ;
F_101 ( V_3 ) ;
} else {
F_68 ( V_238 , V_22 , V_186 [ V_68 ] ,
L_62 ) ;
}
}
F_78 ( V_186 [ V_68 ] ) ;
V_186 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_170 ; V_68 ++ ) {
if ( ! ( V_169 [ V_68 ] -> V_108 & V_177 ) )
continue;
if ( F_102 ( V_7 , V_169 [ V_68 ] -> V_102 ,
V_169 [ V_68 ] -> V_103 , V_169 [ V_68 ] -> V_104 ) == 0 )
continue;
F_68 ( V_238 , V_22 , V_169 [ V_68 ] ,
L_63 ) ;
F_77 ( V_22 , V_169 [ V_68 ] ) ;
V_169 [ V_68 ] = NULL ;
}
V_237:
F_78 ( V_169 ) ;
F_78 ( V_186 ) ;
}
static struct V_75 * F_103 ( struct V_1 * V_22 ,
int V_102 , int V_103 , int V_104 )
{
int V_68 ;
struct V_75 * V_174 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_174 = V_22 -> V_30 [ V_68 ] ;
if ( V_174 -> V_102 == V_102 && V_174 -> V_103 == V_103 && V_174 -> V_104 == V_104 )
return V_174 ;
}
return NULL ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_75 * V_174 ;
unsigned long V_77 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_98 , V_77 ) ;
V_174 = F_103 ( V_22 , F_105 ( V_3 ) ,
F_106 ( V_3 ) , V_3 -> V_104 ) ;
if ( F_46 ( V_174 ) ) {
F_107 ( & V_174 -> V_239 , 0 ) ;
V_3 -> V_79 = ( V_174 -> V_108 & V_177 ) ? V_174 : NULL ;
} else
V_3 -> V_79 = NULL ;
F_35 ( & V_22 -> V_98 , V_77 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 )
{
struct V_75 * V_174 ;
int V_185 ;
V_174 = V_3 -> V_79 ;
V_3 -> V_240 = ! V_174 || ! ( V_174 -> V_108 & V_241 ) ;
if ( V_174 )
V_185 = V_174 -> V_185 != 0 ?
V_174 -> V_185 : V_3 -> V_5 -> V_242 ;
else
V_185 = V_3 -> V_5 -> V_242 ;
F_109 ( V_3 , V_185 ) ;
return 0 ;
}
static void F_110 ( struct V_2 * V_3 )
{
}
static void F_111 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_243 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
F_78 ( V_22 -> V_243 [ V_68 ] ) ;
V_22 -> V_243 [ V_68 ] = NULL ;
}
F_78 ( V_22 -> V_243 ) ;
V_22 -> V_243 = NULL ;
}
static int F_112 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_244 <= 0 )
return 0 ;
V_22 -> V_243 =
F_98 ( sizeof( * V_22 -> V_243 ) * V_22 -> V_232 ,
V_198 ) ;
if ( ! V_22 -> V_243 )
return - V_245 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
V_22 -> V_243 [ V_68 ] =
F_89 ( sizeof( * V_22 -> V_243 [ V_68 ] ) *
V_22 -> V_246 , V_198 ) ;
if ( ! V_22 -> V_243 [ V_68 ] )
goto V_247;
}
return 0 ;
V_247:
F_111 ( V_22 ) ;
return - V_245 ;
}
static void F_113 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_248 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
F_78 ( V_22 -> V_248 [ V_68 ] ) ;
V_22 -> V_248 [ V_68 ] = NULL ;
}
F_78 ( V_22 -> V_248 ) ;
V_22 -> V_248 = NULL ;
}
static int F_114 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_244 <= 0 )
return 0 ;
V_22 -> V_248 = F_98 ( sizeof( * V_22 -> V_248 ) * V_22 -> V_232 ,
V_198 ) ;
if ( ! V_22 -> V_248 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_64 ) ;
return - V_245 ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
V_22 -> V_248 [ V_68 ] = F_89 ( sizeof( * V_22 -> V_248 [ V_68 ] ) *
V_22 -> V_244 , V_198 ) ;
if ( ! V_22 -> V_248 [ V_68 ] ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_65 ) ;
goto V_247;
}
}
return 0 ;
V_247:
F_113 ( V_22 ) ;
return - V_245 ;
}
static int F_115 ( struct V_1 * V_22 ,
struct V_139 * V_131 , struct V_8 * V_9 )
{
struct V_249 * V_250 ;
T_5 V_251 ;
T_4 V_252 ;
V_250 = V_22 -> V_243 [ V_9 -> V_133 ] ;
V_252 = F_116 ( V_131 -> V_253 ) ;
V_251 = F_117 ( V_22 -> V_29 , V_250 , V_252 ,
V_254 ) ;
if ( F_118 ( & V_22 -> V_29 -> V_30 , V_251 ) ) {
V_131 -> V_255 -> V_256 = 0 ;
return - 1 ;
}
V_131 -> V_255 -> V_256 = F_119 ( V_251 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_22 ,
struct V_139 * V_131 )
{
struct V_249 * V_257 ;
T_5 V_251 ;
T_4 V_252 ;
V_257 = V_131 -> V_255 ;
V_251 = F_121 ( V_257 -> V_256 ) ;
V_252 = F_116 ( V_131 -> V_253 ) ;
F_122 ( V_22 -> V_29 , V_251 , V_252 , V_254 ) ;
}
static int F_123 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_258 * V_257 , * V_250 ;
T_5 V_251 ;
T_4 V_259 ;
V_257 = & V_9 -> V_260 [ V_22 -> V_261 - 1 ] ;
V_250 = V_22 -> V_248 [ V_9 -> V_133 ] ;
V_257 -> V_262 = F_124 ( V_263 ) ;
V_259 = sizeof( * V_257 ) *
( F_94 ( V_9 -> V_124 . V_264 ) - V_22 -> V_261 ) ;
V_257 -> V_265 = F_124 ( V_259 ) ;
V_251 = F_117 ( V_22 -> V_29 , V_250 , V_259 ,
V_254 ) ;
if ( F_118 ( & V_22 -> V_29 -> V_30 , V_251 ) ) {
V_257 -> V_266 = F_119 ( 0 ) ;
return - 1 ;
}
V_257 -> V_266 = F_119 ( V_251 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_258 * V_257 ;
if ( F_94 ( V_9 -> V_124 . V_264 ) <= V_22 -> V_261 )
return;
V_257 = & V_9 -> V_260 [ V_22 -> V_261 - 1 ] ;
F_122 ( V_22 -> V_29 , F_121 ( V_257 -> V_266 ) ,
F_116 ( V_257 -> V_265 ) , V_254 ) ;
}
static int F_126 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_267 * V_268 ,
struct V_139 * V_269 )
{
int V_253 ;
int V_270 = 0 ;
T_4 V_271 = 0 ;
switch ( V_269 -> V_272 . V_273 ) {
case V_274 :
switch ( V_269 -> V_272 . V_49 ) {
case V_275 :
break;
case V_276 :
V_268 -> V_277 |= V_278 ;
if ( V_269 -> V_272 . V_279 !=
V_280 ) {
memset ( V_268 -> V_281 , 0 ,
V_282 ) ;
break;
}
V_253 = V_269 -> V_272 . V_15 ;
if ( V_253 > V_282 )
V_253 = V_282 ;
if ( V_253 > sizeof( V_269 -> V_272 . V_283 ) )
V_253 =
sizeof( V_269 -> V_272 . V_283 ) ;
memcpy ( V_268 -> V_281 ,
V_269 -> V_272 . V_283 , V_253 ) ;
V_270 = 1 ;
break;
case V_284 :
V_270 = 1 ;
break;
case V_285 :
V_270 = 1 ;
break;
case V_286 :
V_270 = 1 ;
break;
case V_287 :
V_270 = 1 ;
break;
default:
V_270 = 1 ;
break;
}
break;
case V_288 :
switch ( V_269 -> V_272 . V_49 ) {
case V_289 :
case V_290 :
case V_291 :
V_270 = 1 ;
break;
case V_292 :
V_268 -> V_277 = ( V_293 << 16 ) ;
V_268 -> V_277 |= ( V_294 << 8 ) ;
V_271 = F_127 (
& V_269 -> V_272 . V_295 [ 0 ] ) ;
F_128 ( V_268 , V_271 ) ;
break;
case V_296 :
case V_297 :
case V_298 :
V_270 = 1 ;
break;
default:
V_270 = 1 ;
}
break;
case V_299 :
break;
case V_300 :
break;
case V_301 :
V_270 = 1 ;
break;
case V_302 :
break;
default:
V_270 = 1 ;
break;
}
return V_270 ;
}
static void F_129 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_303 = false ;
V_9 -> V_10 = V_11 ;
F_130 () ;
if ( V_9 -> V_12 ) {
V_303 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_77 ;
struct V_75 * V_30 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_56 ( & V_30 -> V_304 ) )
V_303 = true ;
V_9 -> V_13 = NULL ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
if ( V_303 )
F_131 ( & V_22 -> V_305 ) ;
}
static void F_132 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_129 ( V_22 , V_9 ) ;
F_133 ( V_22 , V_9 ) ;
}
static void F_134 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_267 * V_268 )
{
F_132 ( V_22 , V_9 ) ;
V_268 -> V_306 ( V_268 ) ;
}
static void F_135 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_136 ( & V_9 -> V_307 , V_308 ) ;
F_137 ( F_47 () , V_22 -> V_309 , & V_9 -> V_307 ) ;
}
static void F_138 ( struct V_267 * V_268 )
{
V_268 -> V_277 = V_310 << 16 ;
}
static void F_139 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_267 * V_268 )
{
F_138 ( V_268 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_66 ,
V_9 -> V_144 . V_145 , V_9 -> V_24 -> V_38 ) ;
F_132 ( V_22 , V_9 ) ;
}
static void F_140 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_267 * V_268 ,
struct V_75 * V_30 )
{
struct V_139 * V_269 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_46 ( V_269 -> V_272 . V_273 == 0 &&
V_269 -> V_272 . V_49 == 0 ) )
return F_134 ( V_22 , V_9 , V_268 ) ;
if ( F_31 ( V_30 -> V_72 ) &&
V_269 -> V_272 . V_273 ==
V_288 ) {
if ( V_269 -> V_272 . V_49 ==
V_298 )
V_30 -> V_88 = 0 ;
return F_135 ( V_22 , V_9 ) ;
}
if ( F_126 ( V_22 , V_9 , V_268 , V_269 ) )
return F_135 ( V_22 , V_9 ) ;
return F_134 ( V_22 , V_9 , V_268 ) ;
}
static int F_141 ( struct V_1 * V_22 ,
struct V_8 * V_131 )
{
T_1 V_311 = V_131 -> V_24 -> V_38 ;
switch ( V_311 ) {
case V_312 :
case V_313 :
return 0 ;
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_67 ,
V_311 ) ;
break;
}
return - V_311 ;
}
static void F_142 ( struct V_8 * V_131 )
{
struct V_267 * V_268 ;
struct V_1 * V_22 ;
struct V_319 * V_320 ;
struct V_75 * V_30 ;
struct V_139 * V_269 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_321 ;
V_320 = V_131 -> V_24 ;
V_268 = V_131 -> V_10 ;
V_22 = V_131 -> V_22 ;
V_30 = V_268 -> V_42 -> V_79 ;
V_269 = & V_22 -> V_137 [ V_131 -> V_133 ] ;
F_143 ( V_268 ) ;
if ( ( V_131 -> V_150 == V_322 ) &&
( F_94 ( V_131 -> V_124 . V_264 ) > V_22 -> V_261 ) )
F_125 ( V_22 , V_131 ) ;
if ( ( V_131 -> V_150 == V_154 ) &&
( V_269 -> V_255 [ 0 ] . V_323 == V_324 ) )
F_120 ( V_22 , V_269 ) ;
V_268 -> V_277 = ( V_293 << 16 ) ;
V_268 -> V_277 |= ( V_294 << 8 ) ;
if ( V_131 -> V_150 == V_154 || V_131 -> V_150 == V_151 )
F_44 ( & V_131 -> V_231 -> V_239 ) ;
if ( F_43 ( V_320 -> V_36 == V_325 ) ) {
V_268 -> V_277 = V_326 << 16 ;
return F_134 ( V_22 , V_131 , V_268 ) ;
}
if ( ( F_43 ( F_5 ( V_131 ) ) ) ) {
if ( V_131 -> V_13 )
return F_132 ( V_22 , V_131 ) ;
if ( V_131 -> V_12 )
return F_139 ( V_22 , V_131 , V_268 ) ;
}
if ( V_131 -> V_150 == V_154 )
return F_140 ( V_22 , V_131 , V_268 , V_30 ) ;
F_128 ( V_268 , V_320 -> V_327 ) ;
if ( V_320 -> V_36 == 0 )
return F_134 ( V_22 , V_131 , V_268 ) ;
if ( V_131 -> V_150 == V_151 ) {
struct V_130 * V_9 = & V_22 -> V_132 [ V_131 -> V_133 ] ;
V_131 -> V_124 . V_125 = F_144 ( V_268 ) ;
V_131 -> V_124 . V_264 = F_145 ( V_131 -> V_124 . V_125 ) ;
V_131 -> V_144 . V_328 = F_94 ( V_9 -> V_329 ) &
V_330 ;
V_131 -> V_124 . V_331 = V_9 -> V_331 ;
memcpy ( V_131 -> V_124 . V_332 . V_333 , V_9 -> V_334 , 8 ) ;
memcpy ( V_131 -> V_144 . V_145 , V_9 -> V_145 , V_131 -> V_144 . V_328 ) ;
if ( F_31 ( V_30 -> V_72 ) ) {
if ( V_320 -> V_36 == V_335 )
V_30 -> V_88 = 0 ;
return F_135 ( V_22 , V_131 ) ;
}
}
switch ( V_320 -> V_36 ) {
case V_37 :
V_268 -> V_277 |= V_320 -> V_38 ;
if ( V_282 < sizeof( V_320 -> V_26 ) )
V_321 = V_282 ;
else
V_321 = sizeof( V_320 -> V_26 ) ;
if ( V_320 -> V_25 < V_321 )
V_321 = V_320 -> V_25 ;
memcpy ( V_268 -> V_281 , V_320 -> V_26 , V_321 ) ;
if ( V_320 -> V_38 )
F_6 ( V_320 -> V_26 , V_321 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_320 -> V_38 == V_278 ) {
if ( V_16 == V_336 ) {
V_268 -> V_277 |= V_337 << 16 ;
break;
}
break;
}
if ( V_320 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_68
L_69
L_70 ,
V_131 , V_320 -> V_38 ,
V_16 , V_17 , V_18 ,
V_268 -> V_277 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_71
L_72 , V_131 ) ,
V_268 -> V_277 = V_326 << 16 ;
}
break;
case V_338 :
break;
case V_339 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_73 , V_131 -> V_144 . V_145 ) ;
break;
case V_340 : {
V_268 -> V_277 = V_326 << 16 ;
}
break;
case V_341 :
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_74 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_343 :
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_75 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_344 :
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_76 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_345 :
return F_139 ( V_22 , V_131 , V_268 ) ;
case V_346 :
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_77 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_347 :
V_268 -> V_277 = V_337 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_78 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_348 :
V_268 -> V_277 = V_349 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_79 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_350 :
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_80 ) ;
break;
case V_351 :
if ( F_141 ( V_22 , V_131 ) )
V_268 -> V_277 = V_342 << 16 ;
break;
case V_335 :
V_268 -> V_277 = V_337 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_81 , V_131 ) ;
break;
default:
V_268 -> V_277 = V_342 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_82 ,
V_131 , V_320 -> V_36 ) ;
}
return F_134 ( V_22 , V_131 , V_268 ) ;
}
static void F_146 ( struct V_352 * V_29 ,
struct V_8 * V_9 , int V_353 , int V_354 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_353 ; V_68 ++ )
F_122 ( V_29 , ( V_355 ) F_121 ( V_9 -> V_260 [ V_68 ] . V_266 ) ,
F_116 ( V_9 -> V_260 [ V_68 ] . V_265 ) ,
V_354 ) ;
}
static int F_147 ( struct V_352 * V_29 ,
struct V_8 * V_131 ,
unsigned char * V_45 ,
T_3 V_356 ,
int V_354 )
{
T_5 V_357 ;
if ( V_356 == 0 || V_354 == V_358 ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_264 = F_145 ( 0 ) ;
return 0 ;
}
V_357 = F_117 ( V_29 , V_45 , V_356 , V_354 ) ;
if ( F_118 ( & V_29 -> V_30 , V_357 ) ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_264 = F_145 ( 0 ) ;
return - 1 ;
}
V_131 -> V_260 [ 0 ] . V_266 = F_119 ( V_357 ) ;
V_131 -> V_260 [ 0 ] . V_265 = F_124 ( V_356 ) ;
V_131 -> V_260 [ 0 ] . V_262 = F_124 ( V_359 ) ;
V_131 -> V_124 . V_125 = 1 ;
V_131 -> V_124 . V_264 = F_145 ( 1 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_113 , unsigned long V_360 )
{
F_149 ( V_361 ) ;
V_9 -> V_362 = & V_361 ;
F_57 ( V_22 , V_9 , V_113 ) ;
if ( V_360 == V_363 ) {
F_150 ( & V_361 ) ;
return V_364 ;
}
if ( ! F_151 ( & V_361 ,
F_152 ( V_360 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_83 ) ;
return - V_365 ;
}
return V_364 ;
}
static int F_153 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_113 , unsigned long V_360 )
{
if ( F_43 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_325 ;
return V_364 ;
}
return F_148 ( V_22 , V_9 , V_113 , V_360 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_366 ;
T_4 V_21 , * F_13 ;
V_366 = F_154 () ;
F_13 = F_155 ( V_22 -> F_13 , V_366 ) ;
V_21 = * F_13 ;
F_156 () ;
return V_21 ;
}
static int F_157 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_354 , unsigned long V_360 )
{
int V_367 = 10 , V_368 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_153 ( V_22 , V_9 , V_127 ,
V_360 ) ;
if ( V_21 )
break;
V_368 ++ ;
if ( V_368 > 3 ) {
F_158 ( V_367 ) ;
if ( V_367 < 1000 )
V_367 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_368 <= V_369 );
F_146 ( V_22 -> V_29 , V_9 , 1 , V_354 ) ;
if ( V_368 > V_369 )
V_21 = - V_370 ;
return V_21 ;
}
static void F_159 ( struct V_1 * V_22 , char * V_371 ,
struct V_8 * V_9 )
{
const T_1 * V_141 = V_9 -> V_144 . V_145 ;
const T_1 * V_104 = V_9 -> V_124 . V_332 . V_333 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_84
L_85 ,
V_371 , V_104 [ 0 ] , V_104 [ 1 ] , V_104 [ 2 ] , V_104 [ 3 ] ,
V_104 [ 4 ] , V_104 [ 5 ] , V_104 [ 6 ] , V_104 [ 7 ] ,
V_141 [ 0 ] , V_141 [ 1 ] , V_141 [ 2 ] , V_141 [ 3 ] ,
V_141 [ 4 ] , V_141 [ 5 ] , V_141 [ 6 ] , V_141 [ 7 ] ,
V_141 [ 8 ] , V_141 [ 9 ] , V_141 [ 10 ] , V_141 [ 11 ] ,
V_141 [ 12 ] , V_141 [ 13 ] , V_141 [ 14 ] , V_141 [ 15 ] ) ;
}
static void F_160 ( struct V_1 * V_22 ,
struct V_8 * V_131 )
{
const struct V_319 * V_320 = V_131 -> V_24 ;
struct V_42 * V_372 = & V_131 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_320 -> V_36 ) {
case V_37 :
if ( V_320 -> V_25 > sizeof( V_320 -> V_26 ) )
V_23 = sizeof( V_320 -> V_26 ) ;
else
V_23 = V_320 -> V_25 ;
F_6 ( V_320 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_159 ( V_22 , L_86 , V_131 ) ;
if ( V_320 -> V_38 == V_278 )
F_9 ( V_372 , L_87 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_372 , L_88 , V_320 -> V_38 ) ;
if ( V_320 -> V_38 == 0 )
F_9 ( V_372 , L_89
L_90
L_91
L_92 ) ;
break;
case V_338 :
break;
case V_339 :
F_159 ( V_22 , L_93 , V_131 ) ;
break;
case V_340 : {
F_159 ( V_22 , L_94 , V_131 ) ;
F_9 ( V_372 , L_95 ) ;
}
break;
case V_341 :
F_159 ( V_22 , L_96 , V_131 ) ;
break;
case V_343 :
F_159 ( V_22 , L_97 , V_131 ) ;
break;
case V_344 :
F_159 ( V_22 , L_98 , V_131 ) ;
break;
case V_345 :
F_159 ( V_22 , L_99 , V_131 ) ;
break;
case V_346 :
F_159 ( V_22 , L_100 , V_131 ) ;
break;
case V_347 :
F_159 ( V_22 , L_101 , V_131 ) ;
break;
case V_348 :
F_159 ( V_22 , L_102 , V_131 ) ;
break;
case V_350 :
F_159 ( V_22 , L_103 , V_131 ) ;
break;
case V_325 :
F_159 ( V_22 , L_104 , V_131 ) ;
break;
default:
F_159 ( V_22 , L_105 , V_131 ) ;
F_9 ( V_372 , L_106 ,
V_320 -> V_36 ) ;
}
}
static int F_161 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_373 , unsigned char * V_45 ,
unsigned char V_374 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
struct V_319 * V_320 ;
V_9 = F_162 ( V_22 ) ;
if ( F_163 ( V_9 , V_375 , V_22 , V_45 , V_374 ,
V_373 , V_72 , V_376 ) ) {
V_21 = - 1 ;
goto V_377;
}
V_21 = F_157 ( V_22 , V_9 ,
V_378 , V_363 ) ;
if ( V_21 )
goto V_377;
V_320 = V_9 -> V_24 ;
if ( V_320 -> V_36 != 0 && V_320 -> V_36 != V_338 ) {
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_377:
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_165 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_379 , int V_113 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
struct V_319 * V_320 ;
V_9 = F_162 ( V_22 ) ;
( void ) F_163 ( V_9 , V_380 , V_22 , NULL , 0 , 0 ,
V_72 , V_381 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_379 ;
V_21 = F_153 ( V_22 , V_9 , V_113 , V_363 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_107 ) ;
goto V_377;
}
V_320 = V_9 -> V_24 ;
if ( V_320 -> V_36 != 0 ) {
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_377:
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_166 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_75 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_382 = false ;
struct V_139 * V_269 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_383 = (struct V_136 * ) V_269 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_150 ) {
case V_322 :
case V_384 :
V_382 = ! memcmp ( V_72 , & V_9 -> V_124 . V_332 . V_333 ,
sizeof( V_9 -> V_124 . V_332 . V_333 ) ) ;
break;
case V_151 :
case V_154 :
if ( V_9 -> V_231 == V_30 ) {
V_382 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_230 && ! V_382 ; V_68 ++ ) {
V_382 = V_30 -> V_231 [ V_68 ] == V_9 -> V_231 ;
}
}
break;
case V_156 :
for ( V_68 = 0 ; V_68 < V_30 -> V_230 && ! V_382 ; V_68 ++ ) {
V_382 = V_30 -> V_231 [ V_68 ] -> V_182 ==
F_116 ( V_383 -> V_385 ) ;
}
break;
case 0 :
V_382 = false ;
break;
default:
F_71 ( & V_22 -> V_29 -> V_30 , L_108 ,
V_9 -> V_150 ) ;
F_167 () ;
}
return V_382 ;
}
static int F_168 ( struct V_1 * V_22 , struct V_75 * V_30 ,
unsigned char * V_72 , T_1 V_379 , int V_113 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_169 ( & V_22 -> V_386 ) == - V_387 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_109 ) ;
return - V_387 ;
}
F_73 ( F_21 ( & V_30 -> V_304 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_388 + V_68 ;
int V_389 = F_170 ( & V_9 -> V_389 ) ;
if ( V_389 > 1 && F_166 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_77 ;
V_9 -> V_13 = V_30 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! F_4 ( V_9 ) )
F_54 ( & V_30 -> V_304 ) ;
else
V_9 -> V_13 = NULL ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
F_164 ( V_22 , V_9 ) ;
}
V_21 = F_165 ( V_22 , V_72 , V_379 , V_113 ) ;
if ( ! V_21 )
F_171 ( V_22 -> V_305 ,
F_21 ( & V_30 -> V_304 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_43 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_110 ) ;
V_21 = - V_80 ;
}
if ( F_43 ( V_21 ) )
F_107 ( & V_30 -> V_304 , 0 ) ;
F_172 ( & V_22 -> V_386 ) ;
return V_21 ;
}
static void F_173 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_82 )
{
int V_21 ;
unsigned char * V_45 ;
* V_82 = V_83 ;
V_45 = F_98 ( 64 , V_198 ) ;
if ( ! V_45 )
return;
V_21 = F_161 ( V_22 , V_72 , V_390 | 0xC1 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_82 = V_45 [ 8 ] ;
if ( * V_82 > V_83 )
* V_82 = V_83 ;
F_78 ( V_45 ) ;
return;
}
static void F_174 ( struct V_1 * V_22 , int V_21 ,
struct V_216 * V_391 )
{
struct V_218 * V_219 = & V_391 -> V_220 [ 0 ] ;
int V_217 , V_392 , V_393 ;
T_6 V_394 , V_225 , V_395 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_92 ( & V_22 -> V_29 -> V_30 , L_111 ,
F_116 ( V_391 -> V_396 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_112 ,
F_116 ( V_391 -> V_397 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_113 ,
F_121 ( V_391 -> V_398 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_114 ,
V_391 -> V_399 ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_115 ,
V_391 -> V_400 ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_116 ,
F_94 ( V_391 -> V_401 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_117 ,
F_121 ( V_391 -> V_402 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_118 ,
F_121 ( V_391 -> V_403 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_119 ,
F_94 ( V_391 -> V_222 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_120 ,
F_94 ( V_391 -> V_223 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_121 ,
F_94 ( V_391 -> V_225 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_122 ,
F_94 ( V_391 -> V_226 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_123 ,
F_94 ( V_391 -> V_77 ) ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_94 ( V_391 -> V_77 ) &
V_404 ? L_125 : L_126 ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_94 ( V_391 -> V_405 ) ) ;
V_394 = F_94 ( V_391 -> V_226 ) ;
for ( V_217 = 0 ; V_217 < V_394 ; V_217 ++ ) {
F_92 ( & V_22 -> V_29 -> V_30 , L_128 , V_217 ) ;
V_225 = F_94 ( V_391 -> V_225 ) ;
for ( V_392 = 0 ; V_392 < V_225 ; V_392 ++ ) {
F_92 ( & V_22 -> V_29 -> V_30 , L_129 , V_392 ) ;
V_395 =
F_94 ( V_391 -> V_222 ) ;
for ( V_393 = 0 ; V_393 < V_395 ; V_393 ++ , V_219 ++ )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_130 ,
V_393 , V_219 -> V_182 ,
V_219 -> V_406 [ 0 ] , V_219 -> V_406 [ 1 ] ) ;
V_395 =
F_94 ( V_391 -> V_223 ) ;
for ( V_393 = 0 ; V_393 < V_395 ; V_393 ++ , V_219 ++ )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_131 ,
V_393 , V_219 -> V_182 ,
V_219 -> V_406 [ 0 ] , V_219 -> V_406 [ 1 ] ) ;
}
}
}
static int F_175 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_75 * V_407 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_319 * V_320 ;
V_9 = F_162 ( V_22 ) ;
if ( F_163 ( V_9 , V_408 , V_22 , & V_407 -> V_181 ,
sizeof( V_407 -> V_181 ) , 0 ,
V_72 , V_376 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_132 ) ;
F_164 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_157 ( V_22 , V_9 ,
V_378 , V_363 ) ;
if ( V_21 )
goto V_377;
V_320 = V_9 -> V_24 ;
if ( V_320 -> V_36 != 0 && V_320 -> V_36 != V_338 ) {
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_377;
}
F_164 ( V_22 , V_9 ) ;
if ( F_116 ( V_407 -> V_181 . V_396 ) >
sizeof( V_407 -> V_181 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_133 ) ;
V_21 = - 1 ;
}
F_174 ( V_22 , V_21 , & V_407 -> V_181 ) ;
return V_21 ;
V_377:
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_176 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_409 ,
struct V_410 * V_45 , T_3 V_374 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
struct V_319 * V_320 ;
V_9 = F_162 ( V_22 ) ;
V_21 = F_163 ( V_9 , V_411 , V_22 , V_45 , V_374 ,
0 , V_158 , V_376 ) ;
if ( V_21 )
goto V_377;
V_9 -> V_144 . V_145 [ 2 ] = V_409 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_409 >> 8 ) & 0xff ;
F_157 ( V_22 , V_9 , V_378 ,
V_363 ) ;
V_320 = V_9 -> V_24 ;
if ( V_320 -> V_36 != 0 && V_320 -> V_36 != V_338 ) {
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_377:
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_177 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_373 )
{
int V_21 ;
int V_68 ;
int V_412 ;
unsigned char * V_45 , V_374 ;
V_45 = F_98 ( 256 , V_198 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_161 ( V_22 , V_72 ,
V_390 | V_413 ,
V_45 , V_414 ) ;
if ( V_21 != 0 )
goto V_415;
V_412 = V_45 [ 3 ] ;
if ( ( V_412 + V_414 ) <= 255 )
V_374 = V_412 + V_414 ;
else
V_374 = 255 ;
V_21 = F_161 ( V_22 , V_72 ,
V_390 | V_413 ,
V_45 , V_374 ) ;
if ( V_21 != 0 )
goto V_415;
V_412 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_412 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_373 )
goto V_416;
V_415:
F_78 ( V_45 ) ;
return 0 ;
V_416:
F_78 ( V_45 ) ;
return 1 ;
}
static void F_178 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_75 * V_407 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_417 ;
V_407 -> V_167 = 0 ;
V_407 -> V_88 = 0 ;
V_407 -> V_178 = 0 ;
V_45 = F_98 ( 64 , V_198 ) ;
if ( ! V_45 )
return;
if ( ! F_177 ( V_22 , V_72 , V_418 ) )
goto V_377;
V_21 = F_161 ( V_22 , V_72 ,
V_390 | V_418 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_377;
#define F_179 4
#define F_180 0x01
#define F_181 0x02
V_417 = V_45 [ F_179 ] ;
V_407 -> V_167 =
! ! ( V_417 & F_180 ) ;
if ( V_407 -> V_167 ) {
V_407 -> V_88 =
! ! ( V_417 & F_181 ) ;
if ( F_175 ( V_22 , V_72 , V_407 ) )
V_407 -> V_88 = 0 ;
}
V_407 -> V_178 = V_407 -> V_88 ;
V_377:
F_78 ( V_45 ) ;
return;
}
static int F_182 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_87 , int V_356 )
{
int V_21 ;
unsigned char * V_45 ;
if ( V_356 > 16 )
V_356 = 16 ;
V_45 = F_98 ( 64 , V_198 ) ;
if ( ! V_45 )
return - V_245 ;
V_21 = F_161 ( V_22 , V_72 , V_390 | 0x83 , V_45 , 64 ) ;
if ( V_21 == 0 )
memcpy ( V_87 , & V_45 [ 8 ] , V_356 ) ;
F_78 ( V_45 ) ;
return V_21 != 0 ;
}
static int F_183 ( struct V_1 * V_22 , int V_419 ,
void * V_45 , int V_374 ,
int V_420 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_319 * V_320 ;
V_9 = F_162 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_163 ( V_9 , V_419 ? V_421 : V_422 , V_22 ,
V_45 , V_374 , 0 , V_72 , V_376 ) ) {
V_21 = - 1 ;
goto V_377;
}
if ( V_420 )
V_9 -> V_144 . V_145 [ 1 ] = V_420 ;
V_21 = F_157 ( V_22 , V_9 ,
V_378 , V_363 ) ;
if ( V_21 )
goto V_377;
V_320 = V_9 -> V_24 ;
if ( V_320 -> V_36 != 0 &&
V_320 -> V_36 != V_338 ) {
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_423 * V_424 = V_45 ;
if ( V_424 -> V_425 != V_420 ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_134 ,
V_420 ,
V_424 -> V_425 ) ;
V_21 = - 1 ;
}
}
V_377:
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_184 ( struct V_1 * V_22 ,
struct V_426 * V_45 , int V_374 )
{
return F_183 ( V_22 , 0 , V_45 , V_374 ,
V_427 ) ;
}
static inline int F_185 ( struct V_1 * V_22 ,
struct V_423 * V_45 , int V_374 )
{
return F_183 ( V_22 , 1 , V_45 , V_374 , 0 ) ;
}
static inline void F_186 ( struct V_75 * V_42 ,
int V_102 , int V_103 , int V_104 )
{
V_42 -> V_102 = V_102 ;
V_42 -> V_103 = V_103 ;
V_42 -> V_104 = V_104 ;
}
static int F_187 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_428 ;
unsigned char * V_45 ;
V_45 = F_98 ( 64 , V_198 ) ;
if ( ! V_45 )
return V_202 ;
if ( ! F_177 ( V_22 , V_72 , V_429 ) )
goto V_430;
V_21 = F_161 ( V_22 , V_72 , V_390 | V_429 ,
V_45 , V_414 ) ;
if ( V_21 != 0 )
goto V_430;
V_428 = V_45 [ 3 ] ;
V_21 = F_161 ( V_22 , V_72 , V_390 | V_429 ,
V_45 , V_428 + V_414 ) ;
if ( V_21 != 0 )
goto V_430;
V_49 = V_45 [ 4 ] ;
F_78 ( V_45 ) ;
return V_49 ;
V_430:
F_78 ( V_45 ) ;
return V_202 ;
}
static int F_188 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_431 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_432 = 0 ;
T_6 V_433 ;
T_1 V_434 ;
#define F_189 0x04
#define F_190 0x04
#define F_191 0x02
V_9 = F_162 ( V_22 ) ;
( void ) F_163 ( V_9 , V_435 , V_22 , NULL , 0 , 0 , V_72 , V_376 ) ;
V_21 = F_153 ( V_22 , V_9 , V_127 , V_363 ) ;
if ( V_21 ) {
F_164 ( V_22 , V_9 ) ;
return 0 ;
}
V_431 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_431 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_433 = V_9 -> V_24 -> V_36 ;
V_434 = V_9 -> V_24 -> V_38 ;
F_164 ( V_22 , V_9 ) ;
if ( V_433 != V_37 ||
V_434 != V_278 ||
V_16 != V_436 ||
V_17 != F_189 ) {
return 0 ;
}
V_432 = F_187 ( V_22 , V_72 ) ;
switch ( V_432 ) {
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
return V_432 ;
case V_202 :
if ( ( V_18 == F_190 ) ||
( V_18 == F_191 ) )
return V_432 ;
break;
default:
break;
}
return 0 ;
}
static int F_192 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_319 * V_320 ;
int V_21 = 0 ;
T_5 V_331 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_162 ( V_22 ) ;
( void ) F_163 ( V_9 , V_437 , V_22 , & V_331 , 0 , 0 , V_72 , V_381 ) ;
( void ) F_153 ( V_22 , V_9 , V_127 , V_363 ) ;
V_320 = V_9 -> V_24 ;
switch ( V_320 -> V_36 ) {
case V_340 :
V_21 = 0 ;
break;
case V_350 :
case V_346 :
V_21 = 1 ;
break;
case V_351 :
V_21 = F_141 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_193 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_75 * V_407 ,
unsigned char * V_438 )
{
#define F_194 43
#define F_195 "$DR-10"
#define F_196 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_197 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_439 ;
unsigned char * V_440 ;
V_439 = F_98 ( F_197 , V_198 ) ;
if ( ! V_439 )
goto V_441;
if ( F_161 ( V_22 , V_72 , 0 , V_439 ,
( unsigned char ) F_197 ) != 0 ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_135 ) ;
goto V_441;
}
V_407 -> V_105 = ( V_439 [ 0 ] & 0x1f ) ;
memcpy ( V_407 -> V_72 , V_72 , 8 ) ;
memcpy ( V_407 -> V_165 , & V_439 [ 8 ] ,
sizeof( V_407 -> V_165 ) ) ;
memcpy ( V_407 -> V_166 , & V_439 [ 16 ] ,
sizeof( V_407 -> V_166 ) ) ;
memset ( V_407 -> V_87 , 0 ,
sizeof( V_407 -> V_87 ) ) ;
F_182 ( V_22 , V_72 , V_407 -> V_87 ,
sizeof( V_407 -> V_87 ) ) ;
if ( V_407 -> V_105 == V_107 &&
F_31 ( V_72 ) ) {
int V_195 ;
F_173 ( V_22 , V_72 , & V_407 -> V_82 ) ;
if ( V_22 -> V_442 & V_443 )
F_178 ( V_22 , V_72 , V_407 ) ;
V_195 = F_188 ( V_22 , V_72 ) ;
if ( V_195 < 0 || V_195 > 0xff )
V_195 = V_202 ;
V_407 -> V_195 = V_195 & 0xff ;
} else {
V_407 -> V_82 = V_83 ;
V_407 -> V_167 = 0 ;
V_407 -> V_88 = 0 ;
V_407 -> V_178 = 0 ;
V_407 -> V_183 = 0 ;
V_407 -> V_195 = 0 ;
V_407 -> V_185 = V_22 -> V_232 ;
}
if ( V_438 ) {
V_440 = & V_439 [ F_194 ] ;
* V_438 = ( V_407 -> V_105 == V_444 &&
strncmp ( V_440 , F_195 ,
F_196 ) == 0 ) ;
}
F_78 ( V_439 ) ;
return 0 ;
V_441:
F_78 ( V_439 ) ;
return 1 ;
}
static void F_198 ( struct V_1 * V_22 ,
struct V_75 * V_30 , T_1 * V_72 )
{
unsigned long V_77 ;
int V_21 , V_179 ;
F_34 ( & V_22 -> V_98 , V_77 ) ;
V_21 = F_81 ( V_30 , V_22 -> V_30 , V_22 -> V_162 , & V_179 ) ;
if ( ( V_21 == F_84 || V_21 == F_85 ) &&
V_179 >= 0 && V_179 < V_22 -> V_162 ) {
V_30 -> V_445 = V_22 -> V_30 [ V_179 ] -> V_445 ;
F_35 ( & V_22 -> V_98 , V_77 ) ;
} else {
F_35 ( & V_22 -> V_98 , V_77 ) ;
V_30 -> V_445 =
F_192 ( V_22 , V_72 ) ;
if ( V_30 -> V_445 < 0 )
V_30 -> V_445 = 0 ;
}
}
static int F_41 ( struct V_1 * V_22 , struct V_75 * V_42 )
{
int V_68 ;
for ( V_68 = 0 ; V_446 [ V_68 ] ; V_68 ++ )
if ( strncmp ( V_42 -> V_166 , V_446 [ V_68 ] ,
strlen ( V_446 [ V_68 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_199 ( struct V_1 * V_22 ,
T_1 * V_447 , struct V_75 * V_42 )
{
T_4 V_85 = F_116 ( * ( ( V_448 * ) V_447 ) ) ;
if ( ! F_31 ( V_447 ) ) {
if ( F_61 ( V_447 ) )
F_186 ( V_42 , 3 , 0 , V_85 & 0x3fff ) ;
else
F_186 ( V_42 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_41 ( V_22 , V_42 ) ) {
F_186 ( V_42 ,
1 , ( V_85 >> 16 ) & 0x3fff , V_85 & 0x00ff ) ;
return;
}
F_186 ( V_42 , 0 , 0 , V_85 & 0x3fff ) ;
}
static int F_200 ( struct V_1 * V_22 ,
struct V_75 * V_449 ,
struct V_75 * V_407 , T_1 * V_447 ,
unsigned long V_450 [] , int * V_451 )
{
unsigned char V_72 [ 8 ] ;
if ( F_201 ( V_449 -> V_103 , V_450 ) )
return 0 ;
if ( ! F_31 ( V_447 ) )
return 0 ;
if ( ! F_41 ( V_22 , V_449 ) )
return 0 ;
if ( V_449 -> V_104 == 0 )
return 0 ;
memset ( V_72 , 0 , 8 ) ;
V_72 [ 3 ] = V_449 -> V_103 ;
if ( F_61 ( V_72 ) )
return 0 ;
if ( F_62 ( V_22 ) )
return 0 ;
if ( * V_451 >= V_452 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_136
L_137
L_138 ) ;
return 0 ;
}
if ( F_193 ( V_22 , V_72 , V_407 , NULL ) )
return 0 ;
( * V_451 ) ++ ;
F_186 ( V_407 ,
V_449 -> V_102 , V_449 -> V_103 , 0 ) ;
F_198 ( V_22 , V_407 , V_72 ) ;
F_202 ( V_449 -> V_103 , V_450 ) ;
return 1 ;
}
static int F_203 ( struct V_1 * V_22 ,
struct V_8 * V_453 , unsigned char * V_72 )
{
struct V_139 * V_269 =
& V_22 -> V_137 [ V_453 -> V_133 ] ;
unsigned long V_77 ;
int V_68 ;
F_34 ( & V_22 -> V_98 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_182 == F_116 ( V_269 -> V_454 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_35 ( & V_22 -> V_98 , V_77 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_98 , V_77 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_22 ,
struct V_426 * V_455 , T_4 * V_456 ,
struct V_423 * V_457 , T_4 * V_458 )
{
if ( F_184 ( V_22 , V_455 , sizeof( * V_455 ) ) ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_139 ) ;
return - 1 ;
}
* V_456 = F_205 ( * ( ( V_459 * ) V_455 -> V_460 ) ) / 24 ;
if ( * V_456 > V_461 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_140 ,
V_461 , * V_456 - V_461 ) ;
* V_456 = V_461 ;
}
if ( F_185 ( V_22 , V_457 , sizeof( * V_457 ) ) ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_141 ) ;
return - 1 ;
}
* V_458 = F_205 ( * ( ( V_459 * ) V_457 -> V_460 ) ) / 8 ;
if ( * V_458 > V_462 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_142
L_143 , V_462 ,
* V_458 - V_462 ) ;
* V_458 = V_462 ;
}
if ( * V_458 + * V_456 > V_461 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_144
L_143 , V_461 ,
* V_456 + * V_458 - V_461 ) ;
* V_458 = V_461 - * V_456 ;
}
return 0 ;
}
static T_1 * F_206 ( struct V_1 * V_22 , int V_463 ,
int V_68 , int V_456 , int V_458 ,
struct V_426 * V_464 ,
struct V_423 * V_465 )
{
int V_466 = V_456 + ( V_463 == 0 ) ;
int V_467 = V_456 + V_458 + ( V_463 == 0 ) ;
if ( V_68 == V_463 )
return V_158 ;
if ( V_68 < V_466 )
return & V_464 -> V_332 [ V_68 -
( V_463 == 0 ) ] . V_85 [ 0 ] ;
if ( V_68 < V_467 )
return & V_465 -> V_332 [ V_68 - V_456 -
( V_463 == 0 ) ] [ 0 ] ;
F_167 () ;
return NULL ;
}
static void F_207 ( struct V_1 * V_22 ,
struct V_75 * V_30 ,
T_1 * V_447 ,
struct V_410 * V_468 )
{
int V_21 ;
struct V_469 * V_470 =
(struct V_469 * ) V_447 ;
V_30 -> V_182 = V_470 -> V_182 ;
if ( F_208 ( V_447 ) && V_30 -> V_182 )
V_30 -> V_183 = 1 ;
memset ( V_468 , 0 , sizeof( * V_468 ) ) ;
V_21 = F_176 ( V_22 , V_447 ,
F_209 ( V_447 ) , V_468 ,
sizeof( * V_468 ) ) ;
if ( ! V_21 )
#define F_210 2
#define F_211 7
V_30 -> V_185 =
F_94 ( V_468 -> V_471 ) -
F_210 ;
else
V_30 -> V_185 = F_211 ;
F_107 ( & V_30 -> V_239 , 0 ) ;
F_107 ( & V_30 -> V_304 , 0 ) ;
}
static void F_212 ( struct V_75 * V_407 ,
T_1 * V_447 ,
struct V_410 * V_468 )
{
if ( F_208 ( V_447 )
&& V_407 -> V_182 )
V_407 -> V_183 = 1 ;
memcpy ( & V_407 -> V_99 ,
& V_468 -> V_472 ,
sizeof( V_407 -> V_99 ) ) ;
memcpy ( & V_407 -> V_100 ,
& V_468 -> V_473 ,
sizeof( V_407 -> V_100 ) ) ;
memcpy ( & V_407 -> V_90 ,
& V_468 -> V_474 ,
sizeof( V_407 -> V_90 ) ) ;
memcpy ( & V_407 -> V_94 ,
& V_468 -> V_475 ,
sizeof( V_407 -> V_94 ) ) ;
memcpy ( & V_407 -> V_91 ,
& V_468 -> V_476 ,
sizeof( V_407 -> V_91 ) ) ;
}
static void F_213 ( struct V_1 * V_22 , int V_168 )
{
struct V_426 * V_464 = NULL ;
struct V_423 * V_465 = NULL ;
struct V_410 * V_468 = NULL ;
T_4 V_456 = 0 ;
T_4 V_458 = 0 ;
T_4 V_477 = 0 ;
struct V_75 * * V_478 , * V_407 , * V_449 ;
int V_479 = 0 ;
int V_68 , V_451 , V_480 ;
int V_463 ;
F_64 ( V_450 , V_452 ) ;
V_478 = F_98 ( sizeof( * V_478 ) * V_161 , V_198 ) ;
V_464 = F_98 ( sizeof( * V_464 ) , V_198 ) ;
V_465 = F_98 ( sizeof( * V_465 ) , V_198 ) ;
V_449 = F_98 ( sizeof( * V_449 ) , V_198 ) ;
V_468 = F_98 ( sizeof( * V_468 ) , V_198 ) ;
if ( ! V_478 || ! V_464 || ! V_465 ||
! V_449 || ! V_468 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_145 ) ;
goto V_377;
}
memset ( V_450 , 0 , sizeof( V_450 ) ) ;
if ( F_204 ( V_22 , V_464 , & V_456 ,
V_465 , & V_458 ) )
goto V_377;
V_480 = V_456 + V_458 + V_452 + 1 ;
for ( V_68 = 0 ; V_68 < V_480 ; V_68 ++ ) {
if ( V_68 >= V_161 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_146
L_147 , V_161 ,
V_480 - V_161 ) ;
break;
}
V_478 [ V_68 ] = F_98 ( sizeof( * V_478 [ V_68 ] ) , V_198 ) ;
if ( ! V_478 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_148 ,
__FILE__ , __LINE__ ) ;
goto V_377;
}
V_477 ++ ;
}
if ( F_62 ( V_22 ) )
V_463 = 0 ;
else
V_463 = V_456 + V_458 ;
V_451 = 0 ;
for ( V_68 = 0 ; V_68 < V_456 + V_458 + 1 ; V_68 ++ ) {
T_1 * V_447 , V_481 = 0 ;
V_447 = F_206 ( V_22 , V_463 ,
V_68 , V_456 , V_458 , V_464 , V_465 ) ;
if ( F_214 ( V_447 ) )
if ( V_68 < V_456 + ( V_463 == 0 ) &&
F_215 ( V_447 ) )
continue;
if ( F_193 ( V_22 , V_447 , V_449 ,
& V_481 ) )
continue;
F_199 ( V_22 , V_447 , V_449 ) ;
F_198 ( V_22 , V_449 , V_447 ) ;
V_407 = V_478 [ V_479 ] ;
if ( F_200 ( V_22 , V_449 , V_407 ,
V_447 , V_450 ,
& V_451 ) ) {
V_479 ++ ;
V_407 = V_478 [ V_479 ] ;
}
* V_407 = * V_449 ;
if ( F_214 ( V_447 ) &&
V_68 < V_456 + ( V_463 == 0 ) ) {
V_407 -> V_108 = V_109 ;
} else {
V_407 -> V_108 =
V_482 | V_241 ;
}
switch ( V_407 -> V_105 ) {
case V_444 :
if ( V_481 )
V_479 ++ ;
break;
case V_107 :
if ( V_68 < V_456 + ( V_463 == 0 ) ) {
V_407 -> V_88 = 0 ;
F_207 ( V_22 , V_407 ,
V_447 , V_468 ) ;
F_212 ( V_407 , V_447 ,
V_468 ) ;
}
V_479 ++ ;
break;
case V_483 :
case V_484 :
case V_485 :
V_479 ++ ;
break;
case V_106 :
if ( ! F_61 ( V_447 ) )
break;
V_479 ++ ;
break;
default:
break;
}
if ( V_479 >= V_161 )
break;
}
F_97 ( V_22 , V_168 , V_478 , V_479 ) ;
V_377:
F_78 ( V_449 ) ;
for ( V_68 = 0 ; V_68 < V_477 ; V_68 ++ )
F_78 ( V_478 [ V_68 ] ) ;
F_78 ( V_478 ) ;
F_78 ( V_464 ) ;
F_78 ( V_465 ) ;
F_78 ( V_468 ) ;
}
static void F_216 ( struct V_258 * V_486 ,
struct V_487 * V_255 )
{
T_5 V_357 = ( T_5 ) F_217 ( V_255 ) ;
unsigned int V_50 = F_218 ( V_255 ) ;
V_486 -> V_266 = F_119 ( V_357 ) ;
V_486 -> V_265 = F_124 ( V_50 ) ;
V_486 -> V_262 = 0 ;
}
static int F_219 ( struct V_1 * V_22 ,
struct V_8 * V_131 ,
struct V_267 * V_268 )
{
struct V_487 * V_255 ;
int V_488 , V_68 , V_489 , V_490 , V_491 ;
struct V_258 * V_492 ;
F_73 ( F_144 ( V_268 ) > V_22 -> V_246 ) ;
V_488 = F_220 ( V_268 ) ;
if ( V_488 < 0 )
return V_488 ;
if ( ! V_488 )
goto V_493;
V_492 = V_131 -> V_260 ;
V_490 = V_488 > V_22 -> V_261 ;
V_489 = V_490 ? V_22 -> V_261 - 1 : V_488 ;
V_491 = F_144 ( V_268 ) - 1 ;
F_221 (cmd, sg, sg_limit, i) {
F_216 ( V_492 , V_255 ) ;
V_492 ++ ;
}
if ( V_490 ) {
V_492 = V_22 -> V_248 [ V_131 -> V_133 ] ;
V_489 = V_488 - V_489 ;
F_222 (sg, sg, sg_limit, i) {
F_216 ( V_492 , V_255 ) ;
V_492 ++ ;
}
}
( V_492 - 1 ) -> V_262 = F_124 ( V_359 ) ;
if ( V_488 + V_490 > V_22 -> V_494 )
V_22 -> V_494 = V_488 + V_490 ;
if ( V_490 ) {
V_131 -> V_124 . V_125 = V_22 -> V_261 ;
V_131 -> V_124 . V_264 = F_145 ( V_488 + 1 ) ;
if ( F_123 ( V_22 , V_131 ) ) {
F_143 ( V_268 ) ;
return - 1 ;
}
return 0 ;
}
V_493:
V_131 -> V_124 . V_125 = ( T_1 ) V_488 ;
V_131 -> V_124 . V_264 = F_145 ( V_488 ) ;
return 0 ;
}
static int F_223 ( T_1 * V_141 , int * V_495 )
{
int V_496 = 0 ;
T_4 V_497 ;
T_4 V_498 ;
switch ( V_141 [ 0 ] ) {
case V_499 :
case V_500 :
V_496 = 1 ;
case V_501 :
case V_502 :
if ( * V_495 == 6 ) {
V_497 = ( ( ( T_4 ) V_141 [ 2 ] ) << 8 ) | V_141 [ 3 ] ;
V_498 = V_141 [ 4 ] ;
} else {
F_73 ( * V_495 != 12 ) ;
V_497 = ( ( ( T_4 ) V_141 [ 2 ] ) << 24 ) |
( ( ( T_4 ) V_141 [ 3 ] ) << 16 ) |
( ( ( T_4 ) V_141 [ 4 ] ) << 8 ) |
V_141 [ 5 ] ;
V_498 =
( ( ( T_4 ) V_141 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_141 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_141 [ 8 ] ) << 8 ) |
V_141 [ 9 ] ;
}
if ( V_498 > 0xffff )
return V_503 ;
V_141 [ 0 ] = V_496 ? V_504 : V_505 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_497 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_497 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_497 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_497 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_498 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_498 ) ;
V_141 [ 9 ] = 0 ;
* V_495 = 10 ;
break;
}
return 0 ;
}
static int F_224 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_182 , T_1 * V_141 , int V_495 ,
T_1 * V_72 , struct V_75 * V_231 )
{
struct V_267 * V_268 = V_9 -> V_10 ;
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
unsigned int V_50 ;
unsigned int V_506 = 0 ;
struct V_487 * V_255 ;
T_5 V_357 ;
int V_488 , V_68 ;
struct V_258 * V_492 ;
T_4 V_507 = V_508 ;
if ( F_144 ( V_268 ) > V_22 -> V_509 ) {
F_44 ( & V_231 -> V_239 ) ;
return V_503 ;
}
F_73 ( V_268 -> V_510 > V_511 ) ;
if ( F_223 ( V_141 , & V_495 ) ) {
F_44 ( & V_231 -> V_239 ) ;
return V_503 ;
}
V_9 -> V_150 = V_151 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_512 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_73 ( V_9 -> V_122 & 0x0000007F ) ;
V_488 = F_220 ( V_268 ) ;
if ( V_488 < 0 ) {
F_44 ( & V_231 -> V_239 ) ;
return V_488 ;
}
if ( V_488 ) {
V_492 = V_131 -> V_260 ;
F_221 (cmd, sg, use_sg, i) {
V_357 = ( T_5 ) F_217 ( V_255 ) ;
V_50 = F_218 ( V_255 ) ;
V_506 += V_50 ;
V_492 -> V_266 = F_119 ( V_357 ) ;
V_492 -> V_265 = F_124 ( V_50 ) ;
V_492 -> V_262 = F_124 ( 0 ) ;
V_492 ++ ;
}
( -- V_492 ) -> V_262 = F_124 ( V_359 ) ;
switch ( V_268 -> V_513 ) {
case V_514 :
V_507 |= V_515 ;
break;
case V_516 :
V_507 |= V_517 ;
break;
case V_518 :
V_507 |= V_519 ;
break;
default:
F_71 ( & V_22 -> V_29 -> V_30 , L_149 ,
V_268 -> V_513 ) ;
F_167 () ;
break;
}
} else {
V_507 |= V_519 ;
}
V_9 -> V_124 . V_125 = V_488 ;
V_131 -> V_520 = F_145 ( V_182 & 0xFFFF ) ;
V_131 -> V_521 = F_124 ( V_506 ) ;
V_131 -> V_329 = F_145 ( V_522 |
( V_495 & V_330 ) ) ;
V_131 -> V_507 = F_124 ( V_507 ) ;
memcpy ( V_131 -> V_145 , V_141 , V_495 ) ;
memcpy ( V_131 -> V_334 , V_72 , 8 ) ;
F_59 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_225 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_267 * V_268 = V_9 -> V_10 ;
struct V_75 * V_30 = V_268 -> V_42 -> V_79 ;
V_9 -> V_231 = V_30 ;
return F_226 ( V_22 , V_9 , V_30 -> V_182 ,
V_268 -> V_523 , V_268 -> V_510 , V_30 -> V_72 , V_30 ) ;
}
static void F_227 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_139 * V_131 )
{
struct V_267 * V_268 = V_9 -> V_10 ;
struct V_75 * V_30 = V_268 -> V_42 -> V_79 ;
struct V_216 * V_217 = & V_30 -> V_181 ;
T_5 V_524 ;
if ( ! ( F_94 ( V_217 -> V_77 ) & V_404 ) )
return;
V_131 -> V_405 = V_217 -> V_405 ;
V_131 -> V_525 |= V_526 ;
switch ( V_268 -> V_523 [ 0 ] ) {
case V_499 :
case V_501 :
V_524 = F_228 ( & V_268 -> V_523 [ 2 ] ) ;
break;
case V_504 :
case V_505 :
case V_500 :
case V_502 :
V_524 = F_229 ( & V_268 -> V_523 [ 2 ] ) ;
break;
case V_527 :
case V_528 :
V_524 = F_230 ( & V_268 -> V_523 [ 2 ] ) ;
break;
default:
F_71 ( & V_22 -> V_29 -> V_30 ,
L_150 ,
V_199 , V_268 -> V_523 [ 0 ] ) ;
F_167 () ;
break;
}
if ( F_116 ( V_217 -> V_397 ) != 512 )
V_524 = V_524 *
F_116 ( V_217 -> V_397 ) / 512 ;
V_131 -> V_529 = F_124 ( V_524 ) ;
V_131 -> V_530 = F_124 ( V_524 >> 32 ) ;
}
static int F_231 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_182 , T_1 * V_141 , int V_495 ,
T_1 * V_72 , struct V_75 * V_231 )
{
struct V_267 * V_268 = V_9 -> V_10 ;
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_249 * V_492 ;
int V_488 , V_68 ;
struct V_487 * V_255 ;
T_5 V_357 ;
T_4 V_50 ;
T_4 V_506 = 0 ;
F_73 ( F_144 ( V_268 ) > V_22 -> V_246 ) ;
if ( F_223 ( V_141 , & V_495 ) ) {
F_44 ( & V_231 -> V_239 ) ;
return V_503 ;
}
V_9 -> V_150 = V_154 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_531 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_73 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_532 = V_533 ;
V_488 = F_220 ( V_268 ) ;
if ( V_488 < 0 ) {
F_44 ( & V_231 -> V_239 ) ;
return V_488 ;
}
if ( V_488 ) {
V_492 = V_131 -> V_255 ;
if ( V_488 > V_22 -> V_509 ) {
V_357 = F_121 (
V_22 -> V_243 [ V_9 -> V_133 ] -> V_256 ) ;
V_492 -> V_256 = F_119 ( V_357 ) ;
V_492 -> V_534 = 0 ;
V_492 -> V_535 [ 0 ] = 0 ;
V_492 -> V_535 [ 1 ] = 0 ;
V_492 -> V_535 [ 2 ] = 0 ;
V_492 -> V_323 = 0x80 ;
V_492 = V_22 -> V_243 [ V_9 -> V_133 ] ;
}
F_221 (cmd, sg, use_sg, i) {
V_357 = ( T_5 ) F_217 ( V_255 ) ;
V_50 = F_218 ( V_255 ) ;
V_506 += V_50 ;
V_492 -> V_256 = F_119 ( V_357 ) ;
V_492 -> V_534 = F_124 ( V_50 ) ;
V_492 -> V_535 [ 0 ] = 0 ;
V_492 -> V_535 [ 1 ] = 0 ;
V_492 -> V_535 [ 2 ] = 0 ;
V_492 -> V_323 = 0 ;
V_492 ++ ;
}
switch ( V_268 -> V_513 ) {
case V_514 :
V_131 -> V_525 &= ~ V_536 ;
V_131 -> V_525 |= V_537 ;
break;
case V_516 :
V_131 -> V_525 &= ~ V_536 ;
V_131 -> V_525 |= V_538 ;
break;
case V_518 :
V_131 -> V_525 &= ~ V_536 ;
V_131 -> V_525 |= V_539 ;
break;
default:
F_71 ( & V_22 -> V_29 -> V_30 , L_149 ,
V_268 -> V_513 ) ;
F_167 () ;
break;
}
} else {
V_131 -> V_525 &= ~ V_536 ;
V_131 -> V_525 |= V_539 ;
}
F_227 ( V_22 , V_9 , V_131 ) ;
V_131 -> V_454 = F_124 ( V_182 ) ;
V_131 -> V_540 = F_124 ( V_9 -> V_133 << V_541 ) ;
memcpy ( V_131 -> V_141 , V_141 , sizeof( V_131 -> V_141 ) ) ;
V_131 -> V_253 = F_124 ( V_506 ) ;
V_131 -> V_542 = F_119 ( V_9 -> V_122 +
F_232 ( struct V_139 , V_272 ) ) ;
V_131 -> V_543 = F_124 ( sizeof( V_131 -> V_272 ) ) ;
if ( V_488 > V_22 -> V_509 ) {
V_131 -> V_140 = 1 ;
if ( F_115 ( V_22 , V_131 , V_9 ) ) {
F_44 ( & V_231 -> V_239 ) ;
F_143 ( V_268 ) ;
return - 1 ;
}
} else
V_131 -> V_140 = ( T_1 ) V_488 ;
F_59 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_226 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_182 , T_1 * V_141 , int V_495 ,
T_1 * V_72 , struct V_75 * V_231 )
{
if ( F_170 ( & V_231 -> V_239 ) >
V_231 -> V_185 ) {
F_44 ( & V_231 -> V_239 ) ;
return V_503 ;
}
if ( V_22 -> V_63 & V_114 )
return F_224 ( V_22 , V_9 , V_182 ,
V_141 , V_495 , V_72 ,
V_231 ) ;
else
return F_231 ( V_22 , V_9 , V_182 ,
V_141 , V_495 , V_72 ,
V_231 ) ;
}
static void F_233 ( struct V_216 * V_217 ,
int V_184 , T_4 * V_544 , T_4 * V_545 )
{
if ( V_184 == 0 ) {
* V_544 %= F_94 ( V_217 -> V_222 ) ;
return;
}
do {
* V_545 = * V_544 /
F_94 ( V_217 -> V_222 ) ;
if ( V_184 == * V_545 )
continue;
if ( * V_545 < F_94 ( V_217 -> V_226 ) - 1 ) {
* V_544 += F_94 ( V_217 -> V_222 ) ;
( * V_545 ) ++ ;
} else {
* V_544 %= F_94 ( V_217 -> V_222 ) ;
* V_545 = 0 ;
}
} while ( V_184 != * V_545 );
}
static int F_234 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_267 * V_268 = V_9 -> V_10 ;
struct V_75 * V_30 = V_268 -> V_42 -> V_79 ;
struct V_216 * V_217 = & V_30 -> V_181 ;
struct V_218 * V_219 = & V_217 -> V_220 [ 0 ] ;
int V_496 = 0 ;
T_4 V_544 ;
T_5 V_524 , V_546 ;
T_4 V_498 ;
T_4 V_547 ;
T_5 V_548 , V_549 ;
T_4 V_550 , V_551 ;
T_4 V_552 , V_553 ;
T_5 V_554 , V_555 ;
T_4 V_556 ;
T_5 V_557 , V_558 ;
T_4 V_559 , V_560 ;
T_4 V_561 , V_562 ;
T_4 V_221 ;
T_4 V_563 ;
T_4 V_564 , V_565 , V_545 ;
T_4 V_566 ;
T_4 V_567 ;
T_5 V_568 ;
T_4 V_569 ;
T_1 V_141 [ 16 ] ;
T_1 V_495 ;
T_6 V_401 ;
#if V_570 == 32
T_5 V_571 ;
#endif
int V_184 ;
switch ( V_268 -> V_523 [ 0 ] ) {
case V_499 :
V_496 = 1 ;
case V_501 :
V_524 =
( ( ( T_5 ) V_268 -> V_523 [ 2 ] ) << 8 ) |
V_268 -> V_523 [ 3 ] ;
V_498 = V_268 -> V_523 [ 4 ] ;
if ( V_498 == 0 )
V_498 = 256 ;
break;
case V_504 :
V_496 = 1 ;
case V_505 :
V_524 =
( ( ( T_5 ) V_268 -> V_523 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_268 -> V_523 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_268 -> V_523 [ 4 ] ) << 8 ) |
V_268 -> V_523 [ 5 ] ;
V_498 =
( ( ( T_4 ) V_268 -> V_523 [ 7 ] ) << 8 ) |
V_268 -> V_523 [ 8 ] ;
break;
case V_500 :
V_496 = 1 ;
case V_502 :
V_524 =
( ( ( T_5 ) V_268 -> V_523 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_268 -> V_523 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_268 -> V_523 [ 4 ] ) << 8 ) |
V_268 -> V_523 [ 5 ] ;
V_498 =
( ( ( T_4 ) V_268 -> V_523 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_268 -> V_523 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_268 -> V_523 [ 8 ] ) << 8 ) |
V_268 -> V_523 [ 9 ] ;
break;
case V_527 :
V_496 = 1 ;
case V_528 :
V_524 =
( ( ( T_5 ) V_268 -> V_523 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_268 -> V_523 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_268 -> V_523 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_268 -> V_523 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_268 -> V_523 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_268 -> V_523 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_268 -> V_523 [ 8 ] ) << 8 ) |
V_268 -> V_523 [ 9 ] ;
V_498 =
( ( ( T_4 ) V_268 -> V_523 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_268 -> V_523 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_268 -> V_523 [ 12 ] ) << 8 ) |
V_268 -> V_523 [ 13 ] ;
break;
default:
return V_503 ;
}
V_546 = V_524 + V_498 - 1 ;
if ( V_496 && V_30 -> V_82 != 0 )
return V_503 ;
if ( V_546 >= F_121 ( V_217 -> V_398 ) ||
V_546 < V_524 )
return V_503 ;
V_547 = F_94 ( V_217 -> V_222 ) *
F_94 ( V_217 -> V_401 ) ;
V_401 = F_94 ( V_217 -> V_401 ) ;
#if V_570 == 32
V_571 = V_524 ;
( void ) F_235 ( V_571 , V_547 ) ;
V_548 = V_571 ;
V_571 = V_546 ;
( void ) F_235 ( V_571 , V_547 ) ;
V_549 = V_571 ;
V_550 = ( T_4 ) ( V_524 - ( V_548 * V_547 ) ) ;
V_551 = ( T_4 ) ( V_546 - ( V_549 * V_547 ) ) ;
V_571 = V_550 ;
( void ) F_235 ( V_571 , V_401 ) ;
V_552 = V_571 ;
V_571 = V_551 ;
( void ) F_235 ( V_571 , V_401 ) ;
V_553 = V_571 ;
#else
V_548 = V_524 / V_547 ;
V_549 = V_546 / V_547 ;
V_550 = ( T_4 ) ( V_524 - ( V_548 * V_547 ) ) ;
V_551 = ( T_4 ) ( V_546 - ( V_549 * V_547 ) ) ;
V_552 = V_550 / V_401 ;
V_553 = V_551 / V_401 ;
#endif
if ( ( V_548 != V_549 ) || ( V_552 != V_553 ) )
return V_503 ;
V_221 = F_94 ( V_217 -> V_222 ) +
F_94 ( V_217 -> V_223 ) ;
V_566 = ( ( T_4 ) ( V_548 >> V_217 -> V_400 ) ) %
F_94 ( V_217 -> V_225 ) ;
V_544 = ( V_566 * V_221 ) + V_552 ;
switch ( V_30 -> V_82 ) {
case V_572 :
break;
case V_573 :
F_73 ( F_94 ( V_217 -> V_226 ) != 2 ) ;
if ( V_30 -> V_184 )
V_544 += F_94 ( V_217 -> V_222 ) ;
V_30 -> V_184 = ! V_30 -> V_184 ;
break;
case V_574 :
F_73 ( F_94 ( V_217 -> V_226 ) != 3 ) ;
V_184 = V_30 -> V_184 ;
F_233 ( V_217 , V_184 ,
& V_544 , & V_545 ) ;
V_184 =
( V_184 >=
F_94 ( V_217 -> V_226 ) - 1 )
? 0 : V_184 + 1 ;
V_30 -> V_184 = V_184 ;
break;
case V_575 :
case V_576 :
if ( F_94 ( V_217 -> V_226 ) <= 1 )
break;
V_556 =
F_94 ( V_217 -> V_401 ) *
F_94 ( V_217 -> V_222 ) ;
F_73 ( V_556 == 0 ) ;
V_563 = V_556 *
F_94 ( V_217 -> V_226 ) ;
#if V_570 == 32
V_571 = V_524 ;
V_564 = F_235 ( V_571 , V_563 ) ;
V_571 = V_564 ;
( void ) F_235 ( V_571 , V_556 ) ;
V_564 = V_571 ;
V_571 = V_546 ;
V_565 = F_235 ( V_571 , V_563 ) ;
V_571 = V_565 ;
( void ) F_235 ( V_571 , V_556 ) ;
V_565 = V_571 ;
#else
V_564 = ( V_524 % V_563 ) / V_556 ;
V_565 = ( V_546 % V_563 ) / V_556 ;
#endif
if ( V_564 != V_565 )
return V_503 ;
#if V_570 == 32
V_571 = V_524 ;
( void ) F_235 ( V_571 , V_563 ) ;
V_548 = V_557 = V_554 = V_571 ;
V_571 = V_546 ;
( void ) F_235 ( V_571 , V_563 ) ;
V_558 = V_555 = V_571 ;
#else
V_548 = V_557 = V_554 =
V_524 / V_563 ;
V_558 = V_555 = V_546 / V_563 ;
#endif
if ( V_557 != V_558 )
return V_503 ;
#if V_570 == 32
V_571 = V_524 ;
V_550 = F_235 ( V_571 , V_563 ) ;
V_571 = V_550 ;
V_550 = ( T_4 ) F_235 ( V_571 , V_556 ) ;
V_559 = V_550 ;
V_571 = V_546 ;
V_560 = F_235 ( V_571 , V_563 ) ;
V_571 = V_560 ;
V_560 = F_235 ( V_571 , V_556 ) ;
V_571 = V_559 ;
( void ) F_235 ( V_571 , V_217 -> V_401 ) ;
V_552 = V_561 = V_571 ;
V_571 = V_560 ;
( void ) F_235 ( V_571 , V_217 -> V_401 ) ;
V_562 = V_571 ;
#else
V_550 = V_559 =
( T_4 ) ( ( V_524 % V_563 ) %
V_556 ) ;
V_560 =
( T_4 ) ( ( V_546 % V_563 ) %
V_556 ) ;
V_552 = V_561 =
V_559 / F_94 ( V_217 -> V_401 ) ;
V_562 =
V_560 / F_94 ( V_217 -> V_401 ) ;
#endif
if ( V_561 != V_562 )
return V_503 ;
V_566 = ( ( T_4 ) ( V_548 >> V_217 -> V_400 ) ) %
F_94 ( V_217 -> V_225 ) ;
V_544 = ( V_564 *
( F_94 ( V_217 -> V_225 ) * V_221 ) ) +
( V_566 * V_221 ) + V_552 ;
break;
default:
return V_503 ;
}
if ( F_43 ( V_544 >= V_229 ) )
return V_503 ;
V_9 -> V_231 = V_30 -> V_231 [ V_544 ] ;
V_567 = V_219 [ V_544 ] . V_182 ;
V_568 = F_121 ( V_217 -> V_402 ) +
V_548 * F_94 ( V_217 -> V_401 ) +
( V_550 - V_552 *
F_94 ( V_217 -> V_401 ) ) ;
V_569 = V_498 ;
if ( V_217 -> V_399 ) {
V_568 <<= V_217 -> V_399 ;
V_569 <<= V_217 -> V_399 ;
}
F_73 ( V_569 > 0xffff ) ;
if ( V_568 > 0xffffffff ) {
V_141 [ 0 ] = V_496 ? V_527 : V_528 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_568 >> 56 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_568 >> 48 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_568 >> 40 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_568 >> 32 ) ;
V_141 [ 6 ] = ( T_1 ) ( V_568 >> 24 ) ;
V_141 [ 7 ] = ( T_1 ) ( V_568 >> 16 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_568 >> 8 ) ;
V_141 [ 9 ] = ( T_1 ) ( V_568 ) ;
V_141 [ 10 ] = ( T_1 ) ( V_569 >> 24 ) ;
V_141 [ 11 ] = ( T_1 ) ( V_569 >> 16 ) ;
V_141 [ 12 ] = ( T_1 ) ( V_569 >> 8 ) ;
V_141 [ 13 ] = ( T_1 ) ( V_569 ) ;
V_141 [ 14 ] = 0 ;
V_141 [ 15 ] = 0 ;
V_495 = 16 ;
} else {
V_141 [ 0 ] = V_496 ? V_504 : V_505 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_568 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_568 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_568 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_568 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_569 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_569 ) ;
V_141 [ 9 ] = 0 ;
V_495 = 10 ;
}
return F_226 ( V_22 , V_9 , V_567 , V_141 , V_495 ,
V_30 -> V_72 ,
V_30 -> V_231 [ V_544 ] ) ;
}
static int F_236 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_267 * V_268 ,
unsigned char V_72 [] )
{
V_268 -> V_577 = ( unsigned char * ) V_9 ;
V_9 -> V_150 = V_322 ;
V_9 -> V_10 = V_268 ;
V_9 -> V_124 . V_128 = 0 ;
memcpy ( & V_9 -> V_124 . V_332 . V_333 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_124 . V_331 = F_119 ( ( V_9 -> V_133 << V_541 ) ) ;
V_9 -> V_144 . V_578 = 0 ;
F_73 ( V_268 -> V_510 > sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_328 = V_268 -> V_510 ;
memcpy ( V_9 -> V_144 . V_145 , V_268 -> V_523 , V_268 -> V_510 ) ;
switch ( V_268 -> V_513 ) {
case V_514 :
V_9 -> V_144 . V_579 =
F_237 ( V_376 , V_580 , V_581 ) ;
break;
case V_516 :
V_9 -> V_144 . V_579 =
F_237 ( V_376 , V_580 , V_582 ) ;
break;
case V_518 :
V_9 -> V_144 . V_579 =
F_237 ( V_376 , V_580 , V_583 ) ;
break;
case V_584 :
V_9 -> V_144 . V_579 =
F_237 ( V_376 , V_580 , V_585 ) ;
break;
default:
F_71 ( & V_22 -> V_29 -> V_30 , L_149 ,
V_268 -> V_513 ) ;
F_167 () ;
break;
}
if ( F_219 ( V_22 , V_9 , V_268 ) < 0 ) {
F_132 ( V_22 , V_9 ) ;
return V_586 ;
}
F_59 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_22 , int V_194 ,
struct V_8 * V_9 )
{
V_355 V_587 , V_588 ;
memset ( V_9 , 0 , F_232 ( struct V_8 , V_389 ) ) ;
V_9 -> V_124 . V_331 = F_119 ( ( T_5 ) ( V_194 << V_541 ) ) ;
V_587 = V_22 -> V_589 + V_194 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_590 + V_194 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_588 = V_22 -> V_591
+ V_194 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_133 = V_194 ;
V_9 -> V_122 = ( T_4 ) V_587 ;
V_9 -> V_592 . V_266 = F_119 ( ( T_5 ) V_588 ) ;
V_9 -> V_592 . V_265 = F_124 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_239 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_388 + V_68 ;
F_238 ( V_22 , V_68 , V_9 ) ;
F_107 ( & V_9 -> V_389 , 0 ) ;
}
}
static inline void F_240 ( struct V_1 * V_22 , int V_194 ,
struct V_8 * V_9 )
{
V_355 V_587 = V_22 -> V_589 + V_194 * sizeof( * V_9 ) ;
F_73 ( V_9 -> V_133 != V_194 ) ;
memset ( V_9 -> V_144 . V_145 , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_122 = ( T_4 ) V_587 ;
}
static int F_241 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_267 * V_268 ,
unsigned char * V_72 )
{
struct V_75 * V_30 = V_268 -> V_42 -> V_79 ;
int V_21 = V_503 ;
V_268 -> V_577 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_88 ) {
F_238 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_322 ;
V_9 -> V_10 = V_268 ;
V_21 = F_234 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_586 ;
} else if ( V_30 -> V_183 ) {
F_238 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_322 ;
V_9 -> V_10 = V_268 ;
V_21 = F_225 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_586 ;
}
return V_21 ;
}
static void V_308 ( struct V_593 * V_307 )
{
struct V_267 * V_268 ;
struct V_75 * V_30 ;
struct V_8 * V_9 = F_242 ( V_307 , struct V_8 , V_307 ) ;
V_268 = V_9 -> V_10 ;
V_30 = V_268 -> V_42 -> V_79 ;
if ( ! V_30 ) {
V_268 -> V_277 = V_326 << 16 ;
return F_134 ( V_9 -> V_22 , V_9 , V_268 ) ;
}
if ( V_9 -> V_13 )
return F_132 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_139 ( V_9 -> V_22 , V_9 , V_268 ) ;
if ( V_9 -> V_150 == V_154 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_139 * V_269 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
int V_21 ;
if ( V_269 -> V_272 . V_273 ==
V_286 ) {
V_21 = F_241 ( V_22 , V_9 , V_268 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_586 ) {
V_268 -> V_277 = V_594 << 16 ;
return F_134 ( V_22 , V_9 , V_268 ) ;
}
}
}
F_240 ( V_9 -> V_22 , V_9 -> V_133 , V_9 ) ;
if ( F_236 ( V_9 -> V_22 , V_9 , V_268 , V_30 -> V_72 ) ) {
V_268 -> V_277 = V_594 << 16 ;
V_268 -> V_306 ( V_268 ) ;
}
}
static int F_243 ( struct V_6 * V_7 , struct V_267 * V_268 )
{
struct V_1 * V_22 ;
struct V_75 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_268 -> V_42 ) ;
F_73 ( V_268 -> V_595 -> V_331 < 0 ) ;
V_30 = V_268 -> V_42 -> V_79 ;
if ( ! V_30 ) {
V_268 -> V_277 = V_326 << 16 ;
V_268 -> V_306 ( V_268 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_43 ( F_13 ( V_22 ) ) ) {
V_268 -> V_277 = V_326 << 16 ;
V_268 -> V_306 ( V_268 ) ;
return 0 ;
}
V_9 = F_244 ( V_22 , V_268 ) ;
if ( F_46 ( V_268 -> V_596 == 0 &&
V_268 -> V_595 -> V_150 == V_597 &&
V_22 -> V_56 ) ) {
V_21 = F_241 ( V_22 , V_9 , V_268 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_586 ) {
F_132 ( V_22 , V_9 ) ;
return V_586 ;
}
}
return F_236 ( V_22 , V_9 , V_268 , V_72 ) ;
}
static void F_245 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
F_34 ( & V_22 -> V_598 , V_77 ) ;
V_22 -> V_599 = 1 ;
F_131 ( & V_22 -> V_600 ) ;
F_35 ( & V_22 -> V_598 , V_77 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_77 ;
if ( F_43 ( F_13 ( V_22 ) ) )
return F_245 ( V_22 ) ;
while ( 1 ) {
F_34 ( & V_22 -> V_598 , V_77 ) ;
if ( V_22 -> V_599 )
break;
F_35 ( & V_22 -> V_598 , V_77 ) ;
F_171 ( V_22 -> V_600 , V_22 -> V_599 ) ;
}
V_22 -> V_599 = 0 ;
F_35 ( & V_22 -> V_598 , V_77 ) ;
if ( F_43 ( F_13 ( V_22 ) ) )
return F_245 ( V_22 ) ;
F_213 ( V_22 , V_22 -> V_59 -> V_101 ) ;
F_245 ( V_22 ) ;
}
static int F_246 ( struct V_2 * V_3 , int V_228 )
{
struct V_75 * V_215 = V_3 -> V_79 ;
if ( ! V_215 )
return - V_80 ;
if ( V_228 < 1 )
V_228 = 1 ;
else if ( V_228 > V_215 -> V_185 )
V_228 = V_215 -> V_185 ;
return F_109 ( V_3 , V_228 ) ;
}
static int F_247 ( struct V_6 * V_7 ,
unsigned long V_601 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_77 ;
int V_602 ;
F_34 ( & V_22 -> V_598 , V_77 ) ;
V_602 = V_22 -> V_599 ;
F_35 ( & V_22 -> V_598 , V_77 ) ;
return V_602 ;
}
static int F_248 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_249 ( & V_603 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_151 ) ;
return - V_245 ;
}
V_7 -> V_604 = 0 ;
V_7 -> V_605 = 0 ;
V_7 -> V_606 = - 1 ;
V_7 -> V_607 = 3 ;
V_7 -> V_608 = V_609 ;
V_7 -> V_610 = V_462 ;
V_7 -> V_611 = V_462 ;
V_7 -> V_242 = V_22 -> V_232 - V_612 ;
V_7 -> V_613 = V_7 -> V_242 ;
V_7 -> V_614 = V_22 -> V_246 ;
V_7 -> V_79 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_615 = V_22 -> V_616 [ V_22 -> V_617 ] ;
V_7 -> V_618 = V_7 -> V_615 ;
error = F_250 ( V_7 , V_7 -> V_242 ) ;
if ( error ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_152 ,
V_199 , V_22 -> V_619 ) ;
F_251 ( V_7 ) ;
return error ;
}
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_252 ( struct V_1 * V_22 )
{
int V_620 ;
V_620 = F_253 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_620 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_153 ) ;
return V_620 ;
}
F_254 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_255 ( struct V_267 * V_621 )
{
int V_622 = V_621 -> V_595 -> V_331 ;
if ( V_622 < 0 )
return V_622 ;
return V_622 += V_612 ;
}
static int F_256 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_623 [] ,
int V_113 )
{
int V_21 ;
( void ) F_163 ( V_9 , V_435 , V_22 ,
NULL , 0 , 0 , V_623 , V_376 ) ;
V_21 = F_153 ( V_22 , V_9 , V_113 , V_363 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_624 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_278 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_625 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_257 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_623 [] , int V_113 )
{
int V_21 ;
int V_48 = 0 ;
int V_626 = 1 ;
for ( V_48 = 0 ; V_48 < V_627 ; V_48 ++ ) {
F_158 ( 1000 * V_626 ) ;
V_21 = F_256 ( V_22 , V_9 , V_623 , V_113 ) ;
if ( ! V_21 )
break;
if ( V_626 < V_628 )
V_626 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_154 ,
V_626 ) ;
}
return V_21 ;
}
static int F_258 ( struct V_1 * V_22 ,
unsigned char V_623 [] ,
int V_113 )
{
int V_629 ;
int V_630 ;
int V_112 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_162 ( V_22 ) ;
if ( V_113 == V_127 ) {
V_629 = 0 ;
V_630 = V_22 -> V_129 - 1 ;
} else {
V_629 = V_113 ;
V_630 = V_113 ;
}
for ( V_112 = V_629 ; V_112 <= V_630 ; V_112 ++ ) {
V_21 = F_257 ( V_22 , V_9 , V_623 , V_112 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_155 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_156 ) ;
F_164 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_259 ( struct V_267 * V_631 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_75 * V_30 ;
char V_632 [ 48 ] ;
V_22 = F_1 ( V_631 -> V_42 ) ;
if ( V_22 == NULL )
return V_633 ;
if ( F_13 ( V_22 ) )
return V_633 ;
V_30 = V_631 -> V_42 -> V_79 ;
if ( ! V_30 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_157 , V_199 ) ;
return V_633 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_632 , sizeof( V_632 ) ,
L_158 ,
F_255 ( V_631 ) ) ;
F_68 ( V_238 , V_22 , V_30 , V_632 ) ;
return V_633 ;
}
if ( F_260 ( V_22 ) ) {
snprintf ( V_632 , sizeof( V_632 ) ,
L_159 ,
F_255 ( V_631 ) ) ;
F_68 ( V_238 , V_22 , V_30 , V_632 ) ;
return V_633 ;
}
if ( F_61 ( V_30 -> V_72 ) )
return V_634 ;
F_68 ( V_238 , V_22 , V_30 , L_160 ) ;
V_21 = F_168 ( V_22 , V_30 , V_30 -> V_72 , V_635 ,
V_127 ) ;
snprintf ( V_632 , sizeof( V_632 ) , L_161 ,
V_21 == 0 ? L_162 : L_163 ) ;
F_68 ( V_238 , V_22 , V_30 , V_632 ) ;
return V_21 == 0 ? V_634 : V_633 ;
}
static void F_261 ( T_1 * V_331 )
{
T_1 V_636 [ 8 ] ;
memcpy ( V_636 , V_331 , 8 ) ;
V_331 [ 0 ] = V_636 [ 3 ] ;
V_331 [ 1 ] = V_636 [ 2 ] ;
V_331 [ 2 ] = V_636 [ 1 ] ;
V_331 [ 3 ] = V_636 [ 0 ] ;
V_331 [ 4 ] = V_636 [ 7 ] ;
V_331 [ 5 ] = V_636 [ 6 ] ;
V_331 [ 6 ] = V_636 [ 5 ] ;
V_331 [ 7 ] = V_636 [ 4 ] ;
}
static void F_262 ( struct V_1 * V_22 ,
struct V_8 * V_9 , V_448 * V_637 , V_448 * V_638 )
{
T_5 V_331 ;
if ( V_9 -> V_150 == V_151 ) {
struct V_130 * V_639 = (struct V_130 * )
& V_22 -> V_132 [ V_9 -> V_133 ] ;
V_331 = F_121 ( V_639 -> V_331 ) ;
* V_638 = F_124 ( V_331 >> 32 ) ;
* V_637 = F_124 ( V_331 ) ;
return;
}
if ( V_9 -> V_150 == V_154 ) {
struct V_139 * V_640 = (struct V_139 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
memset ( V_638 , 0 , sizeof( * V_638 ) ) ;
* V_637 = V_640 -> V_540 ;
return;
}
V_331 = F_121 ( V_9 -> V_124 . V_331 ) ;
* V_638 = F_124 ( V_331 >> 32 ) ;
* V_637 = F_124 ( V_331 ) ;
}
static int F_263 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
struct V_319 * V_320 ;
V_448 V_638 , V_637 ;
V_9 = F_162 ( V_22 ) ;
( void ) F_163 ( V_9 , V_437 , V_22 , & abort -> V_124 . V_331 ,
0 , 0 , V_72 , V_381 ) ;
if ( V_22 -> V_71 )
F_261 ( & V_9 -> V_144 . V_145 [ 4 ] ) ;
( void ) F_153 ( V_22 , V_9 , V_113 , V_363 ) ;
F_262 ( V_22 , abort , & V_637 , & V_638 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_164 ,
V_199 , V_638 , V_637 ) ;
V_320 = V_9 -> V_24 ;
switch ( V_320 -> V_36 ) {
case V_624 :
break;
case V_351 :
V_21 = F_141 ( V_22 , V_9 ) ;
break;
case V_350 :
V_21 = - 1 ;
break;
default:
F_264 ( & V_22 -> V_29 -> V_30 , L_165 ,
V_199 , V_638 , V_637 ) ;
F_160 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_164 ( V_22 , V_9 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_199 , V_638 , V_637 ) ;
return V_21 ;
}
static void F_265 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_641 , int V_113 )
{
struct V_139 * V_269 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_383 = (struct V_136 * ) V_269 ;
struct V_139 * V_642 =
& V_22 -> V_137 [ V_641 -> V_133 ] ;
struct V_267 * V_621 = V_641 -> V_10 ;
struct V_75 * V_30 = V_621 -> V_42 -> V_79 ;
F_266 ( sizeof( struct V_136 ) >
sizeof( struct V_139 ) ) ;
F_73 ( F_232 ( struct V_139 , V_272 ) <
F_232 ( struct V_136 , V_643 ) +
sizeof( V_383 -> V_643 ) ) ;
V_9 -> V_150 = V_156 ;
V_9 -> V_10 = V_644 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_531 +
( V_9 -> V_133 * sizeof( struct V_139 ) ) ;
F_73 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_383 , 0 , sizeof( * V_269 ) ) ;
V_383 -> V_645 = V_646 ;
V_383 -> V_113 = V_113 ;
V_383 -> V_647 = V_648 ;
V_383 -> V_385 = F_124 ( V_30 -> V_182 ) ;
memset ( V_383 -> V_649 , 0 , sizeof( V_383 -> V_649 ) ) ;
V_383 -> V_331 = F_119 ( V_9 -> V_133 << V_541 ) ;
V_383 -> V_650 = F_119 ( F_116 ( V_642 -> V_540 ) ) ;
V_383 -> V_651 = F_119 ( V_9 -> V_122 +
F_232 ( struct V_139 , V_272 ) ) ;
V_383 -> V_643 = F_124 ( sizeof( V_269 -> V_272 ) ) ;
}
static int F_267 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_113 )
{
int V_21 = V_364 ;
struct V_267 * V_621 ;
struct V_75 * V_30 ;
unsigned char V_652 [ 8 ] ;
unsigned char * V_653 = & V_652 [ 0 ] ;
V_621 = abort -> V_10 ;
V_30 = (struct V_75 * ) ( V_621 -> V_42 -> V_79 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_167 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_168 ,
V_22 -> V_59 -> V_101 , V_30 -> V_102 , V_30 -> V_103 , V_30 -> V_104 ,
L_169 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_88 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_170 ) ;
return - 1 ;
}
if ( ! F_203 ( V_22 , abort , V_653 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_171 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_172 ,
V_653 [ 0 ] , V_653 [ 1 ] , V_653 [ 2 ] , V_653 [ 3 ] ,
V_653 [ 4 ] , V_653 [ 5 ] , V_653 [ 6 ] , V_653 [ 7 ] ) ;
V_21 = F_168 ( V_22 , V_30 , V_653 , V_654 , V_113 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_173 ,
V_653 [ 0 ] , V_653 [ 1 ] , V_653 [ 2 ] , V_653 [ 3 ] ,
V_653 [ 4 ] , V_653 [ 5 ] , V_653 [ 6 ] , V_653 [ 7 ] ) ;
return V_21 ;
}
if ( F_258 ( V_22 , V_653 , V_113 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_174 ,
V_653 [ 0 ] , V_653 [ 1 ] , V_653 [ 2 ] , V_653 [ 3 ] ,
V_653 [ 4 ] , V_653 [ 5 ] , V_653 [ 6 ] , V_653 [ 7 ] ) ;
return - 1 ;
}
F_92 ( & V_22 -> V_29 -> V_30 ,
L_175 ,
V_653 [ 0 ] , V_653 [ 1 ] , V_653 [ 2 ] , V_653 [ 3 ] ,
V_653 [ 4 ] , V_653 [ 5 ] , V_653 [ 6 ] , V_653 [ 7 ] ) ;
return V_21 ;
}
static int F_268 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_364 ;
struct V_8 * V_9 ;
V_448 V_637 , V_638 ;
struct V_75 * V_30 ;
struct V_139 * V_269 ;
V_30 = abort -> V_10 -> V_42 -> V_79 ;
if ( ! V_30 -> V_88 && ! V_30 -> V_183 )
return - 1 ;
V_9 = F_162 ( V_22 ) ;
F_265 ( V_9 , V_22 , abort , V_113 ) ;
V_269 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
( void ) F_153 ( V_22 , V_9 , V_113 , V_363 ) ;
F_262 ( V_22 , abort , & V_637 , & V_638 ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_176 ,
V_199 , V_638 , V_637 ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_177 ,
V_199 , V_638 , V_637 , V_269 -> V_272 . V_273 ) ;
switch ( V_269 -> V_272 . V_273 ) {
case V_299 :
case V_300 :
V_21 = 0 ;
break;
case V_301 :
case V_288 :
case V_302 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_178 ,
V_199 , V_638 , V_637 ,
V_269 -> V_272 . V_273 ) ;
V_21 = - 1 ;
}
F_164 ( V_22 , V_9 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_166 , V_199 ,
V_638 , V_637 ) ;
return V_21 ;
}
static int F_269 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_113 )
{
if ( abort -> V_150 == V_154 ) {
if ( V_655 & V_22 -> V_656 )
return F_268 ( V_22 , abort ,
V_113 ) ;
else
return F_267 ( V_22 , V_72 ,
abort , V_113 ) ;
}
return F_263 ( V_22 , V_72 , abort , V_113 ) ;
}
static int F_270 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_150 == V_154 )
return V_22 -> V_137 [ V_9 -> V_133 ] . V_113 ;
return V_9 -> V_124 . V_128 ;
}
static inline int F_271 ( struct V_1 * V_22 )
{
#define F_272 5000
return ! F_273 ( V_22 -> V_657 ,
F_274 ( & V_22 -> V_658 ) >= 0 ,
F_152 ( F_272 ) ) ;
}
static int F_275 ( struct V_267 * V_659 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_75 * V_30 ;
struct V_8 * abort ;
struct V_267 * V_660 ;
char V_632 [ 256 ] ;
int V_661 = 0 ;
V_448 V_638 , V_637 ;
int V_389 , V_113 ;
if ( V_659 == NULL )
return V_633 ;
if ( V_659 -> V_42 == NULL )
return V_633 ;
V_22 = F_1 ( V_659 -> V_42 ) ;
if ( V_22 == NULL )
return V_633 ;
V_30 = V_659 -> V_42 -> V_79 ;
if ( ! V_30 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_179 ,
V_632 ) ;
return V_633 ;
}
if ( F_13 ( V_22 ) ) {
F_68 ( V_238 , V_22 , V_30 ,
L_180 ) ;
return V_633 ;
}
if ( F_260 ( V_22 ) ) {
F_68 ( V_238 , V_22 , V_30 ,
L_181 ) ;
return V_633 ;
}
if ( ! ( V_662 & V_22 -> V_656 ) &&
! ( V_663 & V_22 -> V_656 ) )
return V_633 ;
memset ( V_632 , 0 , sizeof( V_632 ) ) ;
V_661 += sprintf ( V_632 + V_661 , L_182 ,
V_22 -> V_59 -> V_101 , V_659 -> V_42 -> V_664 ,
V_659 -> V_42 -> V_665 , V_659 -> V_42 -> V_104 ,
L_183 , V_659 ) ;
abort = (struct V_8 * ) V_659 -> V_577 ;
if ( abort == NULL ) {
return V_634 ;
}
V_389 = F_170 ( & abort -> V_389 ) ;
if ( V_389 == 1 ) {
F_164 ( V_22 , abort ) ;
return V_634 ;
}
if ( abort -> V_150 != V_154 &&
abort -> V_150 != V_151 && ! V_30 -> V_445 ) {
F_164 ( V_22 , abort ) ;
return V_633 ;
}
if ( abort -> V_10 != V_659 ) {
F_164 ( V_22 , abort ) ;
return V_634 ;
}
abort -> V_12 = true ;
F_262 ( V_22 , abort , & V_637 , & V_638 ) ;
V_113 = F_270 ( V_22 , abort ) ;
V_661 += sprintf ( V_632 + V_661 , L_184 , V_638 , V_637 ) ;
V_660 = abort -> V_10 ;
if ( V_660 != NULL )
V_661 += sprintf ( V_632 + V_661 ,
L_185 ,
V_660 -> V_510 , V_660 -> V_523 [ 0 ] , V_660 -> V_523 [ 1 ] ,
V_660 -> V_666 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_186 , V_632 ) ;
F_68 ( V_238 , V_22 , V_30 , L_183 ) ;
if ( F_271 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_632 ) ;
F_164 ( V_22 , abort ) ;
return V_633 ;
}
V_21 = F_269 ( V_22 , V_30 -> V_72 , abort , V_113 ) ;
F_54 ( & V_22 -> V_658 ) ;
F_131 ( & V_22 -> V_657 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_188 , V_632 ) ;
F_68 ( V_238 , V_22 , V_30 ,
L_189 ) ;
F_164 ( V_22 , abort ) ;
return V_633 ;
}
F_92 ( & V_22 -> V_29 -> V_30 , L_190 , V_632 ) ;
F_171 ( V_22 -> V_305 ,
abort -> V_10 != V_659 || F_13 ( V_22 ) ) ;
F_164 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_634 : V_633 ;
}
static struct V_8 * F_244 ( struct V_1 * V_22 ,
struct V_267 * V_621 )
{
int V_622 = F_255 ( V_621 ) ;
struct V_8 * V_9 = V_22 -> V_388 + V_622 ;
if ( V_622 < V_612 || V_622 >= V_22 -> V_232 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_191 ,
V_622 , V_612 , V_22 -> V_232 - 1 ) ;
F_167 () ;
}
F_54 ( & V_9 -> V_389 ) ;
if ( F_43 ( ! F_4 ( V_9 ) ) ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_622 ) ;
if ( V_9 -> V_10 != NULL )
F_276 ( V_9 -> V_10 ) ;
F_276 ( V_621 ) ;
}
F_240 ( V_22 , V_622 , V_9 ) ;
return V_9 ;
}
static void F_133 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_44 ( & V_9 -> V_389 ) ;
}
static struct V_8 * F_162 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_389 , V_68 ;
int V_667 = 0 ;
for (; ; ) {
V_68 = F_277 ( V_22 -> V_668 ,
V_612 ,
V_667 ) ;
if ( F_43 ( V_68 >= V_612 ) ) {
V_667 = 0 ;
continue;
}
V_9 = V_22 -> V_388 + V_68 ;
V_389 = F_170 ( & V_9 -> V_389 ) ;
if ( F_43 ( V_389 > 1 ) ) {
F_164 ( V_22 , V_9 ) ;
V_667 = ( V_68 + 1 ) % V_612 ;
continue;
}
F_202 ( V_68 & ( V_570 - 1 ) ,
V_22 -> V_668 + ( V_68 / V_570 ) ) ;
break;
}
F_240 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_164 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_56 ( & V_9 -> V_389 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_388 ;
F_278 ( V_68 & ( V_570 - 1 ) ,
V_22 -> V_668 + ( V_68 / V_570 ) ) ;
}
}
static int F_279 ( struct V_2 * V_30 , int V_268 ,
void T_7 * V_669 )
{
T_8 T_7 * V_670 =
( T_8 T_7 * ) V_669 ;
T_9 V_671 ;
T_9 T_7 * V_672 = F_280 ( sizeof( V_671 ) ) ;
int V_673 ;
T_4 V_131 ;
memset ( & V_671 , 0 , sizeof( V_671 ) ) ;
V_673 = 0 ;
V_673 |= F_281 ( & V_671 . V_674 , & V_670 -> V_674 ,
sizeof( V_671 . V_674 ) ) ;
V_673 |= F_281 ( & V_671 . V_144 , & V_670 -> V_144 ,
sizeof( V_671 . V_144 ) ) ;
V_673 |= F_281 ( & V_671 . V_675 , & V_670 -> V_675 ,
sizeof( V_671 . V_675 ) ) ;
V_673 |= F_282 ( V_671 . V_676 , & V_670 -> V_676 ) ;
V_673 |= F_282 ( V_131 , & V_670 -> V_45 ) ;
V_671 . V_45 = F_283 ( V_131 ) ;
V_673 |= F_284 ( V_672 , & V_671 , sizeof( V_671 ) ) ;
if ( V_673 )
return - V_677 ;
V_673 = F_285 ( V_30 , V_678 , V_672 ) ;
if ( V_673 )
return V_673 ;
V_673 |= F_286 ( & V_670 -> V_675 , & V_672 -> V_675 ,
sizeof( V_670 -> V_675 ) ) ;
if ( V_673 )
return - V_677 ;
return V_673 ;
}
static int F_287 ( struct V_2 * V_30 ,
int V_268 , void T_7 * V_669 )
{
T_10 T_7 * V_670 =
( T_10 T_7 * ) V_669 ;
T_11 V_671 ;
T_11 T_7 * V_672 =
F_280 ( sizeof( V_671 ) ) ;
int V_673 ;
T_4 V_131 ;
memset ( & V_671 , 0 , sizeof( V_671 ) ) ;
V_673 = 0 ;
V_673 |= F_281 ( & V_671 . V_674 , & V_670 -> V_674 ,
sizeof( V_671 . V_674 ) ) ;
V_673 |= F_281 ( & V_671 . V_144 , & V_670 -> V_144 ,
sizeof( V_671 . V_144 ) ) ;
V_673 |= F_281 ( & V_671 . V_675 , & V_670 -> V_675 ,
sizeof( V_671 . V_675 ) ) ;
V_673 |= F_282 ( V_671 . V_676 , & V_670 -> V_676 ) ;
V_673 |= F_282 ( V_671 . V_679 , & V_670 -> V_679 ) ;
V_673 |= F_282 ( V_131 , & V_670 -> V_45 ) ;
V_671 . V_45 = F_283 ( V_131 ) ;
V_673 |= F_284 ( V_672 , & V_671 , sizeof( V_671 ) ) ;
if ( V_673 )
return - V_677 ;
V_673 = F_285 ( V_30 , V_680 , V_672 ) ;
if ( V_673 )
return V_673 ;
V_673 |= F_286 ( & V_670 -> V_675 , & V_672 -> V_675 ,
sizeof( V_670 -> V_675 ) ) ;
if ( V_673 )
return - V_677 ;
return V_673 ;
}
static int F_288 ( struct V_2 * V_30 , int V_268 , void T_7 * V_669 )
{
switch ( V_268 ) {
case V_681 :
case V_682 :
case V_683 :
case V_684 :
case V_685 :
case V_686 :
case V_687 :
case V_688 :
case V_689 :
case V_690 :
case V_691 :
case V_692 :
case V_693 :
case V_694 :
case V_695 :
return F_285 ( V_30 , V_268 , V_669 ) ;
case V_696 :
return F_279 ( V_30 , V_268 , V_669 ) ;
case V_697 :
return F_287 ( V_30 , V_268 , V_669 ) ;
default:
return - V_698 ;
}
}
static int F_289 ( struct V_1 * V_22 , void T_7 * V_699 )
{
struct V_700 V_701 ;
if ( ! V_699 )
return - V_55 ;
V_701 . V_702 = F_290 ( V_22 -> V_29 -> V_102 ) ;
V_701 . V_102 = V_22 -> V_29 -> V_102 -> V_703 ;
V_701 . V_704 = V_22 -> V_29 -> V_705 ;
V_701 . V_67 = V_22 -> V_67 ;
if ( F_284 ( V_699 , & V_701 , sizeof( V_701 ) ) )
return - V_677 ;
return 0 ;
}
static int F_291 ( struct V_1 * V_22 , void T_7 * V_699 )
{
T_12 V_706 ;
unsigned char V_707 , V_708 , V_709 ;
int V_21 ;
V_21 = sscanf ( V_710 , L_193 ,
& V_707 , & V_708 , & V_709 ) ;
if ( V_21 != 3 ) {
F_92 ( & V_22 -> V_29 -> V_30 , L_194
L_195 , V_710 ) ;
V_707 = 0 ;
V_708 = 0 ;
V_709 = 0 ;
}
V_706 = ( V_707 << 16 ) | ( V_708 << 8 ) | V_709 ;
if ( ! V_699 )
return - V_55 ;
if ( F_284 ( V_699 , & V_706 , sizeof( T_12 ) ) )
return - V_677 ;
return 0 ;
}
static int F_292 ( struct V_1 * V_22 , void T_7 * V_699 )
{
T_9 V_711 ;
struct V_8 * V_9 ;
char * V_712 = NULL ;
T_5 V_251 ;
int V_21 = 0 ;
if ( ! V_699 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_713 ;
if ( F_281 ( & V_711 , V_699 , sizeof( V_711 ) ) )
return - V_677 ;
if ( ( V_711 . V_676 < 1 ) &&
( V_711 . V_144 . Type . V_714 != V_583 ) ) {
return - V_55 ;
}
if ( V_711 . V_676 > 0 ) {
V_712 = F_89 ( V_711 . V_676 , V_198 ) ;
if ( V_712 == NULL )
return - V_245 ;
if ( V_711 . V_144 . Type . V_714 & V_581 ) {
if ( F_281 ( V_712 , V_711 . V_45 ,
V_711 . V_676 ) ) {
V_21 = - V_677 ;
goto V_715;
}
} else {
memset ( V_712 , 0 , V_711 . V_676 ) ;
}
}
V_9 = F_162 ( V_22 ) ;
V_9 -> V_150 = V_384 ;
V_9 -> V_10 = V_644 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_711 . V_676 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_264 = F_145 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_264 = F_145 ( 0 ) ;
}
memcpy ( & V_9 -> V_124 . V_332 , & V_711 . V_674 , sizeof( V_9 -> V_124 . V_332 ) ) ;
memcpy ( & V_9 -> V_144 , & V_711 . V_144 ,
sizeof( V_9 -> V_144 ) ) ;
if ( V_711 . V_676 > 0 ) {
V_251 = F_117 ( V_22 -> V_29 , V_712 ,
V_711 . V_676 , V_716 ) ;
if ( F_118 ( & V_22 -> V_29 -> V_30 , ( V_355 ) V_251 ) ) {
V_9 -> V_260 [ 0 ] . V_266 = F_119 ( 0 ) ;
V_9 -> V_260 [ 0 ] . V_265 = F_124 ( 0 ) ;
V_21 = - V_245 ;
goto V_377;
}
V_9 -> V_260 [ 0 ] . V_266 = F_119 ( V_251 ) ;
V_9 -> V_260 [ 0 ] . V_265 = F_124 ( V_711 . V_676 ) ;
V_9 -> V_260 [ 0 ] . V_262 = F_124 ( V_359 ) ;
}
V_21 = F_153 ( V_22 , V_9 , V_127 , V_363 ) ;
if ( V_711 . V_676 > 0 )
F_146 ( V_22 -> V_29 , V_9 , 1 , V_716 ) ;
F_293 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_370 ;
goto V_377;
}
memcpy ( & V_711 . V_675 , V_9 -> V_24 ,
sizeof( V_711 . V_675 ) ) ;
if ( F_284 ( V_699 , & V_711 , sizeof( V_711 ) ) ) {
V_21 = - V_677 ;
goto V_377;
}
if ( ( V_711 . V_144 . Type . V_714 & V_582 ) &&
V_711 . V_676 > 0 ) {
if ( F_284 ( V_711 . V_45 , V_712 , V_711 . V_676 ) ) {
V_21 = - V_677 ;
goto V_377;
}
}
V_377:
F_164 ( V_22 , V_9 ) ;
V_715:
F_78 ( V_712 ) ;
return V_21 ;
}
static int F_294 ( struct V_1 * V_22 , void T_7 * V_699 )
{
T_11 * V_717 ;
struct V_8 * V_9 ;
unsigned char * * V_712 = NULL ;
int * V_718 = NULL ;
T_5 V_251 ;
T_13 V_353 = 0 ;
int V_49 = 0 ;
T_4 V_719 ;
T_4 V_720 ;
T_13 T_7 * V_721 ;
if ( ! V_699 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_713 ;
V_717 = ( T_11 * )
F_89 ( sizeof( * V_717 ) , V_198 ) ;
if ( ! V_717 ) {
V_49 = - V_245 ;
goto V_722;
}
if ( F_281 ( V_717 , V_699 , sizeof( * V_717 ) ) ) {
V_49 = - V_677 ;
goto V_722;
}
if ( ( V_717 -> V_676 < 1 ) &&
( V_717 -> V_144 . Type . V_714 != V_583 ) ) {
V_49 = - V_55 ;
goto V_722;
}
if ( V_717 -> V_679 > V_723 ) {
V_49 = - V_55 ;
goto V_722;
}
if ( V_717 -> V_676 > V_717 -> V_679 * V_724 ) {
V_49 = - V_55 ;
goto V_722;
}
V_712 = F_98 ( V_724 * sizeof( char * ) , V_198 ) ;
if ( ! V_712 ) {
V_49 = - V_245 ;
goto V_722;
}
V_718 = F_89 ( V_724 * sizeof( int ) , V_198 ) ;
if ( ! V_718 ) {
V_49 = - V_245 ;
goto V_722;
}
V_719 = V_717 -> V_676 ;
V_721 = V_717 -> V_45 ;
while ( V_719 ) {
V_720 = ( V_719 > V_717 -> V_679 ) ? V_717 -> V_679 : V_719 ;
V_718 [ V_353 ] = V_720 ;
V_712 [ V_353 ] = F_89 ( V_720 , V_198 ) ;
if ( V_712 [ V_353 ] == NULL ) {
V_49 = - V_245 ;
goto V_722;
}
if ( V_717 -> V_144 . Type . V_714 & V_581 ) {
if ( F_281 ( V_712 [ V_353 ] , V_721 , V_720 ) ) {
V_49 = - V_677 ;
goto V_722;
}
} else
memset ( V_712 [ V_353 ] , 0 , V_720 ) ;
V_719 -= V_720 ;
V_721 += V_720 ;
V_353 ++ ;
}
V_9 = F_162 ( V_22 ) ;
V_9 -> V_150 = V_384 ;
V_9 -> V_10 = V_644 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = ( T_1 ) V_353 ;
V_9 -> V_124 . V_264 = F_145 ( V_353 ) ;
memcpy ( & V_9 -> V_124 . V_332 , & V_717 -> V_674 , sizeof( V_9 -> V_124 . V_332 ) ) ;
memcpy ( & V_9 -> V_144 , & V_717 -> V_144 , sizeof( V_9 -> V_144 ) ) ;
if ( V_717 -> V_676 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_353 ; V_68 ++ ) {
V_251 = F_117 ( V_22 -> V_29 , V_712 [ V_68 ] ,
V_718 [ V_68 ] , V_716 ) ;
if ( F_118 ( & V_22 -> V_29 -> V_30 ,
( V_355 ) V_251 ) ) {
V_9 -> V_260 [ V_68 ] . V_266 = F_119 ( 0 ) ;
V_9 -> V_260 [ V_68 ] . V_265 = F_124 ( 0 ) ;
F_146 ( V_22 -> V_29 , V_9 , V_68 ,
V_716 ) ;
V_49 = - V_245 ;
goto V_725;
}
V_9 -> V_260 [ V_68 ] . V_266 = F_119 ( V_251 ) ;
V_9 -> V_260 [ V_68 ] . V_265 = F_124 ( V_718 [ V_68 ] ) ;
V_9 -> V_260 [ V_68 ] . V_262 = F_124 ( 0 ) ;
}
V_9 -> V_260 [ -- V_68 ] . V_262 = F_124 ( V_359 ) ;
}
V_49 = F_153 ( V_22 , V_9 , V_127 , V_363 ) ;
if ( V_353 )
F_146 ( V_22 -> V_29 , V_9 , V_353 , V_716 ) ;
F_293 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_370 ;
goto V_725;
}
memcpy ( & V_717 -> V_675 , V_9 -> V_24 , sizeof( V_717 -> V_675 ) ) ;
if ( F_284 ( V_699 , V_717 , sizeof( * V_717 ) ) ) {
V_49 = - V_677 ;
goto V_725;
}
if ( ( V_717 -> V_144 . Type . V_714 & V_582 ) && V_717 -> V_676 > 0 ) {
int V_68 ;
T_13 T_7 * V_726 = V_717 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_353 ; V_68 ++ ) {
if ( F_284 ( V_726 , V_712 [ V_68 ] , V_718 [ V_68 ] ) ) {
V_49 = - V_677 ;
goto V_725;
}
V_726 += V_718 [ V_68 ] ;
}
}
V_49 = 0 ;
V_725:
F_164 ( V_22 , V_9 ) ;
V_722:
if ( V_712 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_353 ; V_68 ++ )
F_78 ( V_712 [ V_68 ] ) ;
F_78 ( V_712 ) ;
}
F_78 ( V_718 ) ;
F_78 ( V_717 ) ;
return V_49 ;
}
static void F_293 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_278 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_285 ( struct V_2 * V_30 , int V_268 , void T_7 * V_669 )
{
struct V_1 * V_22 ;
void T_7 * V_699 = ( void T_7 * ) V_669 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_268 ) {
case V_691 :
case V_692 :
case V_693 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_681 :
return F_289 ( V_22 , V_699 ) ;
case V_689 :
return F_291 ( V_22 , V_699 ) ;
case V_678 :
if ( F_274 ( & V_22 -> V_727 ) < 0 )
return - V_728 ;
V_21 = F_292 ( V_22 , V_699 ) ;
F_54 ( & V_22 -> V_727 ) ;
return V_21 ;
case V_680 :
if ( F_274 ( & V_22 -> V_727 ) < 0 )
return - V_728 ;
V_21 = F_294 ( V_22 , V_699 ) ;
F_54 ( & V_22 -> V_727 ) ;
return V_21 ;
default:
return - V_729 ;
}
}
static void F_295 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_379 )
{
struct V_8 * V_9 ;
V_9 = F_162 ( V_22 ) ;
( void ) F_163 ( V_9 , V_380 , V_22 , NULL , 0 , 0 ,
V_158 , V_381 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_379 ;
V_9 -> V_362 = NULL ;
F_59 ( V_22 , V_9 ) ;
return;
}
static int F_163 ( struct V_8 * V_9 , T_1 V_268 , struct V_1 * V_22 ,
void * V_712 , T_3 V_428 , T_6 V_730 , unsigned char * V_72 ,
int V_150 )
{
int V_731 = V_583 ;
T_5 V_331 ;
V_9 -> V_150 = V_384 ;
V_9 -> V_10 = V_644 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_712 != NULL && V_428 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_264 = F_145 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_264 = F_145 ( 0 ) ;
}
memcpy ( V_9 -> V_124 . V_332 . V_333 , V_72 , 8 ) ;
if ( V_150 == V_376 ) {
switch ( V_268 ) {
case V_375 :
if ( V_730 & V_390 ) {
V_9 -> V_144 . V_145 [ 1 ] = 0x01 ;
V_9 -> V_144 . V_145 [ 2 ] = ( V_730 & 0xff ) ;
}
V_9 -> V_144 . V_328 = 6 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_582 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_375 ;
V_9 -> V_144 . V_145 [ 4 ] = V_428 & 0xFF ;
break;
case V_421 :
case V_422 :
V_9 -> V_144 . V_328 = 12 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_582 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_268 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_428 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_428 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_428 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_428 & 0xFF ;
break;
case V_732 :
V_9 -> V_144 . V_328 = 12 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 ,
V_580 , V_581 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_733 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_428 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = V_428 & 0xFF ;
break;
case V_435 :
V_9 -> V_144 . V_328 = 6 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_583 ) ;
V_9 -> V_144 . V_578 = 0 ;
break;
case V_408 :
V_9 -> V_144 . V_328 = 12 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_582 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_734 ;
V_9 -> V_144 . V_145 [ 1 ] = V_268 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_428 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_428 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_428 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_428 & 0xFF ;
break;
case V_735 :
V_9 -> V_144 . V_328 = 10 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_582 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_736 ;
V_9 -> V_144 . V_145 [ 6 ] = V_735 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_428 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_428 >> 8 ) & 0xFF ;
break;
case V_411 :
V_9 -> V_144 . V_328 = 10 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_582 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_736 ;
V_9 -> V_144 . V_145 [ 6 ] = V_411 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_428 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_428 >> 8 ) & 0XFF ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_196 , V_268 ) ;
F_167 () ;
return - 1 ;
}
} else if ( V_150 == V_381 ) {
switch ( V_268 ) {
case V_380 :
V_9 -> V_144 . V_328 = 16 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 , V_580 , V_583 ) ;
V_9 -> V_144 . V_578 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_268 ;
V_9 -> V_144 . V_145 [ 1 ] = V_635 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_437 :
memcpy ( & V_331 , V_712 , sizeof( V_331 ) ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_197 ,
V_331 , V_9 -> V_124 . V_331 ) ;
V_9 -> V_144 . V_328 = 16 ;
V_9 -> V_144 . V_579 =
F_237 ( V_150 ,
V_580 , V_581 ) ;
V_9 -> V_144 . V_578 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_737 ;
V_9 -> V_144 . V_145 [ 1 ] = V_738 ;
V_9 -> V_144 . V_145 [ 2 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_144 . V_145 [ 4 ] , & V_331 , sizeof( V_331 ) ) ;
V_9 -> V_144 . V_145 [ 12 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 13 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 14 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_198 ,
V_268 ) ;
F_167 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_199 , V_150 ) ;
F_167 () ;
}
switch ( F_296 ( V_9 -> V_144 . V_579 ) ) {
case V_582 :
V_731 = V_378 ;
break;
case V_581 :
V_731 = V_254 ;
break;
case V_583 :
V_731 = V_358 ;
break;
default:
V_731 = V_716 ;
}
if ( F_147 ( V_22 -> V_29 , V_9 , V_712 , V_428 , V_731 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_297 ( T_15 V_739 , T_15 V_428 )
{
T_15 V_740 = ( ( T_15 ) V_739 ) & V_741 ;
T_15 V_742 = ( ( T_15 ) V_739 ) - V_740 ;
void T_14 * V_743 = F_298 ( V_740 ,
V_742 + V_428 ) ;
return V_743 ? ( V_743 + V_742 ) : NULL ;
}
static inline unsigned long F_299 ( struct V_1 * V_22 , T_1 V_110 )
{
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
}
static inline bool F_300 ( struct V_1 * V_22 )
{
return V_22 -> V_115 . V_744 ( V_22 ) ;
}
static inline long F_301 ( struct V_1 * V_22 )
{
return ( V_22 -> V_115 . V_744 ( V_22 ) == 0 ) ||
( V_22 -> V_745 == 0 ) ;
}
static inline int F_302 ( struct V_1 * V_22 , T_4 V_746 ,
T_4 V_747 )
{
if ( F_43 ( V_746 >= V_22 -> V_232 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_200 , V_747 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_60 ( struct V_8 * V_9 )
{
F_55 ( V_9 -> V_22 , V_9 ) ;
if ( F_46 ( V_9 -> V_150 == V_151 || V_9 -> V_150 == V_322
|| V_9 -> V_150 == V_154 ) )
F_142 ( V_9 ) ;
else if ( V_9 -> V_150 == V_384 || V_9 -> V_150 == V_156 )
F_303 ( V_9 -> V_362 ) ;
}
static inline T_4 F_304 ( struct V_1 * V_22 , T_4 V_331 )
{
#define F_305 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_306 0x03
if ( F_43 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_331 & ~ F_306 ;
return V_331 & ~ F_305 ;
}
static inline void F_307 ( struct V_1 * V_22 ,
T_4 V_747 )
{
T_4 V_746 ;
struct V_8 * V_9 ;
V_746 = V_747 >> V_541 ;
if ( ! F_302 ( V_22 , V_746 , V_747 ) ) {
V_9 = V_22 -> V_388 + V_746 ;
F_60 ( V_9 ) ;
}
}
static int F_308 ( struct V_1 * V_22 )
{
if ( F_46 ( ! V_748 ) )
return 0 ;
if ( F_46 ( V_22 -> V_745 ) )
return 0 ;
F_92 ( & V_22 -> V_29 -> V_30 , L_201
L_202 ) ;
return 1 ;
}
static struct V_1 * F_309 ( T_1 * V_749 )
{
return F_242 ( ( V_749 - * V_749 ) , struct V_1 , V_110 [ 0 ] ) ;
}
static T_16 F_310 ( int V_615 , void * V_749 )
{
struct V_1 * V_22 = F_309 ( V_749 ) ;
T_1 V_110 = * ( T_1 * ) V_749 ;
T_4 V_747 ;
if ( F_308 ( V_22 ) )
return V_750 ;
if ( F_301 ( V_22 ) )
return V_750 ;
V_22 -> V_751 = F_311 () ;
while ( F_300 ( V_22 ) ) {
V_747 = F_299 ( V_22 , V_110 ) ;
while ( V_747 != V_120 )
V_747 = F_42 ( V_22 , V_110 ) ;
}
return V_752 ;
}
static T_16 F_312 ( int V_615 , void * V_749 )
{
struct V_1 * V_22 = F_309 ( V_749 ) ;
T_4 V_747 ;
T_1 V_110 = * ( T_1 * ) V_749 ;
if ( F_308 ( V_22 ) )
return V_750 ;
V_22 -> V_751 = F_311 () ;
V_747 = F_299 ( V_22 , V_110 ) ;
while ( V_747 != V_120 )
V_747 = F_42 ( V_22 , V_110 ) ;
return V_752 ;
}
static T_16 F_313 ( int V_615 , void * V_749 )
{
struct V_1 * V_22 = F_309 ( ( T_1 * ) V_749 ) ;
T_4 V_747 ;
T_1 V_110 = * ( T_1 * ) V_749 ;
if ( F_301 ( V_22 ) )
return V_750 ;
V_22 -> V_751 = F_311 () ;
while ( F_300 ( V_22 ) ) {
V_747 = F_299 ( V_22 , V_110 ) ;
while ( V_747 != V_120 ) {
F_307 ( V_22 , V_747 ) ;
V_747 = F_42 ( V_22 , V_110 ) ;
}
}
return V_752 ;
}
static T_16 F_314 ( int V_615 , void * V_749 )
{
struct V_1 * V_22 = F_309 ( V_749 ) ;
T_4 V_747 ;
T_1 V_110 = * ( T_1 * ) V_749 ;
V_22 -> V_751 = F_311 () ;
V_747 = F_299 ( V_22 , V_110 ) ;
while ( V_747 != V_120 ) {
F_307 ( V_22 , V_747 ) ;
V_747 = F_42 ( V_22 , V_110 ) ;
}
return V_752 ;
}
static int F_315 ( struct V_352 * V_29 , unsigned char V_753 ,
unsigned char type )
{
struct V_754 {
struct V_755 V_756 ;
struct V_757 V_144 ;
struct V_758 V_759 ;
};
struct V_754 * V_268 ;
static const T_3 V_760 = sizeof( * V_268 ) +
sizeof( V_268 -> V_759 ) ;
V_355 V_761 ;
V_448 V_762 ;
T_4 V_331 ;
void T_14 * V_152 ;
int V_68 , V_673 ;
V_152 = F_316 ( V_29 , 0 ) ;
if ( V_152 == NULL )
return - V_245 ;
V_673 = F_317 ( V_29 , F_318 ( 32 ) ) ;
if ( V_673 ) {
F_319 ( V_152 ) ;
return V_673 ;
}
V_268 = F_320 ( V_29 , V_760 , & V_761 ) ;
if ( V_268 == NULL ) {
F_319 ( V_152 ) ;
return - V_245 ;
}
V_762 = F_124 ( V_761 ) ;
V_268 -> V_756 . V_128 = 0 ;
V_268 -> V_756 . V_125 = 0 ;
V_268 -> V_756 . V_264 = F_145 ( 0 ) ;
V_268 -> V_756 . V_331 = F_119 ( V_761 ) ;
memset ( & V_268 -> V_756 . V_332 . V_333 , 0 , 8 ) ;
V_268 -> V_144 . V_328 = 16 ;
V_268 -> V_144 . V_579 =
F_237 ( V_381 , V_763 , V_583 ) ;
V_268 -> V_144 . V_578 = 0 ;
V_268 -> V_144 . V_145 [ 0 ] = V_753 ;
V_268 -> V_144 . V_145 [ 1 ] = type ;
memset ( & V_268 -> V_144 . V_145 [ 2 ] , 0 , 14 ) ;
V_268 -> V_759 . V_266 =
F_119 ( ( F_116 ( V_762 ) + sizeof( * V_268 ) ) ) ;
V_268 -> V_759 . V_265 = F_124 ( sizeof( struct V_319 ) ) ;
F_58 ( F_116 ( V_762 ) , V_152 + V_153 ) ;
for ( V_68 = 0 ; V_68 < V_764 ; V_68 ++ ) {
V_331 = F_321 ( V_152 + V_765 ) ;
if ( ( V_331 & ~ F_306 ) == V_761 )
break;
F_158 ( V_766 ) ;
}
F_319 ( V_152 ) ;
if ( V_68 == V_764 ) {
F_71 ( & V_29 -> V_30 , L_203 ,
V_753 , type ) ;
return - V_365 ;
}
F_322 ( V_29 , V_760 , V_268 , V_761 ) ;
if ( V_331 & V_767 ) {
F_71 ( & V_29 -> V_30 , L_204 ,
V_753 , type ) ;
return - V_370 ;
}
F_92 ( & V_29 -> V_30 , L_205 ,
V_753 , type ) ;
return 0 ;
}
static int F_323 ( struct V_352 * V_29 ,
void T_14 * V_152 , T_4 V_768 )
{
if ( V_768 ) {
F_92 ( & V_29 -> V_30 , L_206 ) ;
F_58 ( V_768 , V_152 + V_769 ) ;
F_158 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_92 ( & V_29 -> V_30 , L_207 ) ;
V_21 = F_324 ( V_29 , V_770 ) ;
if ( V_21 )
return V_21 ;
F_158 ( 500 ) ;
V_21 = F_324 ( V_29 , V_771 ) ;
if ( V_21 )
return V_21 ;
F_158 ( 500 ) ;
}
return 0 ;
}
static void F_325 ( char * V_772 , int V_50 )
{
memset ( V_772 , 0 , V_50 ) ;
strncpy ( V_772 , V_41 L_208 V_710 , V_50 - 1 ) ;
}
static int F_326 ( struct V_773 T_14 * V_774 )
{
char * V_772 ;
int V_68 , V_428 = sizeof( V_774 -> V_772 ) ;
V_772 = F_89 ( V_428 , V_198 ) ;
if ( ! V_772 )
return - V_245 ;
F_325 ( V_772 , V_428 ) ;
for ( V_68 = 0 ; V_68 < V_428 ; V_68 ++ )
F_327 ( V_772 [ V_68 ] , & V_774 -> V_772 [ V_68 ] ) ;
F_78 ( V_772 ) ;
return 0 ;
}
static void F_328 ( struct V_773 T_14 * V_774 ,
unsigned char * V_775 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_774 -> V_772 ) ; V_68 ++ )
V_775 [ V_68 ] = F_329 ( & V_774 -> V_772 [ V_68 ] ) ;
}
static int F_330 ( struct V_773 T_14 * V_774 )
{
char * V_775 , * V_776 ;
int V_21 , V_428 = sizeof( V_774 -> V_772 ) ;
V_776 = F_89 ( 2 * V_428 , V_198 ) ;
if ( ! V_776 )
return - V_245 ;
V_775 = V_776 + V_428 ;
F_325 ( V_776 , V_428 ) ;
F_328 ( V_774 , V_775 ) ;
V_21 = ! memcmp ( V_775 , V_776 , V_428 ) ;
F_78 ( V_776 ) ;
return V_21 ;
}
static int F_331 ( struct V_352 * V_29 , T_4 V_67 )
{
T_5 V_777 ;
T_4 V_778 ;
T_5 V_779 ;
void T_14 * V_152 ;
unsigned long V_780 ;
T_4 V_781 ;
int V_21 ;
struct V_773 T_14 * V_774 ;
T_4 V_768 ;
T_6 V_782 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_209 ) ;
return - V_80 ;
}
if ( ! F_25 ( V_67 ) )
return - V_783 ;
F_332 ( V_29 , 4 , & V_782 ) ;
F_333 ( V_29 ) ;
V_21 = F_334 ( V_29 , & V_780 ) ;
if ( V_21 )
return V_21 ;
V_152 = F_297 ( V_780 , 0x250 ) ;
if ( ! V_152 )
return - V_245 ;
V_21 = F_335 ( V_29 , V_152 , & V_778 ,
& V_779 , & V_777 ) ;
if ( V_21 )
goto V_784;
V_774 = F_297 ( F_336 ( V_29 ,
V_779 ) + V_777 , sizeof( * V_774 ) ) ;
if ( ! V_774 ) {
V_21 = - V_245 ;
goto V_784;
}
V_21 = F_326 ( V_774 ) ;
if ( V_21 )
goto V_785;
V_781 = F_321 ( & V_774 -> V_781 ) ;
V_768 = V_781 & V_786 ;
if ( V_768 ) {
V_768 = V_787 ;
} else {
V_768 = V_781 & V_788 ;
if ( V_768 ) {
F_9 ( & V_29 -> V_30 ,
L_210 ) ;
V_21 = - V_783 ;
goto V_785;
}
}
V_21 = F_323 ( V_29 , V_152 , V_768 ) ;
if ( V_21 )
goto V_785;
F_337 ( V_29 ) ;
F_338 ( V_29 , 4 , V_782 ) ;
F_158 ( V_789 ) ;
V_21 = F_339 ( V_29 , V_152 , V_790 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_211 ) ;
goto V_785;
}
V_21 = F_330 ( V_152 ) ;
if ( V_21 < 0 )
goto V_785;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_212
L_213 ) ;
V_21 = - V_783 ;
} else {
F_92 ( & V_29 -> V_30 , L_214 ) ;
}
V_785:
F_319 ( V_774 ) ;
V_784:
F_319 ( V_152 ) ;
return V_21 ;
}
static void F_340 ( struct V_42 * V_30 , struct V_773 T_14 * V_791 )
{
#ifdef F_341
int V_68 ;
char V_792 [ 17 ] ;
F_92 ( V_30 , L_215 ) ;
F_92 ( V_30 , L_216 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_792 [ V_68 ] = F_329 ( & ( V_791 -> V_793 [ V_68 ] ) ) ;
V_792 [ 4 ] = '\0' ;
F_92 ( V_30 , L_217 , V_792 ) ;
F_92 ( V_30 , L_218 , F_321 ( & ( V_791 -> V_794 ) ) ) ;
F_92 ( V_30 , L_219 ,
F_321 ( & ( V_791 -> V_795 ) ) ) ;
F_92 ( V_30 , L_220 ,
F_321 ( & ( V_791 -> V_796 ) ) ) ;
F_92 ( V_30 , L_221 ,
F_321 ( & ( V_791 -> V_797 . V_798 ) ) ) ;
F_92 ( V_30 , L_222 ,
F_321 ( & ( V_791 -> V_797 . V_799 ) ) ) ;
F_92 ( V_30 , L_223 ,
F_321 ( & ( V_791 -> V_797 . V_800 ) ) ) ;
F_92 ( V_30 , L_224 ,
F_321 ( & ( V_791 -> V_801 ) ) ) ;
F_92 ( V_30 , L_225 , F_321 ( & ( V_791 -> V_802 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_792 [ V_68 ] = F_329 ( & ( V_791 -> V_803 [ V_68 ] ) ) ;
V_792 [ 16 ] = '\0' ;
F_92 ( V_30 , L_226 , V_792 ) ;
F_92 ( V_30 , L_227 ,
F_321 ( & ( V_791 -> V_804 ) ) ) ;
#endif
}
static int F_342 ( struct V_352 * V_29 , unsigned long V_805 )
{
int V_68 , V_667 , V_806 , V_807 ;
if ( V_805 == V_808 )
return 0 ;
V_667 = 0 ;
for ( V_68 = 0 ; V_68 < V_809 ; V_68 ++ ) {
V_807 = F_343 ( V_29 , V_68 ) & V_810 ;
if ( V_807 == V_811 )
V_667 += 4 ;
else {
V_806 = F_343 ( V_29 , V_68 ) &
V_812 ;
switch ( V_806 ) {
case V_813 :
case V_814 :
V_667 += 4 ;
break;
case V_815 :
V_667 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_228 ) ;
return - 1 ;
break;
}
}
if ( V_667 == V_805 - V_808 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_344 ( struct V_1 * V_22 )
{
if ( V_22 -> V_126 ) {
if ( V_22 -> V_29 -> V_816 )
F_345 ( V_22 -> V_29 ) ;
V_22 -> V_126 = 0 ;
} else if ( V_22 -> V_817 ) {
if ( V_22 -> V_29 -> V_818 )
F_346 ( V_22 -> V_29 ) ;
V_22 -> V_817 = 0 ;
}
}
static void F_347 ( struct V_1 * V_22 )
{
#ifdef F_348
int V_673 , V_68 ;
struct V_819 V_820 [ V_821 ] ;
for ( V_68 = 0 ; V_68 < V_821 ; V_68 ++ ) {
V_820 [ V_68 ] . V_822 = 0 ;
V_820 [ V_68 ] . V_179 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_823;
if ( F_349 ( V_22 -> V_29 , V_824 ) ) {
F_92 ( & V_22 -> V_29 -> V_30 , L_229 ) ;
V_22 -> V_126 = V_821 ;
if ( V_22 -> V_126 > F_350 () )
V_22 -> V_126 = F_350 () ;
V_673 = F_351 ( V_22 -> V_29 , V_820 ,
1 , V_22 -> V_126 ) ;
if ( V_673 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_230 , V_673 ) ;
V_22 -> V_126 = 0 ;
goto V_825;
} else if ( V_673 < V_22 -> V_126 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_231
L_232 , V_673 ) ;
}
V_22 -> V_126 = V_673 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ )
V_22 -> V_616 [ V_68 ] = V_820 [ V_68 ] . V_822 ;
return;
}
V_825:
if ( F_349 ( V_22 -> V_29 , V_826 ) ) {
F_92 ( & V_22 -> V_29 -> V_30 , L_233 ) ;
if ( ! F_352 ( V_22 -> V_29 ) )
V_22 -> V_817 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_234 ) ;
}
V_823:
#endif
V_22 -> V_616 [ V_22 -> V_617 ] = V_22 -> V_29 -> V_615 ;
}
static int F_353 ( struct V_352 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_827 , V_828 ;
V_827 = V_29 -> V_829 ;
V_828 = V_29 -> V_830 ;
* V_67 = ( ( V_828 << 16 ) & 0xffff0000 ) |
V_827 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_831 ) ; V_68 ++ )
if ( * V_67 == V_831 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_827 != V_832 &&
V_827 != V_833 ) ||
! V_834 ) {
F_9 ( & V_29 -> V_30 , L_235
L_236 , * V_67 ) ;
return - V_80 ;
}
return F_26 ( V_831 ) - 1 ;
}
static int F_334 ( struct V_352 * V_29 ,
unsigned long * V_835 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_809 ; V_68 ++ )
if ( F_343 ( V_29 , V_68 ) & V_836 ) {
* V_835 = F_336 ( V_29 , V_68 ) ;
F_264 ( & V_29 -> V_30 , L_237 ,
* V_835 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_238 ) ;
return - V_80 ;
}
static int F_339 ( struct V_352 * V_29 , void T_14 * V_152 ,
int V_837 )
{
int V_68 , V_838 ;
T_4 V_839 ;
if ( V_837 )
V_838 = V_840 ;
else
V_838 = V_841 ;
for ( V_68 = 0 ; V_68 < V_838 ; V_68 ++ ) {
V_839 = F_321 ( V_152 + V_842 ) ;
if ( V_837 ) {
if ( V_839 == V_843 )
return 0 ;
} else {
if ( V_839 != V_843 )
return 0 ;
}
F_158 ( V_844 ) ;
}
F_9 ( & V_29 -> V_30 , L_239 ) ;
return - V_80 ;
}
static int F_335 ( struct V_352 * V_29 , void T_14 * V_152 ,
T_4 * V_778 , T_5 * V_779 ,
T_5 * V_777 )
{
* V_778 = F_321 ( V_152 + V_845 ) ;
* V_777 = F_321 ( V_152 + V_846 ) ;
* V_778 &= ( T_4 ) 0x0000ffff ;
* V_779 = F_342 ( V_29 , * V_778 ) ;
if ( * V_779 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_240 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_354 ( struct V_1 * V_22 )
{
if ( V_22 -> V_847 ) {
F_319 ( V_22 -> V_847 ) ;
V_22 -> V_847 = NULL ;
}
if ( V_22 -> V_774 ) {
F_319 ( V_22 -> V_774 ) ;
V_22 -> V_774 = NULL ;
}
}
static int F_355 ( struct V_1 * V_22 )
{
T_5 V_777 ;
T_4 V_778 ;
T_5 V_779 ;
T_4 V_848 ;
int V_21 ;
V_21 = F_335 ( V_22 -> V_29 , V_22 -> V_152 , & V_778 ,
& V_779 , & V_777 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_774 = F_297 ( F_336 ( V_22 -> V_29 ,
V_779 ) + V_777 , sizeof( * V_22 -> V_774 ) ) ;
if ( ! V_22 -> V_774 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_241 ) ;
return - V_245 ;
}
V_21 = F_326 ( V_22 -> V_774 ) ;
if ( V_21 )
return V_21 ;
V_848 = F_321 ( & V_22 -> V_774 -> V_849 ) ;
V_22 -> V_847 = F_297 ( F_336 ( V_22 -> V_29 ,
V_779 ) + V_777 + V_848 ,
sizeof( * V_22 -> V_847 ) ) ;
if ( ! V_22 -> V_847 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_242 ) ;
F_354 ( V_22 ) ;
return - V_245 ;
}
return 0 ;
}
static void F_356 ( struct V_1 * V_22 )
{
#define F_357 16
F_266 ( F_357 <= V_612 ) ;
V_22 -> V_121 = F_321 ( & V_22 -> V_774 -> V_850 ) ;
if ( V_748 && V_22 -> V_121 > 32 )
V_22 -> V_121 = 32 ;
if ( V_22 -> V_121 < F_357 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_243 ,
V_22 -> V_121 ,
F_357 ) ;
V_22 -> V_121 = F_357 ;
}
}
static int F_358 ( struct V_1 * V_22 )
{
return V_22 -> V_246 > 512 ;
}
static void F_359 ( struct V_1 * V_22 )
{
F_356 ( V_22 ) ;
V_22 -> V_232 = V_22 -> V_121 ;
V_22 -> V_246 = F_321 ( & ( V_22 -> V_774 -> V_851 ) ) ;
V_22 -> V_442 = F_321 ( & ( V_22 -> V_774 -> V_781 ) ) ;
if ( F_358 ( V_22 ) ) {
V_22 -> V_261 = 32 ;
V_22 -> V_244 = V_22 -> V_246 - V_22 -> V_261 ;
V_22 -> V_246 -- ;
} else {
V_22 -> V_261 = 31 ;
V_22 -> V_246 = 31 ;
V_22 -> V_244 = 0 ;
}
V_22 -> V_656 = F_321 ( & ( V_22 -> V_774 -> V_656 ) ) ;
if ( ! ( V_662 & V_22 -> V_656 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_244 ) ;
if ( ! ( V_663 & V_22 -> V_656 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_245 ) ;
if ( ! ( V_655 & V_22 -> V_656 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_246 ) ;
}
static inline bool F_360 ( struct V_1 * V_22 )
{
if ( ! F_361 ( V_22 -> V_774 -> V_793 , L_247 , 4 ) ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_248 ) ;
return false ;
}
return true ;
}
static inline void F_362 ( struct V_1 * V_22 )
{
T_4 V_852 ;
V_852 = F_321 ( & ( V_22 -> V_774 -> V_852 ) ) ;
#ifdef F_363
V_852 |= V_853 ;
#endif
V_852 |= V_854 ;
F_58 ( V_852 , & ( V_22 -> V_774 -> V_852 ) ) ;
}
static inline void F_364 ( struct V_1 * V_22 )
{
T_4 V_855 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_855 = F_321 ( V_22 -> V_152 + V_856 ) ;
V_855 |= 0x8000 ;
F_58 ( V_855 , V_22 -> V_152 + V_856 ) ;
}
static int F_365 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_857 ;
unsigned long V_77 ;
for ( V_68 = 0 ; V_68 < V_858 ; V_68 ++ ) {
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_857 = F_321 ( V_22 -> V_152 + V_769 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( ! ( V_857 & V_859 ) )
goto V_860;
F_158 ( V_861 ) ;
}
return - V_80 ;
V_860:
return 0 ;
}
static int F_366 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_857 ;
unsigned long V_77 ;
for ( V_68 = 0 ; V_68 < V_862 ; V_68 ++ ) {
if ( V_22 -> V_863 )
goto V_860;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_857 = F_321 ( V_22 -> V_152 + V_769 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( ! ( V_857 & V_864 ) )
goto V_860;
F_158 ( V_865 ) ;
}
return - V_80 ;
V_860:
return 0 ;
}
static int F_367 ( struct V_1 * V_22 )
{
T_4 V_866 ;
V_866 = F_321 ( & ( V_22 -> V_774 -> V_795 ) ) ;
if ( ! ( V_866 & V_867 ) )
return - V_783 ;
V_22 -> V_121 = F_321 ( & ( V_22 -> V_774 -> V_801 ) ) ;
F_58 ( V_868 , & ( V_22 -> V_774 -> V_797 . V_798 ) ) ;
F_58 ( 0 , & V_22 -> V_774 -> V_797 . V_869 ) ;
F_58 ( V_864 , V_22 -> V_152 + V_769 ) ;
if ( F_366 ( V_22 ) )
goto error;
F_340 ( & V_22 -> V_29 -> V_30 , V_22 -> V_774 ) ;
if ( ! ( F_321 ( & ( V_22 -> V_774 -> V_796 ) ) & V_868 ) )
goto error;
V_22 -> V_63 = V_868 ;
return 0 ;
error:
F_71 ( & V_22 -> V_29 -> V_30 , L_249 ) ;
return - V_80 ;
}
static void F_368 ( struct V_1 * V_22 )
{
F_354 ( V_22 ) ;
F_319 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
F_344 ( V_22 ) ;
F_369 ( V_22 -> V_29 ) ;
F_370 ( V_22 -> V_29 ) ;
}
static int F_371 ( struct V_1 * V_22 )
{
int V_870 , V_673 ;
V_870 = F_353 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_870 < 0 )
return V_870 ;
V_22 -> V_871 = V_831 [ V_870 ] . V_871 ;
V_22 -> V_115 = * ( V_831 [ V_870 ] . V_115 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_372 ( V_22 -> V_29 , V_872 |
V_873 | V_874 ) ;
V_673 = F_373 ( V_22 -> V_29 ) ;
if ( V_673 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_250 ) ;
F_369 ( V_22 -> V_29 ) ;
return V_673 ;
}
V_673 = F_374 ( V_22 -> V_29 , V_41 ) ;
if ( V_673 ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_251 ) ;
F_369 ( V_22 -> V_29 ) ;
return V_673 ;
}
F_375 ( V_22 -> V_29 ) ;
F_347 ( V_22 ) ;
V_673 = F_334 ( V_22 -> V_29 , & V_22 -> V_780 ) ;
if ( V_673 )
goto V_875;
V_22 -> V_152 = F_297 ( V_22 -> V_780 , 0x250 ) ;
if ( ! V_22 -> V_152 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_252 ) ;
V_673 = - V_245 ;
goto V_875;
}
V_673 = F_339 ( V_22 -> V_29 , V_22 -> V_152 , V_790 ) ;
if ( V_673 )
goto V_876;
V_673 = F_355 ( V_22 ) ;
if ( V_673 )
goto V_876;
F_359 ( V_22 ) ;
if ( ! F_360 ( V_22 ) ) {
V_673 = - V_80 ;
goto V_877;
}
F_362 ( V_22 ) ;
F_364 ( V_22 ) ;
V_673 = F_367 ( V_22 ) ;
if ( V_673 )
goto V_877;
return 0 ;
V_877:
F_354 ( V_22 ) ;
V_876:
F_319 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
V_875:
F_344 ( V_22 ) ;
F_369 ( V_22 -> V_29 ) ;
F_370 ( V_22 -> V_29 ) ;
return V_673 ;
}
static void F_376 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_377 64
V_22 -> V_61 = F_89 ( F_377 , V_198 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_161 ( V_22 , V_158 , 0 ,
V_22 -> V_61 , F_377 ) ;
if ( V_21 != 0 ) {
F_78 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_378 ( struct V_352 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_14 * V_152 ;
if ( ! V_748 )
return 0 ;
V_21 = F_373 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_253 ) ;
return - V_80 ;
}
F_369 ( V_29 ) ;
F_158 ( 260 ) ;
V_21 = F_373 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_254 ) ;
return - V_80 ;
}
F_375 ( V_29 ) ;
V_152 = F_316 ( V_29 , 0 ) ;
if ( V_152 == NULL ) {
V_21 = - V_245 ;
goto V_878;
}
F_58 ( V_879 , V_152 + V_880 ) ;
F_319 ( V_152 ) ;
V_21 = F_331 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_878;
F_92 ( & V_29 -> V_30 , L_255 ) ;
for ( V_68 = 0 ; V_68 < V_881 ; V_68 ++ ) {
if ( F_379 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_256 ,
( V_68 < 11 ? L_257 : L_258 ) ) ;
}
V_878:
F_369 ( V_29 ) ;
return V_21 ;
}
static void F_380 ( struct V_1 * V_22 )
{
F_78 ( V_22 -> V_668 ) ;
V_22 -> V_668 = NULL ;
if ( V_22 -> V_388 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( struct V_8 ) ,
V_22 -> V_388 ,
V_22 -> V_589 ) ;
V_22 -> V_388 = NULL ;
V_22 -> V_589 = 0 ;
}
if ( V_22 -> V_590 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( struct V_319 ) ,
V_22 -> V_590 ,
V_22 -> V_591 ) ;
V_22 -> V_590 = NULL ;
V_22 -> V_591 = 0 ;
}
}
static int F_381 ( struct V_1 * V_22 )
{
V_22 -> V_668 = F_98 (
F_382 ( V_22 -> V_232 , V_570 ) *
sizeof( unsigned long ) , V_198 ) ;
V_22 -> V_388 = F_320 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_388 ) ,
& ( V_22 -> V_589 ) ) ;
V_22 -> V_590 = F_320 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_590 ) ,
& ( V_22 -> V_591 ) ) ;
if ( ( V_22 -> V_668 == NULL )
|| ( V_22 -> V_388 == NULL )
|| ( V_22 -> V_590 == NULL ) ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_259 , V_199 ) ;
goto V_882;
}
F_239 ( V_22 ) ;
return 0 ;
V_882:
F_380 ( V_22 ) ;
return - V_245 ;
}
static void F_383 ( struct V_1 * V_22 )
{
int V_68 , V_366 ;
V_366 = F_384 ( V_883 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_385 ( V_22 -> V_616 [ V_68 ] , F_386 ( V_366 ) ) ;
V_366 = F_387 ( V_366 , V_883 ) ;
}
}
static void F_388 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_126 || V_22 -> V_617 != V_884 ) {
V_68 = V_22 -> V_617 ;
F_385 ( V_22 -> V_616 [ V_68 ] , NULL ) ;
F_389 ( V_22 -> V_616 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_385 ( V_22 -> V_616 [ V_68 ] , NULL ) ;
F_389 ( V_22 -> V_616 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
}
for (; V_68 < V_821 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = 0 ;
}
static int F_390 ( struct V_1 * V_22 ,
T_16 (* F_391)( int , void * ) ,
T_16 (* F_392)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_821 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_617 == V_884 && V_22 -> V_126 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
sprintf ( V_22 -> V_885 [ V_68 ] , L_260 , V_22 -> V_31 , V_68 ) ;
V_21 = F_393 ( V_22 -> V_616 [ V_68 ] , F_391 ,
0 , V_22 -> V_885 [ V_68 ] ,
& V_22 -> V_110 [ V_68 ] ) ;
if ( V_21 ) {
int V_188 ;
F_71 ( & V_22 -> V_29 -> V_30 ,
L_261 ,
V_22 -> V_616 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_188 = 0 ; V_188 < V_68 ; V_188 ++ ) {
F_389 ( V_22 -> V_616 [ V_188 ] , & V_22 -> V_110 [ V_188 ] ) ;
V_22 -> V_110 [ V_188 ] = 0 ;
}
for (; V_188 < V_821 ; V_188 ++ )
V_22 -> V_110 [ V_188 ] = 0 ;
return V_21 ;
}
}
F_383 ( V_22 ) ;
} else {
if ( V_22 -> V_126 > 0 || V_22 -> V_817 ) {
if ( V_22 -> V_126 )
sprintf ( V_22 -> V_885 [ V_22 -> V_617 ] ,
L_262 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_885 [ V_22 -> V_617 ] ,
L_263 , V_22 -> V_31 ) ;
V_21 = F_393 ( V_22 -> V_616 [ V_22 -> V_617 ] ,
F_391 , 0 ,
V_22 -> V_885 [ V_22 -> V_617 ] ,
& V_22 -> V_110 [ V_22 -> V_617 ] ) ;
} else {
sprintf ( V_22 -> V_885 [ V_22 -> V_617 ] ,
L_264 , V_22 -> V_31 ) ;
V_21 = F_393 ( V_22 -> V_616 [ V_22 -> V_617 ] ,
F_392 , V_886 ,
V_22 -> V_885 [ V_22 -> V_617 ] ,
& V_22 -> V_110 [ V_22 -> V_617 ] ) ;
}
F_385 ( V_22 -> V_616 [ V_22 -> V_617 ] , NULL ) ;
}
if ( V_21 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_261 ,
V_22 -> V_616 [ V_22 -> V_617 ] , V_22 -> V_31 ) ;
F_388 ( V_22 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_394 ( struct V_1 * V_22 )
{
int V_21 ;
F_295 ( V_22 , V_158 , V_887 ) ;
F_92 ( & V_22 -> V_29 -> V_30 , L_265 ) ;
V_21 = F_339 ( V_22 -> V_29 , V_22 -> V_152 , V_888 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_266 ) ;
return V_21 ;
}
F_92 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
V_21 = F_339 ( V_22 -> V_29 , V_22 -> V_152 , V_790 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_268
L_269 ) ;
return V_21 ;
}
return 0 ;
}
static void F_395 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
if ( ! V_22 -> V_113 [ V_68 ] . V_117 )
continue;
F_322 ( V_22 -> V_29 ,
V_22 -> V_889 ,
V_22 -> V_113 [ V_68 ] . V_117 ,
V_22 -> V_113 [ V_68 ] . V_122 ) ;
V_22 -> V_113 [ V_68 ] . V_117 = NULL ;
V_22 -> V_113 [ V_68 ] . V_122 = 0 ;
}
V_22 -> V_889 = 0 ;
}
static void F_396 ( struct V_1 * V_22 )
{
F_397 ( V_22 ) ;
F_113 ( V_22 ) ;
F_380 ( V_22 ) ;
F_388 ( V_22 ) ;
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_368 ( V_22 ) ;
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_309 ) {
F_399 ( V_22 -> V_309 ) ;
V_22 -> V_309 = NULL ;
}
if ( V_22 -> V_890 ) {
F_399 ( V_22 -> V_890 ) ;
V_22 -> V_890 = NULL ;
}
F_78 ( V_22 ) ;
}
static void F_400 ( struct V_1 * V_22 )
{
int V_68 , V_389 ;
struct V_8 * V_9 ;
int V_891 = 0 ;
F_401 ( V_22 -> V_309 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
V_9 = V_22 -> V_388 + V_68 ;
V_389 = F_170 ( & V_9 -> V_389 ) ;
if ( V_389 > 1 ) {
V_9 -> V_24 -> V_36 = V_325 ;
F_60 ( V_9 ) ;
F_44 ( & V_22 -> V_62 ) ;
V_891 ++ ;
}
F_164 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_270 , V_891 ) ;
}
static void F_402 ( struct V_1 * V_22 , T_4 V_892 )
{
int V_366 ;
F_403 (cpu) {
T_4 * F_13 ;
F_13 = F_155 ( V_22 -> F_13 , V_366 ) ;
* F_13 = V_892 ;
}
F_74 () ;
}
static void F_404 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
T_4 F_13 ;
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
F_13 = F_321 ( V_22 -> V_152 + V_842 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_271 ,
V_22 -> V_147 / V_895 ) ;
F_13 = 0xffffffff ;
}
F_402 ( V_22 , F_13 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_272 ,
F_13 , V_22 -> V_147 / V_895 ) ;
F_369 ( V_22 -> V_29 ) ;
F_400 ( V_22 ) ;
}
static int F_260 ( struct V_1 * V_22 )
{
T_5 V_896 ;
T_4 V_897 ;
unsigned long V_77 ;
V_896 = F_311 () ;
if ( F_405 ( V_22 -> V_751 +
( V_22 -> V_147 ) , V_896 ) )
return false ;
if ( F_405 ( V_22 -> V_898 +
( V_22 -> V_147 ) , V_896 ) )
return false ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_897 = F_321 ( & V_22 -> V_774 -> V_804 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( V_22 -> V_899 == V_897 ) {
F_404 ( V_22 ) ;
return true ;
}
V_22 -> V_899 = V_897 ;
V_22 -> V_898 = V_896 ;
return false ;
}
static void F_406 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_900 ;
if ( ! ( V_22 -> V_442 & V_901 ) )
return;
if ( ( V_22 -> V_63 & ( V_114
| V_902 ) ) &&
( V_22 -> V_903 & V_904 ||
V_22 -> V_903 & V_905 ) ) {
if ( V_22 -> V_903 & V_904 )
V_900 = L_273 ;
if ( V_22 -> V_903 & V_905 )
V_900 = L_274 ;
F_407 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_88 = 0 ;
F_408 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_275 ,
V_22 -> V_903 , V_900 ) ;
F_58 ( V_22 -> V_903 , & ( V_22 -> V_774 -> V_906 ) ) ;
F_58 ( V_859 , V_22 -> V_152 + V_769 ) ;
F_365 ( V_22 ) ;
F_409 ( V_22 -> V_59 ) ;
} else {
F_58 ( V_22 -> V_903 , & ( V_22 -> V_774 -> V_906 ) ) ;
F_58 ( V_859 , V_22 -> V_152 + V_769 ) ;
F_365 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_410 ( struct V_1 * V_22 )
{
if ( ! ( V_22 -> V_442 & V_901 ) )
return 0 ;
V_22 -> V_903 = F_321 ( & ( V_22 -> V_774 -> V_907 ) ) ;
return V_22 -> V_903 & V_908 ;
}
static int F_411 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
struct V_196 * V_372 ;
struct V_909 * V_910 , * V_911 ;
F_34 ( & V_22 -> V_197 , V_77 ) ;
F_412 (this, tmp, &h->offline_device_list) {
V_372 = F_413 ( V_910 , struct V_196 ,
V_200 ) ;
F_35 ( & V_22 -> V_197 , V_77 ) ;
if ( ! F_188 ( V_22 , V_372 -> V_72 ) ) {
F_34 ( & V_22 -> V_197 , V_77 ) ;
F_414 ( & V_372 -> V_200 ) ;
F_35 ( & V_22 -> V_197 , V_77 ) ;
return 1 ;
}
F_34 ( & V_22 -> V_197 , V_77 ) ;
}
F_35 ( & V_22 -> V_197 , V_77 ) ;
return 0 ;
}
static void F_415 ( struct V_593 * V_307 )
{
unsigned long V_77 ;
struct V_1 * V_22 = F_242 ( F_416 ( V_307 ) ,
struct V_1 , V_912 ) ;
if ( V_22 -> V_863 )
return;
if ( F_410 ( V_22 ) || F_411 ( V_22 ) ) {
F_417 ( V_22 -> V_59 ) ;
F_406 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_251 ( V_22 -> V_59 ) ;
}
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! V_22 -> V_863 )
F_418 ( V_22 -> V_890 , & V_22 -> V_912 ,
V_22 -> V_147 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
static void F_419 ( struct V_593 * V_307 )
{
unsigned long V_77 ;
struct V_1 * V_22 = F_242 ( F_416 ( V_307 ) ,
struct V_1 , V_913 ) ;
F_260 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! V_22 -> V_863 )
F_420 ( & V_22 -> V_913 ,
V_22 -> V_147 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
static struct V_914 * F_421 ( struct V_1 * V_22 ,
char * V_915 )
{
struct V_914 * V_916 = NULL ;
V_916 = F_422 ( L_276 , 0 , V_915 , V_22 -> V_619 ) ;
if ( ! V_916 )
F_71 ( & V_22 -> V_29 -> V_30 , L_277 , V_915 ) ;
return V_916 ;
}
static int F_423 ( struct V_352 * V_29 , const struct V_917 * V_918 )
{
int V_919 , V_21 ;
struct V_1 * V_22 ;
int V_920 = 0 ;
unsigned long V_77 ;
T_4 V_67 ;
if ( V_921 == 0 )
F_424 (KERN_INFO DRIVER_NAME L_278 ) ;
V_21 = F_353 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_279 ) ;
return V_21 ;
}
V_21 = F_378 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_783 )
return V_21 ;
V_920 = 1 ;
V_21 = 0 ;
}
V_922:
F_266 ( sizeof( struct V_8 ) % V_923 ) ;
V_22 = F_98 ( sizeof( * V_22 ) , V_198 ) ;
if ( ! V_22 ) {
F_71 ( & V_29 -> V_30 , L_280 ) ;
return - V_245 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_617 = V_924 ? V_925 : V_884 ;
F_425 ( & V_22 -> V_201 ) ;
F_426 ( & V_22 -> V_78 ) ;
F_426 ( & V_22 -> V_197 ) ;
F_426 ( & V_22 -> V_598 ) ;
F_107 ( & V_22 -> V_727 , V_926 ) ;
F_107 ( & V_22 -> V_658 , V_927 ) ;
V_22 -> F_13 = F_427 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_71 ( & V_22 -> V_29 -> V_30 , L_281 ) ;
V_21 = - V_245 ;
goto V_928;
}
F_402 ( V_22 , 0 ) ;
V_21 = F_371 ( V_22 ) ;
if ( V_21 )
goto V_875;
V_21 = F_248 ( V_22 ) ;
if ( V_21 )
goto V_929;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_101 ) ;
V_22 -> V_619 = V_921 ;
V_921 ++ ;
V_21 = F_428 ( V_29 , F_318 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_919 = 1 ;
} else {
V_21 = F_428 ( V_29 , F_318 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_919 = 0 ;
} else {
F_71 ( & V_29 -> V_30 , L_282 ) ;
goto V_876;
}
}
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
V_21 = F_390 ( V_22 , F_314 , F_313 ) ;
if ( V_21 )
goto V_876;
V_21 = F_381 ( V_22 ) ;
if ( V_21 )
goto V_877;
V_21 = F_114 ( V_22 ) ;
if ( V_21 )
goto V_930;
F_429 ( & V_22 -> V_600 ) ;
F_429 ( & V_22 -> V_657 ) ;
F_429 ( & V_22 -> V_305 ) ;
F_430 ( & V_22 -> V_386 ) ;
V_22 -> V_599 = 1 ;
F_431 ( V_29 , V_22 ) ;
V_22 -> V_162 = 0 ;
F_426 ( & V_22 -> V_98 ) ;
V_21 = F_432 ( V_22 ) ;
if ( V_21 )
goto V_931;
V_21 = F_252 ( V_22 ) ;
if ( V_21 )
goto V_932;
V_22 -> V_890 = F_421 ( V_22 , L_283 ) ;
if ( ! V_22 -> V_890 ) {
V_21 = - V_245 ;
goto V_932;
}
V_22 -> V_309 = F_421 ( V_22 , L_284 ) ;
if ( ! V_22 -> V_309 ) {
V_21 = - V_245 ;
goto V_932;
}
if ( V_920 ) {
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_388 ( V_22 ) ;
V_21 = F_390 ( V_22 , F_312 ,
F_310 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_285 ) ;
F_397 ( V_22 ) ;
F_113 ( V_22 ) ;
F_380 ( V_22 ) ;
goto V_876;
}
V_21 = F_394 ( V_22 ) ;
if ( V_21 )
goto V_932;
F_92 ( & V_22 -> V_29 -> V_30 , L_286 ) ;
F_92 ( & V_22 -> V_29 -> V_30 ,
L_287 ) ;
V_22 -> V_115 . V_893 ( V_22 , V_933 ) ;
F_158 ( 10000 ) ;
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
V_21 = F_330 ( V_22 -> V_774 ) ;
if ( V_21 )
F_92 ( & V_22 -> V_29 -> V_30 ,
L_288 ) ;
F_396 ( V_22 ) ;
V_920 = 0 ;
if ( V_21 )
return - V_80 ;
goto V_922;
}
V_22 -> V_56 = 1 ;
V_22 -> V_115 . V_893 ( V_22 , V_933 ) ;
F_376 ( V_22 ) ;
V_22 -> V_147 = V_149 ;
F_433 ( & V_22 -> V_913 , F_419 ) ;
F_420 ( & V_22 -> V_913 ,
V_22 -> V_147 ) ;
F_433 ( & V_22 -> V_912 , F_415 ) ;
F_418 ( V_22 -> V_890 , & V_22 -> V_912 ,
V_22 -> V_147 ) ;
return 0 ;
V_932:
F_397 ( V_22 ) ;
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
V_931:
F_113 ( V_22 ) ;
V_930:
F_380 ( V_22 ) ;
V_877:
F_388 ( V_22 ) ;
V_876:
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_929:
F_368 ( V_22 ) ;
V_875:
if ( V_22 -> F_13 ) {
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_928:
if ( V_22 -> V_309 ) {
F_399 ( V_22 -> V_309 ) ;
V_22 -> V_309 = NULL ;
}
if ( V_22 -> V_890 ) {
F_399 ( V_22 -> V_890 ) ;
V_22 -> V_890 = NULL ;
}
F_78 ( V_22 ) ;
return V_21 ;
}
static void F_434 ( struct V_1 * V_22 )
{
char * V_934 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_43 ( F_13 ( V_22 ) ) )
return;
V_934 = F_98 ( 4 , V_198 ) ;
if ( ! V_934 )
return;
V_9 = F_162 ( V_22 ) ;
if ( F_163 ( V_9 , V_732 , V_22 , V_934 , 4 , 0 ,
V_158 , V_376 ) ) {
goto V_377;
}
V_21 = F_157 ( V_22 , V_9 ,
V_254 , V_363 ) ;
if ( V_21 )
goto V_377;
if ( V_9 -> V_24 -> V_36 != 0 )
V_377:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_289 ) ;
F_164 ( V_22 , V_9 ) ;
F_78 ( V_934 ) ;
}
static void F_435 ( struct V_352 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_436 ( V_29 ) ;
F_434 ( V_22 ) ;
V_22 -> V_115 . V_893 ( V_22 , V_894 ) ;
F_388 ( V_22 ) ;
F_344 ( V_22 ) ;
}
static void F_437 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
F_78 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_438 ( struct V_352 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_77 ;
if ( F_436 ( V_29 ) == NULL ) {
F_71 ( & V_29 -> V_30 , L_290 ) ;
return;
}
V_22 = F_436 ( V_29 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_22 -> V_863 = 1 ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_439 ( & V_22 -> V_913 ) ;
F_439 ( & V_22 -> V_912 ) ;
F_399 ( V_22 -> V_890 ) ;
F_399 ( V_22 -> V_309 ) ;
if ( V_22 -> V_59 )
F_440 ( V_22 -> V_59 ) ;
F_435 ( V_29 ) ;
F_437 ( V_22 ) ;
F_78 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_111 ( V_22 ) ;
F_397 ( V_22 ) ;
F_113 ( V_22 ) ;
F_380 ( V_22 ) ;
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_368 ( V_22 ) ;
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_78 ( V_22 ) ;
}
static void F_441 ( int V_935 [] , int V_936 ,
int V_937 , int V_938 , T_4 * V_939 )
{
int V_68 , V_188 , V_940 , V_428 ;
for ( V_68 = 0 ; V_68 <= V_937 ; V_68 ++ ) {
V_428 = V_68 + V_938 ;
V_940 = V_936 ;
for ( V_188 = 0 ; V_188 < V_936 ; V_188 ++ ) {
if ( V_935 [ V_188 ] >= V_428 ) {
V_940 = V_188 ;
break;
}
}
V_939 [ V_68 ] = V_940 ;
}
}
static int F_442 ( struct V_1 * V_22 , T_4 V_866 )
{
int V_68 ;
unsigned long V_941 ;
unsigned long V_63 = V_64 |
( V_866 & V_942 ) |
V_943 |
( V_866 & ( V_114 |
V_902 ) ) ;
struct V_944 V_115 = V_945 ;
int V_946 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_724 + 4 } ;
#define F_443 5
#define F_444 4
int V_947 [ 16 ] = { F_443 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_444 + V_948 } ;
F_266 ( F_26 ( V_947 ) != 16 ) ;
F_266 ( F_26 ( V_946 ) != 8 ) ;
F_266 ( F_232 ( struct V_139 , V_255 ) >
16 * F_443 ) ;
F_266 ( sizeof( struct V_249 ) != 16 ) ;
F_266 ( 28 > V_724 + 4 ) ;
if ( V_866 & ( V_114 | V_902 ) )
V_115 = V_949 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 , 0 , V_22 -> V_889 ) ;
V_946 [ 7 ] = V_724 + 4 ;
F_441 ( V_946 , F_26 ( V_946 ) ,
V_724 , 4 , V_22 -> V_123 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_58 ( V_946 [ V_68 ] , & V_22 -> V_847 -> V_950 [ V_68 ] ) ;
F_58 ( V_22 -> V_121 , & V_22 -> V_847 -> V_951 ) ;
F_58 ( V_22 -> V_129 , & V_22 -> V_847 -> V_952 ) ;
F_58 ( 0 , & V_22 -> V_847 -> V_953 ) ;
F_58 ( 0 , & V_22 -> V_847 -> V_954 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_58 ( 0 , & V_22 -> V_847 -> V_955 [ V_68 ] . V_956 ) ;
F_58 ( V_22 -> V_113 [ V_68 ] . V_122 ,
& V_22 -> V_847 -> V_955 [ V_68 ] . V_957 ) ;
}
F_58 ( 0 , & V_22 -> V_774 -> V_797 . V_869 ) ;
F_58 ( V_63 , & ( V_22 -> V_774 -> V_797 . V_798 ) ) ;
if ( V_866 & V_114 ) {
V_115 = V_958 ;
F_58 ( 10 , & V_22 -> V_774 -> V_797 . V_799 ) ;
F_58 ( 4 , & V_22 -> V_774 -> V_797 . V_800 ) ;
} else {
if ( V_866 & V_902 ) {
V_115 = V_959 ;
F_58 ( 10 , & V_22 -> V_774 -> V_797 . V_799 ) ;
F_58 ( 4 , & V_22 -> V_774 -> V_797 . V_800 ) ;
}
}
F_58 ( V_864 , V_22 -> V_152 + V_769 ) ;
if ( F_366 ( V_22 ) ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_291 ) ;
return - V_80 ;
}
V_941 = F_321 ( & ( V_22 -> V_774 -> V_796 ) ) ;
if ( ! ( V_941 & V_64 ) ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_292 ) ;
return - V_80 ;
}
V_22 -> V_115 = V_115 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_866 & V_114 ) ||
( V_866 & V_902 ) ) )
return 0 ;
if ( V_866 & V_114 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_58 ( V_68 , V_22 -> V_152 + V_960 ) ;
V_22 -> V_113 [ V_68 ] . V_118 =
F_321 ( V_22 -> V_152 + V_961 ) ;
}
V_946 [ 7 ] = V_22 -> V_509 + 8 ;
F_441 ( V_946 , F_26 ( V_946 ) , V_22 -> V_509 , 8 ,
V_22 -> V_134 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 ,
( T_1 ) V_962 ,
V_22 -> V_889 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
struct V_130 * V_131 = & V_22 -> V_132 [ V_68 ] ;
V_131 -> V_963 = V_964 ;
V_131 -> V_24 = ( T_4 ) ( V_22 -> V_591 +
( V_68 * sizeof( struct V_319 ) ) ) ;
V_131 -> V_965 = sizeof( struct V_319 ) ;
V_131 -> V_966 = V_967 ;
V_131 -> V_968 =
F_145 ( V_969 ) ;
V_131 -> V_970 = 0 ;
V_131 -> V_128 = 0 ;
V_131 -> V_331 =
F_119 ( ( V_68 << V_541 ) ) ;
V_131 -> V_971 =
F_119 ( V_22 -> V_512 +
( V_68 * sizeof( struct V_130 ) ) ) ;
}
} else if ( V_866 & V_902 ) {
T_5 V_777 , V_779 ;
T_4 V_972 , V_778 ;
int V_21 ;
V_21 = F_335 ( V_22 -> V_29 , V_22 -> V_152 , & V_778 ,
& V_779 , & V_777 ) ;
F_266 ( F_232 ( struct V_139 , V_255 ) != 64 ) ;
V_947 [ 15 ] = V_22 -> V_509 + F_444 ;
F_441 ( V_947 , F_26 ( V_947 ) , V_22 -> V_509 ,
4 , V_22 -> V_138 ) ;
V_972 = F_321 ( & V_22 -> V_774 -> V_973 ) ;
F_266 ( F_232 ( struct V_773 ,
V_973 ) != 0xb8 ) ;
V_22 -> V_974 =
F_297 ( F_336 ( V_22 -> V_29 ,
V_779 ) +
V_777 + V_972 ,
F_26 ( V_947 ) *
sizeof( * V_22 -> V_974 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_947 ) ; V_68 ++ )
F_58 ( V_947 [ V_68 ] , & V_22 -> V_974 [ V_68 ] ) ;
}
F_58 ( V_864 , V_22 -> V_152 + V_769 ) ;
if ( F_366 ( V_22 ) ) {
F_71 ( & V_22 -> V_29 -> V_30 ,
L_293 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_445 ( struct V_1 * V_22 )
{
if ( V_22 -> V_132 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_132 ) ,
V_22 -> V_132 ,
V_22 -> V_512 ) ;
V_22 -> V_132 = NULL ;
V_22 -> V_512 = 0 ;
}
F_78 ( V_22 -> V_134 ) ;
V_22 -> V_134 = NULL ;
}
static int F_446 ( struct V_1 * V_22 )
{
V_22 -> V_509 =
F_321 ( & ( V_22 -> V_774 -> V_975 ) ) ;
if ( V_22 -> V_509 > V_976 )
V_22 -> V_509 = V_976 ;
F_266 ( sizeof( struct V_130 ) %
V_977 ) ;
V_22 -> V_132 =
F_320 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_132 ) ,
& ( V_22 -> V_512 ) ) ;
V_22 -> V_134 =
F_89 ( ( ( V_22 -> V_509 + 1 ) *
sizeof( T_4 ) ) , V_198 ) ;
if ( ( V_22 -> V_132 == NULL ) ||
( V_22 -> V_134 == NULL ) )
goto V_882;
memset ( V_22 -> V_132 , 0 ,
V_22 -> V_232 * sizeof( * V_22 -> V_132 ) ) ;
return 0 ;
V_882:
F_445 ( V_22 ) ;
return - V_245 ;
}
static void F_447 ( struct V_1 * V_22 )
{
F_111 ( V_22 ) ;
if ( V_22 -> V_137 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_137 ) ,
V_22 -> V_137 ,
V_22 -> V_531 ) ;
V_22 -> V_137 = NULL ;
V_22 -> V_531 = 0 ;
}
F_78 ( V_22 -> V_138 ) ;
V_22 -> V_138 = NULL ;
}
static int F_448 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_509 =
F_321 ( & ( V_22 -> V_774 -> V_975 ) ) ;
if ( V_22 -> V_509 > V_948 )
V_22 -> V_509 = V_948 ;
F_266 ( sizeof( struct V_139 ) %
V_978 ) ;
V_22 -> V_137 =
F_320 ( V_22 -> V_29 ,
V_22 -> V_232 * sizeof( * V_22 -> V_137 ) ,
& ( V_22 -> V_531 ) ) ;
V_22 -> V_138 =
F_89 ( ( ( V_22 -> V_509 + 1 ) *
sizeof( T_4 ) ) , V_198 ) ;
if ( ( V_22 -> V_137 == NULL ) ||
( V_22 -> V_138 == NULL ) ) {
V_21 = - V_245 ;
goto V_882;
}
V_21 = F_112 ( V_22 ) ;
if ( V_21 )
goto V_882;
memset ( V_22 -> V_137 , 0 ,
V_22 -> V_232 * sizeof( * V_22 -> V_137 ) ) ;
return 0 ;
V_882:
F_447 ( V_22 ) ;
return V_21 ;
}
static void F_397 ( struct V_1 * V_22 )
{
F_78 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
F_395 ( V_22 ) ;
F_445 ( V_22 ) ;
F_447 ( V_22 ) ;
}
static int F_432 ( struct V_1 * V_22 )
{
T_4 V_866 ;
unsigned long V_63 = V_64 |
V_942 ;
int V_68 , V_21 ;
if ( V_924 )
return 0 ;
V_866 = F_321 ( & ( V_22 -> V_774 -> V_795 ) ) ;
if ( ! ( V_866 & V_979 ) )
return 0 ;
if ( V_866 & V_114 ) {
V_63 |= V_114 |
V_943 ;
V_21 = F_446 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_866 & V_902 ) {
V_63 |= V_902 |
V_943 ;
V_21 = F_448 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_129 = V_22 -> V_126 > 0 ? V_22 -> V_126 : 1 ;
F_356 ( V_22 ) ;
V_22 -> V_889 = V_22 -> V_121 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
V_22 -> V_113 [ V_68 ] . V_117 = F_320 ( V_22 -> V_29 ,
V_22 -> V_889 ,
& ( V_22 -> V_113 [ V_68 ] . V_122 ) ) ;
if ( ! V_22 -> V_113 [ V_68 ] . V_117 ) {
V_21 = - V_245 ;
goto V_928;
}
V_22 -> V_113 [ V_68 ] . V_428 = V_22 -> V_121 ;
V_22 -> V_113 [ V_68 ] . V_119 = 1 ;
V_22 -> V_113 [ V_68 ] . V_118 = 0 ;
}
V_22 -> V_123 = F_89 ( ( ( V_724 + 1 ) *
sizeof( T_4 ) ) , V_198 ) ;
if ( ! V_22 -> V_123 ) {
V_21 = - V_245 ;
goto V_928;
}
V_21 = F_442 ( V_22 , V_866 ) ;
if ( V_21 )
goto V_875;
return 0 ;
V_875:
F_78 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
V_928:
F_395 ( V_22 ) ;
F_445 ( V_22 ) ;
F_447 ( V_22 ) ;
return V_21 ;
}
static int F_449 ( struct V_8 * V_9 )
{
return V_9 -> V_150 == V_151 || V_9 -> V_150 == V_154 ;
}
static void F_408 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_980 ;
int V_389 ;
do {
V_980 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_232 ; V_68 ++ ) {
V_9 = V_22 -> V_388 + V_68 ;
V_389 = F_170 ( & V_9 -> V_389 ) ;
if ( V_389 > 1 )
V_980 += F_449 ( V_9 ) ;
F_164 ( V_22 , V_9 ) ;
}
if ( V_980 <= 0 )
break;
F_158 ( 100 ) ;
} while ( 1 );
}
static int T_17 F_450 ( void )
{
return F_451 ( & V_981 ) ;
}
static void T_18 F_452 ( void )
{
F_453 ( & V_981 ) ;
}
