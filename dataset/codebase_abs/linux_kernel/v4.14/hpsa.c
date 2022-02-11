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
static T_2 F_44 ( struct V_41 * V_29 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_21 ;
struct V_6 * V_46 = F_12 ( V_29 ) ;
V_21 = F_3 ( V_46 ) ;
return snprintf ( V_44 , 20 , L_15 , V_21 -> V_109 ? 1 : 0 ) ;
}
static inline T_4 F_45 ( struct V_1 * V_21 , T_1 V_110 )
{
T_4 V_64 ;
struct V_111 * V_112 = & V_21 -> V_113 [ V_110 ] ;
if ( V_21 -> V_62 & V_114 )
return V_21 -> V_115 . V_116 ( V_21 , V_110 ) ;
if ( F_46 ( ! ( V_21 -> V_62 & V_63 ) ) )
return V_21 -> V_115 . V_116 ( V_21 , V_110 ) ;
if ( ( V_112 -> V_117 [ V_112 -> V_118 ] & 1 ) == V_112 -> V_119 ) {
V_64 = V_112 -> V_117 [ V_112 -> V_118 ] ;
V_112 -> V_118 ++ ;
F_47 ( & V_21 -> V_61 ) ;
} else {
V_64 = V_120 ;
}
if ( V_112 -> V_118 == V_21 -> V_121 ) {
V_112 -> V_118 = 0 ;
V_112 -> V_119 ^= 1 ;
}
return V_64 ;
}
static void F_48 ( struct V_1 * V_21 , struct V_8 * V_9 ,
int V_113 )
{
if ( F_49 ( V_21 -> V_62 & V_63 ) ) {
V_9 -> V_122 |= 1 | ( V_21 -> V_123 [ V_9 -> V_124 . V_125 ] << 1 ) ;
if ( F_46 ( ! V_21 -> V_126 ) )
return;
if ( F_49 ( V_113 == V_127 ) )
V_9 -> V_124 . V_128 =
F_50 () % V_21 -> V_129 ;
else
V_9 -> V_124 . V_128 = V_113 % V_21 -> V_129 ;
}
}
static void F_51 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_130 * V_131 = & V_21 -> V_132 [ V_9 -> V_133 ] ;
if ( F_49 ( V_113 == V_127 ) )
V_131 -> V_128 = F_52 () % V_21 -> V_129 ;
else
V_131 -> V_128 = V_113 % V_21 -> V_129 ;
V_9 -> V_122 |= 1 | ( V_21 -> V_134 [ V_9 -> V_124 . V_125 ] << 1 ) |
V_135 ;
}
static void F_53 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_136 * V_131 = (struct V_136 * )
& V_21 -> V_137 [ V_9 -> V_133 ] ;
if ( F_49 ( V_113 == V_127 ) )
V_131 -> V_113 = F_52 () % V_21 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_21 -> V_129 ;
V_9 -> V_122 |= V_21 -> V_138 [ 0 ] ;
}
static void F_54 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
int V_113 )
{
struct V_139 * V_131 = & V_21 -> V_137 [ V_9 -> V_133 ] ;
if ( F_49 ( V_113 == V_127 ) )
V_131 -> V_113 = F_52 () % V_21 -> V_129 ;
else
V_131 -> V_113 = V_113 % V_21 -> V_129 ;
V_9 -> V_122 |= ( V_21 -> V_138 [ V_131 -> V_140 ] ) ;
}
static int F_55 ( T_1 * V_141 )
{
return V_141 [ 0 ] == V_142 && V_141 [ 6 ] == V_143 ;
}
static void F_56 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 -> V_144 . V_145 ) )
return;
F_57 ( & V_21 -> V_146 ) ;
V_21 -> V_147 = V_148 ;
}
static void F_58 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( F_55 ( V_9 -> V_144 . V_145 ) &&
F_59 ( & V_21 -> V_146 ) )
V_21 -> V_147 = V_149 ;
}
static void F_60 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_113 )
{
F_56 ( V_21 , V_9 ) ;
F_57 ( & V_21 -> V_61 ) ;
switch ( V_9 -> V_150 ) {
case V_151 :
F_51 ( V_21 , V_9 , V_113 ) ;
F_61 ( V_9 -> V_122 , V_21 -> V_152 + V_153 ) ;
break;
case V_154 :
F_54 ( V_21 , V_9 , V_113 ) ;
F_61 ( V_9 -> V_122 , V_21 -> V_152 + V_155 ) ;
break;
case V_156 :
F_53 ( V_21 , V_9 , V_113 ) ;
F_61 ( V_9 -> V_122 , V_21 -> V_152 + V_155 ) ;
break;
default:
F_48 ( V_21 , V_9 , V_113 ) ;
V_21 -> V_115 . V_157 ( V_21 , V_9 ) ;
}
}
static void F_62 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
if ( F_46 ( F_5 ( V_9 ) ) )
return F_63 ( V_9 ) ;
F_60 ( V_21 , V_9 , V_127 ) ;
}
static inline int F_64 ( unsigned char V_70 [] )
{
return memcmp ( V_70 , V_158 , 8 ) == 0 ;
}
static inline int F_65 ( struct V_1 * V_21 )
{
if ( ! V_21 -> V_60 )
return 0 ;
if ( ( V_21 -> V_60 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_21 ,
unsigned char V_70 [] , int V_101 , int * V_102 , int * V_103 )
{
int V_67 , V_159 = 0 ;
F_67 ( V_160 , V_161 ) ;
F_68 ( V_160 , V_161 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] -> V_101 == V_101 && V_21 -> V_29 [ V_67 ] -> V_102 != - 1 )
F_69 ( V_21 -> V_29 [ V_67 ] -> V_102 , V_160 ) ;
}
V_67 = F_70 ( V_160 , V_161 ) ;
if ( V_67 < V_161 ) {
* V_102 = V_67 ;
* V_103 = 0 ;
V_159 = 1 ;
}
return ! V_159 ;
}
static void F_71 ( const char * V_163 , struct V_1 * V_21 ,
struct V_71 * V_29 , char * V_164 )
{
#define F_72 25
char V_165 [ F_72 ] ;
if ( V_21 == NULL || V_21 -> V_28 == NULL || V_21 -> V_58 == NULL )
return;
switch ( V_29 -> V_104 ) {
case V_105 :
snprintf ( V_165 , F_72 , L_33 ) ;
break;
case V_166 :
snprintf ( V_165 , F_72 , L_34 ) ;
break;
case V_106 :
case V_107 :
if ( V_29 -> V_167 )
snprintf ( V_165 , F_72 , L_35 ) ;
else if ( ! F_30 ( V_29 -> V_70 ) )
snprintf ( V_165 , F_72 , L_36 ,
V_83 [ V_168 ] ) ;
else
snprintf ( V_165 , F_72 , L_37 ,
V_29 -> V_81 > V_82 ? L_38 :
V_83 [ V_29 -> V_81 ] ) ;
break;
case V_169 :
snprintf ( V_165 , F_72 , L_39 ) ;
break;
case V_170 :
snprintf ( V_165 , F_72 , L_40 ) ;
break;
case V_171 :
snprintf ( V_165 , F_72 , L_41 ) ;
break;
default:
snprintf ( V_165 , F_72 , L_42 ) ;
break;
}
F_73 ( V_163 , & V_21 -> V_28 -> V_29 ,
L_43 ,
V_21 -> V_58 -> V_100 , V_29 -> V_101 , V_29 -> V_102 , V_29 -> V_103 ,
V_164 ,
F_42 ( V_29 -> V_104 ) ,
V_29 -> V_172 ,
V_29 -> V_173 ,
V_165 ,
V_29 -> V_174 ? '+' : '-' ,
V_29 -> V_89 ? '+' : '-' ,
V_29 -> V_88 ) ;
}
static int F_74 ( struct V_1 * V_21 ,
struct V_71 * V_41 ,
struct V_71 * V_175 [] , int * V_176 )
{
int V_177 = V_21 -> V_162 ;
int V_67 ;
unsigned char V_178 [ 8 ] , V_179 [ 8 ] ;
struct V_71 * V_180 ;
if ( V_177 >= V_161 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_44
L_45 ) ;
return - 1 ;
}
if ( V_41 -> V_103 != - 1 )
goto V_181;
if ( V_41 -> V_70 [ 4 ] == 0 ) {
if ( F_66 ( V_21 , V_41 -> V_70 ,
V_41 -> V_101 , & V_41 -> V_102 , & V_41 -> V_103 ) != 0 )
return - 1 ;
goto V_181;
}
memcpy ( V_178 , V_41 -> V_70 , 8 ) ;
V_178 [ 4 ] = 0 ;
V_178 [ 5 ] = 0 ;
for ( V_67 = 0 ; V_67 < V_177 ; V_67 ++ ) {
V_180 = V_21 -> V_29 [ V_67 ] ;
memcpy ( V_179 , V_180 -> V_70 , 8 ) ;
V_179 [ 4 ] = 0 ;
V_179 [ 5 ] = 0 ;
if ( memcmp ( V_178 , V_179 , 8 ) == 0 ) {
V_41 -> V_101 = V_180 -> V_101 ;
V_41 -> V_102 = V_180 -> V_102 ;
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
V_181:
V_21 -> V_29 [ V_177 ] = V_41 ;
V_21 -> V_162 ++ ;
V_175 [ * V_176 ] = V_41 ;
( * V_176 ) ++ ;
F_71 ( V_182 , V_21 , V_41 ,
V_41 -> V_88 ? L_49 : L_50 ) ;
V_41 -> V_183 = V_41 -> V_89 ;
V_41 -> V_89 = 0 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_21 ,
int V_184 , struct V_71 * V_185 )
{
int V_89 ;
F_77 ( V_184 < 0 || V_184 >= V_161 ) ;
V_21 -> V_29 [ V_184 ] -> V_81 = V_185 -> V_81 ;
if ( V_185 -> V_174 && V_185 -> V_89 ) {
V_21 -> V_29 [ V_184 ] -> V_186 = V_185 -> V_186 ;
V_21 -> V_29 [ V_184 ] -> V_187 = V_185 -> V_187 ;
}
if ( V_185 -> V_188 ) {
V_21 -> V_29 [ V_184 ] -> V_187 = V_185 -> V_187 ;
F_78 () ;
}
V_21 -> V_29 [ V_184 ] -> V_188 = V_185 -> V_188 ;
V_21 -> V_29 [ V_184 ] -> V_174 = V_185 -> V_174 ;
V_21 -> V_29 [ V_184 ] -> V_189 = V_185 -> V_189 ;
V_21 -> V_29 [ V_184 ] -> V_190 = V_185 -> V_190 ;
V_21 -> V_29 [ V_184 ] -> V_183 = V_185 -> V_89 ;
if ( ! V_185 -> V_89 )
V_21 -> V_29 [ V_184 ] -> V_89 = 0 ;
V_89 = V_21 -> V_29 [ V_184 ] -> V_89 ;
V_21 -> V_29 [ V_184 ] -> V_89 = V_21 -> V_29 [ V_184 ] -> V_183 ;
F_71 ( V_182 , V_21 , V_21 -> V_29 [ V_184 ] , L_51 ) ;
V_21 -> V_29 [ V_184 ] -> V_89 = V_89 ;
}
static void F_79 ( struct V_1 * V_21 ,
int V_184 , struct V_71 * V_185 ,
struct V_71 * V_175 [] , int * V_176 ,
struct V_71 * V_191 [] , int * V_192 )
{
F_77 ( V_184 < 0 || V_184 >= V_161 ) ;
V_191 [ * V_192 ] = V_21 -> V_29 [ V_184 ] ;
( * V_192 ) ++ ;
if ( V_185 -> V_102 == - 1 ) {
V_185 -> V_102 = V_21 -> V_29 [ V_184 ] -> V_102 ;
V_185 -> V_103 = V_21 -> V_29 [ V_184 ] -> V_103 ;
}
V_21 -> V_29 [ V_184 ] = V_185 ;
V_175 [ * V_176 ] = V_185 ;
( * V_176 ) ++ ;
F_71 ( V_182 , V_21 , V_185 , L_52 ) ;
V_185 -> V_183 = V_185 -> V_89 ;
V_185 -> V_89 = 0 ;
}
static void F_80 ( struct V_1 * V_21 , int V_184 ,
struct V_71 * V_191 [] , int * V_192 )
{
int V_67 ;
struct V_71 * V_180 ;
F_77 ( V_184 < 0 || V_184 >= V_161 ) ;
V_180 = V_21 -> V_29 [ V_184 ] ;
V_191 [ * V_192 ] = V_21 -> V_29 [ V_184 ] ;
( * V_192 ) ++ ;
for ( V_67 = V_184 ; V_67 < V_21 -> V_162 - 1 ; V_67 ++ )
V_21 -> V_29 [ V_67 ] = V_21 -> V_29 [ V_67 + 1 ] ;
V_21 -> V_162 -- ;
F_71 ( V_182 , V_21 , V_180 , L_53 ) ;
}
static void F_81 ( struct V_1 * V_21 ,
struct V_71 * V_175 )
{
unsigned long V_76 ;
int V_67 , V_193 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] == V_175 ) {
for ( V_193 = V_67 ; V_193 < V_21 -> V_162 - 1 ; V_193 ++ )
V_21 -> V_29 [ V_193 ] = V_21 -> V_29 [ V_193 + 1 ] ;
V_21 -> V_162 -- ;
break;
}
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_82 ( V_175 ) ;
}
static inline int F_83 ( struct V_71 * V_194 ,
struct V_71 * V_195 )
{
if ( memcmp ( V_194 -> V_70 , V_195 -> V_70 ,
sizeof( V_194 -> V_70 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_86 , V_195 -> V_86 ,
sizeof( V_194 -> V_86 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_173 , V_195 -> V_173 , sizeof( V_194 -> V_173 ) ) != 0 )
return 0 ;
if ( memcmp ( V_194 -> V_172 , V_195 -> V_172 , sizeof( V_194 -> V_172 ) ) != 0 )
return 0 ;
if ( V_194 -> V_104 != V_195 -> V_104 )
return 0 ;
if ( V_194 -> V_101 != V_195 -> V_101 )
return 0 ;
return 1 ;
}
static inline int F_84 ( struct V_71 * V_194 ,
struct V_71 * V_195 )
{
if ( V_194 -> V_81 != V_195 -> V_81 )
return 1 ;
if ( V_194 -> V_174 != V_195 -> V_174 )
return 1 ;
if ( V_194 -> V_89 != V_195 -> V_89 )
return 1 ;
if ( ! F_30 ( V_194 -> V_70 ) )
if ( V_194 -> V_190 != V_195 -> V_190 )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_71 * V_196 ,
struct V_71 * V_197 [] , int V_198 ,
int * V_199 )
{
int V_67 ;
#define F_86 0
#define F_87 1
#define F_88 2
#define F_89 3
if ( V_196 == NULL )
return F_86 ;
for ( V_67 = 0 ; V_67 < V_198 ; V_67 ++ ) {
if ( V_197 [ V_67 ] == NULL )
continue;
if ( F_90 ( V_196 -> V_70 , V_197 [ V_67 ] -> V_70 ) ) {
* V_199 = V_67 ;
if ( F_83 ( V_196 , V_197 [ V_67 ] ) ) {
if ( F_84 ( V_196 , V_197 [ V_67 ] ) )
return F_89 ;
return F_88 ;
} else {
if ( V_196 -> V_200 )
return F_86 ;
return F_87 ;
}
}
}
* V_199 = - 1 ;
return F_86 ;
}
static void F_91 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
struct V_201 * V_41 ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_202 , V_76 ) ;
F_92 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_41 -> V_70 , V_70 ,
sizeof( V_41 -> V_70 ) ) == 0 ) {
F_35 ( & V_21 -> V_202 , V_76 ) ;
return;
}
}
F_35 ( & V_21 -> V_202 , V_76 ) ;
V_41 = F_93 ( sizeof( * V_41 ) , V_203 ) ;
if ( ! V_41 )
return;
memcpy ( V_41 -> V_70 , V_70 , sizeof( V_41 -> V_70 ) ) ;
F_34 ( & V_21 -> V_202 , V_76 ) ;
F_94 ( & V_41 -> V_204 , & V_21 -> V_205 ) ;
F_35 ( & V_21 -> V_202 , V_76 ) ;
}
static void F_95 ( struct V_1 * V_21 ,
struct V_71 * V_180 )
{
if ( V_180 -> V_200 == V_206 )
F_96 ( & V_21 -> V_28 -> V_29 ,
L_54 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
switch ( V_180 -> V_200 ) {
case V_207 :
break;
case V_208 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_55 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_209 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_56 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_210 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_57 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_211 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_58 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_212 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_59 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_213 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_60 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_214 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_61 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_215 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_62 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_216 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_63 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_217 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_64 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
case V_218 :
F_96 ( & V_21 -> V_28 -> V_29 ,
L_65 ,
V_21 -> V_58 -> V_100 ,
V_180 -> V_101 , V_180 -> V_102 , V_180 -> V_103 ) ;
break;
}
}
static void F_97 ( struct V_1 * V_21 ,
struct V_71 * V_29 [] , int V_162 ,
struct V_71 * V_219 )
{
struct V_220 * V_221 = & V_219 -> V_186 ;
struct V_222 * V_223 = & V_221 -> V_224 [ 0 ] ;
int V_67 , V_193 ;
int V_225 = F_98 ( V_221 -> V_226 ) +
F_98 ( V_221 -> V_227 ) ;
int V_228 = F_98 ( V_221 -> V_229 ) *
F_98 ( V_221 -> V_230 ) *
V_225 ;
int V_231 = F_98 ( V_221 -> V_230 ) *
V_225 ;
int V_232 ;
if ( V_228 > V_233 )
V_228 = V_233 ;
V_219 -> V_234 = V_228 ;
V_232 = 0 ;
for ( V_67 = 0 ; V_67 < V_228 ; V_67 ++ ) {
V_219 -> V_235 [ V_67 ] = NULL ;
if ( ! V_219 -> V_174 )
continue;
for ( V_193 = 0 ; V_193 < V_162 ; V_193 ++ ) {
if ( V_29 [ V_193 ] == NULL )
continue;
if ( V_29 [ V_193 ] -> V_104 != V_106 &&
V_29 [ V_193 ] -> V_104 != V_107 )
continue;
if ( F_31 ( V_29 [ V_193 ] ) )
continue;
if ( V_29 [ V_193 ] -> V_187 != V_223 [ V_67 ] . V_187 )
continue;
V_219 -> V_235 [ V_67 ] = V_29 [ V_193 ] ;
if ( V_67 < V_231 )
V_232 = F_99 ( V_21 -> V_236 , V_232 +
V_219 -> V_235 [ V_67 ] -> V_190 ) ;
break;
}
if ( ! V_219 -> V_235 [ V_67 ] ) {
V_219 -> V_89 = 0 ;
V_219 -> V_183 = 0 ;
V_219 -> V_190 = 8 ;
}
}
if ( V_228 )
V_219 -> V_190 = V_232 ;
else
V_219 -> V_190 = V_21 -> V_236 ;
}
static void F_100 ( struct V_1 * V_21 ,
struct V_71 * V_29 [] , int V_162 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_162 ; V_67 ++ ) {
if ( V_29 [ V_67 ] == NULL )
continue;
if ( V_29 [ V_67 ] -> V_104 != V_106 &&
V_29 [ V_67 ] -> V_104 != V_107 )
continue;
if ( ! F_31 ( V_29 [ V_67 ] ) )
continue;
if ( V_29 [ V_67 ] -> V_89 )
continue;
F_97 ( V_21 , V_29 , V_162 , V_29 [ V_67 ] ) ;
}
}
static int F_101 ( struct V_1 * V_21 , struct V_71 * V_41 )
{
int V_20 = 0 ;
if ( ! V_21 -> V_58 )
return 1 ;
if ( F_31 ( V_41 ) )
V_20 = F_102 ( V_21 -> V_58 , V_41 -> V_101 ,
V_41 -> V_102 , V_41 -> V_103 ) ;
else
V_20 = F_103 ( V_21 -> V_237 , V_41 ) ;
return V_20 ;
}
static int F_104 ( struct V_1 * V_21 ,
struct V_71 * V_29 )
{
int V_67 ;
int V_47 = 0 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_238 + V_67 ;
int V_239 = F_105 ( & V_9 -> V_239 ) ;
if ( V_239 > 1 && F_106 ( V_21 , V_9 , V_29 ,
V_29 -> V_70 ) ) {
unsigned long V_76 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! F_4 ( V_9 ) )
++ V_47 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
F_107 ( V_21 , V_9 ) ;
}
return V_47 ;
}
static void F_108 ( struct V_1 * V_21 ,
struct V_71 * V_41 )
{
int V_240 = 0 ;
int V_241 = 0 ;
while ( 1 ) {
V_240 = F_104 ( V_21 , V_41 ) ;
if ( V_240 == 0 )
break;
if ( ++ V_241 > 20 )
break;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_66 ,
V_242 , V_240 ) ;
F_109 ( 1000 ) ;
}
}
static void F_110 ( struct V_1 * V_21 ,
struct V_71 * V_41 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_21 -> V_58 )
return;
if ( F_31 ( V_41 ) ) {
V_3 = F_111 ( V_21 -> V_58 , V_41 -> V_101 ,
V_41 -> V_102 , V_41 -> V_103 ) ;
if ( V_3 ) {
F_112 ( V_3 ) ;
F_113 ( V_3 ) ;
} else {
F_71 ( V_243 , V_21 , V_41 ,
L_67 ) ;
}
} else {
V_41 -> V_191 = 1 ;
F_108 ( V_21 , V_41 ) ;
F_114 ( V_41 ) ;
}
}
static void F_115 ( struct V_1 * V_21 ,
struct V_71 * V_180 [] , int V_244 )
{
int V_67 , V_184 , V_245 , V_246 = 0 ;
struct V_71 * V_247 ;
unsigned long V_76 ;
struct V_71 * * V_175 , * * V_191 ;
int V_176 , V_192 ;
F_34 ( & V_21 -> V_248 , V_76 ) ;
if ( V_21 -> V_249 ) {
V_21 -> V_250 = 1 ;
F_35 ( & V_21 -> V_248 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_248 , V_76 ) ;
V_175 = F_116 ( sizeof( * V_175 ) * V_161 , V_203 ) ;
V_191 = F_116 ( sizeof( * V_191 ) * V_161 , V_203 ) ;
if ( ! V_175 || ! V_191 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_68
L_69 ) ;
goto V_251;
}
F_34 ( & V_21 -> V_96 , V_76 ) ;
V_67 = 0 ;
V_192 = 0 ;
V_176 = 0 ;
while ( V_67 < V_21 -> V_162 ) {
V_247 = V_21 -> V_29 [ V_67 ] ;
V_245 = F_85 ( V_247 , V_180 , V_244 , & V_184 ) ;
if ( V_245 == F_86 ) {
V_246 ++ ;
F_80 ( V_21 , V_67 , V_191 , & V_192 ) ;
continue;
} else if ( V_245 == F_87 ) {
V_246 ++ ;
F_79 ( V_21 , V_67 , V_180 [ V_184 ] ,
V_175 , & V_176 , V_191 , & V_192 ) ;
V_180 [ V_184 ] = NULL ;
} else if ( V_245 == F_89 ) {
F_76 ( V_21 , V_67 , V_180 [ V_184 ] ) ;
}
V_67 ++ ;
}
for ( V_67 = 0 ; V_67 < V_244 ; V_67 ++ ) {
if ( ! V_180 [ V_67 ] )
continue;
if ( V_180 [ V_67 ] -> V_200 ) {
F_95 ( V_21 , V_180 [ V_67 ] ) ;
F_71 ( V_182 , V_21 , V_180 [ V_67 ] , L_70 ) ;
continue;
}
V_245 = F_85 ( V_180 [ V_67 ] , V_21 -> V_29 ,
V_21 -> V_162 , & V_184 ) ;
if ( V_245 == F_86 ) {
V_246 ++ ;
if ( F_74 ( V_21 , V_180 [ V_67 ] , V_175 , & V_176 ) != 0 )
break;
V_180 [ V_67 ] = NULL ;
} else if ( V_245 == F_87 ) {
V_246 ++ ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_71 ) ;
}
}
F_100 ( V_21 , V_21 -> V_29 , V_21 -> V_162 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
if ( V_21 -> V_29 [ V_67 ] == NULL )
continue;
V_21 -> V_29 [ V_67 ] -> V_89 = V_21 -> V_29 [ V_67 ] -> V_183 ;
}
F_35 ( & V_21 -> V_96 , V_76 ) ;
for ( V_67 = 0 ; V_67 < V_244 ; V_67 ++ ) {
if ( ! V_180 [ V_67 ] )
continue;
if ( V_180 [ V_67 ] -> V_200 )
F_91 ( V_21 , V_180 [ V_67 ] -> V_70 ) ;
}
if ( ! V_246 )
goto V_251;
for ( V_67 = 0 ; V_67 < V_192 ; V_67 ++ ) {
if ( V_191 [ V_67 ] == NULL )
continue;
if ( V_191 [ V_67 ] -> V_88 )
F_110 ( V_21 , V_191 [ V_67 ] ) ;
F_82 ( V_191 [ V_67 ] ) ;
V_191 [ V_67 ] = NULL ;
}
for ( V_67 = 0 ; V_67 < V_176 ; V_67 ++ ) {
int V_20 = 0 ;
if ( V_175 [ V_67 ] == NULL )
continue;
if ( ! ( V_175 [ V_67 ] -> V_88 ) )
continue;
V_20 = F_101 ( V_21 , V_175 [ V_67 ] ) ;
if ( ! V_20 )
continue;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_72 , V_20 ) ;
F_81 ( V_21 , V_175 [ V_67 ] ) ;
V_21 -> V_250 = 1 ;
}
V_251:
F_82 ( V_175 ) ;
F_82 ( V_191 ) ;
}
static struct V_71 * F_117 ( struct V_1 * V_21 ,
int V_101 , int V_102 , int V_103 )
{
int V_67 ;
struct V_71 * V_180 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
V_180 = V_21 -> V_29 [ V_67 ] ;
if ( V_180 -> V_101 == V_101 && V_180 -> V_102 == V_102 && V_180 -> V_103 == V_103 )
return V_180 ;
}
return NULL ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_71 * V_180 = NULL ;
unsigned long V_76 ;
struct V_1 * V_21 ;
V_21 = F_1 ( V_3 ) ;
F_34 ( & V_21 -> V_96 , V_76 ) ;
if ( F_119 ( V_3 ) == V_252 ) {
struct V_253 * V_254 ;
struct V_255 * V_256 ;
V_254 = V_253 ( V_3 ) ;
V_256 = F_120 ( V_254 ) ;
V_180 = F_121 ( V_21 , V_256 ) ;
if ( V_180 ) {
V_180 -> V_102 = F_122 ( V_3 ) ;
V_180 -> V_103 = V_3 -> V_103 ;
}
}
if ( ! V_180 )
V_180 = F_117 ( V_21 , F_119 ( V_3 ) ,
F_122 ( V_3 ) , V_3 -> V_103 ) ;
if ( V_180 && V_180 -> V_88 ) {
F_123 ( & V_180 -> V_257 , 0 ) ;
V_3 -> V_78 = V_180 ;
} else
V_3 -> V_78 = NULL ;
F_35 ( & V_21 -> V_96 , V_76 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 )
{
struct V_71 * V_180 ;
int V_190 ;
V_180 = V_3 -> V_78 ;
V_3 -> V_258 = ! V_180 || ! V_180 -> V_88 ;
if ( V_180 ) {
if ( V_180 -> V_167 )
V_190 = V_259 ;
else
V_190 = V_180 -> V_190 != 0 ?
V_180 -> V_190 : V_3 -> V_5 -> V_260 ;
} else
V_190 = V_3 -> V_5 -> V_260 ;
F_125 ( V_3 , V_190 ) ;
return 0 ;
}
static void F_126 ( struct V_2 * V_3 )
{
}
static void F_127 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_261 )
return;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
F_82 ( V_21 -> V_261 [ V_67 ] ) ;
V_21 -> V_261 [ V_67 ] = NULL ;
}
F_82 ( V_21 -> V_261 ) ;
V_21 -> V_261 = NULL ;
}
static int F_128 ( struct V_1 * V_21 )
{
int V_67 ;
if ( V_21 -> V_262 <= 0 )
return 0 ;
V_21 -> V_261 =
F_116 ( sizeof( * V_21 -> V_261 ) * V_21 -> V_236 ,
V_203 ) ;
if ( ! V_21 -> V_261 )
return - V_263 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
V_21 -> V_261 [ V_67 ] =
F_93 ( sizeof( * V_21 -> V_261 [ V_67 ] ) *
V_21 -> V_264 , V_203 ) ;
if ( ! V_21 -> V_261 [ V_67 ] )
goto V_265;
}
return 0 ;
V_265:
F_127 ( V_21 ) ;
return - V_263 ;
}
static void F_129 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_266 )
return;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
F_82 ( V_21 -> V_266 [ V_67 ] ) ;
V_21 -> V_266 [ V_67 ] = NULL ;
}
F_82 ( V_21 -> V_266 ) ;
V_21 -> V_266 = NULL ;
}
static int F_130 ( struct V_1 * V_21 )
{
int V_67 ;
if ( V_21 -> V_262 <= 0 )
return 0 ;
V_21 -> V_266 = F_116 ( sizeof( * V_21 -> V_266 ) * V_21 -> V_236 ,
V_203 ) ;
if ( ! V_21 -> V_266 )
return - V_263 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
V_21 -> V_266 [ V_67 ] = F_93 ( sizeof( * V_21 -> V_266 [ V_67 ] ) *
V_21 -> V_262 , V_203 ) ;
if ( ! V_21 -> V_266 [ V_67 ] )
goto V_265;
}
return 0 ;
V_265:
F_129 ( V_21 ) ;
return - V_263 ;
}
static int F_131 ( struct V_1 * V_21 ,
struct V_139 * V_131 , struct V_8 * V_9 )
{
struct V_267 * V_268 ;
T_5 V_269 ;
T_4 V_270 ;
V_268 = V_21 -> V_261 [ V_9 -> V_133 ] ;
V_270 = F_132 ( V_131 -> V_271 [ 0 ] . V_272 ) ;
V_269 = F_133 ( V_21 -> V_28 , V_268 , V_270 ,
V_273 ) ;
if ( F_134 ( & V_21 -> V_28 -> V_29 , V_269 ) ) {
V_131 -> V_271 -> V_274 = 0 ;
return - 1 ;
}
V_131 -> V_271 -> V_274 = F_135 ( V_269 ) ;
return 0 ;
}
static void F_136 ( struct V_1 * V_21 ,
struct V_139 * V_131 )
{
struct V_267 * V_275 ;
T_5 V_269 ;
T_4 V_270 ;
V_275 = V_131 -> V_271 ;
V_269 = F_137 ( V_275 -> V_274 ) ;
V_270 = F_132 ( V_131 -> V_271 [ 0 ] . V_272 ) ;
F_138 ( V_21 -> V_28 , V_269 , V_270 , V_273 ) ;
}
static int F_139 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_276 * V_275 , * V_268 ;
T_5 V_269 ;
T_4 V_277 ;
V_275 = & V_9 -> V_278 [ V_21 -> V_279 - 1 ] ;
V_268 = V_21 -> V_266 [ V_9 -> V_133 ] ;
V_275 -> V_280 = F_140 ( V_281 ) ;
V_277 = sizeof( * V_275 ) *
( F_98 ( V_9 -> V_124 . V_282 ) - V_21 -> V_279 ) ;
V_275 -> V_283 = F_140 ( V_277 ) ;
V_269 = F_133 ( V_21 -> V_28 , V_268 , V_277 ,
V_273 ) ;
if ( F_134 ( & V_21 -> V_28 -> V_29 , V_269 ) ) {
V_275 -> V_284 = F_135 ( 0 ) ;
return - 1 ;
}
V_275 -> V_284 = F_135 ( V_269 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_276 * V_275 ;
if ( F_98 ( V_9 -> V_124 . V_282 ) <= V_21 -> V_279 )
return;
V_275 = & V_9 -> V_278 [ V_21 -> V_279 - 1 ] ;
F_138 ( V_21 -> V_28 , F_137 ( V_275 -> V_284 ) ,
F_132 ( V_275 -> V_283 ) , V_273 ) ;
}
static int F_142 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
struct V_285 * V_286 ,
struct V_139 * V_287 ,
struct V_71 * V_29 )
{
int V_288 ;
int V_289 = 0 ;
T_4 V_290 = 0 ;
switch ( V_287 -> V_291 . V_292 ) {
case V_293 :
switch ( V_287 -> V_291 . V_48 ) {
case V_294 :
break;
case V_295 :
V_286 -> V_296 |= V_297 ;
if ( V_287 -> V_291 . V_298 !=
V_299 ) {
memset ( V_286 -> V_300 , 0 ,
V_301 ) ;
break;
}
V_288 = V_287 -> V_291 . V_14 ;
if ( V_288 > V_301 )
V_288 = V_301 ;
if ( V_288 > sizeof( V_287 -> V_291 . V_302 ) )
V_288 =
sizeof( V_287 -> V_291 . V_302 ) ;
memcpy ( V_286 -> V_300 ,
V_287 -> V_291 . V_302 , V_288 ) ;
V_289 = 1 ;
break;
case V_303 :
V_289 = 1 ;
break;
case V_304 :
V_289 = 1 ;
break;
case V_305 :
V_289 = 1 ;
break;
case V_306 :
V_289 = 1 ;
break;
default:
V_289 = 1 ;
break;
}
break;
case V_307 :
switch ( V_287 -> V_291 . V_48 ) {
case V_308 :
case V_309 :
case V_310 :
V_289 = 1 ;
break;
case V_311 :
V_286 -> V_296 = ( V_312 << 16 ) ;
V_286 -> V_296 |= ( V_313 << 8 ) ;
V_290 = F_143 (
& V_287 -> V_291 . V_314 [ 0 ] ) ;
F_144 ( V_286 , V_290 ) ;
break;
case V_315 :
case V_316 :
case V_317 :
if ( V_29 -> V_72 && V_29 -> V_88 ) {
V_286 -> V_296 = V_318 << 16 ;
V_29 -> V_191 = 1 ;
V_21 -> V_250 = 1 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_73 , V_242 ) ;
} else
V_289 = 1 ;
break;
default:
V_289 = 1 ;
}
break;
case V_319 :
break;
case V_320 :
break;
case V_321 :
V_289 = 1 ;
break;
case V_322 :
break;
default:
V_289 = 1 ;
break;
}
return V_289 ;
}
static void F_145 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
bool V_323 = false ;
V_9 -> V_10 = V_11 ;
F_146 () ;
if ( V_9 -> V_12 ) {
unsigned long V_76 ;
struct V_71 * V_29 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_29 = V_9 -> V_12 ;
if ( V_29 && F_59 ( & V_29 -> V_324 ) )
V_323 = true ;
V_9 -> V_12 = NULL ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
if ( V_323 )
F_147 ( & V_21 -> V_325 ) ;
}
static void F_148 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
F_145 ( V_21 , V_9 ) ;
F_149 ( V_21 , V_9 ) ;
}
static void F_150 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_285 * V_286 )
{
F_148 ( V_21 , V_9 ) ;
if ( V_286 && V_286 -> V_326 )
V_286 -> V_326 ( V_286 ) ;
}
static void F_151 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
F_152 ( & V_9 -> V_327 , V_328 ) ;
F_153 ( F_50 () , V_21 -> V_329 , & V_9 -> V_327 ) ;
}
static void F_154 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_285 * V_286 ,
struct V_71 * V_29 )
{
struct V_139 * V_287 = & V_21 -> V_137 [ V_9 -> V_133 ] ;
if ( F_49 ( V_287 -> V_291 . V_292 == 0 &&
V_287 -> V_291 . V_48 == 0 ) )
return F_150 ( V_21 , V_9 , V_286 ) ;
if ( F_31 ( V_29 ) &&
V_287 -> V_291 . V_292 ==
V_307 ) {
if ( V_287 -> V_291 . V_48 ==
V_317 ) {
V_29 -> V_89 = 0 ;
V_29 -> V_183 = 0 ;
}
return F_151 ( V_21 , V_9 ) ;
}
if ( F_142 ( V_21 , V_9 , V_286 , V_287 , V_29 ) )
return F_151 ( V_21 , V_9 ) ;
return F_150 ( V_21 , V_9 , V_286 ) ;
}
static int F_155 ( struct V_1 * V_21 ,
struct V_8 * V_131 )
{
T_1 V_330 = V_131 -> V_23 -> V_37 ;
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
F_9 ( & V_21 -> V_28 -> V_29 , L_74 ,
V_330 ) ;
break;
}
return - V_330 ;
}
static void F_156 ( struct V_8 * V_131 )
{
struct V_285 * V_286 ;
struct V_1 * V_21 ;
struct V_338 * V_339 ;
struct V_71 * V_29 ;
struct V_139 * V_287 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
unsigned long V_340 ;
V_339 = V_131 -> V_23 ;
V_286 = V_131 -> V_10 ;
V_21 = V_131 -> V_21 ;
if ( ! V_286 -> V_41 ) {
V_286 -> V_296 = V_318 << 16 ;
return F_150 ( V_21 , V_131 , V_286 ) ;
}
V_29 = V_286 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_286 -> V_296 = V_318 << 16 ;
return F_150 ( V_21 , V_131 , V_286 ) ;
}
V_287 = & V_21 -> V_137 [ V_131 -> V_133 ] ;
F_157 ( V_286 ) ;
if ( ( V_131 -> V_150 == V_341 ) &&
( F_98 ( V_131 -> V_124 . V_282 ) > V_21 -> V_279 ) )
F_141 ( V_21 , V_131 ) ;
if ( ( V_131 -> V_150 == V_154 ) &&
( V_287 -> V_271 [ 0 ] . V_342 == V_343 ) )
F_136 ( V_21 , V_287 ) ;
V_286 -> V_296 = ( V_312 << 16 ) ;
V_286 -> V_296 |= ( V_313 << 8 ) ;
if ( V_131 -> V_150 == V_154 || V_131 -> V_150 == V_151 ) {
if ( V_29 -> V_72 && V_29 -> V_88 &&
V_29 -> V_191 ) {
V_286 -> V_296 = V_318 << 16 ;
return F_150 ( V_21 , V_131 , V_286 ) ;
}
if ( F_49 ( V_131 -> V_235 != NULL ) )
F_47 ( & V_131 -> V_235 -> V_257 ) ;
}
if ( F_46 ( V_339 -> V_35 == V_344 ) ) {
V_286 -> V_296 = V_318 << 16 ;
return F_150 ( V_21 , V_131 , V_286 ) ;
}
if ( ( F_46 ( F_5 ( V_131 ) ) ) )
if ( V_131 -> V_12 )
return F_150 ( V_21 , V_131 , V_286 ) ;
if ( V_131 -> V_150 == V_154 )
return F_154 ( V_21 , V_131 , V_286 , V_29 ) ;
F_144 ( V_286 , V_339 -> V_345 ) ;
if ( V_339 -> V_35 == 0 )
return F_150 ( V_21 , V_131 , V_286 ) ;
if ( V_131 -> V_150 == V_151 ) {
struct V_130 * V_9 = & V_21 -> V_132 [ V_131 -> V_133 ] ;
V_131 -> V_124 . V_125 = F_158 ( V_286 ) ;
V_131 -> V_124 . V_282 = F_159 ( V_131 -> V_124 . V_125 ) ;
V_131 -> V_144 . V_346 = F_98 ( V_9 -> V_347 ) &
V_348 ;
V_131 -> V_124 . V_349 = V_9 -> V_349 ;
memcpy ( V_131 -> V_124 . V_350 . V_351 , V_9 -> V_352 , 8 ) ;
memcpy ( V_131 -> V_144 . V_145 , V_9 -> V_145 , V_131 -> V_144 . V_346 ) ;
if ( F_31 ( V_29 ) ) {
if ( V_339 -> V_35 == V_353 )
V_29 -> V_89 = 0 ;
return F_151 ( V_21 , V_131 ) ;
}
}
switch ( V_339 -> V_35 ) {
case V_36 :
V_286 -> V_296 |= V_339 -> V_37 ;
if ( V_301 < sizeof( V_339 -> V_25 ) )
V_340 = V_301 ;
else
V_340 = sizeof( V_339 -> V_25 ) ;
if ( V_339 -> V_24 < V_340 )
V_340 = V_339 -> V_24 ;
memcpy ( V_286 -> V_300 , V_339 -> V_25 , V_340 ) ;
if ( V_339 -> V_37 )
F_6 ( V_339 -> V_25 , V_340 ,
& V_15 , & V_16 , & V_17 ) ;
if ( V_339 -> V_37 == V_297 ) {
if ( V_15 == V_354 ) {
V_286 -> V_296 |= V_355 << 16 ;
break;
}
break;
}
if ( V_339 -> V_37 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_75
L_76
L_77 ,
V_131 , V_339 -> V_37 ,
V_15 , V_16 , V_17 ,
V_286 -> V_296 ) ;
} else {
F_9 ( & V_21 -> V_28 -> V_29 , L_78
L_79 , V_131 ) ,
V_286 -> V_296 = V_318 << 16 ;
}
break;
case V_356 :
break;
case V_357 :
F_9 ( & V_21 -> V_28 -> V_29 ,
L_80 , V_131 -> V_144 . V_145 ) ;
break;
case V_358 : {
V_286 -> V_296 = V_318 << 16 ;
}
break;
case V_359 :
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_81 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_361 :
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_82 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_362 :
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_83 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_363 :
V_286 -> V_296 = V_364 << 16 ;
break;
case V_365 :
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_84 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_366 :
V_286 -> V_296 = V_355 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_85 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_367 :
V_286 -> V_296 = V_368 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_86 ,
V_131 -> V_144 . V_145 ) ;
break;
case V_369 :
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_87 ) ;
break;
case V_370 :
if ( F_155 ( V_21 , V_131 ) )
V_286 -> V_296 = V_360 << 16 ;
break;
case V_353 :
V_286 -> V_296 = V_355 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_88 , V_131 ) ;
break;
default:
V_286 -> V_296 = V_360 << 16 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_89 ,
V_131 , V_339 -> V_35 ) ;
}
return F_150 ( V_21 , V_131 , V_286 ) ;
}
static void F_160 ( struct V_371 * V_28 ,
struct V_8 * V_9 , int V_372 , int V_373 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_372 ; V_67 ++ )
F_138 ( V_28 , ( V_374 ) F_137 ( V_9 -> V_278 [ V_67 ] . V_284 ) ,
F_132 ( V_9 -> V_278 [ V_67 ] . V_283 ) ,
V_373 ) ;
}
static int F_161 ( struct V_371 * V_28 ,
struct V_8 * V_131 ,
unsigned char * V_44 ,
T_3 V_375 ,
int V_373 )
{
T_5 V_376 ;
if ( V_375 == 0 || V_373 == V_377 ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_282 = F_159 ( 0 ) ;
return 0 ;
}
V_376 = F_133 ( V_28 , V_44 , V_375 , V_373 ) ;
if ( F_134 ( & V_28 -> V_29 , V_376 ) ) {
V_131 -> V_124 . V_125 = 0 ;
V_131 -> V_124 . V_282 = F_159 ( 0 ) ;
return - 1 ;
}
V_131 -> V_278 [ 0 ] . V_284 = F_135 ( V_376 ) ;
V_131 -> V_278 [ 0 ] . V_283 = F_140 ( V_375 ) ;
V_131 -> V_278 [ 0 ] . V_280 = F_140 ( V_378 ) ;
V_131 -> V_124 . V_125 = 1 ;
V_131 -> V_124 . V_282 = F_159 ( 1 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_113 , unsigned long V_379 )
{
F_163 ( V_380 ) ;
V_9 -> V_381 = & V_380 ;
F_60 ( V_21 , V_9 , V_113 ) ;
if ( V_379 == V_382 ) {
F_164 ( & V_380 ) ;
return V_383 ;
}
if ( ! F_165 ( & V_380 ,
F_166 ( V_379 ) ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_90 ) ;
return - V_384 ;
}
return V_383 ;
}
static int F_167 ( struct V_1 * V_21 , struct V_8 * V_9 ,
int V_113 , unsigned long V_379 )
{
if ( F_46 ( F_13 ( V_21 ) ) ) {
V_9 -> V_23 -> V_35 = V_344 ;
return V_383 ;
}
return F_162 ( V_21 , V_9 , V_113 , V_379 ) ;
}
static T_4 F_13 ( struct V_1 * V_21 )
{
int V_385 ;
T_4 V_20 , * F_13 ;
V_385 = F_168 () ;
F_13 = F_169 ( V_21 -> F_13 , V_385 ) ;
V_20 = * F_13 ;
F_170 () ;
return V_20 ;
}
static int F_171 ( struct V_1 * V_21 ,
struct V_8 * V_9 , int V_373 , unsigned long V_379 )
{
int V_386 = 10 , V_387 = 0 ;
int V_20 ;
do {
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_20 = F_167 ( V_21 , V_9 , V_127 ,
V_379 ) ;
if ( V_20 )
break;
V_387 ++ ;
if ( V_387 > 3 ) {
F_109 ( V_386 ) ;
if ( V_386 < 1000 )
V_386 *= 2 ;
}
} while ( ( F_8 ( V_21 , V_9 ) ||
F_10 ( V_21 , V_9 ) ) &&
V_387 <= V_388 );
F_160 ( V_21 -> V_28 , V_9 , 1 , V_373 ) ;
if ( V_387 > V_388 )
V_20 = - V_389 ;
return V_20 ;
}
static void F_172 ( struct V_1 * V_21 , char * V_390 ,
struct V_8 * V_9 )
{
const T_1 * V_141 = V_9 -> V_144 . V_145 ;
const T_1 * V_103 = V_9 -> V_124 . V_350 . V_351 ;
F_9 ( & V_21 -> V_28 -> V_29 , L_91 ,
V_390 , V_103 , V_141 ) ;
}
static void F_173 ( struct V_1 * V_21 ,
struct V_8 * V_131 )
{
const struct V_338 * V_339 = V_131 -> V_23 ;
struct V_41 * V_391 = & V_131 -> V_21 -> V_28 -> V_29 ;
T_1 V_15 , V_16 , V_17 ;
int V_22 ;
switch ( V_339 -> V_35 ) {
case V_36 :
if ( V_339 -> V_24 > sizeof( V_339 -> V_25 ) )
V_22 = sizeof( V_339 -> V_25 ) ;
else
V_22 = V_339 -> V_24 ;
F_6 ( V_339 -> V_25 , V_22 ,
& V_15 , & V_16 , & V_17 ) ;
F_172 ( V_21 , L_92 , V_131 ) ;
if ( V_339 -> V_37 == V_297 )
F_9 ( V_391 , L_93 ,
V_15 , V_16 , V_17 ) ;
else
F_9 ( V_391 , L_94 , V_339 -> V_37 ) ;
if ( V_339 -> V_37 == 0 )
F_9 ( V_391 , L_95
L_96
L_97
L_98 ) ;
break;
case V_356 :
break;
case V_357 :
F_172 ( V_21 , L_99 , V_131 ) ;
break;
case V_358 : {
F_172 ( V_21 , L_100 , V_131 ) ;
F_9 ( V_391 , L_101 ) ;
}
break;
case V_359 :
F_172 ( V_21 , L_102 , V_131 ) ;
break;
case V_361 :
F_172 ( V_21 , L_103 , V_131 ) ;
break;
case V_362 :
F_172 ( V_21 , L_104 , V_131 ) ;
break;
case V_363 :
F_172 ( V_21 , L_105 , V_131 ) ;
break;
case V_365 :
F_172 ( V_21 , L_106 , V_131 ) ;
break;
case V_366 :
F_172 ( V_21 , L_107 , V_131 ) ;
break;
case V_367 :
F_172 ( V_21 , L_108 , V_131 ) ;
break;
case V_369 :
F_172 ( V_21 , L_109 , V_131 ) ;
break;
case V_344 :
F_172 ( V_21 , L_110 , V_131 ) ;
break;
default:
F_172 ( V_21 , L_111 , V_131 ) ;
F_9 ( V_391 , L_112 ,
V_339 -> V_35 ) ;
}
}
static int F_174 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_6 V_392 , unsigned char * V_44 ,
unsigned char V_393 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
if ( F_176 ( V_9 , V_394 , V_21 , V_44 , V_393 ,
V_392 , V_70 , V_395 ) ) {
V_20 = - 1 ;
goto V_396;
}
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_177 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_1 V_399 , int V_113 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
( void ) F_176 ( V_9 , V_399 , V_21 , NULL , 0 , 0 ,
V_70 , V_400 ) ;
V_20 = F_167 ( V_21 , V_9 , V_113 , V_382 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_113 ) ;
goto V_396;
}
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static bool F_106 ( struct V_1 * V_21 , struct V_8 * V_9 ,
struct V_71 * V_29 ,
unsigned char * V_70 )
{
int V_67 ;
bool V_401 = false ;
struct V_139 * V_287 = & V_21 -> V_137 [ V_9 -> V_133 ] ;
struct V_136 * V_402 = (struct V_136 * ) V_287 ;
if ( F_4 ( V_9 ) )
return false ;
switch ( V_9 -> V_150 ) {
case V_341 :
case V_403 :
V_401 = ! memcmp ( V_70 , & V_9 -> V_124 . V_350 . V_351 ,
sizeof( V_9 -> V_124 . V_350 . V_351 ) ) ;
break;
case V_151 :
case V_154 :
if ( V_9 -> V_235 == V_29 ) {
V_401 = true ;
} else {
for ( V_67 = 0 ; V_67 < V_29 -> V_234 && ! V_401 ; V_67 ++ ) {
V_401 = V_29 -> V_235 [ V_67 ] == V_9 -> V_235 ;
}
}
break;
case V_156 :
for ( V_67 = 0 ; V_67 < V_29 -> V_234 && ! V_401 ; V_67 ++ ) {
V_401 = V_29 -> V_235 [ V_67 ] -> V_187 ==
F_132 ( V_402 -> V_404 ) ;
}
break;
case 0 :
V_401 = false ;
break;
default:
F_75 ( & V_21 -> V_28 -> V_29 , L_114 ,
V_9 -> V_150 ) ;
F_178 () ;
}
return V_401 ;
}
static int F_179 ( struct V_1 * V_21 , struct V_71 * V_29 ,
unsigned char * V_70 , T_1 V_399 , int V_113 )
{
int V_67 ;
int V_20 = 0 ;
if ( F_180 ( & V_21 -> V_405 ) == - V_406 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_115 ) ;
return - V_406 ;
}
F_77 ( F_21 ( & V_29 -> V_324 ) != 0 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_238 + V_67 ;
int V_239 = F_105 ( & V_9 -> V_239 ) ;
if ( V_239 > 1 && F_106 ( V_21 , V_9 , V_29 , V_70 ) ) {
unsigned long V_76 ;
V_9 -> V_12 = V_29 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! F_4 ( V_9 ) )
F_57 ( & V_29 -> V_324 ) ;
else
V_9 -> V_12 = NULL ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
F_107 ( V_21 , V_9 ) ;
}
V_20 = F_177 ( V_21 , V_70 , V_399 , V_113 ) ;
if ( ! V_20 )
F_181 ( V_21 -> V_325 ,
F_21 ( & V_29 -> V_324 ) == 0 ||
F_13 ( V_21 ) ) ;
if ( F_46 ( F_13 ( V_21 ) ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_116 ) ;
V_20 = - V_79 ;
}
if ( F_46 ( V_20 ) )
F_123 ( & V_29 -> V_324 , 0 ) ;
else
V_20 = F_182 ( V_21 , V_70 , 0 ) ;
F_183 ( & V_21 -> V_405 ) ;
return V_20 ;
}
static void F_184 ( struct V_1 * V_21 ,
unsigned char * V_70 , unsigned char * V_81 )
{
int V_20 ;
unsigned char * V_44 ;
* V_81 = V_82 ;
V_44 = F_116 ( 64 , V_203 ) ;
if ( ! V_44 )
return;
if ( ! F_185 ( V_21 , V_70 ,
V_407 ) )
goto exit;
V_20 = F_174 ( V_21 , V_70 , V_408 |
V_407 , V_44 , 64 ) ;
if ( V_20 == 0 )
* V_81 = V_44 [ 8 ] ;
if ( * V_81 > V_82 )
* V_81 = V_82 ;
exit:
F_82 ( V_44 ) ;
return;
}
static void F_186 ( struct V_1 * V_21 , int V_20 ,
struct V_220 * V_409 )
{
struct V_222 * V_223 = & V_409 -> V_224 [ 0 ] ;
int V_221 , V_410 , V_411 ;
T_6 V_412 , V_229 , V_413 ;
if ( V_20 != 0 )
return;
if ( V_21 -> V_57 < 2 )
return;
F_96 ( & V_21 -> V_28 -> V_29 , L_117 ,
F_132 ( V_409 -> V_414 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_118 ,
F_132 ( V_409 -> V_415 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_119 ,
F_137 ( V_409 -> V_416 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_120 ,
V_409 -> V_417 ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_121 ,
V_409 -> V_418 ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_122 ,
F_98 ( V_409 -> V_419 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_123 ,
F_137 ( V_409 -> V_420 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_124 ,
F_137 ( V_409 -> V_421 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_125 ,
F_98 ( V_409 -> V_226 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_126 ,
F_98 ( V_409 -> V_227 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_127 ,
F_98 ( V_409 -> V_229 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_128 ,
F_98 ( V_409 -> V_230 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_129 ,
F_98 ( V_409 -> V_76 ) ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_130 ,
F_98 ( V_409 -> V_76 ) &
V_422 ? L_131 : L_132 ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_133 ,
F_98 ( V_409 -> V_423 ) ) ;
V_412 = F_98 ( V_409 -> V_230 ) ;
for ( V_221 = 0 ; V_221 < V_412 ; V_221 ++ ) {
F_96 ( & V_21 -> V_28 -> V_29 , L_134 , V_221 ) ;
V_229 = F_98 ( V_409 -> V_229 ) ;
for ( V_410 = 0 ; V_410 < V_229 ; V_410 ++ ) {
F_96 ( & V_21 -> V_28 -> V_29 , L_135 , V_410 ) ;
V_413 =
F_98 ( V_409 -> V_226 ) ;
for ( V_411 = 0 ; V_411 < V_413 ; V_411 ++ , V_223 ++ )
F_96 ( & V_21 -> V_28 -> V_29 ,
L_136 ,
V_411 , V_223 -> V_187 ,
V_223 -> V_424 [ 0 ] , V_223 -> V_424 [ 1 ] ) ;
V_413 =
F_98 ( V_409 -> V_227 ) ;
for ( V_411 = 0 ; V_411 < V_413 ; V_411 ++ , V_223 ++ )
F_96 ( & V_21 -> V_28 -> V_29 ,
L_137 ,
V_411 , V_223 -> V_187 ,
V_223 -> V_424 [ 0 ] , V_223 -> V_424 [ 1 ] ) ;
}
}
}
static int F_187 ( struct V_1 * V_21 ,
unsigned char * V_70 , struct V_71 * V_425 )
{
int V_20 = 0 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
if ( F_176 ( V_9 , V_426 , V_21 , & V_425 -> V_186 ,
sizeof( V_425 -> V_186 ) , 0 ,
V_70 , V_395 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_138 ) ;
F_107 ( V_21 , V_9 ) ;
return - 1 ;
}
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
goto V_396;
}
F_107 ( V_21 , V_9 ) ;
if ( F_132 ( V_425 -> V_186 . V_414 ) >
sizeof( V_425 -> V_186 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_139 ) ;
V_20 = - 1 ;
}
F_186 ( V_21 , V_20 , & V_425 -> V_186 ) ;
return V_20 ;
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_188 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_6 V_427 ,
struct V_428 * V_44 , T_3 V_393 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
V_20 = F_176 ( V_9 , V_429 , V_21 , V_44 , V_393 ,
0 , V_158 , V_395 ) ;
if ( V_20 )
goto V_396;
V_9 -> V_144 . V_145 [ 2 ] = V_427 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_427 >> 8 ) & 0xff ;
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_189 ( struct V_1 * V_21 ,
struct V_430 * V_44 , T_3 V_393 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
V_20 = F_176 ( V_9 , V_431 , V_21 , V_44 , V_393 ,
0 , V_158 , V_395 ) ;
if ( V_20 )
goto V_396;
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_190 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_6 V_427 ,
struct V_432 * V_44 , T_3 V_393 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
V_20 = F_176 ( V_9 , V_433 , V_21 , V_44 , V_393 ,
0 , V_158 , V_395 ) ;
if ( V_20 )
goto V_396;
V_9 -> V_144 . V_145 [ 2 ] = V_427 & 0xff ;
V_9 -> V_144 . V_145 [ 9 ] = ( V_427 >> 8 ) & 0xff ;
F_171 ( V_21 , V_9 , V_397 ,
V_398 ) ;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - 1 ;
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static void F_191 ( struct V_1 * V_21 ,
unsigned char * V_70 ,
struct V_434 * V_435 , int V_436 ,
struct V_71 * V_437 )
{
int V_20 = - 1 ;
struct V_8 * V_9 = NULL ;
struct V_338 * V_339 = NULL ;
struct V_438 * V_439 = NULL ;
struct V_432 * V_440 = NULL ;
struct V_441 * V_442 = & V_435 -> V_350 [ V_436 ] ;
T_6 V_427 = 0 ;
V_427 = F_192 ( & V_442 -> V_84 [ 0 ] ) ;
if ( V_437 -> V_102 == - 1 || V_437 -> V_103 == - 1 ) {
V_20 = V_383 ;
goto V_396;
}
if ( V_427 == 0xFF00 || F_193 ( & V_442 -> V_84 [ 0 ] ) ) {
V_20 = V_383 ;
goto V_396;
}
V_439 = F_116 ( sizeof( * V_439 ) , V_203 ) ;
if ( ! V_439 )
goto V_396;
V_440 = F_116 ( sizeof( * V_440 ) , V_203 ) ;
if ( ! V_440 )
goto V_396;
V_20 = F_190 ( V_21 , V_70 , V_427 ,
V_440 , sizeof( * V_440 ) ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_140 ,
V_242 , V_437 -> V_167 , V_427 ) ;
goto V_396;
}
V_9 = F_175 ( V_21 ) ;
V_20 = F_176 ( V_9 , V_443 , V_21 , V_439 ,
sizeof( * V_439 ) , 0 , V_158 , V_395 ) ;
if ( V_20 )
goto V_396;
if ( V_440 -> V_95 [ 1 ] == 'E' )
V_9 -> V_144 . V_145 [ 5 ] = V_440 -> V_444 ;
else
V_9 -> V_144 . V_145 [ 5 ] = 0 ;
V_20 = F_171 ( V_21 , V_9 , V_397 ,
V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 && V_339 -> V_35 != V_356 ) {
V_20 = - 1 ;
goto V_396;
}
V_437 -> V_91 [ V_440 -> V_445 ] = V_439 -> V_446 ;
memcpy ( & V_437 -> V_95 [ V_440 -> V_445 ] ,
V_439 -> V_95 , sizeof( V_439 -> V_95 ) ) ;
V_20 = V_383 ;
V_396:
F_82 ( V_439 ) ;
F_82 ( V_440 ) ;
if ( V_9 )
F_107 ( V_21 , V_9 ) ;
if ( V_20 != V_383 )
F_71 ( V_182 , V_21 , V_437 ,
L_141 ) ;
}
static T_5 F_194 ( struct V_1 * V_21 ,
unsigned char * V_70 )
{
struct V_434 * V_447 ;
T_4 V_448 ;
T_5 V_449 = 0 ;
int V_67 ;
V_447 = F_116 ( sizeof( * V_447 ) , V_203 ) ;
if ( ! V_447 )
return 0 ;
if ( F_195 ( V_21 , V_447 , sizeof( * V_447 ) ) ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_142 ) ;
F_82 ( V_447 ) ;
return 0 ;
}
V_448 = F_196 ( V_447 -> V_450 ) / 24 ;
for ( V_67 = 0 ; V_67 < V_448 ; V_67 ++ )
if ( ! memcmp ( & V_447 -> V_350 [ V_67 ] . V_84 [ 0 ] , V_70 , 8 ) ) {
V_449 = F_197 ( & V_447 -> V_350 [ V_67 ] . V_451 [ 0 ] ) ;
break;
}
F_82 ( V_447 ) ;
return V_449 ;
}
static void F_198 ( struct V_1 * V_21 , unsigned char * V_70 ,
struct V_71 * V_29 )
{
int V_20 ;
T_5 V_449 = 0 ;
if ( F_64 ( V_70 ) ) {
struct V_428 * V_452 ;
V_452 = F_116 ( sizeof( * V_452 ) , V_203 ) ;
if ( ! V_452 )
return;
V_20 = F_188 ( V_21 ,
V_70 , 0 , V_452 , sizeof( * V_452 ) ) ;
if ( V_20 == 0 ) {
V_449 = F_197 ( V_452 -> V_453 ) ;
V_21 -> V_87 = V_449 ;
}
F_82 ( V_452 ) ;
} else
V_449 = F_194 ( V_21 , V_70 ) ;
V_29 -> V_87 = V_449 ;
}
static bool F_185 ( struct V_1 * V_21 ,
unsigned char V_70 [] , T_1 V_392 )
{
int V_20 ;
int V_67 ;
int V_454 ;
unsigned char * V_44 , V_393 ;
V_44 = F_116 ( 256 , V_203 ) ;
if ( ! V_44 )
return false ;
V_20 = F_174 ( V_21 , V_70 ,
V_408 | V_455 ,
V_44 , V_456 ) ;
if ( V_20 != 0 )
goto V_457;
V_454 = V_44 [ 3 ] ;
if ( ( V_454 + V_456 ) <= 255 )
V_393 = V_454 + V_456 ;
else
V_393 = 255 ;
V_20 = F_174 ( V_21 , V_70 ,
V_408 | V_455 ,
V_44 , V_393 ) ;
if ( V_20 != 0 )
goto V_457;
V_454 = V_44 [ 3 ] ;
for ( V_67 = 1 ; V_67 <= V_454 ; V_67 ++ )
if ( V_44 [ 3 + V_67 ] == V_392 )
goto V_458;
V_457:
F_82 ( V_44 ) ;
return false ;
V_458:
F_82 ( V_44 ) ;
return true ;
}
static void F_199 ( struct V_1 * V_21 ,
unsigned char * V_70 , struct V_71 * V_425 )
{
int V_20 ;
unsigned char * V_44 ;
T_1 V_459 ;
V_425 -> V_174 = 0 ;
V_425 -> V_89 = 0 ;
V_425 -> V_183 = 0 ;
V_44 = F_116 ( 64 , V_203 ) ;
if ( ! V_44 )
return;
if ( ! F_185 ( V_21 , V_70 , V_460 ) )
goto V_396;
V_20 = F_174 ( V_21 , V_70 ,
V_408 | V_460 , V_44 , 64 ) ;
if ( V_20 != 0 )
goto V_396;
#define F_200 4
#define F_201 0x01
#define F_202 0x02
V_459 = V_44 [ F_200 ] ;
V_425 -> V_174 =
! ! ( V_459 & F_201 ) ;
if ( V_425 -> V_174 ) {
V_425 -> V_89 =
! ! ( V_459 & F_202 ) ;
if ( F_187 ( V_21 , V_70 , V_425 ) )
V_425 -> V_89 = 0 ;
}
V_425 -> V_183 = V_425 -> V_89 ;
V_396:
F_82 ( V_44 ) ;
return;
}
static int F_203 ( struct V_1 * V_21 , unsigned char * V_70 ,
unsigned char * V_86 , int V_199 , int V_375 )
{
int V_20 ;
unsigned char * V_44 ;
if ( ! F_185 ( V_21 , V_70 , V_461 ) )
return 1 ;
V_44 = F_116 ( 64 , V_203 ) ;
if ( ! V_44 )
return - V_263 ;
V_20 = F_174 ( V_21 , V_70 , V_408 |
V_461 , V_44 , 64 ) ;
if ( V_20 == 0 ) {
if ( V_375 > 16 )
V_375 = 16 ;
memcpy ( V_86 , & V_44 [ 8 ] , V_375 ) ;
}
F_82 ( V_44 ) ;
return V_20 ;
}
static int F_204 ( struct V_1 * V_21 , int V_462 ,
void * V_44 , int V_393 ,
int V_463 )
{
int V_20 = V_383 ;
struct V_8 * V_9 ;
unsigned char V_70 [ 8 ] ;
struct V_338 * V_339 ;
V_9 = F_175 ( V_21 ) ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
if ( F_176 ( V_9 , V_462 ? V_464 : V_465 , V_21 ,
V_44 , V_393 , 0 , V_70 , V_395 ) ) {
V_20 = - V_466 ;
goto V_396;
}
if ( V_463 )
V_9 -> V_144 . V_145 [ 1 ] = V_463 ;
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( V_20 )
goto V_396;
V_339 = V_9 -> V_23 ;
if ( V_339 -> V_35 != 0 &&
V_339 -> V_35 != V_356 ) {
F_173 ( V_21 , V_9 ) ;
V_20 = - V_389 ;
} else {
struct V_467 * V_468 = V_44 ;
if ( V_468 -> V_469 != V_463 ) {
if ( ! V_21 -> V_109 ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_143 ,
V_463 ,
V_468 -> V_469 ) ;
V_20 = - V_54 ;
} else
V_20 = - V_470 ;
}
}
V_396:
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static inline int F_195 ( struct V_1 * V_21 ,
struct V_434 * V_44 , int V_393 )
{
int V_20 ;
struct V_467 * V_471 ;
V_20 = F_204 ( V_21 , 0 , V_44 , V_393 ,
V_472 ) ;
if ( ! V_20 || V_20 != - V_470 )
return V_20 ;
V_471 = F_116 ( sizeof( * V_471 ) , V_203 ) ;
if ( ! V_471 )
return - V_263 ;
V_20 = F_204 ( V_21 , 0 , V_471 , sizeof( * V_471 ) , 0 ) ;
if ( ! V_20 ) {
int V_67 ;
T_4 V_473 ;
memcpy ( V_44 , V_471 , 8 ) ;
V_473 = F_205 ( * ( ( V_474 * ) V_471 -> V_450 ) ) / 8 ;
for ( V_67 = 0 ; V_67 < V_473 ; V_67 ++ )
memcpy ( V_44 -> V_350 [ V_67 ] . V_84 , V_471 -> V_350 [ V_67 ] , 8 ) ;
}
F_82 ( V_471 ) ;
return V_20 ;
}
static inline int F_206 ( struct V_1 * V_21 ,
struct V_467 * V_44 , int V_393 )
{
return F_204 ( V_21 , 1 , V_44 , V_393 , 0 ) ;
}
static inline void F_207 ( struct V_71 * V_41 ,
int V_101 , int V_102 , int V_103 )
{
V_41 -> V_101 = V_101 ;
V_41 -> V_102 = V_102 ;
V_41 -> V_103 = V_103 ;
}
static int F_208 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
int V_20 ;
int V_48 ;
int V_475 ;
unsigned char * V_44 ;
V_44 = F_116 ( 64 , V_203 ) ;
if ( ! V_44 )
return V_206 ;
if ( ! F_185 ( V_21 , V_70 , V_476 ) )
goto V_477;
V_20 = F_174 ( V_21 , V_70 , V_408 | V_476 ,
V_44 , V_456 ) ;
if ( V_20 != 0 )
goto V_477;
V_475 = V_44 [ 3 ] ;
V_20 = F_174 ( V_21 , V_70 , V_408 | V_476 ,
V_44 , V_475 + V_456 ) ;
if ( V_20 != 0 )
goto V_477;
V_48 = V_44 [ 4 ] ;
F_82 ( V_44 ) ;
return V_48 ;
V_477:
F_82 ( V_44 ) ;
return V_206 ;
}
static unsigned char F_209 ( struct V_1 * V_21 ,
unsigned char V_70 [] )
{
struct V_8 * V_9 ;
unsigned char * V_478 ;
T_1 V_15 , V_16 , V_17 ;
int V_22 ;
int V_20 , V_479 = 0 ;
T_6 V_480 ;
T_1 V_481 ;
#define F_210 0x04
#define F_211 0x04
#define F_212 0x02
V_9 = F_175 ( V_21 ) ;
( void ) F_176 ( V_9 , V_482 , V_21 , NULL , 0 , 0 , V_70 , V_395 ) ;
V_20 = F_167 ( V_21 , V_9 , V_127 ,
V_398 ) ;
if ( V_20 ) {
F_107 ( V_21 , V_9 ) ;
return V_206 ;
}
V_478 = V_9 -> V_23 -> V_25 ;
if ( V_9 -> V_23 -> V_24 > sizeof( V_9 -> V_23 -> V_25 ) )
V_22 = sizeof( V_9 -> V_23 -> V_25 ) ;
else
V_22 = V_9 -> V_23 -> V_24 ;
F_6 ( V_478 , V_22 , & V_15 , & V_16 , & V_17 ) ;
V_480 = V_9 -> V_23 -> V_35 ;
V_481 = V_9 -> V_23 -> V_37 ;
F_107 ( V_21 , V_9 ) ;
V_479 = F_208 ( V_21 , V_70 ) ;
switch ( V_479 ) {
case V_483 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
return V_479 ;
case V_206 :
if ( ( V_17 == F_211 ) ||
( V_17 == F_212 ) )
return V_479 ;
break;
default:
break;
}
return V_207 ;
}
static int F_213 ( struct V_1 * V_21 ,
unsigned char V_70 [] , struct V_71 * V_425 ,
unsigned char * V_484 )
{
#define F_214 43
#define F_215 "$DR-10"
#define F_216 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_217 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_485 ;
unsigned char * V_486 ;
int V_20 = 0 ;
V_485 = F_116 ( F_217 , V_203 ) ;
if ( ! V_485 ) {
V_20 = - V_263 ;
goto V_487;
}
if ( F_174 ( V_21 , V_70 , 0 , V_485 ,
( unsigned char ) F_217 ) != 0 ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_144 ,
V_242 ) ;
V_20 = V_488 ;
goto V_487;
}
F_218 ( & V_485 [ 8 ] , 8 ) ;
F_218 ( & V_485 [ 16 ] , 16 ) ;
V_425 -> V_104 = ( V_485 [ 0 ] & 0x1f ) ;
memcpy ( V_425 -> V_70 , V_70 , 8 ) ;
memcpy ( V_425 -> V_172 , & V_485 [ 8 ] ,
sizeof( V_425 -> V_172 ) ) ;
memcpy ( V_425 -> V_173 , & V_485 [ 16 ] ,
sizeof( V_425 -> V_173 ) ) ;
V_425 -> V_489 = V_485 [ 2 ] ;
memset ( V_425 -> V_86 , 0 ,
sizeof( V_425 -> V_86 ) ) ;
if ( F_203 ( V_21 , V_70 , V_425 -> V_86 , 8 ,
sizeof( V_425 -> V_86 ) ) < 0 )
F_75 ( & V_21 -> V_28 -> V_29 ,
L_145 ,
V_21 -> V_108 , V_242 ,
V_21 -> V_58 -> V_100 ,
V_425 -> V_102 , V_425 -> V_103 ,
F_42 ( V_425 -> V_104 ) ,
V_425 -> V_173 ) ;
if ( ( V_425 -> V_104 == V_106 ||
V_425 -> V_104 == V_107 ) &&
F_30 ( V_70 ) ) {
unsigned char V_200 ;
F_184 ( V_21 , V_70 , & V_425 -> V_81 ) ;
if ( V_21 -> V_490 & V_491 )
F_199 ( V_21 , V_70 , V_425 ) ;
V_200 = F_209 ( V_21 , V_70 ) ;
if ( V_200 == V_206 &&
V_21 -> V_109 ) {
F_96 ( & V_21 -> V_28 -> V_29 ,
L_146 ,
V_425 -> V_102 , V_425 -> V_103 ) ;
V_200 = 0 ;
}
V_425 -> V_200 = V_200 ;
if ( V_200 == V_483 ) {
V_20 = V_483 ;
F_75 ( & V_21 -> V_28 -> V_29 ,
L_147 ,
V_242 ) ;
goto V_487;
}
} else {
V_425 -> V_81 = V_82 ;
V_425 -> V_174 = 0 ;
V_425 -> V_89 = 0 ;
V_425 -> V_183 = 0 ;
V_425 -> V_188 = 0 ;
V_425 -> V_200 = 0 ;
V_425 -> V_190 = V_21 -> V_236 ;
}
if ( V_425 -> V_167 )
V_425 -> V_190 = V_259 ;
if ( V_484 ) {
V_486 = & V_485 [ F_214 ] ;
* V_484 = ( V_425 -> V_104 == V_169 &&
strncmp ( V_486 , F_215 ,
F_216 ) == 0 ) ;
}
F_82 ( V_485 ) ;
return 0 ;
V_487:
F_82 ( V_485 ) ;
return V_20 ;
}
static void F_219 ( struct V_1 * V_21 ,
T_1 * V_492 , struct V_71 * V_41 )
{
T_4 V_84 = F_143 ( V_492 ) ;
if ( ! F_30 ( V_492 ) ) {
if ( F_64 ( V_492 ) ) {
int V_101 = V_493 ;
if ( ! V_41 -> V_489 )
V_101 = V_494 ;
F_207 ( V_41 ,
V_101 , 0 , V_84 & 0x3fff ) ;
} else
F_207 ( V_41 ,
V_252 , - 1 , - 1 ) ;
return;
}
if ( V_41 -> V_167 ) {
F_207 ( V_41 ,
V_495 , ( V_84 >> 16 ) & 0x3fff ,
V_84 & 0x00ff ) ;
return;
}
F_207 ( V_41 , V_496 ,
0 , V_84 & 0x3fff ) ;
}
static int F_220 ( struct V_1 * V_21 , int V_497 ,
int V_67 , int V_448 , int V_498 )
{
int V_499 = V_448 + ( V_497 == 0 ) ;
if ( V_67 == V_497 )
return 0 ;
if ( V_67 < V_499 )
return 0 ;
if ( ( V_67 - V_448 - ( V_497 == 0 ) ) < V_498 )
return 0 ;
return 1 ;
}
static int F_221 ( struct V_1 * V_21 ,
struct V_434 * V_447 , T_4 * V_448 ,
struct V_467 * V_500 , T_4 * V_501 )
{
if ( F_195 ( V_21 , V_447 , sizeof( * V_447 ) ) ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_142 ) ;
return - 1 ;
}
* V_448 = F_205 ( * ( ( V_474 * ) V_447 -> V_450 ) ) / 24 ;
if ( * V_448 > V_502 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_148 ,
V_502 , * V_448 - V_502 ) ;
* V_448 = V_502 ;
}
if ( F_206 ( V_21 , V_500 , sizeof( * V_500 ) ) ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_149 ) ;
return - 1 ;
}
* V_501 = F_205 ( * ( ( V_474 * ) V_500 -> V_450 ) ) / 8 ;
if ( * V_501 > V_503 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_150
L_151 , V_503 ,
* V_501 - V_503 ) ;
* V_501 = V_503 ;
}
if ( * V_501 + * V_448 > V_502 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_152
L_151 , V_502 ,
* V_448 + * V_501 - V_502 ) ;
* V_501 = V_502 - * V_448 ;
}
return 0 ;
}
static T_1 * F_222 ( struct V_1 * V_21 , int V_497 ,
int V_67 , int V_448 , int V_501 ,
struct V_434 * V_504 ,
struct V_467 * V_505 )
{
int V_499 = V_448 + ( V_497 == 0 ) ;
int V_506 = V_448 + V_501 + ( V_497 == 0 ) ;
if ( V_67 == V_497 )
return V_158 ;
if ( V_67 < V_499 )
return & V_504 -> V_350 [ V_67 -
( V_497 == 0 ) ] . V_84 [ 0 ] ;
if ( V_67 < V_506 )
return & V_505 -> V_350 [ V_67 - V_448 -
( V_497 == 0 ) ] [ 0 ] ;
F_178 () ;
return NULL ;
}
static void F_223 ( struct V_1 * V_21 ,
struct V_71 * V_29 ,
struct V_434 * V_435 , int V_436 ,
struct V_432 * V_440 )
{
int V_20 ;
struct V_441 * V_442 ;
V_442 = & V_435 -> V_350 [ V_436 ] ;
V_29 -> V_187 = V_442 -> V_187 ;
if ( ( V_442 -> V_507 & 0x08 ) && V_29 -> V_187 )
V_29 -> V_188 = 1 ;
memset ( V_440 , 0 , sizeof( * V_440 ) ) ;
V_20 = F_190 ( V_21 , & V_442 -> V_84 [ 0 ] ,
F_192 ( & V_442 -> V_84 [ 0 ] ) , V_440 ,
sizeof( * V_440 ) ) ;
if ( ! V_20 )
#define F_224 2
#define F_225 7
V_29 -> V_190 =
F_98 ( V_440 -> V_508 ) -
F_224 ;
else
V_29 -> V_190 = F_225 ;
}
static void F_226 ( struct V_71 * V_425 ,
struct V_434 * V_435 , int V_436 ,
struct V_432 * V_440 )
{
struct V_441 * V_442 = & V_435 -> V_350 [ V_436 ] ;
if ( ( V_442 -> V_507 & 0x08 ) && V_425 -> V_187 )
V_425 -> V_188 = 1 ;
memcpy ( & V_425 -> V_98 ,
& V_440 -> V_445 ,
sizeof( V_425 -> V_98 ) ) ;
memcpy ( & V_425 -> V_99 ,
& V_440 -> V_509 ,
sizeof( V_425 -> V_99 ) ) ;
memcpy ( & V_425 -> V_91 ,
& V_440 -> V_510 ,
sizeof( V_425 -> V_91 ) ) ;
memcpy ( & V_425 -> V_95 ,
& V_440 -> V_511 ,
sizeof( V_425 -> V_95 ) ) ;
memcpy ( & V_425 -> V_92 ,
& V_440 -> V_512 ,
sizeof( V_425 -> V_92 ) ) ;
}
static int F_227 ( struct V_1 * V_21 ,
struct V_430 * V_513 ,
T_4 * V_514 )
{
int V_20 ;
if ( ! V_513 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_153 ,
V_242 ) ;
return - V_263 ;
}
memset ( V_513 , 0 , sizeof( * V_513 ) ) ;
V_20 = F_189 ( V_21 , V_513 , sizeof( * V_513 ) ) ;
if ( ! V_20 )
if ( V_513 -> V_515 < 255 )
* V_514 = V_513 -> V_515 ;
else
* V_514 = F_98 (
V_513 -> V_516 ) ;
else
* V_514 = - 1 ;
return V_20 ;
}
static bool F_228 ( struct V_1 * V_21 , T_1 * V_492 )
{
struct V_432 * V_440 ;
bool V_517 = false ;
int V_20 ;
V_440 = F_116 ( sizeof( * V_440 ) , V_203 ) ;
if ( ! V_440 )
return false ;
V_20 = F_190 ( V_21 ,
V_492 ,
F_192 ( V_492 ) ,
V_440 , sizeof( * V_440 ) ) ;
if ( V_20 == 0 )
V_517 = ( V_440 -> V_518 >> 6 ) & 0x01 ;
F_82 ( V_440 ) ;
return V_517 ;
}
static bool F_229 ( struct V_1 * V_21 , T_1 * V_492 ,
struct V_441 * V_442 )
{
T_1 V_507 ;
T_1 V_519 ;
if ( ! F_193 ( V_492 ) )
return false ;
V_507 = V_442 -> V_507 ;
V_519 = V_442 -> V_519 ;
if ( V_507 & V_520 ) {
if ( V_519 == V_521 )
return false ;
return true ;
}
if ( ! ( V_507 & V_522 ) )
return false ;
if ( V_507 & V_523 )
return false ;
if ( F_228 ( V_21 , V_492 ) )
return true ;
return false ;
}
static void F_230 ( struct V_1 * V_21 )
{
struct V_434 * V_504 = NULL ;
struct V_467 * V_505 = NULL ;
struct V_432 * V_440 = NULL ;
struct V_430 * V_513 = NULL ;
T_4 V_448 = 0 ;
T_4 V_501 = 0 ;
T_4 V_498 = 0 ;
T_4 V_524 = 0 ;
struct V_71 * * V_525 , * V_425 , * V_526 ;
int V_527 = 0 ;
int V_67 , V_528 , V_529 ;
int V_497 ;
bool V_72 ;
F_67 ( V_530 , V_531 ) ;
V_525 = F_116 ( sizeof( * V_525 ) * V_161 , V_203 ) ;
V_504 = F_116 ( sizeof( * V_504 ) , V_203 ) ;
V_505 = F_116 ( sizeof( * V_505 ) , V_203 ) ;
V_526 = F_116 ( sizeof( * V_526 ) , V_203 ) ;
V_440 = F_116 ( sizeof( * V_440 ) , V_203 ) ;
V_513 = F_116 ( sizeof( * V_513 ) , V_203 ) ;
if ( ! V_525 || ! V_504 || ! V_505 ||
! V_526 || ! V_440 || ! V_513 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_154 ) ;
goto V_396;
}
memset ( V_530 , 0 , sizeof( V_530 ) ) ;
V_21 -> V_250 = 0 ;
if ( F_221 ( V_21 , V_504 , & V_448 ,
V_505 , & V_501 ) ) {
V_21 -> V_250 = 1 ;
goto V_396;
}
if ( F_227 ( V_21 , V_513 , & V_498 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_155 ,
V_242 ) ;
}
V_529 = V_448 + V_501 + V_531 + 1 ;
for ( V_67 = 0 ; V_67 < V_529 ; V_67 ++ ) {
if ( V_67 >= V_161 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_156
L_157 , V_161 ,
V_529 - V_161 ) ;
break;
}
V_525 [ V_67 ] = F_116 ( sizeof( * V_525 [ V_67 ] ) , V_203 ) ;
if ( ! V_525 [ V_67 ] ) {
V_21 -> V_250 = 1 ;
goto V_396;
}
V_524 ++ ;
}
if ( F_65 ( V_21 ) )
V_497 = 0 ;
else
V_497 = V_448 + V_501 ;
V_528 = 0 ;
for ( V_67 = 0 ; V_67 < V_448 + V_501 + 1 ; V_67 ++ ) {
T_1 * V_492 , V_532 = 0 ;
int V_20 = 0 ;
int V_533 = V_67 - ( V_497 == 0 ) ;
bool V_534 = false ;
V_72 = V_67 < V_448 + ( V_497 == 0 ) ;
V_492 = F_222 ( V_21 , V_497 ,
V_67 , V_448 , V_501 , V_504 , V_505 ) ;
V_526 -> V_167 =
F_220 ( V_21 , V_497 , V_67 ,
V_448 , V_498 ) ;
if ( ! V_526 -> V_167 && V_72 ) {
V_534 = F_229 ( V_21 , V_492 ,
& V_504 -> V_350 [ V_533 ] ) ;
if ( V_534 )
continue;
}
V_20 = F_213 ( V_21 , V_492 , V_526 ,
& V_532 ) ;
if ( V_20 == - V_263 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_158 ) ;
V_21 -> V_250 = 1 ;
goto V_396;
}
if ( V_20 ) {
V_21 -> V_250 = 1 ;
continue;
}
F_219 ( V_21 , V_492 , V_526 ) ;
V_425 = V_525 [ V_527 ] ;
if ( ! V_21 -> V_535 ) {
if ( V_526 -> V_167 ) {
V_21 -> V_535 = 1 ;
F_96 ( & V_21 -> V_28 -> V_29 ,
L_159 ) ;
}
}
* V_425 = * V_526 ;
V_425 -> V_72 = V_72 ;
if ( F_193 ( V_492 ) && V_425 -> V_72 )
V_425 -> V_88 = 0 ;
else
V_425 -> V_88 = 1 ;
if ( V_425 -> V_72 && V_425 -> V_88 )
F_198 ( V_21 , V_492 , V_425 ) ;
switch ( V_425 -> V_104 ) {
case V_169 :
if ( V_532 )
V_527 ++ ;
break;
case V_106 :
case V_107 :
if ( V_425 -> V_72 ) {
V_425 -> V_89 = 0 ;
F_223 ( V_21 , V_425 ,
V_504 , V_533 , V_440 ) ;
F_226 ( V_425 ,
V_504 , V_533 , V_440 ) ;
}
V_527 ++ ;
break;
case V_170 :
case V_171 :
V_527 ++ ;
break;
case V_166 :
if ( ! V_425 -> V_167 )
F_191 ( V_21 , V_492 ,
V_504 , V_533 ,
V_425 ) ;
V_527 ++ ;
break;
case V_105 :
if ( ! F_64 ( V_492 ) )
break;
V_527 ++ ;
break;
default:
break;
}
if ( V_527 >= V_161 )
break;
}
if ( V_21 -> V_237 == NULL ) {
int V_20 = 0 ;
V_20 = F_231 ( V_21 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_160 , V_20 ) ;
goto V_396;
}
}
F_115 ( V_21 , V_525 , V_527 ) ;
V_396:
F_82 ( V_526 ) ;
for ( V_67 = 0 ; V_67 < V_524 ; V_67 ++ )
F_82 ( V_525 [ V_67 ] ) ;
F_82 ( V_525 ) ;
F_82 ( V_504 ) ;
F_82 ( V_505 ) ;
F_82 ( V_513 ) ;
F_82 ( V_440 ) ;
}
static void F_232 ( struct V_276 * V_536 ,
struct V_537 * V_271 )
{
T_5 V_376 = ( T_5 ) F_233 ( V_271 ) ;
unsigned int V_49 = F_234 ( V_271 ) ;
V_536 -> V_284 = F_135 ( V_376 ) ;
V_536 -> V_283 = F_140 ( V_49 ) ;
V_536 -> V_280 = 0 ;
}
static int F_235 ( struct V_1 * V_21 ,
struct V_8 * V_131 ,
struct V_285 * V_286 )
{
struct V_537 * V_271 ;
int V_538 , V_67 , V_539 , V_540 , V_541 ;
struct V_276 * V_542 ;
F_77 ( F_158 ( V_286 ) > V_21 -> V_264 ) ;
V_538 = F_236 ( V_286 ) ;
if ( V_538 < 0 )
return V_538 ;
if ( ! V_538 )
goto V_543;
V_542 = V_131 -> V_278 ;
V_540 = V_538 > V_21 -> V_279 ;
V_539 = V_540 ? V_21 -> V_279 - 1 : V_538 ;
V_541 = F_158 ( V_286 ) - 1 ;
F_237 (cmd, sg, sg_limit, i) {
F_232 ( V_542 , V_271 ) ;
V_542 ++ ;
}
if ( V_540 ) {
V_542 = V_21 -> V_266 [ V_131 -> V_133 ] ;
V_539 = V_538 - V_539 ;
F_238 (sg, sg, sg_limit, i) {
F_232 ( V_542 , V_271 ) ;
V_542 ++ ;
}
}
( V_542 - 1 ) -> V_280 = F_140 ( V_378 ) ;
if ( V_538 + V_540 > V_21 -> V_544 )
V_21 -> V_544 = V_538 + V_540 ;
if ( V_540 ) {
V_131 -> V_124 . V_125 = V_21 -> V_279 ;
V_131 -> V_124 . V_282 = F_159 ( V_538 + 1 ) ;
if ( F_139 ( V_21 , V_131 ) ) {
F_157 ( V_286 ) ;
return - 1 ;
}
return 0 ;
}
V_543:
V_131 -> V_124 . V_125 = ( T_1 ) V_538 ;
V_131 -> V_124 . V_282 = F_159 ( V_538 ) ;
return 0 ;
}
static inline void F_239 ( struct V_1 * V_21 ,
T_1 * V_141 , int V_545 ,
const char * V_546 )
{
char V_44 [ V_547 ] ;
int V_548 ;
int V_67 ;
V_548 = F_41 ( V_44 , V_547 ,
L_161 , V_546 ) ;
for ( V_67 = 0 ; V_67 < V_545 ; V_67 ++ )
V_548 += F_41 ( V_44 + V_548 , V_547 - V_548 ,
L_162 , V_141 [ V_67 ] ) ;
F_9 ( & V_21 -> V_28 -> V_29 , L_16 , V_44 ) ;
}
static bool F_240 ( T_1 * V_141 )
{
T_4 V_549 ;
switch ( V_141 [ 0 ] ) {
case V_550 :
case V_551 :
case V_552 :
case V_553 :
V_549 = F_241 ( & V_141 [ 7 ] ) ;
break;
case V_554 :
case V_555 :
case V_556 :
case V_557 :
V_549 = F_196 ( & V_141 [ 6 ] ) ;
break;
case V_558 :
case V_559 :
case V_560 :
V_549 = F_196 ( & V_141 [ 10 ] ) ;
break;
default:
return false ;
}
return V_549 == 0 ;
}
static int F_242 ( T_1 * V_141 , int * V_545 )
{
int V_561 = 0 ;
T_4 V_562 ;
T_4 V_549 ;
switch ( V_141 [ 0 ] ) {
case V_563 :
case V_555 :
V_561 = 1 ;
case V_564 :
case V_554 :
if ( * V_545 == 6 ) {
V_562 = ( ( ( V_141 [ 1 ] & 0x1F ) << 16 ) |
( V_141 [ 2 ] << 8 ) |
V_141 [ 3 ] ) ;
V_549 = V_141 [ 4 ] ;
if ( V_549 == 0 )
V_549 = 256 ;
} else {
F_77 ( * V_545 != 12 ) ;
V_562 = F_196 ( & V_141 [ 2 ] ) ;
V_549 = F_196 ( & V_141 [ 6 ] ) ;
}
if ( V_549 > 0xffff )
return V_565 ;
V_141 [ 0 ] = V_561 ? V_551 : V_550 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_562 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_562 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_562 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_562 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_549 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_549 ) ;
V_141 [ 9 ] = 0 ;
* V_545 = 10 ;
break;
}
return 0 ;
}
static int F_243 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_545 ,
T_1 * V_70 , struct V_71 * V_235 )
{
struct V_285 * V_286 = V_9 -> V_10 ;
struct V_130 * V_131 = & V_21 -> V_132 [ V_9 -> V_133 ] ;
unsigned int V_49 ;
unsigned int V_566 = 0 ;
struct V_537 * V_271 ;
T_5 V_376 ;
int V_538 , V_67 ;
struct V_276 * V_542 ;
T_4 V_567 = V_568 ;
if ( F_158 ( V_286 ) > V_21 -> V_569 ) {
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
F_77 ( V_286 -> V_570 > V_571 ) ;
if ( F_240 ( V_141 ) ) {
F_239 ( V_21 , V_141 , V_545 , V_242 ) ;
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
if ( F_242 ( V_141 , & V_545 ) ) {
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
V_9 -> V_150 = V_151 ;
V_9 -> V_122 = ( T_4 ) V_21 -> V_572 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_77 ( V_9 -> V_122 & 0x0000007F ) ;
V_538 = F_236 ( V_286 ) ;
if ( V_538 < 0 ) {
F_47 ( & V_235 -> V_257 ) ;
return V_538 ;
}
if ( V_538 ) {
V_542 = V_131 -> V_278 ;
F_237 (cmd, sg, use_sg, i) {
V_376 = ( T_5 ) F_233 ( V_271 ) ;
V_49 = F_234 ( V_271 ) ;
V_566 += V_49 ;
V_542 -> V_284 = F_135 ( V_376 ) ;
V_542 -> V_283 = F_140 ( V_49 ) ;
V_542 -> V_280 = F_140 ( 0 ) ;
V_542 ++ ;
}
( -- V_542 ) -> V_280 = F_140 ( V_378 ) ;
switch ( V_286 -> V_573 ) {
case V_574 :
V_567 |= V_575 ;
break;
case V_576 :
V_567 |= V_577 ;
break;
case V_578 :
V_567 |= V_579 ;
break;
default:
F_75 ( & V_21 -> V_28 -> V_29 , L_163 ,
V_286 -> V_573 ) ;
F_178 () ;
break;
}
} else {
V_567 |= V_579 ;
}
V_9 -> V_124 . V_125 = V_538 ;
V_131 -> V_580 = F_159 ( V_187 & 0xFFFF ) ;
V_131 -> V_581 = F_140 ( V_566 ) ;
V_131 -> V_347 = F_159 ( V_582 |
( V_545 & V_348 ) ) ;
V_131 -> V_567 = F_140 ( V_567 ) ;
memcpy ( V_131 -> V_145 , V_141 , V_545 ) ;
memcpy ( V_131 -> V_352 , V_70 , 8 ) ;
F_62 ( V_21 , V_9 ) ;
return 0 ;
}
static int F_244 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_285 * V_286 = V_9 -> V_10 ;
struct V_71 * V_29 = V_286 -> V_41 -> V_78 ;
if ( ! V_29 )
return - 1 ;
V_9 -> V_235 = V_29 ;
return F_245 ( V_21 , V_9 , V_29 -> V_187 ,
V_286 -> V_583 , V_286 -> V_570 , V_29 -> V_70 , V_29 ) ;
}
static void F_246 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_139 * V_131 )
{
struct V_285 * V_286 = V_9 -> V_10 ;
struct V_71 * V_29 = V_286 -> V_41 -> V_78 ;
struct V_220 * V_221 = & V_29 -> V_186 ;
T_5 V_584 ;
if ( ! ( F_98 ( V_221 -> V_76 ) & V_422 ) )
return;
V_131 -> V_423 = V_221 -> V_423 ;
V_131 -> V_585 |= V_586 ;
switch ( V_286 -> V_583 [ 0 ] ) {
case V_564 :
case V_563 :
V_584 = ( ( ( V_286 -> V_583 [ 1 ] & 0x1F ) << 16 ) |
( V_286 -> V_583 [ 2 ] << 8 ) |
V_286 -> V_583 [ 3 ] ) ;
break;
case V_551 :
case V_550 :
case V_555 :
case V_554 :
V_584 = F_196 ( & V_286 -> V_583 [ 2 ] ) ;
break;
case V_559 :
case V_558 :
V_584 = F_197 ( & V_286 -> V_583 [ 2 ] ) ;
break;
default:
F_75 ( & V_21 -> V_28 -> V_29 ,
L_164 ,
V_242 , V_286 -> V_583 [ 0 ] ) ;
F_178 () ;
break;
}
if ( F_132 ( V_221 -> V_415 ) != 512 )
V_584 = V_584 *
F_132 ( V_221 -> V_415 ) / 512 ;
V_131 -> V_587 = F_140 ( V_584 ) ;
V_131 -> V_588 = F_140 ( V_584 >> 32 ) ;
}
static int F_247 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_545 ,
T_1 * V_70 , struct V_71 * V_235 )
{
struct V_285 * V_286 = V_9 -> V_10 ;
struct V_139 * V_131 = & V_21 -> V_137 [ V_9 -> V_133 ] ;
struct V_267 * V_542 ;
int V_538 , V_67 ;
struct V_537 * V_271 ;
T_5 V_376 ;
T_4 V_49 ;
T_4 V_566 = 0 ;
if ( ! V_286 -> V_41 )
return - 1 ;
if ( ! V_286 -> V_41 -> V_78 )
return - 1 ;
F_77 ( F_158 ( V_286 ) > V_21 -> V_264 ) ;
if ( F_240 ( V_141 ) ) {
F_239 ( V_21 , V_141 , V_545 , V_242 ) ;
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
if ( F_242 ( V_141 , & V_545 ) ) {
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
V_9 -> V_150 = V_154 ;
V_9 -> V_122 = ( T_4 ) V_21 -> V_589 +
( V_9 -> V_133 * sizeof( * V_131 ) ) ;
F_77 ( V_9 -> V_122 & 0x0000007F ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> V_590 = V_591 ;
V_538 = F_236 ( V_286 ) ;
if ( V_538 < 0 ) {
F_47 ( & V_235 -> V_257 ) ;
return V_538 ;
}
if ( V_538 ) {
V_542 = V_131 -> V_271 ;
if ( V_538 > V_21 -> V_569 ) {
V_376 = F_137 (
V_21 -> V_261 [ V_9 -> V_133 ] -> V_274 ) ;
V_542 -> V_274 = F_135 ( V_376 ) ;
V_542 -> V_272 = 0 ;
V_542 -> V_592 [ 0 ] = 0 ;
V_542 -> V_592 [ 1 ] = 0 ;
V_542 -> V_592 [ 2 ] = 0 ;
V_542 -> V_342 = 0x80 ;
V_542 = V_21 -> V_261 [ V_9 -> V_133 ] ;
}
F_237 (cmd, sg, use_sg, i) {
V_376 = ( T_5 ) F_233 ( V_271 ) ;
V_49 = F_234 ( V_271 ) ;
V_566 += V_49 ;
V_542 -> V_274 = F_135 ( V_376 ) ;
V_542 -> V_272 = F_140 ( V_49 ) ;
V_542 -> V_592 [ 0 ] = 0 ;
V_542 -> V_592 [ 1 ] = 0 ;
V_542 -> V_592 [ 2 ] = 0 ;
V_542 -> V_342 = 0 ;
V_542 ++ ;
}
switch ( V_286 -> V_573 ) {
case V_574 :
V_131 -> V_585 &= ~ V_593 ;
V_131 -> V_585 |= V_594 ;
break;
case V_576 :
V_131 -> V_585 &= ~ V_593 ;
V_131 -> V_585 |= V_595 ;
break;
case V_578 :
V_131 -> V_585 &= ~ V_593 ;
V_131 -> V_585 |= V_596 ;
break;
default:
F_75 ( & V_21 -> V_28 -> V_29 , L_163 ,
V_286 -> V_573 ) ;
F_178 () ;
break;
}
} else {
V_131 -> V_585 &= ~ V_593 ;
V_131 -> V_585 |= V_596 ;
}
F_246 ( V_21 , V_9 , V_131 ) ;
V_131 -> V_597 = F_140 ( V_187 ) ;
V_131 -> V_598 = F_140 ( V_9 -> V_133 << V_599 ) ;
memcpy ( V_131 -> V_141 , V_141 , sizeof( V_131 -> V_141 ) ) ;
V_131 -> V_288 = F_140 ( V_566 ) ;
V_131 -> V_600 = F_135 ( V_9 -> V_122 +
F_248 ( struct V_139 , V_291 ) ) ;
V_131 -> V_601 = F_140 ( sizeof( V_131 -> V_291 ) ) ;
if ( V_538 > V_21 -> V_569 ) {
V_131 -> V_140 = 1 ;
V_131 -> V_271 [ 0 ] . V_272 = F_140 ( V_538 * sizeof( V_131 -> V_271 [ 0 ] ) ) ;
if ( F_131 ( V_21 , V_131 , V_9 ) ) {
F_47 ( & V_235 -> V_257 ) ;
F_157 ( V_286 ) ;
return - 1 ;
}
} else
V_131 -> V_140 = ( T_1 ) V_538 ;
F_62 ( V_21 , V_9 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_21 ,
struct V_8 * V_9 , T_4 V_187 , T_1 * V_141 , int V_545 ,
T_1 * V_70 , struct V_71 * V_235 )
{
if ( ! V_9 -> V_10 -> V_41 )
return - 1 ;
if ( ! V_9 -> V_10 -> V_41 -> V_78 )
return - 1 ;
if ( F_105 ( & V_235 -> V_257 ) >
V_235 -> V_190 ) {
F_47 ( & V_235 -> V_257 ) ;
return V_565 ;
}
if ( V_21 -> V_62 & V_114 )
return F_243 ( V_21 , V_9 , V_187 ,
V_141 , V_545 , V_70 ,
V_235 ) ;
else
return F_247 ( V_21 , V_9 , V_187 ,
V_141 , V_545 , V_70 ,
V_235 ) ;
}
static void F_249 ( struct V_220 * V_221 ,
int V_189 , T_4 * V_602 , T_4 * V_603 )
{
if ( V_189 == 0 ) {
* V_602 %= F_98 ( V_221 -> V_226 ) ;
return;
}
do {
* V_603 = * V_602 /
F_98 ( V_221 -> V_226 ) ;
if ( V_189 == * V_603 )
continue;
if ( * V_603 < F_98 ( V_221 -> V_230 ) - 1 ) {
* V_602 += F_98 ( V_221 -> V_226 ) ;
( * V_603 ) ++ ;
} else {
* V_602 %= F_98 ( V_221 -> V_226 ) ;
* V_603 = 0 ;
}
} while ( V_189 != * V_603 );
}
static int F_250 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
struct V_285 * V_286 = V_9 -> V_10 ;
struct V_71 * V_29 = V_286 -> V_41 -> V_78 ;
struct V_220 * V_221 = & V_29 -> V_186 ;
struct V_222 * V_223 = & V_221 -> V_224 [ 0 ] ;
int V_561 = 0 ;
T_4 V_602 ;
T_5 V_584 , V_604 ;
T_4 V_549 ;
T_4 V_605 ;
T_5 V_606 , V_607 ;
T_4 V_608 , V_609 ;
T_4 V_610 , V_611 ;
T_5 V_612 , V_613 ;
T_4 V_614 ;
T_5 V_615 , V_616 ;
T_4 V_617 , V_618 ;
T_4 V_619 , V_620 ;
T_4 V_225 ;
T_4 V_621 ;
T_4 V_622 , V_623 , V_603 ;
T_4 V_624 ;
T_4 V_625 ;
T_5 V_626 ;
T_4 V_627 ;
T_1 V_141 [ 16 ] ;
T_1 V_545 ;
T_6 V_419 ;
#if V_628 == 32
T_5 V_629 ;
#endif
int V_189 ;
if ( ! V_29 )
return - 1 ;
switch ( V_286 -> V_583 [ 0 ] ) {
case V_563 :
V_561 = 1 ;
case V_564 :
V_584 = ( ( ( V_286 -> V_583 [ 1 ] & 0x1F ) << 16 ) |
( V_286 -> V_583 [ 2 ] << 8 ) |
V_286 -> V_583 [ 3 ] ) ;
V_549 = V_286 -> V_583 [ 4 ] ;
if ( V_549 == 0 )
V_549 = 256 ;
break;
case V_551 :
V_561 = 1 ;
case V_550 :
V_584 =
( ( ( T_5 ) V_286 -> V_583 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_286 -> V_583 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_286 -> V_583 [ 4 ] ) << 8 ) |
V_286 -> V_583 [ 5 ] ;
V_549 =
( ( ( T_4 ) V_286 -> V_583 [ 7 ] ) << 8 ) |
V_286 -> V_583 [ 8 ] ;
break;
case V_555 :
V_561 = 1 ;
case V_554 :
V_584 =
( ( ( T_5 ) V_286 -> V_583 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_286 -> V_583 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_286 -> V_583 [ 4 ] ) << 8 ) |
V_286 -> V_583 [ 5 ] ;
V_549 =
( ( ( T_4 ) V_286 -> V_583 [ 6 ] ) << 24 ) |
( ( ( T_4 ) V_286 -> V_583 [ 7 ] ) << 16 ) |
( ( ( T_4 ) V_286 -> V_583 [ 8 ] ) << 8 ) |
V_286 -> V_583 [ 9 ] ;
break;
case V_559 :
V_561 = 1 ;
case V_558 :
V_584 =
( ( ( T_5 ) V_286 -> V_583 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_286 -> V_583 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_286 -> V_583 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_286 -> V_583 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_286 -> V_583 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_286 -> V_583 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_286 -> V_583 [ 8 ] ) << 8 ) |
V_286 -> V_583 [ 9 ] ;
V_549 =
( ( ( T_4 ) V_286 -> V_583 [ 10 ] ) << 24 ) |
( ( ( T_4 ) V_286 -> V_583 [ 11 ] ) << 16 ) |
( ( ( T_4 ) V_286 -> V_583 [ 12 ] ) << 8 ) |
V_286 -> V_583 [ 13 ] ;
break;
default:
return V_565 ;
}
V_604 = V_584 + V_549 - 1 ;
if ( V_561 && V_29 -> V_81 != 0 )
return V_565 ;
if ( V_604 >= F_137 ( V_221 -> V_416 ) ||
V_604 < V_584 )
return V_565 ;
V_605 = F_98 ( V_221 -> V_226 ) *
F_98 ( V_221 -> V_419 ) ;
V_419 = F_98 ( V_221 -> V_419 ) ;
#if V_628 == 32
V_629 = V_584 ;
( void ) F_251 ( V_629 , V_605 ) ;
V_606 = V_629 ;
V_629 = V_604 ;
( void ) F_251 ( V_629 , V_605 ) ;
V_607 = V_629 ;
V_608 = ( T_4 ) ( V_584 - ( V_606 * V_605 ) ) ;
V_609 = ( T_4 ) ( V_604 - ( V_607 * V_605 ) ) ;
V_629 = V_608 ;
( void ) F_251 ( V_629 , V_419 ) ;
V_610 = V_629 ;
V_629 = V_609 ;
( void ) F_251 ( V_629 , V_419 ) ;
V_611 = V_629 ;
#else
V_606 = V_584 / V_605 ;
V_607 = V_604 / V_605 ;
V_608 = ( T_4 ) ( V_584 - ( V_606 * V_605 ) ) ;
V_609 = ( T_4 ) ( V_604 - ( V_607 * V_605 ) ) ;
V_610 = V_608 / V_419 ;
V_611 = V_609 / V_419 ;
#endif
if ( ( V_606 != V_607 ) || ( V_610 != V_611 ) )
return V_565 ;
V_225 = F_98 ( V_221 -> V_226 ) +
F_98 ( V_221 -> V_227 ) ;
V_624 = ( ( T_4 ) ( V_606 >> V_221 -> V_418 ) ) %
F_98 ( V_221 -> V_229 ) ;
V_602 = ( V_624 * V_225 ) + V_610 ;
switch ( V_29 -> V_81 ) {
case V_630 :
break;
case V_631 :
F_77 ( F_98 ( V_221 -> V_230 ) != 2 ) ;
if ( V_29 -> V_189 )
V_602 += F_98 ( V_221 -> V_226 ) ;
V_29 -> V_189 = ! V_29 -> V_189 ;
break;
case V_632 :
F_77 ( F_98 ( V_221 -> V_230 ) != 3 ) ;
V_189 = V_29 -> V_189 ;
F_249 ( V_221 , V_189 ,
& V_602 , & V_603 ) ;
V_189 =
( V_189 >=
F_98 ( V_221 -> V_230 ) - 1 )
? 0 : V_189 + 1 ;
V_29 -> V_189 = V_189 ;
break;
case V_633 :
case V_634 :
if ( F_98 ( V_221 -> V_230 ) <= 1 )
break;
V_614 =
F_98 ( V_221 -> V_419 ) *
F_98 ( V_221 -> V_226 ) ;
F_77 ( V_614 == 0 ) ;
V_621 = V_614 *
F_98 ( V_221 -> V_230 ) ;
#if V_628 == 32
V_629 = V_584 ;
V_622 = F_251 ( V_629 , V_621 ) ;
V_629 = V_622 ;
( void ) F_251 ( V_629 , V_614 ) ;
V_622 = V_629 ;
V_629 = V_604 ;
V_623 = F_251 ( V_629 , V_621 ) ;
V_629 = V_623 ;
( void ) F_251 ( V_629 , V_614 ) ;
V_623 = V_629 ;
#else
V_622 = ( V_584 % V_621 ) / V_614 ;
V_623 = ( V_604 % V_621 ) / V_614 ;
#endif
if ( V_622 != V_623 )
return V_565 ;
#if V_628 == 32
V_629 = V_584 ;
( void ) F_251 ( V_629 , V_621 ) ;
V_606 = V_615 = V_612 = V_629 ;
V_629 = V_604 ;
( void ) F_251 ( V_629 , V_621 ) ;
V_616 = V_613 = V_629 ;
#else
V_606 = V_615 = V_612 =
V_584 / V_621 ;
V_616 = V_613 = V_604 / V_621 ;
#endif
if ( V_615 != V_616 )
return V_565 ;
#if V_628 == 32
V_629 = V_584 ;
V_608 = F_251 ( V_629 , V_621 ) ;
V_629 = V_608 ;
V_608 = ( T_4 ) F_251 ( V_629 , V_614 ) ;
V_617 = V_608 ;
V_629 = V_604 ;
V_618 = F_251 ( V_629 , V_621 ) ;
V_629 = V_618 ;
V_618 = F_251 ( V_629 , V_614 ) ;
V_629 = V_617 ;
( void ) F_251 ( V_629 , V_221 -> V_419 ) ;
V_610 = V_619 = V_629 ;
V_629 = V_618 ;
( void ) F_251 ( V_629 , V_221 -> V_419 ) ;
V_620 = V_629 ;
#else
V_608 = V_617 =
( T_4 ) ( ( V_584 % V_621 ) %
V_614 ) ;
V_618 =
( T_4 ) ( ( V_604 % V_621 ) %
V_614 ) ;
V_610 = V_619 =
V_617 / F_98 ( V_221 -> V_419 ) ;
V_620 =
V_618 / F_98 ( V_221 -> V_419 ) ;
#endif
if ( V_619 != V_620 )
return V_565 ;
V_624 = ( ( T_4 ) ( V_606 >> V_221 -> V_418 ) ) %
F_98 ( V_221 -> V_229 ) ;
V_602 = ( V_622 *
( F_98 ( V_221 -> V_229 ) * V_225 ) ) +
( V_624 * V_225 ) + V_610 ;
break;
default:
return V_565 ;
}
if ( F_46 ( V_602 >= V_233 ) )
return V_565 ;
V_9 -> V_235 = V_29 -> V_235 [ V_602 ] ;
if ( ! V_9 -> V_235 )
return V_565 ;
V_625 = V_223 [ V_602 ] . V_187 ;
V_626 = F_137 ( V_221 -> V_420 ) +
V_606 * F_98 ( V_221 -> V_419 ) +
( V_608 - V_610 *
F_98 ( V_221 -> V_419 ) ) ;
V_627 = V_549 ;
if ( V_221 -> V_417 ) {
V_626 <<= V_221 -> V_417 ;
V_627 <<= V_221 -> V_417 ;
}
F_77 ( V_627 > 0xffff ) ;
if ( V_626 > 0xffffffff ) {
V_141 [ 0 ] = V_561 ? V_559 : V_558 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_626 >> 56 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_626 >> 48 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_626 >> 40 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_626 >> 32 ) ;
V_141 [ 6 ] = ( T_1 ) ( V_626 >> 24 ) ;
V_141 [ 7 ] = ( T_1 ) ( V_626 >> 16 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_626 >> 8 ) ;
V_141 [ 9 ] = ( T_1 ) ( V_626 ) ;
V_141 [ 10 ] = ( T_1 ) ( V_627 >> 24 ) ;
V_141 [ 11 ] = ( T_1 ) ( V_627 >> 16 ) ;
V_141 [ 12 ] = ( T_1 ) ( V_627 >> 8 ) ;
V_141 [ 13 ] = ( T_1 ) ( V_627 ) ;
V_141 [ 14 ] = 0 ;
V_141 [ 15 ] = 0 ;
V_545 = 16 ;
} else {
V_141 [ 0 ] = V_561 ? V_551 : V_550 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = ( T_1 ) ( V_626 >> 24 ) ;
V_141 [ 3 ] = ( T_1 ) ( V_626 >> 16 ) ;
V_141 [ 4 ] = ( T_1 ) ( V_626 >> 8 ) ;
V_141 [ 5 ] = ( T_1 ) ( V_626 ) ;
V_141 [ 6 ] = 0 ;
V_141 [ 7 ] = ( T_1 ) ( V_627 >> 8 ) ;
V_141 [ 8 ] = ( T_1 ) ( V_627 ) ;
V_141 [ 9 ] = 0 ;
V_545 = 10 ;
}
return F_245 ( V_21 , V_9 , V_625 , V_141 , V_545 ,
V_29 -> V_70 ,
V_29 -> V_235 [ V_602 ] ) ;
}
static int F_252 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_285 * V_286 ,
unsigned char V_70 [] )
{
V_286 -> V_635 = ( unsigned char * ) V_9 ;
V_9 -> V_150 = V_341 ;
V_9 -> V_10 = V_286 ;
V_9 -> V_124 . V_128 = 0 ;
memcpy ( & V_9 -> V_124 . V_350 . V_351 [ 0 ] , & V_70 [ 0 ] , 8 ) ;
V_9 -> V_124 . V_349 = F_135 ( ( V_9 -> V_133 << V_599 ) ) ;
V_9 -> V_144 . V_636 = 0 ;
F_77 ( V_286 -> V_570 > sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_346 = V_286 -> V_570 ;
memcpy ( V_9 -> V_144 . V_145 , V_286 -> V_583 , V_286 -> V_570 ) ;
switch ( V_286 -> V_573 ) {
case V_574 :
V_9 -> V_144 . V_637 =
F_253 ( V_395 , V_638 , V_639 ) ;
break;
case V_576 :
V_9 -> V_144 . V_637 =
F_253 ( V_395 , V_638 , V_640 ) ;
break;
case V_578 :
V_9 -> V_144 . V_637 =
F_253 ( V_395 , V_638 , V_641 ) ;
break;
case V_642 :
V_9 -> V_144 . V_637 =
F_253 ( V_395 , V_638 , V_643 ) ;
break;
default:
F_75 ( & V_21 -> V_28 -> V_29 , L_163 ,
V_286 -> V_573 ) ;
F_178 () ;
break;
}
if ( F_235 ( V_21 , V_9 , V_286 ) < 0 ) {
F_148 ( V_21 , V_9 ) ;
return V_644 ;
}
F_62 ( V_21 , V_9 ) ;
return 0 ;
}
static void F_254 ( struct V_1 * V_21 , int V_199 ,
struct V_8 * V_9 )
{
V_374 V_645 , V_646 ;
memset ( V_9 , 0 , F_248 ( struct V_8 , V_239 ) ) ;
V_9 -> V_124 . V_349 = F_135 ( ( T_5 ) ( V_199 << V_599 ) ) ;
V_645 = V_21 -> V_647 + V_199 * sizeof( * V_9 ) ;
V_9 -> V_23 = V_21 -> V_648 + V_199 ;
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_646 = V_21 -> V_649
+ V_199 * sizeof( * V_9 -> V_23 ) ;
V_9 -> V_133 = V_199 ;
V_9 -> V_122 = ( T_4 ) V_645 ;
V_9 -> V_650 . V_284 = F_135 ( ( T_5 ) V_646 ) ;
V_9 -> V_650 . V_283 = F_140 ( ( T_4 ) sizeof( * V_9 -> V_23 ) ) ;
V_9 -> V_21 = V_21 ;
V_9 -> V_10 = V_11 ;
}
static void F_255 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
struct V_8 * V_9 = V_21 -> V_238 + V_67 ;
F_254 ( V_21 , V_67 , V_9 ) ;
F_123 ( & V_9 -> V_239 , 0 ) ;
}
}
static inline void F_256 ( struct V_1 * V_21 , int V_199 ,
struct V_8 * V_9 )
{
V_374 V_645 = V_21 -> V_647 + V_199 * sizeof( * V_9 ) ;
F_77 ( V_9 -> V_133 != V_199 ) ;
memset ( V_9 -> V_144 . V_145 , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
memset ( V_9 -> V_23 , 0 , sizeof( * V_9 -> V_23 ) ) ;
V_9 -> V_122 = ( T_4 ) V_645 ;
}
static int F_257 ( struct V_1 * V_21 ,
struct V_8 * V_9 , struct V_285 * V_286 ,
unsigned char * V_70 )
{
struct V_71 * V_29 = V_286 -> V_41 -> V_78 ;
int V_20 = V_565 ;
if ( ! V_29 )
return V_644 ;
V_286 -> V_635 = ( unsigned char * ) V_9 ;
if ( V_29 -> V_89 ) {
F_254 ( V_21 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_341 ;
V_9 -> V_10 = V_286 ;
V_20 = F_250 ( V_21 , V_9 ) ;
if ( V_20 < 0 )
V_20 = V_644 ;
} else if ( V_29 -> V_188 ) {
F_254 ( V_21 , V_9 -> V_133 , V_9 ) ;
V_9 -> V_150 = V_341 ;
V_9 -> V_10 = V_286 ;
V_20 = F_244 ( V_21 , V_9 ) ;
if ( V_20 < 0 )
V_20 = V_644 ;
}
return V_20 ;
}
static void V_328 ( struct V_651 * V_327 )
{
struct V_285 * V_286 ;
struct V_71 * V_29 ;
struct V_8 * V_9 = F_258 ( V_327 , struct V_8 , V_327 ) ;
V_286 = V_9 -> V_10 ;
V_29 = V_286 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_286 -> V_296 = V_318 << 16 ;
return F_150 ( V_9 -> V_21 , V_9 , V_286 ) ;
}
if ( V_9 -> V_12 )
return F_150 ( V_9 -> V_21 , V_9 , V_286 ) ;
if ( V_9 -> V_150 == V_154 ) {
struct V_1 * V_21 = V_9 -> V_21 ;
struct V_139 * V_287 = & V_21 -> V_137 [ V_9 -> V_133 ] ;
int V_20 ;
if ( V_287 -> V_291 . V_292 ==
V_305 ) {
V_20 = F_257 ( V_21 , V_9 , V_286 , V_29 -> V_70 ) ;
if ( V_20 == 0 )
return;
if ( V_20 == V_644 ) {
V_286 -> V_296 = V_652 << 16 ;
return F_150 ( V_21 , V_9 , V_286 ) ;
}
}
}
F_256 ( V_9 -> V_21 , V_9 -> V_133 , V_9 ) ;
if ( F_252 ( V_9 -> V_21 , V_9 , V_286 , V_29 -> V_70 ) ) {
V_286 -> V_296 = V_652 << 16 ;
V_286 -> V_326 ( V_286 ) ;
}
}
static int F_259 ( struct V_6 * V_7 , struct V_285 * V_286 )
{
struct V_1 * V_21 ;
struct V_71 * V_29 ;
unsigned char V_70 [ 8 ] ;
struct V_8 * V_9 ;
int V_20 = 0 ;
V_21 = F_1 ( V_286 -> V_41 ) ;
F_77 ( V_286 -> V_653 -> V_349 < 0 ) ;
V_29 = V_286 -> V_41 -> V_78 ;
if ( ! V_29 ) {
V_286 -> V_296 = V_318 << 16 ;
V_286 -> V_326 ( V_286 ) ;
return 0 ;
}
if ( V_29 -> V_191 ) {
V_286 -> V_296 = V_318 << 16 ;
V_286 -> V_326 ( V_286 ) ;
return 0 ;
}
memcpy ( V_70 , V_29 -> V_70 , sizeof( V_70 ) ) ;
if ( F_46 ( F_13 ( V_21 ) ) ) {
V_286 -> V_296 = V_318 << 16 ;
V_286 -> V_326 ( V_286 ) ;
return 0 ;
}
V_9 = F_260 ( V_21 , V_286 ) ;
if ( F_49 ( V_286 -> V_654 == 0 &&
! F_261 ( V_286 -> V_653 ) &&
V_21 -> V_55 ) ) {
V_20 = F_257 ( V_21 , V_9 , V_286 , V_70 ) ;
if ( V_20 == 0 )
return 0 ;
if ( V_20 == V_644 ) {
F_148 ( V_21 , V_9 ) ;
return V_644 ;
}
}
return F_252 ( V_21 , V_9 , V_286 , V_70 ) ;
}
static void F_262 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
F_34 ( & V_21 -> V_655 , V_76 ) ;
V_21 -> V_656 = 1 ;
F_263 ( & V_21 -> V_657 ) ;
F_35 ( & V_21 -> V_655 , V_76 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_21 = F_3 ( V_7 ) ;
unsigned long V_76 ;
if ( F_46 ( F_13 ( V_21 ) ) )
return F_262 ( V_21 ) ;
F_34 ( & V_21 -> V_655 , V_76 ) ;
if ( V_21 -> V_658 ) {
F_35 ( & V_21 -> V_655 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_655 , V_76 ) ;
while ( 1 ) {
F_34 ( & V_21 -> V_655 , V_76 ) ;
if ( V_21 -> V_656 )
break;
V_21 -> V_658 = 1 ;
F_35 ( & V_21 -> V_655 , V_76 ) ;
F_181 ( V_21 -> V_657 , V_21 -> V_656 ) ;
}
V_21 -> V_656 = 0 ;
V_21 -> V_658 = 0 ;
F_35 ( & V_21 -> V_655 , V_76 ) ;
if ( F_46 ( F_13 ( V_21 ) ) )
return F_262 ( V_21 ) ;
F_34 ( & V_21 -> V_248 , V_76 ) ;
if ( V_21 -> V_249 ) {
V_21 -> V_250 = 1 ;
F_35 ( & V_21 -> V_248 , V_76 ) ;
F_262 ( V_21 ) ;
return;
}
F_35 ( & V_21 -> V_248 , V_76 ) ;
F_230 ( V_21 ) ;
F_262 ( V_21 ) ;
}
static int F_264 ( struct V_2 * V_3 , int V_232 )
{
struct V_71 * V_219 = V_3 -> V_78 ;
if ( ! V_219 )
return - V_79 ;
if ( V_232 < 1 )
V_232 = 1 ;
else if ( V_232 > V_219 -> V_190 )
V_232 = V_219 -> V_190 ;
return F_125 ( V_3 , V_232 ) ;
}
static int F_265 ( struct V_6 * V_7 ,
unsigned long V_659 )
{
struct V_1 * V_21 = F_3 ( V_7 ) ;
unsigned long V_76 ;
int V_660 ;
F_34 ( & V_21 -> V_655 , V_76 ) ;
V_660 = V_21 -> V_656 ;
F_35 ( & V_21 -> V_655 , V_76 ) ;
return V_660 ;
}
static int F_266 ( struct V_1 * V_21 )
{
struct V_6 * V_7 ;
V_7 = F_267 ( & V_661 , sizeof( V_21 ) ) ;
if ( V_7 == NULL ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_165 ) ;
return - V_263 ;
}
V_7 -> V_662 = 0 ;
V_7 -> V_663 = 0 ;
V_7 -> V_664 = - 1 ;
V_7 -> V_665 = 3 ;
V_7 -> V_666 = V_667 ;
V_7 -> V_668 = V_503 ;
V_7 -> V_669 = V_503 ;
V_7 -> V_260 = V_21 -> V_236 - V_670 ;
V_7 -> V_671 = V_7 -> V_260 ;
V_7 -> V_672 = V_21 -> V_264 ;
V_7 -> V_673 = V_674 ;
V_7 -> V_78 [ 0 ] = ( unsigned long ) V_21 ;
V_7 -> V_675 = F_268 ( V_21 -> V_28 , 0 ) ;
V_7 -> V_676 = V_7 -> V_675 ;
V_21 -> V_58 = V_7 ;
return 0 ;
}
static int F_269 ( struct V_1 * V_21 )
{
int V_677 ;
V_677 = F_270 ( V_21 -> V_58 , & V_21 -> V_28 -> V_29 ) ;
if ( V_677 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_166 ) ;
return V_677 ;
}
F_271 ( V_21 -> V_58 ) ;
return 0 ;
}
static int F_272 ( struct V_285 * V_678 )
{
int V_679 = V_678 -> V_653 -> V_349 ;
if ( V_679 < 0 )
return V_679 ;
return V_679 += V_670 ;
}
static int F_273 ( struct V_1 * V_21 ,
struct V_8 * V_9 , unsigned char V_680 [] ,
int V_113 )
{
int V_20 ;
( void ) F_176 ( V_9 , V_482 , V_21 ,
NULL , 0 , 0 , V_680 , V_395 ) ;
V_20 = F_167 ( V_21 , V_9 , V_113 , V_398 ) ;
if ( V_20 )
return V_20 ;
if ( V_9 -> V_23 -> V_35 == V_681 )
return 0 ;
if ( V_9 -> V_23 -> V_35 == V_36 &&
V_9 -> V_23 -> V_37 == V_297 &&
( V_9 -> V_23 -> V_25 [ 2 ] == V_682 ||
V_9 -> V_23 -> V_25 [ 2 ] == V_26 ) )
return 0 ;
return 1 ;
}
static int F_274 ( struct V_1 * V_21 ,
struct V_8 * V_9 ,
unsigned char V_680 [] , int V_113 )
{
int V_20 ;
int V_47 = 0 ;
int V_683 = 1 ;
for ( V_47 = 0 ; V_47 < V_684 ; V_47 ++ ) {
F_109 ( 1000 * V_683 ) ;
V_20 = F_273 ( V_21 , V_9 , V_680 , V_113 ) ;
if ( ! V_20 )
break;
if ( V_683 < V_685 )
V_683 *= 2 ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_167 ,
V_683 ) ;
}
return V_20 ;
}
static int F_182 ( struct V_1 * V_21 ,
unsigned char V_680 [] ,
int V_113 )
{
int V_686 ;
int V_687 ;
int V_112 ;
int V_20 = 0 ;
struct V_8 * V_9 ;
V_9 = F_175 ( V_21 ) ;
if ( V_113 == V_127 ) {
V_686 = 0 ;
V_687 = V_21 -> V_129 - 1 ;
} else {
V_686 = V_113 ;
V_687 = V_113 ;
}
for ( V_112 = V_686 ; V_112 <= V_687 ; V_112 ++ ) {
V_20 = F_274 ( V_21 , V_9 , V_680 , V_112 ) ;
if ( V_20 )
break;
}
if ( V_20 )
F_9 ( & V_21 -> V_28 -> V_29 , L_168 ) ;
else
F_9 ( & V_21 -> V_28 -> V_29 , L_169 ) ;
F_107 ( V_21 , V_9 ) ;
return V_20 ;
}
static int F_275 ( struct V_285 * V_688 )
{
int V_20 = V_689 ;
struct V_1 * V_21 ;
struct V_71 * V_29 ;
T_1 V_399 ;
char V_690 [ 48 ] ;
unsigned long V_76 ;
V_21 = F_1 ( V_688 -> V_41 ) ;
if ( V_21 == NULL )
return V_691 ;
F_34 ( & V_21 -> V_248 , V_76 ) ;
V_21 -> V_249 = 1 ;
F_35 ( & V_21 -> V_248 , V_76 ) ;
if ( F_13 ( V_21 ) ) {
V_20 = V_691 ;
goto V_692;
}
V_29 = V_688 -> V_41 -> V_78 ;
if ( ! V_29 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_170 , V_242 ) ;
V_20 = V_691 ;
goto V_692;
}
if ( V_29 -> V_104 == V_166 ) {
V_20 = V_689 ;
goto V_692;
}
if ( F_13 ( V_21 ) ) {
snprintf ( V_690 , sizeof( V_690 ) ,
L_171 ,
F_272 ( V_688 ) ) ;
F_71 ( V_243 , V_21 , V_29 , V_690 ) ;
V_20 = V_691 ;
goto V_692;
}
if ( F_276 ( V_21 ) ) {
snprintf ( V_690 , sizeof( V_690 ) ,
L_172 ,
F_272 ( V_688 ) ) ;
F_71 ( V_243 , V_21 , V_29 , V_690 ) ;
V_20 = V_691 ;
goto V_692;
}
if ( F_64 ( V_29 -> V_70 ) ) {
V_20 = V_689 ;
goto V_692;
}
if ( F_30 ( V_29 -> V_70 ) )
V_399 = V_693 ;
else
V_399 = V_694 ;
sprintf ( V_690 , L_173 ,
V_399 == V_693 ? L_174 : L_175 ) ;
F_71 ( V_243 , V_21 , V_29 , V_690 ) ;
V_20 = F_179 ( V_21 , V_29 , V_29 -> V_70 , V_399 ,
V_127 ) ;
if ( V_20 == 0 )
V_20 = V_689 ;
else
V_20 = V_691 ;
sprintf ( V_690 , L_176 ,
V_399 == V_693 ? L_174 : L_175 ,
V_20 == V_689 ? L_177 : L_178 ) ;
F_71 ( V_243 , V_21 , V_29 , V_690 ) ;
V_692:
F_34 ( & V_21 -> V_248 , V_76 ) ;
V_21 -> V_249 = 0 ;
F_35 ( & V_21 -> V_248 , V_76 ) ;
return V_20 ;
}
static struct V_8 * F_260 ( struct V_1 * V_21 ,
struct V_285 * V_678 )
{
int V_679 = F_272 ( V_678 ) ;
struct V_8 * V_9 = V_21 -> V_238 + V_679 ;
if ( V_679 < V_670 || V_679 >= V_21 -> V_236 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_179 ,
V_679 , V_670 , V_21 -> V_236 - 1 ) ;
F_178 () ;
}
F_57 ( & V_9 -> V_239 ) ;
if ( F_46 ( ! F_4 ( V_9 ) ) ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_180 ,
V_679 ) ;
if ( V_9 -> V_10 != NULL )
F_277 ( V_9 -> V_10 ) ;
F_277 ( V_678 ) ;
}
F_256 ( V_21 , V_679 , V_9 ) ;
return V_9 ;
}
static void F_149 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
( void ) F_47 ( & V_9 -> V_239 ) ;
}
static struct V_8 * F_175 ( struct V_1 * V_21 )
{
struct V_8 * V_9 ;
int V_239 , V_67 ;
int V_695 = 0 ;
for (; ; ) {
V_67 = F_278 ( V_21 -> V_696 ,
V_670 ,
V_695 ) ;
if ( F_46 ( V_67 >= V_670 ) ) {
V_695 = 0 ;
continue;
}
V_9 = V_21 -> V_238 + V_67 ;
V_239 = F_105 ( & V_9 -> V_239 ) ;
if ( F_46 ( V_239 > 1 ) ) {
F_107 ( V_21 , V_9 ) ;
V_695 = ( V_67 + 1 ) % V_670 ;
continue;
}
F_279 ( V_67 & ( V_628 - 1 ) ,
V_21 -> V_696 + ( V_67 / V_628 ) ) ;
break;
}
F_256 ( V_21 , V_67 , V_9 ) ;
return V_9 ;
}
static void F_107 ( struct V_1 * V_21 , struct V_8 * V_9 )
{
if ( F_59 ( & V_9 -> V_239 ) ) {
int V_67 ;
V_67 = V_9 - V_21 -> V_238 ;
F_280 ( V_67 & ( V_628 - 1 ) ,
V_21 -> V_696 + ( V_67 / V_628 ) ) ;
}
}
static int F_281 ( struct V_2 * V_29 , int V_286 ,
void T_7 * V_697 )
{
T_8 T_7 * V_698 =
( T_8 T_7 * ) V_697 ;
T_9 V_699 ;
T_9 T_7 * V_700 = F_282 ( sizeof( V_699 ) ) ;
int V_701 ;
T_4 V_131 ;
memset ( & V_699 , 0 , sizeof( V_699 ) ) ;
V_701 = 0 ;
V_701 |= F_283 ( & V_699 . V_702 , & V_698 -> V_702 ,
sizeof( V_699 . V_702 ) ) ;
V_701 |= F_283 ( & V_699 . V_144 , & V_698 -> V_144 ,
sizeof( V_699 . V_144 ) ) ;
V_701 |= F_283 ( & V_699 . V_703 , & V_698 -> V_703 ,
sizeof( V_699 . V_703 ) ) ;
V_701 |= F_284 ( V_699 . V_704 , & V_698 -> V_704 ) ;
V_701 |= F_284 ( V_131 , & V_698 -> V_44 ) ;
V_699 . V_44 = F_285 ( V_131 ) ;
V_701 |= F_286 ( V_700 , & V_699 , sizeof( V_699 ) ) ;
if ( V_701 )
return - V_705 ;
V_701 = F_287 ( V_29 , V_706 , V_700 ) ;
if ( V_701 )
return V_701 ;
V_701 |= F_288 ( & V_698 -> V_703 , & V_700 -> V_703 ,
sizeof( V_698 -> V_703 ) ) ;
if ( V_701 )
return - V_705 ;
return V_701 ;
}
static int F_289 ( struct V_2 * V_29 ,
int V_286 , void T_7 * V_697 )
{
T_10 T_7 * V_698 =
( T_10 T_7 * ) V_697 ;
T_11 V_699 ;
T_11 T_7 * V_700 =
F_282 ( sizeof( V_699 ) ) ;
int V_701 ;
T_4 V_131 ;
memset ( & V_699 , 0 , sizeof( V_699 ) ) ;
V_701 = 0 ;
V_701 |= F_283 ( & V_699 . V_702 , & V_698 -> V_702 ,
sizeof( V_699 . V_702 ) ) ;
V_701 |= F_283 ( & V_699 . V_144 , & V_698 -> V_144 ,
sizeof( V_699 . V_144 ) ) ;
V_701 |= F_283 ( & V_699 . V_703 , & V_698 -> V_703 ,
sizeof( V_699 . V_703 ) ) ;
V_701 |= F_284 ( V_699 . V_704 , & V_698 -> V_704 ) ;
V_701 |= F_284 ( V_699 . V_707 , & V_698 -> V_707 ) ;
V_701 |= F_284 ( V_131 , & V_698 -> V_44 ) ;
V_699 . V_44 = F_285 ( V_131 ) ;
V_701 |= F_286 ( V_700 , & V_699 , sizeof( V_699 ) ) ;
if ( V_701 )
return - V_705 ;
V_701 = F_287 ( V_29 , V_708 , V_700 ) ;
if ( V_701 )
return V_701 ;
V_701 |= F_288 ( & V_698 -> V_703 , & V_700 -> V_703 ,
sizeof( V_698 -> V_703 ) ) ;
if ( V_701 )
return - V_705 ;
return V_701 ;
}
static int F_290 ( struct V_2 * V_29 , int V_286 , void T_7 * V_697 )
{
switch ( V_286 ) {
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
return F_287 ( V_29 , V_286 , V_697 ) ;
case V_724 :
return F_281 ( V_29 , V_286 , V_697 ) ;
case V_725 :
return F_289 ( V_29 , V_286 , V_697 ) ;
default:
return - V_726 ;
}
}
static int F_291 ( struct V_1 * V_21 , void T_7 * V_727 )
{
struct V_728 V_729 ;
if ( ! V_727 )
return - V_54 ;
V_729 . V_730 = F_292 ( V_21 -> V_28 -> V_101 ) ;
V_729 . V_101 = V_21 -> V_28 -> V_101 -> V_731 ;
V_729 . V_732 = V_21 -> V_28 -> V_733 ;
V_729 . V_66 = V_21 -> V_66 ;
if ( F_286 ( V_727 , & V_729 , sizeof( V_729 ) ) )
return - V_705 ;
return 0 ;
}
static int F_293 ( struct V_1 * V_21 , void T_7 * V_727 )
{
T_12 V_734 ;
unsigned char V_735 , V_736 , V_737 ;
int V_20 ;
V_20 = sscanf ( V_738 , L_181 ,
& V_735 , & V_736 , & V_737 ) ;
if ( V_20 != 3 ) {
F_96 ( & V_21 -> V_28 -> V_29 , L_182
L_183 , V_738 ) ;
V_735 = 0 ;
V_736 = 0 ;
V_737 = 0 ;
}
V_734 = ( V_735 << 16 ) | ( V_736 << 8 ) | V_737 ;
if ( ! V_727 )
return - V_54 ;
if ( F_286 ( V_727 , & V_734 , sizeof( T_12 ) ) )
return - V_705 ;
return 0 ;
}
static int F_294 ( struct V_1 * V_21 , void T_7 * V_727 )
{
T_9 V_739 ;
struct V_8 * V_9 ;
char * V_740 = NULL ;
T_5 V_269 ;
int V_20 = 0 ;
if ( ! V_727 )
return - V_54 ;
if ( ! F_15 ( V_52 ) )
return - V_741 ;
if ( F_283 ( & V_739 , V_727 , sizeof( V_739 ) ) )
return - V_705 ;
if ( ( V_739 . V_704 < 1 ) &&
( V_739 . V_144 . Type . V_742 != V_641 ) ) {
return - V_54 ;
}
if ( V_739 . V_704 > 0 ) {
V_740 = F_93 ( V_739 . V_704 , V_203 ) ;
if ( V_740 == NULL )
return - V_263 ;
if ( V_739 . V_144 . Type . V_742 & V_639 ) {
if ( F_283 ( V_740 , V_739 . V_44 ,
V_739 . V_704 ) ) {
V_20 = - V_705 ;
goto V_743;
}
} else {
memset ( V_740 , 0 , V_739 . V_704 ) ;
}
}
V_9 = F_175 ( V_21 ) ;
V_9 -> V_150 = V_403 ;
V_9 -> V_10 = V_744 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_739 . V_704 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_282 = F_159 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_282 = F_159 ( 0 ) ;
}
memcpy ( & V_9 -> V_124 . V_350 , & V_739 . V_702 , sizeof( V_9 -> V_124 . V_350 ) ) ;
memcpy ( & V_9 -> V_144 , & V_739 . V_144 ,
sizeof( V_9 -> V_144 ) ) ;
if ( V_739 . V_704 > 0 ) {
V_269 = F_133 ( V_21 -> V_28 , V_740 ,
V_739 . V_704 , V_745 ) ;
if ( F_134 ( & V_21 -> V_28 -> V_29 , ( V_374 ) V_269 ) ) {
V_9 -> V_278 [ 0 ] . V_284 = F_135 ( 0 ) ;
V_9 -> V_278 [ 0 ] . V_283 = F_140 ( 0 ) ;
V_20 = - V_263 ;
goto V_396;
}
V_9 -> V_278 [ 0 ] . V_284 = F_135 ( V_269 ) ;
V_9 -> V_278 [ 0 ] . V_283 = F_140 ( V_739 . V_704 ) ;
V_9 -> V_278 [ 0 ] . V_280 = F_140 ( V_378 ) ;
}
V_20 = F_167 ( V_21 , V_9 , V_127 ,
V_382 ) ;
if ( V_739 . V_704 > 0 )
F_160 ( V_21 -> V_28 , V_9 , 1 , V_745 ) ;
F_295 ( V_21 , V_9 ) ;
if ( V_20 ) {
V_20 = - V_389 ;
goto V_396;
}
memcpy ( & V_739 . V_703 , V_9 -> V_23 ,
sizeof( V_739 . V_703 ) ) ;
if ( F_286 ( V_727 , & V_739 , sizeof( V_739 ) ) ) {
V_20 = - V_705 ;
goto V_396;
}
if ( ( V_739 . V_144 . Type . V_742 & V_640 ) &&
V_739 . V_704 > 0 ) {
if ( F_286 ( V_739 . V_44 , V_740 , V_739 . V_704 ) ) {
V_20 = - V_705 ;
goto V_396;
}
}
V_396:
F_107 ( V_21 , V_9 ) ;
V_743:
F_82 ( V_740 ) ;
return V_20 ;
}
static int F_296 ( struct V_1 * V_21 , void T_7 * V_727 )
{
T_11 * V_746 ;
struct V_8 * V_9 ;
unsigned char * * V_740 = NULL ;
int * V_747 = NULL ;
T_5 V_269 ;
T_13 V_372 = 0 ;
int V_48 = 0 ;
T_4 V_748 ;
T_4 V_749 ;
T_13 T_7 * V_750 ;
if ( ! V_727 )
return - V_54 ;
if ( ! F_15 ( V_52 ) )
return - V_741 ;
V_746 = F_93 ( sizeof( * V_746 ) , V_203 ) ;
if ( ! V_746 ) {
V_48 = - V_263 ;
goto V_751;
}
if ( F_283 ( V_746 , V_727 , sizeof( * V_746 ) ) ) {
V_48 = - V_705 ;
goto V_751;
}
if ( ( V_746 -> V_704 < 1 ) &&
( V_746 -> V_144 . Type . V_742 != V_641 ) ) {
V_48 = - V_54 ;
goto V_751;
}
if ( V_746 -> V_707 > V_752 ) {
V_48 = - V_54 ;
goto V_751;
}
if ( V_746 -> V_704 > V_746 -> V_707 * V_753 ) {
V_48 = - V_54 ;
goto V_751;
}
V_740 = F_116 ( V_753 * sizeof( char * ) , V_203 ) ;
if ( ! V_740 ) {
V_48 = - V_263 ;
goto V_751;
}
V_747 = F_93 ( V_753 * sizeof( int ) , V_203 ) ;
if ( ! V_747 ) {
V_48 = - V_263 ;
goto V_751;
}
V_748 = V_746 -> V_704 ;
V_750 = V_746 -> V_44 ;
while ( V_748 ) {
V_749 = ( V_748 > V_746 -> V_707 ) ? V_746 -> V_707 : V_748 ;
V_747 [ V_372 ] = V_749 ;
V_740 [ V_372 ] = F_93 ( V_749 , V_203 ) ;
if ( V_740 [ V_372 ] == NULL ) {
V_48 = - V_263 ;
goto V_751;
}
if ( V_746 -> V_144 . Type . V_742 & V_639 ) {
if ( F_283 ( V_740 [ V_372 ] , V_750 , V_749 ) ) {
V_48 = - V_705 ;
goto V_751;
}
} else
memset ( V_740 [ V_372 ] , 0 , V_749 ) ;
V_748 -= V_749 ;
V_750 += V_749 ;
V_372 ++ ;
}
V_9 = F_175 ( V_21 ) ;
V_9 -> V_150 = V_403 ;
V_9 -> V_10 = V_744 ;
V_9 -> V_124 . V_128 = 0 ;
V_9 -> V_124 . V_125 = ( T_1 ) V_372 ;
V_9 -> V_124 . V_282 = F_159 ( V_372 ) ;
memcpy ( & V_9 -> V_124 . V_350 , & V_746 -> V_702 , sizeof( V_9 -> V_124 . V_350 ) ) ;
memcpy ( & V_9 -> V_144 , & V_746 -> V_144 , sizeof( V_9 -> V_144 ) ) ;
if ( V_746 -> V_704 > 0 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_372 ; V_67 ++ ) {
V_269 = F_133 ( V_21 -> V_28 , V_740 [ V_67 ] ,
V_747 [ V_67 ] , V_745 ) ;
if ( F_134 ( & V_21 -> V_28 -> V_29 ,
( V_374 ) V_269 ) ) {
V_9 -> V_278 [ V_67 ] . V_284 = F_135 ( 0 ) ;
V_9 -> V_278 [ V_67 ] . V_283 = F_140 ( 0 ) ;
F_160 ( V_21 -> V_28 , V_9 , V_67 ,
V_745 ) ;
V_48 = - V_263 ;
goto V_754;
}
V_9 -> V_278 [ V_67 ] . V_284 = F_135 ( V_269 ) ;
V_9 -> V_278 [ V_67 ] . V_283 = F_140 ( V_747 [ V_67 ] ) ;
V_9 -> V_278 [ V_67 ] . V_280 = F_140 ( 0 ) ;
}
V_9 -> V_278 [ -- V_67 ] . V_280 = F_140 ( V_378 ) ;
}
V_48 = F_167 ( V_21 , V_9 , V_127 ,
V_382 ) ;
if ( V_372 )
F_160 ( V_21 -> V_28 , V_9 , V_372 , V_745 ) ;
F_295 ( V_21 , V_9 ) ;
if ( V_48 ) {
V_48 = - V_389 ;
goto V_754;
}
memcpy ( & V_746 -> V_703 , V_9 -> V_23 , sizeof( V_746 -> V_703 ) ) ;
if ( F_286 ( V_727 , V_746 , sizeof( * V_746 ) ) ) {
V_48 = - V_705 ;
goto V_754;
}
if ( ( V_746 -> V_144 . Type . V_742 & V_640 ) && V_746 -> V_704 > 0 ) {
int V_67 ;
T_13 T_7 * V_755 = V_746 -> V_44 ;
for ( V_67 = 0 ; V_67 < V_372 ; V_67 ++ ) {
if ( F_286 ( V_755 , V_740 [ V_67 ] , V_747 [ V_67 ] ) ) {
V_48 = - V_705 ;
goto V_754;
}
V_755 += V_747 [ V_67 ] ;
}
}
V_48 = 0 ;
V_754:
F_107 ( V_21 , V_9 ) ;
V_751:
if ( V_740 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_372 ; V_67 ++ )
F_82 ( V_740 [ V_67 ] ) ;
F_82 ( V_740 ) ;
}
F_82 ( V_747 ) ;
F_82 ( V_746 ) ;
return V_48 ;
}
static void F_295 ( struct V_1 * V_21 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_23 -> V_35 == V_36 &&
V_9 -> V_23 -> V_37 != V_297 )
( void ) F_8 ( V_21 , V_9 ) ;
}
static int F_287 ( struct V_2 * V_29 , int V_286 , void T_7 * V_697 )
{
struct V_1 * V_21 ;
void T_7 * V_727 = ( void T_7 * ) V_697 ;
int V_20 ;
V_21 = F_1 ( V_29 ) ;
switch ( V_286 ) {
case V_719 :
case V_720 :
case V_721 :
F_18 ( V_21 -> V_58 ) ;
return 0 ;
case V_709 :
return F_291 ( V_21 , V_727 ) ;
case V_717 :
return F_293 ( V_21 , V_727 ) ;
case V_706 :
if ( F_297 ( & V_21 -> V_756 ) < 0 )
return - V_466 ;
V_20 = F_294 ( V_21 , V_727 ) ;
F_57 ( & V_21 -> V_756 ) ;
return V_20 ;
case V_708 :
if ( F_297 ( & V_21 -> V_756 ) < 0 )
return - V_466 ;
V_20 = F_296 ( V_21 , V_727 ) ;
F_57 ( & V_21 -> V_756 ) ;
return V_20 ;
default:
return - V_757 ;
}
}
static void F_298 ( struct V_1 * V_21 , unsigned char * V_70 ,
T_1 V_399 )
{
struct V_8 * V_9 ;
V_9 = F_175 ( V_21 ) ;
( void ) F_176 ( V_9 , V_693 , V_21 , NULL , 0 , 0 ,
V_158 , V_400 ) ;
V_9 -> V_144 . V_145 [ 1 ] = V_399 ;
V_9 -> V_381 = NULL ;
F_62 ( V_21 , V_9 ) ;
return;
}
static int F_176 ( struct V_8 * V_9 , T_1 V_286 , struct V_1 * V_21 ,
void * V_740 , T_3 V_475 , T_6 V_758 , unsigned char * V_70 ,
int V_150 )
{
int V_759 = V_641 ;
V_9 -> V_150 = V_403 ;
V_9 -> V_10 = V_744 ;
V_9 -> V_124 . V_128 = 0 ;
if ( V_740 != NULL && V_475 > 0 ) {
V_9 -> V_124 . V_125 = 1 ;
V_9 -> V_124 . V_282 = F_159 ( 1 ) ;
} else {
V_9 -> V_124 . V_125 = 0 ;
V_9 -> V_124 . V_282 = F_159 ( 0 ) ;
}
memcpy ( V_9 -> V_124 . V_350 . V_351 , V_70 , 8 ) ;
if ( V_150 == V_395 ) {
switch ( V_286 ) {
case V_394 :
if ( V_758 & V_408 ) {
V_9 -> V_144 . V_145 [ 1 ] = 0x01 ;
V_9 -> V_144 . V_145 [ 2 ] = ( V_758 & 0xff ) ;
}
V_9 -> V_144 . V_346 = 6 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_394 ;
V_9 -> V_144 . V_145 [ 4 ] = V_475 & 0xFF ;
break;
case V_464 :
case V_465 :
V_9 -> V_144 . V_346 = 12 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_286 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_475 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_475 & 0xFF ;
break;
case V_760 :
V_9 -> V_144 . V_346 = 16 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 6 ] = V_760 ;
break;
case V_762 :
V_9 -> V_144 . V_346 = 16 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 ,
V_638 , V_639 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_762 ;
break;
case V_763 :
V_9 -> V_144 . V_346 = 12 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 ,
V_638 , V_639 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_142 ;
V_9 -> V_144 . V_145 [ 6 ] = V_764 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = V_475 & 0xFF ;
break;
case V_482 :
V_9 -> V_144 . V_346 = 6 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_641 ) ;
V_9 -> V_144 . V_636 = 0 ;
break;
case V_426 :
V_9 -> V_144 . V_346 = 12 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_765 ;
V_9 -> V_144 . V_145 [ 1 ] = V_286 ;
V_9 -> V_144 . V_145 [ 6 ] = ( V_475 >> 24 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 9 ] = V_475 & 0xFF ;
break;
case V_766 :
V_9 -> V_144 . V_346 = 10 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 6 ] = V_766 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0xFF ;
break;
case V_433 :
V_9 -> V_144 . V_346 = 10 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 6 ] = V_433 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0XFF ;
break;
case V_429 :
V_9 -> V_144 . V_346 = 10 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 6 ] = V_429 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0XFF ;
break;
case V_443 :
V_9 -> V_144 . V_346 = 10 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 6 ] = V_443 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0XFF ;
break;
case V_431 :
V_9 -> V_144 . V_346 = 10 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_640 ) ;
V_9 -> V_144 . V_636 = 0 ;
V_9 -> V_144 . V_145 [ 0 ] = V_761 ;
V_9 -> V_144 . V_145 [ 1 ] = 0 ;
V_9 -> V_144 . V_145 [ 2 ] = 0 ;
V_9 -> V_144 . V_145 [ 3 ] = 0 ;
V_9 -> V_144 . V_145 [ 4 ] = 0 ;
V_9 -> V_144 . V_145 [ 5 ] = 0 ;
V_9 -> V_144 . V_145 [ 6 ] = V_431 ;
V_9 -> V_144 . V_145 [ 7 ] = ( V_475 >> 16 ) & 0xFF ;
V_9 -> V_144 . V_145 [ 8 ] = ( V_475 >> 8 ) & 0XFF ;
V_9 -> V_144 . V_145 [ 9 ] = 0 ;
break;
default:
F_9 ( & V_21 -> V_28 -> V_29 , L_184 , V_286 ) ;
F_178 () ;
}
} else if ( V_150 == V_400 ) {
switch ( V_286 ) {
case V_694 :
V_9 -> V_144 . V_346 = 16 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_641 ) ;
V_9 -> V_144 . V_636 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_767 ;
V_9 -> V_144 . V_145 [ 1 ] = V_768 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
case V_693 :
V_9 -> V_144 . V_346 = 16 ;
V_9 -> V_144 . V_637 =
F_253 ( V_150 , V_638 , V_641 ) ;
V_9 -> V_144 . V_636 = 0 ;
memset ( & V_9 -> V_144 . V_145 [ 0 ] , 0 , sizeof( V_9 -> V_144 . V_145 ) ) ;
V_9 -> V_144 . V_145 [ 0 ] = V_286 ;
V_9 -> V_144 . V_145 [ 1 ] = V_769 ;
V_9 -> V_144 . V_145 [ 4 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 5 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 6 ] = 0x00 ;
V_9 -> V_144 . V_145 [ 7 ] = 0x00 ;
break;
default:
F_9 ( & V_21 -> V_28 -> V_29 , L_185 ,
V_286 ) ;
F_178 () ;
}
} else {
F_9 ( & V_21 -> V_28 -> V_29 , L_186 , V_150 ) ;
F_178 () ;
}
switch ( F_299 ( V_9 -> V_144 . V_637 ) ) {
case V_640 :
V_759 = V_397 ;
break;
case V_639 :
V_759 = V_273 ;
break;
case V_641 :
V_759 = V_377 ;
break;
default:
V_759 = V_745 ;
}
if ( F_161 ( V_21 -> V_28 , V_9 , V_740 , V_475 , V_759 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_300 ( T_15 V_770 , T_15 V_475 )
{
T_15 V_771 = ( ( T_15 ) V_770 ) & V_772 ;
T_15 V_773 = ( ( T_15 ) V_770 ) - V_771 ;
void T_14 * V_774 = F_301 ( V_771 ,
V_773 + V_475 ) ;
return V_774 ? ( V_774 + V_773 ) : NULL ;
}
static inline unsigned long F_302 ( struct V_1 * V_21 , T_1 V_110 )
{
return V_21 -> V_115 . V_116 ( V_21 , V_110 ) ;
}
static inline bool F_303 ( struct V_1 * V_21 )
{
return V_21 -> V_115 . V_775 ( V_21 ) ;
}
static inline long F_304 ( struct V_1 * V_21 )
{
return ( V_21 -> V_115 . V_775 ( V_21 ) == 0 ) ||
( V_21 -> V_776 == 0 ) ;
}
static inline int F_305 ( struct V_1 * V_21 , T_4 V_777 ,
T_4 V_778 )
{
if ( F_46 ( V_777 >= V_21 -> V_236 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_187 , V_778 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_63 ( struct V_8 * V_9 )
{
F_58 ( V_9 -> V_21 , V_9 ) ;
if ( F_49 ( V_9 -> V_150 == V_151 || V_9 -> V_150 == V_341
|| V_9 -> V_150 == V_154 ) )
F_156 ( V_9 ) ;
else if ( V_9 -> V_150 == V_403 || V_9 -> V_150 == V_156 )
F_306 ( V_9 -> V_381 ) ;
}
static inline void F_307 ( struct V_1 * V_21 ,
T_4 V_778 )
{
T_4 V_777 ;
struct V_8 * V_9 ;
V_777 = V_778 >> V_599 ;
if ( ! F_305 ( V_21 , V_777 , V_778 ) ) {
V_9 = V_21 -> V_238 + V_777 ;
F_63 ( V_9 ) ;
}
}
static int F_308 ( struct V_1 * V_21 )
{
if ( F_49 ( ! V_779 ) )
return 0 ;
if ( F_49 ( V_21 -> V_776 ) )
return 0 ;
F_96 ( & V_21 -> V_28 -> V_29 , L_188
L_189 ) ;
return 1 ;
}
static struct V_1 * F_309 ( T_1 * V_780 )
{
return F_258 ( ( V_780 - * V_780 ) , struct V_1 , V_110 [ 0 ] ) ;
}
static T_16 F_310 ( int V_675 , void * V_780 )
{
struct V_1 * V_21 = F_309 ( V_780 ) ;
T_1 V_110 = * ( T_1 * ) V_780 ;
T_4 V_778 ;
if ( F_308 ( V_21 ) )
return V_781 ;
if ( F_304 ( V_21 ) )
return V_781 ;
V_21 -> V_782 = F_311 () ;
while ( F_303 ( V_21 ) ) {
V_778 = F_302 ( V_21 , V_110 ) ;
while ( V_778 != V_120 )
V_778 = F_45 ( V_21 , V_110 ) ;
}
return V_783 ;
}
static T_16 F_312 ( int V_675 , void * V_780 )
{
struct V_1 * V_21 = F_309 ( V_780 ) ;
T_4 V_778 ;
T_1 V_110 = * ( T_1 * ) V_780 ;
if ( F_308 ( V_21 ) )
return V_781 ;
V_21 -> V_782 = F_311 () ;
V_778 = F_302 ( V_21 , V_110 ) ;
while ( V_778 != V_120 )
V_778 = F_45 ( V_21 , V_110 ) ;
return V_783 ;
}
static T_16 F_313 ( int V_675 , void * V_780 )
{
struct V_1 * V_21 = F_309 ( ( T_1 * ) V_780 ) ;
T_4 V_778 ;
T_1 V_110 = * ( T_1 * ) V_780 ;
if ( F_304 ( V_21 ) )
return V_781 ;
V_21 -> V_782 = F_311 () ;
while ( F_303 ( V_21 ) ) {
V_778 = F_302 ( V_21 , V_110 ) ;
while ( V_778 != V_120 ) {
F_307 ( V_21 , V_778 ) ;
V_778 = F_45 ( V_21 , V_110 ) ;
}
}
return V_783 ;
}
static T_16 F_314 ( int V_675 , void * V_780 )
{
struct V_1 * V_21 = F_309 ( V_780 ) ;
T_4 V_778 ;
T_1 V_110 = * ( T_1 * ) V_780 ;
V_21 -> V_782 = F_311 () ;
V_778 = F_302 ( V_21 , V_110 ) ;
while ( V_778 != V_120 ) {
F_307 ( V_21 , V_778 ) ;
V_778 = F_45 ( V_21 , V_110 ) ;
}
return V_783 ;
}
static int F_315 ( struct V_371 * V_28 , unsigned char V_784 ,
unsigned char type )
{
struct V_785 {
struct V_786 V_787 ;
struct V_788 V_144 ;
struct V_789 V_790 ;
};
struct V_785 * V_286 ;
static const T_3 V_791 = sizeof( * V_286 ) +
sizeof( V_286 -> V_790 ) ;
V_374 V_792 ;
T_17 V_793 ;
T_4 V_349 ;
void T_14 * V_152 ;
int V_67 , V_701 ;
V_152 = F_316 ( V_28 , 0 ) ;
if ( V_152 == NULL )
return - V_263 ;
V_701 = F_317 ( V_28 , F_318 ( 32 ) ) ;
if ( V_701 ) {
F_319 ( V_152 ) ;
return V_701 ;
}
V_286 = F_320 ( V_28 , V_791 , & V_792 ) ;
if ( V_286 == NULL ) {
F_319 ( V_152 ) ;
return - V_263 ;
}
V_793 = F_140 ( V_792 ) ;
V_286 -> V_787 . V_128 = 0 ;
V_286 -> V_787 . V_125 = 0 ;
V_286 -> V_787 . V_282 = F_159 ( 0 ) ;
V_286 -> V_787 . V_349 = F_135 ( V_792 ) ;
memset ( & V_286 -> V_787 . V_350 . V_351 , 0 , 8 ) ;
V_286 -> V_144 . V_346 = 16 ;
V_286 -> V_144 . V_637 =
F_253 ( V_400 , V_794 , V_641 ) ;
V_286 -> V_144 . V_636 = 0 ;
V_286 -> V_144 . V_145 [ 0 ] = V_784 ;
V_286 -> V_144 . V_145 [ 1 ] = type ;
memset ( & V_286 -> V_144 . V_145 [ 2 ] , 0 , 14 ) ;
V_286 -> V_790 . V_284 =
F_135 ( ( F_132 ( V_793 ) + sizeof( * V_286 ) ) ) ;
V_286 -> V_790 . V_283 = F_140 ( sizeof( struct V_338 ) ) ;
F_61 ( F_132 ( V_793 ) , V_152 + V_153 ) ;
for ( V_67 = 0 ; V_67 < V_795 ; V_67 ++ ) {
V_349 = F_321 ( V_152 + V_796 ) ;
if ( ( V_349 & ~ V_797 ) == V_792 )
break;
F_109 ( V_798 ) ;
}
F_319 ( V_152 ) ;
if ( V_67 == V_795 ) {
F_75 ( & V_28 -> V_29 , L_190 ,
V_784 , type ) ;
return - V_384 ;
}
F_322 ( V_28 , V_791 , V_286 , V_792 ) ;
if ( V_349 & V_799 ) {
F_75 ( & V_28 -> V_29 , L_191 ,
V_784 , type ) ;
return - V_389 ;
}
F_96 ( & V_28 -> V_29 , L_192 ,
V_784 , type ) ;
return 0 ;
}
static int F_323 ( struct V_371 * V_28 ,
void T_14 * V_152 , T_4 V_800 )
{
if ( V_800 ) {
F_96 ( & V_28 -> V_29 , L_193 ) ;
F_61 ( V_800 , V_152 + V_801 ) ;
F_109 ( 10000 ) ;
} else {
int V_20 = 0 ;
F_96 ( & V_28 -> V_29 , L_194 ) ;
V_20 = F_324 ( V_28 , V_802 ) ;
if ( V_20 )
return V_20 ;
F_109 ( 500 ) ;
V_20 = F_324 ( V_28 , V_803 ) ;
if ( V_20 )
return V_20 ;
F_109 ( 500 ) ;
}
return 0 ;
}
static void F_325 ( char * V_804 , int V_49 )
{
memset ( V_804 , 0 , V_49 ) ;
strncpy ( V_804 , V_40 L_195 V_738 , V_49 - 1 ) ;
}
static int F_326 ( struct V_805 T_14 * V_806 )
{
char * V_804 ;
int V_67 , V_475 = sizeof( V_806 -> V_804 ) ;
V_804 = F_93 ( V_475 , V_203 ) ;
if ( ! V_804 )
return - V_263 ;
F_325 ( V_804 , V_475 ) ;
for ( V_67 = 0 ; V_67 < V_475 ; V_67 ++ )
F_327 ( V_804 [ V_67 ] , & V_806 -> V_804 [ V_67 ] ) ;
F_82 ( V_804 ) ;
return 0 ;
}
static void F_328 ( struct V_805 T_14 * V_806 ,
unsigned char * V_807 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < sizeof( V_806 -> V_804 ) ; V_67 ++ )
V_807 [ V_67 ] = F_329 ( & V_806 -> V_804 [ V_67 ] ) ;
}
static int F_330 ( struct V_805 T_14 * V_806 )
{
char * V_807 , * V_808 ;
int V_20 , V_475 = sizeof( V_806 -> V_804 ) ;
V_808 = F_93 ( 2 * V_475 , V_203 ) ;
if ( ! V_808 )
return - V_263 ;
V_807 = V_808 + V_475 ;
F_325 ( V_808 , V_475 ) ;
F_328 ( V_806 , V_807 ) ;
V_20 = ! memcmp ( V_807 , V_808 , V_475 ) ;
F_82 ( V_808 ) ;
return V_20 ;
}
static int F_331 ( struct V_371 * V_28 , T_4 V_66 )
{
T_5 V_809 ;
T_4 V_810 ;
T_5 V_811 ;
void T_14 * V_152 ;
unsigned long V_812 ;
T_4 V_813 ;
int V_20 ;
struct V_805 T_14 * V_806 ;
T_4 V_800 ;
T_6 V_814 ;
if ( ! F_28 ( V_66 ) ) {
F_9 ( & V_28 -> V_29 , L_196 ) ;
return - V_79 ;
}
if ( ! F_25 ( V_66 ) )
return - V_815 ;
F_332 ( V_28 , 4 , & V_814 ) ;
F_333 ( V_28 ) ;
V_20 = F_334 ( V_28 , & V_812 ) ;
if ( V_20 )
return V_20 ;
V_152 = F_300 ( V_812 , 0x250 ) ;
if ( ! V_152 )
return - V_263 ;
V_20 = F_335 ( V_28 , V_152 , & V_810 ,
& V_811 , & V_809 ) ;
if ( V_20 )
goto V_816;
V_806 = F_300 ( F_336 ( V_28 ,
V_811 ) + V_809 , sizeof( * V_806 ) ) ;
if ( ! V_806 ) {
V_20 = - V_263 ;
goto V_816;
}
V_20 = F_326 ( V_806 ) ;
if ( V_20 )
goto V_817;
V_813 = F_321 ( & V_806 -> V_813 ) ;
V_800 = V_813 & V_818 ;
if ( V_800 ) {
V_800 = V_819 ;
} else {
V_800 = V_813 & V_820 ;
if ( V_800 ) {
F_9 ( & V_28 -> V_29 ,
L_197 ) ;
V_20 = - V_815 ;
goto V_817;
}
}
V_20 = F_323 ( V_28 , V_152 , V_800 ) ;
if ( V_20 )
goto V_817;
F_337 ( V_28 ) ;
F_338 ( V_28 , 4 , V_814 ) ;
F_109 ( V_821 ) ;
V_20 = F_339 ( V_28 , V_152 , V_822 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 ,
L_198 ) ;
goto V_817;
}
V_20 = F_330 ( V_152 ) ;
if ( V_20 < 0 )
goto V_817;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_199
L_200 ) ;
V_20 = - V_815 ;
} else {
F_96 ( & V_28 -> V_29 , L_201 ) ;
}
V_817:
F_319 ( V_806 ) ;
V_816:
F_319 ( V_152 ) ;
return V_20 ;
}
static void F_340 ( struct V_41 * V_29 , struct V_805 T_14 * V_823 )
{
#ifdef F_341
int V_67 ;
char V_824 [ 17 ] ;
F_96 ( V_29 , L_202 ) ;
F_96 ( V_29 , L_203 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
V_824 [ V_67 ] = F_329 ( & ( V_823 -> V_825 [ V_67 ] ) ) ;
V_824 [ 4 ] = '\0' ;
F_96 ( V_29 , L_204 , V_824 ) ;
F_96 ( V_29 , L_205 , F_321 ( & ( V_823 -> V_826 ) ) ) ;
F_96 ( V_29 , L_206 ,
F_321 ( & ( V_823 -> V_827 ) ) ) ;
F_96 ( V_29 , L_207 ,
F_321 ( & ( V_823 -> V_828 ) ) ) ;
F_96 ( V_29 , L_208 ,
F_321 ( & ( V_823 -> V_829 . V_830 ) ) ) ;
F_96 ( V_29 , L_209 ,
F_321 ( & ( V_823 -> V_829 . V_831 ) ) ) ;
F_96 ( V_29 , L_210 ,
F_321 ( & ( V_823 -> V_829 . V_832 ) ) ) ;
F_96 ( V_29 , L_211 ,
F_321 ( & ( V_823 -> V_833 ) ) ) ;
F_96 ( V_29 , L_212 , F_321 ( & ( V_823 -> V_834 ) ) ) ;
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ )
V_824 [ V_67 ] = F_329 ( & ( V_823 -> V_835 [ V_67 ] ) ) ;
V_824 [ 16 ] = '\0' ;
F_96 ( V_29 , L_213 , V_824 ) ;
F_96 ( V_29 , L_214 ,
F_321 ( & ( V_823 -> V_836 ) ) ) ;
#endif
}
static int F_342 ( struct V_371 * V_28 , unsigned long V_837 )
{
int V_67 , V_695 , V_838 , V_839 ;
if ( V_837 == V_840 )
return 0 ;
V_695 = 0 ;
for ( V_67 = 0 ; V_67 < V_841 ; V_67 ++ ) {
V_839 = F_343 ( V_28 , V_67 ) & V_842 ;
if ( V_839 == V_843 )
V_695 += 4 ;
else {
V_838 = F_343 ( V_28 , V_67 ) &
V_844 ;
switch ( V_838 ) {
case V_845 :
case V_846 :
V_695 += 4 ;
break;
case V_847 :
V_695 += 8 ;
break;
default:
F_9 ( & V_28 -> V_29 ,
L_215 ) ;
return - 1 ;
break;
}
}
if ( V_695 == V_837 - V_840 )
return V_67 + 1 ;
}
return - 1 ;
}
static void F_344 ( struct V_1 * V_21 )
{
F_345 ( V_21 -> V_28 ) ;
V_21 -> V_126 = 0 ;
}
static int F_346 ( struct V_1 * V_21 )
{
unsigned int V_76 = V_848 ;
int V_849 ;
switch ( V_21 -> V_66 ) {
case 0x40700E11 :
case 0x40800E11 :
case 0x40820E11 :
case 0x40830E11 :
break;
default:
V_849 = F_347 ( V_21 -> V_28 , 1 , V_850 ,
V_851 | V_852 ) ;
if ( V_849 > 0 ) {
V_21 -> V_126 = V_849 ;
return 0 ;
}
V_76 |= V_853 ;
break;
}
V_849 = F_347 ( V_21 -> V_28 , 1 , 1 , V_76 ) ;
if ( V_849 < 0 )
return V_849 ;
return 0 ;
}
static int F_348 ( struct V_371 * V_28 , T_4 * V_66 ,
bool * V_109 )
{
int V_67 ;
T_4 V_854 , V_855 ;
V_854 = V_28 -> V_856 ;
V_855 = V_28 -> V_857 ;
* V_66 = ( ( V_855 << 16 ) & 0xffff0000 ) |
V_854 ;
if ( V_109 )
* V_109 = false ;
for ( V_67 = 0 ; V_67 < F_26 ( V_858 ) ; V_67 ++ )
if ( * V_66 == V_858 [ V_67 ] . V_66 ) {
if ( V_858 [ V_67 ] . V_115 != & V_859 &&
V_858 [ V_67 ] . V_115 != & V_860 )
return V_67 ;
F_9 ( & V_28 -> V_29 ,
L_216 ,
* V_66 ) ;
if ( V_109 )
* V_109 = true ;
return V_67 ;
}
F_9 ( & V_28 -> V_29 , L_217 , * V_66 ) ;
if ( V_109 )
* V_109 = true ;
return F_26 ( V_858 ) - 1 ;
}
static int F_334 ( struct V_371 * V_28 ,
unsigned long * V_861 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_841 ; V_67 ++ )
if ( F_343 ( V_28 , V_67 ) & V_862 ) {
* V_861 = F_336 ( V_28 , V_67 ) ;
F_349 ( & V_28 -> V_29 , L_218 ,
* V_861 ) ;
return 0 ;
}
F_9 ( & V_28 -> V_29 , L_219 ) ;
return - V_79 ;
}
static int F_339 ( struct V_371 * V_28 , void T_14 * V_152 ,
int V_863 )
{
int V_67 , V_864 ;
T_4 V_865 ;
if ( V_863 )
V_864 = V_866 ;
else
V_864 = V_867 ;
for ( V_67 = 0 ; V_67 < V_864 ; V_67 ++ ) {
V_865 = F_321 ( V_152 + V_868 ) ;
if ( V_863 ) {
if ( V_865 == V_869 )
return 0 ;
} else {
if ( V_865 != V_869 )
return 0 ;
}
F_109 ( V_870 ) ;
}
F_9 ( & V_28 -> V_29 , L_220 ) ;
return - V_79 ;
}
static int F_335 ( struct V_371 * V_28 , void T_14 * V_152 ,
T_4 * V_810 , T_5 * V_811 ,
T_5 * V_809 )
{
* V_810 = F_321 ( V_152 + V_871 ) ;
* V_809 = F_321 ( V_152 + V_872 ) ;
* V_810 &= ( T_4 ) 0x0000ffff ;
* V_811 = F_342 ( V_28 , * V_810 ) ;
if ( * V_811 == - 1 ) {
F_9 ( & V_28 -> V_29 , L_221 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_350 ( struct V_1 * V_21 )
{
if ( V_21 -> V_873 ) {
F_319 ( V_21 -> V_873 ) ;
V_21 -> V_873 = NULL ;
}
if ( V_21 -> V_806 ) {
F_319 ( V_21 -> V_806 ) ;
V_21 -> V_806 = NULL ;
}
}
static int F_351 ( struct V_1 * V_21 )
{
T_5 V_809 ;
T_4 V_810 ;
T_5 V_811 ;
T_4 V_874 ;
int V_20 ;
V_20 = F_335 ( V_21 -> V_28 , V_21 -> V_152 , & V_810 ,
& V_811 , & V_809 ) ;
if ( V_20 )
return V_20 ;
V_21 -> V_806 = F_300 ( F_336 ( V_21 -> V_28 ,
V_811 ) + V_809 , sizeof( * V_21 -> V_806 ) ) ;
if ( ! V_21 -> V_806 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_222 ) ;
return - V_263 ;
}
V_20 = F_326 ( V_21 -> V_806 ) ;
if ( V_20 )
return V_20 ;
V_874 = F_321 ( & V_21 -> V_806 -> V_875 ) ;
V_21 -> V_873 = F_300 ( F_336 ( V_21 -> V_28 ,
V_811 ) + V_809 + V_874 ,
sizeof( * V_21 -> V_873 ) ) ;
if ( ! V_21 -> V_873 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_223 ) ;
F_350 ( V_21 ) ;
return - V_263 ;
}
return 0 ;
}
static void F_352 ( struct V_1 * V_21 )
{
#define F_353 16
F_354 ( F_353 <= V_670 ) ;
V_21 -> V_121 = F_321 ( & V_21 -> V_806 -> V_876 ) ;
if ( V_779 && V_21 -> V_121 > 32 )
V_21 -> V_121 = 32 ;
if ( V_21 -> V_121 < F_353 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_224 ,
V_21 -> V_121 ,
F_353 ) ;
V_21 -> V_121 = F_353 ;
}
}
static int F_355 ( struct V_1 * V_21 )
{
return V_21 -> V_264 > 512 ;
}
static void F_356 ( struct V_1 * V_21 )
{
F_352 ( V_21 ) ;
V_21 -> V_236 = V_21 -> V_121 ;
V_21 -> V_264 = F_321 ( & ( V_21 -> V_806 -> V_877 ) ) ;
V_21 -> V_490 = F_321 ( & ( V_21 -> V_806 -> V_813 ) ) ;
if ( F_355 ( V_21 ) ) {
V_21 -> V_279 = 32 ;
V_21 -> V_262 = V_21 -> V_264 - V_21 -> V_279 ;
V_21 -> V_264 -- ;
} else {
V_21 -> V_279 = 31 ;
V_21 -> V_264 = 31 ;
V_21 -> V_262 = 0 ;
}
V_21 -> V_878 = F_321 ( & ( V_21 -> V_806 -> V_878 ) ) ;
if ( ! ( V_879 & V_21 -> V_878 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_225 ) ;
if ( ! ( V_880 & V_21 -> V_878 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_226 ) ;
if ( ! ( V_881 & V_21 -> V_878 ) )
F_9 ( & V_21 -> V_28 -> V_29 , L_227 ) ;
}
static inline bool F_357 ( struct V_1 * V_21 )
{
if ( ! F_358 ( V_21 -> V_806 -> V_825 , L_228 , 4 ) ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_229 ) ;
return false ;
}
return true ;
}
static inline void F_359 ( struct V_1 * V_21 )
{
T_4 V_882 ;
V_882 = F_321 ( & ( V_21 -> V_806 -> V_882 ) ) ;
#ifdef F_360
V_882 |= V_883 ;
#endif
V_882 |= V_884 ;
F_61 ( V_882 , & ( V_21 -> V_806 -> V_882 ) ) ;
}
static inline void F_361 ( struct V_1 * V_21 )
{
T_4 V_885 ;
if ( V_21 -> V_66 != 0x3225103C )
return;
V_885 = F_321 ( V_21 -> V_152 + V_886 ) ;
V_885 |= 0x8000 ;
F_61 ( V_885 , V_21 -> V_152 + V_886 ) ;
}
static int F_362 ( struct V_1 * V_21 )
{
int V_67 ;
T_4 V_887 ;
unsigned long V_76 ;
for ( V_67 = 0 ; V_67 < V_888 ; V_67 ++ ) {
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_887 = F_321 ( V_21 -> V_152 + V_801 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( ! ( V_887 & V_889 ) )
goto V_890;
F_109 ( V_891 ) ;
}
return - V_79 ;
V_890:
return 0 ;
}
static int F_363 ( struct V_1 * V_21 )
{
int V_67 ;
T_4 V_887 ;
unsigned long V_76 ;
for ( V_67 = 0 ; V_67 < V_892 ; V_67 ++ ) {
if ( V_21 -> V_893 )
goto V_890;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_887 = F_321 ( V_21 -> V_152 + V_801 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( ! ( V_887 & V_894 ) )
goto V_890;
F_109 ( V_895 ) ;
}
return - V_79 ;
V_890:
return 0 ;
}
static int F_364 ( struct V_1 * V_21 )
{
T_4 V_896 ;
V_896 = F_321 ( & ( V_21 -> V_806 -> V_827 ) ) ;
if ( ! ( V_896 & V_897 ) )
return - V_815 ;
V_21 -> V_121 = F_321 ( & ( V_21 -> V_806 -> V_833 ) ) ;
F_61 ( V_898 , & ( V_21 -> V_806 -> V_829 . V_830 ) ) ;
F_61 ( 0 , & V_21 -> V_806 -> V_829 . V_899 ) ;
F_61 ( V_894 , V_21 -> V_152 + V_801 ) ;
if ( F_363 ( V_21 ) )
goto error;
F_340 ( & V_21 -> V_28 -> V_29 , V_21 -> V_806 ) ;
if ( ! ( F_321 ( & ( V_21 -> V_806 -> V_828 ) ) & V_898 ) )
goto error;
V_21 -> V_62 = V_898 ;
return 0 ;
error:
F_75 ( & V_21 -> V_28 -> V_29 , L_230 ) ;
return - V_79 ;
}
static void F_365 ( struct V_1 * V_21 )
{
F_350 ( V_21 ) ;
F_319 ( V_21 -> V_152 ) ;
V_21 -> V_152 = NULL ;
F_344 ( V_21 ) ;
F_366 ( V_21 -> V_28 ) ;
F_367 ( V_21 -> V_28 ) ;
}
static int F_368 ( struct V_1 * V_21 )
{
int V_900 , V_701 ;
bool V_109 ;
V_900 = F_348 ( V_21 -> V_28 , & V_21 -> V_66 , & V_109 ) ;
if ( V_900 < 0 )
return V_900 ;
V_21 -> V_901 = V_858 [ V_900 ] . V_901 ;
V_21 -> V_115 = * ( V_858 [ V_900 ] . V_115 ) ;
V_21 -> V_109 = V_109 ;
F_369 ( V_21 -> V_28 , V_902 |
V_903 | V_904 ) ;
V_701 = F_370 ( V_21 -> V_28 ) ;
if ( V_701 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_231 ) ;
F_366 ( V_21 -> V_28 ) ;
return V_701 ;
}
V_701 = F_371 ( V_21 -> V_28 , V_40 ) ;
if ( V_701 ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_232 ) ;
F_366 ( V_21 -> V_28 ) ;
return V_701 ;
}
F_372 ( V_21 -> V_28 ) ;
V_701 = F_346 ( V_21 ) ;
if ( V_701 )
goto V_905;
V_701 = F_334 ( V_21 -> V_28 , & V_21 -> V_812 ) ;
if ( V_701 )
goto V_906;
V_21 -> V_152 = F_300 ( V_21 -> V_812 , 0x250 ) ;
if ( ! V_21 -> V_152 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_233 ) ;
V_701 = - V_263 ;
goto V_906;
}
V_701 = F_339 ( V_21 -> V_28 , V_21 -> V_152 , V_822 ) ;
if ( V_701 )
goto V_907;
V_701 = F_351 ( V_21 ) ;
if ( V_701 )
goto V_907;
F_356 ( V_21 ) ;
if ( ! F_357 ( V_21 ) ) {
V_701 = - V_79 ;
goto V_908;
}
F_359 ( V_21 ) ;
F_361 ( V_21 ) ;
V_701 = F_364 ( V_21 ) ;
if ( V_701 )
goto V_908;
return 0 ;
V_908:
F_350 ( V_21 ) ;
V_907:
F_319 ( V_21 -> V_152 ) ;
V_21 -> V_152 = NULL ;
V_906:
F_344 ( V_21 ) ;
V_905:
F_366 ( V_21 -> V_28 ) ;
F_367 ( V_21 -> V_28 ) ;
return V_701 ;
}
static void F_373 ( struct V_1 * V_21 )
{
int V_20 ;
#define F_374 64
V_21 -> V_60 = F_93 ( F_374 , V_203 ) ;
if ( ! V_21 -> V_60 )
return;
V_20 = F_174 ( V_21 , V_158 , 0 ,
V_21 -> V_60 , F_374 ) ;
if ( V_20 != 0 ) {
F_82 ( V_21 -> V_60 ) ;
V_21 -> V_60 = NULL ;
}
}
static int F_375 ( struct V_371 * V_28 , T_4 V_66 )
{
int V_20 , V_67 ;
void T_14 * V_152 ;
if ( ! V_779 )
return 0 ;
V_20 = F_370 ( V_28 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_234 ) ;
return - V_79 ;
}
F_366 ( V_28 ) ;
F_109 ( 260 ) ;
V_20 = F_370 ( V_28 ) ;
if ( V_20 ) {
F_9 ( & V_28 -> V_29 , L_235 ) ;
return - V_79 ;
}
F_372 ( V_28 ) ;
V_152 = F_316 ( V_28 , 0 ) ;
if ( V_152 == NULL ) {
V_20 = - V_263 ;
goto V_909;
}
F_61 ( V_910 , V_152 + V_911 ) ;
F_319 ( V_152 ) ;
V_20 = F_331 ( V_28 , V_66 ) ;
if ( V_20 )
goto V_909;
F_96 ( & V_28 -> V_29 , L_236 ) ;
for ( V_67 = 0 ; V_67 < V_912 ; V_67 ++ ) {
if ( F_376 ( V_28 ) == 0 )
break;
else
F_9 ( & V_28 -> V_29 , L_237 ,
( V_67 < 11 ? L_238 : L_239 ) ) ;
}
V_909:
F_366 ( V_28 ) ;
return V_20 ;
}
static void F_377 ( struct V_1 * V_21 )
{
F_82 ( V_21 -> V_696 ) ;
V_21 -> V_696 = NULL ;
if ( V_21 -> V_238 ) {
F_322 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( struct V_8 ) ,
V_21 -> V_238 ,
V_21 -> V_647 ) ;
V_21 -> V_238 = NULL ;
V_21 -> V_647 = 0 ;
}
if ( V_21 -> V_648 ) {
F_322 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( struct V_338 ) ,
V_21 -> V_648 ,
V_21 -> V_649 ) ;
V_21 -> V_648 = NULL ;
V_21 -> V_649 = 0 ;
}
}
static int F_378 ( struct V_1 * V_21 )
{
V_21 -> V_696 = F_116 (
F_379 ( V_21 -> V_236 , V_628 ) *
sizeof( unsigned long ) , V_203 ) ;
V_21 -> V_238 = F_320 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_238 ) ,
& ( V_21 -> V_647 ) ) ;
V_21 -> V_648 = F_320 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_648 ) ,
& ( V_21 -> V_649 ) ) ;
if ( ( V_21 -> V_696 == NULL )
|| ( V_21 -> V_238 == NULL )
|| ( V_21 -> V_648 == NULL ) ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_240 , V_242 ) ;
goto V_913;
}
F_255 ( V_21 ) ;
return 0 ;
V_913:
F_377 ( V_21 ) ;
return - V_263 ;
}
static void F_380 ( struct V_1 * V_21 )
{
int V_67 ;
if ( ! V_21 -> V_126 || V_21 -> V_914 != V_915 ) {
F_381 ( F_268 ( V_21 -> V_28 , 0 ) , & V_21 -> V_110 [ V_21 -> V_914 ] ) ;
V_21 -> V_110 [ V_21 -> V_914 ] = 0 ;
return;
}
for ( V_67 = 0 ; V_67 < V_21 -> V_126 ; V_67 ++ ) {
F_381 ( F_268 ( V_21 -> V_28 , V_67 ) , & V_21 -> V_110 [ V_67 ] ) ;
V_21 -> V_110 [ V_67 ] = 0 ;
}
for (; V_67 < V_850 ; V_67 ++ )
V_21 -> V_110 [ V_67 ] = 0 ;
}
static int F_382 ( struct V_1 * V_21 ,
T_16 (* F_383)( int , void * ) ,
T_16 (* F_384)( int , void * ) )
{
int V_20 , V_67 ;
for ( V_67 = 0 ; V_67 < V_850 ; V_67 ++ )
V_21 -> V_110 [ V_67 ] = ( T_1 ) V_67 ;
if ( V_21 -> V_914 == V_915 && V_21 -> V_126 > 0 ) {
for ( V_67 = 0 ; V_67 < V_21 -> V_126 ; V_67 ++ ) {
sprintf ( V_21 -> V_916 [ V_67 ] , L_241 , V_21 -> V_30 , V_67 ) ;
V_20 = F_385 ( F_268 ( V_21 -> V_28 , V_67 ) , F_383 ,
0 , V_21 -> V_916 [ V_67 ] ,
& V_21 -> V_110 [ V_67 ] ) ;
if ( V_20 ) {
int V_193 ;
F_75 ( & V_21 -> V_28 -> V_29 ,
L_242 ,
F_268 ( V_21 -> V_28 , V_67 ) , V_21 -> V_30 ) ;
for ( V_193 = 0 ; V_193 < V_67 ; V_193 ++ ) {
F_381 ( F_268 ( V_21 -> V_28 , V_193 ) , & V_21 -> V_110 [ V_193 ] ) ;
V_21 -> V_110 [ V_193 ] = 0 ;
}
for (; V_193 < V_850 ; V_193 ++ )
V_21 -> V_110 [ V_193 ] = 0 ;
return V_20 ;
}
}
} else {
if ( V_21 -> V_126 > 0 || V_21 -> V_28 -> V_917 ) {
sprintf ( V_21 -> V_916 [ 0 ] , L_243 , V_21 -> V_30 ,
V_21 -> V_126 ? L_244 : L_239 ) ;
V_20 = F_385 ( F_268 ( V_21 -> V_28 , 0 ) ,
F_383 , 0 ,
V_21 -> V_916 [ 0 ] ,
& V_21 -> V_110 [ V_21 -> V_914 ] ) ;
} else {
sprintf ( V_21 -> V_916 [ V_21 -> V_914 ] ,
L_245 , V_21 -> V_30 ) ;
V_20 = F_385 ( F_268 ( V_21 -> V_28 , 0 ) ,
F_384 , V_918 ,
V_21 -> V_916 [ 0 ] ,
& V_21 -> V_110 [ V_21 -> V_914 ] ) ;
}
}
if ( V_20 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_242 ,
F_268 ( V_21 -> V_28 , 0 ) , V_21 -> V_30 ) ;
F_380 ( V_21 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_386 ( struct V_1 * V_21 )
{
int V_20 ;
F_298 ( V_21 , V_158 , V_919 ) ;
F_96 ( & V_21 -> V_28 -> V_29 , L_246 ) ;
V_20 = F_339 ( V_21 -> V_28 , V_21 -> V_152 , V_920 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_247 ) ;
return V_20 ;
}
F_96 ( & V_21 -> V_28 -> V_29 , L_248 ) ;
V_20 = F_339 ( V_21 -> V_28 , V_21 -> V_152 , V_822 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 , L_249
L_250 ) ;
return V_20 ;
}
return 0 ;
}
static void F_387 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ ) {
if ( ! V_21 -> V_113 [ V_67 ] . V_117 )
continue;
F_322 ( V_21 -> V_28 ,
V_21 -> V_921 ,
V_21 -> V_113 [ V_67 ] . V_117 ,
V_21 -> V_113 [ V_67 ] . V_122 ) ;
V_21 -> V_113 [ V_67 ] . V_117 = NULL ;
V_21 -> V_113 [ V_67 ] . V_122 = 0 ;
}
V_21 -> V_921 = 0 ;
}
static void F_388 ( struct V_1 * V_21 )
{
F_389 ( V_21 ) ;
F_129 ( V_21 ) ;
F_377 ( V_21 ) ;
F_380 ( V_21 ) ;
F_390 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
F_365 ( V_21 ) ;
F_391 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
if ( V_21 -> V_329 ) {
F_392 ( V_21 -> V_329 ) ;
V_21 -> V_329 = NULL ;
}
if ( V_21 -> V_922 ) {
F_392 ( V_21 -> V_922 ) ;
V_21 -> V_922 = NULL ;
}
F_82 ( V_21 ) ;
}
static void F_393 ( struct V_1 * V_21 )
{
int V_67 , V_239 ;
struct V_8 * V_9 ;
int V_923 = 0 ;
F_394 ( V_21 -> V_329 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
V_9 = V_21 -> V_238 + V_67 ;
V_239 = F_105 ( & V_9 -> V_239 ) ;
if ( V_239 > 1 ) {
V_9 -> V_23 -> V_35 = V_344 ;
F_63 ( V_9 ) ;
F_47 ( & V_21 -> V_61 ) ;
V_923 ++ ;
}
F_107 ( V_21 , V_9 ) ;
}
F_9 ( & V_21 -> V_28 -> V_29 ,
L_251 , V_923 ) ;
}
static void F_395 ( struct V_1 * V_21 , T_4 V_924 )
{
int V_385 ;
F_396 (cpu) {
T_4 * F_13 ;
F_13 = F_169 ( V_21 -> F_13 , V_385 ) ;
* F_13 = V_924 ;
}
F_78 () ;
}
static void F_397 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
T_4 F_13 ;
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
F_13 = F_321 ( V_21 -> V_152 + V_868 ) ;
if ( ! F_13 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_252 ,
V_21 -> V_147 / V_927 ) ;
F_13 = 0xffffffff ;
}
F_395 ( V_21 , F_13 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_9 ( & V_21 -> V_28 -> V_29 , L_253 ,
F_13 , V_21 -> V_147 / V_927 ) ;
F_366 ( V_21 -> V_28 ) ;
F_393 ( V_21 ) ;
}
static int F_276 ( struct V_1 * V_21 )
{
T_5 V_928 ;
T_4 V_929 ;
unsigned long V_76 ;
V_928 = F_311 () ;
if ( F_398 ( V_21 -> V_782 +
( V_21 -> V_147 ) , V_928 ) )
return false ;
if ( F_398 ( V_21 -> V_930 +
( V_21 -> V_147 ) , V_928 ) )
return false ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_929 = F_321 ( & V_21 -> V_806 -> V_836 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_931 == V_929 ) {
F_397 ( V_21 ) ;
return true ;
}
V_21 -> V_931 = V_929 ;
V_21 -> V_930 = V_928 ;
return false ;
}
static void F_399 ( struct V_1 * V_21 )
{
int V_67 ;
char * V_932 ;
if ( ! ( V_21 -> V_490 & V_933 ) )
return;
if ( ( V_21 -> V_62 & ( V_114
| V_934 ) ) &&
( V_21 -> V_935 & V_936 ||
V_21 -> V_935 & V_937 ) ) {
if ( V_21 -> V_935 & V_936 )
V_932 = L_254 ;
if ( V_21 -> V_935 & V_937 )
V_932 = L_255 ;
F_400 ( V_21 -> V_58 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
V_21 -> V_29 [ V_67 ] -> V_89 = 0 ;
V_21 -> V_29 [ V_67 ] -> V_183 = 0 ;
}
F_401 ( V_21 ) ;
F_9 ( & V_21 -> V_28 -> V_29 ,
L_256 ,
V_21 -> V_935 , V_932 ) ;
F_61 ( V_21 -> V_935 , & ( V_21 -> V_806 -> V_938 ) ) ;
F_61 ( V_889 , V_21 -> V_152 + V_801 ) ;
F_362 ( V_21 ) ;
F_402 ( V_21 -> V_58 ) ;
} else {
F_61 ( V_21 -> V_935 , & ( V_21 -> V_806 -> V_938 ) ) ;
F_61 ( V_889 , V_21 -> V_152 + V_801 ) ;
F_362 ( V_21 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_403 ( struct V_1 * V_21 )
{
if ( V_21 -> V_250 ) {
V_21 -> V_250 = 0 ;
return 1 ;
}
if ( ! ( V_21 -> V_490 & V_933 ) )
return 0 ;
V_21 -> V_935 = F_321 ( & ( V_21 -> V_806 -> V_939 ) ) ;
return V_21 -> V_935 & V_940 ;
}
static int F_404 ( struct V_1 * V_21 )
{
unsigned long V_76 ;
struct V_201 * V_391 ;
struct V_941 * V_942 , * V_943 ;
F_34 ( & V_21 -> V_202 , V_76 ) ;
F_405 (this, tmp, &h->offline_device_list) {
V_391 = F_406 ( V_942 , struct V_201 ,
V_204 ) ;
F_35 ( & V_21 -> V_202 , V_76 ) ;
if ( ! F_209 ( V_21 , V_391 -> V_70 ) ) {
F_34 ( & V_21 -> V_202 , V_76 ) ;
F_407 ( & V_391 -> V_204 ) ;
F_35 ( & V_21 -> V_202 , V_76 ) ;
return 1 ;
}
F_34 ( & V_21 -> V_202 , V_76 ) ;
}
F_35 ( & V_21 -> V_202 , V_76 ) ;
return 0 ;
}
static int F_408 ( struct V_1 * V_21 )
{
int V_20 = 1 ;
struct V_467 * V_500 = NULL ;
if ( ! V_21 -> V_944 )
return V_20 ;
V_500 = F_116 ( sizeof( * V_500 ) , V_203 ) ;
if ( ! V_500 )
return V_20 ;
if ( F_204 ( V_21 , 1 , V_500 , sizeof( * V_500 ) , 0 ) ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_257 ) ;
goto V_396;
}
if ( memcmp ( V_500 , V_21 -> V_944 , sizeof( * V_500 ) ) ) {
F_96 ( & V_21 -> V_28 -> V_29 ,
L_258 ) ;
memcpy ( V_21 -> V_944 , V_500 , sizeof( * V_500 ) ) ;
goto V_396;
} else
V_20 = 0 ;
V_396:
F_82 ( V_500 ) ;
return V_20 ;
}
static void F_409 ( struct V_1 * V_21 )
{
struct V_6 * V_7 = NULL ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_248 , V_76 ) ;
if ( V_21 -> V_249 ) {
V_21 -> V_250 = 1 ;
F_35 ( & V_21 -> V_248 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_248 , V_76 ) ;
V_7 = F_410 ( V_21 -> V_58 ) ;
if ( V_7 != NULL ) {
F_18 ( V_7 ) ;
F_390 ( V_7 ) ;
V_21 -> V_250 = 0 ;
}
}
static void F_411 ( struct V_651 * V_327 )
{
struct V_1 * V_21 = F_258 ( F_412 ( V_327 ) ,
struct V_1 , V_945 ) ;
unsigned long V_76 ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_893 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( F_403 ( V_21 ) ) {
F_399 ( V_21 ) ;
F_409 ( V_21 ) ;
}
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_893 )
F_413 ( & V_21 -> V_945 ,
V_946 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static void F_414 ( struct V_651 * V_327 )
{
unsigned long V_76 ;
struct V_1 * V_21 = F_258 ( F_412 ( V_327 ) ,
struct V_1 , V_947 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_893 ) {
F_35 ( & V_21 -> V_77 , V_76 ) ;
return;
}
F_35 ( & V_21 -> V_77 , V_76 ) ;
if ( V_21 -> V_250 || F_404 ( V_21 ) ) {
F_409 ( V_21 ) ;
} else if ( V_21 -> V_535 ) {
F_415 ( V_21 ) ;
if ( F_408 ( V_21 ) ) {
F_96 ( & V_21 -> V_28 -> V_29 ,
L_259 ) ;
F_409 ( V_21 ) ;
}
}
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_893 )
F_416 ( V_21 -> V_922 , & V_21 -> V_947 ,
V_21 -> V_147 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static void F_417 ( struct V_651 * V_327 )
{
unsigned long V_76 ;
struct V_1 * V_21 = F_258 ( F_412 ( V_327 ) ,
struct V_1 , V_948 ) ;
F_276 ( V_21 ) ;
if ( F_13 ( V_21 ) )
return;
F_34 ( & V_21 -> V_77 , V_76 ) ;
if ( ! V_21 -> V_893 )
F_413 ( & V_21 -> V_948 ,
V_21 -> V_147 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
}
static struct V_949 * F_418 ( struct V_1 * V_21 ,
char * V_950 )
{
struct V_949 * V_951 = NULL ;
V_951 = F_419 ( L_260 , 0 , V_950 , V_21 -> V_108 ) ;
if ( ! V_951 )
F_75 ( & V_21 -> V_28 -> V_29 , L_261 , V_950 ) ;
return V_951 ;
}
static int F_420 ( struct V_371 * V_28 , const struct V_952 * V_953 )
{
int V_954 , V_20 ;
struct V_1 * V_21 ;
int V_955 = 0 ;
unsigned long V_76 ;
T_4 V_66 ;
if ( V_956 == 0 )
F_421 (KERN_INFO DRIVER_NAME L_262 ) ;
V_20 = F_348 ( V_28 , & V_66 , NULL ) ;
if ( V_20 < 0 ) {
F_9 ( & V_28 -> V_29 , L_263 ) ;
return V_20 ;
}
V_20 = F_375 ( V_28 , V_66 ) ;
if ( V_20 ) {
if ( V_20 != - V_815 )
return V_20 ;
V_955 = 1 ;
V_20 = 0 ;
}
V_957:
F_354 ( sizeof( struct V_8 ) % V_958 ) ;
V_21 = F_116 ( sizeof( * V_21 ) , V_203 ) ;
if ( ! V_21 ) {
F_75 ( & V_28 -> V_29 , L_264 ) ;
return - V_263 ;
}
V_21 -> V_28 = V_28 ;
V_21 -> V_914 = V_959 ? V_960 : V_915 ;
F_422 ( & V_21 -> V_205 ) ;
F_423 ( & V_21 -> V_77 ) ;
F_423 ( & V_21 -> V_202 ) ;
F_423 ( & V_21 -> V_655 ) ;
F_423 ( & V_21 -> V_248 ) ;
F_123 ( & V_21 -> V_756 , V_961 ) ;
V_21 -> F_13 = F_424 ( T_4 ) ;
if ( ! V_21 -> F_13 ) {
F_75 ( & V_21 -> V_28 -> V_29 , L_265 ) ;
V_20 = - V_263 ;
goto V_905;
}
F_395 ( V_21 , 0 ) ;
V_20 = F_368 ( V_21 ) ;
if ( V_20 )
goto V_906;
V_20 = F_266 ( V_21 ) ;
if ( V_20 )
goto V_962;
sprintf ( V_21 -> V_30 , V_40 L_9 , V_21 -> V_58 -> V_100 ) ;
V_21 -> V_108 = V_956 ;
V_956 ++ ;
V_20 = F_425 ( V_28 , F_318 ( 64 ) ) ;
if ( V_20 == 0 ) {
V_954 = 1 ;
} else {
V_20 = F_425 ( V_28 , F_318 ( 32 ) ) ;
if ( V_20 == 0 ) {
V_954 = 0 ;
} else {
F_75 ( & V_28 -> V_29 , L_266 ) ;
goto V_907;
}
}
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
V_20 = F_382 ( V_21 , F_314 , F_313 ) ;
if ( V_20 )
goto V_907;
V_20 = F_378 ( V_21 ) ;
if ( V_20 )
goto V_908;
V_20 = F_130 ( V_21 ) ;
if ( V_20 )
goto V_963;
F_426 ( & V_21 -> V_657 ) ;
F_426 ( & V_21 -> V_325 ) ;
F_427 ( & V_21 -> V_405 ) ;
V_21 -> V_656 = 1 ;
V_21 -> V_658 = 0 ;
F_428 ( V_28 , V_21 ) ;
V_21 -> V_162 = 0 ;
F_423 ( & V_21 -> V_96 ) ;
V_20 = F_429 ( V_21 ) ;
if ( V_20 )
goto V_964;
V_21 -> V_922 = F_418 ( V_21 , L_267 ) ;
if ( ! V_21 -> V_922 ) {
V_20 = - V_263 ;
goto V_965;
}
V_21 -> V_329 = F_418 ( V_21 , L_268 ) ;
if ( ! V_21 -> V_329 ) {
V_20 = - V_263 ;
goto V_965;
}
if ( V_955 ) {
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_380 ( V_21 ) ;
V_20 = F_382 ( V_21 , F_312 ,
F_310 ) ;
if ( V_20 ) {
F_9 ( & V_21 -> V_28 -> V_29 ,
L_269 ) ;
F_389 ( V_21 ) ;
F_129 ( V_21 ) ;
F_377 ( V_21 ) ;
goto V_907;
}
V_20 = F_386 ( V_21 ) ;
if ( V_20 )
goto V_965;
F_96 ( & V_21 -> V_28 -> V_29 , L_270 ) ;
F_96 ( & V_21 -> V_28 -> V_29 ,
L_271 ) ;
V_21 -> V_115 . V_925 ( V_21 , V_966 ) ;
F_109 ( 10000 ) ;
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
V_20 = F_330 ( V_21 -> V_806 ) ;
if ( V_20 )
F_96 ( & V_21 -> V_28 -> V_29 ,
L_272 ) ;
F_388 ( V_21 ) ;
V_955 = 0 ;
if ( V_20 )
return - V_79 ;
goto V_957;
}
V_21 -> V_55 = 1 ;
V_21 -> V_535 = 0 ;
V_21 -> V_115 . V_925 ( V_21 , V_966 ) ;
F_373 ( V_21 ) ;
V_21 -> V_944 = F_116 ( sizeof( * ( V_21 -> V_944 ) ) , V_203 ) ;
if ( ! V_21 -> V_944 )
F_96 ( & V_21 -> V_28 -> V_29 ,
L_273 ) ;
V_20 = F_269 ( V_21 ) ;
if ( V_20 )
goto V_965;
V_21 -> V_147 = V_149 ;
F_430 ( & V_21 -> V_948 , F_417 ) ;
F_413 ( & V_21 -> V_948 ,
V_21 -> V_147 ) ;
F_430 ( & V_21 -> V_947 , F_414 ) ;
F_416 ( V_21 -> V_922 , & V_21 -> V_947 ,
V_21 -> V_147 ) ;
F_430 ( & V_21 -> V_945 , F_411 ) ;
F_413 ( & V_21 -> V_945 ,
V_946 ) ;
return 0 ;
V_965:
F_389 ( V_21 ) ;
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
V_964:
F_129 ( V_21 ) ;
V_963:
F_377 ( V_21 ) ;
V_908:
F_380 ( V_21 ) ;
V_907:
F_390 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
V_962:
F_365 ( V_21 ) ;
V_906:
if ( V_21 -> F_13 ) {
F_391 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
}
V_905:
if ( V_21 -> V_329 ) {
F_392 ( V_21 -> V_329 ) ;
V_21 -> V_329 = NULL ;
}
if ( V_21 -> V_922 ) {
F_392 ( V_21 -> V_922 ) ;
V_21 -> V_922 = NULL ;
}
F_82 ( V_21 ) ;
return V_20 ;
}
static void F_431 ( struct V_1 * V_21 )
{
char * V_967 ;
struct V_8 * V_9 ;
int V_20 ;
if ( F_46 ( F_13 ( V_21 ) ) )
return;
V_967 = F_116 ( 4 , V_203 ) ;
if ( ! V_967 )
return;
V_9 = F_175 ( V_21 ) ;
if ( F_176 ( V_9 , V_763 , V_21 , V_967 , 4 , 0 ,
V_158 , V_395 ) ) {
goto V_396;
}
V_20 = F_171 ( V_21 , V_9 ,
V_273 , V_398 ) ;
if ( V_20 )
goto V_396;
if ( V_9 -> V_23 -> V_35 != 0 )
V_396:
F_9 ( & V_21 -> V_28 -> V_29 ,
L_274 ) ;
F_107 ( V_21 , V_9 ) ;
F_82 ( V_967 ) ;
}
static void F_415 ( struct V_1 * V_21 )
{
T_4 * V_968 ;
struct V_8 * V_9 ;
int V_20 ;
if ( F_46 ( V_21 -> F_13 ) )
return;
V_968 = F_116 ( sizeof( * V_968 ) , V_203 ) ;
if ( ! V_968 )
return;
V_9 = F_175 ( V_21 ) ;
if ( F_176 ( V_9 , V_760 , V_21 , V_968 , 4 , 0 ,
V_158 , V_395 ) )
goto V_969;
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_969;
* V_968 |= V_970 ;
if ( F_176 ( V_9 , V_762 , V_21 , V_968 , 4 , 0 ,
V_158 , V_395 ) )
goto V_969;
V_20 = F_171 ( V_21 , V_9 ,
V_273 , V_398 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_969;
if ( F_176 ( V_9 , V_760 , V_21 , V_968 , 4 , 0 ,
V_158 , V_395 ) )
goto V_969;
V_20 = F_171 ( V_21 , V_9 ,
V_397 , V_398 ) ;
if ( ( V_20 != 0 ) || ( V_9 -> V_23 -> V_35 != 0 ) )
goto V_969;
if ( * V_968 & V_970 )
goto V_396;
V_969:
F_75 ( & V_21 -> V_28 -> V_29 ,
L_275 ) ;
V_396:
F_107 ( V_21 , V_9 ) ;
F_82 ( V_968 ) ;
}
static void F_432 ( struct V_371 * V_28 )
{
struct V_1 * V_21 ;
V_21 = F_433 ( V_28 ) ;
F_431 ( V_21 ) ;
V_21 -> V_115 . V_925 ( V_21 , V_926 ) ;
F_380 ( V_21 ) ;
F_344 ( V_21 ) ;
}
static void F_434 ( struct V_1 * V_21 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
F_82 ( V_21 -> V_29 [ V_67 ] ) ;
V_21 -> V_29 [ V_67 ] = NULL ;
}
}
static void F_435 ( struct V_371 * V_28 )
{
struct V_1 * V_21 ;
unsigned long V_76 ;
if ( F_433 ( V_28 ) == NULL ) {
F_75 ( & V_28 -> V_29 , L_276 ) ;
return;
}
V_21 = F_433 ( V_28 ) ;
F_34 ( & V_21 -> V_77 , V_76 ) ;
V_21 -> V_893 = 1 ;
F_35 ( & V_21 -> V_77 , V_76 ) ;
F_436 ( & V_21 -> V_948 ) ;
F_436 ( & V_21 -> V_947 ) ;
F_436 ( & V_21 -> V_945 ) ;
F_392 ( V_21 -> V_922 ) ;
F_392 ( V_21 -> V_329 ) ;
if ( V_21 -> V_58 )
F_437 ( V_21 -> V_58 ) ;
F_432 ( V_28 ) ;
F_434 ( V_21 ) ;
F_82 ( V_21 -> V_60 ) ;
V_21 -> V_60 = NULL ;
F_127 ( V_21 ) ;
F_389 ( V_21 ) ;
F_129 ( V_21 ) ;
F_377 ( V_21 ) ;
F_82 ( V_21 -> V_944 ) ;
F_390 ( V_21 -> V_58 ) ;
V_21 -> V_58 = NULL ;
F_365 ( V_21 ) ;
F_391 ( V_21 -> F_13 ) ;
V_21 -> F_13 = NULL ;
F_438 ( V_21 ) ;
F_82 ( V_21 ) ;
}
static void F_439 ( int V_971 [] , int V_972 ,
int V_973 , int V_974 , T_4 * V_975 )
{
int V_67 , V_193 , V_976 , V_475 ;
for ( V_67 = 0 ; V_67 <= V_973 ; V_67 ++ ) {
V_475 = V_67 + V_974 ;
V_976 = V_972 ;
for ( V_193 = 0 ; V_193 < V_972 ; V_193 ++ ) {
if ( V_971 [ V_193 ] >= V_475 ) {
V_976 = V_193 ;
break;
}
}
V_975 [ V_67 ] = V_976 ;
}
}
static int F_440 ( struct V_1 * V_21 , T_4 V_896 )
{
int V_67 ;
unsigned long V_977 ;
unsigned long V_62 = V_63 |
( V_896 & V_978 ) |
V_979 |
( V_896 & ( V_114 |
V_934 ) ) ;
struct V_980 V_115 = V_981 ;
int V_982 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_753 + 4 } ;
#define F_441 5
#define F_442 4
int V_983 [ 16 ] = { F_441 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_442 + V_984 } ;
F_354 ( F_26 ( V_983 ) != 16 ) ;
F_354 ( F_26 ( V_982 ) != 8 ) ;
F_354 ( F_248 ( struct V_139 , V_271 ) >
16 * F_441 ) ;
F_354 ( sizeof( struct V_267 ) != 16 ) ;
F_354 ( 28 > V_753 + 4 ) ;
if ( V_896 & ( V_114 | V_934 ) )
V_115 = V_985 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ )
memset ( V_21 -> V_113 [ V_67 ] . V_117 , 0 , V_21 -> V_921 ) ;
V_982 [ 7 ] = V_753 + 4 ;
F_439 ( V_982 , F_26 ( V_982 ) ,
V_753 , 4 , V_21 -> V_123 ) ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ )
F_61 ( V_982 [ V_67 ] , & V_21 -> V_873 -> V_986 [ V_67 ] ) ;
F_61 ( V_21 -> V_121 , & V_21 -> V_873 -> V_987 ) ;
F_61 ( V_21 -> V_129 , & V_21 -> V_873 -> V_988 ) ;
F_61 ( 0 , & V_21 -> V_873 -> V_989 ) ;
F_61 ( 0 , & V_21 -> V_873 -> V_990 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ ) {
F_61 ( 0 , & V_21 -> V_873 -> V_991 [ V_67 ] . V_992 ) ;
F_61 ( V_21 -> V_113 [ V_67 ] . V_122 ,
& V_21 -> V_873 -> V_991 [ V_67 ] . V_993 ) ;
}
F_61 ( 0 , & V_21 -> V_806 -> V_829 . V_899 ) ;
F_61 ( V_62 , & ( V_21 -> V_806 -> V_829 . V_830 ) ) ;
if ( V_896 & V_114 ) {
V_115 = V_994 ;
F_61 ( 10 , & V_21 -> V_806 -> V_829 . V_831 ) ;
F_61 ( 4 , & V_21 -> V_806 -> V_829 . V_832 ) ;
} else
if ( V_896 & V_934 )
V_115 = V_995 ;
F_61 ( V_894 , V_21 -> V_152 + V_801 ) ;
if ( F_363 ( V_21 ) ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_277 ) ;
return - V_79 ;
}
V_977 = F_321 ( & ( V_21 -> V_806 -> V_828 ) ) ;
if ( ! ( V_977 & V_63 ) ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_278 ) ;
return - V_79 ;
}
V_21 -> V_115 = V_115 ;
V_21 -> V_62 = V_62 ;
if ( ! ( ( V_896 & V_114 ) ||
( V_896 & V_934 ) ) )
return 0 ;
if ( V_896 & V_114 ) {
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ ) {
F_61 ( V_67 , V_21 -> V_152 + V_996 ) ;
V_21 -> V_113 [ V_67 ] . V_118 =
F_321 ( V_21 -> V_152 + V_997 ) ;
}
V_982 [ 7 ] = V_21 -> V_569 + 8 ;
F_439 ( V_982 , F_26 ( V_982 ) , V_21 -> V_569 , 8 ,
V_21 -> V_134 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ )
memset ( V_21 -> V_113 [ V_67 ] . V_117 ,
( T_1 ) V_998 ,
V_21 -> V_921 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
struct V_130 * V_131 = & V_21 -> V_132 [ V_67 ] ;
V_131 -> V_999 = V_1000 ;
V_131 -> V_23 = ( T_4 ) ( V_21 -> V_649 +
( V_67 * sizeof( struct V_338 ) ) ) ;
V_131 -> V_1001 = sizeof( struct V_338 ) ;
V_131 -> V_1002 = V_1003 ;
V_131 -> V_1004 =
F_159 ( V_1005 ) ;
V_131 -> V_1006 = 0 ;
V_131 -> V_128 = 0 ;
V_131 -> V_349 =
F_135 ( ( V_67 << V_599 ) ) ;
V_131 -> V_1007 =
F_135 ( V_21 -> V_572 +
( V_67 * sizeof( struct V_130 ) ) ) ;
}
} else if ( V_896 & V_934 ) {
T_5 V_809 , V_811 ;
T_4 V_1008 , V_810 ;
int V_20 ;
V_20 = F_335 ( V_21 -> V_28 , V_21 -> V_152 , & V_810 ,
& V_811 , & V_809 ) ;
F_354 ( F_248 ( struct V_139 , V_271 ) != 64 ) ;
V_983 [ 15 ] = V_21 -> V_569 + F_442 ;
F_439 ( V_983 , F_26 ( V_983 ) , V_21 -> V_569 ,
4 , V_21 -> V_138 ) ;
V_1008 = F_321 ( & V_21 -> V_806 -> V_1009 ) ;
F_354 ( F_248 ( struct V_805 ,
V_1009 ) != 0xb8 ) ;
V_21 -> V_1010 =
F_300 ( F_336 ( V_21 -> V_28 ,
V_811 ) +
V_809 + V_1008 ,
F_26 ( V_983 ) *
sizeof( * V_21 -> V_1010 ) ) ;
for ( V_67 = 0 ; V_67 < F_26 ( V_983 ) ; V_67 ++ )
F_61 ( V_983 [ V_67 ] , & V_21 -> V_1010 [ V_67 ] ) ;
}
F_61 ( V_894 , V_21 -> V_152 + V_801 ) ;
if ( F_363 ( V_21 ) ) {
F_75 ( & V_21 -> V_28 -> V_29 ,
L_279 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_443 ( struct V_1 * V_21 )
{
if ( V_21 -> V_132 ) {
F_322 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_132 ) ,
V_21 -> V_132 ,
V_21 -> V_572 ) ;
V_21 -> V_132 = NULL ;
V_21 -> V_572 = 0 ;
}
F_82 ( V_21 -> V_134 ) ;
V_21 -> V_134 = NULL ;
}
static int F_444 ( struct V_1 * V_21 )
{
V_21 -> V_569 =
F_321 ( & ( V_21 -> V_806 -> V_1011 ) ) ;
if ( V_21 -> V_569 > V_1012 )
V_21 -> V_569 = V_1012 ;
F_354 ( sizeof( struct V_130 ) %
V_1013 ) ;
V_21 -> V_132 =
F_320 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_132 ) ,
& ( V_21 -> V_572 ) ) ;
V_21 -> V_134 =
F_93 ( ( ( V_21 -> V_569 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_21 -> V_132 == NULL ) ||
( V_21 -> V_134 == NULL ) )
goto V_913;
memset ( V_21 -> V_132 , 0 ,
V_21 -> V_236 * sizeof( * V_21 -> V_132 ) ) ;
return 0 ;
V_913:
F_443 ( V_21 ) ;
return - V_263 ;
}
static void F_445 ( struct V_1 * V_21 )
{
F_127 ( V_21 ) ;
if ( V_21 -> V_137 ) {
F_322 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_137 ) ,
V_21 -> V_137 ,
V_21 -> V_589 ) ;
V_21 -> V_137 = NULL ;
V_21 -> V_589 = 0 ;
}
F_82 ( V_21 -> V_138 ) ;
V_21 -> V_138 = NULL ;
}
static int F_446 ( struct V_1 * V_21 )
{
int V_20 ;
V_21 -> V_569 =
F_321 ( & ( V_21 -> V_806 -> V_1011 ) ) ;
if ( V_21 -> V_569 > V_984 )
V_21 -> V_569 = V_984 ;
F_354 ( sizeof( struct V_139 ) %
V_1014 ) ;
V_21 -> V_137 =
F_320 ( V_21 -> V_28 ,
V_21 -> V_236 * sizeof( * V_21 -> V_137 ) ,
& ( V_21 -> V_589 ) ) ;
V_21 -> V_138 =
F_93 ( ( ( V_21 -> V_569 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ( V_21 -> V_137 == NULL ) ||
( V_21 -> V_138 == NULL ) ) {
V_20 = - V_263 ;
goto V_913;
}
V_20 = F_128 ( V_21 ) ;
if ( V_20 )
goto V_913;
memset ( V_21 -> V_137 , 0 ,
V_21 -> V_236 * sizeof( * V_21 -> V_137 ) ) ;
return 0 ;
V_913:
F_445 ( V_21 ) ;
return V_20 ;
}
static void F_389 ( struct V_1 * V_21 )
{
F_82 ( V_21 -> V_123 ) ;
V_21 -> V_123 = NULL ;
F_387 ( V_21 ) ;
F_443 ( V_21 ) ;
F_445 ( V_21 ) ;
}
static int F_429 ( struct V_1 * V_21 )
{
T_4 V_896 ;
unsigned long V_62 = V_63 |
V_978 ;
int V_67 , V_20 ;
if ( V_959 )
return 0 ;
V_896 = F_321 ( & ( V_21 -> V_806 -> V_827 ) ) ;
if ( ! ( V_896 & V_1015 ) )
return 0 ;
if ( V_896 & V_114 ) {
V_62 |= V_114 |
V_979 ;
V_20 = F_444 ( V_21 ) ;
if ( V_20 )
return V_20 ;
} else if ( V_896 & V_934 ) {
V_62 |= V_934 |
V_979 ;
V_20 = F_446 ( V_21 ) ;
if ( V_20 )
return V_20 ;
}
V_21 -> V_129 = V_21 -> V_126 > 0 ? V_21 -> V_126 : 1 ;
F_352 ( V_21 ) ;
V_21 -> V_921 = V_21 -> V_121 * sizeof( T_5 ) ;
for ( V_67 = 0 ; V_67 < V_21 -> V_129 ; V_67 ++ ) {
V_21 -> V_113 [ V_67 ] . V_117 = F_320 ( V_21 -> V_28 ,
V_21 -> V_921 ,
& ( V_21 -> V_113 [ V_67 ] . V_122 ) ) ;
if ( ! V_21 -> V_113 [ V_67 ] . V_117 ) {
V_20 = - V_263 ;
goto V_905;
}
V_21 -> V_113 [ V_67 ] . V_475 = V_21 -> V_121 ;
V_21 -> V_113 [ V_67 ] . V_119 = 1 ;
V_21 -> V_113 [ V_67 ] . V_118 = 0 ;
}
V_21 -> V_123 = F_93 ( ( ( V_753 + 1 ) *
sizeof( T_4 ) ) , V_203 ) ;
if ( ! V_21 -> V_123 ) {
V_20 = - V_263 ;
goto V_905;
}
V_20 = F_440 ( V_21 , V_896 ) ;
if ( V_20 )
goto V_906;
return 0 ;
V_906:
F_82 ( V_21 -> V_123 ) ;
V_21 -> V_123 = NULL ;
V_905:
F_387 ( V_21 ) ;
F_443 ( V_21 ) ;
F_445 ( V_21 ) ;
return V_20 ;
}
static int F_447 ( struct V_8 * V_9 )
{
return V_9 -> V_150 == V_151 || V_9 -> V_150 == V_154 ;
}
static void F_401 ( struct V_1 * V_21 )
{
struct V_8 * V_9 = NULL ;
int V_67 , V_1016 ;
int V_239 ;
do {
V_1016 = 0 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_236 ; V_67 ++ ) {
V_9 = V_21 -> V_238 + V_67 ;
V_239 = F_105 ( & V_9 -> V_239 ) ;
if ( V_239 > 1 )
V_1016 += F_447 ( V_9 ) ;
F_107 ( V_21 , V_9 ) ;
}
if ( V_1016 <= 0 )
break;
F_109 ( 100 ) ;
} while ( 1 );
}
static struct V_1017 * F_448 (
struct V_1018 * V_1018 )
{
struct V_1017 * V_1017 ;
struct V_1019 * V_1020 ;
V_1017 = F_116 ( sizeof( * V_1017 ) , V_203 ) ;
if ( ! V_1017 )
return NULL ;
V_1020 = F_449 ( V_1018 -> V_1021 -> V_1022 ,
V_1018 -> V_1023 ) ;
if ( ! V_1020 ) {
F_82 ( V_1017 ) ;
return NULL ;
}
V_1018 -> V_1023 ++ ;
V_1017 -> V_1020 = V_1020 ;
V_1017 -> V_1024 = V_1018 ;
return V_1017 ;
}
static void F_450 ( struct V_1017 * V_1017 )
{
struct V_1019 * V_1020 = V_1017 -> V_1020 ;
F_451 ( V_1017 -> V_1024 -> V_1025 , V_1020 ) ;
F_452 ( V_1020 ) ;
if ( V_1017 -> V_1026 )
F_407 ( & V_1017 -> V_1027 ) ;
F_82 ( V_1017 ) ;
}
static int F_453 ( struct V_1017 * V_1017 )
{
int V_20 ;
struct V_1018 * V_1018 ;
struct V_1019 * V_1020 ;
struct V_1028 * V_1029 ;
V_1018 = V_1017 -> V_1024 ;
V_1020 = V_1017 -> V_1020 ;
V_1029 = & V_1020 -> V_1029 ;
memset ( V_1029 , 0 , sizeof( * V_1029 ) ) ;
V_1029 -> V_87 = V_1018 -> V_87 ;
V_1029 -> V_519 = V_1030 ;
V_1029 -> V_1031 = V_1032 ;
V_1029 -> V_1033 = V_1032 ;
V_1020 -> V_1034 = V_1035 ;
V_1020 -> V_1036 = V_1035 ;
V_1020 -> V_1037 = V_1035 ;
V_1020 -> V_1038 = V_1035 ;
V_1020 -> V_1039 = V_1035 ;
V_20 = F_454 ( V_1017 -> V_1020 ) ;
if ( V_20 )
return V_20 ;
F_455 ( V_1018 -> V_1025 , V_1017 -> V_1020 ) ;
F_94 ( & V_1017 -> V_1027 ,
& V_1018 -> V_1040 ) ;
V_1017 -> V_1026 = true ;
return 0 ;
}
static int
F_456 ( struct V_1018 * V_1018 ,
struct V_255 * V_256 )
{
struct V_1028 * V_1029 ;
V_1029 = & V_256 -> V_1029 ;
V_1029 -> V_87 = V_1018 -> V_87 ;
V_1029 -> V_1031 = V_1032 ;
V_1029 -> V_1033 = V_1032 ;
return F_457 ( V_256 ) ;
}
static struct V_1018
* F_458 ( struct V_1041 * V_1041 ,
T_5 V_87 )
{
int V_20 ;
struct V_1018 * V_1018 ;
struct V_1042 * V_1025 ;
V_1018 = F_116 ( sizeof( * V_1018 ) , V_203 ) ;
if ( ! V_1018 )
return NULL ;
F_422 ( & V_1018 -> V_1040 ) ;
V_1018 -> V_1021 = V_1041 ;
V_1025 = F_459 ( V_1041 -> V_1022 ) ;
if ( ! V_1025 )
goto V_1043;
V_20 = F_460 ( V_1025 ) ;
if ( V_20 )
goto V_1044;
V_1018 -> V_1025 = V_1025 ;
V_1018 -> V_87 = V_87 ;
F_94 ( & V_1018 -> V_1045 ,
& V_1041 -> V_1046 ) ;
return V_1018 ;
V_1044:
F_461 ( V_1025 ) ;
V_1043:
F_82 ( V_1018 ) ;
return NULL ;
}
static void F_462 ( struct V_1018 * V_1018 )
{
struct V_1017 * V_1017 ;
struct V_1017 * V_1047 ;
F_463 (hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
F_450 ( V_1017 ) ;
F_464 ( V_1018 -> V_1025 ) ;
F_407 ( & V_1018 -> V_1045 ) ;
F_82 ( V_1018 ) ;
}
static struct V_1041 * F_465 ( struct V_41 * V_1022 )
{
struct V_1041 * V_1041 ;
V_1041 = F_116 ( sizeof( * V_1041 ) , V_203 ) ;
if ( V_1041 ) {
V_1041 -> V_1022 = V_1022 ;
F_422 ( & V_1041 -> V_1046 ) ;
}
return V_1041 ;
}
static void F_466 ( struct V_1041 * V_1041 )
{
struct V_1018 * V_1018 ;
struct V_1018 * V_1047 ;
if ( ! V_1041 )
return;
F_463 (hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
F_462 ( V_1018 ) ;
F_82 ( V_1041 ) ;
}
static struct V_71
* F_121 ( struct V_1 * V_21 ,
struct V_255 * V_256 )
{
int V_67 ;
struct V_71 * V_41 ;
for ( V_67 = 0 ; V_67 < V_21 -> V_162 ; V_67 ++ ) {
V_41 = V_21 -> V_29 [ V_67 ] ;
if ( ! V_41 -> V_1042 )
continue;
if ( V_41 -> V_1042 -> V_256 == V_256 )
return V_41 ;
}
return NULL ;
}
static int F_231 ( struct V_1 * V_21 )
{
int V_20 ;
struct V_41 * V_1022 ;
struct V_1041 * V_1041 ;
struct V_1018 * V_1018 ;
struct V_1017 * V_1017 ;
V_1022 = & V_21 -> V_58 -> V_1048 ;
V_1041 = F_465 ( V_1022 ) ;
if ( ! V_1041 )
return - V_263 ;
V_1018 = F_458 ( V_1041 , V_21 -> V_87 ) ;
if ( ! V_1018 ) {
V_20 = - V_79 ;
goto V_1049;
}
V_1017 = F_448 ( V_1018 ) ;
if ( ! V_1017 ) {
V_20 = - V_79 ;
goto V_1044;
}
V_20 = F_453 ( V_1017 ) ;
if ( V_20 )
goto V_1050;
V_21 -> V_237 = V_1041 ;
return 0 ;
V_1050:
F_450 ( V_1017 ) ;
V_1044:
F_462 ( V_1018 ) ;
V_1049:
F_466 ( V_1041 ) ;
return V_20 ;
}
static void F_438 ( struct V_1 * V_21 )
{
F_466 ( V_21 -> V_237 ) ;
}
static int F_103 ( struct V_1041 * V_1041 ,
struct V_71 * V_41 )
{
int V_20 ;
struct V_1018 * V_1018 ;
struct V_255 * V_256 ;
V_1018 = F_458 ( V_1041 , V_41 -> V_87 ) ;
if ( ! V_1018 )
return - V_263 ;
V_256 = F_467 ( V_1018 -> V_1025 ) ;
if ( ! V_256 ) {
V_20 = - V_79 ;
goto V_1044;
}
V_1018 -> V_256 = V_256 ;
V_41 -> V_1042 = V_1018 ;
V_20 = F_456 ( V_1018 , V_256 ) ;
if ( V_20 )
goto V_1044;
return 0 ;
V_1044:
F_462 ( V_1018 ) ;
V_41 -> V_1042 = NULL ;
return V_20 ;
}
static void F_114 ( struct V_71 * V_41 )
{
if ( V_41 -> V_1042 ) {
F_462 ( V_41 -> V_1042 ) ;
V_41 -> V_1042 = NULL ;
}
}
static int
F_468 ( struct V_1019 * V_1020 )
{
return 0 ;
}
static int
F_469 ( struct V_255 * V_256 , T_5 * V_1051 )
{
* V_1051 = 0 ;
return 0 ;
}
static int
F_470 ( struct V_255 * V_256 )
{
return - V_1052 ;
}
static int
F_471 ( struct V_1019 * V_1020 , int V_1053 )
{
return 0 ;
}
static int
F_472 ( struct V_1019 * V_1020 , int V_1054 )
{
return 0 ;
}
static int
F_473 ( struct V_1019 * V_1020 )
{
return 0 ;
}
static void
F_474 ( struct V_1019 * V_1020 )
{
}
static int
F_475 ( struct V_1019 * V_1020 , struct V_1055 * V_1056 )
{
return - V_54 ;
}
static int T_18 F_476 ( void )
{
int V_20 ;
V_674 =
F_477 ( & V_1057 ) ;
if ( ! V_674 )
return - V_79 ;
V_20 = F_478 ( & V_1058 ) ;
if ( V_20 )
F_479 ( V_674 ) ;
return V_20 ;
}
static void T_19 F_480 ( void )
{
F_481 ( & V_1058 ) ;
F_479 ( V_674 ) ;
}
