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
struct V_107 time ;
struct V_108 V_109 ;
V_27 = sizeof( * V_26 ) ;
V_26 = F_49 ( V_27 , V_95 ) ;
if ( ! V_26 )
return - V_31 ;
V_26 -> V_98 [ 0 ] = '<' ;
V_26 -> V_98 [ 1 ] = 'H' ;
V_26 -> V_98 [ 2 ] = 'W' ;
V_26 -> V_98 [ 3 ] = '>' ;
V_26 -> V_110 [ 0 ] = 'T' ;
V_26 -> V_110 [ 1 ] = 'D' ;
F_29 ( sizeof( V_26 -> time ) ,
& V_26 -> V_111 ) ;
F_51 ( & time ) ;
V_105 = time . V_112 - ( V_113 . V_114 * 60 ) ;
F_52 ( V_105 , & V_109 ) ;
V_106 = V_109 . V_115 + 1900 ;
V_26 -> time [ 0 ] = F_53 ( V_109 . V_116 ) ;
V_26 -> time [ 1 ] = F_53 ( V_109 . V_117 ) ;
V_26 -> time [ 2 ] = F_53 ( V_109 . V_118 ) ;
V_26 -> time [ 3 ] = 0 ;
V_26 -> time [ 4 ] = F_53 ( V_109 . V_119 + 1 ) ;
V_26 -> time [ 5 ] = F_53 ( V_109 . V_120 ) ;
V_26 -> time [ 6 ] = F_53 ( V_106 / 100 ) ;
V_26 -> time [ 7 ] = F_53 ( V_106 % 100 ) ;
V_26 -> V_121 [ 0 ] = 'D' ;
V_26 -> V_121 [ 1 ] = 'W' ;
V_26 -> V_103 [ 0 ] = 'Z' ;
V_26 -> V_103 [ 1 ] = 'Z' ;
V_89 = F_47 ( V_15 , V_26 , V_27 ) ;
F_46 ( V_26 ) ;
return V_89 ;
}
static void F_54 ( struct V_122 * V_123 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_55 ( F_56 ( V_123 ) , struct V_8 ,
V_124 ) ;
V_89 = F_50 ( V_15 ) ;
if ( V_89 )
F_57 ( & V_15 -> V_23 -> V_75 ,
L_3 ) ;
F_18 ( & V_15 -> V_124 ,
V_125 ) ;
}
static inline void F_58 (
struct V_8 * V_15 )
{
F_18 ( & V_15 -> V_124 , 0 ) ;
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
T_2 V_126 ;
T_2 V_127 ;
T_2 V_128 ;
void * V_129 = NULL ;
struct V_130 * V_130 ;
V_130 = F_49 ( sizeof( * V_130 ) , V_95 ) ;
if ( ! V_130 ) {
V_89 = - V_31 ;
goto V_96;
}
V_89 = F_59 ( V_15 , V_42 , V_130 ,
sizeof( * V_130 ) ) ;
if ( V_89 )
goto V_96;
V_126 = F_61 ( & V_130 -> V_131 ) ;
V_132:
V_127 = sizeof( struct V_130 ) + V_126 ;
V_129 = F_49 ( V_127 , V_95 ) ;
if ( ! V_129 ) {
V_89 = - V_31 ;
goto V_96;
}
if ( V_126 == 0 ) {
memcpy ( V_129 , V_130 , sizeof( * V_130 ) ) ;
goto V_96;
}
V_89 = F_59 ( V_15 , V_42 , V_129 , V_127 ) ;
if ( V_89 )
goto V_96;
V_128 = F_61 (
& ( (struct V_130 * ) V_129 ) -> V_131 ) ;
if ( V_128 > V_126 ) {
V_126 = V_128 ;
F_46 ( V_129 ) ;
goto V_132;
}
V_96:
F_46 ( V_130 ) ;
if ( V_89 ) {
F_46 ( V_129 ) ;
V_129 = NULL ;
}
* V_26 = V_129 ;
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
struct V_133 * * V_134 ,
struct V_135 * * V_136 )
{
int V_89 ;
T_2 V_137 ;
T_2 V_138 ;
struct V_135 * V_139 ;
struct V_135 * V_140 ;
struct V_130 V_130 ;
V_89 = F_62 ( V_15 , ( void * * ) V_134 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_4 ) ;
V_89 = F_63 ( V_15 , ( void * * ) V_136 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_5 ) ;
V_140 = * V_136 ;
if ( V_140 ) {
V_137 =
F_61 ( & V_140 -> V_47 . V_131 ) ;
} else {
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_140 =
(struct V_135 * ) & V_130 ;
V_137 = 0 ;
}
V_138 = sizeof( struct V_130 ) +
V_137 ;
V_139 = F_49 ( V_138 +
sizeof( struct V_135 ) , V_95 ) ;
if ( ! V_139 ) {
F_46 ( * V_136 ) ;
* V_136 = NULL ;
return - V_31 ;
}
memcpy ( V_139 , V_140 , V_138 ) ;
memset ( ( T_1 * ) V_139 + V_138 , 0 ,
sizeof( struct V_141 ) ) ;
F_31 ( V_137 +
sizeof( struct V_141 ) ,
& V_139 -> V_47 . V_131 ) ;
F_46 ( * V_136 ) ;
* V_136 = V_139 ;
return 0 ;
}
static inline void F_65 ( struct V_12 * V_13 ,
int V_142 , int V_143 , int V_144 )
{
V_13 -> V_142 = V_142 ;
V_13 -> V_143 = V_143 ;
V_13 -> V_144 = V_144 ;
}
static void F_66 ( struct V_12 * V_13 )
{
T_1 * V_17 ;
T_6 V_145 ;
V_17 = V_13 -> V_17 ;
V_145 = F_27 ( V_17 ) ;
if ( F_12 ( V_17 ) ) {
F_65 ( V_13 , V_146 , 0 , V_145 & 0x3fff ) ;
V_13 -> V_147 = true ;
return;
}
if ( F_7 ( V_13 ) ) {
F_65 ( V_13 , V_148 , 0 ,
V_145 & 0x3fff ) ;
V_13 -> V_147 = true ;
return;
}
F_65 ( V_13 , V_149 , 0 , 0 ) ;
}
static void F_67 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_1 V_1 ;
T_1 * V_26 ;
V_1 = V_150 ;
V_26 = F_49 ( 64 , V_95 ) ;
if ( V_26 ) {
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_151 , V_26 , 64 ) ;
if ( V_89 == 0 ) {
V_1 = V_26 [ 8 ] ;
if ( V_1 > V_152 )
V_1 = V_150 ;
}
F_46 ( V_26 ) ;
}
V_13 -> V_1 = V_1 ;
}
static int F_68 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_153 * V_153 )
{
char * V_154 ;
T_6 V_155 ;
T_6 V_156 ;
unsigned int V_157 ;
unsigned int V_158 ;
V_155 = F_27 ( & V_153 -> V_159 ) ;
if ( V_155 < F_30 ( struct V_153 , V_160 ) ) {
V_154 = L_6 ;
goto V_161;
}
if ( V_155 > sizeof( * V_153 ) ) {
V_154 = L_7 ;
goto V_161;
}
V_157 = F_69 ( & V_153 -> V_162 ) *
( F_69 ( & V_153 -> V_163 ) +
F_69 ( & V_153 -> V_164 ) ) ;
V_158 = V_157 *
F_69 ( & V_153 -> V_165 ) ;
if ( V_158 > V_166 ) {
V_154 = L_8 ;
goto V_161;
}
if ( V_13 -> V_1 == V_167 ) {
if ( F_69 ( & V_153 -> V_162 ) != 2 ) {
V_154 = L_9 ;
goto V_161;
}
} else if ( V_13 -> V_1 == V_168 ) {
if ( F_69 ( & V_153 -> V_162 ) != 3 ) {
V_154 = L_10 ;
goto V_161;
}
} else if ( ( V_13 -> V_1 == V_169 ||
V_13 -> V_1 == V_170 ) &&
F_69 ( & V_153 -> V_162 ) > 1 ) {
V_156 =
F_69 ( & V_153 -> V_171 ) *
F_69 ( & V_153 -> V_163 ) ;
if ( V_156 == 0 ) {
V_154 = L_11 ;
goto V_161;
}
}
return 0 ;
V_161:
F_57 ( & V_15 -> V_23 -> V_75 , L_12 , V_154 ) ;
return - V_172 ;
}
static int F_70 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
int V_44 ;
struct V_40 V_41 ;
struct V_153 * V_153 ;
V_153 = F_49 ( sizeof( * V_153 ) , V_95 ) ;
if ( ! V_153 )
return - V_31 ;
V_89 = F_28 ( V_15 , & V_41 ,
V_65 , V_13 -> V_17 , V_153 ,
sizeof( * V_153 ) , 0 , & V_44 ) ;
if ( V_89 )
goto error;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_44 ) ;
if ( V_89 )
goto error;
V_89 = F_68 ( V_15 , V_13 , V_153 ) ;
if ( V_89 )
goto error;
V_13 -> V_153 = V_153 ;
return 0 ;
error:
F_46 ( V_153 ) ;
return V_89 ;
}
static void F_71 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_1 * V_26 ;
T_1 V_173 ;
V_26 = F_49 ( 64 , V_95 ) ;
if ( ! V_26 )
return;
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_174 , V_26 , 64 ) ;
if ( V_89 )
goto V_96;
#define F_72 4
#define F_73 0x1
#define F_74 0x2
V_173 = V_26 [ F_72 ] ;
V_13 -> V_175 =
! ! ( V_173 & F_73 ) ;
if ( V_13 -> V_175 ) {
V_13 -> V_176 =
! ! ( V_173 & F_74 ) ;
if ( F_70 ( V_15 , V_13 ) )
V_13 -> V_176 = false ;
}
V_96:
F_46 ( V_26 ) ;
}
static void F_75 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
T_2 V_177 ;
T_1 V_178 = V_179 ;
bool V_180 = true ;
T_6 V_181 ;
struct V_182 * V_183 ;
V_183 = F_49 ( sizeof( * V_183 ) , V_95 ) ;
if ( ! V_183 )
goto V_184;
V_89 = F_41 ( V_15 , V_13 -> V_17 ,
V_60 | V_185 , V_183 , sizeof( * V_183 ) ) ;
if ( V_89 )
goto V_96;
V_177 = F_30 ( struct V_182 ,
V_178 ) + V_183 -> V_177 ;
if ( V_177 < sizeof( * V_183 ) )
goto V_96;
V_178 = V_183 -> V_178 ;
V_181 = F_61 ( & V_183 -> V_36 ) ;
V_180 = ( V_181 & V_186 ) != 0 ;
V_96:
F_46 ( V_183 ) ;
V_184:
V_13 -> V_178 = V_178 ;
V_13 -> V_180 = V_180 ;
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
V_13 -> V_187 = V_26 [ 0 ] & 0x1f ;
memcpy ( V_13 -> V_188 , & V_26 [ 8 ] ,
sizeof( V_13 -> V_188 ) ) ;
memcpy ( V_13 -> V_189 , & V_26 [ 16 ] ,
sizeof( V_13 -> V_189 ) ) ;
if ( F_7 ( V_13 ) && V_13 -> V_187 == V_190 ) {
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
struct V_91 * V_191 )
{
int V_89 ;
memset ( V_191 , 0 , sizeof( * V_191 ) ) ;
V_89 = F_42 ( V_15 , V_13 ,
V_191 , sizeof( * V_191 ) ) ;
if ( V_89 ) {
V_13 -> V_192 = V_193 ;
return;
}
V_13 -> V_192 =
F_69 ( & V_191 -> V_194 ) ;
V_13 -> V_195 = V_191 -> V_195 ;
V_13 -> V_196 = V_191 -> V_197 ;
V_13 -> V_198 = V_191 -> V_199 ;
memcpy ( & V_13 -> V_200 ,
& V_191 -> V_201 ,
sizeof( V_13 -> V_200 ) ) ;
memcpy ( & V_13 -> V_202 ,
& V_191 -> V_203 ,
sizeof( V_13 -> V_202 ) ) ;
V_13 -> V_204 = V_191 -> V_205 ;
}
static void F_79 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
char * V_86 ;
static const char V_206 [] =
L_13 ;
char V_207 [ sizeof( V_206 ) + 10 ] ;
switch ( V_13 -> V_178 ) {
case V_208 :
V_86 = L_14 ;
break;
case V_209 :
V_86 = L_15 ;
break;
case V_210 :
V_86 = L_16 ;
break;
case V_211 :
V_86 = L_17 ;
break;
case V_212 :
V_86 = L_18 ;
break;
case V_213 :
V_86 = L_19 ;
break;
case V_214 :
V_86 = L_20 ;
break;
case V_215 :
V_86 = L_21 ;
break;
case V_216 :
V_86 = L_22 ;
break;
case V_217 :
V_86 = L_23 ;
break;
case V_218 :
V_86 = L_24 ;
break;
case V_219 :
V_86 = L_25 ;
break;
case V_220 :
V_86 = L_26 ;
break;
case V_221 :
V_86 = L_27 ;
break;
case V_222 :
V_86 = L_28 ;
break;
case V_223 :
V_86 = L_29 ;
break;
case V_224 :
V_86 = L_30 ;
break;
case V_225 :
V_86 = L_31 ;
break;
case V_226 :
V_86 = L_32 ;
break;
case V_227 :
V_86 = L_33 ;
break;
case V_228 :
V_86 = L_34 ;
break;
case V_229 :
V_86 = L_35 ;
break;
case V_230 :
V_86 =
L_36 ;
break;
case V_231 :
V_86 = L_37 ;
break;
case V_232 :
V_86 = L_38 ;
break;
case V_233 :
V_86 = L_39 ;
break;
case V_179 :
V_86 = L_40 ;
break;
default:
snprintf ( V_207 , sizeof( V_207 ) ,
V_206 , V_13 -> V_178 ) ;
V_86 = V_207 ;
break;
}
F_80 ( & V_15 -> V_23 -> V_75 ,
L_41 ,
V_15 -> V_234 -> V_235 ,
V_13 -> V_142 , V_13 -> V_143 , V_13 -> V_144 , V_86 ) ;
}
static struct V_12 * F_81 (
struct V_8 * V_15 , T_6 V_236 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_187 != V_190 && V_13 -> V_187 != V_237 )
continue;
if ( F_7 ( V_13 ) )
continue;
if ( V_13 -> V_236 == V_236 )
return V_13 ;
}
return NULL ;
}
static void F_83 (
struct V_8 * V_15 , struct V_12 * V_238 )
{
unsigned int V_39 ;
struct V_153 * V_153 ;
struct V_239 * V_160 ;
struct V_12 * V_240 ;
unsigned int V_157 ;
unsigned int V_158 ;
unsigned int V_192 ;
V_238 -> V_192 = V_241 ;
V_153 = V_238 -> V_153 ;
if ( ! V_153 )
return;
V_160 = V_153 -> V_160 ;
V_157 = F_69 ( & V_153 -> V_162 ) *
( F_69 ( & V_153 -> V_163 ) +
F_69 ( & V_153 -> V_164 ) ) ;
V_158 = V_157 *
F_69 ( & V_153 -> V_165 ) ;
V_192 = 0 ;
for ( V_39 = 0 ; V_39 < V_158 ; V_39 ++ ) {
V_240 = F_81 ( V_15 ,
V_160 [ V_39 ] . V_236 ) ;
if ( ! V_240 ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_42 ,
F_84 ( V_238 -> V_17 ) ) ;
V_238 -> V_242 = false ;
V_238 -> V_176 = false ;
F_46 ( V_153 ) ;
V_238 -> V_153 = NULL ;
return;
}
V_192 += V_240 -> V_192 ;
}
V_238 -> V_192 = V_192 ;
}
static void F_85 (
struct V_8 * V_15 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_187 != V_190 && V_13 -> V_187 != V_237 )
continue;
if ( ! F_7 ( V_13 ) )
continue;
F_83 ( V_15 , V_13 ) ;
}
}
static void F_86 ( struct V_122 * V_123 )
{
struct V_8 * V_15 ;
V_15 = F_55 ( F_56 ( V_123 ) , struct V_8 ,
V_21 ) ;
F_87 ( V_15 ) ;
}
static int F_88 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
if ( F_7 ( V_13 ) )
V_89 = F_89 ( V_15 -> V_234 , V_13 -> V_142 ,
V_13 -> V_143 , V_13 -> V_144 ) ;
else
V_89 = F_90 ( V_15 -> V_243 , V_13 ) ;
return V_89 ;
}
static inline void F_91 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
if ( F_7 ( V_13 ) )
F_92 ( V_13 -> V_244 ) ;
else
F_93 ( V_13 ) ;
}
static struct V_12 * F_94 ( struct V_8 * V_15 ,
int V_142 , int V_143 , int V_144 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
if ( V_13 -> V_142 == V_142 && V_13 -> V_143 == V_143 &&
V_13 -> V_144 == V_144 )
return V_13 ;
return NULL ;
}
static inline bool F_95 ( struct V_12 * V_245 ,
struct V_12 * V_246 )
{
if ( V_245 -> V_14 != V_246 -> V_14 )
return false ;
if ( V_245 -> V_14 )
return V_245 -> V_247 == V_246 -> V_247 ;
return memcmp ( V_245 -> V_248 , V_246 -> V_248 ,
sizeof( V_245 -> V_248 ) ) == 0 ;
}
static enum V_249 F_96 ( struct V_8 * V_15 ,
struct V_12 * V_250 ,
struct V_12 * * V_251 )
{
struct V_12 * V_13 ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_4 ( V_250 -> V_17 ,
V_13 -> V_17 ) ) {
* V_251 = V_13 ;
if ( F_95 ( V_250 , V_13 ) ) {
if ( V_250 -> V_180 )
return V_252 ;
return V_253 ;
}
return V_252 ;
}
}
return V_254 ;
}
static void F_97 ( struct V_8 * V_15 ,
char * V_255 , struct V_12 * V_13 )
{
F_80 ( & V_15 -> V_23 -> V_75 ,
L_43 ,
V_255 ,
V_15 -> V_234 -> V_235 ,
V_13 -> V_142 ,
V_13 -> V_143 ,
V_13 -> V_144 ,
F_98 ( V_13 -> V_187 ) ,
V_13 -> V_188 ,
V_13 -> V_189 ,
F_1 ( V_13 -> V_1 ) ,
V_13 -> V_175 ? '+' : '-' ,
V_13 -> V_176 ? '+' : '-' ,
V_13 -> V_256 ? '+' : '-' ,
V_13 -> V_192 ) ;
}
static void F_99 ( struct V_12 * V_257 ,
struct V_12 * V_258 )
{
V_257 -> V_187 = V_258 -> V_187 ;
V_257 -> V_195 = V_258 -> V_195 ;
V_257 -> V_142 = V_258 -> V_142 ;
if ( V_258 -> V_147 ) {
V_257 -> V_143 = V_258 -> V_143 ;
V_257 -> V_144 = V_258 -> V_144 ;
V_257 -> V_147 = true ;
}
V_257 -> V_14 = V_258 -> V_14 ;
V_257 -> V_256 = V_258 -> V_256 ;
V_257 -> V_259 = V_258 -> V_259 ;
V_257 -> V_260 = V_258 -> V_260 ;
memcpy ( V_257 -> V_188 , V_258 -> V_188 ,
sizeof( V_257 -> V_188 ) ) ;
memcpy ( V_257 -> V_189 , V_258 -> V_189 ,
sizeof( V_257 -> V_189 ) ) ;
V_257 -> V_261 = V_258 -> V_261 ;
V_257 -> V_1 = V_258 -> V_1 ;
V_257 -> V_192 = V_258 -> V_192 ;
V_257 -> V_236 = V_258 -> V_236 ;
V_257 -> V_178 = V_258 -> V_178 ;
V_257 -> V_196 = V_258 -> V_196 ;
V_257 -> V_198 = V_258 -> V_198 ;
V_257 -> V_204 = V_258 -> V_204 ;
memcpy ( V_257 -> V_200 , V_258 -> V_200 ,
sizeof( V_257 -> V_200 ) ) ;
memcpy ( V_257 -> V_202 , V_258 -> V_202 ,
sizeof( V_257 -> V_202 ) ) ;
V_257 -> V_175 = V_258 -> V_175 ;
V_257 -> V_242 = false ;
V_257 -> V_176 =
V_258 -> V_176 ;
V_257 -> V_262 = 0 ;
F_46 ( V_257 -> V_153 ) ;
V_257 -> V_153 = V_258 -> V_153 ;
V_258 -> V_153 = NULL ;
}
static inline void F_100 ( struct V_12 * V_13 )
{
if ( V_13 ) {
F_46 ( V_13 -> V_153 ) ;
F_46 ( V_13 ) ;
}
}
static inline void F_101 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
unsigned long V_36 ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
F_103 ( & V_13 -> V_264 ) ;
F_104 ( & V_15 -> V_263 , V_36 ) ;
V_13 -> V_265 = false ;
}
static void F_105 ( struct V_8 * V_15 ,
struct V_12 * V_266 [] , unsigned int V_267 )
{
int V_89 ;
unsigned int V_39 ;
unsigned long V_36 ;
enum V_249 V_268 ;
struct V_12 * V_13 ;
struct V_12 * V_269 ;
struct V_12 * V_251 ;
struct V_270 V_271 ;
struct V_270 V_272 ;
F_106 ( & V_271 ) ;
F_106 ( & V_272 ) ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_273 = true ;
for ( V_39 = 0 ; V_39 < V_267 ; V_39 ++ ) {
V_13 = V_266 [ V_39 ] ;
V_268 = F_96 ( V_15 , V_13 ,
& V_251 ) ;
switch ( V_268 ) {
case V_253 :
V_13 -> V_258 = false ;
V_251 -> V_273 = false ;
F_99 ( V_251 , V_13 ) ;
break;
case V_254 :
V_13 -> V_258 = true ;
break;
case V_252 :
V_13 -> V_258 = true ;
break;
default:
F_34 ( V_268 ) ;
break;
}
}
F_107 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_273 ) {
F_103 ( & V_13 -> V_264 ) ;
F_108 ( & V_13 -> V_274 , & V_272 ) ;
}
}
for ( V_39 = 0 ; V_39 < V_267 ; V_39 ++ ) {
V_13 = V_266 [ V_39 ] ;
if ( ! V_13 -> V_258 )
continue;
if ( V_13 -> V_180 )
continue;
F_108 ( & V_13 -> V_264 ,
& V_15 -> V_275 ) ;
F_108 ( & V_13 -> V_276 , & V_271 ) ;
V_13 -> V_265 = true ;
}
F_85 ( V_15 ) ;
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_242 =
V_13 -> V_176 ;
F_104 ( & V_15 -> V_263 , V_36 ) ;
F_107 (device, next, &delete_list,
delete_list_entry) {
if ( V_13 -> V_244 )
F_91 ( V_15 , V_13 ) ;
if ( V_13 -> V_180 ) {
F_97 ( V_15 , L_44 , V_13 ) ;
F_79 ( V_15 , V_13 ) ;
} else {
F_97 ( V_15 , L_45 , V_13 ) ;
}
F_103 ( & V_13 -> V_274 ) ;
F_100 ( V_13 ) ;
}
F_82 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_244 && V_13 -> V_192 !=
V_13 -> V_277 ) {
V_13 -> V_277 = V_13 -> V_192 ;
F_109 ( V_13 -> V_244 ,
V_13 -> V_277 ) ;
}
}
F_107 (device, next, &add_list, add_list_entry) {
if ( V_13 -> V_256 && ! V_13 -> V_244 ) {
V_89 = F_88 ( V_15 , V_13 ) ;
if ( V_89 ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_46 ,
V_15 -> V_234 -> V_235 ,
V_13 -> V_142 , V_13 -> V_143 ,
V_13 -> V_144 ) ;
F_101 ( V_15 , V_13 ) ;
continue;
}
}
F_97 ( V_15 , L_47 , V_13 ) ;
}
}
static bool F_110 ( struct V_12 * V_13 )
{
bool V_278 = false ;
switch ( V_13 -> V_187 ) {
case V_190 :
case V_237 :
case V_279 :
case V_280 :
case V_281 :
V_278 = true ;
break;
case V_282 :
if ( F_12 ( V_13 -> V_17 ) )
V_278 = true ;
break;
}
return V_278 ;
}
static inline bool F_111 ( T_1 * V_17 ,
struct V_283 * V_284 )
{
T_1 V_285 ;
if ( ! F_112 ( V_17 ) )
return false ;
V_285 = V_284 -> V_285 ;
if ( V_285 & V_286 ) {
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
struct V_270 V_287 ;
struct V_133 * V_134 = NULL ;
struct V_135 * V_136 = NULL ;
struct V_283 * V_284 ;
struct V_141 * V_288 ;
struct V_91 * V_191 = NULL ;
T_6 V_289 ;
T_6 V_290 ;
struct V_12 * * V_266 = NULL ;
struct V_12 * V_13 ;
struct V_12 * V_269 ;
unsigned int V_267 ;
unsigned int V_291 ;
bool V_14 ;
T_1 * V_17 ;
static char * V_292 =
L_48 ;
F_106 ( & V_287 ) ;
V_89 = F_64 ( V_15 , & V_134 , & V_136 ) ;
if ( V_89 )
goto V_96;
if ( V_134 )
V_289 =
F_61 ( & V_134 -> V_47 . V_131 )
/ sizeof( V_134 -> V_293 [ 0 ] ) ;
else
V_289 = 0 ;
if ( V_136 )
V_290 =
F_61 ( & V_136 -> V_47 . V_131 )
/ sizeof( V_136 -> V_293 [ 0 ] ) ;
else
V_290 = 0 ;
if ( V_289 ) {
V_191 = F_49 ( sizeof( * V_191 ) , V_95 ) ;
if ( ! V_191 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_292 ) ;
V_89 = - V_31 ;
goto V_96;
}
}
V_267 = V_289 + V_290 ;
V_266 = F_49 ( sizeof( * V_266 ) *
V_267 , V_95 ) ;
if ( ! V_266 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 , V_292 ) ;
V_89 = - V_31 ;
goto V_96;
}
for ( V_39 = 0 ; V_39 < V_267 ; V_39 ++ ) {
V_13 = F_45 ( sizeof( * V_13 ) , V_95 ) ;
if ( ! V_13 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_292 ) ;
V_89 = - V_31 ;
goto V_96;
}
F_108 ( & V_13 -> V_294 ,
& V_287 ) ;
}
V_13 = NULL ;
V_291 = 0 ;
for ( V_39 = 0 ; V_39 < V_267 ; V_39 ++ ) {
if ( V_39 < V_289 ) {
V_14 = true ;
V_284 = & V_134 -> V_293 [ V_39 ] ;
V_288 = NULL ;
V_17 = V_284 -> V_145 ;
} else {
V_14 = false ;
V_284 = NULL ;
V_288 =
& V_136 -> V_293 [ V_39 - V_289 ] ;
V_17 = V_288 -> V_145 ;
}
if ( V_14 &&
F_111 ( V_17 , V_284 ) )
continue;
if ( V_13 )
V_13 = F_115 ( V_13 , V_294 ) ;
else
V_13 = F_116 ( & V_287 ,
struct V_12 , V_294 ) ;
memcpy ( V_13 -> V_17 , V_17 , sizeof( V_13 -> V_17 ) ) ;
V_13 -> V_14 = V_14 ;
V_13 -> V_1 = V_150 ;
V_89 = F_76 ( V_15 , V_13 ) ;
if ( V_89 == - V_31 ) {
F_57 ( & V_15 -> V_23 -> V_75 , L_12 ,
V_292 ) ;
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
V_13 -> V_256 = F_113 ( V_13 ) ;
if ( V_13 -> V_14 ) {
V_13 -> V_247 = V_284 -> V_247 ;
if ( ( V_284 -> V_285 &
V_295 ) &&
V_284 -> V_236 )
V_13 -> V_260 = true ;
} else {
memcpy ( V_13 -> V_248 , V_288 -> V_248 ,
sizeof( V_13 -> V_248 ) ) ;
}
switch ( V_13 -> V_187 ) {
case V_190 :
case V_237 :
case V_281 :
if ( V_13 -> V_14 ) {
V_13 -> V_261 =
F_84 ( & V_13 -> V_247 ) ;
if ( V_13 -> V_187 == V_190 ||
V_13 -> V_187 == V_237 ) {
V_13 -> V_236 =
V_284 -> V_236 ;
F_78 ( V_15 ,
V_13 , V_191 ) ;
}
}
break;
}
V_266 [ V_291 ++ ] = V_13 ;
}
F_105 ( V_15 , V_266 , V_291 ) ;
V_96:
F_107 (device, next, &new_device_list_head,
new_device_list_entry) {
if ( V_13 -> V_265 )
continue;
F_103 ( & V_13 -> V_294 ) ;
F_100 ( V_13 ) ;
}
F_46 ( V_266 ) ;
F_46 ( V_134 ) ;
F_46 ( V_136 ) ;
F_46 ( V_191 ) ;
return V_89 ;
}
static void F_117 ( struct V_8 * V_15 )
{
unsigned long V_36 ;
struct V_12 * V_13 ;
struct V_12 * V_269 ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
F_107 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_244 )
F_91 ( V_15 , V_13 ) ;
F_103 ( & V_13 -> V_264 ) ;
F_100 ( V_13 ) ;
}
F_104 ( & V_15 -> V_263 , V_36 ) ;
}
static int F_87 ( struct V_8 * V_15 )
{
int V_89 ;
if ( F_8 ( V_15 ) )
return - V_93 ;
F_118 ( & V_15 -> V_296 ) ;
V_89 = F_114 ( V_15 ) ;
if ( V_89 )
F_17 ( V_15 ) ;
F_119 ( & V_15 -> V_296 ) ;
return V_89 ;
}
static void F_120 ( struct V_9 * V_10 )
{
F_87 ( F_5 ( V_10 ) ) ;
}
static int F_121 ( struct V_9 * V_10 ,
unsigned long V_297 )
{
struct V_8 * V_15 ;
V_15 = F_6 ( V_10 ) ;
return ! F_122 ( & V_15 -> V_296 ) ;
}
static inline void F_123 (
struct V_298 * V_299 , struct V_153 * V_153 ,
V_32 V_300 )
{
T_6 V_301 ;
V_301 = F_27 ( & V_153 -> V_301 ) ;
if ( V_301 != 512 )
V_300 = ( V_300 * V_301 ) / 512 ;
V_299 -> V_302 =
F_69 ( & V_153 -> V_302 ) ;
V_299 -> V_303 = F_124 ( V_300 ) ;
V_299 -> V_304 = F_125 ( V_300 ) ;
}
static int F_126 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_305 * V_306 )
{
struct V_153 * V_153 ;
bool V_307 = false ;
T_6 V_308 ;
V_32 V_300 ;
V_32 V_309 ;
T_6 V_310 ;
T_6 V_311 ;
V_32 V_312 ;
V_32 V_313 ;
T_6 V_314 ;
T_6 V_315 ;
T_6 V_316 ;
T_6 V_317 ;
V_32 V_318 ;
V_32 V_319 ;
T_6 V_156 ;
V_32 V_320 ;
V_32 V_321 ;
T_6 V_322 ;
T_6 V_323 ;
T_6 V_324 ;
T_6 V_325 ;
T_4 V_163 ;
T_6 V_326 ;
T_4 V_162 ;
T_6 V_327 ;
T_4 V_171 ;
T_6 V_328 ;
T_6 V_329 ;
T_6 V_330 ;
T_6 V_331 ;
T_6 V_236 ;
V_32 V_332 ;
T_6 V_333 ;
T_1 V_45 [ 16 ] ;
T_1 V_334 ;
int V_262 ;
struct V_298 * V_335 ;
struct V_298 V_299 ;
#if V_336 == 32
V_32 V_337 ;
#endif
switch ( V_4 -> V_338 [ 0 ] ) {
case V_339 :
V_307 = true ;
case V_340 :
V_300 = ( V_32 ) ( ( ( V_4 -> V_338 [ 1 ] & 0x1f ) << 16 ) |
( V_4 -> V_338 [ 2 ] << 8 ) | V_4 -> V_338 [ 3 ] ) ;
V_310 = ( T_6 ) V_4 -> V_338 [ 4 ] ;
if ( V_310 == 0 )
V_310 = 256 ;
break;
case V_341 :
V_307 = true ;
case V_342 :
V_300 = ( V_32 ) F_61 ( & V_4 -> V_338 [ 2 ] ) ;
V_310 = ( T_6 ) F_127 ( & V_4 -> V_338 [ 7 ] ) ;
break;
case V_343 :
V_307 = true ;
case V_344 :
V_300 = ( V_32 ) F_61 ( & V_4 -> V_338 [ 2 ] ) ;
V_310 = F_61 ( & V_4 -> V_338 [ 6 ] ) ;
break;
case V_345 :
V_307 = true ;
case V_346 :
V_300 = F_84 ( & V_4 -> V_338 [ 2 ] ) ;
V_310 = F_61 ( & V_4 -> V_338 [ 10 ] ) ;
break;
default:
return V_347 ;
}
if ( V_307 && V_13 -> V_1 != V_348 )
return V_347 ;
if ( F_128 ( V_310 == 0 ) )
return V_347 ;
V_309 = V_300 + V_310 - 1 ;
V_153 = V_13 -> V_153 ;
if ( V_309 >= F_26 ( & V_153 -> V_349 ) ||
V_309 < V_300 )
return V_347 ;
V_163 = F_69 ( & V_153 -> V_163 ) ;
V_171 = F_69 ( & V_153 -> V_171 ) ;
V_162 = F_69 ( & V_153 -> V_162 ) ;
V_311 = V_163 * V_171 ;
#if V_336 == 32
V_337 = V_300 ;
F_129 ( V_337 , V_311 ) ;
V_312 = V_337 ;
V_337 = V_309 ;
F_129 ( V_337 , V_311 ) ;
V_313 = V_337 ;
V_314 = ( T_6 ) ( V_300 - ( V_312 * V_311 ) ) ;
V_315 = ( T_6 ) ( V_309 - ( V_313 * V_311 ) ) ;
V_337 = V_314 ;
F_129 ( V_337 , V_171 ) ;
V_316 = V_337 ;
V_337 = V_315 ;
F_129 ( V_337 , V_171 ) ;
V_317 = V_337 ;
#else
V_312 = V_300 / V_311 ;
V_313 = V_309 / V_311 ;
V_314 = ( T_6 ) ( V_300 - ( V_312 * V_311 ) ) ;
V_315 = ( T_6 ) ( V_309 - ( V_313 * V_311 ) ) ;
V_316 = V_314 / V_171 ;
V_317 = V_315 / V_171 ;
#endif
if ( V_312 != V_313 || V_316 != V_317 )
return V_347 ;
V_326 = V_163 +
F_69 ( & V_153 -> V_164 ) ;
V_331 = ( ( T_6 ) ( V_312 >> V_153 -> V_350 ) ) %
F_69 ( & V_153 -> V_165 ) ;
V_308 = ( V_331 * V_326 ) + V_316 ;
if ( V_13 -> V_1 == V_167 ) {
if ( V_13 -> V_262 )
V_308 += V_163 ;
V_13 -> V_262 = ! V_13 -> V_262 ;
} else if ( V_13 -> V_1 == V_168 ) {
V_262 = V_13 -> V_262 ;
if ( V_262 == 0 ) {
V_308 %= V_163 ;
} else {
do {
V_330 = V_308 / V_163 ;
if ( V_262 != V_330 ) {
if ( V_330 <
V_162 - 1 ) {
V_308 += V_163 ;
V_330 ++ ;
} else {
V_308 %= V_163 ;
V_330 = 0 ;
}
}
} while ( V_262 != V_330 );
}
V_262 =
( V_262 >= V_162 - 1 ) ?
0 : V_262 + 1 ;
F_34 ( V_262 >= V_162 ) ;
V_13 -> V_262 = V_262 ;
} else if ( ( V_13 -> V_1 == V_169 ||
V_13 -> V_1 == V_170 ) && V_162 > 1 ) {
V_156 = V_171 * V_163 ;
V_327 = V_156 * V_162 ;
#if V_336 == 32
V_337 = V_300 ;
V_328 = F_129 ( V_337 , V_327 ) ;
V_337 = V_328 ;
F_129 ( V_337 , V_156 ) ;
V_328 = V_337 ;
V_337 = V_309 ;
V_329 = F_129 ( V_337 , V_327 ) ;
V_337 = V_329 ;
F_129 ( V_337 , V_156 ) ;
V_329 = V_337 ;
#else
V_328 = ( V_300 % V_327 ) / V_156 ;
V_329 = ( V_309 % V_327 ) / V_156 ;
#endif
if ( V_328 != V_329 )
return V_347 ;
#if V_336 == 32
V_337 = V_300 ;
F_129 ( V_337 , V_327 ) ;
V_312 = V_320 = V_318 = V_337 ;
V_337 = V_309 ;
F_129 ( V_337 , V_327 ) ;
V_321 = V_319 = V_337 ;
#else
V_312 = V_320 = V_318 =
V_300 / V_327 ;
V_321 = V_319 = V_309 / V_327 ;
#endif
if ( V_320 != V_321 )
return V_347 ;
#if V_336 == 32
V_337 = V_300 ;
V_314 = F_129 ( V_337 , V_327 ) ;
V_337 = V_314 ;
V_314 = ( T_6 ) F_129 ( V_337 , V_156 ) ;
V_322 = V_314 ;
V_337 = V_309 ;
V_323 = F_129 ( V_337 , V_327 ) ;
V_337 = V_323 ;
V_323 = F_129 ( V_337 , V_156 ) ;
V_337 = V_322 ;
F_129 ( V_337 , V_171 ) ;
V_316 = V_324 = V_337 ;
V_337 = V_323 ;
F_129 ( V_337 , V_171 ) ;
V_325 = V_337 ;
#else
V_314 = V_322 =
( T_6 ) ( ( V_300 % V_327 ) %
V_156 ) ;
V_323 =
( T_6 ) ( ( V_309 % V_327 ) %
V_156 ) ;
V_316 = V_322 / V_171 ;
V_324 = V_316 ;
V_325 = V_323 / V_171 ;
#endif
if ( V_324 != V_325 )
return V_347 ;
V_331 =
( ( T_6 ) ( V_312 >> V_153 -> V_350 ) ) %
F_69 ( & V_153 -> V_165 ) ;
V_308 = ( V_328 *
( F_69 ( & V_153 -> V_165 ) *
V_326 ) ) +
( V_331 * V_326 ) + V_316 ;
}
if ( F_128 ( V_308 >= V_166 ) )
return V_347 ;
V_236 = V_153 -> V_160 [ V_308 ] . V_236 ;
V_332 = F_26 ( & V_153 -> V_351 ) +
V_312 * V_171 +
( V_314 - V_316 * V_171 ) ;
V_333 = V_310 ;
if ( V_153 -> V_352 ) {
V_332 <<= V_153 -> V_352 ;
V_333 <<= V_153 -> V_352 ;
}
if ( F_128 ( V_333 > 0xffff ) )
return V_347 ;
if ( V_332 > 0xffffffff ) {
V_45 [ 0 ] = V_307 ? V_345 : V_346 ;
V_45 [ 1 ] = 0 ;
F_130 ( V_332 , & V_45 [ 2 ] ) ;
F_31 ( V_333 , & V_45 [ 10 ] ) ;
V_45 [ 14 ] = 0 ;
V_45 [ 15 ] = 0 ;
V_334 = 16 ;
} else {
V_45 [ 0 ] = V_307 ? V_341 : V_342 ;
V_45 [ 1 ] = 0 ;
F_31 ( ( T_6 ) V_332 , & V_45 [ 2 ] ) ;
V_45 [ 6 ] = 0 ;
F_32 ( ( T_4 ) V_333 , & V_45 [ 7 ] ) ;
V_45 [ 9 ] = 0 ;
V_334 = 10 ;
}
if ( F_69 ( & V_153 -> V_36 ) &
V_353 ) {
F_123 ( & V_299 , V_153 ,
V_300 ) ;
V_335 = & V_299 ;
} else {
V_335 = NULL ;
}
return F_131 ( V_15 , V_4 , V_236 ,
V_45 , V_334 , V_306 , V_335 ) ;
}
static int F_132 ( struct V_8 * V_15 )
{
struct V_354 T_7 * V_355 ;
unsigned long V_356 ;
V_32 V_357 ;
T_1 V_86 ;
V_355 = V_15 -> V_355 ;
V_356 = ( V_358 * V_359 ) + V_360 ;
while ( 1 ) {
V_357 = F_133 ( & V_355 -> V_357 ) ;
if ( memcmp ( & V_357 , V_361 ,
sizeof( V_357 ) ) == 0 )
break;
if ( F_134 ( V_360 , V_356 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_50 ) ;
return - V_362 ;
}
F_135 ( V_363 ) ;
}
while ( 1 ) {
V_86 = F_136 ( & V_355 -> V_364 ) ;
if ( V_86 == V_365 )
break;
if ( F_134 ( V_360 , V_356 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_51 ) ;
return - V_362 ;
}
F_135 ( V_363 ) ;
}
while ( 1 ) {
if ( F_137 ( & V_355 -> V_366 ) ==
V_367 )
break;
if ( F_134 ( V_360 , V_356 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_52 ) ;
return - V_362 ;
}
F_135 ( V_363 ) ;
}
return 0 ;
}
static inline void F_138 ( struct V_80 * V_81 )
{
struct V_12 * V_13 ;
V_13 = V_81 -> V_4 -> V_13 -> V_11 ;
V_13 -> V_242 = false ;
}
static inline void F_139 ( struct V_368 * V_244 )
{
struct V_8 * V_15 ;
struct V_12 * V_13 ;
if ( F_140 ( V_244 ) ) {
F_141 ( V_244 , V_369 ) ;
V_15 = F_5 ( V_244 -> V_370 ) ;
F_18 ( & V_15 -> V_21 , 0 ) ;
V_13 = V_244 -> V_11 ;
F_33 ( & V_15 -> V_23 -> V_75 , L_53 ,
V_15 -> V_234 -> V_235 , V_13 -> V_142 ,
V_13 -> V_143 , V_13 -> V_144 ) ;
}
}
static void F_142 ( struct V_80 * V_81 )
{
T_1 V_371 ;
T_1 V_372 ;
struct V_3 * V_4 ;
struct V_373 * V_87 ;
T_2 V_374 ;
int V_375 ;
int V_376 ;
struct V_377 V_378 ;
V_4 = V_81 -> V_4 ;
if ( ! V_4 )
return;
V_87 = V_81 -> V_87 ;
V_371 = V_87 -> V_86 ;
V_372 = V_379 ;
if ( V_87 -> V_380 == V_381 ) {
V_376 =
F_27 ( & V_87 -> V_382 ) ;
V_375 = F_143 ( V_4 ) - V_376 ;
F_144 ( V_4 , V_375 ) ;
if ( V_376 < V_4 -> V_383 )
V_372 = V_384 ;
}
V_374 = F_69 ( & V_87 -> V_374 ) ;
if ( V_374 == 0 )
V_374 =
F_69 ( & V_87 -> V_385 ) ;
if ( V_374 ) {
if ( V_374 > sizeof( V_87 -> V_386 ) )
V_374 = sizeof( V_87 -> V_386 ) ;
if ( V_371 == V_387 &&
F_145 ( V_87 -> V_386 ,
V_374 , & V_378 ) &&
V_378 . V_388 == V_389 &&
V_378 . V_390 == 0x3e &&
V_378 . V_391 == 0x1 ) {
F_139 ( V_4 -> V_13 ) ;
V_372 = V_392 ;
}
if ( V_374 > V_393 )
V_374 = V_393 ;
memcpy ( V_4 -> V_394 , V_87 -> V_386 ,
V_374 ) ;
}
V_4 -> V_395 = V_371 ;
F_146 ( V_4 , V_372 ) ;
}
static void F_147 ( struct V_80 * V_81 )
{
T_1 V_371 ;
T_1 V_372 ;
struct V_3 * V_4 ;
struct V_396 * V_87 ;
T_2 V_374 ;
int V_375 ;
int V_376 ;
bool V_397 ;
V_4 = V_81 -> V_4 ;
V_87 = V_81 -> V_87 ;
V_372 = V_379 ;
V_374 = 0 ;
V_397 = false ;
switch ( V_87 -> V_398 ) {
case V_399 :
V_371 = V_87 -> V_86 ;
break;
case V_400 :
switch ( V_87 -> V_86 ) {
case V_401 :
V_371 = V_402 ;
break;
case V_403 :
V_371 = V_404 ;
V_375 = F_27 (
& V_87 -> V_375 ) ;
F_144 ( V_4 , V_375 ) ;
V_376 = F_143 ( V_4 ) - V_375 ;
if ( V_376 < V_4 -> V_383 )
V_372 = V_384 ;
break;
case V_405 :
V_371 = V_404 ;
break;
case V_406 :
F_138 ( V_81 ) ;
V_371 = V_404 ;
V_81 -> V_86 = - V_407 ;
break;
case V_408 :
case V_409 :
V_397 = true ;
F_139 ( V_4 -> V_13 ) ;
V_372 = V_392 ;
V_371 = V_387 ;
break;
case V_410 :
default:
V_371 = V_387 ;
break;
}
break;
case V_411 :
case V_412 :
V_371 = V_404 ;
break;
case V_413 :
case V_414 :
default:
V_371 = V_387 ;
break;
}
if ( V_87 -> V_415 ) {
V_374 =
F_69 ( & V_87 -> V_416 ) ;
if ( V_374 ) {
if ( V_374 > sizeof( V_87 -> V_386 ) )
V_374 = sizeof( V_87 -> V_386 ) ;
if ( V_374 > V_393 )
V_374 = V_393 ;
memcpy ( V_4 -> V_394 , V_87 -> V_386 ,
V_374 ) ;
}
}
if ( V_397 && V_374 == 0 )
F_148 ( 0 , V_4 -> V_394 , V_389 ,
0x3e , 0x1 ) ;
V_4 -> V_395 = V_371 ;
F_146 ( V_4 , V_372 ) ;
}
static void F_149 ( unsigned int V_48 ,
struct V_80 * V_81 )
{
switch ( V_48 ) {
case V_417 :
F_142 ( V_81 ) ;
break;
case V_418 :
F_147 ( V_81 ) ;
break;
}
}
static int F_150 (
struct V_419 * V_420 )
{
int V_89 ;
switch ( V_420 -> V_421 ) {
case V_422 :
case V_423 :
V_89 = 0 ;
break;
default:
V_89 = - V_424 ;
break;
}
return V_89 ;
}
static unsigned int F_151 ( struct V_8 * V_15 ,
struct V_305 * V_306 )
{
unsigned int V_425 ;
T_8 V_426 ;
T_8 V_427 ;
struct V_80 * V_81 ;
struct V_428 * V_420 ;
T_4 V_429 ;
V_425 = 0 ;
V_427 = V_306 -> V_430 ;
while ( 1 ) {
V_426 = * V_306 -> V_426 ;
if ( V_426 == V_427 )
break;
V_425 ++ ;
V_420 = V_306 -> V_431 +
( V_427 * V_432 ) ;
V_429 = F_69 ( & V_420 -> V_429 ) ;
F_34 ( V_429 >= V_15 -> V_85 ) ;
V_81 = & V_15 -> V_83 [ V_429 ] ;
F_34 ( F_152 ( & V_81 -> V_84 ) == 0 ) ;
switch ( V_420 -> V_47 . V_48 ) {
case V_433 :
case V_434 :
case V_435 :
break;
case V_436 :
V_81 -> V_86 =
F_150 (
( void * ) V_420 ) ;
break;
case V_437 :
F_138 ( V_81 ) ;
V_81 -> V_86 = - V_407 ;
break;
case V_417 :
case V_418 :
V_81 -> V_87 = V_15 -> V_438 +
( F_69 ( & V_420 -> V_439 ) *
V_440 ) ;
F_149 ( V_420 -> V_47 . V_48 ,
V_81 ) ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_54 ,
V_420 -> V_47 . V_48 ) ;
F_34 ( V_420 -> V_47 . V_48 ) ;
break;
}
V_81 -> V_441 ( V_81 ,
V_81 -> V_442 ) ;
V_427 = ( V_427 + 1 ) % V_15 -> V_443 ;
}
if ( V_425 ) {
V_306 -> V_430 = V_427 ;
F_153 ( V_427 , V_306 -> V_427 ) ;
}
return V_425 ;
}
static inline unsigned int F_154 ( unsigned int V_444 ,
unsigned int V_445 , unsigned int V_446 )
{
unsigned int V_447 ;
if ( V_444 >= V_445 )
V_447 = V_444 - V_445 ;
else
V_447 = V_446 - V_445 + V_444 ;
return V_446 - V_447 - 1 ;
}
static void F_155 ( struct V_8 * V_15 ,
struct V_448 * V_449 , T_2 V_52 )
{
T_8 V_450 ;
T_8 V_451 ;
unsigned long V_36 ;
void * V_452 ;
unsigned long V_356 ;
struct V_305 * V_306 ;
V_306 = & V_15 -> V_453 [ V_454 ] ;
F_29 ( V_306 -> V_455 , & V_449 -> V_47 . V_456 ) ;
V_356 = ( V_457 * V_359 ) + V_360 ;
while ( 1 ) {
F_102 ( & V_306 -> V_458 [ V_459 ] , V_36 ) ;
V_450 = V_306 -> V_460 [ V_459 ] ;
V_451 = * V_306 -> V_451 [ V_459 ] ;
if ( F_154 ( V_450 , V_451 ,
V_15 -> V_461 ) )
break;
F_104 (
& V_306 -> V_458 [ V_459 ] , V_36 ) ;
if ( F_134 ( V_360 , V_356 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_55 ) ;
return;
}
}
V_452 = V_306 -> V_462 [ V_459 ] +
( V_450 * V_463 ) ;
memcpy ( V_452 , V_449 , V_52 ) ;
V_450 = ( V_450 + 1 ) % V_15 -> V_461 ;
V_306 -> V_460 [ V_459 ] = V_450 ;
F_153 ( V_450 , V_306 -> V_450 [ V_459 ] ) ;
F_104 ( & V_306 -> V_458 [ V_459 ] , V_36 ) ;
}
static void F_156 ( struct V_8 * V_15 ,
struct V_464 * V_465 )
{
struct V_448 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_466 ;
F_29 ( sizeof( V_41 ) - V_51 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_467 = V_465 -> V_467 ;
V_41 . V_468 = V_465 -> V_468 ;
V_41 . V_469 = V_465 -> V_469 ;
F_155 ( V_15 , & V_41 , sizeof( V_41 ) ) ;
}
static void F_157 ( struct V_122 * V_123 )
{
unsigned int V_39 ;
struct V_8 * V_15 ;
struct V_464 * V_470 ;
bool V_471 = false ;
V_15 = F_55 ( V_123 , struct V_8 , V_472 ) ;
V_470 = V_15 -> V_473 ;
for ( V_39 = 0 ; V_39 < V_474 ; V_39 ++ ) {
if ( V_470 -> V_475 ) {
V_470 -> V_475 = false ;
F_156 ( V_15 , V_470 ) ;
if ( V_39 != V_476 )
V_471 = true ;
}
V_470 ++ ;
}
if ( V_471 )
F_17 ( V_15 ) ;
}
static void F_11 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
unsigned int V_477 ;
struct V_305 * V_306 ;
unsigned long V_36 ;
struct V_80 * V_81 ;
struct V_80 * V_269 ;
struct V_3 * V_4 ;
V_15 -> V_16 = false ;
F_33 ( & V_15 -> V_23 -> V_75 , L_56 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_306 = & V_15 -> V_453 [ V_39 ] ;
for ( V_477 = 0 ; V_477 < 2 ; V_477 ++ ) {
F_102 (
& V_306 -> V_458 [ V_477 ] , V_36 ) ;
F_107 (io_request, next,
&queue_group->request_list[path],
request_list_entry) {
V_4 = V_81 -> V_4 ;
if ( V_4 ) {
F_146 ( V_4 , V_392 ) ;
F_3 ( V_4 ) ;
}
F_103 ( & V_81 -> V_479 ) ;
}
F_104 (
& V_306 -> V_458 [ V_477 ] , V_36 ) ;
}
}
}
static void F_158 ( unsigned long V_386 )
{
int V_480 ;
struct V_8 * V_15 = (struct V_8 * ) V_386 ;
V_480 = F_152 ( & V_15 -> V_480 ) ;
if ( V_480 == V_15 -> V_481 ) {
V_15 -> V_482 ++ ;
if ( V_15 -> V_482 >
V_483 ) {
F_11 ( V_15 ) ;
return;
}
V_15 -> V_473 [ V_476 ] . V_475 = true ;
F_159 ( & V_15 -> V_472 ) ;
} else {
V_15 -> V_482 = 0 ;
}
V_15 -> V_481 = V_480 ;
F_160 ( & V_15 -> V_484 ,
V_360 + V_485 ) ;
}
static void F_161 ( struct V_8 * V_15 )
{
V_15 -> V_481 =
F_152 ( & V_15 -> V_480 ) ;
F_162 ( & V_15 -> V_484 ) ;
V_15 -> V_484 . V_486 =
V_360 + V_485 ;
V_15 -> V_484 . V_386 = ( unsigned long ) V_15 ;
V_15 -> V_484 . V_487 = F_158 ;
F_163 ( & V_15 -> V_484 ) ;
V_15 -> V_488 = true ;
}
static inline void F_164 ( struct V_8 * V_15 )
{
if ( V_15 -> V_488 )
F_165 ( & V_15 -> V_484 ) ;
}
static int F_166 ( unsigned int V_467 )
{
int V_489 ;
switch ( V_467 ) {
case V_490 :
V_489 = V_476 ;
break;
case V_491 :
V_489 = V_492 ;
break;
case V_493 :
V_489 = V_494 ;
break;
case V_495 :
V_489 = V_496 ;
break;
case V_497 :
V_489 = V_498 ;
break;
case V_499 :
V_489 = V_500 ;
break;
case V_501 :
V_489 = V_502 ;
break;
default:
V_489 = - 1 ;
break;
}
return V_489 ;
}
static unsigned int F_167 ( struct V_8 * V_15 )
{
unsigned int V_503 ;
T_8 V_426 ;
T_8 V_427 ;
struct V_504 * V_505 ;
struct V_506 * V_420 ;
struct V_464 * V_470 ;
bool V_507 ;
int V_508 ;
V_505 = & V_15 -> V_505 ;
V_503 = 0 ;
V_507 = false ;
V_427 = V_505 -> V_430 ;
while ( 1 ) {
V_426 = * V_505 -> V_426 ;
if ( V_426 == V_427 )
break;
V_503 ++ ;
V_420 = V_505 -> V_431 +
( V_427 * V_509 ) ;
V_508 =
F_166 ( V_420 -> V_467 ) ;
if ( V_508 >= 0 ) {
if ( V_420 -> V_510 ) {
V_470 =
& V_15 -> V_473 [ V_508 ] ;
V_470 -> V_467 =
V_420 -> V_467 ;
V_470 -> V_468 = V_420 -> V_468 ;
V_470 -> V_469 =
V_420 -> V_469 ;
if ( V_508 != V_476 ) {
V_470 -> V_475 = true ;
V_507 = true ;
}
}
}
V_427 = ( V_427 + 1 ) % V_511 ;
}
if ( V_503 ) {
V_505 -> V_430 = V_427 ;
F_153 ( V_427 , V_505 -> V_427 ) ;
if ( V_507 )
F_159 ( & V_15 -> V_472 ) ;
}
return V_503 ;
}
static T_9 F_168 ( int V_512 , void * V_386 )
{
struct V_8 * V_15 ;
struct V_305 * V_306 ;
unsigned int V_513 ;
V_306 = V_386 ;
V_15 = V_306 -> V_15 ;
if ( ! V_15 || ! V_306 -> V_427 )
return V_514 ;
V_513 = F_151 ( V_15 , V_306 ) ;
if ( V_512 == V_15 -> V_515 )
V_513 += F_167 ( V_15 ) ;
if ( V_513 )
F_169 ( & V_15 -> V_480 ) ;
F_170 ( V_15 , V_306 , V_459 , NULL ) ;
F_170 ( V_15 , V_306 , V_516 , NULL ) ;
return V_517 ;
}
static int F_171 ( struct V_8 * V_15 )
{
struct V_23 * V_518 = V_15 -> V_23 ;
int V_39 ;
int V_89 ;
V_15 -> V_515 = F_172 ( V_518 , 0 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_519 ; V_39 ++ ) {
V_89 = F_173 ( F_172 ( V_518 , V_39 ) , F_168 , 0 ,
V_520 , & V_15 -> V_453 [ V_39 ] ) ;
if ( V_89 ) {
F_33 ( & V_518 -> V_75 ,
L_57 ,
F_172 ( V_518 , V_39 ) , V_89 ) ;
return V_89 ;
}
V_15 -> V_521 ++ ;
}
return 0 ;
}
static int F_174 ( struct V_8 * V_15 )
{
int V_522 ;
V_522 = F_175 ( V_15 -> V_23 ,
V_523 , V_15 -> V_478 ,
V_524 | V_525 ) ;
if ( V_522 < 0 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_58 , V_522 ) ;
return V_522 ;
}
V_15 -> V_519 = V_522 ;
return 0 ;
}
static int F_176 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
T_2 V_526 ;
T_2 V_527 ;
T_2 V_528 ;
void * V_529 ;
void * V_530 ;
void * V_531 ;
unsigned int V_532 ;
unsigned int V_533 ;
unsigned int V_534 ;
struct V_305 * V_306 ;
V_527 =
V_463 *
V_15 -> V_461 ;
V_528 =
V_432 *
V_15 -> V_443 ;
V_532 = V_15 -> V_478 * 2 ;
V_533 = V_15 -> V_478 ;
V_534 = ( V_15 -> V_478 * 3 ) + 1 ;
V_531 = NULL ;
for ( V_39 = 0 ; V_39 < V_532 ; V_39 ++ ) {
V_531 = F_177 ( V_531 ,
V_535 ) ;
V_531 += V_527 ;
}
for ( V_39 = 0 ; V_39 < V_533 ; V_39 ++ ) {
V_531 = F_177 ( V_531 ,
V_535 ) ;
V_531 += V_528 ;
}
V_531 = F_177 ( V_531 ,
V_535 ) ;
V_531 += V_511 *
V_509 ;
for ( V_39 = 0 ; V_39 < V_534 ; V_39 ++ ) {
V_531 = F_177 ( V_531 ,
V_536 ) ;
V_531 += sizeof( T_8 ) ;
}
V_526 = ( T_2 ) V_531 +
V_535 ;
V_15 -> V_537 =
F_178 ( & V_15 -> V_23 -> V_75 ,
V_526 ,
& V_15 -> V_538 , V_95 ) ;
if ( ! V_15 -> V_537 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_59 ) ;
return - V_31 ;
}
V_15 -> V_539 = V_526 ;
V_529 = F_177 ( V_15 -> V_537 ,
V_535 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_306 = & V_15 -> V_453 [ V_39 ] ;
V_306 -> V_462 [ V_459 ] = V_529 ;
V_306 -> V_540 [ V_459 ] =
V_15 -> V_538 +
( V_529 - V_15 -> V_537 ) ;
V_529 += V_527 ;
V_529 = F_177 ( V_529 ,
V_535 ) ;
V_306 -> V_462 [ V_516 ] = V_529 ;
V_306 -> V_540 [ V_516 ] =
V_15 -> V_538 +
( V_529 - V_15 -> V_537 ) ;
V_529 += V_527 ;
V_529 = F_177 ( V_529 ,
V_535 ) ;
}
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_306 = & V_15 -> V_453 [ V_39 ] ;
V_306 -> V_431 = V_529 ;
V_306 -> V_541 =
V_15 -> V_538 +
( V_529 - V_15 -> V_537 ) ;
V_529 += V_528 ;
V_529 = F_177 ( V_529 ,
V_535 ) ;
}
V_15 -> V_505 . V_431 = V_529 ;
V_15 -> V_505 . V_541 =
V_15 -> V_538 +
( V_529 - V_15 -> V_537 ) ;
V_529 += V_511 *
V_509 ;
V_530 = F_177 ( V_529 ,
V_536 ) ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_306 = & V_15 -> V_453 [ V_39 ] ;
V_306 -> V_451 [ V_459 ] = V_530 ;
V_306 -> V_542 [ V_459 ] =
V_15 -> V_538 +
( V_530 - V_15 -> V_537 ) ;
V_530 += sizeof( T_8 ) ;
V_530 = F_177 ( V_530 ,
V_536 ) ;
V_306 -> V_451 [ V_516 ] = V_530 ;
V_306 -> V_542 [ V_516 ] =
V_15 -> V_538 +
( V_530 - V_15 -> V_537 ) ;
V_530 += sizeof( T_8 ) ;
V_530 = F_177 ( V_530 ,
V_536 ) ;
V_306 -> V_426 = V_530 ;
V_306 -> V_543 =
V_15 -> V_538 +
( V_530 - V_15 -> V_537 ) ;
V_530 += sizeof( T_8 ) ;
V_530 = F_177 ( V_530 ,
V_536 ) ;
}
V_15 -> V_505 . V_426 = V_530 ;
V_15 -> V_505 . V_543 =
V_15 -> V_538 +
( V_530 - V_15 -> V_537 ) ;
return 0 ;
}
static void F_179 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
T_4 V_544 = V_545 ;
T_4 V_546 = V_545 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ )
V_15 -> V_453 [ V_39 ] . V_15 = V_15 ;
V_15 -> V_505 . V_455 = V_546 ++ ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_15 -> V_453 [ V_39 ] . V_547 [ V_459 ] = V_544 ++ ;
V_15 -> V_453 [ V_39 ] . V_547 [ V_516 ] = V_544 ++ ;
V_15 -> V_453 [ V_39 ] . V_455 = V_546 ++ ;
}
V_15 -> V_505 . V_548 = 0 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ )
V_15 -> V_453 [ V_39 ] . V_548 = V_39 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
F_180 ( & V_15 -> V_453 [ V_39 ] . V_458 [ 0 ] ) ;
F_180 ( & V_15 -> V_453 [ V_39 ] . V_458 [ 1 ] ) ;
F_106 ( & V_15 -> V_453 [ V_39 ] . V_549 [ 0 ] ) ;
F_106 ( & V_15 -> V_453 [ V_39 ] . V_549 [ 1 ] ) ;
}
}
static int F_181 ( struct V_8 * V_15 )
{
T_2 V_526 ;
struct V_550 * V_551 ;
struct V_552 * V_553 ;
V_526 = sizeof( struct V_550 ) +
V_535 ;
V_15 -> V_554 =
F_178 ( & V_15 -> V_23 -> V_75 ,
V_526 ,
& V_15 -> V_555 ,
V_95 ) ;
if ( ! V_15 -> V_554 )
return - V_31 ;
V_15 -> V_556 = V_526 ;
V_553 = & V_15 -> V_553 ;
V_551 = F_177 ( V_15 -> V_554 ,
V_535 ) ;
V_553 -> V_462 =
& V_551 -> V_462 ;
V_553 -> V_431 =
& V_551 -> V_431 ;
V_553 -> V_451 = & V_551 -> V_451 ;
V_553 -> V_426 = & V_551 -> V_426 ;
V_553 -> V_540 =
V_15 -> V_555 +
( V_553 -> V_462 -
V_15 -> V_554 ) ;
V_553 -> V_541 =
V_15 -> V_555 +
( V_553 -> V_431 -
V_15 -> V_554 ) ;
V_553 -> V_542 =
V_15 -> V_555 +
( ( void * ) V_553 -> V_451 -
V_15 -> V_554 ) ;
V_553 -> V_543 =
V_15 -> V_555 +
( ( void * ) V_553 -> V_426 -
V_15 -> V_554 ) ;
return 0 ;
}
static int F_182 ( struct V_8 * V_15 )
{
struct V_354 T_7 * V_355 ;
struct V_552 * V_553 ;
unsigned long V_356 ;
T_1 V_86 ;
T_6 V_557 ;
V_355 = V_15 -> V_355 ;
V_553 = & V_15 -> V_553 ;
F_183 ( ( V_32 ) V_553 -> V_540 ,
& V_355 -> V_558 ) ;
F_183 ( ( V_32 ) V_553 -> V_541 ,
& V_355 -> V_559 ) ;
F_183 ( ( V_32 ) V_553 -> V_542 ,
& V_355 -> V_560 ) ;
F_183 ( ( V_32 ) V_553 -> V_543 ,
& V_355 -> V_561 ) ;
V_557 = V_562 |
( V_563 ) << 8 |
( V_553 -> V_548 << 16 ) ;
F_153 ( V_557 , & V_355 -> V_564 ) ;
F_153 ( V_565 ,
& V_355 -> V_364 ) ;
V_356 = V_566 + V_360 ;
while ( 1 ) {
V_86 = F_136 ( & V_355 -> V_364 ) ;
if ( V_86 == V_365 )
break;
if ( F_134 ( V_360 , V_356 ) )
return - V_362 ;
F_135 ( V_567 ) ;
}
V_553 -> V_450 = V_15 -> V_568 +
V_569 +
F_133 ( & V_355 -> V_570 ) ;
V_553 -> V_427 = V_15 -> V_568 +
V_569 +
F_133 ( & V_355 -> V_571 ) ;
return 0 ;
}
static void F_184 ( struct V_8 * V_15 ,
struct V_572 * V_41 )
{
struct V_552 * V_553 ;
void * V_452 ;
T_8 V_450 ;
V_553 = & V_15 -> V_553 ;
V_450 = V_553 -> V_460 ;
V_452 = V_553 -> V_462 +
( V_450 * V_573 ) ;
memcpy ( V_452 , V_41 , sizeof( * V_41 ) ) ;
V_450 = ( V_450 + 1 ) % V_562 ;
V_553 -> V_460 = V_450 ;
F_153 ( V_450 , V_553 -> V_450 ) ;
}
static int F_185 ( struct V_8 * V_15 ,
struct V_574 * V_420 )
{
struct V_552 * V_553 ;
T_8 V_426 ;
T_8 V_427 ;
unsigned long V_356 ;
V_553 = & V_15 -> V_553 ;
V_427 = V_553 -> V_430 ;
V_356 = ( 3 * V_359 ) + V_360 ;
while ( 1 ) {
V_426 = * V_553 -> V_426 ;
if ( V_426 != V_427 )
break;
if ( F_134 ( V_360 , V_356 ) ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_60 ) ;
return - V_362 ;
}
F_186 ( 1000 , 2000 ) ;
}
memcpy ( V_420 , V_553 -> V_431 +
( V_427 * V_575 ) , sizeof( * V_420 ) ) ;
V_427 = ( V_427 + 1 ) % V_563 ;
V_553 -> V_430 = V_427 ;
F_153 ( V_427 , V_553 -> V_427 ) ;
return 0 ;
}
static void F_170 ( struct V_8 * V_15 ,
struct V_305 * V_306 , enum V_576 V_477 ,
struct V_80 * V_81 )
{
struct V_80 * V_269 ;
void * V_452 ;
T_8 V_450 ;
T_8 V_451 ;
T_2 V_52 ;
unsigned long V_36 ;
unsigned int V_577 ;
unsigned int V_578 ;
T_2 V_579 ;
struct V_580 * V_41 ;
F_102 ( & V_306 -> V_458 [ V_477 ] , V_36 ) ;
if ( V_81 )
F_108 ( & V_81 -> V_479 ,
& V_306 -> V_549 [ V_477 ] ) ;
V_450 = V_306 -> V_460 [ V_477 ] ;
F_107 (io_request, next,
&queue_group->request_list[path], request_list_entry) {
V_41 = V_81 -> V_449 ;
V_52 = F_69 ( & V_41 -> V_52 ) +
V_51 ;
V_577 =
F_187 ( V_52 ,
V_463 ) ;
V_451 = * V_306 -> V_451 [ V_477 ] ;
if ( V_577 > F_154 ( V_450 , V_451 ,
V_15 -> V_461 ) )
break;
F_29 ( V_306 -> V_455 ,
& V_41 -> V_456 ) ;
V_452 = V_306 -> V_462 [ V_477 ] +
( V_450 * V_463 ) ;
V_578 =
V_15 -> V_461 - V_450 ;
if ( V_577 <= V_578 ) {
memcpy ( V_452 , V_41 , V_52 ) ;
} else {
V_579 = V_578 *
V_463 ;
memcpy ( V_452 , V_41 , V_579 ) ;
memcpy ( V_306 -> V_462 [ V_477 ] ,
( T_1 * ) V_41 + V_579 ,
V_52 - V_579 ) ;
}
V_450 = ( V_450 + V_577 ) %
V_15 -> V_461 ;
F_103 ( & V_81 -> V_479 ) ;
}
if ( V_450 != V_306 -> V_460 [ V_477 ] ) {
V_306 -> V_460 [ V_477 ] = V_450 ;
F_153 ( V_450 , V_306 -> V_450 [ V_477 ] ) ;
}
F_104 ( & V_306 -> V_458 [ V_477 ] , V_36 ) ;
}
static void F_188 ( struct V_80 * V_81 ,
void * V_442 )
{
struct V_581 * V_582 = V_442 ;
F_189 ( V_582 ) ;
}
static int F_190 (
struct V_8 * V_15 , struct V_80 * V_81 ,
unsigned long V_583 )
{
int V_89 = 0 ;
F_191 ( V_584 ) ;
V_81 -> V_441 = F_188 ;
V_81 -> V_442 = & V_584 ;
F_170 ( V_15 ,
& V_15 -> V_453 [ V_454 ] , V_459 ,
V_81 ) ;
if ( V_583 == V_90 ) {
F_192 ( & V_584 ) ;
} else {
if ( ! F_193 ( & V_584 ,
F_194 ( V_583 ) ) ) {
F_57 ( & V_15 -> V_23 -> V_75 ,
L_61 ) ;
V_89 = - V_362 ;
}
}
return V_89 ;
}
static int F_40 ( struct V_8 * V_15 ,
struct V_580 * V_41 , unsigned int V_36 ,
struct V_373 * V_87 , unsigned long V_583 )
{
int V_89 ;
struct V_80 * V_81 ;
unsigned long V_585 ;
unsigned long V_586 ;
T_2 V_52 ;
if ( V_36 & V_587 ) {
if ( F_195 ( & V_15 -> V_588 ) )
return - V_589 ;
} else {
if ( V_583 == V_90 ) {
F_196 ( & V_15 -> V_588 ) ;
} else {
V_585 = V_360 ;
if ( F_197 ( & V_15 -> V_588 ,
F_194 ( V_583 ) ) )
return - V_362 ;
V_586 =
F_198 ( V_360 - V_585 ) ;
if ( V_586 >= V_583 )
return - V_362 ;
V_583 -= V_586 ;
}
}
V_81 = F_35 ( V_15 ) ;
F_29 ( V_81 -> V_489 ,
& ( ( (struct V_40 * ) V_41 ) -> V_429 ) ) ;
if ( V_41 -> V_48 == V_49 )
( (struct V_40 * ) V_41 ) -> V_439 =
( (struct V_40 * ) V_41 ) -> V_429 ;
V_52 = F_69 ( & V_41 -> V_52 ) +
V_51 ;
memcpy ( V_81 -> V_449 , V_41 , V_52 ) ;
V_89 = F_190 ( V_15 ,
V_81 , V_583 ) ;
if ( V_87 ) {
if ( V_81 -> V_87 )
memcpy ( V_87 , V_81 -> V_87 ,
sizeof( * V_87 ) ) ;
else
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
} else if ( V_89 == 0 && V_81 -> V_87 ) {
T_1 V_371 ;
struct V_373 * V_590 ;
V_590 = V_81 -> V_87 ;
V_371 = V_590 -> V_86 ;
if ( V_371 == V_387 &&
V_590 -> V_380 ==
V_381 )
V_371 = V_404 ;
if ( V_371 != V_404 )
V_89 = - V_424 ;
}
F_38 ( V_81 ) ;
F_199 ( & V_15 -> V_588 ) ;
return V_89 ;
}
static int F_200 (
struct V_574 * V_420 , T_1 V_591 )
{
if ( V_420 -> V_47 . V_48 != V_592 )
return - V_172 ;
if ( F_69 ( & V_420 -> V_47 . V_52 ) !=
V_593 )
return - V_172 ;
if ( V_420 -> V_594 != V_591 )
return - V_172 ;
if ( V_420 -> V_86 != V_595 )
return - V_172 ;
return 0 ;
}
static int F_201 (
struct V_8 * V_15 ,
struct V_572 * V_41 ,
struct V_574 * V_420 )
{
int V_89 ;
F_184 ( V_15 , V_41 ) ;
V_89 = F_185 ( V_15 , V_420 ) ;
if ( V_89 == 0 )
V_89 = F_200 ( V_420 ,
V_41 -> V_594 ) ;
return V_89 ;
}
static int F_202 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_572 V_41 ;
struct V_574 V_420 ;
struct V_596 * V_597 ;
struct V_598 * V_599 ;
V_597 = F_49 ( sizeof( * V_597 ) , V_95 ) ;
if ( ! V_597 )
return - V_31 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 =
V_601 ;
F_23 ( sizeof( * V_597 ) ,
& V_41 . V_386 . V_602 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
& V_41 . V_386 . V_602 . V_25 ,
V_597 , sizeof( * V_597 ) ,
V_76 ) ;
if ( V_89 )
goto V_96;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
F_24 ( V_15 -> V_23 ,
& V_41 . V_386 . V_602 . V_25 , 1 ,
V_76 ) ;
if ( V_89 )
goto V_96;
if ( V_420 . V_86 != V_595 ) {
V_89 = - V_424 ;
goto V_96;
}
V_15 -> V_603 =
F_69 ( & V_597 -> V_603 ) ;
V_15 -> V_604 =
F_69 ( & V_597 -> V_604 ) ;
V_15 -> V_605 =
F_69 ( & V_597 -> V_605 )
* 16 ;
V_15 -> V_606 =
F_69 ( & V_597 -> V_606 ) ;
V_15 -> V_607 =
F_69 ( & V_597 -> V_607 ) ;
V_15 -> V_608 =
F_69 ( & V_597 -> V_608 )
* 16 ;
V_599 =
& V_597 -> V_609 [ V_610 ] ;
V_15 -> V_611 =
F_69 (
& V_599 -> V_612 ) ;
V_15 -> V_613 =
V_599 -> V_613 ;
V_15 -> V_614 =
V_599 -> V_614 ;
V_96:
F_46 ( V_597 ) ;
return V_89 ;
}
static int F_203 ( struct V_8 * V_15 )
{
if ( V_15 -> V_605 <
V_463 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_62 ,
V_15 -> V_605 ,
V_463 ) ;
return - V_172 ;
}
if ( V_15 -> V_608 <
V_432 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_63 ,
V_15 -> V_608 ,
V_432 ) ;
return - V_172 ;
}
if ( V_15 -> V_611 <
V_463 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_64 ,
V_15 -> V_611 ,
V_463 ) ;
return - V_172 ;
}
if ( ! V_15 -> V_613 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_65 ) ;
return - V_172 ;
}
if ( V_15 -> V_614 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_66 ) ;
return - V_172 ;
}
return 0 ;
}
static int F_204 ( struct V_8 * V_15 ,
bool V_615 , T_4 V_616 )
{
struct V_572 V_41 ;
struct V_574 V_420 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
if ( V_615 )
V_41 . V_594 =
V_617 ;
else
V_41 . V_594 =
V_618 ;
F_29 ( V_616 ,
& V_41 . V_386 . V_619 . V_616 ) ;
return F_201 ( V_15 , & V_41 ,
& V_420 ) ;
}
static int F_205 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_504 * V_505 ;
struct V_572 V_41 ;
struct V_574 V_420 ;
V_505 = & V_15 -> V_505 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 = V_620 ;
F_29 ( V_505 -> V_455 ,
& V_41 . V_386 . V_621 . V_616 ) ;
F_22 ( ( V_32 ) V_505 -> V_541 ,
& V_41 . V_386 . V_621 . V_622 ) ;
F_22 ( ( V_32 ) V_505 -> V_543 ,
& V_41 . V_386 . V_621 . V_623 ) ;
F_29 ( V_511 ,
& V_41 . V_386 . V_621 . V_624 ) ;
F_29 ( V_509 / 16 ,
& V_41 . V_386 . V_621 . V_625 ) ;
V_41 . V_386 . V_621 . V_626 = V_610 ;
F_29 ( V_505 -> V_548 ,
& V_41 . V_386 . V_621 . V_548 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
if ( V_89 )
return V_89 ;
V_505 -> V_427 = V_15 -> V_568 +
V_569 +
F_26 (
& V_420 . V_386 . V_621 . V_627 ) ;
return 0 ;
}
static int F_206 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
int V_89 ;
struct V_305 * V_306 ;
struct V_572 V_41 ;
struct V_574 V_420 ;
V_39 = V_15 -> V_628 ;
V_306 = & V_15 -> V_453 [ V_39 ] ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 = V_629 ;
F_29 ( V_306 -> V_547 [ V_459 ] ,
& V_41 . V_386 . V_630 . V_616 ) ;
F_22 (
( V_32 ) V_306 -> V_540 [ V_459 ] ,
& V_41 . V_386 . V_630 . V_622 ) ;
F_22 ( ( V_32 ) V_306 -> V_542 [ V_459 ] ,
& V_41 . V_386 . V_630 . V_631 ) ;
F_29 ( V_15 -> V_461 ,
& V_41 . V_386 . V_630 . V_624 ) ;
F_29 ( V_463 / 16 ,
& V_41 . V_386 . V_630 . V_625 ) ;
V_41 . V_386 . V_630 . V_626 = V_610 ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_67 ) ;
return V_89 ;
}
V_306 -> V_450 [ V_459 ] = V_15 -> V_568 +
V_569 +
F_26 (
& V_420 . V_386 . V_630 . V_632 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 = V_629 ;
F_29 ( V_306 -> V_547 [ V_516 ] ,
& V_41 . V_386 . V_630 . V_616 ) ;
F_22 ( ( V_32 ) V_306 ->
V_540 [ V_516 ] ,
& V_41 . V_386 . V_630 . V_622 ) ;
F_22 ( ( V_32 ) V_306 -> V_542 [ V_516 ] ,
& V_41 . V_386 . V_630 . V_631 ) ;
F_29 ( V_15 -> V_461 ,
& V_41 . V_386 . V_630 . V_624 ) ;
F_29 ( V_463 / 16 ,
& V_41 . V_386 . V_630 . V_625 ) ;
V_41 . V_386 . V_630 . V_626 = V_610 ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_68 ) ;
goto V_633;
}
V_306 -> V_450 [ V_516 ] = V_15 -> V_568 +
V_569 +
F_26 (
& V_420 . V_386 . V_630 . V_632 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 = V_634 ;
F_29 ( V_306 -> V_547 [ V_516 ] ,
& V_41 . V_386 . V_635 . V_616 ) ;
F_23 ( V_636 ,
& V_41 . V_386 . V_635 . V_637 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_69 ) ;
goto V_638;
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_600 ;
F_29 ( V_593 ,
& V_41 . V_47 . V_52 ) ;
V_41 . V_594 = V_620 ;
F_29 ( V_306 -> V_455 ,
& V_41 . V_386 . V_621 . V_616 ) ;
F_22 ( ( V_32 ) V_306 -> V_541 ,
& V_41 . V_386 . V_621 . V_622 ) ;
F_22 ( ( V_32 ) V_306 -> V_543 ,
& V_41 . V_386 . V_621 . V_623 ) ;
F_29 ( V_15 -> V_443 ,
& V_41 . V_386 . V_621 . V_624 ) ;
F_29 ( V_432 / 16 ,
& V_41 . V_386 . V_621 . V_625 ) ;
V_41 . V_386 . V_621 . V_626 = V_610 ;
F_29 ( V_306 -> V_548 ,
& V_41 . V_386 . V_621 . V_548 ) ;
V_89 = F_201 ( V_15 , & V_41 ,
& V_420 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_70 ) ;
goto V_638;
}
V_306 -> V_427 = V_15 -> V_568 +
V_569 +
F_26 (
& V_420 . V_386 . V_621 . V_627 ) ;
V_15 -> V_628 ++ ;
return 0 ;
V_638:
F_204 ( V_15 , true ,
V_306 -> V_547 [ V_516 ] ) ;
V_633:
F_204 ( V_15 , true ,
V_306 -> V_547 [ V_459 ] ) ;
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
for ( V_39 = 0 ; V_39 < V_15 -> V_478 ; V_39 ++ ) {
V_89 = F_206 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_72 ,
V_39 , V_15 -> V_478 ) ;
return V_89 ;
}
}
return 0 ;
}
static int F_208 ( struct V_8 * V_15 )
{
int V_89 ;
unsigned int V_39 ;
struct V_639 * V_640 ;
struct V_641 V_41 ;
V_640 = F_49 ( V_642 ,
V_95 ) ;
if ( ! V_640 )
return - V_31 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_643 ;
F_29 ( F_30 ( struct V_641 ,
V_386 . V_644 . V_50 [ 1 ] ) -
V_51 , & V_41 . V_47 . V_52 ) ;
F_23 ( V_642 ,
& V_41 . V_386 . V_644 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
V_41 . V_386 . V_644 . V_50 ,
V_640 , V_642 ,
V_76 ) ;
if ( V_89 )
goto V_96;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
0 , NULL , V_90 ) ;
F_24 ( V_15 -> V_23 ,
V_41 . V_386 . V_644 . V_50 , 1 ,
V_76 ) ;
if ( V_89 )
goto V_96;
for ( V_39 = 0 ; V_39 < V_640 -> V_645 ; V_39 ++ )
F_29 ( V_15 -> V_505 . V_455 ,
& V_640 -> V_37 [ V_39 ] . V_455 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_646 ;
F_29 ( F_30 ( struct V_641 ,
V_386 . V_644 . V_50 [ 1 ] ) -
V_51 , & V_41 . V_47 . V_52 ) ;
F_23 ( V_642 ,
& V_41 . V_386 . V_644 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
V_41 . V_386 . V_644 . V_50 ,
V_640 , V_642 ,
V_77 ) ;
if ( V_89 )
goto V_96;
V_89 = F_40 ( V_15 , & V_41 . V_47 , 0 ,
NULL , V_90 ) ;
F_24 ( V_15 -> V_23 ,
V_41 . V_386 . V_644 . V_50 , 1 ,
V_77 ) ;
V_96:
F_46 ( V_640 ) ;
return V_89 ;
}
static void F_209 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
struct V_13 * V_75 ;
T_2 V_647 ;
struct V_80 * V_81 ;
if ( ! V_15 -> V_83 )
return;
V_75 = & V_15 -> V_23 -> V_75 ;
V_647 = V_15 -> V_647 ;
V_81 = V_15 -> V_83 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_85 ; V_39 ++ ) {
F_46 ( V_81 -> V_449 ) ;
if ( ! V_81 -> V_648 )
break;
F_210 ( V_75 , V_647 ,
V_81 -> V_648 ,
V_81 -> V_649 ) ;
V_81 ++ ;
}
F_46 ( V_15 -> V_83 ) ;
V_15 -> V_83 = NULL ;
}
static inline int F_211 ( struct V_8 * V_15 )
{
V_15 -> V_438 = F_178 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_650 ,
& V_15 -> V_651 , V_95 ) ;
if ( ! V_15 -> V_438 )
return - V_31 ;
return 0 ;
}
static int F_212 ( struct V_8 * V_15 )
{
unsigned int V_39 ;
void * V_648 ;
T_2 V_647 ;
T_3 V_649 ;
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
V_647 = V_15 -> V_647 ;
V_81 = V_15 -> V_83 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_85 ; V_39 ++ ) {
V_81 -> V_449 =
F_49 ( V_15 -> V_612 , V_95 ) ;
if ( ! V_81 -> V_449 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_74 ) ;
goto error;
}
V_648 = F_213 ( V_75 ,
V_647 , & V_649 ,
V_95 ) ;
if ( ! V_648 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_75 ) ;
goto error;
}
V_81 -> V_489 = V_39 ;
V_81 -> V_648 = V_648 ;
V_81 -> V_649 =
V_649 ;
V_81 ++ ;
}
return 0 ;
error:
F_209 ( V_15 ) ;
return - V_31 ;
}
static void F_214 ( struct V_8 * V_15 )
{
T_6 V_652 ;
T_6 V_653 ;
V_15 -> V_654 =
V_15 -> V_655 - V_656 ;
V_15 -> V_85 = V_15 -> V_655 ;
V_15 -> V_650 =
V_15 -> V_85 * V_440 ;
V_652 =
F_215 ( V_15 -> V_652 , V_657 ) ;
V_653 = V_652 / V_658 ;
V_653 ++ ;
V_653 = F_215 ( V_15 -> V_653 , V_653 ) ;
V_652 = ( V_653 - 1 ) * V_658 ;
V_15 -> V_647 =
V_653 * sizeof( struct V_24 ) ;
V_15 -> V_659 = V_653 ;
V_15 -> V_660 = V_652 / 512 ;
}
static void F_216 ( struct V_8 * V_15 )
{
int V_661 ;
int V_662 ;
int V_478 ;
T_4 V_461 ;
T_4 V_443 ;
V_662 = F_215 ( V_15 -> V_603 / 2 ,
V_15 -> V_606 - 1 ) ;
V_662 = F_215 ( V_662 , V_663 ) ;
V_661 = F_217 () ;
V_478 = F_215 ( V_661 , V_15 -> V_664 ) ;
V_478 = F_215 ( V_478 , V_662 ) ;
V_15 -> V_478 = V_478 ;
V_15 -> V_612 =
( V_15 -> V_611 /
V_463 ) *
V_463 ;
V_461 =
( V_15 -> V_612 /
V_463 ) ;
V_461 ++ ;
V_461 = F_215 ( V_461 ,
V_15 -> V_604 ) ;
V_443 = ( ( V_461 - 1 ) * 2 ) + 1 ;
V_443 = F_215 ( V_443 ,
V_15 -> V_607 ) ;
V_15 -> V_461 = V_461 ;
V_15 -> V_443 = V_443 ;
V_15 -> V_665 =
( ( V_15 -> V_612 -
V_463 ) /
sizeof( struct V_24 ) ) +
V_666 ;
}
static inline void F_218 (
struct V_24 * V_25 , struct V_667 * V_668 )
{
V_32 V_33 = ( V_32 ) F_219 ( V_668 ) ;
unsigned int V_34 = F_220 ( V_668 ) ;
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
int V_669 ;
bool V_670 ;
unsigned int V_671 ;
unsigned int V_665 ;
struct V_667 * V_668 ;
struct V_24 * V_25 ;
V_669 = F_222 ( V_4 ) ;
if ( V_669 < 0 )
return V_669 ;
V_52 = F_30 ( struct V_40 , V_50 ) -
V_51 ;
if ( V_669 == 0 )
goto V_96;
V_668 = F_223 ( V_4 ) ;
V_25 = V_41 -> V_50 ;
V_665 = V_15 -> V_665 - 1 ;
V_670 = false ;
V_671 = 0 ;
V_39 = 0 ;
while ( 1 ) {
F_218 ( V_25 , V_668 ) ;
if ( ! V_670 )
V_671 ++ ;
V_39 ++ ;
if ( V_39 == V_669 )
break;
V_25 ++ ;
if ( V_39 == V_665 ) {
F_22 (
( V_32 ) V_81 -> V_649 ,
& V_25 -> V_33 ) ;
F_23 ( ( V_669 - V_671 )
* sizeof( * V_25 ) ,
& V_25 -> V_34 ) ;
F_23 ( V_672 ,
& V_25 -> V_36 ) ;
V_670 = true ;
V_671 ++ ;
V_25 = V_81 -> V_648 ;
}
V_668 = F_224 ( V_668 ) ;
}
F_23 ( V_35 , & V_25 -> V_36 ) ;
V_41 -> V_673 = V_670 ;
V_52 += V_671 * sizeof( * V_25 ) ;
V_96:
F_29 ( V_52 , & V_41 -> V_47 . V_52 ) ;
return 0 ;
}
static int F_225 ( struct V_8 * V_15 ,
struct V_674 * V_41 , struct V_3 * V_4 ,
struct V_80 * V_81 )
{
int V_39 ;
T_4 V_52 ;
int V_669 ;
bool V_670 ;
unsigned int V_671 ;
unsigned int V_665 ;
struct V_667 * V_668 ;
struct V_24 * V_25 ;
V_669 = F_222 ( V_4 ) ;
if ( V_669 < 0 )
return V_669 ;
V_52 = F_30 ( struct V_674 , V_50 ) -
V_51 ;
V_671 = 0 ;
if ( V_669 == 0 )
goto V_96;
V_668 = F_223 ( V_4 ) ;
V_25 = V_41 -> V_50 ;
V_665 = V_15 -> V_665 - 1 ;
V_670 = false ;
V_39 = 0 ;
while ( 1 ) {
F_218 ( V_25 , V_668 ) ;
if ( ! V_670 )
V_671 ++ ;
V_39 ++ ;
if ( V_39 == V_669 )
break;
V_25 ++ ;
if ( V_39 == V_665 ) {
F_22 (
( V_32 ) V_81 -> V_649 ,
& V_25 -> V_33 ) ;
F_23 ( ( V_669 - V_671 )
* sizeof( * V_25 ) ,
& V_25 -> V_34 ) ;
F_23 ( V_672 ,
& V_25 -> V_36 ) ;
V_670 = true ;
V_671 ++ ;
V_25 = V_81 -> V_648 ;
}
V_668 = F_224 ( V_668 ) ;
}
F_23 ( V_35 , & V_25 -> V_36 ) ;
V_41 -> V_673 = V_670 ;
V_52 += V_671 * sizeof( * V_25 ) ;
V_96:
F_29 ( V_52 , & V_41 -> V_47 . V_52 ) ;
V_41 -> V_675 = V_671 ;
return 0 ;
}
static void F_226 ( struct V_80 * V_81 ,
void * V_442 )
{
struct V_3 * V_4 ;
V_4 = V_81 -> V_4 ;
F_38 ( V_81 ) ;
F_227 ( V_4 ) ;
F_3 ( V_4 ) ;
}
static int F_228 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_305 * V_306 )
{
int V_89 ;
T_2 V_334 ;
struct V_80 * V_81 ;
struct V_40 * V_41 ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_441 = F_226 ;
V_81 -> V_4 = V_4 ;
V_4 -> V_676 = ( unsigned char * ) V_81 ;
V_41 = V_81 -> V_449 ;
memset ( V_41 , 0 ,
F_30 ( struct V_40 , V_50 ) ) ;
V_41 -> V_47 . V_48 = V_49 ;
F_23 ( F_143 ( V_4 ) , & V_41 -> V_27 ) ;
V_41 -> V_54 = V_55 ;
F_29 ( V_81 -> V_489 , & V_41 -> V_429 ) ;
V_41 -> V_439 = V_41 -> V_429 ;
memcpy ( V_41 -> V_53 , V_13 -> V_17 ,
sizeof( V_41 -> V_53 ) ) ;
V_334 = F_229 ( T_2 , V_4 -> V_677 , sizeof( V_41 -> V_45 ) ) ;
memcpy ( V_41 -> V_45 , V_4 -> V_338 , V_334 ) ;
switch ( V_334 ) {
case 6 :
case 10 :
case 12 :
case 16 :
V_41 -> V_56 =
V_57 ;
break;
case 20 :
V_41 -> V_56 =
V_678 ;
break;
case 24 :
V_41 -> V_56 =
V_679 ;
break;
case 28 :
V_41 -> V_56 =
V_680 ;
break;
case 32 :
default:
V_41 -> V_56 =
V_681 ;
break;
}
switch ( V_4 -> V_682 ) {
case V_683 :
V_41 -> V_28 = V_59 ;
break;
case V_684 :
V_41 -> V_28 = V_68 ;
break;
case V_685 :
V_41 -> V_28 = V_78 ;
break;
case V_686 :
V_41 -> V_28 = V_687 ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_76 ,
V_4 -> V_682 ) ;
F_34 ( V_4 -> V_682 ) ;
break;
}
V_89 = F_221 ( V_15 , V_41 , V_4 , V_81 ) ;
if ( V_89 ) {
F_38 ( V_81 ) ;
return V_688 ;
}
F_170 ( V_15 , V_306 , V_459 , V_81 ) ;
return 0 ;
}
static void F_230 ( struct V_80 * V_81 ,
void * V_442 )
{
struct V_3 * V_4 ;
V_4 = V_81 -> V_4 ;
F_227 ( V_4 ) ;
if ( V_81 -> V_86 == - V_407 )
F_146 ( V_4 , V_689 ) ;
F_38 ( V_81 ) ;
F_3 ( V_4 ) ;
}
static inline int F_231 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_305 * V_306 )
{
return F_131 ( V_15 , V_4 , V_13 -> V_236 ,
V_4 -> V_338 , V_4 -> V_677 , V_306 , NULL ) ;
}
static int F_131 ( struct V_8 * V_15 ,
struct V_3 * V_4 , T_6 V_236 , T_1 * V_45 ,
unsigned int V_334 , struct V_305 * V_306 ,
struct V_298 * V_299 )
{
int V_89 ;
struct V_80 * V_81 ;
struct V_674 * V_41 ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_441 = F_230 ;
V_81 -> V_4 = V_4 ;
V_4 -> V_676 = ( unsigned char * ) V_81 ;
V_41 = V_81 -> V_449 ;
memset ( V_41 , 0 ,
F_30 ( struct V_40 , V_50 ) ) ;
V_41 -> V_47 . V_48 = V_690 ;
F_23 ( V_236 , & V_41 -> V_691 ) ;
F_23 ( F_143 ( V_4 ) , & V_41 -> V_27 ) ;
V_41 -> V_54 = V_55 ;
F_29 ( V_81 -> V_489 , & V_41 -> V_429 ) ;
V_41 -> V_439 = V_41 -> V_429 ;
if ( V_334 > sizeof( V_41 -> V_45 ) )
V_334 = sizeof( V_41 -> V_45 ) ;
V_41 -> V_334 = V_334 ;
memcpy ( V_41 -> V_45 , V_45 , V_334 ) ;
switch ( V_4 -> V_682 ) {
case V_683 :
V_41 -> V_28 = V_59 ;
break;
case V_684 :
V_41 -> V_28 = V_68 ;
break;
case V_685 :
V_41 -> V_28 = V_78 ;
break;
case V_686 :
V_41 -> V_28 = V_687 ;
break;
default:
F_33 ( & V_15 -> V_23 -> V_75 ,
L_76 ,
V_4 -> V_682 ) ;
F_34 ( V_4 -> V_682 ) ;
break;
}
if ( V_299 ) {
V_41 -> V_692 = true ;
F_29 ( V_299 -> V_302 ,
& V_41 -> V_302 ) ;
F_23 ( V_299 -> V_303 ,
& V_41 -> V_303 ) ;
F_23 ( V_299 -> V_304 ,
& V_41 -> V_304 ) ;
}
V_89 = F_225 ( V_15 , V_41 , V_4 , V_81 ) ;
if ( V_89 ) {
F_38 ( V_81 ) ;
return V_688 ;
}
F_170 ( V_15 , V_306 , V_516 , V_81 ) ;
return 0 ;
}
static int F_232 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
int V_89 ;
struct V_8 * V_15 ;
struct V_12 * V_13 ;
T_4 V_693 ;
struct V_305 * V_306 ;
bool V_694 ;
V_13 = V_4 -> V_13 -> V_11 ;
V_15 = F_5 ( V_10 ) ;
if ( F_8 ( V_15 ) ) {
F_146 ( V_4 , V_392 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
V_4 -> V_395 = 0 ;
V_693 = F_233 ( F_234 ( V_4 -> V_41 ) ) ;
if ( V_693 >= V_15 -> V_478 )
V_693 = 0 ;
V_306 = & V_15 -> V_453 [ V_693 ] ;
if ( F_7 ( V_13 ) ) {
V_694 = false ;
if ( V_13 -> V_242 &&
V_4 -> V_41 -> V_695 == V_696 ) {
V_89 = F_126 ( V_15 , V_13 ,
V_4 , V_306 ) ;
if ( V_89 == 0 ||
V_89 == V_688 ||
V_89 == V_387 ||
V_89 == V_697 )
V_694 = true ;
}
if ( ! V_694 )
V_89 = F_228 ( V_15 , V_13 , V_4 ,
V_306 ) ;
} else {
if ( V_13 -> V_260 )
V_89 = F_231 ( V_15 , V_13 , V_4 ,
V_306 ) ;
else
V_89 = F_228 ( V_15 , V_13 , V_4 ,
V_306 ) ;
}
return V_89 ;
}
static void F_235 ( struct V_80 * V_81 ,
void * V_442 )
{
struct V_581 * V_582 = V_442 ;
F_189 ( V_582 ) ;
}
static int F_236 ( struct V_8 * V_15 ,
struct V_12 * V_13 , struct V_581 * V_584 )
{
int V_89 ;
unsigned int V_698 = 0 ;
while ( 1 ) {
if ( F_193 ( V_584 ,
V_699 * V_359 ) ) {
V_89 = 0 ;
break;
}
F_9 ( V_15 ) ;
if ( F_8 ( V_15 ) ) {
V_89 = - V_362 ;
break;
}
V_698 += V_699 ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_77 ,
V_15 -> V_234 -> V_235 , V_13 -> V_142 ,
V_13 -> V_143 , V_13 -> V_144 , V_698 ) ;
}
return V_89 ;
}
static int F_237 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
struct V_80 * V_81 ;
F_191 ( V_584 ) ;
struct V_700 * V_41 ;
F_196 ( & V_15 -> V_701 ) ;
V_81 = F_35 ( V_15 ) ;
V_81 -> V_441 = F_235 ;
V_81 -> V_442 = & V_584 ;
V_41 = V_81 -> V_449 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_47 . V_48 = V_702 ;
F_29 ( sizeof( * V_41 ) - V_51 ,
& V_41 -> V_47 . V_52 ) ;
F_29 ( V_81 -> V_489 , & V_41 -> V_429 ) ;
memcpy ( V_41 -> V_53 , V_13 -> V_17 ,
sizeof( V_41 -> V_53 ) ) ;
V_41 -> V_703 = V_704 ;
F_170 ( V_15 ,
& V_15 -> V_453 [ V_454 ] , V_459 ,
V_81 ) ;
V_89 = F_236 ( V_15 , V_13 , & V_584 ) ;
if ( V_89 == 0 )
V_89 = V_81 -> V_86 ;
F_38 ( V_81 ) ;
F_199 ( & V_15 -> V_701 ) ;
return V_89 ;
}
static int F_238 ( struct V_8 * V_15 ,
struct V_12 * V_13 )
{
int V_89 ;
F_9 ( V_15 ) ;
if ( F_8 ( V_15 ) )
return V_705 ;
V_89 = F_237 ( V_15 , V_13 ) ;
return V_89 == 0 ? V_706 : V_705 ;
}
static int F_239 ( struct V_3 * V_4 )
{
int V_89 ;
struct V_8 * V_15 ;
struct V_12 * V_13 ;
V_15 = F_5 ( V_4 -> V_13 -> V_370 ) ;
V_13 = V_4 -> V_13 -> V_11 ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_78 ,
V_15 -> V_234 -> V_235 ,
V_13 -> V_142 , V_13 -> V_143 , V_13 -> V_144 ) ;
V_89 = F_238 ( V_15 , V_13 ) ;
F_33 ( & V_15 -> V_23 -> V_75 ,
L_79 ,
V_15 -> V_234 -> V_235 ,
V_13 -> V_142 , V_13 -> V_143 , V_13 -> V_144 ,
V_89 == V_706 ? L_80 : L_81 ) ;
return V_89 ;
}
static int F_240 ( struct V_368 * V_244 )
{
struct V_12 * V_13 ;
unsigned long V_36 ;
struct V_8 * V_15 ;
struct V_707 * V_708 ;
struct V_709 * V_710 ;
V_15 = F_5 ( V_244 -> V_370 ) ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
if ( F_241 ( V_244 ) == V_149 ) {
V_708 = V_707 ( V_244 ) ;
V_710 = F_242 ( V_708 ) ;
V_13 = F_243 ( V_15 , V_710 ) ;
if ( V_13 ) {
V_13 -> V_143 = F_244 ( V_244 ) ;
V_13 -> V_144 = V_244 -> V_144 ;
V_13 -> V_147 = true ;
}
} else {
V_13 = F_94 ( V_15 , F_241 ( V_244 ) ,
F_244 ( V_244 ) , V_244 -> V_144 ) ;
}
if ( V_13 && V_13 -> V_256 ) {
V_244 -> V_11 = V_13 ;
V_13 -> V_244 = V_244 ;
if ( V_13 -> V_192 ) {
V_13 -> V_277 = V_13 -> V_192 ;
F_109 ( V_244 ,
V_13 -> V_277 ) ;
}
}
F_104 ( & V_15 -> V_263 , V_36 ) ;
return 0 ;
}
static int F_245 ( struct V_368 * V_244 )
{
struct V_12 * V_13 ;
V_13 = V_244 -> V_11 ;
if ( ! V_13 -> V_256 )
V_244 -> V_259 = true ;
return 0 ;
}
static int F_246 ( struct V_9 * V_10 )
{
struct V_8 * V_15 = F_5 ( V_10 ) ;
return F_247 ( & V_10 -> V_711 , V_15 -> V_23 ) ;
}
static int F_248 ( struct V_8 * V_15 ,
void T_10 * V_712 )
{
struct V_23 * V_23 ;
T_6 V_713 ;
T_6 V_714 ;
T_11 V_715 ;
if ( ! V_712 )
return - V_172 ;
V_23 = V_15 -> V_23 ;
V_715 . V_716 = F_249 ( V_23 -> V_142 ) ;
V_715 . V_142 = V_23 -> V_142 -> V_717 ;
V_715 . V_718 = V_23 -> V_719 ;
V_713 = V_23 -> V_713 ;
V_714 = V_23 -> V_714 ;
V_715 . V_720 = ( ( V_714 << 16 ) & 0xffff0000 ) |
V_713 ;
if ( F_250 ( V_712 , & V_715 , sizeof( V_715 ) ) )
return - V_721 ;
return 0 ;
}
static int F_251 ( void T_10 * V_712 )
{
T_6 V_722 ;
if ( ! V_712 )
return - V_172 ;
V_722 = ( V_723 << 28 ) | ( V_724 << 24 ) |
( V_725 << 16 ) | V_726 ;
if ( F_250 ( V_712 , & V_722 , sizeof( V_722 ) ) )
return - V_721 ;
return 0 ;
}
static void F_252 ( struct V_373 * V_727 ,
struct V_728 * V_728 )
{
int V_729 ;
T_2 V_374 ;
switch ( V_727 -> V_380 ) {
case V_730 :
V_729 = V_731 ;
break;
case V_381 :
V_729 = V_732 ;
break;
case V_733 :
V_729 = V_734 ;
break;
case V_735 :
case V_736 :
case V_737 :
case V_738 :
case V_739 :
V_729 = V_740 ;
break;
case V_741 :
case V_742 :
case V_743 :
case V_744 :
case V_745 :
case V_746 :
case V_747 :
case V_748 :
case V_749 :
case V_750 :
V_729 = V_751 ;
break;
case V_752 :
V_729 = V_753 ;
break;
case V_754 :
V_729 = V_755 ;
break;
case V_756 :
V_729 = V_757 ;
break;
default:
V_729 = V_758 ;
break;
}
V_374 =
F_69 ( & V_727 -> V_374 ) ;
if ( V_374 == 0 )
V_374 =
F_69 ( & V_727 -> V_385 ) ;
if ( V_374 )
if ( V_374 > sizeof( V_727 -> V_386 ) )
V_374 = sizeof( V_727 -> V_386 ) ;
V_728 -> V_371 = V_727 -> V_86 ;
V_728 -> V_759 = V_729 ;
V_728 -> V_374 = V_374 ;
}
static int F_253 ( struct V_8 * V_15 , void T_10 * V_712 )
{
int V_89 ;
char * V_760 = NULL ;
T_4 V_52 ;
T_2 V_374 ;
T_12 V_761 ;
struct V_40 V_41 ;
struct V_373 V_727 ;
struct V_728 V_728 ;
if ( F_8 ( V_15 ) )
return - V_93 ;
if ( ! V_712 )
return - V_172 ;
if ( ! F_254 ( V_762 ) )
return - V_763 ;
if ( F_255 ( & V_761 , V_712 , sizeof( V_761 ) ) )
return - V_721 ;
if ( V_761 . V_764 < 1 &&
V_761 . V_765 . Type . V_766 != V_767 )
return - V_172 ;
if ( V_761 . V_765 . V_768 > sizeof( V_41 . V_45 ) )
return - V_172 ;
if ( V_761 . V_765 . Type . Type != V_769 )
return - V_172 ;
switch ( V_761 . V_765 . Type . V_766 ) {
case V_767 :
case V_770 :
case V_771 :
break;
default:
return - V_172 ;
}
if ( V_761 . V_764 > 0 ) {
V_760 = F_49 ( V_761 . V_764 , V_95 ) ;
if ( ! V_760 )
return - V_31 ;
if ( V_761 . V_765 . Type . V_766 & V_770 ) {
if ( F_255 ( V_760 , V_761 . V_772 ,
V_761 . V_764 ) ) {
V_89 = - V_721 ;
goto V_96;
}
} else {
memset ( V_760 , 0 , V_761 . V_764 ) ;
}
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_47 . V_48 = V_49 ;
V_52 = F_30 ( struct V_40 , V_50 ) -
V_51 ;
memcpy ( V_41 . V_53 , V_761 . V_773 . V_774 ,
sizeof( V_41 . V_53 ) ) ;
memcpy ( V_41 . V_45 , V_761 . V_765 . V_775 , V_761 . V_765 . V_768 ) ;
V_41 . V_56 = V_57 ;
switch ( V_761 . V_765 . Type . V_766 ) {
case V_767 :
V_41 . V_28 = V_78 ;
break;
case V_770 :
V_41 . V_28 = V_68 ;
break;
case V_771 :
V_41 . V_28 = V_59 ;
break;
}
V_41 . V_54 = V_55 ;
if ( V_761 . V_764 > 0 ) {
F_23 ( V_761 . V_764 , & V_41 . V_27 ) ;
V_89 = F_19 ( V_15 -> V_23 ,
& V_41 . V_50 [ 0 ] , V_760 ,
V_761 . V_764 , V_79 ) ;
if ( V_89 )
goto V_96;
V_52 += sizeof( V_41 . V_50 [ 0 ] ) ;
}
F_29 ( V_52 , & V_41 . V_47 . V_52 ) ;
V_89 = F_40 ( V_15 , & V_41 . V_47 ,
V_587 , & V_727 , V_90 ) ;
if ( V_761 . V_764 > 0 )
F_24 ( V_15 -> V_23 , V_41 . V_50 , 1 ,
V_79 ) ;
memset ( & V_761 . V_87 , 0 , sizeof( V_761 . V_87 ) ) ;
if ( V_89 == 0 ) {
F_252 ( & V_727 , & V_728 ) ;
V_761 . V_87 . V_776 = V_728 . V_371 ;
V_761 . V_87 . V_777 =
V_728 . V_759 ;
V_374 = V_728 . V_374 ;
if ( V_374 ) {
if ( V_374 >
sizeof( V_761 . V_87 . V_778 ) )
V_374 =
sizeof( V_761 . V_87 . V_778 ) ;
memcpy ( V_761 . V_87 . V_778 ,
V_727 . V_386 , V_374 ) ;
V_761 . V_87 . V_779 = V_374 ;
}
}
if ( F_250 ( V_712 , & V_761 , sizeof( V_761 ) ) ) {
V_89 = - V_721 ;
goto V_96;
}
if ( V_89 == 0 && V_761 . V_764 > 0 &&
( V_761 . V_765 . Type . V_766 & V_771 ) ) {
if ( F_250 ( V_761 . V_772 , V_760 ,
V_761 . V_764 ) ) {
V_89 = - V_721 ;
}
}
V_96:
F_46 ( V_760 ) ;
return V_89 ;
}
static int F_256 ( struct V_368 * V_244 , int V_42 , void T_10 * V_712 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_5 ( V_244 -> V_370 ) ;
switch ( V_42 ) {
case V_780 :
case V_781 :
case V_782 :
V_89 = F_87 ( V_15 ) ;
break;
case V_783 :
V_89 = F_248 ( V_15 , V_712 ) ;
break;
case V_784 :
V_89 = F_251 ( V_712 ) ;
break;
case V_785 :
V_89 = F_253 ( V_15 , V_712 ) ;
break;
default:
V_89 = - V_172 ;
break;
}
return V_89 ;
}
static T_13 F_257 ( struct V_13 * V_75 ,
struct V_786 * V_787 , char * V_26 )
{
T_13 V_788 = 0 ;
struct V_9 * V_10 ;
struct V_8 * V_15 ;
V_10 = F_258 ( V_75 ) ;
V_15 = F_5 ( V_10 ) ;
V_788 += snprintf (buffer + count, PAGE_SIZE - count,
L_82 , DRIVER_VERSION BUILD_TIMESTAMP) ;
V_788 += snprintf ( V_26 + V_788 , V_658 - V_788 ,
L_83 , V_15 -> V_789 ) ;
return V_788 ;
}
static T_13 F_259 ( struct V_13 * V_75 ,
struct V_786 * V_787 , const char * V_26 , T_2 V_788 )
{
struct V_9 * V_10 = F_258 ( V_75 ) ;
F_120 ( V_10 ) ;
return V_788 ;
}
static T_13 F_260 ( struct V_13 * V_75 ,
struct V_786 * V_787 , char * V_26 )
{
struct V_8 * V_15 ;
struct V_368 * V_244 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
V_32 V_261 ;
V_244 = F_261 ( V_75 ) ;
V_15 = F_5 ( V_244 -> V_370 ) ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
V_13 = V_244 -> V_11 ;
if ( F_7 ( V_13 ) ) {
F_104 ( & V_15 -> V_263 ,
V_36 ) ;
return - V_790 ;
}
V_261 = V_13 -> V_261 ;
F_104 ( & V_15 -> V_263 , V_36 ) ;
return snprintf ( V_26 , V_658 , L_84 , V_261 ) ;
}
static T_13 F_262 ( struct V_13 * V_75 ,
struct V_786 * V_787 , char * V_26 )
{
struct V_8 * V_15 ;
struct V_368 * V_244 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
V_244 = F_261 ( V_75 ) ;
V_15 = F_5 ( V_244 -> V_370 ) ;
F_102 ( & V_15 -> V_263 , V_36 ) ;
V_13 = V_244 -> V_11 ;
V_26 [ 0 ] = V_13 -> V_242 ? '1' : '0' ;
V_26 [ 1 ] = '\n' ;
V_26 [ 2 ] = '\0' ;
F_104 ( & V_15 -> V_263 , V_36 ) ;
return 2 ;
}
static int F_263 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_9 * V_10 ;
V_10 = F_264 ( & V_791 , sizeof( V_15 ) ) ;
if ( ! V_10 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_85 ,
V_15 -> V_792 ) ;
return - V_31 ;
}
V_10 -> V_793 = 0 ;
V_10 -> V_794 = 0 ;
V_10 -> V_795 = - 1 ;
V_10 -> V_796 = V_797 ;
V_10 -> V_798 = V_799 ;
V_10 -> V_800 = ~ 0 ;
V_10 -> V_801 = ~ 0 ;
V_10 -> V_660 = V_15 -> V_660 ;
V_10 -> V_802 = V_15 -> V_654 ;
V_10 -> V_803 = V_10 -> V_802 ;
V_10 -> V_659 = V_15 -> V_659 ;
V_10 -> V_804 = V_805 ;
V_10 -> V_512 = F_172 ( V_15 -> V_23 , 0 ) ;
V_10 -> V_806 = V_10 -> V_512 ;
V_10 -> V_807 = V_15 -> V_478 ;
V_10 -> V_11 [ 0 ] = ( unsigned long ) V_15 ;
V_89 = F_265 ( V_10 , & V_15 -> V_23 -> V_75 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_86 ,
V_15 -> V_792 ) ;
goto V_808;
}
V_89 = F_266 ( V_10 , V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_87 ,
V_15 -> V_792 ) ;
goto V_809;
}
V_15 -> V_234 = V_10 ;
return 0 ;
V_809:
F_267 ( V_10 ) ;
V_808:
F_268 ( V_10 ) ;
return V_89 ;
}
static void F_269 ( struct V_8 * V_15 )
{
struct V_9 * V_10 ;
F_270 ( V_15 ) ;
V_10 = V_15 -> V_234 ;
if ( ! V_10 )
return;
F_267 ( V_10 ) ;
F_268 ( V_10 ) ;
}
static int F_271 ( struct V_8 * V_15 )
{
int V_89 ;
T_6 V_810 ;
V_810 = ( V_811 << 5 ) |
V_812 ;
F_153 ( V_810 ,
& V_15 -> V_355 -> V_813 ) ;
V_89 = F_132 ( V_15 ) ;
if ( V_89 )
F_33 ( & V_15 -> V_23 -> V_75 ,
L_88 ) ;
return V_89 ;
}
static int F_272 ( struct V_8 * V_15 )
{
int V_89 ;
struct V_88 * V_814 ;
V_814 = F_49 ( sizeof( * V_814 ) , V_95 ) ;
if ( ! V_814 )
return - V_31 ;
V_89 = F_39 ( V_15 , V_814 ) ;
if ( V_89 )
goto V_96;
memcpy ( V_15 -> V_789 , V_814 -> V_789 ,
sizeof( V_814 -> V_789 ) ) ;
V_15 -> V_789 [ sizeof( V_814 -> V_789 ) ] = '\0' ;
snprintf ( V_15 -> V_789 +
strlen ( V_15 -> V_789 ) ,
sizeof( V_15 -> V_789 ) ,
L_89 , F_69 ( & V_814 -> V_815 ) ) ;
V_96:
F_46 ( V_814 ) ;
return V_89 ;
}
static int F_273 ( struct V_8 * V_15 )
{
if ( ! F_10 ( V_15 ) )
return - V_93 ;
if ( F_13 ( V_15 ) == V_816 ) {
F_274 ( V_15 ) ;
if ( F_271 ( V_15 ) == 0 )
F_275 ( V_15 ) ;
}
return 0 ;
}
static int F_276 ( struct V_8 * V_15 )
{
int V_89 ;
if ( V_817 ) {
V_89 = F_273 ( V_15 ) ;
if ( V_89 )
return V_89 ;
}
V_89 = F_277 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_90 ) ;
return V_89 ;
}
V_89 = F_278 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_91 ) ;
return V_89 ;
}
V_89 = F_279 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_92 ) ;
return V_89 ;
}
if ( V_15 -> V_655 > V_818 )
V_15 -> V_655 =
V_818 ;
F_214 ( V_15 ) ;
V_89 = F_211 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_93 ) ;
return V_89 ;
}
V_89 = F_280 ( V_15 ) ;
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
V_15 -> V_819 = true ;
F_15 ( V_15 , V_816 ) ;
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
if ( V_15 -> V_519 < V_15 -> V_478 ) {
V_15 -> V_664 =
V_15 -> V_519 ;
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
F_281 ( V_15 ) ;
V_89 = F_208 ( V_15 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_99 ) ;
return V_89 ;
}
F_161 ( V_15 ) ;
V_15 -> V_16 = true ;
V_89 = F_263 ( V_15 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_272 ( V_15 ) ;
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
static int F_282 ( struct V_8 * V_15 )
{
int V_89 ;
V_32 V_820 ;
V_89 = F_283 ( V_15 -> V_23 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_102 ) ;
return V_89 ;
}
if ( sizeof( T_3 ) > 4 )
V_820 = F_284 ( 64 ) ;
else
V_820 = F_284 ( 32 ) ;
V_89 = F_285 ( & V_15 -> V_23 -> V_75 , V_820 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 , L_103 ) ;
goto V_821;
}
V_89 = F_286 ( V_15 -> V_23 , V_520 ) ;
if ( V_89 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_104 ) ;
goto V_821;
}
V_15 -> V_568 = F_287 ( F_288 (
V_15 -> V_23 , 0 ) ,
sizeof( struct V_822 ) ) ;
if ( ! V_15 -> V_568 ) {
F_33 ( & V_15 -> V_23 -> V_75 ,
L_105 ) ;
V_89 = - V_31 ;
goto V_823;
}
V_15 -> V_824 = V_15 -> V_568 ;
V_15 -> V_355 = & V_15 -> V_824 -> V_355 ;
F_289 ( V_15 -> V_23 ) ;
F_290 ( V_15 -> V_23 , V_15 ) ;
return 0 ;
V_823:
F_291 ( V_15 -> V_23 ) ;
V_821:
F_292 ( V_15 -> V_23 ) ;
return V_89 ;
}
static void F_293 ( struct V_8 * V_15 )
{
F_294 ( V_15 -> V_568 ) ;
F_291 ( V_15 -> V_23 ) ;
F_292 ( V_15 -> V_23 ) ;
F_290 ( V_15 -> V_23 , NULL ) ;
}
static struct V_8 * F_295 ( int V_825 )
{
struct V_8 * V_15 ;
V_15 = F_296 ( sizeof( struct V_8 ) ,
V_95 , V_825 ) ;
if ( ! V_15 )
return NULL ;
F_297 ( & V_15 -> V_296 ) ;
F_106 ( & V_15 -> V_275 ) ;
F_180 ( & V_15 -> V_263 ) ;
F_298 ( & V_15 -> V_472 , F_157 ) ;
F_299 ( & V_15 -> V_480 , 0 ) ;
F_300 ( & V_15 -> V_21 , F_86 ) ;
F_300 ( & V_15 -> V_124 , F_54 ) ;
F_301 ( & V_15 -> V_588 ,
V_826 ) ;
F_301 ( & V_15 -> V_701 , V_827 ) ;
V_15 -> V_792 = F_36 ( & V_828 ) - 1 ;
V_15 -> V_664 = V_829 ;
return V_15 ;
}
static inline void F_302 ( struct V_8 * V_15 )
{
F_46 ( V_15 ) ;
}
static void F_303 ( struct V_8 * V_15 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_521 ; V_39 ++ ) {
F_304 ( F_172 ( V_15 -> V_23 , V_39 ) ,
& V_15 -> V_453 [ V_39 ] ) ;
}
F_305 ( V_15 -> V_23 ) ;
}
static void F_306 ( struct V_8 * V_15 )
{
F_164 ( V_15 ) ;
F_303 ( V_15 ) ;
if ( V_15 -> V_537 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_539 ,
V_15 -> V_537 ,
V_15 -> V_538 ) ;
if ( V_15 -> V_554 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_556 ,
V_15 -> V_554 ,
V_15 -> V_555 ) ;
F_209 ( V_15 ) ;
if ( V_15 -> V_438 )
F_210 ( & V_15 -> V_23 -> V_75 ,
V_15 -> V_650 ,
V_15 -> V_438 ,
V_15 -> V_651 ) ;
if ( V_15 -> V_568 )
F_293 ( V_15 ) ;
F_302 ( V_15 ) ;
}
static void F_307 ( struct V_8 * V_15 )
{
F_308 ( & V_15 -> V_21 ) ;
F_308 ( & V_15 -> V_124 ) ;
F_117 ( V_15 ) ;
F_269 ( V_15 ) ;
if ( V_15 -> V_819 ) {
F_274 ( V_15 ) ;
if ( F_271 ( V_15 ) == 0 )
F_275 ( V_15 ) ;
}
F_306 ( V_15 ) ;
}
static void F_309 ( struct V_23 * V_518 ,
const struct V_830 * V_831 )
{
char * V_832 ;
if ( V_831 -> V_833 ) {
V_832 = ( char * ) V_831 -> V_833 ;
} else {
switch ( V_831 -> V_834 ) {
case V_835 :
V_832 = V_836 ;
break;
case V_837 :
default:
V_832 = V_838 ;
break;
}
}
F_80 ( & V_518 -> V_75 , L_106 , V_832 ) ;
}
static int F_310 ( struct V_23 * V_518 , const struct V_830 * V_831 )
{
int V_89 ;
int V_839 ;
struct V_8 * V_15 ;
F_309 ( V_518 , V_831 ) ;
if ( V_840 &&
V_831 -> V_834 == V_841 &&
V_831 -> V_842 == V_841 ) {
F_57 ( & V_518 -> V_75 ,
L_107 ) ;
return - V_790 ;
}
if ( V_831 -> V_834 == V_841 || V_831 -> V_842 == V_841 )
F_57 ( & V_518 -> V_75 ,
L_108 ) ;
V_839 = F_311 ( & V_518 -> V_75 ) ;
if ( V_839 == V_843 )
F_312 ( & V_518 -> V_75 , 0 ) ;
V_15 = F_295 ( V_839 ) ;
if ( ! V_15 ) {
F_33 ( & V_518 -> V_75 ,
L_109 ) ;
return - V_31 ;
}
V_15 -> V_23 = V_518 ;
V_89 = F_282 ( V_15 ) ;
if ( V_89 )
goto error;
V_89 = F_276 ( V_15 ) ;
if ( V_89 )
goto error;
return 0 ;
error:
F_307 ( V_15 ) ;
return V_89 ;
}
static void F_313 ( struct V_23 * V_518 )
{
struct V_8 * V_15 ;
V_15 = F_314 ( V_518 ) ;
if ( ! V_15 )
return;
F_307 ( V_15 ) ;
}
static void F_315 ( struct V_23 * V_518 )
{
int V_89 ;
struct V_8 * V_15 ;
V_15 = F_314 ( V_518 ) ;
if ( ! V_15 )
goto error;
V_89 = F_44 ( V_15 ) ;
if ( V_89 == 0 )
return;
error:
F_57 ( & V_518 -> V_75 ,
L_110 ) ;
}
static int T_14 F_316 ( void )
{
int V_89 ;
F_317 ( V_844 L_111 ) ;
V_805 =
F_318 ( & V_845 ) ;
if ( ! V_805 )
return - V_790 ;
V_89 = F_319 ( & V_846 ) ;
if ( V_89 )
F_320 ( V_805 ) ;
return V_89 ;
}
static void T_15 F_321 ( void )
{
F_322 ( & V_846 ) ;
F_320 ( V_805 ) ;
}
