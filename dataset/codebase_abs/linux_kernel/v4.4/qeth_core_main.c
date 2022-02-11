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
memcpy ( & V_362 , F_177 ( V_113 -> V_117 ) , 2 ) ;
if ( V_362 != F_181 ( V_2 -> V_12 . V_260 ) ) {
F_68 ( 2 , L_160
L_161 ,
F_69 ( & V_2 -> V_114 . V_119 -> V_9 ) ,
V_2 -> V_12 . V_260 , V_362 ) ;
goto V_73;
}
memcpy ( & V_2 -> V_354 . V_377 ,
F_176 ( V_113 -> V_117 ) ,
V_370 ) ;
memcpy ( & V_2 -> V_12 . V_302 [ 0 ] ,
F_186 ( V_113 -> V_117 ) , V_378 ) ;
V_162 -> V_3 = V_115 ;
V_73:
F_98 ( V_162 , V_113 ) ;
}
void F_187 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 )
{
F_70 ( & V_2 -> V_155 , V_113 -> V_117 , V_163 ) ;
V_113 -> V_175 = F_98 ;
memcpy ( F_174 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_367 , V_189 ) ;
V_2 -> V_182 . V_367 ++ ;
memcpy ( F_103 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_379 , V_189 ) ;
V_2 -> V_182 . V_379 ++ ;
memcpy ( F_188 ( V_113 -> V_117 ) ,
& V_2 -> V_182 . V_188 , V_189 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
}
int F_189 ( struct V_1 * V_2 , int V_163 ,
struct V_112 * V_113 ,
int (* F_190)( struct V_1 * V_380 ,
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
F_98 ( V_113 -> V_162 , V_113 ) ;
return - V_116 ;
}
V_125 = F_73 ( V_2 ) ;
if ( ! V_125 ) {
return - V_50 ;
}
V_125 -> V_175 = F_190 ;
V_125 -> V_386 = V_383 ;
if ( V_2 -> V_3 == V_55 )
V_125 -> V_182 = V_183 ;
else
V_125 -> V_182 = V_2 -> V_182 . V_387 ++ ;
F_106 ( & V_125 -> V_36 ) ;
F_17 ( & V_2 -> V_154 , V_32 ) ;
F_102 ( & V_125 -> V_42 , & V_2 -> V_187 ) ;
F_18 ( & V_2 -> V_154 , V_32 ) ;
F_39 ( V_156 , 2 , V_113 -> V_117 , V_157 ) ;
while ( F_59 ( & V_2 -> V_155 . V_122 , 0 , 1 ) ) ;
F_187 ( V_2 , V_163 , V_113 ) ;
if ( F_84 ( V_113 -> V_117 ) )
V_385 = V_388 ;
else
V_385 = V_323 ;
V_384 = V_389 + V_385 ;
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
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
if ( ( V_130 -> V_133 . V_134 == V_391 ) &&
( V_130 -> V_133 . V_392 == V_393 ) ) {
if ( ! F_191 ( V_125 -> V_36 ,
F_51 ( & V_125 -> V_128 ) , V_385 ) )
goto V_394;
} else {
while ( ! F_51 ( & V_125 -> V_128 ) ) {
if ( F_192 ( V_389 , V_384 ) )
goto V_394;
F_193 () ;
}
}
if ( V_125 -> V_37 == - V_116 )
goto error;
V_37 = V_125 -> V_37 ;
F_77 ( V_125 ) ;
return V_37 ;
V_394:
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
static int F_194 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_166 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_395 ,
F_195 ( V_113 -> V_117 ) ,
V_370 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_167 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_396 , V_397 ) ;
memcpy ( F_197 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_377 , V_370 ) ;
memcpy ( F_198 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_356 , V_370 ) ;
V_37 = F_189 ( V_2 , V_397 , V_113 ,
F_194 , NULL ) ;
return V_37 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_168 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_398 ,
F_200 ( V_113 -> V_117 ) ,
V_370 ) ;
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_169 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_399 , V_400 ) ;
memcpy ( F_202 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_377 , V_370 ) ;
memcpy ( F_203 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_357 , V_370 ) ;
memcpy ( F_204 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_395 , V_370 ) ;
V_37 = F_189 ( V_2 , V_400 , V_113 ,
F_199 , NULL ) ;
return V_37 ;
}
static inline int F_205 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_321 :
return 1500 ;
case V_15 :
return V_2 -> V_12 . V_401 ;
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
static inline int F_206 ( int V_402 )
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
static inline int F_207 ( struct V_1 * V_2 , int V_403 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
case V_15 :
return ( ( V_403 >= 576 ) &&
( V_403 <= V_2 -> V_12 . V_401 ) ) ;
case V_18 :
case V_321 :
default:
return 1 ;
}
}
static int F_208 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
V_185 V_403 , V_402 ;
V_185 V_163 ;
T_2 V_19 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_170 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_404 ,
F_209 ( V_113 -> V_117 ) ,
V_370 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
memcpy ( & V_402 , F_210 ( V_113 -> V_117 ) , 2 ) ;
V_403 = F_206 ( V_402 ) ;
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
V_2 -> V_46 . V_263 = V_403 + 2 * V_407 ;
} else {
V_2 -> V_12 . V_401 = * ( V_185 * ) F_210 (
V_113 -> V_117 ) ;
V_2 -> V_12 . V_406 = F_211 ( V_2 -> V_12 . V_401 ,
F_205 ( V_2 ) ) ;
V_2 -> V_46 . V_263 = V_264 ;
}
memcpy ( & V_163 , F_212 ( V_113 -> V_117 ) , 2 ) ;
if ( V_163 >= V_408 ) {
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
char V_409 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_172 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_410 , V_411 ) ;
* ( F_215 ( V_113 -> V_117 ) ) =
( T_2 ) V_2 -> V_12 . V_369 ;
if ( V_2 -> V_66 . V_307 )
if ( V_2 -> V_12 . type == V_18 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
memcpy ( F_216 ( V_113 -> V_117 ) , & V_409 , 1 ) ;
memcpy ( F_217 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_398 , V_370 ) ;
memcpy ( F_218 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_358 , V_370 ) ;
V_37 = F_189 ( V_2 , V_411 , V_113 ,
F_208 , NULL ) ;
return V_37 ;
}
static int F_219 ( struct V_1 * V_2 , struct V_124 * V_125 ,
unsigned long V_117 )
{
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_173 ) ;
V_113 = (struct V_112 * ) V_117 ;
memcpy ( & V_2 -> V_354 . V_415 ,
F_220 ( V_113 -> V_117 ) ,
V_370 ) ;
if ( ! strncmp ( L_174 , F_220 ( V_113 -> V_117 ) ,
3 ) ) {
F_41 ( V_65 , 2 , L_175 ) ;
F_47 ( & V_2 -> V_10 -> V_9 , L_176
L_177 ) ;
V_113 -> V_37 = - V_416 ;
}
F_45 ( V_65 , 2 , L_77 , V_113 -> V_37 ) ;
return 0 ;
}
static int F_221 ( struct V_1 * V_2 )
{
int V_37 ;
V_185 V_362 ;
struct V_112 * V_113 ;
struct V_363 V_417 ;
F_41 ( V_65 , 2 , L_178 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_418 , V_419 ) ;
memcpy ( F_222 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_398 , V_370 ) ;
memcpy ( F_223 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_359 , V_370 ) ;
memcpy ( F_224 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_404 , V_370 ) ;
F_178 ( F_44 ( V_2 ) , & V_417 ) ;
memcpy ( F_225 ( V_113 -> V_117 ) , & V_417 . V_371 , 2 ) ;
V_362 = ( V_2 -> V_12 . V_348 << 8 ) + V_2 -> V_12 . V_347 ;
memcpy ( F_226 ( V_113 -> V_117 ) , & V_362 , 2 ) ;
V_37 = F_189 ( V_2 , V_419 , V_113 ,
F_219 , NULL ) ;
return V_37 ;
}
static int F_56 ( struct V_92 * V_60 , int V_93 )
{
int V_37 ;
struct V_96 * V_420 ;
V_37 = 0 ;
V_420 = F_227 ( V_101 , V_126 ) ;
if ( ! V_420 ) {
V_37 = - V_50 ;
goto V_73;
}
V_420 -> V_64 = V_60 -> V_61 [ V_93 ] ;
F_228 ( & V_420 -> V_234 ) ;
F_229 ( & V_420 -> V_234 . V_154 , & V_421 ) ;
V_420 -> V_60 = V_60 ;
V_420 -> V_102 = NULL ;
V_420 -> V_95 = V_60 -> V_63 [ V_93 ] ;
F_60 ( & V_420 -> V_3 , V_249 ) ;
V_60 -> V_63 [ V_93 ] = V_420 ;
if ( V_60 -> V_81 ) {
V_60 -> V_81 [ V_93 ] . V_422 = V_420 ;
F_52 ( V_60 -> V_2 , 2 , L_179 , V_93 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 , ( long ) V_420 ) ;
F_52 ( V_60 -> V_2 , 2 , L_43 ,
( long ) V_420 -> V_95 ) ;
}
V_73:
return V_37 ;
}
static void F_230 ( struct V_92 * V_60 )
{
if ( ! V_60 )
return;
F_36 ( V_60 -> V_61 , V_62 ) ;
F_32 ( V_60 ) ;
}
static struct V_92 * F_231 ( void )
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
static int F_232 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
F_41 ( V_65 , 2 , L_180 ) ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_256 ,
V_335 ) != V_256 )
return 0 ;
F_41 ( V_65 , 2 , L_181 ) ;
V_2 -> V_46 . V_423 = F_37 () ;
if ( ! V_2 -> V_46 . V_423 )
goto V_424;
if ( F_26 ( V_2 ) )
goto V_425;
V_2 -> V_46 . V_80 =
F_27 ( V_2 -> V_46 . V_78 *
sizeof( struct V_92 * ) , V_49 ) ;
if ( ! V_2 -> V_46 . V_80 )
goto V_426;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
V_2 -> V_46 . V_80 [ V_44 ] = F_231 () ;
if ( ! V_2 -> V_46 . V_80 [ V_44 ] )
goto V_427;
F_45 ( V_65 , 2 , L_182 , V_44 ) ;
F_39 ( V_65 , 2 , & V_2 -> V_46 . V_80 [ V_44 ] , sizeof( void * ) ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_428 = V_44 ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
F_75 ( V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] != NULL ) ;
if ( F_56 ( V_2 -> V_46 . V_80 [ V_44 ] , V_45 ) )
goto V_429;
}
}
if ( F_46 ( V_2 ) )
goto V_427;
return 0 ;
V_429:
while ( V_45 > 0 ) {
-- V_45 ;
F_55 ( V_101 ,
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] ) ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] = NULL ;
}
V_427:
while ( V_44 > 0 ) {
F_230 ( V_2 -> V_46 . V_80 [ -- V_44 ] ) ;
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
V_426:
F_28 ( V_2 ) ;
V_425:
F_35 ( V_2 -> V_46 . V_423 ) ;
V_2 -> V_46 . V_423 = NULL ;
V_424:
F_60 ( & V_2 -> V_46 . V_3 , V_256 ) ;
return - V_50 ;
}
static void F_132 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
if ( F_233 ( & V_2 -> V_46 . V_3 , V_256 ) ==
V_256 )
return;
F_48 ( V_2 ) ;
F_234 ( & V_2 -> V_295 ) ;
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 ) {
if ( V_2 -> V_46 . V_423 -> V_63 [ V_45 ] . V_430 )
F_127 ( V_2 -> V_46 . V_423 -> V_63 [ V_45 ] . V_430 ) ;
}
F_35 ( V_2 -> V_46 . V_423 ) ;
V_2 -> V_46 . V_423 = NULL ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 . V_80 ) {
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 ) {
F_128 ( V_2 -> V_46 . V_80 [ V_44 ] , 1 ) ;
F_230 ( V_2 -> V_46 . V_80 [ V_44 ] ) ;
}
F_32 ( V_2 -> V_46 . V_80 ) ;
V_2 -> V_46 . V_80 = NULL ;
}
}
static void F_235 ( struct V_1 * V_2 ,
char * V_431 )
{
V_431 [ 0 ] = V_349 [ 'P' ] ;
V_431 [ 1 ] = V_349 [ 'C' ] ;
V_431 [ 2 ] = V_349 [ 'I' ] ;
V_431 [ 3 ] = V_349 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_431 [ 4 ] ) ) = F_236 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_431 [ 8 ] ) ) = F_237 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_431 [ 12 ] ) ) = F_238 ( V_2 ) ;
}
static void F_239 ( struct V_1 * V_2 ,
char * V_431 )
{
V_431 [ 16 ] = V_349 [ 'B' ] ;
V_431 [ 17 ] = V_349 [ 'L' ] ;
V_431 [ 18 ] = V_349 [ 'K' ] ;
V_431 [ 19 ] = V_349 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_431 [ 20 ] ) ) = V_2 -> V_12 . V_350 . V_351 ;
* ( ( unsigned int * ) ( & V_431 [ 24 ] ) ) = V_2 -> V_12 . V_350 . V_352 ;
* ( ( unsigned int * ) ( & V_431 [ 28 ] ) ) =
V_2 -> V_12 . V_350 . V_353 ;
}
static int F_240 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 3 , L_183 ) ;
return F_241 ( F_44 ( V_2 ) ) ;
}
static int F_242 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_184 ) ;
V_113 = F_99 ( & V_2 -> V_155 ) ;
memcpy ( V_113 -> V_117 , V_432 , V_433 ) ;
memcpy ( F_243 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_398 , V_370 ) ;
memcpy ( F_244 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_415 , V_370 ) ;
V_37 = F_189 ( V_2 , V_433 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_245 ( struct V_1 * V_2 )
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
goto V_434;
}
V_37 = F_201 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_434;
}
V_37 = F_214 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
goto V_434;
}
V_37 = F_221 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_434;
}
V_37 = F_232 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_434;
}
V_37 = F_246 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_132 ( V_2 ) ;
goto V_434;
}
V_37 = F_240 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_434;
}
V_37 = F_242 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_190 , V_37 ) ;
goto V_434;
}
return 0 ;
V_434:
F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_247 ( F_44 ( V_2 ) ) ;
return V_37 ;
}
void F_248 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_14 :
case V_16 :
case V_17 :
if ( ! V_2 -> V_12 . V_302 [ 0 ] ) {
sprintf ( V_2 -> V_12 . V_302 , L_191 ,
V_2 -> V_12 . V_302 [ 2 ] ,
V_2 -> V_12 . V_302 [ 3 ] ) ;
V_2 -> V_12 . V_302 [ V_378 ] = 0 ;
break;
}
case V_15 :
if ( ( V_2 -> V_12 . V_13 ) ||
( V_2 -> V_12 . V_302 [ 0 ] & 0x80 ) ) {
V_2 -> V_12 . V_302 [ 0 ] = ( char ) V_435 [ ( T_2 )
V_2 -> V_12 . V_302 [ 0 ] ] ;
V_2 -> V_12 . V_302 [ 1 ] = ( char ) V_435 [ ( T_2 )
V_2 -> V_12 . V_302 [ 1 ] ] ;
V_2 -> V_12 . V_302 [ 2 ] = ( char ) V_435 [ ( T_2 )
V_2 -> V_12 . V_302 [ 2 ] ] ;
V_2 -> V_12 . V_302 [ 3 ] = ( char ) V_435 [ ( T_2 )
V_2 -> V_12 . V_302 [ 3 ] ] ;
V_2 -> V_12 . V_302 [ V_378 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_12 . V_302 [ 0 ] , 0 , V_378 + 1 ) ;
}
F_89 ( & V_2 -> V_10 -> V_9 ,
L_192 ,
F_11 ( V_2 ) ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_193 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? V_2 -> V_12 . V_302 : L_74 ,
( V_2 -> V_12 . V_302 [ 0 ] ) ? L_194 : L_74 ,
F_12 ( V_2 ) ) ;
}
static void F_249 ( struct V_1 * V_2 )
{
struct V_39 * V_436 ;
F_4 ( V_2 , 5 , L_195 ) ;
F_250 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_251 ( V_2 , V_436 ) ;
}
}
static inline struct V_39 * F_252 (
struct V_1 * V_2 )
{
struct V_303 * V_437 ;
struct V_39 * V_436 ;
int V_44 , free ;
struct V_438 * V_438 ;
if ( F_253 ( & V_2 -> V_46 . V_58 . V_53 ) )
return NULL ;
F_254 (plh, &card->qdio.in_buf_pool.entry_list) {
V_436 = F_255 ( V_437 , struct V_39 , V_42 ) ;
free = 1 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_256 ( F_257 ( V_436 -> V_51 [ V_44 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_92 ( & V_436 -> V_42 ) ;
return V_436 ;
}
}
V_436 = F_255 ( V_2 -> V_46 . V_58 . V_53 . V_439 ,
struct V_39 , V_42 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
if ( F_256 ( F_257 ( V_436 -> V_51 [ V_44 ] ) ) > 1 ) {
V_438 = F_258 ( V_126 ) ;
if ( ! V_438 ) {
return NULL ;
} else {
F_31 ( ( unsigned long ) V_436 -> V_51 [ V_44 ] ) ;
V_436 -> V_51 [ V_44 ] = F_259 ( V_438 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_440 . V_441 ++ ;
}
}
}
F_92 ( & V_436 -> V_42 ) ;
return V_436 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_442 * V_231 )
{
struct V_39 * V_40 ;
int V_44 ;
if ( ( V_2 -> V_66 . V_67 == V_68 ) && ( ! V_231 -> V_430 ) ) {
V_231 -> V_430 = F_261 ( V_443 + V_444 ) ;
if ( ! V_231 -> V_430 )
return 1 ;
}
V_40 = F_252 ( V_2 ) ;
if ( ! V_40 )
return 1 ;
V_231 -> V_40 = V_40 ;
for ( V_44 = 0 ; V_44 < F_29 ( V_2 ) ; ++ V_44 ) {
V_231 -> V_64 -> V_245 [ V_44 ] . V_253 = V_407 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_250 = V_40 -> V_51 [ V_44 ] ;
if ( V_44 == F_29 ( V_2 ) - 1 )
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = V_445 ;
else
V_231 -> V_64 -> V_245 [ V_44 ] . V_254 = 0 ;
V_231 -> V_64 -> V_245 [ V_44 ] . V_246 = 0 ;
}
return 0 ;
}
int F_262 ( struct V_1 * V_2 )
{
int V_44 , V_45 ;
int V_37 ;
F_41 ( V_65 , 2 , L_196 ) ;
F_42 ( V_2 -> V_46 . V_423 -> V_61 ,
V_62 ) ;
F_249 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_58 . V_48 - 1 ; ++ V_44 )
F_260 ( V_2 , & V_2 -> V_46 . V_423 -> V_63 [ V_44 ] ) ;
V_2 -> V_46 . V_423 -> V_70 =
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
V_2 -> V_46 . V_80 [ V_44 ] -> V_446 = 0 ;
V_2 -> V_46 . V_80 [ V_44 ] -> V_447 = 0 ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_448 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_248 , 0 ) ;
F_60 ( & V_2 -> V_46 . V_80 [ V_44 ] -> V_3 ,
V_449 ) ;
}
return 0 ;
}
static inline T_2 F_263 ( enum V_450 V_19 )
{
switch ( V_19 ) {
case V_21 :
return 2 ;
default:
return 1 ;
}
}
static void F_264 ( struct V_1 * V_2 ,
struct V_129 * V_130 , T_2 V_134 ,
enum V_451 V_452 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_133 . V_134 = V_134 ;
V_130 -> V_133 . V_453 = V_454 ;
V_130 -> V_133 . V_182 = V_2 -> V_182 . V_387 ;
V_130 -> V_133 . V_455 = F_263 ( V_2 -> V_12 . V_19 ) ;
V_130 -> V_133 . V_456 = ( T_2 ) V_2 -> V_12 . V_369 ;
if ( V_2 -> V_66 . V_307 )
V_130 -> V_133 . V_457 = 2 ;
else
V_130 -> V_133 . V_457 = 1 ;
V_130 -> V_133 . V_458 = 1 ;
V_130 -> V_133 . V_392 = V_452 ;
V_130 -> V_133 . V_459 = 0 ;
V_130 -> V_133 . V_460 = 0 ;
}
struct V_112 * F_265 ( struct V_1 * V_2 ,
enum V_461 V_462 , enum V_451 V_452 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_66 ( & V_2 -> V_155 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
F_264 ( V_2 , V_130 , V_462 , V_452 ) ;
} else {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_197 ) ;
F_68 ( 1 , L_198 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
}
return V_113 ;
}
void F_266 ( struct V_1 * V_2 , struct V_112 * V_113 ,
char V_409 )
{
memcpy ( V_113 -> V_117 , V_463 , V_390 ) ;
memcpy ( F_267 ( V_113 -> V_117 ) , & V_409 , 1 ) ;
memcpy ( F_268 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_415 , V_370 ) ;
}
int F_269 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int (* F_190)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_383 )
{
int V_37 ;
char V_409 ;
F_4 ( V_2 , 4 , L_199 ) ;
if ( V_2 -> V_66 . V_307 )
if ( V_2 -> V_12 . type == V_18 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
F_266 ( V_2 , V_113 , V_409 ) ;
V_37 = F_189 ( V_2 , V_464 ,
V_113 , F_190 , V_383 ) ;
if ( V_37 == - V_325 ) {
F_91 ( V_2 ) ;
F_72 ( V_2 ) ;
}
return V_37 ;
}
int F_270 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_41 ( V_65 , 2 , L_200 ) ;
V_113 = F_265 ( V_2 , V_144 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_269 ( V_2 , V_113 , NULL , NULL ) ;
return V_37 ;
}
static int F_271 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_201 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 )
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_465 . V_133 . V_139 ;
return 0 ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 3 , L_202 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_117 . V_465 . V_117 . V_466 . V_467 & 0x7f ) {
V_2 -> V_12 . V_19 =
V_130 -> V_117 . V_465 . V_117 . V_466 . V_467 ;
F_45 ( V_65 , 2 , L_203 , V_2 -> V_12 . V_19 ) ;
}
V_2 -> V_66 . V_468 . V_469 =
V_130 -> V_117 . V_465 . V_117 . V_466 . V_470 ;
return F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
}
static struct V_112 * F_273 ( struct V_1 * V_2 ,
T_1 V_134 , T_1 V_471 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
V_113 = F_265 ( V_2 , V_472 ,
V_393 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_465 . V_133 . V_473 = V_471 ;
V_130 -> V_117 . V_465 . V_133 . V_474 = V_134 ;
V_130 -> V_117 . V_465 . V_133 . V_475 = 1 ;
V_130 -> V_117 . V_465 . V_133 . V_476 = 1 ;
}
return V_113 ;
}
int F_274 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 3 , L_204 ) ;
V_113 = F_273 ( V_2 , V_477 ,
sizeof( struct V_478 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_269 ( V_2 , V_113 , F_272 , NULL ) ;
return V_37 ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_205 ) ;
V_130 = (struct V_129 * ) V_117 ;
switch ( V_130 -> V_133 . V_139 ) {
case V_479 :
case V_480 :
F_41 ( V_65 , 2 , L_206 ) ;
V_2 -> V_66 . V_481 . V_469 |= V_482 ;
V_2 -> V_66 . V_483 . V_469 |= V_482 ;
return - 0 ;
default:
if ( V_130 -> V_133 . V_139 ) {
F_68 ( 1 , L_207
L_208 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ,
V_130 -> V_133 . V_139 ) ;
return 0 ;
}
}
if ( V_130 -> V_133 . V_392 == V_393 ) {
V_2 -> V_66 . V_481 . V_469 = V_130 -> V_133 . V_459 ;
V_2 -> V_66 . V_481 . V_484 = V_130 -> V_133 . V_460 ;
} else if ( V_130 -> V_133 . V_392 == V_485 ) {
V_2 -> V_66 . V_483 . V_469 = V_130 -> V_133 . V_459 ;
V_2 -> V_66 . V_483 . V_484 = V_130 -> V_133 . V_460 ;
} else
F_68 ( 1 , L_209
L_210 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
return 0 ;
}
int F_276 ( struct V_1 * V_2 , enum V_451 V_452 )
{
int V_37 ;
struct V_112 * V_113 ;
F_45 ( V_65 , 2 , L_211 , V_452 ) ;
V_113 = F_265 ( V_2 , V_486 , V_452 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_269 ( V_2 , V_113 , F_275 , NULL ) ;
return V_37 ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_487 * V_488 ;
struct V_489 * V_490 ;
F_4 ( V_2 , 2 , L_212 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_488 = (struct V_487 * ) V_125 -> V_386 ;
if ( V_130 -> V_117 . V_465 . V_133 . V_139 == 0 ) {
V_490 = & V_130 -> V_117 . V_465 . V_117 . V_491 ;
V_488 -> V_492 = V_490 -> V_492 ;
V_488 -> V_493 = V_490 -> V_493 ;
F_52 ( V_2 , 2 , L_213 , V_488 -> V_492 ,
V_488 -> V_493 ) ;
}
F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int V_489 ( struct V_1 * V_2 ,
struct V_487 * V_488 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_214 ) ;
if ( ! F_278 ( V_2 , V_494 ) )
return - V_340 ;
if ( ! F_87 ( V_2 -> V_9 ) )
return - V_495 ;
V_113 = F_273 ( V_2 , V_494 ,
sizeof( struct V_496 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_269 ( V_2 , V_113 ,
F_277 , V_488 ) ;
}
static int F_279 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_215 , V_37 ) ;
else
V_2 -> V_12 . V_497 = V_130 -> V_117 . V_498 . V_499 ;
return 0 ;
}
static int F_280 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_216 ) ;
V_113 = F_265 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_498 . V_500 = 16 ;
V_130 -> V_117 . V_498 . V_501 = V_502 ;
return F_269 ( V_2 , V_113 , F_279 , NULL ) ;
}
static void F_281 ( struct V_1 * V_2 , struct V_503 * V_504 )
{
unsigned long V_12 = F_282 ( V_49 ) ;
struct V_505 * V_506 = (struct V_505 * ) V_12 ;
struct V_507 * V_508 = (struct V_507 * ) V_12 ;
struct V_363 V_509 ;
int V_373 ;
V_504 -> V_142 = V_2 -> V_12 . V_142 ;
F_178 ( F_152 ( V_2 ) , & V_509 ) ;
V_504 -> V_510 = V_509 . V_510 ;
V_504 -> V_371 = V_509 . V_371 ;
if ( ! V_12 )
return;
V_373 = F_283 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_373 >= 2 ) && ( F_283 ( V_506 , 2 , 2 , 2 ) == 0 ) )
V_504 -> V_511 = V_506 -> V_512 ;
if ( ( V_373 >= 3 ) && ( F_283 ( V_508 , 3 , 2 , 2 ) == 0 ) ) {
F_284 ( V_508 -> V_513 [ 0 ] . V_514 , sizeof( V_508 -> V_513 [ 0 ] . V_514 ) ) ;
memcpy ( V_504 -> V_515 , V_508 -> V_513 [ 0 ] . V_514 , sizeof( V_504 -> V_515 ) ) ;
}
F_31 ( V_12 ) ;
return;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
V_185 V_37 ;
V_130 = (struct V_129 * ) V_117 ;
V_37 = V_130 -> V_133 . V_139 ;
if ( V_37 )
F_52 ( V_2 , 2 , L_217 , V_37 ) ;
return 0 ;
}
int F_286 ( struct V_1 * V_2 , enum V_516 V_517 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_41 ( V_65 , 2 , L_218 ) ;
V_113 = F_265 ( V_2 , V_138 , 0 ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_498 . V_500 = 80 ;
V_130 -> V_117 . V_498 . V_501 = V_518 ;
V_130 -> V_117 . V_498 . type = 1 ;
V_130 -> V_117 . V_498 . V_517 = V_517 ;
switch ( V_517 ) {
case V_519 :
V_130 -> V_117 . V_498 . V_66 = 0x0003 ;
V_130 -> V_117 . V_498 . V_499 = 0x00010000 +
sizeof( struct V_503 ) ;
F_281 ( V_2 ,
(struct V_503 * ) V_130 -> V_117 . V_498 . V_520 ) ;
break;
case V_521 :
V_130 -> V_117 . V_498 . V_66 = 0x0001 ;
break;
case V_522 :
break;
}
return F_269 ( V_2 , V_113 , F_285 , NULL ) ;
}
int F_287 ( struct V_1 * V_2 , struct V_523 * V_231 ,
unsigned int V_524 , const char * V_525 )
{
if ( V_524 ) {
F_4 ( V_2 , 2 , V_525 ) ;
F_52 ( V_2 , 2 , L_219 ,
V_231 -> V_245 [ 15 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_220 ,
V_231 -> V_245 [ 14 ] . V_246 ) ;
F_52 ( V_2 , 2 , L_221 , V_524 ) ;
if ( ( V_231 -> V_245 [ 15 ] . V_246 ) == 0x12 ) {
V_2 -> V_526 . V_527 ++ ;
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
F_52 ( V_2 , 2 , L_222 , V_2 -> V_528 ) ;
F_288 ( V_2 , V_2 -> V_528 ) ;
}
void F_288 ( struct V_1 * V_2 , int V_169 )
{
struct V_59 * V_111 = V_2 -> V_46 . V_423 ;
struct V_303 * V_529 ;
int V_167 ;
int V_44 ;
int V_37 ;
int V_530 = 0 ;
V_167 = ( V_169 < V_111 -> V_70 ) ?
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 - V_169 ) :
V_2 -> V_46 . V_58 . V_48 -
( V_111 -> V_70 + V_62 - V_169 ) ;
if ( V_167 >= F_289 ( V_2 ) ) {
for ( V_44 = V_111 -> V_70 ;
V_44 < V_111 -> V_70 + V_167 ; ++ V_44 ) {
if ( F_260 ( V_2 ,
& V_111 -> V_63 [ V_44 % V_62 ] ) ) {
break;
} else {
V_530 ++ ;
}
}
if ( V_530 < V_167 ) {
F_60 ( & V_2 -> V_531 , 3 ) ;
V_167 = V_530 ;
} else {
F_290 ( & V_2 -> V_531 , - 1 , 0 ) ;
}
if ( ! V_167 ) {
V_44 = 0 ;
F_254 (lh, &card->qdio.in_buf_pool.entry_list)
V_44 ++ ;
if ( V_44 == V_2 -> V_46 . V_58 . V_48 ) {
F_4 ( V_2 , 2 , L_223 ) ;
V_2 -> V_528 = V_169 ;
F_291 (
& V_2 -> V_295 ,
V_532 ) ;
}
return;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_440 . V_533 ++ ;
V_2 -> V_440 . V_534 =
F_292 () ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , 0 ,
V_111 -> V_70 , V_167 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_440 . V_535 +=
F_292 () -
V_2 -> V_440 . V_534 ;
if ( V_37 ) {
F_4 ( V_2 , 2 , L_224 ) ;
}
V_111 -> V_70 = ( V_111 -> V_70 + V_167 ) %
V_62 ;
}
}
static int F_293 ( struct V_1 * V_2 ,
struct V_96 * V_64 , unsigned int V_536 )
{
int V_83 = V_64 -> V_64 -> V_245 [ 15 ] . V_246 ;
F_4 ( V_2 , 6 , L_225 ) ;
if ( V_2 -> V_12 . type == V_15 ) {
if ( V_83 == 0 ) {
V_536 = 0 ;
} else {
V_536 = 1 ;
}
}
F_287 ( V_2 , V_64 -> V_64 , V_536 , L_226 ) ;
if ( ! V_536 )
return V_537 ;
if ( ( V_83 >= 15 ) && ( V_83 <= 31 ) )
return V_538 ;
F_4 ( V_2 , 1 , L_227 ) ;
F_52 ( V_2 , 1 , L_228 ,
( V_186 ) V_536 , ( V_279 ) V_83 ) ;
return V_539 ;
}
static void F_294 ( struct V_92 * V_111 )
{
if ( ! V_111 -> V_447 ) {
if ( F_51 ( & V_111 -> V_448 )
>= V_540 ) {
F_4 ( V_111 -> V_2 , 6 , L_229 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_440 . V_541 ++ ;
V_111 -> V_447 = 1 ;
}
}
}
static int F_295 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
int V_542 = 0 ;
if ( V_111 -> V_447 ) {
if ( F_51 ( & V_111 -> V_448 )
<= V_543 ) {
F_4 ( V_111 -> V_2 , 6 , L_230 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_440 . V_544 ++ ;
V_111 -> V_447 = 0 ;
V_64 = V_111 -> V_63 [ V_111 -> V_446 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) ==
V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 ,
V_107 ) ;
V_542 ++ ;
V_111 -> V_446 =
( V_111 -> V_446 + 1 ) %
V_62 ;
}
}
}
return V_542 ;
}
static int F_296 ( struct V_92 * V_111 )
{
struct V_96 * V_64 ;
V_64 = V_111 -> V_63 [ V_111 -> V_446 ] ;
if ( ( F_51 ( & V_64 -> V_3 ) == V_249 ) &&
( V_64 -> V_255 > 0 ) ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_111 -> V_446 =
( V_111 -> V_446 + 1 ) % V_62 ;
return 1 ;
}
return 0 ;
}
static void F_297 ( struct V_92 * V_111 , int V_169 ,
int V_167 )
{
struct V_96 * V_231 ;
int V_37 ;
int V_44 ;
unsigned int V_545 ;
for ( V_44 = V_169 ; V_44 < V_169 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_231 = V_111 -> V_63 [ V_93 ] ;
V_231 -> V_64 -> V_245 [ V_231 -> V_255 - 1 ] . V_254 |=
V_445 ;
if ( V_111 -> V_81 )
V_111 -> V_81 [ V_93 ] . V_422 = V_231 ;
if ( V_111 -> V_2 -> V_12 . type == V_15 )
continue;
if ( ! V_111 -> V_447 ) {
if ( ( F_51 ( & V_111 -> V_448 ) >=
( V_540 -
V_546 ) ) &&
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
V_111 -> V_2 -> V_9 -> V_547 = V_389 ;
if ( V_111 -> V_2 -> V_66 . V_273 ) {
V_111 -> V_2 -> V_440 . V_548 ++ ;
V_111 -> V_2 -> V_440 . V_549 =
F_292 () ;
}
V_545 = V_550 ;
if ( F_51 ( & V_111 -> V_248 ) )
V_545 |= V_551 ;
V_37 = F_43 ( F_44 ( V_111 -> V_2 ) , V_545 ,
V_111 -> V_428 , V_169 , V_167 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_440 . V_552 +=
F_292 () -
V_111 -> V_2 -> V_440 . V_549 ;
F_298 ( V_167 , & V_111 -> V_448 ) ;
if ( V_37 ) {
V_111 -> V_2 -> V_526 . V_553 += V_167 ;
if ( V_37 == - V_554 )
return;
F_4 ( V_111 -> V_2 , 2 , L_231 ) ;
F_52 ( V_111 -> V_2 , 2 , L_232 , V_111 -> V_428 ) ;
F_52 ( V_111 -> V_2 , 2 , L_233 , V_169 ) ;
F_52 ( V_111 -> V_2 , 2 , L_234 , V_167 ) ;
F_52 ( V_111 -> V_2 , 2 , L_165 , V_37 ) ;
F_72 ( V_111 -> V_2 ) ;
return;
}
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_440 . V_555 += V_167 ;
}
static void F_299 ( struct V_92 * V_111 )
{
int V_169 ;
int V_556 = 0 ;
int V_557 = 0 ;
if ( ( F_51 ( & V_111 -> V_448 ) <= V_543 ) ||
! F_51 ( & V_111 -> V_248 ) ) {
if ( F_233 ( & V_111 -> V_3 , V_558 ) ==
V_449 ) {
F_300 ( V_111 -> V_2 -> V_9 ) ;
V_169 = V_111 -> V_446 ;
V_557 = V_111 -> V_447 ;
F_301 () ;
V_556 += F_295 ( V_111 ) ;
if ( ! V_556 &&
! F_51 ( & V_111 -> V_248 ) )
V_556 +=
F_296 ( V_111 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 &&
V_557 )
V_111 -> V_2 -> V_440 . V_559 +=
V_556 ;
if ( V_556 )
F_297 ( V_111 , V_169 , V_556 ) ;
F_60 ( & V_111 -> V_3 , V_449 ) ;
}
}
}
void F_302 ( struct V_158 * V_119 , int V_111 ,
unsigned long V_560 )
{
struct V_1 * V_2 = (struct V_1 * ) V_560 ;
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_32 & V_561 ) )
F_303 ( & V_2 -> V_562 ) ;
}
int F_304 ( struct V_1 * V_2 , enum V_563 V_67 )
{
int V_37 ;
if ( V_2 -> V_66 . V_67 == V_564 ) {
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
static void F_305 ( struct V_1 * V_2 ,
unsigned int V_536 ,
unsigned int V_111 , int V_565 , int V_167 ) {
struct V_59 * V_67 = V_2 -> V_46 . V_69 ;
int V_44 ;
int V_37 ;
if ( ! F_64 ( V_2 , V_111 ) )
goto V_73;
F_52 ( V_2 , 5 , L_235 , V_565 ) ;
F_52 ( V_2 , 5 , L_236 , V_167 ) ;
F_52 ( V_2 , 5 , L_237 , V_536 ) ;
if ( V_536 ) {
F_300 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
goto V_73;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_440 . V_566 ++ ;
V_2 -> V_440 . V_567 = F_292 () ;
}
for ( V_44 = V_565 ; V_44 < V_565 + V_167 ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
struct V_523 * V_64 = V_67 -> V_61 [ V_93 ] ;
int V_568 ;
V_568 = 0 ;
while ( V_64 -> V_245 [ V_568 ] . V_250 ) {
unsigned long V_103 ;
V_103 = ( unsigned long ) V_64 -> V_245 [ V_568 ] . V_250 ;
F_57 ( V_2 , V_103 ) ;
V_64 -> V_245 [ V_568 ] . V_250 = NULL ;
V_64 -> V_245 [ V_568 ] . V_254 = 0 ;
V_64 -> V_245 [ V_568 ] . V_246 = 0 ;
V_64 -> V_245 [ V_568 ] . V_253 = 0 ;
++ V_568 ;
}
V_64 -> V_245 [ 15 ] . V_254 = 0 ;
V_64 -> V_245 [ 15 ] . V_246 = 0 ;
}
V_37 = F_43 ( F_44 ( V_2 ) , V_71 , V_111 ,
V_2 -> V_46 . V_69 -> V_70 ,
V_167 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 ,
L_238 , V_37 ) ;
F_4 ( V_2 , 2 , L_239 ) ;
}
V_2 -> V_46 . V_69 -> V_70 = ( V_2 -> V_46 . V_69 -> V_70
+ V_167 ) % V_62 ;
F_306 ( V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_273 ) {
int V_569 = F_292 () ;
V_569 -= V_2 -> V_440 . V_567 ;
V_2 -> V_440 . V_570 += V_569 ;
}
V_73:
return;
}
void F_307 ( struct V_158 * V_119 , unsigned int V_536 ,
unsigned int V_111 , int V_571 , int V_167 ,
unsigned long V_560 )
{
struct V_1 * V_2 = (struct V_1 * ) V_560 ;
F_52 ( V_2 , 2 , L_240 , V_111 ) ;
F_52 ( V_2 , 2 , L_241 , V_536 ) ;
if ( F_64 ( V_2 , V_111 ) )
F_305 ( V_2 , V_536 , V_111 , V_571 , V_167 ) ;
else if ( V_536 )
F_72 ( V_2 ) ;
}
void F_308 ( struct V_158 * V_119 ,
unsigned int V_524 , int V_572 , int V_565 ,
int V_167 , unsigned long V_560 )
{
struct V_1 * V_2 = (struct V_1 * ) V_560 ;
struct V_92 * V_111 = V_2 -> V_46 . V_80 [ V_572 ] ;
struct V_96 * V_64 ;
int V_44 ;
F_4 ( V_2 , 6 , L_242 ) ;
if ( V_524 & V_573 ) {
F_4 ( V_2 , 2 , L_243 ) ;
F_300 ( V_2 -> V_9 ) ;
F_72 ( V_2 ) ;
return;
}
if ( V_2 -> V_66 . V_273 ) {
V_2 -> V_440 . V_574 ++ ;
V_2 -> V_440 . V_575 =
F_292 () ;
}
for ( V_44 = V_565 ; V_44 < ( V_565 + V_167 ) ; ++ V_44 ) {
int V_93 = V_44 % V_62 ;
V_64 = V_111 -> V_63 [ V_93 ] ;
F_293 ( V_2 , V_64 , V_524 ) ;
if ( V_111 -> V_81 &&
( V_111 -> V_81 [ V_93 ] . V_32 &
V_576 ) != 0 ) {
F_54 ( V_2 -> V_66 . V_67 != V_68 ) ;
if ( F_59 ( & V_64 -> V_3 ,
V_107 ,
V_109 ) ==
V_107 ) {
F_61 ( V_111 , V_64 ,
V_577 ) ;
}
V_64 -> V_102 = V_111 -> V_81 [ V_93 ] . V_102 ;
F_52 ( V_111 -> V_2 , 5 , L_244 , V_93 ) ;
F_4 ( V_111 -> V_2 , 5 , L_245 ) ;
F_52 ( V_111 -> V_2 , 5 , L_43 ,
F_309 ( V_64 -> V_102 ) ) ;
if ( F_56 ( V_111 , V_93 ) ) {
F_4 ( V_2 , 2 , L_246 ) ;
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
F_310 ( V_167 , & V_111 -> V_448 ) ;
if ( V_2 -> V_12 . type != V_15 )
F_299 ( V_111 ) ;
F_306 ( V_111 -> V_2 -> V_9 ) ;
if ( V_2 -> V_66 . V_273 )
V_2 -> V_440 . V_578 += F_292 () -
V_2 -> V_440 . V_575 ;
}
int F_311 ( struct V_1 * V_2 , struct V_232 * V_233 ,
int V_579 , int V_580 )
{
T_3 * V_581 ;
V_279 V_582 ;
if ( V_580 && V_2 -> V_12 . V_319 )
return V_2 -> V_12 . V_319 &
( V_2 -> V_46 . V_78 - 1 ) ;
switch ( V_2 -> V_46 . V_309 ) {
case V_583 :
case V_584 :
switch ( V_579 ) {
case 4 :
V_582 = F_312 ( F_313 ( V_233 ) ) ;
break;
case 6 :
V_582 = F_314 ( F_315 ( V_233 ) ) ;
break;
default:
return V_2 -> V_46 . V_257 ;
}
if ( V_2 -> V_46 . V_309 == V_584 )
return ~ V_582 >> 6 & 3 ;
if ( V_582 & V_585 )
return 3 ;
if ( V_582 & V_586 )
return 2 ;
if ( V_582 & V_587 )
return 1 ;
if ( V_582 & V_588 )
return 0 ;
break;
case V_589 :
if ( V_233 -> V_590 > 5 )
return 0 ;
return ~ V_233 -> V_590 >> 1 & 3 ;
case V_591 :
V_581 = & ( (struct V_592 * ) V_233 -> V_117 ) -> V_593 ;
if ( * V_581 == V_594 )
return ~ * ( V_581 + 1 ) >> ( V_595 + 1 ) & 3 ;
break;
default:
break;
}
return V_2 -> V_46 . V_257 ;
}
int F_316 ( struct V_232 * V_233 )
{
int V_177 , V_253 , V_568 , V_51 = 0 ;
struct V_596 * V_597 ;
char * V_117 ;
for ( V_177 = 0 ; V_177 < F_317 ( V_233 ) -> V_598 ; V_177 ++ ) {
V_597 = & F_317 ( V_233 ) -> V_599 [ V_177 ] ;
V_117 = ( char * ) F_318 ( F_319 ( V_597 ) ) +
V_597 -> V_600 ;
V_253 = V_597 -> V_601 ;
V_568 = F_320 ( ( unsigned long ) V_117 + V_253 - 1 ) -
F_321 ( ( unsigned long ) V_117 ) ;
V_51 += V_568 ;
}
return V_51 ;
}
int F_322 ( struct V_1 * V_2 ,
struct V_232 * V_233 , int V_602 )
{
int V_603 = V_233 -> V_163 - V_233 -> V_604 ;
int V_605 = F_320 ( ( unsigned long ) V_233 -> V_117 + V_603 - 1 ) -
F_321 ( ( unsigned long ) V_233 -> V_117 ) ;
V_605 += F_316 ( V_233 ) ;
if ( ( V_605 + V_602 ) > F_29 ( V_2 ) ) {
F_68 ( 2 , L_247
L_248 ,
( V_605 + V_602 ) , V_233 -> V_163 ) ;
return 0 ;
}
return V_605 ;
}
int F_323 ( struct V_232 * V_233 , struct V_606 * * V_133 , int V_163 )
{
int V_607 , V_608 , V_609 ;
if ( ( ( unsigned long ) V_233 -> V_117 & V_610 ) !=
( ( ( unsigned long ) V_233 -> V_117 + V_163 - 1 ) & V_610 ) ) {
V_607 = F_324 ( V_233 ) ;
V_608 = V_407 - ( ( unsigned long ) V_233 -> V_117 % V_407 ) ;
V_609 = V_163 - V_608 ;
if ( V_609 > V_607 )
return 1 ;
memmove ( V_233 -> V_117 - V_609 , V_233 -> V_117 , V_233 -> V_163 - V_233 -> V_604 ) ;
V_233 -> V_117 -= V_609 ;
V_233 -> V_611 -= V_609 ;
* V_133 = (struct V_606 * ) V_233 -> V_117 ;
F_68 ( 2 , L_249 , V_163 , V_609 ) ;
}
return 0 ;
}
static inline void F_325 ( struct V_232 * V_233 ,
struct V_523 * V_64 , int V_612 , int * V_255 ,
int V_184 )
{
int V_253 = V_233 -> V_163 - V_233 -> V_604 ;
int V_613 ;
int V_245 ;
char * V_117 ;
int V_614 , V_177 ;
struct V_596 * V_597 ;
V_245 = * V_255 ;
V_117 = V_233 -> V_117 ;
V_614 = ( V_612 == 0 ? 1 : 0 ) ;
if ( V_184 >= 0 ) {
V_117 = V_233 -> V_117 + V_184 ;
V_253 -= V_184 ;
V_614 = 0 ;
}
while ( V_253 > 0 ) {
V_613 = V_407 - ( ( unsigned long ) V_117 % V_407 ) ;
if ( V_253 < V_613 )
V_613 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_613 ;
V_253 -= V_613 ;
if ( ! V_253 ) {
if ( V_614 )
if ( F_317 ( V_233 ) -> V_598 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_615 ;
else
V_64 -> V_245 [ V_245 ] . V_254 = 0 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_616 ;
} else {
if ( V_614 )
V_64 -> V_245 [ V_245 ] . V_254 =
V_615 ;
else
V_64 -> V_245 [ V_245 ] . V_254 =
V_616 ;
}
V_117 += V_613 ;
V_245 ++ ;
V_614 = 0 ;
}
for ( V_177 = 0 ; V_177 < F_317 ( V_233 ) -> V_598 ; V_177 ++ ) {
V_597 = & F_317 ( V_233 ) -> V_599 [ V_177 ] ;
V_117 = ( char * ) F_318 ( F_319 ( V_597 ) ) +
V_597 -> V_600 ;
V_253 = V_597 -> V_601 ;
while ( V_253 > 0 ) {
V_613 = V_407 -
( ( unsigned long ) V_117 % V_407 ) ;
if ( V_253 < V_613 )
V_613 = V_253 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_613 ;
V_64 -> V_245 [ V_245 ] . V_254 =
V_616 ;
V_253 -= V_613 ;
V_117 += V_613 ;
V_245 ++ ;
}
}
if ( V_64 -> V_245 [ V_245 - 1 ] . V_254 )
V_64 -> V_245 [ V_245 - 1 ] . V_254 = V_617 ;
* V_255 = V_245 ;
}
static inline int F_326 ( struct V_92 * V_111 ,
struct V_96 * V_231 , struct V_232 * V_233 ,
struct V_606 * V_133 , int V_184 , int V_618 )
{
struct V_523 * V_64 ;
int V_556 = 0 , V_619 , V_620 = 0 ;
V_64 = V_231 -> V_64 ;
F_76 ( & V_233 -> V_242 ) ;
F_327 ( & V_231 -> V_234 , V_233 ) ;
if ( V_133 -> V_133 . V_621 . V_314 == V_622 ) {
int V_245 = V_231 -> V_255 ;
V_619 = sizeof( struct V_623 ) +
( (struct V_623 * ) V_133 ) -> V_499 . V_624 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_233 -> V_117 ;
V_64 -> V_245 [ V_245 ] . V_253 = V_619 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_615 ;
V_231 -> V_255 ++ ;
V_233 -> V_117 += V_619 ;
V_233 -> V_163 -= V_619 ;
V_620 = 1 ;
}
if ( V_184 >= 0 ) {
int V_245 = V_231 -> V_255 ;
V_64 -> V_245 [ V_245 ] . V_250 = V_133 ;
V_64 -> V_245 [ V_245 ] . V_253 = sizeof( struct V_606 ) +
V_618 ;
V_64 -> V_245 [ V_245 ] . V_254 = V_615 ;
V_231 -> V_251 [ V_245 ] = 1 ;
V_231 -> V_255 ++ ;
}
F_325 ( V_233 , V_64 , V_620 ,
( int * ) & V_231 -> V_255 , V_184 ) ;
if ( ! V_111 -> V_447 ) {
F_4 ( V_111 -> V_2 , 6 , L_250 ) ;
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_556 = 1 ;
} else {
F_4 ( V_111 -> V_2 , 6 , L_251 ) ;
if ( V_111 -> V_2 -> V_66 . V_273 )
V_111 -> V_2 -> V_440 . V_625 ++ ;
if ( V_231 -> V_255 >=
F_29 ( V_111 -> V_2 ) ) {
F_60 ( & V_231 -> V_3 , V_107 ) ;
V_556 = 1 ;
}
}
return V_556 ;
}
int F_328 ( struct V_1 * V_2 ,
struct V_92 * V_111 , struct V_232 * V_233 ,
struct V_606 * V_133 , int V_605 ,
int V_184 , int V_618 )
{
struct V_96 * V_64 ;
int V_169 ;
while ( F_59 ( & V_111 -> V_3 , V_449 ,
V_626 ) != V_449 ) ;
V_169 = V_111 -> V_446 ;
V_64 = V_111 -> V_63 [ V_111 -> V_446 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 )
goto V_73;
V_111 -> V_446 = ( V_111 -> V_446 + 1 ) %
V_62 ;
F_60 ( & V_111 -> V_3 , V_449 ) ;
F_326 ( V_111 , V_64 , V_233 , V_133 , V_184 , V_618 ) ;
F_297 ( V_111 , V_169 , 1 ) ;
return 0 ;
V_73:
F_60 ( & V_111 -> V_3 , V_449 ) ;
return - V_627 ;
}
int F_329 ( struct V_1 * V_2 , struct V_92 * V_111 ,
struct V_232 * V_233 , struct V_606 * V_133 ,
int V_605 )
{
struct V_96 * V_64 ;
int V_628 ;
int V_542 = 0 ;
int V_447 = 0 ;
int V_41 ;
int V_37 = 0 ;
while ( F_59 ( & V_111 -> V_3 , V_449 ,
V_626 ) != V_449 ) ;
V_628 = V_111 -> V_446 ;
V_64 = V_111 -> V_63 [ V_111 -> V_446 ] ;
if ( F_51 ( & V_64 -> V_3 ) != V_249 ) {
F_60 ( & V_111 -> V_3 , V_449 ) ;
return - V_627 ;
}
F_294 ( V_111 ) ;
if ( V_111 -> V_447 ) {
V_447 = 1 ;
if ( ( F_29 ( V_2 ) -
V_64 -> V_255 ) < V_605 ) {
F_60 ( & V_64 -> V_3 , V_107 ) ;
V_542 ++ ;
V_111 -> V_446 =
( V_111 -> V_446 + 1 ) %
V_62 ;
V_64 = V_111 -> V_63 [ V_111 -> V_446 ] ;
if ( F_51 ( & V_64 -> V_3 ) !=
V_249 ) {
F_297 ( V_111 , V_628 ,
V_542 ) ;
F_60 ( & V_111 -> V_3 ,
V_449 ) ;
return - V_627 ;
}
}
}
V_41 = F_326 ( V_111 , V_64 , V_233 , V_133 , - 1 , 0 ) ;
V_111 -> V_446 = ( V_111 -> V_446 + V_41 ) %
V_62 ;
V_542 += V_41 ;
if ( V_542 )
F_297 ( V_111 , V_628 , V_542 ) ;
else if ( ! F_51 ( & V_111 -> V_248 ) )
F_233 ( & V_111 -> V_3 , V_558 ) ;
while ( F_330 ( & V_111 -> V_3 ) ) {
V_542 = 0 ;
V_628 = V_111 -> V_446 ;
V_542 += F_295 ( V_111 ) ;
if ( ! V_542 && ! F_51 ( & V_111 -> V_248 ) )
V_542 += F_296 ( V_111 ) ;
if ( V_542 )
F_297 ( V_111 , V_628 , V_542 ) ;
}
if ( V_111 -> V_2 -> V_66 . V_273 && V_447 )
V_111 -> V_2 -> V_440 . V_559 += V_542 ;
return V_37 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_478 * V_629 ;
F_4 ( V_2 , 4 , L_252 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_629 = & ( V_130 -> V_117 . V_465 ) ;
F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_253 , V_130 -> V_133 . V_139 ) ;
V_629 -> V_117 . V_630 = V_631 ;
}
V_2 -> V_12 . V_632 = V_629 -> V_117 . V_630 ;
return 0 ;
}
void F_332 ( struct V_1 * V_2 )
{
enum V_633 V_630 ;
struct V_634 * V_9 = V_2 -> V_9 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_254 ) ;
if ( ( ( V_9 -> V_32 & V_635 ) &&
( V_2 -> V_12 . V_632 == V_636 ) ) ||
( ! ( V_9 -> V_32 & V_635 ) &&
( V_2 -> V_12 . V_632 == V_631 ) ) )
return;
V_630 = V_631 ;
if ( V_9 -> V_32 & V_635 )
V_630 = V_636 ;
F_52 ( V_2 , 4 , L_255 , V_630 ) ;
V_113 = F_273 ( V_2 , V_637 ,
sizeof( struct V_496 ) + 8 ) ;
if ( ! V_113 )
return;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_465 . V_117 . V_630 = V_630 ;
F_269 ( V_2 , V_113 , F_331 , NULL ) ;
}
int F_333 ( struct V_634 * V_9 , int V_638 )
{
struct V_1 * V_2 ;
char V_639 [ 15 ] ;
V_2 = V_9 -> V_640 ;
F_4 ( V_2 , 4 , L_256 ) ;
sprintf ( V_639 , L_257 , V_638 ) ;
F_4 ( V_2 , 4 , V_639 ) ;
if ( V_638 < 64 )
return - V_405 ;
if ( V_638 > 65535 )
return - V_405 ;
if ( ( ! F_334 ( V_2 , V_641 ) ) &&
( ! F_207 ( V_2 , V_638 ) ) )
return - V_405 ;
V_9 -> V_403 = V_638 ;
return 0 ;
}
struct V_642 * F_335 ( struct V_634 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_640 ;
F_4 ( V_2 , 5 , L_258 ) ;
return & V_2 -> V_526 ;
}
static int F_336 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_259 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( ! V_2 -> V_66 . V_307 ||
! ( V_2 -> V_12 . V_643 & V_644 ) ) {
memcpy ( V_2 -> V_9 -> V_645 ,
& V_130 -> V_117 . V_465 . V_117 . V_646 . V_250 ,
V_647 ) ;
V_2 -> V_12 . V_643 |= V_644 ;
}
F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
int F_337 ( struct V_1 * V_2 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_260 ) ;
V_113 = F_273 ( V_2 , V_648 ,
sizeof( struct V_496 ) +
sizeof( struct V_649 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_465 . V_117 . V_646 . V_130 = V_650 ;
V_130 -> V_117 . V_465 . V_117 . V_646 . V_651 = V_647 ;
memcpy ( & V_130 -> V_117 . V_465 . V_117 . V_646 . V_250 ,
V_2 -> V_9 -> V_645 , V_647 ) ;
V_37 = F_269 ( V_2 , V_113 , F_336 ,
NULL ) ;
return V_37 ;
}
static int F_338 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_652 * V_653 ;
int V_654 = * ( int * ) V_125 -> V_386 ;
F_4 ( V_2 , 4 , L_261 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_653 = & V_130 -> V_117 . V_465 . V_117 . V_655 ;
F_45 ( V_65 , 2 , L_261 ) ;
F_45 ( V_65 , 2 , L_262 , V_2 -> V_10 -> V_9 . V_656 . V_514 ) ;
F_45 ( V_65 , 2 , L_263 ,
V_130 -> V_117 . V_465 . V_133 . V_139 ) ;
if ( V_130 -> V_117 . V_465 . V_133 . V_139 !=
V_657 )
F_68 ( 3 , L_264 ,
V_2 -> V_10 -> V_9 . V_656 . V_514 ,
V_653 -> V_658 ,
V_130 -> V_117 . V_465 . V_133 . V_139 ) ;
switch ( V_130 -> V_117 . V_465 . V_133 . V_139 ) {
case V_657 :
if ( V_2 -> V_66 . V_276 == V_277 ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_265 ) ;
} else {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_266 ) ;
}
break;
case V_659 :
F_68 ( 2 , L_267
L_268 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_661 :
F_68 ( 2 , L_269
L_270 , F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_662 :
F_47 ( & V_2 -> V_10 -> V_9 , L_271
L_272 ) ;
break;
case V_663 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_273
L_274 ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_664 :
F_47 ( & V_2 -> V_10 -> V_9 ,
L_275 ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_665 :
F_47 ( & V_2 -> V_10 -> V_9 , L_276
L_277 ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_666 :
F_47 ( & V_2 -> V_10 -> V_9 , L_278
L_279 ) ;
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
case V_667 :
F_67 ( & V_2 -> V_10 -> V_9 , L_280
L_281 ) ;
break;
default:
if ( V_654 )
V_2 -> V_66 . V_276 = V_2 -> V_66 . V_660 ;
break;
}
F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int F_339 ( struct V_1 * V_2 ,
enum V_668 V_276 , int V_654 )
{
int V_37 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_652 * V_653 ;
F_4 ( V_2 , 4 , L_282 ) ;
F_45 ( V_65 , 2 , L_282 ) ;
F_45 ( V_65 , 2 , L_262 , V_2 -> V_10 -> V_9 . V_656 . V_514 ) ;
V_113 = F_273 ( V_2 , V_669 ,
sizeof( struct V_496 ) +
sizeof( struct V_652 ) ) ;
if ( ! V_113 )
return - V_50 ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_653 = & V_130 -> V_117 . V_465 . V_117 . V_655 ;
V_653 -> V_658 = V_276 ;
V_37 = F_269 ( V_2 , V_113 , F_338 ,
& V_654 ) ;
F_45 ( V_65 , 2 , L_263 , V_37 ) ;
return V_37 ;
}
int F_340 ( struct V_1 * V_2 , int V_654 )
{
int V_37 = 0 ;
F_4 ( V_2 , 4 , L_283 ) ;
if ( ( V_2 -> V_12 . type == V_14 ||
V_2 -> V_12 . type == V_17 ) &&
F_278 ( V_2 , V_669 ) ) {
V_37 = F_339 ( V_2 ,
V_2 -> V_66 . V_276 , V_654 ) ;
if ( V_37 ) {
F_68 ( 3 ,
L_284 ,
V_2 -> V_10 -> V_9 . V_656 . V_514 ,
V_37 ) ;
V_37 = - V_340 ;
}
} else if ( V_2 -> V_66 . V_276 != V_277 ) {
V_2 -> V_66 . V_276 = V_277 ;
F_47 ( & V_2 -> V_10 -> V_9 , L_271
L_272 ) ;
V_37 = - V_340 ;
}
return V_37 ;
}
void F_341 ( struct V_634 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_640 ;
F_4 ( V_2 , 4 , L_285 ) ;
V_2 -> V_526 . V_553 ++ ;
F_72 ( V_2 ) ;
}
int F_342 ( struct V_634 * V_9 , int V_670 , int V_671 )
{
struct V_1 * V_2 = V_9 -> V_640 ;
int V_37 = 0 ;
switch ( V_671 ) {
case V_672 :
V_37 = V_673 ;
if ( ( V_2 -> V_12 . V_19 != V_22 ) &&
( V_2 -> V_12 . V_19 != V_674 ) &&
( V_2 -> V_12 . V_19 != V_23 ) )
V_37 |= V_675 ;
break;
case V_676 :
V_37 = V_677 | V_678 | V_679 |
V_680 | V_681 | V_682 | V_683 |
V_684 ;
break;
case V_685 :
V_37 = ( V_9 -> V_645 [ 0 ] << 16 ) | ( V_9 -> V_645 [ 1 ] << 8 ) |
V_9 -> V_645 [ 2 ] ;
V_37 = ( V_37 >> 5 ) & 0xFFFF ;
break;
case V_686 :
V_37 = ( V_9 -> V_645 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_687 :
V_37 = V_688 ;
break;
case V_689 :
V_37 = V_690 | V_691 | V_692 | V_693 |
V_694 | V_695 ;
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
V_37 = V_2 -> V_526 . V_701 ;
break;
case V_702 :
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
default:
break;
}
return V_37 ;
}
static int F_343 ( struct V_1 * V_2 ,
struct V_112 * V_113 , int V_163 ,
int (* F_190)( struct V_1 * , struct V_124 * ,
unsigned long ) ,
void * V_383 )
{
V_186 V_709 , V_710 ;
F_4 ( V_2 , 4 , L_286 ) ;
memcpy ( V_113 -> V_117 , V_463 , V_390 ) ;
memcpy ( F_268 ( V_113 -> V_117 ) ,
& V_2 -> V_354 . V_415 , V_370 ) ;
V_709 = ( V_711 ) V_390 + V_163 ;
V_710 = ( V_711 ) V_163 ;
memcpy ( F_344 ( V_113 -> V_117 ) , & V_709 , 2 ) ;
memcpy ( F_345 ( V_113 -> V_117 ) , & V_710 , 2 ) ;
memcpy ( F_346 ( V_113 -> V_117 ) , & V_710 , 2 ) ;
memcpy ( F_347 ( V_113 -> V_117 ) , & V_710 , 2 ) ;
return F_189 ( V_2 , V_390 + V_163 , V_113 ,
F_190 , V_383 ) ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_712 )
{
struct V_129 * V_130 ;
struct V_713 * V_714 ;
struct V_715 * V_716 ;
unsigned char * V_117 ;
V_185 V_604 ;
F_4 ( V_2 , 3 , L_287 ) ;
V_130 = (struct V_129 * ) V_712 ;
V_117 = ( unsigned char * ) ( ( char * ) V_130 - V_125 -> V_184 ) ;
V_714 = (struct V_713 * ) V_125 -> V_386 ;
V_716 = & V_130 -> V_117 . V_465 . V_117 . V_716 ;
if ( V_130 -> V_133 . V_139 ) {
F_52 ( V_2 , 4 , L_288 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
if ( V_130 -> V_117 . V_465 . V_133 . V_139 ) {
V_130 -> V_133 . V_139 =
V_130 -> V_117 . V_465 . V_133 . V_139 ;
F_52 ( V_2 , 4 , L_289 , V_130 -> V_133 . V_139 ) ;
return 0 ;
}
V_604 = * ( ( V_185 * ) F_345 ( V_117 ) ) ;
if ( V_130 -> V_117 . V_465 . V_133 . V_476 == 1 )
V_604 -= ( V_185 ) ( ( char * ) & V_716 -> V_117 - ( char * ) V_130 ) ;
else
V_604 -= ( V_185 ) ( ( char * ) & V_716 -> V_717 - ( char * ) V_130 ) ;
if ( ( V_714 -> V_718 - V_714 -> V_719 ) < V_604 ) {
F_52 ( V_2 , 4 , L_290 , - V_50 ) ;
V_130 -> V_133 . V_139 = V_720 ;
return 0 ;
}
F_52 ( V_2 , 4 , L_291 ,
V_130 -> V_117 . V_465 . V_133 . V_475 ) ;
F_52 ( V_2 , 4 , L_292 ,
V_130 -> V_117 . V_465 . V_133 . V_476 ) ;
if ( V_130 -> V_117 . V_465 . V_133 . V_476 == 1 ) {
memcpy ( V_714 -> V_721 + V_714 -> V_719 ,
( char * ) V_716 ,
V_604 + F_349 ( struct V_715 , V_117 ) ) ;
V_714 -> V_719 += F_349 ( struct V_715 , V_117 ) ;
} else {
memcpy ( V_714 -> V_721 + V_714 -> V_719 ,
( char * ) & V_716 -> V_717 , V_604 ) ;
}
V_714 -> V_719 += V_604 ;
F_52 ( V_2 , 4 , L_293 ,
V_130 -> V_117 . V_465 . V_133 . V_475 ) ;
F_52 ( V_2 , 4 , L_294 ,
V_130 -> V_117 . V_465 . V_133 . V_476 ) ;
if ( V_130 -> V_117 . V_465 . V_133 . V_476 <
V_130 -> V_117 . V_465 . V_133 . V_475 )
return 1 ;
return 0 ;
}
int F_350 ( struct V_1 * V_2 , char T_4 * V_721 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_722 * V_723 ;
unsigned int V_724 ;
struct V_713 V_714 = { 0 , } ;
int V_37 = 0 ;
F_4 ( V_2 , 3 , L_295 ) ;
if ( V_2 -> V_12 . V_13 )
return - V_340 ;
if ( ( ! F_278 ( V_2 , V_725 ) ) &&
( ! V_2 -> V_66 . V_307 ) ) {
return - V_340 ;
}
if ( F_351 ( & V_724 , V_721 + sizeof( int ) , sizeof( int ) ) )
return - V_726 ;
if ( V_724 > ( V_118 - V_390 -
sizeof( struct V_727 ) -
sizeof( struct V_496 ) ) )
return - V_405 ;
V_723 = F_352 ( V_721 , V_724 + sizeof( struct V_728 ) ) ;
if ( F_116 ( V_723 ) ) {
F_4 ( V_2 , 2 , L_296 ) ;
return F_117 ( V_723 ) ;
}
V_714 . V_718 = V_723 -> V_133 . V_604 ;
V_714 . V_721 = F_27 ( V_714 . V_718 , V_49 ) ;
if ( ! V_714 . V_721 ) {
F_32 ( V_723 ) ;
return - V_50 ;
}
V_714 . V_719 = sizeof( struct V_728 ) ;
V_113 = F_273 ( V_2 , V_725 ,
V_729 + V_724 ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_73;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
memcpy ( & V_130 -> V_117 . V_465 . V_117 . V_716 , & V_723 -> V_130 , V_724 ) ;
V_37 = F_343 ( V_2 , V_113 , V_730 + V_724 ,
F_348 , ( void * ) & V_714 ) ;
if ( V_37 )
F_68 ( 2 , L_297 ,
F_81 ( V_2 ) , V_37 ) ;
else {
if ( F_353 ( V_721 , V_714 . V_721 , V_714 . V_718 ) )
V_37 = - V_726 ;
}
V_73:
F_32 ( V_723 ) ;
F_32 ( V_714 . V_721 ) ;
return V_37 ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_731 * V_732 ;
char * V_733 ;
int V_734 ;
F_4 ( V_2 , 3 , L_298 ) ;
V_130 = (struct V_129 * ) V_117 ;
V_732 = (struct V_731 * ) V_125 -> V_386 ;
V_734 = V_130 -> V_117 . V_465 . V_133 . V_473 ;
V_733 = ( char * ) V_117 + 28 ;
if ( V_734 > ( V_732 -> V_735 - V_732 -> V_736 ) ) {
V_130 -> V_133 . V_139 = V_737 ;
return 0 ;
}
memcpy ( ( V_732 -> V_64 + V_732 -> V_736 ) , V_733 ,
V_734 ) ;
V_732 -> V_736 += V_734 ;
if ( V_130 -> V_117 . V_465 . V_133 . V_476 <
V_130 -> V_117 . V_465 . V_133 . V_475 )
return 1 ;
return 0 ;
}
int F_355 ( struct V_1 * V_2 , char T_4 * V_721 )
{
int V_37 = 0 ;
struct V_112 * V_113 ;
struct V_129 * V_130 ;
struct V_738 * V_739 ;
struct V_740 V_741 ;
struct V_731 V_732 ;
void T_4 * V_41 ;
F_4 ( V_2 , 3 , L_299 ) ;
if ( ! F_278 ( V_2 , V_742 ) ) {
V_37 = - V_340 ;
goto V_73;
}
if ( F_351 ( & V_741 , V_721 ,
sizeof( struct V_740 ) ) ) {
V_37 = - V_726 ;
goto V_73;
}
V_732 . V_735 = V_741 . V_735 ;
V_732 . V_736 = 0 ;
V_732 . V_64 = F_27 ( V_741 . V_735 , V_49 ) ;
if ( ! V_732 . V_64 ) {
V_37 = - V_50 ;
goto V_73;
}
V_113 = F_273 ( V_2 , V_742 ,
sizeof( struct V_496 ) +
sizeof( struct V_738 ) ) ;
if ( ! V_113 ) {
V_37 = - V_50 ;
goto V_743;
}
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_739 = & V_130 -> V_117 . V_465 . V_117 . V_744 ;
V_739 -> V_658 = V_741 . V_134 ;
V_37 = F_269 ( V_2 , V_113 , F_354 ,
& V_732 ) ;
if ( ! V_37 ) {
if ( F_356 () )
V_41 = F_357 ( V_741 . V_43 ) ;
else
V_41 = ( void T_4 * ) ( unsigned long ) V_741 . V_43 ;
if ( F_353 ( V_41 , V_732 . V_64 ,
V_732 . V_736 ) ) {
V_37 = - V_726 ;
goto V_743;
}
V_741 . V_736 = V_732 . V_736 ;
if ( F_353 ( V_721 , & V_741 ,
sizeof( struct V_740 ) ) )
V_37 = - V_726 ;
} else
if ( V_37 == V_737 )
V_37 = - V_726 ;
V_743:
F_32 ( V_732 . V_64 ) ;
V_73:
return V_37 ;
}
static int F_358 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
struct V_745 * V_746 ;
struct V_747 * V_747 ;
F_4 ( V_2 , 2 , L_300 ) ;
V_747 = (struct V_747 * ) V_125 -> V_386 ;
V_130 = (struct V_129 * ) V_117 ;
V_746 = & V_130 -> V_117 . V_465 . V_117 . V_746 ;
if ( V_130 -> V_117 . V_465 . V_133 . V_139 == 0 ) {
V_747 -> V_748 = V_746 -> V_748 ;
V_747 -> V_749 = V_746 -> V_749 ;
V_747 -> V_750 = V_746 -> V_750 ;
}
F_271 ( V_2 , V_125 , ( unsigned long ) V_130 ) ;
return 0 ;
}
static int V_745 ( struct V_1 * V_2 ,
struct V_747 * V_747 )
{
struct V_112 * V_113 ;
F_4 ( V_2 , 2 , L_301 ) ;
if ( ! F_278 ( V_2 , V_751 ) )
return - V_340 ;
V_113 = F_273 ( V_2 , V_751 ,
sizeof( struct V_496 ) ) ;
if ( ! V_113 )
return - V_50 ;
return F_269 ( V_2 , V_113 , F_358 ,
( void * ) V_747 ) ;
}
static inline int F_359 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_12 . type ) {
case V_15 :
return 2 ;
default:
return 0 ;
}
}
static void F_360 ( struct V_1 * V_2 )
{
int V_37 ;
int V_253 ;
char * V_346 ;
struct V_158 * V_752 ;
int V_753 = 0 ;
F_41 ( V_65 , 2 , L_302 ) ;
V_752 = F_44 ( V_2 ) ;
if ( ! V_752 -> V_754 ) {
V_753 = 1 ;
V_37 = F_361 ( V_752 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_73;
}
}
V_37 = F_164 ( V_2 , ( void * * ) & V_346 , & V_253 ) ;
if ( V_37 ) {
F_68 ( 2 , L_303 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_755;
}
F_167 ( V_2 , V_346 ) ;
if ( V_753 )
F_168 ( V_2 , V_346 ) ;
F_32 ( V_346 ) ;
V_37 = F_362 ( V_752 , & V_2 -> V_756 ) ;
if ( V_37 )
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
F_45 ( V_65 , 2 , L_304 , V_2 -> V_756 . V_757 ) ;
F_45 ( V_65 , 2 , L_305 , V_2 -> V_756 . V_758 ) ;
F_45 ( V_65 , 2 , L_305 , V_2 -> V_756 . V_759 ) ;
F_45 ( V_65 , 2 , L_306 , V_2 -> V_756 . V_760 ) ;
if ( ! ( ( V_2 -> V_756 . V_757 != V_761 ) ||
( ( V_2 -> V_756 . V_758 & V_762 ) == 0 ) ||
( ( V_2 -> V_756 . V_759 & V_763 ) == 0 ) ) ) {
F_89 ( & V_2 -> V_10 -> V_9 ,
L_307 ) ;
} else {
V_2 -> V_66 . V_67 = V_564 ;
}
V_755:
if ( V_753 == 1 )
F_363 ( V_752 ) ;
V_73:
return;
}
static inline void F_364 ( struct V_1 * V_2 ,
struct V_523 * * V_764 ,
void (* * F_365) ( struct V_158 * , int , unsigned long ) ) {
int V_44 ;
if ( V_2 -> V_66 . V_67 == V_68 ) {
int V_184 = V_62 *
( V_2 -> V_46 . V_72 - 1 ) ;
V_44 = V_62 * ( V_2 -> V_46 . V_72 - 1 ) ;
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_764 [ V_184 + V_44 ] = (struct V_523 * )
F_309 ( V_2 -> V_46 . V_69 -> V_63 [ V_44 ] . V_64 ) ;
}
F_365 [ V_2 -> V_46 . V_72 - 1 ] = NULL ;
}
}
static int F_246 ( struct V_1 * V_2 )
{
struct V_765 V_766 ;
char * V_767 ;
struct V_523 * * V_764 ;
void (* * F_365) ( struct V_158 * , int , unsigned long );
struct V_523 * * V_768 ;
int V_44 , V_45 , V_769 ;
int V_37 = 0 ;
F_41 ( V_65 , 2 , L_308 ) ;
V_767 = F_27 ( V_62 * sizeof( char ) ,
V_49 ) ;
if ( ! V_767 ) {
V_37 = - V_50 ;
goto V_770;
}
F_235 ( V_2 , V_767 ) ;
F_239 ( V_2 , V_767 ) ;
V_764 = F_27 ( V_2 -> V_46 . V_72 *
V_62 * sizeof( void * ) ,
V_49 ) ;
if ( ! V_764 ) {
V_37 = - V_50 ;
goto V_771;
}
for ( V_44 = 0 ; V_44 < V_62 ; ++ V_44 ) {
V_764 [ V_44 ] = (struct V_523 * )
F_309 ( V_2 -> V_46 . V_423 -> V_63 [ V_44 ] . V_64 ) ;
}
F_365 = F_27 ( sizeof( void * ) * V_2 -> V_46 . V_72 ,
V_49 ) ;
if ( ! F_365 ) {
V_37 = - V_50 ;
goto V_772;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_46 . V_72 ; ++ V_44 )
F_365 [ V_44 ] = V_2 -> V_149 -> V_773 ;
F_364 ( V_2 , V_764 , F_365 ) ;
V_768 =
F_27 ( V_2 -> V_46 . V_78 * V_62 *
sizeof( void * ) , V_49 ) ;
if ( ! V_768 ) {
V_37 = - V_50 ;
goto V_774;
}
for ( V_44 = 0 , V_769 = 0 ; V_44 < V_2 -> V_46 . V_78 ; ++ V_44 )
for ( V_45 = 0 ; V_45 < V_62 ; ++ V_45 , ++ V_769 ) {
V_768 [ V_769 ] = (struct V_523 * ) F_309 (
V_2 -> V_46 . V_80 [ V_44 ] -> V_63 [ V_45 ] -> V_64 ) ;
}
memset ( & V_766 , 0 , sizeof( struct V_765 ) ) ;
V_766 . V_159 = F_44 ( V_2 ) ;
V_766 . V_775 = F_359 ( V_2 ) ;
V_766 . V_776 = 0 ;
V_766 . V_767 = V_767 ;
V_766 . V_777 = V_2 -> V_46 . V_72 ;
V_766 . V_778 = V_2 -> V_46 . V_78 ;
V_766 . V_779 = V_2 -> V_149 -> V_779 ;
V_766 . V_780 = V_2 -> V_149 -> V_780 ;
V_766 . V_781 = F_365 ;
V_766 . V_782 = ( unsigned long ) V_2 ;
V_766 . V_783 = ( void * * ) V_764 ;
V_766 . V_784 = ( void * * ) V_768 ;
V_766 . V_785 = V_2 -> V_46 . V_77 ;
V_766 . V_786 =
( V_2 -> V_12 . type == V_15 ) ? 1 : 32 ;
if ( F_59 ( & V_2 -> V_46 . V_3 , V_335 ,
V_331 ) == V_335 ) {
V_37 = F_366 ( & V_766 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_335 ) ;
goto V_73;
}
V_37 = F_367 ( & V_766 ) ;
if ( V_37 ) {
F_60 ( & V_2 -> V_46 . V_3 , V_335 ) ;
F_247 ( F_44 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_66 . V_67 ) {
case V_68 :
F_89 ( & V_2 -> V_10 -> V_9 , L_309 ) ;
break;
case V_278 :
F_89 ( & V_2 -> V_10 -> V_9 , L_310 ) ;
break;
default:
break;
}
V_73:
F_32 ( V_768 ) ;
V_774:
F_32 ( F_365 ) ;
V_772:
F_32 ( V_764 ) ;
V_771:
F_32 ( V_767 ) ;
V_770:
return V_37 ;
}
static void F_368 ( struct V_1 * V_2 )
{
F_41 ( V_65 , 2 , L_311 ) ;
F_39 ( V_65 , 2 , & V_2 , sizeof( void * ) ) ;
F_130 ( & V_2 -> V_114 ) ;
F_130 ( & V_2 -> V_155 ) ;
if ( V_2 -> V_9 )
F_369 ( V_2 -> V_9 ) ;
F_32 ( V_2 -> V_289 ) ;
F_132 ( V_2 ) ;
F_370 ( & V_2 -> V_301 ) ;
F_32 ( V_2 ) ;
}
void F_371 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 2 , L_312 ) ;
F_372 ( V_2 , 2 , & V_2 -> V_66 . V_481 , sizeof( V_2 -> V_66 . V_481 ) ) ;
F_372 ( V_2 , 2 , & V_2 -> V_66 . V_483 , sizeof( V_2 -> V_66 . V_483 ) ) ;
F_372 ( V_2 , 2 , & V_2 -> V_66 . V_468 , sizeof( V_2 -> V_66 . V_468 ) ) ;
F_372 ( V_2 , 2 , & V_2 -> V_12 . V_497 ,
sizeof( V_2 -> V_12 . V_497 ) ) ;
}
int F_373 ( struct V_1 * V_2 )
{
int V_787 = 3 ;
int V_37 ;
F_41 ( V_65 , 2 , L_313 ) ;
F_60 ( & V_2 -> V_531 , 0 ) ;
F_134 ( V_2 ) ;
V_788:
if ( V_787 < 3 )
F_68 ( 2 , L_314 ,
F_69 ( & V_2 -> V_10 -> V_9 ) ) ;
V_37 = F_162 ( V_2 , V_2 -> V_12 . type != V_15 ) ;
F_363 ( F_44 ( V_2 ) ) ;
F_363 ( F_374 ( V_2 ) ) ;
F_363 ( F_152 ( V_2 ) ) ;
F_247 ( F_44 ( V_2 ) ) ;
V_37 = F_361 ( F_152 ( V_2 ) ) ;
if ( V_37 )
goto V_789;
V_37 = F_361 ( F_374 ( V_2 ) ) ;
if ( V_37 )
goto V_789;
V_37 = F_361 ( F_44 ( V_2 ) ) ;
if ( V_37 )
goto V_789;
V_789:
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_315 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_37 , V_37 ) ;
if ( -- V_787 < 0 )
goto V_73;
else
goto V_788;
}
F_360 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
V_37 = F_173 ( & V_2 -> V_114 , F_185 ) ;
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_316 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
if ( -- V_787 < 0 )
goto V_73;
else
goto V_788;
}
V_37 = F_173 ( & V_2 -> V_155 , F_182 ) ;
if ( V_37 == - V_324 ) {
F_41 ( V_65 , 2 , L_317 ) ;
return V_37 ;
} else if ( V_37 ) {
F_45 ( V_65 , 2 , L_186 , V_37 ) ;
if ( -- V_787 < 0 )
goto V_73;
else
goto V_788;
}
V_2 -> V_123 = 0 ;
V_37 = F_245 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_187 , V_37 ) ;
goto V_73;
}
V_2 -> V_66 . V_481 . V_469 = 0 ;
V_2 -> V_66 . V_483 . V_469 = 0 ;
V_2 -> V_66 . V_468 . V_469 = 0 ;
V_2 -> V_66 . V_790 . V_469 = 0 ;
V_2 -> V_12 . V_497 = 0 ;
V_37 = F_276 ( V_2 , V_393 ) ;
if ( V_37 == - V_50 )
goto V_73;
if ( F_334 ( V_2 , V_482 ) ) {
V_37 = F_274 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_188 , V_37 ) ;
goto V_73;
}
}
if ( F_278 ( V_2 , V_791 ) ) {
V_37 = F_280 ( V_2 ) ;
if ( V_37 < 0 ) {
F_45 ( V_65 , 2 , L_189 , V_37 ) ;
goto V_73;
}
}
return 0 ;
V_73:
F_67 ( & V_2 -> V_10 -> V_9 , L_106
L_107 ) ;
F_68 ( 2 , L_318 ,
F_69 ( & V_2 -> V_10 -> V_9 ) , V_37 ) ;
return V_37 ;
}
static inline int F_375 ( struct V_442 * V_792 ,
struct V_793 * V_245 ,
struct V_232 * * V_794 , int V_184 , int * V_795 , int V_604 )
{
struct V_438 * V_438 = F_257 ( V_245 -> V_250 ) ;
if ( * V_794 == NULL ) {
if ( V_792 -> V_430 ) {
* V_794 = V_792 -> V_430 ;
V_792 -> V_430 = NULL ;
} else {
* V_794 = F_261 ( V_443 + V_444 ) ;
if ( ! ( * V_794 ) )
return - V_50 ;
}
F_376 ( * V_794 , V_444 ) ;
if ( V_604 <= V_443 ) {
memcpy ( F_377 ( * V_794 , V_604 ) , V_245 -> V_250 + V_184 ,
V_604 ) ;
} else {
F_378 ( V_438 ) ;
memcpy ( F_377 ( * V_794 , V_443 ) ,
V_245 -> V_250 + V_184 , V_443 ) ;
F_379 ( * V_794 , * V_795 , V_438 ,
V_184 + V_443 ,
V_604 - V_443 ) ;
( * V_794 ) -> V_604 += V_604 - V_443 ;
( * V_794 ) -> V_163 += V_604 - V_443 ;
( * V_794 ) -> V_796 += V_604 - V_443 ;
( * V_795 ) ++ ;
}
} else {
F_378 ( V_438 ) ;
F_379 ( * V_794 , * V_795 , V_438 , V_184 , V_604 ) ;
( * V_794 ) -> V_604 += V_604 ;
( * V_794 ) -> V_163 += V_604 ;
( * V_794 ) -> V_796 += V_604 ;
( * V_795 ) ++ ;
}
return 0 ;
}
static inline int F_380 ( struct V_793 * V_797 )
{
return ( V_797 -> V_254 & V_445 ) ;
}
struct V_232 * F_381 ( struct V_1 * V_2 ,
struct V_442 * V_792 ,
struct V_793 * * V_798 , int * V_799 ,
struct V_606 * * V_133 )
{
struct V_793 * V_245 = * V_798 ;
struct V_523 * V_64 = V_792 -> V_64 ;
int V_184 = * V_799 ;
struct V_232 * V_233 = NULL ;
int V_800 = 0 ;
void * V_801 ;
int V_604 ;
int V_802 = 0 ;
int V_803 = 0 ;
int V_597 = 0 ;
if ( V_245 -> V_253 < V_184 + sizeof( struct V_606 ) ) {
if ( F_380 ( V_245 ) )
return NULL ;
V_245 ++ ;
V_184 = 0 ;
if ( V_245 -> V_253 < sizeof( struct V_606 ) )
return NULL ;
}
* V_133 = V_245 -> V_250 + V_184 ;
V_184 += sizeof( struct V_606 ) ;
switch ( ( * V_133 ) -> V_133 . V_804 . V_314 ) {
case V_805 :
V_800 = ( * V_133 ) -> V_133 . V_804 . V_806 ;
break;
case V_807 :
V_800 = ( * V_133 ) -> V_133 . V_621 . V_253 ;
V_802 = V_444 ;
break;
case V_808 :
V_800 = ( * V_133 ) -> V_133 . V_809 . V_810 ;
V_802 = sizeof( struct V_606 ) ;
break;
default:
break;
}
if ( ! V_800 )
return NULL ;
if ( ( ( V_800 >= V_2 -> V_66 . V_274 ) &&
( ! ( V_2 -> V_12 . type == V_18 ) ) &&
( ! F_51 ( & V_2 -> V_531 ) ) ) ||
( V_2 -> V_66 . V_67 == V_68 ) ) {
V_803 = 1 ;
} else {
V_233 = F_261 ( V_800 + V_802 ) ;
if ( ! V_233 )
goto V_811;
if ( V_802 )
F_376 ( V_233 , V_802 ) ;
}
V_801 = V_245 -> V_250 + V_184 ;
while ( V_800 ) {
V_604 = F_211 ( V_800 , ( int ) ( V_245 -> V_253 - V_184 ) ) ;
if ( V_604 ) {
if ( V_803 ) {
if ( F_375 ( V_792 , V_245 ,
& V_233 , V_184 , & V_597 , V_604 ) )
goto V_811;
} else {
memcpy ( F_377 ( V_233 , V_604 ) , V_801 ,
V_604 ) ;
}
}
V_800 -= V_604 ;
if ( V_800 ) {
if ( F_380 ( V_245 ) ) {
F_4 ( V_2 , 4 , L_319 ) ;
F_372 ( V_2 , 2 , V_64 , sizeof( void * ) ) ;
F_127 ( V_233 ) ;
V_2 -> V_526 . V_701 ++ ;
return NULL ;
}
V_245 ++ ;
V_184 = 0 ;
V_801 = V_245 -> V_250 ;
} else {
V_184 += V_604 ;
}
}
* V_798 = V_245 ;
* V_799 = V_184 ;
if ( V_803 && V_2 -> V_66 . V_273 ) {
V_2 -> V_440 . V_812 ++ ;
V_2 -> V_440 . V_813 += F_317 ( V_233 ) -> V_598 ;
}
return V_233 ;
V_811:
if ( F_382 () ) {
F_4 ( V_2 , 2 , L_320 ) ;
}
V_2 -> V_526 . V_527 ++ ;
return NULL ;
}
static int F_383 ( struct V_1 * V_2 ,
struct V_124 * V_125 , unsigned long V_117 )
{
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_201 ) ;
V_130 = (struct V_129 * ) V_117 ;
if ( V_130 -> V_133 . V_139 == 0 ) {
V_130 -> V_133 . V_139 = V_130 -> V_117 . V_814 . V_133 . V_139 ;
if ( V_130 -> V_133 . V_392 == V_393 )
V_2 -> V_66 . V_481 . V_484 = V_130 -> V_133 . V_460 ;
if ( V_130 -> V_133 . V_392 == V_485 )
V_2 -> V_66 . V_483 . V_484 = V_130 -> V_133 . V_460 ;
}
if ( V_130 -> V_117 . V_814 . V_133 . V_815 == V_816 &&
V_130 -> V_117 . V_814 . V_133 . V_474 == V_817 ) {
V_2 -> V_12 . V_818 = V_130 -> V_117 . V_814 . V_117 . V_819 ;
F_52 ( V_2 , 3 , L_321 , V_2 -> V_12 . V_818 ) ;
}
if ( V_130 -> V_117 . V_814 . V_133 . V_815 == V_820 &&
V_130 -> V_117 . V_814 . V_133 . V_474 == V_817 ) {
V_2 -> V_12 . V_821 =
V_130 -> V_117 . V_814 . V_117 . V_819 ;
F_52 ( V_2 , 3 , L_322 , V_2 -> V_12 . V_821 ) ;
}
return 0 ;
}
static struct V_112 * F_384 ( struct V_1 * V_2 ,
enum V_822 V_823 ,
V_185 V_341 , V_185 V_163 ,
enum V_451 V_452 )
{
struct V_112 * V_113 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_323 ) ;
V_113 = F_265 ( V_2 , V_824 , V_452 ) ;
if ( V_113 ) {
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
V_130 -> V_117 . V_814 . V_133 . V_815 = V_823 ;
V_130 -> V_117 . V_814 . V_133 . V_253 = 8 + V_163 ;
V_130 -> V_117 . V_814 . V_133 . V_474 = V_341 ;
V_130 -> V_117 . V_814 . V_133 . V_139 = 0 ;
V_130 -> V_117 . V_814 . V_133 . V_476 = 0 ;
}
return V_113 ;
}
int F_385 ( struct V_1 * V_2 ,
struct V_112 * V_113 , V_185 V_163 , long V_117 ,
int (* F_190)( struct V_1 * ,
struct V_124 * , unsigned long ) ,
void * V_383 )
{
int V_37 ;
struct V_129 * V_130 ;
F_4 ( V_2 , 4 , L_324 ) ;
V_130 = (struct V_129 * ) ( V_113 -> V_117 + V_390 ) ;
if ( V_163 <= sizeof( T_1 ) )
V_130 -> V_117 . V_814 . V_117 . V_819 = ( T_1 ) V_117 ;
else
memcpy ( & V_130 -> V_117 . V_814 . V_117 , ( void * ) V_117 , V_163 ) ;
V_37 = F_269 ( V_2 , V_113 , F_190 , V_383 ) ;
return V_37 ;
}
int F_386 ( struct V_1 * V_2 ,
enum V_822 V_823 ,
V_185 V_341 , long V_117 )
{
int V_37 ;
int V_253 = 0 ;
struct V_112 * V_113 ;
F_4 ( V_2 , 4 , L_325 ) ;
if ( V_117 )
V_253 = sizeof( T_1 ) ;
V_113 = F_384 ( V_2 , V_823 , V_341 ,
V_253 , V_393 ) ;
if ( ! V_113 )
return - V_50 ;
V_37 = F_385 ( V_2 , V_113 , V_253 , V_117 ,
F_383 , NULL ) ;
return V_37 ;
}
static void F_387 ( void )
{
int V_825 ;
for ( V_825 = 0 ; V_825 < V_826 ; V_825 ++ ) {
F_388 ( V_827 [ V_825 ] . V_314 ) ;
V_827 [ V_825 ] . V_314 = NULL ;
}
}
void F_389 ( T_5 * V_314 , int V_373 , char * V_828 , ... )
{
char V_829 [ 32 ] ;
T_6 args ;
if ( ! F_390 ( V_314 , V_373 ) )
return;
va_start ( args , V_828 ) ;
vsnprintf ( V_829 , sizeof( V_829 ) , V_828 , args ) ;
va_end ( args ) ;
F_391 ( V_314 , V_373 , V_829 ) ;
}
static int F_392 ( void )
{
int V_338 ;
int V_825 ;
for ( V_825 = 0 ; V_825 < V_826 ; V_825 ++ ) {
V_827 [ V_825 ] . V_314 = F_393 ( V_827 [ V_825 ] . V_514 ,
V_827 [ V_825 ] . V_830 ,
V_827 [ V_825 ] . V_831 ,
V_827 [ V_825 ] . V_163 ) ;
if ( V_827 [ V_825 ] . V_314 == NULL ) {
F_387 () ;
return - V_50 ;
}
V_338 = F_394 ( V_827 [ V_825 ] . V_314 , V_827 [ V_825 ] . V_832 ) ;
if ( V_338 ) {
F_387 () ;
return V_338 ;
}
F_395 ( V_827 [ V_825 ] . V_314 , V_827 [ V_825 ] . V_373 ) ;
}
return 0 ;
}
int F_396 ( struct V_1 * V_2 ,
enum V_833 V_149 )
{
int V_37 = 0 ;
F_397 ( & V_834 ) ;
switch ( V_149 ) {
case V_835 :
V_2 -> V_149 = F_398 (
F_399 ( V_836 ) , L_326 ) ;
break;
case V_837 :
V_2 -> V_149 = F_398 (
F_399 ( V_838 ) , L_327 ) ;
break;
}
if ( ! V_2 -> V_149 ) {
F_47 ( & V_2 -> V_10 -> V_9 , L_328
L_329 , V_149 ) ;
V_37 = - V_405 ;
}
F_400 ( & V_834 ) ;
return V_37 ;
}
void F_401 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 . V_307 )
F_402 ( V_838 ) ;
else
F_402 ( V_836 ) ;
V_2 -> V_149 = NULL ;
}
static T_5 * F_403 ( char * V_514 )
{
struct V_839 * V_436 ;
T_5 * V_37 = NULL ;
F_397 ( & V_840 ) ;
F_250 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_436 -> V_841 , V_514 ) == 0 ) {
V_37 = V_436 -> V_842 ;
break;
}
}
F_400 ( & V_840 ) ;
return V_37 ;
}
static int F_404 ( struct V_1 * V_2 , char * V_514 )
{
struct V_839 * V_843 ;
V_2 -> V_844 = F_393 ( V_514 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_844 ) {
F_45 ( V_65 , 2 , L_262 , L_330 ) ;
goto V_845;
}
if ( F_394 ( V_2 -> V_844 , & V_846 ) )
goto V_847;
V_843 = F_27 ( sizeof( struct V_839 ) , V_49 ) ;
if ( ! V_843 )
goto V_847;
strncpy ( V_843 -> V_841 , V_514 , V_848 ) ;
V_843 -> V_842 = V_2 -> V_844 ;
F_397 ( & V_840 ) ;
F_33 ( & V_843 -> V_849 , & V_850 ) ;
F_400 ( & V_840 ) ;
return 0 ;
V_847:
F_388 ( V_2 -> V_844 ) ;
V_845:
return - V_50 ;
}
static void F_405 ( void )
{
struct V_839 * V_436 , * V_41 ;
F_397 ( & V_840 ) ;
F_24 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_25 ( & V_436 -> V_849 ) ;
F_388 ( V_436 -> V_842 ) ;
F_32 ( V_436 ) ;
}
F_400 ( & V_840 ) ;
}
static int F_406 ( struct V_160 * V_10 )
{
struct V_1 * V_2 ;
struct V_851 * V_9 ;
int V_37 ;
unsigned long V_32 ;
char V_841 [ V_848 ] ;
F_41 ( V_65 , 2 , L_331 ) ;
V_9 = & V_10 -> V_9 ;
if ( ! F_407 ( V_9 ) )
return - V_852 ;
F_45 ( V_65 , 2 , L_262 , F_69 ( & V_10 -> V_9 ) ) ;
V_2 = F_149 () ;
if ( ! V_2 ) {
F_45 ( V_65 , 2 , L_37 , - V_50 ) ;
V_37 = - V_50 ;
goto V_853;
}
snprintf ( V_841 , sizeof( V_841 ) , L_332 ,
F_69 ( & V_10 -> V_9 ) ) ;
V_2 -> V_844 = F_403 ( V_841 ) ;
if ( ! V_2 -> V_844 ) {
V_37 = F_404 ( V_2 , V_841 ) ;
if ( V_37 )
goto V_854;
}
V_2 -> V_114 . V_119 = V_10 -> V_159 [ 0 ] ;
V_2 -> V_155 . V_119 = V_10 -> V_159 [ 1 ] ;
V_2 -> V_117 . V_119 = V_10 -> V_159 [ 2 ] ;
F_408 ( & V_10 -> V_9 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_10 -> V_159 [ 0 ] -> V_855 = F_118 ;
V_10 -> V_159 [ 1 ] -> V_855 = F_118 ;
V_10 -> V_159 [ 2 ] -> V_855 = F_118 ;
V_37 = F_151 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_141 , V_37 ) ;
goto V_854;
}
V_37 = F_142 ( V_2 ) ;
if ( V_37 ) {
F_45 ( V_65 , 2 , L_136 , V_37 ) ;
goto V_854;
}
if ( V_2 -> V_12 . type == V_18 )
V_10 -> V_9 . type = & V_856 ;
else
V_10 -> V_9 . type = & V_857 ;
switch ( V_2 -> V_12 . type ) {
case V_18 :
case V_16 :
V_37 = F_396 ( V_2 , V_837 ) ;
if ( V_37 )
goto V_854;
V_37 = V_2 -> V_149 -> V_858 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_859;
case V_14 :
case V_17 :
default:
break;
}
F_409 ( & V_860 . V_861 , V_32 ) ;
F_102 ( & V_2 -> V_42 , & V_860 . V_42 ) ;
F_410 ( & V_860 . V_861 , V_32 ) ;
F_360 ( V_2 ) ;
return 0 ;
V_859:
F_401 ( V_2 ) ;
V_854:
F_368 ( V_2 ) ;
V_853:
F_411 ( V_9 ) ;
return V_37 ;
}
static void F_412 ( struct V_160 * V_10 )
{
unsigned long V_32 ;
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
F_41 ( V_65 , 2 , L_333 ) ;
if ( V_2 -> V_149 ) {
V_2 -> V_149 -> remove ( V_10 ) ;
F_401 ( V_2 ) ;
}
F_409 ( & V_860 . V_861 , V_32 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_410 ( & V_860 . V_861 , V_32 ) ;
F_368 ( V_2 ) ;
F_408 ( & V_10 -> V_9 , NULL ) ;
F_411 ( & V_10 -> V_9 ) ;
return;
}
static int F_413 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
int V_37 = 0 ;
int V_862 ;
if ( ! V_2 -> V_149 ) {
if ( V_2 -> V_12 . type == V_15 )
V_862 = V_835 ;
else
V_862 = V_837 ;
V_37 = F_396 ( V_2 , V_862 ) ;
if ( V_37 )
goto V_845;
V_37 = V_2 -> V_149 -> V_858 ( V_2 -> V_10 ) ;
if ( V_37 )
goto V_845;
}
V_37 = V_2 -> V_149 -> V_863 ( V_10 ) ;
V_845:
return V_37 ;
}
static int F_414 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
return V_2 -> V_149 -> V_864 ( V_10 ) ;
}
static void F_415 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_865 )
V_2 -> V_149 -> V_865 ( V_10 ) ;
}
static int F_416 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_866 )
return V_2 -> V_149 -> V_866 ( V_10 ) ;
return 0 ;
}
static void F_417 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_867 )
V_2 -> V_149 -> V_867 ( V_10 ) ;
}
static int F_418 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_868 )
return V_2 -> V_149 -> V_868 ( V_10 ) ;
return 0 ;
}
static int F_419 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_869 )
return V_2 -> V_149 -> V_869 ( V_10 ) ;
return 0 ;
}
static int F_420 ( struct V_160 * V_10 )
{
struct V_1 * V_2 = F_95 ( & V_10 -> V_9 ) ;
if ( V_2 -> V_149 && V_2 -> V_149 -> V_870 )
return V_2 -> V_149 -> V_870 ( V_10 ) ;
return 0 ;
}
static T_7 F_421 ( struct V_871 * V_872 ,
const char * V_231 , T_8 V_167 )
{
int V_845 ;
V_845 = F_422 ( V_873 ,
& V_874 , 3 , V_231 ) ;
return V_845 ? V_845 : V_167 ;
}
int F_423 ( struct V_634 * V_9 , int V_875 )
{
switch ( V_875 ) {
case V_876 :
return ( sizeof( V_877 ) / V_878 ) ;
default:
return - V_405 ;
}
}
void F_424 ( struct V_634 * V_9 ,
struct V_879 * V_526 , T_9 * V_117 )
{
struct V_1 * V_2 = V_9 -> V_640 ;
V_117 [ 0 ] = V_2 -> V_526 . V_880 -
V_2 -> V_440 . V_881 ;
V_117 [ 1 ] = V_2 -> V_440 . V_882 ;
V_117 [ 2 ] = V_2 -> V_526 . V_883 -
V_2 -> V_440 . V_884 ;
V_117 [ 3 ] = V_2 -> V_440 . V_555 ;
V_117 [ 4 ] = V_2 -> V_526 . V_883 - V_2 -> V_440 . V_884
- V_2 -> V_440 . V_625 ;
V_117 [ 5 ] = V_2 -> V_440 . V_555 - V_2 -> V_440 . V_559 ;
V_117 [ 6 ] = V_2 -> V_440 . V_625 ;
V_117 [ 7 ] = V_2 -> V_440 . V_559 ;
V_117 [ 8 ] = V_2 -> V_440 . V_885 ;
V_117 [ 9 ] = V_2 -> V_440 . V_886 ;
V_117 [ 10 ] = V_2 -> V_440 . V_812 ;
V_117 [ 11 ] = V_2 -> V_440 . V_813 ;
V_117 [ 12 ] = V_2 -> V_440 . V_441 ;
V_117 [ 13 ] = ( V_2 -> V_440 . V_887 >> 10 ) ;
V_117 [ 14 ] = V_2 -> V_440 . V_888 ;
V_117 [ 15 ] = V_2 -> V_440 . V_541 ;
V_117 [ 16 ] = V_2 -> V_440 . V_544 ;
V_117 [ 17 ] = V_543 ;
V_117 [ 18 ] = V_540 ;
V_117 [ 19 ] = F_51 ( & V_2 -> V_46 . V_80 [ 0 ] -> V_448 ) ;
V_117 [ 20 ] = ( V_2 -> V_46 . V_78 > 1 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 1 ] -> V_448 ) : 0 ;
V_117 [ 21 ] = ( V_2 -> V_46 . V_78 > 2 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 2 ] -> V_448 ) : 0 ;
V_117 [ 22 ] = ( V_2 -> V_46 . V_78 > 3 ) ?
F_51 ( & V_2 -> V_46 . V_80 [ 3 ] -> V_448 ) : 0 ;
V_117 [ 23 ] = V_2 -> V_440 . V_889 ;
V_117 [ 24 ] = V_2 -> V_440 . V_890 ;
V_117 [ 25 ] = V_2 -> V_440 . V_535 ;
V_117 [ 26 ] = V_2 -> V_440 . V_533 ;
V_117 [ 27 ] = V_2 -> V_440 . V_578 ;
V_117 [ 28 ] = V_2 -> V_440 . V_574 ;
V_117 [ 29 ] = V_2 -> V_440 . V_891 ;
V_117 [ 30 ] = V_2 -> V_440 . V_892 ;
V_117 [ 31 ] = V_2 -> V_440 . V_552 ;
V_117 [ 32 ] = V_2 -> V_440 . V_548 ;
V_117 [ 33 ] = V_2 -> V_440 . V_893 ;
V_117 [ 34 ] = V_2 -> V_440 . V_894 ;
V_117 [ 35 ] = V_2 -> V_440 . V_566 ;
V_117 [ 36 ] = V_2 -> V_440 . V_570 ;
}
void F_425 ( struct V_634 * V_9 , V_711 V_875 , V_279 * V_117 )
{
switch ( V_875 ) {
case V_876 :
memcpy ( V_117 , & V_877 ,
sizeof( V_877 ) ) ;
break;
default:
F_75 ( 1 ) ;
break;
}
}
void F_426 ( struct V_634 * V_9 ,
struct V_895 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_640 ;
F_427 ( V_12 -> V_896 , V_2 -> V_66 . V_307 ? L_327 : L_326 ,
sizeof( V_12 -> V_896 ) ) ;
F_427 ( V_12 -> V_897 , L_334 , sizeof( V_12 -> V_897 ) ) ;
F_427 ( V_12 -> V_898 , V_2 -> V_12 . V_302 ,
sizeof( V_12 -> V_898 ) ) ;
snprintf ( V_12 -> V_899 , sizeof( V_12 -> V_899 ) , L_335 ,
F_428 ( V_2 ) , F_429 ( V_2 ) , F_430 ( V_2 ) ) ;
}
static void F_431 ( struct V_900 * V_901 ,
int V_902 , int V_903 )
{
int V_904 , V_905 , V_906 , V_907 ;
switch ( V_903 ) {
case V_908 :
V_904 = V_909 ;
V_905 = V_910 ;
break;
case V_911 :
V_904 = V_912 ;
V_905 = V_913 ;
break;
default:
V_904 = V_909 ;
V_905 = V_910 ;
F_54 ( 1 ) ;
}
V_906 = 0 ;
V_907 = 0 ;
switch ( V_902 ) {
case V_914 :
V_906 |= V_915 ;
V_907 |= V_916 ;
case V_917 :
V_906 |= V_918 | V_919 ;
V_907 |= V_920 |
V_921 ;
case V_922 :
V_906 |= V_923 | V_924 ;
V_907 |= V_925 | V_926 ;
case V_927 :
V_906 |= V_928 | V_929 ;
V_907 |= V_930 | V_931 ;
break;
default:
V_906 = V_928 | V_929 ;
V_907 = V_930 | V_931 ;
F_54 ( 1 ) ;
}
V_901 -> V_932 = V_933 | V_905 | V_907 ;
V_901 -> V_934 = V_935 | V_904 | V_906 ;
}
int F_432 ( struct V_634 * V_936 ,
struct V_900 * V_901 )
{
struct V_1 * V_2 = V_936 -> V_640 ;
enum V_450 V_19 ;
struct V_747 V_747 ;
int V_37 ;
V_711 V_937 ;
if ( ( V_2 -> V_12 . type == V_15 ) || ( V_2 -> V_12 . V_13 ) )
V_19 = V_23 ;
else
V_19 = V_2 -> V_12 . V_19 ;
V_901 -> V_938 = V_939 ;
V_901 -> V_940 = V_941 ;
V_901 -> V_942 = V_943 ;
switch ( V_19 ) {
case V_20 :
case V_24 :
F_431 ( V_901 , V_922 , V_908 ) ;
V_937 = V_922 ;
V_901 -> V_944 = V_908 ;
break;
case V_22 :
case V_26 :
F_431 ( V_901 , V_917 , V_911 ) ;
V_937 = V_917 ;
V_901 -> V_944 = V_911 ;
break;
case V_23 :
F_431 ( V_901 , V_914 , V_911 ) ;
V_937 = V_914 ;
V_901 -> V_944 = V_911 ;
break;
default:
F_431 ( V_901 , V_927 , V_908 ) ;
V_937 = V_927 ;
V_901 -> V_944 = V_908 ;
}
F_433 ( V_901 , V_937 ) ;
if ( ! F_1 ( V_2 ) )
return - V_852 ;
V_37 = V_745 ( V_2 , & V_747 ) ;
if ( V_37 == - V_340 )
return 0 ;
if ( V_37 )
return V_37 ;
F_434 ( V_936 ,
L_336 ,
V_747 . V_748 ,
V_747 . V_749 ,
V_747 . V_750 ) ;
switch ( V_747 . V_748 ) {
case V_945 :
case V_946 :
F_431 ( V_901 , V_917 , V_908 ) ;
V_901 -> V_944 = V_908 ;
break;
case V_947 :
case V_948 :
F_431 ( V_901 , V_917 , V_911 ) ;
V_901 -> V_944 = V_911 ;
break;
case V_949 :
case V_950 :
F_431 ( V_901 , V_914 , V_911 ) ;
V_901 -> V_944 = V_911 ;
break;
}
switch ( V_747 . V_749 ) {
case V_951 :
V_901 -> V_940 = V_941 ;
break;
case V_952 :
V_901 -> V_940 = V_953 ;
break;
}
switch ( V_747 . V_750 ) {
case V_954 :
V_937 = V_927 ;
break;
case V_955 :
V_937 = V_922 ;
break;
case V_956 :
V_937 = V_917 ;
break;
case V_957 :
V_937 = V_914 ;
break;
}
F_433 ( V_901 , V_937 ) ;
return 0 ;
}
static int F_435 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_386 ( V_2 , V_816 ,
V_817 , 0 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 , L_337
L_338 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
V_37 = F_386 ( V_2 , V_816 ,
V_958 ,
V_2 -> V_12 . V_818 ) ;
if ( V_37 ) {
F_67 ( & V_2 -> V_10 -> V_9 , L_339
L_338 ,
F_81 ( V_2 ) ) ;
return V_37 ;
}
return 0 ;
}
int F_436 ( struct V_1 * V_2 , int V_959 )
{
int V_37 ;
if ( V_959 ) {
V_37 = F_435 ( V_2 ) ;
if ( V_37 )
return - V_116 ;
F_89 ( & V_2 -> V_10 -> V_9 ,
L_340 ) ;
} else {
V_37 = F_386 ( V_2 ,
V_816 , V_960 , 0 ) ;
if ( V_37 )
return - V_116 ;
}
return 0 ;
}
int F_437 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
if ( ! F_334 ( V_2 , V_820 ) )
return V_37 ;
V_37 = F_386 ( V_2 , V_820 ,
V_817 , 0 ) ;
if ( V_37 )
goto V_961;
V_37 = F_386 ( V_2 , V_820 ,
V_958 ,
V_2 -> V_12 . V_821 ) ;
if ( V_37 )
goto V_961;
F_89 ( & V_2 -> V_10 -> V_9 , L_341 ) ;
return V_37 ;
V_961:
F_67 ( & V_2 -> V_10 -> V_9 , L_342
L_343 , F_81 ( V_2 ) ) ;
return V_37 ;
}
static int T_10 F_438 ( void )
{
int V_37 ;
F_439 ( L_344 ) ;
F_137 ( & V_860 . V_42 ) ;
F_137 ( & V_850 ) ;
F_440 ( & V_860 . V_861 ) ;
F_143 ( & V_834 ) ;
V_11 = F_441 ( L_345 ) ;
V_37 = F_392 () ;
if ( V_37 )
goto V_962;
V_873 = F_442 ( L_346 ) ;
V_37 = F_443 ( V_873 ) ;
if ( V_37 )
goto V_963;
V_252 = F_444 ( L_347 ,
sizeof( struct V_606 ) + V_444 , 64 , 0 , NULL ) ;
if ( ! V_252 ) {
V_37 = - V_50 ;
goto V_964;
}
V_101 = F_444 ( L_348 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
if ( ! V_101 ) {
V_37 = - V_50 ;
goto V_965;
}
V_37 = F_445 ( & V_966 ) ;
if ( V_37 )
goto V_967;
V_874 . V_896 . V_968 = V_969 ;
V_37 = F_446 ( & V_874 ) ;
if ( V_37 )
goto V_970;
return 0 ;
V_970:
F_447 ( & V_966 ) ;
V_967:
F_448 ( V_101 ) ;
V_965:
F_448 ( V_252 ) ;
V_964:
F_449 ( V_873 ) ;
V_963:
F_387 () ;
V_962:
F_450 ( L_349 ) ;
return V_37 ;
}
static void T_11 F_451 ( void )
{
F_405 () ;
F_452 ( V_11 ) ;
F_453 ( & V_874 ) ;
F_447 ( & V_966 ) ;
F_448 ( V_101 ) ;
F_448 ( V_252 ) ;
F_449 ( V_873 ) ;
F_387 () ;
F_439 ( L_350 ) ;
}
