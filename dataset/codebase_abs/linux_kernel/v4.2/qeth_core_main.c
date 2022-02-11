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
if ( V_233 -> V_235 == V_236 ) {
if ( V_233 -> V_237 ) {
struct V_238 * V_239 = F_122 ( V_233 -> V_237 ) ;
V_239 -> V_240 ( V_233 , V_105 ) ;
}
}
if ( F_123 ( & V_231 -> V_234 , V_233 ) )
V_233 = NULL ;
else
V_233 = F_124 ( & V_231 -> V_234 , V_233 ) ;
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
V_233 = F_125 ( & V_231 -> V_234 ) ;
while ( V_233 ) {
F_4 ( V_231 -> V_60 -> V_2 , 5 , L_112 ) ;
F_52 ( V_231 -> V_60 -> V_2 , 5 , L_43 , ( long ) V_233 ) ;
if ( V_241 && V_233 -> V_235 == V_236 ) {
if ( V_233 -> V_237 ) {
V_239 = F_122 ( V_233 -> V_237 ) ;
V_239 -> V_240 ( V_233 , V_91 ) ;
}
}
F_126 ( & V_233 -> V_242 ) ;
F_127 ( V_233 ) ;
V_233 = F_125 ( & V_231 -> V_234 ) ;
}
}
static void F_62 ( struct V_92 * V_111 ,
struct V_96 * V_231 ,
enum V_243 V_244 )
{
int V_44 ;
if ( V_231 -> V_64 -> V_245 [ 0 ] . V_246 & V_247 )
F_126 ( & V_111 -> V_248 ) ;
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
static void F_128 ( struct V_92 * V_60 , int free )
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
static void F_130 ( struct V_161 * V_162 )
{
int V_177 ;
F_41 ( V_65 , 2 , L_114 ) ;
for ( V_177 = 0 ; V_177 < V_173 ; V_177 ++ )
F_32 ( V_162 -> V_113 [ V_177 ] . V_117 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 4 ) )
F_132 ( V_2 ) ;
V_2 -> V_46 . V_78 = 1 ;
if ( V_2 -> V_46 . V_257 != 0 )
F_89 ( & V_2 -> V_10 -> V_9 , L_115 ) ;
V_2 -> V_46 . V_257 = 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
if ( ( F_51 ( & V_2 -> V_46 . V_3 ) != V_256 ) &&
( V_2 -> V_46 . V_78 == 1 ) ) {
F_132 ( V_2 ) ;
V_2 -> V_46 . V_257 = 2 ;
}
V_2 -> V_46 . V_78 = 4 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_158 * V_119 ;
struct V_258 * V_259 ;
F_41 ( V_65 , 2 , L_116 ) ;
V_119 = V_2 -> V_117 . V_119 ;
V_259 = F_135 ( V_119 , 0 ) ;
if ( ! V_259 )
goto V_73;
V_2 -> V_12 . V_260 = 0x4100 + V_259 -> V_261 ;
if ( V_2 -> V_12 . type == V_15 )
goto V_73;
if ( ( V_259 -> V_262 & 0x02 ) == 0x02 )
F_131 ( V_2 ) ;
else
F_133 ( V_2 ) ;
V_73:
F_32 ( V_259 ) ;
F_45 ( V_65 , 2 , L_117 , V_2 -> V_46 . V_78 ) ;
F_45 ( V_65 , 2 , L_118 , V_2 -> V_12 . V_260 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 4 , L_119 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
V_2 -> V_46 . V_263 = V_264 ;
if ( V_2 -> V_12 . type == V_15 )
V_2 -> V_46 . V_47 . V_48 = V_265 ;
else
V_2 -> V_46 . V_47 . V_48 = V_266 ;
V_2 -> V_46 . V_58 . V_48 = V_2 -> V_46 . V_47 . V_48 ;
F_137 ( & V_2 -> V_46 . V_58 . V_53 ) ;
F_137 ( & V_2 -> V_46 . V_47 . V_53 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
V_2 -> V_66 . V_267 . type = V_268 ;
V_2 -> V_66 . V_269 . type = V_268 ;
V_2 -> V_66 . V_270 = 0 ;
V_2 -> V_66 . V_271 = V_272 ;
V_2 -> V_66 . V_273 = 0 ;
V_2 -> V_66 . V_274 = V_275 ;
V_2 -> V_66 . V_276 = V_277 ;
V_2 -> V_66 . V_67 = V_278 ;
}
static int F_139 ( struct V_1 * V_2 , unsigned long V_191 )
{
unsigned long V_32 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_33 , V_32 ) ;
F_52 ( V_2 , 4 , L_120 ,
( V_279 ) V_2 -> V_35 ,
( V_279 ) V_2 -> V_34 ,
( V_279 ) V_2 -> V_38 ) ;
V_37 = ( V_2 -> V_35 & V_191 ) ;
F_18 ( & V_2 -> V_33 , V_32 ) ;
return V_37 ;
}
static void F_140 ( struct V_6 * V_7 )
{
struct V_280 * V_281 ;
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_193 ) ;
F_4 ( V_2 , 2 , L_121 ) ;
if ( V_2 -> V_114 . V_3 != V_115 &&
V_2 -> V_155 . V_3 != V_115 )
return;
if ( F_139 ( V_2 , V_192 ) ) {
V_281 = F_141 ( V_2 -> V_149 -> V_282 , ( void * ) V_2 ,
L_122 ) ;
if ( F_116 ( V_281 ) ) {
F_108 ( V_2 , V_192 ) ;
F_109 ( V_2 ,
V_192 ) ;
}
}
}
static int F_142 ( struct V_1 * V_2 )
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
F_105 ( & V_2 -> V_283 ) ;
F_105 ( & V_2 -> V_284 ) ;
F_105 ( & V_2 -> V_154 ) ;
F_105 ( & V_2 -> V_285 ) ;
F_105 ( & V_2 -> V_33 ) ;
F_143 ( & V_2 -> V_286 ) ;
F_143 ( & V_2 -> V_287 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_38 = 0 ;
F_144 ( & V_2 -> V_193 , F_140 ) ;
F_137 ( & V_2 -> V_288 ) ;
F_137 ( V_2 -> V_289 ) ;
F_137 ( & V_2 -> V_187 ) ;
F_106 ( & V_2 -> V_36 ) ;
F_138 ( V_2 ) ;
F_137 ( & V_2 -> V_290 . V_291 ) ;
V_2 -> V_290 . V_292 = 0 ;
V_2 -> V_290 . V_293 = 0 ;
V_2 -> V_290 . V_294 = 0 ;
F_136 ( V_2 ) ;
F_145 ( & V_2 -> V_295 , V_296 ) ;
F_144 ( & V_2 -> V_8 , F_2 ) ;
return 0 ;
}
static void F_146 ( struct V_297 * V_298 , struct V_299 * V_300 )
{
struct V_1 * V_2 = F_3 ( V_300 , struct V_1 ,
V_301 ) ;
if ( V_2 -> V_12 . V_302 [ 0 ] )
F_147 ( V_298 , L_124 ,
F_148 ( V_2 ) , V_2 -> V_12 . V_302 ) ;
}
static struct V_1 * F_149 ( void )
{
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_125 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_190 | V_49 ) ;
if ( ! V_2 )
goto V_73;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_289 = F_27 ( sizeof( struct V_303 ) , V_49 ) ;
if ( ! V_2 -> V_289 ) {
F_41 ( V_65 , 0 , L_126 ) ;
goto V_304;
}
if ( F_104 ( & V_2 -> V_114 ) )
goto V_305;
if ( F_104 ( & V_2 -> V_155 ) )
goto V_306;
V_2 -> V_66 . V_307 = - 1 ;
V_2 -> V_301 . V_308 = F_146 ;
F_150 ( & V_2 -> V_301 ) ;
return V_2 ;
V_306:
F_130 ( & V_2 -> V_114 ) ;
V_305:
F_32 ( V_2 -> V_289 ) ;
V_304:
F_32 ( V_2 ) ;
V_73:
return NULL ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
F_41 ( V_65 , 2 , L_127 ) ;
V_2 -> V_46 . V_309 = V_310 ;
V_2 -> V_46 . V_257 = V_311 ;
while ( V_312 [ V_44 ] [ V_313 ] ) {
if ( ( F_152 ( V_2 ) -> V_314 . V_315 ==
V_312 [ V_44 ] [ V_316 ] ) &&
( F_152 ( V_2 ) -> V_314 . V_317 ==
V_312 [ V_44 ] [ V_313 ] ) ) {
V_2 -> V_12 . type = V_312 [ V_44 ] [ V_313 ] ;
V_2 -> V_46 . V_78 =
V_312 [ V_44 ] [ V_318 ] ;
V_2 -> V_46 . V_72 = 1 ;
V_2 -> V_12 . V_319 =
V_312 [ V_44 ] [ V_320 ] ;
F_134 ( V_2 ) ;
return 0 ;
}
V_44 ++ ;
}
V_2 -> V_12 . type = V_321 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_128
L_129 ) ;
return - V_322 ;
}
static int F_153 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_130 ) ;
F_17 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_155 ( V_162 -> V_119 , V_222 ) ;
F_18 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_156 ( V_2 -> V_36 ,
V_162 -> V_3 == V_219 , V_323 ) ;
if ( V_37 == - V_324 )
return V_37 ;
if ( V_162 -> V_3 != V_219 )
return - V_325 ;
V_162 -> V_3 = V_216 ;
return 0 ;
}
static int F_157 ( struct V_161 * V_162 )
{
unsigned long V_32 ;
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_4 ( V_2 , 3 , L_131 ) ;
F_17 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_158 ( V_162 -> V_119 , V_223 ) ;
F_18 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_156 ( V_2 -> V_36 ,
V_162 -> V_3 == V_221 , V_323 ) ;
if ( V_37 == - V_324 )
return V_37 ;
if ( V_162 -> V_3 != V_221 )
return - V_325 ;
return 0 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_326 = 0 , V_327 = 0 , V_328 = 0 ;
F_4 ( V_2 , 3 , L_132 ) ;
V_326 = F_157 ( & V_2 -> V_114 ) ;
V_327 = F_157 ( & V_2 -> V_155 ) ;
V_328 = F_157 ( & V_2 -> V_117 ) ;
if ( V_326 )
return V_326 ;
if ( V_327 )
return V_327 ;
return V_328 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_326 = 0 , V_327 = 0 , V_328 = 0 ;
F_4 ( V_2 , 3 , L_133 ) ;
V_326 = F_153 ( & V_2 -> V_114 ) ;
V_327 = F_153 ( & V_2 -> V_155 ) ;
V_328 = F_153 ( & V_2 -> V_117 ) ;
if ( V_326 )
return V_326 ;
if ( V_327 )
return V_327 ;
return V_328 ;
}
static int F_161 ( struct V_1 * V_2 , int V_329 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_134 ) ;
if ( V_329 )
V_37 = F_159 ( V_2 ) ;
if ( V_37 )
return V_37 ;
return F_160 ( V_2 ) ;
}
int F_162 ( struct V_1 * V_2 , int V_330 )
{
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_135 ) ;
switch ( F_59 ( & V_2 -> V_46 . V_3 , V_331 ,
V_332 ) ) {
case V_331 :
if ( V_2 -> V_12 . type == V_15 )
V_37 = F_163 ( F_44 ( V_2 ) ,
V_333 ) ;
else
V_37 = F_163 ( F_44 ( V_2 ) ,
V_334 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_37 , V_37 ) ;
F_60 ( & V_2 -> V_46 . V_3 , V_335 ) ;
break;
case V_332 :
return V_37 ;
default:
break;
}
V_37 = F_161 ( V_2 , V_330 ) ;
if ( V_37 )
F_52 ( V_2 , 3 , L_136 , V_37 ) ;
V_2 -> V_3 = V_55 ;
return V_37 ;
}
static int F_164 ( struct V_1 * V_2 , void * * V_64 ,
int * V_253 )
{
struct V_336 * V_336 ;
char * V_337 ;
int V_338 ;
struct V_161 * V_162 = & V_2 -> V_117 ;
unsigned long V_32 ;
V_336 = F_165 ( V_162 -> V_119 , V_339 ) ;
if ( ! V_336 || V_336 -> V_130 == 0 )
return - V_340 ;
V_337 = F_27 ( V_336 -> V_167 , V_49 | V_190 ) ;
if ( ! V_337 )
return - V_50 ;
V_162 -> V_120 . V_341 = V_336 -> V_130 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_337 ) ;
V_162 -> V_120 . V_167 = V_336 -> V_167 ;
V_162 -> V_120 . V_32 = V_342 ;
V_162 -> V_3 = V_343 ;
F_17 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
V_338 = F_166 ( V_162 -> V_119 , & V_162 -> V_120 ,
V_215 , V_344 , 0 ,
V_345 ) ;
F_18 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
if ( ! V_338 )
F_100 ( V_2 -> V_36 ,
( V_162 -> V_3 == V_229 ||
V_162 -> V_3 == V_216 ) ) ;
if ( V_162 -> V_3 == V_216 )
V_338 = - V_116 ;
else
V_162 -> V_3 = V_216 ;
if ( V_338 ) {
F_32 ( V_337 ) ;
* V_64 = NULL ;
* V_253 = 0 ;
} else {
* V_253 = V_336 -> V_167 ;
* V_64 = V_337 ;
}
return V_338 ;
}
static void F_167 ( struct V_1 * V_2 , char * V_346 )
{
F_41 ( V_65 , 2 , L_137 ) ;
V_2 -> V_12 . V_142 = V_346 [ 30 ] ;
V_2 -> V_12 . V_347 = V_346 [ 31 ] ;
V_2 -> V_12 . V_348 = V_346 [ 63 ] ;
V_2 -> V_12 . V_13 = ( ( V_346 [ 0x10 ] == V_349 [ 'V' ] ) &&
( V_346 [ 0x11 ] == V_349 [ 'M' ] ) ) ;
}
static void F_168 ( struct V_1 * V_2 , char * V_346 )
{
F_41 ( V_65 , 2 , L_138 ) ;
if ( V_346 [ 74 ] == 0xF0 && V_346 [ 75 ] == 0xF0 &&
V_346 [ 76 ] >= 0xF1 && V_346 [ 76 ] <= 0xF4 ) {
V_2 -> V_12 . V_350 . V_351 = 0 ;
V_2 -> V_12 . V_350 . V_352 = 0 ;
V_2 -> V_12 . V_350 . V_353 = 0 ;
} else {
V_2 -> V_12 . V_350 . V_351 = 250 ;
V_2 -> V_12 . V_350 . V_352 = 5 ;
V_2 -> V_12 . V_350 . V_353 = 15 ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
V_2 -> V_354 . V_355 = 0x00010103UL ;
V_2 -> V_354 . V_356 = 0x00010108UL ;
V_2 -> V_354 . V_357 = 0x0001010aUL ;
V_2 -> V_354 . V_358 = 0x0001010bUL ;
V_2 -> V_354 . V_359 = 0x0001010dUL ;
}
static void F_170 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
V_2 -> V_12 . V_260 = V_360 ;
break;
case V_14 :
case V_18 :
V_2 -> V_12 . V_260 = V_361 ;
break;
default:
break;
}
}
static int F_171 ( struct V_161 * V_162 ,
void (* F_172)( struct V_161 * ,
struct V_112 * ) )
{
struct V_112 * V_113 ;
unsigned long V_32 ;
int V_37 ;
struct V_1 * V_2 ;
F_41 ( V_65 , 2 , L_139 ) ;
V_2 = F_94 ( V_162 -> V_119 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_172 ;
memcpy ( & V_162 -> V_120 , V_164 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_118 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_140 , V_37 ) ;
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_156 ( V_2 -> V_36 ,
V_162 -> V_3 == V_115 , V_323 ) ;
if ( V_37 == - V_324 )
return V_37 ;
if ( V_162 -> V_3 != V_115 ) {
V_37 = - V_325 ;
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
F_101 ( V_162 ) ;
} else
V_37 = 0 ;
return V_37 ;
}
static int F_173 ( struct V_161 * V_162 ,
void (* F_172)( struct V_161 * ,
struct V_112 * ) )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
unsigned long V_32 ;
V_185 V_362 ;
T_2 V_41 ;
int V_37 ;
struct V_363 V_364 ;
V_2 = F_94 ( V_162 -> V_119 ) ;
F_41 ( V_65 , 2 , L_142 ) ;
V_113 = F_66 ( V_162 ) ;
if ( ! V_113 )
return - V_50 ;
V_113 -> V_175 = F_172 ;
memcpy ( & V_162 -> V_120 , V_166 , sizeof( struct V_165 ) ) ;
V_162 -> V_120 . V_167 = V_365 ;
V_162 -> V_120 . V_168 = ( T_1 ) F_96 ( V_113 -> V_117 ) ;
if ( V_162 == & V_2 -> V_155 ) {
memcpy ( V_113 -> V_117 , V_366 , V_365 ) ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_367 , V_189 ) ;
V_2 -> V_182 . V_367 ++ ;
} else {
memcpy ( V_113 -> V_117 , V_368 , V_365 ) ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_367 , V_189 ) ;
}
V_41 = ( ( T_2 ) V_2 -> V_12 . V_369 ) | 0x80 ;
memcpy ( F_175 ( V_113 -> V_117 ) , & V_41 , 1 ) ;
memcpy ( F_176 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_355 , V_370 ) ;
memcpy ( F_177 ( V_113 -> V_117 ) ,
& V_2 -> V_12 . V_260 , sizeof( V_185 ) ) ;
F_178 ( F_44 ( V_2 ) , & V_364 ) ;
memcpy ( F_179 ( V_113 -> V_117 ) , & V_364 . V_371 , 2 ) ;
V_362 = ( V_2 -> V_12 . V_348 << 8 ) + V_2 -> V_12 . V_347 ;
memcpy ( F_180 ( V_113 -> V_117 ) , & V_362 , 2 ) ;
F_100 ( V_2 -> V_36 ,
F_59 ( & V_162 -> V_122 , 0 , 1 ) == 0 ) ;
F_41 ( V_65 , 6 , L_52 ) ;
F_17 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
V_37 = F_71 ( V_162 -> V_119 ,
& V_162 -> V_120 , ( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_162 -> V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_143 ,
V_37 ) ;
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
F_60 ( & V_162 -> V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_37 = F_156 ( V_2 -> V_36 ,
V_162 -> V_3 == V_372 , V_323 ) ;
if ( V_37 == - V_324 )
return V_37 ;
if ( V_162 -> V_3 != V_372 ) {
F_67 ( & V_162 -> V_119 -> V_9 , L_144
L_145 ) ;
F_68 ( 2 , L_146 ,
F_69 ( & V_162 -> V_119 -> V_9 ) ) ;
F_45 ( V_65 , 2 , L_136 , - V_325 ) ;
F_101 ( V_162 ) ;
return - V_325 ;
}
return F_171 ( V_162 , F_172 ) ;
}
static int F_181 ( int V_373 )
{
if ( ( V_373 & 0xff ) == 8 )
return ( V_373 & 0xff ) + 0x400 ;
if ( ( ( V_373 >> 8 ) & 3 ) == 1 )
return ( V_373 & 0xff ) + 0x200 ;
return V_373 ;
}
static void F_182 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_362 ;
F_41 ( V_65 , 2 , L_147 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_372 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( ! ( F_183 ( V_113 -> V_117 ) ) ) {
if ( F_184 ( V_113 -> V_117 ) == V_374 )
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_148
L_149 ) ;
else
F_68 ( 2 , L_150
L_151 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ) ;
goto V_73;
}
memcpy ( & V_362 , F_177 ( V_113 -> V_117 ) , 2 ) ;
if ( ( V_362 & ~ 0x0100 ) != F_181 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_152
L_153
L_154 , F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_362 ) ;
goto V_73;
}
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
static void F_185 ( struct V_161 * V_162 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 ;
V_185 V_362 ;
F_41 ( V_65 , 2 , L_155 ) ;
if ( V_162 -> V_3 == V_216 ) {
V_162 -> V_3 = V_372 ;
goto V_73;
}
V_2 = F_94 ( V_162 -> V_119 ) ;
if ( F_93 ( V_2 , V_113 -> V_117 ) )
goto V_73;
if ( ! ( F_183 ( V_113 -> V_117 ) ) ) {
switch ( F_184 ( V_113 -> V_117 ) ) {
case V_374 :
F_47 ( & V_2 -> V_155 . V_119 -> V_9 ,
L_148
L_149 ) ;
break;
case V_375 :
case V_376 :
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
V_2 -> V_12 . V_377 = 1 ;
memcpy ( & V_362 , F_177 ( V_113 -> V_117 ) , 2 ) ;
if ( V_362 != F_181 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_160
L_161 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_362 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_354 . V_378 ,
F_176 ( V_113 -> V_117 ) ,
V_370 ) ;
memcpy ( & V_2 -> V_12 . V_302 [ 0 ] ,
F_187 ( V_113 -> V_117 ) , V_379 ) ;
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
void F_188 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_155 , V_113 -> V_117 , V_163 ) ;
V_113 -> V_175 = F_98 ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_367 , V_189 ) ;
V_2 -> V_182 . V_367 ++ ;
memcpy ( F_103 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_380 , V_189 ) ;
V_2 -> V_182 . V_380 ++ ;
memcpy ( F_189 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_188 , V_189 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
}
int F_190 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 ,
int (* F_191)( struct V_1 * V_381 ,
struct V_124 * V_382 ,
unsigned long V_383 ) ,
void * V_384 )
{
int V_37 ;
unsigned long V_32 ;
struct V_124 * V_125 = NULL ;
unsigned long V_385 , V_386 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 2 , L_162 ) ;
if ( V_2 -> V_123 ) {
F_98 ( V_113 -> V_162 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_175 = F_191 ;
V_125 -> V_387 = V_384 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_182 = V_183 ;
else
V_125 -> V_182 = V_2 -> V_182 . V_388 ++ ;
F_106 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_102 ( & V_125 -> V_42 , & V_2 -> V_187 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
while ( F_59 ( & V_2 -> V_155 . V_122 , 0 , 1 ) ) ;
F_188 ( V_2 , V_163 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_386 = V_389 ;
else
V_386 = V_323 ;
V_385 = V_390 + V_386 ;
F_4 ( V_2 , 6 , L_52 ) ;
F_17 ( F_154 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
V_37 = F_71 ( V_2 -> V_155 . V_119 , & V_2 -> V_155 . V_120 ,
( V_121 ) V_113 , 0 , 0 ) ;
F_18 ( F_154 ( V_2 -> V_155 . V_119 ) , V_32 ) ;
if ( V_37 ) {
F_68 ( 2 , L_163
L_164 ,
F_69 ( & V_2 -> V_155 . V_119 -> V_9 ) , V_37 ) ;
F_52 ( V_2 , 2 , L_165 , V_37 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_92 ( & V_125 -> V_42 ) ;
F_77 ( V_125 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_98 ( V_113 -> V_162 , V_113 ) ;
F_60 ( & V_2 -> V_155 . V_122 , 0 ) ;
F_19 ( & V_2 -> V_36 ) ;
return V_37 ;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
if ( ( V_130 -> V_133 . V_134 == V_392 ) &&
( V_130 -> V_133 . V_393 == V_394 ) ) {
if ( ! F_192 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_386 ) )
goto V_395;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_193 ( V_390 , V_385 ) )
goto V_395;
F_194 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_395:
V_125 -> V_37 = - V_325 ;
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
F_41 ( V_65 , 2 , L_166 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_396 ,
F_196 ( V_113 -> V_117 ) ,
V_370 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_167 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_397 , V_398 ) ;
memcpy ( F_198 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_378 , V_370 ) ;
memcpy ( F_199 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_356 , V_370 ) ;
V_37 = F_190 ( V_2 , V_398 , V_113 ,
F_195 , NULL ) ;
return V_37 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_399 ,
F_201 ( V_113 -> V_117 ) ,
V_370 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_400 , V_401 ) ;
memcpy ( F_203 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_378 , V_370 ) ;
memcpy ( F_204 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_357 , V_370 ) ;
memcpy ( F_205 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_396 , V_370 ) ;
V_37 = F_190 ( V_2 , V_401 , V_113 ,
F_200 , NULL ) ;
return V_37 ;
}
static inline int F_206 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_321 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_402 ;
case V_14 :
switch ( V_2 -> V_12 . V_19 ) {
case V_21 :
case V_25 :
return 2000 ;
default:
return V_2 -> V_66 . V_307 ? 1500 : 1492 ;
}
case V_16 :
case V_17 :
return V_2 -> V_66 . V_307 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_207 ( int V_403 )
{
switch ( V_403 ) {
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
static inline int F_208 ( struct V_1 * V_2 , int V_404 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_404 >= 576 ) &&
( V_404 <= V_2 -> V_12 . V_402 ) ) ;
case V_18 :
case V_321 :
default:
return 1 ;
}
}
static int F_209 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_185 V_404 , V_403 ;
V_185 V_163 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_170 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_405 ,
F_210 ( V_113 -> V_117 ) ,
V_370 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_403 , F_211 ( V_113 -> V_117 ) , 2 ) ;
V_404 = F_207 ( V_403 ) ;
if ( ! V_404 ) {
V_113 -> V_37 = - V_406 ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
if ( V_2 -> V_12 . V_407 && ( V_2 -> V_12 . V_407 != V_404 ) ) {
if ( V_2 -> V_9 &&
( ( V_2 -> V_9 -> V_404 == V_2 -> V_12 . V_407 ) ||
( V_2 -> V_9 -> V_404 > V_404 ) ) )
V_2 -> V_9 -> V_404 = V_404 ;
F_132 ( V_2 ) ;
}
V_2 -> V_12 . V_407 = V_404 ;
V_2 -> V_12 . V_402 = V_404 ;
V_2 -> V_46 . V_263 = V_404 + 2 * V_408 ;
} else {
V_2 -> V_12 . V_402 = * ( V_185 * ) F_211 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_407 = F_212 ( V_2 -> V_12 . V_402 ,
F_206 ( V_2 ) ) ;
V_2 -> V_46 . V_263 = V_264 ;
}
memcpy ( & V_163 , F_213 ( V_113 -> V_117 ) , 2 ) ;
if ( V_163 >= V_409 ) {
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
char V_410 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_411 , V_412 ) ;
* ( F_216 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_369 ;
if ( V_2 -> V_66 . V_307 )
if ( V_2 -> V_12 . type == V_18 )
V_410 = V_413 ;
else
V_410 = V_414 ;
else
V_410 = V_415 ;
memcpy ( F_217 ( V_113 -> V_117 ) , & V_410 , 1 ) ;
memcpy ( F_218 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_399 , V_370 ) ;
memcpy ( F_219 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_358 , V_370 ) ;
memcpy ( F_220 ( V_113 -> V_117 ) ,
V_2 -> V_12 . V_416 , 9 ) ;
V_37 = F_190 ( V_2 , V_412 , V_113 ,
F_209 , NULL ) ;
return V_37 ;
}
static int F_221 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_173 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_417 ,
F_222 ( V_113 -> V_117 ) ,
V_370 ) ;
if ( ! strncmp ( L_174 , F_222 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_175 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_176
L_177 ) ;
V_113 -> V_37 = - V_418 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 )
{
int V_37 ;
V_185 V_362 ;
struct V_112 * V_113 ;
struct V_363 V_419 ;
F_41 ( V_65 , 2 , L_178 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_420 , V_421 ) ;
memcpy ( F_224 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_399 , V_370 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_359 , V_370 ) ;
memcpy ( F_226 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_405 , V_370 ) ;
F_178 ( F_44 ( V_2 ) , & V_419 ) ;
memcpy ( F_227 ( V_113 -> V_117 ) , & V_419 . V_371 , 2 ) ;
V_362 = ( V_2 -> V_12 . V_348 << 8 ) + V_2 -> V_12 . V_347 ;
memcpy ( F_228 ( V_113 -> V_117 ) , & V_362 , 2 ) ;
V_37 = F_190 ( V_2 , V_421 , V_113 ,
F_221 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_422 ;
V_37 = 0 ;
V_422 = F_229 ( V_101 , V_126 ) ;
if ( ! V_422 ) {
V_37 = - V_50 ;
goto V_73;
}
V_422 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_230 ( & V_422 -> V_234 ) ;
F_231 ( & V_422 -> V_234 . V_154 , & V_423 ) ;
V_422 -> V_60 = V_60 ;
V_422 -> V_102 = NULL ;
V_422 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_422 -> V_3 , V_249 ) ;
V_60 -> V_63 [ V_93 ] = V_422 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_424 = V_422 ;
F_52 ( V_60 -> V_2 , 2 , L_179 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_422 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_422 -> V_95 ) ;
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
if ( F_59 ( & V_2 -> V_46 . V_3 , V_256 ,
V_335 ) != V_256 )
return 0 ;
F_41 ( V_65 , 2 , L_181 ) ;
V_2 -> V_46 . V_425 = F_37 () ;
if ( ! V_2 -> V_46 . V_425 )
goto V_426;
if ( F_26 ( V_2 ) )
goto V_427;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_428;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_233 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_429;
F_45 ( V_65 , 2 , L_182 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_430 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_431;
}
}
if ( F_46 ( V_2 ) )
goto V_429;
return 0 ;
V_431:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_429:
while ( V_44 > 0 ) {
F_232 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_428:
F_28 ( V_2 ) ;
V_427:
F_35 ( V_2 -> V_46 . V_425 ) ;
V_2 -> V_46 . V_425 = NULL ;
V_426:
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
return - V_50 ;
}
static void F_132 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_235 ( & V_2 -> V_46 . V_3 , V_256 ) ==
V_256 )
return;
F_48 ( V_2 ) ;
F_236 ( & V_2 -> V_295 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_425 -> V_63 [ V_45 ] . V_432 )
F_127 ( V_2 -> V_46 . V_425 -> V_63 [ V_45 ] . V_432 ) ;
}
F_35 ( V_2 -> V_46 . V_425 ) ;
V_2 -> V_46 . V_425 = NULL ;
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
char * V_433 )
{
V_433 [ 0 ] = V_349 [ 'P' ] ;
V_433 [ 1 ] = V_349 [ 'C' ] ;
V_433 [ 2 ] = V_349 [ 'I' ] ;
V_433 [ 3 ] = V_349 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_433 [ 4 ] ) ) = F_238 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_433 [ 8 ] ) ) = F_239 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_433 [ 12 ] ) ) = F_240 ( V_2 ) ;
}
static void F_241 ( struct V_1 * V_2 ,
char * V_433 )
{
V_433 [ 16 ] = V_349 [ 'B' ] ;
V_433 [ 17 ] = V_349 [ 'L' ] ;
V_433 [ 18 ] = V_349 [ 'K' ] ;
V_433 [ 19 ] = V_349 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_433 [ 20 ] ) ) = V_2 -> V_12 . V_350 . V_351 ;
* ( ( unsigned int * ) ( & V_433 [ 24 ] ) ) = V_2 -> V_12 . V_350 . V_352 ;
* ( ( unsigned int * ) ( & V_433 [ 28 ] ) ) =
V_2 -> V_12 . V_350 . V_353 ;
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
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_434 , V_435 ) ;
memcpy ( F_245 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_399 , V_370 ) ;
memcpy ( F_246 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_417 , V_370 ) ;
V_37 = F_190 ( V_2 , V_435 , V_113 , NULL , NULL ) ;
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
goto V_436;
}
V_37 = F_202 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_436;
}
V_37 = F_215 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_436;
}
V_37 = F_223 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_436;
}
V_37 = F_234 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_436;
}
V_37 = F_248 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_132 ( V_2 ) ;
goto V_436;
}
V_37 = F_242 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_436;
}
V_37 = F_244 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
goto V_436;
}
return 0 ;
V_436:
F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_249 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
static void F_250 ( struct V_1 * V_2 )
{
char V_437 [ 15 ] ;
int V_44 ;
sprintf ( V_437 , L_191 , V_2 -> V_12 . V_416 + 1 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_437 [ V_44 ] =
( char ) V_438 [ ( T_2 ) V_437 [ V_44 ] ] ;
V_437 [ 8 ] = 0 ;
F_89 ( & V_2 -> V_10 -> V_9 , L_192
L_193 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? V_2 -> V_12 . V_302 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ,
V_437 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_416 [ 0 ] )
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_197
L_198 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? V_2 -> V_12 . V_302 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
else
F_89 ( & V_2 -> V_10 -> V_9 , L_196
L_199 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_194 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? V_2 -> V_12 . V_302 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_195 : L_74 ,
F_12 ( V_2 ) ) ;
}
void F_252 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_302 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_302 , L_200 ,
V_2 -> V_12 . V_302 [ 2 ] ,
V_2 -> V_12 . V_302 [ 3 ] ) ;
V_2 -> V_12 . V_302 [ V_379 ] = 0 ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_302 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_302 [ 0 ] = ( char ) V_438 [ ( T_2 )
V_2 -> V_12 . V_302 [ 0 ] ] ;
V_2 -> V_12 . V_302 [ 1 ] = ( char ) V_438 [ ( T_2 )
V_2 -> V_12 . V_302 [ 1 ] ] ;
V_2 -> V_12 . V_302 [ 2 ] = ( char ) V_438 [ ( T_2 )
V_2 -> V_12 . V_302 [ 2 ] ] ;
V_2 -> V_12 . V_302 [ 3 ] = ( char ) V_438 [ ( T_2 )
V_2 -> V_12 . V_302 [ 3 ] ] ;
V_2 -> V_12 . V_302 [ V_379 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_302 [ 0 ] , 0 , V_379 + 1 ) ;
}
if ( V_2 -> V_12 . V_377 )
F_250 ( V_2 ) ;
else
F_251 ( V_2 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
struct V_39 * V_439 ;
F_4 ( V_2 , 5 , L_201 ) ;
F_254 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_255 ( V_2 , V_439 ) ;
}
}
static inline struct V_39 * F_256 (
struct V_1 * V_2 )
{
struct V_303 * V_440 ;
struct V_39 * V_439 ;
int V_44 , free ;
struct V_441 * V_441 ;
if ( F_257 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_258 (plh, &card->qdio.in_buf_pool.entry_list) {
V_439 = F_259 ( V_440 , struct V_39 , V_42 ) ;
free = 1 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_260 ( F_261 ( V_439 -> V_51 [ V_44 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_92 ( & V_439 -> V_42 ) ;
return V_439 ;
}
}
V_439 = F_259 ( V_2 -> V_46 . V_58 . V_53 . V_442 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_260 ( F_261 ( V_439 -> V_51 [ V_44 ] ) ) > 1 ) {
V_441 = F_262 ( V_126 ) ;
if ( ! V_441 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_439 -> V_51 [ V_44 ] ) ;
V_439 -> V_51 [ V_44 ] = F_263 ( V_441 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_443 . V_444 ++ ;
}
}
}
F_92 ( & V_439 -> V_42 ) ;
return V_439 ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_445 * V_231 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_231 -> V_432 ) ) {
V_231 -> V_432 = F_265 ( V_446 + V_447 ) ;
if ( ! V_231 -> V_432 )
return 1 ;
}
V_40 = F_256 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_231 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_231 -> V_64 -> V_245 [ V_44 ] . V_253 = V_408 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = V_448 ;
else
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_246 = 0 ;
}
return 0 ;
}
int F_266 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_202 ) ;
F_42 ( V_2 -> V_46 . V_425 -> V_61 ,
V_62 ) ;
F_253 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_264 ( V_2 , & V_2 -> V_46 . V_425 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_425 -> V_70 =
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
V_2 -> V_46 . V_80 [ V_44 ] -> V_449 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_450 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_451 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_248 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_452 ) ;
}
return 0 ;
}
static inline T_2 F_267 ( enum V_453 V_19 )
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
enum V_454 V_455 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_456 = V_457 ;
V_130 -> V_133 . V_182 = V_2 -> V_182 . V_388 ;
V_130 -> V_133 . V_458 = F_267 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_459 = ( T_2 ) V_2 -> V_12 . V_369 ;
if ( V_2 -> V_66 . V_307 )
V_130 -> V_133 . V_460 = 2 ;
else
V_130 -> V_133 . V_460 = 1 ;
V_130 -> V_133 . V_461 = 1 ;
V_130 -> V_133 . V_393 = V_455 ;
V_130 -> V_133 . V_462 = 0 ;
V_130 -> V_133 . V_463 = 0 ;
}
struct V_112 * F_269 ( struct V_1 * V_2 ,
enum V_464 V_465 , enum V_454 V_455 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_66 ( & V_2 -> V_155 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
F_268 ( V_2 , V_130 , V_465 , V_455 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_203 ) ;
F_68 ( 1 , L_204 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
}
return V_113 ;
}
void F_270 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_410 )
{
memcpy ( V_113 -> V_117 , V_466 , V_391 ) ;
memcpy ( F_271 ( V_113 -> V_117 ) , & V_410 , 1 ) ;
memcpy ( F_272 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_417 , V_370 ) ;
}
int F_273 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_384 )
{
int V_37 ;
char V_410 ;
F_4 ( V_2 , 4 , L_205 ) ;
if ( V_2 -> V_66 . V_307 )
if ( V_2 -> V_12 . type == V_18 )
V_410 = V_413 ;
else
V_410 = V_414 ;
else
V_410 = V_415 ;
F_270 ( V_2 , V_113 , V_410 ) ;
V_37 = F_190 ( V_2 , V_467 ,
V_113 , F_191 , V_384 ) ;
if ( V_37 == - V_325 ) {
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
V_130 -> V_117 . V_468 . V_133 . V_139 ;
return 0 ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_208 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_468 . V_117 . V_469 . V_470 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_468 . V_117 . V_469 . V_470 ;
F_45 ( V_65 , 2 , L_209 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_471 . V_472 =
V_130 -> V_117 . V_468 . V_117 . V_469 . V_473 ;
return F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_277 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_474 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_269 ( V_2 , V_475 ,
V_394 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_130 -> V_117 . V_468 . V_133 . V_476 = V_474 ;
V_130 -> V_117 . V_468 . V_133 . V_477 = V_134 ;
V_130 -> V_117 . V_468 . V_133 . V_478 = 1 ;
V_130 -> V_117 . V_468 . V_133 . V_479 = 1 ;
}
return V_113 ;
}
int F_278 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_210 ) ;
V_113 = F_277 ( V_2 , V_480 ,
sizeof( struct V_481 ) ) ;
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
case V_482 :
case V_483 :
F_41 ( V_65 , 2 , L_212 ) ;
V_2 -> V_66 . V_484 . V_472 |= V_485 ;
V_2 -> V_66 . V_486 . V_472 |= V_485 ;
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
if ( V_130 -> V_133 . V_393 == V_394 ) {
V_2 -> V_66 . V_484 . V_472 = V_130 -> V_133 . V_462 ;
V_2 -> V_66 . V_484 . V_487 = V_130 -> V_133 . V_463 ;
} else if ( V_130 -> V_133 . V_393 == V_488 ) {
V_2 -> V_66 . V_486 . V_472 = V_130 -> V_133 . V_462 ;
V_2 -> V_66 . V_486 . V_487 = V_130 -> V_133 . V_463 ;
} else
F_68 ( 1 , L_215
L_216 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_280 ( struct V_1 * V_2 , enum V_454 V_455 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_217 , V_455 ) ;
V_113 = F_269 ( V_2 , V_489 , V_455 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_273 ( V_2 , V_113 , F_279 , NULL ) ;
return V_37 ;
}
static int F_281 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_490 * V_491 ;
struct V_492 * V_493 ;
F_4 ( V_2 , 2 , L_218 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_491 = (struct V_490 * ) V_125 -> V_387 ;
if ( V_130 -> V_117 . V_468 . V_133 . V_139 == 0 ) {
V_493 = & V_130 -> V_117 . V_468 . V_117 . V_494 ;
V_491 -> V_495 = V_493 -> V_495 ;
V_491 -> V_496 = V_493 -> V_496 ;
F_52 ( V_2 , 2 , L_219 , V_491 -> V_495 ,
V_491 -> V_496 ) ;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_492 ( struct V_1 * V_2 ,
struct V_490 * V_491 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_220 ) ;
if ( ! F_282 ( V_2 , V_497 ) )
return - V_340 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_498 ;
V_113 = F_277 ( V_2 , V_497 ,
sizeof( struct V_499 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_273 ( V_2 , V_113 ,
F_281 , V_491 ) ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_221 , V_37 ) ;
else
V_2 -> V_12 . V_500 = V_130 -> V_117 . V_501 . V_502 ;
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
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_130 -> V_117 . V_501 . V_503 = 16 ;
V_130 -> V_117 . V_501 . V_504 = V_505 ;
return F_273 ( V_2 , V_113 , F_283 , NULL ) ;
}
static void F_285 ( struct V_1 * V_2 , struct V_506 * V_507 )
{
unsigned long V_12 = F_286 ( V_49 ) ;
struct V_508 * V_509 = (struct V_508 * ) V_12 ;
struct V_510 * V_511 = (struct V_510 * ) V_12 ;
struct V_363 V_512 ;
int V_373 ;
V_507 -> V_142 = V_2 -> V_12 . V_142 ;
F_178 ( F_152 ( V_2 ) , & V_512 ) ;
V_507 -> V_513 = V_512 . V_513 ;
V_507 -> V_371 = V_512 . V_371 ;
if ( ! V_12 )
return;
V_373 = F_287 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_373 >= 2 ) && ( F_287 ( V_509 , 2 , 2 , 2 ) == 0 ) )
V_507 -> V_514 = V_509 -> V_515 ;
if ( ( V_373 >= 3 ) && ( F_287 ( V_511 , 3 , 2 , 2 ) == 0 ) ) {
F_288 ( V_511 -> V_516 [ 0 ] . V_517 , sizeof( V_511 -> V_516 [ 0 ] . V_517 ) ) ;
memcpy ( V_507 -> V_518 , V_511 -> V_516 [ 0 ] . V_517 , sizeof( V_507 -> V_518 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_289 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_223 , V_37 ) ;
return 0 ;
}
int F_290 ( struct V_1 * V_2 , enum V_519 V_520 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_224 ) ;
V_113 = F_269 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_130 -> V_117 . V_501 . V_503 = 80 ;
V_130 -> V_117 . V_501 . V_504 = V_521 ;
V_130 -> V_117 . V_501 . type = 1 ;
V_130 -> V_117 . V_501 . V_520 = V_520 ;
switch ( V_520 ) {
case V_522 :
V_130 -> V_117 . V_501 . V_66 = 0x0003 ;
V_130 -> V_117 . V_501 . V_502 = 0x00010000 +
sizeof( struct V_506 ) ;
F_285 ( V_2 ,
(struct V_506 * ) V_130 -> V_117 . V_501 . V_523 ) ;
break;
case V_524 :
V_130 -> V_117 . V_501 . V_66 = 0x0001 ;
break;
case V_525 :
break;
}
return F_273 ( V_2 , V_113 , F_289 , NULL ) ;
}
int F_291 ( struct V_1 * V_2 , struct V_526 * V_231 ,
unsigned int V_527 , const char * V_528 )
{
if ( V_527 ) {
F_4 ( V_2 , 2 , V_528 ) ;
F_52 ( V_2 , 2 , L_225 ,
V_231 -> V_245 [ 15 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_226 ,
V_231 -> V_245 [ 14 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_227 , V_527 ) ;
if ( ( V_231 -> V_245 [ 15 ] . V_246 ) == 0x12 ) {
V_2 -> V_529 . V_530 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static void V_296 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 , struct V_1 ,
V_295 . V_7 ) ;
F_52 ( V_2 , 2 , L_228 , V_2 -> V_531 ) ;
F_292 ( V_2 , V_2 -> V_531 ) ;
}
void F_292 ( struct V_1 * V_2 , int V_169 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_425 ;
struct V_303 * V_532 ;
int V_167 ;
int V_44 ;
int V_37 ;
int V_533 = 0 ;
V_167 = ( V_169 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_169 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_169 ) ;
if ( V_167 >= F_293 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_167 ; ++ V_44 ) {
if ( F_264 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_533 ++ ;
}
}
if ( V_533 < V_167 ) {
F_60 ( & V_2 -> V_534 , 3 ) ;
V_167 = V_533 ;
} else {
F_294 ( & V_2 -> V_534 , - 1 , 0 ) ;
}
if ( ! V_167 ) {
V_44 = 0 ;
F_258 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_229 ) ;
V_2 -> V_531 = V_169 ;
F_295 (
& V_2 -> V_295 ,
V_535 ) ;
}
return;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_443 . V_536 ++ ;
V_2 -> V_443 . V_537 =
F_296 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_167 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_443 . V_538 +=
F_296 () -
V_2 -> V_443 . V_537 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_230 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_167 ) %
V_62 ;
}
}
static int F_297 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_539 )
{
int V_83 = V_64 -> V_64 -> V_245 [ 15 ] . V_246 ;
F_4 ( V_2 , 6 , L_231 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_539 = 0 ;
} else {
V_539 = 1 ;
}
}
F_291 ( V_2 , V_64 -> V_64 , V_539 , L_232 ) ;
if ( ! V_539 )
return V_540 ;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return V_541 ;
F_4 ( V_2 , 1 , L_233 ) ;
F_52 ( V_2 , 1 , L_234 ,
( V_186 ) V_539 , ( V_279 ) V_83 ) ;
return V_542 ;
}
static void F_298 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_450 ) {
if ( F_51 ( & V_111 -> V_451 )
>= V_543 ) {
F_4 ( V_111 -> V_2 , 6 , L_235 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_443 . V_544 ++ ;
V_111 -> V_450 = 1 ;
}
}
}
static int F_299 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
int V_545 = 0 ;
if ( V_111 -> V_450 ) {
if ( F_51 ( & V_111 -> V_451 )
<= V_546 ) {
F_4 ( V_111 -> V_2 , 6 , L_236 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_443 . V_547 ++ ;
V_111 -> V_450 = 0 ;
V_64 = V_111 -> V_63 [ V_111 -> V_449 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) ==
V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 ,
V_107 ) ;
V_545 ++ ;
V_111 -> V_449 =
( V_111 -> V_449 + 1 ) %
V_62 ;
}
}
}
return V_545 ;
}
static int F_300 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_449 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_449 =
( V_111 -> V_449 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_301 ( struct V_92 * V_111 , int V_169 ,
int V_167 )
{
struct V_96 * V_231 ;
int V_37 ;
int V_44 ;
unsigned int V_548 ;
for ( V_44 = V_169 ; V_44 < V_169 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_231 = V_111 -> V_63 [ V_93 ] ;
V_231 -> V_64 -> V_245 [ V_231 -> V_255 - 1 ] . V_254 |=
V_448 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_424 = V_231 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_450 ) {
if ( ( F_51 ( & V_111 -> V_451 ) >=
( V_543 -
V_549 ) ) &&
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
V_111 -> V_2 -> V_9 -> V_550 = V_390 ;
if ( V_111 -> V_2 -> V_66 . V_273 ) {
V_111 -> V_2 -> V_443 . V_551 ++ ;
V_111 -> V_2 -> V_443 . V_552 =
F_296 () ;
}
V_548 = V_553 ;
if ( F_51 ( & V_111 -> V_248 ) )
V_548 |= V_554 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_548 ,
V_111 -> V_430 , V_169 , V_167 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_443 . V_555 +=
F_296 () -
V_111 -> V_2 -> V_443 . V_552 ;
F_302 ( V_167 , & V_111 -> V_451 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_529 . V_556 += V_167 ;
if ( V_37 == - V_557 )
return;
F_4 ( V_111 -> V_2 , 2 , L_237 ) ;
F_52 ( V_111 -> V_2 , 2 , L_238 , V_111 -> V_430 ) ;
F_52 ( V_111 -> V_2 , 2 , L_239 , V_169 ) ;
F_52 ( V_111 -> V_2 , 2 , L_240 , V_167 ) ;
F_52 ( V_111 -> V_2 , 2 , L_165 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_443 . V_558 += V_167 ;
}
static void F_303 ( struct V_92 * V_111 )
{
int V_169 ;
int V_559 = 0 ;
int V_560 = 0 ;
if ( ( F_51 ( & V_111 -> V_451 ) <= V_546 ) ||
! F_51 ( & V_111 -> V_248 ) ) {
if ( F_235 ( & V_111 -> V_3 , V_561 ) ==
V_452 ) {
F_304 ( V_111 -> V_2 -> V_9 ) ;
V_169 = V_111 -> V_449 ;
V_560 = V_111 -> V_450 ;
F_305 () ;
V_559 += F_299 ( V_111 ) ;
if ( ! V_559 &&
! F_51 ( & V_111 -> V_248 ) )
V_559 +=
F_300 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 &&
V_560 )
V_111 -> V_2 -> V_443 . V_562 +=
V_559 ;
if ( V_559 )
F_301 ( V_111 , V_169 , V_559 ) ;
F_60 ( & V_111 -> V_3 , V_452 ) ;
}
}
}
void F_306 ( struct V_158 * V_119 , int V_111 ,
unsigned long V_563 )
{
struct V_1 * V_2 = (struct V_1 * ) V_563 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_564 ) )
F_307 ( & V_2 -> V_565 ) ;
}
int F_308 ( struct V_1 * V_2 , enum V_566 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_567 ) {
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
unsigned int V_539 ,
unsigned int V_111 , int V_568 , int V_167 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_241 , V_568 ) ;
F_52 ( V_2 , 5 , L_242 , V_167 ) ;
F_52 ( V_2 , 5 , L_243 , V_539 ) ;
if ( V_539 ) {
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_443 . V_569 ++ ;
V_2 -> V_443 . V_570 = F_296 () ;
}
for ( V_44 = V_568 ; V_44 < V_568 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_526 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_571 ;
V_571 = 0 ;
while ( V_64 -> V_245 [ V_571 ] . V_250 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_245 [ V_571 ] . V_250 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_245 [ V_571 ] . V_250 = NULL ;
V_64 -> V_245 [ V_571 ] . V_254 = 0 ;
V_64 -> V_245 [ V_571 ] . V_246 = 0 ;
V_64 -> V_245 [ V_571 ] . V_253 = 0 ;
++ V_571 ;
}
V_64 -> V_245 [ 15 ] . V_254 = 0 ;
V_64 -> V_245 [ 15 ] . V_246 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_167 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_244 , V_37 ) ;
F_4 ( V_2 , 2 , L_245 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_167 ) % V_62 ;
F_310 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_273 ) {
int V_572 = F_296 () ;
V_572 -= V_2 -> V_443 . V_570 ;
V_2 -> V_443 . V_573 += V_572 ;
}
V_73:
return;
}
void F_311 ( struct V_158 * V_119 , unsigned int V_539 ,
unsigned int V_111 , int V_574 , int V_167 ,
unsigned long V_563 )
{
struct V_1 * V_2 = (struct V_1 * ) V_563 ;
F_52 ( V_2 , 2 , L_246 , V_111 ) ;
F_52 ( V_2 , 2 , L_247 , V_539 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_309 ( V_2 , V_539 , V_111 , V_574 , V_167 ) ;
else if ( V_539 )
F_72 ( V_2 ) ;
}
void F_312 ( struct V_158 * V_119 ,
unsigned int V_527 , int V_575 , int V_568 ,
int V_167 , unsigned long V_563 )
{
struct V_1 * V_2 = (struct V_1 * ) V_563 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_575 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_248 ) ;
if ( V_527 & V_576 ) {
F_4 ( V_2 , 2 , L_249 ) ;
F_304 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_443 . V_577 ++ ;
V_2 -> V_443 . V_578 =
F_296 () ;
}
for ( V_44 = V_568 ; V_44 < ( V_568 + V_167 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_297 ( V_2 , V_64 , V_527 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_579 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_580 ) ;
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
V_64 -> V_64 -> V_245 [ 15 ] . V_246 , 0 ) ;
F_61 ( V_111 , V_64 , V_85 ) ;
}
F_62 ( V_111 , V_64 ,
V_249 ) ;
}
F_50 ( V_111 , V_93 , 0 ) ;
}
F_314 ( V_167 , & V_111 -> V_451 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_303 ( V_111 ) ;
F_310 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_443 . V_581 += F_296 () -
V_2 -> V_443 . V_578 ;
}
int F_315 ( struct V_1 * V_2 , struct V_232 * V_233 ,
int V_582 , int V_583 )
{
T_3 * V_584 ;
V_279 V_585 ;
if ( V_583 && V_2 -> V_12 . V_319 )
return V_2 -> V_12 . V_319 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_309 ) {
case V_586 :
case V_587 :
switch ( V_582 ) {
case 4 :
V_585 = F_316 ( F_317 ( V_233 ) ) ;
break;
case 6 :
V_585 = F_318 ( F_319 ( V_233 ) ) ;
break;
default:
return V_2 -> V_46 . V_257 ;
}
if ( V_2 -> V_46 . V_309 == V_587 )
return ~ V_585 >> 6 & 3 ;
if ( V_585 & V_588 )
return 3 ;
if ( V_585 & V_589 )
return 2 ;
if ( V_585 & V_590 )
return 1 ;
if ( V_585 & V_591 )
return 0 ;
break;
case V_592 :
if ( V_233 -> V_593 > 5 )
return 0 ;
return ~ V_233 -> V_593 >> 1 & 3 ;
case V_594 :
V_584 = & ( (struct V_595 * ) V_233 -> V_117 ) -> V_596 ;
if ( * V_584 == V_597 )
return ~ * ( V_584 + 1 ) >> ( V_598 + 1 ) & 3 ;
break;
default:
break;
}
return V_2 -> V_46 . V_257 ;
}
int F_320 ( struct V_232 * V_233 )
{
int V_177 , V_253 , V_571 , V_51 = 0 ;
struct V_599 * V_600 ;
char * V_117 ;
for ( V_177 = 0 ; V_177 < F_321 ( V_233 ) -> V_601 ; V_177 ++ ) {
V_600 = & F_321 ( V_233 ) -> V_602 [ V_177 ] ;
V_117 = ( char * ) F_322 ( F_323 ( V_600 ) ) +
V_600 -> V_603 ;
V_253 = V_600 -> V_604 ;
V_571 = F_324 ( ( unsigned long ) V_117 + V_253 - 1 ) -
F_325 ( ( unsigned long ) V_117 ) ;
V_51 += V_571 ;
}
return V_51 ;
}
int F_326 ( struct V_1 * V_2 ,
struct V_232 * V_233 , int V_605 )
{
int V_606 = V_233 -> V_163 - V_233 -> V_607 ;
int V_608 = F_324 ( ( unsigned long ) V_233 -> V_117 + V_606 - 1 ) -
F_325 ( ( unsigned long ) V_233 -> V_117 ) ;
V_608 += F_320 ( V_233 ) ;
if ( ( V_608 + V_605 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_253
L_254 ,
( V_608 + V_605 ) , V_233 -> V_163 ) ;
return 0 ;
}
return V_608 ;
}
int F_327 ( struct V_232 * V_233 , struct V_609 * * V_133 , int V_163 )
{
int V_610 , V_611 , V_612 ;
if ( ( ( unsigned long ) V_233 -> V_117 & V_613 ) !=
( ( ( unsigned long ) V_233 -> V_117 + V_163 - 1 ) & V_613 ) ) {
V_610 = F_328 ( V_233 ) ;
V_611 = V_408 - ( ( unsigned long ) V_233 -> V_117 % V_408 ) ;
V_612 = V_163 - V_611 ;
if ( V_612 > V_610 )
return 1 ;
memmove ( V_233 -> V_117 - V_612 , V_233 -> V_117 , V_233 -> V_163 - V_233 -> V_607 ) ;
V_233 -> V_117 -= V_612 ;
V_233 -> V_614 -= V_612 ;
* V_133 = (struct V_609 * ) V_233 -> V_117 ;
F_68 ( 2 , L_255 , V_163 , V_612 ) ;
}
return 0 ;
}
static inline void F_329 ( struct V_232 * V_233 ,
struct V_526 * V_64 , int V_615 , int * V_255 ,
int V_184 )
{
int V_253 = V_233 -> V_163 - V_233 -> V_607 ;
int V_616 ;
int V_245 ;
char * V_117 ;
int V_617 , V_177 ;
struct V_599 * V_600 ;
V_245 = * V_255 ;
V_117 = V_233 -> V_117 ;
V_617 = ( V_615 == 0 ? 1 : 0 ) ;
if ( V_184 >= 0 ) {
V_117 = V_233 -> V_117 + V_184 ;
V_253 -= V_184 ;
V_617 = 0 ;
}
while ( V_253 > 0 ) {
V_616 = V_408 - ( ( unsigned long ) V_117 % V_408 ) ;
if ( V_253 < V_616 )
V_616 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_616 ;
V_253 -= V_616 ;
if ( ! V_253 ) {
if ( V_617 )
if ( F_321 ( V_233 ) -> V_601 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_618 ;
else
V_64 -> V_245 [ V_245 ] . V_254 = 0 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_619 ;
} else {
if ( V_617 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_618 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_619 ;
}
V_117 += V_616 ;
V_245 ++ ;
V_617 = 0 ;
}
for ( V_177 = 0 ; V_177 < F_321 ( V_233 ) -> V_601 ; V_177 ++ ) {
V_600 = & F_321 ( V_233 ) -> V_602 [ V_177 ] ;
V_117 = ( char * ) F_322 ( F_323 ( V_600 ) ) +
V_600 -> V_603 ;
V_253 = V_600 -> V_604 ;
while ( V_253 > 0 ) {
V_616 = V_408 -
( ( unsigned long ) V_117 % V_408 ) ;
if ( V_253 < V_616 )
V_616 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_616 ;
V_64 -> V_245 [ V_245 ] . V_254 =
V_619 ;
V_253 -= V_616 ;
V_117 += V_616 ;
V_245 ++ ;
}
}
if ( V_64 -> V_245 [ V_245 - 1 ] . V_254 )
V_64 -> V_245 [ V_245 - 1 ] . V_254 = V_620 ;
* V_255 = V_245 ;
}
static inline int F_330 ( struct V_92 * V_111 ,
struct V_96 * V_231 , struct V_232 * V_233 ,
struct V_609 * V_133 , int V_184 , int V_621 )
{
struct V_526 * V_64 ;
int V_559 = 0 , V_622 , V_623 = 0 ;
V_64 = V_231 -> V_64 ;
F_76 ( & V_233 -> V_242 ) ;
F_331 ( & V_231 -> V_234 , V_233 ) ;
if ( V_133 -> V_133 . V_624 . V_314 == V_625 ) {
int V_245 = V_231 -> V_255 ;
V_622 = sizeof( struct V_626 ) +
( (struct V_626 * ) V_133 ) -> V_502 . V_627 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_233 -> V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_622 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_618 ;
V_231 -> V_255 ++ ;
V_233 -> V_117 += V_622 ;
V_233 -> V_163 -= V_622 ;
V_623 = 1 ;
}
if ( V_184 >= 0 ) {
int V_245 = V_231 -> V_255 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_133 ;
V_64 -> V_245 [ V_245 ] . V_253 = sizeof( struct V_609 ) +
V_621 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_618 ;
V_231 -> V_251 [ V_245 ] = 1 ;
V_231 -> V_255 ++ ;
}
F_329 ( V_233 , V_64 , V_623 ,
( int * ) & V_231 -> V_255 , V_184 ) ;
if ( ! V_111 -> V_450 ) {
F_4 ( V_111 -> V_2 , 6 , L_256 ) ;
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_559 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_257 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_443 . V_628 ++ ;
if ( V_231 -> V_255 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_559 = 1 ;
}
}
return V_559 ;
}
int F_332 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_232 * V_233 ,
struct V_609 * V_133 , int V_608 ,
int V_184 , int V_621 )
{
struct V_96 * V_64 ;
int V_169 ;
while ( F_59 ( & V_111 -> V_3 , V_452 ,
V_629 ) != V_452 ) ;
V_169 = V_111 -> V_449 ;
V_64 = V_111 -> V_63 [ V_111 -> V_449 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 )
goto V_73;
V_111 -> V_449 = ( V_111 -> V_449 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_452 ) ;
F_330 ( V_111 , V_64 , V_233 , V_133 , V_184 , V_621 ) ;
F_301 ( V_111 , V_169 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_452 ) ;
return - V_630 ;
}
int F_333 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_232 * V_233 , struct V_609 * V_133 ,
int V_608 )
{
struct V_96 * V_64 ;
int V_631 ;
int V_545 = 0 ;
int V_450 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_452 ,
V_629 ) != V_452 ) ;
V_631 = V_111 -> V_449 ;
V_64 = V_111 -> V_63 [ V_111 -> V_449 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 ) {
F_60 ( & V_111 -> V_3 , V_452 ) ;
return - V_630 ;
}
F_298 ( V_111 ) ;
if ( V_111 -> V_450 ) {
V_450 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_255 ) < V_608 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_545 ++ ;
V_111 -> V_449 =
( V_111 -> V_449 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_449 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_249 ) {
F_301 ( V_111 , V_631 ,
V_545 ) ;
F_60 ( & V_111 -> V_3 ,
V_452 ) ;
return - V_630 ;
}
}
}
V_41 = F_330 ( V_111 , V_64 , V_233 , V_133 , - 1 , 0 ) ;
V_111 -> V_449 = ( V_111 -> V_449 + V_41 ) %
V_62 ;
V_545 += V_41 ;
if ( V_545 )
F_301 ( V_111 , V_631 , V_545 ) ;
else if ( ! F_51 ( & V_111 -> V_248 ) )
F_235 ( & V_111 -> V_3 , V_561 ) ;
while ( F_334 ( & V_111 -> V_3 ) ) {
V_545 = 0 ;
V_631 = V_111 -> V_449 ;
V_545 += F_299 ( V_111 ) ;
if ( ! V_545 && ! F_51 ( & V_111 -> V_248 ) )
V_545 += F_300 ( V_111 ) ;
if ( V_545 )
F_301 ( V_111 , V_631 , V_545 ) ;
}
if ( V_111 -> V_2 -> V_66 . V_273 && V_450 )
V_111 -> V_2 -> V_443 . V_562 += V_545 ;
return V_37 ;
}
static int F_335 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_481 * V_632 ;
F_4 ( V_2 , 4 , L_258 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_632 = & ( V_130 -> V_117 . V_468 ) ;
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_259 , V_130 -> V_133 . V_139 ) ;
V_632 -> V_117 . V_633 = V_634 ;
}
V_2 -> V_12 . V_635 = V_632 -> V_117 . V_633 ;
return 0 ;
}
void F_336 ( struct V_1 * V_2 )
{
enum V_636 V_633 ;
struct V_637 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_260 ) ;
if ( ( ( V_9 -> V_32 & V_638 ) &&
( V_2 -> V_12 . V_635 == V_639 ) ) ||
( ! ( V_9 -> V_32 & V_638 ) &&
( V_2 -> V_12 . V_635 == V_634 ) ) )
return;
V_633 = V_634 ;
if ( V_9 -> V_32 & V_638 )
V_633 = V_639 ;
F_52 ( V_2 , 4 , L_261 , V_633 ) ;
V_113 = F_277 ( V_2 , V_640 ,
sizeof( struct V_499 ) + 8 ) ;
if ( ! V_113 )
return;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_130 -> V_117 . V_468 . V_117 . V_633 = V_633 ;
F_273 ( V_2 , V_113 , F_335 , NULL ) ;
}
int F_337 ( struct V_637 * V_9 , int V_641 )
{
struct V_1 * V_2 ;
char V_437 [ 15 ] ;
V_2 = V_9 -> V_642 ;
F_4 ( V_2 , 4 , L_262 ) ;
sprintf ( V_437 , L_263 , V_641 ) ;
F_4 ( V_2 , 4 , V_437 ) ;
if ( V_641 < 64 )
return - V_406 ;
if ( V_641 > 65535 )
return - V_406 ;
if ( ( ! F_338 ( V_2 , V_643 ) ) &&
( ! F_208 ( V_2 , V_641 ) ) )
return - V_406 ;
V_9 -> V_404 = V_641 ;
return 0 ;
}
struct V_644 * F_339 ( struct V_637 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_642 ;
F_4 ( V_2 , 5 , L_264 ) ;
return & V_2 -> V_529 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_265 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_307 ||
! ( V_2 -> V_12 . V_645 & V_646 ) ) {
memcpy ( V_2 -> V_9 -> V_647 ,
& V_130 -> V_117 . V_468 . V_117 . V_648 . V_250 ,
V_649 ) ;
V_2 -> V_12 . V_645 |= V_646 ;
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
V_113 = F_277 ( V_2 , V_650 ,
sizeof( struct V_499 ) +
sizeof( struct V_651 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_130 -> V_117 . V_468 . V_117 . V_648 . V_130 = V_652 ;
V_130 -> V_117 . V_468 . V_117 . V_648 . V_653 = V_649 ;
memcpy ( & V_130 -> V_117 . V_468 . V_117 . V_648 . V_250 ,
V_2 -> V_9 -> V_647 , V_649 ) ;
V_37 = F_273 ( V_2 , V_113 , F_340 ,
NULL ) ;
return V_37 ;
}
static int F_342 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_654 * V_655 ;
int V_656 = * ( int * ) V_125 -> V_387 ;
F_4 ( V_2 , 4 , L_267 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_655 = & V_130 -> V_117 . V_468 . V_117 . V_657 ;
F_45 ( V_65 , 2 , L_267 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_658 . V_517 ) ;
F_45 ( V_65 , 2 , L_268 ,
V_130 -> V_117 . V_468 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_468 . V_133 . V_139 !=
V_659 )
F_68 ( 3 , L_269 ,
V_2 -> V_10 -> V_9 . V_658 . V_517 ,
V_655 -> V_660 ,
V_130 -> V_117 . V_468 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_468 . V_133 . V_139 ) {
case V_659 :
if ( V_2 -> V_66 . V_276 == V_277 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_270 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_271 ) ;
}
break;
case V_661 :
F_68 ( 2 , L_272
L_273 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_663 :
F_68 ( 2 , L_274
L_275 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_664 :
F_47 ( & V_2 -> V_10 -> V_9 , L_276
L_277 ) ;
break;
case V_665 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_278
L_279 ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_666 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_280 ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_667 :
F_47 ( & V_2 -> V_10 -> V_9 , L_281
L_282 ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_668 :
F_47 ( & V_2 -> V_10 -> V_9 , L_283
L_284 ) ;
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
case V_669 :
F_67 ( & V_2 -> V_10 -> V_9 , L_285
L_286 ) ;
break;
default:
if ( V_656 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_662 ;
break;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_343 ( struct V_1 * V_2 ,
enum V_670 V_276 , int V_656 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_654 * V_655 ;
F_4 ( V_2 , 4 , L_287 ) ;
F_45 ( V_65 , 2 , L_287 ) ;
F_45 ( V_65 , 2 , L_191 , V_2 -> V_10 -> V_9 . V_658 . V_517 ) ;
V_113 = F_277 ( V_2 , V_671 ,
sizeof( struct V_499 ) +
sizeof( struct V_654 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_655 = & V_130 -> V_117 . V_468 . V_117 . V_657 ;
V_655 -> V_660 = V_276 ;
V_37 = F_273 ( V_2 , V_113 , F_342 ,
& V_656 ) ;
F_45 ( V_65 , 2 , L_268 , V_37 ) ;
return V_37 ;
}
int F_344 ( struct V_1 * V_2 , int V_656 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_288 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_282 ( V_2 , V_671 ) ) {
V_37 = F_343 ( V_2 ,
V_2 -> V_66 . V_276 , V_656 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_289 ,
V_2 -> V_10 -> V_9 . V_658 . V_517 ,
V_37 ) ;
V_37 = - V_340 ;
}
} else if ( V_2 -> V_66 . V_276 != V_277 ) {
V_2 -> V_66 . V_276 = V_277 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_276
L_277 ) ;
V_37 = - V_340 ;
}
return V_37 ;
}
void F_345 ( struct V_637 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_642 ;
F_4 ( V_2 , 4 , L_290 ) ;
V_2 -> V_529 . V_556 ++ ;
F_72 ( V_2 ) ;
}
int F_346 ( struct V_637 * V_9 , int V_672 , int V_673 )
{
struct V_1 * V_2 = V_9 -> V_642 ;
int V_37 = 0 ;
switch ( V_673 ) {
case V_674 :
V_37 = V_675 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_676 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_677 ;
break;
case V_678 :
V_37 = V_679 | V_680 | V_681 |
V_682 | V_683 | V_684 | V_685 |
V_686 ;
break;
case V_687 :
V_37 = ( V_9 -> V_647 [ 0 ] << 16 ) | ( V_9 -> V_647 [ 1 ] << 8 ) |
V_9 -> V_647 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_688 :
V_37 = ( V_9 -> V_647 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_689 :
V_37 = V_690 ;
break;
case V_691 :
V_37 = V_692 | V_693 | V_694 | V_695 |
V_696 | V_697 ;
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
V_37 = V_2 -> V_529 . V_703 ;
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
case V_710 :
break;
default:
break;
}
return V_37 ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_163 ,
int (* F_191)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_384 )
{
V_186 V_711 , V_712 ;
F_4 ( V_2 , 4 , L_291 ) ;
memcpy ( V_113 -> V_117 , V_466 , V_391 ) ;
memcpy ( F_272 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_417 , V_370 ) ;
V_711 = ( V_713 ) V_391 + V_163 ;
V_712 = ( V_713 ) V_163 ;
memcpy ( F_348 ( V_113 -> V_117 ) , & V_711 , 2 ) ;
memcpy ( F_349 ( V_113 -> V_117 ) , & V_712 , 2 ) ;
memcpy ( F_350 ( V_113 -> V_117 ) , & V_712 , 2 ) ;
memcpy ( F_351 ( V_113 -> V_117 ) , & V_712 , 2 ) ;
return F_190 ( V_2 , V_391 + V_163 , V_113 ,
F_191 , V_384 ) ;
}
static int F_352 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_714 )
{
struct V_129 * V_130 ;
struct V_715 * V_716 ;
struct V_717 * V_718 ;
unsigned char * V_117 ;
V_185 V_607 ;
F_4 ( V_2 , 3 , L_292 ) ;
V_130 = (struct V_129 * ) V_714 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_184 ) ;
V_716 = (struct V_715 * ) V_125 -> V_387 ;
V_718 = & V_130 -> V_117 . V_468 . V_117 . V_718 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_293 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_468 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_468 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_294 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_607 = * ( ( V_185 * ) F_349 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_468 . V_133 . V_479 == 1 )
V_607 -= ( V_185 ) ( ( char * ) & V_718 -> V_117 - ( char * ) V_130 ) ;
else
V_607 -= ( V_185 ) ( ( char * ) & V_718 -> V_719 - ( char * ) V_130 ) ;
if ( ( V_716 -> V_720 - V_716 -> V_721 ) < V_607 ) {
F_52 ( V_2 , 4 , L_295 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_722 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_296 ,
V_130 -> V_117 . V_468 . V_133 . V_478 ) ;
F_52 ( V_2 , 4 , L_297 ,
V_130 -> V_117 . V_468 . V_133 . V_479 ) ;
if ( V_130 -> V_117 . V_468 . V_133 . V_479 == 1 ) {
memcpy ( V_716 -> V_723 + V_716 -> V_721 ,
( char * ) V_718 ,
V_607 + F_353 ( struct V_717 , V_117 ) ) ;
V_716 -> V_721 += F_353 ( struct V_717 , V_117 ) ;
} else {
memcpy ( V_716 -> V_723 + V_716 -> V_721 ,
( char * ) & V_718 -> V_719 , V_607 ) ;
}
V_716 -> V_721 += V_607 ;
F_52 ( V_2 , 4 , L_298 ,
V_130 -> V_117 . V_468 . V_133 . V_478 ) ;
F_52 ( V_2 , 4 , L_299 ,
V_130 -> V_117 . V_468 . V_133 . V_479 ) ;
if ( V_130 -> V_117 . V_468 . V_133 . V_479 <
V_130 -> V_117 . V_468 . V_133 . V_478 )
return 1 ;
return 0 ;
}
int F_354 ( struct V_1 * V_2 , char T_4 * V_723 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_724 * V_725 ;
unsigned int V_726 ;
struct V_715 V_716 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_300 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_340 ;
if ( ( ! F_282 ( V_2 , V_727 ) ) &&
( ! V_2 -> V_66 . V_307 ) ) {
return - V_340 ;
}
if ( F_355 ( & V_726 , V_723 + sizeof( int ) , sizeof( int ) ) )
return - V_728 ;
if ( V_726 > ( V_118 - V_391 -
sizeof( struct V_729 ) -
sizeof( struct V_499 ) ) )
return - V_406 ;
V_725 = F_356 ( V_723 , V_726 + sizeof( struct V_730 ) ) ;
if ( F_116 ( V_725 ) ) {
F_4 ( V_2 , 2 , L_301 ) ;
return F_117 ( V_725 ) ;
}
V_716 . V_720 = V_725 -> V_133 . V_607 ;
V_716 . V_723 = F_27 ( V_716 . V_720 , V_49 ) ;
if ( ! V_716 . V_723 ) {
F_32 ( V_725 ) ;
return - V_50 ;
}
V_716 . V_721 = sizeof( struct V_730 ) ;
V_113 = F_277 ( V_2 , V_727 ,
V_731 + V_726 ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_73;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
memcpy ( & V_130 -> V_117 . V_468 . V_117 . V_718 , & V_725 -> V_130 , V_726 ) ;
V_37 = F_347 ( V_2 , V_113 , V_732 + V_726 ,
F_352 , ( void * ) & V_716 ) ;
if ( V_37 )
F_68 ( 2 , L_302 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_357 ( V_723 , V_716 . V_723 , V_716 . V_720 ) )
V_37 = - V_728 ;
}
V_73:
F_32 ( V_725 ) ;
F_32 ( V_716 . V_723 ) ;
return V_37 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_733 * V_734 ;
char * V_735 ;
int V_736 ;
F_4 ( V_2 , 3 , L_303 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_734 = (struct V_733 * ) V_125 -> V_387 ;
V_736 = V_130 -> V_117 . V_468 . V_133 . V_476 ;
V_735 = ( char * ) V_117 + 28 ;
if ( V_736 > ( V_734 -> V_737 - V_734 -> V_738 ) ) {
V_130 -> V_133 . V_139 = V_739 ;
return 0 ;
}
memcpy ( ( V_734 -> V_64 + V_734 -> V_738 ) , V_735 ,
V_736 ) ;
V_734 -> V_738 += V_736 ;
if ( V_130 -> V_117 . V_468 . V_133 . V_479 <
V_130 -> V_117 . V_468 . V_133 . V_478 )
return 1 ;
return 0 ;
}
int F_359 ( struct V_1 * V_2 , char T_4 * V_723 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_740 * V_741 ;
struct V_742 V_743 ;
struct V_733 V_734 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_304 ) ;
if ( ! F_282 ( V_2 , V_744 ) ) {
V_37 = - V_340 ;
goto V_73;
}
if ( F_355 ( & V_743 , V_723 ,
sizeof( struct V_742 ) ) ) {
V_37 = - V_728 ;
goto V_73;
}
V_734 . V_737 = V_743 . V_737 ;
V_734 . V_738 = 0 ;
V_734 . V_64 = F_27 ( V_743 . V_737 , V_49 ) ;
if ( ! V_734 . V_64 ) {
V_37 = - V_50 ;
goto V_73;
}
V_113 = F_277 ( V_2 , V_744 ,
sizeof( struct V_499 ) +
sizeof( struct V_740 ) ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_745;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_391 ) ;
V_741 = & V_130 -> V_117 . V_468 . V_117 . V_746 ;
V_741 -> V_660 = V_743 . V_134 ;
V_37 = F_273 ( V_2 , V_113 , F_358 ,
& V_734 ) ;
if ( ! V_37 ) {
if ( F_360 () )
V_41 = F_361 ( V_743 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_743 . V_43 ;
if ( F_357 ( V_41 , V_734 . V_64 ,
V_734 . V_738 ) ) {
V_37 = - V_728 ;
goto V_745;
}
V_743 . V_738 = V_734 . V_738 ;
if ( F_357 ( V_723 , & V_743 ,
sizeof( struct V_742 ) ) )
V_37 = - V_728 ;
} else
if ( V_37 == V_739 )
V_37 = - V_728 ;
V_745:
F_32 ( V_734 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_747 * V_748 ;
struct V_749 * V_749 ;
F_4 ( V_2 , 2 , L_305 ) ;
V_749 = (struct V_749 * ) V_125 -> V_387 ;
V_130 = (struct V_129 * ) V_117 ;
V_748 = & V_130 -> V_117 . V_468 . V_117 . V_748 ;
if ( V_130 -> V_117 . V_468 . V_133 . V_139 == 0 ) {
V_749 -> V_750 = V_748 -> V_750 ;
V_749 -> V_751 = V_748 -> V_751 ;
V_749 -> V_752 = V_748 -> V_752 ;
}
F_275 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int V_747 ( struct V_1 * V_2 ,
struct V_749 * V_749 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_306 ) ;
if ( ! F_282 ( V_2 , V_753 ) )
return - V_340 ;
V_113 = F_277 ( V_2 , V_753 ,
sizeof( struct V_499 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_273 ( V_2 , V_113 , F_362 ,
( void * ) V_749 ) ;
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
int V_253 ;
char * V_346 ;
struct V_158 * V_754 ;
int V_755 = 0 ;
F_41 ( V_65 , 2 , L_307 ) ;
V_754 = F_44 ( V_2 ) ;
if ( ! V_754 -> V_756 ) {
V_755 = 1 ;
V_37 = F_365 ( V_754 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_73;
}
}
V_37 = F_164 ( V_2 , ( void * * ) & V_346 , & V_253 ) ;
if ( V_37 ) {
F_68 ( 2 , L_308 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_757;
}
F_167 ( V_2 , V_346 ) ;
if ( V_755 )
F_168 ( V_2 , V_346 ) ;
F_32 ( V_346 ) ;
V_37 = F_366 ( V_754 , & V_2 -> V_758 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_45 ( V_65 , 2 , L_309 , V_2 -> V_758 . V_759 ) ;
F_45 ( V_65 , 2 , L_310 , V_2 -> V_758 . V_760 ) ;
F_45 ( V_65 , 2 , L_310 , V_2 -> V_758 . V_761 ) ;
F_45 ( V_65 , 2 , L_311 , V_2 -> V_758 . V_762 ) ;
if ( ! ( ( V_2 -> V_758 . V_759 != V_763 ) ||
( ( V_2 -> V_758 . V_760 & V_764 ) == 0 ) ||
( ( V_2 -> V_758 . V_761 & V_765 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_312 ) ;
} else {
V_2 -> V_66 . V_67 = V_567 ;
}
V_757:
if ( V_755 == 1 )
F_367 ( V_754 ) ;
V_73:
return;
}
static inline void F_368 ( struct V_1 * V_2 ,
struct V_526 * * V_766 ,
void (* * F_369) ( struct V_158 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_184 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_766 [ V_184 + V_44 ] = (struct V_526 * )
F_313 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_369 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_248 ( struct V_1 * V_2 )
{
struct V_767 V_768 ;
char * V_769 ;
struct V_526 * * V_766 ;
void (* * F_369) ( struct V_158 * , int , unsigned long );
struct V_526 * * V_770 ;
int V_44 , V_45 , V_771 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_313 ) ;
V_769 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_769 ) {
V_37 = - V_50 ;
goto V_772;
}
F_237 ( V_2 , V_769 ) ;
F_241 ( V_2 , V_769 ) ;
V_766 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_766 ) {
V_37 = - V_50 ;
goto V_773;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_766 [ V_44 ] = (struct V_526 * )
F_313 ( V_2 -> V_46 . V_425 -> V_63 [ V_44 ] . V_64 ) ;
}
F_369 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_369 ) {
V_37 = - V_50 ;
goto V_774;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_369 [ V_44 ] = V_2 -> V_149 -> V_775 ;
F_368 ( V_2 , V_766 , F_369 ) ;
V_770 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_770 ) {
V_37 = - V_50 ;
goto V_776;
}
for ( V_44 = 0 , V_771 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_771 ) {
V_770 [ V_771 ] = (struct V_526 * ) F_313 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_768 , 0 , sizeof( struct V_767 ) ) ;
V_768 . V_159 = F_44 ( V_2 ) ;
V_768 . V_777 = F_363 ( V_2 ) ;
V_768 . V_778 = 0 ;
V_768 . V_769 = V_769 ;
V_768 . V_779 = V_2 -> V_46 . V_72 ;
V_768 . V_780 = V_2 -> V_46 . V_78 ;
V_768 . V_781 = V_2 -> V_149 -> V_781 ;
V_768 . V_782 = V_2 -> V_149 -> V_782 ;
V_768 . V_783 = F_369 ;
V_768 . V_784 = ( unsigned long ) V_2 ;
V_768 . V_785 = ( void * * ) V_766 ;
V_768 . V_786 = ( void * * ) V_770 ;
V_768 . V_787 = V_2 -> V_46 . V_77 ;
V_768 . V_788 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_335 ,
V_331 ) == V_335 ) {
V_37 = F_370 ( & V_768 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_335 ) ;
goto V_73;
}
V_37 = F_371 ( & V_768 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_335 ) ;
F_249 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_314 ) ;
break;
case V_278 :
F_89 ( & V_2 -> V_10 -> V_9 , L_315 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_770 ) ;
V_776:
F_32 ( F_369 ) ;
V_774:
F_32 ( V_766 ) ;
V_773:
F_32 ( V_769 ) ;
V_772:
return V_37 ;
}
static void F_372 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_316 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_130 ( & V_2 -> V_114 ) ;
F_130 ( & V_2 -> V_155 ) ;
if ( V_2 -> V_9 )
F_373 ( V_2 -> V_9 ) ;
F_32 ( V_2 -> V_289 ) ;
F_132 ( V_2 ) ;
F_374 ( & V_2 -> V_301 ) ;
F_32 ( V_2 ) ;
}
void F_375 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_317 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_484 . V_472 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_484 . V_487 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_486 . V_472 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_486 . V_487 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_471 . V_472 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_66 . V_471 . V_487 ) ;
F_52 ( V_2 , 2 , L_318 , V_2 -> V_12 . V_500 ) ;
}
int F_376 ( struct V_1 * V_2 )
{
int V_789 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_319 ) ;
F_60 ( & V_2 -> V_534 , 0 ) ;
F_134 ( V_2 ) ;
V_790:
if ( V_789 < 3 )
F_68 ( 2 , L_320 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_367 ( F_44 ( V_2 ) ) ;
F_367 ( F_377 ( V_2 ) ) ;
F_367 ( F_152 ( V_2 ) ) ;
F_249 ( F_44 ( V_2 ) ) ;
V_37 = F_365 ( F_152 ( V_2 ) ) ;
if ( V_37 )
goto V_791;
V_37 = F_365 ( F_377 ( V_2 ) ) ;
if ( V_37 )
goto V_791;
V_37 = F_365 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_791;
V_791:
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_321 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_789 < 0 )
goto V_73;
else
goto V_790;
}
F_364 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
V_37 = F_173 ( & V_2 -> V_114 , F_185 ) ;
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_322 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
if ( -- V_789 < 0 )
goto V_73;
else
goto V_790;
}
V_37 = F_173 ( & V_2 -> V_155 , F_182 ) ;
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_323 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
if ( -- V_789 < 0 )
goto V_73;
else
goto V_790;
}
V_2 -> V_123 = 0 ;
V_37 = F_247 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_73;
}
V_2 -> V_66 . V_484 . V_472 = 0 ;
V_2 -> V_66 . V_471 . V_472 = 0 ;
V_2 -> V_66 . V_792 . V_472 = 0 ;
V_2 -> V_12 . V_500 = 0 ;
V_37 = F_280 ( V_2 , V_394 ) ;
if ( V_37 == - V_50 )
goto V_73;
if ( F_338 ( V_2 , V_485 ) ) {
V_37 = F_278 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_73;
}
}
if ( F_282 ( V_2 , V_793 ) ) {
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
static inline int F_378 ( struct V_445 * V_794 ,
struct V_795 * V_245 ,
struct V_232 * * V_796 , int V_184 , int * V_797 , int V_607 )
{
struct V_441 * V_441 = F_261 ( V_245 -> V_250 ) ;
if ( * V_796 == NULL ) {
if ( V_794 -> V_432 ) {
* V_796 = V_794 -> V_432 ;
V_794 -> V_432 = NULL ;
} else {
* V_796 = F_265 ( V_446 + V_447 ) ;
if ( ! ( * V_796 ) )
return - V_50 ;
}
F_379 ( * V_796 , V_447 ) ;
if ( V_607 <= V_446 ) {
memcpy ( F_380 ( * V_796 , V_607 ) , V_245 -> V_250 + V_184 ,
V_607 ) ;
} else {
F_381 ( V_441 ) ;
memcpy ( F_380 ( * V_796 , V_446 ) ,
V_245 -> V_250 + V_184 , V_446 ) ;
F_382 ( * V_796 , * V_797 , V_441 ,
V_184 + V_446 ,
V_607 - V_446 ) ;
( * V_796 ) -> V_607 += V_607 - V_446 ;
( * V_796 ) -> V_163 += V_607 - V_446 ;
( * V_796 ) -> V_798 += V_607 - V_446 ;
( * V_797 ) ++ ;
}
} else {
F_381 ( V_441 ) ;
F_382 ( * V_796 , * V_797 , V_441 , V_184 , V_607 ) ;
( * V_796 ) -> V_607 += V_607 ;
( * V_796 ) -> V_163 += V_607 ;
( * V_796 ) -> V_798 += V_607 ;
( * V_797 ) ++ ;
}
return 0 ;
}
static inline int F_383 ( struct V_795 * V_799 )
{
return ( V_799 -> V_254 & V_448 ) ;
}
struct V_232 * F_384 ( struct V_1 * V_2 ,
struct V_445 * V_794 ,
struct V_795 * * V_800 , int * V_801 ,
struct V_609 * * V_133 )
{
struct V_795 * V_245 = * V_800 ;
struct V_526 * V_64 = V_794 -> V_64 ;
int V_184 = * V_801 ;
struct V_232 * V_233 = NULL ;
int V_802 = 0 ;
void * V_803 ;
int V_607 ;
int V_804 = 0 ;
int V_805 = 0 ;
int V_600 = 0 ;
if ( V_245 -> V_253 < V_184 + sizeof( struct V_609 ) ) {
if ( F_383 ( V_245 ) )
return NULL ;
V_245 ++ ;
V_184 = 0 ;
if ( V_245 -> V_253 < sizeof( struct V_609 ) )
return NULL ;
}
* V_133 = V_245 -> V_250 + V_184 ;
V_184 += sizeof( struct V_609 ) ;
switch ( ( * V_133 ) -> V_133 . V_806 . V_314 ) {
case V_807 :
V_802 = ( * V_133 ) -> V_133 . V_806 . V_808 ;
break;
case V_809 :
V_802 = ( * V_133 ) -> V_133 . V_624 . V_253 ;
V_804 = V_447 ;
break;
case V_810 :
V_802 = ( * V_133 ) -> V_133 . V_811 . V_812 ;
V_804 = sizeof( struct V_609 ) ;
break;
default:
break;
}
if ( ! V_802 )
return NULL ;
if ( ( ( V_802 >= V_2 -> V_66 . V_274 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_534 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_805 = 1 ;
} else {
V_233 = F_265 ( V_802 + V_804 ) ;
if ( ! V_233 )
goto V_813;
if ( V_804 )
F_379 ( V_233 , V_804 ) ;
}
V_803 = V_245 -> V_250 + V_184 ;
while ( V_802 ) {
V_607 = F_212 ( V_802 , ( int ) ( V_245 -> V_253 - V_184 ) ) ;
if ( V_607 ) {
if ( V_805 ) {
if ( F_378 ( V_794 , V_245 ,
& V_233 , V_184 , & V_600 , V_607 ) )
goto V_813;
} else {
memcpy ( F_380 ( V_233 , V_607 ) , V_803 ,
V_607 ) ;
}
}
V_802 -= V_607 ;
if ( V_802 ) {
if ( F_383 ( V_245 ) ) {
F_4 ( V_2 , 4 , L_325 ) ;
F_385 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_127 ( V_233 ) ;
V_2 -> V_529 . V_703 ++ ;
return NULL ;
}
V_245 ++ ;
V_184 = 0 ;
V_803 = V_245 -> V_250 ;
} else {
V_184 += V_607 ;
}
}
* V_800 = V_245 ;
* V_801 = V_184 ;
if ( V_805 && V_2 -> V_66 . V_273 ) {
V_2 -> V_443 . V_814 ++ ;
V_2 -> V_443 . V_815 += F_321 ( V_233 ) -> V_601 ;
}
return V_233 ;
V_813:
if ( F_386 () ) {
F_4 ( V_2 , 2 , L_326 ) ;
}
V_2 -> V_529 . V_530 ++ ;
return NULL ;
}
static void F_387 ( void )
{
int V_816 ;
for ( V_816 = 0 ; V_816 < V_817 ; V_816 ++ ) {
F_388 ( V_818 [ V_816 ] . V_314 ) ;
V_818 [ V_816 ] . V_314 = NULL ;
}
}
void F_389 ( T_5 * V_314 , int V_373 , char * V_819 , ... )
{
char V_820 [ 32 ] ;
T_6 args ;
if ( ! F_390 ( V_314 , V_373 ) )
return;
va_start ( args , V_819 ) ;
vsnprintf ( V_820 , sizeof( V_820 ) , V_819 , args ) ;
va_end ( args ) ;
F_391 ( V_314 , V_373 , V_820 ) ;
}
static int F_392 ( void )
{
int V_338 ;
int V_816 ;
for ( V_816 = 0 ; V_816 < V_817 ; V_816 ++ ) {
V_818 [ V_816 ] . V_314 = F_393 ( V_818 [ V_816 ] . V_517 ,
V_818 [ V_816 ] . V_821 ,
V_818 [ V_816 ] . V_822 ,
V_818 [ V_816 ] . V_163 ) ;
if ( V_818 [ V_816 ] . V_314 == NULL ) {
F_387 () ;
return - V_50 ;
}
V_338 = F_394 ( V_818 [ V_816 ] . V_314 , V_818 [ V_816 ] . V_823 ) ;
if ( V_338 ) {
F_387 () ;
return V_338 ;
}
F_395 ( V_818 [ V_816 ] . V_314 , V_818 [ V_816 ] . V_373 ) ;
}
return 0 ;
}
int F_396 ( struct V_1 * V_2 ,
enum V_824 V_149 )
{
int V_37 = 0 ;
F_397 ( & V_825 ) ;
switch ( V_149 ) {
case V_826 :
V_2 -> V_149 = F_398 (
F_399 ( V_827 ) , L_327 ) ;
break;
case V_828 :
V_2 -> V_149 = F_398 (
F_399 ( V_829 ) , L_328 ) ;
break;
}
if ( ! V_2 -> V_149 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_329
L_330 , V_149 ) ;
V_37 = - V_406 ;
}
F_400 ( & V_825 ) ;
return V_37 ;
}
void F_401 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_307 )
F_402 ( V_829 ) ;
else
F_402 ( V_827 ) ;
V_2 -> V_149 = NULL ;
}
static T_5 * F_403 ( char * V_517 )
{
struct V_830 * V_439 ;
T_5 * V_37 = NULL ;
F_397 ( & V_831 ) ;
F_254 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_439 -> V_832 , V_517 ) == 0 ) {
V_37 = V_439 -> V_833 ;
break;
}
}
F_400 ( & V_831 ) ;
return V_37 ;
}
static int F_404 ( struct V_1 * V_2 , char * V_517 )
{
struct V_830 * V_834 ;
V_2 -> V_835 = F_393 ( V_517 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_835 ) {
F_45 ( V_65 , 2 , L_191 , L_331 ) ;
goto V_836;
}
if ( F_394 ( V_2 -> V_835 , & V_837 ) )
goto V_838;
V_834 = F_27 ( sizeof( struct V_830 ) , V_49 ) ;
if ( ! V_834 )
goto V_838;
strncpy ( V_834 -> V_832 , V_517 , V_839 ) ;
V_834 -> V_833 = V_2 -> V_835 ;
F_397 ( & V_831 ) ;
F_33 ( & V_834 -> V_840 , & V_841 ) ;
F_400 ( & V_831 ) ;
return 0 ;
V_838:
F_388 ( V_2 -> V_835 ) ;
V_836:
return - V_50 ;
}
static void F_405 ( void )
{
struct V_830 * V_439 , * V_41 ;
F_397 ( & V_831 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_439 -> V_840 ) ;
F_388 ( V_439 -> V_833 ) ;
F_32 ( V_439 ) ;
}
F_400 ( & V_831 ) ;
}
static int F_406 ( struct V_160 * V_10 )
{
struct V_1 * V_2 ;
struct V_842 * V_9 ;
int V_37 ;
unsigned long V_32 ;
char V_832 [ V_839 ] ;
F_41 ( V_65 , 2 , L_332 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_407 ( V_9 ) )
return - V_843 ;
F_45 ( V_65 , 2 , L_191 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_149 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_844;
}
snprintf ( V_832 , sizeof( V_832 ) , L_333 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_835 = F_403 ( V_832 ) ;
if ( ! V_2 -> V_835 ) {
V_37 = F_404 ( V_2 , V_832 ) ;
if ( V_37 )
goto V_845;
}
V_2 -> V_114 . V_119 = V_10 -> V_159 [ 0 ] ;
V_2 -> V_155 . V_119 = V_10 -> V_159 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_159 [ 2 ] ;
F_408 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_159 [ 0 ] -> V_846 = F_118 ;
V_10 -> V_159 [ 1 ] -> V_846 = F_118 ;
V_10 -> V_159 [ 2 ] -> V_846 = F_118 ;
V_37 = F_151 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_845;
}
V_37 = F_142 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_845;
}
if ( V_2 -> V_12 . type == V_18 )
V_10 -> V_9 . type = & V_847 ;
else
V_10 -> V_9 . type = & V_848 ;
switch ( V_2 -> V_12 . type ) {
case V_18 :
case V_16 :
V_37 = F_396 ( V_2 , V_828 ) ;
if ( V_37 )
goto V_845;
V_37 = V_2 -> V_149 -> V_849 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_850;
case V_14 :
case V_17 :
default:
break;
}
F_409 ( & V_851 . V_852 , V_32 ) ;
F_102 ( & V_2 -> V_42 , & V_851 . V_42 ) ;
F_410 ( & V_851 . V_852 , V_32 ) ;
F_364 ( V_2 ) ;
return 0 ;
V_850:
F_401 ( V_2 ) ;
V_845:
F_372 ( V_2 ) ;
V_844:
F_411 ( V_9 ) ;
return V_37 ;
}
static void F_412 ( struct V_160 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_334 ) ;
if ( V_2 -> V_149 ) {
V_2 -> V_149 -> remove ( V_10 ) ;
F_401 ( V_2 ) ;
}
F_409 ( & V_851 . V_852 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_410 ( & V_851 . V_852 , V_32 ) ;
F_372 ( V_2 ) ;
F_408 ( & V_10 -> V_9 , NULL ) ;
F_411 ( & V_10 -> V_9 ) ;
return;
}
static int F_413 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
int V_853 ;
if ( ! V_2 -> V_149 ) {
if ( V_2 -> V_12 . type == V_15 )
V_853 = V_826 ;
else
V_853 = V_828 ;
V_37 = F_396 ( V_2 , V_853 ) ;
if ( V_37 )
goto V_836;
V_37 = V_2 -> V_149 -> V_849 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_836;
}
V_37 = V_2 -> V_149 -> V_854 ( V_10 ) ;
V_836:
return V_37 ;
}
static int F_414 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
return V_2 -> V_149 -> V_855 ( V_10 ) ;
}
static void F_415 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_856 )
V_2 -> V_149 -> V_856 ( V_10 ) ;
}
static int F_416 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_857 )
return V_2 -> V_149 -> V_857 ( V_10 ) ;
return 0 ;
}
static void F_417 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_858 )
V_2 -> V_149 -> V_858 ( V_10 ) ;
}
static int F_418 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_859 )
return V_2 -> V_149 -> V_859 ( V_10 ) ;
return 0 ;
}
static int F_419 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_860 )
return V_2 -> V_149 -> V_860 ( V_10 ) ;
return 0 ;
}
static int F_420 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_861 )
return V_2 -> V_149 -> V_861 ( V_10 ) ;
return 0 ;
}
static T_7 F_421 ( struct V_862 * V_863 ,
const char * V_231 , T_8 V_167 )
{
int V_836 ;
V_836 = F_422 ( V_864 ,
& V_865 , 3 , V_231 ) ;
return V_836 ? V_836 : V_167 ;
}
int F_423 ( struct V_637 * V_9 , int V_866 )
{
switch ( V_866 ) {
case V_867 :
return ( sizeof( V_868 ) / V_869 ) ;
default:
return - V_406 ;
}
}
void F_424 ( struct V_637 * V_9 ,
struct V_870 * V_529 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_642 ;
V_117 [ 0 ] = V_2 -> V_529 . V_871 -
V_2 -> V_443 . V_872 ;
V_117 [ 1 ] = V_2 -> V_443 . V_873 ;
V_117 [ 2 ] = V_2 -> V_529 . V_874 -
V_2 -> V_443 . V_875 ;
V_117 [ 3 ] = V_2 -> V_443 . V_558 ;
V_117 [ 4 ] = V_2 -> V_529 . V_874 - V_2 -> V_443 . V_875
- V_2 -> V_443 . V_628 ;
V_117 [ 5 ] = V_2 -> V_443 . V_558 - V_2 -> V_443 . V_562 ;
V_117 [ 6 ] = V_2 -> V_443 . V_628 ;
V_117 [ 7 ] = V_2 -> V_443 . V_562 ;
V_117 [ 8 ] = V_2 -> V_443 . V_876 ;
V_117 [ 9 ] = V_2 -> V_443 . V_877 ;
V_117 [ 10 ] = V_2 -> V_443 . V_814 ;
V_117 [ 11 ] = V_2 -> V_443 . V_815 ;
V_117 [ 12 ] = V_2 -> V_443 . V_444 ;
V_117 [ 13 ] = ( V_2 -> V_443 . V_878 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_443 . V_879 ;
V_117 [ 15 ] = V_2 -> V_443 . V_544 ;
V_117 [ 16 ] = V_2 -> V_443 . V_547 ;
V_117 [ 17 ] = V_546 ;
V_117 [ 18 ] = V_543 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_451 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_451 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_451 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_451 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_443 . V_880 ;
V_117 [ 24 ] = V_2 -> V_443 . V_881 ;
V_117 [ 25 ] = V_2 -> V_443 . V_538 ;
V_117 [ 26 ] = V_2 -> V_443 . V_536 ;
V_117 [ 27 ] = V_2 -> V_443 . V_581 ;
V_117 [ 28 ] = V_2 -> V_443 . V_577 ;
V_117 [ 29 ] = V_2 -> V_443 . V_882 ;
V_117 [ 30 ] = V_2 -> V_443 . V_883 ;
V_117 [ 31 ] = V_2 -> V_443 . V_555 ;
V_117 [ 32 ] = V_2 -> V_443 . V_551 ;
V_117 [ 33 ] = V_2 -> V_443 . V_884 ;
V_117 [ 34 ] = V_2 -> V_443 . V_885 ;
V_117 [ 35 ] = V_2 -> V_443 . V_569 ;
V_117 [ 36 ] = V_2 -> V_443 . V_573 ;
}
void F_425 ( struct V_637 * V_9 , V_713 V_866 , V_279 * V_117 )
{
switch ( V_866 ) {
case V_867 :
memcpy ( V_117 , & V_868 ,
sizeof( V_868 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_426 ( struct V_637 * V_9 ,
struct V_886 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_642 ;
F_427 ( V_12 -> V_887 , V_2 -> V_66 . V_307 ? L_328 : L_327 ,
sizeof( V_12 -> V_887 ) ) ;
F_427 ( V_12 -> V_888 , L_335 , sizeof( V_12 -> V_888 ) ) ;
F_427 ( V_12 -> V_889 , V_2 -> V_12 . V_302 ,
sizeof( V_12 -> V_889 ) ) ;
snprintf ( V_12 -> V_890 , sizeof( V_12 -> V_890 ) , L_336 ,
F_428 ( V_2 ) , F_429 ( V_2 ) , F_430 ( V_2 ) ) ;
}
static void F_431 ( struct V_891 * V_892 ,
int V_893 , int V_894 )
{
int V_895 , V_896 , V_897 , V_898 ;
switch ( V_894 ) {
case V_899 :
V_895 = V_900 ;
V_896 = V_901 ;
break;
case V_902 :
V_895 = V_903 ;
V_896 = V_904 ;
break;
default:
V_895 = V_900 ;
V_896 = V_901 ;
F_54 ( 1 ) ;
}
V_897 = 0 ;
V_898 = 0 ;
switch ( V_893 ) {
case V_905 :
V_897 |= V_906 ;
V_898 |= V_907 ;
case V_908 :
V_897 |= V_909 | V_910 ;
V_898 |= V_911 |
V_912 ;
case V_913 :
V_897 |= V_914 | V_915 ;
V_898 |= V_916 | V_917 ;
case V_918 :
V_897 |= V_919 | V_920 ;
V_898 |= V_921 | V_922 ;
break;
default:
V_897 = V_919 | V_920 ;
V_898 = V_921 | V_922 ;
F_54 ( 1 ) ;
}
V_892 -> V_923 = V_924 | V_896 | V_898 ;
V_892 -> V_925 = V_926 | V_895 | V_897 ;
}
int F_432 ( struct V_637 * V_927 ,
struct V_891 * V_892 )
{
struct V_1 * V_2 = V_927 -> V_642 ;
enum V_453 V_19 ;
struct V_749 V_749 ;
int V_37 ;
V_713 V_928 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_892 -> V_929 = V_930 ;
V_892 -> V_931 = V_932 ;
V_892 -> V_933 = V_934 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
F_431 ( V_892 , V_913 , V_899 ) ;
V_928 = V_913 ;
V_892 -> V_935 = V_899 ;
break;
case V_22 :
case V_26 :
F_431 ( V_892 , V_908 , V_902 ) ;
V_928 = V_908 ;
V_892 -> V_935 = V_902 ;
break;
case V_23 :
F_431 ( V_892 , V_905 , V_902 ) ;
V_928 = V_905 ;
V_892 -> V_935 = V_902 ;
break;
default:
F_431 ( V_892 , V_918 , V_899 ) ;
V_928 = V_918 ;
V_892 -> V_935 = V_899 ;
}
F_433 ( V_892 , V_928 ) ;
if ( ! F_1 ( V_2 ) )
return - V_843 ;
V_37 = V_747 ( V_2 , & V_749 ) ;
if ( V_37 == - V_340 )
return 0 ;
if ( V_37 )
return V_37 ;
F_434 ( V_927 ,
L_337 ,
V_749 . V_750 ,
V_749 . V_751 ,
V_749 . V_752 ) ;
switch ( V_749 . V_750 ) {
case V_936 :
case V_937 :
F_431 ( V_892 , V_908 , V_899 ) ;
V_892 -> V_935 = V_899 ;
break;
case V_938 :
case V_939 :
F_431 ( V_892 , V_908 , V_902 ) ;
V_892 -> V_935 = V_902 ;
break;
case V_940 :
case V_941 :
F_431 ( V_892 , V_905 , V_902 ) ;
V_892 -> V_935 = V_902 ;
break;
}
switch ( V_749 . V_751 ) {
case V_942 :
V_892 -> V_931 = V_932 ;
break;
case V_943 :
V_892 -> V_931 = V_944 ;
break;
}
switch ( V_749 . V_752 ) {
case V_945 :
V_928 = V_918 ;
break;
case V_946 :
V_928 = V_913 ;
break;
case V_947 :
V_928 = V_908 ;
break;
case V_948 :
V_928 = V_905 ;
break;
}
F_433 ( V_892 , V_928 ) ;
return 0 ;
}
static int T_10 F_435 ( void )
{
int V_37 ;
F_436 ( L_338 ) ;
F_137 ( & V_851 . V_42 ) ;
F_137 ( & V_841 ) ;
F_437 ( & V_851 . V_852 ) ;
F_143 ( & V_825 ) ;
V_11 = F_438 ( L_339 ) ;
V_37 = F_392 () ;
if ( V_37 )
goto V_949;
V_864 = F_439 ( L_340 ) ;
V_37 = F_440 ( V_864 ) ;
if ( V_37 )
goto V_950;
V_252 = F_441 ( L_341 ,
sizeof( struct V_609 ) + V_447 , 64 , 0 , NULL ) ;
if ( ! V_252 ) {
V_37 = - V_50 ;
goto V_951;
}
V_101 = F_441 ( L_342 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_952;
}
V_37 = F_442 ( & V_953 ) ;
if ( V_37 )
goto V_954;
V_865 . V_887 . V_955 = V_956 ;
V_37 = F_443 ( & V_865 ) ;
if ( V_37 )
goto V_957;
return 0 ;
V_957:
F_444 ( & V_953 ) ;
V_954:
F_445 ( V_101 ) ;
V_952:
F_445 ( V_252 ) ;
V_951:
F_446 ( V_864 ) ;
V_950:
F_387 () ;
V_949:
F_447 ( L_343 ) ;
return V_37 ;
}
static void T_11 F_448 ( void )
{
F_405 () ;
F_449 ( V_11 ) ;
F_450 ( & V_865 ) ;
F_444 ( & V_953 ) ;
F_445 ( V_101 ) ;
F_445 ( V_252 ) ;
F_446 ( V_864 ) ;
F_387 () ;
F_436 ( L_344 ) ;
}
