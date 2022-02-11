static char * F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return L_1 ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( V_4 ) ;
}
static inline bool F_4 ( T_1 * V_6 , T_1 * V_7 )
{
return memcmp ( V_6 , V_7 , 8 ) == 0 ;
}
static inline struct V_8 * F_5 ( struct V_9 * V_10 )
{
void * V_11 = F_6 ( V_10 ) ;
return * ( (struct V_8 * * ) V_11 ) ;
}
static inline bool F_7 ( struct V_12 * V_13 )
{
return ! V_13 -> V_14 ;
}
static inline bool F_8 ( struct V_8 * V_15 )
{
return ! V_15 -> V_16 ;
}
static inline void F_9 ( struct V_8 * V_15 )
{
if ( V_15 -> V_16 )
if ( ! F_10 ( V_15 ) )
F_11 ( V_15 ) ;
}
static inline bool F_12 ( T_1 * V_17 )
{
return F_4 ( V_17 , V_18 ) ;
}
static inline enum V_19 F_13 (
struct V_8 * V_15 )
{
return F_14 ( V_15 ) ;
}
static inline void F_15 ( struct V_8 * V_15 ,
enum V_19 V_20 )
{
F_16 ( V_15 , V_20 ) ;
}
static inline void F_17 ( struct V_8 * V_15 )
{
F_18 ( & V_15 -> V_21 ,
V_22 ) ;
}
static int F_19 ( struct V_23 * V_23 ,
struct V_24 * V_25 , void * V_26 ,
T_2 V_27 , int V_28 )
{
T_3 V_29 ;
if ( ! V_26 || V_27 == 0 || V_28 == V_30 )
return 0 ;
V_29 = F_20 ( V_23 , V_26 , V_27 ,
V_28 ) ;
if ( F_21 ( V_23 , V_29 ) )
return - V_31 ;
F_22 ( ( V_32 ) V_29 , & V_25 -> V_33 ) ;
F_23 ( V_27 , & V_25 -> V_34 ) ;
F_23 ( V_35 , & V_25 -> V_36 ) ;
return 0 ;
}
static void F_24 ( struct V_23 * V_23 ,
struct V_24 * V_37 , int V_38 ,
int V_28 )
{
int V_39 ;
if ( V_28 == V_30 )
return;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
F_25 ( V_23 ,
( T_3 ) F_26 ( & V_37 [ V_39 ] . V_33 ) ,
F_27 ( & V_37 [ V_39 ] . V_34 ) ,
V_28 ) ;
}
static int F_28 ( struct V_8 * V_15 ,
struct V_40 * V_41 , T_1 V_42 ,
T_1 * V_17 , void * V_26 , T_2 V_27 ,
T_4 V_43 , int * V_44 )
{
T_1 * V_45 ;
int V_46 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_47 . V_48 = V_49 ;
F_29 ( F_30 ( struct V_40 ,
V_50 [ 1 ] ) - V_51 ,
& V_41 -> V_47 . V_52 ) ;
F_23 ( V_27 , & V_41 -> V_27 ) ;
memcpy ( V_41 -> V_53 , V_17 , sizeof( V_41 -> V_53 ) ) ;
V_41 -> V_54 = V_55 ;
V_41 -> V_56 = V_57 ;
V_45 = V_41 -> V_45 ;
switch ( V_42 ) {
case V_58 :
V_41 -> V_28 = V_59 ;
V_45 [ 0 ] = V_58 ;
if ( V_43 & V_60 ) {
V_45 [ 1 ] = 0x1 ;
V_45 [ 2 ] = ( T_1 ) V_43 ;
}
V_45 [ 4 ] = ( T_1 ) V_27 ;
break;
case V_61 :
case V_62 :
V_41 -> V_28 = V_59 ;
V_45 [ 0 ] = V_42 ;
if ( V_42 == V_62 )
V_45 [ 1 ] = V_63 ;
else
V_45 [ 1 ] = V_64 ;
F_31 ( V_27 , & V_45 [ 6 ] ) ;
break;
case V_65 :
V_41 -> V_28 = V_59 ;
V_45 [ 0 ] = V_66 ;
V_45 [ 1 ] = V_65 ;
F_31 ( V_27 , & V_45 [ 6 ] ) ;
break;
case V_67 :
V_41 -> V_28 = V_68 ;
V_45 [ 0 ] = V_69 ;
V_45 [ 6 ] = V_70 ;
F_32 ( V_27 , & V_45 [ 7 ] ) ;
break;
case V_71 :
case V_72 :
V_41 -> V_28 = V_59 ;
V_45 [ 0 ] = V_73 ;
V_45 [ 6 ] = V_42 ;
F_32 ( V_27 , & V_45 [ 7 ] ) ;
break;
case V_74 :
V_41 -> V_28 = V_68 ;
V_45 [ 0 ] = V_69 ;
V_45 [ 6 ] = V_42 ;
F_32 ( V_27 , & V_45 [ 7 ] ) ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 , L_2 ,
V_42 ) ;
F_34 ( V_42 ) ;
break;
}
switch ( V_41 -> V_28 ) {
case V_59 :
V_46 = V_76 ;
break;
case V_68 :
V_46 = V_77 ;
break;
case V_78 :
V_46 = V_30 ;
break;
default:
V_46 = V_79 ;
break;
}
* V_44 = V_46 ;
return F_19 ( V_15 -> V_23 , & V_41 -> V_50 [ 0 ] ,
V_26 , V_27 , V_46 ) ;
}
static struct V_80 * F_35 (
struct V_8 * V_15 )
{
struct V_80 * V_81 ;
T_4 V_39 = V_15 -> V_82 ;
while ( 1 ) {
V_81 = & V_15 -> V_83 [ V_39 ] ;
if ( F_36 ( & V_81 -> V_84 ) == 1 )
break;
F_37 ( & V_81 -> V_84 ) ;
V_39 = ( V_39 + 1 ) % V_15 -> V_85 ;
}
V_15 -> V_82 = ( V_39 + 1 ) % V_15 -> V_85 ;
V_81 -> V_4 = NULL ;
V_81 -> V_86 = 0 ;
V_81 -> V_87 = NULL ;
return V_81 ;
}
static void F_38 ( struct V_80 * V_81 )
{
F_37 ( & V_81 -> V_84 ) ;
}
static int F_39 ( struct V_8 * V_15 ,
struct V_88 * V_26 )
{
int V_89 ;
int V_44 ;
struct V_40 V_41 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_71 , V_18 , V_26 ,
sizeof( * V_26 ) , 0 , & V_44 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
return V_89 ;
}
static int F_41 ( struct V_8 * V_15 ,
T_1 * V_17 , T_4 V_43 , void * V_26 , T_2 V_27 )
{
int V_89 ;
int V_44 ;
struct V_40 V_41 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_58 , V_17 , V_26 , V_27 , V_43 ,
& V_44 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
return V_89 ;
}
static int F_42 ( struct V_8 * V_15 ,
struct V_12 * V_13 ,
struct V_91 * V_26 ,
T_2 V_27 )
{
int V_89 ;
int V_44 ;
T_4 V_92 ;
struct V_40 V_41 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_72 , V_18 , V_26 ,
V_27 , 0 , & V_44 ) ;
if ( V_89 )
return V_89 ;
V_92 = F_43 ( V_13 -> V_17 ) ;
V_41 . V_45 [ 2 ] = ( T_1 ) V_92 ;
V_41 . V_45 [ 9 ] = ( T_1 ) ( V_92 >> 8 ) ;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
0 , NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
return V_89 ;
}
static int F_44 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_40 V_41 ;
int V_44 ;
T_1 * V_26 ;
if ( F_8 ( V_15 ) )
return - V_93 ;
V_26 = F_45 ( V_94 , V_95 ) ;
if ( ! V_26 )
return - V_31 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_67 , V_18 , V_26 ,
V_94 , 0 , & V_44 ) ;
if ( V_89 )
goto V_96;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
0 , NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
V_96:
F_46 ( V_26 ) ;
return V_89 ;
}
static int F_47 ( struct V_8 * V_15 ,
void * V_26 , T_2 V_27 )
{
int V_89 ;
struct V_40 V_41 ;
int V_44 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_74 , V_18 , V_26 ,
V_27 , 0 , & V_44 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
0 , NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
return V_89 ;
}
static int F_48 (
struct V_8 * V_15 )
{
int V_89 ;
struct V_97 * V_26 ;
T_2 V_27 ;
V_27 = sizeof( * V_26 ) ;
V_26 = F_49 ( V_27 , V_95 ) ;
if ( ! V_26 )
return - V_31 ;
V_26 -> V_98 [ 0 ] = '<' ;
V_26 -> V_98 [ 1 ] = 'H' ;
V_26 -> V_98 [ 2 ] = 'W' ;
V_26 -> V_98 [ 3 ] = '>' ;
V_26 -> V_99 [ 0 ] = 'D' ;
V_26 -> V_99 [ 1 ] = 'V' ;
F_29 ( sizeof( V_26 -> V_100 ) ,
& V_26 -> V_101 ) ;
strncpy ( V_26 -> V_100 , V_102 ,
sizeof( V_26 -> V_100 ) - 1 ) ;
V_26 -> V_100 [ sizeof( V_26 -> V_100 ) - 1 ] = '\0' ;
V_26 -> V_103 [ 0 ] = 'Z' ;
V_26 -> V_103 [ 1 ] = 'Z' ;
V_89 = F_47 ( V_15 , V_26 , V_27 ) ;
F_46 ( V_26 ) ;
return V_89 ;
}
static int F_50 (
struct V_8 * V_15 )
{
int V_89 ;
struct V_104 * V_26 ;
T_2 V_27 ;
T_5 V_105 ;
unsigned int V_106 ;
struct V_107 V_107 ;
V_27 = sizeof( * V_26 ) ;
V_26 = F_49 ( V_27 , V_95 ) ;
if ( ! V_26 )
return - V_31 ;
V_26 -> V_98 [ 0 ] = '<' ;
V_26 -> V_98 [ 1 ] = 'H' ;
V_26 -> V_98 [ 2 ] = 'W' ;
V_26 -> V_98 [ 3 ] = '>' ;
V_26 -> V_108 [ 0 ] = 'T' ;
V_26 -> V_108 [ 1 ] = 'D' ;
F_29 ( sizeof( V_26 -> time ) ,
& V_26 -> V_109 ) ;
V_105 = F_51 () ;
F_52 ( V_105 , - V_110 . V_111 * 60 , & V_107 ) ;
V_106 = V_107 . V_112 + 1900 ;
V_26 -> time [ 0 ] = F_53 ( V_107 . V_113 ) ;
V_26 -> time [ 1 ] = F_53 ( V_107 . V_114 ) ;
V_26 -> time [ 2 ] = F_53 ( V_107 . V_115 ) ;
V_26 -> time [ 3 ] = 0 ;
V_26 -> time [ 4 ] = F_53 ( V_107 . V_116 + 1 ) ;
V_26 -> time [ 5 ] = F_53 ( V_107 . V_117 ) ;
V_26 -> time [ 6 ] = F_53 ( V_106 / 100 ) ;
V_26 -> time [ 7 ] = F_53 ( V_106 % 100 ) ;
V_26 -> V_118 [ 0 ] = 'D' ;
V_26 -> V_118 [ 1 ] = 'W' ;
V_26 -> V_103 [ 0 ] = 'Z' ;
V_26 -> V_103 [ 1 ] = 'Z' ;
V_89 = F_47 ( V_15 , V_26 , V_27 ) ;
F_46 ( V_26 ) ;
return V_89 ;
}
static void F_54 ( struct V_119 * V_120 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_55 ( F_56 ( V_120 ) , struct V_8 ,
V_121 ) ;
V_89 = F_50 ( V_15 ) ;
if ( V_89 )
F_57 ( & V_15 -> V_23 -> V_75 ,
L_3 ) ;
F_18 ( & V_15 -> V_121 ,
V_122 ) ;
}
static inline void F_58 (
struct V_8 * V_15 )
{
F_18 ( & V_15 -> V_121 , 0 ) ;
}
static int F_59 ( struct V_8 * V_15 , T_1 V_42 ,
void * V_26 , T_2 V_27 )
{
int V_89 ;
int V_44 ;
struct V_40 V_41 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_42 , V_18 , V_26 , V_27 , 0 , & V_44 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
return V_89 ;
}
static int F_60 ( struct V_8 * V_15 , T_1 V_42 ,
void * * V_26 )
{
int V_89 ;
T_2 V_123 ;
T_2 V_124 ;
T_2 V_125 ;
void * V_126 = NULL ;
struct V_127 * V_127 ;
V_127 = F_49 ( sizeof( * V_127 ) , V_95 ) ;
if ( ! V_127 ) {
V_89 = - V_31 ;
goto V_96;
}
V_89 = F_59 ( V_15 , V_42 , V_127 ,
sizeof( * V_127 ) ) ;
if ( V_89 )
goto V_96;
V_123 = F_61 ( & V_127 -> V_128 ) ;
V_129:
V_124 = sizeof( struct V_127 ) + V_123 ;
V_126 = F_49 ( V_124 , V_95 ) ;
if ( ! V_126 ) {
V_89 = - V_31 ;
goto V_96;
}
if ( V_123 == 0 ) {
memcpy ( V_126 , V_127 , sizeof( * V_127 ) ) ;
goto V_96;
}
V_89 = F_59 ( V_15 , V_42 , V_126 , V_124 ) ;
if ( V_89 )
goto V_96;
V_125 = F_61 (
& ( (struct V_127 * ) V_126 ) -> V_128 ) ;
if ( V_125 > V_123 ) {
V_123 = V_125 ;
F_46 ( V_126 ) ;
goto V_129;
}
V_96:
F_46 ( V_127 ) ;
if ( V_89 ) {
F_46 ( V_126 ) ;
V_126 = NULL ;
}
* V_26 = V_126 ;
return V_89 ;
}
static inline int F_62 ( struct V_8 * V_15 ,
void * * V_26 )
{
return F_60 ( V_15 , V_62 ,
V_26 ) ;
}
static inline int F_63 ( struct V_8 * V_15 ,
void * * V_26 )
{
return F_60 ( V_15 , V_61 , V_26 ) ;
}
static int F_64 ( struct V_8 * V_15 ,
struct V_130 * * V_131 ,
struct V_132 * * V_133 )
{
int V_89 ;
T_2 V_134 ;
T_2 V_135 ;
struct V_132 * V_136 ;
struct V_132 * V_137 ;
struct V_127 V_127 ;
V_89 = F_62 ( V_15 , ( void * * ) V_131 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_4 ) ;
V_89 = F_63 ( V_15 , ( void * * ) V_133 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_5 ) ;
V_137 = * V_133 ;
if ( V_137 ) {
V_134 =
F_61 ( & V_137 -> V_47 . V_128 ) ;
} else {
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_137 =
(struct V_132 * ) & V_127 ;
V_134 = 0 ;
}
V_135 = sizeof( struct V_127 ) +
V_134 ;
V_136 = F_49 ( V_135 +
sizeof( struct V_132 ) , V_95 ) ;
if ( ! V_136 ) {
F_46 ( * V_133 ) ;
* V_133 = NULL ;
return - V_31 ;
}
memcpy ( V_136 , V_137 , V_135 ) ;
memset ( ( T_1 * ) V_136 + V_135 , 0 ,
sizeof( struct V_138 ) ) ;
F_31 ( V_134 +
sizeof( struct V_138 ) ,
& V_136 -> V_47 . V_128 ) ;
F_46 ( * V_133 ) ;
* V_133 = V_136 ;
return 0 ;
}
static inline void F_65 ( struct V_12 * V_13 ,
int V_139 , int V_140 , int V_141 )
{
V_13 -> V_139 = V_139 ;
V_13 -> V_140 = V_140 ;
V_13 -> V_141 = V_141 ;
}
static void F_66 ( struct V_12 * V_13 )
{
T_1 * V_17 ;
T_6 V_142 ;
V_17 = V_13 -> V_17 ;
V_142 = F_27 ( V_17 ) ;
if ( F_12 ( V_17 ) ) {
F_65 ( V_13 , V_143 , 0 , V_142 & 0x3fff ) ;
V_13 -> V_144 = true ;
return;
}
if ( F_7 ( V_13 ) ) {
F_65 ( V_13 , V_145 , 0 ,
V_142 & 0x3fff ) ;
V_13 -> V_144 = true ;
return;
}
F_65 ( V_13 , V_146 , 0 , 0 ) ;
}
static void F_67 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_1 V_1 ;
T_1 * V_26 ;
V_1 = V_147 ;
V_26 = F_49 ( 64 , V_95 ) ;
if ( V_26 ) {
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_148 , V_26 , 64 ) ;
if ( V_89 == 0 ) {
V_1 = V_26 [ 8 ] ;
if ( V_1 > V_149 )
V_1 = V_147 ;
}
F_46 ( V_26 ) ;
}
V_13 -> V_1 = V_1 ;
}
static int F_68 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_150 * V_150 )
{
char * V_151 ;
T_6 V_152 ;
T_6 V_153 ;
unsigned int V_154 ;
unsigned int V_155 ;
V_152 = F_27 ( & V_150 -> V_156 ) ;
if ( V_152 < F_30 ( struct V_150 , V_157 ) ) {
V_151 = L_6 ;
goto V_158;
}
if ( V_152 > sizeof( * V_150 ) ) {
V_151 = L_7 ;
goto V_158;
}
V_154 = F_69 ( & V_150 -> V_159 ) *
( F_69 ( & V_150 -> V_160 ) +
F_69 ( & V_150 -> V_161 ) ) ;
V_155 = V_154 *
F_69 ( & V_150 -> V_162 ) ;
if ( V_155 > V_163 ) {
V_151 = L_8 ;
goto V_158;
}
if ( V_13 -> V_1 == V_164 ) {
if ( F_69 ( & V_150 -> V_159 ) != 2 ) {
V_151 = L_9 ;
goto V_158;
}
} else if ( V_13 -> V_1 == V_165 ) {
if ( F_69 ( & V_150 -> V_159 ) != 3 ) {
V_151 = L_10 ;
goto V_158;
}
} else if ( ( V_13 -> V_1 == V_166 ||
V_13 -> V_1 == V_167 ) &&
F_69 ( & V_150 -> V_159 ) > 1 ) {
V_153 =
F_69 ( & V_150 -> V_168 ) *
F_69 ( & V_150 -> V_160 ) ;
if ( V_153 == 0 ) {
V_151 = L_11 ;
goto V_158;
}
}
return 0 ;
V_158:
F_57 ( & V_15 -> V_23 -> V_75 , L_12 , V_151 ) ;
return - V_169 ;
}
static int F_70 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
int V_44 ;
struct V_40 V_41 ;
struct V_150 * V_150 ;
V_150 = F_49 ( sizeof( * V_150 ) , V_95 ) ;
if ( ! V_150 )
return - V_31 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_65 , V_13 -> V_17 , V_150 ,
sizeof( * V_150 ) , 0 , & V_44 ) ;
if ( V_89 )
goto error;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
if ( V_89 )
goto error;
V_89 = F_68 ( V_15 , V_13 , V_150 ) ;
if ( V_89 )
goto error;
V_13 -> V_150 = V_150 ;
return 0 ;
error:
F_46 ( V_150 ) ;
return V_89 ;
}
static void F_71 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_1 * V_26 ;
T_1 V_170 ;
V_26 = F_49 ( 64 , V_95 ) ;
if ( ! V_26 )
return;
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_171 , V_26 , 64 ) ;
if ( V_89 )
goto V_96;
#define F_72 4
#define F_73 0x1
#define F_74 0x2
V_170 = V_26 [ F_72 ] ;
V_13 -> V_172 =
! ! ( V_170 & F_73 ) ;
if ( V_13 -> V_172 ) {
V_13 -> V_173 =
! ! ( V_170 & F_74 ) ;
if ( F_70 ( V_15 , V_13 ) )
V_13 -> V_173 = false ;
}
V_96:
F_46 ( V_26 ) ;
}
static void F_75 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_2 V_174 ;
T_1 V_175 = V_176 ;
bool V_177 = true ;
T_6 V_178 ;
struct V_179 * V_180 ;
V_180 = F_49 ( sizeof( * V_180 ) , V_95 ) ;
if ( ! V_180 )
goto V_181;
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_182 , V_180 , sizeof( * V_180 ) ) ;
if ( V_89 )
goto V_96;
V_174 = F_30 ( struct V_179 ,
V_175 ) + V_180 -> V_174 ;
if ( V_174 < sizeof( * V_180 ) )
goto V_96;
V_175 = V_180 -> V_175 ;
V_178 = F_61 ( & V_180 -> V_36 ) ;
V_177 = ( V_178 & V_183 ) != 0 ;
V_96:
F_46 ( V_180 ) ;
V_181:
V_13 -> V_175 = V_175 ;
V_13 -> V_177 = V_177 ;
}
static int F_76 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_1 * V_26 ;
V_26 = F_49 ( 64 , V_95 ) ;
if ( ! V_26 )
return - V_31 ;
V_89 = F_41 ( V_15 , V_13 -> V_17 , 0 , V_26 , 64 ) ;
if ( V_89 )
goto V_96;
F_77 ( & V_26 [ 8 ] , 8 ) ;
F_77 ( & V_26 [ 16 ] , 16 ) ;
V_13 -> V_184 = V_26 [ 0 ] & 0x1f ;
memcpy ( V_13 -> V_185 , & V_26 [ 8 ] ,
sizeof( V_13 -> V_185 ) ) ;
memcpy ( V_13 -> V_186 , & V_26 [ 16 ] ,
sizeof( V_13 -> V_186 ) ) ;
if ( F_7 ( V_13 ) && V_13 -> V_184 == V_187 ) {
F_67 ( V_15 , V_13 ) ;
F_71 ( V_15 , V_13 ) ;
F_75 ( V_15 , V_13 ) ;
}
V_96:
F_46 ( V_26 ) ;
return V_89 ;
}
static void F_78 ( struct V_8 * V_15 ,
struct V_12 * V_13 ,
struct V_91 * V_188 )
{
int V_89 ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
V_89 = F_42 ( V_15 , V_13 ,
V_188 , sizeof( * V_188 ) ) ;
if ( V_89 ) {
V_13 -> V_189 = V_190 ;
return;
}
V_13 -> V_189 =
F_69 ( & V_188 -> V_191 ) ;
V_13 -> V_192 = V_188 -> V_192 ;
V_13 -> V_193 = V_188 -> V_194 ;
V_13 -> V_195 = V_188 -> V_196 ;
memcpy ( & V_13 -> V_197 ,
& V_188 -> V_198 ,
sizeof( V_13 -> V_197 ) ) ;
memcpy ( & V_13 -> V_199 ,
& V_188 -> V_200 ,
sizeof( V_13 -> V_199 ) ) ;
V_13 -> V_201 = V_188 -> V_202 ;
}
static void F_79 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
char * V_86 ;
static const char V_203 [] =
L_13 ;
char V_204 [ sizeof( V_203 ) + 10 ] ;
switch ( V_13 -> V_175 ) {
case V_205 :
V_86 = L_14 ;
break;
case V_206 :
V_86 = L_15 ;
break;
case V_207 :
V_86 = L_16 ;
break;
case V_208 :
V_86 = L_17 ;
break;
case V_209 :
V_86 = L_18 ;
break;
case V_210 :
V_86 = L_19 ;
break;
case V_211 :
V_86 = L_20 ;
break;
case V_212 :
V_86 = L_21 ;
break;
case V_213 :
V_86 = L_22 ;
break;
case V_214 :
V_86 = L_23 ;
break;
case V_215 :
V_86 = L_24 ;
break;
case V_216 :
V_86 = L_25 ;
break;
case V_217 :
V_86 = L_26 ;
break;
case V_218 :
V_86 = L_27 ;
break;
case V_219 :
V_86 = L_28 ;
break;
case V_220 :
V_86 = L_29 ;
break;
case V_221 :
V_86 = L_30 ;
break;
case V_222 :
V_86 = L_31 ;
break;
case V_223 :
V_86 = L_32 ;
break;
case V_224 :
V_86 = L_33 ;
break;
case V_225 :
V_86 = L_34 ;
break;
case V_226 :
V_86 = L_35 ;
break;
case V_227 :
V_86 =
L_36 ;
break;
case V_228 :
V_86 = L_37 ;
break;
case V_229 :
V_86 = L_38 ;
break;
case V_230 :
V_86 = L_39 ;
break;
case V_176 :
V_86 = L_40 ;
break;
default:
snprintf ( V_204 , sizeof( V_204 ) ,
V_203 , V_13 -> V_175 ) ;
V_86 = V_204 ;
break;
}
F_80 ( & V_15 -> V_23 -> V_75 ,
L_41 ,
V_15 -> V_231 -> V_232 ,
V_13 -> V_139 , V_13 -> V_140 , V_13 -> V_141 , V_86 ) ;
}
static struct V_12 * F_81 (
struct V_8 * V_15 , T_6 V_233 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_184 != V_187 && V_13 -> V_184 != V_234 )
continue;
if ( F_7 ( V_13 ) )
continue;
if ( V_13 -> V_233 == V_233 )
return V_13 ;
}
return NULL ;
}
static void F_83 (
struct V_8 * V_15 , struct V_12 * V_235 )
{
unsigned int V_39 ;
struct V_150 * V_150 ;
struct V_236 * V_157 ;
struct V_12 * V_237 ;
unsigned int V_154 ;
unsigned int V_155 ;
unsigned int V_189 ;
V_235 -> V_189 = V_238 ;
V_150 = V_235 -> V_150 ;
if ( ! V_150 )
return;
V_157 = V_150 -> V_157 ;
V_154 = F_69 ( & V_150 -> V_159 ) *
( F_69 ( & V_150 -> V_160 ) +
F_69 ( & V_150 -> V_161 ) ) ;
V_155 = V_154 *
F_69 ( & V_150 -> V_162 ) ;
V_189 = 0 ;
for ( V_39 = 0 ; V_39 < V_155 ; V_39 ++ ) {
V_237 = F_81 ( V_15 ,
V_157 [ V_39 ] . V_233 ) ;
if ( ! V_237 ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_42 ,
F_84 ( V_235 -> V_17 ) ) ;
V_235 -> V_239 = false ;
V_235 -> V_173 = false ;
F_46 ( V_150 ) ;
V_235 -> V_150 = NULL ;
return;
}
V_189 += V_237 -> V_189 ;
}
V_235 -> V_189 = V_189 ;
}
static void F_85 (
struct V_8 * V_15 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_184 != V_187 && V_13 -> V_184 != V_234 )
continue;
if ( ! F_7 ( V_13 ) )
continue;
F_83 ( V_15 , V_13 ) ;
}
}
static void F_86 ( struct V_119 * V_120 )
{
struct V_8 * V_15 ;
V_15 = F_55 ( F_56 ( V_120 ) , struct V_8 ,
V_21 ) ;
F_87 ( V_15 ) ;
}
static int F_88 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
if ( F_7 ( V_13 ) )
V_89 = F_89 ( V_15 -> V_231 , V_13 -> V_139 ,
V_13 -> V_140 , V_13 -> V_141 ) ;
else
V_89 = F_90 ( V_15 -> V_240 , V_13 ) ;
return V_89 ;
}
static inline void F_91 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
if ( F_7 ( V_13 ) )
F_92 ( V_13 -> V_241 ) ;
else
F_93 ( V_13 ) ;
}
static struct V_12 * F_94 ( struct V_8 * V_15 ,
int V_139 , int V_140 , int V_141 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
if ( V_13 -> V_139 == V_139 && V_13 -> V_140 == V_140 &&
V_13 -> V_141 == V_141 )
return V_13 ;
return NULL ;
}
static inline bool F_95 ( struct V_12 * V_242 ,
struct V_12 * V_243 )
{
if ( V_242 -> V_14 != V_243 -> V_14 )
return false ;
if ( V_242 -> V_14 )
return V_242 -> V_244 == V_243 -> V_244 ;
return memcmp ( V_242 -> V_245 , V_243 -> V_245 ,
sizeof( V_242 -> V_245 ) ) == 0 ;
}
static enum V_246 F_96 ( struct V_8 * V_15 ,
struct V_12 * V_247 ,
struct V_12 * * V_248 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_4 ( V_247 -> V_17 ,
V_13 -> V_17 ) ) {
* V_248 = V_13 ;
if ( F_95 ( V_247 , V_13 ) ) {
if ( V_247 -> V_177 )
return V_249 ;
return V_250 ;
}
return V_249 ;
}
}
return V_251 ;
}
static void F_97 ( struct V_8 * V_15 ,
char * V_252 , struct V_12 * V_13 )
{
F_80 ( & V_15 -> V_23 -> V_75 ,
L_43 ,
V_252 ,
V_15 -> V_231 -> V_232 ,
V_13 -> V_139 ,
V_13 -> V_140 ,
V_13 -> V_141 ,
F_98 ( V_13 -> V_184 ) ,
V_13 -> V_185 ,
V_13 -> V_186 ,
F_1 ( V_13 -> V_1 ) ,
V_13 -> V_172 ? '+' : '-' ,
V_13 -> V_173 ? '+' : '-' ,
V_13 -> V_253 ? '+' : '-' ,
V_13 -> V_189 ) ;
}
static void F_99 ( struct V_12 * V_254 ,
struct V_12 * V_255 )
{
V_254 -> V_184 = V_255 -> V_184 ;
V_254 -> V_192 = V_255 -> V_192 ;
V_254 -> V_139 = V_255 -> V_139 ;
if ( V_255 -> V_144 ) {
V_254 -> V_140 = V_255 -> V_140 ;
V_254 -> V_141 = V_255 -> V_141 ;
V_254 -> V_144 = true ;
}
V_254 -> V_14 = V_255 -> V_14 ;
V_254 -> V_253 = V_255 -> V_253 ;
V_254 -> V_256 = V_255 -> V_256 ;
V_254 -> V_257 = V_255 -> V_257 ;
memcpy ( V_254 -> V_185 , V_255 -> V_185 ,
sizeof( V_254 -> V_185 ) ) ;
memcpy ( V_254 -> V_186 , V_255 -> V_186 ,
sizeof( V_254 -> V_186 ) ) ;
V_254 -> V_258 = V_255 -> V_258 ;
V_254 -> V_1 = V_255 -> V_1 ;
V_254 -> V_189 = V_255 -> V_189 ;
V_254 -> V_233 = V_255 -> V_233 ;
V_254 -> V_175 = V_255 -> V_175 ;
V_254 -> V_193 = V_255 -> V_193 ;
V_254 -> V_195 = V_255 -> V_195 ;
V_254 -> V_201 = V_255 -> V_201 ;
memcpy ( V_254 -> V_197 , V_255 -> V_197 ,
sizeof( V_254 -> V_197 ) ) ;
memcpy ( V_254 -> V_199 , V_255 -> V_199 ,
sizeof( V_254 -> V_199 ) ) ;
V_254 -> V_172 = V_255 -> V_172 ;
V_254 -> V_239 = false ;
V_254 -> V_173 =
V_255 -> V_173 ;
V_254 -> V_259 = 0 ;
F_46 ( V_254 -> V_150 ) ;
V_254 -> V_150 = V_255 -> V_150 ;
V_255 -> V_150 = NULL ;
}
static inline void F_100 ( struct V_12 * V_13 )
{
if ( V_13 ) {
F_46 ( V_13 -> V_150 ) ;
F_46 ( V_13 ) ;
}
}
static inline void F_101 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
unsigned long V_36 ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
F_103 ( & V_13 -> V_261 ) ;
F_104 ( & V_15 -> V_260 , V_36 ) ;
V_13 -> V_262 = false ;
}
static void F_105 ( struct V_8 * V_15 ,
struct V_12 * V_263 [] , unsigned int V_264 )
{
int V_89 ;
unsigned int V_39 ;
unsigned long V_36 ;
enum V_246 V_265 ;
struct V_12 * V_13 ;
struct V_12 * V_266 ;
struct V_12 * V_248 ;
struct V_267 V_268 ;
struct V_267 V_269 ;
F_106 ( & V_268 ) ;
F_106 ( & V_269 ) ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_270 = true ;
for ( V_39 = 0 ; V_39 < V_264 ; V_39 ++ ) {
V_13 = V_263 [ V_39 ] ;
V_265 = F_96 ( V_15 , V_13 ,
& V_248 ) ;
switch ( V_265 ) {
case V_250 :
V_13 -> V_255 = false ;
V_248 -> V_270 = false ;
F_99 ( V_248 , V_13 ) ;
break;
case V_251 :
V_13 -> V_255 = true ;
break;
case V_249 :
V_13 -> V_255 = true ;
break;
default:
F_34 ( V_265 ) ;
break;
}
}
F_107 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_270 ) {
F_103 ( & V_13 -> V_261 ) ;
F_108 ( & V_13 -> V_271 , & V_269 ) ;
}
}
for ( V_39 = 0 ; V_39 < V_264 ; V_39 ++ ) {
V_13 = V_263 [ V_39 ] ;
if ( ! V_13 -> V_255 )
continue;
if ( V_13 -> V_177 )
continue;
F_108 ( & V_13 -> V_261 ,
& V_15 -> V_272 ) ;
F_108 ( & V_13 -> V_273 , & V_268 ) ;
V_13 -> V_262 = true ;
}
F_85 ( V_15 ) ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_239 =
V_13 -> V_173 ;
F_104 ( & V_15 -> V_260 , V_36 ) ;
F_107 (device, next, &delete_list,
delete_list_entry) {
if ( V_13 -> V_241 )
F_91 ( V_15 , V_13 ) ;
if ( V_13 -> V_177 ) {
F_97 ( V_15 , L_44 , V_13 ) ;
F_79 ( V_15 , V_13 ) ;
} else {
F_97 ( V_15 , L_45 , V_13 ) ;
}
F_103 ( & V_13 -> V_271 ) ;
F_100 ( V_13 ) ;
}
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_241 && V_13 -> V_189 !=
V_13 -> V_274 ) {
V_13 -> V_274 = V_13 -> V_189 ;
F_109 ( V_13 -> V_241 ,
V_13 -> V_274 ) ;
}
}
F_107 (device, next, &add_list, add_list_entry) {
if ( V_13 -> V_253 && ! V_13 -> V_241 ) {
V_89 = F_88 ( V_15 , V_13 ) ;
if ( V_89 ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_46 ,
V_15 -> V_231 -> V_232 ,
V_13 -> V_139 , V_13 -> V_140 ,
V_13 -> V_141 ) ;
F_101 ( V_15 , V_13 ) ;
continue;
}
}
F_97 ( V_15 , L_47 , V_13 ) ;
}
}
static bool F_110 ( struct V_12 * V_13 )
{
bool V_275 = false ;
switch ( V_13 -> V_184 ) {
case V_187 :
case V_234 :
case V_276 :
case V_277 :
case V_278 :
V_275 = true ;
break;
case V_279 :
if ( F_12 ( V_13 -> V_17 ) )
V_275 = true ;
break;
}
return V_275 ;
}
static inline bool F_111 ( T_1 * V_17 ,
struct V_280 * V_281 )
{
T_1 V_282 ;
if ( ! F_112 ( V_17 ) )
return false ;
V_282 = V_281 -> V_282 ;
if ( V_282 & V_283 ) {
return true ;
}
return false ;
}
static inline bool F_113 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 && F_112 ( V_13 -> V_17 ) )
return false ;
return true ;
}
static int F_114 ( struct V_8 * V_15 )
{
int V_39 ;
int V_89 ;
struct V_267 V_284 ;
struct V_130 * V_131 = NULL ;
struct V_132 * V_133 = NULL ;
struct V_280 * V_281 ;
struct V_138 * V_285 ;
struct V_91 * V_188 = NULL ;
T_6 V_286 ;
T_6 V_287 ;
struct V_12 * * V_263 = NULL ;
struct V_12 * V_13 ;
struct V_12 * V_266 ;
unsigned int V_264 ;
unsigned int V_288 ;
bool V_14 ;
T_1 * V_17 ;
static char * V_289 =
L_48 ;
F_106 ( & V_284 ) ;
V_89 = F_64 ( V_15 , & V_131 , & V_133 ) ;
if ( V_89 )
goto V_96;
if ( V_131 )
V_286 =
F_61 ( & V_131 -> V_47 . V_128 )
/ sizeof( V_131 -> V_290 [ 0 ] ) ;
else
V_286 = 0 ;
if ( V_133 )
V_287 =
F_61 ( & V_133 -> V_47 . V_128 )
/ sizeof( V_133 -> V_290 [ 0 ] ) ;
else
V_287 = 0 ;
if ( V_286 ) {
V_188 = F_49 ( sizeof( * V_188 ) , V_95 ) ;
if ( ! V_188 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_289 ) ;
V_89 = - V_31 ;
goto V_96;
}
}
V_264 = V_286 + V_287 ;
V_263 = F_49 ( sizeof( * V_263 ) *
V_264 , V_95 ) ;
if ( ! V_263 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 , V_289 ) ;
V_89 = - V_31 ;
goto V_96;
}
for ( V_39 = 0 ; V_39 < V_264 ; V_39 ++ ) {
V_13 = F_45 ( sizeof( * V_13 ) , V_95 ) ;
if ( ! V_13 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_289 ) ;
V_89 = - V_31 ;
goto V_96;
}
F_108 ( & V_13 -> V_291 ,
& V_284 ) ;
}
V_13 = NULL ;
V_288 = 0 ;
for ( V_39 = 0 ; V_39 < V_264 ; V_39 ++ ) {
if ( V_39 < V_286 ) {
V_14 = true ;
V_281 = & V_131 -> V_290 [ V_39 ] ;
V_285 = NULL ;
V_17 = V_281 -> V_142 ;
} else {
V_14 = false ;
V_281 = NULL ;
V_285 =
& V_133 -> V_290 [ V_39 - V_286 ] ;
V_17 = V_285 -> V_142 ;
}
if ( V_14 &&
F_111 ( V_17 , V_281 ) )
continue;
if ( V_13 )
V_13 = F_115 ( V_13 , V_291 ) ;
else
V_13 = F_116 ( & V_284 ,
struct V_12 , V_291 ) ;
memcpy ( V_13 -> V_17 , V_17 , sizeof( V_13 -> V_17 ) ) ;
V_13 -> V_14 = V_14 ;
V_13 -> V_1 = V_147 ;
V_89 = F_76 ( V_15 , V_13 ) ;
if ( V_89 == - V_31 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_289 ) ;
goto V_96;
}
if ( V_89 ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_49 ,
F_84 ( V_13 -> V_17 ) ) ;
V_89 = 0 ;
continue;
}
if ( ! F_110 ( V_13 ) )
continue;
F_66 ( V_13 ) ;
V_13 -> V_253 = F_113 ( V_13 ) ;
if ( V_13 -> V_14 ) {
V_13 -> V_244 = V_281 -> V_244 ;
if ( ( V_281 -> V_282 &
V_292 ) &&
V_281 -> V_233 )
V_13 -> V_257 = true ;
} else {
memcpy ( V_13 -> V_245 , V_285 -> V_245 ,
sizeof( V_13 -> V_245 ) ) ;
}
switch ( V_13 -> V_184 ) {
case V_187 :
case V_234 :
case V_278 :
if ( V_13 -> V_14 ) {
V_13 -> V_258 =
F_84 ( & V_13 -> V_244 ) ;
if ( V_13 -> V_184 == V_187 ||
V_13 -> V_184 == V_234 ) {
V_13 -> V_233 =
V_281 -> V_233 ;
F_78 ( V_15 ,
V_13 , V_188 ) ;
}
}
break;
}
V_263 [ V_288 ++ ] = V_13 ;
}
F_105 ( V_15 , V_263 , V_288 ) ;
V_96:
F_107 (device, next, &new_device_list_head,
new_device_list_entry) {
if ( V_13 -> V_262 )
continue;
F_103 ( & V_13 -> V_291 ) ;
F_100 ( V_13 ) ;
}
F_46 ( V_263 ) ;
F_46 ( V_131 ) ;
F_46 ( V_133 ) ;
F_46 ( V_188 ) ;
return V_89 ;
}
static void F_117 ( struct V_8 * V_15 )
{
unsigned long V_36 ;
struct V_12 * V_13 ;
struct V_12 * V_266 ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
F_107 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_241 )
F_91 ( V_15 , V_13 ) ;
F_103 ( & V_13 -> V_261 ) ;
F_100 ( V_13 ) ;
}
F_104 ( & V_15 -> V_260 , V_36 ) ;
}
static int F_87 ( struct V_8 * V_15 )
{
int V_89 ;
if ( F_8 ( V_15 ) )
return - V_93 ;
F_118 ( & V_15 -> V_293 ) ;
V_89 = F_114 ( V_15 ) ;
if ( V_89 )
F_17 ( V_15 ) ;
F_119 ( & V_15 -> V_293 ) ;
return V_89 ;
}
static void F_120 ( struct V_9 * V_10 )
{
F_87 ( F_5 ( V_10 ) ) ;
}
static int F_121 ( struct V_9 * V_10 ,
unsigned long V_294 )
{
struct V_8 * V_15 ;
V_15 = F_6 ( V_10 ) ;
return ! F_122 ( & V_15 -> V_293 ) ;
}
static inline void F_123 (
struct V_295 * V_296 , struct V_150 * V_150 ,
V_32 V_297 )
{
T_6 V_298 ;
V_298 = F_27 ( & V_150 -> V_298 ) ;
if ( V_298 != 512 )
V_297 = ( V_297 * V_298 ) / 512 ;
V_296 -> V_299 =
F_69 ( & V_150 -> V_299 ) ;
V_296 -> V_300 = F_124 ( V_297 ) ;
V_296 -> V_301 = F_125 ( V_297 ) ;
}
static int F_126 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_302 * V_303 )
{
struct V_150 * V_150 ;
bool V_304 = false ;
T_6 V_305 ;
V_32 V_297 ;
V_32 V_306 ;
T_6 V_307 ;
T_6 V_308 ;
V_32 V_309 ;
V_32 V_310 ;
T_6 V_311 ;
T_6 V_312 ;
T_6 V_313 ;
T_6 V_314 ;
V_32 V_315 ;
V_32 V_316 ;
T_6 V_153 ;
V_32 V_317 ;
V_32 V_318 ;
T_6 V_319 ;
T_6 V_320 ;
T_6 V_321 ;
T_6 V_322 ;
T_4 V_160 ;
T_6 V_323 ;
T_4 V_159 ;
T_6 V_324 ;
T_4 V_168 ;
T_6 V_325 ;
T_6 V_326 ;
T_6 V_327 ;
T_6 V_328 ;
T_6 V_233 ;
V_32 V_329 ;
T_6 V_330 ;
T_1 V_45 [ 16 ] ;
T_1 V_331 ;
int V_259 ;
struct V_295 * V_332 ;
struct V_295 V_296 ;
#if V_333 == 32
V_32 V_334 ;
#endif
switch ( V_4 -> V_335 [ 0 ] ) {
case V_336 :
V_304 = true ;
case V_337 :
V_297 = ( V_32 ) ( ( ( V_4 -> V_335 [ 1 ] & 0x1f ) << 16 ) |
( V_4 -> V_335 [ 2 ] << 8 ) | V_4 -> V_335 [ 3 ] ) ;
V_307 = ( T_6 ) V_4 -> V_335 [ 4 ] ;
if ( V_307 == 0 )
V_307 = 256 ;
break;
case V_338 :
V_304 = true ;
case V_339 :
V_297 = ( V_32 ) F_61 ( & V_4 -> V_335 [ 2 ] ) ;
V_307 = ( T_6 ) F_127 ( & V_4 -> V_335 [ 7 ] ) ;
break;
case V_340 :
V_304 = true ;
case V_341 :
V_297 = ( V_32 ) F_61 ( & V_4 -> V_335 [ 2 ] ) ;
V_307 = F_61 ( & V_4 -> V_335 [ 6 ] ) ;
break;
case V_342 :
V_304 = true ;
case V_343 :
V_297 = F_84 ( & V_4 -> V_335 [ 2 ] ) ;
V_307 = F_61 ( & V_4 -> V_335 [ 10 ] ) ;
break;
default:
return V_344 ;
}
if ( V_304 && V_13 -> V_1 != V_345 )
return V_344 ;
if ( F_128 ( V_307 == 0 ) )
return V_344 ;
V_306 = V_297 + V_307 - 1 ;
V_150 = V_13 -> V_150 ;
if ( V_306 >= F_26 ( & V_150 -> V_346 ) ||
V_306 < V_297 )
return V_344 ;
V_160 = F_69 ( & V_150 -> V_160 ) ;
V_168 = F_69 ( & V_150 -> V_168 ) ;
V_159 = F_69 ( & V_150 -> V_159 ) ;
V_308 = V_160 * V_168 ;
#if V_333 == 32
V_334 = V_297 ;
F_129 ( V_334 , V_308 ) ;
V_309 = V_334 ;
V_334 = V_306 ;
F_129 ( V_334 , V_308 ) ;
V_310 = V_334 ;
V_311 = ( T_6 ) ( V_297 - ( V_309 * V_308 ) ) ;
V_312 = ( T_6 ) ( V_306 - ( V_310 * V_308 ) ) ;
V_334 = V_311 ;
F_129 ( V_334 , V_168 ) ;
V_313 = V_334 ;
V_334 = V_312 ;
F_129 ( V_334 , V_168 ) ;
V_314 = V_334 ;
#else
V_309 = V_297 / V_308 ;
V_310 = V_306 / V_308 ;
V_311 = ( T_6 ) ( V_297 - ( V_309 * V_308 ) ) ;
V_312 = ( T_6 ) ( V_306 - ( V_310 * V_308 ) ) ;
V_313 = V_311 / V_168 ;
V_314 = V_312 / V_168 ;
#endif
if ( V_309 != V_310 || V_313 != V_314 )
return V_344 ;
V_323 = V_160 +
F_69 ( & V_150 -> V_161 ) ;
V_328 = ( ( T_6 ) ( V_309 >> V_150 -> V_347 ) ) %
F_69 ( & V_150 -> V_162 ) ;
V_305 = ( V_328 * V_323 ) + V_313 ;
if ( V_13 -> V_1 == V_164 ) {
if ( V_13 -> V_259 )
V_305 += V_160 ;
V_13 -> V_259 = ! V_13 -> V_259 ;
} else if ( V_13 -> V_1 == V_165 ) {
V_259 = V_13 -> V_259 ;
if ( V_259 == 0 ) {
V_305 %= V_160 ;
} else {
do {
V_327 = V_305 / V_160 ;
if ( V_259 != V_327 ) {
if ( V_327 <
V_159 - 1 ) {
V_305 += V_160 ;
V_327 ++ ;
} else {
V_305 %= V_160 ;
V_327 = 0 ;
}
}
} while ( V_259 != V_327 );
}
V_259 =
( V_259 >= V_159 - 1 ) ?
0 : V_259 + 1 ;
F_34 ( V_259 >= V_159 ) ;
V_13 -> V_259 = V_259 ;
} else if ( ( V_13 -> V_1 == V_166 ||
V_13 -> V_1 == V_167 ) && V_159 > 1 ) {
V_153 = V_168 * V_160 ;
V_324 = V_153 * V_159 ;
#if V_333 == 32
V_334 = V_297 ;
V_325 = F_129 ( V_334 , V_324 ) ;
V_334 = V_325 ;
F_129 ( V_334 , V_153 ) ;
V_325 = V_334 ;
V_334 = V_306 ;
V_326 = F_129 ( V_334 , V_324 ) ;
V_334 = V_326 ;
F_129 ( V_334 , V_153 ) ;
V_326 = V_334 ;
#else
V_325 = ( V_297 % V_324 ) / V_153 ;
V_326 = ( V_306 % V_324 ) / V_153 ;
#endif
if ( V_325 != V_326 )
return V_344 ;
#if V_333 == 32
V_334 = V_297 ;
F_129 ( V_334 , V_324 ) ;
V_309 = V_317 = V_315 = V_334 ;
V_334 = V_306 ;
F_129 ( V_334 , V_324 ) ;
V_318 = V_316 = V_334 ;
#else
V_309 = V_317 = V_315 =
V_297 / V_324 ;
V_318 = V_316 = V_306 / V_324 ;
#endif
if ( V_317 != V_318 )
return V_344 ;
#if V_333 == 32
V_334 = V_297 ;
V_311 = F_129 ( V_334 , V_324 ) ;
V_334 = V_311 ;
V_311 = ( T_6 ) F_129 ( V_334 , V_153 ) ;
V_319 = V_311 ;
V_334 = V_306 ;
V_320 = F_129 ( V_334 , V_324 ) ;
V_334 = V_320 ;
V_320 = F_129 ( V_334 , V_153 ) ;
V_334 = V_319 ;
F_129 ( V_334 , V_168 ) ;
V_313 = V_321 = V_334 ;
V_334 = V_320 ;
F_129 ( V_334 , V_168 ) ;
V_322 = V_334 ;
#else
V_311 = V_319 =
( T_6 ) ( ( V_297 % V_324 ) %
V_153 ) ;
V_320 =
( T_6 ) ( ( V_306 % V_324 ) %
V_153 ) ;
V_313 = V_319 / V_168 ;
V_321 = V_313 ;
V_322 = V_320 / V_168 ;
#endif
if ( V_321 != V_322 )
return V_344 ;
V_328 =
( ( T_6 ) ( V_309 >> V_150 -> V_347 ) ) %
F_69 ( & V_150 -> V_162 ) ;
V_305 = ( V_325 *
( F_69 ( & V_150 -> V_162 ) *
V_323 ) ) +
( V_328 * V_323 ) + V_313 ;
}
if ( F_128 ( V_305 >= V_163 ) )
return V_344 ;
V_233 = V_150 -> V_157 [ V_305 ] . V_233 ;
V_329 = F_26 ( & V_150 -> V_348 ) +
V_309 * V_168 +
( V_311 - V_313 * V_168 ) ;
V_330 = V_307 ;
if ( V_150 -> V_349 ) {
V_329 <<= V_150 -> V_349 ;
V_330 <<= V_150 -> V_349 ;
}
if ( F_128 ( V_330 > 0xffff ) )
return V_344 ;
if ( V_329 > 0xffffffff ) {
V_45 [ 0 ] = V_304 ? V_342 : V_343 ;
V_45 [ 1 ] = 0 ;
F_130 ( V_329 , & V_45 [ 2 ] ) ;
F_31 ( V_330 , & V_45 [ 10 ] ) ;
V_45 [ 14 ] = 0 ;
V_45 [ 15 ] = 0 ;
V_331 = 16 ;
} else {
V_45 [ 0 ] = V_304 ? V_338 : V_339 ;
V_45 [ 1 ] = 0 ;
F_31 ( ( T_6 ) V_329 , & V_45 [ 2 ] ) ;
V_45 [ 6 ] = 0 ;
F_32 ( ( T_4 ) V_330 , & V_45 [ 7 ] ) ;
V_45 [ 9 ] = 0 ;
V_331 = 10 ;
}
if ( F_69 ( & V_150 -> V_36 ) &
V_350 ) {
F_123 ( & V_296 , V_150 ,
V_297 ) ;
V_332 = & V_296 ;
} else {
V_332 = NULL ;
}
return F_131 ( V_15 , V_4 , V_233 ,
V_45 , V_331 , V_303 , V_332 ) ;
}
static int F_132 ( struct V_8 * V_15 )
{
struct V_351 T_7 * V_352 ;
unsigned long V_353 ;
V_32 V_354 ;
T_1 V_86 ;
V_352 = V_15 -> V_352 ;
V_353 = ( V_355 * V_356 ) + V_357 ;
while ( 1 ) {
V_354 = F_133 ( & V_352 -> V_354 ) ;
if ( memcmp ( & V_354 , V_358 ,
sizeof( V_354 ) ) == 0 )
break;
if ( F_134 ( V_357 , V_353 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_50 ) ;
return - V_359 ;
}
F_135 ( V_360 ) ;
}
while ( 1 ) {
V_86 = F_136 ( & V_352 -> V_361 ) ;
if ( V_86 == V_362 )
break;
if ( F_134 ( V_357 , V_353 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_51 ) ;
return - V_359 ;
}
F_135 ( V_360 ) ;
}
while ( 1 ) {
if ( F_137 ( & V_352 -> V_363 ) ==
V_364 )
break;
if ( F_134 ( V_357 , V_353 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_52 ) ;
return - V_359 ;
}
F_135 ( V_360 ) ;
}
return 0 ;
}
static inline void F_138 ( struct V_80 * V_81 )
{
struct V_12 * V_13 ;
V_13 = V_81 -> V_4 -> V_13 -> V_11 ;
V_13 -> V_239 = false ;
}
static inline void F_139 ( struct V_365 * V_241 )
{
struct V_8 * V_15 ;
struct V_12 * V_13 ;
if ( F_140 ( V_241 ) ) {
F_141 ( V_241 , V_366 ) ;
V_15 = F_5 ( V_241 -> V_367 ) ;
F_18 ( & V_15 -> V_21 , 0 ) ;
V_13 = V_241 -> V_11 ;
F_33 ( & V_15 -> V_23 -> V_75 , L_53 ,
V_15 -> V_231 -> V_232 , V_13 -> V_139 ,
V_13 -> V_140 , V_13 -> V_141 ) ;
}
}
static void F_142 ( struct V_80 * V_81 )
{
T_1 V_368 ;
T_1 V_369 ;
struct V_3 * V_4 ;
struct V_370 * V_87 ;
T_2 V_371 ;
int V_372 ;
int V_373 ;
struct V_374 V_375 ;
V_4 = V_81 -> V_4 ;
if ( ! V_4 )
return;
V_87 = V_81 -> V_87 ;
V_368 = V_87 -> V_86 ;
V_369 = V_376 ;
if ( V_87 -> V_377 == V_378 ) {
V_373 =
F_27 ( & V_87 -> V_379 ) ;
V_372 = F_143 ( V_4 ) - V_373 ;
F_144 ( V_4 , V_372 ) ;
if ( V_373 < V_4 -> V_380 )
V_369 = V_381 ;
}
V_371 = F_69 ( & V_87 -> V_371 ) ;
if ( V_371 == 0 )
V_371 =
F_69 ( & V_87 -> V_382 ) ;
if ( V_371 ) {
if ( V_371 > sizeof( V_87 -> V_383 ) )
V_371 = sizeof( V_87 -> V_383 ) ;
if ( V_368 == V_384 &&
F_145 ( V_87 -> V_383 ,
V_371 , & V_375 ) &&
V_375 . V_385 == V_386 &&
V_375 . V_387 == 0x3e &&
V_375 . V_388 == 0x1 ) {
F_139 ( V_4 -> V_13 ) ;
V_369 = V_389 ;
}
if ( V_371 > V_390 )
V_371 = V_390 ;
memcpy ( V_4 -> V_391 , V_87 -> V_383 ,
V_371 ) ;
}
V_4 -> V_392 = V_368 ;
F_146 ( V_4 , V_369 ) ;
}
static void F_147 ( struct V_80 * V_81 )
{
T_1 V_368 ;
T_1 V_369 ;
struct V_3 * V_4 ;
struct V_393 * V_87 ;
T_2 V_371 ;
int V_372 ;
int V_373 ;
bool V_394 ;
V_4 = V_81 -> V_4 ;
V_87 = V_81 -> V_87 ;
V_369 = V_376 ;
V_371 = 0 ;
V_394 = false ;
switch ( V_87 -> V_395 ) {
case V_396 :
V_368 = V_87 -> V_86 ;
break;
case V_397 :
switch ( V_87 -> V_86 ) {
case V_398 :
V_368 = V_399 ;
break;
case V_400 :
V_368 = V_401 ;
V_372 = F_27 (
& V_87 -> V_372 ) ;
F_144 ( V_4 , V_372 ) ;
V_373 = F_143 ( V_4 ) - V_372 ;
if ( V_373 < V_4 -> V_380 )
V_369 = V_381 ;
break;
case V_402 :
V_368 = V_401 ;
break;
case V_403 :
F_138 ( V_81 ) ;
V_368 = V_401 ;
V_81 -> V_86 = - V_404 ;
break;
case V_405 :
case V_406 :
V_394 = true ;
F_139 ( V_4 -> V_13 ) ;
V_369 = V_389 ;
V_368 = V_384 ;
break;
case V_407 :
default:
V_368 = V_384 ;
break;
}
break;
case V_408 :
case V_409 :
V_368 = V_401 ;
break;
case V_410 :
case V_411 :
default:
V_368 = V_384 ;
break;
}
if ( V_87 -> V_412 ) {
V_371 =
F_69 ( & V_87 -> V_413 ) ;
if ( V_371 ) {
if ( V_371 > sizeof( V_87 -> V_383 ) )
V_371 = sizeof( V_87 -> V_383 ) ;
if ( V_371 > V_390 )
V_371 = V_390 ;
memcpy ( V_4 -> V_391 , V_87 -> V_383 ,
V_371 ) ;
}
}
if ( V_394 && V_371 == 0 )
F_148 ( 0 , V_4 -> V_391 , V_386 ,
0x3e , 0x1 ) ;
V_4 -> V_392 = V_368 ;
F_146 ( V_4 , V_369 ) ;
}
static void F_149 ( unsigned int V_48 ,
struct V_80 * V_81 )
{
switch ( V_48 ) {
case V_414 :
F_142 ( V_81 ) ;
break;
case V_415 :
F_147 ( V_81 ) ;
break;
}
}
static int F_150 (
struct V_416 * V_417 )
{
int V_89 ;
switch ( V_417 -> V_418 ) {
case V_419 :
case V_420 :
V_89 = 0 ;
break;
default:
V_89 = - V_421 ;
break;
}
return V_89 ;
}
static unsigned int F_151 ( struct V_8 * V_15 ,
struct V_302 * V_303 )
{
unsigned int V_422 ;
T_8 V_423 ;
T_8 V_424 ;
struct V_80 * V_81 ;
struct V_425 * V_417 ;
T_4 V_426 ;
V_422 = 0 ;
V_424 = V_303 -> V_427 ;
while ( 1 ) {
V_423 = * V_303 -> V_423 ;
if ( V_423 == V_424 )
break;
V_422 ++ ;
V_417 = V_303 -> V_428 +
( V_424 * V_429 ) ;
V_426 = F_69 ( & V_417 -> V_426 ) ;
F_34 ( V_426 >= V_15 -> V_85 ) ;
V_81 = & V_15 -> V_83 [ V_426 ] ;
F_34 ( F_152 ( & V_81 -> V_84 ) == 0 ) ;
switch ( V_417 -> V_47 . V_48 ) {
case V_430 :
case V_431 :
case V_432 :
break;
case V_433 :
V_81 -> V_86 =
F_150 (
( void * ) V_417 ) ;
break;
case V_434 :
F_138 ( V_81 ) ;
V_81 -> V_86 = - V_404 ;
break;
case V_414 :
case V_415 :
V_81 -> V_87 = V_15 -> V_435 +
( F_69 ( & V_417 -> V_436 ) *
V_437 ) ;
F_149 ( V_417 -> V_47 . V_48 ,
V_81 ) ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_54 ,
V_417 -> V_47 . V_48 ) ;
F_34 ( V_417 -> V_47 . V_48 ) ;
break;
}
V_81 -> V_438 ( V_81 ,
V_81 -> V_439 ) ;
V_424 = ( V_424 + 1 ) % V_15 -> V_440 ;
}
if ( V_422 ) {
V_303 -> V_427 = V_424 ;
F_153 ( V_424 , V_303 -> V_424 ) ;
}
return V_422 ;
}
static inline unsigned int F_154 ( unsigned int V_441 ,
unsigned int V_442 , unsigned int V_443 )
{
unsigned int V_444 ;
if ( V_441 >= V_442 )
V_444 = V_441 - V_442 ;
else
V_444 = V_443 - V_442 + V_441 ;
return V_443 - V_444 - 1 ;
}
static void F_155 ( struct V_8 * V_15 ,
struct V_445 * V_446 , T_2 V_52 )
{
T_8 V_447 ;
T_8 V_448 ;
unsigned long V_36 ;
void * V_449 ;
unsigned long V_353 ;
struct V_302 * V_303 ;
V_303 = & V_15 -> V_450 [ V_451 ] ;
F_29 ( V_303 -> V_452 , & V_446 -> V_47 . V_453 ) ;
V_353 = ( V_454 * V_356 ) + V_357 ;
while ( 1 ) {
F_102 ( & V_303 -> V_455 [ V_456 ] , V_36 ) ;
V_447 = V_303 -> V_457 [ V_456 ] ;
V_448 = * V_303 -> V_448 [ V_456 ] ;
if ( F_154 ( V_447 , V_448 ,
V_15 -> V_458 ) )
break;
F_104 (
& V_303 -> V_455 [ V_456 ] , V_36 ) ;
if ( F_134 ( V_357 , V_353 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_55 ) ;
return;
}
}
V_449 = V_303 -> V_459 [ V_456 ] +
( V_447 * V_460 ) ;
memcpy ( V_449 , V_446 , V_52 ) ;
V_447 = ( V_447 + 1 ) % V_15 -> V_458 ;
V_303 -> V_457 [ V_456 ] = V_447 ;
F_153 ( V_447 , V_303 -> V_447 [ V_456 ] ) ;
F_104 ( & V_303 -> V_455 [ V_456 ] , V_36 ) ;
}
static void F_156 ( struct V_8 * V_15 ,
struct V_461 * V_462 )
{
struct V_445 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_463 ;
F_29 ( sizeof( V_41 ) - V_51 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_464 = V_462 -> V_464 ;
V_41 . V_465 = V_462 -> V_465 ;
V_41 . V_466 = V_462 -> V_466 ;
F_155 ( V_15 , & V_41 , sizeof( V_41 ) ) ;
}
static void F_157 ( struct V_119 * V_120 )
{
unsigned int V_39 ;
struct V_8 * V_15 ;
struct V_461 * V_467 ;
bool V_468 = false ;
V_15 = F_55 ( V_120 , struct V_8 , V_469 ) ;
V_467 = V_15 -> V_470 ;
for ( V_39 = 0 ; V_39 < V_471 ; V_39 ++ ) {
if ( V_467 -> V_472 ) {
V_467 -> V_472 = false ;
F_156 ( V_15 , V_467 ) ;
if ( V_39 != V_473 )
V_468 = true ;
}
V_467 ++ ;
}
if ( V_468 )
F_17 ( V_15 ) ;
}
static void F_11 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
unsigned int V_474 ;
struct V_302 * V_303 ;
unsigned long V_36 ;
struct V_80 * V_81 ;
struct V_80 * V_266 ;
struct V_3 * V_4 ;
V_15 -> V_16 = false ;
F_33 ( & V_15 -> V_23 -> V_75 , L_56 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_303 = & V_15 -> V_450 [ V_39 ] ;
for ( V_474 = 0 ; V_474 < 2 ; V_474 ++ ) {
F_102 (
& V_303 -> V_455 [ V_474 ] , V_36 ) ;
F_107 (io_request, next,
&queue_group->request_list[path],
request_list_entry) {
V_4 = V_81 -> V_4 ;
if ( V_4 ) {
F_146 ( V_4 , V_389 ) ;
F_3 ( V_4 ) ;
}
F_103 ( & V_81 -> V_476 ) ;
}
F_104 (
& V_303 -> V_455 [ V_474 ] , V_36 ) ;
}
}
}
static void F_158 ( unsigned long V_383 )
{
int V_477 ;
struct V_8 * V_15 = (struct V_8 * ) V_383 ;
V_477 = F_152 ( & V_15 -> V_477 ) ;
if ( V_477 == V_15 -> V_478 ) {
V_15 -> V_479 ++ ;
if ( V_15 -> V_479 >
V_480 ) {
F_11 ( V_15 ) ;
return;
}
V_15 -> V_470 [ V_473 ] . V_472 = true ;
F_159 ( & V_15 -> V_469 ) ;
} else {
V_15 -> V_479 = 0 ;
}
V_15 -> V_478 = V_477 ;
F_160 ( & V_15 -> V_481 ,
V_357 + V_482 ) ;
}
static void F_161 ( struct V_8 * V_15 )
{
V_15 -> V_478 =
F_152 ( & V_15 -> V_477 ) ;
F_162 ( & V_15 -> V_481 ) ;
V_15 -> V_481 . V_483 =
V_357 + V_482 ;
V_15 -> V_481 . V_383 = ( unsigned long ) V_15 ;
V_15 -> V_481 . V_484 = F_158 ;
F_163 ( & V_15 -> V_481 ) ;
V_15 -> V_485 = true ;
}
static inline void F_164 ( struct V_8 * V_15 )
{
if ( V_15 -> V_485 )
F_165 ( & V_15 -> V_481 ) ;
}
static int F_166 ( unsigned int V_464 )
{
int V_486 ;
switch ( V_464 ) {
case V_487 :
V_486 = V_473 ;
break;
case V_488 :
V_486 = V_489 ;
break;
case V_490 :
V_486 = V_491 ;
break;
case V_492 :
V_486 = V_493 ;
break;
case V_494 :
V_486 = V_495 ;
break;
case V_496 :
V_486 = V_497 ;
break;
case V_498 :
V_486 = V_499 ;
break;
default:
V_486 = - 1 ;
break;
}
return V_486 ;
}
static unsigned int F_167 ( struct V_8 * V_15 )
{
unsigned int V_500 ;
T_8 V_423 ;
T_8 V_424 ;
struct V_501 * V_502 ;
struct V_503 * V_417 ;
struct V_461 * V_467 ;
bool V_504 ;
int V_505 ;
V_502 = & V_15 -> V_502 ;
V_500 = 0 ;
V_504 = false ;
V_424 = V_502 -> V_427 ;
while ( 1 ) {
V_423 = * V_502 -> V_423 ;
if ( V_423 == V_424 )
break;
V_500 ++ ;
V_417 = V_502 -> V_428 +
( V_424 * V_506 ) ;
V_505 =
F_166 ( V_417 -> V_464 ) ;
if ( V_505 >= 0 ) {
if ( V_417 -> V_507 ) {
V_467 =
& V_15 -> V_470 [ V_505 ] ;
V_467 -> V_464 =
V_417 -> V_464 ;
V_467 -> V_465 = V_417 -> V_465 ;
V_467 -> V_466 =
V_417 -> V_466 ;
if ( V_505 != V_473 ) {
V_467 -> V_472 = true ;
V_504 = true ;
}
}
}
V_424 = ( V_424 + 1 ) % V_508 ;
}
if ( V_500 ) {
V_502 -> V_427 = V_424 ;
F_153 ( V_424 , V_502 -> V_424 ) ;
if ( V_504 )
F_159 ( & V_15 -> V_469 ) ;
}
return V_500 ;
}
static T_9 F_168 ( int V_509 , void * V_383 )
{
struct V_8 * V_15 ;
struct V_302 * V_303 ;
unsigned int V_510 ;
V_303 = V_383 ;
V_15 = V_303 -> V_15 ;
if ( ! V_15 || ! V_303 -> V_424 )
return V_511 ;
V_510 = F_151 ( V_15 , V_303 ) ;
if ( V_509 == V_15 -> V_512 )
V_510 += F_167 ( V_15 ) ;
if ( V_510 )
F_169 ( & V_15 -> V_477 ) ;
F_170 ( V_15 , V_303 , V_456 , NULL ) ;
F_170 ( V_15 , V_303 , V_513 , NULL ) ;
return V_514 ;
}
static int F_171 ( struct V_8 * V_15 )
{
struct V_23 * V_515 = V_15 -> V_23 ;
int V_39 ;
int V_89 ;
V_15 -> V_512 = F_172 ( V_515 , 0 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_516 ; V_39 ++ ) {
V_89 = F_173 ( F_172 ( V_515 , V_39 ) , F_168 , 0 ,
V_517 , & V_15 -> V_450 [ V_39 ] ) ;
if ( V_89 ) {
F_33 ( & V_515 -> V_75 ,
L_57 ,
F_172 ( V_515 , V_39 ) , V_89 ) ;
return V_89 ;
}
V_15 -> V_518 ++ ;
}
return 0 ;
}
static int F_174 ( struct V_8 * V_15 )
{
int V_519 ;
V_519 = F_175 ( V_15 -> V_23 ,
V_520 , V_15 -> V_475 ,
V_521 | V_522 ) ;
if ( V_519 < 0 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_58 , V_519 ) ;
return V_519 ;
}
V_15 -> V_516 = V_519 ;
return 0 ;
}
static int F_176 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
T_2 V_523 ;
T_2 V_524 ;
T_2 V_525 ;
void * V_526 ;
void * V_527 ;
void * V_528 ;
unsigned int V_529 ;
unsigned int V_530 ;
unsigned int V_531 ;
struct V_302 * V_303 ;
V_524 =
V_460 *
V_15 -> V_458 ;
V_525 =
V_429 *
V_15 -> V_440 ;
V_529 = V_15 -> V_475 * 2 ;
V_530 = V_15 -> V_475 ;
V_531 = ( V_15 -> V_475 * 3 ) + 1 ;
V_528 = NULL ;
for ( V_39 = 0 ; V_39 < V_529 ; V_39 ++ ) {
V_528 = F_177 ( V_528 ,
V_532 ) ;
V_528 += V_524 ;
}
for ( V_39 = 0 ; V_39 < V_530 ; V_39 ++ ) {
V_528 = F_177 ( V_528 ,
V_532 ) ;
V_528 += V_525 ;
}
V_528 = F_177 ( V_528 ,
V_532 ) ;
V_528 += V_508 *
V_506 ;
for ( V_39 = 0 ; V_39 < V_531 ; V_39 ++ ) {
V_528 = F_177 ( V_528 ,
V_533 ) ;
V_528 += sizeof( T_8 ) ;
}
V_523 = ( T_2 ) V_528 +
V_532 ;
V_15 -> V_534 =
F_178 ( & V_15 -> V_23 -> V_75 ,
V_523 ,
& V_15 -> V_535 , V_95 ) ;
if ( ! V_15 -> V_534 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_59 ) ;
return - V_31 ;
}
V_15 -> V_536 = V_523 ;
V_526 = F_177 ( V_15 -> V_534 ,
V_532 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_303 = & V_15 -> V_450 [ V_39 ] ;
V_303 -> V_459 [ V_456 ] = V_526 ;
V_303 -> V_537 [ V_456 ] =
V_15 -> V_535 +
( V_526 - V_15 -> V_534 ) ;
V_526 += V_524 ;
V_526 = F_177 ( V_526 ,
V_532 ) ;
V_303 -> V_459 [ V_513 ] = V_526 ;
V_303 -> V_537 [ V_513 ] =
V_15 -> V_535 +
( V_526 - V_15 -> V_534 ) ;
V_526 += V_524 ;
V_526 = F_177 ( V_526 ,
V_532 ) ;
}
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_303 = & V_15 -> V_450 [ V_39 ] ;
V_303 -> V_428 = V_526 ;
V_303 -> V_538 =
V_15 -> V_535 +
( V_526 - V_15 -> V_534 ) ;
V_526 += V_525 ;
V_526 = F_177 ( V_526 ,
V_532 ) ;
}
V_15 -> V_502 . V_428 = V_526 ;
V_15 -> V_502 . V_538 =
V_15 -> V_535 +
( V_526 - V_15 -> V_534 ) ;
V_526 += V_508 *
V_506 ;
V_527 = F_177 ( V_526 ,
V_533 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_303 = & V_15 -> V_450 [ V_39 ] ;
V_303 -> V_448 [ V_456 ] = V_527 ;
V_303 -> V_539 [ V_456 ] =
V_15 -> V_535 +
( V_527 - V_15 -> V_534 ) ;
V_527 += sizeof( T_8 ) ;
V_527 = F_177 ( V_527 ,
V_533 ) ;
V_303 -> V_448 [ V_513 ] = V_527 ;
V_303 -> V_539 [ V_513 ] =
V_15 -> V_535 +
( V_527 - V_15 -> V_534 ) ;
V_527 += sizeof( T_8 ) ;
V_527 = F_177 ( V_527 ,
V_533 ) ;
V_303 -> V_423 = V_527 ;
V_303 -> V_540 =
V_15 -> V_535 +
( V_527 - V_15 -> V_534 ) ;
V_527 += sizeof( T_8 ) ;
V_527 = F_177 ( V_527 ,
V_533 ) ;
}
V_15 -> V_502 . V_423 = V_527 ;
V_15 -> V_502 . V_540 =
V_15 -> V_535 +
( V_527 - V_15 -> V_534 ) ;
return 0 ;
}
static void F_179 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
T_4 V_541 = V_542 ;
T_4 V_543 = V_542 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ )
V_15 -> V_450 [ V_39 ] . V_15 = V_15 ;
V_15 -> V_502 . V_452 = V_543 ++ ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_15 -> V_450 [ V_39 ] . V_544 [ V_456 ] = V_541 ++ ;
V_15 -> V_450 [ V_39 ] . V_544 [ V_513 ] = V_541 ++ ;
V_15 -> V_450 [ V_39 ] . V_452 = V_543 ++ ;
}
V_15 -> V_502 . V_545 = 0 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ )
V_15 -> V_450 [ V_39 ] . V_545 = V_39 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
F_180 ( & V_15 -> V_450 [ V_39 ] . V_455 [ 0 ] ) ;
F_180 ( & V_15 -> V_450 [ V_39 ] . V_455 [ 1 ] ) ;
F_106 ( & V_15 -> V_450 [ V_39 ] . V_546 [ 0 ] ) ;
F_106 ( & V_15 -> V_450 [ V_39 ] . V_546 [ 1 ] ) ;
}
}
static int F_181 ( struct V_8 * V_15 )
{
T_2 V_523 ;
struct V_547 * V_548 ;
struct V_549 * V_550 ;
V_523 = sizeof( struct V_547 ) +
V_532 ;
V_15 -> V_551 =
F_178 ( & V_15 -> V_23 -> V_75 ,
V_523 ,
& V_15 -> V_552 ,
V_95 ) ;
if ( ! V_15 -> V_551 )
return - V_31 ;
V_15 -> V_553 = V_523 ;
V_550 = & V_15 -> V_550 ;
V_548 = F_177 ( V_15 -> V_551 ,
V_532 ) ;
V_550 -> V_459 =
& V_548 -> V_459 ;
V_550 -> V_428 =
& V_548 -> V_428 ;
V_550 -> V_448 = & V_548 -> V_448 ;
V_550 -> V_423 = & V_548 -> V_423 ;
V_550 -> V_537 =
V_15 -> V_552 +
( V_550 -> V_459 -
V_15 -> V_551 ) ;
V_550 -> V_538 =
V_15 -> V_552 +
( V_550 -> V_428 -
V_15 -> V_551 ) ;
V_550 -> V_539 =
V_15 -> V_552 +
( ( void * ) V_550 -> V_448 -
V_15 -> V_551 ) ;
V_550 -> V_540 =
V_15 -> V_552 +
( ( void * ) V_550 -> V_423 -
V_15 -> V_551 ) ;
return 0 ;
}
static int F_182 ( struct V_8 * V_15 )
{
struct V_351 T_7 * V_352 ;
struct V_549 * V_550 ;
unsigned long V_353 ;
T_1 V_86 ;
T_6 V_554 ;
V_352 = V_15 -> V_352 ;
V_550 = & V_15 -> V_550 ;
F_183 ( ( V_32 ) V_550 -> V_537 ,
& V_352 -> V_555 ) ;
F_183 ( ( V_32 ) V_550 -> V_538 ,
& V_352 -> V_556 ) ;
F_183 ( ( V_32 ) V_550 -> V_539 ,
& V_352 -> V_557 ) ;
F_183 ( ( V_32 ) V_550 -> V_540 ,
& V_352 -> V_558 ) ;
V_554 = V_559 |
( V_560 ) << 8 |
( V_550 -> V_545 << 16 ) ;
F_153 ( V_554 , & V_352 -> V_561 ) ;
F_153 ( V_562 ,
& V_352 -> V_361 ) ;
V_353 = V_563 + V_357 ;
while ( 1 ) {
V_86 = F_136 ( & V_352 -> V_361 ) ;
if ( V_86 == V_362 )
break;
if ( F_134 ( V_357 , V_353 ) )
return - V_359 ;
F_135 ( V_564 ) ;
}
V_550 -> V_447 = V_15 -> V_565 +
V_566 +
F_133 ( & V_352 -> V_567 ) ;
V_550 -> V_424 = V_15 -> V_565 +
V_566 +
F_133 ( & V_352 -> V_568 ) ;
return 0 ;
}
static void F_184 ( struct V_8 * V_15 ,
struct V_569 * V_41 )
{
struct V_549 * V_550 ;
void * V_449 ;
T_8 V_447 ;
V_550 = & V_15 -> V_550 ;
V_447 = V_550 -> V_457 ;
V_449 = V_550 -> V_459 +
( V_447 * V_570 ) ;
memcpy ( V_449 , V_41 , sizeof( * V_41 ) ) ;
V_447 = ( V_447 + 1 ) % V_559 ;
V_550 -> V_457 = V_447 ;
F_153 ( V_447 , V_550 -> V_447 ) ;
}
static int F_185 ( struct V_8 * V_15 ,
struct V_571 * V_417 )
{
struct V_549 * V_550 ;
T_8 V_423 ;
T_8 V_424 ;
unsigned long V_353 ;
V_550 = & V_15 -> V_550 ;
V_424 = V_550 -> V_427 ;
V_353 = ( 3 * V_356 ) + V_357 ;
while ( 1 ) {
V_423 = * V_550 -> V_423 ;
if ( V_423 != V_424 )
break;
if ( F_134 ( V_357 , V_353 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_60 ) ;
return - V_359 ;
}
F_186 ( 1000 , 2000 ) ;
}
memcpy ( V_417 , V_550 -> V_428 +
( V_424 * V_572 ) , sizeof( * V_417 ) ) ;
V_424 = ( V_424 + 1 ) % V_560 ;
V_550 -> V_427 = V_424 ;
F_153 ( V_424 , V_550 -> V_424 ) ;
return 0 ;
}
static void F_170 ( struct V_8 * V_15 ,
struct V_302 * V_303 , enum V_573 V_474 ,
struct V_80 * V_81 )
{
struct V_80 * V_266 ;
void * V_449 ;
T_8 V_447 ;
T_8 V_448 ;
T_2 V_52 ;
unsigned long V_36 ;
unsigned int V_574 ;
unsigned int V_575 ;
T_2 V_576 ;
struct V_577 * V_41 ;
F_102 ( & V_303 -> V_455 [ V_474 ] , V_36 ) ;
if ( V_81 )
F_108 ( & V_81 -> V_476 ,
& V_303 -> V_546 [ V_474 ] ) ;
V_447 = V_303 -> V_457 [ V_474 ] ;
F_107 (io_request, next,
&queue_group->request_list[path], request_list_entry) {
V_41 = V_81 -> V_446 ;
V_52 = F_69 ( & V_41 -> V_52 ) +
V_51 ;
V_574 =
F_187 ( V_52 ,
V_460 ) ;
V_448 = * V_303 -> V_448 [ V_474 ] ;
if ( V_574 > F_154 ( V_447 , V_448 ,
V_15 -> V_458 ) )
break;
F_29 ( V_303 -> V_452 ,
& V_41 -> V_453 ) ;
V_449 = V_303 -> V_459 [ V_474 ] +
( V_447 * V_460 ) ;
V_575 =
V_15 -> V_458 - V_447 ;
if ( V_574 <= V_575 ) {
memcpy ( V_449 , V_41 , V_52 ) ;
} else {
V_576 = V_575 *
V_460 ;
memcpy ( V_449 , V_41 , V_576 ) ;
memcpy ( V_303 -> V_459 [ V_474 ] ,
( T_1 * ) V_41 + V_576 ,
V_52 - V_576 ) ;
}
V_447 = ( V_447 + V_574 ) %
V_15 -> V_458 ;
F_103 ( & V_81 -> V_476 ) ;
}
if ( V_447 != V_303 -> V_457 [ V_474 ] ) {
V_303 -> V_457 [ V_474 ] = V_447 ;
F_153 ( V_447 , V_303 -> V_447 [ V_474 ] ) ;
}
F_104 ( & V_303 -> V_455 [ V_474 ] , V_36 ) ;
}
static void F_188 ( struct V_80 * V_81 ,
void * V_439 )
{
struct V_578 * V_579 = V_439 ;
F_189 ( V_579 ) ;
}
static int F_190 (
struct V_8 * V_15 , struct V_80 * V_81 ,
unsigned long V_580 )
{
int V_89 = 0 ;
F_191 ( V_581 ) ;
V_81 -> V_438 = F_188 ;
V_81 -> V_439 = & V_581 ;
F_170 ( V_15 ,
& V_15 -> V_450 [ V_451 ] , V_456 ,
V_81 ) ;
if ( V_580 == V_90 ) {
F_192 ( & V_581 ) ;
} else {
if ( ! F_193 ( & V_581 ,
F_194 ( V_580 ) ) ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_61 ) ;
V_89 = - V_359 ;
}
}
return V_89 ;
}
static int F_40 ( struct V_8 * V_15 ,
struct V_577 * V_41 , unsigned int V_36 ,
struct V_370 * V_87 , unsigned long V_580 )
{
int V_89 ;
struct V_80 * V_81 ;
unsigned long V_582 ;
unsigned long V_583 ;
T_2 V_52 ;
if ( V_36 & V_584 ) {
if ( F_195 ( & V_15 -> V_585 ) )
return - V_586 ;
} else {
if ( V_580 == V_90 ) {
F_196 ( & V_15 -> V_585 ) ;
} else {
V_582 = V_357 ;
if ( F_197 ( & V_15 -> V_585 ,
F_194 ( V_580 ) ) )
return - V_359 ;
V_583 =
F_198 ( V_357 - V_582 ) ;
if ( V_583 >= V_580 )
return - V_359 ;
V_580 -= V_583 ;
}
}
V_81 = F_35 ( V_15 ) ;
F_29 ( V_81 -> V_486 ,
& ( ( (struct V_40 * ) V_41 ) -> V_426 ) ) ;
if ( V_41 -> V_48 == V_49 )
( (struct V_40 * ) V_41 ) -> V_436 =
( (struct V_40 * ) V_41 ) -> V_426 ;
V_52 = F_69 ( & V_41 -> V_52 ) +
V_51 ;
memcpy ( V_81 -> V_446 , V_41 , V_52 ) ;
V_89 = F_190 ( V_15 ,
V_81 , V_580 ) ;
if ( V_87 ) {
if ( V_81 -> V_87 )
memcpy ( V_87 , V_81 -> V_87 ,
sizeof( * V_87 ) ) ;
else
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else if ( V_89 == 0 && V_81 -> V_87 ) {
T_1 V_368 ;
struct V_370 * V_587 ;
V_587 = V_81 -> V_87 ;
V_368 = V_587 -> V_86 ;
if ( V_368 == V_384 &&
V_587 -> V_377 ==
V_378 )
V_368 = V_401 ;
if ( V_368 != V_401 )
V_89 = - V_421 ;
}
F_38 ( V_81 ) ;
F_199 ( & V_15 -> V_585 ) ;
return V_89 ;
}
static int F_200 (
struct V_571 * V_417 , T_1 V_588 )
{
if ( V_417 -> V_47 . V_48 != V_589 )
return - V_169 ;
if ( F_69 ( & V_417 -> V_47 . V_52 ) !=
V_590 )
return - V_169 ;
if ( V_417 -> V_591 != V_588 )
return - V_169 ;
if ( V_417 -> V_86 != V_592 )
return - V_169 ;
return 0 ;
}
static int F_201 (
struct V_8 * V_15 ,
struct V_569 * V_41 ,
struct V_571 * V_417 )
{
int V_89 ;
F_184 ( V_15 , V_41 ) ;
V_89 = F_185 ( V_15 , V_417 ) ;
if ( V_89 == 0 )
V_89 = F_200 ( V_417 ,
V_41 -> V_591 ) ;
return V_89 ;
}
static int F_202 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_569 V_41 ;
struct V_571 V_417 ;
struct V_593 * V_594 ;
struct V_595 * V_596 ;
V_594 = F_49 ( sizeof( * V_594 ) , V_95 ) ;
if ( ! V_594 )
return - V_31 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 =
V_598 ;
F_23 ( sizeof( * V_594 ) ,
& V_41 . V_383 . V_599 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
& V_41 . V_383 . V_599 . V_25 ,
V_594 , sizeof( * V_594 ) ,
V_76 ) ;
if ( V_89 )
goto V_96;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
F_24 ( V_15 -> V_23 ,
& V_41 . V_383 . V_599 . V_25 , 1 ,
V_76 ) ;
if ( V_89 )
goto V_96;
if ( V_417 . V_86 != V_592 ) {
V_89 = - V_421 ;
goto V_96;
}
V_15 -> V_600 =
F_69 ( & V_594 -> V_600 ) ;
V_15 -> V_601 =
F_69 ( & V_594 -> V_601 ) ;
V_15 -> V_602 =
F_69 ( & V_594 -> V_602 )
* 16 ;
V_15 -> V_603 =
F_69 ( & V_594 -> V_603 ) ;
V_15 -> V_604 =
F_69 ( & V_594 -> V_604 ) ;
V_15 -> V_605 =
F_69 ( & V_594 -> V_605 )
* 16 ;
V_596 =
& V_594 -> V_606 [ V_607 ] ;
V_15 -> V_608 =
F_69 (
& V_596 -> V_609 ) ;
V_15 -> V_610 =
V_596 -> V_610 ;
V_15 -> V_611 =
V_596 -> V_611 ;
V_96:
F_46 ( V_594 ) ;
return V_89 ;
}
static int F_203 ( struct V_8 * V_15 )
{
if ( V_15 -> V_602 <
V_460 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_62 ,
V_15 -> V_602 ,
V_460 ) ;
return - V_169 ;
}
if ( V_15 -> V_605 <
V_429 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_63 ,
V_15 -> V_605 ,
V_429 ) ;
return - V_169 ;
}
if ( V_15 -> V_608 <
V_460 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_64 ,
V_15 -> V_608 ,
V_460 ) ;
return - V_169 ;
}
if ( ! V_15 -> V_610 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_65 ) ;
return - V_169 ;
}
if ( V_15 -> V_611 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_66 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_204 ( struct V_8 * V_15 ,
bool V_612 , T_4 V_613 )
{
struct V_569 V_41 ;
struct V_571 V_417 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
if ( V_612 )
V_41 . V_591 =
V_614 ;
else
V_41 . V_591 =
V_615 ;
F_29 ( V_613 ,
& V_41 . V_383 . V_616 . V_613 ) ;
return F_201 ( V_15 , & V_41 ,
& V_417 ) ;
}
static int F_205 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_501 * V_502 ;
struct V_569 V_41 ;
struct V_571 V_417 ;
V_502 = & V_15 -> V_502 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 = V_617 ;
F_29 ( V_502 -> V_452 ,
& V_41 . V_383 . V_618 . V_613 ) ;
F_22 ( ( V_32 ) V_502 -> V_538 ,
& V_41 . V_383 . V_618 . V_619 ) ;
F_22 ( ( V_32 ) V_502 -> V_540 ,
& V_41 . V_383 . V_618 . V_620 ) ;
F_29 ( V_508 ,
& V_41 . V_383 . V_618 . V_621 ) ;
F_29 ( V_506 / 16 ,
& V_41 . V_383 . V_618 . V_622 ) ;
V_41 . V_383 . V_618 . V_623 = V_607 ;
F_29 ( V_502 -> V_545 ,
& V_41 . V_383 . V_618 . V_545 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
if ( V_89 )
return V_89 ;
V_502 -> V_424 = V_15 -> V_565 +
V_566 +
F_26 (
& V_417 . V_383 . V_618 . V_624 ) ;
return 0 ;
}
static int F_206 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
int V_89 ;
struct V_302 * V_303 ;
struct V_569 V_41 ;
struct V_571 V_417 ;
V_39 = V_15 -> V_625 ;
V_303 = & V_15 -> V_450 [ V_39 ] ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 = V_626 ;
F_29 ( V_303 -> V_544 [ V_456 ] ,
& V_41 . V_383 . V_627 . V_613 ) ;
F_22 (
( V_32 ) V_303 -> V_537 [ V_456 ] ,
& V_41 . V_383 . V_627 . V_619 ) ;
F_22 ( ( V_32 ) V_303 -> V_539 [ V_456 ] ,
& V_41 . V_383 . V_627 . V_628 ) ;
F_29 ( V_15 -> V_458 ,
& V_41 . V_383 . V_627 . V_621 ) ;
F_29 ( V_460 / 16 ,
& V_41 . V_383 . V_627 . V_622 ) ;
V_41 . V_383 . V_627 . V_623 = V_607 ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_67 ) ;
return V_89 ;
}
V_303 -> V_447 [ V_456 ] = V_15 -> V_565 +
V_566 +
F_26 (
& V_417 . V_383 . V_627 . V_629 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 = V_626 ;
F_29 ( V_303 -> V_544 [ V_513 ] ,
& V_41 . V_383 . V_627 . V_613 ) ;
F_22 ( ( V_32 ) V_303 ->
V_537 [ V_513 ] ,
& V_41 . V_383 . V_627 . V_619 ) ;
F_22 ( ( V_32 ) V_303 -> V_539 [ V_513 ] ,
& V_41 . V_383 . V_627 . V_628 ) ;
F_29 ( V_15 -> V_458 ,
& V_41 . V_383 . V_627 . V_621 ) ;
F_29 ( V_460 / 16 ,
& V_41 . V_383 . V_627 . V_622 ) ;
V_41 . V_383 . V_627 . V_623 = V_607 ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_68 ) ;
goto V_630;
}
V_303 -> V_447 [ V_513 ] = V_15 -> V_565 +
V_566 +
F_26 (
& V_417 . V_383 . V_627 . V_629 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 = V_631 ;
F_29 ( V_303 -> V_544 [ V_513 ] ,
& V_41 . V_383 . V_632 . V_613 ) ;
F_23 ( V_633 ,
& V_41 . V_383 . V_632 . V_634 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_69 ) ;
goto V_635;
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_597 ;
F_29 ( V_590 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_591 = V_617 ;
F_29 ( V_303 -> V_452 ,
& V_41 . V_383 . V_618 . V_613 ) ;
F_22 ( ( V_32 ) V_303 -> V_538 ,
& V_41 . V_383 . V_618 . V_619 ) ;
F_22 ( ( V_32 ) V_303 -> V_540 ,
& V_41 . V_383 . V_618 . V_620 ) ;
F_29 ( V_15 -> V_440 ,
& V_41 . V_383 . V_618 . V_621 ) ;
F_29 ( V_429 / 16 ,
& V_41 . V_383 . V_618 . V_622 ) ;
V_41 . V_383 . V_618 . V_623 = V_607 ;
F_29 ( V_303 -> V_545 ,
& V_41 . V_383 . V_618 . V_545 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_417 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_70 ) ;
goto V_635;
}
V_303 -> V_424 = V_15 -> V_565 +
V_566 +
F_26 (
& V_417 . V_383 . V_618 . V_624 ) ;
V_15 -> V_625 ++ ;
return 0 ;
V_635:
F_204 ( V_15 , true ,
V_303 -> V_544 [ V_513 ] ) ;
V_630:
F_204 ( V_15 , true ,
V_303 -> V_544 [ V_456 ] ) ;
return V_89 ;
}
static int F_207 ( struct V_8 * V_15 )
{
int V_89 ;
unsigned int V_39 ;
V_89 = F_205 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_71 ) ;
return V_89 ;
}
for ( V_39 = 0 ; V_39 < V_15 -> V_475 ; V_39 ++ ) {
V_89 = F_206 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_72 ,
V_39 , V_15 -> V_475 ) ;
return V_89 ;
}
}
return 0 ;
}
static int F_208 ( struct V_8 * V_15 )
{
int V_89 ;
unsigned int V_39 ;
struct V_636 * V_637 ;
struct V_638 V_41 ;
V_637 = F_49 ( V_639 ,
V_95 ) ;
if ( ! V_637 )
return - V_31 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_640 ;
F_29 ( F_30 ( struct V_638 ,
V_383 . V_641 . V_50 [ 1 ] ) -
V_51 , & V_41 . V_47 . V_52 ) ;
F_23 ( V_639 ,
& V_41 . V_383 . V_641 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
V_41 . V_383 . V_641 . V_50 ,
V_637 , V_639 ,
V_76 ) ;
if ( V_89 )
goto V_96;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
0 , NULL , V_90 ) ;
F_24 ( V_15 -> V_23 ,
V_41 . V_383 . V_641 . V_50 , 1 ,
V_76 ) ;
if ( V_89 )
goto V_96;
for ( V_39 = 0 ; V_39 < V_637 -> V_642 ; V_39 ++ )
F_29 ( V_15 -> V_502 . V_452 ,
& V_637 -> V_37 [ V_39 ] . V_452 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_643 ;
F_29 ( F_30 ( struct V_638 ,
V_383 . V_641 . V_50 [ 1 ] ) -
V_51 , & V_41 . V_47 . V_52 ) ;
F_23 ( V_639 ,
& V_41 . V_383 . V_641 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
V_41 . V_383 . V_641 . V_50 ,
V_637 , V_639 ,
V_77 ) ;
if ( V_89 )
goto V_96;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 ,
V_41 . V_383 . V_641 . V_50 , 1 ,
V_77 ) ;
V_96:
F_46 ( V_637 ) ;
return V_89 ;
}
static void F_209 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
struct V_13 * V_75 ;
T_2 V_644 ;
struct V_80 * V_81 ;
if ( ! V_15 -> V_83 )
return;
V_75 = & V_15 -> V_23 -> V_75 ;
V_644 = V_15 -> V_644 ;
V_81 = V_15 -> V_83 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_85 ; V_39 ++ ) {
F_46 ( V_81 -> V_446 ) ;
if ( ! V_81 -> V_645 )
break;
F_210 ( V_75 , V_644 ,
V_81 -> V_645 ,
V_81 -> V_646 ) ;
V_81 ++ ;
}
F_46 ( V_15 -> V_83 ) ;
V_15 -> V_83 = NULL ;
}
static inline int F_211 ( struct V_8 * V_15 )
{
V_15 -> V_435 = F_178 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_647 ,
& V_15 -> V_648 , V_95 ) ;
if ( ! V_15 -> V_435 )
return - V_31 ;
return 0 ;
}
static int F_212 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
void * V_645 ;
T_2 V_644 ;
T_3 V_646 ;
struct V_13 * V_75 ;
struct V_80 * V_81 ;
V_15 -> V_83 = F_45 ( V_15 -> V_85 *
sizeof( V_15 -> V_83 [ 0 ] ) , V_95 ) ;
if ( ! V_15 -> V_83 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_73 ) ;
goto error;
}
V_75 = & V_15 -> V_23 -> V_75 ;
V_644 = V_15 -> V_644 ;
V_81 = V_15 -> V_83 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_85 ; V_39 ++ ) {
V_81 -> V_446 =
F_49 ( V_15 -> V_609 , V_95 ) ;
if ( ! V_81 -> V_446 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_74 ) ;
goto error;
}
V_645 = F_213 ( V_75 ,
V_644 , & V_646 ,
V_95 ) ;
if ( ! V_645 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_75 ) ;
goto error;
}
V_81 -> V_486 = V_39 ;
V_81 -> V_645 = V_645 ;
V_81 -> V_646 =
V_646 ;
V_81 ++ ;
}
return 0 ;
error:
F_209 ( V_15 ) ;
return - V_31 ;
}
static void F_214 ( struct V_8 * V_15 )
{
T_6 V_649 ;
T_6 V_650 ;
V_15 -> V_651 =
V_15 -> V_652 - V_653 ;
V_15 -> V_85 = V_15 -> V_652 ;
V_15 -> V_647 =
V_15 -> V_85 * V_437 ;
V_649 =
F_215 ( V_15 -> V_649 , V_654 ) ;
V_650 = V_649 / V_655 ;
V_650 ++ ;
V_650 = F_215 ( V_15 -> V_650 , V_650 ) ;
V_649 = ( V_650 - 1 ) * V_655 ;
V_15 -> V_644 =
V_650 * sizeof( struct V_24 ) ;
V_15 -> V_656 = V_650 ;
V_15 -> V_657 = V_649 / 512 ;
}
static void F_216 ( struct V_8 * V_15 )
{
int V_658 ;
int V_659 ;
int V_475 ;
T_4 V_458 ;
T_4 V_440 ;
V_659 = F_215 ( V_15 -> V_600 / 2 ,
V_15 -> V_603 - 1 ) ;
V_659 = F_215 ( V_659 , V_660 ) ;
V_658 = F_217 () ;
V_475 = F_215 ( V_658 , V_15 -> V_661 ) ;
V_475 = F_215 ( V_475 , V_659 ) ;
V_15 -> V_475 = V_475 ;
V_15 -> V_609 =
( V_15 -> V_608 /
V_460 ) *
V_460 ;
V_458 =
( V_15 -> V_609 /
V_460 ) ;
V_458 ++ ;
V_458 = F_215 ( V_458 ,
V_15 -> V_601 ) ;
V_440 = ( ( V_458 - 1 ) * 2 ) + 1 ;
V_440 = F_215 ( V_440 ,
V_15 -> V_604 ) ;
V_15 -> V_458 = V_458 ;
V_15 -> V_440 = V_440 ;
V_15 -> V_662 =
( ( V_15 -> V_609 -
V_460 ) /
sizeof( struct V_24 ) ) +
V_663 ;
}
static inline void F_218 (
struct V_24 * V_25 , struct V_664 * V_665 )
{
V_32 V_33 = ( V_32 ) F_219 ( V_665 ) ;
unsigned int V_34 = F_220 ( V_665 ) ;
F_22 ( V_33 , & V_25 -> V_33 ) ;
F_23 ( V_34 , & V_25 -> V_34 ) ;
F_23 ( 0 , & V_25 -> V_36 ) ;
}
static int F_221 ( struct V_8 * V_15 ,
struct V_40 * V_41 , struct V_3 * V_4 ,
struct V_80 * V_81 )
{
int V_39 ;
T_4 V_52 ;
int V_666 ;
bool V_667 ;
unsigned int V_668 ;
unsigned int V_662 ;
struct V_664 * V_665 ;
struct V_24 * V_25 ;
V_666 = F_222 ( V_4 ) ;
if ( V_666 < 0 )
return V_666 ;
V_52 = F_30 ( struct V_40 , V_50 ) -
V_51 ;
if ( V_666 == 0 )
goto V_96;
V_665 = F_223 ( V_4 ) ;
V_25 = V_41 -> V_50 ;
V_662 = V_15 -> V_662 - 1 ;
V_667 = false ;
V_668 = 0 ;
V_39 = 0 ;
while ( 1 ) {
F_218 ( V_25 , V_665 ) ;
if ( ! V_667 )
V_668 ++ ;
V_39 ++ ;
if ( V_39 == V_666 )
break;
V_25 ++ ;
if ( V_39 == V_662 ) {
F_22 (
( V_32 ) V_81 -> V_646 ,
& V_25 -> V_33 ) ;
F_23 ( ( V_666 - V_668 )
* sizeof( * V_25 ) ,
& V_25 -> V_34 ) ;
F_23 ( V_669 ,
& V_25 -> V_36 ) ;
V_667 = true ;
V_668 ++ ;
V_25 = V_81 -> V_645 ;
}
V_665 = F_224 ( V_665 ) ;
}
F_23 ( V_35 , & V_25 -> V_36 ) ;
V_41 -> V_670 = V_667 ;
V_52 += V_668 * sizeof( * V_25 ) ;
V_96:
F_29 ( V_52 , & V_41 -> V_47 . V_52 ) ;
return 0 ;
}
static int F_225 ( struct V_8 * V_15 ,
struct V_671 * V_41 , struct V_3 * V_4 ,
struct V_80 * V_81 )
{
int V_39 ;
T_4 V_52 ;
int V_666 ;
bool V_667 ;
unsigned int V_668 ;
unsigned int V_662 ;
struct V_664 * V_665 ;
struct V_24 * V_25 ;
V_666 = F_222 ( V_4 ) ;
if ( V_666 < 0 )
return V_666 ;
V_52 = F_30 ( struct V_671 , V_50 ) -
V_51 ;
V_668 = 0 ;
if ( V_666 == 0 )
goto V_96;
V_665 = F_223 ( V_4 ) ;
V_25 = V_41 -> V_50 ;
V_662 = V_15 -> V_662 - 1 ;
V_667 = false ;
V_39 = 0 ;
while ( 1 ) {
F_218 ( V_25 , V_665 ) ;
if ( ! V_667 )
V_668 ++ ;
V_39 ++ ;
if ( V_39 == V_666 )
break;
V_25 ++ ;
if ( V_39 == V_662 ) {
F_22 (
( V_32 ) V_81 -> V_646 ,
& V_25 -> V_33 ) ;
F_23 ( ( V_666 - V_668 )
* sizeof( * V_25 ) ,
& V_25 -> V_34 ) ;
F_23 ( V_669 ,
& V_25 -> V_36 ) ;
V_667 = true ;
V_668 ++ ;
V_25 = V_81 -> V_645 ;
}
V_665 = F_224 ( V_665 ) ;
}
F_23 ( V_35 , & V_25 -> V_36 ) ;
V_41 -> V_670 = V_667 ;
V_52 += V_668 * sizeof( * V_25 ) ;
V_96:
F_29 ( V_52 , & V_41 -> V_47 . V_52 ) ;
V_41 -> V_672 = V_668 ;
return 0 ;
}
static void F_226 ( struct V_80 * V_81 ,
void * V_439 )
{
struct V_3 * V_4 ;
V_4 = V_81 -> V_4 ;
F_38 ( V_81 ) ;
F_227 ( V_4 ) ;
F_3 ( V_4 ) ;
}
static int F_228 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_302 * V_303 )
{
int V_89 ;
T_2 V_331 ;
struct V_80 * V_81 ;
struct V_40 * V_41 ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_438 = F_226 ;
V_81 -> V_4 = V_4 ;
V_4 -> V_673 = ( unsigned char * ) V_81 ;
V_41 = V_81 -> V_446 ;
memset ( V_41 , 0 ,
F_30 ( struct V_40 , V_50 ) ) ;
V_41 -> V_47 . V_48 = V_49 ;
F_23 ( F_143 ( V_4 ) , & V_41 -> V_27 ) ;
V_41 -> V_54 = V_55 ;
F_29 ( V_81 -> V_486 , & V_41 -> V_426 ) ;
V_41 -> V_436 = V_41 -> V_426 ;
memcpy ( V_41 -> V_53 , V_13 -> V_17 ,
sizeof( V_41 -> V_53 ) ) ;
V_331 = F_229 ( T_2 , V_4 -> V_674 , sizeof( V_41 -> V_45 ) ) ;
memcpy ( V_41 -> V_45 , V_4 -> V_335 , V_331 ) ;
switch ( V_331 ) {
case 6 :
case 10 :
case 12 :
case 16 :
V_41 -> V_56 =
V_57 ;
break;
case 20 :
V_41 -> V_56 =
V_675 ;
break;
case 24 :
V_41 -> V_56 =
V_676 ;
break;
case 28 :
V_41 -> V_56 =
V_677 ;
break;
case 32 :
default:
V_41 -> V_56 =
V_678 ;
break;
}
switch ( V_4 -> V_679 ) {
case V_680 :
V_41 -> V_28 = V_59 ;
break;
case V_681 :
V_41 -> V_28 = V_68 ;
break;
case V_682 :
V_41 -> V_28 = V_78 ;
break;
case V_683 :
V_41 -> V_28 = V_684 ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_76 ,
V_4 -> V_679 ) ;
F_34 ( V_4 -> V_679 ) ;
break;
}
V_89 = F_221 ( V_15 , V_41 , V_4 , V_81 ) ;
if ( V_89 ) {
F_38 ( V_81 ) ;
return V_685 ;
}
F_170 ( V_15 , V_303 , V_456 , V_81 ) ;
return 0 ;
}
static void F_230 ( struct V_80 * V_81 ,
void * V_439 )
{
struct V_3 * V_4 ;
V_4 = V_81 -> V_4 ;
F_227 ( V_4 ) ;
if ( V_81 -> V_86 == - V_404 )
F_146 ( V_4 , V_686 ) ;
F_38 ( V_81 ) ;
F_3 ( V_4 ) ;
}
static inline int F_231 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_302 * V_303 )
{
return F_131 ( V_15 , V_4 , V_13 -> V_233 ,
V_4 -> V_335 , V_4 -> V_674 , V_303 , NULL ) ;
}
static int F_131 ( struct V_8 * V_15 ,
struct V_3 * V_4 , T_6 V_233 , T_1 * V_45 ,
unsigned int V_331 , struct V_302 * V_303 ,
struct V_295 * V_296 )
{
int V_89 ;
struct V_80 * V_81 ;
struct V_671 * V_41 ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_438 = F_230 ;
V_81 -> V_4 = V_4 ;
V_4 -> V_673 = ( unsigned char * ) V_81 ;
V_41 = V_81 -> V_446 ;
memset ( V_41 , 0 ,
F_30 ( struct V_40 , V_50 ) ) ;
V_41 -> V_47 . V_48 = V_687 ;
F_23 ( V_233 , & V_41 -> V_688 ) ;
F_23 ( F_143 ( V_4 ) , & V_41 -> V_27 ) ;
V_41 -> V_54 = V_55 ;
F_29 ( V_81 -> V_486 , & V_41 -> V_426 ) ;
V_41 -> V_436 = V_41 -> V_426 ;
if ( V_331 > sizeof( V_41 -> V_45 ) )
V_331 = sizeof( V_41 -> V_45 ) ;
V_41 -> V_331 = V_331 ;
memcpy ( V_41 -> V_45 , V_45 , V_331 ) ;
switch ( V_4 -> V_679 ) {
case V_680 :
V_41 -> V_28 = V_59 ;
break;
case V_681 :
V_41 -> V_28 = V_68 ;
break;
case V_682 :
V_41 -> V_28 = V_78 ;
break;
case V_683 :
V_41 -> V_28 = V_684 ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_76 ,
V_4 -> V_679 ) ;
F_34 ( V_4 -> V_679 ) ;
break;
}
if ( V_296 ) {
V_41 -> V_689 = true ;
F_29 ( V_296 -> V_299 ,
& V_41 -> V_299 ) ;
F_23 ( V_296 -> V_300 ,
& V_41 -> V_300 ) ;
F_23 ( V_296 -> V_301 ,
& V_41 -> V_301 ) ;
}
V_89 = F_225 ( V_15 , V_41 , V_4 , V_81 ) ;
if ( V_89 ) {
F_38 ( V_81 ) ;
return V_685 ;
}
F_170 ( V_15 , V_303 , V_513 , V_81 ) ;
return 0 ;
}
static int F_232 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
int V_89 ;
struct V_8 * V_15 ;
struct V_12 * V_13 ;
T_4 V_690 ;
struct V_302 * V_303 ;
bool V_691 ;
V_13 = V_4 -> V_13 -> V_11 ;
V_15 = F_5 ( V_10 ) ;
if ( F_8 ( V_15 ) ) {
F_146 ( V_4 , V_389 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
V_4 -> V_392 = 0 ;
V_690 = F_233 ( F_234 ( V_4 -> V_41 ) ) ;
if ( V_690 >= V_15 -> V_475 )
V_690 = 0 ;
V_303 = & V_15 -> V_450 [ V_690 ] ;
if ( F_7 ( V_13 ) ) {
V_691 = false ;
if ( V_13 -> V_239 &&
! F_235 ( V_4 -> V_41 ) ) {
V_89 = F_126 ( V_15 , V_13 ,
V_4 , V_303 ) ;
if ( V_89 == 0 ||
V_89 == V_685 ||
V_89 == V_384 ||
V_89 == V_692 )
V_691 = true ;
}
if ( ! V_691 )
V_89 = F_228 ( V_15 , V_13 , V_4 ,
V_303 ) ;
} else {
if ( V_13 -> V_257 )
V_89 = F_231 ( V_15 , V_13 , V_4 ,
V_303 ) ;
else
V_89 = F_228 ( V_15 , V_13 , V_4 ,
V_303 ) ;
}
return V_89 ;
}
static void F_236 ( struct V_80 * V_81 ,
void * V_439 )
{
struct V_578 * V_579 = V_439 ;
F_189 ( V_579 ) ;
}
static int F_237 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_578 * V_581 )
{
int V_89 ;
unsigned int V_693 = 0 ;
while ( 1 ) {
if ( F_193 ( V_581 ,
V_694 * V_356 ) ) {
V_89 = 0 ;
break;
}
F_9 ( V_15 ) ;
if ( F_8 ( V_15 ) ) {
V_89 = - V_359 ;
break;
}
V_693 += V_694 ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_77 ,
V_15 -> V_231 -> V_232 , V_13 -> V_139 ,
V_13 -> V_140 , V_13 -> V_141 , V_693 ) ;
}
return V_89 ;
}
static int F_238 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
struct V_80 * V_81 ;
F_191 ( V_581 ) ;
struct V_695 * V_41 ;
F_196 ( & V_15 -> V_696 ) ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_438 = F_236 ;
V_81 -> V_439 = & V_581 ;
V_41 = V_81 -> V_446 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_47 . V_48 = V_697 ;
F_29 ( sizeof( * V_41 ) - V_51 ,
& V_41 -> V_47 . V_52 ) ;
F_29 ( V_81 -> V_486 , & V_41 -> V_426 ) ;
memcpy ( V_41 -> V_53 , V_13 -> V_17 ,
sizeof( V_41 -> V_53 ) ) ;
V_41 -> V_698 = V_699 ;
F_170 ( V_15 ,
& V_15 -> V_450 [ V_451 ] , V_456 ,
V_81 ) ;
V_89 = F_237 ( V_15 , V_13 , & V_581 ) ;
if ( V_89 == 0 )
V_89 = V_81 -> V_86 ;
F_38 ( V_81 ) ;
F_199 ( & V_15 -> V_696 ) ;
return V_89 ;
}
static int F_239 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
F_9 ( V_15 ) ;
if ( F_8 ( V_15 ) )
return V_700 ;
V_89 = F_238 ( V_15 , V_13 ) ;
return V_89 == 0 ? V_701 : V_700 ;
}
static int F_240 ( struct V_3 * V_4 )
{
int V_89 ;
struct V_8 * V_15 ;
struct V_12 * V_13 ;
V_15 = F_5 ( V_4 -> V_13 -> V_367 ) ;
V_13 = V_4 -> V_13 -> V_11 ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_78 ,
V_15 -> V_231 -> V_232 ,
V_13 -> V_139 , V_13 -> V_140 , V_13 -> V_141 ) ;
V_89 = F_239 ( V_15 , V_13 ) ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_79 ,
V_15 -> V_231 -> V_232 ,
V_13 -> V_139 , V_13 -> V_140 , V_13 -> V_141 ,
V_89 == V_701 ? L_80 : L_81 ) ;
return V_89 ;
}
static int F_241 ( struct V_365 * V_241 )
{
struct V_12 * V_13 ;
unsigned long V_36 ;
struct V_8 * V_15 ;
struct V_702 * V_703 ;
struct V_704 * V_705 ;
V_15 = F_5 ( V_241 -> V_367 ) ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
if ( F_242 ( V_241 ) == V_146 ) {
V_703 = V_702 ( V_241 ) ;
V_705 = F_243 ( V_703 ) ;
V_13 = F_244 ( V_15 , V_705 ) ;
if ( V_13 ) {
V_13 -> V_140 = F_245 ( V_241 ) ;
V_13 -> V_141 = V_241 -> V_141 ;
V_13 -> V_144 = true ;
}
} else {
V_13 = F_94 ( V_15 , F_242 ( V_241 ) ,
F_245 ( V_241 ) , V_241 -> V_141 ) ;
}
if ( V_13 && V_13 -> V_253 ) {
V_241 -> V_11 = V_13 ;
V_13 -> V_241 = V_241 ;
if ( V_13 -> V_189 ) {
V_13 -> V_274 = V_13 -> V_189 ;
F_109 ( V_241 ,
V_13 -> V_274 ) ;
}
}
F_104 ( & V_15 -> V_260 , V_36 ) ;
return 0 ;
}
static int F_246 ( struct V_365 * V_241 )
{
struct V_12 * V_13 ;
V_13 = V_241 -> V_11 ;
if ( ! V_13 -> V_253 )
V_241 -> V_256 = true ;
return 0 ;
}
static int F_247 ( struct V_9 * V_10 )
{
struct V_8 * V_15 = F_5 ( V_10 ) ;
return F_248 ( & V_10 -> V_706 , V_15 -> V_23 ) ;
}
static int F_249 ( struct V_8 * V_15 ,
void T_10 * V_707 )
{
struct V_23 * V_23 ;
T_6 V_708 ;
T_6 V_709 ;
T_11 V_710 ;
if ( ! V_707 )
return - V_169 ;
V_23 = V_15 -> V_23 ;
V_710 . V_711 = F_250 ( V_23 -> V_139 ) ;
V_710 . V_139 = V_23 -> V_139 -> V_712 ;
V_710 . V_713 = V_23 -> V_714 ;
V_708 = V_23 -> V_708 ;
V_709 = V_23 -> V_709 ;
V_710 . V_715 = ( ( V_709 << 16 ) & 0xffff0000 ) |
V_708 ;
if ( F_251 ( V_707 , & V_710 , sizeof( V_710 ) ) )
return - V_716 ;
return 0 ;
}
static int F_252 ( void T_10 * V_707 )
{
T_6 V_717 ;
if ( ! V_707 )
return - V_169 ;
V_717 = ( V_718 << 28 ) | ( V_719 << 24 ) |
( V_720 << 16 ) | V_721 ;
if ( F_251 ( V_707 , & V_717 , sizeof( V_717 ) ) )
return - V_716 ;
return 0 ;
}
static void F_253 ( struct V_370 * V_722 ,
struct V_723 * V_723 )
{
int V_724 ;
T_2 V_371 ;
switch ( V_722 -> V_377 ) {
case V_725 :
V_724 = V_726 ;
break;
case V_378 :
V_724 = V_727 ;
break;
case V_728 :
V_724 = V_729 ;
break;
case V_730 :
case V_731 :
case V_732 :
case V_733 :
case V_734 :
V_724 = V_735 ;
break;
case V_736 :
case V_737 :
case V_738 :
case V_739 :
case V_740 :
case V_741 :
case V_742 :
case V_743 :
case V_744 :
case V_745 :
V_724 = V_746 ;
break;
case V_747 :
V_724 = V_748 ;
break;
case V_749 :
V_724 = V_750 ;
break;
case V_751 :
V_724 = V_752 ;
break;
default:
V_724 = V_753 ;
break;
}
V_371 =
F_69 ( & V_722 -> V_371 ) ;
if ( V_371 == 0 )
V_371 =
F_69 ( & V_722 -> V_382 ) ;
if ( V_371 )
if ( V_371 > sizeof( V_722 -> V_383 ) )
V_371 = sizeof( V_722 -> V_383 ) ;
V_723 -> V_368 = V_722 -> V_86 ;
V_723 -> V_754 = V_724 ;
V_723 -> V_371 = V_371 ;
}
static int F_254 ( struct V_8 * V_15 , void T_10 * V_707 )
{
int V_89 ;
char * V_755 = NULL ;
T_4 V_52 ;
T_2 V_371 ;
T_12 V_756 ;
struct V_40 V_41 ;
struct V_370 V_722 ;
struct V_723 V_723 ;
if ( F_8 ( V_15 ) )
return - V_93 ;
if ( ! V_707 )
return - V_169 ;
if ( ! F_255 ( V_757 ) )
return - V_758 ;
if ( F_256 ( & V_756 , V_707 , sizeof( V_756 ) ) )
return - V_716 ;
if ( V_756 . V_759 < 1 &&
V_756 . V_760 . Type . V_761 != V_762 )
return - V_169 ;
if ( V_756 . V_760 . V_763 > sizeof( V_41 . V_45 ) )
return - V_169 ;
if ( V_756 . V_760 . Type . Type != V_764 )
return - V_169 ;
switch ( V_756 . V_760 . Type . V_761 ) {
case V_762 :
case V_765 :
case V_766 :
break;
default:
return - V_169 ;
}
if ( V_756 . V_759 > 0 ) {
V_755 = F_49 ( V_756 . V_759 , V_95 ) ;
if ( ! V_755 )
return - V_31 ;
if ( V_756 . V_760 . Type . V_761 & V_765 ) {
if ( F_256 ( V_755 , V_756 . V_767 ,
V_756 . V_759 ) ) {
V_89 = - V_716 ;
goto V_96;
}
} else {
memset ( V_755 , 0 , V_756 . V_759 ) ;
}
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_49 ;
V_52 = F_30 ( struct V_40 , V_50 ) -
V_51 ;
memcpy ( V_41 . V_53 , V_756 . V_768 . V_769 ,
sizeof( V_41 . V_53 ) ) ;
memcpy ( V_41 . V_45 , V_756 . V_760 . V_770 , V_756 . V_760 . V_763 ) ;
V_41 . V_56 = V_57 ;
switch ( V_756 . V_760 . Type . V_761 ) {
case V_762 :
V_41 . V_28 = V_78 ;
break;
case V_765 :
V_41 . V_28 = V_68 ;
break;
case V_766 :
V_41 . V_28 = V_59 ;
break;
}
V_41 . V_54 = V_55 ;
if ( V_756 . V_759 > 0 ) {
F_23 ( V_756 . V_759 , & V_41 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
& V_41 . V_50 [ 0 ] , V_755 ,
V_756 . V_759 , V_79 ) ;
if ( V_89 )
goto V_96;
V_52 += sizeof( V_41 . V_50 [ 0 ] ) ;
}
F_29 ( V_52 , & V_41 . V_47 . V_52 ) ;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
V_584 , & V_722 , V_90 ) ;
if ( V_756 . V_759 > 0 )
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_79 ) ;
memset ( & V_756 . V_87 , 0 , sizeof( V_756 . V_87 ) ) ;
if ( V_89 == 0 ) {
F_253 ( & V_722 , & V_723 ) ;
V_756 . V_87 . V_771 = V_723 . V_368 ;
V_756 . V_87 . V_772 =
V_723 . V_754 ;
V_371 = V_723 . V_371 ;
if ( V_371 ) {
if ( V_371 >
sizeof( V_756 . V_87 . V_773 ) )
V_371 =
sizeof( V_756 . V_87 . V_773 ) ;
memcpy ( V_756 . V_87 . V_773 ,
V_722 . V_383 , V_371 ) ;
V_756 . V_87 . V_774 = V_371 ;
}
}
if ( F_251 ( V_707 , & V_756 , sizeof( V_756 ) ) ) {
V_89 = - V_716 ;
goto V_96;
}
if ( V_89 == 0 && V_756 . V_759 > 0 &&
( V_756 . V_760 . Type . V_761 & V_766 ) ) {
if ( F_251 ( V_756 . V_767 , V_755 ,
V_756 . V_759 ) ) {
V_89 = - V_716 ;
}
}
V_96:
F_46 ( V_755 ) ;
return V_89 ;
}
static int F_257 ( struct V_365 * V_241 , int V_42 , void T_10 * V_707 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_5 ( V_241 -> V_367 ) ;
switch ( V_42 ) {
case V_775 :
case V_776 :
case V_777 :
V_89 = F_87 ( V_15 ) ;
break;
case V_778 :
V_89 = F_249 ( V_15 , V_707 ) ;
break;
case V_779 :
V_89 = F_252 ( V_707 ) ;
break;
case V_780 :
V_89 = F_254 ( V_15 , V_707 ) ;
break;
default:
V_89 = - V_169 ;
break;
}
return V_89 ;
}
static T_13 F_258 ( struct V_13 * V_75 ,
struct V_781 * V_782 , char * V_26 )
{
T_13 V_783 = 0 ;
struct V_9 * V_10 ;
struct V_8 * V_15 ;
V_10 = F_259 ( V_75 ) ;
V_15 = F_5 ( V_10 ) ;
V_783 += snprintf (buffer + count, PAGE_SIZE - count,
L_82 , DRIVER_VERSION BUILD_TIMESTAMP) ;
V_783 += snprintf ( V_26 + V_783 , V_655 - V_783 ,
L_83 , V_15 -> V_784 ) ;
return V_783 ;
}
static T_13 F_260 ( struct V_13 * V_75 ,
struct V_781 * V_782 , const char * V_26 , T_2 V_783 )
{
struct V_9 * V_10 = F_259 ( V_75 ) ;
F_120 ( V_10 ) ;
return V_783 ;
}
static T_13 F_261 ( struct V_13 * V_75 ,
struct V_781 * V_782 , char * V_26 )
{
struct V_8 * V_15 ;
struct V_365 * V_241 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
V_32 V_258 ;
V_241 = F_262 ( V_75 ) ;
V_15 = F_5 ( V_241 -> V_367 ) ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
V_13 = V_241 -> V_11 ;
if ( F_7 ( V_13 ) ) {
F_104 ( & V_15 -> V_260 ,
V_36 ) ;
return - V_785 ;
}
V_258 = V_13 -> V_258 ;
F_104 ( & V_15 -> V_260 , V_36 ) ;
return snprintf ( V_26 , V_655 , L_84 , V_258 ) ;
}
static T_13 F_263 ( struct V_13 * V_75 ,
struct V_781 * V_782 , char * V_26 )
{
struct V_8 * V_15 ;
struct V_365 * V_241 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
V_241 = F_262 ( V_75 ) ;
V_15 = F_5 ( V_241 -> V_367 ) ;
F_102 ( & V_15 -> V_260 , V_36 ) ;
V_13 = V_241 -> V_11 ;
V_26 [ 0 ] = V_13 -> V_239 ? '1' : '0' ;
V_26 [ 1 ] = '\n' ;
V_26 [ 2 ] = '\0' ;
F_104 ( & V_15 -> V_260 , V_36 ) ;
return 2 ;
}
static int F_264 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_9 * V_10 ;
V_10 = F_265 ( & V_786 , sizeof( V_15 ) ) ;
if ( ! V_10 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_85 ,
V_15 -> V_787 ) ;
return - V_31 ;
}
V_10 -> V_788 = 0 ;
V_10 -> V_789 = 0 ;
V_10 -> V_790 = - 1 ;
V_10 -> V_791 = V_792 ;
V_10 -> V_793 = V_794 ;
V_10 -> V_795 = ~ 0 ;
V_10 -> V_796 = ~ 0 ;
V_10 -> V_657 = V_15 -> V_657 ;
V_10 -> V_797 = V_15 -> V_651 ;
V_10 -> V_798 = V_10 -> V_797 ;
V_10 -> V_656 = V_15 -> V_656 ;
V_10 -> V_799 = V_800 ;
V_10 -> V_509 = F_172 ( V_15 -> V_23 , 0 ) ;
V_10 -> V_801 = V_10 -> V_509 ;
V_10 -> V_802 = V_15 -> V_475 ;
V_10 -> V_11 [ 0 ] = ( unsigned long ) V_15 ;
V_89 = F_266 ( V_10 , & V_15 -> V_23 -> V_75 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_86 ,
V_15 -> V_787 ) ;
goto V_803;
}
V_89 = F_267 ( V_10 , V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_87 ,
V_15 -> V_787 ) ;
goto V_804;
}
V_15 -> V_231 = V_10 ;
return 0 ;
V_804:
F_268 ( V_10 ) ;
V_803:
F_269 ( V_10 ) ;
return V_89 ;
}
static void F_270 ( struct V_8 * V_15 )
{
struct V_9 * V_10 ;
F_271 ( V_15 ) ;
V_10 = V_15 -> V_231 ;
if ( ! V_10 )
return;
F_268 ( V_10 ) ;
F_269 ( V_10 ) ;
}
static int F_272 ( struct V_8 * V_15 )
{
int V_89 ;
T_6 V_805 ;
V_805 = ( V_806 << 5 ) |
V_807 ;
F_153 ( V_805 ,
& V_15 -> V_352 -> V_808 ) ;
V_89 = F_132 ( V_15 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_88 ) ;
return V_89 ;
}
static int F_273 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_88 * V_809 ;
V_809 = F_49 ( sizeof( * V_809 ) , V_95 ) ;
if ( ! V_809 )
return - V_31 ;
V_89 = F_39 ( V_15 , V_809 ) ;
if ( V_89 )
goto V_96;
memcpy ( V_15 -> V_784 , V_809 -> V_784 ,
sizeof( V_809 -> V_784 ) ) ;
V_15 -> V_784 [ sizeof( V_809 -> V_784 ) ] = '\0' ;
snprintf ( V_15 -> V_784 +
strlen ( V_15 -> V_784 ) ,
sizeof( V_15 -> V_784 ) ,
L_89 , F_69 ( & V_809 -> V_810 ) ) ;
V_96:
F_46 ( V_809 ) ;
return V_89 ;
}
static int F_274 ( struct V_8 * V_15 )
{
if ( ! F_10 ( V_15 ) )
return - V_93 ;
if ( F_13 ( V_15 ) == V_811 ) {
F_275 ( V_15 ) ;
if ( F_272 ( V_15 ) == 0 )
F_276 ( V_15 ) ;
}
return 0 ;
}
static int F_277 ( struct V_8 * V_15 )
{
int V_89 ;
if ( V_812 ) {
V_89 = F_274 ( V_15 ) ;
if ( V_89 )
return V_89 ;
}
V_89 = F_278 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_90 ) ;
return V_89 ;
}
V_89 = F_279 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_91 ) ;
return V_89 ;
}
V_89 = F_280 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_92 ) ;
return V_89 ;
}
if ( V_15 -> V_652 > V_813 )
V_15 -> V_652 =
V_813 ;
F_214 ( V_15 ) ;
V_89 = F_211 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_93 ) ;
return V_89 ;
}
V_89 = F_281 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_94 ) ;
return V_89 ;
}
V_89 = F_132 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_95 ) ;
return V_89 ;
}
V_15 -> V_814 = true ;
F_15 ( V_15 , V_811 ) ;
V_89 = F_181 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_96 ) ;
return V_89 ;
}
V_89 = F_182 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_97 ) ;
return V_89 ;
}
V_89 = F_202 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_98 ) ;
return V_89 ;
}
V_89 = F_203 ( V_15 ) ;
if ( V_89 )
return V_89 ;
F_216 ( V_15 ) ;
V_89 = F_174 ( V_15 ) ;
if ( V_89 )
return V_89 ;
if ( V_15 -> V_516 < V_15 -> V_475 ) {
V_15 -> V_661 =
V_15 -> V_516 ;
F_216 ( V_15 ) ;
}
V_89 = F_212 ( V_15 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_176 ( V_15 ) ;
if ( V_89 )
return V_89 ;
F_179 ( V_15 ) ;
V_89 = F_171 ( V_15 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_207 ( V_15 ) ;
if ( V_89 )
return V_89 ;
F_282 ( V_15 ) ;
V_89 = F_208 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_99 ) ;
return V_89 ;
}
F_161 ( V_15 ) ;
V_15 -> V_16 = true ;
V_89 = F_264 ( V_15 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_273 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_100 ) ;
return V_89 ;
}
V_89 = F_48 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_101 ) ;
return V_89 ;
}
F_58 ( V_15 ) ;
F_87 ( V_15 ) ;
return 0 ;
}
static int F_283 ( struct V_8 * V_15 )
{
int V_89 ;
V_32 V_815 ;
V_89 = F_284 ( V_15 -> V_23 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_102 ) ;
return V_89 ;
}
if ( sizeof( T_3 ) > 4 )
V_815 = F_285 ( 64 ) ;
else
V_815 = F_285 ( 32 ) ;
V_89 = F_286 ( & V_15 -> V_23 -> V_75 , V_815 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 , L_103 ) ;
goto V_816;
}
V_89 = F_287 ( V_15 -> V_23 , V_517 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_104 ) ;
goto V_816;
}
V_15 -> V_565 = F_288 ( F_289 (
V_15 -> V_23 , 0 ) ,
sizeof( struct V_817 ) ) ;
if ( ! V_15 -> V_565 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_105 ) ;
V_89 = - V_31 ;
goto V_818;
}
V_15 -> V_819 = V_15 -> V_565 ;
V_15 -> V_352 = & V_15 -> V_819 -> V_352 ;
F_290 ( V_15 -> V_23 ) ;
F_291 ( V_15 -> V_23 , V_15 ) ;
return 0 ;
V_818:
F_292 ( V_15 -> V_23 ) ;
V_816:
F_293 ( V_15 -> V_23 ) ;
return V_89 ;
}
static void F_294 ( struct V_8 * V_15 )
{
F_295 ( V_15 -> V_565 ) ;
F_292 ( V_15 -> V_23 ) ;
F_293 ( V_15 -> V_23 ) ;
F_291 ( V_15 -> V_23 , NULL ) ;
}
static struct V_8 * F_296 ( int V_820 )
{
struct V_8 * V_15 ;
V_15 = F_297 ( sizeof( struct V_8 ) ,
V_95 , V_820 ) ;
if ( ! V_15 )
return NULL ;
F_298 ( & V_15 -> V_293 ) ;
F_106 ( & V_15 -> V_272 ) ;
F_180 ( & V_15 -> V_260 ) ;
F_299 ( & V_15 -> V_469 , F_157 ) ;
F_300 ( & V_15 -> V_477 , 0 ) ;
F_301 ( & V_15 -> V_21 , F_86 ) ;
F_301 ( & V_15 -> V_121 , F_54 ) ;
F_302 ( & V_15 -> V_585 ,
V_821 ) ;
F_302 ( & V_15 -> V_696 , V_822 ) ;
V_15 -> V_787 = F_36 ( & V_823 ) - 1 ;
V_15 -> V_661 = V_824 ;
return V_15 ;
}
static inline void F_303 ( struct V_8 * V_15 )
{
F_46 ( V_15 ) ;
}
static void F_304 ( struct V_8 * V_15 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_518 ; V_39 ++ ) {
F_305 ( F_172 ( V_15 -> V_23 , V_39 ) ,
& V_15 -> V_450 [ V_39 ] ) ;
}
F_306 ( V_15 -> V_23 ) ;
}
static void F_307 ( struct V_8 * V_15 )
{
F_164 ( V_15 ) ;
F_304 ( V_15 ) ;
if ( V_15 -> V_534 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_536 ,
V_15 -> V_534 ,
V_15 -> V_535 ) ;
if ( V_15 -> V_551 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_553 ,
V_15 -> V_551 ,
V_15 -> V_552 ) ;
F_209 ( V_15 ) ;
if ( V_15 -> V_435 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_647 ,
V_15 -> V_435 ,
V_15 -> V_648 ) ;
if ( V_15 -> V_565 )
F_294 ( V_15 ) ;
F_303 ( V_15 ) ;
}
static void F_308 ( struct V_8 * V_15 )
{
F_309 ( & V_15 -> V_21 ) ;
F_309 ( & V_15 -> V_121 ) ;
F_117 ( V_15 ) ;
F_270 ( V_15 ) ;
if ( V_15 -> V_814 ) {
F_275 ( V_15 ) ;
if ( F_272 ( V_15 ) == 0 )
F_276 ( V_15 ) ;
}
F_307 ( V_15 ) ;
}
static void F_310 ( struct V_23 * V_515 ,
const struct V_825 * V_826 )
{
char * V_827 ;
if ( V_826 -> V_828 ) {
V_827 = ( char * ) V_826 -> V_828 ;
} else {
switch ( V_826 -> V_829 ) {
case V_830 :
V_827 = V_831 ;
break;
case V_832 :
default:
V_827 = V_833 ;
break;
}
}
F_80 ( & V_515 -> V_75 , L_106 , V_827 ) ;
}
static int F_311 ( struct V_23 * V_515 , const struct V_825 * V_826 )
{
int V_89 ;
int V_834 ;
struct V_8 * V_15 ;
F_310 ( V_515 , V_826 ) ;
if ( V_835 &&
V_826 -> V_829 == V_836 &&
V_826 -> V_837 == V_836 ) {
F_57 ( & V_515 -> V_75 ,
L_107 ) ;
return - V_785 ;
}
if ( V_826 -> V_829 == V_836 || V_826 -> V_837 == V_836 )
F_57 ( & V_515 -> V_75 ,
L_108 ) ;
V_834 = F_312 ( & V_515 -> V_75 ) ;
if ( V_834 == V_838 )
F_313 ( & V_515 -> V_75 , 0 ) ;
V_15 = F_296 ( V_834 ) ;
if ( ! V_15 ) {
F_33 ( & V_515 -> V_75 ,
L_109 ) ;
return - V_31 ;
}
V_15 -> V_23 = V_515 ;
V_89 = F_283 ( V_15 ) ;
if ( V_89 )
goto error;
V_89 = F_277 ( V_15 ) ;
if ( V_89 )
goto error;
return 0 ;
error:
F_308 ( V_15 ) ;
return V_89 ;
}
static void F_314 ( struct V_23 * V_515 )
{
struct V_8 * V_15 ;
V_15 = F_315 ( V_515 ) ;
if ( ! V_15 )
return;
F_308 ( V_15 ) ;
}
static void F_316 ( struct V_23 * V_515 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_315 ( V_515 ) ;
if ( ! V_15 )
goto error;
V_89 = F_44 ( V_15 ) ;
if ( V_89 == 0 )
return;
error:
F_57 ( & V_515 -> V_75 ,
L_110 ) ;
}
static int T_14 F_317 ( void )
{
int V_89 ;
F_318 ( V_839 L_111 ) ;
V_800 =
F_319 ( & V_840 ) ;
if ( ! V_800 )
return - V_785 ;
V_89 = F_320 ( & V_841 ) ;
if ( V_89 )
F_321 ( V_800 ) ;
return V_89 ;
}
static void T_15 F_322 ( void )
{
F_323 ( & V_841 ) ;
F_321 ( V_800 ) ;
}
