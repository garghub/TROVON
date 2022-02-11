int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_4 ) ||
( V_2 -> V_3 == V_5 ) ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_7 , struct V_1 , V_8 ) ;
F_4 ( V_2 , 2 , L_1 ) ;
F_5 () ;
F_6 ( V_2 -> V_9 ) ;
F_7 () ;
F_8 ( V_2 -> V_10 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_2 ) ;
F_10 ( V_11 , & V_2 -> V_8 ) ;
}
static inline const char * F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_13 ) {
switch ( V_2 -> V_12 . type ) {
case V_14 :
return L_3 ;
case V_15 :
return L_4 ;
case V_16 :
return L_5 ;
case V_17 :
return L_6 ;
default:
return L_7 ;
}
} else {
switch ( V_2 -> V_12 . type ) {
case V_14 :
return L_8 ;
case V_15 :
return L_9 ;
case V_18 :
return L_10 ;
case V_16 :
return L_11 ;
case V_17 :
return L_12 ;
default:
return L_7 ;
}
}
return L_13 ;
}
const char * F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_13 ) {
switch ( V_2 -> V_12 . type ) {
case V_14 :
return L_14 ;
case V_15 :
return L_15 ;
case V_16 :
return L_16 ;
case V_17 :
return L_17 ;
default:
return L_18 ;
}
} else {
switch ( V_2 -> V_12 . type ) {
case V_14 :
switch ( V_2 -> V_12 . V_19 ) {
case V_20 :
return L_19 ;
case V_21 :
return L_20 ;
case V_22 :
return L_21 ;
case V_23 :
return L_22 ;
case V_24 :
return L_23 ;
case V_25 :
return L_24 ;
case V_26 :
return L_25 ;
case V_27 :
return L_26 ;
default:
return L_27 ;
}
case V_15 :
return L_28 ;
case V_18 :
return L_29 ;
case V_16 :
return L_30 ;
case V_17 :
return L_31 ;
default:
return L_18 ;
}
}
return L_32 ;
}
void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_28 = V_29 ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_28 = NULL ;
}
static bool F_15 ( const struct V_1 * V_2 )
{
return V_2 -> V_28 == V_29 ;
}
void F_16 ( struct V_1 * V_2 , unsigned long V_30 ,
int V_31 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_34 = V_30 ;
if ( V_31 )
V_2 -> V_35 &= V_30 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned long V_30 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_37 = ( V_2 -> V_38 & V_30 ) ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
int F_21 ( struct V_1 * V_2 , unsigned long V_30 )
{
if ( F_15 ( V_2 ) )
return 0 ;
return F_22 ( V_2 -> V_36 ,
F_20 ( V_2 , V_30 ) == 0 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_39 * V_40 , * V_41 ;
F_4 ( V_2 , 5 , L_33 ) ;
F_24 (pool_entry, tmp,
&card->qdio.in_buf_pool.entry_list, list) {
F_25 ( & V_40 -> V_42 ) ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
void * V_43 ;
int V_44 , V_45 ;
F_4 ( V_2 , 5 , L_34 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_47 . V_48 ; ++ V_44 ) {
V_40 = F_27 ( sizeof( * V_40 ) , V_49 ) ;
if ( ! V_40 ) {
F_28 ( V_2 ) ;
return - V_50 ;
}
for ( V_45 = 0 ; V_45 < F_29 ( V_2 ) ; ++ V_45 ) {
V_43 = ( void * ) F_30 ( V_49 ) ;
if ( ! V_43 ) {
while ( V_45 > 0 )
F_31 ( ( unsigned long )
V_40 -> V_51 [ -- V_45 ] ) ;
F_32 ( V_40 ) ;
F_28 ( V_2 ) ;
return - V_50 ;
}
V_40 -> V_51 [ V_45 ] = V_43 ;
}
F_33 ( & V_40 -> V_52 ,
& V_2 -> V_46 . V_47 . V_53 ) ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 , int V_54 )
{
F_4 ( V_2 , 2 , L_35 ) ;
if ( ( V_2 -> V_3 != V_55 ) &&
( V_2 -> V_3 != V_56 ) )
return - V_57 ;
F_23 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_46 . V_58 . V_48 = V_54 ;
V_2 -> V_46 . V_47 . V_48 = V_54 ;
return F_26 ( V_2 ) ;
}
static void F_35 ( struct V_59 * V_60 )
{
if ( ! V_60 )
return;
F_36 ( V_60 -> V_61 , V_62 ) ;
F_32 ( V_60 ) ;
}
static struct V_59 * F_37 ( void )
{
struct V_59 * V_60 = F_27 ( sizeof( * V_60 ) , V_49 ) ;
int V_44 ;
if ( ! V_60 )
return NULL ;
if ( F_38 ( V_60 -> V_61 , V_62 ) ) {
F_32 ( V_60 ) ;
return NULL ;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 )
V_60 -> V_63 [ V_44 ] . V_64 = V_60 -> V_61 [ V_44 ] ;
F_39 ( V_65 , 2 , & V_60 , sizeof( void * ) ) ;
return V_60 ;
}
static inline int F_40 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
F_41 ( V_65 , 2 , L_36 ) ;
F_42 ( V_2 -> V_46 . V_69 -> V_61 ,
V_62 ) ;
V_2 -> V_46 . V_69 -> V_70 = 127 ;
V_37 = F_43 ( F_44 ( V_2 ) , V_71 ,
V_2 -> V_46 . V_72 - 1 , 0 ,
127 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
goto V_73;
}
}
V_37 = 0 ;
V_73:
return V_37 ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_44 ;
struct V_74 * V_75 ;
F_41 ( V_65 , 2 , L_38 ) ;
V_2 -> V_46 . V_69 = F_37 () ;
if ( ! V_2 -> V_46 . V_69 ) {
V_37 = - 1 ;
goto V_76;
}
V_2 -> V_46 . V_72 = 2 ;
V_2 -> V_46 . V_77 =
F_27 ( V_2 -> V_46 . V_78 *
V_62 *
sizeof( struct V_74 ) , V_49 ) ;
V_75 = V_2 -> V_46 . V_77 ;
if ( V_75 == NULL ) {
V_37 = - 1 ;
goto V_79;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] -> V_81 = V_75 ;
V_75 += V_62 ;
}
} else {
F_41 ( V_65 , 2 , L_39 ) ;
V_2 -> V_46 . V_69 = NULL ;
V_2 -> V_46 . V_72 = 1 ;
}
F_45 ( V_65 , 2 , L_40 , V_2 -> V_46 . V_72 ) ;
V_37 = 0 ;
V_73:
return V_37 ;
V_79:
F_35 ( V_2 -> V_46 . V_69 ) ;
V_2 -> V_46 . V_69 = NULL ;
V_76:
F_47 ( & V_2 -> V_10 -> V_9 , L_41 ) ;
goto V_73;
}
static inline void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 . V_69 ) {
-- V_2 -> V_46 . V_72 ;
F_35 ( V_2 -> V_46 . V_69 ) ;
V_2 -> V_46 . V_69 = NULL ;
}
F_32 ( V_2 -> V_46 . V_77 ) ;
V_2 -> V_46 . V_77 = NULL ;
}
static inline enum V_82 F_49 ( int V_83 ,
int V_84 ) {
enum V_82 V_85 ;
switch ( V_83 ) {
case 0 :
V_85 = V_84 ? V_86 : V_87 ;
break;
case 4 :
case 16 :
case 17 :
case 18 :
V_85 = V_84 ? V_88 :
V_89 ;
break;
default:
V_85 = V_84 ? V_90 :
V_91 ;
break;
}
return V_85 ;
}
static inline void F_50 ( struct V_92 * V_60 ,
int V_93 , int V_94 )
{
if ( V_60 -> V_2 -> V_66 . V_67 != V_68 )
return;
if ( V_60 -> V_63 [ V_93 ] -> V_95 != NULL ) {
struct V_96 * V_97 = V_60 -> V_63 [ V_93 ] ;
struct V_96 * V_98 = V_60 -> V_63 [ V_93 ] -> V_95 ;
while ( V_98 ) {
if ( V_94 ||
F_51 ( & V_98 -> V_3 ) ==
V_99 ) {
struct V_96 * V_100 = V_98 ;
F_4 ( V_100 -> V_60 -> V_2 , 5 , L_42 ) ;
F_52 ( V_100 -> V_60 -> V_2 , 5 , L_43 , ( long ) V_100 ) ;
F_53 ( V_98 ) ;
V_98 = V_100 -> V_95 ;
F_54 ( V_97 -> V_95 != V_100 ) ;
V_97 -> V_95 = V_98 ;
F_55 ( V_101 , V_100 ) ;
} else {
V_97 = V_98 ;
V_98 = V_98 -> V_95 ;
}
}
}
if ( V_94 && ( F_51 ( & ( V_60 -> V_63 [ V_93 ] -> V_3 ) ) ==
V_99 ) ) {
V_60 -> V_63 [ V_93 ] -> V_102 = V_60 -> V_81 [ V_93 ] . V_102 ;
F_56 ( V_60 , V_93 ) ;
F_4 ( V_60 -> V_2 , 2 , L_44 ) ;
}
}
static inline void F_57 ( struct V_1 * V_2 ,
unsigned long V_103 ) {
struct V_104 * V_102 ;
struct V_96 * V_64 ;
enum V_82 V_105 ;
V_102 = (struct V_104 * ) F_58 ( V_103 ) ;
F_4 ( V_2 , 5 , L_45 ) ;
F_52 ( V_2 , 5 , L_43 , V_103 ) ;
V_64 = (struct V_96 * ) V_102 -> V_106 ;
F_52 ( V_2 , 5 , L_43 , V_102 -> V_106 ) ;
if ( F_59 ( & V_64 -> V_3 , V_107 ,
V_108 ) == V_107 ) {
V_105 = V_87 ;
} else {
F_54 ( F_51 ( & V_64 -> V_3 ) !=
V_109 ) ;
F_60 ( & V_64 -> V_3 , V_108 ) ;
V_105 = V_86 ;
}
if ( V_102 -> V_110 != 0 ) {
F_52 ( V_2 , 2 , L_46 , V_102 -> V_110 ) ;
V_105 = F_49 ( V_102 -> V_110 , 1 ) ;
}
F_61 ( V_64 -> V_60 , V_64 , V_105 ) ;
V_64 -> V_102 = NULL ;
F_62 ( V_64 -> V_60 , V_64 ,
V_99 ) ;
F_63 ( V_102 ) ;
}
static inline int F_64 ( struct V_1 * V_2 , unsigned int V_111 )
{
return V_2 -> V_66 . V_67 == V_68 &&
V_2 -> V_46 . V_69 != NULL &&
V_111 != 0 &&
V_111 == V_2 -> V_46 . V_72 - 1 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 5 , L_47 ) ;
if ( V_2 -> V_114 . V_3 != V_115 )
return - V_116 ;
V_113 = F_66 ( & V_2 -> V_114 ) ;
if ( ! V_113 ) {
F_67 ( & V_2 -> V_10 -> V_9 , L_48
L_49 ) ;
F_68 ( 2 , L_50
L_51 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return - V_50 ;
}
F_70 ( & V_2 -> V_114 , V_113 -> V_117 , V_118 ) ;
F_4 ( V_2 , 6 , L_52 ) ;
V_37 = F_71 ( V_2 -> V_114 . V_119 , & V_2 -> V_114 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
if ( V_37 ) {
F_68 ( 2 , L_53
L_54 , F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_60 ( & V_2 -> V_114 . V_122 , 0 ) ;
V_2 -> V_123 = 1 ;
F_72 ( V_2 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
return V_37 ;
}
static struct V_124 * F_73 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
V_125 = F_27 ( sizeof( struct V_124 ) , V_126 ) ;
if ( V_125 ) {
F_60 ( & V_125 -> V_127 , 1 ) ;
F_60 ( & V_125 -> V_128 , 0 ) ;
V_125 -> V_2 = V_2 ;
}
return V_125 ;
}
static void F_74 ( struct V_124 * V_125 )
{
F_75 ( F_51 ( & V_125 -> V_127 ) <= 0 ) ;
F_76 ( & V_125 -> V_127 ) ;
}
static void F_77 ( struct V_124 * V_125 )
{
F_75 ( F_51 ( & V_125 -> V_127 ) <= 0 ) ;
if ( F_78 ( & V_125 -> V_127 ) )
F_32 ( V_125 ) ;
}
static void F_79 ( struct V_129 * V_130 , int V_37 ,
struct V_1 * V_2 )
{
char * V_131 ;
int V_132 = V_130 -> V_133 . V_134 ;
V_131 = F_80 ( V_132 ) ;
if ( V_37 )
F_68 ( 2 , L_55
L_56 ,
V_131 , V_132 , F_69 ( & V_2 -> V_10 -> V_9 ) ,
F_81 ( V_2 ) , V_37 ,
F_82 ( V_37 ) ) ;
else
F_68 ( 5 , L_57 ,
V_131 , V_132 , F_69 ( & V_2 -> V_10 -> V_9 ) ,
F_81 ( V_2 ) ) ;
}
static struct V_129 * F_83 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_129 * V_130 = NULL ;
F_4 ( V_2 , 5 , L_58 ) ;
if ( F_84 ( V_113 -> V_117 ) ) {
V_130 = (struct V_129 * ) F_85 ( V_113 -> V_117 ) ;
if ( F_86 ( V_130 ) ) {
if ( V_130 -> V_133 . V_134 != V_135 &&
V_130 -> V_133 . V_134 != V_136 &&
V_130 -> V_133 . V_134 != V_137 &&
V_130 -> V_133 . V_134 != V_138 )
F_79 ( V_130 ,
V_130 -> V_133 . V_139 , V_2 ) ;
return V_130 ;
} else {
switch ( V_130 -> V_133 . V_134 ) {
case V_140 :
if ( V_130 -> V_133 . V_139 ==
V_141 ) {
F_47 ( & V_2 -> V_10 -> V_9 ,
L_59
L_60
L_61 ,
F_81 ( V_2 ) ) ;
F_9 ( V_2 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_62
L_63 ,
F_81 ( V_2 ) ,
V_2 -> V_12 . V_142 ) ;
F_79 ( V_130 ,
V_130 -> V_133 . V_139 , V_2 ) ;
}
V_2 -> V_143 = 0 ;
if ( V_2 -> V_9 && F_87 ( V_2 -> V_9 ) )
F_88 ( V_2 -> V_9 ) ;
return NULL ;
case V_144 :
F_89 ( & V_2 -> V_10 -> V_9 ,
L_64
L_65 ,
F_81 ( V_2 ) ,
V_2 -> V_12 . V_142 ) ;
F_90 ( V_2 -> V_9 ) ;
V_2 -> V_143 = 1 ;
if ( V_2 -> V_12 . V_145 )
V_2 -> V_12 . V_145 = 2 ;
F_72 ( V_2 ) ;
return NULL ;
case V_146 :
case V_147 :
if ( V_2 -> V_148 -> V_149
( V_2 , V_130 ) )
return V_130 ;
else
return NULL ;
case V_137 :
return V_130 ;
case V_150 :
F_4 ( V_2 , 3 , L_66 ) ;
break;
case V_151 :
F_4 ( V_2 , 3 , L_67 ) ;
break;
default:
F_68 ( 2 , L_68
L_69 ) ;
break;
}
}
}
return V_130 ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_124 * V_125 , * V_152 ;
unsigned long V_32 ;
F_4 ( V_2 , 4 , L_70 ) ;
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_24 (reply, r, &card->cmd_waiter_list, list) {
F_74 ( V_125 ) ;
V_125 -> V_37 = - V_116 ;
F_76 ( & V_125 -> V_128 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_19 ( & V_125 -> V_36 ) ;
F_77 ( V_125 ) ;
}
F_18 ( & V_2 -> V_153 , V_32 ) ;
F_60 ( & V_2 -> V_154 . V_122 , 0 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
unsigned char * V_64 )
{
if ( ! V_64 )
return 0 ;
F_39 ( V_155 , 2 , V_64 , V_156 ) ;
if ( ( V_64 [ 2 ] & 0xc0 ) == 0xc0 ) {
F_68 ( 2 , L_71
L_72 ,
V_64 [ 4 ] ,
( ( V_64 [ 4 ] == 0x22 ) ?
L_73 : L_74 ) ) ;
F_4 ( V_2 , 2 , L_75 ) ;
F_4 ( V_2 , 2 , L_76 ) ;
F_52 ( V_2 , 2 , L_77 , - V_116 ) ;
if ( V_64 [ 4 ] == 0xf6 ) {
F_47 ( & V_2 -> V_10 -> V_9 ,
L_78
L_79 ) ;
return - V_57 ;
}
return - V_116 ;
}
return 0 ;
}
static void F_70 ( struct V_157 * V_158 , unsigned char * V_113 ,
T_1 V_159 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_158 -> V_119 ) ;
F_4 ( V_2 , 4 , L_80 ) ;
if ( V_158 == & V_2 -> V_114 )
memcpy ( & V_158 -> V_120 , V_160 , sizeof( struct V_161 ) ) ;
else
memcpy ( & V_158 -> V_120 , V_162 , sizeof( struct V_161 ) ) ;
V_158 -> V_120 . V_163 = V_159 ;
V_158 -> V_120 . V_164 = ( T_1 ) F_95 ( V_113 ) ;
}
static struct V_112 * F_96 ( struct V_157 * V_158 )
{
T_2 V_165 ;
F_4 ( F_94 ( V_158 -> V_119 ) , 6 , L_81 ) ;
V_165 = V_158 -> V_166 ;
do {
if ( V_158 -> V_113 [ V_165 ] . V_3 == V_167 ) {
V_158 -> V_113 [ V_165 ] . V_3 = V_168 ;
V_158 -> V_166 = ( V_158 -> V_166 + 1 ) %
V_169 ;
memset ( V_158 -> V_113 [ V_165 ] . V_117 , 0 , V_118 ) ;
return V_158 -> V_113 + V_165 ;
}
V_165 = ( V_165 + 1 ) % V_169 ;
} while ( V_165 != V_158 -> V_166 );
return NULL ;
}
void F_97 ( struct V_157 * V_158 ,
struct V_112 * V_113 )
{
unsigned long V_32 ;
F_4 ( F_94 ( V_158 -> V_119 ) , 6 , L_82 ) ;
F_17 ( & V_158 -> V_170 , V_32 ) ;
memset ( V_113 -> V_117 , 0 , V_118 ) ;
V_113 -> V_3 = V_167 ;
V_113 -> V_171 = V_172 ;
V_113 -> V_37 = 0 ;
F_18 ( & V_158 -> V_170 , V_32 ) ;
F_19 ( & V_158 -> V_36 ) ;
}
static struct V_112 * F_66 ( struct V_157 * V_158 )
{
struct V_112 * V_64 = NULL ;
unsigned long V_32 ;
F_17 ( & V_158 -> V_170 , V_32 ) ;
V_64 = F_96 ( V_158 ) ;
F_18 ( & V_158 -> V_170 , V_32 ) ;
return V_64 ;
}
struct V_112 * F_98 ( struct V_157 * V_158 )
{
struct V_112 * V_64 ;
F_99 ( V_158 -> V_36 ,
( ( V_64 = F_66 ( V_158 ) ) != NULL ) ) ;
return V_64 ;
}
void F_100 ( struct V_157 * V_158 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_169 ; V_173 ++ )
F_97 ( V_158 , & V_158 -> V_113 [ V_173 ] ) ;
V_158 -> V_174 = 0 ;
V_158 -> V_166 = 0 ;
}
static void V_172 ( struct V_157 * V_158 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 , * V_152 ;
struct V_129 * V_130 ;
unsigned long V_32 ;
int V_175 ;
int V_37 = 0 ;
V_2 = F_94 ( V_158 -> V_119 ) ;
F_4 ( V_2 , 4 , L_83 ) ;
V_37 = F_93 ( V_2 , V_113 -> V_117 ) ;
switch ( V_37 ) {
case 0 :
break;
case - V_116 :
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
default:
goto V_73;
}
V_130 = F_83 ( V_2 , V_113 ) ;
if ( ( V_130 == NULL ) && ( V_2 -> V_3 != V_55 ) )
goto V_73;
if ( V_2 -> V_12 . type == V_18 &&
V_130 &&
V_130 -> V_133 . V_134 != V_144 &&
V_2 -> V_176 . V_177 != NULL ) {
V_2 -> V_176 . V_177 ( V_2 -> V_9 , V_130 ) ;
goto V_73;
}
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_24 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_125 -> V_178 == V_179 ) ||
( ( V_130 ) && ( V_125 -> V_178 == V_130 -> V_133 . V_178 ) ) ) {
F_74 ( V_125 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
V_175 = 0 ;
if ( V_125 -> V_171 != NULL ) {
if ( V_130 ) {
V_125 -> V_180 = ( V_181 ) ( ( char * ) V_130 -
( char * ) V_113 -> V_117 ) ;
V_175 = V_125 -> V_171 ( V_2 ,
V_125 ,
( unsigned long ) V_130 ) ;
} else
V_175 = V_125 -> V_171 ( V_2 ,
V_125 ,
( unsigned long ) V_113 ) ;
}
if ( V_130 )
V_125 -> V_37 = ( V_182 ) V_130 -> V_133 . V_139 ;
else if ( V_113 -> V_37 )
V_125 -> V_37 = V_113 -> V_37 ;
if ( V_175 ) {
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_101 ( & V_125 -> V_42 ,
& V_2 -> V_183 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
} else {
F_76 ( & V_125 -> V_128 ) ;
F_19 ( & V_125 -> V_36 ) ;
}
F_77 ( V_125 ) ;
goto V_73;
}
}
F_18 ( & V_2 -> V_153 , V_32 ) ;
V_73:
memcpy ( & V_2 -> V_178 . V_184 ,
F_102 ( V_113 -> V_117 ) ,
V_185 ) ;
F_97 ( V_158 , V_113 ) ;
}
static int F_103 ( struct V_157 * V_158 )
{
int V_173 ;
F_41 ( V_65 , 2 , L_84 ) ;
for ( V_173 = 0 ; V_173 < V_169 ; V_173 ++ ) {
V_158 -> V_113 [ V_173 ] . V_117 =
F_27 ( V_118 , V_186 | V_49 ) ;
if ( V_158 -> V_113 [ V_173 ] . V_117 == NULL )
break;
V_158 -> V_113 [ V_173 ] . V_3 = V_167 ;
V_158 -> V_113 [ V_173 ] . V_158 = V_158 ;
V_158 -> V_113 [ V_173 ] . V_171 = V_172 ;
V_158 -> V_113 [ V_173 ] . V_37 = 0 ;
}
if ( V_173 < V_169 ) {
while ( V_173 -- > 0 )
F_32 ( V_158 -> V_113 [ V_173 ] . V_117 ) ;
return - V_50 ;
}
V_158 -> V_174 = 0 ;
V_158 -> V_166 = 0 ;
F_60 ( & V_158 -> V_122 , 0 ) ;
F_104 ( & V_158 -> V_170 ) ;
F_105 ( & V_158 -> V_36 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
unsigned long V_187 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( ! ( V_2 -> V_34 & V_187 ) ||
( V_2 -> V_35 & V_187 ) ) {
F_18 ( & V_2 -> V_33 , V_32 ) ;
return - V_57 ;
}
V_2 -> V_35 |= V_187 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return 0 ;
}
void F_107 ( struct V_1 * V_2 , unsigned long V_187 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_35 &= ~ V_187 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
void F_108 ( struct V_1 * V_2 , unsigned long V_187 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_38 &= ~ V_187 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
static int F_109 ( struct V_1 * V_2 , unsigned long V_187 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( V_2 -> V_35 & V_187 ) {
if ( ( V_2 -> V_34 & V_187 ) &&
! ( V_2 -> V_38 & V_187 ) ) {
V_37 = 1 ;
V_2 -> V_35 &= ~ V_187 ;
V_2 -> V_38 |= V_187 ;
} else
V_37 = - V_57 ;
}
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
int F_110 ( struct V_1 * V_2 , unsigned long V_187 )
{
int V_37 = 0 ;
F_99 ( V_2 -> V_36 ,
( V_37 = F_109 ( V_2 , V_187 ) ) >= 0 ) ;
return V_37 ;
}
void F_72 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_85 ) ;
if ( F_106 ( V_2 , V_188 ) == 0 )
F_111 ( & V_2 -> V_189 ) ;
}
static int F_112 ( struct V_190 * V_191 , struct V_192 * V_192 )
{
int V_193 , V_194 ;
char * V_195 ;
struct V_1 * V_2 ;
V_195 = ( char * ) V_192 -> V_196 ;
V_194 = V_192 -> V_197 . V_130 . V_194 ;
V_193 = V_192 -> V_197 . V_130 . V_193 ;
V_2 = F_94 ( V_191 ) ;
if ( V_194 & ( V_198 | V_199 |
V_200 | V_201 |
V_202 | V_203 ) ) {
F_4 ( V_2 , 2 , L_86 ) ;
F_67 ( & V_191 -> V_9 , L_48
L_49 ) ;
F_68 ( 2 , L_87 ,
F_69 ( & V_191 -> V_9 ) , V_193 , V_194 ) ;
F_113 ( V_204 , L_88 , V_205 ,
16 , 1 , V_192 , 64 , 1 ) ;
return 1 ;
}
if ( V_193 & V_206 ) {
if ( V_195 [ V_207 ] &
V_208 ) {
F_4 ( V_2 , 2 , L_89 ) ;
return 1 ;
}
if ( V_195 [ V_209 ] &
V_210 ) {
F_4 ( V_2 , 2 , L_90 ) ;
return 1 ;
}
if ( ( V_195 [ 2 ] == 0xaf ) && ( V_195 [ 3 ] == 0xfe ) ) {
F_4 ( V_2 , 2 , L_91 ) ;
return 1 ;
}
if ( ( ! V_195 [ 0 ] ) && ( ! V_195 [ 1 ] ) && ( ! V_195 [ 2 ] ) && ( ! V_195 [ 3 ] ) ) {
F_4 ( V_2 , 2 , L_92 ) ;
return 0 ;
}
F_4 ( V_2 , 2 , L_93 ) ;
return 1 ;
}
return 0 ;
}
static long F_114 ( struct V_190 * V_191 ,
unsigned long V_211 , struct V_192 * V_192 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_191 ) ;
if ( ! V_2 || ! F_115 ( V_192 ) )
return 0 ;
switch ( F_116 ( V_192 ) ) {
case - V_116 :
F_68 ( 2 , L_94 ,
F_69 ( & V_191 -> V_9 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_116 ) ;
break;
case - V_212 :
F_67 ( & V_191 -> V_9 , L_96
L_97 ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_212 ) ;
if ( V_211 == V_213 ) {
if ( V_2 -> V_117 . V_119 == V_191 ) {
V_2 -> V_117 . V_3 = V_214 ;
F_19 ( & V_2 -> V_36 ) ;
}
}
break;
default:
F_68 ( 2 , L_98 ,
F_69 ( & V_191 -> V_9 ) , F_116 ( V_192 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_4 ( V_2 , 2 , L_99 ) ;
}
return F_116 ( V_192 ) ;
}
static void F_117 ( struct V_190 * V_191 , unsigned long V_211 ,
struct V_192 * V_192 )
{
int V_37 ;
int V_194 , V_193 ;
struct V_112 * V_64 ;
struct V_157 * V_158 ;
struct V_1 * V_2 ;
struct V_112 * V_113 ;
T_2 V_165 ;
if ( F_114 ( V_191 , V_211 , V_192 ) )
return;
V_194 = V_192 -> V_197 . V_130 . V_194 ;
V_193 = V_192 -> V_197 . V_130 . V_193 ;
V_2 = F_94 ( V_191 ) ;
if ( ! V_2 )
return;
F_4 ( V_2 , 5 , L_100 ) ;
if ( V_2 -> V_114 . V_119 == V_191 ) {
V_158 = & V_2 -> V_114 ;
F_4 ( V_2 , 5 , L_101 ) ;
} else if ( V_2 -> V_154 . V_119 == V_191 ) {
V_158 = & V_2 -> V_154 ;
F_4 ( V_2 , 5 , L_102 ) ;
} else {
V_158 = & V_2 -> V_117 ;
F_4 ( V_2 , 5 , L_103 ) ;
}
F_60 ( & V_158 -> V_122 , 0 ) ;
if ( V_192 -> V_197 . V_130 . V_215 & ( V_216 ) )
V_158 -> V_3 = V_217 ;
if ( V_192 -> V_197 . V_130 . V_215 & ( V_218 ) )
V_158 -> V_3 = V_219 ;
if ( ( V_158 == & V_2 -> V_117 ) && ( V_211 != 0 ) &&
( V_211 != V_213 ) )
goto V_73;
if ( V_211 == V_220 ) {
F_4 ( V_2 , 6 , L_104 ) ;
V_211 = 0 ;
}
if ( V_211 == V_221 ) {
F_4 ( V_2 , 6 , L_105 ) ;
V_211 = 0 ;
}
if ( ( V_193 & V_222 ) ||
( V_193 & V_206 ) ||
( V_194 ) ) {
if ( V_192 -> V_223 . V_224 . V_225 . V_226 ) {
F_67 ( & V_158 -> V_119 -> V_9 ,
L_106
L_107 ) ;
F_68 ( 2 , L_108
L_109 ,
F_69 ( & V_158 -> V_119 -> V_9 ) , V_194 , V_193 ) ;
F_113 ( V_204 , L_88 ,
V_205 , 16 , 1 , V_192 , 32 , 1 ) ;
F_113 ( V_204 , L_110 ,
V_205 , 16 , 1 , V_192 -> V_196 , 32 , 1 ) ;
}
if ( V_211 == V_213 ) {
V_158 -> V_3 = V_214 ;
goto V_73;
}
V_37 = F_112 ( V_191 , V_192 ) ;
if ( V_37 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
}
if ( V_211 == V_213 ) {
V_158 -> V_3 = V_227 ;
goto V_73;
}
if ( V_211 ) {
V_64 = (struct V_112 * ) F_118 ( ( V_121 ) V_211 ) ;
V_64 -> V_3 = V_228 ;
}
if ( V_158 == & V_2 -> V_117 )
return;
if ( V_158 == & V_2 -> V_114 &&
V_158 -> V_3 == V_115 )
F_65 ( V_2 ) ;
V_113 = V_158 -> V_113 ;
V_165 = V_158 -> V_174 ;
while ( V_113 [ V_165 ] . V_3 == V_228 ) {
if ( V_113 [ V_165 ] . V_171 != NULL )
V_113 [ V_165 ] . V_171 ( V_158 , V_113 + V_165 ) ;
V_165 = ( V_165 + 1 ) % V_169 ;
}
V_158 -> V_174 = V_165 ;
V_73:
F_19 ( & V_2 -> V_36 ) ;
return;
}
static void F_61 ( struct V_92 * V_60 ,
struct V_96 * V_229 ,
enum V_82 V_105 )
{
struct V_230 * V_231 ;
if ( F_119 ( & V_229 -> V_232 ) )
goto V_73;
V_231 = F_120 ( & V_229 -> V_232 ) ;
while ( V_231 ) {
F_52 ( V_60 -> V_2 , 5 , L_111 , V_105 ) ;
F_52 ( V_60 -> V_2 , 5 , L_43 , ( long ) V_231 ) ;
if ( V_231 -> V_233 == V_234 ) {
if ( V_231 -> V_235 ) {
struct V_236 * V_237 = F_121 ( V_231 -> V_235 ) ;
V_237 -> V_238 ( V_231 , V_105 ) ;
}
}
if ( F_122 ( & V_229 -> V_232 , V_231 ) )
V_231 = NULL ;
else
V_231 = F_123 ( & V_229 -> V_232 , V_231 ) ;
}
V_73:
return;
}
static void F_53 ( struct V_96 * V_229 )
{
struct V_230 * V_231 ;
struct V_236 * V_237 ;
int V_239 = 0 ;
if ( F_51 ( & V_229 -> V_3 ) == V_109 )
V_239 = 1 ;
F_54 ( F_51 ( & V_229 -> V_3 ) == V_108 ) ;
V_231 = F_124 ( & V_229 -> V_232 ) ;
while ( V_231 ) {
F_4 ( V_229 -> V_60 -> V_2 , 5 , L_112 ) ;
F_52 ( V_229 -> V_60 -> V_2 , 5 , L_43 , ( long ) V_231 ) ;
if ( V_239 && V_231 -> V_233 == V_234 ) {
if ( V_231 -> V_235 ) {
V_237 = F_121 ( V_231 -> V_235 ) ;
V_237 -> V_238 ( V_231 , V_91 ) ;
}
}
F_125 ( & V_231 -> V_240 ) ;
F_126 ( V_231 ) ;
V_231 = F_124 ( & V_229 -> V_232 ) ;
}
}
static void F_62 ( struct V_92 * V_111 ,
struct V_96 * V_229 ,
enum V_241 V_242 )
{
int V_44 ;
if ( V_229 -> V_64 -> V_243 [ 0 ] . V_244 & V_245 )
F_125 ( & V_111 -> V_246 ) ;
if ( V_242 == V_247 ) {
F_53 ( V_229 ) ;
}
for ( V_44 = 0 ; V_44 < F_29 ( V_111 -> V_2 ) ; ++ V_44 ) {
if ( V_229 -> V_64 -> V_243 [ V_44 ] . V_248 && V_229 -> V_249 [ V_44 ] )
F_55 ( V_250 ,
V_229 -> V_64 -> V_243 [ V_44 ] . V_248 ) ;
V_229 -> V_249 [ V_44 ] = 0 ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_251 = 0 ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_248 = NULL ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_252 = 0 ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_244 = 0 ;
}
V_229 -> V_64 -> V_243 [ 15 ] . V_252 = 0 ;
V_229 -> V_64 -> V_243 [ 15 ] . V_244 = 0 ;
V_229 -> V_253 = 0 ;
F_60 ( & V_229 -> V_3 , V_242 ) ;
}
static void F_127 ( struct V_92 * V_60 , int free )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( ! V_60 -> V_63 [ V_45 ] )
continue;
F_50 ( V_60 , V_45 , 1 ) ;
F_62 ( V_60 , V_60 -> V_63 [ V_45 ] , V_247 ) ;
if ( free ) {
F_55 ( V_101 , V_60 -> V_63 [ V_45 ] ) ;
V_60 -> V_63 [ V_45 ] = NULL ;
}
}
}
void F_128 ( struct V_1 * V_2 )
{
int V_44 ;
F_4 ( V_2 , 2 , L_113 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
if ( V_2 -> V_46 . V_80 [ V_44 ] ) {
F_127 ( V_2 -> V_46 . V_80 [ V_44 ] , 0 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_39 * V_40 , * V_41 ;
int V_44 = 0 ;
F_24 (pool_entry, tmp,
&card->qdio.init_pool.entry_list, init_list) {
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 )
F_31 ( ( unsigned long ) V_40 -> V_51 [ V_44 ] ) ;
F_25 ( & V_40 -> V_52 ) ;
F_32 ( V_40 ) ;
}
}
static void F_129 ( struct V_157 * V_158 )
{
int V_173 ;
F_41 ( V_65 , 2 , L_114 ) ;
for ( V_173 = 0 ; V_173 < V_169 ; V_173 ++ )
F_32 ( V_158 -> V_113 [ V_173 ] . V_117 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_254 ) &&
( V_2 -> V_46 . V_78 == 4 ) )
F_131 ( V_2 ) ;
V_2 -> V_46 . V_78 = 1 ;
if ( V_2 -> V_46 . V_255 != 0 )
F_89 ( & V_2 -> V_10 -> V_9 , L_115 ) ;
V_2 -> V_46 . V_255 = 0 ;
}
static void F_132 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_254 ) &&
( V_2 -> V_46 . V_78 == 1 ) ) {
F_131 ( V_2 ) ;
V_2 -> V_46 . V_255 = 2 ;
}
V_2 -> V_46 . V_78 = 4 ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_190 * V_119 ;
struct V_256 * V_257 ;
F_41 ( V_65 , 2 , L_116 ) ;
V_119 = V_2 -> V_117 . V_119 ;
V_257 = F_134 ( V_119 , 0 ) ;
if ( ! V_257 )
goto V_73;
V_2 -> V_12 . V_258 = 0x4100 + V_257 -> V_259 ;
if ( V_2 -> V_12 . type == V_15 )
goto V_73;
if ( ( V_257 -> V_260 & 0x02 ) == 0x02 )
F_130 ( V_2 ) ;
else
F_132 ( V_2 ) ;
V_73:
F_32 ( V_257 ) ;
F_45 ( V_65 , 2 , L_117 , V_2 -> V_46 . V_78 ) ;
F_45 ( V_65 , 2 , L_118 , V_2 -> V_12 . V_258 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 4 , L_119 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_254 ) ;
V_2 -> V_46 . V_261 = V_262 ;
if ( V_2 -> V_12 . type == V_15 )
V_2 -> V_46 . V_47 . V_48 = V_263 ;
else
V_2 -> V_46 . V_47 . V_48 = V_264 ;
V_2 -> V_46 . V_58 . V_48 = V_2 -> V_46 . V_47 . V_48 ;
F_136 ( & V_2 -> V_46 . V_58 . V_53 ) ;
F_136 ( & V_2 -> V_46 . V_47 . V_53 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
V_2 -> V_66 . V_265 . type = V_266 ;
V_2 -> V_66 . V_267 . type = V_266 ;
V_2 -> V_66 . V_268 = 0 ;
V_2 -> V_66 . V_269 = V_270 ;
V_2 -> V_66 . V_271 = 0 ;
V_2 -> V_66 . V_272 = V_273 ;
V_2 -> V_66 . V_274 = V_275 ;
V_2 -> V_66 . V_67 = V_276 ;
}
static int F_138 ( struct V_1 * V_2 , unsigned long V_187 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
F_52 ( V_2 , 4 , L_120 ,
( V_277 ) V_2 -> V_35 ,
( V_277 ) V_2 -> V_34 ,
( V_277 ) V_2 -> V_38 ) ;
V_37 = ( V_2 -> V_35 & V_187 ) ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
static void F_139 ( struct V_6 * V_7 )
{
struct V_278 * V_279 ;
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_189 ) ;
F_4 ( V_2 , 2 , L_121 ) ;
if ( V_2 -> V_114 . V_3 != V_115 &&
V_2 -> V_154 . V_3 != V_115 )
return;
if ( F_138 ( V_2 , V_188 ) ) {
V_279 = F_140 ( V_2 -> V_148 -> V_280 , ( void * ) V_2 ,
L_122 ) ;
if ( F_115 ( V_279 ) ) {
F_107 ( V_2 , V_188 ) ;
F_108 ( V_2 ,
V_188 ) ;
}
}
}
static int F_141 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_123 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_114 . V_3 = V_214 ;
V_2 -> V_154 . V_3 = V_214 ;
V_2 -> V_117 . V_3 = V_214 ;
V_2 -> V_3 = V_55 ;
V_2 -> V_143 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_9 = NULL ;
F_104 ( & V_2 -> V_281 ) ;
F_104 ( & V_2 -> V_282 ) ;
F_104 ( & V_2 -> V_153 ) ;
F_104 ( & V_2 -> V_283 ) ;
F_104 ( & V_2 -> V_33 ) ;
F_142 ( & V_2 -> V_284 ) ;
F_142 ( & V_2 -> V_285 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_38 = 0 ;
F_143 ( & V_2 -> V_189 , F_139 ) ;
F_136 ( & V_2 -> V_286 ) ;
F_136 ( V_2 -> V_287 ) ;
F_136 ( & V_2 -> V_183 ) ;
F_105 ( & V_2 -> V_36 ) ;
F_137 ( V_2 ) ;
F_136 ( & V_2 -> V_288 . V_289 ) ;
V_2 -> V_288 . V_290 = 0 ;
V_2 -> V_288 . V_291 = 0 ;
V_2 -> V_288 . V_292 = 0 ;
F_135 ( V_2 ) ;
F_144 ( & V_2 -> V_293 , V_294 ) ;
F_143 ( & V_2 -> V_8 , F_2 ) ;
return 0 ;
}
static void F_145 ( struct V_295 * V_296 , struct V_297 * V_298 )
{
struct V_1 * V_2 = F_3 ( V_298 , struct V_1 ,
V_299 ) ;
if ( V_2 -> V_12 . V_300 [ 0 ] )
F_146 ( V_296 , L_124 ,
F_147 ( V_2 ) , V_2 -> V_12 . V_300 ) ;
}
static struct V_1 * F_148 ( void )
{
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_125 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_186 | V_49 ) ;
if ( ! V_2 )
goto V_73;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_287 = F_27 ( sizeof( struct V_301 ) , V_49 ) ;
if ( ! V_2 -> V_287 ) {
F_41 ( V_65 , 0 , L_126 ) ;
goto V_302;
}
if ( F_103 ( & V_2 -> V_114 ) )
goto V_303;
if ( F_103 ( & V_2 -> V_154 ) )
goto V_304;
V_2 -> V_66 . V_305 = - 1 ;
V_2 -> V_299 . V_306 = F_145 ;
F_149 ( & V_2 -> V_299 ) ;
return V_2 ;
V_304:
F_129 ( & V_2 -> V_114 ) ;
V_303:
F_32 ( V_2 -> V_287 ) ;
V_302:
F_32 ( V_2 ) ;
V_73:
return NULL ;
}
static int F_150 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
F_41 ( V_65 , 2 , L_127 ) ;
V_2 -> V_46 . V_307 = V_308 ;
V_2 -> V_46 . V_255 = V_309 ;
while ( V_310 [ V_44 ] [ V_311 ] ) {
if ( ( F_151 ( V_2 ) -> V_312 . V_313 ==
V_310 [ V_44 ] [ V_314 ] ) &&
( F_151 ( V_2 ) -> V_312 . V_315 ==
V_310 [ V_44 ] [ V_311 ] ) ) {
V_2 -> V_12 . type = V_310 [ V_44 ] [ V_311 ] ;
V_2 -> V_46 . V_78 =
V_310 [ V_44 ] [ V_316 ] ;
V_2 -> V_46 . V_72 = 1 ;
V_2 -> V_12 . V_317 =
V_310 [ V_44 ] [ V_318 ] ;
F_133 ( V_2 ) ;
return 0 ;
}
V_44 ++ ;
}
V_2 -> V_12 . type = V_319 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_128
L_129 ) ;
return - V_320 ;
}
static int F_152 ( struct V_157 * V_158 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_158 -> V_119 ) ;
F_4 ( V_2 , 3 , L_130 ) ;
F_17 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
V_37 = F_154 ( V_158 -> V_119 , V_220 ) ;
F_18 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_155 ( V_2 -> V_36 ,
V_158 -> V_3 == V_217 , V_321 ) ;
if ( V_37 == - V_322 )
return V_37 ;
if ( V_158 -> V_3 != V_217 )
return - V_323 ;
V_158 -> V_3 = V_214 ;
return 0 ;
}
static int F_156 ( struct V_157 * V_158 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_158 -> V_119 ) ;
F_4 ( V_2 , 3 , L_131 ) ;
F_17 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
V_37 = F_157 ( V_158 -> V_119 , V_221 ) ;
F_18 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_155 ( V_2 -> V_36 ,
V_158 -> V_3 == V_219 , V_321 ) ;
if ( V_37 == - V_322 )
return V_37 ;
if ( V_158 -> V_3 != V_219 )
return - V_323 ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_324 = 0 , V_325 = 0 , V_326 = 0 ;
F_4 ( V_2 , 3 , L_132 ) ;
V_324 = F_156 ( & V_2 -> V_114 ) ;
V_325 = F_156 ( & V_2 -> V_154 ) ;
V_326 = F_156 ( & V_2 -> V_117 ) ;
if ( V_324 )
return V_324 ;
if ( V_325 )
return V_325 ;
return V_326 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_324 = 0 , V_325 = 0 , V_326 = 0 ;
F_4 ( V_2 , 3 , L_133 ) ;
V_324 = F_152 ( & V_2 -> V_114 ) ;
V_325 = F_152 ( & V_2 -> V_154 ) ;
V_326 = F_152 ( & V_2 -> V_117 ) ;
if ( V_324 )
return V_324 ;
if ( V_325 )
return V_325 ;
return V_326 ;
}
static int F_160 ( struct V_1 * V_2 , int V_327 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_134 ) ;
if ( V_327 )
V_37 = F_158 ( V_2 ) ;
if ( V_37 )
return V_37 ;
return F_159 ( V_2 ) ;
}
int F_161 ( struct V_1 * V_2 , int V_328 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_135 ) ;
switch ( F_59 ( & V_2 -> V_46 . V_3 , V_329 ,
V_330 ) ) {
case V_329 :
if ( V_2 -> V_12 . type == V_15 )
V_37 = F_162 ( F_44 ( V_2 ) ,
V_331 ) ;
else
V_37 = F_162 ( F_44 ( V_2 ) ,
V_332 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_37 , V_37 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_333 ) ;
break;
case V_330 :
return V_37 ;
default:
break;
}
V_37 = F_160 ( V_2 , V_328 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_136 , V_37 ) ;
V_2 -> V_3 = V_55 ;
return V_37 ;
}
static int F_163 ( struct V_1 * V_2 , void * * V_64 ,
int * V_251 )
{
struct V_334 * V_334 ;
char * V_335 ;
int V_336 ;
struct V_157 * V_158 = & V_2 -> V_117 ;
unsigned long V_32 ;
V_334 = F_164 ( V_158 -> V_119 , V_337 ) ;
if ( ! V_334 || V_334 -> V_130 == 0 )
return - V_338 ;
V_335 = F_27 ( V_334 -> V_163 , V_49 | V_186 ) ;
if ( ! V_335 )
return - V_50 ;
V_158 -> V_120 . V_339 = V_334 -> V_130 ;
V_158 -> V_120 . V_164 = ( T_1 ) F_95 ( V_335 ) ;
V_158 -> V_120 . V_163 = V_334 -> V_163 ;
V_158 -> V_120 . V_32 = V_340 ;
V_158 -> V_3 = V_341 ;
F_17 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
V_336 = F_165 ( V_158 -> V_119 , & V_158 -> V_120 ,
V_213 , V_342 , 0 ,
V_343 ) ;
F_18 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
if ( ! V_336 )
F_99 ( V_2 -> V_36 ,
( V_158 -> V_3 == V_227 ||
V_158 -> V_3 == V_214 ) ) ;
if ( V_158 -> V_3 == V_214 )
V_336 = - V_116 ;
else
V_158 -> V_3 = V_214 ;
if ( V_336 ) {
F_32 ( V_335 ) ;
* V_64 = NULL ;
* V_251 = 0 ;
} else {
* V_251 = V_334 -> V_163 ;
* V_64 = V_335 ;
}
return V_336 ;
}
static void F_166 ( struct V_1 * V_2 , char * V_344 )
{
F_41 ( V_65 , 2 , L_137 ) ;
V_2 -> V_12 . V_142 = V_344 [ 30 ] ;
V_2 -> V_12 . V_345 = V_344 [ 31 ] ;
V_2 -> V_12 . V_346 = V_344 [ 63 ] ;
V_2 -> V_12 . V_13 = ( ( V_344 [ 0x10 ] == V_347 [ 'V' ] ) &&
( V_344 [ 0x11 ] == V_347 [ 'M' ] ) ) ;
}
static void F_167 ( struct V_1 * V_2 , char * V_344 )
{
F_41 ( V_65 , 2 , L_138 ) ;
if ( V_344 [ 74 ] == 0xF0 && V_344 [ 75 ] == 0xF0 &&
V_344 [ 76 ] >= 0xF1 && V_344 [ 76 ] <= 0xF4 ) {
V_2 -> V_12 . V_348 . V_349 = 0 ;
V_2 -> V_12 . V_348 . V_350 = 0 ;
V_2 -> V_12 . V_348 . V_351 = 0 ;
} else {
V_2 -> V_12 . V_348 . V_349 = 250 ;
V_2 -> V_12 . V_348 . V_350 = 5 ;
V_2 -> V_12 . V_348 . V_351 = 15 ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
V_2 -> V_352 . V_353 = 0x00010103UL ;
V_2 -> V_352 . V_354 = 0x00010108UL ;
V_2 -> V_352 . V_355 = 0x0001010aUL ;
V_2 -> V_352 . V_356 = 0x0001010bUL ;
V_2 -> V_352 . V_357 = 0x0001010dUL ;
}
static void F_169 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
V_2 -> V_12 . V_258 = V_358 ;
break;
case V_14 :
case V_18 :
V_2 -> V_12 . V_258 = V_359 ;
break;
default:
break;
}
}
static int F_170 ( struct V_157 * V_158 ,
void (* F_171)( struct V_157 * ,
struct V_112 * ) )
{
struct V_112 * V_113 ;
unsigned long V_32 ;
int V_37 ;
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_139 ) ;
V_2 = F_94 ( V_158 -> V_119 ) ;
V_113 = F_66 ( V_158 ) ;
V_113 -> V_171 = F_171 ;
memcpy ( & V_158 -> V_120 , V_160 , sizeof( struct V_161 ) ) ;
V_158 -> V_120 . V_163 = V_118 ;
V_158 -> V_120 . V_164 = ( T_1 ) F_95 ( V_113 -> V_117 ) ;
F_99 ( V_2 -> V_36 ,
F_59 ( & V_158 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_158 -> V_119 ,
& V_158 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_140 , V_37 ) ;
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
F_60 ( & V_158 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_155 ( V_2 -> V_36 ,
V_158 -> V_3 == V_115 , V_321 ) ;
if ( V_37 == - V_322 )
return V_37 ;
if ( V_158 -> V_3 != V_115 ) {
V_37 = - V_323 ;
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
F_100 ( V_158 ) ;
} else
V_37 = 0 ;
return V_37 ;
}
static int F_172 ( struct V_157 * V_158 ,
void (* F_171)( struct V_157 * ,
struct V_112 * ) )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
unsigned long V_32 ;
V_181 V_360 ;
T_2 V_41 ;
int V_37 ;
struct V_361 V_362 ;
V_2 = F_94 ( V_158 -> V_119 ) ;
F_41 ( V_65 , 2 , L_142 ) ;
V_113 = F_66 ( V_158 ) ;
V_113 -> V_171 = F_171 ;
memcpy ( & V_158 -> V_120 , V_162 , sizeof( struct V_161 ) ) ;
V_158 -> V_120 . V_163 = V_363 ;
V_158 -> V_120 . V_164 = ( T_1 ) F_95 ( V_113 -> V_117 ) ;
if ( V_158 == & V_2 -> V_154 ) {
memcpy ( V_113 -> V_117 , V_364 , V_363 ) ;
memcpy ( F_173 ( V_113 -> V_117 ) ,
& V_2 -> V_178 . V_365 , V_185 ) ;
V_2 -> V_178 . V_365 ++ ;
} else {
memcpy ( V_113 -> V_117 , V_366 , V_363 ) ;
memcpy ( F_173 ( V_113 -> V_117 ) ,
& V_2 -> V_178 . V_365 , V_185 ) ;
}
V_41 = ( ( T_2 ) V_2 -> V_12 . V_367 ) | 0x80 ;
memcpy ( F_174 ( V_113 -> V_117 ) , & V_41 , 1 ) ;
memcpy ( F_175 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_353 , V_368 ) ;
memcpy ( F_176 ( V_113 -> V_117 ) ,
& V_2 -> V_12 . V_258 , sizeof( V_181 ) ) ;
F_177 ( F_44 ( V_2 ) , & V_362 ) ;
memcpy ( F_178 ( V_113 -> V_117 ) , & V_362 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_12 . V_346 << 8 ) + V_2 -> V_12 . V_345 ;
memcpy ( F_179 ( V_113 -> V_117 ) , & V_360 , 2 ) ;
F_99 ( V_2 -> V_36 ,
F_59 ( & V_158 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_158 -> V_119 ,
& V_158 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_153 ( V_158 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_143 ,
V_37 ) ;
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
F_60 ( & V_158 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_155 ( V_2 -> V_36 ,
V_158 -> V_3 == V_370 , V_321 ) ;
if ( V_37 == - V_322 )
return V_37 ;
if ( V_158 -> V_3 != V_370 ) {
F_67 ( & V_158 -> V_119 -> V_9 , L_144
L_145 ) ;
F_68 ( 2 , L_146 ,
F_69 ( & V_158 -> V_119 -> V_9 ) ) ;
F_45 ( V_65 , 2 , L_136 , - V_323 ) ;
F_100 ( V_158 ) ;
return - V_323 ;
}
return F_170 ( V_158 , F_171 ) ;
}
static int F_180 ( int V_371 )
{
if ( ( V_371 & 0xff ) == 8 )
return ( V_371 & 0xff ) + 0x400 ;
if ( ( ( V_371 >> 8 ) & 3 ) == 1 )
return ( V_371 & 0xff ) + 0x200 ;
return V_371 ;
}
static void F_181 ( struct V_157 * V_158 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_181 V_360 ;
F_41 ( V_65 , 2 , L_147 ) ;
if ( V_158 -> V_3 == V_214 ) {
V_158 -> V_3 = V_370 ;
goto V_73;
}
V_2 = F_94 ( V_158 -> V_119 ) ;
if ( ! ( F_182 ( V_113 -> V_117 ) ) ) {
if ( F_183 ( V_113 -> V_117 ) == V_372 )
F_47 ( & V_2 -> V_154 . V_119 -> V_9 ,
L_148
L_149 ) ;
else
F_68 ( 2 , L_150
L_151 ,
F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) ) ;
goto V_73;
}
memcpy ( & V_360 , F_176 ( V_113 -> V_117 ) , 2 ) ;
if ( ( V_360 & ~ 0x0100 ) != F_180 ( V_2 -> V_12 . V_258 ) ) {
F_68 ( 2 , L_152
L_153
L_154 , F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_258 , V_360 ) ;
goto V_73;
}
V_158 -> V_3 = V_115 ;
V_73:
F_97 ( V_158 , V_113 ) ;
}
static void F_184 ( struct V_157 * V_158 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_181 V_360 ;
F_41 ( V_65 , 2 , L_155 ) ;
if ( V_158 -> V_3 == V_214 ) {
V_158 -> V_3 = V_370 ;
goto V_73;
}
V_2 = F_94 ( V_158 -> V_119 ) ;
if ( F_93 ( V_2 , V_113 -> V_117 ) )
goto V_73;
if ( ! ( F_182 ( V_113 -> V_117 ) ) ) {
switch ( F_183 ( V_113 -> V_117 ) ) {
case V_372 :
F_47 ( & V_2 -> V_154 . V_119 -> V_9 ,
L_148
L_149 ) ;
break;
case V_373 :
case V_374 :
F_47 ( & V_2 -> V_114 . V_119 -> V_9 ,
L_156
L_157 ) ;
break;
default:
F_68 ( 2 , L_158
L_151 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ) ;
}
F_52 ( V_2 , 2 , L_159 ,
F_183 ( V_113 -> V_117 ) ) ;
goto V_73;
}
if ( ( ! F_185 ( V_113 -> V_117 ) ) ||
( V_2 -> V_12 . type == V_14 ) )
V_2 -> V_12 . V_375 = 1 ;
memcpy ( & V_360 , F_176 ( V_113 -> V_117 ) , 2 ) ;
if ( V_360 != F_180 ( V_2 -> V_12 . V_258 ) ) {
F_68 ( 2 , L_160
L_161 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_258 , V_360 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_352 . V_376 ,
F_175 ( V_113 -> V_117 ) ,
V_368 ) ;
memcpy ( & V_2 -> V_12 . V_300 [ 0 ] ,
F_186 ( V_113 -> V_117 ) , V_377 ) ;
V_158 -> V_3 = V_115 ;
V_73:
F_97 ( V_158 , V_113 ) ;
}
void F_187 ( struct V_1 * V_2 , int V_159 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_154 , V_113 -> V_117 , V_159 ) ;
V_113 -> V_171 = F_97 ;
memcpy ( F_173 ( V_113 -> V_117 ) ,
& V_2 -> V_178 . V_365 , V_185 ) ;
V_2 -> V_178 . V_365 ++ ;
memcpy ( F_102 ( V_113 -> V_117 ) ,
& V_2 -> V_178 . V_378 , V_185 ) ;
V_2 -> V_178 . V_378 ++ ;
memcpy ( F_188 ( V_113 -> V_117 ) ,
& V_2 -> V_178 . V_184 , V_185 ) ;
F_39 ( V_155 , 2 , V_113 -> V_117 , V_156 ) ;
}
int F_189 ( struct V_1 * V_2 , int V_159 ,
struct V_112 * V_113 ,
int (* F_190)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_379 )
{
int V_37 ;
unsigned long V_32 ;
struct V_124 * V_125 = NULL ;
unsigned long V_380 , V_381 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 2 , L_162 ) ;
if ( V_2 -> V_123 ) {
F_97 ( V_113 -> V_158 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_171 = F_190 ;
V_125 -> V_382 = V_379 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_178 = V_179 ;
else
V_125 -> V_178 = V_2 -> V_178 . V_383 ++ ;
F_105 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_101 ( & V_125 -> V_42 , & V_2 -> V_183 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
F_39 ( V_155 , 2 , V_113 -> V_117 , V_156 ) ;
while ( F_59 ( & V_2 -> V_154 . V_122 , 0 , 1 ) ) ;
F_187 ( V_2 , V_159 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_381 = V_384 ;
else
V_381 = V_321 ;
V_380 = V_385 + V_381 ;
F_4 ( V_2 , 6 , L_52 ) ;
F_17 ( F_153 ( V_2 -> V_154 . V_119 ) , V_32 ) ;
V_37 = F_71 ( V_2 -> V_154 . V_119 , & V_2 -> V_154 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_153 ( V_2 -> V_154 . V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_163
L_164 ,
F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) , V_37 ) ;
F_52 ( V_2 , 2 , L_165 , V_37 ) ;
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_77 ( V_125 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
F_97 ( V_113 -> V_158 , V_113 ) ;
F_60 ( & V_2 -> V_154 . V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
if ( ( V_130 -> V_133 . V_134 == V_387 ) &&
( V_130 -> V_133 . V_388 == V_389 ) ) {
if ( ! F_191 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_381 ) )
goto V_390;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_192 ( V_385 , V_380 ) )
goto V_390;
F_193 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_390:
V_125 -> V_37 = - V_323 ;
F_17 ( & V_125 -> V_2 -> V_153 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_125 -> V_2 -> V_153 , V_32 ) ;
F_76 ( & V_125 -> V_128 ) ;
error:
F_60 ( & V_2 -> V_154 . V_122 , 0 ) ;
F_97 ( V_113 -> V_158 , V_113 ) ;
V_2 -> V_154 . V_174 = ( V_2 -> V_154 . V_174 + 1 ) % V_169 ;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_166 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_391 ,
F_195 ( V_113 -> V_117 ) ,
V_368 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_167 ) ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_392 , V_393 ) ;
memcpy ( F_197 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_376 , V_368 ) ;
memcpy ( F_198 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_354 , V_368 ) ;
V_37 = F_189 ( V_2 , V_393 , V_113 ,
F_194 , NULL ) ;
return V_37 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_394 ,
F_200 ( V_113 -> V_117 ) ,
V_368 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_395 , V_396 ) ;
memcpy ( F_202 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_376 , V_368 ) ;
memcpy ( F_203 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_355 , V_368 ) ;
memcpy ( F_204 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_391 , V_368 ) ;
V_37 = F_189 ( V_2 , V_396 , V_113 ,
F_199 , NULL ) ;
return V_37 ;
}
static inline int F_205 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_319 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_397 ;
case V_14 :
switch ( V_2 -> V_12 . V_19 ) {
case V_21 :
case V_25 :
return 2000 ;
default:
return V_2 -> V_66 . V_305 ? 1500 : 1492 ;
}
case V_16 :
case V_17 :
return V_2 -> V_66 . V_305 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_206 ( int V_398 )
{
switch ( V_398 ) {
case 0x4000 :
return 8192 ;
case 0x6000 :
return 16384 ;
case 0xa000 :
return 32768 ;
case 0xffff :
return 57344 ;
default:
return 0 ;
}
}
static inline int F_207 ( struct V_1 * V_2 , int V_399 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_399 >= 576 ) &&
( V_399 <= V_2 -> V_12 . V_397 ) ) ;
case V_18 :
case V_319 :
default:
return 1 ;
}
}
static int F_208 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_181 V_399 , V_398 ;
V_181 V_159 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_170 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_400 ,
F_209 ( V_113 -> V_117 ) ,
V_368 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_398 , F_210 ( V_113 -> V_117 ) , 2 ) ;
V_399 = F_206 ( V_398 ) ;
if ( ! V_399 ) {
V_113 -> V_37 = - V_401 ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
if ( V_2 -> V_12 . V_402 && ( V_2 -> V_12 . V_402 != V_399 ) ) {
if ( V_2 -> V_9 &&
( ( V_2 -> V_9 -> V_399 == V_2 -> V_12 . V_402 ) ||
( V_2 -> V_9 -> V_399 > V_399 ) ) )
V_2 -> V_9 -> V_399 = V_399 ;
F_131 ( V_2 ) ;
}
V_2 -> V_12 . V_402 = V_399 ;
V_2 -> V_12 . V_397 = V_399 ;
V_2 -> V_46 . V_261 = V_399 + 2 * V_403 ;
} else {
V_2 -> V_12 . V_397 = * ( V_181 * ) F_210 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_402 = F_211 ( V_2 -> V_12 . V_397 ,
F_205 ( V_2 ) ) ;
V_2 -> V_46 . V_261 = V_262 ;
}
memcpy ( & V_159 , F_212 ( V_113 -> V_117 ) , 2 ) ;
if ( V_159 >= V_404 ) {
memcpy ( & V_19 ,
F_213 ( V_113 -> V_117 ) , 1 ) ;
V_2 -> V_12 . V_19 = V_19 ;
} else
V_2 -> V_12 . V_19 = 0 ;
F_45 ( V_65 , 2 , L_171 , V_2 -> V_12 . V_19 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 )
{
int V_37 ;
char V_405 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_406 , V_407 ) ;
* ( F_215 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_367 ;
if ( V_2 -> V_66 . V_305 )
if ( V_2 -> V_12 . type == V_18 )
V_405 = V_408 ;
else
V_405 = V_409 ;
else
V_405 = V_410 ;
memcpy ( F_216 ( V_113 -> V_117 ) , & V_405 , 1 ) ;
memcpy ( F_217 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_218 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_356 , V_368 ) ;
memcpy ( F_219 ( V_113 -> V_117 ) ,
V_2 -> V_12 . V_411 , 9 ) ;
V_37 = F_189 ( V_2 , V_407 , V_113 ,
F_208 , NULL ) ;
return V_37 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_173 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_412 ,
F_221 ( V_113 -> V_117 ) ,
V_368 ) ;
if ( ! strncmp ( L_174 , F_221 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_175 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_176
L_177 ) ;
V_113 -> V_37 = - V_413 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 )
{
int V_37 ;
V_181 V_360 ;
struct V_112 * V_113 ;
struct V_361 V_414 ;
F_41 ( V_65 , 2 , L_178 ) ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_415 , V_416 ) ;
memcpy ( F_223 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_224 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_357 , V_368 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_400 , V_368 ) ;
F_177 ( F_44 ( V_2 ) , & V_414 ) ;
memcpy ( F_226 ( V_113 -> V_117 ) , & V_414 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_12 . V_346 << 8 ) + V_2 -> V_12 . V_345 ;
memcpy ( F_227 ( V_113 -> V_117 ) , & V_360 , 2 ) ;
V_37 = F_189 ( V_2 , V_416 , V_113 ,
F_220 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_417 ;
V_37 = 0 ;
V_417 = F_228 ( V_101 , V_126 ) ;
if ( ! V_417 ) {
V_37 = - V_50 ;
goto V_73;
}
V_417 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_229 ( & V_417 -> V_232 ) ;
F_230 ( & V_417 -> V_232 . V_153 , & V_418 ) ;
V_417 -> V_60 = V_60 ;
V_417 -> V_102 = NULL ;
V_417 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_417 -> V_3 , V_247 ) ;
V_60 -> V_63 [ V_93 ] = V_417 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_419 = V_417 ;
F_52 ( V_60 -> V_2 , 2 , L_179 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_417 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_417 -> V_95 ) ;
}
V_73:
return V_37 ;
}
static void F_231 ( struct V_92 * V_60 )
{
if ( ! V_60 )
return;
F_36 ( V_60 -> V_61 , V_62 ) ;
F_32 ( V_60 ) ;
}
static struct V_92 * F_232 ( void )
{
struct V_92 * V_60 = F_27 ( sizeof( * V_60 ) , V_49 ) ;
if ( ! V_60 )
return NULL ;
if ( F_38 ( V_60 -> V_61 , V_62 ) ) {
F_32 ( V_60 ) ;
return NULL ;
}
return V_60 ;
}
static int F_233 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
F_41 ( V_65 , 2 , L_180 ) ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_254 ,
V_333 ) != V_254 )
return 0 ;
F_41 ( V_65 , 2 , L_181 ) ;
V_2 -> V_46 . V_420 = F_37 () ;
if ( ! V_2 -> V_46 . V_420 )
goto V_421;
if ( F_26 ( V_2 ) )
goto V_422;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_423;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_232 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_424;
F_45 ( V_65 , 2 , L_182 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_425 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_426;
}
}
if ( F_46 ( V_2 ) )
goto V_424;
return 0 ;
V_426:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_424:
while ( V_44 > 0 ) {
F_231 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_127 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_423:
F_28 ( V_2 ) ;
V_422:
F_35 ( V_2 -> V_46 . V_420 ) ;
V_2 -> V_46 . V_420 = NULL ;
V_421:
F_60 ( & V_2 -> V_46 . V_3 , V_254 ) ;
return - V_50 ;
}
static void F_131 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_234 ( & V_2 -> V_46 . V_3 , V_254 ) ==
V_254 )
return;
F_48 ( V_2 ) ;
F_235 ( & V_2 -> V_293 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_420 -> V_63 [ V_45 ] . V_427 )
F_126 ( V_2 -> V_46 . V_420 -> V_63 [ V_45 ] . V_427 ) ;
}
F_35 ( V_2 -> V_46 . V_420 ) ;
V_2 -> V_46 . V_420 = NULL ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 . V_80 ) {
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_127 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
F_231 ( V_2 -> V_46 . V_80 [ V_44 ] ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
}
}
static void F_236 ( struct V_1 * V_2 ,
char * V_428 )
{
V_428 [ 0 ] = V_347 [ 'P' ] ;
V_428 [ 1 ] = V_347 [ 'C' ] ;
V_428 [ 2 ] = V_347 [ 'I' ] ;
V_428 [ 3 ] = V_347 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_428 [ 4 ] ) ) = F_237 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_428 [ 8 ] ) ) = F_238 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_428 [ 12 ] ) ) = F_239 ( V_2 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
char * V_428 )
{
V_428 [ 16 ] = V_347 [ 'B' ] ;
V_428 [ 17 ] = V_347 [ 'L' ] ;
V_428 [ 18 ] = V_347 [ 'K' ] ;
V_428 [ 19 ] = V_347 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_428 [ 20 ] ) ) = V_2 -> V_12 . V_348 . V_349 ;
* ( ( unsigned int * ) ( & V_428 [ 24 ] ) ) = V_2 -> V_12 . V_348 . V_350 ;
* ( ( unsigned int * ) ( & V_428 [ 28 ] ) ) =
V_2 -> V_12 . V_348 . V_351 ;
}
static int F_241 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 3 , L_183 ) ;
return F_242 ( F_44 ( V_2 ) ) ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_184 ) ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_429 , V_430 ) ;
memcpy ( F_244 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_245 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
V_37 = F_189 ( V_2 , V_430 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_246 ( struct V_1 * V_2 )
{
int V_37 ;
F_41 ( V_65 , 2 , L_185 ) ;
V_37 = F_65 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
return V_37 ;
}
V_37 = F_196 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_431;
}
V_37 = F_201 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_431;
}
V_37 = F_214 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_431;
}
V_37 = F_222 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_431;
}
V_37 = F_233 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_431;
}
V_37 = F_247 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_131 ( V_2 ) ;
goto V_431;
}
V_37 = F_241 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_431;
}
V_37 = F_243 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
goto V_431;
}
return 0 ;
V_431:
F_161 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_248 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
static void F_249 ( struct V_1 * V_2 )
{
char V_432 [ 15 ] ;
int V_44 ;
sprintf ( V_432 , L_191 , V_2 -> V_12 . V_411 + 1 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_432 [ V_44 ] =
( char ) V_433 [ ( T_2 ) V_432 [ V_44 ] ] ;
V_432 [ 8 ] = 0 ;
F_89 ( & V_2 -> V_10 -> V_9 , L_192
L_193 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? V_2 -> V_12 . V_300 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ,
V_432 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_411 [ 0 ] )
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_197
L_198 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? V_2 -> V_12 . V_300 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
else
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_199 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? V_2 -> V_12 . V_300 : L_74 ,
( V_2 -> V_12 . V_300 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
}
void F_251 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_300 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_300 , L_200 ,
V_2 -> V_12 . V_300 [ 2 ] ,
V_2 -> V_12 . V_300 [ 3 ] ) ;
V_2 -> V_12 . V_300 [ V_377 ] = 0 ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_300 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_300 [ 0 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_300 [ 0 ] ] ;
V_2 -> V_12 . V_300 [ 1 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_300 [ 1 ] ] ;
V_2 -> V_12 . V_300 [ 2 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_300 [ 2 ] ] ;
V_2 -> V_12 . V_300 [ 3 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_300 [ 3 ] ] ;
V_2 -> V_12 . V_300 [ V_377 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_300 [ 0 ] , 0 , V_377 + 1 ) ;
}
if ( V_2 -> V_12 . V_375 )
F_249 ( V_2 ) ;
else
F_250 ( V_2 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_39 * V_434 ;
F_4 ( V_2 , 5 , L_201 ) ;
F_253 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_254 ( V_2 , V_434 ) ;
}
}
static inline struct V_39 * F_255 (
struct V_1 * V_2 )
{
struct V_301 * V_435 ;
struct V_39 * V_434 ;
int V_44 , free ;
struct V_436 * V_436 ;
if ( F_256 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_257 (plh, &card->qdio.in_buf_pool.entry_list) {
V_434 = F_258 ( V_435 , struct V_39 , V_42 ) ;
free = 1 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_259 ( F_260 ( V_434 -> V_51 [ V_44 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_92 ( & V_434 -> V_42 ) ;
return V_434 ;
}
}
V_434 = F_258 ( V_2 -> V_46 . V_58 . V_53 . V_437 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_259 ( F_260 ( V_434 -> V_51 [ V_44 ] ) ) > 1 ) {
V_436 = F_261 ( V_126 ) ;
if ( ! V_436 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_434 -> V_51 [ V_44 ] ) ;
V_434 -> V_51 [ V_44 ] = F_262 ( V_436 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_438 . V_439 ++ ;
}
}
}
F_92 ( & V_434 -> V_42 ) ;
return V_434 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_440 * V_229 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_229 -> V_427 ) ) {
V_229 -> V_427 = F_264 ( V_441 + V_442 ) ;
if ( ! V_229 -> V_427 )
return 1 ;
}
V_40 = F_255 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_229 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_229 -> V_64 -> V_243 [ V_44 ] . V_251 = V_403 ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_248 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_229 -> V_64 -> V_243 [ V_44 ] . V_252 = V_443 ;
else
V_229 -> V_64 -> V_243 [ V_44 ] . V_252 = 0 ;
V_229 -> V_64 -> V_243 [ V_44 ] . V_244 = 0 ;
}
return 0 ;
}
int F_265 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_202 ) ;
F_42 ( V_2 -> V_46 . V_420 -> V_61 ,
V_62 ) ;
F_252 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_263 ( V_2 , & V_2 -> V_46 . V_420 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_420 -> V_70 =
V_2 -> V_46 . V_58 . V_48 - 1 ;
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 , 0 ,
V_2 -> V_46 . V_58 . V_48 - 1 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
return V_37 ;
}
V_37 = F_40 ( V_2 ) ;
if ( V_37 ) {
return V_37 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_42 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_61 ,
V_62 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_62 ( V_2 -> V_46 . V_80 [ V_44 ] ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ,
V_247 ) ;
}
V_2 -> V_46 . V_80 [ V_44 ] -> V_2 = V_2 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_444 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_445 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_446 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_246 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_447 ) ;
}
return 0 ;
}
static inline T_2 F_266 ( enum V_448 V_19 )
{
switch ( V_19 ) {
case V_21 :
return 2 ;
default:
return 1 ;
}
}
static void F_267 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_2 V_134 ,
enum V_449 V_450 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_451 = V_452 ;
V_130 -> V_133 . V_178 = V_2 -> V_178 . V_383 ;
V_130 -> V_133 . V_453 = F_266 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_454 = ( T_2 ) V_2 -> V_12 . V_367 ;
if ( V_2 -> V_66 . V_305 )
V_130 -> V_133 . V_455 = 2 ;
else
V_130 -> V_133 . V_455 = 1 ;
V_130 -> V_133 . V_456 = 1 ;
V_130 -> V_133 . V_388 = V_450 ;
V_130 -> V_133 . V_457 = 0 ;
V_130 -> V_133 . V_458 = 0 ;
}
struct V_112 * F_268 ( struct V_1 * V_2 ,
enum V_459 V_460 , enum V_449 V_450 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_98 ( & V_2 -> V_154 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
F_267 ( V_2 , V_130 , V_460 , V_450 ) ;
return V_113 ;
}
void F_269 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_405 )
{
memcpy ( V_113 -> V_117 , V_461 , V_386 ) ;
memcpy ( F_270 ( V_113 -> V_117 ) , & V_405 , 1 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
}
int F_272 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_190)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_379 )
{
int V_37 ;
char V_405 ;
F_4 ( V_2 , 4 , L_203 ) ;
if ( V_2 -> V_66 . V_305 )
if ( V_2 -> V_12 . type == V_18 )
V_405 = V_408 ;
else
V_405 = V_409 ;
else
V_405 = V_410 ;
F_269 ( V_2 , V_113 , V_405 ) ;
V_37 = F_189 ( V_2 , V_462 ,
V_113 , F_190 , V_379 ) ;
if ( V_37 == - V_323 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_37 ;
}
int F_273 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_204 ) ;
V_113 = F_268 ( V_2 , V_144 , 0 ) ;
V_37 = F_272 ( V_2 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_274 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_205 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 )
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_463 . V_133 . V_139 ;
return 0 ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_206 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_463 . V_117 . V_464 . V_465 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_463 . V_117 . V_464 . V_465 ;
F_45 ( V_65 , 2 , L_207 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_466 . V_467 =
V_130 -> V_117 . V_463 . V_117 . V_464 . V_468 ;
return F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_276 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_469 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_268 ( V_2 , V_470 ,
V_389 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_130 -> V_117 . V_463 . V_133 . V_471 = V_469 ;
V_130 -> V_117 . V_463 . V_133 . V_472 = V_134 ;
V_130 -> V_117 . V_463 . V_133 . V_473 = 1 ;
V_130 -> V_117 . V_463 . V_133 . V_474 = 1 ;
return V_113 ;
}
int F_277 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_208 ) ;
V_113 = F_276 ( V_2 , V_475 ,
sizeof( struct V_476 ) ) ;
V_37 = F_272 ( V_2 , V_113 , F_275 , NULL ) ;
return V_37 ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_209 ) ;
V_130 = (struct V_129 * ) V_117 ;
switch ( V_130 -> V_133 . V_139 ) {
case V_477 :
case V_478 :
F_41 ( V_65 , 2 , L_210 ) ;
V_2 -> V_66 . V_479 . V_467 |= V_480 ;
V_2 -> V_66 . V_481 . V_467 |= V_480 ;
return - 0 ;
default:
if ( V_130 -> V_133 . V_139 ) {
F_68 ( 1 , L_211
L_212 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ,
V_130 -> V_133 . V_139 ) ;
return 0 ;
}
}
if ( V_130 -> V_133 . V_388 == V_389 ) {
V_2 -> V_66 . V_479 . V_467 = V_130 -> V_133 . V_457 ;
V_2 -> V_66 . V_479 . V_482 = V_130 -> V_133 . V_458 ;
} else if ( V_130 -> V_133 . V_388 == V_483 ) {
V_2 -> V_66 . V_481 . V_467 = V_130 -> V_133 . V_457 ;
V_2 -> V_66 . V_481 . V_482 = V_130 -> V_133 . V_458 ;
} else
F_68 ( 1 , L_213
L_214 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_279 ( struct V_1 * V_2 , enum V_449 V_450 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_215 , V_450 ) ;
V_113 = F_268 ( V_2 , V_484 , V_450 ) ;
V_37 = F_272 ( V_2 , V_113 , F_278 , NULL ) ;
return V_37 ;
}
static int F_280 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_485 * V_486 ;
struct V_487 * V_488 ;
F_4 ( V_2 , 2 , L_216 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_486 = (struct V_485 * ) V_125 -> V_382 ;
if ( V_130 -> V_117 . V_463 . V_133 . V_139 == 0 ) {
V_488 = & V_130 -> V_117 . V_463 . V_117 . V_489 ;
V_486 -> V_490 = V_488 -> V_490 ;
V_486 -> V_491 = V_488 -> V_491 ;
F_52 ( V_2 , 2 , L_217 , V_486 -> V_490 ,
V_486 -> V_491 ) ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_487 ( struct V_1 * V_2 ,
struct V_485 * V_486 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_218 ) ;
if ( ! F_281 ( V_2 , V_492 ) )
return - V_338 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_493 ;
V_113 = F_276 ( V_2 , V_492 ,
sizeof( struct V_494 ) ) ;
return F_272 ( V_2 , V_113 ,
F_280 , V_486 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_181 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_219 , V_37 ) ;
else
V_2 -> V_12 . V_495 = V_130 -> V_117 . V_496 . V_497 ;
return 0 ;
}
static int F_283 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_220 ) ;
V_113 = F_268 ( V_2 , V_138 , 0 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_130 -> V_117 . V_496 . V_498 = 16 ;
V_130 -> V_117 . V_496 . V_499 = V_500 ;
return F_272 ( V_2 , V_113 , F_282 , NULL ) ;
}
static void F_284 ( struct V_1 * V_2 , struct V_501 * V_502 )
{
unsigned long V_12 = F_285 ( V_49 ) ;
struct V_503 * V_504 = (struct V_503 * ) V_12 ;
struct V_505 * V_506 = (struct V_505 * ) V_12 ;
struct V_361 V_507 ;
int V_371 ;
V_502 -> V_142 = V_2 -> V_12 . V_142 ;
F_177 ( F_151 ( V_2 ) , & V_507 ) ;
V_502 -> V_508 = V_507 . V_508 ;
V_502 -> V_369 = V_507 . V_369 ;
if ( ! V_12 )
return;
V_371 = F_286 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_371 >= 2 ) && ( F_286 ( V_504 , 2 , 2 , 2 ) == 0 ) )
V_502 -> V_509 = V_504 -> V_510 ;
if ( ( V_371 >= 3 ) && ( F_286 ( V_506 , 3 , 2 , 2 ) == 0 ) ) {
F_287 ( V_506 -> V_511 [ 0 ] . V_512 , sizeof( V_506 -> V_511 [ 0 ] . V_512 ) ) ;
memcpy ( V_502 -> V_513 , V_506 -> V_511 [ 0 ] . V_512 , sizeof( V_502 -> V_513 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_181 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_221 , V_37 ) ;
return 0 ;
}
int F_289 ( struct V_1 * V_2 , enum V_514 V_515 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_222 ) ;
V_113 = F_268 ( V_2 , V_138 , 0 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_130 -> V_117 . V_496 . V_498 = 80 ;
V_130 -> V_117 . V_496 . V_499 = V_516 ;
V_130 -> V_117 . V_496 . type = 1 ;
V_130 -> V_117 . V_496 . V_515 = V_515 ;
switch ( V_515 ) {
case V_517 :
V_130 -> V_117 . V_496 . V_66 = 0x0003 ;
V_130 -> V_117 . V_496 . V_497 = 0x00010000 +
sizeof( struct V_501 ) ;
F_284 ( V_2 ,
(struct V_501 * ) V_130 -> V_117 . V_496 . V_518 ) ;
break;
case V_519 :
V_130 -> V_117 . V_496 . V_66 = 0x0001 ;
break;
case V_520 :
break;
}
return F_272 ( V_2 , V_113 , F_288 , NULL ) ;
}
int F_290 ( struct V_1 * V_2 , struct V_521 * V_229 ,
unsigned int V_522 , const char * V_523 )
{
if ( V_522 ) {
F_4 ( V_2 , 2 , V_523 ) ;
F_52 ( V_2 , 2 , L_223 ,
V_229 -> V_243 [ 15 ] . V_244 ) ;
F_52 ( V_2 , 2 , L_224 ,
V_229 -> V_243 [ 14 ] . V_244 ) ;
F_52 ( V_2 , 2 , L_225 , V_522 ) ;
if ( ( V_229 -> V_243 [ 15 ] . V_244 ) == 0x12 ) {
V_2 -> V_524 . V_525 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_294 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_293 . V_7 ) ;
F_52 ( V_2 , 2 , L_226 , V_2 -> V_526 ) ;
F_291 ( V_2 , V_2 -> V_526 ) ;
}
void F_291 ( struct V_1 * V_2 , int V_165 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_420 ;
struct V_301 * V_527 ;
int V_163 ;
int V_44 ;
int V_37 ;
int V_528 = 0 ;
V_163 = ( V_165 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_165 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_165 ) ;
if ( V_163 >= F_292 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_163 ; ++ V_44 ) {
if ( F_263 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_528 ++ ;
}
}
if ( V_528 < V_163 ) {
F_60 ( & V_2 -> V_529 , 3 ) ;
V_163 = V_528 ;
} else {
F_293 ( & V_2 -> V_529 , - 1 , 0 ) ;
}
if ( ! V_163 ) {
V_44 = 0 ;
F_257 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_227 ) ;
V_2 -> V_526 = V_165 ;
F_294 (
& V_2 -> V_293 ,
V_530 ) ;
}
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_438 . V_531 ++ ;
V_2 -> V_438 . V_532 =
F_295 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_163 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_438 . V_533 +=
F_295 () -
V_2 -> V_438 . V_532 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_228 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_163 ) %
V_62 ;
}
}
static int F_296 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_534 )
{
int V_83 = V_64 -> V_64 -> V_243 [ 15 ] . V_244 ;
F_4 ( V_2 , 6 , L_229 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_534 = 0 ;
} else {
V_534 = 1 ;
}
}
F_290 ( V_2 , V_64 -> V_64 , V_534 , L_230 ) ;
if ( ! V_534 )
return V_535 ;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return V_536 ;
F_4 ( V_2 , 1 , L_231 ) ;
F_52 ( V_2 , 1 , L_232 ,
( V_182 ) V_534 , ( V_277 ) V_83 ) ;
return V_537 ;
}
static void F_297 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_445 ) {
if ( F_51 ( & V_111 -> V_446 )
>= V_538 ) {
F_4 ( V_111 -> V_2 , 6 , L_233 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_438 . V_539 ++ ;
V_111 -> V_445 = 1 ;
}
}
}
static int F_298 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
int V_540 = 0 ;
if ( V_111 -> V_445 ) {
if ( F_51 ( & V_111 -> V_446 )
<= V_541 ) {
F_4 ( V_111 -> V_2 , 6 , L_234 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_438 . V_542 ++ ;
V_111 -> V_445 = 0 ;
V_64 = V_111 -> V_63 [ V_111 -> V_444 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) ==
V_247 ) &&
( V_64 -> V_253 > 0 ) ) {
F_60 ( & V_64 -> V_3 ,
V_107 ) ;
V_540 ++ ;
V_111 -> V_444 =
( V_111 -> V_444 + 1 ) %
V_62 ;
}
}
}
return V_540 ;
}
static int F_299 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_444 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_247 ) &&
( V_64 -> V_253 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_444 =
( V_111 -> V_444 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_300 ( struct V_92 * V_111 , int V_165 ,
int V_163 )
{
struct V_96 * V_229 ;
int V_37 ;
int V_44 ;
unsigned int V_543 ;
for ( V_44 = V_165 ; V_44 < V_165 + V_163 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_229 = V_111 -> V_63 [ V_93 ] ;
V_229 -> V_64 -> V_243 [ V_229 -> V_253 - 1 ] . V_252 |=
V_443 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_419 = V_229 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_445 ) {
if ( ( F_51 ( & V_111 -> V_446 ) >=
( V_538 -
V_544 ) ) &&
! F_51 ( & V_111 -> V_246 ) ) {
F_76 ( & V_111 -> V_246 ) ;
V_229 -> V_64 -> V_243 [ 0 ] . V_244 |= V_245 ;
}
} else {
if ( ! F_51 ( & V_111 -> V_246 ) ) {
F_76 ( & V_111 -> V_246 ) ;
V_229 -> V_64 -> V_243 [ 0 ] . V_244 |= V_245 ;
}
}
}
V_111 -> V_2 -> V_9 -> V_545 = V_385 ;
if ( V_111 -> V_2 -> V_66 . V_271 ) {
V_111 -> V_2 -> V_438 . V_546 ++ ;
V_111 -> V_2 -> V_438 . V_547 =
F_295 () ;
}
V_543 = V_548 ;
if ( F_51 ( & V_111 -> V_246 ) )
V_543 |= V_549 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_543 ,
V_111 -> V_425 , V_165 , V_163 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_438 . V_550 +=
F_295 () -
V_111 -> V_2 -> V_438 . V_547 ;
F_301 ( V_163 , & V_111 -> V_446 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_524 . V_551 += V_163 ;
if ( V_37 == - V_552 )
return;
F_4 ( V_111 -> V_2 , 2 , L_235 ) ;
F_52 ( V_111 -> V_2 , 2 , L_236 , V_111 -> V_425 ) ;
F_52 ( V_111 -> V_2 , 2 , L_237 , V_165 ) ;
F_52 ( V_111 -> V_2 , 2 , L_238 , V_163 ) ;
F_52 ( V_111 -> V_2 , 2 , L_165 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_438 . V_553 += V_163 ;
}
static void F_302 ( struct V_92 * V_111 )
{
int V_165 ;
int V_554 = 0 ;
int V_555 = 0 ;
if ( ( F_51 ( & V_111 -> V_446 ) <= V_541 ) ||
! F_51 ( & V_111 -> V_246 ) ) {
if ( F_234 ( & V_111 -> V_3 , V_556 ) ==
V_447 ) {
F_303 ( V_111 -> V_2 -> V_9 ) ;
V_165 = V_111 -> V_444 ;
V_555 = V_111 -> V_445 ;
F_304 () ;
V_554 += F_298 ( V_111 ) ;
if ( ! V_554 &&
! F_51 ( & V_111 -> V_246 ) )
V_554 +=
F_299 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 &&
V_555 )
V_111 -> V_2 -> V_438 . V_557 +=
V_554 ;
if ( V_554 )
F_300 ( V_111 , V_165 , V_554 ) ;
F_60 ( & V_111 -> V_3 , V_447 ) ;
}
}
}
void F_305 ( struct V_190 * V_119 , int V_111 ,
unsigned long V_558 )
{
struct V_1 * V_2 = (struct V_1 * ) V_558 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_559 ) )
F_306 ( & V_2 -> V_560 ) ;
}
int F_307 ( struct V_1 * V_2 , enum V_561 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_562 ) {
V_37 = - 1 ;
goto V_73;
} else {
if ( V_2 -> V_66 . V_67 == V_67 ) {
V_37 = 0 ;
goto V_73;
}
if ( V_2 -> V_3 != V_55 &&
V_2 -> V_3 != V_56 ) {
V_37 = - 1 ;
goto V_73;
}
F_131 ( V_2 ) ;
V_2 -> V_66 . V_67 = V_67 ;
V_37 = 0 ;
}
V_73:
return V_37 ;
}
static void F_308 ( struct V_1 * V_2 ,
unsigned int V_534 ,
unsigned int V_111 , int V_563 , int V_163 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_239 , V_563 ) ;
F_52 ( V_2 , 5 , L_240 , V_163 ) ;
F_52 ( V_2 , 5 , L_241 , V_534 ) ;
if ( V_534 ) {
F_303 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_438 . V_564 ++ ;
V_2 -> V_438 . V_565 = F_295 () ;
}
for ( V_44 = V_563 ; V_44 < V_563 + V_163 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_521 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_566 ;
V_566 = 0 ;
while ( V_64 -> V_243 [ V_566 ] . V_248 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_243 [ V_566 ] . V_248 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_243 [ V_566 ] . V_248 = NULL ;
V_64 -> V_243 [ V_566 ] . V_252 = 0 ;
V_64 -> V_243 [ V_566 ] . V_244 = 0 ;
V_64 -> V_243 [ V_566 ] . V_251 = 0 ;
++ V_566 ;
}
V_64 -> V_243 [ 15 ] . V_252 = 0 ;
V_64 -> V_243 [ 15 ] . V_244 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_163 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_242 , V_37 ) ;
F_4 ( V_2 , 2 , L_243 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_163 ) % V_62 ;
F_309 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 ) {
int V_567 = F_295 () ;
V_567 -= V_2 -> V_438 . V_565 ;
V_2 -> V_438 . V_568 += V_567 ;
}
V_73:
return;
}
void F_310 ( struct V_190 * V_119 , unsigned int V_534 ,
unsigned int V_111 , int V_569 , int V_163 ,
unsigned long V_558 )
{
struct V_1 * V_2 = (struct V_1 * ) V_558 ;
F_52 ( V_2 , 2 , L_244 , V_111 ) ;
F_52 ( V_2 , 2 , L_245 , V_534 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_308 ( V_2 , V_534 , V_111 , V_569 , V_163 ) ;
else if ( V_534 )
F_72 ( V_2 ) ;
}
void F_311 ( struct V_190 * V_119 ,
unsigned int V_522 , int V_570 , int V_563 ,
int V_163 , unsigned long V_558 )
{
struct V_1 * V_2 = (struct V_1 * ) V_558 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_570 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_246 ) ;
if ( V_522 & V_571 ) {
F_4 ( V_2 , 2 , L_247 ) ;
F_303 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_438 . V_572 ++ ;
V_2 -> V_438 . V_573 =
F_295 () ;
}
for ( V_44 = V_563 ; V_44 < ( V_563 + V_163 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_296 ( V_2 , V_64 , V_522 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_574 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_575 ) ;
}
V_64 -> V_102 = V_111 -> V_81 [ V_93 ] . V_102 ;
F_52 ( V_111 -> V_2 , 5 , L_248 , V_93 ) ;
F_4 ( V_111 -> V_2 , 5 , L_249 ) ;
F_52 ( V_111 -> V_2 , 5 , L_43 ,
F_312 ( V_64 -> V_102 ) ) ;
if ( F_56 ( V_111 , V_93 ) ) {
F_4 ( V_2 , 2 , L_250 ) ;
F_72 ( V_2 ) ;
}
} else {
if ( V_2 -> V_66 . V_67 == V_68 ) {
enum V_82 V_85 ;
V_85 = F_49 (
V_64 -> V_64 -> V_243 [ 15 ] . V_244 , 0 ) ;
F_61 ( V_111 , V_64 , V_85 ) ;
}
F_62 ( V_111 , V_64 ,
V_247 ) ;
}
F_50 ( V_111 , V_93 , 0 ) ;
}
F_313 ( V_163 , & V_111 -> V_446 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_302 ( V_111 ) ;
F_309 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_438 . V_576 += F_295 () -
V_2 -> V_438 . V_573 ;
}
int F_314 ( struct V_1 * V_2 , struct V_230 * V_231 ,
int V_577 , int V_578 )
{
T_3 * V_579 ;
V_277 V_580 ;
if ( V_578 && V_2 -> V_12 . V_317 )
return V_2 -> V_12 . V_317 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_307 ) {
case V_581 :
case V_582 :
switch ( V_577 ) {
case 4 :
V_580 = F_315 ( F_316 ( V_231 ) ) ;
break;
case 6 :
V_580 = F_317 ( F_318 ( V_231 ) ) ;
break;
default:
return V_2 -> V_46 . V_255 ;
}
if ( V_2 -> V_46 . V_307 == V_582 )
return ~ V_580 >> 6 & 3 ;
if ( V_580 & V_583 )
return 3 ;
if ( V_580 & V_584 )
return 2 ;
if ( V_580 & V_585 )
return 1 ;
if ( V_580 & V_586 )
return 0 ;
break;
case V_587 :
if ( V_231 -> V_588 > 5 )
return 0 ;
return ~ V_231 -> V_588 >> 1 & 3 ;
case V_589 :
V_579 = & ( (struct V_590 * ) V_231 -> V_117 ) -> V_591 ;
if ( * V_579 == V_592 )
return ~ * ( V_579 + 1 ) >> ( V_593 + 1 ) & 3 ;
break;
default:
break;
}
return V_2 -> V_46 . V_255 ;
}
int F_319 ( struct V_230 * V_231 )
{
int V_173 , V_251 , V_566 , V_51 = 0 ;
struct V_594 * V_595 ;
char * V_117 ;
for ( V_173 = 0 ; V_173 < F_320 ( V_231 ) -> V_596 ; V_173 ++ ) {
V_595 = & F_320 ( V_231 ) -> V_597 [ V_173 ] ;
V_117 = ( char * ) F_321 ( F_322 ( V_595 ) ) +
V_595 -> V_598 ;
V_251 = V_595 -> V_599 ;
V_566 = F_323 ( ( unsigned long ) V_117 + V_251 - 1 ) -
F_324 ( ( unsigned long ) V_117 ) ;
V_51 += V_566 ;
}
return V_51 ;
}
int F_325 ( struct V_1 * V_2 ,
struct V_230 * V_231 , int V_600 )
{
int V_601 = V_231 -> V_159 - V_231 -> V_602 ;
int V_603 = F_323 ( ( unsigned long ) V_231 -> V_117 + V_601 - 1 ) -
F_324 ( ( unsigned long ) V_231 -> V_117 ) ;
V_603 += F_319 ( V_231 ) ;
if ( ( V_603 + V_600 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_251
L_252 ,
( V_603 + V_600 ) , V_231 -> V_159 ) ;
return 0 ;
}
return V_603 ;
}
int F_326 ( struct V_230 * V_231 , struct V_604 * * V_133 , int V_159 )
{
int V_605 , V_606 , V_607 ;
if ( ( ( unsigned long ) V_231 -> V_117 & V_608 ) !=
( ( ( unsigned long ) V_231 -> V_117 + V_159 - 1 ) & V_608 ) ) {
V_605 = F_327 ( V_231 ) ;
V_606 = V_403 - ( ( unsigned long ) V_231 -> V_117 % V_403 ) ;
V_607 = V_159 - V_606 ;
if ( V_607 > V_605 )
return 1 ;
memmove ( V_231 -> V_117 - V_607 , V_231 -> V_117 , V_231 -> V_159 - V_231 -> V_602 ) ;
V_231 -> V_117 -= V_607 ;
V_231 -> V_609 -= V_607 ;
* V_133 = (struct V_604 * ) V_231 -> V_117 ;
F_68 ( 2 , L_253 , V_159 , V_607 ) ;
}
return 0 ;
}
static inline void F_328 ( struct V_230 * V_231 ,
struct V_521 * V_64 , int V_610 , int * V_253 ,
int V_180 )
{
int V_251 = V_231 -> V_159 - V_231 -> V_602 ;
int V_611 ;
int V_243 ;
char * V_117 ;
int V_612 , V_173 ;
struct V_594 * V_595 ;
V_243 = * V_253 ;
V_117 = V_231 -> V_117 ;
V_612 = ( V_610 == 0 ? 1 : 0 ) ;
if ( V_180 >= 0 ) {
V_117 = V_231 -> V_117 + V_180 ;
V_251 -= V_180 ;
V_612 = 0 ;
}
while ( V_251 > 0 ) {
V_611 = V_403 - ( ( unsigned long ) V_117 % V_403 ) ;
if ( V_251 < V_611 )
V_611 = V_251 ;
V_64 -> V_243 [ V_243 ] . V_248 = V_117 ;
V_64 -> V_243 [ V_243 ] . V_251 = V_611 ;
V_251 -= V_611 ;
if ( ! V_251 ) {
if ( V_612 )
if ( F_320 ( V_231 ) -> V_596 )
V_64 -> V_243 [ V_243 ] . V_252 =
V_613 ;
else
V_64 -> V_243 [ V_243 ] . V_252 = 0 ;
else
V_64 -> V_243 [ V_243 ] . V_252 =
V_614 ;
} else {
if ( V_612 )
V_64 -> V_243 [ V_243 ] . V_252 =
V_613 ;
else
V_64 -> V_243 [ V_243 ] . V_252 =
V_614 ;
}
V_117 += V_611 ;
V_243 ++ ;
V_612 = 0 ;
}
for ( V_173 = 0 ; V_173 < F_320 ( V_231 ) -> V_596 ; V_173 ++ ) {
V_595 = & F_320 ( V_231 ) -> V_597 [ V_173 ] ;
V_117 = ( char * ) F_321 ( F_322 ( V_595 ) ) +
V_595 -> V_598 ;
V_251 = V_595 -> V_599 ;
while ( V_251 > 0 ) {
V_611 = V_403 -
( ( unsigned long ) V_117 % V_403 ) ;
if ( V_251 < V_611 )
V_611 = V_251 ;
V_64 -> V_243 [ V_243 ] . V_248 = V_117 ;
V_64 -> V_243 [ V_243 ] . V_251 = V_611 ;
V_64 -> V_243 [ V_243 ] . V_252 =
V_614 ;
V_251 -= V_611 ;
V_117 += V_611 ;
V_243 ++ ;
}
}
if ( V_64 -> V_243 [ V_243 - 1 ] . V_252 )
V_64 -> V_243 [ V_243 - 1 ] . V_252 = V_615 ;
* V_253 = V_243 ;
}
static inline int F_329 ( struct V_92 * V_111 ,
struct V_96 * V_229 , struct V_230 * V_231 ,
struct V_604 * V_133 , int V_180 , int V_616 )
{
struct V_521 * V_64 ;
int V_554 = 0 , V_617 , V_618 = 0 ;
V_64 = V_229 -> V_64 ;
F_76 ( & V_231 -> V_240 ) ;
F_330 ( & V_229 -> V_232 , V_231 ) ;
if ( V_133 -> V_133 . V_619 . V_312 == V_620 ) {
int V_243 = V_229 -> V_253 ;
V_617 = sizeof( struct V_621 ) +
( (struct V_621 * ) V_133 ) -> V_497 . V_622 ;
V_64 -> V_243 [ V_243 ] . V_248 = V_231 -> V_117 ;
V_64 -> V_243 [ V_243 ] . V_251 = V_617 ;
V_64 -> V_243 [ V_243 ] . V_252 = V_613 ;
V_229 -> V_253 ++ ;
V_231 -> V_117 += V_617 ;
V_231 -> V_159 -= V_617 ;
V_618 = 1 ;
}
if ( V_180 >= 0 ) {
int V_243 = V_229 -> V_253 ;
V_64 -> V_243 [ V_243 ] . V_248 = V_133 ;
V_64 -> V_243 [ V_243 ] . V_251 = sizeof( struct V_604 ) +
V_616 ;
V_64 -> V_243 [ V_243 ] . V_252 = V_613 ;
V_229 -> V_249 [ V_243 ] = 1 ;
V_229 -> V_253 ++ ;
}
F_328 ( V_231 , V_64 , V_618 ,
( int * ) & V_229 -> V_253 , V_180 ) ;
if ( ! V_111 -> V_445 ) {
F_4 ( V_111 -> V_2 , 6 , L_254 ) ;
F_60 ( & V_229 -> V_3 , V_107 ) ;
V_554 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_255 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_438 . V_623 ++ ;
if ( V_229 -> V_253 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_229 -> V_3 , V_107 ) ;
V_554 = 1 ;
}
}
return V_554 ;
}
int F_331 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_230 * V_231 ,
struct V_604 * V_133 , int V_603 ,
int V_180 , int V_616 )
{
struct V_96 * V_64 ;
int V_165 ;
while ( F_59 ( & V_111 -> V_3 , V_447 ,
V_624 ) != V_447 ) ;
V_165 = V_111 -> V_444 ;
V_64 = V_111 -> V_63 [ V_111 -> V_444 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_247 )
goto V_73;
V_111 -> V_444 = ( V_111 -> V_444 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_447 ) ;
F_329 ( V_111 , V_64 , V_231 , V_133 , V_180 , V_616 ) ;
F_300 ( V_111 , V_165 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_447 ) ;
return - V_625 ;
}
int F_332 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_230 * V_231 , struct V_604 * V_133 ,
int V_603 )
{
struct V_96 * V_64 ;
int V_626 ;
int V_540 = 0 ;
int V_445 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_447 ,
V_624 ) != V_447 ) ;
V_626 = V_111 -> V_444 ;
V_64 = V_111 -> V_63 [ V_111 -> V_444 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_247 ) {
F_60 ( & V_111 -> V_3 , V_447 ) ;
return - V_625 ;
}
F_297 ( V_111 ) ;
if ( V_111 -> V_445 ) {
V_445 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_253 ) < V_603 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_540 ++ ;
V_111 -> V_444 =
( V_111 -> V_444 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_444 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_247 ) {
F_300 ( V_111 , V_626 ,
V_540 ) ;
F_60 ( & V_111 -> V_3 ,
V_447 ) ;
return - V_625 ;
}
}
}
V_41 = F_329 ( V_111 , V_64 , V_231 , V_133 , - 1 , 0 ) ;
V_111 -> V_444 = ( V_111 -> V_444 + V_41 ) %
V_62 ;
V_540 += V_41 ;
if ( V_540 )
F_300 ( V_111 , V_626 , V_540 ) ;
else if ( ! F_51 ( & V_111 -> V_246 ) )
F_234 ( & V_111 -> V_3 , V_556 ) ;
while ( F_333 ( & V_111 -> V_3 ) ) {
V_540 = 0 ;
V_626 = V_111 -> V_444 ;
V_540 += F_298 ( V_111 ) ;
if ( ! V_540 && ! F_51 ( & V_111 -> V_246 ) )
V_540 += F_299 ( V_111 ) ;
if ( V_540 )
F_300 ( V_111 , V_626 , V_540 ) ;
}
if ( V_111 -> V_2 -> V_66 . V_271 && V_445 )
V_111 -> V_2 -> V_438 . V_557 += V_540 ;
return V_37 ;
}
static int F_334 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_476 * V_627 ;
F_4 ( V_2 , 4 , L_256 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_627 = & ( V_130 -> V_117 . V_463 ) ;
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_257 , V_130 -> V_133 . V_139 ) ;
V_627 -> V_117 . V_628 = V_629 ;
}
V_2 -> V_12 . V_630 = V_627 -> V_117 . V_628 ;
return 0 ;
}
void F_335 ( struct V_1 * V_2 )
{
enum V_631 V_628 ;
struct V_632 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_258 ) ;
if ( ( ( V_9 -> V_32 & V_633 ) &&
( V_2 -> V_12 . V_630 == V_634 ) ) ||
( ! ( V_9 -> V_32 & V_633 ) &&
( V_2 -> V_12 . V_630 == V_629 ) ) )
return;
V_628 = V_629 ;
if ( V_9 -> V_32 & V_633 )
V_628 = V_634 ;
F_52 ( V_2 , 4 , L_259 , V_628 ) ;
V_113 = F_276 ( V_2 , V_635 ,
sizeof( struct V_476 ) ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_130 -> V_117 . V_463 . V_117 . V_628 = V_628 ;
F_272 ( V_2 , V_113 , F_334 , NULL ) ;
}
int F_336 ( struct V_632 * V_9 , int V_636 )
{
struct V_1 * V_2 ;
char V_432 [ 15 ] ;
V_2 = V_9 -> V_637 ;
F_4 ( V_2 , 4 , L_260 ) ;
sprintf ( V_432 , L_261 , V_636 ) ;
F_4 ( V_2 , 4 , V_432 ) ;
if ( V_636 < 64 )
return - V_401 ;
if ( V_636 > 65535 )
return - V_401 ;
if ( ( ! F_337 ( V_2 , V_638 ) ) &&
( ! F_207 ( V_2 , V_636 ) ) )
return - V_401 ;
V_9 -> V_399 = V_636 ;
return 0 ;
}
struct V_639 * F_338 ( struct V_632 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_637 ;
F_4 ( V_2 , 5 , L_262 ) ;
return & V_2 -> V_524 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_263 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_305 ||
! ( V_2 -> V_12 . V_640 & V_641 ) ) {
memcpy ( V_2 -> V_9 -> V_642 ,
& V_130 -> V_117 . V_463 . V_117 . V_643 . V_248 ,
V_644 ) ;
V_2 -> V_12 . V_640 |= V_641 ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int F_340 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_264 ) ;
V_113 = F_276 ( V_2 , V_645 ,
sizeof( struct V_476 ) ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_130 -> V_117 . V_463 . V_117 . V_643 . V_130 = V_646 ;
V_130 -> V_117 . V_463 . V_117 . V_643 . V_647 = V_644 ;
memcpy ( & V_130 -> V_117 . V_463 . V_117 . V_643 . V_248 ,
V_2 -> V_9 -> V_642 , V_644 ) ;
V_37 = F_272 ( V_2 , V_113 , F_339 ,
NULL ) ;
return V_37 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_648 * V_649 ;
int V_650 = * ( int * ) V_125 -> V_382 ;
F_4 ( V_2 , 4 , L_265 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_649 = & V_130 -> V_117 . V_463 . V_117 . V_651 ;
F_45 ( V_65 , 2 , L_265 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_652 . V_512 ) ;
F_45 ( V_65 , 2 , L_266 ,
V_130 -> V_117 . V_463 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_463 . V_133 . V_139 !=
V_653 )
F_68 ( 3 , L_267 ,
V_2 -> V_10 -> V_9 . V_652 . V_512 ,
V_649 -> V_654 ,
V_130 -> V_117 . V_463 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_463 . V_133 . V_139 ) {
case V_653 :
if ( V_2 -> V_66 . V_274 == V_275 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_268 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_269 ) ;
}
break;
case V_655 :
F_68 ( 2 , L_270
L_271 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_657 :
F_68 ( 2 , L_272
L_273 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_658 :
F_47 ( & V_2 -> V_10 -> V_9 , L_274
L_275 ) ;
break;
case V_659 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_276
L_277 ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_660 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_278 ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_661 :
F_47 ( & V_2 -> V_10 -> V_9 , L_279
L_280 ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_662 :
F_47 ( & V_2 -> V_10 -> V_9 , L_281
L_282 ) ;
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
case V_663 :
F_67 ( & V_2 -> V_10 -> V_9 , L_283
L_284 ) ;
break;
default:
if ( V_650 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_656 ;
break;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_342 ( struct V_1 * V_2 ,
enum V_664 V_274 , int V_650 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_648 * V_649 ;
F_4 ( V_2 , 4 , L_285 ) ;
F_45 ( V_65 , 2 , L_285 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_652 . V_512 ) ;
V_113 = F_276 ( V_2 , V_665 ,
sizeof( struct V_494 ) +
sizeof( struct V_648 ) ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_649 = & V_130 -> V_117 . V_463 . V_117 . V_651 ;
V_649 -> V_654 = V_274 ;
V_37 = F_272 ( V_2 , V_113 , F_341 ,
& V_650 ) ;
F_45 ( V_65 , 2 , L_266 , V_37 ) ;
return V_37 ;
}
int F_343 ( struct V_1 * V_2 , int V_650 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_286 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_281 ( V_2 , V_665 ) ) {
V_37 = F_342 ( V_2 ,
V_2 -> V_66 . V_274 , V_650 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_287 ,
V_2 -> V_10 -> V_9 . V_652 . V_512 ,
V_37 ) ;
V_37 = - V_338 ;
}
} else if ( V_2 -> V_66 . V_274 != V_275 ) {
V_2 -> V_66 . V_274 = V_275 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_274
L_275 ) ;
V_37 = - V_338 ;
}
return V_37 ;
}
void F_344 ( struct V_632 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_637 ;
F_4 ( V_2 , 4 , L_288 ) ;
V_2 -> V_524 . V_551 ++ ;
F_72 ( V_2 ) ;
}
int F_345 ( struct V_632 * V_9 , int V_666 , int V_667 )
{
struct V_1 * V_2 = V_9 -> V_637 ;
int V_37 = 0 ;
switch ( V_667 ) {
case V_668 :
V_37 = V_669 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_670 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_671 ;
break;
case V_672 :
V_37 = V_673 | V_674 | V_675 |
V_676 | V_677 | V_678 | V_679 |
V_680 ;
break;
case V_681 :
V_37 = ( V_9 -> V_642 [ 0 ] << 16 ) | ( V_9 -> V_642 [ 1 ] << 8 ) |
V_9 -> V_642 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_682 :
V_37 = ( V_9 -> V_642 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_683 :
V_37 = V_684 ;
break;
case V_685 :
V_37 = V_686 | V_687 | V_688 | V_689 |
V_690 | V_691 ;
break;
case V_692 :
break;
case V_693 :
break;
case V_694 :
break;
case V_695 :
break;
case V_696 :
V_37 = V_2 -> V_524 . V_697 ;
break;
case V_698 :
break;
case V_699 :
break;
case V_700 :
break;
case V_701 :
break;
case V_702 :
break;
case V_703 :
break;
case V_704 :
break;
default:
break;
}
return V_37 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_159 ,
int (* F_190)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_379 )
{
V_182 V_705 , V_706 ;
F_4 ( V_2 , 4 , L_289 ) ;
memcpy ( V_113 -> V_117 , V_461 , V_386 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
V_705 = ( V_707 ) V_386 + V_159 ;
V_706 = ( V_707 ) V_159 ;
memcpy ( F_347 ( V_113 -> V_117 ) , & V_705 , 2 ) ;
memcpy ( F_348 ( V_113 -> V_117 ) , & V_706 , 2 ) ;
memcpy ( F_349 ( V_113 -> V_117 ) , & V_706 , 2 ) ;
memcpy ( F_350 ( V_113 -> V_117 ) , & V_706 , 2 ) ;
return F_189 ( V_2 , V_386 + V_159 , V_113 ,
F_190 , V_379 ) ;
}
static int F_351 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_708 )
{
struct V_129 * V_130 ;
struct V_709 * V_710 ;
struct V_711 * V_712 ;
unsigned char * V_117 ;
V_181 V_602 ;
F_4 ( V_2 , 3 , L_290 ) ;
V_130 = (struct V_129 * ) V_708 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_180 ) ;
V_710 = (struct V_709 * ) V_125 -> V_382 ;
V_712 = & V_130 -> V_117 . V_463 . V_117 . V_712 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_291 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_463 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_463 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_292 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_602 = * ( ( V_181 * ) F_348 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_463 . V_133 . V_474 == 1 )
V_602 -= ( V_181 ) ( ( char * ) & V_712 -> V_117 - ( char * ) V_130 ) ;
else
V_602 -= ( V_181 ) ( ( char * ) & V_712 -> V_713 - ( char * ) V_130 ) ;
if ( ( V_710 -> V_714 - V_710 -> V_715 ) < V_602 ) {
F_52 ( V_2 , 4 , L_293 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_716 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_294 ,
V_130 -> V_117 . V_463 . V_133 . V_473 ) ;
F_52 ( V_2 , 4 , L_295 ,
V_130 -> V_117 . V_463 . V_133 . V_474 ) ;
if ( V_130 -> V_117 . V_463 . V_133 . V_474 == 1 ) {
memcpy ( V_710 -> V_717 + V_710 -> V_715 ,
( char * ) V_712 ,
V_602 + F_352 ( struct V_711 , V_117 ) ) ;
V_710 -> V_715 += F_352 ( struct V_711 , V_117 ) ;
} else {
memcpy ( V_710 -> V_717 + V_710 -> V_715 ,
( char * ) & V_712 -> V_713 , V_602 ) ;
}
V_710 -> V_715 += V_602 ;
F_52 ( V_2 , 4 , L_296 ,
V_130 -> V_117 . V_463 . V_133 . V_473 ) ;
F_52 ( V_2 , 4 , L_297 ,
V_130 -> V_117 . V_463 . V_133 . V_474 ) ;
if ( V_130 -> V_117 . V_463 . V_133 . V_474 <
V_130 -> V_117 . V_463 . V_133 . V_473 )
return 1 ;
return 0 ;
}
int F_353 ( struct V_1 * V_2 , char T_4 * V_717 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_718 * V_719 ;
unsigned int V_720 ;
struct V_709 V_710 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_298 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_338 ;
if ( ( ! F_281 ( V_2 , V_721 ) ) &&
( ! V_2 -> V_66 . V_305 ) ) {
return - V_338 ;
}
if ( F_354 ( & V_720 , V_717 + sizeof( int ) , sizeof( int ) ) )
return - V_722 ;
if ( V_720 > ( V_118 - V_386 -
sizeof( struct V_723 ) -
sizeof( struct V_494 ) ) )
return - V_401 ;
V_719 = F_355 ( V_717 , V_720 + sizeof( struct V_724 ) ) ;
if ( F_115 ( V_719 ) ) {
F_4 ( V_2 , 2 , L_299 ) ;
return F_116 ( V_719 ) ;
}
V_710 . V_714 = V_719 -> V_133 . V_602 ;
V_710 . V_717 = F_27 ( V_710 . V_714 , V_49 ) ;
if ( ! V_710 . V_717 ) {
F_32 ( V_719 ) ;
return - V_50 ;
}
V_710 . V_715 = sizeof( struct V_724 ) ;
V_113 = F_276 ( V_2 , V_721 ,
V_725 + V_720 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
memcpy ( & V_130 -> V_117 . V_463 . V_117 . V_712 , & V_719 -> V_130 , V_720 ) ;
V_37 = F_346 ( V_2 , V_113 , V_726 + V_720 ,
F_351 , ( void * ) & V_710 ) ;
if ( V_37 )
F_68 ( 2 , L_300 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_356 ( V_717 , V_710 . V_717 , V_710 . V_714 ) )
V_37 = - V_722 ;
}
F_32 ( V_719 ) ;
F_32 ( V_710 . V_717 ) ;
return V_37 ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_727 * V_728 ;
char * V_729 ;
int V_730 ;
F_4 ( V_2 , 3 , L_301 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_728 = (struct V_727 * ) V_125 -> V_382 ;
V_730 = V_130 -> V_117 . V_463 . V_133 . V_471 ;
V_729 = ( char * ) V_117 + 28 ;
if ( V_730 > ( V_728 -> V_731 - V_728 -> V_732 ) ) {
V_130 -> V_133 . V_139 = V_733 ;
return 0 ;
}
memcpy ( ( V_728 -> V_64 + V_728 -> V_732 ) , V_729 ,
V_730 ) ;
V_728 -> V_732 += V_730 ;
if ( V_130 -> V_117 . V_463 . V_133 . V_474 <
V_130 -> V_117 . V_463 . V_133 . V_473 )
return 1 ;
return 0 ;
}
int F_358 ( struct V_1 * V_2 , char T_4 * V_717 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_734 * V_735 ;
struct V_736 V_737 ;
struct V_727 V_728 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_302 ) ;
if ( ! F_281 ( V_2 , V_738 ) ) {
V_37 = - V_338 ;
goto V_73;
}
if ( F_354 ( & V_737 , V_717 ,
sizeof( struct V_736 ) ) ) {
V_37 = - V_722 ;
goto V_73;
}
V_728 . V_731 = V_737 . V_731 ;
V_728 . V_732 = 0 ;
V_728 . V_64 = F_27 ( V_737 . V_731 , V_49 ) ;
if ( ! V_728 . V_64 ) {
V_37 = - V_50 ;
goto V_73;
}
V_113 = F_276 ( V_2 , V_738 ,
sizeof( struct V_494 ) +
sizeof( struct V_734 ) ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_386 ) ;
V_735 = & V_130 -> V_117 . V_463 . V_117 . V_739 ;
V_735 -> V_654 = V_737 . V_134 ;
V_37 = F_272 ( V_2 , V_113 , F_357 ,
& V_728 ) ;
if ( ! V_37 ) {
if ( F_359 () )
V_41 = F_360 ( V_737 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_737 . V_43 ;
if ( F_356 ( V_41 , V_728 . V_64 ,
V_728 . V_732 ) ) {
V_37 = - V_722 ;
goto V_740;
}
V_737 . V_732 = V_728 . V_732 ;
if ( F_356 ( V_717 , & V_737 ,
sizeof( struct V_736 ) ) )
V_37 = - V_722 ;
} else
if ( V_37 == V_733 )
V_37 = - V_722 ;
V_740:
F_32 ( V_728 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_741 * V_742 ;
struct V_743 * V_743 ;
F_4 ( V_2 , 2 , L_303 ) ;
V_743 = (struct V_743 * ) V_125 -> V_382 ;
V_130 = (struct V_129 * ) V_117 ;
V_742 = & V_130 -> V_117 . V_463 . V_117 . V_742 ;
if ( V_130 -> V_117 . V_463 . V_133 . V_139 == 0 ) {
V_743 -> V_744 = V_742 -> V_744 ;
V_743 -> V_745 = V_742 -> V_745 ;
V_743 -> V_746 = V_742 -> V_746 ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_741 ( struct V_1 * V_2 ,
struct V_743 * V_743 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_304 ) ;
if ( ! F_281 ( V_2 , V_747 ) )
return - V_338 ;
V_113 = F_276 ( V_2 , V_747 ,
sizeof( struct V_494 ) ) ;
return F_272 ( V_2 , V_113 , F_361 ,
( void * ) V_743 ) ;
}
static inline int F_362 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
return 2 ;
default:
return 0 ;
}
}
static void F_363 ( struct V_1 * V_2 )
{
int V_37 ;
int V_251 ;
char * V_344 ;
struct V_190 * V_748 ;
int V_749 = 0 ;
F_41 ( V_65 , 2 , L_305 ) ;
V_748 = F_44 ( V_2 ) ;
if ( ! V_748 -> V_750 ) {
V_749 = 1 ;
V_37 = F_364 ( V_748 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_73;
}
}
V_37 = F_163 ( V_2 , ( void * * ) & V_344 , & V_251 ) ;
if ( V_37 ) {
F_68 ( 2 , L_306 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_751;
}
F_166 ( V_2 , V_344 ) ;
if ( V_749 )
F_167 ( V_2 , V_344 ) ;
F_32 ( V_344 ) ;
V_37 = F_365 ( V_748 , & V_2 -> V_752 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_45 ( V_65 , 2 , L_307 , V_2 -> V_752 . V_753 ) ;
F_45 ( V_65 , 2 , L_308 , V_2 -> V_752 . V_754 ) ;
F_45 ( V_65 , 2 , L_308 , V_2 -> V_752 . V_755 ) ;
F_45 ( V_65 , 2 , L_309 , V_2 -> V_752 . V_756 ) ;
if ( ! ( ( V_2 -> V_752 . V_753 != V_757 ) ||
( ( V_2 -> V_752 . V_754 & V_758 ) == 0 ) ||
( ( V_2 -> V_752 . V_755 & V_759 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_310 ) ;
} else {
V_2 -> V_66 . V_67 = V_562 ;
}
V_751:
if ( V_749 == 1 )
F_366 ( V_748 ) ;
V_73:
return;
}
static inline void F_367 ( struct V_1 * V_2 ,
struct V_521 * * V_760 ,
void (* * F_368) ( struct V_190 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_180 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_760 [ V_180 + V_44 ] = (struct V_521 * )
F_312 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_368 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_761 V_762 ;
char * V_763 ;
struct V_521 * * V_760 ;
void (* * F_368) ( struct V_190 * , int , unsigned long );
struct V_521 * * V_764 ;
int V_44 , V_45 , V_765 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_311 ) ;
V_763 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_763 ) {
V_37 = - V_50 ;
goto V_766;
}
F_236 ( V_2 , V_763 ) ;
F_240 ( V_2 , V_763 ) ;
V_760 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_760 ) {
V_37 = - V_50 ;
goto V_767;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_760 [ V_44 ] = (struct V_521 * )
F_312 ( V_2 -> V_46 . V_420 -> V_63 [ V_44 ] . V_64 ) ;
}
F_368 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_368 ) {
V_37 = - V_50 ;
goto V_768;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_368 [ V_44 ] = V_2 -> V_148 -> V_769 ;
F_367 ( V_2 , V_760 , F_368 ) ;
V_764 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_764 ) {
V_37 = - V_50 ;
goto V_770;
}
for ( V_44 = 0 , V_765 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_765 ) {
V_764 [ V_765 ] = (struct V_521 * ) F_312 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_762 , 0 , sizeof( struct V_761 ) ) ;
V_762 . V_191 = F_44 ( V_2 ) ;
V_762 . V_771 = F_362 ( V_2 ) ;
V_762 . V_772 = 0 ;
V_762 . V_763 = V_763 ;
V_762 . V_773 = V_2 -> V_46 . V_72 ;
V_762 . V_774 = V_2 -> V_46 . V_78 ;
V_762 . V_775 = V_2 -> V_148 -> V_775 ;
V_762 . V_776 = V_2 -> V_148 -> V_776 ;
V_762 . V_777 = F_368 ;
V_762 . V_778 = ( unsigned long ) V_2 ;
V_762 . V_779 = ( void * * ) V_760 ;
V_762 . V_780 = ( void * * ) V_764 ;
V_762 . V_781 = V_2 -> V_46 . V_77 ;
V_762 . V_782 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_333 ,
V_329 ) == V_333 ) {
V_37 = F_369 ( & V_762 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_333 ) ;
goto V_73;
}
V_37 = F_370 ( & V_762 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_333 ) ;
F_248 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_312 ) ;
break;
case V_276 :
F_89 ( & V_2 -> V_10 -> V_9 , L_313 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_764 ) ;
V_770:
F_32 ( F_368 ) ;
V_768:
F_32 ( V_760 ) ;
V_767:
F_32 ( V_763 ) ;
V_766:
return V_37 ;
}
static void F_371 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_314 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_129 ( & V_2 -> V_114 ) ;
F_129 ( & V_2 -> V_154 ) ;
if ( V_2 -> V_9 )
F_372 ( V_2 -> V_9 ) ;
F_32 ( V_2 -> V_287 ) ;
F_131 ( V_2 ) ;
F_373 ( & V_2 -> V_299 ) ;
F_32 ( V_2 ) ;
}
void F_374 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_315 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_479 . V_467 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_479 . V_482 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_481 . V_467 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_481 . V_482 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_466 . V_467 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_66 . V_466 . V_482 ) ;
F_52 ( V_2 , 2 , L_316 , V_2 -> V_12 . V_495 ) ;
}
int F_375 ( struct V_1 * V_2 )
{
int V_783 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_317 ) ;
F_60 ( & V_2 -> V_529 , 0 ) ;
F_133 ( V_2 ) ;
V_784:
if ( V_783 < 3 )
F_68 ( 2 , L_318 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_161 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_366 ( F_44 ( V_2 ) ) ;
F_366 ( F_376 ( V_2 ) ) ;
F_366 ( F_151 ( V_2 ) ) ;
F_248 ( F_44 ( V_2 ) ) ;
V_37 = F_364 ( F_151 ( V_2 ) ) ;
if ( V_37 )
goto V_785;
V_37 = F_364 ( F_376 ( V_2 ) ) ;
if ( V_37 )
goto V_785;
V_37 = F_364 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_785;
V_785:
if ( V_37 == - V_322 ) {
F_41 ( V_65 , 2 , L_319 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_783 < 0 )
goto V_73;
else
goto V_784;
}
F_363 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
V_37 = F_172 ( & V_2 -> V_114 , F_184 ) ;
if ( V_37 == - V_322 ) {
F_41 ( V_65 , 2 , L_320 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
if ( -- V_783 < 0 )
goto V_73;
else
goto V_784;
}
V_37 = F_172 ( & V_2 -> V_154 , F_181 ) ;
if ( V_37 == - V_322 ) {
F_41 ( V_65 , 2 , L_321 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
if ( -- V_783 < 0 )
goto V_73;
else
goto V_784;
}
V_2 -> V_123 = 0 ;
V_37 = F_246 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_73;
}
V_2 -> V_66 . V_479 . V_467 = 0 ;
V_2 -> V_66 . V_466 . V_467 = 0 ;
V_2 -> V_66 . V_786 . V_467 = 0 ;
V_2 -> V_12 . V_495 = 0 ;
F_279 ( V_2 , V_389 ) ;
if ( F_337 ( V_2 , V_480 ) )
F_277 ( V_2 ) ;
if ( F_281 ( V_2 , V_787 ) )
F_283 ( V_2 ) ;
return 0 ;
V_73:
F_67 ( & V_2 -> V_10 -> V_9 , L_106
L_107 ) ;
F_68 ( 2 , L_322 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
return V_37 ;
}
static inline int F_377 ( struct V_440 * V_788 ,
struct V_789 * V_243 ,
struct V_230 * * V_790 , int V_180 , int * V_791 , int V_602 )
{
struct V_436 * V_436 = F_260 ( V_243 -> V_248 ) ;
if ( * V_790 == NULL ) {
if ( V_788 -> V_427 ) {
* V_790 = V_788 -> V_427 ;
V_788 -> V_427 = NULL ;
} else {
* V_790 = F_264 ( V_441 + V_442 ) ;
if ( ! ( * V_790 ) )
return - V_50 ;
}
F_378 ( * V_790 , V_442 ) ;
if ( V_602 <= V_441 ) {
memcpy ( F_379 ( * V_790 , V_602 ) , V_243 -> V_248 + V_180 ,
V_602 ) ;
} else {
F_380 ( V_436 ) ;
memcpy ( F_379 ( * V_790 , V_441 ) ,
V_243 -> V_248 + V_180 , V_441 ) ;
F_381 ( * V_790 , * V_791 , V_436 ,
V_180 + V_441 ,
V_602 - V_441 ) ;
( * V_790 ) -> V_602 += V_602 - V_441 ;
( * V_790 ) -> V_159 += V_602 - V_441 ;
( * V_790 ) -> V_792 += V_602 - V_441 ;
( * V_791 ) ++ ;
}
} else {
F_380 ( V_436 ) ;
F_381 ( * V_790 , * V_791 , V_436 , V_180 , V_602 ) ;
( * V_790 ) -> V_602 += V_602 ;
( * V_790 ) -> V_159 += V_602 ;
( * V_790 ) -> V_792 += V_602 ;
( * V_791 ) ++ ;
}
return 0 ;
}
struct V_230 * F_382 ( struct V_1 * V_2 ,
struct V_440 * V_788 ,
struct V_789 * * V_793 , int * V_794 ,
struct V_604 * * V_133 )
{
struct V_789 * V_243 = * V_793 ;
struct V_521 * V_64 = V_788 -> V_64 ;
int V_180 = * V_794 ;
struct V_230 * V_231 = NULL ;
int V_795 = 0 ;
void * V_796 ;
int V_602 ;
int V_797 = 0 ;
int V_798 = 0 ;
int V_595 = 0 ;
if ( V_243 -> V_251 < V_180 + sizeof( struct V_604 ) ) {
if ( F_383 ( V_243 ) )
return NULL ;
V_243 ++ ;
V_180 = 0 ;
if ( V_243 -> V_251 < sizeof( struct V_604 ) )
return NULL ;
}
* V_133 = V_243 -> V_248 + V_180 ;
V_180 += sizeof( struct V_604 ) ;
switch ( ( * V_133 ) -> V_133 . V_799 . V_312 ) {
case V_800 :
V_795 = ( * V_133 ) -> V_133 . V_799 . V_801 ;
break;
case V_802 :
V_795 = ( * V_133 ) -> V_133 . V_619 . V_251 ;
V_797 = V_442 ;
break;
case V_803 :
V_795 = ( * V_133 ) -> V_133 . V_804 . V_805 ;
V_797 = sizeof( struct V_604 ) ;
break;
default:
break;
}
if ( ! V_795 )
return NULL ;
if ( ( ( V_795 >= V_2 -> V_66 . V_272 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_529 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_798 = 1 ;
} else {
V_231 = F_264 ( V_795 + V_797 ) ;
if ( ! V_231 )
goto V_806;
if ( V_797 )
F_378 ( V_231 , V_797 ) ;
}
V_796 = V_243 -> V_248 + V_180 ;
while ( V_795 ) {
V_602 = F_211 ( V_795 , ( int ) ( V_243 -> V_251 - V_180 ) ) ;
if ( V_602 ) {
if ( V_798 ) {
if ( F_377 ( V_788 , V_243 ,
& V_231 , V_180 , & V_595 , V_602 ) )
goto V_806;
} else {
memcpy ( F_379 ( V_231 , V_602 ) , V_796 ,
V_602 ) ;
}
}
V_795 -= V_602 ;
if ( V_795 ) {
if ( F_383 ( V_243 ) ) {
F_4 ( V_2 , 4 , L_323 ) ;
F_384 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_126 ( V_231 ) ;
V_2 -> V_524 . V_697 ++ ;
return NULL ;
}
V_243 ++ ;
V_180 = 0 ;
V_796 = V_243 -> V_248 ;
} else {
V_180 += V_602 ;
}
}
* V_793 = V_243 ;
* V_794 = V_180 ;
if ( V_798 && V_2 -> V_66 . V_271 ) {
V_2 -> V_438 . V_807 ++ ;
V_2 -> V_438 . V_808 += F_320 ( V_231 ) -> V_596 ;
}
return V_231 ;
V_806:
if ( F_385 () ) {
F_4 ( V_2 , 2 , L_324 ) ;
}
V_2 -> V_524 . V_525 ++ ;
return NULL ;
}
static void F_386 ( void )
{
int V_809 ;
for ( V_809 = 0 ; V_809 < V_810 ; V_809 ++ ) {
F_387 ( V_811 [ V_809 ] . V_312 ) ;
V_811 [ V_809 ] . V_312 = NULL ;
}
}
void F_388 ( T_5 * V_312 , int V_371 , char * V_812 , ... )
{
char V_813 [ 32 ] ;
T_6 args ;
if ( ! F_389 ( V_312 , V_371 ) )
return;
va_start ( args , V_812 ) ;
vsnprintf ( V_813 , sizeof( V_813 ) , V_812 , args ) ;
va_end ( args ) ;
F_390 ( V_312 , V_371 , V_813 ) ;
}
static int F_391 ( void )
{
int V_336 ;
int V_809 ;
for ( V_809 = 0 ; V_809 < V_810 ; V_809 ++ ) {
V_811 [ V_809 ] . V_312 = F_392 ( V_811 [ V_809 ] . V_512 ,
V_811 [ V_809 ] . V_814 ,
V_811 [ V_809 ] . V_815 ,
V_811 [ V_809 ] . V_159 ) ;
if ( V_811 [ V_809 ] . V_312 == NULL ) {
F_386 () ;
return - V_50 ;
}
V_336 = F_393 ( V_811 [ V_809 ] . V_312 , V_811 [ V_809 ] . V_816 ) ;
if ( V_336 ) {
F_386 () ;
return V_336 ;
}
F_394 ( V_811 [ V_809 ] . V_312 , V_811 [ V_809 ] . V_371 ) ;
}
return 0 ;
}
int F_395 ( struct V_1 * V_2 ,
enum V_817 V_148 )
{
int V_37 = 0 ;
F_396 ( & V_818 ) ;
switch ( V_148 ) {
case V_819 :
V_2 -> V_148 = F_397 (
F_398 ( V_820 ) , L_325 ) ;
break;
case V_821 :
V_2 -> V_148 = F_397 (
F_398 ( V_822 ) , L_326 ) ;
break;
}
if ( ! V_2 -> V_148 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_327
L_328 , V_148 ) ;
V_37 = - V_401 ;
}
F_399 ( & V_818 ) ;
return V_37 ;
}
void F_400 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_305 )
F_401 ( V_822 ) ;
else
F_401 ( V_820 ) ;
V_2 -> V_148 = NULL ;
}
static T_5 * F_402 ( char * V_512 )
{
struct V_823 * V_434 ;
T_5 * V_37 = NULL ;
F_396 ( & V_824 ) ;
F_253 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_434 -> V_825 , V_512 ) == 0 ) {
V_37 = V_434 -> V_826 ;
break;
}
}
F_399 ( & V_824 ) ;
return V_37 ;
}
static int F_403 ( struct V_1 * V_2 , char * V_512 )
{
struct V_823 * V_827 ;
V_2 -> V_828 = F_392 ( V_512 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_828 ) {
F_45 ( V_65 , 2 , L_191 , L_329 ) ;
goto V_829;
}
if ( F_393 ( V_2 -> V_828 , & V_830 ) )
goto V_831;
V_827 = F_27 ( sizeof( struct V_823 ) , V_49 ) ;
if ( ! V_827 )
goto V_831;
strncpy ( V_827 -> V_825 , V_512 , V_832 ) ;
V_827 -> V_826 = V_2 -> V_828 ;
F_396 ( & V_824 ) ;
F_33 ( & V_827 -> V_833 , & V_834 ) ;
F_399 ( & V_824 ) ;
return 0 ;
V_831:
F_387 ( V_2 -> V_828 ) ;
V_829:
return - V_50 ;
}
static void F_404 ( void )
{
struct V_823 * V_434 , * V_41 ;
F_396 ( & V_824 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_434 -> V_833 ) ;
F_387 ( V_434 -> V_826 ) ;
F_32 ( V_434 ) ;
}
F_399 ( & V_824 ) ;
}
static int F_405 ( struct V_835 * V_10 )
{
struct V_1 * V_2 ;
struct V_836 * V_9 ;
int V_37 ;
unsigned long V_32 ;
char V_825 [ V_832 ] ;
F_41 ( V_65 , 2 , L_330 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_406 ( V_9 ) )
return - V_837 ;
F_45 ( V_65 , 2 , L_191 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_148 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_838;
}
snprintf ( V_825 , sizeof( V_825 ) , L_331 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_828 = F_402 ( V_825 ) ;
if ( ! V_2 -> V_828 ) {
V_37 = F_403 ( V_2 , V_825 ) ;
if ( V_37 )
goto V_839;
}
V_2 -> V_114 . V_119 = V_10 -> V_191 [ 0 ] ;
V_2 -> V_154 . V_119 = V_10 -> V_191 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_191 [ 2 ] ;
F_407 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_191 [ 0 ] -> V_840 = F_117 ;
V_10 -> V_191 [ 1 ] -> V_840 = F_117 ;
V_10 -> V_191 [ 2 ] -> V_840 = F_117 ;
V_37 = F_150 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_839;
}
V_37 = F_141 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_839;
}
if ( V_2 -> V_12 . type == V_18 )
V_10 -> V_9 . type = & V_841 ;
else
V_10 -> V_9 . type = & V_842 ;
switch ( V_2 -> V_12 . type ) {
case V_18 :
case V_16 :
V_37 = F_395 ( V_2 , V_821 ) ;
if ( V_37 )
goto V_839;
V_37 = V_2 -> V_148 -> V_843 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_844;
case V_14 :
case V_17 :
default:
break;
}
F_408 ( & V_845 . V_846 , V_32 ) ;
F_101 ( & V_2 -> V_42 , & V_845 . V_42 ) ;
F_409 ( & V_845 . V_846 , V_32 ) ;
F_363 ( V_2 ) ;
return 0 ;
V_844:
F_400 ( V_2 ) ;
V_839:
F_371 ( V_2 ) ;
V_838:
F_410 ( V_9 ) ;
return V_37 ;
}
static void F_411 ( struct V_835 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_332 ) ;
if ( V_2 -> V_148 ) {
V_2 -> V_148 -> remove ( V_10 ) ;
F_400 ( V_2 ) ;
}
F_408 ( & V_845 . V_846 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_409 ( & V_845 . V_846 , V_32 ) ;
F_371 ( V_2 ) ;
F_407 ( & V_10 -> V_9 , NULL ) ;
F_410 ( & V_10 -> V_9 ) ;
return;
}
static int F_413 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
int V_847 ;
if ( ! V_2 -> V_148 ) {
if ( V_2 -> V_12 . type == V_15 )
V_847 = V_819 ;
else
V_847 = V_821 ;
V_37 = F_395 ( V_2 , V_847 ) ;
if ( V_37 )
goto V_829;
V_37 = V_2 -> V_148 -> V_843 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_829;
}
V_37 = V_2 -> V_148 -> V_848 ( V_10 ) ;
V_829:
return V_37 ;
}
static int F_414 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
return V_2 -> V_148 -> V_849 ( V_10 ) ;
}
static void F_415 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_850 )
V_2 -> V_148 -> V_850 ( V_10 ) ;
}
static int F_416 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_851 )
return V_2 -> V_148 -> V_851 ( V_10 ) ;
return 0 ;
}
static void F_417 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_852 )
V_2 -> V_148 -> V_852 ( V_10 ) ;
}
static int F_418 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_853 )
return V_2 -> V_148 -> V_853 ( V_10 ) ;
return 0 ;
}
static int F_419 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_854 )
return V_2 -> V_148 -> V_854 ( V_10 ) ;
return 0 ;
}
static int F_420 ( struct V_835 * V_10 )
{
struct V_1 * V_2 = F_412 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_855 )
return V_2 -> V_148 -> V_855 ( V_10 ) ;
return 0 ;
}
static T_7 F_421 ( struct V_856 * V_857 ,
const char * V_229 , T_8 V_163 )
{
int V_829 ;
V_829 = F_422 ( V_858 ,
& V_859 , 3 , V_229 ) ;
return V_829 ? V_829 : V_163 ;
}
int F_423 ( struct V_632 * V_9 , int V_860 )
{
switch ( V_860 ) {
case V_861 :
return ( sizeof( V_862 ) / V_863 ) ;
default:
return - V_401 ;
}
}
void F_424 ( struct V_632 * V_9 ,
struct V_864 * V_524 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_637 ;
V_117 [ 0 ] = V_2 -> V_524 . V_865 -
V_2 -> V_438 . V_866 ;
V_117 [ 1 ] = V_2 -> V_438 . V_867 ;
V_117 [ 2 ] = V_2 -> V_524 . V_868 -
V_2 -> V_438 . V_869 ;
V_117 [ 3 ] = V_2 -> V_438 . V_553 ;
V_117 [ 4 ] = V_2 -> V_524 . V_868 - V_2 -> V_438 . V_869
- V_2 -> V_438 . V_623 ;
V_117 [ 5 ] = V_2 -> V_438 . V_553 - V_2 -> V_438 . V_557 ;
V_117 [ 6 ] = V_2 -> V_438 . V_623 ;
V_117 [ 7 ] = V_2 -> V_438 . V_557 ;
V_117 [ 8 ] = V_2 -> V_438 . V_870 ;
V_117 [ 9 ] = V_2 -> V_438 . V_871 ;
V_117 [ 10 ] = V_2 -> V_438 . V_807 ;
V_117 [ 11 ] = V_2 -> V_438 . V_808 ;
V_117 [ 12 ] = V_2 -> V_438 . V_439 ;
V_117 [ 13 ] = ( V_2 -> V_438 . V_872 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_438 . V_873 ;
V_117 [ 15 ] = V_2 -> V_438 . V_539 ;
V_117 [ 16 ] = V_2 -> V_438 . V_542 ;
V_117 [ 17 ] = V_541 ;
V_117 [ 18 ] = V_538 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_446 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_446 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_446 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_446 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_438 . V_874 ;
V_117 [ 24 ] = V_2 -> V_438 . V_875 ;
V_117 [ 25 ] = V_2 -> V_438 . V_533 ;
V_117 [ 26 ] = V_2 -> V_438 . V_531 ;
V_117 [ 27 ] = V_2 -> V_438 . V_576 ;
V_117 [ 28 ] = V_2 -> V_438 . V_572 ;
V_117 [ 29 ] = V_2 -> V_438 . V_876 ;
V_117 [ 30 ] = V_2 -> V_438 . V_877 ;
V_117 [ 31 ] = V_2 -> V_438 . V_550 ;
V_117 [ 32 ] = V_2 -> V_438 . V_546 ;
V_117 [ 33 ] = V_2 -> V_438 . V_878 ;
V_117 [ 34 ] = V_2 -> V_438 . V_879 ;
V_117 [ 35 ] = V_2 -> V_438 . V_564 ;
V_117 [ 36 ] = V_2 -> V_438 . V_568 ;
}
void F_425 ( struct V_632 * V_9 , V_707 V_860 , V_277 * V_117 )
{
switch ( V_860 ) {
case V_861 :
memcpy ( V_117 , & V_862 ,
sizeof( V_862 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_426 ( struct V_632 * V_9 ,
struct V_880 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_637 ;
F_427 ( V_12 -> V_881 , V_2 -> V_66 . V_305 ? L_326 : L_325 ,
sizeof( V_12 -> V_881 ) ) ;
F_427 ( V_12 -> V_882 , L_333 , sizeof( V_12 -> V_882 ) ) ;
F_427 ( V_12 -> V_883 , V_2 -> V_12 . V_300 ,
sizeof( V_12 -> V_883 ) ) ;
snprintf ( V_12 -> V_884 , sizeof( V_12 -> V_884 ) , L_334 ,
F_428 ( V_2 ) , F_429 ( V_2 ) , F_430 ( V_2 ) ) ;
}
static void F_431 ( struct V_885 * V_886 ,
int V_887 , int V_888 )
{
int V_889 , V_890 , V_891 , V_892 ;
switch ( V_888 ) {
case V_893 :
V_889 = V_894 ;
V_890 = V_895 ;
break;
case V_896 :
V_889 = V_897 ;
V_890 = V_898 ;
break;
default:
V_889 = V_894 ;
V_890 = V_895 ;
F_54 ( 1 ) ;
}
V_891 = 0 ;
V_892 = 0 ;
switch ( V_887 ) {
case V_899 :
V_891 |= V_900 ;
V_892 |= V_901 ;
case V_902 :
V_891 |= V_903 | V_904 ;
V_892 |= V_905 |
V_906 ;
case V_907 :
V_891 |= V_908 | V_909 ;
V_892 |= V_910 | V_911 ;
case V_912 :
V_891 |= V_913 | V_914 ;
V_892 |= V_915 | V_916 ;
break;
default:
V_891 = V_913 | V_914 ;
V_892 = V_915 | V_916 ;
F_54 ( 1 ) ;
}
V_886 -> V_917 = V_918 | V_890 | V_892 ;
V_886 -> V_919 = V_920 | V_889 | V_891 ;
}
int F_432 ( struct V_632 * V_921 ,
struct V_885 * V_886 )
{
struct V_1 * V_2 = V_921 -> V_637 ;
enum V_448 V_19 ;
struct V_743 V_743 ;
int V_37 ;
V_707 V_922 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_886 -> V_923 = V_924 ;
V_886 -> V_925 = V_926 ;
V_886 -> V_927 = V_928 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
F_431 ( V_886 , V_907 , V_893 ) ;
V_922 = V_907 ;
V_886 -> V_929 = V_893 ;
break;
case V_22 :
case V_26 :
F_431 ( V_886 , V_902 , V_896 ) ;
V_922 = V_902 ;
V_886 -> V_929 = V_896 ;
break;
case V_23 :
F_431 ( V_886 , V_899 , V_896 ) ;
V_922 = V_899 ;
V_886 -> V_929 = V_896 ;
break;
default:
F_431 ( V_886 , V_912 , V_893 ) ;
V_922 = V_912 ;
V_886 -> V_929 = V_893 ;
}
F_433 ( V_886 , V_922 ) ;
if ( ! F_1 ( V_2 ) )
return - V_837 ;
V_37 = V_741 ( V_2 , & V_743 ) ;
if ( V_37 == - V_338 )
return 0 ;
if ( V_37 )
return V_37 ;
F_434 ( V_921 ,
L_335 ,
V_743 . V_744 ,
V_743 . V_745 ,
V_743 . V_746 ) ;
switch ( V_743 . V_744 ) {
case V_930 :
case V_931 :
F_431 ( V_886 , V_902 , V_893 ) ;
V_886 -> V_929 = V_893 ;
break;
case V_932 :
case V_933 :
F_431 ( V_886 , V_902 , V_896 ) ;
V_886 -> V_929 = V_896 ;
break;
case V_934 :
case V_935 :
F_431 ( V_886 , V_899 , V_896 ) ;
V_886 -> V_929 = V_896 ;
break;
}
switch ( V_743 . V_745 ) {
case V_936 :
V_886 -> V_925 = V_926 ;
break;
case V_937 :
V_886 -> V_925 = V_938 ;
break;
}
switch ( V_743 . V_746 ) {
case V_939 :
V_922 = V_912 ;
break;
case V_940 :
V_922 = V_907 ;
break;
case V_941 :
V_922 = V_902 ;
break;
case V_942 :
V_922 = V_899 ;
break;
}
F_433 ( V_886 , V_922 ) ;
return 0 ;
}
static int T_10 F_435 ( void )
{
int V_37 ;
F_436 ( L_336 ) ;
F_136 ( & V_845 . V_42 ) ;
F_136 ( & V_834 ) ;
F_437 ( & V_845 . V_846 ) ;
F_142 ( & V_818 ) ;
V_11 = F_438 ( L_337 ) ;
V_37 = F_391 () ;
if ( V_37 )
goto V_943;
V_858 = F_439 ( L_338 ) ;
V_37 = F_440 ( V_858 ) ;
if ( V_37 )
goto V_944;
V_250 = F_441 ( L_339 ,
sizeof( struct V_604 ) + V_442 , 64 , 0 , NULL ) ;
if ( ! V_250 ) {
V_37 = - V_50 ;
goto V_945;
}
V_101 = F_441 ( L_340 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_946;
}
V_37 = F_442 ( & V_947 ) ;
if ( V_37 )
goto V_948;
V_859 . V_881 . V_949 = V_950 ;
V_37 = F_443 ( & V_859 ) ;
if ( V_37 )
goto V_951;
return 0 ;
V_951:
F_444 ( & V_947 ) ;
V_948:
F_445 ( V_101 ) ;
V_946:
F_445 ( V_250 ) ;
V_945:
F_446 ( V_858 ) ;
V_944:
F_386 () ;
V_943:
F_447 ( L_341 ) ;
return V_37 ;
}
static void T_11 F_448 ( void )
{
F_404 () ;
F_449 ( V_11 ) ;
F_450 ( & V_859 ) ;
F_444 ( & V_947 ) ;
F_445 ( V_101 ) ;
F_445 ( V_250 ) ;
F_446 ( V_858 ) ;
F_386 () ;
F_436 ( L_342 ) ;
}
