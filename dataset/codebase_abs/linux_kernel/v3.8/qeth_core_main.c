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
if ( V_85 -> V_2 -> V_49 . V_50 != V_51 )
return;
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
if ( V_87 && ( F_34 ( & ( V_85 -> V_65 [ V_86 ] -> V_44 ) ) ==
V_92 ) ) {
V_85 -> V_65 [ V_86 ] -> V_95 = V_85 -> V_71 [ V_86 ] . V_95 ;
F_39 ( V_85 , V_86 ) ;
F_11 ( V_85 -> V_2 , 2 , L_42 ) ;
}
}
static inline void F_40 ( struct V_1 * V_2 ,
unsigned long V_96 ) {
struct V_97 * V_95 ;
struct V_89 * V_66 ;
enum V_74 V_98 ;
V_95 = (struct V_97 * ) F_41 ( V_96 ) ;
F_11 ( V_2 , 5 , L_43 ) ;
F_35 ( V_2 , 5 , L_41 , V_96 ) ;
V_66 = (struct V_89 * ) V_95 -> V_99 ;
F_35 ( V_2 , 5 , L_41 , V_95 -> V_99 ) ;
if ( F_42 ( & V_66 -> V_44 , V_100 ,
V_101 ) == V_100 ) {
V_98 = V_79 ;
} else {
F_37 ( F_34 ( & V_66 -> V_44 ) !=
V_102 ) ;
F_43 ( & V_66 -> V_44 , V_101 ) ;
V_98 = V_78 ;
}
if ( V_95 -> V_103 != 0 ) {
F_35 ( V_2 , 2 , L_44 , V_95 -> V_103 ) ;
V_98 = F_32 ( V_95 -> V_103 , 1 ) ;
}
F_44 ( V_66 -> V_85 , V_66 , V_98 ) ;
V_66 -> V_95 = NULL ;
F_45 ( V_66 -> V_85 , V_66 ,
V_92 ) ;
F_46 ( V_95 ) ;
}
static inline int F_47 ( struct V_1 * V_2 , unsigned int V_104 )
{
return V_2 -> V_49 . V_50 == V_51 &&
V_2 -> V_35 . V_53 != NULL &&
V_104 != 0 &&
V_104 == V_2 -> V_35 . V_59 - 1 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 5 , L_45 ) ;
if ( V_2 -> V_107 . V_44 != V_108 )
return - V_109 ;
V_106 = F_49 ( & V_2 -> V_107 ) ;
if ( ! V_106 ) {
F_50 ( & V_2 -> V_72 -> V_73 , L_46
L_47 ) ;
F_51 ( 2 , L_48
L_49 , F_52 ( & V_2 -> V_72 -> V_73 ) ) ;
return - V_39 ;
}
F_53 ( & V_2 -> V_107 , V_106 -> V_110 , V_111 ) ;
F_11 ( V_2 , 6 , L_50 ) ;
V_26 = F_54 ( V_2 -> V_107 . V_112 , & V_2 -> V_107 . V_113 ,
( V_114 ) V_106 , 0 , 0 ) ;
if ( V_26 ) {
F_51 ( 2 , L_51
L_52 , F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_43 ( & V_2 -> V_107 . V_115 , 0 ) ;
V_2 -> V_116 = 1 ;
F_55 ( V_2 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
return V_26 ;
}
static struct V_117 * F_56 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
V_118 = F_15 ( sizeof( struct V_117 ) , V_119 ) ;
if ( V_118 ) {
F_43 ( & V_118 -> V_120 , 1 ) ;
F_43 ( & V_118 -> V_121 , 0 ) ;
V_118 -> V_2 = V_2 ;
}
return V_118 ;
}
static void F_57 ( struct V_117 * V_118 )
{
F_58 ( F_34 ( & V_118 -> V_120 ) <= 0 ) ;
F_59 ( & V_118 -> V_120 ) ;
}
static void F_60 ( struct V_117 * V_118 )
{
F_58 ( F_34 ( & V_118 -> V_120 ) <= 0 ) ;
if ( F_61 ( & V_118 -> V_120 ) )
F_20 ( V_118 ) ;
}
static void F_62 ( struct V_122 * V_123 , int V_26 ,
struct V_1 * V_2 )
{
char * V_124 ;
int V_125 = V_123 -> V_126 . V_127 ;
V_124 = F_63 ( V_125 ) ;
if ( V_26 )
F_51 ( 2 , L_53
L_54 ,
V_124 , V_125 , F_52 ( & V_2 -> V_72 -> V_73 ) ,
F_64 ( V_2 ) , V_26 ,
F_65 ( V_26 ) ) ;
else
F_51 ( 5 , L_55 ,
V_124 , V_125 , F_52 ( & V_2 -> V_72 -> V_73 ) ,
F_64 ( V_2 ) ) ;
}
static struct V_122 * F_66 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_122 * V_123 = NULL ;
F_11 ( V_2 , 5 , L_56 ) ;
if ( F_67 ( V_106 -> V_110 ) ) {
V_123 = (struct V_122 * ) F_68 ( V_106 -> V_110 ) ;
if ( F_69 ( V_123 ) ) {
if ( V_123 -> V_126 . V_127 != V_128 &&
V_123 -> V_126 . V_127 != V_129 &&
V_123 -> V_126 . V_127 != V_130 &&
V_123 -> V_126 . V_127 != V_131 )
F_62 ( V_123 ,
V_123 -> V_126 . V_132 , V_2 ) ;
return V_123 ;
} else {
switch ( V_123 -> V_126 . V_127 ) {
case V_133 :
F_50 ( & V_2 -> V_72 -> V_73 ,
L_57
L_58 ,
F_64 ( V_2 ) ,
V_2 -> V_3 . V_134 ) ;
V_2 -> V_135 = 0 ;
if ( V_2 -> V_73 && F_70 ( V_2 -> V_73 ) )
F_71 ( V_2 -> V_73 ) ;
return NULL ;
case V_136 :
F_72 ( & V_2 -> V_72 -> V_73 ,
L_59
L_60 ,
F_64 ( V_2 ) ,
V_2 -> V_3 . V_134 ) ;
F_73 ( V_2 -> V_73 ) ;
V_2 -> V_135 = 1 ;
if ( V_2 -> V_3 . V_137 )
V_2 -> V_3 . V_137 = 2 ;
F_55 ( V_2 ) ;
return NULL ;
case V_130 :
return V_123 ;
case V_138 :
F_11 ( V_2 , 3 , L_61 ) ;
break;
case V_139 :
F_11 ( V_2 , 3 , L_62 ) ;
break;
default:
F_51 ( 2 , L_63
L_64 ) ;
break;
}
}
}
return V_123 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_117 * V_118 , * V_140 ;
unsigned long V_21 ;
F_11 ( V_2 , 4 , L_65 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_12 (reply, r, &card->cmd_waiter_list, list) {
F_57 ( V_118 ) ;
V_118 -> V_26 = - V_109 ;
F_59 ( & V_118 -> V_121 ) ;
F_75 ( & V_118 -> V_31 ) ;
F_6 ( & V_118 -> V_25 ) ;
F_60 ( V_118 ) ;
}
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_43 ( & V_2 -> V_142 . V_115 , 0 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
unsigned char * V_66 )
{
if ( ! V_66 )
return 0 ;
F_29 ( V_143 , 2 , V_66 , V_144 ) ;
if ( ( V_66 [ 2 ] & 0xc0 ) == 0xc0 ) {
F_51 ( 2 , L_66
L_67 ,
V_66 [ 4 ] ,
( ( V_66 [ 4 ] == 0x22 ) ?
L_68 : L_69 ) ) ;
F_11 ( V_2 , 2 , L_70 ) ;
F_11 ( V_2 , 2 , L_71 ) ;
F_35 ( V_2 , 2 , L_72 , - V_109 ) ;
if ( V_66 [ 4 ] == 0xf6 ) {
F_30 ( & V_2 -> V_72 -> V_73 ,
L_73
L_74 ) ;
return - V_47 ;
}
return - V_109 ;
}
return 0 ;
}
static void F_53 ( struct V_145 * V_146 , unsigned char * V_106 ,
T_1 V_147 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 4 , L_75 ) ;
if ( V_146 == & V_2 -> V_107 )
memcpy ( & V_146 -> V_113 , V_148 , sizeof( struct V_149 ) ) ;
else
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_147 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 ) ;
}
static struct V_105 * F_79 ( struct V_145 * V_146 )
{
T_2 V_153 ;
F_11 ( F_77 ( V_146 -> V_112 ) , 6 , L_76 ) ;
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
void F_80 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
unsigned long V_21 ;
F_11 ( F_77 ( V_146 -> V_112 ) , 6 , L_77 ) ;
F_4 ( & V_146 -> V_158 , V_21 ) ;
memset ( V_106 -> V_110 , 0 , V_111 ) ;
V_106 -> V_44 = V_155 ;
V_106 -> V_159 = V_160 ;
V_106 -> V_26 = 0 ;
F_5 ( & V_146 -> V_158 , V_21 ) ;
F_6 ( & V_146 -> V_25 ) ;
}
static struct V_105 * F_49 ( struct V_145 * V_146 )
{
struct V_105 * V_66 = NULL ;
unsigned long V_21 ;
F_4 ( & V_146 -> V_158 , V_21 ) ;
V_66 = F_79 ( V_146 ) ;
F_5 ( & V_146 -> V_158 , V_21 ) ;
return V_66 ;
}
struct V_105 * F_81 ( struct V_145 * V_146 )
{
struct V_105 * V_66 ;
F_82 ( V_146 -> V_25 ,
( ( V_66 = F_49 ( V_146 ) ) != NULL ) ) ;
return V_66 ;
}
void F_83 ( struct V_145 * V_146 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ )
F_80 ( V_146 , & V_146 -> V_106 [ V_161 ] ) ;
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
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 4 , L_78 ) ;
V_26 = F_76 ( V_2 , V_106 -> V_110 ) ;
switch ( V_26 ) {
case 0 :
break;
case - V_109 :
F_74 ( V_2 ) ;
F_55 ( V_2 ) ;
default:
goto V_60;
}
V_123 = F_66 ( V_2 , V_106 ) ;
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
F_57 ( V_118 ) ;
F_75 ( & V_118 -> V_31 ) ;
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
F_84 ( & V_118 -> V_31 ,
& V_2 -> V_171 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
} else {
F_59 ( & V_118 -> V_121 ) ;
F_6 ( & V_118 -> V_25 ) ;
}
F_60 ( V_118 ) ;
goto V_60;
}
}
F_5 ( & V_2 -> V_141 , V_21 ) ;
V_60:
memcpy ( & V_2 -> V_166 . V_172 ,
F_85 ( V_106 -> V_110 ) ,
V_173 ) ;
F_80 ( V_146 , V_106 ) ;
}
static int F_86 ( struct V_145 * V_146 )
{
int V_161 ;
F_24 ( V_52 , 2 , L_79 ) ;
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
F_43 ( & V_146 -> V_115 , 0 ) ;
F_87 ( & V_146 -> V_158 ) ;
F_88 ( & V_146 -> V_25 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
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
void F_90 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_24 &= ~ V_175 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
void F_91 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_27 &= ~ V_175 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
static int F_92 ( struct V_1 * V_2 , unsigned long V_175 )
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
int F_93 ( struct V_1 * V_2 , unsigned long V_175 )
{
int V_26 = 0 ;
F_82 ( V_2 -> V_25 ,
( V_26 = F_92 ( V_2 , V_175 ) ) >= 0 ) ;
return V_26 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 2 , L_80 ) ;
if ( F_89 ( V_2 , V_176 ) == 0 )
F_94 ( & V_2 -> V_177 ) ;
}
static int F_95 ( struct V_178 * V_179 , struct V_180 * V_180 )
{
int V_181 , V_182 ;
char * V_183 ;
struct V_1 * V_2 ;
V_183 = ( char * ) V_180 -> V_184 ;
V_182 = V_180 -> V_185 . V_123 . V_182 ;
V_181 = V_180 -> V_185 . V_123 . V_181 ;
V_2 = F_77 ( V_179 ) ;
if ( V_182 & ( V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 ) ) {
F_11 ( V_2 , 2 , L_81 ) ;
F_50 ( & V_179 -> V_73 , L_46
L_47 ) ;
F_51 ( 2 , L_82 ,
F_52 ( & V_179 -> V_73 ) , V_181 , V_182 ) ;
F_96 ( V_192 , L_83 , V_193 ,
16 , 1 , V_180 , 64 , 1 ) ;
return 1 ;
}
if ( V_181 & V_194 ) {
if ( V_183 [ V_195 ] &
V_196 ) {
F_11 ( V_2 , 2 , L_84 ) ;
return 1 ;
}
if ( V_183 [ V_197 ] &
V_198 ) {
F_11 ( V_2 , 2 , L_85 ) ;
return 1 ;
}
if ( ( V_183 [ 2 ] == 0xaf ) && ( V_183 [ 3 ] == 0xfe ) ) {
F_11 ( V_2 , 2 , L_86 ) ;
return 1 ;
}
if ( ( ! V_183 [ 0 ] ) && ( ! V_183 [ 1 ] ) && ( ! V_183 [ 2 ] ) && ( ! V_183 [ 3 ] ) ) {
F_11 ( V_2 , 2 , L_87 ) ;
return 0 ;
}
F_11 ( V_2 , 2 , L_88 ) ;
return 1 ;
}
return 0 ;
}
static long F_97 ( struct V_178 * V_179 ,
unsigned long V_199 , struct V_180 * V_180 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_179 ) ;
if ( ! F_98 ( V_180 ) )
return 0 ;
switch ( F_99 ( V_180 ) ) {
case - V_109 :
F_51 ( 2 , L_89 ,
F_52 ( & V_179 -> V_73 ) ) ;
F_11 ( V_2 , 2 , L_90 ) ;
F_35 ( V_2 , 2 , L_72 , - V_109 ) ;
break;
case - V_200 :
F_50 ( & V_179 -> V_73 , L_91
L_92 ) ;
F_11 ( V_2 , 2 , L_90 ) ;
F_35 ( V_2 , 2 , L_72 , - V_200 ) ;
if ( V_199 == V_201 ) {
if ( V_2 && ( V_2 -> V_110 . V_112 == V_179 ) ) {
V_2 -> V_110 . V_44 = V_202 ;
F_6 ( & V_2 -> V_25 ) ;
}
}
break;
default:
F_51 ( 2 , L_93 ,
F_52 ( & V_179 -> V_73 ) , F_99 ( V_180 ) ) ;
F_11 ( V_2 , 2 , L_90 ) ;
F_11 ( V_2 , 2 , L_94 ) ;
}
return F_99 ( V_180 ) ;
}
static void F_100 ( struct V_178 * V_179 , unsigned long V_199 ,
struct V_180 * V_180 )
{
int V_26 ;
int V_182 , V_181 ;
struct V_105 * V_66 ;
struct V_145 * V_146 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
T_2 V_153 ;
if ( F_97 ( V_179 , V_199 , V_180 ) )
return;
V_182 = V_180 -> V_185 . V_123 . V_182 ;
V_181 = V_180 -> V_185 . V_123 . V_181 ;
V_2 = F_77 ( V_179 ) ;
if ( ! V_2 )
return;
F_11 ( V_2 , 5 , L_95 ) ;
if ( V_2 -> V_107 . V_112 == V_179 ) {
V_146 = & V_2 -> V_107 ;
F_11 ( V_2 , 5 , L_96 ) ;
} else if ( V_2 -> V_142 . V_112 == V_179 ) {
V_146 = & V_2 -> V_142 ;
F_11 ( V_2 , 5 , L_97 ) ;
} else {
V_146 = & V_2 -> V_110 ;
F_11 ( V_2 , 5 , L_98 ) ;
}
F_43 ( & V_146 -> V_115 , 0 ) ;
if ( V_180 -> V_185 . V_123 . V_203 & ( V_204 ) )
V_146 -> V_44 = V_205 ;
if ( V_180 -> V_185 . V_123 . V_203 & ( V_206 ) )
V_146 -> V_44 = V_207 ;
if ( ( V_146 == & V_2 -> V_110 ) && ( V_199 != 0 ) &&
( V_199 != V_201 ) )
goto V_60;
if ( V_199 == V_208 ) {
F_11 ( V_2 , 6 , L_99 ) ;
V_199 = 0 ;
}
if ( V_199 == V_209 ) {
F_11 ( V_2 , 6 , L_100 ) ;
V_199 = 0 ;
}
if ( ( V_181 & V_210 ) ||
( V_181 & V_194 ) ||
( V_182 ) ) {
if ( V_180 -> V_211 . V_212 . V_213 . V_214 ) {
F_50 ( & V_146 -> V_112 -> V_73 ,
L_101
L_102 ) ;
F_51 ( 2 , L_103
L_104 ,
F_52 ( & V_146 -> V_112 -> V_73 ) , V_182 , V_181 ) ;
F_96 ( V_192 , L_83 ,
V_193 , 16 , 1 , V_180 , 32 , 1 ) ;
F_96 ( V_192 , L_105 ,
V_193 , 16 , 1 , V_180 -> V_184 , 32 , 1 ) ;
}
if ( V_199 == V_201 ) {
V_146 -> V_44 = V_202 ;
goto V_60;
}
V_26 = F_95 ( V_179 , V_180 ) ;
if ( V_26 ) {
F_74 ( V_2 ) ;
F_55 ( V_2 ) ;
goto V_60;
}
}
if ( V_199 == V_201 ) {
V_146 -> V_44 = V_215 ;
goto V_60;
}
if ( V_199 ) {
V_66 = (struct V_105 * ) F_101 ( ( V_114 ) V_199 ) ;
V_66 -> V_44 = V_216 ;
}
if ( V_146 == & V_2 -> V_110 )
return;
if ( V_146 == & V_2 -> V_107 &&
V_146 -> V_44 == V_108 )
F_48 ( V_2 ) ;
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
static void F_44 ( struct V_84 * V_85 ,
struct V_89 * V_217 ,
enum V_74 V_98 )
{
struct V_218 * V_219 ;
if ( F_102 ( & V_217 -> V_220 ) )
goto V_60;
V_219 = F_103 ( & V_217 -> V_220 ) ;
while ( V_219 ) {
F_35 ( V_85 -> V_2 , 5 , L_106 , V_98 ) ;
F_35 ( V_85 -> V_2 , 5 , L_41 , ( long ) V_219 ) ;
if ( V_219 -> V_221 == V_222 ) {
if ( V_219 -> V_223 ) {
struct V_224 * V_225 = F_104 ( V_219 -> V_223 ) ;
V_225 -> V_226 ( V_219 , V_98 ) ;
}
}
if ( F_105 ( & V_217 -> V_220 , V_219 ) )
V_219 = NULL ;
else
V_219 = F_106 ( & V_217 -> V_220 , V_219 ) ;
}
V_60:
return;
}
static void F_36 ( struct V_89 * V_217 )
{
struct V_218 * V_219 ;
struct V_224 * V_225 ;
int V_227 = 0 ;
if ( F_34 ( & V_217 -> V_44 ) == V_102 )
V_227 = 1 ;
F_37 ( F_34 ( & V_217 -> V_44 ) == V_101 ) ;
V_219 = F_107 ( & V_217 -> V_220 ) ;
while ( V_219 ) {
F_11 ( V_217 -> V_85 -> V_2 , 5 , L_107 ) ;
F_35 ( V_217 -> V_85 -> V_2 , 5 , L_41 , ( long ) V_219 ) ;
if ( V_227 && V_219 -> V_221 == V_222 ) {
if ( V_219 -> V_223 ) {
V_225 = F_104 ( V_219 -> V_223 ) ;
V_225 -> V_226 ( V_219 , V_83 ) ;
}
}
F_108 ( & V_219 -> V_228 ) ;
F_109 ( V_219 ) ;
V_219 = F_107 ( & V_217 -> V_220 ) ;
}
}
static void F_45 ( struct V_84 * V_104 ,
struct V_89 * V_217 ,
enum V_229 V_230 )
{
int V_33 ;
if ( V_217 -> V_66 -> V_231 [ 0 ] . V_232 & V_233 )
F_108 ( & V_104 -> V_234 ) ;
if ( V_230 == V_235 ) {
F_36 ( V_217 ) ;
}
for ( V_33 = 0 ; V_33 < F_17 ( V_104 -> V_2 ) ; ++ V_33 ) {
if ( V_217 -> V_66 -> V_231 [ V_33 ] . V_236 && V_217 -> V_237 [ V_33 ] )
F_38 ( V_238 ,
V_217 -> V_66 -> V_231 [ V_33 ] . V_236 ) ;
V_217 -> V_237 [ V_33 ] = 0 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_239 = 0 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_236 = NULL ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_240 = 0 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_232 = 0 ;
}
V_217 -> V_66 -> V_231 [ 15 ] . V_240 = 0 ;
V_217 -> V_66 -> V_231 [ 15 ] . V_232 = 0 ;
V_217 -> V_241 = 0 ;
F_43 ( & V_217 -> V_44 , V_230 ) ;
}
static void F_110 ( struct V_84 * V_85 , int free )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
if ( ! V_85 -> V_65 [ V_34 ] )
continue;
F_33 ( V_85 , V_34 , 1 ) ;
F_45 ( V_85 , V_85 -> V_65 [ V_34 ] , V_235 ) ;
if ( free ) {
F_38 ( V_94 , V_85 -> V_65 [ V_34 ] ) ;
V_85 -> V_65 [ V_34 ] = NULL ;
}
}
}
void F_111 ( struct V_1 * V_2 )
{
int V_33 ;
F_11 ( V_2 , 2 , L_108 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
if ( V_2 -> V_35 . V_70 [ V_33 ] ) {
F_110 ( V_2 -> V_35 . V_70 [ V_33 ] , 0 ) ;
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
static void F_112 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
if ( F_113 ( & V_2 -> V_35 . V_44 , V_242 ) ==
V_242 )
return;
F_31 ( V_2 ) ;
F_114 ( & V_2 -> V_243 ) ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 )
F_109 ( V_2 -> V_35 . V_244 -> V_65 [ V_34 ] . V_245 ) ;
F_20 ( V_2 -> V_35 . V_244 ) ;
V_2 -> V_35 . V_244 = NULL ;
F_16 ( V_2 ) ;
if ( V_2 -> V_35 . V_70 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
F_110 ( V_2 -> V_35 . V_70 [ V_33 ] , 1 ) ;
F_20 ( V_2 -> V_35 . V_70 [ V_33 ] ) ;
}
F_20 ( V_2 -> V_35 . V_70 ) ;
V_2 -> V_35 . V_70 = NULL ;
}
}
static void F_115 ( struct V_145 * V_146 )
{
int V_161 ;
F_24 ( V_52 , 2 , L_109 ) ;
for ( V_161 = 0 ; V_161 < V_157 ; V_161 ++ )
F_20 ( V_146 -> V_106 [ V_161 ] . V_110 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) != V_242 ) &&
( V_2 -> V_35 . V_68 == 4 ) )
F_112 ( V_2 ) ;
V_2 -> V_35 . V_68 = 1 ;
if ( V_2 -> V_35 . V_246 != 0 )
F_72 ( & V_2 -> V_72 -> V_73 , L_110 ) ;
V_2 -> V_35 . V_246 = 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) != V_242 ) &&
( V_2 -> V_35 . V_68 == 1 ) ) {
F_112 ( V_2 ) ;
V_2 -> V_35 . V_246 = 2 ;
}
V_2 -> V_35 . V_68 = 4 ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_178 * V_112 ;
struct V_247 {
T_3 V_21 ;
T_3 V_248 ;
T_3 V_249 ;
T_3 V_134 ;
T_3 V_250 ;
T_3 V_251 ;
T_3 V_252 ;
T_3 V_253 ;
} * V_254 ;
F_24 ( V_52 , 2 , L_111 ) ;
V_112 = V_2 -> V_110 . V_112 ;
V_254 = F_119 ( V_112 , 0 ) ;
if ( ! V_254 )
goto V_60;
V_2 -> V_3 . V_255 = 0x4100 + V_254 -> V_249 ;
if ( V_2 -> V_3 . type == V_6 )
goto V_60;
if ( ( V_254 -> V_253 & 0x02 ) == 0x02 )
F_116 ( V_2 ) ;
else
F_117 ( V_2 ) ;
V_60:
F_20 ( V_254 ) ;
F_27 ( V_52 , 2 , L_112 , V_2 -> V_35 . V_68 ) ;
F_27 ( V_52 , 2 , L_113 , V_2 -> V_3 . V_255 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 4 , L_114 ) ;
F_43 ( & V_2 -> V_35 . V_44 , V_242 ) ;
V_2 -> V_35 . V_256 = V_257 ;
if ( V_2 -> V_3 . type == V_6 )
V_2 -> V_35 . V_36 . V_37 = V_258 ;
else
V_2 -> V_35 . V_36 . V_37 = V_259 ;
V_2 -> V_35 . V_48 . V_37 = V_2 -> V_35 . V_36 . V_37 ;
F_121 ( & V_2 -> V_35 . V_48 . V_42 ) ;
F_121 ( & V_2 -> V_35 . V_36 . V_42 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
V_2 -> V_49 . V_260 . type = V_261 ;
V_2 -> V_49 . V_262 . type = V_261 ;
V_2 -> V_49 . V_263 = 0 ;
V_2 -> V_49 . V_264 = V_265 ;
V_2 -> V_49 . V_266 = 0 ;
V_2 -> V_49 . V_267 = V_268 ;
V_2 -> V_49 . V_269 = V_270 ;
V_2 -> V_49 . V_50 = V_271 ;
}
static int F_123 ( struct V_1 * V_2 , unsigned long V_175 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
F_35 ( V_2 , 4 , L_115 ,
( T_3 ) V_2 -> V_24 ,
( T_3 ) V_2 -> V_23 ,
( T_3 ) V_2 -> V_27 ) ;
V_26 = ( V_2 -> V_24 & V_175 ) ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
static void F_124 ( struct V_272 * V_273 )
{
struct V_274 * V_275 ;
struct V_1 * V_2 = F_125 ( V_273 , struct V_1 ,
V_177 ) ;
F_11 ( V_2 , 2 , L_116 ) ;
if ( V_2 -> V_107 . V_44 != V_108 &&
V_2 -> V_142 . V_44 != V_108 )
return;
if ( F_123 ( V_2 , V_176 ) ) {
V_275 = F_126 ( V_2 -> V_276 -> V_277 , ( void * ) V_2 ,
L_117 ) ;
if ( F_98 ( V_275 ) ) {
F_90 ( V_2 , V_176 ) ;
F_91 ( V_2 ,
V_176 ) ;
}
}
}
static int F_127 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_118 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_107 . V_44 = V_202 ;
V_2 -> V_142 . V_44 = V_202 ;
V_2 -> V_110 . V_44 = V_202 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_135 = 0 ;
V_2 -> V_116 = 0 ;
V_2 -> V_73 = NULL ;
F_87 ( & V_2 -> V_278 ) ;
F_87 ( & V_2 -> V_279 ) ;
F_87 ( & V_2 -> V_141 ) ;
F_87 ( & V_2 -> V_280 ) ;
F_87 ( & V_2 -> V_22 ) ;
F_128 ( & V_2 -> V_281 ) ;
F_128 ( & V_2 -> V_282 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_27 = 0 ;
F_129 ( & V_2 -> V_177 , F_124 ) ;
F_121 ( & V_2 -> V_283 ) ;
F_121 ( V_2 -> V_284 ) ;
F_121 ( & V_2 -> V_171 ) ;
F_88 ( & V_2 -> V_25 ) ;
F_122 ( V_2 ) ;
F_121 ( & V_2 -> V_285 . V_286 ) ;
V_2 -> V_285 . V_287 = 0 ;
V_2 -> V_285 . V_288 = 0 ;
V_2 -> V_285 . V_289 = 0 ;
F_120 ( V_2 ) ;
F_130 ( & V_2 -> V_243 , V_290 ) ;
return 0 ;
}
static void F_131 ( struct V_291 * V_292 , struct V_293 * V_294 )
{
struct V_1 * V_2 = F_125 ( V_294 , struct V_1 ,
V_295 ) ;
if ( V_2 -> V_3 . V_296 [ 0 ] )
F_132 ( V_292 , L_119 ,
F_133 ( V_2 ) , V_2 -> V_3 . V_296 ) ;
}
static struct V_1 * F_134 ( void )
{
struct V_1 * V_2 ;
F_24 ( V_52 , 2 , L_120 ) ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_174 | V_38 ) ;
if ( ! V_2 )
goto V_60;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_284 = F_15 ( sizeof( struct V_297 ) , V_38 ) ;
if ( ! V_2 -> V_284 ) {
F_24 ( V_52 , 0 , L_121 ) ;
goto V_298;
}
if ( F_86 ( & V_2 -> V_107 ) )
goto V_299;
if ( F_86 ( & V_2 -> V_142 ) )
goto V_300;
V_2 -> V_49 . V_301 = - 1 ;
V_2 -> V_295 . V_302 = F_131 ;
F_135 ( & V_2 -> V_295 ) ;
return V_2 ;
V_300:
F_115 ( & V_2 -> V_107 ) ;
V_299:
F_20 ( V_2 -> V_284 ) ;
V_298:
F_20 ( V_2 ) ;
V_60:
return NULL ;
}
static int F_136 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
F_24 ( V_52 , 2 , L_122 ) ;
V_2 -> V_35 . V_303 = V_304 ;
V_2 -> V_35 . V_246 = V_305 ;
while ( V_306 [ V_33 ] [ V_307 ] ) {
if ( ( F_137 ( V_2 ) -> V_308 . V_309 ==
V_306 [ V_33 ] [ V_310 ] ) &&
( F_137 ( V_2 ) -> V_308 . V_311 ==
V_306 [ V_33 ] [ V_307 ] ) ) {
V_2 -> V_3 . type = V_306 [ V_33 ] [ V_307 ] ;
V_2 -> V_35 . V_68 =
V_306 [ V_33 ] [ V_312 ] ;
V_2 -> V_35 . V_59 = 1 ;
V_2 -> V_3 . V_313 =
V_306 [ V_33 ] [ V_314 ] ;
F_118 ( V_2 ) ;
return 0 ;
}
V_33 ++ ;
}
V_2 -> V_3 . type = V_315 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_123
L_124 ) ;
return - V_316 ;
}
static int F_138 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_125 ) ;
F_4 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_140 ( V_146 -> V_112 , V_208 ) ;
F_5 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_141 ( V_2 -> V_25 ,
V_146 -> V_44 == V_205 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_205 )
return - V_319 ;
V_146 -> V_44 = V_202 ;
return 0 ;
}
static int F_142 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_126 ) ;
F_4 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_143 ( V_146 -> V_112 , V_209 ) ;
F_5 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_141 ( V_2 -> V_25 ,
V_146 -> V_44 == V_207 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_207 )
return - V_319 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_11 ( V_2 , 3 , L_127 ) ;
V_320 = F_142 ( & V_2 -> V_107 ) ;
V_321 = F_142 ( & V_2 -> V_142 ) ;
V_322 = F_142 ( & V_2 -> V_110 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_11 ( V_2 , 3 , L_128 ) ;
V_320 = F_138 ( & V_2 -> V_107 ) ;
V_321 = F_138 ( & V_2 -> V_142 ) ;
V_322 = F_138 ( & V_2 -> V_110 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_146 ( struct V_1 * V_2 , int V_323 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_129 ) ;
if ( V_323 )
V_26 = F_144 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_145 ( V_2 ) ;
}
int F_147 ( struct V_1 * V_2 , int V_324 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_130 ) ;
switch ( F_42 ( & V_2 -> V_35 . V_44 , V_325 ,
V_326 ) ) {
case V_325 :
if ( V_2 -> V_3 . type == V_6 )
V_26 = F_148 ( F_26 ( V_2 ) ,
V_327 ) ;
else
V_26 = F_148 ( F_26 ( V_2 ) ,
V_328 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_35 , V_26 ) ;
F_149 ( F_26 ( V_2 ) ) ;
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
break;
case V_326 :
return V_26 ;
default:
break;
}
V_26 = F_146 ( V_2 , V_324 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_131 , V_26 ) ;
V_2 -> V_44 = V_45 ;
return V_26 ;
}
static int F_150 ( struct V_1 * V_2 , void * * V_66 ,
int * V_239 )
{
struct V_330 * V_330 ;
char * V_331 ;
int V_332 ;
struct V_145 * V_146 = & V_2 -> V_110 ;
unsigned long V_21 ;
V_330 = F_151 ( V_146 -> V_112 , V_333 ) ;
if ( ! V_330 || V_330 -> V_123 == 0 )
return - V_334 ;
V_331 = F_15 ( V_330 -> V_151 , V_38 | V_174 ) ;
if ( ! V_331 )
return - V_39 ;
V_146 -> V_113 . V_335 = V_330 -> V_123 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_331 ) ;
V_146 -> V_113 . V_151 = V_330 -> V_151 ;
V_146 -> V_113 . V_21 = V_336 ;
V_146 -> V_44 = V_337 ;
F_4 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
V_332 = F_152 ( V_146 -> V_112 , & V_146 -> V_113 ,
V_201 , V_338 , 0 ,
V_339 ) ;
F_5 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
if ( ! V_332 )
F_82 ( V_2 -> V_25 ,
( V_146 -> V_44 == V_215 ||
V_146 -> V_44 == V_202 ) ) ;
if ( V_146 -> V_44 == V_202 )
V_332 = - V_109 ;
else
V_146 -> V_44 = V_202 ;
if ( V_332 ) {
F_20 ( V_331 ) ;
* V_66 = NULL ;
* V_239 = 0 ;
} else {
* V_239 = V_330 -> V_151 ;
* V_66 = V_331 ;
}
return V_332 ;
}
static void F_153 ( struct V_1 * V_2 , char * V_340 )
{
F_24 ( V_52 , 2 , L_132 ) ;
V_2 -> V_3 . V_134 = V_340 [ 30 ] ;
V_2 -> V_3 . V_341 = V_340 [ 31 ] ;
V_2 -> V_3 . V_342 = V_340 [ 63 ] ;
V_2 -> V_3 . V_4 = ( ( V_340 [ 0x10 ] == V_343 [ 'V' ] ) &&
( V_340 [ 0x11 ] == V_343 [ 'M' ] ) ) ;
}
static void F_154 ( struct V_1 * V_2 , char * V_340 )
{
F_24 ( V_52 , 2 , L_133 ) ;
if ( V_340 [ 74 ] == 0xF0 && V_340 [ 75 ] == 0xF0 &&
( V_340 [ 76 ] == 0xF5 || V_340 [ 76 ] == 0xF6 ) ) {
V_2 -> V_3 . V_344 . V_345 = 250 ;
V_2 -> V_3 . V_344 . V_346 = 5 ;
V_2 -> V_3 . V_344 . V_347 = 15 ;
} else {
V_2 -> V_3 . V_344 . V_345 = 0 ;
V_2 -> V_3 . V_344 . V_346 = 0 ;
V_2 -> V_3 . V_344 . V_347 = 0 ;
}
}
static void F_155 ( struct V_1 * V_2 )
{
V_2 -> V_348 . V_349 = 0x00010103UL ;
V_2 -> V_348 . V_350 = 0x00010108UL ;
V_2 -> V_348 . V_351 = 0x0001010aUL ;
V_2 -> V_348 . V_352 = 0x0001010bUL ;
V_2 -> V_348 . V_353 = 0x0001010dUL ;
}
static void F_156 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
V_2 -> V_3 . V_255 = V_354 ;
break;
case V_5 :
case V_9 :
V_2 -> V_3 . V_255 = V_355 ;
break;
default:
break;
}
}
static int F_157 ( struct V_145 * V_146 ,
void (* F_158)( struct V_145 * ,
struct V_105 * ) )
{
struct V_105 * V_106 ;
unsigned long V_21 ;
int V_26 ;
struct V_1 * V_2 ;
F_24 ( V_52 , 2 , L_134 ) ;
V_2 = F_77 ( V_146 -> V_112 ) ;
V_106 = F_49 ( V_146 ) ;
V_106 -> V_159 = F_158 ;
memcpy ( & V_146 -> V_113 , V_148 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_111 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 -> V_110 ) ;
F_82 ( V_2 -> V_25 ,
F_42 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_50 ) ;
F_4 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_54 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_51 ( 2 , L_135 , V_26 ) ;
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
F_43 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_141 ( V_2 -> V_25 ,
V_146 -> V_44 == V_108 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_108 ) {
V_26 = - V_319 ;
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
F_83 ( V_146 ) ;
} else
V_26 = 0 ;
return V_26 ;
}
static int F_159 ( struct V_145 * V_146 ,
void (* F_158)( struct V_145 * ,
struct V_105 * ) )
{
struct V_1 * V_2 ;
struct V_105 * V_106 ;
unsigned long V_21 ;
V_169 V_356 ;
T_2 V_30 ;
int V_26 ;
struct V_357 V_358 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_24 ( V_52 , 2 , L_137 ) ;
V_106 = F_49 ( V_146 ) ;
V_106 -> V_159 = F_158 ;
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_359 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 -> V_110 ) ;
if ( V_146 == & V_2 -> V_142 ) {
memcpy ( V_106 -> V_110 , V_360 , V_359 ) ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_361 , V_173 ) ;
V_2 -> V_166 . V_361 ++ ;
} else {
memcpy ( V_106 -> V_110 , V_362 , V_359 ) ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_361 , V_173 ) ;
}
V_30 = ( ( T_2 ) V_2 -> V_3 . V_363 ) | 0x80 ;
memcpy ( F_161 ( V_106 -> V_110 ) , & V_30 , 1 ) ;
memcpy ( F_162 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_349 , V_364 ) ;
memcpy ( F_163 ( V_106 -> V_110 ) ,
& V_2 -> V_3 . V_255 , sizeof( V_169 ) ) ;
F_164 ( F_26 ( V_2 ) , & V_358 ) ;
memcpy ( F_165 ( V_106 -> V_110 ) , & V_358 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_3 . V_342 << 8 ) + V_2 -> V_3 . V_341 ;
memcpy ( F_166 ( V_106 -> V_110 ) , & V_356 , 2 ) ;
F_82 ( V_2 -> V_25 ,
F_42 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_50 ) ;
F_4 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_54 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_139 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_51 ( 2 , L_138 ,
V_26 ) ;
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
F_43 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_141 ( V_2 -> V_25 ,
V_146 -> V_44 == V_366 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_366 ) {
F_50 ( & V_146 -> V_112 -> V_73 , L_139
L_140 ) ;
F_51 ( 2 , L_141 ,
F_52 ( & V_146 -> V_112 -> V_73 ) ) ;
F_27 ( V_52 , 2 , L_131 , - V_319 ) ;
F_83 ( V_146 ) ;
return - V_319 ;
}
return F_157 ( V_146 , F_158 ) ;
}
static int F_167 ( int V_367 )
{
if ( ( V_367 & 0xff ) == 8 )
return ( V_367 & 0xff ) + 0x400 ;
if ( ( ( V_367 >> 8 ) & 3 ) == 1 )
return ( V_367 & 0xff ) + 0x200 ;
return V_367 ;
}
static void F_168 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_356 ;
F_24 ( V_52 , 2 , L_142 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_366 ;
goto V_60;
}
V_2 = F_77 ( V_146 -> V_112 ) ;
if ( ! ( F_169 ( V_106 -> V_110 ) ) ) {
if ( F_170 ( V_106 -> V_110 ) == V_368 )
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_143
L_144 ) ;
else
F_51 ( 2 , L_145
L_146 ,
F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) ) ;
goto V_60;
}
memcpy ( & V_356 , F_163 ( V_106 -> V_110 ) , 2 ) ;
if ( ( V_356 & ~ 0x0100 ) != F_167 ( V_2 -> V_3 . V_255 ) ) {
F_51 ( 2 , L_147
L_148
L_149 , F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_255 , V_356 ) ;
goto V_60;
}
V_146 -> V_44 = V_108 ;
V_60:
F_80 ( V_146 , V_106 ) ;
}
static void F_171 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_356 ;
F_24 ( V_52 , 2 , L_150 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_366 ;
goto V_60;
}
V_2 = F_77 ( V_146 -> V_112 ) ;
if ( F_76 ( V_2 , V_106 -> V_110 ) )
goto V_60;
if ( ! ( F_169 ( V_106 -> V_110 ) ) ) {
switch ( F_170 ( V_106 -> V_110 ) ) {
case V_368 :
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_143
L_144 ) ;
break;
case V_369 :
case V_370 :
F_30 ( & V_2 -> V_107 . V_112 -> V_73 ,
L_151
L_152 ) ;
break;
default:
F_51 ( 2 , L_153
L_146 ,
F_52 ( & V_2 -> V_107 . V_112 -> V_73 ) ) ;
}
F_35 ( V_2 , 2 , L_154 ,
F_170 ( V_106 -> V_110 ) ) ;
goto V_60;
}
if ( ( ! F_172 ( V_106 -> V_110 ) ) ||
( V_2 -> V_3 . type == V_5 ) )
V_2 -> V_3 . V_371 = 1 ;
memcpy ( & V_356 , F_163 ( V_106 -> V_110 ) , 2 ) ;
if ( V_356 != F_167 ( V_2 -> V_3 . V_255 ) ) {
F_51 ( 2 , L_155
L_156 ,
F_52 ( & V_2 -> V_107 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_255 , V_356 ) ;
goto V_60;
}
memcpy ( & V_2 -> V_348 . V_372 ,
F_162 ( V_106 -> V_110 ) ,
V_364 ) ;
memcpy ( & V_2 -> V_3 . V_296 [ 0 ] ,
F_173 ( V_106 -> V_110 ) , V_373 ) ;
V_146 -> V_44 = V_108 ;
V_60:
F_80 ( V_146 , V_106 ) ;
}
void F_174 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 )
{
F_53 ( & V_2 -> V_142 , V_106 -> V_110 , V_147 ) ;
V_106 -> V_159 = F_80 ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_361 , V_173 ) ;
V_2 -> V_166 . V_361 ++ ;
memcpy ( F_85 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_374 , V_173 ) ;
V_2 -> V_166 . V_374 ++ ;
memcpy ( F_175 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_172 , V_173 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
}
int F_176 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 ,
int (* F_177)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_375 )
{
int V_26 ;
unsigned long V_21 ;
struct V_117 * V_118 = NULL ;
unsigned long V_376 , V_377 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 2 , L_157 ) ;
if ( V_2 -> V_116 ) {
F_80 ( V_106 -> V_146 , V_106 ) ;
return - V_109 ;
}
V_118 = F_56 ( V_2 ) ;
if ( ! V_118 ) {
return - V_39 ;
}
V_118 -> V_159 = F_177 ;
V_118 -> V_378 = V_375 ;
if ( V_2 -> V_44 == V_45 )
V_118 -> V_166 = V_167 ;
else
V_118 -> V_166 = V_2 -> V_166 . V_379 ++ ;
F_88 ( & V_118 -> V_25 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_84 ( & V_118 -> V_31 , & V_2 -> V_171 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
while ( F_42 ( & V_2 -> V_142 . V_115 , 0 , 1 ) ) ;
F_174 ( V_2 , V_147 , V_106 ) ;
if ( F_67 ( V_106 -> V_110 ) )
V_377 = V_380 ;
else
V_377 = V_317 ;
V_376 = V_381 + V_377 ;
F_11 ( V_2 , 6 , L_50 ) ;
F_4 ( F_139 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
V_26 = F_54 ( V_2 -> V_142 . V_112 , & V_2 -> V_142 . V_113 ,
( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_139 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
if ( V_26 ) {
F_51 ( 2 , L_158
L_159 ,
F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) , V_26 ) ;
F_35 ( V_2 , 2 , L_160 , V_26 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_75 ( & V_118 -> V_31 ) ;
F_60 ( V_118 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_80 ( V_106 -> V_146 , V_106 ) ;
F_43 ( & V_2 -> V_142 . V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
if ( ( V_123 -> V_126 . V_127 == V_383 ) &&
( V_123 -> V_126 . V_384 == V_385 ) ) {
if ( ! F_178 ( V_118 -> V_25 ,
F_34 ( & V_118 -> V_121 ) , V_377 ) )
goto V_386;
} else {
while ( ! F_34 ( & V_118 -> V_121 ) ) {
if ( F_179 ( V_381 , V_376 ) )
goto V_386;
F_180 () ;
}
}
if ( V_118 -> V_26 == - V_109 )
goto error;
V_26 = V_118 -> V_26 ;
F_60 ( V_118 ) ;
return V_26 ;
V_386:
V_118 -> V_26 = - V_319 ;
F_4 ( & V_118 -> V_2 -> V_141 , V_21 ) ;
F_75 ( & V_118 -> V_31 ) ;
F_5 ( & V_118 -> V_2 -> V_141 , V_21 ) ;
F_59 ( & V_118 -> V_121 ) ;
error:
F_43 ( & V_2 -> V_142 . V_115 , 0 ) ;
F_80 ( V_106 -> V_146 , V_106 ) ;
V_2 -> V_142 . V_162 = ( V_2 -> V_142 . V_162 + 1 ) % V_157 ;
V_26 = V_118 -> V_26 ;
F_60 ( V_118 ) ;
return V_26 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_161 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_387 ,
F_182 ( V_106 -> V_110 ) ,
V_364 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_162 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_388 , V_389 ) ;
memcpy ( F_184 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_372 , V_364 ) ;
memcpy ( F_185 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_350 , V_364 ) ;
V_26 = F_176 ( V_2 , V_389 , V_106 ,
F_181 , NULL ) ;
return V_26 ;
}
static int F_186 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_163 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_390 ,
F_187 ( V_106 -> V_110 ) ,
V_364 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_164 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_391 , V_392 ) ;
memcpy ( F_189 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_372 , V_364 ) ;
memcpy ( F_190 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_351 , V_364 ) ;
memcpy ( F_191 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_387 , V_364 ) ;
V_26 = F_176 ( V_2 , V_392 , V_106 ,
F_186 , NULL ) ;
return V_26 ;
}
static inline int F_192 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_315 :
return 1500 ;
case V_6 :
return V_2 -> V_3 . V_393 ;
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
static inline int F_193 ( int V_394 )
{
switch ( V_394 ) {
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
static inline int F_194 ( struct V_1 * V_2 , int V_395 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
case V_6 :
return ( ( V_395 >= 576 ) &&
( V_395 <= V_2 -> V_3 . V_393 ) ) ;
case V_9 :
case V_315 :
default:
return 1 ;
}
}
static int F_195 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
V_169 V_395 , V_394 ;
V_169 V_147 ;
T_2 V_10 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_165 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_396 ,
F_196 ( V_106 -> V_110 ) ,
V_364 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
memcpy ( & V_394 , F_197 ( V_106 -> V_110 ) , 2 ) ;
V_395 = F_193 ( V_394 ) ;
if ( ! V_395 ) {
V_106 -> V_26 = - V_397 ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
if ( V_2 -> V_3 . V_398 && ( V_2 -> V_3 . V_398 != V_395 ) ) {
if ( V_2 -> V_73 &&
( ( V_2 -> V_73 -> V_395 == V_2 -> V_3 . V_398 ) ||
( V_2 -> V_73 -> V_395 > V_395 ) ) )
V_2 -> V_73 -> V_395 = V_395 ;
F_112 ( V_2 ) ;
}
V_2 -> V_3 . V_398 = V_395 ;
V_2 -> V_3 . V_393 = V_395 ;
V_2 -> V_35 . V_256 = V_395 + 2 * V_399 ;
} else {
V_2 -> V_3 . V_398 = F_192 ( V_2 ) ;
V_2 -> V_3 . V_393 = * ( V_169 * ) F_197 (
V_106 -> V_110 ) ;
V_2 -> V_35 . V_256 = V_257 ;
}
memcpy ( & V_147 , F_198 ( V_106 -> V_110 ) , 2 ) ;
if ( V_147 >= V_400 ) {
memcpy ( & V_10 ,
F_199 ( V_106 -> V_110 ) , 1 ) ;
V_2 -> V_3 . V_10 = V_10 ;
} else
V_2 -> V_3 . V_10 = 0 ;
F_27 ( V_52 , 2 , L_166 , V_2 -> V_3 . V_10 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_26 ;
char V_401 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_167 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_402 , V_403 ) ;
* ( F_201 ( V_106 -> V_110 ) ) =
( T_2 ) V_2 -> V_3 . V_363 ;
if ( V_2 -> V_49 . V_301 )
if ( V_2 -> V_3 . type == V_9 )
V_401 = V_404 ;
else
V_401 = V_405 ;
else
V_401 = V_406 ;
memcpy ( F_202 ( V_106 -> V_110 ) , & V_401 , 1 ) ;
memcpy ( F_203 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_204 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_352 , V_364 ) ;
memcpy ( F_205 ( V_106 -> V_110 ) ,
V_2 -> V_3 . V_407 , 9 ) ;
V_26 = F_176 ( V_2 , V_403 , V_106 ,
F_195 , NULL ) ;
return V_26 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_168 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_408 ,
F_207 ( V_106 -> V_110 ) ,
V_364 ) ;
if ( ! strncmp ( L_169 , F_207 ( V_106 -> V_110 ) ,
3 ) ) {
F_24 ( V_52 , 2 , L_170 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_171
L_172 ) ;
V_106 -> V_26 = - V_409 ;
}
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 )
{
int V_26 ;
V_169 V_356 ;
struct V_105 * V_106 ;
struct V_357 V_410 ;
F_24 ( V_52 , 2 , L_173 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_411 , V_412 ) ;
memcpy ( F_209 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_210 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_353 , V_364 ) ;
memcpy ( F_211 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_396 , V_364 ) ;
F_164 ( F_26 ( V_2 ) , & V_410 ) ;
memcpy ( F_212 ( V_106 -> V_110 ) , & V_410 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_3 . V_342 << 8 ) + V_2 -> V_3 . V_341 ;
memcpy ( F_213 ( V_106 -> V_110 ) , & V_356 , 2 ) ;
V_26 = F_176 ( V_2 , V_412 , V_106 ,
F_206 , NULL ) ;
return V_26 ;
}
static int F_39 ( struct V_84 * V_85 , int V_86 )
{
int V_26 ;
struct V_89 * V_413 ;
V_26 = 0 ;
V_413 = F_214 ( V_94 , V_119 ) ;
if ( ! V_413 ) {
V_26 = - V_39 ;
goto V_60;
}
V_413 -> V_66 = & V_85 -> V_54 [ V_86 ] ;
F_215 ( & V_413 -> V_220 ) ;
F_216 ( & V_413 -> V_220 . V_141 , & V_414 ) ;
V_413 -> V_85 = V_85 ;
V_413 -> V_95 = NULL ;
V_413 -> V_88 = V_85 -> V_65 [ V_86 ] ;
F_43 ( & V_413 -> V_44 , V_235 ) ;
V_85 -> V_65 [ V_86 ] = V_413 ;
if ( V_85 -> V_71 ) {
V_85 -> V_71 [ V_86 ] . V_415 = V_413 ;
F_35 ( V_85 -> V_2 , 2 , L_174 , V_86 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 , ( long ) V_413 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 ,
( long ) V_413 -> V_88 ) ;
}
V_60:
return V_26 ;
}
static int F_217 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
F_24 ( V_52 , 2 , L_175 ) ;
if ( F_42 ( & V_2 -> V_35 . V_44 , V_242 ,
V_329 ) != V_242 )
return 0 ;
V_2 -> V_35 . V_244 = F_15 ( sizeof( struct V_63 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_244 )
goto V_416;
F_24 ( V_52 , 2 , L_176 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_244 , sizeof( void * ) ) ;
memset ( V_2 -> V_35 . V_244 , 0 , sizeof( struct V_63 ) ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_66 =
& V_2 -> V_35 . V_244 -> V_54 [ V_33 ] ;
V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_245 = NULL ;
}
if ( F_14 ( V_2 ) )
goto V_417;
V_2 -> V_35 . V_70 =
F_15 ( V_2 -> V_35 . V_68 *
sizeof( struct V_84 * ) , V_38 ) ;
if ( ! V_2 -> V_35 . V_70 )
goto V_418;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
V_2 -> V_35 . V_70 [ V_33 ] = F_15 ( sizeof( struct V_84 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_70 [ V_33 ] )
goto V_419;
F_27 ( V_52 , 2 , L_177 , V_33 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_70 [ V_33 ] , sizeof( void * ) ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_420 = V_33 ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
F_58 ( V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] != NULL ) ;
if ( F_39 ( V_2 -> V_35 . V_70 [ V_33 ] , V_34 ) )
goto V_421;
}
}
if ( F_28 ( V_2 ) )
goto V_419;
return 0 ;
V_421:
while ( V_34 > 0 ) {
-- V_34 ;
F_38 ( V_94 ,
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] = NULL ;
}
V_419:
while ( V_33 > 0 ) {
F_20 ( V_2 -> V_35 . V_70 [ -- V_33 ] ) ;
F_110 ( V_2 -> V_35 . V_70 [ V_33 ] , 1 ) ;
}
F_20 ( V_2 -> V_35 . V_70 ) ;
V_2 -> V_35 . V_70 = NULL ;
V_418:
F_16 ( V_2 ) ;
V_417:
F_20 ( V_2 -> V_35 . V_244 ) ;
V_2 -> V_35 . V_244 = NULL ;
V_416:
F_43 ( & V_2 -> V_35 . V_44 , V_242 ) ;
return - V_39 ;
}
static void F_218 ( struct V_1 * V_2 ,
char * V_422 )
{
V_422 [ 0 ] = V_343 [ 'P' ] ;
V_422 [ 1 ] = V_343 [ 'C' ] ;
V_422 [ 2 ] = V_343 [ 'I' ] ;
V_422 [ 3 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_422 [ 4 ] ) ) = F_219 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_422 [ 8 ] ) ) = F_220 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_422 [ 12 ] ) ) = F_221 ( V_2 ) ;
}
static void F_222 ( struct V_1 * V_2 ,
char * V_422 )
{
V_422 [ 16 ] = V_343 [ 'B' ] ;
V_422 [ 17 ] = V_343 [ 'L' ] ;
V_422 [ 18 ] = V_343 [ 'K' ] ;
V_422 [ 19 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_422 [ 20 ] ) ) = V_2 -> V_3 . V_344 . V_345 ;
* ( ( unsigned int * ) ( & V_422 [ 24 ] ) ) = V_2 -> V_3 . V_344 . V_346 ;
* ( ( unsigned int * ) ( & V_422 [ 28 ] ) ) =
V_2 -> V_3 . V_344 . V_347 ;
}
static int F_223 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 3 , L_178 ) ;
return F_224 ( F_26 ( V_2 ) ) ;
}
static int F_225 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_179 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_423 , V_424 ) ;
memcpy ( F_226 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_227 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
V_26 = F_176 ( V_2 , V_424 , V_106 , NULL , NULL ) ;
return V_26 ;
}
static int F_228 ( struct V_1 * V_2 )
{
int V_26 ;
F_24 ( V_52 , 2 , L_180 ) ;
V_26 = F_48 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_183 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
goto V_425;
}
V_26 = F_188 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_425;
}
V_26 = F_200 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_425;
}
V_26 = F_208 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_425;
}
V_26 = F_217 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_425;
}
V_26 = F_229 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_112 ( V_2 ) ;
goto V_425;
}
V_26 = F_223 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_184 , V_26 ) ;
goto V_425;
}
V_26 = F_225 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_185 , V_26 ) ;
goto V_425;
}
return 0 ;
V_425:
F_147 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
return V_26 ;
}
static void F_230 ( struct V_1 * V_2 )
{
char V_426 [ 15 ] ;
int V_33 ;
sprintf ( V_426 , L_186 , V_2 -> V_3 . V_407 + 1 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_426 [ V_33 ] =
( char ) V_427 [ ( T_2 ) V_426 [ V_33 ] ] ;
V_426 [ 8 ] = 0 ;
F_72 ( & V_2 -> V_72 -> V_73 , L_187
L_188 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? V_2 -> V_3 . V_296 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ,
V_426 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_407 [ 0 ] )
F_72 ( & V_2 -> V_72 -> V_73 , L_191
L_192
L_193 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? V_2 -> V_3 . V_296 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ) ;
else
F_72 ( & V_2 -> V_72 -> V_73 , L_191
L_194 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? V_2 -> V_3 . V_296 : L_69 ,
( V_2 -> V_3 . V_296 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ) ;
}
void F_232 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
if ( ! V_2 -> V_3 . V_296 [ 0 ] ) {
sprintf ( V_2 -> V_3 . V_296 , L_195 ,
V_2 -> V_3 . V_296 [ 2 ] ,
V_2 -> V_3 . V_296 [ 3 ] ) ;
V_2 -> V_3 . V_296 [ V_373 ] = 0 ;
break;
}
case V_6 :
if ( ( V_2 -> V_3 . V_4 ) ||
( V_2 -> V_3 . V_296 [ 0 ] & 0x80 ) ) {
V_2 -> V_3 . V_296 [ 0 ] = ( char ) V_427 [ ( T_2 )
V_2 -> V_3 . V_296 [ 0 ] ] ;
V_2 -> V_3 . V_296 [ 1 ] = ( char ) V_427 [ ( T_2 )
V_2 -> V_3 . V_296 [ 1 ] ] ;
V_2 -> V_3 . V_296 [ 2 ] = ( char ) V_427 [ ( T_2 )
V_2 -> V_3 . V_296 [ 2 ] ] ;
V_2 -> V_3 . V_296 [ 3 ] = ( char ) V_427 [ ( T_2 )
V_2 -> V_3 . V_296 [ 3 ] ] ;
V_2 -> V_3 . V_296 [ V_373 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_3 . V_296 [ 0 ] , 0 , V_373 + 1 ) ;
}
if ( V_2 -> V_3 . V_371 )
F_230 ( V_2 ) ;
else
F_231 ( V_2 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_28 * V_428 ;
F_11 ( V_2 , 5 , L_196 ) ;
F_234 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_235 ( V_2 , V_428 ) ;
}
}
static inline struct V_28 * F_236 (
struct V_1 * V_2 )
{
struct V_297 * V_429 ;
struct V_28 * V_428 ;
int V_33 , free ;
struct V_430 * V_430 ;
if ( F_237 ( & V_2 -> V_35 . V_48 . V_42 ) )
return NULL ;
F_238 (plh, &card->qdio.in_buf_pool.entry_list) {
V_428 = F_239 ( V_429 , struct V_28 , V_31 ) ;
free = 1 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_240 ( F_241 ( V_428 -> V_40 [ V_33 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_75 ( & V_428 -> V_31 ) ;
return V_428 ;
}
}
V_428 = F_239 ( V_2 -> V_35 . V_48 . V_42 . V_431 ,
struct V_28 , V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_240 ( F_241 ( V_428 -> V_40 [ V_33 ] ) ) > 1 ) {
V_430 = F_242 ( V_119 ) ;
if ( ! V_430 ) {
return NULL ;
} else {
F_19 ( ( unsigned long ) V_428 -> V_40 [ V_33 ] ) ;
V_428 -> V_40 [ V_33 ] = F_243 ( V_430 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_433 ++ ;
}
}
}
F_75 ( & V_428 -> V_31 ) ;
return V_428 ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_434 * V_217 )
{
struct V_28 * V_29 ;
int V_33 ;
if ( ( V_2 -> V_49 . V_50 == V_51 ) && ( ! V_217 -> V_245 ) ) {
V_217 -> V_245 = F_245 ( V_435 + V_436 ) ;
if ( ! V_217 -> V_245 )
return 1 ;
}
V_29 = F_236 ( V_2 ) ;
if ( ! V_29 )
return 1 ;
V_217 -> V_29 = V_29 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
V_217 -> V_66 -> V_231 [ V_33 ] . V_239 = V_399 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_236 = V_29 -> V_40 [ V_33 ] ;
if ( V_33 == F_17 ( V_2 ) - 1 )
V_217 -> V_66 -> V_231 [ V_33 ] . V_240 = V_437 ;
else
V_217 -> V_66 -> V_231 [ V_33 ] . V_240 = 0 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_232 = 0 ;
}
return 0 ;
}
int F_246 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
int V_26 ;
F_24 ( V_52 , 2 , L_197 ) ;
memset ( V_2 -> V_35 . V_244 -> V_54 , 0 ,
V_55 * sizeof( struct V_56 ) ) ;
F_233 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_48 . V_37 - 1 ; ++ V_33 )
F_244 ( V_2 , & V_2 -> V_35 . V_244 -> V_65 [ V_33 ] ) ;
V_2 -> V_35 . V_244 -> V_57 =
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
F_45 ( V_2 -> V_35 . V_70 [ V_33 ] ,
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] ,
V_235 ) ;
}
V_2 -> V_35 . V_70 [ V_33 ] -> V_2 = V_2 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_438 = 0 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_439 = 0 ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_440 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_234 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_44 ,
V_441 ) ;
}
return 0 ;
}
static inline T_2 F_247 ( enum V_442 V_10 )
{
switch ( V_10 ) {
case V_12 :
return 2 ;
default:
return 1 ;
}
}
static void F_248 ( struct V_1 * V_2 ,
struct V_122 * V_123 , T_2 V_127 ,
enum V_443 V_444 )
{
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_126 . V_127 = V_127 ;
V_123 -> V_126 . V_445 = V_446 ;
V_123 -> V_126 . V_166 = V_2 -> V_166 . V_379 ;
V_123 -> V_126 . V_447 = F_247 ( V_2 -> V_3 . V_10 ) ;
V_123 -> V_126 . V_448 = ( T_2 ) V_2 -> V_3 . V_363 ;
if ( V_2 -> V_49 . V_301 )
V_123 -> V_126 . V_449 = 2 ;
else
V_123 -> V_126 . V_449 = 1 ;
V_123 -> V_126 . V_450 = 1 ;
V_123 -> V_126 . V_384 = V_444 ;
V_123 -> V_126 . V_451 = 0 ;
V_123 -> V_126 . V_452 = 0 ;
}
struct V_105 * F_249 ( struct V_1 * V_2 ,
enum V_453 V_454 , enum V_443 V_444 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
F_248 ( V_2 , V_123 , V_454 , V_444 ) ;
return V_106 ;
}
void F_250 ( struct V_1 * V_2 , struct V_105 * V_106 ,
char V_401 )
{
memcpy ( V_106 -> V_110 , V_455 , V_382 ) ;
memcpy ( F_251 ( V_106 -> V_110 ) , & V_401 , 1 ) ;
memcpy ( F_252 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
}
int F_253 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int (* F_177)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_375 )
{
int V_26 ;
char V_401 ;
F_11 ( V_2 , 4 , L_198 ) ;
if ( V_2 -> V_49 . V_301 )
if ( V_2 -> V_3 . type == V_9 )
V_401 = V_404 ;
else
V_401 = V_405 ;
else
V_401 = V_406 ;
F_250 ( V_2 , V_106 , V_401 ) ;
V_26 = F_176 ( V_2 , V_456 ,
V_106 , F_177 , V_375 ) ;
if ( V_26 == - V_319 ) {
F_74 ( V_2 ) ;
F_55 ( V_2 ) ;
}
return V_26 ;
}
int F_254 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_199 ) ;
V_106 = F_249 ( V_2 , V_136 , 0 ) ;
V_26 = F_253 ( V_2 , V_106 , NULL , NULL ) ;
return V_26 ;
}
int F_255 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_200 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_132 == 0 )
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_457 . V_126 . V_132 ;
return 0 ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 3 , L_201 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_110 . V_457 . V_110 . V_458 . V_459 & 0x7f ) {
V_2 -> V_3 . V_10 =
V_123 -> V_110 . V_457 . V_110 . V_458 . V_459 ;
F_27 ( V_52 , 2 , L_202 , V_2 -> V_3 . V_10 ) ;
}
V_2 -> V_49 . V_460 . V_461 =
V_123 -> V_110 . V_457 . V_110 . V_458 . V_462 ;
return F_255 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
}
struct V_105 * F_257 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_463 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_249 ( V_2 , V_464 ,
V_385 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_126 . V_465 = V_463 ;
V_123 -> V_110 . V_457 . V_126 . V_466 = V_127 ;
V_123 -> V_110 . V_457 . V_126 . V_467 = 1 ;
V_123 -> V_110 . V_457 . V_126 . V_468 = 1 ;
return V_106 ;
}
int F_258 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 3 , L_203 ) ;
V_106 = F_257 ( V_2 , V_469 ,
sizeof( struct V_470 ) ) ;
V_26 = F_253 ( V_2 , V_106 , F_256 , NULL ) ;
return V_26 ;
}
static int F_259 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_204 ) ;
V_123 = (struct V_122 * ) V_110 ;
switch ( V_123 -> V_126 . V_132 ) {
case V_471 :
case V_472 :
F_24 ( V_52 , 2 , L_205 ) ;
V_2 -> V_49 . V_473 . V_461 |= V_474 ;
V_2 -> V_49 . V_475 . V_461 |= V_474 ;
return - 0 ;
default:
if ( V_123 -> V_126 . V_132 ) {
F_51 ( 1 , L_206
L_207 ,
F_52 ( & V_2 -> V_72 -> V_73 ) ,
V_123 -> V_126 . V_132 ) ;
return 0 ;
}
}
if ( V_123 -> V_126 . V_384 == V_385 ) {
V_2 -> V_49 . V_473 . V_461 = V_123 -> V_126 . V_451 ;
V_2 -> V_49 . V_473 . V_476 = V_123 -> V_126 . V_452 ;
} else if ( V_123 -> V_126 . V_384 == V_477 ) {
V_2 -> V_49 . V_475 . V_461 = V_123 -> V_126 . V_451 ;
V_2 -> V_49 . V_475 . V_476 = V_123 -> V_126 . V_452 ;
} else
F_51 ( 1 , L_208
L_209 , F_52 ( & V_2 -> V_72 -> V_73 ) ) ;
return 0 ;
}
int F_260 ( struct V_1 * V_2 , enum V_443 V_444 )
{
int V_26 ;
struct V_105 * V_106 ;
F_27 ( V_52 , 2 , L_210 , V_444 ) ;
V_106 = F_249 ( V_2 , V_478 , V_444 ) ;
V_26 = F_253 ( V_2 , V_106 , F_259 , NULL ) ;
return V_26 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_211 , V_26 ) ;
else
V_2 -> V_3 . V_479 = V_123 -> V_110 . V_480 . V_481 ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_212 ) ;
V_106 = F_249 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_480 . V_482 = 16 ;
V_123 -> V_110 . V_480 . V_483 = V_484 ;
return F_253 ( V_2 , V_106 , F_261 , NULL ) ;
}
static void F_263 ( struct V_1 * V_2 , struct V_485 * V_486 )
{
unsigned long V_3 = F_264 ( V_38 ) ;
struct V_487 * V_488 = (struct V_487 * ) V_3 ;
struct V_489 * V_490 = (struct V_489 * ) V_3 ;
struct V_357 V_491 ;
int V_367 ;
V_486 -> V_134 = V_2 -> V_3 . V_134 ;
F_164 ( F_137 ( V_2 ) , & V_491 ) ;
V_486 -> V_492 = V_491 . V_492 ;
V_486 -> V_365 = V_491 . V_365 ;
if ( ! V_3 )
return;
V_367 = F_265 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_367 >= 2 ) && ( F_265 ( V_488 , 2 , 2 , 2 ) == 0 ) )
V_486 -> V_493 = V_488 -> V_494 ;
if ( ( V_367 >= 3 ) && ( F_265 ( V_490 , 3 , 2 , 2 ) == 0 ) ) {
F_266 ( V_490 -> V_495 [ 0 ] . V_496 , sizeof( V_490 -> V_495 [ 0 ] . V_496 ) ) ;
memcpy ( V_486 -> V_497 , V_490 -> V_495 [ 0 ] . V_496 , sizeof( V_486 -> V_497 ) ) ;
}
F_19 ( V_3 ) ;
return;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_213 , V_26 ) ;
return 0 ;
}
int F_268 ( struct V_1 * V_2 , enum V_498 V_499 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_214 ) ;
V_106 = F_249 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_480 . V_482 = 80 ;
V_123 -> V_110 . V_480 . V_483 = V_500 ;
V_123 -> V_110 . V_480 . type = 1 ;
V_123 -> V_110 . V_480 . V_499 = V_499 ;
switch ( V_499 ) {
case V_501 :
V_123 -> V_110 . V_480 . V_49 = 0x0003 ;
V_123 -> V_110 . V_480 . V_481 = 0x00010000 +
sizeof( struct V_485 ) ;
F_263 ( V_2 ,
(struct V_485 * ) V_123 -> V_110 . V_480 . V_502 ) ;
break;
case V_503 :
V_123 -> V_110 . V_480 . V_49 = 0x0001 ;
break;
case V_504 :
break;
}
return F_253 ( V_2 , V_106 , F_267 , NULL ) ;
}
int F_269 ( struct V_1 * V_2 , struct V_56 * V_217 ,
unsigned int V_505 , const char * V_506 )
{
if ( V_505 ) {
F_11 ( V_2 , 2 , V_506 ) ;
F_35 ( V_2 , 2 , L_215 ,
V_217 -> V_231 [ 15 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_216 ,
V_217 -> V_231 [ 14 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_217 , V_505 ) ;
if ( ( V_217 -> V_231 [ 15 ] . V_232 ) == 0x12 ) {
V_2 -> V_507 . V_508 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_290 ( struct V_272 * V_273 )
{
struct V_1 * V_2 = F_125 ( V_273 , struct V_1 ,
V_243 . V_273 ) ;
F_35 ( V_2 , 2 , L_218 , V_2 -> V_509 ) ;
F_270 ( V_2 , V_2 -> V_509 ) ;
}
void F_270 ( struct V_1 * V_2 , int V_153 )
{
struct V_63 * V_104 = V_2 -> V_35 . V_244 ;
struct V_297 * V_510 ;
int V_151 ;
int V_33 ;
int V_26 ;
int V_511 = 0 ;
V_151 = ( V_153 < V_104 -> V_57 ) ?
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 - V_153 ) :
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 + V_55 - V_153 ) ;
if ( V_151 >= F_271 ( V_2 ) ) {
for ( V_33 = V_104 -> V_57 ;
V_33 < V_104 -> V_57 + V_151 ; ++ V_33 ) {
if ( F_244 ( V_2 ,
& V_104 -> V_65 [ V_33 % V_55 ] ) ) {
break;
} else {
V_511 ++ ;
}
}
if ( V_511 < V_151 ) {
F_43 ( & V_2 -> V_512 , 3 ) ;
V_151 = V_511 ;
} else {
F_272 ( & V_2 -> V_512 , - 1 , 0 ) ;
}
if ( ! V_151 ) {
V_33 = 0 ;
F_238 (lh, &card->qdio.in_buf_pool.entry_list)
V_33 ++ ;
if ( V_33 == V_2 -> V_35 . V_48 . V_37 ) {
F_11 ( V_2 , 2 , L_219 ) ;
V_2 -> V_509 = V_153 ;
F_273 (
& V_2 -> V_243 ,
V_513 ) ;
}
return;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_514 ++ ;
V_2 -> V_432 . V_515 =
F_274 () ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , 0 ,
V_104 -> V_57 , V_151 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_516 +=
F_274 () -
V_2 -> V_432 . V_515 ;
if ( V_26 ) {
F_11 ( V_2 , 2 , L_220 ) ;
}
V_104 -> V_57 = ( V_104 -> V_57 + V_151 ) %
V_55 ;
}
}
static int F_275 ( struct V_1 * V_2 ,
struct V_89 * V_66 , unsigned int V_517 )
{
int V_75 = V_66 -> V_66 -> V_231 [ 15 ] . V_232 ;
F_11 ( V_2 , 6 , L_221 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
if ( V_75 == 0 ) {
V_517 = 0 ;
} else {
V_517 = 1 ;
}
}
F_269 ( V_2 , V_66 -> V_66 , V_517 , L_222 ) ;
if ( ! V_517 )
return V_518 ;
if ( ( V_75 >= 15 ) && ( V_75 <= 31 ) )
return V_519 ;
F_11 ( V_2 , 1 , L_223 ) ;
F_35 ( V_2 , 1 , L_224 ,
( V_170 ) V_517 , ( T_3 ) V_75 ) ;
return V_520 ;
}
static void F_276 ( struct V_84 * V_104 )
{
if ( ! V_104 -> V_439 ) {
if ( F_34 ( & V_104 -> V_440 )
>= V_521 ) {
F_11 ( V_104 -> V_2 , 6 , L_225 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_522 ++ ;
V_104 -> V_439 = 1 ;
}
}
}
static int F_277 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
int V_523 = 0 ;
if ( V_104 -> V_439 ) {
if ( F_34 ( & V_104 -> V_440 )
<= V_524 ) {
F_11 ( V_104 -> V_2 , 6 , L_226 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_525 ++ ;
V_104 -> V_439 = 0 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) ==
V_235 ) &&
( V_66 -> V_241 > 0 ) ) {
F_43 ( & V_66 -> V_44 ,
V_100 ) ;
V_523 ++ ;
V_104 -> V_438 =
( V_104 -> V_438 + 1 ) %
V_55 ;
}
}
}
return V_523 ;
}
static int F_278 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) == V_235 ) &&
( V_66 -> V_241 > 0 ) ) {
F_43 ( & V_66 -> V_44 , V_100 ) ;
V_104 -> V_438 =
( V_104 -> V_438 + 1 ) % V_55 ;
return 1 ;
}
return 0 ;
}
static void F_279 ( struct V_84 * V_104 , int V_153 ,
int V_151 )
{
struct V_89 * V_217 ;
int V_26 ;
int V_33 ;
unsigned int V_526 ;
for ( V_33 = V_153 ; V_33 < V_153 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_217 = V_104 -> V_65 [ V_86 ] ;
V_217 -> V_66 -> V_231 [ V_217 -> V_241 - 1 ] . V_240 |=
V_437 ;
if ( V_104 -> V_71 )
V_104 -> V_71 [ V_86 ] . V_415 = V_217 ;
if ( V_104 -> V_2 -> V_3 . type == V_6 )
continue;
if ( ! V_104 -> V_439 ) {
if ( ( F_34 ( & V_104 -> V_440 ) >=
( V_521 -
V_527 ) ) &&
! F_34 ( & V_104 -> V_234 ) ) {
F_59 ( & V_104 -> V_234 ) ;
V_217 -> V_66 -> V_231 [ 0 ] . V_232 |= V_233 ;
}
} else {
if ( ! F_34 ( & V_104 -> V_234 ) ) {
F_59 ( & V_104 -> V_234 ) ;
V_217 -> V_66 -> V_231 [ 0 ] . V_232 |= V_233 ;
}
}
}
V_104 -> V_2 -> V_73 -> V_528 = V_381 ;
if ( V_104 -> V_2 -> V_49 . V_266 ) {
V_104 -> V_2 -> V_432 . V_529 ++ ;
V_104 -> V_2 -> V_432 . V_530 =
F_274 () ;
}
V_526 = V_531 ;
if ( F_34 ( & V_104 -> V_234 ) )
V_526 |= V_532 ;
V_26 = F_25 ( F_26 ( V_104 -> V_2 ) , V_526 ,
V_104 -> V_420 , V_153 , V_151 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_533 +=
F_274 () -
V_104 -> V_2 -> V_432 . V_530 ;
F_280 ( V_151 , & V_104 -> V_440 ) ;
if ( V_26 ) {
V_104 -> V_2 -> V_507 . V_534 += V_151 ;
if ( V_26 == - V_535 )
return;
F_11 ( V_104 -> V_2 , 2 , L_227 ) ;
F_35 ( V_104 -> V_2 , 2 , L_228 , V_104 -> V_420 ) ;
F_35 ( V_104 -> V_2 , 2 , L_229 , V_153 ) ;
F_35 ( V_104 -> V_2 , 2 , L_230 , V_151 ) ;
F_35 ( V_104 -> V_2 , 2 , L_160 , V_26 ) ;
F_55 ( V_104 -> V_2 ) ;
return;
}
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_536 += V_151 ;
}
static void F_281 ( struct V_84 * V_104 )
{
int V_153 ;
int V_537 = 0 ;
int V_538 = 0 ;
if ( ( F_34 ( & V_104 -> V_440 ) <= V_524 ) ||
! F_34 ( & V_104 -> V_234 ) ) {
if ( F_113 ( & V_104 -> V_44 , V_539 ) ==
V_441 ) {
F_282 ( V_104 -> V_2 -> V_73 ) ;
V_153 = V_104 -> V_438 ;
V_538 = V_104 -> V_439 ;
F_283 () ;
V_537 += F_277 ( V_104 ) ;
if ( ! V_537 &&
! F_34 ( & V_104 -> V_234 ) )
V_537 +=
F_278 ( V_104 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 &&
V_538 )
V_104 -> V_2 -> V_432 . V_540 +=
V_537 ;
if ( V_537 )
F_279 ( V_104 , V_153 , V_537 ) ;
F_43 ( & V_104 -> V_44 , V_441 ) ;
}
}
}
void F_284 ( struct V_178 * V_112 , int V_104 ,
unsigned long V_541 )
{
struct V_1 * V_2 = (struct V_1 * ) V_541 ;
if ( V_2 -> V_73 && ( V_2 -> V_73 -> V_21 & V_542 ) )
F_285 ( & V_2 -> V_543 ) ;
}
int F_286 ( struct V_1 * V_2 , enum V_544 V_50 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_545 ) {
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
F_112 ( V_2 ) ;
V_2 -> V_49 . V_50 = V_50 ;
V_26 = 0 ;
}
V_60:
return V_26 ;
}
static void F_287 ( struct V_1 * V_2 ,
unsigned int V_517 ,
unsigned int V_104 , int V_546 , int V_151 ) {
struct V_63 * V_50 = V_2 -> V_35 . V_53 ;
int V_33 ;
int V_26 ;
if ( ! F_47 ( V_2 , V_104 ) )
goto V_60;
F_35 ( V_2 , 5 , L_231 , V_546 ) ;
F_35 ( V_2 , 5 , L_232 , V_151 ) ;
F_35 ( V_2 , 5 , L_233 , V_517 ) ;
if ( V_517 ) {
F_282 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_547 ++ ;
V_2 -> V_432 . V_548 = F_274 () ;
}
for ( V_33 = V_546 ; V_33 < V_546 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
struct V_56 * V_66 = & V_50 -> V_54 [ V_86 ] ;
int V_549 ;
V_549 = 0 ;
while ( V_66 -> V_231 [ V_549 ] . V_236 ) {
unsigned long V_96 ;
V_96 = ( unsigned long ) V_66 -> V_231 [ V_549 ] . V_236 ;
F_40 ( V_2 , V_96 ) ;
V_66 -> V_231 [ V_549 ] . V_236 = NULL ;
V_66 -> V_231 [ V_549 ] . V_240 = 0 ;
V_66 -> V_231 [ V_549 ] . V_232 = 0 ;
V_66 -> V_231 [ V_549 ] . V_239 = 0 ;
++ V_549 ;
}
V_66 -> V_231 [ 15 ] . V_240 = 0 ;
V_66 -> V_231 [ 15 ] . V_232 = 0 ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , V_104 ,
V_2 -> V_35 . V_53 -> V_57 ,
V_151 ) ;
if ( V_26 ) {
F_50 ( & V_2 -> V_72 -> V_73 ,
L_234 , V_26 ) ;
F_11 ( V_2 , 2 , L_235 ) ;
}
V_2 -> V_35 . V_53 -> V_57 = ( V_2 -> V_35 . V_53 -> V_57
+ V_151 ) % V_55 ;
F_288 ( V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_266 ) {
int V_550 = F_274 () ;
V_550 -= V_2 -> V_432 . V_548 ;
V_2 -> V_432 . V_551 += V_550 ;
}
V_60:
return;
}
void F_289 ( struct V_178 * V_112 , unsigned int V_517 ,
unsigned int V_104 , int V_552 , int V_151 ,
unsigned long V_541 )
{
struct V_1 * V_2 = (struct V_1 * ) V_541 ;
F_35 ( V_2 , 2 , L_236 , V_104 ) ;
F_35 ( V_2 , 2 , L_237 , V_517 ) ;
if ( F_47 ( V_2 , V_104 ) )
F_287 ( V_2 , V_517 , V_104 , V_552 , V_151 ) ;
else if ( V_517 )
F_55 ( V_2 ) ;
}
void F_290 ( struct V_178 * V_112 ,
unsigned int V_505 , int V_553 , int V_546 ,
int V_151 , unsigned long V_541 )
{
struct V_1 * V_2 = (struct V_1 * ) V_541 ;
struct V_84 * V_104 = V_2 -> V_35 . V_70 [ V_553 ] ;
struct V_89 * V_66 ;
int V_33 ;
F_11 ( V_2 , 6 , L_238 ) ;
if ( V_505 & V_554 ) {
F_11 ( V_2 , 2 , L_239 ) ;
F_282 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
return;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_555 ++ ;
V_2 -> V_432 . V_556 =
F_274 () ;
}
for ( V_33 = V_546 ; V_33 < ( V_546 + V_151 ) ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_66 = V_104 -> V_65 [ V_86 ] ;
F_275 ( V_2 , V_66 , V_505 ) ;
if ( V_104 -> V_71 &&
( V_104 -> V_71 [ V_86 ] . V_21 &
V_557 ) != 0 ) {
F_37 ( V_2 -> V_49 . V_50 != V_51 ) ;
if ( F_42 ( & V_66 -> V_44 ,
V_100 ,
V_102 ) ==
V_100 ) {
F_44 ( V_104 , V_66 ,
V_558 ) ;
}
V_66 -> V_95 = V_104 -> V_71 [ V_86 ] . V_95 ;
F_35 ( V_104 -> V_2 , 5 , L_240 , V_86 ) ;
F_11 ( V_104 -> V_2 , 5 , L_241 ) ;
F_35 ( V_104 -> V_2 , 5 , L_41 ,
F_291 ( V_66 -> V_95 ) ) ;
if ( F_39 ( V_104 , V_86 ) ) {
F_11 ( V_2 , 2 , L_242 ) ;
F_55 ( V_2 ) ;
}
} else {
if ( V_2 -> V_49 . V_50 == V_51 ) {
enum V_74 V_77 ;
V_77 = F_32 (
V_66 -> V_66 -> V_231 [ 15 ] . V_232 , 0 ) ;
F_44 ( V_104 , V_66 , V_77 ) ;
}
F_45 ( V_104 , V_66 ,
V_235 ) ;
}
F_33 ( V_104 , V_86 , 0 ) ;
}
F_292 ( V_151 , & V_104 -> V_440 ) ;
if ( V_2 -> V_3 . type != V_6 )
F_281 ( V_104 ) ;
F_288 ( V_104 -> V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_559 += F_274 () -
V_2 -> V_432 . V_556 ;
}
int F_293 ( struct V_1 * V_2 , struct V_218 * V_219 ,
int V_560 , int V_561 )
{
if ( ! V_560 && ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) )
return V_2 -> V_35 . V_246 ;
switch ( V_2 -> V_35 . V_68 ) {
case 4 :
if ( V_561 && V_2 -> V_3 . V_313 )
return V_2 -> V_3 . V_313 &
( V_2 -> V_35 . V_68 - 1 ) ;
if ( V_2 -> V_35 . V_303 && ( V_560 == 4 ) ) {
const T_3 V_562 = F_294 ( V_219 ) -> V_562 ;
if ( V_2 -> V_35 . V_303 ==
V_563 ) {
if ( V_562 & V_564 )
return 3 ;
if ( V_562 & V_565 )
return 2 ;
if ( V_562 & V_566 )
return 1 ;
if ( V_562 & V_567 )
return 0 ;
}
if ( V_2 -> V_35 . V_303 ==
V_568 )
return 3 - ( V_562 >> 6 ) ;
} else if ( V_2 -> V_35 . V_303 && ( V_560 == 6 ) ) {
}
return V_2 -> V_35 . V_246 ;
case 1 :
default:
return V_2 -> V_35 . V_246 ;
}
}
int F_295 ( struct V_1 * V_2 , void * V_126 ,
struct V_218 * V_219 , int V_569 )
{
int V_570 = V_219 -> V_147 - V_219 -> V_571 ;
int V_572 = F_296 ( ( unsigned long ) V_219 -> V_110 + V_570 - 1 ) -
F_297 ( ( unsigned long ) V_219 -> V_110 ) ;
V_572 += F_298 ( V_219 ) -> V_573 ;
if ( ( V_572 + V_569 ) > F_17 ( V_2 ) ) {
F_51 ( 2 , L_243
L_244 ,
( V_572 + V_569 ) , V_219 -> V_147 ) ;
return 0 ;
}
return V_572 ;
}
int F_299 ( struct V_218 * V_219 , int V_147 )
{
int V_574 , V_575 , V_576 ;
if ( ( ( unsigned long ) V_219 -> V_110 & V_577 ) !=
( ( ( unsigned long ) V_219 -> V_110 + V_147 - 1 ) & V_577 ) ) {
V_574 = F_300 ( V_219 ) ;
V_575 = V_399 - ( ( unsigned long ) V_219 -> V_110 % V_399 ) ;
V_576 = V_147 - V_575 ;
if ( V_576 > V_574 )
return 1 ;
memmove ( V_219 -> V_110 - V_576 , V_219 -> V_110 , V_219 -> V_147 - V_219 -> V_571 ) ;
V_219 -> V_110 -= V_576 ;
F_51 ( 2 , L_245 , V_147 , V_576 ) ;
}
return 0 ;
}
static inline void F_301 ( struct V_218 * V_219 ,
struct V_56 * V_66 , int V_578 , int * V_241 ,
int V_168 )
{
int V_239 = V_219 -> V_147 - V_219 -> V_571 ;
int V_579 ;
int V_231 ;
char * V_110 ;
int V_580 , V_161 ;
struct V_581 * V_582 ;
V_231 = * V_241 ;
V_110 = V_219 -> V_110 ;
V_580 = ( V_578 == 0 ? 1 : 0 ) ;
if ( V_168 >= 0 ) {
V_110 = V_219 -> V_110 + V_168 ;
V_239 -= V_168 ;
V_580 = 0 ;
}
while ( V_239 > 0 ) {
V_579 = V_399 - ( ( unsigned long ) V_110 % V_399 ) ;
if ( V_239 < V_579 )
V_579 = V_239 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_579 ;
V_239 -= V_579 ;
if ( ! V_239 ) {
if ( V_580 )
if ( F_298 ( V_219 ) -> V_573 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_583 ;
else
V_66 -> V_231 [ V_231 ] . V_240 = 0 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_584 ;
} else {
if ( V_580 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_583 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_584 ;
}
V_110 += V_579 ;
V_231 ++ ;
V_580 = 0 ;
}
for ( V_161 = 0 ; V_161 < F_298 ( V_219 ) -> V_573 ; V_161 ++ ) {
V_582 = & F_298 ( V_219 ) -> V_585 [ V_161 ] ;
V_66 -> V_231 [ V_231 ] . V_236 = ( char * )
F_302 ( F_303 ( V_582 ) )
+ V_582 -> V_586 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_582 -> V_587 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_584 ;
V_231 ++ ;
}
if ( V_66 -> V_231 [ V_231 - 1 ] . V_240 )
V_66 -> V_231 [ V_231 - 1 ] . V_240 = V_588 ;
* V_241 = V_231 ;
}
static inline int F_304 ( struct V_84 * V_104 ,
struct V_89 * V_217 , struct V_218 * V_219 ,
struct V_589 * V_126 , int V_168 , int V_590 )
{
struct V_56 * V_66 ;
int V_537 = 0 , V_591 , V_592 = 0 ;
V_66 = V_217 -> V_66 ;
F_59 ( & V_219 -> V_228 ) ;
F_305 ( & V_217 -> V_220 , V_219 ) ;
if ( V_126 -> V_126 . V_593 . V_308 == V_594 ) {
int V_231 = V_217 -> V_241 ;
V_591 = sizeof( struct V_595 ) +
( (struct V_595 * ) V_126 ) -> V_481 . V_596 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_219 -> V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_591 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_583 ;
V_217 -> V_241 ++ ;
V_219 -> V_110 += V_591 ;
V_219 -> V_147 -= V_591 ;
V_592 = 1 ;
}
if ( V_168 >= 0 ) {
int V_231 = V_217 -> V_241 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_126 ;
V_66 -> V_231 [ V_231 ] . V_239 = sizeof( struct V_589 ) +
V_590 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_583 ;
V_217 -> V_237 [ V_231 ] = 1 ;
V_217 -> V_241 ++ ;
}
F_301 ( V_219 , V_66 , V_592 ,
( int * ) & V_217 -> V_241 , V_168 ) ;
if ( ! V_104 -> V_439 ) {
F_11 ( V_104 -> V_2 , 6 , L_246 ) ;
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_537 = 1 ;
} else {
F_11 ( V_104 -> V_2 , 6 , L_247 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_597 ++ ;
if ( V_217 -> V_241 >=
F_17 ( V_104 -> V_2 ) ) {
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_537 = 1 ;
}
}
return V_537 ;
}
int F_306 ( struct V_1 * V_2 ,
struct V_84 * V_104 , struct V_218 * V_219 ,
struct V_589 * V_126 , int V_572 ,
int V_168 , int V_590 )
{
struct V_89 * V_66 ;
int V_153 ;
while ( F_42 ( & V_104 -> V_44 , V_441 ,
V_598 ) != V_441 ) ;
V_153 = V_104 -> V_438 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 )
goto V_60;
V_104 -> V_438 = ( V_104 -> V_438 + 1 ) %
V_55 ;
F_43 ( & V_104 -> V_44 , V_441 ) ;
F_304 ( V_104 , V_66 , V_219 , V_126 , V_168 , V_590 ) ;
F_279 ( V_104 , V_153 , 1 ) ;
return 0 ;
V_60:
F_43 ( & V_104 -> V_44 , V_441 ) ;
return - V_599 ;
}
int F_307 ( struct V_1 * V_2 , struct V_84 * V_104 ,
struct V_218 * V_219 , struct V_589 * V_126 ,
int V_572 )
{
struct V_89 * V_66 ;
int V_600 ;
int V_523 = 0 ;
int V_439 = 0 ;
int V_30 ;
int V_26 = 0 ;
while ( F_42 ( & V_104 -> V_44 , V_441 ,
V_598 ) != V_441 ) ;
V_600 = V_104 -> V_438 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 ) {
F_43 ( & V_104 -> V_44 , V_441 ) ;
return - V_599 ;
}
F_276 ( V_104 ) ;
if ( V_104 -> V_439 ) {
V_439 = 1 ;
if ( ( F_17 ( V_2 ) -
V_66 -> V_241 ) < V_572 ) {
F_43 ( & V_66 -> V_44 , V_100 ) ;
V_523 ++ ;
V_104 -> V_438 =
( V_104 -> V_438 + 1 ) %
V_55 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) !=
V_235 ) {
F_279 ( V_104 , V_600 ,
V_523 ) ;
F_43 ( & V_104 -> V_44 ,
V_441 ) ;
return - V_599 ;
}
}
}
V_30 = F_304 ( V_104 , V_66 , V_219 , V_126 , - 1 , 0 ) ;
V_104 -> V_438 = ( V_104 -> V_438 + V_30 ) %
V_55 ;
V_523 += V_30 ;
if ( V_523 )
F_279 ( V_104 , V_600 , V_523 ) ;
else if ( ! F_34 ( & V_104 -> V_234 ) )
F_113 ( & V_104 -> V_44 , V_539 ) ;
while ( F_308 ( & V_104 -> V_44 ) ) {
V_523 = 0 ;
V_600 = V_104 -> V_438 ;
V_523 += F_277 ( V_104 ) ;
if ( ! V_523 && ! F_34 ( & V_104 -> V_234 ) )
V_523 += F_278 ( V_104 ) ;
if ( V_523 )
F_279 ( V_104 , V_600 , V_523 ) ;
}
if ( V_104 -> V_2 -> V_49 . V_266 && V_439 )
V_104 -> V_2 -> V_432 . V_540 += V_523 ;
return V_26 ;
}
static int F_309 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_470 * V_601 ;
F_11 ( V_2 , 4 , L_248 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_601 = & ( V_123 -> V_110 . V_457 ) ;
F_255 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_249 , V_123 -> V_126 . V_132 ) ;
V_601 -> V_110 . V_602 = V_603 ;
}
V_2 -> V_3 . V_604 = V_601 -> V_110 . V_602 ;
return 0 ;
}
void F_310 ( struct V_1 * V_2 )
{
enum V_605 V_602 ;
struct V_606 * V_73 = V_2 -> V_73 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_250 ) ;
if ( ( ( V_73 -> V_21 & V_607 ) &&
( V_2 -> V_3 . V_604 == V_608 ) ) ||
( ! ( V_73 -> V_21 & V_607 ) &&
( V_2 -> V_3 . V_604 == V_603 ) ) )
return;
V_602 = V_603 ;
if ( V_73 -> V_21 & V_607 )
V_602 = V_608 ;
F_35 ( V_2 , 4 , L_251 , V_602 ) ;
V_106 = F_257 ( V_2 , V_609 ,
sizeof( struct V_470 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_110 . V_602 = V_602 ;
F_253 ( V_2 , V_106 , F_309 , NULL ) ;
}
int F_311 ( struct V_606 * V_73 , int V_610 )
{
struct V_1 * V_2 ;
char V_426 [ 15 ] ;
V_2 = V_73 -> V_611 ;
F_11 ( V_2 , 4 , L_252 ) ;
sprintf ( V_426 , L_253 , V_610 ) ;
F_11 ( V_2 , 4 , V_426 ) ;
if ( V_610 < 64 )
return - V_397 ;
if ( V_610 > 65535 )
return - V_397 ;
if ( ( ! F_312 ( V_2 , V_612 ) ) &&
( ! F_194 ( V_2 , V_610 ) ) )
return - V_397 ;
V_73 -> V_395 = V_610 ;
return 0 ;
}
struct V_613 * F_313 ( struct V_606 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_611 ;
F_11 ( V_2 , 5 , L_254 ) ;
return & V_2 -> V_507 ;
}
static int F_314 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_255 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( ! V_2 -> V_49 . V_301 ||
! ( V_2 -> V_3 . V_614 & V_615 ) ) {
memcpy ( V_2 -> V_73 -> V_616 ,
& V_123 -> V_110 . V_457 . V_110 . V_617 . V_236 ,
V_618 ) ;
V_2 -> V_3 . V_614 |= V_615 ;
}
F_255 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
int F_315 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_256 ) ;
V_106 = F_257 ( V_2 , V_619 ,
sizeof( struct V_470 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_110 . V_617 . V_123 = V_620 ;
V_123 -> V_110 . V_457 . V_110 . V_617 . V_621 = V_618 ;
memcpy ( & V_123 -> V_110 . V_457 . V_110 . V_617 . V_236 ,
V_2 -> V_73 -> V_616 , V_618 ) ;
V_26 = F_253 ( V_2 , V_106 , F_314 ,
NULL ) ;
return V_26 ;
}
static int F_316 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_622 * V_623 ;
F_11 ( V_2 , 4 , L_257 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_623 = & V_123 -> V_110 . V_457 . V_110 . V_624 ;
F_27 ( V_52 , 2 , L_257 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_625 . V_496 ) ;
F_27 ( V_52 , 2 , L_258 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
switch ( V_123 -> V_110 . V_457 . V_126 . V_132 ) {
case V_626 :
case V_627 :
case V_628 :
{
V_2 -> V_49 . V_269 = V_623 -> V_629 ;
if ( V_2 -> V_49 . V_269 == V_270 ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_259 ) ;
} else {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_260 ) ;
}
F_51 ( 3 , L_261 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_623 -> V_629 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
break;
}
case V_630 :
{
F_51 ( 3 , L_262 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_623 -> V_629 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_263
L_264 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
case V_631 :
{
F_51 ( 3 , L_265 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_623 -> V_629 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_266
L_267 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
case V_632 :
{
F_51 ( 3 , L_265 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_623 -> V_629 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_268 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
default:
{
F_51 ( 3 , L_269
L_270 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_623 -> V_629 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
}
F_255 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
static int F_317 ( struct V_1 * V_2 ,
enum V_633 V_269 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_622 * V_623 ;
F_11 ( V_2 , 4 , L_271 ) ;
F_27 ( V_52 , 2 , L_271 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_625 . V_496 ) ;
V_106 = F_257 ( V_2 , V_634 ,
sizeof( struct V_635 ) +
sizeof( struct V_622 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_623 = & V_123 -> V_110 . V_457 . V_110 . V_624 ;
V_623 -> V_629 = V_269 ;
V_26 = F_253 ( V_2 , V_106 , F_316 ,
NULL ) ;
F_27 ( V_52 , 2 , L_258 , V_26 ) ;
return V_26 ;
}
int F_318 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
F_11 ( V_2 , 4 , L_272 ) ;
if ( ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) &&
F_319 ( V_2 , V_634 ) ) {
V_26 = F_317 ( V_2 ,
V_2 -> V_49 . V_269 ) ;
if ( V_26 ) {
F_51 ( 3 ,
L_273 ,
V_2 -> V_72 -> V_73 . V_625 . V_496 ,
V_26 ) ;
}
} else if ( V_2 -> V_49 . V_269 != V_270 ) {
V_2 -> V_49 . V_269 = V_270 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_263
L_264 ) ;
V_26 = - V_334 ;
}
return V_26 ;
}
void F_320 ( struct V_606 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_611 ;
F_11 ( V_2 , 4 , L_274 ) ;
V_2 -> V_507 . V_534 ++ ;
F_55 ( V_2 ) ;
}
int F_321 ( struct V_606 * V_73 , int V_636 , int V_637 )
{
struct V_1 * V_2 = V_73 -> V_611 ;
int V_26 = 0 ;
switch ( V_637 ) {
case V_638 :
V_26 = V_639 ;
if ( ( V_2 -> V_3 . V_10 != V_13 ) &&
( V_2 -> V_3 . V_10 != V_640 ) &&
( V_2 -> V_3 . V_10 != V_14 ) )
V_26 |= V_641 ;
break;
case V_642 :
V_26 = V_643 | V_644 | V_645 |
V_646 | V_647 | V_648 | V_649 |
V_650 ;
break;
case V_651 :
V_26 = ( V_73 -> V_616 [ 0 ] << 16 ) | ( V_73 -> V_616 [ 1 ] << 8 ) |
V_73 -> V_616 [ 2 ] ;
V_26 = ( V_26 >> 5 ) & 0xFFFF ;
break;
case V_652 :
V_26 = ( V_73 -> V_616 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_653 :
V_26 = V_654 ;
break;
case V_655 :
V_26 = V_656 | V_657 | V_658 | V_659 |
V_660 | V_661 ;
break;
case V_662 :
break;
case V_663 :
break;
case V_664 :
break;
case V_665 :
break;
case V_666 :
V_26 = V_2 -> V_507 . V_667 ;
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
case V_673 :
break;
case V_674 :
break;
default:
break;
}
return V_26 ;
}
static int F_322 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_147 ,
int (* F_177)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_375 )
{
V_170 V_675 , V_676 ;
F_11 ( V_2 , 4 , L_275 ) ;
memcpy ( V_106 -> V_110 , V_455 , V_382 ) ;
memcpy ( F_252 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
V_675 = ( V_677 ) V_382 + V_147 ;
V_676 = ( V_677 ) V_147 ;
memcpy ( F_323 ( V_106 -> V_110 ) , & V_675 , 2 ) ;
memcpy ( F_324 ( V_106 -> V_110 ) , & V_676 , 2 ) ;
memcpy ( F_325 ( V_106 -> V_110 ) , & V_676 , 2 ) ;
memcpy ( F_326 ( V_106 -> V_110 ) , & V_676 , 2 ) ;
return F_176 ( V_2 , V_382 + V_147 , V_106 ,
F_177 , V_375 ) ;
}
static int F_327 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_678 )
{
struct V_122 * V_123 ;
struct V_679 * V_680 ;
struct V_681 * V_682 ;
unsigned char * V_110 ;
V_169 V_571 ;
F_11 ( V_2 , 3 , L_276 ) ;
V_123 = (struct V_122 * ) V_678 ;
V_110 = ( unsigned char * ) ( ( char * ) V_123 - V_118 -> V_168 ) ;
V_680 = (struct V_679 * ) V_118 -> V_378 ;
V_682 = & V_123 -> V_110 . V_457 . V_110 . V_682 ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_277 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
if ( V_123 -> V_110 . V_457 . V_126 . V_132 ) {
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_457 . V_126 . V_132 ;
F_35 ( V_2 , 4 , L_278 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
V_571 = * ( ( V_169 * ) F_324 ( V_110 ) ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 == 1 )
V_571 -= ( V_169 ) ( ( char * ) & V_682 -> V_110 - ( char * ) V_123 ) ;
else
V_571 -= ( V_169 ) ( ( char * ) & V_682 -> V_683 - ( char * ) V_123 ) ;
if ( ( V_680 -> V_684 - V_680 -> V_685 ) < V_571 ) {
F_35 ( V_2 , 4 , L_279 , - V_39 ) ;
V_123 -> V_126 . V_132 = V_686 ;
return 0 ;
}
F_35 ( V_2 , 4 , L_280 ,
V_123 -> V_110 . V_457 . V_126 . V_467 ) ;
F_35 ( V_2 , 4 , L_281 ,
V_123 -> V_110 . V_457 . V_126 . V_468 ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 == 1 ) {
memcpy ( V_680 -> V_687 + V_680 -> V_685 ,
( char * ) V_682 ,
V_571 + F_328 ( struct V_681 , V_110 ) ) ;
V_680 -> V_685 += F_328 ( struct V_681 , V_110 ) ;
} else {
memcpy ( V_680 -> V_687 + V_680 -> V_685 ,
( char * ) & V_682 -> V_683 , V_571 ) ;
}
V_680 -> V_685 += V_571 ;
F_35 ( V_2 , 4 , L_282 ,
V_123 -> V_110 . V_457 . V_126 . V_467 ) ;
F_35 ( V_2 , 4 , L_283 ,
V_123 -> V_110 . V_457 . V_126 . V_468 ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 <
V_123 -> V_110 . V_457 . V_126 . V_467 )
return 1 ;
return 0 ;
}
int F_329 ( struct V_1 * V_2 , char T_4 * V_687 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_688 * V_689 ;
int V_690 ;
struct V_679 V_680 = { 0 , } ;
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_284 ) ;
if ( V_2 -> V_3 . V_4 )
return - V_334 ;
if ( ( ! F_319 ( V_2 , V_691 ) ) &&
( ! V_2 -> V_49 . V_301 ) ) {
return - V_334 ;
}
if ( F_330 ( & V_690 , V_687 + sizeof( int ) , sizeof( int ) ) )
return - V_692 ;
V_689 = F_331 ( V_687 , V_690 + sizeof( struct V_693 ) ) ;
if ( F_98 ( V_689 ) ) {
F_11 ( V_2 , 2 , L_285 ) ;
return F_99 ( V_689 ) ;
}
V_680 . V_684 = V_689 -> V_126 . V_571 ;
V_680 . V_687 = F_15 ( V_680 . V_684 , V_38 ) ;
if ( ! V_680 . V_687 ) {
F_20 ( V_689 ) ;
return - V_39 ;
}
V_680 . V_685 = sizeof( struct V_693 ) ;
V_106 = F_257 ( V_2 , V_691 ,
V_694 + V_690 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
memcpy ( & V_123 -> V_110 . V_457 . V_110 . V_682 , & V_689 -> V_123 , V_690 ) ;
V_26 = F_322 ( V_2 , V_106 , V_695 + V_690 ,
F_327 , ( void * ) & V_680 ) ;
if ( V_26 )
F_51 ( 2 , L_286 ,
F_64 ( V_2 ) , V_26 ) ;
else {
if ( F_332 ( V_687 , V_680 . V_687 , V_680 . V_684 ) )
V_26 = - V_692 ;
}
F_20 ( V_689 ) ;
F_20 ( V_680 . V_687 ) ;
return V_26 ;
}
static int F_333 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_696 * V_697 ;
char * V_698 ;
int V_699 ;
F_11 ( V_2 , 3 , L_287 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_697 = (struct V_696 * ) V_118 -> V_378 ;
V_699 = V_123 -> V_110 . V_457 . V_126 . V_465 ;
V_698 = ( char * ) V_110 + 28 ;
if ( V_699 > ( V_697 -> V_700 - V_697 -> V_701 ) ) {
V_123 -> V_126 . V_132 = V_702 ;
return 0 ;
}
memcpy ( ( V_697 -> V_66 + V_697 -> V_701 ) , V_698 ,
V_699 ) ;
V_697 -> V_701 += V_699 ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 <
V_123 -> V_110 . V_457 . V_126 . V_467 )
return 1 ;
return 0 ;
}
int F_334 ( struct V_1 * V_2 , char T_4 * V_687 )
{
int V_26 = 0 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_703 * V_704 ;
struct V_705 V_706 ;
struct V_696 V_697 ;
void T_4 * V_30 ;
F_11 ( V_2 , 3 , L_288 ) ;
if ( ! F_319 ( V_2 , V_707 ) ) {
V_26 = - V_334 ;
goto V_60;
}
if ( F_330 ( & V_706 , V_687 ,
sizeof( struct V_705 ) ) ) {
V_26 = - V_692 ;
goto V_60;
}
V_697 . V_700 = V_706 . V_700 ;
V_697 . V_701 = 0 ;
V_697 . V_66 = F_15 ( V_706 . V_700 , V_38 ) ;
if ( ! V_697 . V_66 ) {
V_26 = - V_39 ;
goto V_60;
}
V_106 = F_257 ( V_2 , V_707 ,
sizeof( struct V_635 ) +
sizeof( struct V_703 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_704 = & V_123 -> V_110 . V_457 . V_110 . V_708 ;
V_704 -> V_629 = V_706 . V_127 ;
V_26 = F_253 ( V_2 , V_106 , F_333 ,
& V_697 ) ;
if ( ! V_26 ) {
if ( F_335 () )
V_30 = F_336 ( V_706 . V_32 ) ;
else
V_30 = ( void T_4 * ) ( unsigned long ) V_706 . V_32 ;
if ( F_332 ( V_30 , V_697 . V_66 ,
V_697 . V_701 ) ) {
V_26 = - V_692 ;
goto V_709;
}
V_706 . V_701 = V_697 . V_701 ;
if ( F_332 ( V_687 , & V_706 ,
sizeof( struct V_705 ) ) )
V_26 = - V_692 ;
} else
if ( V_26 == V_702 )
V_26 = - V_692 ;
V_709:
F_20 ( V_697 . V_66 ) ;
V_60:
return V_26 ;
}
static inline int F_337 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
return 2 ;
default:
return 0 ;
}
}
static void F_338 ( struct V_1 * V_2 )
{
int V_26 ;
int V_239 ;
char * V_340 ;
struct V_178 * V_710 ;
int V_711 = 0 ;
F_24 ( V_52 , 2 , L_289 ) ;
V_710 = F_26 ( V_2 ) ;
if ( ! V_710 -> V_712 ) {
V_711 = 1 ;
V_26 = F_339 ( V_710 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_60;
}
}
V_26 = F_150 ( V_2 , ( void * * ) & V_340 , & V_239 ) ;
if ( V_26 ) {
F_51 ( 2 , L_290 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_713;
}
F_153 ( V_2 , V_340 ) ;
if ( V_711 )
F_154 ( V_2 , V_340 ) ;
F_20 ( V_340 ) ;
V_26 = F_340 ( V_710 , & V_2 -> V_714 ) ;
if ( V_26 )
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_27 ( V_52 , 2 , L_291 , V_2 -> V_714 . V_715 ) ;
F_27 ( V_52 , 2 , L_292 , V_2 -> V_714 . V_716 ) ;
F_27 ( V_52 , 2 , L_292 , V_2 -> V_714 . V_717 ) ;
F_27 ( V_52 , 2 , L_293 , V_2 -> V_714 . V_718 ) ;
if ( ! ( ( V_2 -> V_714 . V_715 != V_719 ) ||
( ( V_2 -> V_714 . V_716 & V_720 ) == 0 ) ||
( ( V_2 -> V_714 . V_717 & V_721 ) == 0 ) ) ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_294 ) ;
} else {
V_2 -> V_49 . V_50 = V_545 ;
}
V_713:
if ( V_711 == 1 )
F_341 ( V_710 ) ;
V_60:
return;
}
static inline void F_342 ( struct V_1 * V_2 ,
struct V_56 * * V_722 ,
void (* * F_343) ( struct V_178 * , int , unsigned long ) ) {
int V_33 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
int V_168 = V_55 *
( V_2 -> V_35 . V_59 - 1 ) ;
V_33 = V_55 * ( V_2 -> V_35 . V_59 - 1 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_722 [ V_168 + V_33 ] = (struct V_56 * )
F_291 ( V_2 -> V_35 . V_53 -> V_65 [ V_33 ] . V_66 ) ;
}
F_343 [ V_2 -> V_35 . V_59 - 1 ] = NULL ;
}
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_723 V_724 ;
char * V_725 ;
struct V_56 * * V_722 ;
void (* * F_343) ( struct V_178 * , int , unsigned long );
struct V_56 * * V_726 ;
int V_33 , V_34 , V_727 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_295 ) ;
V_725 = F_15 ( V_55 * sizeof( char ) ,
V_38 ) ;
if ( ! V_725 ) {
V_26 = - V_39 ;
goto V_728;
}
F_218 ( V_2 , V_725 ) ;
F_222 ( V_2 , V_725 ) ;
V_722 = F_15 ( V_2 -> V_35 . V_59 *
V_55 * sizeof( void * ) ,
V_38 ) ;
if ( ! V_722 ) {
V_26 = - V_39 ;
goto V_729;
}
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_722 [ V_33 ] = (struct V_56 * )
F_291 ( V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_66 ) ;
}
F_343 = F_15 ( sizeof( void * ) * V_2 -> V_35 . V_59 ,
V_38 ) ;
if ( ! F_343 ) {
V_26 = - V_39 ;
goto V_730;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_59 ; ++ V_33 )
F_343 [ V_33 ] = V_2 -> V_276 -> V_731 ;
F_342 ( V_2 , V_722 , F_343 ) ;
V_726 =
F_15 ( V_2 -> V_35 . V_68 * V_55 *
sizeof( void * ) , V_38 ) ;
if ( ! V_726 ) {
V_26 = - V_39 ;
goto V_732;
}
for ( V_33 = 0 , V_727 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 )
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 , ++ V_727 ) {
V_726 [ V_727 ] = (struct V_56 * ) F_291 (
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] -> V_66 ) ;
}
memset ( & V_724 , 0 , sizeof( struct V_723 ) ) ;
V_724 . V_179 = F_26 ( V_2 ) ;
V_724 . V_733 = F_337 ( V_2 ) ;
V_724 . V_734 = 0 ;
V_724 . V_725 = V_725 ;
V_724 . V_735 = V_2 -> V_35 . V_59 ;
V_724 . V_736 = V_2 -> V_35 . V_68 ;
V_724 . V_737 = V_2 -> V_276 -> V_737 ;
V_724 . V_738 = V_2 -> V_276 -> V_738 ;
V_724 . V_739 = F_343 ;
V_724 . V_740 = ( unsigned long ) V_2 ;
V_724 . V_741 = ( void * * ) V_722 ;
V_724 . V_742 = ( void * * ) V_726 ;
V_724 . V_743 = V_2 -> V_35 . V_67 ;
V_724 . V_744 =
( V_2 -> V_3 . type == V_6 ) ? 8 : 32 ;
if ( F_42 ( & V_2 -> V_35 . V_44 , V_329 ,
V_325 ) == V_329 ) {
V_26 = F_344 ( & V_724 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
goto V_60;
}
V_26 = F_345 ( & V_724 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
F_149 ( F_26 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_49 . V_50 ) {
case V_51 :
F_72 ( & V_2 -> V_72 -> V_73 , L_296 ) ;
break;
case V_271 :
F_72 ( & V_2 -> V_72 -> V_73 , L_297 ) ;
break;
default:
break;
}
V_60:
F_20 ( V_726 ) ;
V_732:
F_20 ( F_343 ) ;
V_730:
F_20 ( V_722 ) ;
V_729:
F_20 ( V_725 ) ;
V_728:
return V_26 ;
}
static void F_346 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_298 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
F_115 ( & V_2 -> V_107 ) ;
F_115 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_73 )
F_347 ( V_2 -> V_73 ) ;
F_20 ( V_2 -> V_284 ) ;
F_112 ( V_2 ) ;
F_348 ( & V_2 -> V_295 ) ;
F_20 ( V_2 ) ;
}
void F_349 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 2 , L_299 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_473 . V_461 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_473 . V_476 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_475 . V_461 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_475 . V_476 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_460 . V_461 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_49 . V_460 . V_476 ) ;
F_35 ( V_2 , 2 , L_300 , V_2 -> V_3 . V_479 ) ;
}
int F_350 ( struct V_1 * V_2 )
{
int V_745 = 0 ;
int V_26 ;
F_24 ( V_52 , 2 , L_301 ) ;
F_43 ( & V_2 -> V_512 , 0 ) ;
F_118 ( V_2 ) ;
V_746:
if ( V_745 )
F_51 ( 2 , L_302 ,
F_52 ( & V_2 -> V_72 -> V_73 ) ) ;
F_341 ( F_26 ( V_2 ) ) ;
F_341 ( F_351 ( V_2 ) ) ;
F_341 ( F_137 ( V_2 ) ) ;
V_26 = F_339 ( F_137 ( V_2 ) ) ;
if ( V_26 )
goto V_747;
V_26 = F_339 ( F_351 ( V_2 ) ) ;
if ( V_26 )
goto V_747;
V_26 = F_339 ( F_26 ( V_2 ) ) ;
if ( V_26 )
goto V_747;
V_26 = F_147 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
V_747:
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_303 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
if ( ++ V_745 > 3 )
goto V_60;
else
goto V_746;
}
F_338 ( V_2 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
V_26 = F_159 ( & V_2 -> V_107 , F_171 ) ;
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_304 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
if ( -- V_745 < 0 )
goto V_60;
else
goto V_746;
}
V_26 = F_159 ( & V_2 -> V_142 , F_168 ) ;
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_305 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
if ( -- V_745 < 0 )
goto V_60;
else
goto V_746;
}
V_2 -> V_116 = 0 ;
V_26 = F_228 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_60;
}
V_2 -> V_49 . V_473 . V_461 = 0 ;
V_2 -> V_49 . V_460 . V_461 = 0 ;
V_2 -> V_3 . V_479 = 0 ;
F_260 ( V_2 , V_385 ) ;
if ( F_312 ( V_2 , V_474 ) )
F_258 ( V_2 ) ;
if ( F_319 ( V_2 , V_748 ) )
F_262 ( V_2 ) ;
return 0 ;
V_60:
F_50 ( & V_2 -> V_72 -> V_73 , L_101
L_102 ) ;
F_51 ( 2 , L_306 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
return V_26 ;
}
static inline int F_352 ( struct V_434 * V_749 ,
struct V_750 * V_231 ,
struct V_218 * * V_751 , int V_168 , int * V_752 , int V_571 )
{
struct V_430 * V_430 = F_241 ( V_231 -> V_236 ) ;
if ( * V_751 == NULL ) {
if ( V_749 -> V_245 ) {
* V_751 = V_749 -> V_245 ;
V_749 -> V_245 = NULL ;
} else {
* V_751 = F_245 ( V_435 + V_436 ) ;
if ( ! ( * V_751 ) )
return - V_39 ;
}
F_353 ( * V_751 , V_436 ) ;
if ( V_571 <= V_435 ) {
memcpy ( F_354 ( * V_751 , V_571 ) , V_231 -> V_236 + V_168 ,
V_571 ) ;
} else {
F_355 ( V_430 ) ;
memcpy ( F_354 ( * V_751 , V_435 ) ,
V_231 -> V_236 + V_168 , V_435 ) ;
F_356 ( * V_751 , * V_752 , V_430 ,
V_168 + V_435 ,
V_571 - V_435 ) ;
( * V_751 ) -> V_571 += V_571 - V_435 ;
( * V_751 ) -> V_147 += V_571 - V_435 ;
( * V_751 ) -> V_753 += V_571 - V_435 ;
( * V_752 ) ++ ;
}
} else {
F_355 ( V_430 ) ;
F_356 ( * V_751 , * V_752 , V_430 , V_168 , V_571 ) ;
( * V_751 ) -> V_571 += V_571 ;
( * V_751 ) -> V_147 += V_571 ;
( * V_751 ) -> V_753 += V_571 ;
( * V_752 ) ++ ;
}
return 0 ;
}
struct V_218 * F_357 ( struct V_1 * V_2 ,
struct V_434 * V_749 ,
struct V_750 * * V_754 , int * V_755 ,
struct V_589 * * V_126 )
{
struct V_750 * V_231 = * V_754 ;
struct V_56 * V_66 = V_749 -> V_66 ;
int V_168 = * V_755 ;
struct V_218 * V_219 = NULL ;
int V_756 = 0 ;
void * V_757 ;
int V_571 ;
int V_758 = 0 ;
int V_759 = 0 ;
int V_582 = 0 ;
if ( V_231 -> V_239 < V_168 + sizeof( struct V_589 ) ) {
if ( F_358 ( V_231 ) )
return NULL ;
V_231 ++ ;
V_168 = 0 ;
if ( V_231 -> V_239 < sizeof( struct V_589 ) )
return NULL ;
}
* V_126 = V_231 -> V_236 + V_168 ;
V_168 += sizeof( struct V_589 ) ;
switch ( ( * V_126 ) -> V_126 . V_760 . V_308 ) {
case V_761 :
V_756 = ( * V_126 ) -> V_126 . V_760 . V_762 ;
break;
case V_763 :
V_756 = ( * V_126 ) -> V_126 . V_593 . V_239 ;
V_758 = V_436 ;
break;
case V_764 :
V_756 = ( * V_126 ) -> V_126 . V_765 . V_766 ;
V_758 = sizeof( struct V_589 ) ;
break;
default:
break;
}
if ( ! V_756 )
return NULL ;
if ( ( ( V_756 >= V_2 -> V_49 . V_267 ) &&
( ! ( V_2 -> V_3 . type == V_9 ) ) &&
( ! F_34 ( & V_2 -> V_512 ) ) ) ||
( V_2 -> V_49 . V_50 == V_51 ) ) {
V_759 = 1 ;
} else {
V_219 = F_245 ( V_756 + V_758 ) ;
if ( ! V_219 )
goto V_767;
if ( V_758 )
F_353 ( V_219 , V_758 ) ;
}
V_757 = V_231 -> V_236 + V_168 ;
while ( V_756 ) {
V_571 = F_359 ( V_756 , ( int ) ( V_231 -> V_239 - V_168 ) ) ;
if ( V_571 ) {
if ( V_759 ) {
if ( F_352 ( V_749 , V_231 ,
& V_219 , V_168 , & V_582 , V_571 ) )
goto V_767;
} else {
memcpy ( F_354 ( V_219 , V_571 ) , V_757 ,
V_571 ) ;
}
}
V_756 -= V_571 ;
if ( V_756 ) {
if ( F_358 ( V_231 ) ) {
F_11 ( V_2 , 4 , L_307 ) ;
F_360 ( V_2 , 2 , V_66 , sizeof( void * ) ) ;
F_109 ( V_219 ) ;
V_2 -> V_507 . V_667 ++ ;
return NULL ;
}
V_231 ++ ;
V_168 = 0 ;
V_757 = V_231 -> V_236 ;
} else {
V_168 += V_571 ;
}
}
* V_754 = V_231 ;
* V_755 = V_168 ;
if ( V_759 && V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_768 ++ ;
V_2 -> V_432 . V_769 += F_298 ( V_219 ) -> V_573 ;
}
return V_219 ;
V_767:
if ( F_361 () ) {
F_11 ( V_2 , 2 , L_308 ) ;
}
V_2 -> V_507 . V_508 ++ ;
return NULL ;
}
static void F_362 ( void )
{
int V_770 ;
for ( V_770 = 0 ; V_770 < V_771 ; V_770 ++ ) {
F_363 ( V_772 [ V_770 ] . V_308 ) ;
V_772 [ V_770 ] . V_308 = NULL ;
}
}
void F_364 ( T_5 * V_308 , int V_367 , char * V_773 , ... )
{
char V_774 [ 32 ] ;
T_6 args ;
if ( V_367 > V_308 -> V_367 )
return;
va_start ( args , V_773 ) ;
vsnprintf ( V_774 , sizeof( V_774 ) , V_773 , args ) ;
va_end ( args ) ;
F_365 ( V_308 , V_367 , V_774 ) ;
}
static int F_366 ( void )
{
int V_332 ;
int V_770 ;
for ( V_770 = 0 ; V_770 < V_771 ; V_770 ++ ) {
V_772 [ V_770 ] . V_308 = F_367 ( V_772 [ V_770 ] . V_496 ,
V_772 [ V_770 ] . V_775 ,
V_772 [ V_770 ] . V_776 ,
V_772 [ V_770 ] . V_147 ) ;
if ( V_772 [ V_770 ] . V_308 == NULL ) {
F_362 () ;
return - V_39 ;
}
V_332 = F_368 ( V_772 [ V_770 ] . V_308 , V_772 [ V_770 ] . V_777 ) ;
if ( V_332 ) {
F_362 () ;
return V_332 ;
}
F_369 ( V_772 [ V_770 ] . V_308 , V_772 [ V_770 ] . V_367 ) ;
}
return 0 ;
}
int F_370 ( struct V_1 * V_2 ,
enum V_778 V_276 )
{
int V_26 = 0 ;
F_371 ( & V_779 ) ;
switch ( V_276 ) {
case V_780 :
V_2 -> V_276 = F_372 (
F_373 ( V_781 ) , L_309 ) ;
break;
case V_782 :
V_2 -> V_276 = F_372 (
F_373 ( V_783 ) , L_310 ) ;
break;
}
if ( ! V_2 -> V_276 ) {
F_30 ( & V_2 -> V_72 -> V_73 , L_311
L_312 , V_276 ) ;
V_26 = - V_397 ;
}
F_374 ( & V_779 ) ;
return V_26 ;
}
void F_375 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 . V_301 )
F_376 ( V_783 ) ;
else
F_376 ( V_781 ) ;
V_2 -> V_276 = NULL ;
}
static int F_377 ( struct V_784 * V_72 )
{
struct V_1 * V_2 ;
struct V_785 * V_73 ;
int V_26 ;
unsigned long V_21 ;
char V_786 [ 20 ] ;
F_24 ( V_52 , 2 , L_313 ) ;
V_73 = & V_72 -> V_73 ;
if ( ! F_378 ( V_73 ) )
return - V_787 ;
F_27 ( V_52 , 2 , L_186 , F_52 ( & V_72 -> V_73 ) ) ;
V_2 = F_134 () ;
if ( ! V_2 ) {
F_27 ( V_52 , 2 , L_35 , - V_39 ) ;
V_26 = - V_39 ;
goto V_788;
}
snprintf ( V_786 , sizeof( V_786 ) , L_314 ,
F_52 ( & V_72 -> V_73 ) ) ;
V_2 -> V_789 = F_367 ( V_786 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_789 ) {
F_27 ( V_52 , 2 , L_186 , L_315 ) ;
V_26 = - V_39 ;
goto V_790;
}
F_368 ( V_2 -> V_789 , & V_791 ) ;
V_2 -> V_107 . V_112 = V_72 -> V_179 [ 0 ] ;
V_2 -> V_142 . V_112 = V_72 -> V_179 [ 1 ] ;
V_2 -> V_110 . V_112 = V_72 -> V_179 [ 2 ] ;
F_379 ( & V_72 -> V_73 , V_2 ) ;
V_2 -> V_72 = V_72 ;
V_72 -> V_179 [ 0 ] -> V_792 = F_100 ;
V_72 -> V_179 [ 1 ] -> V_792 = F_100 ;
V_72 -> V_179 [ 2 ] -> V_792 = F_100 ;
V_26 = F_136 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_793;
}
V_26 = F_127 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
goto V_793;
}
if ( V_2 -> V_3 . type == V_9 )
V_72 -> V_73 . type = & V_794 ;
else
V_72 -> V_73 . type = & V_795 ;
switch ( V_2 -> V_3 . type ) {
case V_9 :
case V_7 :
V_26 = F_370 ( V_2 , V_782 ) ;
if ( V_26 )
goto V_793;
V_26 = V_2 -> V_276 -> V_796 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_797;
case V_5 :
case V_8 :
default:
break;
}
F_380 ( & V_798 . V_799 , V_21 ) ;
F_84 ( & V_2 -> V_31 , & V_798 . V_31 ) ;
F_381 ( & V_798 . V_799 , V_21 ) ;
F_338 ( V_2 ) ;
return 0 ;
V_797:
F_375 ( V_2 ) ;
V_793:
F_363 ( V_2 -> V_789 ) ;
V_790:
F_346 ( V_2 ) ;
V_788:
F_382 ( V_73 ) ;
return V_26 ;
}
static void F_383 ( struct V_784 * V_72 )
{
unsigned long V_21 ;
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
F_24 ( V_52 , 2 , L_316 ) ;
if ( V_2 -> V_276 ) {
V_2 -> V_276 -> remove ( V_72 ) ;
F_375 ( V_2 ) ;
}
F_363 ( V_2 -> V_789 ) ;
F_380 ( & V_798 . V_799 , V_21 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_381 ( & V_798 . V_799 , V_21 ) ;
F_346 ( V_2 ) ;
F_379 ( & V_72 -> V_73 , NULL ) ;
F_382 ( & V_72 -> V_73 ) ;
return;
}
static int F_385 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
int V_26 = 0 ;
int V_800 ;
if ( ! V_2 -> V_276 ) {
if ( V_2 -> V_3 . type == V_6 )
V_800 = V_780 ;
else
V_800 = V_782 ;
V_26 = F_370 ( V_2 , V_800 ) ;
if ( V_26 )
goto V_801;
V_26 = V_2 -> V_276 -> V_796 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_801;
}
V_26 = V_2 -> V_276 -> V_802 ( V_72 ) ;
V_801:
return V_26 ;
}
static int F_386 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
return V_2 -> V_276 -> V_803 ( V_72 ) ;
}
static void F_387 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_804 )
V_2 -> V_276 -> V_804 ( V_72 ) ;
}
static int F_388 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_805 )
return V_2 -> V_276 -> V_805 ( V_72 ) ;
return 0 ;
}
static void F_389 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_806 )
V_2 -> V_276 -> V_806 ( V_72 ) ;
}
static int F_390 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_807 )
return V_2 -> V_276 -> V_807 ( V_72 ) ;
return 0 ;
}
static int F_391 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_808 )
return V_2 -> V_276 -> V_808 ( V_72 ) ;
return 0 ;
}
static int F_392 ( struct V_784 * V_72 )
{
struct V_1 * V_2 = F_384 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_809 )
return V_2 -> V_276 -> V_809 ( V_72 ) ;
return 0 ;
}
static T_7 F_393 ( struct V_810 * V_811 ,
const char * V_217 , T_8 V_151 )
{
int V_801 ;
V_801 = F_394 ( V_812 ,
& V_813 , 3 , V_217 ) ;
return V_801 ? V_801 : V_151 ;
}
int F_395 ( struct V_606 * V_73 , int V_814 )
{
switch ( V_814 ) {
case V_815 :
return ( sizeof( V_816 ) / V_817 ) ;
default:
return - V_397 ;
}
}
void F_396 ( struct V_606 * V_73 ,
struct V_818 * V_507 , T_9 * V_110 )
{
struct V_1 * V_2 = V_73 -> V_611 ;
V_110 [ 0 ] = V_2 -> V_507 . V_819 -
V_2 -> V_432 . V_820 ;
V_110 [ 1 ] = V_2 -> V_432 . V_821 ;
V_110 [ 2 ] = V_2 -> V_507 . V_822 -
V_2 -> V_432 . V_823 ;
V_110 [ 3 ] = V_2 -> V_432 . V_536 ;
V_110 [ 4 ] = V_2 -> V_507 . V_822 - V_2 -> V_432 . V_823
- V_2 -> V_432 . V_597 ;
V_110 [ 5 ] = V_2 -> V_432 . V_536 - V_2 -> V_432 . V_540 ;
V_110 [ 6 ] = V_2 -> V_432 . V_597 ;
V_110 [ 7 ] = V_2 -> V_432 . V_540 ;
V_110 [ 8 ] = V_2 -> V_432 . V_824 ;
V_110 [ 9 ] = V_2 -> V_432 . V_825 ;
V_110 [ 10 ] = V_2 -> V_432 . V_768 ;
V_110 [ 11 ] = V_2 -> V_432 . V_769 ;
V_110 [ 12 ] = V_2 -> V_432 . V_433 ;
V_110 [ 13 ] = ( V_2 -> V_432 . V_826 >> 10 ) ;
V_110 [ 14 ] = V_2 -> V_432 . V_827 ;
V_110 [ 15 ] = V_2 -> V_432 . V_522 ;
V_110 [ 16 ] = V_2 -> V_432 . V_525 ;
V_110 [ 17 ] = V_524 ;
V_110 [ 18 ] = V_521 ;
V_110 [ 19 ] = F_34 ( & V_2 -> V_35 . V_70 [ 0 ] -> V_440 ) ;
V_110 [ 20 ] = ( V_2 -> V_35 . V_68 > 1 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 1 ] -> V_440 ) : 0 ;
V_110 [ 21 ] = ( V_2 -> V_35 . V_68 > 2 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 2 ] -> V_440 ) : 0 ;
V_110 [ 22 ] = ( V_2 -> V_35 . V_68 > 3 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 3 ] -> V_440 ) : 0 ;
V_110 [ 23 ] = V_2 -> V_432 . V_828 ;
V_110 [ 24 ] = V_2 -> V_432 . V_829 ;
V_110 [ 25 ] = V_2 -> V_432 . V_516 ;
V_110 [ 26 ] = V_2 -> V_432 . V_514 ;
V_110 [ 27 ] = V_2 -> V_432 . V_559 ;
V_110 [ 28 ] = V_2 -> V_432 . V_555 ;
V_110 [ 29 ] = V_2 -> V_432 . V_830 ;
V_110 [ 30 ] = V_2 -> V_432 . V_831 ;
V_110 [ 31 ] = V_2 -> V_432 . V_533 ;
V_110 [ 32 ] = V_2 -> V_432 . V_529 ;
V_110 [ 33 ] = V_2 -> V_432 . V_832 ;
V_110 [ 34 ] = V_2 -> V_432 . V_833 ;
V_110 [ 35 ] = V_2 -> V_432 . V_547 ;
V_110 [ 36 ] = V_2 -> V_432 . V_551 ;
}
void F_397 ( struct V_606 * V_73 , V_677 V_814 , T_3 * V_110 )
{
switch ( V_814 ) {
case V_815 :
memcpy ( V_110 , & V_816 ,
sizeof( V_816 ) ) ;
break;
default:
F_58 ( 1 ) ;
break;
}
}
void F_398 ( struct V_606 * V_73 ,
struct V_834 * V_3 )
{
struct V_1 * V_2 = V_73 -> V_611 ;
if ( V_2 -> V_49 . V_301 )
strcpy ( V_3 -> V_835 , L_310 ) ;
else
strcpy ( V_3 -> V_835 , L_309 ) ;
strcpy ( V_3 -> V_836 , L_317 ) ;
strcpy ( V_3 -> V_837 , V_2 -> V_3 . V_296 ) ;
sprintf ( V_3 -> V_838 , L_318 ,
F_399 ( V_2 ) ,
F_400 ( V_2 ) ,
F_401 ( V_2 ) ) ;
}
int F_402 ( struct V_606 * V_839 ,
struct V_840 * V_841 )
{
struct V_1 * V_2 = V_839 -> V_611 ;
enum V_442 V_10 ;
if ( ( V_2 -> V_3 . type == V_6 ) || ( V_2 -> V_3 . V_4 ) )
V_10 = V_14 ;
else
V_10 = V_2 -> V_3 . V_10 ;
V_841 -> V_842 = V_843 ;
V_841 -> V_844 = V_845 ;
V_841 -> V_846 = V_847 ;
V_841 -> V_848 = V_849 ;
V_841 -> V_850 = V_851 ;
switch ( V_10 ) {
case V_11 :
case V_15 :
V_841 -> V_844 |= V_852 |
V_853 |
V_854 |
V_855 |
V_856 ;
V_841 -> V_846 |= V_857 |
V_858 |
V_859 |
V_860 |
V_861 ;
V_841 -> V_862 = V_863 ;
V_841 -> V_864 = V_865 ;
break;
case V_13 :
case V_17 :
V_841 -> V_844 |= V_852 |
V_853 |
V_854 |
V_855 |
V_866 |
V_867 |
V_868 ;
V_841 -> V_846 |= V_857 |
V_858 |
V_859 |
V_860 |
V_869 |
V_870 |
V_871 ;
V_841 -> V_862 = V_872 ;
V_841 -> V_864 = V_873 ;
break;
case V_14 :
V_841 -> V_844 |= V_852 |
V_853 |
V_854 |
V_855 |
V_866 |
V_867 |
V_874 |
V_868 ;
V_841 -> V_846 |= V_857 |
V_858 |
V_859 |
V_860 |
V_869 |
V_870 |
V_875 |
V_871 ;
V_841 -> V_862 = V_876 ;
V_841 -> V_864 = V_873 ;
break;
default:
V_841 -> V_844 |= V_852 |
V_853 |
V_856 ;
V_841 -> V_846 |= V_857 |
V_858 |
V_861 ;
V_841 -> V_862 = V_877 ;
V_841 -> V_864 = V_865 ;
}
return 0 ;
}
static int T_10 F_403 ( void )
{
int V_26 ;
F_404 ( L_319 ) ;
F_121 ( & V_798 . V_31 ) ;
F_405 ( & V_798 . V_799 ) ;
F_128 ( & V_779 ) ;
V_26 = F_366 () ;
if ( V_26 )
goto V_878;
V_812 = F_406 ( L_320 ) ;
V_26 = F_98 ( V_812 ) ? F_99 ( V_812 ) : 0 ;
if ( V_26 )
goto V_879;
V_238 = F_407 ( L_321 ,
sizeof( struct V_589 ) + V_436 , 64 , 0 , NULL ) ;
if ( ! V_238 ) {
V_26 = - V_39 ;
goto V_880;
}
V_94 = F_407 ( L_322 ,
sizeof( struct V_89 ) , 0 , 0 , NULL ) ;
if ( ! V_94 ) {
V_26 = - V_39 ;
goto V_881;
}
V_26 = F_408 ( & V_882 ) ;
if ( V_26 )
goto V_883;
V_813 . V_835 . V_884 = V_885 ;
V_26 = F_409 ( & V_813 ) ;
if ( V_26 )
goto V_886;
return 0 ;
V_886:
F_410 ( & V_882 ) ;
V_883:
F_411 ( V_94 ) ;
V_881:
F_411 ( V_238 ) ;
V_880:
F_412 ( V_812 ) ;
V_879:
F_362 () ;
V_878:
F_413 ( L_323 ) ;
return V_26 ;
}
static void T_11 F_414 ( void )
{
F_415 ( & V_813 ) ;
F_410 ( & V_882 ) ;
F_411 ( V_94 ) ;
F_411 ( V_238 ) ;
F_412 ( V_812 ) ;
F_362 () ;
F_404 ( L_324 ) ;
}
