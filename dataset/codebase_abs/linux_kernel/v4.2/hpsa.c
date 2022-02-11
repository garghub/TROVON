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
if ( V_16 != V_27 || V_17 == - 1 )
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
static inline T_4 F_39 ( struct V_1 * V_22 , T_1 V_89 )
{
T_4 V_65 ;
struct V_90 * V_91 = & V_22 -> V_92 [ V_89 ] ;
if ( V_22 -> V_63 & V_93 )
return V_22 -> V_94 . V_95 ( V_22 , V_89 ) ;
if ( F_40 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_22 -> V_94 . V_95 ( V_22 , V_89 ) ;
if ( ( V_91 -> V_96 [ V_91 -> V_97 ] & 1 ) == V_91 -> V_98 ) {
V_65 = V_91 -> V_96 [ V_91 -> V_97 ] ;
V_91 -> V_97 ++ ;
F_41 ( & V_22 -> V_62 ) ;
} else {
V_65 = V_99 ;
}
if ( V_91 -> V_97 == V_22 -> V_100 ) {
V_91 -> V_97 = 0 ;
V_91 -> V_98 ^= 1 ;
}
return V_65 ;
}
static void F_42 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_92 )
{
if ( F_43 ( V_22 -> V_63 & V_64 ) ) {
V_9 -> V_101 |= 1 | ( V_22 -> V_102 [ V_9 -> V_103 . V_104 ] << 1 ) ;
if ( F_40 ( ! V_22 -> V_105 ) )
return;
if ( F_43 ( V_92 == V_106 ) )
V_9 -> V_103 . V_107 =
F_44 () % V_22 -> V_108 ;
else
V_9 -> V_103 . V_107 = V_92 % V_22 -> V_108 ;
}
}
static void F_45 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_92 )
{
struct V_109 * V_110 = & V_22 -> V_111 [ V_9 -> V_112 ] ;
if ( F_43 ( V_92 == V_106 ) )
V_110 -> V_107 = F_46 () % V_22 -> V_108 ;
else
V_110 -> V_107 = V_92 % V_22 -> V_108 ;
V_9 -> V_101 |= 1 | ( V_22 -> V_113 [ V_9 -> V_103 . V_104 ] << 1 ) |
V_114 ;
}
static void F_47 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_92 )
{
struct V_115 * V_110 = (struct V_115 * )
& V_22 -> V_116 [ V_9 -> V_112 ] ;
if ( F_43 ( V_92 == V_106 ) )
V_110 -> V_92 = F_46 () % V_22 -> V_108 ;
else
V_110 -> V_92 = V_92 % V_22 -> V_108 ;
V_9 -> V_101 |= V_22 -> V_117 [ 0 ] ;
}
static void F_48 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
int V_92 )
{
struct V_118 * V_110 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
if ( F_43 ( V_92 == V_106 ) )
V_110 -> V_92 = F_46 () % V_22 -> V_108 ;
else
V_110 -> V_92 = V_92 % V_22 -> V_108 ;
V_9 -> V_101 |= ( V_22 -> V_117 [ V_110 -> V_119 ] ) ;
}
static int F_49 ( T_1 * V_120 )
{
return V_120 [ 0 ] == V_121 && V_120 [ 6 ] == V_122 ;
}
static void F_50 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( ! F_49 ( V_9 -> V_123 . V_124 ) )
return;
F_51 ( & V_22 -> V_125 ) ;
V_22 -> V_126 = V_127 ;
}
static void F_52 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( F_49 ( V_9 -> V_123 . V_124 ) &&
F_53 ( & V_22 -> V_125 ) )
V_22 -> V_126 = V_128 ;
}
static void F_54 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_92 )
{
F_50 ( V_22 , V_9 ) ;
F_51 ( & V_22 -> V_62 ) ;
switch ( V_9 -> V_129 ) {
case V_130 :
F_45 ( V_22 , V_9 , V_92 ) ;
F_55 ( V_9 -> V_101 , V_22 -> V_131 + V_132 ) ;
break;
case V_133 :
F_48 ( V_22 , V_9 , V_92 ) ;
F_55 ( V_9 -> V_101 , V_22 -> V_131 + V_134 ) ;
break;
case V_135 :
F_47 ( V_22 , V_9 , V_92 ) ;
F_55 ( V_9 -> V_101 , V_22 -> V_131 + V_134 ) ;
break;
default:
F_42 ( V_22 , V_9 , V_92 ) ;
V_22 -> V_94 . V_136 ( V_22 , V_9 ) ;
}
}
static void F_56 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_40 ( F_5 ( V_9 ) ) )
return F_57 ( V_9 ) ;
F_54 ( V_22 , V_9 , V_106 ) ;
}
static inline int F_58 ( unsigned char V_72 [] )
{
return memcmp ( V_72 , V_137 , 8 ) == 0 ;
}
static inline int F_59 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_61 )
return 0 ;
if ( ( V_22 -> V_61 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_22 ,
unsigned char V_72 [] , int V_138 , int * V_139 , int * V_140 )
{
int V_68 , V_141 = 0 ;
F_61 ( V_142 , V_143 ) ;
F_62 ( V_142 , V_143 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] -> V_138 == V_138 && V_22 -> V_30 [ V_68 ] -> V_139 != - 1 )
F_63 ( V_22 -> V_30 [ V_68 ] -> V_139 , V_142 ) ;
}
V_68 = F_64 ( V_142 , V_143 ) ;
if ( V_68 < V_143 ) {
* V_139 = V_68 ;
* V_140 = 0 ;
V_141 = 1 ;
}
return ! V_141 ;
}
static inline void F_65 ( const char * V_145 , struct V_1 * V_22 ,
struct V_75 * V_30 , char * V_146 )
{
F_66 ( V_145 , & V_22 -> V_29 -> V_30 ,
L_25 ,
V_22 -> V_59 -> V_147 , V_30 -> V_138 , V_30 -> V_139 , V_30 -> V_140 ,
V_146 ,
F_67 ( V_30 -> V_148 ) ,
V_30 -> V_149 ,
V_30 -> V_150 ,
V_30 -> V_82 > V_83 ?
L_26 : V_84 [ V_30 -> V_82 ] ,
V_30 -> V_151 ? '+' : '-' ,
V_30 -> V_88 ? '+' : '-' ,
V_30 -> V_152 ) ;
}
static int F_68 ( struct V_1 * V_22 , int V_153 ,
struct V_75 * V_42 ,
struct V_75 * V_154 [] , int * V_155 )
{
int V_156 = V_22 -> V_144 ;
int V_68 ;
unsigned char V_157 [ 8 ] , V_158 [ 8 ] ;
struct V_75 * V_159 ;
if ( V_156 >= V_143 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_27
L_28 ) ;
return - 1 ;
}
if ( V_42 -> V_140 != - 1 )
goto V_160;
if ( V_42 -> V_72 [ 4 ] == 0 ) {
if ( F_60 ( V_22 , V_42 -> V_72 ,
V_42 -> V_138 , & V_42 -> V_139 , & V_42 -> V_140 ) != 0 )
return - 1 ;
goto V_160;
}
memcpy ( V_157 , V_42 -> V_72 , 8 ) ;
V_157 [ 4 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_156 ; V_68 ++ ) {
V_159 = V_22 -> V_30 [ V_68 ] ;
memcpy ( V_158 , V_159 -> V_72 , 8 ) ;
V_158 [ 4 ] = 0 ;
if ( memcmp ( V_157 , V_158 , 8 ) == 0 ) {
V_42 -> V_138 = V_159 -> V_138 ;
V_42 -> V_139 = V_159 -> V_139 ;
V_42 -> V_140 = V_42 -> V_72 [ 4 ] ;
break;
}
}
if ( V_42 -> V_140 == - 1 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_29
L_30
L_31 ) ;
return - 1 ;
}
V_160:
V_22 -> V_30 [ V_156 ] = V_42 ;
V_22 -> V_144 ++ ;
V_154 [ * V_155 ] = V_42 ;
( * V_155 ) ++ ;
F_65 ( V_161 , V_22 , V_42 ,
V_42 -> V_152 & V_162 ? L_32 : L_33 ) ;
V_42 -> V_163 = V_42 -> V_88 ;
V_42 -> V_88 = 0 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_22 , int V_153 ,
int V_164 , struct V_75 * V_165 )
{
int V_88 ;
F_71 ( V_164 < 0 || V_164 >= V_143 ) ;
V_22 -> V_30 [ V_164 ] -> V_82 = V_165 -> V_82 ;
if ( V_165 -> V_151 && V_165 -> V_88 ) {
V_22 -> V_30 [ V_164 ] -> V_166 = V_165 -> V_166 ;
V_22 -> V_30 [ V_164 ] -> V_167 = V_165 -> V_167 ;
}
if ( V_165 -> V_168 ) {
V_22 -> V_30 [ V_164 ] -> V_167 = V_165 -> V_167 ;
F_72 () ;
}
V_22 -> V_30 [ V_164 ] -> V_168 = V_165 -> V_168 ;
V_22 -> V_30 [ V_164 ] -> V_151 = V_165 -> V_151 ;
V_22 -> V_30 [ V_164 ] -> V_169 = V_165 -> V_169 ;
V_22 -> V_30 [ V_164 ] -> V_170 = V_165 -> V_170 ;
V_22 -> V_30 [ V_164 ] -> V_163 = V_165 -> V_88 ;
if ( ! V_165 -> V_88 )
V_22 -> V_30 [ V_164 ] -> V_88 = 0 ;
V_88 = V_22 -> V_30 [ V_164 ] -> V_88 ;
V_22 -> V_30 [ V_164 ] -> V_88 = V_22 -> V_30 [ V_164 ] -> V_163 ;
F_65 ( V_161 , V_22 , V_22 -> V_30 [ V_164 ] , L_34 ) ;
V_22 -> V_30 [ V_164 ] -> V_88 = V_88 ;
}
static void F_73 ( struct V_1 * V_22 , int V_153 ,
int V_164 , struct V_75 * V_165 ,
struct V_75 * V_154 [] , int * V_155 ,
struct V_75 * V_171 [] , int * V_172 )
{
F_71 ( V_164 < 0 || V_164 >= V_143 ) ;
V_171 [ * V_172 ] = V_22 -> V_30 [ V_164 ] ;
( * V_172 ) ++ ;
if ( V_165 -> V_139 == - 1 ) {
V_165 -> V_139 = V_22 -> V_30 [ V_164 ] -> V_139 ;
V_165 -> V_140 = V_22 -> V_30 [ V_164 ] -> V_140 ;
}
V_22 -> V_30 [ V_164 ] = V_165 ;
V_154 [ * V_155 ] = V_165 ;
( * V_155 ) ++ ;
F_65 ( V_161 , V_22 , V_165 , L_35 ) ;
V_165 -> V_163 = V_165 -> V_88 ;
V_165 -> V_88 = 0 ;
}
static void F_74 ( struct V_1 * V_22 , int V_153 , int V_164 ,
struct V_75 * V_171 [] , int * V_172 )
{
int V_68 ;
struct V_75 * V_159 ;
F_71 ( V_164 < 0 || V_164 >= V_143 ) ;
V_159 = V_22 -> V_30 [ V_164 ] ;
V_171 [ * V_172 ] = V_22 -> V_30 [ V_164 ] ;
( * V_172 ) ++ ;
for ( V_68 = V_164 ; V_68 < V_22 -> V_144 - 1 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] = V_22 -> V_30 [ V_68 + 1 ] ;
V_22 -> V_144 -- ;
F_65 ( V_161 , V_22 , V_159 , L_36 ) ;
}
static void F_75 ( struct V_1 * V_22 ,
struct V_75 * V_154 )
{
unsigned long V_77 ;
int V_68 , V_173 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ ) {
if ( V_22 -> V_30 [ V_68 ] == V_154 ) {
for ( V_173 = V_68 ; V_173 < V_22 -> V_144 - 1 ; V_173 ++ )
V_22 -> V_30 [ V_173 ] = V_22 -> V_30 [ V_173 + 1 ] ;
V_22 -> V_144 -- ;
break;
}
}
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_76 ( V_154 ) ;
}
static inline int F_77 ( struct V_75 * V_174 ,
struct V_75 * V_175 )
{
if ( memcmp ( V_174 -> V_72 , V_175 -> V_72 ,
sizeof( V_174 -> V_72 ) ) != 0 )
return 0 ;
if ( memcmp ( V_174 -> V_87 , V_175 -> V_87 ,
sizeof( V_174 -> V_87 ) ) != 0 )
return 0 ;
if ( memcmp ( V_174 -> V_150 , V_175 -> V_150 , sizeof( V_174 -> V_150 ) ) != 0 )
return 0 ;
if ( memcmp ( V_174 -> V_149 , V_175 -> V_149 , sizeof( V_174 -> V_149 ) ) != 0 )
return 0 ;
if ( V_174 -> V_148 != V_175 -> V_148 )
return 0 ;
if ( V_174 -> V_138 != V_175 -> V_138 )
return 0 ;
return 1 ;
}
static inline int F_78 ( struct V_75 * V_174 ,
struct V_75 * V_175 )
{
if ( V_174 -> V_82 != V_175 -> V_82 )
return 1 ;
if ( V_174 -> V_151 != V_175 -> V_151 )
return 1 ;
if ( V_174 -> V_88 != V_175 -> V_88 )
return 1 ;
if ( V_174 -> V_170 != V_175 -> V_170 )
return 1 ;
return 0 ;
}
static int F_79 ( struct V_75 * V_176 ,
struct V_75 * V_177 [] , int V_178 ,
int * V_179 )
{
int V_68 ;
#define F_80 0
#define F_81 1
#define F_82 2
#define F_83 3
for ( V_68 = 0 ; V_68 < V_178 ; V_68 ++ ) {
if ( V_177 [ V_68 ] == NULL )
continue;
if ( F_84 ( V_176 -> V_72 , V_177 [ V_68 ] -> V_72 ) ) {
* V_179 = V_68 ;
if ( F_77 ( V_176 , V_177 [ V_68 ] ) ) {
if ( F_78 ( V_176 , V_177 [ V_68 ] ) )
return F_83 ;
return F_82 ;
} else {
if ( V_176 -> V_180 )
return F_80 ;
return F_81 ;
}
}
}
* V_179 = - 1 ;
return F_80 ;
}
static void F_85 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_181 * V_42 ;
unsigned long V_77 ;
F_34 ( & V_22 -> V_182 , V_77 ) ;
F_86 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_42 -> V_72 , V_72 ,
sizeof( V_42 -> V_72 ) ) == 0 ) {
F_35 ( & V_22 -> V_182 , V_77 ) ;
return;
}
}
F_35 ( & V_22 -> V_182 , V_77 ) ;
V_42 = F_87 ( sizeof( * V_42 ) , V_183 ) ;
if ( ! V_42 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_37 , V_184 ) ;
return;
}
memcpy ( V_42 -> V_72 , V_72 , sizeof( V_42 -> V_72 ) ) ;
F_34 ( & V_22 -> V_182 , V_77 ) ;
F_88 ( & V_42 -> V_185 , & V_22 -> V_186 ) ;
F_35 ( & V_22 -> V_182 , V_77 ) ;
}
static void F_89 ( struct V_1 * V_22 ,
struct V_75 * V_159 )
{
if ( V_159 -> V_180 == V_187 )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_38 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
switch ( V_159 -> V_180 ) {
case V_188 :
break;
case V_189 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_39 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_190 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_40 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_191 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_41 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_192 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_42 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_193 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_43 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_194 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_44 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_195 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_45 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_196 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_46 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_197 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_47 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
case V_198 :
F_90 ( & V_22 -> V_29 -> V_30 ,
L_48 ,
V_22 -> V_59 -> V_147 ,
V_159 -> V_138 , V_159 -> V_139 , V_159 -> V_140 ) ;
break;
}
}
static void F_91 ( struct V_1 * V_22 ,
struct V_75 * V_30 [] , int V_144 ,
struct V_75 * V_199 )
{
struct V_200 * V_201 = & V_199 -> V_166 ;
struct V_202 * V_203 = & V_201 -> V_204 [ 0 ] ;
int V_68 , V_173 ;
int V_205 = F_92 ( V_201 -> V_206 ) +
F_92 ( V_201 -> V_207 ) ;
int V_208 = F_92 ( V_201 -> V_209 ) *
F_92 ( V_201 -> V_210 ) *
V_205 ;
int V_211 = F_92 ( V_201 -> V_210 ) *
V_205 ;
int V_212 ;
if ( V_208 > V_213 )
V_208 = V_213 ;
V_199 -> V_214 = V_208 ;
V_212 = 0 ;
for ( V_68 = 0 ; V_68 < V_208 ; V_68 ++ ) {
V_199 -> V_215 [ V_68 ] = NULL ;
if ( ! V_199 -> V_151 )
continue;
for ( V_173 = 0 ; V_173 < V_144 ; V_173 ++ ) {
if ( V_30 [ V_173 ] -> V_148 != V_216 )
continue;
if ( F_31 ( V_30 [ V_173 ] -> V_72 ) )
continue;
if ( V_30 [ V_173 ] -> V_167 != V_203 [ V_68 ] . V_167 )
continue;
V_199 -> V_215 [ V_68 ] = V_30 [ V_173 ] ;
if ( V_68 < V_211 )
V_212 = F_93 ( V_22 -> V_217 , V_212 +
V_199 -> V_215 [ V_68 ] -> V_170 ) ;
break;
}
if ( ! V_199 -> V_215 [ V_68 ] ) {
V_199 -> V_88 = 0 ;
V_199 -> V_163 = 0 ;
V_199 -> V_170 = 8 ;
}
}
if ( V_208 )
V_199 -> V_170 = V_212 ;
else
V_199 -> V_170 = V_22 -> V_217 ;
}
static void F_94 ( struct V_1 * V_22 ,
struct V_75 * V_30 [] , int V_144 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_144 ; V_68 ++ ) {
if ( V_30 [ V_68 ] -> V_148 != V_216 )
continue;
if ( ! F_31 ( V_30 [ V_68 ] -> V_72 ) )
continue;
if ( V_30 [ V_68 ] -> V_88 )
continue;
F_91 ( V_22 , V_30 , V_144 , V_30 [ V_68 ] ) ;
}
}
static void F_95 ( struct V_1 * V_22 , int V_153 ,
struct V_75 * V_159 [] , int V_218 )
{
int V_68 , V_164 , V_219 , V_220 = 0 ;
struct V_75 * V_221 ;
unsigned long V_77 ;
struct V_75 * * V_154 , * * V_171 ;
int V_155 , V_172 ;
struct V_6 * V_7 = NULL ;
V_154 = F_96 ( sizeof( * V_154 ) * V_143 , V_183 ) ;
V_171 = F_96 ( sizeof( * V_171 ) * V_143 , V_183 ) ;
if ( ! V_154 || ! V_171 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_49
L_50 ) ;
goto V_222;
}
F_34 ( & V_22 -> V_223 , V_77 ) ;
V_68 = 0 ;
V_172 = 0 ;
V_155 = 0 ;
while ( V_68 < V_22 -> V_144 ) {
V_221 = V_22 -> V_30 [ V_68 ] ;
V_219 = F_79 ( V_221 , V_159 , V_218 , & V_164 ) ;
if ( V_219 == F_80 ) {
V_220 ++ ;
F_74 ( V_22 , V_153 , V_68 ,
V_171 , & V_172 ) ;
continue;
} else if ( V_219 == F_81 ) {
V_220 ++ ;
F_73 ( V_22 , V_153 , V_68 , V_159 [ V_164 ] ,
V_154 , & V_155 , V_171 , & V_172 ) ;
V_159 [ V_164 ] = NULL ;
} else if ( V_219 == F_83 ) {
F_70 ( V_22 , V_153 , V_68 , V_159 [ V_164 ] ) ;
}
V_68 ++ ;
}
for ( V_68 = 0 ; V_68 < V_218 ; V_68 ++ ) {
if ( ! V_159 [ V_68 ] )
continue;
if ( V_159 [ V_68 ] -> V_180 ) {
F_89 ( V_22 , V_159 [ V_68 ] ) ;
F_65 ( V_161 , V_22 , V_159 [ V_68 ] , L_51 ) ;
continue;
}
V_219 = F_79 ( V_159 [ V_68 ] , V_22 -> V_30 ,
V_22 -> V_144 , & V_164 ) ;
if ( V_219 == F_80 ) {
V_220 ++ ;
if ( F_68 ( V_22 , V_153 , V_159 [ V_68 ] ,
V_154 , & V_155 ) != 0 )
break;
V_159 [ V_68 ] = NULL ;
} else if ( V_219 == F_81 ) {
V_220 ++ ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_52 ) ;
}
}
F_94 ( V_22 , V_22 -> V_30 , V_22 -> V_144 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_88 = V_22 -> V_30 [ V_68 ] -> V_163 ;
F_35 ( & V_22 -> V_223 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_218 ; V_68 ++ ) {
if ( ! V_159 [ V_68 ] )
continue;
if ( V_159 [ V_68 ] -> V_180 )
F_85 ( V_22 , V_159 [ V_68 ] -> V_72 ) ;
}
if ( V_153 == - 1 || ! V_220 )
goto V_222;
V_7 = V_22 -> V_59 ;
for ( V_68 = 0 ; V_68 < V_172 ; V_68 ++ ) {
if ( V_171 [ V_68 ] -> V_152 & V_162 ) {
struct V_2 * V_3 =
F_97 ( V_7 , V_171 [ V_68 ] -> V_138 ,
V_171 [ V_68 ] -> V_139 , V_171 [ V_68 ] -> V_140 ) ;
if ( V_3 != NULL ) {
F_98 ( V_3 ) ;
F_99 ( V_3 ) ;
} else {
F_65 ( V_224 , V_22 , V_171 [ V_68 ] ,
L_53 ) ;
}
}
F_76 ( V_171 [ V_68 ] ) ;
V_171 [ V_68 ] = NULL ;
}
for ( V_68 = 0 ; V_68 < V_155 ; V_68 ++ ) {
if ( ! ( V_154 [ V_68 ] -> V_152 & V_162 ) )
continue;
if ( F_100 ( V_7 , V_154 [ V_68 ] -> V_138 ,
V_154 [ V_68 ] -> V_139 , V_154 [ V_68 ] -> V_140 ) == 0 )
continue;
F_65 ( V_224 , V_22 , V_154 [ V_68 ] ,
L_54 ) ;
F_75 ( V_22 , V_154 [ V_68 ] ) ;
V_154 [ V_68 ] = NULL ;
}
V_222:
F_76 ( V_154 ) ;
F_76 ( V_171 ) ;
}
static struct V_75 * F_101 ( struct V_1 * V_22 ,
int V_138 , int V_139 , int V_140 )
{
int V_68 ;
struct V_75 * V_159 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ ) {
V_159 = V_22 -> V_30 [ V_68 ] ;
if ( V_159 -> V_138 == V_138 && V_159 -> V_139 == V_139 && V_159 -> V_140 == V_140 )
return V_159 ;
}
return NULL ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_75 * V_159 ;
unsigned long V_77 ;
struct V_1 * V_22 ;
V_22 = F_1 ( V_3 ) ;
F_34 ( & V_22 -> V_223 , V_77 ) ;
V_159 = F_101 ( V_22 , F_103 ( V_3 ) ,
F_104 ( V_3 ) , V_3 -> V_140 ) ;
if ( F_43 ( V_159 ) ) {
F_105 ( & V_159 -> V_225 , 0 ) ;
V_3 -> V_79 = ( V_159 -> V_152 & V_162 ) ? V_159 : NULL ;
} else
V_3 -> V_79 = NULL ;
F_35 ( & V_22 -> V_223 , V_77 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_75 * V_159 ;
int V_170 ;
V_159 = V_3 -> V_79 ;
V_3 -> V_226 = ! V_159 || ! ( V_159 -> V_152 & V_227 ) ;
if ( V_159 )
V_170 = V_159 -> V_170 != 0 ?
V_159 -> V_170 : V_3 -> V_5 -> V_228 ;
else
V_170 = V_3 -> V_5 -> V_228 ;
F_107 ( V_3 , V_170 ) ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 )
{
}
static void F_109 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_229 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
F_76 ( V_22 -> V_229 [ V_68 ] ) ;
V_22 -> V_229 [ V_68 ] = NULL ;
}
F_76 ( V_22 -> V_229 ) ;
V_22 -> V_229 = NULL ;
}
static int F_110 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_230 <= 0 )
return 0 ;
V_22 -> V_229 =
F_96 ( sizeof( * V_22 -> V_229 ) * V_22 -> V_217 ,
V_183 ) ;
if ( ! V_22 -> V_229 )
return - V_231 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
V_22 -> V_229 [ V_68 ] =
F_87 ( sizeof( * V_22 -> V_229 [ V_68 ] ) *
V_22 -> V_232 , V_183 ) ;
if ( ! V_22 -> V_229 [ V_68 ] )
goto V_233;
}
return 0 ;
V_233:
F_109 ( V_22 ) ;
return - V_231 ;
}
static void F_111 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_234 )
return;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
F_76 ( V_22 -> V_234 [ V_68 ] ) ;
V_22 -> V_234 [ V_68 ] = NULL ;
}
F_76 ( V_22 -> V_234 ) ;
V_22 -> V_234 = NULL ;
}
static int F_112 ( struct V_1 * V_22 )
{
int V_68 ;
if ( V_22 -> V_230 <= 0 )
return 0 ;
V_22 -> V_234 = F_96 ( sizeof( * V_22 -> V_234 ) * V_22 -> V_217 ,
V_183 ) ;
if ( ! V_22 -> V_234 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_55 ) ;
return - V_231 ;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
V_22 -> V_234 [ V_68 ] = F_87 ( sizeof( * V_22 -> V_234 [ V_68 ] ) *
V_22 -> V_230 , V_183 ) ;
if ( ! V_22 -> V_234 [ V_68 ] ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_56 ) ;
goto V_233;
}
}
return 0 ;
V_233:
F_111 ( V_22 ) ;
return - V_231 ;
}
static int F_113 ( struct V_1 * V_22 ,
struct V_118 * V_110 , struct V_8 * V_9 )
{
struct V_235 * V_236 ;
T_5 V_237 ;
T_4 V_238 ;
V_236 = V_22 -> V_229 [ V_9 -> V_112 ] ;
V_238 = F_114 ( V_110 -> V_239 ) ;
V_237 = F_115 ( V_22 -> V_29 , V_236 , V_238 ,
V_240 ) ;
if ( F_116 ( & V_22 -> V_29 -> V_30 , V_237 ) ) {
V_110 -> V_241 -> V_242 = 0 ;
return - 1 ;
}
V_110 -> V_241 -> V_242 = F_117 ( V_237 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_22 ,
struct V_118 * V_110 )
{
struct V_235 * V_243 ;
T_5 V_237 ;
T_4 V_238 ;
V_243 = V_110 -> V_241 ;
V_237 = F_119 ( V_243 -> V_242 ) ;
V_238 = F_114 ( V_110 -> V_239 ) ;
F_120 ( V_22 -> V_29 , V_237 , V_238 , V_240 ) ;
}
static int F_121 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_244 * V_243 , * V_236 ;
T_5 V_237 ;
T_4 V_245 ;
V_243 = & V_9 -> V_246 [ V_22 -> V_247 - 1 ] ;
V_236 = V_22 -> V_234 [ V_9 -> V_112 ] ;
V_243 -> V_248 = F_122 ( V_249 ) ;
V_245 = sizeof( * V_243 ) *
( F_92 ( V_9 -> V_103 . V_250 ) - V_22 -> V_247 ) ;
V_243 -> V_251 = F_122 ( V_245 ) ;
V_237 = F_115 ( V_22 -> V_29 , V_236 , V_245 ,
V_240 ) ;
if ( F_116 ( & V_22 -> V_29 -> V_30 , V_237 ) ) {
V_243 -> V_252 = F_117 ( 0 ) ;
return - 1 ;
}
V_243 -> V_252 = F_117 ( V_237 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_244 * V_243 ;
if ( F_92 ( V_9 -> V_103 . V_250 ) <= V_22 -> V_247 )
return;
V_243 = & V_9 -> V_246 [ V_22 -> V_247 - 1 ] ;
F_120 ( V_22 -> V_29 , F_119 ( V_243 -> V_252 ) ,
F_114 ( V_243 -> V_251 ) , V_240 ) ;
}
static int F_124 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
struct V_253 * V_254 ,
struct V_118 * V_255 )
{
int V_239 ;
int V_256 = 0 ;
T_4 V_257 = 0 ;
switch ( V_255 -> V_258 . V_259 ) {
case V_260 :
switch ( V_255 -> V_258 . V_49 ) {
case V_261 :
break;
case V_262 :
V_254 -> V_263 |= V_264 ;
if ( V_255 -> V_258 . V_265 !=
V_266 ) {
memset ( V_254 -> V_267 , 0 ,
V_268 ) ;
break;
}
V_239 = V_255 -> V_258 . V_15 ;
if ( V_239 > V_268 )
V_239 = V_268 ;
if ( V_239 > sizeof( V_255 -> V_258 . V_269 ) )
V_239 =
sizeof( V_255 -> V_258 . V_269 ) ;
memcpy ( V_254 -> V_267 ,
V_255 -> V_258 . V_269 , V_239 ) ;
V_256 = 1 ;
break;
case V_270 :
V_256 = 1 ;
break;
case V_271 :
V_256 = 1 ;
break;
case V_272 :
V_256 = 1 ;
break;
case V_273 :
V_256 = 1 ;
break;
default:
V_256 = 1 ;
break;
}
break;
case V_274 :
switch ( V_255 -> V_258 . V_49 ) {
case V_275 :
case V_276 :
case V_277 :
V_256 = 1 ;
break;
case V_278 :
V_254 -> V_263 = ( V_279 << 16 ) ;
V_254 -> V_263 |= ( V_280 << 8 ) ;
V_257 = F_125 (
& V_255 -> V_258 . V_281 [ 0 ] ) ;
F_126 ( V_254 , V_257 ) ;
break;
case V_282 :
case V_283 :
case V_284 :
V_256 = 1 ;
break;
default:
V_256 = 1 ;
}
break;
case V_285 :
break;
case V_286 :
break;
case V_287 :
V_256 = 1 ;
break;
case V_288 :
break;
default:
V_256 = 1 ;
break;
}
return V_256 ;
}
static void F_127 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
bool V_289 = false ;
V_9 -> V_10 = V_11 ;
F_128 () ;
if ( V_9 -> V_12 ) {
V_289 = true ;
V_9 -> V_12 = false ;
}
if ( V_9 -> V_13 ) {
unsigned long V_77 ;
struct V_75 * V_30 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_30 = V_9 -> V_13 ;
if ( V_30 && F_53 ( & V_30 -> V_290 ) )
V_289 = true ;
V_9 -> V_13 = NULL ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
if ( V_289 )
F_129 ( & V_22 -> V_291 ) ;
}
static void F_130 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
F_127 ( V_22 , V_9 ) ;
F_131 ( V_22 , V_9 ) ;
}
static void F_132 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_253 * V_254 )
{
F_130 ( V_22 , V_9 ) ;
V_254 -> V_292 ( V_254 ) ;
}
static void F_133 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
F_134 ( & V_9 -> V_293 , V_294 ) ;
F_135 ( F_44 () , V_22 -> V_295 , & V_9 -> V_293 ) ;
}
static void F_136 ( struct V_253 * V_254 )
{
V_254 -> V_263 = V_296 << 16 ;
}
static void F_137 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_253 * V_254 )
{
F_136 ( V_254 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_57 ,
V_9 -> V_123 . V_124 , V_9 -> V_24 -> V_38 ) ;
F_130 ( V_22 , V_9 ) ;
}
static void F_138 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_253 * V_254 ,
struct V_75 * V_30 )
{
struct V_118 * V_255 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
if ( F_43 ( V_255 -> V_258 . V_259 == 0 &&
V_255 -> V_258 . V_49 == 0 ) )
return F_132 ( V_22 , V_9 , V_254 ) ;
if ( F_31 ( V_30 -> V_72 ) &&
V_255 -> V_258 . V_259 ==
V_274 ) {
if ( V_255 -> V_258 . V_49 ==
V_284 )
V_30 -> V_88 = 0 ;
return F_133 ( V_22 , V_9 ) ;
}
if ( F_124 ( V_22 , V_9 , V_254 , V_255 ) )
return F_133 ( V_22 , V_9 ) ;
return F_132 ( V_22 , V_9 , V_254 ) ;
}
static int F_139 ( struct V_1 * V_22 ,
struct V_8 * V_110 )
{
T_1 V_297 = V_110 -> V_24 -> V_38 ;
switch ( V_297 ) {
case V_298 :
case V_299 :
return 0 ;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_58 ,
V_297 ) ;
break;
}
return - V_297 ;
}
static void F_140 ( struct V_8 * V_110 )
{
struct V_253 * V_254 ;
struct V_1 * V_22 ;
struct V_305 * V_306 ;
struct V_75 * V_30 ;
struct V_118 * V_255 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned long V_307 ;
V_306 = V_110 -> V_24 ;
V_254 = V_110 -> V_10 ;
V_22 = V_110 -> V_22 ;
V_30 = V_254 -> V_42 -> V_79 ;
V_255 = & V_22 -> V_116 [ V_110 -> V_112 ] ;
F_141 ( V_254 ) ;
if ( ( V_110 -> V_129 == V_308 ) &&
( F_92 ( V_110 -> V_103 . V_250 ) > V_22 -> V_247 ) )
F_123 ( V_22 , V_110 ) ;
if ( ( V_110 -> V_129 == V_133 ) &&
( V_255 -> V_241 [ 0 ] . V_309 == V_310 ) )
F_118 ( V_22 , V_255 ) ;
V_254 -> V_263 = ( V_279 << 16 ) ;
V_254 -> V_263 |= ( V_280 << 8 ) ;
if ( V_110 -> V_129 == V_133 || V_110 -> V_129 == V_130 )
F_41 ( & V_110 -> V_215 -> V_225 ) ;
if ( F_40 ( V_306 -> V_36 == V_311 ) ) {
V_254 -> V_263 = V_312 << 16 ;
return F_132 ( V_22 , V_110 , V_254 ) ;
}
if ( ( F_40 ( F_5 ( V_110 ) ) ) ) {
if ( V_110 -> V_13 )
return F_130 ( V_22 , V_110 ) ;
if ( V_110 -> V_12 )
return F_137 ( V_22 , V_110 , V_254 ) ;
}
if ( V_110 -> V_129 == V_133 )
return F_138 ( V_22 , V_110 , V_254 , V_30 ) ;
F_126 ( V_254 , V_306 -> V_313 ) ;
if ( V_306 -> V_36 == 0 )
return F_132 ( V_22 , V_110 , V_254 ) ;
if ( V_110 -> V_129 == V_130 ) {
struct V_109 * V_9 = & V_22 -> V_111 [ V_110 -> V_112 ] ;
V_110 -> V_103 . V_104 = F_142 ( V_254 ) ;
V_110 -> V_103 . V_250 = F_143 ( V_110 -> V_103 . V_104 ) ;
V_110 -> V_123 . V_314 = F_92 ( V_9 -> V_315 ) &
V_316 ;
V_110 -> V_103 . V_317 = V_9 -> V_317 ;
memcpy ( V_110 -> V_103 . V_318 . V_319 , V_9 -> V_320 , 8 ) ;
memcpy ( V_110 -> V_123 . V_124 , V_9 -> V_124 , V_110 -> V_123 . V_314 ) ;
if ( F_31 ( V_30 -> V_72 ) ) {
if ( V_306 -> V_36 == V_321 )
V_30 -> V_88 = 0 ;
return F_133 ( V_22 , V_110 ) ;
}
}
switch ( V_306 -> V_36 ) {
case V_37 :
V_254 -> V_263 |= V_306 -> V_38 ;
if ( V_268 < sizeof( V_306 -> V_26 ) )
V_307 = V_268 ;
else
V_307 = sizeof( V_306 -> V_26 ) ;
if ( V_306 -> V_25 < V_307 )
V_307 = V_306 -> V_25 ;
memcpy ( V_254 -> V_267 , V_306 -> V_26 , V_307 ) ;
if ( V_306 -> V_38 )
F_6 ( V_306 -> V_26 , V_307 ,
& V_16 , & V_17 , & V_18 ) ;
if ( V_306 -> V_38 == V_264 ) {
if ( V_16 == V_322 ) {
V_254 -> V_263 |= V_323 << 16 ;
break;
}
break;
}
if ( V_306 -> V_38 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_59
L_60
L_61 ,
V_110 , V_306 -> V_38 ,
V_16 , V_17 , V_18 ,
V_254 -> V_263 ) ;
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_62
L_63 , V_110 ) ,
V_254 -> V_263 = V_312 << 16 ;
}
break;
case V_324 :
break;
case V_325 :
F_9 ( & V_22 -> V_29 -> V_30 ,
L_64 , V_110 -> V_123 . V_124 ) ;
break;
case V_326 : {
V_254 -> V_263 = V_312 << 16 ;
}
break;
case V_327 :
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_65 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_329 :
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_66 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_330 :
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_67 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_331 :
return F_137 ( V_22 , V_110 , V_254 ) ;
case V_332 :
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_68 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_333 :
V_254 -> V_263 = V_323 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_69 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_334 :
V_254 -> V_263 = V_335 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_70 ,
V_110 -> V_123 . V_124 ) ;
break;
case V_336 :
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_71 ) ;
break;
case V_337 :
if ( F_139 ( V_22 , V_110 ) )
V_254 -> V_263 = V_328 << 16 ;
break;
case V_321 :
V_254 -> V_263 = V_323 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_72 , V_110 ) ;
break;
default:
V_254 -> V_263 = V_328 << 16 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_73 ,
V_110 , V_306 -> V_36 ) ;
}
return F_132 ( V_22 , V_110 , V_254 ) ;
}
static void F_144 ( struct V_338 * V_29 ,
struct V_8 * V_9 , int V_339 , int V_340 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_339 ; V_68 ++ )
F_120 ( V_29 , ( V_341 ) F_119 ( V_9 -> V_246 [ V_68 ] . V_252 ) ,
F_114 ( V_9 -> V_246 [ V_68 ] . V_251 ) ,
V_340 ) ;
}
static int F_145 ( struct V_338 * V_29 ,
struct V_8 * V_110 ,
unsigned char * V_45 ,
T_3 V_342 ,
int V_340 )
{
T_5 V_343 ;
if ( V_342 == 0 || V_340 == V_344 ) {
V_110 -> V_103 . V_104 = 0 ;
V_110 -> V_103 . V_250 = F_143 ( 0 ) ;
return 0 ;
}
V_343 = F_115 ( V_29 , V_45 , V_342 , V_340 ) ;
if ( F_116 ( & V_29 -> V_30 , V_343 ) ) {
V_110 -> V_103 . V_104 = 0 ;
V_110 -> V_103 . V_250 = F_143 ( 0 ) ;
return - 1 ;
}
V_110 -> V_246 [ 0 ] . V_252 = F_117 ( V_343 ) ;
V_110 -> V_246 [ 0 ] . V_251 = F_122 ( V_342 ) ;
V_110 -> V_246 [ 0 ] . V_248 = F_122 ( V_345 ) ;
V_110 -> V_103 . V_104 = 1 ;
V_110 -> V_103 . V_250 = F_143 ( 1 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_92 , unsigned long V_346 )
{
F_147 ( V_347 ) ;
V_9 -> V_348 = & V_347 ;
F_54 ( V_22 , V_9 , V_92 ) ;
if ( V_346 == V_349 ) {
F_148 ( & V_347 ) ;
return V_350 ;
}
if ( ! F_149 ( & V_347 ,
F_150 ( V_346 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_74 ) ;
return - V_351 ;
}
return V_350 ;
}
static int F_151 ( struct V_1 * V_22 , struct V_8 * V_9 ,
int V_92 , unsigned long V_346 )
{
if ( F_40 ( F_13 ( V_22 ) ) ) {
V_9 -> V_24 -> V_36 = V_311 ;
return V_350 ;
}
return F_146 ( V_22 , V_9 , V_92 , V_346 ) ;
}
static T_4 F_13 ( struct V_1 * V_22 )
{
int V_352 ;
T_4 V_21 , * F_13 ;
V_352 = F_152 () ;
F_13 = F_153 ( V_22 -> F_13 , V_352 ) ;
V_21 = * F_13 ;
F_154 () ;
return V_21 ;
}
static int F_155 ( struct V_1 * V_22 ,
struct V_8 * V_9 , int V_340 , unsigned long V_346 )
{
int V_353 = 10 , V_354 = 0 ;
int V_21 ;
do {
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_21 = F_151 ( V_22 , V_9 , V_106 ,
V_346 ) ;
if ( V_21 )
break;
V_354 ++ ;
if ( V_354 > 3 ) {
F_156 ( V_353 ) ;
if ( V_353 < 1000 )
V_353 *= 2 ;
}
} while ( ( F_8 ( V_22 , V_9 ) ||
F_10 ( V_22 , V_9 ) ) &&
V_354 <= V_355 );
F_144 ( V_22 -> V_29 , V_9 , 1 , V_340 ) ;
if ( V_354 > V_355 )
V_21 = - V_356 ;
return V_21 ;
}
static void F_157 ( struct V_1 * V_22 , char * V_357 ,
struct V_8 * V_9 )
{
const T_1 * V_120 = V_9 -> V_123 . V_124 ;
const T_1 * V_140 = V_9 -> V_103 . V_318 . V_319 ;
F_9 ( & V_22 -> V_29 -> V_30 , L_75
L_76 ,
V_357 , V_140 [ 0 ] , V_140 [ 1 ] , V_140 [ 2 ] , V_140 [ 3 ] ,
V_140 [ 4 ] , V_140 [ 5 ] , V_140 [ 6 ] , V_140 [ 7 ] ,
V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ,
V_120 [ 8 ] , V_120 [ 9 ] , V_120 [ 10 ] , V_120 [ 11 ] ,
V_120 [ 12 ] , V_120 [ 13 ] , V_120 [ 14 ] , V_120 [ 15 ] ) ;
}
static void F_158 ( struct V_1 * V_22 ,
struct V_8 * V_110 )
{
const struct V_305 * V_306 = V_110 -> V_24 ;
struct V_42 * V_358 = & V_110 -> V_22 -> V_29 -> V_30 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
switch ( V_306 -> V_36 ) {
case V_37 :
if ( V_306 -> V_25 > sizeof( V_306 -> V_26 ) )
V_23 = sizeof( V_306 -> V_26 ) ;
else
V_23 = V_306 -> V_25 ;
F_6 ( V_306 -> V_26 , V_23 ,
& V_16 , & V_17 , & V_18 ) ;
F_157 ( V_22 , L_77 , V_110 ) ;
if ( V_306 -> V_38 == V_264 )
F_9 ( V_358 , L_78 ,
V_16 , V_17 , V_18 ) ;
else
F_9 ( V_358 , L_79 , V_306 -> V_38 ) ;
if ( V_306 -> V_38 == 0 )
F_9 ( V_358 , L_80
L_81
L_82
L_83 ) ;
break;
case V_324 :
break;
case V_325 :
F_157 ( V_22 , L_84 , V_110 ) ;
break;
case V_326 : {
F_157 ( V_22 , L_85 , V_110 ) ;
F_9 ( V_358 , L_86 ) ;
}
break;
case V_327 :
F_157 ( V_22 , L_87 , V_110 ) ;
break;
case V_329 :
F_157 ( V_22 , L_88 , V_110 ) ;
break;
case V_330 :
F_157 ( V_22 , L_89 , V_110 ) ;
break;
case V_331 :
F_157 ( V_22 , L_90 , V_110 ) ;
break;
case V_332 :
F_157 ( V_22 , L_91 , V_110 ) ;
break;
case V_333 :
F_157 ( V_22 , L_92 , V_110 ) ;
break;
case V_334 :
F_157 ( V_22 , L_93 , V_110 ) ;
break;
case V_336 :
F_157 ( V_22 , L_94 , V_110 ) ;
break;
case V_311 :
F_157 ( V_22 , L_95 , V_110 ) ;
break;
default:
F_157 ( V_22 , L_96 , V_110 ) ;
F_9 ( V_358 , L_97 ,
V_306 -> V_36 ) ;
}
}
static int F_159 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_6 V_359 , unsigned char * V_45 ,
unsigned char V_360 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
if ( F_161 ( V_9 , V_361 , V_22 , V_45 , V_360 ,
V_359 , V_72 , V_362 ) ) {
V_21 = - 1 ;
goto V_363;
}
V_21 = F_155 ( V_22 , V_9 ,
V_364 , V_349 ) ;
if ( V_21 )
goto V_363;
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 && V_306 -> V_36 != V_324 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_163 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char V_359 ,
struct V_365 * V_45 , T_3 V_360 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
if ( F_161 ( V_9 , V_366 , V_22 , V_45 , V_360 ,
V_359 , V_72 , V_362 ) ) {
V_21 = - 1 ;
goto V_363;
}
V_21 = F_155 ( V_22 , V_9 ,
V_364 , V_349 ) ;
if ( V_21 )
goto V_363;
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 && V_306 -> V_36 != V_324 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_164 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_367 , int V_92 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
( void ) F_161 ( V_9 , V_368 , V_22 , NULL , 0 , 0 ,
V_72 , V_369 ) ;
V_9 -> V_123 . V_124 [ 1 ] = V_367 ;
V_21 = F_151 ( V_22 , V_9 , V_92 , V_349 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_98 ) ;
goto V_363;
}
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static bool F_165 ( struct V_1 * V_22 , struct V_8 * V_9 ,
struct V_75 * V_30 ,
unsigned char * V_72 )
{
int V_68 ;
bool V_370 = false ;
struct V_118 * V_255 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
struct V_115 * V_371 = (struct V_115 * ) V_255 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_129 ) {
case V_308 :
case V_372 :
V_370 = ! memcmp ( V_72 , & V_9 -> V_103 . V_318 . V_319 ,
sizeof( V_9 -> V_103 . V_318 . V_319 ) ) ;
break;
case V_130 :
case V_133 :
if ( V_9 -> V_215 == V_30 ) {
V_370 = true ;
} else {
for ( V_68 = 0 ; V_68 < V_30 -> V_214 && ! V_370 ; V_68 ++ ) {
V_370 = V_30 -> V_215 [ V_68 ] == V_9 -> V_215 ;
}
}
break;
case V_135 :
for ( V_68 = 0 ; V_68 < V_30 -> V_214 && ! V_370 ; V_68 ++ ) {
V_370 = V_30 -> V_215 [ V_68 ] -> V_167 ==
F_114 ( V_371 -> V_373 ) ;
}
break;
case 0 :
V_370 = false ;
break;
default:
F_69 ( & V_22 -> V_29 -> V_30 , L_99 ,
V_9 -> V_129 ) ;
F_166 () ;
}
return V_370 ;
}
static int F_167 ( struct V_1 * V_22 , struct V_75 * V_30 ,
unsigned char * V_72 , T_1 V_367 , int V_92 )
{
int V_68 ;
int V_21 = 0 ;
if ( F_168 ( & V_22 -> V_374 ) == - V_375 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_100 ) ;
return - V_375 ;
}
F_71 ( F_21 ( & V_30 -> V_290 ) != 0 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_376 + V_68 ;
int V_377 = F_169 ( & V_9 -> V_377 ) ;
if ( V_377 > 1 && F_165 ( V_22 , V_9 , V_30 , V_72 ) ) {
unsigned long V_77 ;
V_9 -> V_13 = V_30 ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! F_4 ( V_9 ) )
F_51 ( & V_30 -> V_290 ) ;
else
V_9 -> V_13 = NULL ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
F_162 ( V_22 , V_9 ) ;
}
V_21 = F_164 ( V_22 , V_72 , V_367 , V_92 ) ;
if ( ! V_21 )
F_170 ( V_22 -> V_291 ,
F_21 ( & V_30 -> V_290 ) == 0 ||
F_13 ( V_22 ) ) ;
if ( F_40 ( F_13 ( V_22 ) ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_101 ) ;
F_171 ( & V_22 -> V_374 ) ;
V_21 = - V_80 ;
}
if ( F_40 ( V_21 ) )
F_105 ( & V_30 -> V_290 , 0 ) ;
F_171 ( & V_22 -> V_374 ) ;
return V_21 ;
}
static void F_172 ( struct V_1 * V_22 ,
unsigned char * V_72 , unsigned char * V_82 )
{
int V_21 ;
unsigned char * V_45 ;
* V_82 = V_83 ;
V_45 = F_96 ( 64 , V_183 ) ;
if ( ! V_45 )
return;
V_21 = F_159 ( V_22 , V_72 , V_378 | 0xC1 , V_45 , 64 ) ;
if ( V_21 == 0 )
* V_82 = V_45 [ 8 ] ;
if ( * V_82 > V_83 )
* V_82 = V_83 ;
F_76 ( V_45 ) ;
return;
}
static void F_173 ( struct V_1 * V_22 , int V_21 ,
struct V_200 * V_379 )
{
struct V_202 * V_203 = & V_379 -> V_204 [ 0 ] ;
int V_201 , V_380 , V_381 ;
T_6 V_382 , V_209 , V_383 ;
if ( V_21 != 0 )
return;
if ( V_22 -> V_58 < 2 )
return;
F_90 ( & V_22 -> V_29 -> V_30 , L_102 ,
F_114 ( V_379 -> V_384 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_103 ,
F_114 ( V_379 -> V_385 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_104 ,
F_119 ( V_379 -> V_386 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_105 ,
V_379 -> V_387 ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_106 ,
V_379 -> V_388 ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_107 ,
F_92 ( V_379 -> V_389 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_108 ,
F_119 ( V_379 -> V_390 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_109 ,
F_119 ( V_379 -> V_391 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_110 ,
F_92 ( V_379 -> V_206 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_111 ,
F_92 ( V_379 -> V_207 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_112 ,
F_92 ( V_379 -> V_209 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_113 ,
F_92 ( V_379 -> V_210 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_114 ,
F_92 ( V_379 -> V_77 ) ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_115 ,
F_92 ( V_379 -> V_77 ) &
V_392 ? L_116 : L_117 ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_118 ,
F_92 ( V_379 -> V_393 ) ) ;
V_382 = F_92 ( V_379 -> V_210 ) ;
for ( V_201 = 0 ; V_201 < V_382 ; V_201 ++ ) {
F_90 ( & V_22 -> V_29 -> V_30 , L_119 , V_201 ) ;
V_209 = F_92 ( V_379 -> V_209 ) ;
for ( V_380 = 0 ; V_380 < V_209 ; V_380 ++ ) {
F_90 ( & V_22 -> V_29 -> V_30 , L_120 , V_380 ) ;
V_383 =
F_92 ( V_379 -> V_206 ) ;
for ( V_381 = 0 ; V_381 < V_383 ; V_381 ++ , V_203 ++ )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_121 ,
V_381 , V_203 -> V_167 ,
V_203 -> V_394 [ 0 ] , V_203 -> V_394 [ 1 ] ) ;
V_383 =
F_92 ( V_379 -> V_207 ) ;
for ( V_381 = 0 ; V_381 < V_383 ; V_381 ++ , V_203 ++ )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_122 ,
V_381 , V_203 -> V_167 ,
V_203 -> V_394 [ 0 ] , V_203 -> V_394 [ 1 ] ) ;
}
}
}
static int F_174 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_75 * V_395 )
{
int V_21 = 0 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
if ( F_161 ( V_9 , V_396 , V_22 , & V_395 -> V_166 ,
sizeof( V_395 -> V_166 ) , 0 ,
V_72 , V_362 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_123 ) ;
F_162 ( V_22 , V_9 ) ;
return - 1 ;
}
V_21 = F_155 ( V_22 , V_9 ,
V_364 , V_349 ) ;
if ( V_21 )
goto V_363;
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 && V_306 -> V_36 != V_324 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
goto V_363;
}
F_162 ( V_22 , V_9 ) ;
if ( F_114 ( V_395 -> V_166 . V_384 ) >
sizeof( V_395 -> V_166 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_124 ) ;
V_21 = - 1 ;
}
F_173 ( V_22 , V_21 , & V_395 -> V_166 ) ;
return V_21 ;
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_175 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_6 V_397 ,
struct V_398 * V_45 , T_3 V_360 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
V_21 = F_161 ( V_9 , V_399 , V_22 , V_45 , V_360 ,
0 , V_137 , V_362 ) ;
if ( V_21 )
goto V_363;
V_9 -> V_123 . V_124 [ 2 ] = V_397 & 0xff ;
V_9 -> V_123 . V_124 [ 9 ] = ( V_397 >> 8 ) & 0xff ;
F_155 ( V_22 , V_9 , V_364 ,
V_349 ) ;
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 && V_306 -> V_36 != V_324 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
}
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_176 ( struct V_1 * V_22 ,
unsigned char V_72 [] , T_1 V_359 )
{
int V_21 ;
int V_68 ;
int V_400 ;
unsigned char * V_45 , V_360 ;
V_45 = F_96 ( 256 , V_183 ) ;
if ( ! V_45 )
return 0 ;
V_21 = F_159 ( V_22 , V_72 ,
V_378 | V_401 ,
V_45 , V_402 ) ;
if ( V_21 != 0 )
goto V_403;
V_400 = V_45 [ 3 ] ;
if ( ( V_400 + V_402 ) <= 255 )
V_360 = V_400 + V_402 ;
else
V_360 = 255 ;
V_21 = F_159 ( V_22 , V_72 ,
V_378 | V_401 ,
V_45 , V_360 ) ;
if ( V_21 != 0 )
goto V_403;
V_400 = V_45 [ 3 ] ;
for ( V_68 = 1 ; V_68 <= V_400 ; V_68 ++ )
if ( V_45 [ 3 + V_68 ] == V_359 )
goto V_404;
V_403:
F_76 ( V_45 ) ;
return 0 ;
V_404:
F_76 ( V_45 ) ;
return 1 ;
}
static void F_177 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_75 * V_395 )
{
int V_21 ;
unsigned char * V_45 ;
T_1 V_405 ;
V_395 -> V_151 = 0 ;
V_395 -> V_88 = 0 ;
V_395 -> V_163 = 0 ;
V_45 = F_96 ( 64 , V_183 ) ;
if ( ! V_45 )
return;
if ( ! F_176 ( V_22 , V_72 , V_406 ) )
goto V_363;
V_21 = F_159 ( V_22 , V_72 ,
V_378 | V_406 , V_45 , 64 ) ;
if ( V_21 != 0 )
goto V_363;
#define F_178 4
#define F_179 0x01
#define F_180 0x02
V_405 = V_45 [ F_178 ] ;
V_395 -> V_151 =
! ! ( V_405 & F_179 ) ;
if ( V_395 -> V_151 ) {
V_395 -> V_88 =
! ! ( V_405 & F_180 ) ;
if ( F_174 ( V_22 , V_72 , V_395 ) )
V_395 -> V_88 = 0 ;
}
V_395 -> V_163 = V_395 -> V_88 ;
V_363:
F_76 ( V_45 ) ;
return;
}
static int F_181 ( struct V_1 * V_22 , unsigned char * V_72 ,
unsigned char * V_87 , int V_342 )
{
int V_21 ;
unsigned char * V_45 ;
if ( V_342 > 16 )
V_342 = 16 ;
V_45 = F_96 ( 64 , V_183 ) ;
if ( ! V_45 )
return - V_231 ;
V_21 = F_159 ( V_22 , V_72 , V_378 | 0x83 , V_45 , 64 ) ;
if ( V_21 == 0 )
memcpy ( V_87 , & V_45 [ 8 ] , V_342 ) ;
F_76 ( V_45 ) ;
return V_21 != 0 ;
}
static int F_182 ( struct V_1 * V_22 , int V_407 ,
void * V_45 , int V_360 ,
int V_408 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
unsigned char V_72 [ 8 ] ;
struct V_305 * V_306 ;
V_9 = F_160 ( V_22 ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
if ( F_161 ( V_9 , V_407 ? V_409 : V_410 , V_22 ,
V_45 , V_360 , 0 , V_72 , V_362 ) ) {
V_21 = - 1 ;
goto V_363;
}
if ( V_408 )
V_9 -> V_123 . V_124 [ 1 ] = V_408 ;
V_21 = F_155 ( V_22 , V_9 ,
V_364 , V_349 ) ;
if ( V_21 )
goto V_363;
V_306 = V_9 -> V_24 ;
if ( V_306 -> V_36 != 0 &&
V_306 -> V_36 != V_324 ) {
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
} else {
struct V_411 * V_412 = V_45 ;
if ( V_412 -> V_413 != V_408 ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_125 ,
V_408 ,
V_412 -> V_413 ) ;
V_21 = - 1 ;
}
}
V_363:
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static inline int F_183 ( struct V_1 * V_22 ,
struct V_414 * V_45 , int V_360 )
{
return F_182 ( V_22 , 0 , V_45 , V_360 ,
V_415 ) ;
}
static inline int F_184 ( struct V_1 * V_22 ,
struct V_411 * V_45 , int V_360 )
{
return F_182 ( V_22 , 1 , V_45 , V_360 , 0 ) ;
}
static inline void F_185 ( struct V_75 * V_42 ,
int V_138 , int V_139 , int V_140 )
{
V_42 -> V_138 = V_138 ;
V_42 -> V_139 = V_139 ;
V_42 -> V_140 = V_140 ;
}
static int F_186 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
int V_21 ;
int V_49 ;
int V_416 ;
unsigned char * V_45 ;
V_45 = F_96 ( 64 , V_183 ) ;
if ( ! V_45 )
return V_187 ;
if ( ! F_176 ( V_22 , V_72 , V_417 ) )
goto V_418;
V_21 = F_159 ( V_22 , V_72 , V_378 | V_417 ,
V_45 , V_402 ) ;
if ( V_21 != 0 )
goto V_418;
V_416 = V_45 [ 3 ] ;
V_21 = F_159 ( V_22 , V_72 , V_378 | V_417 ,
V_45 , V_416 + V_402 ) ;
if ( V_21 != 0 )
goto V_418;
V_49 = V_45 [ 4 ] ;
F_76 ( V_45 ) ;
return V_49 ;
V_418:
F_76 ( V_45 ) ;
return V_187 ;
}
static int F_187 ( struct V_1 * V_22 ,
unsigned char V_72 [] )
{
struct V_8 * V_9 ;
unsigned char * V_419 ;
T_1 V_16 , V_17 , V_18 ;
int V_23 ;
int V_21 , V_420 = 0 ;
T_6 V_421 ;
T_1 V_422 ;
#define F_188 0x04
#define F_189 0x04
#define F_190 0x02
V_9 = F_160 ( V_22 ) ;
( void ) F_161 ( V_9 , V_423 , V_22 , NULL , 0 , 0 , V_72 , V_362 ) ;
V_21 = F_151 ( V_22 , V_9 , V_106 , V_349 ) ;
if ( V_21 ) {
F_162 ( V_22 , V_9 ) ;
return 0 ;
}
V_419 = V_9 -> V_24 -> V_26 ;
if ( V_9 -> V_24 -> V_25 > sizeof( V_9 -> V_24 -> V_26 ) )
V_23 = sizeof( V_9 -> V_24 -> V_26 ) ;
else
V_23 = V_9 -> V_24 -> V_25 ;
F_6 ( V_419 , V_23 , & V_16 , & V_17 , & V_18 ) ;
V_421 = V_9 -> V_24 -> V_36 ;
V_422 = V_9 -> V_24 -> V_38 ;
F_162 ( V_22 , V_9 ) ;
if ( V_421 != V_37 ||
V_422 != V_264 ||
V_16 != V_424 ||
V_17 != F_188 ) {
return 0 ;
}
V_420 = F_186 ( V_22 , V_72 ) ;
switch ( V_420 ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
return V_420 ;
case V_187 :
if ( ( V_18 == F_189 ) ||
( V_18 == F_190 ) )
return V_420 ;
break;
default:
break;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_22 ,
unsigned char * V_72 )
{
struct V_8 * V_9 ;
struct V_305 * V_306 ;
int V_21 = 0 ;
T_5 V_317 = ( T_5 ) - 1 ;
if ( ! F_31 ( V_72 ) )
return 1 ;
V_9 = F_160 ( V_22 ) ;
( void ) F_161 ( V_9 , V_425 , V_22 , & V_317 , 0 , 0 , V_72 , V_369 ) ;
( void ) F_151 ( V_22 , V_9 , V_106 , V_349 ) ;
V_306 = V_9 -> V_24 ;
switch ( V_306 -> V_36 ) {
case V_326 :
V_21 = 0 ;
break;
case V_336 :
case V_332 :
V_21 = 1 ;
break;
case V_337 :
V_21 = F_139 ( V_22 , V_9 ) ;
break;
default:
V_21 = 0 ;
break;
}
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_192 ( struct V_1 * V_22 ,
unsigned char V_72 [] , struct V_75 * V_395 ,
unsigned char * V_426 )
{
#define F_193 43
#define F_194 "$DR-10"
#define F_195 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_196 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_427 ;
unsigned char * V_428 ;
V_427 = F_96 ( F_196 , V_183 ) ;
if ( ! V_427 )
goto V_429;
if ( F_159 ( V_22 , V_72 , 0 , V_427 ,
( unsigned char ) F_196 ) != 0 ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_126 ) ;
goto V_429;
}
V_395 -> V_148 = ( V_427 [ 0 ] & 0x1f ) ;
memcpy ( V_395 -> V_72 , V_72 , 8 ) ;
memcpy ( V_395 -> V_149 , & V_427 [ 8 ] ,
sizeof( V_395 -> V_149 ) ) ;
memcpy ( V_395 -> V_150 , & V_427 [ 16 ] ,
sizeof( V_395 -> V_150 ) ) ;
memset ( V_395 -> V_87 , 0 ,
sizeof( V_395 -> V_87 ) ) ;
F_181 ( V_22 , V_72 , V_395 -> V_87 ,
sizeof( V_395 -> V_87 ) ) ;
if ( V_395 -> V_148 == V_216 &&
F_31 ( V_72 ) ) {
int V_180 ;
F_172 ( V_22 , V_72 , & V_395 -> V_82 ) ;
if ( V_22 -> V_430 & V_431 )
F_177 ( V_22 , V_72 , V_395 ) ;
V_180 = F_187 ( V_22 , V_72 ) ;
if ( V_180 < 0 || V_180 > 0xff )
V_180 = V_187 ;
V_395 -> V_180 = V_180 & 0xff ;
} else {
V_395 -> V_82 = V_83 ;
V_395 -> V_151 = 0 ;
V_395 -> V_88 = 0 ;
V_395 -> V_163 = 0 ;
V_395 -> V_168 = 0 ;
V_395 -> V_180 = 0 ;
V_395 -> V_170 = V_22 -> V_217 ;
}
if ( V_426 ) {
V_428 = & V_427 [ F_193 ] ;
* V_426 = ( V_395 -> V_148 == V_432 &&
strncmp ( V_428 , F_194 ,
F_195 ) == 0 ) ;
}
F_76 ( V_427 ) ;
return 0 ;
V_429:
F_76 ( V_427 ) ;
return 1 ;
}
static void F_197 ( struct V_1 * V_22 ,
struct V_75 * V_30 , T_1 * V_72 )
{
unsigned long V_77 ;
int V_21 , V_164 ;
F_34 ( & V_22 -> V_223 , V_77 ) ;
V_21 = F_79 ( V_30 , V_22 -> V_30 , V_22 -> V_144 , & V_164 ) ;
if ( ( V_21 == F_82 || V_21 == F_83 ) &&
V_164 >= 0 && V_164 < V_22 -> V_144 ) {
V_30 -> V_433 = V_22 -> V_30 [ V_164 ] -> V_433 ;
F_35 ( & V_22 -> V_223 , V_77 ) ;
} else {
F_35 ( & V_22 -> V_223 , V_77 ) ;
V_30 -> V_433 =
F_191 ( V_22 , V_72 ) ;
if ( V_30 -> V_433 < 0 )
V_30 -> V_433 = 0 ;
}
}
static int F_198 ( struct V_1 * V_22 , struct V_75 * V_42 )
{
int V_68 ;
for ( V_68 = 0 ; V_434 [ V_68 ] ; V_68 ++ )
if ( strncmp ( V_42 -> V_150 , V_434 [ V_68 ] ,
strlen ( V_434 [ V_68 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_199 ( struct V_1 * V_22 ,
T_1 * V_435 , struct V_75 * V_42 )
{
T_4 V_85 = F_114 ( * ( ( V_436 * ) V_435 ) ) ;
if ( ! F_31 ( V_435 ) ) {
if ( F_58 ( V_435 ) )
F_185 ( V_42 , 3 , 0 , V_85 & 0x3fff ) ;
else
F_185 ( V_42 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_198 ( V_22 , V_42 ) ) {
F_185 ( V_42 ,
1 , ( V_85 >> 16 ) & 0x3fff , V_85 & 0x00ff ) ;
return;
}
F_185 ( V_42 , 0 , 0 , V_85 & 0x3fff ) ;
}
static int F_200 ( struct V_1 * V_22 ,
struct V_75 * V_437 ,
struct V_75 * V_395 , T_1 * V_435 ,
unsigned long V_438 [] , int * V_439 )
{
unsigned char V_72 [ 8 ] ;
if ( F_201 ( V_437 -> V_139 , V_438 ) )
return 0 ;
if ( ! F_31 ( V_435 ) )
return 0 ;
if ( ! F_198 ( V_22 , V_437 ) )
return 0 ;
if ( V_437 -> V_140 == 0 )
return 0 ;
memset ( V_72 , 0 , 8 ) ;
V_72 [ 3 ] = V_437 -> V_139 ;
if ( F_58 ( V_72 ) )
return 0 ;
if ( F_59 ( V_22 ) )
return 0 ;
if ( * V_439 >= V_440 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_127
L_128
L_129 ) ;
return 0 ;
}
if ( F_192 ( V_22 , V_72 , V_395 , NULL ) )
return 0 ;
( * V_439 ) ++ ;
F_185 ( V_395 ,
V_437 -> V_138 , V_437 -> V_139 , 0 ) ;
F_197 ( V_22 , V_395 , V_72 ) ;
F_202 ( V_437 -> V_139 , V_438 ) ;
return 1 ;
}
static int F_203 ( struct V_1 * V_22 ,
struct V_8 * V_441 , unsigned char * V_72 )
{
struct V_118 * V_255 =
& V_22 -> V_116 [ V_441 -> V_112 ] ;
unsigned long V_77 ;
int V_68 ;
F_34 ( & V_22 -> V_223 , V_77 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ )
if ( V_22 -> V_30 [ V_68 ] -> V_167 == F_114 ( V_255 -> V_442 ) ) {
memcpy ( V_72 , V_22 -> V_30 [ V_68 ] -> V_72 ,
sizeof( V_22 -> V_30 [ V_68 ] -> V_72 ) ) ;
F_35 ( & V_22 -> V_223 , V_77 ) ;
return 1 ;
}
F_35 ( & V_22 -> V_223 , V_77 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_22 ,
struct V_414 * V_443 , T_4 * V_444 ,
struct V_411 * V_445 , T_4 * V_446 )
{
if ( F_183 ( V_22 , V_443 , sizeof( * V_443 ) ) ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_130 ) ;
return - 1 ;
}
* V_444 = F_205 ( * ( ( V_447 * ) V_443 -> V_448 ) ) / 24 ;
if ( * V_444 > V_449 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_131 ,
V_449 , * V_444 - V_449 ) ;
* V_444 = V_449 ;
}
if ( F_184 ( V_22 , V_445 , sizeof( * V_445 ) ) ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_132 ) ;
return - 1 ;
}
* V_446 = F_205 ( * ( ( V_447 * ) V_445 -> V_448 ) ) / 8 ;
if ( * V_446 > V_450 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_133
L_134 , V_450 ,
* V_446 - V_450 ) ;
* V_446 = V_450 ;
}
if ( * V_446 + * V_444 > V_449 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_135
L_134 , V_449 ,
* V_444 + * V_446 - V_449 ) ;
* V_446 = V_449 - * V_444 ;
}
return 0 ;
}
static T_1 * F_206 ( struct V_1 * V_22 , int V_451 ,
int V_68 , int V_444 , int V_446 ,
struct V_414 * V_452 ,
struct V_411 * V_453 )
{
int V_454 = V_444 + ( V_451 == 0 ) ;
int V_455 = V_444 + V_446 + ( V_451 == 0 ) ;
if ( V_68 == V_451 )
return V_137 ;
if ( V_68 < V_454 )
return & V_452 -> V_318 [ V_68 -
( V_451 == 0 ) ] . V_85 [ 0 ] ;
if ( V_68 < V_455 )
return & V_453 -> V_318 [ V_68 - V_444 -
( V_451 == 0 ) ] [ 0 ] ;
F_166 () ;
return NULL ;
}
static int F_207 ( struct V_1 * V_22 )
{
int V_21 ;
int V_456 ;
struct V_365 * V_457 ;
V_457 = F_96 ( sizeof( struct V_365 ) ,
V_183 ) ;
if ( ! V_457 )
return - V_231 ;
V_21 = F_163 ( V_22 , V_137 , 0 , V_457 ,
sizeof( struct V_365 ) ) ;
if ( V_21 ) {
F_76 ( V_457 ) ;
return V_21 ;
}
V_456 =
( ( V_457 -> V_458 & V_459 ) != 0 ) ;
F_76 ( V_457 ) ;
return V_456 ;
}
static void F_208 ( struct V_1 * V_22 ,
struct V_75 * V_30 ,
T_1 * V_435 ,
struct V_398 * V_460 )
{
int V_21 ;
struct V_461 * V_462 =
(struct V_461 * ) V_435 ;
V_30 -> V_167 = V_462 -> V_167 ;
if ( F_209 ( V_435 ) && V_30 -> V_167 )
V_30 -> V_168 = 1 ;
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
V_21 = F_175 ( V_22 , V_435 ,
F_210 ( V_435 ) , V_460 ,
sizeof( * V_460 ) ) ;
if ( ! V_21 )
#define F_211 2
#define F_212 7
V_30 -> V_170 =
F_92 ( V_460 -> V_463 ) -
F_211 ;
else
V_30 -> V_170 = F_212 ;
F_105 ( & V_30 -> V_225 , 0 ) ;
F_105 ( & V_30 -> V_290 , 0 ) ;
}
static void F_213 ( struct V_1 * V_22 , int V_153 )
{
struct V_414 * V_452 = NULL ;
struct V_411 * V_453 = NULL ;
struct V_398 * V_460 = NULL ;
T_4 V_444 = 0 ;
T_4 V_446 = 0 ;
T_4 V_464 = 0 ;
struct V_75 * * V_465 , * V_395 , * V_437 ;
int V_466 = 0 ;
int V_68 , V_439 , V_467 ;
int V_451 ;
int V_468 ;
F_61 ( V_438 , V_440 ) ;
V_465 = F_96 ( sizeof( * V_465 ) * V_143 , V_183 ) ;
V_452 = F_96 ( sizeof( * V_452 ) , V_183 ) ;
V_453 = F_96 ( sizeof( * V_453 ) , V_183 ) ;
V_437 = F_96 ( sizeof( * V_437 ) , V_183 ) ;
V_460 = F_96 ( sizeof( * V_460 ) , V_183 ) ;
if ( ! V_465 || ! V_452 || ! V_453 ||
! V_437 || ! V_460 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_136 ) ;
goto V_363;
}
memset ( V_438 , 0 , sizeof( V_438 ) ) ;
V_468 = F_207 ( V_22 ) ;
if ( V_468 < 0 )
goto V_363;
if ( ! V_22 -> V_456 && V_468 )
F_9 ( & V_22 -> V_29 -> V_30 , L_137 ) ;
else if ( V_22 -> V_456 && ! V_468 )
F_9 ( & V_22 -> V_29 -> V_30 , L_138 ) ;
V_22 -> V_456 = V_468 ;
if ( F_204 ( V_22 , V_452 , & V_444 ,
V_453 , & V_446 ) )
goto V_363;
V_467 = V_444 + V_446 + V_440 + 1 ;
for ( V_68 = 0 ; V_68 < V_467 ; V_68 ++ ) {
if ( V_68 >= V_143 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_139
L_140 , V_143 ,
V_467 - V_143 ) ;
break;
}
V_465 [ V_68 ] = F_96 ( sizeof( * V_465 [ V_68 ] ) , V_183 ) ;
if ( ! V_465 [ V_68 ] ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_141 ,
__FILE__ , __LINE__ ) ;
goto V_363;
}
V_464 ++ ;
}
if ( F_59 ( V_22 ) )
V_451 = 0 ;
else
V_451 = V_444 + V_446 ;
V_439 = 0 ;
for ( V_68 = 0 ; V_68 < V_444 + V_446 + 1 ; V_68 ++ ) {
T_1 * V_435 , V_469 = 0 ;
V_435 = F_206 ( V_22 , V_451 ,
V_68 , V_444 , V_446 , V_452 , V_453 ) ;
if ( F_214 ( V_435 ) )
if ( V_68 < V_444 + ( V_451 == 0 ) &&
F_215 ( V_435 ) )
continue;
if ( F_192 ( V_22 , V_435 , V_437 ,
& V_469 ) )
continue;
F_199 ( V_22 , V_435 , V_437 ) ;
F_197 ( V_22 , V_437 , V_435 ) ;
V_395 = V_465 [ V_466 ] ;
if ( F_200 ( V_22 , V_437 , V_395 ,
V_435 , V_438 ,
& V_439 ) ) {
V_466 ++ ;
V_395 = V_465 [ V_466 ] ;
}
* V_395 = * V_437 ;
if ( F_214 ( V_435 ) &&
V_68 < V_444 + ( V_451 == 0 ) ) {
if ( V_22 -> V_456 )
F_9 ( & V_22 -> V_29 -> V_30 ,
L_142 ) ;
V_395 -> V_152 = V_470 ;
} else {
V_395 -> V_152 =
V_471 | V_227 ;
}
switch ( V_395 -> V_148 ) {
case V_432 :
if ( V_469 )
V_466 ++ ;
break;
case V_216 :
if ( V_68 >= V_444 ) {
V_466 ++ ;
break;
}
if ( V_22 -> V_456 )
V_395 -> V_88 = 0 ;
else if ( ! ( V_22 -> V_63 & V_93 ||
V_22 -> V_63 & V_472 ) )
break;
F_208 ( V_22 , V_395 ,
V_435 , V_460 ) ;
F_105 ( & V_395 -> V_225 , 0 ) ;
V_466 ++ ;
break;
case V_473 :
case V_474 :
V_466 ++ ;
break;
case V_475 :
if ( V_22 -> V_456 )
V_466 ++ ;
break;
case V_476 :
if ( ! F_58 ( V_435 ) )
break;
V_466 ++ ;
break;
default:
break;
}
if ( V_466 >= V_143 )
break;
}
F_95 ( V_22 , V_153 , V_465 , V_466 ) ;
V_363:
F_76 ( V_437 ) ;
for ( V_68 = 0 ; V_68 < V_464 ; V_68 ++ )
F_76 ( V_465 [ V_68 ] ) ;
F_76 ( V_465 ) ;
F_76 ( V_452 ) ;
F_76 ( V_453 ) ;
F_76 ( V_460 ) ;
}
static void F_216 ( struct V_244 * V_477 ,
struct V_478 * V_241 )
{
T_5 V_343 = ( T_5 ) F_217 ( V_241 ) ;
unsigned int V_50 = F_218 ( V_241 ) ;
V_477 -> V_252 = F_117 ( V_343 ) ;
V_477 -> V_251 = F_122 ( V_50 ) ;
V_477 -> V_248 = 0 ;
}
static int F_219 ( struct V_1 * V_22 ,
struct V_8 * V_110 ,
struct V_253 * V_254 )
{
struct V_478 * V_241 ;
int V_479 , V_68 , V_480 , V_481 , V_482 ;
struct V_244 * V_483 ;
F_71 ( F_142 ( V_254 ) > V_22 -> V_232 ) ;
V_479 = F_220 ( V_254 ) ;
if ( V_479 < 0 )
return V_479 ;
if ( ! V_479 )
goto V_484;
V_483 = V_110 -> V_246 ;
V_481 = V_479 > V_22 -> V_247 ;
V_480 = V_481 ? V_22 -> V_247 - 1 : V_479 ;
V_482 = F_142 ( V_254 ) - 1 ;
F_221 (cmd, sg, sg_limit, i) {
F_216 ( V_483 , V_241 ) ;
V_483 ++ ;
}
if ( V_481 ) {
V_483 = V_22 -> V_234 [ V_110 -> V_112 ] ;
V_480 = V_479 - V_480 ;
F_222 (sg, sg, sg_limit, i) {
F_216 ( V_483 , V_241 ) ;
V_483 ++ ;
}
}
( V_483 - 1 ) -> V_248 = F_122 ( V_345 ) ;
if ( V_479 + V_481 > V_22 -> V_485 )
V_22 -> V_485 = V_479 + V_481 ;
if ( V_481 ) {
V_110 -> V_103 . V_104 = V_22 -> V_247 ;
V_110 -> V_103 . V_250 = F_143 ( V_479 + 1 ) ;
if ( F_121 ( V_22 , V_110 ) ) {
F_141 ( V_254 ) ;
return - 1 ;
}
return 0 ;
}
V_484:
V_110 -> V_103 . V_104 = ( T_1 ) V_479 ;
V_110 -> V_103 . V_250 = F_143 ( V_479 ) ;
return 0 ;
}
static int F_223 ( T_1 * V_120 , int * V_486 )
{
int V_487 = 0 ;
T_4 V_488 ;
T_4 V_489 ;
switch ( V_120 [ 0 ] ) {
case V_490 :
case V_491 :
V_487 = 1 ;
case V_492 :
case V_493 :
if ( * V_486 == 6 ) {
V_488 = ( ( ( T_4 ) V_120 [ 2 ] ) << 8 ) | V_120 [ 3 ] ;
V_489 = V_120 [ 4 ] ;
} else {
F_71 ( * V_486 != 12 ) ;
V_488 = ( ( ( T_4 ) V_120 [ 2 ] ) << 24 ) |
( ( ( T_4 ) V_120 [ 3 ] ) << 16 ) |
( ( ( T_4 ) V_120 [ 4 ] ) << 8 ) |
V_120 [ 5 ] ;
V_489 =
( ( ( T_4 ) V_120 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_120 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_120 [ 8 ] ) << 8 ) |
V_120 [ 9 ] ;
}
if ( V_489 > 0xffff )
return V_494 ;
V_120 [ 0 ] = V_487 ? V_495 : V_496 ;
V_120 [ 1 ] = 0 ;
V_120 [ 2 ] = ( T_1 ) ( V_488 >> 24 ) ;
V_120 [ 3 ] = ( T_1 ) ( V_488 >> 16 ) ;
V_120 [ 4 ] = ( T_1 ) ( V_488 >> 8 ) ;
V_120 [ 5 ] = ( T_1 ) ( V_488 ) ;
V_120 [ 6 ] = 0 ;
V_120 [ 7 ] = ( T_1 ) ( V_489 >> 8 ) ;
V_120 [ 8 ] = ( T_1 ) ( V_489 ) ;
V_120 [ 9 ] = 0 ;
* V_486 = 10 ;
break;
}
return 0 ;
}
static int F_224 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_167 , T_1 * V_120 , int V_486 ,
T_1 * V_72 , struct V_75 * V_215 )
{
struct V_253 * V_254 = V_9 -> V_10 ;
struct V_109 * V_110 = & V_22 -> V_111 [ V_9 -> V_112 ] ;
unsigned int V_50 ;
unsigned int V_497 = 0 ;
struct V_478 * V_241 ;
T_5 V_343 ;
int V_479 , V_68 ;
struct V_244 * V_483 ;
T_4 V_498 = V_499 ;
if ( F_142 ( V_254 ) > V_22 -> V_500 ) {
F_41 ( & V_215 -> V_225 ) ;
return V_494 ;
}
F_71 ( V_254 -> V_501 > V_502 ) ;
if ( F_223 ( V_120 , & V_486 ) ) {
F_41 ( & V_215 -> V_225 ) ;
return V_494 ;
}
V_9 -> V_129 = V_130 ;
V_9 -> V_101 = ( T_4 ) V_22 -> V_503 +
( V_9 -> V_112 * sizeof( * V_110 ) ) ;
F_71 ( V_9 -> V_101 & 0x0000007F ) ;
V_479 = F_220 ( V_254 ) ;
if ( V_479 < 0 ) {
F_41 ( & V_215 -> V_225 ) ;
return V_479 ;
}
if ( V_479 ) {
V_483 = V_110 -> V_246 ;
F_221 (cmd, sg, use_sg, i) {
V_343 = ( T_5 ) F_217 ( V_241 ) ;
V_50 = F_218 ( V_241 ) ;
V_497 += V_50 ;
V_483 -> V_252 = F_117 ( V_343 ) ;
V_483 -> V_251 = F_122 ( V_50 ) ;
V_483 -> V_248 = F_122 ( 0 ) ;
V_483 ++ ;
}
( -- V_483 ) -> V_248 = F_122 ( V_345 ) ;
switch ( V_254 -> V_504 ) {
case V_505 :
V_498 |= V_506 ;
break;
case V_507 :
V_498 |= V_508 ;
break;
case V_509 :
V_498 |= V_510 ;
break;
default:
F_69 ( & V_22 -> V_29 -> V_30 , L_143 ,
V_254 -> V_504 ) ;
F_166 () ;
break;
}
} else {
V_498 |= V_510 ;
}
V_9 -> V_103 . V_104 = V_479 ;
V_110 -> V_511 = F_143 ( V_167 & 0xFFFF ) ;
V_110 -> V_512 = F_122 ( V_497 ) ;
V_110 -> V_315 = F_143 ( V_513 |
( V_486 & V_316 ) ) ;
V_110 -> V_498 = F_122 ( V_498 ) ;
memcpy ( V_110 -> V_124 , V_120 , V_486 ) ;
memcpy ( V_110 -> V_320 , V_72 , 8 ) ;
F_56 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_225 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_253 * V_254 = V_9 -> V_10 ;
struct V_75 * V_30 = V_254 -> V_42 -> V_79 ;
V_9 -> V_215 = V_30 ;
return F_226 ( V_22 , V_9 , V_30 -> V_167 ,
V_254 -> V_514 , V_254 -> V_501 , V_30 -> V_72 , V_30 ) ;
}
static void F_227 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_118 * V_110 )
{
struct V_253 * V_254 = V_9 -> V_10 ;
struct V_75 * V_30 = V_254 -> V_42 -> V_79 ;
struct V_200 * V_201 = & V_30 -> V_166 ;
T_5 V_515 ;
if ( ! ( F_92 ( V_201 -> V_77 ) & V_392 ) )
return;
V_110 -> V_393 = V_201 -> V_393 ;
V_110 -> V_516 |= V_517 ;
switch ( V_254 -> V_514 [ 0 ] ) {
case V_490 :
case V_492 :
V_515 = F_228 ( & V_254 -> V_514 [ 2 ] ) ;
break;
case V_495 :
case V_496 :
case V_491 :
case V_493 :
V_515 = F_229 ( & V_254 -> V_514 [ 2 ] ) ;
break;
case V_518 :
case V_519 :
V_515 = F_230 ( & V_254 -> V_514 [ 2 ] ) ;
break;
default:
F_69 ( & V_22 -> V_29 -> V_30 ,
L_144 ,
V_184 , V_254 -> V_514 [ 0 ] ) ;
F_166 () ;
break;
}
if ( F_114 ( V_201 -> V_385 ) != 512 )
V_515 = V_515 *
F_114 ( V_201 -> V_385 ) / 512 ;
V_110 -> V_520 = F_122 ( V_515 ) ;
V_110 -> V_521 = F_122 ( V_515 >> 32 ) ;
}
static int F_231 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_167 , T_1 * V_120 , int V_486 ,
T_1 * V_72 , struct V_75 * V_215 )
{
struct V_253 * V_254 = V_9 -> V_10 ;
struct V_118 * V_110 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
struct V_235 * V_483 ;
int V_479 , V_68 ;
struct V_478 * V_241 ;
T_5 V_343 ;
T_4 V_50 ;
T_4 V_497 = 0 ;
F_71 ( F_142 ( V_254 ) > V_22 -> V_232 ) ;
if ( F_223 ( V_120 , & V_486 ) ) {
F_41 ( & V_215 -> V_225 ) ;
return V_494 ;
}
V_9 -> V_129 = V_133 ;
V_9 -> V_101 = ( T_4 ) V_22 -> V_522 +
( V_9 -> V_112 * sizeof( * V_110 ) ) ;
F_71 ( V_9 -> V_101 & 0x0000007F ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_523 = V_524 ;
V_479 = F_220 ( V_254 ) ;
if ( V_479 < 0 ) {
F_41 ( & V_215 -> V_225 ) ;
return V_479 ;
}
if ( V_479 ) {
V_483 = V_110 -> V_241 ;
if ( V_479 > V_22 -> V_500 ) {
V_343 = F_119 (
V_22 -> V_229 [ V_9 -> V_112 ] -> V_242 ) ;
V_483 -> V_242 = F_117 ( V_343 ) ;
V_483 -> V_525 = 0 ;
V_483 -> V_526 [ 0 ] = 0 ;
V_483 -> V_526 [ 1 ] = 0 ;
V_483 -> V_526 [ 2 ] = 0 ;
V_483 -> V_309 = 0x80 ;
V_483 = V_22 -> V_229 [ V_9 -> V_112 ] ;
}
F_221 (cmd, sg, use_sg, i) {
V_343 = ( T_5 ) F_217 ( V_241 ) ;
V_50 = F_218 ( V_241 ) ;
V_497 += V_50 ;
V_483 -> V_242 = F_117 ( V_343 ) ;
V_483 -> V_525 = F_122 ( V_50 ) ;
V_483 -> V_526 [ 0 ] = 0 ;
V_483 -> V_526 [ 1 ] = 0 ;
V_483 -> V_526 [ 2 ] = 0 ;
V_483 -> V_309 = 0 ;
V_483 ++ ;
}
switch ( V_254 -> V_504 ) {
case V_505 :
V_110 -> V_516 &= ~ V_527 ;
V_110 -> V_516 |= V_528 ;
break;
case V_507 :
V_110 -> V_516 &= ~ V_527 ;
V_110 -> V_516 |= V_529 ;
break;
case V_509 :
V_110 -> V_516 &= ~ V_527 ;
V_110 -> V_516 |= V_530 ;
break;
default:
F_69 ( & V_22 -> V_29 -> V_30 , L_143 ,
V_254 -> V_504 ) ;
F_166 () ;
break;
}
} else {
V_110 -> V_516 &= ~ V_527 ;
V_110 -> V_516 |= V_530 ;
}
F_227 ( V_22 , V_9 , V_110 ) ;
V_110 -> V_442 = F_122 ( V_167 ) ;
V_110 -> V_531 = F_122 ( V_9 -> V_112 << V_532 ) ;
memcpy ( V_110 -> V_120 , V_120 , sizeof( V_110 -> V_120 ) ) ;
V_110 -> V_239 = F_122 ( V_497 ) ;
V_110 -> V_533 = F_117 ( V_9 -> V_101 +
F_232 ( struct V_118 , V_258 ) ) ;
V_110 -> V_534 = F_122 ( sizeof( V_110 -> V_258 ) ) ;
if ( V_479 > V_22 -> V_500 ) {
V_110 -> V_119 = 1 ;
if ( F_113 ( V_22 , V_110 , V_9 ) ) {
F_41 ( & V_215 -> V_225 ) ;
F_141 ( V_254 ) ;
return - 1 ;
}
} else
V_110 -> V_119 = ( T_1 ) V_479 ;
F_56 ( V_22 , V_9 ) ;
return 0 ;
}
static int F_226 ( struct V_1 * V_22 ,
struct V_8 * V_9 , T_4 V_167 , T_1 * V_120 , int V_486 ,
T_1 * V_72 , struct V_75 * V_215 )
{
if ( F_169 ( & V_215 -> V_225 ) >
V_215 -> V_170 ) {
F_41 ( & V_215 -> V_225 ) ;
return V_494 ;
}
if ( V_22 -> V_63 & V_93 )
return F_224 ( V_22 , V_9 , V_167 ,
V_120 , V_486 , V_72 ,
V_215 ) ;
else
return F_231 ( V_22 , V_9 , V_167 ,
V_120 , V_486 , V_72 ,
V_215 ) ;
}
static void F_233 ( struct V_200 * V_201 ,
int V_169 , T_4 * V_535 , T_4 * V_536 )
{
if ( V_169 == 0 ) {
* V_535 %= F_92 ( V_201 -> V_206 ) ;
return;
}
do {
* V_536 = * V_535 /
F_92 ( V_201 -> V_206 ) ;
if ( V_169 == * V_536 )
continue;
if ( * V_536 < F_92 ( V_201 -> V_210 ) - 1 ) {
* V_535 += F_92 ( V_201 -> V_206 ) ;
( * V_536 ) ++ ;
} else {
* V_535 %= F_92 ( V_201 -> V_206 ) ;
* V_536 = 0 ;
}
} while ( V_169 != * V_536 );
}
static int F_234 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
struct V_253 * V_254 = V_9 -> V_10 ;
struct V_75 * V_30 = V_254 -> V_42 -> V_79 ;
struct V_200 * V_201 = & V_30 -> V_166 ;
struct V_202 * V_203 = & V_201 -> V_204 [ 0 ] ;
int V_487 = 0 ;
T_4 V_535 ;
T_5 V_515 , V_537 ;
T_4 V_489 ;
T_4 V_538 ;
T_5 V_539 , V_540 ;
T_4 V_541 , V_542 ;
T_4 V_543 , V_544 ;
T_5 V_545 , V_546 ;
T_4 V_547 ;
T_5 V_548 , V_549 ;
T_4 V_550 , V_551 ;
T_4 V_552 , V_553 ;
T_4 V_205 ;
T_4 V_554 ;
T_4 V_555 , V_556 , V_536 ;
T_4 V_557 ;
T_4 V_558 ;
T_5 V_559 ;
T_4 V_560 ;
T_1 V_120 [ 16 ] ;
T_1 V_486 ;
T_6 V_389 ;
#if V_561 == 32
T_5 V_562 ;
#endif
int V_169 ;
switch ( V_254 -> V_514 [ 0 ] ) {
case V_490 :
V_487 = 1 ;
case V_492 :
V_515 =
( ( ( T_5 ) V_254 -> V_514 [ 2 ] ) << 8 ) |
V_254 -> V_514 [ 3 ] ;
V_489 = V_254 -> V_514 [ 4 ] ;
if ( V_489 == 0 )
V_489 = 256 ;
break;
case V_495 :
V_487 = 1 ;
case V_496 :
V_515 =
( ( ( T_5 ) V_254 -> V_514 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_254 -> V_514 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_254 -> V_514 [ 4 ] ) << 8 ) |
V_254 -> V_514 [ 5 ] ;
V_489 =
( ( ( T_4 ) V_254 -> V_514 [ 7 ] ) << 8 ) |
V_254 -> V_514 [ 8 ] ;
break;
case V_491 :
V_487 = 1 ;
case V_493 :
V_515 =
( ( ( T_5 ) V_254 -> V_514 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_254 -> V_514 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_254 -> V_514 [ 4 ] ) << 8 ) |
V_254 -> V_514 [ 5 ] ;
V_489 =
( ( ( T_4 ) V_254 -> V_514 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_254 -> V_514 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_254 -> V_514 [ 8 ] ) << 8 ) |
V_254 -> V_514 [ 9 ] ;
break;
case V_518 :
V_487 = 1 ;
case V_519 :
V_515 =
( ( ( T_5 ) V_254 -> V_514 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_254 -> V_514 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_254 -> V_514 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_254 -> V_514 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_254 -> V_514 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_254 -> V_514 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_254 -> V_514 [ 8 ] ) << 8 ) |
V_254 -> V_514 [ 9 ] ;
V_489 =
( ( ( T_4 ) V_254 -> V_514 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_254 -> V_514 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_254 -> V_514 [ 12 ] ) << 8 ) |
V_254 -> V_514 [ 13 ] ;
break;
default:
return V_494 ;
}
V_537 = V_515 + V_489 - 1 ;
if ( V_487 && V_30 -> V_82 != 0 )
return V_494 ;
if ( V_537 >= F_119 ( V_201 -> V_386 ) ||
V_537 < V_515 )
return V_494 ;
V_538 = F_92 ( V_201 -> V_206 ) *
F_92 ( V_201 -> V_389 ) ;
V_389 = F_92 ( V_201 -> V_389 ) ;
#if V_561 == 32
V_562 = V_515 ;
( void ) F_235 ( V_562 , V_538 ) ;
V_539 = V_562 ;
V_562 = V_537 ;
( void ) F_235 ( V_562 , V_538 ) ;
V_540 = V_562 ;
V_541 = ( T_4 ) ( V_515 - ( V_539 * V_538 ) ) ;
V_542 = ( T_4 ) ( V_537 - ( V_540 * V_538 ) ) ;
V_562 = V_541 ;
( void ) F_235 ( V_562 , V_389 ) ;
V_543 = V_562 ;
V_562 = V_542 ;
( void ) F_235 ( V_562 , V_389 ) ;
V_544 = V_562 ;
#else
V_539 = V_515 / V_538 ;
V_540 = V_537 / V_538 ;
V_541 = ( T_4 ) ( V_515 - ( V_539 * V_538 ) ) ;
V_542 = ( T_4 ) ( V_537 - ( V_540 * V_538 ) ) ;
V_543 = V_541 / V_389 ;
V_544 = V_542 / V_389 ;
#endif
if ( ( V_539 != V_540 ) || ( V_543 != V_544 ) )
return V_494 ;
V_205 = F_92 ( V_201 -> V_206 ) +
F_92 ( V_201 -> V_207 ) ;
V_557 = ( ( T_4 ) ( V_539 >> V_201 -> V_388 ) ) %
F_92 ( V_201 -> V_209 ) ;
V_535 = ( V_557 * V_205 ) + V_543 ;
switch ( V_30 -> V_82 ) {
case V_563 :
break;
case V_564 :
F_71 ( F_92 ( V_201 -> V_210 ) != 2 ) ;
if ( V_30 -> V_169 )
V_535 += F_92 ( V_201 -> V_206 ) ;
V_30 -> V_169 = ! V_30 -> V_169 ;
break;
case V_565 :
F_71 ( F_92 ( V_201 -> V_210 ) != 3 ) ;
V_169 = V_30 -> V_169 ;
F_233 ( V_201 , V_169 ,
& V_535 , & V_536 ) ;
V_169 =
( V_169 >=
F_92 ( V_201 -> V_210 ) - 1 )
? 0 : V_169 + 1 ;
V_30 -> V_169 = V_169 ;
break;
case V_566 :
case V_567 :
if ( F_92 ( V_201 -> V_210 ) <= 1 )
break;
V_547 =
F_92 ( V_201 -> V_389 ) *
F_92 ( V_201 -> V_206 ) ;
F_71 ( V_547 == 0 ) ;
V_554 = V_547 *
F_92 ( V_201 -> V_210 ) ;
#if V_561 == 32
V_562 = V_515 ;
V_555 = F_235 ( V_562 , V_554 ) ;
V_562 = V_555 ;
( void ) F_235 ( V_562 , V_547 ) ;
V_555 = V_562 ;
V_562 = V_537 ;
V_556 = F_235 ( V_562 , V_554 ) ;
V_562 = V_556 ;
( void ) F_235 ( V_562 , V_547 ) ;
V_556 = V_562 ;
#else
V_555 = ( V_515 % V_554 ) / V_547 ;
V_556 = ( V_537 % V_554 ) / V_547 ;
#endif
if ( V_555 != V_556 )
return V_494 ;
#if V_561 == 32
V_562 = V_515 ;
( void ) F_235 ( V_562 , V_554 ) ;
V_539 = V_548 = V_545 = V_562 ;
V_562 = V_537 ;
( void ) F_235 ( V_562 , V_554 ) ;
V_549 = V_546 = V_562 ;
#else
V_539 = V_548 = V_545 =
V_515 / V_554 ;
V_549 = V_546 = V_537 / V_554 ;
#endif
if ( V_548 != V_549 )
return V_494 ;
#if V_561 == 32
V_562 = V_515 ;
V_541 = F_235 ( V_562 , V_554 ) ;
V_562 = V_541 ;
V_541 = ( T_4 ) F_235 ( V_562 , V_547 ) ;
V_550 = V_541 ;
V_562 = V_537 ;
V_551 = F_235 ( V_562 , V_554 ) ;
V_562 = V_551 ;
V_551 = F_235 ( V_562 , V_547 ) ;
V_562 = V_550 ;
( void ) F_235 ( V_562 , V_201 -> V_389 ) ;
V_543 = V_552 = V_562 ;
V_562 = V_551 ;
( void ) F_235 ( V_562 , V_201 -> V_389 ) ;
V_553 = V_562 ;
#else
V_541 = V_550 =
( T_4 ) ( ( V_515 % V_554 ) %
V_547 ) ;
V_551 =
( T_4 ) ( ( V_537 % V_554 ) %
V_547 ) ;
V_543 = V_552 =
V_550 / F_92 ( V_201 -> V_389 ) ;
V_553 =
V_551 / F_92 ( V_201 -> V_389 ) ;
#endif
if ( V_552 != V_553 )
return V_494 ;
V_557 = ( ( T_4 ) ( V_539 >> V_201 -> V_388 ) ) %
F_92 ( V_201 -> V_209 ) ;
V_535 = ( V_555 *
( F_92 ( V_201 -> V_209 ) * V_205 ) ) +
( V_557 * V_205 ) + V_543 ;
break;
default:
return V_494 ;
}
if ( F_40 ( V_535 >= V_213 ) )
return V_494 ;
V_9 -> V_215 = V_30 -> V_215 [ V_535 ] ;
V_558 = V_203 [ V_535 ] . V_167 ;
V_559 = F_119 ( V_201 -> V_390 ) +
V_539 * F_92 ( V_201 -> V_389 ) +
( V_541 - V_543 *
F_92 ( V_201 -> V_389 ) ) ;
V_560 = V_489 ;
if ( V_201 -> V_387 ) {
V_559 <<= V_201 -> V_387 ;
V_560 <<= V_201 -> V_387 ;
}
F_71 ( V_560 > 0xffff ) ;
if ( V_559 > 0xffffffff ) {
V_120 [ 0 ] = V_487 ? V_518 : V_519 ;
V_120 [ 1 ] = 0 ;
V_120 [ 2 ] = ( T_1 ) ( V_559 >> 56 ) ;
V_120 [ 3 ] = ( T_1 ) ( V_559 >> 48 ) ;
V_120 [ 4 ] = ( T_1 ) ( V_559 >> 40 ) ;
V_120 [ 5 ] = ( T_1 ) ( V_559 >> 32 ) ;
V_120 [ 6 ] = ( T_1 ) ( V_559 >> 24 ) ;
V_120 [ 7 ] = ( T_1 ) ( V_559 >> 16 ) ;
V_120 [ 8 ] = ( T_1 ) ( V_559 >> 8 ) ;
V_120 [ 9 ] = ( T_1 ) ( V_559 ) ;
V_120 [ 10 ] = ( T_1 ) ( V_560 >> 24 ) ;
V_120 [ 11 ] = ( T_1 ) ( V_560 >> 16 ) ;
V_120 [ 12 ] = ( T_1 ) ( V_560 >> 8 ) ;
V_120 [ 13 ] = ( T_1 ) ( V_560 ) ;
V_120 [ 14 ] = 0 ;
V_120 [ 15 ] = 0 ;
V_486 = 16 ;
} else {
V_120 [ 0 ] = V_487 ? V_495 : V_496 ;
V_120 [ 1 ] = 0 ;
V_120 [ 2 ] = ( T_1 ) ( V_559 >> 24 ) ;
V_120 [ 3 ] = ( T_1 ) ( V_559 >> 16 ) ;
V_120 [ 4 ] = ( T_1 ) ( V_559 >> 8 ) ;
V_120 [ 5 ] = ( T_1 ) ( V_559 ) ;
V_120 [ 6 ] = 0 ;
V_120 [ 7 ] = ( T_1 ) ( V_560 >> 8 ) ;
V_120 [ 8 ] = ( T_1 ) ( V_560 ) ;
V_120 [ 9 ] = 0 ;
V_486 = 10 ;
}
return F_226 ( V_22 , V_9 , V_558 , V_120 , V_486 ,
V_30 -> V_72 ,
V_30 -> V_215 [ V_535 ] ) ;
}
static int F_236 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_253 * V_254 ,
unsigned char V_72 [] )
{
V_254 -> V_568 = ( unsigned char * ) V_9 ;
V_9 -> V_129 = V_308 ;
V_9 -> V_10 = V_254 ;
V_9 -> V_103 . V_107 = 0 ;
memcpy ( & V_9 -> V_103 . V_318 . V_319 [ 0 ] , & V_72 [ 0 ] , 8 ) ;
V_9 -> V_103 . V_317 = F_117 ( ( V_9 -> V_112 << V_532 ) ) ;
V_9 -> V_123 . V_569 = 0 ;
F_71 ( V_254 -> V_501 > sizeof( V_9 -> V_123 . V_124 ) ) ;
V_9 -> V_123 . V_314 = V_254 -> V_501 ;
memcpy ( V_9 -> V_123 . V_124 , V_254 -> V_514 , V_254 -> V_501 ) ;
switch ( V_254 -> V_504 ) {
case V_505 :
V_9 -> V_123 . V_570 =
F_237 ( V_362 , V_571 , V_572 ) ;
break;
case V_507 :
V_9 -> V_123 . V_570 =
F_237 ( V_362 , V_571 , V_573 ) ;
break;
case V_509 :
V_9 -> V_123 . V_570 =
F_237 ( V_362 , V_571 , V_574 ) ;
break;
case V_575 :
V_9 -> V_123 . V_570 =
F_237 ( V_362 , V_571 , V_576 ) ;
break;
default:
F_69 ( & V_22 -> V_29 -> V_30 , L_143 ,
V_254 -> V_504 ) ;
F_166 () ;
break;
}
if ( F_219 ( V_22 , V_9 , V_254 ) < 0 ) {
F_130 ( V_22 , V_9 ) ;
return V_577 ;
}
F_56 ( V_22 , V_9 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_22 , int V_179 ,
struct V_8 * V_9 )
{
V_341 V_578 , V_579 ;
memset ( V_9 , 0 , F_232 ( struct V_8 , V_377 ) ) ;
V_9 -> V_103 . V_317 = F_117 ( ( T_5 ) ( V_179 << V_532 ) ) ;
V_578 = V_22 -> V_580 + V_179 * sizeof( * V_9 ) ;
V_9 -> V_24 = V_22 -> V_581 + V_179 ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_579 = V_22 -> V_582
+ V_179 * sizeof( * V_9 -> V_24 ) ;
V_9 -> V_112 = V_179 ;
V_9 -> V_101 = ( T_4 ) V_578 ;
V_9 -> V_583 . V_252 = F_117 ( ( T_5 ) V_579 ) ;
V_9 -> V_583 . V_251 = F_122 ( ( T_4 ) sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_10 = V_11 ;
}
static void F_239 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
struct V_8 * V_9 = V_22 -> V_376 + V_68 ;
F_238 ( V_22 , V_68 , V_9 ) ;
F_105 ( & V_9 -> V_377 , 0 ) ;
}
}
static inline void F_240 ( struct V_1 * V_22 , int V_179 ,
struct V_8 * V_9 )
{
V_341 V_578 = V_22 -> V_580 + V_179 * sizeof( * V_9 ) ;
F_71 ( V_9 -> V_112 != V_179 ) ;
memset ( V_9 -> V_123 . V_124 , 0 , sizeof( V_9 -> V_123 . V_124 ) ) ;
memset ( V_9 -> V_24 , 0 , sizeof( * V_9 -> V_24 ) ) ;
V_9 -> V_101 = ( T_4 ) V_578 ;
}
static int F_241 ( struct V_1 * V_22 ,
struct V_8 * V_9 , struct V_253 * V_254 ,
unsigned char * V_72 )
{
struct V_75 * V_30 = V_254 -> V_42 -> V_79 ;
int V_21 = V_494 ;
V_254 -> V_568 = ( unsigned char * ) V_9 ;
if ( V_30 -> V_88 ) {
F_238 ( V_22 , V_9 -> V_112 , V_9 ) ;
V_9 -> V_129 = V_308 ;
V_9 -> V_10 = V_254 ;
V_21 = F_234 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_577 ;
} else if ( V_30 -> V_168 ) {
F_238 ( V_22 , V_9 -> V_112 , V_9 ) ;
V_9 -> V_129 = V_308 ;
V_9 -> V_10 = V_254 ;
V_21 = F_225 ( V_22 , V_9 ) ;
if ( V_21 < 0 )
V_21 = V_577 ;
}
return V_21 ;
}
static void V_294 ( struct V_584 * V_293 )
{
struct V_253 * V_254 ;
struct V_75 * V_30 ;
struct V_8 * V_9 = F_242 ( V_293 , struct V_8 , V_293 ) ;
V_254 = V_9 -> V_10 ;
V_30 = V_254 -> V_42 -> V_79 ;
if ( ! V_30 ) {
V_254 -> V_263 = V_312 << 16 ;
return F_132 ( V_9 -> V_22 , V_9 , V_254 ) ;
}
if ( V_9 -> V_13 )
return F_130 ( V_9 -> V_22 , V_9 ) ;
if ( V_9 -> V_12 )
return F_137 ( V_9 -> V_22 , V_9 , V_254 ) ;
if ( V_9 -> V_129 == V_133 ) {
struct V_1 * V_22 = V_9 -> V_22 ;
struct V_118 * V_255 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
int V_21 ;
if ( V_255 -> V_258 . V_259 ==
V_272 ) {
V_21 = F_241 ( V_22 , V_9 , V_254 , V_30 -> V_72 ) ;
if ( V_21 == 0 )
return;
if ( V_21 == V_577 ) {
V_254 -> V_263 = V_585 << 16 ;
return F_132 ( V_22 , V_9 , V_254 ) ;
}
}
}
F_240 ( V_9 -> V_22 , V_9 -> V_112 , V_9 ) ;
if ( F_236 ( V_9 -> V_22 , V_9 , V_254 , V_30 -> V_72 ) ) {
V_254 -> V_263 = V_585 << 16 ;
V_254 -> V_292 ( V_254 ) ;
}
}
static int F_243 ( struct V_6 * V_7 , struct V_253 * V_254 )
{
struct V_1 * V_22 ;
struct V_75 * V_30 ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 ;
int V_21 = 0 ;
V_22 = F_1 ( V_254 -> V_42 ) ;
F_71 ( V_254 -> V_586 -> V_317 < 0 ) ;
V_30 = V_254 -> V_42 -> V_79 ;
if ( ! V_30 ) {
V_254 -> V_263 = V_312 << 16 ;
V_254 -> V_292 ( V_254 ) ;
return 0 ;
}
memcpy ( V_72 , V_30 -> V_72 , sizeof( V_72 ) ) ;
if ( F_40 ( F_13 ( V_22 ) ) ) {
V_254 -> V_263 = V_312 << 16 ;
V_254 -> V_292 ( V_254 ) ;
return 0 ;
}
V_9 = F_244 ( V_22 , V_254 ) ;
if ( F_43 ( V_254 -> V_587 == 0 &&
V_254 -> V_586 -> V_129 == V_588 &&
V_22 -> V_56 ) ) {
V_21 = F_241 ( V_22 , V_9 , V_254 , V_72 ) ;
if ( V_21 == 0 )
return 0 ;
if ( V_21 == V_577 ) {
F_130 ( V_22 , V_9 ) ;
return V_577 ;
}
}
return F_236 ( V_22 , V_9 , V_254 , V_72 ) ;
}
static void F_245 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
F_34 ( & V_22 -> V_589 , V_77 ) ;
V_22 -> V_590 = 1 ;
F_129 ( & V_22 -> V_591 ) ;
F_35 ( & V_22 -> V_589 , V_77 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_77 ;
if ( F_40 ( F_13 ( V_22 ) ) )
return F_245 ( V_22 ) ;
while ( 1 ) {
F_34 ( & V_22 -> V_589 , V_77 ) ;
if ( V_22 -> V_590 )
break;
F_35 ( & V_22 -> V_589 , V_77 ) ;
F_170 ( V_22 -> V_591 , V_22 -> V_590 ) ;
}
V_22 -> V_590 = 0 ;
F_35 ( & V_22 -> V_589 , V_77 ) ;
if ( F_40 ( F_13 ( V_22 ) ) )
return F_245 ( V_22 ) ;
F_213 ( V_22 , V_22 -> V_59 -> V_147 ) ;
F_245 ( V_22 ) ;
}
static int F_246 ( struct V_2 * V_3 , int V_212 )
{
struct V_75 * V_199 = V_3 -> V_79 ;
if ( ! V_199 )
return - V_80 ;
if ( V_212 < 1 )
V_212 = 1 ;
else if ( V_212 > V_199 -> V_170 )
V_212 = V_199 -> V_170 ;
return F_107 ( V_3 , V_212 ) ;
}
static int F_247 ( struct V_6 * V_7 ,
unsigned long V_592 )
{
struct V_1 * V_22 = F_3 ( V_7 ) ;
unsigned long V_77 ;
int V_593 ;
F_34 ( & V_22 -> V_589 , V_77 ) ;
V_593 = V_22 -> V_590 ;
F_35 ( & V_22 -> V_589 , V_77 ) ;
return V_593 ;
}
static int F_248 ( struct V_1 * V_22 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_249 ( & V_594 , sizeof( V_22 ) ) ;
if ( V_7 == NULL ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_145 ) ;
return - V_231 ;
}
V_7 -> V_595 = 0 ;
V_7 -> V_596 = 0 ;
V_7 -> V_597 = - 1 ;
V_7 -> V_598 = 3 ;
V_7 -> V_599 = V_600 ;
V_7 -> V_601 = V_450 ;
V_7 -> V_602 = V_450 ;
V_7 -> V_228 = V_22 -> V_217 - V_603 ;
V_7 -> V_604 = V_7 -> V_228 ;
V_7 -> V_605 = V_22 -> V_232 ;
V_7 -> V_79 [ 0 ] = ( unsigned long ) V_22 ;
V_7 -> V_606 = V_22 -> V_607 [ V_22 -> V_608 ] ;
V_7 -> V_609 = V_7 -> V_606 ;
error = F_250 ( V_7 , V_7 -> V_228 ) ;
if ( error ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_146 ,
V_184 , V_22 -> V_610 ) ;
F_251 ( V_7 ) ;
return error ;
}
V_22 -> V_59 = V_7 ;
return 0 ;
}
static int F_252 ( struct V_1 * V_22 )
{
int V_611 ;
V_611 = F_253 ( V_22 -> V_59 , & V_22 -> V_29 -> V_30 ) ;
if ( V_611 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_147 ) ;
return V_611 ;
}
F_254 ( V_22 -> V_59 ) ;
return 0 ;
}
static int F_255 ( struct V_253 * V_612 )
{
int V_613 = V_612 -> V_586 -> V_317 ;
if ( V_613 < 0 )
return V_613 ;
return V_613 += V_603 ;
}
static int F_256 ( struct V_1 * V_22 ,
struct V_8 * V_9 , unsigned char V_614 [] ,
int V_92 )
{
int V_21 ;
( void ) F_161 ( V_9 , V_423 , V_22 ,
NULL , 0 , 0 , V_614 , V_362 ) ;
V_21 = F_151 ( V_22 , V_9 , V_92 , V_349 ) ;
if ( V_21 )
return V_21 ;
if ( V_9 -> V_24 -> V_36 == V_615 )
return 0 ;
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 == V_264 &&
( V_9 -> V_24 -> V_26 [ 2 ] == V_616 ||
V_9 -> V_24 -> V_26 [ 2 ] == V_27 ) )
return 0 ;
return 1 ;
}
static int F_257 ( struct V_1 * V_22 ,
struct V_8 * V_9 ,
unsigned char V_614 [] , int V_92 )
{
int V_21 ;
int V_48 = 0 ;
int V_617 = 1 ;
for ( V_48 = 0 ; V_48 < V_618 ; V_48 ++ ) {
F_156 ( 1000 * V_617 ) ;
V_21 = F_256 ( V_22 , V_9 , V_614 , V_92 ) ;
if ( ! V_21 )
break;
if ( V_617 < V_619 )
V_617 *= 2 ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_148 ,
V_617 ) ;
}
return V_21 ;
}
static int F_258 ( struct V_1 * V_22 ,
unsigned char V_614 [] ,
int V_92 )
{
int V_620 ;
int V_621 ;
int V_91 ;
int V_21 = 0 ;
struct V_8 * V_9 ;
V_9 = F_160 ( V_22 ) ;
if ( V_92 == V_106 ) {
V_620 = 0 ;
V_621 = V_22 -> V_108 - 1 ;
} else {
V_620 = V_92 ;
V_621 = V_92 ;
}
for ( V_91 = V_620 ; V_91 <= V_621 ; V_91 ++ ) {
V_21 = F_257 ( V_22 , V_9 , V_614 , V_91 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_9 ( & V_22 -> V_29 -> V_30 , L_149 ) ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_150 ) ;
F_162 ( V_22 , V_9 ) ;
return V_21 ;
}
static int F_259 ( struct V_253 * V_622 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_75 * V_30 ;
char V_623 [ 40 ] ;
V_22 = F_1 ( V_622 -> V_42 ) ;
if ( V_22 == NULL )
return V_624 ;
if ( F_13 ( V_22 ) )
return V_624 ;
V_30 = V_622 -> V_42 -> V_79 ;
if ( ! V_30 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_151 , V_184 ) ;
return V_624 ;
}
if ( F_13 ( V_22 ) ) {
sprintf ( V_623 , L_152 ,
F_255 ( V_622 ) ) ;
F_65 ( V_224 , V_22 , V_30 , V_623 ) ;
return V_624 ;
}
if ( F_260 ( V_22 ) ) {
sprintf ( V_623 , L_153 ,
F_255 ( V_622 ) ) ;
F_65 ( V_224 , V_22 , V_30 , V_623 ) ;
return V_624 ;
}
if ( F_58 ( V_30 -> V_72 ) )
return V_625 ;
F_65 ( V_224 , V_22 , V_30 , L_154 ) ;
V_21 = F_167 ( V_22 , V_30 , V_30 -> V_72 , V_626 ,
V_106 ) ;
sprintf ( V_623 , L_155 , V_21 == 0 ? L_156 : L_157 ) ;
F_65 ( V_224 , V_22 , V_30 , V_623 ) ;
return V_21 == 0 ? V_625 : V_624 ;
}
static void F_261 ( T_1 * V_317 )
{
T_1 V_627 [ 8 ] ;
memcpy ( V_627 , V_317 , 8 ) ;
V_317 [ 0 ] = V_627 [ 3 ] ;
V_317 [ 1 ] = V_627 [ 2 ] ;
V_317 [ 2 ] = V_627 [ 1 ] ;
V_317 [ 3 ] = V_627 [ 0 ] ;
V_317 [ 4 ] = V_627 [ 7 ] ;
V_317 [ 5 ] = V_627 [ 6 ] ;
V_317 [ 6 ] = V_627 [ 5 ] ;
V_317 [ 7 ] = V_627 [ 4 ] ;
}
static void F_262 ( struct V_1 * V_22 ,
struct V_8 * V_9 , V_436 * V_628 , V_436 * V_629 )
{
T_5 V_317 ;
if ( V_9 -> V_129 == V_130 ) {
struct V_109 * V_630 = (struct V_109 * )
& V_22 -> V_111 [ V_9 -> V_112 ] ;
V_317 = F_119 ( V_630 -> V_317 ) ;
* V_629 = F_122 ( V_317 >> 32 ) ;
* V_628 = F_122 ( V_317 ) ;
return;
}
if ( V_9 -> V_129 == V_133 ) {
struct V_118 * V_631 = (struct V_118 * )
& V_22 -> V_116 [ V_9 -> V_112 ] ;
memset ( V_629 , 0 , sizeof( * V_629 ) ) ;
* V_628 = V_631 -> V_531 ;
return;
}
V_317 = F_119 ( V_9 -> V_103 . V_317 ) ;
* V_629 = F_122 ( V_317 >> 32 ) ;
* V_628 = F_122 ( V_317 ) ;
}
static int F_263 ( struct V_1 * V_22 , unsigned char * V_72 ,
struct V_8 * abort , int V_92 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
struct V_305 * V_306 ;
V_436 V_629 , V_628 ;
V_9 = F_160 ( V_22 ) ;
( void ) F_161 ( V_9 , V_425 , V_22 , & abort -> V_103 . V_317 ,
0 , 0 , V_72 , V_369 ) ;
if ( V_22 -> V_71 )
F_261 ( & V_9 -> V_123 . V_124 [ 4 ] ) ;
( void ) F_151 ( V_22 , V_9 , V_92 , V_349 ) ;
F_262 ( V_22 , abort , & V_628 , & V_629 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_158 ,
V_184 , V_629 , V_628 ) ;
V_306 = V_9 -> V_24 ;
switch ( V_306 -> V_36 ) {
case V_615 :
break;
case V_337 :
V_21 = F_139 ( V_22 , V_9 ) ;
break;
case V_336 :
V_21 = - 1 ;
break;
default:
F_264 ( & V_22 -> V_29 -> V_30 , L_159 ,
V_184 , V_629 , V_628 ) ;
F_158 ( V_22 , V_9 ) ;
V_21 = - 1 ;
break;
}
F_162 ( V_22 , V_9 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_160 ,
V_184 , V_629 , V_628 ) ;
return V_21 ;
}
static void F_265 ( struct V_8 * V_9 , struct V_1 * V_22 ,
struct V_8 * V_632 , int V_92 )
{
struct V_118 * V_255 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
struct V_115 * V_371 = (struct V_115 * ) V_255 ;
struct V_118 * V_633 =
& V_22 -> V_116 [ V_632 -> V_112 ] ;
struct V_253 * V_612 = V_632 -> V_10 ;
struct V_75 * V_30 = V_612 -> V_42 -> V_79 ;
F_266 ( sizeof( struct V_115 ) >
sizeof( struct V_118 ) ) ;
F_71 ( F_232 ( struct V_118 , V_258 ) <
F_232 ( struct V_115 , V_634 ) +
sizeof( V_371 -> V_634 ) ) ;
V_9 -> V_129 = V_135 ;
V_9 -> V_10 = V_635 ;
V_9 -> V_101 = ( T_4 ) V_22 -> V_522 +
( V_9 -> V_112 * sizeof( struct V_118 ) ) ;
F_71 ( V_9 -> V_101 & 0x0000007F ) ;
memset ( V_371 , 0 , sizeof( * V_255 ) ) ;
V_371 -> V_636 = V_637 ;
V_371 -> V_92 = V_92 ;
V_371 -> V_638 = V_639 ;
V_371 -> V_373 = F_122 ( V_30 -> V_167 ) ;
memset ( V_371 -> V_640 , 0 , sizeof( V_371 -> V_640 ) ) ;
V_371 -> V_317 = F_117 ( V_9 -> V_112 << V_532 ) ;
V_371 -> V_641 = F_117 ( F_114 ( V_633 -> V_531 ) ) ;
V_371 -> V_642 = F_117 ( V_9 -> V_101 +
F_232 ( struct V_118 , V_258 ) ) ;
V_371 -> V_634 = F_122 ( sizeof( V_255 -> V_258 ) ) ;
}
static int F_267 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_92 )
{
int V_21 = V_350 ;
struct V_253 * V_612 ;
struct V_75 * V_30 ;
unsigned char V_643 [ 8 ] ;
unsigned char * V_644 = & V_643 [ 0 ] ;
V_612 = abort -> V_10 ;
V_30 = (struct V_75 * ) ( V_612 -> V_42 -> V_79 ) ;
if ( V_30 == NULL ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_161 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_162 ,
V_22 -> V_59 -> V_147 , V_30 -> V_138 , V_30 -> V_139 , V_30 -> V_140 ,
L_163 ,
V_72 [ 0 ] , V_72 [ 1 ] , V_72 [ 2 ] , V_72 [ 3 ] ,
V_72 [ 4 ] , V_72 [ 5 ] , V_72 [ 6 ] , V_72 [ 7 ] ) ;
if ( ! V_30 -> V_88 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_164 ) ;
return - 1 ;
}
if ( ! F_203 ( V_22 , abort , V_644 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_165 ) ;
return - 1 ;
}
if ( V_22 -> V_58 > 0 )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_166 ,
V_644 [ 0 ] , V_644 [ 1 ] , V_644 [ 2 ] , V_644 [ 3 ] ,
V_644 [ 4 ] , V_644 [ 5 ] , V_644 [ 6 ] , V_644 [ 7 ] ) ;
V_21 = F_167 ( V_22 , V_30 , V_644 , V_645 , V_92 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_167 ,
V_644 [ 0 ] , V_644 [ 1 ] , V_644 [ 2 ] , V_644 [ 3 ] ,
V_644 [ 4 ] , V_644 [ 5 ] , V_644 [ 6 ] , V_644 [ 7 ] ) ;
return V_21 ;
}
if ( F_258 ( V_22 , V_644 , V_92 ) != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_168 ,
V_644 [ 0 ] , V_644 [ 1 ] , V_644 [ 2 ] , V_644 [ 3 ] ,
V_644 [ 4 ] , V_644 [ 5 ] , V_644 [ 6 ] , V_644 [ 7 ] ) ;
return - 1 ;
}
F_90 ( & V_22 -> V_29 -> V_30 ,
L_169 ,
V_644 [ 0 ] , V_644 [ 1 ] , V_644 [ 2 ] , V_644 [ 3 ] ,
V_644 [ 4 ] , V_644 [ 5 ] , V_644 [ 6 ] , V_644 [ 7 ] ) ;
return V_21 ;
}
static int F_268 ( struct V_1 * V_22 ,
struct V_8 * abort , int V_92 )
{
int V_21 = V_350 ;
struct V_8 * V_9 ;
V_436 V_628 , V_629 ;
struct V_75 * V_30 ;
struct V_118 * V_255 ;
V_30 = abort -> V_10 -> V_42 -> V_79 ;
if ( ! V_30 -> V_88 && ! V_30 -> V_168 )
return - 1 ;
V_9 = F_160 ( V_22 ) ;
F_265 ( V_9 , V_22 , abort , V_92 ) ;
V_255 = & V_22 -> V_116 [ V_9 -> V_112 ] ;
( void ) F_151 ( V_22 , V_9 , V_92 , V_349 ) ;
F_262 ( V_22 , abort , & V_628 , & V_629 ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_170 ,
V_184 , V_629 , V_628 ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_171 ,
V_184 , V_629 , V_628 , V_255 -> V_258 . V_259 ) ;
switch ( V_255 -> V_258 . V_259 ) {
case V_285 :
case V_286 :
V_21 = 0 ;
break;
case V_287 :
case V_274 :
case V_288 :
V_21 = - 1 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_172 ,
V_184 , V_629 , V_628 ,
V_255 -> V_258 . V_259 ) ;
V_21 = - 1 ;
}
F_162 ( V_22 , V_9 ) ;
F_264 ( & V_22 -> V_29 -> V_30 , L_160 , V_184 ,
V_629 , V_628 ) ;
return V_21 ;
}
static int F_269 ( struct V_1 * V_22 ,
unsigned char * V_72 , struct V_8 * abort , int V_92 )
{
if ( abort -> V_129 == V_133 ) {
if ( V_646 & V_22 -> V_647 )
return F_268 ( V_22 , abort ,
V_92 ) ;
else
return F_267 ( V_22 , V_72 ,
abort , V_92 ) ;
}
return F_263 ( V_22 , V_72 , abort , V_92 ) ;
}
static int F_270 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_129 == V_133 )
return V_22 -> V_116 [ V_9 -> V_112 ] . V_92 ;
return V_9 -> V_103 . V_107 ;
}
static inline int F_271 ( struct V_1 * V_22 )
{
#define F_272 5000
return ! F_273 ( V_22 -> V_648 ,
F_274 ( & V_22 -> V_649 ) >= 0 ,
F_150 ( F_272 ) ) ;
}
static int F_275 ( struct V_253 * V_650 )
{
int V_21 ;
struct V_1 * V_22 ;
struct V_75 * V_30 ;
struct V_8 * abort ;
struct V_253 * V_651 ;
char V_623 [ 256 ] ;
int V_652 = 0 ;
V_436 V_629 , V_628 ;
int V_377 , V_92 ;
if ( V_650 == NULL )
return V_624 ;
if ( V_650 -> V_42 == NULL )
return V_624 ;
V_22 = F_1 ( V_650 -> V_42 ) ;
if ( V_22 == NULL )
return V_624 ;
V_30 = V_650 -> V_42 -> V_79 ;
if ( ! V_30 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_173 ,
V_623 ) ;
return V_624 ;
}
if ( F_13 ( V_22 ) ) {
F_65 ( V_224 , V_22 , V_30 ,
L_174 ) ;
return V_624 ;
}
if ( F_260 ( V_22 ) ) {
F_65 ( V_224 , V_22 , V_30 ,
L_175 ) ;
return V_624 ;
}
if ( ! ( V_653 & V_22 -> V_647 ) &&
! ( V_654 & V_22 -> V_647 ) )
return V_624 ;
memset ( V_623 , 0 , sizeof( V_623 ) ) ;
V_652 += sprintf ( V_623 + V_652 , L_176 ,
V_22 -> V_59 -> V_147 , V_650 -> V_42 -> V_655 ,
V_650 -> V_42 -> V_656 , V_650 -> V_42 -> V_140 ,
L_177 , V_650 ) ;
abort = (struct V_8 * ) V_650 -> V_568 ;
if ( abort == NULL ) {
return V_625 ;
}
V_377 = F_169 ( & abort -> V_377 ) ;
if ( V_377 == 1 ) {
F_162 ( V_22 , abort ) ;
return V_625 ;
}
if ( abort -> V_129 != V_133 &&
abort -> V_129 != V_130 && ! V_30 -> V_433 ) {
F_162 ( V_22 , abort ) ;
return V_624 ;
}
if ( abort -> V_10 != V_650 ) {
F_162 ( V_22 , abort ) ;
return V_625 ;
}
abort -> V_12 = true ;
F_262 ( V_22 , abort , & V_628 , & V_629 ) ;
V_92 = F_270 ( V_22 , abort ) ;
V_652 += sprintf ( V_623 + V_652 , L_178 , V_629 , V_628 ) ;
V_651 = abort -> V_10 ;
if ( V_651 != NULL )
V_652 += sprintf ( V_623 + V_652 ,
L_179 ,
V_651 -> V_501 , V_651 -> V_514 [ 0 ] , V_651 -> V_514 [ 1 ] ,
V_651 -> V_657 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_180 , V_623 ) ;
F_65 ( V_224 , V_22 , V_30 , L_177 ) ;
if ( F_271 ( V_22 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_181 ,
V_623 ) ;
F_162 ( V_22 , abort ) ;
return V_624 ;
}
V_21 = F_269 ( V_22 , V_30 -> V_72 , abort , V_92 ) ;
F_51 ( & V_22 -> V_649 ) ;
F_129 ( & V_22 -> V_648 ) ;
if ( V_21 != 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_182 , V_623 ) ;
F_65 ( V_224 , V_22 , V_30 ,
L_183 ) ;
F_162 ( V_22 , abort ) ;
return V_624 ;
}
F_90 ( & V_22 -> V_29 -> V_30 , L_184 , V_623 ) ;
F_170 ( V_22 -> V_291 ,
abort -> V_10 != V_650 || F_13 ( V_22 ) ) ;
F_162 ( V_22 , abort ) ;
return ! F_13 ( V_22 ) ? V_625 : V_624 ;
}
static struct V_8 * F_244 ( struct V_1 * V_22 ,
struct V_253 * V_612 )
{
int V_613 = F_255 ( V_612 ) ;
struct V_8 * V_9 = V_22 -> V_376 + V_613 ;
if ( V_613 < V_603 || V_613 >= V_22 -> V_217 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_185 ,
V_613 , V_603 , V_22 -> V_217 - 1 ) ;
F_166 () ;
}
F_51 ( & V_9 -> V_377 ) ;
if ( F_40 ( ! F_4 ( V_9 ) ) ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_186 ,
V_613 ) ;
if ( V_9 -> V_10 != NULL )
F_276 ( V_9 -> V_10 ) ;
F_276 ( V_612 ) ;
}
F_240 ( V_22 , V_613 , V_9 ) ;
return V_9 ;
}
static void F_131 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
( void ) F_41 ( & V_9 -> V_377 ) ;
}
static struct V_8 * F_160 ( struct V_1 * V_22 )
{
struct V_8 * V_9 ;
int V_377 , V_68 ;
int V_658 = 0 ;
for (; ; ) {
V_68 = F_277 ( V_22 -> V_659 ,
V_603 ,
V_658 ) ;
if ( F_40 ( V_68 >= V_603 ) ) {
V_658 = 0 ;
continue;
}
V_9 = V_22 -> V_376 + V_68 ;
V_377 = F_169 ( & V_9 -> V_377 ) ;
if ( F_40 ( V_377 > 1 ) ) {
F_162 ( V_22 , V_9 ) ;
V_658 = ( V_68 + 1 ) % V_603 ;
continue;
}
F_202 ( V_68 & ( V_561 - 1 ) ,
V_22 -> V_659 + ( V_68 / V_561 ) ) ;
break;
}
F_240 ( V_22 , V_68 , V_9 ) ;
return V_9 ;
}
static void F_162 ( struct V_1 * V_22 , struct V_8 * V_9 )
{
if ( F_53 ( & V_9 -> V_377 ) ) {
int V_68 ;
V_68 = V_9 - V_22 -> V_376 ;
F_278 ( V_68 & ( V_561 - 1 ) ,
V_22 -> V_659 + ( V_68 / V_561 ) ) ;
}
}
static int F_279 ( struct V_2 * V_30 , int V_254 ,
void T_7 * V_660 )
{
T_8 T_7 * V_661 =
( T_8 T_7 * ) V_660 ;
T_9 V_662 ;
T_9 T_7 * V_663 = F_280 ( sizeof( V_662 ) ) ;
int V_664 ;
T_4 V_110 ;
memset ( & V_662 , 0 , sizeof( V_662 ) ) ;
V_664 = 0 ;
V_664 |= F_281 ( & V_662 . V_665 , & V_661 -> V_665 ,
sizeof( V_662 . V_665 ) ) ;
V_664 |= F_281 ( & V_662 . V_123 , & V_661 -> V_123 ,
sizeof( V_662 . V_123 ) ) ;
V_664 |= F_281 ( & V_662 . V_666 , & V_661 -> V_666 ,
sizeof( V_662 . V_666 ) ) ;
V_664 |= F_282 ( V_662 . V_667 , & V_661 -> V_667 ) ;
V_664 |= F_282 ( V_110 , & V_661 -> V_45 ) ;
V_662 . V_45 = F_283 ( V_110 ) ;
V_664 |= F_284 ( V_663 , & V_662 , sizeof( V_662 ) ) ;
if ( V_664 )
return - V_668 ;
V_664 = F_285 ( V_30 , V_669 , V_663 ) ;
if ( V_664 )
return V_664 ;
V_664 |= F_286 ( & V_661 -> V_666 , & V_663 -> V_666 ,
sizeof( V_661 -> V_666 ) ) ;
if ( V_664 )
return - V_668 ;
return V_664 ;
}
static int F_287 ( struct V_2 * V_30 ,
int V_254 , void T_7 * V_660 )
{
T_10 T_7 * V_661 =
( T_10 T_7 * ) V_660 ;
T_11 V_662 ;
T_11 T_7 * V_663 =
F_280 ( sizeof( V_662 ) ) ;
int V_664 ;
T_4 V_110 ;
memset ( & V_662 , 0 , sizeof( V_662 ) ) ;
V_664 = 0 ;
V_664 |= F_281 ( & V_662 . V_665 , & V_661 -> V_665 ,
sizeof( V_662 . V_665 ) ) ;
V_664 |= F_281 ( & V_662 . V_123 , & V_661 -> V_123 ,
sizeof( V_662 . V_123 ) ) ;
V_664 |= F_281 ( & V_662 . V_666 , & V_661 -> V_666 ,
sizeof( V_662 . V_666 ) ) ;
V_664 |= F_282 ( V_662 . V_667 , & V_661 -> V_667 ) ;
V_664 |= F_282 ( V_662 . V_670 , & V_661 -> V_670 ) ;
V_664 |= F_282 ( V_110 , & V_661 -> V_45 ) ;
V_662 . V_45 = F_283 ( V_110 ) ;
V_664 |= F_284 ( V_663 , & V_662 , sizeof( V_662 ) ) ;
if ( V_664 )
return - V_668 ;
V_664 = F_285 ( V_30 , V_671 , V_663 ) ;
if ( V_664 )
return V_664 ;
V_664 |= F_286 ( & V_661 -> V_666 , & V_663 -> V_666 ,
sizeof( V_661 -> V_666 ) ) ;
if ( V_664 )
return - V_668 ;
return V_664 ;
}
static int F_288 ( struct V_2 * V_30 , int V_254 , void T_7 * V_660 )
{
switch ( V_254 ) {
case V_672 :
case V_673 :
case V_674 :
case V_675 :
case V_676 :
case V_677 :
case V_678 :
case V_679 :
case V_680 :
case V_681 :
case V_682 :
case V_683 :
case V_684 :
case V_685 :
case V_686 :
return F_285 ( V_30 , V_254 , V_660 ) ;
case V_687 :
return F_279 ( V_30 , V_254 , V_660 ) ;
case V_688 :
return F_287 ( V_30 , V_254 , V_660 ) ;
default:
return - V_689 ;
}
}
static int F_289 ( struct V_1 * V_22 , void T_7 * V_690 )
{
struct V_691 V_692 ;
if ( ! V_690 )
return - V_55 ;
V_692 . V_693 = F_290 ( V_22 -> V_29 -> V_138 ) ;
V_692 . V_138 = V_22 -> V_29 -> V_138 -> V_694 ;
V_692 . V_695 = V_22 -> V_29 -> V_696 ;
V_692 . V_67 = V_22 -> V_67 ;
if ( F_284 ( V_690 , & V_692 , sizeof( V_692 ) ) )
return - V_668 ;
return 0 ;
}
static int F_291 ( struct V_1 * V_22 , void T_7 * V_690 )
{
T_12 V_697 ;
unsigned char V_698 , V_699 , V_700 ;
int V_21 ;
V_21 = sscanf ( V_701 , L_187 ,
& V_698 , & V_699 , & V_700 ) ;
if ( V_21 != 3 ) {
F_90 ( & V_22 -> V_29 -> V_30 , L_188
L_189 , V_701 ) ;
V_698 = 0 ;
V_699 = 0 ;
V_700 = 0 ;
}
V_697 = ( V_698 << 16 ) | ( V_699 << 8 ) | V_700 ;
if ( ! V_690 )
return - V_55 ;
if ( F_284 ( V_690 , & V_697 , sizeof( T_12 ) ) )
return - V_668 ;
return 0 ;
}
static int F_292 ( struct V_1 * V_22 , void T_7 * V_690 )
{
T_9 V_702 ;
struct V_8 * V_9 ;
char * V_703 = NULL ;
T_5 V_237 ;
int V_21 = 0 ;
if ( ! V_690 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_704 ;
if ( F_281 ( & V_702 , V_690 , sizeof( V_702 ) ) )
return - V_668 ;
if ( ( V_702 . V_667 < 1 ) &&
( V_702 . V_123 . Type . V_705 != V_574 ) ) {
return - V_55 ;
}
if ( V_702 . V_667 > 0 ) {
V_703 = F_87 ( V_702 . V_667 , V_183 ) ;
if ( V_703 == NULL )
return - V_231 ;
if ( V_702 . V_123 . Type . V_705 & V_572 ) {
if ( F_281 ( V_703 , V_702 . V_45 ,
V_702 . V_667 ) ) {
V_21 = - V_668 ;
goto V_706;
}
} else {
memset ( V_703 , 0 , V_702 . V_667 ) ;
}
}
V_9 = F_160 ( V_22 ) ;
V_9 -> V_129 = V_372 ;
V_9 -> V_10 = V_635 ;
V_9 -> V_103 . V_107 = 0 ;
if ( V_702 . V_667 > 0 ) {
V_9 -> V_103 . V_104 = 1 ;
V_9 -> V_103 . V_250 = F_143 ( 1 ) ;
} else {
V_9 -> V_103 . V_104 = 0 ;
V_9 -> V_103 . V_250 = F_143 ( 0 ) ;
}
memcpy ( & V_9 -> V_103 . V_318 , & V_702 . V_665 , sizeof( V_9 -> V_103 . V_318 ) ) ;
memcpy ( & V_9 -> V_123 , & V_702 . V_123 ,
sizeof( V_9 -> V_123 ) ) ;
if ( V_702 . V_667 > 0 ) {
V_237 = F_115 ( V_22 -> V_29 , V_703 ,
V_702 . V_667 , V_707 ) ;
if ( F_116 ( & V_22 -> V_29 -> V_30 , ( V_341 ) V_237 ) ) {
V_9 -> V_246 [ 0 ] . V_252 = F_117 ( 0 ) ;
V_9 -> V_246 [ 0 ] . V_251 = F_122 ( 0 ) ;
V_21 = - V_231 ;
goto V_363;
}
V_9 -> V_246 [ 0 ] . V_252 = F_117 ( V_237 ) ;
V_9 -> V_246 [ 0 ] . V_251 = F_122 ( V_702 . V_667 ) ;
V_9 -> V_246 [ 0 ] . V_248 = F_122 ( V_345 ) ;
}
V_21 = F_151 ( V_22 , V_9 , V_106 , V_349 ) ;
if ( V_702 . V_667 > 0 )
F_144 ( V_22 -> V_29 , V_9 , 1 , V_707 ) ;
F_293 ( V_22 , V_9 ) ;
if ( V_21 ) {
V_21 = - V_356 ;
goto V_363;
}
memcpy ( & V_702 . V_666 , V_9 -> V_24 ,
sizeof( V_702 . V_666 ) ) ;
if ( F_284 ( V_690 , & V_702 , sizeof( V_702 ) ) ) {
V_21 = - V_668 ;
goto V_363;
}
if ( ( V_702 . V_123 . Type . V_705 & V_573 ) &&
V_702 . V_667 > 0 ) {
if ( F_284 ( V_702 . V_45 , V_703 , V_702 . V_667 ) ) {
V_21 = - V_668 ;
goto V_363;
}
}
V_363:
F_162 ( V_22 , V_9 ) ;
V_706:
F_76 ( V_703 ) ;
return V_21 ;
}
static int F_294 ( struct V_1 * V_22 , void T_7 * V_690 )
{
T_11 * V_708 ;
struct V_8 * V_9 ;
unsigned char * * V_703 = NULL ;
int * V_709 = NULL ;
T_5 V_237 ;
T_13 V_339 = 0 ;
int V_49 = 0 ;
T_4 V_710 ;
T_4 V_711 ;
T_13 T_7 * V_712 ;
if ( ! V_690 )
return - V_55 ;
if ( ! F_15 ( V_53 ) )
return - V_704 ;
V_708 = ( T_11 * )
F_87 ( sizeof( * V_708 ) , V_183 ) ;
if ( ! V_708 ) {
V_49 = - V_231 ;
goto V_713;
}
if ( F_281 ( V_708 , V_690 , sizeof( * V_708 ) ) ) {
V_49 = - V_668 ;
goto V_713;
}
if ( ( V_708 -> V_667 < 1 ) &&
( V_708 -> V_123 . Type . V_705 != V_574 ) ) {
V_49 = - V_55 ;
goto V_713;
}
if ( V_708 -> V_670 > V_714 ) {
V_49 = - V_55 ;
goto V_713;
}
if ( V_708 -> V_667 > V_708 -> V_670 * V_715 ) {
V_49 = - V_55 ;
goto V_713;
}
V_703 = F_96 ( V_715 * sizeof( char * ) , V_183 ) ;
if ( ! V_703 ) {
V_49 = - V_231 ;
goto V_713;
}
V_709 = F_87 ( V_715 * sizeof( int ) , V_183 ) ;
if ( ! V_709 ) {
V_49 = - V_231 ;
goto V_713;
}
V_710 = V_708 -> V_667 ;
V_712 = V_708 -> V_45 ;
while ( V_710 ) {
V_711 = ( V_710 > V_708 -> V_670 ) ? V_708 -> V_670 : V_710 ;
V_709 [ V_339 ] = V_711 ;
V_703 [ V_339 ] = F_87 ( V_711 , V_183 ) ;
if ( V_703 [ V_339 ] == NULL ) {
V_49 = - V_231 ;
goto V_713;
}
if ( V_708 -> V_123 . Type . V_705 & V_572 ) {
if ( F_281 ( V_703 [ V_339 ] , V_712 , V_711 ) ) {
V_49 = - V_668 ;
goto V_713;
}
} else
memset ( V_703 [ V_339 ] , 0 , V_711 ) ;
V_710 -= V_711 ;
V_712 += V_711 ;
V_339 ++ ;
}
V_9 = F_160 ( V_22 ) ;
V_9 -> V_129 = V_372 ;
V_9 -> V_10 = V_635 ;
V_9 -> V_103 . V_107 = 0 ;
V_9 -> V_103 . V_104 = ( T_1 ) V_339 ;
V_9 -> V_103 . V_250 = F_143 ( V_339 ) ;
memcpy ( & V_9 -> V_103 . V_318 , & V_708 -> V_665 , sizeof( V_9 -> V_103 . V_318 ) ) ;
memcpy ( & V_9 -> V_123 , & V_708 -> V_123 , sizeof( V_9 -> V_123 ) ) ;
if ( V_708 -> V_667 > 0 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_339 ; V_68 ++ ) {
V_237 = F_115 ( V_22 -> V_29 , V_703 [ V_68 ] ,
V_709 [ V_68 ] , V_707 ) ;
if ( F_116 ( & V_22 -> V_29 -> V_30 ,
( V_341 ) V_237 ) ) {
V_9 -> V_246 [ V_68 ] . V_252 = F_117 ( 0 ) ;
V_9 -> V_246 [ V_68 ] . V_251 = F_122 ( 0 ) ;
F_144 ( V_22 -> V_29 , V_9 , V_68 ,
V_707 ) ;
V_49 = - V_231 ;
goto V_716;
}
V_9 -> V_246 [ V_68 ] . V_252 = F_117 ( V_237 ) ;
V_9 -> V_246 [ V_68 ] . V_251 = F_122 ( V_709 [ V_68 ] ) ;
V_9 -> V_246 [ V_68 ] . V_248 = F_122 ( 0 ) ;
}
V_9 -> V_246 [ -- V_68 ] . V_248 = F_122 ( V_345 ) ;
}
V_49 = F_151 ( V_22 , V_9 , V_106 , V_349 ) ;
if ( V_339 )
F_144 ( V_22 -> V_29 , V_9 , V_339 , V_707 ) ;
F_293 ( V_22 , V_9 ) ;
if ( V_49 ) {
V_49 = - V_356 ;
goto V_716;
}
memcpy ( & V_708 -> V_666 , V_9 -> V_24 , sizeof( V_708 -> V_666 ) ) ;
if ( F_284 ( V_690 , V_708 , sizeof( * V_708 ) ) ) {
V_49 = - V_668 ;
goto V_716;
}
if ( ( V_708 -> V_123 . Type . V_705 & V_573 ) && V_708 -> V_667 > 0 ) {
int V_68 ;
T_13 T_7 * V_717 = V_708 -> V_45 ;
for ( V_68 = 0 ; V_68 < V_339 ; V_68 ++ ) {
if ( F_284 ( V_717 , V_703 [ V_68 ] , V_709 [ V_68 ] ) ) {
V_49 = - V_668 ;
goto V_716;
}
V_717 += V_709 [ V_68 ] ;
}
}
V_49 = 0 ;
V_716:
F_162 ( V_22 , V_9 ) ;
V_713:
if ( V_703 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < V_339 ; V_68 ++ )
F_76 ( V_703 [ V_68 ] ) ;
F_76 ( V_703 ) ;
}
F_76 ( V_709 ) ;
F_76 ( V_708 ) ;
return V_49 ;
}
static void F_293 ( struct V_1 * V_22 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_24 -> V_36 == V_37 &&
V_9 -> V_24 -> V_38 != V_264 )
( void ) F_8 ( V_22 , V_9 ) ;
}
static int F_285 ( struct V_2 * V_30 , int V_254 , void T_7 * V_660 )
{
struct V_1 * V_22 ;
void T_7 * V_690 = ( void T_7 * ) V_660 ;
int V_21 ;
V_22 = F_1 ( V_30 ) ;
switch ( V_254 ) {
case V_682 :
case V_683 :
case V_684 :
F_18 ( V_22 -> V_59 ) ;
return 0 ;
case V_672 :
return F_289 ( V_22 , V_690 ) ;
case V_680 :
return F_291 ( V_22 , V_690 ) ;
case V_669 :
if ( F_274 ( & V_22 -> V_718 ) < 0 )
return - V_719 ;
V_21 = F_292 ( V_22 , V_690 ) ;
F_51 ( & V_22 -> V_718 ) ;
return V_21 ;
case V_671 :
if ( F_274 ( & V_22 -> V_718 ) < 0 )
return - V_719 ;
V_21 = F_294 ( V_22 , V_690 ) ;
F_51 ( & V_22 -> V_718 ) ;
return V_21 ;
default:
return - V_720 ;
}
}
static void F_295 ( struct V_1 * V_22 , unsigned char * V_72 ,
T_1 V_367 )
{
struct V_8 * V_9 ;
V_9 = F_160 ( V_22 ) ;
( void ) F_161 ( V_9 , V_368 , V_22 , NULL , 0 , 0 ,
V_137 , V_369 ) ;
V_9 -> V_123 . V_124 [ 1 ] = V_367 ;
V_9 -> V_348 = NULL ;
F_56 ( V_22 , V_9 ) ;
return;
}
static int F_161 ( struct V_8 * V_9 , T_1 V_254 , struct V_1 * V_22 ,
void * V_703 , T_3 V_416 , T_6 V_721 , unsigned char * V_72 ,
int V_129 )
{
int V_722 = V_574 ;
T_5 V_317 ;
V_9 -> V_129 = V_372 ;
V_9 -> V_10 = V_635 ;
V_9 -> V_103 . V_107 = 0 ;
if ( V_703 != NULL && V_416 > 0 ) {
V_9 -> V_103 . V_104 = 1 ;
V_9 -> V_103 . V_250 = F_143 ( 1 ) ;
} else {
V_9 -> V_103 . V_104 = 0 ;
V_9 -> V_103 . V_250 = F_143 ( 0 ) ;
}
memcpy ( V_9 -> V_103 . V_318 . V_319 , V_72 , 8 ) ;
if ( V_129 == V_362 ) {
switch ( V_254 ) {
case V_361 :
if ( V_721 & V_378 ) {
V_9 -> V_123 . V_124 [ 1 ] = 0x01 ;
V_9 -> V_123 . V_124 [ 2 ] = ( V_721 & 0xff ) ;
}
V_9 -> V_123 . V_314 = 6 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_573 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_361 ;
V_9 -> V_123 . V_124 [ 4 ] = V_416 & 0xFF ;
break;
case V_409 :
case V_410 :
V_9 -> V_123 . V_314 = 12 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_573 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_254 ;
V_9 -> V_123 . V_124 [ 6 ] = ( V_416 >> 24 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 7 ] = ( V_416 >> 16 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 8 ] = ( V_416 >> 8 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 9 ] = V_416 & 0xFF ;
break;
case V_723 :
V_9 -> V_123 . V_314 = 12 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 ,
V_571 , V_572 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_121 ;
V_9 -> V_123 . V_124 [ 6 ] = V_724 ;
V_9 -> V_123 . V_124 [ 7 ] = ( V_416 >> 8 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 8 ] = V_416 & 0xFF ;
break;
case V_423 :
V_9 -> V_123 . V_314 = 6 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_574 ) ;
V_9 -> V_123 . V_569 = 0 ;
break;
case V_396 :
V_9 -> V_123 . V_314 = 12 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_573 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_725 ;
V_9 -> V_123 . V_124 [ 1 ] = V_254 ;
V_9 -> V_123 . V_124 [ 6 ] = ( V_416 >> 24 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 7 ] = ( V_416 >> 16 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 8 ] = ( V_416 >> 8 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 9 ] = V_416 & 0xFF ;
break;
case V_366 :
V_9 -> V_123 . V_314 = 10 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_573 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_726 ;
V_9 -> V_123 . V_124 [ 6 ] = V_366 ;
V_9 -> V_123 . V_124 [ 7 ] = ( V_416 >> 16 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 8 ] = ( V_416 >> 8 ) & 0xFF ;
break;
case V_399 :
V_9 -> V_123 . V_314 = 10 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_573 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_726 ;
V_9 -> V_123 . V_124 [ 6 ] = V_399 ;
V_9 -> V_123 . V_124 [ 7 ] = ( V_416 >> 16 ) & 0xFF ;
V_9 -> V_123 . V_124 [ 8 ] = ( V_416 >> 8 ) & 0XFF ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_190 , V_254 ) ;
F_166 () ;
return - 1 ;
}
} else if ( V_129 == V_369 ) {
switch ( V_254 ) {
case V_368 :
V_9 -> V_123 . V_314 = 16 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 , V_571 , V_574 ) ;
V_9 -> V_123 . V_569 = 0 ;
memset ( & V_9 -> V_123 . V_124 [ 0 ] , 0 , sizeof( V_9 -> V_123 . V_124 ) ) ;
V_9 -> V_123 . V_124 [ 0 ] = V_254 ;
V_9 -> V_123 . V_124 [ 1 ] = V_626 ;
V_9 -> V_123 . V_124 [ 4 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 5 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 6 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 7 ] = 0x00 ;
break;
case V_425 :
memcpy ( & V_317 , V_703 , sizeof( V_317 ) ) ;
F_264 ( & V_22 -> V_29 -> V_30 ,
L_191 ,
V_317 , V_9 -> V_103 . V_317 ) ;
V_9 -> V_123 . V_314 = 16 ;
V_9 -> V_123 . V_570 =
F_237 ( V_129 ,
V_571 , V_572 ) ;
V_9 -> V_123 . V_569 = 0 ;
V_9 -> V_123 . V_124 [ 0 ] = V_727 ;
V_9 -> V_123 . V_124 [ 1 ] = V_728 ;
V_9 -> V_123 . V_124 [ 2 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 3 ] = 0x00 ;
memcpy ( & V_9 -> V_123 . V_124 [ 4 ] , & V_317 , sizeof( V_317 ) ) ;
V_9 -> V_123 . V_124 [ 12 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 13 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 14 ] = 0x00 ;
V_9 -> V_123 . V_124 [ 15 ] = 0x00 ;
break;
default:
F_9 ( & V_22 -> V_29 -> V_30 , L_192 ,
V_254 ) ;
F_166 () ;
}
} else {
F_9 ( & V_22 -> V_29 -> V_30 , L_193 , V_129 ) ;
F_166 () ;
}
switch ( F_296 ( V_9 -> V_123 . V_570 ) ) {
case V_573 :
V_722 = V_364 ;
break;
case V_572 :
V_722 = V_240 ;
break;
case V_574 :
V_722 = V_344 ;
break;
default:
V_722 = V_707 ;
}
if ( F_145 ( V_22 -> V_29 , V_9 , V_703 , V_416 , V_722 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_297 ( T_15 V_729 , T_15 V_416 )
{
T_15 V_730 = ( ( T_15 ) V_729 ) & V_731 ;
T_15 V_732 = ( ( T_15 ) V_729 ) - V_730 ;
void T_14 * V_733 = F_298 ( V_730 ,
V_732 + V_416 ) ;
return V_733 ? ( V_733 + V_732 ) : NULL ;
}
static inline unsigned long F_299 ( struct V_1 * V_22 , T_1 V_89 )
{
return V_22 -> V_94 . V_95 ( V_22 , V_89 ) ;
}
static inline bool F_300 ( struct V_1 * V_22 )
{
return V_22 -> V_94 . V_734 ( V_22 ) ;
}
static inline long F_301 ( struct V_1 * V_22 )
{
return ( V_22 -> V_94 . V_734 ( V_22 ) == 0 ) ||
( V_22 -> V_735 == 0 ) ;
}
static inline int F_302 ( struct V_1 * V_22 , T_4 V_736 ,
T_4 V_737 )
{
if ( F_40 ( V_736 >= V_22 -> V_217 ) ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_194 , V_737 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_57 ( struct V_8 * V_9 )
{
F_52 ( V_9 -> V_22 , V_9 ) ;
if ( F_43 ( V_9 -> V_129 == V_130 || V_9 -> V_129 == V_308
|| V_9 -> V_129 == V_133 ) )
F_140 ( V_9 ) ;
else if ( V_9 -> V_129 == V_372 || V_9 -> V_129 == V_135 )
F_303 ( V_9 -> V_348 ) ;
}
static inline T_4 F_304 ( struct V_1 * V_22 , T_4 V_317 )
{
#define F_305 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_306 0x03
if ( F_40 ( ! ( V_22 -> V_63 & V_64 ) ) )
return V_317 & ~ F_306 ;
return V_317 & ~ F_305 ;
}
static inline void F_307 ( struct V_1 * V_22 ,
T_4 V_737 )
{
T_4 V_736 ;
struct V_8 * V_9 ;
V_736 = V_737 >> V_532 ;
if ( ! F_302 ( V_22 , V_736 , V_737 ) ) {
V_9 = V_22 -> V_376 + V_736 ;
F_57 ( V_9 ) ;
}
}
static int F_308 ( struct V_1 * V_22 )
{
if ( F_43 ( ! V_738 ) )
return 0 ;
if ( F_43 ( V_22 -> V_735 ) )
return 0 ;
F_90 ( & V_22 -> V_29 -> V_30 , L_195
L_196 ) ;
return 1 ;
}
static struct V_1 * F_309 ( T_1 * V_739 )
{
return F_242 ( ( V_739 - * V_739 ) , struct V_1 , V_89 [ 0 ] ) ;
}
static T_16 F_310 ( int V_606 , void * V_739 )
{
struct V_1 * V_22 = F_309 ( V_739 ) ;
T_1 V_89 = * ( T_1 * ) V_739 ;
T_4 V_737 ;
if ( F_308 ( V_22 ) )
return V_740 ;
if ( F_301 ( V_22 ) )
return V_740 ;
V_22 -> V_741 = F_311 () ;
while ( F_300 ( V_22 ) ) {
V_737 = F_299 ( V_22 , V_89 ) ;
while ( V_737 != V_99 )
V_737 = F_39 ( V_22 , V_89 ) ;
}
return V_742 ;
}
static T_16 F_312 ( int V_606 , void * V_739 )
{
struct V_1 * V_22 = F_309 ( V_739 ) ;
T_4 V_737 ;
T_1 V_89 = * ( T_1 * ) V_739 ;
if ( F_308 ( V_22 ) )
return V_740 ;
V_22 -> V_741 = F_311 () ;
V_737 = F_299 ( V_22 , V_89 ) ;
while ( V_737 != V_99 )
V_737 = F_39 ( V_22 , V_89 ) ;
return V_742 ;
}
static T_16 F_313 ( int V_606 , void * V_739 )
{
struct V_1 * V_22 = F_309 ( ( T_1 * ) V_739 ) ;
T_4 V_737 ;
T_1 V_89 = * ( T_1 * ) V_739 ;
if ( F_301 ( V_22 ) )
return V_740 ;
V_22 -> V_741 = F_311 () ;
while ( F_300 ( V_22 ) ) {
V_737 = F_299 ( V_22 , V_89 ) ;
while ( V_737 != V_99 ) {
F_307 ( V_22 , V_737 ) ;
V_737 = F_39 ( V_22 , V_89 ) ;
}
}
return V_742 ;
}
static T_16 F_314 ( int V_606 , void * V_739 )
{
struct V_1 * V_22 = F_309 ( V_739 ) ;
T_4 V_737 ;
T_1 V_89 = * ( T_1 * ) V_739 ;
V_22 -> V_741 = F_311 () ;
V_737 = F_299 ( V_22 , V_89 ) ;
while ( V_737 != V_99 ) {
F_307 ( V_22 , V_737 ) ;
V_737 = F_39 ( V_22 , V_89 ) ;
}
return V_742 ;
}
static int F_315 ( struct V_338 * V_29 , unsigned char V_743 ,
unsigned char type )
{
struct V_744 {
struct V_745 V_746 ;
struct V_747 V_123 ;
struct V_748 V_749 ;
};
struct V_744 * V_254 ;
static const T_3 V_750 = sizeof( * V_254 ) +
sizeof( V_254 -> V_749 ) ;
V_341 V_751 ;
V_436 V_752 ;
T_4 V_317 ;
void T_14 * V_131 ;
int V_68 , V_664 ;
V_131 = F_316 ( V_29 , 0 ) ;
if ( V_131 == NULL )
return - V_231 ;
V_664 = F_317 ( V_29 , F_318 ( 32 ) ) ;
if ( V_664 ) {
F_319 ( V_131 ) ;
return V_664 ;
}
V_254 = F_320 ( V_29 , V_750 , & V_751 ) ;
if ( V_254 == NULL ) {
F_319 ( V_131 ) ;
return - V_231 ;
}
V_752 = F_122 ( V_751 ) ;
V_254 -> V_746 . V_107 = 0 ;
V_254 -> V_746 . V_104 = 0 ;
V_254 -> V_746 . V_250 = F_143 ( 0 ) ;
V_254 -> V_746 . V_317 = F_117 ( V_751 ) ;
memset ( & V_254 -> V_746 . V_318 . V_319 , 0 , 8 ) ;
V_254 -> V_123 . V_314 = 16 ;
V_254 -> V_123 . V_570 =
F_237 ( V_369 , V_753 , V_574 ) ;
V_254 -> V_123 . V_569 = 0 ;
V_254 -> V_123 . V_124 [ 0 ] = V_743 ;
V_254 -> V_123 . V_124 [ 1 ] = type ;
memset ( & V_254 -> V_123 . V_124 [ 2 ] , 0 , 14 ) ;
V_254 -> V_749 . V_252 =
F_117 ( ( F_114 ( V_752 ) + sizeof( * V_254 ) ) ) ;
V_254 -> V_749 . V_251 = F_122 ( sizeof( struct V_305 ) ) ;
F_55 ( F_114 ( V_752 ) , V_131 + V_132 ) ;
for ( V_68 = 0 ; V_68 < V_754 ; V_68 ++ ) {
V_317 = F_321 ( V_131 + V_755 ) ;
if ( ( V_317 & ~ F_306 ) == V_751 )
break;
F_156 ( V_756 ) ;
}
F_319 ( V_131 ) ;
if ( V_68 == V_754 ) {
F_69 ( & V_29 -> V_30 , L_197 ,
V_743 , type ) ;
return - V_351 ;
}
F_322 ( V_29 , V_750 , V_254 , V_751 ) ;
if ( V_317 & V_757 ) {
F_69 ( & V_29 -> V_30 , L_198 ,
V_743 , type ) ;
return - V_356 ;
}
F_90 ( & V_29 -> V_30 , L_199 ,
V_743 , type ) ;
return 0 ;
}
static int F_323 ( struct V_338 * V_29 ,
void T_14 * V_131 , T_4 V_758 )
{
if ( V_758 ) {
F_90 ( & V_29 -> V_30 , L_200 ) ;
F_55 ( V_758 , V_131 + V_759 ) ;
F_156 ( 10000 ) ;
} else {
int V_21 = 0 ;
F_90 ( & V_29 -> V_30 , L_201 ) ;
V_21 = F_324 ( V_29 , V_760 ) ;
if ( V_21 )
return V_21 ;
F_156 ( 500 ) ;
V_21 = F_324 ( V_29 , V_761 ) ;
if ( V_21 )
return V_21 ;
F_156 ( 500 ) ;
}
return 0 ;
}
static void F_325 ( char * V_762 , int V_50 )
{
memset ( V_762 , 0 , V_50 ) ;
strncpy ( V_762 , V_41 L_202 V_701 , V_50 - 1 ) ;
}
static int F_326 ( struct V_763 T_14 * V_764 )
{
char * V_762 ;
int V_68 , V_416 = sizeof( V_764 -> V_762 ) ;
V_762 = F_87 ( V_416 , V_183 ) ;
if ( ! V_762 )
return - V_231 ;
F_325 ( V_762 , V_416 ) ;
for ( V_68 = 0 ; V_68 < V_416 ; V_68 ++ )
F_327 ( V_762 [ V_68 ] , & V_764 -> V_762 [ V_68 ] ) ;
F_76 ( V_762 ) ;
return 0 ;
}
static void F_328 ( struct V_763 T_14 * V_764 ,
unsigned char * V_765 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_764 -> V_762 ) ; V_68 ++ )
V_765 [ V_68 ] = F_329 ( & V_764 -> V_762 [ V_68 ] ) ;
}
static int F_330 ( struct V_763 T_14 * V_764 )
{
char * V_765 , * V_766 ;
int V_21 , V_416 = sizeof( V_764 -> V_762 ) ;
V_766 = F_87 ( 2 * V_416 , V_183 ) ;
if ( ! V_766 )
return - V_231 ;
V_765 = V_766 + V_416 ;
F_325 ( V_766 , V_416 ) ;
F_328 ( V_764 , V_765 ) ;
V_21 = ! memcmp ( V_765 , V_766 , V_416 ) ;
F_76 ( V_766 ) ;
return V_21 ;
}
static int F_331 ( struct V_338 * V_29 , T_4 V_67 )
{
T_5 V_767 ;
T_4 V_768 ;
T_5 V_769 ;
void T_14 * V_131 ;
unsigned long V_770 ;
T_4 V_771 ;
int V_21 ;
struct V_763 T_14 * V_764 ;
T_4 V_758 ;
T_6 V_772 ;
if ( ! F_28 ( V_67 ) ) {
F_9 ( & V_29 -> V_30 , L_203 ) ;
return - V_80 ;
}
if ( ! F_25 ( V_67 ) )
return - V_773 ;
F_332 ( V_29 , 4 , & V_772 ) ;
F_333 ( V_29 ) ;
V_21 = F_334 ( V_29 , & V_770 ) ;
if ( V_21 )
return V_21 ;
V_131 = F_297 ( V_770 , 0x250 ) ;
if ( ! V_131 )
return - V_231 ;
V_21 = F_335 ( V_29 , V_131 , & V_768 ,
& V_769 , & V_767 ) ;
if ( V_21 )
goto V_774;
V_764 = F_297 ( F_336 ( V_29 ,
V_769 ) + V_767 , sizeof( * V_764 ) ) ;
if ( ! V_764 ) {
V_21 = - V_231 ;
goto V_774;
}
V_21 = F_326 ( V_764 ) ;
if ( V_21 )
goto V_775;
V_771 = F_321 ( & V_764 -> V_771 ) ;
V_758 = V_771 & V_776 ;
if ( V_758 ) {
V_758 = V_777 ;
} else {
V_758 = V_771 & V_778 ;
if ( V_758 ) {
F_9 ( & V_29 -> V_30 ,
L_204 ) ;
V_21 = - V_773 ;
goto V_775;
}
}
V_21 = F_323 ( V_29 , V_131 , V_758 ) ;
if ( V_21 )
goto V_775;
F_337 ( V_29 ) ;
F_338 ( V_29 , 4 , V_772 ) ;
F_156 ( V_779 ) ;
V_21 = F_339 ( V_29 , V_131 , V_780 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 ,
L_205 ) ;
goto V_775;
}
V_21 = F_330 ( V_131 ) ;
if ( V_21 < 0 )
goto V_775;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_206
L_207 ) ;
V_21 = - V_773 ;
} else {
F_90 ( & V_29 -> V_30 , L_208 ) ;
}
V_775:
F_319 ( V_764 ) ;
V_774:
F_319 ( V_131 ) ;
return V_21 ;
}
static void F_340 ( struct V_42 * V_30 , struct V_763 T_14 * V_781 )
{
#ifdef F_341
int V_68 ;
char V_782 [ 17 ] ;
F_90 ( V_30 , L_209 ) ;
F_90 ( V_30 , L_210 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ )
V_782 [ V_68 ] = F_329 ( & ( V_781 -> V_783 [ V_68 ] ) ) ;
V_782 [ 4 ] = '\0' ;
F_90 ( V_30 , L_211 , V_782 ) ;
F_90 ( V_30 , L_212 , F_321 ( & ( V_781 -> V_784 ) ) ) ;
F_90 ( V_30 , L_213 ,
F_321 ( & ( V_781 -> V_785 ) ) ) ;
F_90 ( V_30 , L_214 ,
F_321 ( & ( V_781 -> V_786 ) ) ) ;
F_90 ( V_30 , L_215 ,
F_321 ( & ( V_781 -> V_787 . V_788 ) ) ) ;
F_90 ( V_30 , L_216 ,
F_321 ( & ( V_781 -> V_787 . V_789 ) ) ) ;
F_90 ( V_30 , L_217 ,
F_321 ( & ( V_781 -> V_787 . V_790 ) ) ) ;
F_90 ( V_30 , L_218 ,
F_321 ( & ( V_781 -> V_791 ) ) ) ;
F_90 ( V_30 , L_219 , F_321 ( & ( V_781 -> V_792 ) ) ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ )
V_782 [ V_68 ] = F_329 ( & ( V_781 -> V_793 [ V_68 ] ) ) ;
V_782 [ 16 ] = '\0' ;
F_90 ( V_30 , L_220 , V_782 ) ;
F_90 ( V_30 , L_221 ,
F_321 ( & ( V_781 -> V_794 ) ) ) ;
#endif
}
static int F_342 ( struct V_338 * V_29 , unsigned long V_795 )
{
int V_68 , V_658 , V_796 , V_797 ;
if ( V_795 == V_798 )
return 0 ;
V_658 = 0 ;
for ( V_68 = 0 ; V_68 < V_799 ; V_68 ++ ) {
V_797 = F_343 ( V_29 , V_68 ) & V_800 ;
if ( V_797 == V_801 )
V_658 += 4 ;
else {
V_796 = F_343 ( V_29 , V_68 ) &
V_802 ;
switch ( V_796 ) {
case V_803 :
case V_804 :
V_658 += 4 ;
break;
case V_805 :
V_658 += 8 ;
break;
default:
F_9 ( & V_29 -> V_30 ,
L_222 ) ;
return - 1 ;
break;
}
}
if ( V_658 == V_795 - V_798 )
return V_68 + 1 ;
}
return - 1 ;
}
static void F_344 ( struct V_1 * V_22 )
{
if ( V_22 -> V_105 ) {
if ( V_22 -> V_29 -> V_806 )
F_345 ( V_22 -> V_29 ) ;
V_22 -> V_105 = 0 ;
} else if ( V_22 -> V_807 ) {
if ( V_22 -> V_29 -> V_808 )
F_346 ( V_22 -> V_29 ) ;
V_22 -> V_807 = 0 ;
}
}
static void F_347 ( struct V_1 * V_22 )
{
#ifdef F_348
int V_664 , V_68 ;
struct V_809 V_810 [ V_811 ] ;
for ( V_68 = 0 ; V_68 < V_811 ; V_68 ++ ) {
V_810 [ V_68 ] . V_812 = 0 ;
V_810 [ V_68 ] . V_164 = V_68 ;
}
if ( ( V_22 -> V_67 == 0x40700E11 ) || ( V_22 -> V_67 == 0x40800E11 ) ||
( V_22 -> V_67 == 0x40820E11 ) || ( V_22 -> V_67 == 0x40830E11 ) )
goto V_813;
if ( F_349 ( V_22 -> V_29 , V_814 ) ) {
F_90 ( & V_22 -> V_29 -> V_30 , L_223 ) ;
V_22 -> V_105 = V_811 ;
if ( V_22 -> V_105 > F_350 () )
V_22 -> V_105 = F_350 () ;
V_664 = F_351 ( V_22 -> V_29 , V_810 ,
1 , V_22 -> V_105 ) ;
if ( V_664 < 0 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_224 , V_664 ) ;
V_22 -> V_105 = 0 ;
goto V_815;
} else if ( V_664 < V_22 -> V_105 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_225
L_226 , V_664 ) ;
}
V_22 -> V_105 = V_664 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_105 ; V_68 ++ )
V_22 -> V_607 [ V_68 ] = V_810 [ V_68 ] . V_812 ;
return;
}
V_815:
if ( F_349 ( V_22 -> V_29 , V_816 ) ) {
F_90 ( & V_22 -> V_29 -> V_30 , L_227 ) ;
if ( ! F_352 ( V_22 -> V_29 ) )
V_22 -> V_807 = 1 ;
else
F_9 ( & V_22 -> V_29 -> V_30 , L_228 ) ;
}
V_813:
#endif
V_22 -> V_607 [ V_22 -> V_608 ] = V_22 -> V_29 -> V_606 ;
}
static int F_353 ( struct V_338 * V_29 , T_4 * V_67 )
{
int V_68 ;
T_4 V_817 , V_818 ;
V_817 = V_29 -> V_819 ;
V_818 = V_29 -> V_820 ;
* V_67 = ( ( V_818 << 16 ) & 0xffff0000 ) |
V_817 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_821 ) ; V_68 ++ )
if ( * V_67 == V_821 [ V_68 ] . V_67 )
return V_68 ;
if ( ( V_817 != V_822 &&
V_817 != V_823 ) ||
! V_824 ) {
F_9 ( & V_29 -> V_30 , L_229
L_230 , * V_67 ) ;
return - V_80 ;
}
return F_26 ( V_821 ) - 1 ;
}
static int F_334 ( struct V_338 * V_29 ,
unsigned long * V_825 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_799 ; V_68 ++ )
if ( F_343 ( V_29 , V_68 ) & V_826 ) {
* V_825 = F_336 ( V_29 , V_68 ) ;
F_264 ( & V_29 -> V_30 , L_231 ,
* V_825 ) ;
return 0 ;
}
F_9 ( & V_29 -> V_30 , L_232 ) ;
return - V_80 ;
}
static int F_339 ( struct V_338 * V_29 , void T_14 * V_131 ,
int V_827 )
{
int V_68 , V_828 ;
T_4 V_829 ;
if ( V_827 )
V_828 = V_830 ;
else
V_828 = V_831 ;
for ( V_68 = 0 ; V_68 < V_828 ; V_68 ++ ) {
V_829 = F_321 ( V_131 + V_832 ) ;
if ( V_827 ) {
if ( V_829 == V_833 )
return 0 ;
} else {
if ( V_829 != V_833 )
return 0 ;
}
F_156 ( V_834 ) ;
}
F_9 ( & V_29 -> V_30 , L_233 ) ;
return - V_80 ;
}
static int F_335 ( struct V_338 * V_29 , void T_14 * V_131 ,
T_4 * V_768 , T_5 * V_769 ,
T_5 * V_767 )
{
* V_768 = F_321 ( V_131 + V_835 ) ;
* V_767 = F_321 ( V_131 + V_836 ) ;
* V_768 &= ( T_4 ) 0x0000ffff ;
* V_769 = F_342 ( V_29 , * V_768 ) ;
if ( * V_769 == - 1 ) {
F_9 ( & V_29 -> V_30 , L_234 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_354 ( struct V_1 * V_22 )
{
if ( V_22 -> V_837 ) {
F_319 ( V_22 -> V_837 ) ;
V_22 -> V_837 = NULL ;
}
if ( V_22 -> V_764 ) {
F_319 ( V_22 -> V_764 ) ;
V_22 -> V_764 = NULL ;
}
}
static int F_355 ( struct V_1 * V_22 )
{
T_5 V_767 ;
T_4 V_768 ;
T_5 V_769 ;
T_4 V_838 ;
int V_21 ;
V_21 = F_335 ( V_22 -> V_29 , V_22 -> V_131 , & V_768 ,
& V_769 , & V_767 ) ;
if ( V_21 )
return V_21 ;
V_22 -> V_764 = F_297 ( F_336 ( V_22 -> V_29 ,
V_769 ) + V_767 , sizeof( * V_22 -> V_764 ) ) ;
if ( ! V_22 -> V_764 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_235 ) ;
return - V_231 ;
}
V_21 = F_326 ( V_22 -> V_764 ) ;
if ( V_21 )
return V_21 ;
V_838 = F_321 ( & V_22 -> V_764 -> V_839 ) ;
V_22 -> V_837 = F_297 ( F_336 ( V_22 -> V_29 ,
V_769 ) + V_767 + V_838 ,
sizeof( * V_22 -> V_837 ) ) ;
if ( ! V_22 -> V_837 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_236 ) ;
F_354 ( V_22 ) ;
return - V_231 ;
}
return 0 ;
}
static void F_356 ( struct V_1 * V_22 )
{
#define F_357 16
F_266 ( F_357 <= V_603 ) ;
V_22 -> V_100 = F_321 ( & V_22 -> V_764 -> V_840 ) ;
if ( V_738 && V_22 -> V_100 > 32 )
V_22 -> V_100 = 32 ;
if ( V_22 -> V_100 < F_357 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_237 ,
V_22 -> V_100 ,
F_357 ) ;
V_22 -> V_100 = F_357 ;
}
}
static int F_358 ( struct V_1 * V_22 )
{
return V_22 -> V_232 > 512 ;
}
static void F_359 ( struct V_1 * V_22 )
{
F_356 ( V_22 ) ;
V_22 -> V_217 = V_22 -> V_100 ;
V_22 -> V_232 = F_321 ( & ( V_22 -> V_764 -> V_841 ) ) ;
V_22 -> V_430 = F_321 ( & ( V_22 -> V_764 -> V_771 ) ) ;
if ( F_358 ( V_22 ) ) {
V_22 -> V_247 = 32 ;
V_22 -> V_230 = V_22 -> V_232 - V_22 -> V_247 ;
V_22 -> V_232 -- ;
} else {
V_22 -> V_247 = 31 ;
V_22 -> V_232 = 31 ;
V_22 -> V_230 = 0 ;
}
V_22 -> V_647 = F_321 ( & ( V_22 -> V_764 -> V_647 ) ) ;
if ( ! ( V_653 & V_22 -> V_647 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_238 ) ;
if ( ! ( V_654 & V_22 -> V_647 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_239 ) ;
if ( ! ( V_646 & V_22 -> V_647 ) )
F_9 ( & V_22 -> V_29 -> V_30 , L_240 ) ;
}
static inline bool F_360 ( struct V_1 * V_22 )
{
if ( ! F_361 ( V_22 -> V_764 -> V_783 , L_241 , 4 ) ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_242 ) ;
return false ;
}
return true ;
}
static inline void F_362 ( struct V_1 * V_22 )
{
T_4 V_842 ;
V_842 = F_321 ( & ( V_22 -> V_764 -> V_842 ) ) ;
#ifdef F_363
V_842 |= V_843 ;
#endif
V_842 |= V_844 ;
F_55 ( V_842 , & ( V_22 -> V_764 -> V_842 ) ) ;
}
static inline void F_364 ( struct V_1 * V_22 )
{
T_4 V_845 ;
if ( V_22 -> V_67 != 0x3225103C )
return;
V_845 = F_321 ( V_22 -> V_131 + V_846 ) ;
V_845 |= 0x8000 ;
F_55 ( V_845 , V_22 -> V_131 + V_846 ) ;
}
static int F_365 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_847 ;
unsigned long V_77 ;
for ( V_68 = 0 ; V_68 < V_848 ; V_68 ++ ) {
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_847 = F_321 ( V_22 -> V_131 + V_759 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( ! ( V_847 & V_849 ) )
goto V_850;
F_156 ( V_851 ) ;
}
return - V_80 ;
V_850:
return 0 ;
}
static int F_366 ( struct V_1 * V_22 )
{
int V_68 ;
T_4 V_847 ;
unsigned long V_77 ;
for ( V_68 = 0 ; V_68 < V_852 ; V_68 ++ ) {
if ( V_22 -> V_853 )
goto V_850;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_847 = F_321 ( V_22 -> V_131 + V_759 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( ! ( V_847 & V_854 ) )
goto V_850;
F_156 ( V_855 ) ;
}
return - V_80 ;
V_850:
return 0 ;
}
static int F_367 ( struct V_1 * V_22 )
{
T_4 V_856 ;
V_856 = F_321 ( & ( V_22 -> V_764 -> V_785 ) ) ;
if ( ! ( V_856 & V_857 ) )
return - V_773 ;
V_22 -> V_100 = F_321 ( & ( V_22 -> V_764 -> V_791 ) ) ;
F_55 ( V_858 , & ( V_22 -> V_764 -> V_787 . V_788 ) ) ;
F_55 ( 0 , & V_22 -> V_764 -> V_787 . V_859 ) ;
F_55 ( V_854 , V_22 -> V_131 + V_759 ) ;
if ( F_366 ( V_22 ) )
goto error;
F_340 ( & V_22 -> V_29 -> V_30 , V_22 -> V_764 ) ;
if ( ! ( F_321 ( & ( V_22 -> V_764 -> V_786 ) ) & V_858 ) )
goto error;
V_22 -> V_63 = V_858 ;
return 0 ;
error:
F_69 ( & V_22 -> V_29 -> V_30 , L_243 ) ;
return - V_80 ;
}
static void F_368 ( struct V_1 * V_22 )
{
F_354 ( V_22 ) ;
F_319 ( V_22 -> V_131 ) ;
V_22 -> V_131 = NULL ;
F_344 ( V_22 ) ;
F_369 ( V_22 -> V_29 ) ;
F_370 ( V_22 -> V_29 ) ;
}
static int F_371 ( struct V_1 * V_22 )
{
int V_860 , V_664 ;
V_860 = F_353 ( V_22 -> V_29 , & V_22 -> V_67 ) ;
if ( V_860 < 0 )
return V_860 ;
V_22 -> V_861 = V_821 [ V_860 ] . V_861 ;
V_22 -> V_94 = * ( V_821 [ V_860 ] . V_94 ) ;
V_22 -> V_71 =
F_29 ( V_22 -> V_67 ) ;
F_372 ( V_22 -> V_29 , V_862 |
V_863 | V_864 ) ;
V_664 = F_373 ( V_22 -> V_29 ) ;
if ( V_664 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_244 ) ;
F_369 ( V_22 -> V_29 ) ;
return V_664 ;
}
V_664 = F_374 ( V_22 -> V_29 , V_41 ) ;
if ( V_664 ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_245 ) ;
F_369 ( V_22 -> V_29 ) ;
return V_664 ;
}
F_375 ( V_22 -> V_29 ) ;
F_347 ( V_22 ) ;
V_664 = F_334 ( V_22 -> V_29 , & V_22 -> V_770 ) ;
if ( V_664 )
goto V_865;
V_22 -> V_131 = F_297 ( V_22 -> V_770 , 0x250 ) ;
if ( ! V_22 -> V_131 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_246 ) ;
V_664 = - V_231 ;
goto V_865;
}
V_664 = F_339 ( V_22 -> V_29 , V_22 -> V_131 , V_780 ) ;
if ( V_664 )
goto V_866;
V_664 = F_355 ( V_22 ) ;
if ( V_664 )
goto V_866;
F_359 ( V_22 ) ;
if ( ! F_360 ( V_22 ) ) {
V_664 = - V_80 ;
goto V_867;
}
F_362 ( V_22 ) ;
F_364 ( V_22 ) ;
V_664 = F_367 ( V_22 ) ;
if ( V_664 )
goto V_867;
return 0 ;
V_867:
F_354 ( V_22 ) ;
V_866:
F_319 ( V_22 -> V_131 ) ;
V_22 -> V_131 = NULL ;
V_865:
F_344 ( V_22 ) ;
F_369 ( V_22 -> V_29 ) ;
F_370 ( V_22 -> V_29 ) ;
return V_664 ;
}
static void F_376 ( struct V_1 * V_22 )
{
int V_21 ;
#define F_377 64
V_22 -> V_61 = F_87 ( F_377 , V_183 ) ;
if ( ! V_22 -> V_61 )
return;
V_21 = F_159 ( V_22 , V_137 , 0 ,
V_22 -> V_61 , F_377 ) ;
if ( V_21 != 0 ) {
F_76 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
}
}
static int F_378 ( struct V_338 * V_29 , T_4 V_67 )
{
int V_21 , V_68 ;
void T_14 * V_131 ;
if ( ! V_738 )
return 0 ;
V_21 = F_373 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_247 ) ;
return - V_80 ;
}
F_369 ( V_29 ) ;
F_156 ( 260 ) ;
V_21 = F_373 ( V_29 ) ;
if ( V_21 ) {
F_9 ( & V_29 -> V_30 , L_248 ) ;
return - V_80 ;
}
F_375 ( V_29 ) ;
V_131 = F_316 ( V_29 , 0 ) ;
if ( V_131 == NULL ) {
V_21 = - V_231 ;
goto V_868;
}
F_55 ( V_869 , V_131 + V_870 ) ;
F_319 ( V_131 ) ;
V_21 = F_331 ( V_29 , V_67 ) ;
if ( V_21 )
goto V_868;
F_90 ( & V_29 -> V_30 , L_249 ) ;
for ( V_68 = 0 ; V_68 < V_871 ; V_68 ++ ) {
if ( F_379 ( V_29 ) == 0 )
break;
else
F_9 ( & V_29 -> V_30 , L_250 ,
( V_68 < 11 ? L_251 : L_252 ) ) ;
}
V_868:
F_369 ( V_29 ) ;
return V_21 ;
}
static void F_380 ( struct V_1 * V_22 )
{
F_76 ( V_22 -> V_659 ) ;
V_22 -> V_659 = NULL ;
if ( V_22 -> V_376 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( struct V_8 ) ,
V_22 -> V_376 ,
V_22 -> V_580 ) ;
V_22 -> V_376 = NULL ;
V_22 -> V_580 = 0 ;
}
if ( V_22 -> V_581 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( struct V_305 ) ,
V_22 -> V_581 ,
V_22 -> V_582 ) ;
V_22 -> V_581 = NULL ;
V_22 -> V_582 = 0 ;
}
}
static int F_381 ( struct V_1 * V_22 )
{
V_22 -> V_659 = F_96 (
F_382 ( V_22 -> V_217 , V_561 ) *
sizeof( unsigned long ) , V_183 ) ;
V_22 -> V_376 = F_320 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_376 ) ,
& ( V_22 -> V_580 ) ) ;
V_22 -> V_581 = F_320 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_581 ) ,
& ( V_22 -> V_582 ) ) ;
if ( ( V_22 -> V_659 == NULL )
|| ( V_22 -> V_376 == NULL )
|| ( V_22 -> V_581 == NULL ) ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_253 , V_184 ) ;
goto V_872;
}
F_239 ( V_22 ) ;
return 0 ;
V_872:
F_380 ( V_22 ) ;
return - V_231 ;
}
static void F_383 ( struct V_1 * V_22 )
{
int V_68 , V_352 ;
V_352 = F_384 ( V_873 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_105 ; V_68 ++ ) {
F_385 ( V_22 -> V_607 [ V_68 ] , F_386 ( V_352 ) ) ;
V_352 = F_387 ( V_352 , V_873 ) ;
}
}
static void F_388 ( struct V_1 * V_22 )
{
int V_68 ;
if ( ! V_22 -> V_105 || V_22 -> V_608 != V_874 ) {
V_68 = V_22 -> V_608 ;
F_385 ( V_22 -> V_607 [ V_68 ] , NULL ) ;
F_389 ( V_22 -> V_607 [ V_68 ] , & V_22 -> V_89 [ V_68 ] ) ;
V_22 -> V_89 [ V_68 ] = 0 ;
return;
}
for ( V_68 = 0 ; V_68 < V_22 -> V_105 ; V_68 ++ ) {
F_385 ( V_22 -> V_607 [ V_68 ] , NULL ) ;
F_389 ( V_22 -> V_607 [ V_68 ] , & V_22 -> V_89 [ V_68 ] ) ;
V_22 -> V_89 [ V_68 ] = 0 ;
}
for (; V_68 < V_811 ; V_68 ++ )
V_22 -> V_89 [ V_68 ] = 0 ;
}
static int F_390 ( struct V_1 * V_22 ,
T_16 (* F_391)( int , void * ) ,
T_16 (* F_392)( int , void * ) )
{
int V_21 , V_68 ;
for ( V_68 = 0 ; V_68 < V_811 ; V_68 ++ )
V_22 -> V_89 [ V_68 ] = ( T_1 ) V_68 ;
if ( V_22 -> V_608 == V_874 && V_22 -> V_105 > 0 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_105 ; V_68 ++ ) {
sprintf ( V_22 -> V_875 [ V_68 ] , L_254 , V_22 -> V_31 , V_68 ) ;
V_21 = F_393 ( V_22 -> V_607 [ V_68 ] , F_391 ,
0 , V_22 -> V_875 [ V_68 ] ,
& V_22 -> V_89 [ V_68 ] ) ;
if ( V_21 ) {
int V_173 ;
F_69 ( & V_22 -> V_29 -> V_30 ,
L_255 ,
V_22 -> V_607 [ V_68 ] , V_22 -> V_31 ) ;
for ( V_173 = 0 ; V_173 < V_68 ; V_173 ++ ) {
F_389 ( V_22 -> V_607 [ V_173 ] , & V_22 -> V_89 [ V_173 ] ) ;
V_22 -> V_89 [ V_173 ] = 0 ;
}
for (; V_173 < V_811 ; V_173 ++ )
V_22 -> V_89 [ V_173 ] = 0 ;
return V_21 ;
}
}
F_383 ( V_22 ) ;
} else {
if ( V_22 -> V_105 > 0 || V_22 -> V_807 ) {
if ( V_22 -> V_105 )
sprintf ( V_22 -> V_875 [ V_22 -> V_608 ] ,
L_256 , V_22 -> V_31 ) ;
else
sprintf ( V_22 -> V_875 [ V_22 -> V_608 ] ,
L_257 , V_22 -> V_31 ) ;
V_21 = F_393 ( V_22 -> V_607 [ V_22 -> V_608 ] ,
F_391 , 0 ,
V_22 -> V_875 [ V_22 -> V_608 ] ,
& V_22 -> V_89 [ V_22 -> V_608 ] ) ;
} else {
sprintf ( V_22 -> V_875 [ V_22 -> V_608 ] ,
L_258 , V_22 -> V_31 ) ;
V_21 = F_393 ( V_22 -> V_607 [ V_22 -> V_608 ] ,
F_392 , V_876 ,
V_22 -> V_875 [ V_22 -> V_608 ] ,
& V_22 -> V_89 [ V_22 -> V_608 ] ) ;
}
F_385 ( V_22 -> V_607 [ V_22 -> V_608 ] , NULL ) ;
}
if ( V_21 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_255 ,
V_22 -> V_607 [ V_22 -> V_608 ] , V_22 -> V_31 ) ;
F_388 ( V_22 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_394 ( struct V_1 * V_22 )
{
int V_21 ;
F_295 ( V_22 , V_137 , V_877 ) ;
F_90 ( & V_22 -> V_29 -> V_30 , L_259 ) ;
V_21 = F_339 ( V_22 -> V_29 , V_22 -> V_131 , V_878 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_260 ) ;
return V_21 ;
}
F_90 ( & V_22 -> V_29 -> V_30 , L_261 ) ;
V_21 = F_339 ( V_22 -> V_29 , V_22 -> V_131 , V_780 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 , L_262
L_263 ) ;
return V_21 ;
}
return 0 ;
}
static void F_395 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ ) {
if ( ! V_22 -> V_92 [ V_68 ] . V_96 )
continue;
F_322 ( V_22 -> V_29 ,
V_22 -> V_879 ,
V_22 -> V_92 [ V_68 ] . V_96 ,
V_22 -> V_92 [ V_68 ] . V_101 ) ;
V_22 -> V_92 [ V_68 ] . V_96 = NULL ;
V_22 -> V_92 [ V_68 ] . V_101 = 0 ;
}
V_22 -> V_879 = 0 ;
}
static void F_396 ( struct V_1 * V_22 )
{
F_397 ( V_22 ) ;
F_111 ( V_22 ) ;
F_380 ( V_22 ) ;
F_388 ( V_22 ) ;
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_368 ( V_22 ) ;
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
if ( V_22 -> V_295 ) {
F_399 ( V_22 -> V_295 ) ;
V_22 -> V_295 = NULL ;
}
if ( V_22 -> V_880 ) {
F_399 ( V_22 -> V_880 ) ;
V_22 -> V_880 = NULL ;
}
F_76 ( V_22 ) ;
}
static void F_400 ( struct V_1 * V_22 )
{
int V_68 , V_377 ;
struct V_8 * V_9 ;
int V_881 = 0 ;
F_401 ( V_22 -> V_295 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
V_9 = V_22 -> V_376 + V_68 ;
V_377 = F_169 ( & V_9 -> V_377 ) ;
if ( V_377 > 1 ) {
V_9 -> V_24 -> V_36 = V_311 ;
F_57 ( V_9 ) ;
F_41 ( & V_22 -> V_62 ) ;
V_881 ++ ;
}
F_162 ( V_22 , V_9 ) ;
}
F_9 ( & V_22 -> V_29 -> V_30 ,
L_264 , V_881 ) ;
}
static void F_402 ( struct V_1 * V_22 , T_4 V_882 )
{
int V_352 ;
F_403 (cpu) {
T_4 * F_13 ;
F_13 = F_153 ( V_22 -> F_13 , V_352 ) ;
* F_13 = V_882 ;
}
F_72 () ;
}
static void F_404 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
T_4 F_13 ;
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
F_13 = F_321 ( V_22 -> V_131 + V_832 ) ;
if ( ! F_13 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_265 ,
V_22 -> V_126 / V_885 ) ;
F_13 = 0xffffffff ;
}
F_402 ( V_22 , F_13 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_9 ( & V_22 -> V_29 -> V_30 , L_266 ,
F_13 , V_22 -> V_126 / V_885 ) ;
F_369 ( V_22 -> V_29 ) ;
F_400 ( V_22 ) ;
}
static int F_260 ( struct V_1 * V_22 )
{
T_5 V_886 ;
T_4 V_887 ;
unsigned long V_77 ;
V_886 = F_311 () ;
if ( F_405 ( V_22 -> V_741 +
( V_22 -> V_126 ) , V_886 ) )
return false ;
if ( F_405 ( V_22 -> V_888 +
( V_22 -> V_126 ) , V_886 ) )
return false ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_887 = F_321 ( & V_22 -> V_764 -> V_794 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
if ( V_22 -> V_889 == V_887 ) {
F_404 ( V_22 ) ;
return true ;
}
V_22 -> V_889 = V_887 ;
V_22 -> V_888 = V_886 ;
return false ;
}
static void F_406 ( struct V_1 * V_22 )
{
int V_68 ;
char * V_890 ;
if ( ! ( V_22 -> V_430 & V_891 ) )
return;
if ( ( V_22 -> V_63 & ( V_93
| V_472 ) ) &&
( V_22 -> V_892 & V_893 ||
V_22 -> V_892 & V_894 ) ) {
if ( V_22 -> V_892 & V_893 )
V_890 = L_267 ;
if ( V_22 -> V_892 & V_894 )
V_890 = L_268 ;
F_407 ( V_22 -> V_59 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ )
V_22 -> V_30 [ V_68 ] -> V_88 = 0 ;
F_408 ( V_22 ) ;
F_9 ( & V_22 -> V_29 -> V_30 ,
L_269 ,
V_22 -> V_892 , V_890 ) ;
F_55 ( V_22 -> V_892 , & ( V_22 -> V_764 -> V_895 ) ) ;
F_55 ( V_849 , V_22 -> V_131 + V_759 ) ;
F_365 ( V_22 ) ;
F_409 ( V_22 -> V_59 ) ;
} else {
F_55 ( V_22 -> V_892 , & ( V_22 -> V_764 -> V_895 ) ) ;
F_55 ( V_849 , V_22 -> V_131 + V_759 ) ;
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
if ( ! ( V_22 -> V_430 & V_891 ) )
return 0 ;
V_22 -> V_892 = F_321 ( & ( V_22 -> V_764 -> V_896 ) ) ;
return V_22 -> V_892 & V_897 ;
}
static int F_411 ( struct V_1 * V_22 )
{
unsigned long V_77 ;
struct V_181 * V_358 ;
struct V_898 * V_899 , * V_900 ;
F_34 ( & V_22 -> V_182 , V_77 ) ;
F_412 (this, tmp, &h->offline_device_list) {
V_358 = F_413 ( V_899 , struct V_181 ,
V_185 ) ;
F_35 ( & V_22 -> V_182 , V_77 ) ;
if ( ! F_187 ( V_22 , V_358 -> V_72 ) ) {
F_34 ( & V_22 -> V_182 , V_77 ) ;
F_414 ( & V_358 -> V_185 ) ;
F_35 ( & V_22 -> V_182 , V_77 ) ;
return 1 ;
}
F_34 ( & V_22 -> V_182 , V_77 ) ;
}
F_35 ( & V_22 -> V_182 , V_77 ) ;
return 0 ;
}
static void F_415 ( struct V_584 * V_293 )
{
unsigned long V_77 ;
struct V_1 * V_22 = F_242 ( F_416 ( V_293 ) ,
struct V_1 , V_901 ) ;
if ( V_22 -> V_853 )
return;
if ( F_410 ( V_22 ) || F_411 ( V_22 ) ) {
F_417 ( V_22 -> V_59 ) ;
F_406 ( V_22 ) ;
F_18 ( V_22 -> V_59 ) ;
F_251 ( V_22 -> V_59 ) ;
}
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! V_22 -> V_853 )
F_418 ( V_22 -> V_880 , & V_22 -> V_901 ,
V_22 -> V_126 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
static void F_419 ( struct V_584 * V_293 )
{
unsigned long V_77 ;
struct V_1 * V_22 = F_242 ( F_416 ( V_293 ) ,
struct V_1 , V_902 ) ;
F_260 ( V_22 ) ;
if ( F_13 ( V_22 ) )
return;
F_34 ( & V_22 -> V_78 , V_77 ) ;
if ( ! V_22 -> V_853 )
F_420 ( & V_22 -> V_902 ,
V_22 -> V_126 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
}
static struct V_903 * F_421 ( struct V_1 * V_22 ,
char * V_904 )
{
struct V_903 * V_905 = NULL ;
V_905 = F_422 ( L_270 , 0 , V_904 , V_22 -> V_610 ) ;
if ( ! V_905 )
F_69 ( & V_22 -> V_29 -> V_30 , L_271 , V_904 ) ;
return V_905 ;
}
static int F_423 ( struct V_338 * V_29 , const struct V_906 * V_907 )
{
int V_908 , V_21 ;
struct V_1 * V_22 ;
int V_909 = 0 ;
unsigned long V_77 ;
T_4 V_67 ;
if ( V_910 == 0 )
F_424 (KERN_INFO DRIVER_NAME L_272 ) ;
V_21 = F_353 ( V_29 , & V_67 ) ;
if ( V_21 < 0 ) {
F_9 ( & V_29 -> V_30 , L_273 ) ;
return V_21 ;
}
V_21 = F_378 ( V_29 , V_67 ) ;
if ( V_21 ) {
if ( V_21 != - V_773 )
return V_21 ;
V_909 = 1 ;
V_21 = 0 ;
}
V_911:
F_266 ( sizeof( struct V_8 ) % V_912 ) ;
V_22 = F_96 ( sizeof( * V_22 ) , V_183 ) ;
if ( ! V_22 ) {
F_69 ( & V_29 -> V_30 , L_274 ) ;
return - V_231 ;
}
V_22 -> V_29 = V_29 ;
V_22 -> V_608 = V_913 ? V_914 : V_874 ;
F_425 ( & V_22 -> V_186 ) ;
F_426 ( & V_22 -> V_78 ) ;
F_426 ( & V_22 -> V_182 ) ;
F_426 ( & V_22 -> V_589 ) ;
F_105 ( & V_22 -> V_718 , V_915 ) ;
F_105 ( & V_22 -> V_649 , V_916 ) ;
V_22 -> F_13 = F_427 ( T_4 ) ;
if ( ! V_22 -> F_13 ) {
F_69 ( & V_22 -> V_29 -> V_30 , L_275 ) ;
V_21 = - V_231 ;
goto V_917;
}
F_402 ( V_22 , 0 ) ;
V_21 = F_371 ( V_22 ) ;
if ( V_21 )
goto V_865;
V_21 = F_248 ( V_22 ) ;
if ( V_21 )
goto V_918;
sprintf ( V_22 -> V_31 , V_41 L_9 , V_22 -> V_59 -> V_147 ) ;
V_22 -> V_610 = V_910 ;
V_910 ++ ;
V_21 = F_428 ( V_29 , F_318 ( 64 ) ) ;
if ( V_21 == 0 ) {
V_908 = 1 ;
} else {
V_21 = F_428 ( V_29 , F_318 ( 32 ) ) ;
if ( V_21 == 0 ) {
V_908 = 0 ;
} else {
F_69 ( & V_29 -> V_30 , L_276 ) ;
goto V_866;
}
}
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
V_21 = F_390 ( V_22 , F_314 , F_313 ) ;
if ( V_21 )
goto V_866;
V_21 = F_381 ( V_22 ) ;
if ( V_21 )
goto V_867;
V_21 = F_112 ( V_22 ) ;
if ( V_21 )
goto V_919;
F_429 ( & V_22 -> V_591 ) ;
F_429 ( & V_22 -> V_648 ) ;
F_429 ( & V_22 -> V_291 ) ;
F_430 ( & V_22 -> V_374 ) ;
V_22 -> V_590 = 1 ;
F_431 ( V_29 , V_22 ) ;
V_22 -> V_144 = 0 ;
V_22 -> V_456 = 0 ;
F_426 ( & V_22 -> V_223 ) ;
V_21 = F_432 ( V_22 ) ;
if ( V_21 )
goto V_920;
V_21 = F_252 ( V_22 ) ;
if ( V_21 )
goto V_921;
V_22 -> V_880 = F_421 ( V_22 , L_277 ) ;
if ( ! V_22 -> V_880 ) {
V_21 = - V_231 ;
goto V_921;
}
V_22 -> V_295 = F_421 ( V_22 , L_278 ) ;
if ( ! V_22 -> V_295 ) {
V_21 = - V_231 ;
goto V_921;
}
if ( V_909 ) {
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_388 ( V_22 ) ;
V_21 = F_390 ( V_22 , F_312 ,
F_310 ) ;
if ( V_21 ) {
F_9 ( & V_22 -> V_29 -> V_30 ,
L_279 ) ;
F_397 ( V_22 ) ;
F_111 ( V_22 ) ;
F_380 ( V_22 ) ;
goto V_866;
}
V_21 = F_394 ( V_22 ) ;
if ( V_21 )
goto V_922;
F_90 ( & V_22 -> V_29 -> V_30 , L_280 ) ;
F_90 ( & V_22 -> V_29 -> V_30 ,
L_281 ) ;
V_22 -> V_94 . V_883 ( V_22 , V_923 ) ;
F_156 ( 10000 ) ;
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
V_21 = F_330 ( V_22 -> V_764 ) ;
if ( V_21 )
F_90 ( & V_22 -> V_29 -> V_30 ,
L_282 ) ;
F_396 ( V_22 ) ;
V_909 = 0 ;
if ( V_21 )
return - V_80 ;
goto V_911;
}
V_22 -> V_56 = 1 ;
V_22 -> V_94 . V_883 ( V_22 , V_923 ) ;
F_376 ( V_22 ) ;
V_22 -> V_126 = V_128 ;
F_433 ( & V_22 -> V_902 , F_419 ) ;
F_420 ( & V_22 -> V_902 ,
V_22 -> V_126 ) ;
F_433 ( & V_22 -> V_901 , F_415 ) ;
F_418 ( V_22 -> V_880 , & V_22 -> V_901 ,
V_22 -> V_126 ) ;
return 0 ;
V_922:
F_76 ( V_22 -> V_61 ) ;
V_921:
F_397 ( V_22 ) ;
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
V_920:
F_111 ( V_22 ) ;
V_919:
F_380 ( V_22 ) ;
V_867:
F_388 ( V_22 ) ;
V_866:
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
V_918:
F_368 ( V_22 ) ;
V_865:
if ( V_22 -> F_13 ) {
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
}
V_917:
if ( V_22 -> V_295 ) {
F_399 ( V_22 -> V_295 ) ;
V_22 -> V_295 = NULL ;
}
if ( V_22 -> V_880 ) {
F_399 ( V_22 -> V_880 ) ;
V_22 -> V_880 = NULL ;
}
F_76 ( V_22 ) ;
return V_21 ;
}
static void F_434 ( struct V_1 * V_22 )
{
char * V_924 ;
struct V_8 * V_9 ;
int V_21 ;
if ( F_40 ( F_13 ( V_22 ) ) )
return;
V_924 = F_96 ( 4 , V_183 ) ;
if ( ! V_924 )
return;
V_9 = F_160 ( V_22 ) ;
if ( F_161 ( V_9 , V_723 , V_22 , V_924 , 4 , 0 ,
V_137 , V_362 ) ) {
goto V_363;
}
V_21 = F_155 ( V_22 , V_9 ,
V_240 , V_349 ) ;
if ( V_21 )
goto V_363;
if ( V_9 -> V_24 -> V_36 != 0 )
V_363:
F_9 ( & V_22 -> V_29 -> V_30 ,
L_283 ) ;
F_162 ( V_22 , V_9 ) ;
F_76 ( V_924 ) ;
}
static void F_435 ( struct V_338 * V_29 )
{
struct V_1 * V_22 ;
V_22 = F_436 ( V_29 ) ;
F_434 ( V_22 ) ;
V_22 -> V_94 . V_883 ( V_22 , V_884 ) ;
F_388 ( V_22 ) ;
F_344 ( V_22 ) ;
}
static void F_437 ( struct V_1 * V_22 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_144 ; V_68 ++ ) {
F_76 ( V_22 -> V_30 [ V_68 ] ) ;
V_22 -> V_30 [ V_68 ] = NULL ;
}
}
static void F_438 ( struct V_338 * V_29 )
{
struct V_1 * V_22 ;
unsigned long V_77 ;
if ( F_436 ( V_29 ) == NULL ) {
F_69 ( & V_29 -> V_30 , L_284 ) ;
return;
}
V_22 = F_436 ( V_29 ) ;
F_34 ( & V_22 -> V_78 , V_77 ) ;
V_22 -> V_853 = 1 ;
F_35 ( & V_22 -> V_78 , V_77 ) ;
F_439 ( & V_22 -> V_902 ) ;
F_439 ( & V_22 -> V_901 ) ;
F_399 ( V_22 -> V_880 ) ;
F_399 ( V_22 -> V_295 ) ;
F_435 ( V_29 ) ;
F_437 ( V_22 ) ;
F_76 ( V_22 -> V_61 ) ;
V_22 -> V_61 = NULL ;
if ( V_22 -> V_59 )
F_440 ( V_22 -> V_59 ) ;
F_109 ( V_22 ) ;
F_397 ( V_22 ) ;
F_111 ( V_22 ) ;
F_380 ( V_22 ) ;
F_251 ( V_22 -> V_59 ) ;
V_22 -> V_59 = NULL ;
F_368 ( V_22 ) ;
F_398 ( V_22 -> F_13 ) ;
V_22 -> F_13 = NULL ;
F_76 ( V_22 ) ;
}
static void F_441 ( int V_925 [] , int V_926 ,
int V_927 , int V_928 , T_4 * V_929 )
{
int V_68 , V_173 , V_930 , V_416 ;
for ( V_68 = 0 ; V_68 <= V_927 ; V_68 ++ ) {
V_416 = V_68 + V_928 ;
V_930 = V_926 ;
for ( V_173 = 0 ; V_173 < V_926 ; V_173 ++ ) {
if ( V_925 [ V_173 ] >= V_416 ) {
V_930 = V_173 ;
break;
}
}
V_929 [ V_68 ] = V_930 ;
}
}
static int F_442 ( struct V_1 * V_22 , T_4 V_856 )
{
int V_68 ;
unsigned long V_931 ;
unsigned long V_63 = V_64 |
( V_856 & V_932 ) |
V_933 |
( V_856 & ( V_93 |
V_472 ) ) ;
struct V_934 V_94 = V_935 ;
int V_936 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_715 + 4 } ;
#define F_443 5
#define F_444 4
int V_937 [ 16 ] = { F_443 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_444 + V_938 } ;
F_266 ( F_26 ( V_937 ) != 16 ) ;
F_266 ( F_26 ( V_936 ) != 8 ) ;
F_266 ( F_232 ( struct V_118 , V_241 ) >
16 * F_443 ) ;
F_266 ( sizeof( struct V_235 ) != 16 ) ;
F_266 ( 28 > V_715 + 4 ) ;
if ( V_856 & ( V_93 | V_472 ) )
V_94 = V_939 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ )
memset ( V_22 -> V_92 [ V_68 ] . V_96 , 0 , V_22 -> V_879 ) ;
V_936 [ 7 ] = V_715 + 4 ;
F_441 ( V_936 , F_26 ( V_936 ) ,
V_715 , 4 , V_22 -> V_102 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_55 ( V_936 [ V_68 ] , & V_22 -> V_837 -> V_940 [ V_68 ] ) ;
F_55 ( V_22 -> V_100 , & V_22 -> V_837 -> V_941 ) ;
F_55 ( V_22 -> V_108 , & V_22 -> V_837 -> V_942 ) ;
F_55 ( 0 , & V_22 -> V_837 -> V_943 ) ;
F_55 ( 0 , & V_22 -> V_837 -> V_944 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ ) {
F_55 ( 0 , & V_22 -> V_837 -> V_945 [ V_68 ] . V_946 ) ;
F_55 ( V_22 -> V_92 [ V_68 ] . V_101 ,
& V_22 -> V_837 -> V_945 [ V_68 ] . V_947 ) ;
}
F_55 ( 0 , & V_22 -> V_764 -> V_787 . V_859 ) ;
F_55 ( V_63 , & ( V_22 -> V_764 -> V_787 . V_788 ) ) ;
if ( V_856 & V_93 ) {
V_94 = V_948 ;
F_55 ( 10 , & V_22 -> V_764 -> V_787 . V_789 ) ;
F_55 ( 4 , & V_22 -> V_764 -> V_787 . V_790 ) ;
} else {
if ( V_856 & V_472 ) {
V_94 = V_949 ;
F_55 ( 10 , & V_22 -> V_764 -> V_787 . V_789 ) ;
F_55 ( 4 , & V_22 -> V_764 -> V_787 . V_790 ) ;
}
}
F_55 ( V_854 , V_22 -> V_131 + V_759 ) ;
if ( F_366 ( V_22 ) ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_285 ) ;
return - V_80 ;
}
V_931 = F_321 ( & ( V_22 -> V_764 -> V_786 ) ) ;
if ( ! ( V_931 & V_64 ) ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_286 ) ;
return - V_80 ;
}
V_22 -> V_94 = V_94 ;
V_22 -> V_63 = V_63 ;
if ( ! ( ( V_856 & V_93 ) ||
( V_856 & V_472 ) ) )
return 0 ;
if ( V_856 & V_93 ) {
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ ) {
F_55 ( V_68 , V_22 -> V_131 + V_950 ) ;
V_22 -> V_92 [ V_68 ] . V_97 =
F_321 ( V_22 -> V_131 + V_951 ) ;
}
V_936 [ 7 ] = V_22 -> V_500 + 8 ;
F_441 ( V_936 , F_26 ( V_936 ) , V_22 -> V_500 , 8 ,
V_22 -> V_113 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ )
memset ( V_22 -> V_92 [ V_68 ] . V_96 ,
( T_1 ) V_952 ,
V_22 -> V_879 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
struct V_109 * V_110 = & V_22 -> V_111 [ V_68 ] ;
V_110 -> V_953 = V_954 ;
V_110 -> V_24 = ( T_4 ) ( V_22 -> V_582 +
( V_68 * sizeof( struct V_305 ) ) ) ;
V_110 -> V_955 = sizeof( struct V_305 ) ;
V_110 -> V_956 = V_957 ;
V_110 -> V_958 =
F_143 ( V_959 ) ;
V_110 -> V_960 = 0 ;
V_110 -> V_107 = 0 ;
V_110 -> V_317 =
F_117 ( ( V_68 << V_532 ) ) ;
V_110 -> V_961 =
F_117 ( V_22 -> V_503 +
( V_68 * sizeof( struct V_109 ) ) ) ;
}
} else if ( V_856 & V_472 ) {
T_5 V_767 , V_769 ;
T_4 V_962 , V_768 ;
int V_21 ;
V_21 = F_335 ( V_22 -> V_29 , V_22 -> V_131 , & V_768 ,
& V_769 , & V_767 ) ;
F_266 ( F_232 ( struct V_118 , V_241 ) != 64 ) ;
V_937 [ 15 ] = V_22 -> V_500 + F_444 ;
F_441 ( V_937 , F_26 ( V_937 ) , V_22 -> V_500 ,
4 , V_22 -> V_117 ) ;
V_962 = F_321 ( & V_22 -> V_764 -> V_963 ) ;
F_266 ( F_232 ( struct V_763 ,
V_963 ) != 0xb8 ) ;
V_22 -> V_964 =
F_297 ( F_336 ( V_22 -> V_29 ,
V_769 ) +
V_767 + V_962 ,
F_26 ( V_937 ) *
sizeof( * V_22 -> V_964 ) ) ;
for ( V_68 = 0 ; V_68 < F_26 ( V_937 ) ; V_68 ++ )
F_55 ( V_937 [ V_68 ] , & V_22 -> V_964 [ V_68 ] ) ;
}
F_55 ( V_854 , V_22 -> V_131 + V_759 ) ;
if ( F_366 ( V_22 ) ) {
F_69 ( & V_22 -> V_29 -> V_30 ,
L_287 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_445 ( struct V_1 * V_22 )
{
if ( V_22 -> V_111 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_111 ) ,
V_22 -> V_111 ,
V_22 -> V_503 ) ;
V_22 -> V_111 = NULL ;
V_22 -> V_503 = 0 ;
}
F_76 ( V_22 -> V_113 ) ;
V_22 -> V_113 = NULL ;
}
static int F_446 ( struct V_1 * V_22 )
{
V_22 -> V_500 =
F_321 ( & ( V_22 -> V_764 -> V_965 ) ) ;
if ( V_22 -> V_500 > V_966 )
V_22 -> V_500 = V_966 ;
F_266 ( sizeof( struct V_109 ) %
V_967 ) ;
V_22 -> V_111 =
F_320 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_111 ) ,
& ( V_22 -> V_503 ) ) ;
V_22 -> V_113 =
F_87 ( ( ( V_22 -> V_500 + 1 ) *
sizeof( T_4 ) ) , V_183 ) ;
if ( ( V_22 -> V_111 == NULL ) ||
( V_22 -> V_113 == NULL ) )
goto V_872;
memset ( V_22 -> V_111 , 0 ,
V_22 -> V_217 * sizeof( * V_22 -> V_111 ) ) ;
return 0 ;
V_872:
F_445 ( V_22 ) ;
return - V_231 ;
}
static void F_447 ( struct V_1 * V_22 )
{
F_109 ( V_22 ) ;
if ( V_22 -> V_116 ) {
F_322 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_116 ) ,
V_22 -> V_116 ,
V_22 -> V_522 ) ;
V_22 -> V_116 = NULL ;
V_22 -> V_522 = 0 ;
}
F_76 ( V_22 -> V_117 ) ;
V_22 -> V_117 = NULL ;
}
static int F_448 ( struct V_1 * V_22 )
{
int V_21 ;
V_22 -> V_500 =
F_321 ( & ( V_22 -> V_764 -> V_965 ) ) ;
if ( V_22 -> V_500 > V_938 )
V_22 -> V_500 = V_938 ;
F_266 ( sizeof( struct V_118 ) %
V_968 ) ;
V_22 -> V_116 =
F_320 ( V_22 -> V_29 ,
V_22 -> V_217 * sizeof( * V_22 -> V_116 ) ,
& ( V_22 -> V_522 ) ) ;
V_22 -> V_117 =
F_87 ( ( ( V_22 -> V_500 + 1 ) *
sizeof( T_4 ) ) , V_183 ) ;
if ( ( V_22 -> V_116 == NULL ) ||
( V_22 -> V_117 == NULL ) ) {
V_21 = - V_231 ;
goto V_872;
}
V_21 = F_110 ( V_22 ) ;
if ( V_21 )
goto V_872;
memset ( V_22 -> V_116 , 0 ,
V_22 -> V_217 * sizeof( * V_22 -> V_116 ) ) ;
return 0 ;
V_872:
F_447 ( V_22 ) ;
return V_21 ;
}
static void F_397 ( struct V_1 * V_22 )
{
F_76 ( V_22 -> V_102 ) ;
V_22 -> V_102 = NULL ;
F_395 ( V_22 ) ;
F_445 ( V_22 ) ;
F_447 ( V_22 ) ;
}
static int F_432 ( struct V_1 * V_22 )
{
T_4 V_856 ;
unsigned long V_63 = V_64 |
V_932 ;
int V_68 , V_21 ;
if ( V_913 )
return 0 ;
V_856 = F_321 ( & ( V_22 -> V_764 -> V_785 ) ) ;
if ( ! ( V_856 & V_969 ) )
return 0 ;
if ( V_856 & V_93 ) {
V_63 |= V_93 |
V_933 ;
V_21 = F_446 ( V_22 ) ;
if ( V_21 )
return V_21 ;
} else if ( V_856 & V_472 ) {
V_63 |= V_472 |
V_933 ;
V_21 = F_448 ( V_22 ) ;
if ( V_21 )
return V_21 ;
}
V_22 -> V_108 = V_22 -> V_105 > 0 ? V_22 -> V_105 : 1 ;
F_356 ( V_22 ) ;
V_22 -> V_879 = V_22 -> V_100 * sizeof( T_5 ) ;
for ( V_68 = 0 ; V_68 < V_22 -> V_108 ; V_68 ++ ) {
V_22 -> V_92 [ V_68 ] . V_96 = F_320 ( V_22 -> V_29 ,
V_22 -> V_879 ,
& ( V_22 -> V_92 [ V_68 ] . V_101 ) ) ;
if ( ! V_22 -> V_92 [ V_68 ] . V_96 ) {
V_21 = - V_231 ;
goto V_917;
}
V_22 -> V_92 [ V_68 ] . V_416 = V_22 -> V_100 ;
V_22 -> V_92 [ V_68 ] . V_98 = 1 ;
V_22 -> V_92 [ V_68 ] . V_97 = 0 ;
}
V_22 -> V_102 = F_87 ( ( ( V_715 + 1 ) *
sizeof( T_4 ) ) , V_183 ) ;
if ( ! V_22 -> V_102 ) {
V_21 = - V_231 ;
goto V_917;
}
V_21 = F_442 ( V_22 , V_856 ) ;
if ( V_21 )
goto V_865;
return 0 ;
V_865:
F_76 ( V_22 -> V_102 ) ;
V_22 -> V_102 = NULL ;
V_917:
F_395 ( V_22 ) ;
F_445 ( V_22 ) ;
F_447 ( V_22 ) ;
return V_21 ;
}
static int F_449 ( struct V_8 * V_9 )
{
return V_9 -> V_129 == V_130 || V_9 -> V_129 == V_133 ;
}
static void F_408 ( struct V_1 * V_22 )
{
struct V_8 * V_9 = NULL ;
int V_68 , V_970 ;
int V_377 ;
do {
V_970 = 0 ;
for ( V_68 = 0 ; V_68 < V_22 -> V_217 ; V_68 ++ ) {
V_9 = V_22 -> V_376 + V_68 ;
V_377 = F_169 ( & V_9 -> V_377 ) ;
if ( V_377 > 1 )
V_970 += F_449 ( V_9 ) ;
F_162 ( V_22 , V_9 ) ;
}
if ( V_970 <= 0 )
break;
F_156 ( 100 ) ;
} while ( 1 );
}
static int T_17 F_450 ( void )
{
return F_451 ( & V_971 ) ;
}
static void T_18 F_452 ( void )
{
F_453 ( & V_971 ) ;
}
