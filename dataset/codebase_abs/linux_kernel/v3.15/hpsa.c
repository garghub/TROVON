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
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_3
L_4 , V_8 -> V_18 ) ;
break;
case V_20 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_5
L_6 , V_8 -> V_18 ) ;
break;
case V_21 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_7
L_8 , V_8 -> V_18 ) ;
break;
case V_22 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_9
L_10 , V_8 -> V_18 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_11
L_12 , V_8 -> V_18 ) ;
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
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_13 ) ;
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
if ( sscanf ( V_36 , L_14 , & V_33 ) != 1 )
return - V_40 ;
V_8 = F_3 ( V_35 ) ;
V_8 -> V_41 = ! ! V_33 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_15 ,
V_8 -> V_41 ? L_16 : L_17 ) ;
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
if ( sscanf ( V_36 , L_14 , & V_42 ) != 1 )
return - V_40 ;
if ( V_42 < 0 )
V_42 = 0 ;
V_8 = F_3 ( V_35 ) ;
V_8 -> V_43 = V_42 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_18 ,
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
return snprintf ( V_31 , 20 , L_19 ,
V_45 [ 0 ] , V_45 [ 1 ] , V_45 [ 2 ] , V_45 [ 3 ] ) ;
}
static T_1 F_14 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_6 * V_35 = F_8 ( V_16 ) ;
struct V_1 * V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_20 , V_8 -> V_47 ) ;
}
static T_1 F_15 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_21 ,
V_8 -> V_48 & V_49 ?
L_22 : L_23 ) ;
}
static T_1 F_16 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 30 , L_24 ,
( V_8 -> V_41 == 1 ) ? L_16 : L_17 ) ;
}
static int F_17 ( T_3 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_18 ( V_52 ) ; V_51 ++ )
if ( V_52 [ V_51 ] == V_50 )
return 0 ;
return 1 ;
}
static int F_19 ( T_3 V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_18 ( V_53 ) ; V_51 ++ )
if ( V_53 [ V_51 ] == V_50 )
return 0 ;
return 1 ;
}
static int F_20 ( T_3 V_50 )
{
return F_17 ( V_50 ) ||
F_19 ( V_50 ) ;
}
static T_1 F_21 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_6 * V_35 = F_8 ( V_16 ) ;
V_8 = F_3 ( V_35 ) ;
return snprintf ( V_31 , 20 , L_20 , F_20 ( V_8 -> V_50 ) ) ;
}
static inline int F_22 ( unsigned char V_54 [] )
{
return ( V_54 [ 3 ] & 0xC0 ) == 0x40 ;
}
static T_1 F_23 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
T_1 V_55 = 0 ;
unsigned char V_56 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
V_3 = F_24 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
if ( ! F_22 ( V_58 -> V_54 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_55 = snprintf ( V_31 , V_63 , L_25 ) ;
return V_55 ;
}
V_56 = V_58 -> V_64 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_56 > V_65 )
V_56 = V_65 ;
V_55 = snprintf ( V_31 , V_63 , L_26 , V_66 [ V_56 ] ) ;
return V_55 ;
}
static T_1 F_27 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
unsigned char V_67 [ 8 ] ;
V_3 = F_24 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
memcpy ( V_67 , V_58 -> V_54 , sizeof( V_67 ) ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 20 , L_27 ,
V_67 [ 0 ] , V_67 [ 1 ] , V_67 [ 2 ] , V_67 [ 3 ] ,
V_67 [ 4 ] , V_67 [ 5 ] , V_67 [ 6 ] , V_67 [ 7 ] ) ;
}
static T_1 F_28 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
unsigned char V_68 [ 16 ] ;
V_3 = F_24 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
memcpy ( V_68 , V_58 -> V_69 , sizeof( V_68 ) ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 16 * 2 + 2 ,
L_28
L_29 ,
V_68 [ 0 ] , V_68 [ 1 ] , V_68 [ 2 ] , V_68 [ 3 ] ,
V_68 [ 4 ] , V_68 [ 5 ] , V_68 [ 6 ] , V_68 [ 7 ] ,
V_68 [ 8 ] , V_68 [ 9 ] , V_68 [ 10 ] , V_68 [ 11 ] ,
V_68 [ 12 ] , V_68 [ 13 ] , V_68 [ 14 ] , V_68 [ 15 ] ) ;
}
static T_1 F_29 ( struct V_28 * V_16 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
int V_70 ;
V_3 = F_24 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_58 = V_3 -> V_61 ;
if ( ! V_58 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return - V_62 ;
}
V_70 = V_58 -> V_70 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
return snprintf ( V_31 , 20 , L_20 , V_70 ) ;
}
static inline void F_30 ( struct V_71 * V_72 , struct V_9 * V_10 )
{
F_31 ( & V_10 -> V_72 , V_72 ) ;
}
static inline T_3 F_32 ( struct V_1 * V_8 , T_4 V_73 )
{
T_3 V_74 ;
struct V_75 * V_76 = & V_8 -> V_77 [ V_73 ] ;
unsigned long V_59 ;
if ( V_8 -> V_48 & V_78 )
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
if ( F_33 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
if ( ( V_76 -> V_81 [ V_76 -> V_82 ] & 1 ) == V_76 -> V_83 ) {
V_74 = V_76 -> V_81 [ V_76 -> V_82 ] ;
V_76 -> V_82 ++ ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_47 -- ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
} else {
V_74 = V_84 ;
}
if ( V_76 -> V_82 == V_8 -> V_85 ) {
V_76 -> V_82 = 0 ;
V_76 -> V_83 ^= 1 ;
}
return V_74 ;
}
static void F_34 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_35 ( V_8 -> V_48 & V_49 ) ) {
V_10 -> V_86 |= 1 | ( V_8 -> V_87 [ V_10 -> V_88 . V_89 ] << 1 ) ;
if ( F_35 ( V_8 -> V_90 > 0 ) )
V_10 -> V_88 . V_91 =
F_36 () % V_8 -> V_92 ;
}
}
static void F_37 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_93 * V_94 = & V_8 -> V_95 [ V_10 -> V_96 ] ;
V_94 -> V_91 = F_38 () % V_8 -> V_92 ;
V_10 -> V_86 |= 1 | ( V_8 -> V_97 [ V_10 -> V_88 . V_89 ] << 1 ) |
V_98 ;
}
static void F_39 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_99 * V_94 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
V_94 -> V_77 = F_38 () % V_8 -> V_92 ;
V_10 -> V_86 |= ( V_8 -> V_101 [ V_94 -> V_102 ] ) ;
}
static int F_40 ( T_4 * V_103 )
{
return V_103 [ 0 ] == V_104 && V_103 [ 6 ] == V_105 ;
}
static void F_41 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_40 ( V_10 -> V_106 . V_107 ) )
return;
F_42 ( & V_8 -> V_108 ) ;
V_8 -> V_109 = V_110 ;
}
static void F_43 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_40 ( V_10 -> V_106 . V_107 ) &&
F_44 ( & V_8 -> V_108 ) )
V_8 -> V_109 = V_111 ;
}
static void F_45 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_59 ;
switch ( V_10 -> V_112 ) {
case V_113 :
F_37 ( V_8 , V_10 ) ;
break;
case V_114 :
F_39 ( V_8 , V_10 ) ;
break;
default:
F_34 ( V_8 , V_10 ) ;
}
F_41 ( V_8 , V_10 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_30 ( & V_8 -> V_115 , V_10 ) ;
V_8 -> V_116 ++ ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_46 ( V_8 ) ;
}
static inline void F_47 ( struct V_9 * V_10 )
{
if ( F_48 ( F_49 ( & V_10 -> V_72 ) ) )
return;
F_50 ( & V_10 -> V_72 ) ;
}
static inline int F_51 ( unsigned char V_54 [] )
{
return memcmp ( V_54 , V_117 , 8 ) == 0 ;
}
static inline int F_52 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_46 )
return 0 ;
if ( ( V_8 -> V_46 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_8 ,
unsigned char V_54 [] , int V_118 , int * V_119 , int * V_120 )
{
int V_51 , V_121 = 0 ;
F_54 ( V_122 , V_123 ) ;
F_55 ( V_122 , V_123 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] -> V_118 == V_118 && V_8 -> V_16 [ V_51 ] -> V_119 != - 1 )
F_56 ( V_8 -> V_16 [ V_51 ] -> V_119 , V_122 ) ;
}
V_51 = F_57 ( V_122 , V_123 ) ;
if ( V_51 < V_123 ) {
* V_119 = V_51 ;
* V_120 = 0 ;
V_121 = 1 ;
}
return ! V_121 ;
}
static int F_58 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_28 ,
struct V_57 * V_126 [] , int * V_127 )
{
int V_128 = V_8 -> V_124 ;
int V_51 ;
unsigned char V_129 [ 8 ] , V_130 [ 8 ] ;
struct V_57 * V_131 ;
if ( V_128 >= V_123 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_30
L_31 ) ;
return - 1 ;
}
if ( V_28 -> V_120 != - 1 )
goto V_132;
if ( V_28 -> V_54 [ 4 ] == 0 ) {
if ( F_53 ( V_8 , V_28 -> V_54 ,
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
F_5 ( & V_8 -> V_15 -> V_16 , L_32
L_33
L_34 ) ;
return - 1 ;
}
V_132:
V_8 -> V_16 [ V_128 ] = V_28 ;
V_8 -> V_124 ++ ;
V_126 [ * V_127 ] = V_28 ;
( * V_127 ) ++ ;
F_60 ( & V_8 -> V_15 -> V_16 , L_35 ,
F_61 ( V_28 -> V_133 ) , V_125 ,
V_28 -> V_118 , V_28 -> V_119 , V_28 -> V_120 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 )
{
F_63 ( V_134 < 0 || V_134 >= V_123 ) ;
V_8 -> V_16 [ V_134 ] -> V_64 = V_135 -> V_64 ;
V_8 -> V_16 [ V_134 ] -> V_136 = V_135 -> V_136 ;
V_8 -> V_16 [ V_134 ] -> V_70 = V_135 -> V_70 ;
V_8 -> V_16 [ V_134 ] -> V_137 = V_135 -> V_137 ;
V_8 -> V_16 [ V_134 ] -> V_138 = V_135 -> V_138 ;
V_8 -> V_16 [ V_134 ] -> V_139 = V_135 -> V_139 ;
F_60 ( & V_8 -> V_15 -> V_16 , L_36 ,
F_61 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_64 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 ,
struct V_57 * V_126 [] , int * V_127 ,
struct V_57 * V_140 [] , int * V_141 )
{
F_63 ( V_134 < 0 || V_134 >= V_123 ) ;
V_140 [ * V_141 ] = V_8 -> V_16 [ V_134 ] ;
( * V_141 ) ++ ;
if ( V_135 -> V_119 == - 1 ) {
V_135 -> V_119 = V_8 -> V_16 [ V_134 ] -> V_119 ;
V_135 -> V_120 = V_8 -> V_16 [ V_134 ] -> V_120 ;
}
V_8 -> V_16 [ V_134 ] = V_135 ;
V_126 [ * V_127 ] = V_135 ;
( * V_127 ) ++ ;
F_60 ( & V_8 -> V_15 -> V_16 , L_37 ,
F_61 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_65 ( struct V_1 * V_8 , int V_125 , int V_134 ,
struct V_57 * V_140 [] , int * V_141 )
{
int V_51 ;
struct V_57 * V_131 ;
F_63 ( V_134 < 0 || V_134 >= V_123 ) ;
V_131 = V_8 -> V_16 [ V_134 ] ;
V_140 [ * V_141 ] = V_8 -> V_16 [ V_134 ] ;
( * V_141 ) ++ ;
for ( V_51 = V_134 ; V_51 < V_8 -> V_124 - 1 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] = V_8 -> V_16 [ V_51 + 1 ] ;
V_8 -> V_124 -- ;
F_60 ( & V_8 -> V_15 -> V_16 , L_38 ,
F_61 ( V_131 -> V_133 ) , V_125 , V_131 -> V_118 , V_131 -> V_119 ,
V_131 -> V_120 ) ;
}
static void F_66 ( struct V_1 * V_8 ,
struct V_57 * V_126 )
{
unsigned long V_59 ;
int V_51 , V_142 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] == V_126 ) {
for ( V_142 = V_51 ; V_142 < V_8 -> V_124 - 1 ; V_142 ++ )
V_8 -> V_16 [ V_142 ] = V_8 -> V_16 [ V_142 + 1 ] ;
V_8 -> V_124 -- ;
break;
}
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_67 ( V_126 ) ;
}
static inline int F_68 ( struct V_57 * V_143 ,
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
static inline int F_69 ( struct V_57 * V_143 ,
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
static int F_70 ( struct V_57 * V_147 ,
struct V_57 * V_148 [] , int V_149 ,
int * V_150 )
{
int V_51 ;
#define F_71 0
#define F_72 1
#define F_73 2
#define F_74 3
for ( V_51 = 0 ; V_51 < V_149 ; V_51 ++ ) {
if ( V_148 [ V_51 ] == NULL )
continue;
if ( F_75 ( V_147 -> V_54 , V_148 [ V_51 ] -> V_54 ) ) {
* V_150 = V_51 ;
if ( F_68 ( V_147 , V_148 [ V_51 ] ) ) {
if ( F_69 ( V_147 , V_148 [ V_51 ] ) )
return F_74 ;
return F_73 ;
} else {
if ( V_147 -> V_151 )
return F_71 ;
return F_72 ;
}
}
}
* V_150 = - 1 ;
return F_71 ;
}
static void F_76 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_152 * V_28 ;
unsigned long V_59 ;
F_25 ( & V_8 -> V_153 , V_59 ) ;
F_77 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_28 -> V_54 , V_54 ,
sizeof( V_28 -> V_54 ) ) == 0 ) {
F_26 ( & V_8 -> V_153 , V_59 ) ;
return;
}
}
F_26 ( & V_8 -> V_153 , V_59 ) ;
V_28 = F_78 ( sizeof( * V_28 ) , V_154 ) ;
if ( ! V_28 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_39 , V_155 ) ;
return;
}
memcpy ( V_28 -> V_54 , V_54 , sizeof( V_28 -> V_54 ) ) ;
F_25 ( & V_8 -> V_153 , V_59 ) ;
F_31 ( & V_28 -> V_156 , & V_8 -> V_157 ) ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
}
static void F_79 ( struct V_1 * V_8 ,
struct V_57 * V_131 )
{
if ( V_131 -> V_151 == V_158 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_40 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
switch ( V_131 -> V_151 ) {
case V_160 :
break;
case V_161 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_41 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_162 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_42 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_163 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_43 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_164 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_44 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_165 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_45 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_166 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_46 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_167 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_47 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_168 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_48 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_169 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_49 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_170 :
F_60 ( & V_8 -> V_15 -> V_16 ,
L_50 ,
V_8 -> V_44 -> V_159 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
}
}
static void F_80 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_131 [] , int V_171 )
{
int V_51 , V_134 , V_172 , V_173 = 0 ;
struct V_57 * V_174 ;
unsigned long V_59 ;
struct V_57 * * V_126 , * * V_140 ;
int V_127 , V_141 ;
struct V_6 * V_7 = NULL ;
V_126 = F_81 ( sizeof( * V_126 ) * V_123 , V_154 ) ;
V_140 = F_81 ( sizeof( * V_140 ) * V_123 , V_154 ) ;
if ( ! V_126 || ! V_140 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_51
L_52 ) ;
goto V_175;
}
F_25 ( & V_8 -> V_176 , V_59 ) ;
V_51 = 0 ;
V_141 = 0 ;
V_127 = 0 ;
while ( V_51 < V_8 -> V_124 ) {
V_174 = V_8 -> V_16 [ V_51 ] ;
V_172 = F_70 ( V_174 , V_131 , V_171 , & V_134 ) ;
if ( V_172 == F_71 ) {
V_173 ++ ;
F_65 ( V_8 , V_125 , V_51 ,
V_140 , & V_141 ) ;
continue;
} else if ( V_172 == F_72 ) {
V_173 ++ ;
F_64 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ,
V_126 , & V_127 , V_140 , & V_141 ) ;
V_131 [ V_134 ] = NULL ;
} else if ( V_172 == F_74 ) {
F_62 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ) ;
}
V_51 ++ ;
}
for ( V_51 = 0 ; V_51 < V_171 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_151 ) {
F_79 ( V_8 , V_131 [ V_51 ] ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_53 ,
V_8 -> V_44 -> V_159 ,
V_131 [ V_51 ] -> V_118 , V_131 [ V_51 ] -> V_119 , V_131 [ V_51 ] -> V_120 ) ;
continue;
}
V_172 = F_70 ( V_131 [ V_51 ] , V_8 -> V_16 ,
V_8 -> V_124 , & V_134 ) ;
if ( V_172 == F_71 ) {
V_173 ++ ;
if ( F_58 ( V_8 , V_125 , V_131 [ V_51 ] ,
V_126 , & V_127 ) != 0 )
break;
V_131 [ V_51 ] = NULL ;
} else if ( V_172 == F_72 ) {
V_173 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_54 ) ;
}
}
F_26 ( & V_8 -> V_176 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_171 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_151 )
F_76 ( V_8 , V_131 [ V_51 ] -> V_54 ) ;
}
if ( V_125 == - 1 || ! V_173 )
goto V_175;
V_7 = V_8 -> V_44 ;
for ( V_51 = 0 ; V_51 < V_141 ; V_51 ++ ) {
struct V_2 * V_3 =
F_82 ( V_7 , V_140 [ V_51 ] -> V_118 ,
V_140 [ V_51 ] -> V_119 , V_140 [ V_51 ] -> V_120 ) ;
if ( V_3 != NULL ) {
F_83 ( V_3 ) ;
F_84 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_55
L_56 , V_125 , V_140 [ V_51 ] -> V_118 ,
V_140 [ V_51 ] -> V_119 , V_140 [ V_51 ] -> V_120 ) ;
}
F_67 ( V_140 [ V_51 ] ) ;
V_140 [ V_51 ] = NULL ;
}
for ( V_51 = 0 ; V_51 < V_127 ; V_51 ++ ) {
if ( F_85 ( V_7 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_57
L_58 , V_125 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) ;
F_66 ( V_8 , V_126 [ V_51 ] ) ;
}
V_175:
F_67 ( V_126 ) ;
F_67 ( V_140 ) ;
}
static struct V_57 * F_86 ( struct V_1 * V_8 ,
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
static int F_87 ( struct V_2 * V_3 )
{
struct V_57 * V_131 ;
unsigned long V_59 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 ) ;
F_25 ( & V_8 -> V_176 , V_59 ) ;
V_131 = F_86 ( V_8 , F_88 ( V_3 ) ,
F_89 ( V_3 ) , V_3 -> V_120 ) ;
if ( V_131 != NULL )
V_3 -> V_61 = V_131 ;
F_26 ( & V_8 -> V_176 , V_59 ) ;
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
}
static void F_91 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_177 )
return;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
F_67 ( V_8 -> V_177 [ V_51 ] ) ;
V_8 -> V_177 [ V_51 ] = NULL ;
}
F_67 ( V_8 -> V_177 ) ;
V_8 -> V_177 = NULL ;
}
static int F_92 ( struct V_1 * V_8 )
{
int V_51 ;
if ( V_8 -> V_179 <= 0 )
return 0 ;
V_8 -> V_177 = F_81 ( sizeof( * V_8 -> V_177 ) * V_8 -> V_178 ,
V_154 ) ;
if ( ! V_8 -> V_177 )
return - V_180 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
V_8 -> V_177 [ V_51 ] = F_78 ( sizeof( * V_8 -> V_177 [ V_51 ] ) *
V_8 -> V_179 , V_154 ) ;
if ( ! V_8 -> V_177 [ V_51 ] )
goto V_181;
}
return 0 ;
V_181:
F_91 ( V_8 ) ;
return - V_180 ;
}
static int F_93 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_182 * V_183 , * V_184 ;
T_5 V_185 ;
V_183 = & V_10 -> V_186 [ V_8 -> V_187 - 1 ] ;
V_184 = V_8 -> V_177 [ V_10 -> V_96 ] ;
V_183 -> V_188 = V_189 ;
V_183 -> V_190 = sizeof( * V_183 ) *
( V_10 -> V_88 . V_191 - V_8 -> V_187 ) ;
V_185 = F_94 ( V_8 -> V_15 , V_184 , V_183 -> V_190 ,
V_192 ) ;
if ( F_95 ( & V_8 -> V_15 -> V_16 , V_185 ) ) {
V_183 -> V_193 . V_194 = 0 ;
V_183 -> V_193 . V_195 = 0 ;
return - 1 ;
}
V_183 -> V_193 . V_194 = ( T_3 ) ( V_185 & 0x0FFFFFFFFULL ) ;
V_183 -> V_193 . V_195 = ( T_3 ) ( ( V_185 >> 32 ) & 0x0FFFFFFFFULL ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_182 * V_183 ;
union V_196 V_185 ;
if ( V_10 -> V_88 . V_191 <= V_8 -> V_187 )
return;
V_183 = & V_10 -> V_186 [ V_8 -> V_187 - 1 ] ;
V_185 . V_197 . V_194 = V_183 -> V_193 . V_194 ;
V_185 . V_197 . V_195 = V_183 -> V_193 . V_195 ;
F_97 ( V_8 -> V_15 , V_185 . V_198 , V_183 -> V_190 , V_192 ) ;
}
static int F_98 ( struct V_1 * V_8 ,
struct V_9 * V_10 ,
struct V_199 * V_200 ,
struct V_99 * V_201 )
{
int V_202 ;
int V_203 = 0 ;
switch ( V_201 -> V_204 . V_205 ) {
case V_206 :
switch ( V_201 -> V_204 . V_33 ) {
case V_207 :
break;
case V_208 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_59 ,
L_60 ) ;
if ( V_201 -> V_204 . V_209 !=
V_210 )
break;
V_202 = V_201 -> V_204 . V_211 ;
if ( V_202 > V_212 )
V_202 = V_212 ;
if ( V_202 > sizeof( V_201 -> V_204 . V_213 ) )
V_202 =
sizeof( V_201 -> V_204 . V_213 ) ;
memcpy ( V_200 -> V_214 ,
V_201 -> V_204 . V_213 , V_202 ) ;
V_200 -> V_215 |= V_216 ;
V_203 = 1 ;
break;
case V_217 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_61 ,
L_60 ) ;
V_203 = 1 ;
break;
case V_218 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_62 ,
L_60 ) ;
V_203 = 1 ;
break;
case V_219 :
V_200 -> V_215 = V_220 << 16 ;
break;
case V_221 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_63 ,
L_60 ) ;
V_203 = 1 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_64 ,
L_60 , V_201 -> V_204 . V_33 ) ;
V_203 = 1 ;
break;
}
break;
case V_222 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_65 ,
V_201 -> V_204 . V_33 ) ;
V_203 = 1 ;
break;
case V_223 :
break;
case V_224 :
break;
case V_225 :
F_5 ( & V_8 -> V_15 -> V_16 , L_66 ) ;
V_203 = 1 ;
break;
case V_226 :
F_5 ( & V_8 -> V_15 -> V_16 , L_67 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_68 ,
L_60 ,
V_201 -> V_204 . V_205 ) ;
V_203 = 1 ;
break;
}
return V_203 ;
}
static void F_99 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_199 * V_200 ,
struct V_57 * V_16 )
{
struct V_99 * V_201 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
int V_227 = 0 ;
if ( F_35 ( V_201 -> V_204 . V_205 == 0 &&
V_201 -> V_204 . V_33 == 0 ) ) {
F_100 ( V_8 , V_10 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
if ( F_22 ( V_16 -> V_54 ) &&
V_201 -> V_204 . V_205 ==
V_222 ) {
if ( V_201 -> V_204 . V_33 ==
V_229 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_69 ,
L_60 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 ,
L_70 ,
L_60 , V_201 -> V_204 . V_33 ) ;
V_16 -> V_70 = 0 ;
V_8 -> V_230 = 1 ;
V_200 -> V_215 = V_231 << 16 ;
F_100 ( V_8 , V_10 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
V_227 = F_98 ( V_8 , V_10 , V_200 , V_201 ) ;
if ( V_227 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_71 ,
L_60 ) ;
V_16 -> V_70 = 0 ;
V_8 -> V_230 = 1 ;
V_200 -> V_215 = V_231 << 16 ;
}
F_100 ( V_8 , V_10 ) ;
V_200 -> V_228 ( V_200 ) ;
}
static void F_101 ( struct V_9 * V_94 )
{
struct V_199 * V_200 ;
struct V_1 * V_8 ;
struct V_232 * V_233 ;
struct V_57 * V_16 ;
unsigned char V_234 ;
unsigned char V_235 ;
unsigned char V_236 ;
unsigned long V_237 ;
V_233 = V_94 -> V_11 ;
V_200 = (struct V_199 * ) V_94 -> V_238 ;
V_8 = V_94 -> V_8 ;
V_16 = V_200 -> V_28 -> V_61 ;
F_102 ( V_200 ) ;
if ( ( V_94 -> V_112 == V_239 ) &&
( V_94 -> V_88 . V_191 > V_8 -> V_187 ) )
F_96 ( V_8 , V_94 ) ;
V_200 -> V_215 = ( V_240 << 16 ) ;
V_200 -> V_215 |= ( V_241 << 8 ) ;
if ( V_94 -> V_112 == V_114 )
return F_99 ( V_8 , V_94 , V_200 , V_16 ) ;
V_200 -> V_215 |= V_233 -> V_25 ;
if ( V_212 < sizeof( V_233 -> V_12 ) )
V_237 = V_212 ;
else
V_237 = sizeof( V_233 -> V_12 ) ;
if ( V_233 -> V_242 < V_237 )
V_237 = V_233 -> V_242 ;
memcpy ( V_200 -> V_214 , V_233 -> V_12 , V_237 ) ;
F_103 ( V_200 , V_233 -> V_243 ) ;
if ( V_233 -> V_23 == 0 ) {
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
if ( V_94 -> V_112 == V_113 ) {
struct V_93 * V_10 = & V_8 -> V_95 [ V_94 -> V_96 ] ;
V_94 -> V_88 . V_89 = V_94 -> V_88 . V_191 = F_104 ( V_200 ) ;
V_94 -> V_106 . V_244 = V_10 -> V_245 & V_246 ;
V_94 -> V_88 . V_247 . V_194 = V_10 -> V_247 . V_194 ;
V_94 -> V_88 . V_247 . V_195 = V_10 -> V_247 . V_195 ;
memcpy ( V_94 -> V_88 . V_248 . V_249 , V_10 -> V_250 , 8 ) ;
memcpy ( V_94 -> V_106 . V_107 , V_10 -> V_107 , V_94 -> V_106 . V_244 ) ;
if ( F_22 ( V_16 -> V_54 ) ) {
if ( V_233 -> V_23 == V_251 )
V_16 -> V_70 = 0 ;
V_200 -> V_215 = V_231 << 16 ;
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
}
switch ( V_233 -> V_23 ) {
case V_24 :
if ( V_233 -> V_25 ) {
V_234 = 0xf & V_233 -> V_12 [ 2 ] ;
V_235 = V_233 -> V_12 [ 12 ] ;
V_236 = V_233 -> V_12 [ 13 ] ;
}
if ( V_233 -> V_25 == V_216 ) {
if ( F_4 ( V_8 , V_94 ) )
break;
if ( V_234 == V_252 ) {
if ( V_94 -> V_106 . V_107 [ 0 ] == V_253 )
break;
if ( ( V_235 == 0x25 ) && ( V_236 == 0x0 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_72
L_73 , V_94 ) ;
break;
}
}
if ( V_234 == V_254 ) {
if ( ( V_235 == 0x04 ) && ( V_236 == 0x03 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_72
L_74
L_75
L_76 , V_94 ) ;
break;
}
}
if ( V_234 == V_255 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_72
L_77
L_78 ,
V_94 , V_235 , V_236 ) ;
V_200 -> V_215 |= V_231 << 16 ;
break;
}
F_105 ( & V_8 -> V_15 -> V_16 , L_79
L_80
L_81
L_82
L_83
L_84
L_85 ,
V_94 , V_234 , V_235 , V_236 ,
V_200 -> V_215 ,
V_200 -> V_256 [ 0 ] , V_200 -> V_256 [ 1 ] ,
V_200 -> V_256 [ 2 ] , V_200 -> V_256 [ 3 ] ,
V_200 -> V_256 [ 4 ] , V_200 -> V_256 [ 5 ] ,
V_200 -> V_256 [ 6 ] , V_200 -> V_256 [ 7 ] ,
V_200 -> V_256 [ 8 ] , V_200 -> V_256 [ 9 ] ,
V_200 -> V_256 [ 10 ] , V_200 -> V_256 [ 11 ] ,
V_200 -> V_256 [ 12 ] , V_200 -> V_256 [ 13 ] ,
V_200 -> V_256 [ 14 ] , V_200 -> V_256 [ 15 ] ) ;
break;
}
if ( V_233 -> V_25 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_86
L_81
L_87 ,
V_94 , V_233 -> V_25 ,
V_234 , V_235 , V_236 ,
V_200 -> V_215 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_88
L_89 , V_94 ) ,
V_200 -> V_215 = V_257 << 16 ;
}
break;
case V_258 :
break;
case V_259 :
F_5 ( & V_8 -> V_15 -> V_16 , L_90
L_91
L_92 , V_94 ) ;
break;
case V_260 : {
V_200 -> V_215 = V_257 << 16 ;
}
break;
case V_261 :
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_93
L_94 , V_94 ) ;
break;
case V_263 :
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_95 , V_94 ) ;
break;
case V_264 :
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_96 , V_94 ) ;
break;
case V_265 :
V_200 -> V_215 = V_266 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_97 ,
V_94 , V_233 -> V_25 ) ;
break;
case V_267 :
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_98 , V_94 ) ;
break;
case V_268 :
V_200 -> V_215 = V_231 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_99
L_100 , V_94 ) ;
break;
case V_269 :
V_200 -> V_215 = V_270 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_101 , V_94 ) ;
break;
case V_271 :
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_102 ) ;
break;
case V_251 :
V_200 -> V_215 = V_231 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_103 , V_94 ) ;
break;
default:
V_200 -> V_215 = V_262 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_104 ,
V_94 , V_233 -> V_23 ) ;
}
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
}
static void F_106 ( struct V_272 * V_15 ,
struct V_9 * V_10 , int V_273 , int V_274 )
{
int V_51 ;
union V_196 V_275 ;
for ( V_51 = 0 ; V_51 < V_273 ; V_51 ++ ) {
V_275 . V_197 . V_194 = V_10 -> V_186 [ V_51 ] . V_193 . V_194 ;
V_275 . V_197 . V_195 = V_10 -> V_186 [ V_51 ] . V_193 . V_195 ;
F_97 ( V_15 , ( V_276 ) V_275 . V_198 , V_10 -> V_186 [ V_51 ] . V_190 ,
V_274 ) ;
}
}
static int F_107 ( struct V_272 * V_15 ,
struct V_9 * V_94 ,
unsigned char * V_31 ,
T_2 V_277 ,
int V_274 )
{
T_5 V_275 ;
if ( V_277 == 0 || V_274 == V_278 ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = 0 ;
return 0 ;
}
V_275 = ( T_5 ) F_94 ( V_15 , V_31 , V_277 , V_274 ) ;
if ( F_95 ( & V_15 -> V_16 , V_275 ) ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = 0 ;
return - 1 ;
}
V_94 -> V_186 [ 0 ] . V_193 . V_194 =
( T_3 ) ( V_275 & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_94 -> V_186 [ 0 ] . V_193 . V_195 =
( T_3 ) ( ( V_275 >> 32 ) & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_94 -> V_186 [ 0 ] . V_190 = V_277 ;
V_94 -> V_186 [ 0 ] . V_188 = V_279 ;
V_94 -> V_88 . V_89 = ( T_4 ) 1 ;
V_94 -> V_88 . V_191 = ( V_280 ) 1 ;
return 0 ;
}
static inline void F_108 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_109 ( V_281 ) ;
V_10 -> V_282 = & V_281 ;
F_45 ( V_8 , V_10 ) ;
F_110 ( & V_281 ) ;
}
static void F_111 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
if ( F_33 ( V_8 -> V_283 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_10 -> V_11 -> V_23 = V_263 ;
} else {
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_108 ( V_8 , V_10 ) ;
}
}
static void F_112 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_274 )
{
int V_284 = 10 , V_285 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_108 ( V_8 , V_10 ) ;
V_285 ++ ;
if ( V_285 > 3 ) {
F_113 ( V_284 ) ;
if ( V_284 < 1000 )
V_284 *= 2 ;
}
} while ( ( F_4 ( V_8 , V_10 ) ||
F_6 ( V_8 , V_10 ) ) &&
V_285 <= V_286 );
F_106 ( V_8 -> V_15 , V_10 , 1 , V_274 ) ;
}
static void F_114 ( struct V_1 * V_8 , char * V_287 ,
struct V_9 * V_10 )
{
const T_4 * V_103 = V_10 -> V_106 . V_107 ;
const T_4 * V_120 = V_10 -> V_88 . V_248 . V_249 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_105
L_106 ,
V_287 , V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ,
V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_103 [ 8 ] , V_103 [ 9 ] , V_103 [ 10 ] , V_103 [ 11 ] ,
V_103 [ 12 ] , V_103 [ 13 ] , V_103 [ 14 ] , V_103 [ 15 ] ) ;
}
static void F_115 ( struct V_1 * V_8 ,
struct V_9 * V_94 )
{
const struct V_232 * V_233 = V_94 -> V_11 ;
struct V_28 * V_288 = & V_94 -> V_8 -> V_15 -> V_16 ;
const T_4 * V_131 = V_233 -> V_12 ;
switch ( V_233 -> V_23 ) {
case V_24 :
F_114 ( V_8 , L_107 , V_94 ) ;
if ( V_233 -> V_25 == V_216 )
F_5 ( V_288 , L_108 ,
V_131 [ 2 ] & 0x0f , V_131 [ 12 ] , V_131 [ 13 ] ) ;
else
F_5 ( V_288 , L_109 , V_233 -> V_25 ) ;
if ( V_233 -> V_25 == 0 )
F_5 ( V_288 , L_110
L_111
L_112
L_113 ) ;
break;
case V_258 :
break;
case V_259 :
F_114 ( V_8 , L_114 , V_94 ) ;
break;
case V_260 : {
F_114 ( V_8 , L_115 , V_94 ) ;
F_5 ( V_288 , L_116 ) ;
}
break;
case V_261 :
F_114 ( V_8 , L_117 , V_94 ) ;
break;
case V_263 :
F_114 ( V_8 , L_118 , V_94 ) ;
break;
case V_264 :
F_114 ( V_8 , L_119 , V_94 ) ;
break;
case V_265 :
F_114 ( V_8 , L_120 , V_94 ) ;
break;
case V_267 :
F_114 ( V_8 , L_121 , V_94 ) ;
break;
case V_268 :
F_114 ( V_8 , L_122 , V_94 ) ;
break;
case V_269 :
F_114 ( V_8 , L_123 , V_94 ) ;
break;
case V_271 :
F_114 ( V_8 , L_124 , V_94 ) ;
break;
default:
F_114 ( V_8 , L_125 , V_94 ) ;
F_5 ( V_288 , L_126 ,
V_233 -> V_23 ) ;
}
}
static int F_116 ( struct V_1 * V_8 , unsigned char * V_54 ,
V_280 V_289 , unsigned char * V_31 ,
unsigned char V_290 )
{
int V_291 = V_292 ;
struct V_9 * V_10 ;
struct V_232 * V_233 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - V_180 ;
}
if ( F_118 ( V_10 , V_293 , V_8 , V_31 , V_290 ,
V_289 , V_54 , V_294 ) ) {
V_291 = - 1 ;
goto V_295;
}
F_112 ( V_8 , V_10 , V_296 ) ;
V_233 = V_10 -> V_11 ;
if ( V_233 -> V_23 != 0 && V_233 -> V_23 != V_258 ) {
F_115 ( V_8 , V_10 ) ;
V_291 = - 1 ;
}
V_295:
F_119 ( V_8 , V_10 ) ;
return V_291 ;
}
static int F_120 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char V_289 ,
struct V_297 * V_31 , T_2 V_290 )
{
int V_291 = V_292 ;
struct V_9 * V_10 ;
struct V_232 * V_233 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - V_180 ;
}
if ( F_118 ( V_10 , V_298 , V_8 , V_31 , V_290 ,
V_289 , V_54 , V_294 ) ) {
V_291 = - 1 ;
goto V_295;
}
F_112 ( V_8 , V_10 , V_296 ) ;
V_233 = V_10 -> V_11 ;
if ( V_233 -> V_23 != 0 && V_233 -> V_23 != V_258 ) {
F_115 ( V_8 , V_10 ) ;
V_291 = - 1 ;
}
V_295:
F_119 ( V_8 , V_10 ) ;
return V_291 ;
}
static int F_121 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_299 )
{
int V_291 = V_292 ;
struct V_9 * V_10 ;
struct V_232 * V_233 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - V_180 ;
}
( void ) F_118 ( V_10 , V_300 , V_8 , NULL , 0 , 0 ,
V_54 , V_301 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_299 ;
F_108 ( V_8 , V_10 ) ;
V_233 = V_10 -> V_11 ;
if ( V_233 -> V_23 != 0 ) {
F_115 ( V_8 , V_10 ) ;
V_291 = - 1 ;
}
F_119 ( V_8 , V_10 ) ;
return V_291 ;
}
static void F_122 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char * V_64 )
{
int V_291 ;
unsigned char * V_31 ;
* V_64 = V_65 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
V_291 = F_116 ( V_8 , V_54 , V_302 | 0xC1 , V_31 , 64 ) ;
if ( V_291 == 0 )
* V_64 = V_31 [ 8 ] ;
if ( * V_64 > V_65 )
* V_64 = V_65 ;
F_67 ( V_31 ) ;
return;
}
static void F_123 ( struct V_1 * V_8 , int V_291 ,
struct V_303 * V_304 )
{
struct V_305 * V_306 = & V_304 -> V_307 [ 0 ] ;
int V_308 , V_309 , V_310 ;
V_280 V_311 , V_312 , V_313 ;
if ( V_291 != 0 )
return;
if ( V_8 -> V_43 < 2 )
return;
F_60 ( & V_8 -> V_15 -> V_16 , L_128 ,
F_124 ( V_304 -> V_314 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_129 ,
F_124 ( V_304 -> V_315 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_130 ,
F_125 ( V_304 -> V_316 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_131 ,
V_304 -> V_317 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_132 ,
V_304 -> V_318 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_133 ,
F_126 ( V_304 -> V_319 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_134 ,
F_125 ( V_304 -> V_320 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_135 ,
F_125 ( V_304 -> V_321 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_136 ,
F_126 ( V_304 -> V_322 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_137 ,
F_126 ( V_304 -> V_323 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_138 ,
F_126 ( V_304 -> V_312 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_139 ,
F_126 ( V_304 -> V_324 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_140 ,
F_126 ( V_304 -> V_59 ) ) ;
if ( V_304 -> V_59 & V_325 )
F_60 ( & V_8 -> V_15 -> V_16 , L_141 ) ;
else
F_60 ( & V_8 -> V_15 -> V_16 , L_142 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_143 ,
F_126 ( V_304 -> V_326 ) ) ;
V_311 = F_126 ( V_304 -> V_324 ) ;
for ( V_308 = 0 ; V_308 < V_311 ; V_308 ++ ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_144 , V_308 ) ;
V_312 = F_126 ( V_304 -> V_312 ) ;
for ( V_309 = 0 ; V_309 < V_312 ; V_309 ++ ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_145 , V_309 ) ;
V_313 =
F_126 ( V_304 -> V_322 ) ;
for ( V_310 = 0 ; V_310 < V_313 ; V_310 ++ , V_306 ++ )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_146 ,
V_310 , V_306 -> V_137 ,
V_306 -> V_327 [ 0 ] , V_306 -> V_327 [ 1 ] ) ;
V_313 =
F_126 ( V_304 -> V_323 ) ;
for ( V_310 = 0 ; V_310 < V_313 ; V_310 ++ , V_306 ++ )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_147 ,
V_310 , V_306 -> V_137 ,
V_306 -> V_327 [ 0 ] , V_306 -> V_327 [ 1 ] ) ;
}
}
}
static int F_127 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_328 )
{
int V_291 = 0 ;
struct V_9 * V_10 ;
struct V_232 * V_233 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - V_180 ;
}
if ( F_118 ( V_10 , V_329 , V_8 , & V_328 -> V_139 ,
sizeof( V_328 -> V_139 ) , 0 ,
V_54 , V_294 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_148 ) ;
F_119 ( V_8 , V_10 ) ;
return - V_180 ;
}
F_112 ( V_8 , V_10 , V_296 ) ;
V_233 = V_10 -> V_11 ;
if ( V_233 -> V_23 != 0 && V_233 -> V_23 != V_258 ) {
F_115 ( V_8 , V_10 ) ;
F_119 ( V_8 , V_10 ) ;
return - 1 ;
}
F_119 ( V_8 , V_10 ) ;
if ( F_124 ( V_328 -> V_139 . V_314 ) >
sizeof( V_328 -> V_139 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_149 ) ;
V_291 = - 1 ;
}
F_123 ( V_8 , V_291 , & V_328 -> V_139 ) ;
return V_291 ;
}
static int F_128 ( struct V_1 * V_8 ,
unsigned char V_54 [] , T_4 V_289 )
{
int V_291 ;
int V_51 ;
int V_330 ;
unsigned char * V_31 , V_290 ;
V_31 = F_81 ( 256 , V_154 ) ;
if ( ! V_31 )
return 0 ;
V_291 = F_116 ( V_8 , V_54 ,
V_302 | V_331 ,
V_31 , V_332 ) ;
if ( V_291 != 0 )
goto V_333;
V_330 = V_31 [ 3 ] ;
if ( ( V_330 + V_332 ) <= 255 )
V_290 = V_330 + V_332 ;
else
V_290 = 255 ;
V_291 = F_116 ( V_8 , V_54 ,
V_302 | V_331 ,
V_31 , V_290 ) ;
if ( V_291 != 0 )
goto V_333;
V_330 = V_31 [ 3 ] ;
for ( V_51 = 1 ; V_51 <= V_330 ; V_51 ++ )
if ( V_31 [ 3 + V_51 ] == V_289 )
goto V_334;
V_333:
F_67 ( V_31 ) ;
return 0 ;
V_334:
F_67 ( V_31 ) ;
return 1 ;
}
static void F_129 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_328 )
{
int V_291 ;
unsigned char * V_31 ;
T_4 V_335 ;
V_328 -> V_136 = 0 ;
V_328 -> V_70 = 0 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
if ( ! F_128 ( V_8 , V_54 , V_336 ) )
goto V_295;
V_291 = F_116 ( V_8 , V_54 ,
V_302 | V_336 , V_31 , 64 ) ;
if ( V_291 != 0 )
goto V_295;
#define F_130 4
#define F_131 0x01
#define F_132 0x02
V_335 = V_31 [ F_130 ] ;
V_328 -> V_136 =
! ! ( V_335 & F_131 ) ;
if ( V_328 -> V_136 ) {
V_328 -> V_70 =
! ! ( V_335 & F_132 ) ;
if ( F_127 ( V_8 , V_54 , V_328 ) )
V_328 -> V_70 = 0 ;
}
V_295:
F_67 ( V_31 ) ;
return;
}
static int F_133 ( struct V_1 * V_8 , unsigned char * V_54 ,
unsigned char * V_69 , int V_277 )
{
int V_291 ;
unsigned char * V_31 ;
if ( V_277 > 16 )
V_277 = 16 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return - 1 ;
V_291 = F_116 ( V_8 , V_54 , V_302 | 0x83 , V_31 , 64 ) ;
if ( V_291 == 0 )
memcpy ( V_69 , & V_31 [ 8 ] , V_277 ) ;
F_67 ( V_31 ) ;
return V_291 != 0 ;
}
static int F_134 ( struct V_1 * V_8 , int V_337 ,
struct V_338 * V_31 , int V_290 ,
int V_339 )
{
int V_291 = V_292 ;
struct V_9 * V_10 ;
unsigned char V_54 [ 8 ] ;
struct V_232 * V_233 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - 1 ;
}
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
if ( F_118 ( V_10 , V_337 ? V_340 : V_341 , V_8 ,
V_31 , V_290 , 0 , V_54 , V_294 ) ) {
V_291 = - 1 ;
goto V_295;
}
if ( V_339 )
V_10 -> V_106 . V_107 [ 1 ] = V_339 ;
F_112 ( V_8 , V_10 , V_296 ) ;
V_233 = V_10 -> V_11 ;
if ( V_233 -> V_23 != 0 &&
V_233 -> V_23 != V_258 ) {
F_115 ( V_8 , V_10 ) ;
V_291 = - 1 ;
} else {
if ( V_31 -> V_342 != V_339 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_150 ,
V_339 ,
V_31 -> V_342 ) ;
V_291 = - 1 ;
}
}
V_295:
F_119 ( V_8 , V_10 ) ;
return V_291 ;
}
static inline int F_135 ( struct V_1 * V_8 ,
struct V_338 * V_31 ,
int V_290 , int V_339 )
{
return F_134 ( V_8 , 0 , V_31 , V_290 , V_339 ) ;
}
static inline int F_136 ( struct V_1 * V_8 ,
struct V_338 * V_31 , int V_290 )
{
return F_134 ( V_8 , 1 , V_31 , V_290 , 0 ) ;
}
static inline void F_137 ( struct V_57 * V_28 ,
int V_118 , int V_119 , int V_120 )
{
V_28 -> V_118 = V_118 ;
V_28 -> V_119 = V_119 ;
V_28 -> V_120 = V_120 ;
}
static int F_138 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
int V_291 ;
int V_33 ;
int V_343 ;
unsigned char * V_31 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return V_158 ;
if ( ! F_128 ( V_8 , V_54 , V_344 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_151 ) ;
goto V_345;
}
V_291 = F_116 ( V_8 , V_54 , V_302 | V_344 ,
V_31 , V_332 ) ;
if ( V_291 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_152 ) ;
goto V_345;
}
V_343 = V_31 [ 3 ] ;
V_291 = F_116 ( V_8 , V_54 , V_302 | V_344 ,
V_31 , V_343 + V_332 ) ;
if ( V_291 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_152 ) ;
goto V_345;
}
V_33 = V_31 [ 4 ] ;
F_67 ( V_31 ) ;
return V_33 ;
V_345:
F_67 ( V_31 ) ;
return V_158 ;
}
static unsigned char F_139 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_9 * V_10 ;
unsigned char * V_346 , V_234 , V_235 , V_236 ;
int V_347 = 0 ;
V_280 V_348 ;
T_4 V_349 ;
#define F_140 0x04
#define F_141 0x04
#define F_142 0x02
V_10 = F_143 ( V_8 ) ;
if ( ! V_10 )
return 0 ;
( void ) F_118 ( V_10 , V_350 , V_8 , NULL , 0 , 0 , V_54 , V_294 ) ;
F_108 ( V_8 , V_10 ) ;
V_346 = V_10 -> V_11 -> V_12 ;
V_234 = V_346 [ 2 ] ;
V_235 = V_346 [ 12 ] ;
V_236 = V_346 [ 13 ] ;
V_348 = V_10 -> V_11 -> V_23 ;
V_349 = V_10 -> V_11 -> V_25 ;
F_100 ( V_8 , V_10 ) ;
if ( V_348 != V_24 ||
V_349 != V_216 ||
V_234 != V_254 ||
V_235 != F_140 ) {
return 0 ;
}
V_347 = F_138 ( V_8 , V_54 ) ;
switch ( V_347 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
return V_347 ;
case V_158 :
if ( ( V_236 == F_141 ) ||
( V_236 == F_142 ) )
return V_347 ;
break;
default:
break;
}
return 0 ;
}
static int F_144 ( struct V_1 * V_8 ,
unsigned char V_54 [] , struct V_57 * V_328 ,
unsigned char * V_351 )
{
#define F_145 43
#define F_146 "$DR-10"
#define F_147 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_148 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_352 ;
unsigned char * V_353 ;
V_352 = F_81 ( F_148 , V_154 ) ;
if ( ! V_352 )
goto V_354;
if ( F_116 ( V_8 , V_54 , 0 , V_352 ,
( unsigned char ) F_148 ) != 0 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_153 ) ;
goto V_354;
}
V_328 -> V_133 = ( V_352 [ 0 ] & 0x1f ) ;
memcpy ( V_328 -> V_54 , V_54 , 8 ) ;
memcpy ( V_328 -> V_146 , & V_352 [ 8 ] ,
sizeof( V_328 -> V_146 ) ) ;
memcpy ( V_328 -> V_145 , & V_352 [ 16 ] ,
sizeof( V_328 -> V_145 ) ) ;
memset ( V_328 -> V_69 , 0 ,
sizeof( V_328 -> V_69 ) ) ;
F_133 ( V_8 , V_54 , V_328 -> V_69 ,
sizeof( V_328 -> V_69 ) ) ;
if ( V_328 -> V_133 == V_355 &&
F_22 ( V_54 ) ) {
F_122 ( V_8 , V_54 , & V_328 -> V_64 ) ;
if ( V_8 -> V_356 & V_357 )
F_129 ( V_8 , V_54 , V_328 ) ;
V_328 -> V_151 =
F_139 ( V_8 , V_54 ) ;
} else {
V_328 -> V_64 = V_65 ;
V_328 -> V_136 = 0 ;
V_328 -> V_70 = 0 ;
V_328 -> V_151 = 0 ;
}
if ( V_351 ) {
V_353 = & V_352 [ F_145 ] ;
* V_351 = ( V_328 -> V_133 == V_358 &&
strncmp ( V_353 , F_146 ,
F_147 ) == 0 ) ;
}
F_67 ( V_352 ) ;
return 0 ;
V_354:
F_67 ( V_352 ) ;
return 1 ;
}
static int F_149 ( struct V_1 * V_8 , struct V_57 * V_28 )
{
int V_51 ;
for ( V_51 = 0 ; V_359 [ V_51 ] ; V_51 ++ )
if ( strncmp ( V_28 -> V_145 , V_359 [ V_51 ] ,
strlen ( V_359 [ V_51 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_150 ( struct V_1 * V_8 ,
T_4 * V_360 , struct V_57 * V_28 )
{
T_3 V_67 = F_124 ( * ( ( V_361 * ) V_360 ) ) ;
if ( ! F_22 ( V_360 ) ) {
if ( F_51 ( V_360 ) )
F_137 ( V_28 , 3 , 0 , V_67 & 0x3fff ) ;
else
F_137 ( V_28 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_149 ( V_8 , V_28 ) ) {
F_137 ( V_28 ,
1 , ( V_67 >> 16 ) & 0x3fff , V_67 & 0x00ff ) ;
return;
}
F_137 ( V_28 , 0 , 0 , V_67 & 0x3fff ) ;
}
static int F_151 ( struct V_1 * V_8 ,
struct V_57 * V_362 ,
struct V_57 * V_328 , T_4 * V_360 ,
unsigned long V_363 [] , int * V_364 )
{
unsigned char V_54 [ 8 ] ;
if ( F_152 ( V_362 -> V_119 , V_363 ) )
return 0 ;
if ( ! F_22 ( V_360 ) )
return 0 ;
if ( ! F_149 ( V_8 , V_362 ) )
return 0 ;
if ( V_362 -> V_120 == 0 )
return 0 ;
memset ( V_54 , 0 , 8 ) ;
V_54 [ 3 ] = V_362 -> V_119 ;
if ( F_51 ( V_54 ) )
return 0 ;
if ( F_52 ( V_8 ) )
return 0 ;
if ( * V_364 >= V_365 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_154
L_155
L_156 ) ;
return 0 ;
}
if ( F_144 ( V_8 , V_54 , V_328 , NULL ) )
return 0 ;
( * V_364 ) ++ ;
F_137 ( V_328 ,
V_362 -> V_118 , V_362 -> V_119 , 0 ) ;
F_153 ( V_362 -> V_119 , V_363 ) ;
return 1 ;
}
static int F_154 ( struct V_1 * V_8 ,
struct V_9 * V_366 , unsigned char * V_54 )
{
struct V_367 * V_368 = NULL ;
int V_369 = 24 ;
int V_370 = 2 ;
int V_371 = sizeof( * V_368 ) + V_372 * V_369 ;
T_3 V_373 = 0 ;
int V_121 = 0 ;
T_3 V_374 ;
int V_51 ;
struct V_199 * V_375 ;
struct V_57 * V_288 ;
struct V_99 * V_376 ;
T_3 V_377 ;
T_3 V_378 ;
if ( V_366 -> V_112 != V_114 )
return 0 ;
V_376 = & V_8 -> V_100 [ V_366 -> V_96 ] ;
if ( V_376 == NULL )
return 0 ;
V_375 = (struct V_199 * ) V_366 -> V_238 ;
if ( V_375 == NULL )
return 0 ;
V_288 = V_375 -> V_28 -> V_61 ;
if ( V_288 == NULL )
return 0 ;
V_377 = F_155 ( ( T_3 ) V_288 -> V_137 ) ;
V_378 = F_155 ( ( T_3 ) V_376 -> V_378 ) ;
V_374 = V_376 -> V_378 ;
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_157 ,
V_155 , V_378 ,
V_288 -> V_69 [ 0 ] , V_288 -> V_69 [ 1 ] , V_288 -> V_69 [ 2 ] ,
V_288 -> V_69 [ 3 ] , V_288 -> V_69 [ 4 ] , V_288 -> V_69 [ 5 ] ,
V_288 -> V_69 [ 6 ] , V_288 -> V_69 [ 7 ] , V_288 -> V_69 [ 8 ] ,
V_288 -> V_69 [ 9 ] , V_288 -> V_69 [ 10 ] , V_288 -> V_69 [ 11 ] ,
V_288 -> V_69 [ 12 ] , V_288 -> V_69 [ 13 ] , V_288 -> V_69 [ 14 ] ,
V_288 -> V_69 [ 15 ] ) ;
V_368 = F_81 ( V_371 , V_154 ) ;
if ( F_135 ( V_8 , (struct V_338 * ) V_368 ,
V_371 , V_370 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_158 ,
L_60 ) ;
F_67 ( V_368 ) ;
return 0 ;
}
V_373 = F_156 ( * ( ( V_379 * ) V_368 -> V_380 ) ) /
V_369 ;
for ( V_51 = 0 ; V_51 < V_373 ; V_51 ++ ) {
if ( memcmp ( & ( (struct V_367 * )
V_368 ) -> V_248 [ V_51 ] [ 20 ] , & V_374 , 4 ) != 0 ) {
continue;
}
V_121 = 1 ;
memcpy ( V_54 , & ( (struct V_367 * )
V_368 ) -> V_248 [ V_51 ] [ 0 ] , 8 ) ;
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_159 ,
V_155 , V_374 ,
( (struct V_367 * )
V_368 ) -> V_248 [ V_51 ] [ 20 ] ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] ,
V_54 [ 3 ] , V_54 [ 4 ] , V_54 [ 5 ] ,
V_54 [ 6 ] , V_54 [ 7 ] ) ;
break;
}
F_67 ( V_368 ) ;
if ( V_121 )
return 1 ;
else
return 0 ;
}
static int F_157 ( struct V_1 * V_8 ,
int V_381 ,
struct V_338 * V_382 , T_3 * V_373 , int * V_383 ,
struct V_338 * V_384 , T_3 * V_385 )
{
int V_386 = 8 ;
* V_383 = 0 ;
if ( V_8 -> V_48 & V_78 ||
V_8 -> V_48 & V_387 ) {
* V_383 = V_388 ;
V_386 = 24 ;
}
if ( F_135 ( V_8 , V_382 , V_381 ,
* V_383 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_160 ) ;
return - 1 ;
}
* V_373 = F_156 ( * ( ( V_379 * ) V_382 -> V_380 ) ) /
V_386 ;
if ( * V_373 > V_372 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_161
L_162 , V_372 ,
* V_373 - V_372 ) ;
* V_373 = V_372 ;
}
if ( F_136 ( V_8 , V_384 , V_381 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_163 ) ;
return - 1 ;
}
* V_385 = F_156 ( * ( ( V_379 * ) V_384 -> V_380 ) ) / 8 ;
if ( * V_385 > V_389 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_164
L_165 , V_389 ,
* V_385 - V_389 ) ;
* V_385 = V_389 ;
}
if ( * V_385 + * V_373 > V_372 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_166
L_165 , V_372 ,
* V_373 + * V_385 - V_372 ) ;
* V_385 = V_372 - * V_373 ;
}
return 0 ;
}
T_4 * F_158 ( struct V_1 * V_8 , int V_390 , int V_51 ,
int V_373 , int V_385 ,
struct V_367 * V_391 ,
struct V_338 * V_392 )
{
int V_393 = V_373 + ( V_390 == 0 ) ;
int V_394 = V_373 + V_385 + ( V_390 == 0 ) ;
if ( V_51 == V_390 )
return V_117 ;
if ( V_51 < V_393 )
return & V_391 -> V_248 [ V_51 - ( V_390 == 0 ) ] [ 0 ] ;
if ( V_51 < V_394 )
return & V_392 -> V_248 [ V_51 - V_373 -
( V_390 == 0 ) ] [ 0 ] ;
F_159 () ;
return NULL ;
}
static int F_160 ( struct V_1 * V_8 )
{
int V_291 ;
struct V_297 * V_395 ;
V_395 = F_81 ( sizeof( struct V_297 ) ,
V_154 ) ;
if ( ! V_395 )
return 0 ;
V_291 = F_120 ( V_8 , V_117 , 0 , V_395 ,
sizeof( struct V_297 ) ) ;
if ( V_291 != 0 ) {
F_67 ( V_395 ) ;
return 0 ;
}
return V_395 -> V_396 & ( 1 << 3 ) ? 1 : 0 ;
}
static void F_161 ( struct V_1 * V_8 , int V_125 )
{
struct V_367 * V_391 = NULL ;
struct V_338 * V_392 = NULL ;
T_3 V_373 = 0 ;
T_3 V_385 = 0 ;
int V_383 = 0 ;
T_3 V_397 = 0 ;
struct V_57 * * V_398 , * V_328 , * V_362 ;
int V_399 = 0 ;
int V_381 = sizeof( * V_391 ) + V_372 * 24 ;
int V_51 , V_364 , V_400 ;
int V_390 ;
T_4 V_401 ;
F_54 ( V_363 , V_365 ) ;
V_398 = F_81 ( sizeof( * V_398 ) * V_123 , V_154 ) ;
V_391 = F_81 ( V_381 , V_154 ) ;
V_392 = F_81 ( V_381 , V_154 ) ;
V_362 = F_81 ( sizeof( * V_362 ) , V_154 ) ;
if ( ! V_398 || ! V_391 || ! V_392 || ! V_362 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_167 ) ;
goto V_295;
}
memset ( V_363 , 0 , sizeof( V_363 ) ) ;
V_401 = F_160 ( V_8 ) ;
if ( ! V_8 -> V_402 && V_401 )
F_5 ( & V_8 -> V_15 -> V_16 , L_168 ) ;
else if ( V_8 -> V_402 && ! V_401 )
F_5 ( & V_8 -> V_15 -> V_16 , L_169 ) ;
V_8 -> V_402 = V_401 ;
if ( F_157 ( V_8 , V_381 ,
(struct V_338 * ) V_391 , & V_373 ,
& V_383 , V_392 , & V_385 ) )
goto V_295;
V_400 = V_373 + V_385 + V_365 + 1 ;
for ( V_51 = 0 ; V_51 < V_400 ; V_51 ++ ) {
if ( V_51 >= V_123 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_170
L_171 , V_123 ,
V_400 - V_123 ) ;
break;
}
V_398 [ V_51 ] = F_81 ( sizeof( * V_398 [ V_51 ] ) , V_154 ) ;
if ( ! V_398 [ V_51 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_172 ,
__FILE__ , __LINE__ ) ;
goto V_295;
}
V_397 ++ ;
}
if ( F_33 ( F_52 ( V_8 ) ) )
V_390 = 0 ;
else
V_390 = V_373 + V_385 ;
V_364 = 0 ;
for ( V_51 = 0 ; V_51 < V_373 + V_385 + 1 ; V_51 ++ ) {
T_4 * V_360 , V_403 = 0 ;
V_360 = F_158 ( V_8 , V_390 ,
V_51 , V_373 , V_385 , V_391 , V_392 ) ;
if ( V_360 [ 3 ] & 0xC0 &&
V_51 < V_373 + ( V_390 == 0 ) )
continue;
if ( F_144 ( V_8 , V_360 , V_362 ,
& V_403 ) )
continue;
F_150 ( V_8 , V_360 , V_362 ) ;
V_328 = V_398 [ V_399 ] ;
if ( F_151 ( V_8 , V_362 , V_328 ,
V_360 , V_363 ,
& V_364 ) ) {
V_399 ++ ;
V_328 = V_398 [ V_399 ] ;
}
* V_328 = * V_362 ;
switch ( V_328 -> V_133 ) {
case V_358 :
if ( V_403 )
V_399 ++ ;
break;
case V_355 :
if ( V_8 -> V_402 ) {
V_328 -> V_70 = 0 ;
V_399 ++ ;
break;
} else if ( V_8 -> V_41 ) {
if ( V_51 >= V_373 ) {
V_399 ++ ;
break;
}
} else {
if ( V_51 < V_373 )
break;
V_399 ++ ;
break;
}
if ( V_383 == V_388 ) {
memcpy ( & V_328 -> V_137 ,
& V_360 [ 20 ] ,
sizeof( V_328 -> V_137 ) ) ;
V_399 ++ ;
}
break;
case V_404 :
case V_405 :
V_399 ++ ;
break;
case V_406 :
if ( ! F_51 ( V_360 ) )
break;
V_399 ++ ;
break;
default:
break;
}
if ( V_399 >= V_123 )
break;
}
F_80 ( V_8 , V_125 , V_398 , V_399 ) ;
V_295:
F_67 ( V_362 ) ;
for ( V_51 = 0 ; V_51 < V_397 ; V_51 ++ )
F_67 ( V_398 [ V_51 ] ) ;
F_67 ( V_398 ) ;
F_67 ( V_391 ) ;
F_67 ( V_392 ) ;
}
static int F_162 ( struct V_1 * V_8 ,
struct V_9 * V_94 ,
struct V_199 * V_200 )
{
unsigned int V_34 ;
struct V_407 * V_408 ;
T_5 V_275 ;
int V_409 , V_51 , V_410 , V_411 ;
struct V_182 * V_412 ;
F_63 ( F_104 ( V_200 ) > V_8 -> V_413 ) ;
V_409 = F_163 ( V_200 ) ;
if ( V_409 < 0 )
return V_409 ;
if ( ! V_409 )
goto V_414;
V_412 = V_94 -> V_186 ;
V_411 = 0 ;
V_410 = 0 ;
F_164 (cmd, sg, use_sg, i) {
if ( V_51 == V_8 -> V_187 - 1 &&
V_409 > V_8 -> V_187 ) {
V_411 = 1 ;
V_412 = V_8 -> V_177 [ V_94 -> V_96 ] ;
V_410 = 0 ;
}
V_275 = ( T_5 ) F_165 ( V_408 ) ;
V_34 = F_166 ( V_408 ) ;
V_412 -> V_193 . V_194 = ( T_3 ) ( V_275 & 0x0FFFFFFFFULL ) ;
V_412 -> V_193 . V_195 = ( T_3 ) ( ( V_275 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_412 -> V_190 = V_34 ;
V_412 -> V_188 = ( V_51 < F_104 ( V_200 ) - 1 ) ? 0 : V_279 ;
V_412 ++ ;
}
if ( V_409 + V_411 > V_8 -> V_415 )
V_8 -> V_415 = V_409 + V_411 ;
if ( V_411 ) {
V_94 -> V_88 . V_89 = V_8 -> V_187 ;
V_94 -> V_88 . V_191 = ( V_280 ) ( V_409 + 1 ) ;
if ( F_93 ( V_8 , V_94 ) ) {
F_102 ( V_200 ) ;
return - 1 ;
}
return 0 ;
}
V_414:
V_94 -> V_88 . V_89 = ( T_4 ) V_409 ;
V_94 -> V_88 . V_191 = ( V_280 ) V_409 ;
return 0 ;
}
static int F_167 ( T_4 * V_103 , int * V_416 )
{
int V_417 = 0 ;
T_3 V_418 ;
T_3 V_419 ;
switch ( V_103 [ 0 ] ) {
case V_420 :
case V_421 :
V_417 = 1 ;
case V_422 :
case V_423 :
if ( * V_416 == 6 ) {
V_418 = ( ( ( T_3 ) V_103 [ 2 ] ) << 8 ) | V_103 [ 3 ] ;
V_419 = V_103 [ 4 ] ;
} else {
F_63 ( * V_416 != 12 ) ;
V_418 = ( ( ( T_3 ) V_103 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 4 ] ) << 8 ) |
V_103 [ 5 ] ;
V_419 =
( ( ( T_3 ) V_103 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 8 ] ) << 8 ) |
V_103 [ 9 ] ;
}
if ( V_419 > 0xffff )
return V_424 ;
V_103 [ 0 ] = V_417 ? V_425 : V_426 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_418 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_418 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_418 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_418 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_419 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_419 ) ;
V_103 [ 9 ] = 0 ;
* V_416 = 10 ;
break;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_416 ,
T_4 * V_54 )
{
struct V_199 * V_200 = V_10 -> V_238 ;
struct V_93 * V_94 = & V_8 -> V_95 [ V_10 -> V_96 ] ;
unsigned int V_34 ;
unsigned int V_427 = 0 ;
struct V_407 * V_408 ;
T_5 V_275 ;
int V_409 , V_51 ;
struct V_182 * V_412 ;
T_3 V_428 = V_429 ;
if ( F_104 ( V_200 ) > V_8 -> V_430 )
return V_424 ;
F_63 ( V_200 -> V_431 > V_432 ) ;
if ( F_167 ( V_103 , & V_416 ) )
return V_424 ;
V_10 -> V_112 = V_113 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_433 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_63 ( V_10 -> V_86 & 0x0000007F ) ;
V_409 = F_163 ( V_200 ) ;
if ( V_409 < 0 )
return V_409 ;
if ( V_409 ) {
V_412 = V_94 -> V_186 ;
F_164 (cmd, sg, use_sg, i) {
V_275 = ( T_5 ) F_165 ( V_408 ) ;
V_34 = F_166 ( V_408 ) ;
V_427 += V_34 ;
V_412 -> V_193 . V_194 = ( T_3 ) ( V_275 & 0x0FFFFFFFFULL ) ;
V_412 -> V_193 . V_195 =
( T_3 ) ( ( V_275 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_412 -> V_190 = V_34 ;
if ( V_51 == ( F_104 ( V_200 ) - 1 ) )
V_412 -> V_188 = V_279 ;
else
V_412 -> V_188 = 0 ;
V_412 ++ ;
}
switch ( V_200 -> V_434 ) {
case V_435 :
V_428 |= V_436 ;
break;
case V_437 :
V_428 |= V_438 ;
break;
case V_439 :
V_428 |= V_440 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_173 ,
V_200 -> V_434 ) ;
F_159 () ;
break;
}
} else {
V_428 |= V_440 ;
}
V_10 -> V_88 . V_89 = V_409 ;
V_94 -> V_441 = V_137 & 0xFFFF ;
V_94 -> V_442 = V_427 ;
V_94 -> V_245 = V_443 |
( V_416 & V_246 ) ;
V_94 -> V_428 = V_428 ;
memcpy ( V_94 -> V_107 , V_103 , V_416 ) ;
memcpy ( V_94 -> V_250 , V_54 , 8 ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_199 * V_200 = V_10 -> V_238 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
return F_170 ( V_8 , V_10 , V_16 -> V_137 ,
V_200 -> V_256 , V_200 -> V_431 , V_16 -> V_54 ) ;
}
static void F_171 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_99 * V_94 )
{
struct V_199 * V_200 = V_10 -> V_238 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
struct V_303 * V_308 = & V_16 -> V_139 ;
T_5 V_444 ;
F_63 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
if ( ! ( V_308 -> V_59 & V_325 ) )
return;
V_94 -> V_326 = V_308 -> V_326 ;
V_94 -> V_445 |= V_446 ;
switch ( V_200 -> V_256 [ 0 ] ) {
case V_420 :
case V_422 :
if ( V_308 -> V_315 == 512 ) {
V_94 -> V_447 =
( ( ( T_3 ) V_200 -> V_256 [ 2 ] ) << 8 ) |
V_200 -> V_256 [ 3 ] ;
V_94 -> V_448 = 0 ;
} else {
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 8 ) |
V_200 -> V_256 [ 3 ] ;
V_444 = ( V_444 * V_308 -> V_315 ) / 512 ;
V_94 -> V_447 = ( T_3 ) V_444 ;
V_94 -> V_448 = ( T_3 ) ( V_444 >> 32 ) ;
}
break;
case V_425 :
case V_426 :
if ( V_308 -> V_315 == 512 ) {
V_94 -> V_447 =
( ( ( T_3 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_94 -> V_448 = 0 ;
} else {
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_444 = ( V_444 * V_308 -> V_315 ) / 512 ;
V_94 -> V_447 = ( T_3 ) V_444 ;
V_94 -> V_448 = ( T_3 ) ( V_444 >> 32 ) ;
}
break;
case V_421 :
case V_423 :
if ( V_308 -> V_315 == 512 ) {
V_94 -> V_447 =
( ( ( T_3 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_94 -> V_448 = 0 ;
} else {
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_444 = ( V_444 * V_308 -> V_315 ) / 512 ;
V_94 -> V_447 = ( T_3 ) V_444 ;
V_94 -> V_448 = ( T_3 ) ( V_444 >> 32 ) ;
}
break;
case V_449 :
case V_450 :
if ( V_308 -> V_315 == 512 ) {
V_94 -> V_447 =
( ( ( T_3 ) V_200 -> V_256 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 8 ] ) << 8 ) |
V_200 -> V_256 [ 9 ] ;
V_94 -> V_448 =
( ( ( T_3 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
} else {
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_200 -> V_256 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_200 -> V_256 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 8 ] ) << 8 ) |
V_200 -> V_256 [ 9 ] ;
V_444 = ( V_444 * V_308 -> V_315 ) / 512 ;
V_94 -> V_447 = ( T_3 ) V_444 ;
V_94 -> V_448 = ( T_3 ) ( V_444 >> 32 ) ;
}
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 ,
L_174 ,
V_155 ) ;
F_159 () ;
break;
}
}
static int F_172 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_416 ,
T_4 * V_54 )
{
struct V_199 * V_200 = V_10 -> V_238 ;
struct V_99 * V_94 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
struct V_451 * V_412 ;
int V_409 , V_51 ;
struct V_407 * V_408 ;
T_5 V_275 ;
T_3 V_34 ;
T_3 V_427 = 0 ;
if ( F_104 ( V_200 ) > V_8 -> V_430 )
return V_424 ;
if ( F_167 ( V_103 , & V_416 ) )
return V_424 ;
V_10 -> V_112 = V_114 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_452 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_63 ( V_10 -> V_86 & 0x0000007F ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_453 = V_454 ;
V_409 = F_163 ( V_200 ) ;
if ( V_409 < 0 )
return V_409 ;
if ( V_409 ) {
F_63 ( V_409 > V_455 ) ;
V_412 = V_94 -> V_408 ;
F_164 (cmd, sg, use_sg, i) {
V_275 = ( T_5 ) F_165 ( V_408 ) ;
V_34 = F_166 ( V_408 ) ;
V_427 += V_34 ;
V_412 -> V_456 = F_173 ( V_275 ) ;
V_412 -> V_457 = F_155 ( V_34 ) ;
V_412 -> V_458 [ 0 ] = 0 ;
V_412 -> V_458 [ 1 ] = 0 ;
V_412 -> V_458 [ 2 ] = 0 ;
V_412 -> V_459 = 0 ;
V_412 ++ ;
}
switch ( V_200 -> V_434 ) {
case V_435 :
V_94 -> V_445 &= ~ V_460 ;
V_94 -> V_445 |= V_461 ;
break;
case V_437 :
V_94 -> V_445 &= ~ V_460 ;
V_94 -> V_445 |= V_462 ;
break;
case V_439 :
V_94 -> V_445 &= ~ V_460 ;
V_94 -> V_445 |= V_463 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_173 ,
V_200 -> V_434 ) ;
F_159 () ;
break;
}
} else {
V_94 -> V_445 &= ~ V_460 ;
V_94 -> V_445 |= V_463 ;
}
F_171 ( V_8 , V_10 , V_94 ) ;
V_94 -> V_378 = V_137 ;
V_94 -> V_247 = ( V_10 -> V_96 << V_464 ) |
V_465 ;
memcpy ( V_94 -> V_103 , V_103 , sizeof( V_94 -> V_103 ) ) ;
V_94 -> V_102 = ( T_4 ) V_409 ;
V_94 -> V_202 = F_155 ( V_427 ) ;
V_94 -> V_466 = F_173 ( V_10 -> V_86 +
F_174 ( struct V_99 , V_204 ) ) ;
V_94 -> V_467 = F_155 ( ( T_3 ) sizeof( V_94 -> V_204 ) ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_416 ,
T_4 * V_54 )
{
if ( V_8 -> V_48 & V_78 )
return F_168 ( V_8 , V_10 , V_137 ,
V_103 , V_416 , V_54 ) ;
else
return F_172 ( V_8 , V_10 , V_137 ,
V_103 , V_416 , V_54 ) ;
}
static void F_175 ( struct V_303 * V_308 ,
int V_138 , T_3 * V_468 , T_3 * V_469 )
{
if ( V_138 == 0 ) {
* V_468 %= V_308 -> V_322 ;
return;
}
do {
* V_469 = * V_468 / V_308 -> V_322 ;
if ( V_138 == * V_469 )
continue;
if ( * V_469 < ( V_308 -> V_324 - 1 ) ) {
* V_468 += V_308 -> V_322 ;
( * V_469 ) ++ ;
} else {
* V_468 %= V_308 -> V_322 ;
* V_469 = 0 ;
}
} while ( V_138 != * V_469 );
}
static int F_176 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_199 * V_200 = V_10 -> V_238 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
struct V_303 * V_308 = & V_16 -> V_139 ;
struct V_305 * V_306 = & V_308 -> V_307 [ 0 ] ;
int V_417 = 0 ;
T_3 V_468 ;
T_5 V_444 , V_470 ;
T_3 V_419 ;
T_3 V_471 ;
T_5 V_472 , V_473 ;
T_3 V_474 , V_475 ;
T_3 V_476 , V_477 ;
T_5 V_478 , V_479 ;
T_3 V_480 ;
T_5 V_481 , V_482 ;
T_3 V_483 , V_484 ;
T_3 V_485 , V_486 ;
T_3 V_487 ;
T_3 V_488 ;
T_3 V_489 , V_490 , V_469 ;
T_3 V_491 ;
T_3 V_492 ;
T_5 V_493 ;
T_3 V_494 ;
T_4 V_103 [ 16 ] ;
T_4 V_416 ;
#if V_495 == 32
T_5 V_496 ;
#endif
int V_138 ;
F_63 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
switch ( V_200 -> V_256 [ 0 ] ) {
case V_420 :
V_417 = 1 ;
case V_422 :
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 8 ) |
V_200 -> V_256 [ 3 ] ;
V_419 = V_200 -> V_256 [ 4 ] ;
break;
case V_425 :
V_417 = 1 ;
case V_426 :
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_419 =
( ( ( T_3 ) V_200 -> V_256 [ 7 ] ) << 8 ) |
V_200 -> V_256 [ 8 ] ;
break;
case V_421 :
V_417 = 1 ;
case V_423 :
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 8 ) |
V_200 -> V_256 [ 5 ] ;
V_419 =
( ( ( T_3 ) V_200 -> V_256 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 8 ] ) << 8 ) |
V_200 -> V_256 [ 9 ] ;
break;
case V_449 :
V_417 = 1 ;
case V_450 :
V_444 =
( ( ( T_5 ) V_200 -> V_256 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_200 -> V_256 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_200 -> V_256 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_200 -> V_256 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_200 -> V_256 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_256 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_256 [ 8 ] ) << 8 ) |
V_200 -> V_256 [ 9 ] ;
V_419 =
( ( ( T_3 ) V_200 -> V_256 [ 10 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_256 [ 11 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_256 [ 12 ] ) << 8 ) |
V_200 -> V_256 [ 13 ] ;
break;
default:
return V_424 ;
}
F_63 ( V_419 == 0 ) ;
V_470 = V_444 + V_419 - 1 ;
if ( V_417 && V_16 -> V_64 != 0 )
return V_424 ;
if ( V_470 >= V_308 -> V_316 || V_470 < V_444 )
return V_424 ;
V_471 = V_308 -> V_322 * V_308 -> V_319 ;
#if V_495 == 32
V_496 = V_444 ;
( void ) F_177 ( V_496 , V_471 ) ;
V_472 = V_496 ;
V_496 = V_470 ;
( void ) F_177 ( V_496 , V_471 ) ;
V_473 = V_496 ;
V_474 = ( T_3 ) ( V_444 - ( V_472 * V_471 ) ) ;
V_475 = ( T_3 ) ( V_470 - ( V_473 * V_471 ) ) ;
V_496 = V_474 ;
( void ) F_177 ( V_496 , V_308 -> V_319 ) ;
V_476 = V_496 ;
V_496 = V_475 ;
( void ) F_177 ( V_496 , V_308 -> V_319 ) ;
V_477 = V_496 ;
#else
V_472 = V_444 / V_471 ;
V_473 = V_470 / V_471 ;
V_474 = ( T_3 ) ( V_444 - ( V_472 * V_471 ) ) ;
V_475 = ( T_3 ) ( V_470 - ( V_473 * V_471 ) ) ;
V_476 = V_474 / V_308 -> V_319 ;
V_477 = V_475 / V_308 -> V_319 ;
#endif
if ( ( V_472 != V_473 ) || ( V_476 != V_477 ) )
return V_424 ;
V_487 = V_308 -> V_322 +
V_308 -> V_323 ;
V_491 = ( ( T_3 ) ( V_472 >> V_308 -> V_318 ) ) %
V_308 -> V_312 ;
V_468 = ( V_491 * V_487 ) + V_476 ;
switch ( V_16 -> V_64 ) {
case V_497 :
break;
case V_498 :
F_63 ( V_308 -> V_324 != 2 ) ;
if ( V_16 -> V_138 )
V_468 += V_308 -> V_322 ;
V_16 -> V_138 = ! V_16 -> V_138 ;
break;
case V_499 :
F_63 ( V_308 -> V_324 != 3 ) ;
V_138 = V_16 -> V_138 ;
F_175 ( V_308 , V_138 ,
& V_468 , & V_469 ) ;
V_138 =
( V_138 >= V_308 -> V_324 - 1 )
? 0 : V_138 + 1 ;
F_63 ( V_138 >= V_308 -> V_324 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_175 ,
V_468 , V_138 ) ;
V_16 -> V_138 = V_138 ;
break;
case V_500 :
case V_501 :
if ( V_308 -> V_324 <= 1 )
break;
V_480 =
V_308 -> V_319 * V_308 -> V_322 ;
F_63 ( V_480 == 0 ) ;
V_488 = V_480 * V_308 -> V_324 ;
#if V_495 == 32
V_496 = V_444 ;
V_489 = F_177 ( V_496 , V_488 ) ;
V_496 = V_489 ;
( void ) F_177 ( V_496 , V_480 ) ;
V_489 = V_496 ;
V_496 = V_470 ;
V_490 = F_177 ( V_496 , V_488 ) ;
V_496 = V_490 ;
( void ) F_177 ( V_496 , V_480 ) ;
V_490 = V_496 ;
#else
V_489 = ( V_444 % V_488 ) / V_480 ;
V_490 = ( V_470 % V_488 ) / V_480 ;
#endif
if ( V_489 != V_490 )
return V_424 ;
#if V_495 == 32
V_496 = V_444 ;
( void ) F_177 ( V_496 , V_488 ) ;
V_472 = V_481 = V_478 = V_496 ;
V_496 = V_470 ;
( void ) F_177 ( V_496 , V_488 ) ;
V_482 = V_479 = V_496 ;
#else
V_472 = V_481 = V_478 =
V_444 / V_488 ;
V_482 = V_479 = V_470 / V_488 ;
#endif
if ( V_481 != V_482 )
return V_424 ;
#if V_495 == 32
V_496 = V_444 ;
V_474 = F_177 ( V_496 , V_488 ) ;
V_496 = V_474 ;
V_474 = ( T_3 ) F_177 ( V_496 , V_480 ) ;
V_483 = V_474 ;
V_496 = V_470 ;
V_484 = F_177 ( V_496 , V_488 ) ;
V_496 = V_484 ;
V_484 = F_177 ( V_496 , V_480 ) ;
V_496 = V_483 ;
( void ) F_177 ( V_496 , V_308 -> V_319 ) ;
V_476 = V_485 = V_496 ;
V_496 = V_484 ;
( void ) F_177 ( V_496 , V_308 -> V_319 ) ;
V_486 = V_496 ;
#else
V_474 = V_483 =
( T_3 ) ( ( V_444 % V_488 ) %
V_480 ) ;
V_484 =
( T_3 ) ( ( V_470 % V_488 ) %
V_480 ) ;
V_476 = V_485 =
V_483 / V_308 -> V_319 ;
V_486 =
V_484 / V_308 -> V_319 ;
#endif
if ( V_485 != V_486 )
return V_424 ;
V_491 = ( ( T_3 ) ( V_472 >> V_308 -> V_318 ) ) %
V_308 -> V_312 ;
V_468 = ( V_489 *
( V_308 -> V_312 * V_487 ) ) +
( V_491 * V_487 ) + V_476 ;
break;
default:
return V_424 ;
}
V_492 = V_306 [ V_468 ] . V_137 ;
V_493 = V_308 -> V_320 + ( V_472 * V_308 -> V_319 ) +
( V_474 - ( V_476 * V_308 -> V_319 ) ) ;
V_494 = V_419 ;
if ( V_308 -> V_317 ) {
V_493 <<= V_308 -> V_317 ;
V_494 <<= V_308 -> V_317 ;
}
F_63 ( V_494 > 0xffff ) ;
if ( V_493 > 0xffffffff ) {
V_103 [ 0 ] = V_417 ? V_449 : V_450 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_493 >> 56 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_493 >> 48 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_493 >> 40 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_493 >> 32 ) ;
V_103 [ 6 ] = ( T_4 ) ( V_493 >> 24 ) ;
V_103 [ 7 ] = ( T_4 ) ( V_493 >> 16 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_493 >> 8 ) ;
V_103 [ 9 ] = ( T_4 ) ( V_493 ) ;
V_103 [ 10 ] = ( T_4 ) ( V_494 >> 24 ) ;
V_103 [ 11 ] = ( T_4 ) ( V_494 >> 16 ) ;
V_103 [ 12 ] = ( T_4 ) ( V_494 >> 8 ) ;
V_103 [ 13 ] = ( T_4 ) ( V_494 ) ;
V_103 [ 14 ] = 0 ;
V_103 [ 15 ] = 0 ;
V_416 = 16 ;
} else {
V_103 [ 0 ] = V_417 ? V_425 : V_426 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_493 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_493 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_493 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_493 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_494 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_494 ) ;
V_103 [ 9 ] = 0 ;
V_416 = 10 ;
}
return F_170 ( V_8 , V_10 , V_492 , V_103 , V_416 ,
V_16 -> V_54 ) ;
}
static int F_178 ( struct V_199 * V_200 ,
void (* F_179)( struct V_199 * ) )
{
struct V_1 * V_8 ;
struct V_57 * V_16 ;
unsigned char V_54 [ 8 ] ;
struct V_9 * V_10 ;
unsigned long V_59 ;
int V_291 = 0 ;
V_8 = F_1 ( V_200 -> V_28 ) ;
V_16 = V_200 -> V_28 -> V_61 ;
if ( ! V_16 ) {
V_200 -> V_215 = V_257 << 16 ;
F_179 ( V_200 ) ;
return 0 ;
}
memcpy ( V_54 , V_16 -> V_54 , sizeof( V_54 ) ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
if ( F_33 ( V_8 -> V_283 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_200 -> V_215 = V_262 << 16 ;
F_179 ( V_200 ) ;
return 0 ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_10 = F_143 ( V_8 ) ;
if ( V_10 == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_176 ) ;
return V_502 ;
}
V_200 -> V_228 = F_179 ;
V_200 -> V_503 = ( unsigned char * ) V_10 ;
V_10 -> V_112 = V_239 ;
V_10 -> V_238 = V_200 ;
if ( F_35 ( V_200 -> V_504 == 0 &&
V_200 -> V_505 -> V_112 == V_506 &&
V_8 -> V_41 ) ) {
if ( V_16 -> V_70 ) {
V_291 = F_176 ( V_8 , V_10 ) ;
if ( V_291 == 0 )
return 0 ;
if ( V_291 < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_502 ;
}
} else if ( V_16 -> V_137 ) {
V_291 = F_169 ( V_8 , V_10 ) ;
if ( V_291 == 0 )
return 0 ;
if ( V_291 < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_502 ;
}
}
}
V_10 -> V_88 . V_91 = 0 ;
memcpy ( & V_10 -> V_88 . V_248 . V_249 [ 0 ] , & V_54 [ 0 ] , 8 ) ;
V_10 -> V_88 . V_247 . V_194 = ( V_10 -> V_96 << V_464 ) ;
V_10 -> V_88 . V_247 . V_194 |= V_465 ;
V_10 -> V_106 . V_507 = 0 ;
memset ( V_10 -> V_106 . V_107 , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
F_63 ( V_200 -> V_431 > sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_244 = V_200 -> V_431 ;
memcpy ( V_10 -> V_106 . V_107 , V_200 -> V_256 , V_200 -> V_431 ) ;
V_10 -> V_106 . Type . Type = V_294 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
switch ( V_200 -> V_434 ) {
case V_435 :
V_10 -> V_106 . Type . V_510 = V_511 ;
break;
case V_437 :
V_10 -> V_106 . Type . V_510 = V_512 ;
break;
case V_439 :
V_10 -> V_106 . Type . V_510 = V_513 ;
break;
case V_514 :
V_10 -> V_106 . Type . V_510 = V_515 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_173 ,
V_200 -> V_434 ) ;
F_159 () ;
break;
}
if ( F_162 ( V_8 , V_10 , V_200 ) < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_502 ;
}
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
if ( F_180 ( V_8 ) )
return;
while ( 1 ) {
F_25 ( & V_8 -> V_516 , V_59 ) ;
if ( V_8 -> V_517 )
break;
F_26 ( & V_8 -> V_516 , V_59 ) ;
F_181 ( V_8 -> V_518 , V_8 -> V_517 ) ;
}
V_8 -> V_517 = 0 ;
F_26 ( & V_8 -> V_516 , V_59 ) ;
if ( F_180 ( V_8 ) )
return;
F_161 ( V_8 , V_8 -> V_44 -> V_159 ) ;
F_25 ( & V_8 -> V_516 , V_59 ) ;
V_8 -> V_517 = 1 ;
F_182 ( & V_8 -> V_518 ) ;
F_26 ( & V_8 -> V_516 , V_59 ) ;
}
static int F_183 ( struct V_6 * V_7 ,
unsigned long V_519 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
int V_520 ;
F_25 ( & V_8 -> V_516 , V_59 ) ;
V_520 = V_8 -> V_517 ;
F_26 ( & V_8 -> V_516 , V_59 ) ;
return V_520 ;
}
static int F_184 ( struct V_2 * V_3 ,
int V_521 , int V_522 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_522 != V_523 )
return - V_524 ;
if ( V_521 < 1 )
V_521 = 1 ;
else
if ( V_521 > V_8 -> V_178 )
V_521 = V_8 -> V_178 ;
F_185 ( V_3 , F_186 ( V_3 ) , V_521 ) ;
return V_3 -> V_525 ;
}
static void F_187 ( struct V_1 * V_8 )
{
F_188 ( V_8 -> V_44 ) ;
F_189 ( V_8 -> V_44 ) ;
V_8 -> V_44 = NULL ;
}
static int F_190 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_191 ( & V_526 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_527;
V_7 -> V_528 = 0 ;
V_7 -> V_529 = 0 ;
V_7 -> V_530 = - 1 ;
V_7 -> V_531 = 3 ;
V_7 -> V_532 = V_533 ;
V_7 -> V_534 = V_389 ;
V_7 -> V_535 = V_389 ;
V_7 -> V_536 = V_8 -> V_178 ;
if ( V_8 -> V_402 )
V_7 -> V_537 = 7 ;
else
V_7 -> V_537 = V_8 -> V_178 ;
V_7 -> V_538 = V_8 -> V_413 ;
V_8 -> V_44 = V_7 ;
V_7 -> V_61 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_539 = V_8 -> V_540 [ V_8 -> V_541 ] ;
V_7 -> V_542 = V_7 -> V_539 ;
error = F_192 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_543;
F_193 ( V_7 ) ;
return 0 ;
V_543:
F_59 ( & V_8 -> V_15 -> V_16 , L_177
L_178 , V_155 , V_8 -> V_18 ) ;
F_189 ( V_7 ) ;
return error ;
V_527:
F_59 ( & V_8 -> V_15 -> V_16 , L_179
L_178 , V_155 , V_8 -> V_18 ) ;
return - V_180 ;
}
static int F_194 ( struct V_1 * V_8 ,
unsigned char V_544 [] )
{
int V_291 ;
int V_32 = 0 ;
int V_545 = 1 ;
struct V_9 * V_10 ;
V_10 = F_117 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_51
L_180 ) ;
return V_546 ;
}
while ( V_32 < V_547 ) {
F_113 ( 1000 * V_545 ) ;
V_32 ++ ;
V_291 = 0 ;
if ( V_545 < V_548 )
V_545 = V_545 * 2 ;
( void ) F_118 ( V_10 , V_350 , V_8 ,
NULL , 0 , 0 , V_544 , V_294 ) ;
F_108 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_23 == V_549 )
break;
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 == V_216 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_550 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_181
L_182 , V_545 ) ;
V_291 = 1 ;
}
if ( V_291 )
F_5 ( & V_8 -> V_15 -> V_16 , L_183 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_184 ) ;
F_119 ( V_8 , V_10 ) ;
return V_291 ;
}
static int F_195 ( struct V_199 * V_551 )
{
int V_291 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
V_8 = F_1 ( V_551 -> V_28 ) ;
if ( V_8 == NULL )
return V_552 ;
V_16 = V_551 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_185
L_186 ) ;
return V_552 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_291 = F_121 ( V_8 , V_16 -> V_54 , V_553 ) ;
if ( V_291 == 0 && F_194 ( V_8 , V_16 -> V_54 ) == 0 )
return V_554 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_188 ) ;
return V_552 ;
}
static void F_196 ( T_4 * V_555 )
{
T_4 V_556 [ 8 ] ;
memcpy ( V_556 , V_555 , 8 ) ;
V_555 [ 0 ] = V_556 [ 3 ] ;
V_555 [ 1 ] = V_556 [ 2 ] ;
V_555 [ 2 ] = V_556 [ 1 ] ;
V_555 [ 3 ] = V_556 [ 0 ] ;
V_555 [ 4 ] = V_556 [ 7 ] ;
V_555 [ 5 ] = V_556 [ 6 ] ;
V_555 [ 6 ] = V_556 [ 5 ] ;
V_555 [ 7 ] = V_556 [ 4 ] ;
}
static void F_197 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 * V_557 , T_3 * V_558 )
{
if ( V_10 -> V_112 == V_113 ) {
struct V_93 * V_559 = (struct V_93 * )
& V_8 -> V_95 [ V_10 -> V_96 ] ;
* V_558 = V_559 -> V_247 . V_195 ;
* V_557 = V_559 -> V_247 . V_194 ;
return;
}
if ( V_10 -> V_112 == V_114 ) {
struct V_99 * V_560 = (struct V_99 * )
& V_8 -> V_100 [ V_10 -> V_96 ] ;
memset ( V_558 , 0 , sizeof( * V_558 ) ) ;
* V_557 = V_560 -> V_247 ;
return;
}
* V_558 = V_10 -> V_88 . V_247 . V_195 ;
* V_557 = V_10 -> V_88 . V_247 . V_194 ;
}
static int F_198 ( struct V_1 * V_8 , unsigned char * V_54 ,
struct V_9 * abort , int V_561 )
{
int V_291 = V_292 ;
struct V_9 * V_10 ;
struct V_232 * V_233 ;
T_3 V_558 , V_557 ;
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
return - V_180 ;
}
( void ) F_118 ( V_10 , V_562 , V_8 , abort ,
0 , 0 , V_54 , V_301 ) ;
if ( V_561 )
F_196 ( & V_10 -> V_106 . V_107 [ 4 ] ) ;
F_108 ( V_8 , V_10 ) ;
F_197 ( V_8 , abort , & V_557 , & V_558 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_189 ,
V_155 , V_558 , V_557 ) ;
V_233 = V_10 -> V_11 ;
switch ( V_233 -> V_23 ) {
case V_549 :
break;
case V_271 :
V_291 = - 1 ;
break;
default:
F_105 ( & V_8 -> V_15 -> V_16 , L_190 ,
V_155 , V_558 , V_557 ) ;
F_115 ( V_8 , V_10 ) ;
V_291 = - 1 ;
break;
}
F_119 ( V_8 , V_10 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_191 ,
V_155 , V_558 , V_557 ) ;
return V_291 ;
}
static struct V_9 * F_199 ( struct V_1 * V_8 ,
struct V_199 * V_374 , struct V_71 * V_563 )
{
unsigned long V_59 ;
struct V_9 * V_10 = NULL ;
if ( ! V_374 )
return 0 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, queue_head, list) {
if ( V_10 -> V_238 == NULL )
continue;
if ( V_10 -> V_238 == V_374 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static struct V_9 * F_200 ( struct V_1 * V_8 ,
T_4 * V_555 , struct V_71 * V_563 )
{
unsigned long V_59 ;
struct V_9 * V_10 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, queue_head, list) {
if ( memcmp ( & V_10 -> V_88 . V_247 , V_555 , 8 ) != 0 )
continue;
F_26 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static int F_201 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
int V_291 = V_292 ;
struct V_199 * V_375 ;
struct V_57 * V_16 ;
unsigned char V_564 [ 8 ] ;
unsigned char * V_565 = & V_564 [ 0 ] ;
V_375 = (struct V_199 * ) abort -> V_238 ;
V_16 = (struct V_57 * ) ( V_375 -> V_28 -> V_61 ) ;
if ( V_16 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_192 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_193 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ,
V_54 [ 4 ] , V_54 [ 5 ] , V_54 [ 6 ] , V_54 [ 7 ] ) ;
if ( ! V_16 -> V_70 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_194 ) ;
return - 1 ;
}
if ( ! F_154 ( V_8 , abort , V_565 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_195 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_196 ,
V_565 [ 0 ] , V_565 [ 1 ] , V_565 [ 2 ] , V_565 [ 3 ] ,
V_565 [ 4 ] , V_565 [ 5 ] , V_565 [ 6 ] , V_565 [ 7 ] ) ;
V_291 = F_121 ( V_8 , V_565 , V_566 ) ;
if ( V_291 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_197 ,
V_565 [ 0 ] , V_565 [ 1 ] , V_565 [ 2 ] , V_565 [ 3 ] ,
V_565 [ 4 ] , V_565 [ 5 ] , V_565 [ 6 ] , V_565 [ 7 ] ) ;
return V_291 ;
}
if ( F_194 ( V_8 , V_565 ) != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_198 ,
V_565 [ 0 ] , V_565 [ 1 ] , V_565 [ 2 ] , V_565 [ 3 ] ,
V_565 [ 4 ] , V_565 [ 5 ] , V_565 [ 6 ] , V_565 [ 7 ] ) ;
return - 1 ;
}
F_60 ( & V_8 -> V_15 -> V_16 ,
L_199 ,
V_565 [ 0 ] , V_565 [ 1 ] , V_565 [ 2 ] , V_565 [ 3 ] ,
V_565 [ 4 ] , V_565 [ 5 ] , V_565 [ 6 ] , V_565 [ 7 ] ) ;
return V_291 ;
}
static int F_202 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
T_4 V_567 [ 8 ] ;
struct V_9 * V_10 ;
int V_291 = 0 , V_568 = 0 ;
if ( abort -> V_112 == V_114 )
return F_201 ( V_8 , V_54 , abort ) ;
memcpy ( V_567 , & abort -> V_106 . V_107 [ 4 ] , 8 ) ;
F_196 ( V_567 ) ;
V_10 = F_200 ( V_8 , V_567 , & V_8 -> V_569 ) ;
if ( V_10 != NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_200 ) ;
return F_198 ( V_8 , V_54 , abort , 0 ) ;
}
V_291 = F_198 ( V_8 , V_54 , abort , 0 ) ;
V_10 = F_199 ( V_8 , abort -> V_238 , & V_8 -> V_569 ) ;
if ( V_10 )
V_568 = F_198 ( V_8 , V_54 , abort , 1 ) ;
return V_291 && V_568 ;
}
static int F_203 ( struct V_199 * V_570 )
{
int V_51 , V_291 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
struct V_9 * abort ;
struct V_9 * V_121 ;
struct V_199 * V_571 ;
char V_572 [ 256 ] ;
int V_573 = 0 ;
T_3 V_558 , V_557 ;
V_8 = F_1 ( V_570 -> V_28 ) ;
if ( F_204 ( V_8 == NULL ,
L_201 ) )
return V_552 ;
if ( ! ( V_574 & V_8 -> V_575 ) &&
! ( V_576 & V_8 -> V_575 ) )
return V_552 ;
memset ( V_572 , 0 , sizeof( V_572 ) ) ;
V_573 += sprintf ( V_572 + V_573 , L_202 ,
V_8 -> V_44 -> V_159 , V_570 -> V_28 -> V_577 ,
V_570 -> V_28 -> V_578 , V_570 -> V_28 -> V_120 ) ;
V_16 = V_570 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_203 ,
V_572 ) ;
return V_552 ;
}
abort = (struct V_9 * ) V_570 -> V_503 ;
if ( abort == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_204 ,
V_572 ) ;
return V_552 ;
}
F_197 ( V_8 , abort , & V_557 , & V_558 ) ;
V_573 += sprintf ( V_572 + V_573 , L_205 , V_558 , V_557 ) ;
V_571 = (struct V_199 * ) abort -> V_238 ;
if ( V_571 != NULL )
V_573 += sprintf ( V_572 + V_573 , L_206 ,
V_571 -> V_256 [ 0 ] , V_571 -> V_579 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_21 , V_572 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_207 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_121 = F_199 ( V_8 , V_570 , & V_8 -> V_115 ) ;
if ( V_121 ) {
V_121 -> V_11 -> V_23 = V_265 ;
F_205 ( V_121 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_208 ,
V_572 ) ;
return V_554 ;
}
V_121 = F_199 ( V_8 , V_570 , & V_8 -> V_569 ) ;
if ( ! V_121 ) {
F_105 ( & V_8 -> V_15 -> V_16 , L_209 ,
V_572 ) ;
return V_554 ;
}
V_291 = F_202 ( V_8 , V_16 -> V_54 , abort ) ;
if ( V_291 != 0 ) {
F_105 ( & V_8 -> V_15 -> V_16 , L_210 , V_572 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_211 ,
V_8 -> V_44 -> V_159 ,
V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
return V_552 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_212 , V_572 ) ;
#define F_206 30
for ( V_51 = 0 ; V_51 < F_206 * 10 ; V_51 ++ ) {
V_121 = F_199 ( V_8 , V_570 , & V_8 -> V_569 ) ;
if ( ! V_121 )
return V_554 ;
F_113 ( 100 ) ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_213 ,
V_572 , F_206 ) ;
return V_552 ;
}
static struct V_9 * F_143 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_51 ;
union V_196 V_185 ;
V_276 V_580 , V_581 ;
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
do {
V_51 = F_57 ( V_8 -> V_582 , V_8 -> V_178 ) ;
if ( V_51 == V_8 -> V_178 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
} while ( F_207
( V_51 & ( V_495 - 1 ) ,
V_8 -> V_582 + ( V_51 / V_495 ) ) != 0 );
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_10 = V_8 -> V_583 + V_51 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_580 = V_8 -> V_584
+ V_51 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_585 + V_51 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_581 = V_8 -> V_586
+ V_51 * sizeof( * V_10 -> V_11 ) ;
V_10 -> V_96 = V_51 ;
F_208 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_580 ;
V_185 . V_198 = ( T_5 ) V_581 ;
V_10 -> V_587 . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_587 . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_587 . V_190 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_117 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_196 V_185 ;
V_276 V_580 , V_581 ;
V_10 = F_209 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_580 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_112 = V_239 ;
V_10 -> V_96 = - 1 ;
V_10 -> V_11 = F_209 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_581 ) ;
if ( V_10 -> V_11 == NULL ) {
F_210 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_580 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_208 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_580 ;
V_185 . V_198 = ( T_5 ) V_581 ;
V_10 -> V_587 . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_587 . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_587 . V_190 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_100 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_51 ;
unsigned long V_59 ;
V_51 = V_10 - V_8 -> V_583 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_211 ( V_51 & ( V_495 - 1 ) ,
V_8 -> V_582 + ( V_51 / V_495 ) ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_119 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_196 V_185 ;
V_185 . V_197 . V_194 = V_10 -> V_587 . V_193 . V_194 ;
V_185 . V_197 . V_195 = V_10 -> V_587 . V_193 . V_195 ;
F_210 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_276 ) V_185 . V_198 ) ;
F_210 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_276 ) ( V_10 -> V_86 & V_588 ) ) ;
}
static int F_212 ( struct V_2 * V_16 , int V_200 , void * V_589 )
{
T_6 T_7 * V_590 =
( T_6 T_7 * ) V_589 ;
T_8 V_591 ;
T_8 T_7 * V_592 = F_213 ( sizeof( V_591 ) ) ;
int V_593 ;
T_3 V_94 ;
memset ( & V_591 , 0 , sizeof( V_591 ) ) ;
V_593 = 0 ;
V_593 |= F_214 ( & V_591 . V_594 , & V_590 -> V_594 ,
sizeof( V_591 . V_594 ) ) ;
V_593 |= F_214 ( & V_591 . V_106 , & V_590 -> V_106 ,
sizeof( V_591 . V_106 ) ) ;
V_593 |= F_214 ( & V_591 . V_595 , & V_590 -> V_595 ,
sizeof( V_591 . V_595 ) ) ;
V_593 |= F_215 ( V_591 . V_596 , & V_590 -> V_596 ) ;
V_593 |= F_215 ( V_94 , & V_590 -> V_31 ) ;
V_591 . V_31 = F_216 ( V_94 ) ;
V_593 |= F_217 ( V_592 , & V_591 , sizeof( V_591 ) ) ;
if ( V_593 )
return - V_597 ;
V_593 = F_218 ( V_16 , V_598 , ( void * ) V_592 ) ;
if ( V_593 )
return V_593 ;
V_593 |= F_219 ( & V_590 -> V_595 , & V_592 -> V_595 ,
sizeof( V_590 -> V_595 ) ) ;
if ( V_593 )
return - V_597 ;
return V_593 ;
}
static int F_220 ( struct V_2 * V_16 ,
int V_200 , void * V_589 )
{
T_9 T_7 * V_590 =
( T_9 T_7 * ) V_589 ;
T_10 V_591 ;
T_10 T_7 * V_592 =
F_213 ( sizeof( V_591 ) ) ;
int V_593 ;
T_3 V_94 ;
memset ( & V_591 , 0 , sizeof( V_591 ) ) ;
V_593 = 0 ;
V_593 |= F_214 ( & V_591 . V_594 , & V_590 -> V_594 ,
sizeof( V_591 . V_594 ) ) ;
V_593 |= F_214 ( & V_591 . V_106 , & V_590 -> V_106 ,
sizeof( V_591 . V_106 ) ) ;
V_593 |= F_214 ( & V_591 . V_595 , & V_590 -> V_595 ,
sizeof( V_591 . V_595 ) ) ;
V_593 |= F_215 ( V_591 . V_596 , & V_590 -> V_596 ) ;
V_593 |= F_215 ( V_591 . V_599 , & V_590 -> V_599 ) ;
V_593 |= F_215 ( V_94 , & V_590 -> V_31 ) ;
V_591 . V_31 = F_216 ( V_94 ) ;
V_593 |= F_217 ( V_592 , & V_591 , sizeof( V_591 ) ) ;
if ( V_593 )
return - V_597 ;
V_593 = F_218 ( V_16 , V_600 , ( void * ) V_592 ) ;
if ( V_593 )
return V_593 ;
V_593 |= F_219 ( & V_590 -> V_595 , & V_592 -> V_595 ,
sizeof( V_590 -> V_595 ) ) ;
if ( V_593 )
return - V_597 ;
return V_593 ;
}
static int F_221 ( struct V_2 * V_16 , int V_200 , void * V_589 )
{
switch ( V_200 ) {
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
return F_218 ( V_16 , V_200 , V_589 ) ;
case V_616 :
return F_212 ( V_16 , V_200 , V_589 ) ;
case V_617 :
return F_220 ( V_16 , V_200 , V_589 ) ;
default:
return - V_618 ;
}
}
static int F_222 ( struct V_1 * V_8 , void T_7 * V_619 )
{
struct V_620 V_621 ;
if ( ! V_619 )
return - V_40 ;
V_621 . V_622 = F_223 ( V_8 -> V_15 -> V_118 ) ;
V_621 . V_118 = V_8 -> V_15 -> V_118 -> V_623 ;
V_621 . V_624 = V_8 -> V_15 -> V_625 ;
V_621 . V_50 = V_8 -> V_50 ;
if ( F_217 ( V_619 , & V_621 , sizeof( V_621 ) ) )
return - V_597 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_8 , void T_7 * V_619 )
{
T_11 V_626 ;
unsigned char V_627 , V_628 , V_629 ;
int V_291 ;
V_291 = sscanf ( V_630 , L_214 ,
& V_627 , & V_628 , & V_629 ) ;
if ( V_291 != 3 ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_215
L_216 , V_630 ) ;
V_627 = 0 ;
V_628 = 0 ;
V_629 = 0 ;
}
V_626 = ( V_627 << 16 ) | ( V_628 << 8 ) | V_629 ;
if ( ! V_619 )
return - V_40 ;
if ( F_217 ( V_619 , & V_626 , sizeof( T_11 ) ) )
return - V_597 ;
return 0 ;
}
static int F_225 ( struct V_1 * V_8 , void T_7 * V_619 )
{
T_8 V_631 ;
struct V_9 * V_10 ;
char * V_632 = NULL ;
union V_196 V_185 ;
int V_291 = 0 ;
if ( ! V_619 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_633 ;
if ( F_214 ( & V_631 , V_619 , sizeof( V_631 ) ) )
return - V_597 ;
if ( ( V_631 . V_596 < 1 ) &&
( V_631 . V_106 . Type . V_510 != V_513 ) ) {
return - V_40 ;
}
if ( V_631 . V_596 > 0 ) {
V_632 = F_78 ( V_631 . V_596 , V_154 ) ;
if ( V_632 == NULL )
return - V_597 ;
if ( V_631 . V_106 . Type . V_510 == V_511 ) {
if ( F_214 ( V_632 , V_631 . V_31 ,
V_631 . V_596 ) ) {
V_291 = - V_597 ;
goto V_634;
}
} else {
memset ( V_632 , 0 , V_631 . V_596 ) ;
}
}
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
V_291 = - V_180 ;
goto V_634;
}
V_10 -> V_112 = V_635 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_631 . V_596 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = 1 ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = 0 ;
}
memcpy ( & V_10 -> V_88 . V_248 , & V_631 . V_594 , sizeof( V_10 -> V_88 . V_248 ) ) ;
V_10 -> V_88 . V_247 . V_194 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_631 . V_106 ,
sizeof( V_10 -> V_106 ) ) ;
if ( V_631 . V_596 > 0 ) {
V_185 . V_198 = F_94 ( V_8 -> V_15 , V_632 ,
V_631 . V_596 , V_636 ) ;
if ( F_95 ( & V_8 -> V_15 -> V_16 , V_185 . V_198 ) ) {
V_10 -> V_186 [ 0 ] . V_193 . V_194 = 0 ;
V_10 -> V_186 [ 0 ] . V_193 . V_195 = 0 ;
V_10 -> V_186 [ 0 ] . V_190 = 0 ;
V_291 = - V_180 ;
goto V_295;
}
V_10 -> V_186 [ 0 ] . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_186 [ 0 ] . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_186 [ 0 ] . V_190 = V_631 . V_596 ;
V_10 -> V_186 [ 0 ] . V_188 = V_279 ;
}
F_111 ( V_8 , V_10 ) ;
if ( V_631 . V_596 > 0 )
F_106 ( V_8 -> V_15 , V_10 , 1 , V_636 ) ;
F_226 ( V_8 , V_10 ) ;
memcpy ( & V_631 . V_595 , V_10 -> V_11 ,
sizeof( V_631 . V_595 ) ) ;
if ( F_217 ( V_619 , & V_631 , sizeof( V_631 ) ) ) {
V_291 = - V_597 ;
goto V_295;
}
if ( V_631 . V_106 . Type . V_510 == V_512 &&
V_631 . V_596 > 0 ) {
if ( F_217 ( V_631 . V_31 , V_632 , V_631 . V_596 ) ) {
V_291 = - V_597 ;
goto V_295;
}
}
V_295:
F_119 ( V_8 , V_10 ) ;
V_634:
F_67 ( V_632 ) ;
return V_291 ;
}
static int F_227 ( struct V_1 * V_8 , void T_7 * V_619 )
{
T_10 * V_637 ;
struct V_9 * V_10 ;
unsigned char * * V_632 = NULL ;
int * V_638 = NULL ;
union V_196 V_185 ;
T_12 V_273 = 0 ;
int V_33 = 0 ;
int V_51 ;
T_3 V_639 ;
T_3 V_640 ;
T_12 T_7 * V_641 ;
if ( ! V_619 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_633 ;
V_637 = ( T_10 * )
F_78 ( sizeof( * V_637 ) , V_154 ) ;
if ( ! V_637 ) {
V_33 = - V_180 ;
goto V_642;
}
if ( F_214 ( V_637 , V_619 , sizeof( * V_637 ) ) ) {
V_33 = - V_597 ;
goto V_642;
}
if ( ( V_637 -> V_596 < 1 ) &&
( V_637 -> V_106 . Type . V_510 != V_513 ) ) {
V_33 = - V_40 ;
goto V_642;
}
if ( V_637 -> V_599 > V_643 ) {
V_33 = - V_40 ;
goto V_642;
}
if ( V_637 -> V_596 > V_637 -> V_599 * V_644 ) {
V_33 = - V_40 ;
goto V_642;
}
V_632 = F_81 ( V_644 * sizeof( char * ) , V_154 ) ;
if ( ! V_632 ) {
V_33 = - V_180 ;
goto V_642;
}
V_638 = F_78 ( V_644 * sizeof( int ) , V_154 ) ;
if ( ! V_638 ) {
V_33 = - V_180 ;
goto V_642;
}
V_639 = V_637 -> V_596 ;
V_641 = V_637 -> V_31 ;
while ( V_639 ) {
V_640 = ( V_639 > V_637 -> V_599 ) ? V_637 -> V_599 : V_639 ;
V_638 [ V_273 ] = V_640 ;
V_632 [ V_273 ] = F_78 ( V_640 , V_154 ) ;
if ( V_632 [ V_273 ] == NULL ) {
V_33 = - V_180 ;
goto V_642;
}
if ( V_637 -> V_106 . Type . V_510 == V_511 ) {
if ( F_214 ( V_632 [ V_273 ] , V_641 , V_640 ) ) {
V_33 = - V_180 ;
goto V_642;
}
} else
memset ( V_632 [ V_273 ] , 0 , V_640 ) ;
V_639 -= V_640 ;
V_641 += V_640 ;
V_273 ++ ;
}
V_10 = F_117 ( V_8 ) ;
if ( V_10 == NULL ) {
V_33 = - V_180 ;
goto V_642;
}
V_10 -> V_112 = V_635 ;
V_10 -> V_88 . V_91 = 0 ;
V_10 -> V_88 . V_89 = V_10 -> V_88 . V_191 = V_273 ;
memcpy ( & V_10 -> V_88 . V_248 , & V_637 -> V_594 , sizeof( V_10 -> V_88 . V_248 ) ) ;
V_10 -> V_88 . V_247 . V_194 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_637 -> V_106 , sizeof( V_10 -> V_106 ) ) ;
if ( V_637 -> V_596 > 0 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_273 ; V_51 ++ ) {
V_185 . V_198 = F_94 ( V_8 -> V_15 , V_632 [ V_51 ] ,
V_638 [ V_51 ] , V_636 ) ;
if ( F_95 ( & V_8 -> V_15 -> V_16 , V_185 . V_198 ) ) {
V_10 -> V_186 [ V_51 ] . V_193 . V_194 = 0 ;
V_10 -> V_186 [ V_51 ] . V_193 . V_195 = 0 ;
V_10 -> V_186 [ V_51 ] . V_190 = 0 ;
F_106 ( V_8 -> V_15 , V_10 , V_51 ,
V_636 ) ;
V_33 = - V_180 ;
goto V_645;
}
V_10 -> V_186 [ V_51 ] . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_186 [ V_51 ] . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_186 [ V_51 ] . V_190 = V_638 [ V_51 ] ;
V_10 -> V_186 [ V_51 ] . V_188 = V_51 < V_273 - 1 ? 0 : V_279 ;
}
}
F_111 ( V_8 , V_10 ) ;
if ( V_273 )
F_106 ( V_8 -> V_15 , V_10 , V_273 , V_636 ) ;
F_226 ( V_8 , V_10 ) ;
memcpy ( & V_637 -> V_595 , V_10 -> V_11 , sizeof( V_637 -> V_595 ) ) ;
if ( F_217 ( V_619 , V_637 , sizeof( * V_637 ) ) ) {
V_33 = - V_597 ;
goto V_645;
}
if ( V_637 -> V_106 . Type . V_510 == V_512 && V_637 -> V_596 > 0 ) {
T_12 T_7 * V_646 = V_637 -> V_31 ;
for ( V_51 = 0 ; V_51 < V_273 ; V_51 ++ ) {
if ( F_217 ( V_646 , V_632 [ V_51 ] , V_638 [ V_51 ] ) ) {
V_33 = - V_597 ;
goto V_645;
}
V_646 += V_638 [ V_51 ] ;
}
}
V_33 = 0 ;
V_645:
F_119 ( V_8 , V_10 ) ;
V_642:
if ( V_632 ) {
for ( V_51 = 0 ; V_51 < V_273 ; V_51 ++ )
F_67 ( V_632 [ V_51 ] ) ;
F_67 ( V_632 ) ;
}
F_67 ( V_638 ) ;
F_67 ( V_637 ) ;
return V_33 ;
}
static void F_226 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 != V_216 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_228 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_647 , V_59 ) ;
if ( V_8 -> V_648 >= V_649 ) {
F_26 ( & V_8 -> V_647 , V_59 ) ;
return - 1 ;
}
V_8 -> V_648 ++ ;
F_26 ( & V_8 -> V_647 , V_59 ) ;
return 0 ;
}
static void F_229 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_647 , V_59 ) ;
if ( V_8 -> V_648 <= 0 ) {
F_26 ( & V_8 -> V_647 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_217 ) ;
return;
}
V_8 -> V_648 -- ;
F_26 ( & V_8 -> V_647 , V_59 ) ;
}
static int F_218 ( struct V_2 * V_16 , int V_200 , void * V_589 )
{
struct V_1 * V_8 ;
void T_7 * V_619 = ( void T_7 * ) V_589 ;
int V_291 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_200 ) {
case V_611 :
case V_612 :
case V_613 :
F_12 ( V_8 -> V_44 ) ;
return 0 ;
case V_601 :
return F_222 ( V_8 , V_619 ) ;
case V_609 :
return F_224 ( V_8 , V_619 ) ;
case V_598 :
if ( F_228 ( V_8 ) )
return - V_650 ;
V_291 = F_225 ( V_8 , V_619 ) ;
F_229 ( V_8 ) ;
return V_291 ;
case V_600 :
if ( F_228 ( V_8 ) )
return - V_650 ;
V_291 = F_227 ( V_8 , V_619 ) ;
F_229 ( V_8 ) ;
return V_291 ;
default:
return - V_651 ;
}
}
static int F_230 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_299 )
{
struct V_9 * V_10 ;
V_10 = F_143 ( V_8 ) ;
if ( ! V_10 )
return - V_180 ;
( void ) F_118 ( V_10 , V_300 , V_8 , NULL , 0 , 0 ,
V_117 , V_301 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_299 ;
V_10 -> V_282 = NULL ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_118 ( struct V_9 * V_10 , T_4 V_200 , struct V_1 * V_8 ,
void * V_632 , T_2 V_343 , V_280 V_652 , unsigned char * V_54 ,
int V_112 )
{
int V_653 = V_513 ;
struct V_9 * V_74 ;
V_10 -> V_112 = V_635 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_632 != NULL && V_343 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = 1 ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = 0 ;
}
V_10 -> V_88 . V_247 . V_194 = V_10 -> V_86 ;
memcpy ( V_10 -> V_88 . V_248 . V_249 , V_54 , 8 ) ;
V_10 -> V_106 . Type . Type = V_112 ;
if ( V_112 == V_294 ) {
switch ( V_200 ) {
case V_293 :
if ( V_652 & V_302 ) {
V_10 -> V_106 . V_107 [ 1 ] = 0x01 ;
V_10 -> V_106 . V_107 [ 2 ] = ( V_652 & 0xff ) ;
}
V_10 -> V_106 . V_244 = 6 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_512 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_293 ;
V_10 -> V_106 . V_107 [ 4 ] = V_343 & 0xFF ;
break;
case V_340 :
case V_341 :
V_10 -> V_106 . V_244 = 12 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_512 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_200 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_343 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_343 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_343 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_343 & 0xFF ;
break;
case V_654 :
V_10 -> V_106 . V_244 = 12 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_511 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_104 ;
V_10 -> V_106 . V_107 [ 6 ] = V_655 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_343 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_343 & 0xFF ;
break;
case V_350 :
V_10 -> V_106 . V_244 = 6 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_513 ;
V_10 -> V_106 . V_507 = 0 ;
break;
case V_329 :
V_10 -> V_106 . V_244 = 12 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_512 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_656 ;
V_10 -> V_106 . V_107 [ 1 ] = V_200 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_343 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_343 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_343 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_343 & 0xFF ;
break;
case V_298 :
V_10 -> V_106 . V_244 = 10 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_512 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_657 ;
V_10 -> V_106 . V_107 [ 6 ] = V_298 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_343 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_343 >> 8 ) & 0xFF ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_218 , V_200 ) ;
F_159 () ;
return - 1 ;
}
} else if ( V_112 == V_301 ) {
switch ( V_200 ) {
case V_300 :
V_10 -> V_106 . V_244 = 16 ;
V_10 -> V_106 . Type . Type = 1 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_513 ;
V_10 -> V_106 . V_507 = 0 ;
memset ( & V_10 -> V_106 . V_107 [ 0 ] , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_107 [ 0 ] = V_200 ;
V_10 -> V_106 . V_107 [ 1 ] = V_553 ;
V_10 -> V_106 . V_107 [ 4 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 5 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 6 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 7 ] = 0x00 ;
break;
case V_562 :
V_74 = V_632 ;
F_105 ( & V_8 -> V_15 -> V_16 , L_219 ,
V_74 -> V_88 . V_247 . V_195 , V_74 -> V_88 . V_247 . V_194 ,
V_10 -> V_88 . V_247 . V_195 , V_10 -> V_88 . V_247 . V_194 ) ;
V_10 -> V_106 . V_244 = 16 ;
V_10 -> V_106 . Type . Type = V_301 ;
V_10 -> V_106 . Type . V_508 = V_509 ;
V_10 -> V_106 . Type . V_510 = V_511 ;
V_10 -> V_106 . V_507 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_658 ;
V_10 -> V_106 . V_107 [ 1 ] = V_659 ;
V_10 -> V_106 . V_107 [ 2 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 3 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 4 ] = V_74 -> V_88 . V_247 . V_194 & 0xFF ;
V_10 -> V_106 . V_107 [ 5 ] = ( V_74 -> V_88 . V_247 . V_194 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_74 -> V_88 . V_247 . V_194 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_74 -> V_88 . V_247 . V_194 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_74 -> V_88 . V_247 . V_195 & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = ( V_74 -> V_88 . V_247 . V_195 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 10 ] = ( V_74 -> V_88 . V_247 . V_195 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 11 ] = ( V_74 -> V_88 . V_247 . V_195 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 12 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 13 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 14 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 15 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_220 ,
V_200 ) ;
F_159 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_221 , V_112 ) ;
F_159 () ;
}
switch ( V_10 -> V_106 . Type . V_510 ) {
case V_512 :
V_653 = V_296 ;
break;
case V_511 :
V_653 = V_192 ;
break;
case V_513 :
V_653 = V_278 ;
break;
default:
V_653 = V_636 ;
}
if ( F_107 ( V_8 -> V_15 , V_10 , V_632 , V_343 , V_653 ) )
return - 1 ;
return 0 ;
}
static void T_13 * F_231 ( T_14 V_660 , T_14 V_343 )
{
T_14 V_661 = ( ( T_14 ) V_660 ) & V_662 ;
T_14 V_663 = ( ( T_14 ) V_660 ) - V_661 ;
void T_13 * V_664 = F_232 ( V_661 ,
V_663 + V_343 ) ;
return V_664 ? ( V_664 + V_663 ) : NULL ;
}
static void F_46 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
while ( ! F_49 ( & V_8 -> V_115 ) ) {
V_10 = F_233 ( V_8 -> V_115 . V_665 , struct V_9 , V_72 ) ;
if ( ( V_8 -> V_79 . V_666 ( V_8 ) ) ) {
V_8 -> V_667 = 1 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_222 ) ;
break;
}
V_8 -> V_667 = 0 ;
F_47 ( V_10 ) ;
V_8 -> V_116 -- ;
F_30 ( & V_8 -> V_569 , V_10 ) ;
V_8 -> V_47 ++ ;
if ( V_8 -> V_47 > V_8 -> V_668 )
V_8 -> V_668 = V_8 -> V_47 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_79 . V_669 ( V_8 , V_10 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static inline unsigned long F_234 ( struct V_1 * V_8 , T_4 V_73 )
{
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
}
static inline bool F_235 ( struct V_1 * V_8 )
{
return V_8 -> V_79 . V_670 ( V_8 ) ;
}
static inline long F_236 ( struct V_1 * V_8 )
{
return ( V_8 -> V_79 . V_670 ( V_8 ) == 0 ) ||
( V_8 -> V_671 == 0 ) ;
}
static inline int F_237 ( struct V_1 * V_8 , T_3 V_672 ,
T_3 V_673 )
{
if ( F_33 ( V_672 >= V_8 -> V_178 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_223 , V_673 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_205 ( struct V_9 * V_10 )
{
unsigned long V_59 ;
int V_674 = 0 ;
struct V_1 * V_8 = V_10 -> V_8 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_47 ( V_10 ) ;
if ( F_33 ( V_8 -> V_667 ) &&
V_8 -> V_47 < 5 )
V_674 = 1 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_43 ( V_10 -> V_8 , V_10 ) ;
if ( F_35 ( V_10 -> V_112 == V_113 || V_10 -> V_112 == V_239
|| V_10 -> V_112 == V_114 ) )
F_101 ( V_10 ) ;
else if ( V_10 -> V_112 == V_635 )
F_238 ( V_10 -> V_282 ) ;
if ( F_33 ( V_674 ) )
F_46 ( V_8 ) ;
}
static inline T_3 F_239 ( T_3 V_555 )
{
return V_555 & V_465 ;
}
static inline T_3 F_240 ( T_3 V_555 )
{
return V_555 >> V_464 ;
}
static inline T_3 F_241 ( struct V_1 * V_8 , T_3 V_555 )
{
#define F_242 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_243 0x03
if ( F_33 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_555 & ~ F_243 ;
return V_555 & ~ F_242 ;
}
static inline void F_244 ( struct V_1 * V_8 ,
T_3 V_673 )
{
T_3 V_672 ;
struct V_9 * V_10 ;
V_672 = F_240 ( V_673 ) ;
if ( ! F_237 ( V_8 , V_672 , V_673 ) ) {
V_10 = V_8 -> V_583 + V_672 ;
F_205 ( V_10 ) ;
}
}
static inline void F_245 ( struct V_1 * V_8 ,
T_3 V_673 )
{
T_3 V_555 ;
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
V_555 = F_241 ( V_8 , V_673 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_86 & 0xFFFFFFE0 ) == ( V_555 & 0xFFFFFFE0 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_205 ( V_10 ) ;
return;
}
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_237 ( V_8 , V_8 -> V_178 + 1 , V_673 ) ;
}
static int F_246 ( struct V_1 * V_8 )
{
if ( F_35 ( ! V_675 ) )
return 0 ;
if ( F_35 ( V_8 -> V_671 ) )
return 0 ;
F_60 ( & V_8 -> V_15 -> V_16 , L_224
L_225 ) ;
return 1 ;
}
static struct V_1 * F_247 ( T_4 * V_676 )
{
return F_248 ( ( V_676 - * V_676 ) , struct V_1 , V_73 [ 0 ] ) ;
}
static T_15 F_249 ( int V_539 , void * V_676 )
{
struct V_1 * V_8 = F_247 ( V_676 ) ;
T_4 V_73 = * ( T_4 * ) V_676 ;
T_3 V_673 ;
if ( F_246 ( V_8 ) )
return V_677 ;
if ( F_236 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_250 () ;
while ( F_235 ( V_8 ) ) {
V_673 = F_234 ( V_8 , V_73 ) ;
while ( V_673 != V_84 )
V_673 = F_32 ( V_8 , V_73 ) ;
}
return V_679 ;
}
static T_15 F_251 ( int V_539 , void * V_676 )
{
struct V_1 * V_8 = F_247 ( V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
if ( F_246 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_250 () ;
V_673 = F_234 ( V_8 , V_73 ) ;
while ( V_673 != V_84 )
V_673 = F_32 ( V_8 , V_73 ) ;
return V_679 ;
}
static T_15 F_252 ( int V_539 , void * V_676 )
{
struct V_1 * V_8 = F_247 ( ( T_4 * ) V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
if ( F_236 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_250 () ;
while ( F_235 ( V_8 ) ) {
V_673 = F_234 ( V_8 , V_73 ) ;
while ( V_673 != V_84 ) {
if ( F_35 ( F_239 ( V_673 ) ) )
F_244 ( V_8 , V_673 ) ;
else
F_245 ( V_8 , V_673 ) ;
V_673 = F_32 ( V_8 , V_73 ) ;
}
}
return V_679 ;
}
static T_15 F_253 ( int V_539 , void * V_676 )
{
struct V_1 * V_8 = F_247 ( V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
V_8 -> V_678 = F_250 () ;
V_673 = F_234 ( V_8 , V_73 ) ;
while ( V_673 != V_84 ) {
if ( F_35 ( F_239 ( V_673 ) ) )
F_244 ( V_8 , V_673 ) ;
else
F_245 ( V_8 , V_673 ) ;
V_673 = F_32 ( V_8 , V_73 ) ;
}
return V_679 ;
}
static int F_254 ( struct V_272 * V_15 , unsigned char V_680 ,
unsigned char type )
{
struct V_681 {
struct V_682 V_683 ;
struct V_684 V_106 ;
struct V_685 V_686 ;
};
struct V_681 * V_200 ;
static const T_2 V_687 = sizeof( * V_200 ) +
sizeof( V_200 -> V_686 ) ;
V_276 V_688 ;
T_16 V_689 , V_555 ;
void T_13 * V_690 ;
int V_51 , V_593 ;
V_690 = F_255 ( V_15 , 0 ) ;
if ( V_690 == NULL )
return - V_180 ;
V_593 = F_256 ( V_15 , F_257 ( 32 ) ) ;
if ( V_593 ) {
F_258 ( V_690 ) ;
return - V_180 ;
}
V_200 = F_209 ( V_15 , V_687 , & V_688 ) ;
if ( V_200 == NULL ) {
F_258 ( V_690 ) ;
return - V_180 ;
}
V_689 = V_688 ;
V_200 -> V_683 . V_91 = 0 ;
V_200 -> V_683 . V_89 = 0 ;
V_200 -> V_683 . V_191 = 0 ;
V_200 -> V_683 . V_247 . V_194 = V_689 ;
V_200 -> V_683 . V_247 . V_195 = 0 ;
memset ( & V_200 -> V_683 . V_248 . V_249 , 0 , 8 ) ;
V_200 -> V_106 . V_244 = 16 ;
V_200 -> V_106 . Type . Type = V_301 ;
V_200 -> V_106 . Type . V_508 = V_691 ;
V_200 -> V_106 . Type . V_510 = V_513 ;
V_200 -> V_106 . V_507 = 0 ;
V_200 -> V_106 . V_107 [ 0 ] = V_680 ;
V_200 -> V_106 . V_107 [ 1 ] = type ;
memset ( & V_200 -> V_106 . V_107 [ 2 ] , 0 , 14 ) ;
V_200 -> V_686 . V_193 . V_194 = V_689 + sizeof( * V_200 ) ;
V_200 -> V_686 . V_193 . V_195 = 0 ;
V_200 -> V_686 . V_190 = sizeof( struct V_232 ) ;
F_259 ( V_689 , V_690 + V_692 ) ;
for ( V_51 = 0 ; V_51 < V_693 ; V_51 ++ ) {
V_555 = F_260 ( V_690 + V_694 ) ;
if ( ( V_555 & ~ F_243 ) == V_689 )
break;
F_113 ( V_695 ) ;
}
F_258 ( V_690 ) ;
if ( V_51 == V_693 ) {
F_59 ( & V_15 -> V_16 , L_226 ,
V_680 , type ) ;
return - V_696 ;
}
F_210 ( V_15 , V_687 , V_200 , V_688 ) ;
if ( V_555 & V_697 ) {
F_59 ( & V_15 -> V_16 , L_227 ,
V_680 , type ) ;
return - V_698 ;
}
F_60 ( & V_15 -> V_16 , L_228 ,
V_680 , type ) ;
return 0 ;
}
static int F_261 ( struct V_272 * V_15 ,
void * T_13 V_690 , T_3 V_699 )
{
V_280 V_700 ;
int V_701 ;
if ( V_699 ) {
F_60 ( & V_15 -> V_16 , L_229 ) ;
F_259 ( V_699 , V_690 + V_702 ) ;
F_113 ( 5000 ) ;
} else {
V_701 = F_262 ( V_15 , V_703 ) ;
if ( V_701 == 0 ) {
F_59 ( & V_15 -> V_16 ,
L_230
L_231 ) ;
return - V_62 ;
}
F_60 ( & V_15 -> V_16 , L_232 ) ;
F_263 ( V_15 , V_701 + V_704 , & V_700 ) ;
V_700 &= ~ V_705 ;
V_700 |= V_706 ;
F_264 ( V_15 , V_701 + V_704 , V_700 ) ;
F_113 ( 500 ) ;
V_700 &= ~ V_705 ;
V_700 |= V_707 ;
F_264 ( V_15 , V_701 + V_704 , V_700 ) ;
F_113 ( 500 ) ;
}
return 0 ;
}
static void F_265 ( char * V_708 , int V_34 )
{
memset ( V_708 , 0 , V_34 ) ;
strncpy ( V_708 , V_17 L_233 V_630 , V_34 - 1 ) ;
}
static int F_266 ( struct V_709 T_13 * V_710 )
{
char * V_708 ;
int V_51 , V_343 = sizeof( V_710 -> V_708 ) ;
V_708 = F_78 ( V_343 , V_154 ) ;
if ( ! V_708 )
return - V_180 ;
F_265 ( V_708 , V_343 ) ;
for ( V_51 = 0 ; V_51 < V_343 ; V_51 ++ )
F_267 ( V_708 [ V_51 ] , & V_710 -> V_708 [ V_51 ] ) ;
F_67 ( V_708 ) ;
return 0 ;
}
static void F_268 ( struct V_709 T_13 * V_710 ,
unsigned char * V_711 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < sizeof( V_710 -> V_708 ) ; V_51 ++ )
V_711 [ V_51 ] = F_269 ( & V_710 -> V_708 [ V_51 ] ) ;
}
static int F_270 ( struct V_709 T_13 * V_710 )
{
char * V_711 , * V_712 ;
int V_291 , V_343 = sizeof( V_710 -> V_708 ) ;
V_712 = F_78 ( 2 * V_343 , V_154 ) ;
if ( ! V_712 )
return - V_180 ;
V_711 = V_712 + V_343 ;
F_265 ( V_712 , V_343 ) ;
F_268 ( V_710 , V_711 ) ;
V_291 = ! memcmp ( V_711 , V_712 , V_343 ) ;
F_67 ( V_712 ) ;
return V_291 ;
}
static int F_271 ( struct V_272 * V_15 )
{
T_5 V_713 ;
T_3 V_714 ;
T_5 V_715 ;
void T_13 * V_690 ;
unsigned long V_716 ;
T_3 V_717 ;
int V_291 ;
struct V_709 T_13 * V_710 ;
T_3 V_699 ;
T_3 V_50 ;
V_280 V_718 ;
V_291 = F_272 ( V_15 , & V_50 ) ;
if ( V_291 < 0 || ! F_20 ( V_50 ) ) {
F_5 ( & V_15 -> V_16 , L_234 ) ;
return - V_62 ;
}
if ( ! F_17 ( V_50 ) )
return - V_524 ;
F_263 ( V_15 , 4 , & V_718 ) ;
F_273 ( V_15 ) ;
F_274 ( V_15 ) ;
V_291 = F_275 ( V_15 , & V_716 ) ;
if ( V_291 )
return V_291 ;
V_690 = F_231 ( V_716 , 0x250 ) ;
if ( ! V_690 )
return - V_180 ;
V_291 = F_276 ( V_15 , V_690 , & V_714 ,
& V_715 , & V_713 ) ;
if ( V_291 )
goto V_719;
V_710 = F_231 ( F_277 ( V_15 ,
V_715 ) + V_713 , sizeof( * V_710 ) ) ;
if ( ! V_710 ) {
V_291 = - V_180 ;
goto V_719;
}
V_291 = F_266 ( V_710 ) ;
if ( V_291 )
goto V_719;
V_717 = F_260 ( & V_710 -> V_717 ) ;
V_699 = V_717 & V_720 ;
if ( V_699 ) {
V_699 = V_721 ;
} else {
V_699 = V_717 & V_722 ;
if ( V_699 ) {
F_5 ( & V_15 -> V_16 , L_235
L_236 ) ;
V_291 = - V_524 ;
goto V_723;
}
}
V_291 = F_261 ( V_15 , V_690 , V_699 ) ;
if ( V_291 )
goto V_723;
F_278 ( V_15 ) ;
V_291 = F_279 ( V_15 ) ;
if ( V_291 ) {
F_5 ( & V_15 -> V_16 , L_237 ) ;
goto V_723;
}
F_264 ( V_15 , 4 , V_718 ) ;
F_113 ( V_724 ) ;
V_291 = F_280 ( V_15 , V_690 , V_725 ) ;
if ( V_291 ) {
F_5 ( & V_15 -> V_16 ,
L_238
L_239 ) ;
goto V_723;
}
V_291 = F_270 ( V_690 ) ;
if ( V_291 < 0 )
goto V_723;
if ( V_291 ) {
F_5 ( & V_15 -> V_16 , L_240
L_241 ) ;
V_291 = - V_524 ;
} else {
F_60 ( & V_15 -> V_16 , L_242 ) ;
}
V_723:
F_258 ( V_710 ) ;
V_719:
F_258 ( V_690 ) ;
return V_291 ;
}
static void F_281 ( struct V_28 * V_16 , struct V_709 * V_726 )
{
#ifdef F_282
int V_51 ;
char V_727 [ 17 ] ;
F_60 ( V_16 , L_243 ) ;
F_60 ( V_16 , L_244 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
V_727 [ V_51 ] = F_269 ( & ( V_726 -> V_728 [ V_51 ] ) ) ;
V_727 [ 4 ] = '\0' ;
F_60 ( V_16 , L_245 , V_727 ) ;
F_60 ( V_16 , L_246 , F_260 ( & ( V_726 -> V_729 ) ) ) ;
F_60 ( V_16 , L_247 ,
F_260 ( & ( V_726 -> V_730 ) ) ) ;
F_60 ( V_16 , L_248 ,
F_260 ( & ( V_726 -> V_731 ) ) ) ;
F_60 ( V_16 , L_249 ,
F_260 ( & ( V_726 -> V_732 . V_733 ) ) ) ;
F_60 ( V_16 , L_250 ,
F_260 ( & ( V_726 -> V_732 . V_734 ) ) ) ;
F_60 ( V_16 , L_251 ,
F_260 ( & ( V_726 -> V_732 . V_735 ) ) ) ;
F_60 ( V_16 , L_252 ,
F_260 ( & ( V_726 -> V_736 ) ) ) ;
F_60 ( V_16 , L_253 , F_260 ( & ( V_726 -> V_737 ) ) ) ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_727 [ V_51 ] = F_269 ( & ( V_726 -> V_738 [ V_51 ] ) ) ;
V_727 [ 16 ] = '\0' ;
F_60 ( V_16 , L_254 , V_727 ) ;
F_60 ( V_16 , L_255 ,
F_260 ( & ( V_726 -> V_739 ) ) ) ;
#endif
}
static int F_283 ( struct V_272 * V_15 , unsigned long V_740 )
{
int V_51 , V_741 , V_742 , V_743 ;
if ( V_740 == V_744 )
return 0 ;
V_741 = 0 ;
for ( V_51 = 0 ; V_51 < V_745 ; V_51 ++ ) {
V_743 = F_284 ( V_15 , V_51 ) & V_746 ;
if ( V_743 == V_747 )
V_741 += 4 ;
else {
V_742 = F_284 ( V_15 , V_51 ) &
V_748 ;
switch ( V_742 ) {
case V_749 :
case V_750 :
V_741 += 4 ;
break;
case V_751 :
V_741 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_256 ) ;
return - 1 ;
break;
}
}
if ( V_741 == V_740 - V_744 )
return V_51 + 1 ;
}
return - 1 ;
}
static void F_285 ( struct V_1 * V_8 )
{
#ifdef F_286
int V_593 , V_51 ;
struct V_752 V_753 [ V_754 ] ;
for ( V_51 = 0 ; V_51 < V_754 ; V_51 ++ ) {
V_753 [ V_51 ] . V_755 = 0 ;
V_753 [ V_51 ] . V_134 = V_51 ;
}
if ( ( V_8 -> V_50 == 0x40700E11 ) || ( V_8 -> V_50 == 0x40800E11 ) ||
( V_8 -> V_50 == 0x40820E11 ) || ( V_8 -> V_50 == 0x40830E11 ) )
goto V_756;
if ( F_262 ( V_8 -> V_15 , V_757 ) ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_257 ) ;
V_8 -> V_90 = V_754 ;
V_593 = F_287 ( V_8 -> V_15 , V_753 ,
V_8 -> V_90 ) ;
if ( V_593 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_258
L_259 , V_593 ) ;
V_8 -> V_90 = V_593 ;
V_593 = F_287 ( V_8 -> V_15 , V_753 ,
V_8 -> V_90 ) ;
}
if ( ! V_593 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_8 -> V_540 [ V_51 ] = V_753 [ V_51 ] . V_755 ;
return;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_260 ,
V_593 ) ;
V_8 -> V_90 = 0 ;
goto V_756;
}
}
if ( F_262 ( V_8 -> V_15 , V_758 ) ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_261 ) ;
if ( ! F_288 ( V_8 -> V_15 ) )
V_8 -> V_759 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_262 ) ;
}
V_756:
#endif
V_8 -> V_540 [ V_8 -> V_541 ] = V_8 -> V_15 -> V_539 ;
}
static int F_272 ( struct V_272 * V_15 , T_3 * V_50 )
{
int V_51 ;
T_3 V_760 , V_761 ;
V_760 = V_15 -> V_762 ;
V_761 = V_15 -> V_763 ;
* V_50 = ( ( V_761 << 16 ) & 0xffff0000 ) |
V_760 ;
for ( V_51 = 0 ; V_51 < F_18 ( V_764 ) ; V_51 ++ )
if ( * V_50 == V_764 [ V_51 ] . V_50 )
return V_51 ;
if ( ( V_760 != V_765 &&
V_760 != V_766 ) ||
! V_767 ) {
F_5 ( & V_15 -> V_16 , L_263
L_264 , * V_50 ) ;
return - V_62 ;
}
return F_18 ( V_764 ) - 1 ;
}
static int F_275 ( struct V_272 * V_15 ,
unsigned long * V_768 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_745 ; V_51 ++ )
if ( F_284 ( V_15 , V_51 ) & V_769 ) {
* V_768 = F_277 ( V_15 , V_51 ) ;
F_105 ( & V_15 -> V_16 , L_265 ,
* V_768 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_266 ) ;
return - V_62 ;
}
static int F_280 ( struct V_272 * V_15 , void T_13 * V_690 ,
int V_770 )
{
int V_51 , V_771 ;
T_3 V_772 ;
if ( V_770 )
V_771 = V_773 ;
else
V_771 = V_774 ;
for ( V_51 = 0 ; V_51 < V_771 ; V_51 ++ ) {
V_772 = F_260 ( V_690 + V_775 ) ;
if ( V_770 ) {
if ( V_772 == V_776 )
return 0 ;
} else {
if ( V_772 != V_776 )
return 0 ;
}
F_113 ( V_777 ) ;
}
F_5 ( & V_15 -> V_16 , L_267 ) ;
return - V_62 ;
}
static int F_276 ( struct V_272 * V_15 , void T_13 * V_690 ,
T_3 * V_714 , T_5 * V_715 ,
T_5 * V_713 )
{
* V_714 = F_260 ( V_690 + V_778 ) ;
* V_713 = F_260 ( V_690 + V_779 ) ;
* V_714 &= ( T_3 ) 0x0000ffff ;
* V_715 = F_283 ( V_15 , * V_714 ) ;
if ( * V_715 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_268 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_289 ( struct V_1 * V_8 )
{
T_5 V_713 ;
T_3 V_714 ;
T_5 V_715 ;
T_3 V_780 ;
int V_291 ;
V_291 = F_276 ( V_8 -> V_15 , V_8 -> V_690 , & V_714 ,
& V_715 , & V_713 ) ;
if ( V_291 )
return V_291 ;
V_8 -> V_710 = F_231 ( F_277 ( V_8 -> V_15 ,
V_715 ) + V_713 , sizeof( * V_8 -> V_710 ) ) ;
if ( ! V_8 -> V_710 )
return - V_180 ;
V_291 = F_266 ( V_8 -> V_710 ) ;
if ( V_291 )
return V_291 ;
V_780 = F_260 ( & V_8 -> V_710 -> V_781 ) ;
V_8 -> V_782 = F_231 ( F_277 ( V_8 -> V_15 ,
V_715 ) + V_713 + V_780 ,
sizeof( * V_8 -> V_782 ) ) ;
if ( ! V_8 -> V_782 )
return - V_180 ;
return 0 ;
}
static void F_290 ( struct V_1 * V_8 )
{
V_8 -> V_85 = F_260 ( & ( V_8 -> V_710 -> V_783 ) ) ;
if ( V_675 && V_8 -> V_85 > 32 )
V_8 -> V_85 = 32 ;
if ( V_8 -> V_85 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_269
L_270
L_271 ,
V_8 -> V_85 ) ;
V_8 -> V_85 = 16 ;
}
}
static void F_291 ( struct V_1 * V_8 )
{
F_290 ( V_8 ) ;
V_8 -> V_178 = V_8 -> V_85 - 4 ;
V_8 -> V_413 = F_260 ( & ( V_8 -> V_710 -> V_784 ) ) ;
V_8 -> V_356 = F_260 ( & ( V_8 -> V_710 -> V_717 ) ) ;
V_8 -> V_187 = 31 ;
if ( V_8 -> V_413 > 512 ) {
V_8 -> V_187 = 32 ;
V_8 -> V_179 = V_8 -> V_413 - V_8 -> V_187 + 1 ;
V_8 -> V_413 -- ;
} else {
V_8 -> V_413 = 31 ;
V_8 -> V_179 = 0 ;
}
V_8 -> V_575 = F_260 ( & ( V_8 -> V_710 -> V_575 ) ) ;
if ( ! ( V_574 & V_8 -> V_575 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_272 ) ;
if ( ! ( V_576 & V_8 -> V_575 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_273 ) ;
}
static inline bool F_292 ( struct V_1 * V_8 )
{
if ( ! F_293 ( V_8 -> V_710 -> V_728 , L_274 , 4 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_275 ) ;
return false ;
}
return true ;
}
static inline void F_294 ( struct V_1 * V_8 )
{
T_3 V_785 ;
#ifdef F_295
V_785 = F_260 ( & ( V_8 -> V_710 -> V_785 ) ) ;
V_785 |= V_786 ;
#endif
V_785 |= V_787 ;
F_259 ( V_785 , & ( V_8 -> V_710 -> V_785 ) ) ;
}
static inline void F_296 ( struct V_1 * V_8 )
{
T_3 V_788 ;
if ( V_8 -> V_50 != 0x3225103C )
return;
V_788 = F_260 ( V_8 -> V_690 + V_789 ) ;
V_788 |= 0x8000 ;
F_259 ( V_788 , V_8 -> V_690 + V_789 ) ;
}
static void F_297 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_790 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_791 ; V_51 ++ ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_790 = F_260 ( V_8 -> V_690 + V_702 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_790 & V_792 ) )
break;
F_113 ( 20 ) ;
}
}
static void F_298 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_790 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_791 ; V_51 ++ ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_790 = F_260 ( V_8 -> V_690 + V_702 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_790 & V_793 ) )
break;
F_299 ( 10000 , 20000 ) ;
}
}
static int F_300 ( struct V_1 * V_8 )
{
T_3 V_794 ;
V_794 = F_260 ( & ( V_8 -> V_710 -> V_730 ) ) ;
if ( ! ( V_794 & V_795 ) )
return - V_524 ;
V_8 -> V_85 = F_260 ( & ( V_8 -> V_710 -> V_736 ) ) ;
F_259 ( V_796 , & ( V_8 -> V_710 -> V_732 . V_733 ) ) ;
F_259 ( 0 , & V_8 -> V_710 -> V_732 . V_797 ) ;
F_259 ( V_793 , V_8 -> V_690 + V_702 ) ;
F_298 ( V_8 ) ;
F_281 ( & V_8 -> V_15 -> V_16 , V_8 -> V_710 ) ;
if ( ! ( F_260 ( & ( V_8 -> V_710 -> V_731 ) ) & V_796 ) )
goto error;
V_8 -> V_48 = V_796 ;
return 0 ;
error:
F_5 ( & V_8 -> V_15 -> V_16 , L_276 ) ;
return - V_62 ;
}
static int F_301 ( struct V_1 * V_8 )
{
int V_798 , V_593 ;
V_798 = F_272 ( V_8 -> V_15 , & V_8 -> V_50 ) ;
if ( V_798 < 0 )
return - V_62 ;
V_8 -> V_799 = V_764 [ V_798 ] . V_799 ;
V_8 -> V_79 = * ( V_764 [ V_798 ] . V_79 ) ;
F_302 ( V_8 -> V_15 , V_800 |
V_801 | V_802 ) ;
V_593 = F_279 ( V_8 -> V_15 ) ;
if ( V_593 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_277 ) ;
return V_593 ;
}
F_303 ( V_8 -> V_15 ) ;
V_593 = F_304 ( V_8 -> V_15 , V_17 ) ;
if ( V_593 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_278 ) ;
return V_593 ;
}
F_285 ( V_8 ) ;
V_593 = F_275 ( V_8 -> V_15 , & V_8 -> V_716 ) ;
if ( V_593 )
goto V_803;
V_8 -> V_690 = F_231 ( V_8 -> V_716 , 0x250 ) ;
if ( ! V_8 -> V_690 ) {
V_593 = - V_180 ;
goto V_803;
}
V_593 = F_280 ( V_8 -> V_15 , V_8 -> V_690 , V_725 ) ;
if ( V_593 )
goto V_803;
V_593 = F_289 ( V_8 ) ;
if ( V_593 )
goto V_803;
F_291 ( V_8 ) ;
if ( ! F_292 ( V_8 ) ) {
V_593 = - V_62 ;
goto V_803;
}
F_294 ( V_8 ) ;
F_296 ( V_8 ) ;
V_593 = F_300 ( V_8 ) ;
if ( V_593 )
goto V_803;
return 0 ;
V_803:
if ( V_8 -> V_782 )
F_258 ( V_8 -> V_782 ) ;
if ( V_8 -> V_710 )
F_258 ( V_8 -> V_710 ) ;
if ( V_8 -> V_690 )
F_258 ( V_8 -> V_690 ) ;
F_273 ( V_8 -> V_15 ) ;
F_305 ( V_8 -> V_15 ) ;
return V_593 ;
}
static void F_306 ( struct V_1 * V_8 )
{
int V_291 ;
#define F_307 64
V_8 -> V_46 = F_78 ( F_307 , V_154 ) ;
if ( ! V_8 -> V_46 )
return;
V_291 = F_116 ( V_8 , V_117 , 0 ,
V_8 -> V_46 , F_307 ) ;
if ( V_291 != 0 ) {
F_67 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
}
static int F_308 ( struct V_272 * V_15 )
{
int V_291 , V_51 ;
if ( ! V_675 )
return 0 ;
V_291 = F_271 ( V_15 ) ;
if ( V_291 == - V_524 )
return V_291 ;
if ( V_291 )
return - V_62 ;
F_5 ( & V_15 -> V_16 , L_279 ) ;
for ( V_51 = 0 ; V_51 < V_804 ; V_51 ++ ) {
if ( F_309 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_280 ,
( V_51 < 11 ? L_281 : L_282 ) ) ;
}
return 0 ;
}
static int F_310 ( struct V_1 * V_8 )
{
V_8 -> V_582 = F_81 (
F_311 ( V_8 -> V_178 , V_495 ) *
sizeof( unsigned long ) , V_154 ) ;
V_8 -> V_583 = F_209 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_583 ) ,
& ( V_8 -> V_584 ) ) ;
V_8 -> V_585 = F_209 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_585 ) ,
& ( V_8 -> V_586 ) ) ;
if ( ( V_8 -> V_582 == NULL )
|| ( V_8 -> V_583 == NULL )
|| ( V_8 -> V_585 == NULL ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_283 , V_155 ) ;
return - V_180 ;
}
return 0 ;
}
static void F_312 ( struct V_1 * V_8 )
{
F_67 ( V_8 -> V_582 ) ;
if ( V_8 -> V_583 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_583 , V_8 -> V_584 ) ;
if ( V_8 -> V_100 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_452 ) ;
if ( V_8 -> V_585 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_232 ) ,
V_8 -> V_585 ,
V_8 -> V_586 ) ;
if ( V_8 -> V_95 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_93 ) ,
V_8 -> V_95 , V_8 -> V_433 ) ;
}
static int F_313 ( struct V_1 * V_8 ,
T_15 (* F_314)( int , void * ) ,
T_15 (* F_315)( int , void * ) )
{
int V_291 , V_51 ;
for ( V_51 = 0 ; V_51 < V_754 ; V_51 ++ )
V_8 -> V_73 [ V_51 ] = ( T_4 ) V_51 ;
if ( V_8 -> V_541 == V_805 && V_8 -> V_90 > 0 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_291 = F_316 ( V_8 -> V_540 [ V_51 ] , F_314 ,
0 , V_8 -> V_806 ,
& V_8 -> V_73 [ V_51 ] ) ;
} else {
if ( V_8 -> V_90 > 0 || V_8 -> V_759 ) {
V_291 = F_316 ( V_8 -> V_540 [ V_8 -> V_541 ] ,
F_314 , 0 , V_8 -> V_806 ,
& V_8 -> V_73 [ V_8 -> V_541 ] ) ;
} else {
V_291 = F_316 ( V_8 -> V_540 [ V_8 -> V_541 ] ,
F_315 , V_807 , V_8 -> V_806 ,
& V_8 -> V_73 [ V_8 -> V_541 ] ) ;
}
}
if ( V_291 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_284 ,
V_8 -> V_540 [ V_8 -> V_541 ] , V_8 -> V_806 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_317 ( struct V_1 * V_8 )
{
if ( F_230 ( V_8 , V_117 ,
V_808 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_285 ) ;
return - V_698 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_286 ) ;
if ( F_280 ( V_8 -> V_15 , V_8 -> V_690 , V_809 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_287 ) ;
return - 1 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_288 ) ;
if ( F_280 ( V_8 -> V_15 , V_8 -> V_690 , V_725 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_289
L_290 ) ;
return - 1 ;
}
return 0 ;
}
static void F_318 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_90 || V_8 -> V_541 != V_805 ) {
V_51 = V_8 -> V_541 ;
F_319 ( V_8 -> V_540 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
F_319 ( V_8 -> V_540 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
}
static void F_320 ( struct V_1 * V_8 )
{
F_318 ( V_8 ) ;
#ifdef F_286
if ( V_8 -> V_90 ) {
if ( V_8 -> V_15 -> V_810 )
F_321 ( V_8 -> V_15 ) ;
} else if ( V_8 -> V_759 ) {
if ( V_8 -> V_15 -> V_811 )
F_322 ( V_8 -> V_15 ) ;
}
#endif
}
static void F_323 ( struct V_1 * V_8 )
{
F_320 ( V_8 ) ;
F_91 ( V_8 ) ;
F_312 ( V_8 ) ;
F_67 ( V_8 -> V_97 ) ;
F_67 ( V_8 -> V_87 ) ;
F_210 ( V_8 -> V_15 , V_8 -> V_812 ,
V_8 -> V_75 , V_8 -> V_813 ) ;
if ( V_8 -> V_690 )
F_258 ( V_8 -> V_690 ) ;
if ( V_8 -> V_782 )
F_258 ( V_8 -> V_782 ) ;
if ( V_8 -> V_710 )
F_258 ( V_8 -> V_710 ) ;
F_305 ( V_8 -> V_15 ) ;
F_67 ( V_8 ) ;
}
static void F_324 ( struct V_1 * V_8 , struct V_71 * V_72 )
{
struct V_9 * V_10 = NULL ;
F_325 ( & V_8 -> V_60 ) ;
while ( ! F_49 ( V_72 ) ) {
V_10 = F_233 ( V_72 -> V_665 , struct V_9 , V_72 ) ;
V_10 -> V_11 -> V_23 = V_263 ;
F_205 ( V_10 ) ;
}
}
static void F_326 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
V_8 -> V_79 . V_814 ( V_8 , V_815 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_283 = F_260 ( V_8 -> V_690 + V_775 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_291 ,
V_8 -> V_283 ) ;
F_273 ( V_8 -> V_15 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_324 ( V_8 , & V_8 -> V_569 ) ;
F_324 ( V_8 , & V_8 -> V_115 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_327 ( struct V_1 * V_8 )
{
T_5 V_816 ;
T_3 V_817 ;
unsigned long V_59 ;
V_816 = F_250 () ;
if ( F_328 ( V_8 -> V_678 +
( V_8 -> V_109 ) , V_816 ) )
return;
if ( F_328 ( V_8 -> V_818 +
( V_8 -> V_109 ) , V_816 ) )
return;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_817 = F_260 ( & V_8 -> V_710 -> V_739 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_819 == V_817 ) {
F_326 ( V_8 ) ;
return;
}
V_8 -> V_819 = V_817 ;
V_8 -> V_818 = V_816 ;
}
static void F_329 ( struct V_1 * V_8 )
{
int V_51 ;
char * V_820 ;
V_8 -> V_230 = 0 ;
if ( ( V_8 -> V_48 & ( V_78
| V_387 ) ) &&
( V_8 -> V_821 & V_822 ||
V_8 -> V_821 & V_823 ) ) {
if ( V_8 -> V_821 & V_822 )
V_820 = L_292 ;
if ( V_8 -> V_821 & V_823 )
V_820 = L_293 ;
F_330 ( V_8 -> V_44 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] -> V_70 = 0 ;
F_331 ( V_8 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_294 ,
V_8 -> V_821 , V_820 ) ;
F_259 ( V_8 -> V_821 , & ( V_8 -> V_710 -> V_824 ) ) ;
F_259 ( V_792 , V_8 -> V_690 + V_702 ) ;
F_297 ( V_8 ) ;
F_332 ( V_8 -> V_44 ) ;
} else {
F_259 ( V_8 -> V_821 , & ( V_8 -> V_710 -> V_824 ) ) ;
F_259 ( V_792 , V_8 -> V_690 + V_702 ) ;
F_297 ( V_8 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_333 ( struct V_1 * V_8 )
{
if ( V_8 -> V_230 )
return 1 ;
if ( ! ( V_8 -> V_356 & V_825 ) )
return 0 ;
V_8 -> V_821 = F_260 ( & ( V_8 -> V_710 -> V_826 ) ) ;
return V_8 -> V_821 & V_827 ;
}
static int F_334 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
struct V_152 * V_288 ;
struct V_71 * V_828 , * V_829 ;
F_25 ( & V_8 -> V_153 , V_59 ) ;
F_335 (this, tmp, &h->offline_device_list) {
V_288 = F_233 ( V_828 , struct V_152 ,
V_156 ) ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
if ( ! F_139 ( V_8 , V_288 -> V_54 ) )
return 1 ;
F_25 ( & V_8 -> V_153 , V_59 ) ;
}
F_26 ( & V_8 -> V_153 , V_59 ) ;
return 0 ;
}
static void F_336 ( struct V_830 * V_831 )
{
unsigned long V_59 ;
struct V_1 * V_8 = F_248 ( F_337 ( V_831 ) ,
struct V_1 , V_832 ) ;
F_327 ( V_8 ) ;
if ( V_8 -> V_283 )
return;
if ( F_333 ( V_8 ) || F_334 ( V_8 ) ) {
F_338 ( V_8 -> V_44 ) ;
V_8 -> V_230 = 0 ;
F_329 ( V_8 ) ;
F_12 ( V_8 -> V_44 ) ;
F_189 ( V_8 -> V_44 ) ;
}
F_25 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_833 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return;
}
F_339 ( & V_8 -> V_832 ,
V_8 -> V_109 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static int F_340 ( struct V_272 * V_15 , const struct V_834 * V_835 )
{
int V_836 , V_291 ;
struct V_1 * V_8 ;
int V_837 = 0 ;
unsigned long V_59 ;
if ( V_838 == 0 )
F_341 (KERN_INFO DRIVER_NAME L_295 ) ;
V_291 = F_308 ( V_15 ) ;
if ( V_291 ) {
if ( V_291 != - V_524 )
return V_291 ;
V_837 = 1 ;
V_291 = 0 ;
}
V_839:
#define F_342 128
F_343 ( sizeof( struct V_9 ) % F_342 ) ;
V_8 = F_81 ( sizeof( * V_8 ) , V_154 ) ;
if ( ! V_8 )
return - V_180 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_541 = V_840 ? V_841 : V_805 ;
F_208 ( & V_8 -> V_569 ) ;
F_208 ( & V_8 -> V_115 ) ;
F_208 ( & V_8 -> V_157 ) ;
F_344 ( & V_8 -> V_60 ) ;
F_344 ( & V_8 -> V_153 ) ;
F_344 ( & V_8 -> V_516 ) ;
F_344 ( & V_8 -> V_647 ) ;
V_291 = F_301 ( V_8 ) ;
if ( V_291 != 0 )
goto V_842;
sprintf ( V_8 -> V_806 , V_17 L_14 , V_838 ) ;
V_8 -> V_18 = V_838 ;
V_838 ++ ;
V_291 = F_345 ( V_15 , F_257 ( 64 ) ) ;
if ( V_291 == 0 ) {
V_836 = 1 ;
} else {
V_291 = F_345 ( V_15 , F_257 ( 32 ) ) ;
if ( V_291 == 0 ) {
V_836 = 0 ;
} else {
F_59 ( & V_15 -> V_16 , L_296 ) ;
goto V_842;
}
}
V_8 -> V_79 . V_814 ( V_8 , V_815 ) ;
if ( F_313 ( V_8 , F_253 , F_252 ) )
goto V_843;
F_60 ( & V_15 -> V_16 , L_297 ,
V_8 -> V_806 , V_15 -> V_28 ,
V_8 -> V_540 [ V_8 -> V_541 ] , V_836 ? L_282 : L_298 ) ;
if ( F_310 ( V_8 ) )
goto V_844;
if ( F_92 ( V_8 ) )
goto V_844;
F_346 ( & V_8 -> V_518 ) ;
V_8 -> V_517 = 1 ;
F_347 ( V_15 , V_8 ) ;
V_8 -> V_124 = 0 ;
V_8 -> V_402 = 0 ;
V_8 -> V_44 = NULL ;
F_344 ( & V_8 -> V_176 ) ;
F_348 ( V_8 ) ;
if ( V_837 ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_79 . V_814 ( V_8 , V_815 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_318 ( V_8 ) ;
V_291 = F_313 ( V_8 , F_251 ,
F_249 ) ;
if ( V_291 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_299
L_300 ) ;
goto V_844;
}
V_291 = F_317 ( V_8 ) ;
if ( V_291 )
goto V_844;
F_60 ( & V_8 -> V_15 -> V_16 , L_301 ) ;
F_60 ( & V_8 -> V_15 -> V_16 ,
L_302 ) ;
V_8 -> V_79 . V_814 ( V_8 , V_845 ) ;
F_113 ( 10000 ) ;
V_8 -> V_79 . V_814 ( V_8 , V_815 ) ;
V_291 = F_270 ( V_8 -> V_710 ) ;
if ( V_291 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_303 ) ;
F_323 ( V_8 ) ;
V_837 = 0 ;
if ( V_291 )
return - V_62 ;
goto V_839;
}
V_8 -> V_41 = 1 ;
V_8 -> V_230 = 0 ;
V_8 -> V_79 . V_814 ( V_8 , V_845 ) ;
F_306 ( V_8 ) ;
F_190 ( V_8 ) ;
V_8 -> V_109 = V_111 ;
F_349 ( & V_8 -> V_832 , F_336 ) ;
F_339 ( & V_8 -> V_832 ,
V_8 -> V_109 ) ;
return 0 ;
V_844:
F_91 ( V_8 ) ;
F_312 ( V_8 ) ;
F_318 ( V_8 ) ;
V_843:
V_842:
F_67 ( V_8 ) ;
return V_291 ;
}
static void F_350 ( struct V_1 * V_8 )
{
char * V_846 ;
struct V_9 * V_10 ;
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
if ( F_33 ( V_8 -> V_283 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_846 = F_81 ( 4 , V_154 ) ;
if ( ! V_846 )
return;
V_10 = F_117 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_127 ) ;
goto V_847;
}
if ( F_118 ( V_10 , V_654 , V_8 , V_846 , 4 , 0 ,
V_117 , V_294 ) ) {
goto V_295;
}
F_112 ( V_8 , V_10 , V_192 ) ;
if ( V_10 -> V_11 -> V_23 != 0 )
V_295:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_304 ) ;
F_119 ( V_8 , V_10 ) ;
V_847:
F_67 ( V_846 ) ;
}
static void F_351 ( struct V_272 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_352 ( V_15 ) ;
F_350 ( V_8 ) ;
V_8 -> V_79 . V_814 ( V_8 , V_815 ) ;
F_320 ( V_8 ) ;
}
static void F_353 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
F_67 ( V_8 -> V_16 [ V_51 ] ) ;
}
static void F_354 ( struct V_272 * V_15 )
{
struct V_1 * V_8 ;
unsigned long V_59 ;
if ( F_352 ( V_15 ) == NULL ) {
F_59 ( & V_15 -> V_16 , L_305 ) ;
return;
}
V_8 = F_352 ( V_15 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_833 = 1 ;
F_355 ( & V_8 -> V_832 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_187 ( V_8 ) ;
F_351 ( V_15 ) ;
F_258 ( V_8 -> V_690 ) ;
F_258 ( V_8 -> V_782 ) ;
F_258 ( V_8 -> V_710 ) ;
F_353 ( V_8 ) ;
F_91 ( V_8 ) ;
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_583 , V_8 -> V_584 ) ;
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_232 ) ,
V_8 -> V_585 , V_8 -> V_586 ) ;
F_210 ( V_8 -> V_15 , V_8 -> V_812 ,
V_8 -> V_75 , V_8 -> V_813 ) ;
F_67 ( V_8 -> V_582 ) ;
F_67 ( V_8 -> V_87 ) ;
F_67 ( V_8 -> V_97 ) ;
F_67 ( V_8 -> V_101 ) ;
F_67 ( V_8 -> V_46 ) ;
F_273 ( V_15 ) ;
F_305 ( V_15 ) ;
F_67 ( V_8 ) ;
}
static void F_356 ( int V_848 [] , int V_849 ,
int V_850 , int V_851 , int * V_852 )
{
int V_51 , V_142 , V_853 , V_343 ;
for ( V_51 = 0 ; V_51 <= V_850 ; V_51 ++ ) {
V_343 = V_51 + V_851 ;
V_853 = V_849 ;
for ( V_142 = 0 ; V_142 < V_849 ; V_142 ++ ) {
if ( V_848 [ V_142 ] >= V_343 ) {
V_853 = V_142 ;
break;
}
}
V_852 [ V_51 ] = V_853 ;
}
}
static void F_357 ( struct V_1 * V_8 , T_3 V_794 )
{
int V_51 ;
unsigned long V_854 ;
unsigned long V_48 = V_49 |
( V_794 & V_855 ) |
V_856 |
( V_794 & ( V_78 |
V_387 ) ) ;
struct V_857 V_79 = V_858 ;
int V_859 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_644 + 4 } ;
#define F_358 5
#define F_359 4
int V_860 [ 16 ] = { F_358 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_359 + V_455 } ;
F_343 ( F_18 ( V_860 ) != 16 ) ;
F_343 ( F_18 ( V_859 ) != 8 ) ;
F_343 ( F_174 ( struct V_99 , V_408 ) >
16 * F_358 ) ;
F_343 ( sizeof( struct V_451 ) != 16 ) ;
F_343 ( 28 > V_644 + 4 ) ;
memset ( V_8 -> V_75 , 0 , V_8 -> V_812 ) ;
V_859 [ 7 ] = V_644 + 4 ;
F_356 ( V_859 , F_18 ( V_859 ) ,
V_644 , 4 , V_8 -> V_87 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
F_259 ( V_859 [ V_51 ] , & V_8 -> V_782 -> V_861 [ V_51 ] ) ;
F_259 ( V_8 -> V_85 , & V_8 -> V_782 -> V_862 ) ;
F_259 ( V_8 -> V_92 , & V_8 -> V_782 -> V_863 ) ;
F_259 ( 0 , & V_8 -> V_782 -> V_864 ) ;
F_259 ( 0 , & V_8 -> V_782 -> V_865 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_259 ( 0 , & V_8 -> V_782 -> V_866 [ V_51 ] . V_195 ) ;
F_259 ( V_8 -> V_813 +
( V_8 -> V_85 * sizeof( T_5 ) * V_51 ) ,
& V_8 -> V_782 -> V_866 [ V_51 ] . V_194 ) ;
}
F_259 ( 0 , & V_8 -> V_710 -> V_732 . V_797 ) ;
F_259 ( V_48 , & ( V_8 -> V_710 -> V_732 . V_733 ) ) ;
if ( V_794 & V_78 ) {
V_79 = V_867 ;
F_259 ( 10 , & V_8 -> V_710 -> V_732 . V_734 ) ;
F_259 ( 4 , & V_8 -> V_710 -> V_732 . V_735 ) ;
} else {
if ( V_794 & V_387 ) {
V_79 = V_868 ;
F_259 ( 10 , & V_8 -> V_710 -> V_732 . V_734 ) ;
F_259 ( 4 , & V_8 -> V_710 -> V_732 . V_735 ) ;
}
}
F_259 ( V_793 , V_8 -> V_690 + V_702 ) ;
F_298 ( V_8 ) ;
V_854 = F_260 ( & ( V_8 -> V_710 -> V_731 ) ) ;
if ( ! ( V_854 & V_49 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_306
L_307 ) ;
return;
}
V_8 -> V_79 = V_79 ;
V_8 -> V_48 = V_48 ;
if ( ! ( ( V_794 & V_78 ) ||
( V_794 & V_387 ) ) )
return;
if ( V_794 & V_78 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_259 ( V_51 , V_8 -> V_690 + V_869 ) ;
V_8 -> V_77 [ V_51 ] . V_82 =
F_260 ( V_8 -> V_690 + V_870 ) ;
}
V_859 [ 7 ] = V_8 -> V_430 + 8 ;
F_356 ( V_859 , F_18 ( V_859 ) , V_8 -> V_430 , 8 ,
V_8 -> V_97 ) ;
memset ( V_8 -> V_75 , ( T_4 ) V_871 ,
V_8 -> V_812 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
struct V_93 * V_94 = & V_8 -> V_95 [ V_51 ] ;
V_94 -> V_872 = V_873 ;
V_94 -> V_11 = ( T_3 ) ( V_8 -> V_586 +
( V_51 * sizeof( struct V_232 ) ) ) ;
V_94 -> V_874 = sizeof( struct V_232 ) ;
V_94 -> V_875 = V_876 ;
V_94 -> V_877 = V_878 ;
V_94 -> V_879 = 0 ;
V_94 -> V_91 = 0 ;
V_94 -> V_247 . V_194 = ( V_51 << V_464 ) |
V_465 ;
V_94 -> V_247 . V_195 = 0 ;
V_94 -> V_880 . V_194 =
( T_3 ) ( V_8 -> V_433 +
( V_51 * sizeof( struct V_93 ) ) ) ;
V_94 -> V_880 . V_195 = 0 ;
}
} else if ( V_794 & V_387 ) {
T_5 V_713 , V_715 ;
T_3 V_881 , V_714 ;
int V_291 ;
V_291 = F_276 ( V_8 -> V_15 , V_8 -> V_690 , & V_714 ,
& V_715 , & V_713 ) ;
F_343 ( F_174 ( struct V_99 , V_408 ) != 64 ) ;
V_860 [ 15 ] = V_8 -> V_430 + F_359 ;
F_356 ( V_860 , F_18 ( V_860 ) , V_8 -> V_430 ,
4 , V_8 -> V_101 ) ;
V_881 = F_260 ( & V_8 -> V_710 -> V_882 ) ;
F_343 ( F_174 ( struct V_709 ,
V_882 ) != 0xb8 ) ;
V_8 -> V_883 =
F_231 ( F_277 ( V_8 -> V_15 ,
V_715 ) +
V_713 + V_881 ,
F_18 ( V_860 ) *
sizeof( * V_8 -> V_883 ) ) ;
for ( V_51 = 0 ; V_51 < F_18 ( V_860 ) ; V_51 ++ )
F_259 ( V_860 [ V_51 ] , & V_8 -> V_883 [ V_51 ] ) ;
}
F_259 ( V_793 , V_8 -> V_690 + V_702 ) ;
F_298 ( V_8 ) ;
}
static int F_360 ( struct V_1 * V_8 )
{
V_8 -> V_430 =
F_260 ( & ( V_8 -> V_710 -> V_884 ) ) ;
if ( V_8 -> V_430 > V_885 )
V_8 -> V_430 = V_885 ;
#define F_361 128
F_343 ( sizeof( struct V_93 ) %
F_361 ) ;
V_8 -> V_95 =
F_209 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
& ( V_8 -> V_433 ) ) ;
V_8 -> V_97 =
F_78 ( ( ( V_8 -> V_430 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_95 == NULL ) ||
( V_8 -> V_97 == NULL ) )
goto V_886;
memset ( V_8 -> V_95 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ) ;
return 0 ;
V_886:
if ( V_8 -> V_95 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
V_8 -> V_95 , V_8 -> V_433 ) ;
F_67 ( V_8 -> V_97 ) ;
return 1 ;
}
static int F_362 ( struct V_1 * V_8 )
{
V_8 -> V_430 =
F_260 ( & ( V_8 -> V_710 -> V_884 ) ) ;
if ( V_8 -> V_430 > V_455 )
V_8 -> V_430 = V_455 ;
#define F_363 128
F_343 ( sizeof( struct V_99 ) %
F_363 ) ;
V_8 -> V_100 =
F_209 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
& ( V_8 -> V_452 ) ) ;
V_8 -> V_101 =
F_78 ( ( ( V_8 -> V_430 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_100 == NULL ) ||
( V_8 -> V_101 == NULL ) )
goto V_886;
memset ( V_8 -> V_100 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ) ;
return 0 ;
V_886:
if ( V_8 -> V_100 )
F_210 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_452 ) ;
F_67 ( V_8 -> V_101 ) ;
return 1 ;
}
static void F_348 ( struct V_1 * V_8 )
{
T_3 V_794 ;
unsigned long V_48 = V_49 |
V_855 ;
int V_51 ;
if ( V_840 )
return;
V_794 = F_260 ( & ( V_8 -> V_710 -> V_730 ) ) ;
if ( ! ( V_794 & V_887 ) )
return;
if ( V_794 & V_78 ) {
V_48 |= V_78 |
V_856 ;
if ( F_360 ( V_8 ) )
goto V_886;
} else {
if ( V_794 & V_387 ) {
V_48 |= V_387 |
V_856 ;
if ( F_362 ( V_8 ) )
goto V_886;
}
}
V_8 -> V_92 = V_8 -> V_90 > 0 ? V_8 -> V_90 : 1 ;
F_290 ( V_8 ) ;
V_8 -> V_812 = V_8 -> V_85 * sizeof( T_5 ) * V_8 -> V_92 ;
V_8 -> V_75 = F_209 ( V_8 -> V_15 , V_8 -> V_812 ,
& ( V_8 -> V_813 ) ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
V_8 -> V_77 [ V_51 ] . V_81 = & V_8 -> V_75 [ V_8 -> V_85 * V_51 ] ;
V_8 -> V_77 [ V_51 ] . V_343 = V_8 -> V_85 ;
V_8 -> V_77 [ V_51 ] . V_83 = 1 ;
V_8 -> V_77 [ V_51 ] . V_82 = 0 ;
}
V_8 -> V_87 = F_78 ( ( ( V_644 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_75 == NULL )
|| ( V_8 -> V_87 == NULL ) )
goto V_886;
F_357 ( V_8 , V_794 ) ;
return;
V_886:
if ( V_8 -> V_75 )
F_210 ( V_8 -> V_15 , V_8 -> V_812 ,
V_8 -> V_75 , V_8 -> V_813 ) ;
F_67 ( V_8 -> V_87 ) ;
}
static int F_364 ( struct V_9 * V_10 )
{
return V_10 -> V_112 == V_113 || V_10 -> V_112 == V_114 ;
}
static void F_331 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
int V_888 ;
do {
V_888 = 0 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, &h->cmpQ, list)
V_888 += F_364 ( V_10 ) ;
F_77 (c, &h->reqQ, list)
V_888 += F_364 ( V_10 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_888 <= 0 )
break;
F_113 ( 100 ) ;
} while ( 1 );
}
static int T_17 F_365 ( void )
{
return F_366 ( & V_889 ) ;
}
static void T_18 F_367 ( void )
{
F_368 ( & V_889 ) ;
}
