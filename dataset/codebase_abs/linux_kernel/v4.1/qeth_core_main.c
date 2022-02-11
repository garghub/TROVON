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
static struct V_1 * F_94 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_95 ( & ( (struct V_159 * )
F_95 ( & V_158 -> V_9 ) ) -> V_9 ) ;
return V_2 ;
}
static void F_70 ( struct V_160 * V_161 , unsigned char * V_113 ,
T_1 V_162 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_161 -> V_119 ) ;
F_4 ( V_2 , 4 , L_80 ) ;
if ( V_161 == & V_2 -> V_114 )
memcpy ( & V_161 -> V_120 , V_163 , sizeof( struct V_164 ) ) ;
else
memcpy ( & V_161 -> V_120 , V_165 , sizeof( struct V_164 ) ) ;
V_161 -> V_120 . V_166 = V_162 ;
V_161 -> V_120 . V_167 = ( T_1 ) F_96 ( V_113 ) ;
}
static struct V_112 * F_97 ( struct V_160 * V_161 )
{
T_2 V_168 ;
F_4 ( F_94 ( V_161 -> V_119 ) , 6 , L_81 ) ;
V_168 = V_161 -> V_169 ;
do {
if ( V_161 -> V_113 [ V_168 ] . V_3 == V_170 ) {
V_161 -> V_113 [ V_168 ] . V_3 = V_171 ;
V_161 -> V_169 = ( V_161 -> V_169 + 1 ) %
V_172 ;
memset ( V_161 -> V_113 [ V_168 ] . V_117 , 0 , V_118 ) ;
return V_161 -> V_113 + V_168 ;
}
V_168 = ( V_168 + 1 ) % V_172 ;
} while ( V_168 != V_161 -> V_169 );
return NULL ;
}
void F_98 ( struct V_160 * V_161 ,
struct V_112 * V_113 )
{
unsigned long V_32 ;
F_4 ( F_94 ( V_161 -> V_119 ) , 6 , L_82 ) ;
F_17 ( & V_161 -> V_173 , V_32 ) ;
memset ( V_113 -> V_117 , 0 , V_118 ) ;
V_113 -> V_3 = V_170 ;
V_113 -> V_174 = V_175 ;
V_113 -> V_37 = 0 ;
F_18 ( & V_161 -> V_173 , V_32 ) ;
F_19 ( & V_161 -> V_36 ) ;
}
static struct V_112 * F_66 ( struct V_160 * V_161 )
{
struct V_112 * V_64 = NULL ;
unsigned long V_32 ;
F_17 ( & V_161 -> V_173 , V_32 ) ;
V_64 = F_97 ( V_161 ) ;
F_18 ( & V_161 -> V_173 , V_32 ) ;
return V_64 ;
}
struct V_112 * F_99 ( struct V_160 * V_161 )
{
struct V_112 * V_64 ;
F_100 ( V_161 -> V_36 ,
( ( V_64 = F_66 ( V_161 ) ) != NULL ) ) ;
return V_64 ;
}
void F_101 ( struct V_160 * V_161 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ )
F_98 ( V_161 , & V_161 -> V_113 [ V_176 ] ) ;
V_161 -> V_177 = 0 ;
V_161 -> V_169 = 0 ;
}
static void V_175 ( struct V_160 * V_161 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 , * V_152 ;
struct V_129 * V_130 ;
unsigned long V_32 ;
int V_178 ;
int V_37 = 0 ;
V_2 = F_94 ( V_161 -> V_119 ) ;
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
V_2 -> V_179 . V_180 != NULL ) {
V_2 -> V_179 . V_180 ( V_2 -> V_9 , V_130 ) ;
goto V_73;
}
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_24 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_125 -> V_181 == V_182 ) ||
( ( V_130 ) && ( V_125 -> V_181 == V_130 -> V_133 . V_181 ) ) ) {
F_74 ( V_125 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
V_178 = 0 ;
if ( V_125 -> V_174 != NULL ) {
if ( V_130 ) {
V_125 -> V_183 = ( V_184 ) ( ( char * ) V_130 -
( char * ) V_113 -> V_117 ) ;
V_178 = V_125 -> V_174 ( V_2 ,
V_125 ,
( unsigned long ) V_130 ) ;
} else
V_178 = V_125 -> V_174 ( V_2 ,
V_125 ,
( unsigned long ) V_113 ) ;
}
if ( V_130 )
V_125 -> V_37 = ( V_185 ) V_130 -> V_133 . V_139 ;
else if ( V_113 -> V_37 )
V_125 -> V_37 = V_113 -> V_37 ;
if ( V_178 ) {
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_102 ( & V_125 -> V_42 ,
& V_2 -> V_186 ) ;
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
memcpy ( & V_2 -> V_181 . V_187 ,
F_103 ( V_113 -> V_117 ) ,
V_188 ) ;
F_98 ( V_161 , V_113 ) ;
}
static int F_104 ( struct V_160 * V_161 )
{
int V_176 ;
F_41 ( V_65 , 2 , L_84 ) ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
V_161 -> V_113 [ V_176 ] . V_117 =
F_27 ( V_118 , V_189 | V_49 ) ;
if ( V_161 -> V_113 [ V_176 ] . V_117 == NULL )
break;
V_161 -> V_113 [ V_176 ] . V_3 = V_170 ;
V_161 -> V_113 [ V_176 ] . V_161 = V_161 ;
V_161 -> V_113 [ V_176 ] . V_174 = V_175 ;
V_161 -> V_113 [ V_176 ] . V_37 = 0 ;
}
if ( V_176 < V_172 ) {
while ( V_176 -- > 0 )
F_32 ( V_161 -> V_113 [ V_176 ] . V_117 ) ;
return - V_50 ;
}
V_161 -> V_177 = 0 ;
V_161 -> V_169 = 0 ;
F_60 ( & V_161 -> V_122 , 0 ) ;
F_105 ( & V_161 -> V_173 ) ;
F_106 ( & V_161 -> V_36 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
unsigned long V_190 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( ! ( V_2 -> V_34 & V_190 ) ||
( V_2 -> V_35 & V_190 ) ) {
F_18 ( & V_2 -> V_33 , V_32 ) ;
return - V_57 ;
}
V_2 -> V_35 |= V_190 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return 0 ;
}
void F_108 ( struct V_1 * V_2 , unsigned long V_190 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_35 &= ~ V_190 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
void F_109 ( struct V_1 * V_2 , unsigned long V_190 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_38 &= ~ V_190 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned long V_190 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( V_2 -> V_35 & V_190 ) {
if ( ( V_2 -> V_34 & V_190 ) &&
! ( V_2 -> V_38 & V_190 ) ) {
V_37 = 1 ;
V_2 -> V_35 &= ~ V_190 ;
V_2 -> V_38 |= V_190 ;
} else
V_37 = - V_57 ;
}
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
int F_111 ( struct V_1 * V_2 , unsigned long V_190 )
{
int V_37 = 0 ;
F_100 ( V_2 -> V_36 ,
( V_37 = F_110 ( V_2 , V_190 ) ) >= 0 ) ;
return V_37 ;
}
void F_72 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_85 ) ;
if ( F_107 ( V_2 , V_191 ) == 0 )
F_112 ( & V_2 -> V_192 ) ;
}
static int F_113 ( struct V_157 * V_158 , struct V_193 * V_193 )
{
int V_194 , V_195 ;
char * V_196 ;
struct V_1 * V_2 ;
V_196 = ( char * ) V_193 -> V_197 ;
V_195 = V_193 -> V_198 . V_130 . V_195 ;
V_194 = V_193 -> V_198 . V_130 . V_194 ;
V_2 = F_94 ( V_158 ) ;
if ( V_195 & ( V_199 | V_200 |
V_201 | V_202 |
V_203 | V_204 ) ) {
F_4 ( V_2 , 2 , L_86 ) ;
F_67 ( & V_158 -> V_9 , L_48
L_49 ) ;
F_68 ( 2 , L_87 ,
F_69 ( & V_158 -> V_9 ) , V_194 , V_195 ) ;
F_114 ( V_205 , L_88 , V_206 ,
16 , 1 , V_193 , 64 , 1 ) ;
return 1 ;
}
if ( V_194 & V_207 ) {
if ( V_196 [ V_208 ] &
V_209 ) {
F_4 ( V_2 , 2 , L_89 ) ;
return 1 ;
}
if ( V_196 [ V_210 ] &
V_211 ) {
F_4 ( V_2 , 2 , L_90 ) ;
return 1 ;
}
if ( ( V_196 [ 2 ] == 0xaf ) && ( V_196 [ 3 ] == 0xfe ) ) {
F_4 ( V_2 , 2 , L_91 ) ;
return 1 ;
}
if ( ( ! V_196 [ 0 ] ) && ( ! V_196 [ 1 ] ) && ( ! V_196 [ 2 ] ) && ( ! V_196 [ 3 ] ) ) {
F_4 ( V_2 , 2 , L_92 ) ;
return 0 ;
}
F_4 ( V_2 , 2 , L_93 ) ;
return 1 ;
}
return 0 ;
}
static long F_115 ( struct V_157 * V_158 ,
unsigned long V_212 , struct V_193 * V_193 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_158 ) ;
if ( ! V_2 || ! F_116 ( V_193 ) )
return 0 ;
switch ( F_117 ( V_193 ) ) {
case - V_116 :
F_68 ( 2 , L_94 ,
F_69 ( & V_158 -> V_9 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_116 ) ;
break;
case - V_213 :
F_67 ( & V_158 -> V_9 , L_96
L_97 ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_213 ) ;
if ( V_212 == V_214 ) {
if ( V_2 -> V_117 . V_119 == V_158 ) {
V_2 -> V_117 . V_3 = V_215 ;
F_19 ( & V_2 -> V_36 ) ;
}
}
break;
default:
F_68 ( 2 , L_98 ,
F_69 ( & V_158 -> V_9 ) , F_117 ( V_193 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_4 ( V_2 , 2 , L_99 ) ;
}
return F_117 ( V_193 ) ;
}
static void F_118 ( struct V_157 * V_158 , unsigned long V_212 ,
struct V_193 * V_193 )
{
int V_37 ;
int V_195 , V_194 ;
struct V_112 * V_64 ;
struct V_160 * V_161 ;
struct V_1 * V_2 ;
struct V_112 * V_113 ;
T_2 V_168 ;
if ( F_115 ( V_158 , V_212 , V_193 ) )
return;
V_195 = V_193 -> V_198 . V_130 . V_195 ;
V_194 = V_193 -> V_198 . V_130 . V_194 ;
V_2 = F_94 ( V_158 ) ;
if ( ! V_2 )
return;
F_4 ( V_2 , 5 , L_100 ) ;
if ( V_2 -> V_114 . V_119 == V_158 ) {
V_161 = & V_2 -> V_114 ;
F_4 ( V_2 , 5 , L_101 ) ;
} else if ( V_2 -> V_154 . V_119 == V_158 ) {
V_161 = & V_2 -> V_154 ;
F_4 ( V_2 , 5 , L_102 ) ;
} else {
V_161 = & V_2 -> V_117 ;
F_4 ( V_2 , 5 , L_103 ) ;
}
F_60 ( & V_161 -> V_122 , 0 ) ;
if ( V_193 -> V_198 . V_130 . V_216 & ( V_217 ) )
V_161 -> V_3 = V_218 ;
if ( V_193 -> V_198 . V_130 . V_216 & ( V_219 ) )
V_161 -> V_3 = V_220 ;
if ( ( V_161 == & V_2 -> V_117 ) && ( V_212 != 0 ) &&
( V_212 != V_214 ) )
goto V_73;
if ( V_212 == V_221 ) {
F_4 ( V_2 , 6 , L_104 ) ;
V_212 = 0 ;
}
if ( V_212 == V_222 ) {
F_4 ( V_2 , 6 , L_105 ) ;
V_212 = 0 ;
}
if ( ( V_194 & V_223 ) ||
( V_194 & V_207 ) ||
( V_195 ) ) {
if ( V_193 -> V_224 . V_225 . V_226 . V_227 ) {
F_67 ( & V_161 -> V_119 -> V_9 ,
L_106
L_107 ) ;
F_68 ( 2 , L_108
L_109 ,
F_69 ( & V_161 -> V_119 -> V_9 ) , V_195 , V_194 ) ;
F_114 ( V_205 , L_88 ,
V_206 , 16 , 1 , V_193 , 32 , 1 ) ;
F_114 ( V_205 , L_110 ,
V_206 , 16 , 1 , V_193 -> V_197 , 32 , 1 ) ;
}
if ( V_212 == V_214 ) {
V_161 -> V_3 = V_215 ;
goto V_73;
}
V_37 = F_113 ( V_158 , V_193 ) ;
if ( V_37 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
}
if ( V_212 == V_214 ) {
V_161 -> V_3 = V_228 ;
goto V_73;
}
if ( V_212 ) {
V_64 = (struct V_112 * ) F_119 ( ( V_121 ) V_212 ) ;
V_64 -> V_3 = V_229 ;
}
if ( V_161 == & V_2 -> V_117 )
return;
if ( V_161 == & V_2 -> V_114 &&
V_161 -> V_3 == V_115 )
F_65 ( V_2 ) ;
V_113 = V_161 -> V_113 ;
V_168 = V_161 -> V_177 ;
while ( V_113 [ V_168 ] . V_3 == V_229 ) {
if ( V_113 [ V_168 ] . V_174 != NULL )
V_113 [ V_168 ] . V_174 ( V_161 , V_113 + V_168 ) ;
V_168 = ( V_168 + 1 ) % V_172 ;
}
V_161 -> V_177 = V_168 ;
V_73:
F_19 ( & V_2 -> V_36 ) ;
return;
}
static void F_61 ( struct V_92 * V_60 ,
struct V_96 * V_230 ,
enum V_82 V_105 )
{
struct V_231 * V_232 ;
if ( F_120 ( & V_230 -> V_233 ) )
goto V_73;
V_232 = F_121 ( & V_230 -> V_233 ) ;
while ( V_232 ) {
F_52 ( V_60 -> V_2 , 5 , L_111 , V_105 ) ;
F_52 ( V_60 -> V_2 , 5 , L_43 , ( long ) V_232 ) ;
if ( V_232 -> V_234 == V_235 ) {
if ( V_232 -> V_236 ) {
struct V_237 * V_238 = F_122 ( V_232 -> V_236 ) ;
V_238 -> V_239 ( V_232 , V_105 ) ;
}
}
if ( F_123 ( & V_230 -> V_233 , V_232 ) )
V_232 = NULL ;
else
V_232 = F_124 ( & V_230 -> V_233 , V_232 ) ;
}
V_73:
return;
}
static void F_53 ( struct V_96 * V_230 )
{
struct V_231 * V_232 ;
struct V_237 * V_238 ;
int V_240 = 0 ;
if ( F_51 ( & V_230 -> V_3 ) == V_109 )
V_240 = 1 ;
F_54 ( F_51 ( & V_230 -> V_3 ) == V_108 ) ;
V_232 = F_125 ( & V_230 -> V_233 ) ;
while ( V_232 ) {
F_4 ( V_230 -> V_60 -> V_2 , 5 , L_112 ) ;
F_52 ( V_230 -> V_60 -> V_2 , 5 , L_43 , ( long ) V_232 ) ;
if ( V_240 && V_232 -> V_234 == V_235 ) {
if ( V_232 -> V_236 ) {
V_238 = F_122 ( V_232 -> V_236 ) ;
V_238 -> V_239 ( V_232 , V_91 ) ;
}
}
F_126 ( & V_232 -> V_241 ) ;
F_127 ( V_232 ) ;
V_232 = F_125 ( & V_230 -> V_233 ) ;
}
}
static void F_62 ( struct V_92 * V_111 ,
struct V_96 * V_230 ,
enum V_242 V_243 )
{
int V_44 ;
if ( V_230 -> V_64 -> V_244 [ 0 ] . V_245 & V_246 )
F_126 ( & V_111 -> V_247 ) ;
if ( V_243 == V_248 ) {
F_53 ( V_230 ) ;
}
for ( V_44 = 0 ; V_44 < F_29 ( V_111 -> V_2 ) ; ++ V_44 ) {
if ( V_230 -> V_64 -> V_244 [ V_44 ] . V_249 && V_230 -> V_250 [ V_44 ] )
F_55 ( V_251 ,
V_230 -> V_64 -> V_244 [ V_44 ] . V_249 ) ;
V_230 -> V_250 [ V_44 ] = 0 ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_252 = 0 ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_249 = NULL ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_253 = 0 ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_245 = 0 ;
}
V_230 -> V_64 -> V_244 [ 15 ] . V_253 = 0 ;
V_230 -> V_64 -> V_244 [ 15 ] . V_245 = 0 ;
V_230 -> V_254 = 0 ;
F_60 ( & V_230 -> V_3 , V_243 ) ;
}
static void F_128 ( struct V_92 * V_60 , int free )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( ! V_60 -> V_63 [ V_45 ] )
continue;
F_50 ( V_60 , V_45 , 1 ) ;
F_62 ( V_60 , V_60 -> V_63 [ V_45 ] , V_248 ) ;
if ( free ) {
F_55 ( V_101 , V_60 -> V_63 [ V_45 ] ) ;
V_60 -> V_63 [ V_45 ] = NULL ;
}
}
}
void F_129 ( struct V_1 * V_2 )
{
int V_44 ;
F_4 ( V_2 , 2 , L_113 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
if ( V_2 -> V_46 . V_80 [ V_44 ] ) {
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 0 ) ;
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
static void F_130 ( struct V_160 * V_161 )
{
int V_176 ;
F_41 ( V_65 , 2 , L_114 ) ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ )
F_32 ( V_161 -> V_113 [ V_176 ] . V_117 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_255 ) &&
( V_2 -> V_46 . V_78 == 4 ) )
F_132 ( V_2 ) ;
V_2 -> V_46 . V_78 = 1 ;
if ( V_2 -> V_46 . V_256 != 0 )
F_89 ( & V_2 -> V_10 -> V_9 , L_115 ) ;
V_2 -> V_46 . V_256 = 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_255 ) &&
( V_2 -> V_46 . V_78 == 1 ) ) {
F_132 ( V_2 ) ;
V_2 -> V_46 . V_256 = 2 ;
}
V_2 -> V_46 . V_78 = 4 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_157 * V_119 ;
struct V_257 * V_258 ;
F_41 ( V_65 , 2 , L_116 ) ;
V_119 = V_2 -> V_117 . V_119 ;
V_258 = F_135 ( V_119 , 0 ) ;
if ( ! V_258 )
goto V_73;
V_2 -> V_12 . V_259 = 0x4100 + V_258 -> V_260 ;
if ( V_2 -> V_12 . type == V_15 )
goto V_73;
if ( ( V_258 -> V_261 & 0x02 ) == 0x02 )
F_131 ( V_2 ) ;
else
F_133 ( V_2 ) ;
V_73:
F_32 ( V_258 ) ;
F_45 ( V_65 , 2 , L_117 , V_2 -> V_46 . V_78 ) ;
F_45 ( V_65 , 2 , L_118 , V_2 -> V_12 . V_259 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 4 , L_119 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_255 ) ;
V_2 -> V_46 . V_262 = V_263 ;
if ( V_2 -> V_12 . type == V_15 )
V_2 -> V_46 . V_47 . V_48 = V_264 ;
else
V_2 -> V_46 . V_47 . V_48 = V_265 ;
V_2 -> V_46 . V_58 . V_48 = V_2 -> V_46 . V_47 . V_48 ;
F_137 ( & V_2 -> V_46 . V_58 . V_53 ) ;
F_137 ( & V_2 -> V_46 . V_47 . V_53 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
V_2 -> V_66 . V_266 . type = V_267 ;
V_2 -> V_66 . V_268 . type = V_267 ;
V_2 -> V_66 . V_269 = 0 ;
V_2 -> V_66 . V_270 = V_271 ;
V_2 -> V_66 . V_272 = 0 ;
V_2 -> V_66 . V_273 = V_274 ;
V_2 -> V_66 . V_275 = V_276 ;
V_2 -> V_66 . V_67 = V_277 ;
}
static int F_139 ( struct V_1 * V_2 , unsigned long V_190 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
F_52 ( V_2 , 4 , L_120 ,
( V_278 ) V_2 -> V_35 ,
( V_278 ) V_2 -> V_34 ,
( V_278 ) V_2 -> V_38 ) ;
V_37 = ( V_2 -> V_35 & V_190 ) ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
static void F_140 ( struct V_6 * V_7 )
{
struct V_279 * V_280 ;
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_192 ) ;
F_4 ( V_2 , 2 , L_121 ) ;
if ( V_2 -> V_114 . V_3 != V_115 &&
V_2 -> V_154 . V_3 != V_115 )
return;
if ( F_139 ( V_2 , V_191 ) ) {
V_280 = F_141 ( V_2 -> V_148 -> V_281 , ( void * ) V_2 ,
L_122 ) ;
if ( F_116 ( V_280 ) ) {
F_108 ( V_2 , V_191 ) ;
F_109 ( V_2 ,
V_191 ) ;
}
}
}
static int F_142 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_123 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_114 . V_3 = V_215 ;
V_2 -> V_154 . V_3 = V_215 ;
V_2 -> V_117 . V_3 = V_215 ;
V_2 -> V_3 = V_55 ;
V_2 -> V_143 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_9 = NULL ;
F_105 ( & V_2 -> V_282 ) ;
F_105 ( & V_2 -> V_283 ) ;
F_105 ( & V_2 -> V_153 ) ;
F_105 ( & V_2 -> V_284 ) ;
F_105 ( & V_2 -> V_33 ) ;
F_143 ( & V_2 -> V_285 ) ;
F_143 ( & V_2 -> V_286 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_38 = 0 ;
F_144 ( & V_2 -> V_192 , F_140 ) ;
F_137 ( & V_2 -> V_287 ) ;
F_137 ( V_2 -> V_288 ) ;
F_137 ( & V_2 -> V_186 ) ;
F_106 ( & V_2 -> V_36 ) ;
F_138 ( V_2 ) ;
F_137 ( & V_2 -> V_289 . V_290 ) ;
V_2 -> V_289 . V_291 = 0 ;
V_2 -> V_289 . V_292 = 0 ;
V_2 -> V_289 . V_293 = 0 ;
F_136 ( V_2 ) ;
F_145 ( & V_2 -> V_294 , V_295 ) ;
F_144 ( & V_2 -> V_8 , F_2 ) ;
return 0 ;
}
static void F_146 ( struct V_296 * V_297 , struct V_298 * V_299 )
{
struct V_1 * V_2 = F_3 ( V_299 , struct V_1 ,
V_300 ) ;
if ( V_2 -> V_12 . V_301 [ 0 ] )
F_147 ( V_297 , L_124 ,
F_148 ( V_2 ) , V_2 -> V_12 . V_301 ) ;
}
static struct V_1 * F_149 ( void )
{
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_125 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_189 | V_49 ) ;
if ( ! V_2 )
goto V_73;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_288 = F_27 ( sizeof( struct V_302 ) , V_49 ) ;
if ( ! V_2 -> V_288 ) {
F_41 ( V_65 , 0 , L_126 ) ;
goto V_303;
}
if ( F_104 ( & V_2 -> V_114 ) )
goto V_304;
if ( F_104 ( & V_2 -> V_154 ) )
goto V_305;
V_2 -> V_66 . V_306 = - 1 ;
V_2 -> V_300 . V_307 = F_146 ;
F_150 ( & V_2 -> V_300 ) ;
return V_2 ;
V_305:
F_130 ( & V_2 -> V_114 ) ;
V_304:
F_32 ( V_2 -> V_288 ) ;
V_303:
F_32 ( V_2 ) ;
V_73:
return NULL ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
F_41 ( V_65 , 2 , L_127 ) ;
V_2 -> V_46 . V_308 = V_309 ;
V_2 -> V_46 . V_256 = V_310 ;
while ( V_311 [ V_44 ] [ V_312 ] ) {
if ( ( F_152 ( V_2 ) -> V_313 . V_314 ==
V_311 [ V_44 ] [ V_315 ] ) &&
( F_152 ( V_2 ) -> V_313 . V_316 ==
V_311 [ V_44 ] [ V_312 ] ) ) {
V_2 -> V_12 . type = V_311 [ V_44 ] [ V_312 ] ;
V_2 -> V_46 . V_78 =
V_311 [ V_44 ] [ V_317 ] ;
V_2 -> V_46 . V_72 = 1 ;
V_2 -> V_12 . V_318 =
V_311 [ V_44 ] [ V_319 ] ;
F_134 ( V_2 ) ;
return 0 ;
}
V_44 ++ ;
}
V_2 -> V_12 . type = V_320 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_128
L_129 ) ;
return - V_321 ;
}
static int F_153 ( struct V_160 * V_161 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_161 -> V_119 ) ;
F_4 ( V_2 , 3 , L_130 ) ;
F_17 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
V_37 = F_155 ( V_161 -> V_119 , V_221 ) ;
F_18 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_156 ( V_2 -> V_36 ,
V_161 -> V_3 == V_218 , V_322 ) ;
if ( V_37 == - V_323 )
return V_37 ;
if ( V_161 -> V_3 != V_218 )
return - V_324 ;
V_161 -> V_3 = V_215 ;
return 0 ;
}
static int F_157 ( struct V_160 * V_161 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_161 -> V_119 ) ;
F_4 ( V_2 , 3 , L_131 ) ;
F_17 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
V_37 = F_158 ( V_161 -> V_119 , V_222 ) ;
F_18 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_156 ( V_2 -> V_36 ,
V_161 -> V_3 == V_220 , V_322 ) ;
if ( V_37 == - V_323 )
return V_37 ;
if ( V_161 -> V_3 != V_220 )
return - V_324 ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_325 = 0 , V_326 = 0 , V_327 = 0 ;
F_4 ( V_2 , 3 , L_132 ) ;
V_325 = F_157 ( & V_2 -> V_114 ) ;
V_326 = F_157 ( & V_2 -> V_154 ) ;
V_327 = F_157 ( & V_2 -> V_117 ) ;
if ( V_325 )
return V_325 ;
if ( V_326 )
return V_326 ;
return V_327 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_325 = 0 , V_326 = 0 , V_327 = 0 ;
F_4 ( V_2 , 3 , L_133 ) ;
V_325 = F_153 ( & V_2 -> V_114 ) ;
V_326 = F_153 ( & V_2 -> V_154 ) ;
V_327 = F_153 ( & V_2 -> V_117 ) ;
if ( V_325 )
return V_325 ;
if ( V_326 )
return V_326 ;
return V_327 ;
}
static int F_161 ( struct V_1 * V_2 , int V_328 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_134 ) ;
if ( V_328 )
V_37 = F_159 ( V_2 ) ;
if ( V_37 )
return V_37 ;
return F_160 ( V_2 ) ;
}
int F_162 ( struct V_1 * V_2 , int V_329 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_135 ) ;
switch ( F_59 ( & V_2 -> V_46 . V_3 , V_330 ,
V_331 ) ) {
case V_330 :
if ( V_2 -> V_12 . type == V_15 )
V_37 = F_163 ( F_44 ( V_2 ) ,
V_332 ) ;
else
V_37 = F_163 ( F_44 ( V_2 ) ,
V_333 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_37 , V_37 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_334 ) ;
break;
case V_331 :
return V_37 ;
default:
break;
}
V_37 = F_161 ( V_2 , V_329 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_136 , V_37 ) ;
V_2 -> V_3 = V_55 ;
return V_37 ;
}
static int F_164 ( struct V_1 * V_2 , void * * V_64 ,
int * V_252 )
{
struct V_335 * V_335 ;
char * V_336 ;
int V_337 ;
struct V_160 * V_161 = & V_2 -> V_117 ;
unsigned long V_32 ;
V_335 = F_165 ( V_161 -> V_119 , V_338 ) ;
if ( ! V_335 || V_335 -> V_130 == 0 )
return - V_339 ;
V_336 = F_27 ( V_335 -> V_166 , V_49 | V_189 ) ;
if ( ! V_336 )
return - V_50 ;
V_161 -> V_120 . V_340 = V_335 -> V_130 ;
V_161 -> V_120 . V_167 = ( T_1 ) F_96 ( V_336 ) ;
V_161 -> V_120 . V_166 = V_335 -> V_166 ;
V_161 -> V_120 . V_32 = V_341 ;
V_161 -> V_3 = V_342 ;
F_17 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
V_337 = F_166 ( V_161 -> V_119 , & V_161 -> V_120 ,
V_214 , V_343 , 0 ,
V_344 ) ;
F_18 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
if ( ! V_337 )
F_100 ( V_2 -> V_36 ,
( V_161 -> V_3 == V_228 ||
V_161 -> V_3 == V_215 ) ) ;
if ( V_161 -> V_3 == V_215 )
V_337 = - V_116 ;
else
V_161 -> V_3 = V_215 ;
if ( V_337 ) {
F_32 ( V_336 ) ;
* V_64 = NULL ;
* V_252 = 0 ;
} else {
* V_252 = V_335 -> V_166 ;
* V_64 = V_336 ;
}
return V_337 ;
}
static void F_167 ( struct V_1 * V_2 , char * V_345 )
{
F_41 ( V_65 , 2 , L_137 ) ;
V_2 -> V_12 . V_142 = V_345 [ 30 ] ;
V_2 -> V_12 . V_346 = V_345 [ 31 ] ;
V_2 -> V_12 . V_347 = V_345 [ 63 ] ;
V_2 -> V_12 . V_13 = ( ( V_345 [ 0x10 ] == V_348 [ 'V' ] ) &&
( V_345 [ 0x11 ] == V_348 [ 'M' ] ) ) ;
}
static void F_168 ( struct V_1 * V_2 , char * V_345 )
{
F_41 ( V_65 , 2 , L_138 ) ;
if ( V_345 [ 74 ] == 0xF0 && V_345 [ 75 ] == 0xF0 &&
V_345 [ 76 ] >= 0xF1 && V_345 [ 76 ] <= 0xF4 ) {
V_2 -> V_12 . V_349 . V_350 = 0 ;
V_2 -> V_12 . V_349 . V_351 = 0 ;
V_2 -> V_12 . V_349 . V_352 = 0 ;
} else {
V_2 -> V_12 . V_349 . V_350 = 250 ;
V_2 -> V_12 . V_349 . V_351 = 5 ;
V_2 -> V_12 . V_349 . V_352 = 15 ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
V_2 -> V_353 . V_354 = 0x00010103UL ;
V_2 -> V_353 . V_355 = 0x00010108UL ;
V_2 -> V_353 . V_356 = 0x0001010aUL ;
V_2 -> V_353 . V_357 = 0x0001010bUL ;
V_2 -> V_353 . V_358 = 0x0001010dUL ;
}
static void F_170 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
V_2 -> V_12 . V_259 = V_359 ;
break;
case V_14 :
case V_18 :
V_2 -> V_12 . V_259 = V_360 ;
break;
default:
break;
}
}
static int F_171 ( struct V_160 * V_161 ,
void (* F_172)( struct V_160 * ,
struct V_112 * ) )
{
struct V_112 * V_113 ;
unsigned long V_32 ;
int V_37 ;
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_139 ) ;
V_2 = F_94 ( V_161 -> V_119 ) ;
V_113 = F_66 ( V_161 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_174 = F_172 ;
memcpy ( & V_161 -> V_120 , V_163 , sizeof( struct V_164 ) ) ;
V_161 -> V_120 . V_166 = V_118 ;
V_161 -> V_120 . V_167 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_161 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_161 -> V_119 ,
& V_161 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_140 , V_37 ) ;
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
F_60 ( & V_161 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_156 ( V_2 -> V_36 ,
V_161 -> V_3 == V_115 , V_322 ) ;
if ( V_37 == - V_323 )
return V_37 ;
if ( V_161 -> V_3 != V_115 ) {
V_37 = - V_324 ;
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
F_101 ( V_161 ) ;
} else
V_37 = 0 ;
return V_37 ;
}
static int F_173 ( struct V_160 * V_161 ,
void (* F_172)( struct V_160 * ,
struct V_112 * ) )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
unsigned long V_32 ;
V_184 V_361 ;
T_2 V_41 ;
int V_37 ;
struct V_362 V_363 ;
V_2 = F_94 ( V_161 -> V_119 ) ;
F_41 ( V_65 , 2 , L_142 ) ;
V_113 = F_66 ( V_161 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_174 = F_172 ;
memcpy ( & V_161 -> V_120 , V_165 , sizeof( struct V_164 ) ) ;
V_161 -> V_120 . V_166 = V_364 ;
V_161 -> V_120 . V_167 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
if ( V_161 == & V_2 -> V_154 ) {
memcpy ( V_113 -> V_117 , V_365 , V_364 ) ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_181 . V_366 , V_188 ) ;
V_2 -> V_181 . V_366 ++ ;
} else {
memcpy ( V_113 -> V_117 , V_367 , V_364 ) ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_181 . V_366 , V_188 ) ;
}
V_41 = ( ( T_2 ) V_2 -> V_12 . V_368 ) | 0x80 ;
memcpy ( F_175 ( V_113 -> V_117 ) , & V_41 , 1 ) ;
memcpy ( F_176 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_354 , V_369 ) ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_12 . V_259 , sizeof( V_184 ) ) ;
F_178 ( F_44 ( V_2 ) , & V_363 ) ;
memcpy ( F_179 ( V_113 -> V_117 ) , & V_363 . V_370 , 2 ) ;
V_361 = ( V_2 -> V_12 . V_347 << 8 ) + V_2 -> V_12 . V_346 ;
memcpy ( F_180 ( V_113 -> V_117 ) , & V_361 , 2 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_161 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_161 -> V_119 ,
& V_161 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_161 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_143 ,
V_37 ) ;
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
F_60 ( & V_161 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_156 ( V_2 -> V_36 ,
V_161 -> V_3 == V_371 , V_322 ) ;
if ( V_37 == - V_323 )
return V_37 ;
if ( V_161 -> V_3 != V_371 ) {
F_67 ( & V_161 -> V_119 -> V_9 , L_144
L_145 ) ;
F_68 ( 2 , L_146 ,
F_69 ( & V_161 -> V_119 -> V_9 ) ) ;
F_45 ( V_65 , 2 , L_136 , - V_324 ) ;
F_101 ( V_161 ) ;
return - V_324 ;
}
return F_171 ( V_161 , F_172 ) ;
}
static int F_181 ( int V_372 )
{
if ( ( V_372 & 0xff ) == 8 )
return ( V_372 & 0xff ) + 0x400 ;
if ( ( ( V_372 >> 8 ) & 3 ) == 1 )
return ( V_372 & 0xff ) + 0x200 ;
return V_372 ;
}
static void F_182 ( struct V_160 * V_161 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_184 V_361 ;
F_41 ( V_65 , 2 , L_147 ) ;
if ( V_161 -> V_3 == V_215 ) {
V_161 -> V_3 = V_371 ;
goto V_73;
}
V_2 = F_94 ( V_161 -> V_119 ) ;
if ( ! ( F_183 ( V_113 -> V_117 ) ) ) {
if ( F_184 ( V_113 -> V_117 ) == V_373 )
F_47 ( & V_2 -> V_154 . V_119 -> V_9 ,
L_148
L_149 ) ;
else
F_68 ( 2 , L_150
L_151 ,
F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) ) ;
goto V_73;
}
memcpy ( & V_361 , F_177 ( V_113 -> V_117 ) , 2 ) ;
if ( ( V_361 & ~ 0x0100 ) != F_181 ( V_2 -> V_12 . V_259 ) ) {
F_68 ( 2 , L_152
L_153
L_154 , F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_259 , V_361 ) ;
goto V_73;
}
V_161 -> V_3 = V_115 ;
V_73:
F_98 ( V_161 , V_113 ) ;
}
static void F_185 ( struct V_160 * V_161 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_184 V_361 ;
F_41 ( V_65 , 2 , L_155 ) ;
if ( V_161 -> V_3 == V_215 ) {
V_161 -> V_3 = V_371 ;
goto V_73;
}
V_2 = F_94 ( V_161 -> V_119 ) ;
if ( F_93 ( V_2 , V_113 -> V_117 ) )
goto V_73;
if ( ! ( F_183 ( V_113 -> V_117 ) ) ) {
switch ( F_184 ( V_113 -> V_117 ) ) {
case V_373 :
F_47 ( & V_2 -> V_154 . V_119 -> V_9 ,
L_148
L_149 ) ;
break;
case V_374 :
case V_375 :
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
F_184 ( V_113 -> V_117 ) ) ;
goto V_73;
}
if ( ( ! F_186 ( V_113 -> V_117 ) ) ||
( V_2 -> V_12 . type == V_14 ) )
V_2 -> V_12 . V_376 = 1 ;
memcpy ( & V_361 , F_177 ( V_113 -> V_117 ) , 2 ) ;
if ( V_361 != F_181 ( V_2 -> V_12 . V_259 ) ) {
F_68 ( 2 , L_160
L_161 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_259 , V_361 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_353 . V_377 ,
F_176 ( V_113 -> V_117 ) ,
V_369 ) ;
memcpy ( & V_2 -> V_12 . V_301 [ 0 ] ,
F_187 ( V_113 -> V_117 ) , V_378 ) ;
V_161 -> V_3 = V_115 ;
V_73:
F_98 ( V_161 , V_113 ) ;
}
void F_188 ( struct V_1 * V_2 , int V_162 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_154 , V_113 -> V_117 , V_162 ) ;
V_113 -> V_174 = F_98 ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_181 . V_366 , V_188 ) ;
V_2 -> V_181 . V_366 ++ ;
memcpy ( F_103 ( V_113 -> V_117 ) ,
& V_2 -> V_181 . V_379 , V_188 ) ;
V_2 -> V_181 . V_379 ++ ;
memcpy ( F_189 ( V_113 -> V_117 ) ,
& V_2 -> V_181 . V_187 , V_188 ) ;
F_39 ( V_155 , 2 , V_113 -> V_117 , V_156 ) ;
}
int F_190 ( struct V_1 * V_2 , int V_162 ,
struct V_112 * V_113 ,
int (* F_191)( struct V_1 * V_380 ,
struct V_124 * V_381 ,
unsigned long V_382 ) ,
void * V_383 )
{
int V_37 ;
unsigned long V_32 ;
struct V_124 * V_125 = NULL ;
unsigned long V_384 , V_385 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 2 , L_162 ) ;
if ( V_2 -> V_123 ) {
F_98 ( V_113 -> V_161 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_174 = F_191 ;
V_125 -> V_386 = V_383 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_181 = V_182 ;
else
V_125 -> V_181 = V_2 -> V_181 . V_387 ++ ;
F_106 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_102 ( & V_125 -> V_42 , & V_2 -> V_186 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
F_39 ( V_155 , 2 , V_113 -> V_117 , V_156 ) ;
while ( F_59 ( & V_2 -> V_154 . V_122 , 0 , 1 ) ) ;
F_188 ( V_2 , V_162 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_385 = V_388 ;
else
V_385 = V_322 ;
V_384 = V_389 + V_385 ;
F_4 ( V_2 , 6 , L_52 ) ;
F_17 ( F_154 ( V_2 -> V_154 . V_119 ) , V_32 ) ;
V_37 = F_71 ( V_2 -> V_154 . V_119 , & V_2 -> V_154 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_2 -> V_154 . V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_163
L_164 ,
F_69 ( & V_2 -> V_154 . V_119 -> V_9 ) , V_37 ) ;
F_52 ( V_2 , 2 , L_165 , V_37 ) ;
F_17 ( & V_2 -> V_153 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_77 ( V_125 ) ;
F_18 ( & V_2 -> V_153 , V_32 ) ;
F_98 ( V_113 -> V_161 , V_113 ) ;
F_60 ( & V_2 -> V_154 . V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
if ( ( V_130 -> V_133 . V_134 == V_391 ) &&
( V_130 -> V_133 . V_392 == V_393 ) ) {
if ( ! F_192 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_385 ) )
goto V_394;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_193 ( V_389 , V_384 ) )
goto V_394;
F_194 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_394:
V_125 -> V_37 = - V_324 ;
F_17 ( & V_125 -> V_2 -> V_153 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_125 -> V_2 -> V_153 , V_32 ) ;
F_76 ( & V_125 -> V_128 ) ;
error:
F_60 ( & V_2 -> V_154 . V_122 , 0 ) ;
F_98 ( V_113 -> V_161 , V_113 ) ;
V_2 -> V_154 . V_177 = ( V_2 -> V_154 . V_177 + 1 ) % V_172 ;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
}
static int F_195 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_166 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_353 . V_395 ,
F_196 ( V_113 -> V_117 ) ,
V_369 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_167 ) ;
V_113 = F_99 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_396 , V_397 ) ;
memcpy ( F_198 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_377 , V_369 ) ;
memcpy ( F_199 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_355 , V_369 ) ;
V_37 = F_190 ( V_2 , V_397 , V_113 ,
F_195 , NULL ) ;
return V_37 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_353 . V_398 ,
F_201 ( V_113 -> V_117 ) ,
V_369 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = F_99 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_399 , V_400 ) ;
memcpy ( F_203 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_377 , V_369 ) ;
memcpy ( F_204 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_356 , V_369 ) ;
memcpy ( F_205 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_395 , V_369 ) ;
V_37 = F_190 ( V_2 , V_400 , V_113 ,
F_200 , NULL ) ;
return V_37 ;
}
static inline int F_206 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_320 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_401 ;
case V_14 :
switch ( V_2 -> V_12 . V_19 ) {
case V_21 :
case V_25 :
return 2000 ;
default:
return V_2 -> V_66 . V_306 ? 1500 : 1492 ;
}
case V_16 :
case V_17 :
return V_2 -> V_66 . V_306 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_207 ( int V_402 )
{
switch ( V_402 ) {
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
static inline int F_208 ( struct V_1 * V_2 , int V_403 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_403 >= 576 ) &&
( V_403 <= V_2 -> V_12 . V_401 ) ) ;
case V_18 :
case V_320 :
default:
return 1 ;
}
}
static int F_209 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_184 V_403 , V_402 ;
V_184 V_162 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_170 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_353 . V_404 ,
F_210 ( V_113 -> V_117 ) ,
V_369 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_402 , F_211 ( V_113 -> V_117 ) , 2 ) ;
V_403 = F_207 ( V_402 ) ;
if ( ! V_403 ) {
V_113 -> V_37 = - V_405 ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
if ( V_2 -> V_12 . V_406 && ( V_2 -> V_12 . V_406 != V_403 ) ) {
if ( V_2 -> V_9 &&
( ( V_2 -> V_9 -> V_403 == V_2 -> V_12 . V_406 ) ||
( V_2 -> V_9 -> V_403 > V_403 ) ) )
V_2 -> V_9 -> V_403 = V_403 ;
F_132 ( V_2 ) ;
}
V_2 -> V_12 . V_406 = V_403 ;
V_2 -> V_12 . V_401 = V_403 ;
V_2 -> V_46 . V_262 = V_403 + 2 * V_407 ;
} else {
V_2 -> V_12 . V_401 = * ( V_184 * ) F_211 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_406 = F_212 ( V_2 -> V_12 . V_401 ,
F_206 ( V_2 ) ) ;
V_2 -> V_46 . V_262 = V_263 ;
}
memcpy ( & V_162 , F_213 ( V_113 -> V_117 ) , 2 ) ;
if ( V_162 >= V_408 ) {
memcpy ( & V_19 ,
F_214 ( V_113 -> V_117 ) , 1 ) ;
V_2 -> V_12 . V_19 = V_19 ;
} else
V_2 -> V_12 . V_19 = 0 ;
F_45 ( V_65 , 2 , L_171 , V_2 -> V_12 . V_19 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_215 ( struct V_1 * V_2 )
{
int V_37 ;
char V_409 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = F_99 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_410 , V_411 ) ;
* ( F_216 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_368 ;
if ( V_2 -> V_66 . V_306 )
if ( V_2 -> V_12 . type == V_18 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
memcpy ( F_217 ( V_113 -> V_117 ) , & V_409 , 1 ) ;
memcpy ( F_218 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_398 , V_369 ) ;
memcpy ( F_219 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_357 , V_369 ) ;
memcpy ( F_220 ( V_113 -> V_117 ) ,
V_2 -> V_12 . V_415 , 9 ) ;
V_37 = F_190 ( V_2 , V_411 , V_113 ,
F_209 , NULL ) ;
return V_37 ;
}
static int F_221 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_173 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_353 . V_416 ,
F_222 ( V_113 -> V_117 ) ,
V_369 ) ;
if ( ! strncmp ( L_174 , F_222 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_175 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_176
L_177 ) ;
V_113 -> V_37 = - V_417 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 )
{
int V_37 ;
V_184 V_361 ;
struct V_112 * V_113 ;
struct V_362 V_418 ;
F_41 ( V_65 , 2 , L_178 ) ;
V_113 = F_99 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_419 , V_420 ) ;
memcpy ( F_224 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_398 , V_369 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_358 , V_369 ) ;
memcpy ( F_226 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_404 , V_369 ) ;
F_178 ( F_44 ( V_2 ) , & V_418 ) ;
memcpy ( F_227 ( V_113 -> V_117 ) , & V_418 . V_370 , 2 ) ;
V_361 = ( V_2 -> V_12 . V_347 << 8 ) + V_2 -> V_12 . V_346 ;
memcpy ( F_228 ( V_113 -> V_117 ) , & V_361 , 2 ) ;
V_37 = F_190 ( V_2 , V_420 , V_113 ,
F_221 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_421 ;
V_37 = 0 ;
V_421 = F_229 ( V_101 , V_126 ) ;
if ( ! V_421 ) {
V_37 = - V_50 ;
goto V_73;
}
V_421 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_230 ( & V_421 -> V_233 ) ;
F_231 ( & V_421 -> V_233 . V_153 , & V_422 ) ;
V_421 -> V_60 = V_60 ;
V_421 -> V_102 = NULL ;
V_421 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_421 -> V_3 , V_248 ) ;
V_60 -> V_63 [ V_93 ] = V_421 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_423 = V_421 ;
F_52 ( V_60 -> V_2 , 2 , L_179 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_421 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_421 -> V_95 ) ;
}
V_73:
return V_37 ;
}
static void F_232 ( struct V_92 * V_60 )
{
if ( ! V_60 )
return;
F_36 ( V_60 -> V_61 , V_62 ) ;
F_32 ( V_60 ) ;
}
static struct V_92 * F_233 ( void )
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
static int F_234 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
F_41 ( V_65 , 2 , L_180 ) ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_255 ,
V_334 ) != V_255 )
return 0 ;
F_41 ( V_65 , 2 , L_181 ) ;
V_2 -> V_46 . V_424 = F_37 () ;
if ( ! V_2 -> V_46 . V_424 )
goto V_425;
if ( F_26 ( V_2 ) )
goto V_426;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_427;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_233 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_428;
F_45 ( V_65 , 2 , L_182 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_429 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_430;
}
}
if ( F_46 ( V_2 ) )
goto V_428;
return 0 ;
V_430:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_428:
while ( V_44 > 0 ) {
F_232 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_427:
F_28 ( V_2 ) ;
V_426:
F_35 ( V_2 -> V_46 . V_424 ) ;
V_2 -> V_46 . V_424 = NULL ;
V_425:
F_60 ( & V_2 -> V_46 . V_3 , V_255 ) ;
return - V_50 ;
}
static void F_132 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_235 ( & V_2 -> V_46 . V_3 , V_255 ) ==
V_255 )
return;
F_48 ( V_2 ) ;
F_236 ( & V_2 -> V_294 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_424 -> V_63 [ V_45 ] . V_431 )
F_127 ( V_2 -> V_46 . V_424 -> V_63 [ V_45 ] . V_431 ) ;
}
F_35 ( V_2 -> V_46 . V_424 ) ;
V_2 -> V_46 . V_424 = NULL ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 . V_80 ) {
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
F_232 ( V_2 -> V_46 . V_80 [ V_44 ] ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
}
}
static void F_237 ( struct V_1 * V_2 ,
char * V_432 )
{
V_432 [ 0 ] = V_348 [ 'P' ] ;
V_432 [ 1 ] = V_348 [ 'C' ] ;
V_432 [ 2 ] = V_348 [ 'I' ] ;
V_432 [ 3 ] = V_348 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_432 [ 4 ] ) ) = F_238 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_432 [ 8 ] ) ) = F_239 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_432 [ 12 ] ) ) = F_240 ( V_2 ) ;
}
static void F_241 ( struct V_1 * V_2 ,
char * V_432 )
{
V_432 [ 16 ] = V_348 [ 'B' ] ;
V_432 [ 17 ] = V_348 [ 'L' ] ;
V_432 [ 18 ] = V_348 [ 'K' ] ;
V_432 [ 19 ] = V_348 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_432 [ 20 ] ) ) = V_2 -> V_12 . V_349 . V_350 ;
* ( ( unsigned int * ) ( & V_432 [ 24 ] ) ) = V_2 -> V_12 . V_349 . V_351 ;
* ( ( unsigned int * ) ( & V_432 [ 28 ] ) ) =
V_2 -> V_12 . V_349 . V_352 ;
}
static int F_242 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 3 , L_183 ) ;
return F_243 ( F_44 ( V_2 ) ) ;
}
static int F_244 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_184 ) ;
V_113 = F_99 ( & V_2 -> V_154 ) ;
memcpy ( V_113 -> V_117 , V_433 , V_434 ) ;
memcpy ( F_245 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_398 , V_369 ) ;
memcpy ( F_246 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_416 , V_369 ) ;
V_37 = F_190 ( V_2 , V_434 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_247 ( struct V_1 * V_2 )
{
int V_37 ;
F_41 ( V_65 , 2 , L_185 ) ;
V_37 = F_65 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
return V_37 ;
}
V_37 = F_197 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_435;
}
V_37 = F_202 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_435;
}
V_37 = F_215 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_435;
}
V_37 = F_223 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_435;
}
V_37 = F_234 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_435;
}
V_37 = F_248 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_132 ( V_2 ) ;
goto V_435;
}
V_37 = F_242 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_435;
}
V_37 = F_244 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
goto V_435;
}
return 0 ;
V_435:
F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_249 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
static void F_250 ( struct V_1 * V_2 )
{
char V_436 [ 15 ] ;
int V_44 ;
sprintf ( V_436 , L_191 , V_2 -> V_12 . V_415 + 1 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_436 [ V_44 ] =
( char ) V_437 [ ( T_2 ) V_436 [ V_44 ] ] ;
V_436 [ 8 ] = 0 ;
F_89 ( & V_2 -> V_10 -> V_9 , L_192
L_193 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? V_2 -> V_12 . V_301 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ,
V_436 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_415 [ 0 ] )
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_197
L_198 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? V_2 -> V_12 . V_301 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
else
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_199 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? V_2 -> V_12 . V_301 : L_74 ,
( V_2 -> V_12 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
}
void F_252 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_301 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_301 , L_200 ,
V_2 -> V_12 . V_301 [ 2 ] ,
V_2 -> V_12 . V_301 [ 3 ] ) ;
V_2 -> V_12 . V_301 [ V_378 ] = 0 ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_301 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_301 [ 0 ] = ( char ) V_437 [ ( T_2 )
V_2 -> V_12 . V_301 [ 0 ] ] ;
V_2 -> V_12 . V_301 [ 1 ] = ( char ) V_437 [ ( T_2 )
V_2 -> V_12 . V_301 [ 1 ] ] ;
V_2 -> V_12 . V_301 [ 2 ] = ( char ) V_437 [ ( T_2 )
V_2 -> V_12 . V_301 [ 2 ] ] ;
V_2 -> V_12 . V_301 [ 3 ] = ( char ) V_437 [ ( T_2 )
V_2 -> V_12 . V_301 [ 3 ] ] ;
V_2 -> V_12 . V_301 [ V_378 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_301 [ 0 ] , 0 , V_378 + 1 ) ;
}
if ( V_2 -> V_12 . V_376 )
F_250 ( V_2 ) ;
else
F_251 ( V_2 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_39 * V_438 ;
F_4 ( V_2 , 5 , L_201 ) ;
F_254 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_255 ( V_2 , V_438 ) ;
}
}
static inline struct V_39 * F_256 (
struct V_1 * V_2 )
{
struct V_302 * V_439 ;
struct V_39 * V_438 ;
int V_44 , free ;
struct V_440 * V_440 ;
if ( F_257 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_258 (plh, &card->qdio.in_buf_pool.entry_list) {
V_438 = F_259 ( V_439 , struct V_39 , V_42 ) ;
free = 1 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_260 ( F_261 ( V_438 -> V_51 [ V_44 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_92 ( & V_438 -> V_42 ) ;
return V_438 ;
}
}
V_438 = F_259 ( V_2 -> V_46 . V_58 . V_53 . V_441 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_260 ( F_261 ( V_438 -> V_51 [ V_44 ] ) ) > 1 ) {
V_440 = F_262 ( V_126 ) ;
if ( ! V_440 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_438 -> V_51 [ V_44 ] ) ;
V_438 -> V_51 [ V_44 ] = F_263 ( V_440 ) ;
if ( V_2 -> V_66 . V_272 )
V_2 -> V_442 . V_443 ++ ;
}
}
}
F_92 ( & V_438 -> V_42 ) ;
return V_438 ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_444 * V_230 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_230 -> V_431 ) ) {
V_230 -> V_431 = F_265 ( V_445 + V_446 ) ;
if ( ! V_230 -> V_431 )
return 1 ;
}
V_40 = F_256 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_230 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_230 -> V_64 -> V_244 [ V_44 ] . V_252 = V_407 ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_249 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_230 -> V_64 -> V_244 [ V_44 ] . V_253 = V_447 ;
else
V_230 -> V_64 -> V_244 [ V_44 ] . V_253 = 0 ;
V_230 -> V_64 -> V_244 [ V_44 ] . V_245 = 0 ;
}
return 0 ;
}
int F_266 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_202 ) ;
F_42 ( V_2 -> V_46 . V_424 -> V_61 ,
V_62 ) ;
F_253 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_264 ( V_2 , & V_2 -> V_46 . V_424 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_424 -> V_70 =
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
V_248 ) ;
}
V_2 -> V_46 . V_80 [ V_44 ] -> V_2 = V_2 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_448 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_449 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_450 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_247 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_451 ) ;
}
return 0 ;
}
static inline T_2 F_267 ( enum V_452 V_19 )
{
switch ( V_19 ) {
case V_21 :
return 2 ;
default:
return 1 ;
}
}
static void F_268 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_2 V_134 ,
enum V_453 V_454 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_455 = V_456 ;
V_130 -> V_133 . V_181 = V_2 -> V_181 . V_387 ;
V_130 -> V_133 . V_457 = F_267 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_458 = ( T_2 ) V_2 -> V_12 . V_368 ;
if ( V_2 -> V_66 . V_306 )
V_130 -> V_133 . V_459 = 2 ;
else
V_130 -> V_133 . V_459 = 1 ;
V_130 -> V_133 . V_460 = 1 ;
V_130 -> V_133 . V_392 = V_454 ;
V_130 -> V_133 . V_461 = 0 ;
V_130 -> V_133 . V_462 = 0 ;
}
struct V_112 * F_269 ( struct V_1 * V_2 ,
enum V_463 V_464 , enum V_453 V_454 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_66 ( & V_2 -> V_154 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
F_268 ( V_2 , V_130 , V_464 , V_454 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_203 ) ;
F_68 ( 1 , L_204 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
}
return V_113 ;
}
void F_270 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_409 )
{
memcpy ( V_113 -> V_117 , V_465 , V_390 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) , & V_409 , 1 ) ;
memcpy ( F_272 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_416 , V_369 ) ;
}
int F_273 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_383 )
{
int V_37 ;
char V_409 ;
F_4 ( V_2 , 4 , L_205 ) ;
if ( V_2 -> V_66 . V_306 )
if ( V_2 -> V_12 . type == V_18 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
F_270 ( V_2 , V_113 , V_409 ) ;
V_37 = F_190 ( V_2 , V_466 ,
V_113 , F_191 , V_383 ) ;
if ( V_37 == - V_324 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_37 ;
}
int F_274 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_206 ) ;
V_113 = F_269 ( V_2 , V_144 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_273 ( V_2 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_207 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 )
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_467 . V_133 . V_139 ;
return 0 ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_208 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_467 . V_117 . V_468 . V_469 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_467 . V_117 . V_468 . V_469 ;
F_45 ( V_65 , 2 , L_209 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_470 . V_471 =
V_130 -> V_117 . V_467 . V_117 . V_468 . V_472 ;
return F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_277 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_473 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_269 ( V_2 , V_474 ,
V_393 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_467 . V_133 . V_475 = V_473 ;
V_130 -> V_117 . V_467 . V_133 . V_476 = V_134 ;
V_130 -> V_117 . V_467 . V_133 . V_477 = 1 ;
V_130 -> V_117 . V_467 . V_133 . V_478 = 1 ;
}
return V_113 ;
}
int F_278 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_210 ) ;
V_113 = F_277 ( V_2 , V_479 ,
sizeof( struct V_480 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_273 ( V_2 , V_113 , F_276 , NULL ) ;
return V_37 ;
}
static int F_279 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_211 ) ;
V_130 = (struct V_129 * ) V_117 ;
switch ( V_130 -> V_133 . V_139 ) {
case V_481 :
case V_482 :
F_41 ( V_65 , 2 , L_212 ) ;
V_2 -> V_66 . V_483 . V_471 |= V_484 ;
V_2 -> V_66 . V_485 . V_471 |= V_484 ;
return - 0 ;
default:
if ( V_130 -> V_133 . V_139 ) {
F_68 ( 1 , L_213
L_214 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ,
V_130 -> V_133 . V_139 ) ;
return 0 ;
}
}
if ( V_130 -> V_133 . V_392 == V_393 ) {
V_2 -> V_66 . V_483 . V_471 = V_130 -> V_133 . V_461 ;
V_2 -> V_66 . V_483 . V_486 = V_130 -> V_133 . V_462 ;
} else if ( V_130 -> V_133 . V_392 == V_487 ) {
V_2 -> V_66 . V_485 . V_471 = V_130 -> V_133 . V_461 ;
V_2 -> V_66 . V_485 . V_486 = V_130 -> V_133 . V_462 ;
} else
F_68 ( 1 , L_215
L_216 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_280 ( struct V_1 * V_2 , enum V_453 V_454 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_217 , V_454 ) ;
V_113 = F_269 ( V_2 , V_488 , V_454 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_273 ( V_2 , V_113 , F_279 , NULL ) ;
return V_37 ;
}
static int F_281 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_489 * V_490 ;
struct V_491 * V_492 ;
F_4 ( V_2 , 2 , L_218 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_490 = (struct V_489 * ) V_125 -> V_386 ;
if ( V_130 -> V_117 . V_467 . V_133 . V_139 == 0 ) {
V_492 = & V_130 -> V_117 . V_467 . V_117 . V_493 ;
V_490 -> V_494 = V_492 -> V_494 ;
V_490 -> V_495 = V_492 -> V_495 ;
F_52 ( V_2 , 2 , L_219 , V_490 -> V_494 ,
V_490 -> V_495 ) ;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_491 ( struct V_1 * V_2 ,
struct V_489 * V_490 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_220 ) ;
if ( ! F_282 ( V_2 , V_496 ) )
return - V_339 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_497 ;
V_113 = F_277 ( V_2 , V_496 ,
sizeof( struct V_498 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_273 ( V_2 , V_113 ,
F_281 , V_490 ) ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_184 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_221 , V_37 ) ;
else
V_2 -> V_12 . V_499 = V_130 -> V_117 . V_500 . V_501 ;
return 0 ;
}
static int F_284 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_222 ) ;
V_113 = F_269 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_500 . V_502 = 16 ;
V_130 -> V_117 . V_500 . V_503 = V_504 ;
return F_273 ( V_2 , V_113 , F_283 , NULL ) ;
}
static void F_285 ( struct V_1 * V_2 , struct V_505 * V_506 )
{
unsigned long V_12 = F_286 ( V_49 ) ;
struct V_507 * V_508 = (struct V_507 * ) V_12 ;
struct V_509 * V_510 = (struct V_509 * ) V_12 ;
struct V_362 V_511 ;
int V_372 ;
V_506 -> V_142 = V_2 -> V_12 . V_142 ;
F_178 ( F_152 ( V_2 ) , & V_511 ) ;
V_506 -> V_512 = V_511 . V_512 ;
V_506 -> V_370 = V_511 . V_370 ;
if ( ! V_12 )
return;
V_372 = F_287 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_372 >= 2 ) && ( F_287 ( V_508 , 2 , 2 , 2 ) == 0 ) )
V_506 -> V_513 = V_508 -> V_514 ;
if ( ( V_372 >= 3 ) && ( F_287 ( V_510 , 3 , 2 , 2 ) == 0 ) ) {
F_288 ( V_510 -> V_515 [ 0 ] . V_516 , sizeof( V_510 -> V_515 [ 0 ] . V_516 ) ) ;
memcpy ( V_506 -> V_517 , V_510 -> V_515 [ 0 ] . V_516 , sizeof( V_506 -> V_517 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_289 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_184 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_223 , V_37 ) ;
return 0 ;
}
int F_290 ( struct V_1 * V_2 , enum V_518 V_519 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_224 ) ;
V_113 = F_269 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_500 . V_502 = 80 ;
V_130 -> V_117 . V_500 . V_503 = V_520 ;
V_130 -> V_117 . V_500 . type = 1 ;
V_130 -> V_117 . V_500 . V_519 = V_519 ;
switch ( V_519 ) {
case V_521 :
V_130 -> V_117 . V_500 . V_66 = 0x0003 ;
V_130 -> V_117 . V_500 . V_501 = 0x00010000 +
sizeof( struct V_505 ) ;
F_285 ( V_2 ,
(struct V_505 * ) V_130 -> V_117 . V_500 . V_522 ) ;
break;
case V_523 :
V_130 -> V_117 . V_500 . V_66 = 0x0001 ;
break;
case V_524 :
break;
}
return F_273 ( V_2 , V_113 , F_289 , NULL ) ;
}
int F_291 ( struct V_1 * V_2 , struct V_525 * V_230 ,
unsigned int V_526 , const char * V_527 )
{
if ( V_526 ) {
F_4 ( V_2 , 2 , V_527 ) ;
F_52 ( V_2 , 2 , L_225 ,
V_230 -> V_244 [ 15 ] . V_245 ) ;
F_52 ( V_2 , 2 , L_226 ,
V_230 -> V_244 [ 14 ] . V_245 ) ;
F_52 ( V_2 , 2 , L_227 , V_526 ) ;
if ( ( V_230 -> V_244 [ 15 ] . V_245 ) == 0x12 ) {
V_2 -> V_528 . V_529 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static void V_295 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_294 . V_7 ) ;
F_52 ( V_2 , 2 , L_228 , V_2 -> V_530 ) ;
F_292 ( V_2 , V_2 -> V_530 ) ;
}
void F_292 ( struct V_1 * V_2 , int V_168 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_424 ;
struct V_302 * V_531 ;
int V_166 ;
int V_44 ;
int V_37 ;
int V_532 = 0 ;
V_166 = ( V_168 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_168 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_168 ) ;
if ( V_166 >= F_293 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_166 ; ++ V_44 ) {
if ( F_264 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_532 ++ ;
}
}
if ( V_532 < V_166 ) {
F_60 ( & V_2 -> V_533 , 3 ) ;
V_166 = V_532 ;
} else {
F_294 ( & V_2 -> V_533 , - 1 , 0 ) ;
}
if ( ! V_166 ) {
V_44 = 0 ;
F_258 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_229 ) ;
V_2 -> V_530 = V_168 ;
F_295 (
& V_2 -> V_294 ,
V_534 ) ;
}
return;
}
if ( V_2 -> V_66 . V_272 ) {
V_2 -> V_442 . V_535 ++ ;
V_2 -> V_442 . V_536 =
F_296 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_166 ) ;
if ( V_2 -> V_66 . V_272 )
V_2 -> V_442 . V_537 +=
F_296 () -
V_2 -> V_442 . V_536 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_230 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_166 ) %
V_62 ;
}
}
static int F_297 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_538 )
{
int V_83 = V_64 -> V_64 -> V_244 [ 15 ] . V_245 ;
F_4 ( V_2 , 6 , L_231 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_538 = 0 ;
} else {
V_538 = 1 ;
}
}
F_291 ( V_2 , V_64 -> V_64 , V_538 , L_232 ) ;
if ( ! V_538 )
return V_539 ;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return V_540 ;
F_4 ( V_2 , 1 , L_233 ) ;
F_52 ( V_2 , 1 , L_234 ,
( V_185 ) V_538 , ( V_278 ) V_83 ) ;
return V_541 ;
}
static void F_298 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_449 ) {
if ( F_51 ( & V_111 -> V_450 )
>= V_542 ) {
F_4 ( V_111 -> V_2 , 6 , L_235 ) ;
if ( V_111 -> V_2 -> V_66 . V_272 )
V_111 -> V_2 -> V_442 . V_543 ++ ;
V_111 -> V_449 = 1 ;
}
}
}
static int F_299 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
int V_544 = 0 ;
if ( V_111 -> V_449 ) {
if ( F_51 ( & V_111 -> V_450 )
<= V_545 ) {
F_4 ( V_111 -> V_2 , 6 , L_236 ) ;
if ( V_111 -> V_2 -> V_66 . V_272 )
V_111 -> V_2 -> V_442 . V_546 ++ ;
V_111 -> V_449 = 0 ;
V_64 = V_111 -> V_63 [ V_111 -> V_448 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) ==
V_248 ) &&
( V_64 -> V_254 > 0 ) ) {
F_60 ( & V_64 -> V_3 ,
V_107 ) ;
V_544 ++ ;
V_111 -> V_448 =
( V_111 -> V_448 + 1 ) %
V_62 ;
}
}
}
return V_544 ;
}
static int F_300 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_448 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_248 ) &&
( V_64 -> V_254 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_448 =
( V_111 -> V_448 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_301 ( struct V_92 * V_111 , int V_168 ,
int V_166 )
{
struct V_96 * V_230 ;
int V_37 ;
int V_44 ;
unsigned int V_547 ;
for ( V_44 = V_168 ; V_44 < V_168 + V_166 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_230 = V_111 -> V_63 [ V_93 ] ;
V_230 -> V_64 -> V_244 [ V_230 -> V_254 - 1 ] . V_253 |=
V_447 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_423 = V_230 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_449 ) {
if ( ( F_51 ( & V_111 -> V_450 ) >=
( V_542 -
V_548 ) ) &&
! F_51 ( & V_111 -> V_247 ) ) {
F_76 ( & V_111 -> V_247 ) ;
V_230 -> V_64 -> V_244 [ 0 ] . V_245 |= V_246 ;
}
} else {
if ( ! F_51 ( & V_111 -> V_247 ) ) {
F_76 ( & V_111 -> V_247 ) ;
V_230 -> V_64 -> V_244 [ 0 ] . V_245 |= V_246 ;
}
}
}
V_111 -> V_2 -> V_9 -> V_549 = V_389 ;
if ( V_111 -> V_2 -> V_66 . V_272 ) {
V_111 -> V_2 -> V_442 . V_550 ++ ;
V_111 -> V_2 -> V_442 . V_551 =
F_296 () ;
}
V_547 = V_552 ;
if ( F_51 ( & V_111 -> V_247 ) )
V_547 |= V_553 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_547 ,
V_111 -> V_429 , V_168 , V_166 ) ;
if ( V_111 -> V_2 -> V_66 . V_272 )
V_111 -> V_2 -> V_442 . V_554 +=
F_296 () -
V_111 -> V_2 -> V_442 . V_551 ;
F_302 ( V_166 , & V_111 -> V_450 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_528 . V_555 += V_166 ;
if ( V_37 == - V_556 )
return;
F_4 ( V_111 -> V_2 , 2 , L_237 ) ;
F_52 ( V_111 -> V_2 , 2 , L_238 , V_111 -> V_429 ) ;
F_52 ( V_111 -> V_2 , 2 , L_239 , V_168 ) ;
F_52 ( V_111 -> V_2 , 2 , L_240 , V_166 ) ;
F_52 ( V_111 -> V_2 , 2 , L_165 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_272 )
V_111 -> V_2 -> V_442 . V_557 += V_166 ;
}
static void F_303 ( struct V_92 * V_111 )
{
int V_168 ;
int V_558 = 0 ;
int V_559 = 0 ;
if ( ( F_51 ( & V_111 -> V_450 ) <= V_545 ) ||
! F_51 ( & V_111 -> V_247 ) ) {
if ( F_235 ( & V_111 -> V_3 , V_560 ) ==
V_451 ) {
F_304 ( V_111 -> V_2 -> V_9 ) ;
V_168 = V_111 -> V_448 ;
V_559 = V_111 -> V_449 ;
F_305 () ;
V_558 += F_299 ( V_111 ) ;
if ( ! V_558 &&
! F_51 ( & V_111 -> V_247 ) )
V_558 +=
F_300 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_272 &&
V_559 )
V_111 -> V_2 -> V_442 . V_561 +=
V_558 ;
if ( V_558 )
F_301 ( V_111 , V_168 , V_558 ) ;
F_60 ( & V_111 -> V_3 , V_451 ) ;
}
}
}
void F_306 ( struct V_157 * V_119 , int V_111 ,
unsigned long V_562 )
{
struct V_1 * V_2 = (struct V_1 * ) V_562 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_563 ) )
F_307 ( & V_2 -> V_564 ) ;
}
int F_308 ( struct V_1 * V_2 , enum V_565 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_566 ) {
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
F_132 ( V_2 ) ;
V_2 -> V_66 . V_67 = V_67 ;
V_37 = 0 ;
}
V_73:
return V_37 ;
}
static void F_309 ( struct V_1 * V_2 ,
unsigned int V_538 ,
unsigned int V_111 , int V_567 , int V_166 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_241 , V_567 ) ;
F_52 ( V_2 , 5 , L_242 , V_166 ) ;
F_52 ( V_2 , 5 , L_243 , V_538 ) ;
if ( V_538 ) {
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_272 ) {
V_2 -> V_442 . V_568 ++ ;
V_2 -> V_442 . V_569 = F_296 () ;
}
for ( V_44 = V_567 ; V_44 < V_567 + V_166 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_525 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_570 ;
V_570 = 0 ;
while ( V_64 -> V_244 [ V_570 ] . V_249 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_244 [ V_570 ] . V_249 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_244 [ V_570 ] . V_249 = NULL ;
V_64 -> V_244 [ V_570 ] . V_253 = 0 ;
V_64 -> V_244 [ V_570 ] . V_245 = 0 ;
V_64 -> V_244 [ V_570 ] . V_252 = 0 ;
++ V_570 ;
}
V_64 -> V_244 [ 15 ] . V_253 = 0 ;
V_64 -> V_244 [ 15 ] . V_245 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_166 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_244 , V_37 ) ;
F_4 ( V_2 , 2 , L_245 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_166 ) % V_62 ;
F_310 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_272 ) {
int V_571 = F_296 () ;
V_571 -= V_2 -> V_442 . V_569 ;
V_2 -> V_442 . V_572 += V_571 ;
}
V_73:
return;
}
void F_311 ( struct V_157 * V_119 , unsigned int V_538 ,
unsigned int V_111 , int V_573 , int V_166 ,
unsigned long V_562 )
{
struct V_1 * V_2 = (struct V_1 * ) V_562 ;
F_52 ( V_2 , 2 , L_246 , V_111 ) ;
F_52 ( V_2 , 2 , L_247 , V_538 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_309 ( V_2 , V_538 , V_111 , V_573 , V_166 ) ;
else if ( V_538 )
F_72 ( V_2 ) ;
}
void F_312 ( struct V_157 * V_119 ,
unsigned int V_526 , int V_574 , int V_567 ,
int V_166 , unsigned long V_562 )
{
struct V_1 * V_2 = (struct V_1 * ) V_562 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_574 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_248 ) ;
if ( V_526 & V_575 ) {
F_4 ( V_2 , 2 , L_249 ) ;
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_272 ) {
V_2 -> V_442 . V_576 ++ ;
V_2 -> V_442 . V_577 =
F_296 () ;
}
for ( V_44 = V_567 ; V_44 < ( V_567 + V_166 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_297 ( V_2 , V_64 , V_526 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_578 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_579 ) ;
}
V_64 -> V_102 = V_111 -> V_81 [ V_93 ] . V_102 ;
F_52 ( V_111 -> V_2 , 5 , L_250 , V_93 ) ;
F_4 ( V_111 -> V_2 , 5 , L_251 ) ;
F_52 ( V_111 -> V_2 , 5 , L_43 ,
F_313 ( V_64 -> V_102 ) ) ;
if ( F_56 ( V_111 , V_93 ) ) {
F_4 ( V_2 , 2 , L_252 ) ;
F_72 ( V_2 ) ;
}
} else {
if ( V_2 -> V_66 . V_67 == V_68 ) {
enum V_82 V_85 ;
V_85 = F_49 (
V_64 -> V_64 -> V_244 [ 15 ] . V_245 , 0 ) ;
F_61 ( V_111 , V_64 , V_85 ) ;
}
F_62 ( V_111 , V_64 ,
V_248 ) ;
}
F_50 ( V_111 , V_93 , 0 ) ;
}
F_314 ( V_166 , & V_111 -> V_450 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_303 ( V_111 ) ;
F_310 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_272 )
V_2 -> V_442 . V_580 += F_296 () -
V_2 -> V_442 . V_577 ;
}
int F_315 ( struct V_1 * V_2 , struct V_231 * V_232 ,
int V_581 , int V_582 )
{
T_3 * V_583 ;
V_278 V_584 ;
if ( V_582 && V_2 -> V_12 . V_318 )
return V_2 -> V_12 . V_318 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_308 ) {
case V_585 :
case V_586 :
switch ( V_581 ) {
case 4 :
V_584 = F_316 ( F_317 ( V_232 ) ) ;
break;
case 6 :
V_584 = F_318 ( F_319 ( V_232 ) ) ;
break;
default:
return V_2 -> V_46 . V_256 ;
}
if ( V_2 -> V_46 . V_308 == V_586 )
return ~ V_584 >> 6 & 3 ;
if ( V_584 & V_587 )
return 3 ;
if ( V_584 & V_588 )
return 2 ;
if ( V_584 & V_589 )
return 1 ;
if ( V_584 & V_590 )
return 0 ;
break;
case V_591 :
if ( V_232 -> V_592 > 5 )
return 0 ;
return ~ V_232 -> V_592 >> 1 & 3 ;
case V_593 :
V_583 = & ( (struct V_594 * ) V_232 -> V_117 ) -> V_595 ;
if ( * V_583 == V_596 )
return ~ * ( V_583 + 1 ) >> ( V_597 + 1 ) & 3 ;
break;
default:
break;
}
return V_2 -> V_46 . V_256 ;
}
int F_320 ( struct V_231 * V_232 )
{
int V_176 , V_252 , V_570 , V_51 = 0 ;
struct V_598 * V_599 ;
char * V_117 ;
for ( V_176 = 0 ; V_176 < F_321 ( V_232 ) -> V_600 ; V_176 ++ ) {
V_599 = & F_321 ( V_232 ) -> V_601 [ V_176 ] ;
V_117 = ( char * ) F_322 ( F_323 ( V_599 ) ) +
V_599 -> V_602 ;
V_252 = V_599 -> V_603 ;
V_570 = F_324 ( ( unsigned long ) V_117 + V_252 - 1 ) -
F_325 ( ( unsigned long ) V_117 ) ;
V_51 += V_570 ;
}
return V_51 ;
}
int F_326 ( struct V_1 * V_2 ,
struct V_231 * V_232 , int V_604 )
{
int V_605 = V_232 -> V_162 - V_232 -> V_606 ;
int V_607 = F_324 ( ( unsigned long ) V_232 -> V_117 + V_605 - 1 ) -
F_325 ( ( unsigned long ) V_232 -> V_117 ) ;
V_607 += F_320 ( V_232 ) ;
if ( ( V_607 + V_604 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_253
L_254 ,
( V_607 + V_604 ) , V_232 -> V_162 ) ;
return 0 ;
}
return V_607 ;
}
int F_327 ( struct V_231 * V_232 , struct V_608 * * V_133 , int V_162 )
{
int V_609 , V_610 , V_611 ;
if ( ( ( unsigned long ) V_232 -> V_117 & V_612 ) !=
( ( ( unsigned long ) V_232 -> V_117 + V_162 - 1 ) & V_612 ) ) {
V_609 = F_328 ( V_232 ) ;
V_610 = V_407 - ( ( unsigned long ) V_232 -> V_117 % V_407 ) ;
V_611 = V_162 - V_610 ;
if ( V_611 > V_609 )
return 1 ;
memmove ( V_232 -> V_117 - V_611 , V_232 -> V_117 , V_232 -> V_162 - V_232 -> V_606 ) ;
V_232 -> V_117 -= V_611 ;
V_232 -> V_613 -= V_611 ;
* V_133 = (struct V_608 * ) V_232 -> V_117 ;
F_68 ( 2 , L_255 , V_162 , V_611 ) ;
}
return 0 ;
}
static inline void F_329 ( struct V_231 * V_232 ,
struct V_525 * V_64 , int V_614 , int * V_254 ,
int V_183 )
{
int V_252 = V_232 -> V_162 - V_232 -> V_606 ;
int V_615 ;
int V_244 ;
char * V_117 ;
int V_616 , V_176 ;
struct V_598 * V_599 ;
V_244 = * V_254 ;
V_117 = V_232 -> V_117 ;
V_616 = ( V_614 == 0 ? 1 : 0 ) ;
if ( V_183 >= 0 ) {
V_117 = V_232 -> V_117 + V_183 ;
V_252 -= V_183 ;
V_616 = 0 ;
}
while ( V_252 > 0 ) {
V_615 = V_407 - ( ( unsigned long ) V_117 % V_407 ) ;
if ( V_252 < V_615 )
V_615 = V_252 ;
V_64 -> V_244 [ V_244 ] . V_249 = V_117 ;
V_64 -> V_244 [ V_244 ] . V_252 = V_615 ;
V_252 -= V_615 ;
if ( ! V_252 ) {
if ( V_616 )
if ( F_321 ( V_232 ) -> V_600 )
V_64 -> V_244 [ V_244 ] . V_253 =
V_617 ;
else
V_64 -> V_244 [ V_244 ] . V_253 = 0 ;
else
V_64 -> V_244 [ V_244 ] . V_253 =
V_618 ;
} else {
if ( V_616 )
V_64 -> V_244 [ V_244 ] . V_253 =
V_617 ;
else
V_64 -> V_244 [ V_244 ] . V_253 =
V_618 ;
}
V_117 += V_615 ;
V_244 ++ ;
V_616 = 0 ;
}
for ( V_176 = 0 ; V_176 < F_321 ( V_232 ) -> V_600 ; V_176 ++ ) {
V_599 = & F_321 ( V_232 ) -> V_601 [ V_176 ] ;
V_117 = ( char * ) F_322 ( F_323 ( V_599 ) ) +
V_599 -> V_602 ;
V_252 = V_599 -> V_603 ;
while ( V_252 > 0 ) {
V_615 = V_407 -
( ( unsigned long ) V_117 % V_407 ) ;
if ( V_252 < V_615 )
V_615 = V_252 ;
V_64 -> V_244 [ V_244 ] . V_249 = V_117 ;
V_64 -> V_244 [ V_244 ] . V_252 = V_615 ;
V_64 -> V_244 [ V_244 ] . V_253 =
V_618 ;
V_252 -= V_615 ;
V_117 += V_615 ;
V_244 ++ ;
}
}
if ( V_64 -> V_244 [ V_244 - 1 ] . V_253 )
V_64 -> V_244 [ V_244 - 1 ] . V_253 = V_619 ;
* V_254 = V_244 ;
}
static inline int F_330 ( struct V_92 * V_111 ,
struct V_96 * V_230 , struct V_231 * V_232 ,
struct V_608 * V_133 , int V_183 , int V_620 )
{
struct V_525 * V_64 ;
int V_558 = 0 , V_621 , V_622 = 0 ;
V_64 = V_230 -> V_64 ;
F_76 ( & V_232 -> V_241 ) ;
F_331 ( & V_230 -> V_233 , V_232 ) ;
if ( V_133 -> V_133 . V_623 . V_313 == V_624 ) {
int V_244 = V_230 -> V_254 ;
V_621 = sizeof( struct V_625 ) +
( (struct V_625 * ) V_133 ) -> V_501 . V_626 ;
V_64 -> V_244 [ V_244 ] . V_249 = V_232 -> V_117 ;
V_64 -> V_244 [ V_244 ] . V_252 = V_621 ;
V_64 -> V_244 [ V_244 ] . V_253 = V_617 ;
V_230 -> V_254 ++ ;
V_232 -> V_117 += V_621 ;
V_232 -> V_162 -= V_621 ;
V_622 = 1 ;
}
if ( V_183 >= 0 ) {
int V_244 = V_230 -> V_254 ;
V_64 -> V_244 [ V_244 ] . V_249 = V_133 ;
V_64 -> V_244 [ V_244 ] . V_252 = sizeof( struct V_608 ) +
V_620 ;
V_64 -> V_244 [ V_244 ] . V_253 = V_617 ;
V_230 -> V_250 [ V_244 ] = 1 ;
V_230 -> V_254 ++ ;
}
F_329 ( V_232 , V_64 , V_622 ,
( int * ) & V_230 -> V_254 , V_183 ) ;
if ( ! V_111 -> V_449 ) {
F_4 ( V_111 -> V_2 , 6 , L_256 ) ;
F_60 ( & V_230 -> V_3 , V_107 ) ;
V_558 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_257 ) ;
if ( V_111 -> V_2 -> V_66 . V_272 )
V_111 -> V_2 -> V_442 . V_627 ++ ;
if ( V_230 -> V_254 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_230 -> V_3 , V_107 ) ;
V_558 = 1 ;
}
}
return V_558 ;
}
int F_332 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_231 * V_232 ,
struct V_608 * V_133 , int V_607 ,
int V_183 , int V_620 )
{
struct V_96 * V_64 ;
int V_168 ;
while ( F_59 ( & V_111 -> V_3 , V_451 ,
V_628 ) != V_451 ) ;
V_168 = V_111 -> V_448 ;
V_64 = V_111 -> V_63 [ V_111 -> V_448 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_248 )
goto V_73;
V_111 -> V_448 = ( V_111 -> V_448 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_451 ) ;
F_330 ( V_111 , V_64 , V_232 , V_133 , V_183 , V_620 ) ;
F_301 ( V_111 , V_168 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_451 ) ;
return - V_629 ;
}
int F_333 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_231 * V_232 , struct V_608 * V_133 ,
int V_607 )
{
struct V_96 * V_64 ;
int V_630 ;
int V_544 = 0 ;
int V_449 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_451 ,
V_628 ) != V_451 ) ;
V_630 = V_111 -> V_448 ;
V_64 = V_111 -> V_63 [ V_111 -> V_448 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_248 ) {
F_60 ( & V_111 -> V_3 , V_451 ) ;
return - V_629 ;
}
F_298 ( V_111 ) ;
if ( V_111 -> V_449 ) {
V_449 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_254 ) < V_607 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_544 ++ ;
V_111 -> V_448 =
( V_111 -> V_448 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_448 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_248 ) {
F_301 ( V_111 , V_630 ,
V_544 ) ;
F_60 ( & V_111 -> V_3 ,
V_451 ) ;
return - V_629 ;
}
}
}
V_41 = F_330 ( V_111 , V_64 , V_232 , V_133 , - 1 , 0 ) ;
V_111 -> V_448 = ( V_111 -> V_448 + V_41 ) %
V_62 ;
V_544 += V_41 ;
if ( V_544 )
F_301 ( V_111 , V_630 , V_544 ) ;
else if ( ! F_51 ( & V_111 -> V_247 ) )
F_235 ( & V_111 -> V_3 , V_560 ) ;
while ( F_334 ( & V_111 -> V_3 ) ) {
V_544 = 0 ;
V_630 = V_111 -> V_448 ;
V_544 += F_299 ( V_111 ) ;
if ( ! V_544 && ! F_51 ( & V_111 -> V_247 ) )
V_544 += F_300 ( V_111 ) ;
if ( V_544 )
F_301 ( V_111 , V_630 , V_544 ) ;
}
if ( V_111 -> V_2 -> V_66 . V_272 && V_449 )
V_111 -> V_2 -> V_442 . V_561 += V_544 ;
return V_37 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_480 * V_631 ;
F_4 ( V_2 , 4 , L_258 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_631 = & ( V_130 -> V_117 . V_467 ) ;
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_259 , V_130 -> V_133 . V_139 ) ;
V_631 -> V_117 . V_632 = V_633 ;
}
V_2 -> V_12 . V_634 = V_631 -> V_117 . V_632 ;
return 0 ;
}
void F_336 ( struct V_1 * V_2 )
{
enum V_635 V_632 ;
struct V_636 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_260 ) ;
if ( ( ( V_9 -> V_32 & V_637 ) &&
( V_2 -> V_12 . V_634 == V_638 ) ) ||
( ! ( V_9 -> V_32 & V_637 ) &&
( V_2 -> V_12 . V_634 == V_633 ) ) )
return;
V_632 = V_633 ;
if ( V_9 -> V_32 & V_637 )
V_632 = V_638 ;
F_52 ( V_2 , 4 , L_261 , V_632 ) ;
V_113 = F_277 ( V_2 , V_639 ,
sizeof( struct V_498 ) + 8 ) ;
if ( ! V_113 )
return;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_467 . V_117 . V_632 = V_632 ;
F_273 ( V_2 , V_113 , F_335 , NULL ) ;
}
int F_337 ( struct V_636 * V_9 , int V_640 )
{
struct V_1 * V_2 ;
char V_436 [ 15 ] ;
V_2 = V_9 -> V_641 ;
F_4 ( V_2 , 4 , L_262 ) ;
sprintf ( V_436 , L_263 , V_640 ) ;
F_4 ( V_2 , 4 , V_436 ) ;
if ( V_640 < 64 )
return - V_405 ;
if ( V_640 > 65535 )
return - V_405 ;
if ( ( ! F_338 ( V_2 , V_642 ) ) &&
( ! F_208 ( V_2 , V_640 ) ) )
return - V_405 ;
V_9 -> V_403 = V_640 ;
return 0 ;
}
struct V_643 * F_339 ( struct V_636 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_641 ;
F_4 ( V_2 , 5 , L_264 ) ;
return & V_2 -> V_528 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_265 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_306 ||
! ( V_2 -> V_12 . V_644 & V_645 ) ) {
memcpy ( V_2 -> V_9 -> V_646 ,
& V_130 -> V_117 . V_467 . V_117 . V_647 . V_249 ,
V_648 ) ;
V_2 -> V_12 . V_644 |= V_645 ;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int F_341 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_266 ) ;
V_113 = F_277 ( V_2 , V_649 ,
sizeof( struct V_498 ) +
sizeof( struct V_650 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_467 . V_117 . V_647 . V_130 = V_651 ;
V_130 -> V_117 . V_467 . V_117 . V_647 . V_652 = V_648 ;
memcpy ( & V_130 -> V_117 . V_467 . V_117 . V_647 . V_249 ,
V_2 -> V_9 -> V_646 , V_648 ) ;
V_37 = F_273 ( V_2 , V_113 , F_340 ,
NULL ) ;
return V_37 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_653 * V_654 ;
int V_655 = * ( int * ) V_125 -> V_386 ;
F_4 ( V_2 , 4 , L_267 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_654 = & V_130 -> V_117 . V_467 . V_117 . V_656 ;
F_45 ( V_65 , 2 , L_267 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_657 . V_516 ) ;
F_45 ( V_65 , 2 , L_268 ,
V_130 -> V_117 . V_467 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_467 . V_133 . V_139 !=
V_658 )
F_68 ( 3 , L_269 ,
V_2 -> V_10 -> V_9 . V_657 . V_516 ,
V_654 -> V_659 ,
V_130 -> V_117 . V_467 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_467 . V_133 . V_139 ) {
case V_658 :
if ( V_2 -> V_66 . V_275 == V_276 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_270 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_271 ) ;
}
break;
case V_660 :
F_68 ( 2 , L_272
L_273 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_662 :
F_68 ( 2 , L_274
L_275 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_663 :
F_47 ( & V_2 -> V_10 -> V_9 , L_276
L_277 ) ;
break;
case V_664 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_278
L_279 ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_665 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_280 ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_666 :
F_47 ( & V_2 -> V_10 -> V_9 , L_281
L_282 ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_667 :
F_47 ( & V_2 -> V_10 -> V_9 , L_283
L_284 ) ;
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
case V_668 :
F_67 ( & V_2 -> V_10 -> V_9 , L_285
L_286 ) ;
break;
default:
if ( V_655 )
V_2 -> V_66 . V_275 = V_2 -> V_66 . V_661 ;
break;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_343 ( struct V_1 * V_2 ,
enum V_669 V_275 , int V_655 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_653 * V_654 ;
F_4 ( V_2 , 4 , L_287 ) ;
F_45 ( V_65 , 2 , L_287 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_657 . V_516 ) ;
V_113 = F_277 ( V_2 , V_670 ,
sizeof( struct V_498 ) +
sizeof( struct V_653 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_654 = & V_130 -> V_117 . V_467 . V_117 . V_656 ;
V_654 -> V_659 = V_275 ;
V_37 = F_273 ( V_2 , V_113 , F_342 ,
& V_655 ) ;
F_45 ( V_65 , 2 , L_268 , V_37 ) ;
return V_37 ;
}
int F_344 ( struct V_1 * V_2 , int V_655 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_288 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_282 ( V_2 , V_670 ) ) {
V_37 = F_343 ( V_2 ,
V_2 -> V_66 . V_275 , V_655 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_289 ,
V_2 -> V_10 -> V_9 . V_657 . V_516 ,
V_37 ) ;
V_37 = - V_339 ;
}
} else if ( V_2 -> V_66 . V_275 != V_276 ) {
V_2 -> V_66 . V_275 = V_276 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_276
L_277 ) ;
V_37 = - V_339 ;
}
return V_37 ;
}
void F_345 ( struct V_636 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_641 ;
F_4 ( V_2 , 4 , L_290 ) ;
V_2 -> V_528 . V_555 ++ ;
F_72 ( V_2 ) ;
}
int F_346 ( struct V_636 * V_9 , int V_671 , int V_672 )
{
struct V_1 * V_2 = V_9 -> V_641 ;
int V_37 = 0 ;
switch ( V_672 ) {
case V_673 :
V_37 = V_674 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_675 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_676 ;
break;
case V_677 :
V_37 = V_678 | V_679 | V_680 |
V_681 | V_682 | V_683 | V_684 |
V_685 ;
break;
case V_686 :
V_37 = ( V_9 -> V_646 [ 0 ] << 16 ) | ( V_9 -> V_646 [ 1 ] << 8 ) |
V_9 -> V_646 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_687 :
V_37 = ( V_9 -> V_646 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_688 :
V_37 = V_689 ;
break;
case V_690 :
V_37 = V_691 | V_692 | V_693 | V_694 |
V_695 | V_696 ;
break;
case V_697 :
break;
case V_698 :
break;
case V_699 :
break;
case V_700 :
break;
case V_701 :
V_37 = V_2 -> V_528 . V_702 ;
break;
case V_703 :
break;
case V_704 :
break;
case V_705 :
break;
case V_706 :
break;
case V_707 :
break;
case V_708 :
break;
case V_709 :
break;
default:
break;
}
return V_37 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_162 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_383 )
{
V_185 V_710 , V_711 ;
F_4 ( V_2 , 4 , L_291 ) ;
memcpy ( V_113 -> V_117 , V_465 , V_390 ) ;
memcpy ( F_272 ( V_113 -> V_117 ) ,
& V_2 -> V_353 . V_416 , V_369 ) ;
V_710 = ( V_712 ) V_390 + V_162 ;
V_711 = ( V_712 ) V_162 ;
memcpy ( F_348 ( V_113 -> V_117 ) , & V_710 , 2 ) ;
memcpy ( F_349 ( V_113 -> V_117 ) , & V_711 , 2 ) ;
memcpy ( F_350 ( V_113 -> V_117 ) , & V_711 , 2 ) ;
memcpy ( F_351 ( V_113 -> V_117 ) , & V_711 , 2 ) ;
return F_190 ( V_2 , V_390 + V_162 , V_113 ,
F_191 , V_383 ) ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_713 )
{
struct V_129 * V_130 ;
struct V_714 * V_715 ;
struct V_716 * V_717 ;
unsigned char * V_117 ;
V_184 V_606 ;
F_4 ( V_2 , 3 , L_292 ) ;
V_130 = (struct V_129 * ) V_713 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_183 ) ;
V_715 = (struct V_714 * ) V_125 -> V_386 ;
V_717 = & V_130 -> V_117 . V_467 . V_117 . V_717 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_293 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_467 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_467 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_294 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_606 = * ( ( V_184 * ) F_349 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_467 . V_133 . V_478 == 1 )
V_606 -= ( V_184 ) ( ( char * ) & V_717 -> V_117 - ( char * ) V_130 ) ;
else
V_606 -= ( V_184 ) ( ( char * ) & V_717 -> V_718 - ( char * ) V_130 ) ;
if ( ( V_715 -> V_719 - V_715 -> V_720 ) < V_606 ) {
F_52 ( V_2 , 4 , L_295 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_721 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_296 ,
V_130 -> V_117 . V_467 . V_133 . V_477 ) ;
F_52 ( V_2 , 4 , L_297 ,
V_130 -> V_117 . V_467 . V_133 . V_478 ) ;
if ( V_130 -> V_117 . V_467 . V_133 . V_478 == 1 ) {
memcpy ( V_715 -> V_722 + V_715 -> V_720 ,
( char * ) V_717 ,
V_606 + F_353 ( struct V_716 , V_117 ) ) ;
V_715 -> V_720 += F_353 ( struct V_716 , V_117 ) ;
} else {
memcpy ( V_715 -> V_722 + V_715 -> V_720 ,
( char * ) & V_717 -> V_718 , V_606 ) ;
}
V_715 -> V_720 += V_606 ;
F_52 ( V_2 , 4 , L_298 ,
V_130 -> V_117 . V_467 . V_133 . V_477 ) ;
F_52 ( V_2 , 4 , L_299 ,
V_130 -> V_117 . V_467 . V_133 . V_478 ) ;
if ( V_130 -> V_117 . V_467 . V_133 . V_478 <
V_130 -> V_117 . V_467 . V_133 . V_477 )
return 1 ;
return 0 ;
}
int F_354 ( struct V_1 * V_2 , char T_4 * V_722 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_723 * V_724 ;
unsigned int V_725 ;
struct V_714 V_715 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_300 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_339 ;
if ( ( ! F_282 ( V_2 , V_726 ) ) &&
( ! V_2 -> V_66 . V_306 ) ) {
return - V_339 ;
}
if ( F_355 ( & V_725 , V_722 + sizeof( int ) , sizeof( int ) ) )
return - V_727 ;
if ( V_725 > ( V_118 - V_390 -
sizeof( struct V_728 ) -
sizeof( struct V_498 ) ) )
return - V_405 ;
V_724 = F_356 ( V_722 , V_725 + sizeof( struct V_729 ) ) ;
if ( F_116 ( V_724 ) ) {
F_4 ( V_2 , 2 , L_301 ) ;
return F_117 ( V_724 ) ;
}
V_715 . V_719 = V_724 -> V_133 . V_606 ;
V_715 . V_722 = F_27 ( V_715 . V_719 , V_49 ) ;
if ( ! V_715 . V_722 ) {
F_32 ( V_724 ) ;
return - V_50 ;
}
V_715 . V_720 = sizeof( struct V_729 ) ;
V_113 = F_277 ( V_2 , V_726 ,
V_730 + V_725 ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_73;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
memcpy ( & V_130 -> V_117 . V_467 . V_117 . V_717 , & V_724 -> V_130 , V_725 ) ;
V_37 = F_347 ( V_2 , V_113 , V_731 + V_725 ,
F_352 , ( void * ) & V_715 ) ;
if ( V_37 )
F_68 ( 2 , L_302 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_357 ( V_722 , V_715 . V_722 , V_715 . V_719 ) )
V_37 = - V_727 ;
}
V_73:
F_32 ( V_724 ) ;
F_32 ( V_715 . V_722 ) ;
return V_37 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_732 * V_733 ;
char * V_734 ;
int V_735 ;
F_4 ( V_2 , 3 , L_303 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_733 = (struct V_732 * ) V_125 -> V_386 ;
V_735 = V_130 -> V_117 . V_467 . V_133 . V_475 ;
V_734 = ( char * ) V_117 + 28 ;
if ( V_735 > ( V_733 -> V_736 - V_733 -> V_737 ) ) {
V_130 -> V_133 . V_139 = V_738 ;
return 0 ;
}
memcpy ( ( V_733 -> V_64 + V_733 -> V_737 ) , V_734 ,
V_735 ) ;
V_733 -> V_737 += V_735 ;
if ( V_130 -> V_117 . V_467 . V_133 . V_478 <
V_130 -> V_117 . V_467 . V_133 . V_477 )
return 1 ;
return 0 ;
}
int F_359 ( struct V_1 * V_2 , char T_4 * V_722 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_739 * V_740 ;
struct V_741 V_742 ;
struct V_732 V_733 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_304 ) ;
if ( ! F_282 ( V_2 , V_743 ) ) {
V_37 = - V_339 ;
goto V_73;
}
if ( F_355 ( & V_742 , V_722 ,
sizeof( struct V_741 ) ) ) {
V_37 = - V_727 ;
goto V_73;
}
V_733 . V_736 = V_742 . V_736 ;
V_733 . V_737 = 0 ;
V_733 . V_64 = F_27 ( V_742 . V_736 , V_49 ) ;
if ( ! V_733 . V_64 ) {
V_37 = - V_50 ;
goto V_73;
}
V_113 = F_277 ( V_2 , V_743 ,
sizeof( struct V_498 ) +
sizeof( struct V_739 ) ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_744;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_740 = & V_130 -> V_117 . V_467 . V_117 . V_745 ;
V_740 -> V_659 = V_742 . V_134 ;
V_37 = F_273 ( V_2 , V_113 , F_358 ,
& V_733 ) ;
if ( ! V_37 ) {
if ( F_360 () )
V_41 = F_361 ( V_742 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_742 . V_43 ;
if ( F_357 ( V_41 , V_733 . V_64 ,
V_733 . V_737 ) ) {
V_37 = - V_727 ;
goto V_744;
}
V_742 . V_737 = V_733 . V_737 ;
if ( F_357 ( V_722 , & V_742 ,
sizeof( struct V_741 ) ) )
V_37 = - V_727 ;
} else
if ( V_37 == V_738 )
V_37 = - V_727 ;
V_744:
F_32 ( V_733 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_746 * V_747 ;
struct V_748 * V_748 ;
F_4 ( V_2 , 2 , L_305 ) ;
V_748 = (struct V_748 * ) V_125 -> V_386 ;
V_130 = (struct V_129 * ) V_117 ;
V_747 = & V_130 -> V_117 . V_467 . V_117 . V_747 ;
if ( V_130 -> V_117 . V_467 . V_133 . V_139 == 0 ) {
V_748 -> V_749 = V_747 -> V_749 ;
V_748 -> V_750 = V_747 -> V_750 ;
V_748 -> V_751 = V_747 -> V_751 ;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int V_746 ( struct V_1 * V_2 ,
struct V_748 * V_748 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_306 ) ;
if ( ! F_282 ( V_2 , V_752 ) )
return - V_339 ;
V_113 = F_277 ( V_2 , V_752 ,
sizeof( struct V_498 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_273 ( V_2 , V_113 , F_362 ,
( void * ) V_748 ) ;
}
static inline int F_363 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
return 2 ;
default:
return 0 ;
}
}
static void F_364 ( struct V_1 * V_2 )
{
int V_37 ;
int V_252 ;
char * V_345 ;
struct V_157 * V_753 ;
int V_754 = 0 ;
F_41 ( V_65 , 2 , L_307 ) ;
V_753 = F_44 ( V_2 ) ;
if ( ! V_753 -> V_755 ) {
V_754 = 1 ;
V_37 = F_365 ( V_753 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_73;
}
}
V_37 = F_164 ( V_2 , ( void * * ) & V_345 , & V_252 ) ;
if ( V_37 ) {
F_68 ( 2 , L_308 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_756;
}
F_167 ( V_2 , V_345 ) ;
if ( V_754 )
F_168 ( V_2 , V_345 ) ;
F_32 ( V_345 ) ;
V_37 = F_366 ( V_753 , & V_2 -> V_757 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_45 ( V_65 , 2 , L_309 , V_2 -> V_757 . V_758 ) ;
F_45 ( V_65 , 2 , L_310 , V_2 -> V_757 . V_759 ) ;
F_45 ( V_65 , 2 , L_310 , V_2 -> V_757 . V_760 ) ;
F_45 ( V_65 , 2 , L_311 , V_2 -> V_757 . V_761 ) ;
if ( ! ( ( V_2 -> V_757 . V_758 != V_762 ) ||
( ( V_2 -> V_757 . V_759 & V_763 ) == 0 ) ||
( ( V_2 -> V_757 . V_760 & V_764 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_312 ) ;
} else {
V_2 -> V_66 . V_67 = V_566 ;
}
V_756:
if ( V_754 == 1 )
F_367 ( V_753 ) ;
V_73:
return;
}
static inline void F_368 ( struct V_1 * V_2 ,
struct V_525 * * V_765 ,
void (* * F_369) ( struct V_157 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_183 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_765 [ V_183 + V_44 ] = (struct V_525 * )
F_313 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_369 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_248 ( struct V_1 * V_2 )
{
struct V_766 V_767 ;
char * V_768 ;
struct V_525 * * V_765 ;
void (* * F_369) ( struct V_157 * , int , unsigned long );
struct V_525 * * V_769 ;
int V_44 , V_45 , V_770 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_313 ) ;
V_768 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_768 ) {
V_37 = - V_50 ;
goto V_771;
}
F_237 ( V_2 , V_768 ) ;
F_241 ( V_2 , V_768 ) ;
V_765 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_765 ) {
V_37 = - V_50 ;
goto V_772;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_765 [ V_44 ] = (struct V_525 * )
F_313 ( V_2 -> V_46 . V_424 -> V_63 [ V_44 ] . V_64 ) ;
}
F_369 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_369 ) {
V_37 = - V_50 ;
goto V_773;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_369 [ V_44 ] = V_2 -> V_148 -> V_774 ;
F_368 ( V_2 , V_765 , F_369 ) ;
V_769 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_769 ) {
V_37 = - V_50 ;
goto V_775;
}
for ( V_44 = 0 , V_770 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_770 ) {
V_769 [ V_770 ] = (struct V_525 * ) F_313 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_767 , 0 , sizeof( struct V_766 ) ) ;
V_767 . V_158 = F_44 ( V_2 ) ;
V_767 . V_776 = F_363 ( V_2 ) ;
V_767 . V_777 = 0 ;
V_767 . V_768 = V_768 ;
V_767 . V_778 = V_2 -> V_46 . V_72 ;
V_767 . V_779 = V_2 -> V_46 . V_78 ;
V_767 . V_780 = V_2 -> V_148 -> V_780 ;
V_767 . V_781 = V_2 -> V_148 -> V_781 ;
V_767 . V_782 = F_369 ;
V_767 . V_783 = ( unsigned long ) V_2 ;
V_767 . V_784 = ( void * * ) V_765 ;
V_767 . V_785 = ( void * * ) V_769 ;
V_767 . V_786 = V_2 -> V_46 . V_77 ;
V_767 . V_787 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_334 ,
V_330 ) == V_334 ) {
V_37 = F_370 ( & V_767 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_334 ) ;
goto V_73;
}
V_37 = F_371 ( & V_767 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_334 ) ;
F_249 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_314 ) ;
break;
case V_277 :
F_89 ( & V_2 -> V_10 -> V_9 , L_315 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_769 ) ;
V_775:
F_32 ( F_369 ) ;
V_773:
F_32 ( V_765 ) ;
V_772:
F_32 ( V_768 ) ;
V_771:
return V_37 ;
}
static void F_372 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_316 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_130 ( & V_2 -> V_114 ) ;
F_130 ( & V_2 -> V_154 ) ;
if ( V_2 -> V_9 )
F_373 ( V_2 -> V_9 ) ;
F_32 ( V_2 -> V_288 ) ;
F_132 ( V_2 ) ;
F_374 ( & V_2 -> V_300 ) ;
F_32 ( V_2 ) ;
}
void F_375 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_317 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_483 . V_471 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_483 . V_486 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_485 . V_471 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_485 . V_486 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_470 . V_471 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_470 . V_486 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_12 . V_499 ) ;
}
int F_376 ( struct V_1 * V_2 )
{
int V_788 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_319 ) ;
F_60 ( & V_2 -> V_533 , 0 ) ;
F_134 ( V_2 ) ;
V_789:
if ( V_788 < 3 )
F_68 ( 2 , L_320 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_367 ( F_44 ( V_2 ) ) ;
F_367 ( F_377 ( V_2 ) ) ;
F_367 ( F_152 ( V_2 ) ) ;
F_249 ( F_44 ( V_2 ) ) ;
V_37 = F_365 ( F_152 ( V_2 ) ) ;
if ( V_37 )
goto V_790;
V_37 = F_365 ( F_377 ( V_2 ) ) ;
if ( V_37 )
goto V_790;
V_37 = F_365 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_790;
V_790:
if ( V_37 == - V_323 ) {
F_41 ( V_65 , 2 , L_321 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_788 < 0 )
goto V_73;
else
goto V_789;
}
F_364 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
V_37 = F_173 ( & V_2 -> V_114 , F_185 ) ;
if ( V_37 == - V_323 ) {
F_41 ( V_65 , 2 , L_322 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
if ( -- V_788 < 0 )
goto V_73;
else
goto V_789;
}
V_37 = F_173 ( & V_2 -> V_154 , F_182 ) ;
if ( V_37 == - V_323 ) {
F_41 ( V_65 , 2 , L_323 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
if ( -- V_788 < 0 )
goto V_73;
else
goto V_789;
}
V_2 -> V_123 = 0 ;
V_37 = F_247 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_73;
}
V_2 -> V_66 . V_483 . V_471 = 0 ;
V_2 -> V_66 . V_470 . V_471 = 0 ;
V_2 -> V_66 . V_791 . V_471 = 0 ;
V_2 -> V_12 . V_499 = 0 ;
V_37 = F_280 ( V_2 , V_393 ) ;
if ( V_37 == - V_50 )
goto V_73;
if ( F_338 ( V_2 , V_484 ) ) {
V_37 = F_278 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_73;
}
}
if ( F_282 ( V_2 , V_792 ) ) {
V_37 = F_284 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_73;
}
}
return 0 ;
V_73:
F_67 ( & V_2 -> V_10 -> V_9 , L_106
L_107 ) ;
F_68 ( 2 , L_324 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
return V_37 ;
}
static inline int F_378 ( struct V_444 * V_793 ,
struct V_794 * V_244 ,
struct V_231 * * V_795 , int V_183 , int * V_796 , int V_606 )
{
struct V_440 * V_440 = F_261 ( V_244 -> V_249 ) ;
if ( * V_795 == NULL ) {
if ( V_793 -> V_431 ) {
* V_795 = V_793 -> V_431 ;
V_793 -> V_431 = NULL ;
} else {
* V_795 = F_265 ( V_445 + V_446 ) ;
if ( ! ( * V_795 ) )
return - V_50 ;
}
F_379 ( * V_795 , V_446 ) ;
if ( V_606 <= V_445 ) {
memcpy ( F_380 ( * V_795 , V_606 ) , V_244 -> V_249 + V_183 ,
V_606 ) ;
} else {
F_381 ( V_440 ) ;
memcpy ( F_380 ( * V_795 , V_445 ) ,
V_244 -> V_249 + V_183 , V_445 ) ;
F_382 ( * V_795 , * V_796 , V_440 ,
V_183 + V_445 ,
V_606 - V_445 ) ;
( * V_795 ) -> V_606 += V_606 - V_445 ;
( * V_795 ) -> V_162 += V_606 - V_445 ;
( * V_795 ) -> V_797 += V_606 - V_445 ;
( * V_796 ) ++ ;
}
} else {
F_381 ( V_440 ) ;
F_382 ( * V_795 , * V_796 , V_440 , V_183 , V_606 ) ;
( * V_795 ) -> V_606 += V_606 ;
( * V_795 ) -> V_162 += V_606 ;
( * V_795 ) -> V_797 += V_606 ;
( * V_796 ) ++ ;
}
return 0 ;
}
static inline int F_383 ( struct V_794 * V_798 )
{
return ( V_798 -> V_253 & V_447 ) ;
}
struct V_231 * F_384 ( struct V_1 * V_2 ,
struct V_444 * V_793 ,
struct V_794 * * V_799 , int * V_800 ,
struct V_608 * * V_133 )
{
struct V_794 * V_244 = * V_799 ;
struct V_525 * V_64 = V_793 -> V_64 ;
int V_183 = * V_800 ;
struct V_231 * V_232 = NULL ;
int V_801 = 0 ;
void * V_802 ;
int V_606 ;
int V_803 = 0 ;
int V_804 = 0 ;
int V_599 = 0 ;
if ( V_244 -> V_252 < V_183 + sizeof( struct V_608 ) ) {
if ( F_383 ( V_244 ) )
return NULL ;
V_244 ++ ;
V_183 = 0 ;
if ( V_244 -> V_252 < sizeof( struct V_608 ) )
return NULL ;
}
* V_133 = V_244 -> V_249 + V_183 ;
V_183 += sizeof( struct V_608 ) ;
switch ( ( * V_133 ) -> V_133 . V_805 . V_313 ) {
case V_806 :
V_801 = ( * V_133 ) -> V_133 . V_805 . V_807 ;
break;
case V_808 :
V_801 = ( * V_133 ) -> V_133 . V_623 . V_252 ;
V_803 = V_446 ;
break;
case V_809 :
V_801 = ( * V_133 ) -> V_133 . V_810 . V_811 ;
V_803 = sizeof( struct V_608 ) ;
break;
default:
break;
}
if ( ! V_801 )
return NULL ;
if ( ( ( V_801 >= V_2 -> V_66 . V_273 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_533 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_804 = 1 ;
} else {
V_232 = F_265 ( V_801 + V_803 ) ;
if ( ! V_232 )
goto V_812;
if ( V_803 )
F_379 ( V_232 , V_803 ) ;
}
V_802 = V_244 -> V_249 + V_183 ;
while ( V_801 ) {
V_606 = F_212 ( V_801 , ( int ) ( V_244 -> V_252 - V_183 ) ) ;
if ( V_606 ) {
if ( V_804 ) {
if ( F_378 ( V_793 , V_244 ,
& V_232 , V_183 , & V_599 , V_606 ) )
goto V_812;
} else {
memcpy ( F_380 ( V_232 , V_606 ) , V_802 ,
V_606 ) ;
}
}
V_801 -= V_606 ;
if ( V_801 ) {
if ( F_383 ( V_244 ) ) {
F_4 ( V_2 , 4 , L_325 ) ;
F_385 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_127 ( V_232 ) ;
V_2 -> V_528 . V_702 ++ ;
return NULL ;
}
V_244 ++ ;
V_183 = 0 ;
V_802 = V_244 -> V_249 ;
} else {
V_183 += V_606 ;
}
}
* V_799 = V_244 ;
* V_800 = V_183 ;
if ( V_804 && V_2 -> V_66 . V_272 ) {
V_2 -> V_442 . V_813 ++ ;
V_2 -> V_442 . V_814 += F_321 ( V_232 ) -> V_600 ;
}
return V_232 ;
V_812:
if ( F_386 () ) {
F_4 ( V_2 , 2 , L_326 ) ;
}
V_2 -> V_528 . V_529 ++ ;
return NULL ;
}
static void F_387 ( void )
{
int V_815 ;
for ( V_815 = 0 ; V_815 < V_816 ; V_815 ++ ) {
F_388 ( V_817 [ V_815 ] . V_313 ) ;
V_817 [ V_815 ] . V_313 = NULL ;
}
}
void F_389 ( T_5 * V_313 , int V_372 , char * V_818 , ... )
{
char V_819 [ 32 ] ;
T_6 args ;
if ( ! F_390 ( V_313 , V_372 ) )
return;
va_start ( args , V_818 ) ;
vsnprintf ( V_819 , sizeof( V_819 ) , V_818 , args ) ;
va_end ( args ) ;
F_391 ( V_313 , V_372 , V_819 ) ;
}
static int F_392 ( void )
{
int V_337 ;
int V_815 ;
for ( V_815 = 0 ; V_815 < V_816 ; V_815 ++ ) {
V_817 [ V_815 ] . V_313 = F_393 ( V_817 [ V_815 ] . V_516 ,
V_817 [ V_815 ] . V_820 ,
V_817 [ V_815 ] . V_821 ,
V_817 [ V_815 ] . V_162 ) ;
if ( V_817 [ V_815 ] . V_313 == NULL ) {
F_387 () ;
return - V_50 ;
}
V_337 = F_394 ( V_817 [ V_815 ] . V_313 , V_817 [ V_815 ] . V_822 ) ;
if ( V_337 ) {
F_387 () ;
return V_337 ;
}
F_395 ( V_817 [ V_815 ] . V_313 , V_817 [ V_815 ] . V_372 ) ;
}
return 0 ;
}
int F_396 ( struct V_1 * V_2 ,
enum V_823 V_148 )
{
int V_37 = 0 ;
F_397 ( & V_824 ) ;
switch ( V_148 ) {
case V_825 :
V_2 -> V_148 = F_398 (
F_399 ( V_826 ) , L_327 ) ;
break;
case V_827 :
V_2 -> V_148 = F_398 (
F_399 ( V_828 ) , L_328 ) ;
break;
}
if ( ! V_2 -> V_148 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_329
L_330 , V_148 ) ;
V_37 = - V_405 ;
}
F_400 ( & V_824 ) ;
return V_37 ;
}
void F_401 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_306 )
F_402 ( V_828 ) ;
else
F_402 ( V_826 ) ;
V_2 -> V_148 = NULL ;
}
static T_5 * F_403 ( char * V_516 )
{
struct V_829 * V_438 ;
T_5 * V_37 = NULL ;
F_397 ( & V_830 ) ;
F_254 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_438 -> V_831 , V_516 ) == 0 ) {
V_37 = V_438 -> V_832 ;
break;
}
}
F_400 ( & V_830 ) ;
return V_37 ;
}
static int F_404 ( struct V_1 * V_2 , char * V_516 )
{
struct V_829 * V_833 ;
V_2 -> V_834 = F_393 ( V_516 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_834 ) {
F_45 ( V_65 , 2 , L_191 , L_331 ) ;
goto V_835;
}
if ( F_394 ( V_2 -> V_834 , & V_836 ) )
goto V_837;
V_833 = F_27 ( sizeof( struct V_829 ) , V_49 ) ;
if ( ! V_833 )
goto V_837;
strncpy ( V_833 -> V_831 , V_516 , V_838 ) ;
V_833 -> V_832 = V_2 -> V_834 ;
F_397 ( & V_830 ) ;
F_33 ( & V_833 -> V_839 , & V_840 ) ;
F_400 ( & V_830 ) ;
return 0 ;
V_837:
F_388 ( V_2 -> V_834 ) ;
V_835:
return - V_50 ;
}
static void F_405 ( void )
{
struct V_829 * V_438 , * V_41 ;
F_397 ( & V_830 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_438 -> V_839 ) ;
F_388 ( V_438 -> V_832 ) ;
F_32 ( V_438 ) ;
}
F_400 ( & V_830 ) ;
}
static int F_406 ( struct V_159 * V_10 )
{
struct V_1 * V_2 ;
struct V_841 * V_9 ;
int V_37 ;
unsigned long V_32 ;
char V_831 [ V_838 ] ;
F_41 ( V_65 , 2 , L_332 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_407 ( V_9 ) )
return - V_842 ;
F_45 ( V_65 , 2 , L_191 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_149 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_843;
}
snprintf ( V_831 , sizeof( V_831 ) , L_333 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_834 = F_403 ( V_831 ) ;
if ( ! V_2 -> V_834 ) {
V_37 = F_404 ( V_2 , V_831 ) ;
if ( V_37 )
goto V_844;
}
V_2 -> V_114 . V_119 = V_10 -> V_158 [ 0 ] ;
V_2 -> V_154 . V_119 = V_10 -> V_158 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_158 [ 2 ] ;
F_408 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_158 [ 0 ] -> V_845 = F_118 ;
V_10 -> V_158 [ 1 ] -> V_845 = F_118 ;
V_10 -> V_158 [ 2 ] -> V_845 = F_118 ;
V_37 = F_151 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_844;
}
V_37 = F_142 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_844;
}
if ( V_2 -> V_12 . type == V_18 )
V_10 -> V_9 . type = & V_846 ;
else
V_10 -> V_9 . type = & V_847 ;
switch ( V_2 -> V_12 . type ) {
case V_18 :
case V_16 :
V_37 = F_396 ( V_2 , V_827 ) ;
if ( V_37 )
goto V_844;
V_37 = V_2 -> V_148 -> V_848 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_849;
case V_14 :
case V_17 :
default:
break;
}
F_409 ( & V_850 . V_851 , V_32 ) ;
F_102 ( & V_2 -> V_42 , & V_850 . V_42 ) ;
F_410 ( & V_850 . V_851 , V_32 ) ;
F_364 ( V_2 ) ;
return 0 ;
V_849:
F_401 ( V_2 ) ;
V_844:
F_372 ( V_2 ) ;
V_843:
F_411 ( V_9 ) ;
return V_37 ;
}
static void F_412 ( struct V_159 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_334 ) ;
if ( V_2 -> V_148 ) {
V_2 -> V_148 -> remove ( V_10 ) ;
F_401 ( V_2 ) ;
}
F_409 ( & V_850 . V_851 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_410 ( & V_850 . V_851 , V_32 ) ;
F_372 ( V_2 ) ;
F_408 ( & V_10 -> V_9 , NULL ) ;
F_411 ( & V_10 -> V_9 ) ;
return;
}
static int F_413 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
int V_852 ;
if ( ! V_2 -> V_148 ) {
if ( V_2 -> V_12 . type == V_15 )
V_852 = V_825 ;
else
V_852 = V_827 ;
V_37 = F_396 ( V_2 , V_852 ) ;
if ( V_37 )
goto V_835;
V_37 = V_2 -> V_148 -> V_848 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_835;
}
V_37 = V_2 -> V_148 -> V_853 ( V_10 ) ;
V_835:
return V_37 ;
}
static int F_414 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
return V_2 -> V_148 -> V_854 ( V_10 ) ;
}
static void F_415 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_855 )
V_2 -> V_148 -> V_855 ( V_10 ) ;
}
static int F_416 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_856 )
return V_2 -> V_148 -> V_856 ( V_10 ) ;
return 0 ;
}
static void F_417 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_857 )
V_2 -> V_148 -> V_857 ( V_10 ) ;
}
static int F_418 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_858 )
return V_2 -> V_148 -> V_858 ( V_10 ) ;
return 0 ;
}
static int F_419 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_859 )
return V_2 -> V_148 -> V_859 ( V_10 ) ;
return 0 ;
}
static int F_420 ( struct V_159 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_148 && V_2 -> V_148 -> V_860 )
return V_2 -> V_148 -> V_860 ( V_10 ) ;
return 0 ;
}
static T_7 F_421 ( struct V_861 * V_862 ,
const char * V_230 , T_8 V_166 )
{
int V_835 ;
V_835 = F_422 ( V_863 ,
& V_864 , 3 , V_230 ) ;
return V_835 ? V_835 : V_166 ;
}
int F_423 ( struct V_636 * V_9 , int V_865 )
{
switch ( V_865 ) {
case V_866 :
return ( sizeof( V_867 ) / V_868 ) ;
default:
return - V_405 ;
}
}
void F_424 ( struct V_636 * V_9 ,
struct V_869 * V_528 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_641 ;
V_117 [ 0 ] = V_2 -> V_528 . V_870 -
V_2 -> V_442 . V_871 ;
V_117 [ 1 ] = V_2 -> V_442 . V_872 ;
V_117 [ 2 ] = V_2 -> V_528 . V_873 -
V_2 -> V_442 . V_874 ;
V_117 [ 3 ] = V_2 -> V_442 . V_557 ;
V_117 [ 4 ] = V_2 -> V_528 . V_873 - V_2 -> V_442 . V_874
- V_2 -> V_442 . V_627 ;
V_117 [ 5 ] = V_2 -> V_442 . V_557 - V_2 -> V_442 . V_561 ;
V_117 [ 6 ] = V_2 -> V_442 . V_627 ;
V_117 [ 7 ] = V_2 -> V_442 . V_561 ;
V_117 [ 8 ] = V_2 -> V_442 . V_875 ;
V_117 [ 9 ] = V_2 -> V_442 . V_876 ;
V_117 [ 10 ] = V_2 -> V_442 . V_813 ;
V_117 [ 11 ] = V_2 -> V_442 . V_814 ;
V_117 [ 12 ] = V_2 -> V_442 . V_443 ;
V_117 [ 13 ] = ( V_2 -> V_442 . V_877 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_442 . V_878 ;
V_117 [ 15 ] = V_2 -> V_442 . V_543 ;
V_117 [ 16 ] = V_2 -> V_442 . V_546 ;
V_117 [ 17 ] = V_545 ;
V_117 [ 18 ] = V_542 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_450 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_450 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_450 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_450 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_442 . V_879 ;
V_117 [ 24 ] = V_2 -> V_442 . V_880 ;
V_117 [ 25 ] = V_2 -> V_442 . V_537 ;
V_117 [ 26 ] = V_2 -> V_442 . V_535 ;
V_117 [ 27 ] = V_2 -> V_442 . V_580 ;
V_117 [ 28 ] = V_2 -> V_442 . V_576 ;
V_117 [ 29 ] = V_2 -> V_442 . V_881 ;
V_117 [ 30 ] = V_2 -> V_442 . V_882 ;
V_117 [ 31 ] = V_2 -> V_442 . V_554 ;
V_117 [ 32 ] = V_2 -> V_442 . V_550 ;
V_117 [ 33 ] = V_2 -> V_442 . V_883 ;
V_117 [ 34 ] = V_2 -> V_442 . V_884 ;
V_117 [ 35 ] = V_2 -> V_442 . V_568 ;
V_117 [ 36 ] = V_2 -> V_442 . V_572 ;
}
void F_425 ( struct V_636 * V_9 , V_712 V_865 , V_278 * V_117 )
{
switch ( V_865 ) {
case V_866 :
memcpy ( V_117 , & V_867 ,
sizeof( V_867 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_426 ( struct V_636 * V_9 ,
struct V_885 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_641 ;
F_427 ( V_12 -> V_886 , V_2 -> V_66 . V_306 ? L_328 : L_327 ,
sizeof( V_12 -> V_886 ) ) ;
F_427 ( V_12 -> V_887 , L_335 , sizeof( V_12 -> V_887 ) ) ;
F_427 ( V_12 -> V_888 , V_2 -> V_12 . V_301 ,
sizeof( V_12 -> V_888 ) ) ;
snprintf ( V_12 -> V_889 , sizeof( V_12 -> V_889 ) , L_336 ,
F_428 ( V_2 ) , F_429 ( V_2 ) , F_430 ( V_2 ) ) ;
}
static void F_431 ( struct V_890 * V_891 ,
int V_892 , int V_893 )
{
int V_894 , V_895 , V_896 , V_897 ;
switch ( V_893 ) {
case V_898 :
V_894 = V_899 ;
V_895 = V_900 ;
break;
case V_901 :
V_894 = V_902 ;
V_895 = V_903 ;
break;
default:
V_894 = V_899 ;
V_895 = V_900 ;
F_54 ( 1 ) ;
}
V_896 = 0 ;
V_897 = 0 ;
switch ( V_892 ) {
case V_904 :
V_896 |= V_905 ;
V_897 |= V_906 ;
case V_907 :
V_896 |= V_908 | V_909 ;
V_897 |= V_910 |
V_911 ;
case V_912 :
V_896 |= V_913 | V_914 ;
V_897 |= V_915 | V_916 ;
case V_917 :
V_896 |= V_918 | V_919 ;
V_897 |= V_920 | V_921 ;
break;
default:
V_896 = V_918 | V_919 ;
V_897 = V_920 | V_921 ;
F_54 ( 1 ) ;
}
V_891 -> V_922 = V_923 | V_895 | V_897 ;
V_891 -> V_924 = V_925 | V_894 | V_896 ;
}
int F_432 ( struct V_636 * V_926 ,
struct V_890 * V_891 )
{
struct V_1 * V_2 = V_926 -> V_641 ;
enum V_452 V_19 ;
struct V_748 V_748 ;
int V_37 ;
V_712 V_927 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_891 -> V_928 = V_929 ;
V_891 -> V_930 = V_931 ;
V_891 -> V_932 = V_933 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
F_431 ( V_891 , V_912 , V_898 ) ;
V_927 = V_912 ;
V_891 -> V_934 = V_898 ;
break;
case V_22 :
case V_26 :
F_431 ( V_891 , V_907 , V_901 ) ;
V_927 = V_907 ;
V_891 -> V_934 = V_901 ;
break;
case V_23 :
F_431 ( V_891 , V_904 , V_901 ) ;
V_927 = V_904 ;
V_891 -> V_934 = V_901 ;
break;
default:
F_431 ( V_891 , V_917 , V_898 ) ;
V_927 = V_917 ;
V_891 -> V_934 = V_898 ;
}
F_433 ( V_891 , V_927 ) ;
if ( ! F_1 ( V_2 ) )
return - V_842 ;
V_37 = V_746 ( V_2 , & V_748 ) ;
if ( V_37 == - V_339 )
return 0 ;
if ( V_37 )
return V_37 ;
F_434 ( V_926 ,
L_337 ,
V_748 . V_749 ,
V_748 . V_750 ,
V_748 . V_751 ) ;
switch ( V_748 . V_749 ) {
case V_935 :
case V_936 :
F_431 ( V_891 , V_907 , V_898 ) ;
V_891 -> V_934 = V_898 ;
break;
case V_937 :
case V_938 :
F_431 ( V_891 , V_907 , V_901 ) ;
V_891 -> V_934 = V_901 ;
break;
case V_939 :
case V_940 :
F_431 ( V_891 , V_904 , V_901 ) ;
V_891 -> V_934 = V_901 ;
break;
}
switch ( V_748 . V_750 ) {
case V_941 :
V_891 -> V_930 = V_931 ;
break;
case V_942 :
V_891 -> V_930 = V_943 ;
break;
}
switch ( V_748 . V_751 ) {
case V_944 :
V_927 = V_917 ;
break;
case V_945 :
V_927 = V_912 ;
break;
case V_946 :
V_927 = V_907 ;
break;
case V_947 :
V_927 = V_904 ;
break;
}
F_433 ( V_891 , V_927 ) ;
return 0 ;
}
static int T_10 F_435 ( void )
{
int V_37 ;
F_436 ( L_338 ) ;
F_137 ( & V_850 . V_42 ) ;
F_137 ( & V_840 ) ;
F_437 ( & V_850 . V_851 ) ;
F_143 ( & V_824 ) ;
V_11 = F_438 ( L_339 ) ;
V_37 = F_392 () ;
if ( V_37 )
goto V_948;
V_863 = F_439 ( L_340 ) ;
V_37 = F_440 ( V_863 ) ;
if ( V_37 )
goto V_949;
V_251 = F_441 ( L_341 ,
sizeof( struct V_608 ) + V_446 , 64 , 0 , NULL ) ;
if ( ! V_251 ) {
V_37 = - V_50 ;
goto V_950;
}
V_101 = F_441 ( L_342 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_951;
}
V_37 = F_442 ( & V_952 ) ;
if ( V_37 )
goto V_953;
V_864 . V_886 . V_954 = V_955 ;
V_37 = F_443 ( & V_864 ) ;
if ( V_37 )
goto V_956;
return 0 ;
V_956:
F_444 ( & V_952 ) ;
V_953:
F_445 ( V_101 ) ;
V_951:
F_445 ( V_251 ) ;
V_950:
F_446 ( V_863 ) ;
V_949:
F_387 () ;
V_948:
F_447 ( L_343 ) ;
return V_37 ;
}
static void T_11 F_448 ( void )
{
F_405 () ;
F_449 ( V_11 ) ;
F_450 ( & V_864 ) ;
F_444 ( & V_952 ) ;
F_445 ( V_101 ) ;
F_445 ( V_251 ) ;
F_446 ( V_863 ) ;
F_387 () ;
F_436 ( L_344 ) ;
}
