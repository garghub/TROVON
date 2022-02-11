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
return snprintf ( V_45 , 20 , L_22 , V_86 ) ;
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
T_5 V_89 ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 || F_32 ( V_77 ) || ! V_77 -> V_90 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
V_89 = V_77 -> V_89 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
return snprintf ( V_45 , V_82 , L_25 , V_89 ) ;
}
static T_2 F_40 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
int V_91 ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_79 , V_78 ) ;
return - V_81 ;
}
V_91 = V_77 -> V_91 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
return snprintf ( V_45 , 20 , L_15 , V_91 ) ;
}
static T_2 F_41 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
struct V_73 * V_77 ;
unsigned long V_78 ;
int V_68 ;
int V_92 = 0 ;
T_1 V_93 ;
T_1 V_94 ;
T_1 V_95 = 0 ;
char * V_96 ;
unsigned char V_97 [ 2 ] ;
V_3 = F_34 ( V_30 ) ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
V_77 = V_3 -> V_80 ;
if ( ! V_77 ) {
F_36 ( & V_22 -> V_98 , V_78 ) ;
return - V_81 ;
}
V_94 = V_77 -> V_94 ;
for ( V_68 = 0 ; V_68 < V_99 ; V_68 ++ ) {
V_95 = 1 << V_68 ;
if ( V_68 == V_77 -> V_100 )
V_96 = L_26 ;
else if ( V_77 -> V_101 & V_95 )
V_96 = L_27 ;
else
continue;
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 ,
L_28 ,
V_22 -> V_59 -> V_102 ,
V_77 -> V_103 , V_77 -> V_104 , V_77 -> V_105 ,
F_43 ( V_77 -> V_106 ) ) ;
if ( V_77 -> V_106 == V_107 || F_32 ( V_77 ) ) {
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 ,
L_16 , V_96 ) ;
continue;
}
V_93 = V_77 -> V_93 [ V_68 ] ;
memcpy ( & V_97 , & V_77 -> V_97 [ V_68 ] ,
sizeof( V_97 ) ) ;
if ( V_97 [ 0 ] < '0' )
V_97 [ 0 ] = '0' ;
if ( V_97 [ 1 ] < '0' )
V_97 [ 1 ] = '0' ;
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 ,
L_29 ,
V_97 ) ;
if ( ( V_77 -> V_106 == V_108 || V_77 -> V_106 == V_109 ) &&
V_77 -> V_90 ) {
if ( V_93 == 0 || V_93 == 0xFF ) {
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 ,
L_30 ,
V_94 , V_96 ) ;
} else {
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 ,
L_31 ,
V_93 , V_94 , V_96 ) ;
}
} else if ( V_93 != 0 && V_93 != 0xFF ) {
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 , L_32 ,
V_93 , V_96 ) ;
} else
V_92 += F_42 ( V_45 + V_92 ,
V_82 - V_92 , L_16 , V_96 ) ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
return V_92 ;
}
static T_2 F_44 ( struct V_42 * V_30 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_22 ;
struct V_6 * V_47 = F_12 ( V_30 ) ;
V_22 = F_3 ( V_47 ) ;
return snprintf ( V_45 , 20 , L_15 , V_22 -> V_110 ) ;
}
static inline T_4 F_45 ( struct V_1 * V_22 , T_1 V_111 )
{
T_4 V_65 ;
struct V_112 * V_113 = & V_22 -> V_114 [ V_111 ] ;
if ( V_22 -> V_63 & V_115 )
return V_22 -> V_116 . V_117 ( V_22 , V_111 ) ;
if ( F_46 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_116 . V_117 ( V_22 , V_111 ) ;
if ( ( V_113 -> V_118 [ V_113 -> V_119 ] & 1 ) == V_113 -> V_120 ) {
V_65 = V_113 -> V_118 [ V_113 -> V_119 ] ;
V_113 -> V_119 ++ ;
F_47 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_121 ;
}
if ( V_113 -> V_119 == V_22 -> V_122 ) {
V_113 -> V_119 = 0 ;
V_113 -> V_120 ^= 1 ;
}
return V_65 ;
}
static void F_48 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_114 )
{
if ( F_49 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_123 |= 1 | ( V_22 -> V_124 [ V_9 -> V_125 . V_126 ] << 1 ) ;
if ( F_46 ( ! V_22 -> V_127 ) )
return;
if ( F_49 ( V_114 == V_128 ) )
V_9 -> V_125 . V_129 =
F_50 () % V_22 -> V_130 ;
else
V_9 -> V_125 . V_129 = V_114 % V_22 -> V_130 ;
}
}
static void F_51 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_114 )
{
struct V_131 * V_132 = & V_22 -> V_133 [ V_9 -> V_134 ] ;
if ( F_49 ( V_114 == V_128 ) )
V_132 -> V_129 = F_52 () % V_22 -> V_130 ;
else
V_132 -> V_129 = V_114 % V_22 -> V_130 ;
V_9 -> V_123 |= 1 | ( V_22 -> V_135 [ V_9 -> V_125 . V_126 ] << 1 ) |
V_136 ;
}
static void F_53 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_114 )
{
struct V_137 * V_132 = (struct V_137 * )
& V_22 -> V_138 [ V_9 -> V_134 ] ;
if ( F_49 ( V_114 == V_128 ) )
V_132 -> V_114 = F_52 () % V_22 -> V_130 ;
else
V_132 -> V_114 = V_114 % V_22 -> V_130 ;
V_9 -> V_123 |= V_22 -> V_139 [ 0 ] ;
}
static void F_54 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_114 )
{
struct V_140 * V_132 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
if ( F_49 ( V_114 == V_128 ) )
V_132 -> V_114 = F_52 () % V_22 -> V_130 ;
else
V_132 -> V_114 = V_114 % V_22 -> V_130 ;
V_9 -> V_123 |= ( V_22 -> V_139 [ V_132 -> V_141 ] ) ;
}
static int F_55 ( T_1 * V_142 )
{
return V_142 [ 0 ] == V_143 && V_142 [ 6 ] == V_144 ;
}
static void F_56 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 -> V_145 . V_146 ) )
return;
F_57 ( & V_22 -> V_147 ) ;
V_22 -> V_148 = V_149 ;
}
static void F_58 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_55 ( V_9 -> V_145 . V_146 ) &&
F_59 ( & V_22 -> V_147 ) )
V_22 -> V_148 = V_150 ;
}
static void F_60 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_114 )
{
F_56 ( V_22 , V_9 ) ;
F_57 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_151 ) {
case V_152 :
F_51 ( V_22 , V_9 , V_114 ) ;
F_61 ( V_9 -> V_123 , V_22 -> V_153 + V_154 ) ;
break;
case V_155 :
F_54 ( V_22 , V_9 , V_114 ) ;
F_61 ( V_9 -> V_123 , V_22 -> V_153 + V_156 ) ;
break;
case V_157 :
F_53 ( V_22 , V_9 , V_114 ) ;
F_61 ( V_9 -> V_123 , V_22 -> V_153 + V_156 ) ;
break;
default:
F_48 ( V_22 , V_9 , V_114 ) ;
V_22 -> V_116 . V_158 ( V_22 , V_9 ) ;
}
}
static void F_62 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_46 ( F_5 ( V_9 ) ) )
return F_63 ( V_9 ) ;
F_60 ( V_22 , V_9 , V_128 ) ;
}
static inline int F_64 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_159 , 8 ) == 0 ;
}
static inline int F_65 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_61 )
return 0 ;
if ( ( V_22 -> V_61 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_22 ,
unsigned char V_72 [] , int V_103 , int * V_104 , int * V_105 )
{
int V_68 , V_160 = 0 ;
F_67 ( V_161 , V_162 ) ;
F_68 ( V_161 , V_162 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_103 == V_103 && V_22 -> V_30 [ V_68 ] -> V_104 != - 1 )
F_69 ( V_22 -> V_30 [ V_68 ] -> V_104 , V_161 ) ;
}
V_68 = F_70 ( V_161 , V_162 ) ;
if ( V_68 < V_162 ) {
* V_104 = V_68 ;
* V_105 = 0 ;
V_160 = 1 ;
}
return ! V_160 ;
}
static void F_71 ( const char * V_164 , struct V_1 * V_22 ,
struct V_73 * V_30 , char * V_165 )
{
#define F_72 25
char V_166 [ F_72 ] ;
if ( V_22 == NULL || V_22 -> V_29 == NULL || V_22 -> V_59 == NULL )
return;
switch ( V_30 -> V_106 ) {
case V_107 :
snprintf ( V_166 , F_72 , L_33 ) ;
break;
case V_167 :
snprintf ( V_166 , F_72 , L_34 ) ;
break;
case V_108 :
case V_109 :
if ( V_30 -> V_168 )
snprintf ( V_166 , F_72 , L_35 ) ;
else if ( ! F_31 ( V_30 -> V_72 ) )
snprintf ( V_166 , F_72 , L_36 ,
V_85 [ V_169 ] ) ;
else
snprintf ( V_166 , F_72 , L_37 ,
V_30 -> V_83 > V_84 ? L_38 :
V_85 [ V_30 -> V_83 ] ) ;
break;
case V_170 :
snprintf ( V_166 , F_72 , L_39 ) ;
break;
case V_171 :
snprintf ( V_166 , F_72 , L_40 ) ;
break;
case V_172 :
snprintf ( V_166 , F_72 , L_41 ) ;
break;
default:
snprintf ( V_166 , F_72 , L_42 ) ;
break;
}
F_73 ( V_164 , & V_22 -> V_29 -> V_30 ,
L_43 ,
V_22 -> V_59 -> V_102 , V_30 -> V_103 , V_30 -> V_104 , V_30 -> V_105 ,
V_165 ,
F_43 ( V_30 -> V_106 ) ,
V_30 -> V_173 ,
V_30 -> V_174 ,
V_166 ,
V_30 -> V_175 ? '+' : '-' ,
V_30 -> V_91 ? '+' : '-' ,
V_30 -> V_90 ) ;
}
static int F_74 ( struct V_1 * V_22 ,
struct V_73 * V_42 ,
struct V_73 * V_176 [] , int * V_177 )
{
int V_178 = V_22 -> V_163 ;
int V_68 ;
unsigned char V_179 [ 8 ] , V_180 [ 8 ] ;
struct V_73 * V_181 ;
if ( V_178 >= V_162 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_44
L_45 ) ;
return - 1 ;
}
if ( V_42 -> V_105 != - 1 )
goto V_182;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_66 ( V_22 , V_42 -> V_72 ,
V_42 -> V_103 , & V_42 -> V_104 , & V_42 -> V_105 ) != 0 )
return - 1 ;
goto V_182;
}
memcpy ( V_179 , V_42 -> V_72 , 8 ) ;
V_179 [ 4 ] = 0 ;
V_179 [ 5 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_178 ; V_68 ++ ) {
V_181 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_180 , V_181 -> V_72 , 8 ) ;
V_180 [ 4 ] = 0 ;
V_180 [ 5 ] = 0 ;
if ( memcmp ( V_179 , V_180 , 8 ) == 0 ) {
V_42 -> V_103 = V_181 -> V_103 ;
V_42 -> V_104 = V_181 -> V_104 ;
V_42 -> V_105 = V_42 -> V_72 [ 4 ] ;
break;
}
}
if ( V_42 -> V_105 == - 1 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_46
L_47
L_48 ) ;
return - 1 ;
}
V_182:
V_22 -> V_30 [ V_178 ] = V_42 ;
V_22 -> V_163 ++ ;
V_176 [ * V_177 ] = V_42 ;
( * V_177 ) ++ ;
F_71 ( V_183 , V_22 , V_42 ,
V_42 -> V_90 ? L_49 : L_50 ) ;
V_42 -> V_184 = V_42 -> V_91 ;
V_42 -> V_91 = 0 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_22 ,
int V_185 , struct V_73 * V_186 )
{
int V_91 ;
F_77 ( V_185 < 0 || V_185 >= V_162 ) ;
V_22 -> V_30 [ V_185 ] -> V_83 = V_186 -> V_83 ;
if ( V_186 -> V_175 && V_186 -> V_91 ) {
V_22 -> V_30 [ V_185 ] -> V_187 = V_186 -> V_187 ;
V_22 -> V_30 [ V_185 ] -> V_188 = V_186 -> V_188 ;
}
if ( V_186 -> V_189 ) {
V_22 -> V_30 [ V_185 ] -> V_188 = V_186 -> V_188 ;
F_78 () ;
}
V_22 -> V_30 [ V_185 ] -> V_189 = V_186 -> V_189 ;
V_22 -> V_30 [ V_185 ] -> V_175 = V_186 -> V_175 ;
V_22 -> V_30 [ V_185 ] -> V_190 = V_186 -> V_190 ;
V_22 -> V_30 [ V_185 ] -> V_191 = V_186 -> V_191 ;
V_22 -> V_30 [ V_185 ] -> V_184 = V_186 -> V_91 ;
if ( ! V_186 -> V_91 )
V_22 -> V_30 [ V_185 ] -> V_91 = 0 ;
V_91 = V_22 -> V_30 [ V_185 ] -> V_91 ;
V_22 -> V_30 [ V_185 ] -> V_91 = V_22 -> V_30 [ V_185 ] -> V_184 ;
F_71 ( V_183 , V_22 , V_22 -> V_30 [ V_185 ] , L_51 ) ;
V_22 -> V_30 [ V_185 ] -> V_91 = V_91 ;
}
static void F_79 ( struct V_1 * V_22 ,
int V_185 , struct V_73 * V_186 ,
struct V_73 * V_176 [] , int * V_177 ,
struct V_73 * V_192 [] , int * V_193 )
{
F_77 ( V_185 < 0 || V_185 >= V_162 ) ;
V_192 [ * V_193 ] = V_22 -> V_30 [ V_185 ] ;
( * V_193 ) ++ ;
if ( V_186 -> V_104 == - 1 ) {
V_186 -> V_104 = V_22 -> V_30 [ V_185 ] -> V_104 ;
V_186 -> V_105 = V_22 -> V_30 [ V_185 ] -> V_105 ;
}
V_22 -> V_30 [ V_185 ] = V_186 ;
V_176 [ * V_177 ] = V_186 ;
( * V_177 ) ++ ;
F_71 ( V_183 , V_22 , V_186 , L_52 ) ;
V_186 -> V_184 = V_186 -> V_91 ;
V_186 -> V_91 = 0 ;
}
static void F_80 ( struct V_1 * V_22 , int V_185 ,
struct V_73 * V_192 [] , int * V_193 )
{
int V_68 ;
struct V_73 * V_181 ;
F_77 ( V_185 < 0 || V_185 >= V_162 ) ;
V_181 = V_22 -> V_30 [ V_185 ] ;
V_192 [ * V_193 ] = V_22 -> V_30 [ V_185 ] ;
( * V_193 ) ++ ;
for ( V_68 = V_185 ; V_68 < V_22 -> V_163 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_163 -- ;
F_71 ( V_183 , V_22 , V_181 , L_53 ) ;
}
static void F_81 ( struct V_1 * V_22 ,
struct V_73 * V_176 )
{
unsigned long V_78 ;
int V_68 , V_194 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_176 ) {
for ( V_194 = V_68 ; V_194 < V_22 -> V_163 - 1 ; V_194 ++ )
V_22 -> V_30 [ V_194 ] = V_22 -> V_30 [ V_194 + 1 ] ;
V_22 -> V_163 -- ;
break;
}
}
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_82 ( V_176 ) ;
}
static inline int F_83 ( struct V_73 * V_195 ,
struct V_73 * V_196 )
{
if ( memcmp ( V_195 -> V_72 , V_196 -> V_72 ,
sizeof( V_195 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_195 -> V_88 , V_196 -> V_88 ,
sizeof( V_195 -> V_88 ) ) != 0 )
return 0 ;
if ( memcmp ( V_195 -> V_174 , V_196 -> V_174 , sizeof( V_195 -> V_174 ) ) != 0 )
return 0 ;
if ( memcmp ( V_195 -> V_173 , V_196 -> V_173 , sizeof( V_195 -> V_173 ) ) != 0 )
return 0 ;
if ( V_195 -> V_106 != V_196 -> V_106 )
return 0 ;
if ( V_195 -> V_103 != V_196 -> V_103 )
return 0 ;
return 1 ;
}
static inline int F_84 ( struct V_73 * V_195 ,
struct V_73 * V_196 )
{
if ( V_195 -> V_83 != V_196 -> V_83 )
return 1 ;
if ( V_195 -> V_175 != V_196 -> V_175 )
return 1 ;
if ( V_195 -> V_91 != V_196 -> V_91 )
return 1 ;
if ( ! F_31 ( V_195 -> V_72 ) )
if ( V_195 -> V_191 != V_196 -> V_191 )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_73 * V_197 ,
struct V_73 * V_198 [] , int V_199 ,
int * V_200 )
{
int V_68 ;
#define F_86 0
#define F_87 1
#define F_88 2
#define F_89 3
if ( V_197 == NULL )
return F_86 ;
for ( V_68 = 0 ; V_68 < V_199 ; V_68 ++ ) {
if ( V_198 [ V_68 ] == NULL )
continue;
if ( F_90 ( V_197 -> V_72 , V_198 [ V_68 ] -> V_72 ) ) {
* V_200 = V_68 ;
if ( F_83 ( V_197 , V_198 [ V_68 ] ) ) {
if ( F_84 ( V_197 , V_198 [ V_68 ] ) )
return F_89 ;
return F_88 ;
} else {
if ( V_197 -> V_201 )
return F_86 ;
return F_87 ;
}
}
}
* V_200 = - 1 ;
return F_86 ;
}
static void F_91 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_202 * V_42 ;
unsigned long V_78 ;
F_35 ( & V_22 -> V_203 , V_78 ) ;
F_92 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_36 ( & V_22 -> V_203 , V_78 ) ;
return;
}
}
F_36 ( & V_22 -> V_203 , V_78 ) ;
V_42 = F_93 ( sizeof( * V_42 ) , V_204 ) ;
if ( ! V_42 )
return;
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_35 ( & V_22 -> V_203 , V_78 ) ;
F_94 ( & V_42 -> V_205 , & V_22 -> V_206 ) ;
F_36 ( & V_22 -> V_203 , V_78 ) ;
}
static void F_95 ( struct V_1 * V_22 ,
struct V_73 * V_181 )
{
if ( V_181 -> V_201 == V_207 )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_54 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
switch ( V_181 -> V_201 ) {
case V_208 :
break;
case V_209 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_55 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_210 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_56 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_211 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_57 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_212 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_58 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_213 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_59 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_214 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_60 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_215 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_61 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_216 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_62 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_217 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_63 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_218 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_64 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
case V_219 :
F_96 ( & V_22 -> V_29 -> V_30 ,
L_65 ,
V_22 -> V_59 -> V_102 ,
V_181 -> V_103 , V_181 -> V_104 , V_181 -> V_105 ) ;
break;
}
}
static void F_97 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_163 ,
struct V_73 * V_220 )
{
struct V_221 * V_222 = & V_220 -> V_187 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_68 , V_194 ;
int V_226 = F_98 ( V_222 -> V_227 ) +
F_98 ( V_222 -> V_228 ) ;
int V_229 = F_98 ( V_222 -> V_230 ) *
F_98 ( V_222 -> V_231 ) *
V_226 ;
int V_232 = F_98 ( V_222 -> V_231 ) *
V_226 ;
int V_233 ;
if ( V_229 > V_234 )
V_229 = V_234 ;
V_220 -> V_235 = V_229 ;
V_233 = 0 ;
for ( V_68 = 0 ; V_68 < V_229 ; V_68 ++ ) {
V_220 -> V_236 [ V_68 ] = NULL ;
if ( ! V_220 -> V_175 )
continue;
for ( V_194 = 0 ; V_194 < V_163 ; V_194 ++ ) {
if ( V_30 [ V_194 ] == NULL )
continue;
if ( V_30 [ V_194 ] -> V_106 != V_108 &&
V_30 [ V_194 ] -> V_106 != V_109 )
continue;
if ( F_32 ( V_30 [ V_194 ] ) )
continue;
if ( V_30 [ V_194 ] -> V_188 != V_224 [ V_68 ] . V_188 )
continue;
V_220 -> V_236 [ V_68 ] = V_30 [ V_194 ] ;
if ( V_68 < V_232 )
V_233 = F_99 ( V_22 -> V_237 , V_233 +
V_220 -> V_236 [ V_68 ] -> V_191 ) ;
break;
}
if ( ! V_220 -> V_236 [ V_68 ] ) {
V_220 -> V_91 = 0 ;
V_220 -> V_184 = 0 ;
V_220 -> V_191 = 8 ;
}
}
if ( V_229 )
V_220 -> V_191 = V_233 ;
else
V_220 -> V_191 = V_22 -> V_237 ;
}
static void F_100 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_163 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_163 ; V_68 ++ ) {
if ( V_30 [ V_68 ] == NULL )
continue;
if ( V_30 [ V_68 ] -> V_106 != V_108 &&
V_30 [ V_68 ] -> V_106 != V_109 )
continue;
if ( ! F_32 ( V_30 [ V_68 ] ) )
continue;
if ( V_30 [ V_68 ] -> V_91 )
continue;
F_97 ( V_22 , V_30 , V_163 , V_30 [ V_68 ] ) ;
}
}
static int F_101 ( struct V_1 * V_22 , struct V_73 * V_42 )
{
int V_21 = 0 ;
if ( ! V_22 -> V_59 )
return 1 ;
if ( F_32 ( V_42 ) )
V_21 = F_102 ( V_22 -> V_59 , V_42 -> V_103 ,
V_42 -> V_104 , V_42 -> V_105 ) ;
else
V_21 = F_103 ( V_22 -> V_238 , V_42 ) ;
return V_21 ;
}
static int F_104 ( struct V_1 * V_22 ,
struct V_73 * V_30 )
{
int V_68 ;
int V_48 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
int V_240 = F_105 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 && F_106 ( V_22 , V_9 , V_30 ,
V_30 -> V_72 ) ) {
unsigned long V_78 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
++ V_48 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_107 ( V_22 , V_9 ) ;
}
return V_48 ;
}
static void F_108 ( struct V_1 * V_22 ,
struct V_73 * V_42 )
{
int V_241 = 0 ;
int V_242 = 0 ;
while ( 1 ) {
V_241 = F_104 ( V_22 , V_42 ) ;
if ( V_241 == 0 )
break;
if ( ++ V_242 > 20 )
break;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_66 ,
V_243 , V_241 ) ;
F_109 ( 1000 ) ;
}
}
static void F_110 ( struct V_1 * V_22 ,
struct V_73 * V_42 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_22 -> V_59 )
return;
if ( F_32 ( V_42 ) ) {
V_3 = F_111 ( V_22 -> V_59 , V_42 -> V_103 ,
V_42 -> V_104 , V_42 -> V_105 ) ;
if ( V_3 ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
} else {
F_71 ( V_244 , V_22 , V_42 ,
L_67 ) ;
}
} else {
V_42 -> V_192 = 1 ;
F_108 ( V_22 , V_42 ) ;
F_114 ( V_42 ) ;
}
}
static void F_115 ( struct V_1 * V_22 ,
struct V_73 * V_181 [] , int V_245 )
{
int V_68 , V_185 , V_246 , V_247 = 0 ;
struct V_73 * V_248 ;
unsigned long V_78 ;
struct V_73 * * V_176 , * * V_192 ;
int V_177 , V_193 ;
if ( V_22 -> V_249 ) {
V_22 -> V_250 = 1 ;
return;
}
V_176 = F_116 ( sizeof( * V_176 ) * V_162 , V_204 ) ;
V_192 = F_116 ( sizeof( * V_192 ) * V_162 , V_204 ) ;
if ( ! V_176 || ! V_192 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_68
L_69 ) ;
goto V_251;
}
F_35 ( & V_22 -> V_98 , V_78 ) ;
V_68 = 0 ;
V_193 = 0 ;
V_177 = 0 ;
while ( V_68 < V_22 -> V_163 ) {
V_248 = V_22 -> V_30 [ V_68 ] ;
V_246 = F_85 ( V_248 , V_181 , V_245 , & V_185 ) ;
if ( V_246 == F_86 ) {
V_247 ++ ;
F_80 ( V_22 , V_68 , V_192 , & V_193 ) ;
continue;
} else if ( V_246 == F_87 ) {
V_247 ++ ;
F_79 ( V_22 , V_68 , V_181 [ V_185 ] ,
V_176 , & V_177 , V_192 , & V_193 ) ;
V_181 [ V_185 ] = NULL ;
} else if ( V_246 == F_89 ) {
F_76 ( V_22 , V_68 , V_181 [ V_185 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_245 ; V_68 ++ ) {
if ( ! V_181 [ V_68 ] )
continue;
if ( V_181 [ V_68 ] -> V_201 ) {
F_95 ( V_22 , V_181 [ V_68 ] ) ;
F_71 ( V_183 , V_22 , V_181 [ V_68 ] , L_70 ) ;
continue;
}
V_246 = F_85 ( V_181 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_163 , & V_185 ) ;
if ( V_246 == F_86 ) {
V_247 ++ ;
if ( F_74 ( V_22 , V_181 [ V_68 ] , V_176 , & V_177 ) != 0 )
break;
V_181 [ V_68 ] = NULL ;
} else if ( V_246 == F_87 ) {
V_247 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_71 ) ;
}
}
F_100 ( V_22 , V_22 -> V_30 , V_22 -> V_163 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == NULL )
continue;
V_22 -> V_30 [ V_68 ] -> V_91 = V_22 -> V_30 [ V_68 ] -> V_184 ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_245 ; V_68 ++ ) {
if ( ! V_181 [ V_68 ] )
continue;
if ( V_181 [ V_68 ] -> V_201 )
F_91 ( V_22 , V_181 [ V_68 ] -> V_72 ) ;
}
if ( ! V_247 )
goto V_251;
for ( V_68 = 0 ; V_68 < V_193 ; V_68 ++ ) {
if ( V_192 [ V_68 ] == NULL )
continue;
if ( V_192 [ V_68 ] -> V_90 )
F_110 ( V_22 , V_192 [ V_68 ] ) ;
F_82 ( V_192 [ V_68 ] ) ;
V_192 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_177 ; V_68 ++ ) {
int V_21 = 0 ;
if ( V_176 [ V_68 ] == NULL )
continue;
if ( ! ( V_176 [ V_68 ] -> V_90 ) )
continue;
V_21 = F_101 ( V_22 , V_176 [ V_68 ] ) ;
if ( ! V_21 )
continue;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_72 , V_21 ) ;
F_81 ( V_22 , V_176 [ V_68 ] ) ;
V_22 -> V_250 = 1 ;
}
V_251:
F_82 ( V_176 ) ;
F_82 ( V_192 ) ;
}
static struct V_73 * F_117 ( struct V_1 * V_22 ,
int V_103 , int V_104 , int V_105 )
{
int V_68 ;
struct V_73 * V_181 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
V_181 = V_22 -> V_30 [ V_68 ] ;
if ( V_181 -> V_103 == V_103 && V_181 -> V_104 == V_104 && V_181 -> V_105 == V_105 )
return V_181 ;
}
return NULL ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_73 * V_181 = NULL ;
unsigned long V_78 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
if ( F_119 ( V_3 ) == V_252 ) {
struct V_253 * V_254 ;
struct V_255 * V_256 ;
V_254 = V_253 ( V_3 ) ;
V_256 = F_120 ( V_254 ) ;
V_181 = F_121 ( V_22 , V_256 ) ;
if ( V_181 ) {
V_181 -> V_104 = F_122 ( V_3 ) ;
V_181 -> V_105 = V_3 -> V_105 ;
}
}
if ( ! V_181 )
V_181 = F_117 ( V_22 , F_119 ( V_3 ) ,
F_122 ( V_3 ) , V_3 -> V_105 ) ;
if ( V_181 && V_181 -> V_90 ) {
F_123 ( & V_181 -> V_257 , 0 ) ;
V_3 -> V_80 = V_181 ;
} else
V_3 -> V_80 = NULL ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 )
{
struct V_73 * V_181 ;
int V_191 ;
V_181 = V_3 -> V_80 ;
V_3 -> V_258 = ! V_181 || ! V_181 -> V_90 ;
if ( V_181 )
V_191 = V_181 -> V_191 != 0 ?
V_181 -> V_191 : V_3 -> V_5 -> V_259 ;
else
V_191 = V_3 -> V_5 -> V_259 ;
F_125 ( V_3 , V_191 ) ;
return 0 ;
}
static void F_126 ( struct V_2 * V_3 )
{
}
static void F_127 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_260 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
F_82 ( V_22 -> V_260 [ V_68 ] ) ;
V_22 -> V_260 [ V_68 ] = NULL ;
}
F_82 ( V_22 -> V_260 ) ;
V_22 -> V_260 = NULL ;
}
static int F_128 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_261 <= 0 )
return 0 ;
V_22 -> V_260 =
F_116 ( sizeof( * V_22 -> V_260 ) * V_22 -> V_237 ,
V_204 ) ;
if ( ! V_22 -> V_260 )
return - V_262 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_22 -> V_260 [ V_68 ] =
F_93 ( sizeof( * V_22 -> V_260 [ V_68 ] ) *
V_22 -> V_263 , V_204 ) ;
if ( ! V_22 -> V_260 [ V_68 ] )
goto V_264;
}
return 0 ;
V_264:
F_127 ( V_22 ) ;
return - V_262 ;
}
static void F_129 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_265 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
F_82 ( V_22 -> V_265 [ V_68 ] ) ;
V_22 -> V_265 [ V_68 ] = NULL ;
}
F_82 ( V_22 -> V_265 ) ;
V_22 -> V_265 = NULL ;
}
static int F_130 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_261 <= 0 )
return 0 ;
V_22 -> V_265 = F_116 ( sizeof( * V_22 -> V_265 ) * V_22 -> V_237 ,
V_204 ) ;
if ( ! V_22 -> V_265 )
return - V_262 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_22 -> V_265 [ V_68 ] = F_93 ( sizeof( * V_22 -> V_265 [ V_68 ] ) *
V_22 -> V_261 , V_204 ) ;
if ( ! V_22 -> V_265 [ V_68 ] )
goto V_264;
}
return 0 ;
V_264:
F_129 ( V_22 ) ;
return - V_262 ;
}
static int F_131 ( struct V_1 * V_22 ,
struct V_140 * V_132 , struct V_8 * V_9 )
{
struct V_266 * V_267 ;
T_5 V_268 ;
T_4 V_269 ;
V_267 = V_22 -> V_260 [ V_9 -> V_134 ] ;
V_269 = F_132 ( V_132 -> V_270 [ 0 ] . V_271 ) ;
V_268 = F_133 ( V_22 -> V_29 , V_267 , V_269 ,
V_272 ) ;
if ( F_134 ( & V_22 -> V_29 -> V_30 , V_268 ) ) {
V_132 -> V_270 -> V_273 = 0 ;
return - 1 ;
}
V_132 -> V_270 -> V_273 = F_135 ( V_268 ) ;
return 0 ;
}
static void F_136 ( struct V_1 * V_22 ,
struct V_140 * V_132 )
{
struct V_266 * V_274 ;
T_5 V_268 ;
T_4 V_269 ;
V_274 = V_132 -> V_270 ;
V_268 = F_137 ( V_274 -> V_273 ) ;
V_269 = F_132 ( V_132 -> V_270 [ 0 ] . V_271 ) ;
F_138 ( V_22 -> V_29 , V_268 , V_269 , V_272 ) ;
}
static int F_139 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_275 * V_274 , * V_267 ;
T_5 V_268 ;
T_4 V_276 ;
V_274 = & V_9 -> V_277 [ V_22 -> V_278 - 1 ] ;
V_267 = V_22 -> V_265 [ V_9 -> V_134 ] ;
V_274 -> V_279 = F_140 ( V_280 ) ;
V_276 = sizeof( * V_274 ) *
( F_98 ( V_9 -> V_125 . V_281 ) - V_22 -> V_278 ) ;
V_274 -> V_282 = F_140 ( V_276 ) ;
V_268 = F_133 ( V_22 -> V_29 , V_267 , V_276 ,
V_272 ) ;
if ( F_134 ( & V_22 -> V_29 -> V_30 , V_268 ) ) {
V_274 -> V_283 = F_135 ( 0 ) ;
return - 1 ;
}
V_274 -> V_283 = F_135 ( V_268 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_275 * V_274 ;
if ( F_98 ( V_9 -> V_125 . V_281 ) <= V_22 -> V_278 )
return;
V_274 = & V_9 -> V_277 [ V_22 -> V_278 - 1 ] ;
F_138 ( V_22 -> V_29 , F_137 ( V_274 -> V_283 ) ,
F_132 ( V_274 -> V_282 ) , V_272 ) ;
}
static int F_142 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_284 * V_285 ,
struct V_140 * V_286 ,
struct V_73 * V_30 )
{
int V_287 ;
int V_288 = 0 ;
T_4 V_289 = 0 ;
switch ( V_286 -> V_290 . V_291 ) {
case V_292 :
switch ( V_286 -> V_290 . V_49 ) {
case V_293 :
break;
case V_294 :
V_285 -> V_295 |= V_296 ;
if ( V_286 -> V_290 . V_297 !=
V_298 ) {
memset ( V_285 -> V_299 , 0 ,
V_300 ) ;
break;
}
V_287 = V_286 -> V_290 . V_15 ;
if ( V_287 > V_300 )
V_287 = V_300 ;
if ( V_287 > sizeof( V_286 -> V_290 . V_301 ) )
V_287 =
sizeof( V_286 -> V_290 . V_301 ) ;
memcpy ( V_285 -> V_299 ,
V_286 -> V_290 . V_301 , V_287 ) ;
V_288 = 1 ;
break;
case V_302 :
V_288 = 1 ;
break;
case V_303 :
V_288 = 1 ;
break;
case V_304 :
V_288 = 1 ;
break;
case V_305 :
V_288 = 1 ;
break;
default:
V_288 = 1 ;
break;
}
break;
case V_306 :
switch ( V_286 -> V_290 . V_49 ) {
case V_307 :
case V_308 :
case V_309 :
V_288 = 1 ;
break;
case V_310 :
V_285 -> V_295 = ( V_311 << 16 ) ;
V_285 -> V_295 |= ( V_312 << 8 ) ;
V_289 = F_143 (
& V_286 -> V_290 . V_313 [ 0 ] ) ;
F_144 ( V_285 , V_289 ) ;
break;
case V_314 :
case V_315 :
case V_316 :
if ( V_30 -> V_74 && V_30 -> V_90 ) {
V_285 -> V_295 = V_317 << 16 ;
V_30 -> V_192 = 1 ;
V_22 -> V_250 = 1 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_73 , V_243 ) ;
} else
V_288 = 1 ;
break;
default:
V_288 = 1 ;
}
break;
case V_318 :
break;
case V_319 :
break;
case V_320 :
V_288 = 1 ;
break;
case V_321 :
break;
default:
V_288 = 1 ;
break;
}
return V_288 ;
}
static void F_145 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_322 = false ;
V_9 -> V_10 = V_11 ;
F_146 () ;
if ( V_9 -> V_12 ) {
V_322 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_78 ;
struct V_73 * V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_59 ( & V_30 -> V_323 ) )
V_322 = true ;
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
if ( V_322 )
F_147 ( & V_22 -> V_324 ) ;
}
static void F_148 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_145 ( V_22 , V_9 ) ;
F_149 ( V_22 , V_9 ) ;
}
static void F_150 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_284 * V_285 )
{
F_148 ( V_22 , V_9 ) ;
if ( V_285 && V_285 -> V_325 )
V_285 -> V_325 ( V_285 ) ;
}
static void F_151 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_152 ( & V_9 -> V_326 , V_327 ) ;
F_153 ( F_50 () , V_22 -> V_328 , & V_9 -> V_326 ) ;
}
static void F_154 ( struct V_284 * V_285 )
{
V_285 -> V_295 = V_329 << 16 ;
}
static void F_155 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_284 * V_285 )
{
F_154 ( V_285 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_74 ,
V_9 -> V_145 . V_146 , V_9 -> V_24 -> V_38 ) ;
F_148 ( V_22 , V_9 ) ;
}
static void F_156 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
struct V_73 * V_30 )
{
struct V_140 * V_286 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
if ( F_49 ( V_286 -> V_290 . V_291 == 0 &&
V_286 -> V_290 . V_49 == 0 ) )
return F_150 ( V_22 , V_9 , V_285 ) ;
if ( F_32 ( V_30 ) &&
V_286 -> V_290 . V_291 ==
V_306 ) {
if ( V_286 -> V_290 . V_49 ==
V_316 ) {
V_30 -> V_91 = 0 ;
V_30 -> V_184 = 0 ;
}
return F_151 ( V_22 , V_9 ) ;
}
if ( F_142 ( V_22 , V_9 , V_285 , V_286 , V_30 ) )
return F_151 ( V_22 , V_9 ) ;
return F_150 ( V_22 , V_9 , V_285 ) ;
}
static int F_157 ( struct V_1 * V_22 ,
struct V_8 * V_132 )
{
T_1 V_330 = V_132 -> V_24 -> V_38 ;
switch ( V_330 ) {
case V_331 :
case V_332 :
return 0 ;
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_75 ,
V_330 ) ;
break;
}
return - V_330 ;
}
static void F_158 ( struct V_8 * V_132 )
{
struct V_284 * V_285 ;
struct V_1 * V_22 ;
struct V_338 * V_339 ;
struct V_73 * V_30 ;
struct V_140 * V_286 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_340 ;
V_339 = V_132 -> V_24 ;
V_285 = V_132 -> V_10 ;
V_22 = V_132 -> V_22 ;
if ( ! V_285 -> V_42 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_150 ( V_22 , V_132 , V_285 ) ;
}
V_30 = V_285 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_150 ( V_22 , V_132 , V_285 ) ;
}
V_286 = & V_22 -> V_138 [ V_132 -> V_134 ] ;
F_159 ( V_285 ) ;
if ( ( V_132 -> V_151 == V_341 ) &&
( F_98 ( V_132 -> V_125 . V_281 ) > V_22 -> V_278 ) )
F_141 ( V_22 , V_132 ) ;
if ( ( V_132 -> V_151 == V_155 ) &&
( V_286 -> V_270 [ 0 ] . V_342 == V_343 ) )
F_136 ( V_22 , V_286 ) ;
V_285 -> V_295 = ( V_311 << 16 ) ;
V_285 -> V_295 |= ( V_312 << 8 ) ;
if ( V_132 -> V_151 == V_155 || V_132 -> V_151 == V_152 ) {
if ( V_30 -> V_74 && V_30 -> V_90 &&
V_30 -> V_192 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_150 ( V_22 , V_132 , V_285 ) ;
}
if ( F_49 ( V_132 -> V_236 != NULL ) )
F_47 ( & V_132 -> V_236 -> V_257 ) ;
}
if ( F_46 ( V_339 -> V_36 == V_344 ) ) {
V_285 -> V_295 = V_317 << 16 ;
return F_150 ( V_22 , V_132 , V_285 ) ;
}
if ( ( F_46 ( F_5 ( V_132 ) ) ) ) {
if ( V_132 -> V_13 )
return F_150 ( V_22 , V_132 , V_285 ) ;
if ( V_132 -> V_12 )
return F_155 ( V_22 , V_132 , V_285 ) ;
}
if ( V_132 -> V_151 == V_155 )
return F_156 ( V_22 , V_132 , V_285 , V_30 ) ;
F_144 ( V_285 , V_339 -> V_345 ) ;
if ( V_339 -> V_36 == 0 )
return F_150 ( V_22 , V_132 , V_285 ) ;
if ( V_132 -> V_151 == V_152 ) {
struct V_131 * V_9 = & V_22 -> V_133 [ V_132 -> V_134 ] ;
V_132 -> V_125 . V_126 = F_160 ( V_285 ) ;
V_132 -> V_125 . V_281 = F_161 ( V_132 -> V_125 . V_126 ) ;
V_132 -> V_145 . V_346 = F_98 ( V_9 -> V_347 ) &
V_348 ;
V_132 -> V_125 . V_349 = V_9 -> V_349 ;
memcpy ( V_132 -> V_125 . V_350 . V_351 , V_9 -> V_352 , 8 ) ;
memcpy ( V_132 -> V_145 . V_146 , V_9 -> V_146 , V_132 -> V_145 . V_346 ) ;
if ( F_32 ( V_30 ) ) {
if ( V_339 -> V_36 == V_353 )
V_30 -> V_91 = 0 ;
return F_151 ( V_22 , V_132 ) ;
}
}
switch ( V_339 -> V_36 ) {
case V_37 :
V_285 -> V_295 |= V_339 -> V_38 ;
if ( V_300 < sizeof( V_339 -> V_26 ) )
V_340 = V_300 ;
else
V_340 = sizeof( V_339 -> V_26 ) ;
if ( V_339 -> V_25 < V_340 )
V_340 = V_339 -> V_25 ;
memcpy ( V_285 -> V_299 , V_339 -> V_26 , V_340 ) ;
if ( V_339 -> V_38 )
F_6 ( V_339 -> V_26 , V_340 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_339 -> V_38 == V_296 ) {
if ( V_16 == V_354 ) {
V_285 -> V_295 |= V_355 << 16 ;
break;
}
break;
}
if ( V_339 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_76
L_77
L_78 ,
V_132 , V_339 -> V_38 ,
V_16 , V_17 , V_18 ,
V_285 -> V_295 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_79
L_80 , V_132 ) ,
V_285 -> V_295 = V_317 << 16 ;
}
break;
case V_356 :
break;
case V_357 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_81 , V_132 -> V_145 . V_146 ) ;
break;
case V_358 : {
V_285 -> V_295 = V_317 << 16 ;
}
break;
case V_359 :
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_82 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_361 :
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_83 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_362 :
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_84 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_363 :
return F_155 ( V_22 , V_132 , V_285 ) ;
case V_364 :
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_85 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_365 :
V_285 -> V_295 = V_355 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_86 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_366 :
V_285 -> V_295 = V_367 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_87 ,
V_132 -> V_145 . V_146 ) ;
break;
case V_368 :
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_88 ) ;
break;
case V_369 :
if ( F_157 ( V_22 , V_132 ) )
V_285 -> V_295 = V_360 << 16 ;
break;
case V_353 :
V_285 -> V_295 = V_355 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_89 , V_132 ) ;
break;
default:
V_285 -> V_295 = V_360 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_90 ,
V_132 , V_339 -> V_36 ) ;
}
return F_150 ( V_22 , V_132 , V_285 ) ;
}
static void F_162 ( struct V_370 * V_29 ,
struct V_8 * V_9 , int V_371 , int V_372 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_371 ; V_68 ++ )
F_138 ( V_29 , ( V_373 ) F_137 ( V_9 -> V_277 [ V_68 ] . V_283 ) ,
F_132 ( V_9 -> V_277 [ V_68 ] . V_282 ) ,
V_372 ) ;
}
static int F_163 ( struct V_370 * V_29 ,
struct V_8 * V_132 ,
unsigned char * V_45 ,
T_3 V_374 ,
int V_372 )
{
T_5 V_375 ;
if ( V_374 == 0 || V_372 == V_376 ) {
V_132 -> V_125 . V_126 = 0 ;
V_132 -> V_125 . V_281 = F_161 ( 0 ) ;
return 0 ;
}
V_375 = F_133 ( V_29 , V_45 , V_374 , V_372 ) ;
if ( F_134 ( & V_29 -> V_30 , V_375 ) ) {
V_132 -> V_125 . V_126 = 0 ;
V_132 -> V_125 . V_281 = F_161 ( 0 ) ;
return - 1 ;
}
V_132 -> V_277 [ 0 ] . V_283 = F_135 ( V_375 ) ;
V_132 -> V_277 [ 0 ] . V_282 = F_140 ( V_374 ) ;
V_132 -> V_277 [ 0 ] . V_279 = F_140 ( V_377 ) ;
V_132 -> V_125 . V_126 = 1 ;
V_132 -> V_125 . V_281 = F_161 ( 1 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_114 , unsigned long V_378 )
{
F_165 ( V_379 ) ;
V_9 -> V_380 = & V_379 ;
F_60 ( V_22 , V_9 , V_114 ) ;
if ( V_378 == V_381 ) {
F_166 ( & V_379 ) ;
return V_382 ;
}
if ( ! F_167 ( & V_379 ,
F_168 ( V_378 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_91 ) ;
return - V_383 ;
}
return V_382 ;
}
static int F_169 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_114 , unsigned long V_378 )
{
if ( F_46 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_344 ;
return V_382 ;
}
return F_164 ( V_22 , V_9 , V_114 , V_378 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_384 ;
T_4 V_21 , * F_13 ;
V_384 = F_170 () ;
F_13 = F_171 ( V_22 -> F_13 , V_384 ) ;
V_21 = * F_13 ;
F_172 () ;
return V_21 ;
}
static int F_173 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_372 , unsigned long V_378 )
{
int V_385 = 10 , V_386 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_169 ( V_22 , V_9 , V_128 ,
V_378 ) ;
if ( V_21 )
break;
V_386 ++ ;
if ( V_386 > 3 ) {
F_109 ( V_385 ) ;
if ( V_385 < 1000 )
V_385 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_386 <= V_387 );
F_162 ( V_22 -> V_29 , V_9 , 1 , V_372 ) ;
if ( V_386 > V_387 )
V_21 = - V_388 ;
return V_21 ;
}
static void F_174 ( struct V_1 * V_22 , char * V_389 ,
struct V_8 * V_9 )
{
const T_1 * V_142 = V_9 -> V_145 . V_146 ;
const T_1 * V_105 = V_9 -> V_125 . V_350 . V_351 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_92 ,
V_389 , V_105 , V_142 ) ;
}
static void F_175 ( struct V_1 * V_22 ,
struct V_8 * V_132 )
{
const struct V_338 * V_339 = V_132 -> V_24 ;
struct V_42 * V_390 = & V_132 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_339 -> V_36 ) {
case V_37 :
if ( V_339 -> V_25 > sizeof( V_339 -> V_26 ) )
V_23 = sizeof( V_339 -> V_26 ) ;
else
V_23 = V_339 -> V_25 ;
F_6 ( V_339 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_174 ( V_22 , L_93 , V_132 ) ;
if ( V_339 -> V_38 == V_296 )
F_9 ( V_390 , L_94 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_390 , L_95 , V_339 -> V_38 ) ;
if ( V_339 -> V_38 == 0 )
F_9 ( V_390 , L_96
L_97
L_98
L_99 ) ;
break;
case V_356 :
break;
case V_357 :
F_174 ( V_22 , L_100 , V_132 ) ;
break;
case V_358 : {
F_174 ( V_22 , L_101 , V_132 ) ;
F_9 ( V_390 , L_102 ) ;
}
break;
case V_359 :
F_174 ( V_22 , L_103 , V_132 ) ;
break;
case V_361 :
F_174 ( V_22 , L_104 , V_132 ) ;
break;
case V_362 :
F_174 ( V_22 , L_105 , V_132 ) ;
break;
case V_363 :
F_174 ( V_22 , L_106 , V_132 ) ;
break;
case V_364 :
F_174 ( V_22 , L_107 , V_132 ) ;
break;
case V_365 :
F_174 ( V_22 , L_108 , V_132 ) ;
break;
case V_366 :
F_174 ( V_22 , L_109 , V_132 ) ;
break;
case V_368 :
F_174 ( V_22 , L_110 , V_132 ) ;
break;
case V_344 :
F_174 ( V_22 , L_111 , V_132 ) ;
break;
default:
F_174 ( V_22 , L_112 , V_132 ) ;
F_9 ( V_390 , L_113 ,
V_339 -> V_36 ) ;
}
}
static int F_176 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_391 , unsigned char * V_45 ,
unsigned char V_392 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
if ( F_178 ( V_9 , V_393 , V_22 , V_45 , V_392 ,
V_391 , V_72 , V_394 ) ) {
V_21 = - 1 ;
goto V_395;
}
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_179 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_398 , int V_114 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
( void ) F_178 ( V_9 , V_398 , V_22 , NULL , 0 , 0 ,
V_72 , V_399 ) ;
V_21 = F_169 ( V_22 , V_9 , V_114 , V_381 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_114 ) ;
goto V_395;
}
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_106 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_73 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_400 = false ;
struct V_140 * V_286 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
struct V_137 * V_401 = (struct V_137 * ) V_286 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_151 ) {
case V_341 :
case V_402 :
V_400 = ! memcmp ( V_72 , & V_9 -> V_125 . V_350 . V_351 ,
sizeof( V_9 -> V_125 . V_350 . V_351 ) ) ;
break;
case V_152 :
case V_155 :
if ( V_9 -> V_236 == V_30 ) {
V_400 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_235 && ! V_400 ; V_68 ++ ) {
V_400 = V_30 -> V_236 [ V_68 ] == V_9 -> V_236 ;
}
}
break;
case V_157 :
for ( V_68 = 0 ; V_68 < V_30 -> V_235 && ! V_400 ; V_68 ++ ) {
V_400 = V_30 -> V_236 [ V_68 ] -> V_188 ==
F_132 ( V_401 -> V_403 ) ;
}
break;
case 0 :
V_400 = false ;
break;
default:
F_75 ( & V_22 -> V_29 -> V_30 , L_115 ,
V_9 -> V_151 ) ;
F_180 () ;
}
return V_400 ;
}
static int F_181 ( struct V_1 * V_22 , struct V_73 * V_30 ,
unsigned char * V_72 , T_1 V_398 , int V_114 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_182 ( & V_22 -> V_404 ) == - V_405 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_116 ) ;
return - V_405 ;
}
F_77 ( F_21 ( & V_30 -> V_323 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
int V_240 = F_105 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 && F_106 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_78 ;
V_9 -> V_13 = V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
F_57 ( & V_30 -> V_323 ) ;
else
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_107 ( V_22 , V_9 ) ;
}
V_21 = F_179 ( V_22 , V_72 , V_398 , V_114 ) ;
if ( ! V_21 )
F_183 ( V_22 -> V_324 ,
F_21 ( & V_30 -> V_323 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_46 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_117 ) ;
V_21 = - V_81 ;
}
if ( F_46 ( V_21 ) )
F_123 ( & V_30 -> V_323 , 0 ) ;
else
F_184 ( V_22 , V_72 , 0 ) ;
F_185 ( & V_22 -> V_404 ) ;
return V_21 ;
}
static void F_186 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_83 )
{
int V_21 ;
unsigned char * V_45 ;
* V_83 = V_84 ;
V_45 = F_116 ( 64 , V_204 ) ;
if ( ! V_45 )
return;
if ( ! F_187 ( V_22 , V_72 ,
V_406 ) )
goto exit;
V_21 = F_176 ( V_22 , V_72 , V_407 |
V_406 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_83 = V_45 [ 8 ] ;
if ( * V_83 > V_84 )
* V_83 = V_84 ;
exit:
F_82 ( V_45 ) ;
return;
}
static void F_188 ( struct V_1 * V_22 , int V_21 ,
struct V_221 * V_408 )
{
struct V_223 * V_224 = & V_408 -> V_225 [ 0 ] ;
int V_222 , V_409 , V_410 ;
T_6 V_411 , V_230 , V_412 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_96 ( & V_22 -> V_29 -> V_30 , L_118 ,
F_132 ( V_408 -> V_413 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_119 ,
F_132 ( V_408 -> V_414 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_120 ,
F_137 ( V_408 -> V_415 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_121 ,
V_408 -> V_416 ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_122 ,
V_408 -> V_417 ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_123 ,
F_98 ( V_408 -> V_418 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_137 ( V_408 -> V_419 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_125 ,
F_137 ( V_408 -> V_420 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_126 ,
F_98 ( V_408 -> V_227 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_98 ( V_408 -> V_228 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_128 ,
F_98 ( V_408 -> V_230 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_129 ,
F_98 ( V_408 -> V_231 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_130 ,
F_98 ( V_408 -> V_78 ) ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_131 ,
F_98 ( V_408 -> V_78 ) &
V_421 ? L_132 : L_133 ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_134 ,
F_98 ( V_408 -> V_422 ) ) ;
V_411 = F_98 ( V_408 -> V_231 ) ;
for ( V_222 = 0 ; V_222 < V_411 ; V_222 ++ ) {
F_96 ( & V_22 -> V_29 -> V_30 , L_135 , V_222 ) ;
V_230 = F_98 ( V_408 -> V_230 ) ;
for ( V_409 = 0 ; V_409 < V_230 ; V_409 ++ ) {
F_96 ( & V_22 -> V_29 -> V_30 , L_136 , V_409 ) ;
V_412 =
F_98 ( V_408 -> V_227 ) ;
for ( V_410 = 0 ; V_410 < V_412 ; V_410 ++ , V_224 ++ )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_137 ,
V_410 , V_224 -> V_188 ,
V_224 -> V_423 [ 0 ] , V_224 -> V_423 [ 1 ] ) ;
V_412 =
F_98 ( V_408 -> V_228 ) ;
for ( V_410 = 0 ; V_410 < V_412 ; V_410 ++ , V_224 ++ )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_138 ,
V_410 , V_224 -> V_188 ,
V_224 -> V_423 [ 0 ] , V_224 -> V_423 [ 1 ] ) ;
}
}
}
static int F_189 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_424 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
if ( F_178 ( V_9 , V_425 , V_22 , & V_424 -> V_187 ,
sizeof( V_424 -> V_187 ) , 0 ,
V_72 , V_394 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_139 ) ;
F_107 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_395;
}
F_107 ( V_22 , V_9 ) ;
if ( F_132 ( V_424 -> V_187 . V_413 ) >
sizeof( V_424 -> V_187 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_140 ) ;
V_21 = - 1 ;
}
F_188 ( V_22 , V_21 , & V_424 -> V_187 ) ;
return V_21 ;
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_190 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_426 ,
struct V_427 * V_45 , T_3 V_392 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
V_21 = F_178 ( V_9 , V_428 , V_22 , V_45 , V_392 ,
0 , V_159 , V_394 ) ;
if ( V_21 )
goto V_395;
V_9 -> V_145 . V_146 [ 2 ] = V_426 & 0xff ;
V_9 -> V_145 . V_146 [ 9 ] = ( V_426 >> 8 ) & 0xff ;
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_191 ( struct V_1 * V_22 ,
struct V_429 * V_45 , T_3 V_392 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
V_21 = F_178 ( V_9 , V_430 , V_22 , V_45 , V_392 ,
0 , V_159 , V_394 ) ;
if ( V_21 )
goto V_395;
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_192 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_426 ,
struct V_431 * V_45 , T_3 V_392 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
V_21 = F_178 ( V_9 , V_432 , V_22 , V_45 , V_392 ,
0 , V_159 , V_394 ) ;
if ( V_21 )
goto V_395;
V_9 -> V_145 . V_146 [ 2 ] = V_426 & 0xff ;
V_9 -> V_145 . V_146 [ 9 ] = ( V_426 >> 8 ) & 0xff ;
F_173 ( V_22 , V_9 , V_396 ,
V_397 ) ;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static void F_193 ( struct V_1 * V_22 ,
unsigned char * V_72 ,
struct V_433 * V_434 , int V_435 ,
struct V_73 * V_436 )
{
int V_21 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_338 * V_339 = NULL ;
struct V_437 * V_438 = NULL ;
struct V_431 * V_439 = NULL ;
struct V_440 * V_441 = & V_434 -> V_350 [ V_435 ] ;
T_6 V_426 = 0 ;
V_426 = F_194 ( & V_441 -> V_86 [ 0 ] ) ;
if ( V_426 == 0xFF00 || F_195 ( & V_441 -> V_86 [ 0 ] ) ) {
V_21 = V_382 ;
goto V_395;
}
V_438 = F_116 ( sizeof( * V_438 ) , V_204 ) ;
if ( ! V_438 )
goto V_395;
V_439 = F_116 ( sizeof( * V_439 ) , V_204 ) ;
if ( ! V_439 )
goto V_395;
V_21 = F_192 ( V_22 , V_72 , V_426 ,
V_439 , sizeof( * V_439 ) ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_141 ,
V_243 , V_436 -> V_168 , V_426 ) ;
goto V_395;
}
V_9 = F_177 ( V_22 ) ;
V_21 = F_178 ( V_9 , V_442 , V_22 , V_438 ,
sizeof( * V_438 ) , 0 , V_159 , V_394 ) ;
if ( V_21 )
goto V_395;
if ( V_439 -> V_97 [ 1 ] == 'E' )
V_9 -> V_145 . V_146 [ 5 ] = V_439 -> V_443 ;
else
V_9 -> V_145 . V_146 [ 5 ] = 0 ;
V_21 = F_173 ( V_22 , V_9 , V_396 ,
V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 && V_339 -> V_36 != V_356 ) {
V_21 = - 1 ;
goto V_395;
}
V_436 -> V_93 [ V_439 -> V_444 ] = V_438 -> V_445 ;
memcpy ( & V_436 -> V_97 [ V_439 -> V_444 ] ,
V_438 -> V_97 , sizeof( V_438 -> V_97 ) ) ;
V_21 = V_382 ;
V_395:
F_82 ( V_438 ) ;
F_82 ( V_439 ) ;
if ( V_9 )
F_107 ( V_22 , V_9 ) ;
if ( V_21 != V_382 )
F_71 ( V_183 , V_22 , V_436 ,
L_142 ) ;
}
static T_5 F_196 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_433 * V_446 ;
T_4 V_447 ;
T_5 V_448 = 0 ;
int V_68 ;
V_446 = F_116 ( sizeof( * V_446 ) , V_204 ) ;
if ( ! V_446 )
return 0 ;
if ( F_197 ( V_22 , V_446 , sizeof( * V_446 ) ) ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_143 ) ;
F_82 ( V_446 ) ;
return 0 ;
}
V_447 = F_198 ( V_446 -> V_449 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_447 ; V_68 ++ )
if ( ! memcmp ( & V_446 -> V_350 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_448 = F_199 ( & V_446 -> V_350 [ V_68 ] . V_450 [ 0 ] ) ;
break;
}
F_82 ( V_446 ) ;
return V_448 ;
}
static void F_200 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_448 = 0 ;
if ( F_64 ( V_72 ) ) {
struct V_427 * V_451 ;
V_451 = F_116 ( sizeof( * V_451 ) , V_204 ) ;
if ( ! V_451 )
return;
V_21 = F_190 ( V_22 ,
V_72 , 0 , V_451 , sizeof( * V_451 ) ) ;
if ( V_21 == 0 ) {
V_448 = F_199 ( V_451 -> V_452 ) ;
V_22 -> V_89 = V_448 ;
}
F_82 ( V_451 ) ;
} else
V_448 = F_196 ( V_22 , V_72 ) ;
V_30 -> V_89 = V_448 ;
}
static bool F_187 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_391 )
{
int V_21 ;
int V_68 ;
int V_453 ;
unsigned char * V_45 , V_392 ;
V_45 = F_116 ( 256 , V_204 ) ;
if ( ! V_45 )
return false ;
V_21 = F_176 ( V_22 , V_72 ,
V_407 | V_454 ,
V_45 , V_455 ) ;
if ( V_21 != 0 )
goto V_456;
V_453 = V_45 [ 3 ] ;
if ( ( V_453 + V_455 ) <= 255 )
V_392 = V_453 + V_455 ;
else
V_392 = 255 ;
V_21 = F_176 ( V_22 , V_72 ,
V_407 | V_454 ,
V_45 , V_392 ) ;
if ( V_21 != 0 )
goto V_456;
V_453 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_453 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_391 )
goto V_457;
V_456:
F_82 ( V_45 ) ;
return false ;
V_457:
F_82 ( V_45 ) ;
return true ;
}
static void F_201 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_424 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_458 ;
V_424 -> V_175 = 0 ;
V_424 -> V_91 = 0 ;
V_424 -> V_184 = 0 ;
V_45 = F_116 ( 64 , V_204 ) ;
if ( ! V_45 )
return;
if ( ! F_187 ( V_22 , V_72 , V_459 ) )
goto V_395;
V_21 = F_176 ( V_22 , V_72 ,
V_407 | V_459 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_395;
#define F_202 4
#define F_203 0x01
#define F_204 0x02
V_458 = V_45 [ F_202 ] ;
V_424 -> V_175 =
! ! ( V_458 & F_203 ) ;
if ( V_424 -> V_175 ) {
V_424 -> V_91 =
! ! ( V_458 & F_204 ) ;
if ( F_189 ( V_22 , V_72 , V_424 ) )
V_424 -> V_91 = 0 ;
}
V_424 -> V_184 = V_424 -> V_91 ;
V_395:
F_82 ( V_45 ) ;
return;
}
static int F_205 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_88 , int V_200 , int V_374 )
{
int V_21 ;
unsigned char * V_45 ;
if ( ! F_187 ( V_22 , V_72 , V_460 ) )
return 1 ;
V_45 = F_116 ( 64 , V_204 ) ;
if ( ! V_45 )
return - V_262 ;
V_21 = F_176 ( V_22 , V_72 , V_407 |
V_460 , V_45 , 64 ) ;
if ( V_21 == 0 ) {
if ( V_374 > 16 )
V_374 = 16 ;
memcpy ( V_88 , & V_45 [ 8 ] , V_374 ) ;
}
F_82 ( V_45 ) ;
return V_21 ;
}
static int F_206 ( struct V_1 * V_22 , int V_461 ,
void * V_45 , int V_392 ,
int V_462 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_338 * V_339 ;
V_9 = F_177 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_178 ( V_9 , V_461 ? V_463 : V_464 , V_22 ,
V_45 , V_392 , 0 , V_72 , V_394 ) ) {
V_21 = - 1 ;
goto V_395;
}
if ( V_462 )
V_9 -> V_145 . V_146 [ 1 ] = V_462 ;
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( V_21 )
goto V_395;
V_339 = V_9 -> V_24 ;
if ( V_339 -> V_36 != 0 &&
V_339 -> V_36 != V_356 ) {
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_465 * V_466 = V_45 ;
if ( V_466 -> V_467 != V_462 ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_144 ,
V_462 ,
V_466 -> V_467 ) ;
V_21 = - 1 ;
}
}
V_395:
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_197 ( struct V_1 * V_22 ,
struct V_433 * V_45 , int V_392 )
{
int V_21 ;
struct V_465 * V_468 ;
V_21 = F_206 ( V_22 , 0 , V_45 , V_392 ,
V_469 ) ;
if ( ! V_21 || ! V_470 )
return V_21 ;
V_468 = F_116 ( sizeof( * V_468 ) , V_204 ) ;
if ( ! V_468 )
return - V_262 ;
V_21 = F_206 ( V_22 , 0 , V_468 , sizeof( * V_468 ) , 0 ) ;
if ( ! V_21 ) {
int V_68 ;
T_4 V_471 ;
memcpy ( V_45 , V_468 , 8 ) ;
V_471 = F_207 ( * ( ( V_472 * ) V_468 -> V_449 ) ) / 8 ;
for ( V_68 = 0 ; V_68 < V_471 ; V_68 ++ )
memcpy ( V_45 -> V_350 [ V_68 ] . V_86 , V_468 -> V_350 [ V_68 ] , 8 ) ;
}
F_82 ( V_468 ) ;
return V_21 ;
}
static inline int F_208 ( struct V_1 * V_22 ,
struct V_465 * V_45 , int V_392 )
{
return F_206 ( V_22 , 1 , V_45 , V_392 , 0 ) ;
}
static inline void F_209 ( struct V_73 * V_42 ,
int V_103 , int V_104 , int V_105 )
{
V_42 -> V_103 = V_103 ;
V_42 -> V_104 = V_104 ;
V_42 -> V_105 = V_105 ;
}
static int F_210 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_473 ;
unsigned char * V_45 ;
V_45 = F_116 ( 64 , V_204 ) ;
if ( ! V_45 )
return V_207 ;
if ( ! F_187 ( V_22 , V_72 , V_474 ) )
goto V_475;
V_21 = F_176 ( V_22 , V_72 , V_407 | V_474 ,
V_45 , V_455 ) ;
if ( V_21 != 0 )
goto V_475;
V_473 = V_45 [ 3 ] ;
V_21 = F_176 ( V_22 , V_72 , V_407 | V_474 ,
V_45 , V_473 + V_455 ) ;
if ( V_21 != 0 )
goto V_475;
V_49 = V_45 [ 4 ] ;
F_82 ( V_45 ) ;
return V_49 ;
V_475:
F_82 ( V_45 ) ;
return V_207 ;
}
static unsigned char F_211 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_476 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_477 = 0 ;
T_6 V_478 ;
T_1 V_479 ;
#define F_212 0x04
#define F_213 0x04
#define F_214 0x02
V_9 = F_177 ( V_22 ) ;
( void ) F_178 ( V_9 , V_480 , V_22 , NULL , 0 , 0 , V_72 , V_394 ) ;
V_21 = F_169 ( V_22 , V_9 , V_128 ,
V_397 ) ;
if ( V_21 ) {
F_107 ( V_22 , V_9 ) ;
return V_207 ;
}
V_476 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_476 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_478 = V_9 -> V_24 -> V_36 ;
V_479 = V_9 -> V_24 -> V_38 ;
F_107 ( V_22 , V_9 ) ;
V_477 = F_210 ( V_22 , V_72 ) ;
switch ( V_477 ) {
case V_481 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
return V_477 ;
case V_207 :
if ( ( V_18 == F_213 ) ||
( V_18 == F_214 ) )
return V_477 ;
break;
default:
break;
}
return V_208 ;
}
static int F_215 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_338 * V_339 ;
int V_21 = 0 ;
T_5 V_349 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_177 ( V_22 ) ;
( void ) F_178 ( V_9 , V_482 , V_22 , & V_349 , 0 , 0 , V_72 , V_399 ) ;
( void ) F_169 ( V_22 , V_9 , V_128 ,
V_397 ) ;
V_339 = V_9 -> V_24 ;
switch ( V_339 -> V_36 ) {
case V_358 :
V_21 = 0 ;
break;
case V_368 :
case V_364 :
V_21 = 1 ;
break;
case V_369 :
V_21 = F_157 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_216 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_73 * V_424 ,
unsigned char * V_483 )
{
#define F_217 43
#define F_218 "$DR-10"
#define F_219 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_220 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_484 ;
unsigned char * V_485 ;
int V_21 = 0 ;
V_484 = F_116 ( F_220 , V_204 ) ;
if ( ! V_484 ) {
V_21 = - V_262 ;
goto V_486;
}
if ( F_176 ( V_22 , V_72 , 0 , V_484 ,
( unsigned char ) F_220 ) != 0 ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_145 ,
V_243 ) ;
V_21 = V_487 ;
goto V_486;
}
F_221 ( & V_484 [ 8 ] , 8 ) ;
F_221 ( & V_484 [ 16 ] , 16 ) ;
V_424 -> V_106 = ( V_484 [ 0 ] & 0x1f ) ;
memcpy ( V_424 -> V_72 , V_72 , 8 ) ;
memcpy ( V_424 -> V_173 , & V_484 [ 8 ] ,
sizeof( V_424 -> V_173 ) ) ;
memcpy ( V_424 -> V_174 , & V_484 [ 16 ] ,
sizeof( V_424 -> V_174 ) ) ;
V_424 -> V_488 = V_484 [ 2 ] ;
memset ( V_424 -> V_88 , 0 ,
sizeof( V_424 -> V_88 ) ) ;
if ( F_205 ( V_22 , V_72 , V_424 -> V_88 , 8 ,
sizeof( V_424 -> V_88 ) ) )
F_75 ( & V_22 -> V_29 -> V_30 ,
L_146 ,
V_22 -> V_110 , V_243 ,
V_22 -> V_59 -> V_102 ,
V_424 -> V_104 , V_424 -> V_105 ,
F_43 ( V_424 -> V_106 ) ,
V_424 -> V_174 ) ;
if ( ( V_424 -> V_106 == V_108 ||
V_424 -> V_106 == V_109 ) &&
F_31 ( V_72 ) ) {
unsigned char V_201 ;
F_186 ( V_22 , V_72 , & V_424 -> V_83 ) ;
if ( V_22 -> V_489 & V_490 )
F_201 ( V_22 , V_72 , V_424 ) ;
V_201 = F_211 ( V_22 , V_72 ) ;
V_424 -> V_201 = V_201 ;
if ( V_201 == V_481 ) {
V_21 = V_481 ;
F_75 ( & V_22 -> V_29 -> V_30 ,
L_147 ,
V_243 ) ;
goto V_486;
}
} else {
V_424 -> V_83 = V_84 ;
V_424 -> V_175 = 0 ;
V_424 -> V_91 = 0 ;
V_424 -> V_184 = 0 ;
V_424 -> V_189 = 0 ;
V_424 -> V_201 = 0 ;
V_424 -> V_191 = V_22 -> V_237 ;
}
if ( V_483 ) {
V_485 = & V_484 [ F_217 ] ;
* V_483 = ( V_424 -> V_106 == V_170 &&
strncmp ( V_485 , F_218 ,
F_219 ) == 0 ) ;
}
F_82 ( V_484 ) ;
return 0 ;
V_486:
F_82 ( V_484 ) ;
return V_21 ;
}
static void F_222 ( struct V_1 * V_22 ,
struct V_73 * V_30 , T_1 * V_72 )
{
unsigned long V_78 ;
int V_21 , V_185 ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
V_21 = F_85 ( V_30 , V_22 -> V_30 , V_22 -> V_163 , & V_185 ) ;
if ( ( V_21 == F_88 || V_21 == F_89 ) &&
V_185 >= 0 && V_185 < V_22 -> V_163 ) {
V_30 -> V_491 = V_22 -> V_30 [ V_185 ] -> V_491 ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_98 , V_78 ) ;
V_30 -> V_491 =
F_215 ( V_22 , V_72 ) ;
if ( V_30 -> V_491 < 0 )
V_30 -> V_491 = 0 ;
}
}
static void F_223 ( struct V_1 * V_22 ,
T_1 * V_492 , struct V_73 * V_42 )
{
T_4 V_86 = F_143 ( V_492 ) ;
if ( ! F_31 ( V_492 ) ) {
if ( F_64 ( V_492 ) ) {
int V_103 = V_493 ;
if ( ! V_42 -> V_488 )
V_103 = V_494 ;
F_209 ( V_42 ,
V_103 , 0 , V_86 & 0x3fff ) ;
} else
F_209 ( V_42 ,
V_252 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_168 ) {
F_209 ( V_42 ,
V_495 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_209 ( V_42 , V_496 ,
0 , V_86 & 0x3fff ) ;
}
static int F_224 ( struct V_1 * V_22 ,
struct V_8 * V_497 , unsigned char * V_72 )
{
struct V_140 * V_286 =
& V_22 -> V_138 [ V_497 -> V_134 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_188 == F_132 ( V_286 -> V_498 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 0 ;
}
static int F_225 ( struct V_1 * V_22 , int V_499 ,
int V_68 , int V_447 , int V_500 )
{
int V_501 = V_447 + ( V_499 == 0 ) ;
if ( V_68 == V_499 )
return 0 ;
if ( V_68 < V_501 )
return 0 ;
if ( ( V_68 - V_447 - ( V_499 == 0 ) ) < V_500 )
return 0 ;
return 1 ;
}
static int F_226 ( struct V_1 * V_22 ,
struct V_433 * V_446 , T_4 * V_447 ,
struct V_465 * V_502 , T_4 * V_503 )
{
if ( F_197 ( V_22 , V_446 , sizeof( * V_446 ) ) ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_143 ) ;
return - 1 ;
}
* V_447 = F_207 ( * ( ( V_472 * ) V_446 -> V_449 ) ) / 24 ;
if ( * V_447 > V_504 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_148 ,
V_504 , * V_447 - V_504 ) ;
* V_447 = V_504 ;
}
if ( F_208 ( V_22 , V_502 , sizeof( * V_502 ) ) ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_149 ) ;
return - 1 ;
}
* V_503 = F_207 ( * ( ( V_472 * ) V_502 -> V_449 ) ) / 8 ;
if ( * V_503 > V_505 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_150
L_151 , V_505 ,
* V_503 - V_505 ) ;
* V_503 = V_505 ;
}
if ( * V_503 + * V_447 > V_504 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_152
L_151 , V_504 ,
* V_447 + * V_503 - V_504 ) ;
* V_503 = V_504 - * V_447 ;
}
return 0 ;
}
static T_1 * F_227 ( struct V_1 * V_22 , int V_499 ,
int V_68 , int V_447 , int V_503 ,
struct V_433 * V_506 ,
struct V_465 * V_507 )
{
int V_501 = V_447 + ( V_499 == 0 ) ;
int V_508 = V_447 + V_503 + ( V_499 == 0 ) ;
if ( V_68 == V_499 )
return V_159 ;
if ( V_68 < V_501 )
return & V_506 -> V_350 [ V_68 -
( V_499 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_508 )
return & V_507 -> V_350 [ V_68 - V_447 -
( V_499 == 0 ) ] [ 0 ] ;
F_180 () ;
return NULL ;
}
static void F_228 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_433 * V_434 , int V_435 ,
struct V_431 * V_439 )
{
int V_21 ;
struct V_440 * V_441 ;
if ( V_30 -> V_168 ) {
V_30 -> V_191 = 7 ;
return;
}
V_441 = & V_434 -> V_350 [ V_435 ] ;
V_30 -> V_188 = V_441 -> V_188 ;
if ( ( V_441 -> V_509 & 0x08 ) && V_30 -> V_188 )
V_30 -> V_189 = 1 ;
memset ( V_439 , 0 , sizeof( * V_439 ) ) ;
V_21 = F_192 ( V_22 , & V_441 -> V_86 [ 0 ] ,
F_194 ( & V_441 -> V_86 [ 0 ] ) , V_439 ,
sizeof( * V_439 ) ) ;
if ( ! V_21 )
#define F_229 2
#define F_230 7
V_30 -> V_191 =
F_98 ( V_439 -> V_510 ) -
F_229 ;
else
V_30 -> V_191 = F_230 ;
}
static void F_231 ( struct V_73 * V_424 ,
struct V_433 * V_434 , int V_435 ,
struct V_431 * V_439 )
{
struct V_440 * V_441 = & V_434 -> V_350 [ V_435 ] ;
if ( ( V_441 -> V_509 & 0x08 ) && V_424 -> V_188 )
V_424 -> V_189 = 1 ;
memcpy ( & V_424 -> V_100 ,
& V_439 -> V_444 ,
sizeof( V_424 -> V_100 ) ) ;
memcpy ( & V_424 -> V_101 ,
& V_439 -> V_511 ,
sizeof( V_424 -> V_101 ) ) ;
memcpy ( & V_424 -> V_93 ,
& V_439 -> V_512 ,
sizeof( V_424 -> V_93 ) ) ;
memcpy ( & V_424 -> V_97 ,
& V_439 -> V_513 ,
sizeof( V_424 -> V_97 ) ) ;
memcpy ( & V_424 -> V_94 ,
& V_439 -> V_514 ,
sizeof( V_424 -> V_94 ) ) ;
}
static int F_232 ( struct V_1 * V_22 ,
struct V_429 * V_515 ,
T_4 * V_516 )
{
int V_21 ;
if ( ! V_515 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_153 ,
V_243 ) ;
return - V_262 ;
}
memset ( V_515 , 0 , sizeof( * V_515 ) ) ;
V_21 = F_191 ( V_22 , V_515 , sizeof( * V_515 ) ) ;
if ( ! V_21 )
if ( V_515 -> V_517 < 256 )
* V_516 = V_515 -> V_517 ;
else
* V_516 = F_98 (
V_515 -> V_518 ) ;
else
* V_516 = - 1 ;
return V_21 ;
}
static bool F_233 ( struct V_1 * V_22 , T_1 * V_492 )
{
struct V_431 * V_439 ;
bool V_519 = false ;
int V_21 ;
V_439 = F_116 ( sizeof( * V_439 ) , V_204 ) ;
if ( ! V_439 )
return false ;
V_21 = F_192 ( V_22 ,
V_492 ,
F_194 ( V_492 ) ,
V_439 , sizeof( * V_439 ) ) ;
if ( V_21 == 0 )
V_519 = ( V_439 -> V_520 >> 6 ) & 0x01 ;
F_82 ( V_439 ) ;
return V_519 ;
}
static bool F_234 ( struct V_1 * V_22 , T_1 * V_492 ,
struct V_440 * V_441 )
{
T_1 V_509 ;
T_1 V_521 ;
if ( ! F_195 ( V_492 ) )
return false ;
V_509 = V_441 -> V_509 ;
V_521 = V_441 -> V_521 ;
if ( V_509 & V_522 ) {
if ( V_521 == V_523 )
return false ;
return true ;
}
if ( ! ( V_509 & V_524 ) )
return false ;
if ( V_509 & V_525 )
return false ;
if ( F_233 ( V_22 , V_492 ) )
return true ;
return false ;
}
static void F_235 ( struct V_1 * V_22 )
{
struct V_433 * V_506 = NULL ;
struct V_465 * V_507 = NULL ;
struct V_431 * V_439 = NULL ;
struct V_429 * V_515 = NULL ;
T_4 V_447 = 0 ;
T_4 V_503 = 0 ;
T_4 V_500 = 0 ;
T_4 V_526 = 0 ;
struct V_73 * * V_527 , * V_424 , * V_528 ;
int V_529 = 0 ;
int V_68 , V_530 , V_531 ;
int V_499 ;
bool V_74 ;
F_67 ( V_532 , V_533 ) ;
V_527 = F_116 ( sizeof( * V_527 ) * V_162 , V_204 ) ;
V_506 = F_116 ( sizeof( * V_506 ) , V_204 ) ;
V_507 = F_116 ( sizeof( * V_507 ) , V_204 ) ;
V_528 = F_116 ( sizeof( * V_528 ) , V_204 ) ;
V_439 = F_116 ( sizeof( * V_439 ) , V_204 ) ;
V_515 = F_116 ( sizeof( * V_515 ) , V_204 ) ;
if ( ! V_527 || ! V_506 || ! V_507 ||
! V_528 || ! V_439 || ! V_515 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_154 ) ;
goto V_395;
}
memset ( V_532 , 0 , sizeof( V_532 ) ) ;
V_22 -> V_250 = 0 ;
if ( F_226 ( V_22 , V_506 , & V_447 ,
V_507 , & V_503 ) ) {
V_22 -> V_250 = 1 ;
goto V_395;
}
if ( F_232 ( V_22 , V_515 , & V_500 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_155 ,
V_243 ) ;
}
V_531 = V_447 + V_503 + V_533 + 1 ;
for ( V_68 = 0 ; V_68 < V_531 ; V_68 ++ ) {
if ( V_68 >= V_162 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_156
L_157 , V_162 ,
V_531 - V_162 ) ;
break;
}
V_527 [ V_68 ] = F_116 ( sizeof( * V_527 [ V_68 ] ) , V_204 ) ;
if ( ! V_527 [ V_68 ] ) {
V_22 -> V_250 = 1 ;
goto V_395;
}
V_526 ++ ;
}
if ( F_65 ( V_22 ) )
V_499 = 0 ;
else
V_499 = V_447 + V_503 ;
V_530 = 0 ;
for ( V_68 = 0 ; V_68 < V_447 + V_503 + 1 ; V_68 ++ ) {
T_1 * V_492 , V_534 = 0 ;
int V_21 = 0 ;
int V_535 = V_68 - ( V_499 == 0 ) ;
bool V_536 = false ;
V_74 = V_68 < V_447 + ( V_499 == 0 ) ;
V_492 = F_227 ( V_22 , V_499 ,
V_68 , V_447 , V_503 , V_506 , V_507 ) ;
V_528 -> V_168 =
F_225 ( V_22 , V_499 , V_68 ,
V_447 , V_500 ) ;
if ( ! V_528 -> V_168 && V_74 ) {
V_536 = F_234 ( V_22 , V_492 ,
& V_506 -> V_350 [ V_535 ] ) ;
if ( V_536 )
continue;
}
V_21 = F_216 ( V_22 , V_492 , V_528 ,
& V_534 ) ;
if ( V_21 == - V_262 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_158 ) ;
V_22 -> V_250 = 1 ;
goto V_395;
}
if ( V_21 ) {
V_22 -> V_250 = 1 ;
continue;
}
F_223 ( V_22 , V_492 , V_528 ) ;
F_222 ( V_22 , V_528 , V_492 ) ;
V_424 = V_527 [ V_529 ] ;
if ( ! V_22 -> V_537 ) {
if ( V_528 -> V_168 ) {
V_22 -> V_537 = 1 ;
F_96 ( & V_22 -> V_29 -> V_30 ,
L_159 ) ;
}
}
* V_424 = * V_528 ;
V_424 -> V_74 = V_74 ;
if ( F_195 ( V_492 ) && V_424 -> V_74 )
V_424 -> V_90 = 0 ;
else
V_424 -> V_90 = 1 ;
if ( V_424 -> V_74 && V_424 -> V_90 )
F_200 ( V_22 , V_492 , V_424 ) ;
switch ( V_424 -> V_106 ) {
case V_170 :
if ( V_534 )
V_529 ++ ;
break;
case V_108 :
case V_109 :
if ( V_424 -> V_74 ) {
V_424 -> V_91 = 0 ;
F_228 ( V_22 , V_424 ,
V_506 , V_535 , V_439 ) ;
F_231 ( V_424 ,
V_506 , V_535 , V_439 ) ;
}
V_529 ++ ;
break;
case V_171 :
case V_172 :
V_529 ++ ;
break;
case V_167 :
if ( ! V_424 -> V_168 )
F_193 ( V_22 , V_492 ,
V_506 , V_535 ,
V_424 ) ;
V_529 ++ ;
break;
case V_107 :
if ( ! F_64 ( V_492 ) )
break;
V_529 ++ ;
break;
default:
break;
}
if ( V_529 >= V_162 )
break;
}
if ( V_22 -> V_238 == NULL ) {
int V_21 = 0 ;
V_21 = F_236 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_160 , V_21 ) ;
goto V_395;
}
}
F_115 ( V_22 , V_527 , V_529 ) ;
V_395:
F_82 ( V_528 ) ;
for ( V_68 = 0 ; V_68 < V_526 ; V_68 ++ )
F_82 ( V_527 [ V_68 ] ) ;
F_82 ( V_527 ) ;
F_82 ( V_506 ) ;
F_82 ( V_507 ) ;
F_82 ( V_515 ) ;
F_82 ( V_439 ) ;
}
static void F_237 ( struct V_275 * V_538 ,
struct V_539 * V_270 )
{
T_5 V_375 = ( T_5 ) F_238 ( V_270 ) ;
unsigned int V_50 = F_239 ( V_270 ) ;
V_538 -> V_283 = F_135 ( V_375 ) ;
V_538 -> V_282 = F_140 ( V_50 ) ;
V_538 -> V_279 = 0 ;
}
static int F_240 ( struct V_1 * V_22 ,
struct V_8 * V_132 ,
struct V_284 * V_285 )
{
struct V_539 * V_270 ;
int V_540 , V_68 , V_541 , V_542 , V_543 ;
struct V_275 * V_544 ;
F_77 ( F_160 ( V_285 ) > V_22 -> V_263 ) ;
V_540 = F_241 ( V_285 ) ;
if ( V_540 < 0 )
return V_540 ;
if ( ! V_540 )
goto V_545;
V_544 = V_132 -> V_277 ;
V_542 = V_540 > V_22 -> V_278 ;
V_541 = V_542 ? V_22 -> V_278 - 1 : V_540 ;
V_543 = F_160 ( V_285 ) - 1 ;
F_242 (cmd, sg, sg_limit, i) {
F_237 ( V_544 , V_270 ) ;
V_544 ++ ;
}
if ( V_542 ) {
V_544 = V_22 -> V_265 [ V_132 -> V_134 ] ;
V_541 = V_540 - V_541 ;
F_243 (sg, sg, sg_limit, i) {
F_237 ( V_544 , V_270 ) ;
V_544 ++ ;
}
}
( V_544 - 1 ) -> V_279 = F_140 ( V_377 ) ;
if ( V_540 + V_542 > V_22 -> V_546 )
V_22 -> V_546 = V_540 + V_542 ;
if ( V_542 ) {
V_132 -> V_125 . V_126 = V_22 -> V_278 ;
V_132 -> V_125 . V_281 = F_161 ( V_540 + 1 ) ;
if ( F_139 ( V_22 , V_132 ) ) {
F_159 ( V_285 ) ;
return - 1 ;
}
return 0 ;
}
V_545:
V_132 -> V_125 . V_126 = ( T_1 ) V_540 ;
V_132 -> V_125 . V_281 = F_161 ( V_540 ) ;
return 0 ;
}
static int F_244 ( T_1 * V_142 , int * V_547 )
{
int V_548 = 0 ;
T_4 V_549 ;
T_4 V_550 ;
switch ( V_142 [ 0 ] ) {
case V_551 :
case V_552 :
V_548 = 1 ;
case V_553 :
case V_554 :
if ( * V_547 == 6 ) {
V_549 = ( ( ( V_142 [ 1 ] & 0x1F ) << 16 ) |
( V_142 [ 2 ] << 8 ) |
V_142 [ 3 ] ) ;
V_550 = V_142 [ 4 ] ;
if ( V_550 == 0 )
V_550 = 256 ;
} else {
F_77 ( * V_547 != 12 ) ;
V_549 = F_198 ( & V_142 [ 2 ] ) ;
V_550 = F_198 ( & V_142 [ 6 ] ) ;
}
if ( V_550 > 0xffff )
return V_555 ;
V_142 [ 0 ] = V_548 ? V_556 : V_557 ;
V_142 [ 1 ] = 0 ;
V_142 [ 2 ] = ( T_1 ) ( V_549 >> 24 ) ;
V_142 [ 3 ] = ( T_1 ) ( V_549 >> 16 ) ;
V_142 [ 4 ] = ( T_1 ) ( V_549 >> 8 ) ;
V_142 [ 5 ] = ( T_1 ) ( V_549 ) ;
V_142 [ 6 ] = 0 ;
V_142 [ 7 ] = ( T_1 ) ( V_550 >> 8 ) ;
V_142 [ 8 ] = ( T_1 ) ( V_550 ) ;
V_142 [ 9 ] = 0 ;
* V_547 = 10 ;
break;
}
return 0 ;
}
static int F_245 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_188 , T_1 * V_142 , int V_547 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_131 * V_132 = & V_22 -> V_133 [ V_9 -> V_134 ] ;
unsigned int V_50 ;
unsigned int V_558 = 0 ;
struct V_539 * V_270 ;
T_5 V_375 ;
int V_540 , V_68 ;
struct V_275 * V_544 ;
T_4 V_559 = V_560 ;
if ( F_160 ( V_285 ) > V_22 -> V_561 ) {
F_47 ( & V_236 -> V_257 ) ;
return V_555 ;
}
F_77 ( V_285 -> V_562 > V_563 ) ;
if ( F_244 ( V_142 , & V_547 ) ) {
F_47 ( & V_236 -> V_257 ) ;
return V_555 ;
}
V_9 -> V_151 = V_152 ;
V_9 -> V_123 = ( T_4 ) V_22 -> V_564 +
( V_9 -> V_134 * sizeof( * V_132 ) ) ;
F_77 ( V_9 -> V_123 & 0x0000007F ) ;
V_540 = F_241 ( V_285 ) ;
if ( V_540 < 0 ) {
F_47 ( & V_236 -> V_257 ) ;
return V_540 ;
}
if ( V_540 ) {
V_544 = V_132 -> V_277 ;
F_242 (cmd, sg, use_sg, i) {
V_375 = ( T_5 ) F_238 ( V_270 ) ;
V_50 = F_239 ( V_270 ) ;
V_558 += V_50 ;
V_544 -> V_283 = F_135 ( V_375 ) ;
V_544 -> V_282 = F_140 ( V_50 ) ;
V_544 -> V_279 = F_140 ( 0 ) ;
V_544 ++ ;
}
( -- V_544 ) -> V_279 = F_140 ( V_377 ) ;
switch ( V_285 -> V_565 ) {
case V_566 :
V_559 |= V_567 ;
break;
case V_568 :
V_559 |= V_569 ;
break;
case V_570 :
V_559 |= V_571 ;
break;
default:
F_75 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_285 -> V_565 ) ;
F_180 () ;
break;
}
} else {
V_559 |= V_571 ;
}
V_9 -> V_125 . V_126 = V_540 ;
V_132 -> V_572 = F_161 ( V_188 & 0xFFFF ) ;
V_132 -> V_573 = F_140 ( V_558 ) ;
V_132 -> V_347 = F_161 ( V_574 |
( V_547 & V_348 ) ) ;
V_132 -> V_559 = F_140 ( V_559 ) ;
memcpy ( V_132 -> V_146 , V_142 , V_547 ) ;
memcpy ( V_132 -> V_352 , V_72 , 8 ) ;
F_62 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_73 * V_30 = V_285 -> V_42 -> V_80 ;
if ( ! V_30 )
return - 1 ;
V_9 -> V_236 = V_30 ;
return F_247 ( V_22 , V_9 , V_30 -> V_188 ,
V_285 -> V_575 , V_285 -> V_562 , V_30 -> V_72 , V_30 ) ;
}
static void F_248 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_140 * V_132 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_73 * V_30 = V_285 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_187 ;
T_5 V_576 ;
if ( ! ( F_98 ( V_222 -> V_78 ) & V_421 ) )
return;
V_132 -> V_422 = V_222 -> V_422 ;
V_132 -> V_577 |= V_578 ;
switch ( V_285 -> V_575 [ 0 ] ) {
case V_553 :
case V_551 :
V_576 = ( ( ( V_285 -> V_575 [ 1 ] & 0x1F ) << 16 ) |
( V_285 -> V_575 [ 2 ] << 8 ) |
V_285 -> V_575 [ 3 ] ) ;
break;
case V_556 :
case V_557 :
case V_552 :
case V_554 :
V_576 = F_198 ( & V_285 -> V_575 [ 2 ] ) ;
break;
case V_579 :
case V_580 :
V_576 = F_199 ( & V_285 -> V_575 [ 2 ] ) ;
break;
default:
F_75 ( & V_22 -> V_29 -> V_30 ,
L_162 ,
V_243 , V_285 -> V_575 [ 0 ] ) ;
F_180 () ;
break;
}
if ( F_132 ( V_222 -> V_414 ) != 512 )
V_576 = V_576 *
F_132 ( V_222 -> V_414 ) / 512 ;
V_132 -> V_581 = F_140 ( V_576 ) ;
V_132 -> V_582 = F_140 ( V_576 >> 32 ) ;
}
static int F_249 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_188 , T_1 * V_142 , int V_547 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_140 * V_132 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
struct V_266 * V_544 ;
int V_540 , V_68 ;
struct V_539 * V_270 ;
T_5 V_375 ;
T_4 V_50 ;
T_4 V_558 = 0 ;
if ( ! V_285 -> V_42 )
return - 1 ;
if ( ! V_285 -> V_42 -> V_80 )
return - 1 ;
F_77 ( F_160 ( V_285 ) > V_22 -> V_263 ) ;
if ( F_244 ( V_142 , & V_547 ) ) {
F_47 ( & V_236 -> V_257 ) ;
return V_555 ;
}
V_9 -> V_151 = V_155 ;
V_9 -> V_123 = ( T_4 ) V_22 -> V_583 +
( V_9 -> V_134 * sizeof( * V_132 ) ) ;
F_77 ( V_9 -> V_123 & 0x0000007F ) ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
V_132 -> V_584 = V_585 ;
V_540 = F_241 ( V_285 ) ;
if ( V_540 < 0 ) {
F_47 ( & V_236 -> V_257 ) ;
return V_540 ;
}
if ( V_540 ) {
V_544 = V_132 -> V_270 ;
if ( V_540 > V_22 -> V_561 ) {
V_375 = F_137 (
V_22 -> V_260 [ V_9 -> V_134 ] -> V_273 ) ;
V_544 -> V_273 = F_135 ( V_375 ) ;
V_544 -> V_271 = 0 ;
V_544 -> V_586 [ 0 ] = 0 ;
V_544 -> V_586 [ 1 ] = 0 ;
V_544 -> V_586 [ 2 ] = 0 ;
V_544 -> V_342 = 0x80 ;
V_544 = V_22 -> V_260 [ V_9 -> V_134 ] ;
}
F_242 (cmd, sg, use_sg, i) {
V_375 = ( T_5 ) F_238 ( V_270 ) ;
V_50 = F_239 ( V_270 ) ;
V_558 += V_50 ;
V_544 -> V_273 = F_135 ( V_375 ) ;
V_544 -> V_271 = F_140 ( V_50 ) ;
V_544 -> V_586 [ 0 ] = 0 ;
V_544 -> V_586 [ 1 ] = 0 ;
V_544 -> V_586 [ 2 ] = 0 ;
V_544 -> V_342 = 0 ;
V_544 ++ ;
}
switch ( V_285 -> V_565 ) {
case V_566 :
V_132 -> V_577 &= ~ V_587 ;
V_132 -> V_577 |= V_588 ;
break;
case V_568 :
V_132 -> V_577 &= ~ V_587 ;
V_132 -> V_577 |= V_589 ;
break;
case V_570 :
V_132 -> V_577 &= ~ V_587 ;
V_132 -> V_577 |= V_590 ;
break;
default:
F_75 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_285 -> V_565 ) ;
F_180 () ;
break;
}
} else {
V_132 -> V_577 &= ~ V_587 ;
V_132 -> V_577 |= V_590 ;
}
F_248 ( V_22 , V_9 , V_132 ) ;
V_132 -> V_498 = F_140 ( V_188 ) ;
V_132 -> V_591 = F_140 ( V_9 -> V_134 << V_592 ) ;
memcpy ( V_132 -> V_142 , V_142 , sizeof( V_132 -> V_142 ) ) ;
V_132 -> V_287 = F_140 ( V_558 ) ;
V_132 -> V_593 = F_135 ( V_9 -> V_123 +
F_250 ( struct V_140 , V_290 ) ) ;
V_132 -> V_594 = F_140 ( sizeof( V_132 -> V_290 ) ) ;
if ( V_540 > V_22 -> V_561 ) {
V_132 -> V_141 = 1 ;
V_132 -> V_270 [ 0 ] . V_271 = F_140 ( V_540 * sizeof( V_132 -> V_270 [ 0 ] ) ) ;
if ( F_131 ( V_22 , V_132 , V_9 ) ) {
F_47 ( & V_236 -> V_257 ) ;
F_159 ( V_285 ) ;
return - 1 ;
}
} else
V_132 -> V_141 = ( T_1 ) V_540 ;
F_62 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_247 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_188 , T_1 * V_142 , int V_547 ,
T_1 * V_72 , struct V_73 * V_236 )
{
if ( ! V_9 -> V_10 -> V_42 )
return - 1 ;
if ( ! V_9 -> V_10 -> V_42 -> V_80 )
return - 1 ;
if ( F_105 ( & V_236 -> V_257 ) >
V_236 -> V_191 ) {
F_47 ( & V_236 -> V_257 ) ;
return V_555 ;
}
if ( V_22 -> V_63 & V_115 )
return F_245 ( V_22 , V_9 , V_188 ,
V_142 , V_547 , V_72 ,
V_236 ) ;
else
return F_249 ( V_22 , V_9 , V_188 ,
V_142 , V_547 , V_72 ,
V_236 ) ;
}
static void F_251 ( struct V_221 * V_222 ,
int V_190 , T_4 * V_595 , T_4 * V_596 )
{
if ( V_190 == 0 ) {
* V_595 %= F_98 ( V_222 -> V_227 ) ;
return;
}
do {
* V_596 = * V_595 /
F_98 ( V_222 -> V_227 ) ;
if ( V_190 == * V_596 )
continue;
if ( * V_596 < F_98 ( V_222 -> V_231 ) - 1 ) {
* V_595 += F_98 ( V_222 -> V_227 ) ;
( * V_596 ) ++ ;
} else {
* V_595 %= F_98 ( V_222 -> V_227 ) ;
* V_596 = 0 ;
}
} while ( V_190 != * V_596 );
}
static int F_252 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_73 * V_30 = V_285 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_187 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_548 = 0 ;
T_4 V_595 ;
T_5 V_576 , V_597 ;
T_4 V_550 ;
T_4 V_598 ;
T_5 V_599 , V_600 ;
T_4 V_601 , V_602 ;
T_4 V_603 , V_604 ;
T_5 V_605 , V_606 ;
T_4 V_607 ;
T_5 V_608 , V_609 ;
T_4 V_610 , V_611 ;
T_4 V_612 , V_613 ;
T_4 V_226 ;
T_4 V_614 ;
T_4 V_615 , V_616 , V_596 ;
T_4 V_617 ;
T_4 V_618 ;
T_5 V_619 ;
T_4 V_620 ;
T_1 V_142 [ 16 ] ;
T_1 V_547 ;
T_6 V_418 ;
#if V_621 == 32
T_5 V_622 ;
#endif
int V_190 ;
if ( ! V_30 )
return - 1 ;
switch ( V_285 -> V_575 [ 0 ] ) {
case V_551 :
V_548 = 1 ;
case V_553 :
V_576 = ( ( ( V_285 -> V_575 [ 1 ] & 0x1F ) << 16 ) |
( V_285 -> V_575 [ 2 ] << 8 ) |
V_285 -> V_575 [ 3 ] ) ;
V_550 = V_285 -> V_575 [ 4 ] ;
if ( V_550 == 0 )
V_550 = 256 ;
break;
case V_556 :
V_548 = 1 ;
case V_557 :
V_576 =
( ( ( T_5 ) V_285 -> V_575 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_575 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_575 [ 4 ] ) << 8 ) |
V_285 -> V_575 [ 5 ] ;
V_550 =
( ( ( T_4 ) V_285 -> V_575 [ 7 ] ) << 8 ) |
V_285 -> V_575 [ 8 ] ;
break;
case V_552 :
V_548 = 1 ;
case V_554 :
V_576 =
( ( ( T_5 ) V_285 -> V_575 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_575 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_575 [ 4 ] ) << 8 ) |
V_285 -> V_575 [ 5 ] ;
V_550 =
( ( ( T_4 ) V_285 -> V_575 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_285 -> V_575 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_285 -> V_575 [ 8 ] ) << 8 ) |
V_285 -> V_575 [ 9 ] ;
break;
case V_579 :
V_548 = 1 ;
case V_580 :
V_576 =
( ( ( T_5 ) V_285 -> V_575 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_285 -> V_575 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_285 -> V_575 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_285 -> V_575 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_285 -> V_575 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_575 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_575 [ 8 ] ) << 8 ) |
V_285 -> V_575 [ 9 ] ;
V_550 =
( ( ( T_4 ) V_285 -> V_575 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_285 -> V_575 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_285 -> V_575 [ 12 ] ) << 8 ) |
V_285 -> V_575 [ 13 ] ;
break;
default:
return V_555 ;
}
V_597 = V_576 + V_550 - 1 ;
if ( V_548 && V_30 -> V_83 != 0 )
return V_555 ;
if ( V_597 >= F_137 ( V_222 -> V_415 ) ||
V_597 < V_576 )
return V_555 ;
V_598 = F_98 ( V_222 -> V_227 ) *
F_98 ( V_222 -> V_418 ) ;
V_418 = F_98 ( V_222 -> V_418 ) ;
#if V_621 == 32
V_622 = V_576 ;
( void ) F_253 ( V_622 , V_598 ) ;
V_599 = V_622 ;
V_622 = V_597 ;
( void ) F_253 ( V_622 , V_598 ) ;
V_600 = V_622 ;
V_601 = ( T_4 ) ( V_576 - ( V_599 * V_598 ) ) ;
V_602 = ( T_4 ) ( V_597 - ( V_600 * V_598 ) ) ;
V_622 = V_601 ;
( void ) F_253 ( V_622 , V_418 ) ;
V_603 = V_622 ;
V_622 = V_602 ;
( void ) F_253 ( V_622 , V_418 ) ;
V_604 = V_622 ;
#else
V_599 = V_576 / V_598 ;
V_600 = V_597 / V_598 ;
V_601 = ( T_4 ) ( V_576 - ( V_599 * V_598 ) ) ;
V_602 = ( T_4 ) ( V_597 - ( V_600 * V_598 ) ) ;
V_603 = V_601 / V_418 ;
V_604 = V_602 / V_418 ;
#endif
if ( ( V_599 != V_600 ) || ( V_603 != V_604 ) )
return V_555 ;
V_226 = F_98 ( V_222 -> V_227 ) +
F_98 ( V_222 -> V_228 ) ;
V_617 = ( ( T_4 ) ( V_599 >> V_222 -> V_417 ) ) %
F_98 ( V_222 -> V_230 ) ;
V_595 = ( V_617 * V_226 ) + V_603 ;
switch ( V_30 -> V_83 ) {
case V_623 :
break;
case V_624 :
F_77 ( F_98 ( V_222 -> V_231 ) != 2 ) ;
if ( V_30 -> V_190 )
V_595 += F_98 ( V_222 -> V_227 ) ;
V_30 -> V_190 = ! V_30 -> V_190 ;
break;
case V_625 :
F_77 ( F_98 ( V_222 -> V_231 ) != 3 ) ;
V_190 = V_30 -> V_190 ;
F_251 ( V_222 , V_190 ,
& V_595 , & V_596 ) ;
V_190 =
( V_190 >=
F_98 ( V_222 -> V_231 ) - 1 )
? 0 : V_190 + 1 ;
V_30 -> V_190 = V_190 ;
break;
case V_626 :
case V_627 :
if ( F_98 ( V_222 -> V_231 ) <= 1 )
break;
V_607 =
F_98 ( V_222 -> V_418 ) *
F_98 ( V_222 -> V_227 ) ;
F_77 ( V_607 == 0 ) ;
V_614 = V_607 *
F_98 ( V_222 -> V_231 ) ;
#if V_621 == 32
V_622 = V_576 ;
V_615 = F_253 ( V_622 , V_614 ) ;
V_622 = V_615 ;
( void ) F_253 ( V_622 , V_607 ) ;
V_615 = V_622 ;
V_622 = V_597 ;
V_616 = F_253 ( V_622 , V_614 ) ;
V_622 = V_616 ;
( void ) F_253 ( V_622 , V_607 ) ;
V_616 = V_622 ;
#else
V_615 = ( V_576 % V_614 ) / V_607 ;
V_616 = ( V_597 % V_614 ) / V_607 ;
#endif
if ( V_615 != V_616 )
return V_555 ;
#if V_621 == 32
V_622 = V_576 ;
( void ) F_253 ( V_622 , V_614 ) ;
V_599 = V_608 = V_605 = V_622 ;
V_622 = V_597 ;
( void ) F_253 ( V_622 , V_614 ) ;
V_609 = V_606 = V_622 ;
#else
V_599 = V_608 = V_605 =
V_576 / V_614 ;
V_609 = V_606 = V_597 / V_614 ;
#endif
if ( V_608 != V_609 )
return V_555 ;
#if V_621 == 32
V_622 = V_576 ;
V_601 = F_253 ( V_622 , V_614 ) ;
V_622 = V_601 ;
V_601 = ( T_4 ) F_253 ( V_622 , V_607 ) ;
V_610 = V_601 ;
V_622 = V_597 ;
V_611 = F_253 ( V_622 , V_614 ) ;
V_622 = V_611 ;
V_611 = F_253 ( V_622 , V_607 ) ;
V_622 = V_610 ;
( void ) F_253 ( V_622 , V_222 -> V_418 ) ;
V_603 = V_612 = V_622 ;
V_622 = V_611 ;
( void ) F_253 ( V_622 , V_222 -> V_418 ) ;
V_613 = V_622 ;
#else
V_601 = V_610 =
( T_4 ) ( ( V_576 % V_614 ) %
V_607 ) ;
V_611 =
( T_4 ) ( ( V_597 % V_614 ) %
V_607 ) ;
V_603 = V_612 =
V_610 / F_98 ( V_222 -> V_418 ) ;
V_613 =
V_611 / F_98 ( V_222 -> V_418 ) ;
#endif
if ( V_612 != V_613 )
return V_555 ;
V_617 = ( ( T_4 ) ( V_599 >> V_222 -> V_417 ) ) %
F_98 ( V_222 -> V_230 ) ;
V_595 = ( V_615 *
( F_98 ( V_222 -> V_230 ) * V_226 ) ) +
( V_617 * V_226 ) + V_603 ;
break;
default:
return V_555 ;
}
if ( F_46 ( V_595 >= V_234 ) )
return V_555 ;
V_9 -> V_236 = V_30 -> V_236 [ V_595 ] ;
if ( ! V_9 -> V_236 )
return V_555 ;
V_618 = V_224 [ V_595 ] . V_188 ;
V_619 = F_137 ( V_222 -> V_419 ) +
V_599 * F_98 ( V_222 -> V_418 ) +
( V_601 - V_603 *
F_98 ( V_222 -> V_418 ) ) ;
V_620 = V_550 ;
if ( V_222 -> V_416 ) {
V_619 <<= V_222 -> V_416 ;
V_620 <<= V_222 -> V_416 ;
}
F_77 ( V_620 > 0xffff ) ;
if ( V_619 > 0xffffffff ) {
V_142 [ 0 ] = V_548 ? V_579 : V_580 ;
V_142 [ 1 ] = 0 ;
V_142 [ 2 ] = ( T_1 ) ( V_619 >> 56 ) ;
V_142 [ 3 ] = ( T_1 ) ( V_619 >> 48 ) ;
V_142 [ 4 ] = ( T_1 ) ( V_619 >> 40 ) ;
V_142 [ 5 ] = ( T_1 ) ( V_619 >> 32 ) ;
V_142 [ 6 ] = ( T_1 ) ( V_619 >> 24 ) ;
V_142 [ 7 ] = ( T_1 ) ( V_619 >> 16 ) ;
V_142 [ 8 ] = ( T_1 ) ( V_619 >> 8 ) ;
V_142 [ 9 ] = ( T_1 ) ( V_619 ) ;
V_142 [ 10 ] = ( T_1 ) ( V_620 >> 24 ) ;
V_142 [ 11 ] = ( T_1 ) ( V_620 >> 16 ) ;
V_142 [ 12 ] = ( T_1 ) ( V_620 >> 8 ) ;
V_142 [ 13 ] = ( T_1 ) ( V_620 ) ;
V_142 [ 14 ] = 0 ;
V_142 [ 15 ] = 0 ;
V_547 = 16 ;
} else {
V_142 [ 0 ] = V_548 ? V_556 : V_557 ;
V_142 [ 1 ] = 0 ;
V_142 [ 2 ] = ( T_1 ) ( V_619 >> 24 ) ;
V_142 [ 3 ] = ( T_1 ) ( V_619 >> 16 ) ;
V_142 [ 4 ] = ( T_1 ) ( V_619 >> 8 ) ;
V_142 [ 5 ] = ( T_1 ) ( V_619 ) ;
V_142 [ 6 ] = 0 ;
V_142 [ 7 ] = ( T_1 ) ( V_620 >> 8 ) ;
V_142 [ 8 ] = ( T_1 ) ( V_620 ) ;
V_142 [ 9 ] = 0 ;
V_547 = 10 ;
}
return F_247 ( V_22 , V_9 , V_618 , V_142 , V_547 ,
V_30 -> V_72 ,
V_30 -> V_236 [ V_595 ] ) ;
}
static int F_254 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
unsigned char V_72 [] )
{
V_285 -> V_628 = ( unsigned char * ) V_9 ;
V_9 -> V_151 = V_341 ;
V_9 -> V_10 = V_285 ;
V_9 -> V_125 . V_129 = 0 ;
memcpy ( & V_9 -> V_125 . V_350 . V_351 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_125 . V_349 = F_135 ( ( V_9 -> V_134 << V_592 ) ) ;
V_9 -> V_145 . V_629 = 0 ;
F_77 ( V_285 -> V_562 > sizeof( V_9 -> V_145 . V_146 ) ) ;
V_9 -> V_145 . V_346 = V_285 -> V_562 ;
memcpy ( V_9 -> V_145 . V_146 , V_285 -> V_575 , V_285 -> V_562 ) ;
switch ( V_285 -> V_565 ) {
case V_566 :
V_9 -> V_145 . V_630 =
F_255 ( V_394 , V_631 , V_632 ) ;
break;
case V_568 :
V_9 -> V_145 . V_630 =
F_255 ( V_394 , V_631 , V_633 ) ;
break;
case V_570 :
V_9 -> V_145 . V_630 =
F_255 ( V_394 , V_631 , V_634 ) ;
break;
case V_635 :
V_9 -> V_145 . V_630 =
F_255 ( V_394 , V_631 , V_636 ) ;
break;
default:
F_75 ( & V_22 -> V_29 -> V_30 , L_161 ,
V_285 -> V_565 ) ;
F_180 () ;
break;
}
if ( F_240 ( V_22 , V_9 , V_285 ) < 0 ) {
F_148 ( V_22 , V_9 ) ;
return V_637 ;
}
F_62 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_22 , int V_200 ,
struct V_8 * V_9 )
{
V_373 V_638 , V_639 ;
memset ( V_9 , 0 , F_250 ( struct V_8 , V_240 ) ) ;
V_9 -> V_125 . V_349 = F_135 ( ( T_5 ) ( V_200 << V_592 ) ) ;
V_638 = V_22 -> V_640 + V_200 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_641 + V_200 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_639 = V_22 -> V_642
+ V_200 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_134 = V_200 ;
V_9 -> V_123 = ( T_4 ) V_638 ;
V_9 -> V_643 . V_283 = F_135 ( ( T_5 ) V_639 ) ;
V_9 -> V_643 . V_282 = F_140 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_257 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
F_256 ( V_22 , V_68 , V_9 ) ;
F_123 ( & V_9 -> V_240 , 0 ) ;
}
}
static inline void F_258 ( struct V_1 * V_22 , int V_200 ,
struct V_8 * V_9 )
{
V_373 V_638 = V_22 -> V_640 + V_200 * sizeof( * V_9 ) ;
F_77 ( V_9 -> V_134 != V_200 ) ;
memset ( V_9 -> V_145 . V_146 , 0 , sizeof( V_9 -> V_145 . V_146 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_123 = ( T_4 ) V_638 ;
}
static int F_259 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_285 -> V_42 -> V_80 ;
int V_21 = V_555 ;
if ( ! V_30 )
return V_637 ;
V_285 -> V_628 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_91 ) {
F_256 ( V_22 , V_9 -> V_134 , V_9 ) ;
V_9 -> V_151 = V_341 ;
V_9 -> V_10 = V_285 ;
V_21 = F_252 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_637 ;
} else if ( V_30 -> V_189 ) {
F_256 ( V_22 , V_9 -> V_134 , V_9 ) ;
V_9 -> V_151 = V_341 ;
V_9 -> V_10 = V_285 ;
V_21 = F_246 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_637 ;
}
return V_21 ;
}
static void V_327 ( struct V_644 * V_326 )
{
struct V_284 * V_285 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_260 ( V_326 , struct V_8 , V_326 ) ;
V_285 = V_9 -> V_10 ;
V_30 = V_285 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_150 ( V_9 -> V_22 , V_9 , V_285 ) ;
}
if ( V_9 -> V_13 )
return F_148 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_155 ( V_9 -> V_22 , V_9 , V_285 ) ;
if ( V_9 -> V_151 == V_155 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_140 * V_286 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
int V_21 ;
if ( V_286 -> V_290 . V_291 ==
V_304 ) {
V_21 = F_259 ( V_22 , V_9 , V_285 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_637 ) {
V_285 -> V_295 = V_645 << 16 ;
return F_150 ( V_22 , V_9 , V_285 ) ;
}
}
}
F_258 ( V_9 -> V_22 , V_9 -> V_134 , V_9 ) ;
if ( F_254 ( V_9 -> V_22 , V_9 , V_285 , V_30 -> V_72 ) ) {
V_285 -> V_295 = V_645 << 16 ;
V_285 -> V_325 ( V_285 ) ;
}
}
static int F_261 ( struct V_6 * V_7 , struct V_284 * V_285 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_285 -> V_42 ) ;
F_77 ( V_285 -> V_646 -> V_349 < 0 ) ;
V_30 = V_285 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
if ( V_30 -> V_192 ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_46 ( F_13 ( V_22 ) ) ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
V_9 = F_262 ( V_22 , V_285 ) ;
if ( F_49 ( V_285 -> V_647 == 0 &&
! F_263 ( V_285 -> V_646 ) &&
V_22 -> V_56 ) ) {
V_21 = F_259 ( V_22 , V_9 , V_285 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_637 ) {
F_148 ( V_22 , V_9 ) ;
return V_637 ;
}
}
return F_254 ( V_22 , V_9 , V_285 , V_72 ) ;
}
static void F_264 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_648 , V_78 ) ;
V_22 -> V_649 = 1 ;
F_265 ( & V_22 -> V_650 ) ;
F_36 ( & V_22 -> V_648 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_46 ( F_13 ( V_22 ) ) )
return F_264 ( V_22 ) ;
F_35 ( & V_22 -> V_648 , V_78 ) ;
if ( V_22 -> V_651 ) {
F_36 ( & V_22 -> V_648 , V_78 ) ;
return;
}
F_36 ( & V_22 -> V_648 , V_78 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_648 , V_78 ) ;
if ( V_22 -> V_649 )
break;
V_22 -> V_651 = 1 ;
F_36 ( & V_22 -> V_648 , V_78 ) ;
F_183 ( V_22 -> V_650 , V_22 -> V_649 ) ;
}
V_22 -> V_649 = 0 ;
V_22 -> V_651 = 0 ;
F_36 ( & V_22 -> V_648 , V_78 ) ;
if ( F_46 ( F_13 ( V_22 ) ) )
return F_264 ( V_22 ) ;
if ( V_22 -> V_249 ) {
V_22 -> V_250 = 1 ;
return;
}
F_235 ( V_22 ) ;
F_264 ( V_22 ) ;
}
static int F_266 ( struct V_2 * V_3 , int V_233 )
{
struct V_73 * V_220 = V_3 -> V_80 ;
if ( ! V_220 )
return - V_81 ;
if ( V_233 < 1 )
V_233 = 1 ;
else if ( V_233 > V_220 -> V_191 )
V_233 = V_220 -> V_191 ;
return F_125 ( V_3 , V_233 ) ;
}
static int F_267 ( struct V_6 * V_7 ,
unsigned long V_652 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_653 ;
F_35 ( & V_22 -> V_648 , V_78 ) ;
V_653 = V_22 -> V_649 ;
F_36 ( & V_22 -> V_648 , V_78 ) ;
return V_653 ;
}
static int F_268 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_269 ( & V_654 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_163 ) ;
return - V_262 ;
}
V_7 -> V_655 = 0 ;
V_7 -> V_656 = 0 ;
V_7 -> V_657 = - 1 ;
V_7 -> V_658 = 3 ;
V_7 -> V_659 = V_660 ;
V_7 -> V_661 = V_505 ;
V_7 -> V_662 = V_505 ;
V_7 -> V_259 = V_22 -> V_237 - V_663 ;
V_7 -> V_664 = V_7 -> V_259 ;
V_7 -> V_665 = V_22 -> V_263 ;
V_7 -> V_666 = V_667 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_668 = F_270 ( V_22 -> V_29 , 0 ) ;
V_7 -> V_669 = V_7 -> V_668 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_271 ( struct V_1 * V_22 )
{
int V_670 ;
V_670 = F_272 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_670 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_164 ) ;
return V_670 ;
}
F_273 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_274 ( struct V_284 * V_671 )
{
int V_672 = V_671 -> V_646 -> V_349 ;
if ( V_672 < 0 )
return V_672 ;
return V_672 += V_663 ;
}
static int F_275 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_673 [] ,
int V_114 )
{
int V_21 ;
( void ) F_178 ( V_9 , V_480 , V_22 ,
NULL , 0 , 0 , V_673 , V_394 ) ;
V_21 = F_169 ( V_22 , V_9 , V_114 , V_397 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_674 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_296 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_675 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_276 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_673 [] , int V_114 )
{
int V_21 ;
int V_48 = 0 ;
int V_676 = 1 ;
for ( V_48 = 0 ; V_48 < V_677 ; V_48 ++ ) {
F_109 ( 1000 * V_676 ) ;
V_21 = F_275 ( V_22 , V_9 , V_673 , V_114 ) ;
if ( ! V_21 )
break;
if ( V_676 < V_678 )
V_676 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_165 ,
V_676 ) ;
}
return V_21 ;
}
static int F_184 ( struct V_1 * V_22 ,
unsigned char V_673 [] ,
int V_114 )
{
int V_679 ;
int V_680 ;
int V_113 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_177 ( V_22 ) ;
if ( V_114 == V_128 ) {
V_679 = 0 ;
V_680 = V_22 -> V_130 - 1 ;
} else {
V_679 = V_114 ;
V_680 = V_114 ;
}
for ( V_113 = V_679 ; V_113 <= V_680 ; V_113 ++ ) {
V_21 = F_276 ( V_22 , V_9 , V_673 , V_113 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_166 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_167 ) ;
F_107 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_277 ( struct V_284 * V_681 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_398 ;
char V_682 [ 48 ] ;
V_22 = F_1 ( V_681 -> V_42 ) ;
if ( V_22 == NULL )
return V_683 ;
if ( F_13 ( V_22 ) )
return V_683 ;
V_30 = V_681 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_168 , V_243 ) ;
return V_683 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_682 , sizeof( V_682 ) ,
L_169 ,
F_274 ( V_681 ) ) ;
F_71 ( V_244 , V_22 , V_30 , V_682 ) ;
return V_683 ;
}
if ( F_278 ( V_22 ) ) {
snprintf ( V_682 , sizeof( V_682 ) ,
L_170 ,
F_274 ( V_681 ) ) ;
F_71 ( V_244 , V_22 , V_30 , V_682 ) ;
return V_683 ;
}
if ( F_64 ( V_30 -> V_72 ) )
return V_684 ;
if ( F_31 ( V_30 -> V_72 ) )
V_398 = V_685 ;
else
V_398 = V_686 ;
sprintf ( V_682 , L_171 ,
V_398 == V_685 ? L_172 : L_173 ) ;
F_71 ( V_244 , V_22 , V_30 , V_682 ) ;
V_22 -> V_249 = 1 ;
V_21 = F_181 ( V_22 , V_30 , V_30 -> V_72 , V_398 ,
V_128 ) ;
sprintf ( V_682 , L_174 ,
V_398 == V_685 ? L_172 : L_173 ,
V_21 == 0 ? L_175 : L_176 ) ;
F_71 ( V_244 , V_22 , V_30 , V_682 ) ;
V_22 -> V_249 = 0 ;
return V_21 == 0 ? V_684 : V_683 ;
}
static void F_279 ( T_1 * V_349 )
{
T_1 V_687 [ 8 ] ;
memcpy ( V_687 , V_349 , 8 ) ;
V_349 [ 0 ] = V_687 [ 3 ] ;
V_349 [ 1 ] = V_687 [ 2 ] ;
V_349 [ 2 ] = V_687 [ 1 ] ;
V_349 [ 3 ] = V_687 [ 0 ] ;
V_349 [ 4 ] = V_687 [ 7 ] ;
V_349 [ 5 ] = V_687 [ 6 ] ;
V_349 [ 6 ] = V_687 [ 5 ] ;
V_349 [ 7 ] = V_687 [ 4 ] ;
}
static void F_280 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_688 , T_7 * V_689 )
{
T_5 V_349 ;
if ( V_9 -> V_151 == V_152 ) {
struct V_131 * V_690 = (struct V_131 * )
& V_22 -> V_133 [ V_9 -> V_134 ] ;
V_349 = F_137 ( V_690 -> V_349 ) ;
* V_689 = F_140 ( V_349 >> 32 ) ;
* V_688 = F_140 ( V_349 ) ;
return;
}
if ( V_9 -> V_151 == V_155 ) {
struct V_140 * V_691 = (struct V_140 * )
& V_22 -> V_138 [ V_9 -> V_134 ] ;
memset ( V_689 , 0 , sizeof( * V_689 ) ) ;
* V_688 = V_691 -> V_591 ;
return;
}
V_349 = F_137 ( V_9 -> V_125 . V_349 ) ;
* V_689 = F_140 ( V_349 >> 32 ) ;
* V_688 = F_140 ( V_349 ) ;
}
static int F_281 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_114 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
T_7 V_689 , V_688 ;
V_9 = F_177 ( V_22 ) ;
( void ) F_178 ( V_9 , V_482 , V_22 , & abort -> V_125 . V_349 ,
0 , 0 , V_72 , V_399 ) ;
if ( V_22 -> V_71 )
F_279 ( & V_9 -> V_145 . V_146 [ 4 ] ) ;
( void ) F_169 ( V_22 , V_9 , V_114 , V_397 ) ;
F_280 ( V_22 , abort , & V_688 , & V_689 ) ;
F_282 ( & V_22 -> V_29 -> V_30 , L_177 ,
V_243 , V_689 , V_688 ) ;
V_339 = V_9 -> V_24 ;
switch ( V_339 -> V_36 ) {
case V_674 :
break;
case V_369 :
V_21 = F_157 ( V_22 , V_9 ) ;
break;
case V_368 :
V_21 = - 1 ;
break;
default:
F_282 ( & V_22 -> V_29 -> V_30 , L_178 ,
V_243 , V_689 , V_688 ) ;
F_175 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_107 ( V_22 , V_9 ) ;
F_282 ( & V_22 -> V_29 -> V_30 , L_179 ,
V_243 , V_689 , V_688 ) ;
return V_21 ;
}
static void F_283 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_692 , int V_114 )
{
struct V_140 * V_286 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
struct V_137 * V_401 = (struct V_137 * ) V_286 ;
struct V_140 * V_693 =
& V_22 -> V_138 [ V_692 -> V_134 ] ;
struct V_284 * V_671 = V_692 -> V_10 ;
struct V_73 * V_30 = V_671 -> V_42 -> V_80 ;
if ( ! V_30 )
return;
F_284 ( sizeof( struct V_137 ) >
sizeof( struct V_140 ) ) ;
F_77 ( F_250 ( struct V_140 , V_290 ) <
F_250 ( struct V_137 , V_694 ) +
sizeof( V_401 -> V_694 ) ) ;
V_9 -> V_151 = V_157 ;
V_9 -> V_10 = V_695 ;
V_9 -> V_123 = ( T_4 ) V_22 -> V_583 +
( V_9 -> V_134 * sizeof( struct V_140 ) ) ;
F_77 ( V_9 -> V_123 & 0x0000007F ) ;
memset ( V_401 , 0 , sizeof( * V_286 ) ) ;
V_401 -> V_696 = V_697 ;
V_401 -> V_114 = V_114 ;
V_401 -> V_698 = V_699 ;
V_401 -> V_403 = F_140 ( V_30 -> V_188 ) ;
memset ( V_401 -> V_700 , 0 , sizeof( V_401 -> V_700 ) ) ;
V_401 -> V_349 = F_135 ( V_9 -> V_134 << V_592 ) ;
V_401 -> V_701 = F_135 ( F_132 ( V_693 -> V_591 ) ) ;
V_401 -> V_702 = F_135 ( V_9 -> V_123 +
F_250 ( struct V_140 , V_290 ) ) ;
V_401 -> V_694 = F_140 ( sizeof( V_286 -> V_290 ) ) ;
}
static int F_285 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_114 )
{
int V_21 = V_382 ;
struct V_284 * V_671 ;
struct V_73 * V_30 ;
unsigned char V_703 [ 8 ] ;
unsigned char * V_704 = & V_703 [ 0 ] ;
V_671 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_671 -> V_42 -> V_80 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_180 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_181 ,
V_22 -> V_59 -> V_102 , V_30 -> V_103 , V_30 -> V_104 , V_30 -> V_105 ,
L_182 , V_72 ) ;
if ( ! V_30 -> V_91 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_183 ) ;
return - 1 ;
}
if ( ! F_224 ( V_22 , abort , V_704 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_184 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_185 ,
V_704 ) ;
V_21 = F_181 ( V_22 , V_30 , V_704 , V_686 , V_114 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_186 ,
V_704 ) ;
return V_21 ;
}
if ( F_184 ( V_22 , V_704 , V_114 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_704 ) ;
return - 1 ;
}
F_96 ( & V_22 -> V_29 -> V_30 ,
L_188 ,
V_704 ) ;
return V_21 ;
}
static int F_286 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_114 )
{
int V_21 = V_382 ;
struct V_8 * V_9 ;
T_7 V_688 , V_689 ;
struct V_73 * V_30 ;
struct V_140 * V_286 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 )
return - 1 ;
if ( ! V_30 -> V_91 && ! V_30 -> V_189 )
return - 1 ;
V_9 = F_177 ( V_22 ) ;
F_283 ( V_9 , V_22 , abort , V_114 ) ;
V_286 = & V_22 -> V_138 [ V_9 -> V_134 ] ;
( void ) F_169 ( V_22 , V_9 , V_114 , V_397 ) ;
F_280 ( V_22 , abort , & V_688 , & V_689 ) ;
F_282 ( & V_22 -> V_29 -> V_30 ,
L_189 ,
V_243 , V_689 , V_688 ) ;
F_282 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_243 , V_689 , V_688 , V_286 -> V_290 . V_291 ) ;
switch ( V_286 -> V_290 . V_291 ) {
case V_318 :
case V_319 :
V_21 = 0 ;
break;
case V_320 :
case V_306 :
case V_321 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_243 , V_689 , V_688 ,
V_286 -> V_290 . V_291 ) ;
V_21 = - 1 ;
}
F_107 ( V_22 , V_9 ) ;
F_282 ( & V_22 -> V_29 -> V_30 , L_179 , V_243 ,
V_689 , V_688 ) ;
return V_21 ;
}
static int F_287 ( struct V_1 * V_22 ,
struct V_73 * V_30 , struct V_8 * abort , int V_114 )
{
if ( abort -> V_151 == V_155 ) {
if ( ( V_705 & V_22 -> V_706 ) ||
V_30 -> V_74 )
return F_286 ( V_22 , abort ,
V_114 ) ;
else
return F_285 ( V_22 ,
V_30 -> V_72 ,
abort , V_114 ) ;
}
return F_281 ( V_22 , V_30 -> V_72 , abort , V_114 ) ;
}
static int F_288 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_151 == V_155 )
return V_22 -> V_138 [ V_9 -> V_134 ] . V_114 ;
return V_9 -> V_125 . V_129 ;
}
static inline int F_289 ( struct V_1 * V_22 )
{
#define F_290 5000
return ! F_291 ( V_22 -> V_707 ,
F_292 ( & V_22 -> V_708 ) >= 0 ,
F_168 ( F_290 ) ) ;
}
static int F_293 ( struct V_284 * V_709 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_284 * V_710 ;
char V_682 [ 256 ] ;
int V_711 = 0 ;
T_7 V_689 , V_688 ;
int V_240 , V_114 ;
if ( V_709 == NULL )
return V_683 ;
if ( V_709 -> V_42 == NULL )
return V_683 ;
V_22 = F_1 ( V_709 -> V_42 ) ;
if ( V_22 == NULL )
return V_683 ;
V_30 = V_709 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_192 ,
V_682 ) ;
return V_683 ;
}
if ( F_13 ( V_22 ) ) {
F_71 ( V_244 , V_22 , V_30 ,
L_193 ) ;
return V_683 ;
}
if ( F_278 ( V_22 ) ) {
F_71 ( V_244 , V_22 , V_30 ,
L_194 ) ;
return V_683 ;
}
if ( ! ( V_712 & V_22 -> V_706 ) &&
! ( V_713 & V_22 -> V_706 ) )
return V_683 ;
memset ( V_682 , 0 , sizeof( V_682 ) ) ;
V_711 += sprintf ( V_682 + V_711 , L_195 ,
V_22 -> V_59 -> V_102 , V_709 -> V_42 -> V_714 ,
V_709 -> V_42 -> V_715 , V_709 -> V_42 -> V_105 ,
L_196 , V_709 ) ;
abort = (struct V_8 * ) V_709 -> V_628 ;
if ( abort == NULL ) {
return V_684 ;
}
V_240 = F_105 ( & abort -> V_240 ) ;
if ( V_240 == 1 ) {
F_107 ( V_22 , abort ) ;
return V_684 ;
}
if ( abort -> V_151 != V_155 &&
abort -> V_151 != V_152 && ! V_30 -> V_491 ) {
F_107 ( V_22 , abort ) ;
return V_683 ;
}
if ( abort -> V_10 != V_709 ) {
F_107 ( V_22 , abort ) ;
return V_684 ;
}
abort -> V_12 = true ;
F_280 ( V_22 , abort , & V_688 , & V_689 ) ;
V_114 = F_288 ( V_22 , abort ) ;
V_711 += sprintf ( V_682 + V_711 , L_197 , V_689 , V_688 ) ;
V_710 = abort -> V_10 ;
if ( V_710 != NULL )
V_711 += sprintf ( V_682 + V_711 ,
L_198 ,
V_710 -> V_562 , V_710 -> V_575 [ 0 ] , V_710 -> V_575 [ 1 ] ,
V_710 -> V_716 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_199 , V_682 ) ;
F_71 ( V_244 , V_22 , V_30 , L_196 ) ;
if ( F_289 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_200 ,
V_682 ) ;
F_107 ( V_22 , abort ) ;
return V_683 ;
}
V_21 = F_287 ( V_22 , V_30 , abort , V_114 ) ;
F_57 ( & V_22 -> V_708 ) ;
F_147 ( & V_22 -> V_707 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_201 , V_682 ) ;
F_71 ( V_244 , V_22 , V_30 ,
L_202 ) ;
F_107 ( V_22 , abort ) ;
return V_683 ;
}
F_96 ( & V_22 -> V_29 -> V_30 , L_203 , V_682 ) ;
F_183 ( V_22 -> V_324 ,
abort -> V_10 != V_709 || F_13 ( V_22 ) ) ;
F_107 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_684 : V_683 ;
}
static struct V_8 * F_262 ( struct V_1 * V_22 ,
struct V_284 * V_671 )
{
int V_672 = F_274 ( V_671 ) ;
struct V_8 * V_9 = V_22 -> V_239 + V_672 ;
if ( V_672 < V_663 || V_672 >= V_22 -> V_237 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_204 ,
V_672 , V_663 , V_22 -> V_237 - 1 ) ;
F_180 () ;
}
F_57 ( & V_9 -> V_240 ) ;
if ( F_46 ( ! F_4 ( V_9 ) ) ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_205 ,
V_672 ) ;
if ( V_9 -> V_10 != NULL )
F_294 ( V_9 -> V_10 ) ;
F_294 ( V_671 ) ;
}
F_258 ( V_22 , V_672 , V_9 ) ;
return V_9 ;
}
static void F_149 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_47 ( & V_9 -> V_240 ) ;
}
static struct V_8 * F_177 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_240 , V_68 ;
int V_717 = 0 ;
for (; ; ) {
V_68 = F_295 ( V_22 -> V_718 ,
V_663 ,
V_717 ) ;
if ( F_46 ( V_68 >= V_663 ) ) {
V_717 = 0 ;
continue;
}
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_105 ( & V_9 -> V_240 ) ;
if ( F_46 ( V_240 > 1 ) ) {
F_107 ( V_22 , V_9 ) ;
V_717 = ( V_68 + 1 ) % V_663 ;
continue;
}
F_296 ( V_68 & ( V_621 - 1 ) ,
V_22 -> V_718 + ( V_68 / V_621 ) ) ;
break;
}
F_258 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_107 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_59 ( & V_9 -> V_240 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_239 ;
F_297 ( V_68 & ( V_621 - 1 ) ,
V_22 -> V_718 + ( V_68 / V_621 ) ) ;
}
}
static int F_298 ( struct V_2 * V_30 , int V_285 ,
void T_8 * V_719 )
{
T_9 T_8 * V_720 =
( T_9 T_8 * ) V_719 ;
T_10 V_721 ;
T_10 T_8 * V_722 = F_299 ( sizeof( V_721 ) ) ;
int V_723 ;
T_4 V_132 ;
memset ( & V_721 , 0 , sizeof( V_721 ) ) ;
V_723 = 0 ;
V_723 |= F_300 ( & V_721 . V_724 , & V_720 -> V_724 ,
sizeof( V_721 . V_724 ) ) ;
V_723 |= F_300 ( & V_721 . V_145 , & V_720 -> V_145 ,
sizeof( V_721 . V_145 ) ) ;
V_723 |= F_300 ( & V_721 . V_725 , & V_720 -> V_725 ,
sizeof( V_721 . V_725 ) ) ;
V_723 |= F_301 ( V_721 . V_726 , & V_720 -> V_726 ) ;
V_723 |= F_301 ( V_132 , & V_720 -> V_45 ) ;
V_721 . V_45 = F_302 ( V_132 ) ;
V_723 |= F_303 ( V_722 , & V_721 , sizeof( V_721 ) ) ;
if ( V_723 )
return - V_727 ;
V_723 = F_304 ( V_30 , V_728 , V_722 ) ;
if ( V_723 )
return V_723 ;
V_723 |= F_305 ( & V_720 -> V_725 , & V_722 -> V_725 ,
sizeof( V_720 -> V_725 ) ) ;
if ( V_723 )
return - V_727 ;
return V_723 ;
}
static int F_306 ( struct V_2 * V_30 ,
int V_285 , void T_8 * V_719 )
{
T_11 T_8 * V_720 =
( T_11 T_8 * ) V_719 ;
T_12 V_721 ;
T_12 T_8 * V_722 =
F_299 ( sizeof( V_721 ) ) ;
int V_723 ;
T_4 V_132 ;
memset ( & V_721 , 0 , sizeof( V_721 ) ) ;
V_723 = 0 ;
V_723 |= F_300 ( & V_721 . V_724 , & V_720 -> V_724 ,
sizeof( V_721 . V_724 ) ) ;
V_723 |= F_300 ( & V_721 . V_145 , & V_720 -> V_145 ,
sizeof( V_721 . V_145 ) ) ;
V_723 |= F_300 ( & V_721 . V_725 , & V_720 -> V_725 ,
sizeof( V_721 . V_725 ) ) ;
V_723 |= F_301 ( V_721 . V_726 , & V_720 -> V_726 ) ;
V_723 |= F_301 ( V_721 . V_729 , & V_720 -> V_729 ) ;
V_723 |= F_301 ( V_132 , & V_720 -> V_45 ) ;
V_721 . V_45 = F_302 ( V_132 ) ;
V_723 |= F_303 ( V_722 , & V_721 , sizeof( V_721 ) ) ;
if ( V_723 )
return - V_727 ;
V_723 = F_304 ( V_30 , V_730 , V_722 ) ;
if ( V_723 )
return V_723 ;
V_723 |= F_305 ( & V_720 -> V_725 , & V_722 -> V_725 ,
sizeof( V_720 -> V_725 ) ) ;
if ( V_723 )
return - V_727 ;
return V_723 ;
}
static int F_307 ( struct V_2 * V_30 , int V_285 , void T_8 * V_719 )
{
switch ( V_285 ) {
case V_731 :
case V_732 :
case V_733 :
case V_734 :
case V_735 :
case V_736 :
case V_737 :
case V_738 :
case V_739 :
case V_740 :
case V_741 :
case V_742 :
case V_743 :
case V_744 :
case V_745 :
return F_304 ( V_30 , V_285 , V_719 ) ;
case V_746 :
return F_298 ( V_30 , V_285 , V_719 ) ;
case V_747 :
return F_306 ( V_30 , V_285 , V_719 ) ;
default:
return - V_748 ;
}
}
static int F_308 ( struct V_1 * V_22 , void T_8 * V_749 )
{
struct V_750 V_751 ;
if ( ! V_749 )
return - V_55 ;
V_751 . V_752 = F_309 ( V_22 -> V_29 -> V_103 ) ;
V_751 . V_103 = V_22 -> V_29 -> V_103 -> V_753 ;
V_751 . V_754 = V_22 -> V_29 -> V_755 ;
V_751 . V_67 = V_22 -> V_67 ;
if ( F_303 ( V_749 , & V_751 , sizeof( V_751 ) ) )
return - V_727 ;
return 0 ;
}
static int F_310 ( struct V_1 * V_22 , void T_8 * V_749 )
{
T_13 V_756 ;
unsigned char V_757 , V_758 , V_759 ;
int V_21 ;
V_21 = sscanf ( V_760 , L_206 ,
& V_757 , & V_758 , & V_759 ) ;
if ( V_21 != 3 ) {
F_96 ( & V_22 -> V_29 -> V_30 , L_207
L_208 , V_760 ) ;
V_757 = 0 ;
V_758 = 0 ;
V_759 = 0 ;
}
V_756 = ( V_757 << 16 ) | ( V_758 << 8 ) | V_759 ;
if ( ! V_749 )
return - V_55 ;
if ( F_303 ( V_749 , & V_756 , sizeof( T_13 ) ) )
return - V_727 ;
return 0 ;
}
static int F_311 ( struct V_1 * V_22 , void T_8 * V_749 )
{
T_10 V_761 ;
struct V_8 * V_9 ;
char * V_762 = NULL ;
T_5 V_268 ;
int V_21 = 0 ;
if ( ! V_749 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_763 ;
if ( F_300 ( & V_761 , V_749 , sizeof( V_761 ) ) )
return - V_727 ;
if ( ( V_761 . V_726 < 1 ) &&
( V_761 . V_145 . Type . V_764 != V_634 ) ) {
return - V_55 ;
}
if ( V_761 . V_726 > 0 ) {
V_762 = F_93 ( V_761 . V_726 , V_204 ) ;
if ( V_762 == NULL )
return - V_262 ;
if ( V_761 . V_145 . Type . V_764 & V_632 ) {
if ( F_300 ( V_762 , V_761 . V_45 ,
V_761 . V_726 ) ) {
V_21 = - V_727 ;
goto V_765;
}
} else {
memset ( V_762 , 0 , V_761 . V_726 ) ;
}
}
V_9 = F_177 ( V_22 ) ;
V_9 -> V_151 = V_402 ;
V_9 -> V_10 = V_695 ;
V_9 -> V_125 . V_129 = 0 ;
if ( V_761 . V_726 > 0 ) {
V_9 -> V_125 . V_126 = 1 ;
V_9 -> V_125 . V_281 = F_161 ( 1 ) ;
} else {
V_9 -> V_125 . V_126 = 0 ;
V_9 -> V_125 . V_281 = F_161 ( 0 ) ;
}
memcpy ( & V_9 -> V_125 . V_350 , & V_761 . V_724 , sizeof( V_9 -> V_125 . V_350 ) ) ;
memcpy ( & V_9 -> V_145 , & V_761 . V_145 ,
sizeof( V_9 -> V_145 ) ) ;
if ( V_761 . V_726 > 0 ) {
V_268 = F_133 ( V_22 -> V_29 , V_762 ,
V_761 . V_726 , V_766 ) ;
if ( F_134 ( & V_22 -> V_29 -> V_30 , ( V_373 ) V_268 ) ) {
V_9 -> V_277 [ 0 ] . V_283 = F_135 ( 0 ) ;
V_9 -> V_277 [ 0 ] . V_282 = F_140 ( 0 ) ;
V_21 = - V_262 ;
goto V_395;
}
V_9 -> V_277 [ 0 ] . V_283 = F_135 ( V_268 ) ;
V_9 -> V_277 [ 0 ] . V_282 = F_140 ( V_761 . V_726 ) ;
V_9 -> V_277 [ 0 ] . V_279 = F_140 ( V_377 ) ;
}
V_21 = F_169 ( V_22 , V_9 , V_128 ,
V_381 ) ;
if ( V_761 . V_726 > 0 )
F_162 ( V_22 -> V_29 , V_9 , 1 , V_766 ) ;
F_312 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_388 ;
goto V_395;
}
memcpy ( & V_761 . V_725 , V_9 -> V_24 ,
sizeof( V_761 . V_725 ) ) ;
if ( F_303 ( V_749 , & V_761 , sizeof( V_761 ) ) ) {
V_21 = - V_727 ;
goto V_395;
}
if ( ( V_761 . V_145 . Type . V_764 & V_633 ) &&
V_761 . V_726 > 0 ) {
if ( F_303 ( V_761 . V_45 , V_762 , V_761 . V_726 ) ) {
V_21 = - V_727 ;
goto V_395;
}
}
V_395:
F_107 ( V_22 , V_9 ) ;
V_765:
F_82 ( V_762 ) ;
return V_21 ;
}
static int F_313 ( struct V_1 * V_22 , void T_8 * V_749 )
{
T_12 * V_767 ;
struct V_8 * V_9 ;
unsigned char * * V_762 = NULL ;
int * V_768 = NULL ;
T_5 V_268 ;
T_14 V_371 = 0 ;
int V_49 = 0 ;
T_4 V_769 ;
T_4 V_770 ;
T_14 T_8 * V_771 ;
if ( ! V_749 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_763 ;
V_767 = F_93 ( sizeof( * V_767 ) , V_204 ) ;
if ( ! V_767 ) {
V_49 = - V_262 ;
goto V_772;
}
if ( F_300 ( V_767 , V_749 , sizeof( * V_767 ) ) ) {
V_49 = - V_727 ;
goto V_772;
}
if ( ( V_767 -> V_726 < 1 ) &&
( V_767 -> V_145 . Type . V_764 != V_634 ) ) {
V_49 = - V_55 ;
goto V_772;
}
if ( V_767 -> V_729 > V_773 ) {
V_49 = - V_55 ;
goto V_772;
}
if ( V_767 -> V_726 > V_767 -> V_729 * V_774 ) {
V_49 = - V_55 ;
goto V_772;
}
V_762 = F_116 ( V_774 * sizeof( char * ) , V_204 ) ;
if ( ! V_762 ) {
V_49 = - V_262 ;
goto V_772;
}
V_768 = F_93 ( V_774 * sizeof( int ) , V_204 ) ;
if ( ! V_768 ) {
V_49 = - V_262 ;
goto V_772;
}
V_769 = V_767 -> V_726 ;
V_771 = V_767 -> V_45 ;
while ( V_769 ) {
V_770 = ( V_769 > V_767 -> V_729 ) ? V_767 -> V_729 : V_769 ;
V_768 [ V_371 ] = V_770 ;
V_762 [ V_371 ] = F_93 ( V_770 , V_204 ) ;
if ( V_762 [ V_371 ] == NULL ) {
V_49 = - V_262 ;
goto V_772;
}
if ( V_767 -> V_145 . Type . V_764 & V_632 ) {
if ( F_300 ( V_762 [ V_371 ] , V_771 , V_770 ) ) {
V_49 = - V_727 ;
goto V_772;
}
} else
memset ( V_762 [ V_371 ] , 0 , V_770 ) ;
V_769 -= V_770 ;
V_771 += V_770 ;
V_371 ++ ;
}
V_9 = F_177 ( V_22 ) ;
V_9 -> V_151 = V_402 ;
V_9 -> V_10 = V_695 ;
V_9 -> V_125 . V_129 = 0 ;
V_9 -> V_125 . V_126 = ( T_1 ) V_371 ;
V_9 -> V_125 . V_281 = F_161 ( V_371 ) ;
memcpy ( & V_9 -> V_125 . V_350 , & V_767 -> V_724 , sizeof( V_9 -> V_125 . V_350 ) ) ;
memcpy ( & V_9 -> V_145 , & V_767 -> V_145 , sizeof( V_9 -> V_145 ) ) ;
if ( V_767 -> V_726 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_371 ; V_68 ++ ) {
V_268 = F_133 ( V_22 -> V_29 , V_762 [ V_68 ] ,
V_768 [ V_68 ] , V_766 ) ;
if ( F_134 ( & V_22 -> V_29 -> V_30 ,
( V_373 ) V_268 ) ) {
V_9 -> V_277 [ V_68 ] . V_283 = F_135 ( 0 ) ;
V_9 -> V_277 [ V_68 ] . V_282 = F_140 ( 0 ) ;
F_162 ( V_22 -> V_29 , V_9 , V_68 ,
V_766 ) ;
V_49 = - V_262 ;
goto V_775;
}
V_9 -> V_277 [ V_68 ] . V_283 = F_135 ( V_268 ) ;
V_9 -> V_277 [ V_68 ] . V_282 = F_140 ( V_768 [ V_68 ] ) ;
V_9 -> V_277 [ V_68 ] . V_279 = F_140 ( 0 ) ;
}
V_9 -> V_277 [ -- V_68 ] . V_279 = F_140 ( V_377 ) ;
}
V_49 = F_169 ( V_22 , V_9 , V_128 ,
V_381 ) ;
if ( V_371 )
F_162 ( V_22 -> V_29 , V_9 , V_371 , V_766 ) ;
F_312 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_388 ;
goto V_775;
}
memcpy ( & V_767 -> V_725 , V_9 -> V_24 , sizeof( V_767 -> V_725 ) ) ;
if ( F_303 ( V_749 , V_767 , sizeof( * V_767 ) ) ) {
V_49 = - V_727 ;
goto V_775;
}
if ( ( V_767 -> V_145 . Type . V_764 & V_633 ) && V_767 -> V_726 > 0 ) {
int V_68 ;
T_14 T_8 * V_776 = V_767 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_371 ; V_68 ++ ) {
if ( F_303 ( V_776 , V_762 [ V_68 ] , V_768 [ V_68 ] ) ) {
V_49 = - V_727 ;
goto V_775;
}
V_776 += V_768 [ V_68 ] ;
}
}
V_49 = 0 ;
V_775:
F_107 ( V_22 , V_9 ) ;
V_772:
if ( V_762 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_371 ; V_68 ++ )
F_82 ( V_762 [ V_68 ] ) ;
F_82 ( V_762 ) ;
}
F_82 ( V_768 ) ;
F_82 ( V_767 ) ;
return V_49 ;
}
static void F_312 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_296 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_304 ( struct V_2 * V_30 , int V_285 , void T_8 * V_719 )
{
struct V_1 * V_22 ;
void T_8 * V_749 = ( void T_8 * ) V_719 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_285 ) {
case V_741 :
case V_742 :
case V_743 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_731 :
return F_308 ( V_22 , V_749 ) ;
case V_739 :
return F_310 ( V_22 , V_749 ) ;
case V_728 :
if ( F_292 ( & V_22 -> V_777 ) < 0 )
return - V_778 ;
V_21 = F_311 ( V_22 , V_749 ) ;
F_57 ( & V_22 -> V_777 ) ;
return V_21 ;
case V_730 :
if ( F_292 ( & V_22 -> V_777 ) < 0 )
return - V_778 ;
V_21 = F_313 ( V_22 , V_749 ) ;
F_57 ( & V_22 -> V_777 ) ;
return V_21 ;
default:
return - V_779 ;
}
}
static void F_314 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_398 )
{
struct V_8 * V_9 ;
V_9 = F_177 ( V_22 ) ;
( void ) F_178 ( V_9 , V_685 , V_22 , NULL , 0 , 0 ,
V_159 , V_399 ) ;
V_9 -> V_145 . V_146 [ 1 ] = V_398 ;
V_9 -> V_380 = NULL ;
F_62 ( V_22 , V_9 ) ;
return;
}
static int F_178 ( struct V_8 * V_9 , T_1 V_285 , struct V_1 * V_22 ,
void * V_762 , T_3 V_473 , T_6 V_780 , unsigned char * V_72 ,
int V_151 )
{
int V_781 = V_634 ;
T_5 V_349 ;
V_9 -> V_151 = V_402 ;
V_9 -> V_10 = V_695 ;
V_9 -> V_125 . V_129 = 0 ;
if ( V_762 != NULL && V_473 > 0 ) {
V_9 -> V_125 . V_126 = 1 ;
V_9 -> V_125 . V_281 = F_161 ( 1 ) ;
} else {
V_9 -> V_125 . V_126 = 0 ;
V_9 -> V_125 . V_281 = F_161 ( 0 ) ;
}
memcpy ( V_9 -> V_125 . V_350 . V_351 , V_72 , 8 ) ;
if ( V_151 == V_394 ) {
switch ( V_285 ) {
case V_393 :
if ( V_780 & V_407 ) {
V_9 -> V_145 . V_146 [ 1 ] = 0x01 ;
V_9 -> V_145 . V_146 [ 2 ] = ( V_780 & 0xff ) ;
}
V_9 -> V_145 . V_346 = 6 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_393 ;
V_9 -> V_145 . V_146 [ 4 ] = V_473 & 0xFF ;
break;
case V_463 :
case V_464 :
V_9 -> V_145 . V_346 = 12 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_285 ;
V_9 -> V_145 . V_146 [ 6 ] = ( V_473 >> 24 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 9 ] = V_473 & 0xFF ;
break;
case V_782 :
V_9 -> V_145 . V_346 = 16 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 6 ] = V_782 ;
break;
case V_784 :
V_9 -> V_145 . V_346 = 16 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 ,
V_631 , V_632 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_143 ;
V_9 -> V_145 . V_146 [ 6 ] = V_784 ;
break;
case V_785 :
V_9 -> V_145 . V_346 = 12 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 ,
V_631 , V_632 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_143 ;
V_9 -> V_145 . V_146 [ 6 ] = V_786 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = V_473 & 0xFF ;
break;
case V_480 :
V_9 -> V_145 . V_346 = 6 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_634 ) ;
V_9 -> V_145 . V_629 = 0 ;
break;
case V_425 :
V_9 -> V_145 . V_346 = 12 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_787 ;
V_9 -> V_145 . V_146 [ 1 ] = V_285 ;
V_9 -> V_145 . V_146 [ 6 ] = ( V_473 >> 24 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 9 ] = V_473 & 0xFF ;
break;
case V_788 :
V_9 -> V_145 . V_346 = 10 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 6 ] = V_788 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
break;
case V_432 :
V_9 -> V_145 . V_346 = 10 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 6 ] = V_432 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_428 :
V_9 -> V_145 . V_346 = 10 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 6 ] = V_428 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_442 :
V_9 -> V_145 . V_346 = 10 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 6 ] = V_442 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_430 :
V_9 -> V_145 . V_346 = 10 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_633 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_783 ;
V_9 -> V_145 . V_146 [ 1 ] = 0 ;
V_9 -> V_145 . V_146 [ 2 ] = 0 ;
V_9 -> V_145 . V_146 [ 3 ] = 0 ;
V_9 -> V_145 . V_146 [ 4 ] = 0 ;
V_9 -> V_145 . V_146 [ 5 ] = 0 ;
V_9 -> V_145 . V_146 [ 6 ] = V_430 ;
V_9 -> V_145 . V_146 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_145 . V_146 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
V_9 -> V_145 . V_146 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_209 , V_285 ) ;
F_180 () ;
return - 1 ;
}
} else if ( V_151 == V_399 ) {
switch ( V_285 ) {
case V_686 :
V_9 -> V_145 . V_346 = 16 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_634 ) ;
V_9 -> V_145 . V_629 = 0 ;
memset ( & V_9 -> V_145 . V_146 [ 0 ] , 0 , sizeof( V_9 -> V_145 . V_146 ) ) ;
V_9 -> V_145 . V_146 [ 0 ] = V_789 ;
V_9 -> V_145 . V_146 [ 1 ] = V_790 ;
V_9 -> V_145 . V_146 [ 4 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 5 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 6 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 7 ] = 0x00 ;
break;
case V_685 :
V_9 -> V_145 . V_346 = 16 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 , V_631 , V_634 ) ;
V_9 -> V_145 . V_629 = 0 ;
memset ( & V_9 -> V_145 . V_146 [ 0 ] , 0 , sizeof( V_9 -> V_145 . V_146 ) ) ;
V_9 -> V_145 . V_146 [ 0 ] = V_285 ;
V_9 -> V_145 . V_146 [ 1 ] = V_791 ;
V_9 -> V_145 . V_146 [ 4 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 5 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 6 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 7 ] = 0x00 ;
break;
case V_482 :
memcpy ( & V_349 , V_762 , sizeof( V_349 ) ) ;
F_282 ( & V_22 -> V_29 -> V_30 ,
L_210 ,
V_349 , V_9 -> V_125 . V_349 ) ;
V_9 -> V_145 . V_346 = 16 ;
V_9 -> V_145 . V_630 =
F_255 ( V_151 ,
V_631 , V_632 ) ;
V_9 -> V_145 . V_629 = 0 ;
V_9 -> V_145 . V_146 [ 0 ] = V_792 ;
V_9 -> V_145 . V_146 [ 1 ] = V_793 ;
V_9 -> V_145 . V_146 [ 2 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_145 . V_146 [ 4 ] , & V_349 , sizeof( V_349 ) ) ;
V_9 -> V_145 . V_146 [ 12 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 13 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 14 ] = 0x00 ;
V_9 -> V_145 . V_146 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_211 ,
V_285 ) ;
F_180 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_212 , V_151 ) ;
F_180 () ;
}
switch ( F_315 ( V_9 -> V_145 . V_630 ) ) {
case V_633 :
V_781 = V_396 ;
break;
case V_632 :
V_781 = V_272 ;
break;
case V_634 :
V_781 = V_376 ;
break;
default:
V_781 = V_766 ;
}
if ( F_163 ( V_22 -> V_29 , V_9 , V_762 , V_473 , V_781 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_316 ( T_16 V_794 , T_16 V_473 )
{
T_16 V_795 = ( ( T_16 ) V_794 ) & V_796 ;
T_16 V_797 = ( ( T_16 ) V_794 ) - V_795 ;
void T_15 * V_798 = F_317 ( V_795 ,
V_797 + V_473 ) ;
return V_798 ? ( V_798 + V_797 ) : NULL ;
}
static inline unsigned long F_318 ( struct V_1 * V_22 , T_1 V_111 )
{
return V_22 -> V_116 . V_117 ( V_22 , V_111 ) ;
}
static inline bool F_319 ( struct V_1 * V_22 )
{
return V_22 -> V_116 . V_799 ( V_22 ) ;
}
static inline long F_320 ( struct V_1 * V_22 )
{
return ( V_22 -> V_116 . V_799 ( V_22 ) == 0 ) ||
( V_22 -> V_800 == 0 ) ;
}
static inline int F_321 ( struct V_1 * V_22 , T_4 V_801 ,
T_4 V_802 )
{
if ( F_46 ( V_801 >= V_22 -> V_237 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_213 , V_802 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_63 ( struct V_8 * V_9 )
{
F_58 ( V_9 -> V_22 , V_9 ) ;
if ( F_49 ( V_9 -> V_151 == V_152 || V_9 -> V_151 == V_341
|| V_9 -> V_151 == V_155 ) )
F_158 ( V_9 ) ;
else if ( V_9 -> V_151 == V_402 || V_9 -> V_151 == V_157 )
F_322 ( V_9 -> V_380 ) ;
}
static inline void F_323 ( struct V_1 * V_22 ,
T_4 V_802 )
{
T_4 V_801 ;
struct V_8 * V_9 ;
V_801 = V_802 >> V_592 ;
if ( ! F_321 ( V_22 , V_801 , V_802 ) ) {
V_9 = V_22 -> V_239 + V_801 ;
F_63 ( V_9 ) ;
}
}
static int F_324 ( struct V_1 * V_22 )
{
if ( F_49 ( ! V_803 ) )
return 0 ;
if ( F_49 ( V_22 -> V_800 ) )
return 0 ;
F_96 ( & V_22 -> V_29 -> V_30 , L_214
L_215 ) ;
return 1 ;
}
static struct V_1 * F_325 ( T_1 * V_804 )
{
return F_260 ( ( V_804 - * V_804 ) , struct V_1 , V_111 [ 0 ] ) ;
}
static T_17 F_326 ( int V_668 , void * V_804 )
{
struct V_1 * V_22 = F_325 ( V_804 ) ;
T_1 V_111 = * ( T_1 * ) V_804 ;
T_4 V_802 ;
if ( F_324 ( V_22 ) )
return V_805 ;
if ( F_320 ( V_22 ) )
return V_805 ;
V_22 -> V_806 = F_327 () ;
while ( F_319 ( V_22 ) ) {
V_802 = F_318 ( V_22 , V_111 ) ;
while ( V_802 != V_121 )
V_802 = F_45 ( V_22 , V_111 ) ;
}
return V_807 ;
}
static T_17 F_328 ( int V_668 , void * V_804 )
{
struct V_1 * V_22 = F_325 ( V_804 ) ;
T_4 V_802 ;
T_1 V_111 = * ( T_1 * ) V_804 ;
if ( F_324 ( V_22 ) )
return V_805 ;
V_22 -> V_806 = F_327 () ;
V_802 = F_318 ( V_22 , V_111 ) ;
while ( V_802 != V_121 )
V_802 = F_45 ( V_22 , V_111 ) ;
return V_807 ;
}
static T_17 F_329 ( int V_668 , void * V_804 )
{
struct V_1 * V_22 = F_325 ( ( T_1 * ) V_804 ) ;
T_4 V_802 ;
T_1 V_111 = * ( T_1 * ) V_804 ;
if ( F_320 ( V_22 ) )
return V_805 ;
V_22 -> V_806 = F_327 () ;
while ( F_319 ( V_22 ) ) {
V_802 = F_318 ( V_22 , V_111 ) ;
while ( V_802 != V_121 ) {
F_323 ( V_22 , V_802 ) ;
V_802 = F_45 ( V_22 , V_111 ) ;
}
}
return V_807 ;
}
static T_17 F_330 ( int V_668 , void * V_804 )
{
struct V_1 * V_22 = F_325 ( V_804 ) ;
T_4 V_802 ;
T_1 V_111 = * ( T_1 * ) V_804 ;
V_22 -> V_806 = F_327 () ;
V_802 = F_318 ( V_22 , V_111 ) ;
while ( V_802 != V_121 ) {
F_323 ( V_22 , V_802 ) ;
V_802 = F_45 ( V_22 , V_111 ) ;
}
return V_807 ;
}
static int F_331 ( struct V_370 * V_29 , unsigned char V_808 ,
unsigned char type )
{
struct V_809 {
struct V_810 V_811 ;
struct V_812 V_145 ;
struct V_813 V_814 ;
};
struct V_809 * V_285 ;
static const T_3 V_815 = sizeof( * V_285 ) +
sizeof( V_285 -> V_814 ) ;
V_373 V_816 ;
T_7 V_817 ;
T_4 V_349 ;
void T_15 * V_153 ;
int V_68 , V_723 ;
V_153 = F_332 ( V_29 , 0 ) ;
if ( V_153 == NULL )
return - V_262 ;
V_723 = F_333 ( V_29 , F_334 ( 32 ) ) ;
if ( V_723 ) {
F_335 ( V_153 ) ;
return V_723 ;
}
V_285 = F_336 ( V_29 , V_815 , & V_816 ) ;
if ( V_285 == NULL ) {
F_335 ( V_153 ) ;
return - V_262 ;
}
V_817 = F_140 ( V_816 ) ;
V_285 -> V_811 . V_129 = 0 ;
V_285 -> V_811 . V_126 = 0 ;
V_285 -> V_811 . V_281 = F_161 ( 0 ) ;
V_285 -> V_811 . V_349 = F_135 ( V_816 ) ;
memset ( & V_285 -> V_811 . V_350 . V_351 , 0 , 8 ) ;
V_285 -> V_145 . V_346 = 16 ;
V_285 -> V_145 . V_630 =
F_255 ( V_399 , V_818 , V_634 ) ;
V_285 -> V_145 . V_629 = 0 ;
V_285 -> V_145 . V_146 [ 0 ] = V_808 ;
V_285 -> V_145 . V_146 [ 1 ] = type ;
memset ( & V_285 -> V_145 . V_146 [ 2 ] , 0 , 14 ) ;
V_285 -> V_814 . V_283 =
F_135 ( ( F_132 ( V_817 ) + sizeof( * V_285 ) ) ) ;
V_285 -> V_814 . V_282 = F_140 ( sizeof( struct V_338 ) ) ;
F_61 ( F_132 ( V_817 ) , V_153 + V_154 ) ;
for ( V_68 = 0 ; V_68 < V_819 ; V_68 ++ ) {
V_349 = F_337 ( V_153 + V_820 ) ;
if ( ( V_349 & ~ V_821 ) == V_816 )
break;
F_109 ( V_822 ) ;
}
F_335 ( V_153 ) ;
if ( V_68 == V_819 ) {
F_75 ( & V_29 -> V_30 , L_216 ,
V_808 , type ) ;
return - V_383 ;
}
F_338 ( V_29 , V_815 , V_285 , V_816 ) ;
if ( V_349 & V_823 ) {
F_75 ( & V_29 -> V_30 , L_217 ,
V_808 , type ) ;
return - V_388 ;
}
F_96 ( & V_29 -> V_30 , L_218 ,
V_808 , type ) ;
return 0 ;
}
static int F_339 ( struct V_370 * V_29 ,
void T_15 * V_153 , T_4 V_824 )
{
if ( V_824 ) {
F_96 ( & V_29 -> V_30 , L_219 ) ;
F_61 ( V_824 , V_153 + V_825 ) ;
F_109 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_96 ( & V_29 -> V_30 , L_220 ) ;
V_21 = F_340 ( V_29 , V_826 ) ;
if ( V_21 )
return V_21 ;
F_109 ( 500 ) ;
V_21 = F_340 ( V_29 , V_827 ) ;
if ( V_21 )
return V_21 ;
F_109 ( 500 ) ;
}
return 0 ;
}
static void F_341 ( char * V_828 , int V_50 )
{
memset ( V_828 , 0 , V_50 ) ;
strncpy ( V_828 , V_41 L_221 V_760 , V_50 - 1 ) ;
}
static int F_342 ( struct V_829 T_15 * V_830 )
{
char * V_828 ;
int V_68 , V_473 = sizeof( V_830 -> V_828 ) ;
V_828 = F_93 ( V_473 , V_204 ) ;
if ( ! V_828 )
return - V_262 ;
F_341 ( V_828 , V_473 ) ;
for ( V_68 = 0 ; V_68 < V_473 ; V_68 ++ )
F_343 ( V_828 [ V_68 ] , & V_830 -> V_828 [ V_68 ] ) ;
F_82 ( V_828 ) ;
return 0 ;
}
static void F_344 ( struct V_829 T_15 * V_830 ,
unsigned char * V_831 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_830 -> V_828 ) ; V_68 ++ )
V_831 [ V_68 ] = F_345 ( & V_830 -> V_828 [ V_68 ] ) ;
}
static int F_346 ( struct V_829 T_15 * V_830 )
{
char * V_831 , * V_832 ;
int V_21 , V_473 = sizeof( V_830 -> V_828 ) ;
V_832 = F_93 ( 2 * V_473 , V_204 ) ;
if ( ! V_832 )
return - V_262 ;
V_831 = V_832 + V_473 ;
F_341 ( V_832 , V_473 ) ;
F_344 ( V_830 , V_831 ) ;
V_21 = ! memcmp ( V_831 , V_832 , V_473 ) ;
F_82 ( V_832 ) ;
return V_21 ;
}
static int F_347 ( struct V_370 * V_29 , T_4 V_67 )
{
T_5 V_833 ;
T_4 V_834 ;
T_5 V_835 ;
void T_15 * V_153 ;
unsigned long V_836 ;
T_4 V_837 ;
int V_21 ;
struct V_829 T_15 * V_830 ;
T_4 V_824 ;
T_6 V_838 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_222 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_839 ;
F_348 ( V_29 , 4 , & V_838 ) ;
F_349 ( V_29 ) ;
V_21 = F_350 ( V_29 , & V_836 ) ;
if ( V_21 )
return V_21 ;
V_153 = F_316 ( V_836 , 0x250 ) ;
if ( ! V_153 )
return - V_262 ;
V_21 = F_351 ( V_29 , V_153 , & V_834 ,
& V_835 , & V_833 ) ;
if ( V_21 )
goto V_840;
V_830 = F_316 ( F_352 ( V_29 ,
V_835 ) + V_833 , sizeof( * V_830 ) ) ;
if ( ! V_830 ) {
V_21 = - V_262 ;
goto V_840;
}
V_21 = F_342 ( V_830 ) ;
if ( V_21 )
goto V_841;
V_837 = F_337 ( & V_830 -> V_837 ) ;
V_824 = V_837 & V_842 ;
if ( V_824 ) {
V_824 = V_843 ;
} else {
V_824 = V_837 & V_844 ;
if ( V_824 ) {
F_9 ( & V_29 -> V_30 ,
L_223 ) ;
V_21 = - V_839 ;
goto V_841;
}
}
V_21 = F_339 ( V_29 , V_153 , V_824 ) ;
if ( V_21 )
goto V_841;
F_353 ( V_29 ) ;
F_354 ( V_29 , 4 , V_838 ) ;
F_109 ( V_845 ) ;
V_21 = F_355 ( V_29 , V_153 , V_846 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_224 ) ;
goto V_841;
}
V_21 = F_346 ( V_153 ) ;
if ( V_21 < 0 )
goto V_841;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_225
L_226 ) ;
V_21 = - V_839 ;
} else {
F_96 ( & V_29 -> V_30 , L_227 ) ;
}
V_841:
F_335 ( V_830 ) ;
V_840:
F_335 ( V_153 ) ;
return V_21 ;
}
static void F_356 ( struct V_42 * V_30 , struct V_829 T_15 * V_847 )
{
#ifdef F_357
int V_68 ;
char V_848 [ 17 ] ;
F_96 ( V_30 , L_228 ) ;
F_96 ( V_30 , L_229 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_848 [ V_68 ] = F_345 ( & ( V_847 -> V_849 [ V_68 ] ) ) ;
V_848 [ 4 ] = '\0' ;
F_96 ( V_30 , L_230 , V_848 ) ;
F_96 ( V_30 , L_231 , F_337 ( & ( V_847 -> V_850 ) ) ) ;
F_96 ( V_30 , L_232 ,
F_337 ( & ( V_847 -> V_851 ) ) ) ;
F_96 ( V_30 , L_233 ,
F_337 ( & ( V_847 -> V_852 ) ) ) ;
F_96 ( V_30 , L_234 ,
F_337 ( & ( V_847 -> V_853 . V_854 ) ) ) ;
F_96 ( V_30 , L_235 ,
F_337 ( & ( V_847 -> V_853 . V_855 ) ) ) ;
F_96 ( V_30 , L_236 ,
F_337 ( & ( V_847 -> V_853 . V_856 ) ) ) ;
F_96 ( V_30 , L_237 ,
F_337 ( & ( V_847 -> V_857 ) ) ) ;
F_96 ( V_30 , L_238 , F_337 ( & ( V_847 -> V_858 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_848 [ V_68 ] = F_345 ( & ( V_847 -> V_859 [ V_68 ] ) ) ;
V_848 [ 16 ] = '\0' ;
F_96 ( V_30 , L_239 , V_848 ) ;
F_96 ( V_30 , L_240 ,
F_337 ( & ( V_847 -> V_860 ) ) ) ;
#endif
}
static int F_358 ( struct V_370 * V_29 , unsigned long V_861 )
{
int V_68 , V_717 , V_862 , V_863 ;
if ( V_861 == V_864 )
return 0 ;
V_717 = 0 ;
for ( V_68 = 0 ; V_68 < V_865 ; V_68 ++ ) {
V_863 = F_359 ( V_29 , V_68 ) & V_866 ;
if ( V_863 == V_867 )
V_717 += 4 ;
else {
V_862 = F_359 ( V_29 , V_68 ) &
V_868 ;
switch ( V_862 ) {
case V_869 :
case V_870 :
V_717 += 4 ;
break;
case V_871 :
V_717 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_241 ) ;
return - 1 ;
break;
}
}
if ( V_717 == V_861 - V_864 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_360 ( struct V_1 * V_22 )
{
F_361 ( V_22 -> V_29 ) ;
V_22 -> V_127 = 0 ;
}
static int F_362 ( struct V_1 * V_22 )
{
unsigned int V_78 = V_872 ;
int V_873 ;
switch ( V_22 -> V_67 ) {
case 0x40700E11 :
case 0x40800E11 :
case 0x40820E11 :
case 0x40830E11 :
break;
default:
V_873 = F_363 ( V_22 -> V_29 , 1 , V_874 ,
V_875 | V_876 ) ;
if ( V_873 > 0 ) {
V_22 -> V_127 = V_873 ;
return 0 ;
}
V_78 |= V_877 ;
break;
}
V_873 = F_363 ( V_22 -> V_29 , 1 , 1 , V_78 ) ;
if ( V_873 < 0 )
return V_873 ;
return 0 ;
}
static int F_364 ( struct V_370 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_878 , V_879 ;
V_878 = V_29 -> V_880 ;
V_879 = V_29 -> V_881 ;
* V_67 = ( ( V_879 << 16 ) & 0xffff0000 ) |
V_878 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_882 ) ; V_68 ++ )
if ( * V_67 == V_882 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_878 != V_883 &&
V_878 != V_884 ) ||
! V_470 ) {
F_9 ( & V_29 -> V_30 , L_242
L_243 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_882 ) - 1 ;
}
static int F_350 ( struct V_370 * V_29 ,
unsigned long * V_885 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_865 ; V_68 ++ )
if ( F_359 ( V_29 , V_68 ) & V_886 ) {
* V_885 = F_352 ( V_29 , V_68 ) ;
F_282 ( & V_29 -> V_30 , L_244 ,
* V_885 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_245 ) ;
return - V_81 ;
}
static int F_355 ( struct V_370 * V_29 , void T_15 * V_153 ,
int V_887 )
{
int V_68 , V_888 ;
T_4 V_889 ;
if ( V_887 )
V_888 = V_890 ;
else
V_888 = V_891 ;
for ( V_68 = 0 ; V_68 < V_888 ; V_68 ++ ) {
V_889 = F_337 ( V_153 + V_892 ) ;
if ( V_887 ) {
if ( V_889 == V_893 )
return 0 ;
} else {
if ( V_889 != V_893 )
return 0 ;
}
F_109 ( V_894 ) ;
}
F_9 ( & V_29 -> V_30 , L_246 ) ;
return - V_81 ;
}
static int F_351 ( struct V_370 * V_29 , void T_15 * V_153 ,
T_4 * V_834 , T_5 * V_835 ,
T_5 * V_833 )
{
* V_834 = F_337 ( V_153 + V_895 ) ;
* V_833 = F_337 ( V_153 + V_896 ) ;
* V_834 &= ( T_4 ) 0x0000ffff ;
* V_835 = F_358 ( V_29 , * V_834 ) ;
if ( * V_835 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_247 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_365 ( struct V_1 * V_22 )
{
if ( V_22 -> V_897 ) {
F_335 ( V_22 -> V_897 ) ;
V_22 -> V_897 = NULL ;
}
if ( V_22 -> V_830 ) {
F_335 ( V_22 -> V_830 ) ;
V_22 -> V_830 = NULL ;
}
}
static int F_366 ( struct V_1 * V_22 )
{
T_5 V_833 ;
T_4 V_834 ;
T_5 V_835 ;
T_4 V_898 ;
int V_21 ;
V_21 = F_351 ( V_22 -> V_29 , V_22 -> V_153 , & V_834 ,
& V_835 , & V_833 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_830 = F_316 ( F_352 ( V_22 -> V_29 ,
V_835 ) + V_833 , sizeof( * V_22 -> V_830 ) ) ;
if ( ! V_22 -> V_830 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_248 ) ;
return - V_262 ;
}
V_21 = F_342 ( V_22 -> V_830 ) ;
if ( V_21 )
return V_21 ;
V_898 = F_337 ( & V_22 -> V_830 -> V_899 ) ;
V_22 -> V_897 = F_316 ( F_352 ( V_22 -> V_29 ,
V_835 ) + V_833 + V_898 ,
sizeof( * V_22 -> V_897 ) ) ;
if ( ! V_22 -> V_897 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_249 ) ;
F_365 ( V_22 ) ;
return - V_262 ;
}
return 0 ;
}
static void F_367 ( struct V_1 * V_22 )
{
#define F_368 16
F_284 ( F_368 <= V_663 ) ;
V_22 -> V_122 = F_337 ( & V_22 -> V_830 -> V_900 ) ;
if ( V_803 && V_22 -> V_122 > 32 )
V_22 -> V_122 = 32 ;
if ( V_22 -> V_122 < F_368 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_250 ,
V_22 -> V_122 ,
F_368 ) ;
V_22 -> V_122 = F_368 ;
}
}
static int F_369 ( struct V_1 * V_22 )
{
return V_22 -> V_263 > 512 ;
}
static void F_370 ( struct V_1 * V_22 )
{
F_367 ( V_22 ) ;
V_22 -> V_237 = V_22 -> V_122 ;
V_22 -> V_263 = F_337 ( & ( V_22 -> V_830 -> V_901 ) ) ;
V_22 -> V_489 = F_337 ( & ( V_22 -> V_830 -> V_837 ) ) ;
if ( F_369 ( V_22 ) ) {
V_22 -> V_278 = 32 ;
V_22 -> V_261 = V_22 -> V_263 - V_22 -> V_278 ;
V_22 -> V_263 -- ;
} else {
V_22 -> V_278 = 31 ;
V_22 -> V_263 = 31 ;
V_22 -> V_261 = 0 ;
}
V_22 -> V_706 = F_337 ( & ( V_22 -> V_830 -> V_706 ) ) ;
if ( ! ( V_712 & V_22 -> V_706 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_251 ) ;
if ( ! ( V_713 & V_22 -> V_706 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_252 ) ;
if ( ! ( V_705 & V_22 -> V_706 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_253 ) ;
}
static inline bool F_371 ( struct V_1 * V_22 )
{
if ( ! F_372 ( V_22 -> V_830 -> V_849 , L_254 , 4 ) ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_255 ) ;
return false ;
}
return true ;
}
static inline void F_373 ( struct V_1 * V_22 )
{
T_4 V_902 ;
V_902 = F_337 ( & ( V_22 -> V_830 -> V_902 ) ) ;
#ifdef F_374
V_902 |= V_903 ;
#endif
V_902 |= V_904 ;
F_61 ( V_902 , & ( V_22 -> V_830 -> V_902 ) ) ;
}
static inline void F_375 ( struct V_1 * V_22 )
{
T_4 V_905 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_905 = F_337 ( V_22 -> V_153 + V_906 ) ;
V_905 |= 0x8000 ;
F_61 ( V_905 , V_22 -> V_153 + V_906 ) ;
}
static int F_376 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_907 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_908 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_907 = F_337 ( V_22 -> V_153 + V_825 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_907 & V_909 ) )
goto V_910;
F_109 ( V_911 ) ;
}
return - V_81 ;
V_910:
return 0 ;
}
static int F_377 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_907 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_912 ; V_68 ++ ) {
if ( V_22 -> V_913 )
goto V_910;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_907 = F_337 ( V_22 -> V_153 + V_825 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_907 & V_914 ) )
goto V_910;
F_109 ( V_915 ) ;
}
return - V_81 ;
V_910:
return 0 ;
}
static int F_378 ( struct V_1 * V_22 )
{
T_4 V_916 ;
V_916 = F_337 ( & ( V_22 -> V_830 -> V_851 ) ) ;
if ( ! ( V_916 & V_917 ) )
return - V_839 ;
V_22 -> V_122 = F_337 ( & ( V_22 -> V_830 -> V_857 ) ) ;
F_61 ( V_918 , & ( V_22 -> V_830 -> V_853 . V_854 ) ) ;
F_61 ( 0 , & V_22 -> V_830 -> V_853 . V_919 ) ;
F_61 ( V_914 , V_22 -> V_153 + V_825 ) ;
if ( F_377 ( V_22 ) )
goto error;
F_356 ( & V_22 -> V_29 -> V_30 , V_22 -> V_830 ) ;
if ( ! ( F_337 ( & ( V_22 -> V_830 -> V_852 ) ) & V_918 ) )
goto error;
V_22 -> V_63 = V_918 ;
return 0 ;
error:
F_75 ( & V_22 -> V_29 -> V_30 , L_256 ) ;
return - V_81 ;
}
static void F_379 ( struct V_1 * V_22 )
{
F_365 ( V_22 ) ;
F_335 ( V_22 -> V_153 ) ;
V_22 -> V_153 = NULL ;
F_360 ( V_22 ) ;
F_380 ( V_22 -> V_29 ) ;
F_381 ( V_22 -> V_29 ) ;
}
static int F_382 ( struct V_1 * V_22 )
{
int V_920 , V_723 ;
V_920 = F_364 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_920 < 0 )
return V_920 ;
V_22 -> V_921 = V_882 [ V_920 ] . V_921 ;
V_22 -> V_116 = * ( V_882 [ V_920 ] . V_116 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_383 ( V_22 -> V_29 , V_922 |
V_923 | V_924 ) ;
V_723 = F_384 ( V_22 -> V_29 ) ;
if ( V_723 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_257 ) ;
F_380 ( V_22 -> V_29 ) ;
return V_723 ;
}
V_723 = F_385 ( V_22 -> V_29 , V_41 ) ;
if ( V_723 ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_258 ) ;
F_380 ( V_22 -> V_29 ) ;
return V_723 ;
}
F_386 ( V_22 -> V_29 ) ;
V_723 = F_362 ( V_22 ) ;
if ( V_723 )
goto V_925;
V_723 = F_350 ( V_22 -> V_29 , & V_22 -> V_836 ) ;
if ( V_723 )
goto V_926;
V_22 -> V_153 = F_316 ( V_22 -> V_836 , 0x250 ) ;
if ( ! V_22 -> V_153 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
V_723 = - V_262 ;
goto V_926;
}
V_723 = F_355 ( V_22 -> V_29 , V_22 -> V_153 , V_846 ) ;
if ( V_723 )
goto V_927;
V_723 = F_366 ( V_22 ) ;
if ( V_723 )
goto V_927;
F_370 ( V_22 ) ;
if ( ! F_371 ( V_22 ) ) {
V_723 = - V_81 ;
goto V_928;
}
F_373 ( V_22 ) ;
F_375 ( V_22 ) ;
V_723 = F_378 ( V_22 ) ;
if ( V_723 )
goto V_928;
return 0 ;
V_928:
F_365 ( V_22 ) ;
V_927:
F_335 ( V_22 -> V_153 ) ;
V_22 -> V_153 = NULL ;
V_926:
F_360 ( V_22 ) ;
V_925:
F_380 ( V_22 -> V_29 ) ;
F_381 ( V_22 -> V_29 ) ;
return V_723 ;
}
static void F_387 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_388 64
V_22 -> V_61 = F_93 ( F_388 , V_204 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_176 ( V_22 , V_159 , 0 ,
V_22 -> V_61 , F_388 ) ;
if ( V_21 != 0 ) {
F_82 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_389 ( struct V_370 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_153 ;
if ( ! V_803 )
return 0 ;
V_21 = F_384 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_260 ) ;
return - V_81 ;
}
F_380 ( V_29 ) ;
F_109 ( 260 ) ;
V_21 = F_384 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_261 ) ;
return - V_81 ;
}
F_386 ( V_29 ) ;
V_153 = F_332 ( V_29 , 0 ) ;
if ( V_153 == NULL ) {
V_21 = - V_262 ;
goto V_929;
}
F_61 ( V_930 , V_153 + V_931 ) ;
F_335 ( V_153 ) ;
V_21 = F_347 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_929;
F_96 ( & V_29 -> V_30 , L_262 ) ;
for ( V_68 = 0 ; V_68 < V_932 ; V_68 ++ ) {
if ( F_390 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_263 ,
( V_68 < 11 ? L_264 : L_265 ) ) ;
}
V_929:
F_380 ( V_29 ) ;
return V_21 ;
}
static void F_391 ( struct V_1 * V_22 )
{
F_82 ( V_22 -> V_718 ) ;
V_22 -> V_718 = NULL ;
if ( V_22 -> V_239 ) {
F_338 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_8 ) ,
V_22 -> V_239 ,
V_22 -> V_640 ) ;
V_22 -> V_239 = NULL ;
V_22 -> V_640 = 0 ;
}
if ( V_22 -> V_641 ) {
F_338 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_338 ) ,
V_22 -> V_641 ,
V_22 -> V_642 ) ;
V_22 -> V_641 = NULL ;
V_22 -> V_642 = 0 ;
}
}
static int F_392 ( struct V_1 * V_22 )
{
V_22 -> V_718 = F_116 (
F_393 ( V_22 -> V_237 , V_621 ) *
sizeof( unsigned long ) , V_204 ) ;
V_22 -> V_239 = F_336 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_239 ) ,
& ( V_22 -> V_640 ) ) ;
V_22 -> V_641 = F_336 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_641 ) ,
& ( V_22 -> V_642 ) ) ;
if ( ( V_22 -> V_718 == NULL )
|| ( V_22 -> V_239 == NULL )
|| ( V_22 -> V_641 == NULL ) ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_266 , V_243 ) ;
goto V_933;
}
F_257 ( V_22 ) ;
return 0 ;
V_933:
F_391 ( V_22 ) ;
return - V_262 ;
}
static void F_394 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_127 || V_22 -> V_934 != V_935 ) {
F_395 ( F_270 ( V_22 -> V_29 , 0 ) , & V_22 -> V_111 [ V_22 -> V_934 ] ) ;
V_22 -> V_111 [ V_22 -> V_934 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
F_395 ( F_270 ( V_22 -> V_29 , V_68 ) , & V_22 -> V_111 [ V_68 ] ) ;
V_22 -> V_111 [ V_68 ] = 0 ;
}
for (; V_68 < V_874 ; V_68 ++ )
V_22 -> V_111 [ V_68 ] = 0 ;
}
static int F_396 ( struct V_1 * V_22 ,
T_17 (* F_397)( int , void * ) ,
T_17 (* F_398)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_874 ; V_68 ++ )
V_22 -> V_111 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_934 == V_935 && V_22 -> V_127 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_127 ; V_68 ++ ) {
sprintf ( V_22 -> V_936 [ V_68 ] , L_267 , V_22 -> V_31 , V_68 ) ;
V_21 = F_399 ( F_270 ( V_22 -> V_29 , V_68 ) , F_397 ,
0 , V_22 -> V_936 [ V_68 ] ,
& V_22 -> V_111 [ V_68 ] ) ;
if ( V_21 ) {
int V_194 ;
F_75 ( & V_22 -> V_29 -> V_30 ,
L_268 ,
F_270 ( V_22 -> V_29 , V_68 ) , V_22 -> V_31 ) ;
for ( V_194 = 0 ; V_194 < V_68 ; V_194 ++ ) {
F_395 ( F_270 ( V_22 -> V_29 , V_194 ) , & V_22 -> V_111 [ V_194 ] ) ;
V_22 -> V_111 [ V_194 ] = 0 ;
}
for (; V_194 < V_874 ; V_194 ++ )
V_22 -> V_111 [ V_194 ] = 0 ;
return V_21 ;
}
}
} else {
if ( V_22 -> V_127 > 0 || V_22 -> V_29 -> V_937 ) {
sprintf ( V_22 -> V_936 [ 0 ] , L_269 , V_22 -> V_31 ,
V_22 -> V_127 ? L_270 : L_265 ) ;
V_21 = F_399 ( F_270 ( V_22 -> V_29 , 0 ) ,
F_397 , 0 ,
V_22 -> V_936 [ 0 ] ,
& V_22 -> V_111 [ V_22 -> V_934 ] ) ;
} else {
sprintf ( V_22 -> V_936 [ V_22 -> V_934 ] ,
L_271 , V_22 -> V_31 ) ;
V_21 = F_399 ( F_270 ( V_22 -> V_29 , 0 ) ,
F_398 , V_938 ,
V_22 -> V_936 [ 0 ] ,
& V_22 -> V_111 [ V_22 -> V_934 ] ) ;
}
}
if ( V_21 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_268 ,
F_270 ( V_22 -> V_29 , 0 ) , V_22 -> V_31 ) ;
F_394 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_400 ( struct V_1 * V_22 )
{
int V_21 ;
F_314 ( V_22 , V_159 , V_939 ) ;
F_96 ( & V_22 -> V_29 -> V_30 , L_272 ) ;
V_21 = F_355 ( V_22 -> V_29 , V_22 -> V_153 , V_940 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_273 ) ;
return V_21 ;
}
F_96 ( & V_22 -> V_29 -> V_30 , L_274 ) ;
V_21 = F_355 ( V_22 -> V_29 , V_22 -> V_153 , V_846 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_275
L_276 ) ;
return V_21 ;
}
return 0 ;
}
static void F_401 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ ) {
if ( ! V_22 -> V_114 [ V_68 ] . V_118 )
continue;
F_338 ( V_22 -> V_29 ,
V_22 -> V_941 ,
V_22 -> V_114 [ V_68 ] . V_118 ,
V_22 -> V_114 [ V_68 ] . V_123 ) ;
V_22 -> V_114 [ V_68 ] . V_118 = NULL ;
V_22 -> V_114 [ V_68 ] . V_123 = 0 ;
}
V_22 -> V_941 = 0 ;
}
static void F_402 ( struct V_1 * V_22 )
{
F_403 ( V_22 ) ;
F_129 ( V_22 ) ;
F_391 ( V_22 ) ;
F_394 ( V_22 ) ;
F_404 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_379 ( V_22 ) ;
F_405 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_328 ) {
F_406 ( V_22 -> V_328 ) ;
V_22 -> V_328 = NULL ;
}
if ( V_22 -> V_942 ) {
F_406 ( V_22 -> V_942 ) ;
V_22 -> V_942 = NULL ;
}
F_82 ( V_22 ) ;
}
static void F_407 ( struct V_1 * V_22 )
{
int V_68 , V_240 ;
struct V_8 * V_9 ;
int V_943 = 0 ;
F_408 ( V_22 -> V_328 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_105 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 ) {
V_9 -> V_24 -> V_36 = V_344 ;
F_63 ( V_9 ) ;
F_47 ( & V_22 -> V_62 ) ;
V_943 ++ ;
}
F_107 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_277 , V_943 ) ;
}
static void F_409 ( struct V_1 * V_22 , T_4 V_944 )
{
int V_384 ;
F_410 (cpu) {
T_4 * F_13 ;
F_13 = F_171 ( V_22 -> F_13 , V_384 ) ;
* F_13 = V_944 ;
}
F_78 () ;
}
static void F_411 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_337 ( V_22 -> V_153 + V_892 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_278 ,
V_22 -> V_148 / V_947 ) ;
F_13 = 0xffffffff ;
}
F_409 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_279 ,
F_13 , V_22 -> V_148 / V_947 ) ;
F_380 ( V_22 -> V_29 ) ;
F_407 ( V_22 ) ;
}
static int F_278 ( struct V_1 * V_22 )
{
T_5 V_948 ;
T_4 V_949 ;
unsigned long V_78 ;
V_948 = F_327 () ;
if ( F_412 ( V_22 -> V_806 +
( V_22 -> V_148 ) , V_948 ) )
return false ;
if ( F_412 ( V_22 -> V_950 +
( V_22 -> V_148 ) , V_948 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_949 = F_337 ( & V_22 -> V_830 -> V_860 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_951 == V_949 ) {
F_411 ( V_22 ) ;
return true ;
}
V_22 -> V_951 = V_949 ;
V_22 -> V_950 = V_948 ;
return false ;
}
static void F_413 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_952 ;
if ( ! ( V_22 -> V_489 & V_953 ) )
return;
if ( ( V_22 -> V_63 & ( V_115
| V_954 ) ) &&
( V_22 -> V_955 & V_956 ||
V_22 -> V_955 & V_957 ) ) {
if ( V_22 -> V_955 & V_956 )
V_952 = L_280 ;
if ( V_22 -> V_955 & V_957 )
V_952 = L_281 ;
F_414 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
V_22 -> V_30 [ V_68 ] -> V_91 = 0 ;
V_22 -> V_30 [ V_68 ] -> V_184 = 0 ;
}
F_415 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_282 ,
V_22 -> V_955 , V_952 ) ;
F_61 ( V_22 -> V_955 , & ( V_22 -> V_830 -> V_958 ) ) ;
F_61 ( V_909 , V_22 -> V_153 + V_825 ) ;
F_376 ( V_22 ) ;
F_416 ( V_22 -> V_59 ) ;
} else {
F_61 ( V_22 -> V_955 , & ( V_22 -> V_830 -> V_958 ) ) ;
F_61 ( V_909 , V_22 -> V_153 + V_825 ) ;
F_376 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_417 ( struct V_1 * V_22 )
{
if ( V_22 -> V_250 ) {
V_22 -> V_250 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_489 & V_953 ) )
return 0 ;
V_22 -> V_955 = F_337 ( & ( V_22 -> V_830 -> V_959 ) ) ;
return V_22 -> V_955 & V_960 ;
}
static int F_418 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_202 * V_390 ;
struct V_961 * V_962 , * V_963 ;
F_35 ( & V_22 -> V_203 , V_78 ) ;
F_419 (this, tmp, &h->offline_device_list) {
V_390 = F_420 ( V_962 , struct V_202 ,
V_205 ) ;
F_36 ( & V_22 -> V_203 , V_78 ) ;
if ( ! F_211 ( V_22 , V_390 -> V_72 ) ) {
F_35 ( & V_22 -> V_203 , V_78 ) ;
F_421 ( & V_390 -> V_205 ) ;
F_36 ( & V_22 -> V_203 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_203 , V_78 ) ;
}
F_36 ( & V_22 -> V_203 , V_78 ) ;
return 0 ;
}
static int F_422 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_465 * V_502 = NULL ;
if ( ! V_22 -> V_964 )
return V_21 ;
V_502 = F_116 ( sizeof( * V_502 ) , V_204 ) ;
if ( ! V_502 )
return V_21 ;
if ( F_206 ( V_22 , 1 , V_502 , sizeof( * V_502 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_283 ) ;
goto V_395;
}
if ( memcmp ( V_502 , V_22 -> V_964 , sizeof( * V_502 ) ) ) {
F_96 ( & V_22 -> V_29 -> V_30 ,
L_284 ) ;
memcpy ( V_22 -> V_964 , V_502 , sizeof( * V_502 ) ) ;
goto V_395;
} else
V_21 = 0 ;
V_395:
F_82 ( V_502 ) ;
return V_21 ;
}
static void F_423 ( struct V_644 * V_326 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_260 ( F_424 ( V_326 ) ,
struct V_1 , V_965 ) ;
if ( V_22 -> V_913 )
return;
if ( V_22 -> V_249 ) {
V_22 -> V_250 = 1 ;
return;
}
if ( F_417 ( V_22 ) || F_418 ( V_22 ) ) {
F_425 ( V_22 -> V_59 ) ;
F_413 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_404 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_537 ) {
F_426 ( V_22 ) ;
if ( F_422 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_96 ( & V_22 -> V_29 -> V_30 ,
L_285 ) ;
V_7 = F_425 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_404 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_913 )
F_427 ( V_22 -> V_942 , & V_22 -> V_965 ,
V_22 -> V_148 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_428 ( struct V_644 * V_326 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_260 ( F_424 ( V_326 ) ,
struct V_1 , V_966 ) ;
F_278 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_913 )
F_429 ( & V_22 -> V_966 ,
V_22 -> V_148 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_967 * F_430 ( struct V_1 * V_22 ,
char * V_968 )
{
struct V_967 * V_969 = NULL ;
V_969 = F_431 ( L_286 , 0 , V_968 , V_22 -> V_110 ) ;
if ( ! V_969 )
F_75 ( & V_22 -> V_29 -> V_30 , L_287 , V_968 ) ;
return V_969 ;
}
static int F_432 ( struct V_370 * V_29 , const struct V_970 * V_971 )
{
int V_972 , V_21 ;
struct V_1 * V_22 ;
int V_973 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_974 == 0 )
F_433 (KERN_INFO DRIVER_NAME L_288 ) ;
V_21 = F_364 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_289 ) ;
return V_21 ;
}
V_21 = F_389 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_839 )
return V_21 ;
V_973 = 1 ;
V_21 = 0 ;
}
V_975:
F_284 ( sizeof( struct V_8 ) % V_976 ) ;
V_22 = F_116 ( sizeof( * V_22 ) , V_204 ) ;
if ( ! V_22 ) {
F_75 ( & V_29 -> V_30 , L_290 ) ;
return - V_262 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_934 = V_977 ? V_978 : V_935 ;
F_434 ( & V_22 -> V_206 ) ;
F_435 ( & V_22 -> V_79 ) ;
F_435 ( & V_22 -> V_203 ) ;
F_435 ( & V_22 -> V_648 ) ;
F_123 ( & V_22 -> V_777 , V_979 ) ;
F_123 ( & V_22 -> V_708 , V_980 ) ;
V_22 -> F_13 = F_436 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_75 ( & V_22 -> V_29 -> V_30 , L_291 ) ;
V_21 = - V_262 ;
goto V_925;
}
F_409 ( V_22 , 0 ) ;
V_21 = F_382 ( V_22 ) ;
if ( V_21 )
goto V_926;
V_21 = F_268 ( V_22 ) ;
if ( V_21 )
goto V_981;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_102 ) ;
V_22 -> V_110 = V_974 ;
V_974 ++ ;
V_21 = F_437 ( V_29 , F_334 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_972 = 1 ;
} else {
V_21 = F_437 ( V_29 , F_334 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_972 = 0 ;
} else {
F_75 ( & V_29 -> V_30 , L_292 ) ;
goto V_927;
}
}
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
V_21 = F_396 ( V_22 , F_330 , F_329 ) ;
if ( V_21 )
goto V_927;
V_21 = F_392 ( V_22 ) ;
if ( V_21 )
goto V_928;
V_21 = F_130 ( V_22 ) ;
if ( V_21 )
goto V_982;
F_438 ( & V_22 -> V_650 ) ;
F_438 ( & V_22 -> V_707 ) ;
F_438 ( & V_22 -> V_324 ) ;
F_439 ( & V_22 -> V_404 ) ;
V_22 -> V_649 = 1 ;
V_22 -> V_651 = 0 ;
F_440 ( V_29 , V_22 ) ;
V_22 -> V_163 = 0 ;
F_435 ( & V_22 -> V_98 ) ;
V_21 = F_441 ( V_22 ) ;
if ( V_21 )
goto V_983;
V_22 -> V_942 = F_430 ( V_22 , L_293 ) ;
if ( ! V_22 -> V_942 ) {
V_21 = - V_262 ;
goto V_984;
}
V_22 -> V_328 = F_430 ( V_22 , L_294 ) ;
if ( ! V_22 -> V_328 ) {
V_21 = - V_262 ;
goto V_984;
}
if ( V_973 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_394 ( V_22 ) ;
V_21 = F_396 ( V_22 , F_328 ,
F_326 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_295 ) ;
F_403 ( V_22 ) ;
F_129 ( V_22 ) ;
F_391 ( V_22 ) ;
goto V_927;
}
V_21 = F_400 ( V_22 ) ;
if ( V_21 )
goto V_984;
F_96 ( & V_22 -> V_29 -> V_30 , L_296 ) ;
F_96 ( & V_22 -> V_29 -> V_30 ,
L_297 ) ;
V_22 -> V_116 . V_945 ( V_22 , V_985 ) ;
F_109 ( 10000 ) ;
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
V_21 = F_346 ( V_22 -> V_830 ) ;
if ( V_21 )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_298 ) ;
F_402 ( V_22 ) ;
V_973 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_975;
}
V_22 -> V_56 = 1 ;
V_22 -> V_537 = 0 ;
V_22 -> V_116 . V_945 ( V_22 , V_985 ) ;
F_387 ( V_22 ) ;
V_22 -> V_964 = F_116 ( sizeof( * ( V_22 -> V_964 ) ) , V_204 ) ;
if ( ! V_22 -> V_964 )
F_96 ( & V_22 -> V_29 -> V_30 ,
L_299 ) ;
V_21 = F_271 ( V_22 ) ;
if ( V_21 )
goto V_984;
V_22 -> V_148 = V_150 ;
F_442 ( & V_22 -> V_966 , F_428 ) ;
F_429 ( & V_22 -> V_966 ,
V_22 -> V_148 ) ;
F_442 ( & V_22 -> V_965 , F_423 ) ;
F_427 ( V_22 -> V_942 , & V_22 -> V_965 ,
V_22 -> V_148 ) ;
return 0 ;
V_984:
F_403 ( V_22 ) ;
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
V_983:
F_129 ( V_22 ) ;
V_982:
F_391 ( V_22 ) ;
V_928:
F_394 ( V_22 ) ;
V_927:
F_404 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_981:
F_379 ( V_22 ) ;
V_926:
if ( V_22 -> F_13 ) {
F_405 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_925:
if ( V_22 -> V_328 ) {
F_406 ( V_22 -> V_328 ) ;
V_22 -> V_328 = NULL ;
}
if ( V_22 -> V_942 ) {
F_406 ( V_22 -> V_942 ) ;
V_22 -> V_942 = NULL ;
}
F_82 ( V_22 ) ;
return V_21 ;
}
static void F_443 ( struct V_1 * V_22 )
{
char * V_986 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_46 ( F_13 ( V_22 ) ) )
return;
V_986 = F_116 ( 4 , V_204 ) ;
if ( ! V_986 )
return;
V_9 = F_177 ( V_22 ) ;
if ( F_178 ( V_9 , V_785 , V_22 , V_986 , 4 , 0 ,
V_159 , V_394 ) ) {
goto V_395;
}
V_21 = F_173 ( V_22 , V_9 ,
V_272 , V_397 ) ;
if ( V_21 )
goto V_395;
if ( V_9 -> V_24 -> V_36 != 0 )
V_395:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_300 ) ;
F_107 ( V_22 , V_9 ) ;
F_82 ( V_986 ) ;
}
static void F_426 ( struct V_1 * V_22 )
{
T_4 * V_987 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_46 ( V_22 -> F_13 ) )
return;
V_987 = F_116 ( sizeof( * V_987 ) , V_204 ) ;
if ( ! V_987 )
return;
V_9 = F_177 ( V_22 ) ;
if ( F_178 ( V_9 , V_782 , V_22 , V_987 , 4 , 0 ,
V_159 , V_394 ) )
goto V_988;
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
* V_987 |= V_989 ;
if ( F_178 ( V_9 , V_784 , V_22 , V_987 , 4 , 0 ,
V_159 , V_394 ) )
goto V_988;
V_21 = F_173 ( V_22 , V_9 ,
V_272 , V_397 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
if ( F_178 ( V_9 , V_782 , V_22 , V_987 , 4 , 0 ,
V_159 , V_394 ) )
goto V_988;
V_21 = F_173 ( V_22 , V_9 ,
V_396 , V_397 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
if ( * V_987 & V_989 )
goto V_395;
V_988:
F_75 ( & V_22 -> V_29 -> V_30 ,
L_301 ) ;
V_395:
F_107 ( V_22 , V_9 ) ;
F_82 ( V_987 ) ;
}
static void F_444 ( struct V_370 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_445 ( V_29 ) ;
F_443 ( V_22 ) ;
V_22 -> V_116 . V_945 ( V_22 , V_946 ) ;
F_394 ( V_22 ) ;
F_360 ( V_22 ) ;
}
static void F_446 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
F_82 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_447 ( struct V_370 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_445 ( V_29 ) == NULL ) {
F_75 ( & V_29 -> V_30 , L_302 ) ;
return;
}
V_22 = F_445 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_913 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_448 ( & V_22 -> V_966 ) ;
F_448 ( & V_22 -> V_965 ) ;
F_406 ( V_22 -> V_942 ) ;
F_406 ( V_22 -> V_328 ) ;
if ( V_22 -> V_59 )
F_449 ( V_22 -> V_59 ) ;
F_444 ( V_29 ) ;
F_446 ( V_22 ) ;
F_82 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_127 ( V_22 ) ;
F_403 ( V_22 ) ;
F_129 ( V_22 ) ;
F_391 ( V_22 ) ;
F_82 ( V_22 -> V_964 ) ;
F_404 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_379 ( V_22 ) ;
F_405 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_450 ( V_22 ) ;
F_82 ( V_22 ) ;
}
static void F_451 ( int V_990 [] , int V_991 ,
int V_992 , int V_993 , T_4 * V_994 )
{
int V_68 , V_194 , V_995 , V_473 ;
for ( V_68 = 0 ; V_68 <= V_992 ; V_68 ++ ) {
V_473 = V_68 + V_993 ;
V_995 = V_991 ;
for ( V_194 = 0 ; V_194 < V_991 ; V_194 ++ ) {
if ( V_990 [ V_194 ] >= V_473 ) {
V_995 = V_194 ;
break;
}
}
V_994 [ V_68 ] = V_995 ;
}
}
static int F_452 ( struct V_1 * V_22 , T_4 V_916 )
{
int V_68 ;
unsigned long V_996 ;
unsigned long V_63 = V_64 |
( V_916 & V_997 ) |
V_998 |
( V_916 & ( V_115 |
V_954 ) ) ;
struct V_999 V_116 = V_1000 ;
int V_1001 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_774 + 4 } ;
#define F_453 5
#define F_454 4
int V_1002 [ 16 ] = { F_453 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_454 + V_1003 } ;
F_284 ( F_26 ( V_1002 ) != 16 ) ;
F_284 ( F_26 ( V_1001 ) != 8 ) ;
F_284 ( F_250 ( struct V_140 , V_270 ) >
16 * F_453 ) ;
F_284 ( sizeof( struct V_266 ) != 16 ) ;
F_284 ( 28 > V_774 + 4 ) ;
if ( V_916 & ( V_115 | V_954 ) )
V_116 = V_1004 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ )
memset ( V_22 -> V_114 [ V_68 ] . V_118 , 0 , V_22 -> V_941 ) ;
V_1001 [ 7 ] = V_774 + 4 ;
F_451 ( V_1001 , F_26 ( V_1001 ) ,
V_774 , 4 , V_22 -> V_124 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_61 ( V_1001 [ V_68 ] , & V_22 -> V_897 -> V_1005 [ V_68 ] ) ;
F_61 ( V_22 -> V_122 , & V_22 -> V_897 -> V_1006 ) ;
F_61 ( V_22 -> V_130 , & V_22 -> V_897 -> V_1007 ) ;
F_61 ( 0 , & V_22 -> V_897 -> V_1008 ) ;
F_61 ( 0 , & V_22 -> V_897 -> V_1009 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ ) {
F_61 ( 0 , & V_22 -> V_897 -> V_1010 [ V_68 ] . V_1011 ) ;
F_61 ( V_22 -> V_114 [ V_68 ] . V_123 ,
& V_22 -> V_897 -> V_1010 [ V_68 ] . V_1012 ) ;
}
F_61 ( 0 , & V_22 -> V_830 -> V_853 . V_919 ) ;
F_61 ( V_63 , & ( V_22 -> V_830 -> V_853 . V_854 ) ) ;
if ( V_916 & V_115 ) {
V_116 = V_1013 ;
F_61 ( 10 , & V_22 -> V_830 -> V_853 . V_855 ) ;
F_61 ( 4 , & V_22 -> V_830 -> V_853 . V_856 ) ;
} else
if ( V_916 & V_954 )
V_116 = V_1014 ;
F_61 ( V_914 , V_22 -> V_153 + V_825 ) ;
if ( F_377 ( V_22 ) ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_303 ) ;
return - V_81 ;
}
V_996 = F_337 ( & ( V_22 -> V_830 -> V_852 ) ) ;
if ( ! ( V_996 & V_64 ) ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_304 ) ;
return - V_81 ;
}
V_22 -> V_116 = V_116 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_916 & V_115 ) ||
( V_916 & V_954 ) ) )
return 0 ;
if ( V_916 & V_115 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ ) {
F_61 ( V_68 , V_22 -> V_153 + V_1015 ) ;
V_22 -> V_114 [ V_68 ] . V_119 =
F_337 ( V_22 -> V_153 + V_1016 ) ;
}
V_1001 [ 7 ] = V_22 -> V_561 + 8 ;
F_451 ( V_1001 , F_26 ( V_1001 ) , V_22 -> V_561 , 8 ,
V_22 -> V_135 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ )
memset ( V_22 -> V_114 [ V_68 ] . V_118 ,
( T_1 ) V_1017 ,
V_22 -> V_941 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_131 * V_132 = & V_22 -> V_133 [ V_68 ] ;
V_132 -> V_1018 = V_1019 ;
V_132 -> V_24 = ( T_4 ) ( V_22 -> V_642 +
( V_68 * sizeof( struct V_338 ) ) ) ;
V_132 -> V_1020 = sizeof( struct V_338 ) ;
V_132 -> V_1021 = V_1022 ;
V_132 -> V_1023 =
F_161 ( V_1024 ) ;
V_132 -> V_1025 = 0 ;
V_132 -> V_129 = 0 ;
V_132 -> V_349 =
F_135 ( ( V_68 << V_592 ) ) ;
V_132 -> V_1026 =
F_135 ( V_22 -> V_564 +
( V_68 * sizeof( struct V_131 ) ) ) ;
}
} else if ( V_916 & V_954 ) {
T_5 V_833 , V_835 ;
T_4 V_1027 , V_834 ;
int V_21 ;
V_21 = F_351 ( V_22 -> V_29 , V_22 -> V_153 , & V_834 ,
& V_835 , & V_833 ) ;
F_284 ( F_250 ( struct V_140 , V_270 ) != 64 ) ;
V_1002 [ 15 ] = V_22 -> V_561 + F_454 ;
F_451 ( V_1002 , F_26 ( V_1002 ) , V_22 -> V_561 ,
4 , V_22 -> V_139 ) ;
V_1027 = F_337 ( & V_22 -> V_830 -> V_1028 ) ;
F_284 ( F_250 ( struct V_829 ,
V_1028 ) != 0xb8 ) ;
V_22 -> V_1029 =
F_316 ( F_352 ( V_22 -> V_29 ,
V_835 ) +
V_833 + V_1027 ,
F_26 ( V_1002 ) *
sizeof( * V_22 -> V_1029 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_1002 ) ; V_68 ++ )
F_61 ( V_1002 [ V_68 ] , & V_22 -> V_1029 [ V_68 ] ) ;
}
F_61 ( V_914 , V_22 -> V_153 + V_825 ) ;
if ( F_377 ( V_22 ) ) {
F_75 ( & V_22 -> V_29 -> V_30 ,
L_305 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_455 ( struct V_1 * V_22 )
{
if ( V_22 -> V_133 ) {
F_338 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_133 ) ,
V_22 -> V_133 ,
V_22 -> V_564 ) ;
V_22 -> V_133 = NULL ;
V_22 -> V_564 = 0 ;
}
F_82 ( V_22 -> V_135 ) ;
V_22 -> V_135 = NULL ;
}
static int F_456 ( struct V_1 * V_22 )
{
V_22 -> V_561 =
F_337 ( & ( V_22 -> V_830 -> V_1030 ) ) ;
if ( V_22 -> V_561 > V_1031 )
V_22 -> V_561 = V_1031 ;
F_284 ( sizeof( struct V_131 ) %
V_1032 ) ;
V_22 -> V_133 =
F_336 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_133 ) ,
& ( V_22 -> V_564 ) ) ;
V_22 -> V_135 =
F_93 ( ( ( V_22 -> V_561 + 1 ) *
sizeof( T_4 ) ) , V_204 ) ;
if ( ( V_22 -> V_133 == NULL ) ||
( V_22 -> V_135 == NULL ) )
goto V_933;
memset ( V_22 -> V_133 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_133 ) ) ;
return 0 ;
V_933:
F_455 ( V_22 ) ;
return - V_262 ;
}
static void F_457 ( struct V_1 * V_22 )
{
F_127 ( V_22 ) ;
if ( V_22 -> V_138 ) {
F_338 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_138 ) ,
V_22 -> V_138 ,
V_22 -> V_583 ) ;
V_22 -> V_138 = NULL ;
V_22 -> V_583 = 0 ;
}
F_82 ( V_22 -> V_139 ) ;
V_22 -> V_139 = NULL ;
}
static int F_458 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_561 =
F_337 ( & ( V_22 -> V_830 -> V_1030 ) ) ;
if ( V_22 -> V_561 > V_1003 )
V_22 -> V_561 = V_1003 ;
F_284 ( sizeof( struct V_140 ) %
V_1033 ) ;
V_22 -> V_138 =
F_336 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_138 ) ,
& ( V_22 -> V_583 ) ) ;
V_22 -> V_139 =
F_93 ( ( ( V_22 -> V_561 + 1 ) *
sizeof( T_4 ) ) , V_204 ) ;
if ( ( V_22 -> V_138 == NULL ) ||
( V_22 -> V_139 == NULL ) ) {
V_21 = - V_262 ;
goto V_933;
}
V_21 = F_128 ( V_22 ) ;
if ( V_21 )
goto V_933;
memset ( V_22 -> V_138 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_138 ) ) ;
return 0 ;
V_933:
F_457 ( V_22 ) ;
return V_21 ;
}
static void F_403 ( struct V_1 * V_22 )
{
F_82 ( V_22 -> V_124 ) ;
V_22 -> V_124 = NULL ;
F_401 ( V_22 ) ;
F_455 ( V_22 ) ;
F_457 ( V_22 ) ;
}
static int F_441 ( struct V_1 * V_22 )
{
T_4 V_916 ;
unsigned long V_63 = V_64 |
V_997 ;
int V_68 , V_21 ;
if ( V_977 )
return 0 ;
V_916 = F_337 ( & ( V_22 -> V_830 -> V_851 ) ) ;
if ( ! ( V_916 & V_1034 ) )
return 0 ;
if ( V_916 & V_115 ) {
V_63 |= V_115 |
V_998 ;
V_21 = F_456 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_916 & V_954 ) {
V_63 |= V_954 |
V_998 ;
V_21 = F_458 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_130 = V_22 -> V_127 > 0 ? V_22 -> V_127 : 1 ;
F_367 ( V_22 ) ;
V_22 -> V_941 = V_22 -> V_122 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_130 ; V_68 ++ ) {
V_22 -> V_114 [ V_68 ] . V_118 = F_336 ( V_22 -> V_29 ,
V_22 -> V_941 ,
& ( V_22 -> V_114 [ V_68 ] . V_123 ) ) ;
if ( ! V_22 -> V_114 [ V_68 ] . V_118 ) {
V_21 = - V_262 ;
goto V_925;
}
V_22 -> V_114 [ V_68 ] . V_473 = V_22 -> V_122 ;
V_22 -> V_114 [ V_68 ] . V_120 = 1 ;
V_22 -> V_114 [ V_68 ] . V_119 = 0 ;
}
V_22 -> V_124 = F_93 ( ( ( V_774 + 1 ) *
sizeof( T_4 ) ) , V_204 ) ;
if ( ! V_22 -> V_124 ) {
V_21 = - V_262 ;
goto V_925;
}
V_21 = F_452 ( V_22 , V_916 ) ;
if ( V_21 )
goto V_926;
return 0 ;
V_926:
F_82 ( V_22 -> V_124 ) ;
V_22 -> V_124 = NULL ;
V_925:
F_401 ( V_22 ) ;
F_455 ( V_22 ) ;
F_457 ( V_22 ) ;
return V_21 ;
}
static int F_459 ( struct V_8 * V_9 )
{
return V_9 -> V_151 == V_152 || V_9 -> V_151 == V_155 ;
}
static void F_415 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1035 ;
int V_240 ;
do {
V_1035 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_105 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 )
V_1035 += F_459 ( V_9 ) ;
F_107 ( V_22 , V_9 ) ;
}
if ( V_1035 <= 0 )
break;
F_109 ( 100 ) ;
} while ( 1 );
}
static struct V_1036 * F_460 (
struct V_1037 * V_1037 )
{
struct V_1036 * V_1036 ;
struct V_1038 * V_1039 ;
V_1036 = F_116 ( sizeof( * V_1036 ) , V_204 ) ;
if ( ! V_1036 )
return NULL ;
V_1039 = F_461 ( V_1037 -> V_1040 -> V_1041 ,
V_1037 -> V_1042 ) ;
if ( ! V_1039 ) {
F_82 ( V_1036 ) ;
return NULL ;
}
V_1037 -> V_1042 ++ ;
V_1036 -> V_1039 = V_1039 ;
V_1036 -> V_1043 = V_1037 ;
return V_1036 ;
}
static void F_462 ( struct V_1036 * V_1036 )
{
struct V_1038 * V_1039 = V_1036 -> V_1039 ;
F_463 ( V_1036 -> V_1043 -> V_1044 , V_1039 ) ;
F_464 ( V_1039 ) ;
if ( V_1036 -> V_1045 )
F_421 ( & V_1036 -> V_1046 ) ;
F_82 ( V_1036 ) ;
}
static int F_465 ( struct V_1036 * V_1036 )
{
int V_21 ;
struct V_1037 * V_1037 ;
struct V_1038 * V_1039 ;
struct V_1047 * V_1048 ;
V_1037 = V_1036 -> V_1043 ;
V_1039 = V_1036 -> V_1039 ;
V_1048 = & V_1039 -> V_1048 ;
memset ( V_1048 , 0 , sizeof( * V_1048 ) ) ;
V_1048 -> V_89 = V_1037 -> V_89 ;
V_1048 -> V_521 = V_1049 ;
V_1048 -> V_1050 = V_1051 ;
V_1048 -> V_1052 = V_1051 ;
V_1039 -> V_1053 = V_1054 ;
V_1039 -> V_1055 = V_1054 ;
V_1039 -> V_1056 = V_1054 ;
V_1039 -> V_1057 = V_1054 ;
V_1039 -> V_1058 = V_1054 ;
V_21 = F_466 ( V_1036 -> V_1039 ) ;
if ( V_21 )
return V_21 ;
F_467 ( V_1037 -> V_1044 , V_1036 -> V_1039 ) ;
F_94 ( & V_1036 -> V_1046 ,
& V_1037 -> V_1059 ) ;
V_1036 -> V_1045 = true ;
return 0 ;
}
static int
F_468 ( struct V_1037 * V_1037 ,
struct V_255 * V_256 )
{
struct V_1047 * V_1048 ;
V_1048 = & V_256 -> V_1048 ;
V_1048 -> V_89 = V_1037 -> V_89 ;
V_1048 -> V_1050 = V_1051 ;
V_1048 -> V_1052 = V_1051 ;
return F_469 ( V_256 ) ;
}
static struct V_1037
* F_470 ( struct V_1060 * V_1060 ,
T_5 V_89 )
{
int V_21 ;
struct V_1037 * V_1037 ;
struct V_1061 * V_1044 ;
V_1037 = F_116 ( sizeof( * V_1037 ) , V_204 ) ;
if ( ! V_1037 )
return NULL ;
F_434 ( & V_1037 -> V_1059 ) ;
V_1037 -> V_1040 = V_1060 ;
V_1044 = F_471 ( V_1060 -> V_1041 ) ;
if ( ! V_1044 )
goto V_1062;
V_21 = F_472 ( V_1044 ) ;
if ( V_21 )
goto V_1063;
V_1037 -> V_1044 = V_1044 ;
V_1037 -> V_89 = V_89 ;
F_94 ( & V_1037 -> V_1064 ,
& V_1060 -> V_1065 ) ;
return V_1037 ;
V_1063:
F_473 ( V_1044 ) ;
V_1062:
F_82 ( V_1037 ) ;
return NULL ;
}
static void F_474 ( struct V_1037 * V_1037 )
{
struct V_1036 * V_1036 ;
struct V_1036 * V_1066 ;
F_475 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_462 ( V_1036 ) ;
F_476 ( V_1037 -> V_1044 ) ;
F_421 ( & V_1037 -> V_1064 ) ;
F_82 ( V_1037 ) ;
}
static struct V_1060 * F_477 ( struct V_42 * V_1041 )
{
struct V_1060 * V_1060 ;
V_1060 = F_116 ( sizeof( * V_1060 ) , V_204 ) ;
if ( V_1060 ) {
V_1060 -> V_1041 = V_1041 ;
F_434 ( & V_1060 -> V_1065 ) ;
}
return V_1060 ;
}
static void F_478 ( struct V_1060 * V_1060 )
{
struct V_1037 * V_1037 ;
struct V_1037 * V_1066 ;
if ( ! V_1060 )
return;
F_475 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_474 ( V_1037 ) ;
F_82 ( V_1060 ) ;
}
static struct V_73
* F_121 ( struct V_1 * V_22 ,
struct V_255 * V_256 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_163 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1061 )
continue;
if ( V_42 -> V_1061 -> V_256 == V_256 )
return V_42 ;
}
return NULL ;
}
static int F_236 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1041 ;
struct V_1060 * V_1060 ;
struct V_1037 * V_1037 ;
struct V_1036 * V_1036 ;
V_1041 = & V_22 -> V_59 -> V_1067 ;
V_1060 = F_477 ( V_1041 ) ;
if ( ! V_1060 )
return - V_262 ;
V_1037 = F_470 ( V_1060 , V_22 -> V_89 ) ;
if ( ! V_1037 ) {
V_21 = - V_81 ;
goto V_1068;
}
V_1036 = F_460 ( V_1037 ) ;
if ( ! V_1036 ) {
V_21 = - V_81 ;
goto V_1063;
}
V_21 = F_465 ( V_1036 ) ;
if ( V_21 )
goto V_1069;
V_22 -> V_238 = V_1060 ;
return 0 ;
V_1069:
F_462 ( V_1036 ) ;
V_1063:
F_474 ( V_1037 ) ;
V_1068:
F_478 ( V_1060 ) ;
return V_21 ;
}
static void F_450 ( struct V_1 * V_22 )
{
F_478 ( V_22 -> V_238 ) ;
}
static int F_103 ( struct V_1060 * V_1060 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1037 * V_1037 ;
struct V_255 * V_256 ;
V_1037 = F_470 ( V_1060 , V_42 -> V_89 ) ;
if ( ! V_1037 )
return - V_262 ;
V_256 = F_479 ( V_1037 -> V_1044 ) ;
if ( ! V_256 ) {
V_21 = - V_81 ;
goto V_1063;
}
V_1037 -> V_256 = V_256 ;
V_42 -> V_1061 = V_1037 ;
V_21 = F_468 ( V_1037 , V_256 ) ;
if ( V_21 )
goto V_1063;
return 0 ;
V_1063:
F_474 ( V_1037 ) ;
V_42 -> V_1061 = NULL ;
return V_21 ;
}
static void F_114 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1061 ) {
F_474 ( V_42 -> V_1061 ) ;
V_42 -> V_1061 = NULL ;
}
}
static int
F_480 ( struct V_1038 * V_1039 )
{
return 0 ;
}
static int
F_481 ( struct V_255 * V_256 , T_5 * V_1070 )
{
* V_1070 = 0 ;
return 0 ;
}
static int
F_482 ( struct V_255 * V_256 )
{
return - V_1071 ;
}
static int
F_483 ( struct V_1038 * V_1039 , int V_1072 )
{
return 0 ;
}
static int
F_484 ( struct V_1038 * V_1039 , int V_1073 )
{
return 0 ;
}
static int
F_485 ( struct V_1038 * V_1039 )
{
return 0 ;
}
static void
F_486 ( struct V_1038 * V_1039 )
{
}
static int
F_487 ( struct V_1038 * V_1039 , struct V_1074 * V_1075 )
{
return - V_55 ;
}
static int
F_488 ( struct V_6 * V_47 , struct V_255 * V_256 ,
struct V_646 * V_1076 )
{
return - V_55 ;
}
static int T_18 F_489 ( void )
{
int V_21 ;
V_667 =
F_490 ( & V_1077 ) ;
if ( ! V_667 )
return - V_81 ;
V_21 = F_491 ( & V_1078 ) ;
if ( V_21 )
F_492 ( V_667 ) ;
return V_21 ;
}
static void T_19 F_493 ( void )
{
F_494 ( & V_1078 ) ;
F_492 ( V_667 ) ;
}
