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
F_37 ( V_66 == NULL ) ;
if ( F_42 ( & V_66 -> V_44 , V_100 ,
V_101 ) == V_100 ) {
V_98 = V_79 ;
} else {
F_37 ( F_34 ( & V_66 -> V_44 ) != V_102 ) ;
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
} ;
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
struct V_178 * V_112 ;
struct V_246 {
T_3 V_21 ;
T_3 V_247 ;
T_3 V_248 ;
T_3 V_134 ;
T_3 V_249 ;
T_3 V_250 ;
T_3 V_251 ;
T_3 V_252 ;
} * V_253 ;
F_24 ( V_52 , 2 , L_110 ) ;
V_112 = V_2 -> V_110 . V_112 ;
V_253 = (struct V_246 * ) F_117 ( V_112 , 0 ) ;
if ( V_253 != NULL ) {
if ( V_2 -> V_3 . type != V_6 ) {
if ( ( V_253 -> V_252 & 0x02 ) == 0x02 ) {
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) !=
V_242 ) &&
( V_2 -> V_35 . V_68 == 4 ) )
F_112 ( V_2 ) ;
V_2 -> V_35 . V_68 = 1 ;
if ( V_2 -> V_35 . V_254 != 0 )
F_72 ( & V_2 -> V_72 -> V_73 ,
L_111 ) ;
V_2 -> V_35 . V_254 = 0 ;
} else {
if ( ( F_34 ( & V_2 -> V_35 . V_44 ) !=
V_242 ) &&
( V_2 -> V_35 . V_68 == 1 ) ) {
F_112 ( V_2 ) ;
V_2 -> V_35 . V_254 = 2 ;
}
V_2 -> V_35 . V_68 = 4 ;
}
}
V_2 -> V_3 . V_255 = 0x4100 + V_253 -> V_248 ;
F_20 ( V_253 ) ;
}
F_27 ( V_52 , 2 , L_112 , V_2 -> V_35 . V_68 ) ;
F_27 ( V_52 , 2 , L_113 , V_2 -> V_3 . V_255 ) ;
return;
}
static void F_118 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 4 , L_114 ) ;
F_43 ( & V_2 -> V_35 . V_44 , V_242 ) ;
V_2 -> V_35 . V_256 = V_257 ;
if ( V_2 -> V_3 . type == V_6 )
V_2 -> V_35 . V_36 . V_37 = V_258 ;
else
V_2 -> V_35 . V_36 . V_37 = V_259 ;
V_2 -> V_35 . V_48 . V_37 = V_2 -> V_35 . V_36 . V_37 ;
F_119 ( & V_2 -> V_35 . V_48 . V_42 ) ;
F_119 ( & V_2 -> V_35 . V_36 . V_42 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
V_2 -> V_49 . V_260 . type = V_261 ;
V_2 -> V_49 . V_262 . type = V_261 ;
V_2 -> V_49 . V_263 = V_264 ;
V_2 -> V_49 . V_265 = V_266 ;
V_2 -> V_49 . V_267 = 0 ;
V_2 -> V_49 . V_268 = V_269 ;
V_2 -> V_49 . V_270 = 0 ;
V_2 -> V_49 . V_271 = V_272 ;
V_2 -> V_49 . V_273 = V_274 ;
V_2 -> V_49 . V_50 = V_275 ;
}
static int F_121 ( struct V_1 * V_2 , unsigned long V_175 )
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
static void F_122 ( struct V_276 * V_277 )
{
struct V_278 * V_279 ;
struct V_1 * V_2 = F_123 ( V_277 , struct V_1 ,
V_177 ) ;
F_11 ( V_2 , 2 , L_116 ) ;
if ( V_2 -> V_107 . V_44 != V_108 &&
V_2 -> V_142 . V_44 != V_108 )
return;
if ( F_121 ( V_2 , V_176 ) ) {
V_279 = F_124 ( V_2 -> V_280 . V_281 , ( void * ) V_2 ,
L_117 ) ;
if ( F_98 ( V_279 ) ) {
F_90 ( V_2 , V_176 ) ;
F_91 ( V_2 ,
V_176 ) ;
}
}
}
static int F_125 ( struct V_1 * V_2 )
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
F_87 ( & V_2 -> V_282 ) ;
F_87 ( & V_2 -> V_283 ) ;
F_87 ( & V_2 -> V_141 ) ;
F_87 ( & V_2 -> V_284 ) ;
F_87 ( & V_2 -> V_22 ) ;
F_126 ( & V_2 -> V_285 ) ;
F_126 ( & V_2 -> V_286 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_27 = 0 ;
F_127 ( & V_2 -> V_177 , F_122 ) ;
F_119 ( & V_2 -> V_287 ) ;
F_119 ( V_2 -> V_288 ) ;
F_119 ( & V_2 -> V_171 ) ;
F_88 ( & V_2 -> V_25 ) ;
F_120 ( V_2 ) ;
F_119 ( & V_2 -> V_289 . V_290 ) ;
V_2 -> V_289 . V_291 = 0 ;
V_2 -> V_289 . V_292 = 0 ;
V_2 -> V_289 . V_293 = 0 ;
F_118 ( V_2 ) ;
F_128 ( & V_2 -> V_243 , V_294 ) ;
return 0 ;
}
static void F_129 ( struct V_295 * V_296 , struct V_297 * V_298 )
{
struct V_1 * V_2 = F_123 ( V_298 , struct V_1 ,
V_299 ) ;
if ( V_2 -> V_3 . V_300 [ 0 ] )
F_130 ( V_296 , L_119 ,
F_131 ( V_2 ) , V_2 -> V_3 . V_300 ) ;
}
static struct V_1 * F_132 ( void )
{
struct V_1 * V_2 ;
F_24 ( V_52 , 2 , L_120 ) ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_174 | V_38 ) ;
if ( ! V_2 )
goto V_60;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_288 = F_15 ( sizeof( struct V_301 ) , V_38 ) ;
if ( ! V_2 -> V_288 ) {
F_24 ( V_52 , 0 , L_121 ) ;
goto V_302;
}
if ( F_86 ( & V_2 -> V_107 ) )
goto V_303;
if ( F_86 ( & V_2 -> V_142 ) )
goto V_304;
V_2 -> V_49 . V_305 = - 1 ;
V_2 -> V_299 . V_306 = F_129 ;
F_133 ( & V_2 -> V_299 ) ;
return V_2 ;
V_304:
F_115 ( & V_2 -> V_107 ) ;
V_303:
F_20 ( V_2 -> V_288 ) ;
V_302:
F_20 ( V_2 ) ;
V_60:
return NULL ;
}
static int F_134 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
F_24 ( V_52 , 2 , L_122 ) ;
V_2 -> V_35 . V_307 = V_308 ;
V_2 -> V_35 . V_254 = V_309 ;
while ( V_310 [ V_33 ] [ V_311 ] ) {
if ( ( F_135 ( V_2 ) -> V_312 . V_313 ==
V_310 [ V_33 ] [ V_314 ] ) &&
( F_135 ( V_2 ) -> V_312 . V_315 ==
V_310 [ V_33 ] [ V_311 ] ) ) {
V_2 -> V_3 . type = V_310 [ V_33 ] [ V_311 ] ;
V_2 -> V_35 . V_68 =
V_310 [ V_33 ] [ V_316 ] ;
V_2 -> V_35 . V_59 = 1 ;
V_2 -> V_3 . V_317 =
V_310 [ V_33 ] [ V_318 ] ;
F_116 ( V_2 ) ;
return 0 ;
}
V_33 ++ ;
}
V_2 -> V_3 . type = V_319 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_123
L_124 ) ;
return - V_320 ;
}
static int F_136 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_125 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_138 ( V_146 -> V_112 , V_208 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_205 , V_321 ) ;
if ( V_26 == - V_322 )
return V_26 ;
if ( V_146 -> V_44 != V_205 )
return - V_323 ;
V_146 -> V_44 = V_202 ;
return 0 ;
}
static int F_140 ( struct V_145 * V_146 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_11 ( V_2 , 3 , L_126 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_141 ( V_146 -> V_112 , V_209 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_207 , V_321 ) ;
if ( V_26 == - V_322 )
return V_26 ;
if ( V_146 -> V_44 != V_207 )
return - V_323 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
int V_324 = 0 , V_325 = 0 , V_326 = 0 ;
F_11 ( V_2 , 3 , L_127 ) ;
V_324 = F_140 ( & V_2 -> V_107 ) ;
V_325 = F_140 ( & V_2 -> V_142 ) ;
V_326 = F_140 ( & V_2 -> V_110 ) ;
if ( V_324 )
return V_324 ;
if ( V_325 )
return V_325 ;
return V_326 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_324 = 0 , V_325 = 0 , V_326 = 0 ;
F_11 ( V_2 , 3 , L_128 ) ;
V_324 = F_136 ( & V_2 -> V_107 ) ;
V_325 = F_136 ( & V_2 -> V_142 ) ;
V_326 = F_136 ( & V_2 -> V_110 ) ;
if ( V_324 )
return V_324 ;
if ( V_325 )
return V_325 ;
return V_326 ;
}
static int F_144 ( struct V_1 * V_2 , int V_327 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_129 ) ;
if ( V_327 )
V_26 = F_142 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_143 ( V_2 ) ;
}
int F_145 ( struct V_1 * V_2 , int V_328 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_130 ) ;
switch ( F_42 ( & V_2 -> V_35 . V_44 , V_329 ,
V_330 ) ) {
case V_329 :
if ( V_2 -> V_3 . type == V_6 )
V_26 = F_146 ( F_26 ( V_2 ) ,
V_331 ) ;
else
V_26 = F_146 ( F_26 ( V_2 ) ,
V_332 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_35 , V_26 ) ;
F_147 ( F_26 ( V_2 ) ) ;
F_43 ( & V_2 -> V_35 . V_44 , V_333 ) ;
break;
case V_330 :
return V_26 ;
default:
break;
}
V_26 = F_144 ( V_2 , V_328 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_131 , V_26 ) ;
V_2 -> V_44 = V_45 ;
return V_26 ;
}
static int F_148 ( struct V_1 * V_2 , void * * V_66 ,
int * V_239 )
{
struct V_334 * V_334 ;
char * V_335 ;
int V_336 ;
struct V_145 * V_146 = & V_2 -> V_110 ;
unsigned long V_21 ;
V_334 = F_149 ( V_146 -> V_112 , V_337 ) ;
if ( ! V_334 || V_334 -> V_123 == 0 )
return - V_338 ;
V_335 = F_15 ( V_334 -> V_151 , V_38 | V_174 ) ;
if ( ! V_335 )
return - V_39 ;
V_146 -> V_113 . V_339 = V_334 -> V_123 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_335 ) ;
V_146 -> V_113 . V_151 = V_334 -> V_151 ;
V_146 -> V_113 . V_21 = V_340 ;
V_146 -> V_44 = V_341 ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_336 = F_150 ( V_146 -> V_112 , & V_146 -> V_113 ,
V_201 , V_342 , 0 ,
V_343 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( ! V_336 )
F_82 ( V_2 -> V_25 ,
( V_146 -> V_44 == V_215 ||
V_146 -> V_44 == V_202 ) ) ;
if ( V_146 -> V_44 == V_202 )
V_336 = - V_109 ;
else
V_146 -> V_44 = V_202 ;
if ( V_336 ) {
F_20 ( V_335 ) ;
* V_66 = NULL ;
* V_239 = 0 ;
} else {
* V_239 = V_334 -> V_151 ;
* V_66 = V_335 ;
}
return V_336 ;
}
static void F_151 ( struct V_1 * V_2 , char * V_344 )
{
F_24 ( V_52 , 2 , L_132 ) ;
V_2 -> V_3 . V_134 = V_344 [ 30 ] ;
V_2 -> V_3 . V_345 = V_344 [ 31 ] ;
V_2 -> V_3 . V_346 = V_344 [ 63 ] ;
V_2 -> V_3 . V_4 = ( ( V_344 [ 0x10 ] == V_347 [ 'V' ] ) &&
( V_344 [ 0x11 ] == V_347 [ 'M' ] ) ) ;
}
static void F_152 ( struct V_1 * V_2 , char * V_344 )
{
F_24 ( V_52 , 2 , L_133 ) ;
if ( V_344 [ 74 ] == 0xF0 && V_344 [ 75 ] == 0xF0 && V_344 [ 76 ] == 0xF5 ) {
V_2 -> V_3 . V_348 . V_349 = 250 ;
V_2 -> V_3 . V_348 . V_350 = 5 ;
V_2 -> V_3 . V_348 . V_351 = 15 ;
} else {
V_2 -> V_3 . V_348 . V_349 = 0 ;
V_2 -> V_3 . V_348 . V_350 = 0 ;
V_2 -> V_3 . V_348 . V_351 = 0 ;
}
}
static void F_153 ( struct V_1 * V_2 )
{
V_2 -> V_352 . V_353 = 0x00010103UL ;
V_2 -> V_352 . V_354 = 0x00010108UL ;
V_2 -> V_352 . V_355 = 0x0001010aUL ;
V_2 -> V_352 . V_356 = 0x0001010bUL ;
V_2 -> V_352 . V_357 = 0x0001010dUL ;
}
static void F_154 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
V_2 -> V_3 . V_255 = V_358 ;
break;
case V_5 :
case V_9 :
V_2 -> V_3 . V_255 = V_359 ;
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
F_24 ( V_52 , 2 , L_134 ) ;
V_2 = F_77 ( V_146 -> V_112 ) ;
V_106 = F_49 ( V_146 ) ;
V_106 -> V_159 = F_156 ;
memcpy ( & V_146 -> V_113 , V_148 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_111 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 -> V_110 ) ;
F_82 ( V_2 -> V_25 ,
F_42 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_50 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_54 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_51 ( 2 , L_135 , V_26 ) ;
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
F_43 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_108 , V_321 ) ;
if ( V_26 == - V_322 )
return V_26 ;
if ( V_146 -> V_44 != V_108 ) {
V_26 = - V_323 ;
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
F_83 ( V_146 ) ;
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
V_169 V_360 ;
T_2 V_30 ;
int V_26 ;
struct V_361 V_362 ;
V_2 = F_77 ( V_146 -> V_112 ) ;
F_24 ( V_52 , 2 , L_137 ) ;
V_106 = F_49 ( V_146 ) ;
V_106 -> V_159 = F_156 ;
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_363 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 -> V_110 ) ;
if ( V_146 == & V_2 -> V_142 ) {
memcpy ( V_106 -> V_110 , V_364 , V_363 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_365 , V_173 ) ;
V_2 -> V_166 . V_365 ++ ;
} else {
memcpy ( V_106 -> V_110 , V_366 , V_363 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_365 , V_173 ) ;
}
V_30 = ( ( T_2 ) V_2 -> V_3 . V_367 ) | 0x80 ;
memcpy ( F_159 ( V_106 -> V_110 ) , & V_30 , 1 ) ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_353 , V_368 ) ;
memcpy ( F_161 ( V_106 -> V_110 ) ,
& V_2 -> V_3 . V_255 , sizeof( V_169 ) ) ;
F_162 ( F_26 ( V_2 ) , & V_362 ) ;
memcpy ( F_163 ( V_106 -> V_110 ) , & V_362 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_3 . V_346 << 8 ) + V_2 -> V_3 . V_345 ;
memcpy ( F_164 ( V_106 -> V_110 ) , & V_360 , 2 ) ;
F_82 ( V_2 -> V_25 ,
F_42 ( & V_146 -> V_115 , 0 , 1 ) == 0 ) ;
F_24 ( V_52 , 6 , L_50 ) ;
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_26 = F_54 ( V_146 -> V_112 ,
& V_146 -> V_113 , ( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
if ( V_26 ) {
F_51 ( 2 , L_138 ,
V_26 ) ;
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
F_43 ( & V_146 -> V_115 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_139 ( V_2 -> V_25 ,
V_146 -> V_44 == V_370 , V_321 ) ;
if ( V_26 == - V_322 )
return V_26 ;
if ( V_146 -> V_44 != V_370 ) {
F_50 ( & V_146 -> V_112 -> V_73 , L_139
L_140 ) ;
F_51 ( 2 , L_141 ,
F_52 ( & V_146 -> V_112 -> V_73 ) ) ;
F_27 ( V_52 , 2 , L_131 , - V_323 ) ;
F_83 ( V_146 ) ;
return - V_323 ;
}
return F_155 ( V_146 , F_156 ) ;
}
static int F_165 ( int V_371 )
{
if ( ( V_371 & 0xff ) == 8 )
return ( V_371 & 0xff ) + 0x400 ;
if ( ( ( V_371 >> 8 ) & 3 ) == 1 )
return ( V_371 & 0xff ) + 0x200 ;
return V_371 ;
}
static void F_166 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_360 ;
F_24 ( V_52 , 2 , L_142 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_370 ;
goto V_60;
}
V_2 = F_77 ( V_146 -> V_112 ) ;
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
if ( F_168 ( V_106 -> V_110 ) == V_372 )
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_143
L_144 ) ;
else
F_51 ( 2 , L_145
L_146 ,
F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) ) ;
goto V_60;
}
memcpy ( & V_360 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( ( V_360 & ~ 0x0100 ) != F_165 ( V_2 -> V_3 . V_255 ) ) {
F_51 ( 2 , L_147
L_148
L_149 , F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_255 , V_360 ) ;
goto V_60;
}
V_146 -> V_44 = V_108 ;
V_60:
F_80 ( V_146 , V_106 ) ;
}
static void F_169 ( struct V_145 * V_146 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_169 V_360 ;
F_24 ( V_52 , 2 , L_150 ) ;
if ( V_146 -> V_44 == V_202 ) {
V_146 -> V_44 = V_370 ;
goto V_60;
}
V_2 = F_77 ( V_146 -> V_112 ) ;
if ( F_76 ( V_2 , V_106 -> V_110 ) )
goto V_60;
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
switch ( F_168 ( V_106 -> V_110 ) ) {
case V_372 :
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_143
L_144 ) ;
break;
case V_373 :
case V_374 :
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
F_168 ( V_106 -> V_110 ) ) ;
goto V_60;
}
if ( ( ! F_170 ( V_106 -> V_110 ) ) ||
( V_2 -> V_3 . type == V_5 ) )
V_2 -> V_3 . V_375 = 1 ;
memcpy ( & V_360 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( V_360 != F_165 ( V_2 -> V_3 . V_255 ) ) {
F_51 ( 2 , L_155
L_156 ,
F_52 ( & V_2 -> V_107 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_255 , V_360 ) ;
goto V_60;
}
memcpy ( & V_2 -> V_352 . V_376 ,
F_160 ( V_106 -> V_110 ) ,
V_368 ) ;
memcpy ( & V_2 -> V_3 . V_300 [ 0 ] ,
F_171 ( V_106 -> V_110 ) , V_377 ) ;
V_146 -> V_44 = V_108 ;
V_60:
F_80 ( V_146 , V_106 ) ;
}
void F_172 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 )
{
F_53 ( & V_2 -> V_142 , V_106 -> V_110 , V_147 ) ;
V_106 -> V_159 = F_80 ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_365 , V_173 ) ;
V_2 -> V_166 . V_365 ++ ;
memcpy ( F_85 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_378 , V_173 ) ;
V_2 -> V_166 . V_378 ++ ;
memcpy ( F_173 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_172 , V_173 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
}
int F_174 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_379 )
{
int V_26 ;
unsigned long V_21 ;
struct V_117 * V_118 = NULL ;
unsigned long V_380 , V_381 ;
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
V_118 -> V_159 = F_175 ;
V_118 -> V_382 = V_379 ;
if ( V_2 -> V_44 == V_45 )
V_118 -> V_166 = V_167 ;
else
V_118 -> V_166 = V_2 -> V_166 . V_383 ++ ;
F_88 ( & V_118 -> V_25 ) ;
F_4 ( & V_2 -> V_141 , V_21 ) ;
F_84 ( & V_118 -> V_31 , & V_2 -> V_171 ) ;
F_5 ( & V_2 -> V_141 , V_21 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
while ( F_42 ( & V_2 -> V_142 . V_115 , 0 , 1 ) ) ;
F_172 ( V_2 , V_147 , V_106 ) ;
if ( F_67 ( V_106 -> V_110 ) )
V_381 = V_384 ;
else
V_381 = V_321 ;
V_380 = V_385 + V_381 ;
F_11 ( V_2 , 6 , L_50 ) ;
F_4 ( F_137 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
V_26 = F_54 ( V_2 -> V_142 . V_112 , & V_2 -> V_142 . V_113 ,
( V_114 ) V_106 , 0 , 0 ) ;
F_5 ( F_137 ( V_2 -> V_142 . V_112 ) , V_21 ) ;
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
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
if ( ( V_123 -> V_126 . V_127 == V_387 ) &&
( V_123 -> V_126 . V_388 == V_389 ) ) {
if ( ! F_176 ( V_118 -> V_25 ,
F_34 ( & V_118 -> V_121 ) , V_381 ) )
goto V_390;
} else {
while ( ! F_34 ( & V_118 -> V_121 ) ) {
if ( F_177 ( V_385 , V_380 ) )
goto V_390;
F_178 () ;
} ;
}
if ( V_118 -> V_26 == - V_109 )
goto error;
V_26 = V_118 -> V_26 ;
F_60 ( V_118 ) ;
return V_26 ;
V_390:
V_118 -> V_26 = - V_323 ;
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
static int F_179 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_161 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_352 . V_391 ,
F_180 ( V_106 -> V_110 ) ,
V_368 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_162 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_392 , V_393 ) ;
memcpy ( F_182 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_376 , V_368 ) ;
memcpy ( F_183 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_354 , V_368 ) ;
V_26 = F_174 ( V_2 , V_393 , V_106 ,
F_179 , NULL ) ;
return V_26 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_163 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_352 . V_394 ,
F_185 ( V_106 -> V_110 ) ,
V_368 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_164 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_395 , V_396 ) ;
memcpy ( F_187 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_376 , V_368 ) ;
memcpy ( F_188 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_355 , V_368 ) ;
memcpy ( F_189 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_391 , V_368 ) ;
V_26 = F_174 ( V_2 , V_396 , V_106 ,
F_184 , NULL ) ;
return V_26 ;
}
static inline int F_190 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_319 :
return 1500 ;
case V_6 :
return V_2 -> V_3 . V_397 ;
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
static inline int F_191 ( int V_398 )
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
static inline int F_192 ( struct V_1 * V_2 , int V_399 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
case V_6 :
return ( ( V_399 >= 576 ) &&
( V_399 <= V_2 -> V_3 . V_397 ) ) ;
case V_9 :
case V_319 :
default:
return 1 ;
}
}
static int F_193 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
V_169 V_399 , V_398 ;
V_169 V_147 ;
T_2 V_10 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_165 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_352 . V_400 ,
F_194 ( V_106 -> V_110 ) ,
V_368 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
memcpy ( & V_398 , F_195 ( V_106 -> V_110 ) , 2 ) ;
V_399 = F_191 ( V_398 ) ;
if ( ! V_399 ) {
V_106 -> V_26 = - V_401 ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
if ( V_2 -> V_3 . V_402 && ( V_2 -> V_3 . V_402 != V_399 ) ) {
if ( V_2 -> V_73 &&
( ( V_2 -> V_73 -> V_399 == V_2 -> V_3 . V_402 ) ||
( V_2 -> V_73 -> V_399 > V_399 ) ) )
V_2 -> V_73 -> V_399 = V_399 ;
F_112 ( V_2 ) ;
}
V_2 -> V_3 . V_402 = V_399 ;
V_2 -> V_3 . V_397 = V_399 ;
V_2 -> V_35 . V_256 = V_399 + 2 * V_403 ;
} else {
V_2 -> V_3 . V_402 = F_190 ( V_2 ) ;
V_2 -> V_3 . V_397 = * ( V_169 * ) F_195 (
V_106 -> V_110 ) ;
V_2 -> V_35 . V_256 = V_257 ;
}
memcpy ( & V_147 , F_196 ( V_106 -> V_110 ) , 2 ) ;
if ( V_147 >= V_404 ) {
memcpy ( & V_10 ,
F_197 ( V_106 -> V_110 ) , 1 ) ;
V_2 -> V_3 . V_10 = V_10 ;
} else
V_2 -> V_3 . V_10 = 0 ;
F_27 ( V_52 , 2 , L_166 , V_2 -> V_3 . V_10 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
int V_26 ;
char V_405 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_167 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_406 , V_407 ) ;
* ( F_199 ( V_106 -> V_110 ) ) =
( T_2 ) V_2 -> V_3 . V_367 ;
if ( V_2 -> V_49 . V_305 )
if ( V_2 -> V_3 . type == V_9 )
V_405 = V_408 ;
else
V_405 = V_409 ;
else
V_405 = V_410 ;
memcpy ( F_200 ( V_106 -> V_110 ) , & V_405 , 1 ) ;
memcpy ( F_201 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_202 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_356 , V_368 ) ;
memcpy ( F_203 ( V_106 -> V_110 ) ,
V_2 -> V_3 . V_411 , 9 ) ;
V_26 = F_174 ( V_2 , V_407 , V_106 ,
F_193 , NULL ) ;
return V_26 ;
}
static int F_204 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_168 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_352 . V_412 ,
F_205 ( V_106 -> V_110 ) ,
V_368 ) ;
if ( ! strncmp ( L_169 , F_205 ( V_106 -> V_110 ) ,
3 ) ) {
F_24 ( V_52 , 2 , L_170 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_171
L_172 ) ;
V_106 -> V_26 = - V_413 ;
}
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return V_26 ;
}
static int F_206 ( struct V_1 * V_2 )
{
int V_26 ;
V_169 V_360 ;
struct V_105 * V_106 ;
struct V_361 V_414 ;
F_24 ( V_52 , 2 , L_173 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_415 , V_416 ) ;
memcpy ( F_207 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_208 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_357 , V_368 ) ;
memcpy ( F_209 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_400 , V_368 ) ;
F_162 ( F_26 ( V_2 ) , & V_414 ) ;
memcpy ( F_210 ( V_106 -> V_110 ) , & V_414 . V_369 , 2 ) ;
V_360 = ( V_2 -> V_3 . V_346 << 8 ) + V_2 -> V_3 . V_345 ;
memcpy ( F_211 ( V_106 -> V_110 ) , & V_360 , 2 ) ;
V_26 = F_174 ( V_2 , V_416 , V_106 ,
F_204 , NULL ) ;
return V_26 ;
}
static int F_39 ( struct V_84 * V_85 , int V_86 )
{
int V_26 ;
struct V_89 * V_417 ;
V_26 = 0 ;
V_417 = F_212 ( V_94 , V_119 ) ;
if ( ! V_417 ) {
V_26 = - V_39 ;
goto V_60;
}
V_417 -> V_66 = & V_85 -> V_54 [ V_86 ] ;
F_213 ( & V_417 -> V_220 ) ;
F_214 ( & V_417 -> V_220 . V_141 , & V_418 ) ;
V_417 -> V_85 = V_85 ;
V_417 -> V_95 = NULL ;
V_417 -> V_88 = V_85 -> V_65 [ V_86 ] ;
F_43 ( & V_417 -> V_44 , V_235 ) ;
V_85 -> V_65 [ V_86 ] = V_417 ;
if ( V_85 -> V_71 ) {
V_85 -> V_71 [ V_86 ] . V_419 = V_417 ;
F_35 ( V_85 -> V_2 , 2 , L_174 , V_86 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 , ( long ) V_417 ) ;
F_35 ( V_85 -> V_2 , 2 , L_41 ,
( long ) V_417 -> V_88 ) ;
}
V_60:
return V_26 ;
}
static int F_215 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
F_24 ( V_52 , 2 , L_175 ) ;
if ( F_42 ( & V_2 -> V_35 . V_44 , V_242 ,
V_333 ) != V_242 )
return 0 ;
V_2 -> V_35 . V_244 = F_15 ( sizeof( struct V_63 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_244 )
goto V_420;
F_24 ( V_52 , 2 , L_176 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_244 , sizeof( void * ) ) ;
memset ( V_2 -> V_35 . V_244 , 0 , sizeof( struct V_63 ) ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_66 =
& V_2 -> V_35 . V_244 -> V_54 [ V_33 ] ;
V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_245 = NULL ;
}
if ( F_14 ( V_2 ) )
goto V_421;
V_2 -> V_35 . V_70 =
F_15 ( V_2 -> V_35 . V_68 *
sizeof( struct V_84 * ) , V_38 ) ;
if ( ! V_2 -> V_35 . V_70 )
goto V_422;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 ) {
V_2 -> V_35 . V_70 [ V_33 ] = F_15 ( sizeof( struct V_84 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_70 [ V_33 ] )
goto V_423;
F_27 ( V_52 , 2 , L_177 , V_33 ) ;
F_29 ( V_52 , 2 , & V_2 -> V_35 . V_70 [ V_33 ] , sizeof( void * ) ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_424 = V_33 ;
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 ) {
F_37 ( V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] != NULL ) ;
if ( F_39 ( V_2 -> V_35 . V_70 [ V_33 ] , V_34 ) )
goto V_425;
}
}
if ( F_28 ( V_2 ) )
goto V_423;
return 0 ;
V_425:
while ( V_34 > 0 ) {
-- V_34 ;
F_38 ( V_94 ,
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] ) ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] = NULL ;
}
V_423:
while ( V_33 > 0 ) {
F_20 ( V_2 -> V_35 . V_70 [ -- V_33 ] ) ;
F_110 ( V_2 -> V_35 . V_70 [ V_33 ] , 1 ) ;
}
F_20 ( V_2 -> V_35 . V_70 ) ;
V_2 -> V_35 . V_70 = NULL ;
V_422:
F_16 ( V_2 ) ;
V_421:
F_20 ( V_2 -> V_35 . V_244 ) ;
V_2 -> V_35 . V_244 = NULL ;
V_420:
F_43 ( & V_2 -> V_35 . V_44 , V_242 ) ;
return - V_39 ;
}
static void F_216 ( struct V_1 * V_2 ,
char * V_426 )
{
V_426 [ 0 ] = V_347 [ 'P' ] ;
V_426 [ 1 ] = V_347 [ 'C' ] ;
V_426 [ 2 ] = V_347 [ 'I' ] ;
V_426 [ 3 ] = V_347 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_426 [ 4 ] ) ) = F_217 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_426 [ 8 ] ) ) = F_218 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_426 [ 12 ] ) ) = F_219 ( V_2 ) ;
}
static void F_220 ( struct V_1 * V_2 ,
char * V_426 )
{
V_426 [ 16 ] = V_347 [ 'B' ] ;
V_426 [ 17 ] = V_347 [ 'L' ] ;
V_426 [ 18 ] = V_347 [ 'K' ] ;
V_426 [ 19 ] = V_347 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_426 [ 20 ] ) ) = V_2 -> V_3 . V_348 . V_349 ;
* ( ( unsigned int * ) ( & V_426 [ 24 ] ) ) = V_2 -> V_3 . V_348 . V_350 ;
* ( ( unsigned int * ) ( & V_426 [ 28 ] ) ) =
V_2 -> V_3 . V_348 . V_351 ;
}
static int F_221 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 3 , L_178 ) ;
return F_222 ( F_26 ( V_2 ) ) ;
}
static int F_223 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_179 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_427 , V_428 ) ;
memcpy ( F_224 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_394 , V_368 ) ;
memcpy ( F_225 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
V_26 = F_174 ( V_2 , V_428 , V_106 , NULL , NULL ) ;
return V_26 ;
}
static int F_226 ( struct V_1 * V_2 )
{
int V_26 ;
F_24 ( V_52 , 2 , L_180 ) ;
V_26 = F_48 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
return V_26 ;
}
V_26 = F_181 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
goto V_429;
}
V_26 = F_186 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_429;
}
V_26 = F_198 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_429;
}
V_26 = F_206 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_429;
}
V_26 = F_215 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_429;
}
V_26 = F_227 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_112 ( V_2 ) ;
goto V_429;
}
V_26 = F_221 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_184 , V_26 ) ;
goto V_429;
}
V_26 = F_223 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_185 , V_26 ) ;
goto V_429;
}
return 0 ;
V_429:
F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
return V_26 ;
}
static void F_228 ( struct V_1 * V_2 )
{
char V_430 [ 15 ] ;
int V_33 ;
sprintf ( V_430 , L_186 , V_2 -> V_3 . V_411 + 1 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_430 [ V_33 ] =
( char ) V_431 [ ( T_2 ) V_430 [ V_33 ] ] ;
V_430 [ 8 ] = 0 ;
F_72 ( & V_2 -> V_72 -> V_73 , L_187
L_188 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? V_2 -> V_3 . V_300 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ,
V_430 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_411 [ 0 ] )
F_72 ( & V_2 -> V_72 -> V_73 , L_191
L_192
L_193 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? V_2 -> V_3 . V_300 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ) ;
else
F_72 ( & V_2 -> V_72 -> V_73 , L_191
L_194 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_189 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? V_2 -> V_3 . V_300 : L_69 ,
( V_2 -> V_3 . V_300 [ 0 ] ) ? L_190 : L_69 ,
F_2 ( V_2 ) ) ;
}
void F_230 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
if ( ! V_2 -> V_3 . V_300 [ 0 ] ) {
sprintf ( V_2 -> V_3 . V_300 , L_195 ,
V_2 -> V_3 . V_300 [ 2 ] ,
V_2 -> V_3 . V_300 [ 3 ] ) ;
V_2 -> V_3 . V_300 [ V_377 ] = 0 ;
break;
}
case V_6 :
if ( ( V_2 -> V_3 . V_4 ) ||
( V_2 -> V_3 . V_300 [ 0 ] & 0x80 ) ) {
V_2 -> V_3 . V_300 [ 0 ] = ( char ) V_431 [ ( T_2 )
V_2 -> V_3 . V_300 [ 0 ] ] ;
V_2 -> V_3 . V_300 [ 1 ] = ( char ) V_431 [ ( T_2 )
V_2 -> V_3 . V_300 [ 1 ] ] ;
V_2 -> V_3 . V_300 [ 2 ] = ( char ) V_431 [ ( T_2 )
V_2 -> V_3 . V_300 [ 2 ] ] ;
V_2 -> V_3 . V_300 [ 3 ] = ( char ) V_431 [ ( T_2 )
V_2 -> V_3 . V_300 [ 3 ] ] ;
V_2 -> V_3 . V_300 [ V_377 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_3 . V_300 [ 0 ] , 0 , V_377 + 1 ) ;
}
if ( V_2 -> V_3 . V_375 )
F_228 ( V_2 ) ;
else
F_229 ( V_2 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_28 * V_432 ;
F_11 ( V_2 , 5 , L_196 ) ;
F_232 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_233 ( V_2 , V_432 ) ;
}
}
static inline struct V_28 * F_234 (
struct V_1 * V_2 )
{
struct V_301 * V_433 ;
struct V_28 * V_432 ;
int V_33 , free ;
struct V_434 * V_434 ;
if ( F_235 ( & V_2 -> V_35 . V_48 . V_42 ) )
return NULL ;
F_236 (plh, &card->qdio.in_buf_pool.entry_list) {
V_432 = F_237 ( V_433 , struct V_28 , V_31 ) ;
free = 1 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_238 ( F_239 ( V_432 -> V_40 [ V_33 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_75 ( & V_432 -> V_31 ) ;
return V_432 ;
}
}
V_432 = F_237 ( V_2 -> V_35 . V_48 . V_42 . V_435 ,
struct V_28 , V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_238 ( F_239 ( V_432 -> V_40 [ V_33 ] ) ) > 1 ) {
V_434 = F_240 ( V_119 ) ;
if ( ! V_434 ) {
return NULL ;
} else {
F_19 ( ( unsigned long ) V_432 -> V_40 [ V_33 ] ) ;
V_432 -> V_40 [ V_33 ] = F_241 ( V_434 ) ;
if ( V_2 -> V_49 . V_270 )
V_2 -> V_436 . V_437 ++ ;
}
}
}
F_75 ( & V_432 -> V_31 ) ;
return V_432 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_438 * V_217 )
{
struct V_28 * V_29 ;
int V_33 ;
if ( ( V_2 -> V_49 . V_50 == V_51 ) && ( ! V_217 -> V_245 ) ) {
V_217 -> V_245 = F_243 ( V_439 + V_440 ) ;
if ( ! V_217 -> V_245 )
return 1 ;
}
V_29 = F_234 ( V_2 ) ;
if ( ! V_29 )
return 1 ;
V_217 -> V_29 = V_29 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
V_217 -> V_66 -> V_231 [ V_33 ] . V_239 = V_403 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_236 = V_29 -> V_40 [ V_33 ] ;
if ( V_33 == F_17 ( V_2 ) - 1 )
V_217 -> V_66 -> V_231 [ V_33 ] . V_240 = V_441 ;
else
V_217 -> V_66 -> V_231 [ V_33 ] . V_240 = 0 ;
V_217 -> V_66 -> V_231 [ V_33 ] . V_232 = 0 ;
}
return 0 ;
}
int F_244 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
int V_26 ;
F_24 ( V_52 , 2 , L_197 ) ;
memset ( V_2 -> V_35 . V_244 -> V_54 , 0 ,
V_55 * sizeof( struct V_56 ) ) ;
F_231 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_48 . V_37 - 1 ; ++ V_33 )
F_242 ( V_2 , & V_2 -> V_35 . V_244 -> V_65 [ V_33 ] ) ;
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
V_2 -> V_35 . V_70 [ V_33 ] -> V_442 = 0 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_443 = 0 ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_444 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_234 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_44 ,
V_445 ) ;
}
return 0 ;
}
static inline T_2 F_245 ( enum V_446 V_10 )
{
switch ( V_10 ) {
case V_12 :
return 2 ;
default:
return 1 ;
}
}
static void F_246 ( struct V_1 * V_2 ,
struct V_122 * V_123 , T_2 V_127 ,
enum V_447 V_448 )
{
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_126 . V_127 = V_127 ;
V_123 -> V_126 . V_449 = V_450 ;
V_123 -> V_126 . V_166 = V_2 -> V_166 . V_383 ;
V_123 -> V_126 . V_451 = F_245 ( V_2 -> V_3 . V_10 ) ;
V_123 -> V_126 . V_452 = ( T_2 ) V_2 -> V_3 . V_367 ;
if ( V_2 -> V_49 . V_305 )
V_123 -> V_126 . V_453 = 2 ;
else
V_123 -> V_126 . V_453 = 1 ;
V_123 -> V_126 . V_454 = 1 ;
V_123 -> V_126 . V_388 = V_448 ;
V_123 -> V_126 . V_455 = 0 ;
V_123 -> V_126 . V_456 = 0 ;
}
struct V_105 * F_247 ( struct V_1 * V_2 ,
enum V_457 V_458 , enum V_447 V_448 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
F_246 ( V_2 , V_123 , V_458 , V_448 ) ;
return V_106 ;
}
void F_248 ( struct V_1 * V_2 , struct V_105 * V_106 ,
char V_405 )
{
memcpy ( V_106 -> V_110 , V_459 , V_386 ) ;
memcpy ( F_249 ( V_106 -> V_110 ) , & V_405 , 1 ) ;
memcpy ( F_250 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
}
int F_251 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_379 )
{
int V_26 ;
char V_405 ;
F_11 ( V_2 , 4 , L_198 ) ;
if ( V_2 -> V_49 . V_305 )
if ( V_2 -> V_3 . type == V_9 )
V_405 = V_408 ;
else
V_405 = V_409 ;
else
V_405 = V_410 ;
F_248 ( V_2 , V_106 , V_405 ) ;
V_26 = F_174 ( V_2 , V_460 ,
V_106 , F_175 , V_379 ) ;
if ( V_26 == - V_323 ) {
F_74 ( V_2 ) ;
F_55 ( V_2 ) ;
}
return V_26 ;
}
int F_252 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_199 ) ;
V_106 = F_247 ( V_2 , V_136 , 0 ) ;
V_26 = F_251 ( V_2 , V_106 , NULL , NULL ) ;
return V_26 ;
}
int F_253 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_200 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_132 == 0 )
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_461 . V_126 . V_132 ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 3 , L_201 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_110 . V_461 . V_110 . V_462 . V_463 & 0x7f ) {
V_2 -> V_3 . V_10 =
V_123 -> V_110 . V_461 . V_110 . V_462 . V_463 ;
F_27 ( V_52 , 2 , L_202 , V_2 -> V_3 . V_10 ) ;
}
V_2 -> V_49 . V_464 . V_465 =
V_123 -> V_110 . V_461 . V_110 . V_462 . V_466 ;
return F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
}
struct V_105 * F_255 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_467 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_247 ( V_2 , V_468 ,
V_389 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_123 -> V_110 . V_461 . V_126 . V_469 = V_467 ;
V_123 -> V_110 . V_461 . V_126 . V_470 = V_127 ;
V_123 -> V_110 . V_461 . V_126 . V_471 = 1 ;
V_123 -> V_110 . V_461 . V_126 . V_472 = 1 ;
return V_106 ;
}
int F_256 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 3 , L_203 ) ;
V_106 = F_255 ( V_2 , V_473 ,
sizeof( struct V_474 ) ) ;
V_26 = F_251 ( V_2 , V_106 , F_254 , NULL ) ;
return V_26 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_204 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_388 == V_389 ) {
V_2 -> V_49 . V_475 . V_465 = V_123 -> V_126 . V_455 ;
V_2 -> V_49 . V_475 . V_476 = V_123 -> V_126 . V_456 ;
} else {
V_2 -> V_49 . V_477 . V_465 = V_123 -> V_126 . V_455 ;
V_2 -> V_49 . V_477 . V_476 = V_123 -> V_126 . V_456 ;
}
F_24 ( V_52 , 2 , L_205 ) ;
F_27 ( V_52 , 2 , L_206 , V_123 -> V_126 . V_455 ) ;
F_27 ( V_52 , 2 , L_206 , V_123 -> V_126 . V_456 ) ;
return 0 ;
}
int F_258 ( struct V_1 * V_2 , enum V_447 V_448 )
{
int V_26 ;
struct V_105 * V_106 ;
F_27 ( V_52 , 2 , L_207 , V_448 ) ;
V_106 = F_247 ( V_2 , V_478 , V_448 ) ;
V_26 = F_251 ( V_2 , V_106 , F_257 , NULL ) ;
return V_26 ;
}
static int F_259 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_208 , V_26 ) ;
else
V_2 -> V_3 . V_479 = V_123 -> V_110 . V_480 . V_481 ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_209 ) ;
V_106 = F_247 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_123 -> V_110 . V_480 . V_482 = 16 ;
V_123 -> V_110 . V_480 . V_483 = V_484 ;
return F_251 ( V_2 , V_106 , F_259 , NULL ) ;
}
static void F_261 ( struct V_1 * V_2 , struct V_485 * V_486 )
{
unsigned long V_3 = F_262 ( V_38 ) ;
struct V_487 * V_488 = (struct V_487 * ) V_3 ;
struct V_489 * V_490 = (struct V_489 * ) V_3 ;
struct V_361 V_491 ;
int V_371 , V_26 ;
V_486 -> V_134 = V_2 -> V_3 . V_134 ;
F_162 ( F_135 ( V_2 ) , & V_491 ) ;
V_486 -> V_492 = V_491 . V_492 ;
V_486 -> V_369 = V_491 . V_369 ;
if ( ! V_3 )
return;
V_26 = F_263 ( NULL , 0 , 0 , 0 ) ;
if ( V_26 == - V_493 )
V_371 = V_26 ;
else
V_371 = ( ( ( unsigned int ) V_26 ) >> 28 ) ;
if ( ( V_371 >= 2 ) && ( F_263 ( V_488 , 2 , 2 , 2 ) != - V_493 ) )
V_486 -> V_494 = V_488 -> V_495 ;
if ( ( V_371 >= 3 ) && ( F_263 ( V_490 , 3 , 2 , 2 ) != - V_493 ) ) {
F_264 ( V_490 -> V_496 [ 0 ] . V_497 , sizeof( V_490 -> V_496 [ 0 ] . V_497 ) ) ;
memcpy ( V_486 -> V_498 , V_490 -> V_496 [ 0 ] . V_497 , sizeof( V_486 -> V_498 ) ) ;
}
F_19 ( V_3 ) ;
return;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
V_169 V_26 ;
V_123 = (struct V_122 * ) V_110 ;
V_26 = V_123 -> V_126 . V_132 ;
if ( V_26 )
F_35 ( V_2 , 2 , L_210 , V_26 ) ;
return 0 ;
}
int F_266 ( struct V_1 * V_2 , enum V_499 V_500 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_211 ) ;
V_106 = F_247 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_123 -> V_110 . V_480 . V_482 = 80 ;
V_123 -> V_110 . V_480 . V_483 = V_501 ;
V_123 -> V_110 . V_480 . type = 1 ;
V_123 -> V_110 . V_480 . V_500 = V_500 ;
switch ( V_500 ) {
case V_502 :
V_123 -> V_110 . V_480 . V_49 = 0x0003 ;
V_123 -> V_110 . V_480 . V_481 = 0x00010000 +
sizeof( struct V_485 ) ;
F_261 ( V_2 ,
(struct V_485 * ) V_123 -> V_110 . V_480 . V_503 ) ;
break;
case V_504 :
V_123 -> V_110 . V_480 . V_49 = 0x0001 ;
break;
case V_505 :
break;
}
return F_251 ( V_2 , V_106 , F_265 , NULL ) ;
}
int F_267 ( struct V_1 * V_2 , struct V_56 * V_217 ,
unsigned int V_506 , const char * V_507 )
{
if ( V_506 ) {
F_11 ( V_2 , 2 , V_507 ) ;
F_35 ( V_2 , 2 , L_212 ,
V_217 -> V_231 [ 15 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_213 ,
V_217 -> V_231 [ 14 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_214 , V_506 ) ;
if ( ( V_217 -> V_231 [ 15 ] . V_232 ) == 0x12 ) {
V_2 -> V_508 . V_509 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_294 ( struct V_276 * V_277 )
{
struct V_1 * V_2 = F_123 ( V_277 , struct V_1 ,
V_243 . V_277 ) ;
F_35 ( V_2 , 2 , L_215 , V_2 -> V_510 ) ;
F_268 ( V_2 , V_2 -> V_510 ) ;
}
void F_268 ( struct V_1 * V_2 , int V_153 )
{
struct V_63 * V_104 = V_2 -> V_35 . V_244 ;
struct V_301 * V_511 ;
int V_151 ;
int V_33 ;
int V_26 ;
int V_512 = 0 ;
V_151 = ( V_153 < V_104 -> V_57 ) ?
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 - V_153 ) :
V_2 -> V_35 . V_48 . V_37 -
( V_104 -> V_57 + V_55 - V_153 ) ;
if ( V_151 >= F_269 ( V_2 ) ) {
for ( V_33 = V_104 -> V_57 ;
V_33 < V_104 -> V_57 + V_151 ; ++ V_33 ) {
if ( F_242 ( V_2 ,
& V_104 -> V_65 [ V_33 % V_55 ] ) ) {
break;
} else {
V_512 ++ ;
}
}
if ( V_512 < V_151 ) {
F_43 ( & V_2 -> V_513 , 3 ) ;
V_151 = V_512 ;
} else {
F_270 ( & V_2 -> V_513 , - 1 , 0 ) ;
}
if ( ! V_151 ) {
V_33 = 0 ;
F_236 (lh, &card->qdio.in_buf_pool.entry_list)
V_33 ++ ;
if ( V_33 == V_2 -> V_35 . V_48 . V_37 ) {
F_11 ( V_2 , 2 , L_216 ) ;
V_2 -> V_510 = V_153 ;
F_271 (
& V_2 -> V_243 ,
V_514 ) ;
}
return;
}
if ( V_2 -> V_49 . V_270 ) {
V_2 -> V_436 . V_515 ++ ;
V_2 -> V_436 . V_516 =
F_272 () ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , 0 ,
V_104 -> V_57 , V_151 ) ;
if ( V_2 -> V_49 . V_270 )
V_2 -> V_436 . V_517 +=
F_272 () -
V_2 -> V_436 . V_516 ;
if ( V_26 ) {
F_11 ( V_2 , 2 , L_217 ) ;
}
V_104 -> V_57 = ( V_104 -> V_57 + V_151 ) %
V_55 ;
}
}
static int F_273 ( struct V_1 * V_2 ,
struct V_89 * V_66 , unsigned int V_518 )
{
int V_75 = V_66 -> V_66 -> V_231 [ 15 ] . V_232 ;
F_11 ( V_2 , 6 , L_218 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
if ( V_75 == 0 ) {
V_518 = 0 ;
} else {
V_518 = 1 ;
}
}
F_267 ( V_2 , V_66 -> V_66 , V_518 , L_219 ) ;
if ( ! V_518 )
return V_519 ;
if ( ( V_75 >= 15 ) && ( V_75 <= 31 ) )
return V_520 ;
F_11 ( V_2 , 1 , L_220 ) ;
F_35 ( V_2 , 1 , L_221 ,
( V_170 ) V_518 , ( T_3 ) V_75 ) ;
return V_521 ;
}
static void F_274 ( struct V_84 * V_104 )
{
if ( ! V_104 -> V_443 ) {
if ( F_34 ( & V_104 -> V_444 )
>= V_522 ) {
F_11 ( V_104 -> V_2 , 6 , L_222 ) ;
if ( V_104 -> V_2 -> V_49 . V_270 )
V_104 -> V_2 -> V_436 . V_523 ++ ;
V_104 -> V_443 = 1 ;
}
}
}
static int F_275 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
int V_524 = 0 ;
if ( V_104 -> V_443 ) {
if ( F_34 ( & V_104 -> V_444 )
<= V_525 ) {
F_11 ( V_104 -> V_2 , 6 , L_223 ) ;
if ( V_104 -> V_2 -> V_49 . V_270 )
V_104 -> V_2 -> V_436 . V_526 ++ ;
V_104 -> V_443 = 0 ;
V_66 = V_104 -> V_65 [ V_104 -> V_442 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) ==
V_235 ) &&
( V_66 -> V_241 > 0 ) ) {
F_43 ( & V_66 -> V_44 ,
V_100 ) ;
V_524 ++ ;
V_104 -> V_442 =
( V_104 -> V_442 + 1 ) %
V_55 ;
}
}
}
return V_524 ;
}
static int F_276 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
V_66 = V_104 -> V_65 [ V_104 -> V_442 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) == V_235 ) &&
( V_66 -> V_241 > 0 ) ) {
F_43 ( & V_66 -> V_44 , V_100 ) ;
V_104 -> V_442 =
( V_104 -> V_442 + 1 ) % V_55 ;
return 1 ;
}
return 0 ;
}
static void F_277 ( struct V_84 * V_104 , int V_153 ,
int V_151 )
{
struct V_89 * V_217 ;
int V_26 ;
int V_33 ;
unsigned int V_527 ;
for ( V_33 = V_153 ; V_33 < V_153 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_217 = V_104 -> V_65 [ V_86 ] ;
V_217 -> V_66 -> V_231 [ V_217 -> V_241 - 1 ] . V_240 |=
V_441 ;
if ( V_104 -> V_71 )
V_104 -> V_71 [ V_86 ] . V_419 = V_217 ;
if ( V_104 -> V_2 -> V_3 . type == V_6 )
continue;
if ( ! V_104 -> V_443 ) {
if ( ( F_34 ( & V_104 -> V_444 ) >=
( V_522 -
V_528 ) ) &&
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
V_104 -> V_2 -> V_73 -> V_529 = V_385 ;
if ( V_104 -> V_2 -> V_49 . V_270 ) {
V_104 -> V_2 -> V_436 . V_530 ++ ;
V_104 -> V_2 -> V_436 . V_531 =
F_272 () ;
}
V_527 = V_532 ;
if ( F_34 ( & V_104 -> V_234 ) )
V_527 |= V_533 ;
V_26 = F_25 ( F_26 ( V_104 -> V_2 ) , V_527 ,
V_104 -> V_424 , V_153 , V_151 ) ;
if ( V_104 -> V_2 -> V_49 . V_270 )
V_104 -> V_2 -> V_436 . V_534 +=
F_272 () -
V_104 -> V_2 -> V_436 . V_531 ;
F_278 ( V_151 , & V_104 -> V_444 ) ;
if ( V_26 ) {
V_104 -> V_2 -> V_508 . V_535 += V_151 ;
if ( V_26 == V_536 )
return;
F_11 ( V_104 -> V_2 , 2 , L_224 ) ;
F_35 ( V_104 -> V_2 , 2 , L_225 , V_104 -> V_424 ) ;
F_35 ( V_104 -> V_2 , 2 , L_226 , V_153 ) ;
F_35 ( V_104 -> V_2 , 2 , L_227 , V_151 ) ;
F_35 ( V_104 -> V_2 , 2 , L_160 , V_26 ) ;
F_55 ( V_104 -> V_2 ) ;
return;
}
if ( V_104 -> V_2 -> V_49 . V_270 )
V_104 -> V_2 -> V_436 . V_537 += V_151 ;
}
static void F_279 ( struct V_84 * V_104 )
{
int V_153 ;
int V_538 = 0 ;
int V_539 = 0 ;
if ( ( F_34 ( & V_104 -> V_444 ) <= V_525 ) ||
! F_34 ( & V_104 -> V_234 ) ) {
if ( F_113 ( & V_104 -> V_44 , V_540 ) ==
V_445 ) {
F_280 ( V_104 -> V_2 -> V_73 ) ;
V_153 = V_104 -> V_442 ;
V_539 = V_104 -> V_443 ;
F_281 () ;
V_538 += F_275 ( V_104 ) ;
if ( ! V_538 &&
! F_34 ( & V_104 -> V_234 ) )
V_538 +=
F_276 ( V_104 ) ;
if ( V_104 -> V_2 -> V_49 . V_270 &&
V_539 )
V_104 -> V_2 -> V_436 . V_541 +=
V_538 ;
if ( V_538 )
F_277 ( V_104 , V_153 , V_538 ) ;
F_43 ( & V_104 -> V_44 , V_445 ) ;
}
}
}
void F_282 ( struct V_178 * V_112 , int V_104 ,
unsigned long V_542 )
{
struct V_1 * V_2 = (struct V_1 * ) V_542 ;
if ( V_2 -> V_73 && ( V_2 -> V_73 -> V_21 & V_543 ) )
F_283 ( & V_2 -> V_544 ) ;
}
int F_284 ( struct V_1 * V_2 , enum V_545 V_50 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_546 ) {
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
static void F_285 ( struct V_1 * V_2 ,
unsigned int V_518 ,
unsigned int V_104 , int V_547 , int V_151 ) {
struct V_63 * V_50 = V_2 -> V_35 . V_53 ;
int V_33 ;
int V_26 ;
if ( ! F_47 ( V_2 , V_104 ) )
goto V_60;
F_35 ( V_2 , 5 , L_228 , V_547 ) ;
F_35 ( V_2 , 5 , L_229 , V_151 ) ;
F_35 ( V_2 , 5 , L_230 , V_518 ) ;
if ( V_518 ) {
F_280 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_49 . V_270 ) {
V_2 -> V_436 . V_548 ++ ;
V_2 -> V_436 . V_549 = F_272 () ;
}
for ( V_33 = V_547 ; V_33 < V_547 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
struct V_56 * V_66 = & V_50 -> V_54 [ V_86 ] ;
int V_550 ;
V_550 = 0 ;
while ( V_66 -> V_231 [ V_550 ] . V_236 ) {
unsigned long V_96 ;
V_96 = ( unsigned long ) V_66 -> V_231 [ V_550 ] . V_236 ;
F_40 ( V_2 , V_96 ) ;
V_66 -> V_231 [ V_550 ] . V_236 = NULL ;
V_66 -> V_231 [ V_550 ] . V_240 = 0 ;
V_66 -> V_231 [ V_550 ] . V_232 = 0 ;
V_66 -> V_231 [ V_550 ] . V_239 = 0 ;
++ V_550 ;
}
V_66 -> V_231 [ 15 ] . V_240 = 0 ;
V_66 -> V_231 [ 15 ] . V_232 = 0 ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , V_104 ,
V_2 -> V_35 . V_53 -> V_57 ,
V_151 ) ;
if ( V_26 ) {
F_50 ( & V_2 -> V_72 -> V_73 ,
L_231 , V_26 ) ;
F_11 ( V_2 , 2 , L_232 ) ;
}
V_2 -> V_35 . V_53 -> V_57 = ( V_2 -> V_35 . V_53 -> V_57
+ V_151 ) % V_55 ;
F_286 ( V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_270 ) {
int V_551 = F_272 () ;
V_551 -= V_2 -> V_436 . V_549 ;
V_2 -> V_436 . V_552 += V_551 ;
}
V_60:
return;
}
void F_287 ( struct V_178 * V_112 , unsigned int V_518 ,
unsigned int V_104 , int V_553 , int V_151 ,
unsigned long V_542 )
{
struct V_1 * V_2 = (struct V_1 * ) V_542 ;
F_35 ( V_2 , 2 , L_233 , V_104 ) ;
F_35 ( V_2 , 2 , L_234 , V_518 ) ;
if ( F_47 ( V_2 , V_104 ) )
F_285 ( V_2 , V_518 , V_104 , V_553 , V_151 ) ;
else if ( V_518 )
F_55 ( V_2 ) ;
}
void F_288 ( struct V_178 * V_112 ,
unsigned int V_506 , int V_554 , int V_547 ,
int V_151 , unsigned long V_542 )
{
struct V_1 * V_2 = (struct V_1 * ) V_542 ;
struct V_84 * V_104 = V_2 -> V_35 . V_70 [ V_554 ] ;
struct V_89 * V_66 ;
int V_33 ;
F_11 ( V_2 , 6 , L_235 ) ;
if ( V_506 & V_555 ) {
F_11 ( V_2 , 2 , L_236 ) ;
F_280 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
return;
}
if ( V_2 -> V_49 . V_270 ) {
V_2 -> V_436 . V_556 ++ ;
V_2 -> V_436 . V_557 =
F_272 () ;
}
for ( V_33 = V_547 ; V_33 < ( V_547 + V_151 ) ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_66 = V_104 -> V_65 [ V_86 ] ;
F_273 ( V_2 , V_66 , V_506 ) ;
if ( V_104 -> V_71 &&
( V_104 -> V_71 [ V_86 ] . V_21 &
V_558 ) != 0 ) {
F_37 ( V_2 -> V_49 . V_50 != V_51 ) ;
if ( F_42 ( & V_66 -> V_44 ,
V_100 ,
V_102 ) ==
V_100 ) {
F_44 ( V_104 , V_66 ,
V_559 ) ;
}
V_66 -> V_95 = V_104 -> V_71 [ V_86 ] . V_95 ;
F_35 ( V_104 -> V_2 , 5 , L_237 , V_86 ) ;
F_11 ( V_104 -> V_2 , 5 , L_238 ) ;
F_35 ( V_104 -> V_2 , 5 , L_41 ,
F_289 ( V_66 -> V_95 ) ) ;
F_37 ( V_86 < 0 || V_86 >= V_55 ) ;
if ( F_39 ( V_104 , V_86 ) ) {
F_11 ( V_2 , 2 , L_239 ) ;
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
F_290 ( V_151 , & V_104 -> V_444 ) ;
if ( V_2 -> V_3 . type != V_6 )
F_279 ( V_104 ) ;
F_286 ( V_104 -> V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_270 )
V_2 -> V_436 . V_560 += F_272 () -
V_2 -> V_436 . V_557 ;
}
int F_291 ( struct V_1 * V_2 , struct V_218 * V_219 ,
int V_561 , int V_562 )
{
if ( ! V_561 && ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) )
return V_2 -> V_35 . V_254 ;
switch ( V_2 -> V_35 . V_68 ) {
case 4 :
if ( V_562 && V_2 -> V_3 . V_317 )
return V_2 -> V_3 . V_317 &
( V_2 -> V_35 . V_68 - 1 ) ;
if ( V_2 -> V_35 . V_307 && ( V_561 == 4 ) ) {
const T_3 V_563 = F_292 ( V_219 ) -> V_563 ;
if ( V_2 -> V_35 . V_307 ==
V_564 ) {
if ( V_563 & V_565 )
return 3 ;
if ( V_563 & V_566 )
return 2 ;
if ( V_563 & V_567 )
return 1 ;
if ( V_563 & V_568 )
return 0 ;
}
if ( V_2 -> V_35 . V_307 ==
V_569 )
return 3 - ( V_563 >> 6 ) ;
} else if ( V_2 -> V_35 . V_307 && ( V_561 == 6 ) ) {
}
return V_2 -> V_35 . V_254 ;
case 1 :
default:
return V_2 -> V_35 . V_254 ;
}
}
int F_293 ( struct V_1 * V_2 , void * V_126 ,
struct V_218 * V_219 , int V_570 )
{
int V_571 = V_219 -> V_147 - V_219 -> V_572 ;
int V_573 = F_294 ( ( unsigned long ) V_219 -> V_110 + V_571 - 1 ) -
F_295 ( ( unsigned long ) V_219 -> V_110 ) ;
V_573 += F_296 ( V_219 ) -> V_574 ;
if ( ( V_573 + V_570 ) > F_17 ( V_2 ) ) {
F_51 ( 2 , L_240
L_241 ,
( V_573 + V_570 ) , V_219 -> V_147 ) ;
return 0 ;
}
return V_573 ;
}
int F_297 ( struct V_218 * V_219 , int V_147 )
{
int V_575 , V_576 , V_577 ;
if ( ( ( unsigned long ) V_219 -> V_110 & V_578 ) !=
( ( ( unsigned long ) V_219 -> V_110 + V_147 - 1 ) & V_578 ) ) {
V_575 = F_298 ( V_219 ) ;
V_576 = V_403 - ( ( unsigned long ) V_219 -> V_110 % V_403 ) ;
V_577 = V_147 - V_576 ;
if ( V_577 > V_575 )
return 1 ;
memmove ( V_219 -> V_110 - V_577 , V_219 -> V_110 , V_219 -> V_147 - V_219 -> V_572 ) ;
V_219 -> V_110 -= V_577 ;
F_51 ( 2 , L_242 , V_147 , V_577 ) ;
}
return 0 ;
}
static inline void F_299 ( struct V_218 * V_219 ,
struct V_56 * V_66 , int V_579 , int * V_241 ,
int V_168 )
{
int V_239 = V_219 -> V_147 - V_219 -> V_572 ;
int V_580 ;
int V_231 ;
char * V_110 ;
int V_581 , V_161 ;
struct V_582 * V_583 ;
V_231 = * V_241 ;
V_110 = V_219 -> V_110 ;
V_581 = ( V_579 == 0 ? 1 : 0 ) ;
if ( V_168 >= 0 ) {
V_110 = V_219 -> V_110 + V_168 ;
V_239 -= V_168 ;
V_581 = 0 ;
}
while ( V_239 > 0 ) {
V_580 = V_403 - ( ( unsigned long ) V_110 % V_403 ) ;
if ( V_239 < V_580 )
V_580 = V_239 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_580 ;
V_239 -= V_580 ;
if ( ! V_239 ) {
if ( V_581 )
if ( F_296 ( V_219 ) -> V_574 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_584 ;
else
V_66 -> V_231 [ V_231 ] . V_240 = 0 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_585 ;
} else {
if ( V_581 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_584 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_585 ;
}
V_110 += V_580 ;
V_231 ++ ;
V_581 = 0 ;
}
for ( V_161 = 0 ; V_161 < F_296 ( V_219 ) -> V_574 ; V_161 ++ ) {
V_583 = & F_296 ( V_219 ) -> V_586 [ V_161 ] ;
V_66 -> V_231 [ V_231 ] . V_236 = ( char * )
F_300 ( F_301 ( V_583 ) )
+ V_583 -> V_587 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_583 -> V_588 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_585 ;
V_231 ++ ;
}
if ( V_66 -> V_231 [ V_231 - 1 ] . V_240 )
V_66 -> V_231 [ V_231 - 1 ] . V_240 = V_589 ;
* V_241 = V_231 ;
}
static inline int F_302 ( struct V_84 * V_104 ,
struct V_89 * V_217 , struct V_218 * V_219 ,
struct V_590 * V_126 , int V_168 , int V_591 )
{
struct V_56 * V_66 ;
int V_538 = 0 , V_592 , V_593 = 0 ;
V_66 = V_217 -> V_66 ;
F_59 ( & V_219 -> V_228 ) ;
F_303 ( & V_217 -> V_220 , V_219 ) ;
if ( V_126 -> V_126 . V_594 . V_312 == V_595 ) {
int V_231 = V_217 -> V_241 ;
V_592 = sizeof( struct V_596 ) +
( (struct V_596 * ) V_126 ) -> V_481 . V_597 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_219 -> V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_592 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_584 ;
V_217 -> V_241 ++ ;
V_219 -> V_110 += V_592 ;
V_219 -> V_147 -= V_592 ;
V_593 = 1 ;
}
if ( V_168 >= 0 ) {
int V_231 = V_217 -> V_241 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_126 ;
V_66 -> V_231 [ V_231 ] . V_239 = sizeof( struct V_590 ) +
V_591 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_584 ;
V_217 -> V_237 [ V_231 ] = 1 ;
V_217 -> V_241 ++ ;
}
F_299 ( V_219 , V_66 , V_593 ,
( int * ) & V_217 -> V_241 , V_168 ) ;
if ( ! V_104 -> V_443 ) {
F_11 ( V_104 -> V_2 , 6 , L_243 ) ;
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_538 = 1 ;
} else {
F_11 ( V_104 -> V_2 , 6 , L_244 ) ;
if ( V_104 -> V_2 -> V_49 . V_270 )
V_104 -> V_2 -> V_436 . V_598 ++ ;
if ( V_217 -> V_241 >=
F_17 ( V_104 -> V_2 ) ) {
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_538 = 1 ;
}
}
return V_538 ;
}
int F_304 ( struct V_1 * V_2 ,
struct V_84 * V_104 , struct V_218 * V_219 ,
struct V_590 * V_126 , int V_573 ,
int V_168 , int V_591 )
{
struct V_89 * V_66 ;
int V_153 ;
while ( F_42 ( & V_104 -> V_44 , V_445 ,
V_599 ) != V_445 ) ;
V_153 = V_104 -> V_442 ;
V_66 = V_104 -> V_65 [ V_104 -> V_442 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 )
goto V_60;
V_104 -> V_442 = ( V_104 -> V_442 + 1 ) %
V_55 ;
F_43 ( & V_104 -> V_44 , V_445 ) ;
F_302 ( V_104 , V_66 , V_219 , V_126 , V_168 , V_591 ) ;
F_277 ( V_104 , V_153 , 1 ) ;
return 0 ;
V_60:
F_43 ( & V_104 -> V_44 , V_445 ) ;
return - V_600 ;
}
int F_305 ( struct V_1 * V_2 , struct V_84 * V_104 ,
struct V_218 * V_219 , struct V_590 * V_126 ,
int V_573 )
{
struct V_89 * V_66 ;
int V_601 ;
int V_524 = 0 ;
int V_443 = 0 ;
int V_30 ;
int V_26 = 0 ;
while ( F_42 ( & V_104 -> V_44 , V_445 ,
V_599 ) != V_445 ) ;
V_601 = V_104 -> V_442 ;
V_66 = V_104 -> V_65 [ V_104 -> V_442 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 ) {
F_43 ( & V_104 -> V_44 , V_445 ) ;
return - V_600 ;
}
F_274 ( V_104 ) ;
if ( V_104 -> V_443 ) {
V_443 = 1 ;
if ( ( F_17 ( V_2 ) -
V_66 -> V_241 ) < V_573 ) {
F_43 ( & V_66 -> V_44 , V_100 ) ;
V_524 ++ ;
V_104 -> V_442 =
( V_104 -> V_442 + 1 ) %
V_55 ;
V_66 = V_104 -> V_65 [ V_104 -> V_442 ] ;
if ( F_34 ( & V_66 -> V_44 ) !=
V_235 ) {
F_277 ( V_104 , V_601 ,
V_524 ) ;
F_43 ( & V_104 -> V_44 ,
V_445 ) ;
return - V_600 ;
}
}
}
V_30 = F_302 ( V_104 , V_66 , V_219 , V_126 , - 1 , 0 ) ;
V_104 -> V_442 = ( V_104 -> V_442 + V_30 ) %
V_55 ;
V_524 += V_30 ;
if ( V_524 )
F_277 ( V_104 , V_601 , V_524 ) ;
else if ( ! F_34 ( & V_104 -> V_234 ) )
F_113 ( & V_104 -> V_44 , V_540 ) ;
while ( F_306 ( & V_104 -> V_44 ) ) {
V_524 = 0 ;
V_601 = V_104 -> V_442 ;
V_524 += F_275 ( V_104 ) ;
if ( ! V_524 && ! F_34 ( & V_104 -> V_234 ) )
V_524 += F_276 ( V_104 ) ;
if ( V_524 )
F_277 ( V_104 , V_601 , V_524 ) ;
}
if ( V_104 -> V_2 -> V_49 . V_270 && V_443 )
V_104 -> V_2 -> V_436 . V_541 += V_524 ;
return V_26 ;
}
static int F_307 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_474 * V_602 ;
F_11 ( V_2 , 4 , L_245 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_602 = & ( V_123 -> V_110 . V_461 ) ;
F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_246 , V_123 -> V_126 . V_132 ) ;
V_602 -> V_110 . V_603 = V_604 ;
}
V_2 -> V_3 . V_605 = V_602 -> V_110 . V_603 ;
return 0 ;
}
void F_308 ( struct V_1 * V_2 )
{
enum V_606 V_603 ;
struct V_607 * V_73 = V_2 -> V_73 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_247 ) ;
if ( ( ( V_73 -> V_21 & V_608 ) &&
( V_2 -> V_3 . V_605 == V_609 ) ) ||
( ! ( V_73 -> V_21 & V_608 ) &&
( V_2 -> V_3 . V_605 == V_604 ) ) )
return;
V_603 = V_604 ;
if ( V_73 -> V_21 & V_608 )
V_603 = V_609 ;
F_35 ( V_2 , 4 , L_248 , V_603 ) ;
V_106 = F_255 ( V_2 , V_610 ,
sizeof( struct V_474 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_123 -> V_110 . V_461 . V_110 . V_603 = V_603 ;
F_251 ( V_2 , V_106 , F_307 , NULL ) ;
}
int F_309 ( struct V_607 * V_73 , int V_611 )
{
struct V_1 * V_2 ;
char V_430 [ 15 ] ;
V_2 = V_73 -> V_612 ;
F_11 ( V_2 , 4 , L_249 ) ;
sprintf ( V_430 , L_250 , V_611 ) ;
F_11 ( V_2 , 4 , V_430 ) ;
if ( V_611 < 64 )
return - V_401 ;
if ( V_611 > 65535 )
return - V_401 ;
if ( ( ! F_310 ( V_2 , V_613 ) ) &&
( ! F_192 ( V_2 , V_611 ) ) )
return - V_401 ;
V_73 -> V_399 = V_611 ;
return 0 ;
}
struct V_614 * F_311 ( struct V_607 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_612 ;
F_11 ( V_2 , 5 , L_251 ) ;
return & V_2 -> V_508 ;
}
static int F_312 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_252 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( ! V_2 -> V_49 . V_305 ||
! ( V_2 -> V_3 . V_615 & V_616 ) ) {
memcpy ( V_2 -> V_73 -> V_617 ,
& V_123 -> V_110 . V_461 . V_110 . V_618 . V_236 ,
V_619 ) ;
V_2 -> V_3 . V_615 |= V_616 ;
}
F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
int F_313 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_253 ) ;
V_106 = F_255 ( V_2 , V_620 ,
sizeof( struct V_474 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_123 -> V_110 . V_461 . V_110 . V_618 . V_123 = V_621 ;
V_123 -> V_110 . V_461 . V_110 . V_618 . V_622 = V_619 ;
memcpy ( & V_123 -> V_110 . V_461 . V_110 . V_618 . V_236 ,
V_2 -> V_73 -> V_617 , V_619 ) ;
V_26 = F_251 ( V_2 , V_106 , F_312 ,
NULL ) ;
return V_26 ;
}
static int F_314 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_623 * V_624 ;
F_11 ( V_2 , 4 , L_254 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_624 = & V_123 -> V_110 . V_461 . V_110 . V_625 ;
F_27 ( V_52 , 2 , L_254 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_626 . V_497 ) ;
F_27 ( V_52 , 2 , L_255 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
switch ( V_123 -> V_110 . V_461 . V_126 . V_132 ) {
case V_627 :
case V_628 :
case V_629 :
{
V_2 -> V_49 . V_273 = V_624 -> V_630 ;
if ( V_2 -> V_49 . V_273 == V_274 ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_256 ) ;
} else {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_257 ) ;
}
F_51 ( 3 , L_258 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_624 -> V_630 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
break;
}
case V_631 :
{
F_51 ( 3 , L_259 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_624 -> V_630 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_260
L_261 ) ;
V_2 -> V_49 . V_273 = V_274 ;
break;
}
case V_632 :
{
F_51 ( 3 , L_262 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_624 -> V_630 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_263
L_264 ) ;
V_2 -> V_49 . V_273 = V_274 ;
break;
}
case V_633 :
{
F_51 ( 3 , L_262 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_624 -> V_630 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_265 ) ;
V_2 -> V_49 . V_273 = V_274 ;
break;
}
default:
{
F_51 ( 3 , L_266
L_267 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_624 -> V_630 ,
V_123 -> V_110 . V_461 . V_126 . V_132 ) ;
V_2 -> V_49 . V_273 = V_274 ;
break;
}
}
F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
static int F_315 ( struct V_1 * V_2 ,
enum V_634 V_273 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_623 * V_624 ;
F_11 ( V_2 , 4 , L_268 ) ;
F_27 ( V_52 , 2 , L_268 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_626 . V_497 ) ;
V_106 = F_255 ( V_2 , V_635 ,
sizeof( struct V_636 ) +
sizeof( struct V_623 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
V_624 = & V_123 -> V_110 . V_461 . V_110 . V_625 ;
V_624 -> V_630 = V_273 ;
V_26 = F_251 ( V_2 , V_106 , F_314 ,
NULL ) ;
F_27 ( V_52 , 2 , L_255 , V_26 ) ;
return V_26 ;
}
int F_316 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
F_11 ( V_2 , 4 , L_269 ) ;
if ( ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) &&
F_317 ( V_2 , V_635 ) ) {
V_26 = F_315 ( V_2 ,
V_2 -> V_49 . V_273 ) ;
if ( V_26 ) {
F_51 ( 3 ,
L_270 ,
V_2 -> V_72 -> V_73 . V_626 . V_497 ,
V_26 ) ;
}
} else if ( V_2 -> V_49 . V_273 != V_274 ) {
V_2 -> V_49 . V_273 = V_274 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_260
L_261 ) ;
V_26 = - V_338 ;
}
return V_26 ;
}
void F_318 ( struct V_607 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_612 ;
F_11 ( V_2 , 4 , L_271 ) ;
V_2 -> V_508 . V_535 ++ ;
F_55 ( V_2 ) ;
}
int F_319 ( struct V_607 * V_73 , int V_637 , int V_638 )
{
struct V_1 * V_2 = V_73 -> V_612 ;
int V_26 = 0 ;
switch ( V_638 ) {
case V_639 :
V_26 = V_640 ;
if ( ( V_2 -> V_3 . V_10 != V_13 ) &&
( V_2 -> V_3 . V_10 != V_641 ) &&
( V_2 -> V_3 . V_10 != V_14 ) )
V_26 |= V_642 ;
break;
case V_643 :
V_26 = V_644 | V_645 | V_646 |
V_647 | V_648 | V_649 | V_650 |
V_651 ;
break;
case V_652 :
V_26 = ( V_73 -> V_617 [ 0 ] << 16 ) | ( V_73 -> V_617 [ 1 ] << 8 ) |
V_73 -> V_617 [ 2 ] ;
V_26 = ( V_26 >> 5 ) & 0xFFFF ;
break;
case V_653 :
V_26 = ( V_73 -> V_617 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_654 :
V_26 = V_655 ;
break;
case V_656 :
V_26 = V_657 | V_658 | V_659 | V_660 |
V_661 | V_662 ;
break;
case V_663 :
break;
case V_664 :
break;
case V_665 :
break;
case V_666 :
break;
case V_667 :
V_26 = V_2 -> V_508 . V_668 ;
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
case V_675 :
break;
default:
break;
}
return V_26 ;
}
static int F_320 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_147 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_379 )
{
V_170 V_676 , V_677 ;
F_11 ( V_2 , 4 , L_272 ) ;
memcpy ( V_106 -> V_110 , V_459 , V_386 ) ;
memcpy ( F_250 ( V_106 -> V_110 ) ,
& V_2 -> V_352 . V_412 , V_368 ) ;
V_676 = ( V_678 ) V_386 + V_147 ;
V_677 = ( V_678 ) V_147 ;
memcpy ( F_321 ( V_106 -> V_110 ) , & V_676 , 2 ) ;
memcpy ( F_322 ( V_106 -> V_110 ) , & V_677 , 2 ) ;
memcpy ( F_323 ( V_106 -> V_110 ) , & V_677 , 2 ) ;
memcpy ( F_324 ( V_106 -> V_110 ) , & V_677 , 2 ) ;
return F_174 ( V_2 , V_386 + V_147 , V_106 ,
F_175 , V_379 ) ;
}
static int F_325 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_679 )
{
struct V_122 * V_123 ;
struct V_680 * V_681 ;
struct V_682 * V_683 ;
unsigned char * V_110 ;
V_169 V_572 ;
F_11 ( V_2 , 3 , L_273 ) ;
V_123 = (struct V_122 * ) V_679 ;
V_110 = ( unsigned char * ) ( ( char * ) V_123 - V_118 -> V_168 ) ;
V_681 = (struct V_680 * ) V_118 -> V_382 ;
V_683 = & V_123 -> V_110 . V_461 . V_110 . V_683 ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_274 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
if ( V_123 -> V_110 . V_461 . V_126 . V_132 ) {
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_461 . V_126 . V_132 ;
F_35 ( V_2 , 4 , L_275 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
V_572 = * ( ( V_169 * ) F_322 ( V_110 ) ) ;
if ( V_123 -> V_110 . V_461 . V_126 . V_472 == 1 )
V_572 -= ( V_169 ) ( ( char * ) & V_683 -> V_110 - ( char * ) V_123 ) ;
else
V_572 -= ( V_169 ) ( ( char * ) & V_683 -> V_684 - ( char * ) V_123 ) ;
if ( ( V_681 -> V_685 - V_681 -> V_686 ) < V_572 ) {
F_35 ( V_2 , 4 , L_276 , - V_39 ) ;
V_123 -> V_126 . V_132 = - V_39 ;
return 0 ;
}
F_35 ( V_2 , 4 , L_277 ,
V_123 -> V_110 . V_461 . V_126 . V_471 ) ;
F_35 ( V_2 , 4 , L_278 ,
V_123 -> V_110 . V_461 . V_126 . V_472 ) ;
if ( V_123 -> V_110 . V_461 . V_126 . V_472 == 1 ) {
memcpy ( V_681 -> V_687 + V_681 -> V_686 ,
( char * ) V_683 ,
V_572 + F_326 ( struct V_682 , V_110 ) ) ;
V_681 -> V_686 += F_326 ( struct V_682 , V_110 ) ;
} else {
memcpy ( V_681 -> V_687 + V_681 -> V_686 ,
( char * ) & V_683 -> V_684 , V_572 ) ;
}
V_681 -> V_686 += V_572 ;
F_35 ( V_2 , 4 , L_279 ,
V_123 -> V_110 . V_461 . V_126 . V_471 ) ;
F_35 ( V_2 , 4 , L_280 ,
V_123 -> V_110 . V_461 . V_126 . V_472 ) ;
if ( V_123 -> V_110 . V_461 . V_126 . V_472 <
V_123 -> V_110 . V_461 . V_126 . V_471 )
return 1 ;
return 0 ;
}
int F_327 ( struct V_1 * V_2 , char T_4 * V_687 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_688 * V_689 ;
int V_690 ;
struct V_680 V_681 = { 0 , } ;
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_281 ) ;
if ( V_2 -> V_3 . V_4 )
return - V_338 ;
if ( ( ! F_317 ( V_2 , V_691 ) ) &&
( ! V_2 -> V_49 . V_305 ) ) {
return - V_338 ;
}
if ( F_328 ( & V_690 , V_687 + sizeof( int ) , sizeof( int ) ) )
return - V_692 ;
V_689 = F_329 ( V_687 , V_690 + sizeof( struct V_693 ) ) ;
if ( F_98 ( V_689 ) ) {
F_11 ( V_2 , 2 , L_282 ) ;
return F_99 ( V_689 ) ;
}
V_681 . V_685 = V_689 -> V_126 . V_572 ;
V_681 . V_687 = F_15 ( V_681 . V_685 , V_38 ) ;
if ( ! V_681 . V_687 ) {
F_20 ( V_689 ) ;
return - V_39 ;
}
V_681 . V_686 = sizeof( struct V_693 ) ;
V_106 = F_255 ( V_2 , V_691 ,
V_694 + V_690 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_386 ) ;
memcpy ( & V_123 -> V_110 . V_461 . V_110 . V_683 , & V_689 -> V_123 , V_690 ) ;
V_26 = F_320 ( V_2 , V_106 , V_695 + V_690 ,
F_325 , ( void * ) & V_681 ) ;
if ( V_26 )
F_51 ( 2 , L_283 ,
F_64 ( V_2 ) , V_26 ) ;
else {
if ( F_330 ( V_687 , V_681 . V_687 , V_681 . V_685 ) )
V_26 = - V_692 ;
}
F_20 ( V_689 ) ;
F_20 ( V_681 . V_687 ) ;
return V_26 ;
}
static inline int F_331 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
return 2 ;
default:
return 0 ;
}
}
static void F_332 ( struct V_1 * V_2 )
{
int V_26 ;
int V_239 ;
char * V_344 ;
struct V_178 * V_696 ;
int V_697 = 0 ;
F_24 ( V_52 , 2 , L_284 ) ;
V_696 = F_26 ( V_2 ) ;
if ( ! V_696 -> V_698 ) {
V_697 = 1 ;
V_26 = F_333 ( V_696 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_60;
}
}
V_26 = F_148 ( V_2 , ( void * * ) & V_344 , & V_239 ) ;
if ( V_26 ) {
F_51 ( 2 , L_285 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_699;
}
F_151 ( V_2 , V_344 ) ;
F_152 ( V_2 , V_344 ) ;
F_20 ( V_344 ) ;
V_26 = F_334 ( V_696 , & V_2 -> V_700 ) ;
if ( V_26 )
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_27 ( V_52 , 2 , L_286 , V_2 -> V_700 . V_701 ) ;
F_27 ( V_52 , 2 , L_287 , V_2 -> V_700 . V_702 ) ;
F_27 ( V_52 , 2 , L_287 , V_2 -> V_700 . V_703 ) ;
F_27 ( V_52 , 2 , L_288 , V_2 -> V_700 . V_704 ) ;
if ( ! ( ( V_2 -> V_700 . V_701 != V_705 ) ||
( ( V_2 -> V_700 . V_702 & V_706 ) == 0 ) ||
( ( V_2 -> V_700 . V_703 & V_707 ) == 0 ) ) ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_289 ) ;
} else {
V_2 -> V_49 . V_50 = V_546 ;
}
V_699:
if ( V_697 == 1 )
F_335 ( V_696 ) ;
V_60:
return;
}
static inline void F_336 ( struct V_1 * V_2 ,
struct V_56 * * V_708 ,
void (* * F_337) ( struct V_178 * , int , unsigned long ) ) {
int V_33 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
int V_168 = V_55 *
( V_2 -> V_35 . V_59 - 1 ) ;
V_33 = V_55 * ( V_2 -> V_35 . V_59 - 1 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_708 [ V_168 + V_33 ] = (struct V_56 * )
F_289 ( V_2 -> V_35 . V_53 -> V_65 [ V_33 ] . V_66 ) ;
}
F_337 [ V_2 -> V_35 . V_59 - 1 ] = NULL ;
}
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_709 V_710 ;
char * V_711 ;
struct V_56 * * V_708 ;
void (* * F_337) ( struct V_178 * , int , unsigned long );
struct V_56 * * V_712 ;
int V_33 , V_34 , V_713 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_290 ) ;
V_711 = F_15 ( V_55 * sizeof( char ) ,
V_38 ) ;
if ( ! V_711 ) {
V_26 = - V_39 ;
goto V_714;
}
F_216 ( V_2 , V_711 ) ;
F_220 ( V_2 , V_711 ) ;
V_708 = F_15 ( V_2 -> V_35 . V_59 *
V_55 * sizeof( void * ) ,
V_38 ) ;
if ( ! V_708 ) {
V_26 = - V_39 ;
goto V_715;
}
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_708 [ V_33 ] = (struct V_56 * )
F_289 ( V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_66 ) ;
}
F_337 = F_15 ( sizeof( void * ) * V_2 -> V_35 . V_59 ,
V_38 ) ;
if ( ! F_337 ) {
V_26 = - V_39 ;
goto V_716;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_59 ; ++ V_33 )
F_337 [ V_33 ] = V_2 -> V_280 . V_717 ;
F_336 ( V_2 , V_708 , F_337 ) ;
V_712 =
F_15 ( V_2 -> V_35 . V_68 * V_55 *
sizeof( void * ) , V_38 ) ;
if ( ! V_712 ) {
V_26 = - V_39 ;
goto V_718;
}
for ( V_33 = 0 , V_713 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 )
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 , ++ V_713 ) {
V_712 [ V_713 ] = (struct V_56 * ) F_289 (
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] -> V_66 ) ;
}
memset ( & V_710 , 0 , sizeof( struct V_709 ) ) ;
V_710 . V_179 = F_26 ( V_2 ) ;
V_710 . V_719 = F_331 ( V_2 ) ;
V_710 . V_720 = 0 ;
V_710 . V_711 = V_711 ;
V_710 . V_721 = V_2 -> V_35 . V_59 ;
V_710 . V_722 = V_2 -> V_35 . V_68 ;
V_710 . V_723 = V_2 -> V_280 . V_723 ;
V_710 . V_724 = V_2 -> V_280 . V_724 ;
V_710 . V_725 = F_337 ;
V_710 . V_726 = ( unsigned long ) V_2 ;
V_710 . V_727 = ( void * * ) V_708 ;
V_710 . V_728 = ( void * * ) V_712 ;
V_710 . V_729 = V_2 -> V_35 . V_67 ;
V_710 . V_730 =
( V_2 -> V_3 . type == V_6 ) ? 8 : 32 ;
if ( F_42 ( & V_2 -> V_35 . V_44 , V_333 ,
V_329 ) == V_333 ) {
V_26 = F_338 ( & V_710 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_333 ) ;
goto V_60;
}
V_26 = F_339 ( & V_710 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_333 ) ;
F_147 ( F_26 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_49 . V_50 ) {
case V_51 :
F_72 ( & V_2 -> V_72 -> V_73 , L_291 ) ;
break;
case V_275 :
F_72 ( & V_2 -> V_72 -> V_73 , L_292 ) ;
break;
default:
break;
}
V_60:
F_20 ( V_712 ) ;
V_718:
F_20 ( F_337 ) ;
V_716:
F_20 ( V_708 ) ;
V_715:
F_20 ( V_711 ) ;
V_714:
return V_26 ;
}
static void F_340 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_293 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
F_115 ( & V_2 -> V_107 ) ;
F_115 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_73 )
F_341 ( V_2 -> V_73 ) ;
F_20 ( V_2 -> V_288 ) ;
F_112 ( V_2 ) ;
F_342 ( & V_2 -> V_299 ) ;
F_20 ( V_2 ) ;
}
static int F_343 ( const char * V_217 , struct V_731 * V_732 ,
unsigned long V_733 )
{
return F_344 ( V_732 , V_733 ,
& V_734 , 3 , V_217 ) ;
}
int F_345 ( struct V_1 * V_2 )
{
int V_735 = 0 ;
int V_26 ;
F_24 ( V_52 , 2 , L_294 ) ;
F_43 ( & V_2 -> V_513 , 0 ) ;
F_116 ( V_2 ) ;
V_736:
if ( V_735 )
F_51 ( 2 , L_295 ,
F_52 ( & V_2 -> V_72 -> V_73 ) ) ;
F_335 ( F_26 ( V_2 ) ) ;
F_335 ( F_346 ( V_2 ) ) ;
F_335 ( F_135 ( V_2 ) ) ;
V_26 = F_333 ( F_135 ( V_2 ) ) ;
if ( V_26 )
goto V_737;
V_26 = F_333 ( F_346 ( V_2 ) ) ;
if ( V_26 )
goto V_737;
V_26 = F_333 ( F_26 ( V_2 ) ) ;
if ( V_26 )
goto V_737;
V_26 = F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
V_737:
if ( V_26 == - V_322 ) {
F_24 ( V_52 , 2 , L_296 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
if ( ++ V_735 > 3 )
goto V_60;
else
goto V_736;
}
F_332 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
V_26 = F_157 ( & V_2 -> V_107 , F_169 ) ;
if ( V_26 == - V_322 ) {
F_24 ( V_52 , 2 , L_297 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
if ( -- V_735 < 0 )
goto V_60;
else
goto V_736;
}
V_26 = F_157 ( & V_2 -> V_142 , F_166 ) ;
if ( V_26 == - V_322 ) {
F_24 ( V_52 , 2 , L_298 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
if ( -- V_735 < 0 )
goto V_60;
else
goto V_736;
}
V_2 -> V_116 = 0 ;
V_26 = F_226 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_60;
}
V_2 -> V_49 . V_475 . V_465 = 0 ;
V_2 -> V_49 . V_464 . V_465 = 0 ;
V_2 -> V_3 . V_479 = 0 ;
F_258 ( V_2 , V_389 ) ;
if ( F_310 ( V_2 , V_738 ) )
F_256 ( V_2 ) ;
if ( F_317 ( V_2 , V_739 ) )
F_260 ( V_2 ) ;
return 0 ;
V_60:
F_50 ( & V_2 -> V_72 -> V_73 , L_101
L_102 ) ;
F_51 ( 2 , L_299 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
return V_26 ;
}
static inline int F_347 ( struct V_438 * V_740 ,
struct V_741 * V_231 ,
struct V_218 * * V_742 , int V_168 , int * V_743 , int V_572 )
{
struct V_434 * V_434 = F_239 ( V_231 -> V_236 ) ;
if ( * V_742 == NULL ) {
if ( V_740 -> V_245 ) {
* V_742 = V_740 -> V_245 ;
V_740 -> V_245 = NULL ;
} else {
* V_742 = F_243 ( V_439 + V_440 ) ;
if ( ! ( * V_742 ) )
return - V_39 ;
}
F_348 ( * V_742 , V_440 ) ;
if ( V_572 <= V_439 ) {
memcpy ( F_349 ( * V_742 , V_572 ) , V_231 -> V_236 + V_168 ,
V_572 ) ;
} else {
F_350 ( V_434 ) ;
memcpy ( F_349 ( * V_742 , V_439 ) ,
V_231 -> V_236 + V_168 , V_439 ) ;
F_351 ( * V_742 , * V_743 , V_434 ,
V_168 + V_439 ,
V_572 - V_439 ) ;
( * V_742 ) -> V_572 += V_572 - V_439 ;
( * V_742 ) -> V_147 += V_572 - V_439 ;
( * V_742 ) -> V_744 += V_572 - V_439 ;
( * V_743 ) ++ ;
}
} else {
F_350 ( V_434 ) ;
F_351 ( * V_742 , * V_743 , V_434 , V_168 , V_572 ) ;
( * V_742 ) -> V_572 += V_572 ;
( * V_742 ) -> V_147 += V_572 ;
( * V_742 ) -> V_744 += V_572 ;
( * V_743 ) ++ ;
}
return 0 ;
}
struct V_218 * F_352 ( struct V_1 * V_2 ,
struct V_438 * V_740 ,
struct V_741 * * V_745 , int * V_746 ,
struct V_590 * * V_126 )
{
struct V_741 * V_231 = * V_745 ;
struct V_56 * V_66 = V_740 -> V_66 ;
int V_168 = * V_746 ;
struct V_218 * V_219 = NULL ;
int V_747 = 0 ;
void * V_748 ;
int V_572 ;
int V_749 = 0 ;
int V_750 = 0 ;
int V_583 = 0 ;
if ( V_231 -> V_239 < V_168 + sizeof( struct V_590 ) ) {
if ( F_353 ( V_231 ) )
return NULL ;
V_231 ++ ;
V_168 = 0 ;
if ( V_231 -> V_239 < sizeof( struct V_590 ) )
return NULL ;
}
* V_126 = V_231 -> V_236 + V_168 ;
V_168 += sizeof( struct V_590 ) ;
switch ( ( * V_126 ) -> V_126 . V_751 . V_312 ) {
case V_752 :
V_747 = ( * V_126 ) -> V_126 . V_751 . V_753 ;
break;
case V_754 :
V_747 = ( * V_126 ) -> V_126 . V_594 . V_239 ;
if ( ( V_2 -> V_3 . V_10 == V_16 ) ||
( V_2 -> V_3 . V_10 == V_12 ) )
V_749 = V_755 ;
else
V_749 = V_440 ;
break;
case V_756 :
V_747 = ( * V_126 ) -> V_126 . V_757 . V_758 ;
V_749 = sizeof( struct V_590 ) ;
break;
default:
break;
}
if ( ! V_747 )
return NULL ;
if ( ( ( V_747 >= V_2 -> V_49 . V_271 ) &&
( ! ( V_2 -> V_3 . type == V_9 ) ) &&
( ! F_34 ( & V_2 -> V_513 ) ) ) ||
( V_2 -> V_49 . V_50 == V_51 ) ) {
V_750 = 1 ;
} else {
V_219 = F_243 ( V_747 + V_749 ) ;
if ( ! V_219 )
goto V_759;
if ( V_749 )
F_348 ( V_219 , V_749 ) ;
}
V_748 = V_231 -> V_236 + V_168 ;
while ( V_747 ) {
V_572 = F_354 ( V_747 , ( int ) ( V_231 -> V_239 - V_168 ) ) ;
if ( V_572 ) {
if ( V_750 ) {
if ( F_347 ( V_740 , V_231 ,
& V_219 , V_168 , & V_583 , V_572 ) )
goto V_759;
} else {
memcpy ( F_349 ( V_219 , V_572 ) , V_748 ,
V_572 ) ;
}
}
V_747 -= V_572 ;
if ( V_747 ) {
if ( F_353 ( V_231 ) ) {
F_11 ( V_2 , 4 , L_300 ) ;
F_355 ( V_2 , 2 , V_66 , sizeof( void * ) ) ;
F_109 ( V_219 ) ;
V_2 -> V_508 . V_668 ++ ;
return NULL ;
}
V_231 ++ ;
V_168 = 0 ;
V_748 = V_231 -> V_236 ;
} else {
V_168 += V_572 ;
}
}
* V_745 = V_231 ;
* V_746 = V_168 ;
if ( V_750 && V_2 -> V_49 . V_270 ) {
V_2 -> V_436 . V_760 ++ ;
V_2 -> V_436 . V_761 += F_296 ( V_219 ) -> V_574 ;
}
return V_219 ;
V_759:
if ( F_356 () ) {
F_11 ( V_2 , 2 , L_301 ) ;
}
V_2 -> V_508 . V_509 ++ ;
return NULL ;
}
static void F_357 ( void )
{
int V_762 ;
for ( V_762 = 0 ; V_762 < V_763 ; V_762 ++ ) {
F_358 ( V_764 [ V_762 ] . V_312 ) ;
V_764 [ V_762 ] . V_312 = NULL ;
}
}
void F_359 ( T_5 * V_312 , int V_371 , char * V_765 , ... )
{
char V_766 [ 32 ] ;
T_6 args ;
if ( V_371 > V_312 -> V_371 )
return;
va_start ( args , V_765 ) ;
vsnprintf ( V_766 , sizeof( V_766 ) , V_765 , args ) ;
va_end ( args ) ;
F_360 ( V_312 , V_371 , V_766 ) ;
}
static int F_361 ( void )
{
int V_336 ;
int V_762 ;
for ( V_762 = 0 ; V_762 < V_763 ; V_762 ++ ) {
V_764 [ V_762 ] . V_312 = F_362 ( V_764 [ V_762 ] . V_497 ,
V_764 [ V_762 ] . V_767 ,
V_764 [ V_762 ] . V_768 ,
V_764 [ V_762 ] . V_147 ) ;
if ( V_764 [ V_762 ] . V_312 == NULL ) {
F_357 () ;
return - V_39 ;
}
V_336 = F_363 ( V_764 [ V_762 ] . V_312 , V_764 [ V_762 ] . V_769 ) ;
if ( V_336 ) {
F_357 () ;
return V_336 ;
}
F_364 ( V_764 [ V_762 ] . V_312 , V_764 [ V_762 ] . V_371 ) ;
}
return 0 ;
}
int F_365 ( struct V_1 * V_2 ,
enum V_770 V_280 )
{
int V_26 = 0 ;
switch ( V_280 ) {
case V_771 :
V_2 -> V_280 . V_772 = F_366 (
F_367 ( V_773 ) ,
L_302 ) ;
break;
case V_774 :
V_2 -> V_280 . V_772 = F_366 (
F_367 ( V_775 ) ,
L_303 ) ;
break;
}
if ( ! V_2 -> V_280 . V_772 ) {
F_30 ( & V_2 -> V_72 -> V_73 , L_304
L_305 , V_280 ) ;
V_26 = - V_401 ;
}
return V_26 ;
}
void F_368 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 . V_305 )
F_369 ( V_775 ) ;
else
F_369 ( V_773 ) ;
V_2 -> V_280 . V_772 = NULL ;
}
static int F_370 ( struct V_776 * V_72 )
{
struct V_1 * V_2 ;
struct V_731 * V_73 ;
int V_26 ;
unsigned long V_21 ;
char V_777 [ 20 ] ;
F_24 ( V_52 , 2 , L_306 ) ;
V_73 = & V_72 -> V_73 ;
if ( ! F_371 ( V_73 ) )
return - V_778 ;
F_27 ( V_52 , 2 , L_186 , F_52 ( & V_72 -> V_73 ) ) ;
V_2 = F_132 () ;
if ( ! V_2 ) {
F_27 ( V_52 , 2 , L_35 , - V_39 ) ;
V_26 = - V_39 ;
goto V_779;
}
snprintf ( V_777 , sizeof( V_777 ) , L_307 ,
F_52 ( & V_72 -> V_73 ) ) ;
V_2 -> V_780 = F_362 ( V_777 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_780 ) {
F_27 ( V_52 , 2 , L_186 , L_308 ) ;
V_26 = - V_39 ;
goto V_781;
}
F_363 ( V_2 -> V_780 , & V_782 ) ;
V_2 -> V_107 . V_112 = V_72 -> V_179 [ 0 ] ;
V_2 -> V_142 . V_112 = V_72 -> V_179 [ 1 ] ;
V_2 -> V_110 . V_112 = V_72 -> V_179 [ 2 ] ;
F_372 ( & V_72 -> V_73 , V_2 ) ;
V_2 -> V_72 = V_72 ;
V_72 -> V_179 [ 0 ] -> V_783 = F_100 ;
V_72 -> V_179 [ 1 ] -> V_783 = F_100 ;
V_72 -> V_179 [ 2 ] -> V_783 = F_100 ;
V_26 = F_134 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_784;
}
V_26 = F_125 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
goto V_784;
}
if ( V_2 -> V_3 . type == V_9 )
V_26 = F_373 ( V_73 ) ;
else
V_26 = F_374 ( V_73 ) ;
if ( V_26 )
goto V_784;
switch ( V_2 -> V_3 . type ) {
case V_9 :
case V_7 :
V_26 = F_365 ( V_2 , V_774 ) ;
if ( V_26 )
goto V_785;
V_26 = V_2 -> V_280 . V_772 -> V_786 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_787;
case V_5 :
case V_8 :
default:
break;
}
F_375 ( & V_788 . V_789 , V_21 ) ;
F_84 ( & V_2 -> V_31 , & V_788 . V_31 ) ;
F_376 ( & V_788 . V_789 , V_21 ) ;
F_332 ( V_2 ) ;
return 0 ;
V_787:
F_368 ( V_2 ) ;
V_785:
if ( V_2 -> V_3 . type == V_9 )
F_377 ( V_73 ) ;
else
F_378 ( V_73 ) ;
V_784:
F_358 ( V_2 -> V_780 ) ;
V_781:
F_340 ( V_2 ) ;
V_779:
F_379 ( V_73 ) ;
return V_26 ;
}
static void F_380 ( struct V_776 * V_72 )
{
unsigned long V_21 ;
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
F_24 ( V_52 , 2 , L_309 ) ;
if ( V_2 -> V_3 . type == V_9 ) {
F_377 ( & V_72 -> V_73 ) ;
} else {
F_378 ( & V_72 -> V_73 ) ;
}
if ( V_2 -> V_280 . V_772 ) {
V_2 -> V_280 . V_772 -> remove ( V_72 ) ;
F_368 ( V_2 ) ;
}
F_358 ( V_2 -> V_780 ) ;
F_375 ( & V_788 . V_789 , V_21 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_376 ( & V_788 . V_789 , V_21 ) ;
F_340 ( V_2 ) ;
F_372 ( & V_72 -> V_73 , NULL ) ;
F_379 ( & V_72 -> V_73 ) ;
return;
}
static int F_382 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
int V_26 = 0 ;
int V_790 ;
if ( ! V_2 -> V_280 . V_772 ) {
if ( V_2 -> V_3 . type == V_6 )
V_790 = V_771 ;
else
V_790 = V_774 ;
V_26 = F_365 ( V_2 , V_790 ) ;
if ( V_26 )
goto V_791;
V_26 = V_2 -> V_280 . V_772 -> V_786 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_791;
}
V_26 = V_2 -> V_280 . V_772 -> V_792 ( V_72 ) ;
V_791:
return V_26 ;
}
static int F_383 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
return V_2 -> V_280 . V_772 -> V_793 ( V_72 ) ;
}
static void F_384 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_794 )
V_2 -> V_280 . V_772 -> V_794 ( V_72 ) ;
}
static int F_385 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_795 )
return V_2 -> V_280 . V_772 -> V_795 ( V_72 ) ;
return 0 ;
}
static void F_386 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_796 )
V_2 -> V_280 . V_772 -> V_796 ( V_72 ) ;
}
static int F_387 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_797 )
return V_2 -> V_280 . V_772 -> V_797 ( V_72 ) ;
return 0 ;
}
static int F_388 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_798 )
return V_2 -> V_280 . V_772 -> V_798 ( V_72 ) ;
return 0 ;
}
static int F_389 ( struct V_776 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_280 . V_772 &&
V_2 -> V_280 . V_772 -> V_799 )
return V_2 -> V_280 . V_772 -> V_799 ( V_72 ) ;
return 0 ;
}
static T_7
F_390 ( struct V_800 * V_801 , const char * V_217 ,
T_8 V_151 )
{
int V_791 ;
V_791 = F_343 ( V_217 , V_802 ,
V_803 . V_733 ) ;
if ( V_791 )
return V_791 ;
else
return V_151 ;
}
int F_391 ( struct V_607 * V_73 , int V_804 )
{
switch ( V_804 ) {
case V_805 :
return ( sizeof( V_806 ) / V_807 ) ;
default:
return - V_401 ;
}
}
void F_392 ( struct V_607 * V_73 ,
struct V_808 * V_508 , T_9 * V_110 )
{
struct V_1 * V_2 = V_73 -> V_612 ;
V_110 [ 0 ] = V_2 -> V_508 . V_809 -
V_2 -> V_436 . V_810 ;
V_110 [ 1 ] = V_2 -> V_436 . V_811 ;
V_110 [ 2 ] = V_2 -> V_508 . V_812 -
V_2 -> V_436 . V_813 ;
V_110 [ 3 ] = V_2 -> V_436 . V_537 ;
V_110 [ 4 ] = V_2 -> V_508 . V_812 - V_2 -> V_436 . V_813
- V_2 -> V_436 . V_598 ;
V_110 [ 5 ] = V_2 -> V_436 . V_537 - V_2 -> V_436 . V_541 ;
V_110 [ 6 ] = V_2 -> V_436 . V_598 ;
V_110 [ 7 ] = V_2 -> V_436 . V_541 ;
V_110 [ 8 ] = V_2 -> V_436 . V_814 ;
V_110 [ 9 ] = V_2 -> V_436 . V_815 ;
V_110 [ 10 ] = V_2 -> V_436 . V_760 ;
V_110 [ 11 ] = V_2 -> V_436 . V_761 ;
V_110 [ 12 ] = V_2 -> V_436 . V_437 ;
V_110 [ 13 ] = ( V_2 -> V_436 . V_816 >> 10 ) ;
V_110 [ 14 ] = V_2 -> V_436 . V_817 ;
V_110 [ 15 ] = V_2 -> V_436 . V_523 ;
V_110 [ 16 ] = V_2 -> V_436 . V_526 ;
V_110 [ 17 ] = V_525 ;
V_110 [ 18 ] = V_522 ;
V_110 [ 19 ] = F_34 ( & V_2 -> V_35 . V_70 [ 0 ] -> V_444 ) ;
V_110 [ 20 ] = ( V_2 -> V_35 . V_68 > 1 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 1 ] -> V_444 ) : 0 ;
V_110 [ 21 ] = ( V_2 -> V_35 . V_68 > 2 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 2 ] -> V_444 ) : 0 ;
V_110 [ 22 ] = ( V_2 -> V_35 . V_68 > 3 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 3 ] -> V_444 ) : 0 ;
V_110 [ 23 ] = V_2 -> V_436 . V_818 ;
V_110 [ 24 ] = V_2 -> V_436 . V_819 ;
V_110 [ 25 ] = V_2 -> V_436 . V_517 ;
V_110 [ 26 ] = V_2 -> V_436 . V_515 ;
V_110 [ 27 ] = V_2 -> V_436 . V_560 ;
V_110 [ 28 ] = V_2 -> V_436 . V_556 ;
V_110 [ 29 ] = V_2 -> V_436 . V_820 ;
V_110 [ 30 ] = V_2 -> V_436 . V_821 ;
V_110 [ 31 ] = V_2 -> V_436 . V_534 ;
V_110 [ 32 ] = V_2 -> V_436 . V_530 ;
V_110 [ 33 ] = V_2 -> V_436 . V_822 ;
V_110 [ 34 ] = V_2 -> V_436 . V_823 ;
V_110 [ 35 ] = V_2 -> V_436 . V_548 ;
V_110 [ 36 ] = V_2 -> V_436 . V_552 ;
}
void F_393 ( struct V_607 * V_73 , V_678 V_804 , T_3 * V_110 )
{
switch ( V_804 ) {
case V_805 :
memcpy ( V_110 , & V_806 ,
sizeof( V_806 ) ) ;
break;
default:
F_58 ( 1 ) ;
break;
}
}
void F_394 ( struct V_607 * V_73 ,
struct V_824 * V_3 )
{
struct V_1 * V_2 = V_73 -> V_612 ;
if ( V_2 -> V_49 . V_305 )
strcpy ( V_3 -> V_825 , L_303 ) ;
else
strcpy ( V_3 -> V_825 , L_302 ) ;
strcpy ( V_3 -> V_826 , L_310 ) ;
strcpy ( V_3 -> V_827 , V_2 -> V_3 . V_300 ) ;
sprintf ( V_3 -> V_828 , L_311 ,
F_395 ( V_2 ) ,
F_396 ( V_2 ) ,
F_397 ( V_2 ) ) ;
}
int F_398 ( struct V_607 * V_829 ,
struct V_830 * V_831 )
{
struct V_1 * V_2 = V_829 -> V_612 ;
enum V_446 V_10 ;
if ( ( V_2 -> V_3 . type == V_6 ) || ( V_2 -> V_3 . V_4 ) )
V_10 = V_14 ;
else
V_10 = V_2 -> V_3 . V_10 ;
V_831 -> V_832 = V_833 ;
V_831 -> V_834 = V_835 ;
V_831 -> V_836 = V_837 ;
V_831 -> V_838 = V_839 ;
V_831 -> V_840 = V_841 ;
switch ( V_10 ) {
case V_11 :
case V_15 :
V_831 -> V_834 |= V_842 |
V_843 |
V_844 |
V_845 |
V_846 ;
V_831 -> V_836 |= V_847 |
V_848 |
V_849 |
V_850 |
V_851 ;
V_831 -> V_852 = V_853 ;
V_831 -> V_854 = V_855 ;
break;
case V_13 :
case V_17 :
V_831 -> V_834 |= V_842 |
V_843 |
V_844 |
V_845 |
V_856 |
V_857 |
V_858 ;
V_831 -> V_836 |= V_847 |
V_848 |
V_849 |
V_850 |
V_859 |
V_860 |
V_861 ;
V_831 -> V_852 = V_862 ;
V_831 -> V_854 = V_863 ;
break;
case V_14 :
V_831 -> V_834 |= V_842 |
V_843 |
V_844 |
V_845 |
V_856 |
V_857 |
V_864 |
V_858 ;
V_831 -> V_836 |= V_847 |
V_848 |
V_849 |
V_850 |
V_859 |
V_860 |
V_865 |
V_861 ;
V_831 -> V_852 = V_866 ;
V_831 -> V_854 = V_863 ;
break;
default:
V_831 -> V_834 |= V_842 |
V_843 |
V_846 ;
V_831 -> V_836 |= V_847 |
V_848 |
V_851 ;
V_831 -> V_852 = V_867 ;
V_831 -> V_854 = V_855 ;
}
return 0 ;
}
static int T_10 F_399 ( void )
{
int V_26 ;
F_400 ( L_312 ) ;
F_119 ( & V_788 . V_31 ) ;
F_401 ( & V_788 . V_789 ) ;
V_26 = F_361 () ;
if ( V_26 )
goto V_868;
V_26 = F_402 ( & V_734 ) ;
if ( V_26 )
goto V_869;
V_26 = F_403 ( & V_803 ) ;
if ( V_26 )
goto V_870;
V_26 = F_404 ( & V_803 . V_825 ,
& V_871 ) ;
if ( V_26 )
goto V_872;
V_802 = F_405 ( L_313 ) ;
V_26 = F_98 ( V_802 ) ? F_99 ( V_802 ) : 0 ;
if ( V_26 )
goto V_873;
V_238 = F_406 ( L_314 ,
sizeof( struct V_590 ) + V_440 , 64 , 0 , NULL ) ;
if ( ! V_238 ) {
V_26 = - V_39 ;
goto V_874;
}
V_94 = F_406 ( L_315 ,
sizeof( struct V_89 ) , 0 , 0 , NULL ) ;
if ( ! V_94 ) {
V_26 = - V_39 ;
goto V_875;
}
return 0 ;
V_875:
F_407 ( V_238 ) ;
V_874:
F_408 ( V_802 ) ;
V_873:
F_409 ( & V_803 . V_825 ,
& V_871 ) ;
V_872:
F_410 ( & V_803 ) ;
V_870:
F_411 ( & V_734 ) ;
V_869:
F_51 ( 2 , L_316 , V_26 ) ;
F_357 () ;
V_868:
F_412 ( L_317 ) ;
return V_26 ;
}
static void T_11 F_413 ( void )
{
F_408 ( V_802 ) ;
F_409 ( & V_803 . V_825 ,
& V_871 ) ;
F_410 ( & V_803 ) ;
F_411 ( & V_734 ) ;
F_407 ( V_94 ) ;
F_407 ( V_238 ) ;
F_357 () ;
F_400 ( L_318 ) ;
}
