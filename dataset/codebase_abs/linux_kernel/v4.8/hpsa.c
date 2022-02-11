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
static bool F_231 ( struct V_1 * V_22 , T_1 * V_483 )
{
struct V_429 * V_437 ;
bool V_510 = false ;
int V_21 ;
V_437 = F_115 ( sizeof( * V_437 ) , V_203 ) ;
if ( ! V_437 )
return false ;
V_21 = F_189 ( V_22 ,
V_483 ,
F_191 ( V_483 ) ,
V_437 , sizeof( * V_437 ) ) ;
if ( V_21 == 0 )
V_510 = ( V_437 -> V_511 >> 6 ) & 0x01 ;
F_81 ( V_437 ) ;
return V_510 ;
}
static bool F_232 ( struct V_1 * V_22 , T_1 * V_483 ,
struct V_438 * V_439 )
{
T_1 V_500 ;
T_1 V_512 ;
if ( ! F_192 ( V_483 ) )
return false ;
V_500 = V_439 -> V_500 ;
V_512 = V_439 -> V_512 ;
if ( V_500 & V_513 ) {
if ( V_512 == V_514 )
return false ;
return true ;
}
if ( ! ( V_500 & V_515 ) )
return false ;
if ( V_500 & V_516 )
return false ;
if ( F_231 ( V_22 , V_483 ) )
return true ;
return false ;
}
static void F_233 ( struct V_1 * V_22 )
{
struct V_431 * V_497 = NULL ;
struct V_462 * V_498 = NULL ;
struct V_429 * V_437 = NULL ;
struct V_427 * V_506 = NULL ;
T_4 V_445 = 0 ;
T_4 V_493 = 0 ;
T_4 V_490 = 0 ;
T_4 V_517 = 0 ;
struct V_73 * * V_518 , * V_422 , * V_519 ;
int V_520 = 0 ;
int V_68 , V_521 , V_522 ;
int V_489 ;
bool V_74 ;
F_66 ( V_523 , V_524 ) ;
V_518 = F_115 ( sizeof( * V_518 ) * V_161 , V_203 ) ;
V_497 = F_115 ( sizeof( * V_497 ) , V_203 ) ;
V_498 = F_115 ( sizeof( * V_498 ) , V_203 ) ;
V_519 = F_115 ( sizeof( * V_519 ) , V_203 ) ;
V_437 = F_115 ( sizeof( * V_437 ) , V_203 ) ;
V_506 = F_115 ( sizeof( * V_506 ) , V_203 ) ;
if ( ! V_518 || ! V_497 || ! V_498 ||
! V_519 || ! V_437 || ! V_506 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_157 ) ;
goto V_394;
}
memset ( V_523 , 0 , sizeof( V_523 ) ) ;
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
V_522 = V_445 + V_493 + V_524 + 1 ;
for ( V_68 = 0 ; V_68 < V_522 ; V_68 ++ ) {
if ( V_68 >= V_161 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_159
L_160 , V_161 ,
V_522 - V_161 ) ;
break;
}
V_518 [ V_68 ] = F_115 ( sizeof( * V_518 [ V_68 ] ) , V_203 ) ;
if ( ! V_518 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_161 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_249 = 1 ;
goto V_394;
}
V_517 ++ ;
}
if ( F_64 ( V_22 ) )
V_489 = 0 ;
else
V_489 = V_445 + V_493 ;
V_521 = 0 ;
for ( V_68 = 0 ; V_68 < V_445 + V_493 + 1 ; V_68 ++ ) {
T_1 * V_483 , V_525 = 0 ;
int V_21 = 0 ;
int V_526 = V_68 - ( V_489 == 0 ) ;
bool V_527 = false ;
V_74 = V_68 < V_445 + ( V_489 == 0 ) ;
V_483 = F_225 ( V_22 , V_489 ,
V_68 , V_445 , V_493 , V_497 , V_498 ) ;
if ( ! V_519 -> V_167 && V_74 ) {
V_527 = F_232 ( V_22 , V_483 ,
& V_497 -> V_349 [ V_526 ] ) ;
if ( V_527 )
continue;
}
V_21 = F_213 ( V_22 , V_483 , V_519 ,
& V_525 ) ;
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
V_519 -> V_167 =
F_222 ( V_22 , V_489 , V_68 ,
V_445 , V_490 ) ;
F_220 ( V_22 , V_483 , V_519 ) ;
F_219 ( V_22 , V_519 , V_483 ) ;
V_422 = V_518 [ V_520 ] ;
if ( ! V_22 -> V_528 ) {
if ( V_519 -> V_167 ) {
V_22 -> V_528 = 1 ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_164 ) ;
}
}
* V_422 = * V_519 ;
V_422 -> V_74 = V_74 ;
if ( F_192 ( V_483 ) && V_422 -> V_74 )
V_422 -> V_90 = 0 ;
else
V_422 -> V_90 = 1 ;
if ( V_422 -> V_74 && V_422 -> V_90 )
F_197 ( V_22 , V_483 , V_422 ) ;
switch ( V_422 -> V_106 ) {
case V_169 :
if ( V_525 )
V_520 ++ ;
break;
case V_108 :
case V_109 :
if ( V_422 -> V_74 ) {
V_422 -> V_91 = 0 ;
F_226 ( V_22 , V_422 ,
V_497 , V_526 , V_437 ) ;
F_229 ( V_422 ,
V_497 , V_526 , V_437 ) ;
}
V_520 ++ ;
break;
case V_170 :
case V_171 :
V_520 ++ ;
break;
case V_166 :
if ( ! V_422 -> V_167 )
F_190 ( V_22 , V_483 ,
V_497 , V_526 ,
V_422 ) ;
V_520 ++ ;
break;
case V_107 :
if ( ! F_63 ( V_483 ) )
break;
V_520 ++ ;
break;
default:
break;
}
if ( V_520 >= V_161 )
break;
}
if ( V_22 -> V_238 == NULL ) {
int V_21 = 0 ;
V_21 = F_234 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_165 , V_21 ) ;
goto V_394;
}
}
F_114 ( V_22 , V_518 , V_520 ) ;
V_394:
F_81 ( V_519 ) ;
for ( V_68 = 0 ; V_68 < V_517 ; V_68 ++ )
F_81 ( V_518 [ V_68 ] ) ;
F_81 ( V_518 ) ;
F_81 ( V_497 ) ;
F_81 ( V_498 ) ;
F_81 ( V_506 ) ;
F_81 ( V_437 ) ;
}
static void F_235 ( struct V_274 * V_529 ,
struct V_530 * V_269 )
{
T_5 V_374 = ( T_5 ) F_236 ( V_269 ) ;
unsigned int V_50 = F_237 ( V_269 ) ;
V_529 -> V_282 = F_134 ( V_374 ) ;
V_529 -> V_281 = F_139 ( V_50 ) ;
V_529 -> V_278 = 0 ;
}
static int F_238 ( struct V_1 * V_22 ,
struct V_8 * V_131 ,
struct V_283 * V_284 )
{
struct V_530 * V_269 ;
int V_531 , V_68 , V_532 , V_533 , V_534 ;
struct V_274 * V_535 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
V_531 = F_239 ( V_284 ) ;
if ( V_531 < 0 )
return V_531 ;
if ( ! V_531 )
goto V_536;
V_535 = V_131 -> V_276 ;
V_533 = V_531 > V_22 -> V_277 ;
V_532 = V_533 ? V_22 -> V_277 - 1 : V_531 ;
V_534 = F_159 ( V_284 ) - 1 ;
F_240 (cmd, sg, sg_limit, i) {
F_235 ( V_535 , V_269 ) ;
V_535 ++ ;
}
if ( V_533 ) {
V_535 = V_22 -> V_264 [ V_131 -> V_133 ] ;
V_532 = V_531 - V_532 ;
F_241 (sg, sg, sg_limit, i) {
F_235 ( V_535 , V_269 ) ;
V_535 ++ ;
}
}
( V_535 - 1 ) -> V_278 = F_139 ( V_376 ) ;
if ( V_531 + V_533 > V_22 -> V_537 )
V_22 -> V_537 = V_531 + V_533 ;
if ( V_533 ) {
V_131 -> V_124 . V_125 = V_22 -> V_277 ;
V_131 -> V_124 . V_280 = F_160 ( V_531 + 1 ) ;
if ( F_138 ( V_22 , V_131 ) ) {
F_158 ( V_284 ) ;
return - 1 ;
}
return 0 ;
}
V_536:
V_131 -> V_124 . V_125 = ( T_1 ) V_531 ;
V_131 -> V_124 . V_280 = F_160 ( V_531 ) ;
return 0 ;
}
static int F_242 ( T_1 * V_141 , int * V_538 )
{
int V_539 = 0 ;
T_4 V_540 ;
T_4 V_541 ;
switch ( V_141 [ 0 ] ) {
case V_542 :
case V_543 :
V_539 = 1 ;
case V_544 :
case V_545 :
if ( * V_538 == 6 ) {
V_540 = F_243 ( & V_141 [ 2 ] ) ;
V_541 = V_141 [ 4 ] ;
if ( V_541 == 0 )
V_541 = 256 ;
} else {
F_76 ( * V_538 != 12 ) ;
V_540 = F_195 ( & V_141 [ 2 ] ) ;
V_541 = F_195 ( & V_141 [ 6 ] ) ;
}
if ( V_541 > 0xffff )
return V_546 ;
V_141 [ 0 ] = V_539 ? V_547 : V_548 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_540 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_540 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_540 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_540 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_541 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_541 ) ;
V_141 [ 9 ] = 0 ;
* V_538 = 10 ;
break;
}
return 0 ;
}
static int F_244 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_538 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
unsigned int V_50 ;
unsigned int V_549 = 0 ;
struct V_530 * V_269 ;
T_5 V_374 ;
int V_531 , V_68 ;
struct V_274 * V_535 ;
T_4 V_550 = V_551 ;
if ( F_159 ( V_284 ) > V_22 -> V_552 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_546 ;
}
F_76 ( V_284 -> V_553 > V_554 ) ;
if ( F_242 ( V_141 , & V_538 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_546 ;
}
V_9 -> V_150 = V_151 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_555 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
V_531 = F_239 ( V_284 ) ;
if ( V_531 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_531 ;
}
if ( V_531 ) {
V_535 = V_131 -> V_276 ;
F_240 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_236 ( V_269 ) ;
V_50 = F_237 ( V_269 ) ;
V_549 += V_50 ;
V_535 -> V_282 = F_134 ( V_374 ) ;
V_535 -> V_281 = F_139 ( V_50 ) ;
V_535 -> V_278 = F_139 ( 0 ) ;
V_535 ++ ;
}
( -- V_535 ) -> V_278 = F_139 ( V_376 ) ;
switch ( V_284 -> V_556 ) {
case V_557 :
V_550 |= V_558 ;
break;
case V_559 :
V_550 |= V_560 ;
break;
case V_561 :
V_550 |= V_562 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_556 ) ;
F_179 () ;
break;
}
} else {
V_550 |= V_562 ;
}
V_9 -> V_124 . V_125 = V_531 ;
V_131 -> V_563 = F_160 ( V_187 & 0xFFFF ) ;
V_131 -> V_564 = F_139 ( V_549 ) ;
V_131 -> V_346 = F_160 ( V_565 |
( V_538 & V_347 ) ) ;
V_131 -> V_550 = F_139 ( V_550 ) ;
memcpy ( V_131 -> V_145 , V_141 , V_538 ) ;
memcpy ( V_131 -> V_351 , V_72 , 8 ) ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
V_9 -> V_236 = V_30 ;
return F_246 ( V_22 , V_9 , V_30 -> V_187 ,
V_284 -> V_566 , V_284 -> V_553 , V_30 -> V_72 , V_30 ) ;
}
static void F_247 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_139 * V_131 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
T_5 V_567 ;
if ( ! ( F_97 ( V_222 -> V_78 ) & V_419 ) )
return;
V_131 -> V_420 = V_222 -> V_420 ;
V_131 -> V_568 |= V_569 ;
switch ( V_284 -> V_566 [ 0 ] ) {
case V_542 :
case V_544 :
V_567 = F_243 ( & V_284 -> V_566 [ 2 ] ) ;
break;
case V_547 :
case V_548 :
case V_543 :
case V_545 :
V_567 = F_195 ( & V_284 -> V_566 [ 2 ] ) ;
break;
case V_570 :
case V_571 :
V_567 = F_196 ( & V_284 -> V_566 [ 2 ] ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_167 ,
V_204 , V_284 -> V_566 [ 0 ] ) ;
F_179 () ;
break;
}
if ( F_131 ( V_222 -> V_412 ) != 512 )
V_567 = V_567 *
F_131 ( V_222 -> V_412 ) / 512 ;
V_131 -> V_572 = F_139 ( V_567 ) ;
V_131 -> V_573 = F_139 ( V_567 >> 32 ) ;
}
static int F_248 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_538 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_265 * V_535 ;
int V_531 , V_68 ;
struct V_530 * V_269 ;
T_5 V_374 ;
T_4 V_50 ;
T_4 V_549 = 0 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
if ( F_242 ( V_141 , & V_538 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_546 ;
}
V_9 -> V_150 = V_154 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_574 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_575 = V_576 ;
V_531 = F_239 ( V_284 ) ;
if ( V_531 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_531 ;
}
if ( V_531 ) {
V_535 = V_131 -> V_269 ;
if ( V_531 > V_22 -> V_552 ) {
V_374 = F_136 (
V_22 -> V_259 [ V_9 -> V_133 ] -> V_272 ) ;
V_535 -> V_272 = F_134 ( V_374 ) ;
V_535 -> V_270 = 0 ;
V_535 -> V_577 [ 0 ] = 0 ;
V_535 -> V_577 [ 1 ] = 0 ;
V_535 -> V_577 [ 2 ] = 0 ;
V_535 -> V_341 = 0x80 ;
V_535 = V_22 -> V_259 [ V_9 -> V_133 ] ;
}
F_240 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_236 ( V_269 ) ;
V_50 = F_237 ( V_269 ) ;
V_549 += V_50 ;
V_535 -> V_272 = F_134 ( V_374 ) ;
V_535 -> V_270 = F_139 ( V_50 ) ;
V_535 -> V_577 [ 0 ] = 0 ;
V_535 -> V_577 [ 1 ] = 0 ;
V_535 -> V_577 [ 2 ] = 0 ;
V_535 -> V_341 = 0 ;
V_535 ++ ;
}
switch ( V_284 -> V_556 ) {
case V_557 :
V_131 -> V_568 &= ~ V_578 ;
V_131 -> V_568 |= V_579 ;
break;
case V_559 :
V_131 -> V_568 &= ~ V_578 ;
V_131 -> V_568 |= V_580 ;
break;
case V_561 :
V_131 -> V_568 &= ~ V_578 ;
V_131 -> V_568 |= V_581 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_556 ) ;
F_179 () ;
break;
}
} else {
V_131 -> V_568 &= ~ V_578 ;
V_131 -> V_568 |= V_581 ;
}
F_247 ( V_22 , V_9 , V_131 ) ;
V_131 -> V_488 = F_139 ( V_187 ) ;
V_131 -> V_582 = F_139 ( V_9 -> V_133 << V_583 ) ;
memcpy ( V_131 -> V_141 , V_141 , sizeof( V_131 -> V_141 ) ) ;
V_131 -> V_286 = F_139 ( V_549 ) ;
V_131 -> V_584 = F_134 ( V_9 -> V_122 +
F_249 ( struct V_139 , V_289 ) ) ;
V_131 -> V_585 = F_139 ( sizeof( V_131 -> V_289 ) ) ;
if ( V_531 > V_22 -> V_552 ) {
V_131 -> V_140 = 1 ;
V_131 -> V_269 [ 0 ] . V_270 = F_139 ( V_531 * sizeof( V_131 -> V_269 [ 0 ] ) ) ;
if ( F_130 ( V_22 , V_131 , V_9 ) ) {
F_46 ( & V_236 -> V_256 ) ;
F_158 ( V_284 ) ;
return - 1 ;
}
} else
V_131 -> V_140 = ( T_1 ) V_531 ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_538 ,
T_1 * V_72 , struct V_73 * V_236 )
{
if ( F_104 ( & V_236 -> V_256 ) >
V_236 -> V_190 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_546 ;
}
if ( V_22 -> V_63 & V_114 )
return F_244 ( V_22 , V_9 , V_187 ,
V_141 , V_538 , V_72 ,
V_236 ) ;
else
return F_248 ( V_22 , V_9 , V_187 ,
V_141 , V_538 , V_72 ,
V_236 ) ;
}
static void F_250 ( struct V_221 * V_222 ,
int V_189 , T_4 * V_586 , T_4 * V_587 )
{
if ( V_189 == 0 ) {
* V_586 %= F_97 ( V_222 -> V_227 ) ;
return;
}
do {
* V_587 = * V_586 /
F_97 ( V_222 -> V_227 ) ;
if ( V_189 == * V_587 )
continue;
if ( * V_587 < F_97 ( V_222 -> V_231 ) - 1 ) {
* V_586 += F_97 ( V_222 -> V_227 ) ;
( * V_587 ) ++ ;
} else {
* V_586 %= F_97 ( V_222 -> V_227 ) ;
* V_587 = 0 ;
}
} while ( V_189 != * V_587 );
}
static int F_251 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_539 = 0 ;
T_4 V_586 ;
T_5 V_567 , V_588 ;
T_4 V_541 ;
T_4 V_589 ;
T_5 V_590 , V_591 ;
T_4 V_592 , V_593 ;
T_4 V_594 , V_595 ;
T_5 V_596 , V_597 ;
T_4 V_598 ;
T_5 V_599 , V_600 ;
T_4 V_601 , V_602 ;
T_4 V_603 , V_604 ;
T_4 V_226 ;
T_4 V_605 ;
T_4 V_606 , V_607 , V_587 ;
T_4 V_608 ;
T_4 V_609 ;
T_5 V_610 ;
T_4 V_611 ;
T_1 V_141 [ 16 ] ;
T_1 V_538 ;
T_6 V_416 ;
#if V_612 == 32
T_5 V_613 ;
#endif
int V_189 ;
switch ( V_284 -> V_566 [ 0 ] ) {
case V_542 :
V_539 = 1 ;
case V_544 :
V_567 = F_243 ( & V_284 -> V_566 [ 2 ] ) ;
V_541 = V_284 -> V_566 [ 4 ] ;
if ( V_541 == 0 )
V_541 = 256 ;
break;
case V_547 :
V_539 = 1 ;
case V_548 :
V_567 =
( ( ( T_5 ) V_284 -> V_566 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_566 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_566 [ 4 ] ) << 8 ) |
V_284 -> V_566 [ 5 ] ;
V_541 =
( ( ( T_4 ) V_284 -> V_566 [ 7 ] ) << 8 ) |
V_284 -> V_566 [ 8 ] ;
break;
case V_543 :
V_539 = 1 ;
case V_545 :
V_567 =
( ( ( T_5 ) V_284 -> V_566 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_566 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_566 [ 4 ] ) << 8 ) |
V_284 -> V_566 [ 5 ] ;
V_541 =
( ( ( T_4 ) V_284 -> V_566 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_566 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_566 [ 8 ] ) << 8 ) |
V_284 -> V_566 [ 9 ] ;
break;
case V_570 :
V_539 = 1 ;
case V_571 :
V_567 =
( ( ( T_5 ) V_284 -> V_566 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_284 -> V_566 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_284 -> V_566 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_284 -> V_566 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_284 -> V_566 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_566 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_566 [ 8 ] ) << 8 ) |
V_284 -> V_566 [ 9 ] ;
V_541 =
( ( ( T_4 ) V_284 -> V_566 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_566 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_566 [ 12 ] ) << 8 ) |
V_284 -> V_566 [ 13 ] ;
break;
default:
return V_546 ;
}
V_588 = V_567 + V_541 - 1 ;
if ( V_539 && V_30 -> V_83 != 0 )
return V_546 ;
if ( V_588 >= F_136 ( V_222 -> V_413 ) ||
V_588 < V_567 )
return V_546 ;
V_589 = F_97 ( V_222 -> V_227 ) *
F_97 ( V_222 -> V_416 ) ;
V_416 = F_97 ( V_222 -> V_416 ) ;
#if V_612 == 32
V_613 = V_567 ;
( void ) F_252 ( V_613 , V_589 ) ;
V_590 = V_613 ;
V_613 = V_588 ;
( void ) F_252 ( V_613 , V_589 ) ;
V_591 = V_613 ;
V_592 = ( T_4 ) ( V_567 - ( V_590 * V_589 ) ) ;
V_593 = ( T_4 ) ( V_588 - ( V_591 * V_589 ) ) ;
V_613 = V_592 ;
( void ) F_252 ( V_613 , V_416 ) ;
V_594 = V_613 ;
V_613 = V_593 ;
( void ) F_252 ( V_613 , V_416 ) ;
V_595 = V_613 ;
#else
V_590 = V_567 / V_589 ;
V_591 = V_588 / V_589 ;
V_592 = ( T_4 ) ( V_567 - ( V_590 * V_589 ) ) ;
V_593 = ( T_4 ) ( V_588 - ( V_591 * V_589 ) ) ;
V_594 = V_592 / V_416 ;
V_595 = V_593 / V_416 ;
#endif
if ( ( V_590 != V_591 ) || ( V_594 != V_595 ) )
return V_546 ;
V_226 = F_97 ( V_222 -> V_227 ) +
F_97 ( V_222 -> V_228 ) ;
V_608 = ( ( T_4 ) ( V_590 >> V_222 -> V_415 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_586 = ( V_608 * V_226 ) + V_594 ;
switch ( V_30 -> V_83 ) {
case V_614 :
break;
case V_615 :
F_76 ( F_97 ( V_222 -> V_231 ) != 2 ) ;
if ( V_30 -> V_189 )
V_586 += F_97 ( V_222 -> V_227 ) ;
V_30 -> V_189 = ! V_30 -> V_189 ;
break;
case V_616 :
F_76 ( F_97 ( V_222 -> V_231 ) != 3 ) ;
V_189 = V_30 -> V_189 ;
F_250 ( V_222 , V_189 ,
& V_586 , & V_587 ) ;
V_189 =
( V_189 >=
F_97 ( V_222 -> V_231 ) - 1 )
? 0 : V_189 + 1 ;
V_30 -> V_189 = V_189 ;
break;
case V_617 :
case V_618 :
if ( F_97 ( V_222 -> V_231 ) <= 1 )
break;
V_598 =
F_97 ( V_222 -> V_416 ) *
F_97 ( V_222 -> V_227 ) ;
F_76 ( V_598 == 0 ) ;
V_605 = V_598 *
F_97 ( V_222 -> V_231 ) ;
#if V_612 == 32
V_613 = V_567 ;
V_606 = F_252 ( V_613 , V_605 ) ;
V_613 = V_606 ;
( void ) F_252 ( V_613 , V_598 ) ;
V_606 = V_613 ;
V_613 = V_588 ;
V_607 = F_252 ( V_613 , V_605 ) ;
V_613 = V_607 ;
( void ) F_252 ( V_613 , V_598 ) ;
V_607 = V_613 ;
#else
V_606 = ( V_567 % V_605 ) / V_598 ;
V_607 = ( V_588 % V_605 ) / V_598 ;
#endif
if ( V_606 != V_607 )
return V_546 ;
#if V_612 == 32
V_613 = V_567 ;
( void ) F_252 ( V_613 , V_605 ) ;
V_590 = V_599 = V_596 = V_613 ;
V_613 = V_588 ;
( void ) F_252 ( V_613 , V_605 ) ;
V_600 = V_597 = V_613 ;
#else
V_590 = V_599 = V_596 =
V_567 / V_605 ;
V_600 = V_597 = V_588 / V_605 ;
#endif
if ( V_599 != V_600 )
return V_546 ;
#if V_612 == 32
V_613 = V_567 ;
V_592 = F_252 ( V_613 , V_605 ) ;
V_613 = V_592 ;
V_592 = ( T_4 ) F_252 ( V_613 , V_598 ) ;
V_601 = V_592 ;
V_613 = V_588 ;
V_602 = F_252 ( V_613 , V_605 ) ;
V_613 = V_602 ;
V_602 = F_252 ( V_613 , V_598 ) ;
V_613 = V_601 ;
( void ) F_252 ( V_613 , V_222 -> V_416 ) ;
V_594 = V_603 = V_613 ;
V_613 = V_602 ;
( void ) F_252 ( V_613 , V_222 -> V_416 ) ;
V_604 = V_613 ;
#else
V_592 = V_601 =
( T_4 ) ( ( V_567 % V_605 ) %
V_598 ) ;
V_602 =
( T_4 ) ( ( V_588 % V_605 ) %
V_598 ) ;
V_594 = V_603 =
V_601 / F_97 ( V_222 -> V_416 ) ;
V_604 =
V_602 / F_97 ( V_222 -> V_416 ) ;
#endif
if ( V_603 != V_604 )
return V_546 ;
V_608 = ( ( T_4 ) ( V_590 >> V_222 -> V_415 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_586 = ( V_606 *
( F_97 ( V_222 -> V_230 ) * V_226 ) ) +
( V_608 * V_226 ) + V_594 ;
break;
default:
return V_546 ;
}
if ( F_45 ( V_586 >= V_234 ) )
return V_546 ;
V_9 -> V_236 = V_30 -> V_236 [ V_586 ] ;
if ( ! V_9 -> V_236 )
return V_546 ;
V_609 = V_224 [ V_586 ] . V_187 ;
V_610 = F_136 ( V_222 -> V_417 ) +
V_590 * F_97 ( V_222 -> V_416 ) +
( V_592 - V_594 *
F_97 ( V_222 -> V_416 ) ) ;
V_611 = V_541 ;
if ( V_222 -> V_414 ) {
V_610 <<= V_222 -> V_414 ;
V_611 <<= V_222 -> V_414 ;
}
F_76 ( V_611 > 0xffff ) ;
if ( V_610 > 0xffffffff ) {
V_141 [ 0 ] = V_539 ? V_570 : V_571 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_610 >> 56 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_610 >> 48 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_610 >> 40 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_610 >> 32 ) ;
V_141 [ 6 ] = ( T_1 ) ( V_610 >> 24 ) ;
V_141 [ 7 ] = ( T_1 ) ( V_610 >> 16 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_610 >> 8 ) ;
V_141 [ 9 ] = ( T_1 ) ( V_610 ) ;
V_141 [ 10 ] = ( T_1 ) ( V_611 >> 24 ) ;
V_141 [ 11 ] = ( T_1 ) ( V_611 >> 16 ) ;
V_141 [ 12 ] = ( T_1 ) ( V_611 >> 8 ) ;
V_141 [ 13 ] = ( T_1 ) ( V_611 ) ;
V_141 [ 14 ] = 0 ;
V_141 [ 15 ] = 0 ;
V_538 = 16 ;
} else {
V_141 [ 0 ] = V_539 ? V_547 : V_548 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_610 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_610 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_610 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_610 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_611 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_611 ) ;
V_141 [ 9 ] = 0 ;
V_538 = 10 ;
}
return F_246 ( V_22 , V_9 , V_609 , V_141 , V_538 ,
V_30 -> V_72 ,
V_30 -> V_236 [ V_586 ] ) ;
}
static int F_253 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char V_72 [] )
{
V_284 -> V_619 = ( unsigned char * ) V_9 ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_9 -> V_124 . V_128 = 0 ;
memcpy ( & V_9 -> V_124 . V_349 . V_350 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_124 . V_348 = F_134 ( ( V_9 -> V_133 << V_583 ) ) ;
V_9 -> V_144 . V_620 = 0 ;
F_76 ( V_284 -> V_553 > sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_345 = V_284 -> V_553 ;
memcpy ( V_9 -> V_144 . V_145 , V_284 -> V_566 , V_284 -> V_553 ) ;
switch ( V_284 -> V_556 ) {
case V_557 :
V_9 -> V_144 . V_621 =
F_254 ( V_393 , V_622 , V_623 ) ;
break;
case V_559 :
V_9 -> V_144 . V_621 =
F_254 ( V_393 , V_622 , V_624 ) ;
break;
case V_561 :
V_9 -> V_144 . V_621 =
F_254 ( V_393 , V_622 , V_625 ) ;
break;
case V_626 :
V_9 -> V_144 . V_621 =
F_254 ( V_393 , V_622 , V_627 ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_166 ,
V_284 -> V_556 ) ;
F_179 () ;
break;
}
if ( F_238 ( V_22 , V_9 , V_284 ) < 0 ) {
F_147 ( V_22 , V_9 ) ;
return V_628 ;
}
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_255 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_629 , V_630 ;
memset ( V_9 , 0 , F_249 ( struct V_8 , V_240 ) ) ;
V_9 -> V_124 . V_348 = F_134 ( ( T_5 ) ( V_199 << V_583 ) ) ;
V_629 = V_22 -> V_631 + V_199 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_632 + V_199 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_630 = V_22 -> V_633
+ V_199 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_133 = V_199 ;
V_9 -> V_122 = ( T_4 ) V_629 ;
V_9 -> V_634 . V_282 = F_134 ( ( T_5 ) V_630 ) ;
V_9 -> V_634 . V_281 = F_139 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_256 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
F_255 ( V_22 , V_68 , V_9 ) ;
F_122 ( & V_9 -> V_240 , 0 ) ;
}
}
static inline void F_257 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_629 = V_22 -> V_631 + V_199 * sizeof( * V_9 ) ;
F_76 ( V_9 -> V_133 != V_199 ) ;
memset ( V_9 -> V_144 . V_145 , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_122 = ( T_4 ) V_629 ;
}
static int F_258 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
int V_21 = V_546 ;
V_284 -> V_619 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_91 ) {
F_255 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_251 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_628 ;
} else if ( V_30 -> V_188 ) {
F_255 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_245 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_628 ;
}
return V_21 ;
}
static void V_326 ( struct V_635 * V_325 )
{
struct V_283 * V_284 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_259 ( V_325 , struct V_8 , V_325 ) ;
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
V_21 = F_258 ( V_22 , V_9 , V_284 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_628 ) {
V_284 -> V_294 = V_636 << 16 ;
return F_149 ( V_22 , V_9 , V_284 ) ;
}
}
}
F_257 ( V_9 -> V_22 , V_9 -> V_133 , V_9 ) ;
if ( F_253 ( V_9 -> V_22 , V_9 , V_284 , V_30 -> V_72 ) ) {
V_284 -> V_294 = V_636 << 16 ;
V_284 -> V_324 ( V_284 ) ;
}
}
static int F_260 ( struct V_6 * V_7 , struct V_283 * V_284 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_284 -> V_42 ) ;
F_76 ( V_284 -> V_637 -> V_348 < 0 ) ;
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
V_9 = F_261 ( V_22 , V_284 ) ;
if ( F_48 ( V_284 -> V_638 == 0 &&
V_284 -> V_637 -> V_150 == V_639 &&
V_22 -> V_56 ) ) {
V_21 = F_258 ( V_22 , V_9 , V_284 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_628 ) {
F_147 ( V_22 , V_9 ) ;
return V_628 ;
}
}
return F_253 ( V_22 , V_9 , V_284 , V_72 ) ;
}
static void F_262 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_640 , V_78 ) ;
V_22 -> V_641 = 1 ;
F_146 ( & V_22 -> V_642 ) ;
F_36 ( & V_22 -> V_640 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_262 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_640 , V_78 ) ;
if ( V_22 -> V_641 )
break;
F_36 ( & V_22 -> V_640 , V_78 ) ;
F_182 ( V_22 -> V_642 , V_22 -> V_641 ) ;
}
V_22 -> V_641 = 0 ;
F_36 ( & V_22 -> V_640 , V_78 ) ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_262 ( V_22 ) ;
F_233 ( V_22 ) ;
F_262 ( V_22 ) ;
}
static int F_263 ( struct V_2 * V_3 , int V_233 )
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
static int F_264 ( struct V_6 * V_7 ,
unsigned long V_643 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_644 ;
F_35 ( & V_22 -> V_640 , V_78 ) ;
V_644 = V_22 -> V_641 ;
F_36 ( & V_22 -> V_640 , V_78 ) ;
return V_644 ;
}
static int F_265 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_266 ( & V_645 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_168 ) ;
return - V_261 ;
}
V_7 -> V_646 = 0 ;
V_7 -> V_647 = 0 ;
V_7 -> V_648 = - 1 ;
V_7 -> V_649 = 3 ;
V_7 -> V_650 = V_651 ;
V_7 -> V_652 = V_496 ;
V_7 -> V_653 = V_496 ;
V_7 -> V_258 = V_22 -> V_237 - V_654 ;
V_7 -> V_655 = V_7 -> V_258 ;
V_7 -> V_656 = V_22 -> V_262 ;
V_7 -> V_657 = V_658 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_659 = V_22 -> V_660 [ V_22 -> V_661 ] ;
V_7 -> V_662 = V_7 -> V_659 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_267 ( struct V_1 * V_22 )
{
int V_663 ;
V_663 = F_268 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_663 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_169 ) ;
return V_663 ;
}
F_269 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_270 ( struct V_283 * V_664 )
{
int V_665 = V_664 -> V_637 -> V_348 ;
if ( V_665 < 0 )
return V_665 ;
return V_665 += V_654 ;
}
static int F_271 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_666 [] ,
int V_113 )
{
int V_21 ;
( void ) F_177 ( V_9 , V_473 , V_22 ,
NULL , 0 , 0 , V_666 , V_393 ) ;
V_21 = F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_667 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_295 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_668 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_272 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_666 [] , int V_113 )
{
int V_21 ;
int V_48 = 0 ;
int V_669 = 1 ;
for ( V_48 = 0 ; V_48 < V_670 ; V_48 ++ ) {
F_108 ( 1000 * V_669 ) ;
V_21 = F_271 ( V_22 , V_9 , V_666 , V_113 ) ;
if ( ! V_21 )
break;
if ( V_669 < V_671 )
V_669 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_170 ,
V_669 ) ;
}
return V_21 ;
}
static int F_273 ( struct V_1 * V_22 ,
unsigned char V_666 [] ,
int V_113 )
{
int V_672 ;
int V_673 ;
int V_112 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
if ( V_113 == V_127 ) {
V_672 = 0 ;
V_673 = V_22 -> V_129 - 1 ;
} else {
V_672 = V_113 ;
V_673 = V_113 ;
}
for ( V_112 = V_672 ; V_112 <= V_673 ; V_112 ++ ) {
V_21 = F_272 ( V_22 , V_9 , V_666 , V_112 ) ;
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
static int F_274 ( struct V_283 * V_674 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_397 ;
char V_675 [ 48 ] ;
V_22 = F_1 ( V_674 -> V_42 ) ;
if ( V_22 == NULL )
return V_676 ;
if ( F_13 ( V_22 ) )
return V_676 ;
V_30 = V_674 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_173 , V_204 ) ;
return V_676 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_675 , sizeof( V_675 ) ,
L_174 ,
F_270 ( V_674 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_675 ) ;
return V_676 ;
}
if ( F_275 ( V_22 ) ) {
snprintf ( V_675 , sizeof( V_675 ) ,
L_175 ,
F_270 ( V_674 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_675 ) ;
return V_676 ;
}
if ( F_63 ( V_30 -> V_72 ) )
return V_677 ;
if ( F_31 ( V_30 -> V_72 ) )
V_397 = V_678 ;
else
V_397 = V_679 ;
sprintf ( V_675 , L_176 ,
V_397 == V_678 ? L_177 : L_178 ) ;
F_70 ( V_243 , V_22 , V_30 , V_675 ) ;
V_22 -> V_248 = 1 ;
V_21 = F_180 ( V_22 , V_30 , V_30 -> V_72 , V_397 ,
V_127 ) ;
sprintf ( V_675 , L_179 ,
V_397 == V_678 ? L_177 : L_178 ,
V_21 == 0 ? L_180 : L_181 ) ;
F_70 ( V_243 , V_22 , V_30 , V_675 ) ;
V_22 -> V_248 = 0 ;
return V_21 == 0 ? V_677 : V_676 ;
}
static void F_276 ( T_1 * V_348 )
{
T_1 V_680 [ 8 ] ;
memcpy ( V_680 , V_348 , 8 ) ;
V_348 [ 0 ] = V_680 [ 3 ] ;
V_348 [ 1 ] = V_680 [ 2 ] ;
V_348 [ 2 ] = V_680 [ 1 ] ;
V_348 [ 3 ] = V_680 [ 0 ] ;
V_348 [ 4 ] = V_680 [ 7 ] ;
V_348 [ 5 ] = V_680 [ 6 ] ;
V_348 [ 6 ] = V_680 [ 5 ] ;
V_348 [ 7 ] = V_680 [ 4 ] ;
}
static void F_277 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_681 , T_7 * V_682 )
{
T_5 V_348 ;
if ( V_9 -> V_150 == V_151 ) {
struct V_130 * V_683 = (struct V_130 * )
& V_22 -> V_132 [ V_9 -> V_133 ] ;
V_348 = F_136 ( V_683 -> V_348 ) ;
* V_682 = F_139 ( V_348 >> 32 ) ;
* V_681 = F_139 ( V_348 ) ;
return;
}
if ( V_9 -> V_150 == V_154 ) {
struct V_139 * V_684 = (struct V_139 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
memset ( V_682 , 0 , sizeof( * V_682 ) ) ;
* V_681 = V_684 -> V_582 ;
return;
}
V_348 = F_136 ( V_9 -> V_124 . V_348 ) ;
* V_682 = F_139 ( V_348 >> 32 ) ;
* V_681 = F_139 ( V_348 ) ;
}
static int F_278 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
T_7 V_682 , V_681 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_475 , V_22 , & abort -> V_124 . V_348 ,
0 , 0 , V_72 , V_398 ) ;
if ( V_22 -> V_71 )
F_276 ( & V_9 -> V_144 . V_145 [ 4 ] ) ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_277 ( V_22 , abort , & V_681 , & V_682 ) ;
F_279 ( & V_22 -> V_29 -> V_30 , L_182 ,
V_204 , V_682 , V_681 ) ;
V_338 = V_9 -> V_24 ;
switch ( V_338 -> V_36 ) {
case V_667 :
break;
case V_368 :
V_21 = F_156 ( V_22 , V_9 ) ;
break;
case V_367 :
V_21 = - 1 ;
break;
default:
F_279 ( & V_22 -> V_29 -> V_30 , L_183 ,
V_204 , V_682 , V_681 ) ;
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_106 ( V_22 , V_9 ) ;
F_279 ( & V_22 -> V_29 -> V_30 , L_184 ,
V_204 , V_682 , V_681 ) ;
return V_21 ;
}
static void F_280 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_685 , int V_113 )
{
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_400 = (struct V_136 * ) V_285 ;
struct V_139 * V_686 =
& V_22 -> V_137 [ V_685 -> V_133 ] ;
struct V_283 * V_664 = V_685 -> V_10 ;
struct V_73 * V_30 = V_664 -> V_42 -> V_80 ;
F_281 ( sizeof( struct V_136 ) >
sizeof( struct V_139 ) ) ;
F_76 ( F_249 ( struct V_139 , V_289 ) <
F_249 ( struct V_136 , V_687 ) +
sizeof( V_400 -> V_687 ) ) ;
V_9 -> V_150 = V_156 ;
V_9 -> V_10 = V_688 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_574 +
( V_9 -> V_133 * sizeof( struct V_139 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_400 , 0 , sizeof( * V_285 ) ) ;
V_400 -> V_689 = V_690 ;
V_400 -> V_113 = V_113 ;
V_400 -> V_691 = V_692 ;
V_400 -> V_402 = F_139 ( V_30 -> V_187 ) ;
memset ( V_400 -> V_693 , 0 , sizeof( V_400 -> V_693 ) ) ;
V_400 -> V_348 = F_134 ( V_9 -> V_133 << V_583 ) ;
V_400 -> V_694 = F_134 ( F_131 ( V_686 -> V_582 ) ) ;
V_400 -> V_695 = F_134 ( V_9 -> V_122 +
F_249 ( struct V_139 , V_289 ) ) ;
V_400 -> V_687 = F_139 ( sizeof( V_285 -> V_289 ) ) ;
}
static int F_282 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_283 * V_664 ;
struct V_73 * V_30 ;
unsigned char V_696 [ 8 ] ;
unsigned char * V_697 = & V_696 [ 0 ] ;
V_664 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_664 -> V_42 -> V_80 ) ;
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
if ( ! F_221 ( V_22 , abort , V_697 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_189 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_190 ,
V_697 [ 0 ] , V_697 [ 1 ] , V_697 [ 2 ] , V_697 [ 3 ] ,
V_697 [ 4 ] , V_697 [ 5 ] , V_697 [ 6 ] , V_697 [ 7 ] ) ;
V_21 = F_180 ( V_22 , V_30 , V_697 , V_698 , V_113 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_697 [ 0 ] , V_697 [ 1 ] , V_697 [ 2 ] , V_697 [ 3 ] ,
V_697 [ 4 ] , V_697 [ 5 ] , V_697 [ 6 ] , V_697 [ 7 ] ) ;
return V_21 ;
}
if ( F_273 ( V_22 , V_697 , V_113 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_697 [ 0 ] , V_697 [ 1 ] , V_697 [ 2 ] , V_697 [ 3 ] ,
V_697 [ 4 ] , V_697 [ 5 ] , V_697 [ 6 ] , V_697 [ 7 ] ) ;
return - 1 ;
}
F_95 ( & V_22 -> V_29 -> V_30 ,
L_193 ,
V_697 [ 0 ] , V_697 [ 1 ] , V_697 [ 2 ] , V_697 [ 3 ] ,
V_697 [ 4 ] , V_697 [ 5 ] , V_697 [ 6 ] , V_697 [ 7 ] ) ;
return V_21 ;
}
static int F_283 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
T_7 V_681 , V_682 ;
struct V_73 * V_30 ;
struct V_139 * V_285 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 -> V_91 && ! V_30 -> V_188 )
return - 1 ;
V_9 = F_176 ( V_22 ) ;
F_280 ( V_9 , V_22 , abort , V_113 ) ;
V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_277 ( V_22 , abort , & V_681 , & V_682 ) ;
F_279 ( & V_22 -> V_29 -> V_30 ,
L_194 ,
V_204 , V_682 , V_681 ) ;
F_279 ( & V_22 -> V_29 -> V_30 ,
L_195 ,
V_204 , V_682 , V_681 , V_285 -> V_289 . V_290 ) ;
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
V_204 , V_682 , V_681 ,
V_285 -> V_289 . V_290 ) ;
V_21 = - 1 ;
}
F_106 ( V_22 , V_9 ) ;
F_279 ( & V_22 -> V_29 -> V_30 , L_184 , V_204 ,
V_682 , V_681 ) ;
return V_21 ;
}
static int F_284 ( struct V_1 * V_22 ,
struct V_73 * V_30 , struct V_8 * abort , int V_113 )
{
if ( abort -> V_150 == V_154 ) {
if ( ( V_699 & V_22 -> V_700 ) ||
V_30 -> V_74 )
return F_283 ( V_22 , abort ,
V_113 ) ;
else
return F_282 ( V_22 ,
V_30 -> V_72 ,
abort , V_113 ) ;
}
return F_278 ( V_22 , V_30 -> V_72 , abort , V_113 ) ;
}
static int F_285 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_150 == V_154 )
return V_22 -> V_137 [ V_9 -> V_133 ] . V_113 ;
return V_9 -> V_124 . V_128 ;
}
static inline int F_286 ( struct V_1 * V_22 )
{
#define F_287 5000
return ! F_288 ( V_22 -> V_701 ,
F_289 ( & V_22 -> V_702 ) >= 0 ,
F_167 ( F_287 ) ) ;
}
static int F_290 ( struct V_283 * V_703 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_283 * V_704 ;
char V_675 [ 256 ] ;
int V_705 = 0 ;
T_7 V_682 , V_681 ;
int V_240 , V_113 ;
if ( V_703 == NULL )
return V_676 ;
if ( V_703 -> V_42 == NULL )
return V_676 ;
V_22 = F_1 ( V_703 -> V_42 ) ;
if ( V_22 == NULL )
return V_676 ;
V_30 = V_703 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_197 ,
V_675 ) ;
return V_676 ;
}
if ( F_13 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_198 ) ;
return V_676 ;
}
if ( F_275 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_199 ) ;
return V_676 ;
}
if ( ! ( V_706 & V_22 -> V_700 ) &&
! ( V_707 & V_22 -> V_700 ) )
return V_676 ;
memset ( V_675 , 0 , sizeof( V_675 ) ) ;
V_705 += sprintf ( V_675 + V_705 , L_200 ,
V_22 -> V_59 -> V_102 , V_703 -> V_42 -> V_708 ,
V_703 -> V_42 -> V_709 , V_703 -> V_42 -> V_105 ,
L_201 , V_703 ) ;
abort = (struct V_8 * ) V_703 -> V_619 ;
if ( abort == NULL ) {
return V_677 ;
}
V_240 = F_104 ( & abort -> V_240 ) ;
if ( V_240 == 1 ) {
F_106 ( V_22 , abort ) ;
return V_677 ;
}
if ( abort -> V_150 != V_154 &&
abort -> V_150 != V_151 && ! V_30 -> V_482 ) {
F_106 ( V_22 , abort ) ;
return V_676 ;
}
if ( abort -> V_10 != V_703 ) {
F_106 ( V_22 , abort ) ;
return V_677 ;
}
abort -> V_12 = true ;
F_277 ( V_22 , abort , & V_681 , & V_682 ) ;
V_113 = F_285 ( V_22 , abort ) ;
V_705 += sprintf ( V_675 + V_705 , L_202 , V_682 , V_681 ) ;
V_704 = abort -> V_10 ;
if ( V_704 != NULL )
V_705 += sprintf ( V_675 + V_705 ,
L_203 ,
V_704 -> V_553 , V_704 -> V_566 [ 0 ] , V_704 -> V_566 [ 1 ] ,
V_704 -> V_710 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_204 , V_675 ) ;
F_70 ( V_243 , V_22 , V_30 , L_201 ) ;
if ( F_286 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_205 ,
V_675 ) ;
F_106 ( V_22 , abort ) ;
return V_676 ;
}
V_21 = F_284 ( V_22 , V_30 , abort , V_113 ) ;
F_56 ( & V_22 -> V_702 ) ;
F_146 ( & V_22 -> V_701 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_206 , V_675 ) ;
F_70 ( V_243 , V_22 , V_30 ,
L_207 ) ;
F_106 ( V_22 , abort ) ;
return V_676 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_208 , V_675 ) ;
F_182 ( V_22 -> V_323 ,
abort -> V_10 != V_703 || F_13 ( V_22 ) ) ;
F_106 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_677 : V_676 ;
}
static struct V_8 * F_261 ( struct V_1 * V_22 ,
struct V_283 * V_664 )
{
int V_665 = F_270 ( V_664 ) ;
struct V_8 * V_9 = V_22 -> V_239 + V_665 ;
if ( V_665 < V_654 || V_665 >= V_22 -> V_237 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_209 ,
V_665 , V_654 , V_22 -> V_237 - 1 ) ;
F_179 () ;
}
F_56 ( & V_9 -> V_240 ) ;
if ( F_45 ( ! F_4 ( V_9 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_210 ,
V_665 ) ;
if ( V_9 -> V_10 != NULL )
F_291 ( V_9 -> V_10 ) ;
F_291 ( V_664 ) ;
}
F_257 ( V_22 , V_665 , V_9 ) ;
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
int V_711 = 0 ;
for (; ; ) {
V_68 = F_292 ( V_22 -> V_712 ,
V_654 ,
V_711 ) ;
if ( F_45 ( V_68 >= V_654 ) ) {
V_711 = 0 ;
continue;
}
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( F_45 ( V_240 > 1 ) ) {
F_106 ( V_22 , V_9 ) ;
V_711 = ( V_68 + 1 ) % V_654 ;
continue;
}
F_293 ( V_68 & ( V_612 - 1 ) ,
V_22 -> V_712 + ( V_68 / V_612 ) ) ;
break;
}
F_257 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_106 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_58 ( & V_9 -> V_240 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_239 ;
F_294 ( V_68 & ( V_612 - 1 ) ,
V_22 -> V_712 + ( V_68 / V_612 ) ) ;
}
}
static int F_295 ( struct V_2 * V_30 , int V_284 ,
void T_8 * V_713 )
{
T_9 T_8 * V_714 =
( T_9 T_8 * ) V_713 ;
T_10 V_715 ;
T_10 T_8 * V_716 = F_296 ( sizeof( V_715 ) ) ;
int V_717 ;
T_4 V_131 ;
memset ( & V_715 , 0 , sizeof( V_715 ) ) ;
V_717 = 0 ;
V_717 |= F_297 ( & V_715 . V_718 , & V_714 -> V_718 ,
sizeof( V_715 . V_718 ) ) ;
V_717 |= F_297 ( & V_715 . V_144 , & V_714 -> V_144 ,
sizeof( V_715 . V_144 ) ) ;
V_717 |= F_297 ( & V_715 . V_719 , & V_714 -> V_719 ,
sizeof( V_715 . V_719 ) ) ;
V_717 |= F_298 ( V_715 . V_720 , & V_714 -> V_720 ) ;
V_717 |= F_298 ( V_131 , & V_714 -> V_45 ) ;
V_715 . V_45 = F_299 ( V_131 ) ;
V_717 |= F_300 ( V_716 , & V_715 , sizeof( V_715 ) ) ;
if ( V_717 )
return - V_721 ;
V_717 = F_301 ( V_30 , V_722 , V_716 ) ;
if ( V_717 )
return V_717 ;
V_717 |= F_302 ( & V_714 -> V_719 , & V_716 -> V_719 ,
sizeof( V_714 -> V_719 ) ) ;
if ( V_717 )
return - V_721 ;
return V_717 ;
}
static int F_303 ( struct V_2 * V_30 ,
int V_284 , void T_8 * V_713 )
{
T_11 T_8 * V_714 =
( T_11 T_8 * ) V_713 ;
T_12 V_715 ;
T_12 T_8 * V_716 =
F_296 ( sizeof( V_715 ) ) ;
int V_717 ;
T_4 V_131 ;
memset ( & V_715 , 0 , sizeof( V_715 ) ) ;
V_717 = 0 ;
V_717 |= F_297 ( & V_715 . V_718 , & V_714 -> V_718 ,
sizeof( V_715 . V_718 ) ) ;
V_717 |= F_297 ( & V_715 . V_144 , & V_714 -> V_144 ,
sizeof( V_715 . V_144 ) ) ;
V_717 |= F_297 ( & V_715 . V_719 , & V_714 -> V_719 ,
sizeof( V_715 . V_719 ) ) ;
V_717 |= F_298 ( V_715 . V_720 , & V_714 -> V_720 ) ;
V_717 |= F_298 ( V_715 . V_723 , & V_714 -> V_723 ) ;
V_717 |= F_298 ( V_131 , & V_714 -> V_45 ) ;
V_715 . V_45 = F_299 ( V_131 ) ;
V_717 |= F_300 ( V_716 , & V_715 , sizeof( V_715 ) ) ;
if ( V_717 )
return - V_721 ;
V_717 = F_301 ( V_30 , V_724 , V_716 ) ;
if ( V_717 )
return V_717 ;
V_717 |= F_302 ( & V_714 -> V_719 , & V_716 -> V_719 ,
sizeof( V_714 -> V_719 ) ) ;
if ( V_717 )
return - V_721 ;
return V_717 ;
}
static int F_304 ( struct V_2 * V_30 , int V_284 , void T_8 * V_713 )
{
switch ( V_284 ) {
case V_725 :
case V_726 :
case V_727 :
case V_728 :
case V_729 :
case V_730 :
case V_731 :
case V_732 :
case V_733 :
case V_734 :
case V_735 :
case V_736 :
case V_737 :
case V_738 :
case V_739 :
return F_301 ( V_30 , V_284 , V_713 ) ;
case V_740 :
return F_295 ( V_30 , V_284 , V_713 ) ;
case V_741 :
return F_303 ( V_30 , V_284 , V_713 ) ;
default:
return - V_742 ;
}
}
static int F_305 ( struct V_1 * V_22 , void T_8 * V_743 )
{
struct V_744 V_745 ;
if ( ! V_743 )
return - V_55 ;
V_745 . V_746 = F_306 ( V_22 -> V_29 -> V_103 ) ;
V_745 . V_103 = V_22 -> V_29 -> V_103 -> V_747 ;
V_745 . V_748 = V_22 -> V_29 -> V_749 ;
V_745 . V_67 = V_22 -> V_67 ;
if ( F_300 ( V_743 , & V_745 , sizeof( V_745 ) ) )
return - V_721 ;
return 0 ;
}
static int F_307 ( struct V_1 * V_22 , void T_8 * V_743 )
{
T_13 V_750 ;
unsigned char V_751 , V_752 , V_753 ;
int V_21 ;
V_21 = sscanf ( V_754 , L_211 ,
& V_751 , & V_752 , & V_753 ) ;
if ( V_21 != 3 ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_212
L_213 , V_754 ) ;
V_751 = 0 ;
V_752 = 0 ;
V_753 = 0 ;
}
V_750 = ( V_751 << 16 ) | ( V_752 << 8 ) | V_753 ;
if ( ! V_743 )
return - V_55 ;
if ( F_300 ( V_743 , & V_750 , sizeof( T_13 ) ) )
return - V_721 ;
return 0 ;
}
static int F_308 ( struct V_1 * V_22 , void T_8 * V_743 )
{
T_10 V_755 ;
struct V_8 * V_9 ;
char * V_756 = NULL ;
T_5 V_267 ;
int V_21 = 0 ;
if ( ! V_743 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_757 ;
if ( F_297 ( & V_755 , V_743 , sizeof( V_755 ) ) )
return - V_721 ;
if ( ( V_755 . V_720 < 1 ) &&
( V_755 . V_144 . Type . V_758 != V_625 ) ) {
return - V_55 ;
}
if ( V_755 . V_720 > 0 ) {
V_756 = F_92 ( V_755 . V_720 , V_203 ) ;
if ( V_756 == NULL )
return - V_261 ;
if ( V_755 . V_144 . Type . V_758 & V_623 ) {
if ( F_297 ( V_756 , V_755 . V_45 ,
V_755 . V_720 ) ) {
V_21 = - V_721 ;
goto V_759;
}
} else {
memset ( V_756 , 0 , V_755 . V_720 ) ;
}
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_688 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_755 . V_720 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_280 = F_160 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_280 = F_160 ( 0 ) ;
}
memcpy ( & V_9 -> V_124 . V_349 , & V_755 . V_718 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_755 . V_144 ,
sizeof( V_9 -> V_144 ) ) ;
if ( V_755 . V_720 > 0 ) {
V_267 = F_132 ( V_22 -> V_29 , V_756 ,
V_755 . V_720 , V_760 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 , ( V_372 ) V_267 ) ) {
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( 0 ) ;
V_21 = - V_261 ;
goto V_394;
}
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( V_755 . V_720 ) ;
V_9 -> V_276 [ 0 ] . V_278 = F_139 ( V_376 ) ;
}
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_380 ) ;
if ( V_755 . V_720 > 0 )
F_161 ( V_22 -> V_29 , V_9 , 1 , V_760 ) ;
F_309 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_387 ;
goto V_394;
}
memcpy ( & V_755 . V_719 , V_9 -> V_24 ,
sizeof( V_755 . V_719 ) ) ;
if ( F_300 ( V_743 , & V_755 , sizeof( V_755 ) ) ) {
V_21 = - V_721 ;
goto V_394;
}
if ( ( V_755 . V_144 . Type . V_758 & V_624 ) &&
V_755 . V_720 > 0 ) {
if ( F_300 ( V_755 . V_45 , V_756 , V_755 . V_720 ) ) {
V_21 = - V_721 ;
goto V_394;
}
}
V_394:
F_106 ( V_22 , V_9 ) ;
V_759:
F_81 ( V_756 ) ;
return V_21 ;
}
static int F_310 ( struct V_1 * V_22 , void T_8 * V_743 )
{
T_12 * V_761 ;
struct V_8 * V_9 ;
unsigned char * * V_756 = NULL ;
int * V_762 = NULL ;
T_5 V_267 ;
T_14 V_370 = 0 ;
int V_49 = 0 ;
T_4 V_763 ;
T_4 V_764 ;
T_14 T_8 * V_765 ;
if ( ! V_743 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_757 ;
V_761 = ( T_12 * )
F_92 ( sizeof( * V_761 ) , V_203 ) ;
if ( ! V_761 ) {
V_49 = - V_261 ;
goto V_766;
}
if ( F_297 ( V_761 , V_743 , sizeof( * V_761 ) ) ) {
V_49 = - V_721 ;
goto V_766;
}
if ( ( V_761 -> V_720 < 1 ) &&
( V_761 -> V_144 . Type . V_758 != V_625 ) ) {
V_49 = - V_55 ;
goto V_766;
}
if ( V_761 -> V_723 > V_767 ) {
V_49 = - V_55 ;
goto V_766;
}
if ( V_761 -> V_720 > V_761 -> V_723 * V_768 ) {
V_49 = - V_55 ;
goto V_766;
}
V_756 = F_115 ( V_768 * sizeof( char * ) , V_203 ) ;
if ( ! V_756 ) {
V_49 = - V_261 ;
goto V_766;
}
V_762 = F_92 ( V_768 * sizeof( int ) , V_203 ) ;
if ( ! V_762 ) {
V_49 = - V_261 ;
goto V_766;
}
V_763 = V_761 -> V_720 ;
V_765 = V_761 -> V_45 ;
while ( V_763 ) {
V_764 = ( V_763 > V_761 -> V_723 ) ? V_761 -> V_723 : V_763 ;
V_762 [ V_370 ] = V_764 ;
V_756 [ V_370 ] = F_92 ( V_764 , V_203 ) ;
if ( V_756 [ V_370 ] == NULL ) {
V_49 = - V_261 ;
goto V_766;
}
if ( V_761 -> V_144 . Type . V_758 & V_623 ) {
if ( F_297 ( V_756 [ V_370 ] , V_765 , V_764 ) ) {
V_49 = - V_721 ;
goto V_766;
}
} else
memset ( V_756 [ V_370 ] , 0 , V_764 ) ;
V_763 -= V_764 ;
V_765 += V_764 ;
V_370 ++ ;
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_688 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = ( T_1 ) V_370 ;
V_9 -> V_124 . V_280 = F_160 ( V_370 ) ;
memcpy ( & V_9 -> V_124 . V_349 , & V_761 -> V_718 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_761 -> V_144 , sizeof( V_9 -> V_144 ) ) ;
if ( V_761 -> V_720 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
V_267 = F_132 ( V_22 -> V_29 , V_756 [ V_68 ] ,
V_762 [ V_68 ] , V_760 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 ,
( V_372 ) V_267 ) ) {
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( 0 ) ;
F_161 ( V_22 -> V_29 , V_9 , V_68 ,
V_760 ) ;
V_49 = - V_261 ;
goto V_769;
}
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( V_762 [ V_68 ] ) ;
V_9 -> V_276 [ V_68 ] . V_278 = F_139 ( 0 ) ;
}
V_9 -> V_276 [ -- V_68 ] . V_278 = F_139 ( V_376 ) ;
}
V_49 = F_168 ( V_22 , V_9 , V_127 ,
V_380 ) ;
if ( V_370 )
F_161 ( V_22 -> V_29 , V_9 , V_370 , V_760 ) ;
F_309 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_387 ;
goto V_769;
}
memcpy ( & V_761 -> V_719 , V_9 -> V_24 , sizeof( V_761 -> V_719 ) ) ;
if ( F_300 ( V_743 , V_761 , sizeof( * V_761 ) ) ) {
V_49 = - V_721 ;
goto V_769;
}
if ( ( V_761 -> V_144 . Type . V_758 & V_624 ) && V_761 -> V_720 > 0 ) {
int V_68 ;
T_14 T_8 * V_770 = V_761 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
if ( F_300 ( V_770 , V_756 [ V_68 ] , V_762 [ V_68 ] ) ) {
V_49 = - V_721 ;
goto V_769;
}
V_770 += V_762 [ V_68 ] ;
}
}
V_49 = 0 ;
V_769:
F_106 ( V_22 , V_9 ) ;
V_766:
if ( V_756 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ )
F_81 ( V_756 [ V_68 ] ) ;
F_81 ( V_756 ) ;
}
F_81 ( V_762 ) ;
F_81 ( V_761 ) ;
return V_49 ;
}
static void F_309 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_295 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_301 ( struct V_2 * V_30 , int V_284 , void T_8 * V_713 )
{
struct V_1 * V_22 ;
void T_8 * V_743 = ( void T_8 * ) V_713 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_284 ) {
case V_735 :
case V_736 :
case V_737 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_725 :
return F_305 ( V_22 , V_743 ) ;
case V_733 :
return F_307 ( V_22 , V_743 ) ;
case V_722 :
if ( F_289 ( & V_22 -> V_771 ) < 0 )
return - V_772 ;
V_21 = F_308 ( V_22 , V_743 ) ;
F_56 ( & V_22 -> V_771 ) ;
return V_21 ;
case V_724 :
if ( F_289 ( & V_22 -> V_771 ) < 0 )
return - V_772 ;
V_21 = F_310 ( V_22 , V_743 ) ;
F_56 ( & V_22 -> V_771 ) ;
return V_21 ;
default:
return - V_773 ;
}
}
static void F_311 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_397 )
{
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_678 , V_22 , NULL , 0 , 0 ,
V_158 , V_398 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_397 ;
V_9 -> V_379 = NULL ;
F_61 ( V_22 , V_9 ) ;
return;
}
static int F_177 ( struct V_8 * V_9 , T_1 V_284 , struct V_1 * V_22 ,
void * V_756 , T_3 V_466 , T_6 V_774 , unsigned char * V_72 ,
int V_150 )
{
int V_775 = V_625 ;
T_5 V_348 ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_688 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_756 != NULL && V_466 > 0 ) {
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
if ( V_774 & V_405 ) {
V_9 -> V_144 . V_145 [ 1 ] = 0x01 ;
V_9 -> V_144 . V_145 [ 2 ] = ( V_774 & 0xff ) ;
}
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_392 ;
V_9 -> V_144 . V_145 [ 4 ] = V_466 & 0xFF ;
break;
case V_460 :
case V_461 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_466 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_466 & 0xFF ;
break;
case V_776 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
V_9 -> V_144 . V_145 [ 6 ] = V_776 ;
break;
case V_778 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 ,
V_622 , V_623 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_778 ;
break;
case V_779 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 ,
V_622 , V_623 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_780 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = V_466 & 0xFF ;
break;
case V_473 :
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_625 ) ;
V_9 -> V_144 . V_620 = 0 ;
break;
case V_423 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 1 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_466 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_466 & 0xFF ;
break;
case V_782 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
V_9 -> V_144 . V_145 [ 6 ] = V_782 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0xFF ;
break;
case V_430 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
V_9 -> V_144 . V_145 [ 6 ] = V_430 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_426 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
V_9 -> V_144 . V_145 [ 6 ] = V_426 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_440 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
V_9 -> V_144 . V_145 [ 6 ] = V_440 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_466 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_466 >> 8 ) & 0XFF ;
break;
case V_428 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_624 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_777 ;
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
case V_679 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_625 ) ;
V_9 -> V_144 . V_620 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_783 ;
V_9 -> V_144 . V_145 [ 1 ] = V_784 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_678 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 , V_622 , V_625 ) ;
V_9 -> V_144 . V_620 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 1 ] = V_785 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_475 :
memcpy ( & V_348 , V_756 , sizeof( V_348 ) ) ;
F_279 ( & V_22 -> V_29 -> V_30 ,
L_215 ,
V_348 , V_9 -> V_124 . V_348 ) ;
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_621 =
F_254 ( V_150 ,
V_622 , V_623 ) ;
V_9 -> V_144 . V_620 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_786 ;
V_9 -> V_144 . V_145 [ 1 ] = V_787 ;
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
switch ( F_312 ( V_9 -> V_144 . V_621 ) ) {
case V_624 :
V_775 = V_395 ;
break;
case V_623 :
V_775 = V_271 ;
break;
case V_625 :
V_775 = V_375 ;
break;
default:
V_775 = V_760 ;
}
if ( F_162 ( V_22 -> V_29 , V_9 , V_756 , V_466 , V_775 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_313 ( T_16 V_788 , T_16 V_466 )
{
T_16 V_789 = ( ( T_16 ) V_788 ) & V_790 ;
T_16 V_791 = ( ( T_16 ) V_788 ) - V_789 ;
void T_15 * V_792 = F_314 ( V_789 ,
V_791 + V_466 ) ;
return V_792 ? ( V_792 + V_791 ) : NULL ;
}
static inline unsigned long F_315 ( struct V_1 * V_22 , T_1 V_110 )
{
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
}
static inline bool F_316 ( struct V_1 * V_22 )
{
return V_22 -> V_115 . V_793 ( V_22 ) ;
}
static inline long F_317 ( struct V_1 * V_22 )
{
return ( V_22 -> V_115 . V_793 ( V_22 ) == 0 ) ||
( V_22 -> V_794 == 0 ) ;
}
static inline int F_318 ( struct V_1 * V_22 , T_4 V_795 ,
T_4 V_796 )
{
if ( F_45 ( V_795 >= V_22 -> V_237 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_218 , V_796 ) ;
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
F_319 ( V_9 -> V_379 ) ;
}
static inline void F_320 ( struct V_1 * V_22 ,
T_4 V_796 )
{
T_4 V_795 ;
struct V_8 * V_9 ;
V_795 = V_796 >> V_583 ;
if ( ! F_318 ( V_22 , V_795 , V_796 ) ) {
V_9 = V_22 -> V_239 + V_795 ;
F_62 ( V_9 ) ;
}
}
static int F_321 ( struct V_1 * V_22 )
{
if ( F_48 ( ! V_797 ) )
return 0 ;
if ( F_48 ( V_22 -> V_794 ) )
return 0 ;
F_95 ( & V_22 -> V_29 -> V_30 , L_219
L_220 ) ;
return 1 ;
}
static struct V_1 * F_322 ( T_1 * V_798 )
{
return F_259 ( ( V_798 - * V_798 ) , struct V_1 , V_110 [ 0 ] ) ;
}
static T_17 F_323 ( int V_659 , void * V_798 )
{
struct V_1 * V_22 = F_322 ( V_798 ) ;
T_1 V_110 = * ( T_1 * ) V_798 ;
T_4 V_796 ;
if ( F_321 ( V_22 ) )
return V_799 ;
if ( F_317 ( V_22 ) )
return V_799 ;
V_22 -> V_800 = F_324 () ;
while ( F_316 ( V_22 ) ) {
V_796 = F_315 ( V_22 , V_110 ) ;
while ( V_796 != V_120 )
V_796 = F_44 ( V_22 , V_110 ) ;
}
return V_801 ;
}
static T_17 F_325 ( int V_659 , void * V_798 )
{
struct V_1 * V_22 = F_322 ( V_798 ) ;
T_4 V_796 ;
T_1 V_110 = * ( T_1 * ) V_798 ;
if ( F_321 ( V_22 ) )
return V_799 ;
V_22 -> V_800 = F_324 () ;
V_796 = F_315 ( V_22 , V_110 ) ;
while ( V_796 != V_120 )
V_796 = F_44 ( V_22 , V_110 ) ;
return V_801 ;
}
static T_17 F_326 ( int V_659 , void * V_798 )
{
struct V_1 * V_22 = F_322 ( ( T_1 * ) V_798 ) ;
T_4 V_796 ;
T_1 V_110 = * ( T_1 * ) V_798 ;
if ( F_317 ( V_22 ) )
return V_799 ;
V_22 -> V_800 = F_324 () ;
while ( F_316 ( V_22 ) ) {
V_796 = F_315 ( V_22 , V_110 ) ;
while ( V_796 != V_120 ) {
F_320 ( V_22 , V_796 ) ;
V_796 = F_44 ( V_22 , V_110 ) ;
}
}
return V_801 ;
}
static T_17 F_327 ( int V_659 , void * V_798 )
{
struct V_1 * V_22 = F_322 ( V_798 ) ;
T_4 V_796 ;
T_1 V_110 = * ( T_1 * ) V_798 ;
V_22 -> V_800 = F_324 () ;
V_796 = F_315 ( V_22 , V_110 ) ;
while ( V_796 != V_120 ) {
F_320 ( V_22 , V_796 ) ;
V_796 = F_44 ( V_22 , V_110 ) ;
}
return V_801 ;
}
static int F_328 ( struct V_369 * V_29 , unsigned char V_802 ,
unsigned char type )
{
struct V_803 {
struct V_804 V_805 ;
struct V_806 V_144 ;
struct V_807 V_808 ;
};
struct V_803 * V_284 ;
static const T_3 V_809 = sizeof( * V_284 ) +
sizeof( V_284 -> V_808 ) ;
V_372 V_810 ;
T_7 V_811 ;
T_4 V_348 ;
void T_15 * V_152 ;
int V_68 , V_717 ;
V_152 = F_329 ( V_29 , 0 ) ;
if ( V_152 == NULL )
return - V_261 ;
V_717 = F_330 ( V_29 , F_331 ( 32 ) ) ;
if ( V_717 ) {
F_332 ( V_152 ) ;
return V_717 ;
}
V_284 = F_333 ( V_29 , V_809 , & V_810 ) ;
if ( V_284 == NULL ) {
F_332 ( V_152 ) ;
return - V_261 ;
}
V_811 = F_139 ( V_810 ) ;
V_284 -> V_805 . V_128 = 0 ;
V_284 -> V_805 . V_125 = 0 ;
V_284 -> V_805 . V_280 = F_160 ( 0 ) ;
V_284 -> V_805 . V_348 = F_134 ( V_810 ) ;
memset ( & V_284 -> V_805 . V_349 . V_350 , 0 , 8 ) ;
V_284 -> V_144 . V_345 = 16 ;
V_284 -> V_144 . V_621 =
F_254 ( V_398 , V_812 , V_625 ) ;
V_284 -> V_144 . V_620 = 0 ;
V_284 -> V_144 . V_145 [ 0 ] = V_802 ;
V_284 -> V_144 . V_145 [ 1 ] = type ;
memset ( & V_284 -> V_144 . V_145 [ 2 ] , 0 , 14 ) ;
V_284 -> V_808 . V_282 =
F_134 ( ( F_131 ( V_811 ) + sizeof( * V_284 ) ) ) ;
V_284 -> V_808 . V_281 = F_139 ( sizeof( struct V_337 ) ) ;
F_60 ( F_131 ( V_811 ) , V_152 + V_153 ) ;
for ( V_68 = 0 ; V_68 < V_813 ; V_68 ++ ) {
V_348 = F_334 ( V_152 + V_814 ) ;
if ( ( V_348 & ~ V_815 ) == V_810 )
break;
F_108 ( V_816 ) ;
}
F_332 ( V_152 ) ;
if ( V_68 == V_813 ) {
F_74 ( & V_29 -> V_30 , L_221 ,
V_802 , type ) ;
return - V_382 ;
}
F_335 ( V_29 , V_809 , V_284 , V_810 ) ;
if ( V_348 & V_817 ) {
F_74 ( & V_29 -> V_30 , L_222 ,
V_802 , type ) ;
return - V_387 ;
}
F_95 ( & V_29 -> V_30 , L_223 ,
V_802 , type ) ;
return 0 ;
}
static int F_336 ( struct V_369 * V_29 ,
void T_15 * V_152 , T_4 V_818 )
{
if ( V_818 ) {
F_95 ( & V_29 -> V_30 , L_224 ) ;
F_60 ( V_818 , V_152 + V_819 ) ;
F_108 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_95 ( & V_29 -> V_30 , L_225 ) ;
V_21 = F_337 ( V_29 , V_820 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
V_21 = F_337 ( V_29 , V_821 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
}
return 0 ;
}
static void F_338 ( char * V_822 , int V_50 )
{
memset ( V_822 , 0 , V_50 ) ;
strncpy ( V_822 , V_41 L_226 V_754 , V_50 - 1 ) ;
}
static int F_339 ( struct V_823 T_15 * V_824 )
{
char * V_822 ;
int V_68 , V_466 = sizeof( V_824 -> V_822 ) ;
V_822 = F_92 ( V_466 , V_203 ) ;
if ( ! V_822 )
return - V_261 ;
F_338 ( V_822 , V_466 ) ;
for ( V_68 = 0 ; V_68 < V_466 ; V_68 ++ )
F_340 ( V_822 [ V_68 ] , & V_824 -> V_822 [ V_68 ] ) ;
F_81 ( V_822 ) ;
return 0 ;
}
static void F_341 ( struct V_823 T_15 * V_824 ,
unsigned char * V_825 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_824 -> V_822 ) ; V_68 ++ )
V_825 [ V_68 ] = F_342 ( & V_824 -> V_822 [ V_68 ] ) ;
}
static int F_343 ( struct V_823 T_15 * V_824 )
{
char * V_825 , * V_826 ;
int V_21 , V_466 = sizeof( V_824 -> V_822 ) ;
V_826 = F_92 ( 2 * V_466 , V_203 ) ;
if ( ! V_826 )
return - V_261 ;
V_825 = V_826 + V_466 ;
F_338 ( V_826 , V_466 ) ;
F_341 ( V_824 , V_825 ) ;
V_21 = ! memcmp ( V_825 , V_826 , V_466 ) ;
F_81 ( V_826 ) ;
return V_21 ;
}
static int F_344 ( struct V_369 * V_29 , T_4 V_67 )
{
T_5 V_827 ;
T_4 V_828 ;
T_5 V_829 ;
void T_15 * V_152 ;
unsigned long V_830 ;
T_4 V_831 ;
int V_21 ;
struct V_823 T_15 * V_824 ;
T_4 V_818 ;
T_6 V_832 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_227 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_833 ;
F_345 ( V_29 , 4 , & V_832 ) ;
F_346 ( V_29 ) ;
V_21 = F_347 ( V_29 , & V_830 ) ;
if ( V_21 )
return V_21 ;
V_152 = F_313 ( V_830 , 0x250 ) ;
if ( ! V_152 )
return - V_261 ;
V_21 = F_348 ( V_29 , V_152 , & V_828 ,
& V_829 , & V_827 ) ;
if ( V_21 )
goto V_834;
V_824 = F_313 ( F_349 ( V_29 ,
V_829 ) + V_827 , sizeof( * V_824 ) ) ;
if ( ! V_824 ) {
V_21 = - V_261 ;
goto V_834;
}
V_21 = F_339 ( V_824 ) ;
if ( V_21 )
goto V_835;
V_831 = F_334 ( & V_824 -> V_831 ) ;
V_818 = V_831 & V_836 ;
if ( V_818 ) {
V_818 = V_837 ;
} else {
V_818 = V_831 & V_838 ;
if ( V_818 ) {
F_9 ( & V_29 -> V_30 ,
L_228 ) ;
V_21 = - V_833 ;
goto V_835;
}
}
V_21 = F_336 ( V_29 , V_152 , V_818 ) ;
if ( V_21 )
goto V_835;
F_350 ( V_29 ) ;
F_351 ( V_29 , 4 , V_832 ) ;
F_108 ( V_839 ) ;
V_21 = F_352 ( V_29 , V_152 , V_840 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_229 ) ;
goto V_835;
}
V_21 = F_343 ( V_152 ) ;
if ( V_21 < 0 )
goto V_835;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_230
L_231 ) ;
V_21 = - V_833 ;
} else {
F_95 ( & V_29 -> V_30 , L_232 ) ;
}
V_835:
F_332 ( V_824 ) ;
V_834:
F_332 ( V_152 ) ;
return V_21 ;
}
static void F_353 ( struct V_42 * V_30 , struct V_823 T_15 * V_841 )
{
#ifdef F_354
int V_68 ;
char V_842 [ 17 ] ;
F_95 ( V_30 , L_233 ) ;
F_95 ( V_30 , L_234 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_842 [ V_68 ] = F_342 ( & ( V_841 -> V_843 [ V_68 ] ) ) ;
V_842 [ 4 ] = '\0' ;
F_95 ( V_30 , L_235 , V_842 ) ;
F_95 ( V_30 , L_236 , F_334 ( & ( V_841 -> V_844 ) ) ) ;
F_95 ( V_30 , L_237 ,
F_334 ( & ( V_841 -> V_845 ) ) ) ;
F_95 ( V_30 , L_238 ,
F_334 ( & ( V_841 -> V_846 ) ) ) ;
F_95 ( V_30 , L_239 ,
F_334 ( & ( V_841 -> V_847 . V_848 ) ) ) ;
F_95 ( V_30 , L_240 ,
F_334 ( & ( V_841 -> V_847 . V_849 ) ) ) ;
F_95 ( V_30 , L_241 ,
F_334 ( & ( V_841 -> V_847 . V_850 ) ) ) ;
F_95 ( V_30 , L_242 ,
F_334 ( & ( V_841 -> V_851 ) ) ) ;
F_95 ( V_30 , L_243 , F_334 ( & ( V_841 -> V_852 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_842 [ V_68 ] = F_342 ( & ( V_841 -> V_853 [ V_68 ] ) ) ;
V_842 [ 16 ] = '\0' ;
F_95 ( V_30 , L_244 , V_842 ) ;
F_95 ( V_30 , L_245 ,
F_334 ( & ( V_841 -> V_854 ) ) ) ;
#endif
}
static int F_355 ( struct V_369 * V_29 , unsigned long V_855 )
{
int V_68 , V_711 , V_856 , V_857 ;
if ( V_855 == V_858 )
return 0 ;
V_711 = 0 ;
for ( V_68 = 0 ; V_68 < V_859 ; V_68 ++ ) {
V_857 = F_356 ( V_29 , V_68 ) & V_860 ;
if ( V_857 == V_861 )
V_711 += 4 ;
else {
V_856 = F_356 ( V_29 , V_68 ) &
V_862 ;
switch ( V_856 ) {
case V_863 :
case V_864 :
V_711 += 4 ;
break;
case V_865 :
V_711 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_246 ) ;
return - 1 ;
break;
}
}
if ( V_711 == V_855 - V_858 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_357 ( struct V_1 * V_22 )
{
if ( V_22 -> V_126 ) {
if ( V_22 -> V_29 -> V_866 )
F_358 ( V_22 -> V_29 ) ;
V_22 -> V_126 = 0 ;
} else if ( V_22 -> V_867 ) {
if ( V_22 -> V_29 -> V_868 )
F_359 ( V_22 -> V_29 ) ;
V_22 -> V_867 = 0 ;
}
}
static void F_360 ( struct V_1 * V_22 )
{
#ifdef F_361
int V_717 , V_68 ;
struct V_869 V_870 [ V_871 ] ;
for ( V_68 = 0 ; V_68 < V_871 ; V_68 ++ ) {
V_870 [ V_68 ] . V_872 = 0 ;
V_870 [ V_68 ] . V_184 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_873;
if ( F_362 ( V_22 -> V_29 , V_874 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_247 ) ;
V_22 -> V_126 = V_871 ;
if ( V_22 -> V_126 > F_363 () )
V_22 -> V_126 = F_363 () ;
V_717 = F_364 ( V_22 -> V_29 , V_870 ,
1 , V_22 -> V_126 ) ;
if ( V_717 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_248 , V_717 ) ;
V_22 -> V_126 = 0 ;
goto V_875;
} else if ( V_717 < V_22 -> V_126 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_249
L_250 , V_717 ) ;
}
V_22 -> V_126 = V_717 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ )
V_22 -> V_660 [ V_68 ] = V_870 [ V_68 ] . V_872 ;
return;
}
V_875:
if ( F_362 ( V_22 -> V_29 , V_876 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_251 ) ;
if ( ! F_365 ( V_22 -> V_29 ) )
V_22 -> V_867 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_252 ) ;
}
V_873:
#endif
V_22 -> V_660 [ V_22 -> V_661 ] = V_22 -> V_29 -> V_659 ;
}
static int F_366 ( struct V_369 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_877 , V_878 ;
V_877 = V_29 -> V_879 ;
V_878 = V_29 -> V_880 ;
* V_67 = ( ( V_878 << 16 ) & 0xffff0000 ) |
V_877 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_881 ) ; V_68 ++ )
if ( * V_67 == V_881 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_877 != V_882 &&
V_877 != V_883 ) ||
! V_884 ) {
F_9 ( & V_29 -> V_30 , L_253
L_254 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_881 ) - 1 ;
}
static int F_347 ( struct V_369 * V_29 ,
unsigned long * V_885 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_859 ; V_68 ++ )
if ( F_356 ( V_29 , V_68 ) & V_886 ) {
* V_885 = F_349 ( V_29 , V_68 ) ;
F_279 ( & V_29 -> V_30 , L_255 ,
* V_885 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_256 ) ;
return - V_81 ;
}
static int F_352 ( struct V_369 * V_29 , void T_15 * V_152 ,
int V_887 )
{
int V_68 , V_888 ;
T_4 V_889 ;
if ( V_887 )
V_888 = V_890 ;
else
V_888 = V_891 ;
for ( V_68 = 0 ; V_68 < V_888 ; V_68 ++ ) {
V_889 = F_334 ( V_152 + V_892 ) ;
if ( V_887 ) {
if ( V_889 == V_893 )
return 0 ;
} else {
if ( V_889 != V_893 )
return 0 ;
}
F_108 ( V_894 ) ;
}
F_9 ( & V_29 -> V_30 , L_257 ) ;
return - V_81 ;
}
static int F_348 ( struct V_369 * V_29 , void T_15 * V_152 ,
T_4 * V_828 , T_5 * V_829 ,
T_5 * V_827 )
{
* V_828 = F_334 ( V_152 + V_895 ) ;
* V_827 = F_334 ( V_152 + V_896 ) ;
* V_828 &= ( T_4 ) 0x0000ffff ;
* V_829 = F_355 ( V_29 , * V_828 ) ;
if ( * V_829 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_258 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_367 ( struct V_1 * V_22 )
{
if ( V_22 -> V_897 ) {
F_332 ( V_22 -> V_897 ) ;
V_22 -> V_897 = NULL ;
}
if ( V_22 -> V_824 ) {
F_332 ( V_22 -> V_824 ) ;
V_22 -> V_824 = NULL ;
}
}
static int F_368 ( struct V_1 * V_22 )
{
T_5 V_827 ;
T_4 V_828 ;
T_5 V_829 ;
T_4 V_898 ;
int V_21 ;
V_21 = F_348 ( V_22 -> V_29 , V_22 -> V_152 , & V_828 ,
& V_829 , & V_827 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_824 = F_313 ( F_349 ( V_22 -> V_29 ,
V_829 ) + V_827 , sizeof( * V_22 -> V_824 ) ) ;
if ( ! V_22 -> V_824 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
return - V_261 ;
}
V_21 = F_339 ( V_22 -> V_824 ) ;
if ( V_21 )
return V_21 ;
V_898 = F_334 ( & V_22 -> V_824 -> V_899 ) ;
V_22 -> V_897 = F_313 ( F_349 ( V_22 -> V_29 ,
V_829 ) + V_827 + V_898 ,
sizeof( * V_22 -> V_897 ) ) ;
if ( ! V_22 -> V_897 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
F_367 ( V_22 ) ;
return - V_261 ;
}
return 0 ;
}
static void F_369 ( struct V_1 * V_22 )
{
#define F_370 16
F_281 ( F_370 <= V_654 ) ;
V_22 -> V_121 = F_334 ( & V_22 -> V_824 -> V_900 ) ;
if ( V_797 && V_22 -> V_121 > 32 )
V_22 -> V_121 = 32 ;
if ( V_22 -> V_121 < F_370 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_261 ,
V_22 -> V_121 ,
F_370 ) ;
V_22 -> V_121 = F_370 ;
}
}
static int F_371 ( struct V_1 * V_22 )
{
return V_22 -> V_262 > 512 ;
}
static void F_372 ( struct V_1 * V_22 )
{
F_369 ( V_22 ) ;
V_22 -> V_237 = V_22 -> V_121 ;
V_22 -> V_262 = F_334 ( & ( V_22 -> V_824 -> V_901 ) ) ;
V_22 -> V_480 = F_334 ( & ( V_22 -> V_824 -> V_831 ) ) ;
if ( F_371 ( V_22 ) ) {
V_22 -> V_277 = 32 ;
V_22 -> V_260 = V_22 -> V_262 - V_22 -> V_277 ;
V_22 -> V_262 -- ;
} else {
V_22 -> V_277 = 31 ;
V_22 -> V_262 = 31 ;
V_22 -> V_260 = 0 ;
}
V_22 -> V_700 = F_334 ( & ( V_22 -> V_824 -> V_700 ) ) ;
if ( ! ( V_706 & V_22 -> V_700 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_262 ) ;
if ( ! ( V_707 & V_22 -> V_700 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
if ( ! ( V_699 & V_22 -> V_700 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_264 ) ;
}
static inline bool F_373 ( struct V_1 * V_22 )
{
if ( ! F_374 ( V_22 -> V_824 -> V_843 , L_265 , 4 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_266 ) ;
return false ;
}
return true ;
}
static inline void F_375 ( struct V_1 * V_22 )
{
T_4 V_902 ;
V_902 = F_334 ( & ( V_22 -> V_824 -> V_902 ) ) ;
#ifdef F_376
V_902 |= V_903 ;
#endif
V_902 |= V_904 ;
F_60 ( V_902 , & ( V_22 -> V_824 -> V_902 ) ) ;
}
static inline void F_377 ( struct V_1 * V_22 )
{
T_4 V_905 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_905 = F_334 ( V_22 -> V_152 + V_906 ) ;
V_905 |= 0x8000 ;
F_60 ( V_905 , V_22 -> V_152 + V_906 ) ;
}
static int F_378 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_907 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_908 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_907 = F_334 ( V_22 -> V_152 + V_819 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_907 & V_909 ) )
goto V_910;
F_108 ( V_911 ) ;
}
return - V_81 ;
V_910:
return 0 ;
}
static int F_379 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_907 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_912 ; V_68 ++ ) {
if ( V_22 -> V_913 )
goto V_910;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_907 = F_334 ( V_22 -> V_152 + V_819 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_907 & V_914 ) )
goto V_910;
F_108 ( V_915 ) ;
}
return - V_81 ;
V_910:
return 0 ;
}
static int F_380 ( struct V_1 * V_22 )
{
T_4 V_916 ;
V_916 = F_334 ( & ( V_22 -> V_824 -> V_845 ) ) ;
if ( ! ( V_916 & V_917 ) )
return - V_833 ;
V_22 -> V_121 = F_334 ( & ( V_22 -> V_824 -> V_851 ) ) ;
F_60 ( V_918 , & ( V_22 -> V_824 -> V_847 . V_848 ) ) ;
F_60 ( 0 , & V_22 -> V_824 -> V_847 . V_919 ) ;
F_60 ( V_914 , V_22 -> V_152 + V_819 ) ;
if ( F_379 ( V_22 ) )
goto error;
F_353 ( & V_22 -> V_29 -> V_30 , V_22 -> V_824 ) ;
if ( ! ( F_334 ( & ( V_22 -> V_824 -> V_846 ) ) & V_918 ) )
goto error;
V_22 -> V_63 = V_918 ;
return 0 ;
error:
F_74 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
return - V_81 ;
}
static void F_381 ( struct V_1 * V_22 )
{
F_367 ( V_22 ) ;
F_332 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
F_357 ( V_22 ) ;
F_382 ( V_22 -> V_29 ) ;
F_383 ( V_22 -> V_29 ) ;
}
static int F_384 ( struct V_1 * V_22 )
{
int V_920 , V_717 ;
V_920 = F_366 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_920 < 0 )
return V_920 ;
V_22 -> V_921 = V_881 [ V_920 ] . V_921 ;
V_22 -> V_115 = * ( V_881 [ V_920 ] . V_115 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_385 ( V_22 -> V_29 , V_922 |
V_923 | V_924 ) ;
V_717 = F_386 ( V_22 -> V_29 ) ;
if ( V_717 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_268 ) ;
F_382 ( V_22 -> V_29 ) ;
return V_717 ;
}
V_717 = F_387 ( V_22 -> V_29 , V_41 ) ;
if ( V_717 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_269 ) ;
F_382 ( V_22 -> V_29 ) ;
return V_717 ;
}
F_388 ( V_22 -> V_29 ) ;
F_360 ( V_22 ) ;
V_717 = F_347 ( V_22 -> V_29 , & V_22 -> V_830 ) ;
if ( V_717 )
goto V_925;
V_22 -> V_152 = F_313 ( V_22 -> V_830 , 0x250 ) ;
if ( ! V_22 -> V_152 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_270 ) ;
V_717 = - V_261 ;
goto V_925;
}
V_717 = F_352 ( V_22 -> V_29 , V_22 -> V_152 , V_840 ) ;
if ( V_717 )
goto V_926;
V_717 = F_368 ( V_22 ) ;
if ( V_717 )
goto V_926;
F_372 ( V_22 ) ;
if ( ! F_373 ( V_22 ) ) {
V_717 = - V_81 ;
goto V_927;
}
F_375 ( V_22 ) ;
F_377 ( V_22 ) ;
V_717 = F_380 ( V_22 ) ;
if ( V_717 )
goto V_927;
return 0 ;
V_927:
F_367 ( V_22 ) ;
V_926:
F_332 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
V_925:
F_357 ( V_22 ) ;
F_382 ( V_22 -> V_29 ) ;
F_383 ( V_22 -> V_29 ) ;
return V_717 ;
}
static void F_389 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_390 64
V_22 -> V_61 = F_92 ( F_390 , V_203 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_175 ( V_22 , V_158 , 0 ,
V_22 -> V_61 , F_390 ) ;
if ( V_21 != 0 ) {
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_391 ( struct V_369 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_152 ;
if ( ! V_797 )
return 0 ;
V_21 = F_386 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_271 ) ;
return - V_81 ;
}
F_382 ( V_29 ) ;
F_108 ( 260 ) ;
V_21 = F_386 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_272 ) ;
return - V_81 ;
}
F_388 ( V_29 ) ;
V_152 = F_329 ( V_29 , 0 ) ;
if ( V_152 == NULL ) {
V_21 = - V_261 ;
goto V_928;
}
F_60 ( V_929 , V_152 + V_930 ) ;
F_332 ( V_152 ) ;
V_21 = F_344 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_928;
F_95 ( & V_29 -> V_30 , L_273 ) ;
for ( V_68 = 0 ; V_68 < V_931 ; V_68 ++ ) {
if ( F_392 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_274 ,
( V_68 < 11 ? L_275 : L_276 ) ) ;
}
V_928:
F_382 ( V_29 ) ;
return V_21 ;
}
static void F_393 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_712 ) ;
V_22 -> V_712 = NULL ;
if ( V_22 -> V_239 ) {
F_335 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_8 ) ,
V_22 -> V_239 ,
V_22 -> V_631 ) ;
V_22 -> V_239 = NULL ;
V_22 -> V_631 = 0 ;
}
if ( V_22 -> V_632 ) {
F_335 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_337 ) ,
V_22 -> V_632 ,
V_22 -> V_633 ) ;
V_22 -> V_632 = NULL ;
V_22 -> V_633 = 0 ;
}
}
static int F_394 ( struct V_1 * V_22 )
{
V_22 -> V_712 = F_115 (
F_395 ( V_22 -> V_237 , V_612 ) *
sizeof( unsigned long ) , V_203 ) ;
V_22 -> V_239 = F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_239 ) ,
& ( V_22 -> V_631 ) ) ;
V_22 -> V_632 = F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_632 ) ,
& ( V_22 -> V_633 ) ) ;
if ( ( V_22 -> V_712 == NULL )
|| ( V_22 -> V_239 == NULL )
|| ( V_22 -> V_632 == NULL ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_277 , V_204 ) ;
goto V_932;
}
F_256 ( V_22 ) ;
return 0 ;
V_932:
F_393 ( V_22 ) ;
return - V_261 ;
}
static void F_396 ( struct V_1 * V_22 )
{
int V_68 , V_383 ;
V_383 = F_397 ( V_933 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_398 ( V_22 -> V_660 [ V_68 ] , F_399 ( V_383 ) ) ;
V_383 = F_400 ( V_383 , V_933 ) ;
}
}
static void F_401 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_126 || V_22 -> V_661 != V_934 ) {
V_68 = V_22 -> V_661 ;
F_398 ( V_22 -> V_660 [ V_68 ] , NULL ) ;
F_402 ( V_22 -> V_660 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_398 ( V_22 -> V_660 [ V_68 ] , NULL ) ;
F_402 ( V_22 -> V_660 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
}
for (; V_68 < V_871 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = 0 ;
}
static int F_403 ( struct V_1 * V_22 ,
T_17 (* F_404)( int , void * ) ,
T_17 (* F_405)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_871 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_661 == V_934 && V_22 -> V_126 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
sprintf ( V_22 -> V_935 [ V_68 ] , L_278 , V_22 -> V_31 , V_68 ) ;
V_21 = F_406 ( V_22 -> V_660 [ V_68 ] , F_404 ,
0 , V_22 -> V_935 [ V_68 ] ,
& V_22 -> V_110 [ V_68 ] ) ;
if ( V_21 ) {
int V_193 ;
F_74 ( & V_22 -> V_29 -> V_30 ,
L_279 ,
V_22 -> V_660 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_193 = 0 ; V_193 < V_68 ; V_193 ++ ) {
F_402 ( V_22 -> V_660 [ V_193 ] , & V_22 -> V_110 [ V_193 ] ) ;
V_22 -> V_110 [ V_193 ] = 0 ;
}
for (; V_193 < V_871 ; V_193 ++ )
V_22 -> V_110 [ V_193 ] = 0 ;
return V_21 ;
}
}
F_396 ( V_22 ) ;
} else {
if ( V_22 -> V_126 > 0 || V_22 -> V_867 ) {
if ( V_22 -> V_126 )
sprintf ( V_22 -> V_935 [ V_22 -> V_661 ] ,
L_280 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_935 [ V_22 -> V_661 ] ,
L_281 , V_22 -> V_31 ) ;
V_21 = F_406 ( V_22 -> V_660 [ V_22 -> V_661 ] ,
F_404 , 0 ,
V_22 -> V_935 [ V_22 -> V_661 ] ,
& V_22 -> V_110 [ V_22 -> V_661 ] ) ;
} else {
sprintf ( V_22 -> V_935 [ V_22 -> V_661 ] ,
L_282 , V_22 -> V_31 ) ;
V_21 = F_406 ( V_22 -> V_660 [ V_22 -> V_661 ] ,
F_405 , V_936 ,
V_22 -> V_935 [ V_22 -> V_661 ] ,
& V_22 -> V_110 [ V_22 -> V_661 ] ) ;
}
F_398 ( V_22 -> V_660 [ V_22 -> V_661 ] , NULL ) ;
}
if ( V_21 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_279 ,
V_22 -> V_660 [ V_22 -> V_661 ] , V_22 -> V_31 ) ;
F_401 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_407 ( struct V_1 * V_22 )
{
int V_21 ;
F_311 ( V_22 , V_158 , V_937 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_283 ) ;
V_21 = F_352 ( V_22 -> V_29 , V_22 -> V_152 , V_938 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_284 ) ;
return V_21 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_285 ) ;
V_21 = F_352 ( V_22 -> V_29 , V_22 -> V_152 , V_840 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_286
L_287 ) ;
return V_21 ;
}
return 0 ;
}
static void F_408 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
if ( ! V_22 -> V_113 [ V_68 ] . V_117 )
continue;
F_335 ( V_22 -> V_29 ,
V_22 -> V_939 ,
V_22 -> V_113 [ V_68 ] . V_117 ,
V_22 -> V_113 [ V_68 ] . V_122 ) ;
V_22 -> V_113 [ V_68 ] . V_117 = NULL ;
V_22 -> V_113 [ V_68 ] . V_122 = 0 ;
}
V_22 -> V_939 = 0 ;
}
static void F_409 ( struct V_1 * V_22 )
{
F_410 ( V_22 ) ;
F_128 ( V_22 ) ;
F_393 ( V_22 ) ;
F_401 ( V_22 ) ;
F_411 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_381 ( V_22 ) ;
F_412 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_327 ) {
F_413 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_940 ) {
F_413 ( V_22 -> V_940 ) ;
V_22 -> V_940 = NULL ;
}
F_81 ( V_22 ) ;
}
static void F_414 ( struct V_1 * V_22 )
{
int V_68 , V_240 ;
struct V_8 * V_9 ;
int V_941 = 0 ;
F_415 ( V_22 -> V_327 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 ) {
V_9 -> V_24 -> V_36 = V_343 ;
F_62 ( V_9 ) ;
F_46 ( & V_22 -> V_62 ) ;
V_941 ++ ;
}
F_106 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_288 , V_941 ) ;
}
static void F_416 ( struct V_1 * V_22 , T_4 V_942 )
{
int V_383 ;
F_417 (cpu) {
T_4 * F_13 ;
F_13 = F_170 ( V_22 -> F_13 , V_383 ) ;
* F_13 = V_942 ;
}
F_77 () ;
}
static void F_418 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_334 ( V_22 -> V_152 + V_892 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_289 ,
V_22 -> V_147 / V_945 ) ;
F_13 = 0xffffffff ;
}
F_416 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_290 ,
F_13 , V_22 -> V_147 / V_945 ) ;
F_382 ( V_22 -> V_29 ) ;
F_414 ( V_22 ) ;
}
static int F_275 ( struct V_1 * V_22 )
{
T_5 V_946 ;
T_4 V_947 ;
unsigned long V_78 ;
V_946 = F_324 () ;
if ( F_419 ( V_22 -> V_800 +
( V_22 -> V_147 ) , V_946 ) )
return false ;
if ( F_419 ( V_22 -> V_948 +
( V_22 -> V_147 ) , V_946 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_947 = F_334 ( & V_22 -> V_824 -> V_854 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_949 == V_947 ) {
F_418 ( V_22 ) ;
return true ;
}
V_22 -> V_949 = V_947 ;
V_22 -> V_948 = V_946 ;
return false ;
}
static void F_420 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_950 ;
if ( ! ( V_22 -> V_480 & V_951 ) )
return;
if ( ( V_22 -> V_63 & ( V_114
| V_952 ) ) &&
( V_22 -> V_953 & V_954 ||
V_22 -> V_953 & V_955 ) ) {
if ( V_22 -> V_953 & V_954 )
V_950 = L_291 ;
if ( V_22 -> V_953 & V_955 )
V_950 = L_292 ;
F_421 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_22 -> V_30 [ V_68 ] -> V_91 = 0 ;
V_22 -> V_30 [ V_68 ] -> V_183 = 0 ;
}
F_422 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_293 ,
V_22 -> V_953 , V_950 ) ;
F_60 ( V_22 -> V_953 , & ( V_22 -> V_824 -> V_956 ) ) ;
F_60 ( V_909 , V_22 -> V_152 + V_819 ) ;
F_378 ( V_22 ) ;
F_423 ( V_22 -> V_59 ) ;
} else {
F_60 ( V_22 -> V_953 , & ( V_22 -> V_824 -> V_956 ) ) ;
F_60 ( V_909 , V_22 -> V_152 + V_819 ) ;
F_378 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_424 ( struct V_1 * V_22 )
{
if ( V_22 -> V_249 ) {
V_22 -> V_249 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_480 & V_951 ) )
return 0 ;
V_22 -> V_953 = F_334 ( & ( V_22 -> V_824 -> V_957 ) ) ;
return V_22 -> V_953 & V_958 ;
}
static int F_425 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_201 * V_389 ;
struct V_959 * V_960 , * V_961 ;
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_426 (this, tmp, &h->offline_device_list) {
V_389 = F_427 ( V_960 , struct V_201 ,
V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
if ( ! F_208 ( V_22 , V_389 -> V_72 ) ) {
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_428 ( & V_389 -> V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_202 , V_78 ) ;
}
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 0 ;
}
static int F_429 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_462 * V_492 = NULL ;
if ( ! V_22 -> V_962 )
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
if ( memcmp ( V_492 , V_22 -> V_962 , sizeof( * V_492 ) ) ) {
F_95 ( & V_22 -> V_29 -> V_30 ,
L_296 ) ;
memcpy ( V_22 -> V_962 , V_492 , sizeof( * V_492 ) ) ;
goto V_394;
} else
V_21 = 0 ;
V_394:
F_81 ( V_492 ) ;
return V_21 ;
}
static void F_430 ( struct V_635 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_259 ( F_431 ( V_325 ) ,
struct V_1 , V_963 ) ;
if ( V_22 -> V_913 )
return;
if ( F_424 ( V_22 ) || F_425 ( V_22 ) ) {
F_432 ( V_22 -> V_59 ) ;
F_420 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_411 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_528 ) {
F_433 ( V_22 ) ;
if ( F_429 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_297 ) ;
V_7 = F_432 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_411 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_913 )
F_434 ( V_22 -> V_940 , & V_22 -> V_963 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_435 ( struct V_635 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_259 ( F_431 ( V_325 ) ,
struct V_1 , V_964 ) ;
F_275 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_913 )
F_436 ( & V_22 -> V_964 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_965 * F_437 ( struct V_1 * V_22 ,
char * V_966 )
{
struct V_965 * V_967 = NULL ;
V_967 = F_438 ( L_298 , 0 , V_966 , V_22 -> V_968 ) ;
if ( ! V_967 )
F_74 ( & V_22 -> V_29 -> V_30 , L_299 , V_966 ) ;
return V_967 ;
}
static int F_439 ( struct V_369 * V_29 , const struct V_969 * V_970 )
{
int V_971 , V_21 ;
struct V_1 * V_22 ;
int V_972 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_973 == 0 )
F_440 (KERN_INFO DRIVER_NAME L_300 ) ;
V_21 = F_366 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_301 ) ;
return V_21 ;
}
V_21 = F_391 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_833 )
return V_21 ;
V_972 = 1 ;
V_21 = 0 ;
}
V_974:
F_281 ( sizeof( struct V_8 ) % V_975 ) ;
V_22 = F_115 ( sizeof( * V_22 ) , V_203 ) ;
if ( ! V_22 ) {
F_74 ( & V_29 -> V_30 , L_302 ) ;
return - V_261 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_661 = V_976 ? V_977 : V_934 ;
F_441 ( & V_22 -> V_206 ) ;
F_442 ( & V_22 -> V_79 ) ;
F_442 ( & V_22 -> V_202 ) ;
F_442 ( & V_22 -> V_640 ) ;
F_122 ( & V_22 -> V_771 , V_978 ) ;
F_122 ( & V_22 -> V_702 , V_979 ) ;
V_22 -> F_13 = F_443 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_303 ) ;
V_21 = - V_261 ;
goto V_980;
}
F_416 ( V_22 , 0 ) ;
V_21 = F_384 ( V_22 ) ;
if ( V_21 )
goto V_925;
V_21 = F_265 ( V_22 ) ;
if ( V_21 )
goto V_981;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_102 ) ;
V_22 -> V_968 = V_973 ;
V_973 ++ ;
V_21 = F_444 ( V_29 , F_331 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_971 = 1 ;
} else {
V_21 = F_444 ( V_29 , F_331 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_971 = 0 ;
} else {
F_74 ( & V_29 -> V_30 , L_304 ) ;
goto V_926;
}
}
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
V_21 = F_403 ( V_22 , F_327 , F_326 ) ;
if ( V_21 )
goto V_926;
V_21 = F_394 ( V_22 ) ;
if ( V_21 )
goto V_927;
V_21 = F_129 ( V_22 ) ;
if ( V_21 )
goto V_982;
F_445 ( & V_22 -> V_642 ) ;
F_445 ( & V_22 -> V_701 ) ;
F_445 ( & V_22 -> V_323 ) ;
F_446 ( & V_22 -> V_403 ) ;
V_22 -> V_641 = 1 ;
F_447 ( V_29 , V_22 ) ;
V_22 -> V_162 = 0 ;
F_442 ( & V_22 -> V_98 ) ;
V_21 = F_448 ( V_22 ) ;
if ( V_21 )
goto V_983;
V_22 -> V_940 = F_437 ( V_22 , L_305 ) ;
if ( ! V_22 -> V_940 ) {
V_21 = - V_261 ;
goto V_984;
}
V_22 -> V_327 = F_437 ( V_22 , L_306 ) ;
if ( ! V_22 -> V_327 ) {
V_21 = - V_261 ;
goto V_984;
}
if ( V_972 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_401 ( V_22 ) ;
V_21 = F_403 ( V_22 , F_325 ,
F_323 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_307 ) ;
F_410 ( V_22 ) ;
F_128 ( V_22 ) ;
F_393 ( V_22 ) ;
goto V_926;
}
V_21 = F_407 ( V_22 ) ;
if ( V_21 )
goto V_984;
F_95 ( & V_22 -> V_29 -> V_30 , L_308 ) ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_309 ) ;
V_22 -> V_115 . V_943 ( V_22 , V_985 ) ;
F_108 ( 10000 ) ;
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
V_21 = F_343 ( V_22 -> V_824 ) ;
if ( V_21 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_310 ) ;
F_409 ( V_22 ) ;
V_972 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_974;
}
V_22 -> V_56 = 1 ;
V_22 -> V_528 = 0 ;
V_22 -> V_115 . V_943 ( V_22 , V_985 ) ;
F_389 ( V_22 ) ;
V_22 -> V_962 = F_115 ( sizeof( * ( V_22 -> V_962 ) ) , V_203 ) ;
if ( ! V_22 -> V_962 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
V_21 = F_267 ( V_22 ) ;
if ( V_21 )
goto V_984;
V_22 -> V_147 = V_149 ;
F_449 ( & V_22 -> V_964 , F_435 ) ;
F_436 ( & V_22 -> V_964 ,
V_22 -> V_147 ) ;
F_449 ( & V_22 -> V_963 , F_430 ) ;
F_434 ( V_22 -> V_940 , & V_22 -> V_963 ,
V_22 -> V_147 ) ;
return 0 ;
V_984:
F_410 ( V_22 ) ;
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
V_983:
F_128 ( V_22 ) ;
V_982:
F_393 ( V_22 ) ;
V_927:
F_401 ( V_22 ) ;
V_926:
F_411 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_981:
F_381 ( V_22 ) ;
V_925:
if ( V_22 -> F_13 ) {
F_412 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_980:
if ( V_22 -> V_327 ) {
F_413 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_940 ) {
F_413 ( V_22 -> V_940 ) ;
V_22 -> V_940 = NULL ;
}
F_81 ( V_22 ) ;
return V_21 ;
}
static void F_450 ( struct V_1 * V_22 )
{
char * V_986 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return;
V_986 = F_115 ( 4 , V_203 ) ;
if ( ! V_986 )
return;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_779 , V_22 , V_986 , 4 , 0 ,
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
F_81 ( V_986 ) ;
}
static void F_433 ( struct V_1 * V_22 )
{
T_4 * V_987 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( V_22 -> F_13 ) )
return;
V_987 = F_115 ( sizeof( * V_987 ) , V_203 ) ;
if ( ! V_987 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_313 ) ;
return;
}
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_776 , V_22 , V_987 , 4 , 0 ,
V_158 , V_393 ) )
goto V_988;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
* V_987 |= V_989 ;
if ( F_177 ( V_9 , V_778 , V_22 , V_987 , 4 , 0 ,
V_158 , V_393 ) )
goto V_988;
V_21 = F_172 ( V_22 , V_9 ,
V_271 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
if ( F_177 ( V_9 , V_776 , V_22 , V_987 , 4 , 0 ,
V_158 , V_393 ) )
goto V_988;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_988;
if ( * V_987 & V_989 )
goto V_394;
V_988:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_314 ) ;
V_394:
F_106 ( V_22 , V_9 ) ;
F_81 ( V_987 ) ;
}
static void F_451 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_452 ( V_29 ) ;
F_450 ( V_22 ) ;
V_22 -> V_115 . V_943 ( V_22 , V_944 ) ;
F_401 ( V_22 ) ;
F_357 ( V_22 ) ;
}
static void F_453 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
F_81 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_454 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_452 ( V_29 ) == NULL ) {
F_74 ( & V_29 -> V_30 , L_315 ) ;
return;
}
V_22 = F_452 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_913 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_455 ( & V_22 -> V_964 ) ;
F_455 ( & V_22 -> V_963 ) ;
F_413 ( V_22 -> V_940 ) ;
F_413 ( V_22 -> V_327 ) ;
if ( V_22 -> V_59 )
F_456 ( V_22 -> V_59 ) ;
F_451 ( V_29 ) ;
F_453 ( V_22 ) ;
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_126 ( V_22 ) ;
F_410 ( V_22 ) ;
F_128 ( V_22 ) ;
F_393 ( V_22 ) ;
F_81 ( V_22 -> V_962 ) ;
F_411 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_381 ( V_22 ) ;
F_412 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_457 ( V_22 ) ;
F_81 ( V_22 ) ;
}
static void F_458 ( int V_990 [] , int V_991 ,
int V_992 , int V_993 , T_4 * V_994 )
{
int V_68 , V_193 , V_995 , V_466 ;
for ( V_68 = 0 ; V_68 <= V_992 ; V_68 ++ ) {
V_466 = V_68 + V_993 ;
V_995 = V_991 ;
for ( V_193 = 0 ; V_193 < V_991 ; V_193 ++ ) {
if ( V_990 [ V_193 ] >= V_466 ) {
V_995 = V_193 ;
break;
}
}
V_994 [ V_68 ] = V_995 ;
}
}
static int F_459 ( struct V_1 * V_22 , T_4 V_916 )
{
int V_68 ;
unsigned long V_996 ;
unsigned long V_63 = V_64 |
( V_916 & V_997 ) |
V_998 |
( V_916 & ( V_114 |
V_952 ) ) ;
struct V_999 V_115 = V_1000 ;
int V_1001 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_768 + 4 } ;
#define F_460 5
#define F_461 4
int V_1002 [ 16 ] = { F_460 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_461 + V_1003 } ;
F_281 ( F_26 ( V_1002 ) != 16 ) ;
F_281 ( F_26 ( V_1001 ) != 8 ) ;
F_281 ( F_249 ( struct V_139 , V_269 ) >
16 * F_460 ) ;
F_281 ( sizeof( struct V_265 ) != 16 ) ;
F_281 ( 28 > V_768 + 4 ) ;
if ( V_916 & ( V_114 | V_952 ) )
V_115 = V_1004 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 , 0 , V_22 -> V_939 ) ;
V_1001 [ 7 ] = V_768 + 4 ;
F_458 ( V_1001 , F_26 ( V_1001 ) ,
V_768 , 4 , V_22 -> V_123 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_60 ( V_1001 [ V_68 ] , & V_22 -> V_897 -> V_1005 [ V_68 ] ) ;
F_60 ( V_22 -> V_121 , & V_22 -> V_897 -> V_1006 ) ;
F_60 ( V_22 -> V_129 , & V_22 -> V_897 -> V_1007 ) ;
F_60 ( 0 , & V_22 -> V_897 -> V_1008 ) ;
F_60 ( 0 , & V_22 -> V_897 -> V_1009 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( 0 , & V_22 -> V_897 -> V_1010 [ V_68 ] . V_1011 ) ;
F_60 ( V_22 -> V_113 [ V_68 ] . V_122 ,
& V_22 -> V_897 -> V_1010 [ V_68 ] . V_1012 ) ;
}
F_60 ( 0 , & V_22 -> V_824 -> V_847 . V_919 ) ;
F_60 ( V_63 , & ( V_22 -> V_824 -> V_847 . V_848 ) ) ;
if ( V_916 & V_114 ) {
V_115 = V_1013 ;
F_60 ( 10 , & V_22 -> V_824 -> V_847 . V_849 ) ;
F_60 ( 4 , & V_22 -> V_824 -> V_847 . V_850 ) ;
} else {
if ( V_916 & V_952 ) {
V_115 = V_1014 ;
F_60 ( 10 , & V_22 -> V_824 -> V_847 . V_849 ) ;
F_60 ( 4 , & V_22 -> V_824 -> V_847 . V_850 ) ;
}
}
F_60 ( V_914 , V_22 -> V_152 + V_819 ) ;
if ( F_379 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_316 ) ;
return - V_81 ;
}
V_996 = F_334 ( & ( V_22 -> V_824 -> V_846 ) ) ;
if ( ! ( V_996 & V_64 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_317 ) ;
return - V_81 ;
}
V_22 -> V_115 = V_115 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_916 & V_114 ) ||
( V_916 & V_952 ) ) )
return 0 ;
if ( V_916 & V_114 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( V_68 , V_22 -> V_152 + V_1015 ) ;
V_22 -> V_113 [ V_68 ] . V_118 =
F_334 ( V_22 -> V_152 + V_1016 ) ;
}
V_1001 [ 7 ] = V_22 -> V_552 + 8 ;
F_458 ( V_1001 , F_26 ( V_1001 ) , V_22 -> V_552 , 8 ,
V_22 -> V_134 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 ,
( T_1 ) V_1017 ,
V_22 -> V_939 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_130 * V_131 = & V_22 -> V_132 [ V_68 ] ;
V_131 -> V_1018 = V_1019 ;
V_131 -> V_24 = ( T_4 ) ( V_22 -> V_633 +
( V_68 * sizeof( struct V_337 ) ) ) ;
V_131 -> V_1020 = sizeof( struct V_337 ) ;
V_131 -> V_1021 = V_1022 ;
V_131 -> V_1023 =
F_160 ( V_1024 ) ;
V_131 -> V_1025 = 0 ;
V_131 -> V_128 = 0 ;
V_131 -> V_348 =
F_134 ( ( V_68 << V_583 ) ) ;
V_131 -> V_1026 =
F_134 ( V_22 -> V_555 +
( V_68 * sizeof( struct V_130 ) ) ) ;
}
} else if ( V_916 & V_952 ) {
T_5 V_827 , V_829 ;
T_4 V_1027 , V_828 ;
int V_21 ;
V_21 = F_348 ( V_22 -> V_29 , V_22 -> V_152 , & V_828 ,
& V_829 , & V_827 ) ;
F_281 ( F_249 ( struct V_139 , V_269 ) != 64 ) ;
V_1002 [ 15 ] = V_22 -> V_552 + F_461 ;
F_458 ( V_1002 , F_26 ( V_1002 ) , V_22 -> V_552 ,
4 , V_22 -> V_138 ) ;
V_1027 = F_334 ( & V_22 -> V_824 -> V_1028 ) ;
F_281 ( F_249 ( struct V_823 ,
V_1028 ) != 0xb8 ) ;
V_22 -> V_1029 =
F_313 ( F_349 ( V_22 -> V_29 ,
V_829 ) +
V_827 + V_1027 ,
F_26 ( V_1002 ) *
sizeof( * V_22 -> V_1029 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_1002 ) ; V_68 ++ )
F_60 ( V_1002 [ V_68 ] , & V_22 -> V_1029 [ V_68 ] ) ;
}
F_60 ( V_914 , V_22 -> V_152 + V_819 ) ;
if ( F_379 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_318 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_462 ( struct V_1 * V_22 )
{
if ( V_22 -> V_132 ) {
F_335 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
V_22 -> V_132 ,
V_22 -> V_555 ) ;
V_22 -> V_132 = NULL ;
V_22 -> V_555 = 0 ;
}
F_81 ( V_22 -> V_134 ) ;
V_22 -> V_134 = NULL ;
}
static int F_463 ( struct V_1 * V_22 )
{
V_22 -> V_552 =
F_334 ( & ( V_22 -> V_824 -> V_1030 ) ) ;
if ( V_22 -> V_552 > V_1031 )
V_22 -> V_552 = V_1031 ;
F_281 ( sizeof( struct V_130 ) %
V_1032 ) ;
V_22 -> V_132 =
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
& ( V_22 -> V_555 ) ) ;
V_22 -> V_134 =
F_92 ( ( ( V_22 -> V_552 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_132 == NULL ) ||
( V_22 -> V_134 == NULL ) )
goto V_932;
memset ( V_22 -> V_132 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ) ;
return 0 ;
V_932:
F_462 ( V_22 ) ;
return - V_261 ;
}
static void F_464 ( struct V_1 * V_22 )
{
F_126 ( V_22 ) ;
if ( V_22 -> V_137 ) {
F_335 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
V_22 -> V_137 ,
V_22 -> V_574 ) ;
V_22 -> V_137 = NULL ;
V_22 -> V_574 = 0 ;
}
F_81 ( V_22 -> V_138 ) ;
V_22 -> V_138 = NULL ;
}
static int F_465 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_552 =
F_334 ( & ( V_22 -> V_824 -> V_1030 ) ) ;
if ( V_22 -> V_552 > V_1003 )
V_22 -> V_552 = V_1003 ;
F_281 ( sizeof( struct V_139 ) %
V_1033 ) ;
V_22 -> V_137 =
F_333 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
& ( V_22 -> V_574 ) ) ;
V_22 -> V_138 =
F_92 ( ( ( V_22 -> V_552 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_137 == NULL ) ||
( V_22 -> V_138 == NULL ) ) {
V_21 = - V_261 ;
goto V_932;
}
V_21 = F_127 ( V_22 ) ;
if ( V_21 )
goto V_932;
memset ( V_22 -> V_137 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ) ;
return 0 ;
V_932:
F_464 ( V_22 ) ;
return V_21 ;
}
static void F_410 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
F_408 ( V_22 ) ;
F_462 ( V_22 ) ;
F_464 ( V_22 ) ;
}
static int F_448 ( struct V_1 * V_22 )
{
T_4 V_916 ;
unsigned long V_63 = V_64 |
V_997 ;
int V_68 , V_21 ;
if ( V_976 )
return 0 ;
V_916 = F_334 ( & ( V_22 -> V_824 -> V_845 ) ) ;
if ( ! ( V_916 & V_1034 ) )
return 0 ;
if ( V_916 & V_114 ) {
V_63 |= V_114 |
V_998 ;
V_21 = F_463 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_916 & V_952 ) {
V_63 |= V_952 |
V_998 ;
V_21 = F_465 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_129 = V_22 -> V_126 > 0 ? V_22 -> V_126 : 1 ;
F_369 ( V_22 ) ;
V_22 -> V_939 = V_22 -> V_121 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
V_22 -> V_113 [ V_68 ] . V_117 = F_333 ( V_22 -> V_29 ,
V_22 -> V_939 ,
& ( V_22 -> V_113 [ V_68 ] . V_122 ) ) ;
if ( ! V_22 -> V_113 [ V_68 ] . V_117 ) {
V_21 = - V_261 ;
goto V_980;
}
V_22 -> V_113 [ V_68 ] . V_466 = V_22 -> V_121 ;
V_22 -> V_113 [ V_68 ] . V_119 = 1 ;
V_22 -> V_113 [ V_68 ] . V_118 = 0 ;
}
V_22 -> V_123 = F_92 ( ( ( V_768 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ! V_22 -> V_123 ) {
V_21 = - V_261 ;
goto V_980;
}
V_21 = F_459 ( V_22 , V_916 ) ;
if ( V_21 )
goto V_925;
return 0 ;
V_925:
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
V_980:
F_408 ( V_22 ) ;
F_462 ( V_22 ) ;
F_464 ( V_22 ) ;
return V_21 ;
}
static int F_466 ( struct V_8 * V_9 )
{
return V_9 -> V_150 == V_151 || V_9 -> V_150 == V_154 ;
}
static void F_422 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1035 ;
int V_240 ;
do {
V_1035 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 )
V_1035 += F_466 ( V_9 ) ;
F_106 ( V_22 , V_9 ) ;
}
if ( V_1035 <= 0 )
break;
F_108 ( 100 ) ;
} while ( 1 );
}
static struct V_1036 * F_467 (
struct V_1037 * V_1037 )
{
struct V_1036 * V_1036 ;
struct V_1038 * V_1039 ;
V_1036 = F_115 ( sizeof( * V_1036 ) , V_203 ) ;
if ( ! V_1036 )
return NULL ;
V_1039 = F_468 ( V_1037 -> V_1040 -> V_1041 ,
V_1037 -> V_1042 ) ;
if ( ! V_1039 ) {
F_81 ( V_1036 ) ;
return NULL ;
}
V_1037 -> V_1042 ++ ;
V_1036 -> V_1039 = V_1039 ;
V_1036 -> V_1043 = V_1037 ;
return V_1036 ;
}
static void F_469 ( struct V_1036 * V_1036 )
{
struct V_1038 * V_1039 = V_1036 -> V_1039 ;
F_470 ( V_1036 -> V_1043 -> V_1044 , V_1039 ) ;
F_471 ( V_1039 ) ;
if ( V_1036 -> V_1045 )
F_428 ( & V_1036 -> V_1046 ) ;
F_81 ( V_1036 ) ;
}
static int F_472 ( struct V_1036 * V_1036 )
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
V_1048 -> V_512 = V_1049 ;
V_1048 -> V_1050 = V_1051 ;
V_1048 -> V_1052 = V_1051 ;
V_1039 -> V_1053 = V_1054 ;
V_1039 -> V_1055 = V_1054 ;
V_1039 -> V_1056 = V_1054 ;
V_1039 -> V_1057 = V_1054 ;
V_1039 -> V_1058 = V_1054 ;
V_21 = F_473 ( V_1036 -> V_1039 ) ;
if ( V_21 )
return V_21 ;
F_474 ( V_1037 -> V_1044 , V_1036 -> V_1039 ) ;
F_93 ( & V_1036 -> V_1046 ,
& V_1037 -> V_1059 ) ;
V_1036 -> V_1045 = true ;
return 0 ;
}
static int
F_475 ( struct V_1037 * V_1037 ,
struct V_254 * V_255 )
{
struct V_1047 * V_1048 ;
V_1048 = & V_255 -> V_1048 ;
V_1048 -> V_89 = V_1037 -> V_89 ;
V_1048 -> V_1050 = V_1051 ;
V_1048 -> V_1052 = V_1051 ;
return F_476 ( V_255 ) ;
}
static struct V_1037
* F_477 ( struct V_1060 * V_1060 ,
T_5 V_89 )
{
int V_21 ;
struct V_1037 * V_1037 ;
struct V_1061 * V_1044 ;
V_1037 = F_115 ( sizeof( * V_1037 ) , V_203 ) ;
if ( ! V_1037 )
return NULL ;
F_441 ( & V_1037 -> V_1059 ) ;
V_1037 -> V_1040 = V_1060 ;
V_1044 = F_478 ( V_1060 -> V_1041 ) ;
if ( ! V_1044 )
goto V_1062;
V_21 = F_479 ( V_1044 ) ;
if ( V_21 )
goto V_1063;
V_1037 -> V_1044 = V_1044 ;
V_1037 -> V_89 = V_89 ;
F_93 ( & V_1037 -> V_1064 ,
& V_1060 -> V_1065 ) ;
return V_1037 ;
V_1063:
F_480 ( V_1044 ) ;
V_1062:
F_81 ( V_1037 ) ;
return NULL ;
}
static void F_481 ( struct V_1037 * V_1037 )
{
struct V_1036 * V_1036 ;
struct V_1036 * V_1066 ;
F_482 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_469 ( V_1036 ) ;
F_483 ( V_1037 -> V_1044 ) ;
F_428 ( & V_1037 -> V_1064 ) ;
F_81 ( V_1037 ) ;
}
static struct V_1060 * F_484 ( struct V_42 * V_1041 )
{
struct V_1060 * V_1060 ;
V_1060 = F_115 ( sizeof( * V_1060 ) , V_203 ) ;
if ( V_1060 ) {
V_1060 -> V_1041 = V_1041 ;
F_441 ( & V_1060 -> V_1065 ) ;
}
return V_1060 ;
}
static void F_485 ( struct V_1060 * V_1060 )
{
struct V_1037 * V_1037 ;
struct V_1037 * V_1066 ;
if ( ! V_1060 )
return;
F_482 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_481 ( V_1037 ) ;
F_81 ( V_1060 ) ;
}
static struct V_73
* F_120 ( struct V_1 * V_22 ,
struct V_254 * V_255 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1061 )
continue;
if ( V_42 -> V_1061 -> V_255 == V_255 )
return V_42 ;
}
return NULL ;
}
static int F_234 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1041 ;
struct V_1060 * V_1060 ;
struct V_1037 * V_1037 ;
struct V_1036 * V_1036 ;
V_1041 = & V_22 -> V_59 -> V_1067 ;
V_1060 = F_484 ( V_1041 ) ;
if ( ! V_1060 )
return - V_261 ;
V_1037 = F_477 ( V_1060 , V_22 -> V_89 ) ;
if ( ! V_1037 ) {
V_21 = - V_81 ;
goto V_1068;
}
V_1036 = F_467 ( V_1037 ) ;
if ( ! V_1036 ) {
V_21 = - V_81 ;
goto V_1063;
}
V_21 = F_472 ( V_1036 ) ;
if ( V_21 )
goto V_1069;
V_22 -> V_238 = V_1060 ;
return 0 ;
V_1069:
F_469 ( V_1036 ) ;
V_1063:
F_481 ( V_1037 ) ;
V_1068:
F_485 ( V_1060 ) ;
return V_21 ;
}
static void F_457 ( struct V_1 * V_22 )
{
F_485 ( V_22 -> V_238 ) ;
}
static int F_102 ( struct V_1060 * V_1060 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1037 * V_1037 ;
struct V_254 * V_255 ;
V_1037 = F_477 ( V_1060 , V_42 -> V_89 ) ;
if ( ! V_1037 )
return - V_261 ;
V_255 = F_486 ( V_1037 -> V_1044 ) ;
if ( ! V_255 ) {
V_21 = - V_81 ;
goto V_1063;
}
V_1037 -> V_255 = V_255 ;
V_42 -> V_1061 = V_1037 ;
V_21 = F_475 ( V_1037 , V_255 ) ;
if ( V_21 )
goto V_1063;
return 0 ;
V_1063:
F_481 ( V_1037 ) ;
V_42 -> V_1061 = NULL ;
return V_21 ;
}
static void F_113 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1061 ) {
F_481 ( V_42 -> V_1061 ) ;
V_42 -> V_1061 = NULL ;
}
}
static int
F_487 ( struct V_1038 * V_1039 )
{
return 0 ;
}
static int
F_488 ( struct V_254 * V_255 , T_5 * V_1070 )
{
* V_1070 = 0 ;
return 0 ;
}
static int
F_489 ( struct V_254 * V_255 )
{
return - V_1071 ;
}
static int
F_490 ( struct V_1038 * V_1039 , int V_1072 )
{
return 0 ;
}
static int
F_491 ( struct V_1038 * V_1039 , int V_1073 )
{
return 0 ;
}
static int
F_492 ( struct V_1038 * V_1039 )
{
return 0 ;
}
static void
F_493 ( struct V_1038 * V_1039 )
{
}
static int
F_494 ( struct V_1038 * V_1039 , struct V_1074 * V_1075 )
{
return - V_55 ;
}
static int
F_495 ( struct V_6 * V_47 , struct V_254 * V_255 ,
struct V_637 * V_1076 )
{
return - V_55 ;
}
static int T_18 F_496 ( void )
{
int V_21 ;
V_658 =
F_497 ( & V_1077 ) ;
if ( ! V_658 )
return - V_81 ;
V_21 = F_498 ( & V_1078 ) ;
if ( V_21 )
F_499 ( V_658 ) ;
return V_21 ;
}
static void T_19 F_500 ( void )
{
F_501 ( & V_1078 ) ;
F_499 ( V_658 ) ;
}
