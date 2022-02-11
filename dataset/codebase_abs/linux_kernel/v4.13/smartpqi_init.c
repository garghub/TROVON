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
static int F_74 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_53 V_54 ;
int V_57 ;
T_1 * V_39 ;
if ( F_10 ( V_16 ) )
return - V_106 ;
V_39 = F_75 ( V_107 , V_108 ) ;
if ( ! V_39 )
return - V_44 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_80 , V_18 , V_39 ,
V_107 , 0 , & V_57 ) ;
if ( V_103 )
goto V_109;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
V_109:
F_76 ( V_39 ) ;
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
struct V_110 * V_39 ;
T_3 V_40 ;
V_40 = sizeof( * V_39 ) ;
V_39 = F_79 ( V_40 , V_108 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_111 [ 0 ] = '<' ;
V_39 -> V_111 [ 1 ] = 'H' ;
V_39 -> V_111 [ 2 ] = 'W' ;
V_39 -> V_111 [ 3 ] = '>' ;
V_39 -> V_112 [ 0 ] = 'D' ;
V_39 -> V_112 [ 1 ] = 'V' ;
F_60 ( sizeof( V_39 -> V_113 ) ,
& V_39 -> V_114 ) ;
strncpy ( V_39 -> V_113 , L_3 V_115 ,
sizeof( V_39 -> V_113 ) - 1 ) ;
V_39 -> V_113 [ sizeof( V_39 -> V_113 ) - 1 ] = '\0' ;
V_39 -> V_116 [ 0 ] = 'Z' ;
V_39 -> V_116 [ 1 ] = 'Z' ;
V_103 = F_77 ( V_16 , V_39 , V_40 ) ;
F_76 ( V_39 ) ;
return V_103 ;
}
static int F_80 (
struct V_8 * V_16 )
{
int V_103 ;
struct V_117 * V_39 ;
T_3 V_40 ;
T_6 V_118 ;
unsigned int V_119 ;
struct V_120 V_120 ;
V_40 = sizeof( * V_39 ) ;
V_39 = F_79 ( V_40 , V_108 ) ;
if ( ! V_39 )
return - V_44 ;
V_39 -> V_111 [ 0 ] = '<' ;
V_39 -> V_111 [ 1 ] = 'H' ;
V_39 -> V_111 [ 2 ] = 'W' ;
V_39 -> V_111 [ 3 ] = '>' ;
V_39 -> V_121 [ 0 ] = 'T' ;
V_39 -> V_121 [ 1 ] = 'D' ;
F_60 ( sizeof( V_39 -> time ) ,
& V_39 -> V_122 ) ;
V_118 = F_81 () ;
F_82 ( V_118 , - V_123 . V_124 * 60 , & V_120 ) ;
V_119 = V_120 . V_125 + 1900 ;
V_39 -> time [ 0 ] = F_83 ( V_120 . V_126 ) ;
V_39 -> time [ 1 ] = F_83 ( V_120 . V_127 ) ;
V_39 -> time [ 2 ] = F_83 ( V_120 . V_128 ) ;
V_39 -> time [ 3 ] = 0 ;
V_39 -> time [ 4 ] = F_83 ( V_120 . V_129 + 1 ) ;
V_39 -> time [ 5 ] = F_83 ( V_120 . V_130 ) ;
V_39 -> time [ 6 ] = F_83 ( V_119 / 100 ) ;
V_39 -> time [ 7 ] = F_83 ( V_119 % 100 ) ;
V_39 -> V_131 [ 0 ] = 'D' ;
V_39 -> V_131 [ 1 ] = 'W' ;
V_39 -> V_116 [ 0 ] = 'Z' ;
V_39 -> V_116 [ 1 ] = 'Z' ;
V_103 = F_77 ( V_16 , V_39 , V_40 ) ;
F_76 ( V_39 ) ;
return V_103 ;
}
static void F_84 ( struct V_132 * V_133 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_85 ( F_86 ( V_133 ) , struct V_8 ,
V_134 ) ;
if ( F_10 ( V_16 ) )
return;
V_103 = F_80 ( V_16 ) ;
if ( V_103 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_4 ) ;
F_43 ( & V_16 -> V_134 ,
V_135 ) ;
}
static inline void F_88 (
struct V_8 * V_16 )
{
F_43 ( & V_16 -> V_134 , 0 ) ;
}
static inline void F_89 (
struct V_8 * V_16 )
{
F_47 ( & V_16 -> V_134 ) ;
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
T_3 V_136 ;
T_3 V_137 ;
T_3 V_138 ;
void * V_139 = NULL ;
struct V_140 * V_140 ;
V_140 = F_79 ( sizeof( * V_140 ) , V_108 ) ;
if ( ! V_140 ) {
V_103 = - V_44 ;
goto V_109;
}
V_103 = F_90 ( V_16 , V_55 , V_140 ,
sizeof( * V_140 ) ) ;
if ( V_103 )
goto V_109;
V_136 = F_92 ( & V_140 -> V_141 ) ;
V_142:
V_137 = sizeof( struct V_140 ) + V_136 ;
V_139 = F_79 ( V_137 , V_108 ) ;
if ( ! V_139 ) {
V_103 = - V_44 ;
goto V_109;
}
if ( V_136 == 0 ) {
memcpy ( V_139 , V_140 , sizeof( * V_140 ) ) ;
goto V_109;
}
V_103 = F_90 ( V_16 , V_55 , V_139 , V_137 ) ;
if ( V_103 )
goto V_109;
V_138 = F_92 (
& ( (struct V_140 * ) V_139 ) -> V_141 ) ;
if ( V_138 > V_136 ) {
V_136 = V_138 ;
F_76 ( V_139 ) ;
goto V_142;
}
V_109:
F_76 ( V_140 ) ;
if ( V_103 ) {
F_76 ( V_139 ) ;
V_139 = NULL ;
}
* V_39 = V_139 ;
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
struct V_143 * * V_144 ,
struct V_145 * * V_146 )
{
int V_103 ;
T_3 V_147 ;
T_3 V_148 ;
struct V_145 * V_149 ;
struct V_145 * V_150 ;
struct V_140 V_140 ;
V_103 = F_93 ( V_16 , ( void * * ) V_144 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_5 ) ;
V_103 = F_94 ( V_16 , ( void * * ) V_146 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_6 ) ;
V_150 = * V_146 ;
if ( V_150 ) {
V_147 =
F_92 ( & V_150 -> V_60 . V_141 ) ;
} else {
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_150 =
(struct V_145 * ) & V_140 ;
V_147 = 0 ;
}
V_148 = sizeof( struct V_140 ) +
V_147 ;
V_149 = F_79 ( V_148 +
sizeof( struct V_145 ) , V_108 ) ;
if ( ! V_149 ) {
F_76 ( * V_146 ) ;
* V_146 = NULL ;
return - V_44 ;
}
memcpy ( V_149 , V_150 , V_148 ) ;
memset ( ( T_1 * ) V_149 + V_148 , 0 ,
sizeof( struct V_151 ) ) ;
F_62 ( V_147 +
sizeof( struct V_151 ) ,
& V_149 -> V_60 . V_141 ) ;
F_76 ( * V_146 ) ;
* V_146 = V_149 ;
return 0 ;
}
static inline void F_96 ( struct V_12 * V_13 ,
int V_152 , int V_153 , int V_154 )
{
V_13 -> V_152 = V_152 ;
V_13 -> V_153 = V_153 ;
V_13 -> V_154 = V_154 ;
}
static void F_97 ( struct V_12 * V_13 )
{
T_1 * V_15 ;
T_2 V_155 ;
int V_152 ;
int V_153 ;
int V_154 ;
V_15 = V_13 -> V_15 ;
V_155 = F_58 ( V_15 ) ;
if ( F_14 ( V_15 ) ) {
F_96 ( V_13 , V_156 , 0 , V_155 & 0x3fff ) ;
V_13 -> V_157 = true ;
return;
}
if ( F_8 ( V_13 ) ) {
if ( V_13 -> V_158 ) {
V_152 = V_159 ;
V_153 = ( V_155 >> 16 ) & 0x3fff ;
V_154 = V_155 & 0xff ;
} else {
V_152 = V_160 ;
V_153 = 0 ;
V_154 = V_155 & 0x3fff ;
}
F_96 ( V_13 , V_152 , V_153 , V_154 ) ;
V_13 -> V_157 = true ;
return;
}
F_96 ( V_13 , V_161 , 0 , 0 ) ;
}
static void F_98 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 V_1 ;
T_1 * V_39 ;
V_1 = V_162 ;
V_39 = F_79 ( 64 , V_108 ) ;
if ( V_39 ) {
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_163 , V_39 , 64 ) ;
if ( V_103 == 0 ) {
V_1 = V_39 [ 8 ] ;
if ( V_1 > V_164 )
V_1 = V_162 ;
}
F_76 ( V_39 ) ;
}
V_13 -> V_1 = V_1 ;
}
static int F_99 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_165 * V_165 )
{
char * V_166 ;
T_2 V_167 ;
T_2 V_168 ;
unsigned int V_169 ;
unsigned int V_170 ;
V_167 = F_58 ( & V_165 -> V_171 ) ;
if ( V_167 < F_61 ( struct V_165 , V_172 ) ) {
V_166 = L_7 ;
goto V_173;
}
if ( V_167 > sizeof( * V_165 ) ) {
V_166 = L_8 ;
goto V_173;
}
V_169 = F_100 ( & V_165 -> V_174 ) *
( F_100 ( & V_165 -> V_175 ) +
F_100 ( & V_165 -> V_176 ) ) ;
V_170 = V_169 *
F_100 ( & V_165 -> V_177 ) ;
if ( V_170 > V_178 ) {
V_166 = L_9 ;
goto V_173;
}
if ( V_13 -> V_1 == V_179 ) {
if ( F_100 ( & V_165 -> V_174 ) != 2 ) {
V_166 = L_10 ;
goto V_173;
}
} else if ( V_13 -> V_1 == V_180 ) {
if ( F_100 ( & V_165 -> V_174 ) != 3 ) {
V_166 = L_11 ;
goto V_173;
}
} else if ( ( V_13 -> V_1 == V_181 ||
V_13 -> V_1 == V_182 ) &&
F_100 ( & V_165 -> V_174 ) > 1 ) {
V_168 =
F_100 ( & V_165 -> V_183 ) *
F_100 ( & V_165 -> V_175 ) ;
if ( V_168 == 0 ) {
V_166 = L_12 ;
goto V_173;
}
}
return 0 ;
V_173:
F_87 ( & V_16 -> V_36 -> V_88 ,
L_13 ,
V_16 -> V_22 -> V_184 ,
V_13 -> V_152 , V_13 -> V_153 , V_13 -> V_154 , V_166 ) ;
return - V_185 ;
}
static int F_101 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
int V_57 ;
struct V_53 V_54 ;
struct V_165 * V_165 ;
V_165 = F_79 ( sizeof( * V_165 ) , V_108 ) ;
if ( ! V_165 )
return - V_44 ;
V_103 = F_59 ( V_16 , & V_54 ,
V_78 , V_13 -> V_15 , V_165 ,
sizeof( * V_165 ) , 0 , & V_57 ) ;
if ( V_103 )
goto error;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_57 ) ;
if ( V_103 )
goto error;
V_103 = F_99 ( V_16 , V_13 , V_165 ) ;
if ( V_103 )
goto error;
V_13 -> V_165 = V_165 ;
return 0 ;
error:
F_76 ( V_165 ) ;
return V_103 ;
}
static void F_102 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 * V_39 ;
T_1 V_186 ;
V_39 = F_79 ( 64 , V_108 ) ;
if ( ! V_39 )
return;
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_187 , V_39 , 64 ) ;
if ( V_103 )
goto V_109;
#define F_103 4
#define F_104 0x1
#define F_105 0x2
V_186 = V_39 [ F_103 ] ;
V_13 -> V_188 =
( V_186 & F_104 ) != 0 ;
if ( V_13 -> V_188 &&
( V_186 & F_105 ) &&
F_101 ( V_16 , V_13 ) == 0 )
V_13 -> V_189 = true ;
V_109:
F_76 ( V_39 ) ;
}
static void F_106 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_3 V_190 ;
T_1 V_191 = V_192 ;
bool V_193 = true ;
T_2 V_194 ;
struct V_195 * V_196 ;
V_196 = F_79 ( sizeof( * V_196 ) , V_108 ) ;
if ( ! V_196 )
goto V_197;
V_103 = F_71 ( V_16 , V_13 -> V_15 ,
V_73 | V_198 , V_196 , sizeof( * V_196 ) ) ;
if ( V_103 )
goto V_109;
V_190 = F_61 ( struct V_195 ,
V_191 ) + V_196 -> V_190 ;
if ( V_190 < sizeof( * V_196 ) )
goto V_109;
V_191 = V_196 -> V_191 ;
V_194 = F_92 ( & V_196 -> V_49 ) ;
V_193 = ( V_194 & V_199 ) != 0 ;
V_109:
F_76 ( V_196 ) ;
V_197:
V_13 -> V_191 = V_191 ;
V_13 -> V_193 = V_193 ;
}
static int F_107 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
T_1 * V_39 ;
V_39 = F_79 ( 64 , V_108 ) ;
if ( ! V_39 )
return - V_44 ;
V_103 = F_71 ( V_16 , V_13 -> V_15 , 0 , V_39 , 64 ) ;
if ( V_103 )
goto V_109;
F_108 ( & V_39 [ 8 ] , 8 ) ;
F_108 ( & V_39 [ 16 ] , 16 ) ;
V_13 -> V_200 = V_39 [ 0 ] & 0x1f ;
memcpy ( V_13 -> V_201 , & V_39 [ 8 ] , sizeof( V_13 -> V_201 ) ) ;
memcpy ( V_13 -> V_202 , & V_39 [ 16 ] , sizeof( V_13 -> V_202 ) ) ;
if ( F_8 ( V_13 ) && V_13 -> V_200 == V_203 ) {
if ( V_13 -> V_158 ) {
V_13 -> V_1 = V_162 ;
V_13 -> V_191 = V_204 ;
V_13 -> V_193 = false ;
} else {
F_98 ( V_16 , V_13 ) ;
F_102 ( V_16 , V_13 ) ;
F_106 ( V_16 , V_13 ) ;
}
}
V_109:
F_76 ( V_39 ) ;
return V_103 ;
}
static void F_109 ( struct V_8 * V_16 ,
struct V_12 * V_13 ,
struct V_104 * V_205 )
{
int V_103 ;
memset ( V_205 , 0 , sizeof( * V_205 ) ) ;
V_103 = F_72 ( V_16 , V_13 ,
V_205 , sizeof( * V_205 ) ) ;
if ( V_103 ) {
V_13 -> V_206 = V_207 ;
return;
}
V_13 -> V_206 =
F_100 ( & V_205 -> V_208 ) ;
V_13 -> V_209 = V_205 -> V_209 ;
V_13 -> V_210 = V_205 -> V_211 ;
V_13 -> V_212 = V_205 -> V_213 ;
memcpy ( & V_13 -> V_214 ,
& V_205 -> V_215 ,
sizeof( V_13 -> V_214 ) ) ;
memcpy ( & V_13 -> V_216 ,
& V_205 -> V_217 ,
sizeof( V_13 -> V_216 ) ) ;
V_13 -> V_218 = V_205 -> V_219 ;
}
static void F_110 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
char * V_95 ;
static const char V_220 [] =
L_14 ;
char V_221 [ sizeof( V_220 ) + 10 ] ;
switch ( V_13 -> V_191 ) {
case V_204 :
V_95 = L_15 ;
break;
case V_222 :
V_95 = L_16 ;
break;
case V_223 :
V_95 = L_17 ;
break;
case V_224 :
V_95 = L_18 ;
break;
case V_225 :
V_95 = L_19 ;
break;
case V_226 :
V_95 = L_20 ;
break;
case V_227 :
V_95 = L_21 ;
break;
case V_228 :
V_95 = L_22 ;
break;
case V_229 :
V_95 = L_23 ;
break;
case V_230 :
V_95 = L_24 ;
break;
case V_231 :
V_95 = L_25 ;
break;
case V_232 :
V_95 = L_26 ;
break;
case V_233 :
V_95 = L_27 ;
break;
case V_234 :
V_95 = L_28 ;
break;
case V_235 :
V_95 = L_29 ;
break;
case V_236 :
V_95 = L_30 ;
break;
case V_237 :
V_95 = L_31 ;
break;
case V_238 :
V_95 = L_32 ;
break;
case V_239 :
V_95 = L_33 ;
break;
case V_240 :
V_95 = L_34 ;
break;
case V_241 :
V_95 = L_35 ;
break;
case V_242 :
V_95 = L_36 ;
break;
case V_243 :
V_95 = L_37 ;
break;
case V_244 :
V_95 = L_38 ;
break;
case V_245 :
V_95 = L_39 ;
break;
case V_246 :
V_95 = L_40 ;
break;
case V_192 :
V_95 = L_41 ;
break;
default:
snprintf ( V_221 , sizeof( V_221 ) ,
V_220 , V_13 -> V_191 ) ;
V_95 = V_221 ;
break;
}
F_111 ( & V_16 -> V_36 -> V_88 ,
L_13 ,
V_16 -> V_22 -> V_184 ,
V_13 -> V_152 , V_13 -> V_153 , V_13 -> V_154 , V_95 ) ;
}
static void F_112 ( struct V_132 * V_133 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( F_86 ( V_133 ) , struct V_8 ,
V_33 ) ;
F_113 ( V_16 ) ;
}
static int F_114 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
if ( F_8 ( V_13 ) )
V_103 = F_115 ( V_16 -> V_22 , V_13 -> V_152 ,
V_13 -> V_153 , V_13 -> V_154 ) ;
else
V_103 = F_116 ( V_16 -> V_247 , V_13 ) ;
return V_103 ;
}
static inline void F_117 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
if ( F_8 ( V_13 ) )
F_118 ( V_13 -> V_248 ) ;
else
F_119 ( V_13 ) ;
}
static struct V_12 * F_120 ( struct V_8 * V_16 ,
int V_152 , int V_153 , int V_154 )
{
struct V_12 * V_13 ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
if ( V_13 -> V_152 == V_152 && V_13 -> V_153 == V_153 &&
V_13 -> V_154 == V_154 )
return V_13 ;
return NULL ;
}
static inline bool F_122 ( struct V_12 * V_249 ,
struct V_12 * V_250 )
{
if ( V_249 -> V_14 != V_250 -> V_14 )
return false ;
if ( V_249 -> V_14 )
return V_249 -> V_251 == V_250 -> V_251 ;
return memcmp ( V_249 -> V_252 , V_250 -> V_252 ,
sizeof( V_249 -> V_252 ) ) == 0 ;
}
static enum V_253 F_123 ( struct V_8 * V_16 ,
struct V_12 * V_254 ,
struct V_12 * * V_255 )
{
struct V_12 * V_13 ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_5 ( V_254 -> V_15 ,
V_13 -> V_15 ) ) {
* V_255 = V_13 ;
if ( F_122 ( V_254 , V_13 ) ) {
if ( V_254 -> V_193 )
return V_256 ;
return V_257 ;
}
return V_256 ;
}
}
return V_258 ;
}
static void F_124 ( struct V_8 * V_16 ,
char * V_259 , struct V_12 * V_13 )
{
T_7 V_260 ;
char V_39 [ V_261 ] ;
V_260 = snprintf ( V_39 , V_261 ,
L_42 , V_16 -> V_22 -> V_184 , V_13 -> V_152 ) ;
if ( V_13 -> V_157 )
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_43 ,
V_13 -> V_153 ,
V_13 -> V_154 ) ;
else
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_44 ) ;
if ( F_8 ( V_13 ) )
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_45 ,
* ( ( T_2 * ) & V_13 -> V_15 ) ,
* ( ( T_2 * ) & V_13 -> V_15 [ 4 ] ) ) ;
else
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_46 , V_13 -> V_262 ) ;
V_260 += snprintf ( V_39 + V_260 , V_261 - V_260 ,
L_47 ,
F_125 ( V_13 -> V_200 ) ,
V_13 -> V_201 ,
V_13 -> V_202 ) ;
if ( F_8 ( V_13 ) ) {
if ( V_13 -> V_200 == V_203 )
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_48 ,
V_13 -> V_188 ? '+' : '-' ,
V_13 -> V_189 ? '+' : '-' ,
F_1 ( V_13 -> V_1 ) ) ;
} else {
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_49 , V_13 -> V_263 ? '+' : '-' ) ;
if ( V_13 -> V_200 == V_203 ||
V_13 -> V_200 == V_264 )
V_260 += snprintf ( V_39 + V_260 ,
V_261 - V_260 ,
L_50 , V_13 -> V_206 ) ;
}
F_111 ( & V_16 -> V_36 -> V_88 , L_51 , V_259 , V_39 ) ;
}
static void F_126 ( struct V_12 * V_265 ,
struct V_12 * V_266 )
{
V_265 -> V_200 = V_266 -> V_200 ;
V_265 -> V_209 = V_266 -> V_209 ;
V_265 -> V_152 = V_266 -> V_152 ;
if ( V_266 -> V_157 ) {
V_265 -> V_153 = V_266 -> V_153 ;
V_265 -> V_154 = V_266 -> V_154 ;
V_265 -> V_157 = true ;
}
V_265 -> V_14 = V_266 -> V_14 ;
V_265 -> V_158 =
V_266 -> V_158 ;
V_265 -> V_263 = V_266 -> V_263 ;
memcpy ( V_265 -> V_201 , V_266 -> V_201 ,
sizeof( V_265 -> V_201 ) ) ;
memcpy ( V_265 -> V_202 , V_266 -> V_202 ,
sizeof( V_265 -> V_202 ) ) ;
V_265 -> V_262 = V_266 -> V_262 ;
V_265 -> V_1 = V_266 -> V_1 ;
V_265 -> V_206 = V_266 -> V_206 ;
V_265 -> V_267 = V_266 -> V_267 ;
V_265 -> V_191 = V_266 -> V_191 ;
V_265 -> V_210 = V_266 -> V_210 ;
V_265 -> V_212 = V_266 -> V_212 ;
V_265 -> V_218 = V_266 -> V_218 ;
memcpy ( V_265 -> V_214 , V_266 -> V_214 ,
sizeof( V_265 -> V_214 ) ) ;
memcpy ( V_265 -> V_216 , V_266 -> V_216 ,
sizeof( V_265 -> V_216 ) ) ;
V_265 -> V_268 = 0 ;
F_76 ( V_265 -> V_165 ) ;
V_265 -> V_165 = V_266 -> V_165 ;
V_265 -> V_188 =
V_266 -> V_188 ;
V_265 -> V_189 =
V_266 -> V_189 ;
V_266 -> V_165 = NULL ;
}
static inline void F_127 ( struct V_12 * V_13 )
{
if ( V_13 ) {
F_76 ( V_13 -> V_165 ) ;
F_76 ( V_13 ) ;
}
}
static inline void F_128 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
F_130 ( & V_13 -> V_270 ) ;
F_131 ( & V_16 -> V_269 , V_49 ) ;
V_13 -> V_271 = false ;
}
static void F_132 ( struct V_8 * V_16 ,
struct V_12 * V_272 [] , unsigned int V_273 )
{
int V_103 ;
unsigned int V_52 ;
unsigned long V_49 ;
enum V_253 V_274 ;
struct V_12 * V_13 ;
struct V_12 * V_275 ;
struct V_12 * V_255 ;
F_133 ( V_276 ) ;
F_133 ( V_277 ) ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry)
V_13 -> V_278 = true ;
for ( V_52 = 0 ; V_52 < V_273 ; V_52 ++ ) {
V_13 = V_272 [ V_52 ] ;
V_274 = F_123 ( V_16 , V_13 ,
& V_255 ) ;
switch ( V_274 ) {
case V_257 :
V_13 -> V_266 = false ;
V_255 -> V_278 = false ;
F_126 ( V_255 , V_13 ) ;
break;
case V_258 :
V_13 -> V_266 = true ;
break;
case V_256 :
V_13 -> V_266 = true ;
break;
}
}
F_134 (device, next, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_278 ) {
F_130 ( & V_13 -> V_270 ) ;
F_135 ( & V_13 -> V_279 , & V_277 ) ;
}
}
for ( V_52 = 0 ; V_52 < V_273 ; V_52 ++ ) {
V_13 = V_272 [ V_52 ] ;
if ( ! V_13 -> V_266 )
continue;
if ( V_13 -> V_193 )
continue;
F_135 ( & V_13 -> V_270 ,
& V_16 -> V_280 ) ;
F_135 ( & V_13 -> V_281 , & V_276 ) ;
V_13 -> V_271 = true ;
}
F_131 ( & V_16 -> V_269 , V_49 ) ;
F_134 (device, next, &delete_list,
delete_list_entry) {
if ( V_13 -> V_193 ) {
F_124 ( V_16 , L_52 , V_13 ) ;
F_110 ( V_16 , V_13 ) ;
} else {
F_124 ( V_16 , L_53 , V_13 ) ;
}
if ( V_13 -> V_248 )
F_117 ( V_16 , V_13 ) ;
F_130 ( & V_13 -> V_279 ) ;
F_127 ( V_13 ) ;
}
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( V_13 -> V_248 && V_13 -> V_206 !=
V_13 -> V_282 ) {
V_13 -> V_282 = V_13 -> V_206 ;
F_136 ( V_13 -> V_248 ,
V_13 -> V_282 ) ;
}
}
F_134 (device, next, &add_list, add_list_entry) {
if ( ! V_13 -> V_248 ) {
F_124 ( V_16 , L_54 , V_13 ) ;
V_103 = F_114 ( V_16 , V_13 ) ;
if ( V_103 ) {
F_87 ( & V_16 -> V_36 -> V_88 ,
L_55 ,
V_16 -> V_22 -> V_184 ,
V_13 -> V_152 , V_13 -> V_153 ,
V_13 -> V_154 ) ;
F_128 ( V_16 , V_13 ) ;
}
}
}
}
static bool F_137 ( struct V_12 * V_13 )
{
bool V_283 = false ;
switch ( V_13 -> V_200 ) {
case V_203 :
case V_264 :
case V_284 :
case V_285 :
case V_286 :
V_283 = true ;
break;
case V_287 :
if ( F_14 ( V_13 -> V_15 ) )
V_283 = true ;
break;
}
return V_283 ;
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
F_133 ( V_288 ) ;
struct V_143 * V_144 = NULL ;
struct V_145 * V_146 = NULL ;
struct V_289 * V_290 ;
struct V_151 * V_291 ;
struct V_104 * V_205 = NULL ;
T_2 V_292 ;
T_2 V_293 ;
struct V_12 * * V_272 = NULL ;
struct V_12 * V_13 ;
struct V_12 * V_275 ;
unsigned int V_273 ;
unsigned int V_294 ;
bool V_14 ;
T_1 * V_15 ;
static char * V_295 =
L_56 ;
V_103 = F_95 ( V_16 , & V_144 , & V_146 ) ;
if ( V_103 )
goto V_109;
if ( V_144 )
V_292 =
F_92 ( & V_144 -> V_60 . V_141 )
/ sizeof( V_144 -> V_296 [ 0 ] ) ;
else
V_292 = 0 ;
if ( V_146 )
V_293 =
F_92 ( & V_146 -> V_60 . V_141 )
/ sizeof( V_146 -> V_296 [ 0 ] ) ;
else
V_293 = 0 ;
if ( V_292 ) {
V_205 = F_79 ( sizeof( * V_205 ) , V_108 ) ;
if ( ! V_205 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_295 ) ;
V_103 = - V_44 ;
goto V_109;
}
}
V_273 = V_292 + V_293 ;
V_272 = F_79 ( sizeof( * V_272 ) *
V_273 , V_108 ) ;
if ( ! V_272 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 , V_295 ) ;
V_103 = - V_44 ;
goto V_109;
}
for ( V_52 = 0 ; V_52 < V_273 ; V_52 ++ ) {
V_13 = F_75 ( sizeof( * V_13 ) , V_108 ) ;
if ( ! V_13 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_295 ) ;
V_103 = - V_44 ;
goto V_109;
}
F_135 ( & V_13 -> V_297 ,
& V_288 ) ;
}
V_13 = NULL ;
V_294 = 0 ;
for ( V_52 = 0 ; V_52 < V_273 ; V_52 ++ ) {
if ( V_52 < V_292 ) {
V_14 = true ;
V_290 = & V_144 -> V_296 [ V_52 ] ;
V_291 = NULL ;
V_15 = V_290 -> V_155 ;
} else {
V_14 = false ;
V_290 = NULL ;
V_291 =
& V_146 -> V_296 [ V_52 - V_292 ] ;
V_15 = V_291 -> V_155 ;
}
if ( V_14 && F_138 ( V_15 ) )
continue;
if ( V_13 )
V_13 = F_141 ( V_13 , V_297 ) ;
else
V_13 = F_142 ( & V_288 ,
struct V_12 , V_297 ) ;
memcpy ( V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_13 -> V_14 = V_14 ;
if ( ! V_14 )
V_13 -> V_158 =
F_9 ( V_15 ) ;
V_103 = F_107 ( V_16 , V_13 ) ;
if ( V_103 == - V_44 ) {
F_87 ( & V_16 -> V_36 -> V_88 , L_57 ,
V_295 ) ;
goto V_109;
}
if ( V_103 ) {
if ( V_13 -> V_14 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_58 ,
F_143 (
& V_290 -> V_251 ) ) ;
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
V_13 -> V_251 = V_290 -> V_251 ;
if ( ( V_290 -> V_298 &
V_299 ) &&
V_290 -> V_267 )
V_13 -> V_263 = true ;
} else {
memcpy ( V_13 -> V_252 , V_291 -> V_252 ,
sizeof( V_13 -> V_252 ) ) ;
}
switch ( V_13 -> V_200 ) {
case V_203 :
case V_264 :
case V_286 :
if ( V_13 -> V_14 ) {
V_13 -> V_262 =
F_143 ( & V_13 -> V_251 ) ;
if ( V_13 -> V_200 == V_203 ||
V_13 -> V_200 == V_264 ) {
V_13 -> V_267 =
V_290 -> V_267 ;
F_109 ( V_16 ,
V_13 , V_205 ) ;
}
}
break;
}
V_272 [ V_294 ++ ] = V_13 ;
}
F_132 ( V_16 , V_272 , V_294 ) ;
V_109:
F_134 (device, next, &new_device_list_head,
new_device_list_entry) {
if ( V_13 -> V_271 )
continue;
F_130 ( & V_13 -> V_297 ) ;
F_127 ( V_13 ) ;
}
F_76 ( V_272 ) ;
F_76 ( V_144 ) ;
F_76 ( V_146 ) ;
F_76 ( V_205 ) ;
return V_103 ;
}
static void F_144 ( struct V_8 * V_16 )
{
unsigned long V_49 ;
struct V_12 * V_13 ;
while ( 1 ) {
F_129 ( & V_16 -> V_269 , V_49 ) ;
V_13 = F_145 ( & V_16 -> V_280 ,
struct V_12 , V_270 ) ;
if ( V_13 )
F_130 ( & V_13 -> V_270 ) ;
F_131 ( & V_16 -> V_269 ,
V_49 ) ;
if ( ! V_13 )
break;
if ( V_13 -> V_248 )
F_117 ( V_16 , V_13 ) ;
F_127 ( V_13 ) ;
}
}
static int F_113 ( struct V_8 * V_16 )
{
int V_103 ;
if ( F_10 ( V_16 ) )
return - V_106 ;
F_146 ( & V_16 -> V_300 ) ;
V_103 = F_140 ( V_16 ) ;
if ( V_103 )
F_45 ( V_16 ) ;
F_147 ( & V_16 -> V_300 ) ;
return V_103 ;
}
static void F_148 ( struct V_9 * V_10 )
{
F_113 ( F_6 ( V_10 ) ) ;
}
static int F_149 ( struct V_9 * V_10 ,
unsigned long V_301 )
{
struct V_8 * V_16 ;
V_16 = F_7 ( V_10 ) ;
return ! F_150 ( & V_16 -> V_300 ) ;
}
static void F_151 ( struct V_8 * V_16 )
{
F_146 ( & V_16 -> V_300 ) ;
F_147 ( & V_16 -> V_300 ) ;
}
static void F_152 ( struct V_8 * V_16 )
{
F_146 ( & V_16 -> V_302 ) ;
F_147 ( & V_16 -> V_302 ) ;
}
static inline void F_153 (
struct V_303 * V_304 , struct V_165 * V_165 ,
V_45 V_305 )
{
T_2 V_306 ;
V_306 = F_58 ( & V_165 -> V_306 ) ;
if ( V_306 != 512 )
V_305 = ( V_305 * V_306 ) / 512 ;
V_304 -> V_307 =
F_100 ( & V_165 -> V_307 ) ;
V_304 -> V_308 = F_154 ( V_305 ) ;
V_304 -> V_309 = F_155 ( V_305 ) ;
}
static int F_156 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_310 * V_311 )
{
struct V_165 * V_165 ;
bool V_312 = false ;
T_2 V_313 ;
V_45 V_305 ;
V_45 V_314 ;
T_2 V_315 ;
T_2 V_316 ;
V_45 V_317 ;
V_45 V_318 ;
T_2 V_319 ;
T_2 V_320 ;
T_2 V_321 ;
T_2 V_322 ;
V_45 V_323 ;
V_45 V_324 ;
T_2 V_168 ;
V_45 V_325 ;
V_45 V_326 ;
T_2 V_327 ;
T_2 V_328 ;
T_2 V_329 ;
T_2 V_330 ;
T_5 V_175 ;
T_2 V_331 ;
T_5 V_174 ;
T_2 V_332 ;
T_5 V_183 ;
T_2 V_333 ;
T_2 V_334 ;
T_2 V_335 ;
T_2 V_336 ;
T_2 V_267 ;
V_45 V_337 ;
T_2 V_338 ;
T_1 V_58 [ 16 ] ;
T_1 V_339 ;
int V_268 ;
struct V_303 * V_340 ;
struct V_303 V_304 ;
#if V_341 == 32
V_45 V_342 ;
#endif
switch ( V_4 -> V_343 [ 0 ] ) {
case V_344 :
V_312 = true ;
case V_345 :
V_305 = ( V_45 ) ( ( ( V_4 -> V_343 [ 1 ] & 0x1f ) << 16 ) |
( V_4 -> V_343 [ 2 ] << 8 ) | V_4 -> V_343 [ 3 ] ) ;
V_315 = ( T_2 ) V_4 -> V_343 [ 4 ] ;
if ( V_315 == 0 )
V_315 = 256 ;
break;
case V_346 :
V_312 = true ;
case V_347 :
V_305 = ( V_45 ) F_92 ( & V_4 -> V_343 [ 2 ] ) ;
V_315 = ( T_2 ) F_157 ( & V_4 -> V_343 [ 7 ] ) ;
break;
case V_348 :
V_312 = true ;
case V_349 :
V_305 = ( V_45 ) F_92 ( & V_4 -> V_343 [ 2 ] ) ;
V_315 = F_92 ( & V_4 -> V_343 [ 6 ] ) ;
break;
case V_350 :
V_312 = true ;
case V_351 :
V_305 = F_143 ( & V_4 -> V_343 [ 2 ] ) ;
V_315 = F_92 ( & V_4 -> V_343 [ 10 ] ) ;
break;
default:
return V_352 ;
}
if ( V_312 && V_13 -> V_1 != V_353 )
return V_352 ;
if ( F_158 ( V_315 == 0 ) )
return V_352 ;
V_314 = V_305 + V_315 - 1 ;
V_165 = V_13 -> V_165 ;
if ( V_314 >= F_57 ( & V_165 -> V_354 ) ||
V_314 < V_305 )
return V_352 ;
V_175 = F_100 ( & V_165 -> V_175 ) ;
V_183 = F_100 ( & V_165 -> V_183 ) ;
V_174 = F_100 ( & V_165 -> V_174 ) ;
V_316 = V_175 * V_183 ;
#if V_341 == 32
V_342 = V_305 ;
F_159 ( V_342 , V_316 ) ;
V_317 = V_342 ;
V_342 = V_314 ;
F_159 ( V_342 , V_316 ) ;
V_318 = V_342 ;
V_319 = ( T_2 ) ( V_305 - ( V_317 * V_316 ) ) ;
V_320 = ( T_2 ) ( V_314 - ( V_318 * V_316 ) ) ;
V_342 = V_319 ;
F_159 ( V_342 , V_183 ) ;
V_321 = V_342 ;
V_342 = V_320 ;
F_159 ( V_342 , V_183 ) ;
V_322 = V_342 ;
#else
V_317 = V_305 / V_316 ;
V_318 = V_314 / V_316 ;
V_319 = ( T_2 ) ( V_305 - ( V_317 * V_316 ) ) ;
V_320 = ( T_2 ) ( V_314 - ( V_318 * V_316 ) ) ;
V_321 = V_319 / V_183 ;
V_322 = V_320 / V_183 ;
#endif
if ( V_317 != V_318 || V_321 != V_322 )
return V_352 ;
V_331 = V_175 +
F_100 ( & V_165 -> V_176 ) ;
V_336 = ( ( T_2 ) ( V_317 >> V_165 -> V_355 ) ) %
F_100 ( & V_165 -> V_177 ) ;
V_313 = ( V_336 * V_331 ) + V_321 ;
if ( V_13 -> V_1 == V_179 ) {
if ( V_13 -> V_268 )
V_313 += V_175 ;
V_13 -> V_268 = ! V_13 -> V_268 ;
} else if ( V_13 -> V_1 == V_180 ) {
V_268 = V_13 -> V_268 ;
if ( V_268 == 0 ) {
V_313 %= V_175 ;
} else {
do {
V_335 = V_313 / V_175 ;
if ( V_268 != V_335 ) {
if ( V_335 <
V_174 - 1 ) {
V_313 += V_175 ;
V_335 ++ ;
} else {
V_313 %= V_175 ;
V_335 = 0 ;
}
}
} while ( V_268 != V_335 );
}
V_268 =
( V_268 >= V_174 - 1 ) ?
0 : V_268 + 1 ;
F_160 ( V_268 >= V_174 ) ;
V_13 -> V_268 = V_268 ;
} else if ( ( V_13 -> V_1 == V_181 ||
V_13 -> V_1 == V_182 ) && V_174 > 1 ) {
V_168 = V_183 * V_175 ;
V_332 = V_168 * V_174 ;
#if V_341 == 32
V_342 = V_305 ;
V_333 = F_159 ( V_342 , V_332 ) ;
V_342 = V_333 ;
F_159 ( V_342 , V_168 ) ;
V_333 = V_342 ;
V_342 = V_314 ;
V_334 = F_159 ( V_342 , V_332 ) ;
V_342 = V_334 ;
F_159 ( V_342 , V_168 ) ;
V_334 = V_342 ;
#else
V_333 = ( V_305 % V_332 ) / V_168 ;
V_334 = ( V_314 % V_332 ) / V_168 ;
#endif
if ( V_333 != V_334 )
return V_352 ;
#if V_341 == 32
V_342 = V_305 ;
F_159 ( V_342 , V_332 ) ;
V_317 = V_325 = V_323 = V_342 ;
V_342 = V_314 ;
F_159 ( V_342 , V_332 ) ;
V_326 = V_324 = V_342 ;
#else
V_317 = V_325 = V_323 =
V_305 / V_332 ;
V_326 = V_324 = V_314 / V_332 ;
#endif
if ( V_325 != V_326 )
return V_352 ;
#if V_341 == 32
V_342 = V_305 ;
V_319 = F_159 ( V_342 , V_332 ) ;
V_342 = V_319 ;
V_319 = ( T_2 ) F_159 ( V_342 , V_168 ) ;
V_327 = V_319 ;
V_342 = V_314 ;
V_328 = F_159 ( V_342 , V_332 ) ;
V_342 = V_328 ;
V_328 = F_159 ( V_342 , V_168 ) ;
V_342 = V_327 ;
F_159 ( V_342 , V_183 ) ;
V_321 = V_329 = V_342 ;
V_342 = V_328 ;
F_159 ( V_342 , V_183 ) ;
V_330 = V_342 ;
#else
V_319 = V_327 =
( T_2 ) ( ( V_305 % V_332 ) %
V_168 ) ;
V_328 =
( T_2 ) ( ( V_314 % V_332 ) %
V_168 ) ;
V_321 = V_327 / V_183 ;
V_329 = V_321 ;
V_330 = V_328 / V_183 ;
#endif
if ( V_329 != V_330 )
return V_352 ;
V_336 =
( ( T_2 ) ( V_317 >> V_165 -> V_355 ) ) %
F_100 ( & V_165 -> V_177 ) ;
V_313 = ( V_333 *
( F_100 ( & V_165 -> V_177 ) *
V_331 ) ) +
( V_336 * V_331 ) + V_321 ;
}
if ( F_158 ( V_313 >= V_178 ) )
return V_352 ;
V_267 = V_165 -> V_172 [ V_313 ] . V_267 ;
V_337 = F_57 ( & V_165 -> V_356 ) +
V_317 * V_183 +
( V_319 - V_321 * V_183 ) ;
V_338 = V_315 ;
if ( V_165 -> V_357 ) {
V_337 <<= V_165 -> V_357 ;
V_338 <<= V_165 -> V_357 ;
}
if ( F_158 ( V_338 > 0xffff ) )
return V_352 ;
if ( V_337 > 0xffffffff ) {
V_58 [ 0 ] = V_312 ? V_350 : V_351 ;
V_58 [ 1 ] = 0 ;
F_161 ( V_337 , & V_58 [ 2 ] ) ;
F_62 ( V_338 , & V_58 [ 10 ] ) ;
V_58 [ 14 ] = 0 ;
V_58 [ 15 ] = 0 ;
V_339 = 16 ;
} else {
V_58 [ 0 ] = V_312 ? V_346 : V_347 ;
V_58 [ 1 ] = 0 ;
F_62 ( ( T_2 ) V_337 , & V_58 [ 2 ] ) ;
V_58 [ 6 ] = 0 ;
F_63 ( ( T_5 ) V_338 , & V_58 [ 7 ] ) ;
V_58 [ 9 ] = 0 ;
V_339 = 10 ;
}
if ( F_100 ( & V_165 -> V_49 ) &
V_358 ) {
F_153 ( & V_304 , V_165 ,
V_305 ) ;
V_340 = & V_304 ;
} else {
V_340 = NULL ;
}
return F_162 ( V_16 , V_4 , V_267 ,
V_58 , V_339 , V_311 , V_340 , true ) ;
}
static int F_163 ( struct V_8 * V_16 )
{
struct V_359 T_8 * V_360 ;
unsigned long V_361 ;
V_45 V_362 ;
T_1 V_95 ;
V_360 = V_16 -> V_360 ;
V_361 = ( V_363 * V_364 ) + V_365 ;
while ( 1 ) {
V_362 = F_164 ( & V_360 -> V_362 ) ;
if ( memcmp ( & V_362 , V_366 ,
sizeof( V_362 ) ) == 0 )
break;
if ( F_165 ( V_365 , V_361 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_60 ) ;
return - V_367 ;
}
F_166 ( V_368 ) ;
}
while ( 1 ) {
V_95 = F_167 ( & V_360 -> V_369 ) ;
if ( V_95 == V_370 )
break;
if ( F_165 ( V_365 , V_361 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_61 ) ;
return - V_367 ;
}
F_166 ( V_368 ) ;
}
while ( 1 ) {
if ( F_49 ( & V_360 -> V_371 ) ==
V_372 )
break;
if ( F_165 ( V_365 , V_361 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_62 ) ;
return - V_367 ;
}
F_166 ( V_368 ) ;
}
return 0 ;
}
static inline void F_168 ( struct V_93 * V_94 )
{
struct V_12 * V_13 ;
V_13 = V_94 -> V_4 -> V_13 -> V_11 ;
V_13 -> V_189 = false ;
V_13 -> V_263 = false ;
}
static inline void F_169 ( struct V_373 * V_248 , char * V_374 )
{
struct V_8 * V_16 ;
struct V_12 * V_13 ;
V_13 = V_248 -> V_11 ;
if ( V_13 -> V_30 )
return;
V_13 -> V_30 = true ;
F_170 ( V_248 , V_375 ) ;
V_16 = F_6 ( V_248 -> V_376 ) ;
F_44 ( V_16 ) ;
F_64 ( & V_16 -> V_36 -> V_88 , L_63 ,
V_374 , V_16 -> V_22 -> V_184 , V_13 -> V_152 ,
V_13 -> V_153 , V_13 -> V_154 ) ;
}
static void F_171 ( struct V_93 * V_94 )
{
T_1 V_377 ;
T_1 V_378 ;
struct V_3 * V_4 ;
struct V_379 * V_96 ;
T_3 V_380 ;
int V_381 ;
int V_382 ;
struct V_383 V_384 ;
V_4 = V_94 -> V_4 ;
if ( ! V_4 )
return;
V_96 = V_94 -> V_96 ;
V_377 = V_96 -> V_95 ;
V_378 = V_385 ;
switch ( V_96 -> V_386 ) {
case V_387 :
break;
case V_388 :
V_382 =
F_58 ( & V_96 -> V_389 ) ;
V_381 = F_172 ( V_4 ) - V_382 ;
F_173 ( V_4 , V_381 ) ;
if ( V_382 < V_4 -> V_390 )
V_378 = V_391 ;
break;
case V_392 :
case V_393 :
V_378 = V_394 ;
break;
case V_395 :
V_378 = V_396 ;
break;
case V_397 :
case V_398 :
case V_399 :
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
default:
V_378 = V_413 ;
break;
}
V_380 = F_100 ( & V_96 -> V_380 ) ;
if ( V_380 == 0 )
V_380 =
F_100 ( & V_96 -> V_414 ) ;
if ( V_380 ) {
if ( V_380 > sizeof( V_96 -> V_415 ) )
V_380 = sizeof( V_96 -> V_415 ) ;
if ( V_377 == V_416 &&
F_174 ( V_96 -> V_415 ,
V_380 , & V_384 ) &&
V_384 . V_417 == V_418 &&
V_384 . V_419 == 0x3e &&
V_384 . V_420 == 0x1 ) {
F_169 ( V_4 -> V_13 , L_64 ) ;
V_378 = V_421 ;
}
if ( V_380 > V_422 )
V_380 = V_422 ;
memcpy ( V_4 -> V_423 , V_96 -> V_415 ,
V_380 ) ;
}
V_4 -> V_424 = V_377 ;
F_175 ( V_4 , V_378 ) ;
}
static void F_176 ( struct V_93 * V_94 )
{
T_1 V_377 ;
T_1 V_378 ;
struct V_3 * V_4 ;
struct V_425 * V_96 ;
T_3 V_380 ;
int V_381 ;
int V_382 ;
bool V_30 ;
V_4 = V_94 -> V_4 ;
V_96 = V_94 -> V_96 ;
V_378 = V_385 ;
V_380 = 0 ;
V_30 = false ;
switch ( V_96 -> V_426 ) {
case V_427 :
V_377 = V_96 -> V_95 ;
break;
case V_428 :
switch ( V_96 -> V_95 ) {
case V_429 :
V_377 = V_430 ;
break;
case V_431 :
V_377 = V_432 ;
V_381 = F_58 (
& V_96 -> V_381 ) ;
F_173 ( V_4 , V_381 ) ;
V_382 = F_172 ( V_4 ) - V_381 ;
if ( V_382 < V_4 -> V_390 )
V_378 = V_391 ;
break;
case V_433 :
V_377 = V_432 ;
break;
case V_434 :
F_168 ( V_94 ) ;
V_377 = V_432 ;
V_94 -> V_95 = - V_435 ;
break;
case V_436 :
case V_437 :
if ( ! V_94 -> V_97 ) {
V_30 = true ;
F_169 ( V_4 -> V_13 , L_65 ) ;
V_378 = V_421 ;
}
V_377 = V_416 ;
break;
case V_438 :
default:
V_377 = V_416 ;
break;
}
break;
case V_439 :
case V_440 :
V_377 = V_432 ;
break;
case V_441 :
case V_442 :
default:
V_377 = V_416 ;
break;
}
if ( V_96 -> V_443 ) {
V_380 =
F_100 ( & V_96 -> V_444 ) ;
if ( V_380 ) {
if ( V_380 > sizeof( V_96 -> V_415 ) )
V_380 = sizeof( V_96 -> V_415 ) ;
if ( V_380 > V_422 )
V_380 = V_422 ;
memcpy ( V_4 -> V_423 , V_96 -> V_415 ,
V_380 ) ;
}
}
if ( V_30 && V_380 == 0 )
F_177 ( 0 , V_4 -> V_423 , V_418 ,
0x3e , 0x1 ) ;
V_4 -> V_424 = V_377 ;
F_175 ( V_4 , V_378 ) ;
}
static void F_178 ( unsigned int V_61 ,
struct V_93 * V_94 )
{
switch ( V_61 ) {
case V_445 :
F_171 ( V_94 ) ;
break;
case V_446 :
F_176 ( V_94 ) ;
break;
}
}
static int F_179 (
struct V_447 * V_448 )
{
int V_103 ;
switch ( V_448 -> V_449 ) {
case V_450 :
case V_451 :
V_103 = 0 ;
break;
default:
V_103 = - V_452 ;
break;
}
return V_103 ;
}
static unsigned int F_180 ( struct V_8 * V_16 ,
struct V_310 * V_311 )
{
unsigned int V_453 ;
T_9 V_454 ;
T_9 V_455 ;
struct V_93 * V_94 ;
struct V_456 * V_448 ;
T_5 V_457 ;
V_453 = 0 ;
V_455 = V_311 -> V_458 ;
while ( 1 ) {
V_454 = * V_311 -> V_454 ;
if ( V_454 == V_455 )
break;
V_453 ++ ;
V_448 = V_311 -> V_459 +
( V_455 * V_460 ) ;
V_457 = F_100 ( & V_448 -> V_457 ) ;
F_160 ( V_457 >= V_16 -> V_101 ) ;
V_94 = & V_16 -> V_99 [ V_457 ] ;
F_160 ( F_36 ( & V_94 -> V_100 ) == 0 ) ;
switch ( V_448 -> V_60 . V_61 ) {
case V_461 :
case V_462 :
case V_463 :
break;
case V_464 :
V_94 -> V_95 =
F_179 (
( void * ) V_448 ) ;
break;
case V_465 :
F_168 ( V_94 ) ;
V_94 -> V_95 = - V_435 ;
break;
case V_445 :
case V_446 :
V_94 -> V_96 = V_16 -> V_466 +
( F_100 ( & V_448 -> V_467 ) *
V_468 ) ;
F_178 ( V_448 -> V_60 . V_61 ,
V_94 ) ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_66 ,
V_448 -> V_60 . V_61 ) ;
break;
}
V_94 -> V_469 ( V_94 ,
V_94 -> V_470 ) ;
V_455 = ( V_455 + 1 ) % V_16 -> V_471 ;
}
if ( V_453 ) {
V_311 -> V_458 = V_455 ;
F_181 ( V_455 , V_311 -> V_455 ) ;
}
return V_453 ;
}
static inline unsigned int F_182 ( unsigned int V_472 ,
unsigned int V_473 , unsigned int V_474 )
{
unsigned int V_475 ;
if ( V_472 >= V_473 )
V_475 = V_472 - V_473 ;
else
V_475 = V_474 - V_473 + V_472 ;
return V_474 - V_475 - 1 ;
}
static void F_183 ( struct V_8 * V_16 ,
struct V_476 * V_477 , T_3 V_65 )
{
T_9 V_478 ;
T_9 V_479 ;
unsigned long V_49 ;
void * V_480 ;
struct V_310 * V_311 ;
V_311 = & V_16 -> V_481 [ V_482 ] ;
F_60 ( V_311 -> V_483 , & V_477 -> V_60 . V_484 ) ;
while ( 1 ) {
F_129 ( & V_311 -> V_485 [ V_486 ] , V_49 ) ;
V_478 = V_311 -> V_487 [ V_486 ] ;
V_479 = * V_311 -> V_479 [ V_486 ] ;
if ( F_182 ( V_478 , V_479 ,
V_16 -> V_488 ) )
break;
F_131 (
& V_311 -> V_485 [ V_486 ] , V_49 ) ;
if ( F_10 ( V_16 ) )
return;
}
V_480 = V_311 -> V_489 [ V_486 ] +
( V_478 * V_490 ) ;
memcpy ( V_480 , V_477 , V_65 ) ;
V_478 = ( V_478 + 1 ) % V_16 -> V_488 ;
V_311 -> V_487 [ V_486 ] = V_478 ;
F_181 ( V_478 , V_311 -> V_478 [ V_486 ] ) ;
F_131 ( & V_311 -> V_485 [ V_486 ] , V_49 ) ;
}
static void F_184 ( struct V_8 * V_16 ,
struct V_491 * V_492 )
{
struct V_476 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_493 ;
F_60 ( sizeof( V_54 ) - V_64 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_494 = V_492 -> V_494 ;
V_54 . V_495 = V_492 -> V_495 ;
V_54 . V_496 = V_492 -> V_496 ;
F_183 ( V_16 , & V_54 , sizeof( V_54 ) ) ;
}
static void F_185 ( struct V_132 * V_133 )
{
unsigned int V_52 ;
struct V_8 * V_16 ;
struct V_491 * V_492 ;
V_16 = F_85 ( V_133 , struct V_8 , V_497 ) ;
F_33 ( V_16 ) ;
F_26 ( V_16 , V_27 ) ;
if ( F_10 ( V_16 ) )
goto V_109;
F_45 ( V_16 ) ;
V_492 = V_16 -> V_498 ;
for ( V_52 = 0 ; V_52 < V_499 ; V_52 ++ ) {
if ( V_492 -> V_500 ) {
V_492 -> V_500 = false ;
F_184 ( V_16 , V_492 ) ;
}
V_492 ++ ;
}
V_109:
F_34 ( V_16 ) ;
}
static void F_186 ( unsigned long V_415 )
{
int V_501 ;
T_2 V_502 ;
struct V_8 * V_16 = (struct V_8 * ) V_415 ;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return;
V_501 = F_36 ( & V_16 -> V_501 ) ;
V_502 = F_48 ( V_16 ) ;
if ( V_501 == V_16 -> V_503 ) {
if ( V_502 == V_16 -> V_504 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_67 ,
V_502 ) ;
F_13 ( V_16 ) ;
return;
}
} else {
V_16 -> V_503 = V_501 ;
}
V_16 -> V_504 = V_502 ;
F_187 ( & V_16 -> V_505 ,
V_365 + V_506 ) ;
}
static void F_188 ( struct V_8 * V_16 )
{
if ( ! V_16 -> V_35 )
return;
V_16 -> V_503 =
F_36 ( & V_16 -> V_501 ) ;
V_16 -> V_504 =
F_48 ( V_16 ) ;
V_16 -> V_505 . V_507 =
V_365 + V_506 ;
V_16 -> V_505 . V_415 = ( unsigned long ) V_16 ;
V_16 -> V_505 . V_508 = F_186 ;
F_189 ( & V_16 -> V_505 ) ;
}
static inline void F_190 ( struct V_8 * V_16 )
{
F_191 ( & V_16 -> V_505 ) ;
}
static inline int F_192 ( unsigned int V_494 )
{
int V_509 ;
for ( V_509 = 0 ; V_509 < F_2 ( V_510 ) ; V_509 ++ )
if ( V_494 == V_510 [ V_509 ] )
return V_509 ;
return - 1 ;
}
static inline bool F_193 ( unsigned int V_494 )
{
return F_192 ( V_494 ) != - 1 ;
}
static unsigned int F_194 ( struct V_8 * V_16 )
{
unsigned int V_511 ;
T_9 V_454 ;
T_9 V_455 ;
struct V_512 * V_513 ;
struct V_514 * V_448 ;
struct V_491 * V_492 ;
int V_515 ;
V_513 = & V_16 -> V_513 ;
V_511 = 0 ;
V_455 = V_513 -> V_458 ;
while ( 1 ) {
V_454 = * V_513 -> V_454 ;
if ( V_454 == V_455 )
break;
V_511 ++ ;
V_448 = V_513 -> V_459 +
( V_455 * V_516 ) ;
V_515 =
F_192 ( V_448 -> V_494 ) ;
if ( V_515 >= 0 ) {
if ( V_448 -> V_517 ) {
V_492 = & V_16 -> V_498 [ V_515 ] ;
V_492 -> V_500 = true ;
V_492 -> V_494 = V_448 -> V_494 ;
V_492 -> V_495 = V_448 -> V_495 ;
V_492 -> V_496 =
V_448 -> V_496 ;
}
}
V_455 = ( V_455 + 1 ) % V_518 ;
}
if ( V_511 ) {
V_513 -> V_458 = V_455 ;
F_181 ( V_455 , V_513 -> V_455 ) ;
F_195 ( & V_16 -> V_497 ) ;
}
return V_511 ;
}
static inline void F_196 ( struct V_8 * V_16 ,
bool V_519 )
{
T_2 V_520 ;
struct V_359 T_8 * V_360 ;
volatile void T_8 * V_521 ;
V_360 = V_16 -> V_360 ;
if ( V_519 )
V_521 = & V_360 -> V_522 ;
else
V_521 = & V_360 -> V_523 ;
V_520 = F_49 ( V_521 ) ;
V_520 |= V_524 ;
F_181 ( V_520 , V_521 ) ;
}
static void F_197 ( struct V_8 * V_16 ,
enum V_525 V_526 )
{
switch ( V_16 -> V_527 ) {
case V_528 :
switch ( V_526 ) {
case V_528 :
break;
case V_529 :
F_196 ( V_16 , true ) ;
F_198 ( V_16 ) ;
F_199 ( V_16 ) ;
break;
case V_530 :
F_198 ( V_16 ) ;
break;
}
break;
case V_529 :
switch ( V_526 ) {
case V_528 :
F_196 ( V_16 , false ) ;
F_200 ( V_16 ) ;
F_201 ( V_16 ) ;
break;
case V_529 :
break;
case V_530 :
F_196 ( V_16 , false ) ;
F_200 ( V_16 ) ;
break;
}
break;
case V_530 :
switch ( V_526 ) {
case V_528 :
F_201 ( V_16 ) ;
break;
case V_529 :
F_196 ( V_16 , true ) ;
F_199 ( V_16 ) ;
break;
case V_530 :
break;
}
break;
}
V_16 -> V_527 = V_526 ;
}
static inline bool F_202 ( struct V_8 * V_16 )
{
bool V_531 ;
T_2 V_532 ;
switch ( V_16 -> V_527 ) {
case V_528 :
V_531 = true ;
break;
case V_529 :
V_532 =
F_49 ( & V_16 -> V_360 -> V_533 ) ;
if ( V_532 & V_534 )
V_531 = true ;
else
V_531 = false ;
break;
case V_530 :
default:
V_531 = false ;
break;
}
return V_531 ;
}
static T_10 F_203 ( int V_535 , void * V_415 )
{
struct V_8 * V_16 ;
struct V_310 * V_311 ;
unsigned int V_536 ;
V_311 = V_415 ;
V_16 = V_311 -> V_16 ;
if ( ! F_202 ( V_16 ) )
return V_537 ;
V_536 = F_180 ( V_16 , V_311 ) ;
if ( V_535 == V_16 -> V_538 )
V_536 += F_194 ( V_16 ) ;
if ( V_536 )
F_27 ( & V_16 -> V_501 ) ;
F_204 ( V_16 , V_311 , V_486 , NULL ) ;
F_204 ( V_16 , V_311 , V_539 , NULL ) ;
return V_540 ;
}
static int F_205 ( struct V_8 * V_16 )
{
struct V_36 * V_36 = V_16 -> V_36 ;
int V_52 ;
int V_103 ;
V_16 -> V_538 = F_206 ( V_36 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_541 ; V_52 ++ ) {
V_103 = F_207 ( F_206 ( V_36 , V_52 ) , F_203 , 0 ,
V_542 , & V_16 -> V_481 [ V_52 ] ) ;
if ( V_103 ) {
F_64 ( & V_36 -> V_88 ,
L_68 ,
F_206 ( V_36 , V_52 ) , V_103 ) ;
return V_103 ;
}
V_16 -> V_543 ++ ;
}
return 0 ;
}
static void F_208 ( struct V_8 * V_16 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_543 ; V_52 ++ )
F_209 ( F_206 ( V_16 -> V_36 , V_52 ) ,
& V_16 -> V_481 [ V_52 ] ) ;
V_16 -> V_543 = 0 ;
}
static int F_210 ( struct V_8 * V_16 )
{
int V_544 ;
V_544 = F_211 ( V_16 -> V_36 ,
V_545 , V_16 -> V_546 ,
V_547 | V_548 ) ;
if ( V_544 < 0 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_69 ,
V_544 ) ;
return V_544 ;
}
V_16 -> V_541 = V_544 ;
V_16 -> V_527 = V_528 ;
return 0 ;
}
static void F_212 ( struct V_8 * V_16 )
{
if ( V_16 -> V_541 ) {
F_213 ( V_16 -> V_36 ) ;
V_16 -> V_541 = 0 ;
}
}
static int F_214 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
T_3 V_549 ;
T_3 V_550 ;
T_3 V_551 ;
void * V_552 ;
void * V_553 ;
void * V_554 ;
unsigned int V_555 ;
unsigned int V_556 ;
unsigned int V_557 ;
struct V_310 * V_311 ;
V_550 =
V_490 *
V_16 -> V_488 ;
V_551 =
V_460 *
V_16 -> V_471 ;
V_555 = V_16 -> V_546 * 2 ;
V_556 = V_16 -> V_546 ;
V_557 = ( V_16 -> V_546 * 3 ) + 1 ;
V_554 = NULL ;
for ( V_52 = 0 ; V_52 < V_555 ; V_52 ++ ) {
V_554 = F_215 ( V_554 ,
V_558 ) ;
V_554 += V_550 ;
}
for ( V_52 = 0 ; V_52 < V_556 ; V_52 ++ ) {
V_554 = F_215 ( V_554 ,
V_558 ) ;
V_554 += V_551 ;
}
V_554 = F_215 ( V_554 ,
V_558 ) ;
V_554 += V_518 *
V_516 ;
for ( V_52 = 0 ; V_52 < V_557 ; V_52 ++ ) {
V_554 = F_215 ( V_554 ,
V_559 ) ;
V_554 += sizeof( T_9 ) ;
}
V_549 = ( T_3 ) V_554 +
V_558 ;
V_549 += V_560 ;
V_16 -> V_561 =
F_216 ( & V_16 -> V_36 -> V_88 ,
V_549 ,
& V_16 -> V_562 , V_108 ) ;
if ( ! V_16 -> V_561 )
return - V_44 ;
V_16 -> V_563 = V_549 ;
V_552 = F_215 ( V_16 -> V_561 ,
V_558 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_311 = & V_16 -> V_481 [ V_52 ] ;
V_311 -> V_489 [ V_486 ] = V_552 ;
V_311 -> V_564 [ V_486 ] =
V_16 -> V_562 +
( V_552 - V_16 -> V_561 ) ;
V_552 += V_550 ;
V_552 = F_215 ( V_552 ,
V_558 ) ;
V_311 -> V_489 [ V_539 ] = V_552 ;
V_311 -> V_564 [ V_539 ] =
V_16 -> V_562 +
( V_552 - V_16 -> V_561 ) ;
V_552 += V_550 ;
V_552 = F_215 ( V_552 ,
V_558 ) ;
}
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_311 = & V_16 -> V_481 [ V_52 ] ;
V_311 -> V_459 = V_552 ;
V_311 -> V_565 =
V_16 -> V_562 +
( V_552 - V_16 -> V_561 ) ;
V_552 += V_551 ;
V_552 = F_215 ( V_552 ,
V_558 ) ;
}
V_16 -> V_513 . V_459 = V_552 ;
V_16 -> V_513 . V_565 =
V_16 -> V_562 +
( V_552 - V_16 -> V_561 ) ;
V_552 += V_518 *
V_516 ;
V_553 = F_215 ( V_552 ,
V_559 ) ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_311 = & V_16 -> V_481 [ V_52 ] ;
V_311 -> V_479 [ V_486 ] = V_553 ;
V_311 -> V_566 [ V_486 ] =
V_16 -> V_562 +
( V_553 - V_16 -> V_561 ) ;
V_553 += sizeof( T_9 ) ;
V_553 = F_215 ( V_553 ,
V_559 ) ;
V_311 -> V_479 [ V_539 ] = V_553 ;
V_311 -> V_566 [ V_539 ] =
V_16 -> V_562 +
( V_553 - V_16 -> V_561 ) ;
V_553 += sizeof( T_9 ) ;
V_553 = F_215 ( V_553 ,
V_559 ) ;
V_311 -> V_454 = V_553 ;
V_311 -> V_567 =
V_16 -> V_562 +
( V_553 - V_16 -> V_561 ) ;
V_553 += sizeof( T_9 ) ;
V_553 = F_215 ( V_553 ,
V_559 ) ;
}
V_16 -> V_513 . V_454 = V_553 ;
V_16 -> V_513 . V_567 =
V_16 -> V_562 +
( V_553 - V_16 -> V_561 ) ;
return 0 ;
}
static void F_217 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
T_5 V_568 = V_569 ;
T_5 V_570 = V_569 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ )
V_16 -> V_481 [ V_52 ] . V_16 = V_16 ;
V_16 -> V_513 . V_483 = V_570 ++ ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_16 -> V_481 [ V_52 ] . V_571 [ V_486 ] = V_568 ++ ;
V_16 -> V_481 [ V_52 ] . V_571 [ V_539 ] = V_568 ++ ;
V_16 -> V_481 [ V_52 ] . V_483 = V_570 ++ ;
}
V_16 -> V_513 . V_572 = 0 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ )
V_16 -> V_481 [ V_52 ] . V_572 = V_52 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
F_218 ( & V_16 -> V_481 [ V_52 ] . V_485 [ 0 ] ) ;
F_218 ( & V_16 -> V_481 [ V_52 ] . V_485 [ 1 ] ) ;
F_219 ( & V_16 -> V_481 [ V_52 ] . V_573 [ 0 ] ) ;
F_219 ( & V_16 -> V_481 [ V_52 ] . V_573 [ 1 ] ) ;
}
}
static int F_220 ( struct V_8 * V_16 )
{
T_3 V_549 ;
struct V_574 * V_575 ;
struct V_576 * V_577 ;
V_549 = sizeof( struct V_574 ) +
V_558 ;
V_16 -> V_578 =
F_216 ( & V_16 -> V_36 -> V_88 ,
V_549 ,
& V_16 -> V_579 ,
V_108 ) ;
if ( ! V_16 -> V_578 )
return - V_44 ;
V_16 -> V_580 = V_549 ;
V_577 = & V_16 -> V_577 ;
V_575 = F_215 ( V_16 -> V_578 ,
V_558 ) ;
V_577 -> V_489 =
& V_575 -> V_489 ;
V_577 -> V_459 =
& V_575 -> V_459 ;
V_577 -> V_479 = & V_575 -> V_479 ;
V_577 -> V_454 = & V_575 -> V_454 ;
V_577 -> V_564 =
V_16 -> V_579 +
( V_577 -> V_489 -
V_16 -> V_578 ) ;
V_577 -> V_565 =
V_16 -> V_579 +
( V_577 -> V_459 -
V_16 -> V_578 ) ;
V_577 -> V_566 =
V_16 -> V_579 +
( ( void * ) V_577 -> V_479 -
V_16 -> V_578 ) ;
V_577 -> V_567 =
V_16 -> V_579 +
( ( void * ) V_577 -> V_454 -
V_16 -> V_578 ) ;
return 0 ;
}
static int F_221 ( struct V_8 * V_16 )
{
struct V_359 T_8 * V_360 ;
struct V_576 * V_577 ;
unsigned long V_361 ;
T_1 V_95 ;
T_2 V_581 ;
V_360 = V_16 -> V_360 ;
V_577 = & V_16 -> V_577 ;
F_222 ( ( V_45 ) V_577 -> V_564 ,
& V_360 -> V_582 ) ;
F_222 ( ( V_45 ) V_577 -> V_565 ,
& V_360 -> V_583 ) ;
F_222 ( ( V_45 ) V_577 -> V_566 ,
& V_360 -> V_584 ) ;
F_222 ( ( V_45 ) V_577 -> V_567 ,
& V_360 -> V_585 ) ;
V_581 = V_586 |
( V_587 ) << 8 |
( V_577 -> V_572 << 16 ) ;
F_181 ( V_581 , & V_360 -> V_588 ) ;
F_181 ( V_589 ,
& V_360 -> V_369 ) ;
V_361 = V_590 + V_365 ;
while ( 1 ) {
V_95 = F_167 ( & V_360 -> V_369 ) ;
if ( V_95 == V_370 )
break;
if ( F_165 ( V_365 , V_361 ) )
return - V_367 ;
F_166 ( V_591 ) ;
}
V_577 -> V_478 = V_16 -> V_592 +
V_593 +
F_164 ( & V_360 -> V_594 ) ;
V_577 -> V_455 = V_16 -> V_592 +
V_593 +
F_164 ( & V_360 -> V_595 ) ;
return 0 ;
}
static void F_223 ( struct V_8 * V_16 ,
struct V_596 * V_54 )
{
struct V_576 * V_577 ;
void * V_480 ;
T_9 V_478 ;
V_577 = & V_16 -> V_577 ;
V_478 = V_577 -> V_487 ;
V_480 = V_577 -> V_489 +
( V_478 * V_597 ) ;
memcpy ( V_480 , V_54 , sizeof( * V_54 ) ) ;
V_478 = ( V_478 + 1 ) % V_586 ;
V_577 -> V_487 = V_478 ;
F_181 ( V_478 , V_577 -> V_478 ) ;
}
static int F_224 ( struct V_8 * V_16 ,
struct V_598 * V_448 )
{
struct V_576 * V_577 ;
T_9 V_454 ;
T_9 V_455 ;
unsigned long V_361 ;
V_577 = & V_16 -> V_577 ;
V_455 = V_577 -> V_458 ;
V_361 = ( V_599 * V_364 ) + V_365 ;
while ( 1 ) {
V_454 = * V_577 -> V_454 ;
if ( V_454 != V_455 )
break;
if ( F_165 ( V_365 , V_361 ) ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_70 ) ;
return - V_367 ;
}
if ( ! F_12 ( V_16 ) )
return - V_106 ;
F_37 ( 1000 , 2000 ) ;
}
memcpy ( V_448 , V_577 -> V_459 +
( V_455 * V_600 ) , sizeof( * V_448 ) ) ;
V_455 = ( V_455 + 1 ) % V_587 ;
V_577 -> V_458 = V_455 ;
F_181 ( V_455 , V_577 -> V_455 ) ;
return 0 ;
}
static void F_204 ( struct V_8 * V_16 ,
struct V_310 * V_311 , enum V_601 V_374 ,
struct V_93 * V_94 )
{
struct V_93 * V_275 ;
void * V_480 ;
T_9 V_478 ;
T_9 V_479 ;
T_3 V_65 ;
unsigned long V_49 ;
unsigned int V_602 ;
unsigned int V_603 ;
T_3 V_604 ;
struct V_605 * V_54 ;
F_129 ( & V_311 -> V_485 [ V_374 ] , V_49 ) ;
if ( V_94 ) {
V_94 -> V_311 = V_311 ;
F_135 ( & V_94 -> V_606 ,
& V_311 -> V_573 [ V_374 ] ) ;
}
V_478 = V_311 -> V_487 [ V_374 ] ;
F_134 (io_request, next,
&queue_group->request_list[path], request_list_entry) {
V_54 = V_94 -> V_477 ;
V_65 = F_100 ( & V_54 -> V_65 ) +
V_64 ;
V_602 =
F_225 ( V_65 ,
V_490 ) ;
V_479 = * V_311 -> V_479 [ V_374 ] ;
if ( V_602 > F_182 ( V_478 , V_479 ,
V_16 -> V_488 ) )
break;
F_60 ( V_311 -> V_483 ,
& V_54 -> V_484 ) ;
V_480 = V_311 -> V_489 [ V_374 ] +
( V_478 * V_490 ) ;
V_603 =
V_16 -> V_488 - V_478 ;
if ( V_602 <= V_603 ) {
memcpy ( V_480 , V_54 , V_65 ) ;
} else {
V_604 = V_603 *
V_490 ;
memcpy ( V_480 , V_54 , V_604 ) ;
memcpy ( V_311 -> V_489 [ V_374 ] ,
( T_1 * ) V_54 + V_604 ,
V_65 - V_604 ) ;
}
V_478 = ( V_478 + V_602 ) %
V_16 -> V_488 ;
F_130 ( & V_94 -> V_606 ) ;
}
if ( V_478 != V_311 -> V_487 [ V_374 ] ) {
V_311 -> V_487 [ V_374 ] = V_478 ;
F_181 ( V_478 , V_311 -> V_478 [ V_374 ] ) ;
}
F_131 ( & V_311 -> V_485 [ V_374 ] , V_49 ) ;
}
static int F_226 ( struct V_8 * V_16 ,
struct V_607 * V_608 )
{
int V_103 ;
while ( 1 ) {
if ( F_227 ( V_608 ,
V_609 * V_364 ) ) {
V_103 = 0 ;
break;
}
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = - V_106 ;
break;
}
}
return V_103 ;
}
static void F_228 ( struct V_93 * V_94 ,
void * V_470 )
{
struct V_607 * V_610 = V_470 ;
F_229 ( V_610 ) ;
}
static int F_230 (
struct V_8 * V_16 , struct V_93 * V_94 ,
unsigned long V_24 )
{
int V_103 = 0 ;
F_231 ( V_608 ) ;
V_94 -> V_469 = F_228 ;
V_94 -> V_470 = & V_608 ;
F_204 ( V_16 ,
& V_16 -> V_481 [ V_482 ] , V_486 ,
V_94 ) ;
if ( V_24 == V_27 ) {
F_226 ( V_16 , & V_608 ) ;
} else {
if ( ! F_227 ( & V_608 ,
F_30 ( V_24 ) ) ) {
F_87 ( & V_16 -> V_36 -> V_88 ,
L_71 ) ;
V_103 = - V_367 ;
}
}
return V_103 ;
}
static int F_70 ( struct V_8 * V_16 ,
struct V_605 * V_54 , unsigned int V_49 ,
struct V_379 * V_96 , unsigned long V_24 )
{
int V_103 ;
struct V_93 * V_94 ;
unsigned long V_611 ;
unsigned long V_612 ;
T_3 V_65 ;
if ( V_49 & V_613 ) {
if ( F_232 ( & V_16 -> V_614 ) )
return - V_615 ;
} else {
if ( V_24 == V_27 ) {
F_233 ( & V_16 -> V_614 ) ;
} else {
V_611 = V_365 ;
if ( F_234 ( & V_16 -> V_614 ,
F_30 ( V_24 ) ) )
return - V_367 ;
V_612 =
F_31 ( V_365 - V_611 ) ;
if ( V_612 >= V_24 )
return - V_367 ;
V_24 -= V_612 ;
}
}
F_33 ( V_16 ) ;
V_24 = F_26 ( V_16 , V_24 ) ;
if ( V_24 == 0 ) {
V_103 = - V_367 ;
goto V_109;
}
if ( F_10 ( V_16 ) ) {
V_103 = - V_106 ;
goto V_109;
}
V_94 = F_66 ( V_16 ) ;
F_60 ( V_94 -> V_509 ,
& ( ( (struct V_53 * ) V_54 ) -> V_457 ) ) ;
if ( V_54 -> V_61 == V_62 )
( (struct V_53 * ) V_54 ) -> V_467 =
( (struct V_53 * ) V_54 ) -> V_457 ;
V_65 = F_100 ( & V_54 -> V_65 ) +
V_64 ;
memcpy ( V_94 -> V_477 , V_54 , V_65 ) ;
V_103 = F_230 ( V_16 ,
V_94 , V_24 ) ;
if ( V_96 ) {
if ( V_94 -> V_96 )
memcpy ( V_96 , V_94 -> V_96 ,
sizeof( * V_96 ) ) ;
else
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
} else if ( V_103 == 0 && V_94 -> V_96 ) {
T_1 V_377 ;
struct V_379 * V_616 ;
V_616 = V_94 -> V_96 ;
V_377 = V_616 -> V_95 ;
if ( V_377 == V_416 &&
V_616 -> V_386 ==
V_388 )
V_377 = V_432 ;
if ( V_377 != V_432 )
V_103 = - V_452 ;
}
F_68 ( V_94 ) ;
V_109:
F_34 ( V_16 ) ;
F_235 ( & V_16 -> V_614 ) ;
return V_103 ;
}
static int F_236 (
struct V_598 * V_448 , T_1 V_617 )
{
if ( V_448 -> V_60 . V_61 != V_618 )
return - V_185 ;
if ( F_100 ( & V_448 -> V_60 . V_65 ) !=
V_619 )
return - V_185 ;
if ( V_448 -> V_620 != V_617 )
return - V_185 ;
if ( V_448 -> V_95 != V_621 )
return - V_185 ;
return 0 ;
}
static int F_237 (
struct V_8 * V_16 ,
struct V_596 * V_54 ,
struct V_598 * V_448 )
{
int V_103 ;
F_223 ( V_16 , V_54 ) ;
V_103 = F_224 ( V_16 , V_448 ) ;
if ( V_103 == 0 )
V_103 = F_236 ( V_448 ,
V_54 -> V_620 ) ;
return V_103 ;
}
static int F_238 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_596 V_54 ;
struct V_598 V_448 ;
struct V_622 * V_623 ;
struct V_624 * V_625 ;
V_623 = F_79 ( sizeof( * V_623 ) , V_108 ) ;
if ( ! V_623 )
return - V_44 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 =
V_627 ;
F_54 ( sizeof( * V_623 ) ,
& V_54 . V_415 . V_628 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
& V_54 . V_415 . V_628 . V_38 ,
V_623 , sizeof( * V_623 ) ,
V_89 ) ;
if ( V_103 )
goto V_109;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
F_55 ( V_16 -> V_36 ,
& V_54 . V_415 . V_628 . V_38 , 1 ,
V_89 ) ;
if ( V_103 )
goto V_109;
if ( V_448 . V_95 != V_621 ) {
V_103 = - V_452 ;
goto V_109;
}
V_16 -> V_629 =
F_100 ( & V_623 -> V_629 ) ;
V_16 -> V_630 =
F_100 ( & V_623 -> V_630 ) ;
V_16 -> V_631 =
F_100 ( & V_623 -> V_631 )
* 16 ;
V_16 -> V_632 =
F_100 ( & V_623 -> V_632 ) ;
V_16 -> V_633 =
F_100 ( & V_623 -> V_633 ) ;
V_16 -> V_634 =
F_100 ( & V_623 -> V_634 )
* 16 ;
V_625 =
& V_623 -> V_635 [ V_636 ] ;
V_16 -> V_637 =
F_100 (
& V_625 -> V_638 ) ;
V_16 -> V_639 =
V_625 -> V_639 ;
V_16 -> V_640 =
V_625 -> V_640 ;
V_109:
F_76 ( V_623 ) ;
return V_103 ;
}
static int F_239 ( struct V_8 * V_16 )
{
if ( V_16 -> V_631 <
V_490 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_72 ,
V_16 -> V_631 ,
V_490 ) ;
return - V_185 ;
}
if ( V_16 -> V_634 <
V_460 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_73 ,
V_16 -> V_634 ,
V_460 ) ;
return - V_185 ;
}
if ( V_16 -> V_637 <
V_490 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_74 ,
V_16 -> V_637 ,
V_490 ) ;
return - V_185 ;
}
if ( ! V_16 -> V_639 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_75 ) ;
return - V_185 ;
}
if ( V_16 -> V_640 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_76 ) ;
return - V_185 ;
}
return 0 ;
}
static int F_240 ( struct V_8 * V_16 ,
bool V_641 , T_5 V_642 )
{
struct V_596 V_54 ;
struct V_598 V_448 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
if ( V_641 )
V_54 . V_620 =
V_643 ;
else
V_54 . V_620 =
V_644 ;
F_60 ( V_642 ,
& V_54 . V_415 . V_645 . V_642 ) ;
return F_237 ( V_16 , & V_54 ,
& V_448 ) ;
}
static int F_241 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_512 * V_513 ;
struct V_596 V_54 ;
struct V_598 V_448 ;
V_513 = & V_16 -> V_513 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 = V_646 ;
F_60 ( V_513 -> V_483 ,
& V_54 . V_415 . V_647 . V_642 ) ;
F_53 ( ( V_45 ) V_513 -> V_565 ,
& V_54 . V_415 . V_647 . V_648 ) ;
F_53 ( ( V_45 ) V_513 -> V_567 ,
& V_54 . V_415 . V_647 . V_649 ) ;
F_60 ( V_518 ,
& V_54 . V_415 . V_647 . V_650 ) ;
F_60 ( V_516 / 16 ,
& V_54 . V_415 . V_647 . V_651 ) ;
V_54 . V_415 . V_647 . V_652 = V_636 ;
F_60 ( V_513 -> V_572 ,
& V_54 . V_415 . V_647 . V_572 ) ;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
if ( V_103 )
return V_103 ;
V_513 -> V_455 = V_16 -> V_592 +
V_593 +
F_57 (
& V_448 . V_415 . V_647 . V_653 ) ;
return 0 ;
}
static int F_242 ( struct V_8 * V_16 ,
unsigned int V_654 )
{
int V_103 ;
struct V_310 * V_311 ;
struct V_596 V_54 ;
struct V_598 V_448 ;
V_311 = & V_16 -> V_481 [ V_654 ] ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 = V_655 ;
F_60 ( V_311 -> V_571 [ V_486 ] ,
& V_54 . V_415 . V_656 . V_642 ) ;
F_53 (
( V_45 ) V_311 -> V_564 [ V_486 ] ,
& V_54 . V_415 . V_656 . V_648 ) ;
F_53 ( ( V_45 ) V_311 -> V_566 [ V_486 ] ,
& V_54 . V_415 . V_656 . V_657 ) ;
F_60 ( V_16 -> V_488 ,
& V_54 . V_415 . V_656 . V_650 ) ;
F_60 ( V_490 / 16 ,
& V_54 . V_415 . V_656 . V_651 ) ;
V_54 . V_415 . V_656 . V_652 = V_636 ;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_77 ) ;
return V_103 ;
}
V_311 -> V_478 [ V_486 ] = V_16 -> V_592 +
V_593 +
F_57 (
& V_448 . V_415 . V_656 . V_658 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 = V_655 ;
F_60 ( V_311 -> V_571 [ V_539 ] ,
& V_54 . V_415 . V_656 . V_642 ) ;
F_53 ( ( V_45 ) V_311 ->
V_564 [ V_539 ] ,
& V_54 . V_415 . V_656 . V_648 ) ;
F_53 ( ( V_45 ) V_311 -> V_566 [ V_539 ] ,
& V_54 . V_415 . V_656 . V_657 ) ;
F_60 ( V_16 -> V_488 ,
& V_54 . V_415 . V_656 . V_650 ) ;
F_60 ( V_490 / 16 ,
& V_54 . V_415 . V_656 . V_651 ) ;
V_54 . V_415 . V_656 . V_652 = V_636 ;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_78 ) ;
goto V_659;
}
V_311 -> V_478 [ V_539 ] = V_16 -> V_592 +
V_593 +
F_57 (
& V_448 . V_415 . V_656 . V_658 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 = V_660 ;
F_60 ( V_311 -> V_571 [ V_539 ] ,
& V_54 . V_415 . V_661 . V_642 ) ;
F_54 ( V_662 ,
& V_54 . V_415 . V_661 . V_663 ) ;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_79 ) ;
goto V_664;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_626 ;
F_60 ( V_619 ,
& V_54 . V_60 . V_65 ) ;
V_54 . V_620 = V_646 ;
F_60 ( V_311 -> V_483 ,
& V_54 . V_415 . V_647 . V_642 ) ;
F_53 ( ( V_45 ) V_311 -> V_565 ,
& V_54 . V_415 . V_647 . V_648 ) ;
F_53 ( ( V_45 ) V_311 -> V_567 ,
& V_54 . V_415 . V_647 . V_649 ) ;
F_60 ( V_16 -> V_471 ,
& V_54 . V_415 . V_647 . V_650 ) ;
F_60 ( V_460 / 16 ,
& V_54 . V_415 . V_647 . V_651 ) ;
V_54 . V_415 . V_647 . V_652 = V_636 ;
F_60 ( V_311 -> V_572 ,
& V_54 . V_415 . V_647 . V_572 ) ;
V_103 = F_237 ( V_16 , & V_54 ,
& V_448 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_80 ) ;
goto V_664;
}
V_311 -> V_455 = V_16 -> V_592 +
V_593 +
F_57 (
& V_448 . V_415 . V_647 . V_653 ) ;
return 0 ;
V_664:
F_240 ( V_16 , true ,
V_311 -> V_571 [ V_539 ] ) ;
V_659:
F_240 ( V_16 , true ,
V_311 -> V_571 [ V_486 ] ) ;
return V_103 ;
}
static int F_243 ( struct V_8 * V_16 )
{
int V_103 ;
unsigned int V_52 ;
V_103 = F_241 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_81 ) ;
return V_103 ;
}
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_103 = F_242 ( V_16 , V_52 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_82 ,
V_52 , V_16 -> V_546 ) ;
return V_103 ;
}
}
return 0 ;
}
static int F_244 ( struct V_8 * V_16 ,
bool V_665 )
{
int V_103 ;
unsigned int V_52 ;
struct V_666 * V_667 ;
struct V_668 * V_669 ;
struct V_670 V_54 ;
V_667 = F_79 ( V_671 ,
V_108 ) ;
if ( ! V_667 )
return - V_44 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_672 ;
F_60 ( F_61 ( struct V_670 ,
V_415 . V_673 . V_63 [ 1 ] ) -
V_64 , & V_54 . V_60 . V_65 ) ;
F_54 ( V_671 ,
& V_54 . V_415 . V_673 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
V_54 . V_415 . V_673 . V_63 ,
V_667 , V_671 ,
V_89 ) ;
if ( V_103 )
goto V_109;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
0 , NULL , V_27 ) ;
F_55 ( V_16 -> V_36 ,
V_54 . V_415 . V_673 . V_63 , 1 ,
V_89 ) ;
if ( V_103 )
goto V_109;
for ( V_52 = 0 ; V_52 < V_667 -> V_674 ; V_52 ++ ) {
V_669 = & V_667 -> V_50 [ V_52 ] ;
if ( V_665 &&
F_193 ( V_669 -> V_494 ) )
F_60 ( V_16 -> V_513 . V_483 ,
& V_669 -> V_483 ) ;
else
F_60 ( 0 , & V_669 -> V_483 ) ;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_675 ;
F_60 ( F_61 ( struct V_670 ,
V_415 . V_673 . V_63 [ 1 ] ) -
V_64 , & V_54 . V_60 . V_65 ) ;
F_54 ( V_671 ,
& V_54 . V_415 . V_673 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
V_54 . V_415 . V_673 . V_63 ,
V_667 , V_671 ,
V_90 ) ;
if ( V_103 )
goto V_109;
V_103 = F_70 ( V_16 , & V_54 . V_60 , 0 ,
NULL , V_27 ) ;
F_55 ( V_16 -> V_36 ,
V_54 . V_415 . V_673 . V_63 , 1 ,
V_90 ) ;
V_109:
F_76 ( V_667 ) ;
return V_103 ;
}
static inline int F_245 ( struct V_8 * V_16 )
{
return F_244 ( V_16 , true ) ;
}
static inline int F_246 ( struct V_8 * V_16 )
{
return F_244 ( V_16 , false ) ;
}
static void F_247 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
struct V_13 * V_88 ;
T_3 V_676 ;
struct V_93 * V_94 ;
if ( ! V_16 -> V_99 )
return;
V_88 = & V_16 -> V_36 -> V_88 ;
V_676 = V_16 -> V_676 ;
V_94 = V_16 -> V_99 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_101 ; V_52 ++ ) {
F_76 ( V_94 -> V_477 ) ;
if ( ! V_94 -> V_677 )
break;
F_248 ( V_88 , V_676 ,
V_94 -> V_677 ,
V_94 -> V_678 ) ;
V_94 ++ ;
}
F_76 ( V_16 -> V_99 ) ;
V_16 -> V_99 = NULL ;
}
static inline int F_249 ( struct V_8 * V_16 )
{
V_16 -> V_466 = F_216 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_679 ,
& V_16 -> V_680 , V_108 ) ;
if ( ! V_16 -> V_466 )
return - V_44 ;
return 0 ;
}
static int F_250 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
void * V_677 ;
T_3 V_676 ;
T_4 V_678 ;
struct V_13 * V_88 ;
struct V_93 * V_94 ;
V_16 -> V_99 = F_75 ( V_16 -> V_101 *
sizeof( V_16 -> V_99 [ 0 ] ) , V_108 ) ;
if ( ! V_16 -> V_99 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_83 ) ;
goto error;
}
V_88 = & V_16 -> V_36 -> V_88 ;
V_676 = V_16 -> V_676 ;
V_94 = V_16 -> V_99 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_101 ; V_52 ++ ) {
V_94 -> V_477 =
F_79 ( V_16 -> V_638 , V_108 ) ;
if ( ! V_94 -> V_477 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_84 ) ;
goto error;
}
V_677 = F_251 ( V_88 ,
V_676 , & V_678 ,
V_108 ) ;
if ( ! V_677 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_85 ) ;
goto error;
}
V_94 -> V_509 = V_52 ;
V_94 -> V_677 = V_677 ;
V_94 -> V_678 =
V_678 ;
V_94 ++ ;
}
return 0 ;
error:
F_247 ( V_16 ) ;
return - V_44 ;
}
static void F_252 ( struct V_8 * V_16 )
{
T_2 V_681 ;
T_2 V_682 ;
V_16 -> V_683 =
V_16 -> V_684 - V_685 ;
V_16 -> V_101 = V_16 -> V_684 ;
V_16 -> V_679 =
V_16 -> V_101 * V_468 ;
if ( V_686 )
V_681 = F_253 ( V_16 -> V_681 ,
V_687 ) ;
else
V_681 = F_253 ( V_16 -> V_681 ,
V_688 ) ;
V_682 = V_681 / V_689 ;
V_682 ++ ;
V_682 = F_253 ( V_16 -> V_682 , V_682 ) ;
V_681 = ( V_682 - 1 ) * V_689 ;
V_16 -> V_676 =
( V_682 * sizeof( struct V_37 ) ) +
V_560 ;
V_16 -> V_690 = V_682 ;
V_16 -> V_691 = V_681 / 512 ;
}
static void F_254 ( struct V_8 * V_16 )
{
int V_546 ;
T_5 V_488 ;
T_5 V_471 ;
if ( V_686 ) {
V_546 = 1 ;
} else {
int V_692 ;
int V_693 ;
V_693 = F_253 ( V_16 -> V_629 / 2 ,
V_16 -> V_632 - 1 ) ;
V_693 = F_253 ( V_693 , V_694 ) ;
V_692 = F_255 () ;
V_546 = F_253 ( V_692 , V_16 -> V_695 ) ;
V_546 = F_253 ( V_546 , V_693 ) ;
}
V_16 -> V_546 = V_546 ;
V_16 -> V_696 = V_546 - 1 ;
V_16 -> V_638 =
( V_16 -> V_637 /
V_490 ) *
V_490 ;
V_488 =
( V_16 -> V_638 /
V_490 ) ;
V_488 ++ ;
V_488 = F_253 ( V_488 ,
V_16 -> V_630 ) ;
V_471 = ( ( V_488 - 1 ) * 2 ) + 1 ;
V_471 = F_253 ( V_471 ,
V_16 -> V_633 ) ;
V_16 -> V_488 = V_488 ;
V_16 -> V_471 = V_471 ;
V_16 -> V_697 =
( ( V_16 -> V_638 -
V_490 ) /
sizeof( struct V_37 ) ) +
V_698 ;
}
static inline void F_256 (
struct V_37 * V_38 , struct V_699 * V_700 )
{
V_45 V_46 = ( V_45 ) F_257 ( V_700 ) ;
unsigned int V_47 = F_258 ( V_700 ) ;
F_53 ( V_46 , & V_38 -> V_46 ) ;
F_54 ( V_47 , & V_38 -> V_47 ) ;
F_54 ( 0 , & V_38 -> V_49 ) ;
}
static int F_259 ( struct V_8 * V_16 ,
struct V_53 * V_54 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
int V_52 ;
T_5 V_65 ;
int V_701 ;
bool V_702 ;
unsigned int V_703 ;
unsigned int V_697 ;
struct V_699 * V_700 ;
struct V_37 * V_38 ;
V_701 = F_260 ( V_4 ) ;
if ( V_701 < 0 )
return V_701 ;
V_65 = F_61 ( struct V_53 , V_63 ) -
V_64 ;
if ( V_701 == 0 )
goto V_109;
V_700 = F_261 ( V_4 ) ;
V_38 = V_54 -> V_63 ;
V_697 = V_16 -> V_697 - 1 ;
V_702 = false ;
V_703 = 0 ;
V_52 = 0 ;
while ( 1 ) {
F_256 ( V_38 , V_700 ) ;
if ( ! V_702 )
V_703 ++ ;
V_52 ++ ;
if ( V_52 == V_701 )
break;
V_38 ++ ;
if ( V_52 == V_697 ) {
F_53 (
( V_45 ) V_94 -> V_678 ,
& V_38 -> V_46 ) ;
F_54 ( ( V_701 - V_703 )
* sizeof( * V_38 ) ,
& V_38 -> V_47 ) ;
F_54 ( V_704 ,
& V_38 -> V_49 ) ;
V_702 = true ;
V_703 ++ ;
V_38 = V_94 -> V_677 ;
}
V_700 = F_262 ( V_700 ) ;
}
F_54 ( V_48 , & V_38 -> V_49 ) ;
V_54 -> V_705 = V_702 ;
V_65 += V_703 * sizeof( * V_38 ) ;
V_109:
F_60 ( V_65 , & V_54 -> V_60 . V_65 ) ;
return 0 ;
}
static int F_263 ( struct V_8 * V_16 ,
struct V_706 * V_54 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
int V_52 ;
T_5 V_65 ;
int V_701 ;
bool V_702 ;
unsigned int V_703 ;
unsigned int V_697 ;
struct V_699 * V_700 ;
struct V_37 * V_38 ;
V_701 = F_260 ( V_4 ) ;
if ( V_701 < 0 )
return V_701 ;
V_65 = F_61 ( struct V_706 , V_63 ) -
V_64 ;
V_703 = 0 ;
if ( V_701 == 0 )
goto V_109;
V_700 = F_261 ( V_4 ) ;
V_38 = V_54 -> V_63 ;
V_697 = V_16 -> V_697 - 1 ;
V_702 = false ;
V_52 = 0 ;
while ( 1 ) {
F_256 ( V_38 , V_700 ) ;
if ( ! V_702 )
V_703 ++ ;
V_52 ++ ;
if ( V_52 == V_701 )
break;
V_38 ++ ;
if ( V_52 == V_697 ) {
F_53 (
( V_45 ) V_94 -> V_678 ,
& V_38 -> V_46 ) ;
F_54 ( ( V_701 - V_703 )
* sizeof( * V_38 ) ,
& V_38 -> V_47 ) ;
F_54 ( V_704 ,
& V_38 -> V_49 ) ;
V_702 = true ;
V_703 ++ ;
V_38 = V_94 -> V_677 ;
}
V_700 = F_262 ( V_700 ) ;
}
F_54 ( V_48 , & V_38 -> V_49 ) ;
V_54 -> V_705 = V_702 ;
V_65 += V_703 * sizeof( * V_38 ) ;
V_109:
F_60 ( V_65 , & V_54 -> V_60 . V_65 ) ;
V_54 -> V_707 = V_703 ;
return 0 ;
}
static void F_264 ( struct V_93 * V_94 ,
void * V_470 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_68 ( V_94 ) ;
F_265 ( V_4 ) ;
F_3 ( V_4 ) ;
}
static int F_266 (
struct V_8 * V_16 , struct V_93 * V_94 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_310 * V_311 )
{
int V_103 ;
T_3 V_339 ;
struct V_53 * V_54 ;
V_94 -> V_469 = F_264 ;
V_94 -> V_4 = V_4 ;
V_54 = V_94 -> V_477 ;
memset ( V_54 , 0 ,
F_61 ( struct V_53 , V_63 ) ) ;
V_54 -> V_60 . V_61 = V_62 ;
F_54 ( F_172 ( V_4 ) , & V_54 -> V_40 ) ;
V_54 -> V_67 = V_68 ;
F_60 ( V_94 -> V_509 , & V_54 -> V_457 ) ;
V_54 -> V_467 = V_54 -> V_457 ;
memcpy ( V_54 -> V_66 , V_13 -> V_15 ,
sizeof( V_54 -> V_66 ) ) ;
V_339 = F_267 ( T_3 , V_4 -> V_708 , sizeof( V_54 -> V_58 ) ) ;
memcpy ( V_54 -> V_58 , V_4 -> V_343 , V_339 ) ;
switch ( V_339 ) {
case 6 :
case 10 :
case 12 :
case 16 :
V_54 -> V_69 =
V_70 ;
break;
case 20 :
V_54 -> V_69 =
V_709 ;
break;
case 24 :
V_54 -> V_69 =
V_710 ;
break;
case 28 :
V_54 -> V_69 =
V_711 ;
break;
case 32 :
default:
V_54 -> V_69 =
V_712 ;
break;
}
switch ( V_4 -> V_713 ) {
case V_714 :
V_54 -> V_41 = V_72 ;
break;
case V_715 :
V_54 -> V_41 = V_81 ;
break;
case V_716 :
V_54 -> V_41 = V_91 ;
break;
case V_717 :
V_54 -> V_41 = V_718 ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_86 ,
V_4 -> V_713 ) ;
break;
}
V_103 = F_259 ( V_16 , V_54 , V_4 , V_94 ) ;
if ( V_103 ) {
F_68 ( V_94 ) ;
return V_719 ;
}
F_204 ( V_16 , V_311 , V_486 , V_94 ) ;
return 0 ;
}
static inline int F_268 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_310 * V_311 )
{
struct V_93 * V_94 ;
V_94 = F_66 ( V_16 ) ;
return F_266 ( V_16 , V_94 ,
V_13 , V_4 , V_311 ) ;
}
static inline void F_269 ( struct V_8 * V_16 )
{
if ( ! F_25 ( V_16 ) )
F_195 ( & V_16 -> V_720 ) ;
}
static bool F_270 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_8 * V_16 ;
if ( ! V_94 -> V_97 )
return false ;
V_4 = V_94 -> V_4 ;
if ( ( V_4 -> V_424 & 0xff ) == V_432 )
return false ;
if ( V_378 ( V_4 -> V_424 ) == V_421 )
return false ;
V_13 = V_4 -> V_13 -> V_11 ;
if ( F_38 ( V_13 ) )
return false ;
V_16 = F_6 ( V_4 -> V_13 -> V_376 ) ;
if ( F_10 ( V_16 ) )
return false ;
return true ;
}
static inline void F_271 (
struct V_8 * V_16 ,
struct V_93 * V_94 , bool V_721 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_722 , V_49 ) ;
if ( V_721 )
F_272 ( & V_94 -> V_606 ,
& V_16 -> V_723 ) ;
else
F_135 ( & V_94 -> V_606 ,
& V_16 -> V_723 ) ;
F_131 ( & V_16 -> V_722 , V_49 ) ;
}
static void F_273 ( struct V_93 * V_94 ,
void * V_470 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_68 ( V_94 ) ;
F_3 ( V_4 ) ;
}
static void F_274 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_8 * V_16 ;
V_94 -> V_469 = F_273 ;
V_4 = V_94 -> V_4 ;
V_4 -> V_424 = 0 ;
V_16 = F_6 ( V_4 -> V_13 -> V_376 ) ;
F_271 ( V_16 , V_94 , false ) ;
F_269 ( V_16 ) ;
}
static int F_275 ( struct V_93 * V_94 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_8 * V_16 ;
struct V_310 * V_311 ;
V_4 = V_94 -> V_4 ;
V_13 = V_4 -> V_13 -> V_11 ;
if ( F_41 ( V_13 ) ) {
F_68 ( V_94 ) ;
F_175 ( V_4 , V_724 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
V_16 = F_6 ( V_4 -> V_13 -> V_376 ) ;
V_311 = V_94 -> V_311 ;
F_65 ( V_94 ) ;
return F_266 ( V_16 , V_94 ,
V_13 , V_4 , V_311 ) ;
}
static inline struct V_93 * F_276 (
struct V_8 * V_16 )
{
unsigned long V_49 ;
struct V_93 * V_94 ;
F_129 ( & V_16 -> V_722 , V_49 ) ;
V_94 = F_145 (
& V_16 -> V_723 ,
struct V_93 , V_606 ) ;
if ( V_94 )
F_130 ( & V_94 -> V_606 ) ;
F_131 ( & V_16 -> V_722 , V_49 ) ;
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
V_94 = F_276 ( V_16 ) ;
if ( ! V_94 )
break;
V_103 = F_275 ( V_94 ) ;
if ( V_103 ) {
F_271 ( V_16 , V_94 ,
true ) ;
F_269 ( V_16 ) ;
break;
}
}
F_34 ( V_16 ) ;
}
static void F_277 ( struct V_132 * V_133 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( V_133 , struct V_8 ,
V_720 ) ;
F_23 ( V_16 ) ;
}
static void F_278 (
struct V_8 * V_16 )
{
unsigned long V_49 ;
F_129 ( & V_16 -> V_722 , V_49 ) ;
F_219 ( & V_16 -> V_723 ) ;
F_131 ( & V_16 -> V_722 , V_49 ) ;
}
static void F_279 ( struct V_93 * V_94 ,
void * V_470 )
{
struct V_3 * V_4 ;
V_4 = V_94 -> V_4 ;
F_265 ( V_4 ) ;
if ( V_94 -> V_95 == - V_435 )
F_175 ( V_4 , V_725 ) ;
else if ( F_270 ( V_94 ) ) {
F_274 ( V_94 ) ;
return;
}
F_68 ( V_94 ) ;
F_3 ( V_4 ) ;
}
static inline int F_280 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_3 * V_4 ,
struct V_310 * V_311 )
{
return F_162 ( V_16 , V_4 , V_13 -> V_267 ,
V_4 -> V_343 , V_4 -> V_708 , V_311 , NULL , false ) ;
}
static int F_162 ( struct V_8 * V_16 ,
struct V_3 * V_4 , T_2 V_267 , T_1 * V_58 ,
unsigned int V_339 , struct V_310 * V_311 ,
struct V_303 * V_304 , bool V_97 )
{
int V_103 ;
struct V_93 * V_94 ;
struct V_706 * V_54 ;
V_94 = F_66 ( V_16 ) ;
V_94 -> V_469 = F_279 ;
V_94 -> V_4 = V_4 ;
V_94 -> V_97 = V_97 ;
V_54 = V_94 -> V_477 ;
memset ( V_54 , 0 ,
F_61 ( struct V_53 , V_63 ) ) ;
V_54 -> V_60 . V_61 = V_726 ;
F_54 ( V_267 , & V_54 -> V_727 ) ;
F_54 ( F_172 ( V_4 ) , & V_54 -> V_40 ) ;
V_54 -> V_67 = V_68 ;
F_60 ( V_94 -> V_509 , & V_54 -> V_457 ) ;
V_54 -> V_467 = V_54 -> V_457 ;
if ( V_339 > sizeof( V_54 -> V_58 ) )
V_339 = sizeof( V_54 -> V_58 ) ;
V_54 -> V_339 = V_339 ;
memcpy ( V_54 -> V_58 , V_58 , V_339 ) ;
switch ( V_4 -> V_713 ) {
case V_714 :
V_54 -> V_41 = V_72 ;
break;
case V_715 :
V_54 -> V_41 = V_81 ;
break;
case V_716 :
V_54 -> V_41 = V_91 ;
break;
case V_717 :
V_54 -> V_41 = V_718 ;
break;
default:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_86 ,
V_4 -> V_713 ) ;
break;
}
if ( V_304 ) {
V_54 -> V_728 = true ;
F_60 ( V_304 -> V_307 ,
& V_54 -> V_307 ) ;
F_54 ( V_304 -> V_308 ,
& V_54 -> V_308 ) ;
F_54 ( V_304 -> V_309 ,
& V_54 -> V_309 ) ;
}
V_103 = F_263 ( V_16 , V_54 , V_4 , V_94 ) ;
if ( V_103 ) {
F_68 ( V_94 ) ;
return V_719 ;
}
F_204 ( V_16 , V_311 , V_539 , V_94 ) ;
return 0 ;
}
static inline T_5 F_281 ( struct V_8 * V_16 ,
struct V_3 * V_4 )
{
T_5 V_729 ;
V_729 = F_282 ( F_283 ( V_4 -> V_54 ) ) ;
if ( V_729 > V_16 -> V_696 )
V_729 = 0 ;
return V_729 ;
}
void F_4 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = V_4 -> V_13 -> V_11 ;
F_32 ( & V_13 -> V_730 ) ;
}
static int F_284 ( struct V_9 * V_10 ,
struct V_3 * V_4 )
{
int V_103 ;
struct V_8 * V_16 ;
struct V_12 * V_13 ;
T_5 V_729 ;
struct V_310 * V_311 ;
bool V_731 ;
V_13 = V_4 -> V_13 -> V_11 ;
V_16 = F_6 ( V_10 ) ;
F_27 ( & V_13 -> V_730 ) ;
if ( F_10 ( V_16 ) ) {
F_175 ( V_4 , V_421 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
F_33 ( V_16 ) ;
if ( F_25 ( V_16 ) || F_41 ( V_13 ) ) {
V_103 = V_719 ;
goto V_109;
}
V_4 -> V_424 = 0 ;
V_729 = F_281 ( V_16 , V_4 ) ;
V_311 = & V_16 -> V_481 [ V_729 ] ;
if ( F_8 ( V_13 ) ) {
V_731 = false ;
if ( V_13 -> V_189 &&
! F_285 ( V_4 -> V_54 ) ) {
V_103 = F_156 ( V_16 , V_13 ,
V_4 , V_311 ) ;
if ( V_103 == 0 || V_103 == V_719 )
V_731 = true ;
}
if ( ! V_731 )
V_103 = F_268 ( V_16 , V_13 , V_4 ,
V_311 ) ;
} else {
if ( V_13 -> V_263 )
V_103 = F_280 ( V_16 , V_13 , V_4 ,
V_311 ) ;
else
V_103 = F_268 ( V_16 , V_13 , V_4 ,
V_311 ) ;
}
V_109:
F_34 ( V_16 ) ;
if ( V_103 )
F_32 ( & V_13 -> V_730 ) ;
return V_103 ;
}
static int F_286 ( struct V_8 * V_16 ,
struct V_310 * V_311 )
{
unsigned int V_374 ;
unsigned long V_49 ;
bool V_732 ;
for ( V_374 = 0 ; V_374 < 2 ; V_374 ++ ) {
while ( 1 ) {
F_129 (
& V_311 -> V_485 [ V_374 ] , V_49 ) ;
V_732 =
F_287 ( & V_311 -> V_573 [ V_374 ] ) ;
F_131 (
& V_311 -> V_485 [ V_374 ] , V_49 ) ;
if ( V_732 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_106 ;
F_37 ( 1000 , 2000 ) ;
}
}
return 0 ;
}
static int F_288 ( struct V_8 * V_16 )
{
int V_103 ;
unsigned int V_52 ;
unsigned int V_374 ;
struct V_310 * V_311 ;
T_9 V_478 ;
T_9 V_479 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_311 = & V_16 -> V_481 [ V_52 ] ;
V_103 = F_286 ( V_16 , V_311 ) ;
if ( V_103 )
return V_103 ;
for ( V_374 = 0 ; V_374 < 2 ; V_374 ++ ) {
V_478 = V_311 -> V_487 [ V_374 ] ;
while ( 1 ) {
V_479 = * V_311 -> V_479 [ V_374 ] ;
if ( V_479 == V_478 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_106 ;
F_37 ( 1000 , 2000 ) ;
}
}
}
return 0 ;
}
static void F_289 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
unsigned int V_52 ;
unsigned int V_374 ;
struct V_310 * V_311 ;
unsigned long V_49 ;
struct V_93 * V_94 ;
struct V_93 * V_275 ;
struct V_3 * V_4 ;
struct V_12 * V_373 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_311 = & V_16 -> V_481 [ V_52 ] ;
for ( V_374 = 0 ; V_374 < 2 ; V_374 ++ ) {
F_129 (
& V_311 -> V_485 [ V_374 ] , V_49 ) ;
F_134 (io_request, next,
&queue_group->request_list[path],
request_list_entry) {
V_4 = V_94 -> V_4 ;
if ( ! V_4 )
continue;
V_373 = V_4 -> V_13 -> V_11 ;
if ( V_373 != V_13 )
continue;
F_130 ( & V_94 -> V_606 ) ;
F_175 ( V_4 , V_724 ) ;
F_3 ( V_4 ) ;
}
F_131 (
& V_311 -> V_485 [ V_374 ] , V_49 ) ;
}
}
}
static int F_290 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
while ( F_36 ( & V_13 -> V_730 ) ) {
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_106 ;
F_37 ( 1000 , 2000 ) ;
}
return 0 ;
}
static int F_291 ( struct V_8 * V_16 )
{
bool V_733 ;
unsigned long V_49 ;
struct V_12 * V_13 ;
while ( 1 ) {
V_733 = false ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
F_121 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( F_36 ( & V_13 -> V_730 ) ) {
V_733 = true ;
break;
}
}
F_131 ( & V_16 -> V_269 ,
V_49 ) ;
if ( ! V_733 )
break;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) )
return - V_106 ;
F_37 ( 1000 , 2000 ) ;
}
return 0 ;
}
static void F_292 ( struct V_93 * V_94 ,
void * V_470 )
{
struct V_607 * V_610 = V_470 ;
F_229 ( V_610 ) ;
}
static int F_293 ( struct V_8 * V_16 ,
struct V_12 * V_13 , struct V_607 * V_608 )
{
int V_103 ;
while ( 1 ) {
if ( F_227 ( V_608 ,
V_734 * V_364 ) ) {
V_103 = 0 ;
break;
}
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = - V_106 ;
break;
}
}
return V_103 ;
}
static int F_294 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
struct V_93 * V_94 ;
F_231 ( V_608 ) ;
struct V_735 * V_54 ;
V_94 = F_66 ( V_16 ) ;
V_94 -> V_469 = F_292 ;
V_94 -> V_470 = & V_608 ;
V_54 = V_94 -> V_477 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_60 . V_61 = V_736 ;
F_60 ( sizeof( * V_54 ) - V_64 ,
& V_54 -> V_60 . V_65 ) ;
F_60 ( V_94 -> V_509 , & V_54 -> V_457 ) ;
memcpy ( V_54 -> V_66 , V_13 -> V_15 ,
sizeof( V_54 -> V_66 ) ) ;
V_54 -> V_737 = V_738 ;
F_204 ( V_16 ,
& V_16 -> V_481 [ V_482 ] , V_486 ,
V_94 ) ;
V_103 = F_293 ( V_16 , V_13 , & V_608 ) ;
if ( V_103 == 0 )
V_103 = V_94 -> V_95 ;
F_68 ( V_94 ) ;
return V_103 ;
}
static int F_295 ( struct V_8 * V_16 ,
struct V_12 * V_13 )
{
int V_103 ;
V_103 = F_294 ( V_16 , V_13 ) ;
if ( V_103 == 0 )
V_103 = F_290 ( V_16 , V_13 ) ;
return V_103 == 0 ? V_739 : V_740 ;
}
static int F_296 ( struct V_3 * V_4 )
{
int V_103 ;
struct V_9 * V_10 ;
struct V_8 * V_16 ;
struct V_12 * V_13 ;
V_10 = V_4 -> V_13 -> V_376 ;
V_16 = F_6 ( V_10 ) ;
V_13 = V_4 -> V_13 -> V_11 ;
F_64 ( & V_16 -> V_36 -> V_88 ,
L_87 ,
V_10 -> V_184 , V_13 -> V_152 , V_13 -> V_153 , V_13 -> V_154 ) ;
F_11 ( V_16 ) ;
if ( F_10 ( V_16 ) ) {
V_103 = V_740 ;
goto V_109;
}
F_146 ( & V_16 -> V_302 ) ;
F_19 ( V_16 ) ;
F_35 ( V_16 ) ;
F_289 ( V_16 , V_13 ) ;
V_103 = F_288 ( V_16 ) ;
F_39 ( V_13 ) ;
F_21 ( V_16 ) ;
if ( V_103 )
V_103 = V_740 ;
else
V_103 = F_295 ( V_16 , V_13 ) ;
F_40 ( V_13 ) ;
F_147 ( & V_16 -> V_302 ) ;
V_109:
F_64 ( & V_16 -> V_36 -> V_88 ,
L_88 ,
V_10 -> V_184 , V_13 -> V_152 , V_13 -> V_153 , V_13 -> V_154 ,
V_103 == V_739 ? L_89 : L_90 ) ;
return V_103 ;
}
static int F_297 ( struct V_373 * V_248 )
{
struct V_12 * V_13 ;
unsigned long V_49 ;
struct V_8 * V_16 ;
struct V_741 * V_742 ;
struct V_743 * V_744 ;
V_16 = F_6 ( V_248 -> V_376 ) ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
if ( F_298 ( V_248 ) == V_161 ) {
V_742 = V_741 ( V_248 ) ;
V_744 = F_299 ( V_742 ) ;
V_13 = F_300 ( V_16 , V_744 ) ;
if ( V_13 ) {
V_13 -> V_153 = F_301 ( V_248 ) ;
V_13 -> V_154 = V_248 -> V_154 ;
V_13 -> V_157 = true ;
}
} else {
V_13 = F_120 ( V_16 , F_298 ( V_248 ) ,
F_301 ( V_248 ) , V_248 -> V_154 ) ;
}
if ( V_13 ) {
V_248 -> V_11 = V_13 ;
V_13 -> V_248 = V_248 ;
if ( V_13 -> V_206 ) {
V_13 -> V_282 = V_13 -> V_206 ;
F_136 ( V_248 ,
V_13 -> V_282 ) ;
}
}
F_131 ( & V_16 -> V_269 , V_49 ) ;
return 0 ;
}
static int F_302 ( struct V_9 * V_10 )
{
struct V_8 * V_16 = F_6 ( V_10 ) ;
return F_303 ( & V_10 -> V_745 , V_16 -> V_36 ) ;
}
static int F_304 ( struct V_8 * V_16 ,
void T_11 * V_746 )
{
struct V_36 * V_36 ;
T_2 V_747 ;
T_2 V_748 ;
T_12 V_749 ;
if ( ! V_746 )
return - V_185 ;
V_36 = V_16 -> V_36 ;
V_749 . V_750 = F_305 ( V_36 -> V_152 ) ;
V_749 . V_152 = V_36 -> V_152 -> V_751 ;
V_749 . V_752 = V_36 -> V_753 ;
V_747 = V_36 -> V_747 ;
V_748 = V_36 -> V_748 ;
V_749 . V_754 = ( ( V_748 << 16 ) & 0xffff0000 ) |
V_747 ;
if ( F_306 ( V_746 , & V_749 , sizeof( V_749 ) ) )
return - V_755 ;
return 0 ;
}
static int F_307 ( void T_11 * V_746 )
{
T_2 V_756 ;
if ( ! V_746 )
return - V_185 ;
V_756 = ( V_757 << 28 ) | ( V_758 << 24 ) |
( V_759 << 16 ) | V_760 ;
if ( F_306 ( V_746 , & V_756 , sizeof( V_756 ) ) )
return - V_755 ;
return 0 ;
}
static void F_308 ( struct V_379 * V_761 ,
struct V_762 * V_762 )
{
int V_763 ;
T_3 V_380 ;
switch ( V_761 -> V_386 ) {
case V_387 :
V_763 = V_764 ;
break;
case V_388 :
V_763 = V_765 ;
break;
case V_397 :
V_763 = V_766 ;
break;
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
V_763 = V_767 ;
break;
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
V_763 = V_768 ;
break;
case V_392 :
V_763 = V_769 ;
break;
case V_393 :
V_763 = V_770 ;
break;
case V_395 :
V_763 = V_771 ;
break;
default:
V_763 = V_772 ;
break;
}
V_380 =
F_100 ( & V_761 -> V_380 ) ;
if ( V_380 == 0 )
V_380 =
F_100 ( & V_761 -> V_414 ) ;
if ( V_380 )
if ( V_380 > sizeof( V_761 -> V_415 ) )
V_380 = sizeof( V_761 -> V_415 ) ;
V_762 -> V_377 = V_761 -> V_95 ;
V_762 -> V_773 = V_763 ;
V_762 -> V_380 = V_380 ;
}
static int F_309 ( struct V_8 * V_16 , void T_11 * V_746 )
{
int V_103 ;
char * V_774 = NULL ;
T_5 V_65 ;
T_3 V_380 ;
T_13 V_775 ;
struct V_53 V_54 ;
struct V_379 V_761 ;
struct V_762 V_762 ;
if ( F_10 ( V_16 ) )
return - V_106 ;
if ( ! V_746 )
return - V_185 ;
if ( ! F_310 ( V_776 ) )
return - V_777 ;
if ( F_311 ( & V_775 , V_746 , sizeof( V_775 ) ) )
return - V_755 ;
if ( V_775 . V_778 < 1 &&
V_775 . V_779 . Type . V_780 != V_781 )
return - V_185 ;
if ( V_775 . V_779 . V_782 > sizeof( V_54 . V_58 ) )
return - V_185 ;
if ( V_775 . V_779 . Type . Type != V_783 )
return - V_185 ;
switch ( V_775 . V_779 . Type . V_780 ) {
case V_781 :
case V_784 :
case V_785 :
break;
default:
return - V_185 ;
}
if ( V_775 . V_778 > 0 ) {
V_774 = F_79 ( V_775 . V_778 , V_108 ) ;
if ( ! V_774 )
return - V_44 ;
if ( V_775 . V_779 . Type . V_780 & V_784 ) {
if ( F_311 ( V_774 , V_775 . V_786 ,
V_775 . V_778 ) ) {
V_103 = - V_755 ;
goto V_109;
}
} else {
memset ( V_774 , 0 , V_775 . V_778 ) ;
}
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 . V_61 = V_62 ;
V_65 = F_61 ( struct V_53 , V_63 ) -
V_64 ;
memcpy ( V_54 . V_66 , V_775 . V_787 . V_788 ,
sizeof( V_54 . V_66 ) ) ;
memcpy ( V_54 . V_58 , V_775 . V_779 . V_789 , V_775 . V_779 . V_782 ) ;
V_54 . V_69 = V_70 ;
switch ( V_775 . V_779 . Type . V_780 ) {
case V_781 :
V_54 . V_41 = V_91 ;
break;
case V_784 :
V_54 . V_41 = V_81 ;
break;
case V_785 :
V_54 . V_41 = V_72 ;
break;
}
V_54 . V_67 = V_68 ;
if ( V_775 . V_778 > 0 ) {
F_54 ( V_775 . V_778 , & V_54 . V_40 ) ;
V_103 = F_50 ( V_16 -> V_36 ,
& V_54 . V_63 [ 0 ] , V_774 ,
V_775 . V_778 , V_92 ) ;
if ( V_103 )
goto V_109;
V_65 += sizeof( V_54 . V_63 [ 0 ] ) ;
}
F_60 ( V_65 , & V_54 . V_60 . V_65 ) ;
V_103 = F_70 ( V_16 , & V_54 . V_60 ,
V_613 , & V_761 , V_27 ) ;
if ( V_775 . V_778 > 0 )
F_55 ( V_16 -> V_36 , V_54 . V_63 , 1 ,
V_92 ) ;
memset ( & V_775 . V_96 , 0 , sizeof( V_775 . V_96 ) ) ;
if ( V_103 == 0 ) {
F_308 ( & V_761 , & V_762 ) ;
V_775 . V_96 . V_790 = V_762 . V_377 ;
V_775 . V_96 . V_791 =
V_762 . V_773 ;
V_380 = V_762 . V_380 ;
if ( V_380 ) {
if ( V_380 >
sizeof( V_775 . V_96 . V_792 ) )
V_380 =
sizeof( V_775 . V_96 . V_792 ) ;
memcpy ( V_775 . V_96 . V_792 ,
V_761 . V_415 , V_380 ) ;
V_775 . V_96 . V_793 = V_380 ;
}
}
if ( F_306 ( V_746 , & V_775 , sizeof( V_775 ) ) ) {
V_103 = - V_755 ;
goto V_109;
}
if ( V_103 == 0 && V_775 . V_778 > 0 &&
( V_775 . V_779 . Type . V_780 & V_785 ) ) {
if ( F_306 ( V_775 . V_786 , V_774 ,
V_775 . V_778 ) ) {
V_103 = - V_755 ;
}
}
V_109:
F_76 ( V_774 ) ;
return V_103 ;
}
static int F_312 ( struct V_373 * V_248 , int V_55 , void T_11 * V_746 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_6 ( V_248 -> V_376 ) ;
switch ( V_55 ) {
case V_794 :
case V_795 :
case V_796 :
V_103 = F_113 ( V_16 ) ;
break;
case V_797 :
V_103 = F_304 ( V_16 , V_746 ) ;
break;
case V_798 :
V_103 = F_307 ( V_746 ) ;
break;
case V_799 :
V_103 = F_309 ( V_16 , V_746 ) ;
break;
default:
V_103 = - V_185 ;
break;
}
return V_103 ;
}
static T_7 F_313 ( struct V_13 * V_88 ,
struct V_800 * V_801 , char * V_39 )
{
T_7 V_260 = 0 ;
struct V_9 * V_10 ;
struct V_8 * V_16 ;
V_10 = F_314 ( V_88 ) ;
V_16 = F_6 ( V_10 ) ;
V_260 += snprintf (buffer + count, PAGE_SIZE - count,
L_91 , DRIVER_VERSION BUILD_TIMESTAMP) ;
V_260 += snprintf ( V_39 + V_260 , V_689 - V_260 ,
L_92 , V_16 -> V_802 ) ;
return V_260 ;
}
static T_7 F_315 ( struct V_13 * V_88 ,
struct V_800 * V_801 , const char * V_39 , T_3 V_260 )
{
struct V_9 * V_10 = F_314 ( V_88 ) ;
F_148 ( V_10 ) ;
return V_260 ;
}
static T_7 F_316 ( struct V_13 * V_88 ,
struct V_800 * V_801 , char * V_39 )
{
int V_260 = 0 ;
unsigned int V_52 ;
for ( V_52 = 0 ; V_52 < F_2 ( V_803 ) ; V_52 ++ ) {
if ( V_803 [ V_52 ] . V_259 == V_804 )
V_260 += snprintf ( V_39 + V_260 , V_689 - V_260 ,
L_93 , V_803 [ V_52 ] . V_805 ) ;
else
V_260 += snprintf ( V_39 + V_260 , V_689 - V_260 ,
L_94 , V_803 [ V_52 ] . V_805 ) ;
}
V_260 += snprintf ( V_39 + V_260 , V_689 - V_260 , L_95 ) ;
return V_260 ;
}
static T_7 F_317 ( struct V_13 * V_88 ,
struct V_800 * V_801 , const char * V_39 , T_3 V_260 )
{
unsigned int V_52 ;
char * V_806 ;
char V_807 [ 32 ] ;
F_318 ( V_807 , V_39 , sizeof( V_807 ) ) ;
V_806 = F_319 ( V_807 ) ;
for ( V_52 = 0 ; V_52 < F_2 ( V_803 ) ; V_52 ++ ) {
if ( strcmp ( V_806 , V_803 [ V_52 ] . V_805 ) == 0 ) {
V_804 = V_803 [ V_52 ] . V_259 ;
return V_260 ;
}
}
return - V_185 ;
}
static T_7 F_320 ( struct V_13 * V_88 ,
struct V_800 * V_801 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_373 * V_248 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
V_45 V_262 ;
V_248 = F_321 ( V_88 ) ;
V_16 = F_6 ( V_248 -> V_376 ) ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
V_13 = V_248 -> V_11 ;
if ( F_8 ( V_13 ) ) {
F_131 ( & V_16 -> V_269 ,
V_49 ) ;
return - V_808 ;
}
V_262 = V_13 -> V_262 ;
F_131 ( & V_16 -> V_269 , V_49 ) ;
return snprintf ( V_39 , V_689 , L_96 , V_262 ) ;
}
static T_7 F_322 ( struct V_13 * V_88 ,
struct V_800 * V_801 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_373 * V_248 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
V_248 = F_321 ( V_88 ) ;
V_16 = F_6 ( V_248 -> V_376 ) ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
V_13 = V_248 -> V_11 ;
V_39 [ 0 ] = V_13 -> V_189 ? '1' : '0' ;
V_39 [ 1 ] = '\n' ;
V_39 [ 2 ] = '\0' ;
F_131 ( & V_16 -> V_269 , V_49 ) ;
return 2 ;
}
static T_7 F_323 ( struct V_13 * V_88 ,
struct V_800 * V_801 , char * V_39 )
{
struct V_8 * V_16 ;
struct V_373 * V_248 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
char * V_1 ;
V_248 = F_321 ( V_88 ) ;
V_16 = F_6 ( V_248 -> V_376 ) ;
F_129 ( & V_16 -> V_269 , V_49 ) ;
V_13 = V_248 -> V_11 ;
if ( F_8 ( V_13 ) )
V_1 = F_1 ( V_13 -> V_1 ) ;
else
V_1 = L_97 ;
F_131 ( & V_16 -> V_269 , V_49 ) ;
return snprintf ( V_39 , V_689 , L_57 , V_1 ) ;
}
static int F_324 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_9 * V_10 ;
V_10 = F_325 ( & V_809 , sizeof( V_16 ) ) ;
if ( ! V_10 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_98 ,
V_16 -> V_810 ) ;
return - V_44 ;
}
V_10 -> V_811 = 0 ;
V_10 -> V_812 = 0 ;
V_10 -> V_813 = - 1 ;
V_10 -> V_814 = V_815 ;
V_10 -> V_816 = V_817 ;
V_10 -> V_818 = ~ 0 ;
V_10 -> V_819 = ~ 0 ;
V_10 -> V_691 = V_16 -> V_691 ;
V_10 -> V_820 = V_16 -> V_683 ;
V_10 -> V_821 = V_10 -> V_820 ;
V_10 -> V_690 = V_16 -> V_690 ;
V_10 -> V_822 = V_823 ;
V_10 -> V_535 = F_206 ( V_16 -> V_36 , 0 ) ;
V_10 -> V_824 = V_10 -> V_535 ;
V_10 -> V_825 = V_16 -> V_546 ;
V_10 -> V_11 [ 0 ] = ( unsigned long ) V_16 ;
V_103 = F_326 ( V_10 , & V_16 -> V_36 -> V_88 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_99 ,
V_16 -> V_810 ) ;
goto V_826;
}
V_103 = F_327 ( V_10 , V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_100 ,
V_16 -> V_810 ) ;
goto V_827;
}
V_16 -> V_22 = V_10 ;
return 0 ;
V_827:
F_328 ( V_10 ) ;
V_826:
F_329 ( V_10 ) ;
return V_103 ;
}
static void F_330 ( struct V_8 * V_16 )
{
struct V_9 * V_10 ;
F_331 ( V_16 ) ;
V_10 = V_16 -> V_22 ;
if ( ! V_10 )
return;
F_328 ( V_10 ) ;
F_329 ( V_10 ) ;
}
static int F_332 ( struct V_8 * V_16 )
{
int V_103 ;
T_2 V_828 ;
V_828 = ( V_829 << 5 ) |
V_830 ;
F_181 ( V_828 ,
& V_16 -> V_360 -> V_831 ) ;
V_103 = F_163 ( V_16 ) ;
if ( V_103 )
F_64 ( & V_16 -> V_36 -> V_88 ,
L_101 ) ;
return V_103 ;
}
static int F_333 ( struct V_8 * V_16 )
{
int V_103 ;
struct V_102 * V_832 ;
V_832 = F_79 ( sizeof( * V_832 ) , V_108 ) ;
if ( ! V_832 )
return - V_44 ;
V_103 = F_69 ( V_16 , V_832 ) ;
if ( V_103 )
goto V_109;
memcpy ( V_16 -> V_802 , V_832 -> V_802 ,
sizeof( V_832 -> V_802 ) ) ;
V_16 -> V_802 [ sizeof( V_832 -> V_802 ) ] = '\0' ;
snprintf ( V_16 -> V_802 +
strlen ( V_16 -> V_802 ) ,
sizeof( V_16 -> V_802 ) ,
L_102 , F_100 ( & V_832 -> V_833 ) ) ;
V_109:
F_76 ( V_832 ) ;
return V_103 ;
}
static int F_334 ( struct V_8 * V_16 )
{
T_2 V_834 ;
T_2 V_835 ;
void T_8 * V_836 ;
struct V_837 * V_838 ;
struct V_839 * V_840 ;
V_834 = V_16 -> V_841 ;
V_838 = F_79 ( V_834 , V_108 ) ;
if ( ! V_838 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_103 ) ;
return - V_44 ;
}
V_836 = V_16 -> V_592 +
V_16 -> V_842 ;
F_335 ( V_838 , V_836 , V_834 ) ;
V_835 =
F_58 ( & V_838 -> V_843 ) ;
while ( V_835 ) {
V_840 = ( void * ) V_838 + V_835 ;
switch ( F_100 ( & V_840 -> V_844 ) ) {
case V_845 :
if ( V_846 )
F_87 ( & V_16 -> V_36 -> V_88 ,
L_104 ) ;
else
V_16 -> V_35 =
V_836 +
V_835 +
F_61 (
struct V_847 ,
V_35 ) ;
break;
}
V_835 =
F_100 ( & V_840 -> V_848 ) ;
}
F_76 ( V_838 ) ;
return 0 ;
}
static int F_336 ( struct V_8 * V_16 )
{
int V_103 ;
F_197 ( V_16 , V_530 ) ;
V_103 = F_332 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_337 ( V_16 ) ;
F_17 ( V_16 , V_849 ) ;
return 0 ;
}
static int F_338 ( struct V_8 * V_16 )
{
if ( ! F_12 ( V_16 ) )
return - V_106 ;
if ( F_15 ( V_16 ) == V_849 )
return 0 ;
if ( F_339 ( V_16 ) ) {
F_17 ( V_16 , V_849 ) ;
return 0 ;
}
return F_336 ( V_16 ) ;
}
static int F_340 ( struct V_8 * V_16 )
{
int V_103 ;
V_103 = F_338 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_341 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_342 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_105 ) ;
return V_103 ;
}
V_103 = F_343 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_106 ) ;
return V_103 ;
}
if ( V_686 ) {
if ( V_16 -> V_684 >
V_850 )
V_16 -> V_684 =
V_850 ;
} else {
if ( V_16 -> V_684 >
V_851 )
V_16 -> V_684 =
V_851 ;
}
F_252 ( V_16 ) ;
V_103 = F_249 ( V_16 ) ;
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
V_103 = F_163 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_109 ) ;
return V_103 ;
}
V_16 -> V_852 = true ;
F_17 ( V_16 , V_853 ) ;
V_103 = F_334 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_220 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_110 ) ;
return V_103 ;
}
V_103 = F_221 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_111 ) ;
return V_103 ;
}
V_103 = F_238 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_112 ) ;
return V_103 ;
}
V_103 = F_239 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_254 ( V_16 ) ;
V_103 = F_210 ( V_16 ) ;
if ( V_103 )
return V_103 ;
if ( V_16 -> V_541 < V_16 -> V_546 ) {
V_16 -> V_695 =
V_16 -> V_541 ;
F_254 ( V_16 ) ;
}
V_103 = F_250 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_214 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_113 ) ;
return V_103 ;
}
F_217 ( V_16 ) ;
V_103 = F_205 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_243 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_197 ( V_16 , V_528 ) ;
V_16 -> V_17 = true ;
F_188 ( V_16 ) ;
V_103 = F_245 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_114 ) ;
return V_103 ;
}
V_103 = F_324 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_333 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_115 ) ;
return V_103 ;
}
V_103 = F_78 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_116 ) ;
return V_103 ;
}
F_88 ( V_16 ) ;
F_113 ( V_16 ) ;
return 0 ;
}
static void F_345 ( struct V_8 * V_16 )
{
unsigned int V_52 ;
struct V_576 * V_577 ;
struct V_512 * V_513 ;
V_577 = & V_16 -> V_577 ;
V_577 -> V_487 = 0 ;
V_577 -> V_458 = 0 ;
* V_577 -> V_454 = 0 ;
for ( V_52 = 0 ; V_52 < V_16 -> V_546 ; V_52 ++ ) {
V_16 -> V_481 [ V_52 ] . V_487 [ V_486 ] = 0 ;
V_16 -> V_481 [ V_52 ] . V_487 [ V_539 ] = 0 ;
V_16 -> V_481 [ V_52 ] . V_458 = 0 ;
* V_16 -> V_481 [ V_52 ] . V_479 [ V_486 ] = 0 ;
* V_16 -> V_481 [ V_52 ] . V_479 [ V_539 ] = 0 ;
* V_16 -> V_481 [ V_52 ] . V_454 = 0 ;
}
V_513 = & V_16 -> V_513 ;
* V_513 -> V_454 = 0 ;
V_513 -> V_458 = 0 ;
}
static int F_346 ( struct V_8 * V_16 )
{
int V_103 ;
V_103 = F_338 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_347 ( V_16 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_344 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_108 ) ;
return V_103 ;
}
V_103 = F_163 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_109 ) ;
return V_103 ;
}
V_16 -> V_852 = true ;
F_17 ( V_16 , V_853 ) ;
F_345 ( V_16 ) ;
V_103 = F_221 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_111 ) ;
return V_103 ;
}
V_103 = F_243 ( V_16 ) ;
if ( V_103 )
return V_103 ;
F_197 ( V_16 , V_528 ) ;
V_16 -> V_17 = true ;
F_188 ( V_16 ) ;
F_21 ( V_16 ) ;
V_103 = F_245 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_114 ) ;
return V_103 ;
}
V_103 = F_78 ( V_16 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_116 ) ;
return V_103 ;
}
F_88 ( V_16 ) ;
F_113 ( V_16 ) ;
return 0 ;
}
static inline int F_348 ( struct V_36 * V_36 ,
T_5 V_361 )
{
return F_349 ( V_36 , V_854 ,
V_855 , V_361 ) ;
}
static int F_350 ( struct V_8 * V_16 )
{
int V_103 ;
V_45 V_856 ;
V_103 = F_351 ( V_16 -> V_36 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_117 ) ;
return V_103 ;
}
if ( sizeof( T_4 ) > 4 )
V_856 = F_352 ( 64 ) ;
else
V_856 = F_352 ( 32 ) ;
V_103 = F_353 ( & V_16 -> V_36 -> V_88 , V_856 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 , L_118 ) ;
goto V_857;
}
V_103 = F_354 ( V_16 -> V_36 , V_542 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_119 ) ;
goto V_857;
}
V_16 -> V_592 = F_355 ( F_356 (
V_16 -> V_36 , 0 ) ,
sizeof( struct V_858 ) ) ;
if ( ! V_16 -> V_592 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_120 ) ;
V_103 = - V_44 ;
goto V_859;
}
#define F_357 0x6
V_103 = F_348 ( V_16 -> V_36 ,
F_357 ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_121 ) ;
goto V_859;
}
F_358 ( V_16 -> V_36 ) ;
V_16 -> V_860 = V_16 -> V_592 ;
V_16 -> V_360 = & V_16 -> V_860 -> V_360 ;
F_359 ( V_16 -> V_36 , V_16 ) ;
return 0 ;
V_859:
F_360 ( V_16 -> V_36 ) ;
V_857:
F_361 ( V_16 -> V_36 ) ;
return V_103 ;
}
static void F_362 ( struct V_8 * V_16 )
{
F_363 ( V_16 -> V_592 ) ;
F_360 ( V_16 -> V_36 ) ;
if ( F_364 ( V_16 -> V_36 ) )
F_361 ( V_16 -> V_36 ) ;
F_359 ( V_16 -> V_36 , NULL ) ;
}
static struct V_8 * F_365 ( int V_861 )
{
struct V_8 * V_16 ;
V_16 = F_366 ( sizeof( struct V_8 ) ,
V_108 , V_861 ) ;
if ( ! V_16 )
return NULL ;
F_367 ( & V_16 -> V_300 ) ;
F_367 ( & V_16 -> V_302 ) ;
F_219 ( & V_16 -> V_280 ) ;
F_218 ( & V_16 -> V_269 ) ;
F_368 ( & V_16 -> V_497 , F_185 ) ;
F_369 ( & V_16 -> V_501 , 0 ) ;
F_370 ( & V_16 -> V_33 , F_112 ) ;
F_370 ( & V_16 -> V_134 , F_84 ) ;
F_371 ( & V_16 -> V_505 ) ;
F_368 ( & V_16 -> V_862 , V_863 ) ;
F_372 ( & V_16 -> V_614 ,
V_864 ) ;
F_373 ( & V_16 -> V_23 ) ;
F_219 ( & V_16 -> V_723 ) ;
F_218 ( & V_16 -> V_722 ) ;
F_368 ( & V_16 -> V_720 ,
F_277 ) ;
V_16 -> V_810 = F_67 ( & V_865 ) - 1 ;
V_16 -> V_527 = V_530 ;
V_16 -> V_695 = V_866 ;
return V_16 ;
}
static inline void F_374 ( struct V_8 * V_16 )
{
F_76 ( V_16 ) ;
}
static void F_375 ( struct V_8 * V_16 )
{
F_208 ( V_16 ) ;
F_212 ( V_16 ) ;
}
static void F_376 ( struct V_8 * V_16 )
{
F_190 ( V_16 ) ;
F_375 ( V_16 ) ;
if ( V_16 -> V_561 )
F_248 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_563 ,
V_16 -> V_561 ,
V_16 -> V_562 ) ;
if ( V_16 -> V_578 )
F_248 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_580 ,
V_16 -> V_578 ,
V_16 -> V_579 ) ;
F_247 ( V_16 ) ;
if ( V_16 -> V_466 )
F_248 ( & V_16 -> V_36 -> V_88 ,
V_16 -> V_679 ,
V_16 -> V_466 ,
V_16 -> V_680 ) ;
if ( V_16 -> V_592 )
F_362 ( V_16 ) ;
F_374 ( V_16 ) ;
}
static void F_377 ( struct V_8 * V_16 )
{
F_46 ( V_16 ) ;
F_89 ( V_16 ) ;
F_144 ( V_16 ) ;
F_330 ( V_16 ) ;
if ( V_16 -> V_852 )
F_336 ( V_16 ) ;
F_376 ( V_16 ) ;
}
static void F_378 ( void )
{
switch ( V_804 ) {
case V_867 :
F_379 ( L_122 ) ;
break;
case V_868 :
F_380 () ;
break;
case V_869 :
default:
break;
}
}
static void F_381 ( struct V_8 * V_16 )
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
F_175 ( V_4 , V_421 ) ;
} else {
V_94 -> V_95 = - V_106 ;
V_94 -> V_96 =
& V_870 ;
}
V_94 -> V_469 ( V_94 ,
V_94 -> V_470 ) ;
}
}
static void F_382 ( struct V_8 * V_16 )
{
F_378 () ;
F_190 ( V_16 ) ;
F_375 ( V_16 ) ;
F_46 ( V_16 ) ;
F_89 ( V_16 ) ;
F_35 ( V_16 ) ;
F_381 ( V_16 ) ;
F_278 ( V_16 ) ;
F_21 ( V_16 ) ;
}
static void V_863 ( struct V_132 * V_133 )
{
struct V_8 * V_16 ;
V_16 = F_85 ( V_133 , struct V_8 , V_862 ) ;
F_382 ( V_16 ) ;
}
static void F_13 ( struct V_8 * V_16 )
{
if ( ! V_16 -> V_17 )
return;
V_16 -> V_17 = false ;
V_16 -> V_852 = false ;
F_19 ( V_16 ) ;
if ( ! V_871 )
F_383 ( V_16 ) ;
F_361 ( V_16 -> V_36 ) ;
F_64 ( & V_16 -> V_36 -> V_88 , L_123 ) ;
F_195 ( & V_16 -> V_862 ) ;
}
static void F_384 ( struct V_36 * V_36 ,
const struct V_872 * V_873 )
{
char * V_874 ;
if ( V_873 -> V_875 )
V_874 = ( char * ) V_873 -> V_875 ;
else
V_874 = L_124 ;
F_111 ( & V_36 -> V_88 , L_125 , V_874 ) ;
}
static int F_385 ( struct V_36 * V_36 ,
const struct V_872 * V_873 )
{
int V_103 ;
int V_876 ;
struct V_8 * V_16 ;
F_384 ( V_36 , V_873 ) ;
if ( V_877 &&
V_873 -> V_878 == V_879 &&
V_873 -> V_880 == V_879 ) {
F_87 ( & V_36 -> V_88 ,
L_126 ) ;
return - V_808 ;
}
if ( V_873 -> V_878 == V_879 || V_873 -> V_880 == V_879 )
F_87 ( & V_36 -> V_88 ,
L_127 ) ;
V_876 = F_386 ( & V_36 -> V_88 ) ;
if ( V_876 == V_881 )
F_387 ( & V_36 -> V_88 , 0 ) ;
V_16 = F_365 ( V_876 ) ;
if ( ! V_16 ) {
F_64 ( & V_36 -> V_88 ,
L_128 ) ;
return - V_44 ;
}
V_16 -> V_36 = V_36 ;
V_103 = F_350 ( V_16 ) ;
if ( V_103 )
goto error;
V_103 = F_340 ( V_16 ) ;
if ( V_103 )
goto error;
return 0 ;
error:
F_377 ( V_16 ) ;
return V_103 ;
}
static void F_388 ( struct V_36 * V_36 )
{
struct V_8 * V_16 ;
V_16 = F_389 ( V_36 ) ;
if ( ! V_16 )
return;
F_377 ( V_16 ) ;
}
static void F_390 ( struct V_36 * V_36 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_389 ( V_36 ) ;
if ( ! V_16 )
goto error;
V_103 = F_74 ( V_16 ) ;
if ( V_103 == 0 )
return;
error:
F_87 ( & V_36 -> V_88 ,
L_129 ) ;
}
static void F_391 ( void )
{
unsigned int V_52 ;
if ( ! V_882 )
return;
for ( V_52 = 0 ; V_52 < F_2 ( V_803 ) ; V_52 ++ ) {
if ( strcmp ( V_882 ,
V_803 [ V_52 ] . V_805 ) == 0 ) {
V_804 = V_803 [ V_52 ] . V_259 ;
return;
}
}
F_392 ( L_130 ,
V_542 , V_882 ) ;
}
static void F_393 ( void )
{
F_391 () ;
}
static T_14 int F_394 ( struct V_36 * V_36 , T_15 V_883 )
{
struct V_8 * V_16 ;
V_16 = F_389 ( V_36 ) ;
F_246 ( V_16 ) ;
F_89 ( V_16 ) ;
F_46 ( V_16 ) ;
F_151 ( V_16 ) ;
F_152 ( V_16 ) ;
F_74 ( V_16 ) ;
F_19 ( V_16 ) ;
F_35 ( V_16 ) ;
F_288 ( V_16 ) ;
F_291 ( V_16 ) ;
F_190 ( V_16 ) ;
if ( V_883 . V_492 == V_884 )
return 0 ;
F_395 ( V_36 ) ;
F_396 ( V_36 , F_397 ( V_36 , V_883 ) ) ;
V_16 -> V_17 = false ;
V_16 -> V_852 = false ;
return 0 ;
}
static T_14 int F_398 ( struct V_36 * V_36 )
{
int V_103 ;
struct V_8 * V_16 ;
V_16 = F_389 ( V_36 ) ;
if ( V_36 -> V_885 != V_886 ) {
V_16 -> V_696 = 0 ;
F_375 ( V_16 ) ;
F_197 ( V_16 , V_529 ) ;
V_103 = F_207 ( F_206 ( V_36 , 0 ) , F_203 ,
V_887 , V_542 ,
& V_16 -> V_481 [ 0 ] ) ;
if ( V_103 ) {
F_64 ( & V_16 -> V_36 -> V_88 ,
L_68 ,
V_36 -> V_535 , V_103 ) ;
return V_103 ;
}
F_188 ( V_16 ) ;
F_21 ( V_16 ) ;
return 0 ;
}
F_396 ( V_36 , V_886 ) ;
F_399 ( V_36 ) ;
return F_346 ( V_16 ) ;
}
static int T_16 F_400 ( void )
{
int V_103 ;
F_401 ( V_888 L_95 ) ;
V_823 =
F_402 ( & V_889 ) ;
if ( ! V_823 )
return - V_808 ;
F_393 () ;
V_103 = F_403 ( & V_890 ) ;
if ( V_103 )
F_404 ( V_823 ) ;
return V_103 ;
}
static void T_17 F_405 ( void )
{
F_406 ( & V_890 ) ;
F_404 ( V_823 ) ;
}
