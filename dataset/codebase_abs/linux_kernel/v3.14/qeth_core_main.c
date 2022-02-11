static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 , 2 , L_1 ) ;
F_4 () ;
F_5 ( V_4 -> V_6 ) ;
F_6 () ;
F_7 ( V_4 -> V_7 ) ;
}
void F_8 ( struct V_3 * V_4 )
{
F_3 ( V_4 , 2 , L_2 ) ;
F_9 ( V_8 , & V_4 -> V_5 ) ;
}
static inline const char * F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 . V_10 ) {
switch ( V_4 -> V_9 . type ) {
case V_11 :
return L_3 ;
case V_12 :
return L_4 ;
case V_13 :
return L_5 ;
case V_14 :
return L_6 ;
default:
return L_7 ;
}
} else {
switch ( V_4 -> V_9 . type ) {
case V_11 :
return L_8 ;
case V_12 :
return L_9 ;
case V_15 :
return L_10 ;
case V_13 :
return L_11 ;
case V_14 :
return L_12 ;
default:
return L_7 ;
}
}
return L_13 ;
}
const char * F_11 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 . V_10 ) {
switch ( V_4 -> V_9 . type ) {
case V_11 :
return L_14 ;
case V_12 :
return L_15 ;
case V_13 :
return L_16 ;
case V_14 :
return L_17 ;
default:
return L_18 ;
}
} else {
switch ( V_4 -> V_9 . type ) {
case V_11 :
switch ( V_4 -> V_9 . V_16 ) {
case V_17 :
return L_19 ;
case V_18 :
return L_20 ;
case V_19 :
return L_21 ;
case V_20 :
return L_22 ;
case V_21 :
return L_23 ;
case V_22 :
return L_24 ;
case V_23 :
return L_25 ;
case V_24 :
return L_26 ;
default:
return L_27 ;
}
case V_12 :
return L_28 ;
case V_15 :
return L_29 ;
case V_13 :
return L_30 ;
case V_14 :
return L_31 ;
default:
return L_18 ;
}
}
return L_32 ;
}
void F_12 ( struct V_3 * V_4 )
{
V_4 -> V_25 = V_26 ;
}
void F_13 ( struct V_3 * V_4 )
{
V_4 -> V_25 = NULL ;
}
static bool F_14 ( const struct V_3 * V_4 )
{
return V_4 -> V_25 == V_26 ;
}
void F_15 ( struct V_3 * V_4 , unsigned long V_27 ,
int V_28 )
{
unsigned long V_29 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
V_4 -> V_31 = V_27 ;
if ( V_28 )
V_4 -> V_32 &= V_27 ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
F_18 ( & V_4 -> V_33 ) ;
}
int F_19 ( struct V_3 * V_4 , unsigned long V_27 )
{
unsigned long V_29 ;
int V_34 = 0 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
V_34 = ( V_4 -> V_35 & V_27 ) ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
return V_34 ;
}
int F_20 ( struct V_3 * V_4 , unsigned long V_27 )
{
if ( F_14 ( V_4 ) )
return 0 ;
return F_21 ( V_4 -> V_33 ,
F_19 ( V_4 , V_27 ) == 0 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_36 * V_37 , * V_38 ;
F_3 ( V_4 , 5 , L_33 ) ;
F_23 (pool_entry, tmp,
&card->qdio.in_buf_pool.entry_list, list) {
F_24 ( & V_37 -> V_39 ) ;
}
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_36 * V_37 ;
void * V_40 ;
int V_41 , V_42 ;
F_3 ( V_4 , 5 , L_34 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_44 . V_45 ; ++ V_41 ) {
V_37 = F_26 ( sizeof( * V_37 ) , V_46 ) ;
if ( ! V_37 ) {
F_27 ( V_4 ) ;
return - V_47 ;
}
for ( V_42 = 0 ; V_42 < F_28 ( V_4 ) ; ++ V_42 ) {
V_40 = ( void * ) F_29 ( V_46 ) ;
if ( ! V_40 ) {
while ( V_42 > 0 )
F_30 ( ( unsigned long )
V_37 -> V_48 [ -- V_42 ] ) ;
F_31 ( V_37 ) ;
F_27 ( V_4 ) ;
return - V_47 ;
}
V_37 -> V_48 [ V_42 ] = V_40 ;
}
F_32 ( & V_37 -> V_49 ,
& V_4 -> V_43 . V_44 . V_50 ) ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 , int V_51 )
{
F_3 ( V_4 , 2 , L_35 ) ;
if ( ( V_4 -> V_52 != V_53 ) &&
( V_4 -> V_52 != V_54 ) )
return - V_55 ;
F_22 ( V_4 ) ;
F_27 ( V_4 ) ;
V_4 -> V_43 . V_56 . V_45 = V_51 ;
V_4 -> V_43 . V_44 . V_45 = V_51 ;
return F_25 ( V_4 ) ;
}
static inline int F_34 ( struct V_3 * V_4 )
{
int V_34 ;
if ( V_4 -> V_57 . V_58 == V_59 ) {
F_35 ( V_60 , 2 , L_36 ) ;
memset ( V_4 -> V_43 . V_61 -> V_62 , 0 ,
V_63 * sizeof( struct V_64 ) ) ;
V_4 -> V_43 . V_61 -> V_65 = 127 ;
V_34 = F_36 ( F_37 ( V_4 ) , V_66 ,
V_4 -> V_43 . V_67 - 1 , 0 ,
127 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
goto V_68;
}
}
V_34 = 0 ;
V_68:
return V_34 ;
}
static inline int F_39 ( struct V_3 * V_4 )
{
int V_34 ;
if ( V_4 -> V_57 . V_58 == V_59 ) {
int V_41 ;
struct V_69 * V_70 ;
F_35 ( V_60 , 2 , L_38 ) ;
V_4 -> V_43 . V_61 = F_26 ( sizeof( struct V_71 ) ,
V_46 ) ;
if ( ! V_4 -> V_43 . V_61 ) {
V_34 = - 1 ;
goto V_72;
}
F_40 ( V_60 , 2 , & V_4 -> V_43 . V_61 , sizeof( void * ) ) ;
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_4 -> V_43 . V_61 -> V_73 [ V_41 ] . V_74 =
& V_4 -> V_43 . V_61 -> V_62 [ V_41 ] ;
}
V_4 -> V_43 . V_67 = 2 ;
V_4 -> V_43 . V_75 =
F_26 ( V_4 -> V_43 . V_76 *
V_63 *
sizeof( struct V_69 ) , V_46 ) ;
V_70 = V_4 -> V_43 . V_75 ;
if ( V_70 == NULL ) {
V_34 = - 1 ;
goto V_77;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
V_4 -> V_43 . V_78 [ V_41 ] -> V_79 = V_70 ;
V_70 += V_63 ;
}
} else {
F_35 ( V_60 , 2 , L_39 ) ;
V_4 -> V_43 . V_61 = NULL ;
V_4 -> V_43 . V_67 = 1 ;
}
F_38 ( V_60 , 2 , L_40 , V_4 -> V_43 . V_67 ) ;
V_34 = 0 ;
V_68:
return V_34 ;
V_77:
F_31 ( V_4 -> V_43 . V_61 ) ;
V_4 -> V_43 . V_61 = NULL ;
V_72:
F_41 ( & V_4 -> V_7 -> V_6 , L_41 ) ;
goto V_68;
}
static inline void F_42 ( struct V_3 * V_4 )
{
if ( V_4 -> V_43 . V_61 ) {
-- V_4 -> V_43 . V_67 ;
F_31 ( V_4 -> V_43 . V_61 ) ;
V_4 -> V_43 . V_61 = NULL ;
}
F_31 ( V_4 -> V_43 . V_75 ) ;
V_4 -> V_43 . V_75 = NULL ;
}
static inline enum V_80 F_43 ( int V_81 ,
int V_82 ) {
enum V_80 V_83 ;
switch ( V_81 ) {
case 0 :
V_83 = V_82 ? V_84 : V_85 ;
break;
case 4 :
case 16 :
case 17 :
case 18 :
V_83 = V_82 ? V_86 :
V_87 ;
break;
default:
V_83 = V_82 ? V_88 :
V_89 ;
break;
}
return V_83 ;
}
static inline void F_44 ( struct V_90 * V_91 ,
int V_92 , int V_93 )
{
if ( V_91 -> V_4 -> V_57 . V_58 != V_59 )
return;
if ( V_91 -> V_73 [ V_92 ] -> V_94 != NULL ) {
struct V_95 * V_96 = V_91 -> V_73 [ V_92 ] ;
struct V_95 * V_97 = V_91 -> V_73 [ V_92 ] -> V_94 ;
while ( V_97 ) {
if ( V_93 ||
F_45 ( & V_97 -> V_52 ) ==
V_98 ) {
struct V_95 * V_99 = V_97 ;
F_3 ( V_99 -> V_91 -> V_4 , 5 , L_42 ) ;
F_46 ( V_99 -> V_91 -> V_4 , 5 , L_43 , ( long ) V_99 ) ;
F_47 ( V_97 ) ;
V_97 = V_99 -> V_94 ;
F_48 ( V_96 -> V_94 != V_99 ) ;
V_96 -> V_94 = V_97 ;
F_49 ( V_100 , V_99 ) ;
} else {
V_96 = V_97 ;
V_97 = V_97 -> V_94 ;
}
}
}
if ( V_93 && ( F_45 ( & ( V_91 -> V_73 [ V_92 ] -> V_52 ) ) ==
V_98 ) ) {
V_91 -> V_73 [ V_92 ] -> V_101 = V_91 -> V_79 [ V_92 ] . V_101 ;
F_50 ( V_91 , V_92 ) ;
F_3 ( V_91 -> V_4 , 2 , L_44 ) ;
}
}
static inline void F_51 ( struct V_3 * V_4 ,
unsigned long V_102 ) {
struct V_103 * V_101 ;
struct V_95 * V_74 ;
enum V_80 V_104 ;
V_101 = (struct V_103 * ) F_52 ( V_102 ) ;
F_3 ( V_4 , 5 , L_45 ) ;
F_46 ( V_4 , 5 , L_43 , V_102 ) ;
V_74 = (struct V_95 * ) V_101 -> V_105 ;
F_46 ( V_4 , 5 , L_43 , V_101 -> V_105 ) ;
if ( F_53 ( & V_74 -> V_52 , V_106 ,
V_107 ) == V_106 ) {
V_104 = V_85 ;
} else {
F_48 ( F_45 ( & V_74 -> V_52 ) !=
V_108 ) ;
F_54 ( & V_74 -> V_52 , V_107 ) ;
V_104 = V_84 ;
}
if ( V_101 -> V_109 != 0 ) {
F_46 ( V_4 , 2 , L_46 , V_101 -> V_109 ) ;
V_104 = F_43 ( V_101 -> V_109 , 1 ) ;
}
F_55 ( V_74 -> V_91 , V_74 , V_104 ) ;
V_74 -> V_101 = NULL ;
F_56 ( V_74 -> V_91 , V_74 ,
V_98 ) ;
F_57 ( V_101 ) ;
}
static inline int F_58 ( struct V_3 * V_4 , unsigned int V_110 )
{
return V_4 -> V_57 . V_58 == V_59 &&
V_4 -> V_43 . V_61 != NULL &&
V_110 != 0 &&
V_110 == V_4 -> V_43 . V_67 - 1 ;
}
static int F_59 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_3 ( V_4 , 5 , L_47 ) ;
if ( V_4 -> V_113 . V_52 != V_114 )
return - V_115 ;
V_112 = F_60 ( & V_4 -> V_113 ) ;
if ( ! V_112 ) {
F_61 ( & V_4 -> V_7 -> V_6 , L_48
L_49 ) ;
F_62 ( 2 , L_50
L_51 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
return - V_47 ;
}
F_64 ( & V_4 -> V_113 , V_112 -> V_116 , V_117 ) ;
F_3 ( V_4 , 6 , L_52 ) ;
V_34 = F_65 ( V_4 -> V_113 . V_118 , & V_4 -> V_113 . V_119 ,
( V_120 ) V_112 , 0 , 0 ) ;
if ( V_34 ) {
F_62 ( 2 , L_53
L_54 , F_63 ( & V_4 -> V_7 -> V_6 ) , V_34 ) ;
F_54 ( & V_4 -> V_113 . V_121 , 0 ) ;
V_4 -> V_122 = 1 ;
F_66 ( V_4 ) ;
F_18 ( & V_4 -> V_33 ) ;
}
return V_34 ;
}
static struct V_123 * F_67 ( struct V_3 * V_4 )
{
struct V_123 * V_124 ;
V_124 = F_26 ( sizeof( struct V_123 ) , V_125 ) ;
if ( V_124 ) {
F_54 ( & V_124 -> V_126 , 1 ) ;
F_54 ( & V_124 -> V_127 , 0 ) ;
V_124 -> V_4 = V_4 ;
}
return V_124 ;
}
static void F_68 ( struct V_123 * V_124 )
{
F_69 ( F_45 ( & V_124 -> V_126 ) <= 0 ) ;
F_70 ( & V_124 -> V_126 ) ;
}
static void F_71 ( struct V_123 * V_124 )
{
F_69 ( F_45 ( & V_124 -> V_126 ) <= 0 ) ;
if ( F_72 ( & V_124 -> V_126 ) )
F_31 ( V_124 ) ;
}
static void F_73 ( struct V_128 * V_129 , int V_34 ,
struct V_3 * V_4 )
{
char * V_130 ;
int V_131 = V_129 -> V_132 . V_133 ;
V_130 = F_74 ( V_131 ) ;
if ( V_34 )
F_62 ( 2 , L_55
L_56 ,
V_130 , V_131 , F_63 ( & V_4 -> V_7 -> V_6 ) ,
F_75 ( V_4 ) , V_34 ,
F_76 ( V_34 ) ) ;
else
F_62 ( 5 , L_57 ,
V_130 , V_131 , F_63 ( & V_4 -> V_7 -> V_6 ) ,
F_75 ( V_4 ) ) ;
}
static struct V_128 * F_77 ( struct V_3 * V_4 ,
struct V_111 * V_112 )
{
struct V_128 * V_129 = NULL ;
F_3 ( V_4 , 5 , L_58 ) ;
if ( F_78 ( V_112 -> V_116 ) ) {
V_129 = (struct V_128 * ) F_79 ( V_112 -> V_116 ) ;
if ( F_80 ( V_129 ) ) {
if ( V_129 -> V_132 . V_133 != V_134 &&
V_129 -> V_132 . V_133 != V_135 &&
V_129 -> V_132 . V_133 != V_136 &&
V_129 -> V_132 . V_133 != V_137 )
F_73 ( V_129 ,
V_129 -> V_132 . V_138 , V_4 ) ;
return V_129 ;
} else {
switch ( V_129 -> V_132 . V_133 ) {
case V_139 :
if ( V_129 -> V_132 . V_138 ==
V_140 ) {
F_41 ( & V_4 -> V_7 -> V_6 ,
L_59
L_60
L_61 ,
F_75 ( V_4 ) ) ;
F_8 ( V_4 ) ;
} else {
F_61 ( & V_4 -> V_7 -> V_6 ,
L_62
L_63 ,
F_75 ( V_4 ) ,
V_4 -> V_9 . V_141 ) ;
F_73 ( V_129 ,
V_129 -> V_132 . V_138 , V_4 ) ;
}
V_4 -> V_142 = 0 ;
if ( V_4 -> V_6 && F_81 ( V_4 -> V_6 ) )
F_82 ( V_4 -> V_6 ) ;
return NULL ;
case V_143 :
F_83 ( & V_4 -> V_7 -> V_6 ,
L_64
L_65 ,
F_75 ( V_4 ) ,
V_4 -> V_9 . V_141 ) ;
F_84 ( V_4 -> V_6 ) ;
V_4 -> V_142 = 1 ;
if ( V_4 -> V_9 . V_144 )
V_4 -> V_9 . V_144 = 2 ;
F_66 ( V_4 ) ;
return NULL ;
case V_145 :
case V_146 :
if ( V_4 -> V_147 -> V_148
( V_4 , V_129 ) )
return V_129 ;
else
return NULL ;
case V_136 :
return V_129 ;
case V_149 :
F_3 ( V_4 , 3 , L_66 ) ;
break;
case V_150 :
F_3 ( V_4 , 3 , L_67 ) ;
break;
default:
F_62 ( 2 , L_68
L_69 ) ;
break;
}
}
}
return V_129 ;
}
void F_85 ( struct V_3 * V_4 )
{
struct V_123 * V_124 , * V_151 ;
unsigned long V_29 ;
F_3 ( V_4 , 4 , L_70 ) ;
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_23 (reply, r, &card->cmd_waiter_list, list) {
F_68 ( V_124 ) ;
V_124 -> V_34 = - V_115 ;
F_70 ( & V_124 -> V_127 ) ;
F_86 ( & V_124 -> V_39 ) ;
F_18 ( & V_124 -> V_33 ) ;
F_71 ( V_124 ) ;
}
F_17 ( & V_4 -> V_152 , V_29 ) ;
F_54 ( & V_4 -> V_153 . V_121 , 0 ) ;
}
static int F_87 ( struct V_3 * V_4 ,
unsigned char * V_74 )
{
if ( ! V_74 )
return 0 ;
F_40 ( V_154 , 2 , V_74 , V_155 ) ;
if ( ( V_74 [ 2 ] & 0xc0 ) == 0xc0 ) {
F_62 ( 2 , L_71
L_72 ,
V_74 [ 4 ] ,
( ( V_74 [ 4 ] == 0x22 ) ?
L_73 : L_74 ) ) ;
F_3 ( V_4 , 2 , L_75 ) ;
F_3 ( V_4 , 2 , L_76 ) ;
F_46 ( V_4 , 2 , L_77 , - V_115 ) ;
if ( V_74 [ 4 ] == 0xf6 ) {
F_41 ( & V_4 -> V_7 -> V_6 ,
L_78
L_79 ) ;
return - V_55 ;
}
return - V_115 ;
}
return 0 ;
}
static void F_64 ( struct V_156 * V_157 , unsigned char * V_112 ,
T_1 V_158 )
{
struct V_3 * V_4 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_3 ( V_4 , 4 , L_80 ) ;
if ( V_157 == & V_4 -> V_113 )
memcpy ( & V_157 -> V_119 , V_159 , sizeof( struct V_160 ) ) ;
else
memcpy ( & V_157 -> V_119 , V_161 , sizeof( struct V_160 ) ) ;
V_157 -> V_119 . V_162 = V_158 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_112 ) ;
}
static struct V_111 * F_90 ( struct V_156 * V_157 )
{
T_2 V_164 ;
F_3 ( F_88 ( V_157 -> V_118 ) , 6 , L_81 ) ;
V_164 = V_157 -> V_165 ;
do {
if ( V_157 -> V_112 [ V_164 ] . V_52 == V_166 ) {
V_157 -> V_112 [ V_164 ] . V_52 = V_167 ;
V_157 -> V_165 = ( V_157 -> V_165 + 1 ) %
V_168 ;
memset ( V_157 -> V_112 [ V_164 ] . V_116 , 0 , V_117 ) ;
return V_157 -> V_112 + V_164 ;
}
V_164 = ( V_164 + 1 ) % V_168 ;
} while ( V_164 != V_157 -> V_165 );
return NULL ;
}
void F_91 ( struct V_156 * V_157 ,
struct V_111 * V_112 )
{
unsigned long V_29 ;
F_3 ( F_88 ( V_157 -> V_118 ) , 6 , L_82 ) ;
F_16 ( & V_157 -> V_169 , V_29 ) ;
memset ( V_112 -> V_116 , 0 , V_117 ) ;
V_112 -> V_52 = V_166 ;
V_112 -> V_170 = V_171 ;
V_112 -> V_34 = 0 ;
F_17 ( & V_157 -> V_169 , V_29 ) ;
F_18 ( & V_157 -> V_33 ) ;
}
static struct V_111 * F_60 ( struct V_156 * V_157 )
{
struct V_111 * V_74 = NULL ;
unsigned long V_29 ;
F_16 ( & V_157 -> V_169 , V_29 ) ;
V_74 = F_90 ( V_157 ) ;
F_17 ( & V_157 -> V_169 , V_29 ) ;
return V_74 ;
}
struct V_111 * F_92 ( struct V_156 * V_157 )
{
struct V_111 * V_74 ;
F_93 ( V_157 -> V_33 ,
( ( V_74 = F_60 ( V_157 ) ) != NULL ) ) ;
return V_74 ;
}
void F_94 ( struct V_156 * V_157 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_168 ; V_172 ++ )
F_91 ( V_157 , & V_157 -> V_112 [ V_172 ] ) ;
V_157 -> V_173 = 0 ;
V_157 -> V_165 = 0 ;
}
static void V_171 ( struct V_156 * V_157 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 ;
struct V_123 * V_124 , * V_151 ;
struct V_128 * V_129 ;
unsigned long V_29 ;
int V_174 ;
int V_34 = 0 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_3 ( V_4 , 4 , L_83 ) ;
V_34 = F_87 ( V_4 , V_112 -> V_116 ) ;
switch ( V_34 ) {
case 0 :
break;
case - V_115 :
F_85 ( V_4 ) ;
F_66 ( V_4 ) ;
default:
goto V_68;
}
V_129 = F_77 ( V_4 , V_112 ) ;
if ( ( V_129 == NULL ) && ( V_4 -> V_52 != V_53 ) )
goto V_68;
if ( V_4 -> V_9 . type == V_15 &&
V_129 &&
V_129 -> V_132 . V_133 != V_143 &&
V_4 -> V_175 . V_176 != NULL ) {
V_4 -> V_175 . V_176 ( V_4 -> V_6 , V_129 ) ;
goto V_68;
}
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_23 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_124 -> V_177 == V_178 ) ||
( ( V_129 ) && ( V_124 -> V_177 == V_129 -> V_132 . V_177 ) ) ) {
F_68 ( V_124 ) ;
F_86 ( & V_124 -> V_39 ) ;
F_17 ( & V_4 -> V_152 , V_29 ) ;
V_174 = 0 ;
if ( V_124 -> V_170 != NULL ) {
if ( V_129 ) {
V_124 -> V_179 = ( V_180 ) ( ( char * ) V_129 -
( char * ) V_112 -> V_116 ) ;
V_174 = V_124 -> V_170 ( V_4 ,
V_124 ,
( unsigned long ) V_129 ) ;
} else
V_174 = V_124 -> V_170 ( V_4 ,
V_124 ,
( unsigned long ) V_112 ) ;
}
if ( V_129 )
V_124 -> V_34 = ( V_181 ) V_129 -> V_132 . V_138 ;
else if ( V_112 -> V_34 )
V_124 -> V_34 = V_112 -> V_34 ;
if ( V_174 ) {
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_95 ( & V_124 -> V_39 ,
& V_4 -> V_182 ) ;
F_17 ( & V_4 -> V_152 , V_29 ) ;
} else {
F_70 ( & V_124 -> V_127 ) ;
F_18 ( & V_124 -> V_33 ) ;
}
F_71 ( V_124 ) ;
goto V_68;
}
}
F_17 ( & V_4 -> V_152 , V_29 ) ;
V_68:
memcpy ( & V_4 -> V_177 . V_183 ,
F_96 ( V_112 -> V_116 ) ,
V_184 ) ;
F_91 ( V_157 , V_112 ) ;
}
static int F_97 ( struct V_156 * V_157 )
{
int V_172 ;
F_35 ( V_60 , 2 , L_84 ) ;
for ( V_172 = 0 ; V_172 < V_168 ; V_172 ++ ) {
V_157 -> V_112 [ V_172 ] . V_116 =
F_26 ( V_117 , V_185 | V_46 ) ;
if ( V_157 -> V_112 [ V_172 ] . V_116 == NULL )
break;
V_157 -> V_112 [ V_172 ] . V_52 = V_166 ;
V_157 -> V_112 [ V_172 ] . V_157 = V_157 ;
V_157 -> V_112 [ V_172 ] . V_170 = V_171 ;
V_157 -> V_112 [ V_172 ] . V_34 = 0 ;
}
if ( V_172 < V_168 ) {
while ( V_172 -- > 0 )
F_31 ( V_157 -> V_112 [ V_172 ] . V_116 ) ;
return - V_47 ;
}
V_157 -> V_173 = 0 ;
V_157 -> V_165 = 0 ;
F_54 ( & V_157 -> V_121 , 0 ) ;
F_98 ( & V_157 -> V_169 ) ;
F_99 ( & V_157 -> V_33 ) ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 ,
unsigned long V_186 )
{
unsigned long V_29 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
if ( ! ( V_4 -> V_31 & V_186 ) ||
( V_4 -> V_32 & V_186 ) ) {
F_17 ( & V_4 -> V_30 , V_29 ) ;
return - V_55 ;
}
V_4 -> V_32 |= V_186 ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
return 0 ;
}
void F_101 ( struct V_3 * V_4 , unsigned long V_186 )
{
unsigned long V_29 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
V_4 -> V_32 &= ~ V_186 ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
F_18 ( & V_4 -> V_33 ) ;
}
void F_102 ( struct V_3 * V_4 , unsigned long V_186 )
{
unsigned long V_29 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
V_4 -> V_35 &= ~ V_186 ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
F_18 ( & V_4 -> V_33 ) ;
}
static int F_103 ( struct V_3 * V_4 , unsigned long V_186 )
{
unsigned long V_29 ;
int V_34 = 0 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
if ( V_4 -> V_32 & V_186 ) {
if ( ( V_4 -> V_31 & V_186 ) &&
! ( V_4 -> V_35 & V_186 ) ) {
V_34 = 1 ;
V_4 -> V_32 &= ~ V_186 ;
V_4 -> V_35 |= V_186 ;
} else
V_34 = - V_55 ;
}
F_17 ( & V_4 -> V_30 , V_29 ) ;
return V_34 ;
}
int F_104 ( struct V_3 * V_4 , unsigned long V_186 )
{
int V_34 = 0 ;
F_93 ( V_4 -> V_33 ,
( V_34 = F_103 ( V_4 , V_186 ) ) >= 0 ) ;
return V_34 ;
}
void F_66 ( struct V_3 * V_4 )
{
F_3 ( V_4 , 2 , L_85 ) ;
if ( F_100 ( V_4 , V_187 ) == 0 )
F_105 ( & V_4 -> V_188 ) ;
}
static int F_106 ( struct V_189 * V_190 , struct V_191 * V_191 )
{
int V_192 , V_193 ;
char * V_194 ;
struct V_3 * V_4 ;
V_194 = ( char * ) V_191 -> V_195 ;
V_193 = V_191 -> V_196 . V_129 . V_193 ;
V_192 = V_191 -> V_196 . V_129 . V_192 ;
V_4 = F_88 ( V_190 ) ;
if ( V_193 & ( V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ) ) {
F_3 ( V_4 , 2 , L_86 ) ;
F_61 ( & V_190 -> V_6 , L_48
L_49 ) ;
F_62 ( 2 , L_87 ,
F_63 ( & V_190 -> V_6 ) , V_192 , V_193 ) ;
F_107 ( V_203 , L_88 , V_204 ,
16 , 1 , V_191 , 64 , 1 ) ;
return 1 ;
}
if ( V_192 & V_205 ) {
if ( V_194 [ V_206 ] &
V_207 ) {
F_3 ( V_4 , 2 , L_89 ) ;
return 1 ;
}
if ( V_194 [ V_208 ] &
V_209 ) {
F_3 ( V_4 , 2 , L_90 ) ;
return 1 ;
}
if ( ( V_194 [ 2 ] == 0xaf ) && ( V_194 [ 3 ] == 0xfe ) ) {
F_3 ( V_4 , 2 , L_91 ) ;
return 1 ;
}
if ( ( ! V_194 [ 0 ] ) && ( ! V_194 [ 1 ] ) && ( ! V_194 [ 2 ] ) && ( ! V_194 [ 3 ] ) ) {
F_3 ( V_4 , 2 , L_92 ) ;
return 0 ;
}
F_3 ( V_4 , 2 , L_93 ) ;
return 1 ;
}
return 0 ;
}
static long F_108 ( struct V_189 * V_190 ,
unsigned long V_210 , struct V_191 * V_191 )
{
struct V_3 * V_4 ;
V_4 = F_88 ( V_190 ) ;
if ( ! F_109 ( V_191 ) )
return 0 ;
switch ( F_110 ( V_191 ) ) {
case - V_115 :
F_62 ( 2 , L_94 ,
F_63 ( & V_190 -> V_6 ) ) ;
F_3 ( V_4 , 2 , L_95 ) ;
F_46 ( V_4 , 2 , L_77 , - V_115 ) ;
break;
case - V_211 :
F_61 ( & V_190 -> V_6 , L_96
L_97 ) ;
F_3 ( V_4 , 2 , L_95 ) ;
F_46 ( V_4 , 2 , L_77 , - V_211 ) ;
if ( V_210 == V_212 ) {
if ( V_4 && ( V_4 -> V_116 . V_118 == V_190 ) ) {
V_4 -> V_116 . V_52 = V_213 ;
F_18 ( & V_4 -> V_33 ) ;
}
}
break;
default:
F_62 ( 2 , L_98 ,
F_63 ( & V_190 -> V_6 ) , F_110 ( V_191 ) ) ;
F_3 ( V_4 , 2 , L_95 ) ;
F_3 ( V_4 , 2 , L_99 ) ;
}
return F_110 ( V_191 ) ;
}
static void F_111 ( struct V_189 * V_190 , unsigned long V_210 ,
struct V_191 * V_191 )
{
int V_34 ;
int V_193 , V_192 ;
struct V_111 * V_74 ;
struct V_156 * V_157 ;
struct V_3 * V_4 ;
struct V_111 * V_112 ;
T_2 V_164 ;
if ( F_108 ( V_190 , V_210 , V_191 ) )
return;
V_193 = V_191 -> V_196 . V_129 . V_193 ;
V_192 = V_191 -> V_196 . V_129 . V_192 ;
V_4 = F_88 ( V_190 ) ;
if ( ! V_4 )
return;
F_3 ( V_4 , 5 , L_100 ) ;
if ( V_4 -> V_113 . V_118 == V_190 ) {
V_157 = & V_4 -> V_113 ;
F_3 ( V_4 , 5 , L_101 ) ;
} else if ( V_4 -> V_153 . V_118 == V_190 ) {
V_157 = & V_4 -> V_153 ;
F_3 ( V_4 , 5 , L_102 ) ;
} else {
V_157 = & V_4 -> V_116 ;
F_3 ( V_4 , 5 , L_103 ) ;
}
F_54 ( & V_157 -> V_121 , 0 ) ;
if ( V_191 -> V_196 . V_129 . V_214 & ( V_215 ) )
V_157 -> V_52 = V_216 ;
if ( V_191 -> V_196 . V_129 . V_214 & ( V_217 ) )
V_157 -> V_52 = V_218 ;
if ( ( V_157 == & V_4 -> V_116 ) && ( V_210 != 0 ) &&
( V_210 != V_212 ) )
goto V_68;
if ( V_210 == V_219 ) {
F_3 ( V_4 , 6 , L_104 ) ;
V_210 = 0 ;
}
if ( V_210 == V_220 ) {
F_3 ( V_4 , 6 , L_105 ) ;
V_210 = 0 ;
}
if ( ( V_192 & V_221 ) ||
( V_192 & V_205 ) ||
( V_193 ) ) {
if ( V_191 -> V_222 . V_223 . V_224 . V_225 ) {
F_61 ( & V_157 -> V_118 -> V_6 ,
L_106
L_107 ) ;
F_62 ( 2 , L_108
L_109 ,
F_63 ( & V_157 -> V_118 -> V_6 ) , V_193 , V_192 ) ;
F_107 ( V_203 , L_88 ,
V_204 , 16 , 1 , V_191 , 32 , 1 ) ;
F_107 ( V_203 , L_110 ,
V_204 , 16 , 1 , V_191 -> V_195 , 32 , 1 ) ;
}
if ( V_210 == V_212 ) {
V_157 -> V_52 = V_213 ;
goto V_68;
}
V_34 = F_106 ( V_190 , V_191 ) ;
if ( V_34 ) {
F_85 ( V_4 ) ;
F_66 ( V_4 ) ;
goto V_68;
}
}
if ( V_210 == V_212 ) {
V_157 -> V_52 = V_226 ;
goto V_68;
}
if ( V_210 ) {
V_74 = (struct V_111 * ) F_112 ( ( V_120 ) V_210 ) ;
V_74 -> V_52 = V_227 ;
}
if ( V_157 == & V_4 -> V_116 )
return;
if ( V_157 == & V_4 -> V_113 &&
V_157 -> V_52 == V_114 )
F_59 ( V_4 ) ;
V_112 = V_157 -> V_112 ;
V_164 = V_157 -> V_173 ;
while ( V_112 [ V_164 ] . V_52 == V_227 ) {
if ( V_112 [ V_164 ] . V_170 != NULL )
V_112 [ V_164 ] . V_170 ( V_157 , V_112 + V_164 ) ;
V_164 = ( V_164 + 1 ) % V_168 ;
}
V_157 -> V_173 = V_164 ;
V_68:
F_18 ( & V_4 -> V_33 ) ;
return;
}
static void F_55 ( struct V_90 * V_91 ,
struct V_95 * V_228 ,
enum V_80 V_104 )
{
struct V_229 * V_230 ;
if ( F_113 ( & V_228 -> V_231 ) )
goto V_68;
V_230 = F_114 ( & V_228 -> V_231 ) ;
while ( V_230 ) {
F_46 ( V_91 -> V_4 , 5 , L_111 , V_104 ) ;
F_46 ( V_91 -> V_4 , 5 , L_43 , ( long ) V_230 ) ;
if ( V_230 -> V_232 == V_233 ) {
if ( V_230 -> V_234 ) {
struct V_235 * V_236 = F_115 ( V_230 -> V_234 ) ;
V_236 -> V_237 ( V_230 , V_104 ) ;
}
}
if ( F_116 ( & V_228 -> V_231 , V_230 ) )
V_230 = NULL ;
else
V_230 = F_117 ( & V_228 -> V_231 , V_230 ) ;
}
V_68:
return;
}
static void F_47 ( struct V_95 * V_228 )
{
struct V_229 * V_230 ;
struct V_235 * V_236 ;
int V_238 = 0 ;
if ( F_45 ( & V_228 -> V_52 ) == V_108 )
V_238 = 1 ;
F_48 ( F_45 ( & V_228 -> V_52 ) == V_107 ) ;
V_230 = F_118 ( & V_228 -> V_231 ) ;
while ( V_230 ) {
F_3 ( V_228 -> V_91 -> V_4 , 5 , L_112 ) ;
F_46 ( V_228 -> V_91 -> V_4 , 5 , L_43 , ( long ) V_230 ) ;
if ( V_238 && V_230 -> V_232 == V_233 ) {
if ( V_230 -> V_234 ) {
V_236 = F_115 ( V_230 -> V_234 ) ;
V_236 -> V_237 ( V_230 , V_89 ) ;
}
}
F_119 ( & V_230 -> V_239 ) ;
F_120 ( V_230 ) ;
V_230 = F_118 ( & V_228 -> V_231 ) ;
}
}
static void F_56 ( struct V_90 * V_110 ,
struct V_95 * V_228 ,
enum V_240 V_241 )
{
int V_41 ;
if ( V_228 -> V_74 -> V_242 [ 0 ] . V_243 & V_244 )
F_119 ( & V_110 -> V_245 ) ;
if ( V_241 == V_246 ) {
F_47 ( V_228 ) ;
}
for ( V_41 = 0 ; V_41 < F_28 ( V_110 -> V_4 ) ; ++ V_41 ) {
if ( V_228 -> V_74 -> V_242 [ V_41 ] . V_247 && V_228 -> V_248 [ V_41 ] )
F_49 ( V_249 ,
V_228 -> V_74 -> V_242 [ V_41 ] . V_247 ) ;
V_228 -> V_248 [ V_41 ] = 0 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_250 = 0 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_247 = NULL ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_251 = 0 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_243 = 0 ;
}
V_228 -> V_74 -> V_242 [ 15 ] . V_251 = 0 ;
V_228 -> V_74 -> V_242 [ 15 ] . V_243 = 0 ;
V_228 -> V_252 = 0 ;
F_54 ( & V_228 -> V_52 , V_241 ) ;
}
static void F_121 ( struct V_90 * V_91 , int free )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 ) {
if ( ! V_91 -> V_73 [ V_42 ] )
continue;
F_44 ( V_91 , V_42 , 1 ) ;
F_56 ( V_91 , V_91 -> V_73 [ V_42 ] , V_246 ) ;
if ( free ) {
F_49 ( V_100 , V_91 -> V_73 [ V_42 ] ) ;
V_91 -> V_73 [ V_42 ] = NULL ;
}
}
}
void F_122 ( struct V_3 * V_4 )
{
int V_41 ;
F_3 ( V_4 , 2 , L_113 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
if ( V_4 -> V_43 . V_78 [ V_41 ] ) {
F_121 ( V_4 -> V_43 . V_78 [ V_41 ] , 0 ) ;
}
}
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_36 * V_37 , * V_38 ;
int V_41 = 0 ;
F_23 (pool_entry, tmp,
&card->qdio.init_pool.entry_list, init_list) {
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 )
F_30 ( ( unsigned long ) V_37 -> V_48 [ V_41 ] ) ;
F_24 ( & V_37 -> V_49 ) ;
F_31 ( V_37 ) ;
}
}
static void F_123 ( struct V_3 * V_4 )
{
int V_41 , V_42 ;
if ( F_124 ( & V_4 -> V_43 . V_52 , V_253 ) ==
V_253 )
return;
F_42 ( V_4 ) ;
F_125 ( & V_4 -> V_254 ) ;
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 ) {
if ( V_4 -> V_43 . V_255 -> V_73 [ V_42 ] . V_256 )
F_120 ( V_4 -> V_43 . V_255 -> V_73 [ V_42 ] . V_256 ) ;
}
F_31 ( V_4 -> V_43 . V_255 ) ;
V_4 -> V_43 . V_255 = NULL ;
F_27 ( V_4 ) ;
if ( V_4 -> V_43 . V_78 ) {
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
F_121 ( V_4 -> V_43 . V_78 [ V_41 ] , 1 ) ;
F_31 ( V_4 -> V_43 . V_78 [ V_41 ] ) ;
}
F_31 ( V_4 -> V_43 . V_78 ) ;
V_4 -> V_43 . V_78 = NULL ;
}
}
static void F_126 ( struct V_156 * V_157 )
{
int V_172 ;
F_35 ( V_60 , 2 , L_114 ) ;
for ( V_172 = 0 ; V_172 < V_168 ; V_172 ++ )
F_31 ( V_157 -> V_112 [ V_172 ] . V_116 ) ;
}
static void F_127 ( struct V_3 * V_4 )
{
if ( ( F_45 ( & V_4 -> V_43 . V_52 ) != V_253 ) &&
( V_4 -> V_43 . V_76 == 4 ) )
F_123 ( V_4 ) ;
V_4 -> V_43 . V_76 = 1 ;
if ( V_4 -> V_43 . V_257 != 0 )
F_83 ( & V_4 -> V_7 -> V_6 , L_115 ) ;
V_4 -> V_43 . V_257 = 0 ;
}
static void F_128 ( struct V_3 * V_4 )
{
if ( ( F_45 ( & V_4 -> V_43 . V_52 ) != V_253 ) &&
( V_4 -> V_43 . V_76 == 1 ) ) {
F_123 ( V_4 ) ;
V_4 -> V_43 . V_257 = 2 ;
}
V_4 -> V_43 . V_76 = 4 ;
}
static void F_129 ( struct V_3 * V_4 )
{
struct V_189 * V_118 ;
struct V_258 {
T_3 V_29 ;
T_3 V_259 ;
T_3 V_260 ;
T_3 V_141 ;
T_3 V_261 ;
T_3 V_262 ;
T_3 V_263 ;
T_3 V_264 ;
} * V_265 ;
F_35 ( V_60 , 2 , L_116 ) ;
V_118 = V_4 -> V_116 . V_118 ;
V_265 = F_130 ( V_118 , 0 ) ;
if ( ! V_265 )
goto V_68;
V_4 -> V_9 . V_266 = 0x4100 + V_265 -> V_260 ;
if ( V_4 -> V_9 . type == V_12 )
goto V_68;
if ( ( V_265 -> V_264 & 0x02 ) == 0x02 )
F_127 ( V_4 ) ;
else
F_128 ( V_4 ) ;
V_68:
F_31 ( V_265 ) ;
F_38 ( V_60 , 2 , L_117 , V_4 -> V_43 . V_76 ) ;
F_38 ( V_60 , 2 , L_118 , V_4 -> V_9 . V_266 ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 4 , L_119 ) ;
F_54 ( & V_4 -> V_43 . V_52 , V_253 ) ;
V_4 -> V_43 . V_267 = V_268 ;
if ( V_4 -> V_9 . type == V_12 )
V_4 -> V_43 . V_44 . V_45 = V_269 ;
else
V_4 -> V_43 . V_44 . V_45 = V_270 ;
V_4 -> V_43 . V_56 . V_45 = V_4 -> V_43 . V_44 . V_45 ;
F_132 ( & V_4 -> V_43 . V_56 . V_50 ) ;
F_132 ( & V_4 -> V_43 . V_44 . V_50 ) ;
}
static void F_133 ( struct V_3 * V_4 )
{
V_4 -> V_57 . V_271 . type = V_272 ;
V_4 -> V_57 . V_273 . type = V_272 ;
V_4 -> V_57 . V_274 = 0 ;
V_4 -> V_57 . V_275 = V_276 ;
V_4 -> V_57 . V_277 = 0 ;
V_4 -> V_57 . V_278 = V_279 ;
V_4 -> V_57 . V_280 = V_281 ;
V_4 -> V_57 . V_58 = V_282 ;
}
static int F_134 ( struct V_3 * V_4 , unsigned long V_186 )
{
unsigned long V_29 ;
int V_34 = 0 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
F_46 ( V_4 , 4 , L_120 ,
( T_3 ) V_4 -> V_32 ,
( T_3 ) V_4 -> V_31 ,
( T_3 ) V_4 -> V_35 ) ;
V_34 = ( V_4 -> V_32 & V_186 ) ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
return V_34 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_283 * V_284 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_188 ) ;
F_3 ( V_4 , 2 , L_121 ) ;
if ( V_4 -> V_113 . V_52 != V_114 &&
V_4 -> V_153 . V_52 != V_114 )
return;
if ( F_134 ( V_4 , V_187 ) ) {
V_284 = F_136 ( V_4 -> V_147 -> V_285 , ( void * ) V_4 ,
L_122 ) ;
if ( F_109 ( V_284 ) ) {
F_101 ( V_4 , V_187 ) ;
F_102 ( V_4 ,
V_187 ) ;
}
}
}
static int F_137 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 2 , L_123 ) ;
F_40 ( V_60 , 2 , & V_4 , sizeof( void * ) ) ;
V_4 -> V_113 . V_52 = V_213 ;
V_4 -> V_153 . V_52 = V_213 ;
V_4 -> V_116 . V_52 = V_213 ;
V_4 -> V_52 = V_53 ;
V_4 -> V_142 = 0 ;
V_4 -> V_122 = 0 ;
V_4 -> V_6 = NULL ;
F_98 ( & V_4 -> V_286 ) ;
F_98 ( & V_4 -> V_287 ) ;
F_98 ( & V_4 -> V_152 ) ;
F_98 ( & V_4 -> V_288 ) ;
F_98 ( & V_4 -> V_30 ) ;
F_138 ( & V_4 -> V_289 ) ;
F_138 ( & V_4 -> V_290 ) ;
V_4 -> V_32 = 0 ;
V_4 -> V_31 = 0 ;
V_4 -> V_35 = 0 ;
F_139 ( & V_4 -> V_188 , F_135 ) ;
F_132 ( & V_4 -> V_291 ) ;
F_132 ( V_4 -> V_292 ) ;
F_132 ( & V_4 -> V_182 ) ;
F_99 ( & V_4 -> V_33 ) ;
F_133 ( V_4 ) ;
F_132 ( & V_4 -> V_293 . V_294 ) ;
V_4 -> V_293 . V_295 = 0 ;
V_4 -> V_293 . V_296 = 0 ;
V_4 -> V_293 . V_297 = 0 ;
F_131 ( V_4 ) ;
F_140 ( & V_4 -> V_254 , V_298 ) ;
F_139 ( & V_4 -> V_5 , F_1 ) ;
return 0 ;
}
static void F_141 ( struct V_299 * V_300 , struct V_301 * V_302 )
{
struct V_3 * V_4 = F_2 ( V_302 , struct V_3 ,
V_303 ) ;
if ( V_4 -> V_9 . V_304 [ 0 ] )
F_142 ( V_300 , L_124 ,
F_143 ( V_4 ) , V_4 -> V_9 . V_304 ) ;
}
static struct V_3 * F_144 ( void )
{
struct V_3 * V_4 ;
F_35 ( V_60 , 2 , L_125 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_185 | V_46 ) ;
if ( ! V_4 )
goto V_68;
F_40 ( V_60 , 2 , & V_4 , sizeof( void * ) ) ;
V_4 -> V_292 = F_26 ( sizeof( struct V_305 ) , V_46 ) ;
if ( ! V_4 -> V_292 ) {
F_35 ( V_60 , 0 , L_126 ) ;
goto V_306;
}
if ( F_97 ( & V_4 -> V_113 ) )
goto V_307;
if ( F_97 ( & V_4 -> V_153 ) )
goto V_308;
V_4 -> V_57 . V_309 = - 1 ;
V_4 -> V_303 . V_310 = F_141 ;
F_145 ( & V_4 -> V_303 ) ;
return V_4 ;
V_308:
F_126 ( & V_4 -> V_113 ) ;
V_307:
F_31 ( V_4 -> V_292 ) ;
V_306:
F_31 ( V_4 ) ;
V_68:
return NULL ;
}
static int F_146 ( struct V_3 * V_4 )
{
int V_41 = 0 ;
F_35 ( V_60 , 2 , L_127 ) ;
V_4 -> V_43 . V_311 = V_312 ;
V_4 -> V_43 . V_257 = V_313 ;
while ( V_314 [ V_41 ] [ V_315 ] ) {
if ( ( F_147 ( V_4 ) -> V_316 . V_317 ==
V_314 [ V_41 ] [ V_318 ] ) &&
( F_147 ( V_4 ) -> V_316 . V_319 ==
V_314 [ V_41 ] [ V_315 ] ) ) {
V_4 -> V_9 . type = V_314 [ V_41 ] [ V_315 ] ;
V_4 -> V_43 . V_76 =
V_314 [ V_41 ] [ V_320 ] ;
V_4 -> V_43 . V_67 = 1 ;
V_4 -> V_9 . V_321 =
V_314 [ V_41 ] [ V_322 ] ;
F_129 ( V_4 ) ;
return 0 ;
}
V_41 ++ ;
}
V_4 -> V_9 . type = V_323 ;
F_41 ( & V_4 -> V_7 -> V_6 , L_128
L_129 ) ;
return - V_324 ;
}
static int F_148 ( struct V_156 * V_157 )
{
unsigned long V_29 ;
struct V_3 * V_4 ;
int V_34 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_3 ( V_4 , 3 , L_130 ) ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_34 = F_150 ( V_157 -> V_118 , V_219 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_151 ( V_4 -> V_33 ,
V_157 -> V_52 == V_216 , V_325 ) ;
if ( V_34 == - V_326 )
return V_34 ;
if ( V_157 -> V_52 != V_216 )
return - V_327 ;
V_157 -> V_52 = V_213 ;
return 0 ;
}
static int F_152 ( struct V_156 * V_157 )
{
unsigned long V_29 ;
struct V_3 * V_4 ;
int V_34 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_3 ( V_4 , 3 , L_131 ) ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_34 = F_153 ( V_157 -> V_118 , V_220 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_151 ( V_4 -> V_33 ,
V_157 -> V_52 == V_218 , V_325 ) ;
if ( V_34 == - V_326 )
return V_34 ;
if ( V_157 -> V_52 != V_218 )
return - V_327 ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 )
{
int V_328 = 0 , V_329 = 0 , V_330 = 0 ;
F_3 ( V_4 , 3 , L_132 ) ;
V_328 = F_152 ( & V_4 -> V_113 ) ;
V_329 = F_152 ( & V_4 -> V_153 ) ;
V_330 = F_152 ( & V_4 -> V_116 ) ;
if ( V_328 )
return V_328 ;
if ( V_329 )
return V_329 ;
return V_330 ;
}
static int F_155 ( struct V_3 * V_4 )
{
int V_328 = 0 , V_329 = 0 , V_330 = 0 ;
F_3 ( V_4 , 3 , L_133 ) ;
V_328 = F_148 ( & V_4 -> V_113 ) ;
V_329 = F_148 ( & V_4 -> V_153 ) ;
V_330 = F_148 ( & V_4 -> V_116 ) ;
if ( V_328 )
return V_328 ;
if ( V_329 )
return V_329 ;
return V_330 ;
}
static int F_156 ( struct V_3 * V_4 , int V_331 )
{
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_134 ) ;
if ( V_331 )
V_34 = F_154 ( V_4 ) ;
if ( V_34 )
return V_34 ;
return F_155 ( V_4 ) ;
}
int F_157 ( struct V_3 * V_4 , int V_332 )
{
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_135 ) ;
switch ( F_53 ( & V_4 -> V_43 . V_52 , V_333 ,
V_334 ) ) {
case V_333 :
if ( V_4 -> V_9 . type == V_12 )
V_34 = F_158 ( F_37 ( V_4 ) ,
V_335 ) ;
else
V_34 = F_158 ( F_37 ( V_4 ) ,
V_336 ) ;
if ( V_34 )
F_46 ( V_4 , 3 , L_37 , V_34 ) ;
F_54 ( & V_4 -> V_43 . V_52 , V_337 ) ;
break;
case V_334 :
return V_34 ;
default:
break;
}
V_34 = F_156 ( V_4 , V_332 ) ;
if ( V_34 )
F_46 ( V_4 , 3 , L_136 , V_34 ) ;
V_4 -> V_52 = V_53 ;
return V_34 ;
}
static int F_159 ( struct V_3 * V_4 , void * * V_74 ,
int * V_250 )
{
struct V_338 * V_338 ;
char * V_339 ;
int V_340 ;
struct V_156 * V_157 = & V_4 -> V_116 ;
unsigned long V_29 ;
V_338 = F_160 ( V_157 -> V_118 , V_341 ) ;
if ( ! V_338 || V_338 -> V_129 == 0 )
return - V_342 ;
V_339 = F_26 ( V_338 -> V_162 , V_46 | V_185 ) ;
if ( ! V_339 )
return - V_47 ;
V_157 -> V_119 . V_343 = V_338 -> V_129 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_339 ) ;
V_157 -> V_119 . V_162 = V_338 -> V_162 ;
V_157 -> V_119 . V_29 = V_344 ;
V_157 -> V_52 = V_345 ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_340 = F_161 ( V_157 -> V_118 , & V_157 -> V_119 ,
V_212 , V_346 , 0 ,
V_347 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( ! V_340 )
F_93 ( V_4 -> V_33 ,
( V_157 -> V_52 == V_226 ||
V_157 -> V_52 == V_213 ) ) ;
if ( V_157 -> V_52 == V_213 )
V_340 = - V_115 ;
else
V_157 -> V_52 = V_213 ;
if ( V_340 ) {
F_31 ( V_339 ) ;
* V_74 = NULL ;
* V_250 = 0 ;
} else {
* V_250 = V_338 -> V_162 ;
* V_74 = V_339 ;
}
return V_340 ;
}
static void F_162 ( struct V_3 * V_4 , char * V_348 )
{
F_35 ( V_60 , 2 , L_137 ) ;
V_4 -> V_9 . V_141 = V_348 [ 30 ] ;
V_4 -> V_9 . V_349 = V_348 [ 31 ] ;
V_4 -> V_9 . V_350 = V_348 [ 63 ] ;
V_4 -> V_9 . V_10 = ( ( V_348 [ 0x10 ] == V_351 [ 'V' ] ) &&
( V_348 [ 0x11 ] == V_351 [ 'M' ] ) ) ;
}
static void F_163 ( struct V_3 * V_4 , char * V_348 )
{
F_35 ( V_60 , 2 , L_138 ) ;
if ( V_348 [ 74 ] == 0xF0 && V_348 [ 75 ] == 0xF0 &&
V_348 [ 76 ] >= 0xF1 && V_348 [ 76 ] <= 0xF4 ) {
V_4 -> V_9 . V_352 . V_353 = 0 ;
V_4 -> V_9 . V_352 . V_354 = 0 ;
V_4 -> V_9 . V_352 . V_355 = 0 ;
} else {
V_4 -> V_9 . V_352 . V_353 = 250 ;
V_4 -> V_9 . V_352 . V_354 = 5 ;
V_4 -> V_9 . V_352 . V_355 = 15 ;
}
}
static void F_164 ( struct V_3 * V_4 )
{
V_4 -> V_356 . V_357 = 0x00010103UL ;
V_4 -> V_356 . V_358 = 0x00010108UL ;
V_4 -> V_356 . V_359 = 0x0001010aUL ;
V_4 -> V_356 . V_360 = 0x0001010bUL ;
V_4 -> V_356 . V_361 = 0x0001010dUL ;
}
static void F_165 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_12 :
V_4 -> V_9 . V_266 = V_362 ;
break;
case V_11 :
case V_15 :
V_4 -> V_9 . V_266 = V_363 ;
break;
default:
break;
}
}
static int F_166 ( struct V_156 * V_157 ,
void (* F_167)( struct V_156 * ,
struct V_111 * ) )
{
struct V_111 * V_112 ;
unsigned long V_29 ;
int V_34 ;
struct V_3 * V_4 ;
F_35 ( V_60 , 2 , L_139 ) ;
V_4 = F_88 ( V_157 -> V_118 ) ;
V_112 = F_60 ( V_157 ) ;
V_112 -> V_170 = F_167 ;
memcpy ( & V_157 -> V_119 , V_159 , sizeof( struct V_160 ) ) ;
V_157 -> V_119 . V_162 = V_117 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_112 -> V_116 ) ;
F_93 ( V_4 -> V_33 ,
F_53 ( & V_157 -> V_121 , 0 , 1 ) == 0 ) ;
F_35 ( V_60 , 6 , L_52 ) ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_34 = F_65 ( V_157 -> V_118 ,
& V_157 -> V_119 , ( V_120 ) V_112 , 0 , 0 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( V_34 ) {
F_62 ( 2 , L_140 , V_34 ) ;
F_38 ( V_60 , 2 , L_136 , V_34 ) ;
F_54 ( & V_157 -> V_121 , 0 ) ;
F_18 ( & V_4 -> V_33 ) ;
return V_34 ;
}
V_34 = F_151 ( V_4 -> V_33 ,
V_157 -> V_52 == V_114 , V_325 ) ;
if ( V_34 == - V_326 )
return V_34 ;
if ( V_157 -> V_52 != V_114 ) {
V_34 = - V_327 ;
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
F_94 ( V_157 ) ;
} else
V_34 = 0 ;
return V_34 ;
}
static int F_168 ( struct V_156 * V_157 ,
void (* F_167)( struct V_156 * ,
struct V_111 * ) )
{
struct V_3 * V_4 ;
struct V_111 * V_112 ;
unsigned long V_29 ;
V_180 V_364 ;
T_2 V_38 ;
int V_34 ;
struct V_365 V_366 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_35 ( V_60 , 2 , L_142 ) ;
V_112 = F_60 ( V_157 ) ;
V_112 -> V_170 = F_167 ;
memcpy ( & V_157 -> V_119 , V_161 , sizeof( struct V_160 ) ) ;
V_157 -> V_119 . V_162 = V_367 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_112 -> V_116 ) ;
if ( V_157 == & V_4 -> V_153 ) {
memcpy ( V_112 -> V_116 , V_368 , V_367 ) ;
memcpy ( F_169 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_369 , V_184 ) ;
V_4 -> V_177 . V_369 ++ ;
} else {
memcpy ( V_112 -> V_116 , V_370 , V_367 ) ;
memcpy ( F_169 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_369 , V_184 ) ;
}
V_38 = ( ( T_2 ) V_4 -> V_9 . V_371 ) | 0x80 ;
memcpy ( F_170 ( V_112 -> V_116 ) , & V_38 , 1 ) ;
memcpy ( F_171 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_357 , V_372 ) ;
memcpy ( F_172 ( V_112 -> V_116 ) ,
& V_4 -> V_9 . V_266 , sizeof( V_180 ) ) ;
F_173 ( F_37 ( V_4 ) , & V_366 ) ;
memcpy ( F_174 ( V_112 -> V_116 ) , & V_366 . V_373 , 2 ) ;
V_364 = ( V_4 -> V_9 . V_350 << 8 ) + V_4 -> V_9 . V_349 ;
memcpy ( F_175 ( V_112 -> V_116 ) , & V_364 , 2 ) ;
F_93 ( V_4 -> V_33 ,
F_53 ( & V_157 -> V_121 , 0 , 1 ) == 0 ) ;
F_35 ( V_60 , 6 , L_52 ) ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_34 = F_65 ( V_157 -> V_118 ,
& V_157 -> V_119 , ( V_120 ) V_112 , 0 , 0 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( V_34 ) {
F_62 ( 2 , L_143 ,
V_34 ) ;
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
F_54 ( & V_157 -> V_121 , 0 ) ;
F_18 ( & V_4 -> V_33 ) ;
return V_34 ;
}
V_34 = F_151 ( V_4 -> V_33 ,
V_157 -> V_52 == V_374 , V_325 ) ;
if ( V_34 == - V_326 )
return V_34 ;
if ( V_157 -> V_52 != V_374 ) {
F_61 ( & V_157 -> V_118 -> V_6 , L_144
L_145 ) ;
F_62 ( 2 , L_146 ,
F_63 ( & V_157 -> V_118 -> V_6 ) ) ;
F_38 ( V_60 , 2 , L_136 , - V_327 ) ;
F_94 ( V_157 ) ;
return - V_327 ;
}
return F_166 ( V_157 , F_167 ) ;
}
static int F_176 ( int V_375 )
{
if ( ( V_375 & 0xff ) == 8 )
return ( V_375 & 0xff ) + 0x400 ;
if ( ( ( V_375 >> 8 ) & 3 ) == 1 )
return ( V_375 & 0xff ) + 0x200 ;
return V_375 ;
}
static void F_177 ( struct V_156 * V_157 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 ;
V_180 V_364 ;
F_35 ( V_60 , 2 , L_147 ) ;
if ( V_157 -> V_52 == V_213 ) {
V_157 -> V_52 = V_374 ;
goto V_68;
}
V_4 = F_88 ( V_157 -> V_118 ) ;
if ( ! ( F_178 ( V_112 -> V_116 ) ) ) {
if ( F_179 ( V_112 -> V_116 ) == V_376 )
F_41 ( & V_4 -> V_153 . V_118 -> V_6 ,
L_148
L_149 ) ;
else
F_62 ( 2 , L_150
L_151 ,
F_63 ( & V_4 -> V_153 . V_118 -> V_6 ) ) ;
goto V_68;
}
memcpy ( & V_364 , F_172 ( V_112 -> V_116 ) , 2 ) ;
if ( ( V_364 & ~ 0x0100 ) != F_176 ( V_4 -> V_9 . V_266 ) ) {
F_62 ( 2 , L_152
L_153
L_154 , F_63 ( & V_4 -> V_153 . V_118 -> V_6 ) ,
V_4 -> V_9 . V_266 , V_364 ) ;
goto V_68;
}
V_157 -> V_52 = V_114 ;
V_68:
F_91 ( V_157 , V_112 ) ;
}
static void F_180 ( struct V_156 * V_157 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 ;
V_180 V_364 ;
F_35 ( V_60 , 2 , L_155 ) ;
if ( V_157 -> V_52 == V_213 ) {
V_157 -> V_52 = V_374 ;
goto V_68;
}
V_4 = F_88 ( V_157 -> V_118 ) ;
if ( F_87 ( V_4 , V_112 -> V_116 ) )
goto V_68;
if ( ! ( F_178 ( V_112 -> V_116 ) ) ) {
switch ( F_179 ( V_112 -> V_116 ) ) {
case V_376 :
F_41 ( & V_4 -> V_153 . V_118 -> V_6 ,
L_148
L_149 ) ;
break;
case V_377 :
case V_378 :
F_41 ( & V_4 -> V_113 . V_118 -> V_6 ,
L_156
L_157 ) ;
break;
default:
F_62 ( 2 , L_158
L_151 ,
F_63 ( & V_4 -> V_113 . V_118 -> V_6 ) ) ;
}
F_46 ( V_4 , 2 , L_159 ,
F_179 ( V_112 -> V_116 ) ) ;
goto V_68;
}
if ( ( ! F_181 ( V_112 -> V_116 ) ) ||
( V_4 -> V_9 . type == V_11 ) )
V_4 -> V_9 . V_379 = 1 ;
memcpy ( & V_364 , F_172 ( V_112 -> V_116 ) , 2 ) ;
if ( V_364 != F_176 ( V_4 -> V_9 . V_266 ) ) {
F_62 ( 2 , L_160
L_161 ,
F_63 ( & V_4 -> V_113 . V_118 -> V_6 ) ,
V_4 -> V_9 . V_266 , V_364 ) ;
goto V_68;
}
memcpy ( & V_4 -> V_356 . V_380 ,
F_171 ( V_112 -> V_116 ) ,
V_372 ) ;
memcpy ( & V_4 -> V_9 . V_304 [ 0 ] ,
F_182 ( V_112 -> V_116 ) , V_381 ) ;
V_157 -> V_52 = V_114 ;
V_68:
F_91 ( V_157 , V_112 ) ;
}
void F_183 ( struct V_3 * V_4 , int V_158 ,
struct V_111 * V_112 )
{
F_64 ( & V_4 -> V_153 , V_112 -> V_116 , V_158 ) ;
V_112 -> V_170 = F_91 ;
memcpy ( F_169 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_369 , V_184 ) ;
V_4 -> V_177 . V_369 ++ ;
memcpy ( F_96 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_382 , V_184 ) ;
V_4 -> V_177 . V_382 ++ ;
memcpy ( F_184 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_183 , V_184 ) ;
F_40 ( V_154 , 2 , V_112 -> V_116 , V_155 ) ;
}
int F_185 ( struct V_3 * V_4 , int V_158 ,
struct V_111 * V_112 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_383 )
{
int V_34 ;
unsigned long V_29 ;
struct V_123 * V_124 = NULL ;
unsigned long V_384 , V_385 ;
struct V_128 * V_129 ;
F_3 ( V_4 , 2 , L_162 ) ;
if ( V_4 -> V_122 ) {
F_91 ( V_112 -> V_157 , V_112 ) ;
return - V_115 ;
}
V_124 = F_67 ( V_4 ) ;
if ( ! V_124 ) {
return - V_47 ;
}
V_124 -> V_170 = F_186 ;
V_124 -> V_386 = V_383 ;
if ( V_4 -> V_52 == V_53 )
V_124 -> V_177 = V_178 ;
else
V_124 -> V_177 = V_4 -> V_177 . V_387 ++ ;
F_99 ( & V_124 -> V_33 ) ;
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_95 ( & V_124 -> V_39 , & V_4 -> V_182 ) ;
F_17 ( & V_4 -> V_152 , V_29 ) ;
F_40 ( V_154 , 2 , V_112 -> V_116 , V_155 ) ;
while ( F_53 ( & V_4 -> V_153 . V_121 , 0 , 1 ) ) ;
F_183 ( V_4 , V_158 , V_112 ) ;
if ( F_78 ( V_112 -> V_116 ) )
V_385 = V_388 ;
else
V_385 = V_325 ;
V_384 = V_389 + V_385 ;
F_3 ( V_4 , 6 , L_52 ) ;
F_16 ( F_149 ( V_4 -> V_153 . V_118 ) , V_29 ) ;
V_34 = F_65 ( V_4 -> V_153 . V_118 , & V_4 -> V_153 . V_119 ,
( V_120 ) V_112 , 0 , 0 ) ;
F_17 ( F_149 ( V_4 -> V_153 . V_118 ) , V_29 ) ;
if ( V_34 ) {
F_62 ( 2 , L_163
L_164 ,
F_63 ( & V_4 -> V_153 . V_118 -> V_6 ) , V_34 ) ;
F_46 ( V_4 , 2 , L_165 , V_34 ) ;
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_86 ( & V_124 -> V_39 ) ;
F_71 ( V_124 ) ;
F_17 ( & V_4 -> V_152 , V_29 ) ;
F_91 ( V_112 -> V_157 , V_112 ) ;
F_54 ( & V_4 -> V_153 . V_121 , 0 ) ;
F_18 ( & V_4 -> V_33 ) ;
return V_34 ;
}
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
if ( ( V_129 -> V_132 . V_133 == V_391 ) &&
( V_129 -> V_132 . V_392 == V_393 ) ) {
if ( ! F_187 ( V_124 -> V_33 ,
F_45 ( & V_124 -> V_127 ) , V_385 ) )
goto V_394;
} else {
while ( ! F_45 ( & V_124 -> V_127 ) ) {
if ( F_188 ( V_389 , V_384 ) )
goto V_394;
F_189 () ;
}
}
if ( V_124 -> V_34 == - V_115 )
goto error;
V_34 = V_124 -> V_34 ;
F_71 ( V_124 ) ;
return V_34 ;
V_394:
V_124 -> V_34 = - V_327 ;
F_16 ( & V_124 -> V_4 -> V_152 , V_29 ) ;
F_86 ( & V_124 -> V_39 ) ;
F_17 ( & V_124 -> V_4 -> V_152 , V_29 ) ;
F_70 ( & V_124 -> V_127 ) ;
error:
F_54 ( & V_4 -> V_153 . V_121 , 0 ) ;
F_91 ( V_112 -> V_157 , V_112 ) ;
V_4 -> V_153 . V_173 = ( V_4 -> V_153 . V_173 + 1 ) % V_168 ;
V_34 = V_124 -> V_34 ;
F_71 ( V_124 ) ;
return V_34 ;
}
static int F_190 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_166 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_356 . V_395 ,
F_191 ( V_112 -> V_116 ) ,
V_372 ) ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_192 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_167 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_396 , V_397 ) ;
memcpy ( F_193 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_380 , V_372 ) ;
memcpy ( F_194 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_358 , V_372 ) ;
V_34 = F_185 ( V_4 , V_397 , V_112 ,
F_190 , NULL ) ;
return V_34 ;
}
static int F_195 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_168 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_356 . V_398 ,
F_196 ( V_112 -> V_116 ) ,
V_372 ) ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_197 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_169 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_399 , V_400 ) ;
memcpy ( F_198 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_380 , V_372 ) ;
memcpy ( F_199 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_359 , V_372 ) ;
memcpy ( F_200 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_395 , V_372 ) ;
V_34 = F_185 ( V_4 , V_400 , V_112 ,
F_195 , NULL ) ;
return V_34 ;
}
static inline int F_201 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_323 :
return 1500 ;
case V_12 :
return V_4 -> V_9 . V_401 ;
case V_11 :
switch ( V_4 -> V_9 . V_16 ) {
case V_18 :
case V_22 :
return 2000 ;
default:
return V_4 -> V_57 . V_309 ? 1500 : 1492 ;
}
case V_13 :
case V_14 :
return V_4 -> V_57 . V_309 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_202 ( int V_402 )
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
static inline int F_203 ( struct V_3 * V_4 , int V_403 )
{
switch ( V_4 -> V_9 . type ) {
case V_11 :
case V_13 :
case V_14 :
case V_12 :
return ( ( V_403 >= 576 ) &&
( V_403 <= V_4 -> V_9 . V_401 ) ) ;
case V_15 :
case V_323 :
default:
return 1 ;
}
}
static int F_204 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
V_180 V_403 , V_402 ;
V_180 V_158 ;
T_2 V_16 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_170 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_356 . V_404 ,
F_205 ( V_112 -> V_116 ) ,
V_372 ) ;
if ( V_4 -> V_9 . type == V_12 ) {
memcpy ( & V_402 , F_206 ( V_112 -> V_116 ) , 2 ) ;
V_403 = F_202 ( V_402 ) ;
if ( ! V_403 ) {
V_112 -> V_34 = - V_405 ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
if ( V_4 -> V_9 . V_406 && ( V_4 -> V_9 . V_406 != V_403 ) ) {
if ( V_4 -> V_6 &&
( ( V_4 -> V_6 -> V_403 == V_4 -> V_9 . V_406 ) ||
( V_4 -> V_6 -> V_403 > V_403 ) ) )
V_4 -> V_6 -> V_403 = V_403 ;
F_123 ( V_4 ) ;
}
V_4 -> V_9 . V_406 = V_403 ;
V_4 -> V_9 . V_401 = V_403 ;
V_4 -> V_43 . V_267 = V_403 + 2 * V_407 ;
} else {
V_4 -> V_9 . V_401 = * ( V_180 * ) F_206 (
V_112 -> V_116 ) ;
V_4 -> V_9 . V_406 = F_207 ( V_4 -> V_9 . V_401 ,
F_201 ( V_4 ) ) ;
V_4 -> V_43 . V_267 = V_268 ;
}
memcpy ( & V_158 , F_208 ( V_112 -> V_116 ) , 2 ) ;
if ( V_158 >= V_408 ) {
memcpy ( & V_16 ,
F_209 ( V_112 -> V_116 ) , 1 ) ;
V_4 -> V_9 . V_16 = V_16 ;
} else
V_4 -> V_9 . V_16 = 0 ;
F_38 ( V_60 , 2 , L_171 , V_4 -> V_9 . V_16 ) ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_210 ( struct V_3 * V_4 )
{
int V_34 ;
char V_409 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_172 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_410 , V_411 ) ;
* ( F_211 ( V_112 -> V_116 ) ) =
( T_2 ) V_4 -> V_9 . V_371 ;
if ( V_4 -> V_57 . V_309 )
if ( V_4 -> V_9 . type == V_15 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
memcpy ( F_212 ( V_112 -> V_116 ) , & V_409 , 1 ) ;
memcpy ( F_213 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_398 , V_372 ) ;
memcpy ( F_214 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_360 , V_372 ) ;
memcpy ( F_215 ( V_112 -> V_116 ) ,
V_4 -> V_9 . V_415 , 9 ) ;
V_34 = F_185 ( V_4 , V_411 , V_112 ,
F_204 , NULL ) ;
return V_34 ;
}
static int F_216 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_173 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_356 . V_416 ,
F_217 ( V_112 -> V_116 ) ,
V_372 ) ;
if ( ! strncmp ( L_174 , F_217 ( V_112 -> V_116 ) ,
3 ) ) {
F_35 ( V_60 , 2 , L_175 ) ;
F_41 ( & V_4 -> V_7 -> V_6 , L_176
L_177 ) ;
V_112 -> V_34 = - V_417 ;
}
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_218 ( struct V_3 * V_4 )
{
int V_34 ;
V_180 V_364 ;
struct V_111 * V_112 ;
struct V_365 V_418 ;
F_35 ( V_60 , 2 , L_178 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_419 , V_420 ) ;
memcpy ( F_219 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_398 , V_372 ) ;
memcpy ( F_220 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_361 , V_372 ) ;
memcpy ( F_221 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_404 , V_372 ) ;
F_173 ( F_37 ( V_4 ) , & V_418 ) ;
memcpy ( F_222 ( V_112 -> V_116 ) , & V_418 . V_373 , 2 ) ;
V_364 = ( V_4 -> V_9 . V_350 << 8 ) + V_4 -> V_9 . V_349 ;
memcpy ( F_223 ( V_112 -> V_116 ) , & V_364 , 2 ) ;
V_34 = F_185 ( V_4 , V_420 , V_112 ,
F_216 , NULL ) ;
return V_34 ;
}
static int F_50 ( struct V_90 * V_91 , int V_92 )
{
int V_34 ;
struct V_95 * V_421 ;
V_34 = 0 ;
V_421 = F_224 ( V_100 , V_125 ) ;
if ( ! V_421 ) {
V_34 = - V_47 ;
goto V_68;
}
V_421 -> V_74 = & V_91 -> V_62 [ V_92 ] ;
F_225 ( & V_421 -> V_231 ) ;
F_226 ( & V_421 -> V_231 . V_152 , & V_422 ) ;
V_421 -> V_91 = V_91 ;
V_421 -> V_101 = NULL ;
V_421 -> V_94 = V_91 -> V_73 [ V_92 ] ;
F_54 ( & V_421 -> V_52 , V_246 ) ;
V_91 -> V_73 [ V_92 ] = V_421 ;
if ( V_91 -> V_79 ) {
V_91 -> V_79 [ V_92 ] . V_423 = V_421 ;
F_46 ( V_91 -> V_4 , 2 , L_179 , V_92 ) ;
F_46 ( V_91 -> V_4 , 2 , L_43 , ( long ) V_421 ) ;
F_46 ( V_91 -> V_4 , 2 , L_43 ,
( long ) V_421 -> V_94 ) ;
}
V_68:
return V_34 ;
}
static int F_227 ( struct V_3 * V_4 )
{
int V_41 , V_42 ;
F_35 ( V_60 , 2 , L_180 ) ;
if ( F_53 ( & V_4 -> V_43 . V_52 , V_253 ,
V_337 ) != V_253 )
return 0 ;
V_4 -> V_43 . V_255 = F_26 ( sizeof( struct V_71 ) ,
V_46 ) ;
if ( ! V_4 -> V_43 . V_255 )
goto V_424;
F_35 ( V_60 , 2 , L_181 ) ;
F_40 ( V_60 , 2 , & V_4 -> V_43 . V_255 , sizeof( void * ) ) ;
memset ( V_4 -> V_43 . V_255 , 0 , sizeof( struct V_71 ) ) ;
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_74 =
& V_4 -> V_43 . V_255 -> V_62 [ V_41 ] ;
V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_256 = NULL ;
}
if ( F_25 ( V_4 ) )
goto V_425;
V_4 -> V_43 . V_78 =
F_26 ( V_4 -> V_43 . V_76 *
sizeof( struct V_90 * ) , V_46 ) ;
if ( ! V_4 -> V_43 . V_78 )
goto V_426;
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
V_4 -> V_43 . V_78 [ V_41 ] = F_26 ( sizeof( struct V_90 ) ,
V_46 ) ;
if ( ! V_4 -> V_43 . V_78 [ V_41 ] )
goto V_427;
F_38 ( V_60 , 2 , L_182 , V_41 ) ;
F_40 ( V_60 , 2 , & V_4 -> V_43 . V_78 [ V_41 ] , sizeof( void * ) ) ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_428 = V_41 ;
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 ) {
F_69 ( V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] != NULL ) ;
if ( F_50 ( V_4 -> V_43 . V_78 [ V_41 ] , V_42 ) )
goto V_429;
}
}
if ( F_39 ( V_4 ) )
goto V_427;
return 0 ;
V_429:
while ( V_42 > 0 ) {
-- V_42 ;
F_49 ( V_100 ,
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] ) ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] = NULL ;
}
V_427:
while ( V_41 > 0 ) {
F_31 ( V_4 -> V_43 . V_78 [ -- V_41 ] ) ;
F_121 ( V_4 -> V_43 . V_78 [ V_41 ] , 1 ) ;
}
F_31 ( V_4 -> V_43 . V_78 ) ;
V_4 -> V_43 . V_78 = NULL ;
V_426:
F_27 ( V_4 ) ;
V_425:
F_31 ( V_4 -> V_43 . V_255 ) ;
V_4 -> V_43 . V_255 = NULL ;
V_424:
F_54 ( & V_4 -> V_43 . V_52 , V_253 ) ;
return - V_47 ;
}
static void F_228 ( struct V_3 * V_4 ,
char * V_430 )
{
V_430 [ 0 ] = V_351 [ 'P' ] ;
V_430 [ 1 ] = V_351 [ 'C' ] ;
V_430 [ 2 ] = V_351 [ 'I' ] ;
V_430 [ 3 ] = V_351 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_430 [ 4 ] ) ) = F_229 ( V_4 ) ;
* ( ( unsigned int * ) ( & V_430 [ 8 ] ) ) = F_230 ( V_4 ) ;
* ( ( unsigned int * ) ( & V_430 [ 12 ] ) ) = F_231 ( V_4 ) ;
}
static void F_232 ( struct V_3 * V_4 ,
char * V_430 )
{
V_430 [ 16 ] = V_351 [ 'B' ] ;
V_430 [ 17 ] = V_351 [ 'L' ] ;
V_430 [ 18 ] = V_351 [ 'K' ] ;
V_430 [ 19 ] = V_351 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_430 [ 20 ] ) ) = V_4 -> V_9 . V_352 . V_353 ;
* ( ( unsigned int * ) ( & V_430 [ 24 ] ) ) = V_4 -> V_9 . V_352 . V_354 ;
* ( ( unsigned int * ) ( & V_430 [ 28 ] ) ) =
V_4 -> V_9 . V_352 . V_355 ;
}
static int F_233 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 3 , L_183 ) ;
return F_234 ( F_37 ( V_4 ) ) ;
}
static int F_235 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_184 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_431 , V_432 ) ;
memcpy ( F_236 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_398 , V_372 ) ;
memcpy ( F_237 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_416 , V_372 ) ;
V_34 = F_185 ( V_4 , V_432 , V_112 , NULL , NULL ) ;
return V_34 ;
}
static int F_238 ( struct V_3 * V_4 )
{
int V_34 ;
F_35 ( V_60 , 2 , L_185 ) ;
V_34 = F_59 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
return V_34 ;
}
V_34 = F_192 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_136 , V_34 ) ;
goto V_433;
}
V_34 = F_197 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_433;
}
V_34 = F_210 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_186 , V_34 ) ;
goto V_433;
}
V_34 = F_218 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_433;
}
V_34 = F_227 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_433;
}
V_34 = F_239 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_188 , V_34 ) ;
F_123 ( V_4 ) ;
goto V_433;
}
V_34 = F_233 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_189 , V_34 ) ;
goto V_433;
}
V_34 = F_235 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_190 , V_34 ) ;
goto V_433;
}
return 0 ;
V_433:
F_157 ( V_4 , V_4 -> V_9 . type != V_12 ) ;
F_240 ( F_37 ( V_4 ) ) ;
return V_34 ;
}
static void F_241 ( struct V_3 * V_4 )
{
char V_434 [ 15 ] ;
int V_41 ;
sprintf ( V_434 , L_191 , V_4 -> V_9 . V_415 + 1 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
V_434 [ V_41 ] =
( char ) V_435 [ ( T_2 ) V_434 [ V_41 ] ] ;
V_434 [ 8 ] = 0 ;
F_83 ( & V_4 -> V_7 -> V_6 , L_192
L_193 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? V_4 -> V_9 . V_304 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ,
V_434 ) ;
}
static void F_242 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 . V_415 [ 0 ] )
F_83 ( & V_4 -> V_7 -> V_6 , L_196
L_197
L_198 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? V_4 -> V_9 . V_304 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ) ;
else
F_83 ( & V_4 -> V_7 -> V_6 , L_196
L_199 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? V_4 -> V_9 . V_304 : L_74 ,
( V_4 -> V_9 . V_304 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ) ;
}
void F_243 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_11 :
case V_13 :
case V_14 :
if ( ! V_4 -> V_9 . V_304 [ 0 ] ) {
sprintf ( V_4 -> V_9 . V_304 , L_200 ,
V_4 -> V_9 . V_304 [ 2 ] ,
V_4 -> V_9 . V_304 [ 3 ] ) ;
V_4 -> V_9 . V_304 [ V_381 ] = 0 ;
break;
}
case V_12 :
if ( ( V_4 -> V_9 . V_10 ) ||
( V_4 -> V_9 . V_304 [ 0 ] & 0x80 ) ) {
V_4 -> V_9 . V_304 [ 0 ] = ( char ) V_435 [ ( T_2 )
V_4 -> V_9 . V_304 [ 0 ] ] ;
V_4 -> V_9 . V_304 [ 1 ] = ( char ) V_435 [ ( T_2 )
V_4 -> V_9 . V_304 [ 1 ] ] ;
V_4 -> V_9 . V_304 [ 2 ] = ( char ) V_435 [ ( T_2 )
V_4 -> V_9 . V_304 [ 2 ] ] ;
V_4 -> V_9 . V_304 [ 3 ] = ( char ) V_435 [ ( T_2 )
V_4 -> V_9 . V_304 [ 3 ] ] ;
V_4 -> V_9 . V_304 [ V_381 ] = 0 ;
}
break;
default:
memset ( & V_4 -> V_9 . V_304 [ 0 ] , 0 , V_381 + 1 ) ;
}
if ( V_4 -> V_9 . V_379 )
F_241 ( V_4 ) ;
else
F_242 ( V_4 ) ;
}
static void F_244 ( struct V_3 * V_4 )
{
struct V_36 * V_436 ;
F_3 ( V_4 , 5 , L_201 ) ;
F_245 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_246 ( V_4 , V_436 ) ;
}
}
static inline struct V_36 * F_247 (
struct V_3 * V_4 )
{
struct V_305 * V_437 ;
struct V_36 * V_436 ;
int V_41 , free ;
struct V_438 * V_438 ;
if ( F_248 ( & V_4 -> V_43 . V_56 . V_50 ) )
return NULL ;
F_249 (plh, &card->qdio.in_buf_pool.entry_list) {
V_436 = F_250 ( V_437 , struct V_36 , V_39 ) ;
free = 1 ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
if ( F_251 ( F_252 ( V_436 -> V_48 [ V_41 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_86 ( & V_436 -> V_39 ) ;
return V_436 ;
}
}
V_436 = F_250 ( V_4 -> V_43 . V_56 . V_50 . V_439 ,
struct V_36 , V_39 ) ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
if ( F_251 ( F_252 ( V_436 -> V_48 [ V_41 ] ) ) > 1 ) {
V_438 = F_253 ( V_125 ) ;
if ( ! V_438 ) {
return NULL ;
} else {
F_30 ( ( unsigned long ) V_436 -> V_48 [ V_41 ] ) ;
V_436 -> V_48 [ V_41 ] = F_254 ( V_438 ) ;
if ( V_4 -> V_57 . V_277 )
V_4 -> V_440 . V_441 ++ ;
}
}
}
F_86 ( & V_436 -> V_39 ) ;
return V_436 ;
}
static int F_255 ( struct V_3 * V_4 ,
struct V_442 * V_228 )
{
struct V_36 * V_37 ;
int V_41 ;
if ( ( V_4 -> V_57 . V_58 == V_59 ) && ( ! V_228 -> V_256 ) ) {
V_228 -> V_256 = F_256 ( V_443 + V_444 ) ;
if ( ! V_228 -> V_256 )
return 1 ;
}
V_37 = F_247 ( V_4 ) ;
if ( ! V_37 )
return 1 ;
V_228 -> V_37 = V_37 ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
V_228 -> V_74 -> V_242 [ V_41 ] . V_250 = V_407 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_247 = V_37 -> V_48 [ V_41 ] ;
if ( V_41 == F_28 ( V_4 ) - 1 )
V_228 -> V_74 -> V_242 [ V_41 ] . V_251 = V_445 ;
else
V_228 -> V_74 -> V_242 [ V_41 ] . V_251 = 0 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_243 = 0 ;
}
return 0 ;
}
int F_257 ( struct V_3 * V_4 )
{
int V_41 , V_42 ;
int V_34 ;
F_35 ( V_60 , 2 , L_202 ) ;
memset ( V_4 -> V_43 . V_255 -> V_62 , 0 ,
V_63 * sizeof( struct V_64 ) ) ;
F_244 ( V_4 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_56 . V_45 - 1 ; ++ V_41 )
F_255 ( V_4 , & V_4 -> V_43 . V_255 -> V_73 [ V_41 ] ) ;
V_4 -> V_43 . V_255 -> V_65 =
V_4 -> V_43 . V_56 . V_45 - 1 ;
V_34 = F_36 ( F_37 ( V_4 ) , V_66 , 0 , 0 ,
V_4 -> V_43 . V_56 . V_45 - 1 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
return V_34 ;
}
V_34 = F_34 ( V_4 ) ;
if ( V_34 ) {
return V_34 ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
memset ( V_4 -> V_43 . V_78 [ V_41 ] -> V_62 , 0 ,
V_63 * sizeof( struct V_64 ) ) ;
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 ) {
F_56 ( V_4 -> V_43 . V_78 [ V_41 ] ,
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] ,
V_246 ) ;
}
V_4 -> V_43 . V_78 [ V_41 ] -> V_4 = V_4 ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_446 = 0 ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_447 = 0 ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_448 , 0 ) ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_245 , 0 ) ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_52 ,
V_449 ) ;
}
return 0 ;
}
static inline T_2 F_258 ( enum V_450 V_16 )
{
switch ( V_16 ) {
case V_18 :
return 2 ;
default:
return 1 ;
}
}
static void F_259 ( struct V_3 * V_4 ,
struct V_128 * V_129 , T_2 V_133 ,
enum V_451 V_452 )
{
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_129 -> V_132 . V_133 = V_133 ;
V_129 -> V_132 . V_453 = V_454 ;
V_129 -> V_132 . V_177 = V_4 -> V_177 . V_387 ;
V_129 -> V_132 . V_455 = F_258 ( V_4 -> V_9 . V_16 ) ;
V_129 -> V_132 . V_456 = ( T_2 ) V_4 -> V_9 . V_371 ;
if ( V_4 -> V_57 . V_309 )
V_129 -> V_132 . V_457 = 2 ;
else
V_129 -> V_132 . V_457 = 1 ;
V_129 -> V_132 . V_458 = 1 ;
V_129 -> V_132 . V_392 = V_452 ;
V_129 -> V_132 . V_459 = 0 ;
V_129 -> V_132 . V_460 = 0 ;
}
struct V_111 * F_260 ( struct V_3 * V_4 ,
enum V_461 V_462 , enum V_451 V_452 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
F_259 ( V_4 , V_129 , V_462 , V_452 ) ;
return V_112 ;
}
void F_261 ( struct V_3 * V_4 , struct V_111 * V_112 ,
char V_409 )
{
memcpy ( V_112 -> V_116 , V_463 , V_390 ) ;
memcpy ( F_262 ( V_112 -> V_116 ) , & V_409 , 1 ) ;
memcpy ( F_263 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_416 , V_372 ) ;
}
int F_264 ( struct V_3 * V_4 , struct V_111 * V_112 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_383 )
{
int V_34 ;
char V_409 ;
F_3 ( V_4 , 4 , L_203 ) ;
if ( V_4 -> V_57 . V_309 )
if ( V_4 -> V_9 . type == V_15 )
V_409 = V_412 ;
else
V_409 = V_413 ;
else
V_409 = V_414 ;
F_261 ( V_4 , V_112 , V_409 ) ;
V_34 = F_185 ( V_4 , V_464 ,
V_112 , F_186 , V_383 ) ;
if ( V_34 == - V_327 ) {
F_85 ( V_4 ) ;
F_66 ( V_4 ) ;
}
return V_34 ;
}
int F_265 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_204 ) ;
V_112 = F_260 ( V_4 , V_143 , 0 ) ;
V_34 = F_264 ( V_4 , V_112 , NULL , NULL ) ;
return V_34 ;
}
static int F_266 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_205 ) ;
V_129 = (struct V_128 * ) V_116 ;
if ( V_129 -> V_132 . V_138 == 0 )
V_129 -> V_132 . V_138 =
V_129 -> V_116 . V_465 . V_132 . V_138 ;
return 0 ;
}
static int F_267 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_3 ( V_4 , 3 , L_206 ) ;
V_129 = (struct V_128 * ) V_116 ;
if ( V_129 -> V_116 . V_465 . V_116 . V_466 . V_467 & 0x7f ) {
V_4 -> V_9 . V_16 =
V_129 -> V_116 . V_465 . V_116 . V_466 . V_467 ;
F_38 ( V_60 , 2 , L_207 , V_4 -> V_9 . V_16 ) ;
}
V_4 -> V_57 . V_468 . V_469 =
V_129 -> V_116 . V_465 . V_116 . V_466 . V_470 ;
return F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
}
static struct V_111 * F_268 ( struct V_3 * V_4 ,
T_1 V_133 , T_1 V_471 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
V_112 = F_260 ( V_4 , V_472 ,
V_393 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_129 -> V_116 . V_465 . V_132 . V_473 = V_471 ;
V_129 -> V_116 . V_465 . V_132 . V_474 = V_133 ;
V_129 -> V_116 . V_465 . V_132 . V_475 = 1 ;
V_129 -> V_116 . V_465 . V_132 . V_476 = 1 ;
return V_112 ;
}
int F_269 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_3 ( V_4 , 3 , L_208 ) ;
V_112 = F_268 ( V_4 , V_477 ,
sizeof( struct V_478 ) ) ;
V_34 = F_264 ( V_4 , V_112 , F_267 , NULL ) ;
return V_34 ;
}
static int F_270 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_35 ( V_60 , 2 , L_209 ) ;
V_129 = (struct V_128 * ) V_116 ;
switch ( V_129 -> V_132 . V_138 ) {
case V_479 :
case V_480 :
F_35 ( V_60 , 2 , L_210 ) ;
V_4 -> V_57 . V_481 . V_469 |= V_482 ;
V_4 -> V_57 . V_483 . V_469 |= V_482 ;
return - 0 ;
default:
if ( V_129 -> V_132 . V_138 ) {
F_62 ( 1 , L_211
L_212 ,
F_63 ( & V_4 -> V_7 -> V_6 ) ,
V_129 -> V_132 . V_138 ) ;
return 0 ;
}
}
if ( V_129 -> V_132 . V_392 == V_393 ) {
V_4 -> V_57 . V_481 . V_469 = V_129 -> V_132 . V_459 ;
V_4 -> V_57 . V_481 . V_484 = V_129 -> V_132 . V_460 ;
} else if ( V_129 -> V_132 . V_392 == V_485 ) {
V_4 -> V_57 . V_483 . V_469 = V_129 -> V_132 . V_459 ;
V_4 -> V_57 . V_483 . V_484 = V_129 -> V_132 . V_460 ;
} else
F_62 ( 1 , L_213
L_214 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
return 0 ;
}
int F_271 ( struct V_3 * V_4 , enum V_451 V_452 )
{
int V_34 ;
struct V_111 * V_112 ;
F_38 ( V_60 , 2 , L_215 , V_452 ) ;
V_112 = F_260 ( V_4 , V_486 , V_452 ) ;
V_34 = F_264 ( V_4 , V_112 , F_270 , NULL ) ;
return V_34 ;
}
static int F_272 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
V_180 V_34 ;
V_129 = (struct V_128 * ) V_116 ;
V_34 = V_129 -> V_132 . V_138 ;
if ( V_34 )
F_46 ( V_4 , 2 , L_216 , V_34 ) ;
else
V_4 -> V_9 . V_487 = V_129 -> V_116 . V_488 . V_489 ;
return 0 ;
}
static int F_273 ( struct V_3 * V_4 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_35 ( V_60 , 2 , L_217 ) ;
V_112 = F_260 ( V_4 , V_137 , 0 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_129 -> V_116 . V_488 . V_490 = 16 ;
V_129 -> V_116 . V_488 . V_491 = V_492 ;
return F_264 ( V_4 , V_112 , F_272 , NULL ) ;
}
static void F_274 ( struct V_3 * V_4 , struct V_493 * V_494 )
{
unsigned long V_9 = F_275 ( V_46 ) ;
struct V_495 * V_496 = (struct V_495 * ) V_9 ;
struct V_497 * V_498 = (struct V_497 * ) V_9 ;
struct V_365 V_499 ;
int V_375 ;
V_494 -> V_141 = V_4 -> V_9 . V_141 ;
F_173 ( F_147 ( V_4 ) , & V_499 ) ;
V_494 -> V_500 = V_499 . V_500 ;
V_494 -> V_373 = V_499 . V_373 ;
if ( ! V_9 )
return;
V_375 = F_276 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_375 >= 2 ) && ( F_276 ( V_496 , 2 , 2 , 2 ) == 0 ) )
V_494 -> V_501 = V_496 -> V_502 ;
if ( ( V_375 >= 3 ) && ( F_276 ( V_498 , 3 , 2 , 2 ) == 0 ) ) {
F_277 ( V_498 -> V_503 [ 0 ] . V_504 , sizeof( V_498 -> V_503 [ 0 ] . V_504 ) ) ;
memcpy ( V_494 -> V_505 , V_498 -> V_503 [ 0 ] . V_504 , sizeof( V_494 -> V_505 ) ) ;
}
F_30 ( V_9 ) ;
return;
}
static int F_278 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
V_180 V_34 ;
V_129 = (struct V_128 * ) V_116 ;
V_34 = V_129 -> V_132 . V_138 ;
if ( V_34 )
F_46 ( V_4 , 2 , L_218 , V_34 ) ;
return 0 ;
}
int F_279 ( struct V_3 * V_4 , enum V_506 V_507 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_35 ( V_60 , 2 , L_219 ) ;
V_112 = F_260 ( V_4 , V_137 , 0 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_129 -> V_116 . V_488 . V_490 = 80 ;
V_129 -> V_116 . V_488 . V_491 = V_508 ;
V_129 -> V_116 . V_488 . type = 1 ;
V_129 -> V_116 . V_488 . V_507 = V_507 ;
switch ( V_507 ) {
case V_509 :
V_129 -> V_116 . V_488 . V_57 = 0x0003 ;
V_129 -> V_116 . V_488 . V_489 = 0x00010000 +
sizeof( struct V_493 ) ;
F_274 ( V_4 ,
(struct V_493 * ) V_129 -> V_116 . V_488 . V_510 ) ;
break;
case V_511 :
V_129 -> V_116 . V_488 . V_57 = 0x0001 ;
break;
case V_512 :
break;
}
return F_264 ( V_4 , V_112 , F_278 , NULL ) ;
}
int F_280 ( struct V_3 * V_4 , struct V_64 * V_228 ,
unsigned int V_513 , const char * V_514 )
{
if ( V_513 ) {
F_3 ( V_4 , 2 , V_514 ) ;
F_46 ( V_4 , 2 , L_220 ,
V_228 -> V_242 [ 15 ] . V_243 ) ;
F_46 ( V_4 , 2 , L_221 ,
V_228 -> V_242 [ 14 ] . V_243 ) ;
F_46 ( V_4 , 2 , L_222 , V_513 ) ;
if ( ( V_228 -> V_242 [ 15 ] . V_243 ) == 0x12 ) {
V_4 -> V_515 . V_516 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_298 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_254 . V_2 ) ;
F_46 ( V_4 , 2 , L_223 , V_4 -> V_517 ) ;
F_281 ( V_4 , V_4 -> V_517 ) ;
}
void F_281 ( struct V_3 * V_4 , int V_164 )
{
struct V_71 * V_110 = V_4 -> V_43 . V_255 ;
struct V_305 * V_518 ;
int V_162 ;
int V_41 ;
int V_34 ;
int V_519 = 0 ;
V_162 = ( V_164 < V_110 -> V_65 ) ?
V_4 -> V_43 . V_56 . V_45 -
( V_110 -> V_65 - V_164 ) :
V_4 -> V_43 . V_56 . V_45 -
( V_110 -> V_65 + V_63 - V_164 ) ;
if ( V_162 >= F_282 ( V_4 ) ) {
for ( V_41 = V_110 -> V_65 ;
V_41 < V_110 -> V_65 + V_162 ; ++ V_41 ) {
if ( F_255 ( V_4 ,
& V_110 -> V_73 [ V_41 % V_63 ] ) ) {
break;
} else {
V_519 ++ ;
}
}
if ( V_519 < V_162 ) {
F_54 ( & V_4 -> V_520 , 3 ) ;
V_162 = V_519 ;
} else {
F_283 ( & V_4 -> V_520 , - 1 , 0 ) ;
}
if ( ! V_162 ) {
V_41 = 0 ;
F_249 (lh, &card->qdio.in_buf_pool.entry_list)
V_41 ++ ;
if ( V_41 == V_4 -> V_43 . V_56 . V_45 ) {
F_3 ( V_4 , 2 , L_224 ) ;
V_4 -> V_517 = V_164 ;
F_284 (
& V_4 -> V_254 ,
V_521 ) ;
}
return;
}
if ( V_4 -> V_57 . V_277 ) {
V_4 -> V_440 . V_522 ++ ;
V_4 -> V_440 . V_523 =
F_285 () ;
}
V_34 = F_36 ( F_37 ( V_4 ) , V_66 , 0 ,
V_110 -> V_65 , V_162 ) ;
if ( V_4 -> V_57 . V_277 )
V_4 -> V_440 . V_524 +=
F_285 () -
V_4 -> V_440 . V_523 ;
if ( V_34 ) {
F_3 ( V_4 , 2 , L_225 ) ;
}
V_110 -> V_65 = ( V_110 -> V_65 + V_162 ) %
V_63 ;
}
}
static int F_286 ( struct V_3 * V_4 ,
struct V_95 * V_74 , unsigned int V_525 )
{
int V_81 = V_74 -> V_74 -> V_242 [ 15 ] . V_243 ;
F_3 ( V_4 , 6 , L_226 ) ;
if ( V_4 -> V_9 . type == V_12 ) {
if ( V_81 == 0 ) {
V_525 = 0 ;
} else {
V_525 = 1 ;
}
}
F_280 ( V_4 , V_74 -> V_74 , V_525 , L_227 ) ;
if ( ! V_525 )
return V_526 ;
if ( ( V_81 >= 15 ) && ( V_81 <= 31 ) )
return V_527 ;
F_3 ( V_4 , 1 , L_228 ) ;
F_46 ( V_4 , 1 , L_229 ,
( V_181 ) V_525 , ( T_3 ) V_81 ) ;
return V_528 ;
}
static void F_287 ( struct V_90 * V_110 )
{
if ( ! V_110 -> V_447 ) {
if ( F_45 ( & V_110 -> V_448 )
>= V_529 ) {
F_3 ( V_110 -> V_4 , 6 , L_230 ) ;
if ( V_110 -> V_4 -> V_57 . V_277 )
V_110 -> V_4 -> V_440 . V_530 ++ ;
V_110 -> V_447 = 1 ;
}
}
}
static int F_288 ( struct V_90 * V_110 )
{
struct V_95 * V_74 ;
int V_531 = 0 ;
if ( V_110 -> V_447 ) {
if ( F_45 ( & V_110 -> V_448 )
<= V_532 ) {
F_3 ( V_110 -> V_4 , 6 , L_231 ) ;
if ( V_110 -> V_4 -> V_57 . V_277 )
V_110 -> V_4 -> V_440 . V_533 ++ ;
V_110 -> V_447 = 0 ;
V_74 = V_110 -> V_73 [ V_110 -> V_446 ] ;
if ( ( F_45 ( & V_74 -> V_52 ) ==
V_246 ) &&
( V_74 -> V_252 > 0 ) ) {
F_54 ( & V_74 -> V_52 ,
V_106 ) ;
V_531 ++ ;
V_110 -> V_446 =
( V_110 -> V_446 + 1 ) %
V_63 ;
}
}
}
return V_531 ;
}
static int F_289 ( struct V_90 * V_110 )
{
struct V_95 * V_74 ;
V_74 = V_110 -> V_73 [ V_110 -> V_446 ] ;
if ( ( F_45 ( & V_74 -> V_52 ) == V_246 ) &&
( V_74 -> V_252 > 0 ) ) {
F_54 ( & V_74 -> V_52 , V_106 ) ;
V_110 -> V_446 =
( V_110 -> V_446 + 1 ) % V_63 ;
return 1 ;
}
return 0 ;
}
static void F_290 ( struct V_90 * V_110 , int V_164 ,
int V_162 )
{
struct V_95 * V_228 ;
int V_34 ;
int V_41 ;
unsigned int V_534 ;
for ( V_41 = V_164 ; V_41 < V_164 + V_162 ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
V_228 = V_110 -> V_73 [ V_92 ] ;
V_228 -> V_74 -> V_242 [ V_228 -> V_252 - 1 ] . V_251 |=
V_445 ;
if ( V_110 -> V_79 )
V_110 -> V_79 [ V_92 ] . V_423 = V_228 ;
if ( V_110 -> V_4 -> V_9 . type == V_12 )
continue;
if ( ! V_110 -> V_447 ) {
if ( ( F_45 ( & V_110 -> V_448 ) >=
( V_529 -
V_535 ) ) &&
! F_45 ( & V_110 -> V_245 ) ) {
F_70 ( & V_110 -> V_245 ) ;
V_228 -> V_74 -> V_242 [ 0 ] . V_243 |= V_244 ;
}
} else {
if ( ! F_45 ( & V_110 -> V_245 ) ) {
F_70 ( & V_110 -> V_245 ) ;
V_228 -> V_74 -> V_242 [ 0 ] . V_243 |= V_244 ;
}
}
}
V_110 -> V_4 -> V_6 -> V_536 = V_389 ;
if ( V_110 -> V_4 -> V_57 . V_277 ) {
V_110 -> V_4 -> V_440 . V_537 ++ ;
V_110 -> V_4 -> V_440 . V_538 =
F_285 () ;
}
V_534 = V_539 ;
if ( F_45 ( & V_110 -> V_245 ) )
V_534 |= V_540 ;
V_34 = F_36 ( F_37 ( V_110 -> V_4 ) , V_534 ,
V_110 -> V_428 , V_164 , V_162 ) ;
if ( V_110 -> V_4 -> V_57 . V_277 )
V_110 -> V_4 -> V_440 . V_541 +=
F_285 () -
V_110 -> V_4 -> V_440 . V_538 ;
F_291 ( V_162 , & V_110 -> V_448 ) ;
if ( V_34 ) {
V_110 -> V_4 -> V_515 . V_542 += V_162 ;
if ( V_34 == - V_543 )
return;
F_3 ( V_110 -> V_4 , 2 , L_232 ) ;
F_46 ( V_110 -> V_4 , 2 , L_233 , V_110 -> V_428 ) ;
F_46 ( V_110 -> V_4 , 2 , L_234 , V_164 ) ;
F_46 ( V_110 -> V_4 , 2 , L_235 , V_162 ) ;
F_46 ( V_110 -> V_4 , 2 , L_165 , V_34 ) ;
F_66 ( V_110 -> V_4 ) ;
return;
}
if ( V_110 -> V_4 -> V_57 . V_277 )
V_110 -> V_4 -> V_440 . V_544 += V_162 ;
}
static void F_292 ( struct V_90 * V_110 )
{
int V_164 ;
int V_545 = 0 ;
int V_546 = 0 ;
if ( ( F_45 ( & V_110 -> V_448 ) <= V_532 ) ||
! F_45 ( & V_110 -> V_245 ) ) {
if ( F_124 ( & V_110 -> V_52 , V_547 ) ==
V_449 ) {
F_293 ( V_110 -> V_4 -> V_6 ) ;
V_164 = V_110 -> V_446 ;
V_546 = V_110 -> V_447 ;
F_294 () ;
V_545 += F_288 ( V_110 ) ;
if ( ! V_545 &&
! F_45 ( & V_110 -> V_245 ) )
V_545 +=
F_289 ( V_110 ) ;
if ( V_110 -> V_4 -> V_57 . V_277 &&
V_546 )
V_110 -> V_4 -> V_440 . V_548 +=
V_545 ;
if ( V_545 )
F_290 ( V_110 , V_164 , V_545 ) ;
F_54 ( & V_110 -> V_52 , V_449 ) ;
}
}
}
void F_295 ( struct V_189 * V_118 , int V_110 ,
unsigned long V_549 )
{
struct V_3 * V_4 = (struct V_3 * ) V_549 ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> V_29 & V_550 ) )
F_296 ( & V_4 -> V_551 ) ;
}
int F_297 ( struct V_3 * V_4 , enum V_552 V_58 )
{
int V_34 ;
if ( V_4 -> V_57 . V_58 == V_553 ) {
V_34 = - 1 ;
goto V_68;
} else {
if ( V_4 -> V_57 . V_58 == V_58 ) {
V_34 = 0 ;
goto V_68;
}
if ( V_4 -> V_52 != V_53 &&
V_4 -> V_52 != V_54 ) {
V_34 = - 1 ;
goto V_68;
}
F_123 ( V_4 ) ;
V_4 -> V_57 . V_58 = V_58 ;
V_34 = 0 ;
}
V_68:
return V_34 ;
}
static void F_298 ( struct V_3 * V_4 ,
unsigned int V_525 ,
unsigned int V_110 , int V_554 , int V_162 ) {
struct V_71 * V_58 = V_4 -> V_43 . V_61 ;
int V_41 ;
int V_34 ;
if ( ! F_58 ( V_4 , V_110 ) )
goto V_68;
F_46 ( V_4 , 5 , L_236 , V_554 ) ;
F_46 ( V_4 , 5 , L_237 , V_162 ) ;
F_46 ( V_4 , 5 , L_238 , V_525 ) ;
if ( V_525 ) {
F_293 ( V_4 -> V_6 ) ;
F_66 ( V_4 ) ;
goto V_68;
}
if ( V_4 -> V_57 . V_277 ) {
V_4 -> V_440 . V_555 ++ ;
V_4 -> V_440 . V_556 = F_285 () ;
}
for ( V_41 = V_554 ; V_41 < V_554 + V_162 ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
struct V_64 * V_74 = & V_58 -> V_62 [ V_92 ] ;
int V_557 ;
V_557 = 0 ;
while ( V_74 -> V_242 [ V_557 ] . V_247 ) {
unsigned long V_102 ;
V_102 = ( unsigned long ) V_74 -> V_242 [ V_557 ] . V_247 ;
F_51 ( V_4 , V_102 ) ;
V_74 -> V_242 [ V_557 ] . V_247 = NULL ;
V_74 -> V_242 [ V_557 ] . V_251 = 0 ;
V_74 -> V_242 [ V_557 ] . V_243 = 0 ;
V_74 -> V_242 [ V_557 ] . V_250 = 0 ;
++ V_557 ;
}
V_74 -> V_242 [ 15 ] . V_251 = 0 ;
V_74 -> V_242 [ 15 ] . V_243 = 0 ;
}
V_34 = F_36 ( F_37 ( V_4 ) , V_66 , V_110 ,
V_4 -> V_43 . V_61 -> V_65 ,
V_162 ) ;
if ( V_34 ) {
F_61 ( & V_4 -> V_7 -> V_6 ,
L_239 , V_34 ) ;
F_3 ( V_4 , 2 , L_240 ) ;
}
V_4 -> V_43 . V_61 -> V_65 = ( V_4 -> V_43 . V_61 -> V_65
+ V_162 ) % V_63 ;
F_299 ( V_4 -> V_6 ) ;
if ( V_4 -> V_57 . V_277 ) {
int V_558 = F_285 () ;
V_558 -= V_4 -> V_440 . V_556 ;
V_4 -> V_440 . V_559 += V_558 ;
}
V_68:
return;
}
void F_300 ( struct V_189 * V_118 , unsigned int V_525 ,
unsigned int V_110 , int V_560 , int V_162 ,
unsigned long V_549 )
{
struct V_3 * V_4 = (struct V_3 * ) V_549 ;
F_46 ( V_4 , 2 , L_241 , V_110 ) ;
F_46 ( V_4 , 2 , L_242 , V_525 ) ;
if ( F_58 ( V_4 , V_110 ) )
F_298 ( V_4 , V_525 , V_110 , V_560 , V_162 ) ;
else if ( V_525 )
F_66 ( V_4 ) ;
}
void F_301 ( struct V_189 * V_118 ,
unsigned int V_513 , int V_561 , int V_554 ,
int V_162 , unsigned long V_549 )
{
struct V_3 * V_4 = (struct V_3 * ) V_549 ;
struct V_90 * V_110 = V_4 -> V_43 . V_78 [ V_561 ] ;
struct V_95 * V_74 ;
int V_41 ;
F_3 ( V_4 , 6 , L_243 ) ;
if ( V_513 & V_562 ) {
F_3 ( V_4 , 2 , L_244 ) ;
F_293 ( V_4 -> V_6 ) ;
F_66 ( V_4 ) ;
return;
}
if ( V_4 -> V_57 . V_277 ) {
V_4 -> V_440 . V_563 ++ ;
V_4 -> V_440 . V_564 =
F_285 () ;
}
for ( V_41 = V_554 ; V_41 < ( V_554 + V_162 ) ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
V_74 = V_110 -> V_73 [ V_92 ] ;
F_286 ( V_4 , V_74 , V_513 ) ;
if ( V_110 -> V_79 &&
( V_110 -> V_79 [ V_92 ] . V_29 &
V_565 ) != 0 ) {
F_48 ( V_4 -> V_57 . V_58 != V_59 ) ;
if ( F_53 ( & V_74 -> V_52 ,
V_106 ,
V_108 ) ==
V_106 ) {
F_55 ( V_110 , V_74 ,
V_566 ) ;
}
V_74 -> V_101 = V_110 -> V_79 [ V_92 ] . V_101 ;
F_46 ( V_110 -> V_4 , 5 , L_245 , V_92 ) ;
F_3 ( V_110 -> V_4 , 5 , L_246 ) ;
F_46 ( V_110 -> V_4 , 5 , L_43 ,
F_302 ( V_74 -> V_101 ) ) ;
if ( F_50 ( V_110 , V_92 ) ) {
F_3 ( V_4 , 2 , L_247 ) ;
F_66 ( V_4 ) ;
}
} else {
if ( V_4 -> V_57 . V_58 == V_59 ) {
enum V_80 V_83 ;
V_83 = F_43 (
V_74 -> V_74 -> V_242 [ 15 ] . V_243 , 0 ) ;
F_55 ( V_110 , V_74 , V_83 ) ;
}
F_56 ( V_110 , V_74 ,
V_246 ) ;
}
F_44 ( V_110 , V_92 , 0 ) ;
}
F_303 ( V_162 , & V_110 -> V_448 ) ;
if ( V_4 -> V_9 . type != V_12 )
F_292 ( V_110 ) ;
F_299 ( V_110 -> V_4 -> V_6 ) ;
if ( V_4 -> V_57 . V_277 )
V_4 -> V_440 . V_567 += F_285 () -
V_4 -> V_440 . V_564 ;
}
int F_304 ( struct V_3 * V_4 , struct V_229 * V_230 ,
int V_568 , int V_569 )
{
if ( ! V_568 && ( V_4 -> V_9 . type == V_11 ||
V_4 -> V_9 . type == V_14 ) )
return V_4 -> V_43 . V_257 ;
switch ( V_4 -> V_43 . V_76 ) {
case 4 :
if ( V_569 && V_4 -> V_9 . V_321 )
return V_4 -> V_9 . V_321 &
( V_4 -> V_43 . V_76 - 1 ) ;
if ( V_4 -> V_43 . V_311 && ( V_568 == 4 ) ) {
const T_3 V_570 = F_305 ( V_230 ) -> V_570 ;
if ( V_4 -> V_43 . V_311 ==
V_571 ) {
if ( V_570 & V_572 )
return 3 ;
if ( V_570 & V_573 )
return 2 ;
if ( V_570 & V_574 )
return 1 ;
if ( V_570 & V_575 )
return 0 ;
}
if ( V_4 -> V_43 . V_311 ==
V_576 )
return 3 - ( V_570 >> 6 ) ;
} else if ( V_4 -> V_43 . V_311 && ( V_568 == 6 ) ) {
}
return V_4 -> V_43 . V_257 ;
case 1 :
default:
return V_4 -> V_43 . V_257 ;
}
}
int F_306 ( struct V_229 * V_230 )
{
int V_172 , V_250 , V_557 , V_48 = 0 ;
struct V_577 * V_578 ;
char * V_116 ;
for ( V_172 = 0 ; V_172 < F_307 ( V_230 ) -> V_579 ; V_172 ++ ) {
V_578 = & F_307 ( V_230 ) -> V_580 [ V_172 ] ;
V_116 = ( char * ) F_308 ( F_309 ( V_578 ) ) +
V_578 -> V_581 ;
V_250 = V_578 -> V_582 ;
V_557 = F_310 ( ( unsigned long ) V_116 + V_250 - 1 ) -
F_311 ( ( unsigned long ) V_116 ) ;
V_48 += V_557 ;
}
return V_48 ;
}
int F_312 ( struct V_3 * V_4 ,
struct V_229 * V_230 , int V_583 )
{
int V_584 = V_230 -> V_158 - V_230 -> V_585 ;
int V_586 = F_310 ( ( unsigned long ) V_230 -> V_116 + V_584 - 1 ) -
F_311 ( ( unsigned long ) V_230 -> V_116 ) ;
V_586 += F_306 ( V_230 ) ;
if ( ( V_586 + V_583 ) > F_28 ( V_4 ) ) {
F_62 ( 2 , L_248
L_249 ,
( V_586 + V_583 ) , V_230 -> V_158 ) ;
return 0 ;
}
return V_586 ;
}
int F_313 ( struct V_229 * V_230 , struct V_587 * * V_132 , int V_158 )
{
int V_588 , V_589 , V_590 ;
if ( ( ( unsigned long ) V_230 -> V_116 & V_591 ) !=
( ( ( unsigned long ) V_230 -> V_116 + V_158 - 1 ) & V_591 ) ) {
V_588 = F_314 ( V_230 ) ;
V_589 = V_407 - ( ( unsigned long ) V_230 -> V_116 % V_407 ) ;
V_590 = V_158 - V_589 ;
if ( V_590 > V_588 )
return 1 ;
memmove ( V_230 -> V_116 - V_590 , V_230 -> V_116 , V_230 -> V_158 - V_230 -> V_585 ) ;
V_230 -> V_116 -= V_590 ;
V_230 -> V_592 -= V_590 ;
* V_132 = (struct V_587 * ) V_230 -> V_116 ;
F_62 ( 2 , L_250 , V_158 , V_590 ) ;
}
return 0 ;
}
static inline void F_315 ( struct V_229 * V_230 ,
struct V_64 * V_74 , int V_593 , int * V_252 ,
int V_179 )
{
int V_250 = V_230 -> V_158 - V_230 -> V_585 ;
int V_594 ;
int V_242 ;
char * V_116 ;
int V_595 , V_172 ;
struct V_577 * V_578 ;
V_242 = * V_252 ;
V_116 = V_230 -> V_116 ;
V_595 = ( V_593 == 0 ? 1 : 0 ) ;
if ( V_179 >= 0 ) {
V_116 = V_230 -> V_116 + V_179 ;
V_250 -= V_179 ;
V_595 = 0 ;
}
while ( V_250 > 0 ) {
V_594 = V_407 - ( ( unsigned long ) V_116 % V_407 ) ;
if ( V_250 < V_594 )
V_594 = V_250 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_594 ;
V_250 -= V_594 ;
if ( ! V_250 ) {
if ( V_595 )
if ( F_307 ( V_230 ) -> V_579 )
V_74 -> V_242 [ V_242 ] . V_251 =
V_596 ;
else
V_74 -> V_242 [ V_242 ] . V_251 = 0 ;
else
V_74 -> V_242 [ V_242 ] . V_251 =
V_597 ;
} else {
if ( V_595 )
V_74 -> V_242 [ V_242 ] . V_251 =
V_596 ;
else
V_74 -> V_242 [ V_242 ] . V_251 =
V_597 ;
}
V_116 += V_594 ;
V_242 ++ ;
V_595 = 0 ;
}
for ( V_172 = 0 ; V_172 < F_307 ( V_230 ) -> V_579 ; V_172 ++ ) {
V_578 = & F_307 ( V_230 ) -> V_580 [ V_172 ] ;
V_116 = ( char * ) F_308 ( F_309 ( V_578 ) ) +
V_578 -> V_581 ;
V_250 = V_578 -> V_582 ;
while ( V_250 > 0 ) {
V_594 = V_407 -
( ( unsigned long ) V_116 % V_407 ) ;
if ( V_250 < V_594 )
V_594 = V_250 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_594 ;
V_74 -> V_242 [ V_242 ] . V_251 =
V_597 ;
V_250 -= V_594 ;
V_116 += V_594 ;
V_242 ++ ;
}
}
if ( V_74 -> V_242 [ V_242 - 1 ] . V_251 )
V_74 -> V_242 [ V_242 - 1 ] . V_251 = V_598 ;
* V_252 = V_242 ;
}
static inline int F_316 ( struct V_90 * V_110 ,
struct V_95 * V_228 , struct V_229 * V_230 ,
struct V_587 * V_132 , int V_179 , int V_599 )
{
struct V_64 * V_74 ;
int V_545 = 0 , V_600 , V_601 = 0 ;
V_74 = V_228 -> V_74 ;
F_70 ( & V_230 -> V_239 ) ;
F_317 ( & V_228 -> V_231 , V_230 ) ;
if ( V_132 -> V_132 . V_602 . V_316 == V_603 ) {
int V_242 = V_228 -> V_252 ;
V_600 = sizeof( struct V_604 ) +
( (struct V_604 * ) V_132 ) -> V_489 . V_605 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_230 -> V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_600 ;
V_74 -> V_242 [ V_242 ] . V_251 = V_596 ;
V_228 -> V_252 ++ ;
V_230 -> V_116 += V_600 ;
V_230 -> V_158 -= V_600 ;
V_601 = 1 ;
}
if ( V_179 >= 0 ) {
int V_242 = V_228 -> V_252 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_132 ;
V_74 -> V_242 [ V_242 ] . V_250 = sizeof( struct V_587 ) +
V_599 ;
V_74 -> V_242 [ V_242 ] . V_251 = V_596 ;
V_228 -> V_248 [ V_242 ] = 1 ;
V_228 -> V_252 ++ ;
}
F_315 ( V_230 , V_74 , V_601 ,
( int * ) & V_228 -> V_252 , V_179 ) ;
if ( ! V_110 -> V_447 ) {
F_3 ( V_110 -> V_4 , 6 , L_251 ) ;
F_54 ( & V_228 -> V_52 , V_106 ) ;
V_545 = 1 ;
} else {
F_3 ( V_110 -> V_4 , 6 , L_252 ) ;
if ( V_110 -> V_4 -> V_57 . V_277 )
V_110 -> V_4 -> V_440 . V_606 ++ ;
if ( V_228 -> V_252 >=
F_28 ( V_110 -> V_4 ) ) {
F_54 ( & V_228 -> V_52 , V_106 ) ;
V_545 = 1 ;
}
}
return V_545 ;
}
int F_318 ( struct V_3 * V_4 ,
struct V_90 * V_110 , struct V_229 * V_230 ,
struct V_587 * V_132 , int V_586 ,
int V_179 , int V_599 )
{
struct V_95 * V_74 ;
int V_164 ;
while ( F_53 ( & V_110 -> V_52 , V_449 ,
V_607 ) != V_449 ) ;
V_164 = V_110 -> V_446 ;
V_74 = V_110 -> V_73 [ V_110 -> V_446 ] ;
if ( F_45 ( & V_74 -> V_52 ) != V_246 )
goto V_68;
V_110 -> V_446 = ( V_110 -> V_446 + 1 ) %
V_63 ;
F_54 ( & V_110 -> V_52 , V_449 ) ;
F_316 ( V_110 , V_74 , V_230 , V_132 , V_179 , V_599 ) ;
F_290 ( V_110 , V_164 , 1 ) ;
return 0 ;
V_68:
F_54 ( & V_110 -> V_52 , V_449 ) ;
return - V_608 ;
}
int F_319 ( struct V_3 * V_4 , struct V_90 * V_110 ,
struct V_229 * V_230 , struct V_587 * V_132 ,
int V_586 )
{
struct V_95 * V_74 ;
int V_609 ;
int V_531 = 0 ;
int V_447 = 0 ;
int V_38 ;
int V_34 = 0 ;
while ( F_53 ( & V_110 -> V_52 , V_449 ,
V_607 ) != V_449 ) ;
V_609 = V_110 -> V_446 ;
V_74 = V_110 -> V_73 [ V_110 -> V_446 ] ;
if ( F_45 ( & V_74 -> V_52 ) != V_246 ) {
F_54 ( & V_110 -> V_52 , V_449 ) ;
return - V_608 ;
}
F_287 ( V_110 ) ;
if ( V_110 -> V_447 ) {
V_447 = 1 ;
if ( ( F_28 ( V_4 ) -
V_74 -> V_252 ) < V_586 ) {
F_54 ( & V_74 -> V_52 , V_106 ) ;
V_531 ++ ;
V_110 -> V_446 =
( V_110 -> V_446 + 1 ) %
V_63 ;
V_74 = V_110 -> V_73 [ V_110 -> V_446 ] ;
if ( F_45 ( & V_74 -> V_52 ) !=
V_246 ) {
F_290 ( V_110 , V_609 ,
V_531 ) ;
F_54 ( & V_110 -> V_52 ,
V_449 ) ;
return - V_608 ;
}
}
}
V_38 = F_316 ( V_110 , V_74 , V_230 , V_132 , - 1 , 0 ) ;
V_110 -> V_446 = ( V_110 -> V_446 + V_38 ) %
V_63 ;
V_531 += V_38 ;
if ( V_531 )
F_290 ( V_110 , V_609 , V_531 ) ;
else if ( ! F_45 ( & V_110 -> V_245 ) )
F_124 ( & V_110 -> V_52 , V_547 ) ;
while ( F_320 ( & V_110 -> V_52 ) ) {
V_531 = 0 ;
V_609 = V_110 -> V_446 ;
V_531 += F_288 ( V_110 ) ;
if ( ! V_531 && ! F_45 ( & V_110 -> V_245 ) )
V_531 += F_289 ( V_110 ) ;
if ( V_531 )
F_290 ( V_110 , V_609 , V_531 ) ;
}
if ( V_110 -> V_4 -> V_57 . V_277 && V_447 )
V_110 -> V_4 -> V_440 . V_548 += V_531 ;
return V_34 ;
}
static int F_321 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_478 * V_610 ;
F_3 ( V_4 , 4 , L_253 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_610 = & ( V_129 -> V_116 . V_465 ) ;
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
if ( V_129 -> V_132 . V_138 ) {
F_46 ( V_4 , 4 , L_254 , V_129 -> V_132 . V_138 ) ;
V_610 -> V_116 . V_611 = V_612 ;
}
V_4 -> V_9 . V_613 = V_610 -> V_116 . V_611 ;
return 0 ;
}
void F_322 ( struct V_3 * V_4 )
{
enum V_614 V_611 ;
struct V_615 * V_6 = V_4 -> V_6 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_255 ) ;
if ( ( ( V_6 -> V_29 & V_616 ) &&
( V_4 -> V_9 . V_613 == V_617 ) ) ||
( ! ( V_6 -> V_29 & V_616 ) &&
( V_4 -> V_9 . V_613 == V_612 ) ) )
return;
V_611 = V_612 ;
if ( V_6 -> V_29 & V_616 )
V_611 = V_617 ;
F_46 ( V_4 , 4 , L_256 , V_611 ) ;
V_112 = F_268 ( V_4 , V_618 ,
sizeof( struct V_478 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_129 -> V_116 . V_465 . V_116 . V_611 = V_611 ;
F_264 ( V_4 , V_112 , F_321 , NULL ) ;
}
int F_323 ( struct V_615 * V_6 , int V_619 )
{
struct V_3 * V_4 ;
char V_434 [ 15 ] ;
V_4 = V_6 -> V_620 ;
F_3 ( V_4 , 4 , L_257 ) ;
sprintf ( V_434 , L_258 , V_619 ) ;
F_3 ( V_4 , 4 , V_434 ) ;
if ( V_619 < 64 )
return - V_405 ;
if ( V_619 > 65535 )
return - V_405 ;
if ( ( ! F_324 ( V_4 , V_621 ) ) &&
( ! F_203 ( V_4 , V_619 ) ) )
return - V_405 ;
V_6 -> V_403 = V_619 ;
return 0 ;
}
struct V_622 * F_325 ( struct V_615 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_620 ;
F_3 ( V_4 , 5 , L_259 ) ;
return & V_4 -> V_515 ;
}
static int F_326 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_260 ) ;
V_129 = (struct V_128 * ) V_116 ;
if ( ! V_4 -> V_57 . V_309 ||
! ( V_4 -> V_9 . V_623 & V_624 ) ) {
memcpy ( V_4 -> V_6 -> V_625 ,
& V_129 -> V_116 . V_465 . V_116 . V_626 . V_247 ,
V_627 ) ;
V_4 -> V_9 . V_623 |= V_624 ;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
int F_327 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_261 ) ;
V_112 = F_268 ( V_4 , V_628 ,
sizeof( struct V_478 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_129 -> V_116 . V_465 . V_116 . V_626 . V_129 = V_629 ;
V_129 -> V_116 . V_465 . V_116 . V_626 . V_630 = V_627 ;
memcpy ( & V_129 -> V_116 . V_465 . V_116 . V_626 . V_247 ,
V_4 -> V_6 -> V_625 , V_627 ) ;
V_34 = F_264 ( V_4 , V_112 , F_326 ,
NULL ) ;
return V_34 ;
}
static int F_328 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_631 * V_632 ;
int V_633 = * ( int * ) V_124 -> V_386 ;
F_3 ( V_4 , 4 , L_262 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_632 = & V_129 -> V_116 . V_465 . V_116 . V_634 ;
F_38 ( V_60 , 2 , L_262 ) ;
F_38 ( V_60 , 2 , L_191 , V_4 -> V_7 -> V_6 . V_635 . V_504 ) ;
F_38 ( V_60 , 2 , L_263 ,
V_129 -> V_116 . V_465 . V_132 . V_138 ) ;
if ( V_129 -> V_116 . V_465 . V_132 . V_138 !=
V_636 )
F_62 ( 3 , L_264 ,
V_4 -> V_7 -> V_6 . V_635 . V_504 ,
V_632 -> V_637 ,
V_129 -> V_116 . V_465 . V_132 . V_138 ) ;
switch ( V_129 -> V_116 . V_465 . V_132 . V_138 ) {
case V_636 :
if ( V_4 -> V_57 . V_280 == V_281 ) {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_265 ) ;
} else {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_266 ) ;
}
break;
case V_638 :
F_62 ( 2 , L_267
L_268 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_640 :
F_62 ( 2 , L_269
L_270 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_641 :
F_41 ( & V_4 -> V_7 -> V_6 , L_271
L_272 ) ;
break;
case V_642 :
F_41 ( & V_4 -> V_7 -> V_6 ,
L_273
L_274 ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_643 :
F_41 ( & V_4 -> V_7 -> V_6 ,
L_275 ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_644 :
F_41 ( & V_4 -> V_7 -> V_6 , L_276
L_277 ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_645 :
F_41 ( & V_4 -> V_7 -> V_6 , L_278
L_279 ) ;
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
case V_646 :
F_61 ( & V_4 -> V_7 -> V_6 , L_280
L_281 ) ;
break;
default:
if ( V_633 )
V_4 -> V_57 . V_280 = V_4 -> V_57 . V_639 ;
break;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
static int F_329 ( struct V_3 * V_4 ,
enum V_647 V_280 , int V_633 )
{
int V_34 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_631 * V_632 ;
F_3 ( V_4 , 4 , L_282 ) ;
F_38 ( V_60 , 2 , L_282 ) ;
F_38 ( V_60 , 2 , L_191 , V_4 -> V_7 -> V_6 . V_635 . V_504 ) ;
V_112 = F_268 ( V_4 , V_648 ,
sizeof( struct V_649 ) +
sizeof( struct V_631 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_632 = & V_129 -> V_116 . V_465 . V_116 . V_634 ;
V_632 -> V_637 = V_280 ;
V_34 = F_264 ( V_4 , V_112 , F_328 ,
& V_633 ) ;
F_38 ( V_60 , 2 , L_263 , V_34 ) ;
return V_34 ;
}
int F_330 ( struct V_3 * V_4 , int V_633 )
{
int V_34 = 0 ;
F_3 ( V_4 , 4 , L_283 ) ;
if ( ( V_4 -> V_9 . type == V_11 ||
V_4 -> V_9 . type == V_14 ) &&
F_331 ( V_4 , V_648 ) ) {
V_34 = F_329 ( V_4 ,
V_4 -> V_57 . V_280 , V_633 ) ;
if ( V_34 ) {
F_62 ( 3 ,
L_284 ,
V_4 -> V_7 -> V_6 . V_635 . V_504 ,
V_34 ) ;
V_34 = - V_342 ;
}
} else if ( V_4 -> V_57 . V_280 != V_281 ) {
V_4 -> V_57 . V_280 = V_281 ;
F_41 ( & V_4 -> V_7 -> V_6 , L_271
L_272 ) ;
V_34 = - V_342 ;
}
return V_34 ;
}
void F_332 ( struct V_615 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_620 ;
F_3 ( V_4 , 4 , L_285 ) ;
V_4 -> V_515 . V_542 ++ ;
F_66 ( V_4 ) ;
}
int F_333 ( struct V_615 * V_6 , int V_650 , int V_651 )
{
struct V_3 * V_4 = V_6 -> V_620 ;
int V_34 = 0 ;
switch ( V_651 ) {
case V_652 :
V_34 = V_653 ;
if ( ( V_4 -> V_9 . V_16 != V_19 ) &&
( V_4 -> V_9 . V_16 != V_654 ) &&
( V_4 -> V_9 . V_16 != V_20 ) )
V_34 |= V_655 ;
break;
case V_656 :
V_34 = V_657 | V_658 | V_659 |
V_660 | V_661 | V_662 | V_663 |
V_664 ;
break;
case V_665 :
V_34 = ( V_6 -> V_625 [ 0 ] << 16 ) | ( V_6 -> V_625 [ 1 ] << 8 ) |
V_6 -> V_625 [ 2 ] ;
V_34 = ( V_34 >> 5 ) & 0xFFFF ;
break;
case V_666 :
V_34 = ( V_6 -> V_625 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_667 :
V_34 = V_668 ;
break;
case V_669 :
V_34 = V_670 | V_671 | V_672 | V_673 |
V_674 | V_675 ;
break;
case V_676 :
break;
case V_677 :
break;
case V_678 :
break;
case V_679 :
break;
case V_680 :
V_34 = V_4 -> V_515 . V_681 ;
break;
case V_682 :
break;
case V_683 :
break;
case V_684 :
break;
case V_685 :
break;
case V_686 :
break;
case V_687 :
break;
case V_688 :
break;
default:
break;
}
return V_34 ;
}
static int F_334 ( struct V_3 * V_4 ,
struct V_111 * V_112 , int V_158 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_383 )
{
V_181 V_689 , V_690 ;
F_3 ( V_4 , 4 , L_286 ) ;
memcpy ( V_112 -> V_116 , V_463 , V_390 ) ;
memcpy ( F_263 ( V_112 -> V_116 ) ,
& V_4 -> V_356 . V_416 , V_372 ) ;
V_689 = ( V_691 ) V_390 + V_158 ;
V_690 = ( V_691 ) V_158 ;
memcpy ( F_335 ( V_112 -> V_116 ) , & V_689 , 2 ) ;
memcpy ( F_336 ( V_112 -> V_116 ) , & V_690 , 2 ) ;
memcpy ( F_337 ( V_112 -> V_116 ) , & V_690 , 2 ) ;
memcpy ( F_338 ( V_112 -> V_116 ) , & V_690 , 2 ) ;
return F_185 ( V_4 , V_390 + V_158 , V_112 ,
F_186 , V_383 ) ;
}
static int F_339 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_692 )
{
struct V_128 * V_129 ;
struct V_693 * V_694 ;
struct V_695 * V_696 ;
unsigned char * V_116 ;
V_180 V_585 ;
F_3 ( V_4 , 3 , L_287 ) ;
V_129 = (struct V_128 * ) V_692 ;
V_116 = ( unsigned char * ) ( ( char * ) V_129 - V_124 -> V_179 ) ;
V_694 = (struct V_693 * ) V_124 -> V_386 ;
V_696 = & V_129 -> V_116 . V_465 . V_116 . V_696 ;
if ( V_129 -> V_132 . V_138 ) {
F_46 ( V_4 , 4 , L_288 , V_129 -> V_132 . V_138 ) ;
return 0 ;
}
if ( V_129 -> V_116 . V_465 . V_132 . V_138 ) {
V_129 -> V_132 . V_138 =
V_129 -> V_116 . V_465 . V_132 . V_138 ;
F_46 ( V_4 , 4 , L_289 , V_129 -> V_132 . V_138 ) ;
return 0 ;
}
V_585 = * ( ( V_180 * ) F_336 ( V_116 ) ) ;
if ( V_129 -> V_116 . V_465 . V_132 . V_476 == 1 )
V_585 -= ( V_180 ) ( ( char * ) & V_696 -> V_116 - ( char * ) V_129 ) ;
else
V_585 -= ( V_180 ) ( ( char * ) & V_696 -> V_697 - ( char * ) V_129 ) ;
if ( ( V_694 -> V_698 - V_694 -> V_699 ) < V_585 ) {
F_46 ( V_4 , 4 , L_290 , - V_47 ) ;
V_129 -> V_132 . V_138 = V_700 ;
return 0 ;
}
F_46 ( V_4 , 4 , L_291 ,
V_129 -> V_116 . V_465 . V_132 . V_475 ) ;
F_46 ( V_4 , 4 , L_292 ,
V_129 -> V_116 . V_465 . V_132 . V_476 ) ;
if ( V_129 -> V_116 . V_465 . V_132 . V_476 == 1 ) {
memcpy ( V_694 -> V_701 + V_694 -> V_699 ,
( char * ) V_696 ,
V_585 + F_340 ( struct V_695 , V_116 ) ) ;
V_694 -> V_699 += F_340 ( struct V_695 , V_116 ) ;
} else {
memcpy ( V_694 -> V_701 + V_694 -> V_699 ,
( char * ) & V_696 -> V_697 , V_585 ) ;
}
V_694 -> V_699 += V_585 ;
F_46 ( V_4 , 4 , L_293 ,
V_129 -> V_116 . V_465 . V_132 . V_475 ) ;
F_46 ( V_4 , 4 , L_294 ,
V_129 -> V_116 . V_465 . V_132 . V_476 ) ;
if ( V_129 -> V_116 . V_465 . V_132 . V_476 <
V_129 -> V_116 . V_465 . V_132 . V_475 )
return 1 ;
return 0 ;
}
int F_341 ( struct V_3 * V_4 , char T_4 * V_701 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_702 * V_703 ;
unsigned int V_704 ;
struct V_693 V_694 = { 0 , } ;
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_295 ) ;
if ( V_4 -> V_9 . V_10 )
return - V_342 ;
if ( ( ! F_331 ( V_4 , V_705 ) ) &&
( ! V_4 -> V_57 . V_309 ) ) {
return - V_342 ;
}
if ( F_342 ( & V_704 , V_701 + sizeof( int ) , sizeof( int ) ) )
return - V_706 ;
if ( V_704 > ( V_117 - V_390 -
sizeof( struct V_707 ) -
sizeof( struct V_649 ) ) )
return - V_405 ;
V_703 = F_343 ( V_701 , V_704 + sizeof( struct V_708 ) ) ;
if ( F_109 ( V_703 ) ) {
F_3 ( V_4 , 2 , L_296 ) ;
return F_110 ( V_703 ) ;
}
V_694 . V_698 = V_703 -> V_132 . V_585 ;
V_694 . V_701 = F_26 ( V_694 . V_698 , V_46 ) ;
if ( ! V_694 . V_701 ) {
F_31 ( V_703 ) ;
return - V_47 ;
}
V_694 . V_699 = sizeof( struct V_708 ) ;
V_112 = F_268 ( V_4 , V_705 ,
V_709 + V_704 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
memcpy ( & V_129 -> V_116 . V_465 . V_116 . V_696 , & V_703 -> V_129 , V_704 ) ;
V_34 = F_334 ( V_4 , V_112 , V_710 + V_704 ,
F_339 , ( void * ) & V_694 ) ;
if ( V_34 )
F_62 ( 2 , L_297 ,
F_75 ( V_4 ) , V_34 ) ;
else {
if ( F_344 ( V_701 , V_694 . V_701 , V_694 . V_698 ) )
V_34 = - V_706 ;
}
F_31 ( V_703 ) ;
F_31 ( V_694 . V_701 ) ;
return V_34 ;
}
static int F_345 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_711 * V_712 ;
char * V_713 ;
int V_714 ;
F_3 ( V_4 , 3 , L_298 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_712 = (struct V_711 * ) V_124 -> V_386 ;
V_714 = V_129 -> V_116 . V_465 . V_132 . V_473 ;
V_713 = ( char * ) V_116 + 28 ;
if ( V_714 > ( V_712 -> V_715 - V_712 -> V_716 ) ) {
V_129 -> V_132 . V_138 = V_717 ;
return 0 ;
}
memcpy ( ( V_712 -> V_74 + V_712 -> V_716 ) , V_713 ,
V_714 ) ;
V_712 -> V_716 += V_714 ;
if ( V_129 -> V_116 . V_465 . V_132 . V_476 <
V_129 -> V_116 . V_465 . V_132 . V_475 )
return 1 ;
return 0 ;
}
int F_346 ( struct V_3 * V_4 , char T_4 * V_701 )
{
int V_34 = 0 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_718 * V_719 ;
struct V_720 V_721 ;
struct V_711 V_712 ;
void T_4 * V_38 ;
F_3 ( V_4 , 3 , L_299 ) ;
if ( ! F_331 ( V_4 , V_722 ) ) {
V_34 = - V_342 ;
goto V_68;
}
if ( F_342 ( & V_721 , V_701 ,
sizeof( struct V_720 ) ) ) {
V_34 = - V_706 ;
goto V_68;
}
V_712 . V_715 = V_721 . V_715 ;
V_712 . V_716 = 0 ;
V_712 . V_74 = F_26 ( V_721 . V_715 , V_46 ) ;
if ( ! V_712 . V_74 ) {
V_34 = - V_47 ;
goto V_68;
}
V_112 = F_268 ( V_4 , V_722 ,
sizeof( struct V_649 ) +
sizeof( struct V_718 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_390 ) ;
V_719 = & V_129 -> V_116 . V_465 . V_116 . V_723 ;
V_719 -> V_637 = V_721 . V_133 ;
V_34 = F_264 ( V_4 , V_112 , F_345 ,
& V_712 ) ;
if ( ! V_34 ) {
if ( F_347 () )
V_38 = F_348 ( V_721 . V_40 ) ;
else
V_38 = ( void T_4 * ) ( unsigned long ) V_721 . V_40 ;
if ( F_344 ( V_38 , V_712 . V_74 ,
V_712 . V_716 ) ) {
V_34 = - V_706 ;
goto V_724;
}
V_721 . V_716 = V_712 . V_716 ;
if ( F_344 ( V_701 , & V_721 ,
sizeof( struct V_720 ) ) )
V_34 = - V_706 ;
} else
if ( V_34 == V_717 )
V_34 = - V_706 ;
V_724:
F_31 ( V_712 . V_74 ) ;
V_68:
return V_34 ;
}
int F_349 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_725 * V_726 ;
struct V_727 * V_727 ;
F_3 ( V_4 , 2 , L_300 ) ;
V_727 = (struct V_727 * ) V_124 -> V_386 ;
V_129 = (struct V_128 * ) V_116 ;
V_726 = & V_129 -> V_116 . V_465 . V_116 . V_726 ;
if ( V_129 -> V_116 . V_465 . V_132 . V_138 == 0 ) {
V_727 -> V_728 = V_726 -> V_728 ;
V_727 -> V_729 = V_726 -> V_729 ;
V_727 -> V_730 = V_726 -> V_730 ;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
int V_725 ( struct V_3 * V_4 ,
struct V_727 * V_727 )
{
struct V_111 * V_112 ;
F_3 ( V_4 , 2 , L_301 ) ;
if ( ! F_331 ( V_4 , V_731 ) )
return - V_342 ;
V_112 = F_268 ( V_4 , V_731 ,
sizeof( struct V_649 ) ) ;
return F_264 ( V_4 , V_112 , F_349 ,
( void * ) V_727 ) ;
}
static inline int F_350 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_12 :
return 2 ;
default:
return 0 ;
}
}
static void F_351 ( struct V_3 * V_4 )
{
int V_34 ;
int V_250 ;
char * V_348 ;
struct V_189 * V_732 ;
int V_733 = 0 ;
F_35 ( V_60 , 2 , L_302 ) ;
V_732 = F_37 ( V_4 ) ;
if ( ! V_732 -> V_734 ) {
V_733 = 1 ;
V_34 = F_352 ( V_732 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_68;
}
}
V_34 = F_159 ( V_4 , ( void * * ) & V_348 , & V_250 ) ;
if ( V_34 ) {
F_62 ( 2 , L_303 ,
F_63 ( & V_4 -> V_7 -> V_6 ) , V_34 ) ;
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_735;
}
F_162 ( V_4 , V_348 ) ;
if ( V_733 )
F_163 ( V_4 , V_348 ) ;
F_31 ( V_348 ) ;
V_34 = F_353 ( V_732 , & V_4 -> V_736 ) ;
if ( V_34 )
F_38 ( V_60 , 2 , L_188 , V_34 ) ;
F_38 ( V_60 , 2 , L_304 , V_4 -> V_736 . V_737 ) ;
F_38 ( V_60 , 2 , L_305 , V_4 -> V_736 . V_738 ) ;
F_38 ( V_60 , 2 , L_305 , V_4 -> V_736 . V_739 ) ;
F_38 ( V_60 , 2 , L_306 , V_4 -> V_736 . V_740 ) ;
if ( ! ( ( V_4 -> V_736 . V_737 != V_741 ) ||
( ( V_4 -> V_736 . V_738 & V_742 ) == 0 ) ||
( ( V_4 -> V_736 . V_739 & V_743 ) == 0 ) ) ) {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_307 ) ;
} else {
V_4 -> V_57 . V_58 = V_553 ;
}
V_735:
if ( V_733 == 1 )
F_354 ( V_732 ) ;
V_68:
return;
}
static inline void F_355 ( struct V_3 * V_4 ,
struct V_64 * * V_744 ,
void (* * F_356) ( struct V_189 * , int , unsigned long ) ) {
int V_41 ;
if ( V_4 -> V_57 . V_58 == V_59 ) {
int V_179 = V_63 *
( V_4 -> V_43 . V_67 - 1 ) ;
V_41 = V_63 * ( V_4 -> V_43 . V_67 - 1 ) ;
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_744 [ V_179 + V_41 ] = (struct V_64 * )
F_302 ( V_4 -> V_43 . V_61 -> V_73 [ V_41 ] . V_74 ) ;
}
F_356 [ V_4 -> V_43 . V_67 - 1 ] = NULL ;
}
}
static int F_239 ( struct V_3 * V_4 )
{
struct V_745 V_746 ;
char * V_747 ;
struct V_64 * * V_744 ;
void (* * F_356) ( struct V_189 * , int , unsigned long );
struct V_64 * * V_748 ;
int V_41 , V_42 , V_749 ;
int V_34 = 0 ;
F_35 ( V_60 , 2 , L_308 ) ;
V_747 = F_26 ( V_63 * sizeof( char ) ,
V_46 ) ;
if ( ! V_747 ) {
V_34 = - V_47 ;
goto V_750;
}
F_228 ( V_4 , V_747 ) ;
F_232 ( V_4 , V_747 ) ;
V_744 = F_26 ( V_4 -> V_43 . V_67 *
V_63 * sizeof( void * ) ,
V_46 ) ;
if ( ! V_744 ) {
V_34 = - V_47 ;
goto V_751;
}
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_744 [ V_41 ] = (struct V_64 * )
F_302 ( V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_74 ) ;
}
F_356 = F_26 ( sizeof( void * ) * V_4 -> V_43 . V_67 ,
V_46 ) ;
if ( ! F_356 ) {
V_34 = - V_47 ;
goto V_752;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_67 ; ++ V_41 )
F_356 [ V_41 ] = V_4 -> V_147 -> V_753 ;
F_355 ( V_4 , V_744 , F_356 ) ;
V_748 =
F_26 ( V_4 -> V_43 . V_76 * V_63 *
sizeof( void * ) , V_46 ) ;
if ( ! V_748 ) {
V_34 = - V_47 ;
goto V_754;
}
for ( V_41 = 0 , V_749 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 )
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 , ++ V_749 ) {
V_748 [ V_749 ] = (struct V_64 * ) F_302 (
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] -> V_74 ) ;
}
memset ( & V_746 , 0 , sizeof( struct V_745 ) ) ;
V_746 . V_190 = F_37 ( V_4 ) ;
V_746 . V_755 = F_350 ( V_4 ) ;
V_746 . V_756 = 0 ;
V_746 . V_747 = V_747 ;
V_746 . V_757 = V_4 -> V_43 . V_67 ;
V_746 . V_758 = V_4 -> V_43 . V_76 ;
V_746 . V_759 = V_4 -> V_147 -> V_759 ;
V_746 . V_760 = V_4 -> V_147 -> V_760 ;
V_746 . V_761 = F_356 ;
V_746 . V_762 = ( unsigned long ) V_4 ;
V_746 . V_763 = ( void * * ) V_744 ;
V_746 . V_764 = ( void * * ) V_748 ;
V_746 . V_765 = V_4 -> V_43 . V_75 ;
V_746 . V_766 =
( V_4 -> V_9 . type == V_12 ) ? 1 : 32 ;
if ( F_53 ( & V_4 -> V_43 . V_52 , V_337 ,
V_333 ) == V_337 ) {
V_34 = F_357 ( & V_746 ) ;
if ( V_34 ) {
F_54 ( & V_4 -> V_43 . V_52 , V_337 ) ;
goto V_68;
}
V_34 = F_358 ( & V_746 ) ;
if ( V_34 ) {
F_54 ( & V_4 -> V_43 . V_52 , V_337 ) ;
F_240 ( F_37 ( V_4 ) ) ;
}
}
switch ( V_4 -> V_57 . V_58 ) {
case V_59 :
F_83 ( & V_4 -> V_7 -> V_6 , L_309 ) ;
break;
case V_282 :
F_83 ( & V_4 -> V_7 -> V_6 , L_310 ) ;
break;
default:
break;
}
V_68:
F_31 ( V_748 ) ;
V_754:
F_31 ( F_356 ) ;
V_752:
F_31 ( V_744 ) ;
V_751:
F_31 ( V_747 ) ;
V_750:
return V_34 ;
}
static void F_359 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 2 , L_311 ) ;
F_40 ( V_60 , 2 , & V_4 , sizeof( void * ) ) ;
F_126 ( & V_4 -> V_113 ) ;
F_126 ( & V_4 -> V_153 ) ;
if ( V_4 -> V_6 )
F_360 ( V_4 -> V_6 ) ;
F_31 ( V_4 -> V_292 ) ;
F_123 ( V_4 ) ;
F_361 ( & V_4 -> V_303 ) ;
F_31 ( V_4 ) ;
}
void F_362 ( struct V_3 * V_4 )
{
F_3 ( V_4 , 2 , L_312 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_481 . V_469 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_481 . V_484 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_483 . V_469 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_483 . V_484 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_468 . V_469 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_468 . V_484 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_9 . V_487 ) ;
}
int F_363 ( struct V_3 * V_4 )
{
int V_767 = 3 ;
int V_34 ;
F_35 ( V_60 , 2 , L_314 ) ;
F_54 ( & V_4 -> V_520 , 0 ) ;
F_129 ( V_4 ) ;
V_768:
if ( V_767 < 3 )
F_62 ( 2 , L_315 ,
F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
V_34 = F_157 ( V_4 , V_4 -> V_9 . type != V_12 ) ;
F_354 ( F_37 ( V_4 ) ) ;
F_354 ( F_364 ( V_4 ) ) ;
F_354 ( F_147 ( V_4 ) ) ;
F_240 ( F_37 ( V_4 ) ) ;
V_34 = F_352 ( F_147 ( V_4 ) ) ;
if ( V_34 )
goto V_769;
V_34 = F_352 ( F_364 ( V_4 ) ) ;
if ( V_34 )
goto V_769;
V_34 = F_352 ( F_37 ( V_4 ) ) ;
if ( V_34 )
goto V_769;
V_769:
if ( V_34 == - V_326 ) {
F_35 ( V_60 , 2 , L_316 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
if ( -- V_767 < 0 )
goto V_68;
else
goto V_768;
}
F_351 ( V_4 ) ;
F_164 ( V_4 ) ;
F_165 ( V_4 ) ;
V_34 = F_168 ( & V_4 -> V_113 , F_180 ) ;
if ( V_34 == - V_326 ) {
F_35 ( V_60 , 2 , L_317 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
if ( -- V_767 < 0 )
goto V_68;
else
goto V_768;
}
V_34 = F_168 ( & V_4 -> V_153 , F_177 ) ;
if ( V_34 == - V_326 ) {
F_35 ( V_60 , 2 , L_318 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_186 , V_34 ) ;
if ( -- V_767 < 0 )
goto V_68;
else
goto V_768;
}
V_4 -> V_122 = 0 ;
V_34 = F_238 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_68;
}
V_4 -> V_57 . V_481 . V_469 = 0 ;
V_4 -> V_57 . V_468 . V_469 = 0 ;
V_4 -> V_57 . V_770 . V_469 = 0 ;
V_4 -> V_9 . V_487 = 0 ;
F_271 ( V_4 , V_393 ) ;
if ( F_324 ( V_4 , V_482 ) )
F_269 ( V_4 ) ;
if ( F_331 ( V_4 , V_771 ) )
F_273 ( V_4 ) ;
return 0 ;
V_68:
F_61 ( & V_4 -> V_7 -> V_6 , L_106
L_107 ) ;
F_62 ( 2 , L_319 ,
F_63 ( & V_4 -> V_7 -> V_6 ) , V_34 ) ;
return V_34 ;
}
static inline int F_365 ( struct V_442 * V_772 ,
struct V_773 * V_242 ,
struct V_229 * * V_774 , int V_179 , int * V_775 , int V_585 )
{
struct V_438 * V_438 = F_252 ( V_242 -> V_247 ) ;
if ( * V_774 == NULL ) {
if ( V_772 -> V_256 ) {
* V_774 = V_772 -> V_256 ;
V_772 -> V_256 = NULL ;
} else {
* V_774 = F_256 ( V_443 + V_444 ) ;
if ( ! ( * V_774 ) )
return - V_47 ;
}
F_366 ( * V_774 , V_444 ) ;
if ( V_585 <= V_443 ) {
memcpy ( F_367 ( * V_774 , V_585 ) , V_242 -> V_247 + V_179 ,
V_585 ) ;
} else {
F_368 ( V_438 ) ;
memcpy ( F_367 ( * V_774 , V_443 ) ,
V_242 -> V_247 + V_179 , V_443 ) ;
F_369 ( * V_774 , * V_775 , V_438 ,
V_179 + V_443 ,
V_585 - V_443 ) ;
( * V_774 ) -> V_585 += V_585 - V_443 ;
( * V_774 ) -> V_158 += V_585 - V_443 ;
( * V_774 ) -> V_776 += V_585 - V_443 ;
( * V_775 ) ++ ;
}
} else {
F_368 ( V_438 ) ;
F_369 ( * V_774 , * V_775 , V_438 , V_179 , V_585 ) ;
( * V_774 ) -> V_585 += V_585 ;
( * V_774 ) -> V_158 += V_585 ;
( * V_774 ) -> V_776 += V_585 ;
( * V_775 ) ++ ;
}
return 0 ;
}
struct V_229 * F_370 ( struct V_3 * V_4 ,
struct V_442 * V_772 ,
struct V_773 * * V_777 , int * V_778 ,
struct V_587 * * V_132 )
{
struct V_773 * V_242 = * V_777 ;
struct V_64 * V_74 = V_772 -> V_74 ;
int V_179 = * V_778 ;
struct V_229 * V_230 = NULL ;
int V_779 = 0 ;
void * V_780 ;
int V_585 ;
int V_781 = 0 ;
int V_782 = 0 ;
int V_578 = 0 ;
if ( V_242 -> V_250 < V_179 + sizeof( struct V_587 ) ) {
if ( F_371 ( V_242 ) )
return NULL ;
V_242 ++ ;
V_179 = 0 ;
if ( V_242 -> V_250 < sizeof( struct V_587 ) )
return NULL ;
}
* V_132 = V_242 -> V_247 + V_179 ;
V_179 += sizeof( struct V_587 ) ;
switch ( ( * V_132 ) -> V_132 . V_783 . V_316 ) {
case V_784 :
V_779 = ( * V_132 ) -> V_132 . V_783 . V_785 ;
break;
case V_786 :
V_779 = ( * V_132 ) -> V_132 . V_602 . V_250 ;
V_781 = V_444 ;
break;
case V_787 :
V_779 = ( * V_132 ) -> V_132 . V_788 . V_789 ;
V_781 = sizeof( struct V_587 ) ;
break;
default:
break;
}
if ( ! V_779 )
return NULL ;
if ( ( ( V_779 >= V_4 -> V_57 . V_278 ) &&
( ! ( V_4 -> V_9 . type == V_15 ) ) &&
( ! F_45 ( & V_4 -> V_520 ) ) ) ||
( V_4 -> V_57 . V_58 == V_59 ) ) {
V_782 = 1 ;
} else {
V_230 = F_256 ( V_779 + V_781 ) ;
if ( ! V_230 )
goto V_790;
if ( V_781 )
F_366 ( V_230 , V_781 ) ;
}
V_780 = V_242 -> V_247 + V_179 ;
while ( V_779 ) {
V_585 = F_207 ( V_779 , ( int ) ( V_242 -> V_250 - V_179 ) ) ;
if ( V_585 ) {
if ( V_782 ) {
if ( F_365 ( V_772 , V_242 ,
& V_230 , V_179 , & V_578 , V_585 ) )
goto V_790;
} else {
memcpy ( F_367 ( V_230 , V_585 ) , V_780 ,
V_585 ) ;
}
}
V_779 -= V_585 ;
if ( V_779 ) {
if ( F_371 ( V_242 ) ) {
F_3 ( V_4 , 4 , L_320 ) ;
F_372 ( V_4 , 2 , V_74 , sizeof( void * ) ) ;
F_120 ( V_230 ) ;
V_4 -> V_515 . V_681 ++ ;
return NULL ;
}
V_242 ++ ;
V_179 = 0 ;
V_780 = V_242 -> V_247 ;
} else {
V_179 += V_585 ;
}
}
* V_777 = V_242 ;
* V_778 = V_179 ;
if ( V_782 && V_4 -> V_57 . V_277 ) {
V_4 -> V_440 . V_791 ++ ;
V_4 -> V_440 . V_792 += F_307 ( V_230 ) -> V_579 ;
}
return V_230 ;
V_790:
if ( F_373 () ) {
F_3 ( V_4 , 2 , L_321 ) ;
}
V_4 -> V_515 . V_516 ++ ;
return NULL ;
}
static void F_374 ( void )
{
int V_793 ;
for ( V_793 = 0 ; V_793 < V_794 ; V_793 ++ ) {
F_375 ( V_795 [ V_793 ] . V_316 ) ;
V_795 [ V_793 ] . V_316 = NULL ;
}
}
void F_376 ( T_5 * V_316 , int V_375 , char * V_796 , ... )
{
char V_797 [ 32 ] ;
T_6 args ;
if ( ! F_377 ( V_316 , V_375 ) )
return;
va_start ( args , V_796 ) ;
vsnprintf ( V_797 , sizeof( V_797 ) , V_796 , args ) ;
va_end ( args ) ;
F_378 ( V_316 , V_375 , V_797 ) ;
}
static int F_379 ( void )
{
int V_340 ;
int V_793 ;
for ( V_793 = 0 ; V_793 < V_794 ; V_793 ++ ) {
V_795 [ V_793 ] . V_316 = F_380 ( V_795 [ V_793 ] . V_504 ,
V_795 [ V_793 ] . V_798 ,
V_795 [ V_793 ] . V_799 ,
V_795 [ V_793 ] . V_158 ) ;
if ( V_795 [ V_793 ] . V_316 == NULL ) {
F_374 () ;
return - V_47 ;
}
V_340 = F_381 ( V_795 [ V_793 ] . V_316 , V_795 [ V_793 ] . V_800 ) ;
if ( V_340 ) {
F_374 () ;
return V_340 ;
}
F_382 ( V_795 [ V_793 ] . V_316 , V_795 [ V_793 ] . V_375 ) ;
}
return 0 ;
}
int F_383 ( struct V_3 * V_4 ,
enum V_801 V_147 )
{
int V_34 = 0 ;
F_384 ( & V_802 ) ;
switch ( V_147 ) {
case V_803 :
V_4 -> V_147 = F_385 (
F_386 ( V_804 ) , L_322 ) ;
break;
case V_805 :
V_4 -> V_147 = F_385 (
F_386 ( V_806 ) , L_323 ) ;
break;
}
if ( ! V_4 -> V_147 ) {
F_41 ( & V_4 -> V_7 -> V_6 , L_324
L_325 , V_147 ) ;
V_34 = - V_405 ;
}
F_387 ( & V_802 ) ;
return V_34 ;
}
void F_388 ( struct V_3 * V_4 )
{
if ( V_4 -> V_57 . V_309 )
F_389 ( V_806 ) ;
else
F_389 ( V_804 ) ;
V_4 -> V_147 = NULL ;
}
static T_5 * F_390 ( char * V_504 )
{
struct V_807 * V_436 ;
T_5 * V_34 = NULL ;
F_384 ( & V_808 ) ;
F_245 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_436 -> V_809 , V_504 ) == 0 ) {
V_34 = V_436 -> V_810 ;
break;
}
}
F_387 ( & V_808 ) ;
return V_34 ;
}
static int F_391 ( struct V_3 * V_4 , char * V_504 )
{
struct V_807 * V_811 ;
V_4 -> V_812 = F_380 ( V_504 , 2 , 1 , 8 ) ;
if ( ! V_4 -> V_812 ) {
F_38 ( V_60 , 2 , L_191 , L_326 ) ;
goto V_813;
}
if ( F_381 ( V_4 -> V_812 , & V_814 ) )
goto V_815;
V_811 = F_26 ( sizeof( struct V_807 ) , V_46 ) ;
if ( ! V_811 )
goto V_815;
strncpy ( V_811 -> V_809 , V_504 , V_816 ) ;
V_811 -> V_810 = V_4 -> V_812 ;
F_384 ( & V_808 ) ;
F_32 ( & V_811 -> V_817 , & V_818 ) ;
F_387 ( & V_808 ) ;
return 0 ;
V_815:
F_375 ( V_4 -> V_812 ) ;
V_813:
return - V_47 ;
}
static void F_392 ( void )
{
struct V_807 * V_436 , * V_38 ;
F_384 ( & V_808 ) ;
F_23 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_24 ( & V_436 -> V_817 ) ;
F_375 ( V_436 -> V_810 ) ;
F_31 ( V_436 ) ;
}
F_387 ( & V_808 ) ;
}
static int F_393 ( struct V_819 * V_7 )
{
struct V_3 * V_4 ;
struct V_820 * V_6 ;
int V_34 ;
unsigned long V_29 ;
char V_809 [ V_816 ] ;
F_35 ( V_60 , 2 , L_327 ) ;
V_6 = & V_7 -> V_6 ;
if ( ! F_394 ( V_6 ) )
return - V_821 ;
F_38 ( V_60 , 2 , L_191 , F_63 ( & V_7 -> V_6 ) ) ;
V_4 = F_144 () ;
if ( ! V_4 ) {
F_38 ( V_60 , 2 , L_37 , - V_47 ) ;
V_34 = - V_47 ;
goto V_822;
}
snprintf ( V_809 , sizeof( V_809 ) , L_328 ,
F_63 ( & V_7 -> V_6 ) ) ;
V_4 -> V_812 = F_390 ( V_809 ) ;
if ( ! V_4 -> V_812 ) {
V_34 = F_391 ( V_4 , V_809 ) ;
if ( V_34 )
goto V_823;
}
V_4 -> V_113 . V_118 = V_7 -> V_190 [ 0 ] ;
V_4 -> V_153 . V_118 = V_7 -> V_190 [ 1 ] ;
V_4 -> V_116 . V_118 = V_7 -> V_190 [ 2 ] ;
F_395 ( & V_7 -> V_6 , V_4 ) ;
V_4 -> V_7 = V_7 ;
V_7 -> V_190 [ 0 ] -> V_824 = F_111 ;
V_7 -> V_190 [ 1 ] -> V_824 = F_111 ;
V_7 -> V_190 [ 2 ] -> V_824 = F_111 ;
V_34 = F_146 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_823;
}
V_34 = F_137 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_136 , V_34 ) ;
goto V_823;
}
if ( V_4 -> V_9 . type == V_15 )
V_7 -> V_6 . type = & V_825 ;
else
V_7 -> V_6 . type = & V_826 ;
switch ( V_4 -> V_9 . type ) {
case V_15 :
case V_13 :
V_34 = F_383 ( V_4 , V_805 ) ;
if ( V_34 )
goto V_823;
V_34 = V_4 -> V_147 -> V_827 ( V_4 -> V_7 ) ;
if ( V_34 )
goto V_828;
case V_11 :
case V_14 :
default:
break;
}
F_396 ( & V_829 . V_830 , V_29 ) ;
F_95 ( & V_4 -> V_39 , & V_829 . V_39 ) ;
F_397 ( & V_829 . V_830 , V_29 ) ;
F_351 ( V_4 ) ;
return 0 ;
V_828:
F_388 ( V_4 ) ;
V_823:
F_359 ( V_4 ) ;
V_822:
F_398 ( V_6 ) ;
return V_34 ;
}
static void F_399 ( struct V_819 * V_7 )
{
unsigned long V_29 ;
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
F_35 ( V_60 , 2 , L_329 ) ;
if ( V_4 -> V_147 ) {
V_4 -> V_147 -> remove ( V_7 ) ;
F_388 ( V_4 ) ;
}
F_396 ( & V_829 . V_830 , V_29 ) ;
F_24 ( & V_4 -> V_39 ) ;
F_397 ( & V_829 . V_830 , V_29 ) ;
F_359 ( V_4 ) ;
F_395 ( & V_7 -> V_6 , NULL ) ;
F_398 ( & V_7 -> V_6 ) ;
return;
}
static int F_401 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
int V_34 = 0 ;
int V_831 ;
if ( ! V_4 -> V_147 ) {
if ( V_4 -> V_9 . type == V_12 )
V_831 = V_803 ;
else
V_831 = V_805 ;
V_34 = F_383 ( V_4 , V_831 ) ;
if ( V_34 )
goto V_813;
V_34 = V_4 -> V_147 -> V_827 ( V_4 -> V_7 ) ;
if ( V_34 )
goto V_813;
}
V_34 = V_4 -> V_147 -> V_832 ( V_7 ) ;
V_813:
return V_34 ;
}
static int F_402 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
return V_4 -> V_147 -> V_833 ( V_7 ) ;
}
static void F_403 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_834 )
V_4 -> V_147 -> V_834 ( V_7 ) ;
}
static int F_404 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_835 )
return V_4 -> V_147 -> V_835 ( V_7 ) ;
return 0 ;
}
static void F_405 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_836 )
V_4 -> V_147 -> V_836 ( V_7 ) ;
}
static int F_406 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_837 )
return V_4 -> V_147 -> V_837 ( V_7 ) ;
return 0 ;
}
static int F_407 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_838 )
return V_4 -> V_147 -> V_838 ( V_7 ) ;
return 0 ;
}
static int F_408 ( struct V_819 * V_7 )
{
struct V_3 * V_4 = F_400 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_839 )
return V_4 -> V_147 -> V_839 ( V_7 ) ;
return 0 ;
}
static T_7 F_409 ( struct V_840 * V_841 ,
const char * V_228 , T_8 V_162 )
{
int V_813 ;
V_813 = F_410 ( V_842 ,
& V_843 , 3 , V_228 ) ;
return V_813 ? V_813 : V_162 ;
}
int F_411 ( struct V_615 * V_6 , int V_844 )
{
switch ( V_844 ) {
case V_845 :
return ( sizeof( V_846 ) / V_847 ) ;
default:
return - V_405 ;
}
}
void F_412 ( struct V_615 * V_6 ,
struct V_848 * V_515 , T_9 * V_116 )
{
struct V_3 * V_4 = V_6 -> V_620 ;
V_116 [ 0 ] = V_4 -> V_515 . V_849 -
V_4 -> V_440 . V_850 ;
V_116 [ 1 ] = V_4 -> V_440 . V_851 ;
V_116 [ 2 ] = V_4 -> V_515 . V_852 -
V_4 -> V_440 . V_853 ;
V_116 [ 3 ] = V_4 -> V_440 . V_544 ;
V_116 [ 4 ] = V_4 -> V_515 . V_852 - V_4 -> V_440 . V_853
- V_4 -> V_440 . V_606 ;
V_116 [ 5 ] = V_4 -> V_440 . V_544 - V_4 -> V_440 . V_548 ;
V_116 [ 6 ] = V_4 -> V_440 . V_606 ;
V_116 [ 7 ] = V_4 -> V_440 . V_548 ;
V_116 [ 8 ] = V_4 -> V_440 . V_854 ;
V_116 [ 9 ] = V_4 -> V_440 . V_855 ;
V_116 [ 10 ] = V_4 -> V_440 . V_791 ;
V_116 [ 11 ] = V_4 -> V_440 . V_792 ;
V_116 [ 12 ] = V_4 -> V_440 . V_441 ;
V_116 [ 13 ] = ( V_4 -> V_440 . V_856 >> 10 ) ;
V_116 [ 14 ] = V_4 -> V_440 . V_857 ;
V_116 [ 15 ] = V_4 -> V_440 . V_530 ;
V_116 [ 16 ] = V_4 -> V_440 . V_533 ;
V_116 [ 17 ] = V_532 ;
V_116 [ 18 ] = V_529 ;
V_116 [ 19 ] = F_45 ( & V_4 -> V_43 . V_78 [ 0 ] -> V_448 ) ;
V_116 [ 20 ] = ( V_4 -> V_43 . V_76 > 1 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 1 ] -> V_448 ) : 0 ;
V_116 [ 21 ] = ( V_4 -> V_43 . V_76 > 2 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 2 ] -> V_448 ) : 0 ;
V_116 [ 22 ] = ( V_4 -> V_43 . V_76 > 3 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 3 ] -> V_448 ) : 0 ;
V_116 [ 23 ] = V_4 -> V_440 . V_858 ;
V_116 [ 24 ] = V_4 -> V_440 . V_859 ;
V_116 [ 25 ] = V_4 -> V_440 . V_524 ;
V_116 [ 26 ] = V_4 -> V_440 . V_522 ;
V_116 [ 27 ] = V_4 -> V_440 . V_567 ;
V_116 [ 28 ] = V_4 -> V_440 . V_563 ;
V_116 [ 29 ] = V_4 -> V_440 . V_860 ;
V_116 [ 30 ] = V_4 -> V_440 . V_861 ;
V_116 [ 31 ] = V_4 -> V_440 . V_541 ;
V_116 [ 32 ] = V_4 -> V_440 . V_537 ;
V_116 [ 33 ] = V_4 -> V_440 . V_862 ;
V_116 [ 34 ] = V_4 -> V_440 . V_863 ;
V_116 [ 35 ] = V_4 -> V_440 . V_555 ;
V_116 [ 36 ] = V_4 -> V_440 . V_559 ;
}
void F_413 ( struct V_615 * V_6 , V_691 V_844 , T_3 * V_116 )
{
switch ( V_844 ) {
case V_845 :
memcpy ( V_116 , & V_846 ,
sizeof( V_846 ) ) ;
break;
default:
F_69 ( 1 ) ;
break;
}
}
void F_414 ( struct V_615 * V_6 ,
struct V_864 * V_9 )
{
struct V_3 * V_4 = V_6 -> V_620 ;
F_415 ( V_9 -> V_865 , V_4 -> V_57 . V_309 ? L_323 : L_322 ,
sizeof( V_9 -> V_865 ) ) ;
F_415 ( V_9 -> V_866 , L_330 , sizeof( V_9 -> V_866 ) ) ;
F_415 ( V_9 -> V_867 , V_4 -> V_9 . V_304 ,
sizeof( V_9 -> V_867 ) ) ;
snprintf ( V_9 -> V_868 , sizeof( V_9 -> V_868 ) , L_331 ,
F_416 ( V_4 ) , F_417 ( V_4 ) , F_418 ( V_4 ) ) ;
}
static void F_419 ( struct V_869 * V_870 ,
int V_871 , int V_872 )
{
int V_873 , V_874 , V_875 , V_876 ;
switch ( V_872 ) {
case V_877 :
V_873 = V_878 ;
V_874 = V_879 ;
break;
case V_880 :
V_873 = V_881 ;
V_874 = V_882 ;
break;
default:
V_873 = V_878 ;
V_874 = V_879 ;
F_48 ( 1 ) ;
}
V_875 = 0 ;
V_876 = 0 ;
switch ( V_871 ) {
case V_883 :
V_875 |= V_884 ;
V_876 |= V_885 ;
case V_886 :
V_875 |= V_887 | V_888 ;
V_876 |= V_889 |
V_890 ;
case V_891 :
V_875 |= V_892 | V_893 ;
V_876 |= V_894 | V_895 ;
case V_896 :
V_875 |= V_897 | V_898 ;
V_876 |= V_899 | V_900 ;
break;
default:
V_875 = V_897 | V_898 ;
V_876 = V_899 | V_900 ;
F_48 ( 1 ) ;
}
V_870 -> V_901 = V_902 | V_874 | V_876 ;
V_870 -> V_903 = V_904 | V_873 | V_875 ;
}
int F_420 ( struct V_615 * V_905 ,
struct V_869 * V_870 )
{
struct V_3 * V_4 = V_905 -> V_620 ;
enum V_450 V_16 ;
struct V_727 V_727 ;
if ( ( V_4 -> V_9 . type == V_12 ) || ( V_4 -> V_9 . V_10 ) )
V_16 = V_20 ;
else
V_16 = V_4 -> V_9 . V_16 ;
V_870 -> V_906 = V_907 ;
V_870 -> V_908 = V_909 ;
V_870 -> V_910 = V_911 ;
switch ( V_16 ) {
case V_17 :
case V_21 :
F_419 ( V_870 , V_891 , V_877 ) ;
V_870 -> V_912 = V_891 ;
V_870 -> V_913 = V_877 ;
break;
case V_19 :
case V_23 :
F_419 ( V_870 , V_886 , V_880 ) ;
V_870 -> V_912 = V_886 ;
V_870 -> V_913 = V_880 ;
break;
case V_20 :
F_419 ( V_870 , V_883 , V_880 ) ;
V_870 -> V_912 = V_883 ;
V_870 -> V_913 = V_880 ;
break;
default:
F_419 ( V_870 , V_896 , V_877 ) ;
V_870 -> V_912 = V_896 ;
V_870 -> V_913 = V_877 ;
}
if ( V_725 ( V_4 , & V_727 ) != 0 )
return 0 ;
F_421 ( V_905 ,
L_332 ,
V_727 . V_728 ,
V_727 . V_729 ,
V_727 . V_730 ) ;
switch ( V_727 . V_728 ) {
case V_914 :
case V_915 :
F_419 ( V_870 , V_886 , V_877 ) ;
V_870 -> V_913 = V_877 ;
break;
case V_916 :
case V_917 :
F_419 ( V_870 , V_886 , V_880 ) ;
V_870 -> V_913 = V_880 ;
break;
case V_918 :
case V_919 :
F_419 ( V_870 , V_883 , V_880 ) ;
V_870 -> V_913 = V_880 ;
break;
}
switch ( V_727 . V_729 ) {
case V_920 :
V_870 -> V_908 = V_909 ;
break;
case V_921 :
V_870 -> V_908 = V_922 ;
break;
}
switch ( V_727 . V_730 ) {
case V_923 :
V_870 -> V_912 = V_896 ;
break;
case V_924 :
V_870 -> V_912 = V_891 ;
break;
case V_925 :
V_870 -> V_912 = V_886 ;
break;
case V_926 :
V_870 -> V_912 = V_883 ;
break;
}
return 0 ;
}
static int T_10 F_422 ( void )
{
int V_34 ;
F_423 ( L_333 ) ;
F_132 ( & V_829 . V_39 ) ;
F_132 ( & V_818 ) ;
F_424 ( & V_829 . V_830 ) ;
F_138 ( & V_802 ) ;
V_8 = F_425 ( L_334 ) ;
V_34 = F_379 () ;
if ( V_34 )
goto V_927;
V_842 = F_426 ( L_335 ) ;
V_34 = F_427 ( V_842 ) ;
if ( V_34 )
goto V_928;
V_249 = F_428 ( L_336 ,
sizeof( struct V_587 ) + V_444 , 64 , 0 , NULL ) ;
if ( ! V_249 ) {
V_34 = - V_47 ;
goto V_929;
}
V_100 = F_428 ( L_337 ,
sizeof( struct V_95 ) , 0 , 0 , NULL ) ;
if ( ! V_100 ) {
V_34 = - V_47 ;
goto V_930;
}
V_34 = F_429 ( & V_931 ) ;
if ( V_34 )
goto V_932;
V_843 . V_865 . V_933 = V_934 ;
V_34 = F_430 ( & V_843 ) ;
if ( V_34 )
goto V_935;
return 0 ;
V_935:
F_431 ( & V_931 ) ;
V_932:
F_432 ( V_100 ) ;
V_930:
F_432 ( V_249 ) ;
V_929:
F_433 ( V_842 ) ;
V_928:
F_374 () ;
V_927:
F_434 ( L_338 ) ;
return V_34 ;
}
static void T_11 F_435 ( void )
{
F_392 () ;
F_436 ( V_8 ) ;
F_437 ( & V_843 ) ;
F_431 ( & V_931 ) ;
F_432 ( V_100 ) ;
F_432 ( V_249 ) ;
F_433 ( V_842 ) ;
F_374 () ;
F_423 ( L_339 ) ;
}
