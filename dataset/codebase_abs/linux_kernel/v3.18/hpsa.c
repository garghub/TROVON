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
F_46 ( V_8 , & V_59 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
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
V_200 -> V_209 |= V_210 ;
if ( V_201 -> V_204 . V_211 !=
V_212 ) {
memset ( V_200 -> V_213 , 0 ,
V_214 ) ;
break;
}
V_202 = V_201 -> V_204 . V_215 ;
if ( V_202 > V_214 )
V_202 = V_214 ;
if ( V_202 > sizeof( V_201 -> V_204 . V_216 ) )
V_202 =
sizeof( V_201 -> V_204 . V_216 ) ;
memcpy ( V_200 -> V_213 ,
V_201 -> V_204 . V_216 , V_202 ) ;
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
V_200 -> V_209 = V_220 << 16 ;
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
V_16 -> V_70 = 0 ;
V_8 -> V_229 = 1 ;
V_200 -> V_209 = V_230 << 16 ;
F_100 ( V_8 , V_10 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
V_227 = F_98 ( V_8 , V_10 , V_200 , V_201 ) ;
if ( V_227 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_69 ,
L_60 ) ;
V_16 -> V_70 = 0 ;
V_8 -> V_229 = 1 ;
V_200 -> V_209 = V_230 << 16 ;
}
F_100 ( V_8 , V_10 ) ;
V_200 -> V_228 ( V_200 ) ;
}
static void F_101 ( struct V_9 * V_94 )
{
struct V_199 * V_200 ;
struct V_1 * V_8 ;
struct V_231 * V_232 ;
struct V_57 * V_16 ;
unsigned char V_233 ;
unsigned char V_234 ;
unsigned char V_235 ;
unsigned long V_236 ;
V_232 = V_94 -> V_11 ;
V_200 = (struct V_199 * ) V_94 -> V_237 ;
V_8 = V_94 -> V_8 ;
V_16 = V_200 -> V_28 -> V_61 ;
F_102 ( V_200 ) ;
if ( ( V_94 -> V_112 == V_238 ) &&
( V_94 -> V_88 . V_191 > V_8 -> V_187 ) )
F_96 ( V_8 , V_94 ) ;
V_200 -> V_209 = ( V_239 << 16 ) ;
V_200 -> V_209 |= ( V_240 << 8 ) ;
if ( V_94 -> V_112 == V_114 )
return F_99 ( V_8 , V_94 , V_200 , V_16 ) ;
V_200 -> V_209 |= V_232 -> V_25 ;
F_103 ( V_200 , V_232 -> V_241 ) ;
if ( V_232 -> V_23 == 0 ) {
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
if ( V_214 < sizeof( V_232 -> V_12 ) )
V_236 = V_214 ;
else
V_236 = sizeof( V_232 -> V_12 ) ;
if ( V_232 -> V_242 < V_236 )
V_236 = V_232 -> V_242 ;
memcpy ( V_200 -> V_213 , V_232 -> V_12 , V_236 ) ;
if ( V_94 -> V_112 == V_113 ) {
struct V_93 * V_10 = & V_8 -> V_95 [ V_94 -> V_96 ] ;
V_94 -> V_88 . V_89 = V_94 -> V_88 . V_191 = F_104 ( V_200 ) ;
V_94 -> V_106 . V_243 = V_10 -> V_244 & V_245 ;
V_94 -> V_88 . V_246 . V_194 = V_10 -> V_246 . V_194 ;
V_94 -> V_88 . V_246 . V_195 = V_10 -> V_246 . V_195 ;
memcpy ( V_94 -> V_88 . V_247 . V_248 , V_10 -> V_249 , 8 ) ;
memcpy ( V_94 -> V_106 . V_107 , V_10 -> V_107 , V_94 -> V_106 . V_243 ) ;
if ( F_22 ( V_16 -> V_54 ) ) {
if ( V_232 -> V_23 == V_250 )
V_16 -> V_70 = 0 ;
V_200 -> V_209 = V_230 << 16 ;
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
return;
}
}
switch ( V_232 -> V_23 ) {
case V_24 :
if ( V_232 -> V_25 ) {
V_233 = 0xf & V_232 -> V_12 [ 2 ] ;
V_234 = V_232 -> V_12 [ 12 ] ;
V_235 = V_232 -> V_12 [ 13 ] ;
}
if ( V_232 -> V_25 == V_210 ) {
if ( F_4 ( V_8 , V_94 ) )
break;
if ( V_233 == V_251 ) {
if ( V_94 -> V_106 . V_107 [ 0 ] == V_252 )
break;
if ( ( V_234 == 0x25 ) && ( V_235 == 0x0 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_70
L_71 , V_94 ) ;
break;
}
}
if ( V_233 == V_253 ) {
if ( ( V_234 == 0x04 ) && ( V_235 == 0x03 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_70
L_72
L_73
L_74 , V_94 ) ;
break;
}
}
if ( V_233 == V_254 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_70
L_75
L_76 ,
V_94 , V_234 , V_235 ) ;
V_200 -> V_209 |= V_230 << 16 ;
break;
}
F_105 ( & V_8 -> V_15 -> V_16 , L_77
L_78
L_79
L_80
L_81
L_82
L_83 ,
V_94 , V_233 , V_234 , V_235 ,
V_200 -> V_209 ,
V_200 -> V_255 [ 0 ] , V_200 -> V_255 [ 1 ] ,
V_200 -> V_255 [ 2 ] , V_200 -> V_255 [ 3 ] ,
V_200 -> V_255 [ 4 ] , V_200 -> V_255 [ 5 ] ,
V_200 -> V_255 [ 6 ] , V_200 -> V_255 [ 7 ] ,
V_200 -> V_255 [ 8 ] , V_200 -> V_255 [ 9 ] ,
V_200 -> V_255 [ 10 ] , V_200 -> V_255 [ 11 ] ,
V_200 -> V_255 [ 12 ] , V_200 -> V_255 [ 13 ] ,
V_200 -> V_255 [ 14 ] , V_200 -> V_255 [ 15 ] ) ;
break;
}
if ( V_232 -> V_25 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_84
L_79
L_85 ,
V_94 , V_232 -> V_25 ,
V_233 , V_234 , V_235 ,
V_200 -> V_209 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_86
L_87 , V_94 ) ,
V_200 -> V_209 = V_256 << 16 ;
}
break;
case V_257 :
break;
case V_258 :
F_5 ( & V_8 -> V_15 -> V_16 , L_88
L_89
L_90 , V_94 ) ;
break;
case V_259 : {
V_200 -> V_209 = V_256 << 16 ;
}
break;
case V_260 :
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_91
L_92 , V_94 ) ;
break;
case V_262 :
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_93 , V_94 ) ;
break;
case V_263 :
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_94 , V_94 ) ;
break;
case V_264 :
V_200 -> V_209 = V_265 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_95 ,
V_94 , V_232 -> V_25 ) ;
break;
case V_266 :
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_96 , V_94 ) ;
break;
case V_267 :
V_200 -> V_209 = V_230 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_97
L_98 , V_94 ) ;
break;
case V_268 :
V_200 -> V_209 = V_269 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_99 , V_94 ) ;
break;
case V_270 :
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_100 ) ;
break;
case V_250 :
V_200 -> V_209 = V_230 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_101 , V_94 ) ;
break;
default:
V_200 -> V_209 = V_261 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_102 ,
V_94 , V_232 -> V_23 ) ;
}
F_100 ( V_8 , V_94 ) ;
V_200 -> V_228 ( V_200 ) ;
}
static void F_106 ( struct V_271 * V_15 ,
struct V_9 * V_10 , int V_272 , int V_273 )
{
int V_51 ;
union V_196 V_274 ;
for ( V_51 = 0 ; V_51 < V_272 ; V_51 ++ ) {
V_274 . V_197 . V_194 = V_10 -> V_186 [ V_51 ] . V_193 . V_194 ;
V_274 . V_197 . V_195 = V_10 -> V_186 [ V_51 ] . V_193 . V_195 ;
F_97 ( V_15 , ( V_275 ) V_274 . V_198 , V_10 -> V_186 [ V_51 ] . V_190 ,
V_273 ) ;
}
}
static int F_107 ( struct V_271 * V_15 ,
struct V_9 * V_94 ,
unsigned char * V_31 ,
T_2 V_276 ,
int V_273 )
{
T_5 V_274 ;
if ( V_276 == 0 || V_273 == V_277 ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = 0 ;
return 0 ;
}
V_274 = ( T_5 ) F_94 ( V_15 , V_31 , V_276 , V_273 ) ;
if ( F_95 ( & V_15 -> V_16 , V_274 ) ) {
V_94 -> V_88 . V_89 = 0 ;
V_94 -> V_88 . V_191 = 0 ;
return - 1 ;
}
V_94 -> V_186 [ 0 ] . V_193 . V_194 =
( T_3 ) ( V_274 & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_94 -> V_186 [ 0 ] . V_193 . V_195 =
( T_3 ) ( ( V_274 >> 32 ) & ( T_5 ) 0x00000000FFFFFFFF ) ;
V_94 -> V_186 [ 0 ] . V_190 = V_276 ;
V_94 -> V_186 [ 0 ] . V_188 = V_278 ;
V_94 -> V_88 . V_89 = ( T_4 ) 1 ;
V_94 -> V_88 . V_191 = ( V_279 ) 1 ;
return 0 ;
}
static inline void F_108 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_109 ( V_280 ) ;
V_10 -> V_281 = & V_280 ;
F_45 ( V_8 , V_10 ) ;
F_110 ( & V_280 ) ;
}
static T_3 F_111 ( struct V_1 * V_8 )
{
int V_282 ;
T_3 V_283 , * F_111 ;
V_282 = F_112 () ;
F_111 = F_113 ( V_8 -> F_111 , V_282 ) ;
V_283 = * F_111 ;
F_114 () ;
return V_283 ;
}
static void F_115 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_33 ( F_111 ( V_8 ) ) )
V_10 -> V_11 -> V_23 = V_262 ;
else
F_108 ( V_8 , V_10 ) ;
}
static void F_116 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_273 )
{
int V_284 = 10 , V_285 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_108 ( V_8 , V_10 ) ;
V_285 ++ ;
if ( V_285 > 3 ) {
F_117 ( V_284 ) ;
if ( V_284 < 1000 )
V_284 *= 2 ;
}
} while ( ( F_4 ( V_8 , V_10 ) ||
F_6 ( V_8 , V_10 ) ) &&
V_285 <= V_286 );
F_106 ( V_8 -> V_15 , V_10 , 1 , V_273 ) ;
}
static void F_118 ( struct V_1 * V_8 , char * V_287 ,
struct V_9 * V_10 )
{
const T_4 * V_103 = V_10 -> V_106 . V_107 ;
const T_4 * V_120 = V_10 -> V_88 . V_247 . V_248 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_103
L_104 ,
V_287 , V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ,
V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 2 ] , V_103 [ 3 ] ,
V_103 [ 4 ] , V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ,
V_103 [ 8 ] , V_103 [ 9 ] , V_103 [ 10 ] , V_103 [ 11 ] ,
V_103 [ 12 ] , V_103 [ 13 ] , V_103 [ 14 ] , V_103 [ 15 ] ) ;
}
static void F_119 ( struct V_1 * V_8 ,
struct V_9 * V_94 )
{
const struct V_231 * V_232 = V_94 -> V_11 ;
struct V_28 * V_288 = & V_94 -> V_8 -> V_15 -> V_16 ;
const T_4 * V_131 = V_232 -> V_12 ;
switch ( V_232 -> V_23 ) {
case V_24 :
F_118 ( V_8 , L_105 , V_94 ) ;
if ( V_232 -> V_25 == V_210 )
F_5 ( V_288 , L_106 ,
V_131 [ 2 ] & 0x0f , V_131 [ 12 ] , V_131 [ 13 ] ) ;
else
F_5 ( V_288 , L_107 , V_232 -> V_25 ) ;
if ( V_232 -> V_25 == 0 )
F_5 ( V_288 , L_108
L_109
L_110
L_111 ) ;
break;
case V_257 :
break;
case V_258 :
F_118 ( V_8 , L_112 , V_94 ) ;
break;
case V_259 : {
F_118 ( V_8 , L_113 , V_94 ) ;
F_5 ( V_288 , L_114 ) ;
}
break;
case V_260 :
F_118 ( V_8 , L_115 , V_94 ) ;
break;
case V_262 :
F_118 ( V_8 , L_116 , V_94 ) ;
break;
case V_263 :
F_118 ( V_8 , L_117 , V_94 ) ;
break;
case V_264 :
F_118 ( V_8 , L_118 , V_94 ) ;
break;
case V_266 :
F_118 ( V_8 , L_119 , V_94 ) ;
break;
case V_267 :
F_118 ( V_8 , L_120 , V_94 ) ;
break;
case V_268 :
F_118 ( V_8 , L_121 , V_94 ) ;
break;
case V_270 :
F_118 ( V_8 , L_122 , V_94 ) ;
break;
default:
F_118 ( V_8 , L_123 , V_94 ) ;
F_5 ( V_288 , L_124 ,
V_232 -> V_23 ) ;
}
}
static int F_120 ( struct V_1 * V_8 , unsigned char * V_54 ,
V_279 V_289 , unsigned char * V_31 ,
unsigned char V_290 )
{
int V_283 = V_291 ;
struct V_9 * V_10 ;
struct V_231 * V_232 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - V_180 ;
}
if ( F_122 ( V_10 , V_292 , V_8 , V_31 , V_290 ,
V_289 , V_54 , V_293 ) ) {
V_283 = - 1 ;
goto V_294;
}
F_116 ( V_8 , V_10 , V_295 ) ;
V_232 = V_10 -> V_11 ;
if ( V_232 -> V_23 != 0 && V_232 -> V_23 != V_257 ) {
F_119 ( V_8 , V_10 ) ;
V_283 = - 1 ;
}
V_294:
F_123 ( V_8 , V_10 ) ;
return V_283 ;
}
static int F_124 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char V_289 ,
struct V_296 * V_31 , T_2 V_290 )
{
int V_283 = V_291 ;
struct V_9 * V_10 ;
struct V_231 * V_232 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - V_180 ;
}
if ( F_122 ( V_10 , V_297 , V_8 , V_31 , V_290 ,
V_289 , V_54 , V_293 ) ) {
V_283 = - 1 ;
goto V_294;
}
F_116 ( V_8 , V_10 , V_295 ) ;
V_232 = V_10 -> V_11 ;
if ( V_232 -> V_23 != 0 && V_232 -> V_23 != V_257 ) {
F_119 ( V_8 , V_10 ) ;
V_283 = - 1 ;
}
V_294:
F_123 ( V_8 , V_10 ) ;
return V_283 ;
}
static int F_125 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_298 )
{
int V_283 = V_291 ;
struct V_9 * V_10 ;
struct V_231 * V_232 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - V_180 ;
}
( void ) F_122 ( V_10 , V_299 , V_8 , NULL , 0 , 0 ,
V_54 , V_300 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_298 ;
F_108 ( V_8 , V_10 ) ;
V_232 = V_10 -> V_11 ;
if ( V_232 -> V_23 != 0 ) {
F_119 ( V_8 , V_10 ) ;
V_283 = - 1 ;
}
F_123 ( V_8 , V_10 ) ;
return V_283 ;
}
static void F_126 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char * V_64 )
{
int V_283 ;
unsigned char * V_31 ;
* V_64 = V_65 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
V_283 = F_120 ( V_8 , V_54 , V_301 | 0xC1 , V_31 , 64 ) ;
if ( V_283 == 0 )
* V_64 = V_31 [ 8 ] ;
if ( * V_64 > V_65 )
* V_64 = V_65 ;
F_67 ( V_31 ) ;
return;
}
static void F_127 ( struct V_1 * V_8 , int V_283 ,
struct V_302 * V_303 )
{
struct V_304 * V_305 = & V_303 -> V_306 [ 0 ] ;
int V_307 , V_308 , V_309 ;
V_279 V_310 , V_311 , V_312 ;
if ( V_283 != 0 )
return;
if ( V_8 -> V_43 < 2 )
return;
F_60 ( & V_8 -> V_15 -> V_16 , L_126 ,
F_128 ( V_303 -> V_313 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_127 ,
F_128 ( V_303 -> V_314 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_128 ,
F_129 ( V_303 -> V_315 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_129 ,
V_303 -> V_316 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_130 ,
V_303 -> V_317 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_131 ,
F_130 ( V_303 -> V_318 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_132 ,
F_129 ( V_303 -> V_319 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_133 ,
F_129 ( V_303 -> V_320 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_134 ,
F_130 ( V_303 -> V_321 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_135 ,
F_130 ( V_303 -> V_322 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_136 ,
F_130 ( V_303 -> V_311 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_137 ,
F_130 ( V_303 -> V_323 ) ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_138 ,
F_130 ( V_303 -> V_59 ) ) ;
if ( V_303 -> V_59 & V_324 )
F_60 ( & V_8 -> V_15 -> V_16 , L_139 ) ;
else
F_60 ( & V_8 -> V_15 -> V_16 , L_140 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_141 ,
F_130 ( V_303 -> V_325 ) ) ;
V_310 = F_130 ( V_303 -> V_323 ) ;
for ( V_307 = 0 ; V_307 < V_310 ; V_307 ++ ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_142 , V_307 ) ;
V_311 = F_130 ( V_303 -> V_311 ) ;
for ( V_308 = 0 ; V_308 < V_311 ; V_308 ++ ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_143 , V_308 ) ;
V_312 =
F_130 ( V_303 -> V_321 ) ;
for ( V_309 = 0 ; V_309 < V_312 ; V_309 ++ , V_305 ++ )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_144 ,
V_309 , V_305 -> V_137 ,
V_305 -> V_326 [ 0 ] , V_305 -> V_326 [ 1 ] ) ;
V_312 =
F_130 ( V_303 -> V_322 ) ;
for ( V_309 = 0 ; V_309 < V_312 ; V_309 ++ , V_305 ++ )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_145 ,
V_309 , V_305 -> V_137 ,
V_305 -> V_326 [ 0 ] , V_305 -> V_326 [ 1 ] ) ;
}
}
}
static int F_131 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_327 )
{
int V_283 = 0 ;
struct V_9 * V_10 ;
struct V_231 * V_232 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - V_180 ;
}
if ( F_122 ( V_10 , V_328 , V_8 , & V_327 -> V_139 ,
sizeof( V_327 -> V_139 ) , 0 ,
V_54 , V_293 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_146 ) ;
F_123 ( V_8 , V_10 ) ;
return - V_180 ;
}
F_116 ( V_8 , V_10 , V_295 ) ;
V_232 = V_10 -> V_11 ;
if ( V_232 -> V_23 != 0 && V_232 -> V_23 != V_257 ) {
F_119 ( V_8 , V_10 ) ;
F_123 ( V_8 , V_10 ) ;
return - 1 ;
}
F_123 ( V_8 , V_10 ) ;
if ( F_128 ( V_327 -> V_139 . V_313 ) >
sizeof( V_327 -> V_139 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_147 ) ;
V_283 = - 1 ;
}
F_127 ( V_8 , V_283 , & V_327 -> V_139 ) ;
return V_283 ;
}
static int F_132 ( struct V_1 * V_8 ,
unsigned char V_54 [] , T_4 V_289 )
{
int V_283 ;
int V_51 ;
int V_329 ;
unsigned char * V_31 , V_290 ;
V_31 = F_81 ( 256 , V_154 ) ;
if ( ! V_31 )
return 0 ;
V_283 = F_120 ( V_8 , V_54 ,
V_301 | V_330 ,
V_31 , V_331 ) ;
if ( V_283 != 0 )
goto V_332;
V_329 = V_31 [ 3 ] ;
if ( ( V_329 + V_331 ) <= 255 )
V_290 = V_329 + V_331 ;
else
V_290 = 255 ;
V_283 = F_120 ( V_8 , V_54 ,
V_301 | V_330 ,
V_31 , V_290 ) ;
if ( V_283 != 0 )
goto V_332;
V_329 = V_31 [ 3 ] ;
for ( V_51 = 1 ; V_51 <= V_329 ; V_51 ++ )
if ( V_31 [ 3 + V_51 ] == V_289 )
goto V_333;
V_332:
F_67 ( V_31 ) ;
return 0 ;
V_333:
F_67 ( V_31 ) ;
return 1 ;
}
static void F_133 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_327 )
{
int V_283 ;
unsigned char * V_31 ;
T_4 V_334 ;
V_327 -> V_136 = 0 ;
V_327 -> V_70 = 0 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return;
if ( ! F_132 ( V_8 , V_54 , V_335 ) )
goto V_294;
V_283 = F_120 ( V_8 , V_54 ,
V_301 | V_335 , V_31 , 64 ) ;
if ( V_283 != 0 )
goto V_294;
#define F_134 4
#define F_135 0x01
#define F_136 0x02
V_334 = V_31 [ F_134 ] ;
V_327 -> V_136 =
! ! ( V_334 & F_135 ) ;
if ( V_327 -> V_136 ) {
V_327 -> V_70 =
! ! ( V_334 & F_136 ) ;
if ( F_131 ( V_8 , V_54 , V_327 ) )
V_327 -> V_70 = 0 ;
}
V_294:
F_67 ( V_31 ) ;
return;
}
static int F_137 ( struct V_1 * V_8 , unsigned char * V_54 ,
unsigned char * V_69 , int V_276 )
{
int V_283 ;
unsigned char * V_31 ;
if ( V_276 > 16 )
V_276 = 16 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return - V_180 ;
V_283 = F_120 ( V_8 , V_54 , V_301 | 0x83 , V_31 , 64 ) ;
if ( V_283 == 0 )
memcpy ( V_69 , & V_31 [ 8 ] , V_276 ) ;
F_67 ( V_31 ) ;
return V_283 != 0 ;
}
static int F_138 ( struct V_1 * V_8 , int V_336 ,
struct V_337 * V_31 , int V_290 ,
int V_338 )
{
int V_283 = V_291 ;
struct V_9 * V_10 ;
unsigned char V_54 [ 8 ] ;
struct V_231 * V_232 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - 1 ;
}
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
if ( F_122 ( V_10 , V_336 ? V_339 : V_340 , V_8 ,
V_31 , V_290 , 0 , V_54 , V_293 ) ) {
V_283 = - 1 ;
goto V_294;
}
if ( V_338 )
V_10 -> V_106 . V_107 [ 1 ] = V_338 ;
F_116 ( V_8 , V_10 , V_295 ) ;
V_232 = V_10 -> V_11 ;
if ( V_232 -> V_23 != 0 &&
V_232 -> V_23 != V_257 ) {
F_119 ( V_8 , V_10 ) ;
V_283 = - 1 ;
} else {
if ( V_31 -> V_341 != V_338 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_148 ,
V_338 ,
V_31 -> V_341 ) ;
V_283 = - 1 ;
}
}
V_294:
F_123 ( V_8 , V_10 ) ;
return V_283 ;
}
static inline int F_139 ( struct V_1 * V_8 ,
struct V_337 * V_31 ,
int V_290 , int V_338 )
{
return F_138 ( V_8 , 0 , V_31 , V_290 , V_338 ) ;
}
static inline int F_140 ( struct V_1 * V_8 ,
struct V_337 * V_31 , int V_290 )
{
return F_138 ( V_8 , 1 , V_31 , V_290 , 0 ) ;
}
static inline void F_141 ( struct V_57 * V_28 ,
int V_118 , int V_119 , int V_120 )
{
V_28 -> V_118 = V_118 ;
V_28 -> V_119 = V_119 ;
V_28 -> V_120 = V_120 ;
}
static int F_142 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
int V_283 ;
int V_33 ;
int V_342 ;
unsigned char * V_31 ;
V_31 = F_81 ( 64 , V_154 ) ;
if ( ! V_31 )
return V_158 ;
if ( ! F_132 ( V_8 , V_54 , V_343 ) )
goto V_344;
V_283 = F_120 ( V_8 , V_54 , V_301 | V_343 ,
V_31 , V_331 ) ;
if ( V_283 != 0 )
goto V_344;
V_342 = V_31 [ 3 ] ;
V_283 = F_120 ( V_8 , V_54 , V_301 | V_343 ,
V_31 , V_342 + V_331 ) ;
if ( V_283 != 0 )
goto V_344;
V_33 = V_31 [ 4 ] ;
F_67 ( V_31 ) ;
return V_33 ;
V_344:
F_67 ( V_31 ) ;
return V_158 ;
}
static int F_143 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_9 * V_10 ;
unsigned char * V_345 , V_233 , V_234 , V_235 ;
int V_346 = 0 ;
V_279 V_347 ;
T_4 V_348 ;
#define F_144 0x04
#define F_145 0x04
#define F_146 0x02
V_10 = F_147 ( V_8 ) ;
if ( ! V_10 )
return 0 ;
( void ) F_122 ( V_10 , V_349 , V_8 , NULL , 0 , 0 , V_54 , V_293 ) ;
F_108 ( V_8 , V_10 ) ;
V_345 = V_10 -> V_11 -> V_12 ;
V_233 = V_345 [ 2 ] ;
V_234 = V_345 [ 12 ] ;
V_235 = V_345 [ 13 ] ;
V_347 = V_10 -> V_11 -> V_23 ;
V_348 = V_10 -> V_11 -> V_25 ;
F_100 ( V_8 , V_10 ) ;
if ( V_347 != V_24 ||
V_348 != V_210 ||
V_233 != V_253 ||
V_234 != F_144 ) {
return 0 ;
}
V_346 = F_142 ( V_8 , V_54 ) ;
switch ( V_346 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
return V_346 ;
case V_158 :
if ( ( V_235 == F_145 ) ||
( V_235 == F_146 ) )
return V_346 ;
break;
default:
break;
}
return 0 ;
}
static int F_148 ( struct V_1 * V_8 ,
unsigned char V_54 [] , struct V_57 * V_327 ,
unsigned char * V_350 )
{
#define F_149 43
#define F_150 "$DR-10"
#define F_151 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_152 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_351 ;
unsigned char * V_352 ;
V_351 = F_81 ( F_152 , V_154 ) ;
if ( ! V_351 )
goto V_353;
if ( F_120 ( V_8 , V_54 , 0 , V_351 ,
( unsigned char ) F_152 ) != 0 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_149 ) ;
goto V_353;
}
V_327 -> V_133 = ( V_351 [ 0 ] & 0x1f ) ;
memcpy ( V_327 -> V_54 , V_54 , 8 ) ;
memcpy ( V_327 -> V_146 , & V_351 [ 8 ] ,
sizeof( V_327 -> V_146 ) ) ;
memcpy ( V_327 -> V_145 , & V_351 [ 16 ] ,
sizeof( V_327 -> V_145 ) ) ;
memset ( V_327 -> V_69 , 0 ,
sizeof( V_327 -> V_69 ) ) ;
F_137 ( V_8 , V_54 , V_327 -> V_69 ,
sizeof( V_327 -> V_69 ) ) ;
if ( V_327 -> V_133 == V_354 &&
F_22 ( V_54 ) ) {
int V_151 ;
F_126 ( V_8 , V_54 , & V_327 -> V_64 ) ;
if ( V_8 -> V_355 & V_356 )
F_133 ( V_8 , V_54 , V_327 ) ;
V_151 = F_143 ( V_8 , V_54 ) ;
if ( V_151 < 0 || V_151 > 0xff )
V_151 = V_158 ;
V_327 -> V_151 = V_151 & 0xff ;
} else {
V_327 -> V_64 = V_65 ;
V_327 -> V_136 = 0 ;
V_327 -> V_70 = 0 ;
V_327 -> V_151 = 0 ;
}
if ( V_350 ) {
V_352 = & V_351 [ F_149 ] ;
* V_350 = ( V_327 -> V_133 == V_357 &&
strncmp ( V_352 , F_150 ,
F_151 ) == 0 ) ;
}
F_67 ( V_351 ) ;
return 0 ;
V_353:
F_67 ( V_351 ) ;
return 1 ;
}
static int F_153 ( struct V_1 * V_8 , struct V_57 * V_28 )
{
int V_51 ;
for ( V_51 = 0 ; V_358 [ V_51 ] ; V_51 ++ )
if ( strncmp ( V_28 -> V_145 , V_358 [ V_51 ] ,
strlen ( V_358 [ V_51 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_154 ( struct V_1 * V_8 ,
T_4 * V_359 , struct V_57 * V_28 )
{
T_3 V_67 = F_128 ( * ( ( V_360 * ) V_359 ) ) ;
if ( ! F_22 ( V_359 ) ) {
if ( F_51 ( V_359 ) )
F_141 ( V_28 , 3 , 0 , V_67 & 0x3fff ) ;
else
F_141 ( V_28 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_153 ( V_8 , V_28 ) ) {
F_141 ( V_28 ,
1 , ( V_67 >> 16 ) & 0x3fff , V_67 & 0x00ff ) ;
return;
}
F_141 ( V_28 , 0 , 0 , V_67 & 0x3fff ) ;
}
static int F_155 ( struct V_1 * V_8 ,
struct V_57 * V_361 ,
struct V_57 * V_327 , T_4 * V_359 ,
unsigned long V_362 [] , int * V_363 )
{
unsigned char V_54 [ 8 ] ;
if ( F_156 ( V_361 -> V_119 , V_362 ) )
return 0 ;
if ( ! F_22 ( V_359 ) )
return 0 ;
if ( ! F_153 ( V_8 , V_361 ) )
return 0 ;
if ( V_361 -> V_120 == 0 )
return 0 ;
memset ( V_54 , 0 , 8 ) ;
V_54 [ 3 ] = V_361 -> V_119 ;
if ( F_51 ( V_54 ) )
return 0 ;
if ( F_52 ( V_8 ) )
return 0 ;
if ( * V_363 >= V_364 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_150
L_151
L_152 ) ;
return 0 ;
}
if ( F_148 ( V_8 , V_54 , V_327 , NULL ) )
return 0 ;
( * V_363 ) ++ ;
F_141 ( V_327 ,
V_361 -> V_118 , V_361 -> V_119 , 0 ) ;
F_157 ( V_361 -> V_119 , V_362 ) ;
return 1 ;
}
static int F_158 ( struct V_1 * V_8 ,
struct V_9 * V_365 , unsigned char * V_54 )
{
struct V_366 * V_367 = NULL ;
int V_368 = 24 ;
int V_369 = 2 ;
int V_370 = sizeof( * V_367 ) + V_371 * V_368 ;
T_3 V_372 = 0 ;
int V_121 = 0 ;
T_3 V_373 ;
int V_51 ;
struct V_199 * V_374 ;
struct V_57 * V_288 ;
struct V_99 * V_375 ;
T_3 V_376 ;
T_3 V_377 ;
if ( V_365 -> V_112 != V_114 )
return 0 ;
V_375 = & V_8 -> V_100 [ V_365 -> V_96 ] ;
if ( V_375 == NULL )
return 0 ;
V_374 = (struct V_199 * ) V_365 -> V_237 ;
if ( V_374 == NULL )
return 0 ;
V_288 = V_374 -> V_28 -> V_61 ;
if ( V_288 == NULL )
return 0 ;
V_376 = F_159 ( ( T_3 ) V_288 -> V_137 ) ;
V_377 = F_159 ( ( T_3 ) V_375 -> V_377 ) ;
V_373 = V_375 -> V_377 ;
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_153 ,
V_155 , V_377 ,
V_288 -> V_69 [ 0 ] , V_288 -> V_69 [ 1 ] , V_288 -> V_69 [ 2 ] ,
V_288 -> V_69 [ 3 ] , V_288 -> V_69 [ 4 ] , V_288 -> V_69 [ 5 ] ,
V_288 -> V_69 [ 6 ] , V_288 -> V_69 [ 7 ] , V_288 -> V_69 [ 8 ] ,
V_288 -> V_69 [ 9 ] , V_288 -> V_69 [ 10 ] , V_288 -> V_69 [ 11 ] ,
V_288 -> V_69 [ 12 ] , V_288 -> V_69 [ 13 ] , V_288 -> V_69 [ 14 ] ,
V_288 -> V_69 [ 15 ] ) ;
V_367 = F_81 ( V_370 , V_154 ) ;
if ( V_367 == NULL )
return 0 ;
if ( F_139 ( V_8 , (struct V_337 * ) V_367 ,
V_370 , V_369 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_154 ,
L_60 ) ;
F_67 ( V_367 ) ;
return 0 ;
}
V_372 = F_160 ( * ( ( V_378 * ) V_367 -> V_379 ) ) /
V_368 ;
for ( V_51 = 0 ; V_51 < V_372 ; V_51 ++ ) {
struct V_380 * V_134 = & V_367 -> V_247 [ V_51 ] ;
if ( V_134 -> V_137 != V_373 )
continue;
V_121 = 1 ;
memcpy ( V_54 , V_134 -> V_67 , 8 ) ;
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_155 ,
V_155 , V_373 ,
V_134 -> V_137 , V_54 ) ;
break;
}
F_67 ( V_367 ) ;
if ( V_121 )
return 1 ;
else
return 0 ;
}
static int F_161 ( struct V_1 * V_8 ,
int V_381 ,
struct V_337 * V_382 , T_3 * V_372 , int * V_383 ,
struct V_337 * V_384 , T_3 * V_385 )
{
int V_386 = 8 ;
* V_383 = 0 ;
if ( V_8 -> V_48 & V_78 ||
V_8 -> V_48 & V_387 ) {
* V_383 = V_388 ;
V_386 = 24 ;
}
if ( F_139 ( V_8 , V_382 , V_381 ,
* V_383 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_156 ) ;
return - 1 ;
}
* V_372 = F_160 ( * ( ( V_378 * ) V_382 -> V_379 ) ) /
V_386 ;
if ( * V_372 > V_371 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_157
L_158 , V_371 ,
* V_372 - V_371 ) ;
* V_372 = V_371 ;
}
if ( F_140 ( V_8 , V_384 , V_381 ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_159 ) ;
return - 1 ;
}
* V_385 = F_160 ( * ( ( V_378 * ) V_384 -> V_379 ) ) / 8 ;
if ( * V_385 > V_389 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_160
L_161 , V_389 ,
* V_385 - V_389 ) ;
* V_385 = V_389 ;
}
if ( * V_385 + * V_372 > V_371 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_162
L_161 , V_371 ,
* V_372 + * V_385 - V_371 ) ;
* V_385 = V_371 - * V_372 ;
}
return 0 ;
}
T_4 * F_162 ( struct V_1 * V_8 , int V_390 , int V_51 ,
int V_372 , int V_385 ,
struct V_366 * V_391 ,
struct V_337 * V_392 )
{
int V_393 = V_372 + ( V_390 == 0 ) ;
int V_394 = V_372 + V_385 + ( V_390 == 0 ) ;
if ( V_51 == V_390 )
return V_117 ;
if ( V_51 < V_393 )
return & V_391 -> V_247 [ V_51 -
( V_390 == 0 ) ] . V_67 [ 0 ] ;
if ( V_51 < V_394 )
return & V_392 -> V_247 [ V_51 - V_372 -
( V_390 == 0 ) ] [ 0 ] ;
F_163 () ;
return NULL ;
}
static int F_164 ( struct V_1 * V_8 )
{
int V_283 ;
int V_395 ;
struct V_296 * V_396 ;
V_396 = F_81 ( sizeof( struct V_296 ) ,
V_154 ) ;
if ( ! V_396 )
return - V_180 ;
V_283 = F_124 ( V_8 , V_117 , 0 , V_396 ,
sizeof( struct V_296 ) ) ;
if ( V_283 ) {
F_67 ( V_396 ) ;
return V_283 ;
}
V_395 =
( ( V_396 -> V_397 & V_398 ) != 0 ) ;
F_67 ( V_396 ) ;
return V_395 ;
}
static void F_165 ( struct V_1 * V_8 , int V_125 )
{
struct V_366 * V_391 = NULL ;
struct V_337 * V_392 = NULL ;
T_3 V_372 = 0 ;
T_3 V_385 = 0 ;
int V_383 = 0 ;
T_3 V_399 = 0 ;
struct V_57 * * V_400 , * V_327 , * V_361 ;
int V_401 = 0 ;
int V_381 = sizeof( * V_391 ) + V_371 * 24 ;
int V_51 , V_363 , V_402 ;
int V_390 ;
int V_403 ;
F_54 ( V_362 , V_364 ) ;
V_400 = F_81 ( sizeof( * V_400 ) * V_123 , V_154 ) ;
V_391 = F_81 ( V_381 , V_154 ) ;
V_392 = F_81 ( V_381 , V_154 ) ;
V_361 = F_81 ( sizeof( * V_361 ) , V_154 ) ;
if ( ! V_400 || ! V_391 || ! V_392 || ! V_361 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_163 ) ;
goto V_294;
}
memset ( V_362 , 0 , sizeof( V_362 ) ) ;
V_403 = F_164 ( V_8 ) ;
if ( V_403 < 0 )
goto V_294;
if ( ! V_8 -> V_395 && V_403 )
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ) ;
else if ( V_8 -> V_395 && ! V_403 )
F_5 ( & V_8 -> V_15 -> V_16 , L_165 ) ;
V_8 -> V_395 = V_403 ;
if ( F_161 ( V_8 , V_381 ,
(struct V_337 * ) V_391 , & V_372 ,
& V_383 , V_392 , & V_385 ) )
goto V_294;
V_402 = V_372 + V_385 + V_364 + 1 ;
for ( V_51 = 0 ; V_51 < V_402 ; V_51 ++ ) {
if ( V_51 >= V_123 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_166
L_167 , V_123 ,
V_402 - V_123 ) ;
break;
}
V_400 [ V_51 ] = F_81 ( sizeof( * V_400 [ V_51 ] ) , V_154 ) ;
if ( ! V_400 [ V_51 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_168 ,
__FILE__ , __LINE__ ) ;
goto V_294;
}
V_399 ++ ;
}
if ( F_52 ( V_8 ) )
V_390 = 0 ;
else
V_390 = V_372 + V_385 ;
V_363 = 0 ;
for ( V_51 = 0 ; V_51 < V_372 + V_385 + 1 ; V_51 ++ ) {
T_4 * V_359 , V_404 = 0 ;
V_359 = F_162 ( V_8 , V_390 ,
V_51 , V_372 , V_385 , V_391 , V_392 ) ;
if ( V_359 [ 3 ] & 0xC0 &&
V_51 < V_372 + ( V_390 == 0 ) )
continue;
if ( F_148 ( V_8 , V_359 , V_361 ,
& V_404 ) )
continue;
F_154 ( V_8 , V_359 , V_361 ) ;
V_327 = V_400 [ V_401 ] ;
if ( F_155 ( V_8 , V_361 , V_327 ,
V_359 , V_362 ,
& V_363 ) ) {
V_401 ++ ;
V_327 = V_400 [ V_401 ] ;
}
* V_327 = * V_361 ;
switch ( V_327 -> V_133 ) {
case V_357 :
if ( V_404 )
V_401 ++ ;
break;
case V_354 :
if ( V_8 -> V_395 ) {
V_327 -> V_70 = 0 ;
V_401 ++ ;
break;
} else if ( V_8 -> V_41 ) {
if ( V_51 >= V_372 ) {
V_401 ++ ;
break;
}
} else {
if ( V_51 < V_372 )
break;
V_401 ++ ;
break;
}
if ( V_383 == V_388 ) {
memcpy ( & V_327 -> V_137 ,
& V_359 [ 20 ] ,
sizeof( V_327 -> V_137 ) ) ;
V_401 ++ ;
}
break;
case V_405 :
case V_406 :
V_401 ++ ;
break;
case V_407 :
if ( ! F_51 ( V_359 ) )
break;
V_401 ++ ;
break;
default:
break;
}
if ( V_401 >= V_123 )
break;
}
F_80 ( V_8 , V_125 , V_400 , V_401 ) ;
V_294:
F_67 ( V_361 ) ;
for ( V_51 = 0 ; V_51 < V_399 ; V_51 ++ )
F_67 ( V_400 [ V_51 ] ) ;
F_67 ( V_400 ) ;
F_67 ( V_391 ) ;
F_67 ( V_392 ) ;
}
static int F_166 ( struct V_1 * V_8 ,
struct V_9 * V_94 ,
struct V_199 * V_200 )
{
unsigned int V_34 ;
struct V_408 * V_409 ;
T_5 V_274 ;
int V_410 , V_51 , V_411 , V_412 ;
struct V_182 * V_413 ;
F_63 ( F_104 ( V_200 ) > V_8 -> V_414 ) ;
V_410 = F_167 ( V_200 ) ;
if ( V_410 < 0 )
return V_410 ;
if ( ! V_410 )
goto V_415;
V_413 = V_94 -> V_186 ;
V_412 = 0 ;
V_411 = 0 ;
F_168 (cmd, sg, use_sg, i) {
if ( V_51 == V_8 -> V_187 - 1 &&
V_410 > V_8 -> V_187 ) {
V_412 = 1 ;
V_413 = V_8 -> V_177 [ V_94 -> V_96 ] ;
V_411 = 0 ;
}
V_274 = ( T_5 ) F_169 ( V_409 ) ;
V_34 = F_170 ( V_409 ) ;
V_413 -> V_193 . V_194 = ( T_3 ) ( V_274 & 0x0FFFFFFFFULL ) ;
V_413 -> V_193 . V_195 = ( T_3 ) ( ( V_274 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_413 -> V_190 = V_34 ;
V_413 -> V_188 = ( V_51 < F_104 ( V_200 ) - 1 ) ? 0 : V_278 ;
V_413 ++ ;
}
if ( V_410 + V_412 > V_8 -> V_416 )
V_8 -> V_416 = V_410 + V_412 ;
if ( V_412 ) {
V_94 -> V_88 . V_89 = V_8 -> V_187 ;
V_94 -> V_88 . V_191 = ( V_279 ) ( V_410 + 1 ) ;
if ( F_93 ( V_8 , V_94 ) ) {
F_102 ( V_200 ) ;
return - 1 ;
}
return 0 ;
}
V_415:
V_94 -> V_88 . V_89 = ( T_4 ) V_410 ;
V_94 -> V_88 . V_191 = ( V_279 ) V_410 ;
return 0 ;
}
static int F_171 ( T_4 * V_103 , int * V_417 )
{
int V_418 = 0 ;
T_3 V_419 ;
T_3 V_420 ;
switch ( V_103 [ 0 ] ) {
case V_421 :
case V_422 :
V_418 = 1 ;
case V_423 :
case V_424 :
if ( * V_417 == 6 ) {
V_419 = ( ( ( T_3 ) V_103 [ 2 ] ) << 8 ) | V_103 [ 3 ] ;
V_420 = V_103 [ 4 ] ;
} else {
F_63 ( * V_417 != 12 ) ;
V_419 = ( ( ( T_3 ) V_103 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 4 ] ) << 8 ) |
V_103 [ 5 ] ;
V_420 =
( ( ( T_3 ) V_103 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_103 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_103 [ 8 ] ) << 8 ) |
V_103 [ 9 ] ;
}
if ( V_420 > 0xffff )
return V_425 ;
V_103 [ 0 ] = V_418 ? V_426 : V_427 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_419 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_419 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_419 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_419 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_420 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_420 ) ;
V_103 [ 9 ] = 0 ;
* V_417 = 10 ;
break;
}
return 0 ;
}
static int F_172 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_417 ,
T_4 * V_54 )
{
struct V_199 * V_200 = V_10 -> V_237 ;
struct V_93 * V_94 = & V_8 -> V_95 [ V_10 -> V_96 ] ;
unsigned int V_34 ;
unsigned int V_428 = 0 ;
struct V_408 * V_409 ;
T_5 V_274 ;
int V_410 , V_51 ;
struct V_182 * V_413 ;
T_3 V_429 = V_430 ;
if ( F_104 ( V_200 ) > V_8 -> V_431 )
return V_425 ;
F_63 ( V_200 -> V_432 > V_433 ) ;
if ( F_171 ( V_103 , & V_417 ) )
return V_425 ;
V_10 -> V_112 = V_113 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_434 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_63 ( V_10 -> V_86 & 0x0000007F ) ;
V_410 = F_167 ( V_200 ) ;
if ( V_410 < 0 )
return V_410 ;
if ( V_410 ) {
V_413 = V_94 -> V_186 ;
F_168 (cmd, sg, use_sg, i) {
V_274 = ( T_5 ) F_169 ( V_409 ) ;
V_34 = F_170 ( V_409 ) ;
V_428 += V_34 ;
V_413 -> V_193 . V_194 = ( T_3 ) ( V_274 & 0x0FFFFFFFFULL ) ;
V_413 -> V_193 . V_195 =
( T_3 ) ( ( V_274 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_413 -> V_190 = V_34 ;
if ( V_51 == ( F_104 ( V_200 ) - 1 ) )
V_413 -> V_188 = V_278 ;
else
V_413 -> V_188 = 0 ;
V_413 ++ ;
}
switch ( V_200 -> V_435 ) {
case V_436 :
V_429 |= V_437 ;
break;
case V_438 :
V_429 |= V_439 ;
break;
case V_440 :
V_429 |= V_441 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_169 ,
V_200 -> V_435 ) ;
F_163 () ;
break;
}
} else {
V_429 |= V_441 ;
}
V_10 -> V_88 . V_89 = V_410 ;
V_94 -> V_442 = V_137 & 0xFFFF ;
V_94 -> V_443 = V_428 ;
V_94 -> V_244 = V_444 |
( V_417 & V_245 ) ;
V_94 -> V_429 = V_429 ;
memcpy ( V_94 -> V_107 , V_103 , V_417 ) ;
memcpy ( V_94 -> V_249 , V_54 , 8 ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_199 * V_200 = V_10 -> V_237 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
return F_174 ( V_8 , V_10 , V_16 -> V_137 ,
V_200 -> V_255 , V_200 -> V_432 , V_16 -> V_54 ) ;
}
static void F_175 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_99 * V_94 )
{
struct V_199 * V_200 = V_10 -> V_237 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
struct V_302 * V_307 = & V_16 -> V_139 ;
T_5 V_445 ;
F_63 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
if ( ! ( V_307 -> V_59 & V_324 ) )
return;
V_94 -> V_325 = V_307 -> V_325 ;
V_94 -> V_446 |= V_447 ;
switch ( V_200 -> V_255 [ 0 ] ) {
case V_421 :
case V_423 :
if ( V_307 -> V_314 == 512 ) {
V_94 -> V_448 =
( ( ( T_3 ) V_200 -> V_255 [ 2 ] ) << 8 ) |
V_200 -> V_255 [ 3 ] ;
V_94 -> V_449 = 0 ;
} else {
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 8 ) |
V_200 -> V_255 [ 3 ] ;
V_445 = ( V_445 * V_307 -> V_314 ) / 512 ;
V_94 -> V_448 = ( T_3 ) V_445 ;
V_94 -> V_449 = ( T_3 ) ( V_445 >> 32 ) ;
}
break;
case V_426 :
case V_427 :
if ( V_307 -> V_314 == 512 ) {
V_94 -> V_448 =
( ( ( T_3 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_94 -> V_449 = 0 ;
} else {
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_445 = ( V_445 * V_307 -> V_314 ) / 512 ;
V_94 -> V_448 = ( T_3 ) V_445 ;
V_94 -> V_449 = ( T_3 ) ( V_445 >> 32 ) ;
}
break;
case V_422 :
case V_424 :
if ( V_307 -> V_314 == 512 ) {
V_94 -> V_448 =
( ( ( T_3 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_94 -> V_449 = 0 ;
} else {
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_445 = ( V_445 * V_307 -> V_314 ) / 512 ;
V_94 -> V_448 = ( T_3 ) V_445 ;
V_94 -> V_449 = ( T_3 ) ( V_445 >> 32 ) ;
}
break;
case V_450 :
case V_451 :
if ( V_307 -> V_314 == 512 ) {
V_94 -> V_448 =
( ( ( T_3 ) V_200 -> V_255 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 8 ] ) << 8 ) |
V_200 -> V_255 [ 9 ] ;
V_94 -> V_449 =
( ( ( T_3 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
} else {
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_200 -> V_255 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_200 -> V_255 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 8 ] ) << 8 ) |
V_200 -> V_255 [ 9 ] ;
V_445 = ( V_445 * V_307 -> V_314 ) / 512 ;
V_94 -> V_448 = ( T_3 ) V_445 ;
V_94 -> V_449 = ( T_3 ) ( V_445 >> 32 ) ;
}
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 ,
L_170 ,
V_155 ) ;
F_163 () ;
break;
}
}
static int F_176 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_417 ,
T_4 * V_54 )
{
struct V_199 * V_200 = V_10 -> V_237 ;
struct V_99 * V_94 = & V_8 -> V_100 [ V_10 -> V_96 ] ;
struct V_452 * V_413 ;
int V_410 , V_51 ;
struct V_408 * V_409 ;
T_5 V_274 ;
T_3 V_34 ;
T_3 V_428 = 0 ;
if ( F_104 ( V_200 ) > V_8 -> V_431 )
return V_425 ;
if ( F_171 ( V_103 , & V_417 ) )
return V_425 ;
V_10 -> V_112 = V_114 ;
V_10 -> V_86 = ( T_3 ) V_8 -> V_453 +
( V_10 -> V_96 * sizeof( * V_94 ) ) ;
F_63 ( V_10 -> V_86 & 0x0000007F ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_454 = V_455 ;
V_410 = F_167 ( V_200 ) ;
if ( V_410 < 0 )
return V_410 ;
if ( V_410 ) {
F_63 ( V_410 > V_456 ) ;
V_413 = V_94 -> V_409 ;
F_168 (cmd, sg, use_sg, i) {
V_274 = ( T_5 ) F_169 ( V_409 ) ;
V_34 = F_170 ( V_409 ) ;
V_428 += V_34 ;
V_413 -> V_457 = F_177 ( V_274 ) ;
V_413 -> V_458 = F_159 ( V_34 ) ;
V_413 -> V_459 [ 0 ] = 0 ;
V_413 -> V_459 [ 1 ] = 0 ;
V_413 -> V_459 [ 2 ] = 0 ;
V_413 -> V_460 = 0 ;
V_413 ++ ;
}
switch ( V_200 -> V_435 ) {
case V_436 :
V_94 -> V_446 &= ~ V_461 ;
V_94 -> V_446 |= V_462 ;
break;
case V_438 :
V_94 -> V_446 &= ~ V_461 ;
V_94 -> V_446 |= V_463 ;
break;
case V_440 :
V_94 -> V_446 &= ~ V_461 ;
V_94 -> V_446 |= V_464 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_169 ,
V_200 -> V_435 ) ;
F_163 () ;
break;
}
} else {
V_94 -> V_446 &= ~ V_461 ;
V_94 -> V_446 |= V_464 ;
}
F_175 ( V_8 , V_10 , V_94 ) ;
V_94 -> V_377 = V_137 ;
V_94 -> V_246 = ( V_10 -> V_96 << V_465 ) |
V_466 ;
memcpy ( V_94 -> V_103 , V_103 , sizeof( V_94 -> V_103 ) ) ;
V_94 -> V_102 = ( T_4 ) V_410 ;
V_94 -> V_202 = F_159 ( V_428 ) ;
V_94 -> V_467 = F_177 ( V_10 -> V_86 +
F_178 ( struct V_99 , V_204 ) ) ;
V_94 -> V_468 = F_159 ( ( T_3 ) sizeof( V_94 -> V_204 ) ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_137 , T_4 * V_103 , int V_417 ,
T_4 * V_54 )
{
if ( V_8 -> V_48 & V_78 )
return F_172 ( V_8 , V_10 , V_137 ,
V_103 , V_417 , V_54 ) ;
else
return F_176 ( V_8 , V_10 , V_137 ,
V_103 , V_417 , V_54 ) ;
}
static void F_179 ( struct V_302 * V_307 ,
int V_138 , T_3 * V_469 , T_3 * V_470 )
{
if ( V_138 == 0 ) {
* V_469 %= V_307 -> V_321 ;
return;
}
do {
* V_470 = * V_469 / V_307 -> V_321 ;
if ( V_138 == * V_470 )
continue;
if ( * V_470 < ( V_307 -> V_323 - 1 ) ) {
* V_469 += V_307 -> V_321 ;
( * V_470 ) ++ ;
} else {
* V_469 %= V_307 -> V_321 ;
* V_470 = 0 ;
}
} while ( V_138 != * V_470 );
}
static int F_180 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_199 * V_200 = V_10 -> V_237 ;
struct V_57 * V_16 = V_200 -> V_28 -> V_61 ;
struct V_302 * V_307 = & V_16 -> V_139 ;
struct V_304 * V_305 = & V_307 -> V_306 [ 0 ] ;
int V_418 = 0 ;
T_3 V_469 ;
T_5 V_445 , V_471 ;
T_3 V_420 ;
T_3 V_472 ;
T_5 V_473 , V_474 ;
T_3 V_475 , V_476 ;
T_3 V_477 , V_478 ;
T_5 V_479 , V_480 ;
T_3 V_481 ;
T_5 V_482 , V_483 ;
T_3 V_484 , V_485 ;
T_3 V_486 , V_487 ;
T_3 V_488 ;
T_3 V_489 ;
T_3 V_490 , V_491 , V_470 ;
T_3 V_492 ;
T_3 V_493 ;
T_5 V_494 ;
T_3 V_495 ;
T_4 V_103 [ 16 ] ;
T_4 V_417 ;
#if V_496 == 32
T_5 V_497 ;
#endif
int V_138 ;
F_63 ( ! ( V_16 -> V_136 && V_16 -> V_70 ) ) ;
switch ( V_200 -> V_255 [ 0 ] ) {
case V_421 :
V_418 = 1 ;
case V_423 :
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 8 ) |
V_200 -> V_255 [ 3 ] ;
V_420 = V_200 -> V_255 [ 4 ] ;
if ( V_420 == 0 )
V_420 = 256 ;
break;
case V_426 :
V_418 = 1 ;
case V_427 :
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_420 =
( ( ( T_3 ) V_200 -> V_255 [ 7 ] ) << 8 ) |
V_200 -> V_255 [ 8 ] ;
break;
case V_422 :
V_418 = 1 ;
case V_424 :
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 8 ) |
V_200 -> V_255 [ 5 ] ;
V_420 =
( ( ( T_3 ) V_200 -> V_255 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 8 ] ) << 8 ) |
V_200 -> V_255 [ 9 ] ;
break;
case V_450 :
V_418 = 1 ;
case V_451 :
V_445 =
( ( ( T_5 ) V_200 -> V_255 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_200 -> V_255 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_200 -> V_255 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_200 -> V_255 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_200 -> V_255 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_200 -> V_255 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_200 -> V_255 [ 8 ] ) << 8 ) |
V_200 -> V_255 [ 9 ] ;
V_420 =
( ( ( T_3 ) V_200 -> V_255 [ 10 ] ) << 24 ) |
( ( ( T_3 ) V_200 -> V_255 [ 11 ] ) << 16 ) |
( ( ( T_3 ) V_200 -> V_255 [ 12 ] ) << 8 ) |
V_200 -> V_255 [ 13 ] ;
break;
default:
return V_425 ;
}
V_471 = V_445 + V_420 - 1 ;
if ( V_418 && V_16 -> V_64 != 0 )
return V_425 ;
if ( V_471 >= V_307 -> V_315 || V_471 < V_445 )
return V_425 ;
V_472 = V_307 -> V_321 * V_307 -> V_318 ;
#if V_496 == 32
V_497 = V_445 ;
( void ) F_181 ( V_497 , V_472 ) ;
V_473 = V_497 ;
V_497 = V_471 ;
( void ) F_181 ( V_497 , V_472 ) ;
V_474 = V_497 ;
V_475 = ( T_3 ) ( V_445 - ( V_473 * V_472 ) ) ;
V_476 = ( T_3 ) ( V_471 - ( V_474 * V_472 ) ) ;
V_497 = V_475 ;
( void ) F_181 ( V_497 , V_307 -> V_318 ) ;
V_477 = V_497 ;
V_497 = V_476 ;
( void ) F_181 ( V_497 , V_307 -> V_318 ) ;
V_478 = V_497 ;
#else
V_473 = V_445 / V_472 ;
V_474 = V_471 / V_472 ;
V_475 = ( T_3 ) ( V_445 - ( V_473 * V_472 ) ) ;
V_476 = ( T_3 ) ( V_471 - ( V_474 * V_472 ) ) ;
V_477 = V_475 / V_307 -> V_318 ;
V_478 = V_476 / V_307 -> V_318 ;
#endif
if ( ( V_473 != V_474 ) || ( V_477 != V_478 ) )
return V_425 ;
V_488 = V_307 -> V_321 +
V_307 -> V_322 ;
V_492 = ( ( T_3 ) ( V_473 >> V_307 -> V_317 ) ) %
V_307 -> V_311 ;
V_469 = ( V_492 * V_488 ) + V_477 ;
switch ( V_16 -> V_64 ) {
case V_498 :
break;
case V_499 :
F_63 ( V_307 -> V_323 != 2 ) ;
if ( V_16 -> V_138 )
V_469 += V_307 -> V_321 ;
V_16 -> V_138 = ! V_16 -> V_138 ;
break;
case V_500 :
F_63 ( V_307 -> V_323 != 3 ) ;
V_138 = V_16 -> V_138 ;
F_179 ( V_307 , V_138 ,
& V_469 , & V_470 ) ;
V_138 =
( V_138 >= V_307 -> V_323 - 1 )
? 0 : V_138 + 1 ;
F_63 ( V_138 >= V_307 -> V_323 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_171 ,
V_469 , V_138 ) ;
V_16 -> V_138 = V_138 ;
break;
case V_501 :
case V_502 :
if ( V_307 -> V_323 <= 1 )
break;
V_481 =
V_307 -> V_318 * V_307 -> V_321 ;
F_63 ( V_481 == 0 ) ;
V_489 = V_481 * V_307 -> V_323 ;
#if V_496 == 32
V_497 = V_445 ;
V_490 = F_181 ( V_497 , V_489 ) ;
V_497 = V_490 ;
( void ) F_181 ( V_497 , V_481 ) ;
V_490 = V_497 ;
V_497 = V_471 ;
V_491 = F_181 ( V_497 , V_489 ) ;
V_497 = V_491 ;
( void ) F_181 ( V_497 , V_481 ) ;
V_491 = V_497 ;
#else
V_490 = ( V_445 % V_489 ) / V_481 ;
V_491 = ( V_471 % V_489 ) / V_481 ;
#endif
if ( V_490 != V_491 )
return V_425 ;
#if V_496 == 32
V_497 = V_445 ;
( void ) F_181 ( V_497 , V_489 ) ;
V_473 = V_482 = V_479 = V_497 ;
V_497 = V_471 ;
( void ) F_181 ( V_497 , V_489 ) ;
V_483 = V_480 = V_497 ;
#else
V_473 = V_482 = V_479 =
V_445 / V_489 ;
V_483 = V_480 = V_471 / V_489 ;
#endif
if ( V_482 != V_483 )
return V_425 ;
#if V_496 == 32
V_497 = V_445 ;
V_475 = F_181 ( V_497 , V_489 ) ;
V_497 = V_475 ;
V_475 = ( T_3 ) F_181 ( V_497 , V_481 ) ;
V_484 = V_475 ;
V_497 = V_471 ;
V_485 = F_181 ( V_497 , V_489 ) ;
V_497 = V_485 ;
V_485 = F_181 ( V_497 , V_481 ) ;
V_497 = V_484 ;
( void ) F_181 ( V_497 , V_307 -> V_318 ) ;
V_477 = V_486 = V_497 ;
V_497 = V_485 ;
( void ) F_181 ( V_497 , V_307 -> V_318 ) ;
V_487 = V_497 ;
#else
V_475 = V_484 =
( T_3 ) ( ( V_445 % V_489 ) %
V_481 ) ;
V_485 =
( T_3 ) ( ( V_471 % V_489 ) %
V_481 ) ;
V_477 = V_486 =
V_484 / V_307 -> V_318 ;
V_487 =
V_485 / V_307 -> V_318 ;
#endif
if ( V_486 != V_487 )
return V_425 ;
V_492 = ( ( T_3 ) ( V_473 >> V_307 -> V_317 ) ) %
V_307 -> V_311 ;
V_469 = ( V_490 *
( V_307 -> V_311 * V_488 ) ) +
( V_492 * V_488 ) + V_477 ;
break;
default:
return V_425 ;
}
V_493 = V_305 [ V_469 ] . V_137 ;
V_494 = V_307 -> V_319 + ( V_473 * V_307 -> V_318 ) +
( V_475 - ( V_477 * V_307 -> V_318 ) ) ;
V_495 = V_420 ;
if ( V_307 -> V_316 ) {
V_494 <<= V_307 -> V_316 ;
V_495 <<= V_307 -> V_316 ;
}
F_63 ( V_495 > 0xffff ) ;
if ( V_494 > 0xffffffff ) {
V_103 [ 0 ] = V_418 ? V_450 : V_451 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_494 >> 56 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_494 >> 48 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_494 >> 40 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_494 >> 32 ) ;
V_103 [ 6 ] = ( T_4 ) ( V_494 >> 24 ) ;
V_103 [ 7 ] = ( T_4 ) ( V_494 >> 16 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_494 >> 8 ) ;
V_103 [ 9 ] = ( T_4 ) ( V_494 ) ;
V_103 [ 10 ] = ( T_4 ) ( V_495 >> 24 ) ;
V_103 [ 11 ] = ( T_4 ) ( V_495 >> 16 ) ;
V_103 [ 12 ] = ( T_4 ) ( V_495 >> 8 ) ;
V_103 [ 13 ] = ( T_4 ) ( V_495 ) ;
V_103 [ 14 ] = 0 ;
V_103 [ 15 ] = 0 ;
V_417 = 16 ;
} else {
V_103 [ 0 ] = V_418 ? V_426 : V_427 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = ( T_4 ) ( V_494 >> 24 ) ;
V_103 [ 3 ] = ( T_4 ) ( V_494 >> 16 ) ;
V_103 [ 4 ] = ( T_4 ) ( V_494 >> 8 ) ;
V_103 [ 5 ] = ( T_4 ) ( V_494 ) ;
V_103 [ 6 ] = 0 ;
V_103 [ 7 ] = ( T_4 ) ( V_495 >> 8 ) ;
V_103 [ 8 ] = ( T_4 ) ( V_495 ) ;
V_103 [ 9 ] = 0 ;
V_417 = 10 ;
}
return F_174 ( V_8 , V_10 , V_493 , V_103 , V_417 ,
V_16 -> V_54 ) ;
}
static int F_182 ( struct V_199 * V_200 ,
void (* F_183)( struct V_199 * ) )
{
struct V_1 * V_8 ;
struct V_57 * V_16 ;
unsigned char V_54 [ 8 ] ;
struct V_9 * V_10 ;
int V_283 = 0 ;
V_8 = F_1 ( V_200 -> V_28 ) ;
V_16 = V_200 -> V_28 -> V_61 ;
if ( ! V_16 ) {
V_200 -> V_209 = V_256 << 16 ;
F_183 ( V_200 ) ;
return 0 ;
}
memcpy ( V_54 , V_16 -> V_54 , sizeof( V_54 ) ) ;
if ( F_33 ( F_111 ( V_8 ) ) ) {
V_200 -> V_209 = V_261 << 16 ;
F_183 ( V_200 ) ;
return 0 ;
}
V_10 = F_147 ( V_8 ) ;
if ( V_10 == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_172 ) ;
return V_503 ;
}
V_200 -> V_228 = F_183 ;
V_200 -> V_504 = ( unsigned char * ) V_10 ;
V_10 -> V_112 = V_238 ;
V_10 -> V_237 = V_200 ;
if ( F_35 ( V_200 -> V_505 == 0 &&
V_200 -> V_506 -> V_112 == V_507 &&
V_8 -> V_41 ) ) {
if ( V_16 -> V_70 ) {
V_283 = F_180 ( V_8 , V_10 ) ;
if ( V_283 == 0 )
return 0 ;
if ( V_283 < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_503 ;
}
} else if ( V_16 -> V_137 ) {
V_283 = F_173 ( V_8 , V_10 ) ;
if ( V_283 == 0 )
return 0 ;
if ( V_283 < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_503 ;
}
}
}
V_10 -> V_88 . V_91 = 0 ;
memcpy ( & V_10 -> V_88 . V_247 . V_248 [ 0 ] , & V_54 [ 0 ] , 8 ) ;
V_10 -> V_88 . V_246 . V_194 = ( V_10 -> V_96 << V_465 ) ;
V_10 -> V_88 . V_246 . V_194 |= V_466 ;
V_10 -> V_106 . V_508 = 0 ;
memset ( V_10 -> V_106 . V_107 , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
F_63 ( V_200 -> V_432 > sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_243 = V_200 -> V_432 ;
memcpy ( V_10 -> V_106 . V_107 , V_200 -> V_255 , V_200 -> V_432 ) ;
V_10 -> V_106 . Type . Type = V_293 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
switch ( V_200 -> V_435 ) {
case V_436 :
V_10 -> V_106 . Type . V_511 = V_512 ;
break;
case V_438 :
V_10 -> V_106 . Type . V_511 = V_513 ;
break;
case V_440 :
V_10 -> V_106 . Type . V_511 = V_514 ;
break;
case V_515 :
V_10 -> V_106 . Type . V_511 = V_516 ;
break;
default:
F_59 ( & V_8 -> V_15 -> V_16 , L_169 ,
V_200 -> V_435 ) ;
F_163 () ;
break;
}
if ( F_166 ( V_8 , V_10 , V_200 ) < 0 ) {
F_100 ( V_8 , V_10 ) ;
return V_503 ;
}
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
if ( F_184 ( V_8 ) )
return;
while ( 1 ) {
F_25 ( & V_8 -> V_517 , V_59 ) ;
if ( V_8 -> V_518 )
break;
F_26 ( & V_8 -> V_517 , V_59 ) ;
F_185 ( V_8 -> V_519 , V_8 -> V_518 ) ;
}
V_8 -> V_518 = 0 ;
F_26 ( & V_8 -> V_517 , V_59 ) ;
if ( F_184 ( V_8 ) )
return;
F_165 ( V_8 , V_8 -> V_44 -> V_159 ) ;
F_25 ( & V_8 -> V_517 , V_59 ) ;
V_8 -> V_518 = 1 ;
F_186 ( & V_8 -> V_519 ) ;
F_26 ( & V_8 -> V_517 , V_59 ) ;
}
static int F_187 ( struct V_6 * V_7 ,
unsigned long V_520 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
int V_521 ;
F_25 ( & V_8 -> V_517 , V_59 ) ;
V_521 = V_8 -> V_518 ;
F_26 ( & V_8 -> V_517 , V_59 ) ;
return V_521 ;
}
static int F_188 ( struct V_2 * V_3 ,
int V_522 , int V_523 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_523 != V_524 )
return - V_525 ;
if ( V_522 < 1 )
V_522 = 1 ;
else
if ( V_522 > V_8 -> V_178 )
V_522 = V_8 -> V_178 ;
F_189 ( V_3 , F_190 ( V_3 ) , V_522 ) ;
return V_3 -> V_526 ;
}
static void F_191 ( struct V_1 * V_8 )
{
F_192 ( V_8 -> V_44 ) ;
F_193 ( V_8 -> V_44 ) ;
V_8 -> V_44 = NULL ;
}
static int F_194 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_195 ( & V_527 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_528;
V_7 -> V_529 = 0 ;
V_7 -> V_530 = 0 ;
V_7 -> V_531 = - 1 ;
V_7 -> V_532 = 3 ;
V_7 -> V_533 = V_534 ;
V_7 -> V_535 = V_389 ;
V_7 -> V_536 = V_389 ;
V_7 -> V_537 = V_8 -> V_178 ;
if ( V_8 -> V_395 )
V_7 -> V_538 = 7 ;
else
V_7 -> V_538 = V_8 -> V_178 ;
V_7 -> V_539 = V_8 -> V_414 ;
V_8 -> V_44 = V_7 ;
V_7 -> V_61 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_540 = V_8 -> V_541 [ V_8 -> V_542 ] ;
V_7 -> V_543 = V_7 -> V_540 ;
error = F_196 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_544;
F_197 ( V_7 ) ;
return 0 ;
V_544:
F_59 ( & V_8 -> V_15 -> V_16 , L_173
L_174 , V_155 , V_8 -> V_18 ) ;
F_193 ( V_7 ) ;
return error ;
V_528:
F_59 ( & V_8 -> V_15 -> V_16 , L_175
L_174 , V_155 , V_8 -> V_18 ) ;
return - V_180 ;
}
static int F_198 ( struct V_1 * V_8 ,
unsigned char V_545 [] )
{
int V_283 ;
int V_32 = 0 ;
int V_546 = 1 ;
struct V_9 * V_10 ;
V_10 = F_121 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_51
L_176 ) ;
return V_547 ;
}
while ( V_32 < V_548 ) {
F_117 ( 1000 * V_546 ) ;
V_32 ++ ;
V_283 = 0 ;
if ( V_546 < V_549 )
V_546 = V_546 * 2 ;
( void ) F_122 ( V_10 , V_349 , V_8 ,
NULL , 0 , 0 , V_545 , V_293 ) ;
F_108 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_23 == V_550 )
break;
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 == V_210 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_551 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_177
L_178 , V_546 ) ;
V_283 = 1 ;
}
if ( V_283 )
F_5 ( & V_8 -> V_15 -> V_16 , L_179 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_180 ) ;
F_123 ( V_8 , V_10 ) ;
return V_283 ;
}
static int F_199 ( struct V_199 * V_552 )
{
int V_283 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
V_8 = F_1 ( V_552 -> V_28 ) ;
if ( V_8 == NULL )
return V_553 ;
V_16 = V_552 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_181
L_182 ) ;
return V_553 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_183 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_283 = F_125 ( V_8 , V_16 -> V_54 , V_554 ) ;
if ( V_283 == 0 && F_198 ( V_8 , V_16 -> V_54 ) == 0 )
return V_555 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_184 ) ;
return V_553 ;
}
static void F_200 ( T_4 * V_556 )
{
T_4 V_557 [ 8 ] ;
memcpy ( V_557 , V_556 , 8 ) ;
V_556 [ 0 ] = V_557 [ 3 ] ;
V_556 [ 1 ] = V_557 [ 2 ] ;
V_556 [ 2 ] = V_557 [ 1 ] ;
V_556 [ 3 ] = V_557 [ 0 ] ;
V_556 [ 4 ] = V_557 [ 7 ] ;
V_556 [ 5 ] = V_557 [ 6 ] ;
V_556 [ 6 ] = V_557 [ 5 ] ;
V_556 [ 7 ] = V_557 [ 4 ] ;
}
static void F_201 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 * V_558 , T_3 * V_559 )
{
if ( V_10 -> V_112 == V_113 ) {
struct V_93 * V_560 = (struct V_93 * )
& V_8 -> V_95 [ V_10 -> V_96 ] ;
* V_559 = V_560 -> V_246 . V_195 ;
* V_558 = V_560 -> V_246 . V_194 ;
return;
}
if ( V_10 -> V_112 == V_114 ) {
struct V_99 * V_561 = (struct V_99 * )
& V_8 -> V_100 [ V_10 -> V_96 ] ;
memset ( V_559 , 0 , sizeof( * V_559 ) ) ;
* V_558 = V_561 -> V_246 ;
return;
}
* V_559 = V_10 -> V_88 . V_246 . V_195 ;
* V_558 = V_10 -> V_88 . V_246 . V_194 ;
}
static int F_202 ( struct V_1 * V_8 , unsigned char * V_54 ,
struct V_9 * abort , int V_562 )
{
int V_283 = V_291 ;
struct V_9 * V_10 ;
struct V_231 * V_232 ;
T_3 V_559 , V_558 ;
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
return - V_180 ;
}
( void ) F_122 ( V_10 , V_563 , V_8 , abort ,
0 , 0 , V_54 , V_300 ) ;
if ( V_562 )
F_200 ( & V_10 -> V_106 . V_107 [ 4 ] ) ;
F_108 ( V_8 , V_10 ) ;
F_201 ( V_8 , abort , & V_558 , & V_559 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_185 ,
V_155 , V_559 , V_558 ) ;
V_232 = V_10 -> V_11 ;
switch ( V_232 -> V_23 ) {
case V_550 :
break;
case V_270 :
V_283 = - 1 ;
break;
default:
F_105 ( & V_8 -> V_15 -> V_16 , L_186 ,
V_155 , V_559 , V_558 ) ;
F_119 ( V_8 , V_10 ) ;
V_283 = - 1 ;
break;
}
F_123 ( V_8 , V_10 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_155 , V_559 , V_558 ) ;
return V_283 ;
}
static struct V_9 * F_203 ( struct V_1 * V_8 ,
struct V_199 * V_373 , struct V_71 * V_564 )
{
unsigned long V_59 ;
struct V_9 * V_10 = NULL ;
if ( ! V_373 )
return 0 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, queue_head, list) {
if ( V_10 -> V_237 == NULL )
continue;
if ( V_10 -> V_237 == V_373 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static struct V_9 * F_204 ( struct V_1 * V_8 ,
T_4 * V_556 , struct V_71 * V_564 )
{
unsigned long V_59 ;
struct V_9 * V_10 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, queue_head, list) {
if ( memcmp ( & V_10 -> V_88 . V_246 , V_556 , 8 ) != 0 )
continue;
F_26 ( & V_8 -> V_60 , V_59 ) ;
return V_10 ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
static int F_205 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
int V_283 = V_291 ;
struct V_199 * V_374 ;
struct V_57 * V_16 ;
unsigned char V_565 [ 8 ] ;
unsigned char * V_566 = & V_565 [ 0 ] ;
V_374 = (struct V_199 * ) abort -> V_237 ;
V_16 = (struct V_57 * ) ( V_374 -> V_28 -> V_61 ) ;
if ( V_16 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_188 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_189 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ,
V_54 [ 4 ] , V_54 [ 5 ] , V_54 [ 6 ] , V_54 [ 7 ] ) ;
if ( ! V_16 -> V_70 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_190 ) ;
return - 1 ;
}
if ( ! F_158 ( V_8 , abort , V_566 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_191 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_192 ,
V_566 [ 0 ] , V_566 [ 1 ] , V_566 [ 2 ] , V_566 [ 3 ] ,
V_566 [ 4 ] , V_566 [ 5 ] , V_566 [ 6 ] , V_566 [ 7 ] ) ;
V_283 = F_125 ( V_8 , V_566 , V_567 ) ;
if ( V_283 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_193 ,
V_566 [ 0 ] , V_566 [ 1 ] , V_566 [ 2 ] , V_566 [ 3 ] ,
V_566 [ 4 ] , V_566 [ 5 ] , V_566 [ 6 ] , V_566 [ 7 ] ) ;
return V_283 ;
}
if ( F_198 ( V_8 , V_566 ) != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_194 ,
V_566 [ 0 ] , V_566 [ 1 ] , V_566 [ 2 ] , V_566 [ 3 ] ,
V_566 [ 4 ] , V_566 [ 5 ] , V_566 [ 6 ] , V_566 [ 7 ] ) ;
return - 1 ;
}
F_60 ( & V_8 -> V_15 -> V_16 ,
L_195 ,
V_566 [ 0 ] , V_566 [ 1 ] , V_566 [ 2 ] , V_566 [ 3 ] ,
V_566 [ 4 ] , V_566 [ 5 ] , V_566 [ 6 ] , V_566 [ 7 ] ) ;
return V_283 ;
}
static int F_206 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
T_4 V_568 [ 8 ] ;
struct V_9 * V_10 ;
int V_283 = 0 , V_569 = 0 ;
if ( abort -> V_112 == V_114 )
return F_205 ( V_8 , V_54 , abort ) ;
memcpy ( V_568 , & abort -> V_106 . V_107 [ 4 ] , 8 ) ;
F_200 ( V_568 ) ;
V_10 = F_204 ( V_8 , V_568 , & V_8 -> V_570 ) ;
if ( V_10 != NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_196 ) ;
return F_202 ( V_8 , V_54 , abort , 0 ) ;
}
V_283 = F_202 ( V_8 , V_54 , abort , 0 ) ;
V_10 = F_203 ( V_8 , abort -> V_237 , & V_8 -> V_570 ) ;
if ( V_10 )
V_569 = F_202 ( V_8 , V_54 , abort , 1 ) ;
return V_283 && V_569 ;
}
static int F_207 ( struct V_199 * V_571 )
{
int V_51 , V_283 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
struct V_9 * abort ;
struct V_9 * V_121 ;
struct V_199 * V_572 ;
char V_573 [ 256 ] ;
int V_574 = 0 ;
T_3 V_559 , V_558 ;
V_8 = F_1 ( V_571 -> V_28 ) ;
if ( F_208 ( V_8 == NULL ,
L_197 ) )
return V_553 ;
if ( ! ( V_575 & V_8 -> V_576 ) &&
! ( V_577 & V_8 -> V_576 ) )
return V_553 ;
memset ( V_573 , 0 , sizeof( V_573 ) ) ;
V_574 += sprintf ( V_573 + V_574 , L_198 ,
V_8 -> V_44 -> V_159 , V_571 -> V_28 -> V_578 ,
V_571 -> V_28 -> V_579 , V_571 -> V_28 -> V_120 ) ;
V_16 = V_571 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_199 ,
V_573 ) ;
return V_553 ;
}
abort = (struct V_9 * ) V_571 -> V_504 ;
if ( abort == NULL ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_200 ,
V_573 ) ;
return V_553 ;
}
F_201 ( V_8 , abort , & V_558 , & V_559 ) ;
V_574 += sprintf ( V_573 + V_574 , L_201 , V_559 , V_558 ) ;
V_572 = (struct V_199 * ) abort -> V_237 ;
if ( V_572 != NULL )
V_574 += sprintf ( V_573 + V_574 , L_202 ,
V_572 -> V_255 [ 0 ] , V_572 -> V_580 ) ;
F_105 ( & V_8 -> V_15 -> V_16 , L_21 , V_573 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_203 ,
V_8 -> V_44 -> V_159 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_121 = F_203 ( V_8 , V_571 , & V_8 -> V_115 ) ;
if ( V_121 ) {
V_121 -> V_11 -> V_23 = V_264 ;
F_209 ( V_121 ) ;
F_60 ( & V_8 -> V_15 -> V_16 , L_204 ,
V_573 ) ;
return V_555 ;
}
V_121 = F_203 ( V_8 , V_571 , & V_8 -> V_570 ) ;
if ( ! V_121 ) {
F_105 ( & V_8 -> V_15 -> V_16 , L_205 ,
V_573 ) ;
return V_555 ;
}
V_283 = F_206 ( V_8 , V_16 -> V_54 , abort ) ;
if ( V_283 != 0 ) {
F_105 ( & V_8 -> V_15 -> V_16 , L_206 , V_573 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_207 ,
V_8 -> V_44 -> V_159 ,
V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
return V_553 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_208 , V_573 ) ;
#define F_210 30
for ( V_51 = 0 ; V_51 < F_210 * 10 ; V_51 ++ ) {
V_121 = F_203 ( V_8 , V_571 , & V_8 -> V_570 ) ;
if ( ! V_121 )
return V_555 ;
F_117 ( 100 ) ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_209 ,
V_573 , F_210 ) ;
return V_553 ;
}
static struct V_9 * F_147 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_51 ;
union V_196 V_185 ;
V_275 V_581 , V_582 ;
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
do {
V_51 = F_57 ( V_8 -> V_583 , V_8 -> V_178 ) ;
if ( V_51 == V_8 -> V_178 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return NULL ;
}
} while ( F_211
( V_51 & ( V_496 - 1 ) ,
V_8 -> V_583 + ( V_51 / V_496 ) ) != 0 );
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_10 = V_8 -> V_584 + V_51 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_581 = V_8 -> V_585
+ V_51 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_586 + V_51 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_582 = V_8 -> V_587
+ V_51 * sizeof( * V_10 -> V_11 ) ;
V_10 -> V_96 = V_51 ;
F_212 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_581 ;
V_185 . V_198 = ( T_5 ) V_582 ;
V_10 -> V_588 . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_588 . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_588 . V_190 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_121 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_196 V_185 ;
V_275 V_581 , V_582 ;
V_10 = F_213 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_581 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_112 = V_238 ;
V_10 -> V_96 = - 1 ;
V_10 -> V_11 = F_213 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_582 ) ;
if ( V_10 -> V_11 == NULL ) {
F_214 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_581 ) ;
return NULL ;
}
F_212 ( & V_10 -> V_72 ) ;
V_10 -> V_86 = ( T_3 ) V_581 ;
V_185 . V_198 = ( T_5 ) V_582 ;
V_10 -> V_588 . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_588 . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_588 . V_190 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_100 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_51 ;
unsigned long V_59 ;
V_51 = V_10 - V_8 -> V_584 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_215 ( V_51 & ( V_496 - 1 ) ,
V_8 -> V_583 + ( V_51 / V_496 ) ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_123 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_196 V_185 ;
V_185 . V_197 . V_194 = V_10 -> V_588 . V_193 . V_194 ;
V_185 . V_197 . V_195 = V_10 -> V_588 . V_193 . V_195 ;
F_214 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_275 ) V_185 . V_198 ) ;
F_214 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_275 ) ( V_10 -> V_86 & V_589 ) ) ;
}
static int F_216 ( struct V_2 * V_16 , int V_200 , void * V_590 )
{
T_6 T_7 * V_591 =
( T_6 T_7 * ) V_590 ;
T_8 V_592 ;
T_8 T_7 * V_593 = F_217 ( sizeof( V_592 ) ) ;
int V_594 ;
T_3 V_94 ;
memset ( & V_592 , 0 , sizeof( V_592 ) ) ;
V_594 = 0 ;
V_594 |= F_218 ( & V_592 . V_595 , & V_591 -> V_595 ,
sizeof( V_592 . V_595 ) ) ;
V_594 |= F_218 ( & V_592 . V_106 , & V_591 -> V_106 ,
sizeof( V_592 . V_106 ) ) ;
V_594 |= F_218 ( & V_592 . V_596 , & V_591 -> V_596 ,
sizeof( V_592 . V_596 ) ) ;
V_594 |= F_219 ( V_592 . V_597 , & V_591 -> V_597 ) ;
V_594 |= F_219 ( V_94 , & V_591 -> V_31 ) ;
V_592 . V_31 = F_220 ( V_94 ) ;
V_594 |= F_221 ( V_593 , & V_592 , sizeof( V_592 ) ) ;
if ( V_594 )
return - V_598 ;
V_594 = F_222 ( V_16 , V_599 , ( void * ) V_593 ) ;
if ( V_594 )
return V_594 ;
V_594 |= F_223 ( & V_591 -> V_596 , & V_593 -> V_596 ,
sizeof( V_591 -> V_596 ) ) ;
if ( V_594 )
return - V_598 ;
return V_594 ;
}
static int F_224 ( struct V_2 * V_16 ,
int V_200 , void * V_590 )
{
T_9 T_7 * V_591 =
( T_9 T_7 * ) V_590 ;
T_10 V_592 ;
T_10 T_7 * V_593 =
F_217 ( sizeof( V_592 ) ) ;
int V_594 ;
T_3 V_94 ;
memset ( & V_592 , 0 , sizeof( V_592 ) ) ;
V_594 = 0 ;
V_594 |= F_218 ( & V_592 . V_595 , & V_591 -> V_595 ,
sizeof( V_592 . V_595 ) ) ;
V_594 |= F_218 ( & V_592 . V_106 , & V_591 -> V_106 ,
sizeof( V_592 . V_106 ) ) ;
V_594 |= F_218 ( & V_592 . V_596 , & V_591 -> V_596 ,
sizeof( V_592 . V_596 ) ) ;
V_594 |= F_219 ( V_592 . V_597 , & V_591 -> V_597 ) ;
V_594 |= F_219 ( V_592 . V_600 , & V_591 -> V_600 ) ;
V_594 |= F_219 ( V_94 , & V_591 -> V_31 ) ;
V_592 . V_31 = F_220 ( V_94 ) ;
V_594 |= F_221 ( V_593 , & V_592 , sizeof( V_592 ) ) ;
if ( V_594 )
return - V_598 ;
V_594 = F_222 ( V_16 , V_601 , ( void * ) V_593 ) ;
if ( V_594 )
return V_594 ;
V_594 |= F_223 ( & V_591 -> V_596 , & V_593 -> V_596 ,
sizeof( V_591 -> V_596 ) ) ;
if ( V_594 )
return - V_598 ;
return V_594 ;
}
static int F_225 ( struct V_2 * V_16 , int V_200 , void * V_590 )
{
switch ( V_200 ) {
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
case V_616 :
return F_222 ( V_16 , V_200 , V_590 ) ;
case V_617 :
return F_216 ( V_16 , V_200 , V_590 ) ;
case V_618 :
return F_224 ( V_16 , V_200 , V_590 ) ;
default:
return - V_619 ;
}
}
static int F_226 ( struct V_1 * V_8 , void T_7 * V_620 )
{
struct V_621 V_622 ;
if ( ! V_620 )
return - V_40 ;
V_622 . V_623 = F_227 ( V_8 -> V_15 -> V_118 ) ;
V_622 . V_118 = V_8 -> V_15 -> V_118 -> V_624 ;
V_622 . V_625 = V_8 -> V_15 -> V_626 ;
V_622 . V_50 = V_8 -> V_50 ;
if ( F_221 ( V_620 , & V_622 , sizeof( V_622 ) ) )
return - V_598 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_8 , void T_7 * V_620 )
{
T_11 V_627 ;
unsigned char V_628 , V_629 , V_630 ;
int V_283 ;
V_283 = sscanf ( V_631 , L_210 ,
& V_628 , & V_629 , & V_630 ) ;
if ( V_283 != 3 ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_211
L_212 , V_631 ) ;
V_628 = 0 ;
V_629 = 0 ;
V_630 = 0 ;
}
V_627 = ( V_628 << 16 ) | ( V_629 << 8 ) | V_630 ;
if ( ! V_620 )
return - V_40 ;
if ( F_221 ( V_620 , & V_627 , sizeof( T_11 ) ) )
return - V_598 ;
return 0 ;
}
static int F_229 ( struct V_1 * V_8 , void T_7 * V_620 )
{
T_8 V_632 ;
struct V_9 * V_10 ;
char * V_633 = NULL ;
union V_196 V_185 ;
int V_283 = 0 ;
if ( ! V_620 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_634 ;
if ( F_218 ( & V_632 , V_620 , sizeof( V_632 ) ) )
return - V_598 ;
if ( ( V_632 . V_597 < 1 ) &&
( V_632 . V_106 . Type . V_511 != V_514 ) ) {
return - V_40 ;
}
if ( V_632 . V_597 > 0 ) {
V_633 = F_78 ( V_632 . V_597 , V_154 ) ;
if ( V_633 == NULL )
return - V_598 ;
if ( V_632 . V_106 . Type . V_511 & V_512 ) {
if ( F_218 ( V_633 , V_632 . V_31 ,
V_632 . V_597 ) ) {
V_283 = - V_598 ;
goto V_635;
}
} else {
memset ( V_633 , 0 , V_632 . V_597 ) ;
}
}
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
V_283 = - V_180 ;
goto V_635;
}
V_10 -> V_112 = V_636 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_632 . V_597 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = 1 ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = 0 ;
}
memcpy ( & V_10 -> V_88 . V_247 , & V_632 . V_595 , sizeof( V_10 -> V_88 . V_247 ) ) ;
V_10 -> V_88 . V_246 . V_194 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_632 . V_106 ,
sizeof( V_10 -> V_106 ) ) ;
if ( V_632 . V_597 > 0 ) {
V_185 . V_198 = F_94 ( V_8 -> V_15 , V_633 ,
V_632 . V_597 , V_637 ) ;
if ( F_95 ( & V_8 -> V_15 -> V_16 , V_185 . V_198 ) ) {
V_10 -> V_186 [ 0 ] . V_193 . V_194 = 0 ;
V_10 -> V_186 [ 0 ] . V_193 . V_195 = 0 ;
V_10 -> V_186 [ 0 ] . V_190 = 0 ;
V_283 = - V_180 ;
goto V_294;
}
V_10 -> V_186 [ 0 ] . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_186 [ 0 ] . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_186 [ 0 ] . V_190 = V_632 . V_597 ;
V_10 -> V_186 [ 0 ] . V_188 = V_278 ;
}
F_115 ( V_8 , V_10 ) ;
if ( V_632 . V_597 > 0 )
F_106 ( V_8 -> V_15 , V_10 , 1 , V_637 ) ;
F_230 ( V_8 , V_10 ) ;
memcpy ( & V_632 . V_596 , V_10 -> V_11 ,
sizeof( V_632 . V_596 ) ) ;
if ( F_221 ( V_620 , & V_632 , sizeof( V_632 ) ) ) {
V_283 = - V_598 ;
goto V_294;
}
if ( ( V_632 . V_106 . Type . V_511 & V_513 ) &&
V_632 . V_597 > 0 ) {
if ( F_221 ( V_632 . V_31 , V_633 , V_632 . V_597 ) ) {
V_283 = - V_598 ;
goto V_294;
}
}
V_294:
F_123 ( V_8 , V_10 ) ;
V_635:
F_67 ( V_633 ) ;
return V_283 ;
}
static int F_231 ( struct V_1 * V_8 , void T_7 * V_620 )
{
T_10 * V_638 ;
struct V_9 * V_10 ;
unsigned char * * V_633 = NULL ;
int * V_639 = NULL ;
union V_196 V_185 ;
T_12 V_272 = 0 ;
int V_33 = 0 ;
int V_51 ;
T_3 V_640 ;
T_3 V_641 ;
T_12 T_7 * V_642 ;
if ( ! V_620 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_634 ;
V_638 = ( T_10 * )
F_78 ( sizeof( * V_638 ) , V_154 ) ;
if ( ! V_638 ) {
V_33 = - V_180 ;
goto V_643;
}
if ( F_218 ( V_638 , V_620 , sizeof( * V_638 ) ) ) {
V_33 = - V_598 ;
goto V_643;
}
if ( ( V_638 -> V_597 < 1 ) &&
( V_638 -> V_106 . Type . V_511 != V_514 ) ) {
V_33 = - V_40 ;
goto V_643;
}
if ( V_638 -> V_600 > V_644 ) {
V_33 = - V_40 ;
goto V_643;
}
if ( V_638 -> V_597 > V_638 -> V_600 * V_645 ) {
V_33 = - V_40 ;
goto V_643;
}
V_633 = F_81 ( V_645 * sizeof( char * ) , V_154 ) ;
if ( ! V_633 ) {
V_33 = - V_180 ;
goto V_643;
}
V_639 = F_78 ( V_645 * sizeof( int ) , V_154 ) ;
if ( ! V_639 ) {
V_33 = - V_180 ;
goto V_643;
}
V_640 = V_638 -> V_597 ;
V_642 = V_638 -> V_31 ;
while ( V_640 ) {
V_641 = ( V_640 > V_638 -> V_600 ) ? V_638 -> V_600 : V_640 ;
V_639 [ V_272 ] = V_641 ;
V_633 [ V_272 ] = F_78 ( V_641 , V_154 ) ;
if ( V_633 [ V_272 ] == NULL ) {
V_33 = - V_180 ;
goto V_643;
}
if ( V_638 -> V_106 . Type . V_511 & V_512 ) {
if ( F_218 ( V_633 [ V_272 ] , V_642 , V_641 ) ) {
V_33 = - V_598 ;
goto V_643;
}
} else
memset ( V_633 [ V_272 ] , 0 , V_641 ) ;
V_640 -= V_641 ;
V_642 += V_641 ;
V_272 ++ ;
}
V_10 = F_121 ( V_8 ) ;
if ( V_10 == NULL ) {
V_33 = - V_180 ;
goto V_643;
}
V_10 -> V_112 = V_636 ;
V_10 -> V_88 . V_91 = 0 ;
V_10 -> V_88 . V_89 = V_10 -> V_88 . V_191 = V_272 ;
memcpy ( & V_10 -> V_88 . V_247 , & V_638 -> V_595 , sizeof( V_10 -> V_88 . V_247 ) ) ;
V_10 -> V_88 . V_246 . V_194 = V_10 -> V_86 ;
memcpy ( & V_10 -> V_106 , & V_638 -> V_106 , sizeof( V_10 -> V_106 ) ) ;
if ( V_638 -> V_597 > 0 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_272 ; V_51 ++ ) {
V_185 . V_198 = F_94 ( V_8 -> V_15 , V_633 [ V_51 ] ,
V_639 [ V_51 ] , V_637 ) ;
if ( F_95 ( & V_8 -> V_15 -> V_16 , V_185 . V_198 ) ) {
V_10 -> V_186 [ V_51 ] . V_193 . V_194 = 0 ;
V_10 -> V_186 [ V_51 ] . V_193 . V_195 = 0 ;
V_10 -> V_186 [ V_51 ] . V_190 = 0 ;
F_106 ( V_8 -> V_15 , V_10 , V_51 ,
V_637 ) ;
V_33 = - V_180 ;
goto V_646;
}
V_10 -> V_186 [ V_51 ] . V_193 . V_194 = V_185 . V_197 . V_194 ;
V_10 -> V_186 [ V_51 ] . V_193 . V_195 = V_185 . V_197 . V_195 ;
V_10 -> V_186 [ V_51 ] . V_190 = V_639 [ V_51 ] ;
V_10 -> V_186 [ V_51 ] . V_188 = V_51 < V_272 - 1 ? 0 : V_278 ;
}
}
F_115 ( V_8 , V_10 ) ;
if ( V_272 )
F_106 ( V_8 -> V_15 , V_10 , V_272 , V_637 ) ;
F_230 ( V_8 , V_10 ) ;
memcpy ( & V_638 -> V_596 , V_10 -> V_11 , sizeof( V_638 -> V_596 ) ) ;
if ( F_221 ( V_620 , V_638 , sizeof( * V_638 ) ) ) {
V_33 = - V_598 ;
goto V_646;
}
if ( ( V_638 -> V_106 . Type . V_511 & V_513 ) && V_638 -> V_597 > 0 ) {
T_12 T_7 * V_647 = V_638 -> V_31 ;
for ( V_51 = 0 ; V_51 < V_272 ; V_51 ++ ) {
if ( F_221 ( V_647 , V_633 [ V_51 ] , V_639 [ V_51 ] ) ) {
V_33 = - V_598 ;
goto V_646;
}
V_647 += V_639 [ V_51 ] ;
}
}
V_33 = 0 ;
V_646:
F_123 ( V_8 , V_10 ) ;
V_643:
if ( V_633 ) {
for ( V_51 = 0 ; V_51 < V_272 ; V_51 ++ )
F_67 ( V_633 [ V_51 ] ) ;
F_67 ( V_633 ) ;
}
F_67 ( V_639 ) ;
F_67 ( V_638 ) ;
return V_33 ;
}
static void F_230 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 != V_210 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_232 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_648 , V_59 ) ;
if ( V_8 -> V_649 >= V_650 ) {
F_26 ( & V_8 -> V_648 , V_59 ) ;
return - 1 ;
}
V_8 -> V_649 ++ ;
F_26 ( & V_8 -> V_648 , V_59 ) ;
return 0 ;
}
static void F_233 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_648 , V_59 ) ;
if ( V_8 -> V_649 <= 0 ) {
F_26 ( & V_8 -> V_648 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_213 ) ;
return;
}
V_8 -> V_649 -- ;
F_26 ( & V_8 -> V_648 , V_59 ) ;
}
static int F_222 ( struct V_2 * V_16 , int V_200 , void * V_590 )
{
struct V_1 * V_8 ;
void T_7 * V_620 = ( void T_7 * ) V_590 ;
int V_283 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_200 ) {
case V_612 :
case V_613 :
case V_614 :
F_12 ( V_8 -> V_44 ) ;
return 0 ;
case V_602 :
return F_226 ( V_8 , V_620 ) ;
case V_610 :
return F_228 ( V_8 , V_620 ) ;
case V_599 :
if ( F_232 ( V_8 ) )
return - V_651 ;
V_283 = F_229 ( V_8 , V_620 ) ;
F_233 ( V_8 ) ;
return V_283 ;
case V_601 :
if ( F_232 ( V_8 ) )
return - V_651 ;
V_283 = F_231 ( V_8 , V_620 ) ;
F_233 ( V_8 ) ;
return V_283 ;
default:
return - V_652 ;
}
}
static int F_234 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_298 )
{
struct V_9 * V_10 ;
V_10 = F_147 ( V_8 ) ;
if ( ! V_10 )
return - V_180 ;
( void ) F_122 ( V_10 , V_299 , V_8 , NULL , 0 , 0 ,
V_117 , V_300 ) ;
V_10 -> V_106 . V_107 [ 1 ] = V_298 ;
V_10 -> V_281 = NULL ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_122 ( struct V_9 * V_10 , T_4 V_200 , struct V_1 * V_8 ,
void * V_633 , T_2 V_342 , V_279 V_653 , unsigned char * V_54 ,
int V_112 )
{
int V_654 = V_514 ;
struct V_9 * V_74 ;
V_10 -> V_112 = V_636 ;
V_10 -> V_88 . V_91 = 0 ;
if ( V_633 != NULL && V_342 > 0 ) {
V_10 -> V_88 . V_89 = 1 ;
V_10 -> V_88 . V_191 = 1 ;
} else {
V_10 -> V_88 . V_89 = 0 ;
V_10 -> V_88 . V_191 = 0 ;
}
V_10 -> V_88 . V_246 . V_194 = V_10 -> V_86 ;
memcpy ( V_10 -> V_88 . V_247 . V_248 , V_54 , 8 ) ;
V_10 -> V_106 . Type . Type = V_112 ;
if ( V_112 == V_293 ) {
switch ( V_200 ) {
case V_292 :
if ( V_653 & V_301 ) {
V_10 -> V_106 . V_107 [ 1 ] = 0x01 ;
V_10 -> V_106 . V_107 [ 2 ] = ( V_653 & 0xff ) ;
}
V_10 -> V_106 . V_243 = 6 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_513 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_292 ;
V_10 -> V_106 . V_107 [ 4 ] = V_342 & 0xFF ;
break;
case V_339 :
case V_340 :
V_10 -> V_106 . V_243 = 12 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_513 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_200 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_342 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_342 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_342 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_342 & 0xFF ;
break;
case V_655 :
V_10 -> V_106 . V_243 = 12 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_512 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_104 ;
V_10 -> V_106 . V_107 [ 6 ] = V_656 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_342 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_342 & 0xFF ;
break;
case V_349 :
V_10 -> V_106 . V_243 = 6 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_514 ;
V_10 -> V_106 . V_508 = 0 ;
break;
case V_328 :
V_10 -> V_106 . V_243 = 12 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_513 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_657 ;
V_10 -> V_106 . V_107 [ 1 ] = V_200 ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_342 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_342 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_342 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = V_342 & 0xFF ;
break;
case V_297 :
V_10 -> V_106 . V_243 = 10 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_513 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_658 ;
V_10 -> V_106 . V_107 [ 6 ] = V_297 ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_342 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = ( V_342 >> 8 ) & 0xFF ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_214 , V_200 ) ;
F_163 () ;
return - 1 ;
}
} else if ( V_112 == V_300 ) {
switch ( V_200 ) {
case V_299 :
V_10 -> V_106 . V_243 = 16 ;
V_10 -> V_106 . Type . Type = 1 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_514 ;
V_10 -> V_106 . V_508 = 0 ;
memset ( & V_10 -> V_106 . V_107 [ 0 ] , 0 , sizeof( V_10 -> V_106 . V_107 ) ) ;
V_10 -> V_106 . V_107 [ 0 ] = V_200 ;
V_10 -> V_106 . V_107 [ 1 ] = V_554 ;
V_10 -> V_106 . V_107 [ 4 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 5 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 6 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 7 ] = 0x00 ;
break;
case V_563 :
V_74 = V_633 ;
F_105 ( & V_8 -> V_15 -> V_16 , L_215 ,
V_74 -> V_88 . V_246 . V_195 , V_74 -> V_88 . V_246 . V_194 ,
V_10 -> V_88 . V_246 . V_195 , V_10 -> V_88 . V_246 . V_194 ) ;
V_10 -> V_106 . V_243 = 16 ;
V_10 -> V_106 . Type . Type = V_300 ;
V_10 -> V_106 . Type . V_509 = V_510 ;
V_10 -> V_106 . Type . V_511 = V_512 ;
V_10 -> V_106 . V_508 = 0 ;
V_10 -> V_106 . V_107 [ 0 ] = V_659 ;
V_10 -> V_106 . V_107 [ 1 ] = V_660 ;
V_10 -> V_106 . V_107 [ 2 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 3 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 4 ] = V_74 -> V_88 . V_246 . V_194 & 0xFF ;
V_10 -> V_106 . V_107 [ 5 ] = ( V_74 -> V_88 . V_246 . V_194 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 6 ] = ( V_74 -> V_88 . V_246 . V_194 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 7 ] = ( V_74 -> V_88 . V_246 . V_194 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 8 ] = V_74 -> V_88 . V_246 . V_195 & 0xFF ;
V_10 -> V_106 . V_107 [ 9 ] = ( V_74 -> V_88 . V_246 . V_195 >> 8 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 10 ] = ( V_74 -> V_88 . V_246 . V_195 >> 16 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 11 ] = ( V_74 -> V_88 . V_246 . V_195 >> 24 ) & 0xFF ;
V_10 -> V_106 . V_107 [ 12 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 13 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 14 ] = 0x00 ;
V_10 -> V_106 . V_107 [ 15 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_216 ,
V_200 ) ;
F_163 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_217 , V_112 ) ;
F_163 () ;
}
switch ( V_10 -> V_106 . Type . V_511 ) {
case V_513 :
V_654 = V_295 ;
break;
case V_512 :
V_654 = V_192 ;
break;
case V_514 :
V_654 = V_277 ;
break;
default:
V_654 = V_637 ;
}
if ( F_107 ( V_8 -> V_15 , V_10 , V_633 , V_342 , V_654 ) )
return - 1 ;
return 0 ;
}
static void T_13 * F_235 ( T_14 V_661 , T_14 V_342 )
{
T_14 V_662 = ( ( T_14 ) V_661 ) & V_663 ;
T_14 V_664 = ( ( T_14 ) V_661 ) - V_662 ;
void T_13 * V_665 = F_236 ( V_662 ,
V_664 + V_342 ) ;
return V_665 ? ( V_665 + V_664 ) : NULL ;
}
static void F_46 ( struct V_1 * V_8 , unsigned long * V_59 )
{
struct V_9 * V_10 ;
while ( ! F_49 ( & V_8 -> V_115 ) ) {
V_10 = F_237 ( V_8 -> V_115 . V_666 , struct V_9 , V_72 ) ;
if ( ( V_8 -> V_79 . V_667 ( V_8 ) ) ) {
V_8 -> V_668 = 1 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_218 ) ;
break;
}
V_8 -> V_668 = 0 ;
F_47 ( V_10 ) ;
V_8 -> V_116 -- ;
F_30 ( & V_8 -> V_570 , V_10 ) ;
V_8 -> V_47 ++ ;
F_26 ( & V_8 -> V_60 , * V_59 ) ;
V_8 -> V_79 . V_669 ( V_8 , V_10 ) ;
F_25 ( & V_8 -> V_60 , * V_59 ) ;
}
}
static void F_238 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_46 ( V_8 , & V_59 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static inline unsigned long F_239 ( struct V_1 * V_8 , T_4 V_73 )
{
return V_8 -> V_79 . V_80 ( V_8 , V_73 ) ;
}
static inline bool F_240 ( struct V_1 * V_8 )
{
return V_8 -> V_79 . V_670 ( V_8 ) ;
}
static inline long F_241 ( struct V_1 * V_8 )
{
return ( V_8 -> V_79 . V_670 ( V_8 ) == 0 ) ||
( V_8 -> V_671 == 0 ) ;
}
static inline int F_242 ( struct V_1 * V_8 , T_3 V_672 ,
T_3 V_673 )
{
if ( F_33 ( V_672 >= V_8 -> V_178 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_219 , V_673 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_209 ( struct V_9 * V_10 )
{
unsigned long V_59 ;
int V_674 = 0 ;
struct V_1 * V_8 = V_10 -> V_8 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_47 ( V_10 ) ;
if ( F_33 ( V_8 -> V_668 ) &&
V_8 -> V_47 < 5 )
V_674 = 1 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_43 ( V_10 -> V_8 , V_10 ) ;
if ( F_35 ( V_10 -> V_112 == V_113 || V_10 -> V_112 == V_238
|| V_10 -> V_112 == V_114 ) )
F_101 ( V_10 ) ;
else if ( V_10 -> V_112 == V_636 )
F_243 ( V_10 -> V_281 ) ;
if ( F_33 ( V_674 ) )
F_238 ( V_8 ) ;
}
static inline T_3 F_244 ( T_3 V_556 )
{
return V_556 & V_466 ;
}
static inline T_3 F_245 ( T_3 V_556 )
{
return V_556 >> V_465 ;
}
static inline T_3 F_246 ( struct V_1 * V_8 , T_3 V_556 )
{
#define F_247 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_248 0x03
if ( F_33 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_556 & ~ F_248 ;
return V_556 & ~ F_247 ;
}
static inline void F_249 ( struct V_1 * V_8 ,
T_3 V_673 )
{
T_3 V_672 ;
struct V_9 * V_10 ;
V_672 = F_245 ( V_673 ) ;
if ( ! F_242 ( V_8 , V_672 , V_673 ) ) {
V_10 = V_8 -> V_584 + V_672 ;
F_209 ( V_10 ) ;
}
}
static inline void F_250 ( struct V_1 * V_8 ,
T_3 V_673 )
{
T_3 V_556 ;
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
V_556 = F_246 ( V_8 , V_673 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_86 & 0xFFFFFFE0 ) == ( V_556 & 0xFFFFFFE0 ) ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_209 ( V_10 ) ;
return;
}
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_242 ( V_8 , V_8 -> V_178 + 1 , V_673 ) ;
}
static int F_251 ( struct V_1 * V_8 )
{
if ( F_35 ( ! V_675 ) )
return 0 ;
if ( F_35 ( V_8 -> V_671 ) )
return 0 ;
F_60 ( & V_8 -> V_15 -> V_16 , L_220
L_221 ) ;
return 1 ;
}
static struct V_1 * F_252 ( T_4 * V_676 )
{
return F_253 ( ( V_676 - * V_676 ) , struct V_1 , V_73 [ 0 ] ) ;
}
static T_15 F_254 ( int V_540 , void * V_676 )
{
struct V_1 * V_8 = F_252 ( V_676 ) ;
T_4 V_73 = * ( T_4 * ) V_676 ;
T_3 V_673 ;
if ( F_251 ( V_8 ) )
return V_677 ;
if ( F_241 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_255 () ;
while ( F_240 ( V_8 ) ) {
V_673 = F_239 ( V_8 , V_73 ) ;
while ( V_673 != V_84 )
V_673 = F_32 ( V_8 , V_73 ) ;
}
return V_679 ;
}
static T_15 F_256 ( int V_540 , void * V_676 )
{
struct V_1 * V_8 = F_252 ( V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
if ( F_251 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_255 () ;
V_673 = F_239 ( V_8 , V_73 ) ;
while ( V_673 != V_84 )
V_673 = F_32 ( V_8 , V_73 ) ;
return V_679 ;
}
static T_15 F_257 ( int V_540 , void * V_676 )
{
struct V_1 * V_8 = F_252 ( ( T_4 * ) V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
if ( F_241 ( V_8 ) )
return V_677 ;
V_8 -> V_678 = F_255 () ;
while ( F_240 ( V_8 ) ) {
V_673 = F_239 ( V_8 , V_73 ) ;
while ( V_673 != V_84 ) {
if ( F_35 ( F_244 ( V_673 ) ) )
F_249 ( V_8 , V_673 ) ;
else
F_250 ( V_8 , V_673 ) ;
V_673 = F_32 ( V_8 , V_73 ) ;
}
}
return V_679 ;
}
static T_15 F_258 ( int V_540 , void * V_676 )
{
struct V_1 * V_8 = F_252 ( V_676 ) ;
T_3 V_673 ;
T_4 V_73 = * ( T_4 * ) V_676 ;
V_8 -> V_678 = F_255 () ;
V_673 = F_239 ( V_8 , V_73 ) ;
while ( V_673 != V_84 ) {
if ( F_35 ( F_244 ( V_673 ) ) )
F_249 ( V_8 , V_673 ) ;
else
F_250 ( V_8 , V_673 ) ;
V_673 = F_32 ( V_8 , V_73 ) ;
}
return V_679 ;
}
static int F_259 ( struct V_271 * V_15 , unsigned char V_680 ,
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
V_275 V_688 ;
T_16 V_689 , V_556 ;
void T_13 * V_690 ;
int V_51 , V_594 ;
V_690 = F_260 ( V_15 , 0 ) ;
if ( V_690 == NULL )
return - V_180 ;
V_594 = F_261 ( V_15 , F_262 ( 32 ) ) ;
if ( V_594 ) {
F_263 ( V_690 ) ;
return - V_180 ;
}
V_200 = F_264 ( V_15 , V_687 , & V_688 ) ;
if ( V_200 == NULL ) {
F_263 ( V_690 ) ;
return - V_180 ;
}
V_689 = V_688 ;
V_200 -> V_683 . V_91 = 0 ;
V_200 -> V_683 . V_89 = 0 ;
V_200 -> V_683 . V_191 = 0 ;
V_200 -> V_683 . V_246 . V_194 = V_689 ;
V_200 -> V_683 . V_246 . V_195 = 0 ;
memset ( & V_200 -> V_683 . V_247 . V_248 , 0 , 8 ) ;
V_200 -> V_106 . V_243 = 16 ;
V_200 -> V_106 . Type . Type = V_300 ;
V_200 -> V_106 . Type . V_509 = V_691 ;
V_200 -> V_106 . Type . V_511 = V_514 ;
V_200 -> V_106 . V_508 = 0 ;
V_200 -> V_106 . V_107 [ 0 ] = V_680 ;
V_200 -> V_106 . V_107 [ 1 ] = type ;
memset ( & V_200 -> V_106 . V_107 [ 2 ] , 0 , 14 ) ;
V_200 -> V_686 . V_193 . V_194 = V_689 + sizeof( * V_200 ) ;
V_200 -> V_686 . V_193 . V_195 = 0 ;
V_200 -> V_686 . V_190 = sizeof( struct V_231 ) ;
F_265 ( V_689 , V_690 + V_692 ) ;
for ( V_51 = 0 ; V_51 < V_693 ; V_51 ++ ) {
V_556 = F_266 ( V_690 + V_694 ) ;
if ( ( V_556 & ~ F_248 ) == V_689 )
break;
F_117 ( V_695 ) ;
}
F_263 ( V_690 ) ;
if ( V_51 == V_693 ) {
F_59 ( & V_15 -> V_16 , L_222 ,
V_680 , type ) ;
return - V_696 ;
}
F_214 ( V_15 , V_687 , V_200 , V_688 ) ;
if ( V_556 & V_697 ) {
F_59 ( & V_15 -> V_16 , L_223 ,
V_680 , type ) ;
return - V_698 ;
}
F_60 ( & V_15 -> V_16 , L_224 ,
V_680 , type ) ;
return 0 ;
}
static int F_267 ( struct V_271 * V_15 ,
void * T_13 V_690 , T_3 V_699 )
{
V_279 V_700 ;
int V_701 ;
if ( V_699 ) {
F_60 ( & V_15 -> V_16 , L_225 ) ;
F_265 ( V_699 , V_690 + V_702 ) ;
F_117 ( 10000 ) ;
} else {
V_701 = F_268 ( V_15 , V_703 ) ;
if ( V_701 == 0 ) {
F_59 ( & V_15 -> V_16 ,
L_226
L_227 ) ;
return - V_62 ;
}
F_60 ( & V_15 -> V_16 , L_228 ) ;
F_269 ( V_15 , V_701 + V_704 , & V_700 ) ;
V_700 &= ~ V_705 ;
V_700 |= V_706 ;
F_270 ( V_15 , V_701 + V_704 , V_700 ) ;
F_117 ( 500 ) ;
V_700 &= ~ V_705 ;
V_700 |= V_707 ;
F_270 ( V_15 , V_701 + V_704 , V_700 ) ;
F_117 ( 500 ) ;
}
return 0 ;
}
static void F_271 ( char * V_708 , int V_34 )
{
memset ( V_708 , 0 , V_34 ) ;
strncpy ( V_708 , V_17 L_229 V_631 , V_34 - 1 ) ;
}
static int F_272 ( struct V_709 T_13 * V_710 )
{
char * V_708 ;
int V_51 , V_342 = sizeof( V_710 -> V_708 ) ;
V_708 = F_78 ( V_342 , V_154 ) ;
if ( ! V_708 )
return - V_180 ;
F_271 ( V_708 , V_342 ) ;
for ( V_51 = 0 ; V_51 < V_342 ; V_51 ++ )
F_273 ( V_708 [ V_51 ] , & V_710 -> V_708 [ V_51 ] ) ;
F_67 ( V_708 ) ;
return 0 ;
}
static void F_274 ( struct V_709 T_13 * V_710 ,
unsigned char * V_711 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < sizeof( V_710 -> V_708 ) ; V_51 ++ )
V_711 [ V_51 ] = F_275 ( & V_710 -> V_708 [ V_51 ] ) ;
}
static int F_276 ( struct V_709 T_13 * V_710 )
{
char * V_711 , * V_712 ;
int V_283 , V_342 = sizeof( V_710 -> V_708 ) ;
V_712 = F_78 ( 2 * V_342 , V_154 ) ;
if ( ! V_712 )
return - V_180 ;
V_711 = V_712 + V_342 ;
F_271 ( V_712 , V_342 ) ;
F_274 ( V_710 , V_711 ) ;
V_283 = ! memcmp ( V_711 , V_712 , V_342 ) ;
F_67 ( V_712 ) ;
return V_283 ;
}
static int F_277 ( struct V_271 * V_15 )
{
T_5 V_713 ;
T_3 V_714 ;
T_5 V_715 ;
void T_13 * V_690 ;
unsigned long V_716 ;
T_3 V_717 ;
int V_283 ;
struct V_709 T_13 * V_710 ;
T_3 V_699 ;
T_3 V_50 ;
V_279 V_718 ;
V_283 = F_278 ( V_15 , & V_50 ) ;
if ( V_283 < 0 || ! F_20 ( V_50 ) ) {
F_5 ( & V_15 -> V_16 , L_230 ) ;
return - V_62 ;
}
if ( ! F_17 ( V_50 ) )
return - V_525 ;
F_269 ( V_15 , 4 , & V_718 ) ;
F_279 ( V_15 ) ;
V_283 = F_280 ( V_15 , & V_716 ) ;
if ( V_283 )
return V_283 ;
V_690 = F_235 ( V_716 , 0x250 ) ;
if ( ! V_690 )
return - V_180 ;
V_283 = F_281 ( V_15 , V_690 , & V_714 ,
& V_715 , & V_713 ) ;
if ( V_283 )
goto V_719;
V_710 = F_235 ( F_282 ( V_15 ,
V_715 ) + V_713 , sizeof( * V_710 ) ) ;
if ( ! V_710 ) {
V_283 = - V_180 ;
goto V_719;
}
V_283 = F_272 ( V_710 ) ;
if ( V_283 )
goto V_719;
V_717 = F_266 ( & V_710 -> V_717 ) ;
V_699 = V_717 & V_720 ;
if ( V_699 ) {
V_699 = V_721 ;
} else {
V_699 = V_717 & V_722 ;
if ( V_699 ) {
F_5 ( & V_15 -> V_16 , L_231
L_232 ) ;
V_283 = - V_525 ;
goto V_723;
}
}
V_283 = F_267 ( V_15 , V_690 , V_699 ) ;
if ( V_283 )
goto V_723;
F_283 ( V_15 ) ;
F_270 ( V_15 , 4 , V_718 ) ;
F_117 ( V_724 ) ;
V_283 = F_284 ( V_15 , V_690 , V_725 ) ;
if ( V_283 ) {
F_5 ( & V_15 -> V_16 ,
L_233
L_234 ) ;
goto V_723;
}
V_283 = F_276 ( V_690 ) ;
if ( V_283 < 0 )
goto V_723;
if ( V_283 ) {
F_5 ( & V_15 -> V_16 , L_235
L_236 ) ;
V_283 = - V_525 ;
} else {
F_60 ( & V_15 -> V_16 , L_237 ) ;
}
V_723:
F_263 ( V_710 ) ;
V_719:
F_263 ( V_690 ) ;
return V_283 ;
}
static void F_285 ( struct V_28 * V_16 , struct V_709 * V_726 )
{
#ifdef F_286
int V_51 ;
char V_727 [ 17 ] ;
F_60 ( V_16 , L_238 ) ;
F_60 ( V_16 , L_239 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
V_727 [ V_51 ] = F_275 ( & ( V_726 -> V_728 [ V_51 ] ) ) ;
V_727 [ 4 ] = '\0' ;
F_60 ( V_16 , L_240 , V_727 ) ;
F_60 ( V_16 , L_241 , F_266 ( & ( V_726 -> V_729 ) ) ) ;
F_60 ( V_16 , L_242 ,
F_266 ( & ( V_726 -> V_730 ) ) ) ;
F_60 ( V_16 , L_243 ,
F_266 ( & ( V_726 -> V_731 ) ) ) ;
F_60 ( V_16 , L_244 ,
F_266 ( & ( V_726 -> V_732 . V_733 ) ) ) ;
F_60 ( V_16 , L_245 ,
F_266 ( & ( V_726 -> V_732 . V_734 ) ) ) ;
F_60 ( V_16 , L_246 ,
F_266 ( & ( V_726 -> V_732 . V_735 ) ) ) ;
F_60 ( V_16 , L_247 ,
F_266 ( & ( V_726 -> V_736 ) ) ) ;
F_60 ( V_16 , L_248 , F_266 ( & ( V_726 -> V_737 ) ) ) ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_727 [ V_51 ] = F_275 ( & ( V_726 -> V_738 [ V_51 ] ) ) ;
V_727 [ 16 ] = '\0' ;
F_60 ( V_16 , L_249 , V_727 ) ;
F_60 ( V_16 , L_250 ,
F_266 ( & ( V_726 -> V_739 ) ) ) ;
#endif
}
static int F_287 ( struct V_271 * V_15 , unsigned long V_740 )
{
int V_51 , V_741 , V_742 , V_743 ;
if ( V_740 == V_744 )
return 0 ;
V_741 = 0 ;
for ( V_51 = 0 ; V_51 < V_745 ; V_51 ++ ) {
V_743 = F_288 ( V_15 , V_51 ) & V_746 ;
if ( V_743 == V_747 )
V_741 += 4 ;
else {
V_742 = F_288 ( V_15 , V_51 ) &
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
L_251 ) ;
return - 1 ;
break;
}
}
if ( V_741 == V_740 - V_744 )
return V_51 + 1 ;
}
return - 1 ;
}
static void F_289 ( struct V_1 * V_8 )
{
#ifdef F_290
int V_594 , V_51 ;
struct V_752 V_753 [ V_754 ] ;
for ( V_51 = 0 ; V_51 < V_754 ; V_51 ++ ) {
V_753 [ V_51 ] . V_755 = 0 ;
V_753 [ V_51 ] . V_134 = V_51 ;
}
if ( ( V_8 -> V_50 == 0x40700E11 ) || ( V_8 -> V_50 == 0x40800E11 ) ||
( V_8 -> V_50 == 0x40820E11 ) || ( V_8 -> V_50 == 0x40830E11 ) )
goto V_756;
if ( F_268 ( V_8 -> V_15 , V_757 ) ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_252 ) ;
V_8 -> V_90 = V_754 ;
if ( V_8 -> V_90 > F_291 () )
V_8 -> V_90 = F_291 () ;
V_594 = F_292 ( V_8 -> V_15 , V_753 ,
1 , V_8 -> V_90 ) ;
if ( V_594 < 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_253 , V_594 ) ;
V_8 -> V_90 = 0 ;
goto V_758;
} else if ( V_594 < V_8 -> V_90 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_254
L_255 , V_594 ) ;
}
V_8 -> V_90 = V_594 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_8 -> V_541 [ V_51 ] = V_753 [ V_51 ] . V_755 ;
return;
}
V_758:
if ( F_268 ( V_8 -> V_15 , V_759 ) ) {
F_60 ( & V_8 -> V_15 -> V_16 , L_256 ) ;
if ( ! F_293 ( V_8 -> V_15 ) )
V_8 -> V_760 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_257 ) ;
}
V_756:
#endif
V_8 -> V_541 [ V_8 -> V_542 ] = V_8 -> V_15 -> V_540 ;
}
static int F_278 ( struct V_271 * V_15 , T_3 * V_50 )
{
int V_51 ;
T_3 V_761 , V_762 ;
V_761 = V_15 -> V_763 ;
V_762 = V_15 -> V_764 ;
* V_50 = ( ( V_762 << 16 ) & 0xffff0000 ) |
V_761 ;
for ( V_51 = 0 ; V_51 < F_18 ( V_765 ) ; V_51 ++ )
if ( * V_50 == V_765 [ V_51 ] . V_50 )
return V_51 ;
if ( ( V_761 != V_766 &&
V_761 != V_767 ) ||
! V_768 ) {
F_5 ( & V_15 -> V_16 , L_258
L_259 , * V_50 ) ;
return - V_62 ;
}
return F_18 ( V_765 ) - 1 ;
}
static int F_280 ( struct V_271 * V_15 ,
unsigned long * V_769 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_745 ; V_51 ++ )
if ( F_288 ( V_15 , V_51 ) & V_770 ) {
* V_769 = F_282 ( V_15 , V_51 ) ;
F_105 ( & V_15 -> V_16 , L_260 ,
* V_769 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_261 ) ;
return - V_62 ;
}
static int F_284 ( struct V_271 * V_15 , void T_13 * V_690 ,
int V_771 )
{
int V_51 , V_772 ;
T_3 V_773 ;
if ( V_771 )
V_772 = V_774 ;
else
V_772 = V_775 ;
for ( V_51 = 0 ; V_51 < V_772 ; V_51 ++ ) {
V_773 = F_266 ( V_690 + V_776 ) ;
if ( V_771 ) {
if ( V_773 == V_777 )
return 0 ;
} else {
if ( V_773 != V_777 )
return 0 ;
}
F_117 ( V_778 ) ;
}
F_5 ( & V_15 -> V_16 , L_262 ) ;
return - V_62 ;
}
static int F_281 ( struct V_271 * V_15 , void T_13 * V_690 ,
T_3 * V_714 , T_5 * V_715 ,
T_5 * V_713 )
{
* V_714 = F_266 ( V_690 + V_779 ) ;
* V_713 = F_266 ( V_690 + V_780 ) ;
* V_714 &= ( T_3 ) 0x0000ffff ;
* V_715 = F_287 ( V_15 , * V_714 ) ;
if ( * V_715 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_263 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_294 ( struct V_1 * V_8 )
{
T_5 V_713 ;
T_3 V_714 ;
T_5 V_715 ;
T_3 V_781 ;
int V_283 ;
V_283 = F_281 ( V_8 -> V_15 , V_8 -> V_690 , & V_714 ,
& V_715 , & V_713 ) ;
if ( V_283 )
return V_283 ;
V_8 -> V_710 = F_235 ( F_282 ( V_8 -> V_15 ,
V_715 ) + V_713 , sizeof( * V_8 -> V_710 ) ) ;
if ( ! V_8 -> V_710 )
return - V_180 ;
V_283 = F_272 ( V_8 -> V_710 ) ;
if ( V_283 )
return V_283 ;
V_781 = F_266 ( & V_8 -> V_710 -> V_782 ) ;
V_8 -> V_783 = F_235 ( F_282 ( V_8 -> V_15 ,
V_715 ) + V_713 + V_781 ,
sizeof( * V_8 -> V_783 ) ) ;
if ( ! V_8 -> V_783 )
return - V_180 ;
return 0 ;
}
static void F_295 ( struct V_1 * V_8 )
{
V_8 -> V_85 = F_266 ( & ( V_8 -> V_710 -> V_784 ) ) ;
if ( V_675 && V_8 -> V_85 > 32 )
V_8 -> V_85 = 32 ;
if ( V_8 -> V_85 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_264
L_265
L_266 ,
V_8 -> V_85 ) ;
V_8 -> V_85 = 16 ;
}
}
static void F_296 ( struct V_1 * V_8 )
{
F_295 ( V_8 ) ;
V_8 -> V_178 = V_8 -> V_85 - 4 ;
V_8 -> V_414 = F_266 ( & ( V_8 -> V_710 -> V_785 ) ) ;
V_8 -> V_355 = F_266 ( & ( V_8 -> V_710 -> V_717 ) ) ;
V_8 -> V_187 = 31 ;
if ( V_8 -> V_414 > 512 ) {
V_8 -> V_187 = 32 ;
V_8 -> V_179 = V_8 -> V_414 - V_8 -> V_187 + 1 ;
V_8 -> V_414 -- ;
} else {
V_8 -> V_414 = 31 ;
V_8 -> V_179 = 0 ;
}
V_8 -> V_576 = F_266 ( & ( V_8 -> V_710 -> V_576 ) ) ;
if ( ! ( V_575 & V_8 -> V_576 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_267 ) ;
if ( ! ( V_577 & V_8 -> V_576 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_268 ) ;
}
static inline bool F_297 ( struct V_1 * V_8 )
{
if ( ! F_298 ( V_8 -> V_710 -> V_728 , L_269 , 4 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_270 ) ;
return false ;
}
return true ;
}
static inline void F_299 ( struct V_1 * V_8 )
{
T_3 V_786 ;
V_786 = F_266 ( & ( V_8 -> V_710 -> V_786 ) ) ;
#ifdef F_300
V_786 |= V_787 ;
#endif
V_786 |= V_788 ;
F_265 ( V_786 , & ( V_8 -> V_710 -> V_786 ) ) ;
}
static inline void F_301 ( struct V_1 * V_8 )
{
T_3 V_789 ;
if ( V_8 -> V_50 != 0x3225103C )
return;
V_789 = F_266 ( V_8 -> V_690 + V_790 ) ;
V_789 |= 0x8000 ;
F_265 ( V_789 , V_8 -> V_690 + V_790 ) ;
}
static void F_302 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_791 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_792 ; V_51 ++ ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_791 = F_266 ( V_8 -> V_690 + V_702 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_791 & V_793 ) )
break;
F_117 ( 20 ) ;
}
}
static void F_303 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_791 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_792 ; V_51 ++ ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_791 = F_266 ( V_8 -> V_690 + V_702 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_791 & V_794 ) )
break;
F_304 ( 10000 , 20000 ) ;
}
}
static int F_305 ( struct V_1 * V_8 )
{
T_3 V_795 ;
V_795 = F_266 ( & ( V_8 -> V_710 -> V_730 ) ) ;
if ( ! ( V_795 & V_796 ) )
return - V_525 ;
V_8 -> V_85 = F_266 ( & ( V_8 -> V_710 -> V_736 ) ) ;
F_265 ( V_797 , & ( V_8 -> V_710 -> V_732 . V_733 ) ) ;
F_265 ( 0 , & V_8 -> V_710 -> V_732 . V_798 ) ;
F_265 ( V_794 , V_8 -> V_690 + V_702 ) ;
F_303 ( V_8 ) ;
F_285 ( & V_8 -> V_15 -> V_16 , V_8 -> V_710 ) ;
if ( ! ( F_266 ( & ( V_8 -> V_710 -> V_731 ) ) & V_797 ) )
goto error;
V_8 -> V_48 = V_797 ;
return 0 ;
error:
F_5 ( & V_8 -> V_15 -> V_16 , L_271 ) ;
return - V_62 ;
}
static int F_306 ( struct V_1 * V_8 )
{
int V_799 , V_594 ;
V_799 = F_278 ( V_8 -> V_15 , & V_8 -> V_50 ) ;
if ( V_799 < 0 )
return - V_62 ;
V_8 -> V_800 = V_765 [ V_799 ] . V_800 ;
V_8 -> V_79 = * ( V_765 [ V_799 ] . V_79 ) ;
F_307 ( V_8 -> V_15 , V_801 |
V_802 | V_803 ) ;
V_594 = F_308 ( V_8 -> V_15 ) ;
if ( V_594 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_272 ) ;
return V_594 ;
}
F_309 ( V_8 -> V_15 ) ;
V_594 = F_310 ( V_8 -> V_15 , V_17 ) ;
if ( V_594 ) {
F_59 ( & V_8 -> V_15 -> V_16 ,
L_273 ) ;
return V_594 ;
}
F_289 ( V_8 ) ;
V_594 = F_280 ( V_8 -> V_15 , & V_8 -> V_716 ) ;
if ( V_594 )
goto V_804;
V_8 -> V_690 = F_235 ( V_8 -> V_716 , 0x250 ) ;
if ( ! V_8 -> V_690 ) {
V_594 = - V_180 ;
goto V_804;
}
V_594 = F_284 ( V_8 -> V_15 , V_8 -> V_690 , V_725 ) ;
if ( V_594 )
goto V_804;
V_594 = F_294 ( V_8 ) ;
if ( V_594 )
goto V_804;
F_296 ( V_8 ) ;
if ( ! F_297 ( V_8 ) ) {
V_594 = - V_62 ;
goto V_804;
}
F_299 ( V_8 ) ;
F_301 ( V_8 ) ;
V_594 = F_305 ( V_8 ) ;
if ( V_594 )
goto V_804;
return 0 ;
V_804:
if ( V_8 -> V_783 )
F_263 ( V_8 -> V_783 ) ;
if ( V_8 -> V_710 )
F_263 ( V_8 -> V_710 ) ;
if ( V_8 -> V_690 )
F_263 ( V_8 -> V_690 ) ;
F_311 ( V_8 -> V_15 ) ;
F_312 ( V_8 -> V_15 ) ;
return V_594 ;
}
static void F_313 ( struct V_1 * V_8 )
{
int V_283 ;
#define F_314 64
V_8 -> V_46 = F_78 ( F_314 , V_154 ) ;
if ( ! V_8 -> V_46 )
return;
V_283 = F_120 ( V_8 , V_117 , 0 ,
V_8 -> V_46 , F_314 ) ;
if ( V_283 != 0 ) {
F_67 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
}
static int F_315 ( struct V_271 * V_15 )
{
int V_283 , V_51 ;
if ( ! V_675 )
return 0 ;
V_283 = F_308 ( V_15 ) ;
if ( V_283 ) {
F_5 ( & V_15 -> V_16 , L_274 ) ;
return - V_62 ;
}
F_311 ( V_15 ) ;
F_117 ( 260 ) ;
V_283 = F_308 ( V_15 ) ;
if ( V_283 ) {
F_5 ( & V_15 -> V_16 , L_275 ) ;
return - V_62 ;
}
F_309 ( V_15 ) ;
V_283 = F_277 ( V_15 ) ;
if ( V_283 ) {
if ( V_283 != - V_525 )
V_283 = - V_62 ;
goto V_805;
}
F_5 ( & V_15 -> V_16 , L_276 ) ;
for ( V_51 = 0 ; V_51 < V_806 ; V_51 ++ ) {
if ( F_316 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_277 ,
( V_51 < 11 ? L_278 : L_279 ) ) ;
}
V_805:
F_311 ( V_15 ) ;
return V_283 ;
}
static int F_317 ( struct V_1 * V_8 )
{
V_8 -> V_583 = F_81 (
F_318 ( V_8 -> V_178 , V_496 ) *
sizeof( unsigned long ) , V_154 ) ;
V_8 -> V_584 = F_264 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_584 ) ,
& ( V_8 -> V_585 ) ) ;
V_8 -> V_586 = F_264 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_586 ) ,
& ( V_8 -> V_587 ) ) ;
if ( ( V_8 -> V_583 == NULL )
|| ( V_8 -> V_584 == NULL )
|| ( V_8 -> V_586 == NULL ) ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_280 , V_155 ) ;
return - V_180 ;
}
return 0 ;
}
static void F_319 ( struct V_1 * V_8 )
{
F_67 ( V_8 -> V_583 ) ;
if ( V_8 -> V_584 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_584 , V_8 -> V_585 ) ;
if ( V_8 -> V_100 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_453 ) ;
if ( V_8 -> V_586 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_231 ) ,
V_8 -> V_586 ,
V_8 -> V_587 ) ;
if ( V_8 -> V_95 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_93 ) ,
V_8 -> V_95 , V_8 -> V_434 ) ;
}
static void F_320 ( struct V_1 * V_8 )
{
int V_51 , V_282 , V_283 ;
V_282 = F_321 ( V_807 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
V_283 = F_322 ( V_8 -> V_541 [ V_51 ] , F_323 ( V_282 ) ) ;
V_282 = F_324 ( V_282 , V_807 ) ;
}
}
static int F_325 ( struct V_1 * V_8 ,
T_15 (* F_326)( int , void * ) ,
T_15 (* F_327)( int , void * ) )
{
int V_283 , V_51 ;
for ( V_51 = 0 ; V_51 < V_754 ; V_51 ++ )
V_8 -> V_73 [ V_51 ] = ( T_4 ) V_51 ;
if ( V_8 -> V_542 == V_808 && V_8 -> V_90 > 0 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
V_283 = F_328 ( V_8 -> V_541 [ V_51 ] , F_326 ,
0 , V_8 -> V_809 ,
& V_8 -> V_73 [ V_51 ] ) ;
F_320 ( V_8 ) ;
} else {
if ( V_8 -> V_90 > 0 || V_8 -> V_760 ) {
V_283 = F_328 ( V_8 -> V_541 [ V_8 -> V_542 ] ,
F_326 , 0 , V_8 -> V_809 ,
& V_8 -> V_73 [ V_8 -> V_542 ] ) ;
} else {
V_283 = F_328 ( V_8 -> V_541 [ V_8 -> V_542 ] ,
F_327 , V_810 , V_8 -> V_809 ,
& V_8 -> V_73 [ V_8 -> V_542 ] ) ;
}
}
if ( V_283 ) {
F_59 ( & V_8 -> V_15 -> V_16 , L_281 ,
V_8 -> V_541 [ V_8 -> V_542 ] , V_8 -> V_809 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_329 ( struct V_1 * V_8 )
{
if ( F_234 ( V_8 , V_117 ,
V_811 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_282 ) ;
return - V_698 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_283 ) ;
if ( F_284 ( V_8 -> V_15 , V_8 -> V_690 , V_812 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_284 ) ;
return - 1 ;
}
F_60 ( & V_8 -> V_15 -> V_16 , L_285 ) ;
if ( F_284 ( V_8 -> V_15 , V_8 -> V_690 , V_725 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_286
L_287 ) ;
return - 1 ;
}
return 0 ;
}
static void F_330 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_90 || V_8 -> V_542 != V_808 ) {
V_51 = V_8 -> V_542 ;
F_322 ( V_8 -> V_541 [ V_51 ] , NULL ) ;
F_331 ( V_8 -> V_541 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
F_322 ( V_8 -> V_541 [ V_51 ] , NULL ) ;
F_331 ( V_8 -> V_541 [ V_51 ] , & V_8 -> V_73 [ V_51 ] ) ;
}
}
static void F_332 ( struct V_1 * V_8 )
{
F_330 ( V_8 ) ;
#ifdef F_290
if ( V_8 -> V_90 ) {
if ( V_8 -> V_15 -> V_813 )
F_333 ( V_8 -> V_15 ) ;
} else if ( V_8 -> V_760 ) {
if ( V_8 -> V_15 -> V_814 )
F_334 ( V_8 -> V_15 ) ;
}
#endif
}
static void F_335 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
if ( ! V_8 -> V_77 [ V_51 ] . V_81 )
continue;
F_214 ( V_8 -> V_15 , V_8 -> V_815 ,
V_8 -> V_77 [ V_51 ] . V_81 , V_8 -> V_77 [ V_51 ] . V_86 ) ;
V_8 -> V_77 [ V_51 ] . V_81 = NULL ;
V_8 -> V_77 [ V_51 ] . V_86 = 0 ;
}
}
static void F_336 ( struct V_1 * V_8 )
{
F_332 ( V_8 ) ;
F_91 ( V_8 ) ;
F_319 ( V_8 ) ;
F_67 ( V_8 -> V_97 ) ;
F_67 ( V_8 -> V_87 ) ;
F_335 ( V_8 ) ;
if ( V_8 -> V_690 )
F_263 ( V_8 -> V_690 ) ;
if ( V_8 -> V_783 )
F_263 ( V_8 -> V_783 ) ;
if ( V_8 -> V_710 )
F_263 ( V_8 -> V_710 ) ;
F_311 ( V_8 -> V_15 ) ;
F_312 ( V_8 -> V_15 ) ;
F_67 ( V_8 ) ;
}
static void F_337 ( struct V_1 * V_8 , struct V_71 * V_72 )
{
struct V_9 * V_10 = NULL ;
F_338 ( & V_8 -> V_60 ) ;
while ( ! F_49 ( V_72 ) ) {
V_10 = F_237 ( V_72 -> V_666 , struct V_9 , V_72 ) ;
V_10 -> V_11 -> V_23 = V_262 ;
F_209 ( V_10 ) ;
}
}
static void F_339 ( struct V_1 * V_8 , T_3 V_816 )
{
int V_51 , V_282 ;
V_282 = F_321 ( V_807 ) ;
for ( V_51 = 0 ; V_51 < F_291 () ; V_51 ++ ) {
T_3 * F_111 ;
F_111 = F_113 ( V_8 -> F_111 , V_282 ) ;
* F_111 = V_816 ;
V_282 = F_324 ( V_282 , V_807 ) ;
}
F_340 () ;
}
static void F_341 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
T_3 F_111 ;
V_8 -> V_79 . V_817 ( V_8 , V_818 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_111 = F_266 ( V_8 -> V_690 + V_776 ) ;
if ( ! F_111 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_288 ) ;
F_111 = 0xffffffff ;
}
F_339 ( V_8 , F_111 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_289 ,
F_111 ) ;
F_311 ( V_8 -> V_15 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_337 ( V_8 , & V_8 -> V_570 ) ;
F_337 ( V_8 , & V_8 -> V_115 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_342 ( struct V_1 * V_8 )
{
T_5 V_819 ;
T_3 V_820 ;
unsigned long V_59 ;
V_819 = F_255 () ;
if ( F_343 ( V_8 -> V_678 +
( V_8 -> V_109 ) , V_819 ) )
return;
if ( F_343 ( V_8 -> V_821 +
( V_8 -> V_109 ) , V_819 ) )
return;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_820 = F_266 ( & V_8 -> V_710 -> V_739 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_822 == V_820 ) {
F_341 ( V_8 ) ;
return;
}
V_8 -> V_822 = V_820 ;
V_8 -> V_821 = V_819 ;
}
static void F_344 ( struct V_1 * V_8 )
{
int V_51 ;
char * V_823 ;
V_8 -> V_229 = 0 ;
if ( ( V_8 -> V_48 & ( V_78
| V_387 ) ) &&
( V_8 -> V_824 & V_825 ||
V_8 -> V_824 & V_826 ) ) {
if ( V_8 -> V_824 & V_825 )
V_823 = L_290 ;
if ( V_8 -> V_824 & V_826 )
V_823 = L_291 ;
F_345 ( V_8 -> V_44 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] -> V_70 = 0 ;
F_346 ( V_8 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_292 ,
V_8 -> V_824 , V_823 ) ;
F_265 ( V_8 -> V_824 , & ( V_8 -> V_710 -> V_827 ) ) ;
F_265 ( V_793 , V_8 -> V_690 + V_702 ) ;
F_302 ( V_8 ) ;
F_347 ( V_8 -> V_44 ) ;
} else {
F_265 ( V_8 -> V_824 , & ( V_8 -> V_710 -> V_827 ) ) ;
F_265 ( V_793 , V_8 -> V_690 + V_702 ) ;
F_302 ( V_8 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_348 ( struct V_1 * V_8 )
{
if ( V_8 -> V_229 )
return 1 ;
if ( ! ( V_8 -> V_355 & V_828 ) )
return 0 ;
V_8 -> V_824 = F_266 ( & ( V_8 -> V_710 -> V_829 ) ) ;
return V_8 -> V_824 & V_830 ;
}
static int F_349 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
struct V_152 * V_288 ;
struct V_71 * V_831 , * V_832 ;
F_25 ( & V_8 -> V_153 , V_59 ) ;
F_350 (this, tmp, &h->offline_device_list) {
V_288 = F_237 ( V_831 , struct V_152 ,
V_156 ) ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
if ( ! F_143 ( V_8 , V_288 -> V_54 ) ) {
F_25 ( & V_8 -> V_153 , V_59 ) ;
F_351 ( & V_288 -> V_156 ) ;
F_26 ( & V_8 -> V_153 , V_59 ) ;
return 1 ;
}
F_25 ( & V_8 -> V_153 , V_59 ) ;
}
F_26 ( & V_8 -> V_153 , V_59 ) ;
return 0 ;
}
static void F_352 ( struct V_833 * V_834 )
{
unsigned long V_59 ;
struct V_1 * V_8 = F_253 ( F_353 ( V_834 ) ,
struct V_1 , V_835 ) ;
F_342 ( V_8 ) ;
if ( F_111 ( V_8 ) )
return;
if ( F_348 ( V_8 ) || F_349 ( V_8 ) ) {
F_354 ( V_8 -> V_44 ) ;
V_8 -> V_229 = 0 ;
F_344 ( V_8 ) ;
F_12 ( V_8 -> V_44 ) ;
F_193 ( V_8 -> V_44 ) ;
}
F_25 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_836 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
return;
}
F_355 ( & V_8 -> V_835 ,
V_8 -> V_109 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
}
static int F_356 ( struct V_271 * V_15 , const struct V_837 * V_838 )
{
int V_839 , V_283 ;
struct V_1 * V_8 ;
int V_840 = 0 ;
unsigned long V_59 ;
if ( V_841 == 0 )
F_357 (KERN_INFO DRIVER_NAME L_293 ) ;
V_283 = F_315 ( V_15 ) ;
if ( V_283 ) {
if ( V_283 != - V_525 )
return V_283 ;
V_840 = 1 ;
V_283 = 0 ;
}
V_842:
F_358 ( sizeof( struct V_9 ) % V_843 ) ;
V_8 = F_81 ( sizeof( * V_8 ) , V_154 ) ;
if ( ! V_8 )
return - V_180 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_542 = V_844 ? V_845 : V_808 ;
F_212 ( & V_8 -> V_570 ) ;
F_212 ( & V_8 -> V_115 ) ;
F_212 ( & V_8 -> V_157 ) ;
F_359 ( & V_8 -> V_60 ) ;
F_359 ( & V_8 -> V_153 ) ;
F_359 ( & V_8 -> V_517 ) ;
F_359 ( & V_8 -> V_648 ) ;
V_8 -> F_111 = F_360 ( T_3 ) ;
if ( ! V_8 -> F_111 ) {
V_283 = - V_180 ;
goto V_846;
}
F_339 ( V_8 , 0 ) ;
V_283 = F_306 ( V_8 ) ;
if ( V_283 != 0 )
goto V_846;
sprintf ( V_8 -> V_809 , V_17 L_14 , V_841 ) ;
V_8 -> V_18 = V_841 ;
V_841 ++ ;
V_283 = F_361 ( V_15 , F_262 ( 64 ) ) ;
if ( V_283 == 0 ) {
V_839 = 1 ;
} else {
V_283 = F_361 ( V_15 , F_262 ( 32 ) ) ;
if ( V_283 == 0 ) {
V_839 = 0 ;
} else {
F_59 ( & V_15 -> V_16 , L_294 ) ;
goto V_846;
}
}
V_8 -> V_79 . V_817 ( V_8 , V_818 ) ;
if ( F_325 ( V_8 , F_258 , F_257 ) )
goto V_847;
F_60 ( & V_15 -> V_16 , L_295 ,
V_8 -> V_809 , V_15 -> V_28 ,
V_8 -> V_541 [ V_8 -> V_542 ] , V_839 ? L_279 : L_296 ) ;
if ( F_317 ( V_8 ) )
goto V_848;
if ( F_92 ( V_8 ) )
goto V_848;
F_362 ( & V_8 -> V_519 ) ;
V_8 -> V_518 = 1 ;
F_363 ( V_15 , V_8 ) ;
V_8 -> V_124 = 0 ;
V_8 -> V_395 = 0 ;
V_8 -> V_44 = NULL ;
F_359 ( & V_8 -> V_176 ) ;
F_364 ( V_8 ) ;
if ( V_840 ) {
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_79 . V_817 ( V_8 , V_818 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_330 ( V_8 ) ;
V_283 = F_325 ( V_8 , F_256 ,
F_254 ) ;
if ( V_283 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_297
L_298 ) ;
goto V_848;
}
V_283 = F_329 ( V_8 ) ;
if ( V_283 )
goto V_848;
F_60 ( & V_8 -> V_15 -> V_16 , L_299 ) ;
F_60 ( & V_8 -> V_15 -> V_16 ,
L_300 ) ;
V_8 -> V_79 . V_817 ( V_8 , V_849 ) ;
F_117 ( 10000 ) ;
V_8 -> V_79 . V_817 ( V_8 , V_818 ) ;
V_283 = F_276 ( V_8 -> V_710 ) ;
if ( V_283 )
F_60 ( & V_8 -> V_15 -> V_16 ,
L_301 ) ;
F_336 ( V_8 ) ;
V_840 = 0 ;
if ( V_283 )
return - V_62 ;
goto V_842;
}
V_8 -> V_41 = 1 ;
V_8 -> V_229 = 0 ;
V_8 -> V_79 . V_817 ( V_8 , V_849 ) ;
F_313 ( V_8 ) ;
F_194 ( V_8 ) ;
V_8 -> V_109 = V_111 ;
F_365 ( & V_8 -> V_835 , F_352 ) ;
F_355 ( & V_8 -> V_835 ,
V_8 -> V_109 ) ;
return 0 ;
V_848:
F_91 ( V_8 ) ;
F_319 ( V_8 ) ;
F_330 ( V_8 ) ;
V_847:
V_846:
if ( V_8 -> F_111 )
F_366 ( V_8 -> F_111 ) ;
F_67 ( V_8 ) ;
return V_283 ;
}
static void F_367 ( struct V_1 * V_8 )
{
char * V_850 ;
struct V_9 * V_10 ;
if ( F_33 ( F_111 ( V_8 ) ) )
return;
V_850 = F_81 ( 4 , V_154 ) ;
if ( ! V_850 )
return;
V_10 = F_121 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_125 ) ;
goto V_851;
}
if ( F_122 ( V_10 , V_655 , V_8 , V_850 , 4 , 0 ,
V_117 , V_293 ) ) {
goto V_294;
}
F_116 ( V_8 , V_10 , V_192 ) ;
if ( V_10 -> V_11 -> V_23 != 0 )
V_294:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_302 ) ;
F_123 ( V_8 , V_10 ) ;
V_851:
F_67 ( V_850 ) ;
}
static void F_368 ( struct V_271 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_369 ( V_15 ) ;
F_367 ( V_8 ) ;
V_8 -> V_79 . V_817 ( V_8 , V_818 ) ;
F_332 ( V_8 ) ;
}
static void F_370 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
F_67 ( V_8 -> V_16 [ V_51 ] ) ;
}
static void F_371 ( struct V_271 * V_15 )
{
struct V_1 * V_8 ;
unsigned long V_59 ;
if ( F_369 ( V_15 ) == NULL ) {
F_59 ( & V_15 -> V_16 , L_303 ) ;
return;
}
V_8 = F_369 ( V_15 ) ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_836 = 1 ;
F_372 ( & V_8 -> V_835 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_191 ( V_8 ) ;
F_368 ( V_15 ) ;
F_263 ( V_8 -> V_690 ) ;
F_263 ( V_8 -> V_783 ) ;
F_263 ( V_8 -> V_710 ) ;
F_370 ( V_8 ) ;
F_91 ( V_8 ) ;
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_9 ) ,
V_8 -> V_584 , V_8 -> V_585 ) ;
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( struct V_231 ) ,
V_8 -> V_586 , V_8 -> V_587 ) ;
F_335 ( V_8 ) ;
F_67 ( V_8 -> V_583 ) ;
F_67 ( V_8 -> V_87 ) ;
F_67 ( V_8 -> V_97 ) ;
F_67 ( V_8 -> V_101 ) ;
F_67 ( V_8 -> V_46 ) ;
F_311 ( V_15 ) ;
F_312 ( V_15 ) ;
F_366 ( V_8 -> F_111 ) ;
F_67 ( V_8 ) ;
}
static void F_373 ( int V_852 [] , int V_853 ,
int V_854 , int V_855 , int * V_856 )
{
int V_51 , V_142 , V_857 , V_342 ;
for ( V_51 = 0 ; V_51 <= V_854 ; V_51 ++ ) {
V_342 = V_51 + V_855 ;
V_857 = V_853 ;
for ( V_142 = 0 ; V_142 < V_853 ; V_142 ++ ) {
if ( V_852 [ V_142 ] >= V_342 ) {
V_857 = V_142 ;
break;
}
}
V_856 [ V_51 ] = V_857 ;
}
}
static void F_374 ( struct V_1 * V_8 , T_3 V_795 )
{
int V_51 ;
unsigned long V_858 ;
unsigned long V_48 = V_49 |
( V_795 & V_859 ) |
V_860 |
( V_795 & ( V_78 |
V_387 ) ) ;
struct V_861 V_79 = V_862 ;
int V_863 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_645 + 4 } ;
#define F_375 5
#define F_376 4
int V_864 [ 16 ] = { F_375 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_376 + V_456 } ;
F_358 ( F_18 ( V_864 ) != 16 ) ;
F_358 ( F_18 ( V_863 ) != 8 ) ;
F_358 ( F_178 ( struct V_99 , V_409 ) >
16 * F_375 ) ;
F_358 ( sizeof( struct V_452 ) != 16 ) ;
F_358 ( 28 > V_645 + 4 ) ;
if ( V_795 & ( V_78 | V_387 ) )
V_79 = V_865 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ )
memset ( V_8 -> V_77 [ V_51 ] . V_81 , 0 , V_8 -> V_815 ) ;
V_863 [ 7 ] = V_645 + 4 ;
F_373 ( V_863 , F_18 ( V_863 ) ,
V_645 , 4 , V_8 -> V_87 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
F_265 ( V_863 [ V_51 ] , & V_8 -> V_783 -> V_866 [ V_51 ] ) ;
F_265 ( V_8 -> V_85 , & V_8 -> V_783 -> V_867 ) ;
F_265 ( V_8 -> V_92 , & V_8 -> V_783 -> V_868 ) ;
F_265 ( 0 , & V_8 -> V_783 -> V_869 ) ;
F_265 ( 0 , & V_8 -> V_783 -> V_870 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_265 ( 0 , & V_8 -> V_783 -> V_871 [ V_51 ] . V_195 ) ;
F_265 ( V_8 -> V_77 [ V_51 ] . V_86 ,
& V_8 -> V_783 -> V_871 [ V_51 ] . V_194 ) ;
}
F_265 ( 0 , & V_8 -> V_710 -> V_732 . V_798 ) ;
F_265 ( V_48 , & ( V_8 -> V_710 -> V_732 . V_733 ) ) ;
if ( V_795 & V_78 ) {
V_79 = V_872 ;
F_265 ( 10 , & V_8 -> V_710 -> V_732 . V_734 ) ;
F_265 ( 4 , & V_8 -> V_710 -> V_732 . V_735 ) ;
} else {
if ( V_795 & V_387 ) {
V_79 = V_873 ;
F_265 ( 10 , & V_8 -> V_710 -> V_732 . V_734 ) ;
F_265 ( 4 , & V_8 -> V_710 -> V_732 . V_735 ) ;
}
}
F_265 ( V_794 , V_8 -> V_690 + V_702 ) ;
F_303 ( V_8 ) ;
V_858 = F_266 ( & ( V_8 -> V_710 -> V_731 ) ) ;
if ( ! ( V_858 & V_49 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_304
L_305 ) ;
return;
}
V_8 -> V_79 = V_79 ;
V_8 -> V_48 = V_48 ;
if ( ! ( ( V_795 & V_78 ) ||
( V_795 & V_387 ) ) )
return;
if ( V_795 & V_78 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
F_265 ( V_51 , V_8 -> V_690 + V_874 ) ;
V_8 -> V_77 [ V_51 ] . V_82 =
F_266 ( V_8 -> V_690 + V_875 ) ;
}
V_863 [ 7 ] = V_8 -> V_431 + 8 ;
F_373 ( V_863 , F_18 ( V_863 ) , V_8 -> V_431 , 8 ,
V_8 -> V_97 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ )
memset ( V_8 -> V_77 [ V_51 ] . V_81 ,
( T_4 ) V_876 ,
V_8 -> V_815 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_178 ; V_51 ++ ) {
struct V_93 * V_94 = & V_8 -> V_95 [ V_51 ] ;
V_94 -> V_877 = V_878 ;
V_94 -> V_11 = ( T_3 ) ( V_8 -> V_587 +
( V_51 * sizeof( struct V_231 ) ) ) ;
V_94 -> V_879 = sizeof( struct V_231 ) ;
V_94 -> V_880 = V_881 ;
V_94 -> V_882 = V_883 ;
V_94 -> V_884 = 0 ;
V_94 -> V_91 = 0 ;
V_94 -> V_246 . V_194 = ( V_51 << V_465 ) |
V_466 ;
V_94 -> V_246 . V_195 = 0 ;
V_94 -> V_885 . V_194 =
( T_3 ) ( V_8 -> V_434 +
( V_51 * sizeof( struct V_93 ) ) ) ;
V_94 -> V_885 . V_195 = 0 ;
}
} else if ( V_795 & V_387 ) {
T_5 V_713 , V_715 ;
T_3 V_886 , V_714 ;
int V_283 ;
V_283 = F_281 ( V_8 -> V_15 , V_8 -> V_690 , & V_714 ,
& V_715 , & V_713 ) ;
F_358 ( F_178 ( struct V_99 , V_409 ) != 64 ) ;
V_864 [ 15 ] = V_8 -> V_431 + F_376 ;
F_373 ( V_864 , F_18 ( V_864 ) , V_8 -> V_431 ,
4 , V_8 -> V_101 ) ;
V_886 = F_266 ( & V_8 -> V_710 -> V_887 ) ;
F_358 ( F_178 ( struct V_709 ,
V_887 ) != 0xb8 ) ;
V_8 -> V_888 =
F_235 ( F_282 ( V_8 -> V_15 ,
V_715 ) +
V_713 + V_886 ,
F_18 ( V_864 ) *
sizeof( * V_8 -> V_888 ) ) ;
for ( V_51 = 0 ; V_51 < F_18 ( V_864 ) ; V_51 ++ )
F_265 ( V_864 [ V_51 ] , & V_8 -> V_888 [ V_51 ] ) ;
}
F_265 ( V_794 , V_8 -> V_690 + V_702 ) ;
F_303 ( V_8 ) ;
}
static int F_377 ( struct V_1 * V_8 )
{
V_8 -> V_431 =
F_266 ( & ( V_8 -> V_710 -> V_889 ) ) ;
if ( V_8 -> V_431 > V_890 )
V_8 -> V_431 = V_890 ;
F_358 ( sizeof( struct V_93 ) %
V_891 ) ;
V_8 -> V_95 =
F_264 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
& ( V_8 -> V_434 ) ) ;
V_8 -> V_97 =
F_78 ( ( ( V_8 -> V_431 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_95 == NULL ) ||
( V_8 -> V_97 == NULL ) )
goto V_892;
memset ( V_8 -> V_95 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ) ;
return 0 ;
V_892:
if ( V_8 -> V_95 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_95 ) ,
V_8 -> V_95 , V_8 -> V_434 ) ;
F_67 ( V_8 -> V_97 ) ;
return 1 ;
}
static int F_378 ( struct V_1 * V_8 )
{
V_8 -> V_431 =
F_266 ( & ( V_8 -> V_710 -> V_889 ) ) ;
if ( V_8 -> V_431 > V_456 )
V_8 -> V_431 = V_456 ;
F_358 ( sizeof( struct V_99 ) %
V_893 ) ;
V_8 -> V_100 =
F_264 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
& ( V_8 -> V_453 ) ) ;
V_8 -> V_101 =
F_78 ( ( ( V_8 -> V_431 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ( V_8 -> V_100 == NULL ) ||
( V_8 -> V_101 == NULL ) )
goto V_892;
memset ( V_8 -> V_100 , 0 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ) ;
return 0 ;
V_892:
if ( V_8 -> V_100 )
F_214 ( V_8 -> V_15 ,
V_8 -> V_178 * sizeof( * V_8 -> V_100 ) ,
V_8 -> V_100 , V_8 -> V_453 ) ;
F_67 ( V_8 -> V_101 ) ;
return 1 ;
}
static void F_364 ( struct V_1 * V_8 )
{
T_3 V_795 ;
unsigned long V_48 = V_49 |
V_859 ;
int V_51 ;
if ( V_844 )
return;
V_795 = F_266 ( & ( V_8 -> V_710 -> V_730 ) ) ;
if ( ! ( V_795 & V_894 ) )
return;
if ( V_795 & V_78 ) {
V_48 |= V_78 |
V_860 ;
if ( F_377 ( V_8 ) )
goto V_892;
} else {
if ( V_795 & V_387 ) {
V_48 |= V_387 |
V_860 ;
if ( F_378 ( V_8 ) )
goto V_892;
}
}
V_8 -> V_92 = V_8 -> V_90 > 0 ? V_8 -> V_90 : 1 ;
F_295 ( V_8 ) ;
V_8 -> V_815 = V_8 -> V_85 * sizeof( T_5 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_92 ; V_51 ++ ) {
V_8 -> V_77 [ V_51 ] . V_81 = F_264 ( V_8 -> V_15 ,
V_8 -> V_815 ,
& ( V_8 -> V_77 [ V_51 ] . V_86 ) ) ;
if ( ! V_8 -> V_77 [ V_51 ] . V_81 )
goto V_892;
V_8 -> V_77 [ V_51 ] . V_342 = V_8 -> V_85 ;
V_8 -> V_77 [ V_51 ] . V_83 = 1 ;
V_8 -> V_77 [ V_51 ] . V_82 = 0 ;
}
V_8 -> V_87 = F_78 ( ( ( V_645 + 1 ) *
sizeof( T_3 ) ) , V_154 ) ;
if ( ! V_8 -> V_87 )
goto V_892;
F_374 ( V_8 , V_795 ) ;
return;
V_892:
F_335 ( V_8 ) ;
F_67 ( V_8 -> V_87 ) ;
}
static int F_379 ( struct V_9 * V_10 )
{
return V_10 -> V_112 == V_113 || V_10 -> V_112 == V_114 ;
}
static void F_346 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_59 ;
int V_895 ;
do {
V_895 = 0 ;
F_25 ( & V_8 -> V_60 , V_59 ) ;
F_77 (c, &h->cmpQ, list)
V_895 += F_379 ( V_10 ) ;
F_77 (c, &h->reqQ, list)
V_895 += F_379 ( V_10 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( V_895 <= 0 )
break;
F_117 ( 100 ) ;
} while ( 1 );
}
static int T_17 F_380 ( void )
{
return F_381 ( & V_896 ) ;
}
static void T_18 F_382 ( void )
{
F_383 ( & V_896 ) ;
}
