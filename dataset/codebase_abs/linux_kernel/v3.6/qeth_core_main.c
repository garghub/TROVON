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
V_2 -> V_49 . V_263 = 0 ;
V_2 -> V_49 . V_264 = V_265 ;
V_2 -> V_49 . V_266 = 0 ;
V_2 -> V_49 . V_267 = V_268 ;
V_2 -> V_49 . V_269 = V_270 ;
V_2 -> V_49 . V_50 = V_271 ;
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
static void F_122 ( struct V_272 * V_273 )
{
struct V_274 * V_275 ;
struct V_1 * V_2 = F_123 ( V_273 , struct V_1 ,
V_177 ) ;
F_11 ( V_2 , 2 , L_116 ) ;
if ( V_2 -> V_107 . V_44 != V_108 &&
V_2 -> V_142 . V_44 != V_108 )
return;
if ( F_121 ( V_2 , V_176 ) ) {
V_275 = F_124 ( V_2 -> V_276 -> V_277 , ( void * ) V_2 ,
L_117 ) ;
if ( F_98 ( V_275 ) ) {
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
F_87 ( & V_2 -> V_278 ) ;
F_87 ( & V_2 -> V_279 ) ;
F_87 ( & V_2 -> V_141 ) ;
F_87 ( & V_2 -> V_280 ) ;
F_87 ( & V_2 -> V_22 ) ;
F_126 ( & V_2 -> V_281 ) ;
F_126 ( & V_2 -> V_282 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_27 = 0 ;
F_127 ( & V_2 -> V_177 , F_122 ) ;
F_119 ( & V_2 -> V_283 ) ;
F_119 ( V_2 -> V_284 ) ;
F_119 ( & V_2 -> V_171 ) ;
F_88 ( & V_2 -> V_25 ) ;
F_120 ( V_2 ) ;
F_119 ( & V_2 -> V_285 . V_286 ) ;
V_2 -> V_285 . V_287 = 0 ;
V_2 -> V_285 . V_288 = 0 ;
V_2 -> V_285 . V_289 = 0 ;
F_118 ( V_2 ) ;
F_128 ( & V_2 -> V_243 , V_290 ) ;
return 0 ;
}
static void F_129 ( struct V_291 * V_292 , struct V_293 * V_294 )
{
struct V_1 * V_2 = F_123 ( V_294 , struct V_1 ,
V_295 ) ;
if ( V_2 -> V_3 . V_296 [ 0 ] )
F_130 ( V_292 , L_119 ,
F_131 ( V_2 ) , V_2 -> V_3 . V_296 ) ;
}
static struct V_1 * F_132 ( void )
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
V_2 -> V_295 . V_302 = F_129 ;
F_133 ( & V_2 -> V_295 ) ;
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
static int F_134 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
F_24 ( V_52 , 2 , L_122 ) ;
V_2 -> V_35 . V_303 = V_304 ;
V_2 -> V_35 . V_254 = V_305 ;
while ( V_306 [ V_33 ] [ V_307 ] ) {
if ( ( F_135 ( V_2 ) -> V_308 . V_309 ==
V_306 [ V_33 ] [ V_310 ] ) &&
( F_135 ( V_2 ) -> V_308 . V_311 ==
V_306 [ V_33 ] [ V_307 ] ) ) {
V_2 -> V_3 . type = V_306 [ V_33 ] [ V_307 ] ;
V_2 -> V_35 . V_68 =
V_306 [ V_33 ] [ V_312 ] ;
V_2 -> V_35 . V_59 = 1 ;
V_2 -> V_3 . V_313 =
V_306 [ V_33 ] [ V_314 ] ;
F_116 ( V_2 ) ;
return 0 ;
}
V_33 ++ ;
}
V_2 -> V_3 . type = V_315 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_123
L_124 ) ;
return - V_316 ;
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
V_146 -> V_44 == V_205 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_205 )
return - V_319 ;
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
V_146 -> V_44 == V_207 , V_317 ) ;
if ( V_26 == - V_318 )
return V_26 ;
if ( V_146 -> V_44 != V_207 )
return - V_319 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_11 ( V_2 , 3 , L_127 ) ;
V_320 = F_140 ( & V_2 -> V_107 ) ;
V_321 = F_140 ( & V_2 -> V_142 ) ;
V_322 = F_140 ( & V_2 -> V_110 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_320 = 0 , V_321 = 0 , V_322 = 0 ;
F_11 ( V_2 , 3 , L_128 ) ;
V_320 = F_136 ( & V_2 -> V_107 ) ;
V_321 = F_136 ( & V_2 -> V_142 ) ;
V_322 = F_136 ( & V_2 -> V_110 ) ;
if ( V_320 )
return V_320 ;
if ( V_321 )
return V_321 ;
return V_322 ;
}
static int F_144 ( struct V_1 * V_2 , int V_323 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_129 ) ;
if ( V_323 )
V_26 = F_142 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_143 ( V_2 ) ;
}
int F_145 ( struct V_1 * V_2 , int V_324 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_130 ) ;
switch ( F_42 ( & V_2 -> V_35 . V_44 , V_325 ,
V_326 ) ) {
case V_325 :
if ( V_2 -> V_3 . type == V_6 )
V_26 = F_146 ( F_26 ( V_2 ) ,
V_327 ) ;
else
V_26 = F_146 ( F_26 ( V_2 ) ,
V_328 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_35 , V_26 ) ;
F_147 ( F_26 ( V_2 ) ) ;
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
break;
case V_326 :
return V_26 ;
default:
break;
}
V_26 = F_144 ( V_2 , V_324 ) ;
if ( V_26 )
F_35 ( V_2 , 3 , L_131 , V_26 ) ;
V_2 -> V_44 = V_45 ;
return V_26 ;
}
static int F_148 ( struct V_1 * V_2 , void * * V_66 ,
int * V_239 )
{
struct V_330 * V_330 ;
char * V_331 ;
int V_332 ;
struct V_145 * V_146 = & V_2 -> V_110 ;
unsigned long V_21 ;
V_330 = F_149 ( V_146 -> V_112 , V_333 ) ;
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
F_4 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
V_332 = F_150 ( V_146 -> V_112 , & V_146 -> V_113 ,
V_201 , V_338 , 0 ,
V_339 ) ;
F_5 ( F_137 ( V_146 -> V_112 ) , V_21 ) ;
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
static void F_151 ( struct V_1 * V_2 , char * V_340 )
{
F_24 ( V_52 , 2 , L_132 ) ;
V_2 -> V_3 . V_134 = V_340 [ 30 ] ;
V_2 -> V_3 . V_341 = V_340 [ 31 ] ;
V_2 -> V_3 . V_342 = V_340 [ 63 ] ;
V_2 -> V_3 . V_4 = ( ( V_340 [ 0x10 ] == V_343 [ 'V' ] ) &&
( V_340 [ 0x11 ] == V_343 [ 'M' ] ) ) ;
}
static void F_152 ( struct V_1 * V_2 , char * V_340 )
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
static void F_153 ( struct V_1 * V_2 )
{
V_2 -> V_348 . V_349 = 0x00010103UL ;
V_2 -> V_348 . V_350 = 0x00010108UL ;
V_2 -> V_348 . V_351 = 0x0001010aUL ;
V_2 -> V_348 . V_352 = 0x0001010bUL ;
V_2 -> V_348 . V_353 = 0x0001010dUL ;
}
static void F_154 ( struct V_1 * V_2 )
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
static int F_157 ( struct V_145 * V_146 ,
void (* F_156)( struct V_145 * ,
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
V_106 -> V_159 = F_156 ;
memcpy ( & V_146 -> V_113 , V_150 , sizeof( struct V_149 ) ) ;
V_146 -> V_113 . V_151 = V_359 ;
V_146 -> V_113 . V_152 = ( T_1 ) F_78 ( V_106 -> V_110 ) ;
if ( V_146 == & V_2 -> V_142 ) {
memcpy ( V_106 -> V_110 , V_360 , V_359 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_361 , V_173 ) ;
V_2 -> V_166 . V_361 ++ ;
} else {
memcpy ( V_106 -> V_110 , V_362 , V_359 ) ;
memcpy ( F_158 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_361 , V_173 ) ;
}
V_30 = ( ( T_2 ) V_2 -> V_3 . V_363 ) | 0x80 ;
memcpy ( F_159 ( V_106 -> V_110 ) , & V_30 , 1 ) ;
memcpy ( F_160 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_349 , V_364 ) ;
memcpy ( F_161 ( V_106 -> V_110 ) ,
& V_2 -> V_3 . V_255 , sizeof( V_169 ) ) ;
F_162 ( F_26 ( V_2 ) , & V_358 ) ;
memcpy ( F_163 ( V_106 -> V_110 ) , & V_358 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_3 . V_342 << 8 ) + V_2 -> V_3 . V_341 ;
memcpy ( F_164 ( V_106 -> V_110 ) , & V_356 , 2 ) ;
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
return F_155 ( V_146 , F_156 ) ;
}
static int F_165 ( int V_367 )
{
if ( ( V_367 & 0xff ) == 8 )
return ( V_367 & 0xff ) + 0x400 ;
if ( ( ( V_367 >> 8 ) & 3 ) == 1 )
return ( V_367 & 0xff ) + 0x200 ;
return V_367 ;
}
static void F_166 ( struct V_145 * V_146 ,
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
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
if ( F_168 ( V_106 -> V_110 ) == V_368 )
F_30 ( & V_2 -> V_142 . V_112 -> V_73 ,
L_143
L_144 ) ;
else
F_51 ( 2 , L_145
L_146 ,
F_52 ( & V_2 -> V_142 . V_112 -> V_73 ) ) ;
goto V_60;
}
memcpy ( & V_356 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( ( V_356 & ~ 0x0100 ) != F_165 ( V_2 -> V_3 . V_255 ) ) {
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
static void F_169 ( struct V_145 * V_146 ,
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
if ( ! ( F_167 ( V_106 -> V_110 ) ) ) {
switch ( F_168 ( V_106 -> V_110 ) ) {
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
F_168 ( V_106 -> V_110 ) ) ;
goto V_60;
}
if ( ( ! F_170 ( V_106 -> V_110 ) ) ||
( V_2 -> V_3 . type == V_5 ) )
V_2 -> V_3 . V_371 = 1 ;
memcpy ( & V_356 , F_161 ( V_106 -> V_110 ) , 2 ) ;
if ( V_356 != F_165 ( V_2 -> V_3 . V_255 ) ) {
F_51 ( 2 , L_155
L_156 ,
F_52 ( & V_2 -> V_107 . V_112 -> V_73 ) ,
V_2 -> V_3 . V_255 , V_356 ) ;
goto V_60;
}
memcpy ( & V_2 -> V_348 . V_372 ,
F_160 ( V_106 -> V_110 ) ,
V_364 ) ;
memcpy ( & V_2 -> V_3 . V_296 [ 0 ] ,
F_171 ( V_106 -> V_110 ) , V_373 ) ;
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
& V_2 -> V_166 . V_361 , V_173 ) ;
V_2 -> V_166 . V_361 ++ ;
memcpy ( F_85 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_374 , V_173 ) ;
V_2 -> V_166 . V_374 ++ ;
memcpy ( F_173 ( V_106 -> V_110 ) ,
& V_2 -> V_166 . V_172 , V_173 ) ;
F_29 ( V_143 , 2 , V_106 -> V_110 , V_144 ) ;
}
int F_174 ( struct V_1 * V_2 , int V_147 ,
struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
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
V_118 -> V_159 = F_175 ;
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
F_172 ( V_2 , V_147 , V_106 ) ;
if ( F_67 ( V_106 -> V_110 ) )
V_377 = V_380 ;
else
V_377 = V_317 ;
V_376 = V_381 + V_377 ;
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
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
if ( ( V_123 -> V_126 . V_127 == V_383 ) &&
( V_123 -> V_126 . V_384 == V_385 ) ) {
if ( ! F_176 ( V_118 -> V_25 ,
F_34 ( & V_118 -> V_121 ) , V_377 ) )
goto V_386;
} else {
while ( ! F_34 ( & V_118 -> V_121 ) ) {
if ( F_177 ( V_381 , V_376 ) )
goto V_386;
F_178 () ;
} ;
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
static int F_179 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_161 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_387 ,
F_180 ( V_106 -> V_110 ) ,
V_364 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_162 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_388 , V_389 ) ;
memcpy ( F_182 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_372 , V_364 ) ;
memcpy ( F_183 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_350 , V_364 ) ;
V_26 = F_174 ( V_2 , V_389 , V_106 ,
F_179 , NULL ) ;
return V_26 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_163 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_390 ,
F_185 ( V_106 -> V_110 ) ,
V_364 ) ;
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_164 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_391 , V_392 ) ;
memcpy ( F_187 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_372 , V_364 ) ;
memcpy ( F_188 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_351 , V_364 ) ;
memcpy ( F_189 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_387 , V_364 ) ;
V_26 = F_174 ( V_2 , V_392 , V_106 ,
F_184 , NULL ) ;
return V_26 ;
}
static inline int F_190 ( struct V_1 * V_2 )
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
static inline int F_191 ( int V_394 )
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
static inline int F_192 ( struct V_1 * V_2 , int V_395 )
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
static int F_193 ( struct V_1 * V_2 , struct V_117 * V_118 ,
unsigned long V_110 )
{
V_169 V_395 , V_394 ;
V_169 V_147 ;
T_2 V_10 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_165 ) ;
V_106 = (struct V_105 * ) V_110 ;
memcpy ( & V_2 -> V_348 . V_396 ,
F_194 ( V_106 -> V_110 ) ,
V_364 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
memcpy ( & V_394 , F_195 ( V_106 -> V_110 ) , 2 ) ;
V_395 = F_191 ( V_394 ) ;
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
V_2 -> V_3 . V_398 = F_190 ( V_2 ) ;
V_2 -> V_3 . V_393 = * ( V_169 * ) F_195 (
V_106 -> V_110 ) ;
V_2 -> V_35 . V_256 = V_257 ;
}
memcpy ( & V_147 , F_196 ( V_106 -> V_110 ) , 2 ) ;
if ( V_147 >= V_400 ) {
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
char V_401 ;
struct V_105 * V_106 ;
F_24 ( V_52 , 2 , L_167 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_402 , V_403 ) ;
* ( F_199 ( V_106 -> V_110 ) ) =
( T_2 ) V_2 -> V_3 . V_363 ;
if ( V_2 -> V_49 . V_301 )
if ( V_2 -> V_3 . type == V_9 )
V_401 = V_404 ;
else
V_401 = V_405 ;
else
V_401 = V_406 ;
memcpy ( F_200 ( V_106 -> V_110 ) , & V_401 , 1 ) ;
memcpy ( F_201 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_202 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_352 , V_364 ) ;
memcpy ( F_203 ( V_106 -> V_110 ) ,
V_2 -> V_3 . V_407 , 9 ) ;
V_26 = F_174 ( V_2 , V_403 , V_106 ,
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
memcpy ( & V_2 -> V_348 . V_408 ,
F_205 ( V_106 -> V_110 ) ,
V_364 ) ;
if ( ! strncmp ( L_169 , F_205 ( V_106 -> V_110 ) ,
3 ) ) {
F_24 ( V_52 , 2 , L_170 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_171
L_172 ) ;
V_106 -> V_26 = - V_409 ;
}
F_27 ( V_52 , 2 , L_72 , V_106 -> V_26 ) ;
return V_26 ;
}
static int F_206 ( struct V_1 * V_2 )
{
int V_26 ;
V_169 V_356 ;
struct V_105 * V_106 ;
struct V_357 V_410 ;
F_24 ( V_52 , 2 , L_173 ) ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
memcpy ( V_106 -> V_110 , V_411 , V_412 ) ;
memcpy ( F_207 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_208 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_353 , V_364 ) ;
memcpy ( F_209 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_396 , V_364 ) ;
F_162 ( F_26 ( V_2 ) , & V_410 ) ;
memcpy ( F_210 ( V_106 -> V_110 ) , & V_410 . V_365 , 2 ) ;
V_356 = ( V_2 -> V_3 . V_342 << 8 ) + V_2 -> V_3 . V_341 ;
memcpy ( F_211 ( V_106 -> V_110 ) , & V_356 , 2 ) ;
V_26 = F_174 ( V_2 , V_412 , V_106 ,
F_204 , NULL ) ;
return V_26 ;
}
static int F_39 ( struct V_84 * V_85 , int V_86 )
{
int V_26 ;
struct V_89 * V_413 ;
V_26 = 0 ;
V_413 = F_212 ( V_94 , V_119 ) ;
if ( ! V_413 ) {
V_26 = - V_39 ;
goto V_60;
}
V_413 -> V_66 = & V_85 -> V_54 [ V_86 ] ;
F_213 ( & V_413 -> V_220 ) ;
F_214 ( & V_413 -> V_220 . V_141 , & V_414 ) ;
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
static int F_215 ( struct V_1 * V_2 )
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
F_37 ( V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] != NULL ) ;
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
static void F_216 ( struct V_1 * V_2 ,
char * V_422 )
{
V_422 [ 0 ] = V_343 [ 'P' ] ;
V_422 [ 1 ] = V_343 [ 'C' ] ;
V_422 [ 2 ] = V_343 [ 'I' ] ;
V_422 [ 3 ] = V_343 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_422 [ 4 ] ) ) = F_217 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_422 [ 8 ] ) ) = F_218 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_422 [ 12 ] ) ) = F_219 ( V_2 ) ;
}
static void F_220 ( struct V_1 * V_2 ,
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
memcpy ( V_106 -> V_110 , V_423 , V_424 ) ;
memcpy ( F_224 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_390 , V_364 ) ;
memcpy ( F_225 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
V_26 = F_174 ( V_2 , V_424 , V_106 , NULL , NULL ) ;
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
goto V_425;
}
V_26 = F_186 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_425;
}
V_26 = F_198 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
goto V_425;
}
V_26 = F_206 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_425;
}
V_26 = F_215 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_425;
}
V_26 = F_227 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_112 ( V_2 ) ;
goto V_425;
}
V_26 = F_221 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_184 , V_26 ) ;
goto V_425;
}
V_26 = F_223 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_185 , V_26 ) ;
goto V_425;
}
return 0 ;
V_425:
F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
return V_26 ;
}
static void F_228 ( struct V_1 * V_2 )
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
static void F_229 ( struct V_1 * V_2 )
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
void F_230 ( struct V_1 * V_2 )
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
F_228 ( V_2 ) ;
else
F_229 ( V_2 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_28 * V_428 ;
F_11 ( V_2 , 5 , L_196 ) ;
F_232 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_233 ( V_2 , V_428 ) ;
}
}
static inline struct V_28 * F_234 (
struct V_1 * V_2 )
{
struct V_297 * V_429 ;
struct V_28 * V_428 ;
int V_33 , free ;
struct V_430 * V_430 ;
if ( F_235 ( & V_2 -> V_35 . V_48 . V_42 ) )
return NULL ;
F_236 (plh, &card->qdio.in_buf_pool.entry_list) {
V_428 = F_237 ( V_429 , struct V_28 , V_31 ) ;
free = 1 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_238 ( F_239 ( V_428 -> V_40 [ V_33 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_75 ( & V_428 -> V_31 ) ;
return V_428 ;
}
}
V_428 = F_237 ( V_2 -> V_35 . V_48 . V_42 . V_431 ,
struct V_28 , V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_238 ( F_239 ( V_428 -> V_40 [ V_33 ] ) ) > 1 ) {
V_430 = F_240 ( V_119 ) ;
if ( ! V_430 ) {
return NULL ;
} else {
F_19 ( ( unsigned long ) V_428 -> V_40 [ V_33 ] ) ;
V_428 -> V_40 [ V_33 ] = F_241 ( V_430 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_433 ++ ;
}
}
}
F_75 ( & V_428 -> V_31 ) ;
return V_428 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_434 * V_217 )
{
struct V_28 * V_29 ;
int V_33 ;
if ( ( V_2 -> V_49 . V_50 == V_51 ) && ( ! V_217 -> V_245 ) ) {
V_217 -> V_245 = F_243 ( V_435 + V_436 ) ;
if ( ! V_217 -> V_245 )
return 1 ;
}
V_29 = F_234 ( V_2 ) ;
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
V_2 -> V_35 . V_70 [ V_33 ] -> V_438 = 0 ;
V_2 -> V_35 . V_70 [ V_33 ] -> V_439 = 0 ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_440 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_234 , 0 ) ;
F_43 ( & V_2 -> V_35 . V_70 [ V_33 ] -> V_44 ,
V_441 ) ;
}
return 0 ;
}
static inline T_2 F_245 ( enum V_442 V_10 )
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
enum V_443 V_444 )
{
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_126 . V_127 = V_127 ;
V_123 -> V_126 . V_445 = V_446 ;
V_123 -> V_126 . V_166 = V_2 -> V_166 . V_379 ;
V_123 -> V_126 . V_447 = F_245 ( V_2 -> V_3 . V_10 ) ;
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
struct V_105 * F_247 ( struct V_1 * V_2 ,
enum V_453 V_454 , enum V_443 V_444 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_81 ( & V_2 -> V_142 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
F_246 ( V_2 , V_123 , V_454 , V_444 ) ;
return V_106 ;
}
void F_248 ( struct V_1 * V_2 , struct V_105 * V_106 ,
char V_401 )
{
memcpy ( V_106 -> V_110 , V_455 , V_382 ) ;
memcpy ( F_249 ( V_106 -> V_110 ) , & V_401 , 1 ) ;
memcpy ( F_250 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
}
int F_251 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
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
F_248 ( V_2 , V_106 , V_401 ) ;
V_26 = F_174 ( V_2 , V_456 ,
V_106 , F_175 , V_375 ) ;
if ( V_26 == - V_319 ) {
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
V_123 -> V_110 . V_457 . V_126 . V_132 ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 ,
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
return F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
}
struct V_105 * F_255 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_463 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
V_106 = F_247 ( V_2 , V_464 ,
V_385 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_126 . V_465 = V_463 ;
V_123 -> V_110 . V_457 . V_126 . V_466 = V_127 ;
V_123 -> V_110 . V_457 . V_126 . V_467 = 1 ;
V_123 -> V_110 . V_457 . V_126 . V_468 = 1 ;
return V_106 ;
}
int F_256 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_105 * V_106 ;
F_11 ( V_2 , 3 , L_203 ) ;
V_106 = F_255 ( V_2 , V_469 ,
sizeof( struct V_470 ) ) ;
V_26 = F_251 ( V_2 , V_106 , F_254 , NULL ) ;
return V_26 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_204 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( V_123 -> V_126 . V_384 == V_385 ) {
V_2 -> V_49 . V_471 . V_461 = V_123 -> V_126 . V_451 ;
V_2 -> V_49 . V_471 . V_472 = V_123 -> V_126 . V_452 ;
} else {
V_2 -> V_49 . V_473 . V_461 = V_123 -> V_126 . V_451 ;
V_2 -> V_49 . V_473 . V_472 = V_123 -> V_126 . V_452 ;
}
F_24 ( V_52 , 2 , L_205 ) ;
F_27 ( V_52 , 2 , L_206 , ( T_1 ) V_123 -> V_126 . V_451 ) ;
F_27 ( V_52 , 2 , L_206 , ( T_1 ) V_123 -> V_126 . V_452 ) ;
return 0 ;
}
int F_258 ( struct V_1 * V_2 , enum V_443 V_444 )
{
int V_26 ;
struct V_105 * V_106 ;
F_27 ( V_52 , 2 , L_207 , V_444 ) ;
V_106 = F_247 ( V_2 , V_474 , V_444 ) ;
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
V_2 -> V_3 . V_475 = V_123 -> V_110 . V_476 . V_477 ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_209 ) ;
V_106 = F_247 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_476 . V_478 = 16 ;
V_123 -> V_110 . V_476 . V_479 = V_480 ;
return F_251 ( V_2 , V_106 , F_259 , NULL ) ;
}
static void F_261 ( struct V_1 * V_2 , struct V_481 * V_482 )
{
unsigned long V_3 = F_262 ( V_38 ) ;
struct V_483 * V_484 = (struct V_483 * ) V_3 ;
struct V_485 * V_486 = (struct V_485 * ) V_3 ;
struct V_357 V_487 ;
int V_367 , V_26 ;
V_482 -> V_134 = V_2 -> V_3 . V_134 ;
F_162 ( F_135 ( V_2 ) , & V_487 ) ;
V_482 -> V_488 = V_487 . V_488 ;
V_482 -> V_365 = V_487 . V_365 ;
if ( ! V_3 )
return;
V_26 = F_263 ( NULL , 0 , 0 , 0 ) ;
if ( V_26 == - V_489 )
V_367 = V_26 ;
else
V_367 = ( ( ( unsigned int ) V_26 ) >> 28 ) ;
if ( ( V_367 >= 2 ) && ( F_263 ( V_484 , 2 , 2 , 2 ) != - V_489 ) )
V_482 -> V_490 = V_484 -> V_491 ;
if ( ( V_367 >= 3 ) && ( F_263 ( V_486 , 3 , 2 , 2 ) != - V_489 ) ) {
F_264 ( V_486 -> V_492 [ 0 ] . V_493 , sizeof( V_486 -> V_492 [ 0 ] . V_493 ) ) ;
memcpy ( V_482 -> V_494 , V_486 -> V_492 [ 0 ] . V_493 , sizeof( V_482 -> V_494 ) ) ;
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
int F_266 ( struct V_1 * V_2 , enum V_495 V_496 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_24 ( V_52 , 2 , L_211 ) ;
V_106 = F_247 ( V_2 , V_131 , 0 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_476 . V_478 = 80 ;
V_123 -> V_110 . V_476 . V_479 = V_497 ;
V_123 -> V_110 . V_476 . type = 1 ;
V_123 -> V_110 . V_476 . V_496 = V_496 ;
switch ( V_496 ) {
case V_498 :
V_123 -> V_110 . V_476 . V_49 = 0x0003 ;
V_123 -> V_110 . V_476 . V_477 = 0x00010000 +
sizeof( struct V_481 ) ;
F_261 ( V_2 ,
(struct V_481 * ) V_123 -> V_110 . V_476 . V_499 ) ;
break;
case V_500 :
V_123 -> V_110 . V_476 . V_49 = 0x0001 ;
break;
case V_501 :
break;
}
return F_251 ( V_2 , V_106 , F_265 , NULL ) ;
}
int F_267 ( struct V_1 * V_2 , struct V_56 * V_217 ,
unsigned int V_502 , const char * V_503 )
{
if ( V_502 ) {
F_11 ( V_2 , 2 , V_503 ) ;
F_35 ( V_2 , 2 , L_212 ,
V_217 -> V_231 [ 15 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_213 ,
V_217 -> V_231 [ 14 ] . V_232 ) ;
F_35 ( V_2 , 2 , L_214 , V_502 ) ;
if ( ( V_217 -> V_231 [ 15 ] . V_232 ) == 0x12 ) {
V_2 -> V_504 . V_505 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_290 ( struct V_272 * V_273 )
{
struct V_1 * V_2 = F_123 ( V_273 , struct V_1 ,
V_243 . V_273 ) ;
F_35 ( V_2 , 2 , L_215 , V_2 -> V_506 ) ;
F_268 ( V_2 , V_2 -> V_506 ) ;
}
void F_268 ( struct V_1 * V_2 , int V_153 )
{
struct V_63 * V_104 = V_2 -> V_35 . V_244 ;
struct V_297 * V_507 ;
int V_151 ;
int V_33 ;
int V_26 ;
int V_508 = 0 ;
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
V_508 ++ ;
}
}
if ( V_508 < V_151 ) {
F_43 ( & V_2 -> V_509 , 3 ) ;
V_151 = V_508 ;
} else {
F_270 ( & V_2 -> V_509 , - 1 , 0 ) ;
}
if ( ! V_151 ) {
V_33 = 0 ;
F_236 (lh, &card->qdio.in_buf_pool.entry_list)
V_33 ++ ;
if ( V_33 == V_2 -> V_35 . V_48 . V_37 ) {
F_11 ( V_2 , 2 , L_216 ) ;
V_2 -> V_506 = V_153 ;
F_271 (
& V_2 -> V_243 ,
V_510 ) ;
}
return;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_511 ++ ;
V_2 -> V_432 . V_512 =
F_272 () ;
}
V_26 = F_25 ( F_26 ( V_2 ) , V_58 , 0 ,
V_104 -> V_57 , V_151 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_513 +=
F_272 () -
V_2 -> V_432 . V_512 ;
if ( V_26 ) {
F_11 ( V_2 , 2 , L_217 ) ;
}
V_104 -> V_57 = ( V_104 -> V_57 + V_151 ) %
V_55 ;
}
}
static int F_273 ( struct V_1 * V_2 ,
struct V_89 * V_66 , unsigned int V_514 )
{
int V_75 = V_66 -> V_66 -> V_231 [ 15 ] . V_232 ;
F_11 ( V_2 , 6 , L_218 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
if ( V_75 == 0 ) {
V_514 = 0 ;
} else {
V_514 = 1 ;
}
}
F_267 ( V_2 , V_66 -> V_66 , V_514 , L_219 ) ;
if ( ! V_514 )
return V_515 ;
if ( ( V_75 >= 15 ) && ( V_75 <= 31 ) )
return V_516 ;
F_11 ( V_2 , 1 , L_220 ) ;
F_35 ( V_2 , 1 , L_221 ,
( V_170 ) V_514 , ( T_3 ) V_75 ) ;
return V_517 ;
}
static void F_274 ( struct V_84 * V_104 )
{
if ( ! V_104 -> V_439 ) {
if ( F_34 ( & V_104 -> V_440 )
>= V_518 ) {
F_11 ( V_104 -> V_2 , 6 , L_222 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_519 ++ ;
V_104 -> V_439 = 1 ;
}
}
}
static int F_275 ( struct V_84 * V_104 )
{
struct V_89 * V_66 ;
int V_520 = 0 ;
if ( V_104 -> V_439 ) {
if ( F_34 ( & V_104 -> V_440 )
<= V_521 ) {
F_11 ( V_104 -> V_2 , 6 , L_223 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_522 ++ ;
V_104 -> V_439 = 0 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( ( F_34 ( & V_66 -> V_44 ) ==
V_235 ) &&
( V_66 -> V_241 > 0 ) ) {
F_43 ( & V_66 -> V_44 ,
V_100 ) ;
V_520 ++ ;
V_104 -> V_438 =
( V_104 -> V_438 + 1 ) %
V_55 ;
}
}
}
return V_520 ;
}
static int F_276 ( struct V_84 * V_104 )
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
static void F_277 ( struct V_84 * V_104 , int V_153 ,
int V_151 )
{
struct V_89 * V_217 ;
int V_26 ;
int V_33 ;
unsigned int V_523 ;
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
( V_518 -
V_524 ) ) &&
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
V_104 -> V_2 -> V_73 -> V_525 = V_381 ;
if ( V_104 -> V_2 -> V_49 . V_266 ) {
V_104 -> V_2 -> V_432 . V_526 ++ ;
V_104 -> V_2 -> V_432 . V_527 =
F_272 () ;
}
V_523 = V_528 ;
if ( F_34 ( & V_104 -> V_234 ) )
V_523 |= V_529 ;
V_26 = F_25 ( F_26 ( V_104 -> V_2 ) , V_523 ,
V_104 -> V_420 , V_153 , V_151 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_530 +=
F_272 () -
V_104 -> V_2 -> V_432 . V_527 ;
F_278 ( V_151 , & V_104 -> V_440 ) ;
if ( V_26 ) {
V_104 -> V_2 -> V_504 . V_531 += V_151 ;
if ( V_26 == - V_532 )
return;
F_11 ( V_104 -> V_2 , 2 , L_224 ) ;
F_35 ( V_104 -> V_2 , 2 , L_225 , V_104 -> V_420 ) ;
F_35 ( V_104 -> V_2 , 2 , L_226 , V_153 ) ;
F_35 ( V_104 -> V_2 , 2 , L_227 , V_151 ) ;
F_35 ( V_104 -> V_2 , 2 , L_160 , V_26 ) ;
F_55 ( V_104 -> V_2 ) ;
return;
}
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_533 += V_151 ;
}
static void F_279 ( struct V_84 * V_104 )
{
int V_153 ;
int V_534 = 0 ;
int V_535 = 0 ;
if ( ( F_34 ( & V_104 -> V_440 ) <= V_521 ) ||
! F_34 ( & V_104 -> V_234 ) ) {
if ( F_113 ( & V_104 -> V_44 , V_536 ) ==
V_441 ) {
F_280 ( V_104 -> V_2 -> V_73 ) ;
V_153 = V_104 -> V_438 ;
V_535 = V_104 -> V_439 ;
F_281 () ;
V_534 += F_275 ( V_104 ) ;
if ( ! V_534 &&
! F_34 ( & V_104 -> V_234 ) )
V_534 +=
F_276 ( V_104 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 &&
V_535 )
V_104 -> V_2 -> V_432 . V_537 +=
V_534 ;
if ( V_534 )
F_277 ( V_104 , V_153 , V_534 ) ;
F_43 ( & V_104 -> V_44 , V_441 ) ;
}
}
}
void F_282 ( struct V_178 * V_112 , int V_104 ,
unsigned long V_538 )
{
struct V_1 * V_2 = (struct V_1 * ) V_538 ;
if ( V_2 -> V_73 && ( V_2 -> V_73 -> V_21 & V_539 ) )
F_283 ( & V_2 -> V_540 ) ;
}
int F_284 ( struct V_1 * V_2 , enum V_541 V_50 )
{
int V_26 ;
if ( V_2 -> V_49 . V_50 == V_542 ) {
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
unsigned int V_514 ,
unsigned int V_104 , int V_543 , int V_151 ) {
struct V_63 * V_50 = V_2 -> V_35 . V_53 ;
int V_33 ;
int V_26 ;
if ( ! F_47 ( V_2 , V_104 ) )
goto V_60;
F_35 ( V_2 , 5 , L_228 , V_543 ) ;
F_35 ( V_2 , 5 , L_229 , V_151 ) ;
F_35 ( V_2 , 5 , L_230 , V_514 ) ;
if ( V_514 ) {
F_280 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_544 ++ ;
V_2 -> V_432 . V_545 = F_272 () ;
}
for ( V_33 = V_543 ; V_33 < V_543 + V_151 ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
struct V_56 * V_66 = & V_50 -> V_54 [ V_86 ] ;
int V_546 ;
V_546 = 0 ;
while ( V_66 -> V_231 [ V_546 ] . V_236 ) {
unsigned long V_96 ;
V_96 = ( unsigned long ) V_66 -> V_231 [ V_546 ] . V_236 ;
F_40 ( V_2 , V_96 ) ;
V_66 -> V_231 [ V_546 ] . V_236 = NULL ;
V_66 -> V_231 [ V_546 ] . V_240 = 0 ;
V_66 -> V_231 [ V_546 ] . V_232 = 0 ;
V_66 -> V_231 [ V_546 ] . V_239 = 0 ;
++ V_546 ;
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
if ( V_2 -> V_49 . V_266 ) {
int V_547 = F_272 () ;
V_547 -= V_2 -> V_432 . V_545 ;
V_2 -> V_432 . V_548 += V_547 ;
}
V_60:
return;
}
void F_287 ( struct V_178 * V_112 , unsigned int V_514 ,
unsigned int V_104 , int V_549 , int V_151 ,
unsigned long V_538 )
{
struct V_1 * V_2 = (struct V_1 * ) V_538 ;
F_35 ( V_2 , 2 , L_233 , V_104 ) ;
F_35 ( V_2 , 2 , L_234 , V_514 ) ;
if ( F_47 ( V_2 , V_104 ) )
F_285 ( V_2 , V_514 , V_104 , V_549 , V_151 ) ;
else if ( V_514 )
F_55 ( V_2 ) ;
}
void F_288 ( struct V_178 * V_112 ,
unsigned int V_502 , int V_550 , int V_543 ,
int V_151 , unsigned long V_538 )
{
struct V_1 * V_2 = (struct V_1 * ) V_538 ;
struct V_84 * V_104 = V_2 -> V_35 . V_70 [ V_550 ] ;
struct V_89 * V_66 ;
int V_33 ;
F_11 ( V_2 , 6 , L_235 ) ;
if ( V_502 & V_551 ) {
F_11 ( V_2 , 2 , L_236 ) ;
F_280 ( V_2 -> V_73 ) ;
F_55 ( V_2 ) ;
return;
}
if ( V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_552 ++ ;
V_2 -> V_432 . V_553 =
F_272 () ;
}
for ( V_33 = V_543 ; V_33 < ( V_543 + V_151 ) ; ++ V_33 ) {
int V_86 = V_33 % V_55 ;
V_66 = V_104 -> V_65 [ V_86 ] ;
F_273 ( V_2 , V_66 , V_502 ) ;
if ( V_104 -> V_71 &&
( V_104 -> V_71 [ V_86 ] . V_21 &
V_554 ) != 0 ) {
F_37 ( V_2 -> V_49 . V_50 != V_51 ) ;
if ( F_42 ( & V_66 -> V_44 ,
V_100 ,
V_102 ) ==
V_100 ) {
F_44 ( V_104 , V_66 ,
V_555 ) ;
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
F_290 ( V_151 , & V_104 -> V_440 ) ;
if ( V_2 -> V_3 . type != V_6 )
F_279 ( V_104 ) ;
F_286 ( V_104 -> V_2 -> V_73 ) ;
if ( V_2 -> V_49 . V_266 )
V_2 -> V_432 . V_556 += F_272 () -
V_2 -> V_432 . V_553 ;
}
int F_291 ( struct V_1 * V_2 , struct V_218 * V_219 ,
int V_557 , int V_558 )
{
if ( ! V_557 && ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) )
return V_2 -> V_35 . V_254 ;
switch ( V_2 -> V_35 . V_68 ) {
case 4 :
if ( V_558 && V_2 -> V_3 . V_313 )
return V_2 -> V_3 . V_313 &
( V_2 -> V_35 . V_68 - 1 ) ;
if ( V_2 -> V_35 . V_303 && ( V_557 == 4 ) ) {
const T_3 V_559 = F_292 ( V_219 ) -> V_559 ;
if ( V_2 -> V_35 . V_303 ==
V_560 ) {
if ( V_559 & V_561 )
return 3 ;
if ( V_559 & V_562 )
return 2 ;
if ( V_559 & V_563 )
return 1 ;
if ( V_559 & V_564 )
return 0 ;
}
if ( V_2 -> V_35 . V_303 ==
V_565 )
return 3 - ( V_559 >> 6 ) ;
} else if ( V_2 -> V_35 . V_303 && ( V_557 == 6 ) ) {
}
return V_2 -> V_35 . V_254 ;
case 1 :
default:
return V_2 -> V_35 . V_254 ;
}
}
int F_293 ( struct V_1 * V_2 , void * V_126 ,
struct V_218 * V_219 , int V_566 )
{
int V_567 = V_219 -> V_147 - V_219 -> V_568 ;
int V_569 = F_294 ( ( unsigned long ) V_219 -> V_110 + V_567 - 1 ) -
F_295 ( ( unsigned long ) V_219 -> V_110 ) ;
V_569 += F_296 ( V_219 ) -> V_570 ;
if ( ( V_569 + V_566 ) > F_17 ( V_2 ) ) {
F_51 ( 2 , L_240
L_241 ,
( V_569 + V_566 ) , V_219 -> V_147 ) ;
return 0 ;
}
return V_569 ;
}
int F_297 ( struct V_218 * V_219 , int V_147 )
{
int V_571 , V_572 , V_573 ;
if ( ( ( unsigned long ) V_219 -> V_110 & V_574 ) !=
( ( ( unsigned long ) V_219 -> V_110 + V_147 - 1 ) & V_574 ) ) {
V_571 = F_298 ( V_219 ) ;
V_572 = V_399 - ( ( unsigned long ) V_219 -> V_110 % V_399 ) ;
V_573 = V_147 - V_572 ;
if ( V_573 > V_571 )
return 1 ;
memmove ( V_219 -> V_110 - V_573 , V_219 -> V_110 , V_219 -> V_147 - V_219 -> V_568 ) ;
V_219 -> V_110 -= V_573 ;
F_51 ( 2 , L_242 , V_147 , V_573 ) ;
}
return 0 ;
}
static inline void F_299 ( struct V_218 * V_219 ,
struct V_56 * V_66 , int V_575 , int * V_241 ,
int V_168 )
{
int V_239 = V_219 -> V_147 - V_219 -> V_568 ;
int V_576 ;
int V_231 ;
char * V_110 ;
int V_577 , V_161 ;
struct V_578 * V_579 ;
V_231 = * V_241 ;
V_110 = V_219 -> V_110 ;
V_577 = ( V_575 == 0 ? 1 : 0 ) ;
if ( V_168 >= 0 ) {
V_110 = V_219 -> V_110 + V_168 ;
V_239 -= V_168 ;
V_577 = 0 ;
}
while ( V_239 > 0 ) {
V_576 = V_399 - ( ( unsigned long ) V_110 % V_399 ) ;
if ( V_239 < V_576 )
V_576 = V_239 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_576 ;
V_239 -= V_576 ;
if ( ! V_239 ) {
if ( V_577 )
if ( F_296 ( V_219 ) -> V_570 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_580 ;
else
V_66 -> V_231 [ V_231 ] . V_240 = 0 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_581 ;
} else {
if ( V_577 )
V_66 -> V_231 [ V_231 ] . V_240 =
V_580 ;
else
V_66 -> V_231 [ V_231 ] . V_240 =
V_581 ;
}
V_110 += V_576 ;
V_231 ++ ;
V_577 = 0 ;
}
for ( V_161 = 0 ; V_161 < F_296 ( V_219 ) -> V_570 ; V_161 ++ ) {
V_579 = & F_296 ( V_219 ) -> V_582 [ V_161 ] ;
V_66 -> V_231 [ V_231 ] . V_236 = ( char * )
F_300 ( F_301 ( V_579 ) )
+ V_579 -> V_583 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_579 -> V_584 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_581 ;
V_231 ++ ;
}
if ( V_66 -> V_231 [ V_231 - 1 ] . V_240 )
V_66 -> V_231 [ V_231 - 1 ] . V_240 = V_585 ;
* V_241 = V_231 ;
}
static inline int F_302 ( struct V_84 * V_104 ,
struct V_89 * V_217 , struct V_218 * V_219 ,
struct V_586 * V_126 , int V_168 , int V_587 )
{
struct V_56 * V_66 ;
int V_534 = 0 , V_588 , V_589 = 0 ;
V_66 = V_217 -> V_66 ;
F_59 ( & V_219 -> V_228 ) ;
F_303 ( & V_217 -> V_220 , V_219 ) ;
if ( V_126 -> V_126 . V_590 . V_308 == V_591 ) {
int V_231 = V_217 -> V_241 ;
V_588 = sizeof( struct V_592 ) +
( (struct V_592 * ) V_126 ) -> V_477 . V_593 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_219 -> V_110 ;
V_66 -> V_231 [ V_231 ] . V_239 = V_588 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_580 ;
V_217 -> V_241 ++ ;
V_219 -> V_110 += V_588 ;
V_219 -> V_147 -= V_588 ;
V_589 = 1 ;
}
if ( V_168 >= 0 ) {
int V_231 = V_217 -> V_241 ;
V_66 -> V_231 [ V_231 ] . V_236 = V_126 ;
V_66 -> V_231 [ V_231 ] . V_239 = sizeof( struct V_586 ) +
V_587 ;
V_66 -> V_231 [ V_231 ] . V_240 = V_580 ;
V_217 -> V_237 [ V_231 ] = 1 ;
V_217 -> V_241 ++ ;
}
F_299 ( V_219 , V_66 , V_589 ,
( int * ) & V_217 -> V_241 , V_168 ) ;
if ( ! V_104 -> V_439 ) {
F_11 ( V_104 -> V_2 , 6 , L_243 ) ;
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_534 = 1 ;
} else {
F_11 ( V_104 -> V_2 , 6 , L_244 ) ;
if ( V_104 -> V_2 -> V_49 . V_266 )
V_104 -> V_2 -> V_432 . V_594 ++ ;
if ( V_217 -> V_241 >=
F_17 ( V_104 -> V_2 ) ) {
F_43 ( & V_217 -> V_44 , V_100 ) ;
V_534 = 1 ;
}
}
return V_534 ;
}
int F_304 ( struct V_1 * V_2 ,
struct V_84 * V_104 , struct V_218 * V_219 ,
struct V_586 * V_126 , int V_569 ,
int V_168 , int V_587 )
{
struct V_89 * V_66 ;
int V_153 ;
while ( F_42 ( & V_104 -> V_44 , V_441 ,
V_595 ) != V_441 ) ;
V_153 = V_104 -> V_438 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 )
goto V_60;
V_104 -> V_438 = ( V_104 -> V_438 + 1 ) %
V_55 ;
F_43 ( & V_104 -> V_44 , V_441 ) ;
F_302 ( V_104 , V_66 , V_219 , V_126 , V_168 , V_587 ) ;
F_277 ( V_104 , V_153 , 1 ) ;
return 0 ;
V_60:
F_43 ( & V_104 -> V_44 , V_441 ) ;
return - V_596 ;
}
int F_305 ( struct V_1 * V_2 , struct V_84 * V_104 ,
struct V_218 * V_219 , struct V_586 * V_126 ,
int V_569 )
{
struct V_89 * V_66 ;
int V_597 ;
int V_520 = 0 ;
int V_439 = 0 ;
int V_30 ;
int V_26 = 0 ;
while ( F_42 ( & V_104 -> V_44 , V_441 ,
V_595 ) != V_441 ) ;
V_597 = V_104 -> V_438 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) != V_235 ) {
F_43 ( & V_104 -> V_44 , V_441 ) ;
return - V_596 ;
}
F_274 ( V_104 ) ;
if ( V_104 -> V_439 ) {
V_439 = 1 ;
if ( ( F_17 ( V_2 ) -
V_66 -> V_241 ) < V_569 ) {
F_43 ( & V_66 -> V_44 , V_100 ) ;
V_520 ++ ;
V_104 -> V_438 =
( V_104 -> V_438 + 1 ) %
V_55 ;
V_66 = V_104 -> V_65 [ V_104 -> V_438 ] ;
if ( F_34 ( & V_66 -> V_44 ) !=
V_235 ) {
F_277 ( V_104 , V_597 ,
V_520 ) ;
F_43 ( & V_104 -> V_44 ,
V_441 ) ;
return - V_596 ;
}
}
}
V_30 = F_302 ( V_104 , V_66 , V_219 , V_126 , - 1 , 0 ) ;
V_104 -> V_438 = ( V_104 -> V_438 + V_30 ) %
V_55 ;
V_520 += V_30 ;
if ( V_520 )
F_277 ( V_104 , V_597 , V_520 ) ;
else if ( ! F_34 ( & V_104 -> V_234 ) )
F_113 ( & V_104 -> V_44 , V_536 ) ;
while ( F_306 ( & V_104 -> V_44 ) ) {
V_520 = 0 ;
V_597 = V_104 -> V_438 ;
V_520 += F_275 ( V_104 ) ;
if ( ! V_520 && ! F_34 ( & V_104 -> V_234 ) )
V_520 += F_276 ( V_104 ) ;
if ( V_520 )
F_277 ( V_104 , V_597 , V_520 ) ;
}
if ( V_104 -> V_2 -> V_49 . V_266 && V_439 )
V_104 -> V_2 -> V_432 . V_537 += V_520 ;
return V_26 ;
}
static int F_307 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_470 * V_598 ;
F_11 ( V_2 , 4 , L_245 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_598 = & ( V_123 -> V_110 . V_457 ) ;
F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_246 , V_123 -> V_126 . V_132 ) ;
V_598 -> V_110 . V_599 = V_600 ;
}
V_2 -> V_3 . V_601 = V_598 -> V_110 . V_599 ;
return 0 ;
}
void F_308 ( struct V_1 * V_2 )
{
enum V_602 V_599 ;
struct V_603 * V_73 = V_2 -> V_73 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_247 ) ;
if ( ( ( V_73 -> V_21 & V_604 ) &&
( V_2 -> V_3 . V_601 == V_605 ) ) ||
( ! ( V_73 -> V_21 & V_604 ) &&
( V_2 -> V_3 . V_601 == V_600 ) ) )
return;
V_599 = V_600 ;
if ( V_73 -> V_21 & V_604 )
V_599 = V_605 ;
F_35 ( V_2 , 4 , L_248 , V_599 ) ;
V_106 = F_255 ( V_2 , V_606 ,
sizeof( struct V_470 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_110 . V_599 = V_599 ;
F_251 ( V_2 , V_106 , F_307 , NULL ) ;
}
int F_309 ( struct V_603 * V_73 , int V_607 )
{
struct V_1 * V_2 ;
char V_426 [ 15 ] ;
V_2 = V_73 -> V_608 ;
F_11 ( V_2 , 4 , L_249 ) ;
sprintf ( V_426 , L_250 , V_607 ) ;
F_11 ( V_2 , 4 , V_426 ) ;
if ( V_607 < 64 )
return - V_397 ;
if ( V_607 > 65535 )
return - V_397 ;
if ( ( ! F_310 ( V_2 , V_609 ) ) &&
( ! F_192 ( V_2 , V_607 ) ) )
return - V_397 ;
V_73 -> V_395 = V_607 ;
return 0 ;
}
struct V_610 * F_311 ( struct V_603 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_608 ;
F_11 ( V_2 , 5 , L_251 ) ;
return & V_2 -> V_504 ;
}
static int F_312 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
F_11 ( V_2 , 4 , L_252 ) ;
V_123 = (struct V_122 * ) V_110 ;
if ( ! V_2 -> V_49 . V_301 ||
! ( V_2 -> V_3 . V_611 & V_612 ) ) {
memcpy ( V_2 -> V_73 -> V_613 ,
& V_123 -> V_110 . V_457 . V_110 . V_614 . V_236 ,
V_615 ) ;
V_2 -> V_3 . V_611 |= V_612 ;
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
V_106 = F_255 ( V_2 , V_616 ,
sizeof( struct V_470 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_123 -> V_110 . V_457 . V_110 . V_614 . V_123 = V_617 ;
V_123 -> V_110 . V_457 . V_110 . V_614 . V_618 = V_615 ;
memcpy ( & V_123 -> V_110 . V_457 . V_110 . V_614 . V_236 ,
V_2 -> V_73 -> V_613 , V_615 ) ;
V_26 = F_251 ( V_2 , V_106 , F_312 ,
NULL ) ;
return V_26 ;
}
static int F_314 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_619 * V_620 ;
F_11 ( V_2 , 4 , L_254 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_620 = & V_123 -> V_110 . V_457 . V_110 . V_621 ;
F_27 ( V_52 , 2 , L_254 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_622 . V_493 ) ;
F_27 ( V_52 , 2 , L_255 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
switch ( V_123 -> V_110 . V_457 . V_126 . V_132 ) {
case V_623 :
case V_624 :
case V_625 :
{
V_2 -> V_49 . V_269 = V_620 -> V_626 ;
if ( V_2 -> V_49 . V_269 == V_270 ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_256 ) ;
} else {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_257 ) ;
}
F_51 ( 3 , L_258 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_620 -> V_626 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
break;
}
case V_627 :
{
F_51 ( 3 , L_259 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_620 -> V_626 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 , L_260
L_261 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
case V_628 :
{
F_51 ( 3 , L_262 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_620 -> V_626 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_263
L_264 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
case V_629 :
{
F_51 ( 3 , L_262 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_620 -> V_626 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
F_30 ( & V_2 -> V_72 -> V_73 ,
L_265 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
default:
{
F_51 ( 3 , L_266
L_267 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_620 -> V_626 ,
V_123 -> V_110 . V_457 . V_126 . V_132 ) ;
V_2 -> V_49 . V_269 = V_270 ;
break;
}
}
F_253 ( V_2 , V_118 , ( unsigned long ) V_123 ) ;
return 0 ;
}
static int F_315 ( struct V_1 * V_2 ,
enum V_630 V_269 )
{
int V_26 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_619 * V_620 ;
F_11 ( V_2 , 4 , L_268 ) ;
F_27 ( V_52 , 2 , L_268 ) ;
F_27 ( V_52 , 2 , L_186 , V_2 -> V_72 -> V_73 . V_622 . V_493 ) ;
V_106 = F_255 ( V_2 , V_631 ,
sizeof( struct V_632 ) +
sizeof( struct V_619 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_620 = & V_123 -> V_110 . V_457 . V_110 . V_621 ;
V_620 -> V_626 = V_269 ;
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
F_317 ( V_2 , V_631 ) ) {
V_26 = F_315 ( V_2 ,
V_2 -> V_49 . V_269 ) ;
if ( V_26 ) {
F_51 ( 3 ,
L_270 ,
V_2 -> V_72 -> V_73 . V_622 . V_493 ,
V_26 ) ;
}
} else if ( V_2 -> V_49 . V_269 != V_270 ) {
V_2 -> V_49 . V_269 = V_270 ;
F_30 ( & V_2 -> V_72 -> V_73 , L_260
L_261 ) ;
V_26 = - V_334 ;
}
return V_26 ;
}
void F_318 ( struct V_603 * V_73 )
{
struct V_1 * V_2 ;
V_2 = V_73 -> V_608 ;
F_11 ( V_2 , 4 , L_271 ) ;
V_2 -> V_504 . V_531 ++ ;
F_55 ( V_2 ) ;
}
int F_319 ( struct V_603 * V_73 , int V_633 , int V_634 )
{
struct V_1 * V_2 = V_73 -> V_608 ;
int V_26 = 0 ;
switch ( V_634 ) {
case V_635 :
V_26 = V_636 ;
if ( ( V_2 -> V_3 . V_10 != V_13 ) &&
( V_2 -> V_3 . V_10 != V_637 ) &&
( V_2 -> V_3 . V_10 != V_14 ) )
V_26 |= V_638 ;
break;
case V_639 :
V_26 = V_640 | V_641 | V_642 |
V_643 | V_644 | V_645 | V_646 |
V_647 ;
break;
case V_648 :
V_26 = ( V_73 -> V_613 [ 0 ] << 16 ) | ( V_73 -> V_613 [ 1 ] << 8 ) |
V_73 -> V_613 [ 2 ] ;
V_26 = ( V_26 >> 5 ) & 0xFFFF ;
break;
case V_649 :
V_26 = ( V_73 -> V_613 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_650 :
V_26 = V_651 ;
break;
case V_652 :
V_26 = V_653 | V_654 | V_655 | V_656 |
V_657 | V_658 ;
break;
case V_659 :
break;
case V_660 :
break;
case V_661 :
break;
case V_662 :
break;
case V_663 :
V_26 = V_2 -> V_504 . V_664 ;
break;
case V_665 :
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
default:
break;
}
return V_26 ;
}
static int F_320 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_147 ,
int (* F_175)( struct V_1 * , struct V_117 * ,
unsigned long ) ,
void * V_375 )
{
V_170 V_672 , V_673 ;
F_11 ( V_2 , 4 , L_272 ) ;
memcpy ( V_106 -> V_110 , V_455 , V_382 ) ;
memcpy ( F_250 ( V_106 -> V_110 ) ,
& V_2 -> V_348 . V_408 , V_364 ) ;
V_672 = ( V_674 ) V_382 + V_147 ;
V_673 = ( V_674 ) V_147 ;
memcpy ( F_321 ( V_106 -> V_110 ) , & V_672 , 2 ) ;
memcpy ( F_322 ( V_106 -> V_110 ) , & V_673 , 2 ) ;
memcpy ( F_323 ( V_106 -> V_110 ) , & V_673 , 2 ) ;
memcpy ( F_324 ( V_106 -> V_110 ) , & V_673 , 2 ) ;
return F_174 ( V_2 , V_382 + V_147 , V_106 ,
F_175 , V_375 ) ;
}
static int F_325 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_675 )
{
struct V_122 * V_123 ;
struct V_676 * V_677 ;
struct V_678 * V_679 ;
unsigned char * V_110 ;
V_169 V_568 ;
F_11 ( V_2 , 3 , L_273 ) ;
V_123 = (struct V_122 * ) V_675 ;
V_110 = ( unsigned char * ) ( ( char * ) V_123 - V_118 -> V_168 ) ;
V_677 = (struct V_676 * ) V_118 -> V_378 ;
V_679 = & V_123 -> V_110 . V_457 . V_110 . V_679 ;
if ( V_123 -> V_126 . V_132 ) {
F_35 ( V_2 , 4 , L_274 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
if ( V_123 -> V_110 . V_457 . V_126 . V_132 ) {
V_123 -> V_126 . V_132 =
V_123 -> V_110 . V_457 . V_126 . V_132 ;
F_35 ( V_2 , 4 , L_275 , V_123 -> V_126 . V_132 ) ;
return 0 ;
}
V_568 = * ( ( V_169 * ) F_322 ( V_110 ) ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 == 1 )
V_568 -= ( V_169 ) ( ( char * ) & V_679 -> V_110 - ( char * ) V_123 ) ;
else
V_568 -= ( V_169 ) ( ( char * ) & V_679 -> V_680 - ( char * ) V_123 ) ;
if ( ( V_677 -> V_681 - V_677 -> V_682 ) < V_568 ) {
F_35 ( V_2 , 4 , L_276 , - V_39 ) ;
V_123 -> V_126 . V_132 = V_683 ;
return 0 ;
}
F_35 ( V_2 , 4 , L_277 ,
V_123 -> V_110 . V_457 . V_126 . V_467 ) ;
F_35 ( V_2 , 4 , L_278 ,
V_123 -> V_110 . V_457 . V_126 . V_468 ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 == 1 ) {
memcpy ( V_677 -> V_684 + V_677 -> V_682 ,
( char * ) V_679 ,
V_568 + F_326 ( struct V_678 , V_110 ) ) ;
V_677 -> V_682 += F_326 ( struct V_678 , V_110 ) ;
} else {
memcpy ( V_677 -> V_684 + V_677 -> V_682 ,
( char * ) & V_679 -> V_680 , V_568 ) ;
}
V_677 -> V_682 += V_568 ;
F_35 ( V_2 , 4 , L_279 ,
V_123 -> V_110 . V_457 . V_126 . V_467 ) ;
F_35 ( V_2 , 4 , L_280 ,
V_123 -> V_110 . V_457 . V_126 . V_468 ) ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 <
V_123 -> V_110 . V_457 . V_126 . V_467 )
return 1 ;
return 0 ;
}
int F_327 ( struct V_1 * V_2 , char T_4 * V_684 )
{
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_685 * V_686 ;
int V_687 ;
struct V_676 V_677 = { 0 , } ;
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_281 ) ;
if ( V_2 -> V_3 . V_4 )
return - V_334 ;
if ( ( ! F_317 ( V_2 , V_688 ) ) &&
( ! V_2 -> V_49 . V_301 ) ) {
return - V_334 ;
}
if ( F_328 ( & V_687 , V_684 + sizeof( int ) , sizeof( int ) ) )
return - V_689 ;
V_686 = F_329 ( V_684 , V_687 + sizeof( struct V_690 ) ) ;
if ( F_98 ( V_686 ) ) {
F_11 ( V_2 , 2 , L_282 ) ;
return F_99 ( V_686 ) ;
}
V_677 . V_681 = V_686 -> V_126 . V_568 ;
V_677 . V_684 = F_15 ( V_677 . V_681 , V_38 ) ;
if ( ! V_677 . V_684 ) {
F_20 ( V_686 ) ;
return - V_39 ;
}
V_677 . V_682 = sizeof( struct V_690 ) ;
V_106 = F_255 ( V_2 , V_688 ,
V_691 + V_687 ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
memcpy ( & V_123 -> V_110 . V_457 . V_110 . V_679 , & V_686 -> V_123 , V_687 ) ;
V_26 = F_320 ( V_2 , V_106 , V_692 + V_687 ,
F_325 , ( void * ) & V_677 ) ;
if ( V_26 )
F_51 ( 2 , L_283 ,
F_64 ( V_2 ) , V_26 ) ;
else {
if ( F_330 ( V_684 , V_677 . V_684 , V_677 . V_681 ) )
V_26 = - V_689 ;
}
F_20 ( V_686 ) ;
F_20 ( V_677 . V_684 ) ;
return V_26 ;
}
static int F_331 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned long V_110 )
{
struct V_122 * V_123 ;
struct V_693 * V_694 ;
char * V_695 ;
int V_696 ;
F_11 ( V_2 , 3 , L_284 ) ;
V_123 = (struct V_122 * ) V_110 ;
V_694 = (struct V_693 * ) V_118 -> V_378 ;
V_696 = V_123 -> V_110 . V_457 . V_126 . V_465 ;
V_695 = ( char * ) V_110 + 28 ;
if ( V_696 > ( V_694 -> V_697 - V_694 -> V_698 ) ) {
V_123 -> V_126 . V_132 = V_699 ;
return 0 ;
}
memcpy ( ( V_694 -> V_66 + V_694 -> V_698 ) , V_695 ,
V_696 ) ;
V_694 -> V_698 += V_696 ;
if ( V_123 -> V_110 . V_457 . V_126 . V_468 <
V_123 -> V_110 . V_457 . V_126 . V_467 )
return 1 ;
return 0 ;
}
int F_332 ( struct V_1 * V_2 , char T_4 * V_684 )
{
int V_26 = 0 ;
struct V_105 * V_106 ;
struct V_122 * V_123 ;
struct V_700 * V_701 ;
struct V_702 V_703 ;
struct V_693 V_694 ;
void T_4 * V_30 ;
F_11 ( V_2 , 3 , L_285 ) ;
if ( ! F_317 ( V_2 , V_704 ) ) {
V_26 = - V_334 ;
goto V_60;
}
if ( F_328 ( & V_703 , V_684 ,
sizeof( struct V_702 ) ) ) {
V_26 = - V_689 ;
goto V_60;
}
V_694 . V_697 = V_703 . V_697 ;
V_694 . V_698 = 0 ;
V_694 . V_66 = F_15 ( V_703 . V_697 , V_38 ) ;
if ( ! V_694 . V_66 ) {
V_26 = - V_39 ;
goto V_60;
}
V_106 = F_255 ( V_2 , V_704 ,
sizeof( struct V_632 ) +
sizeof( struct V_700 ) ) ;
V_123 = (struct V_122 * ) ( V_106 -> V_110 + V_382 ) ;
V_701 = & V_123 -> V_110 . V_457 . V_110 . V_705 ;
V_701 -> V_626 = V_703 . V_127 ;
V_26 = F_251 ( V_2 , V_106 , F_331 ,
& V_694 ) ;
if ( ! V_26 ) {
if ( F_333 () )
V_30 = F_334 ( V_703 . V_32 ) ;
else
V_30 = ( void T_4 * ) ( unsigned long ) V_703 . V_32 ;
if ( F_330 ( V_30 , V_694 . V_66 ,
V_694 . V_698 ) ) {
V_26 = - V_689 ;
goto V_706;
}
V_703 . V_698 = V_694 . V_698 ;
if ( F_330 ( V_684 , & V_703 ,
sizeof( struct V_702 ) ) )
V_26 = - V_689 ;
} else
if ( V_26 == V_699 )
V_26 = - V_689 ;
V_706:
F_20 ( V_694 . V_66 ) ;
V_60:
return V_26 ;
}
static inline int F_335 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
return 2 ;
default:
return 0 ;
}
}
static void F_336 ( struct V_1 * V_2 )
{
int V_26 ;
int V_239 ;
char * V_340 ;
struct V_178 * V_707 ;
int V_708 = 0 ;
F_24 ( V_52 , 2 , L_286 ) ;
V_707 = F_26 ( V_2 ) ;
if ( ! V_707 -> V_709 ) {
V_708 = 1 ;
V_26 = F_337 ( V_707 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_60;
}
}
V_26 = F_148 ( V_2 , ( void * * ) & V_340 , & V_239 ) ;
if ( V_26 ) {
F_51 ( 2 , L_287 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_710;
}
F_151 ( V_2 , V_340 ) ;
if ( V_708 )
F_152 ( V_2 , V_340 ) ;
F_20 ( V_340 ) ;
V_26 = F_338 ( V_707 , & V_2 -> V_711 ) ;
if ( V_26 )
F_27 ( V_52 , 2 , L_183 , V_26 ) ;
F_27 ( V_52 , 2 , L_288 , V_2 -> V_711 . V_712 ) ;
F_27 ( V_52 , 2 , L_289 , V_2 -> V_711 . V_713 ) ;
F_27 ( V_52 , 2 , L_289 , V_2 -> V_711 . V_714 ) ;
F_27 ( V_52 , 2 , L_290 , V_2 -> V_711 . V_715 ) ;
if ( ! ( ( V_2 -> V_711 . V_712 != V_716 ) ||
( ( V_2 -> V_711 . V_713 & V_717 ) == 0 ) ||
( ( V_2 -> V_711 . V_714 & V_718 ) == 0 ) ) ) {
F_72 ( & V_2 -> V_72 -> V_73 ,
L_291 ) ;
} else {
V_2 -> V_49 . V_50 = V_542 ;
}
V_710:
if ( V_708 == 1 )
F_339 ( V_707 ) ;
V_60:
return;
}
static inline void F_340 ( struct V_1 * V_2 ,
struct V_56 * * V_719 ,
void (* * F_341) ( struct V_178 * , int , unsigned long ) ) {
int V_33 ;
if ( V_2 -> V_49 . V_50 == V_51 ) {
int V_168 = V_55 *
( V_2 -> V_35 . V_59 - 1 ) ;
V_33 = V_55 * ( V_2 -> V_35 . V_59 - 1 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_719 [ V_168 + V_33 ] = (struct V_56 * )
F_289 ( V_2 -> V_35 . V_53 -> V_65 [ V_33 ] . V_66 ) ;
}
F_341 [ V_2 -> V_35 . V_59 - 1 ] = NULL ;
}
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_720 V_721 ;
char * V_722 ;
struct V_56 * * V_719 ;
void (* * F_341) ( struct V_178 * , int , unsigned long );
struct V_56 * * V_723 ;
int V_33 , V_34 , V_724 ;
int V_26 = 0 ;
F_24 ( V_52 , 2 , L_292 ) ;
V_722 = F_15 ( V_55 * sizeof( char ) ,
V_38 ) ;
if ( ! V_722 ) {
V_26 = - V_39 ;
goto V_725;
}
F_216 ( V_2 , V_722 ) ;
F_220 ( V_2 , V_722 ) ;
V_719 = F_15 ( V_2 -> V_35 . V_59 *
V_55 * sizeof( void * ) ,
V_38 ) ;
if ( ! V_719 ) {
V_26 = - V_39 ;
goto V_726;
}
for ( V_33 = 0 ; V_33 < V_55 ; ++ V_33 ) {
V_719 [ V_33 ] = (struct V_56 * )
F_289 ( V_2 -> V_35 . V_244 -> V_65 [ V_33 ] . V_66 ) ;
}
F_341 = F_15 ( sizeof( void * ) * V_2 -> V_35 . V_59 ,
V_38 ) ;
if ( ! F_341 ) {
V_26 = - V_39 ;
goto V_727;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_59 ; ++ V_33 )
F_341 [ V_33 ] = V_2 -> V_276 -> V_728 ;
F_340 ( V_2 , V_719 , F_341 ) ;
V_723 =
F_15 ( V_2 -> V_35 . V_68 * V_55 *
sizeof( void * ) , V_38 ) ;
if ( ! V_723 ) {
V_26 = - V_39 ;
goto V_729;
}
for ( V_33 = 0 , V_724 = 0 ; V_33 < V_2 -> V_35 . V_68 ; ++ V_33 )
for ( V_34 = 0 ; V_34 < V_55 ; ++ V_34 , ++ V_724 ) {
V_723 [ V_724 ] = (struct V_56 * ) F_289 (
V_2 -> V_35 . V_70 [ V_33 ] -> V_65 [ V_34 ] -> V_66 ) ;
}
memset ( & V_721 , 0 , sizeof( struct V_720 ) ) ;
V_721 . V_179 = F_26 ( V_2 ) ;
V_721 . V_730 = F_335 ( V_2 ) ;
V_721 . V_731 = 0 ;
V_721 . V_722 = V_722 ;
V_721 . V_732 = V_2 -> V_35 . V_59 ;
V_721 . V_733 = V_2 -> V_35 . V_68 ;
V_721 . V_734 = V_2 -> V_276 -> V_734 ;
V_721 . V_735 = V_2 -> V_276 -> V_735 ;
V_721 . V_736 = F_341 ;
V_721 . V_737 = ( unsigned long ) V_2 ;
V_721 . V_738 = ( void * * ) V_719 ;
V_721 . V_739 = ( void * * ) V_723 ;
V_721 . V_740 = V_2 -> V_35 . V_67 ;
V_721 . V_741 =
( V_2 -> V_3 . type == V_6 ) ? 8 : 32 ;
if ( F_42 ( & V_2 -> V_35 . V_44 , V_329 ,
V_325 ) == V_329 ) {
V_26 = F_342 ( & V_721 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
goto V_60;
}
V_26 = F_343 ( & V_721 ) ;
if ( V_26 ) {
F_43 ( & V_2 -> V_35 . V_44 , V_329 ) ;
F_147 ( F_26 ( V_2 ) ) ;
}
}
switch ( V_2 -> V_49 . V_50 ) {
case V_51 :
F_72 ( & V_2 -> V_72 -> V_73 , L_293 ) ;
break;
case V_271 :
F_72 ( & V_2 -> V_72 -> V_73 , L_294 ) ;
break;
default:
break;
}
V_60:
F_20 ( V_723 ) ;
V_729:
F_20 ( F_341 ) ;
V_727:
F_20 ( V_719 ) ;
V_726:
F_20 ( V_722 ) ;
V_725:
return V_26 ;
}
static void F_344 ( struct V_1 * V_2 )
{
F_24 ( V_52 , 2 , L_295 ) ;
F_29 ( V_52 , 2 , & V_2 , sizeof( void * ) ) ;
F_115 ( & V_2 -> V_107 ) ;
F_115 ( & V_2 -> V_142 ) ;
if ( V_2 -> V_73 )
F_345 ( V_2 -> V_73 ) ;
F_20 ( V_2 -> V_284 ) ;
F_112 ( V_2 ) ;
F_346 ( & V_2 -> V_295 ) ;
F_20 ( V_2 ) ;
}
int F_347 ( struct V_1 * V_2 )
{
int V_742 = 0 ;
int V_26 ;
F_24 ( V_52 , 2 , L_296 ) ;
F_43 ( & V_2 -> V_509 , 0 ) ;
F_116 ( V_2 ) ;
V_743:
if ( V_742 )
F_51 ( 2 , L_297 ,
F_52 ( & V_2 -> V_72 -> V_73 ) ) ;
F_339 ( F_26 ( V_2 ) ) ;
F_339 ( F_348 ( V_2 ) ) ;
F_339 ( F_135 ( V_2 ) ) ;
V_26 = F_337 ( F_135 ( V_2 ) ) ;
if ( V_26 )
goto V_744;
V_26 = F_337 ( F_348 ( V_2 ) ) ;
if ( V_26 )
goto V_744;
V_26 = F_337 ( F_26 ( V_2 ) ) ;
if ( V_26 )
goto V_744;
V_26 = F_145 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
V_744:
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_298 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_35 , V_26 ) ;
if ( ++ V_742 > 3 )
goto V_60;
else
goto V_743;
}
F_336 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
V_26 = F_157 ( & V_2 -> V_107 , F_169 ) ;
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_299 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
if ( -- V_742 < 0 )
goto V_60;
else
goto V_743;
}
V_26 = F_157 ( & V_2 -> V_142 , F_166 ) ;
if ( V_26 == - V_318 ) {
F_24 ( V_52 , 2 , L_300 ) ;
return V_26 ;
} else if ( V_26 ) {
F_27 ( V_52 , 2 , L_181 , V_26 ) ;
if ( -- V_742 < 0 )
goto V_60;
else
goto V_743;
}
V_2 -> V_116 = 0 ;
V_26 = F_226 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_182 , V_26 ) ;
goto V_60;
}
V_2 -> V_49 . V_471 . V_461 = 0 ;
V_2 -> V_49 . V_460 . V_461 = 0 ;
V_2 -> V_3 . V_475 = 0 ;
F_258 ( V_2 , V_385 ) ;
if ( F_310 ( V_2 , V_745 ) )
F_256 ( V_2 ) ;
if ( F_317 ( V_2 , V_746 ) )
F_260 ( V_2 ) ;
return 0 ;
V_60:
F_50 ( & V_2 -> V_72 -> V_73 , L_101
L_102 ) ;
F_51 ( 2 , L_301 ,
F_52 ( & V_2 -> V_72 -> V_73 ) , V_26 ) ;
return V_26 ;
}
static inline int F_349 ( struct V_434 * V_747 ,
struct V_748 * V_231 ,
struct V_218 * * V_749 , int V_168 , int * V_750 , int V_568 )
{
struct V_430 * V_430 = F_239 ( V_231 -> V_236 ) ;
if ( * V_749 == NULL ) {
if ( V_747 -> V_245 ) {
* V_749 = V_747 -> V_245 ;
V_747 -> V_245 = NULL ;
} else {
* V_749 = F_243 ( V_435 + V_436 ) ;
if ( ! ( * V_749 ) )
return - V_39 ;
}
F_350 ( * V_749 , V_436 ) ;
if ( V_568 <= V_435 ) {
memcpy ( F_351 ( * V_749 , V_568 ) , V_231 -> V_236 + V_168 ,
V_568 ) ;
} else {
F_352 ( V_430 ) ;
memcpy ( F_351 ( * V_749 , V_435 ) ,
V_231 -> V_236 + V_168 , V_435 ) ;
F_353 ( * V_749 , * V_750 , V_430 ,
V_168 + V_435 ,
V_568 - V_435 ) ;
( * V_749 ) -> V_568 += V_568 - V_435 ;
( * V_749 ) -> V_147 += V_568 - V_435 ;
( * V_749 ) -> V_751 += V_568 - V_435 ;
( * V_750 ) ++ ;
}
} else {
F_352 ( V_430 ) ;
F_353 ( * V_749 , * V_750 , V_430 , V_168 , V_568 ) ;
( * V_749 ) -> V_568 += V_568 ;
( * V_749 ) -> V_147 += V_568 ;
( * V_749 ) -> V_751 += V_568 ;
( * V_750 ) ++ ;
}
return 0 ;
}
struct V_218 * F_354 ( struct V_1 * V_2 ,
struct V_434 * V_747 ,
struct V_748 * * V_752 , int * V_753 ,
struct V_586 * * V_126 )
{
struct V_748 * V_231 = * V_752 ;
struct V_56 * V_66 = V_747 -> V_66 ;
int V_168 = * V_753 ;
struct V_218 * V_219 = NULL ;
int V_754 = 0 ;
void * V_755 ;
int V_568 ;
int V_756 = 0 ;
int V_757 = 0 ;
int V_579 = 0 ;
if ( V_231 -> V_239 < V_168 + sizeof( struct V_586 ) ) {
if ( F_355 ( V_231 ) )
return NULL ;
V_231 ++ ;
V_168 = 0 ;
if ( V_231 -> V_239 < sizeof( struct V_586 ) )
return NULL ;
}
* V_126 = V_231 -> V_236 + V_168 ;
V_168 += sizeof( struct V_586 ) ;
switch ( ( * V_126 ) -> V_126 . V_758 . V_308 ) {
case V_759 :
V_754 = ( * V_126 ) -> V_126 . V_758 . V_760 ;
break;
case V_761 :
V_754 = ( * V_126 ) -> V_126 . V_590 . V_239 ;
V_756 = V_436 ;
break;
case V_762 :
V_754 = ( * V_126 ) -> V_126 . V_763 . V_764 ;
V_756 = sizeof( struct V_586 ) ;
break;
default:
break;
}
if ( ! V_754 )
return NULL ;
if ( ( ( V_754 >= V_2 -> V_49 . V_267 ) &&
( ! ( V_2 -> V_3 . type == V_9 ) ) &&
( ! F_34 ( & V_2 -> V_509 ) ) ) ||
( V_2 -> V_49 . V_50 == V_51 ) ) {
V_757 = 1 ;
} else {
V_219 = F_243 ( V_754 + V_756 ) ;
if ( ! V_219 )
goto V_765;
if ( V_756 )
F_350 ( V_219 , V_756 ) ;
}
V_755 = V_231 -> V_236 + V_168 ;
while ( V_754 ) {
V_568 = F_356 ( V_754 , ( int ) ( V_231 -> V_239 - V_168 ) ) ;
if ( V_568 ) {
if ( V_757 ) {
if ( F_349 ( V_747 , V_231 ,
& V_219 , V_168 , & V_579 , V_568 ) )
goto V_765;
} else {
memcpy ( F_351 ( V_219 , V_568 ) , V_755 ,
V_568 ) ;
}
}
V_754 -= V_568 ;
if ( V_754 ) {
if ( F_355 ( V_231 ) ) {
F_11 ( V_2 , 4 , L_302 ) ;
F_357 ( V_2 , 2 , V_66 , sizeof( void * ) ) ;
F_109 ( V_219 ) ;
V_2 -> V_504 . V_664 ++ ;
return NULL ;
}
V_231 ++ ;
V_168 = 0 ;
V_755 = V_231 -> V_236 ;
} else {
V_168 += V_568 ;
}
}
* V_752 = V_231 ;
* V_753 = V_168 ;
if ( V_757 && V_2 -> V_49 . V_266 ) {
V_2 -> V_432 . V_766 ++ ;
V_2 -> V_432 . V_767 += F_296 ( V_219 ) -> V_570 ;
}
return V_219 ;
V_765:
if ( F_358 () ) {
F_11 ( V_2 , 2 , L_303 ) ;
}
V_2 -> V_504 . V_505 ++ ;
return NULL ;
}
static void F_359 ( void )
{
int V_768 ;
for ( V_768 = 0 ; V_768 < V_769 ; V_768 ++ ) {
F_360 ( V_770 [ V_768 ] . V_308 ) ;
V_770 [ V_768 ] . V_308 = NULL ;
}
}
void F_361 ( T_5 * V_308 , int V_367 , char * V_771 , ... )
{
char V_772 [ 32 ] ;
T_6 args ;
if ( V_367 > V_308 -> V_367 )
return;
va_start ( args , V_771 ) ;
vsnprintf ( V_772 , sizeof( V_772 ) , V_771 , args ) ;
va_end ( args ) ;
F_362 ( V_308 , V_367 , V_772 ) ;
}
static int F_363 ( void )
{
int V_332 ;
int V_768 ;
for ( V_768 = 0 ; V_768 < V_769 ; V_768 ++ ) {
V_770 [ V_768 ] . V_308 = F_364 ( V_770 [ V_768 ] . V_493 ,
V_770 [ V_768 ] . V_773 ,
V_770 [ V_768 ] . V_774 ,
V_770 [ V_768 ] . V_147 ) ;
if ( V_770 [ V_768 ] . V_308 == NULL ) {
F_359 () ;
return - V_39 ;
}
V_332 = F_365 ( V_770 [ V_768 ] . V_308 , V_770 [ V_768 ] . V_775 ) ;
if ( V_332 ) {
F_359 () ;
return V_332 ;
}
F_366 ( V_770 [ V_768 ] . V_308 , V_770 [ V_768 ] . V_367 ) ;
}
return 0 ;
}
int F_367 ( struct V_1 * V_2 ,
enum V_776 V_276 )
{
int V_26 = 0 ;
F_368 ( & V_777 ) ;
switch ( V_276 ) {
case V_778 :
V_2 -> V_276 = F_369 (
F_370 ( V_779 ) , L_304 ) ;
break;
case V_780 :
V_2 -> V_276 = F_369 (
F_370 ( V_781 ) , L_305 ) ;
break;
}
if ( ! V_2 -> V_276 ) {
F_30 ( & V_2 -> V_72 -> V_73 , L_306
L_307 , V_276 ) ;
V_26 = - V_397 ;
}
F_371 ( & V_777 ) ;
return V_26 ;
}
void F_372 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 . V_301 )
F_373 ( V_781 ) ;
else
F_373 ( V_779 ) ;
V_2 -> V_276 = NULL ;
}
static int F_374 ( struct V_782 * V_72 )
{
struct V_1 * V_2 ;
struct V_783 * V_73 ;
int V_26 ;
unsigned long V_21 ;
char V_784 [ 20 ] ;
F_24 ( V_52 , 2 , L_308 ) ;
V_73 = & V_72 -> V_73 ;
if ( ! F_375 ( V_73 ) )
return - V_785 ;
F_27 ( V_52 , 2 , L_186 , F_52 ( & V_72 -> V_73 ) ) ;
V_2 = F_132 () ;
if ( ! V_2 ) {
F_27 ( V_52 , 2 , L_35 , - V_39 ) ;
V_26 = - V_39 ;
goto V_786;
}
snprintf ( V_784 , sizeof( V_784 ) , L_309 ,
F_52 ( & V_72 -> V_73 ) ) ;
V_2 -> V_787 = F_364 ( V_784 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_787 ) {
F_27 ( V_52 , 2 , L_186 , L_310 ) ;
V_26 = - V_39 ;
goto V_788;
}
F_365 ( V_2 -> V_787 , & V_789 ) ;
V_2 -> V_107 . V_112 = V_72 -> V_179 [ 0 ] ;
V_2 -> V_142 . V_112 = V_72 -> V_179 [ 1 ] ;
V_2 -> V_110 . V_112 = V_72 -> V_179 [ 2 ] ;
F_376 ( & V_72 -> V_73 , V_2 ) ;
V_2 -> V_72 = V_72 ;
V_72 -> V_179 [ 0 ] -> V_790 = F_100 ;
V_72 -> V_179 [ 1 ] -> V_790 = F_100 ;
V_72 -> V_179 [ 2 ] -> V_790 = F_100 ;
V_26 = F_134 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_136 , V_26 ) ;
goto V_791;
}
V_26 = F_125 ( V_2 ) ;
if ( V_26 ) {
F_27 ( V_52 , 2 , L_131 , V_26 ) ;
goto V_791;
}
if ( V_2 -> V_3 . type == V_9 )
V_72 -> V_73 . type = & V_792 ;
else
V_72 -> V_73 . type = & V_793 ;
switch ( V_2 -> V_3 . type ) {
case V_9 :
case V_7 :
V_26 = F_367 ( V_2 , V_780 ) ;
if ( V_26 )
goto V_791;
V_26 = V_2 -> V_276 -> V_794 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_795;
case V_5 :
case V_8 :
default:
break;
}
F_377 ( & V_796 . V_797 , V_21 ) ;
F_84 ( & V_2 -> V_31 , & V_796 . V_31 ) ;
F_378 ( & V_796 . V_797 , V_21 ) ;
F_336 ( V_2 ) ;
return 0 ;
V_795:
F_372 ( V_2 ) ;
V_791:
F_360 ( V_2 -> V_787 ) ;
V_788:
F_344 ( V_2 ) ;
V_786:
F_379 ( V_73 ) ;
return V_26 ;
}
static void F_380 ( struct V_782 * V_72 )
{
unsigned long V_21 ;
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
F_24 ( V_52 , 2 , L_311 ) ;
if ( V_2 -> V_276 ) {
V_2 -> V_276 -> remove ( V_72 ) ;
F_372 ( V_2 ) ;
}
F_360 ( V_2 -> V_787 ) ;
F_377 ( & V_796 . V_797 , V_21 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_378 ( & V_796 . V_797 , V_21 ) ;
F_344 ( V_2 ) ;
F_376 ( & V_72 -> V_73 , NULL ) ;
F_379 ( & V_72 -> V_73 ) ;
return;
}
static int F_382 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
int V_26 = 0 ;
int V_798 ;
if ( ! V_2 -> V_276 ) {
if ( V_2 -> V_3 . type == V_6 )
V_798 = V_778 ;
else
V_798 = V_780 ;
V_26 = F_367 ( V_2 , V_798 ) ;
if ( V_26 )
goto V_799;
V_26 = V_2 -> V_276 -> V_794 ( V_2 -> V_72 ) ;
if ( V_26 )
goto V_799;
}
V_26 = V_2 -> V_276 -> V_800 ( V_72 ) ;
V_799:
return V_26 ;
}
static int F_383 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
return V_2 -> V_276 -> V_801 ( V_72 ) ;
}
static void F_384 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_802 )
V_2 -> V_276 -> V_802 ( V_72 ) ;
}
static int F_385 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_803 )
return V_2 -> V_276 -> V_803 ( V_72 ) ;
return 0 ;
}
static void F_386 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_804 )
V_2 -> V_276 -> V_804 ( V_72 ) ;
}
static int F_387 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_805 )
return V_2 -> V_276 -> V_805 ( V_72 ) ;
return 0 ;
}
static int F_388 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_806 )
return V_2 -> V_276 -> V_806 ( V_72 ) ;
return 0 ;
}
static int F_389 ( struct V_782 * V_72 )
{
struct V_1 * V_2 = F_381 ( & V_72 -> V_73 ) ;
if ( V_2 -> V_276 && V_2 -> V_276 -> V_807 )
return V_2 -> V_276 -> V_807 ( V_72 ) ;
return 0 ;
}
static T_7 F_390 ( struct V_808 * V_809 ,
const char * V_217 , T_8 V_151 )
{
int V_799 ;
V_799 = F_391 ( V_810 ,
& V_811 , 3 , V_217 ) ;
return V_799 ? V_799 : V_151 ;
}
int F_392 ( struct V_603 * V_73 , int V_812 )
{
switch ( V_812 ) {
case V_813 :
return ( sizeof( V_814 ) / V_815 ) ;
default:
return - V_397 ;
}
}
void F_393 ( struct V_603 * V_73 ,
struct V_816 * V_504 , T_9 * V_110 )
{
struct V_1 * V_2 = V_73 -> V_608 ;
V_110 [ 0 ] = V_2 -> V_504 . V_817 -
V_2 -> V_432 . V_818 ;
V_110 [ 1 ] = V_2 -> V_432 . V_819 ;
V_110 [ 2 ] = V_2 -> V_504 . V_820 -
V_2 -> V_432 . V_821 ;
V_110 [ 3 ] = V_2 -> V_432 . V_533 ;
V_110 [ 4 ] = V_2 -> V_504 . V_820 - V_2 -> V_432 . V_821
- V_2 -> V_432 . V_594 ;
V_110 [ 5 ] = V_2 -> V_432 . V_533 - V_2 -> V_432 . V_537 ;
V_110 [ 6 ] = V_2 -> V_432 . V_594 ;
V_110 [ 7 ] = V_2 -> V_432 . V_537 ;
V_110 [ 8 ] = V_2 -> V_432 . V_822 ;
V_110 [ 9 ] = V_2 -> V_432 . V_823 ;
V_110 [ 10 ] = V_2 -> V_432 . V_766 ;
V_110 [ 11 ] = V_2 -> V_432 . V_767 ;
V_110 [ 12 ] = V_2 -> V_432 . V_433 ;
V_110 [ 13 ] = ( V_2 -> V_432 . V_824 >> 10 ) ;
V_110 [ 14 ] = V_2 -> V_432 . V_825 ;
V_110 [ 15 ] = V_2 -> V_432 . V_519 ;
V_110 [ 16 ] = V_2 -> V_432 . V_522 ;
V_110 [ 17 ] = V_521 ;
V_110 [ 18 ] = V_518 ;
V_110 [ 19 ] = F_34 ( & V_2 -> V_35 . V_70 [ 0 ] -> V_440 ) ;
V_110 [ 20 ] = ( V_2 -> V_35 . V_68 > 1 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 1 ] -> V_440 ) : 0 ;
V_110 [ 21 ] = ( V_2 -> V_35 . V_68 > 2 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 2 ] -> V_440 ) : 0 ;
V_110 [ 22 ] = ( V_2 -> V_35 . V_68 > 3 ) ?
F_34 ( & V_2 -> V_35 . V_70 [ 3 ] -> V_440 ) : 0 ;
V_110 [ 23 ] = V_2 -> V_432 . V_826 ;
V_110 [ 24 ] = V_2 -> V_432 . V_827 ;
V_110 [ 25 ] = V_2 -> V_432 . V_513 ;
V_110 [ 26 ] = V_2 -> V_432 . V_511 ;
V_110 [ 27 ] = V_2 -> V_432 . V_556 ;
V_110 [ 28 ] = V_2 -> V_432 . V_552 ;
V_110 [ 29 ] = V_2 -> V_432 . V_828 ;
V_110 [ 30 ] = V_2 -> V_432 . V_829 ;
V_110 [ 31 ] = V_2 -> V_432 . V_530 ;
V_110 [ 32 ] = V_2 -> V_432 . V_526 ;
V_110 [ 33 ] = V_2 -> V_432 . V_830 ;
V_110 [ 34 ] = V_2 -> V_432 . V_831 ;
V_110 [ 35 ] = V_2 -> V_432 . V_544 ;
V_110 [ 36 ] = V_2 -> V_432 . V_548 ;
}
void F_394 ( struct V_603 * V_73 , V_674 V_812 , T_3 * V_110 )
{
switch ( V_812 ) {
case V_813 :
memcpy ( V_110 , & V_814 ,
sizeof( V_814 ) ) ;
break;
default:
F_58 ( 1 ) ;
break;
}
}
void F_395 ( struct V_603 * V_73 ,
struct V_832 * V_3 )
{
struct V_1 * V_2 = V_73 -> V_608 ;
if ( V_2 -> V_49 . V_301 )
strcpy ( V_3 -> V_833 , L_305 ) ;
else
strcpy ( V_3 -> V_833 , L_304 ) ;
strcpy ( V_3 -> V_834 , L_312 ) ;
strcpy ( V_3 -> V_835 , V_2 -> V_3 . V_296 ) ;
sprintf ( V_3 -> V_836 , L_313 ,
F_396 ( V_2 ) ,
F_397 ( V_2 ) ,
F_398 ( V_2 ) ) ;
}
int F_399 ( struct V_603 * V_837 ,
struct V_838 * V_839 )
{
struct V_1 * V_2 = V_837 -> V_608 ;
enum V_442 V_10 ;
if ( ( V_2 -> V_3 . type == V_6 ) || ( V_2 -> V_3 . V_4 ) )
V_10 = V_14 ;
else
V_10 = V_2 -> V_3 . V_10 ;
V_839 -> V_840 = V_841 ;
V_839 -> V_842 = V_843 ;
V_839 -> V_844 = V_845 ;
V_839 -> V_846 = V_847 ;
V_839 -> V_848 = V_849 ;
switch ( V_10 ) {
case V_11 :
case V_15 :
V_839 -> V_842 |= V_850 |
V_851 |
V_852 |
V_853 |
V_854 ;
V_839 -> V_844 |= V_855 |
V_856 |
V_857 |
V_858 |
V_859 ;
V_839 -> V_860 = V_861 ;
V_839 -> V_862 = V_863 ;
break;
case V_13 :
case V_17 :
V_839 -> V_842 |= V_850 |
V_851 |
V_852 |
V_853 |
V_864 |
V_865 |
V_866 ;
V_839 -> V_844 |= V_855 |
V_856 |
V_857 |
V_858 |
V_867 |
V_868 |
V_869 ;
V_839 -> V_860 = V_870 ;
V_839 -> V_862 = V_871 ;
break;
case V_14 :
V_839 -> V_842 |= V_850 |
V_851 |
V_852 |
V_853 |
V_864 |
V_865 |
V_872 |
V_866 ;
V_839 -> V_844 |= V_855 |
V_856 |
V_857 |
V_858 |
V_867 |
V_868 |
V_873 |
V_869 ;
V_839 -> V_860 = V_874 ;
V_839 -> V_862 = V_871 ;
break;
default:
V_839 -> V_842 |= V_850 |
V_851 |
V_854 ;
V_839 -> V_844 |= V_855 |
V_856 |
V_859 ;
V_839 -> V_860 = V_875 ;
V_839 -> V_862 = V_863 ;
}
return 0 ;
}
static int T_10 F_400 ( void )
{
int V_26 ;
F_401 ( L_314 ) ;
F_119 ( & V_796 . V_31 ) ;
F_402 ( & V_796 . V_797 ) ;
F_126 ( & V_777 ) ;
V_26 = F_363 () ;
if ( V_26 )
goto V_876;
V_810 = F_403 ( L_315 ) ;
V_26 = F_98 ( V_810 ) ? F_99 ( V_810 ) : 0 ;
if ( V_26 )
goto V_877;
V_238 = F_404 ( L_316 ,
sizeof( struct V_586 ) + V_436 , 64 , 0 , NULL ) ;
if ( ! V_238 ) {
V_26 = - V_39 ;
goto V_878;
}
V_94 = F_404 ( L_317 ,
sizeof( struct V_89 ) , 0 , 0 , NULL ) ;
if ( ! V_94 ) {
V_26 = - V_39 ;
goto V_879;
}
V_26 = F_405 ( & V_880 ) ;
if ( V_26 )
goto V_881;
V_811 . V_833 . V_882 = V_883 ;
V_26 = F_406 ( & V_811 ) ;
if ( V_26 )
goto V_884;
return 0 ;
V_884:
F_407 ( & V_880 ) ;
V_881:
F_408 ( V_94 ) ;
V_879:
F_408 ( V_238 ) ;
V_878:
F_409 ( V_810 ) ;
V_877:
F_359 () ;
V_876:
F_410 ( L_318 ) ;
return V_26 ;
}
static void T_11 F_411 ( void )
{
F_412 ( & V_811 ) ;
F_407 ( & V_880 ) ;
F_408 ( V_94 ) ;
F_408 ( V_238 ) ;
F_409 ( V_810 ) ;
F_359 () ;
F_401 ( L_319 ) ;
}
