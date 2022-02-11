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
struct V_73 * V_180 = NULL ;
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
}
if ( ! V_180 )
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
if ( V_284 && V_284 -> V_324 )
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
if ( ! V_284 -> V_42 ) {
V_284 -> V_294 = V_316 << 16 ;
return F_149 ( V_22 , V_131 , V_284 ) ;
}
V_30 = V_284 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_284 -> V_294 = V_316 << 16 ;
return F_149 ( V_22 , V_131 , V_284 ) ;
}
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
if ( V_131 -> V_150 == V_154 || V_131 -> V_150 == V_151 ) {
if ( V_30 -> V_74 && V_30 -> V_90 &&
V_30 -> V_191 ) {
V_284 -> V_294 = V_316 << 16 ;
return F_149 ( V_22 , V_131 , V_284 ) ;
}
if ( F_48 ( V_131 -> V_236 != NULL ) )
F_46 ( & V_131 -> V_236 -> V_256 ) ;
}
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
if ( ! F_185 ( V_22 , V_72 ,
V_405 ) )
goto exit;
V_21 = F_175 ( V_22 , V_72 , V_406 |
V_405 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_83 = V_45 [ 8 ] ;
if ( * V_83 > V_84 )
* V_83 = V_84 ;
exit:
F_81 ( V_45 ) ;
return;
}
static void F_186 ( struct V_1 * V_22 , int V_21 ,
struct V_221 * V_407 )
{
struct V_223 * V_224 = & V_407 -> V_225 [ 0 ] ;
int V_222 , V_408 , V_409 ;
T_6 V_410 , V_230 , V_411 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_95 ( & V_22 -> V_29 -> V_30 , L_122 ,
F_131 ( V_407 -> V_412 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_123 ,
F_131 ( V_407 -> V_413 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_124 ,
F_136 ( V_407 -> V_414 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_125 ,
V_407 -> V_415 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_126 ,
V_407 -> V_416 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_127 ,
F_97 ( V_407 -> V_417 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_128 ,
F_136 ( V_407 -> V_418 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_129 ,
F_136 ( V_407 -> V_419 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_130 ,
F_97 ( V_407 -> V_227 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_131 ,
F_97 ( V_407 -> V_228 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_132 ,
F_97 ( V_407 -> V_230 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_133 ,
F_97 ( V_407 -> V_231 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_134 ,
F_97 ( V_407 -> V_78 ) ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_135 ,
F_97 ( V_407 -> V_78 ) &
V_420 ? L_136 : L_137 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_138 ,
F_97 ( V_407 -> V_421 ) ) ;
V_410 = F_97 ( V_407 -> V_231 ) ;
for ( V_222 = 0 ; V_222 < V_410 ; V_222 ++ ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_139 , V_222 ) ;
V_230 = F_97 ( V_407 -> V_230 ) ;
for ( V_408 = 0 ; V_408 < V_230 ; V_408 ++ ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_140 , V_408 ) ;
V_411 =
F_97 ( V_407 -> V_227 ) ;
for ( V_409 = 0 ; V_409 < V_411 ; V_409 ++ , V_224 ++ )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_141 ,
V_409 , V_224 -> V_187 ,
V_224 -> V_422 [ 0 ] , V_224 -> V_422 [ 1 ] ) ;
V_411 =
F_97 ( V_407 -> V_228 ) ;
for ( V_409 = 0 ; V_409 < V_411 ; V_409 ++ , V_224 ++ )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_142 ,
V_409 , V_224 -> V_187 ,
V_224 -> V_422 [ 0 ] , V_224 -> V_422 [ 1 ] ) ;
}
}
}
static int F_187 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_423 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_424 , V_22 , & V_423 -> V_186 ,
sizeof( V_423 -> V_186 ) , 0 ,
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
if ( F_131 ( V_423 -> V_186 . V_412 ) >
sizeof( V_423 -> V_186 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_144 ) ;
V_21 = - 1 ;
}
F_186 ( V_22 , V_21 , & V_423 -> V_186 ) ;
return V_21 ;
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_188 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_425 ,
struct V_426 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_427 , V_22 , V_45 , V_391 ,
0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
V_9 -> V_144 . V_145 [ 2 ] = V_425 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_425 >> 8 ) & 0xff ;
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
struct V_428 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_429 , V_22 , V_45 , V_391 ,
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
static int F_190 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_425 ,
struct V_430 * V_45 , T_3 V_391 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_431 , V_22 , V_45 , V_391 ,
0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
V_9 -> V_144 . V_145 [ 2 ] = V_425 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_425 >> 8 ) & 0xff ;
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
static void F_191 ( struct V_1 * V_22 ,
unsigned char * V_72 ,
struct V_432 * V_433 , int V_434 ,
struct V_73 * V_435 )
{
int V_21 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_337 * V_338 = NULL ;
struct V_436 * V_437 = NULL ;
struct V_430 * V_438 = NULL ;
struct V_439 * V_440 = & V_433 -> V_349 [ V_434 ] ;
T_6 V_425 = 0 ;
V_425 = F_192 ( & V_440 -> V_86 [ 0 ] ) ;
if ( V_425 == 0xFF00 || F_193 ( & V_440 -> V_86 [ 0 ] ) ) {
V_21 = V_381 ;
goto V_394;
}
V_437 = F_115 ( sizeof( * V_437 ) , V_203 ) ;
if ( ! V_437 )
goto V_394;
V_438 = F_115 ( sizeof( * V_438 ) , V_203 ) ;
if ( ! V_438 )
goto V_394;
V_21 = F_190 ( V_22 , V_72 , V_425 ,
V_438 , sizeof( * V_438 ) ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_145 ,
V_204 , V_435 -> V_167 , V_425 ) ;
goto V_394;
}
V_9 = F_176 ( V_22 ) ;
V_21 = F_177 ( V_9 , V_441 , V_22 , V_437 ,
sizeof( * V_437 ) , 0 , V_158 , V_393 ) ;
if ( V_21 )
goto V_394;
if ( V_438 -> V_97 [ 1 ] == 'E' )
V_9 -> V_144 . V_145 [ 5 ] = V_438 -> V_442 ;
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
V_435 -> V_93 [ V_438 -> V_443 ] = V_437 -> V_444 ;
memcpy ( & V_435 -> V_97 [ V_438 -> V_443 ] ,
V_437 -> V_97 , sizeof( V_437 -> V_97 ) ) ;
V_21 = V_381 ;
V_394:
F_81 ( V_437 ) ;
F_81 ( V_438 ) ;
if ( V_9 )
F_106 ( V_22 , V_9 ) ;
if ( V_21 != V_381 )
F_70 ( V_182 , V_22 , V_435 ,
L_146 ) ;
}
static T_5 F_194 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_432 * V_445 ;
T_4 V_446 ;
T_5 V_447 = 0 ;
int V_68 ;
V_445 = F_115 ( sizeof( * V_445 ) , V_203 ) ;
if ( ! V_445 )
return 0 ;
if ( F_195 ( V_22 , V_445 , sizeof( * V_445 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
F_81 ( V_445 ) ;
return 0 ;
}
V_446 = F_196 ( V_445 -> V_448 ) / 24 ;
for ( V_68 = 0 ; V_68 < V_446 ; V_68 ++ )
if ( ! memcmp ( & V_445 -> V_349 [ V_68 ] . V_86 [ 0 ] , V_72 , 8 ) ) {
V_447 = F_197 ( & V_445 -> V_349 [ V_68 ] . V_449 [ 0 ] ) ;
break;
}
F_81 ( V_445 ) ;
return V_447 ;
}
static void F_198 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_73 * V_30 )
{
int V_21 ;
T_5 V_447 = 0 ;
if ( F_63 ( V_72 ) ) {
struct V_426 * V_450 ;
V_450 = F_115 ( sizeof( * V_450 ) , V_203 ) ;
if ( V_450 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_148 , V_204 ) ;
return;
}
V_21 = F_188 ( V_22 ,
V_72 , 0 , V_450 , sizeof( * V_450 ) ) ;
if ( V_21 == 0 ) {
V_447 = F_197 ( V_450 -> V_451 ) ;
V_22 -> V_89 = V_447 ;
}
F_81 ( V_450 ) ;
} else
V_447 = F_194 ( V_22 , V_72 ) ;
V_30 -> V_89 = V_447 ;
}
static bool F_185 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_390 )
{
int V_21 ;
int V_68 ;
int V_452 ;
unsigned char * V_45 , V_391 ;
V_45 = F_115 ( 256 , V_203 ) ;
if ( ! V_45 )
return false ;
V_21 = F_175 ( V_22 , V_72 ,
V_406 | V_453 ,
V_45 , V_454 ) ;
if ( V_21 != 0 )
goto V_455;
V_452 = V_45 [ 3 ] ;
if ( ( V_452 + V_454 ) <= 255 )
V_391 = V_452 + V_454 ;
else
V_391 = 255 ;
V_21 = F_175 ( V_22 , V_72 ,
V_406 | V_453 ,
V_45 , V_391 ) ;
if ( V_21 != 0 )
goto V_455;
V_452 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_452 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_390 )
goto V_456;
V_455:
F_81 ( V_45 ) ;
return false ;
V_456:
F_81 ( V_45 ) ;
return true ;
}
static void F_199 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_73 * V_423 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_457 ;
V_423 -> V_174 = 0 ;
V_423 -> V_91 = 0 ;
V_423 -> V_183 = 0 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return;
if ( ! F_185 ( V_22 , V_72 , V_458 ) )
goto V_394;
V_21 = F_175 ( V_22 , V_72 ,
V_406 | V_458 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_394;
#define F_200 4
#define F_201 0x01
#define F_202 0x02
V_457 = V_45 [ F_200 ] ;
V_423 -> V_174 =
! ! ( V_457 & F_201 ) ;
if ( V_423 -> V_174 ) {
V_423 -> V_91 =
! ! ( V_457 & F_202 ) ;
if ( F_187 ( V_22 , V_72 , V_423 ) )
V_423 -> V_91 = 0 ;
}
V_423 -> V_183 = V_423 -> V_91 ;
V_394:
F_81 ( V_45 ) ;
return;
}
static int F_203 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_88 , int V_199 , int V_373 )
{
int V_21 ;
unsigned char * V_45 ;
if ( ! F_185 ( V_22 , V_72 , V_459 ) )
return 1 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return - V_261 ;
V_21 = F_175 ( V_22 , V_72 , V_406 |
V_459 , V_45 , 64 ) ;
if ( V_21 == 0 ) {
if ( V_373 > 16 )
V_373 = 16 ;
memcpy ( V_88 , & V_45 [ 8 ] , V_373 ) ;
}
F_81 ( V_45 ) ;
return V_21 ;
}
static int F_204 ( struct V_1 * V_22 , int V_460 ,
void * V_45 , int V_391 ,
int V_461 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_337 * V_338 ;
V_9 = F_176 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_177 ( V_9 , V_460 ? V_462 : V_463 , V_22 ,
V_45 , V_391 , 0 , V_72 , V_393 ) ) {
V_21 = - 1 ;
goto V_394;
}
if ( V_461 )
V_9 -> V_144 . V_145 [ 1 ] = V_461 ;
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
struct V_464 * V_465 = V_45 ;
if ( V_465 -> V_466 != V_461 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_149 ,
V_461 ,
V_465 -> V_466 ) ;
V_21 = - 1 ;
}
}
V_394:
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_195 ( struct V_1 * V_22 ,
struct V_432 * V_45 , int V_391 )
{
return F_204 ( V_22 , 0 , V_45 , V_391 ,
V_467 ) ;
}
static inline int F_205 ( struct V_1 * V_22 ,
struct V_464 * V_45 , int V_391 )
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
int V_468 ;
unsigned char * V_45 ;
V_45 = F_115 ( 64 , V_203 ) ;
if ( ! V_45 )
return V_207 ;
if ( ! F_185 ( V_22 , V_72 , V_469 ) )
goto V_470;
V_21 = F_175 ( V_22 , V_72 , V_406 | V_469 ,
V_45 , V_454 ) ;
if ( V_21 != 0 )
goto V_470;
V_468 = V_45 [ 3 ] ;
V_21 = F_175 ( V_22 , V_72 , V_406 | V_469 ,
V_45 , V_468 + V_454 ) ;
if ( V_21 != 0 )
goto V_470;
V_49 = V_45 [ 4 ] ;
F_81 ( V_45 ) ;
return V_49 ;
V_470:
F_81 ( V_45 ) ;
return V_207 ;
}
static int F_208 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_471 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_472 = 0 ;
T_6 V_473 ;
T_1 V_474 ;
#define F_209 0x04
#define F_210 0x04
#define F_211 0x02
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_475 , V_22 , NULL , 0 , 0 , V_72 , V_393 ) ;
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_396 ) ;
if ( V_21 ) {
F_106 ( V_22 , V_9 ) ;
return 0 ;
}
V_471 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_471 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_473 = V_9 -> V_24 -> V_36 ;
V_474 = V_9 -> V_24 -> V_38 ;
F_106 ( V_22 , V_9 ) ;
if ( V_473 != V_37 ||
V_474 != V_295 ||
V_16 != V_476 ||
V_17 != F_209 ) {
return 0 ;
}
V_472 = F_207 ( V_22 , V_72 ) ;
switch ( V_472 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
return V_472 ;
case V_207 :
if ( ( V_18 == F_210 ) ||
( V_18 == F_211 ) )
return V_472 ;
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
( void ) F_177 ( V_9 , V_477 , V_22 , & V_348 , 0 , 0 , V_72 , V_398 ) ;
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
unsigned char V_72 [] , struct V_73 * V_423 ,
unsigned char * V_478 )
{
#define F_214 43
#define F_215 "$DR-10"
#define F_216 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_217 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_479 ;
unsigned char * V_480 ;
int V_21 = 0 ;
V_479 = F_115 ( F_217 , V_203 ) ;
if ( ! V_479 ) {
V_21 = - V_261 ;
goto V_481;
}
if ( F_175 ( V_22 , V_72 , 0 , V_479 ,
( unsigned char ) F_217 ) != 0 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_150 ) ;
V_21 = - V_387 ;
goto V_481;
}
F_218 ( & V_479 [ 8 ] , 8 ) ;
F_218 ( & V_479 [ 16 ] , 16 ) ;
V_423 -> V_106 = ( V_479 [ 0 ] & 0x1f ) ;
memcpy ( V_423 -> V_72 , V_72 , 8 ) ;
memcpy ( V_423 -> V_172 , & V_479 [ 8 ] ,
sizeof( V_423 -> V_172 ) ) ;
memcpy ( V_423 -> V_173 , & V_479 [ 16 ] ,
sizeof( V_423 -> V_173 ) ) ;
V_423 -> V_482 = V_479 [ 2 ] ;
memset ( V_423 -> V_88 , 0 ,
sizeof( V_423 -> V_88 ) ) ;
if ( F_203 ( V_22 , V_72 , V_423 -> V_88 , 8 ,
sizeof( V_423 -> V_88 ) ) )
F_74 ( & V_22 -> V_29 -> V_30 ,
L_151 ,
V_22 -> V_483 , V_204 ,
V_22 -> V_59 -> V_102 ,
V_423 -> V_104 , V_423 -> V_105 ,
F_43 ( V_423 -> V_106 ) ,
V_423 -> V_173 ) ;
if ( ( V_423 -> V_106 == V_108 ||
V_423 -> V_106 == V_109 ) &&
F_31 ( V_72 ) ) {
int V_200 ;
F_184 ( V_22 , V_72 , & V_423 -> V_83 ) ;
if ( V_22 -> V_484 & V_485 )
F_199 ( V_22 , V_72 , V_423 ) ;
V_200 = F_208 ( V_22 , V_72 ) ;
if ( V_200 < 0 || V_200 > 0xff )
V_200 = V_207 ;
V_423 -> V_200 = V_200 & 0xff ;
} else {
V_423 -> V_83 = V_84 ;
V_423 -> V_174 = 0 ;
V_423 -> V_91 = 0 ;
V_423 -> V_183 = 0 ;
V_423 -> V_188 = 0 ;
V_423 -> V_200 = 0 ;
V_423 -> V_190 = V_22 -> V_237 ;
}
if ( V_478 ) {
V_480 = & V_479 [ F_214 ] ;
* V_478 = ( V_423 -> V_106 == V_169 &&
strncmp ( V_480 , F_215 ,
F_216 ) == 0 ) ;
}
F_81 ( V_479 ) ;
return 0 ;
V_481:
F_81 ( V_479 ) ;
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
V_30 -> V_486 = V_22 -> V_30 [ V_184 ] -> V_486 ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
} else {
F_36 ( & V_22 -> V_98 , V_78 ) ;
V_30 -> V_486 =
F_212 ( V_22 , V_72 ) ;
if ( V_30 -> V_486 < 0 )
V_30 -> V_486 = 0 ;
}
}
static void F_220 ( struct V_1 * V_22 ,
T_1 * V_487 , struct V_73 * V_42 )
{
T_4 V_86 = F_142 ( V_487 ) ;
if ( ! F_31 ( V_487 ) ) {
if ( F_63 ( V_487 ) ) {
int V_103 = V_488 ;
if ( ! V_42 -> V_482 )
V_103 = V_489 ;
F_206 ( V_42 ,
V_103 , 0 , V_86 & 0x3fff ) ;
} else
F_206 ( V_42 ,
V_251 , - 1 , - 1 ) ;
return;
}
if ( V_42 -> V_167 ) {
F_206 ( V_42 ,
V_490 , ( V_86 >> 16 ) & 0x3fff ,
V_86 & 0x00ff ) ;
return;
}
F_206 ( V_42 , V_491 ,
0 , V_86 & 0x3fff ) ;
}
static int F_221 ( struct V_1 * V_22 ,
struct V_8 * V_492 , unsigned char * V_72 )
{
struct V_139 * V_285 =
& V_22 -> V_137 [ V_492 -> V_133 ] ;
unsigned long V_78 ;
int V_68 ;
F_35 ( & V_22 -> V_98 , V_78 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_187 == F_131 ( V_285 -> V_493 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 1 ;
}
F_36 ( & V_22 -> V_98 , V_78 ) ;
return 0 ;
}
static int F_222 ( struct V_1 * V_22 , int V_494 ,
int V_68 , int V_446 , int V_495 )
{
int V_496 = V_446 + ( V_494 == 0 ) ;
if ( V_68 == V_494 )
return 0 ;
if ( V_68 < V_496 )
return 0 ;
if ( ( V_68 - V_446 - ( V_494 == 0 ) ) < V_495 )
return 0 ;
return 1 ;
}
static int F_223 ( struct V_1 * V_22 ,
struct V_432 * V_445 , T_4 * V_446 ,
struct V_464 * V_497 , T_4 * V_498 )
{
if ( F_195 ( V_22 , V_445 , sizeof( * V_445 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
return - 1 ;
}
* V_446 = F_224 ( * ( ( V_499 * ) V_445 -> V_448 ) ) / 24 ;
if ( * V_446 > V_500 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_152 ,
V_500 , * V_446 - V_500 ) ;
* V_446 = V_500 ;
}
if ( F_205 ( V_22 , V_497 , sizeof( * V_497 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_153 ) ;
return - 1 ;
}
* V_498 = F_224 ( * ( ( V_499 * ) V_497 -> V_448 ) ) / 8 ;
if ( * V_498 > V_501 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_154
L_155 , V_501 ,
* V_498 - V_501 ) ;
* V_498 = V_501 ;
}
if ( * V_498 + * V_446 > V_500 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_156
L_155 , V_500 ,
* V_446 + * V_498 - V_500 ) ;
* V_498 = V_500 - * V_446 ;
}
return 0 ;
}
static T_1 * F_225 ( struct V_1 * V_22 , int V_494 ,
int V_68 , int V_446 , int V_498 ,
struct V_432 * V_502 ,
struct V_464 * V_503 )
{
int V_496 = V_446 + ( V_494 == 0 ) ;
int V_504 = V_446 + V_498 + ( V_494 == 0 ) ;
if ( V_68 == V_494 )
return V_158 ;
if ( V_68 < V_496 )
return & V_502 -> V_349 [ V_68 -
( V_494 == 0 ) ] . V_86 [ 0 ] ;
if ( V_68 < V_504 )
return & V_503 -> V_349 [ V_68 - V_446 -
( V_494 == 0 ) ] [ 0 ] ;
F_179 () ;
return NULL ;
}
static void F_226 ( struct V_1 * V_22 ,
struct V_73 * V_30 ,
struct V_432 * V_433 , int V_434 ,
struct V_430 * V_438 )
{
int V_21 ;
struct V_439 * V_440 ;
if ( V_30 -> V_167 ) {
V_30 -> V_190 = 7 ;
return;
}
V_440 = & V_433 -> V_349 [ V_434 ] ;
V_30 -> V_187 = V_440 -> V_187 ;
if ( ( V_440 -> V_505 & 0x08 ) && V_30 -> V_187 )
V_30 -> V_188 = 1 ;
memset ( V_438 , 0 , sizeof( * V_438 ) ) ;
V_21 = F_190 ( V_22 , & V_440 -> V_86 [ 0 ] ,
F_192 ( & V_440 -> V_86 [ 0 ] ) , V_438 ,
sizeof( * V_438 ) ) ;
if ( ! V_21 )
#define F_227 2
#define F_228 7
V_30 -> V_190 =
F_97 ( V_438 -> V_506 ) -
F_227 ;
else
V_30 -> V_190 = F_228 ;
}
static void F_229 ( struct V_73 * V_423 ,
struct V_432 * V_433 , int V_434 ,
struct V_430 * V_438 )
{
struct V_439 * V_440 = & V_433 -> V_349 [ V_434 ] ;
if ( ( V_440 -> V_505 & 0x08 ) && V_423 -> V_187 )
V_423 -> V_188 = 1 ;
memcpy ( & V_423 -> V_100 ,
& V_438 -> V_443 ,
sizeof( V_423 -> V_100 ) ) ;
memcpy ( & V_423 -> V_101 ,
& V_438 -> V_507 ,
sizeof( V_423 -> V_101 ) ) ;
memcpy ( & V_423 -> V_93 ,
& V_438 -> V_508 ,
sizeof( V_423 -> V_93 ) ) ;
memcpy ( & V_423 -> V_97 ,
& V_438 -> V_509 ,
sizeof( V_423 -> V_97 ) ) ;
memcpy ( & V_423 -> V_94 ,
& V_438 -> V_510 ,
sizeof( V_423 -> V_94 ) ) ;
}
static int F_230 ( struct V_1 * V_22 ,
struct V_428 * V_511 ,
T_4 * V_512 )
{
int V_21 ;
if ( ! V_511 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_157 ,
V_204 ) ;
return - V_261 ;
}
memset ( V_511 , 0 , sizeof( * V_511 ) ) ;
V_21 = F_189 ( V_22 , V_511 , sizeof( * V_511 ) ) ;
if ( ! V_21 )
if ( V_511 -> V_513 < 256 )
* V_512 = V_511 -> V_513 ;
else
* V_512 = F_97 (
V_511 -> V_514 ) ;
else
* V_512 = - 1 ;
return V_21 ;
}
static bool F_231 ( struct V_1 * V_22 , T_1 * V_487 )
{
struct V_430 * V_438 ;
bool V_515 = false ;
int V_21 ;
V_438 = F_115 ( sizeof( * V_438 ) , V_203 ) ;
if ( ! V_438 )
return false ;
V_21 = F_190 ( V_22 ,
V_487 ,
F_192 ( V_487 ) ,
V_438 , sizeof( * V_438 ) ) ;
if ( V_21 == 0 )
V_515 = ( V_438 -> V_516 >> 6 ) & 0x01 ;
F_81 ( V_438 ) ;
return V_515 ;
}
static bool F_232 ( struct V_1 * V_22 , T_1 * V_487 ,
struct V_439 * V_440 )
{
T_1 V_505 ;
T_1 V_517 ;
if ( ! F_193 ( V_487 ) )
return false ;
V_505 = V_440 -> V_505 ;
V_517 = V_440 -> V_517 ;
if ( V_505 & V_518 ) {
if ( V_517 == V_519 )
return false ;
return true ;
}
if ( ! ( V_505 & V_520 ) )
return false ;
if ( V_505 & V_521 )
return false ;
if ( F_231 ( V_22 , V_487 ) )
return true ;
return false ;
}
static void F_233 ( struct V_1 * V_22 )
{
struct V_432 * V_502 = NULL ;
struct V_464 * V_503 = NULL ;
struct V_430 * V_438 = NULL ;
struct V_428 * V_511 = NULL ;
T_4 V_446 = 0 ;
T_4 V_498 = 0 ;
T_4 V_495 = 0 ;
T_4 V_522 = 0 ;
struct V_73 * * V_523 , * V_423 , * V_524 ;
int V_525 = 0 ;
int V_68 , V_526 , V_527 ;
int V_494 ;
bool V_74 ;
F_66 ( V_528 , V_529 ) ;
V_523 = F_115 ( sizeof( * V_523 ) * V_161 , V_203 ) ;
V_502 = F_115 ( sizeof( * V_502 ) , V_203 ) ;
V_503 = F_115 ( sizeof( * V_503 ) , V_203 ) ;
V_524 = F_115 ( sizeof( * V_524 ) , V_203 ) ;
V_438 = F_115 ( sizeof( * V_438 ) , V_203 ) ;
V_511 = F_115 ( sizeof( * V_511 ) , V_203 ) ;
if ( ! V_523 || ! V_502 || ! V_503 ||
! V_524 || ! V_438 || ! V_511 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_158 ) ;
goto V_394;
}
memset ( V_528 , 0 , sizeof( V_528 ) ) ;
V_22 -> V_249 = 0 ;
if ( F_223 ( V_22 , V_502 , & V_446 ,
V_503 , & V_498 ) ) {
V_22 -> V_249 = 1 ;
goto V_394;
}
if ( F_230 ( V_22 , V_511 , & V_495 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_159 ,
V_204 ) ;
}
V_527 = V_446 + V_498 + V_529 + 1 ;
for ( V_68 = 0 ; V_68 < V_527 ; V_68 ++ ) {
if ( V_68 >= V_161 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_160
L_161 , V_161 ,
V_527 - V_161 ) ;
break;
}
V_523 [ V_68 ] = F_115 ( sizeof( * V_523 [ V_68 ] ) , V_203 ) ;
if ( ! V_523 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_162 ,
__FILE__ , __LINE__ ) ;
V_22 -> V_249 = 1 ;
goto V_394;
}
V_522 ++ ;
}
if ( F_64 ( V_22 ) )
V_494 = 0 ;
else
V_494 = V_446 + V_498 ;
V_526 = 0 ;
for ( V_68 = 0 ; V_68 < V_446 + V_498 + 1 ; V_68 ++ ) {
T_1 * V_487 , V_530 = 0 ;
int V_21 = 0 ;
int V_531 = V_68 - ( V_494 == 0 ) ;
bool V_532 = false ;
V_74 = V_68 < V_446 + ( V_494 == 0 ) ;
V_487 = F_225 ( V_22 , V_494 ,
V_68 , V_446 , V_498 , V_502 , V_503 ) ;
V_524 -> V_167 =
F_222 ( V_22 , V_494 , V_68 ,
V_446 , V_495 ) ;
if ( ! V_524 -> V_167 && V_74 ) {
V_532 = F_232 ( V_22 , V_487 ,
& V_502 -> V_349 [ V_531 ] ) ;
if ( V_532 )
continue;
}
V_21 = F_213 ( V_22 , V_487 , V_524 ,
& V_530 ) ;
if ( V_21 == - V_261 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_163 ) ;
V_22 -> V_249 = 1 ;
goto V_394;
}
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_164 ) ;
continue;
}
F_220 ( V_22 , V_487 , V_524 ) ;
F_219 ( V_22 , V_524 , V_487 ) ;
V_423 = V_523 [ V_525 ] ;
if ( ! V_22 -> V_533 ) {
if ( V_524 -> V_167 ) {
V_22 -> V_533 = 1 ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_165 ) ;
}
}
* V_423 = * V_524 ;
V_423 -> V_74 = V_74 ;
if ( F_193 ( V_487 ) && V_423 -> V_74 )
V_423 -> V_90 = 0 ;
else
V_423 -> V_90 = 1 ;
if ( V_423 -> V_74 && V_423 -> V_90 )
F_198 ( V_22 , V_487 , V_423 ) ;
switch ( V_423 -> V_106 ) {
case V_169 :
if ( V_530 )
V_525 ++ ;
break;
case V_108 :
case V_109 :
if ( V_423 -> V_74 ) {
V_423 -> V_91 = 0 ;
F_226 ( V_22 , V_423 ,
V_502 , V_531 , V_438 ) ;
F_229 ( V_423 ,
V_502 , V_531 , V_438 ) ;
}
V_525 ++ ;
break;
case V_170 :
case V_171 :
V_525 ++ ;
break;
case V_166 :
if ( ! V_423 -> V_167 )
F_191 ( V_22 , V_487 ,
V_502 , V_531 ,
V_423 ) ;
V_525 ++ ;
break;
case V_107 :
if ( ! F_63 ( V_487 ) )
break;
V_525 ++ ;
break;
default:
break;
}
if ( V_525 >= V_161 )
break;
}
if ( V_22 -> V_238 == NULL ) {
int V_21 = 0 ;
V_21 = F_234 ( V_22 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_166 , V_21 ) ;
goto V_394;
}
}
F_114 ( V_22 , V_523 , V_525 ) ;
V_394:
F_81 ( V_524 ) ;
for ( V_68 = 0 ; V_68 < V_522 ; V_68 ++ )
F_81 ( V_523 [ V_68 ] ) ;
F_81 ( V_523 ) ;
F_81 ( V_502 ) ;
F_81 ( V_503 ) ;
F_81 ( V_511 ) ;
F_81 ( V_438 ) ;
}
static void F_235 ( struct V_274 * V_534 ,
struct V_535 * V_269 )
{
T_5 V_374 = ( T_5 ) F_236 ( V_269 ) ;
unsigned int V_50 = F_237 ( V_269 ) ;
V_534 -> V_282 = F_134 ( V_374 ) ;
V_534 -> V_281 = F_139 ( V_50 ) ;
V_534 -> V_278 = 0 ;
}
static int F_238 ( struct V_1 * V_22 ,
struct V_8 * V_131 ,
struct V_283 * V_284 )
{
struct V_535 * V_269 ;
int V_536 , V_68 , V_537 , V_538 , V_539 ;
struct V_274 * V_540 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
V_536 = F_239 ( V_284 ) ;
if ( V_536 < 0 )
return V_536 ;
if ( ! V_536 )
goto V_541;
V_540 = V_131 -> V_276 ;
V_538 = V_536 > V_22 -> V_277 ;
V_537 = V_538 ? V_22 -> V_277 - 1 : V_536 ;
V_539 = F_159 ( V_284 ) - 1 ;
F_240 (cmd, sg, sg_limit, i) {
F_235 ( V_540 , V_269 ) ;
V_540 ++ ;
}
if ( V_538 ) {
V_540 = V_22 -> V_264 [ V_131 -> V_133 ] ;
V_537 = V_536 - V_537 ;
F_241 (sg, sg, sg_limit, i) {
F_235 ( V_540 , V_269 ) ;
V_540 ++ ;
}
}
( V_540 - 1 ) -> V_278 = F_139 ( V_376 ) ;
if ( V_536 + V_538 > V_22 -> V_542 )
V_22 -> V_542 = V_536 + V_538 ;
if ( V_538 ) {
V_131 -> V_124 . V_125 = V_22 -> V_277 ;
V_131 -> V_124 . V_280 = F_160 ( V_536 + 1 ) ;
if ( F_138 ( V_22 , V_131 ) ) {
F_158 ( V_284 ) ;
return - 1 ;
}
return 0 ;
}
V_541:
V_131 -> V_124 . V_125 = ( T_1 ) V_536 ;
V_131 -> V_124 . V_280 = F_160 ( V_536 ) ;
return 0 ;
}
static int F_242 ( T_1 * V_141 , int * V_543 )
{
int V_544 = 0 ;
T_4 V_545 ;
T_4 V_546 ;
switch ( V_141 [ 0 ] ) {
case V_547 :
case V_548 :
V_544 = 1 ;
case V_549 :
case V_550 :
if ( * V_543 == 6 ) {
V_545 = ( ( ( V_141 [ 1 ] & 0x1F ) << 16 ) |
( V_141 [ 2 ] << 8 ) |
V_141 [ 3 ] ) ;
V_546 = V_141 [ 4 ] ;
if ( V_546 == 0 )
V_546 = 256 ;
} else {
F_76 ( * V_543 != 12 ) ;
V_545 = F_196 ( & V_141 [ 2 ] ) ;
V_546 = F_196 ( & V_141 [ 6 ] ) ;
}
if ( V_546 > 0xffff )
return V_551 ;
V_141 [ 0 ] = V_544 ? V_552 : V_553 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_545 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_545 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_545 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_545 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_546 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_546 ) ;
V_141 [ 9 ] = 0 ;
* V_543 = 10 ;
break;
}
return 0 ;
}
static int F_243 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_543 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_130 * V_131 = & V_22 -> V_132 [ V_9 -> V_133 ] ;
unsigned int V_50 ;
unsigned int V_554 = 0 ;
struct V_535 * V_269 ;
T_5 V_374 ;
int V_536 , V_68 ;
struct V_274 * V_540 ;
T_4 V_555 = V_556 ;
if ( F_159 ( V_284 ) > V_22 -> V_557 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_551 ;
}
F_76 ( V_284 -> V_558 > V_559 ) ;
if ( F_242 ( V_141 , & V_543 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_551 ;
}
V_9 -> V_150 = V_151 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_560 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
V_536 = F_239 ( V_284 ) ;
if ( V_536 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_536 ;
}
if ( V_536 ) {
V_540 = V_131 -> V_276 ;
F_240 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_236 ( V_269 ) ;
V_50 = F_237 ( V_269 ) ;
V_554 += V_50 ;
V_540 -> V_282 = F_134 ( V_374 ) ;
V_540 -> V_281 = F_139 ( V_50 ) ;
V_540 -> V_278 = F_139 ( 0 ) ;
V_540 ++ ;
}
( -- V_540 ) -> V_278 = F_139 ( V_376 ) ;
switch ( V_284 -> V_561 ) {
case V_562 :
V_555 |= V_563 ;
break;
case V_564 :
V_555 |= V_565 ;
break;
case V_566 :
V_555 |= V_567 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_167 ,
V_284 -> V_561 ) ;
F_179 () ;
break;
}
} else {
V_555 |= V_567 ;
}
V_9 -> V_124 . V_125 = V_536 ;
V_131 -> V_568 = F_160 ( V_187 & 0xFFFF ) ;
V_131 -> V_569 = F_139 ( V_554 ) ;
V_131 -> V_346 = F_160 ( V_570 |
( V_543 & V_347 ) ) ;
V_131 -> V_555 = F_139 ( V_555 ) ;
memcpy ( V_131 -> V_145 , V_141 , V_543 ) ;
memcpy ( V_131 -> V_351 , V_72 , 8 ) ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_244 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
if ( ! V_30 )
return - 1 ;
V_9 -> V_236 = V_30 ;
return F_245 ( V_22 , V_9 , V_30 -> V_187 ,
V_284 -> V_571 , V_284 -> V_558 , V_30 -> V_72 , V_30 ) ;
}
static void F_246 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_139 * V_131 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
T_5 V_572 ;
if ( ! ( F_97 ( V_222 -> V_78 ) & V_420 ) )
return;
V_131 -> V_421 = V_222 -> V_421 ;
V_131 -> V_573 |= V_574 ;
switch ( V_284 -> V_571 [ 0 ] ) {
case V_549 :
case V_547 :
V_572 = ( ( ( V_284 -> V_571 [ 1 ] & 0x1F ) << 16 ) |
( V_284 -> V_571 [ 2 ] << 8 ) |
V_284 -> V_571 [ 3 ] ) ;
break;
case V_552 :
case V_553 :
case V_548 :
case V_550 :
V_572 = F_196 ( & V_284 -> V_571 [ 2 ] ) ;
break;
case V_575 :
case V_576 :
V_572 = F_197 ( & V_284 -> V_571 [ 2 ] ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_168 ,
V_204 , V_284 -> V_571 [ 0 ] ) ;
F_179 () ;
break;
}
if ( F_131 ( V_222 -> V_413 ) != 512 )
V_572 = V_572 *
F_131 ( V_222 -> V_413 ) / 512 ;
V_131 -> V_577 = F_139 ( V_572 ) ;
V_131 -> V_578 = F_139 ( V_572 >> 32 ) ;
}
static int F_247 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_543 ,
T_1 * V_72 , struct V_73 * V_236 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_139 * V_131 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_265 * V_540 ;
int V_536 , V_68 ;
struct V_535 * V_269 ;
T_5 V_374 ;
T_4 V_50 ;
T_4 V_554 = 0 ;
if ( ! V_284 -> V_42 )
return - 1 ;
if ( ! V_284 -> V_42 -> V_80 )
return - 1 ;
F_76 ( F_159 ( V_284 ) > V_22 -> V_262 ) ;
if ( F_242 ( V_141 , & V_543 ) ) {
F_46 ( & V_236 -> V_256 ) ;
return V_551 ;
}
V_9 -> V_150 = V_154 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_579 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_580 = V_581 ;
V_536 = F_239 ( V_284 ) ;
if ( V_536 < 0 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_536 ;
}
if ( V_536 ) {
V_540 = V_131 -> V_269 ;
if ( V_536 > V_22 -> V_557 ) {
V_374 = F_136 (
V_22 -> V_259 [ V_9 -> V_133 ] -> V_272 ) ;
V_540 -> V_272 = F_134 ( V_374 ) ;
V_540 -> V_270 = 0 ;
V_540 -> V_582 [ 0 ] = 0 ;
V_540 -> V_582 [ 1 ] = 0 ;
V_540 -> V_582 [ 2 ] = 0 ;
V_540 -> V_341 = 0x80 ;
V_540 = V_22 -> V_259 [ V_9 -> V_133 ] ;
}
F_240 (cmd, sg, use_sg, i) {
V_374 = ( T_5 ) F_236 ( V_269 ) ;
V_50 = F_237 ( V_269 ) ;
V_554 += V_50 ;
V_540 -> V_272 = F_134 ( V_374 ) ;
V_540 -> V_270 = F_139 ( V_50 ) ;
V_540 -> V_582 [ 0 ] = 0 ;
V_540 -> V_582 [ 1 ] = 0 ;
V_540 -> V_582 [ 2 ] = 0 ;
V_540 -> V_341 = 0 ;
V_540 ++ ;
}
switch ( V_284 -> V_561 ) {
case V_562 :
V_131 -> V_573 &= ~ V_583 ;
V_131 -> V_573 |= V_584 ;
break;
case V_564 :
V_131 -> V_573 &= ~ V_583 ;
V_131 -> V_573 |= V_585 ;
break;
case V_566 :
V_131 -> V_573 &= ~ V_583 ;
V_131 -> V_573 |= V_586 ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_167 ,
V_284 -> V_561 ) ;
F_179 () ;
break;
}
} else {
V_131 -> V_573 &= ~ V_583 ;
V_131 -> V_573 |= V_586 ;
}
F_246 ( V_22 , V_9 , V_131 ) ;
V_131 -> V_493 = F_139 ( V_187 ) ;
V_131 -> V_587 = F_139 ( V_9 -> V_133 << V_588 ) ;
memcpy ( V_131 -> V_141 , V_141 , sizeof( V_131 -> V_141 ) ) ;
V_131 -> V_286 = F_139 ( V_554 ) ;
V_131 -> V_589 = F_134 ( V_9 -> V_122 +
F_248 ( struct V_139 , V_289 ) ) ;
V_131 -> V_590 = F_139 ( sizeof( V_131 -> V_289 ) ) ;
if ( V_536 > V_22 -> V_557 ) {
V_131 -> V_140 = 1 ;
V_131 -> V_269 [ 0 ] . V_270 = F_139 ( V_536 * sizeof( V_131 -> V_269 [ 0 ] ) ) ;
if ( F_130 ( V_22 , V_131 , V_9 ) ) {
F_46 ( & V_236 -> V_256 ) ;
F_158 ( V_284 ) ;
return - 1 ;
}
} else
V_131 -> V_140 = ( T_1 ) V_536 ;
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_543 ,
T_1 * V_72 , struct V_73 * V_236 )
{
if ( ! V_9 -> V_10 -> V_42 )
return - 1 ;
if ( ! V_9 -> V_10 -> V_42 -> V_80 )
return - 1 ;
if ( F_104 ( & V_236 -> V_256 ) >
V_236 -> V_190 ) {
F_46 ( & V_236 -> V_256 ) ;
return V_551 ;
}
if ( V_22 -> V_63 & V_114 )
return F_243 ( V_22 , V_9 , V_187 ,
V_141 , V_543 , V_72 ,
V_236 ) ;
else
return F_247 ( V_22 , V_9 , V_187 ,
V_141 , V_543 , V_72 ,
V_236 ) ;
}
static void F_249 ( struct V_221 * V_222 ,
int V_189 , T_4 * V_591 , T_4 * V_592 )
{
if ( V_189 == 0 ) {
* V_591 %= F_97 ( V_222 -> V_227 ) ;
return;
}
do {
* V_592 = * V_591 /
F_97 ( V_222 -> V_227 ) ;
if ( V_189 == * V_592 )
continue;
if ( * V_592 < F_97 ( V_222 -> V_231 ) - 1 ) {
* V_591 += F_97 ( V_222 -> V_227 ) ;
( * V_592 ) ++ ;
} else {
* V_591 %= F_97 ( V_222 -> V_227 ) ;
* V_592 = 0 ;
}
} while ( V_189 != * V_592 );
}
static int F_250 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_283 * V_284 = V_9 -> V_10 ;
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
struct V_221 * V_222 = & V_30 -> V_186 ;
struct V_223 * V_224 = & V_222 -> V_225 [ 0 ] ;
int V_544 = 0 ;
T_4 V_591 ;
T_5 V_572 , V_593 ;
T_4 V_546 ;
T_4 V_594 ;
T_5 V_595 , V_596 ;
T_4 V_597 , V_598 ;
T_4 V_599 , V_600 ;
T_5 V_601 , V_602 ;
T_4 V_603 ;
T_5 V_604 , V_605 ;
T_4 V_606 , V_607 ;
T_4 V_608 , V_609 ;
T_4 V_226 ;
T_4 V_610 ;
T_4 V_611 , V_612 , V_592 ;
T_4 V_613 ;
T_4 V_614 ;
T_5 V_615 ;
T_4 V_616 ;
T_1 V_141 [ 16 ] ;
T_1 V_543 ;
T_6 V_417 ;
#if V_617 == 32
T_5 V_618 ;
#endif
int V_189 ;
if ( ! V_30 )
return - 1 ;
switch ( V_284 -> V_571 [ 0 ] ) {
case V_547 :
V_544 = 1 ;
case V_549 :
V_572 = ( ( ( V_284 -> V_571 [ 1 ] & 0x1F ) << 16 ) |
( V_284 -> V_571 [ 2 ] << 8 ) |
V_284 -> V_571 [ 3 ] ) ;
V_546 = V_284 -> V_571 [ 4 ] ;
if ( V_546 == 0 )
V_546 = 256 ;
break;
case V_552 :
V_544 = 1 ;
case V_553 :
V_572 =
( ( ( T_5 ) V_284 -> V_571 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_571 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_571 [ 4 ] ) << 8 ) |
V_284 -> V_571 [ 5 ] ;
V_546 =
( ( ( T_4 ) V_284 -> V_571 [ 7 ] ) << 8 ) |
V_284 -> V_571 [ 8 ] ;
break;
case V_548 :
V_544 = 1 ;
case V_550 :
V_572 =
( ( ( T_5 ) V_284 -> V_571 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_571 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_571 [ 4 ] ) << 8 ) |
V_284 -> V_571 [ 5 ] ;
V_546 =
( ( ( T_4 ) V_284 -> V_571 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_571 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_571 [ 8 ] ) << 8 ) |
V_284 -> V_571 [ 9 ] ;
break;
case V_575 :
V_544 = 1 ;
case V_576 :
V_572 =
( ( ( T_5 ) V_284 -> V_571 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_284 -> V_571 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_284 -> V_571 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_284 -> V_571 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_284 -> V_571 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_284 -> V_571 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_284 -> V_571 [ 8 ] ) << 8 ) |
V_284 -> V_571 [ 9 ] ;
V_546 =
( ( ( T_4 ) V_284 -> V_571 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_284 -> V_571 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_284 -> V_571 [ 12 ] ) << 8 ) |
V_284 -> V_571 [ 13 ] ;
break;
default:
return V_551 ;
}
V_593 = V_572 + V_546 - 1 ;
if ( V_544 && V_30 -> V_83 != 0 )
return V_551 ;
if ( V_593 >= F_136 ( V_222 -> V_414 ) ||
V_593 < V_572 )
return V_551 ;
V_594 = F_97 ( V_222 -> V_227 ) *
F_97 ( V_222 -> V_417 ) ;
V_417 = F_97 ( V_222 -> V_417 ) ;
#if V_617 == 32
V_618 = V_572 ;
( void ) F_251 ( V_618 , V_594 ) ;
V_595 = V_618 ;
V_618 = V_593 ;
( void ) F_251 ( V_618 , V_594 ) ;
V_596 = V_618 ;
V_597 = ( T_4 ) ( V_572 - ( V_595 * V_594 ) ) ;
V_598 = ( T_4 ) ( V_593 - ( V_596 * V_594 ) ) ;
V_618 = V_597 ;
( void ) F_251 ( V_618 , V_417 ) ;
V_599 = V_618 ;
V_618 = V_598 ;
( void ) F_251 ( V_618 , V_417 ) ;
V_600 = V_618 ;
#else
V_595 = V_572 / V_594 ;
V_596 = V_593 / V_594 ;
V_597 = ( T_4 ) ( V_572 - ( V_595 * V_594 ) ) ;
V_598 = ( T_4 ) ( V_593 - ( V_596 * V_594 ) ) ;
V_599 = V_597 / V_417 ;
V_600 = V_598 / V_417 ;
#endif
if ( ( V_595 != V_596 ) || ( V_599 != V_600 ) )
return V_551 ;
V_226 = F_97 ( V_222 -> V_227 ) +
F_97 ( V_222 -> V_228 ) ;
V_613 = ( ( T_4 ) ( V_595 >> V_222 -> V_416 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_591 = ( V_613 * V_226 ) + V_599 ;
switch ( V_30 -> V_83 ) {
case V_619 :
break;
case V_620 :
F_76 ( F_97 ( V_222 -> V_231 ) != 2 ) ;
if ( V_30 -> V_189 )
V_591 += F_97 ( V_222 -> V_227 ) ;
V_30 -> V_189 = ! V_30 -> V_189 ;
break;
case V_621 :
F_76 ( F_97 ( V_222 -> V_231 ) != 3 ) ;
V_189 = V_30 -> V_189 ;
F_249 ( V_222 , V_189 ,
& V_591 , & V_592 ) ;
V_189 =
( V_189 >=
F_97 ( V_222 -> V_231 ) - 1 )
? 0 : V_189 + 1 ;
V_30 -> V_189 = V_189 ;
break;
case V_622 :
case V_623 :
if ( F_97 ( V_222 -> V_231 ) <= 1 )
break;
V_603 =
F_97 ( V_222 -> V_417 ) *
F_97 ( V_222 -> V_227 ) ;
F_76 ( V_603 == 0 ) ;
V_610 = V_603 *
F_97 ( V_222 -> V_231 ) ;
#if V_617 == 32
V_618 = V_572 ;
V_611 = F_251 ( V_618 , V_610 ) ;
V_618 = V_611 ;
( void ) F_251 ( V_618 , V_603 ) ;
V_611 = V_618 ;
V_618 = V_593 ;
V_612 = F_251 ( V_618 , V_610 ) ;
V_618 = V_612 ;
( void ) F_251 ( V_618 , V_603 ) ;
V_612 = V_618 ;
#else
V_611 = ( V_572 % V_610 ) / V_603 ;
V_612 = ( V_593 % V_610 ) / V_603 ;
#endif
if ( V_611 != V_612 )
return V_551 ;
#if V_617 == 32
V_618 = V_572 ;
( void ) F_251 ( V_618 , V_610 ) ;
V_595 = V_604 = V_601 = V_618 ;
V_618 = V_593 ;
( void ) F_251 ( V_618 , V_610 ) ;
V_605 = V_602 = V_618 ;
#else
V_595 = V_604 = V_601 =
V_572 / V_610 ;
V_605 = V_602 = V_593 / V_610 ;
#endif
if ( V_604 != V_605 )
return V_551 ;
#if V_617 == 32
V_618 = V_572 ;
V_597 = F_251 ( V_618 , V_610 ) ;
V_618 = V_597 ;
V_597 = ( T_4 ) F_251 ( V_618 , V_603 ) ;
V_606 = V_597 ;
V_618 = V_593 ;
V_607 = F_251 ( V_618 , V_610 ) ;
V_618 = V_607 ;
V_607 = F_251 ( V_618 , V_603 ) ;
V_618 = V_606 ;
( void ) F_251 ( V_618 , V_222 -> V_417 ) ;
V_599 = V_608 = V_618 ;
V_618 = V_607 ;
( void ) F_251 ( V_618 , V_222 -> V_417 ) ;
V_609 = V_618 ;
#else
V_597 = V_606 =
( T_4 ) ( ( V_572 % V_610 ) %
V_603 ) ;
V_607 =
( T_4 ) ( ( V_593 % V_610 ) %
V_603 ) ;
V_599 = V_608 =
V_606 / F_97 ( V_222 -> V_417 ) ;
V_609 =
V_607 / F_97 ( V_222 -> V_417 ) ;
#endif
if ( V_608 != V_609 )
return V_551 ;
V_613 = ( ( T_4 ) ( V_595 >> V_222 -> V_416 ) ) %
F_97 ( V_222 -> V_230 ) ;
V_591 = ( V_611 *
( F_97 ( V_222 -> V_230 ) * V_226 ) ) +
( V_613 * V_226 ) + V_599 ;
break;
default:
return V_551 ;
}
if ( F_45 ( V_591 >= V_234 ) )
return V_551 ;
V_9 -> V_236 = V_30 -> V_236 [ V_591 ] ;
if ( ! V_9 -> V_236 )
return V_551 ;
V_614 = V_224 [ V_591 ] . V_187 ;
V_615 = F_136 ( V_222 -> V_418 ) +
V_595 * F_97 ( V_222 -> V_417 ) +
( V_597 - V_599 *
F_97 ( V_222 -> V_417 ) ) ;
V_616 = V_546 ;
if ( V_222 -> V_415 ) {
V_615 <<= V_222 -> V_415 ;
V_616 <<= V_222 -> V_415 ;
}
F_76 ( V_616 > 0xffff ) ;
if ( V_615 > 0xffffffff ) {
V_141 [ 0 ] = V_544 ? V_575 : V_576 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_615 >> 56 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_615 >> 48 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_615 >> 40 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_615 >> 32 ) ;
V_141 [ 6 ] = ( T_1 ) ( V_615 >> 24 ) ;
V_141 [ 7 ] = ( T_1 ) ( V_615 >> 16 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_615 >> 8 ) ;
V_141 [ 9 ] = ( T_1 ) ( V_615 ) ;
V_141 [ 10 ] = ( T_1 ) ( V_616 >> 24 ) ;
V_141 [ 11 ] = ( T_1 ) ( V_616 >> 16 ) ;
V_141 [ 12 ] = ( T_1 ) ( V_616 >> 8 ) ;
V_141 [ 13 ] = ( T_1 ) ( V_616 ) ;
V_141 [ 14 ] = 0 ;
V_141 [ 15 ] = 0 ;
V_543 = 16 ;
} else {
V_141 [ 0 ] = V_544 ? V_552 : V_553 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_615 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_615 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_615 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_615 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_616 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_616 ) ;
V_141 [ 9 ] = 0 ;
V_543 = 10 ;
}
return F_245 ( V_22 , V_9 , V_614 , V_141 , V_543 ,
V_30 -> V_72 ,
V_30 -> V_236 [ V_591 ] ) ;
}
static int F_252 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char V_72 [] )
{
V_284 -> V_624 = ( unsigned char * ) V_9 ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_9 -> V_124 . V_128 = 0 ;
memcpy ( & V_9 -> V_124 . V_349 . V_350 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_124 . V_348 = F_134 ( ( V_9 -> V_133 << V_588 ) ) ;
V_9 -> V_144 . V_625 = 0 ;
F_76 ( V_284 -> V_558 > sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_345 = V_284 -> V_558 ;
memcpy ( V_9 -> V_144 . V_145 , V_284 -> V_571 , V_284 -> V_558 ) ;
switch ( V_284 -> V_561 ) {
case V_562 :
V_9 -> V_144 . V_626 =
F_253 ( V_393 , V_627 , V_628 ) ;
break;
case V_564 :
V_9 -> V_144 . V_626 =
F_253 ( V_393 , V_627 , V_629 ) ;
break;
case V_566 :
V_9 -> V_144 . V_626 =
F_253 ( V_393 , V_627 , V_630 ) ;
break;
case V_631 :
V_9 -> V_144 . V_626 =
F_253 ( V_393 , V_627 , V_632 ) ;
break;
default:
F_74 ( & V_22 -> V_29 -> V_30 , L_167 ,
V_284 -> V_561 ) ;
F_179 () ;
break;
}
if ( F_238 ( V_22 , V_9 , V_284 ) < 0 ) {
F_147 ( V_22 , V_9 ) ;
return V_633 ;
}
F_61 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_254 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_634 , V_635 ;
memset ( V_9 , 0 , F_248 ( struct V_8 , V_240 ) ) ;
V_9 -> V_124 . V_348 = F_134 ( ( T_5 ) ( V_199 << V_588 ) ) ;
V_634 = V_22 -> V_636 + V_199 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_637 + V_199 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_635 = V_22 -> V_638
+ V_199 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_133 = V_199 ;
V_9 -> V_122 = ( T_4 ) V_634 ;
V_9 -> V_639 . V_282 = F_134 ( ( T_5 ) V_635 ) ;
V_9 -> V_639 . V_281 = F_139 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_255 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_239 + V_68 ;
F_254 ( V_22 , V_68 , V_9 ) ;
F_122 ( & V_9 -> V_240 , 0 ) ;
}
}
static inline void F_256 ( struct V_1 * V_22 , int V_199 ,
struct V_8 * V_9 )
{
V_372 V_634 = V_22 -> V_636 + V_199 * sizeof( * V_9 ) ;
F_76 ( V_9 -> V_133 != V_199 ) ;
memset ( V_9 -> V_144 . V_145 , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_122 = ( T_4 ) V_634 ;
}
static int F_257 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_283 * V_284 ,
unsigned char * V_72 )
{
struct V_73 * V_30 = V_284 -> V_42 -> V_80 ;
int V_21 = V_551 ;
if ( ! V_30 )
return V_633 ;
V_284 -> V_624 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_91 ) {
F_254 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_250 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_633 ;
} else if ( V_30 -> V_188 ) {
F_254 ( V_22 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_340 ;
V_9 -> V_10 = V_284 ;
V_21 = F_244 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_633 ;
}
return V_21 ;
}
static void V_326 ( struct V_640 * V_325 )
{
struct V_283 * V_284 ;
struct V_73 * V_30 ;
struct V_8 * V_9 = F_258 ( V_325 , struct V_8 , V_325 ) ;
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
V_21 = F_257 ( V_22 , V_9 , V_284 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_633 ) {
V_284 -> V_294 = V_641 << 16 ;
return F_149 ( V_22 , V_9 , V_284 ) ;
}
}
}
F_256 ( V_9 -> V_22 , V_9 -> V_133 , V_9 ) ;
if ( F_252 ( V_9 -> V_22 , V_9 , V_284 , V_30 -> V_72 ) ) {
V_284 -> V_294 = V_641 << 16 ;
V_284 -> V_324 ( V_284 ) ;
}
}
static int F_259 ( struct V_6 * V_7 , struct V_283 * V_284 )
{
struct V_1 * V_22 ;
struct V_73 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_284 -> V_42 ) ;
F_76 ( V_284 -> V_642 -> V_348 < 0 ) ;
V_30 = V_284 -> V_42 -> V_80 ;
if ( ! V_30 ) {
V_284 -> V_294 = V_476 << 16 ;
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
V_9 = F_260 ( V_22 , V_284 ) ;
if ( F_48 ( V_284 -> V_643 == 0 &&
V_284 -> V_642 -> V_150 == V_644 &&
V_22 -> V_56 ) ) {
V_21 = F_257 ( V_22 , V_9 , V_284 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_633 ) {
F_147 ( V_22 , V_9 ) ;
return V_633 ;
}
}
return F_252 ( V_22 , V_9 , V_284 , V_72 ) ;
}
static void F_261 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
F_35 ( & V_22 -> V_645 , V_78 ) ;
V_22 -> V_646 = 1 ;
F_146 ( & V_22 -> V_647 ) ;
F_36 ( & V_22 -> V_645 , V_78 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_261 ( V_22 ) ;
while ( 1 ) {
F_35 ( & V_22 -> V_645 , V_78 ) ;
if ( V_22 -> V_646 )
break;
F_36 ( & V_22 -> V_645 , V_78 ) ;
F_182 ( V_22 -> V_647 , V_22 -> V_646 ) ;
}
V_22 -> V_646 = 0 ;
F_36 ( & V_22 -> V_645 , V_78 ) ;
if ( F_45 ( F_13 ( V_22 ) ) )
return F_261 ( V_22 ) ;
F_233 ( V_22 ) ;
F_261 ( V_22 ) ;
}
static int F_262 ( struct V_2 * V_3 , int V_233 )
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
static int F_263 ( struct V_6 * V_7 ,
unsigned long V_648 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_78 ;
int V_649 ;
F_35 ( & V_22 -> V_645 , V_78 ) ;
V_649 = V_22 -> V_646 ;
F_36 ( & V_22 -> V_645 , V_78 ) ;
return V_649 ;
}
static int F_264 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
V_7 = F_265 ( & V_650 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_169 ) ;
return - V_261 ;
}
V_7 -> V_651 = 0 ;
V_7 -> V_652 = 0 ;
V_7 -> V_653 = - 1 ;
V_7 -> V_654 = 3 ;
V_7 -> V_655 = V_656 ;
V_7 -> V_657 = V_501 ;
V_7 -> V_658 = V_501 ;
V_7 -> V_258 = V_22 -> V_237 - V_659 ;
V_7 -> V_660 = V_7 -> V_258 ;
V_7 -> V_661 = V_22 -> V_262 ;
V_7 -> V_662 = V_663 ;
V_7 -> V_80 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_664 = V_22 -> V_665 [ V_22 -> V_666 ] ;
V_7 -> V_667 = V_7 -> V_664 ;
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_266 ( struct V_1 * V_22 )
{
int V_668 ;
V_668 = F_267 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_668 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_170 ) ;
return V_668 ;
}
F_268 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_269 ( struct V_283 * V_669 )
{
int V_670 = V_669 -> V_642 -> V_348 ;
if ( V_670 < 0 )
return V_670 ;
return V_670 += V_659 ;
}
static int F_270 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_671 [] ,
int V_113 )
{
int V_21 ;
( void ) F_177 ( V_9 , V_475 , V_22 ,
NULL , 0 , 0 , V_671 , V_393 ) ;
V_21 = F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_672 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_295 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_673 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_271 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_671 [] , int V_113 )
{
int V_21 ;
int V_48 = 0 ;
int V_674 = 1 ;
for ( V_48 = 0 ; V_48 < V_675 ; V_48 ++ ) {
F_108 ( 1000 * V_674 ) ;
V_21 = F_270 ( V_22 , V_9 , V_671 , V_113 ) ;
if ( ! V_21 )
break;
if ( V_674 < V_676 )
V_674 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_171 ,
V_674 ) ;
}
return V_21 ;
}
static int F_272 ( struct V_1 * V_22 ,
unsigned char V_671 [] ,
int V_113 )
{
int V_677 ;
int V_678 ;
int V_112 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
if ( V_113 == V_127 ) {
V_677 = 0 ;
V_678 = V_22 -> V_129 - 1 ;
} else {
V_677 = V_113 ;
V_678 = V_113 ;
}
for ( V_112 = V_677 ; V_112 <= V_678 ; V_112 ++ ) {
V_21 = F_271 ( V_22 , V_9 , V_671 , V_112 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_172 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_173 ) ;
F_106 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_273 ( struct V_283 * V_679 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
T_1 V_397 ;
char V_680 [ 48 ] ;
V_22 = F_1 ( V_679 -> V_42 ) ;
if ( V_22 == NULL )
return V_681 ;
if ( F_13 ( V_22 ) )
return V_681 ;
V_30 = V_679 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_174 , V_204 ) ;
return V_681 ;
}
if ( F_13 ( V_22 ) ) {
snprintf ( V_680 , sizeof( V_680 ) ,
L_175 ,
F_269 ( V_679 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_680 ) ;
return V_681 ;
}
if ( F_274 ( V_22 ) ) {
snprintf ( V_680 , sizeof( V_680 ) ,
L_176 ,
F_269 ( V_679 ) ) ;
F_70 ( V_243 , V_22 , V_30 , V_680 ) ;
return V_681 ;
}
if ( F_63 ( V_30 -> V_72 ) )
return V_682 ;
if ( F_31 ( V_30 -> V_72 ) )
V_397 = V_683 ;
else
V_397 = V_684 ;
sprintf ( V_680 , L_177 ,
V_397 == V_683 ? L_178 : L_179 ) ;
F_70 ( V_243 , V_22 , V_30 , V_680 ) ;
V_22 -> V_248 = 1 ;
V_21 = F_180 ( V_22 , V_30 , V_30 -> V_72 , V_397 ,
V_127 ) ;
sprintf ( V_680 , L_180 ,
V_397 == V_683 ? L_178 : L_179 ,
V_21 == 0 ? L_181 : L_182 ) ;
F_70 ( V_243 , V_22 , V_30 , V_680 ) ;
V_22 -> V_248 = 0 ;
return V_21 == 0 ? V_682 : V_681 ;
}
static void F_275 ( T_1 * V_348 )
{
T_1 V_685 [ 8 ] ;
memcpy ( V_685 , V_348 , 8 ) ;
V_348 [ 0 ] = V_685 [ 3 ] ;
V_348 [ 1 ] = V_685 [ 2 ] ;
V_348 [ 2 ] = V_685 [ 1 ] ;
V_348 [ 3 ] = V_685 [ 0 ] ;
V_348 [ 4 ] = V_685 [ 7 ] ;
V_348 [ 5 ] = V_685 [ 6 ] ;
V_348 [ 6 ] = V_685 [ 5 ] ;
V_348 [ 7 ] = V_685 [ 4 ] ;
}
static void F_276 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_7 * V_686 , T_7 * V_687 )
{
T_5 V_348 ;
if ( V_9 -> V_150 == V_151 ) {
struct V_130 * V_688 = (struct V_130 * )
& V_22 -> V_132 [ V_9 -> V_133 ] ;
V_348 = F_136 ( V_688 -> V_348 ) ;
* V_687 = F_139 ( V_348 >> 32 ) ;
* V_686 = F_139 ( V_348 ) ;
return;
}
if ( V_9 -> V_150 == V_154 ) {
struct V_139 * V_689 = (struct V_139 * )
& V_22 -> V_137 [ V_9 -> V_133 ] ;
memset ( V_687 , 0 , sizeof( * V_687 ) ) ;
* V_686 = V_689 -> V_587 ;
return;
}
V_348 = F_136 ( V_9 -> V_124 . V_348 ) ;
* V_687 = F_139 ( V_348 >> 32 ) ;
* V_686 = F_139 ( V_348 ) ;
}
static int F_277 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
T_7 V_687 , V_686 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_477 , V_22 , & abort -> V_124 . V_348 ,
0 , 0 , V_72 , V_398 ) ;
if ( V_22 -> V_71 )
F_275 ( & V_9 -> V_144 . V_145 [ 4 ] ) ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_276 ( V_22 , abort , & V_686 , & V_687 ) ;
F_278 ( & V_22 -> V_29 -> V_30 , L_183 ,
V_204 , V_687 , V_686 ) ;
V_338 = V_9 -> V_24 ;
switch ( V_338 -> V_36 ) {
case V_672 :
break;
case V_368 :
V_21 = F_156 ( V_22 , V_9 ) ;
break;
case V_367 :
V_21 = - 1 ;
break;
default:
F_278 ( & V_22 -> V_29 -> V_30 , L_184 ,
V_204 , V_687 , V_686 ) ;
F_174 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_106 ( V_22 , V_9 ) ;
F_278 ( & V_22 -> V_29 -> V_30 , L_185 ,
V_204 , V_687 , V_686 ) ;
return V_21 ;
}
static void F_279 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_690 , int V_113 )
{
struct V_139 * V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_400 = (struct V_136 * ) V_285 ;
struct V_139 * V_691 =
& V_22 -> V_137 [ V_690 -> V_133 ] ;
struct V_283 * V_669 = V_690 -> V_10 ;
struct V_73 * V_30 = V_669 -> V_42 -> V_80 ;
if ( ! V_30 )
return;
F_280 ( sizeof( struct V_136 ) >
sizeof( struct V_139 ) ) ;
F_76 ( F_248 ( struct V_139 , V_289 ) <
F_248 ( struct V_136 , V_692 ) +
sizeof( V_400 -> V_692 ) ) ;
V_9 -> V_150 = V_156 ;
V_9 -> V_10 = V_693 ;
V_9 -> V_122 = ( T_4 ) V_22 -> V_579 +
( V_9 -> V_133 * sizeof( struct V_139 ) ) ;
F_76 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_400 , 0 , sizeof( * V_285 ) ) ;
V_400 -> V_694 = V_695 ;
V_400 -> V_113 = V_113 ;
V_400 -> V_696 = V_697 ;
V_400 -> V_402 = F_139 ( V_30 -> V_187 ) ;
memset ( V_400 -> V_698 , 0 , sizeof( V_400 -> V_698 ) ) ;
V_400 -> V_348 = F_134 ( V_9 -> V_133 << V_588 ) ;
V_400 -> V_699 = F_134 ( F_131 ( V_691 -> V_587 ) ) ;
V_400 -> V_700 = F_134 ( V_9 -> V_122 +
F_248 ( struct V_139 , V_289 ) ) ;
V_400 -> V_692 = F_139 ( sizeof( V_285 -> V_289 ) ) ;
}
static int F_281 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_283 * V_669 ;
struct V_73 * V_30 ;
unsigned char V_701 [ 8 ] ;
unsigned char * V_702 = & V_701 [ 0 ] ;
V_669 = abort -> V_10 ;
V_30 = (struct V_73 * ) ( V_669 -> V_42 -> V_80 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_186 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_187 ,
V_22 -> V_59 -> V_102 , V_30 -> V_103 , V_30 -> V_104 , V_30 -> V_105 ,
L_188 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_91 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_189 ) ;
return - 1 ;
}
if ( ! F_221 ( V_22 , abort , V_702 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_190 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_702 [ 0 ] , V_702 [ 1 ] , V_702 [ 2 ] , V_702 [ 3 ] ,
V_702 [ 4 ] , V_702 [ 5 ] , V_702 [ 6 ] , V_702 [ 7 ] ) ;
V_21 = F_180 ( V_22 , V_30 , V_702 , V_684 , V_113 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_192 ,
V_702 [ 0 ] , V_702 [ 1 ] , V_702 [ 2 ] , V_702 [ 3 ] ,
V_702 [ 4 ] , V_702 [ 5 ] , V_702 [ 6 ] , V_702 [ 7 ] ) ;
return V_21 ;
}
if ( F_272 ( V_22 , V_702 , V_113 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_193 ,
V_702 [ 0 ] , V_702 [ 1 ] , V_702 [ 2 ] , V_702 [ 3 ] ,
V_702 [ 4 ] , V_702 [ 5 ] , V_702 [ 6 ] , V_702 [ 7 ] ) ;
return - 1 ;
}
F_95 ( & V_22 -> V_29 -> V_30 ,
L_194 ,
V_702 [ 0 ] , V_702 [ 1 ] , V_702 [ 2 ] , V_702 [ 3 ] ,
V_702 [ 4 ] , V_702 [ 5 ] , V_702 [ 6 ] , V_702 [ 7 ] ) ;
return V_21 ;
}
static int F_282 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_113 )
{
int V_21 = V_381 ;
struct V_8 * V_9 ;
T_7 V_686 , V_687 ;
struct V_73 * V_30 ;
struct V_139 * V_285 ;
V_30 = abort -> V_10 -> V_42 -> V_80 ;
if ( ! V_30 )
return - 1 ;
if ( ! V_30 -> V_91 && ! V_30 -> V_188 )
return - 1 ;
V_9 = F_176 ( V_22 ) ;
F_279 ( V_9 , V_22 , abort , V_113 ) ;
V_285 = & V_22 -> V_137 [ V_9 -> V_133 ] ;
( void ) F_168 ( V_22 , V_9 , V_113 , V_396 ) ;
F_276 ( V_22 , abort , & V_686 , & V_687 ) ;
F_278 ( & V_22 -> V_29 -> V_30 ,
L_195 ,
V_204 , V_687 , V_686 ) ;
F_278 ( & V_22 -> V_29 -> V_30 ,
L_196 ,
V_204 , V_687 , V_686 , V_285 -> V_289 . V_290 ) ;
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
L_197 ,
V_204 , V_687 , V_686 ,
V_285 -> V_289 . V_290 ) ;
V_21 = - 1 ;
}
F_106 ( V_22 , V_9 ) ;
F_278 ( & V_22 -> V_29 -> V_30 , L_185 , V_204 ,
V_687 , V_686 ) ;
return V_21 ;
}
static int F_283 ( struct V_1 * V_22 ,
struct V_73 * V_30 , struct V_8 * abort , int V_113 )
{
if ( abort -> V_150 == V_154 ) {
if ( ( V_703 & V_22 -> V_704 ) ||
V_30 -> V_74 )
return F_282 ( V_22 , abort ,
V_113 ) ;
else
return F_281 ( V_22 ,
V_30 -> V_72 ,
abort , V_113 ) ;
}
return F_277 ( V_22 , V_30 -> V_72 , abort , V_113 ) ;
}
static int F_284 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_150 == V_154 )
return V_22 -> V_137 [ V_9 -> V_133 ] . V_113 ;
return V_9 -> V_124 . V_128 ;
}
static inline int F_285 ( struct V_1 * V_22 )
{
#define F_286 5000
return ! F_287 ( V_22 -> V_705 ,
F_288 ( & V_22 -> V_706 ) >= 0 ,
F_167 ( F_286 ) ) ;
}
static int F_289 ( struct V_283 * V_707 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_73 * V_30 ;
struct V_8 * abort ;
struct V_283 * V_708 ;
char V_680 [ 256 ] ;
int V_709 = 0 ;
T_7 V_687 , V_686 ;
int V_240 , V_113 ;
if ( V_707 == NULL )
return V_681 ;
if ( V_707 -> V_42 == NULL )
return V_681 ;
V_22 = F_1 ( V_707 -> V_42 ) ;
if ( V_22 == NULL )
return V_681 ;
V_30 = V_707 -> V_42 -> V_80 ;
if ( ! V_30 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_198 ,
V_680 ) ;
return V_681 ;
}
if ( F_13 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_199 ) ;
return V_681 ;
}
if ( F_274 ( V_22 ) ) {
F_70 ( V_243 , V_22 , V_30 ,
L_200 ) ;
return V_681 ;
}
if ( ! ( V_710 & V_22 -> V_704 ) &&
! ( V_711 & V_22 -> V_704 ) )
return V_681 ;
memset ( V_680 , 0 , sizeof( V_680 ) ) ;
V_709 += sprintf ( V_680 + V_709 , L_201 ,
V_22 -> V_59 -> V_102 , V_707 -> V_42 -> V_712 ,
V_707 -> V_42 -> V_713 , V_707 -> V_42 -> V_105 ,
L_202 , V_707 ) ;
abort = (struct V_8 * ) V_707 -> V_624 ;
if ( abort == NULL ) {
return V_682 ;
}
V_240 = F_104 ( & abort -> V_240 ) ;
if ( V_240 == 1 ) {
F_106 ( V_22 , abort ) ;
return V_682 ;
}
if ( abort -> V_150 != V_154 &&
abort -> V_150 != V_151 && ! V_30 -> V_486 ) {
F_106 ( V_22 , abort ) ;
return V_681 ;
}
if ( abort -> V_10 != V_707 ) {
F_106 ( V_22 , abort ) ;
return V_682 ;
}
abort -> V_12 = true ;
F_276 ( V_22 , abort , & V_686 , & V_687 ) ;
V_113 = F_284 ( V_22 , abort ) ;
V_709 += sprintf ( V_680 + V_709 , L_203 , V_687 , V_686 ) ;
V_708 = abort -> V_10 ;
if ( V_708 != NULL )
V_709 += sprintf ( V_680 + V_709 ,
L_204 ,
V_708 -> V_558 , V_708 -> V_571 [ 0 ] , V_708 -> V_571 [ 1 ] ,
V_708 -> V_714 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_205 , V_680 ) ;
F_70 ( V_243 , V_22 , V_30 , L_202 ) ;
if ( F_285 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_206 ,
V_680 ) ;
F_106 ( V_22 , abort ) ;
return V_681 ;
}
V_21 = F_283 ( V_22 , V_30 , abort , V_113 ) ;
F_56 ( & V_22 -> V_706 ) ;
F_146 ( & V_22 -> V_705 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_207 , V_680 ) ;
F_70 ( V_243 , V_22 , V_30 ,
L_208 ) ;
F_106 ( V_22 , abort ) ;
return V_681 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_209 , V_680 ) ;
F_182 ( V_22 -> V_323 ,
abort -> V_10 != V_707 || F_13 ( V_22 ) ) ;
F_106 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_682 : V_681 ;
}
static struct V_8 * F_260 ( struct V_1 * V_22 ,
struct V_283 * V_669 )
{
int V_670 = F_269 ( V_669 ) ;
struct V_8 * V_9 = V_22 -> V_239 + V_670 ;
if ( V_670 < V_659 || V_670 >= V_22 -> V_237 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_210 ,
V_670 , V_659 , V_22 -> V_237 - 1 ) ;
F_179 () ;
}
F_56 ( & V_9 -> V_240 ) ;
if ( F_45 ( ! F_4 ( V_9 ) ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_211 ,
V_670 ) ;
if ( V_9 -> V_10 != NULL )
F_290 ( V_9 -> V_10 ) ;
F_290 ( V_669 ) ;
}
F_256 ( V_22 , V_670 , V_9 ) ;
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
int V_715 = 0 ;
for (; ; ) {
V_68 = F_291 ( V_22 -> V_716 ,
V_659 ,
V_715 ) ;
if ( F_45 ( V_68 >= V_659 ) ) {
V_715 = 0 ;
continue;
}
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( F_45 ( V_240 > 1 ) ) {
F_106 ( V_22 , V_9 ) ;
V_715 = ( V_68 + 1 ) % V_659 ;
continue;
}
F_292 ( V_68 & ( V_617 - 1 ) ,
V_22 -> V_716 + ( V_68 / V_617 ) ) ;
break;
}
F_256 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_106 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_58 ( & V_9 -> V_240 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_239 ;
F_293 ( V_68 & ( V_617 - 1 ) ,
V_22 -> V_716 + ( V_68 / V_617 ) ) ;
}
}
static int F_294 ( struct V_2 * V_30 , int V_284 ,
void T_8 * V_717 )
{
T_9 T_8 * V_718 =
( T_9 T_8 * ) V_717 ;
T_10 V_719 ;
T_10 T_8 * V_720 = F_295 ( sizeof( V_719 ) ) ;
int V_721 ;
T_4 V_131 ;
memset ( & V_719 , 0 , sizeof( V_719 ) ) ;
V_721 = 0 ;
V_721 |= F_296 ( & V_719 . V_722 , & V_718 -> V_722 ,
sizeof( V_719 . V_722 ) ) ;
V_721 |= F_296 ( & V_719 . V_144 , & V_718 -> V_144 ,
sizeof( V_719 . V_144 ) ) ;
V_721 |= F_296 ( & V_719 . V_723 , & V_718 -> V_723 ,
sizeof( V_719 . V_723 ) ) ;
V_721 |= F_297 ( V_719 . V_724 , & V_718 -> V_724 ) ;
V_721 |= F_297 ( V_131 , & V_718 -> V_45 ) ;
V_719 . V_45 = F_298 ( V_131 ) ;
V_721 |= F_299 ( V_720 , & V_719 , sizeof( V_719 ) ) ;
if ( V_721 )
return - V_725 ;
V_721 = F_300 ( V_30 , V_726 , V_720 ) ;
if ( V_721 )
return V_721 ;
V_721 |= F_301 ( & V_718 -> V_723 , & V_720 -> V_723 ,
sizeof( V_718 -> V_723 ) ) ;
if ( V_721 )
return - V_725 ;
return V_721 ;
}
static int F_302 ( struct V_2 * V_30 ,
int V_284 , void T_8 * V_717 )
{
T_11 T_8 * V_718 =
( T_11 T_8 * ) V_717 ;
T_12 V_719 ;
T_12 T_8 * V_720 =
F_295 ( sizeof( V_719 ) ) ;
int V_721 ;
T_4 V_131 ;
memset ( & V_719 , 0 , sizeof( V_719 ) ) ;
V_721 = 0 ;
V_721 |= F_296 ( & V_719 . V_722 , & V_718 -> V_722 ,
sizeof( V_719 . V_722 ) ) ;
V_721 |= F_296 ( & V_719 . V_144 , & V_718 -> V_144 ,
sizeof( V_719 . V_144 ) ) ;
V_721 |= F_296 ( & V_719 . V_723 , & V_718 -> V_723 ,
sizeof( V_719 . V_723 ) ) ;
V_721 |= F_297 ( V_719 . V_724 , & V_718 -> V_724 ) ;
V_721 |= F_297 ( V_719 . V_727 , & V_718 -> V_727 ) ;
V_721 |= F_297 ( V_131 , & V_718 -> V_45 ) ;
V_719 . V_45 = F_298 ( V_131 ) ;
V_721 |= F_299 ( V_720 , & V_719 , sizeof( V_719 ) ) ;
if ( V_721 )
return - V_725 ;
V_721 = F_300 ( V_30 , V_728 , V_720 ) ;
if ( V_721 )
return V_721 ;
V_721 |= F_301 ( & V_718 -> V_723 , & V_720 -> V_723 ,
sizeof( V_718 -> V_723 ) ) ;
if ( V_721 )
return - V_725 ;
return V_721 ;
}
static int F_303 ( struct V_2 * V_30 , int V_284 , void T_8 * V_717 )
{
switch ( V_284 ) {
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
case V_740 :
case V_741 :
case V_742 :
case V_743 :
return F_300 ( V_30 , V_284 , V_717 ) ;
case V_744 :
return F_294 ( V_30 , V_284 , V_717 ) ;
case V_745 :
return F_302 ( V_30 , V_284 , V_717 ) ;
default:
return - V_746 ;
}
}
static int F_304 ( struct V_1 * V_22 , void T_8 * V_747 )
{
struct V_748 V_749 ;
if ( ! V_747 )
return - V_55 ;
V_749 . V_750 = F_305 ( V_22 -> V_29 -> V_103 ) ;
V_749 . V_103 = V_22 -> V_29 -> V_103 -> V_751 ;
V_749 . V_752 = V_22 -> V_29 -> V_753 ;
V_749 . V_67 = V_22 -> V_67 ;
if ( F_299 ( V_747 , & V_749 , sizeof( V_749 ) ) )
return - V_725 ;
return 0 ;
}
static int F_306 ( struct V_1 * V_22 , void T_8 * V_747 )
{
T_13 V_754 ;
unsigned char V_755 , V_756 , V_757 ;
int V_21 ;
V_21 = sscanf ( V_758 , L_212 ,
& V_755 , & V_756 , & V_757 ) ;
if ( V_21 != 3 ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_213
L_214 , V_758 ) ;
V_755 = 0 ;
V_756 = 0 ;
V_757 = 0 ;
}
V_754 = ( V_755 << 16 ) | ( V_756 << 8 ) | V_757 ;
if ( ! V_747 )
return - V_55 ;
if ( F_299 ( V_747 , & V_754 , sizeof( T_13 ) ) )
return - V_725 ;
return 0 ;
}
static int F_307 ( struct V_1 * V_22 , void T_8 * V_747 )
{
T_10 V_759 ;
struct V_8 * V_9 ;
char * V_760 = NULL ;
T_5 V_267 ;
int V_21 = 0 ;
if ( ! V_747 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_761 ;
if ( F_296 ( & V_759 , V_747 , sizeof( V_759 ) ) )
return - V_725 ;
if ( ( V_759 . V_724 < 1 ) &&
( V_759 . V_144 . Type . V_762 != V_630 ) ) {
return - V_55 ;
}
if ( V_759 . V_724 > 0 ) {
V_760 = F_92 ( V_759 . V_724 , V_203 ) ;
if ( V_760 == NULL )
return - V_261 ;
if ( V_759 . V_144 . Type . V_762 & V_628 ) {
if ( F_296 ( V_760 , V_759 . V_45 ,
V_759 . V_724 ) ) {
V_21 = - V_725 ;
goto V_763;
}
} else {
memset ( V_760 , 0 , V_759 . V_724 ) ;
}
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_693 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_759 . V_724 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_280 = F_160 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_280 = F_160 ( 0 ) ;
}
memcpy ( & V_9 -> V_124 . V_349 , & V_759 . V_722 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_759 . V_144 ,
sizeof( V_9 -> V_144 ) ) ;
if ( V_759 . V_724 > 0 ) {
V_267 = F_132 ( V_22 -> V_29 , V_760 ,
V_759 . V_724 , V_764 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 , ( V_372 ) V_267 ) ) {
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( 0 ) ;
V_21 = - V_261 ;
goto V_394;
}
V_9 -> V_276 [ 0 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ 0 ] . V_281 = F_139 ( V_759 . V_724 ) ;
V_9 -> V_276 [ 0 ] . V_278 = F_139 ( V_376 ) ;
}
V_21 = F_168 ( V_22 , V_9 , V_127 ,
V_380 ) ;
if ( V_759 . V_724 > 0 )
F_161 ( V_22 -> V_29 , V_9 , 1 , V_764 ) ;
F_308 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_387 ;
goto V_394;
}
memcpy ( & V_759 . V_723 , V_9 -> V_24 ,
sizeof( V_759 . V_723 ) ) ;
if ( F_299 ( V_747 , & V_759 , sizeof( V_759 ) ) ) {
V_21 = - V_725 ;
goto V_394;
}
if ( ( V_759 . V_144 . Type . V_762 & V_629 ) &&
V_759 . V_724 > 0 ) {
if ( F_299 ( V_759 . V_45 , V_760 , V_759 . V_724 ) ) {
V_21 = - V_725 ;
goto V_394;
}
}
V_394:
F_106 ( V_22 , V_9 ) ;
V_763:
F_81 ( V_760 ) ;
return V_21 ;
}
static int F_309 ( struct V_1 * V_22 , void T_8 * V_747 )
{
T_12 * V_765 ;
struct V_8 * V_9 ;
unsigned char * * V_760 = NULL ;
int * V_766 = NULL ;
T_5 V_267 ;
T_14 V_370 = 0 ;
int V_49 = 0 ;
T_4 V_767 ;
T_4 V_768 ;
T_14 T_8 * V_769 ;
if ( ! V_747 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_761 ;
V_765 = ( T_12 * )
F_92 ( sizeof( * V_765 ) , V_203 ) ;
if ( ! V_765 ) {
V_49 = - V_261 ;
goto V_770;
}
if ( F_296 ( V_765 , V_747 , sizeof( * V_765 ) ) ) {
V_49 = - V_725 ;
goto V_770;
}
if ( ( V_765 -> V_724 < 1 ) &&
( V_765 -> V_144 . Type . V_762 != V_630 ) ) {
V_49 = - V_55 ;
goto V_770;
}
if ( V_765 -> V_727 > V_771 ) {
V_49 = - V_55 ;
goto V_770;
}
if ( V_765 -> V_724 > V_765 -> V_727 * V_772 ) {
V_49 = - V_55 ;
goto V_770;
}
V_760 = F_115 ( V_772 * sizeof( char * ) , V_203 ) ;
if ( ! V_760 ) {
V_49 = - V_261 ;
goto V_770;
}
V_766 = F_92 ( V_772 * sizeof( int ) , V_203 ) ;
if ( ! V_766 ) {
V_49 = - V_261 ;
goto V_770;
}
V_767 = V_765 -> V_724 ;
V_769 = V_765 -> V_45 ;
while ( V_767 ) {
V_768 = ( V_767 > V_765 -> V_727 ) ? V_765 -> V_727 : V_767 ;
V_766 [ V_370 ] = V_768 ;
V_760 [ V_370 ] = F_92 ( V_768 , V_203 ) ;
if ( V_760 [ V_370 ] == NULL ) {
V_49 = - V_261 ;
goto V_770;
}
if ( V_765 -> V_144 . Type . V_762 & V_628 ) {
if ( F_296 ( V_760 [ V_370 ] , V_769 , V_768 ) ) {
V_49 = - V_725 ;
goto V_770;
}
} else
memset ( V_760 [ V_370 ] , 0 , V_768 ) ;
V_767 -= V_768 ;
V_769 += V_768 ;
V_370 ++ ;
}
V_9 = F_176 ( V_22 ) ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_693 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = ( T_1 ) V_370 ;
V_9 -> V_124 . V_280 = F_160 ( V_370 ) ;
memcpy ( & V_9 -> V_124 . V_349 , & V_765 -> V_722 , sizeof( V_9 -> V_124 . V_349 ) ) ;
memcpy ( & V_9 -> V_144 , & V_765 -> V_144 , sizeof( V_9 -> V_144 ) ) ;
if ( V_765 -> V_724 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
V_267 = F_132 ( V_22 -> V_29 , V_760 [ V_68 ] ,
V_766 [ V_68 ] , V_764 ) ;
if ( F_133 ( & V_22 -> V_29 -> V_30 ,
( V_372 ) V_267 ) ) {
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( 0 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( 0 ) ;
F_161 ( V_22 -> V_29 , V_9 , V_68 ,
V_764 ) ;
V_49 = - V_261 ;
goto V_773;
}
V_9 -> V_276 [ V_68 ] . V_282 = F_134 ( V_267 ) ;
V_9 -> V_276 [ V_68 ] . V_281 = F_139 ( V_766 [ V_68 ] ) ;
V_9 -> V_276 [ V_68 ] . V_278 = F_139 ( 0 ) ;
}
V_9 -> V_276 [ -- V_68 ] . V_278 = F_139 ( V_376 ) ;
}
V_49 = F_168 ( V_22 , V_9 , V_127 ,
V_380 ) ;
if ( V_370 )
F_161 ( V_22 -> V_29 , V_9 , V_370 , V_764 ) ;
F_308 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_387 ;
goto V_773;
}
memcpy ( & V_765 -> V_723 , V_9 -> V_24 , sizeof( V_765 -> V_723 ) ) ;
if ( F_299 ( V_747 , V_765 , sizeof( * V_765 ) ) ) {
V_49 = - V_725 ;
goto V_773;
}
if ( ( V_765 -> V_144 . Type . V_762 & V_629 ) && V_765 -> V_724 > 0 ) {
int V_68 ;
T_14 T_8 * V_774 = V_765 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ ) {
if ( F_299 ( V_774 , V_760 [ V_68 ] , V_766 [ V_68 ] ) ) {
V_49 = - V_725 ;
goto V_773;
}
V_774 += V_766 [ V_68 ] ;
}
}
V_49 = 0 ;
V_773:
F_106 ( V_22 , V_9 ) ;
V_770:
if ( V_760 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_370 ; V_68 ++ )
F_81 ( V_760 [ V_68 ] ) ;
F_81 ( V_760 ) ;
}
F_81 ( V_766 ) ;
F_81 ( V_765 ) ;
return V_49 ;
}
static void F_308 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_295 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_300 ( struct V_2 * V_30 , int V_284 , void T_8 * V_717 )
{
struct V_1 * V_22 ;
void T_8 * V_747 = ( void T_8 * ) V_717 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_284 ) {
case V_739 :
case V_740 :
case V_741 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_729 :
return F_304 ( V_22 , V_747 ) ;
case V_737 :
return F_306 ( V_22 , V_747 ) ;
case V_726 :
if ( F_288 ( & V_22 -> V_775 ) < 0 )
return - V_776 ;
V_21 = F_307 ( V_22 , V_747 ) ;
F_56 ( & V_22 -> V_775 ) ;
return V_21 ;
case V_728 :
if ( F_288 ( & V_22 -> V_775 ) < 0 )
return - V_776 ;
V_21 = F_309 ( V_22 , V_747 ) ;
F_56 ( & V_22 -> V_775 ) ;
return V_21 ;
default:
return - V_777 ;
}
}
static void F_310 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_397 )
{
struct V_8 * V_9 ;
V_9 = F_176 ( V_22 ) ;
( void ) F_177 ( V_9 , V_683 , V_22 , NULL , 0 , 0 ,
V_158 , V_398 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_397 ;
V_9 -> V_379 = NULL ;
F_61 ( V_22 , V_9 ) ;
return;
}
static int F_177 ( struct V_8 * V_9 , T_1 V_284 , struct V_1 * V_22 ,
void * V_760 , T_3 V_468 , T_6 V_778 , unsigned char * V_72 ,
int V_150 )
{
int V_779 = V_630 ;
T_5 V_348 ;
V_9 -> V_150 = V_401 ;
V_9 -> V_10 = V_693 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_760 != NULL && V_468 > 0 ) {
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
if ( V_778 & V_406 ) {
V_9 -> V_144 . V_145 [ 1 ] = 0x01 ;
V_9 -> V_144 . V_145 [ 2 ] = ( V_778 & 0xff ) ;
}
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_392 ;
V_9 -> V_144 . V_145 [ 4 ] = V_468 & 0xFF ;
break;
case V_462 :
case V_463 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_468 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_468 & 0xFF ;
break;
case V_780 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 6 ] = V_780 ;
break;
case V_782 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 ,
V_627 , V_628 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_782 ;
break;
case V_783 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 ,
V_627 , V_628 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_784 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = V_468 & 0xFF ;
break;
case V_475 :
V_9 -> V_144 . V_345 = 6 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_630 ) ;
V_9 -> V_144 . V_625 = 0 ;
break;
case V_424 :
V_9 -> V_144 . V_345 = 12 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_785 ;
V_9 -> V_144 . V_145 [ 1 ] = V_284 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_468 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_468 & 0xFF ;
break;
case V_786 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 6 ] = V_786 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0xFF ;
break;
case V_431 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 6 ] = V_431 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0XFF ;
break;
case V_427 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 6 ] = V_427 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0XFF ;
break;
case V_441 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 6 ] = V_441 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0XFF ;
break;
case V_429 :
V_9 -> V_144 . V_345 = 10 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_629 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_781 ;
V_9 -> V_144 . V_145 [ 1 ] = 0 ;
V_9 -> V_144 . V_145 [ 2 ] = 0 ;
V_9 -> V_144 . V_145 [ 3 ] = 0 ;
V_9 -> V_144 . V_145 [ 4 ] = 0 ;
V_9 -> V_144 . V_145 [ 5 ] = 0 ;
V_9 -> V_144 . V_145 [ 6 ] = V_429 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_468 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_468 >> 8 ) & 0XFF ;
V_9 -> V_144 . V_145 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_215 , V_284 ) ;
F_179 () ;
return - 1 ;
}
} else if ( V_150 == V_398 ) {
switch ( V_284 ) {
case V_684 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_630 ) ;
V_9 -> V_144 . V_625 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_787 ;
V_9 -> V_144 . V_145 [ 1 ] = V_788 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_683 :
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 , V_627 , V_630 ) ;
V_9 -> V_144 . V_625 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_284 ;
V_9 -> V_144 . V_145 [ 1 ] = V_789 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_477 :
memcpy ( & V_348 , V_760 , sizeof( V_348 ) ) ;
F_278 ( & V_22 -> V_29 -> V_30 ,
L_216 ,
V_348 , V_9 -> V_124 . V_348 ) ;
V_9 -> V_144 . V_345 = 16 ;
V_9 -> V_144 . V_626 =
F_253 ( V_150 ,
V_627 , V_628 ) ;
V_9 -> V_144 . V_625 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_790 ;
V_9 -> V_144 . V_145 [ 1 ] = V_791 ;
V_9 -> V_144 . V_145 [ 2 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_144 . V_145 [ 4 ] , & V_348 , sizeof( V_348 ) ) ;
V_9 -> V_144 . V_145 [ 12 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 13 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 14 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_217 ,
V_284 ) ;
F_179 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_218 , V_150 ) ;
F_179 () ;
}
switch ( F_311 ( V_9 -> V_144 . V_626 ) ) {
case V_629 :
V_779 = V_395 ;
break;
case V_628 :
V_779 = V_271 ;
break;
case V_630 :
V_779 = V_375 ;
break;
default:
V_779 = V_764 ;
}
if ( F_162 ( V_22 -> V_29 , V_9 , V_760 , V_468 , V_779 ) )
return - 1 ;
return 0 ;
}
static void T_15 * F_312 ( T_16 V_792 , T_16 V_468 )
{
T_16 V_793 = ( ( T_16 ) V_792 ) & V_794 ;
T_16 V_795 = ( ( T_16 ) V_792 ) - V_793 ;
void T_15 * V_796 = F_313 ( V_793 ,
V_795 + V_468 ) ;
return V_796 ? ( V_796 + V_795 ) : NULL ;
}
static inline unsigned long F_314 ( struct V_1 * V_22 , T_1 V_110 )
{
return V_22 -> V_115 . V_116 ( V_22 , V_110 ) ;
}
static inline bool F_315 ( struct V_1 * V_22 )
{
return V_22 -> V_115 . V_797 ( V_22 ) ;
}
static inline long F_316 ( struct V_1 * V_22 )
{
return ( V_22 -> V_115 . V_797 ( V_22 ) == 0 ) ||
( V_22 -> V_798 == 0 ) ;
}
static inline int F_317 ( struct V_1 * V_22 , T_4 V_799 ,
T_4 V_800 )
{
if ( F_45 ( V_799 >= V_22 -> V_237 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_219 , V_800 ) ;
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
F_318 ( V_9 -> V_379 ) ;
}
static inline void F_319 ( struct V_1 * V_22 ,
T_4 V_800 )
{
T_4 V_799 ;
struct V_8 * V_9 ;
V_799 = V_800 >> V_588 ;
if ( ! F_317 ( V_22 , V_799 , V_800 ) ) {
V_9 = V_22 -> V_239 + V_799 ;
F_62 ( V_9 ) ;
}
}
static int F_320 ( struct V_1 * V_22 )
{
if ( F_48 ( ! V_801 ) )
return 0 ;
if ( F_48 ( V_22 -> V_798 ) )
return 0 ;
F_95 ( & V_22 -> V_29 -> V_30 , L_220
L_221 ) ;
return 1 ;
}
static struct V_1 * F_321 ( T_1 * V_802 )
{
return F_258 ( ( V_802 - * V_802 ) , struct V_1 , V_110 [ 0 ] ) ;
}
static T_17 F_322 ( int V_664 , void * V_802 )
{
struct V_1 * V_22 = F_321 ( V_802 ) ;
T_1 V_110 = * ( T_1 * ) V_802 ;
T_4 V_800 ;
if ( F_320 ( V_22 ) )
return V_803 ;
if ( F_316 ( V_22 ) )
return V_803 ;
V_22 -> V_804 = F_323 () ;
while ( F_315 ( V_22 ) ) {
V_800 = F_314 ( V_22 , V_110 ) ;
while ( V_800 != V_120 )
V_800 = F_44 ( V_22 , V_110 ) ;
}
return V_805 ;
}
static T_17 F_324 ( int V_664 , void * V_802 )
{
struct V_1 * V_22 = F_321 ( V_802 ) ;
T_4 V_800 ;
T_1 V_110 = * ( T_1 * ) V_802 ;
if ( F_320 ( V_22 ) )
return V_803 ;
V_22 -> V_804 = F_323 () ;
V_800 = F_314 ( V_22 , V_110 ) ;
while ( V_800 != V_120 )
V_800 = F_44 ( V_22 , V_110 ) ;
return V_805 ;
}
static T_17 F_325 ( int V_664 , void * V_802 )
{
struct V_1 * V_22 = F_321 ( ( T_1 * ) V_802 ) ;
T_4 V_800 ;
T_1 V_110 = * ( T_1 * ) V_802 ;
if ( F_316 ( V_22 ) )
return V_803 ;
V_22 -> V_804 = F_323 () ;
while ( F_315 ( V_22 ) ) {
V_800 = F_314 ( V_22 , V_110 ) ;
while ( V_800 != V_120 ) {
F_319 ( V_22 , V_800 ) ;
V_800 = F_44 ( V_22 , V_110 ) ;
}
}
return V_805 ;
}
static T_17 F_326 ( int V_664 , void * V_802 )
{
struct V_1 * V_22 = F_321 ( V_802 ) ;
T_4 V_800 ;
T_1 V_110 = * ( T_1 * ) V_802 ;
V_22 -> V_804 = F_323 () ;
V_800 = F_314 ( V_22 , V_110 ) ;
while ( V_800 != V_120 ) {
F_319 ( V_22 , V_800 ) ;
V_800 = F_44 ( V_22 , V_110 ) ;
}
return V_805 ;
}
static int F_327 ( struct V_369 * V_29 , unsigned char V_806 ,
unsigned char type )
{
struct V_807 {
struct V_808 V_809 ;
struct V_810 V_144 ;
struct V_811 V_812 ;
};
struct V_807 * V_284 ;
static const T_3 V_813 = sizeof( * V_284 ) +
sizeof( V_284 -> V_812 ) ;
V_372 V_814 ;
T_7 V_815 ;
T_4 V_348 ;
void T_15 * V_152 ;
int V_68 , V_721 ;
V_152 = F_328 ( V_29 , 0 ) ;
if ( V_152 == NULL )
return - V_261 ;
V_721 = F_329 ( V_29 , F_330 ( 32 ) ) ;
if ( V_721 ) {
F_331 ( V_152 ) ;
return V_721 ;
}
V_284 = F_332 ( V_29 , V_813 , & V_814 ) ;
if ( V_284 == NULL ) {
F_331 ( V_152 ) ;
return - V_261 ;
}
V_815 = F_139 ( V_814 ) ;
V_284 -> V_809 . V_128 = 0 ;
V_284 -> V_809 . V_125 = 0 ;
V_284 -> V_809 . V_280 = F_160 ( 0 ) ;
V_284 -> V_809 . V_348 = F_134 ( V_814 ) ;
memset ( & V_284 -> V_809 . V_349 . V_350 , 0 , 8 ) ;
V_284 -> V_144 . V_345 = 16 ;
V_284 -> V_144 . V_626 =
F_253 ( V_398 , V_816 , V_630 ) ;
V_284 -> V_144 . V_625 = 0 ;
V_284 -> V_144 . V_145 [ 0 ] = V_806 ;
V_284 -> V_144 . V_145 [ 1 ] = type ;
memset ( & V_284 -> V_144 . V_145 [ 2 ] , 0 , 14 ) ;
V_284 -> V_812 . V_282 =
F_134 ( ( F_131 ( V_815 ) + sizeof( * V_284 ) ) ) ;
V_284 -> V_812 . V_281 = F_139 ( sizeof( struct V_337 ) ) ;
F_60 ( F_131 ( V_815 ) , V_152 + V_153 ) ;
for ( V_68 = 0 ; V_68 < V_817 ; V_68 ++ ) {
V_348 = F_333 ( V_152 + V_818 ) ;
if ( ( V_348 & ~ V_819 ) == V_814 )
break;
F_108 ( V_820 ) ;
}
F_331 ( V_152 ) ;
if ( V_68 == V_817 ) {
F_74 ( & V_29 -> V_30 , L_222 ,
V_806 , type ) ;
return - V_382 ;
}
F_334 ( V_29 , V_813 , V_284 , V_814 ) ;
if ( V_348 & V_821 ) {
F_74 ( & V_29 -> V_30 , L_223 ,
V_806 , type ) ;
return - V_387 ;
}
F_95 ( & V_29 -> V_30 , L_224 ,
V_806 , type ) ;
return 0 ;
}
static int F_335 ( struct V_369 * V_29 ,
void T_15 * V_152 , T_4 V_822 )
{
if ( V_822 ) {
F_95 ( & V_29 -> V_30 , L_225 ) ;
F_60 ( V_822 , V_152 + V_823 ) ;
F_108 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_95 ( & V_29 -> V_30 , L_226 ) ;
V_21 = F_336 ( V_29 , V_824 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
V_21 = F_336 ( V_29 , V_825 ) ;
if ( V_21 )
return V_21 ;
F_108 ( 500 ) ;
}
return 0 ;
}
static void F_337 ( char * V_826 , int V_50 )
{
memset ( V_826 , 0 , V_50 ) ;
strncpy ( V_826 , V_41 L_227 V_758 , V_50 - 1 ) ;
}
static int F_338 ( struct V_827 T_15 * V_828 )
{
char * V_826 ;
int V_68 , V_468 = sizeof( V_828 -> V_826 ) ;
V_826 = F_92 ( V_468 , V_203 ) ;
if ( ! V_826 )
return - V_261 ;
F_337 ( V_826 , V_468 ) ;
for ( V_68 = 0 ; V_68 < V_468 ; V_68 ++ )
F_339 ( V_826 [ V_68 ] , & V_828 -> V_826 [ V_68 ] ) ;
F_81 ( V_826 ) ;
return 0 ;
}
static void F_340 ( struct V_827 T_15 * V_828 ,
unsigned char * V_829 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_828 -> V_826 ) ; V_68 ++ )
V_829 [ V_68 ] = F_341 ( & V_828 -> V_826 [ V_68 ] ) ;
}
static int F_342 ( struct V_827 T_15 * V_828 )
{
char * V_829 , * V_830 ;
int V_21 , V_468 = sizeof( V_828 -> V_826 ) ;
V_830 = F_92 ( 2 * V_468 , V_203 ) ;
if ( ! V_830 )
return - V_261 ;
V_829 = V_830 + V_468 ;
F_337 ( V_830 , V_468 ) ;
F_340 ( V_828 , V_829 ) ;
V_21 = ! memcmp ( V_829 , V_830 , V_468 ) ;
F_81 ( V_830 ) ;
return V_21 ;
}
static int F_343 ( struct V_369 * V_29 , T_4 V_67 )
{
T_5 V_831 ;
T_4 V_832 ;
T_5 V_833 ;
void T_15 * V_152 ;
unsigned long V_834 ;
T_4 V_835 ;
int V_21 ;
struct V_827 T_15 * V_828 ;
T_4 V_822 ;
T_6 V_836 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_228 ) ;
return - V_81 ;
}
if ( ! F_25 ( V_67 ) )
return - V_837 ;
F_344 ( V_29 , 4 , & V_836 ) ;
F_345 ( V_29 ) ;
V_21 = F_346 ( V_29 , & V_834 ) ;
if ( V_21 )
return V_21 ;
V_152 = F_312 ( V_834 , 0x250 ) ;
if ( ! V_152 )
return - V_261 ;
V_21 = F_347 ( V_29 , V_152 , & V_832 ,
& V_833 , & V_831 ) ;
if ( V_21 )
goto V_838;
V_828 = F_312 ( F_348 ( V_29 ,
V_833 ) + V_831 , sizeof( * V_828 ) ) ;
if ( ! V_828 ) {
V_21 = - V_261 ;
goto V_838;
}
V_21 = F_338 ( V_828 ) ;
if ( V_21 )
goto V_839;
V_835 = F_333 ( & V_828 -> V_835 ) ;
V_822 = V_835 & V_840 ;
if ( V_822 ) {
V_822 = V_841 ;
} else {
V_822 = V_835 & V_842 ;
if ( V_822 ) {
F_9 ( & V_29 -> V_30 ,
L_229 ) ;
V_21 = - V_837 ;
goto V_839;
}
}
V_21 = F_335 ( V_29 , V_152 , V_822 ) ;
if ( V_21 )
goto V_839;
F_349 ( V_29 ) ;
F_350 ( V_29 , 4 , V_836 ) ;
F_108 ( V_843 ) ;
V_21 = F_351 ( V_29 , V_152 , V_844 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_230 ) ;
goto V_839;
}
V_21 = F_342 ( V_152 ) ;
if ( V_21 < 0 )
goto V_839;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_231
L_232 ) ;
V_21 = - V_837 ;
} else {
F_95 ( & V_29 -> V_30 , L_233 ) ;
}
V_839:
F_331 ( V_828 ) ;
V_838:
F_331 ( V_152 ) ;
return V_21 ;
}
static void F_352 ( struct V_42 * V_30 , struct V_827 T_15 * V_845 )
{
#ifdef F_353
int V_68 ;
char V_846 [ 17 ] ;
F_95 ( V_30 , L_234 ) ;
F_95 ( V_30 , L_235 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_846 [ V_68 ] = F_341 ( & ( V_845 -> V_847 [ V_68 ] ) ) ;
V_846 [ 4 ] = '\0' ;
F_95 ( V_30 , L_236 , V_846 ) ;
F_95 ( V_30 , L_237 , F_333 ( & ( V_845 -> V_848 ) ) ) ;
F_95 ( V_30 , L_238 ,
F_333 ( & ( V_845 -> V_849 ) ) ) ;
F_95 ( V_30 , L_239 ,
F_333 ( & ( V_845 -> V_850 ) ) ) ;
F_95 ( V_30 , L_240 ,
F_333 ( & ( V_845 -> V_851 . V_852 ) ) ) ;
F_95 ( V_30 , L_241 ,
F_333 ( & ( V_845 -> V_851 . V_853 ) ) ) ;
F_95 ( V_30 , L_242 ,
F_333 ( & ( V_845 -> V_851 . V_854 ) ) ) ;
F_95 ( V_30 , L_243 ,
F_333 ( & ( V_845 -> V_855 ) ) ) ;
F_95 ( V_30 , L_244 , F_333 ( & ( V_845 -> V_856 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_846 [ V_68 ] = F_341 ( & ( V_845 -> V_857 [ V_68 ] ) ) ;
V_846 [ 16 ] = '\0' ;
F_95 ( V_30 , L_245 , V_846 ) ;
F_95 ( V_30 , L_246 ,
F_333 ( & ( V_845 -> V_858 ) ) ) ;
#endif
}
static int F_354 ( struct V_369 * V_29 , unsigned long V_859 )
{
int V_68 , V_715 , V_860 , V_861 ;
if ( V_859 == V_862 )
return 0 ;
V_715 = 0 ;
for ( V_68 = 0 ; V_68 < V_863 ; V_68 ++ ) {
V_861 = F_355 ( V_29 , V_68 ) & V_864 ;
if ( V_861 == V_865 )
V_715 += 4 ;
else {
V_860 = F_355 ( V_29 , V_68 ) &
V_866 ;
switch ( V_860 ) {
case V_867 :
case V_868 :
V_715 += 4 ;
break;
case V_869 :
V_715 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_247 ) ;
return - 1 ;
break;
}
}
if ( V_715 == V_859 - V_862 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_356 ( struct V_1 * V_22 )
{
if ( V_22 -> V_126 ) {
if ( V_22 -> V_29 -> V_870 )
F_357 ( V_22 -> V_29 ) ;
V_22 -> V_126 = 0 ;
} else if ( V_22 -> V_871 ) {
if ( V_22 -> V_29 -> V_872 )
F_358 ( V_22 -> V_29 ) ;
V_22 -> V_871 = 0 ;
}
}
static void F_359 ( struct V_1 * V_22 )
{
#ifdef F_360
int V_721 , V_68 ;
struct V_873 V_874 [ V_875 ] ;
for ( V_68 = 0 ; V_68 < V_875 ; V_68 ++ ) {
V_874 [ V_68 ] . V_876 = 0 ;
V_874 [ V_68 ] . V_184 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_877;
if ( F_361 ( V_22 -> V_29 , V_878 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_248 ) ;
V_22 -> V_126 = V_875 ;
if ( V_22 -> V_126 > F_362 () )
V_22 -> V_126 = F_362 () ;
V_721 = F_363 ( V_22 -> V_29 , V_874 ,
1 , V_22 -> V_126 ) ;
if ( V_721 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_249 , V_721 ) ;
V_22 -> V_126 = 0 ;
goto V_879;
} else if ( V_721 < V_22 -> V_126 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_250
L_251 , V_721 ) ;
}
V_22 -> V_126 = V_721 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ )
V_22 -> V_665 [ V_68 ] = V_874 [ V_68 ] . V_876 ;
return;
}
V_879:
if ( F_361 ( V_22 -> V_29 , V_880 ) ) {
F_95 ( & V_22 -> V_29 -> V_30 , L_252 ) ;
if ( ! F_364 ( V_22 -> V_29 ) )
V_22 -> V_871 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_253 ) ;
}
V_877:
#endif
V_22 -> V_665 [ V_22 -> V_666 ] = V_22 -> V_29 -> V_664 ;
}
static int F_365 ( struct V_369 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_881 , V_882 ;
V_881 = V_29 -> V_883 ;
V_882 = V_29 -> V_884 ;
* V_67 = ( ( V_882 << 16 ) & 0xffff0000 ) |
V_881 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_885 ) ; V_68 ++ )
if ( * V_67 == V_885 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_881 != V_886 &&
V_881 != V_887 ) ||
! V_888 ) {
F_9 ( & V_29 -> V_30 , L_254
L_255 , * V_67 ) ;
return - V_81 ;
}
return F_26 ( V_885 ) - 1 ;
}
static int F_346 ( struct V_369 * V_29 ,
unsigned long * V_889 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_863 ; V_68 ++ )
if ( F_355 ( V_29 , V_68 ) & V_890 ) {
* V_889 = F_348 ( V_29 , V_68 ) ;
F_278 ( & V_29 -> V_30 , L_256 ,
* V_889 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_257 ) ;
return - V_81 ;
}
static int F_351 ( struct V_369 * V_29 , void T_15 * V_152 ,
int V_891 )
{
int V_68 , V_892 ;
T_4 V_893 ;
if ( V_891 )
V_892 = V_894 ;
else
V_892 = V_895 ;
for ( V_68 = 0 ; V_68 < V_892 ; V_68 ++ ) {
V_893 = F_333 ( V_152 + V_896 ) ;
if ( V_891 ) {
if ( V_893 == V_897 )
return 0 ;
} else {
if ( V_893 != V_897 )
return 0 ;
}
F_108 ( V_898 ) ;
}
F_9 ( & V_29 -> V_30 , L_258 ) ;
return - V_81 ;
}
static int F_347 ( struct V_369 * V_29 , void T_15 * V_152 ,
T_4 * V_832 , T_5 * V_833 ,
T_5 * V_831 )
{
* V_832 = F_333 ( V_152 + V_899 ) ;
* V_831 = F_333 ( V_152 + V_900 ) ;
* V_832 &= ( T_4 ) 0x0000ffff ;
* V_833 = F_354 ( V_29 , * V_832 ) ;
if ( * V_833 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_259 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_366 ( struct V_1 * V_22 )
{
if ( V_22 -> V_901 ) {
F_331 ( V_22 -> V_901 ) ;
V_22 -> V_901 = NULL ;
}
if ( V_22 -> V_828 ) {
F_331 ( V_22 -> V_828 ) ;
V_22 -> V_828 = NULL ;
}
}
static int F_367 ( struct V_1 * V_22 )
{
T_5 V_831 ;
T_4 V_832 ;
T_5 V_833 ;
T_4 V_902 ;
int V_21 ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_152 , & V_832 ,
& V_833 , & V_831 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_828 = F_312 ( F_348 ( V_22 -> V_29 ,
V_833 ) + V_831 , sizeof( * V_22 -> V_828 ) ) ;
if ( ! V_22 -> V_828 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
return - V_261 ;
}
V_21 = F_338 ( V_22 -> V_828 ) ;
if ( V_21 )
return V_21 ;
V_902 = F_333 ( & V_22 -> V_828 -> V_903 ) ;
V_22 -> V_901 = F_312 ( F_348 ( V_22 -> V_29 ,
V_833 ) + V_831 + V_902 ,
sizeof( * V_22 -> V_901 ) ) ;
if ( ! V_22 -> V_901 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_261 ) ;
F_366 ( V_22 ) ;
return - V_261 ;
}
return 0 ;
}
static void F_368 ( struct V_1 * V_22 )
{
#define F_369 16
F_280 ( F_369 <= V_659 ) ;
V_22 -> V_121 = F_333 ( & V_22 -> V_828 -> V_904 ) ;
if ( V_801 && V_22 -> V_121 > 32 )
V_22 -> V_121 = 32 ;
if ( V_22 -> V_121 < F_369 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_262 ,
V_22 -> V_121 ,
F_369 ) ;
V_22 -> V_121 = F_369 ;
}
}
static int F_370 ( struct V_1 * V_22 )
{
return V_22 -> V_262 > 512 ;
}
static void F_371 ( struct V_1 * V_22 )
{
F_368 ( V_22 ) ;
V_22 -> V_237 = V_22 -> V_121 ;
V_22 -> V_262 = F_333 ( & ( V_22 -> V_828 -> V_905 ) ) ;
V_22 -> V_484 = F_333 ( & ( V_22 -> V_828 -> V_835 ) ) ;
if ( F_370 ( V_22 ) ) {
V_22 -> V_277 = 32 ;
V_22 -> V_260 = V_22 -> V_262 - V_22 -> V_277 ;
V_22 -> V_262 -- ;
} else {
V_22 -> V_277 = 31 ;
V_22 -> V_262 = 31 ;
V_22 -> V_260 = 0 ;
}
V_22 -> V_704 = F_333 ( & ( V_22 -> V_828 -> V_704 ) ) ;
if ( ! ( V_710 & V_22 -> V_704 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_263 ) ;
if ( ! ( V_711 & V_22 -> V_704 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_264 ) ;
if ( ! ( V_703 & V_22 -> V_704 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_265 ) ;
}
static inline bool F_372 ( struct V_1 * V_22 )
{
if ( ! F_373 ( V_22 -> V_828 -> V_847 , L_266 , 4 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_267 ) ;
return false ;
}
return true ;
}
static inline void F_374 ( struct V_1 * V_22 )
{
T_4 V_906 ;
V_906 = F_333 ( & ( V_22 -> V_828 -> V_906 ) ) ;
#ifdef F_375
V_906 |= V_907 ;
#endif
V_906 |= V_908 ;
F_60 ( V_906 , & ( V_22 -> V_828 -> V_906 ) ) ;
}
static inline void F_376 ( struct V_1 * V_22 )
{
T_4 V_909 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_909 = F_333 ( V_22 -> V_152 + V_910 ) ;
V_909 |= 0x8000 ;
F_60 ( V_909 , V_22 -> V_152 + V_910 ) ;
}
static int F_377 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_911 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_912 ; V_68 ++ ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_911 = F_333 ( V_22 -> V_152 + V_823 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_911 & V_913 ) )
goto V_914;
F_108 ( V_915 ) ;
}
return - V_81 ;
V_914:
return 0 ;
}
static int F_378 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_911 ;
unsigned long V_78 ;
for ( V_68 = 0 ; V_68 < V_916 ; V_68 ++ ) {
if ( V_22 -> V_917 )
goto V_914;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_911 = F_333 ( V_22 -> V_152 + V_823 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( ! ( V_911 & V_918 ) )
goto V_914;
F_108 ( V_919 ) ;
}
return - V_81 ;
V_914:
return 0 ;
}
static int F_379 ( struct V_1 * V_22 )
{
T_4 V_920 ;
V_920 = F_333 ( & ( V_22 -> V_828 -> V_849 ) ) ;
if ( ! ( V_920 & V_921 ) )
return - V_837 ;
V_22 -> V_121 = F_333 ( & ( V_22 -> V_828 -> V_855 ) ) ;
F_60 ( V_922 , & ( V_22 -> V_828 -> V_851 . V_852 ) ) ;
F_60 ( 0 , & V_22 -> V_828 -> V_851 . V_923 ) ;
F_60 ( V_918 , V_22 -> V_152 + V_823 ) ;
if ( F_378 ( V_22 ) )
goto error;
F_352 ( & V_22 -> V_29 -> V_30 , V_22 -> V_828 ) ;
if ( ! ( F_333 ( & ( V_22 -> V_828 -> V_850 ) ) & V_922 ) )
goto error;
V_22 -> V_63 = V_922 ;
return 0 ;
error:
F_74 ( & V_22 -> V_29 -> V_30 , L_268 ) ;
return - V_81 ;
}
static void F_380 ( struct V_1 * V_22 )
{
F_366 ( V_22 ) ;
F_331 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
F_356 ( V_22 ) ;
F_381 ( V_22 -> V_29 ) ;
F_382 ( V_22 -> V_29 ) ;
}
static int F_383 ( struct V_1 * V_22 )
{
int V_924 , V_721 ;
V_924 = F_365 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_924 < 0 )
return V_924 ;
V_22 -> V_925 = V_885 [ V_924 ] . V_925 ;
V_22 -> V_115 = * ( V_885 [ V_924 ] . V_115 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_384 ( V_22 -> V_29 , V_926 |
V_927 | V_928 ) ;
V_721 = F_385 ( V_22 -> V_29 ) ;
if ( V_721 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_269 ) ;
F_381 ( V_22 -> V_29 ) ;
return V_721 ;
}
V_721 = F_386 ( V_22 -> V_29 , V_41 ) ;
if ( V_721 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_270 ) ;
F_381 ( V_22 -> V_29 ) ;
return V_721 ;
}
F_387 ( V_22 -> V_29 ) ;
F_359 ( V_22 ) ;
V_721 = F_346 ( V_22 -> V_29 , & V_22 -> V_834 ) ;
if ( V_721 )
goto V_929;
V_22 -> V_152 = F_312 ( V_22 -> V_834 , 0x250 ) ;
if ( ! V_22 -> V_152 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_271 ) ;
V_721 = - V_261 ;
goto V_929;
}
V_721 = F_351 ( V_22 -> V_29 , V_22 -> V_152 , V_844 ) ;
if ( V_721 )
goto V_930;
V_721 = F_367 ( V_22 ) ;
if ( V_721 )
goto V_930;
F_371 ( V_22 ) ;
if ( ! F_372 ( V_22 ) ) {
V_721 = - V_81 ;
goto V_931;
}
F_374 ( V_22 ) ;
F_376 ( V_22 ) ;
V_721 = F_379 ( V_22 ) ;
if ( V_721 )
goto V_931;
return 0 ;
V_931:
F_366 ( V_22 ) ;
V_930:
F_331 ( V_22 -> V_152 ) ;
V_22 -> V_152 = NULL ;
V_929:
F_356 ( V_22 ) ;
F_381 ( V_22 -> V_29 ) ;
F_382 ( V_22 -> V_29 ) ;
return V_721 ;
}
static void F_388 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_389 64
V_22 -> V_61 = F_92 ( F_389 , V_203 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_175 ( V_22 , V_158 , 0 ,
V_22 -> V_61 , F_389 ) ;
if ( V_21 != 0 ) {
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_390 ( struct V_369 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_15 * V_152 ;
if ( ! V_801 )
return 0 ;
V_21 = F_385 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_272 ) ;
return - V_81 ;
}
F_381 ( V_29 ) ;
F_108 ( 260 ) ;
V_21 = F_385 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_273 ) ;
return - V_81 ;
}
F_387 ( V_29 ) ;
V_152 = F_328 ( V_29 , 0 ) ;
if ( V_152 == NULL ) {
V_21 = - V_261 ;
goto V_932;
}
F_60 ( V_933 , V_152 + V_934 ) ;
F_331 ( V_152 ) ;
V_21 = F_343 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_932;
F_95 ( & V_29 -> V_30 , L_274 ) ;
for ( V_68 = 0 ; V_68 < V_935 ; V_68 ++ ) {
if ( F_391 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_275 ,
( V_68 < 11 ? L_276 : L_277 ) ) ;
}
V_932:
F_381 ( V_29 ) ;
return V_21 ;
}
static void F_392 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_716 ) ;
V_22 -> V_716 = NULL ;
if ( V_22 -> V_239 ) {
F_334 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_8 ) ,
V_22 -> V_239 ,
V_22 -> V_636 ) ;
V_22 -> V_239 = NULL ;
V_22 -> V_636 = 0 ;
}
if ( V_22 -> V_637 ) {
F_334 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( struct V_337 ) ,
V_22 -> V_637 ,
V_22 -> V_638 ) ;
V_22 -> V_637 = NULL ;
V_22 -> V_638 = 0 ;
}
}
static int F_393 ( struct V_1 * V_22 )
{
V_22 -> V_716 = F_115 (
F_394 ( V_22 -> V_237 , V_617 ) *
sizeof( unsigned long ) , V_203 ) ;
V_22 -> V_239 = F_332 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_239 ) ,
& ( V_22 -> V_636 ) ) ;
V_22 -> V_637 = F_332 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_637 ) ,
& ( V_22 -> V_638 ) ) ;
if ( ( V_22 -> V_716 == NULL )
|| ( V_22 -> V_239 == NULL )
|| ( V_22 -> V_637 == NULL ) ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_278 , V_204 ) ;
goto V_936;
}
F_255 ( V_22 ) ;
return 0 ;
V_936:
F_392 ( V_22 ) ;
return - V_261 ;
}
static void F_395 ( struct V_1 * V_22 )
{
int V_68 , V_383 ;
V_383 = F_396 ( V_937 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_397 ( V_22 -> V_665 [ V_68 ] , F_398 ( V_383 ) ) ;
V_383 = F_399 ( V_383 , V_937 ) ;
}
}
static void F_400 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_126 || V_22 -> V_666 != V_938 ) {
V_68 = V_22 -> V_666 ;
F_397 ( V_22 -> V_665 [ V_68 ] , NULL ) ;
F_401 ( V_22 -> V_665 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
F_397 ( V_22 -> V_665 [ V_68 ] , NULL ) ;
F_401 ( V_22 -> V_665 [ V_68 ] , & V_22 -> V_110 [ V_68 ] ) ;
V_22 -> V_110 [ V_68 ] = 0 ;
}
for (; V_68 < V_875 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = 0 ;
}
static int F_402 ( struct V_1 * V_22 ,
T_17 (* F_403)( int , void * ) ,
T_17 (* F_404)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_875 ; V_68 ++ )
V_22 -> V_110 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_666 == V_938 && V_22 -> V_126 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_126 ; V_68 ++ ) {
sprintf ( V_22 -> V_939 [ V_68 ] , L_279 , V_22 -> V_31 , V_68 ) ;
V_21 = F_405 ( V_22 -> V_665 [ V_68 ] , F_403 ,
0 , V_22 -> V_939 [ V_68 ] ,
& V_22 -> V_110 [ V_68 ] ) ;
if ( V_21 ) {
int V_193 ;
F_74 ( & V_22 -> V_29 -> V_30 ,
L_280 ,
V_22 -> V_665 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_193 = 0 ; V_193 < V_68 ; V_193 ++ ) {
F_401 ( V_22 -> V_665 [ V_193 ] , & V_22 -> V_110 [ V_193 ] ) ;
V_22 -> V_110 [ V_193 ] = 0 ;
}
for (; V_193 < V_875 ; V_193 ++ )
V_22 -> V_110 [ V_193 ] = 0 ;
return V_21 ;
}
}
F_395 ( V_22 ) ;
} else {
if ( V_22 -> V_126 > 0 || V_22 -> V_871 ) {
if ( V_22 -> V_126 )
sprintf ( V_22 -> V_939 [ V_22 -> V_666 ] ,
L_281 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_939 [ V_22 -> V_666 ] ,
L_282 , V_22 -> V_31 ) ;
V_21 = F_405 ( V_22 -> V_665 [ V_22 -> V_666 ] ,
F_403 , 0 ,
V_22 -> V_939 [ V_22 -> V_666 ] ,
& V_22 -> V_110 [ V_22 -> V_666 ] ) ;
} else {
sprintf ( V_22 -> V_939 [ V_22 -> V_666 ] ,
L_283 , V_22 -> V_31 ) ;
V_21 = F_405 ( V_22 -> V_665 [ V_22 -> V_666 ] ,
F_404 , V_940 ,
V_22 -> V_939 [ V_22 -> V_666 ] ,
& V_22 -> V_110 [ V_22 -> V_666 ] ) ;
}
F_397 ( V_22 -> V_665 [ V_22 -> V_666 ] , NULL ) ;
}
if ( V_21 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_280 ,
V_22 -> V_665 [ V_22 -> V_666 ] , V_22 -> V_31 ) ;
F_400 ( V_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_406 ( struct V_1 * V_22 )
{
int V_21 ;
F_310 ( V_22 , V_158 , V_941 ) ;
F_95 ( & V_22 -> V_29 -> V_30 , L_284 ) ;
V_21 = F_351 ( V_22 -> V_29 , V_22 -> V_152 , V_942 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_285 ) ;
return V_21 ;
}
F_95 ( & V_22 -> V_29 -> V_30 , L_286 ) ;
V_21 = F_351 ( V_22 -> V_29 , V_22 -> V_152 , V_844 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_287
L_288 ) ;
return V_21 ;
}
return 0 ;
}
static void F_407 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
if ( ! V_22 -> V_113 [ V_68 ] . V_117 )
continue;
F_334 ( V_22 -> V_29 ,
V_22 -> V_943 ,
V_22 -> V_113 [ V_68 ] . V_117 ,
V_22 -> V_113 [ V_68 ] . V_122 ) ;
V_22 -> V_113 [ V_68 ] . V_117 = NULL ;
V_22 -> V_113 [ V_68 ] . V_122 = 0 ;
}
V_22 -> V_943 = 0 ;
}
static void F_408 ( struct V_1 * V_22 )
{
F_409 ( V_22 ) ;
F_128 ( V_22 ) ;
F_392 ( V_22 ) ;
F_400 ( V_22 ) ;
F_410 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_380 ( V_22 ) ;
F_411 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_327 ) {
F_412 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_944 ) {
F_412 ( V_22 -> V_944 ) ;
V_22 -> V_944 = NULL ;
}
F_81 ( V_22 ) ;
}
static void F_413 ( struct V_1 * V_22 )
{
int V_68 , V_240 ;
struct V_8 * V_9 ;
int V_945 = 0 ;
F_414 ( V_22 -> V_327 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 ) {
V_9 -> V_24 -> V_36 = V_343 ;
F_62 ( V_9 ) ;
F_46 ( & V_22 -> V_62 ) ;
V_945 ++ ;
}
F_106 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_289 , V_945 ) ;
}
static void F_415 ( struct V_1 * V_22 , T_4 V_946 )
{
int V_383 ;
F_416 (cpu) {
T_4 * F_13 ;
F_13 = F_170 ( V_22 -> F_13 , V_383 ) ;
* F_13 = V_946 ;
}
F_77 () ;
}
static void F_417 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
T_4 F_13 ;
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
F_13 = F_333 ( V_22 -> V_152 + V_896 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_290 ,
V_22 -> V_147 / V_949 ) ;
F_13 = 0xffffffff ;
}
F_415 ( V_22 , F_13 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_291 ,
F_13 , V_22 -> V_147 / V_949 ) ;
F_381 ( V_22 -> V_29 ) ;
F_413 ( V_22 ) ;
}
static int F_274 ( struct V_1 * V_22 )
{
T_5 V_950 ;
T_4 V_951 ;
unsigned long V_78 ;
V_950 = F_323 () ;
if ( F_418 ( V_22 -> V_804 +
( V_22 -> V_147 ) , V_950 ) )
return false ;
if ( F_418 ( V_22 -> V_952 +
( V_22 -> V_147 ) , V_950 ) )
return false ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_951 = F_333 ( & V_22 -> V_828 -> V_858 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
if ( V_22 -> V_953 == V_951 ) {
F_417 ( V_22 ) ;
return true ;
}
V_22 -> V_953 = V_951 ;
V_22 -> V_952 = V_950 ;
return false ;
}
static void F_419 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_954 ;
if ( ! ( V_22 -> V_484 & V_955 ) )
return;
if ( ( V_22 -> V_63 & ( V_114
| V_956 ) ) &&
( V_22 -> V_957 & V_958 ||
V_22 -> V_957 & V_959 ) ) {
if ( V_22 -> V_957 & V_958 )
V_954 = L_292 ;
if ( V_22 -> V_957 & V_959 )
V_954 = L_293 ;
F_420 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_22 -> V_30 [ V_68 ] -> V_91 = 0 ;
V_22 -> V_30 [ V_68 ] -> V_183 = 0 ;
}
F_421 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_294 ,
V_22 -> V_957 , V_954 ) ;
F_60 ( V_22 -> V_957 , & ( V_22 -> V_828 -> V_960 ) ) ;
F_60 ( V_913 , V_22 -> V_152 + V_823 ) ;
F_377 ( V_22 ) ;
F_422 ( V_22 -> V_59 ) ;
} else {
F_60 ( V_22 -> V_957 , & ( V_22 -> V_828 -> V_960 ) ) ;
F_60 ( V_913 , V_22 -> V_152 + V_823 ) ;
F_377 ( V_22 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_423 ( struct V_1 * V_22 )
{
if ( V_22 -> V_249 ) {
V_22 -> V_249 = 0 ;
return 1 ;
}
if ( ! ( V_22 -> V_484 & V_955 ) )
return 0 ;
V_22 -> V_957 = F_333 ( & ( V_22 -> V_828 -> V_961 ) ) ;
return V_22 -> V_957 & V_962 ;
}
static int F_424 ( struct V_1 * V_22 )
{
unsigned long V_78 ;
struct V_201 * V_389 ;
struct V_963 * V_964 , * V_965 ;
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_425 (this, tmp, &h->offline_device_list) {
V_389 = F_426 ( V_964 , struct V_201 ,
V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
if ( ! F_208 ( V_22 , V_389 -> V_72 ) ) {
F_35 ( & V_22 -> V_202 , V_78 ) ;
F_427 ( & V_389 -> V_205 ) ;
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_202 , V_78 ) ;
}
F_36 ( & V_22 -> V_202 , V_78 ) ;
return 0 ;
}
static int F_428 ( struct V_1 * V_22 )
{
int V_21 = 1 ;
struct V_464 * V_497 = NULL ;
if ( ! V_22 -> V_966 )
goto V_394;
V_497 = F_115 ( sizeof( * V_497 ) , V_203 ) ;
if ( ! V_497 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_295 ) ;
goto V_394;
}
if ( F_204 ( V_22 , 1 , V_497 , sizeof( * V_497 ) , 0 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_296 ) ;
goto V_394;
}
if ( memcmp ( V_497 , V_22 -> V_966 , sizeof( * V_497 ) ) ) {
F_95 ( & V_22 -> V_29 -> V_30 ,
L_297 ) ;
memcpy ( V_22 -> V_966 , V_497 , sizeof( * V_497 ) ) ;
goto V_394;
} else
V_21 = 0 ;
V_394:
F_81 ( V_497 ) ;
return V_21 ;
}
static void F_429 ( struct V_640 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_258 ( F_430 ( V_325 ) ,
struct V_1 , V_967 ) ;
if ( V_22 -> V_917 )
return;
if ( F_423 ( V_22 ) || F_424 ( V_22 ) ) {
F_431 ( V_22 -> V_59 ) ;
F_419 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_410 ( V_22 -> V_59 ) ;
} else if ( V_22 -> V_533 ) {
F_432 ( V_22 ) ;
if ( F_428 ( V_22 ) ) {
struct V_6 * V_7 = NULL ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_298 ) ;
V_7 = F_431 ( V_22 -> V_59 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_410 ( V_7 ) ;
}
}
}
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_917 )
F_433 ( V_22 -> V_944 , & V_22 -> V_967 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static void F_434 ( struct V_640 * V_325 )
{
unsigned long V_78 ;
struct V_1 * V_22 = F_258 ( F_430 ( V_325 ) ,
struct V_1 , V_968 ) ;
F_274 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_35 ( & V_22 -> V_79 , V_78 ) ;
if ( ! V_22 -> V_917 )
F_435 ( & V_22 -> V_968 ,
V_22 -> V_147 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
}
static struct V_969 * F_436 ( struct V_1 * V_22 ,
char * V_970 )
{
struct V_969 * V_971 = NULL ;
V_971 = F_437 ( L_299 , 0 , V_970 , V_22 -> V_483 ) ;
if ( ! V_971 )
F_74 ( & V_22 -> V_29 -> V_30 , L_300 , V_970 ) ;
return V_971 ;
}
static int F_438 ( struct V_369 * V_29 , const struct V_972 * V_973 )
{
int V_974 , V_21 ;
struct V_1 * V_22 ;
int V_975 = 0 ;
unsigned long V_78 ;
T_4 V_67 ;
if ( V_976 == 0 )
F_439 (KERN_INFO DRIVER_NAME L_301 ) ;
V_21 = F_365 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_302 ) ;
return V_21 ;
}
V_21 = F_390 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_837 )
return V_21 ;
V_975 = 1 ;
V_21 = 0 ;
}
V_977:
F_280 ( sizeof( struct V_8 ) % V_978 ) ;
V_22 = F_115 ( sizeof( * V_22 ) , V_203 ) ;
if ( ! V_22 ) {
F_74 ( & V_29 -> V_30 , L_303 ) ;
return - V_261 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_666 = V_979 ? V_980 : V_938 ;
F_440 ( & V_22 -> V_206 ) ;
F_441 ( & V_22 -> V_79 ) ;
F_441 ( & V_22 -> V_202 ) ;
F_441 ( & V_22 -> V_645 ) ;
F_122 ( & V_22 -> V_775 , V_981 ) ;
F_122 ( & V_22 -> V_706 , V_982 ) ;
V_22 -> F_13 = F_442 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_74 ( & V_22 -> V_29 -> V_30 , L_304 ) ;
V_21 = - V_261 ;
goto V_983;
}
F_415 ( V_22 , 0 ) ;
V_21 = F_383 ( V_22 ) ;
if ( V_21 )
goto V_929;
V_21 = F_264 ( V_22 ) ;
if ( V_21 )
goto V_984;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_102 ) ;
V_22 -> V_483 = V_976 ;
V_976 ++ ;
V_21 = F_443 ( V_29 , F_330 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_974 = 1 ;
} else {
V_21 = F_443 ( V_29 , F_330 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_974 = 0 ;
} else {
F_74 ( & V_29 -> V_30 , L_305 ) ;
goto V_930;
}
}
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
V_21 = F_402 ( V_22 , F_326 , F_325 ) ;
if ( V_21 )
goto V_930;
V_21 = F_393 ( V_22 ) ;
if ( V_21 )
goto V_931;
V_21 = F_129 ( V_22 ) ;
if ( V_21 )
goto V_985;
F_444 ( & V_22 -> V_647 ) ;
F_444 ( & V_22 -> V_705 ) ;
F_444 ( & V_22 -> V_323 ) ;
F_445 ( & V_22 -> V_403 ) ;
V_22 -> V_646 = 1 ;
F_446 ( V_29 , V_22 ) ;
V_22 -> V_162 = 0 ;
F_441 ( & V_22 -> V_98 ) ;
V_21 = F_447 ( V_22 ) ;
if ( V_21 )
goto V_986;
V_22 -> V_944 = F_436 ( V_22 , L_306 ) ;
if ( ! V_22 -> V_944 ) {
V_21 = - V_261 ;
goto V_987;
}
V_22 -> V_327 = F_436 ( V_22 , L_307 ) ;
if ( ! V_22 -> V_327 ) {
V_21 = - V_261 ;
goto V_987;
}
if ( V_975 ) {
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_400 ( V_22 ) ;
V_21 = F_402 ( V_22 , F_324 ,
F_322 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_308 ) ;
F_409 ( V_22 ) ;
F_128 ( V_22 ) ;
F_392 ( V_22 ) ;
goto V_930;
}
V_21 = F_406 ( V_22 ) ;
if ( V_21 )
goto V_987;
F_95 ( & V_22 -> V_29 -> V_30 , L_309 ) ;
F_95 ( & V_22 -> V_29 -> V_30 ,
L_310 ) ;
V_22 -> V_115 . V_947 ( V_22 , V_988 ) ;
F_108 ( 10000 ) ;
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
V_21 = F_342 ( V_22 -> V_828 ) ;
if ( V_21 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_311 ) ;
F_408 ( V_22 ) ;
V_975 = 0 ;
if ( V_21 )
return - V_81 ;
goto V_977;
}
V_22 -> V_56 = 1 ;
V_22 -> V_533 = 0 ;
V_22 -> V_115 . V_947 ( V_22 , V_988 ) ;
F_388 ( V_22 ) ;
V_22 -> V_966 = F_115 ( sizeof( * ( V_22 -> V_966 ) ) , V_203 ) ;
if ( ! V_22 -> V_966 )
F_95 ( & V_22 -> V_29 -> V_30 ,
L_312 ) ;
V_21 = F_266 ( V_22 ) ;
if ( V_21 )
goto V_987;
V_22 -> V_147 = V_149 ;
F_448 ( & V_22 -> V_968 , F_434 ) ;
F_435 ( & V_22 -> V_968 ,
V_22 -> V_147 ) ;
F_448 ( & V_22 -> V_967 , F_429 ) ;
F_433 ( V_22 -> V_944 , & V_22 -> V_967 ,
V_22 -> V_147 ) ;
return 0 ;
V_987:
F_409 ( V_22 ) ;
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
V_986:
F_128 ( V_22 ) ;
V_985:
F_392 ( V_22 ) ;
V_931:
F_400 ( V_22 ) ;
V_930:
F_410 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_984:
F_380 ( V_22 ) ;
V_929:
if ( V_22 -> F_13 ) {
F_411 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_983:
if ( V_22 -> V_327 ) {
F_412 ( V_22 -> V_327 ) ;
V_22 -> V_327 = NULL ;
}
if ( V_22 -> V_944 ) {
F_412 ( V_22 -> V_944 ) ;
V_22 -> V_944 = NULL ;
}
F_81 ( V_22 ) ;
return V_21 ;
}
static void F_449 ( struct V_1 * V_22 )
{
char * V_989 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( F_13 ( V_22 ) ) )
return;
V_989 = F_115 ( 4 , V_203 ) ;
if ( ! V_989 )
return;
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_783 , V_22 , V_989 , 4 , 0 ,
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
L_313 ) ;
F_106 ( V_22 , V_9 ) ;
F_81 ( V_989 ) ;
}
static void F_432 ( struct V_1 * V_22 )
{
T_4 * V_990 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_45 ( V_22 -> F_13 ) )
return;
V_990 = F_115 ( sizeof( * V_990 ) , V_203 ) ;
if ( ! V_990 ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_314 ) ;
return;
}
V_9 = F_176 ( V_22 ) ;
if ( F_177 ( V_9 , V_780 , V_22 , V_990 , 4 , 0 ,
V_158 , V_393 ) )
goto V_991;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_991;
* V_990 |= V_992 ;
if ( F_177 ( V_9 , V_782 , V_22 , V_990 , 4 , 0 ,
V_158 , V_393 ) )
goto V_991;
V_21 = F_172 ( V_22 , V_9 ,
V_271 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_991;
if ( F_177 ( V_9 , V_780 , V_22 , V_990 , 4 , 0 ,
V_158 , V_393 ) )
goto V_991;
V_21 = F_172 ( V_22 , V_9 ,
V_395 , V_396 ) ;
if ( ( V_21 != 0 ) || ( V_9 -> V_24 -> V_36 != 0 ) )
goto V_991;
if ( * V_990 & V_992 )
goto V_394;
V_991:
F_74 ( & V_22 -> V_29 -> V_30 ,
L_315 ) ;
V_394:
F_106 ( V_22 , V_9 ) ;
F_81 ( V_990 ) ;
}
static void F_450 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_451 ( V_29 ) ;
F_449 ( V_22 ) ;
V_22 -> V_115 . V_947 ( V_22 , V_948 ) ;
F_400 ( V_22 ) ;
F_356 ( V_22 ) ;
}
static void F_452 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
F_81 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_453 ( struct V_369 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_78 ;
if ( F_451 ( V_29 ) == NULL ) {
F_74 ( & V_29 -> V_30 , L_316 ) ;
return;
}
V_22 = F_451 ( V_29 ) ;
F_35 ( & V_22 -> V_79 , V_78 ) ;
V_22 -> V_917 = 1 ;
F_36 ( & V_22 -> V_79 , V_78 ) ;
F_454 ( & V_22 -> V_968 ) ;
F_454 ( & V_22 -> V_967 ) ;
F_412 ( V_22 -> V_944 ) ;
F_412 ( V_22 -> V_327 ) ;
if ( V_22 -> V_59 )
F_455 ( V_22 -> V_59 ) ;
F_450 ( V_29 ) ;
F_452 ( V_22 ) ;
F_81 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
F_126 ( V_22 ) ;
F_409 ( V_22 ) ;
F_128 ( V_22 ) ;
F_392 ( V_22 ) ;
F_81 ( V_22 -> V_966 ) ;
F_410 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_380 ( V_22 ) ;
F_411 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_456 ( V_22 ) ;
F_81 ( V_22 ) ;
}
static void F_457 ( int V_993 [] , int V_994 ,
int V_995 , int V_996 , T_4 * V_997 )
{
int V_68 , V_193 , V_998 , V_468 ;
for ( V_68 = 0 ; V_68 <= V_995 ; V_68 ++ ) {
V_468 = V_68 + V_996 ;
V_998 = V_994 ;
for ( V_193 = 0 ; V_193 < V_994 ; V_193 ++ ) {
if ( V_993 [ V_193 ] >= V_468 ) {
V_998 = V_193 ;
break;
}
}
V_997 [ V_68 ] = V_998 ;
}
}
static int F_458 ( struct V_1 * V_22 , T_4 V_920 )
{
int V_68 ;
unsigned long V_999 ;
unsigned long V_63 = V_64 |
( V_920 & V_1000 ) |
V_1001 |
( V_920 & ( V_114 |
V_956 ) ) ;
struct V_1002 V_115 = V_1003 ;
int V_1004 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_772 + 4 } ;
#define F_459 5
#define F_460 4
int V_1005 [ 16 ] = { F_459 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_460 + V_1006 } ;
F_280 ( F_26 ( V_1005 ) != 16 ) ;
F_280 ( F_26 ( V_1004 ) != 8 ) ;
F_280 ( F_248 ( struct V_139 , V_269 ) >
16 * F_459 ) ;
F_280 ( sizeof( struct V_265 ) != 16 ) ;
F_280 ( 28 > V_772 + 4 ) ;
if ( V_920 & ( V_114 | V_956 ) )
V_115 = V_1007 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 , 0 , V_22 -> V_943 ) ;
V_1004 [ 7 ] = V_772 + 4 ;
F_457 ( V_1004 , F_26 ( V_1004 ) ,
V_772 , 4 , V_22 -> V_123 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_60 ( V_1004 [ V_68 ] , & V_22 -> V_901 -> V_1008 [ V_68 ] ) ;
F_60 ( V_22 -> V_121 , & V_22 -> V_901 -> V_1009 ) ;
F_60 ( V_22 -> V_129 , & V_22 -> V_901 -> V_1010 ) ;
F_60 ( 0 , & V_22 -> V_901 -> V_1011 ) ;
F_60 ( 0 , & V_22 -> V_901 -> V_1012 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( 0 , & V_22 -> V_901 -> V_1013 [ V_68 ] . V_1014 ) ;
F_60 ( V_22 -> V_113 [ V_68 ] . V_122 ,
& V_22 -> V_901 -> V_1013 [ V_68 ] . V_1015 ) ;
}
F_60 ( 0 , & V_22 -> V_828 -> V_851 . V_923 ) ;
F_60 ( V_63 , & ( V_22 -> V_828 -> V_851 . V_852 ) ) ;
if ( V_920 & V_114 ) {
V_115 = V_1016 ;
F_60 ( 10 , & V_22 -> V_828 -> V_851 . V_853 ) ;
F_60 ( 4 , & V_22 -> V_828 -> V_851 . V_854 ) ;
} else {
if ( V_920 & V_956 ) {
V_115 = V_1017 ;
F_60 ( 10 , & V_22 -> V_828 -> V_851 . V_853 ) ;
F_60 ( 4 , & V_22 -> V_828 -> V_851 . V_854 ) ;
}
}
F_60 ( V_918 , V_22 -> V_152 + V_823 ) ;
if ( F_378 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_317 ) ;
return - V_81 ;
}
V_999 = F_333 ( & ( V_22 -> V_828 -> V_850 ) ) ;
if ( ! ( V_999 & V_64 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_318 ) ;
return - V_81 ;
}
V_22 -> V_115 = V_115 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_920 & V_114 ) ||
( V_920 & V_956 ) ) )
return 0 ;
if ( V_920 & V_114 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
F_60 ( V_68 , V_22 -> V_152 + V_1018 ) ;
V_22 -> V_113 [ V_68 ] . V_118 =
F_333 ( V_22 -> V_152 + V_1019 ) ;
}
V_1004 [ 7 ] = V_22 -> V_557 + 8 ;
F_457 ( V_1004 , F_26 ( V_1004 ) , V_22 -> V_557 , 8 ,
V_22 -> V_134 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ )
memset ( V_22 -> V_113 [ V_68 ] . V_117 ,
( T_1 ) V_1020 ,
V_22 -> V_943 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
struct V_130 * V_131 = & V_22 -> V_132 [ V_68 ] ;
V_131 -> V_1021 = V_1022 ;
V_131 -> V_24 = ( T_4 ) ( V_22 -> V_638 +
( V_68 * sizeof( struct V_337 ) ) ) ;
V_131 -> V_1023 = sizeof( struct V_337 ) ;
V_131 -> V_1024 = V_1025 ;
V_131 -> V_1026 =
F_160 ( V_1027 ) ;
V_131 -> V_1028 = 0 ;
V_131 -> V_128 = 0 ;
V_131 -> V_348 =
F_134 ( ( V_68 << V_588 ) ) ;
V_131 -> V_1029 =
F_134 ( V_22 -> V_560 +
( V_68 * sizeof( struct V_130 ) ) ) ;
}
} else if ( V_920 & V_956 ) {
T_5 V_831 , V_833 ;
T_4 V_1030 , V_832 ;
int V_21 ;
V_21 = F_347 ( V_22 -> V_29 , V_22 -> V_152 , & V_832 ,
& V_833 , & V_831 ) ;
F_280 ( F_248 ( struct V_139 , V_269 ) != 64 ) ;
V_1005 [ 15 ] = V_22 -> V_557 + F_460 ;
F_457 ( V_1005 , F_26 ( V_1005 ) , V_22 -> V_557 ,
4 , V_22 -> V_138 ) ;
V_1030 = F_333 ( & V_22 -> V_828 -> V_1031 ) ;
F_280 ( F_248 ( struct V_827 ,
V_1031 ) != 0xb8 ) ;
V_22 -> V_1032 =
F_312 ( F_348 ( V_22 -> V_29 ,
V_833 ) +
V_831 + V_1030 ,
F_26 ( V_1005 ) *
sizeof( * V_22 -> V_1032 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_1005 ) ; V_68 ++ )
F_60 ( V_1005 [ V_68 ] , & V_22 -> V_1032 [ V_68 ] ) ;
}
F_60 ( V_918 , V_22 -> V_152 + V_823 ) ;
if ( F_378 ( V_22 ) ) {
F_74 ( & V_22 -> V_29 -> V_30 ,
L_319 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_461 ( struct V_1 * V_22 )
{
if ( V_22 -> V_132 ) {
F_334 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
V_22 -> V_132 ,
V_22 -> V_560 ) ;
V_22 -> V_132 = NULL ;
V_22 -> V_560 = 0 ;
}
F_81 ( V_22 -> V_134 ) ;
V_22 -> V_134 = NULL ;
}
static int F_462 ( struct V_1 * V_22 )
{
V_22 -> V_557 =
F_333 ( & ( V_22 -> V_828 -> V_1033 ) ) ;
if ( V_22 -> V_557 > V_1034 )
V_22 -> V_557 = V_1034 ;
F_280 ( sizeof( struct V_130 ) %
V_1035 ) ;
V_22 -> V_132 =
F_332 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ,
& ( V_22 -> V_560 ) ) ;
V_22 -> V_134 =
F_92 ( ( ( V_22 -> V_557 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_132 == NULL ) ||
( V_22 -> V_134 == NULL ) )
goto V_936;
memset ( V_22 -> V_132 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_132 ) ) ;
return 0 ;
V_936:
F_461 ( V_22 ) ;
return - V_261 ;
}
static void F_463 ( struct V_1 * V_22 )
{
F_126 ( V_22 ) ;
if ( V_22 -> V_137 ) {
F_334 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
V_22 -> V_137 ,
V_22 -> V_579 ) ;
V_22 -> V_137 = NULL ;
V_22 -> V_579 = 0 ;
}
F_81 ( V_22 -> V_138 ) ;
V_22 -> V_138 = NULL ;
}
static int F_464 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_557 =
F_333 ( & ( V_22 -> V_828 -> V_1033 ) ) ;
if ( V_22 -> V_557 > V_1006 )
V_22 -> V_557 = V_1006 ;
F_280 ( sizeof( struct V_139 ) %
V_1036 ) ;
V_22 -> V_137 =
F_332 ( V_22 -> V_29 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ,
& ( V_22 -> V_579 ) ) ;
V_22 -> V_138 =
F_92 ( ( ( V_22 -> V_557 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_22 -> V_137 == NULL ) ||
( V_22 -> V_138 == NULL ) ) {
V_21 = - V_261 ;
goto V_936;
}
V_21 = F_127 ( V_22 ) ;
if ( V_21 )
goto V_936;
memset ( V_22 -> V_137 , 0 ,
V_22 -> V_237 * sizeof( * V_22 -> V_137 ) ) ;
return 0 ;
V_936:
F_463 ( V_22 ) ;
return V_21 ;
}
static void F_409 ( struct V_1 * V_22 )
{
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
F_407 ( V_22 ) ;
F_461 ( V_22 ) ;
F_463 ( V_22 ) ;
}
static int F_447 ( struct V_1 * V_22 )
{
T_4 V_920 ;
unsigned long V_63 = V_64 |
V_1000 ;
int V_68 , V_21 ;
if ( V_979 )
return 0 ;
V_920 = F_333 ( & ( V_22 -> V_828 -> V_849 ) ) ;
if ( ! ( V_920 & V_1037 ) )
return 0 ;
if ( V_920 & V_114 ) {
V_63 |= V_114 |
V_1001 ;
V_21 = F_462 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_920 & V_956 ) {
V_63 |= V_956 |
V_1001 ;
V_21 = F_464 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_129 = V_22 -> V_126 > 0 ? V_22 -> V_126 : 1 ;
F_368 ( V_22 ) ;
V_22 -> V_943 = V_22 -> V_121 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_129 ; V_68 ++ ) {
V_22 -> V_113 [ V_68 ] . V_117 = F_332 ( V_22 -> V_29 ,
V_22 -> V_943 ,
& ( V_22 -> V_113 [ V_68 ] . V_122 ) ) ;
if ( ! V_22 -> V_113 [ V_68 ] . V_117 ) {
V_21 = - V_261 ;
goto V_983;
}
V_22 -> V_113 [ V_68 ] . V_468 = V_22 -> V_121 ;
V_22 -> V_113 [ V_68 ] . V_119 = 1 ;
V_22 -> V_113 [ V_68 ] . V_118 = 0 ;
}
V_22 -> V_123 = F_92 ( ( ( V_772 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ! V_22 -> V_123 ) {
V_21 = - V_261 ;
goto V_983;
}
V_21 = F_458 ( V_22 , V_920 ) ;
if ( V_21 )
goto V_929;
return 0 ;
V_929:
F_81 ( V_22 -> V_123 ) ;
V_22 -> V_123 = NULL ;
V_983:
F_407 ( V_22 ) ;
F_461 ( V_22 ) ;
F_463 ( V_22 ) ;
return V_21 ;
}
static int F_465 ( struct V_8 * V_9 )
{
return V_9 -> V_150 == V_151 || V_9 -> V_150 == V_154 ;
}
static void F_421 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_1038 ;
int V_240 ;
do {
V_1038 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_237 ; V_68 ++ ) {
V_9 = V_22 -> V_239 + V_68 ;
V_240 = F_104 ( & V_9 -> V_240 ) ;
if ( V_240 > 1 )
V_1038 += F_465 ( V_9 ) ;
F_106 ( V_22 , V_9 ) ;
}
if ( V_1038 <= 0 )
break;
F_108 ( 100 ) ;
} while ( 1 );
}
static struct V_1039 * F_466 (
struct V_1040 * V_1040 )
{
struct V_1039 * V_1039 ;
struct V_1041 * V_1042 ;
V_1039 = F_115 ( sizeof( * V_1039 ) , V_203 ) ;
if ( ! V_1039 )
return NULL ;
V_1042 = F_467 ( V_1040 -> V_1043 -> V_1044 ,
V_1040 -> V_1045 ) ;
if ( ! V_1042 ) {
F_81 ( V_1039 ) ;
return NULL ;
}
V_1040 -> V_1045 ++ ;
V_1039 -> V_1042 = V_1042 ;
V_1039 -> V_1046 = V_1040 ;
return V_1039 ;
}
static void F_468 ( struct V_1039 * V_1039 )
{
struct V_1041 * V_1042 = V_1039 -> V_1042 ;
F_469 ( V_1039 -> V_1046 -> V_1047 , V_1042 ) ;
F_470 ( V_1042 ) ;
if ( V_1039 -> V_1048 )
F_427 ( & V_1039 -> V_1049 ) ;
F_81 ( V_1039 ) ;
}
static int F_471 ( struct V_1039 * V_1039 )
{
int V_21 ;
struct V_1040 * V_1040 ;
struct V_1041 * V_1042 ;
struct V_1050 * V_1051 ;
V_1040 = V_1039 -> V_1046 ;
V_1042 = V_1039 -> V_1042 ;
V_1051 = & V_1042 -> V_1051 ;
memset ( V_1051 , 0 , sizeof( * V_1051 ) ) ;
V_1051 -> V_89 = V_1040 -> V_89 ;
V_1051 -> V_517 = V_1052 ;
V_1051 -> V_1053 = V_1054 ;
V_1051 -> V_1055 = V_1054 ;
V_1042 -> V_1056 = V_1057 ;
V_1042 -> V_1058 = V_1057 ;
V_1042 -> V_1059 = V_1057 ;
V_1042 -> V_1060 = V_1057 ;
V_1042 -> V_1061 = V_1057 ;
V_21 = F_472 ( V_1039 -> V_1042 ) ;
if ( V_21 )
return V_21 ;
F_473 ( V_1040 -> V_1047 , V_1039 -> V_1042 ) ;
F_93 ( & V_1039 -> V_1049 ,
& V_1040 -> V_1062 ) ;
V_1039 -> V_1048 = true ;
return 0 ;
}
static int
F_474 ( struct V_1040 * V_1040 ,
struct V_254 * V_255 )
{
struct V_1050 * V_1051 ;
V_1051 = & V_255 -> V_1051 ;
V_1051 -> V_89 = V_1040 -> V_89 ;
V_1051 -> V_1053 = V_1054 ;
V_1051 -> V_1055 = V_1054 ;
return F_475 ( V_255 ) ;
}
static struct V_1040
* F_476 ( struct V_1063 * V_1063 ,
T_5 V_89 )
{
int V_21 ;
struct V_1040 * V_1040 ;
struct V_1064 * V_1047 ;
V_1040 = F_115 ( sizeof( * V_1040 ) , V_203 ) ;
if ( ! V_1040 )
return NULL ;
F_440 ( & V_1040 -> V_1062 ) ;
V_1040 -> V_1043 = V_1063 ;
V_1047 = F_477 ( V_1063 -> V_1044 ) ;
if ( ! V_1047 )
goto V_1065;
V_21 = F_478 ( V_1047 ) ;
if ( V_21 )
goto V_1066;
V_1040 -> V_1047 = V_1047 ;
V_1040 -> V_89 = V_89 ;
F_93 ( & V_1040 -> V_1067 ,
& V_1063 -> V_1068 ) ;
return V_1040 ;
V_1066:
F_479 ( V_1047 ) ;
V_1065:
F_81 ( V_1040 ) ;
return NULL ;
}
static void F_480 ( struct V_1040 * V_1040 )
{
struct V_1039 * V_1039 ;
struct V_1039 * V_1069 ;
F_481 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_468 ( V_1039 ) ;
F_482 ( V_1040 -> V_1047 ) ;
F_427 ( & V_1040 -> V_1067 ) ;
F_81 ( V_1040 ) ;
}
static struct V_1063 * F_483 ( struct V_42 * V_1044 )
{
struct V_1063 * V_1063 ;
V_1063 = F_115 ( sizeof( * V_1063 ) , V_203 ) ;
if ( V_1063 ) {
V_1063 -> V_1044 = V_1044 ;
F_440 ( & V_1063 -> V_1068 ) ;
}
return V_1063 ;
}
static void F_484 ( struct V_1063 * V_1063 )
{
struct V_1040 * V_1040 ;
struct V_1040 * V_1069 ;
if ( ! V_1063 )
return;
F_481 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_480 ( V_1040 ) ;
F_81 ( V_1063 ) ;
}
static struct V_73
* F_120 ( struct V_1 * V_22 ,
struct V_254 * V_255 )
{
int V_68 ;
struct V_73 * V_42 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_162 ; V_68 ++ ) {
V_42 = V_22 -> V_30 [ V_68 ] ;
if ( ! V_42 -> V_1064 )
continue;
if ( V_42 -> V_1064 -> V_255 == V_255 )
return V_42 ;
}
return NULL ;
}
static int F_234 ( struct V_1 * V_22 )
{
int V_21 ;
struct V_42 * V_1044 ;
struct V_1063 * V_1063 ;
struct V_1040 * V_1040 ;
struct V_1039 * V_1039 ;
V_1044 = & V_22 -> V_59 -> V_1070 ;
V_1063 = F_483 ( V_1044 ) ;
if ( ! V_1063 )
return - V_261 ;
V_1040 = F_476 ( V_1063 , V_22 -> V_89 ) ;
if ( ! V_1040 ) {
V_21 = - V_81 ;
goto V_1071;
}
V_1039 = F_466 ( V_1040 ) ;
if ( ! V_1039 ) {
V_21 = - V_81 ;
goto V_1066;
}
V_21 = F_471 ( V_1039 ) ;
if ( V_21 )
goto V_1072;
V_22 -> V_238 = V_1063 ;
return 0 ;
V_1072:
F_468 ( V_1039 ) ;
V_1066:
F_480 ( V_1040 ) ;
V_1071:
F_484 ( V_1063 ) ;
return V_21 ;
}
static void F_456 ( struct V_1 * V_22 )
{
F_484 ( V_22 -> V_238 ) ;
}
static int F_102 ( struct V_1063 * V_1063 ,
struct V_73 * V_42 )
{
int V_21 ;
struct V_1040 * V_1040 ;
struct V_254 * V_255 ;
V_1040 = F_476 ( V_1063 , V_42 -> V_89 ) ;
if ( ! V_1040 )
return - V_261 ;
V_255 = F_485 ( V_1040 -> V_1047 ) ;
if ( ! V_255 ) {
V_21 = - V_81 ;
goto V_1066;
}
V_1040 -> V_255 = V_255 ;
V_42 -> V_1064 = V_1040 ;
V_21 = F_474 ( V_1040 , V_255 ) ;
if ( V_21 )
goto V_1066;
return 0 ;
V_1066:
F_480 ( V_1040 ) ;
V_42 -> V_1064 = NULL ;
return V_21 ;
}
static void F_113 ( struct V_73 * V_42 )
{
if ( V_42 -> V_1064 ) {
F_480 ( V_42 -> V_1064 ) ;
V_42 -> V_1064 = NULL ;
}
}
static int
F_486 ( struct V_1041 * V_1042 )
{
return 0 ;
}
static int
F_487 ( struct V_254 * V_255 , T_5 * V_1073 )
{
* V_1073 = 0 ;
return 0 ;
}
static int
F_488 ( struct V_254 * V_255 )
{
return - V_1074 ;
}
static int
F_489 ( struct V_1041 * V_1042 , int V_1075 )
{
return 0 ;
}
static int
F_490 ( struct V_1041 * V_1042 , int V_1076 )
{
return 0 ;
}
static int
F_491 ( struct V_1041 * V_1042 )
{
return 0 ;
}
static void
F_492 ( struct V_1041 * V_1042 )
{
}
static int
F_493 ( struct V_1041 * V_1042 , struct V_1077 * V_1078 )
{
return - V_55 ;
}
static int
F_494 ( struct V_6 * V_47 , struct V_254 * V_255 ,
struct V_642 * V_1079 )
{
return - V_55 ;
}
static int T_18 F_495 ( void )
{
int V_21 ;
V_663 =
F_496 ( & V_1080 ) ;
if ( ! V_663 )
return - V_81 ;
V_21 = F_497 ( & V_1081 ) ;
if ( V_21 )
F_498 ( V_663 ) ;
return V_21 ;
}
static void T_19 F_499 ( void )
{
F_500 ( & V_1081 ) ;
F_498 ( V_663 ) ;
}
