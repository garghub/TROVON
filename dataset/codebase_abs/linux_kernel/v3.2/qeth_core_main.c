static inline const char * F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_1 ;
case V_6 :
return L_2 ;
case V_7 :
return L_3 ;
case V_8 :
return L_4 ;
default:
return L_5 ;
}
} else {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_6 ;
case V_6 :
return L_7 ;
case V_9 :
return L_8 ;
case V_7 :
return L_9 ;
case V_8 :
return L_10 ;
default:
return L_5 ;
}
}
return L_11 ;
}
const char * F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_12 ;
case V_6 :
return L_13 ;
case V_7 :
return L_14 ;
case V_8 :
return L_15 ;
default:
return L_16 ;
}
} else {
switch ( V_2 -> V_3 . type ) {
case V_5 :
switch ( V_2 -> V_3 . V_10 ) {
case V_11 :
return L_17 ;
case V_12 :
return L_18 ;
case V_13 :
return L_19 ;
case V_14 :
return L_20 ;
case V_15 :
return L_21 ;
case V_16 :
return L_22 ;
case V_17 :
return L_23 ;
case V_18 :
return L_24 ;
default:
return L_25 ;
}
case V_6 :
return L_26 ;
case V_9 :
return L_27 ;
case V_7 :
return L_28 ;
case V_8 :
return L_29 ;
default:
return L_16 ;
}
}
return L_30 ;
}
void F_3 ( struct V_1 * V_2 , unsigned long V_19 ,
int V_20 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_23 = V_19 ;
if ( V_20 )
V_2 -> V_24 &= V_19 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned long V_19 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_26 = ( V_2 -> V_27 & V_19 ) ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
int F_8 ( struct V_1 * V_2 , unsigned long V_19 )
{
return F_9 ( V_2 -> V_25 ,
F_7 ( V_2 , V_19 ) == 0 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_30 ;
F_11 ( V_2 , 5 , L_31 ) ;
F_12 (pool_entry, tmp,
&card->qdio.in_buf_pool.entry_list, list) {
F_13 ( & V_29 -> V_31 ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
void * V_32 ;
int V_33 , V_34 ;
F_11 ( V_2 , 5 , L_32 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_36 . V_37 ; ++ V_33 ) {
V_29 = F_15 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 ) {
F_16 ( V_2 ) ;
return - V_39 ;
}
for ( V_34 = 0 ; V_34 < F_17 ( V_2 ) ; ++ V_34 ) {
V_32 = ( void * ) F_18 ( V_38 ) ;
if ( ! V_32 ) {
while ( V_34 > 0 )
F_19 ( ( unsigned long )
V_29 -> V_40 [ -- V_34 ] ) ;
F_20 ( V_29 ) ;
F_16 ( V_2 ) ;
return - V_39 ;
}
V_29 -> V_40 [ V_34 ] = V_32 ;
}
F_21 ( & V_29 -> V_41 ,
& V_2 -> V_35 . V_36 . V_42 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_43 )
{
F_11 ( V_2 , 2 , L_33 ) ;
if ( ( V_2 -> V_44 != V_45 ) &&
( V_2 -> V_44 != V_46 ) )
return - V_47 ;
F_10 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_35 . V_48 . V_37 = V_43 ;
V_2 -> V_35 . V_36 . V_37 = V_43 ;
return F_14 ( V_2 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
F_24 ( V_52 , 2 , L_34 ) ;
memset ( V_2 -> V_35 . V_53 -> V_54 , 0 ,
V_55 * sizeof( struct V_56 ) ) ;
V_2 -> V_35 . V_53 -> V_57 = 127 ;
V_26 = F_25 ( F_26 ( V_2 ) , V_58 ,
V_2 -> V_35 . V_59 - 1 , 0 ,
127 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
goto V_60;
}
}
V_26 = 0 ;
V_60:
return V_26 ;
}
static inline int F_28 ( struct V_1 * V_2 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
int V_33 ;
struct V_61 * V_62 ;
F_24 ( V_52 , 2 , L_36 ) ;
V_2 -> V_35 . V_53 = F_15 ( sizeof( struct V_63 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_53 ) {
V_26 = - 1 ;
goto V_64;
}
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_53 , sizeof( void * ) ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_2 -> V_35 . V_53 -> V_65 [ V_33 ] . V_66 =
& V_2 -> V_35 . V_53 -> V_54 [ V_33 ] ;
}
V_2 -> V_35 . V_59 = 2 ;
V_2 -> V_35 . V_67 = (struct V_61 * )
F_15 ( V_2 -> V_35 . V_68 *
V_55 *
sizeof( struct V_61 ) , V_38 ) ;
V_62 = V_2 -> V_35 . V_67 ;
if ( V_62 == NULL ) {
V_26 = - 1 ;
goto V_69;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
V_2 -> V_35 . V_70 [ V_33 ] -> V_71 = V_62 ;
V_62 += V_55 ;
}
} else {
F_24 ( V_52 , 2 , L_37 ) ;
V_2 -> V_35 . V_53 = NULL ;
V_2 -> V_35 . V_59 = 1 ;
}
F_27 ( V_52 , 2 , L_38 , V_2 -> V_35 . V_59 ) ;
V_26 = 0 ;
V_60:
return V_26 ;
V_69:
F_20 ( V_2 -> V_35 . V_53 ) ;
V_2 -> V_35 . V_53 = NULL ;
V_64:
F_30 ( & V_2 -> V_72 -> V_73 , L_39 ) ;
goto V_60;
}
static inline void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 . V_53 ) {
-- V_2 -> V_35 . V_59 ;
F_20 ( V_2 -> V_35 . V_53 ) ;
V_2 -> V_35 . V_53 = NULL ;
}
F_20 ( V_2 -> V_35 . V_67 ) ;
V_2 -> V_35 . V_67 = NULL ;
}
static inline enum V_74 F_32 ( int V_75 ,
int V_76 ) {
enum V_74 V_77 ;
switch ( V_75 ) {
case 0 :
V_77 = V_76 ? V_78 : V_79 ;
break;
case 4 :
case 16 :
case 17 :
case 18 :
V_77 = V_76 ? V_80 :
V_81 ;
break;
default:
V_77 = V_76 ? V_82 :
V_83 ;
break;
}
return V_77 ;
}
static inline void F_33 ( struct V_84 * V_85 ,
int V_86 , int V_87 )
{
if ( V_85 -> V_65 [ V_86 ] -> V_88 != NULL ) {
struct V_89 * V_90 = V_85 -> V_65 [ V_86 ] ;
struct V_89 * V_91 = V_85 -> V_65 [ V_86 ] -> V_88 ;
while ( V_91 ) {
if ( V_87 ||
F_34 ( & V_91 -> V_44 ) ==
V_92 ) {
struct V_89 * V_93 = V_91 ;
F_11 ( V_93 -> V_85 -> V_2 , 5 , L_40 ) ;
F_35 ( V_93 -> V_85 -> V_2 , 5 , L_41 , ( long ) V_93 ) ;
F_36 ( V_91 ) ;
V_91 = V_93 -> V_88 ;
F_37 ( V_90 -> V_88 != V_93 ) ;
V_90 -> V_88 = V_91 ;
F_38 ( V_94 , V_93 ) ;
} else {
V_90 = V_91 ;
V_91 = V_91 -> V_88 ;
}
}
}
}
static inline void F_39 ( struct V_1 * V_2 ,
unsigned long V_95 ) {
struct V_96 * V_97 ;
struct V_89 * V_66 ;
enum V_74 V_98 ;
V_97 = (struct V_96 * ) F_40 ( V_95 ) ;
F_11 ( V_2 , 5 , L_42 ) ;
F_35 ( V_2 , 5 , L_41 , V_95 ) ;
V_66 = (struct V_89 * ) V_97 -> V_99 ;
F_35 ( V_2 , 5 , L_41 , V_97 -> V_99 ) ;
F_37 ( V_66 == NULL ) ;
if ( F_41 ( & V_66 -> V_44 , V_100 ,
V_101 ) == V_100 ) {
V_98 = V_79 ;
} else {
F_37 ( F_34 ( & V_66 -> V_44 ) != V_102 ) ;
F_42 ( & V_66 -> V_44 , V_101 ) ;
V_98 = V_78 ;
}
if ( V_97 -> V_103 != 0 ) {
F_35 ( V_2 , 2 , L_43 , V_97 -> V_103 ) ;
V_98 = F_32 ( V_97 -> V_103 , 1 ) ;
}
F_43 ( V_66 -> V_85 , V_66 , V_98 ) ;
V_66 -> V_97 = NULL ;
F_44 ( V_66 -> V_85 , V_66 ,
V_92 ) ;
F_45 ( V_97 ) ;
}
static inline int F_46 ( struct V_1 * V_2 , unsigned int V_104 )
{
return V_2 -> V_49 . V_50 == V_51 &&
V_2 -> V_35 . V_53 != NULL &&
V_104 != 0 &&
V_104 == V_2 -> V_35 . V_59 - 1 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 5 , L_44 ) ;
if ( V_2 -> V_107 . V_44 != V_108 )
return - V_109 ;
V_106 = F_48 ( & V_2 -> V_107 ) ;
if ( ! V_106 ) {
F_49 ( & V_2 -> V_72 -> V_73 , L_45
L_46 ) ;
F_50 ( 2 , L_47
L_48 , F_51 ( & V_2 -> V_72 -> V_73 ) ) ;
return - V_39 ;
}
F_52 ( & V_2 -> V_107 , V_106 -> V_110 , V_111 ) ;
F_11 ( V_2 , 6 , L_49 ) ;
V_26 = F_53 ( V_2 -> V_107 . V_112 , & V_2 -> V_107 . V_113 ,
( V_114 ) V_106 , 0 , 0 ) ;
if ( V_26 ) {
F_50 ( 2 , L_50
L_51 , F_51 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_42 ( & V_2 -> V_107 . V_115 , 0 ) ;
V_2 -> V_116 = 1 ;
F_54 ( V_2 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
return V_26 ;
}
static struct V_117 * F_55 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
V_118 = F_15 ( sizeof( struct V_117 ) , V_119 ) ;
if ( V_118 ) {
F_42 ( & V_118 -> V_120 , 1 ) ;
F_42 ( & V_118 -> V_121 , 0 ) ;
V_118 -> V_2 = V_2 ;
} ;
return V_118 ;
}
static void F_56 ( struct V_117 * V_118 )
{
F_57 ( F_34 ( & V_118 -> V_120 ) <= 0 ) ;
F_58 ( & V_118 -> V_120 ) ;
}
static void F_59 ( struct V_117 * V_118 )
{
F_57 ( F_34 ( & V_118 -> V_120 ) <= 0 ) ;
if ( F_60 ( & V_118 -> V_120 ) )
F_20 ( V_118 ) ;
}
static void F_61 ( struct V_122 * V_123 , int V_26 ,
struct V_1 * V_2 )
{
char * V_124 ;
int V_125 = V_123 -> V_126 . V_127 ;
V_124 = F_62 ( V_125 ) ;
if ( V_26 )
F_50 ( 2 , L_52
L_53 ,
V_124 , V_125 , F_51 ( & V_2 -> V_72 -> V_73 ) ,
F_63 ( V_2 ) , V_26 ,
F_64 ( V_26 ) ) ;
else
F_50 ( 5 , L_54 ,
V_124 , V_125 , F_51 ( & V_2 -> V_72 -> V_73 ) ,
F_63 ( V_2 ) ) ;
}
static struct V_122 * F_65 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_122 * V_123 = NULL ;
F_11 ( V_2 , 5 , L_55 ) ;
if ( F_66 ( V_106 -> V_110 ) ) {
V_123 = (struct V_122 * ) F_67 ( V_106 -> V_110 ) ;
if ( F_68 ( V_123 ) ) {
if ( V_123 -> V_126 . V_127 != V_128 &&
V_123 -> V_126 . V_127 != V_129 &&
V_123 -> V_126 . V_127 != V_130 &&
V_123 -> V_126 . V_127 != V_131 )
F_61 ( V_123 ,
V_123 -> V_126 . V_132 , V_2 ) ;
return V_123 ;
} else {
switch ( V_123 -> V_126 . V_127 ) {
case V_133 :
F_49 ( & V_2 -> V_72 -> V_73 ,
L_56
L_57 ,
F_63 ( V_2 ) ,
V_2 -> V_3 . V_134 ) ;
V_2 -> V_135 = 0 ;
if ( V_2 -> V_73 && F_69 ( V_2 -> V_73 ) )
F_70 ( V_2 -> V_73 ) ;
return NULL ;
case V_136 :
F_71 ( & V_2 -> V_72 -> V_73 ,
L_58
L_59 ,
F_63 ( V_2 ) ,
V_2 -> V_3 . V_134 ) ;
F_72 ( V_2 -> V_73 ) ;
V_2 -> V_135 = 1 ;
if ( V_2 -> V_3 . V_137 )
V_2 -> V_3 . V_137 = 2 ;
F_54 ( V_2 ) ;
return NULL ;
case V_130 :
return V_123 ;
case V_138 :
F_11 ( V_2 , 3 , L_60 ) ;
break;
case V_139 :
F_11 ( V_2 , 3 , L_61 ) ;
break;
default:
F_50 ( 2 , L_62
L_63 ) ;
break;
}
}
}
return V_123 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_117 * V_118 , * V_140 ;
unsigned long V_21 ;
F_11 ( V_2 , 4 , L_64 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_12 (reply, r, &card->cmd_waiter_list, list) {
F_56 ( V_118 ) ;
V_118 -> V_26 = - V_109 ;
F_58 ( & V_118 -> V_121 ) ;
F_74 ( & V_118 -> V_31 ) ;
F_6 ( & V_118 -> V_25 ) ;
F_59 ( V_118 ) ;
}
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_42 ( & V_2 -> V_142 . V_115 , 0 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
unsigned char * V_66 )
{
if ( ! V_66 )
return 0 ;
F_29 ( V_143 , 2 , V_66 , V_144 ) ;
if ( ( V_66 [ 2 ] & 0xc0 ) == 0xc0 ) {
F_50 ( 2 , L_65
L_66 ,
V_66 [ 4 ] ,
( ( V_66 [ 4 ] == 0x22 ) ?
L_67 : L_68 ) ) ;
F_11 ( V_2 , 2 , L_69 ) ;
F_11 ( V_2 , 2 , L_70 ) ;
F_35 ( V_2 , 2 , L_71 , - V_109 ) ;
if ( V_66 [ 4 ] == 0xf6 ) {
F_30 ( & V_2 -> V_72 -> V_73 ,
L_72
L_73 ) ;
return - V_47 ;
}
return - V_109 ;
}
return 0 ;
}
static void F_52 ( struct V_145 * V_146 , unsigned char * V_106 ,
T_1 V_147 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 4 , L_74 ) ;
if ( V_146 == & V_2 -> V_107 )
memcpy ( & V_146 -> V_113 , V_148 , sizeof( struct V_149 ) ) ;
else
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_147 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_77 ( V_106 ) ;
}
static struct V_105 * F_78 ( struct V_145 * V_146 )
{
T_2 V_153 ;
F_11 ( F_76 ( V_146 -> V_112 ) , 6 , L_75 ) ;
V_153 = V_146 -> V_154 ;
do {
if ( V_146 -> V_106 [ V_153 ] . V_44 == V_155 ) {
V_146 -> V_106 [ V_153 ] . V_44 = V_156 ;
V_146 -> V_154 = ( V_146 -> V_154 + 1 ) %
V_157 ;
memset ( V_146 -> V_106 [ V_153 ] . V_110 , 0 , V_111 ) ;
return V_146 -> V_106 + V_153 ;
}
V_153 = ( V_153 + 1 ) % V_157 ;
} while ( V_153 != V_146 -> V_154 );
return NULL ;
}
void F_79 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
unsigned long V_21 ;
F_11 ( F_76 ( V_146 -> V_112 ) , 6 , L_76 ) ;
F_4 ( & V_146 -> V_158 , V_21 ) ;
memset ( V_106 -> V_110 , 0 , V_111 ) ;
V_106 -> V_44 = V_155 ;
V_106 -> V_159 = V_160 ;
V_106 -> V_26 = 0 ;
F_5 ( & V_146 -> V_158 , V_21 ) ;
}
static struct V_105 * F_48 ( struct V_145 * V_146 )
{
struct V_105 * V_66 = NULL ;
unsigned long V_21 ;
F_4 ( & V_146 -> V_158 , V_21 ) ;
V_66 = F_78 ( V_146 ) ;
F_5 ( & V_146 -> V_158 , V_21 ) ;
return V_66 ;
}
struct V_105 * F_80 ( struct V_145 * V_146 )
{
struct V_105 * V_66 ;
F_81 ( V_146 -> V_25 ,
( ( V_66 = F_48 ( V_146 ) ) != NULL ) ) ;
return V_66 ;
}
void F_82 ( struct V_145 * V_146 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ )
F_79 ( V_146 , & V_146 -> V_106 [ V_161 ] ) ;
V_146 -> V_162 = 0 ;
V_146 -> V_154 = 0 ;
}
static void V_160 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
struct V_117 * V_118 , * V_140 ;
struct V_122 * V_123 ;
unsigned long V_21 ;
int V_163 ;
int V_26 = 0 ;
V_2 = F_76 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 4 , L_77 ) ;
V_26 = F_75 ( V_2 , V_106 -> V_110 ) ;
switch ( V_26 ) {
case 0 :
break;
case - V_109 :
F_73 ( V_2 ) ;
F_54 ( V_2 ) ;
default:
goto V_60;
}
V_123 = F_65 ( V_2 , V_106 ) ;
if ( ( V_123 == NULL ) && ( V_2 -> V_44 != V_45 ) )
goto V_60;
if ( V_2 -> V_3 . type == V_9 &&
V_123 &&
V_123 -> V_126 . V_127 != V_136 &&
V_2 -> V_164 . V_165 != NULL ) {
V_2 -> V_164 . V_165 ( V_2 -> V_73 , V_123 ) ;
goto V_60;
}
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_12 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_118 -> V_166 == V_167 ) ||
( ( V_123 ) && ( V_118 -> V_166 == V_123 -> V_126 . V_166 ) ) ) {
F_56 ( V_118 ) ;
F_74 ( & V_118 -> V_31 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
V_163 = 0 ;
if ( V_118 -> V_159 != NULL ) {
if ( V_123 ) {
V_118 -> V_168 = ( V_169 ) ( ( char * ) V_123 -
( char * ) V_106 -> V_110 ) ;
V_163 = V_118 -> V_159 ( V_2 ,
V_118 ,
( unsigned long ) V_123 ) ;
} else
V_163 = V_118 -> V_159 ( V_2 ,
V_118 ,
( unsigned long ) V_106 ) ;
}
if ( V_123 )
V_118 -> V_26 = ( V_170 ) V_123 -> V_126 . V_132 ;
else if ( V_106 -> V_26 )
V_118 -> V_26 = V_106 -> V_26 ;
if ( V_163 ) {
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_83 ( & V_118 -> V_31 ,
& V_2 -> V_171 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
} else {
F_58 ( & V_118 -> V_121 ) ;
F_6 ( & V_118 -> V_25 ) ;
}
F_59 ( V_118 ) ;
goto V_60;
}
}
F_5 ( & V_2 -> V_141 , V_21 ) ;
V_60:
memcpy ( & V_2 -> V_166 . V_172 ,
F_84 ( V_106 -> V_110 ) ,
V_173 ) ;
F_79 ( V_146 , V_106 ) ;
}
static int F_85 ( struct V_145 * V_146 )
{
int V_161 ;
F_24 ( V_52 , 2 , L_78 ) ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ ) {
V_146 -> V_106 [ V_161 ] . V_110 =
F_15 ( V_111 , V_174 | V_38 ) ;
if ( V_146 -> V_106 [ V_161 ] . V_110 == NULL )
break;
V_146 -> V_106 [ V_161 ] . V_44 = V_155 ;
V_146 -> V_106 [ V_161 ] . V_146 = V_146 ;
V_146 -> V_106 [ V_161 ] . V_159 = V_160 ;
V_146 -> V_106 [ V_161 ] . V_26 = 0 ;
}
if ( V_161 < V_157 ) {
while ( V_161 -- > 0 )
F_20 ( V_146 -> V_106 [ V_161 ] . V_110 ) ;
return - V_39 ;
}
V_146 -> V_162 = 0 ;
V_146 -> V_154 = 0 ;
F_42 ( & V_146 -> V_115 , 0 ) ;
F_86 ( & V_146 -> V_158 ) ;
F_87 ( & V_146 -> V_25 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
unsigned long V_175 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
if ( ! ( V_2 -> V_23 & V_175 ) ||
( V_2 -> V_24 & V_175 ) ) {
F_5 ( & V_2 -> V_22 , V_21 ) ;
return - V_47 ;
}
V_2 -> V_24 |= V_175 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_24 &= ~ V_175 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
void F_90 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_27 &= ~ V_175 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
static int F_91 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
if ( V_2 -> V_24 & V_175 ) {
if ( ( V_2 -> V_23 & V_175 ) &&
! ( V_2 -> V_27 & V_175 ) ) {
V_26 = 1 ;
V_2 -> V_24 &= ~ V_175 ;
V_2 -> V_27 |= V_175 ;
} else
V_26 = - V_47 ;
}
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
int F_92 ( struct V_1 * V_2 , unsigned long V_175 )
{
int V_26 = 0 ;
F_81 ( V_2 -> V_25 ,
( V_26 = F_91 ( V_2 , V_175 ) ) >= 0 ) ;
return V_26 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 2 , L_79 ) ;
if ( F_88 ( V_2 , V_176 ) == 0 )
F_93 ( & V_2 -> V_177 ) ;
}
static int F_94 ( struct V_178 * V_179 , struct V_180 * V_180 )
{
int V_181 , V_182 ;
char * V_183 ;
struct V_1 * V_2 ;
V_183 = ( char * ) V_180 -> V_184 ;
V_182 = V_180 -> V_185 . V_123 . V_182 ;
V_181 = V_180 -> V_185 . V_123 . V_181 ;
V_2 = F_76 ( V_179 ) ;
if ( V_182 & ( V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 ) ) {
F_11 ( V_2 , 2 , L_80 ) ;
F_49 ( & V_179 -> V_73 , L_45
L_46 ) ;
F_50 ( 2 , L_81 ,
F_51 ( & V_179 -> V_73 ) , V_181 , V_182 ) ;
F_95 ( V_192 , L_82 , V_193 ,
16 , 1 , V_180 , 64 , 1 ) ;
return 1 ;
}
if ( V_181 & V_194 ) {
if ( V_183 [ V_195 ] &
V_196 ) {
F_11 ( V_2 , 2 , L_83 ) ;
return 1 ;
}
if ( V_183 [ V_197 ] &
V_198 ) {
F_11 ( V_2 , 2 , L_84 ) ;
return 1 ;
}
if ( ( V_183 [ 2 ] == 0xaf ) && ( V_183 [ 3 ] == 0xfe ) ) {
F_11 ( V_2 , 2 , L_85 ) ;
return 1 ;
}
if ( ( ! V_183 [ 0 ] ) && ( ! V_183 [ 1 ] ) && ( ! V_183 [ 2 ] ) && ( ! V_183 [ 3 ] ) ) {
F_11 ( V_2 , 2 , L_86 ) ;
return 0 ;
}
F_11 ( V_2 , 2 , L_87 ) ;
return 1 ;
}
return 0 ;
}
static long F_96 ( struct V_178 * V_179 ,
unsigned long V_199 , struct V_180 * V_180 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_179 ) ;
if ( ! F_97 ( V_180 ) )
return 0 ;
switch ( F_98 ( V_180 ) ) {
case - V_109 :
F_50 ( 2 , L_88 ,
F_51 ( & V_179 -> V_73 ) ) ;
F_11 ( V_2 , 2 , L_89 ) ;
F_35 ( V_2 , 2 , L_71 , - V_109 ) ;
break;
case - V_200 :
F_49 ( & V_179 -> V_73 , L_90
L_91 ) ;
F_11 ( V_2 , 2 , L_89 ) ;
F_35 ( V_2 , 2 , L_71 , - V_200 ) ;
if ( V_199 == V_201 ) {
if ( V_2 && ( V_2 -> V_110 . V_112 == V_179 ) ) {
V_2 -> V_110 . V_44 = V_202 ;
F_6 ( & V_2 -> V_25 ) ;
}
}
break;
default:
F_50 ( 2 , L_92 ,
F_51 ( & V_179 -> V_73 ) , F_98 ( V_180 ) ) ;
F_11 ( V_2 , 2 , L_89 ) ;
F_11 ( V_2 , 2 , L_93 ) ;
}
return F_98 ( V_180 ) ;
}
static void F_99 ( struct V_178 * V_179 , unsigned long V_199 ,
struct V_180 * V_180 )
{
int V_26 ;
int V_182 , V_181 ;
struct V_105 * V_66 ;
struct V_145 * V_146 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
T_2 V_153 ;
if ( F_96 ( V_179 , V_199 , V_180 ) )
return;
V_182 = V_180 -> V_185 . V_123 . V_182 ;
V_181 = V_180 -> V_185 . V_123 . V_181 ;
V_2 = F_76 ( V_179 ) ;
if ( ! V_2 )
return;
F_11 ( V_2 , 5 , L_94 ) ;
if ( V_2 -> V_107 . V_112 == V_179 ) {
V_146 = & V_2 -> V_107 ;
F_11 ( V_2 , 5 , L_95 ) ;
} else if ( V_2 -> V_142 . V_112 == V_179 ) {
V_146 = & V_2 -> V_142 ;
F_11 ( V_2 , 5 , L_96 ) ;
} else {
V_146 = & V_2 -> V_110 ;
F_11 ( V_2 , 5 , L_97 ) ;
}
F_42 ( & V_146 -> V_115 , 0 ) ;
if ( V_180 -> V_185 . V_123 . V_203 & ( V_204 ) )
V_146 -> V_44 = V_205 ;
if ( V_180 -> V_185 . V_123 . V_203 & ( V_206 ) )
V_146 -> V_44 = V_207 ;
if ( ( V_146 == & V_2 -> V_110 ) && ( V_199 != 0 ) &&
( V_199 != V_201 ) )
goto V_60;
if ( V_199 == V_208 ) {
F_11 ( V_2 , 6 , L_98 ) ;
V_199 = 0 ;
}
if ( V_199 == V_209 ) {
F_11 ( V_2 , 6 , L_99 ) ;
V_199 = 0 ;
}
if ( ( V_181 & V_210 ) ||
( V_181 & V_194 ) ||
( V_182 ) ) {
if ( V_180 -> V_211 . V_212 . V_213 . V_214 ) {
F_49 ( & V_146 -> V_112 -> V_73 ,
L_100
L_101 ) ;
F_50 ( 2 , L_102
L_103 ,
F_51 ( & V_146 -> V_112 -> V_73 ) , V_182 , V_181 ) ;
F_95 ( V_192 , L_82 ,
V_193 , 16 , 1 , V_180 , 32 , 1 ) ;
F_95 ( V_192 , L_104 ,
V_193 , 16 , 1 , V_180 -> V_184 , 32 , 1 ) ;
}
if ( V_199 == V_201 ) {
V_146 -> V_44 = V_202 ;
goto V_60;
}
V_26 = F_94 ( V_179 , V_180 ) ;
if ( V_26 ) {
F_73 ( V_2 ) ;
F_54 ( V_2 ) ;
goto V_60;
}
}
if ( V_199 == V_201 ) {
V_146 -> V_44 = V_215 ;
goto V_60;
}
if ( V_199 ) {
V_66 = (struct V_105 * ) F_100 ( ( V_114 ) V_199 ) ;
V_66 -> V_44 = V_216 ;
}
if ( V_146 == & V_2 -> V_110 )
return;
if ( V_146 == & V_2 -> V_107 &&
V_146 -> V_44 == V_108 )
F_47 ( V_2 ) ;
V_106 = V_146 -> V_106 ;
V_153 = V_146 -> V_162 ;
while ( V_106 [ V_153 ] . V_44 == V_216 ) {
if ( V_106 [ V_153 ] . V_159 != NULL )
V_106 [ V_153 ] . V_159 ( V_146 , V_106 + V_153 ) ;
V_153 = ( V_153 + 1 ) % V_157 ;
}
V_146 -> V_162 = V_153 ;
V_60:
F_6 ( & V_2 -> V_25 ) ;
return;
}
static void F_43 ( struct V_84 * V_85 ,
struct V_89 * V_217 ,
enum V_74 V_98 )
{
struct V_218 * V_219 ;
if ( F_101 ( & V_217 -> V_220 ) )
goto V_60;
V_219 = F_102 ( & V_217 -> V_220 ) ;
while ( V_219 ) {
F_35 ( V_85 -> V_2 , 5 , L_105 , V_98 ) ;
F_35 ( V_85 -> V_2 , 5 , L_41 , ( long ) V_219 ) ;
if ( V_219 -> V_221 == V_222 ) {
if ( V_219 -> V_223 ) {
struct V_224 * V_225 = F_103 ( V_219 -> V_223 ) ;
V_225 -> V_226 ( V_219 , V_98 ) ;
}
}
if ( F_104 ( & V_217 -> V_220 , V_219 ) )
V_219 = NULL ;
else
V_219 = F_105 ( & V_217 -> V_220 , V_219 ) ;
}
V_60:
return;
}
static void F_36 ( struct V_89 * V_217 )
{
struct V_218 * V_219 ;
V_219 = F_106 ( & V_217 -> V_220 ) ;
while ( V_219 ) {
F_11 ( V_217 -> V_85 -> V_2 , 5 , L_106 ) ;
F_35 ( V_217 -> V_85 -> V_2 , 5 , L_41 , ( long ) V_219 ) ;
F_107 ( & V_219 -> V_227 ) ;
F_108 ( V_219 ) ;
V_219 = F_106 ( & V_217 -> V_220 ) ;
}
}
static void F_44 ( struct V_84 * V_104 ,
struct V_89 * V_217 ,
enum V_228 V_229 )
{
int V_33 ;
if ( V_217 -> V_66 -> V_230 [ 0 ] . V_231 & V_232 )
F_107 ( & V_104 -> V_233 ) ;
if ( V_229 == V_234 ) {
F_36 ( V_217 ) ;
}
for ( V_33 = 0 ; V_33 < F_17 ( V_104 -> V_2 ) ; ++ V_33 ) {
if ( V_217 -> V_66 -> V_230 [ V_33 ] . V_235 && V_217 -> V_236 [ V_33 ] )
F_38 ( V_237 ,
V_217 -> V_66 -> V_230 [ V_33 ] . V_235 ) ;
V_217 -> V_236 [ V_33 ] = 0 ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_238 = 0 ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_235 = NULL ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_239 = 0 ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_231 = 0 ;
}
V_217 -> V_66 -> V_230 [ 15 ] . V_239 = 0 ;
V_217 -> V_66 -> V_230 [ 15 ] . V_231 = 0 ;
V_217 -> V_240 = 0 ;
F_42 ( & V_217 -> V_44 , V_229 ) ;
}
static void F_109 ( struct V_84 * V_85 , int free )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
if ( ! V_85 -> V_65 [ V_34 ] )
continue;
F_33 ( V_85 , V_34 , free ) ;
F_44 ( V_85 , V_85 -> V_65 [ V_34 ] , V_234 ) ;
if ( free ) {
F_38 ( V_94 , V_85 -> V_65 [ V_34 ] ) ;
V_85 -> V_65 [ V_34 ] = NULL ;
}
}
}
void F_110 ( struct V_1 * V_2 )
{
int V_33 ;
F_11 ( V_2 , 2 , L_107 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
if ( V_2 -> V_35 . V_70 [ V_33 ] ) {
F_109 ( V_2 -> V_35 . V_70 [ V_33 ] , 0 ) ;
}
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_30 ;
int V_33 = 0 ;
F_12 (pool_entry, tmp,
&card->qdio.init_pool.entry_list, init_list) {
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 )
F_19 ( ( unsigned long ) V_29 -> V_40 [ V_33 ] ) ;
F_13 ( & V_29 -> V_41 ) ;
F_20 ( V_29 ) ;
}
}
static void F_111 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
if ( F_112 ( & V_2 -> V_35 . V_44 , V_241 ) ==
V_241 )
return;
F_31 ( V_2 ) ;
F_113 ( & V_2 -> V_242 ) ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 )
F_114 ( V_2 -> V_35 . V_243 -> V_65 [ V_34 ] . V_244 ) ;
F_20 ( V_2 -> V_35 . V_243 ) ;
V_2 -> V_35 . V_243 = NULL ;
F_16 ( V_2 ) ;
if ( V_2 -> V_35 . V_70 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
F_109 ( V_2 -> V_35 . V_70 [ V_33 ] , 1 ) ;
F_20 ( V_2 -> V_35 . V_70 [ V_33 ] ) ;
}
F_20 ( V_2 -> V_35 . V_70 ) ;
V_2 -> V_35 . V_70 = NULL ;
}
}
static void F_115 ( struct V_145 * V_146 )
{
int V_161 ;
F_24 ( V_52 , 2 , L_108 ) ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ )
F_20 ( V_146 -> V_106 [ V_161 ] . V_110 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_178 * V_112 ;
struct V_245 {
T_3 V_21 ;
T_3 V_246 ;
T_3 V_247 ;
T_3 V_134 ;
T_3 V_248 ;
T_3 V_249 ;
T_3 V_250 ;
T_3 V_251 ;
} * V_252 ;
F_24 ( V_52 , 2 , L_109 ) ;
V_112 = V_2 -> V_110 . V_112 ;
V_252 = (struct V_245 * ) F_117 ( V_112 , 0 ) ;
if ( V_252 != NULL ) {
if ( V_2 -> V_3 . type != V_6 ) {
if ( ( V_252 -> V_251 & 0x02 ) == 0x02 ) {
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) !=
V_241 ) &&
( V_2 -> V_35 . V_68 == 4 ) )
F_111 ( V_2 ) ;
V_2 -> V_35 . V_68 = 1 ;
if ( V_2 -> V_35 . V_253 != 0 )
F_71 ( & V_2 -> V_72 -> V_73 ,
L_110 ) ;
V_2 -> V_35 . V_253 = 0 ;
} else {
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) !=
V_241 ) &&
( V_2 -> V_35 . V_68 == 1 ) ) {
F_111 ( V_2 ) ;
V_2 -> V_35 . V_253 = 2 ;
}
V_2 -> V_35 . V_68 = 4 ;
}
}
V_2 -> V_3 . V_254 = 0x4100 + V_252 -> V_247 ;
F_20 ( V_252 ) ;
}
F_27 ( V_52 , 2 , L_111 , V_2 -> V_35 . V_68 ) ;
F_27 ( V_52 , 2 , L_112 , V_2 -> V_3 . V_254 ) ;
return;
}
static void F_118 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 4 , L_113 ) ;
F_42 ( & V_2 -> V_35 . V_44 , V_241 ) ;
V_2 -> V_35 . V_255 = V_256 ;
if ( V_2 -> V_3 . type == V_6 )
V_2 -> V_35 . V_36 . V_37 = V_257 ;
else
V_2 -> V_35 . V_36 . V_37 = V_258 ;
V_2 -> V_35 . V_48 . V_37 = V_2 -> V_35 . V_36 . V_37 ;
F_119 ( & V_2 -> V_35 . V_48 . V_42 ) ;
F_119 ( & V_2 -> V_35 . V_36 . V_42 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
V_2 -> V_49 . V_259 . type = V_260 ;
V_2 -> V_49 . V_261 . type = V_260 ;
V_2 -> V_49 . V_262 = V_263 ;
V_2 -> V_49 . V_264 = V_265 ;
V_2 -> V_49 . V_266 = 0 ;
V_2 -> V_49 . V_267 = V_268 ;
V_2 -> V_49 . V_269 = 0 ;
V_2 -> V_49 . V_270 = V_271 ;
V_2 -> V_49 . V_272 = V_273 ;
V_2 -> V_49 . V_50 = V_274 ;
}
static int F_121 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
F_35 ( V_2 , 4 , L_114 ,
( T_3 ) V_2 -> V_24 ,
( T_3 ) V_2 -> V_23 ,
( T_3 ) V_2 -> V_27 ) ;
V_26 = ( V_2 -> V_24 & V_175 ) ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
static void F_122 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = F_123 ( V_276 , struct V_1 ,
V_177 ) ;
F_11 ( V_2 , 2 , L_115 ) ;
if ( V_2 -> V_107 . V_44 != V_108 &&
V_2 -> V_142 . V_44 != V_108 )
return;
if ( F_121 ( V_2 , V_176 ) )
F_124 ( V_2 -> V_277 . V_278 , ( void * ) V_2 ,
L_116 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_117 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_107 . V_44 = V_202 ;
V_2 -> V_142 . V_44 = V_202 ;
V_2 -> V_110 . V_44 = V_202 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_135 = 0 ;
V_2 -> V_116 = 0 ;
V_2 -> V_73 = NULL ;
F_86 ( & V_2 -> V_279 ) ;
F_86 ( & V_2 -> V_280 ) ;
F_86 ( & V_2 -> V_141 ) ;
F_86 ( & V_2 -> V_281 ) ;
F_86 ( & V_2 -> V_22 ) ;
F_126 ( & V_2 -> V_282 ) ;
F_126 ( & V_2 -> V_283 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_27 = 0 ;
F_127 ( & V_2 -> V_177 , F_122 ) ;
F_119 ( & V_2 -> V_284 ) ;
F_119 ( V_2 -> V_285 ) ;
F_119 ( & V_2 -> V_171 ) ;
F_87 ( & V_2 -> V_25 ) ;
F_120 ( V_2 ) ;
F_119 ( & V_2 -> V_286 . V_287 ) ;
V_2 -> V_286 . V_288 = 0 ;
V_2 -> V_286 . V_289 = 0 ;
V_2 -> V_286 . V_290 = 0 ;
F_118 ( V_2 ) ;
F_128 ( & V_2 -> V_242 , V_291 ) ;
return 0 ;
}
static void F_129 ( struct V_292 * V_293 , struct V_294 * V_295 )
{
struct V_1 * V_2 = F_123 ( V_295 , struct V_1 ,
V_296 ) ;
if ( V_2 -> V_3 . V_297 [ 0 ] )
F_130 ( V_293 , L_118 ,
F_131 ( V_2 ) , V_2 -> V_3 . V_297 ) ;
}
static struct V_1 * F_132 ( void )
{
struct V_1 * V_2 ;
F_24 ( V_52 , 2 , L_119 ) ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_174 | V_38 ) ;
if ( ! V_2 )
goto V_60;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_285 = F_15 ( sizeof( struct V_298 ) , V_38 ) ;
if ( ! V_2 -> V_285 ) {
F_24 ( V_52 , 0 , L_120 ) ;
goto V_299;
}
if ( F_85 ( & V_2 -> V_107 ) )
goto V_300;
if ( F_85 ( & V_2 -> V_142 ) )
goto V_301;
V_2 -> V_49 . V_302 = - 1 ;
V_2 -> V_296 . V_303 = F_129 ;
F_133 ( & V_2 -> V_296 ) ;
return V_2 ;
V_301:
F_115 ( & V_2 -> V_107 ) ;
V_300:
F_20 ( V_2 -> V_285 ) ;
V_299:
F_20 ( V_2 ) ;
V_60:
return NULL ;
}
static int F_134 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
F_24 ( V_52 , 2 , L_121 ) ;
V_2 -> V_35 . V_304 = V_305 ;
V_2 -> V_35 . V_253 = V_306 ;
while ( V_307 [ V_33 ] [ V_308 ] ) {
if ( ( F_135 ( V_2 ) -> V_309 . V_310 ==
V_307 [ V_33 ] [ V_311 ] ) &&
( F_135 ( V_2 ) -> V_309 . V_312 ==
V_307 [ V_33 ] [ V_308 ] ) ) {
V_2 -> V_3 . type = V_307 [ V_33 ] [ V_308 ] ;
V_2 -> V_35 . V_68 =
V_307 [ V_33 ] [ V_313 ] ;
V_2 -> V_35 . V_59 = 1 ;
V_2 -> V_3 . V_314 =
V_307 [ V_33 ] [ V_315 ] ;
F_116 ( V_2 ) ;
return 0 ;
}
V_33 ++ ;
}
V_2 -> V_3 . type = V_316 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_122
L_123 ) ;
return - V_317 ;
}
static int F_136 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_76 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_124 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_138 ( V_146 -> V_112 , V_208 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_205 , V_318 ) ;
if ( V_26 == - V_319 )
return V_26 ;
if ( V_146 -> V_44 != V_205 )
return - V_320 ;
V_146 -> V_44 = V_202 ;
return 0 ;
}
static int F_140 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_76 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_125 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_141 ( V_146 -> V_112 , V_209 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_207 , V_318 ) ;
if ( V_26 == - V_319 )
return V_26 ;
if ( V_146 -> V_44 != V_207 )
return - V_320 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
int V_321 = 0 , V_322 = 0 , V_323 = 0 ;
F_11 ( V_2 , 3 , L_126 ) ;
V_321 = F_140 ( & V_2 -> V_107 ) ;
V_322 = F_140 ( & V_2 -> V_142 ) ;
V_323 = F_140 ( & V_2 -> V_110 ) ;
if ( V_321 )
return V_321 ;
if ( V_322 )
return V_322 ;
return V_323 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_321 = 0 , V_322 = 0 , V_323 = 0 ;
F_11 ( V_2 , 3 , L_127 ) ;
V_321 = F_136 ( & V_2 -> V_107 ) ;
V_322 = F_136 ( & V_2 -> V_142 ) ;
V_323 = F_136 ( & V_2 -> V_110 ) ;
if ( V_321 )
return V_321 ;
if ( V_322 )
return V_322 ;
return V_323 ;
}
static int F_144 ( struct V_1 * V_2 , int V_324 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_128 ) ;
if ( V_324 )
V_26 = F_142 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_143 ( V_2 ) ;
}
int F_145 ( struct V_1 * V_2 , int V_325 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_129 ) ;
switch ( F_41 ( & V_2 -> V_35 . V_44 , V_326 ,
V_327 ) ) {
case V_326 :
if ( V_2 -> V_3 . type == V_6 )
V_26 = F_146 ( F_26 ( V_2 ) ,
V_328 ) ;
else
V_26 = F_146 ( F_26 ( V_2 ) ,
V_329 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_35 , V_26 ) ;
F_147 ( F_26 ( V_2 ) ) ;
F_42 ( & V_2 -> V_35 . V_44 , V_330 ) ;
break;
case V_327 :
return V_26 ;
default:
break;
}
V_26 = F_144 ( V_2 , V_325 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_130 , V_26 ) ;
V_2 -> V_44 = V_45 ;
return V_26 ;
}
static int F_148 ( struct V_1 * V_2 , void * * V_66 ,
int * V_238 )
{
struct V_331 * V_331 ;
char * V_332 ;
int V_333 ;
struct V_145 * V_146 = & V_2 -> V_110 ;
unsigned long V_21 ;
V_331 = F_149 ( V_146 -> V_112 , V_334 ) ;
if ( ! V_331 || V_331 -> V_123 == 0 )
return - V_335 ;
V_332 = F_15 ( V_331 -> V_151 , V_38 | V_174 ) ;
if ( ! V_332 )
return - V_39 ;
V_146 -> V_113 . V_336 = V_331 -> V_123 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_77 ( V_332 ) ;
V_146 -> V_113 . V_151 = V_331 -> V_151 ;
V_146 -> V_113 . V_21 = V_337 ;
V_146 -> V_44 = V_338 ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_333 = F_150 ( V_146 -> V_112 , & V_146 -> V_113 ,
V_201 , V_339 , 0 ,
V_340 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( ! V_333 )
F_81 ( V_2 -> V_25 ,
( V_146 -> V_44 == V_215 ||
V_146 -> V_44 == V_202 ) ) ;
if ( V_146 -> V_44 == V_202 )
V_333 = - V_109 ;
else
V_146 -> V_44 = V_202 ;
if ( V_333 ) {
F_20 ( V_332 ) ;
* V_66 = NULL ;
* V_238 = 0 ;
} else {
* V_238 = V_331 -> V_151 ;
* V_66 = V_332 ;
}
return V_333 ;
}
static void F_151 ( struct V_1 * V_2 , char * V_341 )
{
F_24 ( V_52 , 2 , L_131 ) ;
V_2 -> V_3 . V_134 = V_341 [ 30 ] ;
V_2 -> V_3 . V_342 = V_341 [ 31 ] ;
V_2 -> V_3 . V_343 = V_341 [ 63 ] ;
V_2 -> V_3 . V_4 = ( ( V_341 [ 0x10 ] == V_344 [ 'V' ] ) &&
( V_341 [ 0x11 ] == V_344 [ 'M' ] ) ) ;
}
static void F_152 ( struct V_1 * V_2 , char * V_341 )
{
F_24 ( V_52 , 2 , L_132 ) ;
if ( V_341 [ 74 ] == 0xF0 && V_341 [ 75 ] == 0xF0 && V_341 [ 76 ] == 0xF5 ) {
V_2 -> V_3 . V_345 . V_346 = 250 ;
V_2 -> V_3 . V_345 . V_347 = 5 ;
V_2 -> V_3 . V_345 . V_348 = 15 ;
} else {
V_2 -> V_3 . V_345 . V_346 = 0 ;
V_2 -> V_3 . V_345 . V_347 = 0 ;
V_2 -> V_3 . V_345 . V_348 = 0 ;
}
}
static void F_153 ( struct V_1 * V_2 )
{
V_2 -> V_349 . V_350 = 0x00010103UL ;
V_2 -> V_349 . V_351 = 0x00010108UL ;
V_2 -> V_349 . V_352 = 0x0001010aUL ;
V_2 -> V_349 . V_353 = 0x0001010bUL ;
V_2 -> V_349 . V_354 = 0x0001010dUL ;
}
static void F_154 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
V_2 -> V_3 . V_254 = V_355 ;
break;
case V_5 :
case V_9 :
V_2 -> V_3 . V_254 = V_356 ;
break;
default:
break;
}
}
static int F_155 ( struct V_145 * V_146 ,
void (* F_156)( struct V_145 * ,
struct V_105 * ) )
{
struct V_105 * V_106 ;
unsigned long V_21 ;
int V_26 ;
struct V_1 * V_2 ;
F_24 ( V_52 , 2 , L_133 ) ;
V_2 = F_76 ( V_146 -> V_112 ) ;
V_106 = F_48 ( V_146 ) ;
V_106 -> V_159 = F_156 ;
memcpy ( & V_146 -> V_113 , V_148 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_111 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_77 ( V_106 -> V_110 ) ;
F_81 ( V_2 -> V_25 ,
F_41 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_49 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_53 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_50 ( 2 , L_134 , V_26 ) ;
F_27 ( V_52 , 2 , L_130 , V_26 ) ;
F_42 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_108 , V_318 ) ;
if ( V_26 == - V_319 )
return V_26 ;
if ( V_146 -> V_44 != V_108 ) {
V_26 = - V_320 ;
F_27 ( V_52 , 2 , L_135 , V_26 ) ;
F_82 ( V_146 ) ;
} else
V_26 = 0 ;
return V_26 ;
}
static int F_157 ( struct V_145 * V_146 ,
void (* F_156)( struct V_145 * ,
struct V_105 * ) )
{
struct V_1 * V_2 ;
struct V_105 * V_106 ;
unsigned long V_21 ;
V_169 V_357 ;
T_2 V_30 ;
int V_26 ;
struct V_358 V_359 ;
V_2 = F_76 ( V_146 -> V_112 ) ;
F_24 ( V_52 , 2 , L_136 ) ;
V_106 = F_48 ( V_146 ) ;
V_106 -> V_159 = F_156 ;
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_360 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_77 ( V_106 -> V_110 ) ;
if ( V_146 == & V_2 -> V_142 ) {
memcpy ( V_106 -> V_110 , V_361 , V_360 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_362 , V_173 ) ;
V_2 -> V_166 . V_362 ++ ;
} else {
memcpy ( V_106 -> V_110 , V_363 , V_360 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_362 , V_173 ) ;
}
V_30 = ( ( T_2 ) V_2 -> V_3 . V_364 ) | 0x80 ;
memcpy ( F_159 ( V_106 -> V_110 ) , & V_30 , 1 ) ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_350 , V_365 ) ;
memcpy ( F_161 ( V_106 -> V_110 ) ,
& V_2 -> V_3 . V_254 , sizeof( V_169 ) ) ;
F_162 ( F_26 ( V_2 ) , & V_359 ) ;
memcpy ( F_163 ( V_106 -> V_110 ) , & V_359 . V_366 , 2 ) ;
V_357 = ( V_2 -> V_3 . V_343 << 8 ) + V_2 -> V_3 . V_342 ;
memcpy ( F_164 ( V_106 -> V_110 ) , & V_357 , 2 ) ;
F_81 ( V_2 -> V_25 ,
F_41 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_49 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_53 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_50 ( 2 , L_137 ,
V_26 ) ;
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
F_42 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_367 , V_318 ) ;
if ( V_26 == - V_319 )
return V_26 ;
if ( V_146 -> V_44 != V_367 ) {
F_49 ( & V_146 -> V_112 -> V_73 , L_138
L_139 ) ;
F_50 ( 2 , L_140 ,
F_51 ( & V_146 -> V_112 -> V_73 ) ) ;
F_27 ( V_52 , 2 , L_130 , - V_320 ) ;
F_82 ( V_146 ) ;
return - V_320 ;
}
return F_155 ( V_146 , F_156 ) ;
}
static int F_165 ( int V_368 )
{
if ( ( V_368 & 0xff ) == 8 )
return ( V_368 & 0xff ) + 0x400 ;
if ( ( ( V_368 >> 8 ) & 3 ) == 1 )
return ( V_368 & 0xff ) + 0x200 ;
return V_368 ;
}
static void F_166 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_357 ;
F_24 ( V_52 , 2 , L_141 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_367 ;
goto V_60;
}
V_2 = F_76 ( V_146 -> V_112 ) ;
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
if ( F_168 ( V_106 -> V_110 ) == V_369 )
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_142
L_143 ) ;
else
F_50 ( 2 , L_144
L_145 ,
F_51 ( & V_2 -> V_142 . V_112 -> V_73 ) ) ;
goto V_60;
}
memcpy ( & V_357 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( ( V_357 & ~ 0x0100 ) != F_165 ( V_2 -> V_3 . V_254 ) ) {
F_50 ( 2 , L_146
L_147
L_148 , F_51 ( & V_2 -> V_142 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_254 , V_357 ) ;
goto V_60;
}
V_146 -> V_44 = V_108 ;
V_60:
F_79 ( V_146 , V_106 ) ;
}
static void F_169 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_357 ;
F_24 ( V_52 , 2 , L_149 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_367 ;
goto V_60;
}
V_2 = F_76 ( V_146 -> V_112 ) ;
if ( F_75 ( V_2 , V_106 -> V_110 ) )
goto V_60;
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
switch ( F_168 ( V_106 -> V_110 ) ) {
case V_369 :
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_142
L_143 ) ;
break;
case V_370 :
case V_371 :
F_30 ( & V_2 -> V_107 . V_112 -> V_73 ,
L_150
L_151 ) ;
break;
default:
F_50 ( 2 , L_152
L_145 ,
F_51 ( & V_2 -> V_107 . V_112 -> V_73 ) ) ;
}
F_35 ( V_2 , 2 , L_153 ,
F_168 ( V_106 -> V_110 ) ) ;
goto V_60;
}
if ( ( ! F_170 ( V_106 -> V_110 ) ) ||
( V_2 -> V_3 . type == V_5 ) )
V_2 -> V_3 . V_372 = 1 ;
memcpy ( & V_357 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( V_357 != F_165 ( V_2 -> V_3 . V_254 ) ) {
F_50 ( 2 , L_154
L_155 ,
F_51 ( & V_2 -> V_107 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_254 , V_357 ) ;
goto V_60;
}
memcpy ( & V_2 -> V_349 . V_373 ,
F_160 ( V_106 -> V_110 ) ,
V_365 ) ;
memcpy ( & V_2 -> V_3 . V_297 [ 0 ] ,
F_171 ( V_106 -> V_110 ) , V_374 ) ;
V_146 -> V_44 = V_108 ;
V_60:
F_79 ( V_146 , V_106 ) ;
}
void F_172 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 )
{
F_52 ( & V_2 -> V_142 , V_106 -> V_110 , V_147 ) ;
V_106 -> V_159 = F_79 ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_362 , V_173 ) ;
V_2 -> V_166 . V_362 ++ ;
memcpy ( F_84 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_375 , V_173 ) ;
V_2 -> V_166 . V_375 ++ ;
memcpy ( F_173 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_172 , V_173 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
}
int F_174 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_376 )
{
int V_26 ;
unsigned long V_21 ;
struct V_117 * V_118 = NULL ;
unsigned long V_377 , V_378 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 2 , L_156 ) ;
if ( V_2 -> V_116 ) {
F_79 ( V_106 -> V_146 , V_106 ) ;
return - V_109 ;
}
V_118 = F_55 ( V_2 ) ;
if ( ! V_118 ) {
return - V_39 ;
}
V_118 -> V_159 = F_175 ;
V_118 -> V_379 = V_376 ;
if ( V_2 -> V_44 == V_45 )
V_118 -> V_166 = V_167 ;
else
V_118 -> V_166 = V_2 -> V_166 . V_380 ++ ;
F_87 ( & V_118 -> V_25 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_83 ( & V_118 -> V_31 , & V_2 -> V_171 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
while ( F_41 ( & V_2 -> V_142 . V_115 , 0 , 1 ) ) ;
F_172 ( V_2 , V_147 , V_106 ) ;
if ( F_66 ( V_106 -> V_110 ) )
V_378 = V_381 ;
else
V_378 = V_318 ;
V_377 = V_382 + V_378 ;
F_11 ( V_2 , 6 , L_49 ) ;
F_4 ( F_137 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
V_26 = F_53 ( V_2 -> V_142 . V_112 , & V_2 -> V_142 . V_113 ,
( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
if ( V_26 ) {
F_50 ( 2 , L_157
L_158 ,
F_51 ( & V_2 -> V_142 . V_112 -> V_73 ) , V_26 ) ;
F_35 ( V_2 , 2 , L_159 , V_26 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_74 ( & V_118 -> V_31 ) ;
F_59 ( V_118 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_79 ( V_106 -> V_146 , V_106 ) ;
F_42 ( & V_2 -> V_142 . V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
if ( ( V_123 -> V_126 . V_127 == V_384 ) &&
( V_123 -> V_126 . V_385 == V_386 ) ) {
if ( ! F_176 ( V_118 -> V_25 ,
F_34 ( & V_118 -> V_121 ) , V_378 ) )
goto V_387;
} else {
while ( ! F_34 ( & V_118 -> V_121 ) ) {
if ( F_177 ( V_382 , V_377 ) )
goto V_387;
F_178 () ;
} ;
}
if ( V_118 -> V_26 == - V_109 )
goto error;
V_26 = V_118 -> V_26 ;
F_59 ( V_118 ) ;
return V_26 ;
V_387:
V_118 -> V_26 = - V_320 ;
F_4 ( & V_118 -> V_2 -> V_141 , V_21 ) ;
F_74 ( & V_118 -> V_31 ) ;
F_5 ( & V_118 -> V_2 -> V_141 , V_21 ) ;
F_58 ( & V_118 -> V_121 ) ;
error:
F_42 ( & V_2 -> V_142 . V_115 , 0 ) ;
F_79 ( V_106 -> V_146 , V_106 ) ;
V_2 -> V_142 . V_162 = ( V_2 -> V_142 . V_162 + 1 ) % V_157 ;
V_26 = V_118 -> V_26 ;
F_59 ( V_118 ) ;
return V_26 ;
}
static int F_179 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_160 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_349 . V_388 ,
F_180 ( V_106 -> V_110 ) ,
V_365 ) ;
F_27 ( V_52 , 2 , L_71 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_161 ) ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_389 , V_390 ) ;
memcpy ( F_182 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_373 , V_365 ) ;
memcpy ( F_183 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_351 , V_365 ) ;
V_26 = F_174 ( V_2 , V_390 , V_106 ,
F_179 , NULL ) ;
return V_26 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_162 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_349 . V_391 ,
F_185 ( V_106 -> V_110 ) ,
V_365 ) ;
F_27 ( V_52 , 2 , L_71 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_163 ) ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_392 , V_393 ) ;
memcpy ( F_187 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_373 , V_365 ) ;
memcpy ( F_188 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_352 , V_365 ) ;
memcpy ( F_189 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_388 , V_365 ) ;
V_26 = F_174 ( V_2 , V_393 , V_106 ,
F_184 , NULL ) ;
return V_26 ;
}
static inline int F_190 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_316 :
return 1500 ;
case V_6 :
return V_2 -> V_3 . V_394 ;
case V_5 :
switch ( V_2 -> V_3 . V_10 ) {
case V_12 :
case V_16 :
return 2000 ;
default:
return 1492 ;
}
case V_7 :
case V_8 :
return 1492 ;
default:
return 1500 ;
}
}
static inline int F_191 ( int V_395 )
{
switch ( V_395 ) {
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
static inline int F_192 ( struct V_1 * V_2 , int V_396 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
case V_6 :
return ( ( V_396 >= 576 ) &&
( V_396 <= V_2 -> V_3 . V_394 ) ) ;
case V_9 :
case V_316 :
default:
return 1 ;
}
}
static int F_193 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
V_169 V_396 , V_395 ;
V_169 V_147 ;
T_2 V_10 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_164 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_349 . V_397 ,
F_194 ( V_106 -> V_110 ) ,
V_365 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
memcpy ( & V_395 , F_195 ( V_106 -> V_110 ) , 2 ) ;
V_396 = F_191 ( V_395 ) ;
if ( ! V_396 ) {
V_106 -> V_26 = - V_398 ;
F_27 ( V_52 , 2 , L_71 , V_106 -> V_26 ) ;
return 0 ;
}
if ( V_2 -> V_3 . V_399 && ( V_2 -> V_3 . V_399 != V_396 ) ) {
if ( V_2 -> V_73 &&
( ( V_2 -> V_73 -> V_396 == V_2 -> V_3 . V_399 ) ||
( V_2 -> V_73 -> V_396 > V_396 ) ) )
V_2 -> V_73 -> V_396 = V_396 ;
F_111 ( V_2 ) ;
}
V_2 -> V_3 . V_399 = V_396 ;
V_2 -> V_3 . V_394 = V_396 ;
V_2 -> V_35 . V_255 = V_396 + 2 * V_400 ;
} else {
V_2 -> V_3 . V_399 = F_190 ( V_2 ) ;
V_2 -> V_3 . V_394 = * ( V_169 * ) F_195 (
V_106 -> V_110 ) ;
V_2 -> V_35 . V_255 = V_256 ;
}
memcpy ( & V_147 , F_196 ( V_106 -> V_110 ) , 2 ) ;
if ( V_147 >= V_401 ) {
memcpy ( & V_10 ,
F_197 ( V_106 -> V_110 ) , 1 ) ;
V_2 -> V_3 . V_10 = V_10 ;
} else
V_2 -> V_3 . V_10 = 0 ;
F_27 ( V_52 , 2 , L_165 , V_2 -> V_3 . V_10 ) ;
F_27 ( V_52 , 2 , L_71 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
int V_26 ;
char V_402 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_166 ) ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_403 , V_404 ) ;
* ( F_199 ( V_106 -> V_110 ) ) =
( T_2 ) V_2 -> V_3 . V_364 ;
if ( V_2 -> V_49 . V_302 )
if ( V_2 -> V_3 . type == V_9 )
V_402 = V_405 ;
else
V_402 = V_406 ;
else
V_402 = V_407 ;
memcpy ( F_200 ( V_106 -> V_110 ) , & V_402 , 1 ) ;
memcpy ( F_201 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_391 , V_365 ) ;
memcpy ( F_202 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_353 , V_365 ) ;
memcpy ( F_203 ( V_106 -> V_110 ) ,
V_2 -> V_3 . V_408 , 9 ) ;
V_26 = F_174 ( V_2 , V_404 , V_106 ,
F_193 , NULL ) ;
return V_26 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_167 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_349 . V_409 ,
F_205 ( V_106 -> V_110 ) ,
V_365 ) ;
if ( ! strncmp ( L_168 , F_205 ( V_106 -> V_110 ) ,
3 ) ) {
F_24 ( V_52 , 2 , L_169 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_170
L_171 ) ;
V_106 -> V_26 = - V_410 ;
}
F_27 ( V_52 , 2 , L_71 , V_106 -> V_26 ) ;
return V_26 ;
}
static int F_206 ( struct V_1 * V_2 )
{
int V_26 ;
V_169 V_357 ;
struct V_105 * V_106 ;
struct V_358 V_411 ;
F_24 ( V_52 , 2 , L_172 ) ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_412 , V_413 ) ;
memcpy ( F_207 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_391 , V_365 ) ;
memcpy ( F_208 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_354 , V_365 ) ;
memcpy ( F_209 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_397 , V_365 ) ;
F_162 ( F_26 ( V_2 ) , & V_411 ) ;
memcpy ( F_210 ( V_106 -> V_110 ) , & V_411 . V_366 , 2 ) ;
V_357 = ( V_2 -> V_3 . V_343 << 8 ) + V_2 -> V_3 . V_342 ;
memcpy ( F_211 ( V_106 -> V_110 ) , & V_357 , 2 ) ;
V_26 = F_174 ( V_2 , V_413 , V_106 ,
F_204 , NULL ) ;
return V_26 ;
}
static int F_212 ( struct V_84 * V_85 , int V_86 )
{
int V_26 ;
struct V_89 * V_414 ;
V_26 = 0 ;
V_414 = F_213 ( V_94 , V_119 ) ;
if ( ! V_414 ) {
V_26 = - V_39 ;
goto V_60;
}
V_414 -> V_66 = & V_85 -> V_54 [ V_86 ] ;
F_214 ( & V_414 -> V_220 ) ;
F_215 ( & V_414 -> V_220 . V_141 , & V_415 ) ;
V_414 -> V_85 = V_85 ;
V_414 -> V_97 = NULL ;
V_414 -> V_88 = V_85 -> V_65 [ V_86 ] ;
F_42 ( & V_414 -> V_44 , V_234 ) ;
V_85 -> V_65 [ V_86 ] = V_414 ;
if ( V_85 -> V_71 ) {
V_85 -> V_71 [ V_86 ] . V_416 = V_414 ;
F_35 ( V_85 -> V_2 , 2 , L_173 , V_86 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 , ( long ) V_414 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 ,
( long ) V_414 -> V_88 ) ;
}
V_60:
return V_26 ;
}
static int F_216 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
F_24 ( V_52 , 2 , L_174 ) ;
if ( F_41 ( & V_2 -> V_35 . V_44 , V_241 ,
V_330 ) != V_241 )
return 0 ;
V_2 -> V_35 . V_243 = F_15 ( sizeof( struct V_63 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_243 )
goto V_417;
F_24 ( V_52 , 2 , L_175 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_243 , sizeof( void * ) ) ;
memset ( V_2 -> V_35 . V_243 , 0 , sizeof( struct V_63 ) ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_2 -> V_35 . V_243 -> V_65 [ V_33 ] . V_66 =
& V_2 -> V_35 . V_243 -> V_54 [ V_33 ] ;
V_2 -> V_35 . V_243 -> V_65 [ V_33 ] . V_244 = NULL ;
}
if ( F_14 ( V_2 ) )
goto V_418;
V_2 -> V_35 . V_70 =
F_15 ( V_2 -> V_35 . V_68 *
sizeof( struct V_84 * ) , V_38 ) ;
if ( ! V_2 -> V_35 . V_70 )
goto V_419;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
V_2 -> V_35 . V_70 [ V_33 ] = F_15 ( sizeof( struct V_84 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_70 [ V_33 ] )
goto V_420;
F_27 ( V_52 , 2 , L_176 , V_33 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_70 [ V_33 ] , sizeof( void * ) ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_421 = V_33 ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
F_37 ( V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] != NULL ) ;
if ( F_212 ( V_2 -> V_35 . V_70 [ V_33 ] , V_34 ) )
goto V_422;
}
}
if ( F_28 ( V_2 ) )
goto V_420;
return 0 ;
V_422:
while ( V_34 > 0 ) {
-- V_34 ;
F_38 ( V_94 ,
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] = NULL ;
}
V_420:
while ( V_33 > 0 ) {
F_20 ( V_2 -> V_35 . V_70 [ -- V_33 ] ) ;
F_109 ( V_2 -> V_35 . V_70 [ V_33 ] , 1 ) ;
}
F_20 ( V_2 -> V_35 . V_70 ) ;
V_2 -> V_35 . V_70 = NULL ;
V_419:
F_16 ( V_2 ) ;
V_418:
F_20 ( V_2 -> V_35 . V_243 ) ;
V_2 -> V_35 . V_243 = NULL ;
V_417:
F_42 ( & V_2 -> V_35 . V_44 , V_241 ) ;
return - V_39 ;
}
static void F_217 ( struct V_1 * V_2 ,
char * V_423 )
{
V_423 [ 0 ] = V_344 [ 'P' ] ;
V_423 [ 1 ] = V_344 [ 'C' ] ;
V_423 [ 2 ] = V_344 [ 'I' ] ;
V_423 [ 3 ] = V_344 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_423 [ 4 ] ) ) = F_218 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_423 [ 8 ] ) ) = F_219 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_423 [ 12 ] ) ) = F_220 ( V_2 ) ;
}
static void F_221 ( struct V_1 * V_2 ,
char * V_423 )
{
V_423 [ 16 ] = V_344 [ 'B' ] ;
V_423 [ 17 ] = V_344 [ 'L' ] ;
V_423 [ 18 ] = V_344 [ 'K' ] ;
V_423 [ 19 ] = V_344 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_423 [ 20 ] ) ) = V_2 -> V_3 . V_345 . V_346 ;
* ( ( unsigned int * ) ( & V_423 [ 24 ] ) ) = V_2 -> V_3 . V_345 . V_347 ;
* ( ( unsigned int * ) ( & V_423 [ 28 ] ) ) =
V_2 -> V_3 . V_345 . V_348 ;
}
static int F_222 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 3 , L_177 ) ;
return F_223 ( F_26 ( V_2 ) ) ;
}
static int F_224 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_178 ) ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_424 , V_425 ) ;
memcpy ( F_225 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_391 , V_365 ) ;
memcpy ( F_226 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_409 , V_365 ) ;
V_26 = F_174 ( V_2 , V_425 , V_106 , NULL , NULL ) ;
return V_26 ;
}
static int F_227 ( struct V_1 * V_2 )
{
int V_26 ;
F_24 ( V_52 , 2 , L_179 ) ;
V_26 = F_47 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_181 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_130 , V_26 ) ;
goto V_426;
}
V_26 = F_186 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_135 , V_26 ) ;
goto V_426;
}
V_26 = F_198 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_180 , V_26 ) ;
goto V_426;
}
V_26 = F_206 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_426;
}
V_26 = F_216 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_426;
}
V_26 = F_228 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
F_111 ( V_2 ) ;
goto V_426;
}
V_26 = F_222 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
goto V_426;
}
V_26 = F_224 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_184 , V_26 ) ;
goto V_426;
}
return 0 ;
V_426:
F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
return V_26 ;
}
static void F_229 ( struct V_1 * V_2 )
{
char V_427 [ 15 ] ;
int V_33 ;
sprintf ( V_427 , L_185 , V_2 -> V_3 . V_408 + 1 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_427 [ V_33 ] =
( char ) V_428 [ ( T_2 ) V_427 [ V_33 ] ] ;
V_427 [ 8 ] = 0 ;
F_71 ( & V_2 -> V_72 -> V_73 , L_186
L_187 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_188 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? V_2 -> V_3 . V_297 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_189 : L_68 ,
F_2 ( V_2 ) ,
V_427 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_408 [ 0 ] )
F_71 ( & V_2 -> V_72 -> V_73 , L_190
L_191
L_192 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_188 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? V_2 -> V_3 . V_297 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_189 : L_68 ,
F_2 ( V_2 ) ) ;
else
F_71 ( & V_2 -> V_72 -> V_73 , L_190
L_193 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_188 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? V_2 -> V_3 . V_297 : L_68 ,
( V_2 -> V_3 . V_297 [ 0 ] ) ? L_189 : L_68 ,
F_2 ( V_2 ) ) ;
}
void F_231 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
if ( ! V_2 -> V_3 . V_297 [ 0 ] ) {
sprintf ( V_2 -> V_3 . V_297 , L_194 ,
V_2 -> V_3 . V_297 [ 2 ] ,
V_2 -> V_3 . V_297 [ 3 ] ) ;
V_2 -> V_3 . V_297 [ V_374 ] = 0 ;
break;
}
case V_6 :
if ( ( V_2 -> V_3 . V_4 ) ||
( V_2 -> V_3 . V_297 [ 0 ] & 0x80 ) ) {
V_2 -> V_3 . V_297 [ 0 ] = ( char ) V_428 [ ( T_2 )
V_2 -> V_3 . V_297 [ 0 ] ] ;
V_2 -> V_3 . V_297 [ 1 ] = ( char ) V_428 [ ( T_2 )
V_2 -> V_3 . V_297 [ 1 ] ] ;
V_2 -> V_3 . V_297 [ 2 ] = ( char ) V_428 [ ( T_2 )
V_2 -> V_3 . V_297 [ 2 ] ] ;
V_2 -> V_3 . V_297 [ 3 ] = ( char ) V_428 [ ( T_2 )
V_2 -> V_3 . V_297 [ 3 ] ] ;
V_2 -> V_3 . V_297 [ V_374 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_3 . V_297 [ 0 ] , 0 , V_374 + 1 ) ;
}
if ( V_2 -> V_3 . V_372 )
F_229 ( V_2 ) ;
else
F_230 ( V_2 ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_28 * V_429 ;
F_11 ( V_2 , 5 , L_195 ) ;
F_233 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_234 ( V_2 , V_429 ) ;
}
}
static inline struct V_28 * F_235 (
struct V_1 * V_2 )
{
struct V_298 * V_430 ;
struct V_28 * V_429 ;
int V_33 , free ;
struct V_431 * V_431 ;
if ( F_236 ( & V_2 -> V_35 . V_48 . V_42 ) )
return NULL ;
F_237 (plh, &card->qdio.in_buf_pool.entry_list) {
V_429 = F_238 ( V_430 , struct V_28 , V_31 ) ;
free = 1 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_239 ( F_240 ( V_429 -> V_40 [ V_33 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_74 ( & V_429 -> V_31 ) ;
return V_429 ;
}
}
V_429 = F_238 ( V_2 -> V_35 . V_48 . V_42 . V_432 ,
struct V_28 , V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_239 ( F_240 ( V_429 -> V_40 [ V_33 ] ) ) > 1 ) {
V_431 = F_241 ( V_119 ) ;
if ( ! V_431 ) {
return NULL ;
} else {
F_19 ( ( unsigned long ) V_429 -> V_40 [ V_33 ] ) ;
V_429 -> V_40 [ V_33 ] = F_242 ( V_431 ) ;
if ( V_2 -> V_49 . V_269 )
V_2 -> V_433 . V_434 ++ ;
}
}
}
F_74 ( & V_429 -> V_31 ) ;
return V_429 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_435 * V_217 )
{
struct V_28 * V_29 ;
int V_33 ;
if ( ( V_2 -> V_49 . V_50 == V_51 ) && ( ! V_217 -> V_244 ) ) {
V_217 -> V_244 = F_244 ( V_436 + V_437 ) ;
if ( ! V_217 -> V_244 )
return 1 ;
}
V_29 = F_235 ( V_2 ) ;
if ( ! V_29 )
return 1 ;
V_217 -> V_29 = V_29 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
V_217 -> V_66 -> V_230 [ V_33 ] . V_238 = V_400 ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_235 = V_29 -> V_40 [ V_33 ] ;
if ( V_33 == F_17 ( V_2 ) - 1 )
V_217 -> V_66 -> V_230 [ V_33 ] . V_239 = V_438 ;
else
V_217 -> V_66 -> V_230 [ V_33 ] . V_239 = 0 ;
V_217 -> V_66 -> V_230 [ V_33 ] . V_231 = 0 ;
}
return 0 ;
}
int F_245 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
int V_26 ;
F_24 ( V_52 , 2 , L_196 ) ;
memset ( V_2 -> V_35 . V_243 -> V_54 , 0 ,
V_55 * sizeof( struct V_56 ) ) ;
F_232 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_48 . V_37 - 1 ; ++ V_33 )
F_243 ( V_2 , & V_2 -> V_35 . V_243 -> V_65 [ V_33 ] ) ;
V_2 -> V_35 . V_243 -> V_57 =
V_2 -> V_35 . V_48 . V_37 - 1 ;
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , 0 , 0 ,
V_2 -> V_35 . V_48 . V_37 - 1 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_23 ( V_2 ) ;
if ( V_26 ) {
return V_26 ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
memset ( V_2 -> V_35 . V_70 [ V_33 ] -> V_54 , 0 ,
V_55 * sizeof( struct V_56 ) ) ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
F_44 ( V_2 -> V_35 . V_70 [ V_33 ] ,
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] ,
V_234 ) ;
}
V_2 -> V_35 . V_70 [ V_33 ] -> V_2 = V_2 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_439 = 0 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_440 = 0 ;
F_42 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_441 , 0 ) ;
F_42 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_233 , 0 ) ;
F_42 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_44 ,
V_442 ) ;
}
return 0 ;
}
static inline T_2 F_246 ( enum V_443 V_10 )
{
switch ( V_10 ) {
case V_12 :
return 2 ;
default:
return 1 ;
}
}
static void F_247 ( struct V_1 * V_2 ,
struct V_122 * V_123 , T_2 V_127 ,
enum V_444 V_445 )
{
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_126 . V_127 = V_127 ;
V_123 -> V_126 . V_446 = V_447 ;
V_123 -> V_126 . V_166 = V_2 -> V_166 . V_380 ;
V_123 -> V_126 . V_448 = F_246 ( V_2 -> V_3 . V_10 ) ;
V_123 -> V_126 . V_449 = ( T_2 ) V_2 -> V_3 . V_364 ;
if ( V_2 -> V_49 . V_302 )
V_123 -> V_126 . V_450 = 2 ;
else
V_123 -> V_126 . V_450 = 1 ;
V_123 -> V_126 . V_451 = 1 ;
V_123 -> V_126 . V_385 = V_445 ;
V_123 -> V_126 . V_452 = 0 ;
V_123 -> V_126 . V_453 = 0 ;
}
struct V_105 * F_248 ( struct V_1 * V_2 ,
enum V_454 V_455 , enum V_444 V_445 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_80 ( & V_2 -> V_142 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
F_247 ( V_2 , V_123 , V_455 , V_445 ) ;
return V_106 ;
}
void F_249 ( struct V_1 * V_2 , struct V_105 * V_106 ,
char V_402 )
{
memcpy ( V_106 -> V_110 , V_456 , V_383 ) ;
memcpy ( F_250 ( V_106 -> V_110 ) , & V_402 , 1 ) ;
memcpy ( F_251 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_409 , V_365 ) ;
}
int F_252 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_376 )
{
int V_26 ;
char V_402 ;
F_11 ( V_2 , 4 , L_197 ) ;
if ( V_2 -> V_49 . V_302 )
if ( V_2 -> V_3 . type == V_9 )
V_402 = V_405 ;
else
V_402 = V_406 ;
else
V_402 = V_407 ;
F_249 ( V_2 , V_106 , V_402 ) ;
V_26 = F_174 ( V_2 , V_457 ,
V_106 , F_175 , V_376 ) ;
if ( V_26 == - V_320 ) {
F_73 ( V_2 ) ;
F_54 ( V_2 ) ;
}
return V_26 ;
}
int F_253 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_198 ) ;
V_106 = F_248 ( V_2 , V_136 , 0 ) ;
V_26 = F_252 ( V_2 , V_106 , NULL , NULL ) ;
return V_26 ;
}
int F_254 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_199 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_132 == 0 )
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_458 . V_126 . V_132 ;
return 0 ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 3 , L_200 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_110 . V_458 . V_110 . V_459 . V_460 & 0x7f ) {
V_2 -> V_3 . V_10 =
V_123 -> V_110 . V_458 . V_110 . V_459 . V_460 ;
F_27 ( V_52 , 2 , L_201 , V_2 -> V_3 . V_10 ) ;
}
V_2 -> V_49 . V_461 . V_462 =
V_123 -> V_110 . V_458 . V_110 . V_459 . V_463 ;
return F_254 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
}
struct V_105 * F_256 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_464 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_248 ( V_2 , V_465 ,
V_386 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_123 -> V_110 . V_458 . V_126 . V_466 = V_464 ;
V_123 -> V_110 . V_458 . V_126 . V_467 = V_127 ;
V_123 -> V_110 . V_458 . V_126 . V_468 = 1 ;
V_123 -> V_110 . V_458 . V_126 . V_469 = 1 ;
return V_106 ;
}
int F_257 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 3 , L_202 ) ;
V_106 = F_256 ( V_2 , V_470 ,
sizeof( struct V_471 ) ) ;
V_26 = F_252 ( V_2 , V_106 , F_255 , NULL ) ;
return V_26 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_203 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_385 == V_386 ) {
V_2 -> V_49 . V_472 . V_462 = V_123 -> V_126 . V_452 ;
V_2 -> V_49 . V_472 . V_473 = V_123 -> V_126 . V_453 ;
} else {
V_2 -> V_49 . V_474 . V_462 = V_123 -> V_126 . V_452 ;
V_2 -> V_49 . V_474 . V_473 = V_123 -> V_126 . V_453 ;
}
F_24 ( V_52 , 2 , L_204 ) ;
F_27 ( V_52 , 2 , L_205 , V_123 -> V_126 . V_452 ) ;
F_27 ( V_52 , 2 , L_205 , V_123 -> V_126 . V_453 ) ;
return 0 ;
}
int F_259 ( struct V_1 * V_2 , enum V_444 V_445 )
{
int V_26 ;
struct V_105 * V_106 ;
F_27 ( V_52 , 2 , L_206 , V_445 ) ;
V_106 = F_248 ( V_2 , V_475 , V_445 ) ;
V_26 = F_252 ( V_2 , V_106 , F_258 , NULL ) ;
return V_26 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_207 , V_26 ) ;
else
V_2 -> V_3 . V_476 = V_123 -> V_110 . V_477 . V_478 ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_208 ) ;
V_106 = F_248 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_123 -> V_110 . V_477 . V_479 = 16 ;
V_123 -> V_110 . V_477 . V_480 = V_481 ;
return F_252 ( V_2 , V_106 , F_260 , NULL ) ;
}
static void F_262 ( struct V_1 * V_2 , struct V_482 * V_483 )
{
unsigned long V_3 = F_263 ( V_38 ) ;
struct V_484 * V_485 = (struct V_484 * ) V_3 ;
struct V_486 * V_487 = (struct V_486 * ) V_3 ;
struct V_358 V_488 ;
int V_368 , V_26 ;
V_483 -> V_134 = V_2 -> V_3 . V_134 ;
F_162 ( F_135 ( V_2 ) , & V_488 ) ;
V_483 -> V_489 = V_488 . V_489 ;
V_483 -> V_366 = V_488 . V_366 ;
if ( ! V_3 )
return;
V_26 = F_264 ( NULL , 0 , 0 , 0 ) ;
if ( V_26 == - V_490 )
V_368 = V_26 ;
else
V_368 = ( ( ( unsigned int ) V_26 ) >> 28 ) ;
if ( ( V_368 >= 2 ) && ( F_264 ( V_485 , 2 , 2 , 2 ) != - V_490 ) )
V_483 -> V_491 = V_485 -> V_492 ;
if ( ( V_368 >= 3 ) && ( F_264 ( V_487 , 3 , 2 , 2 ) != - V_490 ) ) {
F_265 ( V_487 -> V_493 [ 0 ] . V_494 , sizeof( V_487 -> V_493 [ 0 ] . V_494 ) ) ;
memcpy ( V_483 -> V_495 , V_487 -> V_493 [ 0 ] . V_494 , sizeof( V_483 -> V_495 ) ) ;
}
F_19 ( V_3 ) ;
return;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_209 , V_26 ) ;
return 0 ;
}
int F_267 ( struct V_1 * V_2 , enum V_496 V_497 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_210 ) ;
V_106 = F_248 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_123 -> V_110 . V_477 . V_479 = 80 ;
V_123 -> V_110 . V_477 . V_480 = V_498 ;
V_123 -> V_110 . V_477 . type = 1 ;
V_123 -> V_110 . V_477 . V_497 = V_497 ;
switch ( V_497 ) {
case V_499 :
V_123 -> V_110 . V_477 . V_49 = 0x0003 ;
V_123 -> V_110 . V_477 . V_478 = 0x00010000 +
sizeof( struct V_482 ) ;
F_262 ( V_2 ,
(struct V_482 * ) V_123 -> V_110 . V_477 . V_500 ) ;
break;
case V_501 :
V_123 -> V_110 . V_477 . V_49 = 0x0001 ;
break;
case V_502 :
break;
}
return F_252 ( V_2 , V_106 , F_266 , NULL ) ;
}
int F_268 ( struct V_1 * V_2 , struct V_56 * V_217 ,
unsigned int V_503 , const char * V_504 )
{
if ( V_503 ) {
F_11 ( V_2 , 2 , V_504 ) ;
F_35 ( V_2 , 2 , L_211 ,
V_217 -> V_230 [ 15 ] . V_231 ) ;
F_35 ( V_2 , 2 , L_212 ,
V_217 -> V_230 [ 14 ] . V_231 ) ;
F_35 ( V_2 , 2 , L_213 , V_503 ) ;
if ( ( V_217 -> V_230 [ 15 ] . V_231 ) == 0x12 ) {
V_2 -> V_505 . V_506 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_291 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = F_123 ( V_276 , struct V_1 ,
V_242 . V_276 ) ;
F_35 ( V_2 , 2 , L_214 , V_2 -> V_507 ) ;
F_269 ( V_2 , V_2 -> V_507 ) ;
}
void F_269 ( struct V_1 * V_2 , int V_153 )
{
struct V_63 * V_104 = V_2 -> V_35 . V_243 ;
struct V_298 * V_508 ;
int V_151 ;
int V_33 ;
int V_26 ;
int V_509 = 0 ;
V_151 = ( V_153 < V_104 -> V_57 ) ?
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 - V_153 ) :
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 + V_55 - V_153 ) ;
if ( V_151 >= F_270 ( V_2 ) ) {
for ( V_33 = V_104 -> V_57 ;
V_33 < V_104 -> V_57 + V_151 ; ++ V_33 ) {
if ( F_243 ( V_2 ,
& V_104 -> V_65 [ V_33 % V_55 ] ) ) {
break;
} else {
V_509 ++ ;
}
}
if ( V_509 < V_151 ) {
F_42 ( & V_2 -> V_510 , 3 ) ;
V_151 = V_509 ;
} else {
F_271 ( & V_2 -> V_510 , - 1 , 0 ) ;
}
if ( ! V_151 ) {
V_33 = 0 ;
F_237 (lh, &card->qdio.in_buf_pool.entry_list)
V_33 ++ ;
if ( V_33 == V_2 -> V_35 . V_48 . V_37 ) {
F_11 ( V_2 , 2 , L_215 ) ;
V_2 -> V_507 = V_153 ;
F_272 (
& V_2 -> V_242 ,
V_511 ) ;
}
return;
}
if ( V_2 -> V_49 . V_269 ) {
V_2 -> V_433 . V_512 ++ ;
V_2 -> V_433 . V_513 =
F_273 () ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , 0 ,
V_104 -> V_57 , V_151 ) ;
if ( V_2 -> V_49 . V_269 )
V_2 -> V_433 . V_514 +=
F_273 () -
V_2 -> V_433 . V_513 ;
if ( V_26 ) {
F_11 ( V_2 , 2 , L_216 ) ;
}
V_104 -> V_57 = ( V_104 -> V_57 + V_151 ) %
V_55 ;
}
}
static int F_274 ( struct V_1 * V_2 ,
struct V_89 * V_66 , unsigned int V_515 )
{
int V_75 = V_66 -> V_66 -> V_230 [ 15 ] . V_231 ;
F_11 ( V_2 , 6 , L_217 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
if ( V_75 == 0 ) {
V_515 = 0 ;
} else {
V_515 = 1 ;
}
}
F_268 ( V_2 , V_66 -> V_66 , V_515 , L_218 ) ;
if ( ! V_515 )
return V_516 ;
if ( ( V_75 >= 15 ) && ( V_75 <= 31 ) )
return V_517 ;
F_11 ( V_2 , 1 , L_219 ) ;
F_35 ( V_2 , 1 , L_220 ,
( V_170 ) V_515 , ( T_3 ) V_75 ) ;
return V_518 ;
}
static void F_275 ( struct V_84 * V_104 )
{
if ( ! V_104 -> V_440 ) {
if ( F_34 ( & V_104 -> V_441 )
>= V_519 ) {
F_11 ( V_104 -> V_2 , 6 , L_221 ) ;
if ( V_104 -> V_2 -> V_49 . V_269 )
V_104 -> V_2 -> V_433 . V_520 ++ ;
V_104 -> V_440 = 1 ;
}
}
}
static int F_276 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
int V_521 = 0 ;
if ( V_104 -> V_440 ) {
if ( F_34 ( & V_104 -> V_441 )
<= V_522 ) {
F_11 ( V_104 -> V_2 , 6 , L_222 ) ;
if ( V_104 -> V_2 -> V_49 . V_269 )
V_104 -> V_2 -> V_433 . V_523 ++ ;
V_104 -> V_440 = 0 ;
V_66 = V_104 -> V_65 [ V_104 -> V_439 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) ==
V_234 ) &&
( V_66 -> V_240 > 0 ) ) {
F_42 ( & V_66 -> V_44 ,
V_100 ) ;
V_521 ++ ;
V_104 -> V_439 =
( V_104 -> V_439 + 1 ) %
V_55 ;
}
}
}
return V_521 ;
}
static int F_277 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
V_66 = V_104 -> V_65 [ V_104 -> V_439 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) == V_234 ) &&
( V_66 -> V_240 > 0 ) ) {
F_42 ( & V_66 -> V_44 , V_100 ) ;
V_104 -> V_439 =
( V_104 -> V_439 + 1 ) % V_55 ;
return 1 ;
}
return 0 ;
}
static void F_278 ( struct V_84 * V_104 , int V_153 ,
int V_151 )
{
struct V_89 * V_217 ;
int V_26 ;
int V_33 ;
unsigned int V_524 ;
for ( V_33 = V_153 ; V_33 < V_153 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_217 = V_104 -> V_65 [ V_86 ] ;
V_217 -> V_66 -> V_230 [ V_217 -> V_240 - 1 ] . V_239 |=
V_438 ;
if ( V_104 -> V_71 )
V_104 -> V_71 [ V_86 ] . V_416 = V_217 ;
if ( V_104 -> V_2 -> V_3 . type == V_6 )
continue;
if ( ! V_104 -> V_440 ) {
if ( ( F_34 ( & V_104 -> V_441 ) >=
( V_519 -
V_525 ) ) &&
! F_34 ( & V_104 -> V_233 ) ) {
F_58 ( & V_104 -> V_233 ) ;
V_217 -> V_66 -> V_230 [ 0 ] . V_231 |= V_232 ;
}
} else {
if ( ! F_34 ( & V_104 -> V_233 ) ) {
F_58 ( & V_104 -> V_233 ) ;
V_217 -> V_66 -> V_230 [ 0 ] . V_231 |= V_232 ;
}
}
}
V_104 -> V_2 -> V_73 -> V_526 = V_382 ;
if ( V_104 -> V_2 -> V_49 . V_269 ) {
V_104 -> V_2 -> V_433 . V_527 ++ ;
V_104 -> V_2 -> V_433 . V_528 =
F_273 () ;
}
V_524 = V_529 ;
if ( F_34 ( & V_104 -> V_233 ) )
V_524 |= V_530 ;
V_26 = F_25 ( F_26 ( V_104 -> V_2 ) , V_524 ,
V_104 -> V_421 , V_153 , V_151 ) ;
if ( V_104 -> V_2 -> V_49 . V_269 )
V_104 -> V_2 -> V_433 . V_531 +=
F_273 () -
V_104 -> V_2 -> V_433 . V_528 ;
F_279 ( V_151 , & V_104 -> V_441 ) ;
if ( V_26 ) {
V_104 -> V_2 -> V_505 . V_532 += V_151 ;
if ( V_26 == V_533 )
return;
F_11 ( V_104 -> V_2 , 2 , L_223 ) ;
F_35 ( V_104 -> V_2 , 2 , L_224 , V_104 -> V_421 ) ;
F_35 ( V_104 -> V_2 , 2 , L_225 , V_153 ) ;
F_35 ( V_104 -> V_2 , 2 , L_226 , V_151 ) ;
F_35 ( V_104 -> V_2 , 2 , L_159 , V_26 ) ;
F_54 ( V_104 -> V_2 ) ;
return;
}
if ( V_104 -> V_2 -> V_49 . V_269 )
V_104 -> V_2 -> V_433 . V_534 += V_151 ;
}
static void F_280 ( struct V_84 * V_104 )
{
int V_153 ;
int V_535 = 0 ;
int V_536 = 0 ;
if ( ( F_34 ( & V_104 -> V_441 ) <= V_522 ) ||
! F_34 ( & V_104 -> V_233 ) ) {
if ( F_112 ( & V_104 -> V_44 , V_537 ) ==
V_442 ) {
F_281 ( V_104 -> V_2 -> V_73 ) ;
V_153 = V_104 -> V_439 ;
V_536 = V_104 -> V_440 ;
F_282 () ;
V_535 += F_276 ( V_104 ) ;
if ( ! V_535 &&
! F_34 ( & V_104 -> V_233 ) )
V_535 +=
F_277 ( V_104 ) ;
if ( V_104 -> V_2 -> V_49 . V_269 &&
V_536 )
V_104 -> V_2 -> V_433 . V_538 +=
V_535 ;
if ( V_535 )
F_278 ( V_104 , V_153 , V_535 ) ;
F_42 ( & V_104 -> V_44 , V_442 ) ;
}
}
}
void F_283 ( struct V_178 * V_112 , int V_104 ,
unsigned long V_539 )
{
struct V_1 * V_2 = (struct V_1 * ) V_539 ;
if ( V_2 -> V_73 && ( V_2 -> V_73 -> V_21 & V_540 ) )
F_284 ( & V_2 -> V_541 ) ;
}
int F_285 ( struct V_1 * V_2 , enum V_542 V_50 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_543 ) {
V_26 = - 1 ;
goto V_60;
} else {
if ( V_2 -> V_49 . V_50 == V_50 ) {
V_26 = 0 ;
goto V_60;
}
if ( V_2 -> V_44 != V_45 &&
V_2 -> V_44 != V_46 ) {
V_26 = - 1 ;
goto V_60;
}
F_111 ( V_2 ) ;
V_2 -> V_49 . V_50 = V_50 ;
V_26 = 0 ;
}
V_60:
return V_26 ;
}
static void F_286 ( struct V_1 * V_2 ,
unsigned int V_515 ,
unsigned int V_104 , int V_544 , int V_151 ) {
struct V_63 * V_50 = V_2 -> V_35 . V_53 ;
int V_33 ;
int V_26 ;
if ( ! F_46 ( V_2 , V_104 ) )
goto V_60;
F_35 ( V_2 , 5 , L_227 , V_544 ) ;
F_35 ( V_2 , 5 , L_228 , V_151 ) ;
F_35 ( V_2 , 5 , L_229 , V_515 ) ;
if ( V_515 ) {
F_281 ( V_2 -> V_73 ) ;
F_54 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_49 . V_269 ) {
V_2 -> V_433 . V_545 ++ ;
V_2 -> V_433 . V_546 = F_273 () ;
}
for ( V_33 = V_544 ; V_33 < V_544 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
struct V_56 * V_66 = & V_50 -> V_54 [ V_86 ] ;
int V_547 ;
V_547 = 0 ;
while ( V_66 -> V_230 [ V_547 ] . V_235 ) {
unsigned long V_95 ;
V_95 = ( unsigned long ) V_66 -> V_230 [ V_547 ] . V_235 ;
F_39 ( V_2 , V_95 ) ;
V_66 -> V_230 [ V_547 ] . V_235 = NULL ;
V_66 -> V_230 [ V_547 ] . V_239 = 0 ;
V_66 -> V_230 [ V_547 ] . V_231 = 0 ;
V_66 -> V_230 [ V_547 ] . V_238 = 0 ;
++ V_547 ;
}
V_66 -> V_230 [ 15 ] . V_239 = 0 ;
V_66 -> V_230 [ 15 ] . V_231 = 0 ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , V_104 ,
V_2 -> V_35 . V_53 -> V_57 ,
V_151 ) ;
if ( V_26 ) {
F_49 ( & V_2 -> V_72 -> V_73 ,
L_230 , V_26 ) ;
F_11 ( V_2 , 2 , L_231 ) ;
}
V_2 -> V_35 . V_53 -> V_57 = ( V_2 -> V_35 . V_53 -> V_57
+ V_151 ) % V_55 ;
F_287 ( V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_269 ) {
int V_548 = F_273 () ;
V_548 -= V_2 -> V_433 . V_546 ;
V_2 -> V_433 . V_549 += V_548 ;
}
V_60:
return;
}
void F_288 ( struct V_178 * V_112 , unsigned int V_515 ,
unsigned int V_104 , int V_550 , int V_151 ,
unsigned long V_539 )
{
struct V_1 * V_2 = (struct V_1 * ) V_539 ;
F_35 ( V_2 , 2 , L_232 , V_104 ) ;
F_35 ( V_2 , 2 , L_233 , V_515 ) ;
if ( F_46 ( V_2 , V_104 ) )
F_286 ( V_2 , V_515 , V_104 , V_550 , V_151 ) ;
else if ( V_515 )
F_54 ( V_2 ) ;
}
void F_289 ( struct V_178 * V_112 ,
unsigned int V_503 , int V_551 , int V_544 ,
int V_151 , unsigned long V_539 )
{
struct V_1 * V_2 = (struct V_1 * ) V_539 ;
struct V_84 * V_104 = V_2 -> V_35 . V_70 [ V_551 ] ;
struct V_89 * V_66 ;
int V_33 ;
F_11 ( V_2 , 6 , L_234 ) ;
if ( V_503 & V_552 ) {
F_11 ( V_2 , 2 , L_235 ) ;
F_281 ( V_2 -> V_73 ) ;
F_54 ( V_2 ) ;
return;
}
if ( V_2 -> V_49 . V_269 ) {
V_2 -> V_433 . V_553 ++ ;
V_2 -> V_433 . V_554 =
F_273 () ;
}
for ( V_33 = V_544 ; V_33 < ( V_544 + V_151 ) ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_66 = V_104 -> V_65 [ V_86 ] ;
F_274 ( V_2 , V_66 , V_503 ) ;
if ( V_104 -> V_71 &&
( V_104 -> V_71 [ V_86 ] . V_21 &
V_555 ) != 0 ) {
F_37 ( V_2 -> V_49 . V_50 != V_51 ) ;
if ( F_41 ( & V_66 -> V_44 ,
V_100 ,
V_102 ) ==
V_100 ) {
F_43 ( V_104 , V_66 ,
V_556 ) ;
}
V_66 -> V_97 = V_104 -> V_71 [ V_86 ] . V_97 ;
F_35 ( V_104 -> V_2 , 5 , L_236 , V_86 ) ;
F_11 ( V_104 -> V_2 , 5 , L_237 ) ;
F_35 ( V_104 -> V_2 , 5 , L_41 ,
F_290 ( V_66 -> V_97 ) ) ;
F_37 ( V_86 < 0 || V_86 >= V_55 ) ;
if ( F_212 ( V_104 , V_86 ) ) {
F_11 ( V_2 , 2 , L_238 ) ;
F_54 ( V_2 ) ;
}
} else {
if ( V_2 -> V_49 . V_50 == V_51 ) {
enum V_74 V_77 ;
V_77 = F_32 (
V_66 -> V_66 -> V_230 [ 15 ] . V_231 , 0 ) ;
F_43 ( V_104 , V_66 , V_77 ) ;
}
F_44 ( V_104 , V_66 ,
V_234 ) ;
}
F_33 ( V_104 , V_86 , 0 ) ;
}
F_291 ( V_151 , & V_104 -> V_441 ) ;
if ( V_2 -> V_3 . type != V_6 )
F_280 ( V_104 ) ;
F_287 ( V_104 -> V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_269 )
V_2 -> V_433 . V_557 += F_273 () -
V_2 -> V_433 . V_554 ;
}
int F_292 ( struct V_1 * V_2 , struct V_218 * V_219 ,
int V_558 , int V_559 )
{
if ( ! V_558 && ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) )
return V_2 -> V_35 . V_253 ;
switch ( V_2 -> V_35 . V_68 ) {
case 4 :
if ( V_559 && V_2 -> V_3 . V_314 )
return V_2 -> V_3 . V_314 &
( V_2 -> V_35 . V_68 - 1 ) ;
if ( V_2 -> V_35 . V_304 && ( V_558 == 4 ) ) {
const T_3 V_560 = F_293 ( V_219 ) -> V_560 ;
if ( V_2 -> V_35 . V_304 ==
V_561 ) {
if ( V_560 & V_562 )
return 3 ;
if ( V_560 & V_563 )
return 2 ;
if ( V_560 & V_564 )
return 1 ;
if ( V_560 & V_565 )
return 0 ;
}
if ( V_2 -> V_35 . V_304 ==
V_566 )
return 3 - ( V_560 >> 6 ) ;
} else if ( V_2 -> V_35 . V_304 && ( V_558 == 6 ) ) {
}
return V_2 -> V_35 . V_253 ;
case 1 :
default:
return V_2 -> V_35 . V_253 ;
}
}
int F_294 ( struct V_1 * V_2 , void * V_126 ,
struct V_218 * V_219 , int V_567 )
{
int V_568 = V_219 -> V_147 - V_219 -> V_569 ;
int V_570 = F_295 ( ( unsigned long ) V_219 -> V_110 + V_568 - 1 ) -
F_296 ( ( unsigned long ) V_219 -> V_110 ) ;
V_570 += F_297 ( V_219 ) -> V_571 ;
if ( ( V_570 + V_567 ) > F_17 ( V_2 ) ) {
F_50 ( 2 , L_239
L_240 ,
( V_570 + V_567 ) , V_219 -> V_147 ) ;
return 0 ;
}
return V_570 ;
}
int F_298 ( struct V_218 * V_219 , int V_147 )
{
int V_572 , V_573 , V_574 ;
if ( ( ( unsigned long ) V_219 -> V_110 & V_575 ) !=
( ( ( unsigned long ) V_219 -> V_110 + V_147 - 1 ) & V_575 ) ) {
V_572 = F_299 ( V_219 ) ;
V_573 = V_400 - ( ( unsigned long ) V_219 -> V_110 % V_400 ) ;
V_574 = V_147 - V_573 ;
if ( V_574 > V_572 )
return 1 ;
memmove ( V_219 -> V_110 - V_574 , V_219 -> V_110 , V_219 -> V_147 - V_219 -> V_569 ) ;
V_219 -> V_110 -= V_574 ;
F_50 ( 2 , L_241 , V_147 , V_574 ) ;
}
return 0 ;
}
static inline void F_300 ( struct V_218 * V_219 ,
struct V_56 * V_66 , int V_576 , int * V_240 ,
int V_168 )
{
int V_238 = V_219 -> V_147 - V_219 -> V_569 ;
int V_577 ;
int V_230 ;
char * V_110 ;
int V_578 , V_161 ;
struct V_579 * V_580 ;
V_230 = * V_240 ;
V_110 = V_219 -> V_110 ;
V_578 = ( V_576 == 0 ? 1 : 0 ) ;
if ( V_168 >= 0 ) {
V_110 = V_219 -> V_110 + V_168 ;
V_238 -= V_168 ;
V_578 = 0 ;
}
while ( V_238 > 0 ) {
V_577 = V_400 - ( ( unsigned long ) V_110 % V_400 ) ;
if ( V_238 < V_577 )
V_577 = V_238 ;
V_66 -> V_230 [ V_230 ] . V_235 = V_110 ;
V_66 -> V_230 [ V_230 ] . V_238 = V_577 ;
V_238 -= V_577 ;
if ( ! V_238 ) {
if ( V_578 )
if ( F_297 ( V_219 ) -> V_571 )
V_66 -> V_230 [ V_230 ] . V_239 =
V_581 ;
else
V_66 -> V_230 [ V_230 ] . V_239 = 0 ;
else
V_66 -> V_230 [ V_230 ] . V_239 =
V_582 ;
} else {
if ( V_578 )
V_66 -> V_230 [ V_230 ] . V_239 =
V_581 ;
else
V_66 -> V_230 [ V_230 ] . V_239 =
V_582 ;
}
V_110 += V_577 ;
V_230 ++ ;
V_578 = 0 ;
}
for ( V_161 = 0 ; V_161 < F_297 ( V_219 ) -> V_571 ; V_161 ++ ) {
V_580 = & F_297 ( V_219 ) -> V_583 [ V_161 ] ;
V_66 -> V_230 [ V_230 ] . V_235 = ( char * )
F_301 ( F_302 ( V_580 ) )
+ V_580 -> V_584 ;
V_66 -> V_230 [ V_230 ] . V_238 = V_580 -> V_585 ;
V_66 -> V_230 [ V_230 ] . V_239 = V_582 ;
V_230 ++ ;
}
if ( V_66 -> V_230 [ V_230 - 1 ] . V_239 )
V_66 -> V_230 [ V_230 - 1 ] . V_239 = V_586 ;
* V_240 = V_230 ;
}
static inline int F_303 ( struct V_84 * V_104 ,
struct V_89 * V_217 , struct V_218 * V_219 ,
struct V_587 * V_126 , int V_168 , int V_588 )
{
struct V_56 * V_66 ;
int V_535 = 0 , V_589 , V_590 = 0 ;
V_66 = V_217 -> V_66 ;
F_58 ( & V_219 -> V_227 ) ;
F_304 ( & V_217 -> V_220 , V_219 ) ;
if ( V_126 -> V_126 . V_591 . V_309 == V_592 ) {
int V_230 = V_217 -> V_240 ;
V_589 = sizeof( struct V_593 ) +
( (struct V_593 * ) V_126 ) -> V_478 . V_594 ;
V_66 -> V_230 [ V_230 ] . V_235 = V_219 -> V_110 ;
V_66 -> V_230 [ V_230 ] . V_238 = V_589 ;
V_66 -> V_230 [ V_230 ] . V_239 = V_581 ;
V_217 -> V_240 ++ ;
V_219 -> V_110 += V_589 ;
V_219 -> V_147 -= V_589 ;
V_590 = 1 ;
}
if ( V_168 >= 0 ) {
int V_230 = V_217 -> V_240 ;
V_66 -> V_230 [ V_230 ] . V_235 = V_126 ;
V_66 -> V_230 [ V_230 ] . V_238 = sizeof( struct V_587 ) +
V_588 ;
V_66 -> V_230 [ V_230 ] . V_239 = V_581 ;
V_217 -> V_236 [ V_230 ] = 1 ;
V_217 -> V_240 ++ ;
}
F_300 ( V_219 , V_66 , V_590 ,
( int * ) & V_217 -> V_240 , V_168 ) ;
if ( ! V_104 -> V_440 ) {
F_11 ( V_104 -> V_2 , 6 , L_242 ) ;
F_42 ( & V_217 -> V_44 , V_100 ) ;
V_535 = 1 ;
} else {
F_11 ( V_104 -> V_2 , 6 , L_243 ) ;
if ( V_104 -> V_2 -> V_49 . V_269 )
V_104 -> V_2 -> V_433 . V_595 ++ ;
if ( V_217 -> V_240 >=
F_17 ( V_104 -> V_2 ) ) {
F_42 ( & V_217 -> V_44 , V_100 ) ;
V_535 = 1 ;
}
}
return V_535 ;
}
int F_305 ( struct V_1 * V_2 ,
struct V_84 * V_104 , struct V_218 * V_219 ,
struct V_587 * V_126 , int V_570 ,
int V_168 , int V_588 )
{
struct V_89 * V_66 ;
int V_153 ;
while ( F_41 ( & V_104 -> V_44 , V_442 ,
V_596 ) != V_442 ) ;
V_153 = V_104 -> V_439 ;
V_66 = V_104 -> V_65 [ V_104 -> V_439 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_234 )
goto V_60;
V_104 -> V_439 = ( V_104 -> V_439 + 1 ) %
V_55 ;
F_42 ( & V_104 -> V_44 , V_442 ) ;
F_303 ( V_104 , V_66 , V_219 , V_126 , V_168 , V_588 ) ;
F_278 ( V_104 , V_153 , 1 ) ;
return 0 ;
V_60:
F_42 ( & V_104 -> V_44 , V_442 ) ;
return - V_597 ;
}
int F_306 ( struct V_1 * V_2 , struct V_84 * V_104 ,
struct V_218 * V_219 , struct V_587 * V_126 ,
int V_570 )
{
struct V_89 * V_66 ;
int V_598 ;
int V_521 = 0 ;
int V_440 = 0 ;
int V_30 ;
int V_26 = 0 ;
while ( F_41 ( & V_104 -> V_44 , V_442 ,
V_596 ) != V_442 ) ;
V_598 = V_104 -> V_439 ;
V_66 = V_104 -> V_65 [ V_104 -> V_439 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_234 ) {
F_42 ( & V_104 -> V_44 , V_442 ) ;
return - V_597 ;
}
F_275 ( V_104 ) ;
if ( V_104 -> V_440 ) {
V_440 = 1 ;
if ( ( F_17 ( V_2 ) -
V_66 -> V_240 ) < V_570 ) {
F_42 ( & V_66 -> V_44 , V_100 ) ;
V_521 ++ ;
V_104 -> V_439 =
( V_104 -> V_439 + 1 ) %
V_55 ;
V_66 = V_104 -> V_65 [ V_104 -> V_439 ] ;
if ( F_34 ( & V_66 -> V_44 ) !=
V_234 ) {
F_278 ( V_104 , V_598 ,
V_521 ) ;
F_42 ( & V_104 -> V_44 ,
V_442 ) ;
return - V_597 ;
}
}
}
V_30 = F_303 ( V_104 , V_66 , V_219 , V_126 , - 1 , 0 ) ;
V_104 -> V_439 = ( V_104 -> V_439 + V_30 ) %
V_55 ;
V_521 += V_30 ;
if ( V_521 )
F_278 ( V_104 , V_598 , V_521 ) ;
else if ( ! F_34 ( & V_104 -> V_233 ) )
F_112 ( & V_104 -> V_44 , V_537 ) ;
while ( F_307 ( & V_104 -> V_44 ) ) {
V_521 = 0 ;
V_598 = V_104 -> V_439 ;
V_521 += F_276 ( V_104 ) ;
if ( ! V_521 && ! F_34 ( & V_104 -> V_233 ) )
V_521 += F_277 ( V_104 ) ;
if ( V_521 )
F_278 ( V_104 , V_598 , V_521 ) ;
}
if ( V_104 -> V_2 -> V_49 . V_269 && V_440 )
V_104 -> V_2 -> V_433 . V_538 += V_521 ;
return V_26 ;
}
static int F_308 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_471 * V_599 ;
F_11 ( V_2 , 4 , L_244 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_599 = & ( V_123 -> V_110 . V_458 ) ;
F_254 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_245 , V_123 -> V_126 . V_132 ) ;
V_599 -> V_110 . V_600 = V_601 ;
}
V_2 -> V_3 . V_602 = V_599 -> V_110 . V_600 ;
return 0 ;
}
void F_309 ( struct V_1 * V_2 )
{
enum V_603 V_600 ;
struct V_604 * V_73 = V_2 -> V_73 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_246 ) ;
if ( ( ( V_73 -> V_21 & V_605 ) &&
( V_2 -> V_3 . V_602 == V_606 ) ) ||
( ! ( V_73 -> V_21 & V_605 ) &&
( V_2 -> V_3 . V_602 == V_601 ) ) )
return;
V_600 = V_601 ;
if ( V_73 -> V_21 & V_605 )
V_600 = V_606 ;
F_35 ( V_2 , 4 , L_247 , V_600 ) ;
V_106 = F_256 ( V_2 , V_607 ,
sizeof( struct V_471 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_123 -> V_110 . V_458 . V_110 . V_600 = V_600 ;
F_252 ( V_2 , V_106 , F_308 , NULL ) ;
}
int F_310 ( struct V_604 * V_73 , int V_608 )
{
struct V_1 * V_2 ;
char V_427 [ 15 ] ;
V_2 = V_73 -> V_609 ;
F_11 ( V_2 , 4 , L_248 ) ;
sprintf ( V_427 , L_249 , V_608 ) ;
F_11 ( V_2 , 4 , V_427 ) ;
if ( V_608 < 64 )
return - V_398 ;
if ( V_608 > 65535 )
return - V_398 ;
if ( ( ! F_311 ( V_2 , V_610 ) ) &&
( ! F_192 ( V_2 , V_608 ) ) )
return - V_398 ;
V_73 -> V_396 = V_608 ;
return 0 ;
}
struct V_611 * F_312 ( struct V_604 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_609 ;
F_11 ( V_2 , 5 , L_250 ) ;
return & V_2 -> V_505 ;
}
static int F_313 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_251 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( ! V_2 -> V_49 . V_302 ||
! ( V_2 -> V_3 . V_612 & V_613 ) ) {
memcpy ( V_2 -> V_73 -> V_614 ,
& V_123 -> V_110 . V_458 . V_110 . V_615 . V_235 ,
V_616 ) ;
V_2 -> V_3 . V_612 |= V_613 ;
}
F_254 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
int F_314 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_252 ) ;
V_106 = F_256 ( V_2 , V_617 ,
sizeof( struct V_471 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_123 -> V_110 . V_458 . V_110 . V_615 . V_123 = V_618 ;
V_123 -> V_110 . V_458 . V_110 . V_615 . V_619 = V_616 ;
memcpy ( & V_123 -> V_110 . V_458 . V_110 . V_615 . V_235 ,
V_2 -> V_73 -> V_614 , V_616 ) ;
V_26 = F_252 ( V_2 , V_106 , F_313 ,
NULL ) ;
return V_26 ;
}
static int F_315 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_620 * V_621 ;
F_11 ( V_2 , 4 , L_253 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_621 = & V_123 -> V_110 . V_458 . V_110 . V_622 ;
F_27 ( V_52 , 2 , L_253 ) ;
F_27 ( V_52 , 2 , L_185 , V_2 -> V_72 -> V_73 . V_623 . V_494 ) ;
F_27 ( V_52 , 2 , L_254 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
switch ( V_123 -> V_110 . V_458 . V_126 . V_132 ) {
case V_624 :
case V_625 :
case V_626 :
{
V_2 -> V_49 . V_272 = V_621 -> V_627 ;
if ( V_2 -> V_49 . V_272 == V_273 ) {
F_71 ( & V_2 -> V_72 -> V_73 ,
L_255 ) ;
} else {
F_71 ( & V_2 -> V_72 -> V_73 ,
L_256 ) ;
}
F_50 ( 3 , L_257 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_621 -> V_627 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
break;
}
case V_628 :
{
F_50 ( 3 , L_258 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_621 -> V_627 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_259
L_260 ) ;
V_2 -> V_49 . V_272 = V_273 ;
break;
}
case V_629 :
{
F_50 ( 3 , L_261 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_621 -> V_627 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_262
L_263 ) ;
V_2 -> V_49 . V_272 = V_273 ;
break;
}
case V_630 :
{
F_50 ( 3 , L_261 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_621 -> V_627 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_264 ) ;
V_2 -> V_49 . V_272 = V_273 ;
break;
}
default:
{
F_50 ( 3 , L_265
L_266 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_621 -> V_627 ,
V_123 -> V_110 . V_458 . V_126 . V_132 ) ;
V_2 -> V_49 . V_272 = V_273 ;
break;
}
}
F_254 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
static int F_316 ( struct V_1 * V_2 ,
enum V_631 V_272 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_620 * V_621 ;
F_11 ( V_2 , 4 , L_267 ) ;
F_27 ( V_52 , 2 , L_267 ) ;
F_27 ( V_52 , 2 , L_185 , V_2 -> V_72 -> V_73 . V_623 . V_494 ) ;
V_106 = F_256 ( V_2 , V_632 ,
sizeof( struct V_633 ) +
sizeof( struct V_620 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
V_621 = & V_123 -> V_110 . V_458 . V_110 . V_622 ;
V_621 -> V_627 = V_272 ;
V_26 = F_252 ( V_2 , V_106 , F_315 ,
NULL ) ;
F_27 ( V_52 , 2 , L_254 , V_26 ) ;
return V_26 ;
}
int F_317 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
F_11 ( V_2 , 4 , L_268 ) ;
if ( ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) &&
F_318 ( V_2 , V_632 ) ) {
V_26 = F_316 ( V_2 ,
V_2 -> V_49 . V_272 ) ;
if ( V_26 ) {
F_50 ( 3 ,
L_269 ,
V_2 -> V_72 -> V_73 . V_623 . V_494 ,
V_26 ) ;
}
} else if ( V_2 -> V_49 . V_272 != V_273 ) {
V_2 -> V_49 . V_272 = V_273 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_259
L_260 ) ;
V_26 = - V_335 ;
}
return V_26 ;
}
void F_319 ( struct V_604 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_609 ;
F_11 ( V_2 , 4 , L_270 ) ;
V_2 -> V_505 . V_532 ++ ;
F_54 ( V_2 ) ;
}
int F_320 ( struct V_604 * V_73 , int V_634 , int V_635 )
{
struct V_1 * V_2 = V_73 -> V_609 ;
int V_26 = 0 ;
switch ( V_635 ) {
case V_636 :
V_26 = V_637 ;
if ( ( V_2 -> V_3 . V_10 != V_13 ) &&
( V_2 -> V_3 . V_10 != V_638 ) &&
( V_2 -> V_3 . V_10 != V_14 ) )
V_26 |= V_639 ;
break;
case V_640 :
V_26 = V_641 | V_642 | V_643 |
V_644 | V_645 | V_646 | V_647 |
V_648 ;
break;
case V_649 :
V_26 = ( V_73 -> V_614 [ 0 ] << 16 ) | ( V_73 -> V_614 [ 1 ] << 8 ) |
V_73 -> V_614 [ 2 ] ;
V_26 = ( V_26 >> 5 ) & 0xFFFF ;
break;
case V_650 :
V_26 = ( V_73 -> V_614 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_651 :
V_26 = V_652 ;
break;
case V_653 :
V_26 = V_654 | V_655 | V_656 | V_657 |
V_658 | V_659 ;
break;
case V_660 :
break;
case V_661 :
break;
case V_662 :
break;
case V_663 :
break;
case V_664 :
V_26 = V_2 -> V_505 . V_665 ;
break;
case V_666 :
break;
case V_667 :
break;
case V_668 :
break;
case V_669 :
break;
case V_670 :
break;
case V_671 :
break;
case V_672 :
break;
default:
break;
}
return V_26 ;
}
static int F_321 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_147 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_376 )
{
V_170 V_673 , V_674 ;
F_11 ( V_2 , 4 , L_271 ) ;
memcpy ( V_106 -> V_110 , V_456 , V_383 ) ;
memcpy ( F_251 ( V_106 -> V_110 ) ,
& V_2 -> V_349 . V_409 , V_365 ) ;
V_673 = ( V_675 ) V_383 + V_147 ;
V_674 = ( V_675 ) V_147 ;
memcpy ( F_322 ( V_106 -> V_110 ) , & V_673 , 2 ) ;
memcpy ( F_323 ( V_106 -> V_110 ) , & V_674 , 2 ) ;
memcpy ( F_324 ( V_106 -> V_110 ) , & V_674 , 2 ) ;
memcpy ( F_325 ( V_106 -> V_110 ) , & V_674 , 2 ) ;
return F_174 ( V_2 , V_383 + V_147 , V_106 ,
F_175 , V_376 ) ;
}
static int F_326 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_676 )
{
struct V_122 * V_123 ;
struct V_677 * V_678 ;
struct V_679 * V_680 ;
unsigned char * V_110 ;
V_169 V_569 ;
F_11 ( V_2 , 3 , L_272 ) ;
V_123 = (struct V_122 * ) V_676 ;
V_110 = ( unsigned char * ) ( ( char * ) V_123 - V_118 -> V_168 ) ;
V_678 = (struct V_677 * ) V_118 -> V_379 ;
V_680 = & V_123 -> V_110 . V_458 . V_110 . V_680 ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_273 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
if ( V_123 -> V_110 . V_458 . V_126 . V_132 ) {
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_458 . V_126 . V_132 ;
F_35 ( V_2 , 4 , L_274 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
V_569 = * ( ( V_169 * ) F_323 ( V_110 ) ) ;
if ( V_123 -> V_110 . V_458 . V_126 . V_469 == 1 )
V_569 -= ( V_169 ) ( ( char * ) & V_680 -> V_110 - ( char * ) V_123 ) ;
else
V_569 -= ( V_169 ) ( ( char * ) & V_680 -> V_681 - ( char * ) V_123 ) ;
if ( ( V_678 -> V_682 - V_678 -> V_683 ) < V_569 ) {
F_35 ( V_2 , 4 , L_275 , - V_39 ) ;
V_123 -> V_126 . V_132 = - V_39 ;
return 0 ;
}
F_35 ( V_2 , 4 , L_276 ,
V_123 -> V_110 . V_458 . V_126 . V_468 ) ;
F_35 ( V_2 , 4 , L_277 ,
V_123 -> V_110 . V_458 . V_126 . V_469 ) ;
if ( V_123 -> V_110 . V_458 . V_126 . V_469 == 1 ) {
memcpy ( V_678 -> V_684 + V_678 -> V_683 ,
( char * ) V_680 ,
V_569 + F_327 ( struct V_679 , V_110 ) ) ;
V_678 -> V_683 += F_327 ( struct V_679 , V_110 ) ;
} else {
memcpy ( V_678 -> V_684 + V_678 -> V_683 ,
( char * ) & V_680 -> V_681 , V_569 ) ;
}
V_678 -> V_683 += V_569 ;
F_35 ( V_2 , 4 , L_278 ,
V_123 -> V_110 . V_458 . V_126 . V_468 ) ;
F_35 ( V_2 , 4 , L_279 ,
V_123 -> V_110 . V_458 . V_126 . V_469 ) ;
if ( V_123 -> V_110 . V_458 . V_126 . V_469 <
V_123 -> V_110 . V_458 . V_126 . V_468 )
return 1 ;
return 0 ;
}
int F_328 ( struct V_1 * V_2 , char T_4 * V_684 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_685 * V_686 ;
int V_687 ;
struct V_677 V_678 = { 0 , } ;
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_280 ) ;
if ( V_2 -> V_3 . V_4 )
return - V_335 ;
if ( ( ! F_318 ( V_2 , V_688 ) ) &&
( ! V_2 -> V_49 . V_302 ) ) {
return - V_335 ;
}
if ( F_329 ( & V_687 , V_684 + sizeof( int ) , sizeof( int ) ) )
return - V_689 ;
V_686 = F_330 ( V_684 , V_687 + sizeof( struct V_690 ) ) ;
if ( F_97 ( V_686 ) ) {
F_11 ( V_2 , 2 , L_281 ) ;
return F_98 ( V_686 ) ;
}
V_678 . V_682 = V_686 -> V_126 . V_569 ;
V_678 . V_684 = F_15 ( V_678 . V_682 , V_38 ) ;
if ( ! V_678 . V_684 ) {
F_20 ( V_686 ) ;
return - V_39 ;
}
V_678 . V_683 = sizeof( struct V_690 ) ;
V_106 = F_256 ( V_2 , V_688 ,
V_691 + V_687 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_383 ) ;
memcpy ( & V_123 -> V_110 . V_458 . V_110 . V_680 , & V_686 -> V_123 , V_687 ) ;
V_26 = F_321 ( V_2 , V_106 , V_692 + V_687 ,
F_326 , ( void * ) & V_678 ) ;
if ( V_26 )
F_50 ( 2 , L_282 ,
F_63 ( V_2 ) , V_26 ) ;
else {
if ( F_331 ( V_684 , V_678 . V_684 , V_678 . V_682 ) )
V_26 = - V_689 ;
}
F_20 ( V_686 ) ;
F_20 ( V_678 . V_684 ) ;
return V_26 ;
}
static inline int F_332 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
return 2 ;
default:
return 0 ;
}
}
static void F_333 ( struct V_1 * V_2 )
{
int V_26 ;
int V_238 ;
char * V_341 ;
struct V_178 * V_693 ;
int V_694 = 0 ;
F_24 ( V_52 , 2 , L_283 ) ;
V_693 = F_26 ( V_2 ) ;
if ( ! V_693 -> V_695 ) {
V_694 = 1 ;
V_26 = F_334 ( V_693 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_135 , V_26 ) ;
goto V_60;
}
}
V_26 = F_148 ( V_2 , ( void * * ) & V_341 , & V_238 ) ;
if ( V_26 ) {
F_50 ( 2 , L_284 ,
F_51 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_696;
}
F_151 ( V_2 , V_341 ) ;
F_152 ( V_2 , V_341 ) ;
F_20 ( V_341 ) ;
V_26 = F_335 ( V_693 , & V_2 -> V_697 ) ;
if ( V_26 )
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
F_27 ( V_52 , 2 , L_285 , V_2 -> V_697 . V_698 ) ;
F_27 ( V_52 , 2 , L_286 , V_2 -> V_697 . V_699 ) ;
F_27 ( V_52 , 2 , L_286 , V_2 -> V_697 . V_700 ) ;
F_27 ( V_52 , 2 , L_287 , V_2 -> V_697 . V_701 ) ;
if ( ! ( ( V_2 -> V_697 . V_698 != V_702 ) ||
( ( V_2 -> V_697 . V_699 & V_703 ) == 0 ) ||
( ( V_2 -> V_697 . V_700 & V_704 ) == 0 ) ) ) {
F_71 ( & V_2 -> V_72 -> V_73 ,
L_288 ) ;
} else {
V_2 -> V_49 . V_50 = V_543 ;
}
V_696:
if ( V_694 == 1 )
F_336 ( V_693 ) ;
V_60:
return;
}
static inline void F_337 ( struct V_1 * V_2 ,
struct V_56 * * V_705 ,
void (* * F_338) ( struct V_178 * , int , unsigned long ) ) {
int V_33 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
int V_168 = V_55 *
( V_2 -> V_35 . V_59 - 1 ) ;
V_33 = V_55 * ( V_2 -> V_35 . V_59 - 1 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_705 [ V_168 + V_33 ] = (struct V_56 * )
F_290 ( V_2 -> V_35 . V_53 -> V_65 [ V_33 ] . V_66 ) ;
}
F_338 [ V_2 -> V_35 . V_59 - 1 ] = NULL ;
}
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_706 V_707 ;
char * V_708 ;
struct V_56 * * V_705 ;
void (* * F_338) ( struct V_178 * , int , unsigned long );
struct V_56 * * V_709 ;
int V_33 , V_34 , V_710 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_289 ) ;
V_708 = F_15 ( V_55 * sizeof( char ) ,
V_38 ) ;
if ( ! V_708 ) {
V_26 = - V_39 ;
goto V_711;
}
F_217 ( V_2 , V_708 ) ;
F_221 ( V_2 , V_708 ) ;
V_705 = F_15 ( V_2 -> V_35 . V_59 *
V_55 * sizeof( void * ) ,
V_38 ) ;
if ( ! V_705 ) {
V_26 = - V_39 ;
goto V_712;
}
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_705 [ V_33 ] = (struct V_56 * )
F_290 ( V_2 -> V_35 . V_243 -> V_65 [ V_33 ] . V_66 ) ;
}
F_338 = F_15 ( sizeof( void * ) * V_2 -> V_35 . V_59 ,
V_38 ) ;
if ( ! F_338 ) {
V_26 = - V_39 ;
goto V_713;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_59 ; ++ V_33 )
F_338 [ V_33 ] = V_2 -> V_277 . V_714 ;
F_337 ( V_2 , V_705 , F_338 ) ;
V_709 =
F_15 ( V_2 -> V_35 . V_68 * V_55 *
sizeof( void * ) , V_38 ) ;
if ( ! V_709 ) {
V_26 = - V_39 ;
goto V_715;
}
for ( V_33 = 0 , V_710 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 )
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 , ++ V_710 ) {
V_709 [ V_710 ] = (struct V_56 * ) F_290 (
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] -> V_66 ) ;
}
memset ( & V_707 , 0 , sizeof( struct V_706 ) ) ;
V_707 . V_179 = F_26 ( V_2 ) ;
V_707 . V_716 = F_332 ( V_2 ) ;
V_707 . V_717 = 0 ;
V_707 . V_708 = V_708 ;
V_707 . V_718 = V_2 -> V_35 . V_59 ;
V_707 . V_719 = V_2 -> V_35 . V_68 ;
V_707 . V_720 = V_2 -> V_277 . V_720 ;
V_707 . V_721 = V_2 -> V_277 . V_721 ;
V_707 . F_338 = F_338 ;
V_707 . V_722 = ( unsigned long ) V_2 ;
V_707 . V_723 = ( void * * ) V_705 ;
V_707 . V_724 = ( void * * ) V_709 ;
V_707 . V_725 = V_2 -> V_35 . V_67 ;
V_707 . V_726 =
( V_2 -> V_3 . type == V_6 ) ? 8 : 32 ;
if ( F_41 ( & V_2 -> V_35 . V_44 , V_330 ,
V_326 ) == V_330 ) {
V_26 = F_339 ( & V_707 ) ;
if ( V_26 ) {
F_42 ( & V_2 -> V_35 . V_44 , V_330 ) ;
goto V_60;
}
V_26 = F_340 ( & V_707 ) ;
if ( V_26 ) {
F_42 ( & V_2 -> V_35 . V_44 , V_330 ) ;
F_147 ( F_26 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_49 . V_50 ) {
case V_51 :
F_71 ( & V_2 -> V_72 -> V_73 , L_290 ) ;
break;
case V_274 :
F_71 ( & V_2 -> V_72 -> V_73 , L_291 ) ;
break;
default:
break;
}
V_60:
F_20 ( V_709 ) ;
V_715:
F_20 ( F_338 ) ;
V_713:
F_20 ( V_705 ) ;
V_712:
F_20 ( V_708 ) ;
V_711:
return V_26 ;
}
static void F_341 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_292 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
F_115 ( & V_2 -> V_107 ) ;
F_115 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_73 )
F_342 ( V_2 -> V_73 ) ;
F_20 ( V_2 -> V_285 ) ;
F_111 ( V_2 ) ;
F_343 ( & V_2 -> V_296 ) ;
F_20 ( V_2 ) ;
}
static int F_344 ( const char * V_217 , struct V_727 * V_728 ,
unsigned long V_729 )
{
return F_345 ( V_728 , V_729 ,
& V_730 , 3 , V_217 ) ;
}
int F_346 ( struct V_1 * V_2 )
{
int V_731 = 0 ;
int V_26 ;
F_24 ( V_52 , 2 , L_293 ) ;
F_42 ( & V_2 -> V_510 , 0 ) ;
F_116 ( V_2 ) ;
V_732:
if ( V_731 )
F_50 ( 2 , L_294 ,
F_51 ( & V_2 -> V_72 -> V_73 ) ) ;
F_336 ( F_26 ( V_2 ) ) ;
F_336 ( F_347 ( V_2 ) ) ;
F_336 ( F_135 ( V_2 ) ) ;
V_26 = F_334 ( F_135 ( V_2 ) ) ;
if ( V_26 )
goto V_733;
V_26 = F_334 ( F_347 ( V_2 ) ) ;
if ( V_26 )
goto V_733;
V_26 = F_334 ( F_26 ( V_2 ) ) ;
if ( V_26 )
goto V_733;
V_26 = F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
V_733:
if ( V_26 == - V_319 ) {
F_24 ( V_52 , 2 , L_295 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
if ( ++ V_731 > 3 )
goto V_60;
else
goto V_732;
}
F_333 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
V_26 = F_157 ( & V_2 -> V_107 , F_169 ) ;
if ( V_26 == - V_319 ) {
F_24 ( V_52 , 2 , L_296 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_135 , V_26 ) ;
if ( -- V_731 < 0 )
goto V_60;
else
goto V_732;
}
V_26 = F_157 ( & V_2 -> V_142 , F_166 ) ;
if ( V_26 == - V_319 ) {
F_24 ( V_52 , 2 , L_297 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_180 , V_26 ) ;
if ( -- V_731 < 0 )
goto V_60;
else
goto V_732;
}
V_2 -> V_116 = 0 ;
V_26 = F_227 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_60;
}
V_2 -> V_49 . V_472 . V_462 = 0 ;
V_2 -> V_49 . V_461 . V_462 = 0 ;
V_2 -> V_3 . V_476 = 0 ;
F_259 ( V_2 , V_386 ) ;
if ( F_311 ( V_2 , V_734 ) )
F_257 ( V_2 ) ;
if ( F_318 ( V_2 , V_735 ) )
F_261 ( V_2 ) ;
return 0 ;
V_60:
F_49 ( & V_2 -> V_72 -> V_73 , L_100
L_101 ) ;
F_50 ( 2 , L_298 ,
F_51 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
return V_26 ;
}
static inline int F_348 ( struct V_435 * V_736 ,
struct V_737 * V_230 ,
struct V_218 * * V_738 , int V_168 , int * V_739 , int V_569 )
{
struct V_431 * V_431 = F_240 ( V_230 -> V_235 ) ;
if ( * V_738 == NULL ) {
if ( V_736 -> V_244 ) {
* V_738 = V_736 -> V_244 ;
V_736 -> V_244 = NULL ;
} else {
* V_738 = F_244 ( V_436 + V_437 ) ;
if ( ! ( * V_738 ) )
return - V_39 ;
}
F_349 ( * V_738 , V_437 ) ;
if ( V_569 <= V_436 ) {
memcpy ( F_350 ( * V_738 , V_569 ) , V_230 -> V_235 + V_168 ,
V_569 ) ;
} else {
F_351 ( V_431 ) ;
memcpy ( F_350 ( * V_738 , V_436 ) ,
V_230 -> V_235 + V_168 , V_436 ) ;
F_352 ( * V_738 , * V_739 , V_431 ,
V_168 + V_436 ,
V_569 - V_436 ) ;
( * V_738 ) -> V_569 += V_569 - V_436 ;
( * V_738 ) -> V_147 += V_569 - V_436 ;
( * V_738 ) -> V_740 += V_569 - V_436 ;
( * V_739 ) ++ ;
}
} else {
F_351 ( V_431 ) ;
F_352 ( * V_738 , * V_739 , V_431 , V_168 , V_569 ) ;
( * V_738 ) -> V_569 += V_569 ;
( * V_738 ) -> V_147 += V_569 ;
( * V_738 ) -> V_740 += V_569 ;
( * V_739 ) ++ ;
}
return 0 ;
}
struct V_218 * F_353 ( struct V_1 * V_2 ,
struct V_435 * V_736 ,
struct V_737 * * V_741 , int * V_742 ,
struct V_587 * * V_126 )
{
struct V_737 * V_230 = * V_741 ;
struct V_56 * V_66 = V_736 -> V_66 ;
int V_168 = * V_742 ;
struct V_218 * V_219 = NULL ;
int V_743 = 0 ;
void * V_744 ;
int V_569 ;
int V_745 = 0 ;
int V_746 = 0 ;
int V_580 = 0 ;
if ( V_230 -> V_238 < V_168 + sizeof( struct V_587 ) ) {
if ( F_354 ( V_230 ) )
return NULL ;
V_230 ++ ;
V_168 = 0 ;
if ( V_230 -> V_238 < sizeof( struct V_587 ) )
return NULL ;
}
* V_126 = V_230 -> V_235 + V_168 ;
V_168 += sizeof( struct V_587 ) ;
switch ( ( * V_126 ) -> V_126 . V_747 . V_309 ) {
case V_748 :
V_743 = ( * V_126 ) -> V_126 . V_747 . V_749 ;
break;
case V_750 :
V_743 = ( * V_126 ) -> V_126 . V_591 . V_238 ;
if ( ( V_2 -> V_3 . V_10 == V_16 ) ||
( V_2 -> V_3 . V_10 == V_12 ) )
V_745 = V_751 ;
else
V_745 = V_437 ;
break;
case V_752 :
V_743 = ( * V_126 ) -> V_126 . V_753 . V_754 ;
V_745 = sizeof( struct V_587 ) ;
break;
default:
break;
}
if ( ! V_743 )
return NULL ;
if ( ( ( V_743 >= V_2 -> V_49 . V_270 ) &&
( ! ( V_2 -> V_3 . type == V_9 ) ) &&
( ! F_34 ( & V_2 -> V_510 ) ) ) ||
( V_2 -> V_49 . V_50 == V_51 ) ) {
V_746 = 1 ;
} else {
V_219 = F_244 ( V_743 + V_745 ) ;
if ( ! V_219 )
goto V_755;
if ( V_745 )
F_349 ( V_219 , V_745 ) ;
}
V_744 = V_230 -> V_235 + V_168 ;
while ( V_743 ) {
V_569 = F_355 ( V_743 , ( int ) ( V_230 -> V_238 - V_168 ) ) ;
if ( V_569 ) {
if ( V_746 ) {
if ( F_348 ( V_736 , V_230 ,
& V_219 , V_168 , & V_580 , V_569 ) )
goto V_755;
} else {
memcpy ( F_350 ( V_219 , V_569 ) , V_744 ,
V_569 ) ;
}
}
V_743 -= V_569 ;
if ( V_743 ) {
if ( F_354 ( V_230 ) ) {
F_11 ( V_2 , 4 , L_299 ) ;
F_356 ( V_2 , 2 , V_66 , sizeof( void * ) ) ;
F_108 ( V_219 ) ;
V_2 -> V_505 . V_665 ++ ;
return NULL ;
}
V_230 ++ ;
V_168 = 0 ;
V_744 = V_230 -> V_235 ;
} else {
V_168 += V_569 ;
}
}
* V_741 = V_230 ;
* V_742 = V_168 ;
if ( V_746 && V_2 -> V_49 . V_269 ) {
V_2 -> V_433 . V_756 ++ ;
V_2 -> V_433 . V_757 += F_297 ( V_219 ) -> V_571 ;
}
return V_219 ;
V_755:
if ( F_357 () ) {
F_11 ( V_2 , 2 , L_300 ) ;
}
V_2 -> V_505 . V_506 ++ ;
return NULL ;
}
static void F_358 ( void )
{
int V_758 ;
for ( V_758 = 0 ; V_758 < V_759 ; V_758 ++ ) {
F_359 ( V_760 [ V_758 ] . V_309 ) ;
V_760 [ V_758 ] . V_309 = NULL ;
}
}
void F_360 ( T_5 * V_309 , int V_368 , char * V_761 , ... )
{
char V_762 [ 32 ] ;
T_6 args ;
if ( V_368 > V_309 -> V_368 )
return;
va_start ( args , V_761 ) ;
vsnprintf ( V_762 , sizeof( V_762 ) , V_761 , args ) ;
va_end ( args ) ;
F_361 ( V_309 , V_368 , V_762 ) ;
}
static int F_362 ( void )
{
int V_333 ;
int V_758 ;
for ( V_758 = 0 ; V_758 < V_759 ; V_758 ++ ) {
V_760 [ V_758 ] . V_309 = F_363 ( V_760 [ V_758 ] . V_494 ,
V_760 [ V_758 ] . V_763 ,
V_760 [ V_758 ] . V_764 ,
V_760 [ V_758 ] . V_147 ) ;
if ( V_760 [ V_758 ] . V_309 == NULL ) {
F_358 () ;
return - V_39 ;
}
V_333 = F_364 ( V_760 [ V_758 ] . V_309 , V_760 [ V_758 ] . V_765 ) ;
if ( V_333 ) {
F_358 () ;
return V_333 ;
}
F_365 ( V_760 [ V_758 ] . V_309 , V_760 [ V_758 ] . V_368 ) ;
}
return 0 ;
}
int F_366 ( struct V_1 * V_2 ,
enum V_766 V_277 )
{
int V_26 = 0 ;
switch ( V_277 ) {
case V_767 :
V_2 -> V_277 . V_768 = F_367 (
F_368 ( V_769 ) ,
L_301 ) ;
break;
case V_770 :
V_2 -> V_277 . V_768 = F_367 (
F_368 ( V_771 ) ,
L_302 ) ;
break;
}
if ( ! V_2 -> V_277 . V_768 ) {
F_30 ( & V_2 -> V_72 -> V_73 , L_303
L_304 , V_277 ) ;
V_26 = - V_398 ;
}
return V_26 ;
}
void F_369 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 . V_302 )
F_370 ( V_771 ) ;
else
F_370 ( V_769 ) ;
V_2 -> V_277 . V_768 = NULL ;
}
static int F_371 ( struct V_772 * V_72 )
{
struct V_1 * V_2 ;
struct V_727 * V_73 ;
int V_26 ;
unsigned long V_21 ;
char V_773 [ 20 ] ;
F_24 ( V_52 , 2 , L_305 ) ;
V_73 = & V_72 -> V_73 ;
if ( ! F_372 ( V_73 ) )
return - V_774 ;
F_27 ( V_52 , 2 , L_185 , F_51 ( & V_72 -> V_73 ) ) ;
V_2 = F_132 () ;
if ( ! V_2 ) {
F_27 ( V_52 , 2 , L_35 , - V_39 ) ;
V_26 = - V_39 ;
goto V_775;
}
snprintf ( V_773 , sizeof( V_773 ) , L_306 ,
F_51 ( & V_72 -> V_73 ) ) ;
V_2 -> V_776 = F_363 ( V_773 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_776 ) {
F_27 ( V_52 , 2 , L_185 , L_307 ) ;
V_26 = - V_39 ;
goto V_777;
}
F_364 ( V_2 -> V_776 , & V_778 ) ;
V_2 -> V_107 . V_112 = V_72 -> V_179 [ 0 ] ;
V_2 -> V_142 . V_112 = V_72 -> V_179 [ 1 ] ;
V_2 -> V_110 . V_112 = V_72 -> V_179 [ 2 ] ;
F_373 ( & V_72 -> V_73 , V_2 ) ;
V_2 -> V_72 = V_72 ;
V_72 -> V_179 [ 0 ] -> V_779 = F_99 ;
V_72 -> V_179 [ 1 ] -> V_779 = F_99 ;
V_72 -> V_179 [ 2 ] -> V_779 = F_99 ;
V_26 = F_134 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_135 , V_26 ) ;
goto V_780;
}
V_26 = F_125 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_130 , V_26 ) ;
goto V_780;
}
if ( V_2 -> V_3 . type == V_9 )
V_26 = F_374 ( V_73 ) ;
else
V_26 = F_375 ( V_73 ) ;
if ( V_26 )
goto V_780;
switch ( V_2 -> V_3 . type ) {
case V_9 :
case V_7 :
V_26 = F_366 ( V_2 , V_770 ) ;
if ( V_26 )
goto V_781;
V_26 = V_2 -> V_277 . V_768 -> V_782 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_783;
case V_5 :
case V_8 :
default:
break;
}
F_376 ( & V_784 . V_785 , V_21 ) ;
F_83 ( & V_2 -> V_31 , & V_784 . V_31 ) ;
F_377 ( & V_784 . V_785 , V_21 ) ;
F_333 ( V_2 ) ;
return 0 ;
V_783:
F_369 ( V_2 ) ;
V_781:
if ( V_2 -> V_3 . type == V_9 )
F_378 ( V_73 ) ;
else
F_379 ( V_73 ) ;
V_780:
F_359 ( V_2 -> V_776 ) ;
V_777:
F_341 ( V_2 ) ;
V_775:
F_380 ( V_73 ) ;
return V_26 ;
}
static void F_381 ( struct V_772 * V_72 )
{
unsigned long V_21 ;
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
F_24 ( V_52 , 2 , L_308 ) ;
if ( V_2 -> V_3 . type == V_9 ) {
F_378 ( & V_72 -> V_73 ) ;
} else {
F_379 ( & V_72 -> V_73 ) ;
}
if ( V_2 -> V_277 . V_768 ) {
V_2 -> V_277 . V_768 -> remove ( V_72 ) ;
F_369 ( V_2 ) ;
}
F_359 ( V_2 -> V_776 ) ;
F_376 ( & V_784 . V_785 , V_21 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_377 ( & V_784 . V_785 , V_21 ) ;
F_341 ( V_2 ) ;
F_373 ( & V_72 -> V_73 , NULL ) ;
F_380 ( & V_72 -> V_73 ) ;
return;
}
static int F_383 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
int V_26 = 0 ;
int V_786 ;
if ( ! V_2 -> V_277 . V_768 ) {
if ( V_2 -> V_3 . type == V_6 )
V_786 = V_767 ;
else
V_786 = V_770 ;
V_26 = F_366 ( V_2 , V_786 ) ;
if ( V_26 )
goto V_787;
V_26 = V_2 -> V_277 . V_768 -> V_782 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_787;
}
V_26 = V_2 -> V_277 . V_768 -> V_788 ( V_72 ) ;
V_787:
return V_26 ;
}
static int F_384 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
return V_2 -> V_277 . V_768 -> V_789 ( V_72 ) ;
}
static void F_385 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_790 )
V_2 -> V_277 . V_768 -> V_790 ( V_72 ) ;
}
static int F_386 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_791 )
return V_2 -> V_277 . V_768 -> V_791 ( V_72 ) ;
return 0 ;
}
static void F_387 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_792 )
V_2 -> V_277 . V_768 -> V_792 ( V_72 ) ;
}
static int F_388 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_793 )
return V_2 -> V_277 . V_768 -> V_793 ( V_72 ) ;
return 0 ;
}
static int F_389 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_794 )
return V_2 -> V_277 . V_768 -> V_794 ( V_72 ) ;
return 0 ;
}
static int F_390 ( struct V_772 * V_72 )
{
struct V_1 * V_2 = F_382 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_277 . V_768 &&
V_2 -> V_277 . V_768 -> V_795 )
return V_2 -> V_277 . V_768 -> V_795 ( V_72 ) ;
return 0 ;
}
static T_7
F_391 ( struct V_796 * V_797 , const char * V_217 ,
T_8 V_151 )
{
int V_787 ;
V_787 = F_344 ( V_217 , V_798 ,
V_799 . V_729 ) ;
if ( V_787 )
return V_787 ;
else
return V_151 ;
}
int F_392 ( struct V_604 * V_73 , int V_800 )
{
switch ( V_800 ) {
case V_801 :
return ( sizeof( V_802 ) / V_803 ) ;
default:
return - V_398 ;
}
}
void F_393 ( struct V_604 * V_73 ,
struct V_804 * V_505 , T_9 * V_110 )
{
struct V_1 * V_2 = V_73 -> V_609 ;
V_110 [ 0 ] = V_2 -> V_505 . V_805 -
V_2 -> V_433 . V_806 ;
V_110 [ 1 ] = V_2 -> V_433 . V_807 ;
V_110 [ 2 ] = V_2 -> V_505 . V_808 -
V_2 -> V_433 . V_809 ;
V_110 [ 3 ] = V_2 -> V_433 . V_534 ;
V_110 [ 4 ] = V_2 -> V_505 . V_808 - V_2 -> V_433 . V_809
- V_2 -> V_433 . V_595 ;
V_110 [ 5 ] = V_2 -> V_433 . V_534 - V_2 -> V_433 . V_538 ;
V_110 [ 6 ] = V_2 -> V_433 . V_595 ;
V_110 [ 7 ] = V_2 -> V_433 . V_538 ;
V_110 [ 8 ] = V_2 -> V_433 . V_810 ;
V_110 [ 9 ] = V_2 -> V_433 . V_811 ;
V_110 [ 10 ] = V_2 -> V_433 . V_756 ;
V_110 [ 11 ] = V_2 -> V_433 . V_757 ;
V_110 [ 12 ] = V_2 -> V_433 . V_434 ;
V_110 [ 13 ] = ( V_2 -> V_433 . V_812 >> 10 ) ;
V_110 [ 14 ] = V_2 -> V_433 . V_813 ;
V_110 [ 15 ] = V_2 -> V_433 . V_520 ;
V_110 [ 16 ] = V_2 -> V_433 . V_523 ;
V_110 [ 17 ] = V_522 ;
V_110 [ 18 ] = V_519 ;
V_110 [ 19 ] = F_34 ( & V_2 -> V_35 . V_70 [ 0 ] -> V_441 ) ;
V_110 [ 20 ] = ( V_2 -> V_35 . V_68 > 1 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 1 ] -> V_441 ) : 0 ;
V_110 [ 21 ] = ( V_2 -> V_35 . V_68 > 2 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 2 ] -> V_441 ) : 0 ;
V_110 [ 22 ] = ( V_2 -> V_35 . V_68 > 3 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 3 ] -> V_441 ) : 0 ;
V_110 [ 23 ] = V_2 -> V_433 . V_814 ;
V_110 [ 24 ] = V_2 -> V_433 . V_815 ;
V_110 [ 25 ] = V_2 -> V_433 . V_514 ;
V_110 [ 26 ] = V_2 -> V_433 . V_512 ;
V_110 [ 27 ] = V_2 -> V_433 . V_557 ;
V_110 [ 28 ] = V_2 -> V_433 . V_553 ;
V_110 [ 29 ] = V_2 -> V_433 . V_816 ;
V_110 [ 30 ] = V_2 -> V_433 . V_817 ;
V_110 [ 31 ] = V_2 -> V_433 . V_531 ;
V_110 [ 32 ] = V_2 -> V_433 . V_527 ;
V_110 [ 33 ] = V_2 -> V_433 . V_818 ;
V_110 [ 34 ] = V_2 -> V_433 . V_819 ;
V_110 [ 35 ] = V_2 -> V_433 . V_545 ;
V_110 [ 36 ] = V_2 -> V_433 . V_549 ;
}
void F_394 ( struct V_604 * V_73 , V_675 V_800 , T_3 * V_110 )
{
switch ( V_800 ) {
case V_801 :
memcpy ( V_110 , & V_802 ,
sizeof( V_802 ) ) ;
break;
default:
F_57 ( 1 ) ;
break;
}
}
void F_395 ( struct V_604 * V_73 ,
struct V_820 * V_3 )
{
struct V_1 * V_2 = V_73 -> V_609 ;
if ( V_2 -> V_49 . V_302 )
strcpy ( V_3 -> V_821 , L_302 ) ;
else
strcpy ( V_3 -> V_821 , L_301 ) ;
strcpy ( V_3 -> V_822 , L_309 ) ;
strcpy ( V_3 -> V_823 , V_2 -> V_3 . V_297 ) ;
sprintf ( V_3 -> V_824 , L_310 ,
F_396 ( V_2 ) ,
F_397 ( V_2 ) ,
F_398 ( V_2 ) ) ;
}
int F_399 ( struct V_604 * V_825 ,
struct V_826 * V_827 )
{
struct V_1 * V_2 = V_825 -> V_609 ;
enum V_443 V_10 ;
if ( ( V_2 -> V_3 . type == V_6 ) || ( V_2 -> V_3 . V_4 ) )
V_10 = V_14 ;
else
V_10 = V_2 -> V_3 . V_10 ;
V_827 -> V_828 = V_829 ;
V_827 -> V_830 = V_831 ;
V_827 -> V_832 = V_833 ;
V_827 -> V_834 = V_835 ;
V_827 -> V_836 = V_837 ;
switch ( V_10 ) {
case V_11 :
case V_15 :
V_827 -> V_830 |= V_838 |
V_839 |
V_840 |
V_841 |
V_842 ;
V_827 -> V_832 |= V_843 |
V_844 |
V_845 |
V_846 |
V_847 ;
V_827 -> V_848 = V_849 ;
V_827 -> V_850 = V_851 ;
break;
case V_13 :
case V_17 :
V_827 -> V_830 |= V_838 |
V_839 |
V_840 |
V_841 |
V_852 |
V_853 |
V_854 ;
V_827 -> V_832 |= V_843 |
V_844 |
V_845 |
V_846 |
V_855 |
V_856 |
V_857 ;
V_827 -> V_848 = V_858 ;
V_827 -> V_850 = V_859 ;
break;
case V_14 :
V_827 -> V_830 |= V_838 |
V_839 |
V_840 |
V_841 |
V_852 |
V_853 |
V_860 |
V_854 ;
V_827 -> V_832 |= V_843 |
V_844 |
V_845 |
V_846 |
V_855 |
V_856 |
V_861 |
V_857 ;
V_827 -> V_848 = V_862 ;
V_827 -> V_850 = V_859 ;
break;
default:
V_827 -> V_830 |= V_838 |
V_839 |
V_842 ;
V_827 -> V_832 |= V_843 |
V_844 |
V_847 ;
V_827 -> V_848 = V_863 ;
V_827 -> V_850 = V_851 ;
}
return 0 ;
}
static int T_10 F_400 ( void )
{
int V_26 ;
F_401 ( L_311 ) ;
F_119 ( & V_784 . V_31 ) ;
F_402 ( & V_784 . V_785 ) ;
V_26 = F_362 () ;
if ( V_26 )
goto V_864;
V_26 = F_403 ( & V_730 ) ;
if ( V_26 )
goto V_865;
V_26 = F_404 ( & V_799 ) ;
if ( V_26 )
goto V_866;
V_26 = F_405 ( & V_799 . V_821 ,
& V_867 ) ;
if ( V_26 )
goto V_868;
V_798 = F_406 ( L_312 ) ;
V_26 = F_97 ( V_798 ) ? F_98 ( V_798 ) : 0 ;
if ( V_26 )
goto V_869;
V_237 = F_407 ( L_313 ,
sizeof( struct V_587 ) + V_437 , 64 , 0 , NULL ) ;
if ( ! V_237 ) {
V_26 = - V_39 ;
goto V_870;
}
V_94 = F_407 ( L_314 ,
sizeof( struct V_89 ) , 0 , 0 , NULL ) ;
if ( ! V_94 ) {
V_26 = - V_39 ;
goto V_871;
}
return 0 ;
V_871:
F_408 ( V_237 ) ;
V_870:
F_409 ( V_798 ) ;
V_869:
F_410 ( & V_799 . V_821 ,
& V_867 ) ;
V_868:
F_411 ( & V_799 ) ;
V_866:
F_412 ( & V_730 ) ;
V_865:
F_50 ( 2 , L_315 , V_26 ) ;
F_358 () ;
V_864:
F_413 ( L_316 ) ;
return V_26 ;
}
static void T_11 F_414 ( void )
{
F_409 ( V_798 ) ;
F_410 ( & V_799 . V_821 ,
& V_867 ) ;
F_411 ( & V_799 ) ;
F_412 ( & V_730 ) ;
F_408 ( V_94 ) ;
F_408 ( V_237 ) ;
F_358 () ;
F_401 ( L_317 ) ;
}
