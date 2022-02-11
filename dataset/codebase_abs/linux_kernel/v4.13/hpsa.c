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
return V_9 -> V_12 ;
}
static void F_6 ( const T_1 * V_13 , int V_14 ,
T_1 * V_15 , T_1 * V_16 , T_1 * V_17 )
{
struct V_18 V_19 ;
bool V_20 ;
* V_15 = - 1 ;
* V_16 = - 1 ;
* V_17 = - 1 ;
if ( V_14 < 1 )
return;
V_20 = F_7 ( V_13 , V_14 , & V_19 ) ;
if ( V_20 ) {
* V_15 = V_19 . V_15 ;
* V_16 = V_19 . V_16 ;
* V_17 = V_19 . V_17 ;
}
}
static int F_8 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
T_1 V_15 , V_16 , V_17 ;
int V_22 ;
if ( V_9 -> V_23 -> V_24 > sizeof( V_9 -> V_23 -> V_25 ) )
V_22 = sizeof( V_9 -> V_23 -> V_25 ) ;
else
V_22 = V_9 -> V_23 -> V_24 ;
F_6 ( V_9 -> V_23 -> V_25 , V_22 ,
& V_15 , & V_16 , & V_17 ) ;
if ( V_15 != V_26 || V_16 == 0xff )
return 0 ;
switch ( V_16 ) {
case V_27 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_1 ,
V_21 -> V_30 ) ;
break;
case V_31 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_2 , V_21 -> V_30 ) ;
break;
case V_32 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_3 , V_21 -> V_30 ) ;
break;
case V_33 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_4 ,
V_21 -> V_30 ) ;
break;
case V_34 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_5 ,
V_21 -> V_30 ) ;
break;
default:
F_9 ( & V_21 -> V_28 -> V_29 ,
L_6 ,
V_21 -> V_30 ) ;
break;
}
return 1 ;
}
static int F_10 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
if ( V_9 -> V_23 -> V_35 != V_36 ||
( V_9 -> V_23 -> V_37 != V_38 &&
V_9 -> V_23 -> V_37 != V_39 ) )
return 0 ;
F_9 ( & V_21 -> V_28 -> V_29 , V_40 L_7 ) ;
return 1 ;
}
static T_2 F_11 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
int V_45 ;
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
V_45 = F_13 ( V_21 ) ;
return sprintf ( V_44 , L_8 , V_45 ) ;
}
static T_2 F_14 ( struct V_41 * V_29 ,
struct V_42 * V_43 ,
const char * V_44 , T_3 V_47 )
{
int V_48 , V_49 ;
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
char V_50 [ 10 ] ;
if ( ! F_15 ( V_51 ) || ! F_15 ( V_52 ) )
return - V_53 ;
V_49 = V_47 > sizeof( V_50 ) - 1 ? sizeof( V_50 ) - 1 : V_47 ;
strncpy ( V_50 , V_44 , V_49 ) ;
V_50 [ V_49 ] = '\0' ;
if ( sscanf ( V_50 , L_9 , & V_48 ) != 1 )
return - V_54 ;
V_21 = F_3 ( V_46 ) ;
V_21 -> V_55 = ! ! V_48 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_10 ,
V_21 -> V_55 ? L_11 : L_12 ) ;
return V_47 ;
}
static T_2 F_16 ( struct V_41 * V_29 ,
struct V_42 * V_43 ,
const char * V_44 , T_3 V_47 )
{
int V_56 , V_49 ;
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
char V_50 [ 10 ] ;
if ( ! F_15 ( V_51 ) || ! F_15 ( V_52 ) )
return - V_53 ;
V_49 = V_47 > sizeof( V_50 ) - 1 ? sizeof( V_50 ) - 1 : V_47 ;
strncpy ( V_50 , V_44 , V_49 ) ;
V_50 [ V_49 ] = '\0' ;
if ( sscanf ( V_50 , L_9 , & V_56 ) != 1 )
return - V_54 ;
if ( V_56 < 0 )
V_56 = 0 ;
V_21 = F_3 ( V_46 ) ;
V_21 -> V_57 = V_56 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_13 ,
V_21 -> V_57 ) ;
return V_47 ;
}
static T_2 F_17 ( struct V_41 * V_29 ,
struct V_42 * V_43 ,
const char * V_44 , T_3 V_47 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
F_18 ( V_21 -> V_58 ) ;
return V_47 ;
}
static T_2 F_19 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
unsigned char * V_59 ;
V_21 = F_3 ( V_46 ) ;
if ( ! V_21 -> V_60 )
return 0 ;
V_59 = & V_21 -> V_60 [ 32 ] ;
return snprintf ( V_44 , 20 , L_14 ,
V_59 [ 0 ] , V_59 [ 1 ] , V_59 [ 2 ] , V_59 [ 3 ] ) ;
}
static T_2 F_20 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_6 * V_46 = F_12 ( V_29 ) ;
struct V_1 * V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 20 , L_15 ,
F_21 ( & V_21 -> V_61 ) ) ;
}
static T_2 F_22 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 20 , L_16 ,
V_21 -> V_62 & V_63 ?
L_17 : L_18 ) ;
}
static T_2 F_23 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 30 , L_19 ,
( V_21 -> V_55 == 1 ) ? L_11 : L_12 ) ;
}
static int F_24 ( T_4 V_64 [] , int V_65 , T_4 V_66 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
if ( V_64 [ V_67 ] == V_66 )
return 1 ;
return 0 ;
}
static int F_25 ( T_4 V_66 )
{
return ! F_24 ( V_68 ,
F_26 ( V_68 ) , V_66 ) ;
}
static int F_27 ( T_4 V_66 )
{
return ! F_24 ( V_69 ,
F_26 ( V_69 ) , V_66 ) ;
}
static int F_28 ( T_4 V_66 )
{
return F_25 ( V_66 ) ||
F_27 ( V_66 ) ;
}
static T_2 F_29 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 20 , L_15 , F_28 ( V_21 -> V_66 ) ) ;
}
static inline int F_30 ( unsigned char V_70 [] )
{
return ( V_70 [ 3 ] & 0xC0 ) == 0x40 ;
}
static inline bool F_31 ( struct V_71 * V_41 )
{
return ! V_41 -> V_72 ;
}
static T_2 F_32 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
T_2 V_73 = 0 ;
unsigned char V_74 ;
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return - V_79 ;
}
if ( ! F_31 ( V_75 ) ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
V_73 = snprintf ( V_44 , V_80 , L_20 ) ;
return V_73 ;
}
V_74 = V_75 -> V_81 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( V_74 > V_82 )
V_74 = V_82 ;
V_73 = snprintf ( V_44 , V_80 , L_21 , V_83 [ V_74 ] ) ;
return V_73 ;
}
static T_2 F_36 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
unsigned char V_84 [ 8 ] ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return - V_79 ;
}
memcpy ( V_84 , V_75 -> V_70 , sizeof( V_84 ) ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
return snprintf ( V_44 , 20 , L_22 , V_84 ) ;
}
static T_2 F_37 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
unsigned char V_85 [ 16 ] ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return - V_79 ;
}
memcpy ( V_85 , V_75 -> V_86 , sizeof( V_85 ) ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
return snprintf ( V_44 , 16 * 2 + 2 ,
L_23
L_24 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] ,
V_85 [ 4 ] , V_85 [ 5 ] , V_85 [ 6 ] , V_85 [ 7 ] ,
V_85 [ 8 ] , V_85 [ 9 ] , V_85 [ 10 ] , V_85 [ 11 ] ,
V_85 [ 12 ] , V_85 [ 13 ] , V_85 [ 14 ] , V_85 [ 15 ] ) ;
}
static T_2 F_38 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
T_5 V_87 ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 || F_31 ( V_75 ) || ! V_75 -> V_88 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return - V_79 ;
}
V_87 = V_75 -> V_87 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
return snprintf ( V_44 , V_80 , L_25 , V_87 ) ;
}
static T_2 F_39 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
int V_89 ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return - V_79 ;
}
V_89 = V_75 -> V_89 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
return snprintf ( V_44 , 20 , L_15 , V_89 ) ;
}
static T_2 F_40 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_2 * V_3 ;
struct V_71 * V_75 ;
unsigned long V_76 ;
int V_67 ;
int V_90 = 0 ;
T_1 V_91 ;
T_1 V_92 ;
T_1 V_93 = 0 ;
char * V_94 ;
unsigned char V_95 [ 2 ] ;
V_3 = F_33 ( V_29 ) ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_96 , V_76 ) ;
V_75 = V_3 -> V_78 ;
if ( ! V_75 ) {
F_35 ( & V_21 -> V_96 , V_76 ) ;
return - V_79 ;
}
V_92 = V_75 -> V_92 ;
for ( V_67 = 0 ; V_67 < V_97 ; V_67 ++ ) {
V_93 = 1 << V_67 ;
if ( V_67 == V_75 -> V_98 )
V_94 = L_26 ;
else if ( V_75 -> V_99 & V_93 )
V_94 = L_27 ;
else
continue;
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 ,
L_28 ,
V_21 -> V_58 -> V_100 ,
V_75 -> V_101 , V_75 -> V_102 , V_75 -> V_103 ,
F_42 ( V_75 -> V_104 ) ) ;
if ( V_75 -> V_104 == V_105 || F_31 ( V_75 ) ) {
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 ,
L_16 , V_94 ) ;
continue;
}
V_91 = V_75 -> V_91 [ V_67 ] ;
memcpy ( & V_95 , & V_75 -> V_95 [ V_67 ] ,
sizeof( V_95 ) ) ;
if ( V_95 [ 0 ] < '0' )
V_95 [ 0 ] = '0' ;
if ( V_95 [ 1 ] < '0' )
V_95 [ 1 ] = '0' ;
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 ,
L_29 ,
V_95 ) ;
if ( ( V_75 -> V_104 == V_106 || V_75 -> V_104 == V_107 ) &&
V_75 -> V_88 ) {
if ( V_91 == 0 || V_91 == 0xFF ) {
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 ,
L_30 ,
V_92 , V_94 ) ;
} else {
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 ,
L_31 ,
V_91 , V_92 , V_94 ) ;
}
} else if ( V_91 != 0 && V_91 != 0xFF ) {
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 , L_32 ,
V_91 , V_94 ) ;
} else
V_90 += F_41 ( V_44 + V_90 ,
V_80 - V_90 , L_16 , V_94 ) ;
}
F_35 ( & V_21 -> V_96 , V_76 ) ;
return V_90 ;
}
static T_2 F_43 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 20 , L_15 , V_21 -> V_108 ) ;
}
static inline T_4 F_44 ( struct V_1 * V_21 , T_1 V_109 )
{
T_4 V_64 ;
struct V_110 * V_111 = & V_21 -> V_112 [ V_109 ] ;
if ( V_21 -> V_62 & V_113 )
return V_21 -> V_114 . V_115 ( V_21 , V_109 ) ;
if ( F_45 ( ! ( V_21 -> V_62 & V_63 ) ) )
return V_21 -> V_114 . V_115 ( V_21 , V_109 ) ;
if ( ( V_111 -> V_116 [ V_111 -> V_117 ] & 1 ) == V_111 -> V_118 ) {
V_64 = V_111 -> V_116 [ V_111 -> V_117 ] ;
V_111 -> V_117 ++ ;
F_46 ( & V_21 -> V_61 ) ;
} else {
V_64 = V_119 ;
}
if ( V_111 -> V_117 == V_21 -> V_120 ) {
V_111 -> V_117 = 0 ;
V_111 -> V_118 ^= 1 ;
}
return V_64 ;
}
static void F_47 ( struct V_1 * V_21 , struct V_8 * V_9 ,
int V_112 )
{
if ( F_48 ( V_21 -> V_62 & V_63 ) ) {
V_9 -> V_121 |= 1 | ( V_21 -> V_122 [ V_9 -> V_123 . V_124 ] << 1 ) ;
if ( F_45 ( ! V_21 -> V_125 ) )
return;
if ( F_48 ( V_112 == V_126 ) )
V_9 -> V_123 . V_127 =
F_49 () % V_21 -> V_128 ;
else
V_9 -> V_123 . V_127 = V_112 % V_21 -> V_128 ;
}
}
static void F_50 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_129 * V_130 = & V_21 -> V_131 [ V_9 -> V_132 ] ;
if ( F_48 ( V_112 == V_126 ) )
V_130 -> V_127 = F_51 () % V_21 -> V_128 ;
else
V_130 -> V_127 = V_112 % V_21 -> V_128 ;
V_9 -> V_121 |= 1 | ( V_21 -> V_133 [ V_9 -> V_123 . V_124 ] << 1 ) |
V_134 ;
}
static void F_52 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_135 * V_130 = (struct V_135 * )
& V_21 -> V_136 [ V_9 -> V_132 ] ;
if ( F_48 ( V_112 == V_126 ) )
V_130 -> V_112 = F_51 () % V_21 -> V_128 ;
else
V_130 -> V_112 = V_112 % V_21 -> V_128 ;
V_9 -> V_121 |= V_21 -> V_137 [ 0 ] ;
}
static void F_53 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_112 )
{
struct V_138 * V_130 = & V_21 -> V_136 [ V_9 -> V_132 ] ;
if ( F_48 ( V_112 == V_126 ) )
V_130 -> V_112 = F_51 () % V_21 -> V_128 ;
else
V_130 -> V_112 = V_112 % V_21 -> V_128 ;
V_9 -> V_121 |= ( V_21 -> V_137 [ V_130 -> V_139 ] ) ;
}
static int F_54 ( T_1 * V_140 )
{
return V_140 [ 0 ] == V_141 && V_140 [ 6 ] == V_142 ;
}
static void F_55 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( ! F_54 ( V_9 -> V_143 . V_144 ) )
return;
F_56 ( & V_21 -> V_145 ) ;
V_21 -> V_146 = V_147 ;
}
static void F_57 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( F_54 ( V_9 -> V_143 . V_144 ) &&
F_58 ( & V_21 -> V_145 ) )
V_21 -> V_146 = V_148 ;
}
static void F_59 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_112 )
{
F_55 ( V_21 , V_9 ) ;
F_56 ( & V_21 -> V_61 ) ;
switch ( V_9 -> V_149 ) {
case V_150 :
F_50 ( V_21 , V_9 , V_112 ) ;
F_60 ( V_9 -> V_121 , V_21 -> V_151 + V_152 ) ;
break;
case V_153 :
F_53 ( V_21 , V_9 , V_112 ) ;
F_60 ( V_9 -> V_121 , V_21 -> V_151 + V_154 ) ;
break;
case V_155 :
F_52 ( V_21 , V_9 , V_112 ) ;
F_60 ( V_9 -> V_121 , V_21 -> V_151 + V_154 ) ;
break;
default:
F_47 ( V_21 , V_9 , V_112 ) ;
V_21 -> V_114 . V_156 ( V_21 , V_9 ) ;
}
}
static void F_61 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
if ( F_45 ( F_5 ( V_9 ) ) )
return F_62 ( V_9 ) ;
F_59 ( V_21 , V_9 , V_126 ) ;
}
static inline int F_63 ( unsigned char V_70 [] )
{
return memcmp ( V_70 , V_157 , 8 ) == 0 ;
}
static inline int F_64 ( struct V_1 * V_21 )
{
if ( ! V_21 -> V_60 )
return 0 ;
if ( ( V_21 -> V_60 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_21 ,
unsigned char V_70 [] , int V_101 , int * V_102 , int * V_103 )
{
int V_67 , V_158 = 0 ;
F_66 ( V_159 , V_160 ) ;
F_67 ( V_159 , V_160 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] -> V_101 == V_101 && V_21 -> V_29 [ V_67 ] -> V_102 != - 1 )
F_68 ( V_21 -> V_29 [ V_67 ] -> V_102 , V_159 ) ;
}
V_67 = F_69 ( V_159 , V_160 ) ;
if ( V_67 < V_160 ) {
* V_102 = V_67 ;
* V_103 = 0 ;
V_158 = 1 ;
}
return ! V_158 ;
}
static void F_70 ( const char * V_162 , struct V_1 * V_21 ,
struct V_71 * V_29 , char * V_163 )
{
#define F_71 25
char V_164 [ F_71 ] ;
if ( V_21 == NULL || V_21 -> V_28 == NULL || V_21 -> V_58 == NULL )
return;
switch ( V_29 -> V_104 ) {
case V_105 :
snprintf ( V_164 , F_71 , L_33 ) ;
break;
case V_165 :
snprintf ( V_164 , F_71 , L_34 ) ;
break;
case V_106 :
case V_107 :
if ( V_29 -> V_166 )
snprintf ( V_164 , F_71 , L_35 ) ;
else if ( ! F_30 ( V_29 -> V_70 ) )
snprintf ( V_164 , F_71 , L_36 ,
V_83 [ V_167 ] ) ;
else
snprintf ( V_164 , F_71 , L_37 ,
V_29 -> V_81 > V_82 ? L_38 :
V_83 [ V_29 -> V_81 ] ) ;
break;
case V_168 :
snprintf ( V_164 , F_71 , L_39 ) ;
break;
case V_169 :
snprintf ( V_164 , F_71 , L_40 ) ;
break;
case V_170 :
snprintf ( V_164 , F_71 , L_41 ) ;
break;
default:
snprintf ( V_164 , F_71 , L_42 ) ;
break;
}
F_72 ( V_162 , & V_21 -> V_28 -> V_29 ,
L_43 ,
V_21 -> V_58 -> V_100 , V_29 -> V_101 , V_29 -> V_102 , V_29 -> V_103 ,
V_163 ,
F_42 ( V_29 -> V_104 ) ,
V_29 -> V_171 ,
V_29 -> V_172 ,
V_164 ,
V_29 -> V_173 ? '+' : '-' ,
V_29 -> V_89 ? '+' : '-' ,
V_29 -> V_88 ) ;
}
static int F_73 ( struct V_1 * V_21 ,
struct V_71 * V_41 ,
struct V_71 * V_174 [] , int * V_175 )
{
int V_176 = V_21 -> V_161 ;
int V_67 ;
unsigned char V_177 [ 8 ] , V_178 [ 8 ] ;
struct V_71 * V_179 ;
if ( V_176 >= V_160 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_44
L_45 ) ;
return - 1 ;
}
if ( V_41 -> V_103 != - 1 )
goto V_180;
if ( V_41 -> V_70 [ 4 ] == 0 ) {
if ( F_65 ( V_21 , V_41 -> V_70 ,
V_41 -> V_101 , & V_41 -> V_102 , & V_41 -> V_103 ) != 0 )
return - 1 ;
goto V_180;
}
memcpy ( V_177 , V_41 -> V_70 , 8 ) ;
V_177 [ 4 ] = 0 ;
V_177 [ 5 ] = 0 ;
for ( V_67 = 0 ; V_67 < V_176 ; V_67 ++ ) {
V_179 = V_21 -> V_29 [ V_67 ] ;
memcpy ( V_178 , V_179 -> V_70 , 8 ) ;
V_178 [ 4 ] = 0 ;
V_178 [ 5 ] = 0 ;
if ( memcmp ( V_177 , V_178 , 8 ) == 0 ) {
V_41 -> V_101 = V_179 -> V_101 ;
V_41 -> V_102 = V_179 -> V_102 ;
V_41 -> V_103 = V_41 -> V_70 [ 4 ] ;
break;
}
}
if ( V_41 -> V_103 == - 1 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_46
L_47
L_48 ) ;
return - 1 ;
}
V_180:
V_21 -> V_29 [ V_176 ] = V_41 ;
V_21 -> V_161 ++ ;
V_174 [ * V_175 ] = V_41 ;
( * V_175 ) ++ ;
F_70 ( V_181 , V_21 , V_41 ,
V_41 -> V_88 ? L_49 : L_50 ) ;
V_41 -> V_182 = V_41 -> V_89 ;
V_41 -> V_89 = 0 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_21 ,
int V_183 , struct V_71 * V_184 )
{
int V_89 ;
F_76 ( V_183 < 0 || V_183 >= V_160 ) ;
V_21 -> V_29 [ V_183 ] -> V_81 = V_184 -> V_81 ;
if ( V_184 -> V_173 && V_184 -> V_89 ) {
V_21 -> V_29 [ V_183 ] -> V_185 = V_184 -> V_185 ;
V_21 -> V_29 [ V_183 ] -> V_186 = V_184 -> V_186 ;
}
if ( V_184 -> V_187 ) {
V_21 -> V_29 [ V_183 ] -> V_186 = V_184 -> V_186 ;
F_77 () ;
}
V_21 -> V_29 [ V_183 ] -> V_187 = V_184 -> V_187 ;
V_21 -> V_29 [ V_183 ] -> V_173 = V_184 -> V_173 ;
V_21 -> V_29 [ V_183 ] -> V_188 = V_184 -> V_188 ;
V_21 -> V_29 [ V_183 ] -> V_189 = V_184 -> V_189 ;
V_21 -> V_29 [ V_183 ] -> V_182 = V_184 -> V_89 ;
if ( ! V_184 -> V_89 )
V_21 -> V_29 [ V_183 ] -> V_89 = 0 ;
V_89 = V_21 -> V_29 [ V_183 ] -> V_89 ;
V_21 -> V_29 [ V_183 ] -> V_89 = V_21 -> V_29 [ V_183 ] -> V_182 ;
F_70 ( V_181 , V_21 , V_21 -> V_29 [ V_183 ] , L_51 ) ;
V_21 -> V_29 [ V_183 ] -> V_89 = V_89 ;
}
static void F_78 ( struct V_1 * V_21 ,
int V_183 , struct V_71 * V_184 ,
struct V_71 * V_174 [] , int * V_175 ,
struct V_71 * V_190 [] , int * V_191 )
{
F_76 ( V_183 < 0 || V_183 >= V_160 ) ;
V_190 [ * V_191 ] = V_21 -> V_29 [ V_183 ] ;
( * V_191 ) ++ ;
if ( V_184 -> V_102 == - 1 ) {
V_184 -> V_102 = V_21 -> V_29 [ V_183 ] -> V_102 ;
V_184 -> V_103 = V_21 -> V_29 [ V_183 ] -> V_103 ;
}
V_21 -> V_29 [ V_183 ] = V_184 ;
V_174 [ * V_175 ] = V_184 ;
( * V_175 ) ++ ;
F_70 ( V_181 , V_21 , V_184 , L_52 ) ;
V_184 -> V_182 = V_184 -> V_89 ;
V_184 -> V_89 = 0 ;
}
static void F_79 ( struct V_1 * V_21 , int V_183 ,
struct V_71 * V_190 [] , int * V_191 )
{
int V_67 ;
struct V_71 * V_179 ;
F_76 ( V_183 < 0 || V_183 >= V_160 ) ;
V_179 = V_21 -> V_29 [ V_183 ] ;
V_190 [ * V_191 ] = V_21 -> V_29 [ V_183 ] ;
( * V_191 ) ++ ;
for ( V_67 = V_183 ; V_67 < V_21 -> V_161 - 1 ; V_67 ++ )
V_21 -> V_29 [ V_67 ] = V_21 -> V_29 [ V_67 + 1 ] ;
V_21 -> V_161 -- ;
F_70 ( V_181 , V_21 , V_179 , L_53 ) ;
}
static void F_80 ( struct V_1 * V_21 ,
struct V_71 * V_174 )
{
unsigned long V_76 ;
int V_67 , V_192 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] == V_174 ) {
for ( V_192 = V_67 ; V_192 < V_21 -> V_161 - 1 ; V_192 ++ )
V_21 -> V_29 [ V_192 ] = V_21 -> V_29 [ V_192 + 1 ] ;
V_21 -> V_161 -- ;
break;
}
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_81 ( V_174 ) ;
}
static inline int F_82 ( struct V_71 * V_193 ,
struct V_71 * V_194 )
{
if ( memcmp ( V_193 -> V_70 , V_194 -> V_70 ,
sizeof( V_193 -> V_70 ) ) != 0 )
return 0 ;
if ( memcmp ( V_193 -> V_86 , V_194 -> V_86 ,
sizeof( V_193 -> V_86 ) ) != 0 )
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
static inline int F_83 ( struct V_71 * V_193 ,
struct V_71 * V_194 )
{
if ( V_193 -> V_81 != V_194 -> V_81 )
return 1 ;
if ( V_193 -> V_173 != V_194 -> V_173 )
return 1 ;
if ( V_193 -> V_89 != V_194 -> V_89 )
return 1 ;
if ( ! F_30 ( V_193 -> V_70 ) )
if ( V_193 -> V_189 != V_194 -> V_189 )
return 1 ;
return 0 ;
}
static int F_84 ( struct V_71 * V_195 ,
struct V_71 * V_196 [] , int V_197 ,
int * V_198 )
{
int V_67 ;
#define F_85 0
#define F_86 1
#define F_87 2
#define F_88 3
if ( V_195 == NULL )
return F_85 ;
for ( V_67 = 0 ; V_67 < V_197 ; V_67 ++ ) {
if ( V_196 [ V_67 ] == NULL )
continue;
if ( F_89 ( V_195 -> V_70 , V_196 [ V_67 ] -> V_70 ) ) {
* V_198 = V_67 ;
if ( F_82 ( V_195 , V_196 [ V_67 ] ) ) {
if ( F_83 ( V_195 , V_196 [ V_67 ] ) )
return F_88 ;
return F_87 ;
} else {
if ( V_195 -> V_199 )
return F_85 ;
return F_86 ;
}
}
}
* V_198 = - 1 ;
return F_85 ;
}
static void F_90 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
struct V_200 * V_41 ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_201 , V_76 ) ;
F_91 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_41 -> V_70 , V_70 ,
sizeof( V_41 -> V_70 ) ) == 0 ) {
F_35 ( & V_21 -> V_201 , V_76 ) ;
return;
}
}
F_35 ( & V_21 -> V_201 , V_76 ) ;
V_41 = F_92 ( sizeof( * V_41 ) , V_202 ) ;
if ( ! V_41 )
return;
memcpy ( V_41 -> V_70 , V_70 , sizeof( V_41 -> V_70 ) ) ;
F_34 ( & V_21 -> V_201 , V_76 ) ;
F_93 ( & V_41 -> V_203 , & V_21 -> V_204 ) ;
F_35 ( & V_21 -> V_201 , V_76 ) ;
}
static void F_94 ( struct V_1 * V_21 ,
struct V_71 * V_179 )
{
if ( V_179 -> V_199 == V_205 )
F_95 ( & V_21 -> V_28 -> V_29 ,
L_54 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
switch ( V_179 -> V_199 ) {
case V_206 :
break;
case V_207 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_55 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_208 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_56 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_209 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_57 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_210 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_58 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_211 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_59 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_212 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_60 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_213 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_61 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_214 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_62 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_215 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_63 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_216 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_64 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
case V_217 :
F_95 ( & V_21 -> V_28 -> V_29 ,
L_65 ,
V_21 -> V_58 -> V_100 ,
V_179 -> V_101 , V_179 -> V_102 , V_179 -> V_103 ) ;
break;
}
}
static void F_96 ( struct V_1 * V_21 ,
struct V_71 * V_29 [] , int V_161 ,
struct V_71 * V_218 )
{
struct V_219 * V_220 = & V_218 -> V_185 ;
struct V_221 * V_222 = & V_220 -> V_223 [ 0 ] ;
int V_67 , V_192 ;
int V_224 = F_97 ( V_220 -> V_225 ) +
F_97 ( V_220 -> V_226 ) ;
int V_227 = F_97 ( V_220 -> V_228 ) *
F_97 ( V_220 -> V_229 ) *
V_224 ;
int V_230 = F_97 ( V_220 -> V_229 ) *
V_224 ;
int V_231 ;
if ( V_227 > V_232 )
V_227 = V_232 ;
V_218 -> V_233 = V_227 ;
V_231 = 0 ;
for ( V_67 = 0 ; V_67 < V_227 ; V_67 ++ ) {
V_218 -> V_234 [ V_67 ] = NULL ;
if ( ! V_218 -> V_173 )
continue;
for ( V_192 = 0 ; V_192 < V_161 ; V_192 ++ ) {
if ( V_29 [ V_192 ] == NULL )
continue;
if ( V_29 [ V_192 ] -> V_104 != V_106 &&
V_29 [ V_192 ] -> V_104 != V_107 )
continue;
if ( F_31 ( V_29 [ V_192 ] ) )
continue;
if ( V_29 [ V_192 ] -> V_186 != V_222 [ V_67 ] . V_186 )
continue;
V_218 -> V_234 [ V_67 ] = V_29 [ V_192 ] ;
if ( V_67 < V_230 )
V_231 = F_98 ( V_21 -> V_235 , V_231 +
V_218 -> V_234 [ V_67 ] -> V_189 ) ;
break;
}
if ( ! V_218 -> V_234 [ V_67 ] ) {
V_218 -> V_89 = 0 ;
V_218 -> V_182 = 0 ;
V_218 -> V_189 = 8 ;
}
}
if ( V_227 )
V_218 -> V_189 = V_231 ;
else
V_218 -> V_189 = V_21 -> V_235 ;
}
static void F_99 ( struct V_1 * V_21 ,
struct V_71 * V_29 [] , int V_161 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_161 ; V_67 ++ ) {
if ( V_29 [ V_67 ] == NULL )
continue;
if ( V_29 [ V_67 ] -> V_104 != V_106 &&
V_29 [ V_67 ] -> V_104 != V_107 )
continue;
if ( ! F_31 ( V_29 [ V_67 ] ) )
continue;
if ( V_29 [ V_67 ] -> V_89 )
continue;
F_96 ( V_21 , V_29 , V_161 , V_29 [ V_67 ] ) ;
}
}
static int F_100 ( struct V_1 * V_21 , struct V_71 * V_41 )
{
int V_20 = 0 ;
if ( ! V_21 -> V_58 )
return 1 ;
if ( F_31 ( V_41 ) )
V_20 = F_101 ( V_21 -> V_58 , V_41 -> V_101 ,
V_41 -> V_102 , V_41 -> V_103 ) ;
else
V_20 = F_102 ( V_21 -> V_236 , V_41 ) ;
return V_20 ;
}
static int F_103 ( struct V_1 * V_21 ,
struct V_71 * V_29 )
{
int V_67 ;
int V_47 = 0 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_237 + V_67 ;
int V_238 = F_104 ( & V_9 -> V_238 ) ;
if ( V_238 > 1 && F_105 ( V_21 , V_9 , V_29 ,
V_29 -> V_70 ) ) {
unsigned long V_76 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! F_4 ( V_9 ) )
++ V_47 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
F_106 ( V_21 , V_9 ) ;
}
return V_47 ;
}
static void F_107 ( struct V_1 * V_21 ,
struct V_71 * V_41 )
{
int V_239 = 0 ;
int V_240 = 0 ;
while ( 1 ) {
V_239 = F_103 ( V_21 , V_41 ) ;
if ( V_239 == 0 )
break;
if ( ++ V_240 > 20 )
break;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_66 ,
V_241 , V_239 ) ;
F_108 ( 1000 ) ;
}
}
static void F_109 ( struct V_1 * V_21 ,
struct V_71 * V_41 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_21 -> V_58 )
return;
if ( F_31 ( V_41 ) ) {
V_3 = F_110 ( V_21 -> V_58 , V_41 -> V_101 ,
V_41 -> V_102 , V_41 -> V_103 ) ;
if ( V_3 ) {
F_111 ( V_3 ) ;
F_112 ( V_3 ) ;
} else {
F_70 ( V_242 , V_21 , V_41 ,
L_67 ) ;
}
} else {
V_41 -> V_190 = 1 ;
F_107 ( V_21 , V_41 ) ;
F_113 ( V_41 ) ;
}
}
static void F_114 ( struct V_1 * V_21 ,
struct V_71 * V_179 [] , int V_243 )
{
int V_67 , V_183 , V_244 , V_245 = 0 ;
struct V_71 * V_246 ;
unsigned long V_76 ;
struct V_71 * * V_174 , * * V_190 ;
int V_175 , V_191 ;
F_34 ( & V_21 -> V_247 , V_76 ) ;
if ( V_21 -> V_248 ) {
V_21 -> V_249 = 1 ;
F_35 ( & V_21 -> V_247 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_247 , V_76 ) ;
V_174 = F_115 ( sizeof( * V_174 ) * V_160 , V_202 ) ;
V_190 = F_115 ( sizeof( * V_190 ) * V_160 , V_202 ) ;
if ( ! V_174 || ! V_190 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_68
L_69 ) ;
goto V_250;
}
F_34 ( & V_21 -> V_96 , V_76 ) ;
V_67 = 0 ;
V_191 = 0 ;
V_175 = 0 ;
while ( V_67 < V_21 -> V_161 ) {
V_246 = V_21 -> V_29 [ V_67 ] ;
V_244 = F_84 ( V_246 , V_179 , V_243 , & V_183 ) ;
if ( V_244 == F_85 ) {
V_245 ++ ;
F_79 ( V_21 , V_67 , V_190 , & V_191 ) ;
continue;
} else if ( V_244 == F_86 ) {
V_245 ++ ;
F_78 ( V_21 , V_67 , V_179 [ V_183 ] ,
V_174 , & V_175 , V_190 , & V_191 ) ;
V_179 [ V_183 ] = NULL ;
} else if ( V_244 == F_88 ) {
F_75 ( V_21 , V_67 , V_179 [ V_183 ] ) ;
}
V_67 ++ ;
}
for ( V_67 = 0 ; V_67 < V_243 ; V_67 ++ ) {
if ( ! V_179 [ V_67 ] )
continue;
if ( V_179 [ V_67 ] -> V_199 ) {
F_94 ( V_21 , V_179 [ V_67 ] ) ;
F_70 ( V_181 , V_21 , V_179 [ V_67 ] , L_70 ) ;
continue;
}
V_244 = F_84 ( V_179 [ V_67 ] , V_21 -> V_29 ,
V_21 -> V_161 , & V_183 ) ;
if ( V_244 == F_85 ) {
V_245 ++ ;
if ( F_73 ( V_21 , V_179 [ V_67 ] , V_174 , & V_175 ) != 0 )
break;
V_179 [ V_67 ] = NULL ;
} else if ( V_244 == F_86 ) {
V_245 ++ ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_71 ) ;
}
}
F_99 ( V_21 , V_21 -> V_29 , V_21 -> V_161 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] == NULL )
continue;
V_21 -> V_29 [ V_67 ] -> V_89 = V_21 -> V_29 [ V_67 ] -> V_182 ;
}
F_35 ( & V_21 -> V_96 , V_76 ) ;
for ( V_67 = 0 ; V_67 < V_243 ; V_67 ++ ) {
if ( ! V_179 [ V_67 ] )
continue;
if ( V_179 [ V_67 ] -> V_199 )
F_90 ( V_21 , V_179 [ V_67 ] -> V_70 ) ;
}
if ( ! V_245 )
goto V_250;
for ( V_67 = 0 ; V_67 < V_191 ; V_67 ++ ) {
if ( V_190 [ V_67 ] == NULL )
continue;
if ( V_190 [ V_67 ] -> V_88 )
F_109 ( V_21 , V_190 [ V_67 ] ) ;
F_81 ( V_190 [ V_67 ] ) ;
V_190 [ V_67 ] = NULL ;
}
for ( V_67 = 0 ; V_67 < V_175 ; V_67 ++ ) {
int V_20 = 0 ;
if ( V_174 [ V_67 ] == NULL )
continue;
if ( ! ( V_174 [ V_67 ] -> V_88 ) )
continue;
V_20 = F_100 ( V_21 , V_174 [ V_67 ] ) ;
if ( ! V_20 )
continue;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_72 , V_20 ) ;
F_80 ( V_21 , V_174 [ V_67 ] ) ;
V_21 -> V_249 = 1 ;
}
V_250:
F_81 ( V_174 ) ;
F_81 ( V_190 ) ;
}
static struct V_71 * F_116 ( struct V_1 * V_21 ,
int V_101 , int V_102 , int V_103 )
{
int V_67 ;
struct V_71 * V_179 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
V_179 = V_21 -> V_29 [ V_67 ] ;
if ( V_179 -> V_101 == V_101 && V_179 -> V_102 == V_102 && V_179 -> V_103 == V_103 )
return V_179 ;
}
return NULL ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_71 * V_179 = NULL ;
unsigned long V_76 ;
struct V_1 * V_21 ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_96 , V_76 ) ;
if ( F_118 ( V_3 ) == V_251 ) {
struct V_252 * V_253 ;
struct V_254 * V_255 ;
V_253 = V_252 ( V_3 ) ;
V_255 = F_119 ( V_253 ) ;
V_179 = F_120 ( V_21 , V_255 ) ;
if ( V_179 ) {
V_179 -> V_102 = F_121 ( V_3 ) ;
V_179 -> V_103 = V_3 -> V_103 ;
}
}
if ( ! V_179 )
V_179 = F_116 ( V_21 , F_118 ( V_3 ) ,
F_121 ( V_3 ) , V_3 -> V_103 ) ;
if ( V_179 && V_179 -> V_88 ) {
F_122 ( & V_179 -> V_256 , 0 ) ;
V_3 -> V_78 = V_179 ;
} else
V_3 -> V_78 = NULL ;
F_35 ( & V_21 -> V_96 , V_76 ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 )
{
struct V_71 * V_179 ;
int V_189 ;
V_179 = V_3 -> V_78 ;
V_3 -> V_257 = ! V_179 || ! V_179 -> V_88 ;
if ( V_179 ) {
if ( V_179 -> V_166 )
V_189 = V_258 ;
else
V_189 = V_179 -> V_189 != 0 ?
V_179 -> V_189 : V_3 -> V_5 -> V_259 ;
} else
V_189 = V_3 -> V_5 -> V_259 ;
F_124 ( V_3 , V_189 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 )
{
}
static void F_126 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_260 )
return;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
F_81 ( V_21 -> V_260 [ V_67 ] ) ;
V_21 -> V_260 [ V_67 ] = NULL ;
}
F_81 ( V_21 -> V_260 ) ;
V_21 -> V_260 = NULL ;
}
static int F_127 ( struct V_1 * V_21 )
{
int V_67 ;
if ( V_21 -> V_261 <= 0 )
return 0 ;
V_21 -> V_260 =
F_115 ( sizeof( * V_21 -> V_260 ) * V_21 -> V_235 ,
V_202 ) ;
if ( ! V_21 -> V_260 )
return - V_262 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
V_21 -> V_260 [ V_67 ] =
F_92 ( sizeof( * V_21 -> V_260 [ V_67 ] ) *
V_21 -> V_263 , V_202 ) ;
if ( ! V_21 -> V_260 [ V_67 ] )
goto V_264;
}
return 0 ;
V_264:
F_126 ( V_21 ) ;
return - V_262 ;
}
static void F_128 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_265 )
return;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
F_81 ( V_21 -> V_265 [ V_67 ] ) ;
V_21 -> V_265 [ V_67 ] = NULL ;
}
F_81 ( V_21 -> V_265 ) ;
V_21 -> V_265 = NULL ;
}
static int F_129 ( struct V_1 * V_21 )
{
int V_67 ;
if ( V_21 -> V_261 <= 0 )
return 0 ;
V_21 -> V_265 = F_115 ( sizeof( * V_21 -> V_265 ) * V_21 -> V_235 ,
V_202 ) ;
if ( ! V_21 -> V_265 )
return - V_262 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
V_21 -> V_265 [ V_67 ] = F_92 ( sizeof( * V_21 -> V_265 [ V_67 ] ) *
V_21 -> V_261 , V_202 ) ;
if ( ! V_21 -> V_265 [ V_67 ] )
goto V_264;
}
return 0 ;
V_264:
F_128 ( V_21 ) ;
return - V_262 ;
}
static int F_130 ( struct V_1 * V_21 ,
struct V_138 * V_130 , struct V_8 * V_9 )
{
struct V_266 * V_267 ;
T_5 V_268 ;
T_4 V_269 ;
V_267 = V_21 -> V_260 [ V_9 -> V_132 ] ;
V_269 = F_131 ( V_130 -> V_270 [ 0 ] . V_271 ) ;
V_268 = F_132 ( V_21 -> V_28 , V_267 , V_269 ,
V_272 ) ;
if ( F_133 ( & V_21 -> V_28 -> V_29 , V_268 ) ) {
V_130 -> V_270 -> V_273 = 0 ;
return - 1 ;
}
V_130 -> V_270 -> V_273 = F_134 ( V_268 ) ;
return 0 ;
}
static void F_135 ( struct V_1 * V_21 ,
struct V_138 * V_130 )
{
struct V_266 * V_274 ;
T_5 V_268 ;
T_4 V_269 ;
V_274 = V_130 -> V_270 ;
V_268 = F_136 ( V_274 -> V_273 ) ;
V_269 = F_131 ( V_130 -> V_270 [ 0 ] . V_271 ) ;
F_137 ( V_21 -> V_28 , V_268 , V_269 , V_272 ) ;
}
static int F_138 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_275 * V_274 , * V_267 ;
T_5 V_268 ;
T_4 V_276 ;
V_274 = & V_9 -> V_277 [ V_21 -> V_278 - 1 ] ;
V_267 = V_21 -> V_265 [ V_9 -> V_132 ] ;
V_274 -> V_279 = F_139 ( V_280 ) ;
V_276 = sizeof( * V_274 ) *
( F_97 ( V_9 -> V_123 . V_281 ) - V_21 -> V_278 ) ;
V_274 -> V_282 = F_139 ( V_276 ) ;
V_268 = F_132 ( V_21 -> V_28 , V_267 , V_276 ,
V_272 ) ;
if ( F_133 ( & V_21 -> V_28 -> V_29 , V_268 ) ) {
V_274 -> V_283 = F_134 ( 0 ) ;
return - 1 ;
}
V_274 -> V_283 = F_134 ( V_268 ) ;
return 0 ;
}
static void F_140 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_275 * V_274 ;
if ( F_97 ( V_9 -> V_123 . V_281 ) <= V_21 -> V_278 )
return;
V_274 = & V_9 -> V_277 [ V_21 -> V_278 - 1 ] ;
F_137 ( V_21 -> V_28 , F_136 ( V_274 -> V_283 ) ,
F_131 ( V_274 -> V_282 ) , V_272 ) ;
}
static int F_141 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
struct V_284 * V_285 ,
struct V_138 * V_286 ,
struct V_71 * V_29 )
{
int V_287 ;
int V_288 = 0 ;
T_4 V_289 = 0 ;
switch ( V_286 -> V_290 . V_291 ) {
case V_292 :
switch ( V_286 -> V_290 . V_48 ) {
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
V_287 = V_286 -> V_290 . V_14 ;
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
switch ( V_286 -> V_290 . V_48 ) {
case V_307 :
case V_308 :
case V_309 :
V_288 = 1 ;
break;
case V_310 :
V_285 -> V_295 = ( V_311 << 16 ) ;
V_285 -> V_295 |= ( V_312 << 8 ) ;
V_289 = F_142 (
& V_286 -> V_290 . V_313 [ 0 ] ) ;
F_143 ( V_285 , V_289 ) ;
break;
case V_314 :
case V_315 :
case V_316 :
if ( V_29 -> V_72 && V_29 -> V_88 ) {
V_285 -> V_295 = V_317 << 16 ;
V_29 -> V_190 = 1 ;
V_21 -> V_249 = 1 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_73 , V_241 ) ;
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
static void F_144 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
bool V_322 = false ;
V_9 -> V_10 = V_11 ;
F_145 () ;
if ( V_9 -> V_12 ) {
unsigned long V_76 ;
struct V_71 * V_29 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_29 = V_9 -> V_12 ;
if ( V_29 && F_58 ( & V_29 -> V_323 ) )
V_322 = true ;
V_9 -> V_12 = NULL ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
if ( V_322 )
F_146 ( & V_21 -> V_324 ) ;
}
static void F_147 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
F_144 ( V_21 , V_9 ) ;
F_148 ( V_21 , V_9 ) ;
}
static void F_149 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_284 * V_285 )
{
F_147 ( V_21 , V_9 ) ;
if ( V_285 && V_285 -> V_325 )
V_285 -> V_325 ( V_285 ) ;
}
static void F_150 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
F_151 ( & V_9 -> V_326 , V_327 ) ;
F_152 ( F_49 () , V_21 -> V_328 , & V_9 -> V_326 ) ;
}
static void F_153 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
struct V_71 * V_29 )
{
struct V_138 * V_286 = & V_21 -> V_136 [ V_9 -> V_132 ] ;
if ( F_48 ( V_286 -> V_290 . V_291 == 0 &&
V_286 -> V_290 . V_48 == 0 ) )
return F_149 ( V_21 , V_9 , V_285 ) ;
if ( F_31 ( V_29 ) &&
V_286 -> V_290 . V_291 ==
V_306 ) {
if ( V_286 -> V_290 . V_48 ==
V_316 ) {
V_29 -> V_89 = 0 ;
V_29 -> V_182 = 0 ;
}
return F_150 ( V_21 , V_9 ) ;
}
if ( F_141 ( V_21 , V_9 , V_285 , V_286 , V_29 ) )
return F_150 ( V_21 , V_9 ) ;
return F_149 ( V_21 , V_9 , V_285 ) ;
}
static int F_154 ( struct V_1 * V_21 ,
struct V_8 * V_130 )
{
T_1 V_329 = V_130 -> V_23 -> V_37 ;
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
F_9 ( & V_21 -> V_28 -> V_29 , L_74 ,
V_329 ) ;
break;
}
return - V_329 ;
}
static void F_155 ( struct V_8 * V_130 )
{
struct V_284 * V_285 ;
struct V_1 * V_21 ;
struct V_337 * V_338 ;
struct V_71 * V_29 ;
struct V_138 * V_286 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
unsigned long V_339 ;
V_338 = V_130 -> V_23 ;
V_285 = V_130 -> V_10 ;
V_21 = V_130 -> V_21 ;
if ( ! V_285 -> V_41 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_149 ( V_21 , V_130 , V_285 ) ;
}
V_29 = V_285 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_149 ( V_21 , V_130 , V_285 ) ;
}
V_286 = & V_21 -> V_136 [ V_130 -> V_132 ] ;
F_156 ( V_285 ) ;
if ( ( V_130 -> V_149 == V_340 ) &&
( F_97 ( V_130 -> V_123 . V_281 ) > V_21 -> V_278 ) )
F_140 ( V_21 , V_130 ) ;
if ( ( V_130 -> V_149 == V_153 ) &&
( V_286 -> V_270 [ 0 ] . V_341 == V_342 ) )
F_135 ( V_21 , V_286 ) ;
V_285 -> V_295 = ( V_311 << 16 ) ;
V_285 -> V_295 |= ( V_312 << 8 ) ;
if ( V_130 -> V_149 == V_153 || V_130 -> V_149 == V_150 ) {
if ( V_29 -> V_72 && V_29 -> V_88 &&
V_29 -> V_190 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_149 ( V_21 , V_130 , V_285 ) ;
}
if ( F_48 ( V_130 -> V_234 != NULL ) )
F_46 ( & V_130 -> V_234 -> V_256 ) ;
}
if ( F_45 ( V_338 -> V_35 == V_343 ) ) {
V_285 -> V_295 = V_317 << 16 ;
return F_149 ( V_21 , V_130 , V_285 ) ;
}
if ( ( F_45 ( F_5 ( V_130 ) ) ) )
if ( V_130 -> V_12 )
return F_149 ( V_21 , V_130 , V_285 ) ;
if ( V_130 -> V_149 == V_153 )
return F_153 ( V_21 , V_130 , V_285 , V_29 ) ;
F_143 ( V_285 , V_338 -> V_344 ) ;
if ( V_338 -> V_35 == 0 )
return F_149 ( V_21 , V_130 , V_285 ) ;
if ( V_130 -> V_149 == V_150 ) {
struct V_129 * V_9 = & V_21 -> V_131 [ V_130 -> V_132 ] ;
V_130 -> V_123 . V_124 = F_157 ( V_285 ) ;
V_130 -> V_123 . V_281 = F_158 ( V_130 -> V_123 . V_124 ) ;
V_130 -> V_143 . V_345 = F_97 ( V_9 -> V_346 ) &
V_347 ;
V_130 -> V_123 . V_348 = V_9 -> V_348 ;
memcpy ( V_130 -> V_123 . V_349 . V_350 , V_9 -> V_351 , 8 ) ;
memcpy ( V_130 -> V_143 . V_144 , V_9 -> V_144 , V_130 -> V_143 . V_345 ) ;
if ( F_31 ( V_29 ) ) {
if ( V_338 -> V_35 == V_352 )
V_29 -> V_89 = 0 ;
return F_150 ( V_21 , V_130 ) ;
}
}
switch ( V_338 -> V_35 ) {
case V_36 :
V_285 -> V_295 |= V_338 -> V_37 ;
if ( V_300 < sizeof( V_338 -> V_25 ) )
V_339 = V_300 ;
else
V_339 = sizeof( V_338 -> V_25 ) ;
if ( V_338 -> V_24 < V_339 )
V_339 = V_338 -> V_24 ;
memcpy ( V_285 -> V_299 , V_338 -> V_25 , V_339 ) ;
if ( V_338 -> V_37 )
F_6 ( V_338 -> V_25 , V_339 ,
& V_15 , & V_16 , & V_17 ) ;
if ( V_338 -> V_37 == V_296 ) {
if ( V_15 == V_353 ) {
V_285 -> V_295 |= V_354 << 16 ;
break;
}
break;
}
if ( V_338 -> V_37 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_75
L_76
L_77 ,
V_130 , V_338 -> V_37 ,
V_15 , V_16 , V_17 ,
V_285 -> V_295 ) ;
} else {
F_9 ( & V_21 -> V_28 -> V_29 , L_78
L_79 , V_130 ) ,
V_285 -> V_295 = V_317 << 16 ;
}
break;
case V_355 :
break;
case V_356 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_80 , V_130 -> V_143 . V_144 ) ;
break;
case V_357 : {
V_285 -> V_295 = V_317 << 16 ;
}
break;
case V_358 :
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_81 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_360 :
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_82 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_361 :
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_83 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_362 :
V_285 -> V_295 = V_363 << 16 ;
break;
case V_364 :
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_84 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_365 :
V_285 -> V_295 = V_354 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_85 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_366 :
V_285 -> V_295 = V_367 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_86 ,
V_130 -> V_143 . V_144 ) ;
break;
case V_368 :
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_87 ) ;
break;
case V_369 :
if ( F_154 ( V_21 , V_130 ) )
V_285 -> V_295 = V_359 << 16 ;
break;
case V_352 :
V_285 -> V_295 = V_354 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_88 , V_130 ) ;
break;
default:
V_285 -> V_295 = V_359 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_89 ,
V_130 , V_338 -> V_35 ) ;
}
return F_149 ( V_21 , V_130 , V_285 ) ;
}
static void F_159 ( struct V_370 * V_28 ,
struct V_8 * V_9 , int V_371 , int V_372 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_371 ; V_67 ++ )
F_137 ( V_28 , ( V_373 ) F_136 ( V_9 -> V_277 [ V_67 ] . V_283 ) ,
F_131 ( V_9 -> V_277 [ V_67 ] . V_282 ) ,
V_372 ) ;
}
static int F_160 ( struct V_370 * V_28 ,
struct V_8 * V_130 ,
unsigned char * V_44 ,
T_3 V_374 ,
int V_372 )
{
T_5 V_375 ;
if ( V_374 == 0 || V_372 == V_376 ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_281 = F_158 ( 0 ) ;
return 0 ;
}
V_375 = F_132 ( V_28 , V_44 , V_374 , V_372 ) ;
if ( F_133 ( & V_28 -> V_29 , V_375 ) ) {
V_130 -> V_123 . V_124 = 0 ;
V_130 -> V_123 . V_281 = F_158 ( 0 ) ;
return - 1 ;
}
V_130 -> V_277 [ 0 ] . V_283 = F_134 ( V_375 ) ;
V_130 -> V_277 [ 0 ] . V_282 = F_139 ( V_374 ) ;
V_130 -> V_277 [ 0 ] . V_279 = F_139 ( V_377 ) ;
V_130 -> V_123 . V_124 = 1 ;
V_130 -> V_123 . V_281 = F_158 ( 1 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_112 , unsigned long V_378 )
{
F_162 ( V_379 ) ;
V_9 -> V_380 = & V_379 ;
F_59 ( V_21 , V_9 , V_112 ) ;
if ( V_378 == V_381 ) {
F_163 ( & V_379 ) ;
return V_382 ;
}
if ( ! F_164 ( & V_379 ,
F_165 ( V_378 ) ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_90 ) ;
return - V_383 ;
}
return V_382 ;
}
static int F_166 ( struct V_1 * V_21 , struct V_8 * V_9 ,
int V_112 , unsigned long V_378 )
{
if ( F_45 ( F_13 ( V_21 ) ) ) {
V_9 -> V_23 -> V_35 = V_343 ;
return V_382 ;
}
return F_161 ( V_21 , V_9 , V_112 , V_378 ) ;
}
static T_4 F_13 ( struct V_1 * V_21 )
{
int V_384 ;
T_4 V_20 , * F_13 ;
V_384 = F_167 () ;
F_13 = F_168 ( V_21 -> F_13 , V_384 ) ;
V_20 = * F_13 ;
F_169 () ;
return V_20 ;
}
static int F_170 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_372 , unsigned long V_378 )
{
int V_385 = 10 , V_386 = 0 ;
int V_20 ;
do {
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_20 = F_166 ( V_21 , V_9 , V_126 ,
V_378 ) ;
if ( V_20 )
break;
V_386 ++ ;
if ( V_386 > 3 ) {
F_108 ( V_385 ) ;
if ( V_385 < 1000 )
V_385 *= 2 ;
}
} while ( ( F_8 ( V_21 , V_9 ) ||
F_10 ( V_21 , V_9 ) ) &&
V_386 <= V_387 );
F_159 ( V_21 -> V_28 , V_9 , 1 , V_372 ) ;
if ( V_386 > V_387 )
V_20 = - V_388 ;
return V_20 ;
}
static void F_171 ( struct V_1 * V_21 , char * V_389 ,
struct V_8 * V_9 )
{
const T_1 * V_140 = V_9 -> V_143 . V_144 ;
const T_1 * V_103 = V_9 -> V_123 . V_349 . V_350 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_91 ,
V_389 , V_103 , V_140 ) ;
}
static void F_172 ( struct V_1 * V_21 ,
struct V_8 * V_130 )
{
const struct V_337 * V_338 = V_130 -> V_23 ;
struct V_41 * V_390 = & V_130 -> V_21 -> V_28 -> V_29 ;
T_1 V_15 , V_16 , V_17 ;
int V_22 ;
switch ( V_338 -> V_35 ) {
case V_36 :
if ( V_338 -> V_24 > sizeof( V_338 -> V_25 ) )
V_22 = sizeof( V_338 -> V_25 ) ;
else
V_22 = V_338 -> V_24 ;
F_6 ( V_338 -> V_25 , V_22 ,
& V_15 , & V_16 , & V_17 ) ;
F_171 ( V_21 , L_92 , V_130 ) ;
if ( V_338 -> V_37 == V_296 )
F_9 ( V_390 , L_93 ,
V_15 , V_16 , V_17 ) ;
else
F_9 ( V_390 , L_94 , V_338 -> V_37 ) ;
if ( V_338 -> V_37 == 0 )
F_9 ( V_390 , L_95
L_96
L_97
L_98 ) ;
break;
case V_355 :
break;
case V_356 :
F_171 ( V_21 , L_99 , V_130 ) ;
break;
case V_357 : {
F_171 ( V_21 , L_100 , V_130 ) ;
F_9 ( V_390 , L_101 ) ;
}
break;
case V_358 :
F_171 ( V_21 , L_102 , V_130 ) ;
break;
case V_360 :
F_171 ( V_21 , L_103 , V_130 ) ;
break;
case V_361 :
F_171 ( V_21 , L_104 , V_130 ) ;
break;
case V_362 :
F_171 ( V_21 , L_105 , V_130 ) ;
break;
case V_364 :
F_171 ( V_21 , L_106 , V_130 ) ;
break;
case V_365 :
F_171 ( V_21 , L_107 , V_130 ) ;
break;
case V_366 :
F_171 ( V_21 , L_108 , V_130 ) ;
break;
case V_368 :
F_171 ( V_21 , L_109 , V_130 ) ;
break;
case V_343 :
F_171 ( V_21 , L_110 , V_130 ) ;
break;
default:
F_171 ( V_21 , L_111 , V_130 ) ;
F_9 ( V_390 , L_112 ,
V_338 -> V_35 ) ;
}
}
static int F_173 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_6 V_391 , unsigned char * V_44 ,
unsigned char V_392 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
if ( F_175 ( V_9 , V_393 , V_21 , V_44 , V_392 ,
V_391 , V_70 , V_394 ) ) {
V_20 = - 1 ;
goto V_395;
}
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_176 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_1 V_398 , int V_112 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
( void ) F_175 ( V_9 , V_398 , V_21 , NULL , 0 , 0 ,
V_70 , V_399 ) ;
V_20 = F_166 ( V_21 , V_9 , V_112 , V_381 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_113 ) ;
goto V_395;
}
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static bool F_105 ( struct V_1 * V_21 , struct V_8 * V_9 ,
struct V_71 * V_29 ,
unsigned char * V_70 )
{
int V_67 ;
bool V_400 = false ;
struct V_138 * V_286 = & V_21 -> V_136 [ V_9 -> V_132 ] ;
struct V_135 * V_401 = (struct V_135 * ) V_286 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_149 ) {
case V_340 :
case V_402 :
V_400 = ! memcmp ( V_70 , & V_9 -> V_123 . V_349 . V_350 ,
sizeof( V_9 -> V_123 . V_349 . V_350 ) ) ;
break;
case V_150 :
case V_153 :
if ( V_9 -> V_234 == V_29 ) {
V_400 = true ;
} else {
for ( V_67 = 0 ; V_67 < V_29 -> V_233 && ! V_400 ; V_67 ++ ) {
V_400 = V_29 -> V_234 [ V_67 ] == V_9 -> V_234 ;
}
}
break;
case V_155 :
for ( V_67 = 0 ; V_67 < V_29 -> V_233 && ! V_400 ; V_67 ++ ) {
V_400 = V_29 -> V_234 [ V_67 ] -> V_186 ==
F_131 ( V_401 -> V_403 ) ;
}
break;
case 0 :
V_400 = false ;
break;
default:
F_74 ( & V_21 -> V_28 -> V_29 , L_114 ,
V_9 -> V_149 ) ;
F_177 () ;
}
return V_400 ;
}
static int F_178 ( struct V_1 * V_21 , struct V_71 * V_29 ,
unsigned char * V_70 , T_1 V_398 , int V_112 )
{
int V_67 ;
int V_20 = 0 ;
if ( F_179 ( & V_21 -> V_404 ) == - V_405 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_115 ) ;
return - V_405 ;
}
F_76 ( F_21 ( & V_29 -> V_323 ) != 0 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_237 + V_67 ;
int V_238 = F_104 ( & V_9 -> V_238 ) ;
if ( V_238 > 1 && F_105 ( V_21 , V_9 , V_29 , V_70 ) ) {
unsigned long V_76 ;
V_9 -> V_12 = V_29 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! F_4 ( V_9 ) )
F_56 ( & V_29 -> V_323 ) ;
else
V_9 -> V_12 = NULL ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
F_106 ( V_21 , V_9 ) ;
}
V_20 = F_176 ( V_21 , V_70 , V_398 , V_112 ) ;
if ( ! V_20 )
F_180 ( V_21 -> V_324 ,
F_21 ( & V_29 -> V_323 ) == 0 ||
F_13 ( V_21 ) ) ;
if ( F_45 ( F_13 ( V_21 ) ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_116 ) ;
V_20 = - V_79 ;
}
if ( F_45 ( V_20 ) )
F_122 ( & V_29 -> V_323 , 0 ) ;
else
V_20 = F_181 ( V_21 , V_70 , 0 ) ;
F_182 ( & V_21 -> V_404 ) ;
return V_20 ;
}
static void F_183 ( struct V_1 * V_21 ,
unsigned char * V_70 , unsigned char * V_81 )
{
int V_20 ;
unsigned char * V_44 ;
* V_81 = V_82 ;
V_44 = F_115 ( 64 , V_202 ) ;
if ( ! V_44 )
return;
if ( ! F_184 ( V_21 , V_70 ,
V_406 ) )
goto exit;
V_20 = F_173 ( V_21 , V_70 , V_407 |
V_406 , V_44 , 64 ) ;
if ( V_20 == 0 )
* V_81 = V_44 [ 8 ] ;
if ( * V_81 > V_82 )
* V_81 = V_82 ;
exit:
F_81 ( V_44 ) ;
return;
}
static void F_185 ( struct V_1 * V_21 , int V_20 ,
struct V_219 * V_408 )
{
struct V_221 * V_222 = & V_408 -> V_223 [ 0 ] ;
int V_220 , V_409 , V_410 ;
T_6 V_411 , V_228 , V_412 ;
if ( V_20 != 0 )
return;
if ( V_21 -> V_57 < 2 )
return;
F_95 ( & V_21 -> V_28 -> V_29 , L_117 ,
F_131 ( V_408 -> V_413 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_118 ,
F_131 ( V_408 -> V_414 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_119 ,
F_136 ( V_408 -> V_415 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_120 ,
V_408 -> V_416 ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_121 ,
V_408 -> V_417 ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_122 ,
F_97 ( V_408 -> V_418 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_123 ,
F_136 ( V_408 -> V_419 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_124 ,
F_136 ( V_408 -> V_420 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_125 ,
F_97 ( V_408 -> V_225 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_126 ,
F_97 ( V_408 -> V_226 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_127 ,
F_97 ( V_408 -> V_228 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_128 ,
F_97 ( V_408 -> V_229 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_129 ,
F_97 ( V_408 -> V_76 ) ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_130 ,
F_97 ( V_408 -> V_76 ) &
V_421 ? L_131 : L_132 ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_133 ,
F_97 ( V_408 -> V_422 ) ) ;
V_411 = F_97 ( V_408 -> V_229 ) ;
for ( V_220 = 0 ; V_220 < V_411 ; V_220 ++ ) {
F_95 ( & V_21 -> V_28 -> V_29 , L_134 , V_220 ) ;
V_228 = F_97 ( V_408 -> V_228 ) ;
for ( V_409 = 0 ; V_409 < V_228 ; V_409 ++ ) {
F_95 ( & V_21 -> V_28 -> V_29 , L_135 , V_409 ) ;
V_412 =
F_97 ( V_408 -> V_225 ) ;
for ( V_410 = 0 ; V_410 < V_412 ; V_410 ++ , V_222 ++ )
F_95 ( & V_21 -> V_28 -> V_29 ,
L_136 ,
V_410 , V_222 -> V_186 ,
V_222 -> V_423 [ 0 ] , V_222 -> V_423 [ 1 ] ) ;
V_412 =
F_97 ( V_408 -> V_226 ) ;
for ( V_410 = 0 ; V_410 < V_412 ; V_410 ++ , V_222 ++ )
F_95 ( & V_21 -> V_28 -> V_29 ,
L_137 ,
V_410 , V_222 -> V_186 ,
V_222 -> V_423 [ 0 ] , V_222 -> V_423 [ 1 ] ) ;
}
}
}
static int F_186 ( struct V_1 * V_21 ,
unsigned char * V_70 , struct V_71 * V_424 )
{
int V_20 = 0 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
if ( F_175 ( V_9 , V_425 , V_21 , & V_424 -> V_185 ,
sizeof( V_424 -> V_185 ) , 0 ,
V_70 , V_394 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_138 ) ;
F_106 ( V_21 , V_9 ) ;
return - 1 ;
}
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
goto V_395;
}
F_106 ( V_21 , V_9 ) ;
if ( F_131 ( V_424 -> V_185 . V_413 ) >
sizeof( V_424 -> V_185 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_139 ) ;
V_20 = - 1 ;
}
F_185 ( V_21 , V_20 , & V_424 -> V_185 ) ;
return V_20 ;
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_187 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_6 V_426 ,
struct V_427 * V_44 , T_3 V_392 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
V_20 = F_175 ( V_9 , V_428 , V_21 , V_44 , V_392 ,
0 , V_157 , V_394 ) ;
if ( V_20 )
goto V_395;
V_9 -> V_143 . V_144 [ 2 ] = V_426 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_426 >> 8 ) & 0xff ;
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_188 ( struct V_1 * V_21 ,
struct V_429 * V_44 , T_3 V_392 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
V_20 = F_175 ( V_9 , V_430 , V_21 , V_44 , V_392 ,
0 , V_157 , V_394 ) ;
if ( V_20 )
goto V_395;
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_189 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_6 V_426 ,
struct V_431 * V_44 , T_3 V_392 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
V_20 = F_175 ( V_9 , V_432 , V_21 , V_44 , V_392 ,
0 , V_157 , V_394 ) ;
if ( V_20 )
goto V_395;
V_9 -> V_143 . V_144 [ 2 ] = V_426 & 0xff ;
V_9 -> V_143 . V_144 [ 9 ] = ( V_426 >> 8 ) & 0xff ;
F_170 ( V_21 , V_9 , V_396 ,
V_397 ) ;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static void F_190 ( struct V_1 * V_21 ,
unsigned char * V_70 ,
struct V_433 * V_434 , int V_435 ,
struct V_71 * V_436 )
{
int V_20 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_337 * V_338 = NULL ;
struct V_437 * V_438 = NULL ;
struct V_431 * V_439 = NULL ;
struct V_440 * V_441 = & V_434 -> V_349 [ V_435 ] ;
T_6 V_426 = 0 ;
V_426 = F_191 ( & V_441 -> V_84 [ 0 ] ) ;
if ( V_436 -> V_102 == - 1 || V_436 -> V_103 == - 1 ) {
V_20 = V_382 ;
goto V_395;
}
if ( V_426 == 0xFF00 || F_192 ( & V_441 -> V_84 [ 0 ] ) ) {
V_20 = V_382 ;
goto V_395;
}
V_438 = F_115 ( sizeof( * V_438 ) , V_202 ) ;
if ( ! V_438 )
goto V_395;
V_439 = F_115 ( sizeof( * V_439 ) , V_202 ) ;
if ( ! V_439 )
goto V_395;
V_20 = F_189 ( V_21 , V_70 , V_426 ,
V_439 , sizeof( * V_439 ) ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_140 ,
V_241 , V_436 -> V_166 , V_426 ) ;
goto V_395;
}
V_9 = F_174 ( V_21 ) ;
V_20 = F_175 ( V_9 , V_442 , V_21 , V_438 ,
sizeof( * V_438 ) , 0 , V_157 , V_394 ) ;
if ( V_20 )
goto V_395;
if ( V_439 -> V_95 [ 1 ] == 'E' )
V_9 -> V_143 . V_144 [ 5 ] = V_439 -> V_443 ;
else
V_9 -> V_143 . V_144 [ 5 ] = 0 ;
V_20 = F_170 ( V_21 , V_9 , V_396 ,
V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 && V_338 -> V_35 != V_355 ) {
V_20 = - 1 ;
goto V_395;
}
V_436 -> V_91 [ V_439 -> V_444 ] = V_438 -> V_445 ;
memcpy ( & V_436 -> V_95 [ V_439 -> V_444 ] ,
V_438 -> V_95 , sizeof( V_438 -> V_95 ) ) ;
V_20 = V_382 ;
V_395:
F_81 ( V_438 ) ;
F_81 ( V_439 ) ;
if ( V_9 )
F_106 ( V_21 , V_9 ) ;
if ( V_20 != V_382 )
F_70 ( V_181 , V_21 , V_436 ,
L_141 ) ;
}
static T_5 F_193 ( struct V_1 * V_21 ,
unsigned char * V_70 )
{
struct V_433 * V_446 ;
T_4 V_447 ;
T_5 V_448 = 0 ;
int V_67 ;
V_446 = F_115 ( sizeof( * V_446 ) , V_202 ) ;
if ( ! V_446 )
return 0 ;
if ( F_194 ( V_21 , V_446 , sizeof( * V_446 ) ) ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_142 ) ;
F_81 ( V_446 ) ;
return 0 ;
}
V_447 = F_195 ( V_446 -> V_449 ) / 24 ;
for ( V_67 = 0 ; V_67 < V_447 ; V_67 ++ )
if ( ! memcmp ( & V_446 -> V_349 [ V_67 ] . V_84 [ 0 ] , V_70 , 8 ) ) {
V_448 = F_196 ( & V_446 -> V_349 [ V_67 ] . V_450 [ 0 ] ) ;
break;
}
F_81 ( V_446 ) ;
return V_448 ;
}
static void F_197 ( struct V_1 * V_21 , unsigned char * V_70 ,
struct V_71 * V_29 )
{
int V_20 ;
T_5 V_448 = 0 ;
if ( F_63 ( V_70 ) ) {
struct V_427 * V_451 ;
V_451 = F_115 ( sizeof( * V_451 ) , V_202 ) ;
if ( ! V_451 )
return;
V_20 = F_187 ( V_21 ,
V_70 , 0 , V_451 , sizeof( * V_451 ) ) ;
if ( V_20 == 0 ) {
V_448 = F_196 ( V_451 -> V_452 ) ;
V_21 -> V_87 = V_448 ;
}
F_81 ( V_451 ) ;
} else
V_448 = F_193 ( V_21 , V_70 ) ;
V_29 -> V_87 = V_448 ;
}
static bool F_184 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_1 V_391 )
{
int V_20 ;
int V_67 ;
int V_453 ;
unsigned char * V_44 , V_392 ;
V_44 = F_115 ( 256 , V_202 ) ;
if ( ! V_44 )
return false ;
V_20 = F_173 ( V_21 , V_70 ,
V_407 | V_454 ,
V_44 , V_455 ) ;
if ( V_20 != 0 )
goto V_456;
V_453 = V_44 [ 3 ] ;
if ( ( V_453 + V_455 ) <= 255 )
V_392 = V_453 + V_455 ;
else
V_392 = 255 ;
V_20 = F_173 ( V_21 , V_70 ,
V_407 | V_454 ,
V_44 , V_392 ) ;
if ( V_20 != 0 )
goto V_456;
V_453 = V_44 [ 3 ] ;
for ( V_67 = 1 ; V_67 <= V_453 ; V_67 ++ )
if ( V_44 [ 3 + V_67 ] == V_391 )
goto V_457;
V_456:
F_81 ( V_44 ) ;
return false ;
V_457:
F_81 ( V_44 ) ;
return true ;
}
static void F_198 ( struct V_1 * V_21 ,
unsigned char * V_70 , struct V_71 * V_424 )
{
int V_20 ;
unsigned char * V_44 ;
T_1 V_458 ;
V_424 -> V_173 = 0 ;
V_424 -> V_89 = 0 ;
V_424 -> V_182 = 0 ;
V_44 = F_115 ( 64 , V_202 ) ;
if ( ! V_44 )
return;
if ( ! F_184 ( V_21 , V_70 , V_459 ) )
goto V_395;
V_20 = F_173 ( V_21 , V_70 ,
V_407 | V_459 , V_44 , 64 ) ;
if ( V_20 != 0 )
goto V_395;
#define F_199 4
#define F_200 0x01
#define F_201 0x02
V_458 = V_44 [ F_199 ] ;
V_424 -> V_173 =
! ! ( V_458 & F_200 ) ;
if ( V_424 -> V_173 ) {
V_424 -> V_89 =
! ! ( V_458 & F_201 ) ;
if ( F_186 ( V_21 , V_70 , V_424 ) )
V_424 -> V_89 = 0 ;
}
V_424 -> V_182 = V_424 -> V_89 ;
V_395:
F_81 ( V_44 ) ;
return;
}
static int F_202 ( struct V_1 * V_21 , unsigned char * V_70 ,
unsigned char * V_86 , int V_198 , int V_374 )
{
int V_20 ;
unsigned char * V_44 ;
if ( ! F_184 ( V_21 , V_70 , V_460 ) )
return 1 ;
V_44 = F_115 ( 64 , V_202 ) ;
if ( ! V_44 )
return - V_262 ;
V_20 = F_173 ( V_21 , V_70 , V_407 |
V_460 , V_44 , 64 ) ;
if ( V_20 == 0 ) {
if ( V_374 > 16 )
V_374 = 16 ;
memcpy ( V_86 , & V_44 [ 8 ] , V_374 ) ;
}
F_81 ( V_44 ) ;
return V_20 ;
}
static int F_203 ( struct V_1 * V_21 , int V_461 ,
void * V_44 , int V_392 ,
int V_462 )
{
int V_20 = V_382 ;
struct V_8 * V_9 ;
unsigned char V_70 [ 8 ] ;
struct V_337 * V_338 ;
V_9 = F_174 ( V_21 ) ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
if ( F_175 ( V_9 , V_461 ? V_463 : V_464 , V_21 ,
V_44 , V_392 , 0 , V_70 , V_394 ) ) {
V_20 = - 1 ;
goto V_395;
}
if ( V_462 )
V_9 -> V_143 . V_144 [ 1 ] = V_462 ;
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( V_20 )
goto V_395;
V_338 = V_9 -> V_23 ;
if ( V_338 -> V_35 != 0 &&
V_338 -> V_35 != V_355 ) {
F_172 ( V_21 , V_9 ) ;
V_20 = - 1 ;
} else {
struct V_465 * V_466 = V_44 ;
if ( V_466 -> V_467 != V_462 ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_143 ,
V_462 ,
V_466 -> V_467 ) ;
V_20 = - 1 ;
}
}
V_395:
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static inline int F_194 ( struct V_1 * V_21 ,
struct V_433 * V_44 , int V_392 )
{
int V_20 ;
struct V_465 * V_468 ;
V_20 = F_203 ( V_21 , 0 , V_44 , V_392 ,
V_469 ) ;
if ( ! V_20 || ! V_470 )
return V_20 ;
V_468 = F_115 ( sizeof( * V_468 ) , V_202 ) ;
if ( ! V_468 )
return - V_262 ;
V_20 = F_203 ( V_21 , 0 , V_468 , sizeof( * V_468 ) , 0 ) ;
if ( ! V_20 ) {
int V_67 ;
T_4 V_471 ;
memcpy ( V_44 , V_468 , 8 ) ;
V_471 = F_204 ( * ( ( V_472 * ) V_468 -> V_449 ) ) / 8 ;
for ( V_67 = 0 ; V_67 < V_471 ; V_67 ++ )
memcpy ( V_44 -> V_349 [ V_67 ] . V_84 , V_468 -> V_349 [ V_67 ] , 8 ) ;
}
F_81 ( V_468 ) ;
return V_20 ;
}
static inline int F_205 ( struct V_1 * V_21 ,
struct V_465 * V_44 , int V_392 )
{
return F_203 ( V_21 , 1 , V_44 , V_392 , 0 ) ;
}
static inline void F_206 ( struct V_71 * V_41 ,
int V_101 , int V_102 , int V_103 )
{
V_41 -> V_101 = V_101 ;
V_41 -> V_102 = V_102 ;
V_41 -> V_103 = V_103 ;
}
static int F_207 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
int V_20 ;
int V_48 ;
int V_473 ;
unsigned char * V_44 ;
V_44 = F_115 ( 64 , V_202 ) ;
if ( ! V_44 )
return V_205 ;
if ( ! F_184 ( V_21 , V_70 , V_474 ) )
goto V_475;
V_20 = F_173 ( V_21 , V_70 , V_407 | V_474 ,
V_44 , V_455 ) ;
if ( V_20 != 0 )
goto V_475;
V_473 = V_44 [ 3 ] ;
V_20 = F_173 ( V_21 , V_70 , V_407 | V_474 ,
V_44 , V_473 + V_455 ) ;
if ( V_20 != 0 )
goto V_475;
V_48 = V_44 [ 4 ] ;
F_81 ( V_44 ) ;
return V_48 ;
V_475:
F_81 ( V_44 ) ;
return V_205 ;
}
static unsigned char F_208 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
struct V_8 * V_9 ;
unsigned char * V_476 ;
T_1 V_15 , V_16 , V_17 ;
int V_22 ;
int V_20 , V_477 = 0 ;
T_6 V_478 ;
T_1 V_479 ;
#define F_209 0x04
#define F_210 0x04
#define F_211 0x02
V_9 = F_174 ( V_21 ) ;
( void ) F_175 ( V_9 , V_480 , V_21 , NULL , 0 , 0 , V_70 , V_394 ) ;
V_20 = F_166 ( V_21 , V_9 , V_126 ,
V_397 ) ;
if ( V_20 ) {
F_106 ( V_21 , V_9 ) ;
return V_205 ;
}
V_476 = V_9 -> V_23 -> V_25 ;
if ( V_9 -> V_23 -> V_24 > sizeof( V_9 -> V_23 -> V_25 ) )
V_22 = sizeof( V_9 -> V_23 -> V_25 ) ;
else
V_22 = V_9 -> V_23 -> V_24 ;
F_6 ( V_476 , V_22 , & V_15 , & V_16 , & V_17 ) ;
V_478 = V_9 -> V_23 -> V_35 ;
V_479 = V_9 -> V_23 -> V_37 ;
F_106 ( V_21 , V_9 ) ;
V_477 = F_207 ( V_21 , V_70 ) ;
switch ( V_477 ) {
case V_481 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
return V_477 ;
case V_205 :
if ( ( V_17 == F_210 ) ||
( V_17 == F_211 ) )
return V_477 ;
break;
default:
break;
}
return V_206 ;
}
static int F_212 ( struct V_1 * V_21 ,
unsigned char V_70 [] , struct V_71 * V_424 ,
unsigned char * V_482 )
{
#define F_213 43
#define F_214 "$DR-10"
#define F_215 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_216 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_483 ;
unsigned char * V_484 ;
int V_20 = 0 ;
V_483 = F_115 ( F_216 , V_202 ) ;
if ( ! V_483 ) {
V_20 = - V_262 ;
goto V_485;
}
if ( F_173 ( V_21 , V_70 , 0 , V_483 ,
( unsigned char ) F_216 ) != 0 ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_144 ,
V_241 ) ;
V_20 = V_486 ;
goto V_485;
}
F_217 ( & V_483 [ 8 ] , 8 ) ;
F_217 ( & V_483 [ 16 ] , 16 ) ;
V_424 -> V_104 = ( V_483 [ 0 ] & 0x1f ) ;
memcpy ( V_424 -> V_70 , V_70 , 8 ) ;
memcpy ( V_424 -> V_171 , & V_483 [ 8 ] ,
sizeof( V_424 -> V_171 ) ) ;
memcpy ( V_424 -> V_172 , & V_483 [ 16 ] ,
sizeof( V_424 -> V_172 ) ) ;
V_424 -> V_487 = V_483 [ 2 ] ;
memset ( V_424 -> V_86 , 0 ,
sizeof( V_424 -> V_86 ) ) ;
if ( F_202 ( V_21 , V_70 , V_424 -> V_86 , 8 ,
sizeof( V_424 -> V_86 ) ) )
F_74 ( & V_21 -> V_28 -> V_29 ,
L_145 ,
V_21 -> V_108 , V_241 ,
V_21 -> V_58 -> V_100 ,
V_424 -> V_102 , V_424 -> V_103 ,
F_42 ( V_424 -> V_104 ) ,
V_424 -> V_172 ) ;
if ( ( V_424 -> V_104 == V_106 ||
V_424 -> V_104 == V_107 ) &&
F_30 ( V_70 ) ) {
unsigned char V_199 ;
F_183 ( V_21 , V_70 , & V_424 -> V_81 ) ;
if ( V_21 -> V_488 & V_489 )
F_198 ( V_21 , V_70 , V_424 ) ;
V_199 = F_208 ( V_21 , V_70 ) ;
V_424 -> V_199 = V_199 ;
if ( V_199 == V_481 ) {
V_20 = V_481 ;
F_74 ( & V_21 -> V_28 -> V_29 ,
L_146 ,
V_241 ) ;
goto V_485;
}
} else {
V_424 -> V_81 = V_82 ;
V_424 -> V_173 = 0 ;
V_424 -> V_89 = 0 ;
V_424 -> V_182 = 0 ;
V_424 -> V_187 = 0 ;
V_424 -> V_199 = 0 ;
V_424 -> V_189 = V_21 -> V_235 ;
}
if ( V_424 -> V_166 )
V_424 -> V_189 = V_258 ;
if ( V_482 ) {
V_484 = & V_483 [ F_213 ] ;
* V_482 = ( V_424 -> V_104 == V_168 &&
strncmp ( V_484 , F_214 ,
F_215 ) == 0 ) ;
}
F_81 ( V_483 ) ;
return 0 ;
V_485:
F_81 ( V_483 ) ;
return V_20 ;
}
static void F_218 ( struct V_1 * V_21 ,
T_1 * V_490 , struct V_71 * V_41 )
{
T_4 V_84 = F_142 ( V_490 ) ;
if ( ! F_30 ( V_490 ) ) {
if ( F_63 ( V_490 ) ) {
int V_101 = V_491 ;
if ( ! V_41 -> V_487 )
V_101 = V_492 ;
F_206 ( V_41 ,
V_101 , 0 , V_84 & 0x3fff ) ;
} else
F_206 ( V_41 ,
V_251 , - 1 , - 1 ) ;
return;
}
if ( V_41 -> V_166 ) {
F_206 ( V_41 ,
V_493 , ( V_84 >> 16 ) & 0x3fff ,
V_84 & 0x00ff ) ;
return;
}
F_206 ( V_41 , V_494 ,
0 , V_84 & 0x3fff ) ;
}
static int F_219 ( struct V_1 * V_21 , int V_495 ,
int V_67 , int V_447 , int V_496 )
{
int V_497 = V_447 + ( V_495 == 0 ) ;
if ( V_67 == V_495 )
return 0 ;
if ( V_67 < V_497 )
return 0 ;
if ( ( V_67 - V_447 - ( V_495 == 0 ) ) < V_496 )
return 0 ;
return 1 ;
}
static int F_220 ( struct V_1 * V_21 ,
struct V_433 * V_446 , T_4 * V_447 ,
struct V_465 * V_498 , T_4 * V_499 )
{
if ( F_194 ( V_21 , V_446 , sizeof( * V_446 ) ) ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_142 ) ;
return - 1 ;
}
* V_447 = F_204 ( * ( ( V_472 * ) V_446 -> V_449 ) ) / 24 ;
if ( * V_447 > V_500 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_147 ,
V_500 , * V_447 - V_500 ) ;
* V_447 = V_500 ;
}
if ( F_205 ( V_21 , V_498 , sizeof( * V_498 ) ) ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_148 ) ;
return - 1 ;
}
* V_499 = F_204 ( * ( ( V_472 * ) V_498 -> V_449 ) ) / 8 ;
if ( * V_499 > V_501 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_149
L_150 , V_501 ,
* V_499 - V_501 ) ;
* V_499 = V_501 ;
}
if ( * V_499 + * V_447 > V_500 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_151
L_150 , V_500 ,
* V_447 + * V_499 - V_500 ) ;
* V_499 = V_500 - * V_447 ;
}
return 0 ;
}
static T_1 * F_221 ( struct V_1 * V_21 , int V_495 ,
int V_67 , int V_447 , int V_499 ,
struct V_433 * V_502 ,
struct V_465 * V_503 )
{
int V_497 = V_447 + ( V_495 == 0 ) ;
int V_504 = V_447 + V_499 + ( V_495 == 0 ) ;
if ( V_67 == V_495 )
return V_157 ;
if ( V_67 < V_497 )
return & V_502 -> V_349 [ V_67 -
( V_495 == 0 ) ] . V_84 [ 0 ] ;
if ( V_67 < V_504 )
return & V_503 -> V_349 [ V_67 - V_447 -
( V_495 == 0 ) ] [ 0 ] ;
F_177 () ;
return NULL ;
}
static void F_222 ( struct V_1 * V_21 ,
struct V_71 * V_29 ,
struct V_433 * V_434 , int V_435 ,
struct V_431 * V_439 )
{
int V_20 ;
struct V_440 * V_441 ;
V_441 = & V_434 -> V_349 [ V_435 ] ;
V_29 -> V_186 = V_441 -> V_186 ;
if ( ( V_441 -> V_505 & 0x08 ) && V_29 -> V_186 )
V_29 -> V_187 = 1 ;
memset ( V_439 , 0 , sizeof( * V_439 ) ) ;
V_20 = F_189 ( V_21 , & V_441 -> V_84 [ 0 ] ,
F_191 ( & V_441 -> V_84 [ 0 ] ) , V_439 ,
sizeof( * V_439 ) ) ;
if ( ! V_20 )
#define F_223 2
#define F_224 7
V_29 -> V_189 =
F_97 ( V_439 -> V_506 ) -
F_223 ;
else
V_29 -> V_189 = F_224 ;
}
static void F_225 ( struct V_71 * V_424 ,
struct V_433 * V_434 , int V_435 ,
struct V_431 * V_439 )
{
struct V_440 * V_441 = & V_434 -> V_349 [ V_435 ] ;
if ( ( V_441 -> V_505 & 0x08 ) && V_424 -> V_186 )
V_424 -> V_187 = 1 ;
memcpy ( & V_424 -> V_98 ,
& V_439 -> V_444 ,
sizeof( V_424 -> V_98 ) ) ;
memcpy ( & V_424 -> V_99 ,
& V_439 -> V_507 ,
sizeof( V_424 -> V_99 ) ) ;
memcpy ( & V_424 -> V_91 ,
& V_439 -> V_508 ,
sizeof( V_424 -> V_91 ) ) ;
memcpy ( & V_424 -> V_95 ,
& V_439 -> V_509 ,
sizeof( V_424 -> V_95 ) ) ;
memcpy ( & V_424 -> V_92 ,
& V_439 -> V_510 ,
sizeof( V_424 -> V_92 ) ) ;
}
static int F_226 ( struct V_1 * V_21 ,
struct V_429 * V_511 ,
T_4 * V_512 )
{
int V_20 ;
if ( ! V_511 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_152 ,
V_241 ) ;
return - V_262 ;
}
memset ( V_511 , 0 , sizeof( * V_511 ) ) ;
V_20 = F_188 ( V_21 , V_511 , sizeof( * V_511 ) ) ;
if ( ! V_20 )
if ( V_511 -> V_513 < 256 )
* V_512 = V_511 -> V_513 ;
else
* V_512 = F_97 (
V_511 -> V_514 ) ;
else
* V_512 = - 1 ;
return V_20 ;
}
static bool F_227 ( struct V_1 * V_21 , T_1 * V_490 )
{
struct V_431 * V_439 ;
bool V_515 = false ;
int V_20 ;
V_439 = F_115 ( sizeof( * V_439 ) , V_202 ) ;
if ( ! V_439 )
return false ;
V_20 = F_189 ( V_21 ,
V_490 ,
F_191 ( V_490 ) ,
V_439 , sizeof( * V_439 ) ) ;
if ( V_20 == 0 )
V_515 = ( V_439 -> V_516 >> 6 ) & 0x01 ;
F_81 ( V_439 ) ;
return V_515 ;
}
static bool F_228 ( struct V_1 * V_21 , T_1 * V_490 ,
struct V_440 * V_441 )
{
T_1 V_505 ;
T_1 V_517 ;
if ( ! F_192 ( V_490 ) )
return false ;
V_505 = V_441 -> V_505 ;
V_517 = V_441 -> V_517 ;
if ( V_505 & V_518 ) {
if ( V_517 == V_519 )
return false ;
return true ;
}
if ( ! ( V_505 & V_520 ) )
return false ;
if ( V_505 & V_521 )
return false ;
if ( F_227 ( V_21 , V_490 ) )
return true ;
return false ;
}
static void F_229 ( struct V_1 * V_21 )
{
struct V_433 * V_502 = NULL ;
struct V_465 * V_503 = NULL ;
struct V_431 * V_439 = NULL ;
struct V_429 * V_511 = NULL ;
T_4 V_447 = 0 ;
T_4 V_499 = 0 ;
T_4 V_496 = 0 ;
T_4 V_522 = 0 ;
struct V_71 * * V_523 , * V_424 , * V_524 ;
int V_525 = 0 ;
int V_67 , V_526 , V_527 ;
int V_495 ;
bool V_72 ;
F_66 ( V_528 , V_529 ) ;
V_523 = F_115 ( sizeof( * V_523 ) * V_160 , V_202 ) ;
V_502 = F_115 ( sizeof( * V_502 ) , V_202 ) ;
V_503 = F_115 ( sizeof( * V_503 ) , V_202 ) ;
V_524 = F_115 ( sizeof( * V_524 ) , V_202 ) ;
V_439 = F_115 ( sizeof( * V_439 ) , V_202 ) ;
V_511 = F_115 ( sizeof( * V_511 ) , V_202 ) ;
if ( ! V_523 || ! V_502 || ! V_503 ||
! V_524 || ! V_439 || ! V_511 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_153 ) ;
goto V_395;
}
memset ( V_528 , 0 , sizeof( V_528 ) ) ;
V_21 -> V_249 = 0 ;
if ( F_220 ( V_21 , V_502 , & V_447 ,
V_503 , & V_499 ) ) {
V_21 -> V_249 = 1 ;
goto V_395;
}
if ( F_226 ( V_21 , V_511 , & V_496 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_154 ,
V_241 ) ;
}
V_527 = V_447 + V_499 + V_529 + 1 ;
for ( V_67 = 0 ; V_67 < V_527 ; V_67 ++ ) {
if ( V_67 >= V_160 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_155
L_156 , V_160 ,
V_527 - V_160 ) ;
break;
}
V_523 [ V_67 ] = F_115 ( sizeof( * V_523 [ V_67 ] ) , V_202 ) ;
if ( ! V_523 [ V_67 ] ) {
V_21 -> V_249 = 1 ;
goto V_395;
}
V_522 ++ ;
}
if ( F_64 ( V_21 ) )
V_495 = 0 ;
else
V_495 = V_447 + V_499 ;
V_526 = 0 ;
for ( V_67 = 0 ; V_67 < V_447 + V_499 + 1 ; V_67 ++ ) {
T_1 * V_490 , V_530 = 0 ;
int V_20 = 0 ;
int V_531 = V_67 - ( V_495 == 0 ) ;
bool V_532 = false ;
V_72 = V_67 < V_447 + ( V_495 == 0 ) ;
V_490 = F_221 ( V_21 , V_495 ,
V_67 , V_447 , V_499 , V_502 , V_503 ) ;
V_524 -> V_166 =
F_219 ( V_21 , V_495 , V_67 ,
V_447 , V_496 ) ;
if ( ! V_524 -> V_166 && V_72 ) {
V_532 = F_228 ( V_21 , V_490 ,
& V_502 -> V_349 [ V_531 ] ) ;
if ( V_532 )
continue;
}
V_20 = F_212 ( V_21 , V_490 , V_524 ,
& V_530 ) ;
if ( V_20 == - V_262 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_157 ) ;
V_21 -> V_249 = 1 ;
goto V_395;
}
if ( V_20 ) {
V_21 -> V_249 = 1 ;
continue;
}
F_218 ( V_21 , V_490 , V_524 ) ;
V_424 = V_523 [ V_525 ] ;
if ( ! V_21 -> V_533 ) {
if ( V_524 -> V_166 ) {
V_21 -> V_533 = 1 ;
F_95 ( & V_21 -> V_28 -> V_29 ,
L_158 ) ;
}
}
* V_424 = * V_524 ;
V_424 -> V_72 = V_72 ;
if ( F_192 ( V_490 ) && V_424 -> V_72 )
V_424 -> V_88 = 0 ;
else
V_424 -> V_88 = 1 ;
if ( V_424 -> V_72 && V_424 -> V_88 )
F_197 ( V_21 , V_490 , V_424 ) ;
switch ( V_424 -> V_104 ) {
case V_168 :
if ( V_530 )
V_525 ++ ;
break;
case V_106 :
case V_107 :
if ( V_424 -> V_72 ) {
V_424 -> V_89 = 0 ;
F_222 ( V_21 , V_424 ,
V_502 , V_531 , V_439 ) ;
F_225 ( V_424 ,
V_502 , V_531 , V_439 ) ;
}
V_525 ++ ;
break;
case V_169 :
case V_170 :
V_525 ++ ;
break;
case V_165 :
if ( ! V_424 -> V_166 )
F_190 ( V_21 , V_490 ,
V_502 , V_531 ,
V_424 ) ;
V_525 ++ ;
break;
case V_105 :
if ( ! F_63 ( V_490 ) )
break;
V_525 ++ ;
break;
default:
break;
}
if ( V_525 >= V_160 )
break;
}
if ( V_21 -> V_236 == NULL ) {
int V_20 = 0 ;
V_20 = F_230 ( V_21 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_159 , V_20 ) ;
goto V_395;
}
}
F_114 ( V_21 , V_523 , V_525 ) ;
V_395:
F_81 ( V_524 ) ;
for ( V_67 = 0 ; V_67 < V_522 ; V_67 ++ )
F_81 ( V_523 [ V_67 ] ) ;
F_81 ( V_523 ) ;
F_81 ( V_502 ) ;
F_81 ( V_503 ) ;
F_81 ( V_511 ) ;
F_81 ( V_439 ) ;
}
static void F_231 ( struct V_275 * V_534 ,
struct V_535 * V_270 )
{
T_5 V_375 = ( T_5 ) F_232 ( V_270 ) ;
unsigned int V_49 = F_233 ( V_270 ) ;
V_534 -> V_283 = F_134 ( V_375 ) ;
V_534 -> V_282 = F_139 ( V_49 ) ;
V_534 -> V_279 = 0 ;
}
static int F_234 ( struct V_1 * V_21 ,
struct V_8 * V_130 ,
struct V_284 * V_285 )
{
struct V_535 * V_270 ;
int V_536 , V_67 , V_537 , V_538 , V_539 ;
struct V_275 * V_540 ;
F_76 ( F_157 ( V_285 ) > V_21 -> V_263 ) ;
V_536 = F_235 ( V_285 ) ;
if ( V_536 < 0 )
return V_536 ;
if ( ! V_536 )
goto V_541;
V_540 = V_130 -> V_277 ;
V_538 = V_536 > V_21 -> V_278 ;
V_537 = V_538 ? V_21 -> V_278 - 1 : V_536 ;
V_539 = F_157 ( V_285 ) - 1 ;
F_236 (cmd, sg, sg_limit, i) {
F_231 ( V_540 , V_270 ) ;
V_540 ++ ;
}
if ( V_538 ) {
V_540 = V_21 -> V_265 [ V_130 -> V_132 ] ;
V_537 = V_536 - V_537 ;
F_237 (sg, sg, sg_limit, i) {
F_231 ( V_540 , V_270 ) ;
V_540 ++ ;
}
}
( V_540 - 1 ) -> V_279 = F_139 ( V_377 ) ;
if ( V_536 + V_538 > V_21 -> V_542 )
V_21 -> V_542 = V_536 + V_538 ;
if ( V_538 ) {
V_130 -> V_123 . V_124 = V_21 -> V_278 ;
V_130 -> V_123 . V_281 = F_158 ( V_536 + 1 ) ;
if ( F_138 ( V_21 , V_130 ) ) {
F_156 ( V_285 ) ;
return - 1 ;
}
return 0 ;
}
V_541:
V_130 -> V_123 . V_124 = ( T_1 ) V_536 ;
V_130 -> V_123 . V_281 = F_158 ( V_536 ) ;
return 0 ;
}
static inline void F_238 ( struct V_1 * V_21 ,
T_1 * V_140 , int V_543 ,
const char * V_544 )
{
char V_44 [ V_545 ] ;
int V_546 ;
int V_67 ;
V_546 = F_41 ( V_44 , V_545 ,
L_160 , V_544 ) ;
for ( V_67 = 0 ; V_67 < V_543 ; V_67 ++ )
V_546 += F_41 ( V_44 + V_546 , V_545 - V_546 ,
L_161 , V_140 [ V_67 ] ) ;
F_9 ( & V_21 -> V_28 -> V_29 , L_16 , V_44 ) ;
}
static bool F_239 ( T_1 * V_140 )
{
T_4 V_547 ;
switch ( V_140 [ 0 ] ) {
case V_548 :
case V_549 :
case V_550 :
case V_551 :
V_547 = F_240 ( & V_140 [ 7 ] ) ;
break;
case V_552 :
case V_553 :
case V_554 :
case V_555 :
V_547 = F_195 ( & V_140 [ 6 ] ) ;
break;
case V_556 :
case V_557 :
case V_558 :
V_547 = F_195 ( & V_140 [ 10 ] ) ;
break;
default:
return false ;
}
return V_547 == 0 ;
}
static int F_241 ( T_1 * V_140 , int * V_543 )
{
int V_559 = 0 ;
T_4 V_560 ;
T_4 V_547 ;
switch ( V_140 [ 0 ] ) {
case V_561 :
case V_553 :
V_559 = 1 ;
case V_562 :
case V_552 :
if ( * V_543 == 6 ) {
V_560 = ( ( ( V_140 [ 1 ] & 0x1F ) << 16 ) |
( V_140 [ 2 ] << 8 ) |
V_140 [ 3 ] ) ;
V_547 = V_140 [ 4 ] ;
if ( V_547 == 0 )
V_547 = 256 ;
} else {
F_76 ( * V_543 != 12 ) ;
V_560 = F_195 ( & V_140 [ 2 ] ) ;
V_547 = F_195 ( & V_140 [ 6 ] ) ;
}
if ( V_547 > 0xffff )
return V_563 ;
V_140 [ 0 ] = V_559 ? V_549 : V_548 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_560 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_560 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_560 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_560 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_547 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_547 ) ;
V_140 [ 9 ] = 0 ;
* V_543 = 10 ;
break;
}
return 0 ;
}
static int F_242 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_543 ,
T_1 * V_70 , struct V_71 * V_234 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_129 * V_130 = & V_21 -> V_131 [ V_9 -> V_132 ] ;
unsigned int V_49 ;
unsigned int V_564 = 0 ;
struct V_535 * V_270 ;
T_5 V_375 ;
int V_536 , V_67 ;
struct V_275 * V_540 ;
T_4 V_565 = V_566 ;
if ( F_157 ( V_285 ) > V_21 -> V_567 ) {
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
F_76 ( V_285 -> V_568 > V_569 ) ;
if ( F_239 ( V_140 ) ) {
F_238 ( V_21 , V_140 , V_543 , V_241 ) ;
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
if ( F_241 ( V_140 , & V_543 ) ) {
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
V_9 -> V_149 = V_150 ;
V_9 -> V_121 = ( T_4 ) V_21 -> V_570 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_76 ( V_9 -> V_121 & 0x0000007F ) ;
V_536 = F_235 ( V_285 ) ;
if ( V_536 < 0 ) {
F_46 ( & V_234 -> V_256 ) ;
return V_536 ;
}
if ( V_536 ) {
V_540 = V_130 -> V_277 ;
F_236 (cmd, sg, use_sg, i) {
V_375 = ( T_5 ) F_232 ( V_270 ) ;
V_49 = F_233 ( V_270 ) ;
V_564 += V_49 ;
V_540 -> V_283 = F_134 ( V_375 ) ;
V_540 -> V_282 = F_139 ( V_49 ) ;
V_540 -> V_279 = F_139 ( 0 ) ;
V_540 ++ ;
}
( -- V_540 ) -> V_279 = F_139 ( V_377 ) ;
switch ( V_285 -> V_571 ) {
case V_572 :
V_565 |= V_573 ;
break;
case V_574 :
V_565 |= V_575 ;
break;
case V_576 :
V_565 |= V_577 ;
break;
default:
F_74 ( & V_21 -> V_28 -> V_29 , L_162 ,
V_285 -> V_571 ) ;
F_177 () ;
break;
}
} else {
V_565 |= V_577 ;
}
V_9 -> V_123 . V_124 = V_536 ;
V_130 -> V_578 = F_158 ( V_186 & 0xFFFF ) ;
V_130 -> V_579 = F_139 ( V_564 ) ;
V_130 -> V_346 = F_158 ( V_580 |
( V_543 & V_347 ) ) ;
V_130 -> V_565 = F_139 ( V_565 ) ;
memcpy ( V_130 -> V_144 , V_140 , V_543 ) ;
memcpy ( V_130 -> V_351 , V_70 , 8 ) ;
F_61 ( V_21 , V_9 ) ;
return 0 ;
}
static int F_243 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_71 * V_29 = V_285 -> V_41 -> V_78 ;
if ( ! V_29 )
return - 1 ;
V_9 -> V_234 = V_29 ;
return F_244 ( V_21 , V_9 , V_29 -> V_186 ,
V_285 -> V_581 , V_285 -> V_568 , V_29 -> V_70 , V_29 ) ;
}
static void F_245 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_138 * V_130 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_71 * V_29 = V_285 -> V_41 -> V_78 ;
struct V_219 * V_220 = & V_29 -> V_185 ;
T_5 V_582 ;
if ( ! ( F_97 ( V_220 -> V_76 ) & V_421 ) )
return;
V_130 -> V_422 = V_220 -> V_422 ;
V_130 -> V_583 |= V_584 ;
switch ( V_285 -> V_581 [ 0 ] ) {
case V_562 :
case V_561 :
V_582 = ( ( ( V_285 -> V_581 [ 1 ] & 0x1F ) << 16 ) |
( V_285 -> V_581 [ 2 ] << 8 ) |
V_285 -> V_581 [ 3 ] ) ;
break;
case V_549 :
case V_548 :
case V_553 :
case V_552 :
V_582 = F_195 ( & V_285 -> V_581 [ 2 ] ) ;
break;
case V_557 :
case V_556 :
V_582 = F_196 ( & V_285 -> V_581 [ 2 ] ) ;
break;
default:
F_74 ( & V_21 -> V_28 -> V_29 ,
L_163 ,
V_241 , V_285 -> V_581 [ 0 ] ) ;
F_177 () ;
break;
}
if ( F_131 ( V_220 -> V_414 ) != 512 )
V_582 = V_582 *
F_131 ( V_220 -> V_414 ) / 512 ;
V_130 -> V_585 = F_139 ( V_582 ) ;
V_130 -> V_586 = F_139 ( V_582 >> 32 ) ;
}
static int F_246 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_543 ,
T_1 * V_70 , struct V_71 * V_234 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_138 * V_130 = & V_21 -> V_136 [ V_9 -> V_132 ] ;
struct V_266 * V_540 ;
int V_536 , V_67 ;
struct V_535 * V_270 ;
T_5 V_375 ;
T_4 V_49 ;
T_4 V_564 = 0 ;
if ( ! V_285 -> V_41 )
return - 1 ;
if ( ! V_285 -> V_41 -> V_78 )
return - 1 ;
F_76 ( F_157 ( V_285 ) > V_21 -> V_263 ) ;
if ( F_239 ( V_140 ) ) {
F_238 ( V_21 , V_140 , V_543 , V_241 ) ;
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
if ( F_241 ( V_140 , & V_543 ) ) {
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
V_9 -> V_149 = V_153 ;
V_9 -> V_121 = ( T_4 ) V_21 -> V_587 +
( V_9 -> V_132 * sizeof( * V_130 ) ) ;
F_76 ( V_9 -> V_121 & 0x0000007F ) ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_588 = V_589 ;
V_536 = F_235 ( V_285 ) ;
if ( V_536 < 0 ) {
F_46 ( & V_234 -> V_256 ) ;
return V_536 ;
}
if ( V_536 ) {
V_540 = V_130 -> V_270 ;
if ( V_536 > V_21 -> V_567 ) {
V_375 = F_136 (
V_21 -> V_260 [ V_9 -> V_132 ] -> V_273 ) ;
V_540 -> V_273 = F_134 ( V_375 ) ;
V_540 -> V_271 = 0 ;
V_540 -> V_590 [ 0 ] = 0 ;
V_540 -> V_590 [ 1 ] = 0 ;
V_540 -> V_590 [ 2 ] = 0 ;
V_540 -> V_341 = 0x80 ;
V_540 = V_21 -> V_260 [ V_9 -> V_132 ] ;
}
F_236 (cmd, sg, use_sg, i) {
V_375 = ( T_5 ) F_232 ( V_270 ) ;
V_49 = F_233 ( V_270 ) ;
V_564 += V_49 ;
V_540 -> V_273 = F_134 ( V_375 ) ;
V_540 -> V_271 = F_139 ( V_49 ) ;
V_540 -> V_590 [ 0 ] = 0 ;
V_540 -> V_590 [ 1 ] = 0 ;
V_540 -> V_590 [ 2 ] = 0 ;
V_540 -> V_341 = 0 ;
V_540 ++ ;
}
switch ( V_285 -> V_571 ) {
case V_572 :
V_130 -> V_583 &= ~ V_591 ;
V_130 -> V_583 |= V_592 ;
break;
case V_574 :
V_130 -> V_583 &= ~ V_591 ;
V_130 -> V_583 |= V_593 ;
break;
case V_576 :
V_130 -> V_583 &= ~ V_591 ;
V_130 -> V_583 |= V_594 ;
break;
default:
F_74 ( & V_21 -> V_28 -> V_29 , L_162 ,
V_285 -> V_571 ) ;
F_177 () ;
break;
}
} else {
V_130 -> V_583 &= ~ V_591 ;
V_130 -> V_583 |= V_594 ;
}
F_245 ( V_21 , V_9 , V_130 ) ;
V_130 -> V_595 = F_139 ( V_186 ) ;
V_130 -> V_596 = F_139 ( V_9 -> V_132 << V_597 ) ;
memcpy ( V_130 -> V_140 , V_140 , sizeof( V_130 -> V_140 ) ) ;
V_130 -> V_287 = F_139 ( V_564 ) ;
V_130 -> V_598 = F_134 ( V_9 -> V_121 +
F_247 ( struct V_138 , V_290 ) ) ;
V_130 -> V_599 = F_139 ( sizeof( V_130 -> V_290 ) ) ;
if ( V_536 > V_21 -> V_567 ) {
V_130 -> V_139 = 1 ;
V_130 -> V_270 [ 0 ] . V_271 = F_139 ( V_536 * sizeof( V_130 -> V_270 [ 0 ] ) ) ;
if ( F_130 ( V_21 , V_130 , V_9 ) ) {
F_46 ( & V_234 -> V_256 ) ;
F_156 ( V_285 ) ;
return - 1 ;
}
} else
V_130 -> V_139 = ( T_1 ) V_536 ;
F_61 ( V_21 , V_9 ) ;
return 0 ;
}
static int F_244 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_186 , T_1 * V_140 , int V_543 ,
T_1 * V_70 , struct V_71 * V_234 )
{
if ( ! V_9 -> V_10 -> V_41 )
return - 1 ;
if ( ! V_9 -> V_10 -> V_41 -> V_78 )
return - 1 ;
if ( F_104 ( & V_234 -> V_256 ) >
V_234 -> V_189 ) {
F_46 ( & V_234 -> V_256 ) ;
return V_563 ;
}
if ( V_21 -> V_62 & V_113 )
return F_242 ( V_21 , V_9 , V_186 ,
V_140 , V_543 , V_70 ,
V_234 ) ;
else
return F_246 ( V_21 , V_9 , V_186 ,
V_140 , V_543 , V_70 ,
V_234 ) ;
}
static void F_248 ( struct V_219 * V_220 ,
int V_188 , T_4 * V_600 , T_4 * V_601 )
{
if ( V_188 == 0 ) {
* V_600 %= F_97 ( V_220 -> V_225 ) ;
return;
}
do {
* V_601 = * V_600 /
F_97 ( V_220 -> V_225 ) ;
if ( V_188 == * V_601 )
continue;
if ( * V_601 < F_97 ( V_220 -> V_229 ) - 1 ) {
* V_600 += F_97 ( V_220 -> V_225 ) ;
( * V_601 ) ++ ;
} else {
* V_600 %= F_97 ( V_220 -> V_225 ) ;
* V_601 = 0 ;
}
} while ( V_188 != * V_601 );
}
static int F_249 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_284 * V_285 = V_9 -> V_10 ;
struct V_71 * V_29 = V_285 -> V_41 -> V_78 ;
struct V_219 * V_220 = & V_29 -> V_185 ;
struct V_221 * V_222 = & V_220 -> V_223 [ 0 ] ;
int V_559 = 0 ;
T_4 V_600 ;
T_5 V_582 , V_602 ;
T_4 V_547 ;
T_4 V_603 ;
T_5 V_604 , V_605 ;
T_4 V_606 , V_607 ;
T_4 V_608 , V_609 ;
T_5 V_610 , V_611 ;
T_4 V_612 ;
T_5 V_613 , V_614 ;
T_4 V_615 , V_616 ;
T_4 V_617 , V_618 ;
T_4 V_224 ;
T_4 V_619 ;
T_4 V_620 , V_621 , V_601 ;
T_4 V_622 ;
T_4 V_623 ;
T_5 V_624 ;
T_4 V_625 ;
T_1 V_140 [ 16 ] ;
T_1 V_543 ;
T_6 V_418 ;
#if V_626 == 32
T_5 V_627 ;
#endif
int V_188 ;
if ( ! V_29 )
return - 1 ;
switch ( V_285 -> V_581 [ 0 ] ) {
case V_561 :
V_559 = 1 ;
case V_562 :
V_582 = ( ( ( V_285 -> V_581 [ 1 ] & 0x1F ) << 16 ) |
( V_285 -> V_581 [ 2 ] << 8 ) |
V_285 -> V_581 [ 3 ] ) ;
V_547 = V_285 -> V_581 [ 4 ] ;
if ( V_547 == 0 )
V_547 = 256 ;
break;
case V_549 :
V_559 = 1 ;
case V_548 :
V_582 =
( ( ( T_5 ) V_285 -> V_581 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_581 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_581 [ 4 ] ) << 8 ) |
V_285 -> V_581 [ 5 ] ;
V_547 =
( ( ( T_4 ) V_285 -> V_581 [ 7 ] ) << 8 ) |
V_285 -> V_581 [ 8 ] ;
break;
case V_553 :
V_559 = 1 ;
case V_552 :
V_582 =
( ( ( T_5 ) V_285 -> V_581 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_581 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_581 [ 4 ] ) << 8 ) |
V_285 -> V_581 [ 5 ] ;
V_547 =
( ( ( T_4 ) V_285 -> V_581 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_285 -> V_581 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_285 -> V_581 [ 8 ] ) << 8 ) |
V_285 -> V_581 [ 9 ] ;
break;
case V_557 :
V_559 = 1 ;
case V_556 :
V_582 =
( ( ( T_5 ) V_285 -> V_581 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_285 -> V_581 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_285 -> V_581 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_285 -> V_581 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_285 -> V_581 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_285 -> V_581 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_285 -> V_581 [ 8 ] ) << 8 ) |
V_285 -> V_581 [ 9 ] ;
V_547 =
( ( ( T_4 ) V_285 -> V_581 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_285 -> V_581 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_285 -> V_581 [ 12 ] ) << 8 ) |
V_285 -> V_581 [ 13 ] ;
break;
default:
return V_563 ;
}
V_602 = V_582 + V_547 - 1 ;
if ( V_559 && V_29 -> V_81 != 0 )
return V_563 ;
if ( V_602 >= F_136 ( V_220 -> V_415 ) ||
V_602 < V_582 )
return V_563 ;
V_603 = F_97 ( V_220 -> V_225 ) *
F_97 ( V_220 -> V_418 ) ;
V_418 = F_97 ( V_220 -> V_418 ) ;
#if V_626 == 32
V_627 = V_582 ;
( void ) F_250 ( V_627 , V_603 ) ;
V_604 = V_627 ;
V_627 = V_602 ;
( void ) F_250 ( V_627 , V_603 ) ;
V_605 = V_627 ;
V_606 = ( T_4 ) ( V_582 - ( V_604 * V_603 ) ) ;
V_607 = ( T_4 ) ( V_602 - ( V_605 * V_603 ) ) ;
V_627 = V_606 ;
( void ) F_250 ( V_627 , V_418 ) ;
V_608 = V_627 ;
V_627 = V_607 ;
( void ) F_250 ( V_627 , V_418 ) ;
V_609 = V_627 ;
#else
V_604 = V_582 / V_603 ;
V_605 = V_602 / V_603 ;
V_606 = ( T_4 ) ( V_582 - ( V_604 * V_603 ) ) ;
V_607 = ( T_4 ) ( V_602 - ( V_605 * V_603 ) ) ;
V_608 = V_606 / V_418 ;
V_609 = V_607 / V_418 ;
#endif
if ( ( V_604 != V_605 ) || ( V_608 != V_609 ) )
return V_563 ;
V_224 = F_97 ( V_220 -> V_225 ) +
F_97 ( V_220 -> V_226 ) ;
V_622 = ( ( T_4 ) ( V_604 >> V_220 -> V_417 ) ) %
F_97 ( V_220 -> V_228 ) ;
V_600 = ( V_622 * V_224 ) + V_608 ;
switch ( V_29 -> V_81 ) {
case V_628 :
break;
case V_629 :
F_76 ( F_97 ( V_220 -> V_229 ) != 2 ) ;
if ( V_29 -> V_188 )
V_600 += F_97 ( V_220 -> V_225 ) ;
V_29 -> V_188 = ! V_29 -> V_188 ;
break;
case V_630 :
F_76 ( F_97 ( V_220 -> V_229 ) != 3 ) ;
V_188 = V_29 -> V_188 ;
F_248 ( V_220 , V_188 ,
& V_600 , & V_601 ) ;
V_188 =
( V_188 >=
F_97 ( V_220 -> V_229 ) - 1 )
? 0 : V_188 + 1 ;
V_29 -> V_188 = V_188 ;
break;
case V_631 :
case V_632 :
if ( F_97 ( V_220 -> V_229 ) <= 1 )
break;
V_612 =
F_97 ( V_220 -> V_418 ) *
F_97 ( V_220 -> V_225 ) ;
F_76 ( V_612 == 0 ) ;
V_619 = V_612 *
F_97 ( V_220 -> V_229 ) ;
#if V_626 == 32
V_627 = V_582 ;
V_620 = F_250 ( V_627 , V_619 ) ;
V_627 = V_620 ;
( void ) F_250 ( V_627 , V_612 ) ;
V_620 = V_627 ;
V_627 = V_602 ;
V_621 = F_250 ( V_627 , V_619 ) ;
V_627 = V_621 ;
( void ) F_250 ( V_627 , V_612 ) ;
V_621 = V_627 ;
#else
V_620 = ( V_582 % V_619 ) / V_612 ;
V_621 = ( V_602 % V_619 ) / V_612 ;
#endif
if ( V_620 != V_621 )
return V_563 ;
#if V_626 == 32
V_627 = V_582 ;
( void ) F_250 ( V_627 , V_619 ) ;
V_604 = V_613 = V_610 = V_627 ;
V_627 = V_602 ;
( void ) F_250 ( V_627 , V_619 ) ;
V_614 = V_611 = V_627 ;
#else
V_604 = V_613 = V_610 =
V_582 / V_619 ;
V_614 = V_611 = V_602 / V_619 ;
#endif
if ( V_613 != V_614 )
return V_563 ;
#if V_626 == 32
V_627 = V_582 ;
V_606 = F_250 ( V_627 , V_619 ) ;
V_627 = V_606 ;
V_606 = ( T_4 ) F_250 ( V_627 , V_612 ) ;
V_615 = V_606 ;
V_627 = V_602 ;
V_616 = F_250 ( V_627 , V_619 ) ;
V_627 = V_616 ;
V_616 = F_250 ( V_627 , V_612 ) ;
V_627 = V_615 ;
( void ) F_250 ( V_627 , V_220 -> V_418 ) ;
V_608 = V_617 = V_627 ;
V_627 = V_616 ;
( void ) F_250 ( V_627 , V_220 -> V_418 ) ;
V_618 = V_627 ;
#else
V_606 = V_615 =
( T_4 ) ( ( V_582 % V_619 ) %
V_612 ) ;
V_616 =
( T_4 ) ( ( V_602 % V_619 ) %
V_612 ) ;
V_608 = V_617 =
V_615 / F_97 ( V_220 -> V_418 ) ;
V_618 =
V_616 / F_97 ( V_220 -> V_418 ) ;
#endif
if ( V_617 != V_618 )
return V_563 ;
V_622 = ( ( T_4 ) ( V_604 >> V_220 -> V_417 ) ) %
F_97 ( V_220 -> V_228 ) ;
V_600 = ( V_620 *
( F_97 ( V_220 -> V_228 ) * V_224 ) ) +
( V_622 * V_224 ) + V_608 ;
break;
default:
return V_563 ;
}
if ( F_45 ( V_600 >= V_232 ) )
return V_563 ;
V_9 -> V_234 = V_29 -> V_234 [ V_600 ] ;
if ( ! V_9 -> V_234 )
return V_563 ;
V_623 = V_222 [ V_600 ] . V_186 ;
V_624 = F_136 ( V_220 -> V_419 ) +
V_604 * F_97 ( V_220 -> V_418 ) +
( V_606 - V_608 *
F_97 ( V_220 -> V_418 ) ) ;
V_625 = V_547 ;
if ( V_220 -> V_416 ) {
V_624 <<= V_220 -> V_416 ;
V_625 <<= V_220 -> V_416 ;
}
F_76 ( V_625 > 0xffff ) ;
if ( V_624 > 0xffffffff ) {
V_140 [ 0 ] = V_559 ? V_557 : V_556 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_624 >> 56 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_624 >> 48 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_624 >> 40 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_624 >> 32 ) ;
V_140 [ 6 ] = ( T_1 ) ( V_624 >> 24 ) ;
V_140 [ 7 ] = ( T_1 ) ( V_624 >> 16 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_624 >> 8 ) ;
V_140 [ 9 ] = ( T_1 ) ( V_624 ) ;
V_140 [ 10 ] = ( T_1 ) ( V_625 >> 24 ) ;
V_140 [ 11 ] = ( T_1 ) ( V_625 >> 16 ) ;
V_140 [ 12 ] = ( T_1 ) ( V_625 >> 8 ) ;
V_140 [ 13 ] = ( T_1 ) ( V_625 ) ;
V_140 [ 14 ] = 0 ;
V_140 [ 15 ] = 0 ;
V_543 = 16 ;
} else {
V_140 [ 0 ] = V_559 ? V_549 : V_548 ;
V_140 [ 1 ] = 0 ;
V_140 [ 2 ] = ( T_1 ) ( V_624 >> 24 ) ;
V_140 [ 3 ] = ( T_1 ) ( V_624 >> 16 ) ;
V_140 [ 4 ] = ( T_1 ) ( V_624 >> 8 ) ;
V_140 [ 5 ] = ( T_1 ) ( V_624 ) ;
V_140 [ 6 ] = 0 ;
V_140 [ 7 ] = ( T_1 ) ( V_625 >> 8 ) ;
V_140 [ 8 ] = ( T_1 ) ( V_625 ) ;
V_140 [ 9 ] = 0 ;
V_543 = 10 ;
}
return F_244 ( V_21 , V_9 , V_623 , V_140 , V_543 ,
V_29 -> V_70 ,
V_29 -> V_234 [ V_600 ] ) ;
}
static int F_251 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
unsigned char V_70 [] )
{
V_285 -> V_633 = ( unsigned char * ) V_9 ;
V_9 -> V_149 = V_340 ;
V_9 -> V_10 = V_285 ;
V_9 -> V_123 . V_127 = 0 ;
memcpy ( & V_9 -> V_123 . V_349 . V_350 [ 0 ] , & V_70 [ 0 ] , 8 ) ;
V_9 -> V_123 . V_348 = F_134 ( ( V_9 -> V_132 << V_597 ) ) ;
V_9 -> V_143 . V_634 = 0 ;
F_76 ( V_285 -> V_568 > sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_345 = V_285 -> V_568 ;
memcpy ( V_9 -> V_143 . V_144 , V_285 -> V_581 , V_285 -> V_568 ) ;
switch ( V_285 -> V_571 ) {
case V_572 :
V_9 -> V_143 . V_635 =
F_252 ( V_394 , V_636 , V_637 ) ;
break;
case V_574 :
V_9 -> V_143 . V_635 =
F_252 ( V_394 , V_636 , V_638 ) ;
break;
case V_576 :
V_9 -> V_143 . V_635 =
F_252 ( V_394 , V_636 , V_639 ) ;
break;
case V_640 :
V_9 -> V_143 . V_635 =
F_252 ( V_394 , V_636 , V_641 ) ;
break;
default:
F_74 ( & V_21 -> V_28 -> V_29 , L_162 ,
V_285 -> V_571 ) ;
F_177 () ;
break;
}
if ( F_234 ( V_21 , V_9 , V_285 ) < 0 ) {
F_147 ( V_21 , V_9 ) ;
return V_642 ;
}
F_61 ( V_21 , V_9 ) ;
return 0 ;
}
static void F_253 ( struct V_1 * V_21 , int V_198 ,
struct V_8 * V_9 )
{
V_373 V_643 , V_644 ;
memset ( V_9 , 0 , F_247 ( struct V_8 , V_238 ) ) ;
V_9 -> V_123 . V_348 = F_134 ( ( T_5 ) ( V_198 << V_597 ) ) ;
V_643 = V_21 -> V_645 + V_198 * sizeof( * V_9 ) ;
V_9 -> V_23 = V_21 -> V_646 + V_198 ;
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_644 = V_21 -> V_647
+ V_198 * sizeof( * V_9 -> V_23 ) ;
V_9 -> V_132 = V_198 ;
V_9 -> V_121 = ( T_4 ) V_643 ;
V_9 -> V_648 . V_283 = F_134 ( ( T_5 ) V_644 ) ;
V_9 -> V_648 . V_282 = F_139 ( ( T_4 ) sizeof( * V_9 -> V_23 ) ) ;
V_9 -> V_21 = V_21 ;
V_9 -> V_10 = V_11 ;
}
static void F_254 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_237 + V_67 ;
F_253 ( V_21 , V_67 , V_9 ) ;
F_122 ( & V_9 -> V_238 , 0 ) ;
}
}
static inline void F_255 ( struct V_1 * V_21 , int V_198 ,
struct V_8 * V_9 )
{
V_373 V_643 = V_21 -> V_645 + V_198 * sizeof( * V_9 ) ;
F_76 ( V_9 -> V_132 != V_198 ) ;
memset ( V_9 -> V_143 . V_144 , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_9 -> V_121 = ( T_4 ) V_643 ;
}
static int F_256 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_284 * V_285 ,
unsigned char * V_70 )
{
struct V_71 * V_29 = V_285 -> V_41 -> V_78 ;
int V_20 = V_563 ;
if ( ! V_29 )
return V_642 ;
V_285 -> V_633 = ( unsigned char * ) V_9 ;
if ( V_29 -> V_89 ) {
F_253 ( V_21 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_340 ;
V_9 -> V_10 = V_285 ;
V_20 = F_249 ( V_21 , V_9 ) ;
if ( V_20 < 0 )
V_20 = V_642 ;
} else if ( V_29 -> V_187 ) {
F_253 ( V_21 , V_9 -> V_132 , V_9 ) ;
V_9 -> V_149 = V_340 ;
V_9 -> V_10 = V_285 ;
V_20 = F_243 ( V_21 , V_9 ) ;
if ( V_20 < 0 )
V_20 = V_642 ;
}
return V_20 ;
}
static void V_327 ( struct V_649 * V_326 )
{
struct V_284 * V_285 ;
struct V_71 * V_29 ;
struct V_8 * V_9 = F_257 ( V_326 , struct V_8 , V_326 ) ;
V_285 = V_9 -> V_10 ;
V_29 = V_285 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_285 -> V_295 = V_317 << 16 ;
return F_149 ( V_9 -> V_21 , V_9 , V_285 ) ;
}
if ( V_9 -> V_12 )
return F_149 ( V_9 -> V_21 , V_9 , V_285 ) ;
if ( V_9 -> V_149 == V_153 ) {
struct V_1 * V_21 = V_9 -> V_21 ;
struct V_138 * V_286 = & V_21 -> V_136 [ V_9 -> V_132 ] ;
int V_20 ;
if ( V_286 -> V_290 . V_291 ==
V_304 ) {
V_20 = F_256 ( V_21 , V_9 , V_285 , V_29 -> V_70 ) ;
if ( V_20 == 0 )
return;
if ( V_20 == V_642 ) {
V_285 -> V_295 = V_650 << 16 ;
return F_149 ( V_21 , V_9 , V_285 ) ;
}
}
}
F_255 ( V_9 -> V_21 , V_9 -> V_132 , V_9 ) ;
if ( F_251 ( V_9 -> V_21 , V_9 , V_285 , V_29 -> V_70 ) ) {
V_285 -> V_295 = V_650 << 16 ;
V_285 -> V_325 ( V_285 ) ;
}
}
static int F_258 ( struct V_6 * V_7 , struct V_284 * V_285 )
{
struct V_1 * V_21 ;
struct V_71 * V_29 ;
unsigned char V_70 [ 8 ] ;
struct V_8 * V_9 ;
int V_20 = 0 ;
V_21 = F_1 ( V_285 -> V_41 ) ;
F_76 ( V_285 -> V_651 -> V_348 < 0 ) ;
V_29 = V_285 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
if ( V_29 -> V_190 ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
memcpy ( V_70 , V_29 -> V_70 , sizeof( V_70 ) ) ;
if ( F_45 ( F_13 ( V_21 ) ) ) {
V_285 -> V_295 = V_317 << 16 ;
V_285 -> V_325 ( V_285 ) ;
return 0 ;
}
V_9 = F_259 ( V_21 , V_285 ) ;
if ( F_48 ( V_285 -> V_652 == 0 &&
! F_260 ( V_285 -> V_651 ) &&
V_21 -> V_55 ) ) {
V_20 = F_256 ( V_21 , V_9 , V_285 , V_70 ) ;
if ( V_20 == 0 )
return 0 ;
if ( V_20 == V_642 ) {
F_147 ( V_21 , V_9 ) ;
return V_642 ;
}
}
return F_251 ( V_21 , V_9 , V_285 , V_70 ) ;
}
static void F_261 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
F_34 ( & V_21 -> V_653 , V_76 ) ;
V_21 -> V_654 = 1 ;
F_262 ( & V_21 -> V_655 ) ;
F_35 ( & V_21 -> V_653 , V_76 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_21 = F_3 ( V_7 ) ;
unsigned long V_76 ;
if ( F_45 ( F_13 ( V_21 ) ) )
return F_261 ( V_21 ) ;
F_34 ( & V_21 -> V_653 , V_76 ) ;
if ( V_21 -> V_656 ) {
F_35 ( & V_21 -> V_653 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_653 , V_76 ) ;
while ( 1 ) {
F_34 ( & V_21 -> V_653 , V_76 ) ;
if ( V_21 -> V_654 )
break;
V_21 -> V_656 = 1 ;
F_35 ( & V_21 -> V_653 , V_76 ) ;
F_180 ( V_21 -> V_655 , V_21 -> V_654 ) ;
}
V_21 -> V_654 = 0 ;
V_21 -> V_656 = 0 ;
F_35 ( & V_21 -> V_653 , V_76 ) ;
if ( F_45 ( F_13 ( V_21 ) ) )
return F_261 ( V_21 ) ;
F_34 ( & V_21 -> V_247 , V_76 ) ;
if ( V_21 -> V_248 ) {
V_21 -> V_249 = 1 ;
F_35 ( & V_21 -> V_247 , V_76 ) ;
F_261 ( V_21 ) ;
return;
}
F_35 ( & V_21 -> V_247 , V_76 ) ;
F_229 ( V_21 ) ;
F_261 ( V_21 ) ;
}
static int F_263 ( struct V_2 * V_3 , int V_231 )
{
struct V_71 * V_218 = V_3 -> V_78 ;
if ( ! V_218 )
return - V_79 ;
if ( V_231 < 1 )
V_231 = 1 ;
else if ( V_231 > V_218 -> V_189 )
V_231 = V_218 -> V_189 ;
return F_124 ( V_3 , V_231 ) ;
}
static int F_264 ( struct V_6 * V_7 ,
unsigned long V_657 )
{
struct V_1 * V_21 = F_3 ( V_7 ) ;
unsigned long V_76 ;
int V_658 ;
F_34 ( & V_21 -> V_653 , V_76 ) ;
V_658 = V_21 -> V_654 ;
F_35 ( & V_21 -> V_653 , V_76 ) ;
return V_658 ;
}
static int F_265 ( struct V_1 * V_21 )
{
struct V_6 * V_7 ;
V_7 = F_266 ( & V_659 , sizeof( V_21 ) ) ;
if ( V_7 == NULL ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_164 ) ;
return - V_262 ;
}
V_7 -> V_660 = 0 ;
V_7 -> V_661 = 0 ;
V_7 -> V_662 = - 1 ;
V_7 -> V_663 = 3 ;
V_7 -> V_664 = V_665 ;
V_7 -> V_666 = V_501 ;
V_7 -> V_667 = V_501 ;
V_7 -> V_259 = V_21 -> V_235 - V_668 ;
V_7 -> V_669 = V_7 -> V_259 ;
V_7 -> V_670 = V_21 -> V_263 ;
V_7 -> V_671 = V_672 ;
V_7 -> V_78 [ 0 ] = ( unsigned long ) V_21 ;
V_7 -> V_673 = F_267 ( V_21 -> V_28 , 0 ) ;
V_7 -> V_674 = V_7 -> V_673 ;
V_21 -> V_58 = V_7 ;
return 0 ;
}
static int F_268 ( struct V_1 * V_21 )
{
int V_675 ;
V_675 = F_269 ( V_21 -> V_58 , & V_21 -> V_28 -> V_29 ) ;
if ( V_675 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_165 ) ;
return V_675 ;
}
F_270 ( V_21 -> V_58 ) ;
return 0 ;
}
static int F_271 ( struct V_284 * V_676 )
{
int V_677 = V_676 -> V_651 -> V_348 ;
if ( V_677 < 0 )
return V_677 ;
return V_677 += V_668 ;
}
static int F_272 ( struct V_1 * V_21 ,
struct V_8 * V_9 , unsigned char V_678 [] ,
int V_112 )
{
int V_20 ;
( void ) F_175 ( V_9 , V_480 , V_21 ,
NULL , 0 , 0 , V_678 , V_394 ) ;
V_20 = F_166 ( V_21 , V_9 , V_112 , V_397 ) ;
if ( V_20 )
return V_20 ;
if ( V_9 -> V_23 -> V_35 == V_679 )
return 0 ;
if ( V_9 -> V_23 -> V_35 == V_36 &&
V_9 -> V_23 -> V_37 == V_296 &&
( V_9 -> V_23 -> V_25 [ 2 ] == V_680 ||
V_9 -> V_23 -> V_25 [ 2 ] == V_26 ) )
return 0 ;
return 1 ;
}
static int F_273 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
unsigned char V_678 [] , int V_112 )
{
int V_20 ;
int V_47 = 0 ;
int V_681 = 1 ;
for ( V_47 = 0 ; V_47 < V_682 ; V_47 ++ ) {
F_108 ( 1000 * V_681 ) ;
V_20 = F_272 ( V_21 , V_9 , V_678 , V_112 ) ;
if ( ! V_20 )
break;
if ( V_681 < V_683 )
V_681 *= 2 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_166 ,
V_681 ) ;
}
return V_20 ;
}
static int F_181 ( struct V_1 * V_21 ,
unsigned char V_678 [] ,
int V_112 )
{
int V_684 ;
int V_685 ;
int V_111 ;
int V_20 = 0 ;
struct V_8 * V_9 ;
V_9 = F_174 ( V_21 ) ;
if ( V_112 == V_126 ) {
V_684 = 0 ;
V_685 = V_21 -> V_128 - 1 ;
} else {
V_684 = V_112 ;
V_685 = V_112 ;
}
for ( V_111 = V_684 ; V_111 <= V_685 ; V_111 ++ ) {
V_20 = F_273 ( V_21 , V_9 , V_678 , V_111 ) ;
if ( V_20 )
break;
}
if ( V_20 )
F_9 ( & V_21 -> V_28 -> V_29 , L_167 ) ;
else
F_9 ( & V_21 -> V_28 -> V_29 , L_168 ) ;
F_106 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_274 ( struct V_284 * V_686 )
{
int V_20 = V_687 ;
struct V_1 * V_21 ;
struct V_71 * V_29 ;
T_1 V_398 ;
char V_688 [ 48 ] ;
unsigned long V_76 ;
V_21 = F_1 ( V_686 -> V_41 ) ;
if ( V_21 == NULL )
return V_689 ;
F_34 ( & V_21 -> V_247 , V_76 ) ;
V_21 -> V_248 = 1 ;
F_35 ( & V_21 -> V_247 , V_76 ) ;
if ( F_13 ( V_21 ) ) {
V_20 = V_689 ;
goto V_690;
}
V_29 = V_686 -> V_41 -> V_78 ;
if ( ! V_29 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_169 , V_241 ) ;
V_20 = V_689 ;
goto V_690;
}
if ( V_29 -> V_104 == V_165 ) {
V_20 = V_687 ;
goto V_690;
}
if ( F_13 ( V_21 ) ) {
snprintf ( V_688 , sizeof( V_688 ) ,
L_170 ,
F_271 ( V_686 ) ) ;
F_70 ( V_242 , V_21 , V_29 , V_688 ) ;
V_20 = V_689 ;
goto V_690;
}
if ( F_275 ( V_21 ) ) {
snprintf ( V_688 , sizeof( V_688 ) ,
L_171 ,
F_271 ( V_686 ) ) ;
F_70 ( V_242 , V_21 , V_29 , V_688 ) ;
V_20 = V_689 ;
goto V_690;
}
if ( F_63 ( V_29 -> V_70 ) ) {
V_20 = V_687 ;
goto V_690;
}
if ( F_30 ( V_29 -> V_70 ) )
V_398 = V_691 ;
else
V_398 = V_692 ;
sprintf ( V_688 , L_172 ,
V_398 == V_691 ? L_173 : L_174 ) ;
F_70 ( V_242 , V_21 , V_29 , V_688 ) ;
V_20 = F_178 ( V_21 , V_29 , V_29 -> V_70 , V_398 ,
V_126 ) ;
if ( V_20 == 0 )
V_20 = V_687 ;
else
V_20 = V_689 ;
sprintf ( V_688 , L_175 ,
V_398 == V_691 ? L_173 : L_174 ,
V_20 == V_687 ? L_176 : L_177 ) ;
F_70 ( V_242 , V_21 , V_29 , V_688 ) ;
V_690:
F_34 ( & V_21 -> V_247 , V_76 ) ;
V_21 -> V_248 = 0 ;
F_35 ( & V_21 -> V_247 , V_76 ) ;
return V_20 ;
}
static struct V_8 * F_259 ( struct V_1 * V_21 ,
struct V_284 * V_676 )
{
int V_677 = F_271 ( V_676 ) ;
struct V_8 * V_9 = V_21 -> V_237 + V_677 ;
if ( V_677 < V_668 || V_677 >= V_21 -> V_235 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_178 ,
V_677 , V_668 , V_21 -> V_235 - 1 ) ;
F_177 () ;
}
F_56 ( & V_9 -> V_238 ) ;
if ( F_45 ( ! F_4 ( V_9 ) ) ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_179 ,
V_677 ) ;
if ( V_9 -> V_10 != NULL )
F_276 ( V_9 -> V_10 ) ;
F_276 ( V_676 ) ;
}
F_255 ( V_21 , V_677 , V_9 ) ;
return V_9 ;
}
static void F_148 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
( void ) F_46 ( & V_9 -> V_238 ) ;
}
static struct V_8 * F_174 ( struct V_1 * V_21 )
{
struct V_8 * V_9 ;
int V_238 , V_67 ;
int V_693 = 0 ;
for (; ; ) {
V_67 = F_277 ( V_21 -> V_694 ,
V_668 ,
V_693 ) ;
if ( F_45 ( V_67 >= V_668 ) ) {
V_693 = 0 ;
continue;
}
V_9 = V_21 -> V_237 + V_67 ;
V_238 = F_104 ( & V_9 -> V_238 ) ;
if ( F_45 ( V_238 > 1 ) ) {
F_106 ( V_21 , V_9 ) ;
V_693 = ( V_67 + 1 ) % V_668 ;
continue;
}
F_278 ( V_67 & ( V_626 - 1 ) ,
V_21 -> V_694 + ( V_67 / V_626 ) ) ;
break;
}
F_255 ( V_21 , V_67 , V_9 ) ;
return V_9 ;
}
static void F_106 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
if ( F_58 ( & V_9 -> V_238 ) ) {
int V_67 ;
V_67 = V_9 - V_21 -> V_237 ;
F_279 ( V_67 & ( V_626 - 1 ) ,
V_21 -> V_694 + ( V_67 / V_626 ) ) ;
}
}
static int F_280 ( struct V_2 * V_29 , int V_285 ,
void T_7 * V_695 )
{
T_8 T_7 * V_696 =
( T_8 T_7 * ) V_695 ;
T_9 V_697 ;
T_9 T_7 * V_698 = F_281 ( sizeof( V_697 ) ) ;
int V_699 ;
T_4 V_130 ;
memset ( & V_697 , 0 , sizeof( V_697 ) ) ;
V_699 = 0 ;
V_699 |= F_282 ( & V_697 . V_700 , & V_696 -> V_700 ,
sizeof( V_697 . V_700 ) ) ;
V_699 |= F_282 ( & V_697 . V_143 , & V_696 -> V_143 ,
sizeof( V_697 . V_143 ) ) ;
V_699 |= F_282 ( & V_697 . V_701 , & V_696 -> V_701 ,
sizeof( V_697 . V_701 ) ) ;
V_699 |= F_283 ( V_697 . V_702 , & V_696 -> V_702 ) ;
V_699 |= F_283 ( V_130 , & V_696 -> V_44 ) ;
V_697 . V_44 = F_284 ( V_130 ) ;
V_699 |= F_285 ( V_698 , & V_697 , sizeof( V_697 ) ) ;
if ( V_699 )
return - V_703 ;
V_699 = F_286 ( V_29 , V_704 , V_698 ) ;
if ( V_699 )
return V_699 ;
V_699 |= F_287 ( & V_696 -> V_701 , & V_698 -> V_701 ,
sizeof( V_696 -> V_701 ) ) ;
if ( V_699 )
return - V_703 ;
return V_699 ;
}
static int F_288 ( struct V_2 * V_29 ,
int V_285 , void T_7 * V_695 )
{
T_10 T_7 * V_696 =
( T_10 T_7 * ) V_695 ;
T_11 V_697 ;
T_11 T_7 * V_698 =
F_281 ( sizeof( V_697 ) ) ;
int V_699 ;
T_4 V_130 ;
memset ( & V_697 , 0 , sizeof( V_697 ) ) ;
V_699 = 0 ;
V_699 |= F_282 ( & V_697 . V_700 , & V_696 -> V_700 ,
sizeof( V_697 . V_700 ) ) ;
V_699 |= F_282 ( & V_697 . V_143 , & V_696 -> V_143 ,
sizeof( V_697 . V_143 ) ) ;
V_699 |= F_282 ( & V_697 . V_701 , & V_696 -> V_701 ,
sizeof( V_697 . V_701 ) ) ;
V_699 |= F_283 ( V_697 . V_702 , & V_696 -> V_702 ) ;
V_699 |= F_283 ( V_697 . V_705 , & V_696 -> V_705 ) ;
V_699 |= F_283 ( V_130 , & V_696 -> V_44 ) ;
V_697 . V_44 = F_284 ( V_130 ) ;
V_699 |= F_285 ( V_698 , & V_697 , sizeof( V_697 ) ) ;
if ( V_699 )
return - V_703 ;
V_699 = F_286 ( V_29 , V_706 , V_698 ) ;
if ( V_699 )
return V_699 ;
V_699 |= F_287 ( & V_696 -> V_701 , & V_698 -> V_701 ,
sizeof( V_696 -> V_701 ) ) ;
if ( V_699 )
return - V_703 ;
return V_699 ;
}
static int F_289 ( struct V_2 * V_29 , int V_285 , void T_7 * V_695 )
{
switch ( V_285 ) {
case V_707 :
case V_708 :
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
return F_286 ( V_29 , V_285 , V_695 ) ;
case V_722 :
return F_280 ( V_29 , V_285 , V_695 ) ;
case V_723 :
return F_288 ( V_29 , V_285 , V_695 ) ;
default:
return - V_724 ;
}
}
static int F_290 ( struct V_1 * V_21 , void T_7 * V_725 )
{
struct V_726 V_727 ;
if ( ! V_725 )
return - V_54 ;
V_727 . V_728 = F_291 ( V_21 -> V_28 -> V_101 ) ;
V_727 . V_101 = V_21 -> V_28 -> V_101 -> V_729 ;
V_727 . V_730 = V_21 -> V_28 -> V_731 ;
V_727 . V_66 = V_21 -> V_66 ;
if ( F_285 ( V_725 , & V_727 , sizeof( V_727 ) ) )
return - V_703 ;
return 0 ;
}
static int F_292 ( struct V_1 * V_21 , void T_7 * V_725 )
{
T_12 V_732 ;
unsigned char V_733 , V_734 , V_735 ;
int V_20 ;
V_20 = sscanf ( V_736 , L_180 ,
& V_733 , & V_734 , & V_735 ) ;
if ( V_20 != 3 ) {
F_95 ( & V_21 -> V_28 -> V_29 , L_181
L_182 , V_736 ) ;
V_733 = 0 ;
V_734 = 0 ;
V_735 = 0 ;
}
V_732 = ( V_733 << 16 ) | ( V_734 << 8 ) | V_735 ;
if ( ! V_725 )
return - V_54 ;
if ( F_285 ( V_725 , & V_732 , sizeof( T_12 ) ) )
return - V_703 ;
return 0 ;
}
static int F_293 ( struct V_1 * V_21 , void T_7 * V_725 )
{
T_9 V_737 ;
struct V_8 * V_9 ;
char * V_738 = NULL ;
T_5 V_268 ;
int V_20 = 0 ;
if ( ! V_725 )
return - V_54 ;
if ( ! F_15 ( V_52 ) )
return - V_739 ;
if ( F_282 ( & V_737 , V_725 , sizeof( V_737 ) ) )
return - V_703 ;
if ( ( V_737 . V_702 < 1 ) &&
( V_737 . V_143 . Type . V_740 != V_639 ) ) {
return - V_54 ;
}
if ( V_737 . V_702 > 0 ) {
V_738 = F_92 ( V_737 . V_702 , V_202 ) ;
if ( V_738 == NULL )
return - V_262 ;
if ( V_737 . V_143 . Type . V_740 & V_637 ) {
if ( F_282 ( V_738 , V_737 . V_44 ,
V_737 . V_702 ) ) {
V_20 = - V_703 ;
goto V_741;
}
} else {
memset ( V_738 , 0 , V_737 . V_702 ) ;
}
}
V_9 = F_174 ( V_21 ) ;
V_9 -> V_149 = V_402 ;
V_9 -> V_10 = V_742 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_737 . V_702 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_281 = F_158 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_281 = F_158 ( 0 ) ;
}
memcpy ( & V_9 -> V_123 . V_349 , & V_737 . V_700 , sizeof( V_9 -> V_123 . V_349 ) ) ;
memcpy ( & V_9 -> V_143 , & V_737 . V_143 ,
sizeof( V_9 -> V_143 ) ) ;
if ( V_737 . V_702 > 0 ) {
V_268 = F_132 ( V_21 -> V_28 , V_738 ,
V_737 . V_702 , V_743 ) ;
if ( F_133 ( & V_21 -> V_28 -> V_29 , ( V_373 ) V_268 ) ) {
V_9 -> V_277 [ 0 ] . V_283 = F_134 ( 0 ) ;
V_9 -> V_277 [ 0 ] . V_282 = F_139 ( 0 ) ;
V_20 = - V_262 ;
goto V_395;
}
V_9 -> V_277 [ 0 ] . V_283 = F_134 ( V_268 ) ;
V_9 -> V_277 [ 0 ] . V_282 = F_139 ( V_737 . V_702 ) ;
V_9 -> V_277 [ 0 ] . V_279 = F_139 ( V_377 ) ;
}
V_20 = F_166 ( V_21 , V_9 , V_126 ,
V_381 ) ;
if ( V_737 . V_702 > 0 )
F_159 ( V_21 -> V_28 , V_9 , 1 , V_743 ) ;
F_294 ( V_21 , V_9 ) ;
if ( V_20 ) {
V_20 = - V_388 ;
goto V_395;
}
memcpy ( & V_737 . V_701 , V_9 -> V_23 ,
sizeof( V_737 . V_701 ) ) ;
if ( F_285 ( V_725 , & V_737 , sizeof( V_737 ) ) ) {
V_20 = - V_703 ;
goto V_395;
}
if ( ( V_737 . V_143 . Type . V_740 & V_638 ) &&
V_737 . V_702 > 0 ) {
if ( F_285 ( V_737 . V_44 , V_738 , V_737 . V_702 ) ) {
V_20 = - V_703 ;
goto V_395;
}
}
V_395:
F_106 ( V_21 , V_9 ) ;
V_741:
F_81 ( V_738 ) ;
return V_20 ;
}
static int F_295 ( struct V_1 * V_21 , void T_7 * V_725 )
{
T_11 * V_744 ;
struct V_8 * V_9 ;
unsigned char * * V_738 = NULL ;
int * V_745 = NULL ;
T_5 V_268 ;
T_13 V_371 = 0 ;
int V_48 = 0 ;
T_4 V_746 ;
T_4 V_747 ;
T_13 T_7 * V_748 ;
if ( ! V_725 )
return - V_54 ;
if ( ! F_15 ( V_52 ) )
return - V_739 ;
V_744 = F_92 ( sizeof( * V_744 ) , V_202 ) ;
if ( ! V_744 ) {
V_48 = - V_262 ;
goto V_749;
}
if ( F_282 ( V_744 , V_725 , sizeof( * V_744 ) ) ) {
V_48 = - V_703 ;
goto V_749;
}
if ( ( V_744 -> V_702 < 1 ) &&
( V_744 -> V_143 . Type . V_740 != V_639 ) ) {
V_48 = - V_54 ;
goto V_749;
}
if ( V_744 -> V_705 > V_750 ) {
V_48 = - V_54 ;
goto V_749;
}
if ( V_744 -> V_702 > V_744 -> V_705 * V_751 ) {
V_48 = - V_54 ;
goto V_749;
}
V_738 = F_115 ( V_751 * sizeof( char * ) , V_202 ) ;
if ( ! V_738 ) {
V_48 = - V_262 ;
goto V_749;
}
V_745 = F_92 ( V_751 * sizeof( int ) , V_202 ) ;
if ( ! V_745 ) {
V_48 = - V_262 ;
goto V_749;
}
V_746 = V_744 -> V_702 ;
V_748 = V_744 -> V_44 ;
while ( V_746 ) {
V_747 = ( V_746 > V_744 -> V_705 ) ? V_744 -> V_705 : V_746 ;
V_745 [ V_371 ] = V_747 ;
V_738 [ V_371 ] = F_92 ( V_747 , V_202 ) ;
if ( V_738 [ V_371 ] == NULL ) {
V_48 = - V_262 ;
goto V_749;
}
if ( V_744 -> V_143 . Type . V_740 & V_637 ) {
if ( F_282 ( V_738 [ V_371 ] , V_748 , V_747 ) ) {
V_48 = - V_703 ;
goto V_749;
}
} else
memset ( V_738 [ V_371 ] , 0 , V_747 ) ;
V_746 -= V_747 ;
V_748 += V_747 ;
V_371 ++ ;
}
V_9 = F_174 ( V_21 ) ;
V_9 -> V_149 = V_402 ;
V_9 -> V_10 = V_742 ;
V_9 -> V_123 . V_127 = 0 ;
V_9 -> V_123 . V_124 = ( T_1 ) V_371 ;
V_9 -> V_123 . V_281 = F_158 ( V_371 ) ;
memcpy ( & V_9 -> V_123 . V_349 , & V_744 -> V_700 , sizeof( V_9 -> V_123 . V_349 ) ) ;
memcpy ( & V_9 -> V_143 , & V_744 -> V_143 , sizeof( V_9 -> V_143 ) ) ;
if ( V_744 -> V_702 > 0 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_371 ; V_67 ++ ) {
V_268 = F_132 ( V_21 -> V_28 , V_738 [ V_67 ] ,
V_745 [ V_67 ] , V_743 ) ;
if ( F_133 ( & V_21 -> V_28 -> V_29 ,
( V_373 ) V_268 ) ) {
V_9 -> V_277 [ V_67 ] . V_283 = F_134 ( 0 ) ;
V_9 -> V_277 [ V_67 ] . V_282 = F_139 ( 0 ) ;
F_159 ( V_21 -> V_28 , V_9 , V_67 ,
V_743 ) ;
V_48 = - V_262 ;
goto V_752;
}
V_9 -> V_277 [ V_67 ] . V_283 = F_134 ( V_268 ) ;
V_9 -> V_277 [ V_67 ] . V_282 = F_139 ( V_745 [ V_67 ] ) ;
V_9 -> V_277 [ V_67 ] . V_279 = F_139 ( 0 ) ;
}
V_9 -> V_277 [ -- V_67 ] . V_279 = F_139 ( V_377 ) ;
}
V_48 = F_166 ( V_21 , V_9 , V_126 ,
V_381 ) ;
if ( V_371 )
F_159 ( V_21 -> V_28 , V_9 , V_371 , V_743 ) ;
F_294 ( V_21 , V_9 ) ;
if ( V_48 ) {
V_48 = - V_388 ;
goto V_752;
}
memcpy ( & V_744 -> V_701 , V_9 -> V_23 , sizeof( V_744 -> V_701 ) ) ;
if ( F_285 ( V_725 , V_744 , sizeof( * V_744 ) ) ) {
V_48 = - V_703 ;
goto V_752;
}
if ( ( V_744 -> V_143 . Type . V_740 & V_638 ) && V_744 -> V_702 > 0 ) {
int V_67 ;
T_13 T_7 * V_753 = V_744 -> V_44 ;
for ( V_67 = 0 ; V_67 < V_371 ; V_67 ++ ) {
if ( F_285 ( V_753 , V_738 [ V_67 ] , V_745 [ V_67 ] ) ) {
V_48 = - V_703 ;
goto V_752;
}
V_753 += V_745 [ V_67 ] ;
}
}
V_48 = 0 ;
V_752:
F_106 ( V_21 , V_9 ) ;
V_749:
if ( V_738 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_371 ; V_67 ++ )
F_81 ( V_738 [ V_67 ] ) ;
F_81 ( V_738 ) ;
}
F_81 ( V_745 ) ;
F_81 ( V_744 ) ;
return V_48 ;
}
static void F_294 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_23 -> V_35 == V_36 &&
V_9 -> V_23 -> V_37 != V_296 )
( void ) F_8 ( V_21 , V_9 ) ;
}
static int F_286 ( struct V_2 * V_29 , int V_285 , void T_7 * V_695 )
{
struct V_1 * V_21 ;
void T_7 * V_725 = ( void T_7 * ) V_695 ;
int V_20 ;
V_21 = F_1 ( V_29 ) ;
switch ( V_285 ) {
case V_717 :
case V_718 :
case V_719 :
F_18 ( V_21 -> V_58 ) ;
return 0 ;
case V_707 :
return F_290 ( V_21 , V_725 ) ;
case V_715 :
return F_292 ( V_21 , V_725 ) ;
case V_704 :
if ( F_296 ( & V_21 -> V_754 ) < 0 )
return - V_755 ;
V_20 = F_293 ( V_21 , V_725 ) ;
F_56 ( & V_21 -> V_754 ) ;
return V_20 ;
case V_706 :
if ( F_296 ( & V_21 -> V_754 ) < 0 )
return - V_755 ;
V_20 = F_295 ( V_21 , V_725 ) ;
F_56 ( & V_21 -> V_754 ) ;
return V_20 ;
default:
return - V_756 ;
}
}
static void F_297 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_1 V_398 )
{
struct V_8 * V_9 ;
V_9 = F_174 ( V_21 ) ;
( void ) F_175 ( V_9 , V_691 , V_21 , NULL , 0 , 0 ,
V_157 , V_399 ) ;
V_9 -> V_143 . V_144 [ 1 ] = V_398 ;
V_9 -> V_380 = NULL ;
F_61 ( V_21 , V_9 ) ;
return;
}
static int F_175 ( struct V_8 * V_9 , T_1 V_285 , struct V_1 * V_21 ,
void * V_738 , T_3 V_473 , T_6 V_757 , unsigned char * V_70 ,
int V_149 )
{
int V_758 = V_639 ;
V_9 -> V_149 = V_402 ;
V_9 -> V_10 = V_742 ;
V_9 -> V_123 . V_127 = 0 ;
if ( V_738 != NULL && V_473 > 0 ) {
V_9 -> V_123 . V_124 = 1 ;
V_9 -> V_123 . V_281 = F_158 ( 1 ) ;
} else {
V_9 -> V_123 . V_124 = 0 ;
V_9 -> V_123 . V_281 = F_158 ( 0 ) ;
}
memcpy ( V_9 -> V_123 . V_349 . V_350 , V_70 , 8 ) ;
if ( V_149 == V_394 ) {
switch ( V_285 ) {
case V_393 :
if ( V_757 & V_407 ) {
V_9 -> V_143 . V_144 [ 1 ] = 0x01 ;
V_9 -> V_143 . V_144 [ 2 ] = ( V_757 & 0xff ) ;
}
V_9 -> V_143 . V_345 = 6 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_393 ;
V_9 -> V_143 . V_144 [ 4 ] = V_473 & 0xFF ;
break;
case V_463 :
case V_464 :
V_9 -> V_143 . V_345 = 12 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_285 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_473 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_473 & 0xFF ;
break;
case V_759 :
V_9 -> V_143 . V_345 = 16 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 6 ] = V_759 ;
break;
case V_761 :
V_9 -> V_143 . V_345 = 16 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 ,
V_636 , V_637 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_761 ;
break;
case V_762 :
V_9 -> V_143 . V_345 = 12 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 ,
V_636 , V_637 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_141 ;
V_9 -> V_143 . V_144 [ 6 ] = V_763 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = V_473 & 0xFF ;
break;
case V_480 :
V_9 -> V_143 . V_345 = 6 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_639 ) ;
V_9 -> V_143 . V_634 = 0 ;
break;
case V_425 :
V_9 -> V_143 . V_345 = 12 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_764 ;
V_9 -> V_143 . V_144 [ 1 ] = V_285 ;
V_9 -> V_143 . V_144 [ 6 ] = ( V_473 >> 24 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 9 ] = V_473 & 0xFF ;
break;
case V_765 :
V_9 -> V_143 . V_345 = 10 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 6 ] = V_765 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0xFF ;
break;
case V_432 :
V_9 -> V_143 . V_345 = 10 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 6 ] = V_432 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_428 :
V_9 -> V_143 . V_345 = 10 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 6 ] = V_428 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_442 :
V_9 -> V_143 . V_345 = 10 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 6 ] = V_442 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
break;
case V_430 :
V_9 -> V_143 . V_345 = 10 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_638 ) ;
V_9 -> V_143 . V_634 = 0 ;
V_9 -> V_143 . V_144 [ 0 ] = V_760 ;
V_9 -> V_143 . V_144 [ 1 ] = 0 ;
V_9 -> V_143 . V_144 [ 2 ] = 0 ;
V_9 -> V_143 . V_144 [ 3 ] = 0 ;
V_9 -> V_143 . V_144 [ 4 ] = 0 ;
V_9 -> V_143 . V_144 [ 5 ] = 0 ;
V_9 -> V_143 . V_144 [ 6 ] = V_430 ;
V_9 -> V_143 . V_144 [ 7 ] = ( V_473 >> 16 ) & 0xFF ;
V_9 -> V_143 . V_144 [ 8 ] = ( V_473 >> 8 ) & 0XFF ;
V_9 -> V_143 . V_144 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_21 -> V_28 -> V_29 , L_183 , V_285 ) ;
F_177 () ;
return - 1 ;
}
} else if ( V_149 == V_399 ) {
switch ( V_285 ) {
case V_692 :
V_9 -> V_143 . V_345 = 16 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_639 ) ;
V_9 -> V_143 . V_634 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_766 ;
V_9 -> V_143 . V_144 [ 1 ] = V_767 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
case V_691 :
V_9 -> V_143 . V_345 = 16 ;
V_9 -> V_143 . V_635 =
F_252 ( V_149 , V_636 , V_639 ) ;
V_9 -> V_143 . V_634 = 0 ;
memset ( & V_9 -> V_143 . V_144 [ 0 ] , 0 , sizeof( V_9 -> V_143 . V_144 ) ) ;
V_9 -> V_143 . V_144 [ 0 ] = V_285 ;
V_9 -> V_143 . V_144 [ 1 ] = V_768 ;
V_9 -> V_143 . V_144 [ 4 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 5 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 6 ] = 0x00 ;
V_9 -> V_143 . V_144 [ 7 ] = 0x00 ;
break;
default:
F_9 ( & V_21 -> V_28 -> V_29 , L_184 ,
V_285 ) ;
F_177 () ;
}
} else {
F_9 ( & V_21 -> V_28 -> V_29 , L_185 , V_149 ) ;
F_177 () ;
}
switch ( F_298 ( V_9 -> V_143 . V_635 ) ) {
case V_638 :
V_758 = V_396 ;
break;
case V_637 :
V_758 = V_272 ;
break;
case V_639 :
V_758 = V_376 ;
break;
default:
V_758 = V_743 ;
}
if ( F_160 ( V_21 -> V_28 , V_9 , V_738 , V_473 , V_758 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_299 ( T_15 V_769 , T_15 V_473 )
{
T_15 V_770 = ( ( T_15 ) V_769 ) & V_771 ;
T_15 V_772 = ( ( T_15 ) V_769 ) - V_770 ;
void T_14 * V_773 = F_300 ( V_770 ,
V_772 + V_473 ) ;
return V_773 ? ( V_773 + V_772 ) : NULL ;
}
static inline unsigned long F_301 ( struct V_1 * V_21 , T_1 V_109 )
{
return V_21 -> V_114 . V_115 ( V_21 , V_109 ) ;
}
static inline bool F_302 ( struct V_1 * V_21 )
{
return V_21 -> V_114 . V_774 ( V_21 ) ;
}
static inline long F_303 ( struct V_1 * V_21 )
{
return ( V_21 -> V_114 . V_774 ( V_21 ) == 0 ) ||
( V_21 -> V_775 == 0 ) ;
}
static inline int F_304 ( struct V_1 * V_21 , T_4 V_776 ,
T_4 V_777 )
{
if ( F_45 ( V_776 >= V_21 -> V_235 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_186 , V_777 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_62 ( struct V_8 * V_9 )
{
F_57 ( V_9 -> V_21 , V_9 ) ;
if ( F_48 ( V_9 -> V_149 == V_150 || V_9 -> V_149 == V_340
|| V_9 -> V_149 == V_153 ) )
F_155 ( V_9 ) ;
else if ( V_9 -> V_149 == V_402 || V_9 -> V_149 == V_155 )
F_305 ( V_9 -> V_380 ) ;
}
static inline void F_306 ( struct V_1 * V_21 ,
T_4 V_777 )
{
T_4 V_776 ;
struct V_8 * V_9 ;
V_776 = V_777 >> V_597 ;
if ( ! F_304 ( V_21 , V_776 , V_777 ) ) {
V_9 = V_21 -> V_237 + V_776 ;
F_62 ( V_9 ) ;
}
}
static int F_307 ( struct V_1 * V_21 )
{
if ( F_48 ( ! V_778 ) )
return 0 ;
if ( F_48 ( V_21 -> V_775 ) )
return 0 ;
F_95 ( & V_21 -> V_28 -> V_29 , L_187
L_188 ) ;
return 1 ;
}
static struct V_1 * F_308 ( T_1 * V_779 )
{
return F_257 ( ( V_779 - * V_779 ) , struct V_1 , V_109 [ 0 ] ) ;
}
static T_16 F_309 ( int V_673 , void * V_779 )
{
struct V_1 * V_21 = F_308 ( V_779 ) ;
T_1 V_109 = * ( T_1 * ) V_779 ;
T_4 V_777 ;
if ( F_307 ( V_21 ) )
return V_780 ;
if ( F_303 ( V_21 ) )
return V_780 ;
V_21 -> V_781 = F_310 () ;
while ( F_302 ( V_21 ) ) {
V_777 = F_301 ( V_21 , V_109 ) ;
while ( V_777 != V_119 )
V_777 = F_44 ( V_21 , V_109 ) ;
}
return V_782 ;
}
static T_16 F_311 ( int V_673 , void * V_779 )
{
struct V_1 * V_21 = F_308 ( V_779 ) ;
T_4 V_777 ;
T_1 V_109 = * ( T_1 * ) V_779 ;
if ( F_307 ( V_21 ) )
return V_780 ;
V_21 -> V_781 = F_310 () ;
V_777 = F_301 ( V_21 , V_109 ) ;
while ( V_777 != V_119 )
V_777 = F_44 ( V_21 , V_109 ) ;
return V_782 ;
}
static T_16 F_312 ( int V_673 , void * V_779 )
{
struct V_1 * V_21 = F_308 ( ( T_1 * ) V_779 ) ;
T_4 V_777 ;
T_1 V_109 = * ( T_1 * ) V_779 ;
if ( F_303 ( V_21 ) )
return V_780 ;
V_21 -> V_781 = F_310 () ;
while ( F_302 ( V_21 ) ) {
V_777 = F_301 ( V_21 , V_109 ) ;
while ( V_777 != V_119 ) {
F_306 ( V_21 , V_777 ) ;
V_777 = F_44 ( V_21 , V_109 ) ;
}
}
return V_782 ;
}
static T_16 F_313 ( int V_673 , void * V_779 )
{
struct V_1 * V_21 = F_308 ( V_779 ) ;
T_4 V_777 ;
T_1 V_109 = * ( T_1 * ) V_779 ;
V_21 -> V_781 = F_310 () ;
V_777 = F_301 ( V_21 , V_109 ) ;
while ( V_777 != V_119 ) {
F_306 ( V_21 , V_777 ) ;
V_777 = F_44 ( V_21 , V_109 ) ;
}
return V_782 ;
}
static int F_314 ( struct V_370 * V_28 , unsigned char V_783 ,
unsigned char type )
{
struct V_784 {
struct V_785 V_786 ;
struct V_787 V_143 ;
struct V_788 V_789 ;
};
struct V_784 * V_285 ;
static const T_3 V_790 = sizeof( * V_285 ) +
sizeof( V_285 -> V_789 ) ;
V_373 V_791 ;
T_17 V_792 ;
T_4 V_348 ;
void T_14 * V_151 ;
int V_67 , V_699 ;
V_151 = F_315 ( V_28 , 0 ) ;
if ( V_151 == NULL )
return - V_262 ;
V_699 = F_316 ( V_28 , F_317 ( 32 ) ) ;
if ( V_699 ) {
F_318 ( V_151 ) ;
return V_699 ;
}
V_285 = F_319 ( V_28 , V_790 , & V_791 ) ;
if ( V_285 == NULL ) {
F_318 ( V_151 ) ;
return - V_262 ;
}
V_792 = F_139 ( V_791 ) ;
V_285 -> V_786 . V_127 = 0 ;
V_285 -> V_786 . V_124 = 0 ;
V_285 -> V_786 . V_281 = F_158 ( 0 ) ;
V_285 -> V_786 . V_348 = F_134 ( V_791 ) ;
memset ( & V_285 -> V_786 . V_349 . V_350 , 0 , 8 ) ;
V_285 -> V_143 . V_345 = 16 ;
V_285 -> V_143 . V_635 =
F_252 ( V_399 , V_793 , V_639 ) ;
V_285 -> V_143 . V_634 = 0 ;
V_285 -> V_143 . V_144 [ 0 ] = V_783 ;
V_285 -> V_143 . V_144 [ 1 ] = type ;
memset ( & V_285 -> V_143 . V_144 [ 2 ] , 0 , 14 ) ;
V_285 -> V_789 . V_283 =
F_134 ( ( F_131 ( V_792 ) + sizeof( * V_285 ) ) ) ;
V_285 -> V_789 . V_282 = F_139 ( sizeof( struct V_337 ) ) ;
F_60 ( F_131 ( V_792 ) , V_151 + V_152 ) ;
for ( V_67 = 0 ; V_67 < V_794 ; V_67 ++ ) {
V_348 = F_320 ( V_151 + V_795 ) ;
if ( ( V_348 & ~ V_796 ) == V_791 )
break;
F_108 ( V_797 ) ;
}
F_318 ( V_151 ) ;
if ( V_67 == V_794 ) {
F_74 ( & V_28 -> V_29 , L_189 ,
V_783 , type ) ;
return - V_383 ;
}
F_321 ( V_28 , V_790 , V_285 , V_791 ) ;
if ( V_348 & V_798 ) {
F_74 ( & V_28 -> V_29 , L_190 ,
V_783 , type ) ;
return - V_388 ;
}
F_95 ( & V_28 -> V_29 , L_191 ,
V_783 , type ) ;
return 0 ;
}
static int F_322 ( struct V_370 * V_28 ,
void T_14 * V_151 , T_4 V_799 )
{
if ( V_799 ) {
F_95 ( & V_28 -> V_29 , L_192 ) ;
F_60 ( V_799 , V_151 + V_800 ) ;
F_108 ( 10000 ) ;
} else {
int V_20 = 0 ;
F_95 ( & V_28 -> V_29 , L_193 ) ;
V_20 = F_323 ( V_28 , V_801 ) ;
if ( V_20 )
return V_20 ;
F_108 ( 500 ) ;
V_20 = F_323 ( V_28 , V_802 ) ;
if ( V_20 )
return V_20 ;
F_108 ( 500 ) ;
}
return 0 ;
}
static void F_324 ( char * V_803 , int V_49 )
{
memset ( V_803 , 0 , V_49 ) ;
strncpy ( V_803 , V_40 L_194 V_736 , V_49 - 1 ) ;
}
static int F_325 ( struct V_804 T_14 * V_805 )
{
char * V_803 ;
int V_67 , V_473 = sizeof( V_805 -> V_803 ) ;
V_803 = F_92 ( V_473 , V_202 ) ;
if ( ! V_803 )
return - V_262 ;
F_324 ( V_803 , V_473 ) ;
for ( V_67 = 0 ; V_67 < V_473 ; V_67 ++ )
F_326 ( V_803 [ V_67 ] , & V_805 -> V_803 [ V_67 ] ) ;
F_81 ( V_803 ) ;
return 0 ;
}
static void F_327 ( struct V_804 T_14 * V_805 ,
unsigned char * V_806 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < sizeof( V_805 -> V_803 ) ; V_67 ++ )
V_806 [ V_67 ] = F_328 ( & V_805 -> V_803 [ V_67 ] ) ;
}
static int F_329 ( struct V_804 T_14 * V_805 )
{
char * V_806 , * V_807 ;
int V_20 , V_473 = sizeof( V_805 -> V_803 ) ;
V_807 = F_92 ( 2 * V_473 , V_202 ) ;
if ( ! V_807 )
return - V_262 ;
V_806 = V_807 + V_473 ;
F_324 ( V_807 , V_473 ) ;
F_327 ( V_805 , V_806 ) ;
V_20 = ! memcmp ( V_806 , V_807 , V_473 ) ;
F_81 ( V_807 ) ;
return V_20 ;
}
static int F_330 ( struct V_370 * V_28 , T_4 V_66 )
{
T_5 V_808 ;
T_4 V_809 ;
T_5 V_810 ;
void T_14 * V_151 ;
unsigned long V_811 ;
T_4 V_812 ;
int V_20 ;
struct V_804 T_14 * V_805 ;
T_4 V_799 ;
T_6 V_813 ;
if ( ! F_28 ( V_66 ) ) {
F_9 ( & V_28 -> V_29 , L_195 ) ;
return - V_79 ;
}
if ( ! F_25 ( V_66 ) )
return - V_814 ;
F_331 ( V_28 , 4 , & V_813 ) ;
F_332 ( V_28 ) ;
V_20 = F_333 ( V_28 , & V_811 ) ;
if ( V_20 )
return V_20 ;
V_151 = F_299 ( V_811 , 0x250 ) ;
if ( ! V_151 )
return - V_262 ;
V_20 = F_334 ( V_28 , V_151 , & V_809 ,
& V_810 , & V_808 ) ;
if ( V_20 )
goto V_815;
V_805 = F_299 ( F_335 ( V_28 ,
V_810 ) + V_808 , sizeof( * V_805 ) ) ;
if ( ! V_805 ) {
V_20 = - V_262 ;
goto V_815;
}
V_20 = F_325 ( V_805 ) ;
if ( V_20 )
goto V_816;
V_812 = F_320 ( & V_805 -> V_812 ) ;
V_799 = V_812 & V_817 ;
if ( V_799 ) {
V_799 = V_818 ;
} else {
V_799 = V_812 & V_819 ;
if ( V_799 ) {
F_9 ( & V_28 -> V_29 ,
L_196 ) ;
V_20 = - V_814 ;
goto V_816;
}
}
V_20 = F_322 ( V_28 , V_151 , V_799 ) ;
if ( V_20 )
goto V_816;
F_336 ( V_28 ) ;
F_337 ( V_28 , 4 , V_813 ) ;
F_108 ( V_820 ) ;
V_20 = F_338 ( V_28 , V_151 , V_821 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 ,
L_197 ) ;
goto V_816;
}
V_20 = F_329 ( V_151 ) ;
if ( V_20 < 0 )
goto V_816;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_198
L_199 ) ;
V_20 = - V_814 ;
} else {
F_95 ( & V_28 -> V_29 , L_200 ) ;
}
V_816:
F_318 ( V_805 ) ;
V_815:
F_318 ( V_151 ) ;
return V_20 ;
}
static void F_339 ( struct V_41 * V_29 , struct V_804 T_14 * V_822 )
{
#ifdef F_340
int V_67 ;
char V_823 [ 17 ] ;
F_95 ( V_29 , L_201 ) ;
F_95 ( V_29 , L_202 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
V_823 [ V_67 ] = F_328 ( & ( V_822 -> V_824 [ V_67 ] ) ) ;
V_823 [ 4 ] = '\0' ;
F_95 ( V_29 , L_203 , V_823 ) ;
F_95 ( V_29 , L_204 , F_320 ( & ( V_822 -> V_825 ) ) ) ;
F_95 ( V_29 , L_205 ,
F_320 ( & ( V_822 -> V_826 ) ) ) ;
F_95 ( V_29 , L_206 ,
F_320 ( & ( V_822 -> V_827 ) ) ) ;
F_95 ( V_29 , L_207 ,
F_320 ( & ( V_822 -> V_828 . V_829 ) ) ) ;
F_95 ( V_29 , L_208 ,
F_320 ( & ( V_822 -> V_828 . V_830 ) ) ) ;
F_95 ( V_29 , L_209 ,
F_320 ( & ( V_822 -> V_828 . V_831 ) ) ) ;
F_95 ( V_29 , L_210 ,
F_320 ( & ( V_822 -> V_832 ) ) ) ;
F_95 ( V_29 , L_211 , F_320 ( & ( V_822 -> V_833 ) ) ) ;
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ )
V_823 [ V_67 ] = F_328 ( & ( V_822 -> V_834 [ V_67 ] ) ) ;
V_823 [ 16 ] = '\0' ;
F_95 ( V_29 , L_212 , V_823 ) ;
F_95 ( V_29 , L_213 ,
F_320 ( & ( V_822 -> V_835 ) ) ) ;
#endif
}
static int F_341 ( struct V_370 * V_28 , unsigned long V_836 )
{
int V_67 , V_693 , V_837 , V_838 ;
if ( V_836 == V_839 )
return 0 ;
V_693 = 0 ;
for ( V_67 = 0 ; V_67 < V_840 ; V_67 ++ ) {
V_838 = F_342 ( V_28 , V_67 ) & V_841 ;
if ( V_838 == V_842 )
V_693 += 4 ;
else {
V_837 = F_342 ( V_28 , V_67 ) &
V_843 ;
switch ( V_837 ) {
case V_844 :
case V_845 :
V_693 += 4 ;
break;
case V_846 :
V_693 += 8 ;
break;
default:
F_9 ( & V_28 -> V_29 ,
L_214 ) ;
return - 1 ;
break;
}
}
if ( V_693 == V_836 - V_839 )
return V_67 + 1 ;
}
return - 1 ;
}
static void F_343 ( struct V_1 * V_21 )
{
F_344 ( V_21 -> V_28 ) ;
V_21 -> V_125 = 0 ;
}
static int F_345 ( struct V_1 * V_21 )
{
unsigned int V_76 = V_847 ;
int V_848 ;
switch ( V_21 -> V_66 ) {
case 0x40700E11 :
case 0x40800E11 :
case 0x40820E11 :
case 0x40830E11 :
break;
default:
V_848 = F_346 ( V_21 -> V_28 , 1 , V_849 ,
V_850 | V_851 ) ;
if ( V_848 > 0 ) {
V_21 -> V_125 = V_848 ;
return 0 ;
}
V_76 |= V_852 ;
break;
}
V_848 = F_346 ( V_21 -> V_28 , 1 , 1 , V_76 ) ;
if ( V_848 < 0 )
return V_848 ;
return 0 ;
}
static int F_347 ( struct V_370 * V_28 , T_4 * V_66 )
{
int V_67 ;
T_4 V_853 , V_854 ;
V_853 = V_28 -> V_855 ;
V_854 = V_28 -> V_856 ;
* V_66 = ( ( V_854 << 16 ) & 0xffff0000 ) |
V_853 ;
for ( V_67 = 0 ; V_67 < F_26 ( V_857 ) ; V_67 ++ )
if ( * V_66 == V_857 [ V_67 ] . V_66 )
return V_67 ;
if ( ( V_853 != V_858 &&
V_853 != V_859 ) ||
! V_470 ) {
F_9 ( & V_28 -> V_29 , L_215
L_216 , * V_66 ) ;
return - V_79 ;
}
return F_26 ( V_857 ) - 1 ;
}
static int F_333 ( struct V_370 * V_28 ,
unsigned long * V_860 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_840 ; V_67 ++ )
if ( F_342 ( V_28 , V_67 ) & V_861 ) {
* V_860 = F_335 ( V_28 , V_67 ) ;
F_348 ( & V_28 -> V_29 , L_217 ,
* V_860 ) ;
return 0 ;
}
F_9 ( & V_28 -> V_29 , L_218 ) ;
return - V_79 ;
}
static int F_338 ( struct V_370 * V_28 , void T_14 * V_151 ,
int V_862 )
{
int V_67 , V_863 ;
T_4 V_864 ;
if ( V_862 )
V_863 = V_865 ;
else
V_863 = V_866 ;
for ( V_67 = 0 ; V_67 < V_863 ; V_67 ++ ) {
V_864 = F_320 ( V_151 + V_867 ) ;
if ( V_862 ) {
if ( V_864 == V_868 )
return 0 ;
} else {
if ( V_864 != V_868 )
return 0 ;
}
F_108 ( V_869 ) ;
}
F_9 ( & V_28 -> V_29 , L_219 ) ;
return - V_79 ;
}
static int F_334 ( struct V_370 * V_28 , void T_14 * V_151 ,
T_4 * V_809 , T_5 * V_810 ,
T_5 * V_808 )
{
* V_809 = F_320 ( V_151 + V_870 ) ;
* V_808 = F_320 ( V_151 + V_871 ) ;
* V_809 &= ( T_4 ) 0x0000ffff ;
* V_810 = F_341 ( V_28 , * V_809 ) ;
if ( * V_810 == - 1 ) {
F_9 ( & V_28 -> V_29 , L_220 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_349 ( struct V_1 * V_21 )
{
if ( V_21 -> V_872 ) {
F_318 ( V_21 -> V_872 ) ;
V_21 -> V_872 = NULL ;
}
if ( V_21 -> V_805 ) {
F_318 ( V_21 -> V_805 ) ;
V_21 -> V_805 = NULL ;
}
}
static int F_350 ( struct V_1 * V_21 )
{
T_5 V_808 ;
T_4 V_809 ;
T_5 V_810 ;
T_4 V_873 ;
int V_20 ;
V_20 = F_334 ( V_21 -> V_28 , V_21 -> V_151 , & V_809 ,
& V_810 , & V_808 ) ;
if ( V_20 )
return V_20 ;
V_21 -> V_805 = F_299 ( F_335 ( V_21 -> V_28 ,
V_810 ) + V_808 , sizeof( * V_21 -> V_805 ) ) ;
if ( ! V_21 -> V_805 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_221 ) ;
return - V_262 ;
}
V_20 = F_325 ( V_21 -> V_805 ) ;
if ( V_20 )
return V_20 ;
V_873 = F_320 ( & V_21 -> V_805 -> V_874 ) ;
V_21 -> V_872 = F_299 ( F_335 ( V_21 -> V_28 ,
V_810 ) + V_808 + V_873 ,
sizeof( * V_21 -> V_872 ) ) ;
if ( ! V_21 -> V_872 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_222 ) ;
F_349 ( V_21 ) ;
return - V_262 ;
}
return 0 ;
}
static void F_351 ( struct V_1 * V_21 )
{
#define F_352 16
F_353 ( F_352 <= V_668 ) ;
V_21 -> V_120 = F_320 ( & V_21 -> V_805 -> V_875 ) ;
if ( V_778 && V_21 -> V_120 > 32 )
V_21 -> V_120 = 32 ;
if ( V_21 -> V_120 < F_352 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_223 ,
V_21 -> V_120 ,
F_352 ) ;
V_21 -> V_120 = F_352 ;
}
}
static int F_354 ( struct V_1 * V_21 )
{
return V_21 -> V_263 > 512 ;
}
static void F_355 ( struct V_1 * V_21 )
{
F_351 ( V_21 ) ;
V_21 -> V_235 = V_21 -> V_120 ;
V_21 -> V_263 = F_320 ( & ( V_21 -> V_805 -> V_876 ) ) ;
V_21 -> V_488 = F_320 ( & ( V_21 -> V_805 -> V_812 ) ) ;
if ( F_354 ( V_21 ) ) {
V_21 -> V_278 = 32 ;
V_21 -> V_261 = V_21 -> V_263 - V_21 -> V_278 ;
V_21 -> V_263 -- ;
} else {
V_21 -> V_278 = 31 ;
V_21 -> V_263 = 31 ;
V_21 -> V_261 = 0 ;
}
V_21 -> V_877 = F_320 ( & ( V_21 -> V_805 -> V_877 ) ) ;
if ( ! ( V_878 & V_21 -> V_877 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_224 ) ;
if ( ! ( V_879 & V_21 -> V_877 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_225 ) ;
if ( ! ( V_880 & V_21 -> V_877 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_226 ) ;
}
static inline bool F_356 ( struct V_1 * V_21 )
{
if ( ! F_357 ( V_21 -> V_805 -> V_824 , L_227 , 4 ) ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_228 ) ;
return false ;
}
return true ;
}
static inline void F_358 ( struct V_1 * V_21 )
{
T_4 V_881 ;
V_881 = F_320 ( & ( V_21 -> V_805 -> V_881 ) ) ;
#ifdef F_359
V_881 |= V_882 ;
#endif
V_881 |= V_883 ;
F_60 ( V_881 , & ( V_21 -> V_805 -> V_881 ) ) ;
}
static inline void F_360 ( struct V_1 * V_21 )
{
T_4 V_884 ;
if ( V_21 -> V_66 != 0x3225103C )
return;
V_884 = F_320 ( V_21 -> V_151 + V_885 ) ;
V_884 |= 0x8000 ;
F_60 ( V_884 , V_21 -> V_151 + V_885 ) ;
}
static int F_361 ( struct V_1 * V_21 )
{
int V_67 ;
T_4 V_886 ;
unsigned long V_76 ;
for ( V_67 = 0 ; V_67 < V_887 ; V_67 ++ ) {
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_886 = F_320 ( V_21 -> V_151 + V_800 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( ! ( V_886 & V_888 ) )
goto V_889;
F_108 ( V_890 ) ;
}
return - V_79 ;
V_889:
return 0 ;
}
static int F_362 ( struct V_1 * V_21 )
{
int V_67 ;
T_4 V_886 ;
unsigned long V_76 ;
for ( V_67 = 0 ; V_67 < V_891 ; V_67 ++ ) {
if ( V_21 -> V_892 )
goto V_889;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_886 = F_320 ( V_21 -> V_151 + V_800 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( ! ( V_886 & V_893 ) )
goto V_889;
F_108 ( V_894 ) ;
}
return - V_79 ;
V_889:
return 0 ;
}
static int F_363 ( struct V_1 * V_21 )
{
T_4 V_895 ;
V_895 = F_320 ( & ( V_21 -> V_805 -> V_826 ) ) ;
if ( ! ( V_895 & V_896 ) )
return - V_814 ;
V_21 -> V_120 = F_320 ( & ( V_21 -> V_805 -> V_832 ) ) ;
F_60 ( V_897 , & ( V_21 -> V_805 -> V_828 . V_829 ) ) ;
F_60 ( 0 , & V_21 -> V_805 -> V_828 . V_898 ) ;
F_60 ( V_893 , V_21 -> V_151 + V_800 ) ;
if ( F_362 ( V_21 ) )
goto error;
F_339 ( & V_21 -> V_28 -> V_29 , V_21 -> V_805 ) ;
if ( ! ( F_320 ( & ( V_21 -> V_805 -> V_827 ) ) & V_897 ) )
goto error;
V_21 -> V_62 = V_897 ;
return 0 ;
error:
F_74 ( & V_21 -> V_28 -> V_29 , L_229 ) ;
return - V_79 ;
}
static void F_364 ( struct V_1 * V_21 )
{
F_349 ( V_21 ) ;
F_318 ( V_21 -> V_151 ) ;
V_21 -> V_151 = NULL ;
F_343 ( V_21 ) ;
F_365 ( V_21 -> V_28 ) ;
F_366 ( V_21 -> V_28 ) ;
}
static int F_367 ( struct V_1 * V_21 )
{
int V_899 , V_699 ;
V_899 = F_347 ( V_21 -> V_28 , & V_21 -> V_66 ) ;
if ( V_899 < 0 )
return V_899 ;
V_21 -> V_900 = V_857 [ V_899 ] . V_900 ;
V_21 -> V_114 = * ( V_857 [ V_899 ] . V_114 ) ;
F_368 ( V_21 -> V_28 , V_901 |
V_902 | V_903 ) ;
V_699 = F_369 ( V_21 -> V_28 ) ;
if ( V_699 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_230 ) ;
F_365 ( V_21 -> V_28 ) ;
return V_699 ;
}
V_699 = F_370 ( V_21 -> V_28 , V_40 ) ;
if ( V_699 ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_231 ) ;
F_365 ( V_21 -> V_28 ) ;
return V_699 ;
}
F_371 ( V_21 -> V_28 ) ;
V_699 = F_345 ( V_21 ) ;
if ( V_699 )
goto V_904;
V_699 = F_333 ( V_21 -> V_28 , & V_21 -> V_811 ) ;
if ( V_699 )
goto V_905;
V_21 -> V_151 = F_299 ( V_21 -> V_811 , 0x250 ) ;
if ( ! V_21 -> V_151 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_232 ) ;
V_699 = - V_262 ;
goto V_905;
}
V_699 = F_338 ( V_21 -> V_28 , V_21 -> V_151 , V_821 ) ;
if ( V_699 )
goto V_906;
V_699 = F_350 ( V_21 ) ;
if ( V_699 )
goto V_906;
F_355 ( V_21 ) ;
if ( ! F_356 ( V_21 ) ) {
V_699 = - V_79 ;
goto V_907;
}
F_358 ( V_21 ) ;
F_360 ( V_21 ) ;
V_699 = F_363 ( V_21 ) ;
if ( V_699 )
goto V_907;
return 0 ;
V_907:
F_349 ( V_21 ) ;
V_906:
F_318 ( V_21 -> V_151 ) ;
V_21 -> V_151 = NULL ;
V_905:
F_343 ( V_21 ) ;
V_904:
F_365 ( V_21 -> V_28 ) ;
F_366 ( V_21 -> V_28 ) ;
return V_699 ;
}
static void F_372 ( struct V_1 * V_21 )
{
int V_20 ;
#define F_373 64
V_21 -> V_60 = F_92 ( F_373 , V_202 ) ;
if ( ! V_21 -> V_60 )
return;
V_20 = F_173 ( V_21 , V_157 , 0 ,
V_21 -> V_60 , F_373 ) ;
if ( V_20 != 0 ) {
F_81 ( V_21 -> V_60 ) ;
V_21 -> V_60 = NULL ;
}
}
static int F_374 ( struct V_370 * V_28 , T_4 V_66 )
{
int V_20 , V_67 ;
void T_14 * V_151 ;
if ( ! V_778 )
return 0 ;
V_20 = F_369 ( V_28 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_233 ) ;
return - V_79 ;
}
F_365 ( V_28 ) ;
F_108 ( 260 ) ;
V_20 = F_369 ( V_28 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_234 ) ;
return - V_79 ;
}
F_371 ( V_28 ) ;
V_151 = F_315 ( V_28 , 0 ) ;
if ( V_151 == NULL ) {
V_20 = - V_262 ;
goto V_908;
}
F_60 ( V_909 , V_151 + V_910 ) ;
F_318 ( V_151 ) ;
V_20 = F_330 ( V_28 , V_66 ) ;
if ( V_20 )
goto V_908;
F_95 ( & V_28 -> V_29 , L_235 ) ;
for ( V_67 = 0 ; V_67 < V_911 ; V_67 ++ ) {
if ( F_375 ( V_28 ) == 0 )
break;
else
F_9 ( & V_28 -> V_29 , L_236 ,
( V_67 < 11 ? L_237 : L_238 ) ) ;
}
V_908:
F_365 ( V_28 ) ;
return V_20 ;
}
static void F_376 ( struct V_1 * V_21 )
{
F_81 ( V_21 -> V_694 ) ;
V_21 -> V_694 = NULL ;
if ( V_21 -> V_237 ) {
F_321 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( struct V_8 ) ,
V_21 -> V_237 ,
V_21 -> V_645 ) ;
V_21 -> V_237 = NULL ;
V_21 -> V_645 = 0 ;
}
if ( V_21 -> V_646 ) {
F_321 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( struct V_337 ) ,
V_21 -> V_646 ,
V_21 -> V_647 ) ;
V_21 -> V_646 = NULL ;
V_21 -> V_647 = 0 ;
}
}
static int F_377 ( struct V_1 * V_21 )
{
V_21 -> V_694 = F_115 (
F_378 ( V_21 -> V_235 , V_626 ) *
sizeof( unsigned long ) , V_202 ) ;
V_21 -> V_237 = F_319 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_237 ) ,
& ( V_21 -> V_645 ) ) ;
V_21 -> V_646 = F_319 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_646 ) ,
& ( V_21 -> V_647 ) ) ;
if ( ( V_21 -> V_694 == NULL )
|| ( V_21 -> V_237 == NULL )
|| ( V_21 -> V_646 == NULL ) ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_239 , V_241 ) ;
goto V_912;
}
F_254 ( V_21 ) ;
return 0 ;
V_912:
F_376 ( V_21 ) ;
return - V_262 ;
}
static void F_379 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_125 || V_21 -> V_913 != V_914 ) {
F_380 ( F_267 ( V_21 -> V_28 , 0 ) , & V_21 -> V_109 [ V_21 -> V_913 ] ) ;
V_21 -> V_109 [ V_21 -> V_913 ] = 0 ;
return;
}
for ( V_67 = 0 ; V_67 < V_21 -> V_125 ; V_67 ++ ) {
F_380 ( F_267 ( V_21 -> V_28 , V_67 ) , & V_21 -> V_109 [ V_67 ] ) ;
V_21 -> V_109 [ V_67 ] = 0 ;
}
for (; V_67 < V_849 ; V_67 ++ )
V_21 -> V_109 [ V_67 ] = 0 ;
}
static int F_381 ( struct V_1 * V_21 ,
T_16 (* F_382)( int , void * ) ,
T_16 (* F_383)( int , void * ) )
{
int V_20 , V_67 ;
for ( V_67 = 0 ; V_67 < V_849 ; V_67 ++ )
V_21 -> V_109 [ V_67 ] = ( T_1 ) V_67 ;
if ( V_21 -> V_913 == V_914 && V_21 -> V_125 > 0 ) {
for ( V_67 = 0 ; V_67 < V_21 -> V_125 ; V_67 ++ ) {
sprintf ( V_21 -> V_915 [ V_67 ] , L_240 , V_21 -> V_30 , V_67 ) ;
V_20 = F_384 ( F_267 ( V_21 -> V_28 , V_67 ) , F_382 ,
0 , V_21 -> V_915 [ V_67 ] ,
& V_21 -> V_109 [ V_67 ] ) ;
if ( V_20 ) {
int V_192 ;
F_74 ( & V_21 -> V_28 -> V_29 ,
L_241 ,
F_267 ( V_21 -> V_28 , V_67 ) , V_21 -> V_30 ) ;
for ( V_192 = 0 ; V_192 < V_67 ; V_192 ++ ) {
F_380 ( F_267 ( V_21 -> V_28 , V_192 ) , & V_21 -> V_109 [ V_192 ] ) ;
V_21 -> V_109 [ V_192 ] = 0 ;
}
for (; V_192 < V_849 ; V_192 ++ )
V_21 -> V_109 [ V_192 ] = 0 ;
return V_20 ;
}
}
} else {
if ( V_21 -> V_125 > 0 || V_21 -> V_28 -> V_916 ) {
sprintf ( V_21 -> V_915 [ 0 ] , L_242 , V_21 -> V_30 ,
V_21 -> V_125 ? L_243 : L_238 ) ;
V_20 = F_384 ( F_267 ( V_21 -> V_28 , 0 ) ,
F_382 , 0 ,
V_21 -> V_915 [ 0 ] ,
& V_21 -> V_109 [ V_21 -> V_913 ] ) ;
} else {
sprintf ( V_21 -> V_915 [ V_21 -> V_913 ] ,
L_244 , V_21 -> V_30 ) ;
V_20 = F_384 ( F_267 ( V_21 -> V_28 , 0 ) ,
F_383 , V_917 ,
V_21 -> V_915 [ 0 ] ,
& V_21 -> V_109 [ V_21 -> V_913 ] ) ;
}
}
if ( V_20 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_241 ,
F_267 ( V_21 -> V_28 , 0 ) , V_21 -> V_30 ) ;
F_379 ( V_21 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_385 ( struct V_1 * V_21 )
{
int V_20 ;
F_297 ( V_21 , V_157 , V_918 ) ;
F_95 ( & V_21 -> V_28 -> V_29 , L_245 ) ;
V_20 = F_338 ( V_21 -> V_28 , V_21 -> V_151 , V_919 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_246 ) ;
return V_20 ;
}
F_95 ( & V_21 -> V_28 -> V_29 , L_247 ) ;
V_20 = F_338 ( V_21 -> V_28 , V_21 -> V_151 , V_821 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_248
L_249 ) ;
return V_20 ;
}
return 0 ;
}
static void F_386 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ ) {
if ( ! V_21 -> V_112 [ V_67 ] . V_116 )
continue;
F_321 ( V_21 -> V_28 ,
V_21 -> V_920 ,
V_21 -> V_112 [ V_67 ] . V_116 ,
V_21 -> V_112 [ V_67 ] . V_121 ) ;
V_21 -> V_112 [ V_67 ] . V_116 = NULL ;
V_21 -> V_112 [ V_67 ] . V_121 = 0 ;
}
V_21 -> V_920 = 0 ;
}
static void F_387 ( struct V_1 * V_21 )
{
F_388 ( V_21 ) ;
F_128 ( V_21 ) ;
F_376 ( V_21 ) ;
F_379 ( V_21 ) ;
F_389 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
F_364 ( V_21 ) ;
F_390 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
if ( V_21 -> V_328 ) {
F_391 ( V_21 -> V_328 ) ;
V_21 -> V_328 = NULL ;
}
if ( V_21 -> V_921 ) {
F_391 ( V_21 -> V_921 ) ;
V_21 -> V_921 = NULL ;
}
F_81 ( V_21 ) ;
}
static void F_392 ( struct V_1 * V_21 )
{
int V_67 , V_238 ;
struct V_8 * V_9 ;
int V_922 = 0 ;
F_393 ( V_21 -> V_328 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
V_9 = V_21 -> V_237 + V_67 ;
V_238 = F_104 ( & V_9 -> V_238 ) ;
if ( V_238 > 1 ) {
V_9 -> V_23 -> V_35 = V_343 ;
F_62 ( V_9 ) ;
F_46 ( & V_21 -> V_61 ) ;
V_922 ++ ;
}
F_106 ( V_21 , V_9 ) ;
}
F_9 ( & V_21 -> V_28 -> V_29 ,
L_250 , V_922 ) ;
}
static void F_394 ( struct V_1 * V_21 , T_4 V_923 )
{
int V_384 ;
F_395 (cpu) {
T_4 * F_13 ;
F_13 = F_168 ( V_21 -> F_13 , V_384 ) ;
* F_13 = V_923 ;
}
F_77 () ;
}
static void F_396 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
T_4 F_13 ;
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
F_13 = F_320 ( V_21 -> V_151 + V_867 ) ;
if ( ! F_13 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_251 ,
V_21 -> V_146 / V_926 ) ;
F_13 = 0xffffffff ;
}
F_394 ( V_21 , F_13 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_9 ( & V_21 -> V_28 -> V_29 , L_252 ,
F_13 , V_21 -> V_146 / V_926 ) ;
F_365 ( V_21 -> V_28 ) ;
F_392 ( V_21 ) ;
}
static int F_275 ( struct V_1 * V_21 )
{
T_5 V_927 ;
T_4 V_928 ;
unsigned long V_76 ;
V_927 = F_310 () ;
if ( F_397 ( V_21 -> V_781 +
( V_21 -> V_146 ) , V_927 ) )
return false ;
if ( F_397 ( V_21 -> V_929 +
( V_21 -> V_146 ) , V_927 ) )
return false ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_928 = F_320 ( & V_21 -> V_805 -> V_835 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_930 == V_928 ) {
F_396 ( V_21 ) ;
return true ;
}
V_21 -> V_930 = V_928 ;
V_21 -> V_929 = V_927 ;
return false ;
}
static void F_398 ( struct V_1 * V_21 )
{
int V_67 ;
char * V_931 ;
if ( ! ( V_21 -> V_488 & V_932 ) )
return;
if ( ( V_21 -> V_62 & ( V_113
| V_933 ) ) &&
( V_21 -> V_934 & V_935 ||
V_21 -> V_934 & V_936 ) ) {
if ( V_21 -> V_934 & V_935 )
V_931 = L_253 ;
if ( V_21 -> V_934 & V_936 )
V_931 = L_254 ;
F_399 ( V_21 -> V_58 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
V_21 -> V_29 [ V_67 ] -> V_89 = 0 ;
V_21 -> V_29 [ V_67 ] -> V_182 = 0 ;
}
F_400 ( V_21 ) ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_255 ,
V_21 -> V_934 , V_931 ) ;
F_60 ( V_21 -> V_934 , & ( V_21 -> V_805 -> V_937 ) ) ;
F_60 ( V_888 , V_21 -> V_151 + V_800 ) ;
F_361 ( V_21 ) ;
F_401 ( V_21 -> V_58 ) ;
} else {
F_60 ( V_21 -> V_934 , & ( V_21 -> V_805 -> V_937 ) ) ;
F_60 ( V_888 , V_21 -> V_151 + V_800 ) ;
F_361 ( V_21 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_402 ( struct V_1 * V_21 )
{
if ( V_21 -> V_249 ) {
V_21 -> V_249 = 0 ;
return 1 ;
}
if ( ! ( V_21 -> V_488 & V_932 ) )
return 0 ;
V_21 -> V_934 = F_320 ( & ( V_21 -> V_805 -> V_938 ) ) ;
return V_21 -> V_934 & V_939 ;
}
static int F_403 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
struct V_200 * V_390 ;
struct V_940 * V_941 , * V_942 ;
F_34 ( & V_21 -> V_201 , V_76 ) ;
F_404 (this, tmp, &h->offline_device_list) {
V_390 = F_405 ( V_941 , struct V_200 ,
V_203 ) ;
F_35 ( & V_21 -> V_201 , V_76 ) ;
if ( ! F_208 ( V_21 , V_390 -> V_70 ) ) {
F_34 ( & V_21 -> V_201 , V_76 ) ;
F_406 ( & V_390 -> V_203 ) ;
F_35 ( & V_21 -> V_201 , V_76 ) ;
return 1 ;
}
F_34 ( & V_21 -> V_201 , V_76 ) ;
}
F_35 ( & V_21 -> V_201 , V_76 ) ;
return 0 ;
}
static int F_407 ( struct V_1 * V_21 )
{
int V_20 = 1 ;
struct V_465 * V_498 = NULL ;
if ( ! V_21 -> V_943 )
return V_20 ;
V_498 = F_115 ( sizeof( * V_498 ) , V_202 ) ;
if ( ! V_498 )
return V_20 ;
if ( F_203 ( V_21 , 1 , V_498 , sizeof( * V_498 ) , 0 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_256 ) ;
goto V_395;
}
if ( memcmp ( V_498 , V_21 -> V_943 , sizeof( * V_498 ) ) ) {
F_95 ( & V_21 -> V_28 -> V_29 ,
L_257 ) ;
memcpy ( V_21 -> V_943 , V_498 , sizeof( * V_498 ) ) ;
goto V_395;
} else
V_20 = 0 ;
V_395:
F_81 ( V_498 ) ;
return V_20 ;
}
static void F_408 ( struct V_1 * V_21 )
{
struct V_6 * V_7 = NULL ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_247 , V_76 ) ;
if ( V_21 -> V_248 ) {
V_21 -> V_249 = 1 ;
F_35 ( & V_21 -> V_247 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_247 , V_76 ) ;
V_7 = F_409 ( V_21 -> V_58 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_389 ( V_7 ) ;
V_21 -> V_249 = 0 ;
}
}
static void F_410 ( struct V_649 * V_326 )
{
struct V_1 * V_21 = F_257 ( F_411 ( V_326 ) ,
struct V_1 , V_944 ) ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_892 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( F_402 ( V_21 ) ) {
F_398 ( V_21 ) ;
F_408 ( V_21 ) ;
}
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_892 )
F_412 ( & V_21 -> V_944 ,
V_945 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static void F_413 ( struct V_649 * V_326 )
{
unsigned long V_76 ;
struct V_1 * V_21 = F_257 ( F_411 ( V_326 ) ,
struct V_1 , V_946 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_892 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_249 || F_403 ( V_21 ) ) {
F_408 ( V_21 ) ;
} else if ( V_21 -> V_533 ) {
F_414 ( V_21 ) ;
if ( F_407 ( V_21 ) ) {
F_95 ( & V_21 -> V_28 -> V_29 ,
L_258 ) ;
F_408 ( V_21 ) ;
}
}
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_892 )
F_415 ( V_21 -> V_921 , & V_21 -> V_946 ,
V_21 -> V_146 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static void F_416 ( struct V_649 * V_326 )
{
unsigned long V_76 ;
struct V_1 * V_21 = F_257 ( F_411 ( V_326 ) ,
struct V_1 , V_947 ) ;
F_275 ( V_21 ) ;
if ( F_13 ( V_21 ) )
return;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_892 )
F_412 ( & V_21 -> V_947 ,
V_21 -> V_146 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static struct V_948 * F_417 ( struct V_1 * V_21 ,
char * V_949 )
{
struct V_948 * V_950 = NULL ;
V_950 = F_418 ( L_259 , 0 , V_949 , V_21 -> V_108 ) ;
if ( ! V_950 )
F_74 ( & V_21 -> V_28 -> V_29 , L_260 , V_949 ) ;
return V_950 ;
}
static int F_419 ( struct V_370 * V_28 , const struct V_951 * V_952 )
{
int V_953 , V_20 ;
struct V_1 * V_21 ;
int V_954 = 0 ;
unsigned long V_76 ;
T_4 V_66 ;
if ( V_955 == 0 )
F_420 (KERN_INFO DRIVER_NAME L_261 ) ;
V_20 = F_347 ( V_28 , & V_66 ) ;
if ( V_20 < 0 ) {
F_9 ( & V_28 -> V_29 , L_262 ) ;
return V_20 ;
}
V_20 = F_374 ( V_28 , V_66 ) ;
if ( V_20 ) {
if ( V_20 != - V_814 )
return V_20 ;
V_954 = 1 ;
V_20 = 0 ;
}
V_956:
F_353 ( sizeof( struct V_8 ) % V_957 ) ;
V_21 = F_115 ( sizeof( * V_21 ) , V_202 ) ;
if ( ! V_21 ) {
F_74 ( & V_28 -> V_29 , L_263 ) ;
return - V_262 ;
}
V_21 -> V_28 = V_28 ;
V_21 -> V_913 = V_958 ? V_959 : V_914 ;
F_421 ( & V_21 -> V_204 ) ;
F_422 ( & V_21 -> V_77 ) ;
F_422 ( & V_21 -> V_201 ) ;
F_422 ( & V_21 -> V_653 ) ;
F_422 ( & V_21 -> V_247 ) ;
F_122 ( & V_21 -> V_754 , V_960 ) ;
V_21 -> F_13 = F_423 ( T_4 ) ;
if ( ! V_21 -> F_13 ) {
F_74 ( & V_21 -> V_28 -> V_29 , L_264 ) ;
V_20 = - V_262 ;
goto V_904;
}
F_394 ( V_21 , 0 ) ;
V_20 = F_367 ( V_21 ) ;
if ( V_20 )
goto V_905;
V_20 = F_265 ( V_21 ) ;
if ( V_20 )
goto V_961;
sprintf ( V_21 -> V_30 , V_40 L_9 , V_21 -> V_58 -> V_100 ) ;
V_21 -> V_108 = V_955 ;
V_955 ++ ;
V_20 = F_424 ( V_28 , F_317 ( 64 ) ) ;
if ( V_20 == 0 ) {
V_953 = 1 ;
} else {
V_20 = F_424 ( V_28 , F_317 ( 32 ) ) ;
if ( V_20 == 0 ) {
V_953 = 0 ;
} else {
F_74 ( & V_28 -> V_29 , L_265 ) ;
goto V_906;
}
}
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
V_20 = F_381 ( V_21 , F_313 , F_312 ) ;
if ( V_20 )
goto V_906;
V_20 = F_377 ( V_21 ) ;
if ( V_20 )
goto V_907;
V_20 = F_129 ( V_21 ) ;
if ( V_20 )
goto V_962;
F_425 ( & V_21 -> V_655 ) ;
F_425 ( & V_21 -> V_324 ) ;
F_426 ( & V_21 -> V_404 ) ;
V_21 -> V_654 = 1 ;
V_21 -> V_656 = 0 ;
F_427 ( V_28 , V_21 ) ;
V_21 -> V_161 = 0 ;
F_422 ( & V_21 -> V_96 ) ;
V_20 = F_428 ( V_21 ) ;
if ( V_20 )
goto V_963;
V_21 -> V_921 = F_417 ( V_21 , L_266 ) ;
if ( ! V_21 -> V_921 ) {
V_20 = - V_262 ;
goto V_964;
}
V_21 -> V_328 = F_417 ( V_21 , L_267 ) ;
if ( ! V_21 -> V_328 ) {
V_20 = - V_262 ;
goto V_964;
}
if ( V_954 ) {
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_379 ( V_21 ) ;
V_20 = F_381 ( V_21 , F_311 ,
F_309 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_268 ) ;
F_388 ( V_21 ) ;
F_128 ( V_21 ) ;
F_376 ( V_21 ) ;
goto V_906;
}
V_20 = F_385 ( V_21 ) ;
if ( V_20 )
goto V_964;
F_95 ( & V_21 -> V_28 -> V_29 , L_269 ) ;
F_95 ( & V_21 -> V_28 -> V_29 ,
L_270 ) ;
V_21 -> V_114 . V_924 ( V_21 , V_965 ) ;
F_108 ( 10000 ) ;
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
V_20 = F_329 ( V_21 -> V_805 ) ;
if ( V_20 )
F_95 ( & V_21 -> V_28 -> V_29 ,
L_271 ) ;
F_387 ( V_21 ) ;
V_954 = 0 ;
if ( V_20 )
return - V_79 ;
goto V_956;
}
V_21 -> V_55 = 1 ;
V_21 -> V_533 = 0 ;
V_21 -> V_114 . V_924 ( V_21 , V_965 ) ;
F_372 ( V_21 ) ;
V_21 -> V_943 = F_115 ( sizeof( * ( V_21 -> V_943 ) ) , V_202 ) ;
if ( ! V_21 -> V_943 )
F_95 ( & V_21 -> V_28 -> V_29 ,
L_272 ) ;
V_20 = F_268 ( V_21 ) ;
if ( V_20 )
goto V_964;
V_21 -> V_146 = V_148 ;
F_429 ( & V_21 -> V_947 , F_416 ) ;
F_412 ( & V_21 -> V_947 ,
V_21 -> V_146 ) ;
F_429 ( & V_21 -> V_946 , F_413 ) ;
F_415 ( V_21 -> V_921 , & V_21 -> V_946 ,
V_21 -> V_146 ) ;
F_429 ( & V_21 -> V_944 , F_410 ) ;
F_412 ( & V_21 -> V_944 ,
V_945 ) ;
return 0 ;
V_964:
F_388 ( V_21 ) ;
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
V_963:
F_128 ( V_21 ) ;
V_962:
F_376 ( V_21 ) ;
V_907:
F_379 ( V_21 ) ;
V_906:
F_389 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
V_961:
F_364 ( V_21 ) ;
V_905:
if ( V_21 -> F_13 ) {
F_390 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
}
V_904:
if ( V_21 -> V_328 ) {
F_391 ( V_21 -> V_328 ) ;
V_21 -> V_328 = NULL ;
}
if ( V_21 -> V_921 ) {
F_391 ( V_21 -> V_921 ) ;
V_21 -> V_921 = NULL ;
}
F_81 ( V_21 ) ;
return V_20 ;
}
static void F_430 ( struct V_1 * V_21 )
{
char * V_966 ;
struct V_8 * V_9 ;
int V_20 ;
if ( F_45 ( F_13 ( V_21 ) ) )
return;
V_966 = F_115 ( 4 , V_202 ) ;
if ( ! V_966 )
return;
V_9 = F_174 ( V_21 ) ;
if ( F_175 ( V_9 , V_762 , V_21 , V_966 , 4 , 0 ,
V_157 , V_394 ) ) {
goto V_395;
}
V_20 = F_170 ( V_21 , V_9 ,
V_272 , V_397 ) ;
if ( V_20 )
goto V_395;
if ( V_9 -> V_23 -> V_35 != 0 )
V_395:
F_9 ( & V_21 -> V_28 -> V_29 ,
L_273 ) ;
F_106 ( V_21 , V_9 ) ;
F_81 ( V_966 ) ;
}
static void F_414 ( struct V_1 * V_21 )
{
T_4 * V_967 ;
struct V_8 * V_9 ;
int V_20 ;
if ( F_45 ( V_21 -> F_13 ) )
return;
V_967 = F_115 ( sizeof( * V_967 ) , V_202 ) ;
if ( ! V_967 )
return;
V_9 = F_174 ( V_21 ) ;
if ( F_175 ( V_9 , V_759 , V_21 , V_967 , 4 , 0 ,
V_157 , V_394 ) )
goto V_968;
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_968;
* V_967 |= V_969 ;
if ( F_175 ( V_9 , V_761 , V_21 , V_967 , 4 , 0 ,
V_157 , V_394 ) )
goto V_968;
V_20 = F_170 ( V_21 , V_9 ,
V_272 , V_397 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_968;
if ( F_175 ( V_9 , V_759 , V_21 , V_967 , 4 , 0 ,
V_157 , V_394 ) )
goto V_968;
V_20 = F_170 ( V_21 , V_9 ,
V_396 , V_397 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_968;
if ( * V_967 & V_969 )
goto V_395;
V_968:
F_74 ( & V_21 -> V_28 -> V_29 ,
L_274 ) ;
V_395:
F_106 ( V_21 , V_9 ) ;
F_81 ( V_967 ) ;
}
static void F_431 ( struct V_370 * V_28 )
{
struct V_1 * V_21 ;
V_21 = F_432 ( V_28 ) ;
F_430 ( V_21 ) ;
V_21 -> V_114 . V_924 ( V_21 , V_925 ) ;
F_379 ( V_21 ) ;
F_343 ( V_21 ) ;
}
static void F_433 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
F_81 ( V_21 -> V_29 [ V_67 ] ) ;
V_21 -> V_29 [ V_67 ] = NULL ;
}
}
static void F_434 ( struct V_370 * V_28 )
{
struct V_1 * V_21 ;
unsigned long V_76 ;
if ( F_432 ( V_28 ) == NULL ) {
F_74 ( & V_28 -> V_29 , L_275 ) ;
return;
}
V_21 = F_432 ( V_28 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_21 -> V_892 = 1 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_435 ( & V_21 -> V_947 ) ;
F_435 ( & V_21 -> V_946 ) ;
F_435 ( & V_21 -> V_944 ) ;
F_391 ( V_21 -> V_921 ) ;
F_391 ( V_21 -> V_328 ) ;
if ( V_21 -> V_58 )
F_436 ( V_21 -> V_58 ) ;
F_431 ( V_28 ) ;
F_433 ( V_21 ) ;
F_81 ( V_21 -> V_60 ) ;
V_21 -> V_60 = NULL ;
F_126 ( V_21 ) ;
F_388 ( V_21 ) ;
F_128 ( V_21 ) ;
F_376 ( V_21 ) ;
F_81 ( V_21 -> V_943 ) ;
F_389 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
F_364 ( V_21 ) ;
F_390 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
F_437 ( V_21 ) ;
F_81 ( V_21 ) ;
}
static void F_438 ( int V_970 [] , int V_971 ,
int V_972 , int V_973 , T_4 * V_974 )
{
int V_67 , V_192 , V_975 , V_473 ;
for ( V_67 = 0 ; V_67 <= V_972 ; V_67 ++ ) {
V_473 = V_67 + V_973 ;
V_975 = V_971 ;
for ( V_192 = 0 ; V_192 < V_971 ; V_192 ++ ) {
if ( V_970 [ V_192 ] >= V_473 ) {
V_975 = V_192 ;
break;
}
}
V_974 [ V_67 ] = V_975 ;
}
}
static int F_439 ( struct V_1 * V_21 , T_4 V_895 )
{
int V_67 ;
unsigned long V_976 ;
unsigned long V_62 = V_63 |
( V_895 & V_977 ) |
V_978 |
( V_895 & ( V_113 |
V_933 ) ) ;
struct V_979 V_114 = V_980 ;
int V_981 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_751 + 4 } ;
#define F_440 5
#define F_441 4
int V_982 [ 16 ] = { F_440 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_441 + V_983 } ;
F_353 ( F_26 ( V_982 ) != 16 ) ;
F_353 ( F_26 ( V_981 ) != 8 ) ;
F_353 ( F_247 ( struct V_138 , V_270 ) >
16 * F_440 ) ;
F_353 ( sizeof( struct V_266 ) != 16 ) ;
F_353 ( 28 > V_751 + 4 ) ;
if ( V_895 & ( V_113 | V_933 ) )
V_114 = V_984 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ )
memset ( V_21 -> V_112 [ V_67 ] . V_116 , 0 , V_21 -> V_920 ) ;
V_981 [ 7 ] = V_751 + 4 ;
F_438 ( V_981 , F_26 ( V_981 ) ,
V_751 , 4 , V_21 -> V_122 ) ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ )
F_60 ( V_981 [ V_67 ] , & V_21 -> V_872 -> V_985 [ V_67 ] ) ;
F_60 ( V_21 -> V_120 , & V_21 -> V_872 -> V_986 ) ;
F_60 ( V_21 -> V_128 , & V_21 -> V_872 -> V_987 ) ;
F_60 ( 0 , & V_21 -> V_872 -> V_988 ) ;
F_60 ( 0 , & V_21 -> V_872 -> V_989 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ ) {
F_60 ( 0 , & V_21 -> V_872 -> V_990 [ V_67 ] . V_991 ) ;
F_60 ( V_21 -> V_112 [ V_67 ] . V_121 ,
& V_21 -> V_872 -> V_990 [ V_67 ] . V_992 ) ;
}
F_60 ( 0 , & V_21 -> V_805 -> V_828 . V_898 ) ;
F_60 ( V_62 , & ( V_21 -> V_805 -> V_828 . V_829 ) ) ;
if ( V_895 & V_113 ) {
V_114 = V_993 ;
F_60 ( 10 , & V_21 -> V_805 -> V_828 . V_830 ) ;
F_60 ( 4 , & V_21 -> V_805 -> V_828 . V_831 ) ;
} else
if ( V_895 & V_933 )
V_114 = V_994 ;
F_60 ( V_893 , V_21 -> V_151 + V_800 ) ;
if ( F_362 ( V_21 ) ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_276 ) ;
return - V_79 ;
}
V_976 = F_320 ( & ( V_21 -> V_805 -> V_827 ) ) ;
if ( ! ( V_976 & V_63 ) ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_277 ) ;
return - V_79 ;
}
V_21 -> V_114 = V_114 ;
V_21 -> V_62 = V_62 ;
if ( ! ( ( V_895 & V_113 ) ||
( V_895 & V_933 ) ) )
return 0 ;
if ( V_895 & V_113 ) {
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ ) {
F_60 ( V_67 , V_21 -> V_151 + V_995 ) ;
V_21 -> V_112 [ V_67 ] . V_117 =
F_320 ( V_21 -> V_151 + V_996 ) ;
}
V_981 [ 7 ] = V_21 -> V_567 + 8 ;
F_438 ( V_981 , F_26 ( V_981 ) , V_21 -> V_567 , 8 ,
V_21 -> V_133 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ )
memset ( V_21 -> V_112 [ V_67 ] . V_116 ,
( T_1 ) V_997 ,
V_21 -> V_920 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
struct V_129 * V_130 = & V_21 -> V_131 [ V_67 ] ;
V_130 -> V_998 = V_999 ;
V_130 -> V_23 = ( T_4 ) ( V_21 -> V_647 +
( V_67 * sizeof( struct V_337 ) ) ) ;
V_130 -> V_1000 = sizeof( struct V_337 ) ;
V_130 -> V_1001 = V_1002 ;
V_130 -> V_1003 =
F_158 ( V_1004 ) ;
V_130 -> V_1005 = 0 ;
V_130 -> V_127 = 0 ;
V_130 -> V_348 =
F_134 ( ( V_67 << V_597 ) ) ;
V_130 -> V_1006 =
F_134 ( V_21 -> V_570 +
( V_67 * sizeof( struct V_129 ) ) ) ;
}
} else if ( V_895 & V_933 ) {
T_5 V_808 , V_810 ;
T_4 V_1007 , V_809 ;
int V_20 ;
V_20 = F_334 ( V_21 -> V_28 , V_21 -> V_151 , & V_809 ,
& V_810 , & V_808 ) ;
F_353 ( F_247 ( struct V_138 , V_270 ) != 64 ) ;
V_982 [ 15 ] = V_21 -> V_567 + F_441 ;
F_438 ( V_982 , F_26 ( V_982 ) , V_21 -> V_567 ,
4 , V_21 -> V_137 ) ;
V_1007 = F_320 ( & V_21 -> V_805 -> V_1008 ) ;
F_353 ( F_247 ( struct V_804 ,
V_1008 ) != 0xb8 ) ;
V_21 -> V_1009 =
F_299 ( F_335 ( V_21 -> V_28 ,
V_810 ) +
V_808 + V_1007 ,
F_26 ( V_982 ) *
sizeof( * V_21 -> V_1009 ) ) ;
for ( V_67 = 0 ; V_67 < F_26 ( V_982 ) ; V_67 ++ )
F_60 ( V_982 [ V_67 ] , & V_21 -> V_1009 [ V_67 ] ) ;
}
F_60 ( V_893 , V_21 -> V_151 + V_800 ) ;
if ( F_362 ( V_21 ) ) {
F_74 ( & V_21 -> V_28 -> V_29 ,
L_278 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_442 ( struct V_1 * V_21 )
{
if ( V_21 -> V_131 ) {
F_321 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_131 ) ,
V_21 -> V_131 ,
V_21 -> V_570 ) ;
V_21 -> V_131 = NULL ;
V_21 -> V_570 = 0 ;
}
F_81 ( V_21 -> V_133 ) ;
V_21 -> V_133 = NULL ;
}
static int F_443 ( struct V_1 * V_21 )
{
V_21 -> V_567 =
F_320 ( & ( V_21 -> V_805 -> V_1010 ) ) ;
if ( V_21 -> V_567 > V_1011 )
V_21 -> V_567 = V_1011 ;
F_353 ( sizeof( struct V_129 ) %
V_1012 ) ;
V_21 -> V_131 =
F_319 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_131 ) ,
& ( V_21 -> V_570 ) ) ;
V_21 -> V_133 =
F_92 ( ( ( V_21 -> V_567 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ( V_21 -> V_131 == NULL ) ||
( V_21 -> V_133 == NULL ) )
goto V_912;
memset ( V_21 -> V_131 , 0 ,
V_21 -> V_235 * sizeof( * V_21 -> V_131 ) ) ;
return 0 ;
V_912:
F_442 ( V_21 ) ;
return - V_262 ;
}
static void F_444 ( struct V_1 * V_21 )
{
F_126 ( V_21 ) ;
if ( V_21 -> V_136 ) {
F_321 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_136 ) ,
V_21 -> V_136 ,
V_21 -> V_587 ) ;
V_21 -> V_136 = NULL ;
V_21 -> V_587 = 0 ;
}
F_81 ( V_21 -> V_137 ) ;
V_21 -> V_137 = NULL ;
}
static int F_445 ( struct V_1 * V_21 )
{
int V_20 ;
V_21 -> V_567 =
F_320 ( & ( V_21 -> V_805 -> V_1010 ) ) ;
if ( V_21 -> V_567 > V_983 )
V_21 -> V_567 = V_983 ;
F_353 ( sizeof( struct V_138 ) %
V_1013 ) ;
V_21 -> V_136 =
F_319 ( V_21 -> V_28 ,
V_21 -> V_235 * sizeof( * V_21 -> V_136 ) ,
& ( V_21 -> V_587 ) ) ;
V_21 -> V_137 =
F_92 ( ( ( V_21 -> V_567 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ( V_21 -> V_136 == NULL ) ||
( V_21 -> V_137 == NULL ) ) {
V_20 = - V_262 ;
goto V_912;
}
V_20 = F_127 ( V_21 ) ;
if ( V_20 )
goto V_912;
memset ( V_21 -> V_136 , 0 ,
V_21 -> V_235 * sizeof( * V_21 -> V_136 ) ) ;
return 0 ;
V_912:
F_444 ( V_21 ) ;
return V_20 ;
}
static void F_388 ( struct V_1 * V_21 )
{
F_81 ( V_21 -> V_122 ) ;
V_21 -> V_122 = NULL ;
F_386 ( V_21 ) ;
F_442 ( V_21 ) ;
F_444 ( V_21 ) ;
}
static int F_428 ( struct V_1 * V_21 )
{
T_4 V_895 ;
unsigned long V_62 = V_63 |
V_977 ;
int V_67 , V_20 ;
if ( V_958 )
return 0 ;
V_895 = F_320 ( & ( V_21 -> V_805 -> V_826 ) ) ;
if ( ! ( V_895 & V_1014 ) )
return 0 ;
if ( V_895 & V_113 ) {
V_62 |= V_113 |
V_978 ;
V_20 = F_443 ( V_21 ) ;
if ( V_20 )
return V_20 ;
} else if ( V_895 & V_933 ) {
V_62 |= V_933 |
V_978 ;
V_20 = F_445 ( V_21 ) ;
if ( V_20 )
return V_20 ;
}
V_21 -> V_128 = V_21 -> V_125 > 0 ? V_21 -> V_125 : 1 ;
F_351 ( V_21 ) ;
V_21 -> V_920 = V_21 -> V_120 * sizeof( T_5 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_128 ; V_67 ++ ) {
V_21 -> V_112 [ V_67 ] . V_116 = F_319 ( V_21 -> V_28 ,
V_21 -> V_920 ,
& ( V_21 -> V_112 [ V_67 ] . V_121 ) ) ;
if ( ! V_21 -> V_112 [ V_67 ] . V_116 ) {
V_20 = - V_262 ;
goto V_904;
}
V_21 -> V_112 [ V_67 ] . V_473 = V_21 -> V_120 ;
V_21 -> V_112 [ V_67 ] . V_118 = 1 ;
V_21 -> V_112 [ V_67 ] . V_117 = 0 ;
}
V_21 -> V_122 = F_92 ( ( ( V_751 + 1 ) *
sizeof( T_4 ) ) , V_202 ) ;
if ( ! V_21 -> V_122 ) {
V_20 = - V_262 ;
goto V_904;
}
V_20 = F_439 ( V_21 , V_895 ) ;
if ( V_20 )
goto V_905;
return 0 ;
V_905:
F_81 ( V_21 -> V_122 ) ;
V_21 -> V_122 = NULL ;
V_904:
F_386 ( V_21 ) ;
F_442 ( V_21 ) ;
F_444 ( V_21 ) ;
return V_20 ;
}
static int F_446 ( struct V_8 * V_9 )
{
return V_9 -> V_149 == V_150 || V_9 -> V_149 == V_153 ;
}
static void F_400 ( struct V_1 * V_21 )
{
struct V_8 * V_9 = NULL ;
int V_67 , V_1015 ;
int V_238 ;
do {
V_1015 = 0 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_235 ; V_67 ++ ) {
V_9 = V_21 -> V_237 + V_67 ;
V_238 = F_104 ( & V_9 -> V_238 ) ;
if ( V_238 > 1 )
V_1015 += F_446 ( V_9 ) ;
F_106 ( V_21 , V_9 ) ;
}
if ( V_1015 <= 0 )
break;
F_108 ( 100 ) ;
} while ( 1 );
}
static struct V_1016 * F_447 (
struct V_1017 * V_1017 )
{
struct V_1016 * V_1016 ;
struct V_1018 * V_1019 ;
V_1016 = F_115 ( sizeof( * V_1016 ) , V_202 ) ;
if ( ! V_1016 )
return NULL ;
V_1019 = F_448 ( V_1017 -> V_1020 -> V_1021 ,
V_1017 -> V_1022 ) ;
if ( ! V_1019 ) {
F_81 ( V_1016 ) ;
return NULL ;
}
V_1017 -> V_1022 ++ ;
V_1016 -> V_1019 = V_1019 ;
V_1016 -> V_1023 = V_1017 ;
return V_1016 ;
}
static void F_449 ( struct V_1016 * V_1016 )
{
struct V_1018 * V_1019 = V_1016 -> V_1019 ;
F_450 ( V_1016 -> V_1023 -> V_1024 , V_1019 ) ;
F_451 ( V_1019 ) ;
if ( V_1016 -> V_1025 )
F_406 ( & V_1016 -> V_1026 ) ;
F_81 ( V_1016 ) ;
}
static int F_452 ( struct V_1016 * V_1016 )
{
int V_20 ;
struct V_1017 * V_1017 ;
struct V_1018 * V_1019 ;
struct V_1027 * V_1028 ;
V_1017 = V_1016 -> V_1023 ;
V_1019 = V_1016 -> V_1019 ;
V_1028 = & V_1019 -> V_1028 ;
memset ( V_1028 , 0 , sizeof( * V_1028 ) ) ;
V_1028 -> V_87 = V_1017 -> V_87 ;
V_1028 -> V_517 = V_1029 ;
V_1028 -> V_1030 = V_1031 ;
V_1028 -> V_1032 = V_1031 ;
V_1019 -> V_1033 = V_1034 ;
V_1019 -> V_1035 = V_1034 ;
V_1019 -> V_1036 = V_1034 ;
V_1019 -> V_1037 = V_1034 ;
V_1019 -> V_1038 = V_1034 ;
V_20 = F_453 ( V_1016 -> V_1019 ) ;
if ( V_20 )
return V_20 ;
F_454 ( V_1017 -> V_1024 , V_1016 -> V_1019 ) ;
F_93 ( & V_1016 -> V_1026 ,
& V_1017 -> V_1039 ) ;
V_1016 -> V_1025 = true ;
return 0 ;
}
static int
F_455 ( struct V_1017 * V_1017 ,
struct V_254 * V_255 )
{
struct V_1027 * V_1028 ;
V_1028 = & V_255 -> V_1028 ;
V_1028 -> V_87 = V_1017 -> V_87 ;
V_1028 -> V_1030 = V_1031 ;
V_1028 -> V_1032 = V_1031 ;
return F_456 ( V_255 ) ;
}
static struct V_1017
* F_457 ( struct V_1040 * V_1040 ,
T_5 V_87 )
{
int V_20 ;
struct V_1017 * V_1017 ;
struct V_1041 * V_1024 ;
V_1017 = F_115 ( sizeof( * V_1017 ) , V_202 ) ;
if ( ! V_1017 )
return NULL ;
F_421 ( & V_1017 -> V_1039 ) ;
V_1017 -> V_1020 = V_1040 ;
V_1024 = F_458 ( V_1040 -> V_1021 ) ;
if ( ! V_1024 )
goto V_1042;
V_20 = F_459 ( V_1024 ) ;
if ( V_20 )
goto V_1043;
V_1017 -> V_1024 = V_1024 ;
V_1017 -> V_87 = V_87 ;
F_93 ( & V_1017 -> V_1044 ,
& V_1040 -> V_1045 ) ;
return V_1017 ;
V_1043:
F_460 ( V_1024 ) ;
V_1042:
F_81 ( V_1017 ) ;
return NULL ;
}
static void F_461 ( struct V_1017 * V_1017 )
{
struct V_1016 * V_1016 ;
struct V_1016 * V_1046 ;
F_462 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_449 ( V_1016 ) ;
F_463 ( V_1017 -> V_1024 ) ;
F_406 ( & V_1017 -> V_1044 ) ;
F_81 ( V_1017 ) ;
}
static struct V_1040 * F_464 ( struct V_41 * V_1021 )
{
struct V_1040 * V_1040 ;
V_1040 = F_115 ( sizeof( * V_1040 ) , V_202 ) ;
if ( V_1040 ) {
V_1040 -> V_1021 = V_1021 ;
F_421 ( & V_1040 -> V_1045 ) ;
}
return V_1040 ;
}
static void F_465 ( struct V_1040 * V_1040 )
{
struct V_1017 * V_1017 ;
struct V_1017 * V_1046 ;
if ( ! V_1040 )
return;
F_462 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_461 ( V_1017 ) ;
F_81 ( V_1040 ) ;
}
static struct V_71
* F_120 ( struct V_1 * V_21 ,
struct V_254 * V_255 )
{
int V_67 ;
struct V_71 * V_41 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_161 ; V_67 ++ ) {
V_41 = V_21 -> V_29 [ V_67 ] ;
if ( ! V_41 -> V_1041 )
continue;
if ( V_41 -> V_1041 -> V_255 == V_255 )
return V_41 ;
}
return NULL ;
}
static int F_230 ( struct V_1 * V_21 )
{
int V_20 ;
struct V_41 * V_1021 ;
struct V_1040 * V_1040 ;
struct V_1017 * V_1017 ;
struct V_1016 * V_1016 ;
V_1021 = & V_21 -> V_58 -> V_1047 ;
V_1040 = F_464 ( V_1021 ) ;
if ( ! V_1040 )
return - V_262 ;
V_1017 = F_457 ( V_1040 , V_21 -> V_87 ) ;
if ( ! V_1017 ) {
V_20 = - V_79 ;
goto V_1048;
}
V_1016 = F_447 ( V_1017 ) ;
if ( ! V_1016 ) {
V_20 = - V_79 ;
goto V_1043;
}
V_20 = F_452 ( V_1016 ) ;
if ( V_20 )
goto V_1049;
V_21 -> V_236 = V_1040 ;
return 0 ;
V_1049:
F_449 ( V_1016 ) ;
V_1043:
F_461 ( V_1017 ) ;
V_1048:
F_465 ( V_1040 ) ;
return V_20 ;
}
static void F_437 ( struct V_1 * V_21 )
{
F_465 ( V_21 -> V_236 ) ;
}
static int F_102 ( struct V_1040 * V_1040 ,
struct V_71 * V_41 )
{
int V_20 ;
struct V_1017 * V_1017 ;
struct V_254 * V_255 ;
V_1017 = F_457 ( V_1040 , V_41 -> V_87 ) ;
if ( ! V_1017 )
return - V_262 ;
V_255 = F_466 ( V_1017 -> V_1024 ) ;
if ( ! V_255 ) {
V_20 = - V_79 ;
goto V_1043;
}
V_1017 -> V_255 = V_255 ;
V_41 -> V_1041 = V_1017 ;
V_20 = F_455 ( V_1017 , V_255 ) ;
if ( V_20 )
goto V_1043;
return 0 ;
V_1043:
F_461 ( V_1017 ) ;
V_41 -> V_1041 = NULL ;
return V_20 ;
}
static void F_113 ( struct V_71 * V_41 )
{
if ( V_41 -> V_1041 ) {
F_461 ( V_41 -> V_1041 ) ;
V_41 -> V_1041 = NULL ;
}
}
static int
F_467 ( struct V_1018 * V_1019 )
{
return 0 ;
}
static int
F_468 ( struct V_254 * V_255 , T_5 * V_1050 )
{
* V_1050 = 0 ;
return 0 ;
}
static int
F_469 ( struct V_254 * V_255 )
{
return - V_1051 ;
}
static int
F_470 ( struct V_1018 * V_1019 , int V_1052 )
{
return 0 ;
}
static int
F_471 ( struct V_1018 * V_1019 , int V_1053 )
{
return 0 ;
}
static int
F_472 ( struct V_1018 * V_1019 )
{
return 0 ;
}
static void
F_473 ( struct V_1018 * V_1019 )
{
}
static int
F_474 ( struct V_1018 * V_1019 , struct V_1054 * V_1055 )
{
return - V_54 ;
}
static int
F_475 ( struct V_6 * V_46 , struct V_254 * V_255 ,
struct V_651 * V_1056 )
{
return - V_54 ;
}
static int T_18 F_476 ( void )
{
int V_20 ;
V_672 =
F_477 ( & V_1057 ) ;
if ( ! V_672 )
return - V_79 ;
V_20 = F_478 ( & V_1058 ) ;
if ( V_20 )
F_479 ( V_672 ) ;
return V_20 ;
}
static void T_19 F_480 ( void )
{
F_481 ( & V_1058 ) ;
F_479 ( V_672 ) ;
}
