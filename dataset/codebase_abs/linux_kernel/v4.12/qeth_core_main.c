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
case V_148 :
if ( V_2 -> V_149 -> V_150
( V_2 , V_130 ) )
return V_130 ;
else
return NULL ;
case V_137 :
return V_130 ;
case V_151 :
F_4 ( V_2 , 3 , L_66 ) ;
break;
case V_152 :
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
struct V_124 * V_125 , * V_153 ;
unsigned long V_32 ;
F_4 ( V_2 , 4 , L_70 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_24 (reply, r, &card->cmd_waiter_list, list) {
F_74 ( V_125 ) ;
V_125 -> V_37 = - V_116 ;
F_76 ( & V_125 -> V_128 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_19 ( & V_125 -> V_36 ) ;
F_77 ( V_125 ) ;
}
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_60 ( & V_2 -> V_155 . V_122 , 0 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
unsigned char * V_64 )
{
if ( ! V_64 )
return 0 ;
F_39 ( V_156 , 2 , V_64 , V_157 ) ;
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
static struct V_1 * F_94 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_95 ( & ( (struct V_160 * )
F_95 ( & V_159 -> V_9 ) ) -> V_9 ) ;
return V_2 ;
}
static void F_70 ( struct V_161 * V_162 , unsigned char * V_113 ,
T_1 V_163 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 4 , L_80 ) ;
if ( V_162 == & V_2 -> V_114 )
memcpy ( & V_162 -> V_120 , V_164 , sizeof( struct V_165 ) ) ;
else
memcpy ( & V_162 -> V_120 , V_166 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_163 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 ) ;
}
static struct V_112 * F_97 ( struct V_161 * V_162 )
{
T_2 V_169 ;
F_4 ( F_94 ( V_162 -> V_119 ) , 6 , L_81 ) ;
V_169 = V_162 -> V_170 ;
do {
if ( V_162 -> V_113 [ V_169 ] . V_3 == V_171 ) {
V_162 -> V_113 [ V_169 ] . V_3 = V_172 ;
V_162 -> V_170 = ( V_162 -> V_170 + 1 ) %
V_173 ;
memset ( V_162 -> V_113 [ V_169 ] . V_117 , 0 , V_118 ) ;
return V_162 -> V_113 + V_169 ;
}
V_169 = ( V_169 + 1 ) % V_173 ;
} while ( V_169 != V_162 -> V_170 );
return NULL ;
}
void F_98 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
unsigned long V_32 ;
F_4 ( F_94 ( V_162 -> V_119 ) , 6 , L_82 ) ;
F_17 ( & V_162 -> V_174 , V_32 ) ;
memset ( V_113 -> V_117 , 0 , V_118 ) ;
V_113 -> V_3 = V_171 ;
V_113 -> V_175 = V_176 ;
V_113 -> V_37 = 0 ;
F_18 ( & V_162 -> V_174 , V_32 ) ;
F_19 ( & V_162 -> V_36 ) ;
}
static struct V_112 * F_66 ( struct V_161 * V_162 )
{
struct V_112 * V_64 = NULL ;
unsigned long V_32 ;
F_17 ( & V_162 -> V_174 , V_32 ) ;
V_64 = F_97 ( V_162 ) ;
F_18 ( & V_162 -> V_174 , V_32 ) ;
return V_64 ;
}
struct V_112 * F_99 ( struct V_161 * V_162 )
{
struct V_112 * V_64 ;
F_100 ( V_162 -> V_36 ,
( ( V_64 = F_66 ( V_162 ) ) != NULL ) ) ;
return V_64 ;
}
void F_101 ( struct V_161 * V_162 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ )
F_98 ( V_162 , & V_162 -> V_113 [ V_177 ] ) ;
V_162 -> V_178 = 0 ;
V_162 -> V_170 = 0 ;
}
static void V_176 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 , * V_153 ;
struct V_129 * V_130 ;
unsigned long V_32 ;
int V_179 ;
int V_37 = 0 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
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
V_2 -> V_180 . V_181 != NULL ) {
V_2 -> V_180 . V_181 ( V_2 -> V_9 , V_130 ) ;
goto V_73;
}
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_24 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_125 -> V_182 == V_183 ) ||
( ( V_130 ) && ( V_125 -> V_182 == V_130 -> V_133 . V_182 ) ) ) {
F_74 ( V_125 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
V_179 = 0 ;
if ( V_125 -> V_175 != NULL ) {
if ( V_130 ) {
V_125 -> V_184 = ( V_185 ) ( ( char * ) V_130 -
( char * ) V_113 -> V_117 ) ;
V_179 = V_125 -> V_175 ( V_2 ,
V_125 ,
( unsigned long ) V_130 ) ;
} else
V_179 = V_125 -> V_175 ( V_2 ,
V_125 ,
( unsigned long ) V_113 ) ;
}
if ( V_130 )
V_125 -> V_37 = ( V_186 ) V_130 -> V_133 . V_139 ;
else if ( V_113 -> V_37 )
V_125 -> V_37 = V_113 -> V_37 ;
if ( V_179 ) {
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_102 ( & V_125 -> V_42 ,
& V_2 -> V_187 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
} else {
F_76 ( & V_125 -> V_128 ) ;
F_19 ( & V_125 -> V_36 ) ;
}
F_77 ( V_125 ) ;
goto V_73;
}
}
F_18 ( & V_2 -> V_154 , V_32 ) ;
V_73:
memcpy ( & V_2 -> V_182 . V_188 ,
F_103 ( V_113 -> V_117 ) ,
V_189 ) ;
F_98 ( V_162 , V_113 ) ;
}
static int F_104 ( struct V_161 * V_162 )
{
int V_177 ;
F_41 ( V_65 , 2 , L_84 ) ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ ) {
V_162 -> V_113 [ V_177 ] . V_117 =
F_27 ( V_118 , V_190 | V_49 ) ;
if ( V_162 -> V_113 [ V_177 ] . V_117 == NULL )
break;
V_162 -> V_113 [ V_177 ] . V_3 = V_171 ;
V_162 -> V_113 [ V_177 ] . V_162 = V_162 ;
V_162 -> V_113 [ V_177 ] . V_175 = V_176 ;
V_162 -> V_113 [ V_177 ] . V_37 = 0 ;
}
if ( V_177 < V_173 ) {
while ( V_177 -- > 0 )
F_32 ( V_162 -> V_113 [ V_177 ] . V_117 ) ;
return - V_50 ;
}
V_162 -> V_178 = 0 ;
V_162 -> V_170 = 0 ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_105 ( & V_162 -> V_174 ) ;
F_106 ( & V_162 -> V_36 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
unsigned long V_191 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( ! ( V_2 -> V_34 & V_191 ) ||
( V_2 -> V_35 & V_191 ) ) {
F_18 ( & V_2 -> V_33 , V_32 ) ;
return - V_57 ;
}
V_2 -> V_35 |= V_191 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return 0 ;
}
void F_108 ( struct V_1 * V_2 , unsigned long V_191 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_35 &= ~ V_191 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
void F_109 ( struct V_1 * V_2 , unsigned long V_191 )
{
unsigned long V_32 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
V_2 -> V_38 &= ~ V_191 ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned long V_191 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
if ( V_2 -> V_35 & V_191 ) {
if ( ( V_2 -> V_34 & V_191 ) &&
! ( V_2 -> V_38 & V_191 ) ) {
V_37 = 1 ;
V_2 -> V_35 &= ~ V_191 ;
V_2 -> V_38 |= V_191 ;
} else
V_37 = - V_57 ;
}
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
int F_111 ( struct V_1 * V_2 , unsigned long V_191 )
{
int V_37 = 0 ;
F_100 ( V_2 -> V_36 ,
( V_37 = F_110 ( V_2 , V_191 ) ) >= 0 ) ;
return V_37 ;
}
void F_72 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_85 ) ;
if ( F_107 ( V_2 , V_192 ) == 0 )
F_112 ( & V_2 -> V_193 ) ;
}
static int F_113 ( struct V_158 * V_159 , struct V_194 * V_194 )
{
int V_195 , V_196 ;
char * V_197 ;
struct V_1 * V_2 ;
V_197 = ( char * ) V_194 -> V_198 ;
V_196 = V_194 -> V_199 . V_130 . V_196 ;
V_195 = V_194 -> V_199 . V_130 . V_195 ;
V_2 = F_94 ( V_159 ) ;
if ( V_196 & ( V_200 | V_201 |
V_202 | V_203 |
V_204 | V_205 ) ) {
F_4 ( V_2 , 2 , L_86 ) ;
F_67 ( & V_159 -> V_9 , L_48
L_49 ) ;
F_68 ( 2 , L_87 ,
F_69 ( & V_159 -> V_9 ) , V_195 , V_196 ) ;
F_114 ( V_206 , L_88 , V_207 ,
16 , 1 , V_194 , 64 , 1 ) ;
return 1 ;
}
if ( V_195 & V_208 ) {
if ( V_197 [ V_209 ] &
V_210 ) {
F_4 ( V_2 , 2 , L_89 ) ;
return 1 ;
}
if ( V_197 [ V_211 ] &
V_212 ) {
F_4 ( V_2 , 2 , L_90 ) ;
return 1 ;
}
if ( ( V_197 [ 2 ] == 0xaf ) && ( V_197 [ 3 ] == 0xfe ) ) {
F_4 ( V_2 , 2 , L_91 ) ;
return 1 ;
}
if ( ( ! V_197 [ 0 ] ) && ( ! V_197 [ 1 ] ) && ( ! V_197 [ 2 ] ) && ( ! V_197 [ 3 ] ) ) {
F_4 ( V_2 , 2 , L_92 ) ;
return 0 ;
}
F_4 ( V_2 , 2 , L_93 ) ;
return 1 ;
}
return 0 ;
}
static long F_115 ( struct V_158 * V_159 ,
unsigned long V_213 , struct V_194 * V_194 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_159 ) ;
if ( ! V_2 || ! F_116 ( V_194 ) )
return 0 ;
switch ( F_117 ( V_194 ) ) {
case - V_116 :
F_68 ( 2 , L_94 ,
F_69 ( & V_159 -> V_9 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_116 ) ;
break;
case - V_214 :
F_67 ( & V_159 -> V_9 , L_96
L_97 ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_52 ( V_2 , 2 , L_77 , - V_214 ) ;
if ( V_213 == V_215 ) {
if ( V_2 -> V_117 . V_119 == V_159 ) {
V_2 -> V_117 . V_3 = V_216 ;
F_19 ( & V_2 -> V_36 ) ;
}
}
break;
default:
F_68 ( 2 , L_98 ,
F_69 ( & V_159 -> V_9 ) , F_117 ( V_194 ) ) ;
F_4 ( V_2 , 2 , L_95 ) ;
F_4 ( V_2 , 2 , L_99 ) ;
}
return F_117 ( V_194 ) ;
}
static void F_118 ( struct V_158 * V_159 , unsigned long V_213 ,
struct V_194 * V_194 )
{
int V_37 ;
int V_196 , V_195 ;
struct V_112 * V_64 ;
struct V_161 * V_162 ;
struct V_1 * V_2 ;
struct V_112 * V_113 ;
T_2 V_169 ;
if ( F_115 ( V_159 , V_213 , V_194 ) )
return;
V_196 = V_194 -> V_199 . V_130 . V_196 ;
V_195 = V_194 -> V_199 . V_130 . V_195 ;
V_2 = F_94 ( V_159 ) ;
if ( ! V_2 )
return;
F_4 ( V_2 , 5 , L_100 ) ;
if ( V_2 -> V_114 . V_119 == V_159 ) {
V_162 = & V_2 -> V_114 ;
F_4 ( V_2 , 5 , L_101 ) ;
} else if ( V_2 -> V_155 . V_119 == V_159 ) {
V_162 = & V_2 -> V_155 ;
F_4 ( V_2 , 5 , L_102 ) ;
} else {
V_162 = & V_2 -> V_117 ;
F_4 ( V_2 , 5 , L_103 ) ;
}
F_60 ( & V_162 -> V_122 , 0 ) ;
if ( V_194 -> V_199 . V_130 . V_217 & ( V_218 ) )
V_162 -> V_3 = V_219 ;
if ( V_194 -> V_199 . V_130 . V_217 & ( V_220 ) )
V_162 -> V_3 = V_221 ;
if ( ( V_162 == & V_2 -> V_117 ) && ( V_213 != 0 ) &&
( V_213 != V_215 ) )
goto V_73;
if ( V_213 == V_222 ) {
F_4 ( V_2 , 6 , L_104 ) ;
V_213 = 0 ;
}
if ( V_213 == V_223 ) {
F_4 ( V_2 , 6 , L_105 ) ;
V_213 = 0 ;
}
if ( ( V_195 & V_224 ) ||
( V_195 & V_208 ) ||
( V_196 ) ) {
if ( V_194 -> V_225 . V_226 . V_227 . V_228 ) {
F_67 ( & V_162 -> V_119 -> V_9 ,
L_106
L_107 ) ;
F_68 ( 2 , L_108
L_109 ,
F_69 ( & V_162 -> V_119 -> V_9 ) , V_196 , V_195 ) ;
F_114 ( V_206 , L_88 ,
V_207 , 16 , 1 , V_194 , 32 , 1 ) ;
F_114 ( V_206 , L_110 ,
V_207 , 16 , 1 , V_194 -> V_198 , 32 , 1 ) ;
}
if ( V_213 == V_215 ) {
V_162 -> V_3 = V_216 ;
goto V_73;
}
V_37 = F_113 ( V_159 , V_194 ) ;
if ( V_37 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
}
if ( V_213 == V_215 ) {
V_162 -> V_3 = V_229 ;
goto V_73;
}
if ( V_213 ) {
V_64 = (struct V_112 * ) F_119 ( ( V_121 ) V_213 ) ;
V_64 -> V_3 = V_230 ;
}
if ( V_162 == & V_2 -> V_117 )
return;
if ( V_162 == & V_2 -> V_114 &&
V_162 -> V_3 == V_115 )
F_65 ( V_2 ) ;
V_113 = V_162 -> V_113 ;
V_169 = V_162 -> V_178 ;
while ( V_113 [ V_169 ] . V_3 == V_230 ) {
if ( V_113 [ V_169 ] . V_175 != NULL )
V_113 [ V_169 ] . V_175 ( V_162 , V_113 + V_169 ) ;
V_169 = ( V_169 + 1 ) % V_173 ;
}
V_162 -> V_178 = V_169 ;
V_73:
F_19 ( & V_2 -> V_36 ) ;
return;
}
static void F_61 ( struct V_92 * V_60 ,
struct V_96 * V_231 ,
enum V_82 V_105 )
{
struct V_232 * V_233 ;
if ( F_120 ( & V_231 -> V_234 ) )
goto V_73;
V_233 = F_121 ( & V_231 -> V_234 ) ;
while ( V_233 ) {
F_52 ( V_60 -> V_2 , 5 , L_111 , V_105 ) ;
F_52 ( V_60 -> V_2 , 5 , L_43 , ( long ) V_233 ) ;
if ( F_122 ( V_233 -> V_235 ) == V_236 ) {
if ( V_233 -> V_237 ) {
struct V_238 * V_239 = F_123 ( V_233 -> V_237 ) ;
V_239 -> V_240 ( V_233 , V_105 ) ;
}
}
if ( F_124 ( & V_231 -> V_234 , V_233 ) )
V_233 = NULL ;
else
V_233 = F_125 ( & V_231 -> V_234 , V_233 ) ;
}
V_73:
return;
}
static void F_53 ( struct V_96 * V_231 )
{
struct V_232 * V_233 ;
struct V_238 * V_239 ;
int V_241 = 0 ;
if ( F_51 ( & V_231 -> V_3 ) == V_109 )
V_241 = 1 ;
F_54 ( F_51 ( & V_231 -> V_3 ) == V_108 ) ;
V_233 = F_126 ( & V_231 -> V_234 ) ;
while ( V_233 ) {
F_4 ( V_231 -> V_60 -> V_2 , 5 , L_112 ) ;
F_52 ( V_231 -> V_60 -> V_2 , 5 , L_43 , ( long ) V_233 ) ;
if ( V_241 &&
F_122 ( V_233 -> V_235 ) == V_236 ) {
if ( V_233 -> V_237 ) {
V_239 = F_123 ( V_233 -> V_237 ) ;
V_239 -> V_240 ( V_233 , V_91 ) ;
}
}
F_127 ( & V_233 -> V_242 ) ;
F_128 ( V_233 ) ;
V_233 = F_126 ( & V_231 -> V_234 ) ;
}
}
static void F_62 ( struct V_92 * V_111 ,
struct V_96 * V_231 ,
enum V_243 V_244 )
{
int V_44 ;
if ( V_231 -> V_64 -> V_245 [ 0 ] . V_246 & V_247 )
F_127 ( & V_111 -> V_248 ) ;
if ( V_244 == V_249 ) {
F_53 ( V_231 ) ;
}
for ( V_44 = 0 ; V_44 < F_29 ( V_111 -> V_2 ) ; ++ V_44 ) {
if ( V_231 -> V_64 -> V_245 [ V_44 ] . V_250 && V_231 -> V_251 [ V_44 ] )
F_55 ( V_252 ,
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 ) ;
V_231 -> V_251 [ V_44 ] = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_253 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 = NULL ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_246 = 0 ;
}
V_231 -> V_64 -> V_245 [ 15 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ 15 ] . V_246 = 0 ;
V_231 -> V_255 = 0 ;
F_60 ( & V_231 -> V_3 , V_244 ) ;
}
static void F_129 ( struct V_92 * V_60 , int free )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( ! V_60 -> V_63 [ V_45 ] )
continue;
F_50 ( V_60 , V_45 , 1 ) ;
F_62 ( V_60 , V_60 -> V_63 [ V_45 ] , V_249 ) ;
if ( free ) {
F_55 ( V_101 , V_60 -> V_63 [ V_45 ] ) ;
V_60 -> V_63 [ V_45 ] = NULL ;
}
}
}
void F_130 ( struct V_1 * V_2 )
{
int V_44 ;
F_4 ( V_2 , 2 , L_113 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
if ( V_2 -> V_46 . V_80 [ V_44 ] ) {
F_129 ( V_2 -> V_46 . V_80 [ V_44 ] , 0 ) ;
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
static void F_131 ( struct V_161 * V_162 )
{
int V_177 ;
F_41 ( V_65 , 2 , L_114 ) ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ )
F_32 ( V_162 -> V_113 [ V_177 ] . V_117 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 4 ) )
F_133 ( V_2 ) ;
V_2 -> V_46 . V_78 = 1 ;
if ( V_2 -> V_46 . V_257 != 0 )
F_89 ( & V_2 -> V_10 -> V_9 , L_115 ) ;
V_2 -> V_46 . V_257 = 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 1 ) ) {
F_133 ( V_2 ) ;
V_2 -> V_46 . V_257 = 2 ;
}
V_2 -> V_46 . V_78 = 4 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_158 * V_119 ;
struct V_258 * V_259 ;
F_41 ( V_65 , 2 , L_116 ) ;
V_119 = V_2 -> V_117 . V_119 ;
V_259 = F_136 ( V_119 , 0 ) ;
if ( ! V_259 )
goto V_73;
V_2 -> V_12 . V_260 = 0x4100 + V_259 -> V_261 ;
if ( V_2 -> V_12 . type == V_15 )
goto V_73;
if ( ( V_259 -> V_262 & 0x02 ) == 0x02 )
F_132 ( V_2 ) ;
else
F_134 ( V_2 ) ;
V_73:
F_32 ( V_259 ) ;
F_45 ( V_65 , 2 , L_117 , V_2 -> V_46 . V_78 ) ;
F_45 ( V_65 , 2 , L_118 , V_2 -> V_12 . V_260 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 4 , L_119 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
V_2 -> V_46 . V_263 = V_264 ;
if ( V_2 -> V_12 . type == V_15 )
V_2 -> V_46 . V_47 . V_48 = V_265 ;
else
V_2 -> V_46 . V_47 . V_48 = V_266 ;
V_2 -> V_46 . V_58 . V_48 = V_2 -> V_46 . V_47 . V_48 ;
F_138 ( & V_2 -> V_46 . V_58 . V_53 ) ;
F_138 ( & V_2 -> V_46 . V_47 . V_53 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
V_2 -> V_66 . V_267 . type = V_268 ;
V_2 -> V_66 . V_269 . type = V_268 ;
V_2 -> V_66 . V_270 = 0 ;
V_2 -> V_66 . V_271 = 0 ;
V_2 -> V_66 . V_272 = V_273 ;
V_2 -> V_66 . V_274 = V_275 ;
V_2 -> V_66 . V_67 = V_276 ;
}
static int F_140 ( struct V_1 * V_2 , unsigned long V_191 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
F_52 ( V_2 , 4 , L_120 ,
( V_277 ) V_2 -> V_35 ,
( V_277 ) V_2 -> V_34 ,
( V_277 ) V_2 -> V_38 ) ;
V_37 = ( V_2 -> V_35 & V_191 ) ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
static void F_141 ( struct V_6 * V_7 )
{
struct V_278 * V_279 ;
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_193 ) ;
F_4 ( V_2 , 2 , L_121 ) ;
if ( V_2 -> V_114 . V_3 != V_115 &&
V_2 -> V_155 . V_3 != V_115 )
return;
if ( F_140 ( V_2 , V_192 ) ) {
V_279 = F_142 ( V_2 -> V_149 -> V_280 , ( void * ) V_2 ,
L_122 ) ;
if ( F_116 ( V_279 ) ) {
F_108 ( V_2 , V_192 ) ;
F_109 ( V_2 ,
V_192 ) ;
}
}
}
static int F_143 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_123 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_114 . V_3 = V_216 ;
V_2 -> V_155 . V_3 = V_216 ;
V_2 -> V_117 . V_3 = V_216 ;
V_2 -> V_3 = V_55 ;
V_2 -> V_143 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_9 = NULL ;
F_105 ( & V_2 -> V_281 ) ;
F_105 ( & V_2 -> V_282 ) ;
F_105 ( & V_2 -> V_154 ) ;
F_105 ( & V_2 -> V_283 ) ;
F_105 ( & V_2 -> V_33 ) ;
F_144 ( & V_2 -> V_284 ) ;
F_144 ( & V_2 -> V_285 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_38 = 0 ;
F_145 ( & V_2 -> V_193 , F_141 ) ;
F_138 ( & V_2 -> V_187 ) ;
F_106 ( & V_2 -> V_36 ) ;
F_139 ( V_2 ) ;
F_138 ( & V_2 -> V_286 . V_287 ) ;
V_2 -> V_286 . V_288 = 0 ;
V_2 -> V_286 . V_289 = 0 ;
V_2 -> V_286 . V_290 = 0 ;
F_137 ( V_2 ) ;
F_146 ( & V_2 -> V_291 , V_292 ) ;
F_145 ( & V_2 -> V_8 , F_2 ) ;
return 0 ;
}
static void F_147 ( struct V_293 * V_294 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_3 ( V_296 , struct V_1 ,
V_297 ) ;
if ( V_2 -> V_12 . V_298 [ 0 ] )
F_148 ( V_294 , L_124 ,
F_149 ( V_2 ) , V_2 -> V_12 . V_298 ) ;
}
static struct V_1 * F_150 ( void )
{
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_125 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_190 | V_49 ) ;
if ( ! V_2 )
goto V_73;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
if ( F_104 ( & V_2 -> V_114 ) )
goto V_299;
if ( F_104 ( & V_2 -> V_155 ) )
goto V_300;
V_2 -> V_66 . V_301 = - 1 ;
V_2 -> V_297 . V_302 = F_147 ;
F_151 ( & V_2 -> V_297 ) ;
return V_2 ;
V_300:
F_131 ( & V_2 -> V_114 ) ;
V_299:
F_32 ( V_2 ) ;
V_73:
return NULL ;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
F_41 ( V_65 , 2 , L_126 ) ;
V_2 -> V_46 . V_303 = V_304 ;
V_2 -> V_46 . V_257 = V_305 ;
while ( V_306 [ V_44 ] [ V_307 ] ) {
if ( ( F_153 ( V_2 ) -> V_308 . V_309 ==
V_306 [ V_44 ] [ V_310 ] ) &&
( F_153 ( V_2 ) -> V_308 . V_311 ==
V_306 [ V_44 ] [ V_307 ] ) ) {
V_2 -> V_12 . type = V_306 [ V_44 ] [ V_307 ] ;
V_2 -> V_46 . V_78 =
V_306 [ V_44 ] [ V_312 ] ;
V_2 -> V_46 . V_72 = 1 ;
V_2 -> V_12 . V_313 =
V_306 [ V_44 ] [ V_314 ] ;
F_135 ( V_2 ) ;
return 0 ;
}
V_44 ++ ;
}
V_2 -> V_12 . type = V_315 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_127
L_128 ) ;
return - V_316 ;
}
static int F_154 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_129 ) ;
F_17 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_156 ( V_162 -> V_119 , V_222 ) ;
F_18 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_157 ( V_2 -> V_36 ,
V_162 -> V_3 == V_219 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_219 )
return - V_319 ;
V_162 -> V_3 = V_216 ;
return 0 ;
}
static int F_158 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_130 ) ;
F_17 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_159 ( V_162 -> V_119 , V_223 ) ;
F_18 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_157 ( V_2 -> V_36 ,
V_162 -> V_3 == V_221 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_221 )
return - V_319 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_4 ( V_2 , 3 , L_131 ) ;
V_320 = F_158 ( & V_2 -> V_114 ) ;
V_321 = F_158 ( & V_2 -> V_155 ) ;
V_322 = F_158 ( & V_2 -> V_117 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_4 ( V_2 , 3 , L_132 ) ;
V_320 = F_154 ( & V_2 -> V_114 ) ;
V_321 = F_154 ( & V_2 -> V_155 ) ;
V_322 = F_154 ( & V_2 -> V_117 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_162 ( struct V_1 * V_2 , int V_323 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_133 ) ;
if ( V_323 )
V_37 = F_160 ( V_2 ) ;
if ( V_37 )
return V_37 ;
return F_161 ( V_2 ) ;
}
int F_163 ( struct V_1 * V_2 , int V_324 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_134 ) ;
switch ( F_59 ( & V_2 -> V_46 . V_3 , V_325 ,
V_326 ) ) {
case V_325 :
if ( V_2 -> V_12 . type == V_15 )
V_37 = F_164 ( F_44 ( V_2 ) ,
V_327 ) ;
else
V_37 = F_164 ( F_44 ( V_2 ) ,
V_328 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_37 , V_37 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_329 ) ;
break;
case V_326 :
return V_37 ;
default:
break;
}
V_37 = F_162 ( V_2 , V_324 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_135 , V_37 ) ;
V_2 -> V_3 = V_55 ;
return V_37 ;
}
static int F_165 ( struct V_1 * V_2 , void * * V_64 ,
int * V_253 )
{
struct V_330 * V_330 ;
char * V_331 ;
int V_332 ;
struct V_161 * V_162 = & V_2 -> V_117 ;
unsigned long V_32 ;
V_330 = F_166 ( V_162 -> V_119 , V_333 ) ;
if ( ! V_330 || V_330 -> V_130 == 0 )
return - V_334 ;
V_331 = F_27 ( V_330 -> V_167 , V_49 | V_190 ) ;
if ( ! V_331 )
return - V_50 ;
V_162 -> V_120 . V_335 = V_330 -> V_130 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_331 ) ;
V_162 -> V_120 . V_167 = V_330 -> V_167 ;
V_162 -> V_120 . V_32 = V_336 ;
V_162 -> V_3 = V_337 ;
F_17 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
V_332 = F_167 ( V_162 -> V_119 , & V_162 -> V_120 ,
V_215 , V_338 , 0 ,
V_339 ) ;
F_18 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
if ( ! V_332 )
F_100 ( V_2 -> V_36 ,
( V_162 -> V_3 == V_229 ||
V_162 -> V_3 == V_216 ) ) ;
if ( V_162 -> V_3 == V_216 )
V_332 = - V_116 ;
else
V_162 -> V_3 = V_216 ;
if ( V_332 ) {
F_32 ( V_331 ) ;
* V_64 = NULL ;
* V_253 = 0 ;
} else {
* V_253 = V_330 -> V_167 ;
* V_64 = V_331 ;
}
return V_332 ;
}
static void F_168 ( struct V_1 * V_2 , char * V_340 )
{
F_41 ( V_65 , 2 , L_136 ) ;
V_2 -> V_12 . V_142 = V_340 [ 30 ] ;
V_2 -> V_12 . V_341 = V_340 [ 31 ] ;
V_2 -> V_12 . V_342 = V_340 [ 63 ] ;
V_2 -> V_12 . V_13 = ( ( V_340 [ 0x10 ] == V_343 [ 'V' ] ) &&
( V_340 [ 0x11 ] == V_343 [ 'M' ] ) ) ;
}
static void F_169 ( struct V_1 * V_2 , char * V_340 )
{
F_41 ( V_65 , 2 , L_137 ) ;
if ( V_340 [ 74 ] == 0xF0 && V_340 [ 75 ] == 0xF0 &&
V_340 [ 76 ] >= 0xF1 && V_340 [ 76 ] <= 0xF4 ) {
V_2 -> V_12 . V_344 . V_345 = 0 ;
V_2 -> V_12 . V_344 . V_346 = 0 ;
V_2 -> V_12 . V_344 . V_347 = 0 ;
} else {
V_2 -> V_12 . V_344 . V_345 = 250 ;
V_2 -> V_12 . V_344 . V_346 = 5 ;
V_2 -> V_12 . V_344 . V_347 = 15 ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
V_2 -> V_348 . V_349 = 0x00010103UL ;
V_2 -> V_348 . V_350 = 0x00010108UL ;
V_2 -> V_348 . V_351 = 0x0001010aUL ;
V_2 -> V_348 . V_352 = 0x0001010bUL ;
V_2 -> V_348 . V_353 = 0x0001010dUL ;
}
static void F_171 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
V_2 -> V_12 . V_260 = V_354 ;
break;
case V_14 :
case V_18 :
V_2 -> V_12 . V_260 = V_355 ;
break;
default:
break;
}
}
static int F_172 ( struct V_161 * V_162 ,
void (* F_173)( struct V_161 * ,
struct V_112 * ) )
{
struct V_112 * V_113 ;
unsigned long V_32 ;
int V_37 ;
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_138 ) ;
V_2 = F_94 ( V_162 -> V_119 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_173 ;
memcpy ( & V_162 -> V_120 , V_164 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_118 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_139 , V_37 ) ;
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_157 ( V_2 -> V_36 ,
V_162 -> V_3 == V_115 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_115 ) {
V_37 = - V_319 ;
F_45 ( V_65 , 2 , L_140 , V_37 ) ;
F_101 ( V_162 ) ;
} else
V_37 = 0 ;
return V_37 ;
}
static int F_174 ( struct V_161 * V_162 ,
void (* F_173)( struct V_161 * ,
struct V_112 * ) )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
unsigned long V_32 ;
V_185 V_356 ;
T_2 V_41 ;
int V_37 ;
struct V_357 V_358 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_41 ( V_65 , 2 , L_141 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_173 ;
memcpy ( & V_162 -> V_120 , V_166 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_359 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
if ( V_162 == & V_2 -> V_155 ) {
memcpy ( V_113 -> V_117 , V_360 , V_359 ) ;
memcpy ( F_175 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_361 , V_189 ) ;
V_2 -> V_182 . V_361 ++ ;
} else {
memcpy ( V_113 -> V_117 , V_362 , V_359 ) ;
memcpy ( F_175 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_361 , V_189 ) ;
}
V_41 = ( ( T_2 ) V_2 -> V_12 . V_363 ) | 0x80 ;
memcpy ( F_176 ( V_113 -> V_117 ) , & V_41 , 1 ) ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_349 , V_364 ) ;
memcpy ( F_178 ( V_113 -> V_117 ) ,
& V_2 -> V_12 . V_260 , sizeof( V_185 ) ) ;
F_179 ( F_44 ( V_2 ) , & V_358 ) ;
memcpy ( F_180 ( V_113 -> V_117 ) , & V_358 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_12 . V_342 << 8 ) + V_2 -> V_12 . V_341 ;
memcpy ( F_181 ( V_113 -> V_117 ) , & V_356 , 2 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_155 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_142 ,
V_37 ) ;
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_157 ( V_2 -> V_36 ,
V_162 -> V_3 == V_366 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_366 ) {
F_67 ( & V_162 -> V_119 -> V_9 , L_143
L_144 ) ;
F_68 ( 2 , L_145 ,
F_69 ( & V_162 -> V_119 -> V_9 ) ) ;
F_45 ( V_65 , 2 , L_135 , - V_319 ) ;
F_101 ( V_162 ) ;
return - V_319 ;
}
return F_172 ( V_162 , F_173 ) ;
}
static int F_182 ( int V_367 )
{
if ( ( V_367 & 0xff ) == 8 )
return ( V_367 & 0xff ) + 0x400 ;
if ( ( ( V_367 >> 8 ) & 3 ) == 1 )
return ( V_367 & 0xff ) + 0x200 ;
return V_367 ;
}
static void F_183 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_356 ;
F_41 ( V_65 , 2 , L_146 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_366 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( ! ( F_184 ( V_113 -> V_117 ) ) ) {
if ( F_185 ( V_113 -> V_117 ) == V_368 )
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_147
L_148 ) ;
else
F_68 ( 2 , L_149
L_150 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ) ;
goto V_73;
}
memcpy ( & V_356 , F_178 ( V_113 -> V_117 ) , 2 ) ;
if ( ( V_356 & ~ 0x0100 ) != F_182 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_151
L_152
L_153 , F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_356 ) ;
goto V_73;
}
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
static void F_186 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_356 ;
F_41 ( V_65 , 2 , L_154 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_366 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( F_93 ( V_2 , V_113 -> V_117 ) )
goto V_73;
if ( ! ( F_184 ( V_113 -> V_117 ) ) ) {
switch ( F_185 ( V_113 -> V_117 ) ) {
case V_368 :
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_147
L_148 ) ;
break;
case V_369 :
case V_370 :
F_47 ( & V_2 -> V_114 . V_119 -> V_9 ,
L_155
L_156 ) ;
break;
default:
F_68 ( 2 , L_157
L_150 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ) ;
}
F_52 ( V_2 , 2 , L_158 ,
F_185 ( V_113 -> V_117 ) ) ;
goto V_73;
}
memcpy ( & V_356 , F_178 ( V_113 -> V_117 ) , 2 ) ;
if ( V_356 != F_182 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_159
L_160 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_356 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_348 . V_371 ,
F_177 ( V_113 -> V_117 ) ,
V_364 ) ;
memcpy ( & V_2 -> V_12 . V_298 [ 0 ] ,
F_187 ( V_113 -> V_117 ) , V_372 ) ;
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
void F_188 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_155 , V_113 -> V_117 , V_163 ) ;
V_113 -> V_175 = F_98 ;
memcpy ( F_175 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_361 , V_189 ) ;
V_2 -> V_182 . V_361 ++ ;
memcpy ( F_103 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_373 , V_189 ) ;
V_2 -> V_182 . V_373 ++ ;
memcpy ( F_189 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_188 , V_189 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
}
int F_190 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 ,
int (* F_191)( struct V_1 * V_374 ,
struct V_124 * V_375 ,
unsigned long V_376 ) ,
void * V_377 )
{
int V_37 ;
unsigned long V_32 ;
struct V_124 * V_125 = NULL ;
unsigned long V_378 , V_379 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 2 , L_161 ) ;
if ( V_2 -> V_123 ) {
F_98 ( V_113 -> V_162 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_175 = F_191 ;
V_125 -> V_380 = V_377 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_182 = V_183 ;
else
V_125 -> V_182 = V_2 -> V_182 . V_381 ++ ;
F_106 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_102 ( & V_125 -> V_42 , & V_2 -> V_187 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
while ( F_59 ( & V_2 -> V_155 . V_122 , 0 , 1 ) ) ;
F_188 ( V_2 , V_163 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_379 = V_382 ;
else
V_379 = V_317 ;
V_378 = V_383 + V_379 ;
F_4 ( V_2 , 6 , L_52 ) ;
F_17 ( F_155 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
V_37 = F_71 ( V_2 -> V_155 . V_119 , & V_2 -> V_155 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_155 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_162
L_163 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) , V_37 ) ;
F_52 ( V_2 , 2 , L_164 , V_37 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_77 ( V_125 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_98 ( V_113 -> V_162 , V_113 ) ;
F_60 ( & V_2 -> V_155 . V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
if ( ( V_130 -> V_133 . V_134 == V_385 ) &&
( V_130 -> V_133 . V_386 == V_387 ) ) {
if ( ! F_192 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_379 ) )
goto V_388;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_193 ( V_383 , V_378 ) )
goto V_388;
F_194 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_388:
V_125 -> V_37 = - V_319 ;
F_17 ( & V_125 -> V_2 -> V_154 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_18 ( & V_125 -> V_2 -> V_154 , V_32 ) ;
F_76 ( & V_125 -> V_128 ) ;
error:
F_60 ( & V_2 -> V_155 . V_122 , 0 ) ;
F_98 ( V_113 -> V_162 , V_113 ) ;
V_2 -> V_155 . V_178 = ( V_2 -> V_155 . V_178 + 1 ) % V_173 ;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
}
static int F_195 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_165 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_348 . V_389 ,
F_196 ( V_113 -> V_117 ) ,
V_364 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_166 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_390 , V_391 ) ;
memcpy ( F_198 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_371 , V_364 ) ;
memcpy ( F_199 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_350 , V_364 ) ;
V_37 = F_190 ( V_2 , V_391 , V_113 ,
F_195 , NULL ) ;
return V_37 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_167 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_348 . V_392 ,
F_201 ( V_113 -> V_117 ) ,
V_364 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_393 , V_394 ) ;
memcpy ( F_203 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_371 , V_364 ) ;
memcpy ( F_204 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_351 , V_364 ) ;
memcpy ( F_205 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_389 , V_364 ) ;
V_37 = F_190 ( V_2 , V_394 , V_113 ,
F_200 , NULL ) ;
return V_37 ;
}
static inline int F_206 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_315 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_395 ;
case V_14 :
switch ( V_2 -> V_12 . V_19 ) {
case V_21 :
case V_25 :
return 2000 ;
default:
return V_2 -> V_66 . V_301 ? 1500 : 1492 ;
}
case V_16 :
case V_17 :
return V_2 -> V_66 . V_301 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_207 ( int V_396 )
{
switch ( V_396 ) {
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
static inline int F_208 ( struct V_1 * V_2 , int V_397 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_397 >= 576 ) &&
( V_397 <= V_2 -> V_12 . V_395 ) ) ;
case V_18 :
case V_315 :
default:
return 1 ;
}
}
static int F_209 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_185 V_397 , V_396 ;
V_185 V_163 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_348 . V_398 ,
F_210 ( V_113 -> V_117 ) ,
V_364 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_396 , F_211 ( V_113 -> V_117 ) , 2 ) ;
V_397 = F_207 ( V_396 ) ;
if ( ! V_397 ) {
V_113 -> V_37 = - V_399 ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
if ( V_2 -> V_12 . V_400 && ( V_2 -> V_12 . V_400 != V_397 ) ) {
if ( V_2 -> V_9 &&
( ( V_2 -> V_9 -> V_397 == V_2 -> V_12 . V_400 ) ||
( V_2 -> V_9 -> V_397 > V_397 ) ) )
V_2 -> V_9 -> V_397 = V_397 ;
F_133 ( V_2 ) ;
}
V_2 -> V_12 . V_400 = V_397 ;
V_2 -> V_12 . V_395 = V_397 ;
V_2 -> V_46 . V_263 = V_397 + 2 * V_401 ;
} else {
V_2 -> V_12 . V_395 = * ( V_185 * ) F_211 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_400 = F_212 ( V_2 -> V_12 . V_395 ,
F_206 ( V_2 ) ) ;
V_2 -> V_46 . V_263 = V_264 ;
}
memcpy ( & V_163 , F_213 ( V_113 -> V_117 ) , 2 ) ;
if ( V_163 >= V_402 ) {
memcpy ( & V_19 ,
F_214 ( V_113 -> V_117 ) , 1 ) ;
V_2 -> V_12 . V_19 = V_19 ;
} else
V_2 -> V_12 . V_19 = 0 ;
F_45 ( V_65 , 2 , L_170 , V_2 -> V_12 . V_19 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_215 ( struct V_1 * V_2 )
{
int V_37 ;
char V_403 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_171 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_404 , V_405 ) ;
* ( F_216 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_363 ;
if ( V_2 -> V_66 . V_301 )
if ( V_2 -> V_12 . type == V_18 )
V_403 = V_406 ;
else
V_403 = V_407 ;
else
V_403 = V_408 ;
memcpy ( F_217 ( V_113 -> V_117 ) , & V_403 , 1 ) ;
memcpy ( F_218 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_392 , V_364 ) ;
memcpy ( F_219 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_352 , V_364 ) ;
V_37 = F_190 ( V_2 , V_405 , V_113 ,
F_209 , NULL ) ;
return V_37 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_348 . V_409 ,
F_221 ( V_113 -> V_117 ) ,
V_364 ) ;
if ( ! strncmp ( L_173 , F_221 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_174 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_175
L_176 ) ;
V_113 -> V_37 = - V_410 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 )
{
int V_37 ;
V_185 V_356 ;
struct V_112 * V_113 ;
struct V_357 V_411 ;
F_41 ( V_65 , 2 , L_177 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_412 , V_413 ) ;
memcpy ( F_223 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_392 , V_364 ) ;
memcpy ( F_224 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_353 , V_364 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_398 , V_364 ) ;
F_179 ( F_44 ( V_2 ) , & V_411 ) ;
memcpy ( F_226 ( V_113 -> V_117 ) , & V_411 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_12 . V_342 << 8 ) + V_2 -> V_12 . V_341 ;
memcpy ( F_227 ( V_113 -> V_117 ) , & V_356 , 2 ) ;
V_37 = F_190 ( V_2 , V_413 , V_113 ,
F_220 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_414 ;
V_37 = 0 ;
V_414 = F_228 ( V_101 , V_126 ) ;
if ( ! V_414 ) {
V_37 = - V_50 ;
goto V_73;
}
V_414 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_229 ( & V_414 -> V_234 ) ;
F_230 ( & V_414 -> V_234 . V_154 , & V_415 ) ;
V_414 -> V_60 = V_60 ;
V_414 -> V_102 = NULL ;
V_414 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_414 -> V_3 , V_249 ) ;
V_60 -> V_63 [ V_93 ] = V_414 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_416 = V_414 ;
F_52 ( V_60 -> V_2 , 2 , L_178 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_414 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_414 -> V_95 ) ;
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
F_41 ( V_65 , 2 , L_179 ) ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_256 ,
V_329 ) != V_256 )
return 0 ;
F_41 ( V_65 , 2 , L_180 ) ;
V_2 -> V_46 . V_417 = F_37 () ;
if ( ! V_2 -> V_46 . V_417 )
goto V_418;
if ( F_26 ( V_2 ) )
goto V_419;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_420;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_232 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_421;
F_45 ( V_65 , 2 , L_181 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_422 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_423;
}
}
if ( F_46 ( V_2 ) )
goto V_421;
return 0 ;
V_423:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_421:
while ( V_44 > 0 ) {
F_231 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_129 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_420:
F_28 ( V_2 ) ;
V_419:
F_35 ( V_2 -> V_46 . V_417 ) ;
V_2 -> V_46 . V_417 = NULL ;
V_418:
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
return - V_50 ;
}
static void F_133 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_234 ( & V_2 -> V_46 . V_3 , V_256 ) ==
V_256 )
return;
F_48 ( V_2 ) ;
F_235 ( & V_2 -> V_291 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_417 -> V_63 [ V_45 ] . V_424 )
F_128 ( V_2 -> V_46 . V_417 -> V_63 [ V_45 ] . V_424 ) ;
}
F_35 ( V_2 -> V_46 . V_417 ) ;
V_2 -> V_46 . V_417 = NULL ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 . V_80 ) {
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_129 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
F_231 ( V_2 -> V_46 . V_80 [ V_44 ] ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
}
}
static void F_236 ( struct V_1 * V_2 ,
char * V_425 )
{
V_425 [ 0 ] = V_343 [ 'P' ] ;
V_425 [ 1 ] = V_343 [ 'C' ] ;
V_425 [ 2 ] = V_343 [ 'I' ] ;
V_425 [ 3 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_425 [ 4 ] ) ) = F_237 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_425 [ 8 ] ) ) = F_238 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_425 [ 12 ] ) ) = F_239 ( V_2 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
char * V_425 )
{
V_425 [ 16 ] = V_343 [ 'B' ] ;
V_425 [ 17 ] = V_343 [ 'L' ] ;
V_425 [ 18 ] = V_343 [ 'K' ] ;
V_425 [ 19 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_425 [ 20 ] ) ) = V_2 -> V_12 . V_344 . V_345 ;
* ( ( unsigned int * ) ( & V_425 [ 24 ] ) ) = V_2 -> V_12 . V_344 . V_346 ;
* ( ( unsigned int * ) ( & V_425 [ 28 ] ) ) =
V_2 -> V_12 . V_344 . V_347 ;
}
static int F_241 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 3 , L_182 ) ;
return F_242 ( F_44 ( V_2 ) ) ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_183 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_426 , V_427 ) ;
memcpy ( F_244 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_392 , V_364 ) ;
memcpy ( F_245 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_409 , V_364 ) ;
V_37 = F_190 ( V_2 , V_427 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_246 ( struct V_1 * V_2 )
{
int V_37 ;
F_41 ( V_65 , 2 , L_184 ) ;
V_37 = F_65 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
return V_37 ;
}
V_37 = F_197 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
goto V_428;
}
V_37 = F_202 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_140 , V_37 ) ;
goto V_428;
}
V_37 = F_215 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_185 , V_37 ) ;
goto V_428;
}
V_37 = F_222 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_428;
}
V_37 = F_233 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_428;
}
V_37 = F_247 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
F_133 ( V_2 ) ;
goto V_428;
}
V_37 = F_241 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_428;
}
V_37 = F_243 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_428;
}
return 0 ;
V_428:
F_163 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_248 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
void F_249 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_298 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_298 , L_190 ,
V_2 -> V_12 . V_298 [ 2 ] ,
V_2 -> V_12 . V_298 [ 3 ] ) ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_298 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_298 [ 0 ] = ( char ) V_429 [ ( T_2 )
V_2 -> V_12 . V_298 [ 0 ] ] ;
V_2 -> V_12 . V_298 [ 1 ] = ( char ) V_429 [ ( T_2 )
V_2 -> V_12 . V_298 [ 1 ] ] ;
V_2 -> V_12 . V_298 [ 2 ] = ( char ) V_429 [ ( T_2 )
V_2 -> V_12 . V_298 [ 2 ] ] ;
V_2 -> V_12 . V_298 [ 3 ] = ( char ) V_429 [ ( T_2 )
V_2 -> V_12 . V_298 [ 3 ] ] ;
V_2 -> V_12 . V_298 [ V_372 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_298 [ 0 ] , 0 , V_372 + 1 ) ;
}
F_89 ( & V_2 -> V_10 -> V_9 ,
L_191 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? L_192 : L_74 ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? V_2 -> V_12 . V_298 : L_74 ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? L_193 : L_74 ,
F_12 ( V_2 ) ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_39 * V_430 ;
F_4 ( V_2 , 5 , L_194 ) ;
F_251 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_252 ( V_2 , V_430 ) ;
}
}
static inline struct V_39 * F_253 (
struct V_1 * V_2 )
{
struct V_431 * V_432 ;
struct V_39 * V_430 ;
int V_44 , free ;
struct V_433 * V_433 ;
if ( F_254 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_255 (plh, &card->qdio.in_buf_pool.entry_list) {
V_430 = F_256 ( V_432 , struct V_39 , V_42 ) ;
free = 1 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_257 ( F_258 ( V_430 -> V_51 [ V_44 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_92 ( & V_430 -> V_42 ) ;
return V_430 ;
}
}
V_430 = F_256 ( V_2 -> V_46 . V_58 . V_53 . V_434 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_257 ( F_258 ( V_430 -> V_51 [ V_44 ] ) ) > 1 ) {
V_433 = F_259 ( V_126 ) ;
if ( ! V_433 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_430 -> V_51 [ V_44 ] ) ;
V_430 -> V_51 [ V_44 ] = F_260 ( V_433 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_435 . V_436 ++ ;
}
}
}
F_92 ( & V_430 -> V_42 ) ;
return V_430 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_437 * V_231 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_231 -> V_424 ) ) {
V_231 -> V_424 = F_262 ( V_438 + V_439 ) ;
if ( ! V_231 -> V_424 )
return 1 ;
}
V_40 = F_253 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_231 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_231 -> V_64 -> V_245 [ V_44 ] . V_253 = V_401 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = V_440 ;
else
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_246 = 0 ;
}
return 0 ;
}
int F_263 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_195 ) ;
F_42 ( V_2 -> V_46 . V_417 -> V_61 ,
V_62 ) ;
F_250 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_261 ( V_2 , & V_2 -> V_46 . V_417 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_417 -> V_70 =
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
V_249 ) ;
}
V_2 -> V_46 . V_80 [ V_44 ] -> V_2 = V_2 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_441 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_442 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_443 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_248 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_444 ) ;
}
return 0 ;
}
static inline T_2 F_264 ( enum V_445 V_19 )
{
switch ( V_19 ) {
case V_21 :
return 2 ;
default:
return 1 ;
}
}
static void F_265 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_2 V_134 ,
enum V_446 V_447 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_448 = V_449 ;
V_130 -> V_133 . V_182 = V_2 -> V_182 . V_381 ;
V_130 -> V_133 . V_450 = F_264 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_451 = ( T_2 ) V_2 -> V_12 . V_363 ;
if ( V_2 -> V_66 . V_301 )
V_130 -> V_133 . V_452 = 2 ;
else
V_130 -> V_133 . V_452 = 1 ;
V_130 -> V_133 . V_453 = 1 ;
V_130 -> V_133 . V_386 = V_447 ;
V_130 -> V_133 . V_454 = 0 ;
V_130 -> V_133 . V_455 = 0 ;
}
struct V_112 * F_266 ( struct V_1 * V_2 ,
enum V_456 V_457 , enum V_446 V_447 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_66 ( & V_2 -> V_155 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
F_265 ( V_2 , V_130 , V_457 , V_447 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_196 ) ;
F_68 ( 1 , L_197 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
}
return V_113 ;
}
void F_267 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_403 )
{
memcpy ( V_113 -> V_117 , V_458 , V_384 ) ;
memcpy ( F_268 ( V_113 -> V_117 ) , & V_403 , 1 ) ;
memcpy ( F_269 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_409 , V_364 ) ;
}
int F_270 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_377 )
{
int V_37 ;
char V_403 ;
F_4 ( V_2 , 4 , L_198 ) ;
if ( V_2 -> V_66 . V_301 )
if ( V_2 -> V_12 . type == V_18 )
V_403 = V_406 ;
else
V_403 = V_407 ;
else
V_403 = V_408 ;
F_267 ( V_2 , V_113 , V_403 ) ;
V_37 = F_190 ( V_2 , V_459 ,
V_113 , F_191 , V_377 ) ;
if ( V_37 == - V_319 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_37 ;
}
static int F_271 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_199 ) ;
V_113 = F_266 ( V_2 , V_144 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_270 ( V_2 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_200 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 )
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_460 . V_133 . V_139 ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_201 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_460 . V_117 . V_461 . V_462 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_460 . V_117 . V_461 . V_462 ;
F_45 ( V_65 , 2 , L_202 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_463 . V_464 =
V_130 -> V_117 . V_460 . V_117 . V_461 . V_465 ;
return F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_274 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_466 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_266 ( V_2 , V_467 ,
V_387 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_460 . V_133 . V_468 = V_466 ;
V_130 -> V_117 . V_460 . V_133 . V_469 = V_134 ;
V_130 -> V_117 . V_460 . V_133 . V_470 = 1 ;
V_130 -> V_117 . V_460 . V_133 . V_471 = 1 ;
}
return V_113 ;
}
int F_275 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_203 ) ;
V_113 = F_274 ( V_2 , V_472 ,
sizeof( struct V_473 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_270 ( V_2 , V_113 , F_273 , NULL ) ;
return V_37 ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_204 ) ;
V_130 = (struct V_129 * ) V_117 ;
switch ( V_130 -> V_133 . V_139 ) {
case V_474 :
case V_475 :
F_41 ( V_65 , 2 , L_205 ) ;
V_2 -> V_66 . V_476 . V_464 |= V_477 ;
V_2 -> V_66 . V_478 . V_464 |= V_477 ;
return - 0 ;
default:
if ( V_130 -> V_133 . V_139 ) {
F_68 ( 1 , L_206
L_207 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ,
V_130 -> V_133 . V_139 ) ;
return 0 ;
}
}
if ( V_130 -> V_133 . V_386 == V_387 ) {
V_2 -> V_66 . V_476 . V_464 = V_130 -> V_133 . V_454 ;
V_2 -> V_66 . V_476 . V_479 = V_130 -> V_133 . V_455 ;
} else if ( V_130 -> V_133 . V_386 == V_480 ) {
V_2 -> V_66 . V_478 . V_464 = V_130 -> V_133 . V_454 ;
V_2 -> V_66 . V_478 . V_479 = V_130 -> V_133 . V_455 ;
} else
F_68 ( 1 , L_208
L_209 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_277 ( struct V_1 * V_2 , enum V_446 V_447 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_210 , V_447 ) ;
V_113 = F_266 ( V_2 , V_481 , V_447 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_270 ( V_2 , V_113 , F_276 , NULL ) ;
return V_37 ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_482 * V_483 ;
struct V_484 * V_485 ;
F_4 ( V_2 , 2 , L_211 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_483 = (struct V_482 * ) V_125 -> V_380 ;
if ( V_130 -> V_117 . V_460 . V_133 . V_139 == 0 ) {
V_485 = & V_130 -> V_117 . V_460 . V_117 . V_486 ;
V_483 -> V_487 = V_485 -> V_487 ;
V_483 -> V_488 = V_485 -> V_488 ;
F_52 ( V_2 , 2 , L_212 , V_483 -> V_487 ,
V_483 -> V_488 ) ;
}
F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_484 ( struct V_1 * V_2 ,
struct V_482 * V_483 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_213 ) ;
if ( ! F_279 ( V_2 , V_489 ) )
return - V_334 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_490 ;
V_113 = F_274 ( V_2 , V_489 ,
sizeof( struct V_491 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_270 ( V_2 , V_113 ,
F_278 , V_483 ) ;
}
static int F_280 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_214 , V_37 ) ;
else
V_2 -> V_12 . V_492 = V_130 -> V_117 . V_493 . V_494 ;
return 0 ;
}
static int F_281 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_215 ) ;
V_113 = F_266 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_493 . V_495 = 16 ;
V_130 -> V_117 . V_493 . V_496 = V_497 ;
return F_270 ( V_2 , V_113 , F_280 , NULL ) ;
}
static void F_282 ( struct V_1 * V_2 , struct V_498 * V_499 )
{
unsigned long V_12 = F_283 ( V_49 ) ;
struct V_500 * V_501 = (struct V_500 * ) V_12 ;
struct V_502 * V_503 = (struct V_502 * ) V_12 ;
struct V_357 V_504 ;
int V_367 ;
V_499 -> V_142 = V_2 -> V_12 . V_142 ;
F_179 ( F_153 ( V_2 ) , & V_504 ) ;
V_499 -> V_505 = V_504 . V_505 ;
V_499 -> V_365 = V_504 . V_365 ;
if ( ! V_12 )
return;
V_367 = F_284 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_367 >= 2 ) && ( F_284 ( V_501 , 2 , 2 , 2 ) == 0 ) )
V_499 -> V_506 = V_501 -> V_507 ;
if ( ( V_367 >= 3 ) && ( F_284 ( V_503 , 3 , 2 , 2 ) == 0 ) ) {
F_285 ( V_503 -> V_508 [ 0 ] . V_509 , sizeof( V_503 -> V_508 [ 0 ] . V_509 ) ) ;
memcpy ( V_499 -> V_510 , V_503 -> V_508 [ 0 ] . V_509 , sizeof( V_499 -> V_510 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_286 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_216 , V_37 ) ;
return 0 ;
}
int F_287 ( struct V_1 * V_2 , enum V_511 V_512 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_217 ) ;
V_113 = F_266 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_493 . V_495 = 80 ;
V_130 -> V_117 . V_493 . V_496 = V_513 ;
V_130 -> V_117 . V_493 . type = 1 ;
V_130 -> V_117 . V_493 . V_512 = V_512 ;
switch ( V_512 ) {
case V_514 :
V_130 -> V_117 . V_493 . V_66 = 0x0003 ;
V_130 -> V_117 . V_493 . V_494 = 0x00010000 +
sizeof( struct V_498 ) ;
F_282 ( V_2 ,
(struct V_498 * ) V_130 -> V_117 . V_493 . V_515 ) ;
break;
case V_516 :
V_130 -> V_117 . V_493 . V_66 = 0x0001 ;
break;
case V_517 :
break;
}
return F_270 ( V_2 , V_113 , F_286 , NULL ) ;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_518 * V_231 ,
unsigned int V_519 ,
const char * V_520 )
{
if ( V_519 ) {
F_4 ( V_2 , 2 , V_520 ) ;
F_52 ( V_2 , 2 , L_218 ,
V_231 -> V_245 [ 15 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_219 ,
V_231 -> V_245 [ 14 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_220 , V_519 ) ;
if ( ( V_231 -> V_245 [ 15 ] . V_246 ) == 0x12 ) {
V_2 -> V_521 . V_522 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 , int V_169 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_417 ;
struct V_431 * V_523 ;
int V_167 ;
int V_44 ;
int V_37 ;
int V_524 = 0 ;
V_167 = ( V_169 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_169 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_169 ) ;
if ( V_167 >= F_290 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_167 ; ++ V_44 ) {
if ( F_261 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_524 ++ ;
}
}
if ( V_524 < V_167 ) {
F_60 ( & V_2 -> V_525 , 3 ) ;
V_167 = V_524 ;
} else {
F_291 ( & V_2 -> V_525 , - 1 , 0 ) ;
}
if ( ! V_167 ) {
V_44 = 0 ;
F_255 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_221 ) ;
V_2 -> V_526 = V_169 ;
F_292 (
& V_2 -> V_291 ,
V_527 ) ;
}
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_435 . V_528 ++ ;
V_2 -> V_435 . V_529 =
F_293 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_167 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_435 . V_530 +=
F_293 () -
V_2 -> V_435 . V_529 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_222 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_167 ) %
V_62 ;
}
}
static void V_292 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_291 . V_7 ) ;
F_52 ( V_2 , 2 , L_223 , V_2 -> V_526 ) ;
F_289 ( V_2 , V_2 -> V_526 ) ;
}
static void F_294 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_531 )
{
int V_83 = V_64 -> V_64 -> V_245 [ 15 ] . V_246 ;
F_4 ( V_2 , 6 , L_224 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_531 = 0 ;
} else {
V_531 = 1 ;
}
}
F_288 ( V_2 , V_64 -> V_64 , V_531 , L_225 ) ;
if ( ! V_531 )
return;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return;
F_4 ( V_2 , 1 , L_226 ) ;
F_52 ( V_2 , 1 , L_227 ,
( V_186 ) V_531 , ( V_277 ) V_83 ) ;
}
static void F_295 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_442 ) {
if ( F_51 ( & V_111 -> V_443 )
>= V_532 ) {
F_4 ( V_111 -> V_2 , 6 , L_228 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_435 . V_533 ++ ;
V_111 -> V_442 = 1 ;
}
}
}
static int F_296 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
int V_534 = 0 ;
if ( V_111 -> V_442 ) {
if ( F_51 ( & V_111 -> V_443 )
<= V_535 ) {
F_4 ( V_111 -> V_2 , 6 , L_229 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_435 . V_536 ++ ;
V_111 -> V_442 = 0 ;
V_64 = V_111 -> V_63 [ V_111 -> V_441 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) ==
V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 ,
V_107 ) ;
V_534 ++ ;
V_111 -> V_441 =
( V_111 -> V_441 + 1 ) %
V_62 ;
}
}
}
return V_534 ;
}
static int F_297 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_441 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_441 =
( V_111 -> V_441 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_298 ( struct V_92 * V_111 , int V_169 ,
int V_167 )
{
struct V_96 * V_231 ;
int V_37 ;
int V_44 ;
unsigned int V_537 ;
for ( V_44 = V_169 ; V_44 < V_169 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_231 = V_111 -> V_63 [ V_93 ] ;
V_231 -> V_64 -> V_245 [ V_231 -> V_255 - 1 ] . V_254 |=
V_440 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_416 = V_231 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_442 ) {
if ( ( F_51 ( & V_111 -> V_443 ) >=
( V_532 -
V_538 ) ) &&
! F_51 ( & V_111 -> V_248 ) ) {
F_76 ( & V_111 -> V_248 ) ;
V_231 -> V_64 -> V_245 [ 0 ] . V_246 |= V_247 ;
}
} else {
if ( ! F_51 ( & V_111 -> V_248 ) ) {
F_76 ( & V_111 -> V_248 ) ;
V_231 -> V_64 -> V_245 [ 0 ] . V_246 |= V_247 ;
}
}
}
F_299 ( V_111 -> V_2 -> V_9 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 ) {
V_111 -> V_2 -> V_435 . V_539 ++ ;
V_111 -> V_2 -> V_435 . V_540 =
F_293 () ;
}
V_537 = V_541 ;
if ( F_51 ( & V_111 -> V_248 ) )
V_537 |= V_542 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_537 ,
V_111 -> V_422 , V_169 , V_167 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_435 . V_543 +=
F_293 () -
V_111 -> V_2 -> V_435 . V_540 ;
F_300 ( V_167 , & V_111 -> V_443 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_521 . V_544 += V_167 ;
if ( V_37 == - V_545 )
return;
F_4 ( V_111 -> V_2 , 2 , L_230 ) ;
F_52 ( V_111 -> V_2 , 2 , L_231 , V_111 -> V_422 ) ;
F_52 ( V_111 -> V_2 , 2 , L_232 , V_169 ) ;
F_52 ( V_111 -> V_2 , 2 , L_233 , V_167 ) ;
F_52 ( V_111 -> V_2 , 2 , L_164 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_435 . V_546 += V_167 ;
}
static void F_301 ( struct V_92 * V_111 )
{
int V_169 ;
int V_547 = 0 ;
int V_548 = 0 ;
if ( ( F_51 ( & V_111 -> V_443 ) <= V_535 ) ||
! F_51 ( & V_111 -> V_248 ) ) {
if ( F_234 ( & V_111 -> V_3 , V_549 ) ==
V_444 ) {
F_302 ( V_111 -> V_2 -> V_9 ) ;
V_169 = V_111 -> V_441 ;
V_548 = V_111 -> V_442 ;
F_303 () ;
V_547 += F_296 ( V_111 ) ;
if ( ! V_547 &&
! F_51 ( & V_111 -> V_248 ) )
V_547 +=
F_297 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 &&
V_548 )
V_111 -> V_2 -> V_435 . V_550 +=
V_547 ;
if ( V_547 )
F_298 ( V_111 , V_169 , V_547 ) ;
F_60 ( & V_111 -> V_3 , V_444 ) ;
}
}
}
void F_304 ( struct V_158 * V_119 , int V_111 ,
unsigned long V_551 )
{
struct V_1 * V_2 = (struct V_1 * ) V_551 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_552 ) )
F_305 ( & V_2 -> V_553 ) ;
}
int F_306 ( struct V_1 * V_2 , enum V_554 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_555 ) {
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
F_133 ( V_2 ) ;
V_2 -> V_66 . V_67 = V_67 ;
V_37 = 0 ;
}
V_73:
return V_37 ;
}
static void F_307 ( struct V_1 * V_2 ,
unsigned int V_531 ,
unsigned int V_111 , int V_556 , int V_167 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_234 , V_556 ) ;
F_52 ( V_2 , 5 , L_235 , V_167 ) ;
F_52 ( V_2 , 5 , L_236 , V_531 ) ;
if ( V_531 ) {
F_302 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_435 . V_557 ++ ;
V_2 -> V_435 . V_558 = F_293 () ;
}
for ( V_44 = V_556 ; V_44 < V_556 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_518 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_559 ;
V_559 = 0 ;
while ( ( V_559 < V_560 ) &&
V_64 -> V_245 [ V_559 ] . V_250 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_245 [ V_559 ] . V_250 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_245 [ V_559 ] . V_250 = NULL ;
V_64 -> V_245 [ V_559 ] . V_254 = 0 ;
V_64 -> V_245 [ V_559 ] . V_246 = 0 ;
V_64 -> V_245 [ V_559 ] . V_253 = 0 ;
++ V_559 ;
}
V_64 -> V_245 [ 15 ] . V_254 = 0 ;
V_64 -> V_245 [ 15 ] . V_246 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_167 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_237 , V_37 ) ;
F_4 ( V_2 , 2 , L_238 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_167 ) % V_62 ;
F_308 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 ) {
int V_561 = F_293 () ;
V_561 -= V_2 -> V_435 . V_558 ;
V_2 -> V_435 . V_562 += V_561 ;
}
V_73:
return;
}
void F_309 ( struct V_158 * V_119 , unsigned int V_531 ,
unsigned int V_111 , int V_563 , int V_167 ,
unsigned long V_551 )
{
struct V_1 * V_2 = (struct V_1 * ) V_551 ;
F_52 ( V_2 , 2 , L_239 , V_111 ) ;
F_52 ( V_2 , 2 , L_240 , V_531 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_307 ( V_2 , V_531 , V_111 , V_563 , V_167 ) ;
else if ( V_531 )
F_72 ( V_2 ) ;
}
void F_310 ( struct V_158 * V_119 ,
unsigned int V_519 , int V_564 , int V_556 ,
int V_167 , unsigned long V_551 )
{
struct V_1 * V_2 = (struct V_1 * ) V_551 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_564 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_241 ) ;
if ( V_519 & V_565 ) {
F_4 ( V_2 , 2 , L_242 ) ;
F_302 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_435 . V_566 ++ ;
V_2 -> V_435 . V_567 =
F_293 () ;
}
for ( V_44 = V_556 ; V_44 < ( V_556 + V_167 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_294 ( V_2 , V_64 , V_519 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_568 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_569 ) ;
}
V_64 -> V_102 = V_111 -> V_81 [ V_93 ] . V_102 ;
F_52 ( V_111 -> V_2 , 5 , L_243 , V_93 ) ;
F_4 ( V_111 -> V_2 , 5 , L_244 ) ;
F_52 ( V_111 -> V_2 , 5 , L_43 ,
F_311 ( V_64 -> V_102 ) ) ;
if ( F_56 ( V_111 , V_93 ) ) {
F_4 ( V_2 , 2 , L_245 ) ;
F_72 ( V_2 ) ;
}
} else {
if ( V_2 -> V_66 . V_67 == V_68 ) {
enum V_82 V_85 ;
V_85 = F_49 (
V_64 -> V_64 -> V_245 [ 15 ] . V_246 , 0 ) ;
F_61 ( V_111 , V_64 , V_85 ) ;
}
F_62 ( V_111 , V_64 ,
V_249 ) ;
}
F_50 ( V_111 , V_93 , 0 ) ;
}
F_312 ( V_167 , & V_111 -> V_443 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_301 ( V_111 ) ;
F_308 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_435 . V_570 += F_293 () -
V_2 -> V_435 . V_567 ;
}
static inline int F_313 ( struct V_1 * V_2 , int V_571 )
{
if ( ( V_2 -> V_12 . type == V_15 ) && ( V_571 == 3 ) )
return 2 ;
return V_571 ;
}
int F_314 ( struct V_1 * V_2 , struct V_232 * V_233 ,
int V_572 , int V_573 )
{
T_3 * V_574 ;
V_277 V_575 ;
if ( V_573 && V_2 -> V_12 . V_313 )
return V_2 -> V_12 . V_313 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_303 ) {
case V_576 :
case V_577 :
switch ( V_572 ) {
case 4 :
V_575 = F_315 ( F_316 ( V_233 ) ) ;
break;
case 6 :
V_575 = F_317 ( F_318 ( V_233 ) ) ;
break;
default:
return V_2 -> V_46 . V_257 ;
}
if ( V_2 -> V_46 . V_303 == V_577 )
return F_313 ( V_2 , ~ V_575 >> 6 & 3 ) ;
if ( V_575 & V_578 )
return F_313 ( V_2 , 3 ) ;
if ( V_575 & V_579 )
return 2 ;
if ( V_575 & V_580 )
return 1 ;
if ( V_575 & V_581 )
return 0 ;
break;
case V_582 :
if ( V_233 -> V_583 > 5 )
return 0 ;
return F_313 ( V_2 , ~ V_233 -> V_583 >> 1 & 3 ) ;
case V_584 :
V_574 = & ( (struct V_585 * ) V_233 -> V_117 ) -> V_586 ;
if ( F_122 ( * V_574 ) == V_587 )
return F_313 ( V_2 ,
~ F_122 ( * ( V_574 + 1 ) ) >> ( V_588 + 1 ) & 3 ) ;
break;
default:
break;
}
return V_2 -> V_46 . V_257 ;
}
int F_319 ( struct V_232 * V_233 )
{
int V_177 , V_51 = 0 ;
for ( V_177 = 0 ; V_177 < F_320 ( V_233 ) -> V_589 ; V_177 ++ ) {
struct V_590 * V_591 = & F_320 ( V_233 ) -> V_592 [ V_177 ] ;
V_51 += F_321 (
( V_121 ) F_322 ( V_591 ) ,
( V_121 ) F_322 ( V_591 ) + F_323 ( V_591 ) ) ;
}
return V_51 ;
}
int F_324 ( struct V_1 * V_2 ,
struct V_232 * V_233 , int V_593 , int V_594 )
{
int V_51 = F_321 (
( V_121 ) V_233 -> V_117 + V_594 ,
( V_121 ) V_233 -> V_117 + F_325 ( V_233 ) ) +
F_319 ( V_233 ) ;
if ( ( V_51 + V_593 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_246
L_247 ,
V_51 + V_593 , V_233 -> V_163 ) ;
return 0 ;
}
return V_51 ;
}
int F_326 ( struct V_232 * V_233 , struct V_595 * * V_133 , int V_163 )
{
int V_596 , V_597 , V_598 ;
if ( ( ( unsigned long ) V_233 -> V_117 & V_599 ) !=
( ( ( unsigned long ) V_233 -> V_117 + V_163 - 1 ) & V_599 ) ) {
V_596 = F_327 ( V_233 ) ;
V_597 = V_401 - ( ( unsigned long ) V_233 -> V_117 % V_401 ) ;
V_598 = V_163 - V_597 ;
if ( V_598 > V_596 )
return 1 ;
memmove ( V_233 -> V_117 - V_598 , V_233 -> V_117 , F_325 ( V_233 ) ) ;
V_233 -> V_117 -= V_598 ;
V_233 -> V_600 -= V_598 ;
* V_133 = (struct V_595 * ) V_233 -> V_117 ;
F_68 ( 2 , L_248 , V_163 , V_598 ) ;
}
return 0 ;
}
static inline void F_328 ( struct V_232 * V_233 ,
struct V_518 * V_64 , int V_601 , int * V_255 ,
int V_184 )
{
int V_253 = F_325 ( V_233 ) ;
int V_602 ;
int V_245 ;
char * V_117 ;
int V_603 , V_177 ;
struct V_590 * V_591 ;
V_245 = * V_255 ;
V_117 = V_233 -> V_117 ;
V_603 = ( V_601 == 0 ? 1 : 0 ) ;
if ( V_184 >= 0 ) {
V_117 = V_233 -> V_117 + V_184 ;
V_253 -= V_184 ;
V_603 = 0 ;
}
while ( V_253 > 0 ) {
V_602 = V_401 - ( ( unsigned long ) V_117 % V_401 ) ;
if ( V_253 < V_602 )
V_602 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_602 ;
V_253 -= V_602 ;
if ( ! V_253 ) {
if ( V_603 )
if ( F_320 ( V_233 ) -> V_589 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_604 ;
else
V_64 -> V_245 [ V_245 ] . V_254 = 0 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_605 ;
} else {
if ( V_603 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_604 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_605 ;
}
V_117 += V_602 ;
V_245 ++ ;
V_603 = 0 ;
}
for ( V_177 = 0 ; V_177 < F_320 ( V_233 ) -> V_589 ; V_177 ++ ) {
V_591 = & F_320 ( V_233 ) -> V_592 [ V_177 ] ;
V_117 = ( char * ) F_329 ( F_330 ( V_591 ) ) +
V_591 -> V_606 ;
V_253 = V_591 -> V_607 ;
while ( V_253 > 0 ) {
V_602 = V_401 -
( ( unsigned long ) V_117 % V_401 ) ;
if ( V_253 < V_602 )
V_602 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_602 ;
V_64 -> V_245 [ V_245 ] . V_254 =
V_605 ;
V_253 -= V_602 ;
V_117 += V_602 ;
V_245 ++ ;
}
}
if ( V_64 -> V_245 [ V_245 - 1 ] . V_254 )
V_64 -> V_245 [ V_245 - 1 ] . V_254 = V_608 ;
* V_255 = V_245 ;
}
static inline int F_331 ( struct V_92 * V_111 ,
struct V_96 * V_231 , struct V_232 * V_233 ,
struct V_595 * V_133 , int V_184 , int V_609 )
{
struct V_518 * V_64 ;
int V_547 = 0 , V_610 , V_611 = 0 ;
V_64 = V_231 -> V_64 ;
F_76 ( & V_233 -> V_242 ) ;
F_332 ( & V_231 -> V_234 , V_233 ) ;
if ( V_133 -> V_133 . V_612 . V_308 == V_613 ) {
int V_245 = V_231 -> V_255 ;
V_610 = sizeof( struct V_614 ) +
( (struct V_614 * ) V_133 ) -> V_494 . V_615 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_233 -> V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_610 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_604 ;
V_231 -> V_255 ++ ;
V_233 -> V_117 += V_610 ;
V_233 -> V_163 -= V_610 ;
V_611 = 1 ;
}
if ( V_184 >= 0 ) {
int V_245 = V_231 -> V_255 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_133 ;
V_64 -> V_245 [ V_245 ] . V_253 = sizeof( struct V_595 ) +
V_609 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_604 ;
V_231 -> V_251 [ V_245 ] = 1 ;
V_231 -> V_255 ++ ;
}
F_328 ( V_233 , V_64 , V_611 ,
( int * ) & V_231 -> V_255 , V_184 ) ;
if ( ! V_111 -> V_442 ) {
F_4 ( V_111 -> V_2 , 6 , L_249 ) ;
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_547 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_250 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_435 . V_616 ++ ;
if ( V_231 -> V_255 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_547 = 1 ;
}
}
return V_547 ;
}
int F_333 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_232 * V_233 ,
struct V_595 * V_133 , int V_184 , int V_609 )
{
struct V_96 * V_64 ;
int V_169 ;
while ( F_59 ( & V_111 -> V_3 , V_444 ,
V_617 ) != V_444 ) ;
V_169 = V_111 -> V_441 ;
V_64 = V_111 -> V_63 [ V_111 -> V_441 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 )
goto V_73;
V_111 -> V_441 = ( V_111 -> V_441 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_444 ) ;
F_331 ( V_111 , V_64 , V_233 , V_133 , V_184 , V_609 ) ;
F_298 ( V_111 , V_169 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_444 ) ;
return - V_618 ;
}
int F_334 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_232 * V_233 , struct V_595 * V_133 ,
int V_619 )
{
struct V_96 * V_64 ;
int V_620 ;
int V_534 = 0 ;
int V_442 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_444 ,
V_617 ) != V_444 ) ;
V_620 = V_111 -> V_441 ;
V_64 = V_111 -> V_63 [ V_111 -> V_441 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 ) {
F_60 ( & V_111 -> V_3 , V_444 ) ;
return - V_618 ;
}
F_295 ( V_111 ) ;
if ( V_111 -> V_442 ) {
V_442 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_255 ) < V_619 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_534 ++ ;
V_111 -> V_441 =
( V_111 -> V_441 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_441 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_249 ) {
F_298 ( V_111 , V_620 ,
V_534 ) ;
F_60 ( & V_111 -> V_3 ,
V_444 ) ;
return - V_618 ;
}
}
}
V_41 = F_331 ( V_111 , V_64 , V_233 , V_133 , - 1 , 0 ) ;
V_111 -> V_441 = ( V_111 -> V_441 + V_41 ) %
V_62 ;
V_534 += V_41 ;
if ( V_534 )
F_298 ( V_111 , V_620 , V_534 ) ;
else if ( ! F_51 ( & V_111 -> V_248 ) )
F_234 ( & V_111 -> V_3 , V_549 ) ;
while ( F_335 ( & V_111 -> V_3 ) ) {
V_534 = 0 ;
V_620 = V_111 -> V_441 ;
V_534 += F_296 ( V_111 ) ;
if ( ! V_534 && ! F_51 ( & V_111 -> V_248 ) )
V_534 += F_297 ( V_111 ) ;
if ( V_534 )
F_298 ( V_111 , V_620 , V_534 ) ;
}
if ( V_111 -> V_2 -> V_66 . V_271 && V_442 )
V_111 -> V_2 -> V_435 . V_550 += V_534 ;
return V_37 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_473 * V_621 ;
F_4 ( V_2 , 4 , L_251 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_621 = & ( V_130 -> V_117 . V_460 ) ;
F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_252 , V_130 -> V_133 . V_139 ) ;
V_621 -> V_117 . V_622 = V_623 ;
}
V_2 -> V_12 . V_624 = V_621 -> V_117 . V_622 ;
return 0 ;
}
void F_337 ( struct V_1 * V_2 )
{
enum V_625 V_622 ;
struct V_626 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_253 ) ;
if ( ( ( V_9 -> V_32 & V_627 ) &&
( V_2 -> V_12 . V_624 == V_628 ) ) ||
( ! ( V_9 -> V_32 & V_627 ) &&
( V_2 -> V_12 . V_624 == V_623 ) ) )
return;
V_622 = V_623 ;
if ( V_9 -> V_32 & V_627 )
V_622 = V_628 ;
F_52 ( V_2 , 4 , L_254 , V_622 ) ;
V_113 = F_274 ( V_2 , V_629 ,
sizeof( struct V_491 ) + 8 ) ;
if ( ! V_113 )
return;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_460 . V_117 . V_622 = V_622 ;
F_270 ( V_2 , V_113 , F_336 , NULL ) ;
}
int F_338 ( struct V_626 * V_9 , int V_630 )
{
struct V_1 * V_2 ;
char V_631 [ 15 ] ;
V_2 = V_9 -> V_632 ;
F_4 ( V_2 , 4 , L_255 ) ;
sprintf ( V_631 , L_256 , V_630 ) ;
F_4 ( V_2 , 4 , V_631 ) ;
if ( ( ! F_339 ( V_2 , V_633 ) ) &&
( ! F_208 ( V_2 , V_630 ) ) )
return - V_399 ;
V_9 -> V_397 = V_630 ;
return 0 ;
}
struct V_634 * F_340 ( struct V_626 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_632 ;
F_4 ( V_2 , 5 , L_257 ) ;
return & V_2 -> V_521 ;
}
static int F_341 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_258 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_301 ||
! ( V_2 -> V_12 . V_635 & V_636 ) ) {
memcpy ( V_2 -> V_9 -> V_637 ,
& V_130 -> V_117 . V_460 . V_117 . V_638 . V_250 ,
V_639 ) ;
V_2 -> V_12 . V_635 |= V_636 ;
}
F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int F_342 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_259 ) ;
V_113 = F_274 ( V_2 , V_640 ,
sizeof( struct V_491 ) +
sizeof( struct V_641 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_460 . V_117 . V_638 . V_130 = V_642 ;
V_130 -> V_117 . V_460 . V_117 . V_638 . V_643 = V_639 ;
memcpy ( & V_130 -> V_117 . V_460 . V_117 . V_638 . V_250 ,
V_2 -> V_9 -> V_637 , V_639 ) ;
V_37 = F_270 ( V_2 , V_113 , F_341 ,
NULL ) ;
return V_37 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_644 * V_645 ;
int V_646 = * ( int * ) V_125 -> V_380 ;
F_4 ( V_2 , 4 , L_260 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_645 = & V_130 -> V_117 . V_460 . V_117 . V_647 ;
F_45 ( V_65 , 2 , L_260 ) ;
F_45 ( V_65 , 2 , L_261 , V_2 -> V_10 -> V_9 . V_648 . V_509 ) ;
F_45 ( V_65 , 2 , L_262 ,
V_130 -> V_117 . V_460 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_460 . V_133 . V_139 !=
V_649 )
F_68 ( 3 , L_263 ,
V_2 -> V_10 -> V_9 . V_648 . V_509 ,
V_645 -> V_650 ,
V_130 -> V_117 . V_460 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_460 . V_133 . V_139 ) {
case V_649 :
if ( V_2 -> V_66 . V_274 == V_275 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_264 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_265 ) ;
}
break;
case V_651 :
F_68 ( 2 , L_266
L_267 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_653 :
F_68 ( 2 , L_268
L_269 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_654 :
F_47 ( & V_2 -> V_10 -> V_9 , L_270
L_271 ) ;
break;
case V_655 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_272
L_273 ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_656 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_274 ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_657 :
F_47 ( & V_2 -> V_10 -> V_9 , L_275
L_276 ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_658 :
F_47 ( & V_2 -> V_10 -> V_9 , L_277
L_278 ) ;
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
case V_659 :
F_67 ( & V_2 -> V_10 -> V_9 , L_279
L_280 ) ;
break;
default:
if ( V_646 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_652 ;
break;
}
F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_344 ( struct V_1 * V_2 ,
enum V_660 V_274 , int V_646 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_644 * V_645 ;
F_4 ( V_2 , 4 , L_281 ) ;
F_45 ( V_65 , 2 , L_281 ) ;
F_45 ( V_65 , 2 , L_261 , V_2 -> V_10 -> V_9 . V_648 . V_509 ) ;
V_113 = F_274 ( V_2 , V_661 ,
sizeof( struct V_491 ) +
sizeof( struct V_644 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_645 = & V_130 -> V_117 . V_460 . V_117 . V_647 ;
V_645 -> V_650 = V_274 ;
V_37 = F_270 ( V_2 , V_113 , F_343 ,
& V_646 ) ;
F_45 ( V_65 , 2 , L_262 , V_37 ) ;
return V_37 ;
}
int F_345 ( struct V_1 * V_2 , int V_646 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_282 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_279 ( V_2 , V_661 ) ) {
V_37 = F_344 ( V_2 ,
V_2 -> V_66 . V_274 , V_646 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_283 ,
V_2 -> V_10 -> V_9 . V_648 . V_509 ,
V_37 ) ;
V_37 = - V_334 ;
}
} else if ( V_2 -> V_66 . V_274 != V_275 ) {
V_2 -> V_66 . V_274 = V_275 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_270
L_271 ) ;
V_37 = - V_334 ;
}
return V_37 ;
}
void F_346 ( struct V_626 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_632 ;
F_4 ( V_2 , 4 , L_284 ) ;
V_2 -> V_521 . V_544 ++ ;
F_72 ( V_2 ) ;
}
static int F_347 ( struct V_626 * V_9 , int V_662 , int V_663 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
int V_37 = 0 ;
switch ( V_663 ) {
case V_664 :
V_37 = V_665 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_666 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_667 ;
break;
case V_668 :
V_37 = V_669 | V_670 | V_671 |
V_672 | V_673 | V_674 | V_675 |
V_676 ;
break;
case V_677 :
V_37 = ( V_9 -> V_637 [ 0 ] << 16 ) | ( V_9 -> V_637 [ 1 ] << 8 ) |
V_9 -> V_637 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_678 :
V_37 = ( V_9 -> V_637 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_679 :
V_37 = V_680 ;
break;
case V_681 :
V_37 = V_682 | V_683 | V_684 | V_685 |
V_686 | V_687 ;
break;
case V_688 :
break;
case V_689 :
break;
case V_690 :
break;
case V_691 :
break;
case V_692 :
V_37 = V_2 -> V_521 . V_693 ;
break;
case V_694 :
break;
case V_695 :
break;
case V_696 :
break;
case V_697 :
break;
case V_698 :
break;
case V_699 :
break;
case V_700 :
break;
default:
break;
}
return V_37 ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_163 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_377 )
{
V_186 V_701 , V_702 ;
F_4 ( V_2 , 4 , L_285 ) ;
memcpy ( V_113 -> V_117 , V_458 , V_384 ) ;
memcpy ( F_269 ( V_113 -> V_117 ) ,
& V_2 -> V_348 . V_409 , V_364 ) ;
V_701 = ( V_703 ) V_384 + V_163 ;
V_702 = ( V_703 ) V_163 ;
memcpy ( F_349 ( V_113 -> V_117 ) , & V_701 , 2 ) ;
memcpy ( F_350 ( V_113 -> V_117 ) , & V_702 , 2 ) ;
memcpy ( F_351 ( V_113 -> V_117 ) , & V_702 , 2 ) ;
memcpy ( F_352 ( V_113 -> V_117 ) , & V_702 , 2 ) ;
return F_190 ( V_2 , V_384 + V_163 , V_113 ,
F_191 , V_377 ) ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_704 )
{
struct V_129 * V_130 ;
struct V_705 * V_706 ;
struct V_707 * V_708 ;
unsigned char * V_117 ;
V_185 V_709 ;
F_4 ( V_2 , 3 , L_286 ) ;
V_130 = (struct V_129 * ) V_704 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_184 ) ;
V_706 = (struct V_705 * ) V_125 -> V_380 ;
V_708 = & V_130 -> V_117 . V_460 . V_117 . V_708 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_287 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_460 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_460 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_288 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_709 = * ( ( V_185 * ) F_350 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_460 . V_133 . V_471 == 1 )
V_709 -= ( V_185 ) ( ( char * ) & V_708 -> V_117 - ( char * ) V_130 ) ;
else
V_709 -= ( V_185 ) ( ( char * ) & V_708 -> V_710 - ( char * ) V_130 ) ;
if ( ( V_706 -> V_711 - V_706 -> V_712 ) < V_709 ) {
F_52 ( V_2 , 4 , L_289 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_713 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_290 ,
V_130 -> V_117 . V_460 . V_133 . V_470 ) ;
F_52 ( V_2 , 4 , L_291 ,
V_130 -> V_117 . V_460 . V_133 . V_471 ) ;
if ( V_130 -> V_117 . V_460 . V_133 . V_471 == 1 ) {
memcpy ( V_706 -> V_714 + V_706 -> V_712 ,
( char * ) V_708 ,
V_709 + F_354 ( struct V_707 , V_117 ) ) ;
V_706 -> V_712 += F_354 ( struct V_707 , V_117 ) ;
} else {
memcpy ( V_706 -> V_714 + V_706 -> V_712 ,
( char * ) & V_708 -> V_710 , V_709 ) ;
}
V_706 -> V_712 += V_709 ;
F_52 ( V_2 , 4 , L_292 ,
V_130 -> V_117 . V_460 . V_133 . V_470 ) ;
F_52 ( V_2 , 4 , L_293 ,
V_130 -> V_117 . V_460 . V_133 . V_471 ) ;
if ( V_130 -> V_117 . V_460 . V_133 . V_471 <
V_130 -> V_117 . V_460 . V_133 . V_470 )
return 1 ;
return 0 ;
}
static int F_355 ( struct V_1 * V_2 , char T_4 * V_714 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_715 * V_716 ;
unsigned int V_717 ;
struct V_705 V_706 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_294 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_334 ;
if ( ( ! F_279 ( V_2 , V_718 ) ) &&
( ! V_2 -> V_66 . V_301 ) ) {
return - V_334 ;
}
if ( F_356 ( & V_717 , V_714 + sizeof( int ) , sizeof( int ) ) )
return - V_719 ;
if ( V_717 > ( V_118 - V_384 -
sizeof( struct V_720 ) -
sizeof( struct V_491 ) ) )
return - V_399 ;
V_716 = F_357 ( V_714 , V_717 + sizeof( struct V_721 ) ) ;
if ( F_116 ( V_716 ) ) {
F_4 ( V_2 , 2 , L_295 ) ;
return F_117 ( V_716 ) ;
}
V_706 . V_711 = V_716 -> V_133 . V_709 ;
V_706 . V_714 = F_27 ( V_706 . V_711 , V_49 ) ;
if ( ! V_706 . V_714 ) {
F_32 ( V_716 ) ;
return - V_50 ;
}
V_706 . V_712 = sizeof( struct V_721 ) ;
V_113 = F_274 ( V_2 , V_718 ,
V_722 + V_717 ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_73;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
memcpy ( & V_130 -> V_117 . V_460 . V_117 . V_708 , & V_716 -> V_130 , V_717 ) ;
V_37 = F_348 ( V_2 , V_113 , V_723 + V_717 ,
F_353 , ( void * ) & V_706 ) ;
if ( V_37 )
F_68 ( 2 , L_296 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_358 ( V_714 , V_706 . V_714 , V_706 . V_711 ) )
V_37 = - V_719 ;
}
V_73:
F_32 ( V_716 ) ;
F_32 ( V_706 . V_714 ) ;
return V_37 ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_724 * V_725 ;
char * V_726 ;
int V_727 ;
F_4 ( V_2 , 3 , L_297 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_725 = (struct V_724 * ) V_125 -> V_380 ;
V_727 = V_130 -> V_117 . V_460 . V_133 . V_468 ;
V_726 = ( char * ) V_117 + 28 ;
if ( V_727 > ( V_725 -> V_728 - V_725 -> V_729 ) ) {
V_130 -> V_133 . V_139 = V_730 ;
return 0 ;
}
memcpy ( ( V_725 -> V_64 + V_725 -> V_729 ) , V_726 ,
V_727 ) ;
V_725 -> V_729 += V_727 ;
if ( V_130 -> V_117 . V_460 . V_133 . V_471 <
V_130 -> V_117 . V_460 . V_133 . V_470 )
return 1 ;
return 0 ;
}
static int F_360 ( struct V_1 * V_2 , char T_4 * V_714 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_731 * V_732 ;
struct V_733 V_734 ;
struct V_724 V_725 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_298 ) ;
if ( ! F_279 ( V_2 , V_735 ) ) {
V_37 = - V_334 ;
goto V_73;
}
if ( F_356 ( & V_734 , V_714 ,
sizeof( struct V_733 ) ) ) {
V_37 = - V_719 ;
goto V_73;
}
V_725 . V_728 = V_734 . V_728 ;
V_725 . V_729 = 0 ;
V_725 . V_64 = F_27 ( V_734 . V_728 , V_49 ) ;
if ( ! V_725 . V_64 ) {
V_37 = - V_50 ;
goto V_73;
}
V_113 = F_274 ( V_2 , V_735 ,
sizeof( struct V_491 ) +
sizeof( struct V_731 ) ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_736;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_732 = & V_130 -> V_117 . V_460 . V_117 . V_737 ;
V_732 -> V_650 = V_734 . V_134 ;
V_37 = F_270 ( V_2 , V_113 , F_359 ,
& V_725 ) ;
if ( ! V_37 ) {
if ( F_361 () )
V_41 = F_362 ( V_734 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_734 . V_43 ;
if ( F_358 ( V_41 , V_725 . V_64 ,
V_725 . V_729 ) ) {
V_37 = - V_719 ;
goto V_736;
}
V_734 . V_729 = V_725 . V_729 ;
if ( F_358 ( V_714 , & V_734 ,
sizeof( struct V_733 ) ) )
V_37 = - V_719 ;
} else
if ( V_37 == V_730 )
V_37 = - V_719 ;
V_736:
F_32 ( V_725 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_363 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_738 * V_739 ;
struct V_740 * V_740 ;
F_4 ( V_2 , 2 , L_299 ) ;
V_740 = (struct V_740 * ) V_125 -> V_380 ;
V_130 = (struct V_129 * ) V_117 ;
V_739 = & V_130 -> V_117 . V_460 . V_117 . V_739 ;
if ( V_130 -> V_117 . V_460 . V_133 . V_139 == 0 ) {
V_740 -> V_741 = V_739 -> V_741 ;
V_740 -> V_742 = V_739 -> V_742 ;
V_740 -> V_743 = V_739 -> V_743 ;
}
F_272 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int V_738 ( struct V_1 * V_2 ,
struct V_740 * V_740 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_300 ) ;
if ( ! F_279 ( V_2 , V_744 ) )
return - V_334 ;
V_113 = F_274 ( V_2 , V_744 ,
sizeof( struct V_491 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_270 ( V_2 , V_113 , F_363 ,
( void * ) V_740 ) ;
}
static inline int F_364 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . type == V_15 )
return V_745 ;
else
return V_746 ;
}
static void F_365 ( struct V_1 * V_2 )
{
int V_37 ;
int V_253 ;
char * V_340 ;
struct V_158 * V_747 ;
int V_748 = 0 ;
F_41 ( V_65 , 2 , L_301 ) ;
V_747 = F_44 ( V_2 ) ;
if ( ! V_747 -> V_749 ) {
V_748 = 1 ;
V_37 = F_366 ( V_747 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_140 , V_37 ) ;
goto V_73;
}
}
V_37 = F_165 ( V_2 , ( void * * ) & V_340 , & V_253 ) ;
if ( V_37 ) {
F_68 ( 2 , L_302 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_750;
}
F_168 ( V_2 , V_340 ) ;
if ( V_748 )
F_169 ( V_2 , V_340 ) ;
F_32 ( V_340 ) ;
V_37 = F_367 ( V_747 , & V_2 -> V_751 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
F_45 ( V_65 , 2 , L_303 , V_2 -> V_751 . V_752 ) ;
F_45 ( V_65 , 2 , L_304 , V_2 -> V_751 . V_753 ) ;
F_45 ( V_65 , 2 , L_305 , V_2 -> V_751 . V_754 ) ;
F_45 ( V_65 , 2 , L_306 , V_2 -> V_751 . V_755 ) ;
F_45 ( V_65 , 2 , L_307 , V_2 -> V_751 . V_756 ) ;
if ( ! ( ( V_2 -> V_751 . V_752 != V_745 ) ||
( ( V_2 -> V_751 . V_753 & V_757 ) == 0 ) ||
( ( V_2 -> V_751 . V_755 & V_758 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_308 ) ;
} else {
V_2 -> V_66 . V_67 = V_555 ;
}
V_750:
if ( V_748 == 1 )
F_368 ( V_747 ) ;
V_73:
return;
}
static inline void F_369 ( struct V_1 * V_2 ,
struct V_518 * * V_759 ,
void (* * F_370) ( struct V_158 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_184 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_759 [ V_184 + V_44 ] = (struct V_518 * )
F_311 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_370 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_247 ( struct V_1 * V_2 )
{
struct V_760 V_761 ;
char * V_762 ;
struct V_518 * * V_759 ;
void (* * F_370) ( struct V_158 * , int , unsigned long );
struct V_518 * * V_763 ;
int V_44 , V_45 , V_764 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_309 ) ;
V_762 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_762 ) {
V_37 = - V_50 ;
goto V_765;
}
F_236 ( V_2 , V_762 ) ;
F_240 ( V_2 , V_762 ) ;
V_759 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_759 ) {
V_37 = - V_50 ;
goto V_766;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_759 [ V_44 ] = (struct V_518 * )
F_311 ( V_2 -> V_46 . V_417 -> V_63 [ V_44 ] . V_64 ) ;
}
F_370 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_370 ) {
V_37 = - V_50 ;
goto V_767;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_370 [ V_44 ] = V_2 -> V_149 -> V_768 ;
F_369 ( V_2 , V_759 , F_370 ) ;
V_763 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_763 ) {
V_37 = - V_50 ;
goto V_769;
}
for ( V_44 = 0 , V_764 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_764 ) {
V_763 [ V_764 ] = (struct V_518 * ) F_311 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_761 , 0 , sizeof( struct V_760 ) ) ;
V_761 . V_159 = F_44 ( V_2 ) ;
V_761 . V_770 = F_364 ( V_2 ) ;
V_761 . V_771 = 0 ;
V_761 . V_762 = V_762 ;
V_761 . V_772 = V_2 -> V_46 . V_72 ;
V_761 . V_773 = V_2 -> V_46 . V_78 ;
V_761 . V_774 = V_2 -> V_149 -> V_774 ;
V_761 . V_775 = V_2 -> V_149 -> V_775 ;
V_761 . V_776 = F_370 ;
V_761 . V_777 = ( unsigned long ) V_2 ;
V_761 . V_778 = ( void * * ) V_759 ;
V_761 . V_779 = ( void * * ) V_763 ;
V_761 . V_780 = V_2 -> V_46 . V_77 ;
V_761 . V_781 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_329 ,
V_325 ) == V_329 ) {
V_37 = F_371 ( & V_761 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_329 ) ;
goto V_73;
}
V_37 = F_372 ( & V_761 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_329 ) ;
F_248 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_310 ) ;
break;
case V_276 :
F_89 ( & V_2 -> V_10 -> V_9 , L_311 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_763 ) ;
V_769:
F_32 ( F_370 ) ;
V_767:
F_32 ( V_759 ) ;
V_766:
F_32 ( V_762 ) ;
V_765:
return V_37 ;
}
static void F_373 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_312 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_131 ( & V_2 -> V_114 ) ;
F_131 ( & V_2 -> V_155 ) ;
if ( V_2 -> V_9 )
F_374 ( V_2 -> V_9 ) ;
F_133 ( V_2 ) ;
F_375 ( & V_2 -> V_297 ) ;
F_32 ( V_2 ) ;
}
void F_376 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_313 ) ;
F_377 ( V_2 , 2 , & V_2 -> V_66 . V_476 , sizeof( V_2 -> V_66 . V_476 ) ) ;
F_377 ( V_2 , 2 , & V_2 -> V_66 . V_478 , sizeof( V_2 -> V_66 . V_478 ) ) ;
F_377 ( V_2 , 2 , & V_2 -> V_66 . V_463 , sizeof( V_2 -> V_66 . V_463 ) ) ;
F_377 ( V_2 , 2 , & V_2 -> V_12 . V_492 ,
sizeof( V_2 -> V_12 . V_492 ) ) ;
}
int F_378 ( struct V_1 * V_2 )
{
int V_782 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_314 ) ;
F_60 ( & V_2 -> V_525 , 0 ) ;
F_135 ( V_2 ) ;
V_783:
if ( V_782 < 3 )
F_68 ( 2 , L_315 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_163 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_368 ( F_44 ( V_2 ) ) ;
F_368 ( F_379 ( V_2 ) ) ;
F_368 ( F_153 ( V_2 ) ) ;
F_248 ( F_44 ( V_2 ) ) ;
V_37 = F_366 ( F_153 ( V_2 ) ) ;
if ( V_37 )
goto V_784;
V_37 = F_366 ( F_379 ( V_2 ) ) ;
if ( V_37 )
goto V_784;
V_37 = F_366 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_784;
V_784:
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_316 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_782 < 0 )
goto V_73;
else
goto V_783;
}
F_365 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
V_37 = F_174 ( & V_2 -> V_114 , F_186 ) ;
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_317 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_140 , V_37 ) ;
if ( -- V_782 < 0 )
goto V_73;
else
goto V_783;
}
V_37 = F_174 ( & V_2 -> V_155 , F_183 ) ;
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_318 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_185 , V_37 ) ;
if ( -- V_782 < 0 )
goto V_73;
else
goto V_783;
}
V_2 -> V_123 = 0 ;
V_37 = F_246 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_73;
}
V_37 = F_271 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
if ( V_37 == V_785 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_319 ) ;
V_2 -> V_143 = 0 ;
} else {
V_37 = - V_786 ;
goto V_73;
}
} else
V_2 -> V_143 = 1 ;
V_2 -> V_66 . V_476 . V_464 = 0 ;
V_2 -> V_66 . V_478 . V_464 = 0 ;
V_2 -> V_66 . V_463 . V_464 = 0 ;
V_2 -> V_66 . V_787 . V_464 = 0 ;
V_2 -> V_12 . V_492 = 0 ;
V_37 = F_277 ( V_2 , V_387 ) ;
if ( V_37 == - V_50 )
goto V_73;
if ( F_339 ( V_2 , V_477 ) ) {
V_37 = F_275 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_73;
}
}
if ( F_279 ( V_2 , V_788 ) ) {
V_37 = F_281 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_73;
}
}
return 0 ;
V_73:
F_67 ( & V_2 -> V_10 -> V_9 , L_106
L_107 ) ;
F_68 ( 2 , L_320 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
return V_37 ;
}
static inline int F_380 ( struct V_437 * V_789 ,
struct V_790 * V_245 ,
struct V_232 * * V_791 , int V_184 , int * V_792 , int V_709 )
{
struct V_433 * V_433 = F_258 ( V_245 -> V_250 ) ;
if ( * V_791 == NULL ) {
if ( V_789 -> V_424 ) {
* V_791 = V_789 -> V_424 ;
V_789 -> V_424 = NULL ;
} else {
* V_791 = F_262 ( V_438 + V_439 ) ;
if ( ! ( * V_791 ) )
return - V_50 ;
}
F_381 ( * V_791 , V_439 ) ;
if ( V_709 <= V_438 ) {
memcpy ( F_382 ( * V_791 , V_709 ) , V_245 -> V_250 + V_184 ,
V_709 ) ;
} else {
F_383 ( V_433 ) ;
memcpy ( F_382 ( * V_791 , V_438 ) ,
V_245 -> V_250 + V_184 , V_438 ) ;
F_384 ( * V_791 , * V_792 , V_433 ,
V_184 + V_438 ,
V_709 - V_438 ) ;
( * V_791 ) -> V_709 += V_709 - V_438 ;
( * V_791 ) -> V_163 += V_709 - V_438 ;
( * V_791 ) -> V_793 += V_709 - V_438 ;
( * V_792 ) ++ ;
}
} else {
F_383 ( V_433 ) ;
F_384 ( * V_791 , * V_792 , V_433 , V_184 , V_709 ) ;
( * V_791 ) -> V_709 += V_709 ;
( * V_791 ) -> V_163 += V_709 ;
( * V_791 ) -> V_793 += V_709 ;
( * V_792 ) ++ ;
}
return 0 ;
}
static inline int F_385 ( struct V_790 * V_794 )
{
return ( V_794 -> V_254 & V_440 ) ;
}
struct V_232 * F_386 ( struct V_1 * V_2 ,
struct V_437 * V_789 ,
struct V_790 * * V_795 , int * V_796 ,
struct V_595 * * V_133 )
{
struct V_790 * V_245 = * V_795 ;
struct V_518 * V_64 = V_789 -> V_64 ;
int V_184 = * V_796 ;
struct V_232 * V_233 = NULL ;
int V_797 = 0 ;
void * V_798 ;
int V_709 ;
int V_799 = 0 ;
int V_800 = 0 ;
int V_591 = 0 ;
if ( V_245 -> V_253 < V_184 + sizeof( struct V_595 ) ) {
if ( F_385 ( V_245 ) )
return NULL ;
V_245 ++ ;
V_184 = 0 ;
if ( V_245 -> V_253 < sizeof( struct V_595 ) )
return NULL ;
}
* V_133 = V_245 -> V_250 + V_184 ;
V_184 += sizeof( struct V_595 ) ;
switch ( ( * V_133 ) -> V_133 . V_801 . V_308 ) {
case V_802 :
V_797 = ( * V_133 ) -> V_133 . V_801 . V_803 ;
break;
case V_804 :
V_797 = ( * V_133 ) -> V_133 . V_612 . V_253 ;
V_799 = V_439 ;
break;
case V_805 :
V_797 = ( * V_133 ) -> V_133 . V_806 . V_807 ;
V_799 = sizeof( struct V_595 ) ;
break;
default:
break;
}
if ( ! V_797 )
return NULL ;
if ( ( ( V_797 >= V_2 -> V_66 . V_272 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_525 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_800 = 1 ;
} else {
V_233 = F_262 ( V_797 + V_799 ) ;
if ( ! V_233 )
goto V_808;
if ( V_799 )
F_381 ( V_233 , V_799 ) ;
}
V_798 = V_245 -> V_250 + V_184 ;
while ( V_797 ) {
V_709 = F_212 ( V_797 , ( int ) ( V_245 -> V_253 - V_184 ) ) ;
if ( V_709 ) {
if ( V_800 ) {
if ( F_380 ( V_789 , V_245 ,
& V_233 , V_184 , & V_591 , V_709 ) )
goto V_808;
} else {
memcpy ( F_382 ( V_233 , V_709 ) , V_798 ,
V_709 ) ;
}
}
V_797 -= V_709 ;
if ( V_797 ) {
if ( F_385 ( V_245 ) ) {
F_4 ( V_2 , 4 , L_321 ) ;
F_377 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_128 ( V_233 ) ;
V_2 -> V_521 . V_693 ++ ;
return NULL ;
}
V_245 ++ ;
V_184 = 0 ;
V_798 = V_245 -> V_250 ;
} else {
V_184 += V_709 ;
}
}
* V_795 = V_245 ;
* V_796 = V_184 ;
if ( V_800 && V_2 -> V_66 . V_271 ) {
V_2 -> V_435 . V_809 ++ ;
V_2 -> V_435 . V_810 += F_320 ( V_233 ) -> V_589 ;
}
return V_233 ;
V_808:
if ( F_387 () ) {
F_4 ( V_2 , 2 , L_322 ) ;
}
V_2 -> V_521 . V_522 ++ ;
return NULL ;
}
int F_388 ( struct V_811 * V_553 , int V_812 )
{
struct V_1 * V_2 = F_3 ( V_553 , struct V_1 , V_553 ) ;
int V_813 = 0 ;
struct V_437 * V_64 ;
int V_814 ;
int V_815 = V_812 ;
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_435 . V_816 ++ ;
V_2 -> V_435 . V_817 = F_293 () ;
}
while ( 1 ) {
if ( ! V_2 -> V_818 . V_819 ) {
V_2 -> V_818 . V_531 = 0 ;
V_2 -> V_818 . V_819 = F_389 (
V_2 -> V_117 . V_119 , 0 , & V_2 -> V_818 . V_820 ,
& V_2 -> V_818 . V_531 ) ;
if ( V_2 -> V_818 . V_819 <= 0 ) {
V_2 -> V_818 . V_819 = 0 ;
break;
}
V_2 -> V_818 . V_821 =
& V_2 -> V_46 . V_417 -> V_63 [ V_2 -> V_818 . V_820 ]
. V_64 -> V_245 [ 0 ] ;
V_2 -> V_818 . V_822 = 0 ;
}
while ( V_2 -> V_818 . V_819 ) {
V_64 = & V_2 -> V_46 . V_417 -> V_63 [ V_2 -> V_818 . V_820 ] ;
if ( ! ( V_2 -> V_818 . V_531 &&
F_288 ( V_2 , V_64 -> V_64 ,
V_2 -> V_818 . V_531 , L_323 ) ) )
V_813 +=
V_2 -> V_149 -> V_823 (
V_2 , V_815 , & V_814 ) ;
else
V_814 = 1 ;
if ( V_814 ) {
if ( V_2 -> V_66 . V_271 )
V_2 -> V_435 . V_824 ++ ;
F_252 ( V_2 ,
V_64 -> V_40 ) ;
F_289 ( V_2 , V_2 -> V_818 . V_820 ) ;
V_2 -> V_818 . V_819 -- ;
if ( V_2 -> V_818 . V_819 ) {
V_2 -> V_818 . V_820 =
( V_2 -> V_818 . V_820 + 1 ) %
V_62 ;
V_2 -> V_818 . V_821 =
& V_2 -> V_46 . V_417
-> V_63 [ V_2 -> V_818 . V_820 ]
. V_64 -> V_245 [ 0 ] ;
V_2 -> V_818 . V_822 = 0 ;
}
}
if ( V_813 >= V_812 )
goto V_73;
else
V_815 = V_812 - V_813 ;
}
}
F_390 ( V_553 ) ;
if ( F_391 ( V_2 -> V_117 . V_119 , 0 ) )
F_305 ( & V_2 -> V_553 ) ;
V_73:
if ( V_2 -> V_66 . V_271 )
V_2 -> V_435 . V_825 += F_293 () -
V_2 -> V_435 . V_817 ;
return V_813 ;
}
int F_392 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_200 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 ) {
V_130 -> V_133 . V_139 = V_130 -> V_117 . V_826 . V_133 . V_139 ;
if ( V_130 -> V_133 . V_386 == V_387 )
V_2 -> V_66 . V_476 . V_479 = V_130 -> V_133 . V_455 ;
if ( V_130 -> V_133 . V_386 == V_480 )
V_2 -> V_66 . V_478 . V_479 = V_130 -> V_133 . V_455 ;
}
return 0 ;
}
struct V_112 * F_393 ( struct V_1 * V_2 ,
enum V_827 V_828 ,
V_185 V_335 , V_185 V_163 ,
enum V_446 V_447 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_324 ) ;
V_113 = F_266 ( V_2 , V_829 , V_447 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
V_130 -> V_117 . V_826 . V_133 . V_830 = V_828 ;
V_130 -> V_117 . V_826 . V_133 . V_253 = 8 + V_163 ;
V_130 -> V_117 . V_826 . V_133 . V_469 = V_335 ;
V_130 -> V_117 . V_826 . V_133 . V_139 = 0 ;
V_130 -> V_117 . V_826 . V_133 . V_471 = 0 ;
}
return V_113 ;
}
int F_394 ( struct V_1 * V_2 ,
struct V_112 * V_113 , V_185 V_163 , long V_117 ,
int (* F_191)( struct V_1 * ,
struct V_124 * , unsigned long ) ,
void * V_377 )
{
int V_37 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_325 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_384 ) ;
if ( V_163 <= sizeof( T_1 ) )
V_130 -> V_117 . V_826 . V_117 . V_831 = ( T_1 ) V_117 ;
else
memcpy ( & V_130 -> V_117 . V_826 . V_117 , ( void * ) V_117 , V_163 ) ;
V_37 = F_270 ( V_2 , V_113 , F_191 , V_377 ) ;
return V_37 ;
}
int F_395 ( struct V_1 * V_2 ,
enum V_827 V_828 ,
V_185 V_335 , long V_117 )
{
int V_37 ;
int V_253 = 0 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 4 , L_326 ) ;
if ( V_117 )
V_253 = sizeof( T_1 ) ;
V_113 = F_393 ( V_2 , V_828 , V_335 ,
V_253 , V_387 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_394 ( V_2 , V_113 , V_253 , V_117 ,
F_392 , NULL ) ;
return V_37 ;
}
static void F_396 ( void )
{
int V_832 ;
for ( V_832 = 0 ; V_832 < V_833 ; V_832 ++ ) {
F_397 ( V_834 [ V_832 ] . V_308 ) ;
V_834 [ V_832 ] . V_308 = NULL ;
}
}
void F_398 ( T_5 * V_308 , int V_367 , char * V_835 , ... )
{
char V_836 [ 32 ] ;
T_6 args ;
if ( ! F_399 ( V_308 , V_367 ) )
return;
va_start ( args , V_835 ) ;
vsnprintf ( V_836 , sizeof( V_836 ) , V_835 , args ) ;
va_end ( args ) ;
F_400 ( V_308 , V_367 , V_836 ) ;
}
static int F_401 ( void )
{
int V_332 ;
int V_832 ;
for ( V_832 = 0 ; V_832 < V_833 ; V_832 ++ ) {
V_834 [ V_832 ] . V_308 = F_402 ( V_834 [ V_832 ] . V_509 ,
V_834 [ V_832 ] . V_837 ,
V_834 [ V_832 ] . V_838 ,
V_834 [ V_832 ] . V_163 ) ;
if ( V_834 [ V_832 ] . V_308 == NULL ) {
F_396 () ;
return - V_50 ;
}
V_332 = F_403 ( V_834 [ V_832 ] . V_308 , V_834 [ V_832 ] . V_839 ) ;
if ( V_332 ) {
F_396 () ;
return V_332 ;
}
F_404 ( V_834 [ V_832 ] . V_308 , V_834 [ V_832 ] . V_367 ) ;
}
return 0 ;
}
int F_405 ( struct V_1 * V_2 ,
enum V_840 V_149 )
{
int V_37 = 0 ;
F_406 ( & V_841 ) ;
switch ( V_149 ) {
case V_842 :
V_2 -> V_149 = F_407 (
F_408 ( V_843 ) , L_327 ) ;
break;
case V_844 :
V_2 -> V_149 = F_407 (
F_408 ( V_845 ) , L_328 ) ;
break;
}
if ( ! V_2 -> V_149 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_329
L_330 , V_149 ) ;
V_37 = - V_399 ;
}
F_409 ( & V_841 ) ;
return V_37 ;
}
void F_410 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_301 )
F_411 ( V_845 ) ;
else
F_411 ( V_843 ) ;
V_2 -> V_149 = NULL ;
}
static T_5 * F_412 ( char * V_509 )
{
struct V_846 * V_430 ;
T_5 * V_37 = NULL ;
F_406 ( & V_847 ) ;
F_251 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_430 -> V_848 , V_509 ) == 0 ) {
V_37 = V_430 -> V_849 ;
break;
}
}
F_409 ( & V_847 ) ;
return V_37 ;
}
static int F_413 ( struct V_1 * V_2 , char * V_509 )
{
struct V_846 * V_850 ;
V_2 -> V_851 = F_402 ( V_509 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_851 ) {
F_45 ( V_65 , 2 , L_261 , L_331 ) ;
goto V_852;
}
if ( F_403 ( V_2 -> V_851 , & V_853 ) )
goto V_854;
V_850 = F_27 ( sizeof( struct V_846 ) , V_49 ) ;
if ( ! V_850 )
goto V_854;
strncpy ( V_850 -> V_848 , V_509 , V_855 ) ;
V_850 -> V_849 = V_2 -> V_851 ;
F_406 ( & V_847 ) ;
F_33 ( & V_850 -> V_856 , & V_857 ) ;
F_409 ( & V_847 ) ;
return 0 ;
V_854:
F_397 ( V_2 -> V_851 ) ;
V_852:
return - V_50 ;
}
static void F_414 ( void )
{
struct V_846 * V_430 , * V_41 ;
F_406 ( & V_847 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_430 -> V_856 ) ;
F_397 ( V_430 -> V_849 ) ;
F_32 ( V_430 ) ;
}
F_409 ( & V_847 ) ;
}
static int F_415 ( struct V_160 * V_10 )
{
struct V_1 * V_2 ;
struct V_858 * V_9 ;
int V_37 ;
unsigned long V_32 ;
char V_848 [ V_855 ] ;
F_41 ( V_65 , 2 , L_332 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_416 ( V_9 ) )
return - V_786 ;
F_45 ( V_65 , 2 , L_261 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_150 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_859;
}
snprintf ( V_848 , sizeof( V_848 ) , L_333 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_851 = F_412 ( V_848 ) ;
if ( ! V_2 -> V_851 ) {
V_37 = F_413 ( V_2 , V_848 ) ;
if ( V_37 )
goto V_860;
}
V_2 -> V_114 . V_119 = V_10 -> V_159 [ 0 ] ;
V_2 -> V_155 . V_119 = V_10 -> V_159 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_159 [ 2 ] ;
F_417 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_159 [ 0 ] -> V_861 = F_118 ;
V_10 -> V_159 [ 1 ] -> V_861 = F_118 ;
V_10 -> V_159 [ 2 ] -> V_861 = F_118 ;
V_37 = F_152 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_140 , V_37 ) ;
goto V_860;
}
V_37 = F_143 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
goto V_860;
}
switch ( V_2 -> V_12 . type ) {
case V_18 :
case V_16 :
V_37 = F_405 ( V_2 , V_844 ) ;
if ( V_37 )
goto V_860;
V_10 -> V_9 . type = ( V_2 -> V_12 . type != V_18 )
? V_2 -> V_149 -> V_862
: & V_863 ;
V_37 = V_2 -> V_149 -> V_864 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_865;
break;
default:
V_10 -> V_9 . type = & V_866 ;
break;
}
F_418 ( & V_867 . V_868 , V_32 ) ;
F_102 ( & V_2 -> V_42 , & V_867 . V_42 ) ;
F_419 ( & V_867 . V_868 , V_32 ) ;
F_365 ( V_2 ) ;
return 0 ;
V_865:
F_410 ( V_2 ) ;
V_860:
F_373 ( V_2 ) ;
V_859:
F_420 ( V_9 ) ;
return V_37 ;
}
static void F_421 ( struct V_160 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_334 ) ;
if ( V_2 -> V_149 ) {
V_2 -> V_149 -> remove ( V_10 ) ;
F_410 ( V_2 ) ;
}
F_418 ( & V_867 . V_868 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_419 ( & V_867 . V_868 , V_32 ) ;
F_373 ( V_2 ) ;
F_417 ( & V_10 -> V_9 , NULL ) ;
F_420 ( & V_10 -> V_9 ) ;
return;
}
static int F_422 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
int V_869 ;
if ( ! V_2 -> V_149 ) {
if ( V_2 -> V_12 . type == V_15 )
V_869 = V_842 ;
else
V_869 = V_844 ;
V_37 = F_405 ( V_2 , V_869 ) ;
if ( V_37 )
goto V_852;
V_37 = V_2 -> V_149 -> V_864 ( V_2 -> V_10 ) ;
if ( V_37 ) {
F_410 ( V_2 ) ;
goto V_852;
}
}
V_37 = V_2 -> V_149 -> V_870 ( V_10 ) ;
V_852:
return V_37 ;
}
static int F_423 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
return V_2 -> V_149 -> V_871 ( V_10 ) ;
}
static void F_424 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_16 ( V_2 , 0 , 1 ) ;
if ( ( V_10 -> V_3 == V_872 ) && V_2 -> V_12 . V_145 )
F_287 ( V_2 , V_516 ) ;
F_163 ( V_2 , 0 ) ;
F_130 ( V_2 ) ;
F_248 ( F_44 ( V_2 ) ) ;
}
static int F_425 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_873 )
return V_2 -> V_149 -> V_873 ( V_10 ) ;
return 0 ;
}
static int F_426 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_874 )
return V_2 -> V_149 -> V_874 ( V_10 ) ;
return 0 ;
}
static int F_427 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_875 )
return V_2 -> V_149 -> V_875 ( V_10 ) ;
return 0 ;
}
static T_7 F_428 ( struct V_876 * V_877 ,
const char * V_231 , T_8 V_167 )
{
int V_852 ;
V_852 = F_429 ( V_878 ,
& V_879 , 3 , V_231 ) ;
return V_852 ? V_852 : V_167 ;
}
int F_430 ( struct V_626 * V_9 , struct V_880 * V_881 , int V_130 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
struct V_882 * V_883 ;
int V_37 = 0 ;
if ( ! V_2 )
return - V_786 ;
if ( ! F_1 ( V_2 ) )
return - V_786 ;
if ( V_2 -> V_12 . type == V_18 )
return - V_57 ;
switch ( V_130 ) {
case V_884 :
V_37 = F_355 ( V_2 , V_881 -> V_885 . V_886 ) ;
break;
case V_887 :
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_16 ||
V_2 -> V_12 . type == V_17 ) &&
! V_2 -> V_12 . V_13 )
return 1 ;
else
return 0 ;
case V_888 :
V_883 = F_431 ( V_881 ) ;
V_883 -> V_662 = 0 ;
break;
case V_889 :
V_883 = F_431 ( V_881 ) ;
if ( V_883 -> V_662 != 0 )
V_37 = - V_399 ;
else
V_883 -> V_890 = F_347 ( V_9 ,
V_883 -> V_662 , V_883 -> V_891 ) ;
break;
case V_892 :
V_37 = F_360 ( V_2 , V_881 -> V_885 . V_886 ) ;
break;
default:
if ( V_2 -> V_149 -> V_893 )
V_37 = V_2 -> V_149 -> V_893 ( V_9 , V_881 , V_130 ) ;
else
V_37 = - V_334 ;
}
if ( V_37 )
F_52 ( V_2 , 2 , L_335 , V_37 ) ;
return V_37 ;
}
int F_432 ( struct V_626 * V_9 , int V_894 )
{
switch ( V_894 ) {
case V_895 :
return ( sizeof( V_896 ) / V_897 ) ;
default:
return - V_399 ;
}
}
void F_433 ( struct V_626 * V_9 ,
struct V_898 * V_521 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
V_117 [ 0 ] = V_2 -> V_521 . V_899 -
V_2 -> V_435 . V_900 ;
V_117 [ 1 ] = V_2 -> V_435 . V_824 ;
V_117 [ 2 ] = V_2 -> V_521 . V_901 -
V_2 -> V_435 . V_902 ;
V_117 [ 3 ] = V_2 -> V_435 . V_546 ;
V_117 [ 4 ] = V_2 -> V_521 . V_901 - V_2 -> V_435 . V_902
- V_2 -> V_435 . V_616 ;
V_117 [ 5 ] = V_2 -> V_435 . V_546 - V_2 -> V_435 . V_550 ;
V_117 [ 6 ] = V_2 -> V_435 . V_616 ;
V_117 [ 7 ] = V_2 -> V_435 . V_550 ;
V_117 [ 8 ] = V_2 -> V_435 . V_903 ;
V_117 [ 9 ] = V_2 -> V_435 . V_904 ;
V_117 [ 10 ] = V_2 -> V_435 . V_809 ;
V_117 [ 11 ] = V_2 -> V_435 . V_810 ;
V_117 [ 12 ] = V_2 -> V_435 . V_436 ;
V_117 [ 13 ] = ( V_2 -> V_435 . V_905 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_435 . V_906 ;
V_117 [ 15 ] = V_2 -> V_435 . V_533 ;
V_117 [ 16 ] = V_2 -> V_435 . V_536 ;
V_117 [ 17 ] = V_535 ;
V_117 [ 18 ] = V_532 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_443 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_443 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_443 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_443 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_435 . V_825 ;
V_117 [ 24 ] = V_2 -> V_435 . V_816 ;
V_117 [ 25 ] = V_2 -> V_435 . V_530 ;
V_117 [ 26 ] = V_2 -> V_435 . V_528 ;
V_117 [ 27 ] = V_2 -> V_435 . V_570 ;
V_117 [ 28 ] = V_2 -> V_435 . V_566 ;
V_117 [ 29 ] = V_2 -> V_435 . V_907 ;
V_117 [ 30 ] = V_2 -> V_435 . V_908 ;
V_117 [ 31 ] = V_2 -> V_435 . V_543 ;
V_117 [ 32 ] = V_2 -> V_435 . V_539 ;
V_117 [ 33 ] = V_2 -> V_435 . V_909 ;
V_117 [ 34 ] = V_2 -> V_435 . V_910 ;
V_117 [ 35 ] = V_2 -> V_435 . V_911 ;
V_117 [ 36 ] = V_2 -> V_435 . V_557 ;
V_117 [ 37 ] = V_2 -> V_435 . V_562 ;
}
void F_434 ( struct V_626 * V_9 , V_703 V_894 , V_277 * V_117 )
{
switch ( V_894 ) {
case V_895 :
memcpy ( V_117 , & V_896 ,
sizeof( V_896 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_435 ( struct V_626 * V_9 ,
struct V_912 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
F_436 ( V_12 -> V_913 , V_2 -> V_66 . V_301 ? L_328 : L_327 ,
sizeof( V_12 -> V_913 ) ) ;
F_436 ( V_12 -> V_914 , L_336 , sizeof( V_12 -> V_914 ) ) ;
F_436 ( V_12 -> V_915 , V_2 -> V_12 . V_298 ,
sizeof( V_12 -> V_915 ) ) ;
snprintf ( V_12 -> V_916 , sizeof( V_12 -> V_916 ) , L_337 ,
F_437 ( V_2 ) , F_438 ( V_2 ) , F_439 ( V_2 ) ) ;
}
static void F_440 ( struct V_917 * V_130 ,
int V_918 , int V_919 )
{
F_441 ( V_130 , V_920 ) ;
F_441 ( V_130 , V_921 ) ;
F_441 ( V_130 , V_922 ) ;
F_442 ( V_130 , V_920 , V_923 ) ;
F_442 ( V_130 , V_921 , V_923 ) ;
switch ( V_919 ) {
case V_924 :
F_442 ( V_130 , V_920 , V_925 ) ;
F_442 ( V_130 , V_921 , V_925 ) ;
break;
case V_926 :
F_442 ( V_130 , V_920 , V_927 ) ;
F_442 ( V_130 , V_921 , V_927 ) ;
break;
default:
F_442 ( V_130 , V_920 , V_925 ) ;
F_442 ( V_130 , V_921 , V_925 ) ;
F_54 ( 1 ) ;
}
switch ( V_918 ) {
case V_928 :
F_442 ( V_130 , V_920 ,
10000baseT_Full ) ;
F_442 ( V_130 , V_921 ,
10000baseT_Full ) ;
case V_929 :
F_442 ( V_130 , V_920 ,
1000baseT_Full ) ;
F_442 ( V_130 , V_921 ,
1000baseT_Full ) ;
F_442 ( V_130 , V_920 ,
1000baseT_Half ) ;
F_442 ( V_130 , V_921 ,
1000baseT_Half ) ;
case V_930 :
F_442 ( V_130 , V_920 ,
100baseT_Full ) ;
F_442 ( V_130 , V_921 ,
100baseT_Full ) ;
F_442 ( V_130 , V_920 ,
100baseT_Half ) ;
F_442 ( V_130 , V_921 ,
100baseT_Half ) ;
case V_931 :
F_442 ( V_130 , V_920 ,
10baseT_Full ) ;
F_442 ( V_130 , V_921 ,
10baseT_Full ) ;
F_442 ( V_130 , V_920 ,
10baseT_Half ) ;
F_442 ( V_130 , V_921 ,
10baseT_Half ) ;
break;
default:
F_442 ( V_130 , V_920 ,
10baseT_Full ) ;
F_442 ( V_130 , V_921 ,
10baseT_Full ) ;
F_442 ( V_130 , V_920 ,
10baseT_Half ) ;
F_442 ( V_130 , V_921 ,
10baseT_Half ) ;
F_54 ( 1 ) ;
}
}
int F_443 ( struct V_626 * V_932 ,
struct V_917 * V_130 )
{
struct V_1 * V_2 = V_932 -> V_632 ;
enum V_445 V_19 ;
struct V_740 V_740 ;
int V_37 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_130 -> V_933 . V_934 = V_935 ;
V_130 -> V_933 . V_936 = V_937 ;
V_130 -> V_933 . V_938 = 0 ;
V_130 -> V_933 . V_939 = 0 ;
V_130 -> V_933 . V_940 = V_941 ;
V_130 -> V_933 . V_942 = V_941 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
V_130 -> V_933 . V_943 = V_930 ;
V_130 -> V_933 . V_944 = V_924 ;
break;
case V_22 :
case V_26 :
V_130 -> V_933 . V_943 = V_929 ;
V_130 -> V_933 . V_944 = V_926 ;
break;
case V_23 :
V_130 -> V_933 . V_943 = V_928 ;
V_130 -> V_933 . V_944 = V_926 ;
break;
default:
V_130 -> V_933 . V_943 = V_931 ;
V_130 -> V_933 . V_944 = V_924 ;
}
F_440 ( V_130 , V_130 -> V_933 . V_943 , V_130 -> V_933 . V_944 ) ;
if ( ! F_1 ( V_2 ) )
return - V_786 ;
V_37 = V_738 ( V_2 , & V_740 ) ;
if ( V_37 == - V_334 )
return 0 ;
if ( V_37 )
return V_37 ;
F_444 ( V_932 ,
L_338 ,
V_740 . V_741 ,
V_740 . V_742 ,
V_740 . V_743 ) ;
switch ( V_740 . V_741 ) {
case V_945 :
case V_946 :
V_130 -> V_933 . V_944 = V_924 ;
F_440 ( V_130 , V_929 , V_130 -> V_933 . V_944 ) ;
break;
case V_947 :
case V_948 :
V_130 -> V_933 . V_944 = V_926 ;
F_440 ( V_130 , V_929 , V_130 -> V_933 . V_944 ) ;
break;
case V_949 :
case V_950 :
V_130 -> V_933 . V_944 = V_926 ;
F_440 ( V_130 , V_928 , V_130 -> V_933 . V_944 ) ;
break;
}
switch ( V_740 . V_742 ) {
case V_951 :
V_130 -> V_933 . V_934 = V_935 ;
break;
case V_952 :
V_130 -> V_933 . V_934 = V_953 ;
break;
}
switch ( V_740 . V_743 ) {
case V_954 :
V_130 -> V_933 . V_943 = V_931 ;
break;
case V_955 :
V_130 -> V_933 . V_943 = V_930 ;
break;
case V_956 :
V_130 -> V_933 . V_943 = V_929 ;
break;
case V_957 :
V_130 -> V_933 . V_943 = V_928 ;
break;
}
return 0 ;
}
static int F_445 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_129 * V_130 = (struct V_129 * ) V_117 ;
struct V_958 * V_959 =
(struct V_958 * ) V_125 -> V_380 ;
F_4 ( V_2 , 4 , L_339 ) ;
if ( V_130 -> V_133 . V_139 )
return 0 ;
memset ( V_959 , 0 , sizeof( * V_959 ) ) ;
if ( V_130 -> V_117 . V_826 . V_133 . V_469 == V_960 ) {
V_959 -> V_920 =
V_130 -> V_117 . V_826 . V_117 . V_961 . V_920 ;
F_52 ( V_2 , 3 , L_340 , V_959 -> V_920 ) ;
}
if ( V_130 -> V_117 . V_826 . V_133 . V_469 == V_962 ) {
V_959 -> V_920 =
V_130 -> V_117 . V_826 . V_117 . V_961 . V_920 ;
V_959 -> V_288 =
V_130 -> V_117 . V_826 . V_117 . V_961 . V_288 ;
F_52 ( V_2 , 3 , L_341 , V_959 -> V_920 ) ;
F_52 ( V_2 , 3 , L_342 , V_959 -> V_288 ) ;
}
return 0 ;
}
static int F_446 ( struct V_1 * V_2 ,
enum V_827 V_828 ,
V_185 V_335 , long V_117 ,
struct V_958 * V_959 )
{
struct V_112 * V_113 ;
int V_37 = - V_50 ;
F_4 ( V_2 , 4 , L_343 ) ;
V_113 = F_393 ( V_2 , V_828 , V_335 ,
sizeof( T_1 ) , V_387 ) ;
if ( V_113 )
V_37 = F_394 ( V_2 , V_113 , sizeof( T_1 ) , V_117 ,
F_445 ,
V_959 ) ;
return V_37 ;
}
static int F_447 ( struct V_1 * V_2 , int V_963 )
{
const T_1 V_964 = V_965 |
V_966 |
V_967 ;
struct V_958 V_959 ;
int V_37 ;
V_37 = F_446 ( V_2 , V_963 , V_960 , 0 ,
& V_959 ) ;
if ( ! V_37 ) {
if ( ( V_964 & V_959 . V_920 ) !=
V_964 )
V_37 = - V_116 ;
else if ( ! ( V_968 & V_959 . V_920 ) &&
V_963 == V_969 )
F_67 ( & V_2 -> V_10 -> V_9 ,
L_344 ,
F_81 ( V_2 ) ) ;
}
if ( V_37 ) {
F_395 ( V_2 , V_963 , V_970 , 0 ) ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_345 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
V_37 = F_446 ( V_2 , V_963 , V_962 ,
V_959 . V_920 , & V_959 ) ;
if ( ! V_37 ) {
if ( ( V_964 & V_959 . V_288 ) !=
V_964 )
V_37 = - V_116 ;
}
if ( V_37 ) {
F_395 ( V_2 , V_963 , V_970 , 0 ) ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_346 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
F_89 ( & V_2 -> V_10 -> V_9 , L_347 ,
V_963 == V_969 ? L_348 : L_349 ) ;
return 0 ;
}
static int F_448 ( struct V_1 * V_2 , int V_971 , int V_963 )
{
int V_37 = ( V_971 ) ? F_447 ( V_2 , V_963 )
: F_395 ( V_2 , V_963 ,
V_970 , 0 ) ;
return V_37 ? - V_116 : 0 ;
}
static int F_449 ( struct V_1 * V_2 , int V_971 )
{
int V_37 ;
F_4 ( V_2 , 3 , L_350 ) ;
if ( V_971 ) {
V_37 = F_395 ( V_2 , V_972 ,
V_960 , 0 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_351 ,
F_81 ( V_2 ) ) ;
return - V_116 ;
}
F_89 ( & V_2 -> V_10 -> V_9 , L_352 ) ;
} else {
V_37 = F_395 ( V_2 , V_972 ,
V_970 , 0 ) ;
}
return V_37 ;
}
int F_450 ( struct V_626 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
T_10 V_280 = V_9 -> V_973 ;
if ( V_280 & V_974 ) {
if ( F_448 ( V_2 , 1 , V_975 ) )
V_280 ^= V_974 ;
}
if ( V_280 & V_976 ) {
if ( F_448 ( V_2 , 1 , V_969 ) )
V_280 ^= V_976 ;
}
if ( V_280 & V_977 ) {
if ( F_449 ( V_2 , 1 ) )
V_280 ^= V_977 ;
}
if ( V_280 == V_9 -> V_973 )
return 0 ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_353 ) ;
V_9 -> V_973 = V_280 ;
return - V_116 ;
}
int F_451 ( struct V_626 * V_9 , T_10 V_973 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
T_10 V_978 = V_9 -> V_973 ^ V_973 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_354 ) ;
F_39 ( V_65 , 2 , & V_973 , sizeof( V_973 ) ) ;
if ( ( V_978 & V_974 ) ) {
V_37 = F_448 ( V_2 ,
V_973 & V_974 ? 1 : 0 ,
V_975 ) ;
if ( V_37 )
V_978 ^= V_974 ;
}
if ( ( V_978 & V_976 ) ) {
V_37 = F_448 ( V_2 ,
V_973 & V_976 ? 1 : 0 ,
V_969 ) ;
if ( V_37 )
V_978 ^= V_976 ;
}
if ( ( V_978 & V_977 ) ) {
V_37 = F_449 ( V_2 , V_973 & V_977 ? 1 : 0 ) ;
if ( V_37 )
V_978 ^= V_977 ;
}
if ( ( V_9 -> V_973 ^ V_973 ) == V_978 )
return 0 ;
V_9 -> V_973 ^= V_978 ;
return - V_116 ;
}
T_10 F_452 ( struct V_626 * V_9 ,
T_10 V_973 )
{
struct V_1 * V_2 = V_9 -> V_632 ;
F_41 ( V_65 , 2 , L_355 ) ;
if ( ! F_339 ( V_2 , V_975 ) )
V_973 &= ~ V_974 ;
if ( ! F_339 ( V_2 , V_969 ) )
V_973 &= ~ V_976 ;
if ( ! F_339 ( V_2 , V_972 ) ) {
V_973 &= ~ V_977 ;
F_89 ( & V_2 -> V_10 -> V_9 , L_356 ,
F_81 ( V_2 ) ) ;
}
if ( V_2 -> V_3 == V_55 ||
V_2 -> V_3 == V_56 )
V_973 = V_973 & ~ ( V_974 | V_976 |
V_977 ) ;
F_39 ( V_65 , 2 , & V_973 , sizeof( V_973 ) ) ;
return V_973 ;
}
static int T_11 F_453 ( void )
{
int V_37 ;
F_454 ( L_357 ) ;
F_138 ( & V_867 . V_42 ) ;
F_138 ( & V_857 ) ;
F_455 ( & V_867 . V_868 ) ;
F_144 ( & V_841 ) ;
V_11 = F_456 ( L_358 ) ;
V_37 = F_401 () ;
if ( V_37 )
goto V_979;
V_878 = F_457 ( L_359 ) ;
V_37 = F_458 ( V_878 ) ;
if ( V_37 )
goto V_980;
V_252 = F_459 ( L_360 ,
sizeof( struct V_595 ) + V_439 , 64 , 0 , NULL ) ;
if ( ! V_252 ) {
V_37 = - V_50 ;
goto V_981;
}
V_101 = F_459 ( L_361 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_982;
}
V_37 = F_460 ( & V_983 ) ;
if ( V_37 )
goto V_984;
V_879 . V_913 . V_985 = V_986 ;
V_37 = F_461 ( & V_879 ) ;
if ( V_37 )
goto V_987;
return 0 ;
V_987:
F_462 ( & V_983 ) ;
V_984:
F_463 ( V_101 ) ;
V_982:
F_463 ( V_252 ) ;
V_981:
F_464 ( V_878 ) ;
V_980:
F_396 () ;
V_979:
F_465 ( L_362 ) ;
return V_37 ;
}
static void T_12 F_466 ( void )
{
F_414 () ;
F_467 ( V_11 ) ;
F_468 ( & V_879 ) ;
F_462 ( & V_983 ) ;
F_463 ( V_101 ) ;
F_463 ( V_252 ) ;
F_464 ( V_878 ) ;
F_396 () ;
F_454 ( L_363 ) ;
}
