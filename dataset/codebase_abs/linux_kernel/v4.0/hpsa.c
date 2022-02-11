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
static inline T_3 F_31 ( struct V_1 * V_8 , T_4 V_71 )
{
T_3 V_72 ;
struct V_73 * V_74 = & V_8 -> V_75 [ V_71 ] ;
if ( V_8 -> V_48 & V_76 )
return V_8 -> V_77 . V_78 ( V_8 , V_71 ) ;
if ( F_32 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_8 -> V_77 . V_78 ( V_8 , V_71 ) ;
if ( ( V_74 -> V_79 [ V_74 -> V_80 ] & 1 ) == V_74 -> V_81 ) {
V_72 = V_74 -> V_79 [ V_74 -> V_80 ] ;
V_74 -> V_80 ++ ;
F_33 ( & V_8 -> V_47 ) ;
} else {
V_72 = V_82 ;
}
if ( V_74 -> V_80 == V_8 -> V_83 ) {
V_74 -> V_80 = 0 ;
V_74 -> V_81 ^= 1 ;
}
return V_72 ;
}
static void F_34 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_35 ( V_8 -> V_48 & V_49 ) ) {
V_10 -> V_84 |= 1 | ( V_8 -> V_85 [ V_10 -> V_86 . V_87 ] << 1 ) ;
if ( F_35 ( V_8 -> V_88 > 0 ) )
V_10 -> V_86 . V_89 =
F_36 () % V_8 -> V_90 ;
}
}
static void F_37 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_91 * V_92 = & V_8 -> V_93 [ V_10 -> V_94 ] ;
V_92 -> V_89 = F_38 () % V_8 -> V_90 ;
V_10 -> V_84 |= 1 | ( V_8 -> V_95 [ V_10 -> V_86 . V_87 ] << 1 ) |
V_96 ;
}
static void F_39 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_97 * V_92 = & V_8 -> V_98 [ V_10 -> V_94 ] ;
V_92 -> V_75 = F_38 () % V_8 -> V_90 ;
V_10 -> V_84 |= ( V_8 -> V_99 [ V_92 -> V_100 ] ) ;
}
static int F_40 ( T_4 * V_101 )
{
return V_101 [ 0 ] == V_102 && V_101 [ 6 ] == V_103 ;
}
static void F_41 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_40 ( V_10 -> V_104 . V_105 ) )
return;
F_42 ( & V_8 -> V_106 ) ;
V_8 -> V_107 = V_108 ;
}
static void F_43 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_40 ( V_10 -> V_104 . V_105 ) &&
F_44 ( & V_8 -> V_106 ) )
V_8 -> V_107 = V_109 ;
}
static void F_45 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_41 ( V_8 , V_10 ) ;
F_42 ( & V_8 -> V_47 ) ;
switch ( V_10 -> V_110 ) {
case V_111 :
F_37 ( V_8 , V_10 ) ;
F_46 ( V_10 -> V_84 , V_8 -> V_112 + V_113 ) ;
break;
case V_114 :
F_39 ( V_8 , V_10 ) ;
F_46 ( V_10 -> V_84 , V_8 -> V_112 + V_115 ) ;
break;
default:
F_34 ( V_8 , V_10 ) ;
V_8 -> V_77 . V_116 ( V_8 , V_10 ) ;
}
}
static inline int F_47 ( unsigned char V_54 [] )
{
return memcmp ( V_54 , V_117 , 8 ) == 0 ;
}
static inline int F_48 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_46 )
return 0 ;
if ( ( V_8 -> V_46 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_8 ,
unsigned char V_54 [] , int V_118 , int * V_119 , int * V_120 )
{
int V_51 , V_121 = 0 ;
F_50 ( V_122 , V_123 ) ;
F_51 ( V_122 , V_123 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] -> V_118 == V_118 && V_8 -> V_16 [ V_51 ] -> V_119 != - 1 )
F_52 ( V_8 -> V_16 [ V_51 ] -> V_119 , V_122 ) ;
}
V_51 = F_53 ( V_122 , V_123 ) ;
if ( V_51 < V_123 ) {
* V_119 = V_51 ;
* V_120 = 0 ;
V_121 = 1 ;
}
return ! V_121 ;
}
static int F_54 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_28 ,
struct V_57 * V_126 [] , int * V_127 )
{
int V_128 = V_8 -> V_124 ;
int V_51 ;
unsigned char V_129 [ 8 ] , V_130 [ 8 ] ;
struct V_57 * V_131 ;
if ( V_128 >= V_123 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_28
L_29 ) ;
return - 1 ;
}
if ( V_28 -> V_120 != - 1 )
goto V_132;
if ( V_28 -> V_54 [ 4 ] == 0 ) {
if ( F_49 ( V_8 , V_28 -> V_54 ,
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
F_56 ( & V_8 -> V_15 -> V_16 , L_33 ,
F_57 ( V_28 -> V_133 ) , V_125 ,
V_28 -> V_118 , V_28 -> V_119 , V_28 -> V_120 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 )
{
F_59 ( V_134 < 0 || V_134 >= V_123 ) ;
V_8 -> V_16 [ V_134 ] -> V_64 = V_135 -> V_64 ;
if ( V_135 -> V_136 && V_135 -> V_70 ) {
V_8 -> V_16 [ V_134 ] -> V_137 = V_135 -> V_137 ;
V_8 -> V_16 [ V_134 ] -> V_138 = V_135 -> V_138 ;
F_60 () ;
}
V_8 -> V_16 [ V_134 ] -> V_136 = V_135 -> V_136 ;
V_8 -> V_16 [ V_134 ] -> V_139 = V_135 -> V_139 ;
V_8 -> V_16 [ V_134 ] -> V_70 = V_135 -> V_70 ;
V_8 -> V_16 [ V_134 ] -> V_140 = V_135 -> V_140 ;
F_56 ( & V_8 -> V_15 -> V_16 , L_34 ,
F_57 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_61 ( struct V_1 * V_8 , int V_125 ,
int V_134 , struct V_57 * V_135 ,
struct V_57 * V_126 [] , int * V_127 ,
struct V_57 * V_141 [] , int * V_142 )
{
F_59 ( V_134 < 0 || V_134 >= V_123 ) ;
V_141 [ * V_142 ] = V_8 -> V_16 [ V_134 ] ;
( * V_142 ) ++ ;
if ( V_135 -> V_119 == - 1 ) {
V_135 -> V_119 = V_8 -> V_16 [ V_134 ] -> V_119 ;
V_135 -> V_120 = V_8 -> V_16 [ V_134 ] -> V_120 ;
}
V_8 -> V_16 [ V_134 ] = V_135 ;
V_126 [ * V_127 ] = V_135 ;
( * V_127 ) ++ ;
F_56 ( & V_8 -> V_15 -> V_16 , L_35 ,
F_57 ( V_135 -> V_133 ) , V_125 , V_135 -> V_118 ,
V_135 -> V_119 , V_135 -> V_120 ) ;
}
static void F_62 ( struct V_1 * V_8 , int V_125 , int V_134 ,
struct V_57 * V_141 [] , int * V_142 )
{
int V_51 ;
struct V_57 * V_131 ;
F_59 ( V_134 < 0 || V_134 >= V_123 ) ;
V_131 = V_8 -> V_16 [ V_134 ] ;
V_141 [ * V_142 ] = V_8 -> V_16 [ V_134 ] ;
( * V_142 ) ++ ;
for ( V_51 = V_134 ; V_51 < V_8 -> V_124 - 1 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] = V_8 -> V_16 [ V_51 + 1 ] ;
V_8 -> V_124 -- ;
F_56 ( & V_8 -> V_15 -> V_16 , L_36 ,
F_57 ( V_131 -> V_133 ) , V_125 , V_131 -> V_118 , V_131 -> V_119 ,
V_131 -> V_120 ) ;
}
static void F_63 ( struct V_1 * V_8 ,
struct V_57 * V_126 )
{
unsigned long V_59 ;
int V_51 , V_143 ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ ) {
if ( V_8 -> V_16 [ V_51 ] == V_126 ) {
for ( V_143 = V_51 ; V_143 < V_8 -> V_124 - 1 ; V_143 ++ )
V_8 -> V_16 [ V_143 ] = V_8 -> V_16 [ V_143 + 1 ] ;
V_8 -> V_124 -- ;
break;
}
}
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_64 ( V_126 ) ;
}
static inline int F_65 ( struct V_57 * V_144 ,
struct V_57 * V_145 )
{
if ( memcmp ( V_144 -> V_54 , V_145 -> V_54 ,
sizeof( V_144 -> V_54 ) ) != 0 )
return 0 ;
if ( memcmp ( V_144 -> V_69 , V_145 -> V_69 ,
sizeof( V_144 -> V_69 ) ) != 0 )
return 0 ;
if ( memcmp ( V_144 -> V_146 , V_145 -> V_146 , sizeof( V_144 -> V_146 ) ) != 0 )
return 0 ;
if ( memcmp ( V_144 -> V_147 , V_145 -> V_147 , sizeof( V_144 -> V_147 ) ) != 0 )
return 0 ;
if ( V_144 -> V_133 != V_145 -> V_133 )
return 0 ;
if ( V_144 -> V_118 != V_145 -> V_118 )
return 0 ;
return 1 ;
}
static inline int F_66 ( struct V_57 * V_144 ,
struct V_57 * V_145 )
{
if ( V_144 -> V_64 != V_145 -> V_64 )
return 1 ;
if ( V_144 -> V_136 != V_145 -> V_136 )
return 1 ;
if ( V_144 -> V_70 != V_145 -> V_70 )
return 1 ;
if ( V_144 -> V_140 != V_145 -> V_140 )
return 1 ;
return 0 ;
}
static int F_67 ( struct V_57 * V_148 ,
struct V_57 * V_149 [] , int V_150 ,
int * V_151 )
{
int V_51 ;
#define F_68 0
#define F_69 1
#define F_70 2
#define F_71 3
for ( V_51 = 0 ; V_51 < V_150 ; V_51 ++ ) {
if ( V_149 [ V_51 ] == NULL )
continue;
if ( F_72 ( V_148 -> V_54 , V_149 [ V_51 ] -> V_54 ) ) {
* V_151 = V_51 ;
if ( F_65 ( V_148 , V_149 [ V_51 ] ) ) {
if ( F_66 ( V_148 , V_149 [ V_51 ] ) )
return F_71 ;
return F_70 ;
} else {
if ( V_148 -> V_152 )
return F_68 ;
return F_69 ;
}
}
}
* V_151 = - 1 ;
return F_68 ;
}
static void F_73 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_153 * V_28 ;
unsigned long V_59 ;
F_26 ( & V_8 -> V_154 , V_59 ) ;
F_74 (device, &h->offline_device_list, offline_list) {
if ( memcmp ( V_28 -> V_54 , V_54 ,
sizeof( V_28 -> V_54 ) ) == 0 ) {
F_27 ( & V_8 -> V_154 , V_59 ) ;
return;
}
}
F_27 ( & V_8 -> V_154 , V_59 ) ;
V_28 = F_75 ( sizeof( * V_28 ) , V_155 ) ;
if ( ! V_28 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_37 , V_156 ) ;
return;
}
memcpy ( V_28 -> V_54 , V_54 , sizeof( V_28 -> V_54 ) ) ;
F_26 ( & V_8 -> V_154 , V_59 ) ;
F_76 ( & V_28 -> V_157 , & V_8 -> V_158 ) ;
F_27 ( & V_8 -> V_154 , V_59 ) ;
}
static void F_77 ( struct V_1 * V_8 ,
struct V_57 * V_131 )
{
if ( V_131 -> V_152 == V_159 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_38 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
switch ( V_131 -> V_152 ) {
case V_161 :
break;
case V_162 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_39 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_163 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_40 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_164 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_41 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_165 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_42 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_166 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_43 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_167 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_44 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_168 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_45 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_169 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_46 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_170 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_47 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
case V_171 :
F_56 ( & V_8 -> V_15 -> V_16 ,
L_48 ,
V_8 -> V_44 -> V_160 ,
V_131 -> V_118 , V_131 -> V_119 , V_131 -> V_120 ) ;
break;
}
}
static void F_78 ( struct V_1 * V_8 ,
struct V_57 * V_16 [] , int V_124 ,
struct V_57 * V_172 )
{
struct V_173 * V_174 = & V_172 -> V_137 ;
struct V_175 * V_176 = & V_174 -> V_177 [ 0 ] ;
int V_51 , V_143 ;
int V_178 = F_79 ( V_174 -> V_179 ) +
F_79 ( V_174 -> V_180 ) ;
int V_181 = F_79 ( V_174 -> V_182 ) *
F_79 ( V_174 -> V_183 ) *
V_178 ;
int V_184 = F_79 ( V_174 -> V_183 ) *
V_178 ;
int V_185 ;
if ( V_181 > V_186 )
V_181 = V_186 ;
V_185 = 0 ;
for ( V_51 = 0 ; V_51 < V_181 ; V_51 ++ ) {
V_172 -> V_187 [ V_51 ] = NULL ;
if ( ! V_172 -> V_136 )
continue;
for ( V_143 = 0 ; V_143 < V_124 ; V_143 ++ ) {
if ( V_16 [ V_143 ] -> V_133 != V_188 )
continue;
if ( F_23 ( V_16 [ V_143 ] -> V_54 ) )
continue;
if ( V_16 [ V_143 ] -> V_138 != V_176 [ V_51 ] . V_138 )
continue;
V_172 -> V_187 [ V_51 ] = V_16 [ V_143 ] ;
if ( V_51 < V_184 )
V_185 = F_80 ( V_8 -> V_189 , V_185 +
V_172 -> V_187 [ V_51 ] -> V_140 ) ;
break;
}
if ( ! V_172 -> V_187 [ V_51 ] ) {
V_172 -> V_70 = 0 ;
V_172 -> V_140 = V_8 -> V_189 ;
}
}
if ( V_181 )
V_172 -> V_140 = V_185 ;
else
V_172 -> V_140 = V_8 -> V_189 ;
}
static void F_81 ( struct V_1 * V_8 ,
struct V_57 * V_16 [] , int V_124 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_124 ; V_51 ++ ) {
if ( V_16 [ V_51 ] -> V_133 != V_188 )
continue;
if ( ! F_23 ( V_16 [ V_51 ] -> V_54 ) )
continue;
F_78 ( V_8 , V_16 , V_124 , V_16 [ V_51 ] ) ;
}
}
static void F_82 ( struct V_1 * V_8 , int V_125 ,
struct V_57 * V_131 [] , int V_190 )
{
int V_51 , V_134 , V_191 , V_192 = 0 ;
struct V_57 * V_193 ;
unsigned long V_59 ;
struct V_57 * * V_126 , * * V_141 ;
int V_127 , V_142 ;
struct V_6 * V_7 = NULL ;
V_126 = F_83 ( sizeof( * V_126 ) * V_123 , V_155 ) ;
V_141 = F_83 ( sizeof( * V_141 ) * V_123 , V_155 ) ;
if ( ! V_126 || ! V_141 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_49
L_50 ) ;
goto V_194;
}
F_26 ( & V_8 -> V_195 , V_59 ) ;
V_51 = 0 ;
V_142 = 0 ;
V_127 = 0 ;
while ( V_51 < V_8 -> V_124 ) {
V_193 = V_8 -> V_16 [ V_51 ] ;
V_191 = F_67 ( V_193 , V_131 , V_190 , & V_134 ) ;
if ( V_191 == F_68 ) {
V_192 ++ ;
F_62 ( V_8 , V_125 , V_51 ,
V_141 , & V_142 ) ;
continue;
} else if ( V_191 == F_69 ) {
V_192 ++ ;
F_61 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ,
V_126 , & V_127 , V_141 , & V_142 ) ;
V_131 [ V_134 ] = NULL ;
} else if ( V_191 == F_71 ) {
F_58 ( V_8 , V_125 , V_51 , V_131 [ V_134 ] ) ;
}
V_51 ++ ;
}
for ( V_51 = 0 ; V_51 < V_190 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_152 ) {
F_77 ( V_8 , V_131 [ V_51 ] ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_51 ,
V_8 -> V_44 -> V_160 ,
V_131 [ V_51 ] -> V_118 , V_131 [ V_51 ] -> V_119 , V_131 [ V_51 ] -> V_120 ) ;
continue;
}
V_191 = F_67 ( V_131 [ V_51 ] , V_8 -> V_16 ,
V_8 -> V_124 , & V_134 ) ;
if ( V_191 == F_68 ) {
V_192 ++ ;
if ( F_54 ( V_8 , V_125 , V_131 [ V_51 ] ,
V_126 , & V_127 ) != 0 )
break;
V_131 [ V_51 ] = NULL ;
} else if ( V_191 == F_69 ) {
V_192 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_52 ) ;
}
}
F_27 ( & V_8 -> V_195 , V_59 ) ;
for ( V_51 = 0 ; V_51 < V_190 ; V_51 ++ ) {
if ( ! V_131 [ V_51 ] )
continue;
if ( V_131 [ V_51 ] -> V_152 )
F_73 ( V_8 , V_131 [ V_51 ] -> V_54 ) ;
}
if ( V_125 == - 1 || ! V_192 )
goto V_194;
V_7 = V_8 -> V_44 ;
for ( V_51 = 0 ; V_51 < V_142 ; V_51 ++ ) {
struct V_2 * V_3 =
F_84 ( V_7 , V_141 [ V_51 ] -> V_118 ,
V_141 [ V_51 ] -> V_119 , V_141 [ V_51 ] -> V_120 ) ;
if ( V_3 != NULL ) {
F_85 ( V_3 ) ;
F_86 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_53
L_54 , V_125 , V_141 [ V_51 ] -> V_118 ,
V_141 [ V_51 ] -> V_119 , V_141 [ V_51 ] -> V_120 ) ;
}
F_64 ( V_141 [ V_51 ] ) ;
V_141 [ V_51 ] = NULL ;
}
for ( V_51 = 0 ; V_51 < V_127 ; V_51 ++ ) {
if ( F_87 ( V_7 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_55
L_56 , V_125 , V_126 [ V_51 ] -> V_118 ,
V_126 [ V_51 ] -> V_119 , V_126 [ V_51 ] -> V_120 ) ;
F_63 ( V_8 , V_126 [ V_51 ] ) ;
}
V_194:
F_64 ( V_126 ) ;
F_64 ( V_141 ) ;
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
F_26 ( & V_8 -> V_195 , V_59 ) ;
V_131 = F_88 ( V_8 , F_90 ( V_3 ) ,
F_91 ( V_3 ) , V_3 -> V_120 ) ;
if ( V_131 != NULL ) {
V_3 -> V_61 = V_131 ;
if ( V_131 -> V_140 )
F_92 ( V_3 , V_131 -> V_140 ) ;
F_93 ( & V_131 -> V_196 , 0 ) ;
}
F_27 ( & V_8 -> V_195 , V_59 ) ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
}
static void F_95 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_197 )
return;
for ( V_51 = 0 ; V_51 < V_8 -> V_189 ; V_51 ++ ) {
F_64 ( V_8 -> V_197 [ V_51 ] ) ;
V_8 -> V_197 [ V_51 ] = NULL ;
}
F_64 ( V_8 -> V_197 ) ;
V_8 -> V_197 = NULL ;
}
static int F_96 ( struct V_1 * V_8 )
{
int V_51 ;
if ( V_8 -> V_198 <= 0 )
return 0 ;
V_8 -> V_197 = F_83 ( sizeof( * V_8 -> V_197 ) * V_8 -> V_189 ,
V_155 ) ;
if ( ! V_8 -> V_197 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_57 ) ;
return - V_199 ;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_189 ; V_51 ++ ) {
V_8 -> V_197 [ V_51 ] = F_75 ( sizeof( * V_8 -> V_197 [ V_51 ] ) *
V_8 -> V_198 , V_155 ) ;
if ( ! V_8 -> V_197 [ V_51 ] ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_58 ) ;
goto V_200;
}
}
return 0 ;
V_200:
F_95 ( V_8 ) ;
return - V_199 ;
}
static int F_97 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_201 * V_202 , * V_203 ;
T_5 V_204 ;
T_3 V_205 ;
V_202 = & V_10 -> V_206 [ V_8 -> V_207 - 1 ] ;
V_203 = V_8 -> V_197 [ V_10 -> V_94 ] ;
V_202 -> V_208 = F_98 ( V_209 ) ;
V_205 = sizeof( * V_202 ) *
( F_79 ( V_10 -> V_86 . V_210 ) - V_8 -> V_207 ) ;
V_202 -> V_211 = F_98 ( V_205 ) ;
V_204 = F_99 ( V_8 -> V_15 , V_203 , V_205 ,
V_212 ) ;
if ( F_100 ( & V_8 -> V_15 -> V_16 , V_204 ) ) {
V_202 -> V_213 = F_101 ( 0 ) ;
return - 1 ;
}
V_202 -> V_213 = F_101 ( V_204 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_201 * V_202 ;
if ( F_79 ( V_10 -> V_86 . V_210 ) <= V_8 -> V_207 )
return;
V_202 = & V_10 -> V_206 [ V_8 -> V_207 - 1 ] ;
F_103 ( V_8 -> V_15 , F_104 ( V_202 -> V_213 ) ,
F_105 ( V_202 -> V_211 ) , V_212 ) ;
}
static int F_106 ( struct V_1 * V_8 ,
struct V_9 * V_10 ,
struct V_214 * V_215 ,
struct V_97 * V_216 )
{
int V_217 ;
int V_218 = 0 ;
switch ( V_216 -> V_219 . V_220 ) {
case V_221 :
switch ( V_216 -> V_219 . V_33 ) {
case V_222 :
break;
case V_223 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_59 ,
L_60 ) ;
V_215 -> V_224 |= V_225 ;
if ( V_216 -> V_219 . V_226 !=
V_227 ) {
memset ( V_215 -> V_228 , 0 ,
V_229 ) ;
break;
}
V_217 = V_216 -> V_219 . V_230 ;
if ( V_217 > V_229 )
V_217 = V_229 ;
if ( V_217 > sizeof( V_216 -> V_219 . V_231 ) )
V_217 =
sizeof( V_216 -> V_219 . V_231 ) ;
memcpy ( V_215 -> V_228 ,
V_216 -> V_219 . V_231 , V_217 ) ;
V_218 = 1 ;
break;
case V_232 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_61 ,
L_60 ) ;
V_218 = 1 ;
break;
case V_233 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_62 ,
L_60 ) ;
V_218 = 1 ;
break;
case V_234 :
V_215 -> V_224 = V_235 << 16 ;
break;
case V_236 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_63 ,
L_60 ) ;
V_218 = 1 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_64 ,
L_60 , V_216 -> V_219 . V_33 ) ;
V_218 = 1 ;
break;
}
break;
case V_237 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_65 ,
V_216 -> V_219 . V_33 ) ;
V_218 = 1 ;
break;
case V_238 :
break;
case V_239 :
break;
case V_240 :
F_5 ( & V_8 -> V_15 -> V_16 , L_66 ) ;
V_218 = 1 ;
break;
case V_241 :
F_5 ( & V_8 -> V_15 -> V_16 , L_67 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_68 ,
L_60 ,
V_216 -> V_219 . V_220 ) ;
V_218 = 1 ;
break;
}
return V_218 ;
}
static void F_107 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_214 * V_215 ,
struct V_57 * V_16 )
{
struct V_97 * V_216 = & V_8 -> V_98 [ V_10 -> V_94 ] ;
if ( F_35 ( V_216 -> V_219 . V_220 == 0 &&
V_216 -> V_219 . V_33 == 0 ) ) {
F_108 ( V_8 , V_10 ) ;
V_215 -> V_242 ( V_215 ) ;
return;
}
if ( F_23 ( V_16 -> V_54 ) &&
V_216 -> V_219 . V_220 ==
V_237 ) {
if ( V_216 -> V_219 . V_33 ==
V_243 )
V_16 -> V_70 = 0 ;
goto V_244;
}
if ( F_106 ( V_8 , V_10 , V_215 , V_216 ) )
goto V_244;
F_108 ( V_8 , V_10 ) ;
V_215 -> V_242 ( V_215 ) ;
return;
V_244:
F_109 ( & V_10 -> V_245 , V_246 ) ;
F_110 ( F_36 () , V_8 -> V_247 , & V_10 -> V_245 ) ;
}
static void F_111 ( struct V_9 * V_92 )
{
struct V_214 * V_215 ;
struct V_1 * V_8 ;
struct V_248 * V_249 ;
struct V_57 * V_16 ;
unsigned char V_250 ;
unsigned char V_251 ;
unsigned char V_252 ;
unsigned long V_253 ;
V_249 = V_92 -> V_11 ;
V_215 = V_92 -> V_254 ;
V_8 = V_92 -> V_8 ;
V_16 = V_215 -> V_28 -> V_61 ;
F_112 ( V_215 ) ;
if ( ( V_92 -> V_110 == V_255 ) &&
( F_79 ( V_92 -> V_86 . V_210 ) > V_8 -> V_207 ) )
F_102 ( V_8 , V_92 ) ;
V_215 -> V_224 = ( V_256 << 16 ) ;
V_215 -> V_224 |= ( V_257 << 8 ) ;
if ( V_92 -> V_110 == V_114 || V_92 -> V_110 == V_111 )
F_33 ( & V_92 -> V_187 -> V_196 ) ;
if ( V_92 -> V_110 == V_114 )
return F_107 ( V_8 , V_92 , V_215 , V_16 ) ;
V_215 -> V_224 |= V_249 -> V_25 ;
F_113 ( V_215 , V_249 -> V_258 ) ;
if ( V_249 -> V_23 == 0 ) {
if ( V_92 -> V_110 == V_111 )
F_33 ( & V_92 -> V_187 -> V_196 ) ;
F_108 ( V_8 , V_92 ) ;
V_215 -> V_242 ( V_215 ) ;
return;
}
if ( V_229 < sizeof( V_249 -> V_12 ) )
V_253 = V_229 ;
else
V_253 = sizeof( V_249 -> V_12 ) ;
if ( V_249 -> V_259 < V_253 )
V_253 = V_249 -> V_259 ;
memcpy ( V_215 -> V_228 , V_249 -> V_12 , V_253 ) ;
if ( V_92 -> V_110 == V_111 ) {
struct V_91 * V_10 = & V_8 -> V_93 [ V_92 -> V_94 ] ;
V_92 -> V_86 . V_87 = F_114 ( V_215 ) ;
V_92 -> V_86 . V_210 = F_115 ( V_92 -> V_86 . V_87 ) ;
V_92 -> V_104 . V_260 = F_79 ( V_10 -> V_261 ) &
V_262 ;
V_92 -> V_86 . V_263 = V_10 -> V_263 ;
memcpy ( V_92 -> V_86 . V_264 . V_265 , V_10 -> V_266 , 8 ) ;
memcpy ( V_92 -> V_104 . V_105 , V_10 -> V_105 , V_92 -> V_104 . V_260 ) ;
if ( F_23 ( V_16 -> V_54 ) ) {
if ( V_249 -> V_23 == V_267 )
V_16 -> V_70 = 0 ;
F_109 ( & V_92 -> V_245 , V_246 ) ;
F_110 ( F_36 () ,
V_8 -> V_247 , & V_92 -> V_245 ) ;
return;
}
}
switch ( V_249 -> V_23 ) {
case V_24 :
if ( V_249 -> V_25 ) {
V_250 = 0xf & V_249 -> V_12 [ 2 ] ;
V_251 = V_249 -> V_12 [ 12 ] ;
V_252 = V_249 -> V_12 [ 13 ] ;
}
if ( V_249 -> V_25 == V_225 ) {
if ( V_250 == V_268 ) {
V_215 -> V_224 |= V_269 << 16 ;
break;
}
break;
}
if ( V_249 -> V_25 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_69
L_70
L_71 ,
V_92 , V_249 -> V_25 ,
V_250 , V_251 , V_252 ,
V_215 -> V_224 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_72
L_73 , V_92 ) ,
V_215 -> V_224 = V_270 << 16 ;
}
break;
case V_271 :
break;
case V_272 :
F_5 ( & V_8 -> V_15 -> V_16 ,
L_74 , V_92 -> V_104 . V_105 ) ;
break;
case V_273 : {
V_215 -> V_224 = V_270 << 16 ;
}
break;
case V_274 :
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_75 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_276 :
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_76 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_277 :
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_77 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_278 :
V_215 -> V_224 = V_279 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_78 ,
V_92 -> V_104 . V_105 , V_249 -> V_25 ) ;
break;
case V_280 :
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_79 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_281 :
V_215 -> V_224 = V_269 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_80 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_282 :
V_215 -> V_224 = V_283 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_81 ,
V_92 -> V_104 . V_105 ) ;
break;
case V_284 :
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_82 ) ;
break;
case V_267 :
V_215 -> V_224 = V_269 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_83 , V_92 ) ;
break;
default:
V_215 -> V_224 = V_275 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_84 ,
V_92 , V_249 -> V_23 ) ;
}
F_108 ( V_8 , V_92 ) ;
V_215 -> V_242 ( V_215 ) ;
}
static void F_116 ( struct V_285 * V_15 ,
struct V_9 * V_10 , int V_286 , int V_287 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_286 ; V_51 ++ )
F_103 ( V_15 , ( V_288 ) F_104 ( V_10 -> V_206 [ V_51 ] . V_213 ) ,
F_105 ( V_10 -> V_206 [ V_51 ] . V_211 ) ,
V_287 ) ;
}
static int F_117 ( struct V_285 * V_15 ,
struct V_9 * V_92 ,
unsigned char * V_31 ,
T_2 V_289 ,
int V_287 )
{
T_5 V_290 ;
if ( V_289 == 0 || V_287 == V_291 ) {
V_92 -> V_86 . V_87 = 0 ;
V_92 -> V_86 . V_210 = F_115 ( 0 ) ;
return 0 ;
}
V_290 = F_99 ( V_15 , V_31 , V_289 , V_287 ) ;
if ( F_100 ( & V_15 -> V_16 , V_290 ) ) {
V_92 -> V_86 . V_87 = 0 ;
V_92 -> V_86 . V_210 = F_115 ( 0 ) ;
return - 1 ;
}
V_92 -> V_206 [ 0 ] . V_213 = F_101 ( V_290 ) ;
V_92 -> V_206 [ 0 ] . V_211 = F_98 ( V_289 ) ;
V_92 -> V_206 [ 0 ] . V_208 = F_98 ( V_292 ) ;
V_92 -> V_86 . V_87 = 1 ;
V_92 -> V_86 . V_210 = F_115 ( 1 ) ;
return 0 ;
}
static inline void F_118 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_119 ( V_293 ) ;
V_10 -> V_294 = & V_293 ;
F_45 ( V_8 , V_10 ) ;
F_120 ( & V_293 ) ;
}
static T_3 F_121 ( struct V_1 * V_8 )
{
int V_295 ;
T_3 V_296 , * F_121 ;
V_295 = F_122 () ;
F_121 = F_123 ( V_8 -> F_121 , V_295 ) ;
V_296 = * F_121 ;
F_124 () ;
return V_296 ;
}
static void F_125 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( F_32 ( F_121 ( V_8 ) ) )
V_10 -> V_11 -> V_23 = V_276 ;
else
F_118 ( V_8 , V_10 ) ;
}
static void F_126 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_287 )
{
int V_297 = 10 , V_298 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_118 ( V_8 , V_10 ) ;
V_298 ++ ;
if ( V_298 > 3 ) {
F_127 ( V_297 ) ;
if ( V_297 < 1000 )
V_297 *= 2 ;
}
} while ( ( F_4 ( V_8 , V_10 ) ||
F_6 ( V_8 , V_10 ) ) &&
V_298 <= V_299 );
F_116 ( V_8 -> V_15 , V_10 , 1 , V_287 ) ;
}
static void F_128 ( struct V_1 * V_8 , char * V_300 ,
struct V_9 * V_10 )
{
const T_4 * V_101 = V_10 -> V_104 . V_105 ;
const T_4 * V_120 = V_10 -> V_86 . V_264 . V_265 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_85
L_86 ,
V_300 , V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ,
V_101 [ 0 ] , V_101 [ 1 ] , V_101 [ 2 ] , V_101 [ 3 ] ,
V_101 [ 4 ] , V_101 [ 5 ] , V_101 [ 6 ] , V_101 [ 7 ] ,
V_101 [ 8 ] , V_101 [ 9 ] , V_101 [ 10 ] , V_101 [ 11 ] ,
V_101 [ 12 ] , V_101 [ 13 ] , V_101 [ 14 ] , V_101 [ 15 ] ) ;
}
static void F_129 ( struct V_1 * V_8 ,
struct V_9 * V_92 )
{
const struct V_248 * V_249 = V_92 -> V_11 ;
struct V_28 * V_301 = & V_92 -> V_8 -> V_15 -> V_16 ;
const T_4 * V_131 = V_249 -> V_12 ;
switch ( V_249 -> V_23 ) {
case V_24 :
F_128 ( V_8 , L_87 , V_92 ) ;
if ( V_249 -> V_25 == V_225 )
F_5 ( V_301 , L_88 ,
V_131 [ 2 ] & 0x0f , V_131 [ 12 ] , V_131 [ 13 ] ) ;
else
F_5 ( V_301 , L_89 , V_249 -> V_25 ) ;
if ( V_249 -> V_25 == 0 )
F_5 ( V_301 , L_90
L_91
L_92
L_93 ) ;
break;
case V_271 :
break;
case V_272 :
F_128 ( V_8 , L_94 , V_92 ) ;
break;
case V_273 : {
F_128 ( V_8 , L_95 , V_92 ) ;
F_5 ( V_301 , L_96 ) ;
}
break;
case V_274 :
F_128 ( V_8 , L_97 , V_92 ) ;
break;
case V_276 :
F_128 ( V_8 , L_98 , V_92 ) ;
break;
case V_277 :
F_128 ( V_8 , L_99 , V_92 ) ;
break;
case V_278 :
F_128 ( V_8 , L_100 , V_92 ) ;
break;
case V_280 :
F_128 ( V_8 , L_101 , V_92 ) ;
break;
case V_281 :
F_128 ( V_8 , L_102 , V_92 ) ;
break;
case V_282 :
F_128 ( V_8 , L_103 , V_92 ) ;
break;
case V_284 :
F_128 ( V_8 , L_104 , V_92 ) ;
break;
default:
F_128 ( V_8 , L_105 , V_92 ) ;
F_5 ( V_301 , L_106 ,
V_249 -> V_23 ) ;
}
}
static int F_130 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_6 V_302 , unsigned char * V_31 ,
unsigned char V_303 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - V_199 ;
}
if ( F_132 ( V_10 , V_305 , V_8 , V_31 , V_303 ,
V_302 , V_54 , V_306 ) ) {
V_296 = - 1 ;
goto V_307;
}
F_126 ( V_8 , V_10 , V_308 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 && V_249 -> V_23 != V_271 ) {
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
}
V_307:
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static int F_133 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char V_302 ,
struct V_309 * V_31 , T_2 V_303 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - V_199 ;
}
if ( F_132 ( V_10 , V_310 , V_8 , V_31 , V_303 ,
V_302 , V_54 , V_306 ) ) {
V_296 = - 1 ;
goto V_307;
}
F_126 ( V_8 , V_10 , V_308 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 && V_249 -> V_23 != V_271 ) {
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
}
V_307:
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static int F_134 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_311 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - V_199 ;
}
( void ) F_132 ( V_10 , V_312 , V_8 , NULL , 0 , 0 ,
V_54 , V_313 ) ;
V_10 -> V_104 . V_105 [ 1 ] = V_311 ;
F_118 ( V_8 , V_10 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 ) {
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
}
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static void F_135 ( struct V_1 * V_8 ,
unsigned char * V_54 , unsigned char * V_64 )
{
int V_296 ;
unsigned char * V_31 ;
* V_64 = V_65 ;
V_31 = F_83 ( 64 , V_155 ) ;
if ( ! V_31 )
return;
V_296 = F_130 ( V_8 , V_54 , V_314 | 0xC1 , V_31 , 64 ) ;
if ( V_296 == 0 )
* V_64 = V_31 [ 8 ] ;
if ( * V_64 > V_65 )
* V_64 = V_65 ;
F_64 ( V_31 ) ;
return;
}
static void F_136 ( struct V_1 * V_8 , int V_296 ,
struct V_173 * V_315 )
{
struct V_175 * V_176 = & V_315 -> V_177 [ 0 ] ;
int V_174 , V_316 , V_317 ;
T_6 V_318 , V_182 , V_319 ;
if ( V_296 != 0 )
return;
if ( V_8 -> V_43 < 2 )
return;
F_56 ( & V_8 -> V_15 -> V_16 , L_108 ,
F_105 ( V_315 -> V_320 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_109 ,
F_105 ( V_315 -> V_321 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_110 ,
F_104 ( V_315 -> V_322 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_111 ,
V_315 -> V_323 ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_112 ,
V_315 -> V_324 ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_113 ,
F_79 ( V_315 -> V_325 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_114 ,
F_104 ( V_315 -> V_326 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_115 ,
F_104 ( V_315 -> V_327 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_116 ,
F_79 ( V_315 -> V_179 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_117 ,
F_79 ( V_315 -> V_180 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_118 ,
F_79 ( V_315 -> V_182 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_119 ,
F_79 ( V_315 -> V_183 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_120 ,
F_79 ( V_315 -> V_59 ) ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_121 ,
F_79 ( V_315 -> V_59 ) &
V_328 ? L_122 : L_123 ) ;
F_56 ( & V_8 -> V_15 -> V_16 , L_124 ,
F_79 ( V_315 -> V_329 ) ) ;
V_318 = F_79 ( V_315 -> V_183 ) ;
for ( V_174 = 0 ; V_174 < V_318 ; V_174 ++ ) {
F_56 ( & V_8 -> V_15 -> V_16 , L_125 , V_174 ) ;
V_182 = F_79 ( V_315 -> V_182 ) ;
for ( V_316 = 0 ; V_316 < V_182 ; V_316 ++ ) {
F_56 ( & V_8 -> V_15 -> V_16 , L_126 , V_316 ) ;
V_319 =
F_79 ( V_315 -> V_179 ) ;
for ( V_317 = 0 ; V_317 < V_319 ; V_317 ++ , V_176 ++ )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_127 ,
V_317 , V_176 -> V_138 ,
V_176 -> V_330 [ 0 ] , V_176 -> V_330 [ 1 ] ) ;
V_319 =
F_79 ( V_315 -> V_180 ) ;
for ( V_317 = 0 ; V_317 < V_319 ; V_317 ++ , V_176 ++ )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_128 ,
V_317 , V_176 -> V_138 ,
V_176 -> V_330 [ 0 ] , V_176 -> V_330 [ 1 ] ) ;
}
}
}
static int F_137 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_331 )
{
int V_296 = 0 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - V_199 ;
}
if ( F_132 ( V_10 , V_332 , V_8 , & V_331 -> V_137 ,
sizeof( V_331 -> V_137 ) , 0 ,
V_54 , V_306 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_129 ) ;
F_108 ( V_8 , V_10 ) ;
return - V_199 ;
}
F_126 ( V_8 , V_10 , V_308 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 && V_249 -> V_23 != V_271 ) {
F_129 ( V_8 , V_10 ) ;
F_108 ( V_8 , V_10 ) ;
return - 1 ;
}
F_108 ( V_8 , V_10 ) ;
if ( F_105 ( V_331 -> V_137 . V_320 ) >
sizeof( V_331 -> V_137 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_130 ) ;
V_296 = - 1 ;
}
F_136 ( V_8 , V_296 , & V_331 -> V_137 ) ;
return V_296 ;
}
static int F_138 ( struct V_1 * V_8 ,
unsigned char V_54 [] , T_6 V_333 ,
struct V_334 * V_31 , T_2 V_303 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
V_296 = F_132 ( V_10 , V_335 , V_8 , V_31 , V_303 ,
0 , V_117 , V_306 ) ;
if ( V_296 )
goto V_307;
V_10 -> V_104 . V_105 [ 2 ] = V_333 & 0xff ;
V_10 -> V_104 . V_105 [ 9 ] = ( V_333 >> 8 ) & 0xff ;
F_126 ( V_8 , V_10 , V_308 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 && V_249 -> V_23 != V_271 ) {
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
}
V_307:
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static int F_139 ( struct V_1 * V_8 ,
unsigned char V_54 [] , T_4 V_302 )
{
int V_296 ;
int V_51 ;
int V_336 ;
unsigned char * V_31 , V_303 ;
V_31 = F_83 ( 256 , V_155 ) ;
if ( ! V_31 )
return 0 ;
V_296 = F_130 ( V_8 , V_54 ,
V_314 | V_337 ,
V_31 , V_338 ) ;
if ( V_296 != 0 )
goto V_339;
V_336 = V_31 [ 3 ] ;
if ( ( V_336 + V_338 ) <= 255 )
V_303 = V_336 + V_338 ;
else
V_303 = 255 ;
V_296 = F_130 ( V_8 , V_54 ,
V_314 | V_337 ,
V_31 , V_303 ) ;
if ( V_296 != 0 )
goto V_339;
V_336 = V_31 [ 3 ] ;
for ( V_51 = 1 ; V_51 <= V_336 ; V_51 ++ )
if ( V_31 [ 3 + V_51 ] == V_302 )
goto V_340;
V_339:
F_64 ( V_31 ) ;
return 0 ;
V_340:
F_64 ( V_31 ) ;
return 1 ;
}
static void F_140 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_57 * V_331 )
{
int V_296 ;
unsigned char * V_31 ;
T_4 V_341 ;
V_331 -> V_136 = 0 ;
V_331 -> V_70 = 0 ;
V_31 = F_83 ( 64 , V_155 ) ;
if ( ! V_31 )
return;
if ( ! F_139 ( V_8 , V_54 , V_342 ) )
goto V_307;
V_296 = F_130 ( V_8 , V_54 ,
V_314 | V_342 , V_31 , 64 ) ;
if ( V_296 != 0 )
goto V_307;
#define F_141 4
#define F_142 0x01
#define F_143 0x02
V_341 = V_31 [ F_141 ] ;
V_331 -> V_136 =
! ! ( V_341 & F_142 ) ;
if ( V_331 -> V_136 ) {
V_331 -> V_70 =
! ! ( V_341 & F_143 ) ;
if ( F_137 ( V_8 , V_54 , V_331 ) )
V_331 -> V_70 = 0 ;
}
V_307:
F_64 ( V_31 ) ;
return;
}
static int F_144 ( struct V_1 * V_8 , unsigned char * V_54 ,
unsigned char * V_69 , int V_289 )
{
int V_296 ;
unsigned char * V_31 ;
if ( V_289 > 16 )
V_289 = 16 ;
V_31 = F_83 ( 64 , V_155 ) ;
if ( ! V_31 )
return - V_199 ;
V_296 = F_130 ( V_8 , V_54 , V_314 | 0x83 , V_31 , 64 ) ;
if ( V_296 == 0 )
memcpy ( V_69 , & V_31 [ 8 ] , V_289 ) ;
F_64 ( V_31 ) ;
return V_296 != 0 ;
}
static int F_145 ( struct V_1 * V_8 , int V_343 ,
void * V_31 , int V_303 ,
int V_344 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
unsigned char V_54 [ 8 ] ;
struct V_248 * V_249 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - 1 ;
}
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
if ( F_132 ( V_10 , V_343 ? V_345 : V_346 , V_8 ,
V_31 , V_303 , 0 , V_54 , V_306 ) ) {
V_296 = - 1 ;
goto V_307;
}
if ( V_344 )
V_10 -> V_104 . V_105 [ 1 ] = V_344 ;
F_126 ( V_8 , V_10 , V_308 ) ;
V_249 = V_10 -> V_11 ;
if ( V_249 -> V_23 != 0 &&
V_249 -> V_23 != V_271 ) {
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
} else {
struct V_347 * V_348 = V_31 ;
if ( V_348 -> V_349 != V_344 ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_131 ,
V_344 ,
V_348 -> V_349 ) ;
V_296 = - 1 ;
}
}
V_307:
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static inline int F_146 ( struct V_1 * V_8 ,
struct V_350 * V_31 , int V_303 )
{
return F_145 ( V_8 , 0 , V_31 , V_303 ,
V_351 ) ;
}
static inline int F_147 ( struct V_1 * V_8 ,
struct V_347 * V_31 , int V_303 )
{
return F_145 ( V_8 , 1 , V_31 , V_303 , 0 ) ;
}
static inline void F_148 ( struct V_57 * V_28 ,
int V_118 , int V_119 , int V_120 )
{
V_28 -> V_118 = V_118 ;
V_28 -> V_119 = V_119 ;
V_28 -> V_120 = V_120 ;
}
static int F_149 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
int V_296 ;
int V_33 ;
int V_352 ;
unsigned char * V_31 ;
V_31 = F_83 ( 64 , V_155 ) ;
if ( ! V_31 )
return V_159 ;
if ( ! F_139 ( V_8 , V_54 , V_353 ) )
goto V_354;
V_296 = F_130 ( V_8 , V_54 , V_314 | V_353 ,
V_31 , V_338 ) ;
if ( V_296 != 0 )
goto V_354;
V_352 = V_31 [ 3 ] ;
V_296 = F_130 ( V_8 , V_54 , V_314 | V_353 ,
V_31 , V_352 + V_338 ) ;
if ( V_296 != 0 )
goto V_354;
V_33 = V_31 [ 4 ] ;
F_64 ( V_31 ) ;
return V_33 ;
V_354:
F_64 ( V_31 ) ;
return V_159 ;
}
static int F_150 ( struct V_1 * V_8 ,
unsigned char V_54 [] )
{
struct V_9 * V_10 ;
unsigned char * V_355 , V_250 , V_251 , V_252 ;
int V_356 = 0 ;
T_6 V_357 ;
T_4 V_358 ;
#define F_151 0x04
#define F_152 0x04
#define F_153 0x02
V_10 = F_131 ( V_8 ) ;
if ( ! V_10 )
return 0 ;
( void ) F_132 ( V_10 , V_359 , V_8 , NULL , 0 , 0 , V_54 , V_306 ) ;
F_118 ( V_8 , V_10 ) ;
V_355 = V_10 -> V_11 -> V_12 ;
V_250 = V_355 [ 2 ] ;
V_251 = V_355 [ 12 ] ;
V_252 = V_355 [ 13 ] ;
V_357 = V_10 -> V_11 -> V_23 ;
V_358 = V_10 -> V_11 -> V_25 ;
F_108 ( V_8 , V_10 ) ;
if ( V_357 != V_24 ||
V_358 != V_225 ||
V_250 != V_360 ||
V_251 != F_151 ) {
return 0 ;
}
V_356 = F_149 ( V_8 , V_54 ) ;
switch ( V_356 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
return V_356 ;
case V_159 :
if ( ( V_252 == F_152 ) ||
( V_252 == F_153 ) )
return V_356 ;
break;
default:
break;
}
return 0 ;
}
static int F_154 ( struct V_1 * V_8 ,
unsigned char V_54 [] , struct V_57 * V_331 ,
unsigned char * V_361 )
{
#define F_155 43
#define F_156 "$DR-10"
#define F_157 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_158 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_362 ;
unsigned char * V_363 ;
V_362 = F_83 ( F_158 , V_155 ) ;
if ( ! V_362 )
goto V_364;
if ( F_130 ( V_8 , V_54 , 0 , V_362 ,
( unsigned char ) F_158 ) != 0 ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_132 ) ;
goto V_364;
}
V_331 -> V_133 = ( V_362 [ 0 ] & 0x1f ) ;
memcpy ( V_331 -> V_54 , V_54 , 8 ) ;
memcpy ( V_331 -> V_147 , & V_362 [ 8 ] ,
sizeof( V_331 -> V_147 ) ) ;
memcpy ( V_331 -> V_146 , & V_362 [ 16 ] ,
sizeof( V_331 -> V_146 ) ) ;
memset ( V_331 -> V_69 , 0 ,
sizeof( V_331 -> V_69 ) ) ;
F_144 ( V_8 , V_54 , V_331 -> V_69 ,
sizeof( V_331 -> V_69 ) ) ;
if ( V_331 -> V_133 == V_188 &&
F_23 ( V_54 ) ) {
int V_152 ;
F_135 ( V_8 , V_54 , & V_331 -> V_64 ) ;
if ( V_8 -> V_365 & V_366 )
F_140 ( V_8 , V_54 , V_331 ) ;
V_152 = F_150 ( V_8 , V_54 ) ;
if ( V_152 < 0 || V_152 > 0xff )
V_152 = V_159 ;
V_331 -> V_152 = V_152 & 0xff ;
} else {
V_331 -> V_64 = V_65 ;
V_331 -> V_136 = 0 ;
V_331 -> V_70 = 0 ;
V_331 -> V_152 = 0 ;
V_331 -> V_140 = V_8 -> V_189 ;
}
if ( V_361 ) {
V_363 = & V_362 [ F_155 ] ;
* V_361 = ( V_331 -> V_133 == V_367 &&
strncmp ( V_363 , F_156 ,
F_157 ) == 0 ) ;
}
F_64 ( V_362 ) ;
return 0 ;
V_364:
F_64 ( V_362 ) ;
return 1 ;
}
static int F_159 ( struct V_1 * V_8 , struct V_57 * V_28 )
{
int V_51 ;
for ( V_51 = 0 ; V_368 [ V_51 ] ; V_51 ++ )
if ( strncmp ( V_28 -> V_146 , V_368 [ V_51 ] ,
strlen ( V_368 [ V_51 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_160 ( struct V_1 * V_8 ,
T_4 * V_369 , struct V_57 * V_28 )
{
T_3 V_67 = F_105 ( * ( ( V_370 * ) V_369 ) ) ;
if ( ! F_23 ( V_369 ) ) {
if ( F_47 ( V_369 ) )
F_148 ( V_28 , 3 , 0 , V_67 & 0x3fff ) ;
else
F_148 ( V_28 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_159 ( V_8 , V_28 ) ) {
F_148 ( V_28 ,
1 , ( V_67 >> 16 ) & 0x3fff , V_67 & 0x00ff ) ;
return;
}
F_148 ( V_28 , 0 , 0 , V_67 & 0x3fff ) ;
}
static int F_161 ( struct V_1 * V_8 ,
struct V_57 * V_371 ,
struct V_57 * V_331 , T_4 * V_369 ,
unsigned long V_372 [] , int * V_373 )
{
unsigned char V_54 [ 8 ] ;
if ( F_162 ( V_371 -> V_119 , V_372 ) )
return 0 ;
if ( ! F_23 ( V_369 ) )
return 0 ;
if ( ! F_159 ( V_8 , V_371 ) )
return 0 ;
if ( V_371 -> V_120 == 0 )
return 0 ;
memset ( V_54 , 0 , 8 ) ;
V_54 [ 3 ] = V_371 -> V_119 ;
if ( F_47 ( V_54 ) )
return 0 ;
if ( F_48 ( V_8 ) )
return 0 ;
if ( * V_373 >= V_374 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_133
L_134
L_135 ) ;
return 0 ;
}
if ( F_154 ( V_8 , V_54 , V_331 , NULL ) )
return 0 ;
( * V_373 ) ++ ;
F_148 ( V_331 ,
V_371 -> V_118 , V_371 -> V_119 , 0 ) ;
F_163 ( V_371 -> V_119 , V_372 ) ;
return 1 ;
}
static int F_164 ( struct V_1 * V_8 ,
struct V_9 * V_375 , unsigned char * V_54 )
{
struct V_350 * V_376 = NULL ;
int V_377 = 24 ;
int V_378 = sizeof( * V_376 ) + V_379 * V_377 ;
T_3 V_380 = 0 ;
int V_121 = 0 ;
T_3 V_381 ;
int V_51 ;
struct V_214 * V_382 ;
struct V_57 * V_301 ;
struct V_97 * V_383 ;
V_370 V_384 ;
V_370 V_385 ;
if ( V_375 -> V_110 != V_114 )
return 0 ;
V_383 = & V_8 -> V_98 [ V_375 -> V_94 ] ;
if ( V_383 == NULL )
return 0 ;
V_382 = (struct V_214 * ) V_375 -> V_254 ;
if ( V_382 == NULL )
return 0 ;
V_301 = V_382 -> V_28 -> V_61 ;
if ( V_301 == NULL )
return 0 ;
V_384 = F_98 ( V_301 -> V_138 ) ;
V_385 = V_383 -> V_385 ;
V_381 = F_105 ( V_383 -> V_385 ) ;
if ( V_8 -> V_43 > 0 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_136 ,
V_156 , V_385 ,
V_301 -> V_69 [ 0 ] , V_301 -> V_69 [ 1 ] , V_301 -> V_69 [ 2 ] ,
V_301 -> V_69 [ 3 ] , V_301 -> V_69 [ 4 ] , V_301 -> V_69 [ 5 ] ,
V_301 -> V_69 [ 6 ] , V_301 -> V_69 [ 7 ] , V_301 -> V_69 [ 8 ] ,
V_301 -> V_69 [ 9 ] , V_301 -> V_69 [ 10 ] , V_301 -> V_69 [ 11 ] ,
V_301 -> V_69 [ 12 ] , V_301 -> V_69 [ 13 ] , V_301 -> V_69 [ 14 ] ,
V_301 -> V_69 [ 15 ] ) ;
V_376 = F_83 ( V_378 , V_155 ) ;
if ( V_376 == NULL )
return 0 ;
if ( F_146 ( V_8 , V_376 , V_378 ) ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_137 ,
L_60 ) ;
F_64 ( V_376 ) ;
return 0 ;
}
V_380 = F_165 ( * ( ( V_386 * ) V_376 -> V_387 ) ) /
V_377 ;
for ( V_51 = 0 ; V_51 < V_380 ; V_51 ++ ) {
struct V_388 * V_134 = & V_376 -> V_264 [ V_51 ] ;
if ( V_134 -> V_138 != V_381 )
continue;
V_121 = 1 ;
memcpy ( V_54 , V_134 -> V_67 , 8 ) ;
if ( V_8 -> V_43 > 0 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_138 ,
V_156 , V_381 ,
V_134 -> V_138 , V_54 ) ;
break;
}
F_64 ( V_376 ) ;
if ( V_121 )
return 1 ;
else
return 0 ;
}
static int F_166 ( struct V_1 * V_8 ,
struct V_350 * V_389 , T_3 * V_380 ,
struct V_347 * V_390 , T_3 * V_391 )
{
if ( F_146 ( V_8 , V_389 , sizeof( * V_389 ) ) ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_139 ) ;
return - 1 ;
}
* V_380 = F_165 ( * ( ( V_386 * ) V_389 -> V_387 ) ) / 24 ;
if ( * V_380 > V_379 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_140 ,
V_379 , * V_380 - V_379 ) ;
* V_380 = V_379 ;
}
if ( F_147 ( V_8 , V_390 , sizeof( * V_390 ) ) ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_141 ) ;
return - 1 ;
}
* V_391 = F_165 ( * ( ( V_386 * ) V_390 -> V_387 ) ) / 8 ;
if ( * V_391 > V_392 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_142
L_143 , V_392 ,
* V_391 - V_392 ) ;
* V_391 = V_392 ;
}
if ( * V_391 + * V_380 > V_379 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_144
L_143 , V_379 ,
* V_380 + * V_391 - V_379 ) ;
* V_391 = V_379 - * V_380 ;
}
return 0 ;
}
static T_4 * F_167 ( struct V_1 * V_8 , int V_393 ,
int V_51 , int V_380 , int V_391 ,
struct V_350 * V_394 ,
struct V_347 * V_395 )
{
int V_396 = V_380 + ( V_393 == 0 ) ;
int V_397 = V_380 + V_391 + ( V_393 == 0 ) ;
if ( V_51 == V_393 )
return V_117 ;
if ( V_51 < V_396 )
return & V_394 -> V_264 [ V_51 -
( V_393 == 0 ) ] . V_67 [ 0 ] ;
if ( V_51 < V_397 )
return & V_395 -> V_264 [ V_51 - V_380 -
( V_393 == 0 ) ] [ 0 ] ;
F_168 () ;
return NULL ;
}
static int F_169 ( struct V_1 * V_8 )
{
int V_296 ;
int V_398 ;
struct V_309 * V_399 ;
V_399 = F_83 ( sizeof( struct V_309 ) ,
V_155 ) ;
if ( ! V_399 )
return - V_199 ;
V_296 = F_133 ( V_8 , V_117 , 0 , V_399 ,
sizeof( struct V_309 ) ) ;
if ( V_296 ) {
F_64 ( V_399 ) ;
return V_296 ;
}
V_398 =
( ( V_399 -> V_400 & V_401 ) != 0 ) ;
F_64 ( V_399 ) ;
return V_398 ;
}
static void F_170 ( struct V_1 * V_8 ,
struct V_57 * V_16 ,
T_4 * V_369 ,
struct V_334 * V_402 )
{
int V_296 ;
struct V_388 * V_403 =
(struct V_388 * ) V_369 ;
V_16 -> V_138 = V_403 -> V_138 ;
memset ( V_402 , 0 , sizeof( * V_402 ) ) ;
V_296 = F_138 ( V_8 , V_369 ,
F_171 ( V_369 ) , V_402 ,
sizeof( * V_402 ) ) ;
if ( ! V_296 )
#define F_172 2
#define F_173 7
V_16 -> V_140 =
F_79 ( V_402 -> V_404 ) -
F_172 ;
else
V_16 -> V_140 = F_173 ;
F_93 ( & V_16 -> V_196 , 0 ) ;
}
static void F_174 ( struct V_1 * V_8 , int V_125 )
{
struct V_350 * V_394 = NULL ;
struct V_347 * V_395 = NULL ;
struct V_334 * V_402 = NULL ;
T_3 V_380 = 0 ;
T_3 V_391 = 0 ;
T_3 V_405 = 0 ;
struct V_57 * * V_406 , * V_331 , * V_371 ;
int V_407 = 0 ;
int V_51 , V_373 , V_408 ;
int V_393 ;
int V_409 ;
F_50 ( V_372 , V_374 ) ;
V_406 = F_83 ( sizeof( * V_406 ) * V_123 , V_155 ) ;
V_394 = F_83 ( sizeof( * V_394 ) , V_155 ) ;
V_395 = F_83 ( sizeof( * V_395 ) , V_155 ) ;
V_371 = F_83 ( sizeof( * V_371 ) , V_155 ) ;
V_402 = F_83 ( sizeof( * V_402 ) , V_155 ) ;
if ( ! V_406 || ! V_394 || ! V_395 ||
! V_371 || ! V_402 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_145 ) ;
goto V_307;
}
memset ( V_372 , 0 , sizeof( V_372 ) ) ;
V_409 = F_169 ( V_8 ) ;
if ( V_409 < 0 )
goto V_307;
if ( ! V_8 -> V_398 && V_409 )
F_5 ( & V_8 -> V_15 -> V_16 , L_146 ) ;
else if ( V_8 -> V_398 && ! V_409 )
F_5 ( & V_8 -> V_15 -> V_16 , L_147 ) ;
V_8 -> V_398 = V_409 ;
if ( F_166 ( V_8 , V_394 , & V_380 ,
V_395 , & V_391 ) )
goto V_307;
V_408 = V_380 + V_391 + V_374 + 1 ;
for ( V_51 = 0 ; V_51 < V_408 ; V_51 ++ ) {
if ( V_51 >= V_123 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_148
L_149 , V_123 ,
V_408 - V_123 ) ;
break;
}
V_406 [ V_51 ] = F_83 ( sizeof( * V_406 [ V_51 ] ) , V_155 ) ;
if ( ! V_406 [ V_51 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_150 ,
__FILE__ , __LINE__ ) ;
goto V_307;
}
V_405 ++ ;
}
if ( F_48 ( V_8 ) )
V_393 = 0 ;
else
V_393 = V_380 + V_391 ;
V_373 = 0 ;
for ( V_51 = 0 ; V_51 < V_380 + V_391 + 1 ; V_51 ++ ) {
T_4 * V_369 , V_410 = 0 ;
V_369 = F_167 ( V_8 , V_393 ,
V_51 , V_380 , V_391 , V_394 , V_395 ) ;
if ( V_369 [ 3 ] & 0xC0 &&
V_51 < V_380 + ( V_393 == 0 ) )
continue;
if ( F_154 ( V_8 , V_369 , V_371 ,
& V_410 ) )
continue;
F_160 ( V_8 , V_369 , V_371 ) ;
V_331 = V_406 [ V_407 ] ;
if ( F_161 ( V_8 , V_371 , V_331 ,
V_369 , V_372 ,
& V_373 ) ) {
V_407 ++ ;
V_331 = V_406 [ V_407 ] ;
}
* V_331 = * V_371 ;
switch ( V_331 -> V_133 ) {
case V_367 :
if ( V_410 )
V_407 ++ ;
break;
case V_188 :
if ( V_8 -> V_398 ) {
V_331 -> V_70 = 0 ;
V_407 ++ ;
break;
} else if ( V_8 -> V_41 ) {
if ( V_51 >= V_380 ) {
V_407 ++ ;
break;
}
} else {
if ( V_51 < V_380 )
break;
V_407 ++ ;
break;
}
if ( V_8 -> V_48 & V_76 ||
V_8 -> V_48 & V_411 ) {
F_170 ( V_8 , V_331 ,
V_369 , V_402 ) ;
F_93 ( & V_331 -> V_196 , 0 ) ;
V_407 ++ ;
}
break;
case V_412 :
case V_413 :
V_407 ++ ;
break;
case V_414 :
if ( ! F_47 ( V_369 ) )
break;
V_407 ++ ;
break;
default:
break;
}
if ( V_407 >= V_123 )
break;
}
F_81 ( V_8 , V_406 , V_407 ) ;
F_82 ( V_8 , V_125 , V_406 , V_407 ) ;
V_307:
F_64 ( V_371 ) ;
for ( V_51 = 0 ; V_51 < V_405 ; V_51 ++ )
F_64 ( V_406 [ V_51 ] ) ;
F_64 ( V_406 ) ;
F_64 ( V_394 ) ;
F_64 ( V_395 ) ;
F_64 ( V_402 ) ;
}
static void F_175 ( struct V_201 * V_415 ,
struct V_416 * V_417 )
{
T_5 V_290 = ( T_5 ) F_176 ( V_417 ) ;
unsigned int V_34 = F_177 ( V_417 ) ;
V_415 -> V_213 = F_101 ( V_290 ) ;
V_415 -> V_211 = F_98 ( V_34 ) ;
V_415 -> V_208 = 0 ;
}
static int F_178 ( struct V_1 * V_8 ,
struct V_9 * V_92 ,
struct V_214 * V_215 )
{
struct V_416 * V_417 ;
int V_418 , V_51 , V_419 , V_420 ;
struct V_201 * V_421 ;
F_59 ( F_114 ( V_215 ) > V_8 -> V_422 ) ;
V_418 = F_179 ( V_215 ) ;
if ( V_418 < 0 )
return V_418 ;
if ( ! V_418 )
goto V_423;
V_421 = V_92 -> V_206 ;
V_420 = 0 ;
V_419 = 0 ;
F_180 (cmd, sg, use_sg, i) {
if ( V_51 == V_8 -> V_207 - 1 &&
V_418 > V_8 -> V_207 ) {
V_420 = 1 ;
V_421 = V_8 -> V_197 [ V_92 -> V_94 ] ;
V_419 = 0 ;
}
F_175 ( V_421 , V_417 ) ;
V_421 ++ ;
}
( -- V_421 ) -> V_208 = F_98 ( V_292 ) ;
if ( V_418 + V_420 > V_8 -> V_424 )
V_8 -> V_424 = V_418 + V_420 ;
if ( V_420 ) {
V_92 -> V_86 . V_87 = V_8 -> V_207 ;
V_92 -> V_86 . V_210 = F_115 ( V_418 + 1 ) ;
if ( F_97 ( V_8 , V_92 ) ) {
F_112 ( V_215 ) ;
return - 1 ;
}
return 0 ;
}
V_423:
V_92 -> V_86 . V_87 = ( T_4 ) V_418 ;
V_92 -> V_86 . V_210 = F_115 ( V_418 ) ;
return 0 ;
}
static int F_181 ( T_4 * V_101 , int * V_425 )
{
int V_426 = 0 ;
T_3 V_427 ;
T_3 V_428 ;
switch ( V_101 [ 0 ] ) {
case V_429 :
case V_430 :
V_426 = 1 ;
case V_431 :
case V_432 :
if ( * V_425 == 6 ) {
V_427 = ( ( ( T_3 ) V_101 [ 2 ] ) << 8 ) | V_101 [ 3 ] ;
V_428 = V_101 [ 4 ] ;
} else {
F_59 ( * V_425 != 12 ) ;
V_427 = ( ( ( T_3 ) V_101 [ 2 ] ) << 24 ) |
( ( ( T_3 ) V_101 [ 3 ] ) << 16 ) |
( ( ( T_3 ) V_101 [ 4 ] ) << 8 ) |
V_101 [ 5 ] ;
V_428 =
( ( ( T_3 ) V_101 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_101 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_101 [ 8 ] ) << 8 ) |
V_101 [ 9 ] ;
}
if ( V_428 > 0xffff )
return V_433 ;
V_101 [ 0 ] = V_426 ? V_434 : V_435 ;
V_101 [ 1 ] = 0 ;
V_101 [ 2 ] = ( T_4 ) ( V_427 >> 24 ) ;
V_101 [ 3 ] = ( T_4 ) ( V_427 >> 16 ) ;
V_101 [ 4 ] = ( T_4 ) ( V_427 >> 8 ) ;
V_101 [ 5 ] = ( T_4 ) ( V_427 ) ;
V_101 [ 6 ] = 0 ;
V_101 [ 7 ] = ( T_4 ) ( V_428 >> 8 ) ;
V_101 [ 8 ] = ( T_4 ) ( V_428 ) ;
V_101 [ 9 ] = 0 ;
* V_425 = 10 ;
break;
}
return 0 ;
}
static int F_182 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_138 , T_4 * V_101 , int V_425 ,
T_4 * V_54 , struct V_57 * V_187 )
{
struct V_214 * V_215 = V_10 -> V_254 ;
struct V_91 * V_92 = & V_8 -> V_93 [ V_10 -> V_94 ] ;
unsigned int V_34 ;
unsigned int V_436 = 0 ;
struct V_416 * V_417 ;
T_5 V_290 ;
int V_418 , V_51 ;
struct V_201 * V_421 ;
T_3 V_437 = V_438 ;
if ( F_114 ( V_215 ) > V_8 -> V_439 ) {
F_33 ( & V_187 -> V_196 ) ;
return V_433 ;
}
F_59 ( V_215 -> V_440 > V_441 ) ;
if ( F_181 ( V_101 , & V_425 ) ) {
F_33 ( & V_187 -> V_196 ) ;
return V_433 ;
}
V_10 -> V_110 = V_111 ;
V_10 -> V_84 = ( T_3 ) V_8 -> V_442 +
( V_10 -> V_94 * sizeof( * V_92 ) ) ;
F_59 ( V_10 -> V_84 & 0x0000007F ) ;
V_418 = F_179 ( V_215 ) ;
if ( V_418 < 0 ) {
F_33 ( & V_187 -> V_196 ) ;
return V_418 ;
}
if ( V_418 ) {
V_421 = V_92 -> V_206 ;
F_180 (cmd, sg, use_sg, i) {
V_290 = ( T_5 ) F_176 ( V_417 ) ;
V_34 = F_177 ( V_417 ) ;
V_436 += V_34 ;
V_421 -> V_213 = F_101 ( V_290 ) ;
V_421 -> V_211 = F_98 ( V_34 ) ;
V_421 -> V_208 = F_98 ( 0 ) ;
V_421 ++ ;
}
( -- V_421 ) -> V_208 = F_98 ( V_292 ) ;
switch ( V_215 -> V_443 ) {
case V_444 :
V_437 |= V_445 ;
break;
case V_446 :
V_437 |= V_447 ;
break;
case V_448 :
V_437 |= V_449 ;
break;
default:
F_55 ( & V_8 -> V_15 -> V_16 , L_151 ,
V_215 -> V_443 ) ;
F_168 () ;
break;
}
} else {
V_437 |= V_449 ;
}
V_10 -> V_86 . V_87 = V_418 ;
V_92 -> V_450 = F_115 ( V_138 & 0xFFFF ) ;
V_92 -> V_451 = F_98 ( V_436 ) ;
V_92 -> V_261 = F_115 ( V_452 |
( V_425 & V_262 ) ) ;
V_92 -> V_437 = F_98 ( V_437 ) ;
memcpy ( V_92 -> V_105 , V_101 , V_425 ) ;
memcpy ( V_92 -> V_266 , V_54 , 8 ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_214 * V_215 = V_10 -> V_254 ;
struct V_57 * V_16 = V_215 -> V_28 -> V_61 ;
V_10 -> V_187 = V_16 ;
return F_184 ( V_8 , V_10 , V_16 -> V_138 ,
V_215 -> V_453 , V_215 -> V_440 , V_16 -> V_54 , V_16 ) ;
}
static void F_185 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_97 * V_92 )
{
struct V_214 * V_215 = V_10 -> V_254 ;
struct V_57 * V_16 = V_215 -> V_28 -> V_61 ;
struct V_173 * V_174 = & V_16 -> V_137 ;
T_5 V_454 ;
if ( ! ( F_79 ( V_174 -> V_59 ) & V_328 ) )
return;
V_92 -> V_329 = V_174 -> V_329 ;
V_92 -> V_455 |= V_456 ;
switch ( V_215 -> V_453 [ 0 ] ) {
case V_429 :
case V_431 :
V_454 = F_186 ( & V_215 -> V_453 [ 2 ] ) ;
break;
case V_434 :
case V_435 :
case V_430 :
case V_432 :
V_454 = F_187 ( & V_215 -> V_453 [ 2 ] ) ;
break;
case V_457 :
case V_458 :
V_454 = F_188 ( & V_215 -> V_453 [ 2 ] ) ;
break;
default:
F_55 ( & V_8 -> V_15 -> V_16 ,
L_152 ,
V_156 , V_215 -> V_453 [ 0 ] ) ;
F_168 () ;
break;
}
if ( F_105 ( V_174 -> V_321 ) != 512 )
V_454 = V_454 *
F_105 ( V_174 -> V_321 ) / 512 ;
V_92 -> V_459 = F_98 ( V_454 ) ;
V_92 -> V_460 = F_98 ( V_454 >> 32 ) ;
}
static int F_189 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_138 , T_4 * V_101 , int V_425 ,
T_4 * V_54 , struct V_57 * V_187 )
{
struct V_214 * V_215 = V_10 -> V_254 ;
struct V_97 * V_92 = & V_8 -> V_98 [ V_10 -> V_94 ] ;
struct V_461 * V_421 ;
int V_418 , V_51 ;
struct V_416 * V_417 ;
T_5 V_290 ;
T_3 V_34 ;
T_3 V_436 = 0 ;
if ( F_114 ( V_215 ) > V_8 -> V_439 ) {
F_33 ( & V_187 -> V_196 ) ;
return V_433 ;
}
if ( F_181 ( V_101 , & V_425 ) ) {
F_33 ( & V_187 -> V_196 ) ;
return V_433 ;
}
V_10 -> V_110 = V_114 ;
V_10 -> V_84 = ( T_3 ) V_8 -> V_462 +
( V_10 -> V_94 * sizeof( * V_92 ) ) ;
F_59 ( V_10 -> V_84 & 0x0000007F ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_463 = V_464 ;
V_418 = F_179 ( V_215 ) ;
if ( V_418 < 0 ) {
F_33 ( & V_187 -> V_196 ) ;
return V_418 ;
}
if ( V_418 ) {
F_59 ( V_418 > V_465 ) ;
V_421 = V_92 -> V_417 ;
F_180 (cmd, sg, use_sg, i) {
V_290 = ( T_5 ) F_176 ( V_417 ) ;
V_34 = F_177 ( V_417 ) ;
V_436 += V_34 ;
V_421 -> V_466 = F_101 ( V_290 ) ;
V_421 -> V_467 = F_98 ( V_34 ) ;
V_421 -> V_468 [ 0 ] = 0 ;
V_421 -> V_468 [ 1 ] = 0 ;
V_421 -> V_468 [ 2 ] = 0 ;
V_421 -> V_469 = 0 ;
V_421 ++ ;
}
switch ( V_215 -> V_443 ) {
case V_444 :
V_92 -> V_455 &= ~ V_470 ;
V_92 -> V_455 |= V_471 ;
break;
case V_446 :
V_92 -> V_455 &= ~ V_470 ;
V_92 -> V_455 |= V_472 ;
break;
case V_448 :
V_92 -> V_455 &= ~ V_470 ;
V_92 -> V_455 |= V_473 ;
break;
default:
F_55 ( & V_8 -> V_15 -> V_16 , L_151 ,
V_215 -> V_443 ) ;
F_168 () ;
break;
}
} else {
V_92 -> V_455 &= ~ V_470 ;
V_92 -> V_455 |= V_473 ;
}
F_185 ( V_8 , V_10 , V_92 ) ;
V_92 -> V_385 = F_98 ( V_138 ) ;
V_92 -> V_474 = F_98 ( V_10 -> V_94 << V_475 ) ;
memcpy ( V_92 -> V_101 , V_101 , sizeof( V_92 -> V_101 ) ) ;
V_92 -> V_100 = ( T_4 ) V_418 ;
V_92 -> V_217 = F_98 ( V_436 ) ;
V_92 -> V_476 = F_101 ( V_10 -> V_84 +
F_190 ( struct V_97 , V_219 ) ) ;
V_92 -> V_477 = F_98 ( sizeof( V_92 -> V_219 ) ) ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_184 ( struct V_1 * V_8 ,
struct V_9 * V_10 , T_3 V_138 , T_4 * V_101 , int V_425 ,
T_4 * V_54 , struct V_57 * V_187 )
{
if ( F_191 ( & V_187 -> V_196 ) >
V_187 -> V_140 ) {
F_33 ( & V_187 -> V_196 ) ;
return V_433 ;
}
if ( V_8 -> V_48 & V_76 )
return F_182 ( V_8 , V_10 , V_138 ,
V_101 , V_425 , V_54 ,
V_187 ) ;
else
return F_189 ( V_8 , V_10 , V_138 ,
V_101 , V_425 , V_54 ,
V_187 ) ;
}
static void F_192 ( struct V_173 * V_174 ,
int V_139 , T_3 * V_478 , T_3 * V_479 )
{
if ( V_139 == 0 ) {
* V_478 %= F_79 ( V_174 -> V_179 ) ;
return;
}
do {
* V_479 = * V_478 /
F_79 ( V_174 -> V_179 ) ;
if ( V_139 == * V_479 )
continue;
if ( * V_479 < F_79 ( V_174 -> V_183 ) - 1 ) {
* V_478 += F_79 ( V_174 -> V_179 ) ;
( * V_479 ) ++ ;
} else {
* V_478 %= F_79 ( V_174 -> V_179 ) ;
* V_479 = 0 ;
}
} while ( V_139 != * V_479 );
}
static int F_193 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_214 * V_215 = V_10 -> V_254 ;
struct V_57 * V_16 = V_215 -> V_28 -> V_61 ;
struct V_173 * V_174 = & V_16 -> V_137 ;
struct V_175 * V_176 = & V_174 -> V_177 [ 0 ] ;
int V_426 = 0 ;
T_3 V_478 ;
T_5 V_454 , V_480 ;
T_3 V_428 ;
T_3 V_481 ;
T_5 V_482 , V_483 ;
T_3 V_484 , V_485 ;
T_3 V_486 , V_487 ;
T_5 V_488 , V_489 ;
T_3 V_490 ;
T_5 V_491 , V_492 ;
T_3 V_493 , V_494 ;
T_3 V_495 , V_496 ;
T_3 V_178 ;
T_3 V_497 ;
T_3 V_498 , V_499 , V_479 ;
T_3 V_500 ;
T_3 V_501 ;
T_5 V_502 ;
T_3 V_503 ;
T_4 V_101 [ 16 ] ;
T_4 V_425 ;
T_6 V_325 ;
#if V_504 == 32
T_5 V_505 ;
#endif
int V_139 ;
switch ( V_215 -> V_453 [ 0 ] ) {
case V_429 :
V_426 = 1 ;
case V_431 :
V_454 =
( ( ( T_5 ) V_215 -> V_453 [ 2 ] ) << 8 ) |
V_215 -> V_453 [ 3 ] ;
V_428 = V_215 -> V_453 [ 4 ] ;
if ( V_428 == 0 )
V_428 = 256 ;
break;
case V_434 :
V_426 = 1 ;
case V_435 :
V_454 =
( ( ( T_5 ) V_215 -> V_453 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_215 -> V_453 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_215 -> V_453 [ 4 ] ) << 8 ) |
V_215 -> V_453 [ 5 ] ;
V_428 =
( ( ( T_3 ) V_215 -> V_453 [ 7 ] ) << 8 ) |
V_215 -> V_453 [ 8 ] ;
break;
case V_430 :
V_426 = 1 ;
case V_432 :
V_454 =
( ( ( T_5 ) V_215 -> V_453 [ 2 ] ) << 24 ) |
( ( ( T_5 ) V_215 -> V_453 [ 3 ] ) << 16 ) |
( ( ( T_5 ) V_215 -> V_453 [ 4 ] ) << 8 ) |
V_215 -> V_453 [ 5 ] ;
V_428 =
( ( ( T_3 ) V_215 -> V_453 [ 6 ] ) << 24 ) |
( ( ( T_3 ) V_215 -> V_453 [ 7 ] ) << 16 ) |
( ( ( T_3 ) V_215 -> V_453 [ 8 ] ) << 8 ) |
V_215 -> V_453 [ 9 ] ;
break;
case V_457 :
V_426 = 1 ;
case V_458 :
V_454 =
( ( ( T_5 ) V_215 -> V_453 [ 2 ] ) << 56 ) |
( ( ( T_5 ) V_215 -> V_453 [ 3 ] ) << 48 ) |
( ( ( T_5 ) V_215 -> V_453 [ 4 ] ) << 40 ) |
( ( ( T_5 ) V_215 -> V_453 [ 5 ] ) << 32 ) |
( ( ( T_5 ) V_215 -> V_453 [ 6 ] ) << 24 ) |
( ( ( T_5 ) V_215 -> V_453 [ 7 ] ) << 16 ) |
( ( ( T_5 ) V_215 -> V_453 [ 8 ] ) << 8 ) |
V_215 -> V_453 [ 9 ] ;
V_428 =
( ( ( T_3 ) V_215 -> V_453 [ 10 ] ) << 24 ) |
( ( ( T_3 ) V_215 -> V_453 [ 11 ] ) << 16 ) |
( ( ( T_3 ) V_215 -> V_453 [ 12 ] ) << 8 ) |
V_215 -> V_453 [ 13 ] ;
break;
default:
return V_433 ;
}
V_480 = V_454 + V_428 - 1 ;
if ( V_426 && V_16 -> V_64 != 0 )
return V_433 ;
if ( V_480 >= F_104 ( V_174 -> V_322 ) ||
V_480 < V_454 )
return V_433 ;
V_481 = F_79 ( V_174 -> V_179 ) *
F_79 ( V_174 -> V_325 ) ;
V_325 = F_79 ( V_174 -> V_325 ) ;
#if V_504 == 32
V_505 = V_454 ;
( void ) F_194 ( V_505 , V_481 ) ;
V_482 = V_505 ;
V_505 = V_480 ;
( void ) F_194 ( V_505 , V_481 ) ;
V_483 = V_505 ;
V_484 = ( T_3 ) ( V_454 - ( V_482 * V_481 ) ) ;
V_485 = ( T_3 ) ( V_480 - ( V_483 * V_481 ) ) ;
V_505 = V_484 ;
( void ) F_194 ( V_505 , V_325 ) ;
V_486 = V_505 ;
V_505 = V_485 ;
( void ) F_194 ( V_505 , V_325 ) ;
V_487 = V_505 ;
#else
V_482 = V_454 / V_481 ;
V_483 = V_480 / V_481 ;
V_484 = ( T_3 ) ( V_454 - ( V_482 * V_481 ) ) ;
V_485 = ( T_3 ) ( V_480 - ( V_483 * V_481 ) ) ;
V_486 = V_484 / V_325 ;
V_487 = V_485 / V_325 ;
#endif
if ( ( V_482 != V_483 ) || ( V_486 != V_487 ) )
return V_433 ;
V_178 = F_79 ( V_174 -> V_179 ) +
F_79 ( V_174 -> V_180 ) ;
V_500 = ( ( T_3 ) ( V_482 >> V_174 -> V_324 ) ) %
F_79 ( V_174 -> V_182 ) ;
V_478 = ( V_500 * V_178 ) + V_486 ;
switch ( V_16 -> V_64 ) {
case V_506 :
break;
case V_507 :
F_59 ( F_79 ( V_174 -> V_183 ) != 2 ) ;
if ( V_16 -> V_139 )
V_478 += F_79 ( V_174 -> V_179 ) ;
V_16 -> V_139 = ! V_16 -> V_139 ;
break;
case V_508 :
F_59 ( F_79 ( V_174 -> V_183 ) != 3 ) ;
V_139 = V_16 -> V_139 ;
F_192 ( V_174 , V_139 ,
& V_478 , & V_479 ) ;
V_139 =
( V_139 >=
F_79 ( V_174 -> V_183 ) - 1 )
? 0 : V_139 + 1 ;
V_16 -> V_139 = V_139 ;
break;
case V_509 :
case V_510 :
if ( F_79 ( V_174 -> V_183 ) <= 1 )
break;
V_490 =
F_79 ( V_174 -> V_325 ) *
F_79 ( V_174 -> V_179 ) ;
F_59 ( V_490 == 0 ) ;
V_497 = V_490 *
F_79 ( V_174 -> V_183 ) ;
#if V_504 == 32
V_505 = V_454 ;
V_498 = F_194 ( V_505 , V_497 ) ;
V_505 = V_498 ;
( void ) F_194 ( V_505 , V_490 ) ;
V_498 = V_505 ;
V_505 = V_480 ;
V_499 = F_194 ( V_505 , V_497 ) ;
V_505 = V_499 ;
( void ) F_194 ( V_505 , V_490 ) ;
V_499 = V_505 ;
#else
V_498 = ( V_454 % V_497 ) / V_490 ;
V_499 = ( V_480 % V_497 ) / V_490 ;
#endif
if ( V_498 != V_499 )
return V_433 ;
#if V_504 == 32
V_505 = V_454 ;
( void ) F_194 ( V_505 , V_497 ) ;
V_482 = V_491 = V_488 = V_505 ;
V_505 = V_480 ;
( void ) F_194 ( V_505 , V_497 ) ;
V_492 = V_489 = V_505 ;
#else
V_482 = V_491 = V_488 =
V_454 / V_497 ;
V_492 = V_489 = V_480 / V_497 ;
#endif
if ( V_491 != V_492 )
return V_433 ;
#if V_504 == 32
V_505 = V_454 ;
V_484 = F_194 ( V_505 , V_497 ) ;
V_505 = V_484 ;
V_484 = ( T_3 ) F_194 ( V_505 , V_490 ) ;
V_493 = V_484 ;
V_505 = V_480 ;
V_494 = F_194 ( V_505 , V_497 ) ;
V_505 = V_494 ;
V_494 = F_194 ( V_505 , V_490 ) ;
V_505 = V_493 ;
( void ) F_194 ( V_505 , V_174 -> V_325 ) ;
V_486 = V_495 = V_505 ;
V_505 = V_494 ;
( void ) F_194 ( V_505 , V_174 -> V_325 ) ;
V_496 = V_505 ;
#else
V_484 = V_493 =
( T_3 ) ( ( V_454 % V_497 ) %
V_490 ) ;
V_494 =
( T_3 ) ( ( V_480 % V_497 ) %
V_490 ) ;
V_486 = V_495 =
V_493 / F_79 ( V_174 -> V_325 ) ;
V_496 =
V_494 / F_79 ( V_174 -> V_325 ) ;
#endif
if ( V_495 != V_496 )
return V_433 ;
V_500 = ( ( T_3 ) ( V_482 >> V_174 -> V_324 ) ) %
F_79 ( V_174 -> V_182 ) ;
V_478 = ( V_498 *
( F_79 ( V_174 -> V_182 ) * V_178 ) ) +
( V_500 * V_178 ) + V_486 ;
break;
default:
return V_433 ;
}
if ( F_32 ( V_478 >= V_186 ) )
return V_433 ;
V_10 -> V_187 = V_16 -> V_187 [ V_478 ] ;
V_501 = V_176 [ V_478 ] . V_138 ;
V_502 = F_104 ( V_174 -> V_326 ) +
V_482 * F_79 ( V_174 -> V_325 ) +
( V_484 - V_486 *
F_79 ( V_174 -> V_325 ) ) ;
V_503 = V_428 ;
if ( V_174 -> V_323 ) {
V_502 <<= V_174 -> V_323 ;
V_503 <<= V_174 -> V_323 ;
}
F_59 ( V_503 > 0xffff ) ;
if ( V_502 > 0xffffffff ) {
V_101 [ 0 ] = V_426 ? V_457 : V_458 ;
V_101 [ 1 ] = 0 ;
V_101 [ 2 ] = ( T_4 ) ( V_502 >> 56 ) ;
V_101 [ 3 ] = ( T_4 ) ( V_502 >> 48 ) ;
V_101 [ 4 ] = ( T_4 ) ( V_502 >> 40 ) ;
V_101 [ 5 ] = ( T_4 ) ( V_502 >> 32 ) ;
V_101 [ 6 ] = ( T_4 ) ( V_502 >> 24 ) ;
V_101 [ 7 ] = ( T_4 ) ( V_502 >> 16 ) ;
V_101 [ 8 ] = ( T_4 ) ( V_502 >> 8 ) ;
V_101 [ 9 ] = ( T_4 ) ( V_502 ) ;
V_101 [ 10 ] = ( T_4 ) ( V_503 >> 24 ) ;
V_101 [ 11 ] = ( T_4 ) ( V_503 >> 16 ) ;
V_101 [ 12 ] = ( T_4 ) ( V_503 >> 8 ) ;
V_101 [ 13 ] = ( T_4 ) ( V_503 ) ;
V_101 [ 14 ] = 0 ;
V_101 [ 15 ] = 0 ;
V_425 = 16 ;
} else {
V_101 [ 0 ] = V_426 ? V_434 : V_435 ;
V_101 [ 1 ] = 0 ;
V_101 [ 2 ] = ( T_4 ) ( V_502 >> 24 ) ;
V_101 [ 3 ] = ( T_4 ) ( V_502 >> 16 ) ;
V_101 [ 4 ] = ( T_4 ) ( V_502 >> 8 ) ;
V_101 [ 5 ] = ( T_4 ) ( V_502 ) ;
V_101 [ 6 ] = 0 ;
V_101 [ 7 ] = ( T_4 ) ( V_503 >> 8 ) ;
V_101 [ 8 ] = ( T_4 ) ( V_503 ) ;
V_101 [ 9 ] = 0 ;
V_425 = 10 ;
}
return F_184 ( V_8 , V_10 , V_501 , V_101 , V_425 ,
V_16 -> V_54 ,
V_16 -> V_187 [ V_478 ] ) ;
}
static int F_195 ( struct V_1 * V_8 ,
struct V_9 * V_10 , struct V_214 * V_215 ,
unsigned char V_54 [] )
{
V_215 -> V_511 = ( unsigned char * ) V_10 ;
V_10 -> V_110 = V_255 ;
V_10 -> V_254 = V_215 ;
V_10 -> V_86 . V_89 = 0 ;
memcpy ( & V_10 -> V_86 . V_264 . V_265 [ 0 ] , & V_54 [ 0 ] , 8 ) ;
V_10 -> V_86 . V_263 = F_101 ( ( V_10 -> V_94 << V_475 ) ) ;
V_10 -> V_104 . V_512 = 0 ;
memset ( V_10 -> V_104 . V_105 , 0 , sizeof( V_10 -> V_104 . V_105 ) ) ;
F_59 ( V_215 -> V_440 > sizeof( V_10 -> V_104 . V_105 ) ) ;
V_10 -> V_104 . V_260 = V_215 -> V_440 ;
memcpy ( V_10 -> V_104 . V_105 , V_215 -> V_453 , V_215 -> V_440 ) ;
switch ( V_215 -> V_443 ) {
case V_444 :
V_10 -> V_104 . V_513 =
F_196 ( V_306 , V_514 , V_515 ) ;
break;
case V_446 :
V_10 -> V_104 . V_513 =
F_196 ( V_306 , V_514 , V_516 ) ;
break;
case V_448 :
V_10 -> V_104 . V_513 =
F_196 ( V_306 , V_514 , V_517 ) ;
break;
case V_518 :
V_10 -> V_104 . V_513 =
F_196 ( V_306 , V_514 , V_519 ) ;
break;
default:
F_55 ( & V_8 -> V_15 -> V_16 , L_151 ,
V_215 -> V_443 ) ;
F_168 () ;
break;
}
if ( F_178 ( V_8 , V_10 , V_215 ) < 0 ) {
F_108 ( V_8 , V_10 ) ;
return V_520 ;
}
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static void V_246 ( struct V_521 * V_245 )
{
struct V_214 * V_215 ;
struct V_57 * V_16 ;
struct V_9 * V_10 =
F_197 ( V_245 , struct V_9 , V_245 ) ;
V_215 = V_10 -> V_254 ;
V_16 = V_215 -> V_28 -> V_61 ;
if ( ! V_16 ) {
V_215 -> V_224 = V_270 << 16 ;
V_215 -> V_242 ( V_215 ) ;
return;
}
if ( F_195 ( V_10 -> V_8 , V_10 , V_215 , V_16 -> V_54 ) ) {
V_215 -> V_224 = V_235 << 16 ;
V_215 -> V_242 ( V_215 ) ;
}
}
static int F_198 ( struct V_6 * V_7 , struct V_214 * V_215 )
{
struct V_1 * V_8 ;
struct V_57 * V_16 ;
unsigned char V_54 [ 8 ] ;
struct V_9 * V_10 ;
int V_296 = 0 ;
V_8 = F_1 ( V_215 -> V_28 ) ;
V_16 = V_215 -> V_28 -> V_61 ;
if ( ! V_16 ) {
V_215 -> V_224 = V_270 << 16 ;
V_215 -> V_242 ( V_215 ) ;
return 0 ;
}
memcpy ( V_54 , V_16 -> V_54 , sizeof( V_54 ) ) ;
if ( F_32 ( F_121 ( V_8 ) ) ) {
V_215 -> V_224 = V_275 << 16 ;
V_215 -> V_242 ( V_215 ) ;
return 0 ;
}
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return V_520 ;
}
if ( F_32 ( F_121 ( V_8 ) ) ) {
V_215 -> V_224 = V_275 << 16 ;
F_108 ( V_8 , V_10 ) ;
V_215 -> V_242 ( V_215 ) ;
return 0 ;
}
if ( F_35 ( V_215 -> V_522 == 0 &&
V_215 -> V_523 -> V_110 == V_524 &&
V_8 -> V_41 ) ) {
V_215 -> V_511 = ( unsigned char * ) V_10 ;
V_10 -> V_110 = V_255 ;
V_10 -> V_254 = V_215 ;
if ( V_16 -> V_70 ) {
V_296 = F_193 ( V_8 , V_10 ) ;
if ( V_296 == 0 )
return 0 ;
if ( V_296 < 0 ) {
F_108 ( V_8 , V_10 ) ;
return V_520 ;
}
} else if ( V_16 -> V_138 ) {
V_296 = F_183 ( V_8 , V_10 ) ;
if ( V_296 == 0 )
return 0 ;
if ( V_296 < 0 ) {
F_108 ( V_8 , V_10 ) ;
return V_520 ;
}
}
}
return F_195 ( V_8 , V_10 , V_215 , V_54 ) ;
}
static void F_199 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
F_26 ( & V_8 -> V_525 , V_59 ) ;
V_8 -> V_526 = 1 ;
F_200 ( & V_8 -> V_527 ) ;
F_27 ( & V_8 -> V_525 , V_59 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
if ( F_32 ( F_121 ( V_8 ) ) )
return F_199 ( V_8 ) ;
while ( 1 ) {
F_26 ( & V_8 -> V_525 , V_59 ) ;
if ( V_8 -> V_526 )
break;
F_27 ( & V_8 -> V_525 , V_59 ) ;
F_201 ( V_8 -> V_527 , V_8 -> V_526 ) ;
}
V_8 -> V_526 = 0 ;
F_27 ( & V_8 -> V_525 , V_59 ) ;
if ( F_32 ( F_121 ( V_8 ) ) )
return F_199 ( V_8 ) ;
F_174 ( V_8 , V_8 -> V_44 -> V_160 ) ;
F_199 ( V_8 ) ;
}
static int F_202 ( struct V_2 * V_3 , int V_185 )
{
struct V_57 * V_172 = V_3 -> V_61 ;
if ( ! V_172 )
return - V_62 ;
if ( V_185 < 1 )
V_185 = 1 ;
else if ( V_185 > V_172 -> V_140 )
V_185 = V_172 -> V_140 ;
return F_92 ( V_3 , V_185 ) ;
}
static int F_203 ( struct V_6 * V_7 ,
unsigned long V_528 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_59 ;
int V_529 ;
F_26 ( & V_8 -> V_525 , V_59 ) ;
V_529 = V_8 -> V_526 ;
F_27 ( & V_8 -> V_525 , V_59 ) ;
return V_529 ;
}
static void F_204 ( struct V_1 * V_8 )
{
F_205 ( V_8 -> V_44 ) ;
F_206 ( V_8 -> V_44 ) ;
V_8 -> V_44 = NULL ;
}
static int F_207 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_208 ( & V_530 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_531;
V_7 -> V_532 = 0 ;
V_7 -> V_533 = 0 ;
V_7 -> V_534 = - 1 ;
V_7 -> V_535 = 3 ;
V_7 -> V_536 = V_537 ;
V_7 -> V_538 = V_392 ;
V_7 -> V_539 = V_392 ;
V_7 -> V_540 = V_8 -> V_189 -
V_541 -
V_542 -
V_543 ;
V_7 -> V_544 = V_7 -> V_540 ;
V_7 -> V_545 = V_8 -> V_422 ;
V_8 -> V_44 = V_7 ;
V_7 -> V_61 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_546 = V_8 -> V_547 [ V_8 -> V_548 ] ;
V_7 -> V_549 = V_7 -> V_546 ;
error = F_209 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_550;
F_210 ( V_7 ) ;
return 0 ;
V_550:
F_55 ( & V_8 -> V_15 -> V_16 , L_153
L_154 , V_156 , V_8 -> V_18 ) ;
F_206 ( V_7 ) ;
return error ;
V_531:
F_55 ( & V_8 -> V_15 -> V_16 , L_155
L_154 , V_156 , V_8 -> V_18 ) ;
return - V_199 ;
}
static int F_211 ( struct V_1 * V_8 ,
unsigned char V_551 [] )
{
int V_296 ;
int V_32 = 0 ;
int V_552 = 1 ;
struct V_9 * V_10 ;
V_10 = F_131 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_49
L_156 ) ;
return V_553 ;
}
while ( V_32 < V_554 ) {
F_127 ( 1000 * V_552 ) ;
V_32 ++ ;
V_296 = 0 ;
if ( V_552 < V_555 )
V_552 = V_552 * 2 ;
( void ) F_132 ( V_10 , V_359 , V_8 ,
NULL , 0 , 0 , V_551 , V_306 ) ;
F_118 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_23 == V_556 )
break;
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 == V_225 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_557 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_157
L_158 , V_552 ) ;
V_296 = 1 ;
}
if ( V_296 )
F_5 ( & V_8 -> V_15 -> V_16 , L_159 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_160 ) ;
F_108 ( V_8 , V_10 ) ;
return V_296 ;
}
static int F_212 ( struct V_214 * V_558 )
{
int V_296 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
V_8 = F_1 ( V_558 -> V_28 ) ;
if ( V_8 == NULL )
return V_559 ;
if ( F_121 ( V_8 ) )
return V_559 ;
V_16 = V_558 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_161
L_162 ) ;
return V_559 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_163 ,
V_8 -> V_44 -> V_160 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_296 = F_134 ( V_8 , V_16 -> V_54 , V_560 ) ;
if ( V_296 == 0 && F_211 ( V_8 , V_16 -> V_54 ) == 0 )
return V_561 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ) ;
return V_559 ;
}
static void F_213 ( T_4 * V_263 )
{
T_4 V_562 [ 8 ] ;
memcpy ( V_562 , V_263 , 8 ) ;
V_263 [ 0 ] = V_562 [ 3 ] ;
V_263 [ 1 ] = V_562 [ 2 ] ;
V_263 [ 2 ] = V_562 [ 1 ] ;
V_263 [ 3 ] = V_562 [ 0 ] ;
V_263 [ 4 ] = V_562 [ 7 ] ;
V_263 [ 5 ] = V_562 [ 6 ] ;
V_263 [ 6 ] = V_562 [ 5 ] ;
V_263 [ 7 ] = V_562 [ 4 ] ;
}
static void F_214 ( struct V_1 * V_8 ,
struct V_9 * V_10 , V_370 * V_563 , V_370 * V_564 )
{
T_5 V_263 ;
if ( V_10 -> V_110 == V_111 ) {
struct V_91 * V_565 = (struct V_91 * )
& V_8 -> V_93 [ V_10 -> V_94 ] ;
V_263 = F_104 ( V_565 -> V_263 ) ;
* V_564 = F_98 ( V_263 >> 32 ) ;
* V_563 = F_98 ( V_263 ) ;
return;
}
if ( V_10 -> V_110 == V_114 ) {
struct V_97 * V_566 = (struct V_97 * )
& V_8 -> V_98 [ V_10 -> V_94 ] ;
memset ( V_564 , 0 , sizeof( * V_564 ) ) ;
* V_563 = V_566 -> V_474 ;
return;
}
V_263 = F_104 ( V_10 -> V_86 . V_263 ) ;
* V_564 = F_98 ( V_263 >> 32 ) ;
* V_563 = F_98 ( V_263 ) ;
}
static int F_215 ( struct V_1 * V_8 , unsigned char * V_54 ,
struct V_9 * abort , int V_567 )
{
int V_296 = V_304 ;
struct V_9 * V_10 ;
struct V_248 * V_249 ;
V_370 V_564 , V_563 ;
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
return - V_199 ;
}
( void ) F_132 ( V_10 , V_568 , V_8 , abort ,
0 , 0 , V_54 , V_313 ) ;
if ( V_567 )
F_213 ( & V_10 -> V_104 . V_105 [ 4 ] ) ;
F_118 ( V_8 , V_10 ) ;
F_214 ( V_8 , abort , & V_563 , & V_564 ) ;
F_216 ( & V_8 -> V_15 -> V_16 , L_165 ,
V_156 , V_564 , V_563 ) ;
V_249 = V_10 -> V_11 ;
switch ( V_249 -> V_23 ) {
case V_556 :
break;
case V_284 :
V_296 = - 1 ;
break;
default:
F_216 ( & V_8 -> V_15 -> V_16 , L_166 ,
V_156 , V_564 , V_563 ) ;
F_129 ( V_8 , V_10 ) ;
V_296 = - 1 ;
break;
}
F_108 ( V_8 , V_10 ) ;
F_216 ( & V_8 -> V_15 -> V_16 , L_167 ,
V_156 , V_564 , V_563 ) ;
return V_296 ;
}
static int F_217 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
int V_296 = V_304 ;
struct V_214 * V_382 ;
struct V_57 * V_16 ;
unsigned char V_569 [ 8 ] ;
unsigned char * V_570 = & V_569 [ 0 ] ;
V_382 = abort -> V_254 ;
V_16 = (struct V_57 * ) ( V_382 -> V_28 -> V_61 ) ;
if ( V_16 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_168 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_169 ,
V_8 -> V_44 -> V_160 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ,
V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] , V_54 [ 3 ] ,
V_54 [ 4 ] , V_54 [ 5 ] , V_54 [ 6 ] , V_54 [ 7 ] ) ;
if ( ! V_16 -> V_70 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_170 ) ;
return - 1 ;
}
if ( ! F_164 ( V_8 , abort , V_570 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_171 ) ;
return - 1 ;
}
if ( V_8 -> V_43 > 0 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_172 ,
V_570 [ 0 ] , V_570 [ 1 ] , V_570 [ 2 ] , V_570 [ 3 ] ,
V_570 [ 4 ] , V_570 [ 5 ] , V_570 [ 6 ] , V_570 [ 7 ] ) ;
V_296 = F_134 ( V_8 , V_570 , V_571 ) ;
if ( V_296 != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_173 ,
V_570 [ 0 ] , V_570 [ 1 ] , V_570 [ 2 ] , V_570 [ 3 ] ,
V_570 [ 4 ] , V_570 [ 5 ] , V_570 [ 6 ] , V_570 [ 7 ] ) ;
return V_296 ;
}
if ( F_211 ( V_8 , V_570 ) != 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_174 ,
V_570 [ 0 ] , V_570 [ 1 ] , V_570 [ 2 ] , V_570 [ 3 ] ,
V_570 [ 4 ] , V_570 [ 5 ] , V_570 [ 6 ] , V_570 [ 7 ] ) ;
return - 1 ;
}
F_56 ( & V_8 -> V_15 -> V_16 ,
L_175 ,
V_570 [ 0 ] , V_570 [ 1 ] , V_570 [ 2 ] , V_570 [ 3 ] ,
V_570 [ 4 ] , V_570 [ 5 ] , V_570 [ 6 ] , V_570 [ 7 ] ) ;
return V_296 ;
}
static int F_218 ( struct V_1 * V_8 ,
unsigned char * V_54 , struct V_9 * abort )
{
if ( abort -> V_110 == V_114 )
return F_217 ( V_8 , V_54 , abort ) ;
return F_215 ( V_8 , V_54 , abort , 0 ) &&
F_215 ( V_8 , V_54 , abort , 1 ) ;
}
static int F_219 ( struct V_214 * V_572 )
{
int V_51 , V_296 ;
struct V_1 * V_8 ;
struct V_57 * V_16 ;
struct V_9 * abort ;
struct V_214 * V_573 ;
char V_574 [ 256 ] ;
int V_575 = 0 ;
V_370 V_564 , V_563 ;
int V_576 ;
V_8 = F_1 ( V_572 -> V_28 ) ;
if ( F_220 ( V_8 == NULL ,
L_176 ) )
return V_559 ;
if ( F_121 ( V_8 ) )
return V_559 ;
if ( ! ( V_577 & V_8 -> V_578 ) &&
! ( V_579 & V_8 -> V_578 ) )
return V_559 ;
memset ( V_574 , 0 , sizeof( V_574 ) ) ;
V_575 += sprintf ( V_574 + V_575 , L_177 ,
V_8 -> V_44 -> V_160 , V_572 -> V_28 -> V_580 ,
V_572 -> V_28 -> V_581 , V_572 -> V_28 -> V_120 ) ;
V_16 = V_572 -> V_28 -> V_61 ;
if ( ! V_16 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_178 ,
V_574 ) ;
return V_559 ;
}
abort = (struct V_9 * ) V_572 -> V_511 ;
if ( abort == NULL ) {
return V_561 ;
}
V_576 = F_191 ( & abort -> V_576 ) ;
if ( V_576 == 1 ) {
F_108 ( V_8 , abort ) ;
return V_561 ;
}
F_214 ( V_8 , abort , & V_563 , & V_564 ) ;
V_575 += sprintf ( V_574 + V_575 , L_179 , V_564 , V_563 ) ;
V_573 = abort -> V_254 ;
if ( V_573 != NULL )
V_575 += sprintf ( V_574 + V_575 , L_180 ,
V_573 -> V_453 [ 0 ] , V_573 -> V_582 ) ;
F_216 ( & V_8 -> V_15 -> V_16 , L_19 , V_574 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_181 ,
V_8 -> V_44 -> V_160 , V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
V_296 = F_218 ( V_8 , V_16 -> V_54 , abort ) ;
if ( V_296 != 0 ) {
F_216 ( & V_8 -> V_15 -> V_16 , L_182 , V_574 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_183 ,
V_8 -> V_44 -> V_160 ,
V_16 -> V_118 , V_16 -> V_119 , V_16 -> V_120 ) ;
F_108 ( V_8 , abort ) ;
return V_559 ;
}
F_56 ( & V_8 -> V_15 -> V_16 , L_184 , V_574 ) ;
#define F_221 30
for ( V_51 = 0 ; V_51 < F_221 * 10 ; V_51 ++ ) {
V_576 = F_15 ( & abort -> V_576 ) ;
if ( V_576 < 2 ) {
F_108 ( V_8 , abort ) ;
return V_561 ;
} else {
F_127 ( 100 ) ;
}
}
F_5 ( & V_8 -> V_15 -> V_16 , L_185 ,
V_574 , F_221 ) ;
F_108 ( V_8 , abort ) ;
return V_559 ;
}
static struct V_9 * F_131 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_51 ;
union V_583 V_204 ;
V_288 V_584 , V_585 ;
int V_576 ;
unsigned long V_586 ;
V_586 = V_8 -> V_587 ;
for (; ; ) {
V_51 = F_222 ( V_8 -> V_588 , V_8 -> V_189 , V_586 ) ;
if ( F_32 ( V_51 == V_8 -> V_189 ) ) {
V_586 = 0 ;
continue;
}
V_10 = V_8 -> V_589 + V_51 ;
V_576 = F_191 ( & V_10 -> V_576 ) ;
if ( F_32 ( V_576 > 1 ) ) {
F_108 ( V_8 , V_10 ) ;
V_586 = ( V_51 + 1 ) % V_8 -> V_189 ;
continue;
}
F_163 ( V_51 & ( V_504 - 1 ) ,
V_8 -> V_588 + ( V_51 / V_504 ) ) ;
break;
}
V_8 -> V_587 = V_51 ;
memset ( V_10 , 0 , F_190 ( struct V_9 , V_576 ) ) ;
V_10 -> V_86 . V_263 = F_101 ( ( T_5 ) ( V_51 << V_475 ) ) ;
V_584 = V_8 -> V_590 + V_51 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_591 + V_51 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_585 = V_8 -> V_592
+ V_51 * sizeof( * V_10 -> V_11 ) ;
V_10 -> V_94 = V_51 ;
V_10 -> V_84 = ( T_3 ) V_584 ;
V_204 . V_593 = ( T_5 ) V_585 ;
V_10 -> V_594 . V_213 = F_101 ( ( T_5 ) V_585 ) ;
V_10 -> V_594 . V_211 = F_98 ( ( T_3 ) sizeof( * V_10 -> V_11 ) ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_108 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_44 ( & V_10 -> V_576 ) ) {
int V_51 ;
V_51 = V_10 - V_8 -> V_589 ;
F_223 ( V_51 & ( V_504 - 1 ) ,
V_8 -> V_588 + ( V_51 / V_504 ) ) ;
}
}
static int F_224 ( struct V_2 * V_16 , int V_215 ,
void T_7 * V_595 )
{
T_8 T_7 * V_596 =
( T_8 T_7 * ) V_595 ;
T_9 V_597 ;
T_9 T_7 * V_598 = F_225 ( sizeof( V_597 ) ) ;
int V_599 ;
T_3 V_92 ;
memset ( & V_597 , 0 , sizeof( V_597 ) ) ;
V_599 = 0 ;
V_599 |= F_226 ( & V_597 . V_600 , & V_596 -> V_600 ,
sizeof( V_597 . V_600 ) ) ;
V_599 |= F_226 ( & V_597 . V_104 , & V_596 -> V_104 ,
sizeof( V_597 . V_104 ) ) ;
V_599 |= F_226 ( & V_597 . V_601 , & V_596 -> V_601 ,
sizeof( V_597 . V_601 ) ) ;
V_599 |= F_227 ( V_597 . V_602 , & V_596 -> V_602 ) ;
V_599 |= F_227 ( V_92 , & V_596 -> V_31 ) ;
V_597 . V_31 = F_228 ( V_92 ) ;
V_599 |= F_229 ( V_598 , & V_597 , sizeof( V_597 ) ) ;
if ( V_599 )
return - V_603 ;
V_599 = F_230 ( V_16 , V_604 , V_598 ) ;
if ( V_599 )
return V_599 ;
V_599 |= F_231 ( & V_596 -> V_601 , & V_598 -> V_601 ,
sizeof( V_596 -> V_601 ) ) ;
if ( V_599 )
return - V_603 ;
return V_599 ;
}
static int F_232 ( struct V_2 * V_16 ,
int V_215 , void T_7 * V_595 )
{
T_10 T_7 * V_596 =
( T_10 T_7 * ) V_595 ;
T_11 V_597 ;
T_11 T_7 * V_598 =
F_225 ( sizeof( V_597 ) ) ;
int V_599 ;
T_3 V_92 ;
memset ( & V_597 , 0 , sizeof( V_597 ) ) ;
V_599 = 0 ;
V_599 |= F_226 ( & V_597 . V_600 , & V_596 -> V_600 ,
sizeof( V_597 . V_600 ) ) ;
V_599 |= F_226 ( & V_597 . V_104 , & V_596 -> V_104 ,
sizeof( V_597 . V_104 ) ) ;
V_599 |= F_226 ( & V_597 . V_601 , & V_596 -> V_601 ,
sizeof( V_597 . V_601 ) ) ;
V_599 |= F_227 ( V_597 . V_602 , & V_596 -> V_602 ) ;
V_599 |= F_227 ( V_597 . V_605 , & V_596 -> V_605 ) ;
V_599 |= F_227 ( V_92 , & V_596 -> V_31 ) ;
V_597 . V_31 = F_228 ( V_92 ) ;
V_599 |= F_229 ( V_598 , & V_597 , sizeof( V_597 ) ) ;
if ( V_599 )
return - V_603 ;
V_599 = F_230 ( V_16 , V_606 , V_598 ) ;
if ( V_599 )
return V_599 ;
V_599 |= F_231 ( & V_596 -> V_601 , & V_598 -> V_601 ,
sizeof( V_596 -> V_601 ) ) ;
if ( V_599 )
return - V_603 ;
return V_599 ;
}
static int F_233 ( struct V_2 * V_16 , int V_215 , void T_7 * V_595 )
{
switch ( V_215 ) {
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
case V_617 :
case V_618 :
case V_619 :
case V_620 :
case V_621 :
return F_230 ( V_16 , V_215 , V_595 ) ;
case V_622 :
return F_224 ( V_16 , V_215 , V_595 ) ;
case V_623 :
return F_232 ( V_16 , V_215 , V_595 ) ;
default:
return - V_624 ;
}
}
static int F_234 ( struct V_1 * V_8 , void T_7 * V_625 )
{
struct V_626 V_627 ;
if ( ! V_625 )
return - V_40 ;
V_627 . V_628 = F_235 ( V_8 -> V_15 -> V_118 ) ;
V_627 . V_118 = V_8 -> V_15 -> V_118 -> V_629 ;
V_627 . V_630 = V_8 -> V_15 -> V_631 ;
V_627 . V_50 = V_8 -> V_50 ;
if ( F_229 ( V_625 , & V_627 , sizeof( V_627 ) ) )
return - V_603 ;
return 0 ;
}
static int F_236 ( struct V_1 * V_8 , void T_7 * V_625 )
{
T_12 V_632 ;
unsigned char V_633 , V_634 , V_635 ;
int V_296 ;
V_296 = sscanf ( V_636 , L_186 ,
& V_633 , & V_634 , & V_635 ) ;
if ( V_296 != 3 ) {
F_56 ( & V_8 -> V_15 -> V_16 , L_187
L_188 , V_636 ) ;
V_633 = 0 ;
V_634 = 0 ;
V_635 = 0 ;
}
V_632 = ( V_633 << 16 ) | ( V_634 << 8 ) | V_635 ;
if ( ! V_625 )
return - V_40 ;
if ( F_229 ( V_625 , & V_632 , sizeof( T_12 ) ) )
return - V_603 ;
return 0 ;
}
static int F_237 ( struct V_1 * V_8 , void T_7 * V_625 )
{
T_9 V_637 ;
struct V_9 * V_10 ;
char * V_638 = NULL ;
T_5 V_204 ;
int V_296 = 0 ;
if ( ! V_625 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_639 ;
if ( F_226 ( & V_637 , V_625 , sizeof( V_637 ) ) )
return - V_603 ;
if ( ( V_637 . V_602 < 1 ) &&
( V_637 . V_104 . Type . V_640 != V_517 ) ) {
return - V_40 ;
}
if ( V_637 . V_602 > 0 ) {
V_638 = F_75 ( V_637 . V_602 , V_155 ) ;
if ( V_638 == NULL )
return - V_603 ;
if ( V_637 . V_104 . Type . V_640 & V_515 ) {
if ( F_226 ( V_638 , V_637 . V_31 ,
V_637 . V_602 ) ) {
V_296 = - V_603 ;
goto V_641;
}
} else {
memset ( V_638 , 0 , V_637 . V_602 ) ;
}
}
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
V_296 = - V_199 ;
goto V_641;
}
V_10 -> V_110 = V_642 ;
V_10 -> V_86 . V_89 = 0 ;
if ( V_637 . V_602 > 0 ) {
V_10 -> V_86 . V_87 = 1 ;
V_10 -> V_86 . V_210 = F_115 ( 1 ) ;
} else {
V_10 -> V_86 . V_87 = 0 ;
V_10 -> V_86 . V_210 = F_115 ( 0 ) ;
}
memcpy ( & V_10 -> V_86 . V_264 , & V_637 . V_600 , sizeof( V_10 -> V_86 . V_264 ) ) ;
memcpy ( & V_10 -> V_104 , & V_637 . V_104 ,
sizeof( V_10 -> V_104 ) ) ;
if ( V_637 . V_602 > 0 ) {
V_204 = F_99 ( V_8 -> V_15 , V_638 ,
V_637 . V_602 , V_643 ) ;
if ( F_100 ( & V_8 -> V_15 -> V_16 , ( V_288 ) V_204 ) ) {
V_10 -> V_206 [ 0 ] . V_213 = F_101 ( 0 ) ;
V_10 -> V_206 [ 0 ] . V_211 = F_98 ( 0 ) ;
V_296 = - V_199 ;
goto V_307;
}
V_10 -> V_206 [ 0 ] . V_213 = F_101 ( V_204 ) ;
V_10 -> V_206 [ 0 ] . V_211 = F_98 ( V_637 . V_602 ) ;
V_10 -> V_206 [ 0 ] . V_208 = F_98 ( V_292 ) ;
}
F_125 ( V_8 , V_10 ) ;
if ( V_637 . V_602 > 0 )
F_116 ( V_8 -> V_15 , V_10 , 1 , V_643 ) ;
F_238 ( V_8 , V_10 ) ;
memcpy ( & V_637 . V_601 , V_10 -> V_11 ,
sizeof( V_637 . V_601 ) ) ;
if ( F_229 ( V_625 , & V_637 , sizeof( V_637 ) ) ) {
V_296 = - V_603 ;
goto V_307;
}
if ( ( V_637 . V_104 . Type . V_640 & V_516 ) &&
V_637 . V_602 > 0 ) {
if ( F_229 ( V_637 . V_31 , V_638 , V_637 . V_602 ) ) {
V_296 = - V_603 ;
goto V_307;
}
}
V_307:
F_108 ( V_8 , V_10 ) ;
V_641:
F_64 ( V_638 ) ;
return V_296 ;
}
static int F_239 ( struct V_1 * V_8 , void T_7 * V_625 )
{
T_11 * V_644 ;
struct V_9 * V_10 ;
unsigned char * * V_638 = NULL ;
int * V_645 = NULL ;
T_5 V_204 ;
T_13 V_286 = 0 ;
int V_33 = 0 ;
T_3 V_646 ;
T_3 V_647 ;
T_13 T_7 * V_648 ;
if ( ! V_625 )
return - V_40 ;
if ( ! F_9 ( V_38 ) )
return - V_639 ;
V_644 = ( T_11 * )
F_75 ( sizeof( * V_644 ) , V_155 ) ;
if ( ! V_644 ) {
V_33 = - V_199 ;
goto V_649;
}
if ( F_226 ( V_644 , V_625 , sizeof( * V_644 ) ) ) {
V_33 = - V_603 ;
goto V_649;
}
if ( ( V_644 -> V_602 < 1 ) &&
( V_644 -> V_104 . Type . V_640 != V_517 ) ) {
V_33 = - V_40 ;
goto V_649;
}
if ( V_644 -> V_605 > V_650 ) {
V_33 = - V_40 ;
goto V_649;
}
if ( V_644 -> V_602 > V_644 -> V_605 * V_651 ) {
V_33 = - V_40 ;
goto V_649;
}
V_638 = F_83 ( V_651 * sizeof( char * ) , V_155 ) ;
if ( ! V_638 ) {
V_33 = - V_199 ;
goto V_649;
}
V_645 = F_75 ( V_651 * sizeof( int ) , V_155 ) ;
if ( ! V_645 ) {
V_33 = - V_199 ;
goto V_649;
}
V_646 = V_644 -> V_602 ;
V_648 = V_644 -> V_31 ;
while ( V_646 ) {
V_647 = ( V_646 > V_644 -> V_605 ) ? V_644 -> V_605 : V_646 ;
V_645 [ V_286 ] = V_647 ;
V_638 [ V_286 ] = F_75 ( V_647 , V_155 ) ;
if ( V_638 [ V_286 ] == NULL ) {
V_33 = - V_199 ;
goto V_649;
}
if ( V_644 -> V_104 . Type . V_640 & V_515 ) {
if ( F_226 ( V_638 [ V_286 ] , V_648 , V_647 ) ) {
V_33 = - V_603 ;
goto V_649;
}
} else
memset ( V_638 [ V_286 ] , 0 , V_647 ) ;
V_646 -= V_647 ;
V_648 += V_647 ;
V_286 ++ ;
}
V_10 = F_131 ( V_8 ) ;
if ( V_10 == NULL ) {
V_33 = - V_199 ;
goto V_649;
}
V_10 -> V_110 = V_642 ;
V_10 -> V_86 . V_89 = 0 ;
V_10 -> V_86 . V_87 = ( T_4 ) V_286 ;
V_10 -> V_86 . V_210 = F_115 ( V_286 ) ;
memcpy ( & V_10 -> V_86 . V_264 , & V_644 -> V_600 , sizeof( V_10 -> V_86 . V_264 ) ) ;
memcpy ( & V_10 -> V_104 , & V_644 -> V_104 , sizeof( V_10 -> V_104 ) ) ;
if ( V_644 -> V_602 > 0 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_286 ; V_51 ++ ) {
V_204 = F_99 ( V_8 -> V_15 , V_638 [ V_51 ] ,
V_645 [ V_51 ] , V_643 ) ;
if ( F_100 ( & V_8 -> V_15 -> V_16 ,
( V_288 ) V_204 ) ) {
V_10 -> V_206 [ V_51 ] . V_213 = F_101 ( 0 ) ;
V_10 -> V_206 [ V_51 ] . V_211 = F_98 ( 0 ) ;
F_116 ( V_8 -> V_15 , V_10 , V_51 ,
V_643 ) ;
V_33 = - V_199 ;
goto V_652;
}
V_10 -> V_206 [ V_51 ] . V_213 = F_101 ( V_204 ) ;
V_10 -> V_206 [ V_51 ] . V_211 = F_98 ( V_645 [ V_51 ] ) ;
V_10 -> V_206 [ V_51 ] . V_208 = F_98 ( 0 ) ;
}
V_10 -> V_206 [ -- V_51 ] . V_208 = F_98 ( V_292 ) ;
}
F_125 ( V_8 , V_10 ) ;
if ( V_286 )
F_116 ( V_8 -> V_15 , V_10 , V_286 , V_643 ) ;
F_238 ( V_8 , V_10 ) ;
memcpy ( & V_644 -> V_601 , V_10 -> V_11 , sizeof( V_644 -> V_601 ) ) ;
if ( F_229 ( V_625 , V_644 , sizeof( * V_644 ) ) ) {
V_33 = - V_603 ;
goto V_652;
}
if ( ( V_644 -> V_104 . Type . V_640 & V_516 ) && V_644 -> V_602 > 0 ) {
int V_51 ;
T_13 T_7 * V_653 = V_644 -> V_31 ;
for ( V_51 = 0 ; V_51 < V_286 ; V_51 ++ ) {
if ( F_229 ( V_653 , V_638 [ V_51 ] , V_645 [ V_51 ] ) ) {
V_33 = - V_603 ;
goto V_652;
}
V_653 += V_645 [ V_51 ] ;
}
}
V_33 = 0 ;
V_652:
F_108 ( V_8 , V_10 ) ;
V_649:
if ( V_638 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_286 ; V_51 ++ )
F_64 ( V_638 [ V_51 ] ) ;
F_64 ( V_638 ) ;
}
F_64 ( V_645 ) ;
F_64 ( V_644 ) ;
return V_33 ;
}
static void F_238 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_23 == V_24 &&
V_10 -> V_11 -> V_25 != V_225 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_230 ( struct V_2 * V_16 , int V_215 , void T_7 * V_595 )
{
struct V_1 * V_8 ;
void T_7 * V_625 = ( void T_7 * ) V_595 ;
int V_296 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_215 ) {
case V_617 :
case V_618 :
case V_619 :
F_12 ( V_8 -> V_44 ) ;
return 0 ;
case V_607 :
return F_234 ( V_8 , V_625 ) ;
case V_615 :
return F_236 ( V_8 , V_625 ) ;
case V_604 :
if ( F_240 ( & V_8 -> V_654 ) < 0 )
return - V_655 ;
V_296 = F_237 ( V_8 , V_625 ) ;
F_42 ( & V_8 -> V_654 ) ;
return V_296 ;
case V_606 :
if ( F_240 ( & V_8 -> V_654 ) < 0 )
return - V_655 ;
V_296 = F_239 ( V_8 , V_625 ) ;
F_42 ( & V_8 -> V_654 ) ;
return V_296 ;
default:
return - V_656 ;
}
}
static int F_241 ( struct V_1 * V_8 , unsigned char * V_54 ,
T_4 V_311 )
{
struct V_9 * V_10 ;
V_10 = F_131 ( V_8 ) ;
if ( ! V_10 )
return - V_199 ;
( void ) F_132 ( V_10 , V_312 , V_8 , NULL , 0 , 0 ,
V_117 , V_313 ) ;
V_10 -> V_104 . V_105 [ 1 ] = V_311 ;
V_10 -> V_294 = NULL ;
F_45 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_132 ( struct V_9 * V_10 , T_4 V_215 , struct V_1 * V_8 ,
void * V_638 , T_2 V_352 , T_6 V_657 , unsigned char * V_54 ,
int V_110 )
{
int V_658 = V_517 ;
struct V_9 * V_72 ;
V_10 -> V_110 = V_642 ;
V_10 -> V_86 . V_89 = 0 ;
if ( V_638 != NULL && V_352 > 0 ) {
V_10 -> V_86 . V_87 = 1 ;
V_10 -> V_86 . V_210 = F_115 ( 1 ) ;
} else {
V_10 -> V_86 . V_87 = 0 ;
V_10 -> V_86 . V_210 = F_115 ( 0 ) ;
}
memcpy ( V_10 -> V_86 . V_264 . V_265 , V_54 , 8 ) ;
if ( V_110 == V_306 ) {
switch ( V_215 ) {
case V_305 :
if ( V_657 & V_314 ) {
V_10 -> V_104 . V_105 [ 1 ] = 0x01 ;
V_10 -> V_104 . V_105 [ 2 ] = ( V_657 & 0xff ) ;
}
V_10 -> V_104 . V_260 = 6 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_516 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_305 ;
V_10 -> V_104 . V_105 [ 4 ] = V_352 & 0xFF ;
break;
case V_345 :
case V_346 :
V_10 -> V_104 . V_260 = 12 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_516 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_215 ;
V_10 -> V_104 . V_105 [ 6 ] = ( V_352 >> 24 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 7 ] = ( V_352 >> 16 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 8 ] = ( V_352 >> 8 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 9 ] = V_352 & 0xFF ;
break;
case V_659 :
V_10 -> V_104 . V_260 = 12 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 ,
V_514 , V_515 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_102 ;
V_10 -> V_104 . V_105 [ 6 ] = V_660 ;
V_10 -> V_104 . V_105 [ 7 ] = ( V_352 >> 8 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 8 ] = V_352 & 0xFF ;
break;
case V_359 :
V_10 -> V_104 . V_260 = 6 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_517 ) ;
V_10 -> V_104 . V_512 = 0 ;
break;
case V_332 :
V_10 -> V_104 . V_260 = 12 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_516 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_661 ;
V_10 -> V_104 . V_105 [ 1 ] = V_215 ;
V_10 -> V_104 . V_105 [ 6 ] = ( V_352 >> 24 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 7 ] = ( V_352 >> 16 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 8 ] = ( V_352 >> 8 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 9 ] = V_352 & 0xFF ;
break;
case V_310 :
V_10 -> V_104 . V_260 = 10 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_516 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_662 ;
V_10 -> V_104 . V_105 [ 6 ] = V_310 ;
V_10 -> V_104 . V_105 [ 7 ] = ( V_352 >> 16 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 8 ] = ( V_352 >> 8 ) & 0xFF ;
break;
case V_335 :
V_10 -> V_104 . V_260 = 10 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_516 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_662 ;
V_10 -> V_104 . V_105 [ 6 ] = V_335 ;
V_10 -> V_104 . V_105 [ 7 ] = ( V_352 >> 16 ) & 0xFF ;
V_10 -> V_104 . V_105 [ 8 ] = ( V_352 >> 8 ) & 0XFF ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_189 , V_215 ) ;
F_168 () ;
return - 1 ;
}
} else if ( V_110 == V_313 ) {
switch ( V_215 ) {
case V_312 :
V_10 -> V_104 . V_260 = 16 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 , V_514 , V_517 ) ;
V_10 -> V_104 . V_512 = 0 ;
memset ( & V_10 -> V_104 . V_105 [ 0 ] , 0 , sizeof( V_10 -> V_104 . V_105 ) ) ;
V_10 -> V_104 . V_105 [ 0 ] = V_215 ;
V_10 -> V_104 . V_105 [ 1 ] = V_560 ;
V_10 -> V_104 . V_105 [ 4 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 5 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 6 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 7 ] = 0x00 ;
break;
case V_568 :
V_72 = V_638 ;
F_216 ( & V_8 -> V_15 -> V_16 ,
L_190 ,
V_72 -> V_86 . V_263 , V_10 -> V_86 . V_263 ) ;
V_10 -> V_104 . V_260 = 16 ;
V_10 -> V_104 . V_513 =
F_196 ( V_110 ,
V_514 , V_515 ) ;
V_10 -> V_104 . V_512 = 0 ;
V_10 -> V_104 . V_105 [ 0 ] = V_663 ;
V_10 -> V_104 . V_105 [ 1 ] = V_664 ;
V_10 -> V_104 . V_105 [ 2 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 3 ] = 0x00 ;
memcpy ( & V_10 -> V_104 . V_105 [ 4 ] , & V_72 -> V_86 . V_263 ,
sizeof( V_72 -> V_86 . V_263 ) ) ;
V_10 -> V_104 . V_105 [ 12 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 13 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 14 ] = 0x00 ;
V_10 -> V_104 . V_105 [ 15 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_191 ,
V_215 ) ;
F_168 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_192 , V_110 ) ;
F_168 () ;
}
switch ( F_242 ( V_10 -> V_104 . V_513 ) ) {
case V_516 :
V_658 = V_308 ;
break;
case V_515 :
V_658 = V_212 ;
break;
case V_517 :
V_658 = V_291 ;
break;
default:
V_658 = V_643 ;
}
if ( F_117 ( V_8 -> V_15 , V_10 , V_638 , V_352 , V_658 ) )
return - 1 ;
return 0 ;
}
static void T_14 * F_243 ( T_15 V_665 , T_15 V_352 )
{
T_15 V_666 = ( ( T_15 ) V_665 ) & V_667 ;
T_15 V_668 = ( ( T_15 ) V_665 ) - V_666 ;
void T_14 * V_669 = F_244 ( V_666 ,
V_668 + V_352 ) ;
return V_669 ? ( V_669 + V_668 ) : NULL ;
}
static inline unsigned long F_245 ( struct V_1 * V_8 , T_4 V_71 )
{
return V_8 -> V_77 . V_78 ( V_8 , V_71 ) ;
}
static inline bool F_246 ( struct V_1 * V_8 )
{
return V_8 -> V_77 . V_670 ( V_8 ) ;
}
static inline long F_247 ( struct V_1 * V_8 )
{
return ( V_8 -> V_77 . V_670 ( V_8 ) == 0 ) ||
( V_8 -> V_671 == 0 ) ;
}
static inline int F_248 ( struct V_1 * V_8 , T_3 V_672 ,
T_3 V_673 )
{
if ( F_32 ( V_672 >= V_8 -> V_189 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_193 , V_673 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_249 ( struct V_9 * V_10 )
{
F_43 ( V_10 -> V_8 , V_10 ) ;
if ( F_35 ( V_10 -> V_110 == V_111 || V_10 -> V_110 == V_255
|| V_10 -> V_110 == V_114 ) )
F_111 ( V_10 ) ;
else if ( V_10 -> V_110 == V_642 )
F_250 ( V_10 -> V_294 ) ;
}
static inline T_3 F_251 ( struct V_1 * V_8 , T_3 V_263 )
{
#define F_252 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_253 0x03
if ( F_32 ( ! ( V_8 -> V_48 & V_49 ) ) )
return V_263 & ~ F_253 ;
return V_263 & ~ F_252 ;
}
static inline void F_254 ( struct V_1 * V_8 ,
T_3 V_673 )
{
T_3 V_672 ;
struct V_9 * V_10 ;
V_672 = V_673 >> V_475 ;
if ( ! F_248 ( V_8 , V_672 , V_673 ) ) {
V_10 = V_8 -> V_589 + V_672 ;
F_249 ( V_10 ) ;
}
}
static int F_255 ( struct V_1 * V_8 )
{
if ( F_35 ( ! V_674 ) )
return 0 ;
if ( F_35 ( V_8 -> V_671 ) )
return 0 ;
F_56 ( & V_8 -> V_15 -> V_16 , L_194
L_195 ) ;
return 1 ;
}
static struct V_1 * F_256 ( T_4 * V_675 )
{
return F_197 ( ( V_675 - * V_675 ) , struct V_1 , V_71 [ 0 ] ) ;
}
static T_16 F_257 ( int V_546 , void * V_675 )
{
struct V_1 * V_8 = F_256 ( V_675 ) ;
T_4 V_71 = * ( T_4 * ) V_675 ;
T_3 V_673 ;
if ( F_255 ( V_8 ) )
return V_676 ;
if ( F_247 ( V_8 ) )
return V_676 ;
V_8 -> V_677 = F_258 () ;
while ( F_246 ( V_8 ) ) {
V_673 = F_245 ( V_8 , V_71 ) ;
while ( V_673 != V_82 )
V_673 = F_31 ( V_8 , V_71 ) ;
}
return V_678 ;
}
static T_16 F_259 ( int V_546 , void * V_675 )
{
struct V_1 * V_8 = F_256 ( V_675 ) ;
T_3 V_673 ;
T_4 V_71 = * ( T_4 * ) V_675 ;
if ( F_255 ( V_8 ) )
return V_676 ;
V_8 -> V_677 = F_258 () ;
V_673 = F_245 ( V_8 , V_71 ) ;
while ( V_673 != V_82 )
V_673 = F_31 ( V_8 , V_71 ) ;
return V_678 ;
}
static T_16 F_260 ( int V_546 , void * V_675 )
{
struct V_1 * V_8 = F_256 ( ( T_4 * ) V_675 ) ;
T_3 V_673 ;
T_4 V_71 = * ( T_4 * ) V_675 ;
if ( F_247 ( V_8 ) )
return V_676 ;
V_8 -> V_677 = F_258 () ;
while ( F_246 ( V_8 ) ) {
V_673 = F_245 ( V_8 , V_71 ) ;
while ( V_673 != V_82 ) {
F_254 ( V_8 , V_673 ) ;
V_673 = F_31 ( V_8 , V_71 ) ;
}
}
return V_678 ;
}
static T_16 F_261 ( int V_546 , void * V_675 )
{
struct V_1 * V_8 = F_256 ( V_675 ) ;
T_3 V_673 ;
T_4 V_71 = * ( T_4 * ) V_675 ;
V_8 -> V_677 = F_258 () ;
V_673 = F_245 ( V_8 , V_71 ) ;
while ( V_673 != V_82 ) {
F_254 ( V_8 , V_673 ) ;
V_673 = F_31 ( V_8 , V_71 ) ;
}
return V_678 ;
}
static int F_262 ( struct V_285 * V_15 , unsigned char V_679 ,
unsigned char type )
{
struct V_680 {
struct V_681 V_682 ;
struct V_683 V_104 ;
struct V_684 V_685 ;
};
struct V_680 * V_215 ;
static const T_2 V_686 = sizeof( * V_215 ) +
sizeof( V_215 -> V_685 ) ;
V_288 V_687 ;
V_370 V_688 ;
T_3 V_263 ;
void T_14 * V_112 ;
int V_51 , V_599 ;
V_112 = F_263 ( V_15 , 0 ) ;
if ( V_112 == NULL )
return - V_199 ;
V_599 = F_264 ( V_15 , F_265 ( 32 ) ) ;
if ( V_599 ) {
F_266 ( V_112 ) ;
return V_599 ;
}
V_215 = F_267 ( V_15 , V_686 , & V_687 ) ;
if ( V_215 == NULL ) {
F_266 ( V_112 ) ;
return - V_199 ;
}
V_688 = F_98 ( V_687 ) ;
V_215 -> V_682 . V_89 = 0 ;
V_215 -> V_682 . V_87 = 0 ;
V_215 -> V_682 . V_210 = F_115 ( 0 ) ;
V_215 -> V_682 . V_263 = F_101 ( V_687 ) ;
memset ( & V_215 -> V_682 . V_264 . V_265 , 0 , 8 ) ;
V_215 -> V_104 . V_260 = 16 ;
V_215 -> V_104 . V_513 =
F_196 ( V_313 , V_689 , V_517 ) ;
V_215 -> V_104 . V_512 = 0 ;
V_215 -> V_104 . V_105 [ 0 ] = V_679 ;
V_215 -> V_104 . V_105 [ 1 ] = type ;
memset ( & V_215 -> V_104 . V_105 [ 2 ] , 0 , 14 ) ;
V_215 -> V_685 . V_213 =
F_101 ( ( F_105 ( V_688 ) + sizeof( * V_215 ) ) ) ;
V_215 -> V_685 . V_211 = F_98 ( sizeof( struct V_248 ) ) ;
F_46 ( F_105 ( V_688 ) , V_112 + V_113 ) ;
for ( V_51 = 0 ; V_51 < V_690 ; V_51 ++ ) {
V_263 = F_268 ( V_112 + V_691 ) ;
if ( ( V_263 & ~ F_253 ) == V_687 )
break;
F_127 ( V_692 ) ;
}
F_266 ( V_112 ) ;
if ( V_51 == V_690 ) {
F_55 ( & V_15 -> V_16 , L_196 ,
V_679 , type ) ;
return - V_693 ;
}
F_269 ( V_15 , V_686 , V_215 , V_687 ) ;
if ( V_263 & V_694 ) {
F_55 ( & V_15 -> V_16 , L_197 ,
V_679 , type ) ;
return - V_695 ;
}
F_56 ( & V_15 -> V_16 , L_198 ,
V_679 , type ) ;
return 0 ;
}
static int F_270 ( struct V_285 * V_15 ,
void T_14 * V_112 , T_3 V_696 )
{
if ( V_696 ) {
F_56 ( & V_15 -> V_16 , L_199 ) ;
F_46 ( V_696 , V_112 + V_697 ) ;
F_127 ( 10000 ) ;
} else {
int V_296 = 0 ;
F_56 ( & V_15 -> V_16 , L_200 ) ;
V_296 = F_271 ( V_15 , V_698 ) ;
if ( V_296 )
return V_296 ;
F_127 ( 500 ) ;
V_296 = F_271 ( V_15 , V_699 ) ;
if ( V_296 )
return V_296 ;
F_127 ( 500 ) ;
}
return 0 ;
}
static void F_272 ( char * V_700 , int V_34 )
{
memset ( V_700 , 0 , V_34 ) ;
strncpy ( V_700 , V_17 L_201 V_636 , V_34 - 1 ) ;
}
static int F_273 ( struct V_701 T_14 * V_702 )
{
char * V_700 ;
int V_51 , V_352 = sizeof( V_702 -> V_700 ) ;
V_700 = F_75 ( V_352 , V_155 ) ;
if ( ! V_700 )
return - V_199 ;
F_272 ( V_700 , V_352 ) ;
for ( V_51 = 0 ; V_51 < V_352 ; V_51 ++ )
F_274 ( V_700 [ V_51 ] , & V_702 -> V_700 [ V_51 ] ) ;
F_64 ( V_700 ) ;
return 0 ;
}
static void F_275 ( struct V_701 T_14 * V_702 ,
unsigned char * V_703 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < sizeof( V_702 -> V_700 ) ; V_51 ++ )
V_703 [ V_51 ] = F_276 ( & V_702 -> V_700 [ V_51 ] ) ;
}
static int F_277 ( struct V_701 T_14 * V_702 )
{
char * V_703 , * V_704 ;
int V_296 , V_352 = sizeof( V_702 -> V_700 ) ;
V_704 = F_75 ( 2 * V_352 , V_155 ) ;
if ( ! V_704 )
return - V_199 ;
V_703 = V_704 + V_352 ;
F_272 ( V_704 , V_352 ) ;
F_275 ( V_702 , V_703 ) ;
V_296 = ! memcmp ( V_703 , V_704 , V_352 ) ;
F_64 ( V_704 ) ;
return V_296 ;
}
static int F_278 ( struct V_285 * V_15 )
{
T_5 V_705 ;
T_3 V_706 ;
T_5 V_707 ;
void T_14 * V_112 ;
unsigned long V_708 ;
T_3 V_709 ;
int V_296 ;
struct V_701 T_14 * V_702 ;
T_3 V_696 ;
T_3 V_50 ;
T_6 V_710 ;
V_296 = F_279 ( V_15 , & V_50 ) ;
if ( V_296 < 0 ) {
F_5 ( & V_15 -> V_16 , L_202 ) ;
return V_296 ;
}
if ( ! F_21 ( V_50 ) ) {
F_5 ( & V_15 -> V_16 , L_203 ) ;
return - V_62 ;
}
if ( ! F_18 ( V_50 ) )
return - V_711 ;
F_280 ( V_15 , 4 , & V_710 ) ;
F_281 ( V_15 ) ;
V_296 = F_282 ( V_15 , & V_708 ) ;
if ( V_296 )
return V_296 ;
V_112 = F_243 ( V_708 , 0x250 ) ;
if ( ! V_112 )
return - V_199 ;
V_296 = F_283 ( V_15 , V_112 , & V_706 ,
& V_707 , & V_705 ) ;
if ( V_296 )
goto V_712;
V_702 = F_243 ( F_284 ( V_15 ,
V_707 ) + V_705 , sizeof( * V_702 ) ) ;
if ( ! V_702 ) {
V_296 = - V_199 ;
goto V_712;
}
V_296 = F_273 ( V_702 ) ;
if ( V_296 )
goto V_713;
V_709 = F_268 ( & V_702 -> V_709 ) ;
V_696 = V_709 & V_714 ;
if ( V_696 ) {
V_696 = V_715 ;
} else {
V_696 = V_709 & V_716 ;
if ( V_696 ) {
F_5 ( & V_15 -> V_16 ,
L_204 ) ;
V_296 = - V_711 ;
goto V_713;
}
}
V_296 = F_270 ( V_15 , V_112 , V_696 ) ;
if ( V_296 )
goto V_713;
F_285 ( V_15 ) ;
F_286 ( V_15 , 4 , V_710 ) ;
F_127 ( V_717 ) ;
V_296 = F_287 ( V_15 , V_112 , V_718 ) ;
if ( V_296 ) {
F_5 ( & V_15 -> V_16 ,
L_205 ) ;
goto V_713;
}
V_296 = F_277 ( V_112 ) ;
if ( V_296 < 0 )
goto V_713;
if ( V_296 ) {
F_5 ( & V_15 -> V_16 , L_206
L_207 ) ;
V_296 = - V_711 ;
} else {
F_56 ( & V_15 -> V_16 , L_208 ) ;
}
V_713:
F_266 ( V_702 ) ;
V_712:
F_266 ( V_112 ) ;
return V_296 ;
}
static void F_288 ( struct V_28 * V_16 , struct V_701 T_14 * V_719 )
{
#ifdef F_289
int V_51 ;
char V_720 [ 17 ] ;
F_56 ( V_16 , L_209 ) ;
F_56 ( V_16 , L_210 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
V_720 [ V_51 ] = F_276 ( & ( V_719 -> V_721 [ V_51 ] ) ) ;
V_720 [ 4 ] = '\0' ;
F_56 ( V_16 , L_211 , V_720 ) ;
F_56 ( V_16 , L_212 , F_268 ( & ( V_719 -> V_722 ) ) ) ;
F_56 ( V_16 , L_213 ,
F_268 ( & ( V_719 -> V_723 ) ) ) ;
F_56 ( V_16 , L_214 ,
F_268 ( & ( V_719 -> V_724 ) ) ) ;
F_56 ( V_16 , L_215 ,
F_268 ( & ( V_719 -> V_725 . V_726 ) ) ) ;
F_56 ( V_16 , L_216 ,
F_268 ( & ( V_719 -> V_725 . V_727 ) ) ) ;
F_56 ( V_16 , L_217 ,
F_268 ( & ( V_719 -> V_725 . V_728 ) ) ) ;
F_56 ( V_16 , L_218 ,
F_268 ( & ( V_719 -> V_729 ) ) ) ;
F_56 ( V_16 , L_219 , F_268 ( & ( V_719 -> V_730 ) ) ) ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_720 [ V_51 ] = F_276 ( & ( V_719 -> V_731 [ V_51 ] ) ) ;
V_720 [ 16 ] = '\0' ;
F_56 ( V_16 , L_220 , V_720 ) ;
F_56 ( V_16 , L_221 ,
F_268 ( & ( V_719 -> V_732 ) ) ) ;
#endif
}
static int F_290 ( struct V_285 * V_15 , unsigned long V_733 )
{
int V_51 , V_586 , V_734 , V_735 ;
if ( V_733 == V_736 )
return 0 ;
V_586 = 0 ;
for ( V_51 = 0 ; V_51 < V_737 ; V_51 ++ ) {
V_735 = F_291 ( V_15 , V_51 ) & V_738 ;
if ( V_735 == V_739 )
V_586 += 4 ;
else {
V_734 = F_291 ( V_15 , V_51 ) &
V_740 ;
switch ( V_734 ) {
case V_741 :
case V_742 :
V_586 += 4 ;
break;
case V_743 :
V_586 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_222 ) ;
return - 1 ;
break;
}
}
if ( V_586 == V_733 - V_736 )
return V_51 + 1 ;
}
return - 1 ;
}
static void F_292 ( struct V_1 * V_8 )
{
#ifdef F_293
int V_599 , V_51 ;
struct V_744 V_745 [ V_746 ] ;
for ( V_51 = 0 ; V_51 < V_746 ; V_51 ++ ) {
V_745 [ V_51 ] . V_747 = 0 ;
V_745 [ V_51 ] . V_134 = V_51 ;
}
if ( ( V_8 -> V_50 == 0x40700E11 ) || ( V_8 -> V_50 == 0x40800E11 ) ||
( V_8 -> V_50 == 0x40820E11 ) || ( V_8 -> V_50 == 0x40830E11 ) )
goto V_748;
if ( F_294 ( V_8 -> V_15 , V_749 ) ) {
F_56 ( & V_8 -> V_15 -> V_16 , L_223 ) ;
V_8 -> V_88 = V_746 ;
if ( V_8 -> V_88 > F_295 () )
V_8 -> V_88 = F_295 () ;
V_599 = F_296 ( V_8 -> V_15 , V_745 ,
1 , V_8 -> V_88 ) ;
if ( V_599 < 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_224 , V_599 ) ;
V_8 -> V_88 = 0 ;
goto V_750;
} else if ( V_599 < V_8 -> V_88 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_225
L_226 , V_599 ) ;
}
V_8 -> V_88 = V_599 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_88 ; V_51 ++ )
V_8 -> V_547 [ V_51 ] = V_745 [ V_51 ] . V_747 ;
return;
}
V_750:
if ( F_294 ( V_8 -> V_15 , V_751 ) ) {
F_56 ( & V_8 -> V_15 -> V_16 , L_227 ) ;
if ( ! F_297 ( V_8 -> V_15 ) )
V_8 -> V_752 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_228 ) ;
}
V_748:
#endif
V_8 -> V_547 [ V_8 -> V_548 ] = V_8 -> V_15 -> V_546 ;
}
static int F_279 ( struct V_285 * V_15 , T_3 * V_50 )
{
int V_51 ;
T_3 V_753 , V_754 ;
V_753 = V_15 -> V_755 ;
V_754 = V_15 -> V_756 ;
* V_50 = ( ( V_754 << 16 ) & 0xffff0000 ) |
V_753 ;
for ( V_51 = 0 ; V_51 < F_19 ( V_757 ) ; V_51 ++ )
if ( * V_50 == V_757 [ V_51 ] . V_50 )
return V_51 ;
if ( ( V_753 != V_758 &&
V_753 != V_759 ) ||
! V_760 ) {
F_5 ( & V_15 -> V_16 , L_229
L_230 , * V_50 ) ;
return - V_62 ;
}
return F_19 ( V_757 ) - 1 ;
}
static int F_282 ( struct V_285 * V_15 ,
unsigned long * V_761 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_737 ; V_51 ++ )
if ( F_291 ( V_15 , V_51 ) & V_762 ) {
* V_761 = F_284 ( V_15 , V_51 ) ;
F_216 ( & V_15 -> V_16 , L_231 ,
* V_761 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_232 ) ;
return - V_62 ;
}
static int F_287 ( struct V_285 * V_15 , void T_14 * V_112 ,
int V_763 )
{
int V_51 , V_764 ;
T_3 V_765 ;
if ( V_763 )
V_764 = V_766 ;
else
V_764 = V_767 ;
for ( V_51 = 0 ; V_51 < V_764 ; V_51 ++ ) {
V_765 = F_268 ( V_112 + V_768 ) ;
if ( V_763 ) {
if ( V_765 == V_769 )
return 0 ;
} else {
if ( V_765 != V_769 )
return 0 ;
}
F_127 ( V_770 ) ;
}
F_5 ( & V_15 -> V_16 , L_233 ) ;
return - V_62 ;
}
static int F_283 ( struct V_285 * V_15 , void T_14 * V_112 ,
T_3 * V_706 , T_5 * V_707 ,
T_5 * V_705 )
{
* V_706 = F_268 ( V_112 + V_771 ) ;
* V_705 = F_268 ( V_112 + V_772 ) ;
* V_706 &= ( T_3 ) 0x0000ffff ;
* V_707 = F_290 ( V_15 , * V_706 ) ;
if ( * V_707 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_234 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_298 ( struct V_1 * V_8 )
{
T_5 V_705 ;
T_3 V_706 ;
T_5 V_707 ;
T_3 V_773 ;
int V_296 ;
V_296 = F_283 ( V_8 -> V_15 , V_8 -> V_112 , & V_706 ,
& V_707 , & V_705 ) ;
if ( V_296 )
return V_296 ;
V_8 -> V_702 = F_243 ( F_284 ( V_8 -> V_15 ,
V_707 ) + V_705 , sizeof( * V_8 -> V_702 ) ) ;
if ( ! V_8 -> V_702 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_235 ) ;
return - V_199 ;
}
V_296 = F_273 ( V_8 -> V_702 ) ;
if ( V_296 )
return V_296 ;
V_773 = F_268 ( & V_8 -> V_702 -> V_774 ) ;
V_8 -> V_775 = F_243 ( F_284 ( V_8 -> V_15 ,
V_707 ) + V_705 + V_773 ,
sizeof( * V_8 -> V_775 ) ) ;
if ( ! V_8 -> V_775 )
return - V_199 ;
return 0 ;
}
static void F_299 ( struct V_1 * V_8 )
{
V_8 -> V_83 = F_268 ( & ( V_8 -> V_702 -> V_776 ) ) ;
if ( V_674 && V_8 -> V_83 > 32 )
V_8 -> V_83 = 32 ;
if ( V_8 -> V_83 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_236
L_237
L_238 ,
V_8 -> V_83 ) ;
V_8 -> V_83 = 16 ;
}
}
static int F_300 ( struct V_1 * V_8 )
{
return V_8 -> V_422 > 512 ;
}
static void F_301 ( struct V_1 * V_8 )
{
F_299 ( V_8 ) ;
V_8 -> V_189 = V_8 -> V_83 ;
V_8 -> V_422 = F_268 ( & ( V_8 -> V_702 -> V_777 ) ) ;
V_8 -> V_365 = F_268 ( & ( V_8 -> V_702 -> V_709 ) ) ;
if ( F_300 ( V_8 ) ) {
V_8 -> V_207 = 32 ;
V_8 -> V_198 = V_8 -> V_422 - V_8 -> V_207 ;
V_8 -> V_422 -- ;
} else {
V_8 -> V_207 = 31 ;
V_8 -> V_422 = 31 ;
V_8 -> V_198 = 0 ;
}
V_8 -> V_578 = F_268 ( & ( V_8 -> V_702 -> V_578 ) ) ;
if ( ! ( V_577 & V_8 -> V_578 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_239 ) ;
if ( ! ( V_579 & V_8 -> V_578 ) )
F_5 ( & V_8 -> V_15 -> V_16 , L_240 ) ;
}
static inline bool F_302 ( struct V_1 * V_8 )
{
if ( ! F_303 ( V_8 -> V_702 -> V_721 , L_241 , 4 ) ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_242 ) ;
return false ;
}
return true ;
}
static inline void F_304 ( struct V_1 * V_8 )
{
T_3 V_778 ;
V_778 = F_268 ( & ( V_8 -> V_702 -> V_778 ) ) ;
#ifdef F_305
V_778 |= V_779 ;
#endif
V_778 |= V_780 ;
F_46 ( V_778 , & ( V_8 -> V_702 -> V_778 ) ) ;
}
static inline void F_306 ( struct V_1 * V_8 )
{
T_3 V_781 ;
if ( V_8 -> V_50 != 0x3225103C )
return;
V_781 = F_268 ( V_8 -> V_112 + V_782 ) ;
V_781 |= 0x8000 ;
F_46 ( V_781 , V_8 -> V_112 + V_782 ) ;
}
static int F_307 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_783 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_784 ; V_51 ++ ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_783 = F_268 ( V_8 -> V_112 + V_697 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_783 & V_785 ) )
goto V_786;
F_127 ( V_787 ) ;
}
return - V_62 ;
V_786:
return 0 ;
}
static int F_308 ( struct V_1 * V_8 )
{
int V_51 ;
T_3 V_783 ;
unsigned long V_59 ;
for ( V_51 = 0 ; V_51 < V_788 ; V_51 ++ ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_783 = F_268 ( V_8 -> V_112 + V_697 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( ! ( V_783 & V_789 ) )
goto V_786;
F_127 ( V_790 ) ;
}
return - V_62 ;
V_786:
return 0 ;
}
static int F_309 ( struct V_1 * V_8 )
{
T_3 V_791 ;
V_791 = F_268 ( & ( V_8 -> V_702 -> V_723 ) ) ;
if ( ! ( V_791 & V_792 ) )
return - V_711 ;
V_8 -> V_83 = F_268 ( & ( V_8 -> V_702 -> V_729 ) ) ;
F_46 ( V_793 , & ( V_8 -> V_702 -> V_725 . V_726 ) ) ;
F_46 ( 0 , & V_8 -> V_702 -> V_725 . V_794 ) ;
F_46 ( V_789 , V_8 -> V_112 + V_697 ) ;
if ( F_308 ( V_8 ) )
goto error;
F_288 ( & V_8 -> V_15 -> V_16 , V_8 -> V_702 ) ;
if ( ! ( F_268 ( & ( V_8 -> V_702 -> V_724 ) ) & V_793 ) )
goto error;
V_8 -> V_48 = V_793 ;
return 0 ;
error:
F_55 ( & V_8 -> V_15 -> V_16 , L_243 ) ;
return - V_62 ;
}
static int F_310 ( struct V_1 * V_8 )
{
int V_795 , V_599 ;
V_795 = F_279 ( V_8 -> V_15 , & V_8 -> V_50 ) ;
if ( V_795 < 0 )
return V_795 ;
V_8 -> V_796 = V_757 [ V_795 ] . V_796 ;
V_8 -> V_77 = * ( V_757 [ V_795 ] . V_77 ) ;
F_311 ( V_8 -> V_15 , V_797 |
V_798 | V_799 ) ;
V_599 = F_312 ( V_8 -> V_15 ) ;
if ( V_599 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_244 ) ;
return V_599 ;
}
V_599 = F_313 ( V_8 -> V_15 , V_17 ) ;
if ( V_599 ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_245 ) ;
return V_599 ;
}
F_314 ( V_8 -> V_15 ) ;
F_292 ( V_8 ) ;
V_599 = F_282 ( V_8 -> V_15 , & V_8 -> V_708 ) ;
if ( V_599 )
goto V_800;
V_8 -> V_112 = F_243 ( V_8 -> V_708 , 0x250 ) ;
if ( ! V_8 -> V_112 ) {
V_599 = - V_199 ;
goto V_800;
}
V_599 = F_287 ( V_8 -> V_15 , V_8 -> V_112 , V_718 ) ;
if ( V_599 )
goto V_800;
V_599 = F_298 ( V_8 ) ;
if ( V_599 )
goto V_800;
F_301 ( V_8 ) ;
if ( ! F_302 ( V_8 ) ) {
V_599 = - V_62 ;
goto V_800;
}
F_304 ( V_8 ) ;
F_306 ( V_8 ) ;
V_599 = F_309 ( V_8 ) ;
if ( V_599 )
goto V_800;
return 0 ;
V_800:
if ( V_8 -> V_775 )
F_266 ( V_8 -> V_775 ) ;
if ( V_8 -> V_702 )
F_266 ( V_8 -> V_702 ) ;
if ( V_8 -> V_112 )
F_266 ( V_8 -> V_112 ) ;
F_315 ( V_8 -> V_15 ) ;
F_316 ( V_8 -> V_15 ) ;
return V_599 ;
}
static void F_317 ( struct V_1 * V_8 )
{
int V_296 ;
#define F_318 64
V_8 -> V_46 = F_75 ( F_318 , V_155 ) ;
if ( ! V_8 -> V_46 )
return;
V_296 = F_130 ( V_8 , V_117 , 0 ,
V_8 -> V_46 , F_318 ) ;
if ( V_296 != 0 ) {
F_64 ( V_8 -> V_46 ) ;
V_8 -> V_46 = NULL ;
}
}
static int F_319 ( struct V_285 * V_15 )
{
int V_296 , V_51 ;
void T_14 * V_112 ;
if ( ! V_674 )
return 0 ;
V_296 = F_312 ( V_15 ) ;
if ( V_296 ) {
F_5 ( & V_15 -> V_16 , L_246 ) ;
return - V_62 ;
}
F_315 ( V_15 ) ;
F_127 ( 260 ) ;
V_296 = F_312 ( V_15 ) ;
if ( V_296 ) {
F_5 ( & V_15 -> V_16 , L_247 ) ;
return - V_62 ;
}
F_314 ( V_15 ) ;
V_112 = F_263 ( V_15 , 0 ) ;
if ( V_112 == NULL ) {
V_296 = - V_199 ;
goto V_801;
}
F_46 ( V_802 , V_112 + V_803 ) ;
F_266 ( V_112 ) ;
V_296 = F_278 ( V_15 ) ;
if ( V_296 )
goto V_801;
F_56 ( & V_15 -> V_16 , L_248 ) ;
for ( V_51 = 0 ; V_51 < V_804 ; V_51 ++ ) {
if ( F_320 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_249 ,
( V_51 < 11 ? L_250 : L_251 ) ) ;
}
V_801:
F_315 ( V_15 ) ;
return V_296 ;
}
static int F_321 ( struct V_1 * V_8 )
{
V_8 -> V_588 = F_83 (
F_322 ( V_8 -> V_189 , V_504 ) *
sizeof( unsigned long ) , V_155 ) ;
V_8 -> V_589 = F_267 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_589 ) ,
& ( V_8 -> V_590 ) ) ;
V_8 -> V_591 = F_267 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_591 ) ,
& ( V_8 -> V_592 ) ) ;
if ( ( V_8 -> V_588 == NULL )
|| ( V_8 -> V_589 == NULL )
|| ( V_8 -> V_591 == NULL ) ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_252 , V_156 ) ;
goto V_805;
}
return 0 ;
V_805:
F_323 ( V_8 ) ;
return - V_199 ;
}
static void F_323 ( struct V_1 * V_8 )
{
F_64 ( V_8 -> V_588 ) ;
if ( V_8 -> V_589 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( struct V_9 ) ,
V_8 -> V_589 , V_8 -> V_590 ) ;
if ( V_8 -> V_98 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_98 ) ,
V_8 -> V_98 , V_8 -> V_462 ) ;
if ( V_8 -> V_591 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( struct V_248 ) ,
V_8 -> V_591 ,
V_8 -> V_592 ) ;
if ( V_8 -> V_93 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( struct V_91 ) ,
V_8 -> V_93 , V_8 -> V_442 ) ;
}
static void F_324 ( struct V_1 * V_8 )
{
int V_51 , V_295 ;
V_295 = F_325 ( V_806 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_88 ; V_51 ++ ) {
F_326 ( V_8 -> V_547 [ V_51 ] , F_327 ( V_295 ) ) ;
V_295 = F_328 ( V_295 , V_806 ) ;
}
}
static void F_329 ( struct V_1 * V_8 )
{
int V_51 ;
if ( ! V_8 -> V_88 || V_8 -> V_548 != V_807 ) {
V_51 = V_8 -> V_548 ;
F_326 ( V_8 -> V_547 [ V_51 ] , NULL ) ;
F_330 ( V_8 -> V_547 [ V_51 ] , & V_8 -> V_71 [ V_51 ] ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_8 -> V_88 ; V_51 ++ ) {
F_326 ( V_8 -> V_547 [ V_51 ] , NULL ) ;
F_330 ( V_8 -> V_547 [ V_51 ] , & V_8 -> V_71 [ V_51 ] ) ;
}
for (; V_51 < V_746 ; V_51 ++ )
V_8 -> V_71 [ V_51 ] = 0 ;
}
static int F_331 ( struct V_1 * V_8 ,
T_16 (* F_332)( int , void * ) ,
T_16 (* F_333)( int , void * ) )
{
int V_296 , V_51 ;
for ( V_51 = 0 ; V_51 < V_746 ; V_51 ++ )
V_8 -> V_71 [ V_51 ] = ( T_4 ) V_51 ;
if ( V_8 -> V_548 == V_807 && V_8 -> V_88 > 0 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_88 ; V_51 ++ ) {
V_296 = F_334 ( V_8 -> V_547 [ V_51 ] , F_332 ,
0 , V_8 -> V_808 ,
& V_8 -> V_71 [ V_51 ] ) ;
if ( V_296 ) {
int V_143 ;
F_55 ( & V_8 -> V_15 -> V_16 ,
L_253 ,
V_8 -> V_547 [ V_51 ] , V_8 -> V_808 ) ;
for ( V_143 = 0 ; V_143 < V_51 ; V_143 ++ ) {
F_330 ( V_8 -> V_547 [ V_143 ] , & V_8 -> V_71 [ V_143 ] ) ;
V_8 -> V_71 [ V_143 ] = 0 ;
}
for (; V_143 < V_746 ; V_143 ++ )
V_8 -> V_71 [ V_143 ] = 0 ;
return V_296 ;
}
}
F_324 ( V_8 ) ;
} else {
if ( V_8 -> V_88 > 0 || V_8 -> V_752 ) {
V_296 = F_334 ( V_8 -> V_547 [ V_8 -> V_548 ] ,
F_332 , 0 , V_8 -> V_808 ,
& V_8 -> V_71 [ V_8 -> V_548 ] ) ;
} else {
V_296 = F_334 ( V_8 -> V_547 [ V_8 -> V_548 ] ,
F_333 , V_809 , V_8 -> V_808 ,
& V_8 -> V_71 [ V_8 -> V_548 ] ) ;
}
}
if ( V_296 ) {
F_55 ( & V_8 -> V_15 -> V_16 , L_254 ,
V_8 -> V_547 [ V_8 -> V_548 ] , V_8 -> V_808 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_335 ( struct V_1 * V_8 )
{
if ( F_241 ( V_8 , V_117 ,
V_810 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_255 ) ;
return - V_695 ;
}
F_56 ( & V_8 -> V_15 -> V_16 , L_256 ) ;
if ( F_287 ( V_8 -> V_15 , V_8 -> V_112 , V_811 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_257 ) ;
return - 1 ;
}
F_56 ( & V_8 -> V_15 -> V_16 , L_258 ) ;
if ( F_287 ( V_8 -> V_15 , V_8 -> V_112 , V_718 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_259
L_260 ) ;
return - 1 ;
}
return 0 ;
}
static void F_336 ( struct V_1 * V_8 )
{
F_329 ( V_8 ) ;
#ifdef F_293
if ( V_8 -> V_88 ) {
if ( V_8 -> V_15 -> V_812 )
F_337 ( V_8 -> V_15 ) ;
} else if ( V_8 -> V_752 ) {
if ( V_8 -> V_15 -> V_813 )
F_338 ( V_8 -> V_15 ) ;
}
#endif
}
static void F_339 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
if ( ! V_8 -> V_75 [ V_51 ] . V_79 )
continue;
F_269 ( V_8 -> V_15 , V_8 -> V_814 ,
V_8 -> V_75 [ V_51 ] . V_79 , V_8 -> V_75 [ V_51 ] . V_84 ) ;
V_8 -> V_75 [ V_51 ] . V_79 = NULL ;
V_8 -> V_75 [ V_51 ] . V_84 = 0 ;
}
}
static void F_340 ( struct V_1 * V_8 )
{
F_336 ( V_8 ) ;
F_95 ( V_8 ) ;
F_323 ( V_8 ) ;
F_64 ( V_8 -> V_95 ) ;
F_64 ( V_8 -> V_85 ) ;
F_339 ( V_8 ) ;
if ( V_8 -> V_112 )
F_266 ( V_8 -> V_112 ) ;
if ( V_8 -> V_775 )
F_266 ( V_8 -> V_775 ) ;
if ( V_8 -> V_702 )
F_266 ( V_8 -> V_702 ) ;
F_315 ( V_8 -> V_15 ) ;
F_316 ( V_8 -> V_15 ) ;
F_64 ( V_8 ) ;
}
static void F_341 ( struct V_1 * V_8 )
{
int V_51 , V_576 ;
struct V_9 * V_10 ;
F_342 ( V_8 -> V_247 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_189 ; V_51 ++ ) {
V_10 = V_8 -> V_589 + V_51 ;
V_576 = F_191 ( & V_10 -> V_576 ) ;
if ( V_576 > 1 ) {
V_10 -> V_11 -> V_23 = V_276 ;
F_249 ( V_10 ) ;
}
F_108 ( V_8 , V_10 ) ;
}
}
static void F_343 ( struct V_1 * V_8 , T_3 V_815 )
{
int V_51 , V_295 ;
V_295 = F_325 ( V_806 ) ;
for ( V_51 = 0 ; V_51 < F_295 () ; V_51 ++ ) {
T_3 * F_121 ;
F_121 = F_123 ( V_8 -> F_121 , V_295 ) ;
* F_121 = V_815 ;
V_295 = F_328 ( V_295 , V_806 ) ;
}
F_60 () ;
}
static void F_344 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
T_3 F_121 ;
V_8 -> V_77 . V_816 ( V_8 , V_817 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
F_121 = F_268 ( V_8 -> V_112 + V_768 ) ;
if ( ! F_121 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_261 ) ;
F_121 = 0xffffffff ;
}
F_343 ( V_8 , F_121 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_262 ,
F_121 ) ;
F_315 ( V_8 -> V_15 ) ;
F_341 ( V_8 ) ;
}
static void F_345 ( struct V_1 * V_8 )
{
T_5 V_818 ;
T_3 V_819 ;
unsigned long V_59 ;
V_818 = F_258 () ;
if ( F_346 ( V_8 -> V_677 +
( V_8 -> V_107 ) , V_818 ) )
return;
if ( F_346 ( V_8 -> V_820 +
( V_8 -> V_107 ) , V_818 ) )
return;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_819 = F_268 ( & V_8 -> V_702 -> V_732 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
if ( V_8 -> V_821 == V_819 ) {
F_344 ( V_8 ) ;
return;
}
V_8 -> V_821 = V_819 ;
V_8 -> V_820 = V_818 ;
}
static void F_347 ( struct V_1 * V_8 )
{
int V_51 ;
char * V_822 ;
if ( ! ( V_8 -> V_365 & V_823 ) )
return;
if ( ( V_8 -> V_48 & ( V_76
| V_411 ) ) &&
( V_8 -> V_824 & V_825 ||
V_8 -> V_824 & V_826 ) ) {
if ( V_8 -> V_824 & V_825 )
V_822 = L_263 ;
if ( V_8 -> V_824 & V_826 )
V_822 = L_264 ;
F_348 ( V_8 -> V_44 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
V_8 -> V_16 [ V_51 ] -> V_70 = 0 ;
F_349 ( V_8 ) ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_265 ,
V_8 -> V_824 , V_822 ) ;
F_46 ( V_8 -> V_824 , & ( V_8 -> V_702 -> V_827 ) ) ;
F_46 ( V_785 , V_8 -> V_112 + V_697 ) ;
F_307 ( V_8 ) ;
F_350 ( V_8 -> V_44 ) ;
} else {
F_46 ( V_8 -> V_824 , & ( V_8 -> V_702 -> V_827 ) ) ;
F_46 ( V_785 , V_8 -> V_112 + V_697 ) ;
F_307 ( V_8 ) ;
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int F_351 ( struct V_1 * V_8 )
{
if ( ! ( V_8 -> V_365 & V_823 ) )
return 0 ;
V_8 -> V_824 = F_268 ( & ( V_8 -> V_702 -> V_828 ) ) ;
return V_8 -> V_824 & V_829 ;
}
static int F_352 ( struct V_1 * V_8 )
{
unsigned long V_59 ;
struct V_153 * V_301 ;
struct V_830 * V_831 , * V_832 ;
F_26 ( & V_8 -> V_154 , V_59 ) ;
F_353 (this, tmp, &h->offline_device_list) {
V_301 = F_354 ( V_831 , struct V_153 ,
V_157 ) ;
F_27 ( & V_8 -> V_154 , V_59 ) ;
if ( ! F_150 ( V_8 , V_301 -> V_54 ) ) {
F_26 ( & V_8 -> V_154 , V_59 ) ;
F_355 ( & V_301 -> V_157 ) ;
F_27 ( & V_8 -> V_154 , V_59 ) ;
return 1 ;
}
F_26 ( & V_8 -> V_154 , V_59 ) ;
}
F_27 ( & V_8 -> V_154 , V_59 ) ;
return 0 ;
}
static void F_356 ( struct V_521 * V_245 )
{
unsigned long V_59 ;
struct V_1 * V_8 = F_197 ( F_357 ( V_245 ) ,
struct V_1 , V_833 ) ;
if ( V_8 -> V_834 )
return;
if ( F_351 ( V_8 ) || F_352 ( V_8 ) ) {
F_358 ( V_8 -> V_44 ) ;
F_347 ( V_8 ) ;
F_12 ( V_8 -> V_44 ) ;
F_206 ( V_8 -> V_44 ) ;
}
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! V_8 -> V_834 )
F_359 ( V_8 -> V_835 , & V_8 -> V_833 ,
V_8 -> V_107 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static void F_360 ( struct V_521 * V_245 )
{
unsigned long V_59 ;
struct V_1 * V_8 = F_197 ( F_357 ( V_245 ) ,
struct V_1 , V_836 ) ;
F_345 ( V_8 ) ;
if ( F_121 ( V_8 ) )
return;
F_26 ( & V_8 -> V_60 , V_59 ) ;
if ( ! V_8 -> V_834 )
F_361 ( & V_8 -> V_836 ,
V_8 -> V_107 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
}
static struct V_837 * F_362 ( struct V_1 * V_8 ,
char * V_838 )
{
struct V_837 * V_839 = NULL ;
V_839 = F_363 ( L_266 , 0 , V_838 , V_8 -> V_18 ) ;
if ( ! V_839 )
F_55 ( & V_8 -> V_15 -> V_16 , L_267 , V_838 ) ;
return V_839 ;
}
static int F_364 ( struct V_285 * V_15 , const struct V_840 * V_841 )
{
int V_842 , V_296 ;
struct V_1 * V_8 ;
int V_843 = 0 ;
unsigned long V_59 ;
if ( V_844 == 0 )
F_365 (KERN_INFO DRIVER_NAME L_268 ) ;
V_296 = F_319 ( V_15 ) ;
if ( V_296 ) {
if ( V_296 != - V_711 )
return V_296 ;
V_843 = 1 ;
V_296 = 0 ;
}
V_845:
F_366 ( sizeof( struct V_9 ) % V_846 ) ;
V_8 = F_83 ( sizeof( * V_8 ) , V_155 ) ;
if ( ! V_8 )
return - V_199 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_548 = V_847 ? V_848 : V_807 ;
F_367 ( & V_8 -> V_158 ) ;
F_368 ( & V_8 -> V_60 ) ;
F_368 ( & V_8 -> V_154 ) ;
F_368 ( & V_8 -> V_525 ) ;
F_93 ( & V_8 -> V_654 , V_543 ) ;
V_8 -> V_835 = F_362 ( V_8 , L_269 ) ;
if ( ! V_8 -> V_835 ) {
V_296 = - V_199 ;
goto V_849;
}
V_8 -> V_247 = F_362 ( V_8 , L_270 ) ;
if ( ! V_8 -> V_247 ) {
V_296 = - V_199 ;
goto V_849;
}
V_8 -> F_121 = F_369 ( T_3 ) ;
if ( ! V_8 -> F_121 ) {
V_296 = - V_199 ;
goto V_849;
}
F_343 ( V_8 , 0 ) ;
V_296 = F_310 ( V_8 ) ;
if ( V_296 != 0 )
goto V_849;
sprintf ( V_8 -> V_808 , V_17 L_12 , V_844 ) ;
V_8 -> V_18 = V_844 ;
V_844 ++ ;
V_296 = F_370 ( V_15 , F_265 ( 64 ) ) ;
if ( V_296 == 0 ) {
V_842 = 1 ;
} else {
V_296 = F_370 ( V_15 , F_265 ( 32 ) ) ;
if ( V_296 == 0 ) {
V_842 = 0 ;
} else {
F_55 ( & V_15 -> V_16 , L_271 ) ;
goto V_849;
}
}
V_8 -> V_77 . V_816 ( V_8 , V_817 ) ;
if ( F_331 ( V_8 , F_261 , F_260 ) )
goto V_850;
F_56 ( & V_15 -> V_16 , L_272 ,
V_8 -> V_808 , V_15 -> V_28 ,
V_8 -> V_547 [ V_8 -> V_548 ] , V_842 ? L_251 : L_273 ) ;
V_296 = F_321 ( V_8 ) ;
if ( V_296 )
goto V_851;
if ( F_96 ( V_8 ) )
goto V_852;
F_371 ( & V_8 -> V_527 ) ;
V_8 -> V_526 = 1 ;
F_372 ( V_15 , V_8 ) ;
V_8 -> V_124 = 0 ;
V_8 -> V_398 = 0 ;
V_8 -> V_44 = NULL ;
F_368 ( & V_8 -> V_195 ) ;
F_373 ( V_8 ) ;
if ( V_843 ) {
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_77 . V_816 ( V_8 , V_817 ) ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_329 ( V_8 ) ;
V_296 = F_331 ( V_8 , F_259 ,
F_257 ) ;
if ( V_296 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_274 ) ;
goto V_852;
}
V_296 = F_335 ( V_8 ) ;
if ( V_296 )
goto V_852;
F_56 ( & V_8 -> V_15 -> V_16 , L_275 ) ;
F_56 ( & V_8 -> V_15 -> V_16 ,
L_276 ) ;
V_8 -> V_77 . V_816 ( V_8 , V_853 ) ;
F_127 ( 10000 ) ;
V_8 -> V_77 . V_816 ( V_8 , V_817 ) ;
V_296 = F_277 ( V_8 -> V_702 ) ;
if ( V_296 )
F_56 ( & V_8 -> V_15 -> V_16 ,
L_277 ) ;
F_340 ( V_8 ) ;
V_843 = 0 ;
if ( V_296 )
return - V_62 ;
goto V_845;
}
V_8 -> V_41 = 1 ;
V_8 -> V_77 . V_816 ( V_8 , V_853 ) ;
F_317 ( V_8 ) ;
F_207 ( V_8 ) ;
V_8 -> V_107 = V_109 ;
F_374 ( & V_8 -> V_836 , F_360 ) ;
F_361 ( & V_8 -> V_836 ,
V_8 -> V_107 ) ;
F_374 ( & V_8 -> V_833 , F_356 ) ;
F_359 ( V_8 -> V_835 , & V_8 -> V_833 ,
V_8 -> V_107 ) ;
return 0 ;
V_852:
F_95 ( V_8 ) ;
F_323 ( V_8 ) ;
V_851:
F_329 ( V_8 ) ;
V_850:
V_849:
if ( V_8 -> V_247 )
F_375 ( V_8 -> V_247 ) ;
if ( V_8 -> V_835 )
F_375 ( V_8 -> V_835 ) ;
if ( V_8 -> F_121 )
F_376 ( V_8 -> F_121 ) ;
F_64 ( V_8 ) ;
return V_296 ;
}
static void F_377 ( struct V_1 * V_8 )
{
char * V_854 ;
struct V_9 * V_10 ;
if ( F_32 ( F_121 ( V_8 ) ) )
return;
V_854 = F_83 ( 4 , V_155 ) ;
if ( ! V_854 )
return;
V_10 = F_131 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_107 ) ;
goto V_855;
}
if ( F_132 ( V_10 , V_659 , V_8 , V_854 , 4 , 0 ,
V_117 , V_306 ) ) {
goto V_307;
}
F_126 ( V_8 , V_10 , V_212 ) ;
if ( V_10 -> V_11 -> V_23 != 0 )
V_307:
F_5 ( & V_8 -> V_15 -> V_16 ,
L_278 ) ;
F_108 ( V_8 , V_10 ) ;
V_855:
F_64 ( V_854 ) ;
}
static void F_378 ( struct V_285 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_379 ( V_15 ) ;
F_377 ( V_8 ) ;
V_8 -> V_77 . V_816 ( V_8 , V_817 ) ;
F_336 ( V_8 ) ;
}
static void F_380 ( struct V_1 * V_8 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_124 ; V_51 ++ )
F_64 ( V_8 -> V_16 [ V_51 ] ) ;
}
static void F_381 ( struct V_285 * V_15 )
{
struct V_1 * V_8 ;
unsigned long V_59 ;
if ( F_379 ( V_15 ) == NULL ) {
F_55 ( & V_15 -> V_16 , L_279 ) ;
return;
}
V_8 = F_379 ( V_15 ) ;
F_26 ( & V_8 -> V_60 , V_59 ) ;
V_8 -> V_834 = 1 ;
F_27 ( & V_8 -> V_60 , V_59 ) ;
F_382 ( & V_8 -> V_836 ) ;
F_382 ( & V_8 -> V_833 ) ;
F_375 ( V_8 -> V_835 ) ;
F_375 ( V_8 -> V_247 ) ;
F_204 ( V_8 ) ;
F_378 ( V_15 ) ;
F_266 ( V_8 -> V_112 ) ;
F_266 ( V_8 -> V_775 ) ;
F_266 ( V_8 -> V_702 ) ;
F_380 ( V_8 ) ;
F_95 ( V_8 ) ;
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( struct V_9 ) ,
V_8 -> V_589 , V_8 -> V_590 ) ;
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( struct V_248 ) ,
V_8 -> V_591 , V_8 -> V_592 ) ;
F_339 ( V_8 ) ;
F_64 ( V_8 -> V_588 ) ;
F_64 ( V_8 -> V_85 ) ;
F_64 ( V_8 -> V_95 ) ;
F_64 ( V_8 -> V_99 ) ;
F_64 ( V_8 -> V_46 ) ;
F_315 ( V_15 ) ;
F_316 ( V_15 ) ;
F_376 ( V_8 -> F_121 ) ;
F_64 ( V_8 ) ;
}
static void F_383 ( int V_856 [] , int V_857 ,
int V_858 , int V_859 , T_3 * V_860 )
{
int V_51 , V_143 , V_861 , V_352 ;
for ( V_51 = 0 ; V_51 <= V_858 ; V_51 ++ ) {
V_352 = V_51 + V_859 ;
V_861 = V_857 ;
for ( V_143 = 0 ; V_143 < V_857 ; V_143 ++ ) {
if ( V_856 [ V_143 ] >= V_352 ) {
V_861 = V_143 ;
break;
}
}
V_860 [ V_51 ] = V_861 ;
}
}
static int F_384 ( struct V_1 * V_8 , T_3 V_791 )
{
int V_51 ;
unsigned long V_862 ;
unsigned long V_48 = V_49 |
( V_791 & V_863 ) |
V_864 |
( V_791 & ( V_76 |
V_411 ) ) ;
struct V_865 V_77 = V_866 ;
int V_867 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_651 + 4 } ;
#define F_385 5
#define F_386 4
int V_868 [ 16 ] = { F_385 , 6 , 7 , 8 , 9 , 10 , 11 , 12 ,
13 , 14 , 15 , 16 , 17 , 18 , 19 ,
F_386 + V_465 } ;
F_366 ( F_19 ( V_868 ) != 16 ) ;
F_366 ( F_19 ( V_867 ) != 8 ) ;
F_366 ( F_190 ( struct V_97 , V_417 ) >
16 * F_385 ) ;
F_366 ( sizeof( struct V_461 ) != 16 ) ;
F_366 ( 28 > V_651 + 4 ) ;
if ( V_791 & ( V_76 | V_411 ) )
V_77 = V_869 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
memset ( V_8 -> V_75 [ V_51 ] . V_79 , 0 , V_8 -> V_814 ) ;
V_867 [ 7 ] = V_651 + 4 ;
F_383 ( V_867 , F_19 ( V_867 ) ,
V_651 , 4 , V_8 -> V_85 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
F_46 ( V_867 [ V_51 ] , & V_8 -> V_775 -> V_870 [ V_51 ] ) ;
F_46 ( V_8 -> V_83 , & V_8 -> V_775 -> V_871 ) ;
F_46 ( V_8 -> V_90 , & V_8 -> V_775 -> V_872 ) ;
F_46 ( 0 , & V_8 -> V_775 -> V_873 ) ;
F_46 ( 0 , & V_8 -> V_775 -> V_874 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
F_46 ( 0 , & V_8 -> V_775 -> V_875 [ V_51 ] . V_876 ) ;
F_46 ( V_8 -> V_75 [ V_51 ] . V_84 ,
& V_8 -> V_775 -> V_875 [ V_51 ] . V_877 ) ;
}
F_46 ( 0 , & V_8 -> V_702 -> V_725 . V_794 ) ;
F_46 ( V_48 , & ( V_8 -> V_702 -> V_725 . V_726 ) ) ;
if ( V_791 & V_76 ) {
V_77 = V_878 ;
F_46 ( 10 , & V_8 -> V_702 -> V_725 . V_727 ) ;
F_46 ( 4 , & V_8 -> V_702 -> V_725 . V_728 ) ;
} else {
if ( V_791 & V_411 ) {
V_77 = V_879 ;
F_46 ( 10 , & V_8 -> V_702 -> V_725 . V_727 ) ;
F_46 ( 4 , & V_8 -> V_702 -> V_725 . V_728 ) ;
}
}
F_46 ( V_789 , V_8 -> V_112 + V_697 ) ;
if ( F_308 ( V_8 ) ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_280 ) ;
return - V_62 ;
}
V_862 = F_268 ( & ( V_8 -> V_702 -> V_724 ) ) ;
if ( ! ( V_862 & V_49 ) ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_281 ) ;
return - V_62 ;
}
V_8 -> V_77 = V_77 ;
V_8 -> V_48 = V_48 ;
if ( ! ( ( V_791 & V_76 ) ||
( V_791 & V_411 ) ) )
return 0 ;
if ( V_791 & V_76 ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
F_46 ( V_51 , V_8 -> V_112 + V_880 ) ;
V_8 -> V_75 [ V_51 ] . V_80 =
F_268 ( V_8 -> V_112 + V_881 ) ;
}
V_867 [ 7 ] = V_8 -> V_439 + 8 ;
F_383 ( V_867 , F_19 ( V_867 ) , V_8 -> V_439 , 8 ,
V_8 -> V_95 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ )
memset ( V_8 -> V_75 [ V_51 ] . V_79 ,
( T_4 ) V_882 ,
V_8 -> V_814 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_189 ; V_51 ++ ) {
struct V_91 * V_92 = & V_8 -> V_93 [ V_51 ] ;
V_92 -> V_883 = V_884 ;
V_92 -> V_11 = ( T_3 ) ( V_8 -> V_592 +
( V_51 * sizeof( struct V_248 ) ) ) ;
V_92 -> V_885 = sizeof( struct V_248 ) ;
V_92 -> V_886 = V_887 ;
V_92 -> V_888 =
F_115 ( V_889 ) ;
V_92 -> V_890 = 0 ;
V_92 -> V_89 = 0 ;
V_92 -> V_263 =
F_101 ( ( V_51 << V_475 ) ) ;
V_92 -> V_891 =
F_101 ( V_8 -> V_442 +
( V_51 * sizeof( struct V_91 ) ) ) ;
}
} else if ( V_791 & V_411 ) {
T_5 V_705 , V_707 ;
T_3 V_892 , V_706 ;
int V_296 ;
V_296 = F_283 ( V_8 -> V_15 , V_8 -> V_112 , & V_706 ,
& V_707 , & V_705 ) ;
F_366 ( F_190 ( struct V_97 , V_417 ) != 64 ) ;
V_868 [ 15 ] = V_8 -> V_439 + F_386 ;
F_383 ( V_868 , F_19 ( V_868 ) , V_8 -> V_439 ,
4 , V_8 -> V_99 ) ;
V_892 = F_268 ( & V_8 -> V_702 -> V_893 ) ;
F_366 ( F_190 ( struct V_701 ,
V_893 ) != 0xb8 ) ;
V_8 -> V_894 =
F_243 ( F_284 ( V_8 -> V_15 ,
V_707 ) +
V_705 + V_892 ,
F_19 ( V_868 ) *
sizeof( * V_8 -> V_894 ) ) ;
for ( V_51 = 0 ; V_51 < F_19 ( V_868 ) ; V_51 ++ )
F_46 ( V_868 [ V_51 ] , & V_8 -> V_894 [ V_51 ] ) ;
}
F_46 ( V_789 , V_8 -> V_112 + V_697 ) ;
if ( F_308 ( V_8 ) ) {
F_55 ( & V_8 -> V_15 -> V_16 ,
L_282 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_387 ( struct V_1 * V_8 )
{
V_8 -> V_439 =
F_268 ( & ( V_8 -> V_702 -> V_895 ) ) ;
if ( V_8 -> V_439 > V_896 )
V_8 -> V_439 = V_896 ;
F_366 ( sizeof( struct V_91 ) %
V_897 ) ;
V_8 -> V_93 =
F_267 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_93 ) ,
& ( V_8 -> V_442 ) ) ;
V_8 -> V_95 =
F_75 ( ( ( V_8 -> V_439 + 1 ) *
sizeof( T_3 ) ) , V_155 ) ;
if ( ( V_8 -> V_93 == NULL ) ||
( V_8 -> V_95 == NULL ) )
goto V_805;
memset ( V_8 -> V_93 , 0 ,
V_8 -> V_189 * sizeof( * V_8 -> V_93 ) ) ;
return 0 ;
V_805:
if ( V_8 -> V_93 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_93 ) ,
V_8 -> V_93 , V_8 -> V_442 ) ;
F_64 ( V_8 -> V_95 ) ;
return 1 ;
}
static int F_388 ( struct V_1 * V_8 )
{
V_8 -> V_439 =
F_268 ( & ( V_8 -> V_702 -> V_895 ) ) ;
if ( V_8 -> V_439 > V_465 )
V_8 -> V_439 = V_465 ;
F_366 ( sizeof( struct V_97 ) %
V_898 ) ;
V_8 -> V_98 =
F_267 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_98 ) ,
& ( V_8 -> V_462 ) ) ;
V_8 -> V_99 =
F_75 ( ( ( V_8 -> V_439 + 1 ) *
sizeof( T_3 ) ) , V_155 ) ;
if ( ( V_8 -> V_98 == NULL ) ||
( V_8 -> V_99 == NULL ) )
goto V_805;
memset ( V_8 -> V_98 , 0 ,
V_8 -> V_189 * sizeof( * V_8 -> V_98 ) ) ;
return 0 ;
V_805:
if ( V_8 -> V_98 )
F_269 ( V_8 -> V_15 ,
V_8 -> V_189 * sizeof( * V_8 -> V_98 ) ,
V_8 -> V_98 , V_8 -> V_462 ) ;
F_64 ( V_8 -> V_99 ) ;
return 1 ;
}
static void F_373 ( struct V_1 * V_8 )
{
T_3 V_791 ;
unsigned long V_48 = V_49 |
V_863 ;
int V_51 ;
if ( V_847 )
return;
V_791 = F_268 ( & ( V_8 -> V_702 -> V_723 ) ) ;
if ( ! ( V_791 & V_899 ) )
return;
if ( V_791 & V_76 ) {
V_48 |= V_76 |
V_864 ;
if ( F_387 ( V_8 ) )
goto V_805;
} else {
if ( V_791 & V_411 ) {
V_48 |= V_411 |
V_864 ;
if ( F_388 ( V_8 ) )
goto V_805;
}
}
V_8 -> V_90 = V_8 -> V_88 > 0 ? V_8 -> V_88 : 1 ;
F_299 ( V_8 ) ;
V_8 -> V_814 = V_8 -> V_83 * sizeof( T_5 ) ;
for ( V_51 = 0 ; V_51 < V_8 -> V_90 ; V_51 ++ ) {
V_8 -> V_75 [ V_51 ] . V_79 = F_267 ( V_8 -> V_15 ,
V_8 -> V_814 ,
& ( V_8 -> V_75 [ V_51 ] . V_84 ) ) ;
if ( ! V_8 -> V_75 [ V_51 ] . V_79 )
goto V_805;
V_8 -> V_75 [ V_51 ] . V_352 = V_8 -> V_83 ;
V_8 -> V_75 [ V_51 ] . V_81 = 1 ;
V_8 -> V_75 [ V_51 ] . V_80 = 0 ;
}
V_8 -> V_85 = F_75 ( ( ( V_651 + 1 ) *
sizeof( T_3 ) ) , V_155 ) ;
if ( ! V_8 -> V_85 )
goto V_805;
F_384 ( V_8 , V_791 ) ;
return;
V_805:
F_339 ( V_8 ) ;
F_64 ( V_8 -> V_85 ) ;
}
static int F_389 ( struct V_9 * V_10 )
{
return V_10 -> V_110 == V_111 || V_10 -> V_110 == V_114 ;
}
static void F_349 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = NULL ;
int V_51 , V_900 ;
int V_576 ;
do {
V_900 = 0 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_189 ; V_51 ++ ) {
V_10 = V_8 -> V_589 + V_51 ;
V_576 = F_191 ( & V_10 -> V_576 ) ;
if ( V_576 > 1 )
V_900 += F_389 ( V_10 ) ;
F_108 ( V_8 , V_10 ) ;
}
if ( V_900 <= 0 )
break;
F_127 ( 100 ) ;
} while ( 1 );
}
static int T_17 F_390 ( void )
{
return F_391 ( & V_901 ) ;
}
static void T_18 F_392 ( void )
{
F_393 ( & V_901 ) ;
}
