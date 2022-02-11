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
F_129 ( & V_111 -> V_248 ) ;
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
static void F_130 ( struct V_92 * V_60 , int free )
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
void F_131 ( struct V_1 * V_2 )
{
int V_44 ;
F_4 ( V_2 , 2 , L_113 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
if ( V_2 -> V_46 . V_80 [ V_44 ] ) {
F_130 ( V_2 -> V_46 . V_80 [ V_44 ] , 0 ) ;
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
static void F_132 ( struct V_161 * V_162 )
{
int V_177 ;
F_41 ( V_65 , 2 , L_114 ) ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ )
F_32 ( V_162 -> V_113 [ V_177 ] . V_117 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 4 ) )
F_134 ( V_2 ) ;
V_2 -> V_46 . V_78 = 1 ;
if ( V_2 -> V_46 . V_257 != 0 )
F_89 ( & V_2 -> V_10 -> V_9 , L_115 ) ;
V_2 -> V_46 . V_257 = 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 1 ) ) {
F_134 ( V_2 ) ;
V_2 -> V_46 . V_257 = 2 ;
}
V_2 -> V_46 . V_78 = 4 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_158 * V_119 ;
struct V_258 * V_259 ;
F_41 ( V_65 , 2 , L_116 ) ;
V_119 = V_2 -> V_117 . V_119 ;
V_259 = F_137 ( V_119 , 0 ) ;
if ( ! V_259 )
goto V_73;
V_2 -> V_12 . V_260 = 0x4100 + V_259 -> V_261 ;
if ( V_2 -> V_12 . type == V_15 )
goto V_73;
if ( ( V_259 -> V_262 & 0x02 ) == 0x02 )
F_133 ( V_2 ) ;
else
F_135 ( V_2 ) ;
V_73:
F_32 ( V_259 ) ;
F_45 ( V_65 , 2 , L_117 , V_2 -> V_46 . V_78 ) ;
F_45 ( V_65 , 2 , L_118 , V_2 -> V_12 . V_260 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 4 , L_119 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
V_2 -> V_46 . V_263 = V_264 ;
if ( V_2 -> V_12 . type == V_15 )
V_2 -> V_46 . V_47 . V_48 = V_265 ;
else
V_2 -> V_46 . V_47 . V_48 = V_266 ;
V_2 -> V_46 . V_58 . V_48 = V_2 -> V_46 . V_47 . V_48 ;
F_139 ( & V_2 -> V_46 . V_58 . V_53 ) ;
F_139 ( & V_2 -> V_46 . V_47 . V_53 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
V_2 -> V_66 . V_267 . type = V_268 ;
V_2 -> V_66 . V_269 . type = V_268 ;
V_2 -> V_66 . V_270 = 0 ;
V_2 -> V_66 . V_271 = 0 ;
V_2 -> V_66 . V_272 = V_273 ;
V_2 -> V_66 . V_274 = V_275 ;
V_2 -> V_66 . V_67 = V_276 ;
}
static int F_141 ( struct V_1 * V_2 , unsigned long V_191 )
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
static void F_142 ( struct V_6 * V_7 )
{
struct V_278 * V_279 ;
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_193 ) ;
F_4 ( V_2 , 2 , L_121 ) ;
if ( V_2 -> V_114 . V_3 != V_115 &&
V_2 -> V_155 . V_3 != V_115 )
return;
if ( F_141 ( V_2 , V_192 ) ) {
V_279 = F_143 ( V_2 -> V_149 -> V_280 , ( void * ) V_2 ,
L_122 ) ;
if ( F_116 ( V_279 ) ) {
F_108 ( V_2 , V_192 ) ;
F_109 ( V_2 ,
V_192 ) ;
}
}
}
static int F_144 ( struct V_1 * V_2 )
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
F_145 ( & V_2 -> V_284 ) ;
F_145 ( & V_2 -> V_285 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_38 = 0 ;
F_146 ( & V_2 -> V_193 , F_142 ) ;
F_139 ( & V_2 -> V_187 ) ;
F_106 ( & V_2 -> V_36 ) ;
F_140 ( V_2 ) ;
F_139 ( & V_2 -> V_286 . V_287 ) ;
V_2 -> V_286 . V_288 = 0 ;
V_2 -> V_286 . V_289 = 0 ;
V_2 -> V_286 . V_290 = 0 ;
F_138 ( V_2 ) ;
F_147 ( & V_2 -> V_291 , V_292 ) ;
F_146 ( & V_2 -> V_8 , F_2 ) ;
return 0 ;
}
static void F_148 ( struct V_293 * V_294 , struct V_295 * V_296 )
{
struct V_1 * V_2 = F_3 ( V_296 , struct V_1 ,
V_297 ) ;
if ( V_2 -> V_12 . V_298 [ 0 ] )
F_149 ( V_294 , L_124 ,
F_150 ( V_2 ) , V_2 -> V_12 . V_298 ) ;
}
static struct V_1 * F_151 ( void )
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
V_2 -> V_297 . V_302 = F_148 ;
F_152 ( & V_2 -> V_297 ) ;
return V_2 ;
V_300:
F_132 ( & V_2 -> V_114 ) ;
V_299:
F_32 ( V_2 ) ;
V_73:
return NULL ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
F_41 ( V_65 , 2 , L_126 ) ;
V_2 -> V_46 . V_303 = V_304 ;
V_2 -> V_46 . V_257 = V_305 ;
while ( V_306 [ V_44 ] [ V_307 ] ) {
if ( ( F_154 ( V_2 ) -> V_308 . V_309 ==
V_306 [ V_44 ] [ V_310 ] ) &&
( F_154 ( V_2 ) -> V_308 . V_311 ==
V_306 [ V_44 ] [ V_307 ] ) ) {
V_2 -> V_12 . type = V_306 [ V_44 ] [ V_307 ] ;
V_2 -> V_46 . V_78 =
V_306 [ V_44 ] [ V_312 ] ;
V_2 -> V_46 . V_72 = 1 ;
V_2 -> V_12 . V_313 =
V_306 [ V_44 ] [ V_314 ] ;
F_136 ( V_2 ) ;
return 0 ;
}
V_44 ++ ;
}
V_2 -> V_12 . type = V_315 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_127
L_128 ) ;
return - V_316 ;
}
static int F_155 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_129 ) ;
F_17 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_157 ( V_162 -> V_119 , V_222 ) ;
F_18 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_158 ( V_2 -> V_36 ,
V_162 -> V_3 == V_219 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_219 )
return - V_319 ;
V_162 -> V_3 = V_216 ;
return 0 ;
}
static int F_159 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_130 ) ;
F_17 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_160 ( V_162 -> V_119 , V_223 ) ;
F_18 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_158 ( V_2 -> V_36 ,
V_162 -> V_3 == V_221 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_221 )
return - V_319 ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_4 ( V_2 , 3 , L_131 ) ;
V_320 = F_159 ( & V_2 -> V_114 ) ;
V_321 = F_159 ( & V_2 -> V_155 ) ;
V_322 = F_159 ( & V_2 -> V_117 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_4 ( V_2 , 3 , L_132 ) ;
V_320 = F_155 ( & V_2 -> V_114 ) ;
V_321 = F_155 ( & V_2 -> V_155 ) ;
V_322 = F_155 ( & V_2 -> V_117 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_163 ( struct V_1 * V_2 , int V_323 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_133 ) ;
if ( V_323 )
V_37 = F_161 ( V_2 ) ;
if ( V_37 )
return V_37 ;
return F_162 ( V_2 ) ;
}
int F_164 ( struct V_1 * V_2 , int V_324 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_134 ) ;
switch ( F_59 ( & V_2 -> V_46 . V_3 , V_325 ,
V_326 ) ) {
case V_325 :
if ( V_2 -> V_12 . type == V_15 )
V_37 = F_165 ( F_44 ( V_2 ) ,
V_327 ) ;
else
V_37 = F_165 ( F_44 ( V_2 ) ,
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
V_37 = F_163 ( V_2 , V_324 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_135 , V_37 ) ;
V_2 -> V_3 = V_55 ;
return V_37 ;
}
static int F_166 ( struct V_1 * V_2 , void * * V_64 ,
int * V_253 )
{
struct V_330 * V_330 ;
char * V_331 ;
int V_332 ;
struct V_161 * V_162 = & V_2 -> V_117 ;
unsigned long V_32 ;
V_330 = F_167 ( V_162 -> V_119 , V_333 ) ;
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
F_17 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
V_332 = F_168 ( V_162 -> V_119 , & V_162 -> V_120 ,
V_215 , V_338 , 0 ,
V_339 ) ;
F_18 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
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
static void F_169 ( struct V_1 * V_2 , char * V_340 )
{
F_41 ( V_65 , 2 , L_136 ) ;
V_2 -> V_12 . V_142 = V_340 [ 30 ] ;
V_2 -> V_12 . V_341 = V_340 [ 31 ] ;
V_2 -> V_12 . V_342 = V_340 [ 63 ] ;
V_2 -> V_12 . V_13 = ( ( V_340 [ 0x10 ] == V_343 [ 'V' ] ) &&
( V_340 [ 0x11 ] == V_343 [ 'M' ] ) ) ;
}
static enum V_344 F_170 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . type == V_16 ||
V_2 -> V_12 . type == V_18 ) {
F_41 ( V_65 , 3 , L_137 ) ;
return V_345 ;
}
if ( V_2 -> V_12 . V_13 && V_2 -> V_12 . type == V_15 ) {
F_41 ( V_65 , 3 , L_138 ) ;
return V_346 ;
}
F_41 ( V_65 , 3 , L_139 ) ;
return V_347 ;
}
static void F_171 ( struct V_1 * V_2 , char * V_340 )
{
F_41 ( V_65 , 2 , L_140 ) ;
if ( V_340 [ 74 ] == 0xF0 && V_340 [ 75 ] == 0xF0 &&
V_340 [ 76 ] >= 0xF1 && V_340 [ 76 ] <= 0xF4 ) {
V_2 -> V_12 . V_348 . V_349 = 0 ;
V_2 -> V_12 . V_348 . V_350 = 0 ;
V_2 -> V_12 . V_348 . V_351 = 0 ;
} else {
V_2 -> V_12 . V_348 . V_349 = 250 ;
V_2 -> V_12 . V_348 . V_350 = 5 ;
V_2 -> V_12 . V_348 . V_351 = 15 ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
V_2 -> V_352 . V_353 = 0x00010103UL ;
V_2 -> V_352 . V_354 = 0x00010108UL ;
V_2 -> V_352 . V_355 = 0x0001010aUL ;
V_2 -> V_352 . V_356 = 0x0001010bUL ;
V_2 -> V_352 . V_357 = 0x0001010dUL ;
}
static void F_173 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
V_2 -> V_12 . V_260 = V_358 ;
break;
case V_14 :
case V_18 :
V_2 -> V_12 . V_260 = V_359 ;
break;
default:
break;
}
}
static int F_174 ( struct V_161 * V_162 ,
void (* F_175)( struct V_161 * ,
struct V_112 * ) )
{
struct V_112 * V_113 ;
unsigned long V_32 ;
int V_37 ;
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_141 ) ;
V_2 = F_94 ( V_162 -> V_119 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_175 ;
memcpy ( & V_162 -> V_120 , V_164 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_118 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_142 , V_37 ) ;
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_158 ( V_2 -> V_36 ,
V_162 -> V_3 == V_115 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_115 ) {
V_37 = - V_319 ;
F_45 ( V_65 , 2 , L_143 , V_37 ) ;
F_101 ( V_162 ) ;
} else
V_37 = 0 ;
return V_37 ;
}
static int F_176 ( struct V_161 * V_162 ,
void (* F_175)( struct V_161 * ,
struct V_112 * ) )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
unsigned long V_32 ;
V_185 V_360 ;
T_2 V_41 ;
int V_37 ;
struct V_361 V_362 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_41 ( V_65 , 2 , L_144 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_175 ;
memcpy ( & V_162 -> V_120 , V_166 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_363 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
if ( V_162 == & V_2 -> V_155 ) {
memcpy ( V_113 -> V_117 , V_364 , V_363 ) ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_365 , V_189 ) ;
V_2 -> V_182 . V_365 ++ ;
} else {
memcpy ( V_113 -> V_117 , V_366 , V_363 ) ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_365 , V_189 ) ;
}
V_41 = ( ( T_2 ) V_2 -> V_12 . V_367 ) | 0x80 ;
memcpy ( F_178 ( V_113 -> V_117 ) , & V_41 , 1 ) ;
memcpy ( F_179 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_353 , V_368 ) ;
memcpy ( F_180 ( V_113 -> V_117 ) ,
& V_2 -> V_12 . V_260 , sizeof( V_185 ) ) ;
F_181 ( F_44 ( V_2 ) , & V_362 ) ;
memcpy ( F_182 ( V_113 -> V_117 ) , & V_362 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_12 . V_342 << 8 ) + V_2 -> V_12 . V_341 ;
memcpy ( F_183 ( V_113 -> V_117 ) , & V_360 , 2 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_156 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_145 ,
V_37 ) ;
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_158 ( V_2 -> V_36 ,
V_162 -> V_3 == V_370 , V_317 ) ;
if ( V_37 == - V_318 )
return V_37 ;
if ( V_162 -> V_3 != V_370 ) {
F_67 ( & V_162 -> V_119 -> V_9 , L_146
L_147 ) ;
F_68 ( 2 , L_148 ,
F_69 ( & V_162 -> V_119 -> V_9 ) ) ;
F_45 ( V_65 , 2 , L_135 , - V_319 ) ;
F_101 ( V_162 ) ;
return - V_319 ;
}
return F_174 ( V_162 , F_175 ) ;
}
static int F_184 ( int V_371 )
{
if ( ( V_371 & 0xff ) == 8 )
return ( V_371 & 0xff ) + 0x400 ;
if ( ( ( V_371 >> 8 ) & 3 ) == 1 )
return ( V_371 & 0xff ) + 0x200 ;
return V_371 ;
}
static void F_185 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_360 ;
F_41 ( V_65 , 2 , L_149 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_370 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( ! ( F_186 ( V_113 -> V_117 ) ) ) {
if ( F_187 ( V_113 -> V_117 ) == V_372 )
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_150
L_151 ) ;
else
F_68 ( 2 , L_152
L_153 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ) ;
goto V_73;
}
memcpy ( & V_360 , F_180 ( V_113 -> V_117 ) , 2 ) ;
if ( ( V_360 & ~ 0x0100 ) != F_184 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_154
L_155
L_156 , F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_360 ) ;
goto V_73;
}
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
static void F_188 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_360 ;
F_41 ( V_65 , 2 , L_157 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_370 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( F_93 ( V_2 , V_113 -> V_117 ) )
goto V_73;
if ( ! ( F_186 ( V_113 -> V_117 ) ) ) {
switch ( F_187 ( V_113 -> V_117 ) ) {
case V_372 :
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_150
L_151 ) ;
break;
case V_373 :
case V_374 :
F_47 ( & V_2 -> V_114 . V_119 -> V_9 ,
L_158
L_159 ) ;
break;
default:
F_68 ( 2 , L_160
L_153 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ) ;
}
F_52 ( V_2 , 2 , L_161 ,
F_187 ( V_113 -> V_117 ) ) ;
goto V_73;
}
memcpy ( & V_360 , F_180 ( V_113 -> V_117 ) , 2 ) ;
if ( V_360 != F_184 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_162
L_163 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_360 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_352 . V_375 ,
F_179 ( V_113 -> V_117 ) ,
V_368 ) ;
memcpy ( & V_2 -> V_12 . V_298 [ 0 ] ,
F_189 ( V_113 -> V_117 ) , V_376 ) ;
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
void F_190 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_155 , V_113 -> V_117 , V_163 ) ;
V_113 -> V_175 = F_98 ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_365 , V_189 ) ;
V_2 -> V_182 . V_365 ++ ;
memcpy ( F_103 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_377 , V_189 ) ;
V_2 -> V_182 . V_377 ++ ;
memcpy ( F_191 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_188 , V_189 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
}
int F_192 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 ,
int (* F_193)( struct V_1 * V_378 ,
struct V_124 * V_379 ,
unsigned long V_380 ) ,
void * V_381 )
{
int V_37 ;
unsigned long V_32 ;
struct V_124 * V_125 = NULL ;
unsigned long V_382 , V_383 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 2 , L_164 ) ;
if ( V_2 -> V_123 ) {
F_98 ( V_113 -> V_162 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_175 = F_193 ;
V_125 -> V_384 = V_381 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_182 = V_183 ;
else
V_125 -> V_182 = V_2 -> V_182 . V_385 ++ ;
F_106 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_102 ( & V_125 -> V_42 , & V_2 -> V_187 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
while ( F_59 ( & V_2 -> V_155 . V_122 , 0 , 1 ) ) ;
F_190 ( V_2 , V_163 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_383 = V_386 ;
else
V_383 = V_317 ;
V_382 = V_387 + V_383 ;
F_4 ( V_2 , 6 , L_52 ) ;
F_17 ( F_156 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
V_37 = F_71 ( V_2 -> V_155 . V_119 , & V_2 -> V_155 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_156 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_165
L_166 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) , V_37 ) ;
F_52 ( V_2 , 2 , L_167 , V_37 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_77 ( V_125 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_98 ( V_113 -> V_162 , V_113 ) ;
F_60 ( & V_2 -> V_155 . V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
if ( ( V_130 -> V_133 . V_134 == V_389 ) &&
( V_130 -> V_133 . V_390 == V_391 ) ) {
if ( ! F_194 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_383 ) )
goto V_392;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_195 ( V_387 , V_382 ) )
goto V_392;
F_196 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_392:
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
static int F_197 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_393 ,
F_198 ( V_113 -> V_117 ) ,
V_368 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_394 , V_395 ) ;
memcpy ( F_200 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_375 , V_368 ) ;
memcpy ( F_201 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_354 , V_368 ) ;
V_37 = F_192 ( V_2 , V_395 , V_113 ,
F_197 , NULL ) ;
return V_37 ;
}
static int F_202 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_170 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_396 ,
F_203 ( V_113 -> V_117 ) ,
V_368 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_171 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_397 , V_398 ) ;
memcpy ( F_205 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_375 , V_368 ) ;
memcpy ( F_206 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_355 , V_368 ) ;
memcpy ( F_207 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_393 , V_368 ) ;
V_37 = F_192 ( V_2 , V_398 , V_113 ,
F_202 , NULL ) ;
return V_37 ;
}
static inline int F_208 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_315 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_399 ;
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
static inline int F_209 ( int V_400 )
{
switch ( V_400 ) {
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
static inline int F_210 ( struct V_1 * V_2 , int V_401 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_401 >= 576 ) &&
( V_401 <= V_2 -> V_12 . V_399 ) ) ;
case V_18 :
case V_315 :
default:
return 1 ;
}
}
static int F_211 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_185 V_401 , V_400 ;
V_185 V_163 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_402 ,
F_212 ( V_113 -> V_117 ) ,
V_368 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_400 , F_213 ( V_113 -> V_117 ) , 2 ) ;
V_401 = F_209 ( V_400 ) ;
if ( ! V_401 ) {
V_113 -> V_37 = - V_403 ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
if ( V_2 -> V_12 . V_404 && ( V_2 -> V_12 . V_404 != V_401 ) ) {
if ( V_2 -> V_9 &&
( ( V_2 -> V_9 -> V_401 == V_2 -> V_12 . V_404 ) ||
( V_2 -> V_9 -> V_401 > V_401 ) ) )
V_2 -> V_9 -> V_401 = V_401 ;
F_134 ( V_2 ) ;
}
V_2 -> V_12 . V_404 = V_401 ;
V_2 -> V_12 . V_399 = V_401 ;
V_2 -> V_46 . V_263 = V_401 + 2 * V_405 ;
} else {
V_2 -> V_12 . V_399 = * ( V_185 * ) F_213 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_404 = F_214 ( V_2 -> V_12 . V_399 ,
F_208 ( V_2 ) ) ;
V_2 -> V_46 . V_263 = V_264 ;
}
memcpy ( & V_163 , F_215 ( V_113 -> V_117 ) , 2 ) ;
if ( V_163 >= V_406 ) {
memcpy ( & V_19 ,
F_216 ( V_113 -> V_117 ) , 1 ) ;
V_2 -> V_12 . V_19 = V_19 ;
} else
V_2 -> V_12 . V_19 = 0 ;
F_45 ( V_65 , 2 , L_173 , V_2 -> V_12 . V_19 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 )
{
int V_37 ;
char V_407 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_174 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_408 , V_409 ) ;
* ( F_218 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_367 ;
if ( V_2 -> V_66 . V_301 )
if ( V_2 -> V_12 . type == V_18 )
V_407 = V_410 ;
else
V_407 = V_411 ;
else
V_407 = V_412 ;
memcpy ( F_219 ( V_113 -> V_117 ) , & V_407 , 1 ) ;
memcpy ( F_220 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_396 , V_368 ) ;
memcpy ( F_221 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_356 , V_368 ) ;
V_37 = F_192 ( V_2 , V_409 , V_113 ,
F_211 , NULL ) ;
return V_37 ;
}
static int F_222 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_175 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_352 . V_413 ,
F_223 ( V_113 -> V_117 ) ,
V_368 ) ;
if ( ! strncmp ( L_176 , F_223 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_177 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_178
L_179 ) ;
V_113 -> V_37 = - V_414 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 )
{
int V_37 ;
V_185 V_360 ;
struct V_112 * V_113 ;
struct V_361 V_415 ;
F_41 ( V_65 , 2 , L_180 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_416 , V_417 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_396 , V_368 ) ;
memcpy ( F_226 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_357 , V_368 ) ;
memcpy ( F_227 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_402 , V_368 ) ;
F_181 ( F_44 ( V_2 ) , & V_415 ) ;
memcpy ( F_228 ( V_113 -> V_117 ) , & V_415 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_12 . V_342 << 8 ) + V_2 -> V_12 . V_341 ;
memcpy ( F_229 ( V_113 -> V_117 ) , & V_360 , 2 ) ;
V_37 = F_192 ( V_2 , V_417 , V_113 ,
F_222 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_418 ;
V_37 = 0 ;
V_418 = F_230 ( V_101 , V_126 ) ;
if ( ! V_418 ) {
V_37 = - V_50 ;
goto V_73;
}
V_418 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_231 ( & V_418 -> V_234 ) ;
F_232 ( & V_418 -> V_234 . V_154 , & V_419 ) ;
V_418 -> V_60 = V_60 ;
V_418 -> V_102 = NULL ;
V_418 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_418 -> V_3 , V_249 ) ;
V_60 -> V_63 [ V_93 ] = V_418 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_420 = V_418 ;
F_52 ( V_60 -> V_2 , 2 , L_181 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_418 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_418 -> V_95 ) ;
}
V_73:
return V_37 ;
}
static void F_233 ( struct V_92 * V_60 )
{
if ( ! V_60 )
return;
F_36 ( V_60 -> V_61 , V_62 ) ;
F_32 ( V_60 ) ;
}
static struct V_92 * F_234 ( void )
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
static int F_235 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
F_41 ( V_65 , 2 , L_182 ) ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_256 ,
V_329 ) != V_256 )
return 0 ;
F_41 ( V_65 , 2 , L_183 ) ;
V_2 -> V_46 . V_421 = F_37 () ;
if ( ! V_2 -> V_46 . V_421 )
goto V_422;
if ( F_26 ( V_2 ) )
goto V_423;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_424;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_234 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_425;
F_45 ( V_65 , 2 , L_184 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_426 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_427;
}
}
if ( F_46 ( V_2 ) )
goto V_425;
return 0 ;
V_427:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_425:
while ( V_44 > 0 ) {
F_233 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_130 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_424:
F_28 ( V_2 ) ;
V_423:
F_35 ( V_2 -> V_46 . V_421 ) ;
V_2 -> V_46 . V_421 = NULL ;
V_422:
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
return - V_50 ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_236 ( & V_2 -> V_46 . V_3 , V_256 ) ==
V_256 )
return;
F_48 ( V_2 ) ;
F_237 ( & V_2 -> V_291 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_421 -> V_63 [ V_45 ] . V_428 )
F_128 ( V_2 -> V_46 . V_421 -> V_63 [ V_45 ] . V_428 ) ;
}
F_35 ( V_2 -> V_46 . V_421 ) ;
V_2 -> V_46 . V_421 = NULL ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 . V_80 ) {
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_130 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
F_233 ( V_2 -> V_46 . V_80 [ V_44 ] ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
}
}
static void F_238 ( struct V_1 * V_2 ,
char * V_429 )
{
V_429 [ 0 ] = V_343 [ 'P' ] ;
V_429 [ 1 ] = V_343 [ 'C' ] ;
V_429 [ 2 ] = V_343 [ 'I' ] ;
V_429 [ 3 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_429 [ 4 ] ) ) = F_239 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_429 [ 8 ] ) ) = F_240 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_429 [ 12 ] ) ) = F_241 ( V_2 ) ;
}
static void F_242 ( struct V_1 * V_2 ,
char * V_429 )
{
V_429 [ 16 ] = V_343 [ 'B' ] ;
V_429 [ 17 ] = V_343 [ 'L' ] ;
V_429 [ 18 ] = V_343 [ 'K' ] ;
V_429 [ 19 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_429 [ 20 ] ) ) = V_2 -> V_12 . V_348 . V_349 ;
* ( ( unsigned int * ) ( & V_429 [ 24 ] ) ) = V_2 -> V_12 . V_348 . V_350 ;
* ( ( unsigned int * ) ( & V_429 [ 28 ] ) ) =
V_2 -> V_12 . V_348 . V_351 ;
}
static int F_243 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 3 , L_185 ) ;
return F_244 ( F_44 ( V_2 ) ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_186 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_430 , V_431 ) ;
memcpy ( F_246 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_396 , V_368 ) ;
memcpy ( F_247 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_413 , V_368 ) ;
V_37 = F_192 ( V_2 , V_431 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_248 ( struct V_1 * V_2 )
{
int V_37 ;
F_41 ( V_65 , 2 , L_187 ) ;
V_37 = F_65 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
return V_37 ;
}
V_37 = F_199 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
goto V_432;
}
V_37 = F_204 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_143 , V_37 ) ;
goto V_432;
}
V_37 = F_217 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_432;
}
V_37 = F_224 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_432;
}
V_37 = F_235 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_432;
}
V_37 = F_249 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
F_134 ( V_2 ) ;
goto V_432;
}
V_37 = F_243 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_191 , V_37 ) ;
goto V_432;
}
V_37 = F_245 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_192 , V_37 ) ;
goto V_432;
}
return 0 ;
V_432:
F_164 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_250 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
void F_251 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_298 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_298 , L_193 ,
V_2 -> V_12 . V_298 [ 2 ] ,
V_2 -> V_12 . V_298 [ 3 ] ) ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_298 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_298 [ 0 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_298 [ 0 ] ] ;
V_2 -> V_12 . V_298 [ 1 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_298 [ 1 ] ] ;
V_2 -> V_12 . V_298 [ 2 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_298 [ 2 ] ] ;
V_2 -> V_12 . V_298 [ 3 ] = ( char ) V_433 [ ( T_2 )
V_2 -> V_12 . V_298 [ 3 ] ] ;
V_2 -> V_12 . V_298 [ V_376 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_298 [ 0 ] , 0 , V_376 + 1 ) ;
}
F_89 ( & V_2 -> V_10 -> V_9 ,
L_194 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? L_195 : L_74 ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? V_2 -> V_12 . V_298 : L_74 ,
( V_2 -> V_12 . V_298 [ 0 ] ) ? L_196 : L_74 ,
F_12 ( V_2 ) ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_39 * V_434 ;
F_4 ( V_2 , 5 , L_197 ) ;
F_253 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_254 ( V_2 , V_434 ) ;
}
}
static inline struct V_39 * F_255 (
struct V_1 * V_2 )
{
struct V_435 * V_436 ;
struct V_39 * V_434 ;
int V_44 , free ;
struct V_437 * V_437 ;
if ( F_256 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_257 (plh, &card->qdio.in_buf_pool.entry_list) {
V_434 = F_258 ( V_436 , struct V_39 , V_42 ) ;
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
V_434 = F_258 ( V_2 -> V_46 . V_58 . V_53 . V_438 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_259 ( F_260 ( V_434 -> V_51 [ V_44 ] ) ) > 1 ) {
V_437 = F_261 ( V_126 ) ;
if ( ! V_437 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_434 -> V_51 [ V_44 ] ) ;
V_434 -> V_51 [ V_44 ] = F_262 ( V_437 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_439 . V_440 ++ ;
}
}
}
F_92 ( & V_434 -> V_42 ) ;
return V_434 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_441 * V_231 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_231 -> V_428 ) ) {
V_231 -> V_428 = F_264 ( V_442 + V_443 ) ;
if ( ! V_231 -> V_428 )
return 1 ;
}
V_40 = F_255 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_231 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_231 -> V_64 -> V_245 [ V_44 ] . V_253 = V_405 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = V_444 ;
else
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_246 = 0 ;
}
return 0 ;
}
int F_265 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_198 ) ;
F_42 ( V_2 -> V_46 . V_421 -> V_61 ,
V_62 ) ;
F_252 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_263 ( V_2 , & V_2 -> V_46 . V_421 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_421 -> V_70 =
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
V_2 -> V_46 . V_80 [ V_44 ] -> V_445 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_446 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_447 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_248 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_448 ) ;
}
return 0 ;
}
static inline T_2 F_266 ( enum V_449 V_19 )
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
enum V_450 V_451 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_452 = V_453 ;
V_130 -> V_133 . V_182 = V_2 -> V_182 . V_385 ;
V_130 -> V_133 . V_454 = F_266 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_455 = ( T_2 ) V_2 -> V_12 . V_367 ;
if ( V_2 -> V_66 . V_301 )
V_130 -> V_133 . V_456 = 2 ;
else
V_130 -> V_133 . V_456 = 1 ;
V_130 -> V_133 . V_457 = 1 ;
V_130 -> V_133 . V_390 = V_451 ;
V_130 -> V_133 . V_458 = 0 ;
V_130 -> V_133 . V_459 = 0 ;
}
struct V_112 * F_268 ( struct V_1 * V_2 ,
enum V_460 V_461 , enum V_450 V_451 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_66 ( & V_2 -> V_155 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
F_267 ( V_2 , V_130 , V_461 , V_451 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_199 ) ;
F_68 ( 1 , L_200 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
}
return V_113 ;
}
void F_269 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_407 )
{
memcpy ( V_113 -> V_117 , V_462 , V_388 ) ;
memcpy ( F_270 ( V_113 -> V_117 ) , & V_407 , 1 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_413 , V_368 ) ;
}
int F_272 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_193)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_381 )
{
int V_37 ;
char V_407 ;
F_4 ( V_2 , 4 , L_201 ) ;
if ( V_2 -> V_66 . V_301 )
if ( V_2 -> V_12 . type == V_18 )
V_407 = V_410 ;
else
V_407 = V_411 ;
else
V_407 = V_412 ;
F_269 ( V_2 , V_113 , V_407 ) ;
V_37 = F_192 ( V_2 , V_463 ,
V_113 , F_193 , V_381 ) ;
if ( V_37 == - V_319 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_37 ;
}
static int F_273 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_202 ) ;
V_113 = F_268 ( V_2 , V_144 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_272 ( V_2 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_274 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_203 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 )
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_464 . V_133 . V_139 ;
return 0 ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_204 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_464 . V_117 . V_465 . V_466 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_464 . V_117 . V_465 . V_466 ;
F_45 ( V_65 , 2 , L_205 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_467 . V_468 =
V_130 -> V_117 . V_464 . V_117 . V_465 . V_469 ;
return F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_276 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_470 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_268 ( V_2 , V_471 ,
V_391 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_464 . V_133 . V_472 = V_470 ;
V_130 -> V_117 . V_464 . V_133 . V_473 = V_134 ;
V_130 -> V_117 . V_464 . V_133 . V_474 = 1 ;
V_130 -> V_117 . V_464 . V_133 . V_475 = 1 ;
}
return V_113 ;
}
int F_277 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_206 ) ;
V_113 = F_276 ( V_2 , V_476 ,
sizeof( struct V_477 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_272 ( V_2 , V_113 , F_275 , NULL ) ;
return V_37 ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_207 ) ;
V_130 = (struct V_129 * ) V_117 ;
switch ( V_130 -> V_133 . V_139 ) {
case V_478 :
case V_479 :
F_41 ( V_65 , 2 , L_208 ) ;
V_2 -> V_66 . V_480 . V_468 |= V_481 ;
V_2 -> V_66 . V_482 . V_468 |= V_481 ;
return - 0 ;
default:
if ( V_130 -> V_133 . V_139 ) {
F_68 ( 1 , L_209
L_210 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ,
V_130 -> V_133 . V_139 ) ;
return 0 ;
}
}
if ( V_130 -> V_133 . V_390 == V_391 ) {
V_2 -> V_66 . V_480 . V_468 = V_130 -> V_133 . V_458 ;
V_2 -> V_66 . V_480 . V_483 = V_130 -> V_133 . V_459 ;
} else if ( V_130 -> V_133 . V_390 == V_484 ) {
V_2 -> V_66 . V_482 . V_468 = V_130 -> V_133 . V_458 ;
V_2 -> V_66 . V_482 . V_483 = V_130 -> V_133 . V_459 ;
} else
F_68 ( 1 , L_211
L_212 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_279 ( struct V_1 * V_2 , enum V_450 V_451 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_213 , V_451 ) ;
V_113 = F_268 ( V_2 , V_485 , V_451 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_272 ( V_2 , V_113 , F_278 , NULL ) ;
return V_37 ;
}
static int F_280 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_486 * V_487 ;
struct V_488 * V_489 ;
F_4 ( V_2 , 2 , L_214 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_487 = (struct V_486 * ) V_125 -> V_384 ;
if ( V_130 -> V_117 . V_464 . V_133 . V_139 == 0 ) {
V_489 = & V_130 -> V_117 . V_464 . V_117 . V_490 ;
V_487 -> V_491 = V_489 -> V_491 ;
V_487 -> V_492 = V_489 -> V_492 ;
F_52 ( V_2 , 2 , L_215 , V_487 -> V_491 ,
V_487 -> V_492 ) ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_488 ( struct V_1 * V_2 ,
struct V_486 * V_487 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_216 ) ;
if ( ! F_281 ( V_2 , V_493 ) )
return - V_334 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_494 ;
V_113 = F_276 ( V_2 , V_493 ,
sizeof( struct V_495 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_272 ( V_2 , V_113 ,
F_280 , V_487 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_217 , V_37 ) ;
else
V_2 -> V_12 . V_496 = V_130 -> V_117 . V_497 . V_498 ;
return 0 ;
}
static int F_283 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_218 ) ;
V_113 = F_268 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_497 . V_499 = 16 ;
V_130 -> V_117 . V_497 . V_500 = V_501 ;
return F_272 ( V_2 , V_113 , F_282 , NULL ) ;
}
static void F_284 ( struct V_1 * V_2 , struct V_502 * V_503 )
{
unsigned long V_12 = F_285 ( V_49 ) ;
struct V_504 * V_505 = (struct V_504 * ) V_12 ;
struct V_506 * V_507 = (struct V_506 * ) V_12 ;
struct V_361 V_508 ;
int V_371 ;
V_503 -> V_142 = V_2 -> V_12 . V_142 ;
F_181 ( F_154 ( V_2 ) , & V_508 ) ;
V_503 -> V_509 = V_508 . V_509 ;
V_503 -> V_369 = V_508 . V_369 ;
if ( ! V_12 )
return;
V_371 = F_286 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_371 >= 2 ) && ( F_286 ( V_505 , 2 , 2 , 2 ) == 0 ) )
V_503 -> V_510 = V_505 -> V_511 ;
if ( ( V_371 >= 3 ) && ( F_286 ( V_507 , 3 , 2 , 2 ) == 0 ) ) {
F_287 ( V_507 -> V_512 [ 0 ] . V_513 , sizeof( V_507 -> V_512 [ 0 ] . V_513 ) ) ;
memcpy ( V_503 -> V_514 , V_507 -> V_512 [ 0 ] . V_513 , sizeof( V_503 -> V_514 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_219 , V_37 ) ;
return 0 ;
}
int F_289 ( struct V_1 * V_2 , enum V_515 V_516 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_220 ) ;
V_113 = F_268 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_497 . V_499 = 80 ;
V_130 -> V_117 . V_497 . V_500 = V_517 ;
V_130 -> V_117 . V_497 . type = 1 ;
V_130 -> V_117 . V_497 . V_516 = V_516 ;
switch ( V_516 ) {
case V_518 :
V_130 -> V_117 . V_497 . V_66 = 0x0003 ;
V_130 -> V_117 . V_497 . V_498 = 0x00010000 +
sizeof( struct V_502 ) ;
F_284 ( V_2 ,
(struct V_502 * ) V_130 -> V_117 . V_497 . V_519 ) ;
break;
case V_520 :
V_130 -> V_117 . V_497 . V_66 = 0x0001 ;
break;
case V_521 :
break;
}
return F_272 ( V_2 , V_113 , F_288 , NULL ) ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_522 * V_231 ,
unsigned int V_523 ,
const char * V_524 )
{
if ( V_523 ) {
F_4 ( V_2 , 2 , V_524 ) ;
F_52 ( V_2 , 2 , L_221 ,
V_231 -> V_245 [ 15 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_222 ,
V_231 -> V_245 [ 14 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_223 , V_523 ) ;
if ( ( V_231 -> V_245 [ 15 ] . V_246 ) == 0x12 ) {
V_2 -> V_525 . V_526 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static void F_291 ( struct V_1 * V_2 , int V_169 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_421 ;
struct V_435 * V_527 ;
int V_167 ;
int V_44 ;
int V_37 ;
int V_528 = 0 ;
V_167 = ( V_169 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_169 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_169 ) ;
if ( V_167 >= F_292 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_167 ; ++ V_44 ) {
if ( F_263 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_528 ++ ;
}
}
if ( V_528 < V_167 ) {
F_60 ( & V_2 -> V_529 , 3 ) ;
V_167 = V_528 ;
} else {
F_293 ( & V_2 -> V_529 , - 1 , 0 ) ;
}
if ( ! V_167 ) {
V_44 = 0 ;
F_257 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_224 ) ;
V_2 -> V_530 = V_169 ;
F_294 (
& V_2 -> V_291 ,
V_531 ) ;
}
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_439 . V_532 ++ ;
V_2 -> V_439 . V_533 =
F_295 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_167 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_439 . V_534 +=
F_295 () -
V_2 -> V_439 . V_533 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_225 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_167 ) %
V_62 ;
}
}
static void V_292 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_291 . V_7 ) ;
F_52 ( V_2 , 2 , L_226 , V_2 -> V_530 ) ;
F_291 ( V_2 , V_2 -> V_530 ) ;
}
static void F_296 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_535 )
{
int V_83 = V_64 -> V_64 -> V_245 [ 15 ] . V_246 ;
F_4 ( V_2 , 6 , L_227 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_535 = 0 ;
} else {
V_535 = 1 ;
}
}
F_290 ( V_2 , V_64 -> V_64 , V_535 , L_228 ) ;
if ( ! V_535 )
return;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return;
F_4 ( V_2 , 1 , L_229 ) ;
F_52 ( V_2 , 1 , L_230 ,
( V_186 ) V_535 , ( V_277 ) V_83 ) ;
}
static int F_297 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_445 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_445 =
( V_111 -> V_445 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_298 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_446 ) {
if ( F_51 ( & V_111 -> V_447 )
>= V_536 ) {
F_4 ( V_111 -> V_2 , 6 , L_231 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_439 . V_537 ++ ;
V_111 -> V_446 = 1 ;
}
}
}
static int F_299 ( struct V_92 * V_111 )
{
if ( V_111 -> V_446 ) {
if ( F_51 ( & V_111 -> V_447 )
<= V_538 ) {
F_4 ( V_111 -> V_2 , 6 , L_232 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_439 . V_539 ++ ;
V_111 -> V_446 = 0 ;
return F_297 ( V_111 ) ;
}
}
return 0 ;
}
static void F_300 ( struct V_92 * V_111 , int V_169 ,
int V_167 )
{
struct V_96 * V_231 ;
int V_37 ;
int V_44 ;
unsigned int V_540 ;
for ( V_44 = V_169 ; V_44 < V_169 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_231 = V_111 -> V_63 [ V_93 ] ;
V_231 -> V_64 -> V_245 [ V_231 -> V_255 - 1 ] . V_254 |=
V_444 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_420 = V_231 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_446 ) {
if ( ( F_51 ( & V_111 -> V_447 ) >=
( V_536 -
V_541 ) ) &&
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
F_301 ( V_111 -> V_2 -> V_9 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 ) {
V_111 -> V_2 -> V_439 . V_542 ++ ;
V_111 -> V_2 -> V_439 . V_543 =
F_295 () ;
}
V_540 = V_544 ;
if ( F_51 ( & V_111 -> V_248 ) )
V_540 |= V_545 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_540 ,
V_111 -> V_426 , V_169 , V_167 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_439 . V_546 +=
F_295 () -
V_111 -> V_2 -> V_439 . V_543 ;
F_302 ( V_167 , & V_111 -> V_447 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_525 . V_547 += V_167 ;
if ( V_37 == - V_548 )
return;
F_4 ( V_111 -> V_2 , 2 , L_233 ) ;
F_52 ( V_111 -> V_2 , 2 , L_234 , V_111 -> V_426 ) ;
F_52 ( V_111 -> V_2 , 2 , L_235 , V_169 ) ;
F_52 ( V_111 -> V_2 , 2 , L_236 , V_167 ) ;
F_52 ( V_111 -> V_2 , 2 , L_167 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_439 . V_549 += V_167 ;
}
static void F_303 ( struct V_92 * V_111 )
{
int V_169 ;
int V_550 = 0 ;
int V_551 = 0 ;
if ( ( F_51 ( & V_111 -> V_447 ) <= V_538 ) ||
! F_51 ( & V_111 -> V_248 ) ) {
if ( F_236 ( & V_111 -> V_3 , V_552 ) ==
V_448 ) {
F_304 ( V_111 -> V_2 -> V_9 ) ;
V_169 = V_111 -> V_445 ;
V_551 = V_111 -> V_446 ;
F_305 () ;
V_550 += F_299 ( V_111 ) ;
if ( ! V_550 &&
! F_51 ( & V_111 -> V_248 ) )
V_550 += F_297 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 &&
V_551 )
V_111 -> V_2 -> V_439 . V_553 +=
V_550 ;
if ( V_550 )
F_300 ( V_111 , V_169 , V_550 ) ;
F_60 ( & V_111 -> V_3 , V_448 ) ;
}
}
}
void F_306 ( struct V_158 * V_119 , int V_111 ,
unsigned long V_554 )
{
struct V_1 * V_2 = (struct V_1 * ) V_554 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_555 ) )
F_307 ( & V_2 -> V_556 ) ;
}
int F_308 ( struct V_1 * V_2 , enum V_557 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_558 ) {
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
F_134 ( V_2 ) ;
V_2 -> V_66 . V_67 = V_67 ;
V_37 = 0 ;
}
V_73:
return V_37 ;
}
static void F_309 ( struct V_1 * V_2 ,
unsigned int V_535 ,
unsigned int V_111 , int V_559 , int V_167 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_237 , V_559 ) ;
F_52 ( V_2 , 5 , L_238 , V_167 ) ;
F_52 ( V_2 , 5 , L_239 , V_535 ) ;
if ( V_535 ) {
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_439 . V_560 ++ ;
V_2 -> V_439 . V_561 = F_295 () ;
}
for ( V_44 = V_559 ; V_44 < V_559 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_522 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_562 ;
V_562 = 0 ;
while ( ( V_562 < V_563 ) &&
V_64 -> V_245 [ V_562 ] . V_250 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_245 [ V_562 ] . V_250 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_245 [ V_562 ] . V_250 = NULL ;
V_64 -> V_245 [ V_562 ] . V_254 = 0 ;
V_64 -> V_245 [ V_562 ] . V_246 = 0 ;
V_64 -> V_245 [ V_562 ] . V_253 = 0 ;
++ V_562 ;
}
V_64 -> V_245 [ 15 ] . V_254 = 0 ;
V_64 -> V_245 [ 15 ] . V_246 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_167 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_240 , V_37 ) ;
F_4 ( V_2 , 2 , L_241 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_167 ) % V_62 ;
F_310 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 ) {
int V_564 = F_295 () ;
V_564 -= V_2 -> V_439 . V_561 ;
V_2 -> V_439 . V_565 += V_564 ;
}
V_73:
return;
}
void F_311 ( struct V_158 * V_119 , unsigned int V_535 ,
unsigned int V_111 , int V_566 , int V_167 ,
unsigned long V_554 )
{
struct V_1 * V_2 = (struct V_1 * ) V_554 ;
F_52 ( V_2 , 2 , L_242 , V_111 ) ;
F_52 ( V_2 , 2 , L_243 , V_535 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_309 ( V_2 , V_535 , V_111 , V_566 , V_167 ) ;
else if ( V_535 )
F_72 ( V_2 ) ;
}
void F_312 ( struct V_158 * V_119 ,
unsigned int V_523 , int V_567 , int V_559 ,
int V_167 , unsigned long V_554 )
{
struct V_1 * V_2 = (struct V_1 * ) V_554 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_567 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_244 ) ;
if ( V_523 & V_568 ) {
F_4 ( V_2 , 2 , L_245 ) ;
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_439 . V_569 ++ ;
V_2 -> V_439 . V_570 =
F_295 () ;
}
for ( V_44 = V_559 ; V_44 < ( V_559 + V_167 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_296 ( V_2 , V_64 , V_523 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_571 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_572 ) ;
}
V_64 -> V_102 = V_111 -> V_81 [ V_93 ] . V_102 ;
F_52 ( V_111 -> V_2 , 5 , L_246 , V_93 ) ;
F_4 ( V_111 -> V_2 , 5 , L_247 ) ;
F_52 ( V_111 -> V_2 , 5 , L_43 ,
F_313 ( V_64 -> V_102 ) ) ;
if ( F_56 ( V_111 , V_93 ) ) {
F_4 ( V_2 , 2 , L_248 ) ;
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
F_314 ( V_167 , & V_111 -> V_447 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_303 ( V_111 ) ;
F_310 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_271 )
V_2 -> V_439 . V_573 += F_295 () -
V_2 -> V_439 . V_570 ;
}
static inline int F_315 ( struct V_1 * V_2 , int V_574 )
{
if ( ( V_2 -> V_12 . type == V_15 ) && ( V_574 == 3 ) )
return 2 ;
return V_574 ;
}
int F_316 ( struct V_1 * V_2 , struct V_232 * V_233 ,
int V_575 , int V_576 )
{
T_3 * V_577 ;
V_277 V_578 ;
if ( V_576 && V_2 -> V_12 . V_313 )
return V_2 -> V_12 . V_313 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_303 ) {
case V_579 :
case V_580 :
switch ( V_575 ) {
case 4 :
V_578 = F_317 ( F_318 ( V_233 ) ) ;
break;
case 6 :
V_578 = F_319 ( F_320 ( V_233 ) ) ;
break;
default:
return V_2 -> V_46 . V_257 ;
}
if ( V_2 -> V_46 . V_303 == V_580 )
return F_315 ( V_2 , ~ V_578 >> 6 & 3 ) ;
if ( V_578 & V_581 )
return F_315 ( V_2 , 3 ) ;
if ( V_578 & V_582 )
return 2 ;
if ( V_578 & V_583 )
return 1 ;
if ( V_578 & V_584 )
return 0 ;
break;
case V_585 :
if ( V_233 -> V_586 > 5 )
return 0 ;
return F_315 ( V_2 , ~ V_233 -> V_586 >> 1 & 3 ) ;
case V_587 :
V_577 = & ( (struct V_588 * ) V_233 -> V_117 ) -> V_589 ;
if ( F_122 ( * V_577 ) == V_590 )
return F_315 ( V_2 ,
~ F_122 ( * ( V_577 + 1 ) ) >> ( V_591 + 1 ) & 3 ) ;
break;
default:
break;
}
return V_2 -> V_46 . V_257 ;
}
int F_321 ( struct V_232 * V_233 )
{
int V_177 , V_51 = 0 ;
for ( V_177 = 0 ; V_177 < F_322 ( V_233 ) -> V_592 ; V_177 ++ ) {
struct V_593 * V_594 = & F_322 ( V_233 ) -> V_595 [ V_177 ] ;
V_51 += F_323 (
( V_121 ) F_324 ( V_594 ) ,
( V_121 ) F_324 ( V_594 ) + F_325 ( V_594 ) ) ;
}
return V_51 ;
}
int F_326 ( struct V_1 * V_2 ,
struct V_232 * V_233 , int V_596 , int V_597 )
{
int V_51 = F_323 (
( V_121 ) V_233 -> V_117 + V_597 ,
( V_121 ) V_233 -> V_117 + F_327 ( V_233 ) ) +
F_321 ( V_233 ) ;
if ( ( V_51 + V_596 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_249
L_250 ,
V_51 + V_596 , V_233 -> V_163 ) ;
return 0 ;
}
return V_51 ;
}
int F_328 ( struct V_232 * V_233 , struct V_598 * * V_133 , int V_163 )
{
int V_599 , V_600 , V_601 ;
if ( ( ( unsigned long ) V_233 -> V_117 & V_602 ) !=
( ( ( unsigned long ) V_233 -> V_117 + V_163 - 1 ) & V_602 ) ) {
V_599 = F_329 ( V_233 ) ;
V_600 = V_405 - ( ( unsigned long ) V_233 -> V_117 % V_405 ) ;
V_601 = V_163 - V_600 ;
if ( V_601 > V_599 )
return 1 ;
memmove ( V_233 -> V_117 - V_601 , V_233 -> V_117 , F_327 ( V_233 ) ) ;
V_233 -> V_117 -= V_601 ;
V_233 -> V_603 -= V_601 ;
* V_133 = (struct V_598 * ) V_233 -> V_117 ;
F_68 ( 2 , L_251 , V_163 , V_601 ) ;
}
return 0 ;
}
static inline void F_330 ( struct V_232 * V_233 ,
struct V_522 * V_64 , int V_604 , int * V_255 ,
int V_184 )
{
int V_253 = F_327 ( V_233 ) ;
int V_605 ;
int V_245 ;
char * V_117 ;
int V_606 , V_177 ;
struct V_593 * V_594 ;
V_245 = * V_255 ;
V_117 = V_233 -> V_117 ;
V_606 = ( V_604 == 0 ? 1 : 0 ) ;
if ( V_184 >= 0 ) {
V_117 = V_233 -> V_117 + V_184 ;
V_253 -= V_184 ;
V_606 = 0 ;
}
while ( V_253 > 0 ) {
V_605 = V_405 - ( ( unsigned long ) V_117 % V_405 ) ;
if ( V_253 < V_605 )
V_605 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_605 ;
V_253 -= V_605 ;
if ( ! V_253 ) {
if ( V_606 )
if ( F_322 ( V_233 ) -> V_592 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_607 ;
else
V_64 -> V_245 [ V_245 ] . V_254 = 0 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_608 ;
} else {
if ( V_606 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_607 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_608 ;
}
V_117 += V_605 ;
V_245 ++ ;
V_606 = 0 ;
}
for ( V_177 = 0 ; V_177 < F_322 ( V_233 ) -> V_592 ; V_177 ++ ) {
V_594 = & F_322 ( V_233 ) -> V_595 [ V_177 ] ;
V_117 = ( char * ) F_331 ( F_332 ( V_594 ) ) +
V_594 -> V_609 ;
V_253 = V_594 -> V_610 ;
while ( V_253 > 0 ) {
V_605 = V_405 -
( ( unsigned long ) V_117 % V_405 ) ;
if ( V_253 < V_605 )
V_605 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_605 ;
V_64 -> V_245 [ V_245 ] . V_254 =
V_608 ;
V_253 -= V_605 ;
V_117 += V_605 ;
V_245 ++ ;
}
}
if ( V_64 -> V_245 [ V_245 - 1 ] . V_254 )
V_64 -> V_245 [ V_245 - 1 ] . V_254 = V_611 ;
* V_255 = V_245 ;
}
static inline int F_333 ( struct V_92 * V_111 ,
struct V_96 * V_231 , struct V_232 * V_233 ,
struct V_598 * V_133 , int V_184 , int V_612 )
{
struct V_522 * V_64 ;
int V_550 = 0 , V_613 , V_614 = 0 ;
V_64 = V_231 -> V_64 ;
F_334 ( & V_233 -> V_242 ) ;
F_335 ( & V_231 -> V_234 , V_233 ) ;
if ( V_133 -> V_133 . V_615 . V_308 == V_616 ) {
int V_245 = V_231 -> V_255 ;
V_613 = sizeof( struct V_617 ) +
( (struct V_617 * ) V_133 ) -> V_498 . V_618 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_233 -> V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_613 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_607 ;
V_231 -> V_255 ++ ;
V_233 -> V_117 += V_613 ;
V_233 -> V_163 -= V_613 ;
V_614 = 1 ;
}
if ( V_184 >= 0 ) {
int V_245 = V_231 -> V_255 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_133 ;
V_64 -> V_245 [ V_245 ] . V_253 = sizeof( struct V_598 ) +
V_612 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_607 ;
V_231 -> V_251 [ V_245 ] = 1 ;
V_231 -> V_255 ++ ;
}
F_330 ( V_233 , V_64 , V_614 ,
( int * ) & V_231 -> V_255 , V_184 ) ;
if ( ! V_111 -> V_446 ) {
F_4 ( V_111 -> V_2 , 6 , L_252 ) ;
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_550 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_253 ) ;
if ( V_111 -> V_2 -> V_66 . V_271 )
V_111 -> V_2 -> V_439 . V_619 ++ ;
if ( V_231 -> V_255 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_550 = 1 ;
}
}
return V_550 ;
}
int F_336 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_232 * V_233 ,
struct V_598 * V_133 , int V_184 , int V_612 )
{
struct V_96 * V_64 ;
int V_169 ;
while ( F_59 ( & V_111 -> V_3 , V_448 ,
V_620 ) != V_448 ) ;
V_169 = V_111 -> V_445 ;
V_64 = V_111 -> V_63 [ V_111 -> V_445 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 )
goto V_73;
V_111 -> V_445 = ( V_111 -> V_445 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_448 ) ;
F_333 ( V_111 , V_64 , V_233 , V_133 , V_184 , V_612 ) ;
F_300 ( V_111 , V_169 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_448 ) ;
return - V_621 ;
}
int F_337 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_232 * V_233 , struct V_598 * V_133 ,
int V_622 )
{
struct V_96 * V_64 ;
int V_623 ;
int V_624 = 0 ;
int V_446 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_448 ,
V_620 ) != V_448 ) ;
V_623 = V_111 -> V_445 ;
V_64 = V_111 -> V_63 [ V_111 -> V_445 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 ) {
F_60 ( & V_111 -> V_3 , V_448 ) ;
return - V_621 ;
}
F_298 ( V_111 ) ;
if ( V_111 -> V_446 ) {
V_446 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_255 ) < V_622 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_624 ++ ;
V_111 -> V_445 =
( V_111 -> V_445 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_445 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_249 ) {
F_300 ( V_111 , V_623 ,
V_624 ) ;
F_60 ( & V_111 -> V_3 ,
V_448 ) ;
V_37 = - V_621 ;
goto V_73;
}
}
}
V_41 = F_333 ( V_111 , V_64 , V_233 , V_133 , - 1 , 0 ) ;
V_111 -> V_445 = ( V_111 -> V_445 + V_41 ) %
V_62 ;
V_624 += V_41 ;
if ( V_624 )
F_300 ( V_111 , V_623 , V_624 ) ;
else if ( ! F_51 ( & V_111 -> V_248 ) )
F_236 ( & V_111 -> V_3 , V_552 ) ;
while ( F_338 ( & V_111 -> V_3 ) ) {
V_623 = V_111 -> V_445 ;
V_41 = F_299 ( V_111 ) ;
if ( ! V_41 && ! F_51 ( & V_111 -> V_248 ) )
V_41 = F_297 ( V_111 ) ;
if ( V_41 ) {
F_300 ( V_111 , V_623 , V_41 ) ;
V_624 += V_41 ;
}
}
V_73:
if ( V_111 -> V_2 -> V_66 . V_271 && V_446 )
V_111 -> V_2 -> V_439 . V_553 += V_624 ;
return V_37 ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_477 * V_625 ;
F_4 ( V_2 , 4 , L_254 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_625 = & ( V_130 -> V_117 . V_464 ) ;
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_255 , V_130 -> V_133 . V_139 ) ;
V_625 -> V_117 . V_626 = V_627 ;
}
V_2 -> V_12 . V_628 = V_625 -> V_117 . V_626 ;
return 0 ;
}
void F_340 ( struct V_1 * V_2 )
{
enum V_629 V_626 ;
struct V_630 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_256 ) ;
if ( ( ( V_9 -> V_32 & V_631 ) &&
( V_2 -> V_12 . V_628 == V_632 ) ) ||
( ! ( V_9 -> V_32 & V_631 ) &&
( V_2 -> V_12 . V_628 == V_627 ) ) )
return;
V_626 = V_627 ;
if ( V_9 -> V_32 & V_631 )
V_626 = V_632 ;
F_52 ( V_2 , 4 , L_257 , V_626 ) ;
V_113 = F_276 ( V_2 , V_633 ,
sizeof( struct V_495 ) + 8 ) ;
if ( ! V_113 )
return;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_464 . V_117 . V_626 = V_626 ;
F_272 ( V_2 , V_113 , F_339 , NULL ) ;
}
int F_341 ( struct V_630 * V_9 , int V_634 )
{
struct V_1 * V_2 ;
char V_635 [ 15 ] ;
V_2 = V_9 -> V_636 ;
F_4 ( V_2 , 4 , L_258 ) ;
sprintf ( V_635 , L_259 , V_634 ) ;
F_4 ( V_2 , 4 , V_635 ) ;
if ( ! F_210 ( V_2 , V_634 ) )
return - V_403 ;
V_9 -> V_401 = V_634 ;
return 0 ;
}
struct V_637 * F_342 ( struct V_630 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_636 ;
F_4 ( V_2 , 5 , L_260 ) ;
return & V_2 -> V_525 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_261 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_301 ||
! ( V_2 -> V_12 . V_638 & V_639 ) ) {
memcpy ( V_2 -> V_9 -> V_640 ,
& V_130 -> V_117 . V_464 . V_117 . V_641 . V_250 ,
V_642 ) ;
V_2 -> V_12 . V_638 |= V_639 ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int F_344 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_262 ) ;
V_113 = F_276 ( V_2 , V_643 ,
sizeof( struct V_495 ) +
sizeof( struct V_644 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_464 . V_117 . V_641 . V_130 = V_645 ;
V_130 -> V_117 . V_464 . V_117 . V_641 . V_646 = V_642 ;
memcpy ( & V_130 -> V_117 . V_464 . V_117 . V_641 . V_250 ,
V_2 -> V_9 -> V_640 , V_642 ) ;
V_37 = F_272 ( V_2 , V_113 , F_343 ,
NULL ) ;
return V_37 ;
}
static int F_345 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_647 * V_648 ;
int V_649 = * ( int * ) V_125 -> V_384 ;
F_4 ( V_2 , 4 , L_263 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_648 = & V_130 -> V_117 . V_464 . V_117 . V_650 ;
F_45 ( V_65 , 2 , L_263 ) ;
F_45 ( V_65 , 2 , L_264 , V_2 -> V_10 -> V_9 . V_651 . V_513 ) ;
F_45 ( V_65 , 2 , L_265 ,
V_130 -> V_117 . V_464 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_464 . V_133 . V_139 !=
V_652 )
F_68 ( 3 , L_266 ,
V_2 -> V_10 -> V_9 . V_651 . V_513 ,
V_648 -> V_653 ,
V_130 -> V_117 . V_464 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_464 . V_133 . V_139 ) {
case V_652 :
if ( V_2 -> V_66 . V_274 == V_275 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_267 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_268 ) ;
}
break;
case V_654 :
F_68 ( 2 , L_269
L_270 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_656 :
F_68 ( 2 , L_271
L_272 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_657 :
F_47 ( & V_2 -> V_10 -> V_9 , L_273
L_274 ) ;
break;
case V_658 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_275
L_276 ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_659 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_277 ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_660 :
F_47 ( & V_2 -> V_10 -> V_9 , L_278
L_279 ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_661 :
F_47 ( & V_2 -> V_10 -> V_9 , L_280
L_281 ) ;
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
case V_662 :
F_67 ( & V_2 -> V_10 -> V_9 , L_282
L_283 ) ;
break;
default:
if ( V_649 )
V_2 -> V_66 . V_274 = V_2 -> V_66 . V_655 ;
break;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_346 ( struct V_1 * V_2 ,
enum V_663 V_274 , int V_649 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_647 * V_648 ;
F_4 ( V_2 , 4 , L_284 ) ;
F_45 ( V_65 , 2 , L_284 ) ;
F_45 ( V_65 , 2 , L_264 , V_2 -> V_10 -> V_9 . V_651 . V_513 ) ;
V_113 = F_276 ( V_2 , V_664 ,
sizeof( struct V_495 ) +
sizeof( struct V_647 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_648 = & V_130 -> V_117 . V_464 . V_117 . V_650 ;
V_648 -> V_653 = V_274 ;
V_37 = F_272 ( V_2 , V_113 , F_345 ,
& V_649 ) ;
F_45 ( V_65 , 2 , L_265 , V_37 ) ;
return V_37 ;
}
int F_347 ( struct V_1 * V_2 , int V_649 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_285 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_281 ( V_2 , V_664 ) ) {
V_37 = F_346 ( V_2 ,
V_2 -> V_66 . V_274 , V_649 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_286 ,
V_2 -> V_10 -> V_9 . V_651 . V_513 ,
V_37 ) ;
V_37 = - V_334 ;
}
} else if ( V_2 -> V_66 . V_274 != V_275 ) {
V_2 -> V_66 . V_274 = V_275 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_273
L_274 ) ;
V_37 = - V_334 ;
}
return V_37 ;
}
void F_348 ( struct V_630 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_636 ;
F_4 ( V_2 , 4 , L_287 ) ;
V_2 -> V_525 . V_547 ++ ;
F_72 ( V_2 ) ;
}
static int F_349 ( struct V_630 * V_9 , int V_665 , int V_666 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
int V_37 = 0 ;
switch ( V_666 ) {
case V_667 :
V_37 = V_668 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_669 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_670 ;
break;
case V_671 :
V_37 = V_672 | V_673 | V_674 |
V_675 | V_676 | V_677 | V_678 |
V_679 ;
break;
case V_680 :
V_37 = ( V_9 -> V_640 [ 0 ] << 16 ) | ( V_9 -> V_640 [ 1 ] << 8 ) |
V_9 -> V_640 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_681 :
V_37 = ( V_9 -> V_640 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_682 :
V_37 = V_683 ;
break;
case V_684 :
V_37 = V_685 | V_686 | V_687 | V_688 |
V_689 | V_690 ;
break;
case V_691 :
break;
case V_692 :
break;
case V_693 :
break;
case V_694 :
break;
case V_695 :
V_37 = V_2 -> V_525 . V_696 ;
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
break;
case V_702 :
break;
case V_703 :
break;
default:
break;
}
return V_37 ;
}
static int F_350 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_163 ,
int (* F_193)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_381 )
{
V_186 V_704 , V_705 ;
F_4 ( V_2 , 4 , L_288 ) ;
memcpy ( V_113 -> V_117 , V_462 , V_388 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) ,
& V_2 -> V_352 . V_413 , V_368 ) ;
V_704 = ( V_706 ) V_388 + V_163 ;
V_705 = ( V_706 ) V_163 ;
memcpy ( F_351 ( V_113 -> V_117 ) , & V_704 , 2 ) ;
memcpy ( F_352 ( V_113 -> V_117 ) , & V_705 , 2 ) ;
memcpy ( F_353 ( V_113 -> V_117 ) , & V_705 , 2 ) ;
memcpy ( F_354 ( V_113 -> V_117 ) , & V_705 , 2 ) ;
return F_192 ( V_2 , V_388 + V_163 , V_113 ,
F_193 , V_381 ) ;
}
static int F_355 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_707 )
{
struct V_129 * V_130 ;
struct V_708 * V_709 ;
struct V_710 * V_711 ;
unsigned char * V_117 ;
V_185 V_712 ;
F_4 ( V_2 , 3 , L_289 ) ;
V_130 = (struct V_129 * ) V_707 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_184 ) ;
V_709 = (struct V_708 * ) V_125 -> V_384 ;
V_711 = & V_130 -> V_117 . V_464 . V_117 . V_711 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_290 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_464 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_464 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_291 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_712 = * ( ( V_185 * ) F_352 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_464 . V_133 . V_475 == 1 )
V_712 -= ( V_185 ) ( ( char * ) & V_711 -> V_117 - ( char * ) V_130 ) ;
else
V_712 -= ( V_185 ) ( ( char * ) & V_711 -> V_713 - ( char * ) V_130 ) ;
if ( ( V_709 -> V_714 - V_709 -> V_715 ) < V_712 ) {
F_52 ( V_2 , 4 , L_292 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_716 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_293 ,
V_130 -> V_117 . V_464 . V_133 . V_474 ) ;
F_52 ( V_2 , 4 , L_294 ,
V_130 -> V_117 . V_464 . V_133 . V_475 ) ;
if ( V_130 -> V_117 . V_464 . V_133 . V_475 == 1 ) {
memcpy ( V_709 -> V_717 + V_709 -> V_715 ,
( char * ) V_711 ,
V_712 + F_356 ( struct V_710 , V_117 ) ) ;
V_709 -> V_715 += F_356 ( struct V_710 , V_117 ) ;
} else {
memcpy ( V_709 -> V_717 + V_709 -> V_715 ,
( char * ) & V_711 -> V_713 , V_712 ) ;
}
V_709 -> V_715 += V_712 ;
F_52 ( V_2 , 4 , L_295 ,
V_130 -> V_117 . V_464 . V_133 . V_474 ) ;
F_52 ( V_2 , 4 , L_296 ,
V_130 -> V_117 . V_464 . V_133 . V_475 ) ;
if ( V_130 -> V_117 . V_464 . V_133 . V_475 <
V_130 -> V_117 . V_464 . V_133 . V_474 )
return 1 ;
return 0 ;
}
static int F_357 ( struct V_1 * V_2 , char T_4 * V_717 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_718 * V_719 ;
unsigned int V_720 ;
struct V_708 V_709 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_297 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_334 ;
if ( ( ! F_281 ( V_2 , V_721 ) ) &&
( ! V_2 -> V_66 . V_301 ) ) {
return - V_334 ;
}
if ( F_358 ( & V_720 , V_717 + sizeof( int ) , sizeof( int ) ) )
return - V_722 ;
if ( V_720 > ( V_118 - V_388 -
sizeof( struct V_723 ) -
sizeof( struct V_495 ) ) )
return - V_403 ;
V_719 = F_359 ( V_717 , V_720 + sizeof( struct V_724 ) ) ;
if ( F_116 ( V_719 ) ) {
F_4 ( V_2 , 2 , L_298 ) ;
return F_117 ( V_719 ) ;
}
V_709 . V_714 = V_719 -> V_133 . V_712 ;
V_709 . V_717 = F_27 ( V_709 . V_714 , V_49 ) ;
if ( ! V_709 . V_717 ) {
F_32 ( V_719 ) ;
return - V_50 ;
}
V_709 . V_715 = sizeof( struct V_724 ) ;
V_113 = F_276 ( V_2 , V_721 ,
V_725 + V_720 ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_73;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
memcpy ( & V_130 -> V_117 . V_464 . V_117 . V_711 , & V_719 -> V_130 , V_720 ) ;
V_37 = F_350 ( V_2 , V_113 , V_726 + V_720 ,
F_355 , ( void * ) & V_709 ) ;
if ( V_37 )
F_68 ( 2 , L_299 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_360 ( V_717 , V_709 . V_717 , V_709 . V_714 ) )
V_37 = - V_722 ;
}
V_73:
F_32 ( V_719 ) ;
F_32 ( V_709 . V_717 ) ;
return V_37 ;
}
static int F_361 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_727 * V_728 ;
char * V_729 ;
int V_730 ;
F_4 ( V_2 , 3 , L_300 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_728 = (struct V_727 * ) V_125 -> V_384 ;
V_730 = V_130 -> V_117 . V_464 . V_133 . V_472 ;
V_729 = ( char * ) V_117 + 28 ;
if ( V_730 > ( V_728 -> V_731 - V_728 -> V_732 ) ) {
V_130 -> V_133 . V_139 = V_733 ;
return 0 ;
}
memcpy ( ( V_728 -> V_64 + V_728 -> V_732 ) , V_729 ,
V_730 ) ;
V_728 -> V_732 += V_730 ;
if ( V_130 -> V_117 . V_464 . V_133 . V_475 <
V_130 -> V_117 . V_464 . V_133 . V_474 )
return 1 ;
return 0 ;
}
static int F_362 ( struct V_1 * V_2 , char T_4 * V_717 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_734 * V_735 ;
struct V_736 V_737 ;
struct V_727 V_728 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_301 ) ;
if ( ! F_281 ( V_2 , V_738 ) ) {
V_37 = - V_334 ;
goto V_73;
}
if ( F_358 ( & V_737 , V_717 ,
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
sizeof( struct V_495 ) +
sizeof( struct V_734 ) ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_739;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_735 = & V_130 -> V_117 . V_464 . V_117 . V_740 ;
V_735 -> V_653 = V_737 . V_134 ;
V_37 = F_272 ( V_2 , V_113 , F_361 ,
& V_728 ) ;
if ( ! V_37 ) {
if ( F_363 () )
V_41 = F_364 ( V_737 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_737 . V_43 ;
if ( F_360 ( V_41 , V_728 . V_64 ,
V_728 . V_732 ) ) {
V_37 = - V_722 ;
goto V_739;
}
V_737 . V_732 = V_728 . V_732 ;
if ( F_360 ( V_717 , & V_737 ,
sizeof( struct V_736 ) ) )
V_37 = - V_722 ;
} else
if ( V_37 == V_733 )
V_37 = - V_722 ;
V_739:
F_32 ( V_728 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_365 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_741 * V_742 ;
struct V_743 * V_743 ;
F_4 ( V_2 , 2 , L_302 ) ;
V_743 = (struct V_743 * ) V_125 -> V_384 ;
V_130 = (struct V_129 * ) V_117 ;
V_742 = & V_130 -> V_117 . V_464 . V_117 . V_742 ;
if ( V_130 -> V_117 . V_464 . V_133 . V_139 == 0 ) {
V_743 -> V_744 = V_742 -> V_744 ;
V_743 -> V_745 = V_742 -> V_745 ;
V_743 -> V_746 = V_742 -> V_746 ;
}
F_274 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int V_741 ( struct V_1 * V_2 ,
struct V_743 * V_743 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_303 ) ;
if ( ! F_281 ( V_2 , V_747 ) )
return - V_334 ;
V_113 = F_276 ( V_2 , V_747 ,
sizeof( struct V_495 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_272 ( V_2 , V_113 , F_365 ,
( void * ) V_743 ) ;
}
int F_366 ( struct V_1 * V_2 )
{
struct V_748 * V_749 ;
struct V_750 * V_713 ;
struct V_361 V_308 ;
int V_37 ;
F_41 ( V_65 , 2 , L_304 ) ;
if ( ! V_2 -> V_9 )
return - V_751 ;
V_713 = F_27 ( sizeof( * V_713 ) , V_49 | V_190 ) ;
V_749 = F_27 ( sizeof( * V_749 ) , V_49 | V_190 ) ;
if ( ! V_713 || ! V_749 ) {
V_37 = - V_50 ;
goto V_73;
}
F_181 ( F_44 ( V_2 ) , & V_308 ) ;
V_713 -> V_752 = sizeof( * V_749 ) ;
V_713 -> V_753 = V_754 ;
V_713 -> V_755 = V_756 ;
V_713 -> V_369 = V_308 . V_369 ;
V_37 = F_367 ( V_713 , V_749 , V_757 ) ;
if ( V_37 )
goto V_73;
if ( V_713 -> V_752 < sizeof( * V_749 ) ||
V_749 -> V_758 != V_713 -> V_753 ) {
V_37 = - V_116 ;
F_41 ( V_65 , 2 , L_305 ) ;
F_39 ( V_65 , 2 , & V_713 -> V_752 ,
sizeof( V_713 -> V_752 ) ) ;
} else if ( ! F_368 ( V_749 -> V_759 ) ) {
V_37 = - V_403 ;
F_41 ( V_65 , 2 , L_306 ) ;
F_39 ( V_65 , 2 , V_749 -> V_759 , V_760 ) ;
} else {
F_369 ( V_2 -> V_9 -> V_640 , V_749 -> V_759 ) ;
}
V_73:
F_32 ( V_749 ) ;
F_32 ( V_713 ) ;
return V_37 ;
}
static inline int F_370 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . type == V_15 )
return V_761 ;
else
return V_762 ;
}
static void F_371 ( struct V_1 * V_2 )
{
int V_37 ;
int V_253 ;
char * V_340 ;
struct V_158 * V_763 ;
int V_764 = 0 ;
F_41 ( V_65 , 2 , L_307 ) ;
V_763 = F_44 ( V_2 ) ;
if ( ! V_763 -> V_765 ) {
V_764 = 1 ;
V_37 = F_372 ( V_763 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_143 , V_37 ) ;
goto V_73;
}
}
V_37 = F_166 ( V_2 , ( void * * ) & V_340 , & V_253 ) ;
if ( V_37 ) {
F_68 ( 2 , L_308 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_766;
}
F_169 ( V_2 , V_340 ) ;
if ( V_764 )
F_171 ( V_2 , V_340 ) ;
F_32 ( V_340 ) ;
V_37 = F_373 ( V_763 , & V_2 -> V_767 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
F_45 ( V_65 , 2 , L_309 , V_2 -> V_767 . V_768 ) ;
F_45 ( V_65 , 2 , L_310 , V_2 -> V_767 . V_769 ) ;
F_45 ( V_65 , 2 , L_311 , V_2 -> V_767 . V_770 ) ;
F_45 ( V_65 , 2 , L_312 , V_2 -> V_767 . V_771 ) ;
F_45 ( V_65 , 2 , L_313 , V_2 -> V_767 . V_772 ) ;
if ( ! ( ( V_2 -> V_767 . V_768 != V_761 ) ||
( ( V_2 -> V_767 . V_769 & V_773 ) == 0 ) ||
( ( V_2 -> V_767 . V_771 & V_774 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_314 ) ;
} else {
V_2 -> V_66 . V_67 = V_558 ;
}
V_766:
if ( V_764 == 1 )
F_374 ( V_763 ) ;
V_73:
return;
}
static inline void F_375 ( struct V_1 * V_2 ,
struct V_522 * * V_775 ,
void (* * F_376) ( struct V_158 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_184 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_775 [ V_184 + V_44 ] = (struct V_522 * )
F_313 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_376 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_249 ( struct V_1 * V_2 )
{
struct V_776 V_777 ;
char * V_778 ;
struct V_522 * * V_775 ;
void (* * F_376) ( struct V_158 * , int , unsigned long );
struct V_522 * * V_779 ;
int V_44 , V_45 , V_780 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_315 ) ;
V_778 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_778 ) {
V_37 = - V_50 ;
goto V_781;
}
F_238 ( V_2 , V_778 ) ;
F_242 ( V_2 , V_778 ) ;
V_775 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_775 ) {
V_37 = - V_50 ;
goto V_782;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_775 [ V_44 ] = (struct V_522 * )
F_313 ( V_2 -> V_46 . V_421 -> V_63 [ V_44 ] . V_64 ) ;
}
F_376 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_376 ) {
V_37 = - V_50 ;
goto V_783;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_376 [ V_44 ] = V_2 -> V_149 -> V_784 ;
F_375 ( V_2 , V_775 , F_376 ) ;
V_779 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_779 ) {
V_37 = - V_50 ;
goto V_785;
}
for ( V_44 = 0 , V_780 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_780 ) {
V_779 [ V_780 ] = (struct V_522 * ) F_313 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_777 , 0 , sizeof( struct V_776 ) ) ;
V_777 . V_159 = F_44 ( V_2 ) ;
V_777 . V_786 = F_370 ( V_2 ) ;
V_777 . V_787 = 0 ;
V_777 . V_778 = V_778 ;
V_777 . V_788 = V_2 -> V_46 . V_72 ;
V_777 . V_789 = V_2 -> V_46 . V_78 ;
V_777 . V_790 = V_2 -> V_149 -> V_790 ;
V_777 . V_791 = V_2 -> V_149 -> V_791 ;
V_777 . V_792 = F_376 ;
V_777 . V_793 = ( unsigned long ) V_2 ;
V_777 . V_794 = ( void * * ) V_775 ;
V_777 . V_795 = ( void * * ) V_779 ;
V_777 . V_796 = V_2 -> V_46 . V_77 ;
V_777 . V_797 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_329 ,
V_325 ) == V_329 ) {
V_37 = F_377 ( & V_777 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_329 ) ;
goto V_73;
}
V_37 = F_378 ( & V_777 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_329 ) ;
F_250 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_316 ) ;
break;
case V_276 :
F_89 ( & V_2 -> V_10 -> V_9 , L_317 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_779 ) ;
V_785:
F_32 ( F_376 ) ;
V_783:
F_32 ( V_775 ) ;
V_782:
F_32 ( V_778 ) ;
V_781:
return V_37 ;
}
static void F_379 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_318 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_132 ( & V_2 -> V_114 ) ;
F_132 ( & V_2 -> V_155 ) ;
if ( V_2 -> V_9 )
F_380 ( V_2 -> V_9 ) ;
F_134 ( V_2 ) ;
F_381 ( & V_2 -> V_297 ) ;
F_32 ( V_2 ) ;
}
void F_382 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_319 ) ;
F_383 ( V_2 , 2 , & V_2 -> V_66 . V_480 , sizeof( V_2 -> V_66 . V_480 ) ) ;
F_383 ( V_2 , 2 , & V_2 -> V_66 . V_482 , sizeof( V_2 -> V_66 . V_482 ) ) ;
F_383 ( V_2 , 2 , & V_2 -> V_66 . V_467 , sizeof( V_2 -> V_66 . V_467 ) ) ;
F_383 ( V_2 , 2 , & V_2 -> V_12 . V_496 ,
sizeof( V_2 -> V_12 . V_496 ) ) ;
}
int F_384 ( struct V_1 * V_2 )
{
int V_798 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_320 ) ;
F_60 ( & V_2 -> V_529 , 0 ) ;
F_136 ( V_2 ) ;
V_799:
if ( V_798 < 3 )
F_68 ( 2 , L_321 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_164 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_374 ( F_44 ( V_2 ) ) ;
F_374 ( F_385 ( V_2 ) ) ;
F_374 ( F_154 ( V_2 ) ) ;
F_250 ( F_44 ( V_2 ) ) ;
V_37 = F_372 ( F_154 ( V_2 ) ) ;
if ( V_37 )
goto V_800;
V_37 = F_372 ( F_385 ( V_2 ) ) ;
if ( V_37 )
goto V_800;
V_37 = F_372 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_800;
V_800:
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_322 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_798 < 0 )
goto V_73;
else
goto V_799;
}
F_371 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
V_37 = F_176 ( & V_2 -> V_114 , F_188 ) ;
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_323 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_143 , V_37 ) ;
if ( -- V_798 < 0 )
goto V_73;
else
goto V_799;
}
V_37 = F_176 ( & V_2 -> V_155 , F_185 ) ;
if ( V_37 == - V_318 ) {
F_41 ( V_65 , 2 , L_324 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
if ( -- V_798 < 0 )
goto V_73;
else
goto V_799;
}
V_2 -> V_123 = 0 ;
V_37 = F_248 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_73;
}
V_37 = F_273 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
if ( V_37 == V_801 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_325 ) ;
V_2 -> V_143 = 0 ;
} else {
V_37 = - V_751 ;
goto V_73;
}
} else
V_2 -> V_143 = 1 ;
V_2 -> V_66 . V_480 . V_468 = 0 ;
V_2 -> V_66 . V_482 . V_468 = 0 ;
V_2 -> V_66 . V_467 . V_468 = 0 ;
V_2 -> V_66 . V_802 . V_468 = 0 ;
V_2 -> V_12 . V_496 = 0 ;
V_37 = F_279 ( V_2 , V_391 ) ;
if ( V_37 == - V_50 )
goto V_73;
if ( F_386 ( V_2 , V_481 ) ) {
V_37 = F_277 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_191 , V_37 ) ;
goto V_73;
}
}
if ( F_281 ( V_2 , V_803 ) ) {
V_37 = F_283 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_192 , V_37 ) ;
goto V_73;
}
}
return 0 ;
V_73:
F_67 ( & V_2 -> V_10 -> V_9 , L_106
L_107 ) ;
F_68 ( 2 , L_326 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
return V_37 ;
}
static inline int F_387 ( struct V_441 * V_804 ,
struct V_805 * V_245 ,
struct V_232 * * V_806 , int V_184 , int * V_807 , int V_712 )
{
struct V_437 * V_437 = F_260 ( V_245 -> V_250 ) ;
if ( * V_806 == NULL ) {
if ( V_804 -> V_428 ) {
* V_806 = V_804 -> V_428 ;
V_804 -> V_428 = NULL ;
} else {
* V_806 = F_264 ( V_442 + V_443 ) ;
if ( ! ( * V_806 ) )
return - V_50 ;
}
F_388 ( * V_806 , V_443 ) ;
if ( V_712 <= V_442 ) {
F_389 ( * V_806 , V_245 -> V_250 + V_184 , V_712 ) ;
} else {
F_390 ( V_437 ) ;
F_389 ( * V_806 , V_245 -> V_250 + V_184 ,
V_442 ) ;
F_391 ( * V_806 , * V_807 , V_437 ,
V_184 + V_442 ,
V_712 - V_442 ) ;
( * V_806 ) -> V_712 += V_712 - V_442 ;
( * V_806 ) -> V_163 += V_712 - V_442 ;
( * V_806 ) -> V_808 += V_712 - V_442 ;
( * V_807 ) ++ ;
}
} else {
F_390 ( V_437 ) ;
F_391 ( * V_806 , * V_807 , V_437 , V_184 , V_712 ) ;
( * V_806 ) -> V_712 += V_712 ;
( * V_806 ) -> V_163 += V_712 ;
( * V_806 ) -> V_808 += V_712 ;
( * V_807 ) ++ ;
}
return 0 ;
}
static inline int F_392 ( struct V_805 * V_809 )
{
return ( V_809 -> V_254 & V_444 ) ;
}
struct V_232 * F_393 ( struct V_1 * V_2 ,
struct V_441 * V_804 ,
struct V_805 * * V_810 , int * V_811 ,
struct V_598 * * V_133 )
{
struct V_805 * V_245 = * V_810 ;
struct V_522 * V_64 = V_804 -> V_64 ;
int V_184 = * V_811 ;
struct V_232 * V_233 = NULL ;
int V_812 = 0 ;
void * V_813 ;
int V_712 ;
int V_814 = 0 ;
int V_815 = 0 ;
int V_594 = 0 ;
if ( V_245 -> V_253 < V_184 + sizeof( struct V_598 ) ) {
if ( F_392 ( V_245 ) )
return NULL ;
V_245 ++ ;
V_184 = 0 ;
if ( V_245 -> V_253 < sizeof( struct V_598 ) )
return NULL ;
}
* V_133 = V_245 -> V_250 + V_184 ;
V_184 += sizeof( struct V_598 ) ;
switch ( ( * V_133 ) -> V_133 . V_816 . V_308 ) {
case V_817 :
V_812 = ( * V_133 ) -> V_133 . V_816 . V_818 ;
break;
case V_819 :
V_812 = ( * V_133 ) -> V_133 . V_615 . V_253 ;
V_814 = V_443 ;
break;
case V_820 :
V_812 = ( * V_133 ) -> V_133 . V_821 . V_822 ;
V_814 = sizeof( struct V_598 ) ;
break;
default:
break;
}
if ( ! V_812 )
return NULL ;
if ( ( ( V_812 >= V_2 -> V_66 . V_272 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_529 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_815 = 1 ;
} else {
V_233 = F_264 ( V_812 + V_814 ) ;
if ( ! V_233 )
goto V_823;
if ( V_814 )
F_388 ( V_233 , V_814 ) ;
}
V_813 = V_245 -> V_250 + V_184 ;
while ( V_812 ) {
V_712 = F_214 ( V_812 , ( int ) ( V_245 -> V_253 - V_184 ) ) ;
if ( V_712 ) {
if ( V_815 ) {
if ( F_387 ( V_804 , V_245 ,
& V_233 , V_184 , & V_594 , V_712 ) )
goto V_823;
} else {
F_389 ( V_233 , V_813 , V_712 ) ;
}
}
V_812 -= V_712 ;
if ( V_812 ) {
if ( F_392 ( V_245 ) ) {
F_4 ( V_2 , 4 , L_327 ) ;
F_383 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_128 ( V_233 ) ;
V_2 -> V_525 . V_696 ++ ;
return NULL ;
}
V_245 ++ ;
V_184 = 0 ;
V_813 = V_245 -> V_250 ;
} else {
V_184 += V_712 ;
}
}
* V_810 = V_245 ;
* V_811 = V_184 ;
if ( V_815 && V_2 -> V_66 . V_271 ) {
V_2 -> V_439 . V_824 ++ ;
V_2 -> V_439 . V_825 += F_322 ( V_233 ) -> V_592 ;
}
return V_233 ;
V_823:
if ( F_394 () ) {
F_4 ( V_2 , 2 , L_328 ) ;
}
V_2 -> V_525 . V_526 ++ ;
return NULL ;
}
int F_395 ( struct V_826 * V_556 , int V_827 )
{
struct V_1 * V_2 = F_3 ( V_556 , struct V_1 , V_556 ) ;
int V_828 = 0 ;
struct V_441 * V_64 ;
int V_829 ;
int V_830 = V_827 ;
if ( V_2 -> V_66 . V_271 ) {
V_2 -> V_439 . V_831 ++ ;
V_2 -> V_439 . V_832 = F_295 () ;
}
while ( 1 ) {
if ( ! V_2 -> V_833 . V_834 ) {
V_2 -> V_833 . V_535 = 0 ;
V_2 -> V_833 . V_834 = F_396 (
V_2 -> V_117 . V_119 , 0 , & V_2 -> V_833 . V_835 ,
& V_2 -> V_833 . V_535 ) ;
if ( V_2 -> V_833 . V_834 <= 0 ) {
V_2 -> V_833 . V_834 = 0 ;
break;
}
V_2 -> V_833 . V_836 =
& V_2 -> V_46 . V_421 -> V_63 [ V_2 -> V_833 . V_835 ]
. V_64 -> V_245 [ 0 ] ;
V_2 -> V_833 . V_837 = 0 ;
}
while ( V_2 -> V_833 . V_834 ) {
V_64 = & V_2 -> V_46 . V_421 -> V_63 [ V_2 -> V_833 . V_835 ] ;
if ( ! ( V_2 -> V_833 . V_535 &&
F_290 ( V_2 , V_64 -> V_64 ,
V_2 -> V_833 . V_535 , L_329 ) ) )
V_828 +=
V_2 -> V_149 -> V_838 (
V_2 , V_830 , & V_829 ) ;
else
V_829 = 1 ;
if ( V_829 ) {
if ( V_2 -> V_66 . V_271 )
V_2 -> V_439 . V_839 ++ ;
F_254 ( V_2 ,
V_64 -> V_40 ) ;
F_291 ( V_2 , V_2 -> V_833 . V_835 ) ;
V_2 -> V_833 . V_834 -- ;
if ( V_2 -> V_833 . V_834 ) {
V_2 -> V_833 . V_835 =
( V_2 -> V_833 . V_835 + 1 ) %
V_62 ;
V_2 -> V_833 . V_836 =
& V_2 -> V_46 . V_421
-> V_63 [ V_2 -> V_833 . V_835 ]
. V_64 -> V_245 [ 0 ] ;
V_2 -> V_833 . V_837 = 0 ;
}
}
if ( V_828 >= V_827 )
goto V_73;
else
V_830 = V_827 - V_828 ;
}
}
F_397 ( V_556 ) ;
if ( F_398 ( V_2 -> V_117 . V_119 , 0 ) )
F_307 ( & V_2 -> V_556 ) ;
V_73:
if ( V_2 -> V_66 . V_271 )
V_2 -> V_439 . V_840 += F_295 () -
V_2 -> V_439 . V_832 ;
return V_828 ;
}
int F_399 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_203 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 ) {
V_130 -> V_133 . V_139 = V_130 -> V_117 . V_841 . V_133 . V_139 ;
if ( V_130 -> V_133 . V_390 == V_391 )
V_2 -> V_66 . V_480 . V_483 = V_130 -> V_133 . V_459 ;
if ( V_130 -> V_133 . V_390 == V_484 )
V_2 -> V_66 . V_482 . V_483 = V_130 -> V_133 . V_459 ;
}
return 0 ;
}
struct V_112 * F_400 ( struct V_1 * V_2 ,
enum V_842 V_843 ,
V_185 V_335 , V_185 V_163 ,
enum V_450 V_451 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_330 ) ;
V_113 = F_268 ( V_2 , V_844 , V_451 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
V_130 -> V_117 . V_841 . V_133 . V_845 = V_843 ;
V_130 -> V_117 . V_841 . V_133 . V_253 = 8 + V_163 ;
V_130 -> V_117 . V_841 . V_133 . V_473 = V_335 ;
V_130 -> V_117 . V_841 . V_133 . V_139 = 0 ;
V_130 -> V_117 . V_841 . V_133 . V_475 = 0 ;
}
return V_113 ;
}
int F_401 ( struct V_1 * V_2 ,
struct V_112 * V_113 , V_185 V_163 , long V_117 ,
int (* F_193)( struct V_1 * ,
struct V_124 * , unsigned long ) ,
void * V_381 )
{
int V_37 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_331 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_388 ) ;
if ( V_163 <= sizeof( T_1 ) )
V_130 -> V_117 . V_841 . V_117 . V_846 = ( T_1 ) V_117 ;
else
memcpy ( & V_130 -> V_117 . V_841 . V_117 , ( void * ) V_117 , V_163 ) ;
V_37 = F_272 ( V_2 , V_113 , F_193 , V_381 ) ;
return V_37 ;
}
int F_402 ( struct V_1 * V_2 ,
enum V_842 V_843 ,
V_185 V_335 , long V_117 )
{
int V_37 ;
int V_253 = 0 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 4 , L_332 ) ;
if ( V_117 )
V_253 = sizeof( T_1 ) ;
V_113 = F_400 ( V_2 , V_843 , V_335 ,
V_253 , V_391 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_401 ( V_2 , V_113 , V_253 , V_117 ,
F_399 , NULL ) ;
return V_37 ;
}
static void F_403 ( void )
{
int V_847 ;
for ( V_847 = 0 ; V_847 < V_848 ; V_847 ++ ) {
F_404 ( V_849 [ V_847 ] . V_308 ) ;
V_849 [ V_847 ] . V_308 = NULL ;
}
}
void F_405 ( T_5 * V_308 , int V_371 , char * V_850 , ... )
{
char V_851 [ 32 ] ;
T_6 args ;
if ( ! F_406 ( V_308 , V_371 ) )
return;
va_start ( args , V_850 ) ;
vsnprintf ( V_851 , sizeof( V_851 ) , V_850 , args ) ;
va_end ( args ) ;
F_407 ( V_308 , V_371 , V_851 ) ;
}
static int F_408 ( void )
{
int V_332 ;
int V_847 ;
for ( V_847 = 0 ; V_847 < V_848 ; V_847 ++ ) {
V_849 [ V_847 ] . V_308 = F_409 ( V_849 [ V_847 ] . V_513 ,
V_849 [ V_847 ] . V_852 ,
V_849 [ V_847 ] . V_853 ,
V_849 [ V_847 ] . V_163 ) ;
if ( V_849 [ V_847 ] . V_308 == NULL ) {
F_403 () ;
return - V_50 ;
}
V_332 = F_410 ( V_849 [ V_847 ] . V_308 , V_849 [ V_847 ] . V_854 ) ;
if ( V_332 ) {
F_403 () ;
return V_332 ;
}
F_411 ( V_849 [ V_847 ] . V_308 , V_849 [ V_847 ] . V_371 ) ;
}
return 0 ;
}
int F_412 ( struct V_1 * V_2 ,
enum V_344 V_149 )
{
int V_37 = 0 ;
F_413 ( & V_855 ) ;
switch ( V_149 ) {
case V_346 :
V_2 -> V_149 = F_414 (
F_415 ( V_856 ) , L_333 ) ;
break;
case V_345 :
V_2 -> V_149 = F_414 (
F_415 ( V_857 ) , L_334 ) ;
break;
default:
break;
}
if ( ! V_2 -> V_149 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_335
L_336 , V_149 ) ;
V_37 = - V_403 ;
}
F_416 ( & V_855 ) ;
return V_37 ;
}
void F_417 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_301 )
F_418 ( V_857 ) ;
else
F_418 ( V_856 ) ;
V_2 -> V_149 = NULL ;
}
static T_5 * F_419 ( char * V_513 )
{
struct V_858 * V_434 ;
T_5 * V_37 = NULL ;
F_413 ( & V_859 ) ;
F_253 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_434 -> V_860 , V_513 ) == 0 ) {
V_37 = V_434 -> V_861 ;
break;
}
}
F_416 ( & V_859 ) ;
return V_37 ;
}
static int F_420 ( struct V_1 * V_2 , char * V_513 )
{
struct V_858 * V_862 ;
V_2 -> V_863 = F_409 ( V_513 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_863 ) {
F_45 ( V_65 , 2 , L_264 , L_337 ) ;
goto V_864;
}
if ( F_410 ( V_2 -> V_863 , & V_865 ) )
goto V_866;
V_862 = F_27 ( sizeof( struct V_858 ) , V_49 ) ;
if ( ! V_862 )
goto V_866;
strncpy ( V_862 -> V_860 , V_513 , V_867 ) ;
V_862 -> V_861 = V_2 -> V_863 ;
F_413 ( & V_859 ) ;
F_33 ( & V_862 -> V_868 , & V_869 ) ;
F_416 ( & V_859 ) ;
return 0 ;
V_866:
F_404 ( V_2 -> V_863 ) ;
V_864:
return - V_50 ;
}
static void F_421 ( void )
{
struct V_858 * V_434 , * V_41 ;
F_413 ( & V_859 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_434 -> V_868 ) ;
F_404 ( V_434 -> V_861 ) ;
F_32 ( V_434 ) ;
}
F_416 ( & V_859 ) ;
}
static int F_422 ( struct V_160 * V_10 )
{
struct V_1 * V_2 ;
struct V_870 * V_9 ;
int V_37 ;
enum V_344 V_871 ;
unsigned long V_32 ;
char V_860 [ V_867 ] ;
F_41 ( V_65 , 2 , L_338 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_423 ( V_9 ) )
return - V_751 ;
F_45 ( V_65 , 2 , L_264 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_151 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_872;
}
snprintf ( V_860 , sizeof( V_860 ) , L_339 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_863 = F_419 ( V_860 ) ;
if ( ! V_2 -> V_863 ) {
V_37 = F_420 ( V_2 , V_860 ) ;
if ( V_37 )
goto V_873;
}
V_2 -> V_114 . V_119 = V_10 -> V_159 [ 0 ] ;
V_2 -> V_155 . V_119 = V_10 -> V_159 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_159 [ 2 ] ;
F_424 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_159 [ 0 ] -> V_874 = F_118 ;
V_10 -> V_159 [ 1 ] -> V_874 = F_118 ;
V_10 -> V_159 [ 2 ] -> V_874 = F_118 ;
V_37 = F_153 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_143 , V_37 ) ;
goto V_873;
}
V_37 = F_144 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_135 , V_37 ) ;
goto V_873;
}
F_371 ( V_2 ) ;
V_871 = F_170 ( V_2 ) ;
switch ( V_871 ) {
case V_347 :
V_10 -> V_9 . type = & V_875 ;
break;
default:
V_2 -> V_12 . V_876 = true ;
V_37 = F_412 ( V_2 , V_871 ) ;
if ( V_37 )
goto V_873;
V_10 -> V_9 . type = ( V_2 -> V_12 . type != V_18 )
? V_2 -> V_149 -> V_877
: & V_878 ;
V_37 = V_2 -> V_149 -> V_879 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_880;
break;
}
F_425 ( & V_881 . V_882 , V_32 ) ;
F_102 ( & V_2 -> V_42 , & V_881 . V_42 ) ;
F_426 ( & V_881 . V_882 , V_32 ) ;
return 0 ;
V_880:
F_417 ( V_2 ) ;
V_873:
F_379 ( V_2 ) ;
V_872:
F_427 ( V_9 ) ;
return V_37 ;
}
static void F_428 ( struct V_160 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_340 ) ;
if ( V_2 -> V_149 ) {
V_2 -> V_149 -> remove ( V_10 ) ;
F_417 ( V_2 ) ;
}
F_425 ( & V_881 . V_882 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_426 ( & V_881 . V_882 , V_32 ) ;
F_379 ( V_2 ) ;
F_424 ( & V_10 -> V_9 , NULL ) ;
F_427 ( & V_10 -> V_9 ) ;
return;
}
static int F_429 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
enum V_344 V_883 ;
if ( ! V_2 -> V_149 ) {
if ( V_2 -> V_12 . type == V_15 )
V_883 = V_346 ;
else
V_883 = V_345 ;
V_37 = F_412 ( V_2 , V_883 ) ;
if ( V_37 )
goto V_864;
V_37 = V_2 -> V_149 -> V_879 ( V_2 -> V_10 ) ;
if ( V_37 ) {
F_417 ( V_2 ) ;
goto V_864;
}
}
V_37 = V_2 -> V_149 -> V_884 ( V_10 ) ;
V_864:
return V_37 ;
}
static int F_430 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
return V_2 -> V_149 -> V_885 ( V_10 ) ;
}
static void F_431 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_16 ( V_2 , 0 , 1 ) ;
if ( ( V_10 -> V_3 == V_886 ) && V_2 -> V_12 . V_145 )
F_289 ( V_2 , V_520 ) ;
F_164 ( V_2 , 0 ) ;
F_131 ( V_2 ) ;
F_250 ( F_44 ( V_2 ) ) ;
}
static int F_432 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_887 )
return V_2 -> V_149 -> V_887 ( V_10 ) ;
return 0 ;
}
static int F_433 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_888 )
return V_2 -> V_149 -> V_888 ( V_10 ) ;
return 0 ;
}
static int F_434 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_889 )
return V_2 -> V_149 -> V_889 ( V_10 ) ;
return 0 ;
}
static T_7 F_435 ( struct V_890 * V_891 , const char * V_231 ,
T_8 V_167 )
{
int V_864 ;
V_864 = F_436 ( V_892 ,
& V_893 , 3 , V_231 ) ;
return V_864 ? V_864 : V_167 ;
}
int F_437 ( struct V_630 * V_9 , struct V_894 * V_895 , int V_130 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
struct V_896 * V_897 ;
int V_37 = 0 ;
if ( ! V_2 )
return - V_751 ;
if ( ! F_1 ( V_2 ) )
return - V_751 ;
if ( V_2 -> V_12 . type == V_18 )
return - V_57 ;
switch ( V_130 ) {
case V_898 :
V_37 = F_357 ( V_2 , V_895 -> V_899 . V_900 ) ;
break;
case V_901 :
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_16 ||
V_2 -> V_12 . type == V_17 ) &&
! V_2 -> V_12 . V_13 )
return 1 ;
else
return 0 ;
case V_902 :
V_897 = F_438 ( V_895 ) ;
V_897 -> V_665 = 0 ;
break;
case V_903 :
V_897 = F_438 ( V_895 ) ;
if ( V_897 -> V_665 != 0 )
V_37 = - V_403 ;
else
V_897 -> V_904 = F_349 ( V_9 ,
V_897 -> V_665 , V_897 -> V_905 ) ;
break;
case V_906 :
V_37 = F_362 ( V_2 , V_895 -> V_899 . V_900 ) ;
break;
default:
if ( V_2 -> V_149 -> V_907 )
V_37 = V_2 -> V_149 -> V_907 ( V_9 , V_895 , V_130 ) ;
else
V_37 = - V_334 ;
}
if ( V_37 )
F_52 ( V_2 , 2 , L_341 , V_37 ) ;
return V_37 ;
}
int F_439 ( struct V_630 * V_9 , int V_908 )
{
switch ( V_908 ) {
case V_909 :
return ( sizeof( V_910 ) / V_911 ) ;
default:
return - V_403 ;
}
}
void F_440 ( struct V_630 * V_9 ,
struct V_912 * V_525 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
V_117 [ 0 ] = V_2 -> V_525 . V_913 -
V_2 -> V_439 . V_914 ;
V_117 [ 1 ] = V_2 -> V_439 . V_839 ;
V_117 [ 2 ] = V_2 -> V_525 . V_915 -
V_2 -> V_439 . V_916 ;
V_117 [ 3 ] = V_2 -> V_439 . V_549 ;
V_117 [ 4 ] = V_2 -> V_525 . V_915 - V_2 -> V_439 . V_916
- V_2 -> V_439 . V_619 ;
V_117 [ 5 ] = V_2 -> V_439 . V_549 - V_2 -> V_439 . V_553 ;
V_117 [ 6 ] = V_2 -> V_439 . V_619 ;
V_117 [ 7 ] = V_2 -> V_439 . V_553 ;
V_117 [ 8 ] = V_2 -> V_439 . V_917 ;
V_117 [ 9 ] = V_2 -> V_439 . V_918 ;
V_117 [ 10 ] = V_2 -> V_439 . V_824 ;
V_117 [ 11 ] = V_2 -> V_439 . V_825 ;
V_117 [ 12 ] = V_2 -> V_439 . V_440 ;
V_117 [ 13 ] = ( V_2 -> V_439 . V_919 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_439 . V_920 ;
V_117 [ 15 ] = V_2 -> V_439 . V_537 ;
V_117 [ 16 ] = V_2 -> V_439 . V_539 ;
V_117 [ 17 ] = V_538 ;
V_117 [ 18 ] = V_536 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_447 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_447 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_447 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_447 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_439 . V_840 ;
V_117 [ 24 ] = V_2 -> V_439 . V_831 ;
V_117 [ 25 ] = V_2 -> V_439 . V_534 ;
V_117 [ 26 ] = V_2 -> V_439 . V_532 ;
V_117 [ 27 ] = V_2 -> V_439 . V_573 ;
V_117 [ 28 ] = V_2 -> V_439 . V_569 ;
V_117 [ 29 ] = V_2 -> V_439 . V_921 ;
V_117 [ 30 ] = V_2 -> V_439 . V_922 ;
V_117 [ 31 ] = V_2 -> V_439 . V_546 ;
V_117 [ 32 ] = V_2 -> V_439 . V_542 ;
V_117 [ 33 ] = V_2 -> V_439 . V_923 ;
V_117 [ 34 ] = V_2 -> V_439 . V_924 ;
V_117 [ 35 ] = V_2 -> V_439 . V_925 ;
V_117 [ 36 ] = V_2 -> V_439 . V_560 ;
V_117 [ 37 ] = V_2 -> V_439 . V_565 ;
}
void F_441 ( struct V_630 * V_9 , V_706 V_908 , V_277 * V_117 )
{
switch ( V_908 ) {
case V_909 :
memcpy ( V_117 , & V_910 ,
sizeof( V_910 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_442 ( struct V_630 * V_9 ,
struct V_926 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
F_443 ( V_12 -> V_927 , V_2 -> V_66 . V_301 ? L_334 : L_333 ,
sizeof( V_12 -> V_927 ) ) ;
F_443 ( V_12 -> V_758 , L_342 , sizeof( V_12 -> V_758 ) ) ;
F_443 ( V_12 -> V_928 , V_2 -> V_12 . V_298 ,
sizeof( V_12 -> V_928 ) ) ;
snprintf ( V_12 -> V_929 , sizeof( V_12 -> V_929 ) , L_343 ,
F_444 ( V_2 ) , F_445 ( V_2 ) , F_446 ( V_2 ) ) ;
}
static void F_447 ( struct V_930 * V_130 ,
int V_931 , int V_932 )
{
F_448 ( V_130 , V_933 ) ;
F_448 ( V_130 , V_934 ) ;
F_448 ( V_130 , V_935 ) ;
F_449 ( V_130 , V_933 , V_936 ) ;
F_449 ( V_130 , V_934 , V_936 ) ;
switch ( V_932 ) {
case V_937 :
F_449 ( V_130 , V_933 , V_938 ) ;
F_449 ( V_130 , V_934 , V_938 ) ;
break;
case V_939 :
F_449 ( V_130 , V_933 , V_940 ) ;
F_449 ( V_130 , V_934 , V_940 ) ;
break;
default:
F_449 ( V_130 , V_933 , V_938 ) ;
F_449 ( V_130 , V_934 , V_938 ) ;
F_54 ( 1 ) ;
}
switch ( V_931 ) {
case V_941 :
F_449 ( V_130 , V_933 ,
10000baseT_Full ) ;
F_449 ( V_130 , V_934 ,
10000baseT_Full ) ;
case V_942 :
F_449 ( V_130 , V_933 ,
1000baseT_Full ) ;
F_449 ( V_130 , V_934 ,
1000baseT_Full ) ;
F_449 ( V_130 , V_933 ,
1000baseT_Half ) ;
F_449 ( V_130 , V_934 ,
1000baseT_Half ) ;
case V_943 :
F_449 ( V_130 , V_933 ,
100baseT_Full ) ;
F_449 ( V_130 , V_934 ,
100baseT_Full ) ;
F_449 ( V_130 , V_933 ,
100baseT_Half ) ;
F_449 ( V_130 , V_934 ,
100baseT_Half ) ;
case V_944 :
F_449 ( V_130 , V_933 ,
10baseT_Full ) ;
F_449 ( V_130 , V_934 ,
10baseT_Full ) ;
F_449 ( V_130 , V_933 ,
10baseT_Half ) ;
F_449 ( V_130 , V_934 ,
10baseT_Half ) ;
break;
default:
F_449 ( V_130 , V_933 ,
10baseT_Full ) ;
F_449 ( V_130 , V_934 ,
10baseT_Full ) ;
F_449 ( V_130 , V_933 ,
10baseT_Half ) ;
F_449 ( V_130 , V_934 ,
10baseT_Half ) ;
F_54 ( 1 ) ;
}
}
int F_450 ( struct V_630 * V_945 ,
struct V_930 * V_130 )
{
struct V_1 * V_2 = V_945 -> V_636 ;
enum V_449 V_19 ;
struct V_743 V_743 ;
int V_37 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_130 -> V_946 . V_947 = V_948 ;
V_130 -> V_946 . V_949 = V_950 ;
V_130 -> V_946 . V_951 = 0 ;
V_130 -> V_946 . V_952 = 0 ;
V_130 -> V_946 . V_953 = V_954 ;
V_130 -> V_946 . V_955 = V_954 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
V_130 -> V_946 . V_956 = V_943 ;
V_130 -> V_946 . V_957 = V_937 ;
break;
case V_22 :
case V_26 :
V_130 -> V_946 . V_956 = V_942 ;
V_130 -> V_946 . V_957 = V_939 ;
break;
case V_23 :
V_130 -> V_946 . V_956 = V_941 ;
V_130 -> V_946 . V_957 = V_939 ;
break;
default:
V_130 -> V_946 . V_956 = V_944 ;
V_130 -> V_946 . V_957 = V_937 ;
}
F_447 ( V_130 , V_130 -> V_946 . V_956 , V_130 -> V_946 . V_957 ) ;
if ( ! F_1 ( V_2 ) )
return - V_751 ;
V_37 = V_741 ( V_2 , & V_743 ) ;
if ( V_37 == - V_334 )
return 0 ;
if ( V_37 )
return V_37 ;
F_451 ( V_945 ,
L_344 ,
V_743 . V_744 ,
V_743 . V_745 ,
V_743 . V_746 ) ;
switch ( V_743 . V_744 ) {
case V_958 :
case V_959 :
V_130 -> V_946 . V_957 = V_937 ;
F_447 ( V_130 , V_942 , V_130 -> V_946 . V_957 ) ;
break;
case V_960 :
case V_961 :
V_130 -> V_946 . V_957 = V_939 ;
F_447 ( V_130 , V_942 , V_130 -> V_946 . V_957 ) ;
break;
case V_962 :
case V_963 :
V_130 -> V_946 . V_957 = V_939 ;
F_447 ( V_130 , V_941 , V_130 -> V_946 . V_957 ) ;
break;
}
switch ( V_743 . V_745 ) {
case V_964 :
V_130 -> V_946 . V_947 = V_948 ;
break;
case V_965 :
V_130 -> V_946 . V_947 = V_966 ;
break;
}
switch ( V_743 . V_746 ) {
case V_967 :
V_130 -> V_946 . V_956 = V_944 ;
break;
case V_968 :
V_130 -> V_946 . V_956 = V_943 ;
break;
case V_969 :
V_130 -> V_946 . V_956 = V_942 ;
break;
case V_970 :
V_130 -> V_946 . V_956 = V_941 ;
break;
}
return 0 ;
}
static int F_452 ( struct V_1 * V_2 ,
struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_129 * V_130 = (struct V_129 * ) V_117 ;
struct V_971 * V_972 =
(struct V_971 * ) V_125 -> V_384 ;
F_4 ( V_2 , 4 , L_345 ) ;
if ( V_130 -> V_133 . V_139 )
return 0 ;
memset ( V_972 , 0 , sizeof( * V_972 ) ) ;
if ( V_130 -> V_117 . V_841 . V_133 . V_473 == V_973 ) {
V_972 -> V_933 =
V_130 -> V_117 . V_841 . V_117 . V_974 . V_933 ;
F_52 ( V_2 , 3 , L_346 , V_972 -> V_933 ) ;
}
if ( V_130 -> V_117 . V_841 . V_133 . V_473 == V_975 ) {
V_972 -> V_933 =
V_130 -> V_117 . V_841 . V_117 . V_974 . V_933 ;
V_972 -> V_288 =
V_130 -> V_117 . V_841 . V_117 . V_974 . V_288 ;
F_52 ( V_2 , 3 , L_347 , V_972 -> V_933 ) ;
F_52 ( V_2 , 3 , L_348 , V_972 -> V_288 ) ;
}
return 0 ;
}
static int F_453 ( struct V_1 * V_2 ,
enum V_842 V_843 ,
V_185 V_335 , long V_117 ,
struct V_971 * V_972 )
{
struct V_112 * V_113 ;
int V_37 = - V_50 ;
F_4 ( V_2 , 4 , L_349 ) ;
V_113 = F_400 ( V_2 , V_843 , V_335 ,
sizeof( T_1 ) , V_391 ) ;
if ( V_113 )
V_37 = F_401 ( V_2 , V_113 , sizeof( T_1 ) , V_117 ,
F_452 ,
V_972 ) ;
return V_37 ;
}
static int F_454 ( struct V_1 * V_2 , int V_976 )
{
const T_1 V_977 = V_978 |
V_979 |
V_980 ;
struct V_971 V_972 ;
int V_37 ;
V_37 = F_453 ( V_2 , V_976 , V_973 , 0 ,
& V_972 ) ;
if ( ! V_37 ) {
if ( ( V_977 & V_972 . V_933 ) !=
V_977 )
V_37 = - V_116 ;
else if ( ! ( V_981 & V_972 . V_933 ) &&
V_976 == V_982 )
F_67 ( & V_2 -> V_10 -> V_9 ,
L_350 ,
F_81 ( V_2 ) ) ;
}
if ( V_37 ) {
F_402 ( V_2 , V_976 , V_983 , 0 ) ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_351 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
V_37 = F_453 ( V_2 , V_976 , V_975 ,
V_972 . V_933 , & V_972 ) ;
if ( ! V_37 ) {
if ( ( V_977 & V_972 . V_288 ) !=
V_977 )
V_37 = - V_116 ;
}
if ( V_37 ) {
F_402 ( V_2 , V_976 , V_983 , 0 ) ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_352 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
F_89 ( & V_2 -> V_10 -> V_9 , L_353 ,
V_976 == V_982 ? L_354 : L_355 ) ;
return 0 ;
}
static int F_455 ( struct V_1 * V_2 , int V_984 , int V_976 )
{
int V_37 = ( V_984 ) ? F_454 ( V_2 , V_976 )
: F_402 ( V_2 , V_976 ,
V_983 , 0 ) ;
return V_37 ? - V_116 : 0 ;
}
static int F_456 ( struct V_1 * V_2 , int V_984 )
{
int V_37 ;
F_4 ( V_2 , 3 , L_356 ) ;
if ( V_984 ) {
V_37 = F_402 ( V_2 , V_985 ,
V_973 , 0 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_357 ,
F_81 ( V_2 ) ) ;
return - V_116 ;
}
F_89 ( & V_2 -> V_10 -> V_9 , L_358 ) ;
} else {
V_37 = F_402 ( V_2 , V_985 ,
V_983 , 0 ) ;
}
return V_37 ;
}
int F_457 ( struct V_630 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
T_10 V_280 = V_9 -> V_986 ;
if ( V_280 & V_987 ) {
if ( F_455 ( V_2 , 1 , V_988 ) )
V_280 ^= V_987 ;
}
if ( V_280 & V_989 ) {
if ( F_455 ( V_2 , 1 , V_982 ) )
V_280 ^= V_989 ;
}
if ( V_280 & V_990 ) {
if ( F_456 ( V_2 , 1 ) )
V_280 ^= V_990 ;
}
if ( V_280 == V_9 -> V_986 )
return 0 ;
F_67 ( & V_2 -> V_10 -> V_9 ,
L_359 ) ;
V_9 -> V_986 = V_280 ;
return - V_116 ;
}
int F_458 ( struct V_630 * V_9 , T_10 V_986 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
T_10 V_991 = V_9 -> V_986 ^ V_986 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_360 ) ;
F_39 ( V_65 , 2 , & V_986 , sizeof( V_986 ) ) ;
if ( ( V_991 & V_987 ) ) {
V_37 = F_455 ( V_2 ,
V_986 & V_987 ? 1 : 0 ,
V_988 ) ;
if ( V_37 )
V_991 ^= V_987 ;
}
if ( ( V_991 & V_989 ) ) {
V_37 = F_455 ( V_2 ,
V_986 & V_989 ? 1 : 0 ,
V_982 ) ;
if ( V_37 )
V_991 ^= V_989 ;
}
if ( ( V_991 & V_990 ) ) {
V_37 = F_456 ( V_2 , V_986 & V_990 ? 1 : 0 ) ;
if ( V_37 )
V_991 ^= V_990 ;
}
if ( ( V_9 -> V_986 ^ V_986 ) == V_991 )
return 0 ;
V_9 -> V_986 ^= V_991 ;
return - V_116 ;
}
T_10 F_459 ( struct V_630 * V_9 ,
T_10 V_986 )
{
struct V_1 * V_2 = V_9 -> V_636 ;
F_41 ( V_65 , 2 , L_361 ) ;
if ( ! F_386 ( V_2 , V_988 ) )
V_986 &= ~ V_987 ;
if ( ! F_386 ( V_2 , V_982 ) )
V_986 &= ~ V_989 ;
if ( ! F_386 ( V_2 , V_985 ) )
V_986 &= ~ V_990 ;
if ( V_2 -> V_3 == V_55 ||
V_2 -> V_3 == V_56 )
V_986 = V_986 & ~ ( V_987 | V_989 |
V_990 ) ;
F_39 ( V_65 , 2 , & V_986 , sizeof( V_986 ) ) ;
return V_986 ;
}
static int T_11 F_460 ( void )
{
int V_37 ;
F_461 ( L_362 ) ;
F_139 ( & V_881 . V_42 ) ;
F_139 ( & V_869 ) ;
F_462 ( & V_881 . V_882 ) ;
F_145 ( & V_855 ) ;
V_11 = F_463 ( L_363 ) ;
V_37 = F_408 () ;
if ( V_37 )
goto V_992;
V_892 = F_464 ( L_364 ) ;
V_37 = F_465 ( V_892 ) ;
if ( V_37 )
goto V_993;
V_252 = F_466 ( L_365 ,
sizeof( struct V_598 ) + V_443 , 64 , 0 , NULL ) ;
if ( ! V_252 ) {
V_37 = - V_50 ;
goto V_994;
}
V_101 = F_466 ( L_366 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_995;
}
V_37 = F_467 ( & V_996 ) ;
if ( V_37 )
goto V_997;
V_893 . V_927 . V_998 = V_999 ;
V_37 = F_468 ( & V_893 ) ;
if ( V_37 )
goto V_1000;
return 0 ;
V_1000:
F_469 ( & V_996 ) ;
V_997:
F_470 ( V_101 ) ;
V_995:
F_470 ( V_252 ) ;
V_994:
F_471 ( V_892 ) ;
V_993:
F_403 () ;
V_992:
F_472 ( L_367 ) ;
return V_37 ;
}
static void T_12 F_473 ( void )
{
F_421 () ;
F_474 ( V_11 ) ;
F_475 ( & V_893 ) ;
F_469 ( & V_996 ) ;
F_470 ( V_101 ) ;
F_470 ( V_252 ) ;
F_471 ( V_892 ) ;
F_403 () ;
F_461 ( L_368 ) ;
}
