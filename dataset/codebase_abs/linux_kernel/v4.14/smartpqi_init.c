static char * F_1 ( T_1 V_1 )
{
if ( V_1 < F_2 ( V_2 ) )
return V_2 [ V_1 ] ;
return L_1 ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
V_4 -> V_5 ( V_4 ) ;
}
static inline bool F_5 ( T_1 * V_6 , T_1 * V_7 )
{
return memcmp ( V_6 , V_7 , 8 ) == 0 ;
}
static inline struct V_8 * F_6 ( struct V_9 * V_10 )
{
void * V_11 = F_7 ( V_10 ) ;
return * ( (struct V_8 * * ) V_11 ) ;
}
static inline bool F_8 ( struct V_12 * V_13 )
{
return ! V_13 -> V_14 ;
}
static inline bool F_9 ( T_1 * V_15 )
{
return V_15 [ 2 ] != 0 ;
}
static inline bool F_10 ( struct V_8 * V_16 )
{
return ! V_16 -> V_17 ;
}
static inline void F_11 ( struct V_8 * V_16 )
{
if ( V_16 -> V_17 )
if ( ! F_12 ( V_16 ) )
F_13 ( V_16 ) ;
}
static inline bool F_14 ( T_1 * V_15 )
{
return F_5 ( V_15 , V_18 ) ;
}
static inline enum V_19 F_15 (
struct V_8 * V_16 )
{
return F_16 ( V_16 ) ;
}
static inline void F_17 ( struct V_8 * V_16 ,
enum V_19 V_20 )
{
F_18 ( V_16 , V_20 ) ;
}
static inline void F_19 ( struct V_8 * V_16 )
{
V_16 -> V_21 = true ;
F_20 ( V_16 -> V_22 ) ;
}
static inline void F_21 ( struct V_8 * V_16 )
{
V_16 -> V_21 = false ;
F_22 ( & V_16 -> V_23 ) ;
F_23 ( V_16 ) ;
F_24 ( V_16 -> V_22 ) ;
}
static inline bool F_25 ( struct V_8 * V_16 )
{
return V_16 -> V_21 ;
}
static unsigned long F_26 ( struct V_8 * V_16 ,
unsigned long V_24 )
{
unsigned long V_25 ;
if ( ! F_25 ( V_16 ) )
return V_24 ;
F_27 ( & V_16 -> V_26 ) ;
if ( V_24 == V_27 ) {
F_28 ( V_16 -> V_23 ,
! F_25 ( V_16 ) ) ;
V_25 = V_24 ;
} else {
unsigned long V_28 ;
V_28 =
F_29 ( V_16 -> V_23 ,
! F_25 ( V_16 ) ,
F_30 ( V_24 ) ) ;
V_25 = F_31 ( V_28 ) ;
}
F_32 ( & V_16 -> V_26 ) ;
return V_25 ;
}
static inline void F_33 ( struct V_8 * V_16 )
{
F_27 ( & V_16 -> V_29 ) ;
}
static inline void F_34 ( struct V_8 * V_16 )
{
F_32 ( & V_16 -> V_29 ) ;
}
static inline void F_35 ( struct V_8 * V_16 )
{
while ( F_36 ( & V_16 -> V_29 ) >
F_36 ( & V_16 -> V_26 ) )
F_37 ( 1000 , 2000 ) ;
}
static inline bool F_38 ( struct V_12 * V_13 )
{
return V_13 -> V_30 ;
}
static inline void F_39 ( struct V_12 * V_13 )
{
V_13 -> V_31 = true ;
}
static inline void F_40 ( struct V_12 * V_13 )
{
V_13 -> V_31 = false ;
}
static inline bool F_41 ( struct V_12 * V_13 )
{
return V_13 -> V_31 ;
}
static inline void F_42 (
struct V_8 * V_16 , unsigned long V_32 )
{
if ( F_10 ( V_16 ) )
return;
F_43 ( & V_16 -> V_33 , V_32 ) ;
}
static inline void F_44 ( struct V_8 * V_16 )
{
F_42 ( V_16 , 0 ) ;
}
static inline void F_45 (
struct V_8 * V_16 )
{
F_42 ( V_16 , V_34 ) ;
}
static inline void F_46 ( struct V_8 * V_16 )
{
F_47 ( & V_16 -> V_33 ) ;
}
static inline T_2 F_48 ( struct V_8 * V_16 )
{
if ( ! V_16 -> V_35 )
return 0 ;
return F_49 ( V_16 -> V_35 ) ;
}
static int F_50 ( struct V_36 * V_36 ,
struct V_37 * V_38 , void * V_39 ,
T_3 V_40 , int V_41 )
{
T_4 V_42 ;
if ( ! V_39 || V_40 == 0 || V_41 == V_43 )
return 0 ;
V_42 = F_51 ( V_36 , V_39 , V_40 ,
V_41 ) ;
if ( F_52 ( V_36 , V_42 ) )
return - V_44 ;
F_53 ( ( V_45 ) V_42 , & V_38 -> V_46 ) ;
F_54 ( V_40 , & V_38 -> V_47 ) ;
F_54 ( V_48 , & V_38 -> V_49 ) ;
return 0 ;
}
static void F_55 ( struct V_36 * V_36 ,
struct V_37 * V_50 , int V_51 ,
int V_41 )
{
int V_52 ;
if ( V_41 == V_43 )
return;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
F_56 ( V_36 ,
( T_4 ) F_57 ( & V_50 [ V_52 ] . V_46 ) ,
F_58 ( & V_50 [ V_52 ] . V_47 ) ,
V_41 ) ;
}
static int F_59 ( struct V_8 * V_16 ,
struct V_53 * V_54 , T_1 V_55 ,
T_1 * V_15 , void * V_39 , T_3 V_40 ,
T_5 V_56 , int * V_57 )
{
T_1 * V_58 ;
int V_59 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 . V_61 = V_62 ;
F_60 ( F_61 ( struct V_53 ,
V_63 [ 1 ] ) - V_64 ,
& V_54 -> V_60 . V_65 ) ;
F_54 ( V_40 , & V_54 -> V_40 ) ;
memcpy ( V_54 -> V_66 , V_15 , sizeof( V_54 -> V_66 ) ) ;
V_54 -> V_67 = V_68 ;
V_54 -> V_69 = V_70 ;
V_58 = V_54 -> V_58 ;
switch ( V_55 ) {
case V_71 :
V_54 -> V_41 = V_72 ;
V_58 [ 0 ] = V_71 ;
if ( V_56 & V_73 ) {
V_58 [ 1 ] = 0x1 ;
V_58 [ 2 ] = ( T_1 ) V_56 ;
}
V_58 [ 4 ] = ( T_1 ) V_40 ;
break;
case V_74 :
case V_75 :
V_54 -> V_41 = V_72 ;
V_58 [ 0 ] = V_55 ;
if ( V_55 == V_75 )
V_58 [ 1 ] = V_76 ;
else
V_58 [ 1 ] = V_77 ;
F_62 ( V_40 , & V_58 [ 6 ] ) ;
break;
case V_78 :
V_54 -> V_41 = V_72 ;
V_58 [ 0 ] = V_79 ;
V_58 [ 1 ] = V_78 ;
F_62 ( V_40 , & V_58 [ 6 ] ) ;
break;
case V_80 :
V_54 -> V_41 = V_81 ;
V_58 [ 0 ] = V_82 ;
V_58 [ 6 ] = V_83 ;
F_63 ( V_40 , & V_58 [ 7 ] ) ;
break;
case V_84 :
case V_85 :
V_54 -> V_41 = V_72 ;
V_58 [ 0 ] = V_86 ;
V_58 [ 6 ] = V_55 ;
F_63 ( V_40 , & V_58 [ 7 ] ) ;
break;
case V_87 :
V_54 -> V_41 = V_81 ;
V_58 [ 0 ] = V_82 ;
V_58 [ 6 ] = V_55 ;
F_63 ( V_40 , & V_58 [ 7 ] ) ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 , L_2 ,
V_55 ) ;
break;
}
switch ( V_54 -> V_41 ) {
case V_72 :
V_59 = V_89 ;
break;
case V_81 :
V_59 = V_90 ;
break;
case V_91 :
V_59 = V_43 ;
break;
default:
V_59 = V_92 ;
break;
}
* V_57 = V_59 ;
return F_50 ( V_16 -> V_36 , & V_54 -> V_63 [ 0 ] ,
V_39 , V_40 , V_59 ) ;
}
static inline void F_65 ( struct V_93 * V_94 )
{
V_94 -> V_4 = NULL ;
V_94 -> V_95 = 0 ;
V_94 -> V_96 = NULL ;
V_94 -> V_97 = false ;
}
static struct V_93 * F_66 (
struct V_8 * V_16 )
{
struct V_93 * V_94 ;
T_5 V_52 = V_16 -> V_98 ;
while ( 1 ) {
V_94 = & V_16 -> V_99 [ V_52 ] ;
if ( F_67 ( & V_94 -> V_100 ) == 1 )
break;
F_32 ( & V_94 -> V_100 ) ;
V_52 = ( V_52 + 1 ) % V_16 -> V_101 ;
}
V_16 -> V_98 = ( V_52 + 1 ) % V_16 -> V_101 ;
F_65 ( V_94 ) ;
return V_94 ;
}
static void F_68 ( struct V_93 * V_94 )
{
F_32 ( & V_94 -> V_100 ) ;
}
static int F_69 ( struct V_8 * V_16 ,
struct V_102 * V_39 )
{
int V_103 ;
int V_57 ;
struct V_53 V_54 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_84 , V_18 , V_39 ,
sizeof( * V_39 ) , 0 , & V_57 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
return V_103 ;
}
static int F_71 ( struct V_8 * V_16 ,
T_1 * V_15 , T_5 V_56 , void * V_39 , T_3 V_40 )
{
int V_103 ;
int V_57 ;
struct V_53 V_54 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_71 , V_15 , V_39 , V_40 , V_56 ,
& V_57 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
return V_103 ;
}
static int F_72 ( struct V_8 * V_16 ,
struct V_12 * V_13 ,
struct V_104 * V_39 ,
T_3 V_40 )
{
int V_103 ;
int V_57 ;
T_5 V_105 ;
struct V_53 V_54 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_85 , V_18 , V_39 ,
V_40 , 0 , & V_57 ) ;
if ( V_103 )
return V_103 ;
V_105 = F_73 ( V_13 -> V_15 ) ;
V_54 . V_58 [ 2 ] = ( T_1 ) V_105 ;
V_54 . V_58 [ 9 ] = ( T_1 ) ( V_105 >> 8 ) ;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
return V_103 ;
}
static int F_74 ( struct V_8 * V_16 ,
enum V_106 V_107 )
{
int V_103 ;
struct V_53 V_54 ;
int V_57 ;
struct V_108 * V_109 ;
if ( F_10 ( V_16 ) )
return - V_110 ;
V_109 = F_75 ( sizeof( * V_109 ) , V_111 ) ;
if ( ! V_109 )
return - V_44 ;
V_109 -> V_107 = V_107 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_80 , V_18 , V_109 ,
sizeof( * V_109 ) , 0 , & V_57 ) ;
if ( V_103 )
goto V_112;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
V_112:
F_76 ( V_109 ) ;
return V_103 ;
}
static int F_77 ( struct V_8 * V_16 ,
void * V_39 , T_3 V_40 )
{
int V_103 ;
struct V_53 V_54 ;
int V_57 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_87 , V_18 , V_39 ,
V_40 , 0 , & V_57 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
return V_103 ;
}
static int F_78 (
struct V_8 * V_16 )
{
int V_103 ;
struct V_113 * V_39 ;
T_3 V_40 ;
V_40 = sizeof( * V_39 ) ;
V_39 = F_79 ( V_40 , V_111 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_114 [ 0 ] = '<' ;
V_39 -> V_114 [ 1 ] = 'H' ;
V_39 -> V_114 [ 2 ] = 'W' ;
V_39 -> V_114 [ 3 ] = '>' ;
V_39 -> V_115 [ 0 ] = 'D' ;
V_39 -> V_115 [ 1 ] = 'V' ;
F_60 ( sizeof( V_39 -> V_116 ) ,
& V_39 -> V_117 ) ;
strncpy ( V_39 -> V_116 , L_3 V_118 ,
sizeof( V_39 -> V_116 ) - 1 ) ;
V_39 -> V_116 [ sizeof( V_39 -> V_116 ) - 1 ] = '\0' ;
V_39 -> V_119 [ 0 ] = 'Z' ;
V_39 -> V_119 [ 1 ] = 'Z' ;
V_103 = F_77 ( V_16 , V_39 , V_40 ) ;
F_76 ( V_39 ) ;
return V_103 ;
}
static int F_80 (
struct V_8 * V_16 )
{
int V_103 ;
struct V_120 * V_39 ;
T_3 V_40 ;
T_6 V_121 ;
unsigned int V_122 ;
struct V_123 V_123 ;
V_40 = sizeof( * V_39 ) ;
V_39 = F_79 ( V_40 , V_111 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_114 [ 0 ] = '<' ;
V_39 -> V_114 [ 1 ] = 'H' ;
V_39 -> V_114 [ 2 ] = 'W' ;
V_39 -> V_114 [ 3 ] = '>' ;
V_39 -> V_124 [ 0 ] = 'T' ;
V_39 -> V_124 [ 1 ] = 'D' ;
F_60 ( sizeof( V_39 -> time ) ,
& V_39 -> V_125 ) ;
V_121 = F_81 () ;
F_82 ( V_121 , - V_126 . V_127 * 60 , & V_123 ) ;
V_122 = V_123 . V_128 + 1900 ;
V_39 -> time [ 0 ] = F_83 ( V_123 . V_129 ) ;
V_39 -> time [ 1 ] = F_83 ( V_123 . V_130 ) ;
V_39 -> time [ 2 ] = F_83 ( V_123 . V_131 ) ;
V_39 -> time [ 3 ] = 0 ;
V_39 -> time [ 4 ] = F_83 ( V_123 . V_132 + 1 ) ;
V_39 -> time [ 5 ] = F_83 ( V_123 . V_133 ) ;
V_39 -> time [ 6 ] = F_83 ( V_122 / 100 ) ;
V_39 -> time [ 7 ] = F_83 ( V_122 % 100 ) ;
V_39 -> V_134 [ 0 ] = 'D' ;
V_39 -> V_134 [ 1 ] = 'W' ;
V_39 -> V_119 [ 0 ] = 'Z' ;
V_39 -> V_119 [ 1 ] = 'Z' ;
V_103 = F_77 ( V_16 , V_39 , V_40 ) ;
F_76 ( V_39 ) ;
return V_103 ;
}
static void F_84 ( struct V_135 * V_136 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_85 ( F_86 ( V_136 ) , struct V_8 ,
V_137 ) ;
if ( F_10 ( V_16 ) )
return;
V_103 = F_80 ( V_16 ) ;
if ( V_103 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_4 ) ;
F_43 ( & V_16 -> V_137 ,
V_138 ) ;
}
static inline void F_88 (
struct V_8 * V_16 )
{
F_43 ( & V_16 -> V_137 , 0 ) ;
}
static inline void F_89 (
struct V_8 * V_16 )
{
F_47 ( & V_16 -> V_137 ) ;
}
static int F_90 ( struct V_8 * V_16 , T_1 V_55 ,
void * V_39 , T_3 V_40 )
{
int V_103 ;
int V_57 ;
struct V_53 V_54 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_55 , V_18 , V_39 , V_40 , 0 , & V_57 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
return V_103 ;
}
static int F_91 ( struct V_8 * V_16 , T_1 V_55 ,
void * * V_39 )
{
int V_103 ;
T_3 V_139 ;
T_3 V_140 ;
T_3 V_141 ;
void * V_142 = NULL ;
struct V_143 * V_143 ;
V_143 = F_79 ( sizeof( * V_143 ) , V_111 ) ;
if ( ! V_143 ) {
V_103 = - V_44 ;
goto V_112;
}
V_103 = F_90 ( V_16 , V_55 , V_143 ,
sizeof( * V_143 ) ) ;
if ( V_103 )
goto V_112;
V_139 = F_92 ( & V_143 -> V_144 ) ;
V_145:
V_140 = sizeof( struct V_143 ) + V_139 ;
V_142 = F_79 ( V_140 , V_111 ) ;
if ( ! V_142 ) {
V_103 = - V_44 ;
goto V_112;
}
if ( V_139 == 0 ) {
memcpy ( V_142 , V_143 , sizeof( * V_143 ) ) ;
goto V_112;
}
V_103 = F_90 ( V_16 , V_55 , V_142 , V_140 ) ;
if ( V_103 )
goto V_112;
V_141 = F_92 (
& ( (struct V_143 * ) V_142 ) -> V_144 ) ;
if ( V_141 > V_139 ) {
V_139 = V_141 ;
F_76 ( V_142 ) ;
goto V_145;
}
V_112:
F_76 ( V_143 ) ;
if ( V_103 ) {
F_76 ( V_142 ) ;
V_142 = NULL ;
}
* V_39 = V_142 ;
return V_103 ;
}
static inline int F_93 ( struct V_8 * V_16 ,
void * * V_39 )
{
return F_91 ( V_16 , V_75 ,
V_39 ) ;
}
static inline int F_94 ( struct V_8 * V_16 ,
void * * V_39 )
{
return F_91 ( V_16 , V_74 , V_39 ) ;
}
static int F_95 ( struct V_8 * V_16 ,
struct V_146 * * V_147 ,
struct V_148 * * V_149 )
{
int V_103 ;
T_3 V_150 ;
T_3 V_151 ;
struct V_148 * V_152 ;
struct V_148 * V_153 ;
struct V_143 V_143 ;
V_103 = F_93 ( V_16 , ( void * * ) V_147 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_5 ) ;
V_103 = F_94 ( V_16 , ( void * * ) V_149 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_6 ) ;
V_153 = * V_149 ;
if ( V_153 ) {
V_150 =
F_92 ( & V_153 -> V_60 . V_144 ) ;
} else {
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_153 =
(struct V_148 * ) & V_143 ;
V_150 = 0 ;
}
V_151 = sizeof( struct V_143 ) +
V_150 ;
V_152 = F_79 ( V_151 +
sizeof( struct V_148 ) , V_111 ) ;
if ( ! V_152 ) {
F_76 ( * V_149 ) ;
* V_149 = NULL ;
return - V_44 ;
}
memcpy ( V_152 , V_153 , V_151 ) ;
memset ( ( T_1 * ) V_152 + V_151 , 0 ,
sizeof( struct V_154 ) ) ;
F_62 ( V_150 +
sizeof( struct V_154 ) ,
& V_152 -> V_60 . V_144 ) ;
F_76 ( * V_149 ) ;
* V_149 = V_152 ;
return 0 ;
}
static inline void F_96 ( struct V_12 * V_13 ,
int V_155 , int V_156 , int V_157 )
{
V_13 -> V_155 = V_155 ;
V_13 -> V_156 = V_156 ;
V_13 -> V_157 = V_157 ;
}
static void F_97 ( struct V_12 * V_13 )
{
T_1 * V_15 ;
T_2 V_158 ;
int V_155 ;
int V_156 ;
int V_157 ;
V_15 = V_13 -> V_15 ;
V_158 = F_58 ( V_15 ) ;
if ( F_14 ( V_15 ) ) {
F_96 ( V_13 , V_159 , 0 , V_158 & 0x3fff ) ;
V_13 -> V_160 = true ;
return;
}
if ( F_8 ( V_13 ) ) {
if ( V_13 -> V_161 ) {
V_155 = V_162 ;
V_156 = ( V_158 >> 16 ) & 0x3fff ;
V_157 = V_158 & 0xff ;
} else {
V_155 = V_163 ;
V_156 = 0 ;
V_157 = V_158 & 0x3fff ;
}
F_96 ( V_13 , V_155 , V_156 , V_157 ) ;
V_13 -> V_160 = true ;
return;
}
F_96 ( V_13 , V_164 , 0 , 0 ) ;
}
static void F_98 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 V_1 ;
T_1 * V_39 ;
V_1 = V_165 ;
V_39 = F_79 ( 64 , V_111 ) ;
if ( V_39 ) {
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_166 , V_39 , 64 ) ;
if ( V_103 == 0 ) {
V_1 = V_39 [ 8 ] ;
if ( V_1 > V_167 )
V_1 = V_165 ;
}
F_76 ( V_39 ) ;
}
V_13 -> V_1 = V_1 ;
}
static int F_99 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_168 * V_168 )
{
char * V_169 ;
T_2 V_170 ;
T_2 V_171 ;
unsigned int V_172 ;
unsigned int V_173 ;
V_170 = F_58 ( & V_168 -> V_174 ) ;
if ( V_170 < F_61 ( struct V_168 , V_175 ) ) {
V_169 = L_7 ;
goto V_176;
}
if ( V_170 > sizeof( * V_168 ) ) {
V_169 = L_8 ;
goto V_176;
}
V_172 = F_100 ( & V_168 -> V_177 ) *
( F_100 ( & V_168 -> V_178 ) +
F_100 ( & V_168 -> V_179 ) ) ;
V_173 = V_172 *
F_100 ( & V_168 -> V_180 ) ;
if ( V_173 > V_181 ) {
V_169 = L_9 ;
goto V_176;
}
if ( V_13 -> V_1 == V_182 ) {
if ( F_100 ( & V_168 -> V_177 ) != 2 ) {
V_169 = L_10 ;
goto V_176;
}
} else if ( V_13 -> V_1 == V_183 ) {
if ( F_100 ( & V_168 -> V_177 ) != 3 ) {
V_169 = L_11 ;
goto V_176;
}
} else if ( ( V_13 -> V_1 == V_184 ||
V_13 -> V_1 == V_185 ) &&
F_100 ( & V_168 -> V_177 ) > 1 ) {
V_171 =
F_100 ( & V_168 -> V_186 ) *
F_100 ( & V_168 -> V_178 ) ;
if ( V_171 == 0 ) {
V_169 = L_12 ;
goto V_176;
}
}
return 0 ;
V_176:
F_87 ( & V_16 -> V_36 -> V_88 ,
L_13 ,
V_16 -> V_22 -> V_187 ,
V_13 -> V_155 , V_13 -> V_156 , V_13 -> V_157 , V_169 ) ;
return - V_188 ;
}
static int F_101 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
int V_57 ;
struct V_53 V_54 ;
struct V_168 * V_168 ;
V_168 = F_79 ( sizeof( * V_168 ) , V_111 ) ;
if ( ! V_168 )
return - V_44 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_78 , V_13 -> V_15 , V_168 ,
sizeof( * V_168 ) , 0 , & V_57 ) ;
if ( V_103 )
goto error;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
if ( V_103 )
goto error;
V_103 = F_99 ( V_16 , V_13 , V_168 ) ;
if ( V_103 )
goto error;
V_13 -> V_168 = V_168 ;
return 0 ;
error:
F_76 ( V_168 ) ;
return V_103 ;
}
static void F_102 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 * V_39 ;
T_1 V_189 ;
V_39 = F_79 ( 64 , V_111 ) ;
if ( ! V_39 )
return;
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_190 , V_39 , 64 ) ;
if ( V_103 )
goto V_112;
#define F_103 4
#define F_104 0x1
#define F_105 0x2
V_189 = V_39 [ F_103 ] ;
V_13 -> V_191 =
( V_189 & F_104 ) != 0 ;
if ( V_13 -> V_191 &&
( V_189 & F_105 ) &&
F_101 ( V_16 , V_13 ) == 0 )
V_13 -> V_192 = true ;
V_112:
F_76 ( V_39 ) ;
}
static void F_106 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_3 V_193 ;
T_1 V_194 = V_195 ;
bool V_196 = true ;
T_2 V_197 ;
struct V_198 * V_199 ;
V_199 = F_79 ( sizeof( * V_199 ) , V_111 ) ;
if ( ! V_199 )
goto V_200;
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_201 , V_199 , sizeof( * V_199 ) ) ;
if ( V_103 )
goto V_112;
V_193 = F_61 ( struct V_198 ,
V_194 ) + V_199 -> V_193 ;
if ( V_193 < sizeof( * V_199 ) )
goto V_112;
V_194 = V_199 -> V_194 ;
V_197 = F_92 ( & V_199 -> V_49 ) ;
V_196 = ( V_197 & V_202 ) != 0 ;
V_112:
F_76 ( V_199 ) ;
V_200:
V_13 -> V_194 = V_194 ;
V_13 -> V_196 = V_196 ;
}
static int F_107 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 * V_39 ;
V_39 = F_79 ( 64 , V_111 ) ;
if ( ! V_39 )
return - V_44 ;
V_103 = F_71 ( V_16 , V_13 -> V_15 , 0 , V_39 , 64 ) ;
if ( V_103 )
goto V_112;
F_108 ( & V_39 [ 8 ] , 8 ) ;
F_108 ( & V_39 [ 16 ] , 16 ) ;
V_13 -> V_203 = V_39 [ 0 ] & 0x1f ;
memcpy ( V_13 -> V_204 , & V_39 [ 8 ] , sizeof( V_13 -> V_204 ) ) ;
memcpy ( V_13 -> V_205 , & V_39 [ 16 ] , sizeof( V_13 -> V_205 ) ) ;
if ( F_8 ( V_13 ) && V_13 -> V_203 == V_206 ) {
if ( V_13 -> V_161 ) {
V_13 -> V_1 = V_165 ;
V_13 -> V_194 = V_207 ;
V_13 -> V_196 = false ;
} else {
F_98 ( V_16 , V_13 ) ;
F_102 ( V_16 , V_13 ) ;
F_106 ( V_16 , V_13 ) ;
}
}
V_112:
F_76 ( V_39 ) ;
return V_103 ;
}
static void F_109 ( struct V_8 * V_16 ,
struct V_12 * V_13 ,
struct V_104 * V_208 )
{
int V_103 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_103 = F_72 ( V_16 , V_13 ,
V_208 , sizeof( * V_208 ) ) ;
if ( V_103 ) {
V_13 -> V_209 = V_210 ;
return;
}
V_13 -> V_209 =
F_100 ( & V_208 -> V_211 ) ;
V_13 -> V_212 = V_208 -> V_212 ;
V_13 -> V_213 = V_208 -> V_214 ;
V_13 -> V_215 = V_208 -> V_216 ;
memcpy ( & V_13 -> V_217 ,
& V_208 -> V_218 ,
sizeof( V_13 -> V_217 ) ) ;
memcpy ( & V_13 -> V_219 ,
& V_208 -> V_220 ,
sizeof( V_13 -> V_219 ) ) ;
V_13 -> V_221 = V_208 -> V_222 ;
}
static void F_110 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
char * V_95 ;
static const char V_223 [] =
L_14 ;
char V_224 [ sizeof( V_223 ) + 10 ] ;
switch ( V_13 -> V_194 ) {
case V_207 :
V_95 = L_15 ;
break;
case V_225 :
V_95 = L_16 ;
break;
case V_226 :
V_95 = L_17 ;
break;
case V_227 :
V_95 = L_18 ;
break;
case V_228 :
V_95 = L_19 ;
break;
case V_229 :
V_95 = L_20 ;
break;
case V_230 :
V_95 = L_21 ;
break;
case V_231 :
V_95 = L_22 ;
break;
case V_232 :
V_95 = L_23 ;
break;
case V_233 :
V_95 = L_24 ;
break;
case V_234 :
V_95 = L_25 ;
break;
case V_235 :
V_95 = L_26 ;
break;
case V_236 :
V_95 = L_27 ;
break;
case V_237 :
V_95 = L_28 ;
break;
case V_238 :
V_95 = L_29 ;
break;
case V_239 :
V_95 = L_30 ;
break;
case V_240 :
V_95 = L_31 ;
break;
case V_241 :
V_95 = L_32 ;
break;
case V_242 :
V_95 = L_33 ;
break;
case V_243 :
V_95 = L_34 ;
break;
case V_244 :
V_95 = L_35 ;
break;
case V_245 :
V_95 = L_36 ;
break;
case V_246 :
V_95 = L_37 ;
break;
case V_247 :
V_95 = L_38 ;
break;
case V_248 :
V_95 = L_39 ;
break;
case V_249 :
V_95 = L_40 ;
break;
case V_195 :
V_95 = L_41 ;
break;
default:
snprintf ( V_224 , sizeof( V_224 ) ,
V_223 , V_13 -> V_194 ) ;
V_95 = V_224 ;
break;
}
F_111 ( & V_16 -> V_36 -> V_88 ,
L_13 ,
V_16 -> V_22 -> V_187 ,
V_13 -> V_155 , V_13 -> V_156 , V_13 -> V_157 , V_95 ) ;
}
static void F_112 ( struct V_135 * V_136 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( F_86 ( V_136 ) , struct V_8 ,
V_33 ) ;
F_113 ( V_16 ) ;
}
static int F_114 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
if ( F_8 ( V_13 ) )
V_103 = F_115 ( V_16 -> V_22 , V_13 -> V_155 ,
V_13 -> V_156 , V_13 -> V_157 ) ;
else
V_103 = F_116 ( V_16 -> V_250 , V_13 ) ;
return V_103 ;
}
static inline void F_117 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
if ( F_8 ( V_13 ) )
F_118 ( V_13 -> V_251 ) ;
else
F_119 ( V_13 ) ;
}
static struct V_12 * F_120 ( struct V_8 * V_16 ,
int V_155 , int V_156 , int V_157 )
{
struct V_12 * V_13 ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
if ( V_13 -> V_155 == V_155 && V_13 -> V_156 == V_156 &&
V_13 -> V_157 == V_157 )
return V_13 ;
return NULL ;
}
static inline bool F_122 ( struct V_12 * V_252 ,
struct V_12 * V_253 )
{
if ( V_252 -> V_14 != V_253 -> V_14 )
return false ;
if ( V_252 -> V_14 )
return V_252 -> V_254 == V_253 -> V_254 ;
return memcmp ( V_252 -> V_255 , V_253 -> V_255 ,
sizeof( V_252 -> V_255 ) ) == 0 ;
}
static enum V_256 F_123 ( struct V_8 * V_16 ,
struct V_12 * V_257 ,
struct V_12 * * V_258 )
{
struct V_12 * V_13 ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_5 ( V_257 -> V_15 ,
V_13 -> V_15 ) ) {
* V_258 = V_13 ;
if ( F_122 ( V_257 , V_13 ) ) {
if ( V_257 -> V_196 )
return V_259 ;
return V_260 ;
}
return V_259 ;
}
}
return V_261 ;
}
static void F_124 ( struct V_8 * V_16 ,
char * V_262 , struct V_12 * V_13 )
{
T_7 V_263 ;
char V_39 [ V_264 ] ;
V_263 = snprintf ( V_39 , V_264 ,
L_42 , V_16 -> V_22 -> V_187 , V_13 -> V_155 ) ;
if ( V_13 -> V_160 )
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_43 ,
V_13 -> V_156 ,
V_13 -> V_157 ) ;
else
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_44 ) ;
if ( F_8 ( V_13 ) )
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_45 ,
* ( ( T_2 * ) & V_13 -> V_15 ) ,
* ( ( T_2 * ) & V_13 -> V_15 [ 4 ] ) ) ;
else
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_46 , V_13 -> V_265 ) ;
V_263 += snprintf ( V_39 + V_263 , V_264 - V_263 ,
L_47 ,
F_125 ( V_13 -> V_203 ) ,
V_13 -> V_204 ,
V_13 -> V_205 ) ;
if ( F_8 ( V_13 ) ) {
if ( V_13 -> V_203 == V_206 )
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_48 ,
V_13 -> V_191 ? '+' : '-' ,
V_13 -> V_192 ? '+' : '-' ,
F_1 ( V_13 -> V_1 ) ) ;
} else {
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_49 , V_13 -> V_266 ? '+' : '-' ) ;
if ( V_13 -> V_203 == V_206 ||
V_13 -> V_203 == V_267 )
V_263 += snprintf ( V_39 + V_263 ,
V_264 - V_263 ,
L_50 , V_13 -> V_209 ) ;
}
F_111 ( & V_16 -> V_36 -> V_88 , L_51 , V_262 , V_39 ) ;
}
static void F_126 ( struct V_12 * V_268 ,
struct V_12 * V_269 )
{
V_268 -> V_203 = V_269 -> V_203 ;
V_268 -> V_212 = V_269 -> V_212 ;
V_268 -> V_155 = V_269 -> V_155 ;
if ( V_269 -> V_160 ) {
V_268 -> V_156 = V_269 -> V_156 ;
V_268 -> V_157 = V_269 -> V_157 ;
V_268 -> V_160 = true ;
}
V_268 -> V_14 = V_269 -> V_14 ;
V_268 -> V_161 =
V_269 -> V_161 ;
V_268 -> V_266 = V_269 -> V_266 ;
memcpy ( V_268 -> V_204 , V_269 -> V_204 ,
sizeof( V_268 -> V_204 ) ) ;
memcpy ( V_268 -> V_205 , V_269 -> V_205 ,
sizeof( V_268 -> V_205 ) ) ;
V_268 -> V_265 = V_269 -> V_265 ;
V_268 -> V_1 = V_269 -> V_1 ;
V_268 -> V_209 = V_269 -> V_209 ;
V_268 -> V_270 = V_269 -> V_270 ;
V_268 -> V_194 = V_269 -> V_194 ;
V_268 -> V_213 = V_269 -> V_213 ;
V_268 -> V_215 = V_269 -> V_215 ;
V_268 -> V_221 = V_269 -> V_221 ;
memcpy ( V_268 -> V_217 , V_269 -> V_217 ,
sizeof( V_268 -> V_217 ) ) ;
memcpy ( V_268 -> V_219 , V_269 -> V_219 ,
sizeof( V_268 -> V_219 ) ) ;
V_268 -> V_271 = 0 ;
F_76 ( V_268 -> V_168 ) ;
V_268 -> V_168 = V_269 -> V_168 ;
V_268 -> V_191 =
V_269 -> V_191 ;
V_268 -> V_192 =
V_269 -> V_192 ;
V_269 -> V_168 = NULL ;
}
static inline void F_127 ( struct V_12 * V_13 )
{
if ( V_13 ) {
F_76 ( V_13 -> V_168 ) ;
F_76 ( V_13 ) ;
}
}
static inline void F_128 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
F_130 ( & V_13 -> V_273 ) ;
F_131 ( & V_16 -> V_272 , V_49 ) ;
V_13 -> V_274 = false ;
}
static void F_132 ( struct V_8 * V_16 ,
struct V_12 * V_275 [] , unsigned int V_276 )
{
int V_103 ;
unsigned int V_52 ;
unsigned long V_49 ;
enum V_256 V_277 ;
struct V_12 * V_13 ;
struct V_12 * V_278 ;
struct V_12 * V_258 ;
F_133 ( V_279 ) ;
F_133 ( V_280 ) ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_281 = true ;
for ( V_52 = 0 ; V_52 < V_276 ; V_52 ++ ) {
V_13 = V_275 [ V_52 ] ;
V_277 = F_123 ( V_16 , V_13 ,
& V_258 ) ;
switch ( V_277 ) {
case V_260 :
V_13 -> V_269 = false ;
V_258 -> V_281 = false ;
F_126 ( V_258 , V_13 ) ;
break;
case V_261 :
V_13 -> V_269 = true ;
break;
case V_259 :
V_13 -> V_269 = true ;
break;
}
}
F_134 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_281 ) {
F_130 ( & V_13 -> V_273 ) ;
F_135 ( & V_13 -> V_282 , & V_280 ) ;
}
}
for ( V_52 = 0 ; V_52 < V_276 ; V_52 ++ ) {
V_13 = V_275 [ V_52 ] ;
if ( ! V_13 -> V_269 )
continue;
if ( V_13 -> V_196 )
continue;
F_135 ( & V_13 -> V_273 ,
& V_16 -> V_283 ) ;
F_135 ( & V_13 -> V_284 , & V_279 ) ;
V_13 -> V_274 = true ;
}
F_131 ( & V_16 -> V_272 , V_49 ) ;
F_134 (device, next, &delete_list,
delete_list_entry) {
if ( V_13 -> V_196 ) {
F_124 ( V_16 , L_52 , V_13 ) ;
F_110 ( V_16 , V_13 ) ;
} else {
F_124 ( V_16 , L_53 , V_13 ) ;
}
if ( V_13 -> V_251 )
F_117 ( V_16 , V_13 ) ;
F_130 ( & V_13 -> V_282 ) ;
F_127 ( V_13 ) ;
}
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_251 && V_13 -> V_209 !=
V_13 -> V_285 ) {
V_13 -> V_285 = V_13 -> V_209 ;
F_136 ( V_13 -> V_251 ,
V_13 -> V_285 ) ;
}
}
F_134 (device, next, &add_list, add_list_entry) {
if ( ! V_13 -> V_251 ) {
F_124 ( V_16 , L_54 , V_13 ) ;
V_103 = F_114 ( V_16 , V_13 ) ;
if ( V_103 ) {
F_87 ( & V_16 -> V_36 -> V_88 ,
L_55 ,
V_16 -> V_22 -> V_187 ,
V_13 -> V_155 , V_13 -> V_156 ,
V_13 -> V_157 ) ;
F_128 ( V_16 , V_13 ) ;
}
}
}
}
static bool F_137 ( struct V_12 * V_13 )
{
bool V_286 = false ;
switch ( V_13 -> V_203 ) {
case V_206 :
case V_267 :
case V_287 :
case V_288 :
case V_289 :
V_286 = true ;
break;
case V_290 :
if ( F_14 ( V_13 -> V_15 ) )
V_286 = true ;
break;
}
return V_286 ;
}
static inline bool F_138 ( T_1 * V_15 )
{
if ( F_139 ( V_15 ) )
return true ;
return false ;
}
static int F_140 ( struct V_8 * V_16 )
{
int V_52 ;
int V_103 ;
F_133 ( V_291 ) ;
struct V_146 * V_147 = NULL ;
struct V_148 * V_149 = NULL ;
struct V_292 * V_293 ;
struct V_154 * V_294 ;
struct V_104 * V_208 = NULL ;
T_2 V_295 ;
T_2 V_296 ;
struct V_12 * * V_275 = NULL ;
struct V_12 * V_13 ;
struct V_12 * V_278 ;
unsigned int V_276 ;
unsigned int V_297 ;
bool V_14 ;
T_1 * V_15 ;
static char * V_298 =
L_56 ;
V_103 = F_95 ( V_16 , & V_147 , & V_149 ) ;
if ( V_103 )
goto V_112;
if ( V_147 )
V_295 =
F_92 ( & V_147 -> V_60 . V_144 )
/ sizeof( V_147 -> V_299 [ 0 ] ) ;
else
V_295 = 0 ;
if ( V_149 )
V_296 =
F_92 ( & V_149 -> V_60 . V_144 )
/ sizeof( V_149 -> V_299 [ 0 ] ) ;
else
V_296 = 0 ;
if ( V_295 ) {
V_208 = F_79 ( sizeof( * V_208 ) , V_111 ) ;
if ( ! V_208 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_298 ) ;
V_103 = - V_44 ;
goto V_112;
}
}
V_276 = V_295 + V_296 ;
V_275 = F_79 ( sizeof( * V_275 ) *
V_276 , V_111 ) ;
if ( ! V_275 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 , V_298 ) ;
V_103 = - V_44 ;
goto V_112;
}
for ( V_52 = 0 ; V_52 < V_276 ; V_52 ++ ) {
V_13 = F_75 ( sizeof( * V_13 ) , V_111 ) ;
if ( ! V_13 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_298 ) ;
V_103 = - V_44 ;
goto V_112;
}
F_135 ( & V_13 -> V_300 ,
& V_291 ) ;
}
V_13 = NULL ;
V_297 = 0 ;
for ( V_52 = 0 ; V_52 < V_276 ; V_52 ++ ) {
if ( V_52 < V_295 ) {
V_14 = true ;
V_293 = & V_147 -> V_299 [ V_52 ] ;
V_294 = NULL ;
V_15 = V_293 -> V_158 ;
} else {
V_14 = false ;
V_293 = NULL ;
V_294 =
& V_149 -> V_299 [ V_52 - V_295 ] ;
V_15 = V_294 -> V_158 ;
}
if ( V_14 && F_138 ( V_15 ) )
continue;
if ( V_13 )
V_13 = F_141 ( V_13 , V_300 ) ;
else
V_13 = F_142 ( & V_291 ,
struct V_12 , V_300 ) ;
memcpy ( V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_13 -> V_14 = V_14 ;
if ( ! V_14 )
V_13 -> V_161 =
F_9 ( V_15 ) ;
V_103 = F_107 ( V_16 , V_13 ) ;
if ( V_103 == - V_44 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_298 ) ;
goto V_112;
}
if ( V_103 ) {
if ( V_13 -> V_14 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_58 ,
F_143 (
& V_293 -> V_254 ) ) ;
else
F_87 ( & V_16 -> V_36 -> V_88 ,
L_59 ,
* ( ( T_2 * ) & V_13 -> V_15 ) ,
* ( ( T_2 * ) & V_13 -> V_15 [ 4 ] ) ) ;
V_103 = 0 ;
continue;
}
if ( ! F_137 ( V_13 ) )
continue;
F_97 ( V_13 ) ;
if ( V_13 -> V_14 ) {
V_13 -> V_254 = V_293 -> V_254 ;
if ( ( V_293 -> V_301 &
V_302 ) &&
V_293 -> V_270 )
V_13 -> V_266 = true ;
} else {
memcpy ( V_13 -> V_255 , V_294 -> V_255 ,
sizeof( V_13 -> V_255 ) ) ;
}
switch ( V_13 -> V_203 ) {
case V_206 :
case V_267 :
case V_289 :
if ( V_13 -> V_14 ) {
V_13 -> V_265 =
F_143 ( & V_13 -> V_254 ) ;
if ( V_13 -> V_203 == V_206 ||
V_13 -> V_203 == V_267 ) {
V_13 -> V_270 =
V_293 -> V_270 ;
F_109 ( V_16 ,
V_13 , V_208 ) ;
}
}
break;
}
V_275 [ V_297 ++ ] = V_13 ;
}
F_132 ( V_16 , V_275 , V_297 ) ;
V_112:
F_134 (device, next, &new_device_list_head,
new_device_list_entry) {
if ( V_13 -> V_274 )
continue;
F_130 ( & V_13 -> V_300 ) ;
F_127 ( V_13 ) ;
}
F_76 ( V_275 ) ;
F_76 ( V_147 ) ;
F_76 ( V_149 ) ;
F_76 ( V_208 ) ;
return V_103 ;
}
static void F_144 ( struct V_8 * V_16 )
{
unsigned long V_49 ;
struct V_12 * V_13 ;
while ( 1 ) {
F_129 ( & V_16 -> V_272 , V_49 ) ;
V_13 = F_145 ( & V_16 -> V_283 ,
struct V_12 , V_273 ) ;
if ( V_13 )
F_130 ( & V_13 -> V_273 ) ;
F_131 ( & V_16 -> V_272 ,
V_49 ) ;
if ( ! V_13 )
break;
if ( V_13 -> V_251 )
F_117 ( V_16 , V_13 ) ;
F_127 ( V_13 ) ;
}
}
static int F_113 ( struct V_8 * V_16 )
{
int V_103 ;
if ( F_10 ( V_16 ) )
return - V_110 ;
F_146 ( & V_16 -> V_303 ) ;
V_103 = F_140 ( V_16 ) ;
if ( V_103 )
F_45 ( V_16 ) ;
F_147 ( & V_16 -> V_303 ) ;
return V_103 ;
}
static void F_148 ( struct V_9 * V_10 )
{
F_113 ( F_6 ( V_10 ) ) ;
}
static int F_149 ( struct V_9 * V_10 ,
unsigned long V_304 )
{
struct V_8 * V_16 ;
V_16 = F_7 ( V_10 ) ;
return ! F_150 ( & V_16 -> V_303 ) ;
}
static void F_151 ( struct V_8 * V_16 )
{
F_146 ( & V_16 -> V_303 ) ;
F_147 ( & V_16 -> V_303 ) ;
}
static void F_152 ( struct V_8 * V_16 )
{
F_146 ( & V_16 -> V_305 ) ;
F_147 ( & V_16 -> V_305 ) ;
}
static inline void F_153 (
struct V_306 * V_307 , struct V_168 * V_168 ,
V_45 V_308 )
{
T_2 V_309 ;
V_309 = F_58 ( & V_168 -> V_309 ) ;
if ( V_309 != 512 )
V_308 = ( V_308 * V_309 ) / 512 ;
V_307 -> V_310 =
F_100 ( & V_168 -> V_310 ) ;
V_307 -> V_311 = F_154 ( V_308 ) ;
V_307 -> V_312 = F_155 ( V_308 ) ;
}
static int F_156 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_313 * V_314 )
{
struct V_168 * V_168 ;
bool V_315 = false ;
T_2 V_316 ;
V_45 V_308 ;
V_45 V_317 ;
T_2 V_318 ;
T_2 V_319 ;
V_45 V_320 ;
V_45 V_321 ;
T_2 V_322 ;
T_2 V_323 ;
T_2 V_324 ;
T_2 V_325 ;
V_45 V_326 ;
V_45 V_327 ;
T_2 V_171 ;
V_45 V_328 ;
V_45 V_329 ;
T_2 V_330 ;
T_2 V_331 ;
T_2 V_332 ;
T_2 V_333 ;
T_5 V_178 ;
T_2 V_334 ;
T_5 V_177 ;
T_2 V_335 ;
T_5 V_186 ;
T_2 V_336 ;
T_2 V_337 ;
T_2 V_338 ;
T_2 V_339 ;
T_2 V_270 ;
V_45 V_340 ;
T_2 V_341 ;
T_1 V_58 [ 16 ] ;
T_1 V_342 ;
int V_271 ;
struct V_306 * V_343 ;
struct V_306 V_307 ;
#if V_344 == 32
V_45 V_345 ;
#endif
switch ( V_4 -> V_346 [ 0 ] ) {
case V_347 :
V_315 = true ;
case V_348 :
V_308 = ( V_45 ) ( ( ( V_4 -> V_346 [ 1 ] & 0x1f ) << 16 ) |
( V_4 -> V_346 [ 2 ] << 8 ) | V_4 -> V_346 [ 3 ] ) ;
V_318 = ( T_2 ) V_4 -> V_346 [ 4 ] ;
if ( V_318 == 0 )
V_318 = 256 ;
break;
case V_349 :
V_315 = true ;
case V_350 :
V_308 = ( V_45 ) F_92 ( & V_4 -> V_346 [ 2 ] ) ;
V_318 = ( T_2 ) F_157 ( & V_4 -> V_346 [ 7 ] ) ;
break;
case V_351 :
V_315 = true ;
case V_352 :
V_308 = ( V_45 ) F_92 ( & V_4 -> V_346 [ 2 ] ) ;
V_318 = F_92 ( & V_4 -> V_346 [ 6 ] ) ;
break;
case V_353 :
V_315 = true ;
case V_354 :
V_308 = F_143 ( & V_4 -> V_346 [ 2 ] ) ;
V_318 = F_92 ( & V_4 -> V_346 [ 10 ] ) ;
break;
default:
return V_355 ;
}
if ( V_315 && V_13 -> V_1 != V_356 )
return V_355 ;
if ( F_158 ( V_318 == 0 ) )
return V_355 ;
V_317 = V_308 + V_318 - 1 ;
V_168 = V_13 -> V_168 ;
if ( V_317 >= F_57 ( & V_168 -> V_357 ) ||
V_317 < V_308 )
return V_355 ;
V_178 = F_100 ( & V_168 -> V_178 ) ;
V_186 = F_100 ( & V_168 -> V_186 ) ;
V_177 = F_100 ( & V_168 -> V_177 ) ;
V_319 = V_178 * V_186 ;
#if V_344 == 32
V_345 = V_308 ;
F_159 ( V_345 , V_319 ) ;
V_320 = V_345 ;
V_345 = V_317 ;
F_159 ( V_345 , V_319 ) ;
V_321 = V_345 ;
V_322 = ( T_2 ) ( V_308 - ( V_320 * V_319 ) ) ;
V_323 = ( T_2 ) ( V_317 - ( V_321 * V_319 ) ) ;
V_345 = V_322 ;
F_159 ( V_345 , V_186 ) ;
V_324 = V_345 ;
V_345 = V_323 ;
F_159 ( V_345 , V_186 ) ;
V_325 = V_345 ;
#else
V_320 = V_308 / V_319 ;
V_321 = V_317 / V_319 ;
V_322 = ( T_2 ) ( V_308 - ( V_320 * V_319 ) ) ;
V_323 = ( T_2 ) ( V_317 - ( V_321 * V_319 ) ) ;
V_324 = V_322 / V_186 ;
V_325 = V_323 / V_186 ;
#endif
if ( V_320 != V_321 || V_324 != V_325 )
return V_355 ;
V_334 = V_178 +
F_100 ( & V_168 -> V_179 ) ;
V_339 = ( ( T_2 ) ( V_320 >> V_168 -> V_358 ) ) %
F_100 ( & V_168 -> V_180 ) ;
V_316 = ( V_339 * V_334 ) + V_324 ;
if ( V_13 -> V_1 == V_182 ) {
if ( V_13 -> V_271 )
V_316 += V_178 ;
V_13 -> V_271 = ! V_13 -> V_271 ;
} else if ( V_13 -> V_1 == V_183 ) {
V_271 = V_13 -> V_271 ;
if ( V_271 == 0 ) {
V_316 %= V_178 ;
} else {
do {
V_338 = V_316 / V_178 ;
if ( V_271 != V_338 ) {
if ( V_338 <
V_177 - 1 ) {
V_316 += V_178 ;
V_338 ++ ;
} else {
V_316 %= V_178 ;
V_338 = 0 ;
}
}
} while ( V_271 != V_338 );
}
V_271 =
( V_271 >= V_177 - 1 ) ?
0 : V_271 + 1 ;
F_160 ( V_271 >= V_177 ) ;
V_13 -> V_271 = V_271 ;
} else if ( ( V_13 -> V_1 == V_184 ||
V_13 -> V_1 == V_185 ) && V_177 > 1 ) {
V_171 = V_186 * V_178 ;
V_335 = V_171 * V_177 ;
#if V_344 == 32
V_345 = V_308 ;
V_336 = F_159 ( V_345 , V_335 ) ;
V_345 = V_336 ;
F_159 ( V_345 , V_171 ) ;
V_336 = V_345 ;
V_345 = V_317 ;
V_337 = F_159 ( V_345 , V_335 ) ;
V_345 = V_337 ;
F_159 ( V_345 , V_171 ) ;
V_337 = V_345 ;
#else
V_336 = ( V_308 % V_335 ) / V_171 ;
V_337 = ( V_317 % V_335 ) / V_171 ;
#endif
if ( V_336 != V_337 )
return V_355 ;
#if V_344 == 32
V_345 = V_308 ;
F_159 ( V_345 , V_335 ) ;
V_320 = V_328 = V_326 = V_345 ;
V_345 = V_317 ;
F_159 ( V_345 , V_335 ) ;
V_329 = V_327 = V_345 ;
#else
V_320 = V_328 = V_326 =
V_308 / V_335 ;
V_329 = V_327 = V_317 / V_335 ;
#endif
if ( V_328 != V_329 )
return V_355 ;
#if V_344 == 32
V_345 = V_308 ;
V_322 = F_159 ( V_345 , V_335 ) ;
V_345 = V_322 ;
V_322 = ( T_2 ) F_159 ( V_345 , V_171 ) ;
V_330 = V_322 ;
V_345 = V_317 ;
V_331 = F_159 ( V_345 , V_335 ) ;
V_345 = V_331 ;
V_331 = F_159 ( V_345 , V_171 ) ;
V_345 = V_330 ;
F_159 ( V_345 , V_186 ) ;
V_324 = V_332 = V_345 ;
V_345 = V_331 ;
F_159 ( V_345 , V_186 ) ;
V_333 = V_345 ;
#else
V_322 = V_330 =
( T_2 ) ( ( V_308 % V_335 ) %
V_171 ) ;
V_331 =
( T_2 ) ( ( V_317 % V_335 ) %
V_171 ) ;
V_324 = V_330 / V_186 ;
V_332 = V_324 ;
V_333 = V_331 / V_186 ;
#endif
if ( V_332 != V_333 )
return V_355 ;
V_339 =
( ( T_2 ) ( V_320 >> V_168 -> V_358 ) ) %
F_100 ( & V_168 -> V_180 ) ;
V_316 = ( V_336 *
( F_100 ( & V_168 -> V_180 ) *
V_334 ) ) +
( V_339 * V_334 ) + V_324 ;
}
if ( F_158 ( V_316 >= V_181 ) )
return V_355 ;
V_270 = V_168 -> V_175 [ V_316 ] . V_270 ;
V_340 = F_57 ( & V_168 -> V_359 ) +
V_320 * V_186 +
( V_322 - V_324 * V_186 ) ;
V_341 = V_318 ;
if ( V_168 -> V_360 ) {
V_340 <<= V_168 -> V_360 ;
V_341 <<= V_168 -> V_360 ;
}
if ( F_158 ( V_341 > 0xffff ) )
return V_355 ;
if ( V_340 > 0xffffffff ) {
V_58 [ 0 ] = V_315 ? V_353 : V_354 ;
V_58 [ 1 ] = 0 ;
F_161 ( V_340 , & V_58 [ 2 ] ) ;
F_62 ( V_341 , & V_58 [ 10 ] ) ;
V_58 [ 14 ] = 0 ;
V_58 [ 15 ] = 0 ;
V_342 = 16 ;
} else {
V_58 [ 0 ] = V_315 ? V_349 : V_350 ;
V_58 [ 1 ] = 0 ;
F_62 ( ( T_2 ) V_340 , & V_58 [ 2 ] ) ;
V_58 [ 6 ] = 0 ;
F_63 ( ( T_5 ) V_341 , & V_58 [ 7 ] ) ;
V_58 [ 9 ] = 0 ;
V_342 = 10 ;
}
if ( F_100 ( & V_168 -> V_49 ) &
V_361 ) {
F_153 ( & V_307 , V_168 ,
V_308 ) ;
V_343 = & V_307 ;
} else {
V_343 = NULL ;
}
return F_162 ( V_16 , V_4 , V_270 ,
V_58 , V_342 , V_314 , V_343 , true ) ;
}
static int F_163 ( struct V_8 * V_16 )
{
struct V_362 T_8 * V_363 ;
unsigned long V_364 ;
V_45 V_365 ;
T_1 V_95 ;
V_363 = V_16 -> V_363 ;
V_364 = ( V_366 * V_367 ) + V_368 ;
while ( 1 ) {
V_365 = F_164 ( & V_363 -> V_365 ) ;
if ( memcmp ( & V_365 , V_369 ,
sizeof( V_365 ) ) == 0 )
break;
if ( F_165 ( V_368 , V_364 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_60 ) ;
return - V_370 ;
}
F_166 ( V_371 ) ;
}
while ( 1 ) {
V_95 = F_167 ( & V_363 -> V_372 ) ;
if ( V_95 == V_373 )
break;
if ( F_165 ( V_368 , V_364 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_61 ) ;
return - V_370 ;
}
F_166 ( V_371 ) ;
}
while ( 1 ) {
if ( F_49 ( & V_363 -> V_374 ) ==
V_375 )
break;
if ( F_165 ( V_368 , V_364 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_62 ) ;
return - V_370 ;
}
F_166 ( V_371 ) ;
}
return 0 ;
}
static inline void F_168 ( struct V_93 * V_94 )
{
struct V_12 * V_13 ;
V_13 = V_94 -> V_4 -> V_13 -> V_11 ;
V_13 -> V_192 = false ;
V_13 -> V_266 = false ;
}
static inline void F_169 ( struct V_376 * V_251 , char * V_377 )
{
struct V_8 * V_16 ;
struct V_12 * V_13 ;
V_13 = V_251 -> V_11 ;
if ( V_13 -> V_30 )
return;
V_13 -> V_30 = true ;
F_170 ( V_251 , V_378 ) ;
V_16 = F_6 ( V_251 -> V_379 ) ;
F_44 ( V_16 ) ;
F_64 ( & V_16 -> V_36 -> V_88 , L_63 ,
V_377 , V_16 -> V_22 -> V_187 , V_13 -> V_155 ,
V_13 -> V_156 , V_13 -> V_157 ) ;
}
static void F_171 ( struct V_93 * V_94 )
{
T_1 V_380 ;
T_1 V_381 ;
struct V_3 * V_4 ;
struct V_382 * V_96 ;
T_3 V_383 ;
int V_384 ;
int V_385 ;
struct V_386 V_387 ;
V_4 = V_94 -> V_4 ;
if ( ! V_4 )
return;
V_96 = V_94 -> V_96 ;
V_380 = V_96 -> V_95 ;
V_381 = V_388 ;
switch ( V_96 -> V_389 ) {
case V_390 :
break;
case V_391 :
V_385 =
F_58 ( & V_96 -> V_392 ) ;
V_384 = F_172 ( V_4 ) - V_385 ;
F_173 ( V_4 , V_384 ) ;
if ( V_385 < V_4 -> V_393 )
V_381 = V_394 ;
break;
case V_395 :
case V_396 :
V_381 = V_397 ;
break;
case V_398 :
V_381 = V_399 ;
break;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
default:
V_381 = V_416 ;
break;
}
V_383 = F_100 ( & V_96 -> V_383 ) ;
if ( V_383 == 0 )
V_383 =
F_100 ( & V_96 -> V_417 ) ;
if ( V_383 ) {
if ( V_383 > sizeof( V_96 -> V_418 ) )
V_383 = sizeof( V_96 -> V_418 ) ;
if ( V_380 == V_419 &&
F_174 ( V_96 -> V_418 ,
V_383 , & V_387 ) &&
V_387 . V_420 == V_421 &&
V_387 . V_422 == 0x3e &&
V_387 . V_423 == 0x1 ) {
F_169 ( V_4 -> V_13 , L_64 ) ;
V_381 = V_424 ;
}
if ( V_383 > V_425 )
V_383 = V_425 ;
memcpy ( V_4 -> V_426 , V_96 -> V_418 ,
V_383 ) ;
}
V_4 -> V_427 = V_380 ;
F_175 ( V_4 , V_381 ) ;
}
static void F_176 ( struct V_93 * V_94 )
{
T_1 V_380 ;
T_1 V_381 ;
struct V_3 * V_4 ;
struct V_428 * V_96 ;
T_3 V_383 ;
int V_384 ;
int V_385 ;
bool V_30 ;
V_4 = V_94 -> V_4 ;
V_96 = V_94 -> V_96 ;
V_381 = V_388 ;
V_383 = 0 ;
V_30 = false ;
switch ( V_96 -> V_429 ) {
case V_430 :
V_380 = V_96 -> V_95 ;
break;
case V_431 :
switch ( V_96 -> V_95 ) {
case V_432 :
V_380 = V_433 ;
break;
case V_434 :
V_380 = V_435 ;
V_384 = F_58 (
& V_96 -> V_384 ) ;
F_173 ( V_4 , V_384 ) ;
V_385 = F_172 ( V_4 ) - V_384 ;
if ( V_385 < V_4 -> V_393 )
V_381 = V_394 ;
break;
case V_436 :
V_380 = V_435 ;
break;
case V_437 :
F_168 ( V_94 ) ;
V_380 = V_435 ;
V_94 -> V_95 = - V_438 ;
break;
case V_439 :
case V_440 :
if ( ! V_94 -> V_97 ) {
V_30 = true ;
F_169 ( V_4 -> V_13 , L_65 ) ;
V_381 = V_424 ;
}
V_380 = V_419 ;
break;
case V_441 :
default:
V_380 = V_419 ;
break;
}
break;
case V_442 :
case V_443 :
V_380 = V_435 ;
break;
case V_444 :
case V_445 :
default:
V_380 = V_419 ;
break;
}
if ( V_96 -> V_446 ) {
V_383 =
F_100 ( & V_96 -> V_447 ) ;
if ( V_383 ) {
if ( V_383 > sizeof( V_96 -> V_418 ) )
V_383 = sizeof( V_96 -> V_418 ) ;
if ( V_383 > V_425 )
V_383 = V_425 ;
memcpy ( V_4 -> V_426 , V_96 -> V_418 ,
V_383 ) ;
}
}
if ( V_30 && V_383 == 0 )
F_177 ( 0 , V_4 -> V_426 , V_421 ,
0x3e , 0x1 ) ;
V_4 -> V_427 = V_380 ;
F_175 ( V_4 , V_381 ) ;
}
static void F_178 ( unsigned int V_61 ,
struct V_93 * V_94 )
{
switch ( V_61 ) {
case V_448 :
F_171 ( V_94 ) ;
break;
case V_449 :
F_176 ( V_94 ) ;
break;
}
}
static int F_179 (
struct V_450 * V_451 )
{
int V_103 ;
switch ( V_451 -> V_452 ) {
case V_453 :
case V_454 :
V_103 = 0 ;
break;
default:
V_103 = - V_455 ;
break;
}
return V_103 ;
}
static unsigned int F_180 ( struct V_8 * V_16 ,
struct V_313 * V_314 )
{
unsigned int V_456 ;
T_9 V_457 ;
T_9 V_458 ;
struct V_93 * V_94 ;
struct V_459 * V_451 ;
T_5 V_460 ;
V_456 = 0 ;
V_458 = V_314 -> V_461 ;
while ( 1 ) {
V_457 = * V_314 -> V_457 ;
if ( V_457 == V_458 )
break;
V_456 ++ ;
V_451 = V_314 -> V_462 +
( V_458 * V_463 ) ;
V_460 = F_100 ( & V_451 -> V_460 ) ;
F_160 ( V_460 >= V_16 -> V_101 ) ;
V_94 = & V_16 -> V_99 [ V_460 ] ;
F_160 ( F_36 ( & V_94 -> V_100 ) == 0 ) ;
switch ( V_451 -> V_60 . V_61 ) {
case V_464 :
case V_465 :
case V_466 :
break;
case V_467 :
V_94 -> V_95 =
F_179 (
( void * ) V_451 ) ;
break;
case V_468 :
F_168 ( V_94 ) ;
V_94 -> V_95 = - V_438 ;
break;
case V_448 :
case V_449 :
V_94 -> V_96 = V_16 -> V_469 +
( F_100 ( & V_451 -> V_470 ) *
V_471 ) ;
F_178 ( V_451 -> V_60 . V_61 ,
V_94 ) ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_66 ,
V_451 -> V_60 . V_61 ) ;
break;
}
V_94 -> V_472 ( V_94 ,
V_94 -> V_473 ) ;
V_458 = ( V_458 + 1 ) % V_16 -> V_474 ;
}
if ( V_456 ) {
V_314 -> V_461 = V_458 ;
F_181 ( V_458 , V_314 -> V_458 ) ;
}
return V_456 ;
}
static inline unsigned int F_182 ( unsigned int V_475 ,
unsigned int V_476 , unsigned int V_477 )
{
unsigned int V_478 ;
if ( V_475 >= V_476 )
V_478 = V_475 - V_476 ;
else
V_478 = V_477 - V_476 + V_475 ;
return V_477 - V_478 - 1 ;
}
static void F_183 ( struct V_8 * V_16 ,
struct V_479 * V_480 , T_3 V_65 )
{
T_9 V_481 ;
T_9 V_482 ;
unsigned long V_49 ;
void * V_483 ;
struct V_313 * V_314 ;
V_314 = & V_16 -> V_484 [ V_485 ] ;
F_60 ( V_314 -> V_486 , & V_480 -> V_60 . V_487 ) ;
while ( 1 ) {
F_129 ( & V_314 -> V_488 [ V_489 ] , V_49 ) ;
V_481 = V_314 -> V_490 [ V_489 ] ;
V_482 = * V_314 -> V_482 [ V_489 ] ;
if ( F_182 ( V_481 , V_482 ,
V_16 -> V_491 ) )
break;
F_131 (
& V_314 -> V_488 [ V_489 ] , V_49 ) ;
if ( F_10 ( V_16 ) )
return;
}
V_483 = V_314 -> V_492 [ V_489 ] +
( V_481 * V_493 ) ;
memcpy ( V_483 , V_480 , V_65 ) ;
V_481 = ( V_481 + 1 ) % V_16 -> V_491 ;
V_314 -> V_490 [ V_489 ] = V_481 ;
F_181 ( V_481 , V_314 -> V_481 [ V_489 ] ) ;
F_131 ( & V_314 -> V_488 [ V_489 ] , V_49 ) ;
}
static void F_184 ( struct V_8 * V_16 ,
struct V_494 * V_495 )
{
struct V_479 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_496 ;
F_60 ( sizeof( V_54 ) - V_64 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_497 = V_495 -> V_497 ;
V_54 . V_498 = V_495 -> V_498 ;
V_54 . V_499 = V_495 -> V_499 ;
F_183 ( V_16 , & V_54 , sizeof( V_54 ) ) ;
}
static void F_185 ( struct V_135 * V_136 )
{
unsigned int V_52 ;
struct V_8 * V_16 ;
struct V_494 * V_495 ;
V_16 = F_85 ( V_136 , struct V_8 , V_500 ) ;
F_33 ( V_16 ) ;
F_26 ( V_16 , V_27 ) ;
if ( F_10 ( V_16 ) )
goto V_112;
F_45 ( V_16 ) ;
V_495 = V_16 -> V_501 ;
for ( V_52 = 0 ; V_52 < V_502 ; V_52 ++ ) {
if ( V_495 -> V_503 ) {
V_495 -> V_503 = false ;
F_184 ( V_16 , V_495 ) ;
}
V_495 ++ ;
}
V_112:
F_34 ( V_16 ) ;
}
static void F_186 ( unsigned long V_418 )
{
int V_504 ;
T_2 V_505 ;
struct V_8 * V_16 = (struct V_8 * ) V_418 ;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return;
V_504 = F_36 ( & V_16 -> V_504 ) ;
V_505 = F_48 ( V_16 ) ;
if ( V_504 == V_16 -> V_506 ) {
if ( V_505 == V_16 -> V_507 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_67 ,
V_505 ) ;
F_13 ( V_16 ) ;
return;
}
} else {
V_16 -> V_506 = V_504 ;
}
V_16 -> V_507 = V_505 ;
F_187 ( & V_16 -> V_508 ,
V_368 + V_509 ) ;
}
static void F_188 ( struct V_8 * V_16 )
{
if ( ! V_16 -> V_35 )
return;
V_16 -> V_506 =
F_36 ( & V_16 -> V_504 ) ;
V_16 -> V_507 =
F_48 ( V_16 ) ;
V_16 -> V_508 . V_510 =
V_368 + V_509 ;
V_16 -> V_508 . V_418 = ( unsigned long ) V_16 ;
V_16 -> V_508 . V_511 = F_186 ;
F_189 ( & V_16 -> V_508 ) ;
}
static inline void F_190 ( struct V_8 * V_16 )
{
F_191 ( & V_16 -> V_508 ) ;
}
static inline int F_192 ( unsigned int V_497 )
{
int V_512 ;
for ( V_512 = 0 ; V_512 < F_2 ( V_513 ) ; V_512 ++ )
if ( V_497 == V_513 [ V_512 ] )
return V_512 ;
return - 1 ;
}
static inline bool F_193 ( unsigned int V_497 )
{
return F_192 ( V_497 ) != - 1 ;
}
static unsigned int F_194 ( struct V_8 * V_16 )
{
unsigned int V_514 ;
T_9 V_457 ;
T_9 V_458 ;
struct V_515 * V_516 ;
struct V_517 * V_451 ;
struct V_494 * V_495 ;
int V_518 ;
V_516 = & V_16 -> V_516 ;
V_514 = 0 ;
V_458 = V_516 -> V_461 ;
while ( 1 ) {
V_457 = * V_516 -> V_457 ;
if ( V_457 == V_458 )
break;
V_514 ++ ;
V_451 = V_516 -> V_462 +
( V_458 * V_519 ) ;
V_518 =
F_192 ( V_451 -> V_497 ) ;
if ( V_518 >= 0 ) {
if ( V_451 -> V_520 ) {
V_495 = & V_16 -> V_501 [ V_518 ] ;
V_495 -> V_503 = true ;
V_495 -> V_497 = V_451 -> V_497 ;
V_495 -> V_498 = V_451 -> V_498 ;
V_495 -> V_499 =
V_451 -> V_499 ;
}
}
V_458 = ( V_458 + 1 ) % V_521 ;
}
if ( V_514 ) {
V_516 -> V_461 = V_458 ;
F_181 ( V_458 , V_516 -> V_458 ) ;
F_195 ( & V_16 -> V_500 ) ;
}
return V_514 ;
}
static inline void F_196 ( struct V_8 * V_16 ,
bool V_522 )
{
T_2 V_523 ;
struct V_362 T_8 * V_363 ;
volatile void T_8 * V_524 ;
V_363 = V_16 -> V_363 ;
if ( V_522 )
V_524 = & V_363 -> V_525 ;
else
V_524 = & V_363 -> V_526 ;
V_523 = F_49 ( V_524 ) ;
V_523 |= V_527 ;
F_181 ( V_523 , V_524 ) ;
}
static void F_197 ( struct V_8 * V_16 ,
enum V_528 V_529 )
{
switch ( V_16 -> V_530 ) {
case V_531 :
switch ( V_529 ) {
case V_531 :
break;
case V_532 :
F_196 ( V_16 , true ) ;
F_198 ( V_16 ) ;
break;
case V_533 :
break;
}
break;
case V_532 :
switch ( V_529 ) {
case V_531 :
F_196 ( V_16 , false ) ;
F_199 ( V_16 ) ;
break;
case V_532 :
break;
case V_533 :
F_196 ( V_16 , false ) ;
break;
}
break;
case V_533 :
switch ( V_529 ) {
case V_531 :
F_199 ( V_16 ) ;
break;
case V_532 :
F_196 ( V_16 , true ) ;
F_198 ( V_16 ) ;
break;
case V_533 :
break;
}
break;
}
V_16 -> V_530 = V_529 ;
}
static inline bool F_200 ( struct V_8 * V_16 )
{
bool V_534 ;
T_2 V_535 ;
switch ( V_16 -> V_530 ) {
case V_531 :
V_534 = true ;
break;
case V_532 :
V_535 =
F_49 ( & V_16 -> V_363 -> V_536 ) ;
if ( V_535 & V_537 )
V_534 = true ;
else
V_534 = false ;
break;
case V_533 :
default:
V_534 = false ;
break;
}
return V_534 ;
}
static T_10 F_201 ( int V_538 , void * V_418 )
{
struct V_8 * V_16 ;
struct V_313 * V_314 ;
unsigned int V_539 ;
V_314 = V_418 ;
V_16 = V_314 -> V_16 ;
if ( ! F_200 ( V_16 ) )
return V_540 ;
V_539 = F_180 ( V_16 , V_314 ) ;
if ( V_538 == V_16 -> V_541 )
V_539 += F_194 ( V_16 ) ;
if ( V_539 )
F_27 ( & V_16 -> V_504 ) ;
F_202 ( V_16 , V_314 , V_489 , NULL ) ;
F_202 ( V_16 , V_314 , V_542 , NULL ) ;
return V_543 ;
}
static int F_203 ( struct V_8 * V_16 )
{
struct V_36 * V_36 = V_16 -> V_36 ;
int V_52 ;
int V_103 ;
V_16 -> V_541 = F_204 ( V_36 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_544 ; V_52 ++ ) {
V_103 = F_205 ( F_204 ( V_36 , V_52 ) , F_201 , 0 ,
V_545 , & V_16 -> V_484 [ V_52 ] ) ;
if ( V_103 ) {
F_64 ( & V_36 -> V_88 ,
L_68 ,
F_204 ( V_36 , V_52 ) , V_103 ) ;
return V_103 ;
}
V_16 -> V_546 ++ ;
}
return 0 ;
}
static void F_206 ( struct V_8 * V_16 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ )
F_207 ( F_204 ( V_16 -> V_36 , V_52 ) ,
& V_16 -> V_484 [ V_52 ] ) ;
V_16 -> V_546 = 0 ;
}
static int F_208 ( struct V_8 * V_16 )
{
int V_547 ;
V_547 = F_209 ( V_16 -> V_36 ,
V_548 , V_16 -> V_549 ,
V_550 | V_551 ) ;
if ( V_547 < 0 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_69 ,
V_547 ) ;
return V_547 ;
}
V_16 -> V_544 = V_547 ;
V_16 -> V_530 = V_531 ;
return 0 ;
}
static void F_210 ( struct V_8 * V_16 )
{
if ( V_16 -> V_544 ) {
F_211 ( V_16 -> V_36 ) ;
V_16 -> V_544 = 0 ;
}
}
static int F_212 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
T_3 V_552 ;
T_3 V_553 ;
T_3 V_554 ;
void * V_555 ;
void * V_556 ;
void * V_557 ;
unsigned int V_558 ;
unsigned int V_559 ;
unsigned int V_560 ;
struct V_313 * V_314 ;
V_553 =
V_493 *
V_16 -> V_491 ;
V_554 =
V_463 *
V_16 -> V_474 ;
V_558 = V_16 -> V_549 * 2 ;
V_559 = V_16 -> V_549 ;
V_560 = ( V_16 -> V_549 * 3 ) + 1 ;
V_557 = NULL ;
for ( V_52 = 0 ; V_52 < V_558 ; V_52 ++ ) {
V_557 = F_213 ( V_557 ,
V_561 ) ;
V_557 += V_553 ;
}
for ( V_52 = 0 ; V_52 < V_559 ; V_52 ++ ) {
V_557 = F_213 ( V_557 ,
V_561 ) ;
V_557 += V_554 ;
}
V_557 = F_213 ( V_557 ,
V_561 ) ;
V_557 += V_521 *
V_519 ;
for ( V_52 = 0 ; V_52 < V_560 ; V_52 ++ ) {
V_557 = F_213 ( V_557 ,
V_562 ) ;
V_557 += sizeof( T_9 ) ;
}
V_552 = ( T_3 ) V_557 +
V_561 ;
V_552 += V_563 ;
V_16 -> V_564 =
F_214 ( & V_16 -> V_36 -> V_88 ,
V_552 ,
& V_16 -> V_565 , V_111 ) ;
if ( ! V_16 -> V_564 )
return - V_44 ;
V_16 -> V_566 = V_552 ;
V_555 = F_213 ( V_16 -> V_564 ,
V_561 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_314 = & V_16 -> V_484 [ V_52 ] ;
V_314 -> V_492 [ V_489 ] = V_555 ;
V_314 -> V_567 [ V_489 ] =
V_16 -> V_565 +
( V_555 - V_16 -> V_564 ) ;
V_555 += V_553 ;
V_555 = F_213 ( V_555 ,
V_561 ) ;
V_314 -> V_492 [ V_542 ] = V_555 ;
V_314 -> V_567 [ V_542 ] =
V_16 -> V_565 +
( V_555 - V_16 -> V_564 ) ;
V_555 += V_553 ;
V_555 = F_213 ( V_555 ,
V_561 ) ;
}
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_314 = & V_16 -> V_484 [ V_52 ] ;
V_314 -> V_462 = V_555 ;
V_314 -> V_568 =
V_16 -> V_565 +
( V_555 - V_16 -> V_564 ) ;
V_555 += V_554 ;
V_555 = F_213 ( V_555 ,
V_561 ) ;
}
V_16 -> V_516 . V_462 = V_555 ;
V_16 -> V_516 . V_568 =
V_16 -> V_565 +
( V_555 - V_16 -> V_564 ) ;
V_555 += V_521 *
V_519 ;
V_556 = F_213 ( V_555 ,
V_562 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_314 = & V_16 -> V_484 [ V_52 ] ;
V_314 -> V_482 [ V_489 ] = V_556 ;
V_314 -> V_569 [ V_489 ] =
V_16 -> V_565 +
( V_556 - V_16 -> V_564 ) ;
V_556 += sizeof( T_9 ) ;
V_556 = F_213 ( V_556 ,
V_562 ) ;
V_314 -> V_482 [ V_542 ] = V_556 ;
V_314 -> V_569 [ V_542 ] =
V_16 -> V_565 +
( V_556 - V_16 -> V_564 ) ;
V_556 += sizeof( T_9 ) ;
V_556 = F_213 ( V_556 ,
V_562 ) ;
V_314 -> V_457 = V_556 ;
V_314 -> V_570 =
V_16 -> V_565 +
( V_556 - V_16 -> V_564 ) ;
V_556 += sizeof( T_9 ) ;
V_556 = F_213 ( V_556 ,
V_562 ) ;
}
V_16 -> V_516 . V_457 = V_556 ;
V_16 -> V_516 . V_570 =
V_16 -> V_565 +
( V_556 - V_16 -> V_564 ) ;
return 0 ;
}
static void F_215 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
T_5 V_571 = V_572 ;
T_5 V_573 = V_572 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ )
V_16 -> V_484 [ V_52 ] . V_16 = V_16 ;
V_16 -> V_516 . V_486 = V_573 ++ ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_16 -> V_484 [ V_52 ] . V_574 [ V_489 ] = V_571 ++ ;
V_16 -> V_484 [ V_52 ] . V_574 [ V_542 ] = V_571 ++ ;
V_16 -> V_484 [ V_52 ] . V_486 = V_573 ++ ;
}
V_16 -> V_516 . V_575 = 0 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ )
V_16 -> V_484 [ V_52 ] . V_575 = V_52 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
F_216 ( & V_16 -> V_484 [ V_52 ] . V_488 [ 0 ] ) ;
F_216 ( & V_16 -> V_484 [ V_52 ] . V_488 [ 1 ] ) ;
F_217 ( & V_16 -> V_484 [ V_52 ] . V_576 [ 0 ] ) ;
F_217 ( & V_16 -> V_484 [ V_52 ] . V_576 [ 1 ] ) ;
}
}
static int F_218 ( struct V_8 * V_16 )
{
T_3 V_552 ;
struct V_577 * V_578 ;
struct V_579 * V_580 ;
V_552 = sizeof( struct V_577 ) +
V_561 ;
V_16 -> V_581 =
F_214 ( & V_16 -> V_36 -> V_88 ,
V_552 ,
& V_16 -> V_582 ,
V_111 ) ;
if ( ! V_16 -> V_581 )
return - V_44 ;
V_16 -> V_583 = V_552 ;
V_580 = & V_16 -> V_580 ;
V_578 = F_213 ( V_16 -> V_581 ,
V_561 ) ;
V_580 -> V_492 =
& V_578 -> V_492 ;
V_580 -> V_462 =
& V_578 -> V_462 ;
V_580 -> V_482 = & V_578 -> V_482 ;
V_580 -> V_457 = & V_578 -> V_457 ;
V_580 -> V_567 =
V_16 -> V_582 +
( V_580 -> V_492 -
V_16 -> V_581 ) ;
V_580 -> V_568 =
V_16 -> V_582 +
( V_580 -> V_462 -
V_16 -> V_581 ) ;
V_580 -> V_569 =
V_16 -> V_582 +
( ( void * ) V_580 -> V_482 -
V_16 -> V_581 ) ;
V_580 -> V_570 =
V_16 -> V_582 +
( ( void * ) V_580 -> V_457 -
V_16 -> V_581 ) ;
return 0 ;
}
static int F_219 ( struct V_8 * V_16 )
{
struct V_362 T_8 * V_363 ;
struct V_579 * V_580 ;
unsigned long V_364 ;
T_1 V_95 ;
T_2 V_584 ;
V_363 = V_16 -> V_363 ;
V_580 = & V_16 -> V_580 ;
F_220 ( ( V_45 ) V_580 -> V_567 ,
& V_363 -> V_585 ) ;
F_220 ( ( V_45 ) V_580 -> V_568 ,
& V_363 -> V_586 ) ;
F_220 ( ( V_45 ) V_580 -> V_569 ,
& V_363 -> V_587 ) ;
F_220 ( ( V_45 ) V_580 -> V_570 ,
& V_363 -> V_588 ) ;
V_584 = V_589 |
( V_590 ) << 8 |
( V_580 -> V_575 << 16 ) ;
F_181 ( V_584 , & V_363 -> V_591 ) ;
F_181 ( V_592 ,
& V_363 -> V_372 ) ;
V_364 = V_593 + V_368 ;
while ( 1 ) {
V_95 = F_167 ( & V_363 -> V_372 ) ;
if ( V_95 == V_373 )
break;
if ( F_165 ( V_368 , V_364 ) )
return - V_370 ;
F_166 ( V_594 ) ;
}
V_580 -> V_481 = V_16 -> V_595 +
V_596 +
F_164 ( & V_363 -> V_597 ) ;
V_580 -> V_458 = V_16 -> V_595 +
V_596 +
F_164 ( & V_363 -> V_598 ) ;
return 0 ;
}
static void F_221 ( struct V_8 * V_16 ,
struct V_599 * V_54 )
{
struct V_579 * V_580 ;
void * V_483 ;
T_9 V_481 ;
V_580 = & V_16 -> V_580 ;
V_481 = V_580 -> V_490 ;
V_483 = V_580 -> V_492 +
( V_481 * V_600 ) ;
memcpy ( V_483 , V_54 , sizeof( * V_54 ) ) ;
V_481 = ( V_481 + 1 ) % V_589 ;
V_580 -> V_490 = V_481 ;
F_181 ( V_481 , V_580 -> V_481 ) ;
}
static int F_222 ( struct V_8 * V_16 ,
struct V_601 * V_451 )
{
struct V_579 * V_580 ;
T_9 V_457 ;
T_9 V_458 ;
unsigned long V_364 ;
V_580 = & V_16 -> V_580 ;
V_458 = V_580 -> V_461 ;
V_364 = ( V_602 * V_367 ) + V_368 ;
while ( 1 ) {
V_457 = * V_580 -> V_457 ;
if ( V_457 != V_458 )
break;
if ( F_165 ( V_368 , V_364 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_70 ) ;
return - V_370 ;
}
if ( ! F_12 ( V_16 ) )
return - V_110 ;
F_37 ( 1000 , 2000 ) ;
}
memcpy ( V_451 , V_580 -> V_462 +
( V_458 * V_603 ) , sizeof( * V_451 ) ) ;
V_458 = ( V_458 + 1 ) % V_590 ;
V_580 -> V_461 = V_458 ;
F_181 ( V_458 , V_580 -> V_458 ) ;
return 0 ;
}
static void F_202 ( struct V_8 * V_16 ,
struct V_313 * V_314 , enum V_604 V_377 ,
struct V_93 * V_94 )
{
struct V_93 * V_278 ;
void * V_483 ;
T_9 V_481 ;
T_9 V_482 ;
T_3 V_65 ;
unsigned long V_49 ;
unsigned int V_605 ;
unsigned int V_606 ;
T_3 V_607 ;
struct V_608 * V_54 ;
F_129 ( & V_314 -> V_488 [ V_377 ] , V_49 ) ;
if ( V_94 ) {
V_94 -> V_314 = V_314 ;
F_135 ( & V_94 -> V_609 ,
& V_314 -> V_576 [ V_377 ] ) ;
}
V_481 = V_314 -> V_490 [ V_377 ] ;
F_134 (io_request, next,
&queue_group->request_list[path], request_list_entry) {
V_54 = V_94 -> V_480 ;
V_65 = F_100 ( & V_54 -> V_65 ) +
V_64 ;
V_605 =
F_223 ( V_65 ,
V_493 ) ;
V_482 = * V_314 -> V_482 [ V_377 ] ;
if ( V_605 > F_182 ( V_481 , V_482 ,
V_16 -> V_491 ) )
break;
F_60 ( V_314 -> V_486 ,
& V_54 -> V_487 ) ;
V_483 = V_314 -> V_492 [ V_377 ] +
( V_481 * V_493 ) ;
V_606 =
V_16 -> V_491 - V_481 ;
if ( V_605 <= V_606 ) {
memcpy ( V_483 , V_54 , V_65 ) ;
} else {
V_607 = V_606 *
V_493 ;
memcpy ( V_483 , V_54 , V_607 ) ;
memcpy ( V_314 -> V_492 [ V_377 ] ,
( T_1 * ) V_54 + V_607 ,
V_65 - V_607 ) ;
}
V_481 = ( V_481 + V_605 ) %
V_16 -> V_491 ;
F_130 ( & V_94 -> V_609 ) ;
}
if ( V_481 != V_314 -> V_490 [ V_377 ] ) {
V_314 -> V_490 [ V_377 ] = V_481 ;
F_181 ( V_481 , V_314 -> V_481 [ V_377 ] ) ;
}
F_131 ( & V_314 -> V_488 [ V_377 ] , V_49 ) ;
}
static int F_224 ( struct V_8 * V_16 ,
struct V_610 * V_611 )
{
int V_103 ;
while ( 1 ) {
if ( F_225 ( V_611 ,
V_612 * V_367 ) ) {
V_103 = 0 ;
break;
}
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = - V_110 ;
break;
}
}
return V_103 ;
}
static void F_226 ( struct V_93 * V_94 ,
void * V_473 )
{
struct V_610 * V_613 = V_473 ;
F_227 ( V_613 ) ;
}
static int F_228 (
struct V_8 * V_16 , struct V_93 * V_94 ,
unsigned long V_24 )
{
int V_103 = 0 ;
F_229 ( V_611 ) ;
V_94 -> V_472 = F_226 ;
V_94 -> V_473 = & V_611 ;
F_202 ( V_16 ,
& V_16 -> V_484 [ V_485 ] , V_489 ,
V_94 ) ;
if ( V_24 == V_27 ) {
F_224 ( V_16 , & V_611 ) ;
} else {
if ( ! F_225 ( & V_611 ,
F_30 ( V_24 ) ) ) {
F_87 ( & V_16 -> V_36 -> V_88 ,
L_71 ) ;
V_103 = - V_370 ;
}
}
return V_103 ;
}
static int F_70 ( struct V_8 * V_16 ,
struct V_608 * V_54 , unsigned int V_49 ,
struct V_382 * V_96 , unsigned long V_24 )
{
int V_103 ;
struct V_93 * V_94 ;
unsigned long V_614 ;
unsigned long V_615 ;
T_3 V_65 ;
if ( V_49 & V_616 ) {
if ( F_230 ( & V_16 -> V_617 ) )
return - V_618 ;
} else {
if ( V_24 == V_27 ) {
F_231 ( & V_16 -> V_617 ) ;
} else {
V_614 = V_368 ;
if ( F_232 ( & V_16 -> V_617 ,
F_30 ( V_24 ) ) )
return - V_370 ;
V_615 =
F_31 ( V_368 - V_614 ) ;
if ( V_615 >= V_24 )
return - V_370 ;
V_24 -= V_615 ;
}
}
F_33 ( V_16 ) ;
V_24 = F_26 ( V_16 , V_24 ) ;
if ( V_24 == 0 ) {
V_103 = - V_370 ;
goto V_112;
}
if ( F_10 ( V_16 ) ) {
V_103 = - V_110 ;
goto V_112;
}
V_94 = F_66 ( V_16 ) ;
F_60 ( V_94 -> V_512 ,
& ( ( (struct V_53 * ) V_54 ) -> V_460 ) ) ;
if ( V_54 -> V_61 == V_62 )
( (struct V_53 * ) V_54 ) -> V_470 =
( (struct V_53 * ) V_54 ) -> V_460 ;
V_65 = F_100 ( & V_54 -> V_65 ) +
V_64 ;
memcpy ( V_94 -> V_480 , V_54 , V_65 ) ;
V_103 = F_228 ( V_16 ,
V_94 , V_24 ) ;
if ( V_96 ) {
if ( V_94 -> V_96 )
memcpy ( V_96 , V_94 -> V_96 ,
sizeof( * V_96 ) ) ;
else
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
} else if ( V_103 == 0 && V_94 -> V_96 ) {
T_1 V_380 ;
struct V_382 * V_619 ;
V_619 = V_94 -> V_96 ;
V_380 = V_619 -> V_95 ;
if ( V_380 == V_419 &&
V_619 -> V_389 ==
V_391 )
V_380 = V_435 ;
if ( V_380 != V_435 )
V_103 = - V_455 ;
}
F_68 ( V_94 ) ;
V_112:
F_34 ( V_16 ) ;
F_233 ( & V_16 -> V_617 ) ;
return V_103 ;
}
static int F_234 (
struct V_601 * V_451 , T_1 V_620 )
{
if ( V_451 -> V_60 . V_61 != V_621 )
return - V_188 ;
if ( F_100 ( & V_451 -> V_60 . V_65 ) !=
V_622 )
return - V_188 ;
if ( V_451 -> V_623 != V_620 )
return - V_188 ;
if ( V_451 -> V_95 != V_624 )
return - V_188 ;
return 0 ;
}
static int F_235 (
struct V_8 * V_16 ,
struct V_599 * V_54 ,
struct V_601 * V_451 )
{
int V_103 ;
F_221 ( V_16 , V_54 ) ;
V_103 = F_222 ( V_16 , V_451 ) ;
if ( V_103 == 0 )
V_103 = F_234 ( V_451 ,
V_54 -> V_623 ) ;
return V_103 ;
}
static int F_236 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_599 V_54 ;
struct V_601 V_451 ;
struct V_625 * V_626 ;
struct V_627 * V_628 ;
V_626 = F_79 ( sizeof( * V_626 ) , V_111 ) ;
if ( ! V_626 )
return - V_44 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 =
V_630 ;
F_54 ( sizeof( * V_626 ) ,
& V_54 . V_418 . V_631 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
& V_54 . V_418 . V_631 . V_38 ,
V_626 , sizeof( * V_626 ) ,
V_89 ) ;
if ( V_103 )
goto V_112;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
F_55 ( V_16 -> V_36 ,
& V_54 . V_418 . V_631 . V_38 , 1 ,
V_89 ) ;
if ( V_103 )
goto V_112;
if ( V_451 . V_95 != V_624 ) {
V_103 = - V_455 ;
goto V_112;
}
V_16 -> V_632 =
F_100 ( & V_626 -> V_632 ) ;
V_16 -> V_633 =
F_100 ( & V_626 -> V_633 ) ;
V_16 -> V_634 =
F_100 ( & V_626 -> V_634 )
* 16 ;
V_16 -> V_635 =
F_100 ( & V_626 -> V_635 ) ;
V_16 -> V_636 =
F_100 ( & V_626 -> V_636 ) ;
V_16 -> V_637 =
F_100 ( & V_626 -> V_637 )
* 16 ;
V_628 =
& V_626 -> V_638 [ V_639 ] ;
V_16 -> V_640 =
F_100 (
& V_628 -> V_641 ) ;
V_16 -> V_642 =
V_628 -> V_642 ;
V_16 -> V_643 =
V_628 -> V_643 ;
V_112:
F_76 ( V_626 ) ;
return V_103 ;
}
static int F_237 ( struct V_8 * V_16 )
{
if ( V_16 -> V_634 <
V_493 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_72 ,
V_16 -> V_634 ,
V_493 ) ;
return - V_188 ;
}
if ( V_16 -> V_637 <
V_463 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_73 ,
V_16 -> V_637 ,
V_463 ) ;
return - V_188 ;
}
if ( V_16 -> V_640 <
V_493 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_74 ,
V_16 -> V_640 ,
V_493 ) ;
return - V_188 ;
}
if ( ! V_16 -> V_642 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_75 ) ;
return - V_188 ;
}
if ( V_16 -> V_643 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_76 ) ;
return - V_188 ;
}
return 0 ;
}
static int F_238 ( struct V_8 * V_16 ,
bool V_644 , T_5 V_645 )
{
struct V_599 V_54 ;
struct V_601 V_451 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
if ( V_644 )
V_54 . V_623 =
V_646 ;
else
V_54 . V_623 =
V_647 ;
F_60 ( V_645 ,
& V_54 . V_418 . V_648 . V_645 ) ;
return F_235 ( V_16 , & V_54 ,
& V_451 ) ;
}
static int F_239 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_515 * V_516 ;
struct V_599 V_54 ;
struct V_601 V_451 ;
V_516 = & V_16 -> V_516 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 = V_649 ;
F_60 ( V_516 -> V_486 ,
& V_54 . V_418 . V_650 . V_645 ) ;
F_53 ( ( V_45 ) V_516 -> V_568 ,
& V_54 . V_418 . V_650 . V_651 ) ;
F_53 ( ( V_45 ) V_516 -> V_570 ,
& V_54 . V_418 . V_650 . V_652 ) ;
F_60 ( V_521 ,
& V_54 . V_418 . V_650 . V_653 ) ;
F_60 ( V_519 / 16 ,
& V_54 . V_418 . V_650 . V_654 ) ;
V_54 . V_418 . V_650 . V_655 = V_639 ;
F_60 ( V_516 -> V_575 ,
& V_54 . V_418 . V_650 . V_575 ) ;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
if ( V_103 )
return V_103 ;
V_516 -> V_458 = V_16 -> V_595 +
V_596 +
F_57 (
& V_451 . V_418 . V_650 . V_656 ) ;
return 0 ;
}
static int F_240 ( struct V_8 * V_16 ,
unsigned int V_657 )
{
int V_103 ;
struct V_313 * V_314 ;
struct V_599 V_54 ;
struct V_601 V_451 ;
V_314 = & V_16 -> V_484 [ V_657 ] ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 = V_658 ;
F_60 ( V_314 -> V_574 [ V_489 ] ,
& V_54 . V_418 . V_659 . V_645 ) ;
F_53 (
( V_45 ) V_314 -> V_567 [ V_489 ] ,
& V_54 . V_418 . V_659 . V_651 ) ;
F_53 ( ( V_45 ) V_314 -> V_569 [ V_489 ] ,
& V_54 . V_418 . V_659 . V_660 ) ;
F_60 ( V_16 -> V_491 ,
& V_54 . V_418 . V_659 . V_653 ) ;
F_60 ( V_493 / 16 ,
& V_54 . V_418 . V_659 . V_654 ) ;
V_54 . V_418 . V_659 . V_655 = V_639 ;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_77 ) ;
return V_103 ;
}
V_314 -> V_481 [ V_489 ] = V_16 -> V_595 +
V_596 +
F_57 (
& V_451 . V_418 . V_659 . V_661 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 = V_658 ;
F_60 ( V_314 -> V_574 [ V_542 ] ,
& V_54 . V_418 . V_659 . V_645 ) ;
F_53 ( ( V_45 ) V_314 ->
V_567 [ V_542 ] ,
& V_54 . V_418 . V_659 . V_651 ) ;
F_53 ( ( V_45 ) V_314 -> V_569 [ V_542 ] ,
& V_54 . V_418 . V_659 . V_660 ) ;
F_60 ( V_16 -> V_491 ,
& V_54 . V_418 . V_659 . V_653 ) ;
F_60 ( V_493 / 16 ,
& V_54 . V_418 . V_659 . V_654 ) ;
V_54 . V_418 . V_659 . V_655 = V_639 ;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_78 ) ;
goto V_662;
}
V_314 -> V_481 [ V_542 ] = V_16 -> V_595 +
V_596 +
F_57 (
& V_451 . V_418 . V_659 . V_661 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 = V_663 ;
F_60 ( V_314 -> V_574 [ V_542 ] ,
& V_54 . V_418 . V_664 . V_645 ) ;
F_54 ( V_665 ,
& V_54 . V_418 . V_664 . V_666 ) ;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_79 ) ;
goto V_667;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_629 ;
F_60 ( V_622 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_623 = V_649 ;
F_60 ( V_314 -> V_486 ,
& V_54 . V_418 . V_650 . V_645 ) ;
F_53 ( ( V_45 ) V_314 -> V_568 ,
& V_54 . V_418 . V_650 . V_651 ) ;
F_53 ( ( V_45 ) V_314 -> V_570 ,
& V_54 . V_418 . V_650 . V_652 ) ;
F_60 ( V_16 -> V_474 ,
& V_54 . V_418 . V_650 . V_653 ) ;
F_60 ( V_463 / 16 ,
& V_54 . V_418 . V_650 . V_654 ) ;
V_54 . V_418 . V_650 . V_655 = V_639 ;
F_60 ( V_314 -> V_575 ,
& V_54 . V_418 . V_650 . V_575 ) ;
V_103 = F_235 ( V_16 , & V_54 ,
& V_451 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_80 ) ;
goto V_667;
}
V_314 -> V_458 = V_16 -> V_595 +
V_596 +
F_57 (
& V_451 . V_418 . V_650 . V_656 ) ;
return 0 ;
V_667:
F_238 ( V_16 , true ,
V_314 -> V_574 [ V_542 ] ) ;
V_662:
F_238 ( V_16 , true ,
V_314 -> V_574 [ V_489 ] ) ;
return V_103 ;
}
static int F_241 ( struct V_8 * V_16 )
{
int V_103 ;
unsigned int V_52 ;
V_103 = F_239 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_81 ) ;
return V_103 ;
}
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_103 = F_240 ( V_16 , V_52 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_82 ,
V_52 , V_16 -> V_549 ) ;
return V_103 ;
}
}
return 0 ;
}
static int F_242 ( struct V_8 * V_16 ,
bool V_668 )
{
int V_103 ;
unsigned int V_52 ;
struct V_669 * V_670 ;
struct V_671 * V_672 ;
struct V_673 V_54 ;
V_670 = F_79 ( V_674 ,
V_111 ) ;
if ( ! V_670 )
return - V_44 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_675 ;
F_60 ( F_61 ( struct V_673 ,
V_418 . V_676 . V_63 [ 1 ] ) -
V_64 , & V_54 . V_60 . V_65 ) ;
F_54 ( V_674 ,
& V_54 . V_418 . V_676 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
V_54 . V_418 . V_676 . V_63 ,
V_670 , V_674 ,
V_89 ) ;
if ( V_103 )
goto V_112;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 ,
V_54 . V_418 . V_676 . V_63 , 1 ,
V_89 ) ;
if ( V_103 )
goto V_112;
for ( V_52 = 0 ; V_52 < V_670 -> V_677 ; V_52 ++ ) {
V_672 = & V_670 -> V_50 [ V_52 ] ;
if ( V_668 &&
F_193 ( V_672 -> V_497 ) )
F_60 ( V_16 -> V_516 . V_486 ,
& V_672 -> V_486 ) ;
else
F_60 ( 0 , & V_672 -> V_486 ) ;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_678 ;
F_60 ( F_61 ( struct V_673 ,
V_418 . V_676 . V_63 [ 1 ] ) -
V_64 , & V_54 . V_60 . V_65 ) ;
F_54 ( V_674 ,
& V_54 . V_418 . V_676 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
V_54 . V_418 . V_676 . V_63 ,
V_670 , V_674 ,
V_90 ) ;
if ( V_103 )
goto V_112;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 ,
V_54 . V_418 . V_676 . V_63 , 1 ,
V_90 ) ;
V_112:
F_76 ( V_670 ) ;
return V_103 ;
}
static inline int F_243 ( struct V_8 * V_16 )
{
return F_242 ( V_16 , true ) ;
}
static inline int F_244 ( struct V_8 * V_16 )
{
return F_242 ( V_16 , false ) ;
}
static void F_245 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
struct V_13 * V_88 ;
T_3 V_679 ;
struct V_93 * V_94 ;
if ( ! V_16 -> V_99 )
return;
V_88 = & V_16 -> V_36 -> V_88 ;
V_679 = V_16 -> V_679 ;
V_94 = V_16 -> V_99 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_101 ; V_52 ++ ) {
F_76 ( V_94 -> V_480 ) ;
if ( ! V_94 -> V_680 )
break;
F_246 ( V_88 , V_679 ,
V_94 -> V_680 ,
V_94 -> V_681 ) ;
V_94 ++ ;
}
F_76 ( V_16 -> V_99 ) ;
V_16 -> V_99 = NULL ;
}
static inline int F_247 ( struct V_8 * V_16 )
{
V_16 -> V_469 = F_214 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_682 ,
& V_16 -> V_683 , V_111 ) ;
if ( ! V_16 -> V_469 )
return - V_44 ;
return 0 ;
}
static int F_248 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
void * V_680 ;
T_3 V_679 ;
T_4 V_681 ;
struct V_13 * V_88 ;
struct V_93 * V_94 ;
V_16 -> V_99 = F_75 ( V_16 -> V_101 *
sizeof( V_16 -> V_99 [ 0 ] ) , V_111 ) ;
if ( ! V_16 -> V_99 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_83 ) ;
goto error;
}
V_88 = & V_16 -> V_36 -> V_88 ;
V_679 = V_16 -> V_679 ;
V_94 = V_16 -> V_99 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_101 ; V_52 ++ ) {
V_94 -> V_480 =
F_79 ( V_16 -> V_641 , V_111 ) ;
if ( ! V_94 -> V_480 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_84 ) ;
goto error;
}
V_680 = F_249 ( V_88 ,
V_679 , & V_681 ,
V_111 ) ;
if ( ! V_680 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_85 ) ;
goto error;
}
V_94 -> V_512 = V_52 ;
V_94 -> V_680 = V_680 ;
V_94 -> V_681 =
V_681 ;
V_94 ++ ;
}
return 0 ;
error:
F_245 ( V_16 ) ;
return - V_44 ;
}
static void F_250 ( struct V_8 * V_16 )
{
T_2 V_684 ;
T_2 V_685 ;
V_16 -> V_686 =
V_16 -> V_687 - V_688 ;
V_16 -> V_101 = V_16 -> V_687 ;
V_16 -> V_682 =
V_16 -> V_101 * V_471 ;
if ( V_689 )
V_684 = F_251 ( V_16 -> V_684 ,
V_690 ) ;
else
V_684 = F_251 ( V_16 -> V_684 ,
V_691 ) ;
V_685 = V_684 / V_692 ;
V_685 ++ ;
V_685 = F_251 ( V_16 -> V_685 , V_685 ) ;
V_684 = ( V_685 - 1 ) * V_692 ;
V_16 -> V_679 =
( V_685 * sizeof( struct V_37 ) ) +
V_563 ;
V_16 -> V_693 = V_685 ;
V_16 -> V_694 = V_684 / 512 ;
}
static void F_252 ( struct V_8 * V_16 )
{
int V_549 ;
T_5 V_491 ;
T_5 V_474 ;
if ( V_689 ) {
V_549 = 1 ;
} else {
int V_695 ;
int V_696 ;
V_696 = F_251 ( V_16 -> V_632 / 2 ,
V_16 -> V_635 - 1 ) ;
V_696 = F_251 ( V_696 , V_697 ) ;
V_695 = F_253 () ;
V_549 = F_251 ( V_695 , V_16 -> V_698 ) ;
V_549 = F_251 ( V_549 , V_696 ) ;
}
V_16 -> V_549 = V_549 ;
V_16 -> V_699 = V_549 - 1 ;
V_16 -> V_641 =
( V_16 -> V_640 /
V_493 ) *
V_493 ;
V_491 =
( V_16 -> V_641 /
V_493 ) ;
V_491 ++ ;
V_491 = F_251 ( V_491 ,
V_16 -> V_633 ) ;
V_474 = ( ( V_491 - 1 ) * 2 ) + 1 ;
V_474 = F_251 ( V_474 ,
V_16 -> V_636 ) ;
V_16 -> V_491 = V_491 ;
V_16 -> V_474 = V_474 ;
V_16 -> V_700 =
( ( V_16 -> V_641 -
V_493 ) /
sizeof( struct V_37 ) ) +
V_701 ;
}
static inline void F_254 (
struct V_37 * V_38 , struct V_702 * V_703 )
{
V_45 V_46 = ( V_45 ) F_255 ( V_703 ) ;
unsigned int V_47 = F_256 ( V_703 ) ;
F_53 ( V_46 , & V_38 -> V_46 ) ;
F_54 ( V_47 , & V_38 -> V_47 ) ;
F_54 ( 0 , & V_38 -> V_49 ) ;
}
static int F_257 ( struct V_8 * V_16 ,
struct V_53 * V_54 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
int V_52 ;
T_5 V_65 ;
int V_704 ;
bool V_705 ;
unsigned int V_706 ;
unsigned int V_700 ;
struct V_702 * V_703 ;
struct V_37 * V_38 ;
V_704 = F_258 ( V_4 ) ;
if ( V_704 < 0 )
return V_704 ;
V_65 = F_61 ( struct V_53 , V_63 ) -
V_64 ;
if ( V_704 == 0 )
goto V_112;
V_703 = F_259 ( V_4 ) ;
V_38 = V_54 -> V_63 ;
V_700 = V_16 -> V_700 - 1 ;
V_705 = false ;
V_706 = 0 ;
V_52 = 0 ;
while ( 1 ) {
F_254 ( V_38 , V_703 ) ;
if ( ! V_705 )
V_706 ++ ;
V_52 ++ ;
if ( V_52 == V_704 )
break;
V_38 ++ ;
if ( V_52 == V_700 ) {
F_53 (
( V_45 ) V_94 -> V_681 ,
& V_38 -> V_46 ) ;
F_54 ( ( V_704 - V_706 )
* sizeof( * V_38 ) ,
& V_38 -> V_47 ) ;
F_54 ( V_707 ,
& V_38 -> V_49 ) ;
V_705 = true ;
V_706 ++ ;
V_38 = V_94 -> V_680 ;
}
V_703 = F_260 ( V_703 ) ;
}
F_54 ( V_48 , & V_38 -> V_49 ) ;
V_54 -> V_708 = V_705 ;
V_65 += V_706 * sizeof( * V_38 ) ;
V_112:
F_60 ( V_65 , & V_54 -> V_60 . V_65 ) ;
return 0 ;
}
static int F_261 ( struct V_8 * V_16 ,
struct V_709 * V_54 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
int V_52 ;
T_5 V_65 ;
int V_704 ;
bool V_705 ;
unsigned int V_706 ;
unsigned int V_700 ;
struct V_702 * V_703 ;
struct V_37 * V_38 ;
V_704 = F_258 ( V_4 ) ;
if ( V_704 < 0 )
return V_704 ;
V_65 = F_61 ( struct V_709 , V_63 ) -
V_64 ;
V_706 = 0 ;
if ( V_704 == 0 )
goto V_112;
V_703 = F_259 ( V_4 ) ;
V_38 = V_54 -> V_63 ;
V_700 = V_16 -> V_700 - 1 ;
V_705 = false ;
V_52 = 0 ;
while ( 1 ) {
F_254 ( V_38 , V_703 ) ;
if ( ! V_705 )
V_706 ++ ;
V_52 ++ ;
if ( V_52 == V_704 )
break;
V_38 ++ ;
if ( V_52 == V_700 ) {
F_53 (
( V_45 ) V_94 -> V_681 ,
& V_38 -> V_46 ) ;
F_54 ( ( V_704 - V_706 )
* sizeof( * V_38 ) ,
& V_38 -> V_47 ) ;
F_54 ( V_707 ,
& V_38 -> V_49 ) ;
V_705 = true ;
V_706 ++ ;
V_38 = V_94 -> V_680 ;
}
V_703 = F_260 ( V_703 ) ;
}
F_54 ( V_48 , & V_38 -> V_49 ) ;
V_54 -> V_708 = V_705 ;
V_65 += V_706 * sizeof( * V_38 ) ;
V_112:
F_60 ( V_65 , & V_54 -> V_60 . V_65 ) ;
V_54 -> V_710 = V_706 ;
return 0 ;
}
static void F_262 ( struct V_93 * V_94 ,
void * V_473 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_68 ( V_94 ) ;
F_263 ( V_4 ) ;
F_3 ( V_4 ) ;
}
static int F_264 (
struct V_8 * V_16 , struct V_93 * V_94 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_313 * V_314 )
{
int V_103 ;
T_3 V_342 ;
struct V_53 * V_54 ;
V_94 -> V_472 = F_262 ;
V_94 -> V_4 = V_4 ;
V_54 = V_94 -> V_480 ;
memset ( V_54 , 0 ,
F_61 ( struct V_53 , V_63 ) ) ;
V_54 -> V_60 . V_61 = V_62 ;
F_54 ( F_172 ( V_4 ) , & V_54 -> V_40 ) ;
V_54 -> V_67 = V_68 ;
F_60 ( V_94 -> V_512 , & V_54 -> V_460 ) ;
V_54 -> V_470 = V_54 -> V_460 ;
memcpy ( V_54 -> V_66 , V_13 -> V_15 ,
sizeof( V_54 -> V_66 ) ) ;
V_342 = F_265 ( T_3 , V_4 -> V_711 , sizeof( V_54 -> V_58 ) ) ;
memcpy ( V_54 -> V_58 , V_4 -> V_346 , V_342 ) ;
switch ( V_342 ) {
case 6 :
case 10 :
case 12 :
case 16 :
V_54 -> V_69 =
V_70 ;
break;
case 20 :
V_54 -> V_69 =
V_712 ;
break;
case 24 :
V_54 -> V_69 =
V_713 ;
break;
case 28 :
V_54 -> V_69 =
V_714 ;
break;
case 32 :
default:
V_54 -> V_69 =
V_715 ;
break;
}
switch ( V_4 -> V_716 ) {
case V_717 :
V_54 -> V_41 = V_72 ;
break;
case V_718 :
V_54 -> V_41 = V_81 ;
break;
case V_719 :
V_54 -> V_41 = V_91 ;
break;
case V_720 :
V_54 -> V_41 = V_721 ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_86 ,
V_4 -> V_716 ) ;
break;
}
V_103 = F_257 ( V_16 , V_54 , V_4 , V_94 ) ;
if ( V_103 ) {
F_68 ( V_94 ) ;
return V_722 ;
}
F_202 ( V_16 , V_314 , V_489 , V_94 ) ;
return 0 ;
}
static inline int F_266 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_313 * V_314 )
{
struct V_93 * V_94 ;
V_94 = F_66 ( V_16 ) ;
return F_264 ( V_16 , V_94 ,
V_13 , V_4 , V_314 ) ;
}
static inline void F_267 ( struct V_8 * V_16 )
{
if ( ! F_25 ( V_16 ) )
F_195 ( & V_16 -> V_723 ) ;
}
static bool F_268 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_8 * V_16 ;
if ( ! V_94 -> V_97 )
return false ;
V_4 = V_94 -> V_4 ;
if ( ( V_4 -> V_427 & 0xff ) == V_435 )
return false ;
if ( V_381 ( V_4 -> V_427 ) == V_424 )
return false ;
V_13 = V_4 -> V_13 -> V_11 ;
if ( F_38 ( V_13 ) )
return false ;
V_16 = F_6 ( V_4 -> V_13 -> V_379 ) ;
if ( F_10 ( V_16 ) )
return false ;
return true ;
}
static inline void F_269 (
struct V_8 * V_16 ,
struct V_93 * V_94 , bool V_724 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_725 , V_49 ) ;
if ( V_724 )
F_270 ( & V_94 -> V_609 ,
& V_16 -> V_726 ) ;
else
F_135 ( & V_94 -> V_609 ,
& V_16 -> V_726 ) ;
F_131 ( & V_16 -> V_725 , V_49 ) ;
}
static void F_271 ( struct V_93 * V_94 ,
void * V_473 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_68 ( V_94 ) ;
F_3 ( V_4 ) ;
}
static void F_272 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_8 * V_16 ;
V_94 -> V_472 = F_271 ;
V_4 = V_94 -> V_4 ;
V_4 -> V_427 = 0 ;
V_16 = F_6 ( V_4 -> V_13 -> V_379 ) ;
F_269 ( V_16 , V_94 , false ) ;
F_267 ( V_16 ) ;
}
static int F_273 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_8 * V_16 ;
struct V_313 * V_314 ;
V_4 = V_94 -> V_4 ;
V_13 = V_4 -> V_13 -> V_11 ;
if ( F_41 ( V_13 ) ) {
F_68 ( V_94 ) ;
F_175 ( V_4 , V_727 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
V_16 = F_6 ( V_4 -> V_13 -> V_379 ) ;
V_314 = V_94 -> V_314 ;
F_65 ( V_94 ) ;
return F_264 ( V_16 , V_94 ,
V_13 , V_4 , V_314 ) ;
}
static inline struct V_93 * F_274 (
struct V_8 * V_16 )
{
unsigned long V_49 ;
struct V_93 * V_94 ;
F_129 ( & V_16 -> V_725 , V_49 ) ;
V_94 = F_145 (
& V_16 -> V_726 ,
struct V_93 , V_609 ) ;
if ( V_94 )
F_130 ( & V_94 -> V_609 ) ;
F_131 ( & V_16 -> V_725 , V_49 ) ;
return V_94 ;
}
static void F_23 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_93 * V_94 ;
F_33 ( V_16 ) ;
while ( 1 ) {
if ( F_25 ( V_16 ) )
break;
V_94 = F_274 ( V_16 ) ;
if ( ! V_94 )
break;
V_103 = F_273 ( V_94 ) ;
if ( V_103 ) {
F_269 ( V_16 , V_94 ,
true ) ;
F_267 ( V_16 ) ;
break;
}
}
F_34 ( V_16 ) ;
}
static void F_275 ( struct V_135 * V_136 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( V_136 , struct V_8 ,
V_723 ) ;
F_23 ( V_16 ) ;
}
static void F_276 (
struct V_8 * V_16 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_725 , V_49 ) ;
F_217 ( & V_16 -> V_726 ) ;
F_131 ( & V_16 -> V_725 , V_49 ) ;
}
static void F_277 ( struct V_93 * V_94 ,
void * V_473 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_263 ( V_4 ) ;
if ( V_94 -> V_95 == - V_438 )
F_175 ( V_4 , V_728 ) ;
else if ( F_268 ( V_94 ) ) {
F_272 ( V_94 ) ;
return;
}
F_68 ( V_94 ) ;
F_3 ( V_4 ) ;
}
static inline int F_278 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_313 * V_314 )
{
return F_162 ( V_16 , V_4 , V_13 -> V_270 ,
V_4 -> V_346 , V_4 -> V_711 , V_314 , NULL , false ) ;
}
static int F_162 ( struct V_8 * V_16 ,
struct V_3 * V_4 , T_2 V_270 , T_1 * V_58 ,
unsigned int V_342 , struct V_313 * V_314 ,
struct V_306 * V_307 , bool V_97 )
{
int V_103 ;
struct V_93 * V_94 ;
struct V_709 * V_54 ;
V_94 = F_66 ( V_16 ) ;
V_94 -> V_472 = F_277 ;
V_94 -> V_4 = V_4 ;
V_94 -> V_97 = V_97 ;
V_54 = V_94 -> V_480 ;
memset ( V_54 , 0 ,
F_61 ( struct V_53 , V_63 ) ) ;
V_54 -> V_60 . V_61 = V_729 ;
F_54 ( V_270 , & V_54 -> V_730 ) ;
F_54 ( F_172 ( V_4 ) , & V_54 -> V_40 ) ;
V_54 -> V_67 = V_68 ;
F_60 ( V_94 -> V_512 , & V_54 -> V_460 ) ;
V_54 -> V_470 = V_54 -> V_460 ;
if ( V_342 > sizeof( V_54 -> V_58 ) )
V_342 = sizeof( V_54 -> V_58 ) ;
V_54 -> V_342 = V_342 ;
memcpy ( V_54 -> V_58 , V_58 , V_342 ) ;
switch ( V_4 -> V_716 ) {
case V_717 :
V_54 -> V_41 = V_72 ;
break;
case V_718 :
V_54 -> V_41 = V_81 ;
break;
case V_719 :
V_54 -> V_41 = V_91 ;
break;
case V_720 :
V_54 -> V_41 = V_721 ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_86 ,
V_4 -> V_716 ) ;
break;
}
if ( V_307 ) {
V_54 -> V_731 = true ;
F_60 ( V_307 -> V_310 ,
& V_54 -> V_310 ) ;
F_54 ( V_307 -> V_311 ,
& V_54 -> V_311 ) ;
F_54 ( V_307 -> V_312 ,
& V_54 -> V_312 ) ;
}
V_103 = F_261 ( V_16 , V_54 , V_4 , V_94 ) ;
if ( V_103 ) {
F_68 ( V_94 ) ;
return V_722 ;
}
F_202 ( V_16 , V_314 , V_542 , V_94 ) ;
return 0 ;
}
static inline T_5 F_279 ( struct V_8 * V_16 ,
struct V_3 * V_4 )
{
T_5 V_732 ;
V_732 = F_280 ( F_281 ( V_4 -> V_54 ) ) ;
if ( V_732 > V_16 -> V_699 )
V_732 = 0 ;
return V_732 ;
}
void F_4 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = V_4 -> V_13 -> V_11 ;
F_32 ( & V_13 -> V_733 ) ;
}
static int F_282 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
int V_103 ;
struct V_8 * V_16 ;
struct V_12 * V_13 ;
T_5 V_732 ;
struct V_313 * V_314 ;
bool V_734 ;
V_13 = V_4 -> V_13 -> V_11 ;
V_16 = F_6 ( V_10 ) ;
F_27 ( & V_13 -> V_733 ) ;
if ( F_10 ( V_16 ) ) {
F_175 ( V_4 , V_424 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
F_33 ( V_16 ) ;
if ( F_25 ( V_16 ) || F_41 ( V_13 ) ) {
V_103 = V_722 ;
goto V_112;
}
V_4 -> V_427 = 0 ;
V_732 = F_279 ( V_16 , V_4 ) ;
V_314 = & V_16 -> V_484 [ V_732 ] ;
if ( F_8 ( V_13 ) ) {
V_734 = false ;
if ( V_13 -> V_192 &&
! F_283 ( V_4 -> V_54 ) ) {
V_103 = F_156 ( V_16 , V_13 ,
V_4 , V_314 ) ;
if ( V_103 == 0 || V_103 == V_722 )
V_734 = true ;
}
if ( ! V_734 )
V_103 = F_266 ( V_16 , V_13 , V_4 ,
V_314 ) ;
} else {
if ( V_13 -> V_266 )
V_103 = F_278 ( V_16 , V_13 , V_4 ,
V_314 ) ;
else
V_103 = F_266 ( V_16 , V_13 , V_4 ,
V_314 ) ;
}
V_112:
F_34 ( V_16 ) ;
if ( V_103 )
F_32 ( & V_13 -> V_733 ) ;
return V_103 ;
}
static int F_284 ( struct V_8 * V_16 ,
struct V_313 * V_314 )
{
unsigned int V_377 ;
unsigned long V_49 ;
bool V_735 ;
for ( V_377 = 0 ; V_377 < 2 ; V_377 ++ ) {
while ( 1 ) {
F_129 (
& V_314 -> V_488 [ V_377 ] , V_49 ) ;
V_735 =
F_285 ( & V_314 -> V_576 [ V_377 ] ) ;
F_131 (
& V_314 -> V_488 [ V_377 ] , V_49 ) ;
if ( V_735 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_110 ;
F_37 ( 1000 , 2000 ) ;
}
}
return 0 ;
}
static int F_286 ( struct V_8 * V_16 )
{
int V_103 ;
unsigned int V_52 ;
unsigned int V_377 ;
struct V_313 * V_314 ;
T_9 V_481 ;
T_9 V_482 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_314 = & V_16 -> V_484 [ V_52 ] ;
V_103 = F_284 ( V_16 , V_314 ) ;
if ( V_103 )
return V_103 ;
for ( V_377 = 0 ; V_377 < 2 ; V_377 ++ ) {
V_481 = V_314 -> V_490 [ V_377 ] ;
while ( 1 ) {
V_482 = * V_314 -> V_482 [ V_377 ] ;
if ( V_482 == V_481 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_110 ;
F_37 ( 1000 , 2000 ) ;
}
}
}
return 0 ;
}
static void F_287 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
unsigned int V_52 ;
unsigned int V_377 ;
struct V_313 * V_314 ;
unsigned long V_49 ;
struct V_93 * V_94 ;
struct V_93 * V_278 ;
struct V_3 * V_4 ;
struct V_12 * V_376 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_314 = & V_16 -> V_484 [ V_52 ] ;
for ( V_377 = 0 ; V_377 < 2 ; V_377 ++ ) {
F_129 (
& V_314 -> V_488 [ V_377 ] , V_49 ) ;
F_134 (io_request, next,
&queue_group->request_list[path],
request_list_entry) {
V_4 = V_94 -> V_4 ;
if ( ! V_4 )
continue;
V_376 = V_4 -> V_13 -> V_11 ;
if ( V_376 != V_13 )
continue;
F_130 ( & V_94 -> V_609 ) ;
F_175 ( V_4 , V_727 ) ;
F_3 ( V_4 ) ;
}
F_131 (
& V_314 -> V_488 [ V_377 ] , V_49 ) ;
}
}
}
static int F_288 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
while ( F_36 ( & V_13 -> V_733 ) ) {
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_110 ;
F_37 ( 1000 , 2000 ) ;
}
return 0 ;
}
static int F_289 ( struct V_8 * V_16 )
{
bool V_736 ;
unsigned long V_49 ;
struct V_12 * V_13 ;
while ( 1 ) {
V_736 = false ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_36 ( & V_13 -> V_733 ) ) {
V_736 = true ;
break;
}
}
F_131 ( & V_16 -> V_272 ,
V_49 ) ;
if ( ! V_736 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_110 ;
F_37 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_290 ( struct V_93 * V_94 ,
void * V_473 )
{
struct V_610 * V_613 = V_473 ;
F_227 ( V_613 ) ;
}
static int F_291 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_610 * V_611 )
{
int V_103 ;
while ( 1 ) {
if ( F_225 ( V_611 ,
V_737 * V_367 ) ) {
V_103 = 0 ;
break;
}
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = - V_110 ;
break;
}
}
return V_103 ;
}
static int F_292 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
struct V_93 * V_94 ;
F_229 ( V_611 ) ;
struct V_738 * V_54 ;
V_94 = F_66 ( V_16 ) ;
V_94 -> V_472 = F_290 ;
V_94 -> V_473 = & V_611 ;
V_54 = V_94 -> V_480 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 . V_61 = V_739 ;
F_60 ( sizeof( * V_54 ) - V_64 ,
& V_54 -> V_60 . V_65 ) ;
F_60 ( V_94 -> V_512 , & V_54 -> V_460 ) ;
memcpy ( V_54 -> V_66 , V_13 -> V_15 ,
sizeof( V_54 -> V_66 ) ) ;
V_54 -> V_740 = V_741 ;
F_202 ( V_16 ,
& V_16 -> V_484 [ V_485 ] , V_489 ,
V_94 ) ;
V_103 = F_291 ( V_16 , V_13 , & V_611 ) ;
if ( V_103 == 0 )
V_103 = V_94 -> V_95 ;
F_68 ( V_94 ) ;
return V_103 ;
}
static int F_293 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
V_103 = F_292 ( V_16 , V_13 ) ;
if ( V_103 == 0 )
V_103 = F_288 ( V_16 , V_13 ) ;
return V_103 == 0 ? V_742 : V_743 ;
}
static int F_294 ( struct V_3 * V_4 )
{
int V_103 ;
struct V_9 * V_10 ;
struct V_8 * V_16 ;
struct V_12 * V_13 ;
V_10 = V_4 -> V_13 -> V_379 ;
V_16 = F_6 ( V_10 ) ;
V_13 = V_4 -> V_13 -> V_11 ;
F_64 ( & V_16 -> V_36 -> V_88 ,
L_87 ,
V_10 -> V_187 , V_13 -> V_155 , V_13 -> V_156 , V_13 -> V_157 ) ;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = V_743 ;
goto V_112;
}
F_146 ( & V_16 -> V_305 ) ;
F_19 ( V_16 ) ;
F_35 ( V_16 ) ;
F_287 ( V_16 , V_13 ) ;
V_103 = F_286 ( V_16 ) ;
F_39 ( V_13 ) ;
F_21 ( V_16 ) ;
if ( V_103 )
V_103 = V_743 ;
else
V_103 = F_293 ( V_16 , V_13 ) ;
F_40 ( V_13 ) ;
F_147 ( & V_16 -> V_305 ) ;
V_112:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_88 ,
V_10 -> V_187 , V_13 -> V_155 , V_13 -> V_156 , V_13 -> V_157 ,
V_103 == V_742 ? L_89 : L_90 ) ;
return V_103 ;
}
static int F_295 ( struct V_376 * V_251 )
{
struct V_12 * V_13 ;
unsigned long V_49 ;
struct V_8 * V_16 ;
struct V_744 * V_745 ;
struct V_746 * V_747 ;
V_16 = F_6 ( V_251 -> V_379 ) ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
if ( F_296 ( V_251 ) == V_164 ) {
V_745 = V_744 ( V_251 ) ;
V_747 = F_297 ( V_745 ) ;
V_13 = F_298 ( V_16 , V_747 ) ;
if ( V_13 ) {
V_13 -> V_156 = F_299 ( V_251 ) ;
V_13 -> V_157 = V_251 -> V_157 ;
V_13 -> V_160 = true ;
}
} else {
V_13 = F_120 ( V_16 , F_296 ( V_251 ) ,
F_299 ( V_251 ) , V_251 -> V_157 ) ;
}
if ( V_13 ) {
V_251 -> V_11 = V_13 ;
V_13 -> V_251 = V_251 ;
if ( V_13 -> V_209 ) {
V_13 -> V_285 = V_13 -> V_209 ;
F_136 ( V_251 ,
V_13 -> V_285 ) ;
}
}
F_131 ( & V_16 -> V_272 , V_49 ) ;
return 0 ;
}
static int F_300 ( struct V_9 * V_10 )
{
struct V_8 * V_16 = F_6 ( V_10 ) ;
return F_301 ( & V_10 -> V_748 , V_16 -> V_36 ) ;
}
static int F_302 ( struct V_8 * V_16 ,
void T_11 * V_749 )
{
struct V_36 * V_36 ;
T_2 V_750 ;
T_2 V_751 ;
T_12 V_752 ;
if ( ! V_749 )
return - V_188 ;
V_36 = V_16 -> V_36 ;
V_752 . V_753 = F_303 ( V_36 -> V_155 ) ;
V_752 . V_155 = V_36 -> V_155 -> V_754 ;
V_752 . V_755 = V_36 -> V_756 ;
V_750 = V_36 -> V_750 ;
V_751 = V_36 -> V_751 ;
V_752 . V_757 = ( ( V_751 << 16 ) & 0xffff0000 ) |
V_750 ;
if ( F_304 ( V_749 , & V_752 , sizeof( V_752 ) ) )
return - V_758 ;
return 0 ;
}
static int F_305 ( void T_11 * V_749 )
{
T_2 V_759 ;
if ( ! V_749 )
return - V_188 ;
V_759 = ( V_760 << 28 ) | ( V_761 << 24 ) |
( V_762 << 16 ) | V_763 ;
if ( F_304 ( V_749 , & V_759 , sizeof( V_759 ) ) )
return - V_758 ;
return 0 ;
}
static void F_306 ( struct V_382 * V_764 ,
struct V_765 * V_765 )
{
int V_766 ;
T_3 V_383 ;
switch ( V_764 -> V_389 ) {
case V_390 :
V_766 = V_767 ;
break;
case V_391 :
V_766 = V_768 ;
break;
case V_400 :
V_766 = V_769 ;
break;
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
V_766 = V_770 ;
break;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
V_766 = V_771 ;
break;
case V_395 :
V_766 = V_772 ;
break;
case V_396 :
V_766 = V_773 ;
break;
case V_398 :
V_766 = V_774 ;
break;
default:
V_766 = V_775 ;
break;
}
V_383 =
F_100 ( & V_764 -> V_383 ) ;
if ( V_383 == 0 )
V_383 =
F_100 ( & V_764 -> V_417 ) ;
if ( V_383 )
if ( V_383 > sizeof( V_764 -> V_418 ) )
V_383 = sizeof( V_764 -> V_418 ) ;
V_765 -> V_380 = V_764 -> V_95 ;
V_765 -> V_776 = V_766 ;
V_765 -> V_383 = V_383 ;
}
static int F_307 ( struct V_8 * V_16 , void T_11 * V_749 )
{
int V_103 ;
char * V_777 = NULL ;
T_5 V_65 ;
T_3 V_383 ;
T_13 V_778 ;
struct V_53 V_54 ;
struct V_382 V_764 ;
struct V_765 V_765 ;
if ( F_10 ( V_16 ) )
return - V_110 ;
if ( ! V_749 )
return - V_188 ;
if ( ! F_308 ( V_779 ) )
return - V_780 ;
if ( F_309 ( & V_778 , V_749 , sizeof( V_778 ) ) )
return - V_758 ;
if ( V_778 . V_781 < 1 &&
V_778 . V_782 . Type . V_783 != V_784 )
return - V_188 ;
if ( V_778 . V_782 . V_785 > sizeof( V_54 . V_58 ) )
return - V_188 ;
if ( V_778 . V_782 . Type . Type != V_786 )
return - V_188 ;
switch ( V_778 . V_782 . Type . V_783 ) {
case V_784 :
case V_787 :
case V_788 :
case V_788 | V_787 :
break;
default:
return - V_188 ;
}
if ( V_778 . V_781 > 0 ) {
V_777 = F_79 ( V_778 . V_781 , V_111 ) ;
if ( ! V_777 )
return - V_44 ;
if ( V_778 . V_782 . Type . V_783 & V_787 ) {
if ( F_309 ( V_777 , V_778 . V_789 ,
V_778 . V_781 ) ) {
V_103 = - V_758 ;
goto V_112;
}
} else {
memset ( V_777 , 0 , V_778 . V_781 ) ;
}
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_62 ;
V_65 = F_61 ( struct V_53 , V_63 ) -
V_64 ;
memcpy ( V_54 . V_66 , V_778 . V_790 . V_791 ,
sizeof( V_54 . V_66 ) ) ;
memcpy ( V_54 . V_58 , V_778 . V_782 . V_792 , V_778 . V_782 . V_785 ) ;
V_54 . V_69 = V_70 ;
switch ( V_778 . V_782 . Type . V_783 ) {
case V_784 :
V_54 . V_41 = V_91 ;
break;
case V_787 :
V_54 . V_41 = V_81 ;
break;
case V_788 :
V_54 . V_41 = V_72 ;
break;
case V_788 | V_787 :
V_54 . V_41 = V_721 ;
break;
}
V_54 . V_67 = V_68 ;
if ( V_778 . V_781 > 0 ) {
F_54 ( V_778 . V_781 , & V_54 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
& V_54 . V_63 [ 0 ] , V_777 ,
V_778 . V_781 , V_92 ) ;
if ( V_103 )
goto V_112;
V_65 += sizeof( V_54 . V_63 [ 0 ] ) ;
}
F_60 ( V_65 , & V_54 . V_60 . V_65 ) ;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
V_616 , & V_764 , V_27 ) ;
if ( V_778 . V_781 > 0 )
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_92 ) ;
memset ( & V_778 . V_96 , 0 , sizeof( V_778 . V_96 ) ) ;
if ( V_103 == 0 ) {
F_306 ( & V_764 , & V_765 ) ;
V_778 . V_96 . V_793 = V_765 . V_380 ;
V_778 . V_96 . V_794 =
V_765 . V_776 ;
V_383 = V_765 . V_383 ;
if ( V_383 ) {
if ( V_383 >
sizeof( V_778 . V_96 . V_795 ) )
V_383 =
sizeof( V_778 . V_96 . V_795 ) ;
memcpy ( V_778 . V_96 . V_795 ,
V_764 . V_418 , V_383 ) ;
V_778 . V_96 . V_796 = V_383 ;
}
}
if ( F_304 ( V_749 , & V_778 , sizeof( V_778 ) ) ) {
V_103 = - V_758 ;
goto V_112;
}
if ( V_103 == 0 && V_778 . V_781 > 0 &&
( V_778 . V_782 . Type . V_783 & V_788 ) ) {
if ( F_304 ( V_778 . V_789 , V_777 ,
V_778 . V_781 ) ) {
V_103 = - V_758 ;
}
}
V_112:
F_76 ( V_777 ) ;
return V_103 ;
}
static int F_310 ( struct V_376 * V_251 , int V_55 , void T_11 * V_749 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_6 ( V_251 -> V_379 ) ;
switch ( V_55 ) {
case V_797 :
case V_798 :
case V_799 :
V_103 = F_113 ( V_16 ) ;
break;
case V_800 :
V_103 = F_302 ( V_16 , V_749 ) ;
break;
case V_801 :
V_103 = F_305 ( V_749 ) ;
break;
case V_802 :
V_103 = F_307 ( V_16 , V_749 ) ;
break;
default:
V_103 = - V_188 ;
break;
}
return V_103 ;
}
static T_7 F_311 ( struct V_13 * V_88 ,
struct V_803 * V_804 , char * V_39 )
{
T_7 V_263 = 0 ;
struct V_9 * V_10 ;
struct V_8 * V_16 ;
V_10 = F_312 ( V_88 ) ;
V_16 = F_6 ( V_10 ) ;
V_263 += snprintf (buffer + count, PAGE_SIZE - count,
L_91 , DRIVER_VERSION BUILD_TIMESTAMP) ;
V_263 += snprintf ( V_39 + V_263 , V_692 - V_263 ,
L_92 , V_16 -> V_805 ) ;
return V_263 ;
}
static T_7 F_313 ( struct V_13 * V_88 ,
struct V_803 * V_804 , const char * V_39 , T_3 V_263 )
{
struct V_9 * V_10 = F_312 ( V_88 ) ;
F_148 ( V_10 ) ;
return V_263 ;
}
static T_7 F_314 ( struct V_13 * V_88 ,
struct V_803 * V_804 , char * V_39 )
{
int V_263 = 0 ;
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < F_2 ( V_806 ) ; V_52 ++ ) {
if ( V_806 [ V_52 ] . V_262 == V_807 )
V_263 += snprintf ( V_39 + V_263 , V_692 - V_263 ,
L_93 , V_806 [ V_52 ] . V_808 ) ;
else
V_263 += snprintf ( V_39 + V_263 , V_692 - V_263 ,
L_94 , V_806 [ V_52 ] . V_808 ) ;
}
V_263 += snprintf ( V_39 + V_263 , V_692 - V_263 , L_95 ) ;
return V_263 ;
}
static T_7 F_315 ( struct V_13 * V_88 ,
struct V_803 * V_804 , const char * V_39 , T_3 V_263 )
{
unsigned int V_52 ;
char * V_809 ;
char V_810 [ 32 ] ;
F_316 ( V_810 , V_39 , sizeof( V_810 ) ) ;
V_809 = F_317 ( V_810 ) ;
for ( V_52 = 0 ; V_52 < F_2 ( V_806 ) ; V_52 ++ ) {
if ( strcmp ( V_809 , V_806 [ V_52 ] . V_808 ) == 0 ) {
V_807 = V_806 [ V_52 ] . V_262 ;
return V_263 ;
}
}
return - V_188 ;
}
static T_7 F_318 ( struct V_13 * V_88 ,
struct V_803 * V_804 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_376 * V_251 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
V_45 V_265 ;
V_251 = F_319 ( V_88 ) ;
V_16 = F_6 ( V_251 -> V_379 ) ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
V_13 = V_251 -> V_11 ;
if ( F_8 ( V_13 ) ) {
F_131 ( & V_16 -> V_272 ,
V_49 ) ;
return - V_811 ;
}
V_265 = V_13 -> V_265 ;
F_131 ( & V_16 -> V_272 , V_49 ) ;
return snprintf ( V_39 , V_692 , L_96 , V_265 ) ;
}
static T_7 F_320 ( struct V_13 * V_88 ,
struct V_803 * V_804 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_376 * V_251 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
V_251 = F_319 ( V_88 ) ;
V_16 = F_6 ( V_251 -> V_379 ) ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
V_13 = V_251 -> V_11 ;
V_39 [ 0 ] = V_13 -> V_192 ? '1' : '0' ;
V_39 [ 1 ] = '\n' ;
V_39 [ 2 ] = '\0' ;
F_131 ( & V_16 -> V_272 , V_49 ) ;
return 2 ;
}
static T_7 F_321 ( struct V_13 * V_88 ,
struct V_803 * V_804 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_376 * V_251 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
char * V_1 ;
V_251 = F_319 ( V_88 ) ;
V_16 = F_6 ( V_251 -> V_379 ) ;
F_129 ( & V_16 -> V_272 , V_49 ) ;
V_13 = V_251 -> V_11 ;
if ( F_8 ( V_13 ) )
V_1 = F_1 ( V_13 -> V_1 ) ;
else
V_1 = L_97 ;
F_131 ( & V_16 -> V_272 , V_49 ) ;
return snprintf ( V_39 , V_692 , L_57 , V_1 ) ;
}
static int F_322 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_9 * V_10 ;
V_10 = F_323 ( & V_812 , sizeof( V_16 ) ) ;
if ( ! V_10 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_98 ,
V_16 -> V_813 ) ;
return - V_44 ;
}
V_10 -> V_814 = 0 ;
V_10 -> V_815 = 0 ;
V_10 -> V_816 = - 1 ;
V_10 -> V_817 = V_818 ;
V_10 -> V_819 = V_820 ;
V_10 -> V_821 = ~ 0 ;
V_10 -> V_822 = ~ 0 ;
V_10 -> V_694 = V_16 -> V_694 ;
V_10 -> V_823 = V_16 -> V_686 ;
V_10 -> V_824 = V_10 -> V_823 ;
V_10 -> V_693 = V_16 -> V_693 ;
V_10 -> V_825 = V_826 ;
V_10 -> V_538 = F_204 ( V_16 -> V_36 , 0 ) ;
V_10 -> V_827 = V_10 -> V_538 ;
V_10 -> V_828 = V_16 -> V_549 ;
V_10 -> V_11 [ 0 ] = ( unsigned long ) V_16 ;
V_103 = F_324 ( V_10 , & V_16 -> V_36 -> V_88 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_99 ,
V_16 -> V_813 ) ;
goto V_829;
}
V_103 = F_325 ( V_10 , V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_100 ,
V_16 -> V_813 ) ;
goto V_830;
}
V_16 -> V_22 = V_10 ;
return 0 ;
V_830:
F_326 ( V_10 ) ;
V_829:
F_327 ( V_10 ) ;
return V_103 ;
}
static void F_328 ( struct V_8 * V_16 )
{
struct V_9 * V_10 ;
F_329 ( V_16 ) ;
V_10 = V_16 -> V_22 ;
if ( ! V_10 )
return;
F_326 ( V_10 ) ;
F_327 ( V_10 ) ;
}
static int F_330 ( struct V_8 * V_16 )
{
int V_103 = 0 ;
struct V_362 T_8 * V_363 ;
unsigned long V_364 ;
unsigned int V_24 ;
union V_831 V_832 ;
V_363 = V_16 -> V_363 ;
V_24 = F_331 ( & V_363 -> V_833 ) * 100 ;
V_364 = F_30 ( V_24 ) + V_368 ;
while ( 1 ) {
F_166 ( V_834 ) ;
V_832 . V_835 = F_49 ( & V_363 -> V_836 ) ;
if ( V_832 . V_837 . V_838 == V_839 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = - V_110 ;
break;
}
if ( F_165 ( V_368 , V_364 ) ) {
V_103 = - V_370 ;
break;
}
}
return V_103 ;
}
static int F_332 ( struct V_8 * V_16 )
{
int V_103 ;
union V_831 V_832 ;
if ( V_16 -> V_840 ) {
V_103 = F_333 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_101 ,
V_103 ) ;
return V_103 ;
}
}
V_832 . V_835 = 0 ;
V_832 . V_837 . V_841 = V_842 ;
V_832 . V_837 . V_838 = V_843 ;
F_181 ( V_832 . V_835 , & V_16 -> V_363 -> V_836 ) ;
V_103 = F_330 ( V_16 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_102 , V_103 ) ;
return V_103 ;
}
static int F_334 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_102 * V_844 ;
V_844 = F_79 ( sizeof( * V_844 ) , V_111 ) ;
if ( ! V_844 )
return - V_44 ;
V_103 = F_69 ( V_16 , V_844 ) ;
if ( V_103 )
goto V_112;
memcpy ( V_16 -> V_805 , V_844 -> V_805 ,
sizeof( V_844 -> V_805 ) ) ;
V_16 -> V_805 [ sizeof( V_844 -> V_805 ) ] = '\0' ;
snprintf ( V_16 -> V_805 +
strlen ( V_16 -> V_805 ) ,
sizeof( V_16 -> V_805 ) ,
L_103 , F_100 ( & V_844 -> V_845 ) ) ;
V_112:
F_76 ( V_844 ) ;
return V_103 ;
}
static int F_335 ( struct V_8 * V_16 )
{
T_2 V_846 ;
T_2 V_847 ;
void T_8 * V_848 ;
struct V_849 * V_850 ;
struct V_851 * V_852 ;
V_846 = V_16 -> V_853 ;
V_850 = F_79 ( V_846 , V_111 ) ;
if ( ! V_850 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_104 ) ;
return - V_44 ;
}
V_848 = V_16 -> V_595 +
V_16 -> V_854 ;
F_336 ( V_850 , V_848 , V_846 ) ;
V_847 =
F_58 ( & V_850 -> V_855 ) ;
while ( V_847 ) {
V_852 = ( void * ) V_850 + V_847 ;
switch ( F_100 ( & V_852 -> V_856 ) ) {
case V_857 :
if ( V_858 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_105 ) ;
else
V_16 -> V_35 =
V_848 +
V_847 +
F_61 (
struct V_859 ,
V_35 ) ;
break;
}
V_847 =
F_100 ( & V_852 -> V_860 ) ;
}
F_76 ( V_850 ) ;
return 0 ;
}
static int F_337 ( struct V_8 * V_16 )
{
int V_103 ;
F_197 ( V_16 , V_533 ) ;
V_103 = F_332 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_338 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_106 , V_103 ) ;
return V_103 ;
}
F_17 ( V_16 , V_861 ) ;
return 0 ;
}
static int F_339 ( struct V_8 * V_16 )
{
if ( ! F_12 ( V_16 ) )
return - V_110 ;
if ( F_15 ( V_16 ) == V_861 )
return 0 ;
if ( F_340 ( V_16 ) ) {
F_17 ( V_16 , V_861 ) ;
return 0 ;
}
return F_337 ( V_16 ) ;
}
static int F_341 ( struct V_8 * V_16 )
{
int V_103 ;
V_103 = F_339 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_342 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_343 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_107 ) ;
return V_103 ;
}
V_103 = F_344 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_108 ) ;
return V_103 ;
}
if ( V_689 ) {
if ( V_16 -> V_687 >
V_862 )
V_16 -> V_687 =
V_862 ;
} else {
if ( V_16 -> V_687 >
V_863 )
V_16 -> V_687 =
V_863 ;
}
F_250 ( V_16 ) ;
V_103 = F_247 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_109 ) ;
return V_103 ;
}
V_103 = F_345 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_110 ) ;
return V_103 ;
}
V_103 = F_163 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_111 ) ;
return V_103 ;
}
V_16 -> V_864 = true ;
F_17 ( V_16 , V_865 ) ;
V_103 = F_335 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_218 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_112 ) ;
return V_103 ;
}
V_103 = F_219 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_113 ) ;
return V_103 ;
}
V_103 = F_236 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_114 ) ;
return V_103 ;
}
V_103 = F_237 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_252 ( V_16 ) ;
V_103 = F_208 ( V_16 ) ;
if ( V_103 )
return V_103 ;
if ( V_16 -> V_544 < V_16 -> V_549 ) {
V_16 -> V_698 =
V_16 -> V_544 ;
F_252 ( V_16 ) ;
}
V_103 = F_248 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_212 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_115 ) ;
return V_103 ;
}
F_215 ( V_16 ) ;
V_103 = F_203 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_241 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_197 ( V_16 , V_531 ) ;
V_16 -> V_17 = true ;
F_188 ( V_16 ) ;
V_103 = F_243 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_116 ) ;
return V_103 ;
}
V_103 = F_322 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_334 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_117 ) ;
return V_103 ;
}
V_103 = F_78 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_118 ) ;
return V_103 ;
}
F_88 ( V_16 ) ;
F_113 ( V_16 ) ;
return 0 ;
}
static void F_346 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
struct V_579 * V_580 ;
struct V_515 * V_516 ;
V_580 = & V_16 -> V_580 ;
V_580 -> V_490 = 0 ;
V_580 -> V_461 = 0 ;
* V_580 -> V_457 = 0 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_549 ; V_52 ++ ) {
V_16 -> V_484 [ V_52 ] . V_490 [ V_489 ] = 0 ;
V_16 -> V_484 [ V_52 ] . V_490 [ V_542 ] = 0 ;
V_16 -> V_484 [ V_52 ] . V_461 = 0 ;
* V_16 -> V_484 [ V_52 ] . V_482 [ V_489 ] = 0 ;
* V_16 -> V_484 [ V_52 ] . V_482 [ V_542 ] = 0 ;
* V_16 -> V_484 [ V_52 ] . V_457 = 0 ;
}
V_516 = & V_16 -> V_516 ;
* V_516 -> V_457 = 0 ;
V_516 -> V_461 = 0 ;
}
static int F_347 ( struct V_8 * V_16 )
{
int V_103 ;
V_103 = F_339 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_348 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_345 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_110 ) ;
return V_103 ;
}
V_103 = F_163 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_111 ) ;
return V_103 ;
}
V_16 -> V_864 = true ;
F_17 ( V_16 , V_865 ) ;
F_346 ( V_16 ) ;
V_103 = F_219 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_113 ) ;
return V_103 ;
}
V_103 = F_241 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_197 ( V_16 , V_531 ) ;
V_16 -> V_17 = true ;
F_188 ( V_16 ) ;
F_21 ( V_16 ) ;
V_103 = F_243 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_116 ) ;
return V_103 ;
}
V_103 = F_78 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_118 ) ;
return V_103 ;
}
F_88 ( V_16 ) ;
F_113 ( V_16 ) ;
return 0 ;
}
static inline int F_349 ( struct V_36 * V_36 ,
T_5 V_364 )
{
return F_350 ( V_36 , V_866 ,
V_867 , V_364 ) ;
}
static int F_351 ( struct V_8 * V_16 )
{
int V_103 ;
V_45 V_868 ;
V_103 = F_352 ( V_16 -> V_36 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_119 ) ;
return V_103 ;
}
if ( sizeof( T_4 ) > 4 )
V_868 = F_353 ( 64 ) ;
else
V_868 = F_353 ( 32 ) ;
V_103 = F_354 ( & V_16 -> V_36 -> V_88 , V_868 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 , L_120 ) ;
goto V_869;
}
V_103 = F_355 ( V_16 -> V_36 , V_545 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_121 ) ;
goto V_869;
}
V_16 -> V_595 = F_356 ( F_357 (
V_16 -> V_36 , 0 ) ,
sizeof( struct V_870 ) ) ;
if ( ! V_16 -> V_595 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_122 ) ;
V_103 = - V_44 ;
goto V_871;
}
#define F_358 0x6
V_103 = F_349 ( V_16 -> V_36 ,
F_358 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_123 ) ;
goto V_871;
}
F_359 ( V_16 -> V_36 ) ;
V_16 -> V_872 = V_16 -> V_595 ;
V_16 -> V_363 = & V_16 -> V_872 -> V_363 ;
F_360 ( V_16 -> V_36 , V_16 ) ;
return 0 ;
V_871:
F_361 ( V_16 -> V_36 ) ;
V_869:
F_362 ( V_16 -> V_36 ) ;
return V_103 ;
}
static void F_363 ( struct V_8 * V_16 )
{
F_364 ( V_16 -> V_595 ) ;
F_361 ( V_16 -> V_36 ) ;
if ( F_365 ( V_16 -> V_36 ) )
F_362 ( V_16 -> V_36 ) ;
F_360 ( V_16 -> V_36 , NULL ) ;
}
static struct V_8 * F_366 ( int V_873 )
{
struct V_8 * V_16 ;
V_16 = F_367 ( sizeof( struct V_8 ) ,
V_111 , V_873 ) ;
if ( ! V_16 )
return NULL ;
F_368 ( & V_16 -> V_303 ) ;
F_368 ( & V_16 -> V_305 ) ;
F_217 ( & V_16 -> V_283 ) ;
F_216 ( & V_16 -> V_272 ) ;
F_369 ( & V_16 -> V_500 , F_185 ) ;
F_370 ( & V_16 -> V_504 , 0 ) ;
F_371 ( & V_16 -> V_33 , F_112 ) ;
F_371 ( & V_16 -> V_137 , F_84 ) ;
F_372 ( & V_16 -> V_508 ) ;
F_369 ( & V_16 -> V_874 , V_875 ) ;
F_373 ( & V_16 -> V_617 ,
V_876 ) ;
F_374 ( & V_16 -> V_23 ) ;
F_217 ( & V_16 -> V_726 ) ;
F_216 ( & V_16 -> V_725 ) ;
F_369 ( & V_16 -> V_723 ,
F_275 ) ;
V_16 -> V_813 = F_67 ( & V_877 ) - 1 ;
V_16 -> V_530 = V_533 ;
V_16 -> V_698 = V_878 ;
return V_16 ;
}
static inline void F_375 ( struct V_8 * V_16 )
{
F_76 ( V_16 ) ;
}
static void F_376 ( struct V_8 * V_16 )
{
F_206 ( V_16 ) ;
F_210 ( V_16 ) ;
}
static void F_377 ( struct V_8 * V_16 )
{
F_190 ( V_16 ) ;
F_376 ( V_16 ) ;
if ( V_16 -> V_564 )
F_246 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_566 ,
V_16 -> V_564 ,
V_16 -> V_565 ) ;
if ( V_16 -> V_581 )
F_246 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_583 ,
V_16 -> V_581 ,
V_16 -> V_582 ) ;
F_245 ( V_16 ) ;
if ( V_16 -> V_469 )
F_246 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_682 ,
V_16 -> V_469 ,
V_16 -> V_683 ) ;
if ( V_16 -> V_595 )
F_363 ( V_16 ) ;
F_375 ( V_16 ) ;
}
static void F_378 ( struct V_8 * V_16 )
{
F_46 ( V_16 ) ;
F_89 ( V_16 ) ;
F_144 ( V_16 ) ;
F_328 ( V_16 ) ;
if ( V_16 -> V_864 )
F_337 ( V_16 ) ;
F_377 ( V_16 ) ;
}
static void F_379 ( void )
{
switch ( V_807 ) {
case V_879 :
F_380 ( L_124 ) ;
break;
case V_880 :
F_381 () ;
break;
case V_881 :
default:
break;
}
}
static void F_382 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
struct V_93 * V_94 ;
struct V_3 * V_4 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_101 ; V_52 ++ ) {
V_94 = & V_16 -> V_99 [ V_52 ] ;
if ( F_36 ( & V_94 -> V_100 ) == 0 )
continue;
V_4 = V_94 -> V_4 ;
if ( V_4 ) {
F_175 ( V_4 , V_424 ) ;
} else {
V_94 -> V_95 = - V_110 ;
V_94 -> V_96 =
& V_882 ;
}
V_94 -> V_472 ( V_94 ,
V_94 -> V_473 ) ;
}
}
static void F_383 ( struct V_8 * V_16 )
{
F_379 () ;
F_190 ( V_16 ) ;
F_376 ( V_16 ) ;
F_46 ( V_16 ) ;
F_89 ( V_16 ) ;
F_35 ( V_16 ) ;
F_382 ( V_16 ) ;
F_276 ( V_16 ) ;
F_21 ( V_16 ) ;
}
static void V_875 ( struct V_135 * V_136 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( V_136 , struct V_8 , V_874 ) ;
F_383 ( V_16 ) ;
}
static void F_13 ( struct V_8 * V_16 )
{
if ( ! V_16 -> V_17 )
return;
V_16 -> V_17 = false ;
V_16 -> V_864 = false ;
F_19 ( V_16 ) ;
if ( ! V_883 )
F_384 ( V_16 ) ;
F_362 ( V_16 -> V_36 ) ;
F_64 ( & V_16 -> V_36 -> V_88 , L_125 ) ;
F_195 ( & V_16 -> V_874 ) ;
}
static void F_385 ( struct V_36 * V_36 ,
const struct V_884 * V_885 )
{
char * V_886 ;
if ( V_885 -> V_887 )
V_886 = ( char * ) V_885 -> V_887 ;
else
V_886 = L_126 ;
F_111 ( & V_36 -> V_88 , L_127 , V_886 ) ;
}
static int F_386 ( struct V_36 * V_36 ,
const struct V_884 * V_885 )
{
int V_103 ;
int V_888 ;
struct V_8 * V_16 ;
F_385 ( V_36 , V_885 ) ;
if ( V_889 &&
V_885 -> V_890 == V_891 &&
V_885 -> V_892 == V_891 ) {
F_87 ( & V_36 -> V_88 ,
L_128 ) ;
return - V_811 ;
}
if ( V_885 -> V_890 == V_891 || V_885 -> V_892 == V_891 )
F_87 ( & V_36 -> V_88 ,
L_129 ) ;
V_888 = F_387 ( & V_36 -> V_88 ) ;
if ( V_888 == V_893 )
F_388 ( & V_36 -> V_88 , 0 ) ;
V_16 = F_366 ( V_888 ) ;
if ( ! V_16 ) {
F_64 ( & V_36 -> V_88 ,
L_130 ) ;
return - V_44 ;
}
V_16 -> V_36 = V_36 ;
V_103 = F_351 ( V_16 ) ;
if ( V_103 )
goto error;
V_103 = F_341 ( V_16 ) ;
if ( V_103 )
goto error;
return 0 ;
error:
F_378 ( V_16 ) ;
return V_103 ;
}
static void F_389 ( struct V_36 * V_36 )
{
struct V_8 * V_16 ;
V_16 = F_390 ( V_36 ) ;
if ( ! V_16 )
return;
F_378 ( V_16 ) ;
}
static void F_391 ( struct V_36 * V_36 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_390 ( V_36 ) ;
if ( ! V_16 )
goto error;
V_103 = F_74 ( V_16 , V_894 ) ;
F_332 ( V_16 ) ;
if ( V_103 == 0 )
return;
error:
F_87 ( & V_36 -> V_88 ,
L_131 ) ;
}
static void F_392 ( void )
{
unsigned int V_52 ;
if ( ! V_895 )
return;
for ( V_52 = 0 ; V_52 < F_2 ( V_806 ) ; V_52 ++ ) {
if ( strcmp ( V_895 ,
V_806 [ V_52 ] . V_808 ) == 0 ) {
V_807 = V_806 [ V_52 ] . V_262 ;
return;
}
}
F_393 ( L_132 ,
V_545 , V_895 ) ;
}
static void F_394 ( void )
{
F_392 () ;
}
static T_14 int F_395 ( struct V_36 * V_36 , T_15 V_896 )
{
struct V_8 * V_16 ;
V_16 = F_390 ( V_36 ) ;
F_244 ( V_16 ) ;
F_89 ( V_16 ) ;
F_46 ( V_16 ) ;
F_151 ( V_16 ) ;
F_152 ( V_16 ) ;
F_74 ( V_16 , V_897 ) ;
F_19 ( V_16 ) ;
F_35 ( V_16 ) ;
F_286 ( V_16 ) ;
F_289 ( V_16 ) ;
F_190 ( V_16 ) ;
if ( V_896 . V_495 == V_898 )
return 0 ;
F_396 ( V_36 ) ;
F_397 ( V_36 , F_398 ( V_36 , V_896 ) ) ;
V_16 -> V_17 = false ;
V_16 -> V_864 = false ;
return 0 ;
}
static T_14 int F_399 ( struct V_36 * V_36 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_390 ( V_36 ) ;
if ( V_36 -> V_899 != V_900 ) {
V_16 -> V_699 = 0 ;
F_376 ( V_16 ) ;
F_197 ( V_16 , V_532 ) ;
V_103 = F_205 ( F_204 ( V_36 , 0 ) , F_201 ,
V_901 , V_545 ,
& V_16 -> V_484 [ 0 ] ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_68 ,
V_36 -> V_538 , V_103 ) ;
return V_103 ;
}
F_188 ( V_16 ) ;
F_21 ( V_16 ) ;
return 0 ;
}
F_397 ( V_36 , V_900 ) ;
F_400 ( V_36 ) ;
return F_347 ( V_16 ) ;
}
static int T_16 F_401 ( void )
{
int V_103 ;
F_402 ( V_902 L_95 ) ;
V_826 =
F_403 ( & V_903 ) ;
if ( ! V_826 )
return - V_811 ;
F_394 () ;
V_103 = F_404 ( & V_904 ) ;
if ( V_103 )
F_405 ( V_826 ) ;
return V_103 ;
}
static void T_17 F_406 ( void )
{
F_407 ( & V_904 ) ;
F_405 ( V_826 ) ;
}
