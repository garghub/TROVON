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
static inline T_4 F_44 ( struct V_1 * V_22 , T_1 V_110 )
{
T_4 V_65 ;
struct V_111 * V_112 = & V_22 -> V_113 [ V_110 ] ;
if ( V_22 -> V_63 & V_114 )
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
if ( F_45 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
if ( ( V_112 -> V_117 [ V_112 -> V_118 ] & 1 ) == V_112 -> V_119 ) {
V_65 = V_112 -> V_117 [ V_112 -> V_118 ] ;
V_112 -> V_118 ++ ;
F_46 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_120 ;
}
if ( V_112 -> V_118 == V_22 -> V_121 ) {
V_112 -> V_118 = 0 ;
V_112 -> V_119 ^= 1 ;
}
return V_65 ;
}
static void F_47 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_113 )
{
if ( F_48 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_122 |= 1 | ( V_22 -> V_123 [ V_9 -> V_124 . V_125 ] << 1 ) ;
if ( F_45 ( ! V_22 -> V_126 ) )
return;
if ( F_48 ( V_113 == V_127 ) )
V_9 -> V_124 . V_128 =
F_49 () % V_22 -> V_129 ;
else
V_9 -> V_124 . V_128 = V_113 % V_22 -> V_129 ;
}
}
static void F_50 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
if ( F_48 ( V_113 == V_127 ) )
V_131 -> V_128 = F_51 () % V_22 -> V_129 ;
else
V_131 -> V_128 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= 1 | ( V_22 -> V_134 [ V_9 -> V_124 . V_125 ] << 1 ) |
V_135 ;
}
static void F_52 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_136 * V_131 = (struct V_136 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_48 ( V_113 == V_127 ) )
V_131 -> V_113 = F_51 () % V_22 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= V_22 -> V_138 [ 0 ] ;
}
static void F_53 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_48 ( V_113 == V_127 ) )
V_131 -> V_113 = F_51 () % V_22 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_22 -> V_129 ;
V_9 -> V_122 |= ( V_22 -> V_138 [ V_131 -> V_140 ] ) ;
}
static int F_54 ( T_1 * V_141 )
{
return V_141 [ 0 ] == V_142 && V_141 [ 6 ] == V_143 ;
}
static void F_55 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_54 ( V_9 -> V_144 . V_145 ) )
return;
F_56 ( & V_22 -> V_146 ) ;
V_22 -> V_147 = V_148 ;
}
static void F_57 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_54 ( V_9 -> V_144 . V_145 ) &&
F_58 ( & V_22 -> V_146 ) )
V_22 -> V_147 = V_149 ;
}
static void F_59 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_113 )
{
F_55 ( V_22 , V_9 ) ;
F_56 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_150 ) {
case V_151 :
F_50 ( V_22 , V_9 , V_113 ) ;
F_60 ( V_9 -> V_122 , V_22 -> V_152 + V_153 ) ;
break;
case V_154 :
F_53 ( V_22 , V_9 , V_113 ) ;
F_60 ( V_9 -> V_122 , V_22 -> V_152 + V_155 ) ;
break;
case V_156 :
F_52 ( V_22 , V_9 , V_113 ) ;
F_60 ( V_9 -> V_122 , V_22 -> V_152 + V_155 ) ;
break;
default:
F_47 ( V_22 , V_9 , V_113 ) ;
V_22 -> V_115 . V_157 ( V_22 , V_9 ) ;
}
}
static void F_61 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_45 ( F_5 ( V_9 ) ) )
return F_62 ( V_9 ) ;
F_59 ( V_22 , V_9 , V_127 ) ;
}
static inline int F_63 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_158 , 8 ) == 0 ;
}
static inline int F_64 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_61 )
return 0 ;
if ( ( V_22 -> V_61 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_22 ,
unsigned char V_72 [] , int V_103 , int * V_104 , int * V_105 )
{
int V_68 , V_159 = 0 ;
F_66 ( V_160 , V_161 ) ;
F_67 ( V_160 , V_161 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_103 == V_103 && V_22 -> V_30 [ V_68 ] -> V_104 != - 1 )
F_68 ( V_22 -> V_30 [ V_68 ] -> V_104 , V_160 ) ;
}
V_68 = F_69 ( V_160 , V_161 ) ;
if ( V_68 < V_161 ) {
* V_104 = V_68 ;
* V_105 = 0 ;
V_159 = 1 ;
}
return ! V_159 ;
}
static void F_70 ( const char * V_163 , struct V_1 * V_22 ,
struct V_73 * V_30 , char * V_164 )
{
#define F_71 25
char V_165 [ F_71 ] ;
if ( V_22 == NULL || V_22 -> V_29 == NULL || V_22 -> V_59 == NULL )
return;
switch ( V_30 -> V_106 ) {
case V_107 :
snprintf ( V_165 , F_71 , L_33 ) ;
break;
case V_166 :
snprintf ( V_165 , F_71 , L_34 ) ;
break;
case V_108 :
case V_109 :
if ( V_30 -> V_167 )
snprintf ( V_165 , F_71 , L_35 ) ;
else if ( ! F_31 ( V_30 -> V_72 ) )
snprintf ( V_165 , F_71 , L_36 ,
V_85 [ V_168 ] ) ;
else
snprintf ( V_165 , F_71 , L_37 ,
V_30 -> V_83 > V_84 ? L_38 :
V_85 [ V_30 -> V_83 ] ) ;
break;
case V_169 :
snprintf ( V_165 , F_71 , L_39 ) ;
break;
case V_170 :
snprintf ( V_165 , F_71 , L_40 ) ;
break;
case V_171 :
snprintf ( V_165 , F_71 , L_41 ) ;
break;
default:
snprintf ( V_165 , F_71 , L_42 ) ;
break;
}
F_72 ( V_163 , & V_22 -> V_29 -> V_30 ,
L_43 ,
V_22 -> V_59 -> V_102 , V_30 -> V_103 , V_30 -> V_104 , V_30 -> V_105 ,
V_164 ,
F_43 ( V_30 -> V_106 ) ,
V_30 -> V_172 ,
V_30 -> V_173 ,
V_165 ,
V_30 -> V_174 ? '+' : '-' ,
V_30 -> V_91 ? '+' : '-' ,
V_30 -> V_90 ) ;
}
static int F_73 ( struct V_1 * V_22 ,
struct V_73 * V_42 ,
struct V_73 * V_175 [] , int * V_176 )
{
int V_177 = V_22 -> V_162 ;
int V_68 ;
unsigned char V_178 [ 8 ] , V_179 [ 8 ] ;
struct V_73 * V_180 ;
if ( V_177 >= V_161 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_44
L_45 ) ;
return - 1 ;
}
if ( V_42 -> V_105 != - 1 )
goto V_181;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_65 ( V_22 , V_42 -> V_72 ,
V_42 -> V_103 , & V_42 -> V_104 , & V_42 -> V_105 ) != 0 )
return - 1 ;
goto V_181;
}
memcpy ( V_178 , V_42 -> V_72 , 8 ) ;
V_178 [ 4 ] = 0 ;
V_178 [ 5 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_177 ; V_68 ++ ) {
V_180 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_179 , V_180 -> V_72 , 8 ) ;
V_179 [ 4 ] = 0 ;
V_179 [ 5 ] = 0 ;
if ( memcmp ( V_178 , V_179 , 8 ) == 0 ) {
V_42 -> V_103 = V_180 -> V_103 ;
V_42 -> V_104 = V_180 -> V_104 ;
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
V_181:
V_22 -> V_30 [ V_177 ] = V_42 ;
V_22 -> V_162 ++ ;
V_175 [ * V_176 ] = V_42 ;
( * V_176 ) ++ ;
F_70 ( V_182 , V_22 , V_42 ,
V_42 -> V_90 ? L_49 : L_50 ) ;
V_42 -> V_183 = V_42 -> V_91 ;
V_42 -> V_91 = 0 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_22 ,
int V_184 , struct V_73 * V_185 )
{
int V_91 ;
F_76 ( V_184 < 0 || V_184 >= V_161 ) ;
V_22 -> V_30 [ V_184 ] -> V_83 = V_185 -> V_83 ;
if ( V_185 -> V_174 && V_185 -> V_91 ) {
V_22 -> V_30 [ V_184 ] -> V_186 = V_185 -> V_186 ;
V_22 -> V_30 [ V_184 ] -> V_187 = V_185 -> V_187 ;
}
if ( V_185 -> V_188 ) {
V_22 -> V_30 [ V_184 ] -> V_187 = V_185 -> V_187 ;
F_77 () ;
}
V_22 -> V_30 [ V_184 ] -> V_188 = V_185 -> V_188 ;
V_22 -> V_30 [ V_184 ] -> V_174 = V_185 -> V_174 ;
V_22 -> V_30 [ V_184 ] -> V_189 = V_185 -> V_189 ;
V_22 -> V_30 [ V_184 ] -> V_190 = V_185 -> V_190 ;
V_22 -> V_30 [ V_184 ] -> V_183 = V_185 -> V_91 ;
if ( ! V_185 -> V_91 )
V_22 -> V_30 [ V_184 ] -> V_91 = 0 ;
V_91 = V_22 -> V_30 [ V_184 ] -> V_91 ;
V_22 -> V_30 [ V_184 ] -> V_91 = V_22 -> V_30 [ V_184 ] -> V_183 ;
F_70 ( V_182 , V_22 , V_22 -> V_30 [ V_184 ] , L_51 ) ;
V_22 -> V_30 [ V_184 ] -> V_91 = V_91 ;
}
static void F_78 ( struct V_1 * V_22 ,
int V_184 , struct V_73 * V_185 ,
struct V_73 * V_175 [] , int * V_176 ,
struct V_73 * V_191 [] , int * V_192 )
{
F_76 ( V_184 < 0 || V_184 >= V_161 ) ;
V_191 [ * V_192 ] = V_22 -> V_30 [ V_184 ] ;
( * V_192 ) ++ ;
if ( V_185 -> V_104 == - 1 ) {
V_185 -> V_104 = V_22 -> V_30 [ V_184 ] -> V_104 ;
V_185 -> V_105 = V_22 -> V_30 [ V_184 ] -> V_105 ;
}
V_22 -> V_30 [ V_184 ] = V_185 ;
V_175 [ * V_176 ] = V_185 ;
( * V_176 ) ++ ;
F_70 ( V_182 , V_22 , V_185 , L_52 ) ;
V_185 -> V_183 = V_185 -> V_91 ;
V_185 -> V_91 = 0 ;
}
static void F_79 ( struct V_1 * V_22 , int V_184 ,
struct V_73 * V_191 [] , int * V_192 )
{
int V_68 ;
struct V_73 * V_180 ;
F_76 ( V_184 < 0 || V_184 >= V_161 ) ;
V_180 = V_22 -> V_30 [ V_184 ] ;
V_191 [ * V_192 ] = V_22 -> V_30 [ V_184 ] ;
( * V_192 ) ++ ;
for ( V_68 = V_184 ; V_68 < V_22 -> V_162 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_162 -- ;
F_70 ( V_182 , V_22 , V_180 , L_53 ) ;
}
static void F_80 ( struct V_1 * V_22 ,
struct V_73 * V_175 )
{
unsigned long V_78 ;
int V_68 , V_193 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_175 ) {
for ( V_193 = V_68 ; V_193 < V_22 -> V_162 - 1 ; V_193 ++ )
V_22 -> V_30 [ V_193 ] = V_22 -> V_30 [ V_193 + 1 ] ;
V_22 -> V_162 -- ;
break;
}
}
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_81 ( V_175 ) ;
}
static inline int F_82 ( struct V_73 * V_194 ,
struct V_73 * V_195 )
{
if ( memcmp ( V_194 -> V_72 , V_195 -> V_72 ,
sizeof( V_194 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_88 , V_195 -> V_88 ,
sizeof( V_194 -> V_88 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_173 , V_195 -> V_173 , sizeof( V_194 -> V_173 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_172 , V_195 -> V_172 , sizeof( V_194 -> V_172 ) ) != 0 )
return 0 ;
if ( V_194 -> V_106 != V_195 -> V_106 )
return 0 ;
if ( V_194 -> V_103 != V_195 -> V_103 )
return 0 ;
return 1 ;
}
static inline int F_83 ( struct V_73 * V_194 ,
struct V_73 * V_195 )
{
if ( V_194 -> V_83 != V_195 -> V_83 )
return 1 ;
if ( V_194 -> V_174 != V_195 -> V_174 )
return 1 ;
if ( V_194 -> V_91 != V_195 -> V_91 )
return 1 ;
if ( ! F_31 ( V_194 -> V_72 ) )
if ( V_194 -> V_190 != V_195 -> V_190 )
return 1 ;
return 0 ;
}
static int F_84 ( struct V_73 * V_196 ,
struct V_73 * V_197 [] , int V_198 ,
int * V_199 )
{
int V_68 ;
#define F_85 0
#define F_86 1
#define F_87 2
#define F_88 3
if ( V_196 == NULL )
return F_85 ;
for ( V_68 = 0 ; V_68 < V_198 ; V_68 ++ ) {
if ( V_197 [ V_68 ] == NULL )
continue;
if ( F_89 ( V_196 -> V_72 , V_197 [ V_68 ] -> V_72 ) ) {
* V_199 = V_68 ;
if ( F_82 ( V_196 , V_197 [ V_68 ] ) ) {
if ( F_83 ( V_196 , V_197 [ V_68 ] ) )
return F_88 ;
return F_87 ;
} else {
if ( V_196 -> V_200 )
return F_85 ;
return F_86 ;
}
}
}
* V_199 = - 1 ;
return F_85 ;
}
static void F_90 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_201 * V_42 ;
unsigned long V_78 ;
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_91 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_36 ( & V_22 -> V_202 , V_78 ) ;
return;
}
}
F_36 ( & V_22 -> V_202 , V_78 ) ;
V_42 = F_92 ( sizeof( * V_42 ) , V_203 ) ;
if ( ! V_42 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_54 , V_204 ) ;
return;
}
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_93 ( & V_42 -> V_205 , & V_22 -> V_206 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
}
static void F_94 ( struct V_1 * V_22 ,
struct V_73 * V_180 )
{
if ( V_180 -> V_200 == V_207 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_55 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
switch ( V_180 -> V_200 ) {
case V_208 :
break;
case V_209 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_56 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_210 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_57 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_211 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_58 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_212 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_59 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_213 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_60 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_214 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_61 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_215 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_62 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_216 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_63 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_217 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_64 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_218 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_65 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
case V_219 :
F_95 ( & V_22 -> V_29 -> V_30 ,
L_66 ,
V_22 -> V_59 -> V_102 ,
V_180 -> V_103 , V_180 -> V_104 , V_180 -> V_105 ) ;
break;
}
}
static void F_96 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_162 ,
struct V_73 * V_220 )
{
struct V_221 * V_222 = & V_220 -> V_186 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_68 , V_193 ;
int V_226 = F_97 ( V_222 -> V_227 ) +
F_97 ( V_222 -> V_228 ) ;
int V_229 = F_97 ( V_222 -> V_230 ) *
F_97 ( V_222 -> V_231 ) *
V_226 ;
int V_232 = F_97 ( V_222 -> V_231 ) *
V_226 ;
int V_233 ;
if ( V_229 > V_234 )
V_229 = V_234 ;
V_220 -> V_235 = V_229 ;
V_233 = 0 ;
for ( V_68 = 0 ; V_68 < V_229 ; V_68 ++ ) {
V_220 -> V_236 [ V_68 ] = NULL ;
if ( ! V_220 -> V_174 )
continue;
for ( V_193 = 0 ; V_193 < V_162 ; V_193 ++ ) {
if ( V_30 [ V_193 ] == NULL )
continue;
if ( V_30 [ V_193 ] -> V_106 != V_108 &&
V_30 [ V_193 ] -> V_106 != V_109 )
continue;
if ( F_32 ( V_30 [ V_193 ] ) )
continue;
if ( V_30 [ V_193 ] -> V_187 != V_224 [ V_68 ] . V_187 )
continue;
V_220 -> V_236 [ V_68 ] = V_30 [ V_193 ] ;
if ( V_68 < V_232 )
V_233 = F_98 ( V_22 -> V_237 , V_233 +
V_220 -> V_236 [ V_68 ] -> V_190 ) ;
break;
}
if ( ! V_220 -> V_236 [ V_68 ] ) {
V_220 -> V_91 = 0 ;
V_220 -> V_183 = 0 ;
V_220 -> V_190 = 8 ;
}
}
if ( V_229 )
V_220 -> V_190 = V_233 ;
else
V_220 -> V_190 = V_22 -> V_237 ;
}
static void F_99 ( struct V_1 * V_22 ,
struct V_73 * V_30 [] , int V_162 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_162 ; V_68 ++ ) {
if ( V_30 [ V_68 ] == NULL )
continue;
if ( V_30 [ V_68 ] -> V_106 != V_108 &&
V_30 [ V_68 ] -> V_106 != V_109 )
continue;
if ( ! F_32 ( V_30 [ V_68 ] ) )
continue;
if ( V_30 [ V_68 ] -> V_91 )
continue;
F_96 ( V_22 , V_30 , V_162 , V_30 [ V_68 ] ) ;
}
}
static int F_100 ( struct V_1 * V_22 , struct V_73 * V_42 )
{
int V_21 = 0 ;
if ( ! V_22 -> V_59 )
return 1 ;
if ( F_32 ( V_42 ) )
V_21 = F_101 ( V_22 -> V_59 , V_42 -> V_103 ,
V_42 -> V_104 , V_42 -> V_105 ) ;
else
V_21 = F_102 ( V_22 -> V_238 , V_42 ) ;
return V_21 ;
}
static int F_103 ( struct V_1 * V_22 ,
struct V_73 * V_30 )
{
int V_68 ;
int V_48 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
int V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 && F_105 ( V_22 , V_9 , V_30 ,
V_30 -> V_72 ) ) {
unsigned long V_78 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
++ V_48 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_106 ( V_22 , V_9 ) ;
}
return V_48 ;
}
static void F_107 ( struct V_1 * V_22 ,
struct V_73 * V_42 )
{
int V_241 = 0 ;
int V_242 = 0 ;
while ( 1 ) {
V_241 = F_103 ( V_22 , V_42 ) ;
if ( V_241 == 0 )
break;
if ( ++ V_242 > 20 )
break;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_67 ,
V_204 , V_241 ) ;
F_108 ( 1000 ) ;
}
}
static void F_109 ( struct V_1 * V_22 ,
struct V_73 * V_42 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_22 -> V_59 )
return;
if ( F_32 ( V_42 ) ) {
V_3 = F_110 ( V_22 -> V_59 , V_42 -> V_103 ,
V_42 -> V_104 , V_42 -> V_105 ) ;
if ( V_3 ) {
F_111 ( V_3 ) ;
F_112 ( V_3 ) ;
} else {
F_70 ( V_243 , V_22 , V_42 ,
L_68 ) ;
}
} else {
V_42 -> V_191 = 1 ;
F_107 ( V_22 , V_42 ) ;
F_113 ( V_42 ) ;
}
}
static void F_114 ( struct V_1 * V_22 ,
struct V_73 * V_180 [] , int V_244 )
{
int V_68 , V_184 , V_245 , V_246 = 0 ;
struct V_73 * V_247 ;
unsigned long V_78 ;
struct V_73 * * V_175 , * * V_191 ;
int V_176 , V_192 ;
if ( V_22 -> V_248 ) {
V_22 -> V_249 = 1 ;
return;
}
V_175 = F_115 ( sizeof( * V_175 ) * V_161 , V_203 ) ;
V_191 = F_115 ( sizeof( * V_191 ) * V_161 , V_203 ) ;
if ( ! V_175 || ! V_191 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_69
L_70 ) ;
goto V_250;
}
F_35 ( & V_22 -> V_98 , V_78 ) ;
V_68 = 0 ;
V_192 = 0 ;
V_176 = 0 ;
while ( V_68 < V_22 -> V_162 ) {
V_247 = V_22 -> V_30 [ V_68 ] ;
V_245 = F_84 ( V_247 , V_180 , V_244 , & V_184 ) ;
if ( V_245 == F_85 ) {
V_246 ++ ;
F_79 ( V_22 , V_68 , V_191 , & V_192 ) ;
continue;
} else if ( V_245 == F_86 ) {
V_246 ++ ;
F_78 ( V_22 , V_68 , V_180 [ V_184 ] ,
V_175 , & V_176 , V_191 , & V_192 ) ;
V_180 [ V_184 ] = NULL ;
} else if ( V_245 == F_88 ) {
F_75 ( V_22 , V_68 , V_180 [ V_184 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_244 ; V_68 ++ ) {
if ( ! V_180 [ V_68 ] )
continue;
if ( V_180 [ V_68 ] -> V_200 ) {
F_94 ( V_22 , V_180 [ V_68 ] ) ;
F_70 ( V_182 , V_22 , V_180 [ V_68 ] , L_71 ) ;
continue;
}
V_245 = F_84 ( V_180 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_162 , & V_184 ) ;
if ( V_245 == F_85 ) {
V_246 ++ ;
if ( F_73 ( V_22 , V_180 [ V_68 ] , V_175 , & V_176 ) != 0 )
break;
V_180 [ V_68 ] = NULL ;
} else if ( V_245 == F_86 ) {
V_246 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_72 ) ;
}
}
F_99 ( V_22 , V_22 -> V_30 , V_22 -> V_162 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == NULL )
continue;
V_22 -> V_30 [ V_68 ] -> V_91 = V_22 -> V_30 [ V_68 ] -> V_183 ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_244 ; V_68 ++ ) {
if ( ! V_180 [ V_68 ] )
continue;
if ( V_180 [ V_68 ] -> V_200 )
F_90 ( V_22 , V_180 [ V_68 ] -> V_72 ) ;
}
if ( ! V_246 )
goto V_250;
for ( V_68 = 0 ; V_68 < V_192 ; V_68 ++ ) {
if ( V_191 [ V_68 ] == NULL )
continue;
if ( V_191 [ V_68 ] -> V_90 )
F_109 ( V_22 , V_191 [ V_68 ] ) ;
F_81 ( V_191 [ V_68 ] ) ;
V_191 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_176 ; V_68 ++ ) {
int V_21 = 0 ;
if ( V_175 [ V_68 ] == NULL )
continue;
if ( ! ( V_175 [ V_68 ] -> V_90 ) )
continue;
V_21 = F_100 ( V_22 , V_175 [ V_68 ] ) ;
if ( ! V_21 )
continue;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_73 , V_21 ) ;
F_80 ( V_22 , V_175 [ V_68 ] ) ;
V_22 -> V_249 = 1 ;
}
V_250:
F_81 ( V_175 ) ;
F_81 ( V_191 ) ;
}
static struct V_73 * F_116 ( struct V_1 * V_22 ,
int V_103 , int V_104 , int V_105 )
{
int V_68 ;
struct V_73 * V_180 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_180 = V_22 -> V_30 [ V_68 ] ;
if ( V_180 -> V_103 == V_103 && V_180 -> V_104 == V_104 && V_180 -> V_105 == V_105 )
return V_180 ;
}
return NULL ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_73 * V_180 ;
unsigned long V_78 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
if ( F_118 ( V_3 ) == V_251 ) {
struct V_252 * V_253 ;
struct V_254 * V_255 ;
V_253 = V_252 ( V_3 ) ;
V_255 = F_119 ( V_253 ) ;
V_180 = F_120 ( V_22 , V_255 ) ;
if ( V_180 ) {
V_180 -> V_104 = F_121 ( V_3 ) ;
V_180 -> V_105 = V_3 -> V_105 ;
}
} else
V_180 = F_116 ( V_22 , F_118 ( V_3 ) ,
F_121 ( V_3 ) , V_3 -> V_105 ) ;
if ( V_180 && V_180 -> V_90 ) {
F_122 ( & V_180 -> V_256 , 0 ) ;
V_3 -> V_80 = V_180 ;
} else
V_3 -> V_80 = NULL ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 )
{
struct V_73 * V_180 ;
int V_190 ;
V_180 = V_3 -> V_80 ;
V_3 -> V_257 = ! V_180 || ! V_180 -> V_90 ;
if ( V_180 )
V_190 = V_180 -> V_190 != 0 ?
V_180 -> V_190 : V_3 -> V_5 -> V_258 ;
else
V_190 = V_3 -> V_5 -> V_258 ;
F_124 ( V_3 , V_190 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 )
{
}
static void F_126 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_259 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
F_81 ( V_22 -> V_259 [ V_68 ] ) ;
V_22 -> V_259 [ V_68 ] = NULL ;
}
F_81 ( V_22 -> V_259 ) ;
V_22 -> V_259 = NULL ;
}
static int F_127 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_260 <= 0 )
return 0 ;
V_22 -> V_259 =
F_115 ( sizeof( * V_22 -> V_259 ) * V_22 -> V_237 ,
V_203 ) ;
if ( ! V_22 -> V_259 )
return - V_261 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_22 -> V_259 [ V_68 ] =
F_92 ( sizeof( * V_22 -> V_259 [ V_68 ] ) *
V_22 -> V_262 , V_203 ) ;
if ( ! V_22 -> V_259 [ V_68 ] )
goto V_263;
}
return 0 ;
V_263:
F_126 ( V_22 ) ;
return - V_261 ;
}
static void F_128 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_264 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
F_81 ( V_22 -> V_264 [ V_68 ] ) ;
V_22 -> V_264 [ V_68 ] = NULL ;
}
F_81 ( V_22 -> V_264 ) ;
V_22 -> V_264 = NULL ;
}
static int F_129 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_260 <= 0 )
return 0 ;
V_22 -> V_264 = F_115 ( sizeof( * V_22 -> V_264 ) * V_22 -> V_237 ,
V_203 ) ;
if ( ! V_22 -> V_264 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_74 ) ;
return - V_261 ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_22 -> V_264 [ V_68 ] = F_92 ( sizeof( * V_22 -> V_264 [ V_68 ] ) *
V_22 -> V_260 , V_203 ) ;
if ( ! V_22 -> V_264 [ V_68 ] ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_75 ) ;
goto V_263;
}
}
return 0 ;
V_263:
F_128 ( V_22 ) ;
return - V_261 ;
}
static int F_130 ( struct V_1 * V_22 ,
struct V_139 * V_131 , struct V_8 * V_9 )
{
struct V_265 * V_266 ;
T_5 V_267 ;
T_4 V_268 ;
V_266 = V_22 -> V_259 [ V_9 -> V_133 ] ;
V_268 = F_131 ( V_131 -> V_269 [ 0 ] . V_270 ) ;
V_267 = F_132 ( V_22 -> V_29 , V_266 , V_268 ,
V_271 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 , V_267 ) ) {
V_131 -> V_269 -> V_272 = 0 ;
return - 1 ;
}
V_131 -> V_269 -> V_272 = F_134 ( V_267 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_22 ,
struct V_139 * V_131 )
{
struct V_265 * V_273 ;
T_5 V_267 ;
T_4 V_268 ;
V_273 = V_131 -> V_269 ;
V_267 = F_136 ( V_273 -> V_272 ) ;
V_268 = F_131 ( V_131 -> V_269 [ 0 ] . V_270 ) ;
F_137 ( V_22 -> V_29 , V_267 , V_268 , V_271 ) ;
}
static int F_138 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_274 * V_273 , * V_266 ;
T_5 V_267 ;
T_4 V_275 ;
V_273 = & V_9 -> V_276 [ V_22 -> V_277 - 1 ] ;
V_266 = V_22 -> V_264 [ V_9 -> V_133 ] ;
V_273 -> V_278 = F_139 ( V_279 ) ;
V_275 = sizeof( * V_273 ) *
( F_97 ( V_9 -> V_124 . V_280 ) - V_22 -> V_277 ) ;
V_273 -> V_281 = F_139 ( V_275 ) ;
V_267 = F_132 ( V_22 -> V_29 , V_266 , V_275 ,
V_271 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 , V_267 ) ) {
V_273 -> V_282 = F_134 ( 0 ) ;
return - 1 ;
}
V_273 -> V_282 = F_134 ( V_267 ) ;
return 0 ;
}
static void F_140 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_274 * V_273 ;
if ( F_97 ( V_9 -> V_124 . V_280 ) <= V_22 -> V_277 )
return;
V_273 = & V_9 -> V_276 [ V_22 -> V_277 - 1 ] ;
F_137 ( V_22 -> V_29 , F_136 ( V_273 -> V_282 ) ,
F_131 ( V_273 -> V_281 ) , V_271 ) ;
}
static int F_141 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_283 * V_284 ,
struct V_139 * V_285 ,
struct V_73 * V_30 )
{
int V_286 ;
int V_287 = 0 ;
T_4 V_288 = 0 ;
switch ( V_285 -> V_289 . V_290 ) {
case V_291 :
switch ( V_285 -> V_289 . V_49 ) {
case V_292 :
break;
case V_293 :
V_284 -> V_294 |= V_295 ;
if ( V_285 -> V_289 . V_296 !=
V_297 ) {
memset ( V_284 -> V_298 , 0 ,
V_299 ) ;
break;
}
V_286 = V_285 -> V_289 . V_15 ;
if ( V_286 > V_299 )
V_286 = V_299 ;
if ( V_286 > sizeof( V_285 -> V_289 . V_300 ) )
V_286 =
sizeof( V_285 -> V_289 . V_300 ) ;
memcpy ( V_284 -> V_298 ,
V_285 -> V_289 . V_300 , V_286 ) ;
V_287 = 1 ;
break;
case V_301 :
V_287 = 1 ;
break;
case V_302 :
V_287 = 1 ;
break;
case V_303 :
V_287 = 1 ;
break;
case V_304 :
V_287 = 1 ;
break;
default:
V_287 = 1 ;
break;
}
break;
case V_305 :
switch ( V_285 -> V_289 . V_49 ) {
case V_306 :
case V_307 :
case V_308 :
V_287 = 1 ;
break;
case V_309 :
V_284 -> V_294 = ( V_310 << 16 ) ;
V_284 -> V_294 |= ( V_311 << 8 ) ;
V_288 = F_142 (
& V_285 -> V_289 . V_312 [ 0 ] ) ;
F_143 ( V_284 , V_288 ) ;
break;
case V_313 :
case V_314 :
case V_315 :
if ( V_30 -> V_74 && V_30 -> V_90 ) {
V_284 -> V_294 = V_316 << 16 ;
V_30 -> V_191 = 1 ;
V_22 -> V_249 = 1 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_76 , V_204 ) ;
} else
V_287 = 1 ;
break;
default:
V_287 = 1 ;
}
break;
case V_317 :
break;
case V_318 :
break;
case V_319 :
V_287 = 1 ;
break;
case V_320 :
break;
default:
V_287 = 1 ;
break;
}
return V_287 ;
}
static void F_144 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_321 = false ;
V_9 -> V_10 = V_11 ;
F_145 () ;
if ( V_9 -> V_12 ) {
V_321 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_78 ;
struct V_73 * V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_58 ( & V_30 -> V_322 ) )
V_321 = true ;
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
if ( V_321 )
F_146 ( & V_22 -> V_323 ) ;
}
static void F_147 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_144 ( V_22 , V_9 ) ;
F_148 ( V_22 , V_9 ) ;
}
static void F_149 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 )
{
F_147 ( V_22 , V_9 ) ;
V_284 -> V_324 ( V_284 ) ;
}
static void F_150 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_151 ( & V_9 -> V_325 , V_326 ) ;
F_152 ( F_49 () , V_22 -> V_327 , & V_9 -> V_325 ) ;
}
static void F_153 ( struct V_283 * V_284 )
{
V_284 -> V_294 = V_328 << 16 ;
}
static void F_154 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_283 * V_284 )
{
F_153 ( V_284 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_77 ,
V_9 -> V_144 . V_145 , V_9 -> V_24 -> V_38 ) ;
F_147 ( V_22 , V_9 ) ;
}
static void F_155 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
struct V_73 * V_30 )
{
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
if ( F_48 ( V_285 -> V_289 . V_290 == 0 &&
V_285 -> V_289 . V_49 == 0 ) )
return F_149 ( V_22 , V_9 , V_284 ) ;
if ( F_32 ( V_30 ) &&
V_285 -> V_289 . V_290 ==
V_305 ) {
if ( V_285 -> V_289 . V_49 ==
V_315 ) {
V_30 -> V_91 = 0 ;
V_30 -> V_183 = 0 ;
}
return F_150 ( V_22 , V_9 ) ;
}
if ( F_141 ( V_22 , V_9 , V_284 , V_285 , V_30 ) )
return F_150 ( V_22 , V_9 ) ;
return F_149 ( V_22 , V_9 , V_284 ) ;
}
static int F_156 ( struct V_1 * V_22 ,
struct V_8 * V_131 )
{
T_1 V_329 = V_131 -> V_24 -> V_38 ;
switch ( V_329 ) {
case V_330 :
case V_331 :
return 0 ;
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_78 ,
V_329 ) ;
break;
}
return - V_329 ;
}
static void F_157 ( struct V_8 * V_131 )
{
struct V_283 * V_284 ;
struct V_1 * V_22 ;
struct V_337 * V_338 ;
struct V_73 * V_30 ;
struct V_139 * V_285 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_339 ;
V_338 = V_131 -> V_24 ;
V_284 = V_131 -> V_10 ;
V_22 = V_131 -> V_22 ;
V_30 = V_284 -> V_42 -> V_80 ;
V_285 = & V_22 -> V_137 [ V_131 -> V_133 ] ;
F_158 ( V_284 ) ;
if ( ( V_131 -> V_150 == V_340 ) &&
( F_97 ( V_131 -> V_124 . V_280 ) > V_22 -> V_277 ) )
F_140 ( V_22 , V_131 ) ;
if ( ( V_131 -> V_150 == V_154 ) &&
( V_285 -> V_269 [ 0 ] . V_341 == V_342 ) )
F_135 ( V_22 , V_285 ) ;
V_284 -> V_294 = ( V_310 << 16 ) ;
V_284 -> V_294 |= ( V_311 << 8 ) ;
if ( V_131 -> V_150 == V_154 || V_131 -> V_150 == V_151 )
F_46 ( & V_131 -> V_236 -> V_256 ) ;
if ( F_45 ( V_338 -> V_36 == V_343 ) ) {
V_284 -> V_294 = V_316 << 16 ;
return F_149 ( V_22 , V_131 , V_284 ) ;
}
if ( ( F_45 ( F_5 ( V_131 ) ) ) ) {
if ( V_131 -> V_13 )
return F_147 ( V_22 , V_131 ) ;
if ( V_131 -> V_12 )
return F_154 ( V_22 , V_131 , V_284 ) ;
}
if ( V_131 -> V_150 == V_154 )
return F_155 ( V_22 , V_131 , V_284 , V_30 ) ;
F_143 ( V_284 , V_338 -> V_344 ) ;
if ( V_338 -> V_36 == 0 )
return F_149 ( V_22 , V_131 , V_284 ) ;
if ( V_131 -> V_150 == V_151 ) {
struct V_130 * V_9 = & V_22 -> V_132 [ V_131 -> V_133 ] ;
V_131 -> V_124 . V_125 = F_159 ( V_284 ) ;
V_131 -> V_124 . V_280 = F_160 ( V_131 -> V_124 . V_125 ) ;
V_131 -> V_144 . V_345 = F_97 ( V_9 -> V_346 ) &
V_347 ;
V_131 -> V_124 . V_348 = V_9 -> V_348 ;
memcpy ( V_131 -> V_124 . V_349 . V_350 , V_9 -> V_351 , 8 ) ;
memcpy ( V_131 -> V_144 . V_145 , V_9 -> V_145 , V_131 -> V_144 . V_345 ) ;
if ( F_32 ( V_30 ) ) {
if ( V_338 -> V_36 == V_352 )
V_30 -> V_91 = 0 ;
return F_150 ( V_22 , V_131 ) ;
}
}
switch ( V_338 -> V_36 ) {
case V_37 :
V_284 -> V_294 |= V_338 -> V_38 ;
if ( V_299 < sizeof( V_338 -> V_26 ) )
V_339 = V_299 ;
else
V_339 = sizeof( V_338 -> V_26 ) ;
if ( V_338 -> V_25 < V_339 )
V_339 = V_338 -> V_25 ;
memcpy ( V_284 -> V_298 , V_338 -> V_26 , V_339 ) ;
if ( V_338 -> V_38 )
F_6 ( V_338 -> V_26 , V_339 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_338 -> V_38 == V_295 ) {
if ( V_16 == V_353 ) {
V_284 -> V_294 |= V_354 << 16 ;
break;
}
break;
}
if ( V_338 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_79
L_80
L_81 ,
V_131 , V_338 -> V_38 ,
V_16 , V_17 , V_18 ,
V_284 -> V_294 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_82
L_83 , V_131 ) ,
V_284 -> V_294 = V_316 << 16 ;
}
break;
case V_355 :
break;
case V_356 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_84 , V_131 -> V_144 . V_145 ) ;
break;
case V_357 : {
V_284 -> V_294 = V_316 << 16 ;
}
break;
case V_358 :
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_85 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_360 :
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_86 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_361 :
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_87 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_362 :
return F_154 ( V_22 , V_131 , V_284 ) ;
case V_363 :
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_88 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_364 :
V_284 -> V_294 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_89 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_365 :
V_284 -> V_294 = V_366 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_90 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_367 :
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_91 ) ;
break;
case V_368 :
if ( F_156 ( V_22 , V_131 ) )
V_284 -> V_294 = V_359 << 16 ;
break;
case V_352 :
V_284 -> V_294 = V_354 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_92 , V_131 ) ;
break;
default:
V_284 -> V_294 = V_359 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_93 ,
V_131 , V_338 -> V_36 ) ;
}
return F_149 ( V_22 , V_131 , V_284 ) ;
}
static void F_161 ( struct V_369 * V_29 ,
struct V_8 * V_9 , int V_370 , int V_371 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ )
F_137 ( V_29 , ( V_372 ) F_136 ( V_9 -> V_276 [ V_68 ] . V_282 ) ,
F_131 ( V_9 -> V_276 [ V_68 ] . V_281 ) ,
V_371 ) ;
}
static int F_162 ( struct V_369 * V_29 ,
struct V_8 * V_131 ,
unsigned char * V_45 ,
T_3 V_373 ,
int V_371 )
{
T_5 V_374 ;
if ( V_373 == 0 || V_371 == V_375 ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_280 = F_160 ( 0 ) ;
return 0 ;
}
V_374 = F_132 ( V_29 , V_45 , V_373 , V_371 ) ;
if ( F_133 ( & V_29 -> V_30 , V_374 ) ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_280 = F_160 ( 0 ) ;
return - 1 ;
}
V_131 -> V_276 [ 0 ] . V_282 = F_134 ( V_374 ) ;
V_131 -> V_276 [ 0 ] . V_281 = F_139 ( V_373 ) ;
V_131 -> V_276 [ 0 ] . V_278 = F_139 ( V_376 ) ;
V_131 -> V_124 . V_125 = 1 ;
V_131 -> V_124 . V_280 = F_160 ( 1 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_113 , unsigned long V_377 )
{
F_164 ( V_378 ) ;
V_9 -> V_379 = & V_378 ;
F_59 ( V_22 , V_9 , V_113 ) ;
if ( V_377 == V_380 ) {
F_165 ( & V_378 ) ;
return V_381 ;
}
if ( ! F_166 ( & V_378 ,
F_167 ( V_377 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_94 ) ;
return - V_382 ;
}
return V_381 ;
}
static int F_168 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_113 , unsigned long V_377 )
{
if ( F_45 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_343 ;
return V_381 ;
}
return F_163 ( V_22 , V_9 , V_113 , V_377 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_383 ;
T_4 V_21 , * F_13 ;
V_383 = F_169 () ;
F_13 = F_170 ( V_22 -> F_13 , V_383 ) ;
V_21 = * F_13 ;
F_171 () ;
return V_21 ;
}
static int F_172 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_371 , unsigned long V_377 )
{
int V_384 = 10 , V_385 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_377 ) ;
if ( V_21 )
break;
V_385 ++ ;
if ( V_385 > 3 ) {
F_108 ( V_384 ) ;
if ( V_384 < 1000 )
V_384 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_385 <= V_386 );
F_161 ( V_22 -> V_29 , V_9 , 1 , V_371 ) ;
if ( V_385 > V_386 )
V_21 = - V_387 ;
return V_21 ;
}
static void F_173 ( struct V_1 * V_22 , char * V_388 ,
struct V_8 * V_9 )
{
const T_1 * V_141 = V_9 -> V_144 . V_145 ;
const T_1 * V_105 = V_9 -> V_124 . V_349 . V_350 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_95
L_96 ,
V_388 , V_105 [ 0 ] , V_105 [ 1 ] , V_105 [ 2 ] , V_105 [ 3 ] ,
V_105 [ 4 ] , V_105 [ 5 ] , V_105 [ 6 ] , V_105 [ 7 ] ,
V_141 [ 0 ] , V_141 [ 1 ] , V_141 [ 2 ] , V_141 [ 3 ] ,
V_141 [ 4 ] , V_141 [ 5 ] , V_141 [ 6 ] , V_141 [ 7 ] ,
V_141 [ 8 ] , V_141 [ 9 ] , V_141 [ 10 ] , V_141 [ 11 ] ,
V_141 [ 12 ] , V_141 [ 13 ] , V_141 [ 14 ] , V_141 [ 15 ] ) ;
}
static void F_174 ( struct V_1 * V_22 ,
struct V_8 * V_131 )
{
const struct V_337 * V_338 = V_131 -> V_24 ;
struct V_42 * V_389 = & V_131 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_338 -> V_36 ) {
case V_37 :
if ( V_338 -> V_25 > sizeof( V_338 -> V_26 ) )
V_23 = sizeof( V_338 -> V_26 ) ;
else
V_23 = V_338 -> V_25 ;
F_6 ( V_338 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_173 ( V_22 , L_97 , V_131 ) ;
if ( V_338 -> V_38 == V_295 )
F_9 ( V_389 , L_98 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_389 , L_99 , V_338 -> V_38 ) ;
if ( V_338 -> V_38 == 0 )
F_9 ( V_389 , L_100
L_101
L_102
L_103 ) ;
break;
case V_355 :
break;
case V_356 :
F_173 ( V_22 , L_104 , V_131 ) ;
break;
case V_357 : {
F_173 ( V_22 , L_105 , V_131 ) ;
F_9 ( V_389 , L_106 ) ;
}
break;
case V_358 :
F_173 ( V_22 , L_107 , V_131 ) ;
break;
case V_360 :
F_173 ( V_22 , L_108 , V_131 ) ;
break;
case V_361 :
F_173 ( V_22 , L_109 , V_131 ) ;
break;
case V_362 :
F_173 ( V_22 , L_110 , V_131 ) ;
break;
case V_363 :
F_173 ( V_22 , L_111 , V_131 ) ;
break;
case V_364 :
F_173 ( V_22 , L_112 , V_131 ) ;
break;
case V_365 :
F_173 ( V_22 , L_113 , V_131 ) ;
break;
case V_367 :
F_173 ( V_22 , L_114 , V_131 ) ;
break;
case V_343 :
F_173 ( V_22 , L_115 , V_131 ) ;
break;
default:
F_173 ( V_22 , L_116 , V_131 ) ;
F_9 ( V_389 , L_117 ,
V_338 -> V_36 ) ;
}
}
static int F_175 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_390 , unsigned char * V_45 ,
unsigned char V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_392 , V_22 , V_45 , V_391 ,
V_390 , V_72 , V_393 ) ) {
V_21 = - 1 ;
goto V_394;
}
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_178 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_397 , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_397 , V_22 , NULL , 0 , 0 ,
V_72 , V_398 ) ;
V_21 = F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_118 ) ;
goto V_394;
}
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_105 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_73 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_399 = false ;
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_400 = (struct V_136 * ) V_285 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_150 ) {
case V_340 :
case V_401 :
V_399 = ! memcmp ( V_72 , & V_9 -> V_124 . V_349 . V_350 ,
sizeof( V_9 -> V_124 . V_349 . V_350 ) ) ;
break;
case V_151 :
case V_154 :
if ( V_9 -> V_236 == V_30 ) {
V_399 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_235 && ! V_399 ; V_68 ++ ) {
V_399 = V_30 -> V_236 [ V_68 ] == V_9 -> V_236 ;
}
}
break;
case V_156 :
for ( V_68 = 0 ; V_68 < V_30 -> V_235 && ! V_399 ; V_68 ++ ) {
V_399 = V_30 -> V_236 [ V_68 ] -> V_187 ==
F_131 ( V_400 -> V_402 ) ;
}
break;
case 0 :
V_399 = false ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_119 ,
V_9 -> V_150 ) ;
F_179 () ;
}
return V_399 ;
}
static int F_180 ( struct V_1 * V_22 , struct V_73 * V_30 ,
unsigned char * V_72 , T_1 V_397 , int V_113 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_181 ( & V_22 -> V_403 ) == - V_404 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_120 ) ;
return - V_404 ;
}
F_76 ( F_21 ( & V_30 -> V_322 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
int V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 && F_105 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_78 ;
V_9 -> V_13 = V_30 ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! F_4 ( V_9 ) )
F_56 ( & V_30 -> V_322 ) ;
else
V_9 -> V_13 = NULL ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
F_106 ( V_22 , V_9 ) ;
}
V_21 = F_178 ( V_22 , V_72 , V_397 , V_113 ) ;
if ( ! V_21 )
F_182 ( V_22 -> V_323 ,
F_21 ( & V_30 -> V_322 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_45 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_121 ) ;
V_21 = - V_81 ;
}
if ( F_45 ( V_21 ) )
F_122 ( & V_30 -> V_322 , 0 ) ;
F_183 ( & V_22 -> V_403 ) ;
return V_21 ;
}
static void F_184 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_83 )
{
int V_21 ;
unsigned char * V_45 ;
* V_83 = V_84 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return;
V_21 = F_175 ( V_22 , V_72 , V_405 | 0xC1 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_83 = V_45 [ 8 ] ;
if ( * V_83 > V_84 )
* V_83 = V_84 ;
F_81 ( V_45 ) ;
return;
}
static void F_185 ( struct V_1 * V_22 , int V_21 ,
struct V_221 * V_406 )
{
struct V_223 * V_224 = & V_406 -> V_225 [ 0 ] ;
int V_222 , V_407 , V_408 ;
T_6 V_409 , V_230 , V_410 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_95 ( & V_22 -> V_29 -> V_30 , L_122 ,
F_131 ( V_406 -> V_411 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_123 ,
F_131 ( V_406 -> V_412 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_136 ( V_406 -> V_413 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_125 ,
V_406 -> V_414 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_126 ,
V_406 -> V_415 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_97 ( V_406 -> V_416 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_128 ,
F_136 ( V_406 -> V_417 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_129 ,
F_136 ( V_406 -> V_418 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_130 ,
F_97 ( V_406 -> V_227 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_131 ,
F_97 ( V_406 -> V_228 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_132 ,
F_97 ( V_406 -> V_230 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_133 ,
F_97 ( V_406 -> V_231 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_134 ,
F_97 ( V_406 -> V_78 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_135 ,
F_97 ( V_406 -> V_78 ) &
V_419 ? L_136 : L_137 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_138 ,
F_97 ( V_406 -> V_420 ) ) ;
V_409 = F_97 ( V_406 -> V_231 ) ;
for ( V_222 = 0 ; V_222 < V_409 ; V_222 ++ ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_139 , V_222 ) ;
V_230 = F_97 ( V_406 -> V_230 ) ;
for ( V_407 = 0 ; V_407 < V_230 ; V_407 ++ ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_140 , V_407 ) ;
V_410 =
F_97 ( V_406 -> V_227 ) ;
for ( V_408 = 0 ; V_408 < V_410 ; V_408 ++ , V_224 ++ )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_141 ,
V_408 , V_224 -> V_187 ,
V_224 -> V_421 [ 0 ] , V_224 -> V_421 [ 1 ] ) ;
V_410 =
F_97 ( V_406 -> V_228 ) ;
for ( V_408 = 0 ; V_408 < V_410 ; V_408 ++ , V_224 ++ )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_142 ,
V_408 , V_224 -> V_187 ,
V_224 -> V_421 [ 0 ] , V_224 -> V_421 [ 1 ] ) ;
}
}
}
static int F_186 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_422 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_423 , V_22 , & V_422 -> V_186 ,
sizeof( V_422 -> V_186 ) , 0 ,
V_72 , V_393 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_143 ) ;
F_106 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_394;
}
F_106 ( V_22 , V_9 ) ;
if ( F_131 ( V_422 -> V_186 . V_411 ) >
sizeof( V_422 -> V_186 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
V_21 = - 1 ;
}
F_185 ( V_22 , V_21 , & V_422 -> V_186 ) ;
return V_21 ;
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_187 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_424 ,
struct V_425 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_426 , V_22 , V_45 , V_391 ,
0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
V_9 -> V_144 . V_145 [ 2 ] = V_424 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_424 >> 8 ) & 0xff ;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_188 ( struct V_1 * V_22 ,
struct V_427 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_428 , V_22 , V_45 , V_391 ,
0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_189 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_424 ,
struct V_429 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_430 , V_22 , V_45 , V_391 ,
0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
V_9 -> V_144 . V_145 [ 2 ] = V_424 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_424 >> 8 ) & 0xff ;
F_172 ( V_22 , V_9 , V_395 ,
V_396 ) ;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static void F_190 ( struct V_1 * V_22 ,
unsigned char * V_72 ,
struct V_431 * V_432 , int V_433 ,
struct V_73 * V_434 )
{
int V_21 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_337 * V_338 = NULL ;
struct V_435 * V_436 = NULL ;
struct V_429 * V_437 = NULL ;
struct V_438 * V_439 = & V_432 -> V_349 [ V_433 ] ;
T_6 V_424 = 0 ;
V_424 = F_191 ( & V_439 -> V_86 [ 0 ] ) ;
if ( V_424 == 0xFF00 || F_192 ( & V_439 -> V_86 [ 0 ] ) ) {
V_21 = V_381 ;
goto V_394;
}
V_436 = F_115 ( sizeof( * V_436 ) , V_203 ) ;
if ( ! V_436 )
goto V_394;
V_437 = F_115 ( sizeof( * V_437 ) , V_203 ) ;
if ( ! V_437 )
goto V_394;
V_21 = F_189 ( V_22 , V_72 , V_424 ,
V_437 , sizeof( * V_437 ) ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_145 ,
V_204 , V_434 -> V_167 , V_424 ) ;
goto V_394;
}
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_440 , V_22 , V_436 ,
sizeof( * V_436 ) , 0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
if ( V_437 -> V_97 [ 1 ] == 'E' )
V_9 -> V_144 . V_145 [ 5 ] = V_437 -> V_441 ;
else
V_9 -> V_144 . V_145 [ 5 ] = 0 ;
V_21 = F_172 ( V_22 , V_9 , V_395 ,
V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 && V_338 -> V_36 != V_355 ) {
V_21 = - 1 ;
goto V_394;
}
V_434 -> V_93 [ V_437 -> V_442 ] = V_436 -> V_443 ;
memcpy ( & V_434 -> V_97 [ V_437 -> V_442 ] ,
V_436 -> V_97 , sizeof( V_436 -> V_97 ) ) ;
V_21 = V_381 ;
V_394:
F_81 ( V_436 ) ;
F_81 ( V_437 ) ;
if ( V_9 )
F_106 ( V_22 , V_9 ) ;
if ( V_21 != V_381 )
F_70 ( V_182 , V_22 , V_434 ,
L_146 ) ;
}
static T_5 F_193 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_431 * V_444 ;
T_4 V_445 ;
T_5 V_446 = 0 ;
int V_68 ;
V_444 = F_115 ( sizeof( * V_444 ) , V_203 ) ;
if ( ! V_444 )
return 0 ;
if ( F_194 ( V_22 , V_444 , sizeof( * V_444 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
F_81 ( V_444 ) ;
return 0 ;
}
V_445 = F_195 ( V_444 -> V_447 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_445 ; V_68 ++ )
if ( ! memcmp ( & V_444 -> V_349 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_446 = F_196 ( & V_444 -> V_349 [ V_68 ] . V_448 [ 0 ] ) ;
break;
}
F_81 ( V_444 ) ;
return V_446 ;
}
static void F_197 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_446 = 0 ;
if ( F_63 ( V_72 ) ) {
struct V_425 * V_449 ;
V_449 = F_115 ( sizeof( * V_449 ) , V_203 ) ;
if ( V_449 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_148 , V_204 ) ;
return;
}
V_21 = F_187 ( V_22 ,
V_72 , 0 , V_449 , sizeof( * V_449 ) ) ;
if ( V_21 == 0 ) {
V_446 = F_196 ( V_449 -> V_450 ) ;
V_22 -> V_89 = V_446 ;
}
F_81 ( V_449 ) ;
} else
V_446 = F_193 ( V_22 , V_72 ) ;
V_30 -> V_89 = V_446 ;
}
static int F_198 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_390 )
{
int V_21 ;
int V_68 ;
int V_451 ;
unsigned char * V_45 , V_391 ;
V_45 = F_115 ( 256 , V_203 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_175 ( V_22 , V_72 ,
V_405 | V_452 ,
V_45 , V_453 ) ;
if ( V_21 != 0 )
goto V_454;
V_451 = V_45 [ 3 ] ;
if ( ( V_451 + V_453 ) <= 255 )
V_391 = V_451 + V_453 ;
else
V_391 = 255 ;
V_21 = F_175 ( V_22 , V_72 ,
V_405 | V_452 ,
V_45 , V_391 ) ;
if ( V_21 != 0 )
goto V_454;
V_451 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_451 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_390 )
goto V_455;
V_454:
F_81 ( V_45 ) ;
return 0 ;
V_455:
F_81 ( V_45 ) ;
return 1 ;
}
static void F_199 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_422 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_456 ;
V_422 -> V_174 = 0 ;
V_422 -> V_91 = 0 ;
V_422 -> V_183 = 0 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return;
if ( ! F_198 ( V_22 , V_72 , V_457 ) )
goto V_394;
V_21 = F_175 ( V_22 , V_72 ,
V_405 | V_457 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_394;
#define F_200 4
#define F_201 0x01
#define F_202 0x02
V_456 = V_45 [ F_200 ] ;
V_422 -> V_174 =
! ! ( V_456 & F_201 ) ;
if ( V_422 -> V_174 ) {
V_422 -> V_91 =
! ! ( V_456 & F_202 ) ;
if ( F_186 ( V_22 , V_72 , V_422 ) )
V_422 -> V_91 = 0 ;
}
V_422 -> V_183 = V_422 -> V_91 ;
V_394:
F_81 ( V_45 ) ;
return;
}
static int F_203 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_88 , int V_199 , int V_373 )
{
int V_21 ;
unsigned char * V_45 ;
if ( V_373 > 16 )
V_373 = 16 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return - V_261 ;
V_21 = F_175 ( V_22 , V_72 , V_405 | 0x83 , V_45 , 64 ) ;
if ( V_21 == 0 )
memcpy ( V_88 , & V_45 [ V_199 ] , V_373 ) ;
F_81 ( V_45 ) ;
return V_21 != 0 ;
}
static int F_204 ( struct V_1 * V_22 , int V_458 ,
void * V_45 , int V_391 ,
int V_459 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_177 ( V_9 , V_458 ? V_460 : V_461 , V_22 ,
V_45 , V_391 , 0 , V_72 , V_393 ) ) {
V_21 = - 1 ;
goto V_394;
}
if ( V_459 )
V_9 -> V_144 . V_145 [ 1 ] = V_459 ;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( V_21 )
goto V_394;
V_338 = V_9 -> V_24 ;
if ( V_338 -> V_36 != 0 &&
V_338 -> V_36 != V_355 ) {
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_462 * V_463 = V_45 ;
if ( V_463 -> V_464 != V_459 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_149 ,
V_459 ,
V_463 -> V_464 ) ;
V_21 = - 1 ;
}
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_194 ( struct V_1 * V_22 ,
struct V_431 * V_45 , int V_391 )
{
return F_204 ( V_22 , 0 , V_45 , V_391 ,
V_465 ) ;
}
static inline int F_205 ( struct V_1 * V_22 ,
struct V_462 * V_45 , int V_391 )
{
return F_204 ( V_22 , 1 , V_45 , V_391 , 0 ) ;
}
static inline void F_206 ( struct V_73 * V_42 ,
int V_103 , int V_104 , int V_105 )
{
V_42 -> V_103 = V_103 ;
V_42 -> V_104 = V_104 ;
V_42 -> V_105 = V_105 ;
}
static int F_207 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_466 ;
unsigned char * V_45 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return V_207 ;
if ( ! F_198 ( V_22 , V_72 , V_467 ) )
goto V_468;
V_21 = F_175 ( V_22 , V_72 , V_405 | V_467 ,
V_45 , V_453 ) ;
if ( V_21 != 0 )
goto V_468;
V_466 = V_45 [ 3 ] ;
V_21 = F_175 ( V_22 , V_72 , V_405 | V_467 ,
V_45 , V_466 + V_453 ) ;
if ( V_21 != 0 )
goto V_468;
V_49 = V_45 [ 4 ] ;
F_81 ( V_45 ) ;
return V_49 ;
V_468:
F_81 ( V_45 ) ;
return V_207 ;
}
static int F_208 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_469 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_470 = 0 ;
T_6 V_471 ;
T_1 V_472 ;
#define F_209 0x04
#define F_210 0x04
#define F_211 0x02
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_473 , V_22 , NULL , 0 , 0 , V_72 , V_393 ) ;
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_396 ) ;
if ( V_21 ) {
F_106 ( V_22 , V_9 ) ;
return 0 ;
}
V_469 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_469 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_471 = V_9 -> V_24 -> V_36 ;
V_472 = V_9 -> V_24 -> V_38 ;
F_106 ( V_22 , V_9 ) ;
if ( V_471 != V_37 ||
V_472 != V_295 ||
V_16 != V_474 ||
V_17 != F_209 ) {
return 0 ;
}
V_470 = F_207 ( V_22 , V_72 ) ;
switch ( V_470 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
return V_470 ;
case V_207 :
if ( ( V_18 == F_210 ) ||
( V_18 == F_211 ) )
return V_470 ;
break;
default:
break;
}
return 0 ;
}
static int F_212 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_337 * V_338 ;
int V_21 = 0 ;
T_5 V_348 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_475 , V_22 , & V_348 , 0 , 0 , V_72 , V_398 ) ;
( void ) F_168 ( V_22 , V_9 , V_127 ,
V_396 ) ;
V_338 = V_9 -> V_24 ;
switch ( V_338 -> V_36 ) {
case V_357 :
V_21 = 0 ;
break;
case V_367 :
case V_363 :
V_21 = 1 ;
break;
case V_368 :
V_21 = F_156 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_213 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_73 * V_422 ,
unsigned char * V_476 )
{
#define F_214 43
#define F_215 "$DR-10"
#define F_216 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_217 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_477 ;
unsigned char * V_478 ;
int V_21 = 0 ;
V_477 = F_115 ( F_217 , V_203 ) ;
if ( ! V_477 ) {
V_21 = - V_261 ;
goto V_479;
}
if ( F_175 ( V_22 , V_72 , 0 , V_477 ,
( unsigned char ) F_217 ) != 0 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_150 ) ;
V_21 = - V_387 ;
goto V_479;
}
F_218 ( & V_477 [ 8 ] , 8 ) ;
F_218 ( & V_477 [ 16 ] , 16 ) ;
V_422 -> V_106 = ( V_477 [ 0 ] & 0x1f ) ;
memcpy ( V_422 -> V_72 , V_72 , 8 ) ;
memcpy ( V_422 -> V_172 , & V_477 [ 8 ] ,
sizeof( V_422 -> V_172 ) ) ;
memcpy ( V_422 -> V_173 , & V_477 [ 16 ] ,
sizeof( V_422 -> V_173 ) ) ;
memset ( V_422 -> V_88 , 0 ,
sizeof( V_422 -> V_88 ) ) ;
F_203 ( V_22 , V_72 , V_422 -> V_88 , 8 ,
sizeof( V_422 -> V_88 ) ) ;
if ( ( V_422 -> V_106 == V_108 ||
V_422 -> V_106 == V_109 ) &&
F_31 ( V_72 ) ) {
int V_200 ;
F_184 ( V_22 , V_72 , & V_422 -> V_83 ) ;
if ( V_22 -> V_480 & V_481 )
F_199 ( V_22 , V_72 , V_422 ) ;
V_200 = F_208 ( V_22 , V_72 ) ;
if ( V_200 < 0 || V_200 > 0xff )
V_200 = V_207 ;
V_422 -> V_200 = V_200 & 0xff ;
} else {
V_422 -> V_83 = V_84 ;
V_422 -> V_174 = 0 ;
V_422 -> V_91 = 0 ;
V_422 -> V_183 = 0 ;
V_422 -> V_188 = 0 ;
V_422 -> V_200 = 0 ;
V_422 -> V_190 = V_22 -> V_237 ;
}
if ( V_476 ) {
V_478 = & V_477 [ F_214 ] ;
* V_476 = ( V_422 -> V_106 == V_169 &&
strncmp ( V_478 , F_215 ,
F_216 ) == 0 ) ;
}
F_81 ( V_477 ) ;
return 0 ;
V_479:
F_81 ( V_477 ) ;
return V_21 ;
}
static void F_219 ( struct V_1 * V_22 ,
struct V_73 * V_30 , T_1 * V_72 )
{
unsigned long V_78 ;
int V_21 , V_184 ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
V_21 = F_84 ( V_30 , V_22 -> V_30 , V_22 -> V_162 , & V_184 ) ;
if ( ( V_21 == F_87 || V_21 == F_88 ) &&
V_184 >= 0 && V_184 < V_22 -> V_162 ) {
V_30 -> V_482 = V_22 -> V_30 [ V_184 ] -> V_482 ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_98 , V_78 ) ;
V_30 -> V_482 =
F_212 ( V_22 , V_72 ) ;
if ( V_30 -> V_482 < 0 )
V_30 -> V_482 = 0 ;
}
}
static void F_220 ( struct V_1 * V_22 ,
T_1 * V_483 , struct V_73 * V_42 )
{
T_4 V_86 = F_142 ( V_483 ) ;
if ( ! F_31 ( V_483 ) ) {
if ( F_63 ( V_483 ) )
F_206 ( V_42 ,
V_484 , 0 , V_86 & 0x3fff ) ;
else
F_206 ( V_42 ,
V_251 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_167 ) {
F_206 ( V_42 ,
V_485 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_206 ( V_42 , V_486 ,
0 , V_86 & 0x3fff ) ;
}
static int F_221 ( struct V_1 * V_22 ,
struct V_8 * V_487 , unsigned char * V_72 )
{
struct V_139 * V_285 =
& V_22 -> V_137 [ V_487 -> V_133 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_187 == F_131 ( V_285 -> V_488 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 0 ;
}
static int F_222 ( struct V_1 * V_22 , int V_489 ,
int V_68 , int V_445 , int V_490 )
{
int V_491 = V_445 + ( V_489 == 0 ) ;
if ( V_68 == V_489 )
return 0 ;
if ( V_68 < V_491 )
return 0 ;
if ( ( V_68 - V_445 - ( V_489 == 0 ) ) < V_490 )
return 0 ;
return 1 ;
}
static int F_223 ( struct V_1 * V_22 ,
struct V_431 * V_444 , T_4 * V_445 ,
struct V_462 * V_492 , T_4 * V_493 )
{
if ( F_194 ( V_22 , V_444 , sizeof( * V_444 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
return - 1 ;
}
* V_445 = F_224 ( * ( ( V_494 * ) V_444 -> V_447 ) ) / 24 ;
if ( * V_445 > V_495 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_151 ,
V_495 , * V_445 - V_495 ) ;
* V_445 = V_495 ;
}
if ( F_205 ( V_22 , V_492 , sizeof( * V_492 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_152 ) ;
return - 1 ;
}
* V_493 = F_224 ( * ( ( V_494 * ) V_492 -> V_447 ) ) / 8 ;
if ( * V_493 > V_496 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_153
L_154 , V_496 ,
* V_493 - V_496 ) ;
* V_493 = V_496 ;
}
if ( * V_493 + * V_445 > V_495 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_155
L_154 , V_495 ,
* V_445 + * V_493 - V_495 ) ;
* V_493 = V_495 - * V_445 ;
}
return 0 ;
}
static T_1 * F_225 ( struct V_1 * V_22 , int V_489 ,
int V_68 , int V_445 , int V_493 ,
struct V_431 * V_497 ,
struct V_462 * V_498 )
{
int V_491 = V_445 + ( V_489 == 0 ) ;
int V_499 = V_445 + V_493 + ( V_489 == 0 ) ;
if ( V_68 == V_489 )
return V_158 ;
if ( V_68 < V_491 )
return & V_497 -> V_349 [ V_68 -
( V_489 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_499 )
return & V_498 -> V_349 [ V_68 - V_445 -
( V_489 == 0 ) ] [ 0 ] ;
F_179 () ;
return NULL ;
}
static void F_226 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_431 * V_432 , int V_433 ,
struct V_429 * V_437 )
{
int V_21 ;
struct V_438 * V_439 = & V_432 -> V_349 [ V_433 ] ;
V_30 -> V_187 = V_439 -> V_187 ;
if ( ( V_439 -> V_500 & 0x08 ) && V_30 -> V_187 )
V_30 -> V_188 = 1 ;
memset ( V_437 , 0 , sizeof( * V_437 ) ) ;
V_21 = F_189 ( V_22 , & V_439 -> V_86 [ 0 ] ,
F_191 ( & V_439 -> V_86 [ 0 ] ) , V_437 ,
sizeof( * V_437 ) ) ;
if ( ! V_21 )
#define F_227 2
#define F_228 7
V_30 -> V_190 =
F_97 ( V_437 -> V_501 ) -
F_227 ;
else
V_30 -> V_190 = F_228 ;
}
static void F_229 ( struct V_73 * V_422 ,
struct V_431 * V_432 , int V_433 ,
struct V_429 * V_437 )
{
struct V_438 * V_439 = & V_432 -> V_349 [ V_433 ] ;
if ( ( V_439 -> V_500 & 0x08 ) && V_422 -> V_187 )
V_422 -> V_188 = 1 ;
memcpy ( & V_422 -> V_100 ,
& V_437 -> V_442 ,
sizeof( V_422 -> V_100 ) ) ;
memcpy ( & V_422 -> V_101 ,
& V_437 -> V_502 ,
sizeof( V_422 -> V_101 ) ) ;
memcpy ( & V_422 -> V_93 ,
& V_437 -> V_503 ,
sizeof( V_422 -> V_93 ) ) ;
memcpy ( & V_422 -> V_97 ,
& V_437 -> V_504 ,
sizeof( V_422 -> V_97 ) ) ;
memcpy ( & V_422 -> V_94 ,
& V_437 -> V_505 ,
sizeof( V_422 -> V_94 ) ) ;
}
static int F_230 ( struct V_1 * V_22 ,
struct V_427 * V_506 ,
T_4 * V_507 )
{
int V_21 ;
if ( ! V_506 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_156 ,
V_204 ) ;
return - V_261 ;
}
memset ( V_506 , 0 , sizeof( * V_506 ) ) ;
V_21 = F_188 ( V_22 , V_506 , sizeof( * V_506 ) ) ;
if ( ! V_21 )
if ( V_506 -> V_508 < 256 )
* V_507 = V_506 -> V_508 ;
else
* V_507 = F_97 (
V_506 -> V_509 ) ;
else
* V_507 = - 1 ;
return V_21 ;
}
static void F_231 ( struct V_1 * V_22 )
{
struct V_431 * V_497 = NULL ;
struct V_462 * V_498 = NULL ;
struct V_429 * V_437 = NULL ;
struct V_427 * V_506 = NULL ;
T_4 V_445 = 0 ;
T_4 V_493 = 0 ;
T_4 V_490 = 0 ;
T_4 V_510 = 0 ;
struct V_73 * * V_511 , * V_422 , * V_512 ;
int V_513 = 0 ;
int V_68 , V_514 , V_515 ;
int V_489 ;
bool V_74 ;
F_66 ( V_516 , V_517 ) ;
V_511 = F_115 ( sizeof( * V_511 ) * V_161 , V_203 ) ;
V_497 = F_115 ( sizeof( * V_497 ) , V_203 ) ;
V_498 = F_115 ( sizeof( * V_498 ) , V_203 ) ;
V_512 = F_115 ( sizeof( * V_512 ) , V_203 ) ;
V_437 = F_115 ( sizeof( * V_437 ) , V_203 ) ;
V_506 = F_115 ( sizeof( * V_506 ) , V_203 ) ;
if ( ! V_511 || ! V_497 || ! V_498 ||
! V_512 || ! V_437 || ! V_506 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_157 ) ;
goto V_394;
}
memset ( V_516 , 0 , sizeof( V_516 ) ) ;
V_22 -> V_249 = 0 ;
if ( F_223 ( V_22 , V_497 , & V_445 ,
V_498 , & V_493 ) ) {
V_22 -> V_249 = 1 ;
goto V_394;
}
if ( F_230 ( V_22 , V_506 , & V_490 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_158 ,
V_204 ) ;
}
V_515 = V_445 + V_493 + V_517 + 1 ;
for ( V_68 = 0 ; V_68 < V_515 ; V_68 ++ ) {
if ( V_68 >= V_161 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_159
L_160 , V_161 ,
V_515 - V_161 ) ;
break;
}
V_511 [ V_68 ] = F_115 ( sizeof( * V_511 [ V_68 ] ) , V_203 ) ;
if ( ! V_511 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_161 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_249 = 1 ;
goto V_394;
}
V_510 ++ ;
}
if ( F_64 ( V_22 ) )
V_489 = 0 ;
else
V_489 = V_445 + V_493 ;
V_514 = 0 ;
for ( V_68 = 0 ; V_68 < V_445 + V_493 + 1 ; V_68 ++ ) {
T_1 * V_483 , V_518 = 0 ;
int V_21 = 0 ;
int V_519 = V_68 - ( V_489 == 0 ) ;
V_74 = V_68 < V_445 + ( V_489 == 0 ) ;
V_483 = F_225 ( V_22 , V_489 ,
V_68 , V_445 , V_493 , V_497 , V_498 ) ;
if ( F_192 ( V_483 ) && V_74 &&
( V_497 -> V_349 [ V_519 ] . V_520 != 0x06 ) &&
( V_497 -> V_349 [ V_519 ] . V_500 & 0x01 ) )
continue;
V_21 = F_213 ( V_22 , V_483 , V_512 ,
& V_518 ) ;
if ( V_21 == - V_261 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_162 ) ;
V_22 -> V_249 = 1 ;
goto V_394;
}
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_163 ) ;
continue;
}
V_512 -> V_167 =
F_222 ( V_22 , V_489 , V_68 ,
V_445 , V_490 ) ;
F_220 ( V_22 , V_483 , V_512 ) ;
F_219 ( V_22 , V_512 , V_483 ) ;
V_422 = V_511 [ V_513 ] ;
if ( ! V_22 -> V_521 ) {
if ( V_512 -> V_167 ) {
V_22 -> V_521 = 1 ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_164 ) ;
}
}
* V_422 = * V_512 ;
V_422 -> V_74 = V_74 ;
if ( F_192 ( V_483 ) && V_422 -> V_74 )
V_422 -> V_90 = 0 ;
else
V_422 -> V_90 = 1 ;
if ( V_422 -> V_74 && V_422 -> V_90 )
F_197 ( V_22 , V_483 , V_422 ) ;
switch ( V_422 -> V_106 ) {
case V_169 :
if ( V_518 )
V_513 ++ ;
break;
case V_108 :
case V_109 :
if ( V_422 -> V_74 ) {
V_422 -> V_91 = 0 ;
F_226 ( V_22 , V_422 ,
V_497 , V_519 , V_437 ) ;
F_229 ( V_422 ,
V_497 , V_519 , V_437 ) ;
}
V_513 ++ ;
break;
case V_170 :
case V_171 :
V_513 ++ ;
break;
case V_166 :
if ( ! V_422 -> V_167 )
F_190 ( V_22 , V_483 ,
V_497 , V_519 ,
V_422 ) ;
V_513 ++ ;
break;
case V_107 :
if ( ! F_63 ( V_483 ) )
break;
V_513 ++ ;
break;
default:
break;
}
if ( V_513 >= V_161 )
break;
}
if ( V_22 -> V_238 == NULL ) {
int V_21 = 0 ;
V_21 = F_232 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_165 , V_21 ) ;
goto V_394;
}
}
F_114 ( V_22 , V_511 , V_513 ) ;
V_394:
F_81 ( V_512 ) ;
for ( V_68 = 0 ; V_68 < V_510 ; V_68 ++ )
F_81 ( V_511 [ V_68 ] ) ;
F_81 ( V_511 ) ;
F_81 ( V_497 ) ;
F_81 ( V_498 ) ;
F_81 ( V_506 ) ;
F_81 ( V_437 ) ;
}
static void F_233 ( struct V_274 * V_522 ,
struct V_523 * V_269 )
{
T_5 V_374 = ( T_5 ) F_234 ( V_269 ) ;
unsigned int V_50 = F_235 ( V_269 ) ;
V_522 -> V_282 = F_134 ( V_374 ) ;
V_522 -> V_281 = F_139 ( V_50 ) ;
V_522 -> V_278 = 0 ;
}
static int F_236 ( struct V_1 * V_22 ,
struct V_8 * V_131 ,
struct V_283 * V_284 )
{
struct V_523 * V_269 ;
int V_524 , V_68 , V_525 , V_526 , V_527 ;
struct V_274 * V_528 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
V_524 = F_237 ( V_284 ) ;
if ( V_524 < 0 )
return V_524 ;
if ( ! V_524 )
goto V_529;
V_528 = V_131 -> V_276 ;
V_526 = V_524 > V_22 -> V_277 ;
V_525 = V_526 ? V_22 -> V_277 - 1 : V_524 ;
V_527 = F_159 ( V_284 ) - 1 ;
F_238 (cmd, sg, sg_limit, i) {
F_233 ( V_528 , V_269 ) ;
V_528 ++ ;
}
if ( V_526 ) {
V_528 = V_22 -> V_264 [ V_131 -> V_133 ] ;
V_525 = V_524 - V_525 ;
F_239 (sg, sg, sg_limit, i) {
F_233 ( V_528 , V_269 ) ;
V_528 ++ ;
}
}
( V_528 - 1 ) -> V_278 = F_139 ( V_376 ) ;
if ( V_524 + V_526 > V_22 -> V_530 )
V_22 -> V_530 = V_524 + V_526 ;
if ( V_526 ) {
V_131 -> V_124 . V_125 = V_22 -> V_277 ;
V_131 -> V_124 . V_280 = F_160 ( V_524 + 1 ) ;
if ( F_138 ( V_22 , V_131 ) ) {
F_158 ( V_284 ) ;
return - 1 ;
}
return 0 ;
}
V_529:
V_131 -> V_124 . V_125 = ( T_1 ) V_524 ;
V_131 -> V_124 . V_280 = F_160 ( V_524 ) ;
return 0 ;
}
static int F_240 ( T_1 * V_141 , int * V_531 )
{
int V_532 = 0 ;
T_4 V_533 ;
T_4 V_534 ;
switch ( V_141 [ 0 ] ) {
case V_535 :
case V_536 :
V_532 = 1 ;
case V_537 :
case V_538 :
if ( * V_531 == 6 ) {
V_533 = F_241 ( & V_141 [ 2 ] ) ;
V_534 = V_141 [ 4 ] ;
if ( V_534 == 0 )
V_534 = 256 ;
} else {
F_76 ( * V_531 != 12 ) ;
V_533 = F_195 ( & V_141 [ 2 ] ) ;
V_534 = F_195 ( & V_141 [ 6 ] ) ;
}
if ( V_534 > 0xffff )
return V_539 ;
V_141 [ 0 ] = V_532 ? V_540 : V_541 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_533 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_533 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_533 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_533 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_534 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_534 ) ;
V_141 [ 9 ] = 0 ;
* V_531 = 10 ;
break;
}
return 0 ;
}
static int F_242 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_531 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
unsigned int V_50 ;
unsigned int V_542 = 0 ;
struct V_523 * V_269 ;
T_5 V_374 ;
int V_524 , V_68 ;
struct V_274 * V_528 ;
T_4 V_543 = V_544 ;
if ( F_159 ( V_284 ) > V_22 -> V_545 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_539 ;
}
F_76 ( V_284 -> V_546 > V_547 ) ;
if ( F_240 ( V_141 , & V_531 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_539 ;
}
V_9 -> V_150 = V_151 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_548 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
V_524 = F_237 ( V_284 ) ;
if ( V_524 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_524 ;
}
if ( V_524 ) {
V_528 = V_131 -> V_276 ;
F_238 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_234 ( V_269 ) ;
V_50 = F_235 ( V_269 ) ;
V_542 += V_50 ;
V_528 -> V_282 = F_134 ( V_374 ) ;
V_528 -> V_281 = F_139 ( V_50 ) ;
V_528 -> V_278 = F_139 ( 0 ) ;
V_528 ++ ;
}
( -- V_528 ) -> V_278 = F_139 ( V_376 ) ;
switch ( V_284 -> V_549 ) {
case V_550 :
V_543 |= V_551 ;
break;
case V_552 :
V_543 |= V_553 ;
break;
case V_554 :
V_543 |= V_555 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_549 ) ;
F_179 () ;
break;
}
} else {
V_543 |= V_555 ;
}
V_9 -> V_124 . V_125 = V_524 ;
V_131 -> V_556 = F_160 ( V_187 & 0xFFFF ) ;
V_131 -> V_557 = F_139 ( V_542 ) ;
V_131 -> V_346 = F_160 ( V_558 |
( V_531 & V_347 ) ) ;
V_131 -> V_543 = F_139 ( V_543 ) ;
memcpy ( V_131 -> V_145 , V_141 , V_531 ) ;
memcpy ( V_131 -> V_351 , V_72 , 8 ) ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_243 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
V_9 -> V_236 = V_30 ;
return F_244 ( V_22 , V_9 , V_30 -> V_187 ,
V_284 -> V_559 , V_284 -> V_546 , V_30 -> V_72 , V_30 ) ;
}
static void F_245 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_139 * V_131 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
T_5 V_560 ;
if ( ! ( F_97 ( V_222 -> V_78 ) & V_419 ) )
return;
V_131 -> V_420 = V_222 -> V_420 ;
V_131 -> V_561 |= V_562 ;
switch ( V_284 -> V_559 [ 0 ] ) {
case V_535 :
case V_537 :
V_560 = F_241 ( & V_284 -> V_559 [ 2 ] ) ;
break;
case V_540 :
case V_541 :
case V_536 :
case V_538 :
V_560 = F_195 ( & V_284 -> V_559 [ 2 ] ) ;
break;
case V_563 :
case V_564 :
V_560 = F_196 ( & V_284 -> V_559 [ 2 ] ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_167 ,
V_204 , V_284 -> V_559 [ 0 ] ) ;
F_179 () ;
break;
}
if ( F_131 ( V_222 -> V_412 ) != 512 )
V_560 = V_560 *
F_131 ( V_222 -> V_412 ) / 512 ;
V_131 -> V_565 = F_139 ( V_560 ) ;
V_131 -> V_566 = F_139 ( V_560 >> 32 ) ;
}
static int F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_531 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_265 * V_528 ;
int V_524 , V_68 ;
struct V_523 * V_269 ;
T_5 V_374 ;
T_4 V_50 ;
T_4 V_542 = 0 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
if ( F_240 ( V_141 , & V_531 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_539 ;
}
V_9 -> V_150 = V_154 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_567 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_568 = V_569 ;
V_524 = F_237 ( V_284 ) ;
if ( V_524 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_524 ;
}
if ( V_524 ) {
V_528 = V_131 -> V_269 ;
if ( V_524 > V_22 -> V_545 ) {
V_374 = F_136 (
V_22 -> V_259 [ V_9 -> V_133 ] -> V_272 ) ;
V_528 -> V_272 = F_134 ( V_374 ) ;
V_528 -> V_270 = 0 ;
V_528 -> V_570 [ 0 ] = 0 ;
V_528 -> V_570 [ 1 ] = 0 ;
V_528 -> V_570 [ 2 ] = 0 ;
V_528 -> V_341 = 0x80 ;
V_528 = V_22 -> V_259 [ V_9 -> V_133 ] ;
}
F_238 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_234 ( V_269 ) ;
V_50 = F_235 ( V_269 ) ;
V_542 += V_50 ;
V_528 -> V_272 = F_134 ( V_374 ) ;
V_528 -> V_270 = F_139 ( V_50 ) ;
V_528 -> V_570 [ 0 ] = 0 ;
V_528 -> V_570 [ 1 ] = 0 ;
V_528 -> V_570 [ 2 ] = 0 ;
V_528 -> V_341 = 0 ;
V_528 ++ ;
}
switch ( V_284 -> V_549 ) {
case V_550 :
V_131 -> V_561 &= ~ V_571 ;
V_131 -> V_561 |= V_572 ;
break;
case V_552 :
V_131 -> V_561 &= ~ V_571 ;
V_131 -> V_561 |= V_573 ;
break;
case V_554 :
V_131 -> V_561 &= ~ V_571 ;
V_131 -> V_561 |= V_574 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_549 ) ;
F_179 () ;
break;
}
} else {
V_131 -> V_561 &= ~ V_571 ;
V_131 -> V_561 |= V_574 ;
}
F_245 ( V_22 , V_9 , V_131 ) ;
V_131 -> V_488 = F_139 ( V_187 ) ;
V_131 -> V_575 = F_139 ( V_9 -> V_133 << V_576 ) ;
memcpy ( V_131 -> V_141 , V_141 , sizeof( V_131 -> V_141 ) ) ;
V_131 -> V_286 = F_139 ( V_542 ) ;
V_131 -> V_577 = F_134 ( V_9 -> V_122 +
F_247 ( struct V_139 , V_289 ) ) ;
V_131 -> V_578 = F_139 ( sizeof( V_131 -> V_289 ) ) ;
if ( V_524 > V_22 -> V_545 ) {
V_131 -> V_140 = 1 ;
V_131 -> V_269 [ 0 ] . V_270 = F_139 ( V_524 * sizeof( V_131 -> V_269 [ 0 ] ) ) ;
if ( F_130 ( V_22 , V_131 , V_9 ) ) {
F_46 ( & V_236 -> V_256 ) ;
F_158 ( V_284 ) ;
return - 1 ;
}
} else
V_131 -> V_140 = ( T_1 ) V_524 ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_244 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_531 ,
T_1 * V_72 , struct V_73 * V_236 )
{
if ( F_104 ( & V_236 -> V_256 ) >
V_236 -> V_190 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_539 ;
}
if ( V_22 -> V_63 & V_114 )
return F_242 ( V_22 , V_9 , V_187 ,
V_141 , V_531 , V_72 ,
V_236 ) ;
else
return F_246 ( V_22 , V_9 , V_187 ,
V_141 , V_531 , V_72 ,
V_236 ) ;
}
static void F_248 ( struct V_221 * V_222 ,
int V_189 , T_4 * V_579 , T_4 * V_580 )
{
if ( V_189 == 0 ) {
* V_579 %= F_97 ( V_222 -> V_227 ) ;
return;
}
do {
* V_580 = * V_579 /
F_97 ( V_222 -> V_227 ) ;
if ( V_189 == * V_580 )
continue;
if ( * V_580 < F_97 ( V_222 -> V_231 ) - 1 ) {
* V_579 += F_97 ( V_222 -> V_227 ) ;
( * V_580 ) ++ ;
} else {
* V_579 %= F_97 ( V_222 -> V_227 ) ;
* V_580 = 0 ;
}
} while ( V_189 != * V_580 );
}
static int F_249 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_532 = 0 ;
T_4 V_579 ;
T_5 V_560 , V_581 ;
T_4 V_534 ;
T_4 V_582 ;
T_5 V_583 , V_584 ;
T_4 V_585 , V_586 ;
T_4 V_587 , V_588 ;
T_5 V_589 , V_590 ;
T_4 V_591 ;
T_5 V_592 , V_593 ;
T_4 V_594 , V_595 ;
T_4 V_596 , V_597 ;
T_4 V_226 ;
T_4 V_598 ;
T_4 V_599 , V_600 , V_580 ;
T_4 V_601 ;
T_4 V_602 ;
T_5 V_603 ;
T_4 V_604 ;
T_1 V_141 [ 16 ] ;
T_1 V_531 ;
T_6 V_416 ;
#if V_605 == 32
T_5 V_606 ;
#endif
int V_189 ;
switch ( V_284 -> V_559 [ 0 ] ) {
case V_535 :
V_532 = 1 ;
case V_537 :
V_560 = F_241 ( & V_284 -> V_559 [ 2 ] ) ;
V_534 = V_284 -> V_559 [ 4 ] ;
if ( V_534 == 0 )
V_534 = 256 ;
break;
case V_540 :
V_532 = 1 ;
case V_541 :
V_560 =
( ( ( T_5 ) V_284 -> V_559 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_559 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_559 [ 4 ] ) << 8 ) |
V_284 -> V_559 [ 5 ] ;
V_534 =
( ( ( T_4 ) V_284 -> V_559 [ 7 ] ) << 8 ) |
V_284 -> V_559 [ 8 ] ;
break;
case V_536 :
V_532 = 1 ;
case V_538 :
V_560 =
( ( ( T_5 ) V_284 -> V_559 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_559 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_559 [ 4 ] ) << 8 ) |
V_284 -> V_559 [ 5 ] ;
V_534 =
( ( ( T_4 ) V_284 -> V_559 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_559 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_559 [ 8 ] ) << 8 ) |
V_284 -> V_559 [ 9 ] ;
break;
case V_563 :
V_532 = 1 ;
case V_564 :
V_560 =
( ( ( T_5 ) V_284 -> V_559 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_284 -> V_559 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_284 -> V_559 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_284 -> V_559 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_284 -> V_559 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_559 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_559 [ 8 ] ) << 8 ) |
V_284 -> V_559 [ 9 ] ;
V_534 =
( ( ( T_4 ) V_284 -> V_559 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_559 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_559 [ 12 ] ) << 8 ) |
V_284 -> V_559 [ 13 ] ;
break;
default:
return V_539 ;
}
V_581 = V_560 + V_534 - 1 ;
if ( V_532 && V_30 -> V_83 != 0 )
return V_539 ;
if ( V_581 >= F_136 ( V_222 -> V_413 ) ||
V_581 < V_560 )
return V_539 ;
V_582 = F_97 ( V_222 -> V_227 ) *
F_97 ( V_222 -> V_416 ) ;
V_416 = F_97 ( V_222 -> V_416 ) ;
#if V_605 == 32
V_606 = V_560 ;
( void ) F_250 ( V_606 , V_582 ) ;
V_583 = V_606 ;
V_606 = V_581 ;
( void ) F_250 ( V_606 , V_582 ) ;
V_584 = V_606 ;
V_585 = ( T_4 ) ( V_560 - ( V_583 * V_582 ) ) ;
V_586 = ( T_4 ) ( V_581 - ( V_584 * V_582 ) ) ;
V_606 = V_585 ;
( void ) F_250 ( V_606 , V_416 ) ;
V_587 = V_606 ;
V_606 = V_586 ;
( void ) F_250 ( V_606 , V_416 ) ;
V_588 = V_606 ;
#else
V_583 = V_560 / V_582 ;
V_584 = V_581 / V_582 ;
V_585 = ( T_4 ) ( V_560 - ( V_583 * V_582 ) ) ;
V_586 = ( T_4 ) ( V_581 - ( V_584 * V_582 ) ) ;
V_587 = V_585 / V_416 ;
V_588 = V_586 / V_416 ;
#endif
if ( ( V_583 != V_584 ) || ( V_587 != V_588 ) )
return V_539 ;
V_226 = F_97 ( V_222 -> V_227 ) +
F_97 ( V_222 -> V_228 ) ;
V_601 = ( ( T_4 ) ( V_583 >> V_222 -> V_415 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_579 = ( V_601 * V_226 ) + V_587 ;
switch ( V_30 -> V_83 ) {
case V_607 :
break;
case V_608 :
F_76 ( F_97 ( V_222 -> V_231 ) != 2 ) ;
if ( V_30 -> V_189 )
V_579 += F_97 ( V_222 -> V_227 ) ;
V_30 -> V_189 = ! V_30 -> V_189 ;
break;
case V_609 :
F_76 ( F_97 ( V_222 -> V_231 ) != 3 ) ;
V_189 = V_30 -> V_189 ;
F_248 ( V_222 , V_189 ,
& V_579 , & V_580 ) ;
V_189 =
( V_189 >=
F_97 ( V_222 -> V_231 ) - 1 )
? 0 : V_189 + 1 ;
V_30 -> V_189 = V_189 ;
break;
case V_610 :
case V_611 :
if ( F_97 ( V_222 -> V_231 ) <= 1 )
break;
V_591 =
F_97 ( V_222 -> V_416 ) *
F_97 ( V_222 -> V_227 ) ;
F_76 ( V_591 == 0 ) ;
V_598 = V_591 *
F_97 ( V_222 -> V_231 ) ;
#if V_605 == 32
V_606 = V_560 ;
V_599 = F_250 ( V_606 , V_598 ) ;
V_606 = V_599 ;
( void ) F_250 ( V_606 , V_591 ) ;
V_599 = V_606 ;
V_606 = V_581 ;
V_600 = F_250 ( V_606 , V_598 ) ;
V_606 = V_600 ;
( void ) F_250 ( V_606 , V_591 ) ;
V_600 = V_606 ;
#else
V_599 = ( V_560 % V_598 ) / V_591 ;
V_600 = ( V_581 % V_598 ) / V_591 ;
#endif
if ( V_599 != V_600 )
return V_539 ;
#if V_605 == 32
V_606 = V_560 ;
( void ) F_250 ( V_606 , V_598 ) ;
V_583 = V_592 = V_589 = V_606 ;
V_606 = V_581 ;
( void ) F_250 ( V_606 , V_598 ) ;
V_593 = V_590 = V_606 ;
#else
V_583 = V_592 = V_589 =
V_560 / V_598 ;
V_593 = V_590 = V_581 / V_598 ;
#endif
if ( V_592 != V_593 )
return V_539 ;
#if V_605 == 32
V_606 = V_560 ;
V_585 = F_250 ( V_606 , V_598 ) ;
V_606 = V_585 ;
V_585 = ( T_4 ) F_250 ( V_606 , V_591 ) ;
V_594 = V_585 ;
V_606 = V_581 ;
V_595 = F_250 ( V_606 , V_598 ) ;
V_606 = V_595 ;
V_595 = F_250 ( V_606 , V_591 ) ;
V_606 = V_594 ;
( void ) F_250 ( V_606 , V_222 -> V_416 ) ;
V_587 = V_596 = V_606 ;
V_606 = V_595 ;
( void ) F_250 ( V_606 , V_222 -> V_416 ) ;
V_597 = V_606 ;
#else
V_585 = V_594 =
( T_4 ) ( ( V_560 % V_598 ) %
V_591 ) ;
V_595 =
( T_4 ) ( ( V_581 % V_598 ) %
V_591 ) ;
V_587 = V_596 =
V_594 / F_97 ( V_222 -> V_416 ) ;
V_597 =
V_595 / F_97 ( V_222 -> V_416 ) ;
#endif
if ( V_596 != V_597 )
return V_539 ;
V_601 = ( ( T_4 ) ( V_583 >> V_222 -> V_415 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_579 = ( V_599 *
( F_97 ( V_222 -> V_230 ) * V_226 ) ) +
( V_601 * V_226 ) + V_587 ;
break;
default:
return V_539 ;
}
if ( F_45 ( V_579 >= V_234 ) )
return V_539 ;
V_9 -> V_236 = V_30 -> V_236 [ V_579 ] ;
if ( ! V_9 -> V_236 )
return V_539 ;
V_602 = V_224 [ V_579 ] . V_187 ;
V_603 = F_136 ( V_222 -> V_417 ) +
V_583 * F_97 ( V_222 -> V_416 ) +
( V_585 - V_587 *
F_97 ( V_222 -> V_416 ) ) ;
V_604 = V_534 ;
if ( V_222 -> V_414 ) {
V_603 <<= V_222 -> V_414 ;
V_604 <<= V_222 -> V_414 ;
}
F_76 ( V_604 > 0xffff ) ;
if ( V_603 > 0xffffffff ) {
V_141 [ 0 ] = V_532 ? V_563 : V_564 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_603 >> 56 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_603 >> 48 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_603 >> 40 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_603 >> 32 ) ;
V_141 [ 6 ] = ( T_1 ) ( V_603 >> 24 ) ;
V_141 [ 7 ] = ( T_1 ) ( V_603 >> 16 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_603 >> 8 ) ;
V_141 [ 9 ] = ( T_1 ) ( V_603 ) ;
V_141 [ 10 ] = ( T_1 ) ( V_604 >> 24 ) ;
V_141 [ 11 ] = ( T_1 ) ( V_604 >> 16 ) ;
V_141 [ 12 ] = ( T_1 ) ( V_604 >> 8 ) ;
V_141 [ 13 ] = ( T_1 ) ( V_604 ) ;
V_141 [ 14 ] = 0 ;
V_141 [ 15 ] = 0 ;
V_531 = 16 ;
} else {
V_141 [ 0 ] = V_532 ? V_540 : V_541 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_603 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_603 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_603 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_603 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_604 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_604 ) ;
V_141 [ 9 ] = 0 ;
V_531 = 10 ;
}
return F_244 ( V_22 , V_9 , V_602 , V_141 , V_531 ,
V_30 -> V_72 ,
V_30 -> V_236 [ V_579 ] ) ;
}
static int F_251 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char V_72 [] )
{
V_284 -> V_612 = ( unsigned char * ) V_9 ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_9 -> V_124 . V_128 = 0 ;
memcpy ( & V_9 -> V_124 . V_349 . V_350 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_124 . V_348 = F_134 ( ( V_9 -> V_133 << V_576 ) ) ;
V_9 -> V_144 . V_613 = 0 ;
F_76 ( V_284 -> V_546 > sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_345 = V_284 -> V_546 ;
memcpy ( V_9 -> V_144 . V_145 , V_284 -> V_559 , V_284 -> V_546 ) ;
switch ( V_284 -> V_549 ) {
case V_550 :
V_9 -> V_144 . V_614 =
F_252 ( V_393 , V_615 , V_616 ) ;
break;
case V_552 :
V_9 -> V_144 . V_614 =
F_252 ( V_393 , V_615 , V_617 ) ;
break;
case V_554 :
V_9 -> V_144 . V_614 =
F_252 ( V_393 , V_615 , V_618 ) ;
break;
case V_619 :
V_9 -> V_144 . V_614 =
F_252 ( V_393 , V_615 , V_620 ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_549 ) ;
F_179 () ;
break;
}
if ( F_236 ( V_22 , V_9 , V_284 ) < 0 ) {
F_147 ( V_22 , V_9 ) ;
return V_621 ;
}
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_253 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_622 , V_623 ;
memset ( V_9 , 0 , F_247 ( struct V_8 , V_240 ) ) ;
V_9 -> V_124 . V_348 = F_134 ( ( T_5 ) ( V_199 << V_576 ) ) ;
V_622 = V_22 -> V_624 + V_199 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_625 + V_199 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_623 = V_22 -> V_626
+ V_199 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_133 = V_199 ;
V_9 -> V_122 = ( T_4 ) V_622 ;
V_9 -> V_627 . V_282 = F_134 ( ( T_5 ) V_623 ) ;
V_9 -> V_627 . V_281 = F_139 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_254 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
F_253 ( V_22 , V_68 , V_9 ) ;
F_122 ( & V_9 -> V_240 , 0 ) ;
}
}
static inline void F_255 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_622 = V_22 -> V_624 + V_199 * sizeof( * V_9 ) ;
F_76 ( V_9 -> V_133 != V_199 ) ;
memset ( V_9 -> V_144 . V_145 , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_122 = ( T_4 ) V_622 ;
}
static int F_256 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
int V_21 = V_539 ;
V_284 -> V_612 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_91 ) {
F_253 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_249 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_621 ;
} else if ( V_30 -> V_188 ) {
F_253 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_243 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_621 ;
}
return V_21 ;
}
static void V_326 ( struct V_628 * V_325 )
{
struct V_283 * V_284 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_257 ( V_325 , struct V_8 , V_325 ) ;
V_284 = V_9 -> V_10 ;
V_30 = V_284 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_284 -> V_294 = V_316 << 16 ;
return F_149 ( V_9 -> V_22 , V_9 , V_284 ) ;
}
if ( V_9 -> V_13 )
return F_147 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_154 ( V_9 -> V_22 , V_9 , V_284 ) ;
if ( V_9 -> V_150 == V_154 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
int V_21 ;
if ( V_285 -> V_289 . V_290 ==
V_303 ) {
V_21 = F_256 ( V_22 , V_9 , V_284 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_621 ) {
V_284 -> V_294 = V_629 << 16 ;
return F_149 ( V_22 , V_9 , V_284 ) ;
}
}
}
F_255 ( V_9 -> V_22 , V_9 -> V_133 , V_9 ) ;
if ( F_251 ( V_9 -> V_22 , V_9 , V_284 , V_30 -> V_72 ) ) {
V_284 -> V_294 = V_629 << 16 ;
V_284 -> V_324 ( V_284 ) ;
}
}
static int F_258 ( struct V_6 * V_7 , struct V_283 * V_284 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_284 -> V_42 ) ;
F_76 ( V_284 -> V_630 -> V_348 < 0 ) ;
V_30 = V_284 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_284 -> V_294 = V_474 << 16 ;
V_284 -> V_324 ( V_284 ) ;
return 0 ;
}
if ( V_30 -> V_191 ) {
V_284 -> V_294 = V_316 << 16 ;
V_284 -> V_324 ( V_284 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_45 ( F_13 ( V_22 ) ) ) {
V_284 -> V_294 = V_316 << 16 ;
V_284 -> V_324 ( V_284 ) ;
return 0 ;
}
V_9 = F_259 ( V_22 , V_284 ) ;
if ( F_48 ( V_284 -> V_631 == 0 &&
V_284 -> V_630 -> V_150 == V_632 &&
V_22 -> V_56 ) ) {
V_21 = F_256 ( V_22 , V_9 , V_284 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_621 ) {
F_147 ( V_22 , V_9 ) ;
return V_621 ;
}
}
return F_251 ( V_22 , V_9 , V_284 , V_72 ) ;
}
static void F_260 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_633 , V_78 ) ;
V_22 -> V_634 = 1 ;
F_146 ( & V_22 -> V_635 ) ;
F_36 ( & V_22 -> V_633 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_260 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_633 , V_78 ) ;
if ( V_22 -> V_634 )
break;
F_36 ( & V_22 -> V_633 , V_78 ) ;
F_182 ( V_22 -> V_635 , V_22 -> V_634 ) ;
}
V_22 -> V_634 = 0 ;
F_36 ( & V_22 -> V_633 , V_78 ) ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_260 ( V_22 ) ;
F_231 ( V_22 ) ;
F_260 ( V_22 ) ;
}
static int F_261 ( struct V_2 * V_3 , int V_233 )
{
struct V_73 * V_220 = V_3 -> V_80 ;
if ( ! V_220 )
return - V_81 ;
if ( V_233 < 1 )
V_233 = 1 ;
else if ( V_233 > V_220 -> V_190 )
V_233 = V_220 -> V_190 ;
return F_124 ( V_3 , V_233 ) ;
}
static int F_262 ( struct V_6 * V_7 ,
unsigned long V_636 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_637 ;
F_35 ( & V_22 -> V_633 , V_78 ) ;
V_637 = V_22 -> V_634 ;
F_36 ( & V_22 -> V_633 , V_78 ) ;
return V_637 ;
}
static int F_263 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_264 ( & V_638 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_168 ) ;
return - V_261 ;
}
V_7 -> V_639 = 0 ;
V_7 -> V_640 = 0 ;
V_7 -> V_641 = - 1 ;
V_7 -> V_642 = 3 ;
V_7 -> V_643 = V_644 ;
V_7 -> V_645 = V_496 ;
V_7 -> V_646 = V_496 ;
V_7 -> V_258 = V_22 -> V_237 - V_647 ;
V_7 -> V_648 = V_7 -> V_258 ;
V_7 -> V_649 = V_22 -> V_262 ;
V_7 -> V_650 = V_651 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_652 = V_22 -> V_653 [ V_22 -> V_654 ] ;
V_7 -> V_655 = V_7 -> V_652 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_265 ( struct V_1 * V_22 )
{
int V_656 ;
V_656 = F_266 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_656 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_169 ) ;
return V_656 ;
}
F_267 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_268 ( struct V_283 * V_657 )
{
int V_658 = V_657 -> V_630 -> V_348 ;
if ( V_658 < 0 )
return V_658 ;
return V_658 += V_647 ;
}
static int F_269 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_659 [] ,
int V_113 )
{
int V_21 ;
( void ) F_177 ( V_9 , V_473 , V_22 ,
NULL , 0 , 0 , V_659 , V_393 ) ;
V_21 = F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_660 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_295 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_661 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_270 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_659 [] , int V_113 )
{
int V_21 ;
int V_48 = 0 ;
int V_662 = 1 ;
for ( V_48 = 0 ; V_48 < V_663 ; V_48 ++ ) {
F_108 ( 1000 * V_662 ) ;
V_21 = F_269 ( V_22 , V_9 , V_659 , V_113 ) ;
if ( ! V_21 )
break;
if ( V_662 < V_664 )
V_662 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_170 ,
V_662 ) ;
}
return V_21 ;
}
static int F_271 ( struct V_1 * V_22 ,
unsigned char V_659 [] ,
int V_113 )
{
int V_665 ;
int V_666 ;
int V_112 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
if ( V_113 == V_127 ) {
V_665 = 0 ;
V_666 = V_22 -> V_129 - 1 ;
} else {
V_665 = V_113 ;
V_666 = V_113 ;
}
for ( V_112 = V_665 ; V_112 <= V_666 ; V_112 ++ ) {
V_21 = F_270 ( V_22 , V_9 , V_659 , V_112 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_171 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_172 ) ;
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_272 ( struct V_283 * V_667 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_397 ;
char V_668 [ 48 ] ;
V_22 = F_1 ( V_667 -> V_42 ) ;
if ( V_22 == NULL )
return V_669 ;
if ( F_13 ( V_22 ) )
return V_669 ;
V_30 = V_667 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_173 , V_204 ) ;
return V_669 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_668 , sizeof( V_668 ) ,
L_174 ,
F_268 ( V_667 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_668 ) ;
return V_669 ;
}
if ( F_273 ( V_22 ) ) {
snprintf ( V_668 , sizeof( V_668 ) ,
L_175 ,
F_268 ( V_667 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_668 ) ;
return V_669 ;
}
if ( F_63 ( V_30 -> V_72 ) )
return V_670 ;
if ( F_31 ( V_30 -> V_72 ) )
V_397 = V_671 ;
else
V_397 = V_672 ;
sprintf ( V_668 , L_176 ,
V_397 == V_671 ? L_177 : L_178 ) ;
F_70 ( V_243 , V_22 , V_30 , V_668 ) ;
V_22 -> V_248 = 1 ;
V_21 = F_180 ( V_22 , V_30 , V_30 -> V_72 , V_397 ,
V_127 ) ;
sprintf ( V_668 , L_179 ,
V_397 == V_671 ? L_177 : L_178 ,
V_21 == 0 ? L_180 : L_181 ) ;
F_70 ( V_243 , V_22 , V_30 , V_668 ) ;
V_22 -> V_248 = 0 ;
return V_21 == 0 ? V_670 : V_669 ;
}
static void F_274 ( T_1 * V_348 )
{
T_1 V_673 [ 8 ] ;
memcpy ( V_673 , V_348 , 8 ) ;
V_348 [ 0 ] = V_673 [ 3 ] ;
V_348 [ 1 ] = V_673 [ 2 ] ;
V_348 [ 2 ] = V_673 [ 1 ] ;
V_348 [ 3 ] = V_673 [ 0 ] ;
V_348 [ 4 ] = V_673 [ 7 ] ;
V_348 [ 5 ] = V_673 [ 6 ] ;
V_348 [ 6 ] = V_673 [ 5 ] ;
V_348 [ 7 ] = V_673 [ 4 ] ;
}
static void F_275 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_674 , T_7 * V_675 )
{
T_5 V_348 ;
if ( V_9 -> V_150 == V_151 ) {
struct V_130 * V_676 = (struct V_130 * )
& V_22 -> V_132 [ V_9 -> V_133 ] ;
V_348 = F_136 ( V_676 -> V_348 ) ;
* V_675 = F_139 ( V_348 >> 32 ) ;
* V_674 = F_139 ( V_348 ) ;
return;
}
if ( V_9 -> V_150 == V_154 ) {
struct V_139 * V_677 = (struct V_139 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
memset ( V_675 , 0 , sizeof( * V_675 ) ) ;
* V_674 = V_677 -> V_575 ;
return;
}
V_348 = F_136 ( V_9 -> V_124 . V_348 ) ;
* V_675 = F_139 ( V_348 >> 32 ) ;
* V_674 = F_139 ( V_348 ) ;
}
static int F_276 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
T_7 V_675 , V_674 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_475 , V_22 , & abort -> V_124 . V_348 ,
0 , 0 , V_72 , V_398 ) ;
if ( V_22 -> V_71 )
F_274 ( & V_9 -> V_144 . V_145 [ 4 ] ) ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_275 ( V_22 , abort , & V_674 , & V_675 ) ;
F_277 ( & V_22 -> V_29 -> V_30 , L_182 ,
V_204 , V_675 , V_674 ) ;
V_338 = V_9 -> V_24 ;
switch ( V_338 -> V_36 ) {
case V_660 :
break;
case V_368 :
V_21 = F_156 ( V_22 , V_9 ) ;
break;
case V_367 :
V_21 = - 1 ;
break;
default:
F_277 ( & V_22 -> V_29 -> V_30 , L_183 ,
V_204 , V_675 , V_674 ) ;
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_106 ( V_22 , V_9 ) ;
F_277 ( & V_22 -> V_29 -> V_30 , L_184 ,
V_204 , V_675 , V_674 ) ;
return V_21 ;
}
static void F_278 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_678 , int V_113 )
{
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_400 = (struct V_136 * ) V_285 ;
struct V_139 * V_679 =
& V_22 -> V_137 [ V_678 -> V_133 ] ;
struct V_283 * V_657 = V_678 -> V_10 ;
struct V_73 * V_30 = V_657 -> V_42 -> V_80 ;
F_279 ( sizeof( struct V_136 ) >
sizeof( struct V_139 ) ) ;
F_76 ( F_247 ( struct V_139 , V_289 ) <
F_247 ( struct V_136 , V_680 ) +
sizeof( V_400 -> V_680 ) ) ;
V_9 -> V_150 = V_156 ;
V_9 -> V_10 = V_681 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_567 +
( V_9 -> V_133 * sizeof( struct V_139 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_400 , 0 , sizeof( * V_285 ) ) ;
V_400 -> V_682 = V_683 ;
V_400 -> V_113 = V_113 ;
V_400 -> V_684 = V_685 ;
V_400 -> V_402 = F_139 ( V_30 -> V_187 ) ;
memset ( V_400 -> V_686 , 0 , sizeof( V_400 -> V_686 ) ) ;
V_400 -> V_348 = F_134 ( V_9 -> V_133 << V_576 ) ;
V_400 -> V_687 = F_134 ( F_131 ( V_679 -> V_575 ) ) ;
V_400 -> V_688 = F_134 ( V_9 -> V_122 +
F_247 ( struct V_139 , V_289 ) ) ;
V_400 -> V_680 = F_139 ( sizeof( V_285 -> V_289 ) ) ;
}
static int F_280 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_283 * V_657 ;
struct V_73 * V_30 ;
unsigned char V_689 [ 8 ] ;
unsigned char * V_690 = & V_689 [ 0 ] ;
V_657 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_657 -> V_42 -> V_80 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_185 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_186 ,
V_22 -> V_59 -> V_102 , V_30 -> V_103 , V_30 -> V_104 , V_30 -> V_105 ,
L_187 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_91 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_188 ) ;
return - 1 ;
}
if ( ! F_221 ( V_22 , abort , V_690 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_189 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_690 [ 0 ] , V_690 [ 1 ] , V_690 [ 2 ] , V_690 [ 3 ] ,
V_690 [ 4 ] , V_690 [ 5 ] , V_690 [ 6 ] , V_690 [ 7 ] ) ;
V_21 = F_180 ( V_22 , V_30 , V_690 , V_691 , V_113 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_690 [ 0 ] , V_690 [ 1 ] , V_690 [ 2 ] , V_690 [ 3 ] ,
V_690 [ 4 ] , V_690 [ 5 ] , V_690 [ 6 ] , V_690 [ 7 ] ) ;
return V_21 ;
}
if ( F_271 ( V_22 , V_690 , V_113 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_690 [ 0 ] , V_690 [ 1 ] , V_690 [ 2 ] , V_690 [ 3 ] ,
V_690 [ 4 ] , V_690 [ 5 ] , V_690 [ 6 ] , V_690 [ 7 ] ) ;
return - 1 ;
}
F_95 ( & V_22 -> V_29 -> V_30 ,
L_193 ,
V_690 [ 0 ] , V_690 [ 1 ] , V_690 [ 2 ] , V_690 [ 3 ] ,
V_690 [ 4 ] , V_690 [ 5 ] , V_690 [ 6 ] , V_690 [ 7 ] ) ;
return V_21 ;
}
static int F_281 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
T_7 V_674 , V_675 ;
struct V_73 * V_30 ;
struct V_139 * V_285 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 -> V_91 && ! V_30 -> V_188 )
return - 1 ;
V_9 = F_176 ( V_22 ) ;
F_278 ( V_9 , V_22 , abort , V_113 ) ;
V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_275 ( V_22 , abort , & V_674 , & V_675 ) ;
F_277 ( & V_22 -> V_29 -> V_30 ,
L_194 ,
V_204 , V_675 , V_674 ) ;
F_277 ( & V_22 -> V_29 -> V_30 ,
L_195 ,
V_204 , V_675 , V_674 , V_285 -> V_289 . V_290 ) ;
switch ( V_285 -> V_289 . V_290 ) {
case V_317 :
case V_318 :
V_21 = 0 ;
break;
case V_319 :
case V_305 :
case V_320 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_196 ,
V_204 , V_675 , V_674 ,
V_285 -> V_289 . V_290 ) ;
V_21 = - 1 ;
}
F_106 ( V_22 , V_9 ) ;
F_277 ( & V_22 -> V_29 -> V_30 , L_184 , V_204 ,
V_675 , V_674 ) ;
return V_21 ;
}
static int F_282 ( struct V_1 * V_22 ,
struct V_73 * V_30 , struct V_8 * abort , int V_113 )
{
if ( abort -> V_150 == V_154 ) {
if ( ( V_692 & V_22 -> V_693 ) ||
V_30 -> V_74 )
return F_281 ( V_22 , abort ,
V_113 ) ;
else
return F_280 ( V_22 ,
V_30 -> V_72 ,
abort , V_113 ) ;
}
return F_276 ( V_22 , V_30 -> V_72 , abort , V_113 ) ;
}
static int F_283 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_150 == V_154 )
return V_22 -> V_137 [ V_9 -> V_133 ] . V_113 ;
return V_9 -> V_124 . V_128 ;
}
static inline int F_284 ( struct V_1 * V_22 )
{
#define F_285 5000
return ! F_286 ( V_22 -> V_694 ,
F_287 ( & V_22 -> V_695 ) >= 0 ,
F_167 ( F_285 ) ) ;
}
static int F_288 ( struct V_283 * V_696 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_283 * V_697 ;
char V_668 [ 256 ] ;
int V_698 = 0 ;
T_7 V_675 , V_674 ;
int V_240 , V_113 ;
if ( V_696 == NULL )
return V_669 ;
if ( V_696 -> V_42 == NULL )
return V_669 ;
V_22 = F_1 ( V_696 -> V_42 ) ;
if ( V_22 == NULL )
return V_669 ;
V_30 = V_696 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_197 ,
V_668 ) ;
return V_669 ;
}
if ( F_13 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_198 ) ;
return V_669 ;
}
if ( F_273 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_199 ) ;
return V_669 ;
}
if ( ! ( V_699 & V_22 -> V_693 ) &&
! ( V_700 & V_22 -> V_693 ) )
return V_669 ;
memset ( V_668 , 0 , sizeof( V_668 ) ) ;
V_698 += sprintf ( V_668 + V_698 , L_200 ,
V_22 -> V_59 -> V_102 , V_696 -> V_42 -> V_701 ,
V_696 -> V_42 -> V_702 , V_696 -> V_42 -> V_105 ,
L_201 , V_696 ) ;
abort = (struct V_8 * ) V_696 -> V_612 ;
if ( abort == NULL ) {
return V_670 ;
}
V_240 = F_104 ( & abort -> V_240 ) ;
if ( V_240 == 1 ) {
F_106 ( V_22 , abort ) ;
return V_670 ;
}
if ( abort -> V_150 != V_154 &&
abort -> V_150 != V_151 && ! V_30 -> V_482 ) {
F_106 ( V_22 , abort ) ;
return V_669 ;
}
if ( abort -> V_10 != V_696 ) {
F_106 ( V_22 , abort ) ;
return V_670 ;
}
abort -> V_12 = true ;
F_275 ( V_22 , abort , & V_674 , & V_675 ) ;
V_113 = F_283 ( V_22 , abort ) ;
V_698 += sprintf ( V_668 + V_698 , L_202 , V_675 , V_674 ) ;
V_697 = abort -> V_10 ;
if ( V_697 != NULL )
V_698 += sprintf ( V_668 + V_698 ,
L_203 ,
V_697 -> V_546 , V_697 -> V_559 [ 0 ] , V_697 -> V_559 [ 1 ] ,
V_697 -> V_703 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_204 , V_668 ) ;
F_70 ( V_243 , V_22 , V_30 , L_201 ) ;
if ( F_284 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_205 ,
V_668 ) ;
F_106 ( V_22 , abort ) ;
return V_669 ;
}
V_21 = F_282 ( V_22 , V_30 , abort , V_113 ) ;
F_56 ( & V_22 -> V_695 ) ;
F_146 ( & V_22 -> V_694 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_206 , V_668 ) ;
F_70 ( V_243 , V_22 , V_30 ,
L_207 ) ;
F_106 ( V_22 , abort ) ;
return V_669 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_208 , V_668 ) ;
F_182 ( V_22 -> V_323 ,
abort -> V_10 != V_696 || F_13 ( V_22 ) ) ;
F_106 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_670 : V_669 ;
}
static struct V_8 * F_259 ( struct V_1 * V_22 ,
struct V_283 * V_657 )
{
int V_658 = F_268 ( V_657 ) ;
struct V_8 * V_9 = V_22 -> V_239 + V_658 ;
if ( V_658 < V_647 || V_658 >= V_22 -> V_237 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_209 ,
V_658 , V_647 , V_22 -> V_237 - 1 ) ;
F_179 () ;
}
F_56 ( & V_9 -> V_240 ) ;
if ( F_45 ( ! F_4 ( V_9 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_210 ,
V_658 ) ;
if ( V_9 -> V_10 != NULL )
F_289 ( V_9 -> V_10 ) ;
F_289 ( V_657 ) ;
}
F_255 ( V_22 , V_658 , V_9 ) ;
return V_9 ;
}
static void F_148 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_46 ( & V_9 -> V_240 ) ;
}
static struct V_8 * F_176 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_240 , V_68 ;
int V_704 = 0 ;
for (; ; ) {
V_68 = F_290 ( V_22 -> V_705 ,
V_647 ,
V_704 ) ;
if ( F_45 ( V_68 >= V_647 ) ) {
V_704 = 0 ;
continue;
}
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( F_45 ( V_240 > 1 ) ) {
F_106 ( V_22 , V_9 ) ;
V_704 = ( V_68 + 1 ) % V_647 ;
continue;
}
F_291 ( V_68 & ( V_605 - 1 ) ,
V_22 -> V_705 + ( V_68 / V_605 ) ) ;
break;
}
F_255 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_106 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_58 ( & V_9 -> V_240 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_239 ;
F_292 ( V_68 & ( V_605 - 1 ) ,
V_22 -> V_705 + ( V_68 / V_605 ) ) ;
}
}
static int F_293 ( struct V_2 * V_30 , int V_284 ,
void T_8 * V_706 )
{
T_9 T_8 * V_707 =
( T_9 T_8 * ) V_706 ;
T_10 V_708 ;
T_10 T_8 * V_709 = F_294 ( sizeof( V_708 ) ) ;
int V_710 ;
T_4 V_131 ;
memset ( & V_708 , 0 , sizeof( V_708 ) ) ;
V_710 = 0 ;
V_710 |= F_295 ( & V_708 . V_711 , & V_707 -> V_711 ,
sizeof( V_708 . V_711 ) ) ;
V_710 |= F_295 ( & V_708 . V_144 , & V_707 -> V_144 ,
sizeof( V_708 . V_144 ) ) ;
V_710 |= F_295 ( & V_708 . V_712 , & V_707 -> V_712 ,
sizeof( V_708 . V_712 ) ) ;
V_710 |= F_296 ( V_708 . V_713 , & V_707 -> V_713 ) ;
V_710 |= F_296 ( V_131 , & V_707 -> V_45 ) ;
V_708 . V_45 = F_297 ( V_131 ) ;
V_710 |= F_298 ( V_709 , & V_708 , sizeof( V_708 ) ) ;
if ( V_710 )
return - V_714 ;
V_710 = F_299 ( V_30 , V_715 , V_709 ) ;
if ( V_710 )
return V_710 ;
V_710 |= F_300 ( & V_707 -> V_712 , & V_709 -> V_712 ,
sizeof( V_707 -> V_712 ) ) ;
if ( V_710 )
return - V_714 ;
return V_710 ;
}
static int F_301 ( struct V_2 * V_30 ,
int V_284 , void T_8 * V_706 )
{
T_11 T_8 * V_707 =
( T_11 T_8 * ) V_706 ;
T_12 V_708 ;
T_12 T_8 * V_709 =
F_294 ( sizeof( V_708 ) ) ;
int V_710 ;
T_4 V_131 ;
memset ( & V_708 , 0 , sizeof( V_708 ) ) ;
V_710 = 0 ;
V_710 |= F_295 ( & V_708 . V_711 , & V_707 -> V_711 ,
sizeof( V_708 . V_711 ) ) ;
V_710 |= F_295 ( & V_708 . V_144 , & V_707 -> V_144 ,
sizeof( V_708 . V_144 ) ) ;
V_710 |= F_295 ( & V_708 . V_712 , & V_707 -> V_712 ,
sizeof( V_708 . V_712 ) ) ;
V_710 |= F_296 ( V_708 . V_713 , & V_707 -> V_713 ) ;
V_710 |= F_296 ( V_708 . V_716 , & V_707 -> V_716 ) ;
V_710 |= F_296 ( V_131 , & V_707 -> V_45 ) ;
V_708 . V_45 = F_297 ( V_131 ) ;
V_710 |= F_298 ( V_709 , & V_708 , sizeof( V_708 ) ) ;
if ( V_710 )
return - V_714 ;
V_710 = F_299 ( V_30 , V_717 , V_709 ) ;
if ( V_710 )
return V_710 ;
V_710 |= F_300 ( & V_707 -> V_712 , & V_709 -> V_712 ,
sizeof( V_707 -> V_712 ) ) ;
if ( V_710 )
return - V_714 ;
return V_710 ;
}
static int F_302 ( struct V_2 * V_30 , int V_284 , void T_8 * V_706 )
{
switch ( V_284 ) {
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
case V_731 :
case V_732 :
return F_299 ( V_30 , V_284 , V_706 ) ;
case V_733 :
return F_293 ( V_30 , V_284 , V_706 ) ;
case V_734 :
return F_301 ( V_30 , V_284 , V_706 ) ;
default:
return - V_735 ;
}
}
static int F_303 ( struct V_1 * V_22 , void T_8 * V_736 )
{
struct V_737 V_738 ;
if ( ! V_736 )
return - V_55 ;
V_738 . V_739 = F_304 ( V_22 -> V_29 -> V_103 ) ;
V_738 . V_103 = V_22 -> V_29 -> V_103 -> V_740 ;
V_738 . V_741 = V_22 -> V_29 -> V_742 ;
V_738 . V_67 = V_22 -> V_67 ;
if ( F_298 ( V_736 , & V_738 , sizeof( V_738 ) ) )
return - V_714 ;
return 0 ;
}
static int F_305 ( struct V_1 * V_22 , void T_8 * V_736 )
{
T_13 V_743 ;
unsigned char V_744 , V_745 , V_746 ;
int V_21 ;
V_21 = sscanf ( V_747 , L_211 ,
& V_744 , & V_745 , & V_746 ) ;
if ( V_21 != 3 ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_212
L_213 , V_747 ) ;
V_744 = 0 ;
V_745 = 0 ;
V_746 = 0 ;
}
V_743 = ( V_744 << 16 ) | ( V_745 << 8 ) | V_746 ;
if ( ! V_736 )
return - V_55 ;
if ( F_298 ( V_736 , & V_743 , sizeof( T_13 ) ) )
return - V_714 ;
return 0 ;
}
static int F_306 ( struct V_1 * V_22 , void T_8 * V_736 )
{
T_10 V_748 ;
struct V_8 * V_9 ;
char * V_749 = NULL ;
T_5 V_267 ;
int V_21 = 0 ;
if ( ! V_736 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_750 ;
if ( F_295 ( & V_748 , V_736 , sizeof( V_748 ) ) )
return - V_714 ;
if ( ( V_748 . V_713 < 1 ) &&
( V_748 . V_144 . Type . V_751 != V_618 ) ) {
return - V_55 ;
}
if ( V_748 . V_713 > 0 ) {
V_749 = F_92 ( V_748 . V_713 , V_203 ) ;
if ( V_749 == NULL )
return - V_261 ;
if ( V_748 . V_144 . Type . V_751 & V_616 ) {
if ( F_295 ( V_749 , V_748 . V_45 ,
V_748 . V_713 ) ) {
V_21 = - V_714 ;
goto V_752;
}
} else {
memset ( V_749 , 0 , V_748 . V_713 ) ;
}
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_681 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_748 . V_713 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_280 = F_160 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_280 = F_160 ( 0 ) ;
}
memcpy ( & V_9 -> V_124 . V_349 , & V_748 . V_711 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_748 . V_144 ,
sizeof( V_9 -> V_144 ) ) ;
if ( V_748 . V_713 > 0 ) {
V_267 = F_132 ( V_22 -> V_29 , V_749 ,
V_748 . V_713 , V_753 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 , ( V_372 ) V_267 ) ) {
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( 0 ) ;
V_21 = - V_261 ;
goto V_394;
}
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( V_748 . V_713 ) ;
V_9 -> V_276 [ 0 ] . V_278 = F_139 ( V_376 ) ;
}
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_396 ) ;
if ( V_748 . V_713 > 0 )
F_161 ( V_22 -> V_29 , V_9 , 1 , V_753 ) ;
F_307 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_387 ;
goto V_394;
}
memcpy ( & V_748 . V_712 , V_9 -> V_24 ,
sizeof( V_748 . V_712 ) ) ;
if ( F_298 ( V_736 , & V_748 , sizeof( V_748 ) ) ) {
V_21 = - V_714 ;
goto V_394;
}
if ( ( V_748 . V_144 . Type . V_751 & V_617 ) &&
V_748 . V_713 > 0 ) {
if ( F_298 ( V_748 . V_45 , V_749 , V_748 . V_713 ) ) {
V_21 = - V_714 ;
goto V_394;
}
}
V_394:
F_106 ( V_22 , V_9 ) ;
V_752:
F_81 ( V_749 ) ;
return V_21 ;
}
static int F_308 ( struct V_1 * V_22 , void T_8 * V_736 )
{
T_12 * V_754 ;
struct V_8 * V_9 ;
unsigned char * * V_749 = NULL ;
int * V_755 = NULL ;
T_5 V_267 ;
T_14 V_370 = 0 ;
int V_49 = 0 ;
T_4 V_756 ;
T_4 V_757 ;
T_14 T_8 * V_758 ;
if ( ! V_736 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_750 ;
V_754 = ( T_12 * )
F_92 ( sizeof( * V_754 ) , V_203 ) ;
if ( ! V_754 ) {
V_49 = - V_261 ;
goto V_759;
}
if ( F_295 ( V_754 , V_736 , sizeof( * V_754 ) ) ) {
V_49 = - V_714 ;
goto V_759;
}
if ( ( V_754 -> V_713 < 1 ) &&
( V_754 -> V_144 . Type . V_751 != V_618 ) ) {
V_49 = - V_55 ;
goto V_759;
}
if ( V_754 -> V_716 > V_760 ) {
V_49 = - V_55 ;
goto V_759;
}
if ( V_754 -> V_713 > V_754 -> V_716 * V_761 ) {
V_49 = - V_55 ;
goto V_759;
}
V_749 = F_115 ( V_761 * sizeof( char * ) , V_203 ) ;
if ( ! V_749 ) {
V_49 = - V_261 ;
goto V_759;
}
V_755 = F_92 ( V_761 * sizeof( int ) , V_203 ) ;
if ( ! V_755 ) {
V_49 = - V_261 ;
goto V_759;
}
V_756 = V_754 -> V_713 ;
V_758 = V_754 -> V_45 ;
while ( V_756 ) {
V_757 = ( V_756 > V_754 -> V_716 ) ? V_754 -> V_716 : V_756 ;
V_755 [ V_370 ] = V_757 ;
V_749 [ V_370 ] = F_92 ( V_757 , V_203 ) ;
if ( V_749 [ V_370 ] == NULL ) {
V_49 = - V_261 ;
goto V_759;
}
if ( V_754 -> V_144 . Type . V_751 & V_616 ) {
if ( F_295 ( V_749 [ V_370 ] , V_758 , V_757 ) ) {
V_49 = - V_714 ;
goto V_759;
}
} else
memset ( V_749 [ V_370 ] , 0 , V_757 ) ;
V_756 -= V_757 ;
V_758 += V_757 ;
V_370 ++ ;
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_681 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = ( T_1 ) V_370 ;
V_9 -> V_124 . V_280 = F_160 ( V_370 ) ;
memcpy ( & V_9 -> V_124 . V_349 , & V_754 -> V_711 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_754 -> V_144 , sizeof( V_9 -> V_144 ) ) ;
if ( V_754 -> V_713 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
V_267 = F_132 ( V_22 -> V_29 , V_749 [ V_68 ] ,
V_755 [ V_68 ] , V_753 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 ,
( V_372 ) V_267 ) ) {
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( 0 ) ;
F_161 ( V_22 -> V_29 , V_9 , V_68 ,
V_753 ) ;
V_49 = - V_261 ;
goto V_762;
}
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( V_755 [ V_68 ] ) ;
V_9 -> V_276 [ V_68 ] . V_278 = F_139 ( 0 ) ;
}
V_9 -> V_276 [ -- V_68 ] . V_278 = F_139 ( V_376 ) ;
}
V_49 = F_168 ( V_22 , V_9 , V_127 ,
V_396 ) ;
if ( V_370 )
F_161 ( V_22 -> V_29 , V_9 , V_370 , V_753 ) ;
F_307 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_387 ;
goto V_762;
}
memcpy ( & V_754 -> V_712 , V_9 -> V_24 , sizeof( V_754 -> V_712 ) ) ;
if ( F_298 ( V_736 , V_754 , sizeof( * V_754 ) ) ) {
V_49 = - V_714 ;
goto V_762;
}
if ( ( V_754 -> V_144 . Type . V_751 & V_617 ) && V_754 -> V_713 > 0 ) {
int V_68 ;
T_14 T_8 * V_763 = V_754 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
if ( F_298 ( V_763 , V_749 [ V_68 ] , V_755 [ V_68 ] ) ) {
V_49 = - V_714 ;
goto V_762;
}
V_763 += V_755 [ V_68 ] ;
}
}
V_49 = 0 ;
V_762:
F_106 ( V_22 , V_9 ) ;
V_759:
if ( V_749 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ )
F_81 ( V_749 [ V_68 ] ) ;
F_81 ( V_749 ) ;
}
F_81 ( V_755 ) ;
F_81 ( V_754 ) ;
return V_49 ;
}
static void F_307 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_295 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_299 ( struct V_2 * V_30 , int V_284 , void T_8 * V_706 )
{
struct V_1 * V_22 ;
void T_8 * V_736 = ( void T_8 * ) V_706 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_284 ) {
case V_728 :
case V_729 :
case V_730 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_718 :
return F_303 ( V_22 , V_736 ) ;
case V_726 :
return F_305 ( V_22 , V_736 ) ;
case V_715 :
if ( F_287 ( & V_22 -> V_764 ) < 0 )
return - V_765 ;
V_21 = F_306 ( V_22 , V_736 ) ;
F_56 ( & V_22 -> V_764 ) ;
return V_21 ;
case V_717 :
if ( F_287 ( & V_22 -> V_764 ) < 0 )
return - V_765 ;
V_21 = F_308 ( V_22 , V_736 ) ;
F_56 ( & V_22 -> V_764 ) ;
return V_21 ;
default:
return - V_766 ;
}
}
static void F_309 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_397 )
{
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_671 , V_22 , NULL , 0 , 0 ,
V_158 , V_398 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_397 ;
V_9 -> V_379 = NULL ;
F_61 ( V_22 , V_9 ) ;
return;
}
static int F_177 ( struct V_8 * V_9 , T_1 V_284 , struct V_1 * V_22 ,
void * V_749 , T_3 V_466 , T_6 V_767 , unsigned char * V_72 ,
int V_150 )
{
int V_768 = V_618 ;
T_5 V_348 ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_681 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_749 != NULL && V_466 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_280 = F_160 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_280 = F_160 ( 0 ) ;
}
memcpy ( V_9 -> V_124 . V_349 . V_350 , V_72 , 8 ) ;
if ( V_150 == V_393 ) {
switch ( V_284 ) {
case V_392 :
if ( V_767 & V_405 ) {
V_9 -> V_144 . V_145 [ 1 ] = 0x01 ;
V_9 -> V_144 . V_145 [ 2 ] = ( V_767 & 0xff ) ;
}
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_392 ;
V_9 -> V_144 . V_145 [ 4 ] = V_466 & 0xFF ;
break;
case V_460 :
case V_461 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_466 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_466 & 0xFF ;
break;
case V_769 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 6 ] = V_769 ;
break;
case V_771 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 ,
V_615 , V_616 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_771 ;
break;
case V_772 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 ,
V_615 , V_616 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_773 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = V_466 & 0xFF ;
break;
case V_473 :
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_618 ) ;
V_9 -> V_144 . V_613 = 0 ;
break;
case V_423 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_774 ;
V_9 -> V_144 . V_145 [ 1 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_466 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_466 & 0xFF ;
break;
case V_775 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 6 ] = V_775 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
break;
case V_430 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 6 ] = V_430 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_426 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 6 ] = V_426 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_440 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 6 ] = V_440 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_428 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_617 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_770 ;
V_9 -> V_144 . V_145 [ 1 ] = 0 ;
V_9 -> V_144 . V_145 [ 2 ] = 0 ;
V_9 -> V_144 . V_145 [ 3 ] = 0 ;
V_9 -> V_144 . V_145 [ 4 ] = 0 ;
V_9 -> V_144 . V_145 [ 5 ] = 0 ;
V_9 -> V_144 . V_145 [ 6 ] = V_428 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
V_9 -> V_144 . V_145 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_214 , V_284 ) ;
F_179 () ;
return - 1 ;
}
} else if ( V_150 == V_398 ) {
switch ( V_284 ) {
case V_672 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_618 ) ;
V_9 -> V_144 . V_613 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_776 ;
V_9 -> V_144 . V_145 [ 1 ] = V_777 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_671 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 , V_615 , V_618 ) ;
V_9 -> V_144 . V_613 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 1 ] = V_778 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_475 :
memcpy ( & V_348 , V_749 , sizeof( V_348 ) ) ;
F_277 ( & V_22 -> V_29 -> V_30 ,
L_215 ,
V_348 , V_9 -> V_124 . V_348 ) ;
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_614 =
F_252 ( V_150 ,
V_615 , V_616 ) ;
V_9 -> V_144 . V_613 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_779 ;
V_9 -> V_144 . V_145 [ 1 ] = V_780 ;
V_9 -> V_144 . V_145 [ 2 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_144 . V_145 [ 4 ] , & V_348 , sizeof( V_348 ) ) ;
V_9 -> V_144 . V_145 [ 12 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 13 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 14 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_216 ,
V_284 ) ;
F_179 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_217 , V_150 ) ;
F_179 () ;
}
switch ( F_310 ( V_9 -> V_144 . V_614 ) ) {
case V_617 :
V_768 = V_395 ;
break;
case V_616 :
V_768 = V_271 ;
break;
case V_618 :
V_768 = V_375 ;
break;
default:
V_768 = V_753 ;
}
if ( F_162 ( V_22 -> V_29 , V_9 , V_749 , V_466 , V_768 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_311 ( T_16 V_781 , T_16 V_466 )
{
T_16 V_782 = ( ( T_16 ) V_781 ) & V_783 ;
T_16 V_784 = ( ( T_16 ) V_781 ) - V_782 ;
void T_15 * V_785 = F_312 ( V_782 ,
V_784 + V_466 ) ;
return V_785 ? ( V_785 + V_784 ) : NULL ;
}
static inline unsigned long F_313 ( struct V_1 * V_22 , T_1 V_110 )
{
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
}
static inline bool F_314 ( struct V_1 * V_22 )
{
return V_22 -> V_115 . V_786 ( V_22 ) ;
}
static inline long F_315 ( struct V_1 * V_22 )
{
return ( V_22 -> V_115 . V_786 ( V_22 ) == 0 ) ||
( V_22 -> V_787 == 0 ) ;
}
static inline int F_316 ( struct V_1 * V_22 , T_4 V_788 ,
T_4 V_789 )
{
if ( F_45 ( V_788 >= V_22 -> V_237 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_218 , V_789 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_62 ( struct V_8 * V_9 )
{
F_57 ( V_9 -> V_22 , V_9 ) ;
if ( F_48 ( V_9 -> V_150 == V_151 || V_9 -> V_150 == V_340
|| V_9 -> V_150 == V_154 ) )
F_157 ( V_9 ) ;
else if ( V_9 -> V_150 == V_401 || V_9 -> V_150 == V_156 )
F_317 ( V_9 -> V_379 ) ;
}
static inline void F_318 ( struct V_1 * V_22 ,
T_4 V_789 )
{
T_4 V_788 ;
struct V_8 * V_9 ;
V_788 = V_789 >> V_576 ;
if ( ! F_316 ( V_22 , V_788 , V_789 ) ) {
V_9 = V_22 -> V_239 + V_788 ;
F_62 ( V_9 ) ;
}
}
static int F_319 ( struct V_1 * V_22 )
{
if ( F_48 ( ! V_790 ) )
return 0 ;
if ( F_48 ( V_22 -> V_787 ) )
return 0 ;
F_95 ( & V_22 -> V_29 -> V_30 , L_219
L_220 ) ;
return 1 ;
}
static struct V_1 * F_320 ( T_1 * V_791 )
{
return F_257 ( ( V_791 - * V_791 ) , struct V_1 , V_110 [ 0 ] ) ;
}
static T_17 F_321 ( int V_652 , void * V_791 )
{
struct V_1 * V_22 = F_320 ( V_791 ) ;
T_1 V_110 = * ( T_1 * ) V_791 ;
T_4 V_789 ;
if ( F_319 ( V_22 ) )
return V_792 ;
if ( F_315 ( V_22 ) )
return V_792 ;
V_22 -> V_793 = F_322 () ;
while ( F_314 ( V_22 ) ) {
V_789 = F_313 ( V_22 , V_110 ) ;
while ( V_789 != V_120 )
V_789 = F_44 ( V_22 , V_110 ) ;
}
return V_794 ;
}
static T_17 F_323 ( int V_652 , void * V_791 )
{
struct V_1 * V_22 = F_320 ( V_791 ) ;
T_4 V_789 ;
T_1 V_110 = * ( T_1 * ) V_791 ;
if ( F_319 ( V_22 ) )
return V_792 ;
V_22 -> V_793 = F_322 () ;
V_789 = F_313 ( V_22 , V_110 ) ;
while ( V_789 != V_120 )
V_789 = F_44 ( V_22 , V_110 ) ;
return V_794 ;
}
static T_17 F_324 ( int V_652 , void * V_791 )
{
struct V_1 * V_22 = F_320 ( ( T_1 * ) V_791 ) ;
T_4 V_789 ;
T_1 V_110 = * ( T_1 * ) V_791 ;
if ( F_315 ( V_22 ) )
return V_792 ;
V_22 -> V_793 = F_322 () ;
while ( F_314 ( V_22 ) ) {
V_789 = F_313 ( V_22 , V_110 ) ;
while ( V_789 != V_120 ) {
F_318 ( V_22 , V_789 ) ;
V_789 = F_44 ( V_22 , V_110 ) ;
}
}
return V_794 ;
}
static T_17 F_325 ( int V_652 , void * V_791 )
{
struct V_1 * V_22 = F_320 ( V_791 ) ;
T_4 V_789 ;
T_1 V_110 = * ( T_1 * ) V_791 ;
V_22 -> V_793 = F_322 () ;
V_789 = F_313 ( V_22 , V_110 ) ;
while ( V_789 != V_120 ) {
F_318 ( V_22 , V_789 ) ;
V_789 = F_44 ( V_22 , V_110 ) ;
}
return V_794 ;
}
static int F_326 ( struct V_369 * V_29 , unsigned char V_795 ,
unsigned char type )
{
struct V_796 {
struct V_797 V_798 ;
struct V_799 V_144 ;
struct V_800 V_801 ;
};
struct V_796 * V_284 ;
static const T_3 V_802 = sizeof( * V_284 ) +
sizeof( V_284 -> V_801 ) ;
V_372 V_803 ;
T_7 V_804 ;
T_4 V_348 ;
void T_15 * V_152 ;
int V_68 , V_710 ;
V_152 = F_327 ( V_29 , 0 ) ;
if ( V_152 == NULL )
return - V_261 ;
V_710 = F_328 ( V_29 , F_329 ( 32 ) ) ;
if ( V_710 ) {
F_330 ( V_152 ) ;
return V_710 ;
}
V_284 = F_331 ( V_29 , V_802 , & V_803 ) ;
if ( V_284 == NULL ) {
F_330 ( V_152 ) ;
return - V_261 ;
}
V_804 = F_139 ( V_803 ) ;
V_284 -> V_798 . V_128 = 0 ;
V_284 -> V_798 . V_125 = 0 ;
V_284 -> V_798 . V_280 = F_160 ( 0 ) ;
V_284 -> V_798 . V_348 = F_134 ( V_803 ) ;
memset ( & V_284 -> V_798 . V_349 . V_350 , 0 , 8 ) ;
V_284 -> V_144 . V_345 = 16 ;
V_284 -> V_144 . V_614 =
F_252 ( V_398 , V_805 , V_618 ) ;
V_284 -> V_144 . V_613 = 0 ;
V_284 -> V_144 . V_145 [ 0 ] = V_795 ;
V_284 -> V_144 . V_145 [ 1 ] = type ;
memset ( & V_284 -> V_144 . V_145 [ 2 ] , 0 , 14 ) ;
V_284 -> V_801 . V_282 =
F_134 ( ( F_131 ( V_804 ) + sizeof( * V_284 ) ) ) ;
V_284 -> V_801 . V_281 = F_139 ( sizeof( struct V_337 ) ) ;
F_60 ( F_131 ( V_804 ) , V_152 + V_153 ) ;
for ( V_68 = 0 ; V_68 < V_806 ; V_68 ++ ) {
V_348 = F_332 ( V_152 + V_807 ) ;
if ( ( V_348 & ~ V_808 ) == V_803 )
break;
F_108 ( V_809 ) ;
}
F_330 ( V_152 ) ;
if ( V_68 == V_806 ) {
F_74 ( & V_29 -> V_30 , L_221 ,
V_795 , type ) ;
return - V_382 ;
}
F_333 ( V_29 , V_802 , V_284 , V_803 ) ;
if ( V_348 & V_810 ) {
F_74 ( & V_29 -> V_30 , L_222 ,
V_795 , type ) ;
return - V_387 ;
}
F_95 ( & V_29 -> V_30 , L_223 ,
V_795 , type ) ;
return 0 ;
}
static int F_334 ( struct V_369 * V_29 ,
void T_15 * V_152 , T_4 V_811 )
{
if ( V_811 ) {
F_95 ( & V_29 -> V_30 , L_224 ) ;
F_60 ( V_811 , V_152 + V_812 ) ;
F_108 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_95 ( & V_29 -> V_30 , L_225 ) ;
V_21 = F_335 ( V_29 , V_813 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
V_21 = F_335 ( V_29 , V_814 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
}
return 0 ;
}
static void F_336 ( char * V_815 , int V_50 )
{
memset ( V_815 , 0 , V_50 ) ;
strncpy ( V_815 , V_41 L_226 V_747 , V_50 - 1 ) ;
}
static int F_337 ( struct V_816 T_15 * V_817 )
{
char * V_815 ;
int V_68 , V_466 = sizeof( V_817 -> V_815 ) ;
V_815 = F_92 ( V_466 , V_203 ) ;
if ( ! V_815 )
return - V_261 ;
F_336 ( V_815 , V_466 ) ;
for ( V_68 = 0 ; V_68 < V_466 ; V_68 ++ )
F_338 ( V_815 [ V_68 ] , & V_817 -> V_815 [ V_68 ] ) ;
F_81 ( V_815 ) ;
return 0 ;
}
static void F_339 ( struct V_816 T_15 * V_817 ,
unsigned char * V_818 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_817 -> V_815 ) ; V_68 ++ )
V_818 [ V_68 ] = F_340 ( & V_817 -> V_815 [ V_68 ] ) ;
}
static int F_341 ( struct V_816 T_15 * V_817 )
{
char * V_818 , * V_819 ;
int V_21 , V_466 = sizeof( V_817 -> V_815 ) ;
V_819 = F_92 ( 2 * V_466 , V_203 ) ;
if ( ! V_819 )
return - V_261 ;
V_818 = V_819 + V_466 ;
F_336 ( V_819 , V_466 ) ;
F_339 ( V_817 , V_818 ) ;
V_21 = ! memcmp ( V_818 , V_819 , V_466 ) ;
F_81 ( V_819 ) ;
return V_21 ;
}
static int F_342 ( struct V_369 * V_29 , T_4 V_67 )
{
T_5 V_820 ;
T_4 V_821 ;
T_5 V_822 ;
void T_15 * V_152 ;
unsigned long V_823 ;
T_4 V_824 ;
int V_21 ;
struct V_816 T_15 * V_817 ;
T_4 V_811 ;
T_6 V_825 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_227 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_826 ;
F_343 ( V_29 , 4 , & V_825 ) ;
F_344 ( V_29 ) ;
V_21 = F_345 ( V_29 , & V_823 ) ;
if ( V_21 )
return V_21 ;
V_152 = F_311 ( V_823 , 0x250 ) ;
if ( ! V_152 )
return - V_261 ;
V_21 = F_346 ( V_29 , V_152 , & V_821 ,
& V_822 , & V_820 ) ;
if ( V_21 )
goto V_827;
V_817 = F_311 ( F_347 ( V_29 ,
V_822 ) + V_820 , sizeof( * V_817 ) ) ;
if ( ! V_817 ) {
V_21 = - V_261 ;
goto V_827;
}
V_21 = F_337 ( V_817 ) ;
if ( V_21 )
goto V_828;
V_824 = F_332 ( & V_817 -> V_824 ) ;
V_811 = V_824 & V_829 ;
if ( V_811 ) {
V_811 = V_830 ;
} else {
V_811 = V_824 & V_831 ;
if ( V_811 ) {
F_9 ( & V_29 -> V_30 ,
L_228 ) ;
V_21 = - V_826 ;
goto V_828;
}
}
V_21 = F_334 ( V_29 , V_152 , V_811 ) ;
if ( V_21 )
goto V_828;
F_348 ( V_29 ) ;
F_349 ( V_29 , 4 , V_825 ) ;
F_108 ( V_832 ) ;
V_21 = F_350 ( V_29 , V_152 , V_833 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_229 ) ;
goto V_828;
}
V_21 = F_341 ( V_152 ) ;
if ( V_21 < 0 )
goto V_828;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_230
L_231 ) ;
V_21 = - V_826 ;
} else {
F_95 ( & V_29 -> V_30 , L_232 ) ;
}
V_828:
F_330 ( V_817 ) ;
V_827:
F_330 ( V_152 ) ;
return V_21 ;
}
static void F_351 ( struct V_42 * V_30 , struct V_816 T_15 * V_834 )
{
#ifdef F_352
int V_68 ;
char V_835 [ 17 ] ;
F_95 ( V_30 , L_233 ) ;
F_95 ( V_30 , L_234 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_835 [ V_68 ] = F_340 ( & ( V_834 -> V_836 [ V_68 ] ) ) ;
V_835 [ 4 ] = '\0' ;
F_95 ( V_30 , L_235 , V_835 ) ;
F_95 ( V_30 , L_236 , F_332 ( & ( V_834 -> V_837 ) ) ) ;
F_95 ( V_30 , L_237 ,
F_332 ( & ( V_834 -> V_838 ) ) ) ;
F_95 ( V_30 , L_238 ,
F_332 ( & ( V_834 -> V_839 ) ) ) ;
F_95 ( V_30 , L_239 ,
F_332 ( & ( V_834 -> V_840 . V_841 ) ) ) ;
F_95 ( V_30 , L_240 ,
F_332 ( & ( V_834 -> V_840 . V_842 ) ) ) ;
F_95 ( V_30 , L_241 ,
F_332 ( & ( V_834 -> V_840 . V_843 ) ) ) ;
F_95 ( V_30 , L_242 ,
F_332 ( & ( V_834 -> V_844 ) ) ) ;
F_95 ( V_30 , L_243 , F_332 ( & ( V_834 -> V_845 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_835 [ V_68 ] = F_340 ( & ( V_834 -> V_846 [ V_68 ] ) ) ;
V_835 [ 16 ] = '\0' ;
F_95 ( V_30 , L_244 , V_835 ) ;
F_95 ( V_30 , L_245 ,
F_332 ( & ( V_834 -> V_847 ) ) ) ;
#endif
}
static int F_353 ( struct V_369 * V_29 , unsigned long V_848 )
{
int V_68 , V_704 , V_849 , V_850 ;
if ( V_848 == V_851 )
return 0 ;
V_704 = 0 ;
for ( V_68 = 0 ; V_68 < V_852 ; V_68 ++ ) {
V_850 = F_354 ( V_29 , V_68 ) & V_853 ;
if ( V_850 == V_854 )
V_704 += 4 ;
else {
V_849 = F_354 ( V_29 , V_68 ) &
V_855 ;
switch ( V_849 ) {
case V_856 :
case V_857 :
V_704 += 4 ;
break;
case V_858 :
V_704 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_246 ) ;
return - 1 ;
break;
}
}
if ( V_704 == V_848 - V_851 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_355 ( struct V_1 * V_22 )
{
if ( V_22 -> V_126 ) {
if ( V_22 -> V_29 -> V_859 )
F_356 ( V_22 -> V_29 ) ;
V_22 -> V_126 = 0 ;
} else if ( V_22 -> V_860 ) {
if ( V_22 -> V_29 -> V_861 )
F_357 ( V_22 -> V_29 ) ;
V_22 -> V_860 = 0 ;
}
}
static void F_358 ( struct V_1 * V_22 )
{
#ifdef F_359
int V_710 , V_68 ;
struct V_862 V_863 [ V_864 ] ;
for ( V_68 = 0 ; V_68 < V_864 ; V_68 ++ ) {
V_863 [ V_68 ] . V_865 = 0 ;
V_863 [ V_68 ] . V_184 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_866;
if ( F_360 ( V_22 -> V_29 , V_867 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_247 ) ;
V_22 -> V_126 = V_864 ;
if ( V_22 -> V_126 > F_361 () )
V_22 -> V_126 = F_361 () ;
V_710 = F_362 ( V_22 -> V_29 , V_863 ,
1 , V_22 -> V_126 ) ;
if ( V_710 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_248 , V_710 ) ;
V_22 -> V_126 = 0 ;
goto V_868;
} else if ( V_710 < V_22 -> V_126 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_249
L_250 , V_710 ) ;
}
V_22 -> V_126 = V_710 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ )
V_22 -> V_653 [ V_68 ] = V_863 [ V_68 ] . V_865 ;
return;
}
V_868:
if ( F_360 ( V_22 -> V_29 , V_869 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_251 ) ;
if ( ! F_363 ( V_22 -> V_29 ) )
V_22 -> V_860 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_252 ) ;
}
V_866:
#endif
V_22 -> V_653 [ V_22 -> V_654 ] = V_22 -> V_29 -> V_652 ;
}
static int F_364 ( struct V_369 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_870 , V_871 ;
V_870 = V_29 -> V_872 ;
V_871 = V_29 -> V_873 ;
* V_67 = ( ( V_871 << 16 ) & 0xffff0000 ) |
V_870 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_874 ) ; V_68 ++ )
if ( * V_67 == V_874 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_870 != V_875 &&
V_870 != V_876 ) ||
! V_877 ) {
F_9 ( & V_29 -> V_30 , L_253
L_254 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_874 ) - 1 ;
}
static int F_345 ( struct V_369 * V_29 ,
unsigned long * V_878 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_852 ; V_68 ++ )
if ( F_354 ( V_29 , V_68 ) & V_879 ) {
* V_878 = F_347 ( V_29 , V_68 ) ;
F_277 ( & V_29 -> V_30 , L_255 ,
* V_878 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_256 ) ;
return - V_81 ;
}
static int F_350 ( struct V_369 * V_29 , void T_15 * V_152 ,
int V_880 )
{
int V_68 , V_881 ;
T_4 V_882 ;
if ( V_880 )
V_881 = V_883 ;
else
V_881 = V_884 ;
for ( V_68 = 0 ; V_68 < V_881 ; V_68 ++ ) {
V_882 = F_332 ( V_152 + V_885 ) ;
if ( V_880 ) {
if ( V_882 == V_886 )
return 0 ;
} else {
if ( V_882 != V_886 )
return 0 ;
}
F_108 ( V_887 ) ;
}
F_9 ( & V_29 -> V_30 , L_257 ) ;
return - V_81 ;
}
static int F_346 ( struct V_369 * V_29 , void T_15 * V_152 ,
T_4 * V_821 , T_5 * V_822 ,
T_5 * V_820 )
{
* V_821 = F_332 ( V_152 + V_888 ) ;
* V_820 = F_332 ( V_152 + V_889 ) ;
* V_821 &= ( T_4 ) 0x0000ffff ;
* V_822 = F_353 ( V_29 , * V_821 ) ;
if ( * V_822 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_258 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_365 ( struct V_1 * V_22 )
{
if ( V_22 -> V_890 ) {
F_330 ( V_22 -> V_890 ) ;
V_22 -> V_890 = NULL ;
}
if ( V_22 -> V_817 ) {
F_330 ( V_22 -> V_817 ) ;
V_22 -> V_817 = NULL ;
}
}
static int F_366 ( struct V_1 * V_22 )
{
T_5 V_820 ;
T_4 V_821 ;
T_5 V_822 ;
T_4 V_891 ;
int V_21 ;
V_21 = F_346 ( V_22 -> V_29 , V_22 -> V_152 , & V_821 ,
& V_822 , & V_820 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_817 = F_311 ( F_347 ( V_22 -> V_29 ,
V_822 ) + V_820 , sizeof( * V_22 -> V_817 ) ) ;
if ( ! V_22 -> V_817 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
return - V_261 ;
}
V_21 = F_337 ( V_22 -> V_817 ) ;
if ( V_21 )
return V_21 ;
V_891 = F_332 ( & V_22 -> V_817 -> V_892 ) ;
V_22 -> V_890 = F_311 ( F_347 ( V_22 -> V_29 ,
V_822 ) + V_820 + V_891 ,
sizeof( * V_22 -> V_890 ) ) ;
if ( ! V_22 -> V_890 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
F_365 ( V_22 ) ;
return - V_261 ;
}
return 0 ;
}
static void F_367 ( struct V_1 * V_22 )
{
#define F_368 16
F_279 ( F_368 <= V_647 ) ;
V_22 -> V_121 = F_332 ( & V_22 -> V_817 -> V_893 ) ;
if ( V_790 && V_22 -> V_121 > 32 )
V_22 -> V_121 = 32 ;
if ( V_22 -> V_121 < F_368 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_261 ,
V_22 -> V_121 ,
F_368 ) ;
V_22 -> V_121 = F_368 ;
}
}
static int F_369 ( struct V_1 * V_22 )
{
return V_22 -> V_262 > 512 ;
}
static void F_370 ( struct V_1 * V_22 )
{
F_367 ( V_22 ) ;
V_22 -> V_237 = V_22 -> V_121 ;
V_22 -> V_262 = F_332 ( & ( V_22 -> V_817 -> V_894 ) ) ;
V_22 -> V_480 = F_332 ( & ( V_22 -> V_817 -> V_824 ) ) ;
if ( F_369 ( V_22 ) ) {
V_22 -> V_277 = 32 ;
V_22 -> V_260 = V_22 -> V_262 - V_22 -> V_277 ;
V_22 -> V_262 -- ;
} else {
V_22 -> V_277 = 31 ;
V_22 -> V_262 = 31 ;
V_22 -> V_260 = 0 ;
}
V_22 -> V_693 = F_332 ( & ( V_22 -> V_817 -> V_693 ) ) ;
if ( ! ( V_699 & V_22 -> V_693 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_262 ) ;
if ( ! ( V_700 & V_22 -> V_693 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
if ( ! ( V_692 & V_22 -> V_693 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_264 ) ;
}
static inline bool F_371 ( struct V_1 * V_22 )
{
if ( ! F_372 ( V_22 -> V_817 -> V_836 , L_265 , 4 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_266 ) ;
return false ;
}
return true ;
}
static inline void F_373 ( struct V_1 * V_22 )
{
T_4 V_895 ;
V_895 = F_332 ( & ( V_22 -> V_817 -> V_895 ) ) ;
#ifdef F_374
V_895 |= V_896 ;
#endif
V_895 |= V_897 ;
F_60 ( V_895 , & ( V_22 -> V_817 -> V_895 ) ) ;
}
static inline void F_375 ( struct V_1 * V_22 )
{
T_4 V_898 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_898 = F_332 ( V_22 -> V_152 + V_899 ) ;
V_898 |= 0x8000 ;
F_60 ( V_898 , V_22 -> V_152 + V_899 ) ;
}
static int F_376 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_900 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_901 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_900 = F_332 ( V_22 -> V_152 + V_812 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_900 & V_902 ) )
goto V_903;
F_108 ( V_904 ) ;
}
return - V_81 ;
V_903:
return 0 ;
}
static int F_377 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_900 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_905 ; V_68 ++ ) {
if ( V_22 -> V_906 )
goto V_903;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_900 = F_332 ( V_22 -> V_152 + V_812 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_900 & V_907 ) )
goto V_903;
F_108 ( V_908 ) ;
}
return - V_81 ;
V_903:
return 0 ;
}
static int F_378 ( struct V_1 * V_22 )
{
T_4 V_909 ;
V_909 = F_332 ( & ( V_22 -> V_817 -> V_838 ) ) ;
if ( ! ( V_909 & V_910 ) )
return - V_826 ;
V_22 -> V_121 = F_332 ( & ( V_22 -> V_817 -> V_844 ) ) ;
F_60 ( V_911 , & ( V_22 -> V_817 -> V_840 . V_841 ) ) ;
F_60 ( 0 , & V_22 -> V_817 -> V_840 . V_912 ) ;
F_60 ( V_907 , V_22 -> V_152 + V_812 ) ;
if ( F_377 ( V_22 ) )
goto error;
F_351 ( & V_22 -> V_29 -> V_30 , V_22 -> V_817 ) ;
if ( ! ( F_332 ( & ( V_22 -> V_817 -> V_839 ) ) & V_911 ) )
goto error;
V_22 -> V_63 = V_911 ;
return 0 ;
error:
F_74 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
return - V_81 ;
}
static void F_379 ( struct V_1 * V_22 )
{
F_365 ( V_22 ) ;
F_330 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
F_355 ( V_22 ) ;
F_380 ( V_22 -> V_29 ) ;
F_381 ( V_22 -> V_29 ) ;
}
static int F_382 ( struct V_1 * V_22 )
{
int V_913 , V_710 ;
V_913 = F_364 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_913 < 0 )
return V_913 ;
V_22 -> V_914 = V_874 [ V_913 ] . V_914 ;
V_22 -> V_115 = * ( V_874 [ V_913 ] . V_115 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_383 ( V_22 -> V_29 , V_915 |
V_916 | V_917 ) ;
V_710 = F_384 ( V_22 -> V_29 ) ;
if ( V_710 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_268 ) ;
F_380 ( V_22 -> V_29 ) ;
return V_710 ;
}
V_710 = F_385 ( V_22 -> V_29 , V_41 ) ;
if ( V_710 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_269 ) ;
F_380 ( V_22 -> V_29 ) ;
return V_710 ;
}
F_386 ( V_22 -> V_29 ) ;
F_358 ( V_22 ) ;
V_710 = F_345 ( V_22 -> V_29 , & V_22 -> V_823 ) ;
if ( V_710 )
goto V_918;
V_22 -> V_152 = F_311 ( V_22 -> V_823 , 0x250 ) ;
if ( ! V_22 -> V_152 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_270 ) ;
V_710 = - V_261 ;
goto V_918;
}
V_710 = F_350 ( V_22 -> V_29 , V_22 -> V_152 , V_833 ) ;
if ( V_710 )
goto V_919;
V_710 = F_366 ( V_22 ) ;
if ( V_710 )
goto V_919;
F_370 ( V_22 ) ;
if ( ! F_371 ( V_22 ) ) {
V_710 = - V_81 ;
goto V_920;
}
F_373 ( V_22 ) ;
F_375 ( V_22 ) ;
V_710 = F_378 ( V_22 ) ;
if ( V_710 )
goto V_920;
return 0 ;
V_920:
F_365 ( V_22 ) ;
V_919:
F_330 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
V_918:
F_355 ( V_22 ) ;
F_380 ( V_22 -> V_29 ) ;
F_381 ( V_22 -> V_29 ) ;
return V_710 ;
}
static void F_387 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_388 64
V_22 -> V_61 = F_92 ( F_388 , V_203 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_175 ( V_22 , V_158 , 0 ,
V_22 -> V_61 , F_388 ) ;
if ( V_21 != 0 ) {
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_389 ( struct V_369 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_152 ;
if ( ! V_790 )
return 0 ;
V_21 = F_384 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_271 ) ;
return - V_81 ;
}
F_380 ( V_29 ) ;
F_108 ( 260 ) ;
V_21 = F_384 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_272 ) ;
return - V_81 ;
}
F_386 ( V_29 ) ;
V_152 = F_327 ( V_29 , 0 ) ;
if ( V_152 == NULL ) {
V_21 = - V_261 ;
goto V_921;
}
F_60 ( V_922 , V_152 + V_923 ) ;
F_330 ( V_152 ) ;
V_21 = F_342 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_921;
F_95 ( & V_29 -> V_30 , L_273 ) ;
for ( V_68 = 0 ; V_68 < V_924 ; V_68 ++ ) {
if ( F_390 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_274 ,
( V_68 < 11 ? L_275 : L_276 ) ) ;
}
V_921:
F_380 ( V_29 ) ;
return V_21 ;
}
static void F_391 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_705 ) ;
V_22 -> V_705 = NULL ;
if ( V_22 -> V_239 ) {
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_8 ) ,
V_22 -> V_239 ,
V_22 -> V_624 ) ;
V_22 -> V_239 = NULL ;
V_22 -> V_624 = 0 ;
}
if ( V_22 -> V_625 ) {
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_337 ) ,
V_22 -> V_625 ,
V_22 -> V_626 ) ;
V_22 -> V_625 = NULL ;
V_22 -> V_626 = 0 ;
}
}
static int F_392 ( struct V_1 * V_22 )
{
V_22 -> V_705 = F_115 (
F_393 ( V_22 -> V_237 , V_605 ) *
sizeof( unsigned long ) , V_203 ) ;
V_22 -> V_239 = F_331 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_239 ) ,
& ( V_22 -> V_624 ) ) ;
V_22 -> V_625 = F_331 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_625 ) ,
& ( V_22 -> V_626 ) ) ;
if ( ( V_22 -> V_705 == NULL )
|| ( V_22 -> V_239 == NULL )
|| ( V_22 -> V_625 == NULL ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_277 , V_204 ) ;
goto V_925;
}
F_254 ( V_22 ) ;
return 0 ;
V_925:
F_391 ( V_22 ) ;
return - V_261 ;
}
static void F_394 ( struct V_1 * V_22 )
{
int V_68 , V_383 ;
V_383 = F_395 ( V_926 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_396 ( V_22 -> V_653 [ V_68 ] , F_397 ( V_383 ) ) ;
V_383 = F_398 ( V_383 , V_926 ) ;
}
}
static void F_399 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_126 || V_22 -> V_654 != V_927 ) {
V_68 = V_22 -> V_654 ;
F_396 ( V_22 -> V_653 [ V_68 ] , NULL ) ;
F_400 ( V_22 -> V_653 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_396 ( V_22 -> V_653 [ V_68 ] , NULL ) ;
F_400 ( V_22 -> V_653 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
}
for (; V_68 < V_864 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = 0 ;
}
static int F_401 ( struct V_1 * V_22 ,
T_17 (* F_402)( int , void * ) ,
T_17 (* F_403)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_864 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_654 == V_927 && V_22 -> V_126 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
sprintf ( V_22 -> V_928 [ V_68 ] , L_278 , V_22 -> V_31 , V_68 ) ;
V_21 = F_404 ( V_22 -> V_653 [ V_68 ] , F_402 ,
0 , V_22 -> V_928 [ V_68 ] ,
& V_22 -> V_110 [ V_68 ] ) ;
if ( V_21 ) {
int V_193 ;
F_74 ( & V_22 -> V_29 -> V_30 ,
L_279 ,
V_22 -> V_653 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_193 = 0 ; V_193 < V_68 ; V_193 ++ ) {
F_400 ( V_22 -> V_653 [ V_193 ] , & V_22 -> V_110 [ V_193 ] ) ;
V_22 -> V_110 [ V_193 ] = 0 ;
}
for (; V_193 < V_864 ; V_193 ++ )
V_22 -> V_110 [ V_193 ] = 0 ;
return V_21 ;
}
}
F_394 ( V_22 ) ;
} else {
if ( V_22 -> V_126 > 0 || V_22 -> V_860 ) {
if ( V_22 -> V_126 )
sprintf ( V_22 -> V_928 [ V_22 -> V_654 ] ,
L_280 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_928 [ V_22 -> V_654 ] ,
L_281 , V_22 -> V_31 ) ;
V_21 = F_404 ( V_22 -> V_653 [ V_22 -> V_654 ] ,
F_402 , 0 ,
V_22 -> V_928 [ V_22 -> V_654 ] ,
& V_22 -> V_110 [ V_22 -> V_654 ] ) ;
} else {
sprintf ( V_22 -> V_928 [ V_22 -> V_654 ] ,
L_282 , V_22 -> V_31 ) ;
V_21 = F_404 ( V_22 -> V_653 [ V_22 -> V_654 ] ,
F_403 , V_929 ,
V_22 -> V_928 [ V_22 -> V_654 ] ,
& V_22 -> V_110 [ V_22 -> V_654 ] ) ;
}
F_396 ( V_22 -> V_653 [ V_22 -> V_654 ] , NULL ) ;
}
if ( V_21 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_279 ,
V_22 -> V_653 [ V_22 -> V_654 ] , V_22 -> V_31 ) ;
F_399 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_405 ( struct V_1 * V_22 )
{
int V_21 ;
F_309 ( V_22 , V_158 , V_930 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_283 ) ;
V_21 = F_350 ( V_22 -> V_29 , V_22 -> V_152 , V_931 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_284 ) ;
return V_21 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_285 ) ;
V_21 = F_350 ( V_22 -> V_29 , V_22 -> V_152 , V_833 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_286
L_287 ) ;
return V_21 ;
}
return 0 ;
}
static void F_406 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
if ( ! V_22 -> V_113 [ V_68 ] . V_117 )
continue;
F_333 ( V_22 -> V_29 ,
V_22 -> V_932 ,
V_22 -> V_113 [ V_68 ] . V_117 ,
V_22 -> V_113 [ V_68 ] . V_122 ) ;
V_22 -> V_113 [ V_68 ] . V_117 = NULL ;
V_22 -> V_113 [ V_68 ] . V_122 = 0 ;
}
V_22 -> V_932 = 0 ;
}
static void F_407 ( struct V_1 * V_22 )
{
F_408 ( V_22 ) ;
F_128 ( V_22 ) ;
F_391 ( V_22 ) ;
F_399 ( V_22 ) ;
F_409 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_379 ( V_22 ) ;
F_410 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_327 ) {
F_411 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_933 ) {
F_411 ( V_22 -> V_933 ) ;
V_22 -> V_933 = NULL ;
}
F_81 ( V_22 ) ;
}
static void F_412 ( struct V_1 * V_22 )
{
int V_68 , V_240 ;
struct V_8 * V_9 ;
int V_934 = 0 ;
F_413 ( V_22 -> V_327 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 ) {
V_9 -> V_24 -> V_36 = V_343 ;
F_62 ( V_9 ) ;
F_46 ( & V_22 -> V_62 ) ;
V_934 ++ ;
}
F_106 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_288 , V_934 ) ;
}
static void F_414 ( struct V_1 * V_22 , T_4 V_935 )
{
int V_383 ;
F_415 (cpu) {
T_4 * F_13 ;
F_13 = F_170 ( V_22 -> F_13 , V_383 ) ;
* F_13 = V_935 ;
}
F_77 () ;
}
static void F_416 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_332 ( V_22 -> V_152 + V_885 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_289 ,
V_22 -> V_147 / V_938 ) ;
F_13 = 0xffffffff ;
}
F_414 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_290 ,
F_13 , V_22 -> V_147 / V_938 ) ;
F_380 ( V_22 -> V_29 ) ;
F_412 ( V_22 ) ;
}
static int F_273 ( struct V_1 * V_22 )
{
T_5 V_939 ;
T_4 V_940 ;
unsigned long V_78 ;
V_939 = F_322 () ;
if ( F_417 ( V_22 -> V_793 +
( V_22 -> V_147 ) , V_939 ) )
return false ;
if ( F_417 ( V_22 -> V_941 +
( V_22 -> V_147 ) , V_939 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_940 = F_332 ( & V_22 -> V_817 -> V_847 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_942 == V_940 ) {
F_416 ( V_22 ) ;
return true ;
}
V_22 -> V_942 = V_940 ;
V_22 -> V_941 = V_939 ;
return false ;
}
static void F_418 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_943 ;
if ( ! ( V_22 -> V_480 & V_944 ) )
return;
if ( ( V_22 -> V_63 & ( V_114
| V_945 ) ) &&
( V_22 -> V_946 & V_947 ||
V_22 -> V_946 & V_948 ) ) {
if ( V_22 -> V_946 & V_947 )
V_943 = L_291 ;
if ( V_22 -> V_946 & V_948 )
V_943 = L_292 ;
F_419 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_22 -> V_30 [ V_68 ] -> V_91 = 0 ;
V_22 -> V_30 [ V_68 ] -> V_183 = 0 ;
}
F_420 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_293 ,
V_22 -> V_946 , V_943 ) ;
F_60 ( V_22 -> V_946 , & ( V_22 -> V_817 -> V_949 ) ) ;
F_60 ( V_902 , V_22 -> V_152 + V_812 ) ;
F_376 ( V_22 ) ;
F_421 ( V_22 -> V_59 ) ;
} else {
F_60 ( V_22 -> V_946 , & ( V_22 -> V_817 -> V_949 ) ) ;
F_60 ( V_902 , V_22 -> V_152 + V_812 ) ;
F_376 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_422 ( struct V_1 * V_22 )
{
if ( V_22 -> V_249 ) {
V_22 -> V_249 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_480 & V_944 ) )
return 0 ;
V_22 -> V_946 = F_332 ( & ( V_22 -> V_817 -> V_950 ) ) ;
return V_22 -> V_946 & V_951 ;
}
static int F_423 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_201 * V_389 ;
struct V_952 * V_953 , * V_954 ;
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_424 (this, tmp, &h->offline_device_list) {
V_389 = F_425 ( V_953 , struct V_201 ,
V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
if ( ! F_208 ( V_22 , V_389 -> V_72 ) ) {
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_426 ( & V_389 -> V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_202 , V_78 ) ;
}
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 0 ;
}
static int F_427 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_462 * V_492 = NULL ;
if ( ! V_22 -> V_955 )
goto V_394;
V_492 = F_115 ( sizeof( * V_492 ) , V_203 ) ;
if ( ! V_492 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_294 ) ;
goto V_394;
}
if ( F_204 ( V_22 , 1 , V_492 , sizeof( * V_492 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_295 ) ;
goto V_394;
}
if ( memcmp ( V_492 , V_22 -> V_955 , sizeof( * V_492 ) ) ) {
F_95 ( & V_22 -> V_29 -> V_30 ,
L_296 ) ;
memcpy ( V_22 -> V_955 , V_492 , sizeof( * V_492 ) ) ;
goto V_394;
} else
V_21 = 0 ;
V_394:
F_81 ( V_492 ) ;
return V_21 ;
}
static void F_428 ( struct V_628 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_257 ( F_429 ( V_325 ) ,
struct V_1 , V_956 ) ;
if ( V_22 -> V_906 )
return;
if ( F_422 ( V_22 ) || F_423 ( V_22 ) ) {
F_430 ( V_22 -> V_59 ) ;
F_418 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_409 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_521 ) {
F_431 ( V_22 ) ;
if ( F_427 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_297 ) ;
V_7 = F_430 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_409 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_906 )
F_432 ( V_22 -> V_933 , & V_22 -> V_956 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_433 ( struct V_628 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_257 ( F_429 ( V_325 ) ,
struct V_1 , V_957 ) ;
F_273 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_906 )
F_434 ( & V_22 -> V_957 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_958 * F_435 ( struct V_1 * V_22 ,
char * V_959 )
{
struct V_958 * V_960 = NULL ;
V_960 = F_436 ( L_298 , 0 , V_959 , V_22 -> V_961 ) ;
if ( ! V_960 )
F_74 ( & V_22 -> V_29 -> V_30 , L_299 , V_959 ) ;
return V_960 ;
}
static int F_437 ( struct V_369 * V_29 , const struct V_962 * V_963 )
{
int V_964 , V_21 ;
struct V_1 * V_22 ;
int V_965 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_966 == 0 )
F_438 (KERN_INFO DRIVER_NAME L_300 ) ;
V_21 = F_364 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_301 ) ;
return V_21 ;
}
V_21 = F_389 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_826 )
return V_21 ;
V_965 = 1 ;
V_21 = 0 ;
}
V_967:
F_279 ( sizeof( struct V_8 ) % V_968 ) ;
V_22 = F_115 ( sizeof( * V_22 ) , V_203 ) ;
if ( ! V_22 ) {
F_74 ( & V_29 -> V_30 , L_302 ) ;
return - V_261 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_654 = V_969 ? V_970 : V_927 ;
F_439 ( & V_22 -> V_206 ) ;
F_440 ( & V_22 -> V_79 ) ;
F_440 ( & V_22 -> V_202 ) ;
F_440 ( & V_22 -> V_633 ) ;
F_122 ( & V_22 -> V_764 , V_971 ) ;
F_122 ( & V_22 -> V_695 , V_972 ) ;
V_22 -> F_13 = F_441 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_303 ) ;
V_21 = - V_261 ;
goto V_973;
}
F_414 ( V_22 , 0 ) ;
V_21 = F_382 ( V_22 ) ;
if ( V_21 )
goto V_918;
V_21 = F_263 ( V_22 ) ;
if ( V_21 )
goto V_974;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_102 ) ;
V_22 -> V_961 = V_966 ;
V_966 ++ ;
V_21 = F_442 ( V_29 , F_329 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_964 = 1 ;
} else {
V_21 = F_442 ( V_29 , F_329 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_964 = 0 ;
} else {
F_74 ( & V_29 -> V_30 , L_304 ) ;
goto V_919;
}
}
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
V_21 = F_401 ( V_22 , F_325 , F_324 ) ;
if ( V_21 )
goto V_919;
V_21 = F_392 ( V_22 ) ;
if ( V_21 )
goto V_920;
V_21 = F_129 ( V_22 ) ;
if ( V_21 )
goto V_975;
F_443 ( & V_22 -> V_635 ) ;
F_443 ( & V_22 -> V_694 ) ;
F_443 ( & V_22 -> V_323 ) ;
F_444 ( & V_22 -> V_403 ) ;
V_22 -> V_634 = 1 ;
F_445 ( V_29 , V_22 ) ;
V_22 -> V_162 = 0 ;
F_440 ( & V_22 -> V_98 ) ;
V_21 = F_446 ( V_22 ) ;
if ( V_21 )
goto V_976;
V_22 -> V_933 = F_435 ( V_22 , L_305 ) ;
if ( ! V_22 -> V_933 ) {
V_21 = - V_261 ;
goto V_977;
}
V_22 -> V_327 = F_435 ( V_22 , L_306 ) ;
if ( ! V_22 -> V_327 ) {
V_21 = - V_261 ;
goto V_977;
}
if ( V_965 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_399 ( V_22 ) ;
V_21 = F_401 ( V_22 , F_323 ,
F_321 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_307 ) ;
F_408 ( V_22 ) ;
F_128 ( V_22 ) ;
F_391 ( V_22 ) ;
goto V_919;
}
V_21 = F_405 ( V_22 ) ;
if ( V_21 )
goto V_977;
F_95 ( & V_22 -> V_29 -> V_30 , L_308 ) ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_309 ) ;
V_22 -> V_115 . V_936 ( V_22 , V_978 ) ;
F_108 ( 10000 ) ;
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
V_21 = F_341 ( V_22 -> V_817 ) ;
if ( V_21 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_310 ) ;
F_407 ( V_22 ) ;
V_965 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_967;
}
V_22 -> V_56 = 1 ;
V_22 -> V_521 = 0 ;
V_22 -> V_115 . V_936 ( V_22 , V_978 ) ;
F_387 ( V_22 ) ;
V_22 -> V_955 = F_115 ( sizeof( * ( V_22 -> V_955 ) ) , V_203 ) ;
if ( ! V_22 -> V_955 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
V_21 = F_265 ( V_22 ) ;
if ( V_21 )
goto V_977;
V_22 -> V_147 = V_149 ;
F_447 ( & V_22 -> V_957 , F_433 ) ;
F_434 ( & V_22 -> V_957 ,
V_22 -> V_147 ) ;
F_447 ( & V_22 -> V_956 , F_428 ) ;
F_432 ( V_22 -> V_933 , & V_22 -> V_956 ,
V_22 -> V_147 ) ;
return 0 ;
V_977:
F_408 ( V_22 ) ;
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
V_976:
F_128 ( V_22 ) ;
V_975:
F_391 ( V_22 ) ;
V_920:
F_399 ( V_22 ) ;
V_919:
F_409 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_974:
F_379 ( V_22 ) ;
V_918:
if ( V_22 -> F_13 ) {
F_410 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_973:
if ( V_22 -> V_327 ) {
F_411 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_933 ) {
F_411 ( V_22 -> V_933 ) ;
V_22 -> V_933 = NULL ;
}
F_81 ( V_22 ) ;
return V_21 ;
}
static void F_448 ( struct V_1 * V_22 )
{
char * V_979 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return;
V_979 = F_115 ( 4 , V_203 ) ;
if ( ! V_979 )
return;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_772 , V_22 , V_979 , 4 , 0 ,
V_158 , V_393 ) ) {
goto V_394;
}
V_21 = F_172 ( V_22 , V_9 ,
V_271 , V_396 ) ;
if ( V_21 )
goto V_394;
if ( V_9 -> V_24 -> V_36 != 0 )
V_394:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_312 ) ;
F_106 ( V_22 , V_9 ) ;
F_81 ( V_979 ) ;
}
static void F_431 ( struct V_1 * V_22 )
{
T_4 * V_980 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( V_22 -> F_13 ) )
return;
V_980 = F_115 ( sizeof( * V_980 ) , V_203 ) ;
if ( ! V_980 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_313 ) ;
return;
}
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_769 , V_22 , V_980 , 4 , 0 ,
V_158 , V_393 ) )
goto V_981;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_981;
* V_980 |= V_982 ;
if ( F_177 ( V_9 , V_771 , V_22 , V_980 , 4 , 0 ,
V_158 , V_393 ) )
goto V_981;
V_21 = F_172 ( V_22 , V_9 ,
V_271 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_981;
if ( F_177 ( V_9 , V_769 , V_22 , V_980 , 4 , 0 ,
V_158 , V_393 ) )
goto V_981;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_981;
if ( * V_980 & V_982 )
goto V_394;
V_981:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_314 ) ;
V_394:
F_106 ( V_22 , V_9 ) ;
F_81 ( V_980 ) ;
}
static void F_449 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_450 ( V_29 ) ;
F_448 ( V_22 ) ;
V_22 -> V_115 . V_936 ( V_22 , V_937 ) ;
F_399 ( V_22 ) ;
F_355 ( V_22 ) ;
}
static void F_451 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
F_81 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_452 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_450 ( V_29 ) == NULL ) {
F_74 ( & V_29 -> V_30 , L_315 ) ;
return;
}
V_22 = F_450 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_906 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_453 ( & V_22 -> V_957 ) ;
F_453 ( & V_22 -> V_956 ) ;
F_411 ( V_22 -> V_933 ) ;
F_411 ( V_22 -> V_327 ) ;
if ( V_22 -> V_59 )
F_454 ( V_22 -> V_59 ) ;
F_449 ( V_29 ) ;
F_451 ( V_22 ) ;
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_126 ( V_22 ) ;
F_408 ( V_22 ) ;
F_128 ( V_22 ) ;
F_391 ( V_22 ) ;
F_81 ( V_22 -> V_955 ) ;
F_409 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_379 ( V_22 ) ;
F_410 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_455 ( V_22 ) ;
F_81 ( V_22 ) ;
}
static void F_456 ( int V_983 [] , int V_984 ,
int V_985 , int V_986 , T_4 * V_987 )
{
int V_68 , V_193 , V_988 , V_466 ;
for ( V_68 = 0 ; V_68 <= V_985 ; V_68 ++ ) {
V_466 = V_68 + V_986 ;
V_988 = V_984 ;
for ( V_193 = 0 ; V_193 < V_984 ; V_193 ++ ) {
if ( V_983 [ V_193 ] >= V_466 ) {
V_988 = V_193 ;
break;
}
}
V_987 [ V_68 ] = V_988 ;
}
}
static int F_457 ( struct V_1 * V_22 , T_4 V_909 )
{
int V_68 ;
unsigned long V_989 ;
unsigned long V_63 = V_64 |
( V_909 & V_990 ) |
V_991 |
( V_909 & ( V_114 |
V_945 ) ) ;
struct V_992 V_115 = V_993 ;
int V_994 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_761 + 4 } ;
#define F_458 5
#define F_459 4
int V_995 [ 16 ] = { F_458 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_459 + V_996 } ;
F_279 ( F_26 ( V_995 ) != 16 ) ;
F_279 ( F_26 ( V_994 ) != 8 ) ;
F_279 ( F_247 ( struct V_139 , V_269 ) >
16 * F_458 ) ;
F_279 ( sizeof( struct V_265 ) != 16 ) ;
F_279 ( 28 > V_761 + 4 ) ;
if ( V_909 & ( V_114 | V_945 ) )
V_115 = V_997 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 , 0 , V_22 -> V_932 ) ;
V_994 [ 7 ] = V_761 + 4 ;
F_456 ( V_994 , F_26 ( V_994 ) ,
V_761 , 4 , V_22 -> V_123 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_60 ( V_994 [ V_68 ] , & V_22 -> V_890 -> V_998 [ V_68 ] ) ;
F_60 ( V_22 -> V_121 , & V_22 -> V_890 -> V_999 ) ;
F_60 ( V_22 -> V_129 , & V_22 -> V_890 -> V_1000 ) ;
F_60 ( 0 , & V_22 -> V_890 -> V_1001 ) ;
F_60 ( 0 , & V_22 -> V_890 -> V_1002 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( 0 , & V_22 -> V_890 -> V_1003 [ V_68 ] . V_1004 ) ;
F_60 ( V_22 -> V_113 [ V_68 ] . V_122 ,
& V_22 -> V_890 -> V_1003 [ V_68 ] . V_1005 ) ;
}
F_60 ( 0 , & V_22 -> V_817 -> V_840 . V_912 ) ;
F_60 ( V_63 , & ( V_22 -> V_817 -> V_840 . V_841 ) ) ;
if ( V_909 & V_114 ) {
V_115 = V_1006 ;
F_60 ( 10 , & V_22 -> V_817 -> V_840 . V_842 ) ;
F_60 ( 4 , & V_22 -> V_817 -> V_840 . V_843 ) ;
} else {
if ( V_909 & V_945 ) {
V_115 = V_1007 ;
F_60 ( 10 , & V_22 -> V_817 -> V_840 . V_842 ) ;
F_60 ( 4 , & V_22 -> V_817 -> V_840 . V_843 ) ;
}
}
F_60 ( V_907 , V_22 -> V_152 + V_812 ) ;
if ( F_377 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_316 ) ;
return - V_81 ;
}
V_989 = F_332 ( & ( V_22 -> V_817 -> V_839 ) ) ;
if ( ! ( V_989 & V_64 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_317 ) ;
return - V_81 ;
}
V_22 -> V_115 = V_115 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_909 & V_114 ) ||
( V_909 & V_945 ) ) )
return 0 ;
if ( V_909 & V_114 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( V_68 , V_22 -> V_152 + V_1008 ) ;
V_22 -> V_113 [ V_68 ] . V_118 =
F_332 ( V_22 -> V_152 + V_1009 ) ;
}
V_994 [ 7 ] = V_22 -> V_545 + 8 ;
F_456 ( V_994 , F_26 ( V_994 ) , V_22 -> V_545 , 8 ,
V_22 -> V_134 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 ,
( T_1 ) V_1010 ,
V_22 -> V_932 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_130 * V_131 = & V_22 -> V_132 [ V_68 ] ;
V_131 -> V_1011 = V_1012 ;
V_131 -> V_24 = ( T_4 ) ( V_22 -> V_626 +
( V_68 * sizeof( struct V_337 ) ) ) ;
V_131 -> V_1013 = sizeof( struct V_337 ) ;
V_131 -> V_1014 = V_1015 ;
V_131 -> V_1016 =
F_160 ( V_1017 ) ;
V_131 -> V_1018 = 0 ;
V_131 -> V_128 = 0 ;
V_131 -> V_348 =
F_134 ( ( V_68 << V_576 ) ) ;
V_131 -> V_1019 =
F_134 ( V_22 -> V_548 +
( V_68 * sizeof( struct V_130 ) ) ) ;
}
} else if ( V_909 & V_945 ) {
T_5 V_820 , V_822 ;
T_4 V_1020 , V_821 ;
int V_21 ;
V_21 = F_346 ( V_22 -> V_29 , V_22 -> V_152 , & V_821 ,
& V_822 , & V_820 ) ;
F_279 ( F_247 ( struct V_139 , V_269 ) != 64 ) ;
V_995 [ 15 ] = V_22 -> V_545 + F_459 ;
F_456 ( V_995 , F_26 ( V_995 ) , V_22 -> V_545 ,
4 , V_22 -> V_138 ) ;
V_1020 = F_332 ( & V_22 -> V_817 -> V_1021 ) ;
F_279 ( F_247 ( struct V_816 ,
V_1021 ) != 0xb8 ) ;
V_22 -> V_1022 =
F_311 ( F_347 ( V_22 -> V_29 ,
V_822 ) +
V_820 + V_1020 ,
F_26 ( V_995 ) *
sizeof( * V_22 -> V_1022 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_995 ) ; V_68 ++ )
F_60 ( V_995 [ V_68 ] , & V_22 -> V_1022 [ V_68 ] ) ;
}
F_60 ( V_907 , V_22 -> V_152 + V_812 ) ;
if ( F_377 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_318 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_460 ( struct V_1 * V_22 )
{
if ( V_22 -> V_132 ) {
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
V_22 -> V_132 ,
V_22 -> V_548 ) ;
V_22 -> V_132 = NULL ;
V_22 -> V_548 = 0 ;
}
F_81 ( V_22 -> V_134 ) ;
V_22 -> V_134 = NULL ;
}
static int F_461 ( struct V_1 * V_22 )
{
V_22 -> V_545 =
F_332 ( & ( V_22 -> V_817 -> V_1023 ) ) ;
if ( V_22 -> V_545 > V_1024 )
V_22 -> V_545 = V_1024 ;
F_279 ( sizeof( struct V_130 ) %
V_1025 ) ;
V_22 -> V_132 =
F_331 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
& ( V_22 -> V_548 ) ) ;
V_22 -> V_134 =
F_92 ( ( ( V_22 -> V_545 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_132 == NULL ) ||
( V_22 -> V_134 == NULL ) )
goto V_925;
memset ( V_22 -> V_132 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ) ;
return 0 ;
V_925:
F_460 ( V_22 ) ;
return - V_261 ;
}
static void F_462 ( struct V_1 * V_22 )
{
F_126 ( V_22 ) ;
if ( V_22 -> V_137 ) {
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
V_22 -> V_137 ,
V_22 -> V_567 ) ;
V_22 -> V_137 = NULL ;
V_22 -> V_567 = 0 ;
}
F_81 ( V_22 -> V_138 ) ;
V_22 -> V_138 = NULL ;
}
static int F_463 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_545 =
F_332 ( & ( V_22 -> V_817 -> V_1023 ) ) ;
if ( V_22 -> V_545 > V_996 )
V_22 -> V_545 = V_996 ;
F_279 ( sizeof( struct V_139 ) %
V_1026 ) ;
V_22 -> V_137 =
F_331 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
& ( V_22 -> V_567 ) ) ;
V_22 -> V_138 =
F_92 ( ( ( V_22 -> V_545 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_137 == NULL ) ||
( V_22 -> V_138 == NULL ) ) {
V_21 = - V_261 ;
goto V_925;
}
V_21 = F_127 ( V_22 ) ;
if ( V_21 )
goto V_925;
memset ( V_22 -> V_137 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ) ;
return 0 ;
V_925:
F_462 ( V_22 ) ;
return V_21 ;
}
static void F_408 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
F_406 ( V_22 ) ;
F_460 ( V_22 ) ;
F_462 ( V_22 ) ;
}
static int F_446 ( struct V_1 * V_22 )
{
T_4 V_909 ;
unsigned long V_63 = V_64 |
V_990 ;
int V_68 , V_21 ;
if ( V_969 )
return 0 ;
V_909 = F_332 ( & ( V_22 -> V_817 -> V_838 ) ) ;
if ( ! ( V_909 & V_1027 ) )
return 0 ;
if ( V_909 & V_114 ) {
V_63 |= V_114 |
V_991 ;
V_21 = F_461 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_909 & V_945 ) {
V_63 |= V_945 |
V_991 ;
V_21 = F_463 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_129 = V_22 -> V_126 > 0 ? V_22 -> V_126 : 1 ;
F_367 ( V_22 ) ;
V_22 -> V_932 = V_22 -> V_121 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
V_22 -> V_113 [ V_68 ] . V_117 = F_331 ( V_22 -> V_29 ,
V_22 -> V_932 ,
& ( V_22 -> V_113 [ V_68 ] . V_122 ) ) ;
if ( ! V_22 -> V_113 [ V_68 ] . V_117 ) {
V_21 = - V_261 ;
goto V_973;
}
V_22 -> V_113 [ V_68 ] . V_466 = V_22 -> V_121 ;
V_22 -> V_113 [ V_68 ] . V_119 = 1 ;
V_22 -> V_113 [ V_68 ] . V_118 = 0 ;
}
V_22 -> V_123 = F_92 ( ( ( V_761 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ! V_22 -> V_123 ) {
V_21 = - V_261 ;
goto V_973;
}
V_21 = F_457 ( V_22 , V_909 ) ;
if ( V_21 )
goto V_918;
return 0 ;
V_918:
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
V_973:
F_406 ( V_22 ) ;
F_460 ( V_22 ) ;
F_462 ( V_22 ) ;
return V_21 ;
}
static int F_464 ( struct V_8 * V_9 )
{
return V_9 -> V_150 == V_151 || V_9 -> V_150 == V_154 ;
}
static void F_420 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1028 ;
int V_240 ;
do {
V_1028 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 )
V_1028 += F_464 ( V_9 ) ;
F_106 ( V_22 , V_9 ) ;
}
if ( V_1028 <= 0 )
break;
F_108 ( 100 ) ;
} while ( 1 );
}
static struct V_1029 * F_465 (
struct V_1030 * V_1030 )
{
struct V_1029 * V_1029 ;
struct V_1031 * V_1032 ;
V_1029 = F_115 ( sizeof( * V_1029 ) , V_203 ) ;
if ( ! V_1029 )
return NULL ;
V_1032 = F_466 ( V_1030 -> V_1033 -> V_1034 ,
V_1030 -> V_1035 ) ;
if ( ! V_1032 ) {
F_81 ( V_1029 ) ;
return NULL ;
}
V_1030 -> V_1035 ++ ;
V_1029 -> V_1032 = V_1032 ;
V_1029 -> V_1036 = V_1030 ;
return V_1029 ;
}
static void F_467 ( struct V_1029 * V_1029 )
{
struct V_1031 * V_1032 = V_1029 -> V_1032 ;
F_468 ( V_1029 -> V_1036 -> V_1037 , V_1032 ) ;
F_469 ( V_1032 ) ;
if ( V_1029 -> V_1038 )
F_426 ( & V_1029 -> V_1039 ) ;
F_81 ( V_1029 ) ;
}
static int F_470 ( struct V_1029 * V_1029 )
{
int V_21 ;
struct V_1030 * V_1030 ;
struct V_1031 * V_1032 ;
struct V_1040 * V_1041 ;
V_1030 = V_1029 -> V_1036 ;
V_1032 = V_1029 -> V_1032 ;
V_1041 = & V_1032 -> V_1041 ;
memset ( V_1041 , 0 , sizeof( * V_1041 ) ) ;
V_1041 -> V_89 = V_1030 -> V_89 ;
V_1041 -> V_520 = V_1042 ;
V_1041 -> V_1043 = V_1044 ;
V_1041 -> V_1045 = V_1044 ;
V_1032 -> V_1046 = V_1047 ;
V_1032 -> V_1048 = V_1047 ;
V_1032 -> V_1049 = V_1047 ;
V_1032 -> V_1050 = V_1047 ;
V_1032 -> V_1051 = V_1047 ;
V_21 = F_471 ( V_1029 -> V_1032 ) ;
if ( V_21 )
return V_21 ;
F_472 ( V_1030 -> V_1037 , V_1029 -> V_1032 ) ;
F_93 ( & V_1029 -> V_1039 ,
& V_1030 -> V_1052 ) ;
V_1029 -> V_1038 = true ;
return 0 ;
}
static int
F_473 ( struct V_1030 * V_1030 ,
struct V_254 * V_255 )
{
struct V_1040 * V_1041 ;
V_1041 = & V_255 -> V_1041 ;
V_1041 -> V_89 = V_1030 -> V_89 ;
V_1041 -> V_1043 = V_1044 ;
V_1041 -> V_1045 = V_1044 ;
return F_474 ( V_255 ) ;
}
static struct V_1030
* F_475 ( struct V_1053 * V_1053 ,
T_5 V_89 )
{
int V_21 ;
struct V_1030 * V_1030 ;
struct V_1054 * V_1037 ;
V_1030 = F_115 ( sizeof( * V_1030 ) , V_203 ) ;
if ( ! V_1030 )
return NULL ;
F_439 ( & V_1030 -> V_1052 ) ;
V_1030 -> V_1033 = V_1053 ;
V_1037 = F_476 ( V_1053 -> V_1034 ) ;
if ( ! V_1037 )
goto V_1055;
V_21 = F_477 ( V_1037 ) ;
if ( V_21 )
goto V_1056;
V_1030 -> V_1037 = V_1037 ;
V_1030 -> V_89 = V_89 ;
F_93 ( & V_1030 -> V_1057 ,
& V_1053 -> V_1058 ) ;
return V_1030 ;
V_1056:
F_478 ( V_1037 ) ;
V_1055:
F_81 ( V_1030 ) ;
return NULL ;
}
static void F_479 ( struct V_1030 * V_1030 )
{
struct V_1029 * V_1029 ;
struct V_1029 * V_1059 ;
F_480 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_467 ( V_1029 ) ;
F_481 ( V_1030 -> V_1037 ) ;
F_426 ( & V_1030 -> V_1057 ) ;
F_81 ( V_1030 ) ;
}
static struct V_1053 * F_482 ( struct V_42 * V_1034 )
{
struct V_1053 * V_1053 ;
V_1053 = F_115 ( sizeof( * V_1053 ) , V_203 ) ;
if ( V_1053 ) {
V_1053 -> V_1034 = V_1034 ;
F_439 ( & V_1053 -> V_1058 ) ;
}
return V_1053 ;
}
static void F_483 ( struct V_1053 * V_1053 )
{
struct V_1030 * V_1030 ;
struct V_1030 * V_1059 ;
if ( ! V_1053 )
return;
F_480 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_479 ( V_1030 ) ;
F_81 ( V_1053 ) ;
}
static struct V_73
* F_120 ( struct V_1 * V_22 ,
struct V_254 * V_255 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1054 )
continue;
if ( V_42 -> V_1054 -> V_255 == V_255 )
return V_42 ;
}
return NULL ;
}
static int F_232 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1034 ;
struct V_1053 * V_1053 ;
struct V_1030 * V_1030 ;
struct V_1029 * V_1029 ;
V_1034 = & V_22 -> V_59 -> V_1060 ;
V_1053 = F_482 ( V_1034 ) ;
if ( ! V_1053 )
return - V_261 ;
V_1030 = F_475 ( V_1053 , V_22 -> V_89 ) ;
if ( ! V_1030 ) {
V_21 = - V_81 ;
goto V_1061;
}
V_1029 = F_465 ( V_1030 ) ;
if ( ! V_1029 ) {
V_21 = - V_81 ;
goto V_1056;
}
V_21 = F_470 ( V_1029 ) ;
if ( V_21 )
goto V_1062;
V_22 -> V_238 = V_1053 ;
return 0 ;
V_1062:
F_467 ( V_1029 ) ;
V_1056:
F_479 ( V_1030 ) ;
V_1061:
F_483 ( V_1053 ) ;
return V_21 ;
}
static void F_455 ( struct V_1 * V_22 )
{
F_483 ( V_22 -> V_238 ) ;
}
static int F_102 ( struct V_1053 * V_1053 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1030 * V_1030 ;
struct V_254 * V_255 ;
V_1030 = F_475 ( V_1053 , V_42 -> V_89 ) ;
if ( ! V_1030 )
return - V_261 ;
V_255 = F_484 ( V_1030 -> V_1037 ) ;
if ( ! V_255 ) {
V_21 = - V_81 ;
goto V_1056;
}
V_1030 -> V_255 = V_255 ;
V_42 -> V_1054 = V_1030 ;
V_21 = F_473 ( V_1030 , V_255 ) ;
if ( V_21 )
goto V_1056;
return 0 ;
V_1056:
F_479 ( V_1030 ) ;
V_42 -> V_1054 = NULL ;
return V_21 ;
}
static void F_113 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1054 ) {
F_479 ( V_42 -> V_1054 ) ;
V_42 -> V_1054 = NULL ;
}
}
static int
F_485 ( struct V_1031 * V_1032 )
{
return 0 ;
}
static int
F_486 ( struct V_254 * V_255 , T_5 * V_1063 )
{
* V_1063 = 0 ;
return 0 ;
}
static int
F_487 ( struct V_254 * V_255 )
{
return - V_1064 ;
}
static int
F_488 ( struct V_1031 * V_1032 , int V_1065 )
{
return 0 ;
}
static int
F_489 ( struct V_1031 * V_1032 , int V_1066 )
{
return 0 ;
}
static int
F_490 ( struct V_1031 * V_1032 )
{
return 0 ;
}
static void
F_491 ( struct V_1031 * V_1032 )
{
}
static int
F_492 ( struct V_1031 * V_1032 , struct V_1067 * V_1068 )
{
return - V_55 ;
}
static int
F_493 ( struct V_6 * V_47 , struct V_254 * V_255 ,
struct V_630 * V_1069 )
{
return - V_55 ;
}
static int T_18 F_494 ( void )
{
int V_21 ;
V_651 =
F_495 ( & V_1070 ) ;
if ( ! V_651 )
return - V_81 ;
V_21 = F_496 ( & V_1071 ) ;
if ( V_21 )
F_497 ( V_651 ) ;
return V_21 ;
}
static void T_19 F_498 ( void )
{
F_499 ( & V_1071 ) ;
F_497 ( V_651 ) ;
}
