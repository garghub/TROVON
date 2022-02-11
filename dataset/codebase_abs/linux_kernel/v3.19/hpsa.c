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
static int F_4 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_12 [ 2 ] != V_13 )
return 0 ;
switch ( V_10 -> V_11 -> V_12 [ 12 ] ) {
case V_14 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_1
L_2 , V_8 -> V_18 ) ;
break;
case V_19 :
F_5 ( & V_8 -> V_15 -> V_16 ,
V_17 L_3 , V_8 -> V_18 ) ;
break;
case V_20 :
F_5 ( & V_8 -> V_15 -> V_16 ,
V_17 L_4 , V_8 -> V_18 ) ;
break;
case V_21 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_5
L_6 , V_8 -> V_18 ) ;
break;
case V_22 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_7
L_8 , V_8 -> V_18 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_9
L_10 , V_8 -> V_18 ) ;
break;
}
return 1 ;
}
static int F_6 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 != V_24 ||
( V_10 -> V_11 -> V_25 != V_26 &&
V_10 -> V_11 -> V_25 != V_27 ) )
return 0 ;
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_11 ) ;
return 1 ;
}
static T_1 F_7 ( struct V_28 * V_16 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_33 , V_34 ;
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
char V_36 [ 10 ] ;
if ( ! F_9 ( V_37 ) || ! F_9 ( V_38 ) )
return - V_39 ;
V_34 = V_32 > sizeof( V_36 ) - 1 ? sizeof( V_36 ) - 1 : V_32 ;
strncpy ( V_36 , V_31 , V_34 ) ;
V_36 [ V_34 ] = '\0' ;
if ( sscanf ( V_36 , L_12 , & V_33 ) != 1 )
return - V_40 ;
V_8 = F_3 ( V_35 ) ;
V_8 -> V_41 = ! ! V_33 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_13 ,
V_8 -> V_41 ? L_14 : L_15 ) ;
return V_32 ;
}
static T_1 F_10 ( struct V_28 * V_16 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_42 , V_34 ;
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
char V_36 [ 10 ] ;
if ( ! F_9 ( V_37 ) || ! F_9 ( V_38 ) )
return - V_39 ;
V_34 = V_32 > sizeof( V_36 ) - 1 ? sizeof( V_36 ) - 1 : V_32 ;
strncpy ( V_36 , V_31 , V_34 ) ;
V_36 [ V_34 ] = '\0' ;
if ( sscanf ( V_36 , L_12 , & V_42 ) != 1 )
return - V_40 ;
if ( V_42 < 0 )
V_42 = 0 ;
V_8 = F_3 ( V_35 ) ;
V_8 -> V_43 = V_42 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_16 ,
V_8 -> V_43 ) ;
return V_32 ;
}
static T_1 F_11 ( struct V_28 * V_16 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
F_12 ( V_8 -> V_44 ) ;
return V_32 ;
}
static T_1 F_13 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
unsigned char * V_45 ;
V_8 = F_3 ( V_35 ) ;
if ( ! V_8 -> V_46 )
return 0 ;
V_45 = & V_8 -> V_46 [ 32 ] ;
return snprintf ( V_31 , 20 , L_17 ,
V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] , V_45 [ 3 ] ) ;
}
static T_1 F_14 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_6 * V_35 = F_8 ( V_16 ) ;
struct V_1 * V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_18 ,
F_15 ( & V_8 -> V_47 ) ) ;
}
static T_1 F_16 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_19 ,
V_8 -> V_48 & V_49 ?
L_20 : L_21 ) ;
}
static T_1 F_17 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 30 , L_22 ,
( V_8 -> V_41 == 1 ) ? L_14 : L_15 ) ;
}
static int F_18 ( T_3 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_19 ( V_52 ) ; V_51 ++ )
if ( V_52 [ V_51 ] == V_50 )
return 0 ;
return 1 ;
}
static int F_20 ( T_3 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_19 ( V_53 ) ; V_51 ++ )
if ( V_53 [ V_51 ] == V_50 )
return 0 ;
return 1 ;
}
static int F_21 ( T_3 V_50 )
{
return F_18 ( V_50 ) ||
F_20 ( V_50 ) ;
}
static T_1 F_22 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_18 , F_21 ( V_8 -> V_50 ) ) ;
}
static inline int F_23 ( unsigned char V_54 [] )
{
return ( V_54 [ 3 ] & 0xC0 ) == 0x40 ;
}
static T_1 F_24 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
T_1 V_55 = 0 ;
unsigned char V_56 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
V_3 = F_25 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
if ( ! F_23 ( V_58 -> V_54 ) ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
V_55 = snprintf ( V_31 , V_63 , L_23 ) ;
return V_55 ;
}
V_56 = V_58 -> V_64 ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( V_56 > V_65 )
V_56 = V_65 ;
V_55 = snprintf ( V_31 , V_63 , L_24 , V_66 [ V_56 ] ) ;
return V_55 ;
}
static T_1 F_28 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
unsigned char V_67 [ 8 ] ;
V_3 = F_25 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
memcpy ( V_67 , V_58 -> V_54 , sizeof( V_67 ) ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 20 , L_25 ,
V_67 [ 0 ] , V_67 [ 1 ] , V_67 [ 2 ] , V_67 [ 3 ] ,
V_67 [ 4 ] , V_67 [ 5 ] , V_67 [ 6 ] , V_67 [ 7 ] ) ;
}
static T_1 F_29 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
unsigned char V_68 [ 16 ] ;
V_3 = F_25 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
memcpy ( V_68 , V_58 -> V_69 , sizeof( V_68 ) ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 16 * 2 + 2 ,
L_26
L_27 ,
V_68 [ 0 ] , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] ,
V_68 [ 4 ] , V_68 [ 5 ] , V_68 [ 6 ] , V_68 [ 7 ] ,
V_68 [ 8 ] , V_68 [ 9 ] , V_68 [ 10 ] , V_68 [ 11 ] ,
V_68 [ 12 ] , V_68 [ 13 ] , V_68 [ 14 ] , V_68 [ 15 ] ) ;
}
static T_1 F_30 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
int V_70 ;
V_3 = F_25 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
V_70 = V_58 -> V_70 ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 20 , L_18 , V_70 ) ;
}
static inline void F_31 ( struct V_71 * V_72 , struct V_9 * V_10 )
{
F_32 ( & V_10 -> V_72 , V_72 ) ;
}
static inline T_3 F_33 ( struct V_1 * V_8 , T_4 V_73 )
{
T_3 V_74 ;
struct V_75 * V_76 = & V_8 -> V_77 [ V_73 ] ;
if ( V_8 -> V_48 & V_78 )
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
if ( F_34 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
if ( ( V_76 -> V_81 [ V_76 -> V_82 ] & 1 ) == V_76 -> V_83 ) {
V_74 = V_76 -> V_81 [ V_76 -> V_82 ] ;
V_76 -> V_82 ++ ;
F_35 ( & V_8 -> V_47 ) ;
} else {
V_74 = V_84 ;
}
if ( V_76 -> V_82 == V_8 -> V_85 ) {
V_76 -> V_82 = 0 ;
V_76 -> V_83 ^= 1 ;
}
return V_74 ;
}
static void F_36 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_37 ( V_8 -> V_48 & V_49 ) ) {
V_10 -> V_86 |= 1 | ( V_8 -> V_87 [ V_10 -> V_88 . V_89 ] << 1 ) ;
if ( F_37 ( V_8 -> V_90 > 0 ) )
V_10 -> V_88 . V_91 =
F_38 () % V_8 -> V_92 ;
}
}
static void F_39 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_93 * V_94 = & V_8 -> V_95 [ V_10 -> V_96 ] ;
V_94 -> V_91 = F_40 () % V_8 -> V_92 ;
V_10 -> V_86 |= 1 | ( V_8 -> V_97 [ V_10 -> V_88 . V_89 ] << 1 ) |
V_98 ;
}
static void F_41 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_99 * V_94 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
V_94 -> V_77 = F_40 () % V_8 -> V_92 ;
V_10 -> V_86 |= ( V_8 -> V_101 [ V_94 -> V_102 ] ) ;
}
static int F_42 ( T_4 * V_103 )
{
return V_103 [ 0 ] == V_104 && V_103 [ 6 ] == V_105 ;
}
static void F_43 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_42 ( V_10 -> V_106 . V_107 ) )
return;
F_44 ( & V_8 -> V_108 ) ;
V_8 -> V_109 = V_110 ;
}
static void F_45 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_42 ( V_10 -> V_106 . V_107 ) &&
F_46 ( & V_8 -> V_108 ) )
V_8 -> V_109 = V_111 ;
}
static void F_47 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_59 ;
switch ( V_10 -> V_112 ) {
case V_113 :
F_39 ( V_8 , V_10 ) ;
break;
case V_114 :
F_41 ( V_8 , V_10 ) ;
break;
default:
F_36 ( V_8 , V_10 ) ;
}
F_43 ( V_8 , V_10 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_31 ( & V_8 -> V_115 , V_10 ) ;
V_8 -> V_116 ++ ;
F_48 ( V_8 , & V_59 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static inline void F_49 ( struct V_9 * V_10 )
{
if ( F_50 ( F_51 ( & V_10 -> V_72 ) ) )
return;
F_52 ( & V_10 -> V_72 ) ;
}
static inline int F_53 ( unsigned char V_54 [] )
{
return memcmp ( V_54 , V_117 , 8 ) == 0 ;
}
static inline int F_54 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_46 )
return 0 ;
if ( ( V_8 -> V_46 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_8 ,
unsigned char V_54 [] , int V_118 , int * V_119 , int * V_120 )
{
int V_51 , V_121 = 0 ;
F_56 ( V_122 , V_123 ) ;
F_57 ( V_122 , V_123 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] -> V_118 == V_118 && V_8 -> V_16 [ V_51 ] -> V_119 != - 1 )
F_58 ( V_8 -> V_16 [ V_51 ] -> V_119 , V_122 ) ;
}
V_51 = F_59 ( V_122 , V_123 ) ;
if ( V_51 < V_123 ) {
* V_119 = V_51 ;
* V_120 = 0 ;
V_121 = 1 ;
}
return ! V_121 ;
}
static int F_60 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_28 ,
struct V_57 * V_126 [] , int * V_127 )
{
int V_128 = V_8 -> V_124 ;
int V_51 ;
unsigned char V_129 [ 8 ] , V_130 [ 8 ] ;
struct V_57 * V_131 ;
if ( V_128 >= V_123 ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_28
L_29 ) ;
return - 1 ;
}
if ( V_28 -> V_120 != - 1 )
goto V_132;
if ( V_28 -> V_54 [ 4 ] == 0 ) {
if ( F_55 ( V_8 , V_28 -> V_54 ,
V_28 -> V_118 , & V_28 -> V_119 , & V_28 -> V_120 ) != 0 )
return - 1 ;
goto V_132;
}
memcpy ( V_129 , V_28 -> V_54 , 8 ) ;
V_129 [ 4 ] = 0 ;
for ( V_51 = 0 ; V_51 < V_128 ; V_51 ++ ) {
V_131 = V_8 -> V_16 [ V_51 ] ;
memcpy ( V_130 , V_131 -> V_54 , 8 ) ;
V_130 [ 4 ] = 0 ;
if ( memcmp ( V_129 , V_130 , 8 ) == 0 ) {
V_28 -> V_118 = V_131 -> V_118 ;
V_28 -> V_119 = V_131 -> V_119 ;
V_28 -> V_120 = V_28 -> V_54 [ 4 ] ;
break;
}
}
if ( V_28 -> V_120 == - 1 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_30
L_31
L_32 ) ;
return - 1 ;
}
V_132:
V_8 -> V_16 [ V_128 ] = V_28 ;
V_8 -> V_124 ++ ;
V_126 [ * V_127 ] = V_28 ;
( * V_127 ) ++ ;
F_62 ( & V_8 -> V_15 -> V_16 , L_33 ,
F_63 ( V_28 -> V_133 ) , V_125 ,
V_28 -> V_118 , V_28 -> V_119 , V_28 -> V_120 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 )
{
F_65 ( V_134 < 0 || V_134 >= V_123 ) ;
V_8 -> V_16 [ V_134 ] -> V_64 = V_135 -> V_64 ;
V_8 -> V_16 [ V_134 ] -> V_136 = V_135 -> V_136 ;
V_8 -> V_16 [ V_134 ] -> V_70 = V_135 -> V_70 ;
V_8 -> V_16 [ V_134 ] -> V_137 = V_135 -> V_137 ;
V_8 -> V_16 [ V_134 ] -> V_138 = V_135 -> V_138 ;
V_8 -> V_16 [ V_134 ] -> V_139 = V_135 -> V_139 ;
F_62 ( & V_8 -> V_15 -> V_16 , L_34 ,
F_63 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_66 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 ,
struct V_57 * V_126 [] , int * V_127 ,
struct V_57 * V_140 [] , int * V_141 )
{
F_65 ( V_134 < 0 || V_134 >= V_123 ) ;
V_140 [ * V_141 ] = V_8 -> V_16 [ V_134 ] ;
( * V_141 ) ++ ;
if ( V_135 -> V_119 == - 1 ) {
V_135 -> V_119 = V_8 -> V_16 [ V_134 ] -> V_119 ;
V_135 -> V_120 = V_8 -> V_16 [ V_134 ] -> V_120 ;
}
V_8 -> V_16 [ V_134 ] = V_135 ;
V_126 [ * V_127 ] = V_135 ;
( * V_127 ) ++ ;
F_62 ( & V_8 -> V_15 -> V_16 , L_35 ,
F_63 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_67 ( struct V_1 * V_8 , int V_125 , int V_134 ,
struct V_57 * V_140 [] , int * V_141 )
{
int V_51 ;
struct V_57 * V_131 ;
F_65 ( V_134 < 0 || V_134 >= V_123 ) ;
V_131 = V_8 -> V_16 [ V_134 ] ;
V_140 [ * V_141 ] = V_8 -> V_16 [ V_134 ] ;
( * V_141 ) ++ ;
for ( V_51 = V_134 ; V_51 < V_8 -> V_124 - 1 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] = V_8 -> V_16 [ V_51 + 1 ] ;
V_8 -> V_124 -- ;
F_62 ( & V_8 -> V_15 -> V_16 , L_36 ,
F_63 ( V_131 -> V_133 ) , V_125 , V_131 -> V_118 , V_131 -> V_119 ,
V_131 -> V_120 ) ;
}
static void F_68 ( struct V_1 * V_8 ,
struct V_57 * V_126 )
{
unsigned long V_59 ;
int V_51 , V_142 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] == V_126 ) {
for ( V_142 = V_51 ; V_142 < V_8 -> V_124 - 1 ; V_142 ++ )
V_8 -> V_16 [ V_142 ] = V_8 -> V_16 [ V_142 + 1 ] ;
V_8 -> V_124 -- ;
break;
}
}
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_69 ( V_126 ) ;
}
static inline int F_70 ( struct V_57 * V_143 ,
struct V_57 * V_144 )
{
if ( memcmp ( V_143 -> V_54 , V_144 -> V_54 ,
sizeof( V_143 -> V_54 ) ) != 0 )
return 0 ;
if ( memcmp ( V_143 -> V_69 , V_144 -> V_69 ,
sizeof( V_143 -> V_69 ) ) != 0 )
return 0 ;
if ( memcmp ( V_143 -> V_145 , V_144 -> V_145 , sizeof( V_143 -> V_145 ) ) != 0 )
return 0 ;
if ( memcmp ( V_143 -> V_146 , V_144 -> V_146 , sizeof( V_143 -> V_146 ) ) != 0 )
return 0 ;
if ( V_143 -> V_133 != V_144 -> V_133 )
return 0 ;
if ( V_143 -> V_118 != V_144 -> V_118 )
return 0 ;
return 1 ;
}
static inline int F_71 ( struct V_57 * V_143 ,
struct V_57 * V_144 )
{
if ( V_143 -> V_64 != V_144 -> V_64 )
return 1 ;
if ( V_143 -> V_136 != V_144 -> V_136 )
return 1 ;
if ( V_143 -> V_70 != V_144 -> V_70 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_57 * V_147 ,
struct V_57 * V_148 [] , int V_149 ,
int * V_150 )
{
int V_51 ;
#define F_73 0
#define F_74 1
#define F_75 2
#define F_76 3
for ( V_51 = 0 ; V_51 < V_149 ; V_51 ++ ) {
if ( V_148 [ V_51 ] == NULL )
continue;
if ( F_77 ( V_147 -> V_54 , V_148 [ V_51 ] -> V_54 ) ) {
* V_150 = V_51 ;
if ( F_70 ( V_147 , V_148 [ V_51 ] ) ) {
if ( F_71 ( V_147 , V_148 [ V_51 ] ) )
return F_76 ;
return F_75 ;
} else {
if ( V_147 -> V_151 )
return F_73 ;
return F_74 ;
}
}
}
* V_150 = - 1 ;
return F_73 ;
}
static void F_78 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_152 * V_28 ;
unsigned long V_59 ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
F_79 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_28 -> V_54 , V_54 ,
sizeof( V_28 -> V_54 ) ) == 0 ) {
F_27 ( & V_8 -> V_153 , V_59 ) ;
return;
}
}
F_27 ( & V_8 -> V_153 , V_59 ) ;
V_28 = F_80 ( sizeof( * V_28 ) , V_154 ) ;
if ( ! V_28 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_37 , V_155 ) ;
return;
}
memcpy ( V_28 -> V_54 , V_54 , sizeof( V_28 -> V_54 ) ) ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
F_32 ( & V_28 -> V_156 , & V_8 -> V_157 ) ;
F_27 ( & V_8 -> V_153 , V_59 ) ;
}
static void F_81 ( struct V_1 * V_8 ,
struct V_57 * V_131 )
{
if ( V_131 -> V_151 == V_158 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_38 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
switch ( V_131 -> V_151 ) {
case V_160 :
break;
case V_161 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_39 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_162 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_40 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_163 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_41 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_164 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_42 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_165 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_43 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_166 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_44 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_167 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_45 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_168 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_46 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_169 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_47 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_170 :
F_62 ( & V_8 -> V_15 -> V_16 ,
L_48 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
}
}
static void F_82 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_131 [] , int V_171 )
{
int V_51 , V_134 , V_172 , V_173 = 0 ;
struct V_57 * V_174 ;
unsigned long V_59 ;
struct V_57 * * V_126 , * * V_140 ;
int V_127 , V_141 ;
struct V_6 * V_7 = NULL ;
V_126 = F_83 ( sizeof( * V_126 ) * V_123 , V_154 ) ;
V_140 = F_83 ( sizeof( * V_140 ) * V_123 , V_154 ) ;
if ( ! V_126 || ! V_140 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_49
L_50 ) ;
goto V_175;
}
F_26 ( & V_8 -> V_176 , V_59 ) ;
V_51 = 0 ;
V_141 = 0 ;
V_127 = 0 ;
while ( V_51 < V_8 -> V_124 ) {
V_174 = V_8 -> V_16 [ V_51 ] ;
V_172 = F_72 ( V_174 , V_131 , V_171 , & V_134 ) ;
if ( V_172 == F_73 ) {
V_173 ++ ;
F_67 ( V_8 , V_125 , V_51 ,
V_140 , & V_141 ) ;
continue;
} else if ( V_172 == F_74 ) {
V_173 ++ ;
F_66 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ,
V_126 , & V_127 , V_140 , & V_141 ) ;
V_131 [ V_134 ] = NULL ;
} else if ( V_172 == F_76 ) {
F_64 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ) ;
}
V_51 ++ ;
}
for ( V_51 = 0 ; V_51 < V_171 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_151 ) {
F_81 ( V_8 , V_131 [ V_51 ] ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_51 ,
V_8 -> V_44 -> V_159 ,
V_131 [ V_51 ] -> V_118 , V_131 [ V_51 ] -> V_119 , V_131 [ V_51 ] -> V_120 ) ;
continue;
}
V_172 = F_72 ( V_131 [ V_51 ] , V_8 -> V_16 ,
V_8 -> V_124 , & V_134 ) ;
if ( V_172 == F_73 ) {
V_173 ++ ;
if ( F_60 ( V_8 , V_125 , V_131 [ V_51 ] ,
V_126 , & V_127 ) != 0 )
break;
V_131 [ V_51 ] = NULL ;
} else if ( V_172 == F_74 ) {
V_173 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_52 ) ;
}
}
F_27 ( & V_8 -> V_176 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_171 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_151 )
F_78 ( V_8 , V_131 [ V_51 ] -> V_54 ) ;
}
if ( V_125 == - 1 || ! V_173 )
goto V_175;
V_7 = V_8 -> V_44 ;
for ( V_51 = 0 ; V_51 < V_141 ; V_51 ++ ) {
struct V_2 * V_3 =
F_84 ( V_7 , V_140 [ V_51 ] -> V_118 ,
V_140 [ V_51 ] -> V_119 , V_140 [ V_51 ] -> V_120 ) ;
if ( V_3 != NULL ) {
F_85 ( V_3 ) ;
F_86 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_53
L_54 , V_125 , V_140 [ V_51 ] -> V_118 ,
V_140 [ V_51 ] -> V_119 , V_140 [ V_51 ] -> V_120 ) ;
}
F_69 ( V_140 [ V_51 ] ) ;
V_140 [ V_51 ] = NULL ;
}
for ( V_51 = 0 ; V_51 < V_127 ; V_51 ++ ) {
if ( F_87 ( V_7 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_55
L_56 , V_125 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) ;
F_68 ( V_8 , V_126 [ V_51 ] ) ;
}
V_175:
F_69 ( V_126 ) ;
F_69 ( V_140 ) ;
}
static struct V_57 * F_88 ( struct V_1 * V_8 ,
int V_118 , int V_119 , int V_120 )
{
int V_51 ;
struct V_57 * V_131 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
V_131 = V_8 -> V_16 [ V_51 ] ;
if ( V_131 -> V_118 == V_118 && V_131 -> V_119 == V_119 && V_131 -> V_120 == V_120 )
return V_131 ;
}
return NULL ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_57 * V_131 ;
unsigned long V_59 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 ) ;
F_26 ( & V_8 -> V_176 , V_59 ) ;
V_131 = F_88 ( V_8 , F_90 ( V_3 ) ,
F_91 ( V_3 ) , V_3 -> V_120 ) ;
if ( V_131 != NULL )
V_3 -> V_61 = V_131 ;
F_27 ( & V_8 -> V_176 , V_59 ) ;
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
}
static void F_93 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_177 )
return;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
F_69 ( V_8 -> V_177 [ V_51 ] ) ;
V_8 -> V_177 [ V_51 ] = NULL ;
}
F_69 ( V_8 -> V_177 ) ;
V_8 -> V_177 = NULL ;
}
static int F_94 ( struct V_1 * V_8 )
{
int V_51 ;
if ( V_8 -> V_179 <= 0 )
return 0 ;
V_8 -> V_177 = F_83 ( sizeof( * V_8 -> V_177 ) * V_8 -> V_178 ,
V_154 ) ;
if ( ! V_8 -> V_177 )
return - V_180 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
V_8 -> V_177 [ V_51 ] = F_80 ( sizeof( * V_8 -> V_177 [ V_51 ] ) *
V_8 -> V_179 , V_154 ) ;
if ( ! V_8 -> V_177 [ V_51 ] )
goto V_181;
}
return 0 ;
V_181:
F_93 ( V_8 ) ;
return - V_180 ;
}
static int F_95 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_182 * V_183 , * V_184 ;
T_5 V_185 ;
T_3 V_186 ;
V_183 = & V_10 -> V_187 [ V_8 -> V_188 - 1 ] ;
V_184 = V_8 -> V_177 [ V_10 -> V_96 ] ;
V_183 -> V_189 = F_96 ( V_190 ) ;
V_186 = sizeof( * V_183 ) *
( V_10 -> V_88 . V_191 - V_8 -> V_188 ) ;
V_183 -> V_192 = F_96 ( V_186 ) ;
V_185 = F_97 ( V_8 -> V_15 , V_184 , V_186 ,
V_193 ) ;
if ( F_98 ( & V_8 -> V_15 -> V_16 , V_185 ) ) {
V_183 -> V_194 = F_99 ( 0 ) ;
return - 1 ;
}
V_183 -> V_194 = F_99 ( V_185 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_182 * V_183 ;
if ( F_101 ( V_10 -> V_88 . V_191 ) <= V_8 -> V_188 )
return;
V_183 = & V_10 -> V_187 [ V_8 -> V_188 - 1 ] ;
F_102 ( V_8 -> V_15 , F_103 ( V_183 -> V_194 ) ,
F_104 ( V_183 -> V_192 ) , V_193 ) ;
}
static int F_105 ( struct V_1 * V_8 ,
struct V_9 * V_10 ,
struct V_195 * V_196 ,
struct V_99 * V_197 )
{
int V_198 ;
int V_199 = 0 ;
switch ( V_197 -> V_200 . V_201 ) {
case V_202 :
switch ( V_197 -> V_200 . V_33 ) {
case V_203 :
break;
case V_204 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_57 ,
L_58 ) ;
V_196 -> V_205 |= V_206 ;
if ( V_197 -> V_200 . V_207 !=
V_208 ) {
memset ( V_196 -> V_209 , 0 ,
V_210 ) ;
break;
}
V_198 = V_197 -> V_200 . V_211 ;
if ( V_198 > V_210 )
V_198 = V_210 ;
if ( V_198 > sizeof( V_197 -> V_200 . V_212 ) )
V_198 =
sizeof( V_197 -> V_200 . V_212 ) ;
memcpy ( V_196 -> V_209 ,
V_197 -> V_200 . V_212 , V_198 ) ;
V_199 = 1 ;
break;
case V_213 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_59 ,
L_58 ) ;
V_199 = 1 ;
break;
case V_214 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_60 ,
L_58 ) ;
V_199 = 1 ;
break;
case V_215 :
V_196 -> V_205 = V_216 << 16 ;
break;
case V_217 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_61 ,
L_58 ) ;
V_199 = 1 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_62 ,
L_58 , V_197 -> V_200 . V_33 ) ;
V_199 = 1 ;
break;
}
break;
case V_218 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_63 ,
V_197 -> V_200 . V_33 ) ;
V_199 = 1 ;
break;
case V_219 :
break;
case V_220 :
break;
case V_221 :
F_5 ( & V_8 -> V_15 -> V_16 , L_64 ) ;
V_199 = 1 ;
break;
case V_222 :
F_5 ( & V_8 -> V_15 -> V_16 , L_65 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_66 ,
L_58 ,
V_197 -> V_200 . V_201 ) ;
V_199 = 1 ;
break;
}
return V_199 ;
}
static void F_106 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_195 * V_196 ,
struct V_57 * V_16 )
{
struct V_99 * V_197 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
int V_223 = 0 ;
if ( F_37 ( V_197 -> V_200 . V_201 == 0 &&
V_197 -> V_200 . V_33 == 0 ) ) {
F_107 ( V_8 , V_10 ) ;
V_196 -> V_224 ( V_196 ) ;
return;
}
if ( F_23 ( V_16 -> V_54 ) &&
V_197 -> V_200 . V_201 ==
V_218 ) {
V_16 -> V_70 = 0 ;
V_8 -> V_225 = 1 ;
V_196 -> V_205 = V_226 << 16 ;
F_107 ( V_8 , V_10 ) ;
V_196 -> V_224 ( V_196 ) ;
return;
}
V_223 = F_105 ( V_8 , V_10 , V_196 , V_197 ) ;
if ( V_223 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_67 ,
L_58 ) ;
V_16 -> V_70 = 0 ;
V_8 -> V_225 = 1 ;
V_196 -> V_205 = V_226 << 16 ;
}
F_107 ( V_8 , V_10 ) ;
V_196 -> V_224 ( V_196 ) ;
}
static void F_108 ( struct V_9 * V_94 )
{
struct V_195 * V_196 ;
struct V_1 * V_8 ;
struct V_227 * V_228 ;
struct V_57 * V_16 ;
unsigned char V_229 ;
unsigned char V_230 ;
unsigned char V_231 ;
unsigned long V_232 ;
V_228 = V_94 -> V_11 ;
V_196 = (struct V_195 * ) V_94 -> V_233 ;
V_8 = V_94 -> V_8 ;
V_16 = V_196 -> V_28 -> V_61 ;
F_109 ( V_196 ) ;
if ( ( V_94 -> V_112 == V_234 ) &&
( V_94 -> V_88 . V_191 > V_8 -> V_188 ) )
F_100 ( V_8 , V_94 ) ;
V_196 -> V_205 = ( V_235 << 16 ) ;
V_196 -> V_205 |= ( V_236 << 8 ) ;
if ( V_94 -> V_112 == V_114 )
return F_106 ( V_8 , V_94 , V_196 , V_16 ) ;
V_196 -> V_205 |= V_228 -> V_25 ;
F_110 ( V_196 , V_228 -> V_237 ) ;
if ( V_228 -> V_23 == 0 ) {
F_107 ( V_8 , V_94 ) ;
V_196 -> V_224 ( V_196 ) ;
return;
}
if ( V_210 < sizeof( V_228 -> V_12 ) )
V_232 = V_210 ;
else
V_232 = sizeof( V_228 -> V_12 ) ;
if ( V_228 -> V_238 < V_232 )
V_232 = V_228 -> V_238 ;
memcpy ( V_196 -> V_209 , V_228 -> V_12 , V_232 ) ;
if ( V_94 -> V_112 == V_113 ) {
struct V_93 * V_10 = & V_8 -> V_95 [ V_94 -> V_96 ] ;
V_94 -> V_88 . V_89 = V_94 -> V_88 . V_191 = F_111 ( V_196 ) ;
V_94 -> V_106 . V_239 = V_10 -> V_240 & V_241 ;
V_94 -> V_88 . V_242 = V_10 -> V_242 ;
memcpy ( V_94 -> V_88 . V_243 . V_244 , V_10 -> V_245 , 8 ) ;
memcpy ( V_94 -> V_106 . V_107 , V_10 -> V_107 , V_94 -> V_106 . V_239 ) ;
if ( F_23 ( V_16 -> V_54 ) ) {
if ( V_228 -> V_23 == V_246 )
V_16 -> V_70 = 0 ;
V_196 -> V_205 = V_226 << 16 ;
F_107 ( V_8 , V_94 ) ;
V_196 -> V_224 ( V_196 ) ;
return;
}
}
switch ( V_228 -> V_23 ) {
case V_24 :
if ( V_228 -> V_25 ) {
V_229 = 0xf & V_228 -> V_12 [ 2 ] ;
V_230 = V_228 -> V_12 [ 12 ] ;
V_231 = V_228 -> V_12 [ 13 ] ;
}
if ( V_228 -> V_25 == V_206 ) {
if ( V_229 == V_247 ) {
V_196 -> V_205 |= V_226 << 16 ;
break;
}
break;
}
if ( V_228 -> V_25 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_68
L_69
L_70 ,
V_94 , V_228 -> V_25 ,
V_229 , V_230 , V_231 ,
V_196 -> V_205 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_71
L_72 , V_94 ) ,
V_196 -> V_205 = V_248 << 16 ;
}
break;
case V_249 :
break;
case V_250 :
F_5 ( & V_8 -> V_15 -> V_16 , L_73
L_74
L_75 , V_94 ) ;
break;
case V_251 : {
V_196 -> V_205 = V_248 << 16 ;
}
break;
case V_252 :
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_76
L_77 , V_94 ) ;
break;
case V_254 :
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_78 , V_94 ) ;
break;
case V_255 :
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_79 , V_94 ) ;
break;
case V_256 :
V_196 -> V_205 = V_257 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_80 ,
V_94 , V_228 -> V_25 ) ;
break;
case V_258 :
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_81 , V_94 ) ;
break;
case V_259 :
V_196 -> V_205 = V_226 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_82
L_83 , V_94 ) ;
break;
case V_260 :
V_196 -> V_205 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_84 , V_94 ) ;
break;
case V_262 :
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_85 ) ;
break;
case V_246 :
V_196 -> V_205 = V_226 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_86 , V_94 ) ;
break;
default:
V_196 -> V_205 = V_253 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_87 ,
V_94 , V_228 -> V_23 ) ;
}
F_107 ( V_8 , V_94 ) ;
V_196 -> V_224 ( V_196 ) ;
}
static void F_112 ( struct V_263 * V_15 ,
struct V_9 * V_10 , int V_264 , int V_265 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_264 ; V_51 ++ )
F_102 ( V_15 , ( V_266 ) F_103 ( V_10 -> V_187 [ V_51 ] . V_194 ) ,
F_104 ( V_10 -> V_187 [ V_51 ] . V_192 ) ,
V_265 ) ;
}
static int F_113 ( struct V_263 * V_15 ,
struct V_9 * V_94 ,
unsigned char * V_31 ,
T_2 V_267 ,
int V_265 )
{
T_5 V_268 ;
if ( V_267 == 0 || V_265 == V_269 ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = F_114 ( 0 ) ;
return 0 ;
}
V_268 = F_97 ( V_15 , V_31 , V_267 , V_265 ) ;
if ( F_98 ( & V_15 -> V_16 , V_268 ) ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = F_114 ( 0 ) ;
return - 1 ;
}
V_94 -> V_187 [ 0 ] . V_194 = F_99 ( V_268 ) ;
V_94 -> V_187 [ 0 ] . V_192 = F_96 ( V_267 ) ;
V_94 -> V_187 [ 0 ] . V_189 = F_96 ( V_270 ) ;
V_94 -> V_88 . V_89 = 1 ;
V_94 -> V_88 . V_191 = F_114 ( 1 ) ;
return 0 ;
}
static inline void F_115 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_116 ( V_271 ) ;
V_10 -> V_272 = & V_271 ;
F_47 ( V_8 , V_10 ) ;
F_117 ( & V_271 ) ;
}
static T_3 F_118 ( struct V_1 * V_8 )
{
int V_273 ;
T_3 V_274 , * F_118 ;
V_273 = F_119 () ;
F_118 = F_120 ( V_8 -> F_118 , V_273 ) ;
V_274 = * F_118 ;
F_121 () ;
return V_274 ;
}
static void F_122 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_34 ( F_118 ( V_8 ) ) )
V_10 -> V_11 -> V_23 = V_254 ;
else
F_115 ( V_8 , V_10 ) ;
}
static void F_123 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_265 )
{
int V_275 = 10 , V_276 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_115 ( V_8 , V_10 ) ;
V_276 ++ ;
if ( V_276 > 3 ) {
F_124 ( V_275 ) ;
if ( V_275 < 1000 )
V_275 *= 2 ;
}
} while ( ( F_4 ( V_8 , V_10 ) ||
F_6 ( V_8 , V_10 ) ) &&
V_276 <= V_277 );
F_112 ( V_8 -> V_15 , V_10 , 1 , V_265 ) ;
}
static void F_125 ( struct V_1 * V_8 , char * V_278 ,
struct V_9 * V_10 )
{
const T_4 * V_103 = V_10 -> V_106 . V_107 ;
const T_4 * V_120 = V_10 -> V_88 . V_243 . V_244 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_88
L_89 ,
V_278 , V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ,
V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_103 [ 8 ] , V_103 [ 9 ] , V_103 [ 10 ] , V_103 [ 11 ] ,
V_103 [ 12 ] , V_103 [ 13 ] , V_103 [ 14 ] , V_103 [ 15 ] ) ;
}
static void F_126 ( struct V_1 * V_8 ,
struct V_9 * V_94 )
{
const struct V_227 * V_228 = V_94 -> V_11 ;
struct V_28 * V_279 = & V_94 -> V_8 -> V_15 -> V_16 ;
const T_4 * V_131 = V_228 -> V_12 ;
switch ( V_228 -> V_23 ) {
case V_24 :
F_125 ( V_8 , L_90 , V_94 ) ;
if ( V_228 -> V_25 == V_206 )
F_5 ( V_279 , L_91 ,
V_131 [ 2 ] & 0x0f , V_131 [ 12 ] , V_131 [ 13 ] ) ;
else
F_5 ( V_279 , L_92 , V_228 -> V_25 ) ;
if ( V_228 -> V_25 == 0 )
F_5 ( V_279 , L_93
L_94
L_95
L_96 ) ;
break;
case V_249 :
break;
case V_250 :
F_125 ( V_8 , L_97 , V_94 ) ;
break;
case V_251 : {
F_125 ( V_8 , L_98 , V_94 ) ;
F_5 ( V_279 , L_99 ) ;
}
break;
case V_252 :
F_125 ( V_8 , L_100 , V_94 ) ;
break;
case V_254 :
F_125 ( V_8 , L_101 , V_94 ) ;
break;
case V_255 :
F_125 ( V_8 , L_102 , V_94 ) ;
break;
case V_256 :
F_125 ( V_8 , L_103 , V_94 ) ;
break;
case V_258 :
F_125 ( V_8 , L_104 , V_94 ) ;
break;
case V_259 :
F_125 ( V_8 , L_105 , V_94 ) ;
break;
case V_260 :
F_125 ( V_8 , L_106 , V_94 ) ;
break;
case V_262 :
F_125 ( V_8 , L_107 , V_94 ) ;
break;
default:
F_125 ( V_8 , L_108 , V_94 ) ;
F_5 ( V_279 , L_109 ,
V_228 -> V_23 ) ;
}
}
static int F_127 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_6 V_280 , unsigned char * V_31 ,
unsigned char V_281 )
{
int V_274 = V_282 ;
struct V_9 * V_10 ;
struct V_227 * V_228 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - V_180 ;
}
if ( F_129 ( V_10 , V_283 , V_8 , V_31 , V_281 ,
V_280 , V_54 , V_284 ) ) {
V_274 = - 1 ;
goto V_285;
}
F_123 ( V_8 , V_10 , V_286 ) ;
V_228 = V_10 -> V_11 ;
if ( V_228 -> V_23 != 0 && V_228 -> V_23 != V_249 ) {
F_126 ( V_8 , V_10 ) ;
V_274 = - 1 ;
}
V_285:
F_130 ( V_8 , V_10 ) ;
return V_274 ;
}
static int F_131 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char V_280 ,
struct V_287 * V_31 , T_2 V_281 )
{
int V_274 = V_282 ;
struct V_9 * V_10 ;
struct V_227 * V_228 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - V_180 ;
}
if ( F_129 ( V_10 , V_288 , V_8 , V_31 , V_281 ,
V_280 , V_54 , V_284 ) ) {
V_274 = - 1 ;
goto V_285;
}
F_123 ( V_8 , V_10 , V_286 ) ;
V_228 = V_10 -> V_11 ;
if ( V_228 -> V_23 != 0 && V_228 -> V_23 != V_249 ) {
F_126 ( V_8 , V_10 ) ;
V_274 = - 1 ;
}
V_285:
F_130 ( V_8 , V_10 ) ;
return V_274 ;
}
static int F_132 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_289 )
{
int V_274 = V_282 ;
struct V_9 * V_10 ;
struct V_227 * V_228 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - V_180 ;
}
( void ) F_129 ( V_10 , V_290 , V_8 , NULL , 0 , 0 ,
V_54 , V_291 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_289 ;
F_115 ( V_8 , V_10 ) ;
V_228 = V_10 -> V_11 ;
if ( V_228 -> V_23 != 0 ) {
F_126 ( V_8 , V_10 ) ;
V_274 = - 1 ;
}
F_130 ( V_8 , V_10 ) ;
return V_274 ;
}
static void F_133 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char * V_64 )
{
int V_274 ;
unsigned char * V_31 ;
* V_64 = V_65 ;
V_31 = F_83 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
V_274 = F_127 ( V_8 , V_54 , V_292 | 0xC1 , V_31 , 64 ) ;
if ( V_274 == 0 )
* V_64 = V_31 [ 8 ] ;
if ( * V_64 > V_65 )
* V_64 = V_65 ;
F_69 ( V_31 ) ;
return;
}
static void F_134 ( struct V_1 * V_8 , int V_274 ,
struct V_293 * V_294 )
{
struct V_295 * V_296 = & V_294 -> V_297 [ 0 ] ;
int V_298 , V_299 , V_300 ;
T_6 V_301 , V_302 , V_303 ;
if ( V_274 != 0 )
return;
if ( V_8 -> V_43 < 2 )
return;
F_62 ( & V_8 -> V_15 -> V_16 , L_111 ,
F_104 ( V_294 -> V_304 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_112 ,
F_104 ( V_294 -> V_305 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_113 ,
F_103 ( V_294 -> V_306 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_114 ,
V_294 -> V_307 ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_115 ,
V_294 -> V_308 ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_116 ,
F_101 ( V_294 -> V_309 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_117 ,
F_103 ( V_294 -> V_310 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_118 ,
F_103 ( V_294 -> V_311 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_119 ,
F_101 ( V_294 -> V_312 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_120 ,
F_101 ( V_294 -> V_313 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_121 ,
F_101 ( V_294 -> V_302 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_122 ,
F_101 ( V_294 -> V_314 ) ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_123 ,
F_101 ( V_294 -> V_59 ) ) ;
if ( V_294 -> V_59 & V_315 )
F_62 ( & V_8 -> V_15 -> V_16 , L_124 ) ;
else
F_62 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_126 ,
F_101 ( V_294 -> V_316 ) ) ;
V_301 = F_101 ( V_294 -> V_314 ) ;
for ( V_298 = 0 ; V_298 < V_301 ; V_298 ++ ) {
F_62 ( & V_8 -> V_15 -> V_16 , L_127 , V_298 ) ;
V_302 = F_101 ( V_294 -> V_302 ) ;
for ( V_299 = 0 ; V_299 < V_302 ; V_299 ++ ) {
F_62 ( & V_8 -> V_15 -> V_16 , L_128 , V_299 ) ;
V_303 =
F_101 ( V_294 -> V_312 ) ;
for ( V_300 = 0 ; V_300 < V_303 ; V_300 ++ , V_296 ++ )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_129 ,
V_300 , V_296 -> V_137 ,
V_296 -> V_317 [ 0 ] , V_296 -> V_317 [ 1 ] ) ;
V_303 =
F_101 ( V_294 -> V_313 ) ;
for ( V_300 = 0 ; V_300 < V_303 ; V_300 ++ , V_296 ++ )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_130 ,
V_300 , V_296 -> V_137 ,
V_296 -> V_317 [ 0 ] , V_296 -> V_317 [ 1 ] ) ;
}
}
}
static int F_135 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_318 )
{
int V_274 = 0 ;
struct V_9 * V_10 ;
struct V_227 * V_228 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - V_180 ;
}
if ( F_129 ( V_10 , V_319 , V_8 , & V_318 -> V_139 ,
sizeof( V_318 -> V_139 ) , 0 ,
V_54 , V_284 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_131 ) ;
F_130 ( V_8 , V_10 ) ;
return - V_180 ;
}
F_123 ( V_8 , V_10 , V_286 ) ;
V_228 = V_10 -> V_11 ;
if ( V_228 -> V_23 != 0 && V_228 -> V_23 != V_249 ) {
F_126 ( V_8 , V_10 ) ;
F_130 ( V_8 , V_10 ) ;
return - 1 ;
}
F_130 ( V_8 , V_10 ) ;
if ( F_104 ( V_318 -> V_139 . V_304 ) >
sizeof( V_318 -> V_139 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_132 ) ;
V_274 = - 1 ;
}
F_134 ( V_8 , V_274 , & V_318 -> V_139 ) ;
return V_274 ;
}
static int F_136 ( struct V_1 * V_8 ,
unsigned char V_54 [] , T_4 V_280 )
{
int V_274 ;
int V_51 ;
int V_320 ;
unsigned char * V_31 , V_281 ;
V_31 = F_83 ( 256 , V_154 ) ;
if ( ! V_31 )
return 0 ;
V_274 = F_127 ( V_8 , V_54 ,
V_292 | V_321 ,
V_31 , V_322 ) ;
if ( V_274 != 0 )
goto V_323;
V_320 = V_31 [ 3 ] ;
if ( ( V_320 + V_322 ) <= 255 )
V_281 = V_320 + V_322 ;
else
V_281 = 255 ;
V_274 = F_127 ( V_8 , V_54 ,
V_292 | V_321 ,
V_31 , V_281 ) ;
if ( V_274 != 0 )
goto V_323;
V_320 = V_31 [ 3 ] ;
for ( V_51 = 1 ; V_51 <= V_320 ; V_51 ++ )
if ( V_31 [ 3 + V_51 ] == V_280 )
goto V_324;
V_323:
F_69 ( V_31 ) ;
return 0 ;
V_324:
F_69 ( V_31 ) ;
return 1 ;
}
static void F_137 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_318 )
{
int V_274 ;
unsigned char * V_31 ;
T_4 V_325 ;
V_318 -> V_136 = 0 ;
V_318 -> V_70 = 0 ;
V_31 = F_83 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
if ( ! F_136 ( V_8 , V_54 , V_326 ) )
goto V_285;
V_274 = F_127 ( V_8 , V_54 ,
V_292 | V_326 , V_31 , 64 ) ;
if ( V_274 != 0 )
goto V_285;
#define F_138 4
#define F_139 0x01
#define F_140 0x02
V_325 = V_31 [ F_138 ] ;
V_318 -> V_136 =
! ! ( V_325 & F_139 ) ;
if ( V_318 -> V_136 ) {
V_318 -> V_70 =
! ! ( V_325 & F_140 ) ;
if ( F_135 ( V_8 , V_54 , V_318 ) )
V_318 -> V_70 = 0 ;
}
V_285:
F_69 ( V_31 ) ;
return;
}
static int F_141 ( struct V_1 * V_8 , unsigned char * V_54 ,
unsigned char * V_69 , int V_267 )
{
int V_274 ;
unsigned char * V_31 ;
if ( V_267 > 16 )
V_267 = 16 ;
V_31 = F_83 ( 64 , V_154 ) ;
if ( ! V_31 )
return - V_180 ;
V_274 = F_127 ( V_8 , V_54 , V_292 | 0x83 , V_31 , 64 ) ;
if ( V_274 == 0 )
memcpy ( V_69 , & V_31 [ 8 ] , V_267 ) ;
F_69 ( V_31 ) ;
return V_274 != 0 ;
}
static int F_142 ( struct V_1 * V_8 , int V_327 ,
struct V_328 * V_31 , int V_281 ,
int V_329 )
{
int V_274 = V_282 ;
struct V_9 * V_10 ;
unsigned char V_54 [ 8 ] ;
struct V_227 * V_228 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - 1 ;
}
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
if ( F_129 ( V_10 , V_327 ? V_330 : V_331 , V_8 ,
V_31 , V_281 , 0 , V_54 , V_284 ) ) {
V_274 = - 1 ;
goto V_285;
}
if ( V_329 )
V_10 -> V_106 . V_107 [ 1 ] = V_329 ;
F_123 ( V_8 , V_10 , V_286 ) ;
V_228 = V_10 -> V_11 ;
if ( V_228 -> V_23 != 0 &&
V_228 -> V_23 != V_249 ) {
F_126 ( V_8 , V_10 ) ;
V_274 = - 1 ;
} else {
if ( V_31 -> V_332 != V_329 ) {
F_61 ( & V_8 -> V_15 -> V_16 ,
L_133 ,
V_329 ,
V_31 -> V_332 ) ;
V_274 = - 1 ;
}
}
V_285:
F_130 ( V_8 , V_10 ) ;
return V_274 ;
}
static inline int F_143 ( struct V_1 * V_8 ,
struct V_328 * V_31 ,
int V_281 , int V_329 )
{
return F_142 ( V_8 , 0 , V_31 , V_281 , V_329 ) ;
}
static inline int F_144 ( struct V_1 * V_8 ,
struct V_328 * V_31 , int V_281 )
{
return F_142 ( V_8 , 1 , V_31 , V_281 , 0 ) ;
}
static inline void F_145 ( struct V_57 * V_28 ,
int V_118 , int V_119 , int V_120 )
{
V_28 -> V_118 = V_118 ;
V_28 -> V_119 = V_119 ;
V_28 -> V_120 = V_120 ;
}
static int F_146 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
int V_274 ;
int V_33 ;
int V_333 ;
unsigned char * V_31 ;
V_31 = F_83 ( 64 , V_154 ) ;
if ( ! V_31 )
return V_158 ;
if ( ! F_136 ( V_8 , V_54 , V_334 ) )
goto V_335;
V_274 = F_127 ( V_8 , V_54 , V_292 | V_334 ,
V_31 , V_322 ) ;
if ( V_274 != 0 )
goto V_335;
V_333 = V_31 [ 3 ] ;
V_274 = F_127 ( V_8 , V_54 , V_292 | V_334 ,
V_31 , V_333 + V_322 ) ;
if ( V_274 != 0 )
goto V_335;
V_33 = V_31 [ 4 ] ;
F_69 ( V_31 ) ;
return V_33 ;
V_335:
F_69 ( V_31 ) ;
return V_158 ;
}
static int F_147 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_9 * V_10 ;
unsigned char * V_336 , V_229 , V_230 , V_231 ;
int V_337 = 0 ;
T_6 V_338 ;
T_4 V_339 ;
#define F_148 0x04
#define F_149 0x04
#define F_150 0x02
V_10 = F_151 ( V_8 ) ;
if ( ! V_10 )
return 0 ;
( void ) F_129 ( V_10 , V_340 , V_8 , NULL , 0 , 0 , V_54 , V_284 ) ;
F_115 ( V_8 , V_10 ) ;
V_336 = V_10 -> V_11 -> V_12 ;
V_229 = V_336 [ 2 ] ;
V_230 = V_336 [ 12 ] ;
V_231 = V_336 [ 13 ] ;
V_338 = V_10 -> V_11 -> V_23 ;
V_339 = V_10 -> V_11 -> V_25 ;
F_107 ( V_8 , V_10 ) ;
if ( V_338 != V_24 ||
V_339 != V_206 ||
V_229 != V_341 ||
V_230 != F_148 ) {
return 0 ;
}
V_337 = F_146 ( V_8 , V_54 ) ;
switch ( V_337 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
return V_337 ;
case V_158 :
if ( ( V_231 == F_149 ) ||
( V_231 == F_150 ) )
return V_337 ;
break;
default:
break;
}
return 0 ;
}
static int F_152 ( struct V_1 * V_8 ,
unsigned char V_54 [] , struct V_57 * V_318 ,
unsigned char * V_342 )
{
#define F_153 43
#define F_154 "$DR-10"
#define F_155 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_156 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_343 ;
unsigned char * V_344 ;
V_343 = F_83 ( F_156 , V_154 ) ;
if ( ! V_343 )
goto V_345;
if ( F_127 ( V_8 , V_54 , 0 , V_343 ,
( unsigned char ) F_156 ) != 0 ) {
F_61 ( & V_8 -> V_15 -> V_16 ,
L_134 ) ;
goto V_345;
}
V_318 -> V_133 = ( V_343 [ 0 ] & 0x1f ) ;
memcpy ( V_318 -> V_54 , V_54 , 8 ) ;
memcpy ( V_318 -> V_146 , & V_343 [ 8 ] ,
sizeof( V_318 -> V_146 ) ) ;
memcpy ( V_318 -> V_145 , & V_343 [ 16 ] ,
sizeof( V_318 -> V_145 ) ) ;
memset ( V_318 -> V_69 , 0 ,
sizeof( V_318 -> V_69 ) ) ;
F_141 ( V_8 , V_54 , V_318 -> V_69 ,
sizeof( V_318 -> V_69 ) ) ;
if ( V_318 -> V_133 == V_346 &&
F_23 ( V_54 ) ) {
int V_151 ;
F_133 ( V_8 , V_54 , & V_318 -> V_64 ) ;
if ( V_8 -> V_347 & V_348 )
F_137 ( V_8 , V_54 , V_318 ) ;
V_151 = F_147 ( V_8 , V_54 ) ;
if ( V_151 < 0 || V_151 > 0xff )
V_151 = V_158 ;
V_318 -> V_151 = V_151 & 0xff ;
} else {
V_318 -> V_64 = V_65 ;
V_318 -> V_136 = 0 ;
V_318 -> V_70 = 0 ;
V_318 -> V_151 = 0 ;
}
if ( V_342 ) {
V_344 = & V_343 [ F_153 ] ;
* V_342 = ( V_318 -> V_133 == V_349 &&
strncmp ( V_344 , F_154 ,
F_155 ) == 0 ) ;
}
F_69 ( V_343 ) ;
return 0 ;
V_345:
F_69 ( V_343 ) ;
return 1 ;
}
static int F_157 ( struct V_1 * V_8 , struct V_57 * V_28 )
{
int V_51 ;
for ( V_51 = 0 ; V_350 [ V_51 ] ; V_51 ++ )
if ( strncmp ( V_28 -> V_145 , V_350 [ V_51 ] ,
strlen ( V_350 [ V_51 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_158 ( struct V_1 * V_8 ,
T_4 * V_351 , struct V_57 * V_28 )
{
T_3 V_67 = F_104 ( * ( ( V_352 * ) V_351 ) ) ;
if ( ! F_23 ( V_351 ) ) {
if ( F_53 ( V_351 ) )
F_145 ( V_28 , 3 , 0 , V_67 & 0x3fff ) ;
else
F_145 ( V_28 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_157 ( V_8 , V_28 ) ) {
F_145 ( V_28 ,
1 , ( V_67 >> 16 ) & 0x3fff , V_67 & 0x00ff ) ;
return;
}
F_145 ( V_28 , 0 , 0 , V_67 & 0x3fff ) ;
}
static int F_159 ( struct V_1 * V_8 ,
struct V_57 * V_353 ,
struct V_57 * V_318 , T_4 * V_351 ,
unsigned long V_354 [] , int * V_355 )
{
unsigned char V_54 [ 8 ] ;
if ( F_160 ( V_353 -> V_119 , V_354 ) )
return 0 ;
if ( ! F_23 ( V_351 ) )
return 0 ;
if ( ! F_157 ( V_8 , V_353 ) )
return 0 ;
if ( V_353 -> V_120 == 0 )
return 0 ;
memset ( V_54 , 0 , 8 ) ;
V_54 [ 3 ] = V_353 -> V_119 ;
if ( F_53 ( V_54 ) )
return 0 ;
if ( F_54 ( V_8 ) )
return 0 ;
if ( * V_355 >= V_356 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_135
L_136
L_137 ) ;
return 0 ;
}
if ( F_152 ( V_8 , V_54 , V_318 , NULL ) )
return 0 ;
( * V_355 ) ++ ;
F_145 ( V_318 ,
V_353 -> V_118 , V_353 -> V_119 , 0 ) ;
F_161 ( V_353 -> V_119 , V_354 ) ;
return 1 ;
}
static int F_162 ( struct V_1 * V_8 ,
struct V_9 * V_357 , unsigned char * V_54 )
{
struct V_358 * V_359 = NULL ;
int V_360 = 24 ;
int V_361 = 2 ;
int V_362 = sizeof( * V_359 ) + V_363 * V_360 ;
T_3 V_364 = 0 ;
int V_121 = 0 ;
T_3 V_365 ;
int V_51 ;
struct V_195 * V_366 ;
struct V_57 * V_279 ;
struct V_99 * V_367 ;
T_3 V_368 ;
T_3 V_369 ;
if ( V_357 -> V_112 != V_114 )
return 0 ;
V_367 = & V_8 -> V_100 [ V_357 -> V_96 ] ;
if ( V_367 == NULL )
return 0 ;
V_366 = (struct V_195 * ) V_357 -> V_233 ;
if ( V_366 == NULL )
return 0 ;
V_279 = V_366 -> V_28 -> V_61 ;
if ( V_279 == NULL )
return 0 ;
V_368 = F_96 ( V_279 -> V_137 ) ;
V_369 = F_96 ( V_367 -> V_369 ) ;
V_365 = V_367 -> V_369 ;
if ( V_8 -> V_43 > 0 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_138 ,
V_155 , V_369 ,
V_279 -> V_69 [ 0 ] , V_279 -> V_69 [ 1 ] , V_279 -> V_69 [ 2 ] ,
V_279 -> V_69 [ 3 ] , V_279 -> V_69 [ 4 ] , V_279 -> V_69 [ 5 ] ,
V_279 -> V_69 [ 6 ] , V_279 -> V_69 [ 7 ] , V_279 -> V_69 [ 8 ] ,
V_279 -> V_69 [ 9 ] , V_279 -> V_69 [ 10 ] , V_279 -> V_69 [ 11 ] ,
V_279 -> V_69 [ 12 ] , V_279 -> V_69 [ 13 ] , V_279 -> V_69 [ 14 ] ,
V_279 -> V_69 [ 15 ] ) ;
V_359 = F_83 ( V_362 , V_154 ) ;
if ( V_359 == NULL )
return 0 ;
if ( F_143 ( V_8 , (struct V_328 * ) V_359 ,
V_362 , V_361 ) ) {
F_61 ( & V_8 -> V_15 -> V_16 ,
L_139 ,
L_58 ) ;
F_69 ( V_359 ) ;
return 0 ;
}
V_364 = F_163 ( * ( ( V_370 * ) V_359 -> V_371 ) ) /
V_360 ;
for ( V_51 = 0 ; V_51 < V_364 ; V_51 ++ ) {
struct V_372 * V_134 = & V_359 -> V_243 [ V_51 ] ;
if ( V_134 -> V_137 != V_365 )
continue;
V_121 = 1 ;
memcpy ( V_54 , V_134 -> V_67 , 8 ) ;
if ( V_8 -> V_43 > 0 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_140 ,
V_155 , V_365 ,
V_134 -> V_137 , V_54 ) ;
break;
}
F_69 ( V_359 ) ;
if ( V_121 )
return 1 ;
else
return 0 ;
}
static int F_164 ( struct V_1 * V_8 ,
int V_373 , int V_374 ,
struct V_328 * V_375 , T_3 * V_364 , int * V_376 ,
struct V_328 * V_377 , T_3 * V_378 )
{
int V_379 = 8 ;
* V_376 = 0 ;
if ( V_8 -> V_48 & V_78 ||
V_8 -> V_48 & V_380 ) {
* V_376 = V_381 ;
V_379 = 24 ;
}
if ( F_143 ( V_8 , V_375 , V_373 ,
* V_376 ) ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_141 ) ;
return - 1 ;
}
* V_364 = F_163 ( * ( ( V_370 * ) V_375 -> V_371 ) ) /
V_379 ;
if ( * V_364 > V_363 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_142
L_143 , V_363 ,
* V_364 - V_363 ) ;
* V_364 = V_363 ;
}
if ( F_144 ( V_8 , V_377 , V_374 ) ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_144 ) ;
return - 1 ;
}
* V_378 = F_163 ( * ( ( V_370 * ) V_377 -> V_371 ) ) / 8 ;
if ( * V_378 > V_382 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_145
L_146 , V_382 ,
* V_378 - V_382 ) ;
* V_378 = V_382 ;
}
if ( * V_378 + * V_364 > V_363 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_147
L_146 , V_363 ,
* V_364 + * V_378 - V_363 ) ;
* V_378 = V_363 - * V_364 ;
}
return 0 ;
}
static T_4 * F_165 ( struct V_1 * V_8 , int V_383 ,
int V_51 , int V_364 , int V_378 ,
struct V_358 * V_384 ,
struct V_328 * V_385 )
{
int V_386 = V_364 + ( V_383 == 0 ) ;
int V_387 = V_364 + V_378 + ( V_383 == 0 ) ;
if ( V_51 == V_383 )
return V_117 ;
if ( V_51 < V_386 )
return & V_384 -> V_243 [ V_51 -
( V_383 == 0 ) ] . V_67 [ 0 ] ;
if ( V_51 < V_387 )
return & V_385 -> V_243 [ V_51 - V_364 -
( V_383 == 0 ) ] [ 0 ] ;
F_166 () ;
return NULL ;
}
static int F_167 ( struct V_1 * V_8 )
{
int V_274 ;
int V_388 ;
struct V_287 * V_389 ;
V_389 = F_83 ( sizeof( struct V_287 ) ,
V_154 ) ;
if ( ! V_389 )
return - V_180 ;
V_274 = F_131 ( V_8 , V_117 , 0 , V_389 ,
sizeof( struct V_287 ) ) ;
if ( V_274 ) {
F_69 ( V_389 ) ;
return V_274 ;
}
V_388 =
( ( V_389 -> V_390 & V_391 ) != 0 ) ;
F_69 ( V_389 ) ;
return V_388 ;
}
static void F_168 ( struct V_1 * V_8 , int V_125 )
{
struct V_358 * V_384 = NULL ;
struct V_328 * V_385 = NULL ;
T_3 V_364 = 0 ;
T_3 V_378 = 0 ;
int V_376 = 0 ;
T_3 V_392 = 0 ;
struct V_57 * * V_393 , * V_318 , * V_353 ;
int V_394 = 0 ;
int V_51 , V_355 , V_395 ;
int V_383 ;
int V_396 ;
F_56 ( V_354 , V_356 ) ;
V_393 = F_83 ( sizeof( * V_393 ) * V_123 , V_154 ) ;
V_384 = F_83 ( sizeof( * V_384 ) , V_154 ) ;
V_385 = F_83 ( sizeof( * V_385 ) , V_154 ) ;
V_353 = F_83 ( sizeof( * V_353 ) , V_154 ) ;
if ( ! V_393 || ! V_384 || ! V_385 || ! V_353 ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_148 ) ;
goto V_285;
}
memset ( V_354 , 0 , sizeof( V_354 ) ) ;
V_396 = F_167 ( V_8 ) ;
if ( V_396 < 0 )
goto V_285;
if ( ! V_8 -> V_388 && V_396 )
F_5 ( & V_8 -> V_15 -> V_16 , L_149 ) ;
else if ( V_8 -> V_388 && ! V_396 )
F_5 ( & V_8 -> V_15 -> V_16 , L_150 ) ;
V_8 -> V_388 = V_396 ;
if ( F_164 ( V_8 ,
sizeof( * V_384 ) , sizeof( * V_385 ) ,
(struct V_328 * ) V_384 , & V_364 ,
& V_376 , V_385 , & V_378 ) )
goto V_285;
V_395 = V_364 + V_378 + V_356 + 1 ;
for ( V_51 = 0 ; V_51 < V_395 ; V_51 ++ ) {
if ( V_51 >= V_123 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_151
L_152 , V_123 ,
V_395 - V_123 ) ;
break;
}
V_393 [ V_51 ] = F_83 ( sizeof( * V_393 [ V_51 ] ) , V_154 ) ;
if ( ! V_393 [ V_51 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_153 ,
__FILE__ , __LINE__ ) ;
goto V_285;
}
V_392 ++ ;
}
if ( F_54 ( V_8 ) )
V_383 = 0 ;
else
V_383 = V_364 + V_378 ;
V_355 = 0 ;
for ( V_51 = 0 ; V_51 < V_364 + V_378 + 1 ; V_51 ++ ) {
T_4 * V_351 , V_397 = 0 ;
V_351 = F_165 ( V_8 , V_383 ,
V_51 , V_364 , V_378 , V_384 , V_385 ) ;
if ( V_351 [ 3 ] & 0xC0 &&
V_51 < V_364 + ( V_383 == 0 ) )
continue;
if ( F_152 ( V_8 , V_351 , V_353 ,
& V_397 ) )
continue;
F_158 ( V_8 , V_351 , V_353 ) ;
V_318 = V_393 [ V_394 ] ;
if ( F_159 ( V_8 , V_353 , V_318 ,
V_351 , V_354 ,
& V_355 ) ) {
V_394 ++ ;
V_318 = V_393 [ V_394 ] ;
}
* V_318 = * V_353 ;
switch ( V_318 -> V_133 ) {
case V_349 :
if ( V_397 )
V_394 ++ ;
break;
case V_346 :
if ( V_8 -> V_388 ) {
V_318 -> V_70 = 0 ;
V_394 ++ ;
break;
} else if ( V_8 -> V_41 ) {
if ( V_51 >= V_364 ) {
V_394 ++ ;
break;
}
} else {
if ( V_51 < V_364 )
break;
V_394 ++ ;
break;
}
if ( V_376 == V_381 ) {
memcpy ( & V_318 -> V_137 ,
& V_351 [ 20 ] ,
sizeof( V_318 -> V_137 ) ) ;
V_394 ++ ;
}
break;
case V_398 :
case V_399 :
V_394 ++ ;
break;
case V_400 :
if ( ! F_53 ( V_351 ) )
break;
V_394 ++ ;
break;
default:
break;
}
if ( V_394 >= V_123 )
break;
}
F_82 ( V_8 , V_125 , V_393 , V_394 ) ;
V_285:
F_69 ( V_353 ) ;
for ( V_51 = 0 ; V_51 < V_392 ; V_51 ++ )
F_69 ( V_393 [ V_51 ] ) ;
F_69 ( V_393 ) ;
F_69 ( V_384 ) ;
F_69 ( V_385 ) ;
}
static int F_169 ( struct V_1 * V_8 ,
struct V_9 * V_94 ,
struct V_195 * V_196 )
{
unsigned int V_34 ;
struct V_401 * V_402 ;
T_5 V_268 ;
int V_403 , V_51 , V_404 , V_405 ;
struct V_182 * V_406 ;
F_65 ( F_111 ( V_196 ) > V_8 -> V_407 ) ;
V_403 = F_170 ( V_196 ) ;
if ( V_403 < 0 )
return V_403 ;
if ( ! V_403 )
goto V_408;
V_406 = V_94 -> V_187 ;
V_405 = 0 ;
V_404 = 0 ;
F_171 (cmd, sg, use_sg, i) {
if ( V_51 == V_8 -> V_188 - 1 &&
V_403 > V_8 -> V_188 ) {
V_405 = 1 ;
V_406 = V_8 -> V_177 [ V_94 -> V_96 ] ;
V_404 = 0 ;
}
V_268 = ( T_5 ) F_172 ( V_402 ) ;
V_34 = F_173 ( V_402 ) ;
V_406 -> V_194 = F_99 ( V_268 ) ;
V_406 -> V_192 = F_96 ( V_34 ) ;
V_406 -> V_189 = F_96 ( 0 ) ;
V_406 ++ ;
}
( -- V_406 ) -> V_189 = F_96 ( V_270 ) ;
if ( V_403 + V_405 > V_8 -> V_409 )
V_8 -> V_409 = V_403 + V_405 ;
if ( V_405 ) {
V_94 -> V_88 . V_89 = V_8 -> V_188 ;
V_94 -> V_88 . V_191 = F_114 ( V_403 + 1 ) ;
if ( F_95 ( V_8 , V_94 ) ) {
F_109 ( V_196 ) ;
return - 1 ;
}
return 0 ;
}
V_408:
V_94 -> V_88 . V_89 = ( T_4 ) V_403 ;
V_94 -> V_88 . V_191 = F_114 ( V_403 ) ;
return 0 ;
}
static int F_174 ( T_4 * V_103 , int * V_410 )
{
int V_411 = 0 ;
T_3 V_412 ;
T_3 V_413 ;
switch ( V_103 [ 0 ] ) {
case V_414 :
case V_415 :
V_411 = 1 ;
case V_416 :
case V_417 :
if ( * V_410 == 6 ) {
V_412 = ( ( ( T_3 ) V_103 [ 2 ] ) << 8 ) | V_103 [ 3 ] ;
V_413 = V_103 [ 4 ] ;
} else {
F_65 ( * V_410 != 12 ) ;
V_412 = ( ( ( T_3 ) V_103 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 4 ] ) << 8 ) |
V_103 [ 5 ] ;
V_413 =
( ( ( T_3 ) V_103 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 8 ] ) << 8 ) |
V_103 [ 9 ] ;
}
if ( V_413 > 0xffff )
return V_418 ;
V_103 [ 0 ] = V_411 ? V_419 : V_420 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_412 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_412 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_412 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_412 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_413 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_413 ) ;
V_103 [ 9 ] = 0 ;
* V_410 = 10 ;
break;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_410 ,
T_4 * V_54 )
{
struct V_195 * V_196 = V_10 -> V_233 ;
struct V_93 * V_94 = & V_8 -> V_95 [ V_10 -> V_96 ] ;
unsigned int V_34 ;
unsigned int V_421 = 0 ;
struct V_401 * V_402 ;
T_5 V_268 ;
int V_403 , V_51 ;
struct V_182 * V_406 ;
T_3 V_422 = V_423 ;
if ( F_111 ( V_196 ) > V_8 -> V_424 )
return V_418 ;
F_65 ( V_196 -> V_425 > V_426 ) ;
if ( F_174 ( V_103 , & V_410 ) )
return V_418 ;
V_10 -> V_112 = V_113 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_427 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_65 ( V_10 -> V_86 & 0x0000007F ) ;
V_403 = F_170 ( V_196 ) ;
if ( V_403 < 0 )
return V_403 ;
if ( V_403 ) {
V_406 = V_94 -> V_187 ;
F_171 (cmd, sg, use_sg, i) {
V_268 = ( T_5 ) F_172 ( V_402 ) ;
V_34 = F_173 ( V_402 ) ;
V_421 += V_34 ;
V_406 -> V_194 = F_99 ( V_268 ) ;
V_406 -> V_192 = F_96 ( V_34 ) ;
V_406 -> V_189 = F_96 ( 0 ) ;
V_406 ++ ;
}
( -- V_406 ) -> V_189 = F_96 ( V_270 ) ;
switch ( V_196 -> V_428 ) {
case V_429 :
V_422 |= V_430 ;
break;
case V_431 :
V_422 |= V_432 ;
break;
case V_433 :
V_422 |= V_434 ;
break;
default:
F_61 ( & V_8 -> V_15 -> V_16 , L_154 ,
V_196 -> V_428 ) ;
F_166 () ;
break;
}
} else {
V_422 |= V_434 ;
}
V_10 -> V_88 . V_89 = V_403 ;
V_94 -> V_435 = V_137 & 0xFFFF ;
V_94 -> V_436 = V_421 ;
V_94 -> V_240 = V_437 |
( V_410 & V_241 ) ;
V_94 -> V_422 = V_422 ;
memcpy ( V_94 -> V_107 , V_103 , V_410 ) ;
memcpy ( V_94 -> V_245 , V_54 , 8 ) ;
F_47 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_176 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_195 * V_196 = V_10 -> V_233 ;
struct V_57 * V_16 = V_196 -> V_28 -> V_61 ;
return F_177 ( V_8 , V_10 , V_16 -> V_137 ,
V_196 -> V_438 , V_196 -> V_425 , V_16 -> V_54 ) ;
}
static void F_178 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_99 * V_94 )
{
struct V_195 * V_196 = V_10 -> V_233 ;
struct V_57 * V_16 = V_196 -> V_28 -> V_61 ;
struct V_293 * V_298 = & V_16 -> V_139 ;
T_5 V_439 ;
F_65 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
if ( ! ( V_298 -> V_59 & V_315 ) )
return;
V_94 -> V_316 = V_298 -> V_316 ;
V_94 -> V_440 |= V_441 ;
switch ( V_196 -> V_438 [ 0 ] ) {
case V_414 :
case V_416 :
if ( V_298 -> V_305 == 512 ) {
V_94 -> V_442 =
( ( ( T_3 ) V_196 -> V_438 [ 2 ] ) << 8 ) |
V_196 -> V_438 [ 3 ] ;
V_94 -> V_443 = 0 ;
} else {
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 8 ) |
V_196 -> V_438 [ 3 ] ;
V_439 = ( V_439 * V_298 -> V_305 ) / 512 ;
V_94 -> V_442 = ( T_3 ) V_439 ;
V_94 -> V_443 = ( T_3 ) ( V_439 >> 32 ) ;
}
break;
case V_419 :
case V_420 :
if ( V_298 -> V_305 == 512 ) {
V_94 -> V_442 =
( ( ( T_3 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_94 -> V_443 = 0 ;
} else {
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_439 = ( V_439 * V_298 -> V_305 ) / 512 ;
V_94 -> V_442 = ( T_3 ) V_439 ;
V_94 -> V_443 = ( T_3 ) ( V_439 >> 32 ) ;
}
break;
case V_415 :
case V_417 :
if ( V_298 -> V_305 == 512 ) {
V_94 -> V_442 =
( ( ( T_3 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_94 -> V_443 = 0 ;
} else {
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_439 = ( V_439 * V_298 -> V_305 ) / 512 ;
V_94 -> V_442 = ( T_3 ) V_439 ;
V_94 -> V_443 = ( T_3 ) ( V_439 >> 32 ) ;
}
break;
case V_444 :
case V_445 :
if ( V_298 -> V_305 == 512 ) {
V_94 -> V_442 =
( ( ( T_3 ) V_196 -> V_438 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 8 ] ) << 8 ) |
V_196 -> V_438 [ 9 ] ;
V_94 -> V_443 =
( ( ( T_3 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
} else {
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_196 -> V_438 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_196 -> V_438 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 8 ] ) << 8 ) |
V_196 -> V_438 [ 9 ] ;
V_439 = ( V_439 * V_298 -> V_305 ) / 512 ;
V_94 -> V_442 = ( T_3 ) V_439 ;
V_94 -> V_443 = ( T_3 ) ( V_439 >> 32 ) ;
}
break;
default:
F_61 ( & V_8 -> V_15 -> V_16 ,
L_155 ,
V_155 ) ;
F_166 () ;
break;
}
}
static int F_179 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_410 ,
T_4 * V_54 )
{
struct V_195 * V_196 = V_10 -> V_233 ;
struct V_99 * V_94 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
struct V_446 * V_406 ;
int V_403 , V_51 ;
struct V_401 * V_402 ;
T_5 V_268 ;
T_3 V_34 ;
T_3 V_421 = 0 ;
if ( F_111 ( V_196 ) > V_8 -> V_424 )
return V_418 ;
if ( F_174 ( V_103 , & V_410 ) )
return V_418 ;
V_10 -> V_112 = V_114 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_447 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_65 ( V_10 -> V_86 & 0x0000007F ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_448 = V_449 ;
V_403 = F_170 ( V_196 ) ;
if ( V_403 < 0 )
return V_403 ;
if ( V_403 ) {
F_65 ( V_403 > V_450 ) ;
V_406 = V_94 -> V_402 ;
F_171 (cmd, sg, use_sg, i) {
V_268 = ( T_5 ) F_172 ( V_402 ) ;
V_34 = F_173 ( V_402 ) ;
V_421 += V_34 ;
V_406 -> V_451 = F_99 ( V_268 ) ;
V_406 -> V_452 = F_96 ( V_34 ) ;
V_406 -> V_453 [ 0 ] = 0 ;
V_406 -> V_453 [ 1 ] = 0 ;
V_406 -> V_453 [ 2 ] = 0 ;
V_406 -> V_454 = 0 ;
V_406 ++ ;
}
switch ( V_196 -> V_428 ) {
case V_429 :
V_94 -> V_440 &= ~ V_455 ;
V_94 -> V_440 |= V_456 ;
break;
case V_431 :
V_94 -> V_440 &= ~ V_455 ;
V_94 -> V_440 |= V_457 ;
break;
case V_433 :
V_94 -> V_440 &= ~ V_455 ;
V_94 -> V_440 |= V_458 ;
break;
default:
F_61 ( & V_8 -> V_15 -> V_16 , L_154 ,
V_196 -> V_428 ) ;
F_166 () ;
break;
}
} else {
V_94 -> V_440 &= ~ V_455 ;
V_94 -> V_440 |= V_458 ;
}
F_178 ( V_8 , V_10 , V_94 ) ;
V_94 -> V_369 = V_137 ;
V_94 -> V_459 = ( V_10 -> V_96 << V_460 ) |
V_461 ;
memcpy ( V_94 -> V_103 , V_103 , sizeof( V_94 -> V_103 ) ) ;
V_94 -> V_102 = ( T_4 ) V_403 ;
V_94 -> V_198 = F_96 ( V_421 ) ;
V_94 -> V_462 = F_99 ( V_10 -> V_86 +
F_180 ( struct V_99 , V_200 ) ) ;
V_94 -> V_463 = F_96 ( sizeof( V_94 -> V_200 ) ) ;
F_47 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_410 ,
T_4 * V_54 )
{
if ( V_8 -> V_48 & V_78 )
return F_175 ( V_8 , V_10 , V_137 ,
V_103 , V_410 , V_54 ) ;
else
return F_179 ( V_8 , V_10 , V_137 ,
V_103 , V_410 , V_54 ) ;
}
static void F_181 ( struct V_293 * V_298 ,
int V_138 , T_3 * V_464 , T_3 * V_465 )
{
if ( V_138 == 0 ) {
* V_464 %= V_298 -> V_312 ;
return;
}
do {
* V_465 = * V_464 / V_298 -> V_312 ;
if ( V_138 == * V_465 )
continue;
if ( * V_465 < ( V_298 -> V_314 - 1 ) ) {
* V_464 += V_298 -> V_312 ;
( * V_465 ) ++ ;
} else {
* V_464 %= V_298 -> V_312 ;
* V_465 = 0 ;
}
} while ( V_138 != * V_465 );
}
static int F_182 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_195 * V_196 = V_10 -> V_233 ;
struct V_57 * V_16 = V_196 -> V_28 -> V_61 ;
struct V_293 * V_298 = & V_16 -> V_139 ;
struct V_295 * V_296 = & V_298 -> V_297 [ 0 ] ;
int V_411 = 0 ;
T_3 V_464 ;
T_5 V_439 , V_466 ;
T_3 V_413 ;
T_3 V_467 ;
T_5 V_468 , V_469 ;
T_3 V_470 , V_471 ;
T_3 V_472 , V_473 ;
T_5 V_474 , V_475 ;
T_3 V_476 ;
T_5 V_477 , V_478 ;
T_3 V_479 , V_480 ;
T_3 V_481 , V_482 ;
T_3 V_483 ;
T_3 V_484 ;
T_3 V_485 , V_486 , V_465 ;
T_3 V_487 ;
T_3 V_488 ;
T_5 V_489 ;
T_3 V_490 ;
T_4 V_103 [ 16 ] ;
T_4 V_410 ;
#if V_491 == 32
T_5 V_492 ;
#endif
int V_138 ;
F_65 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
switch ( V_196 -> V_438 [ 0 ] ) {
case V_414 :
V_411 = 1 ;
case V_416 :
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 8 ) |
V_196 -> V_438 [ 3 ] ;
V_413 = V_196 -> V_438 [ 4 ] ;
if ( V_413 == 0 )
V_413 = 256 ;
break;
case V_419 :
V_411 = 1 ;
case V_420 :
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_413 =
( ( ( T_3 ) V_196 -> V_438 [ 7 ] ) << 8 ) |
V_196 -> V_438 [ 8 ] ;
break;
case V_415 :
V_411 = 1 ;
case V_417 :
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 8 ) |
V_196 -> V_438 [ 5 ] ;
V_413 =
( ( ( T_3 ) V_196 -> V_438 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 8 ] ) << 8 ) |
V_196 -> V_438 [ 9 ] ;
break;
case V_444 :
V_411 = 1 ;
case V_445 :
V_439 =
( ( ( T_5 ) V_196 -> V_438 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_196 -> V_438 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_196 -> V_438 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_196 -> V_438 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_196 -> V_438 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_196 -> V_438 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_196 -> V_438 [ 8 ] ) << 8 ) |
V_196 -> V_438 [ 9 ] ;
V_413 =
( ( ( T_3 ) V_196 -> V_438 [ 10 ] ) << 24 ) |
( ( ( T_3 ) V_196 -> V_438 [ 11 ] ) << 16 ) |
( ( ( T_3 ) V_196 -> V_438 [ 12 ] ) << 8 ) |
V_196 -> V_438 [ 13 ] ;
break;
default:
return V_418 ;
}
V_466 = V_439 + V_413 - 1 ;
if ( V_411 && V_16 -> V_64 != 0 )
return V_418 ;
if ( V_466 >= V_298 -> V_306 || V_466 < V_439 )
return V_418 ;
V_467 = V_298 -> V_312 * V_298 -> V_309 ;
#if V_491 == 32
V_492 = V_439 ;
( void ) F_183 ( V_492 , V_467 ) ;
V_468 = V_492 ;
V_492 = V_466 ;
( void ) F_183 ( V_492 , V_467 ) ;
V_469 = V_492 ;
V_470 = ( T_3 ) ( V_439 - ( V_468 * V_467 ) ) ;
V_471 = ( T_3 ) ( V_466 - ( V_469 * V_467 ) ) ;
V_492 = V_470 ;
( void ) F_183 ( V_492 , V_298 -> V_309 ) ;
V_472 = V_492 ;
V_492 = V_471 ;
( void ) F_183 ( V_492 , V_298 -> V_309 ) ;
V_473 = V_492 ;
#else
V_468 = V_439 / V_467 ;
V_469 = V_466 / V_467 ;
V_470 = ( T_3 ) ( V_439 - ( V_468 * V_467 ) ) ;
V_471 = ( T_3 ) ( V_466 - ( V_469 * V_467 ) ) ;
V_472 = V_470 / V_298 -> V_309 ;
V_473 = V_471 / V_298 -> V_309 ;
#endif
if ( ( V_468 != V_469 ) || ( V_472 != V_473 ) )
return V_418 ;
V_483 = V_298 -> V_312 +
V_298 -> V_313 ;
V_487 = ( ( T_3 ) ( V_468 >> V_298 -> V_308 ) ) %
V_298 -> V_302 ;
V_464 = ( V_487 * V_483 ) + V_472 ;
switch ( V_16 -> V_64 ) {
case V_493 :
break;
case V_494 :
F_65 ( V_298 -> V_314 != 2 ) ;
if ( V_16 -> V_138 )
V_464 += V_298 -> V_312 ;
V_16 -> V_138 = ! V_16 -> V_138 ;
break;
case V_495 :
F_65 ( V_298 -> V_314 != 3 ) ;
V_138 = V_16 -> V_138 ;
F_181 ( V_298 , V_138 ,
& V_464 , & V_465 ) ;
V_138 =
( V_138 >= V_298 -> V_314 - 1 )
? 0 : V_138 + 1 ;
V_16 -> V_138 = V_138 ;
break;
case V_496 :
case V_497 :
if ( V_298 -> V_314 <= 1 )
break;
V_476 =
V_298 -> V_309 * V_298 -> V_312 ;
F_65 ( V_476 == 0 ) ;
V_484 = V_476 * V_298 -> V_314 ;
#if V_491 == 32
V_492 = V_439 ;
V_485 = F_183 ( V_492 , V_484 ) ;
V_492 = V_485 ;
( void ) F_183 ( V_492 , V_476 ) ;
V_485 = V_492 ;
V_492 = V_466 ;
V_486 = F_183 ( V_492 , V_484 ) ;
V_492 = V_486 ;
( void ) F_183 ( V_492 , V_476 ) ;
V_486 = V_492 ;
#else
V_485 = ( V_439 % V_484 ) / V_476 ;
V_486 = ( V_466 % V_484 ) / V_476 ;
#endif
if ( V_485 != V_486 )
return V_418 ;
#if V_491 == 32
V_492 = V_439 ;
( void ) F_183 ( V_492 , V_484 ) ;
V_468 = V_477 = V_474 = V_492 ;
V_492 = V_466 ;
( void ) F_183 ( V_492 , V_484 ) ;
V_478 = V_475 = V_492 ;
#else
V_468 = V_477 = V_474 =
V_439 / V_484 ;
V_478 = V_475 = V_466 / V_484 ;
#endif
if ( V_477 != V_478 )
return V_418 ;
#if V_491 == 32
V_492 = V_439 ;
V_470 = F_183 ( V_492 , V_484 ) ;
V_492 = V_470 ;
V_470 = ( T_3 ) F_183 ( V_492 , V_476 ) ;
V_479 = V_470 ;
V_492 = V_466 ;
V_480 = F_183 ( V_492 , V_484 ) ;
V_492 = V_480 ;
V_480 = F_183 ( V_492 , V_476 ) ;
V_492 = V_479 ;
( void ) F_183 ( V_492 , V_298 -> V_309 ) ;
V_472 = V_481 = V_492 ;
V_492 = V_480 ;
( void ) F_183 ( V_492 , V_298 -> V_309 ) ;
V_482 = V_492 ;
#else
V_470 = V_479 =
( T_3 ) ( ( V_439 % V_484 ) %
V_476 ) ;
V_480 =
( T_3 ) ( ( V_466 % V_484 ) %
V_476 ) ;
V_472 = V_481 =
V_479 / V_298 -> V_309 ;
V_482 =
V_480 / V_298 -> V_309 ;
#endif
if ( V_481 != V_482 )
return V_418 ;
V_487 = ( ( T_3 ) ( V_468 >> V_298 -> V_308 ) ) %
V_298 -> V_302 ;
V_464 = ( V_485 *
( V_298 -> V_302 * V_483 ) ) +
( V_487 * V_483 ) + V_472 ;
break;
default:
return V_418 ;
}
V_488 = V_296 [ V_464 ] . V_137 ;
V_489 = V_298 -> V_310 + ( V_468 * V_298 -> V_309 ) +
( V_470 - ( V_472 * V_298 -> V_309 ) ) ;
V_490 = V_413 ;
if ( V_298 -> V_307 ) {
V_489 <<= V_298 -> V_307 ;
V_490 <<= V_298 -> V_307 ;
}
F_65 ( V_490 > 0xffff ) ;
if ( V_489 > 0xffffffff ) {
V_103 [ 0 ] = V_411 ? V_444 : V_445 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_489 >> 56 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_489 >> 48 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_489 >> 40 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_489 >> 32 ) ;
V_103 [ 6 ] = ( T_4 ) ( V_489 >> 24 ) ;
V_103 [ 7 ] = ( T_4 ) ( V_489 >> 16 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_489 >> 8 ) ;
V_103 [ 9 ] = ( T_4 ) ( V_489 ) ;
V_103 [ 10 ] = ( T_4 ) ( V_490 >> 24 ) ;
V_103 [ 11 ] = ( T_4 ) ( V_490 >> 16 ) ;
V_103 [ 12 ] = ( T_4 ) ( V_490 >> 8 ) ;
V_103 [ 13 ] = ( T_4 ) ( V_490 ) ;
V_103 [ 14 ] = 0 ;
V_103 [ 15 ] = 0 ;
V_410 = 16 ;
} else {
V_103 [ 0 ] = V_411 ? V_419 : V_420 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_489 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_489 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_489 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_489 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_490 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_490 ) ;
V_103 [ 9 ] = 0 ;
V_410 = 10 ;
}
return F_177 ( V_8 , V_10 , V_488 , V_103 , V_410 ,
V_16 -> V_54 ) ;
}
static int F_184 ( struct V_6 * V_7 , struct V_195 * V_196 )
{
struct V_1 * V_8 ;
struct V_57 * V_16 ;
unsigned char V_54 [ 8 ] ;
struct V_9 * V_10 ;
int V_274 = 0 ;
V_8 = F_1 ( V_196 -> V_28 ) ;
V_16 = V_196 -> V_28 -> V_61 ;
if ( ! V_16 ) {
V_196 -> V_205 = V_248 << 16 ;
V_196 -> V_224 ( V_196 ) ;
return 0 ;
}
memcpy ( V_54 , V_16 -> V_54 , sizeof( V_54 ) ) ;
if ( F_34 ( F_118 ( V_8 ) ) ) {
V_196 -> V_205 = V_253 << 16 ;
V_196 -> V_224 ( V_196 ) ;
return 0 ;
}
V_10 = F_151 ( V_8 ) ;
if ( V_10 == NULL ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_156 ) ;
return V_498 ;
}
V_196 -> V_499 = ( unsigned char * ) V_10 ;
V_10 -> V_112 = V_234 ;
V_10 -> V_233 = V_196 ;
if ( F_37 ( V_196 -> V_500 == 0 &&
V_196 -> V_501 -> V_112 == V_502 &&
V_8 -> V_41 ) ) {
if ( V_16 -> V_70 ) {
V_274 = F_182 ( V_8 , V_10 ) ;
if ( V_274 == 0 )
return 0 ;
if ( V_274 < 0 ) {
F_107 ( V_8 , V_10 ) ;
return V_498 ;
}
} else if ( V_16 -> V_137 ) {
V_274 = F_176 ( V_8 , V_10 ) ;
if ( V_274 == 0 )
return 0 ;
if ( V_274 < 0 ) {
F_107 ( V_8 , V_10 ) ;
return V_498 ;
}
}
}
V_10 -> V_88 . V_91 = 0 ;
memcpy ( & V_10 -> V_88 . V_243 . V_244 [ 0 ] , & V_54 [ 0 ] , 8 ) ;
V_10 -> V_88 . V_242 = F_99 ( ( V_10 -> V_96 << V_460 ) |
V_461 ) ;
V_10 -> V_106 . V_503 = 0 ;
memset ( V_10 -> V_106 . V_107 , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
F_65 ( V_196 -> V_425 > sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_239 = V_196 -> V_425 ;
memcpy ( V_10 -> V_106 . V_107 , V_196 -> V_438 , V_196 -> V_425 ) ;
switch ( V_196 -> V_428 ) {
case V_429 :
V_10 -> V_106 . V_504 =
F_185 ( V_284 , V_505 , V_506 ) ;
break;
case V_431 :
V_10 -> V_106 . V_504 =
F_185 ( V_284 , V_505 , V_507 ) ;
break;
case V_433 :
V_10 -> V_106 . V_504 =
F_185 ( V_284 , V_505 , V_508 ) ;
break;
case V_509 :
V_10 -> V_106 . V_504 =
F_185 ( V_284 , V_505 , V_510 ) ;
break;
default:
F_61 ( & V_8 -> V_15 -> V_16 , L_154 ,
V_196 -> V_428 ) ;
F_166 () ;
break;
}
if ( F_169 ( V_8 , V_10 , V_196 ) < 0 ) {
F_107 ( V_8 , V_10 ) ;
return V_498 ;
}
F_47 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
if ( F_34 ( F_118 ( V_8 ) ) ) {
F_26 ( & V_8 -> V_511 , V_59 ) ;
V_8 -> V_512 = 1 ;
F_187 ( & V_8 -> V_513 ) ;
F_27 ( & V_8 -> V_511 , V_59 ) ;
return 1 ;
}
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
if ( F_186 ( V_8 ) )
return;
while ( 1 ) {
F_26 ( & V_8 -> V_511 , V_59 ) ;
if ( V_8 -> V_512 )
break;
F_27 ( & V_8 -> V_511 , V_59 ) ;
F_188 ( V_8 -> V_513 , V_8 -> V_512 ) ;
}
V_8 -> V_512 = 0 ;
F_27 ( & V_8 -> V_511 , V_59 ) ;
if ( F_186 ( V_8 ) )
return;
F_168 ( V_8 , V_8 -> V_44 -> V_159 ) ;
F_26 ( & V_8 -> V_511 , V_59 ) ;
V_8 -> V_512 = 1 ;
F_187 ( & V_8 -> V_513 ) ;
F_27 ( & V_8 -> V_511 , V_59 ) ;
}
static int F_189 ( struct V_6 * V_7 ,
unsigned long V_514 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
int V_515 ;
F_26 ( & V_8 -> V_511 , V_59 ) ;
V_515 = V_8 -> V_512 ;
F_27 ( & V_8 -> V_511 , V_59 ) ;
return V_515 ;
}
static void F_190 ( struct V_1 * V_8 )
{
F_191 ( V_8 -> V_44 ) ;
F_192 ( V_8 -> V_44 ) ;
V_8 -> V_44 = NULL ;
}
static int F_193 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_194 ( & V_516 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_517;
V_7 -> V_518 = 0 ;
V_7 -> V_519 = 0 ;
V_7 -> V_520 = - 1 ;
V_7 -> V_521 = 3 ;
V_7 -> V_522 = V_523 ;
V_7 -> V_524 = V_382 ;
V_7 -> V_525 = V_382 ;
V_7 -> V_526 = V_8 -> V_178 ;
if ( V_8 -> V_388 )
V_7 -> V_527 = 7 ;
else
V_7 -> V_527 = V_8 -> V_178 ;
V_7 -> V_528 = V_8 -> V_407 ;
V_8 -> V_44 = V_7 ;
V_7 -> V_61 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_529 = V_8 -> V_530 [ V_8 -> V_531 ] ;
V_7 -> V_532 = V_7 -> V_529 ;
error = F_195 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_533;
F_196 ( V_7 ) ;
return 0 ;
V_533:
F_61 ( & V_8 -> V_15 -> V_16 , L_157
L_158 , V_155 , V_8 -> V_18 ) ;
F_192 ( V_7 ) ;
return error ;
V_517:
F_61 ( & V_8 -> V_15 -> V_16 , L_159
L_158 , V_155 , V_8 -> V_18 ) ;
return - V_180 ;
}
static int F_197 ( struct V_1 * V_8 ,
unsigned char V_534 [] )
{
int V_274 ;
int V_32 = 0 ;
int V_535 = 1 ;
struct V_9 * V_10 ;
V_10 = F_128 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_49
L_160 ) ;
return V_536 ;
}
while ( V_32 < V_537 ) {
F_124 ( 1000 * V_535 ) ;
V_32 ++ ;
V_274 = 0 ;
if ( V_535 < V_538 )
V_535 = V_535 * 2 ;
( void ) F_129 ( V_10 , V_340 , V_8 ,
NULL , 0 , 0 , V_534 , V_284 ) ;
F_115 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_23 == V_539 )
break;
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 == V_206 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_540 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_161
L_162 , V_535 ) ;
V_274 = 1 ;
}
if ( V_274 )
F_5 ( & V_8 -> V_15 -> V_16 , L_163 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ) ;
F_130 ( V_8 , V_10 ) ;
return V_274 ;
}
static int F_198 ( struct V_195 * V_541 )
{
int V_274 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
V_8 = F_1 ( V_541 -> V_28 ) ;
if ( V_8 == NULL )
return V_542 ;
V_16 = V_541 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_165
L_166 ) ;
return V_542 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_167 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_274 = F_132 ( V_8 , V_16 -> V_54 , V_543 ) ;
if ( V_274 == 0 && F_197 ( V_8 , V_16 -> V_54 ) == 0 )
return V_544 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_168 ) ;
return V_542 ;
}
static void F_199 ( T_4 * V_242 )
{
T_4 V_545 [ 8 ] ;
memcpy ( V_545 , V_242 , 8 ) ;
V_242 [ 0 ] = V_545 [ 3 ] ;
V_242 [ 1 ] = V_545 [ 2 ] ;
V_242 [ 2 ] = V_545 [ 1 ] ;
V_242 [ 3 ] = V_545 [ 0 ] ;
V_242 [ 4 ] = V_545 [ 7 ] ;
V_242 [ 5 ] = V_545 [ 6 ] ;
V_242 [ 6 ] = V_545 [ 5 ] ;
V_242 [ 7 ] = V_545 [ 4 ] ;
}
static void F_200 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 * V_546 , T_3 * V_547 )
{
if ( V_10 -> V_112 == V_113 ) {
struct V_93 * V_548 = (struct V_93 * )
& V_8 -> V_95 [ V_10 -> V_96 ] ;
* V_547 = ( T_3 ) ( V_548 -> V_242 >> 32 ) ;
* V_546 = ( T_3 ) ( V_548 -> V_242 & 0x0ffffffffULL ) ;
return;
}
if ( V_10 -> V_112 == V_114 ) {
struct V_99 * V_549 = (struct V_99 * )
& V_8 -> V_100 [ V_10 -> V_96 ] ;
memset ( V_547 , 0 , sizeof( * V_547 ) ) ;
* V_546 = V_549 -> V_459 ;
return;
}
* V_547 = ( T_3 ) ( V_10 -> V_88 . V_242 >> 32 ) ;
* V_546 = ( T_3 ) ( V_10 -> V_88 . V_242 & 0x0ffffffffULL ) ;
}
static int F_201 ( struct V_1 * V_8 , unsigned char * V_54 ,
struct V_9 * abort , int V_550 )
{
int V_274 = V_282 ;
struct V_9 * V_10 ;
struct V_227 * V_228 ;
T_3 V_547 , V_546 ;
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
return - V_180 ;
}
( void ) F_129 ( V_10 , V_551 , V_8 , abort ,
0 , 0 , V_54 , V_291 ) ;
if ( V_550 )
F_199 ( & V_10 -> V_106 . V_107 [ 4 ] ) ;
F_115 ( V_8 , V_10 ) ;
F_200 ( V_8 , abort , & V_546 , & V_547 ) ;
F_202 ( & V_8 -> V_15 -> V_16 , L_169 ,
V_155 , V_547 , V_546 ) ;
V_228 = V_10 -> V_11 ;
switch ( V_228 -> V_23 ) {
case V_539 :
break;
case V_262 :
V_274 = - 1 ;
break;
default:
F_202 ( & V_8 -> V_15 -> V_16 , L_170 ,
V_155 , V_547 , V_546 ) ;
F_126 ( V_8 , V_10 ) ;
V_274 = - 1 ;
break;
}
F_130 ( V_8 , V_10 ) ;
F_202 ( & V_8 -> V_15 -> V_16 , L_171 ,
V_155 , V_547 , V_546 ) ;
return V_274 ;
}
static struct V_9 * F_203 ( struct V_1 * V_8 ,
struct V_195 * V_365 , struct V_71 * V_552 )
{
unsigned long V_59 ;
struct V_9 * V_10 = NULL ;
if ( ! V_365 )
return NULL ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_79 (c, queue_head, list) {
if ( V_10 -> V_233 == NULL )
continue;
if ( V_10 -> V_233 == V_365 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
}
F_27 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static struct V_9 * F_204 ( struct V_1 * V_8 ,
T_4 * V_242 , struct V_71 * V_552 )
{
unsigned long V_59 ;
struct V_9 * V_10 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_79 (c, queue_head, list) {
if ( memcmp ( & V_10 -> V_88 . V_242 , V_242 , 8 ) != 0 )
continue;
F_27 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
F_27 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static int F_205 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
int V_274 = V_282 ;
struct V_195 * V_366 ;
struct V_57 * V_16 ;
unsigned char V_553 [ 8 ] ;
unsigned char * V_554 = & V_553 [ 0 ] ;
V_366 = (struct V_195 * ) abort -> V_233 ;
V_16 = (struct V_57 * ) ( V_366 -> V_28 -> V_61 ) ;
if ( V_16 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_172 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_173 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ,
V_54 [ 4 ] , V_54 [ 5 ] , V_54 [ 6 ] , V_54 [ 7 ] ) ;
if ( ! V_16 -> V_70 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_174 ) ;
return - 1 ;
}
if ( ! F_162 ( V_8 , abort , V_554 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_175 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_176 ,
V_554 [ 0 ] , V_554 [ 1 ] , V_554 [ 2 ] , V_554 [ 3 ] ,
V_554 [ 4 ] , V_554 [ 5 ] , V_554 [ 6 ] , V_554 [ 7 ] ) ;
V_274 = F_132 ( V_8 , V_554 , V_555 ) ;
if ( V_274 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_177 ,
V_554 [ 0 ] , V_554 [ 1 ] , V_554 [ 2 ] , V_554 [ 3 ] ,
V_554 [ 4 ] , V_554 [ 5 ] , V_554 [ 6 ] , V_554 [ 7 ] ) ;
return V_274 ;
}
if ( F_197 ( V_8 , V_554 ) != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_178 ,
V_554 [ 0 ] , V_554 [ 1 ] , V_554 [ 2 ] , V_554 [ 3 ] ,
V_554 [ 4 ] , V_554 [ 5 ] , V_554 [ 6 ] , V_554 [ 7 ] ) ;
return - 1 ;
}
F_62 ( & V_8 -> V_15 -> V_16 ,
L_179 ,
V_554 [ 0 ] , V_554 [ 1 ] , V_554 [ 2 ] , V_554 [ 3 ] ,
V_554 [ 4 ] , V_554 [ 5 ] , V_554 [ 6 ] , V_554 [ 7 ] ) ;
return V_274 ;
}
static int F_206 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
T_4 V_556 [ 8 ] ;
struct V_9 * V_10 ;
int V_274 = 0 , V_557 = 0 ;
if ( abort -> V_112 == V_114 )
return F_205 ( V_8 , V_54 , abort ) ;
memcpy ( V_556 , & abort -> V_106 . V_107 [ 4 ] , 8 ) ;
F_199 ( V_556 ) ;
V_10 = F_204 ( V_8 , V_556 , & V_8 -> V_558 ) ;
if ( V_10 != NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_180 ) ;
return F_201 ( V_8 , V_54 , abort , 0 ) ;
}
V_274 = F_201 ( V_8 , V_54 , abort , 0 ) ;
V_10 = F_203 ( V_8 , abort -> V_233 , & V_8 -> V_558 ) ;
if ( V_10 )
V_557 = F_201 ( V_8 , V_54 , abort , 1 ) ;
return V_274 && V_557 ;
}
static int F_207 ( struct V_195 * V_559 )
{
int V_51 , V_274 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
struct V_9 * abort ;
struct V_9 * V_121 ;
struct V_195 * V_560 ;
char V_561 [ 256 ] ;
int V_562 = 0 ;
T_3 V_547 , V_546 ;
V_8 = F_1 ( V_559 -> V_28 ) ;
if ( F_208 ( V_8 == NULL ,
L_181 ) )
return V_542 ;
if ( ! ( V_563 & V_8 -> V_564 ) &&
! ( V_565 & V_8 -> V_564 ) )
return V_542 ;
memset ( V_561 , 0 , sizeof( V_561 ) ) ;
V_562 += sprintf ( V_561 + V_562 , L_182 ,
V_8 -> V_44 -> V_159 , V_559 -> V_28 -> V_566 ,
V_559 -> V_28 -> V_567 , V_559 -> V_28 -> V_120 ) ;
V_16 = V_559 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_183 ,
V_561 ) ;
return V_542 ;
}
abort = (struct V_9 * ) V_559 -> V_499 ;
if ( abort == NULL ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_184 ,
V_561 ) ;
return V_542 ;
}
F_200 ( V_8 , abort , & V_546 , & V_547 ) ;
V_562 += sprintf ( V_561 + V_562 , L_185 , V_547 , V_546 ) ;
V_560 = (struct V_195 * ) abort -> V_233 ;
if ( V_560 != NULL )
V_562 += sprintf ( V_561 + V_562 , L_186 ,
V_560 -> V_438 [ 0 ] , V_560 -> V_568 ) ;
F_202 ( & V_8 -> V_15 -> V_16 , L_19 , V_561 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_121 = F_203 ( V_8 , V_559 , & V_8 -> V_115 ) ;
if ( V_121 ) {
V_121 -> V_11 -> V_23 = V_256 ;
F_209 ( V_121 ) ;
F_62 ( & V_8 -> V_15 -> V_16 , L_188 ,
V_561 ) ;
return V_544 ;
}
V_121 = F_203 ( V_8 , V_559 , & V_8 -> V_558 ) ;
if ( ! V_121 ) {
F_202 ( & V_8 -> V_15 -> V_16 , L_189 ,
V_561 ) ;
return V_544 ;
}
V_274 = F_206 ( V_8 , V_16 -> V_54 , abort ) ;
if ( V_274 != 0 ) {
F_202 ( & V_8 -> V_15 -> V_16 , L_190 , V_561 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_191 ,
V_8 -> V_44 -> V_159 ,
V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
return V_542 ;
}
F_62 ( & V_8 -> V_15 -> V_16 , L_192 , V_561 ) ;
#define F_210 30
for ( V_51 = 0 ; V_51 < F_210 * 10 ; V_51 ++ ) {
V_121 = F_203 ( V_8 , V_559 , & V_8 -> V_558 ) ;
if ( ! V_121 )
return V_544 ;
F_124 ( 100 ) ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_193 ,
V_561 , F_210 ) ;
return V_542 ;
}
static struct V_9 * F_151 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_51 ;
union V_569 V_185 ;
V_266 V_570 , V_571 ;
int V_572 ;
V_572 = 0 ;
do {
V_51 = F_59 ( V_8 -> V_573 , V_8 -> V_178 ) ;
if ( V_51 == V_8 -> V_178 )
V_51 = 0 ;
V_572 ++ ;
} while ( F_211 ( V_51 & ( V_491 - 1 ) ,
V_8 -> V_573 + ( V_51 / V_491 ) ) != 0 &&
V_572 < 10 );
if ( V_572 >= 10 )
return NULL ;
V_10 = V_8 -> V_574 + V_51 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_570 = V_8 -> V_575
+ V_51 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_576 + V_51 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_571 = V_8 -> V_577
+ V_51 * sizeof( * V_10 -> V_11 ) ;
V_10 -> V_96 = V_51 ;
F_212 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_570 ;
V_185 . V_578 = ( T_5 ) V_571 ;
V_10 -> V_579 . V_194 = F_99 ( V_571 ) ;
V_10 -> V_579 . V_192 = F_96 ( sizeof( * V_10 -> V_11 ) ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_128 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
V_266 V_570 , V_571 ;
V_10 = F_213 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_570 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_112 = V_234 ;
V_10 -> V_96 = - 1 ;
V_10 -> V_11 = F_213 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_571 ) ;
if ( V_10 -> V_11 == NULL ) {
F_214 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_570 ) ;
return NULL ;
}
F_212 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_570 ;
V_10 -> V_579 . V_194 = F_99 ( V_571 ) ;
V_10 -> V_579 . V_192 = F_96 ( sizeof( * V_10 -> V_11 ) ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_107 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_51 ;
V_51 = V_10 - V_8 -> V_574 ;
F_215 ( V_51 & ( V_491 - 1 ) ,
V_8 -> V_573 + ( V_51 / V_491 ) ) ;
}
static void F_130 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
F_214 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 ,
( V_266 ) F_103 ( V_10 -> V_579 . V_194 ) ) ;
F_214 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_266 ) ( V_10 -> V_86 & V_580 ) ) ;
}
static int F_216 ( struct V_2 * V_16 , int V_196 ,
void T_7 * V_581 )
{
T_8 T_7 * V_582 =
( T_8 T_7 * ) V_581 ;
T_9 V_583 ;
T_9 T_7 * V_584 = F_217 ( sizeof( V_583 ) ) ;
int V_585 ;
T_3 V_94 ;
memset ( & V_583 , 0 , sizeof( V_583 ) ) ;
V_585 = 0 ;
V_585 |= F_218 ( & V_583 . V_586 , & V_582 -> V_586 ,
sizeof( V_583 . V_586 ) ) ;
V_585 |= F_218 ( & V_583 . V_106 , & V_582 -> V_106 ,
sizeof( V_583 . V_106 ) ) ;
V_585 |= F_218 ( & V_583 . V_587 , & V_582 -> V_587 ,
sizeof( V_583 . V_587 ) ) ;
V_585 |= F_219 ( V_583 . V_588 , & V_582 -> V_588 ) ;
V_585 |= F_219 ( V_94 , & V_582 -> V_31 ) ;
V_583 . V_31 = F_220 ( V_94 ) ;
V_585 |= F_221 ( V_584 , & V_583 , sizeof( V_583 ) ) ;
if ( V_585 )
return - V_589 ;
V_585 = F_222 ( V_16 , V_590 , V_584 ) ;
if ( V_585 )
return V_585 ;
V_585 |= F_223 ( & V_582 -> V_587 , & V_584 -> V_587 ,
sizeof( V_582 -> V_587 ) ) ;
if ( V_585 )
return - V_589 ;
return V_585 ;
}
static int F_224 ( struct V_2 * V_16 ,
int V_196 , void T_7 * V_581 )
{
T_10 T_7 * V_582 =
( T_10 T_7 * ) V_581 ;
T_11 V_583 ;
T_11 T_7 * V_584 =
F_217 ( sizeof( V_583 ) ) ;
int V_585 ;
T_3 V_94 ;
memset ( & V_583 , 0 , sizeof( V_583 ) ) ;
V_585 = 0 ;
V_585 |= F_218 ( & V_583 . V_586 , & V_582 -> V_586 ,
sizeof( V_583 . V_586 ) ) ;
V_585 |= F_218 ( & V_583 . V_106 , & V_582 -> V_106 ,
sizeof( V_583 . V_106 ) ) ;
V_585 |= F_218 ( & V_583 . V_587 , & V_582 -> V_587 ,
sizeof( V_583 . V_587 ) ) ;
V_585 |= F_219 ( V_583 . V_588 , & V_582 -> V_588 ) ;
V_585 |= F_219 ( V_583 . V_591 , & V_582 -> V_591 ) ;
V_585 |= F_219 ( V_94 , & V_582 -> V_31 ) ;
V_583 . V_31 = F_220 ( V_94 ) ;
V_585 |= F_221 ( V_584 , & V_583 , sizeof( V_583 ) ) ;
if ( V_585 )
return - V_589 ;
V_585 = F_222 ( V_16 , V_592 , V_584 ) ;
if ( V_585 )
return V_585 ;
V_585 |= F_223 ( & V_582 -> V_587 , & V_584 -> V_587 ,
sizeof( V_582 -> V_587 ) ) ;
if ( V_585 )
return - V_589 ;
return V_585 ;
}
static int F_225 ( struct V_2 * V_16 , int V_196 , void T_7 * V_581 )
{
switch ( V_196 ) {
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
return F_222 ( V_16 , V_196 , V_581 ) ;
case V_608 :
return F_216 ( V_16 , V_196 , V_581 ) ;
case V_609 :
return F_224 ( V_16 , V_196 , V_581 ) ;
default:
return - V_610 ;
}
}
static int F_226 ( struct V_1 * V_8 , void T_7 * V_611 )
{
struct V_612 V_613 ;
if ( ! V_611 )
return - V_40 ;
V_613 . V_614 = F_227 ( V_8 -> V_15 -> V_118 ) ;
V_613 . V_118 = V_8 -> V_15 -> V_118 -> V_615 ;
V_613 . V_616 = V_8 -> V_15 -> V_617 ;
V_613 . V_50 = V_8 -> V_50 ;
if ( F_221 ( V_611 , & V_613 , sizeof( V_613 ) ) )
return - V_589 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_8 , void T_7 * V_611 )
{
T_12 V_618 ;
unsigned char V_619 , V_620 , V_621 ;
int V_274 ;
V_274 = sscanf ( V_622 , L_194 ,
& V_619 , & V_620 , & V_621 ) ;
if ( V_274 != 3 ) {
F_62 ( & V_8 -> V_15 -> V_16 , L_195
L_196 , V_622 ) ;
V_619 = 0 ;
V_620 = 0 ;
V_621 = 0 ;
}
V_618 = ( V_619 << 16 ) | ( V_620 << 8 ) | V_621 ;
if ( ! V_611 )
return - V_40 ;
if ( F_221 ( V_611 , & V_618 , sizeof( T_12 ) ) )
return - V_589 ;
return 0 ;
}
static int F_229 ( struct V_1 * V_8 , void T_7 * V_611 )
{
T_9 V_623 ;
struct V_9 * V_10 ;
char * V_624 = NULL ;
T_5 V_185 ;
int V_274 = 0 ;
if ( ! V_611 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_625 ;
if ( F_218 ( & V_623 , V_611 , sizeof( V_623 ) ) )
return - V_589 ;
if ( ( V_623 . V_588 < 1 ) &&
( V_623 . V_106 . Type . V_626 != V_508 ) ) {
return - V_40 ;
}
if ( V_623 . V_588 > 0 ) {
V_624 = F_80 ( V_623 . V_588 , V_154 ) ;
if ( V_624 == NULL )
return - V_589 ;
if ( V_623 . V_106 . Type . V_626 & V_506 ) {
if ( F_218 ( V_624 , V_623 . V_31 ,
V_623 . V_588 ) ) {
V_274 = - V_589 ;
goto V_627;
}
} else {
memset ( V_624 , 0 , V_623 . V_588 ) ;
}
}
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
V_274 = - V_180 ;
goto V_627;
}
V_10 -> V_112 = V_628 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_623 . V_588 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = F_114 ( 1 ) ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = F_114 ( 0 ) ;
}
memcpy ( & V_10 -> V_88 . V_243 , & V_623 . V_586 , sizeof( V_10 -> V_88 . V_243 ) ) ;
V_10 -> V_88 . V_242 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_623 . V_106 ,
sizeof( V_10 -> V_106 ) ) ;
if ( V_623 . V_588 > 0 ) {
V_185 = F_97 ( V_8 -> V_15 , V_624 ,
V_623 . V_588 , V_629 ) ;
if ( F_98 ( & V_8 -> V_15 -> V_16 , ( V_266 ) V_185 ) ) {
V_10 -> V_187 [ 0 ] . V_194 = F_99 ( 0 ) ;
V_10 -> V_187 [ 0 ] . V_192 = F_96 ( 0 ) ;
V_274 = - V_180 ;
goto V_285;
}
V_10 -> V_187 [ 0 ] . V_194 = F_99 ( V_185 ) ;
V_10 -> V_187 [ 0 ] . V_192 = F_96 ( V_623 . V_588 ) ;
V_10 -> V_187 [ 0 ] . V_189 = F_96 ( V_270 ) ;
}
F_122 ( V_8 , V_10 ) ;
if ( V_623 . V_588 > 0 )
F_112 ( V_8 -> V_15 , V_10 , 1 , V_629 ) ;
F_230 ( V_8 , V_10 ) ;
memcpy ( & V_623 . V_587 , V_10 -> V_11 ,
sizeof( V_623 . V_587 ) ) ;
if ( F_221 ( V_611 , & V_623 , sizeof( V_623 ) ) ) {
V_274 = - V_589 ;
goto V_285;
}
if ( ( V_623 . V_106 . Type . V_626 & V_507 ) &&
V_623 . V_588 > 0 ) {
if ( F_221 ( V_623 . V_31 , V_624 , V_623 . V_588 ) ) {
V_274 = - V_589 ;
goto V_285;
}
}
V_285:
F_130 ( V_8 , V_10 ) ;
V_627:
F_69 ( V_624 ) ;
return V_274 ;
}
static int F_231 ( struct V_1 * V_8 , void T_7 * V_611 )
{
T_11 * V_630 ;
struct V_9 * V_10 ;
unsigned char * * V_624 = NULL ;
int * V_631 = NULL ;
T_5 V_185 ;
T_13 V_264 = 0 ;
int V_33 = 0 ;
int V_51 ;
T_3 V_632 ;
T_3 V_633 ;
T_13 T_7 * V_634 ;
if ( ! V_611 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_625 ;
V_630 = ( T_11 * )
F_80 ( sizeof( * V_630 ) , V_154 ) ;
if ( ! V_630 ) {
V_33 = - V_180 ;
goto V_635;
}
if ( F_218 ( V_630 , V_611 , sizeof( * V_630 ) ) ) {
V_33 = - V_589 ;
goto V_635;
}
if ( ( V_630 -> V_588 < 1 ) &&
( V_630 -> V_106 . Type . V_626 != V_508 ) ) {
V_33 = - V_40 ;
goto V_635;
}
if ( V_630 -> V_591 > V_636 ) {
V_33 = - V_40 ;
goto V_635;
}
if ( V_630 -> V_588 > V_630 -> V_591 * V_637 ) {
V_33 = - V_40 ;
goto V_635;
}
V_624 = F_83 ( V_637 * sizeof( char * ) , V_154 ) ;
if ( ! V_624 ) {
V_33 = - V_180 ;
goto V_635;
}
V_631 = F_80 ( V_637 * sizeof( int ) , V_154 ) ;
if ( ! V_631 ) {
V_33 = - V_180 ;
goto V_635;
}
V_632 = V_630 -> V_588 ;
V_634 = V_630 -> V_31 ;
while ( V_632 ) {
V_633 = ( V_632 > V_630 -> V_591 ) ? V_630 -> V_591 : V_632 ;
V_631 [ V_264 ] = V_633 ;
V_624 [ V_264 ] = F_80 ( V_633 , V_154 ) ;
if ( V_624 [ V_264 ] == NULL ) {
V_33 = - V_180 ;
goto V_635;
}
if ( V_630 -> V_106 . Type . V_626 & V_506 ) {
if ( F_218 ( V_624 [ V_264 ] , V_634 , V_633 ) ) {
V_33 = - V_589 ;
goto V_635;
}
} else
memset ( V_624 [ V_264 ] , 0 , V_633 ) ;
V_632 -= V_633 ;
V_634 += V_633 ;
V_264 ++ ;
}
V_10 = F_128 ( V_8 ) ;
if ( V_10 == NULL ) {
V_33 = - V_180 ;
goto V_635;
}
V_10 -> V_112 = V_628 ;
V_10 -> V_88 . V_91 = 0 ;
V_10 -> V_88 . V_89 = ( T_4 ) V_264 ;
V_10 -> V_88 . V_191 = F_114 ( V_264 ) ;
memcpy ( & V_10 -> V_88 . V_243 , & V_630 -> V_586 , sizeof( V_10 -> V_88 . V_243 ) ) ;
V_10 -> V_88 . V_242 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_630 -> V_106 , sizeof( V_10 -> V_106 ) ) ;
if ( V_630 -> V_588 > 0 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_264 ; V_51 ++ ) {
V_185 = F_97 ( V_8 -> V_15 , V_624 [ V_51 ] ,
V_631 [ V_51 ] , V_629 ) ;
if ( F_98 ( & V_8 -> V_15 -> V_16 ,
( V_266 ) V_185 ) ) {
V_10 -> V_187 [ V_51 ] . V_194 = F_99 ( 0 ) ;
V_10 -> V_187 [ V_51 ] . V_192 = F_96 ( 0 ) ;
F_112 ( V_8 -> V_15 , V_10 , V_51 ,
V_629 ) ;
V_33 = - V_180 ;
goto V_638;
}
V_10 -> V_187 [ V_51 ] . V_194 = F_99 ( V_185 ) ;
V_10 -> V_187 [ V_51 ] . V_192 = F_96 ( V_631 [ V_51 ] ) ;
V_10 -> V_187 [ V_51 ] . V_189 = F_96 ( 0 ) ;
}
V_10 -> V_187 [ -- V_51 ] . V_189 = F_96 ( V_270 ) ;
}
F_122 ( V_8 , V_10 ) ;
if ( V_264 )
F_112 ( V_8 -> V_15 , V_10 , V_264 , V_629 ) ;
F_230 ( V_8 , V_10 ) ;
memcpy ( & V_630 -> V_587 , V_10 -> V_11 , sizeof( V_630 -> V_587 ) ) ;
if ( F_221 ( V_611 , V_630 , sizeof( * V_630 ) ) ) {
V_33 = - V_589 ;
goto V_638;
}
if ( ( V_630 -> V_106 . Type . V_626 & V_507 ) && V_630 -> V_588 > 0 ) {
T_13 T_7 * V_639 = V_630 -> V_31 ;
for ( V_51 = 0 ; V_51 < V_264 ; V_51 ++ ) {
if ( F_221 ( V_639 , V_624 [ V_51 ] , V_631 [ V_51 ] ) ) {
V_33 = - V_589 ;
goto V_638;
}
V_639 += V_631 [ V_51 ] ;
}
}
V_33 = 0 ;
V_638:
F_130 ( V_8 , V_10 ) ;
V_635:
if ( V_624 ) {
for ( V_51 = 0 ; V_51 < V_264 ; V_51 ++ )
F_69 ( V_624 [ V_51 ] ) ;
F_69 ( V_624 ) ;
}
F_69 ( V_631 ) ;
F_69 ( V_630 ) ;
return V_33 ;
}
static void F_230 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 != V_206 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_232 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_26 ( & V_8 -> V_640 , V_59 ) ;
if ( V_8 -> V_641 >= V_642 ) {
F_27 ( & V_8 -> V_640 , V_59 ) ;
return - 1 ;
}
V_8 -> V_641 ++ ;
F_27 ( & V_8 -> V_640 , V_59 ) ;
return 0 ;
}
static void F_233 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_26 ( & V_8 -> V_640 , V_59 ) ;
if ( V_8 -> V_641 <= 0 ) {
F_27 ( & V_8 -> V_640 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_197 ) ;
return;
}
V_8 -> V_641 -- ;
F_27 ( & V_8 -> V_640 , V_59 ) ;
}
static int F_222 ( struct V_2 * V_16 , int V_196 , void T_7 * V_581 )
{
struct V_1 * V_8 ;
void T_7 * V_611 = ( void T_7 * ) V_581 ;
int V_274 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_196 ) {
case V_603 :
case V_604 :
case V_605 :
F_12 ( V_8 -> V_44 ) ;
return 0 ;
case V_593 :
return F_226 ( V_8 , V_611 ) ;
case V_601 :
return F_228 ( V_8 , V_611 ) ;
case V_590 :
if ( F_232 ( V_8 ) )
return - V_643 ;
V_274 = F_229 ( V_8 , V_611 ) ;
F_233 ( V_8 ) ;
return V_274 ;
case V_592 :
if ( F_232 ( V_8 ) )
return - V_643 ;
V_274 = F_231 ( V_8 , V_611 ) ;
F_233 ( V_8 ) ;
return V_274 ;
default:
return - V_644 ;
}
}
static int F_234 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_289 )
{
struct V_9 * V_10 ;
V_10 = F_151 ( V_8 ) ;
if ( ! V_10 )
return - V_180 ;
( void ) F_129 ( V_10 , V_290 , V_8 , NULL , 0 , 0 ,
V_117 , V_291 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_289 ;
V_10 -> V_272 = NULL ;
F_47 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_129 ( struct V_9 * V_10 , T_4 V_196 , struct V_1 * V_8 ,
void * V_624 , T_2 V_333 , T_6 V_645 , unsigned char * V_54 ,
int V_112 )
{
int V_646 = V_508 ;
struct V_9 * V_74 ;
T_3 V_647 , V_648 ;
V_10 -> V_112 = V_628 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_624 != NULL && V_333 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = F_114 ( 1 ) ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = F_114 ( 0 ) ;
}
V_10 -> V_88 . V_242 = V_10 -> V_86 ;
memcpy ( V_10 -> V_88 . V_243 . V_244 , V_54 , 8 ) ;
if ( V_112 == V_284 ) {
switch ( V_196 ) {
case V_283 :
if ( V_645 & V_292 ) {
V_10 -> V_106 . V_107 [ 1 ] = 0x01 ;
V_10 -> V_106 . V_107 [ 2 ] = ( V_645 & 0xff ) ;
}
V_10 -> V_106 . V_239 = 6 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_507 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_283 ;
V_10 -> V_106 . V_107 [ 4 ] = V_333 & 0xFF ;
break;
case V_330 :
case V_331 :
V_10 -> V_106 . V_239 = 12 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_507 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_196 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_333 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_333 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_333 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_333 & 0xFF ;
break;
case V_649 :
V_10 -> V_106 . V_239 = 12 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 ,
V_505 , V_506 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_104 ;
V_10 -> V_106 . V_107 [ 6 ] = V_650 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_333 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_333 & 0xFF ;
break;
case V_340 :
V_10 -> V_106 . V_239 = 6 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_508 ) ;
V_10 -> V_106 . V_503 = 0 ;
break;
case V_319 :
V_10 -> V_106 . V_239 = 12 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_507 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_651 ;
V_10 -> V_106 . V_107 [ 1 ] = V_196 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_333 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_333 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_333 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_333 & 0xFF ;
break;
case V_288 :
V_10 -> V_106 . V_239 = 10 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_507 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_652 ;
V_10 -> V_106 . V_107 [ 6 ] = V_288 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_333 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_333 >> 8 ) & 0xFF ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_198 , V_196 ) ;
F_166 () ;
return - 1 ;
}
} else if ( V_112 == V_291 ) {
switch ( V_196 ) {
case V_290 :
V_10 -> V_106 . V_239 = 16 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 , V_505 , V_508 ) ;
V_10 -> V_106 . V_503 = 0 ;
memset ( & V_10 -> V_106 . V_107 [ 0 ] , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_107 [ 0 ] = V_196 ;
V_10 -> V_106 . V_107 [ 1 ] = V_543 ;
V_10 -> V_106 . V_107 [ 4 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 5 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 6 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 7 ] = 0x00 ;
break;
case V_551 :
V_74 = V_624 ;
F_202 ( & V_8 -> V_15 -> V_16 , L_199 ,
V_74 -> V_88 . V_242 , V_10 -> V_88 . V_242 ) ;
V_648 = ( T_3 ) ( V_74 -> V_88 . V_242 >> 32 ) ;
V_647 = ( T_3 ) ( V_74 -> V_88 . V_242 & 0x0ffffffffULL ) ;
V_10 -> V_106 . V_239 = 16 ;
V_10 -> V_106 . V_504 =
F_185 ( V_112 ,
V_505 , V_506 ) ;
V_10 -> V_106 . V_503 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_653 ;
V_10 -> V_106 . V_107 [ 1 ] = V_654 ;
V_10 -> V_106 . V_107 [ 2 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 3 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 4 ] = V_648 & 0xFF ;
V_10 -> V_106 . V_107 [ 5 ] = ( V_648 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_648 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_648 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_647 & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = ( V_647 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 10 ] = ( V_647 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 11 ] = ( V_647 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 12 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 13 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 14 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 15 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_200 ,
V_196 ) ;
F_166 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_201 , V_112 ) ;
F_166 () ;
}
switch ( F_235 ( V_10 -> V_106 . V_504 ) ) {
case V_507 :
V_646 = V_286 ;
break;
case V_506 :
V_646 = V_193 ;
break;
case V_508 :
V_646 = V_269 ;
break;
default:
V_646 = V_629 ;
}
if ( F_113 ( V_8 -> V_15 , V_10 , V_624 , V_333 , V_646 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_236 ( T_15 V_655 , T_15 V_333 )
{
T_15 V_656 = ( ( T_15 ) V_655 ) & V_657 ;
T_15 V_658 = ( ( T_15 ) V_655 ) - V_656 ;
void T_14 * V_659 = F_237 ( V_656 ,
V_658 + V_333 ) ;
return V_659 ? ( V_659 + V_658 ) : NULL ;
}
static void F_48 ( struct V_1 * V_8 , unsigned long * V_59 )
{
struct V_9 * V_10 ;
while ( ! F_51 ( & V_8 -> V_115 ) ) {
V_10 = F_238 ( V_8 -> V_115 . V_660 , struct V_9 , V_72 ) ;
if ( ( V_8 -> V_79 . V_661 ( V_8 ) ) ) {
V_8 -> V_662 = 1 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_202 ) ;
break;
}
V_8 -> V_662 = 0 ;
F_49 ( V_10 ) ;
V_8 -> V_116 -- ;
F_31 ( & V_8 -> V_558 , V_10 ) ;
F_44 ( & V_8 -> V_47 ) ;
F_27 ( & V_8 -> V_60 , * V_59 ) ;
V_8 -> V_79 . V_663 ( V_8 , V_10 ) ;
F_26 ( & V_8 -> V_60 , * V_59 ) ;
}
}
static void F_239 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_48 ( V_8 , & V_59 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static inline unsigned long F_240 ( struct V_1 * V_8 , T_4 V_73 )
{
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
}
static inline bool F_241 ( struct V_1 * V_8 )
{
return V_8 -> V_79 . V_664 ( V_8 ) ;
}
static inline long F_242 ( struct V_1 * V_8 )
{
return ( V_8 -> V_79 . V_664 ( V_8 ) == 0 ) ||
( V_8 -> V_665 == 0 ) ;
}
static inline int F_243 ( struct V_1 * V_8 , T_3 V_666 ,
T_3 V_667 )
{
if ( F_34 ( V_666 >= V_8 -> V_178 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_203 , V_667 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_209 ( struct V_9 * V_10 )
{
unsigned long V_59 ;
int V_668 = 0 ;
struct V_1 * V_8 = V_10 -> V_8 ;
int V_32 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_49 ( V_10 ) ;
V_32 = F_15 ( & V_8 -> V_47 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( F_34 ( V_8 -> V_662 ) && V_32 < 5 )
V_668 = 1 ;
F_45 ( V_10 -> V_8 , V_10 ) ;
if ( F_37 ( V_10 -> V_112 == V_113 || V_10 -> V_112 == V_234
|| V_10 -> V_112 == V_114 ) )
F_108 ( V_10 ) ;
else if ( V_10 -> V_112 == V_628 )
F_244 ( V_10 -> V_272 ) ;
if ( F_34 ( V_668 ) )
F_239 ( V_8 ) ;
}
static inline T_3 F_245 ( T_3 V_242 )
{
return V_242 & V_461 ;
}
static inline T_3 F_246 ( T_3 V_242 )
{
return V_242 >> V_460 ;
}
static inline T_3 F_247 ( struct V_1 * V_8 , T_3 V_242 )
{
#define F_248 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_249 0x03
if ( F_34 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_242 & ~ F_249 ;
return V_242 & ~ F_248 ;
}
static inline void F_250 ( struct V_1 * V_8 ,
T_3 V_667 )
{
T_3 V_666 ;
struct V_9 * V_10 ;
V_666 = F_246 ( V_667 ) ;
if ( ! F_243 ( V_8 , V_666 , V_667 ) ) {
V_10 = V_8 -> V_574 + V_666 ;
F_209 ( V_10 ) ;
}
}
static inline void F_251 ( struct V_1 * V_8 ,
T_3 V_667 )
{
T_3 V_242 ;
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
V_242 = F_247 ( V_8 , V_667 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_79 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_86 & 0xFFFFFFE0 ) == ( V_242 & 0xFFFFFFE0 ) ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_209 ( V_10 ) ;
return;
}
}
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_243 ( V_8 , V_8 -> V_178 + 1 , V_667 ) ;
}
static int F_252 ( struct V_1 * V_8 )
{
if ( F_37 ( ! V_669 ) )
return 0 ;
if ( F_37 ( V_8 -> V_665 ) )
return 0 ;
F_62 ( & V_8 -> V_15 -> V_16 , L_204
L_205 ) ;
return 1 ;
}
static struct V_1 * F_253 ( T_4 * V_670 )
{
return F_254 ( ( V_670 - * V_670 ) , struct V_1 , V_73 [ 0 ] ) ;
}
static T_16 F_255 ( int V_529 , void * V_670 )
{
struct V_1 * V_8 = F_253 ( V_670 ) ;
T_4 V_73 = * ( T_4 * ) V_670 ;
T_3 V_667 ;
if ( F_252 ( V_8 ) )
return V_671 ;
if ( F_242 ( V_8 ) )
return V_671 ;
V_8 -> V_672 = F_256 () ;
while ( F_241 ( V_8 ) ) {
V_667 = F_240 ( V_8 , V_73 ) ;
while ( V_667 != V_84 )
V_667 = F_33 ( V_8 , V_73 ) ;
}
return V_673 ;
}
static T_16 F_257 ( int V_529 , void * V_670 )
{
struct V_1 * V_8 = F_253 ( V_670 ) ;
T_3 V_667 ;
T_4 V_73 = * ( T_4 * ) V_670 ;
if ( F_252 ( V_8 ) )
return V_671 ;
V_8 -> V_672 = F_256 () ;
V_667 = F_240 ( V_8 , V_73 ) ;
while ( V_667 != V_84 )
V_667 = F_33 ( V_8 , V_73 ) ;
return V_673 ;
}
static T_16 F_258 ( int V_529 , void * V_670 )
{
struct V_1 * V_8 = F_253 ( ( T_4 * ) V_670 ) ;
T_3 V_667 ;
T_4 V_73 = * ( T_4 * ) V_670 ;
if ( F_242 ( V_8 ) )
return V_671 ;
V_8 -> V_672 = F_256 () ;
while ( F_241 ( V_8 ) ) {
V_667 = F_240 ( V_8 , V_73 ) ;
while ( V_667 != V_84 ) {
if ( F_37 ( F_245 ( V_667 ) ) )
F_250 ( V_8 , V_667 ) ;
else
F_251 ( V_8 , V_667 ) ;
V_667 = F_33 ( V_8 , V_73 ) ;
}
}
return V_673 ;
}
static T_16 F_259 ( int V_529 , void * V_670 )
{
struct V_1 * V_8 = F_253 ( V_670 ) ;
T_3 V_667 ;
T_4 V_73 = * ( T_4 * ) V_670 ;
V_8 -> V_672 = F_256 () ;
V_667 = F_240 ( V_8 , V_73 ) ;
while ( V_667 != V_84 ) {
if ( F_37 ( F_245 ( V_667 ) ) )
F_250 ( V_8 , V_667 ) ;
else
F_251 ( V_8 , V_667 ) ;
V_667 = F_33 ( V_8 , V_73 ) ;
}
return V_673 ;
}
static int F_260 ( struct V_263 * V_15 , unsigned char V_674 ,
unsigned char type )
{
struct V_675 {
struct V_676 V_677 ;
struct V_678 V_106 ;
struct V_679 V_680 ;
};
struct V_675 * V_196 ;
static const T_2 V_681 = sizeof( * V_196 ) +
sizeof( V_196 -> V_680 ) ;
V_266 V_682 ;
T_17 V_683 , V_242 ;
void T_14 * V_684 ;
int V_51 , V_585 ;
V_684 = F_261 ( V_15 , 0 ) ;
if ( V_684 == NULL )
return - V_180 ;
V_585 = F_262 ( V_15 , F_263 ( 32 ) ) ;
if ( V_585 ) {
F_264 ( V_684 ) ;
return - V_180 ;
}
V_196 = F_265 ( V_15 , V_681 , & V_682 ) ;
if ( V_196 == NULL ) {
F_264 ( V_684 ) ;
return - V_180 ;
}
V_683 = V_682 ;
V_196 -> V_677 . V_91 = 0 ;
V_196 -> V_677 . V_89 = 0 ;
V_196 -> V_677 . V_191 = F_114 ( 0 ) ;
V_196 -> V_677 . V_242 = V_683 ;
memset ( & V_196 -> V_677 . V_243 . V_244 , 0 , 8 ) ;
V_196 -> V_106 . V_239 = 16 ;
V_196 -> V_106 . V_504 =
F_185 ( V_291 , V_685 , V_508 ) ;
V_196 -> V_106 . V_503 = 0 ;
V_196 -> V_106 . V_107 [ 0 ] = V_674 ;
V_196 -> V_106 . V_107 [ 1 ] = type ;
memset ( & V_196 -> V_106 . V_107 [ 2 ] , 0 , 14 ) ;
V_196 -> V_680 . V_194 =
F_99 ( ( V_683 + sizeof( * V_196 ) ) ) ;
V_196 -> V_680 . V_192 = F_96 ( sizeof( struct V_227 ) ) ;
F_266 ( V_683 , V_684 + V_686 ) ;
for ( V_51 = 0 ; V_51 < V_687 ; V_51 ++ ) {
V_242 = F_267 ( V_684 + V_688 ) ;
if ( ( V_242 & ~ F_249 ) == V_683 )
break;
F_124 ( V_689 ) ;
}
F_264 ( V_684 ) ;
if ( V_51 == V_687 ) {
F_61 ( & V_15 -> V_16 , L_206 ,
V_674 , type ) ;
return - V_690 ;
}
F_214 ( V_15 , V_681 , V_196 , V_682 ) ;
if ( V_242 & V_691 ) {
F_61 ( & V_15 -> V_16 , L_207 ,
V_674 , type ) ;
return - V_692 ;
}
F_62 ( & V_15 -> V_16 , L_208 ,
V_674 , type ) ;
return 0 ;
}
static int F_268 ( struct V_263 * V_15 ,
void T_14 * V_684 , T_3 V_693 )
{
T_6 V_694 ;
int V_695 ;
if ( V_693 ) {
F_62 ( & V_15 -> V_16 , L_209 ) ;
F_266 ( V_693 , V_684 + V_696 ) ;
F_124 ( 10000 ) ;
} else {
V_695 = F_269 ( V_15 , V_697 ) ;
if ( V_695 == 0 ) {
F_61 ( & V_15 -> V_16 ,
L_210
L_211 ) ;
return - V_62 ;
}
F_62 ( & V_15 -> V_16 , L_212 ) ;
F_270 ( V_15 , V_695 + V_698 , & V_694 ) ;
V_694 &= ~ V_699 ;
V_694 |= V_700 ;
F_271 ( V_15 , V_695 + V_698 , V_694 ) ;
F_124 ( 500 ) ;
V_694 &= ~ V_699 ;
V_694 |= V_701 ;
F_271 ( V_15 , V_695 + V_698 , V_694 ) ;
F_124 ( 500 ) ;
}
return 0 ;
}
static void F_272 ( char * V_702 , int V_34 )
{
memset ( V_702 , 0 , V_34 ) ;
strncpy ( V_702 , V_17 L_213 V_622 , V_34 - 1 ) ;
}
static int F_273 ( struct V_703 T_14 * V_704 )
{
char * V_702 ;
int V_51 , V_333 = sizeof( V_704 -> V_702 ) ;
V_702 = F_80 ( V_333 , V_154 ) ;
if ( ! V_702 )
return - V_180 ;
F_272 ( V_702 , V_333 ) ;
for ( V_51 = 0 ; V_51 < V_333 ; V_51 ++ )
F_274 ( V_702 [ V_51 ] , & V_704 -> V_702 [ V_51 ] ) ;
F_69 ( V_702 ) ;
return 0 ;
}
static void F_275 ( struct V_703 T_14 * V_704 ,
unsigned char * V_705 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < sizeof( V_704 -> V_702 ) ; V_51 ++ )
V_705 [ V_51 ] = F_276 ( & V_704 -> V_702 [ V_51 ] ) ;
}
static int F_277 ( struct V_703 T_14 * V_704 )
{
char * V_705 , * V_706 ;
int V_274 , V_333 = sizeof( V_704 -> V_702 ) ;
V_706 = F_80 ( 2 * V_333 , V_154 ) ;
if ( ! V_706 )
return - V_180 ;
V_705 = V_706 + V_333 ;
F_272 ( V_706 , V_333 ) ;
F_275 ( V_704 , V_705 ) ;
V_274 = ! memcmp ( V_705 , V_706 , V_333 ) ;
F_69 ( V_706 ) ;
return V_274 ;
}
static int F_278 ( struct V_263 * V_15 )
{
T_5 V_707 ;
T_3 V_708 ;
T_5 V_709 ;
void T_14 * V_684 ;
unsigned long V_710 ;
T_3 V_711 ;
int V_274 ;
struct V_703 T_14 * V_704 ;
T_3 V_693 ;
T_3 V_50 ;
T_6 V_712 ;
V_274 = F_279 ( V_15 , & V_50 ) ;
if ( V_274 < 0 || ! F_21 ( V_50 ) ) {
F_5 ( & V_15 -> V_16 , L_214 ) ;
return - V_62 ;
}
if ( ! F_18 ( V_50 ) )
return - V_713 ;
F_270 ( V_15 , 4 , & V_712 ) ;
F_280 ( V_15 ) ;
V_274 = F_281 ( V_15 , & V_710 ) ;
if ( V_274 )
return V_274 ;
V_684 = F_236 ( V_710 , 0x250 ) ;
if ( ! V_684 )
return - V_180 ;
V_274 = F_282 ( V_15 , V_684 , & V_708 ,
& V_709 , & V_707 ) ;
if ( V_274 )
goto V_714;
V_704 = F_236 ( F_283 ( V_15 ,
V_709 ) + V_707 , sizeof( * V_704 ) ) ;
if ( ! V_704 ) {
V_274 = - V_180 ;
goto V_714;
}
V_274 = F_273 ( V_704 ) ;
if ( V_274 )
goto V_714;
V_711 = F_267 ( & V_704 -> V_711 ) ;
V_693 = V_711 & V_715 ;
if ( V_693 ) {
V_693 = V_716 ;
} else {
V_693 = V_711 & V_717 ;
if ( V_693 ) {
F_5 ( & V_15 -> V_16 , L_215
L_216 ) ;
V_274 = - V_713 ;
goto V_718;
}
}
V_274 = F_268 ( V_15 , V_684 , V_693 ) ;
if ( V_274 )
goto V_718;
F_284 ( V_15 ) ;
F_271 ( V_15 , 4 , V_712 ) ;
F_124 ( V_719 ) ;
V_274 = F_285 ( V_15 , V_684 , V_720 ) ;
if ( V_274 ) {
F_5 ( & V_15 -> V_16 ,
L_217
L_218 ) ;
goto V_718;
}
V_274 = F_277 ( V_684 ) ;
if ( V_274 < 0 )
goto V_718;
if ( V_274 ) {
F_5 ( & V_15 -> V_16 , L_219
L_220 ) ;
V_274 = - V_713 ;
} else {
F_62 ( & V_15 -> V_16 , L_221 ) ;
}
V_718:
F_264 ( V_704 ) ;
V_714:
F_264 ( V_684 ) ;
return V_274 ;
}
static void F_286 ( struct V_28 * V_16 , struct V_703 T_14 * V_721 )
{
#ifdef F_287
int V_51 ;
char V_722 [ 17 ] ;
F_62 ( V_16 , L_222 ) ;
F_62 ( V_16 , L_223 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
V_722 [ V_51 ] = F_276 ( & ( V_721 -> V_723 [ V_51 ] ) ) ;
V_722 [ 4 ] = '\0' ;
F_62 ( V_16 , L_224 , V_722 ) ;
F_62 ( V_16 , L_225 , F_267 ( & ( V_721 -> V_724 ) ) ) ;
F_62 ( V_16 , L_226 ,
F_267 ( & ( V_721 -> V_725 ) ) ) ;
F_62 ( V_16 , L_227 ,
F_267 ( & ( V_721 -> V_726 ) ) ) ;
F_62 ( V_16 , L_228 ,
F_267 ( & ( V_721 -> V_727 . V_728 ) ) ) ;
F_62 ( V_16 , L_229 ,
F_267 ( & ( V_721 -> V_727 . V_729 ) ) ) ;
F_62 ( V_16 , L_230 ,
F_267 ( & ( V_721 -> V_727 . V_730 ) ) ) ;
F_62 ( V_16 , L_231 ,
F_267 ( & ( V_721 -> V_731 ) ) ) ;
F_62 ( V_16 , L_232 , F_267 ( & ( V_721 -> V_732 ) ) ) ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_722 [ V_51 ] = F_276 ( & ( V_721 -> V_733 [ V_51 ] ) ) ;
V_722 [ 16 ] = '\0' ;
F_62 ( V_16 , L_233 , V_722 ) ;
F_62 ( V_16 , L_234 ,
F_267 ( & ( V_721 -> V_734 ) ) ) ;
#endif
}
static int F_288 ( struct V_263 * V_15 , unsigned long V_735 )
{
int V_51 , V_736 , V_737 , V_738 ;
if ( V_735 == V_739 )
return 0 ;
V_736 = 0 ;
for ( V_51 = 0 ; V_51 < V_740 ; V_51 ++ ) {
V_738 = F_289 ( V_15 , V_51 ) & V_741 ;
if ( V_738 == V_742 )
V_736 += 4 ;
else {
V_737 = F_289 ( V_15 , V_51 ) &
V_743 ;
switch ( V_737 ) {
case V_744 :
case V_745 :
V_736 += 4 ;
break;
case V_746 :
V_736 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_235 ) ;
return - 1 ;
break;
}
}
if ( V_736 == V_735 - V_739 )
return V_51 + 1 ;
}
return - 1 ;
}
static void F_290 ( struct V_1 * V_8 )
{
#ifdef F_291
int V_585 , V_51 ;
struct V_747 V_748 [ V_749 ] ;
for ( V_51 = 0 ; V_51 < V_749 ; V_51 ++ ) {
V_748 [ V_51 ] . V_750 = 0 ;
V_748 [ V_51 ] . V_134 = V_51 ;
}
if ( ( V_8 -> V_50 == 0x40700E11 ) || ( V_8 -> V_50 == 0x40800E11 ) ||
( V_8 -> V_50 == 0x40820E11 ) || ( V_8 -> V_50 == 0x40830E11 ) )
goto V_751;
if ( F_269 ( V_8 -> V_15 , V_752 ) ) {
F_62 ( & V_8 -> V_15 -> V_16 , L_236 ) ;
V_8 -> V_90 = V_749 ;
if ( V_8 -> V_90 > F_292 () )
V_8 -> V_90 = F_292 () ;
V_585 = F_293 ( V_8 -> V_15 , V_748 ,
1 , V_8 -> V_90 ) ;
if ( V_585 < 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_237 , V_585 ) ;
V_8 -> V_90 = 0 ;
goto V_753;
} else if ( V_585 < V_8 -> V_90 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_238
L_239 , V_585 ) ;
}
V_8 -> V_90 = V_585 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_8 -> V_530 [ V_51 ] = V_748 [ V_51 ] . V_750 ;
return;
}
V_753:
if ( F_269 ( V_8 -> V_15 , V_754 ) ) {
F_62 ( & V_8 -> V_15 -> V_16 , L_240 ) ;
if ( ! F_294 ( V_8 -> V_15 ) )
V_8 -> V_755 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_241 ) ;
}
V_751:
#endif
V_8 -> V_530 [ V_8 -> V_531 ] = V_8 -> V_15 -> V_529 ;
}
static int F_279 ( struct V_263 * V_15 , T_3 * V_50 )
{
int V_51 ;
T_3 V_756 , V_757 ;
V_756 = V_15 -> V_758 ;
V_757 = V_15 -> V_759 ;
* V_50 = ( ( V_757 << 16 ) & 0xffff0000 ) |
V_756 ;
for ( V_51 = 0 ; V_51 < F_19 ( V_760 ) ; V_51 ++ )
if ( * V_50 == V_760 [ V_51 ] . V_50 )
return V_51 ;
if ( ( V_756 != V_761 &&
V_756 != V_762 ) ||
! V_763 ) {
F_5 ( & V_15 -> V_16 , L_242
L_243 , * V_50 ) ;
return - V_62 ;
}
return F_19 ( V_760 ) - 1 ;
}
static int F_281 ( struct V_263 * V_15 ,
unsigned long * V_764 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_740 ; V_51 ++ )
if ( F_289 ( V_15 , V_51 ) & V_765 ) {
* V_764 = F_283 ( V_15 , V_51 ) ;
F_202 ( & V_15 -> V_16 , L_244 ,
* V_764 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_245 ) ;
return - V_62 ;
}
static int F_285 ( struct V_263 * V_15 , void T_14 * V_684 ,
int V_766 )
{
int V_51 , V_767 ;
T_3 V_768 ;
if ( V_766 )
V_767 = V_769 ;
else
V_767 = V_770 ;
for ( V_51 = 0 ; V_51 < V_767 ; V_51 ++ ) {
V_768 = F_267 ( V_684 + V_771 ) ;
if ( V_766 ) {
if ( V_768 == V_772 )
return 0 ;
} else {
if ( V_768 != V_772 )
return 0 ;
}
F_124 ( V_773 ) ;
}
F_5 ( & V_15 -> V_16 , L_246 ) ;
return - V_62 ;
}
static int F_282 ( struct V_263 * V_15 , void T_14 * V_684 ,
T_3 * V_708 , T_5 * V_709 ,
T_5 * V_707 )
{
* V_708 = F_267 ( V_684 + V_774 ) ;
* V_707 = F_267 ( V_684 + V_775 ) ;
* V_708 &= ( T_3 ) 0x0000ffff ;
* V_709 = F_288 ( V_15 , * V_708 ) ;
if ( * V_709 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_247 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_295 ( struct V_1 * V_8 )
{
T_5 V_707 ;
T_3 V_708 ;
T_5 V_709 ;
T_3 V_776 ;
int V_274 ;
V_274 = F_282 ( V_8 -> V_15 , V_8 -> V_684 , & V_708 ,
& V_709 , & V_707 ) ;
if ( V_274 )
return V_274 ;
V_8 -> V_704 = F_236 ( F_283 ( V_8 -> V_15 ,
V_709 ) + V_707 , sizeof( * V_8 -> V_704 ) ) ;
if ( ! V_8 -> V_704 )
return - V_180 ;
V_274 = F_273 ( V_8 -> V_704 ) ;
if ( V_274 )
return V_274 ;
V_776 = F_267 ( & V_8 -> V_704 -> V_777 ) ;
V_8 -> V_778 = F_236 ( F_283 ( V_8 -> V_15 ,
V_709 ) + V_707 + V_776 ,
sizeof( * V_8 -> V_778 ) ) ;
if ( ! V_8 -> V_778 )
return - V_180 ;
return 0 ;
}
static void F_296 ( struct V_1 * V_8 )
{
V_8 -> V_85 = F_267 ( & ( V_8 -> V_704 -> V_779 ) ) ;
if ( V_669 && V_8 -> V_85 > 32 )
V_8 -> V_85 = 32 ;
if ( V_8 -> V_85 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_248
L_249
L_250 ,
V_8 -> V_85 ) ;
V_8 -> V_85 = 16 ;
}
}
static void F_297 ( struct V_1 * V_8 )
{
F_296 ( V_8 ) ;
V_8 -> V_178 = V_8 -> V_85 - 4 ;
V_8 -> V_407 = F_267 ( & ( V_8 -> V_704 -> V_780 ) ) ;
V_8 -> V_347 = F_267 ( & ( V_8 -> V_704 -> V_711 ) ) ;
V_8 -> V_188 = 31 ;
if ( V_8 -> V_407 > 512 ) {
V_8 -> V_188 = 32 ;
V_8 -> V_179 = V_8 -> V_407 - V_8 -> V_188 ;
V_8 -> V_407 -- ;
} else {
V_8 -> V_179 = 0 ;
V_8 -> V_407 = 31 ;
}
V_8 -> V_564 = F_267 ( & ( V_8 -> V_704 -> V_564 ) ) ;
if ( ! ( V_563 & V_8 -> V_564 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_251 ) ;
if ( ! ( V_565 & V_8 -> V_564 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_252 ) ;
}
static inline bool F_298 ( struct V_1 * V_8 )
{
if ( ! F_299 ( V_8 -> V_704 -> V_723 , L_253 , 4 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_254 ) ;
return false ;
}
return true ;
}
static inline void F_300 ( struct V_1 * V_8 )
{
T_3 V_781 ;
V_781 = F_267 ( & ( V_8 -> V_704 -> V_781 ) ) ;
#ifdef F_301
V_781 |= V_782 ;
#endif
V_781 |= V_783 ;
F_266 ( V_781 , & ( V_8 -> V_704 -> V_781 ) ) ;
}
static inline void F_302 ( struct V_1 * V_8 )
{
T_3 V_784 ;
if ( V_8 -> V_50 != 0x3225103C )
return;
V_784 = F_267 ( V_8 -> V_684 + V_785 ) ;
V_784 |= 0x8000 ;
F_266 ( V_784 , V_8 -> V_684 + V_785 ) ;
}
static void F_303 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_786 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_787 ; V_51 ++ ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_786 = F_267 ( V_8 -> V_684 + V_696 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_786 & V_788 ) )
break;
F_124 ( 20 ) ;
}
}
static void F_304 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_786 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_787 ; V_51 ++ ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_786 = F_267 ( V_8 -> V_684 + V_696 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_786 & V_789 ) )
break;
F_305 ( 10000 , 20000 ) ;
}
}
static int F_306 ( struct V_1 * V_8 )
{
T_3 V_790 ;
V_790 = F_267 ( & ( V_8 -> V_704 -> V_725 ) ) ;
if ( ! ( V_790 & V_791 ) )
return - V_713 ;
V_8 -> V_85 = F_267 ( & ( V_8 -> V_704 -> V_731 ) ) ;
F_266 ( V_792 , & ( V_8 -> V_704 -> V_727 . V_728 ) ) ;
F_266 ( 0 , & V_8 -> V_704 -> V_727 . V_793 ) ;
F_266 ( V_789 , V_8 -> V_684 + V_696 ) ;
F_304 ( V_8 ) ;
F_286 ( & V_8 -> V_15 -> V_16 , V_8 -> V_704 ) ;
if ( ! ( F_267 ( & ( V_8 -> V_704 -> V_726 ) ) & V_792 ) )
goto error;
V_8 -> V_48 = V_792 ;
return 0 ;
error:
F_5 ( & V_8 -> V_15 -> V_16 , L_255 ) ;
return - V_62 ;
}
static int F_307 ( struct V_1 * V_8 )
{
int V_794 , V_585 ;
V_794 = F_279 ( V_8 -> V_15 , & V_8 -> V_50 ) ;
if ( V_794 < 0 )
return - V_62 ;
V_8 -> V_795 = V_760 [ V_794 ] . V_795 ;
V_8 -> V_79 = * ( V_760 [ V_794 ] . V_79 ) ;
F_308 ( V_8 -> V_15 , V_796 |
V_797 | V_798 ) ;
V_585 = F_309 ( V_8 -> V_15 ) ;
if ( V_585 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_256 ) ;
return V_585 ;
}
V_585 = F_310 ( V_8 -> V_15 , V_17 ) ;
if ( V_585 ) {
F_61 ( & V_8 -> V_15 -> V_16 ,
L_257 ) ;
return V_585 ;
}
F_311 ( V_8 -> V_15 ) ;
F_290 ( V_8 ) ;
V_585 = F_281 ( V_8 -> V_15 , & V_8 -> V_710 ) ;
if ( V_585 )
goto V_799;
V_8 -> V_684 = F_236 ( V_8 -> V_710 , 0x250 ) ;
if ( ! V_8 -> V_684 ) {
V_585 = - V_180 ;
goto V_799;
}
V_585 = F_285 ( V_8 -> V_15 , V_8 -> V_684 , V_720 ) ;
if ( V_585 )
goto V_799;
V_585 = F_295 ( V_8 ) ;
if ( V_585 )
goto V_799;
F_297 ( V_8 ) ;
if ( ! F_298 ( V_8 ) ) {
V_585 = - V_62 ;
goto V_799;
}
F_300 ( V_8 ) ;
F_302 ( V_8 ) ;
V_585 = F_306 ( V_8 ) ;
if ( V_585 )
goto V_799;
return 0 ;
V_799:
if ( V_8 -> V_778 )
F_264 ( V_8 -> V_778 ) ;
if ( V_8 -> V_704 )
F_264 ( V_8 -> V_704 ) ;
if ( V_8 -> V_684 )
F_264 ( V_8 -> V_684 ) ;
F_312 ( V_8 -> V_15 ) ;
F_313 ( V_8 -> V_15 ) ;
return V_585 ;
}
static void F_314 ( struct V_1 * V_8 )
{
int V_274 ;
#define F_315 64
V_8 -> V_46 = F_80 ( F_315 , V_154 ) ;
if ( ! V_8 -> V_46 )
return;
V_274 = F_127 ( V_8 , V_117 , 0 ,
V_8 -> V_46 , F_315 ) ;
if ( V_274 != 0 ) {
F_69 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
}
static int F_316 ( struct V_263 * V_15 )
{
int V_274 , V_51 ;
if ( ! V_669 )
return 0 ;
V_274 = F_309 ( V_15 ) ;
if ( V_274 ) {
F_5 ( & V_15 -> V_16 , L_258 ) ;
return - V_62 ;
}
F_312 ( V_15 ) ;
F_124 ( 260 ) ;
V_274 = F_309 ( V_15 ) ;
if ( V_274 ) {
F_5 ( & V_15 -> V_16 , L_259 ) ;
return - V_62 ;
}
F_311 ( V_15 ) ;
V_274 = F_278 ( V_15 ) ;
if ( V_274 ) {
if ( V_274 != - V_713 )
V_274 = - V_62 ;
goto V_800;
}
F_5 ( & V_15 -> V_16 , L_260 ) ;
for ( V_51 = 0 ; V_51 < V_801 ; V_51 ++ ) {
if ( F_317 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_261 ,
( V_51 < 11 ? L_262 : L_263 ) ) ;
}
V_800:
F_312 ( V_15 ) ;
return V_274 ;
}
static int F_318 ( struct V_1 * V_8 )
{
V_8 -> V_573 = F_83 (
F_319 ( V_8 -> V_178 , V_491 ) *
sizeof( unsigned long ) , V_154 ) ;
V_8 -> V_574 = F_265 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_574 ) ,
& ( V_8 -> V_575 ) ) ;
V_8 -> V_576 = F_265 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_576 ) ,
& ( V_8 -> V_577 ) ) ;
if ( ( V_8 -> V_573 == NULL )
|| ( V_8 -> V_574 == NULL )
|| ( V_8 -> V_576 == NULL ) ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_264 , V_155 ) ;
return - V_180 ;
}
return 0 ;
}
static void F_320 ( struct V_1 * V_8 )
{
F_69 ( V_8 -> V_573 ) ;
if ( V_8 -> V_574 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_574 , V_8 -> V_575 ) ;
if ( V_8 -> V_100 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_447 ) ;
if ( V_8 -> V_576 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_227 ) ,
V_8 -> V_576 ,
V_8 -> V_577 ) ;
if ( V_8 -> V_95 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_93 ) ,
V_8 -> V_95 , V_8 -> V_427 ) ;
}
static void F_321 ( struct V_1 * V_8 )
{
int V_51 , V_273 , V_274 ;
V_273 = F_322 ( V_802 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
V_274 = F_323 ( V_8 -> V_530 [ V_51 ] , F_324 ( V_273 ) ) ;
V_273 = F_325 ( V_273 , V_802 ) ;
}
}
static int F_326 ( struct V_1 * V_8 ,
T_16 (* F_327)( int , void * ) ,
T_16 (* F_328)( int , void * ) )
{
int V_274 , V_51 ;
for ( V_51 = 0 ; V_51 < V_749 ; V_51 ++ )
V_8 -> V_73 [ V_51 ] = ( T_4 ) V_51 ;
if ( V_8 -> V_531 == V_803 && V_8 -> V_90 > 0 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_274 = F_329 ( V_8 -> V_530 [ V_51 ] , F_327 ,
0 , V_8 -> V_804 ,
& V_8 -> V_73 [ V_51 ] ) ;
F_321 ( V_8 ) ;
} else {
if ( V_8 -> V_90 > 0 || V_8 -> V_755 ) {
V_274 = F_329 ( V_8 -> V_530 [ V_8 -> V_531 ] ,
F_327 , 0 , V_8 -> V_804 ,
& V_8 -> V_73 [ V_8 -> V_531 ] ) ;
} else {
V_274 = F_329 ( V_8 -> V_530 [ V_8 -> V_531 ] ,
F_328 , V_805 , V_8 -> V_804 ,
& V_8 -> V_73 [ V_8 -> V_531 ] ) ;
}
}
if ( V_274 ) {
F_61 ( & V_8 -> V_15 -> V_16 , L_265 ,
V_8 -> V_530 [ V_8 -> V_531 ] , V_8 -> V_804 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_330 ( struct V_1 * V_8 )
{
if ( F_234 ( V_8 , V_117 ,
V_806 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_266 ) ;
return - V_692 ;
}
F_62 ( & V_8 -> V_15 -> V_16 , L_267 ) ;
if ( F_285 ( V_8 -> V_15 , V_8 -> V_684 , V_807 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_268 ) ;
return - 1 ;
}
F_62 ( & V_8 -> V_15 -> V_16 , L_269 ) ;
if ( F_285 ( V_8 -> V_15 , V_8 -> V_684 , V_720 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_270
L_271 ) ;
return - 1 ;
}
return 0 ;
}
static void F_331 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_90 || V_8 -> V_531 != V_803 ) {
V_51 = V_8 -> V_531 ;
F_323 ( V_8 -> V_530 [ V_51 ] , NULL ) ;
F_332 ( V_8 -> V_530 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
F_323 ( V_8 -> V_530 [ V_51 ] , NULL ) ;
F_332 ( V_8 -> V_530 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
}
}
static void F_333 ( struct V_1 * V_8 )
{
F_331 ( V_8 ) ;
#ifdef F_291
if ( V_8 -> V_90 ) {
if ( V_8 -> V_15 -> V_808 )
F_334 ( V_8 -> V_15 ) ;
} else if ( V_8 -> V_755 ) {
if ( V_8 -> V_15 -> V_809 )
F_335 ( V_8 -> V_15 ) ;
}
#endif
}
static void F_336 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
if ( ! V_8 -> V_77 [ V_51 ] . V_81 )
continue;
F_214 ( V_8 -> V_15 , V_8 -> V_810 ,
V_8 -> V_77 [ V_51 ] . V_81 , V_8 -> V_77 [ V_51 ] . V_86 ) ;
V_8 -> V_77 [ V_51 ] . V_81 = NULL ;
V_8 -> V_77 [ V_51 ] . V_86 = 0 ;
}
}
static void F_337 ( struct V_1 * V_8 )
{
F_333 ( V_8 ) ;
F_93 ( V_8 ) ;
F_320 ( V_8 ) ;
F_69 ( V_8 -> V_97 ) ;
F_69 ( V_8 -> V_87 ) ;
F_336 ( V_8 ) ;
if ( V_8 -> V_684 )
F_264 ( V_8 -> V_684 ) ;
if ( V_8 -> V_778 )
F_264 ( V_8 -> V_778 ) ;
if ( V_8 -> V_704 )
F_264 ( V_8 -> V_704 ) ;
F_312 ( V_8 -> V_15 ) ;
F_313 ( V_8 -> V_15 ) ;
F_69 ( V_8 ) ;
}
static void F_338 ( struct V_1 * V_8 , struct V_71 * V_72 )
{
struct V_9 * V_10 = NULL ;
F_339 ( & V_8 -> V_60 ) ;
while ( ! F_51 ( V_72 ) ) {
V_10 = F_238 ( V_72 -> V_660 , struct V_9 , V_72 ) ;
V_10 -> V_11 -> V_23 = V_254 ;
F_209 ( V_10 ) ;
}
}
static void F_340 ( struct V_1 * V_8 , T_3 V_811 )
{
int V_51 , V_273 ;
V_273 = F_322 ( V_802 ) ;
for ( V_51 = 0 ; V_51 < F_292 () ; V_51 ++ ) {
T_3 * F_118 ;
F_118 = F_120 ( V_8 -> F_118 , V_273 ) ;
* F_118 = V_811 ;
V_273 = F_325 ( V_273 , V_802 ) ;
}
F_341 () ;
}
static void F_342 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
T_3 F_118 ;
V_8 -> V_79 . V_812 ( V_8 , V_813 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_118 = F_267 ( V_8 -> V_684 + V_771 ) ;
if ( ! F_118 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_272 ) ;
F_118 = 0xffffffff ;
}
F_340 ( V_8 , F_118 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_273 ,
F_118 ) ;
F_312 ( V_8 -> V_15 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_338 ( V_8 , & V_8 -> V_558 ) ;
F_338 ( V_8 , & V_8 -> V_115 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_343 ( struct V_1 * V_8 )
{
T_5 V_814 ;
T_3 V_815 ;
unsigned long V_59 ;
V_814 = F_256 () ;
if ( F_344 ( V_8 -> V_672 +
( V_8 -> V_109 ) , V_814 ) )
return;
if ( F_344 ( V_8 -> V_816 +
( V_8 -> V_109 ) , V_814 ) )
return;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_815 = F_267 ( & V_8 -> V_704 -> V_734 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_817 == V_815 ) {
F_342 ( V_8 ) ;
return;
}
V_8 -> V_817 = V_815 ;
V_8 -> V_816 = V_814 ;
}
static void F_345 ( struct V_1 * V_8 )
{
int V_51 ;
char * V_818 ;
V_8 -> V_225 = 0 ;
if ( ( V_8 -> V_48 & ( V_78
| V_380 ) ) &&
( V_8 -> V_819 & V_820 ||
V_8 -> V_819 & V_821 ) ) {
if ( V_8 -> V_819 & V_820 )
V_818 = L_274 ;
if ( V_8 -> V_819 & V_821 )
V_818 = L_275 ;
F_346 ( V_8 -> V_44 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] -> V_70 = 0 ;
F_347 ( V_8 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_276 ,
V_8 -> V_819 , V_818 ) ;
F_266 ( V_8 -> V_819 , & ( V_8 -> V_704 -> V_822 ) ) ;
F_266 ( V_788 , V_8 -> V_684 + V_696 ) ;
F_303 ( V_8 ) ;
F_348 ( V_8 -> V_44 ) ;
} else {
F_266 ( V_8 -> V_819 , & ( V_8 -> V_704 -> V_822 ) ) ;
F_266 ( V_788 , V_8 -> V_684 + V_696 ) ;
F_303 ( V_8 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_349 ( struct V_1 * V_8 )
{
if ( V_8 -> V_225 )
return 1 ;
if ( ! ( V_8 -> V_347 & V_823 ) )
return 0 ;
V_8 -> V_819 = F_267 ( & ( V_8 -> V_704 -> V_824 ) ) ;
return V_8 -> V_819 & V_825 ;
}
static int F_350 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
struct V_152 * V_279 ;
struct V_71 * V_826 , * V_827 ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
F_351 (this, tmp, &h->offline_device_list) {
V_279 = F_238 ( V_826 , struct V_152 ,
V_156 ) ;
F_27 ( & V_8 -> V_153 , V_59 ) ;
if ( ! F_147 ( V_8 , V_279 -> V_54 ) ) {
F_26 ( & V_8 -> V_153 , V_59 ) ;
F_352 ( & V_279 -> V_156 ) ;
F_27 ( & V_8 -> V_153 , V_59 ) ;
return 1 ;
}
F_26 ( & V_8 -> V_153 , V_59 ) ;
}
F_27 ( & V_8 -> V_153 , V_59 ) ;
return 0 ;
}
static void F_353 ( struct V_828 * V_829 )
{
unsigned long V_59 ;
struct V_1 * V_8 = F_254 ( F_354 ( V_829 ) ,
struct V_1 , V_830 ) ;
F_343 ( V_8 ) ;
if ( F_118 ( V_8 ) )
return;
if ( F_349 ( V_8 ) || F_350 ( V_8 ) ) {
F_355 ( V_8 -> V_44 ) ;
V_8 -> V_225 = 0 ;
F_345 ( V_8 ) ;
F_12 ( V_8 -> V_44 ) ;
F_192 ( V_8 -> V_44 ) ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_831 ) {
F_27 ( & V_8 -> V_60 , V_59 ) ;
return;
}
F_356 ( & V_8 -> V_830 ,
V_8 -> V_109 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static int F_357 ( struct V_263 * V_15 , const struct V_832 * V_833 )
{
int V_834 , V_274 ;
struct V_1 * V_8 ;
int V_835 = 0 ;
unsigned long V_59 ;
if ( V_836 == 0 )
F_358 (KERN_INFO DRIVER_NAME L_277 ) ;
V_274 = F_316 ( V_15 ) ;
if ( V_274 ) {
if ( V_274 != - V_713 )
return V_274 ;
V_835 = 1 ;
V_274 = 0 ;
}
V_837:
F_359 ( sizeof( struct V_9 ) % V_838 ) ;
V_8 = F_83 ( sizeof( * V_8 ) , V_154 ) ;
if ( ! V_8 )
return - V_180 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_531 = V_839 ? V_840 : V_803 ;
F_212 ( & V_8 -> V_558 ) ;
F_212 ( & V_8 -> V_115 ) ;
F_212 ( & V_8 -> V_157 ) ;
F_360 ( & V_8 -> V_60 ) ;
F_360 ( & V_8 -> V_153 ) ;
F_360 ( & V_8 -> V_511 ) ;
F_360 ( & V_8 -> V_640 ) ;
V_8 -> F_118 = F_361 ( T_3 ) ;
if ( ! V_8 -> F_118 ) {
V_274 = - V_180 ;
goto V_841;
}
F_340 ( V_8 , 0 ) ;
V_274 = F_307 ( V_8 ) ;
if ( V_274 != 0 )
goto V_841;
sprintf ( V_8 -> V_804 , V_17 L_12 , V_836 ) ;
V_8 -> V_18 = V_836 ;
V_836 ++ ;
V_274 = F_362 ( V_15 , F_263 ( 64 ) ) ;
if ( V_274 == 0 ) {
V_834 = 1 ;
} else {
V_274 = F_362 ( V_15 , F_263 ( 32 ) ) ;
if ( V_274 == 0 ) {
V_834 = 0 ;
} else {
F_61 ( & V_15 -> V_16 , L_278 ) ;
goto V_841;
}
}
V_8 -> V_79 . V_812 ( V_8 , V_813 ) ;
if ( F_326 ( V_8 , F_259 , F_258 ) )
goto V_842;
F_62 ( & V_15 -> V_16 , L_279 ,
V_8 -> V_804 , V_15 -> V_28 ,
V_8 -> V_530 [ V_8 -> V_531 ] , V_834 ? L_263 : L_280 ) ;
if ( F_318 ( V_8 ) )
goto V_843;
if ( F_94 ( V_8 ) )
goto V_843;
F_363 ( & V_8 -> V_513 ) ;
V_8 -> V_512 = 1 ;
F_364 ( V_15 , V_8 ) ;
V_8 -> V_124 = 0 ;
V_8 -> V_388 = 0 ;
V_8 -> V_44 = NULL ;
F_360 ( & V_8 -> V_176 ) ;
F_365 ( V_8 ) ;
if ( V_835 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_79 . V_812 ( V_8 , V_813 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_331 ( V_8 ) ;
V_274 = F_326 ( V_8 , F_257 ,
F_255 ) ;
if ( V_274 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_281
L_282 ) ;
goto V_843;
}
V_274 = F_330 ( V_8 ) ;
if ( V_274 )
goto V_843;
F_62 ( & V_8 -> V_15 -> V_16 , L_283 ) ;
F_62 ( & V_8 -> V_15 -> V_16 ,
L_284 ) ;
V_8 -> V_79 . V_812 ( V_8 , V_844 ) ;
F_124 ( 10000 ) ;
V_8 -> V_79 . V_812 ( V_8 , V_813 ) ;
V_274 = F_277 ( V_8 -> V_704 ) ;
if ( V_274 )
F_62 ( & V_8 -> V_15 -> V_16 ,
L_285 ) ;
F_337 ( V_8 ) ;
V_835 = 0 ;
if ( V_274 )
return - V_62 ;
goto V_837;
}
V_8 -> V_41 = 1 ;
V_8 -> V_225 = 0 ;
V_8 -> V_79 . V_812 ( V_8 , V_844 ) ;
F_314 ( V_8 ) ;
F_193 ( V_8 ) ;
V_8 -> V_109 = V_111 ;
F_366 ( & V_8 -> V_830 , F_353 ) ;
F_356 ( & V_8 -> V_830 ,
V_8 -> V_109 ) ;
return 0 ;
V_843:
F_93 ( V_8 ) ;
F_320 ( V_8 ) ;
F_331 ( V_8 ) ;
V_842:
V_841:
if ( V_8 -> F_118 )
F_367 ( V_8 -> F_118 ) ;
F_69 ( V_8 ) ;
return V_274 ;
}
static void F_368 ( struct V_1 * V_8 )
{
char * V_845 ;
struct V_9 * V_10 ;
if ( F_34 ( F_118 ( V_8 ) ) )
return;
V_845 = F_83 ( 4 , V_154 ) ;
if ( ! V_845 )
return;
V_10 = F_128 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
goto V_846;
}
if ( F_129 ( V_10 , V_649 , V_8 , V_845 , 4 , 0 ,
V_117 , V_284 ) ) {
goto V_285;
}
F_123 ( V_8 , V_10 , V_193 ) ;
if ( V_10 -> V_11 -> V_23 != 0 )
V_285:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_286 ) ;
F_130 ( V_8 , V_10 ) ;
V_846:
F_69 ( V_845 ) ;
}
static void F_369 ( struct V_263 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_370 ( V_15 ) ;
F_368 ( V_8 ) ;
V_8 -> V_79 . V_812 ( V_8 , V_813 ) ;
F_333 ( V_8 ) ;
}
static void F_371 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
F_69 ( V_8 -> V_16 [ V_51 ] ) ;
}
static void F_372 ( struct V_263 * V_15 )
{
struct V_1 * V_8 ;
unsigned long V_59 ;
if ( F_370 ( V_15 ) == NULL ) {
F_61 ( & V_15 -> V_16 , L_287 ) ;
return;
}
V_8 = F_370 ( V_15 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_831 = 1 ;
F_373 ( & V_8 -> V_830 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_190 ( V_8 ) ;
F_369 ( V_15 ) ;
F_264 ( V_8 -> V_684 ) ;
F_264 ( V_8 -> V_778 ) ;
F_264 ( V_8 -> V_704 ) ;
F_371 ( V_8 ) ;
F_93 ( V_8 ) ;
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_574 , V_8 -> V_575 ) ;
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_227 ) ,
V_8 -> V_576 , V_8 -> V_577 ) ;
F_336 ( V_8 ) ;
F_69 ( V_8 -> V_573 ) ;
F_69 ( V_8 -> V_87 ) ;
F_69 ( V_8 -> V_97 ) ;
F_69 ( V_8 -> V_101 ) ;
F_69 ( V_8 -> V_46 ) ;
F_312 ( V_15 ) ;
F_313 ( V_15 ) ;
F_367 ( V_8 -> F_118 ) ;
F_69 ( V_8 ) ;
}
static void F_374 ( int V_847 [] , int V_848 ,
int V_849 , int V_850 , int * V_851 )
{
int V_51 , V_142 , V_852 , V_333 ;
for ( V_51 = 0 ; V_51 <= V_849 ; V_51 ++ ) {
V_333 = V_51 + V_850 ;
V_852 = V_848 ;
for ( V_142 = 0 ; V_142 < V_848 ; V_142 ++ ) {
if ( V_847 [ V_142 ] >= V_333 ) {
V_852 = V_142 ;
break;
}
}
V_851 [ V_51 ] = V_852 ;
}
}
static void F_375 ( struct V_1 * V_8 , T_3 V_790 )
{
int V_51 ;
unsigned long V_853 ;
unsigned long V_48 = V_49 |
( V_790 & V_854 ) |
V_855 |
( V_790 & ( V_78 |
V_380 ) ) ;
struct V_856 V_79 = V_857 ;
int V_858 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_637 + 4 } ;
#define F_376 5
#define F_377 4
int V_859 [ 16 ] = { F_376 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_377 + V_450 } ;
F_359 ( F_19 ( V_859 ) != 16 ) ;
F_359 ( F_19 ( V_858 ) != 8 ) ;
F_359 ( F_180 ( struct V_99 , V_402 ) >
16 * F_376 ) ;
F_359 ( sizeof( struct V_446 ) != 16 ) ;
F_359 ( 28 > V_637 + 4 ) ;
if ( V_790 & ( V_78 | V_380 ) )
V_79 = V_860 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ )
memset ( V_8 -> V_77 [ V_51 ] . V_81 , 0 , V_8 -> V_810 ) ;
V_858 [ 7 ] = V_637 + 4 ;
F_374 ( V_858 , F_19 ( V_858 ) ,
V_637 , 4 , V_8 -> V_87 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
F_266 ( V_858 [ V_51 ] , & V_8 -> V_778 -> V_861 [ V_51 ] ) ;
F_266 ( V_8 -> V_85 , & V_8 -> V_778 -> V_862 ) ;
F_266 ( V_8 -> V_92 , & V_8 -> V_778 -> V_863 ) ;
F_266 ( 0 , & V_8 -> V_778 -> V_864 ) ;
F_266 ( 0 , & V_8 -> V_778 -> V_865 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_266 ( 0 , & V_8 -> V_778 -> V_866 [ V_51 ] . V_867 ) ;
F_266 ( V_8 -> V_77 [ V_51 ] . V_86 ,
& V_8 -> V_778 -> V_866 [ V_51 ] . V_868 ) ;
}
F_266 ( 0 , & V_8 -> V_704 -> V_727 . V_793 ) ;
F_266 ( V_48 , & ( V_8 -> V_704 -> V_727 . V_728 ) ) ;
if ( V_790 & V_78 ) {
V_79 = V_869 ;
F_266 ( 10 , & V_8 -> V_704 -> V_727 . V_729 ) ;
F_266 ( 4 , & V_8 -> V_704 -> V_727 . V_730 ) ;
} else {
if ( V_790 & V_380 ) {
V_79 = V_870 ;
F_266 ( 10 , & V_8 -> V_704 -> V_727 . V_729 ) ;
F_266 ( 4 , & V_8 -> V_704 -> V_727 . V_730 ) ;
}
}
F_266 ( V_789 , V_8 -> V_684 + V_696 ) ;
F_304 ( V_8 ) ;
V_853 = F_267 ( & ( V_8 -> V_704 -> V_726 ) ) ;
if ( ! ( V_853 & V_49 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_288
L_289 ) ;
return;
}
V_8 -> V_79 = V_79 ;
V_8 -> V_48 = V_48 ;
if ( ! ( ( V_790 & V_78 ) ||
( V_790 & V_380 ) ) )
return;
if ( V_790 & V_78 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_266 ( V_51 , V_8 -> V_684 + V_871 ) ;
V_8 -> V_77 [ V_51 ] . V_82 =
F_267 ( V_8 -> V_684 + V_872 ) ;
}
V_858 [ 7 ] = V_8 -> V_424 + 8 ;
F_374 ( V_858 , F_19 ( V_858 ) , V_8 -> V_424 , 8 ,
V_8 -> V_97 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ )
memset ( V_8 -> V_77 [ V_51 ] . V_81 ,
( T_4 ) V_873 ,
V_8 -> V_810 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
struct V_93 * V_94 = & V_8 -> V_95 [ V_51 ] ;
V_94 -> V_874 = V_875 ;
V_94 -> V_11 = ( T_3 ) ( V_8 -> V_577 +
( V_51 * sizeof( struct V_227 ) ) ) ;
V_94 -> V_876 = sizeof( struct V_227 ) ;
V_94 -> V_877 = V_878 ;
V_94 -> V_879 = V_880 ;
V_94 -> V_881 = 0 ;
V_94 -> V_91 = 0 ;
V_94 -> V_242 =
F_99 ( ( V_51 << V_460 ) |
V_461 ) ;
V_94 -> V_882 =
F_99 ( V_8 -> V_427 +
( V_51 * sizeof( struct V_93 ) ) ) ;
}
} else if ( V_790 & V_380 ) {
T_5 V_707 , V_709 ;
T_3 V_883 , V_708 ;
int V_274 ;
V_274 = F_282 ( V_8 -> V_15 , V_8 -> V_684 , & V_708 ,
& V_709 , & V_707 ) ;
F_359 ( F_180 ( struct V_99 , V_402 ) != 64 ) ;
V_859 [ 15 ] = V_8 -> V_424 + F_377 ;
F_374 ( V_859 , F_19 ( V_859 ) , V_8 -> V_424 ,
4 , V_8 -> V_101 ) ;
V_883 = F_267 ( & V_8 -> V_704 -> V_884 ) ;
F_359 ( F_180 ( struct V_703 ,
V_884 ) != 0xb8 ) ;
V_8 -> V_885 =
F_236 ( F_283 ( V_8 -> V_15 ,
V_709 ) +
V_707 + V_883 ,
F_19 ( V_859 ) *
sizeof( * V_8 -> V_885 ) ) ;
for ( V_51 = 0 ; V_51 < F_19 ( V_859 ) ; V_51 ++ )
F_266 ( V_859 [ V_51 ] , & V_8 -> V_885 [ V_51 ] ) ;
}
F_266 ( V_789 , V_8 -> V_684 + V_696 ) ;
F_304 ( V_8 ) ;
}
static int F_378 ( struct V_1 * V_8 )
{
V_8 -> V_424 =
F_267 ( & ( V_8 -> V_704 -> V_886 ) ) ;
if ( V_8 -> V_424 > V_887 )
V_8 -> V_424 = V_887 ;
F_359 ( sizeof( struct V_93 ) %
V_888 ) ;
V_8 -> V_95 =
F_265 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
& ( V_8 -> V_427 ) ) ;
V_8 -> V_97 =
F_80 ( ( ( V_8 -> V_424 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_95 == NULL ) ||
( V_8 -> V_97 == NULL ) )
goto V_889;
memset ( V_8 -> V_95 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ) ;
return 0 ;
V_889:
if ( V_8 -> V_95 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
V_8 -> V_95 , V_8 -> V_427 ) ;
F_69 ( V_8 -> V_97 ) ;
return 1 ;
}
static int F_379 ( struct V_1 * V_8 )
{
V_8 -> V_424 =
F_267 ( & ( V_8 -> V_704 -> V_886 ) ) ;
if ( V_8 -> V_424 > V_450 )
V_8 -> V_424 = V_450 ;
F_359 ( sizeof( struct V_99 ) %
V_890 ) ;
V_8 -> V_100 =
F_265 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
& ( V_8 -> V_447 ) ) ;
V_8 -> V_101 =
F_80 ( ( ( V_8 -> V_424 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_100 == NULL ) ||
( V_8 -> V_101 == NULL ) )
goto V_889;
memset ( V_8 -> V_100 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ) ;
return 0 ;
V_889:
if ( V_8 -> V_100 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_447 ) ;
F_69 ( V_8 -> V_101 ) ;
return 1 ;
}
static void F_365 ( struct V_1 * V_8 )
{
T_3 V_790 ;
unsigned long V_48 = V_49 |
V_854 ;
int V_51 ;
if ( V_839 )
return;
V_790 = F_267 ( & ( V_8 -> V_704 -> V_725 ) ) ;
if ( ! ( V_790 & V_891 ) )
return;
if ( V_790 & V_78 ) {
V_48 |= V_78 |
V_855 ;
if ( F_378 ( V_8 ) )
goto V_889;
} else {
if ( V_790 & V_380 ) {
V_48 |= V_380 |
V_855 ;
if ( F_379 ( V_8 ) )
goto V_889;
}
}
V_8 -> V_92 = V_8 -> V_90 > 0 ? V_8 -> V_90 : 1 ;
F_296 ( V_8 ) ;
V_8 -> V_810 = V_8 -> V_85 * sizeof( T_5 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
V_8 -> V_77 [ V_51 ] . V_81 = F_265 ( V_8 -> V_15 ,
V_8 -> V_810 ,
& ( V_8 -> V_77 [ V_51 ] . V_86 ) ) ;
if ( ! V_8 -> V_77 [ V_51 ] . V_81 )
goto V_889;
V_8 -> V_77 [ V_51 ] . V_333 = V_8 -> V_85 ;
V_8 -> V_77 [ V_51 ] . V_83 = 1 ;
V_8 -> V_77 [ V_51 ] . V_82 = 0 ;
}
V_8 -> V_87 = F_80 ( ( ( V_637 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ! V_8 -> V_87 )
goto V_889;
F_375 ( V_8 , V_790 ) ;
return;
V_889:
F_336 ( V_8 ) ;
F_69 ( V_8 -> V_87 ) ;
}
static int F_380 ( struct V_9 * V_10 )
{
return V_10 -> V_112 == V_113 || V_10 -> V_112 == V_114 ;
}
static void F_347 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
int V_892 ;
do {
V_892 = 0 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_79 (c, &h->cmpQ, list)
V_892 += F_380 ( V_10 ) ;
F_79 (c, &h->reqQ, list)
V_892 += F_380 ( V_10 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( V_892 <= 0 )
break;
F_124 ( 100 ) ;
} while ( 1 );
}
static int T_18 F_381 ( void )
{
return F_382 ( & V_893 ) ;
}
static void T_19 F_383 ( void )
{
F_384 ( & V_893 ) ;
}
