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
if ( ! V_4 || ! F_109 ( V_191 ) )
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
if ( V_4 -> V_116 . V_118 == V_190 ) {
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
struct V_258 * V_259 ;
F_35 ( V_60 , 2 , L_116 ) ;
V_118 = V_4 -> V_116 . V_118 ;
V_259 = F_130 ( V_118 , 0 ) ;
if ( ! V_259 )
goto V_68;
V_4 -> V_9 . V_260 = 0x4100 + V_259 -> V_261 ;
if ( V_4 -> V_9 . type == V_12 )
goto V_68;
if ( ( V_259 -> V_262 & 0x02 ) == 0x02 )
F_127 ( V_4 ) ;
else
F_128 ( V_4 ) ;
V_68:
F_31 ( V_259 ) ;
F_38 ( V_60 , 2 , L_117 , V_4 -> V_43 . V_76 ) ;
F_38 ( V_60 , 2 , L_118 , V_4 -> V_9 . V_260 ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 4 , L_119 ) ;
F_54 ( & V_4 -> V_43 . V_52 , V_253 ) ;
V_4 -> V_43 . V_263 = V_264 ;
if ( V_4 -> V_9 . type == V_12 )
V_4 -> V_43 . V_44 . V_45 = V_265 ;
else
V_4 -> V_43 . V_44 . V_45 = V_266 ;
V_4 -> V_43 . V_56 . V_45 = V_4 -> V_43 . V_44 . V_45 ;
F_132 ( & V_4 -> V_43 . V_56 . V_50 ) ;
F_132 ( & V_4 -> V_43 . V_44 . V_50 ) ;
}
static void F_133 ( struct V_3 * V_4 )
{
V_4 -> V_57 . V_267 . type = V_268 ;
V_4 -> V_57 . V_269 . type = V_268 ;
V_4 -> V_57 . V_270 = 0 ;
V_4 -> V_57 . V_271 = V_272 ;
V_4 -> V_57 . V_273 = 0 ;
V_4 -> V_57 . V_274 = V_275 ;
V_4 -> V_57 . V_276 = V_277 ;
V_4 -> V_57 . V_58 = V_278 ;
}
static int F_134 ( struct V_3 * V_4 , unsigned long V_186 )
{
unsigned long V_29 ;
int V_34 = 0 ;
F_16 ( & V_4 -> V_30 , V_29 ) ;
F_46 ( V_4 , 4 , L_120 ,
( V_279 ) V_4 -> V_32 ,
( V_279 ) V_4 -> V_31 ,
( V_279 ) V_4 -> V_35 ) ;
V_34 = ( V_4 -> V_32 & V_186 ) ;
F_17 ( & V_4 -> V_30 , V_29 ) ;
return V_34 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_280 * V_281 ;
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_188 ) ;
F_3 ( V_4 , 2 , L_121 ) ;
if ( V_4 -> V_113 . V_52 != V_114 &&
V_4 -> V_153 . V_52 != V_114 )
return;
if ( F_134 ( V_4 , V_187 ) ) {
V_281 = F_136 ( V_4 -> V_147 -> V_282 , ( void * ) V_4 ,
L_122 ) ;
if ( F_109 ( V_281 ) ) {
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
F_98 ( & V_4 -> V_283 ) ;
F_98 ( & V_4 -> V_284 ) ;
F_98 ( & V_4 -> V_152 ) ;
F_98 ( & V_4 -> V_285 ) ;
F_98 ( & V_4 -> V_30 ) ;
F_138 ( & V_4 -> V_286 ) ;
F_138 ( & V_4 -> V_287 ) ;
V_4 -> V_32 = 0 ;
V_4 -> V_31 = 0 ;
V_4 -> V_35 = 0 ;
F_139 ( & V_4 -> V_188 , F_135 ) ;
F_132 ( & V_4 -> V_288 ) ;
F_132 ( V_4 -> V_289 ) ;
F_132 ( & V_4 -> V_182 ) ;
F_99 ( & V_4 -> V_33 ) ;
F_133 ( V_4 ) ;
F_132 ( & V_4 -> V_290 . V_291 ) ;
V_4 -> V_290 . V_292 = 0 ;
V_4 -> V_290 . V_293 = 0 ;
V_4 -> V_290 . V_294 = 0 ;
F_131 ( V_4 ) ;
F_140 ( & V_4 -> V_254 , V_295 ) ;
F_139 ( & V_4 -> V_5 , F_1 ) ;
return 0 ;
}
static void F_141 ( struct V_296 * V_297 , struct V_298 * V_299 )
{
struct V_3 * V_4 = F_2 ( V_299 , struct V_3 ,
V_300 ) ;
if ( V_4 -> V_9 . V_301 [ 0 ] )
F_142 ( V_297 , L_124 ,
F_143 ( V_4 ) , V_4 -> V_9 . V_301 ) ;
}
static struct V_3 * F_144 ( void )
{
struct V_3 * V_4 ;
F_35 ( V_60 , 2 , L_125 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_185 | V_46 ) ;
if ( ! V_4 )
goto V_68;
F_40 ( V_60 , 2 , & V_4 , sizeof( void * ) ) ;
V_4 -> V_289 = F_26 ( sizeof( struct V_302 ) , V_46 ) ;
if ( ! V_4 -> V_289 ) {
F_35 ( V_60 , 0 , L_126 ) ;
goto V_303;
}
if ( F_97 ( & V_4 -> V_113 ) )
goto V_304;
if ( F_97 ( & V_4 -> V_153 ) )
goto V_305;
V_4 -> V_57 . V_306 = - 1 ;
V_4 -> V_300 . V_307 = F_141 ;
F_145 ( & V_4 -> V_300 ) ;
return V_4 ;
V_305:
F_126 ( & V_4 -> V_113 ) ;
V_304:
F_31 ( V_4 -> V_289 ) ;
V_303:
F_31 ( V_4 ) ;
V_68:
return NULL ;
}
static int F_146 ( struct V_3 * V_4 )
{
int V_41 = 0 ;
F_35 ( V_60 , 2 , L_127 ) ;
V_4 -> V_43 . V_308 = V_309 ;
V_4 -> V_43 . V_257 = V_310 ;
while ( V_311 [ V_41 ] [ V_312 ] ) {
if ( ( F_147 ( V_4 ) -> V_313 . V_314 ==
V_311 [ V_41 ] [ V_315 ] ) &&
( F_147 ( V_4 ) -> V_313 . V_316 ==
V_311 [ V_41 ] [ V_312 ] ) ) {
V_4 -> V_9 . type = V_311 [ V_41 ] [ V_312 ] ;
V_4 -> V_43 . V_76 =
V_311 [ V_41 ] [ V_317 ] ;
V_4 -> V_43 . V_67 = 1 ;
V_4 -> V_9 . V_318 =
V_311 [ V_41 ] [ V_319 ] ;
F_129 ( V_4 ) ;
return 0 ;
}
V_41 ++ ;
}
V_4 -> V_9 . type = V_320 ;
F_41 ( & V_4 -> V_7 -> V_6 , L_128
L_129 ) ;
return - V_321 ;
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
V_157 -> V_52 == V_216 , V_322 ) ;
if ( V_34 == - V_323 )
return V_34 ;
if ( V_157 -> V_52 != V_216 )
return - V_324 ;
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
V_157 -> V_52 == V_218 , V_322 ) ;
if ( V_34 == - V_323 )
return V_34 ;
if ( V_157 -> V_52 != V_218 )
return - V_324 ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 )
{
int V_325 = 0 , V_326 = 0 , V_327 = 0 ;
F_3 ( V_4 , 3 , L_132 ) ;
V_325 = F_152 ( & V_4 -> V_113 ) ;
V_326 = F_152 ( & V_4 -> V_153 ) ;
V_327 = F_152 ( & V_4 -> V_116 ) ;
if ( V_325 )
return V_325 ;
if ( V_326 )
return V_326 ;
return V_327 ;
}
static int F_155 ( struct V_3 * V_4 )
{
int V_325 = 0 , V_326 = 0 , V_327 = 0 ;
F_3 ( V_4 , 3 , L_133 ) ;
V_325 = F_148 ( & V_4 -> V_113 ) ;
V_326 = F_148 ( & V_4 -> V_153 ) ;
V_327 = F_148 ( & V_4 -> V_116 ) ;
if ( V_325 )
return V_325 ;
if ( V_326 )
return V_326 ;
return V_327 ;
}
static int F_156 ( struct V_3 * V_4 , int V_328 )
{
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_134 ) ;
if ( V_328 )
V_34 = F_154 ( V_4 ) ;
if ( V_34 )
return V_34 ;
return F_155 ( V_4 ) ;
}
int F_157 ( struct V_3 * V_4 , int V_329 )
{
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_135 ) ;
switch ( F_53 ( & V_4 -> V_43 . V_52 , V_330 ,
V_331 ) ) {
case V_330 :
if ( V_4 -> V_9 . type == V_12 )
V_34 = F_158 ( F_37 ( V_4 ) ,
V_332 ) ;
else
V_34 = F_158 ( F_37 ( V_4 ) ,
V_333 ) ;
if ( V_34 )
F_46 ( V_4 , 3 , L_37 , V_34 ) ;
F_54 ( & V_4 -> V_43 . V_52 , V_334 ) ;
break;
case V_331 :
return V_34 ;
default:
break;
}
V_34 = F_156 ( V_4 , V_329 ) ;
if ( V_34 )
F_46 ( V_4 , 3 , L_136 , V_34 ) ;
V_4 -> V_52 = V_53 ;
return V_34 ;
}
static int F_159 ( struct V_3 * V_4 , void * * V_74 ,
int * V_250 )
{
struct V_335 * V_335 ;
char * V_336 ;
int V_337 ;
struct V_156 * V_157 = & V_4 -> V_116 ;
unsigned long V_29 ;
V_335 = F_160 ( V_157 -> V_118 , V_338 ) ;
if ( ! V_335 || V_335 -> V_129 == 0 )
return - V_339 ;
V_336 = F_26 ( V_335 -> V_162 , V_46 | V_185 ) ;
if ( ! V_336 )
return - V_47 ;
V_157 -> V_119 . V_340 = V_335 -> V_129 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_336 ) ;
V_157 -> V_119 . V_162 = V_335 -> V_162 ;
V_157 -> V_119 . V_29 = V_341 ;
V_157 -> V_52 = V_342 ;
F_16 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
V_337 = F_161 ( V_157 -> V_118 , & V_157 -> V_119 ,
V_212 , V_343 , 0 ,
V_344 ) ;
F_17 ( F_149 ( V_157 -> V_118 ) , V_29 ) ;
if ( ! V_337 )
F_93 ( V_4 -> V_33 ,
( V_157 -> V_52 == V_226 ||
V_157 -> V_52 == V_213 ) ) ;
if ( V_157 -> V_52 == V_213 )
V_337 = - V_115 ;
else
V_157 -> V_52 = V_213 ;
if ( V_337 ) {
F_31 ( V_336 ) ;
* V_74 = NULL ;
* V_250 = 0 ;
} else {
* V_250 = V_335 -> V_162 ;
* V_74 = V_336 ;
}
return V_337 ;
}
static void F_162 ( struct V_3 * V_4 , char * V_345 )
{
F_35 ( V_60 , 2 , L_137 ) ;
V_4 -> V_9 . V_141 = V_345 [ 30 ] ;
V_4 -> V_9 . V_346 = V_345 [ 31 ] ;
V_4 -> V_9 . V_347 = V_345 [ 63 ] ;
V_4 -> V_9 . V_10 = ( ( V_345 [ 0x10 ] == V_348 [ 'V' ] ) &&
( V_345 [ 0x11 ] == V_348 [ 'M' ] ) ) ;
}
static void F_163 ( struct V_3 * V_4 , char * V_345 )
{
F_35 ( V_60 , 2 , L_138 ) ;
if ( V_345 [ 74 ] == 0xF0 && V_345 [ 75 ] == 0xF0 &&
V_345 [ 76 ] >= 0xF1 && V_345 [ 76 ] <= 0xF4 ) {
V_4 -> V_9 . V_349 . V_350 = 0 ;
V_4 -> V_9 . V_349 . V_351 = 0 ;
V_4 -> V_9 . V_349 . V_352 = 0 ;
} else {
V_4 -> V_9 . V_349 . V_350 = 250 ;
V_4 -> V_9 . V_349 . V_351 = 5 ;
V_4 -> V_9 . V_349 . V_352 = 15 ;
}
}
static void F_164 ( struct V_3 * V_4 )
{
V_4 -> V_353 . V_354 = 0x00010103UL ;
V_4 -> V_353 . V_355 = 0x00010108UL ;
V_4 -> V_353 . V_356 = 0x0001010aUL ;
V_4 -> V_353 . V_357 = 0x0001010bUL ;
V_4 -> V_353 . V_358 = 0x0001010dUL ;
}
static void F_165 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_12 :
V_4 -> V_9 . V_260 = V_359 ;
break;
case V_11 :
case V_15 :
V_4 -> V_9 . V_260 = V_360 ;
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
V_157 -> V_52 == V_114 , V_322 ) ;
if ( V_34 == - V_323 )
return V_34 ;
if ( V_157 -> V_52 != V_114 ) {
V_34 = - V_324 ;
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
V_180 V_361 ;
T_2 V_38 ;
int V_34 ;
struct V_362 V_363 ;
V_4 = F_88 ( V_157 -> V_118 ) ;
F_35 ( V_60 , 2 , L_142 ) ;
V_112 = F_60 ( V_157 ) ;
V_112 -> V_170 = F_167 ;
memcpy ( & V_157 -> V_119 , V_161 , sizeof( struct V_160 ) ) ;
V_157 -> V_119 . V_162 = V_364 ;
V_157 -> V_119 . V_163 = ( T_1 ) F_89 ( V_112 -> V_116 ) ;
if ( V_157 == & V_4 -> V_153 ) {
memcpy ( V_112 -> V_116 , V_365 , V_364 ) ;
memcpy ( F_169 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_366 , V_184 ) ;
V_4 -> V_177 . V_366 ++ ;
} else {
memcpy ( V_112 -> V_116 , V_367 , V_364 ) ;
memcpy ( F_169 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_366 , V_184 ) ;
}
V_38 = ( ( T_2 ) V_4 -> V_9 . V_368 ) | 0x80 ;
memcpy ( F_170 ( V_112 -> V_116 ) , & V_38 , 1 ) ;
memcpy ( F_171 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_354 , V_369 ) ;
memcpy ( F_172 ( V_112 -> V_116 ) ,
& V_4 -> V_9 . V_260 , sizeof( V_180 ) ) ;
F_173 ( F_37 ( V_4 ) , & V_363 ) ;
memcpy ( F_174 ( V_112 -> V_116 ) , & V_363 . V_370 , 2 ) ;
V_361 = ( V_4 -> V_9 . V_347 << 8 ) + V_4 -> V_9 . V_346 ;
memcpy ( F_175 ( V_112 -> V_116 ) , & V_361 , 2 ) ;
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
V_157 -> V_52 == V_371 , V_322 ) ;
if ( V_34 == - V_323 )
return V_34 ;
if ( V_157 -> V_52 != V_371 ) {
F_61 ( & V_157 -> V_118 -> V_6 , L_144
L_145 ) ;
F_62 ( 2 , L_146 ,
F_63 ( & V_157 -> V_118 -> V_6 ) ) ;
F_38 ( V_60 , 2 , L_136 , - V_324 ) ;
F_94 ( V_157 ) ;
return - V_324 ;
}
return F_166 ( V_157 , F_167 ) ;
}
static int F_176 ( int V_372 )
{
if ( ( V_372 & 0xff ) == 8 )
return ( V_372 & 0xff ) + 0x400 ;
if ( ( ( V_372 >> 8 ) & 3 ) == 1 )
return ( V_372 & 0xff ) + 0x200 ;
return V_372 ;
}
static void F_177 ( struct V_156 * V_157 ,
struct V_111 * V_112 )
{
struct V_3 * V_4 ;
V_180 V_361 ;
F_35 ( V_60 , 2 , L_147 ) ;
if ( V_157 -> V_52 == V_213 ) {
V_157 -> V_52 = V_371 ;
goto V_68;
}
V_4 = F_88 ( V_157 -> V_118 ) ;
if ( ! ( F_178 ( V_112 -> V_116 ) ) ) {
if ( F_179 ( V_112 -> V_116 ) == V_373 )
F_41 ( & V_4 -> V_153 . V_118 -> V_6 ,
L_148
L_149 ) ;
else
F_62 ( 2 , L_150
L_151 ,
F_63 ( & V_4 -> V_153 . V_118 -> V_6 ) ) ;
goto V_68;
}
memcpy ( & V_361 , F_172 ( V_112 -> V_116 ) , 2 ) ;
if ( ( V_361 & ~ 0x0100 ) != F_176 ( V_4 -> V_9 . V_260 ) ) {
F_62 ( 2 , L_152
L_153
L_154 , F_63 ( & V_4 -> V_153 . V_118 -> V_6 ) ,
V_4 -> V_9 . V_260 , V_361 ) ;
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
V_180 V_361 ;
F_35 ( V_60 , 2 , L_155 ) ;
if ( V_157 -> V_52 == V_213 ) {
V_157 -> V_52 = V_371 ;
goto V_68;
}
V_4 = F_88 ( V_157 -> V_118 ) ;
if ( F_87 ( V_4 , V_112 -> V_116 ) )
goto V_68;
if ( ! ( F_178 ( V_112 -> V_116 ) ) ) {
switch ( F_179 ( V_112 -> V_116 ) ) {
case V_373 :
F_41 ( & V_4 -> V_153 . V_118 -> V_6 ,
L_148
L_149 ) ;
break;
case V_374 :
case V_375 :
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
V_4 -> V_9 . V_376 = 1 ;
memcpy ( & V_361 , F_172 ( V_112 -> V_116 ) , 2 ) ;
if ( V_361 != F_176 ( V_4 -> V_9 . V_260 ) ) {
F_62 ( 2 , L_160
L_161 ,
F_63 ( & V_4 -> V_113 . V_118 -> V_6 ) ,
V_4 -> V_9 . V_260 , V_361 ) ;
goto V_68;
}
memcpy ( & V_4 -> V_353 . V_377 ,
F_171 ( V_112 -> V_116 ) ,
V_369 ) ;
memcpy ( & V_4 -> V_9 . V_301 [ 0 ] ,
F_182 ( V_112 -> V_116 ) , V_378 ) ;
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
& V_4 -> V_177 . V_366 , V_184 ) ;
V_4 -> V_177 . V_366 ++ ;
memcpy ( F_96 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_379 , V_184 ) ;
V_4 -> V_177 . V_379 ++ ;
memcpy ( F_184 ( V_112 -> V_116 ) ,
& V_4 -> V_177 . V_183 , V_184 ) ;
F_40 ( V_154 , 2 , V_112 -> V_116 , V_155 ) ;
}
int F_185 ( struct V_3 * V_4 , int V_158 ,
struct V_111 * V_112 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_380 )
{
int V_34 ;
unsigned long V_29 ;
struct V_123 * V_124 = NULL ;
unsigned long V_381 , V_382 ;
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
V_124 -> V_383 = V_380 ;
if ( V_4 -> V_52 == V_53 )
V_124 -> V_177 = V_178 ;
else
V_124 -> V_177 = V_4 -> V_177 . V_384 ++ ;
F_99 ( & V_124 -> V_33 ) ;
F_16 ( & V_4 -> V_152 , V_29 ) ;
F_95 ( & V_124 -> V_39 , & V_4 -> V_182 ) ;
F_17 ( & V_4 -> V_152 , V_29 ) ;
F_40 ( V_154 , 2 , V_112 -> V_116 , V_155 ) ;
while ( F_53 ( & V_4 -> V_153 . V_121 , 0 , 1 ) ) ;
F_183 ( V_4 , V_158 , V_112 ) ;
if ( F_78 ( V_112 -> V_116 ) )
V_382 = V_385 ;
else
V_382 = V_322 ;
V_381 = V_386 + V_382 ;
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
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
if ( ( V_129 -> V_132 . V_133 == V_388 ) &&
( V_129 -> V_132 . V_389 == V_390 ) ) {
if ( ! F_187 ( V_124 -> V_33 ,
F_45 ( & V_124 -> V_127 ) , V_382 ) )
goto V_391;
} else {
while ( ! F_45 ( & V_124 -> V_127 ) ) {
if ( F_188 ( V_386 , V_381 ) )
goto V_391;
F_189 () ;
}
}
if ( V_124 -> V_34 == - V_115 )
goto error;
V_34 = V_124 -> V_34 ;
F_71 ( V_124 ) ;
return V_34 ;
V_391:
V_124 -> V_34 = - V_324 ;
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
memcpy ( & V_4 -> V_353 . V_392 ,
F_191 ( V_112 -> V_116 ) ,
V_369 ) ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_192 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_167 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_393 , V_394 ) ;
memcpy ( F_193 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_377 , V_369 ) ;
memcpy ( F_194 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_355 , V_369 ) ;
V_34 = F_185 ( V_4 , V_394 , V_112 ,
F_190 , NULL ) ;
return V_34 ;
}
static int F_195 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_168 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_353 . V_395 ,
F_196 ( V_112 -> V_116 ) ,
V_369 ) ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_197 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_169 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_396 , V_397 ) ;
memcpy ( F_198 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_377 , V_369 ) ;
memcpy ( F_199 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_356 , V_369 ) ;
memcpy ( F_200 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_392 , V_369 ) ;
V_34 = F_185 ( V_4 , V_397 , V_112 ,
F_195 , NULL ) ;
return V_34 ;
}
static inline int F_201 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_320 :
return 1500 ;
case V_12 :
return V_4 -> V_9 . V_398 ;
case V_11 :
switch ( V_4 -> V_9 . V_16 ) {
case V_18 :
case V_22 :
return 2000 ;
default:
return V_4 -> V_57 . V_306 ? 1500 : 1492 ;
}
case V_13 :
case V_14 :
return V_4 -> V_57 . V_306 ? 1500 : 1492 ;
default:
return 1500 ;
}
}
static inline int F_202 ( int V_399 )
{
switch ( V_399 ) {
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
static inline int F_203 ( struct V_3 * V_4 , int V_400 )
{
switch ( V_4 -> V_9 . type ) {
case V_11 :
case V_13 :
case V_14 :
case V_12 :
return ( ( V_400 >= 576 ) &&
( V_400 <= V_4 -> V_9 . V_398 ) ) ;
case V_15 :
case V_320 :
default:
return 1 ;
}
}
static int F_204 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
V_180 V_400 , V_399 ;
V_180 V_158 ;
T_2 V_16 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_170 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_353 . V_401 ,
F_205 ( V_112 -> V_116 ) ,
V_369 ) ;
if ( V_4 -> V_9 . type == V_12 ) {
memcpy ( & V_399 , F_206 ( V_112 -> V_116 ) , 2 ) ;
V_400 = F_202 ( V_399 ) ;
if ( ! V_400 ) {
V_112 -> V_34 = - V_402 ;
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
if ( V_4 -> V_9 . V_403 && ( V_4 -> V_9 . V_403 != V_400 ) ) {
if ( V_4 -> V_6 &&
( ( V_4 -> V_6 -> V_400 == V_4 -> V_9 . V_403 ) ||
( V_4 -> V_6 -> V_400 > V_400 ) ) )
V_4 -> V_6 -> V_400 = V_400 ;
F_123 ( V_4 ) ;
}
V_4 -> V_9 . V_403 = V_400 ;
V_4 -> V_9 . V_398 = V_400 ;
V_4 -> V_43 . V_263 = V_400 + 2 * V_404 ;
} else {
V_4 -> V_9 . V_398 = * ( V_180 * ) F_206 (
V_112 -> V_116 ) ;
V_4 -> V_9 . V_403 = F_207 ( V_4 -> V_9 . V_398 ,
F_201 ( V_4 ) ) ;
V_4 -> V_43 . V_263 = V_264 ;
}
memcpy ( & V_158 , F_208 ( V_112 -> V_116 ) , 2 ) ;
if ( V_158 >= V_405 ) {
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
char V_406 ;
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_172 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_407 , V_408 ) ;
* ( F_211 ( V_112 -> V_116 ) ) =
( T_2 ) V_4 -> V_9 . V_368 ;
if ( V_4 -> V_57 . V_306 )
if ( V_4 -> V_9 . type == V_15 )
V_406 = V_409 ;
else
V_406 = V_410 ;
else
V_406 = V_411 ;
memcpy ( F_212 ( V_112 -> V_116 ) , & V_406 , 1 ) ;
memcpy ( F_213 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_395 , V_369 ) ;
memcpy ( F_214 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_357 , V_369 ) ;
memcpy ( F_215 ( V_112 -> V_116 ) ,
V_4 -> V_9 . V_412 , 9 ) ;
V_34 = F_185 ( V_4 , V_408 , V_112 ,
F_204 , NULL ) ;
return V_34 ;
}
static int F_216 ( struct V_3 * V_4 , struct V_123 * V_124 ,
unsigned long V_116 )
{
struct V_111 * V_112 ;
F_35 ( V_60 , 2 , L_173 ) ;
V_112 = (struct V_111 * ) V_116 ;
memcpy ( & V_4 -> V_353 . V_413 ,
F_217 ( V_112 -> V_116 ) ,
V_369 ) ;
if ( ! strncmp ( L_174 , F_217 ( V_112 -> V_116 ) ,
3 ) ) {
F_35 ( V_60 , 2 , L_175 ) ;
F_41 ( & V_4 -> V_7 -> V_6 , L_176
L_177 ) ;
V_112 -> V_34 = - V_414 ;
}
F_38 ( V_60 , 2 , L_77 , V_112 -> V_34 ) ;
return 0 ;
}
static int F_218 ( struct V_3 * V_4 )
{
int V_34 ;
V_180 V_361 ;
struct V_111 * V_112 ;
struct V_362 V_415 ;
F_35 ( V_60 , 2 , L_178 ) ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
memcpy ( V_112 -> V_116 , V_416 , V_417 ) ;
memcpy ( F_219 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_395 , V_369 ) ;
memcpy ( F_220 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_358 , V_369 ) ;
memcpy ( F_221 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_401 , V_369 ) ;
F_173 ( F_37 ( V_4 ) , & V_415 ) ;
memcpy ( F_222 ( V_112 -> V_116 ) , & V_415 . V_370 , 2 ) ;
V_361 = ( V_4 -> V_9 . V_347 << 8 ) + V_4 -> V_9 . V_346 ;
memcpy ( F_223 ( V_112 -> V_116 ) , & V_361 , 2 ) ;
V_34 = F_185 ( V_4 , V_417 , V_112 ,
F_216 , NULL ) ;
return V_34 ;
}
static int F_50 ( struct V_90 * V_91 , int V_92 )
{
int V_34 ;
struct V_95 * V_418 ;
V_34 = 0 ;
V_418 = F_224 ( V_100 , V_125 ) ;
if ( ! V_418 ) {
V_34 = - V_47 ;
goto V_68;
}
V_418 -> V_74 = & V_91 -> V_62 [ V_92 ] ;
F_225 ( & V_418 -> V_231 ) ;
F_226 ( & V_418 -> V_231 . V_152 , & V_419 ) ;
V_418 -> V_91 = V_91 ;
V_418 -> V_101 = NULL ;
V_418 -> V_94 = V_91 -> V_73 [ V_92 ] ;
F_54 ( & V_418 -> V_52 , V_246 ) ;
V_91 -> V_73 [ V_92 ] = V_418 ;
if ( V_91 -> V_79 ) {
V_91 -> V_79 [ V_92 ] . V_420 = V_418 ;
F_46 ( V_91 -> V_4 , 2 , L_179 , V_92 ) ;
F_46 ( V_91 -> V_4 , 2 , L_43 , ( long ) V_418 ) ;
F_46 ( V_91 -> V_4 , 2 , L_43 ,
( long ) V_418 -> V_94 ) ;
}
V_68:
return V_34 ;
}
static int F_227 ( struct V_3 * V_4 )
{
int V_41 , V_42 ;
F_35 ( V_60 , 2 , L_180 ) ;
if ( F_53 ( & V_4 -> V_43 . V_52 , V_253 ,
V_334 ) != V_253 )
return 0 ;
V_4 -> V_43 . V_255 = F_26 ( sizeof( struct V_71 ) ,
V_46 ) ;
if ( ! V_4 -> V_43 . V_255 )
goto V_421;
F_35 ( V_60 , 2 , L_181 ) ;
F_40 ( V_60 , 2 , & V_4 -> V_43 . V_255 , sizeof( void * ) ) ;
memset ( V_4 -> V_43 . V_255 , 0 , sizeof( struct V_71 ) ) ;
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_74 =
& V_4 -> V_43 . V_255 -> V_62 [ V_41 ] ;
V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_256 = NULL ;
}
if ( F_25 ( V_4 ) )
goto V_422;
V_4 -> V_43 . V_78 =
F_26 ( V_4 -> V_43 . V_76 *
sizeof( struct V_90 * ) , V_46 ) ;
if ( ! V_4 -> V_43 . V_78 )
goto V_423;
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 ) {
V_4 -> V_43 . V_78 [ V_41 ] = F_26 ( sizeof( struct V_90 ) ,
V_46 ) ;
if ( ! V_4 -> V_43 . V_78 [ V_41 ] )
goto V_424;
F_38 ( V_60 , 2 , L_182 , V_41 ) ;
F_40 ( V_60 , 2 , & V_4 -> V_43 . V_78 [ V_41 ] , sizeof( void * ) ) ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_425 = V_41 ;
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 ) {
F_69 ( V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] != NULL ) ;
if ( F_50 ( V_4 -> V_43 . V_78 [ V_41 ] , V_42 ) )
goto V_426;
}
}
if ( F_39 ( V_4 ) )
goto V_424;
return 0 ;
V_426:
while ( V_42 > 0 ) {
-- V_42 ;
F_49 ( V_100 ,
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] ) ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] = NULL ;
}
V_424:
while ( V_41 > 0 ) {
F_31 ( V_4 -> V_43 . V_78 [ -- V_41 ] ) ;
F_121 ( V_4 -> V_43 . V_78 [ V_41 ] , 1 ) ;
}
F_31 ( V_4 -> V_43 . V_78 ) ;
V_4 -> V_43 . V_78 = NULL ;
V_423:
F_27 ( V_4 ) ;
V_422:
F_31 ( V_4 -> V_43 . V_255 ) ;
V_4 -> V_43 . V_255 = NULL ;
V_421:
F_54 ( & V_4 -> V_43 . V_52 , V_253 ) ;
return - V_47 ;
}
static void F_228 ( struct V_3 * V_4 ,
char * V_427 )
{
V_427 [ 0 ] = V_348 [ 'P' ] ;
V_427 [ 1 ] = V_348 [ 'C' ] ;
V_427 [ 2 ] = V_348 [ 'I' ] ;
V_427 [ 3 ] = V_348 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_427 [ 4 ] ) ) = F_229 ( V_4 ) ;
* ( ( unsigned int * ) ( & V_427 [ 8 ] ) ) = F_230 ( V_4 ) ;
* ( ( unsigned int * ) ( & V_427 [ 12 ] ) ) = F_231 ( V_4 ) ;
}
static void F_232 ( struct V_3 * V_4 ,
char * V_427 )
{
V_427 [ 16 ] = V_348 [ 'B' ] ;
V_427 [ 17 ] = V_348 [ 'L' ] ;
V_427 [ 18 ] = V_348 [ 'K' ] ;
V_427 [ 19 ] = V_348 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_427 [ 20 ] ) ) = V_4 -> V_9 . V_349 . V_350 ;
* ( ( unsigned int * ) ( & V_427 [ 24 ] ) ) = V_4 -> V_9 . V_349 . V_351 ;
* ( ( unsigned int * ) ( & V_427 [ 28 ] ) ) =
V_4 -> V_9 . V_349 . V_352 ;
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
memcpy ( V_112 -> V_116 , V_428 , V_429 ) ;
memcpy ( F_236 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_395 , V_369 ) ;
memcpy ( F_237 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_413 , V_369 ) ;
V_34 = F_185 ( V_4 , V_429 , V_112 , NULL , NULL ) ;
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
goto V_430;
}
V_34 = F_197 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_430;
}
V_34 = F_210 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_186 , V_34 ) ;
goto V_430;
}
V_34 = F_218 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_430;
}
V_34 = F_227 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_430;
}
V_34 = F_239 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_188 , V_34 ) ;
F_123 ( V_4 ) ;
goto V_430;
}
V_34 = F_233 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_189 , V_34 ) ;
goto V_430;
}
V_34 = F_235 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_190 , V_34 ) ;
goto V_430;
}
return 0 ;
V_430:
F_157 ( V_4 , V_4 -> V_9 . type != V_12 ) ;
F_240 ( F_37 ( V_4 ) ) ;
return V_34 ;
}
static void F_241 ( struct V_3 * V_4 )
{
char V_431 [ 15 ] ;
int V_41 ;
sprintf ( V_431 , L_191 , V_4 -> V_9 . V_412 + 1 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ )
V_431 [ V_41 ] =
( char ) V_432 [ ( T_2 ) V_431 [ V_41 ] ] ;
V_431 [ 8 ] = 0 ;
F_83 ( & V_4 -> V_7 -> V_6 , L_192
L_193 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? V_4 -> V_9 . V_301 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ,
V_431 ) ;
}
static void F_242 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 . V_412 [ 0 ] )
F_83 ( & V_4 -> V_7 -> V_6 , L_196
L_197
L_198 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? V_4 -> V_9 . V_301 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ) ;
else
F_83 ( & V_4 -> V_7 -> V_6 , L_196
L_199 ,
F_10 ( V_4 ) ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_194 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? V_4 -> V_9 . V_301 : L_74 ,
( V_4 -> V_9 . V_301 [ 0 ] ) ? L_195 : L_74 ,
F_11 ( V_4 ) ) ;
}
void F_243 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_11 :
case V_13 :
case V_14 :
if ( ! V_4 -> V_9 . V_301 [ 0 ] ) {
sprintf ( V_4 -> V_9 . V_301 , L_200 ,
V_4 -> V_9 . V_301 [ 2 ] ,
V_4 -> V_9 . V_301 [ 3 ] ) ;
V_4 -> V_9 . V_301 [ V_378 ] = 0 ;
break;
}
case V_12 :
if ( ( V_4 -> V_9 . V_10 ) ||
( V_4 -> V_9 . V_301 [ 0 ] & 0x80 ) ) {
V_4 -> V_9 . V_301 [ 0 ] = ( char ) V_432 [ ( T_2 )
V_4 -> V_9 . V_301 [ 0 ] ] ;
V_4 -> V_9 . V_301 [ 1 ] = ( char ) V_432 [ ( T_2 )
V_4 -> V_9 . V_301 [ 1 ] ] ;
V_4 -> V_9 . V_301 [ 2 ] = ( char ) V_432 [ ( T_2 )
V_4 -> V_9 . V_301 [ 2 ] ] ;
V_4 -> V_9 . V_301 [ 3 ] = ( char ) V_432 [ ( T_2 )
V_4 -> V_9 . V_301 [ 3 ] ] ;
V_4 -> V_9 . V_301 [ V_378 ] = 0 ;
}
break;
default:
memset ( & V_4 -> V_9 . V_301 [ 0 ] , 0 , V_378 + 1 ) ;
}
if ( V_4 -> V_9 . V_376 )
F_241 ( V_4 ) ;
else
F_242 ( V_4 ) ;
}
static void F_244 ( struct V_3 * V_4 )
{
struct V_36 * V_433 ;
F_3 ( V_4 , 5 , L_201 ) ;
F_245 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_246 ( V_4 , V_433 ) ;
}
}
static inline struct V_36 * F_247 (
struct V_3 * V_4 )
{
struct V_302 * V_434 ;
struct V_36 * V_433 ;
int V_41 , free ;
struct V_435 * V_435 ;
if ( F_248 ( & V_4 -> V_43 . V_56 . V_50 ) )
return NULL ;
F_249 (plh, &card->qdio.in_buf_pool.entry_list) {
V_433 = F_250 ( V_434 , struct V_36 , V_39 ) ;
free = 1 ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
if ( F_251 ( F_252 ( V_433 -> V_48 [ V_41 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_86 ( & V_433 -> V_39 ) ;
return V_433 ;
}
}
V_433 = F_250 ( V_4 -> V_43 . V_56 . V_50 . V_436 ,
struct V_36 , V_39 ) ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
if ( F_251 ( F_252 ( V_433 -> V_48 [ V_41 ] ) ) > 1 ) {
V_435 = F_253 ( V_125 ) ;
if ( ! V_435 ) {
return NULL ;
} else {
F_30 ( ( unsigned long ) V_433 -> V_48 [ V_41 ] ) ;
V_433 -> V_48 [ V_41 ] = F_254 ( V_435 ) ;
if ( V_4 -> V_57 . V_273 )
V_4 -> V_437 . V_438 ++ ;
}
}
}
F_86 ( & V_433 -> V_39 ) ;
return V_433 ;
}
static int F_255 ( struct V_3 * V_4 ,
struct V_439 * V_228 )
{
struct V_36 * V_37 ;
int V_41 ;
if ( ( V_4 -> V_57 . V_58 == V_59 ) && ( ! V_228 -> V_256 ) ) {
V_228 -> V_256 = F_256 ( V_440 + V_441 ) ;
if ( ! V_228 -> V_256 )
return 1 ;
}
V_37 = F_247 ( V_4 ) ;
if ( ! V_37 )
return 1 ;
V_228 -> V_37 = V_37 ;
for ( V_41 = 0 ; V_41 < F_28 ( V_4 ) ; ++ V_41 ) {
V_228 -> V_74 -> V_242 [ V_41 ] . V_250 = V_404 ;
V_228 -> V_74 -> V_242 [ V_41 ] . V_247 = V_37 -> V_48 [ V_41 ] ;
if ( V_41 == F_28 ( V_4 ) - 1 )
V_228 -> V_74 -> V_242 [ V_41 ] . V_251 = V_442 ;
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
V_4 -> V_43 . V_78 [ V_41 ] -> V_443 = 0 ;
V_4 -> V_43 . V_78 [ V_41 ] -> V_444 = 0 ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_445 , 0 ) ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_245 , 0 ) ;
F_54 ( & V_4 -> V_43 . V_78 [ V_41 ] -> V_52 ,
V_446 ) ;
}
return 0 ;
}
static inline T_2 F_258 ( enum V_447 V_16 )
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
enum V_448 V_449 )
{
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_129 -> V_132 . V_133 = V_133 ;
V_129 -> V_132 . V_450 = V_451 ;
V_129 -> V_132 . V_177 = V_4 -> V_177 . V_384 ;
V_129 -> V_132 . V_452 = F_258 ( V_4 -> V_9 . V_16 ) ;
V_129 -> V_132 . V_453 = ( T_2 ) V_4 -> V_9 . V_368 ;
if ( V_4 -> V_57 . V_306 )
V_129 -> V_132 . V_454 = 2 ;
else
V_129 -> V_132 . V_454 = 1 ;
V_129 -> V_132 . V_455 = 1 ;
V_129 -> V_132 . V_389 = V_449 ;
V_129 -> V_132 . V_456 = 0 ;
V_129 -> V_132 . V_457 = 0 ;
}
struct V_111 * F_260 ( struct V_3 * V_4 ,
enum V_458 V_459 , enum V_448 V_449 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
V_112 = F_92 ( & V_4 -> V_153 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
F_259 ( V_4 , V_129 , V_459 , V_449 ) ;
return V_112 ;
}
void F_261 ( struct V_3 * V_4 , struct V_111 * V_112 ,
char V_406 )
{
memcpy ( V_112 -> V_116 , V_460 , V_387 ) ;
memcpy ( F_262 ( V_112 -> V_116 ) , & V_406 , 1 ) ;
memcpy ( F_263 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_413 , V_369 ) ;
}
int F_264 ( struct V_3 * V_4 , struct V_111 * V_112 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_380 )
{
int V_34 ;
char V_406 ;
F_3 ( V_4 , 4 , L_203 ) ;
if ( V_4 -> V_57 . V_306 )
if ( V_4 -> V_9 . type == V_15 )
V_406 = V_409 ;
else
V_406 = V_410 ;
else
V_406 = V_411 ;
F_261 ( V_4 , V_112 , V_406 ) ;
V_34 = F_185 ( V_4 , V_461 ,
V_112 , F_186 , V_380 ) ;
if ( V_34 == - V_324 ) {
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
V_129 -> V_116 . V_462 . V_132 . V_138 ;
return 0 ;
}
static int F_267 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_3 ( V_4 , 3 , L_206 ) ;
V_129 = (struct V_128 * ) V_116 ;
if ( V_129 -> V_116 . V_462 . V_116 . V_463 . V_464 & 0x7f ) {
V_4 -> V_9 . V_16 =
V_129 -> V_116 . V_462 . V_116 . V_463 . V_464 ;
F_38 ( V_60 , 2 , L_207 , V_4 -> V_9 . V_16 ) ;
}
V_4 -> V_57 . V_465 . V_466 =
V_129 -> V_116 . V_462 . V_116 . V_463 . V_467 ;
return F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
}
static struct V_111 * F_268 ( struct V_3 * V_4 ,
T_1 V_133 , T_1 V_468 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
V_112 = F_260 ( V_4 , V_469 ,
V_390 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_129 -> V_116 . V_462 . V_132 . V_470 = V_468 ;
V_129 -> V_116 . V_462 . V_132 . V_471 = V_133 ;
V_129 -> V_116 . V_462 . V_132 . V_472 = 1 ;
V_129 -> V_116 . V_462 . V_132 . V_473 = 1 ;
return V_112 ;
}
int F_269 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
F_3 ( V_4 , 3 , L_208 ) ;
V_112 = F_268 ( V_4 , V_474 ,
sizeof( struct V_475 ) ) ;
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
case V_476 :
case V_477 :
F_35 ( V_60 , 2 , L_210 ) ;
V_4 -> V_57 . V_478 . V_466 |= V_479 ;
V_4 -> V_57 . V_480 . V_466 |= V_479 ;
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
if ( V_129 -> V_132 . V_389 == V_390 ) {
V_4 -> V_57 . V_478 . V_466 = V_129 -> V_132 . V_456 ;
V_4 -> V_57 . V_478 . V_481 = V_129 -> V_132 . V_457 ;
} else if ( V_129 -> V_132 . V_389 == V_482 ) {
V_4 -> V_57 . V_480 . V_466 = V_129 -> V_132 . V_456 ;
V_4 -> V_57 . V_480 . V_481 = V_129 -> V_132 . V_457 ;
} else
F_62 ( 1 , L_213
L_214 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
return 0 ;
}
int F_271 ( struct V_3 * V_4 , enum V_448 V_449 )
{
int V_34 ;
struct V_111 * V_112 ;
F_38 ( V_60 , 2 , L_215 , V_449 ) ;
V_112 = F_260 ( V_4 , V_483 , V_449 ) ;
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
V_4 -> V_9 . V_484 = V_129 -> V_116 . V_485 . V_486 ;
return 0 ;
}
static int F_273 ( struct V_3 * V_4 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_35 ( V_60 , 2 , L_217 ) ;
V_112 = F_260 ( V_4 , V_137 , 0 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_129 -> V_116 . V_485 . V_487 = 16 ;
V_129 -> V_116 . V_485 . V_488 = V_489 ;
return F_264 ( V_4 , V_112 , F_272 , NULL ) ;
}
static void F_274 ( struct V_3 * V_4 , struct V_490 * V_491 )
{
unsigned long V_9 = F_275 ( V_46 ) ;
struct V_492 * V_493 = (struct V_492 * ) V_9 ;
struct V_494 * V_495 = (struct V_494 * ) V_9 ;
struct V_362 V_496 ;
int V_372 ;
V_491 -> V_141 = V_4 -> V_9 . V_141 ;
F_173 ( F_147 ( V_4 ) , & V_496 ) ;
V_491 -> V_497 = V_496 . V_497 ;
V_491 -> V_370 = V_496 . V_370 ;
if ( ! V_9 )
return;
V_372 = F_276 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_372 >= 2 ) && ( F_276 ( V_493 , 2 , 2 , 2 ) == 0 ) )
V_491 -> V_498 = V_493 -> V_499 ;
if ( ( V_372 >= 3 ) && ( F_276 ( V_495 , 3 , 2 , 2 ) == 0 ) ) {
F_277 ( V_495 -> V_500 [ 0 ] . V_501 , sizeof( V_495 -> V_500 [ 0 ] . V_501 ) ) ;
memcpy ( V_491 -> V_502 , V_495 -> V_500 [ 0 ] . V_501 , sizeof( V_491 -> V_502 ) ) ;
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
int F_279 ( struct V_3 * V_4 , enum V_503 V_504 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_35 ( V_60 , 2 , L_219 ) ;
V_112 = F_260 ( V_4 , V_137 , 0 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_129 -> V_116 . V_485 . V_487 = 80 ;
V_129 -> V_116 . V_485 . V_488 = V_505 ;
V_129 -> V_116 . V_485 . type = 1 ;
V_129 -> V_116 . V_485 . V_504 = V_504 ;
switch ( V_504 ) {
case V_506 :
V_129 -> V_116 . V_485 . V_57 = 0x0003 ;
V_129 -> V_116 . V_485 . V_486 = 0x00010000 +
sizeof( struct V_490 ) ;
F_274 ( V_4 ,
(struct V_490 * ) V_129 -> V_116 . V_485 . V_507 ) ;
break;
case V_508 :
V_129 -> V_116 . V_485 . V_57 = 0x0001 ;
break;
case V_509 :
break;
}
return F_264 ( V_4 , V_112 , F_278 , NULL ) ;
}
int F_280 ( struct V_3 * V_4 , struct V_64 * V_228 ,
unsigned int V_510 , const char * V_511 )
{
if ( V_510 ) {
F_3 ( V_4 , 2 , V_511 ) ;
F_46 ( V_4 , 2 , L_220 ,
V_228 -> V_242 [ 15 ] . V_243 ) ;
F_46 ( V_4 , 2 , L_221 ,
V_228 -> V_242 [ 14 ] . V_243 ) ;
F_46 ( V_4 , 2 , L_222 , V_510 ) ;
if ( ( V_228 -> V_242 [ 15 ] . V_243 ) == 0x12 ) {
V_4 -> V_512 . V_513 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void V_295 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_254 . V_2 ) ;
F_46 ( V_4 , 2 , L_223 , V_4 -> V_514 ) ;
F_281 ( V_4 , V_4 -> V_514 ) ;
}
void F_281 ( struct V_3 * V_4 , int V_164 )
{
struct V_71 * V_110 = V_4 -> V_43 . V_255 ;
struct V_302 * V_515 ;
int V_162 ;
int V_41 ;
int V_34 ;
int V_516 = 0 ;
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
V_516 ++ ;
}
}
if ( V_516 < V_162 ) {
F_54 ( & V_4 -> V_517 , 3 ) ;
V_162 = V_516 ;
} else {
F_283 ( & V_4 -> V_517 , - 1 , 0 ) ;
}
if ( ! V_162 ) {
V_41 = 0 ;
F_249 (lh, &card->qdio.in_buf_pool.entry_list)
V_41 ++ ;
if ( V_41 == V_4 -> V_43 . V_56 . V_45 ) {
F_3 ( V_4 , 2 , L_224 ) ;
V_4 -> V_514 = V_164 ;
F_284 (
& V_4 -> V_254 ,
V_518 ) ;
}
return;
}
if ( V_4 -> V_57 . V_273 ) {
V_4 -> V_437 . V_519 ++ ;
V_4 -> V_437 . V_520 =
F_285 () ;
}
V_34 = F_36 ( F_37 ( V_4 ) , V_66 , 0 ,
V_110 -> V_65 , V_162 ) ;
if ( V_4 -> V_57 . V_273 )
V_4 -> V_437 . V_521 +=
F_285 () -
V_4 -> V_437 . V_520 ;
if ( V_34 ) {
F_3 ( V_4 , 2 , L_225 ) ;
}
V_110 -> V_65 = ( V_110 -> V_65 + V_162 ) %
V_63 ;
}
}
static int F_286 ( struct V_3 * V_4 ,
struct V_95 * V_74 , unsigned int V_522 )
{
int V_81 = V_74 -> V_74 -> V_242 [ 15 ] . V_243 ;
F_3 ( V_4 , 6 , L_226 ) ;
if ( V_4 -> V_9 . type == V_12 ) {
if ( V_81 == 0 ) {
V_522 = 0 ;
} else {
V_522 = 1 ;
}
}
F_280 ( V_4 , V_74 -> V_74 , V_522 , L_227 ) ;
if ( ! V_522 )
return V_523 ;
if ( ( V_81 >= 15 ) && ( V_81 <= 31 ) )
return V_524 ;
F_3 ( V_4 , 1 , L_228 ) ;
F_46 ( V_4 , 1 , L_229 ,
( V_181 ) V_522 , ( V_279 ) V_81 ) ;
return V_525 ;
}
static void F_287 ( struct V_90 * V_110 )
{
if ( ! V_110 -> V_444 ) {
if ( F_45 ( & V_110 -> V_445 )
>= V_526 ) {
F_3 ( V_110 -> V_4 , 6 , L_230 ) ;
if ( V_110 -> V_4 -> V_57 . V_273 )
V_110 -> V_4 -> V_437 . V_527 ++ ;
V_110 -> V_444 = 1 ;
}
}
}
static int F_288 ( struct V_90 * V_110 )
{
struct V_95 * V_74 ;
int V_528 = 0 ;
if ( V_110 -> V_444 ) {
if ( F_45 ( & V_110 -> V_445 )
<= V_529 ) {
F_3 ( V_110 -> V_4 , 6 , L_231 ) ;
if ( V_110 -> V_4 -> V_57 . V_273 )
V_110 -> V_4 -> V_437 . V_530 ++ ;
V_110 -> V_444 = 0 ;
V_74 = V_110 -> V_73 [ V_110 -> V_443 ] ;
if ( ( F_45 ( & V_74 -> V_52 ) ==
V_246 ) &&
( V_74 -> V_252 > 0 ) ) {
F_54 ( & V_74 -> V_52 ,
V_106 ) ;
V_528 ++ ;
V_110 -> V_443 =
( V_110 -> V_443 + 1 ) %
V_63 ;
}
}
}
return V_528 ;
}
static int F_289 ( struct V_90 * V_110 )
{
struct V_95 * V_74 ;
V_74 = V_110 -> V_73 [ V_110 -> V_443 ] ;
if ( ( F_45 ( & V_74 -> V_52 ) == V_246 ) &&
( V_74 -> V_252 > 0 ) ) {
F_54 ( & V_74 -> V_52 , V_106 ) ;
V_110 -> V_443 =
( V_110 -> V_443 + 1 ) % V_63 ;
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
unsigned int V_531 ;
for ( V_41 = V_164 ; V_41 < V_164 + V_162 ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
V_228 = V_110 -> V_73 [ V_92 ] ;
V_228 -> V_74 -> V_242 [ V_228 -> V_252 - 1 ] . V_251 |=
V_442 ;
if ( V_110 -> V_79 )
V_110 -> V_79 [ V_92 ] . V_420 = V_228 ;
if ( V_110 -> V_4 -> V_9 . type == V_12 )
continue;
if ( ! V_110 -> V_444 ) {
if ( ( F_45 ( & V_110 -> V_445 ) >=
( V_526 -
V_532 ) ) &&
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
V_110 -> V_4 -> V_6 -> V_533 = V_386 ;
if ( V_110 -> V_4 -> V_57 . V_273 ) {
V_110 -> V_4 -> V_437 . V_534 ++ ;
V_110 -> V_4 -> V_437 . V_535 =
F_285 () ;
}
V_531 = V_536 ;
if ( F_45 ( & V_110 -> V_245 ) )
V_531 |= V_537 ;
V_34 = F_36 ( F_37 ( V_110 -> V_4 ) , V_531 ,
V_110 -> V_425 , V_164 , V_162 ) ;
if ( V_110 -> V_4 -> V_57 . V_273 )
V_110 -> V_4 -> V_437 . V_538 +=
F_285 () -
V_110 -> V_4 -> V_437 . V_535 ;
F_291 ( V_162 , & V_110 -> V_445 ) ;
if ( V_34 ) {
V_110 -> V_4 -> V_512 . V_539 += V_162 ;
if ( V_34 == - V_540 )
return;
F_3 ( V_110 -> V_4 , 2 , L_232 ) ;
F_46 ( V_110 -> V_4 , 2 , L_233 , V_110 -> V_425 ) ;
F_46 ( V_110 -> V_4 , 2 , L_234 , V_164 ) ;
F_46 ( V_110 -> V_4 , 2 , L_235 , V_162 ) ;
F_46 ( V_110 -> V_4 , 2 , L_165 , V_34 ) ;
F_66 ( V_110 -> V_4 ) ;
return;
}
if ( V_110 -> V_4 -> V_57 . V_273 )
V_110 -> V_4 -> V_437 . V_541 += V_162 ;
}
static void F_292 ( struct V_90 * V_110 )
{
int V_164 ;
int V_542 = 0 ;
int V_543 = 0 ;
if ( ( F_45 ( & V_110 -> V_445 ) <= V_529 ) ||
! F_45 ( & V_110 -> V_245 ) ) {
if ( F_124 ( & V_110 -> V_52 , V_544 ) ==
V_446 ) {
F_293 ( V_110 -> V_4 -> V_6 ) ;
V_164 = V_110 -> V_443 ;
V_543 = V_110 -> V_444 ;
F_294 () ;
V_542 += F_288 ( V_110 ) ;
if ( ! V_542 &&
! F_45 ( & V_110 -> V_245 ) )
V_542 +=
F_289 ( V_110 ) ;
if ( V_110 -> V_4 -> V_57 . V_273 &&
V_543 )
V_110 -> V_4 -> V_437 . V_545 +=
V_542 ;
if ( V_542 )
F_290 ( V_110 , V_164 , V_542 ) ;
F_54 ( & V_110 -> V_52 , V_446 ) ;
}
}
}
void F_295 ( struct V_189 * V_118 , int V_110 ,
unsigned long V_546 )
{
struct V_3 * V_4 = (struct V_3 * ) V_546 ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> V_29 & V_547 ) )
F_296 ( & V_4 -> V_548 ) ;
}
int F_297 ( struct V_3 * V_4 , enum V_549 V_58 )
{
int V_34 ;
if ( V_4 -> V_57 . V_58 == V_550 ) {
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
unsigned int V_522 ,
unsigned int V_110 , int V_551 , int V_162 ) {
struct V_71 * V_58 = V_4 -> V_43 . V_61 ;
int V_41 ;
int V_34 ;
if ( ! F_58 ( V_4 , V_110 ) )
goto V_68;
F_46 ( V_4 , 5 , L_236 , V_551 ) ;
F_46 ( V_4 , 5 , L_237 , V_162 ) ;
F_46 ( V_4 , 5 , L_238 , V_522 ) ;
if ( V_522 ) {
F_293 ( V_4 -> V_6 ) ;
F_66 ( V_4 ) ;
goto V_68;
}
if ( V_4 -> V_57 . V_273 ) {
V_4 -> V_437 . V_552 ++ ;
V_4 -> V_437 . V_553 = F_285 () ;
}
for ( V_41 = V_551 ; V_41 < V_551 + V_162 ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
struct V_64 * V_74 = & V_58 -> V_62 [ V_92 ] ;
int V_554 ;
V_554 = 0 ;
while ( V_74 -> V_242 [ V_554 ] . V_247 ) {
unsigned long V_102 ;
V_102 = ( unsigned long ) V_74 -> V_242 [ V_554 ] . V_247 ;
F_51 ( V_4 , V_102 ) ;
V_74 -> V_242 [ V_554 ] . V_247 = NULL ;
V_74 -> V_242 [ V_554 ] . V_251 = 0 ;
V_74 -> V_242 [ V_554 ] . V_243 = 0 ;
V_74 -> V_242 [ V_554 ] . V_250 = 0 ;
++ V_554 ;
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
if ( V_4 -> V_57 . V_273 ) {
int V_555 = F_285 () ;
V_555 -= V_4 -> V_437 . V_553 ;
V_4 -> V_437 . V_556 += V_555 ;
}
V_68:
return;
}
void F_300 ( struct V_189 * V_118 , unsigned int V_522 ,
unsigned int V_110 , int V_557 , int V_162 ,
unsigned long V_546 )
{
struct V_3 * V_4 = (struct V_3 * ) V_546 ;
F_46 ( V_4 , 2 , L_241 , V_110 ) ;
F_46 ( V_4 , 2 , L_242 , V_522 ) ;
if ( F_58 ( V_4 , V_110 ) )
F_298 ( V_4 , V_522 , V_110 , V_557 , V_162 ) ;
else if ( V_522 )
F_66 ( V_4 ) ;
}
void F_301 ( struct V_189 * V_118 ,
unsigned int V_510 , int V_558 , int V_551 ,
int V_162 , unsigned long V_546 )
{
struct V_3 * V_4 = (struct V_3 * ) V_546 ;
struct V_90 * V_110 = V_4 -> V_43 . V_78 [ V_558 ] ;
struct V_95 * V_74 ;
int V_41 ;
F_3 ( V_4 , 6 , L_243 ) ;
if ( V_510 & V_559 ) {
F_3 ( V_4 , 2 , L_244 ) ;
F_293 ( V_4 -> V_6 ) ;
F_66 ( V_4 ) ;
return;
}
if ( V_4 -> V_57 . V_273 ) {
V_4 -> V_437 . V_560 ++ ;
V_4 -> V_437 . V_561 =
F_285 () ;
}
for ( V_41 = V_551 ; V_41 < ( V_551 + V_162 ) ; ++ V_41 ) {
int V_92 = V_41 % V_63 ;
V_74 = V_110 -> V_73 [ V_92 ] ;
F_286 ( V_4 , V_74 , V_510 ) ;
if ( V_110 -> V_79 &&
( V_110 -> V_79 [ V_92 ] . V_29 &
V_562 ) != 0 ) {
F_48 ( V_4 -> V_57 . V_58 != V_59 ) ;
if ( F_53 ( & V_74 -> V_52 ,
V_106 ,
V_108 ) ==
V_106 ) {
F_55 ( V_110 , V_74 ,
V_563 ) ;
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
F_303 ( V_162 , & V_110 -> V_445 ) ;
if ( V_4 -> V_9 . type != V_12 )
F_292 ( V_110 ) ;
F_299 ( V_110 -> V_4 -> V_6 ) ;
if ( V_4 -> V_57 . V_273 )
V_4 -> V_437 . V_564 += F_285 () -
V_4 -> V_437 . V_561 ;
}
int F_304 ( struct V_3 * V_4 , struct V_229 * V_230 ,
int V_565 , int V_566 )
{
T_3 * V_567 ;
V_279 V_568 ;
if ( V_566 && V_4 -> V_9 . V_318 )
return V_4 -> V_9 . V_318 &
( V_4 -> V_43 . V_76 - 1 ) ;
switch ( V_4 -> V_43 . V_308 ) {
case V_569 :
case V_570 :
switch ( V_565 ) {
case 4 :
V_568 = F_305 ( F_306 ( V_230 ) ) ;
break;
case 6 :
V_568 = F_307 ( F_308 ( V_230 ) ) ;
break;
default:
return V_4 -> V_43 . V_257 ;
}
if ( V_4 -> V_43 . V_308 == V_570 )
return ~ V_568 >> 6 & 3 ;
if ( V_568 & V_571 )
return 3 ;
if ( V_568 & V_572 )
return 2 ;
if ( V_568 & V_573 )
return 1 ;
if ( V_568 & V_574 )
return 0 ;
break;
case V_575 :
if ( V_230 -> V_576 > 5 )
return 0 ;
return ~ V_230 -> V_576 >> 1 & 3 ;
case V_577 :
V_567 = & ( (struct V_578 * ) V_230 -> V_116 ) -> V_579 ;
if ( * V_567 == V_580 )
return ~ * ( V_567 + 1 ) >> ( V_581 + 1 ) & 3 ;
break;
default:
break;
}
return V_4 -> V_43 . V_257 ;
}
int F_309 ( struct V_229 * V_230 )
{
int V_172 , V_250 , V_554 , V_48 = 0 ;
struct V_582 * V_583 ;
char * V_116 ;
for ( V_172 = 0 ; V_172 < F_310 ( V_230 ) -> V_584 ; V_172 ++ ) {
V_583 = & F_310 ( V_230 ) -> V_585 [ V_172 ] ;
V_116 = ( char * ) F_311 ( F_312 ( V_583 ) ) +
V_583 -> V_586 ;
V_250 = V_583 -> V_587 ;
V_554 = F_313 ( ( unsigned long ) V_116 + V_250 - 1 ) -
F_314 ( ( unsigned long ) V_116 ) ;
V_48 += V_554 ;
}
return V_48 ;
}
int F_315 ( struct V_3 * V_4 ,
struct V_229 * V_230 , int V_588 )
{
int V_589 = V_230 -> V_158 - V_230 -> V_590 ;
int V_591 = F_313 ( ( unsigned long ) V_230 -> V_116 + V_589 - 1 ) -
F_314 ( ( unsigned long ) V_230 -> V_116 ) ;
V_591 += F_309 ( V_230 ) ;
if ( ( V_591 + V_588 ) > F_28 ( V_4 ) ) {
F_62 ( 2 , L_248
L_249 ,
( V_591 + V_588 ) , V_230 -> V_158 ) ;
return 0 ;
}
return V_591 ;
}
int F_316 ( struct V_229 * V_230 , struct V_592 * * V_132 , int V_158 )
{
int V_593 , V_594 , V_595 ;
if ( ( ( unsigned long ) V_230 -> V_116 & V_596 ) !=
( ( ( unsigned long ) V_230 -> V_116 + V_158 - 1 ) & V_596 ) ) {
V_593 = F_317 ( V_230 ) ;
V_594 = V_404 - ( ( unsigned long ) V_230 -> V_116 % V_404 ) ;
V_595 = V_158 - V_594 ;
if ( V_595 > V_593 )
return 1 ;
memmove ( V_230 -> V_116 - V_595 , V_230 -> V_116 , V_230 -> V_158 - V_230 -> V_590 ) ;
V_230 -> V_116 -= V_595 ;
V_230 -> V_597 -= V_595 ;
* V_132 = (struct V_592 * ) V_230 -> V_116 ;
F_62 ( 2 , L_250 , V_158 , V_595 ) ;
}
return 0 ;
}
static inline void F_318 ( struct V_229 * V_230 ,
struct V_64 * V_74 , int V_598 , int * V_252 ,
int V_179 )
{
int V_250 = V_230 -> V_158 - V_230 -> V_590 ;
int V_599 ;
int V_242 ;
char * V_116 ;
int V_600 , V_172 ;
struct V_582 * V_583 ;
V_242 = * V_252 ;
V_116 = V_230 -> V_116 ;
V_600 = ( V_598 == 0 ? 1 : 0 ) ;
if ( V_179 >= 0 ) {
V_116 = V_230 -> V_116 + V_179 ;
V_250 -= V_179 ;
V_600 = 0 ;
}
while ( V_250 > 0 ) {
V_599 = V_404 - ( ( unsigned long ) V_116 % V_404 ) ;
if ( V_250 < V_599 )
V_599 = V_250 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_599 ;
V_250 -= V_599 ;
if ( ! V_250 ) {
if ( V_600 )
if ( F_310 ( V_230 ) -> V_584 )
V_74 -> V_242 [ V_242 ] . V_251 =
V_601 ;
else
V_74 -> V_242 [ V_242 ] . V_251 = 0 ;
else
V_74 -> V_242 [ V_242 ] . V_251 =
V_602 ;
} else {
if ( V_600 )
V_74 -> V_242 [ V_242 ] . V_251 =
V_601 ;
else
V_74 -> V_242 [ V_242 ] . V_251 =
V_602 ;
}
V_116 += V_599 ;
V_242 ++ ;
V_600 = 0 ;
}
for ( V_172 = 0 ; V_172 < F_310 ( V_230 ) -> V_584 ; V_172 ++ ) {
V_583 = & F_310 ( V_230 ) -> V_585 [ V_172 ] ;
V_116 = ( char * ) F_311 ( F_312 ( V_583 ) ) +
V_583 -> V_586 ;
V_250 = V_583 -> V_587 ;
while ( V_250 > 0 ) {
V_599 = V_404 -
( ( unsigned long ) V_116 % V_404 ) ;
if ( V_250 < V_599 )
V_599 = V_250 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_599 ;
V_74 -> V_242 [ V_242 ] . V_251 =
V_602 ;
V_250 -= V_599 ;
V_116 += V_599 ;
V_242 ++ ;
}
}
if ( V_74 -> V_242 [ V_242 - 1 ] . V_251 )
V_74 -> V_242 [ V_242 - 1 ] . V_251 = V_603 ;
* V_252 = V_242 ;
}
static inline int F_319 ( struct V_90 * V_110 ,
struct V_95 * V_228 , struct V_229 * V_230 ,
struct V_592 * V_132 , int V_179 , int V_604 )
{
struct V_64 * V_74 ;
int V_542 = 0 , V_605 , V_606 = 0 ;
V_74 = V_228 -> V_74 ;
F_70 ( & V_230 -> V_239 ) ;
F_320 ( & V_228 -> V_231 , V_230 ) ;
if ( V_132 -> V_132 . V_607 . V_313 == V_608 ) {
int V_242 = V_228 -> V_252 ;
V_605 = sizeof( struct V_609 ) +
( (struct V_609 * ) V_132 ) -> V_486 . V_610 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_230 -> V_116 ;
V_74 -> V_242 [ V_242 ] . V_250 = V_605 ;
V_74 -> V_242 [ V_242 ] . V_251 = V_601 ;
V_228 -> V_252 ++ ;
V_230 -> V_116 += V_605 ;
V_230 -> V_158 -= V_605 ;
V_606 = 1 ;
}
if ( V_179 >= 0 ) {
int V_242 = V_228 -> V_252 ;
V_74 -> V_242 [ V_242 ] . V_247 = V_132 ;
V_74 -> V_242 [ V_242 ] . V_250 = sizeof( struct V_592 ) +
V_604 ;
V_74 -> V_242 [ V_242 ] . V_251 = V_601 ;
V_228 -> V_248 [ V_242 ] = 1 ;
V_228 -> V_252 ++ ;
}
F_318 ( V_230 , V_74 , V_606 ,
( int * ) & V_228 -> V_252 , V_179 ) ;
if ( ! V_110 -> V_444 ) {
F_3 ( V_110 -> V_4 , 6 , L_251 ) ;
F_54 ( & V_228 -> V_52 , V_106 ) ;
V_542 = 1 ;
} else {
F_3 ( V_110 -> V_4 , 6 , L_252 ) ;
if ( V_110 -> V_4 -> V_57 . V_273 )
V_110 -> V_4 -> V_437 . V_611 ++ ;
if ( V_228 -> V_252 >=
F_28 ( V_110 -> V_4 ) ) {
F_54 ( & V_228 -> V_52 , V_106 ) ;
V_542 = 1 ;
}
}
return V_542 ;
}
int F_321 ( struct V_3 * V_4 ,
struct V_90 * V_110 , struct V_229 * V_230 ,
struct V_592 * V_132 , int V_591 ,
int V_179 , int V_604 )
{
struct V_95 * V_74 ;
int V_164 ;
while ( F_53 ( & V_110 -> V_52 , V_446 ,
V_612 ) != V_446 ) ;
V_164 = V_110 -> V_443 ;
V_74 = V_110 -> V_73 [ V_110 -> V_443 ] ;
if ( F_45 ( & V_74 -> V_52 ) != V_246 )
goto V_68;
V_110 -> V_443 = ( V_110 -> V_443 + 1 ) %
V_63 ;
F_54 ( & V_110 -> V_52 , V_446 ) ;
F_319 ( V_110 , V_74 , V_230 , V_132 , V_179 , V_604 ) ;
F_290 ( V_110 , V_164 , 1 ) ;
return 0 ;
V_68:
F_54 ( & V_110 -> V_52 , V_446 ) ;
return - V_613 ;
}
int F_322 ( struct V_3 * V_4 , struct V_90 * V_110 ,
struct V_229 * V_230 , struct V_592 * V_132 ,
int V_591 )
{
struct V_95 * V_74 ;
int V_614 ;
int V_528 = 0 ;
int V_444 = 0 ;
int V_38 ;
int V_34 = 0 ;
while ( F_53 ( & V_110 -> V_52 , V_446 ,
V_612 ) != V_446 ) ;
V_614 = V_110 -> V_443 ;
V_74 = V_110 -> V_73 [ V_110 -> V_443 ] ;
if ( F_45 ( & V_74 -> V_52 ) != V_246 ) {
F_54 ( & V_110 -> V_52 , V_446 ) ;
return - V_613 ;
}
F_287 ( V_110 ) ;
if ( V_110 -> V_444 ) {
V_444 = 1 ;
if ( ( F_28 ( V_4 ) -
V_74 -> V_252 ) < V_591 ) {
F_54 ( & V_74 -> V_52 , V_106 ) ;
V_528 ++ ;
V_110 -> V_443 =
( V_110 -> V_443 + 1 ) %
V_63 ;
V_74 = V_110 -> V_73 [ V_110 -> V_443 ] ;
if ( F_45 ( & V_74 -> V_52 ) !=
V_246 ) {
F_290 ( V_110 , V_614 ,
V_528 ) ;
F_54 ( & V_110 -> V_52 ,
V_446 ) ;
return - V_613 ;
}
}
}
V_38 = F_319 ( V_110 , V_74 , V_230 , V_132 , - 1 , 0 ) ;
V_110 -> V_443 = ( V_110 -> V_443 + V_38 ) %
V_63 ;
V_528 += V_38 ;
if ( V_528 )
F_290 ( V_110 , V_614 , V_528 ) ;
else if ( ! F_45 ( & V_110 -> V_245 ) )
F_124 ( & V_110 -> V_52 , V_544 ) ;
while ( F_323 ( & V_110 -> V_52 ) ) {
V_528 = 0 ;
V_614 = V_110 -> V_443 ;
V_528 += F_288 ( V_110 ) ;
if ( ! V_528 && ! F_45 ( & V_110 -> V_245 ) )
V_528 += F_289 ( V_110 ) ;
if ( V_528 )
F_290 ( V_110 , V_614 , V_528 ) ;
}
if ( V_110 -> V_4 -> V_57 . V_273 && V_444 )
V_110 -> V_4 -> V_437 . V_545 += V_528 ;
return V_34 ;
}
static int F_324 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_475 * V_615 ;
F_3 ( V_4 , 4 , L_253 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_615 = & ( V_129 -> V_116 . V_462 ) ;
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
if ( V_129 -> V_132 . V_138 ) {
F_46 ( V_4 , 4 , L_254 , V_129 -> V_132 . V_138 ) ;
V_615 -> V_116 . V_616 = V_617 ;
}
V_4 -> V_9 . V_618 = V_615 -> V_116 . V_616 ;
return 0 ;
}
void F_325 ( struct V_3 * V_4 )
{
enum V_619 V_616 ;
struct V_620 * V_6 = V_4 -> V_6 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_255 ) ;
if ( ( ( V_6 -> V_29 & V_621 ) &&
( V_4 -> V_9 . V_618 == V_622 ) ) ||
( ! ( V_6 -> V_29 & V_621 ) &&
( V_4 -> V_9 . V_618 == V_617 ) ) )
return;
V_616 = V_617 ;
if ( V_6 -> V_29 & V_621 )
V_616 = V_622 ;
F_46 ( V_4 , 4 , L_256 , V_616 ) ;
V_112 = F_268 ( V_4 , V_623 ,
sizeof( struct V_475 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_129 -> V_116 . V_462 . V_116 . V_616 = V_616 ;
F_264 ( V_4 , V_112 , F_324 , NULL ) ;
}
int F_326 ( struct V_620 * V_6 , int V_624 )
{
struct V_3 * V_4 ;
char V_431 [ 15 ] ;
V_4 = V_6 -> V_625 ;
F_3 ( V_4 , 4 , L_257 ) ;
sprintf ( V_431 , L_258 , V_624 ) ;
F_3 ( V_4 , 4 , V_431 ) ;
if ( V_624 < 64 )
return - V_402 ;
if ( V_624 > 65535 )
return - V_402 ;
if ( ( ! F_327 ( V_4 , V_626 ) ) &&
( ! F_203 ( V_4 , V_624 ) ) )
return - V_402 ;
V_6 -> V_400 = V_624 ;
return 0 ;
}
struct V_627 * F_328 ( struct V_620 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_625 ;
F_3 ( V_4 , 5 , L_259 ) ;
return & V_4 -> V_512 ;
}
static int F_329 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_260 ) ;
V_129 = (struct V_128 * ) V_116 ;
if ( ! V_4 -> V_57 . V_306 ||
! ( V_4 -> V_9 . V_628 & V_629 ) ) {
memcpy ( V_4 -> V_6 -> V_630 ,
& V_129 -> V_116 . V_462 . V_116 . V_631 . V_247 ,
V_632 ) ;
V_4 -> V_9 . V_628 |= V_629 ;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
int F_330 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
F_3 ( V_4 , 4 , L_261 ) ;
V_112 = F_268 ( V_4 , V_633 ,
sizeof( struct V_475 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_129 -> V_116 . V_462 . V_116 . V_631 . V_129 = V_634 ;
V_129 -> V_116 . V_462 . V_116 . V_631 . V_635 = V_632 ;
memcpy ( & V_129 -> V_116 . V_462 . V_116 . V_631 . V_247 ,
V_4 -> V_6 -> V_630 , V_632 ) ;
V_34 = F_264 ( V_4 , V_112 , F_329 ,
NULL ) ;
return V_34 ;
}
static int F_331 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_636 * V_637 ;
int V_638 = * ( int * ) V_124 -> V_383 ;
F_3 ( V_4 , 4 , L_262 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_637 = & V_129 -> V_116 . V_462 . V_116 . V_639 ;
F_38 ( V_60 , 2 , L_262 ) ;
F_38 ( V_60 , 2 , L_191 , V_4 -> V_7 -> V_6 . V_640 . V_501 ) ;
F_38 ( V_60 , 2 , L_263 ,
V_129 -> V_116 . V_462 . V_132 . V_138 ) ;
if ( V_129 -> V_116 . V_462 . V_132 . V_138 !=
V_641 )
F_62 ( 3 , L_264 ,
V_4 -> V_7 -> V_6 . V_640 . V_501 ,
V_637 -> V_642 ,
V_129 -> V_116 . V_462 . V_132 . V_138 ) ;
switch ( V_129 -> V_116 . V_462 . V_132 . V_138 ) {
case V_641 :
if ( V_4 -> V_57 . V_276 == V_277 ) {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_265 ) ;
} else {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_266 ) ;
}
break;
case V_643 :
F_62 ( 2 , L_267
L_268 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_645 :
F_62 ( 2 , L_269
L_270 , F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_646 :
F_41 ( & V_4 -> V_7 -> V_6 , L_271
L_272 ) ;
break;
case V_647 :
F_41 ( & V_4 -> V_7 -> V_6 ,
L_273
L_274 ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_648 :
F_41 ( & V_4 -> V_7 -> V_6 ,
L_275 ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_649 :
F_41 ( & V_4 -> V_7 -> V_6 , L_276
L_277 ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_650 :
F_41 ( & V_4 -> V_7 -> V_6 , L_278
L_279 ) ;
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
case V_651 :
F_61 ( & V_4 -> V_7 -> V_6 , L_280
L_281 ) ;
break;
default:
if ( V_638 )
V_4 -> V_57 . V_276 = V_4 -> V_57 . V_644 ;
break;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
static int F_332 ( struct V_3 * V_4 ,
enum V_652 V_276 , int V_638 )
{
int V_34 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_636 * V_637 ;
F_3 ( V_4 , 4 , L_282 ) ;
F_38 ( V_60 , 2 , L_282 ) ;
F_38 ( V_60 , 2 , L_191 , V_4 -> V_7 -> V_6 . V_640 . V_501 ) ;
V_112 = F_268 ( V_4 , V_653 ,
sizeof( struct V_654 ) +
sizeof( struct V_636 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_637 = & V_129 -> V_116 . V_462 . V_116 . V_639 ;
V_637 -> V_642 = V_276 ;
V_34 = F_264 ( V_4 , V_112 , F_331 ,
& V_638 ) ;
F_38 ( V_60 , 2 , L_263 , V_34 ) ;
return V_34 ;
}
int F_333 ( struct V_3 * V_4 , int V_638 )
{
int V_34 = 0 ;
F_3 ( V_4 , 4 , L_283 ) ;
if ( ( V_4 -> V_9 . type == V_11 ||
V_4 -> V_9 . type == V_14 ) &&
F_334 ( V_4 , V_653 ) ) {
V_34 = F_332 ( V_4 ,
V_4 -> V_57 . V_276 , V_638 ) ;
if ( V_34 ) {
F_62 ( 3 ,
L_284 ,
V_4 -> V_7 -> V_6 . V_640 . V_501 ,
V_34 ) ;
V_34 = - V_339 ;
}
} else if ( V_4 -> V_57 . V_276 != V_277 ) {
V_4 -> V_57 . V_276 = V_277 ;
F_41 ( & V_4 -> V_7 -> V_6 , L_271
L_272 ) ;
V_34 = - V_339 ;
}
return V_34 ;
}
void F_335 ( struct V_620 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_625 ;
F_3 ( V_4 , 4 , L_285 ) ;
V_4 -> V_512 . V_539 ++ ;
F_66 ( V_4 ) ;
}
int F_336 ( struct V_620 * V_6 , int V_655 , int V_656 )
{
struct V_3 * V_4 = V_6 -> V_625 ;
int V_34 = 0 ;
switch ( V_656 ) {
case V_657 :
V_34 = V_658 ;
if ( ( V_4 -> V_9 . V_16 != V_19 ) &&
( V_4 -> V_9 . V_16 != V_659 ) &&
( V_4 -> V_9 . V_16 != V_20 ) )
V_34 |= V_660 ;
break;
case V_661 :
V_34 = V_662 | V_663 | V_664 |
V_665 | V_666 | V_667 | V_668 |
V_669 ;
break;
case V_670 :
V_34 = ( V_6 -> V_630 [ 0 ] << 16 ) | ( V_6 -> V_630 [ 1 ] << 8 ) |
V_6 -> V_630 [ 2 ] ;
V_34 = ( V_34 >> 5 ) & 0xFFFF ;
break;
case V_671 :
V_34 = ( V_6 -> V_630 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_672 :
V_34 = V_673 ;
break;
case V_674 :
V_34 = V_675 | V_676 | V_677 | V_678 |
V_679 | V_680 ;
break;
case V_681 :
break;
case V_682 :
break;
case V_683 :
break;
case V_684 :
break;
case V_685 :
V_34 = V_4 -> V_512 . V_686 ;
break;
case V_687 :
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
break;
case V_693 :
break;
default:
break;
}
return V_34 ;
}
static int F_337 ( struct V_3 * V_4 ,
struct V_111 * V_112 , int V_158 ,
int (* F_186)( struct V_3 * , struct V_123 * ,
unsigned long ) ,
void * V_380 )
{
V_181 V_694 , V_695 ;
F_3 ( V_4 , 4 , L_286 ) ;
memcpy ( V_112 -> V_116 , V_460 , V_387 ) ;
memcpy ( F_263 ( V_112 -> V_116 ) ,
& V_4 -> V_353 . V_413 , V_369 ) ;
V_694 = ( V_696 ) V_387 + V_158 ;
V_695 = ( V_696 ) V_158 ;
memcpy ( F_338 ( V_112 -> V_116 ) , & V_694 , 2 ) ;
memcpy ( F_339 ( V_112 -> V_116 ) , & V_695 , 2 ) ;
memcpy ( F_340 ( V_112 -> V_116 ) , & V_695 , 2 ) ;
memcpy ( F_341 ( V_112 -> V_116 ) , & V_695 , 2 ) ;
return F_185 ( V_4 , V_387 + V_158 , V_112 ,
F_186 , V_380 ) ;
}
static int F_342 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_697 )
{
struct V_128 * V_129 ;
struct V_698 * V_699 ;
struct V_700 * V_701 ;
unsigned char * V_116 ;
V_180 V_590 ;
F_3 ( V_4 , 3 , L_287 ) ;
V_129 = (struct V_128 * ) V_697 ;
V_116 = ( unsigned char * ) ( ( char * ) V_129 - V_124 -> V_179 ) ;
V_699 = (struct V_698 * ) V_124 -> V_383 ;
V_701 = & V_129 -> V_116 . V_462 . V_116 . V_701 ;
if ( V_129 -> V_132 . V_138 ) {
F_46 ( V_4 , 4 , L_288 , V_129 -> V_132 . V_138 ) ;
return 0 ;
}
if ( V_129 -> V_116 . V_462 . V_132 . V_138 ) {
V_129 -> V_132 . V_138 =
V_129 -> V_116 . V_462 . V_132 . V_138 ;
F_46 ( V_4 , 4 , L_289 , V_129 -> V_132 . V_138 ) ;
return 0 ;
}
V_590 = * ( ( V_180 * ) F_339 ( V_116 ) ) ;
if ( V_129 -> V_116 . V_462 . V_132 . V_473 == 1 )
V_590 -= ( V_180 ) ( ( char * ) & V_701 -> V_116 - ( char * ) V_129 ) ;
else
V_590 -= ( V_180 ) ( ( char * ) & V_701 -> V_702 - ( char * ) V_129 ) ;
if ( ( V_699 -> V_703 - V_699 -> V_704 ) < V_590 ) {
F_46 ( V_4 , 4 , L_290 , - V_47 ) ;
V_129 -> V_132 . V_138 = V_705 ;
return 0 ;
}
F_46 ( V_4 , 4 , L_291 ,
V_129 -> V_116 . V_462 . V_132 . V_472 ) ;
F_46 ( V_4 , 4 , L_292 ,
V_129 -> V_116 . V_462 . V_132 . V_473 ) ;
if ( V_129 -> V_116 . V_462 . V_132 . V_473 == 1 ) {
memcpy ( V_699 -> V_706 + V_699 -> V_704 ,
( char * ) V_701 ,
V_590 + F_343 ( struct V_700 , V_116 ) ) ;
V_699 -> V_704 += F_343 ( struct V_700 , V_116 ) ;
} else {
memcpy ( V_699 -> V_706 + V_699 -> V_704 ,
( char * ) & V_701 -> V_702 , V_590 ) ;
}
V_699 -> V_704 += V_590 ;
F_46 ( V_4 , 4 , L_293 ,
V_129 -> V_116 . V_462 . V_132 . V_472 ) ;
F_46 ( V_4 , 4 , L_294 ,
V_129 -> V_116 . V_462 . V_132 . V_473 ) ;
if ( V_129 -> V_116 . V_462 . V_132 . V_473 <
V_129 -> V_116 . V_462 . V_132 . V_472 )
return 1 ;
return 0 ;
}
int F_344 ( struct V_3 * V_4 , char T_4 * V_706 )
{
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_707 * V_708 ;
unsigned int V_709 ;
struct V_698 V_699 = { 0 , } ;
int V_34 = 0 ;
F_3 ( V_4 , 3 , L_295 ) ;
if ( V_4 -> V_9 . V_10 )
return - V_339 ;
if ( ( ! F_334 ( V_4 , V_710 ) ) &&
( ! V_4 -> V_57 . V_306 ) ) {
return - V_339 ;
}
if ( F_345 ( & V_709 , V_706 + sizeof( int ) , sizeof( int ) ) )
return - V_711 ;
if ( V_709 > ( V_117 - V_387 -
sizeof( struct V_712 ) -
sizeof( struct V_654 ) ) )
return - V_402 ;
V_708 = F_346 ( V_706 , V_709 + sizeof( struct V_713 ) ) ;
if ( F_109 ( V_708 ) ) {
F_3 ( V_4 , 2 , L_296 ) ;
return F_110 ( V_708 ) ;
}
V_699 . V_703 = V_708 -> V_132 . V_590 ;
V_699 . V_706 = F_26 ( V_699 . V_703 , V_46 ) ;
if ( ! V_699 . V_706 ) {
F_31 ( V_708 ) ;
return - V_47 ;
}
V_699 . V_704 = sizeof( struct V_713 ) ;
V_112 = F_268 ( V_4 , V_710 ,
V_714 + V_709 ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
memcpy ( & V_129 -> V_116 . V_462 . V_116 . V_701 , & V_708 -> V_129 , V_709 ) ;
V_34 = F_337 ( V_4 , V_112 , V_715 + V_709 ,
F_342 , ( void * ) & V_699 ) ;
if ( V_34 )
F_62 ( 2 , L_297 ,
F_75 ( V_4 ) , V_34 ) ;
else {
if ( F_347 ( V_706 , V_699 . V_706 , V_699 . V_703 ) )
V_34 = - V_711 ;
}
F_31 ( V_708 ) ;
F_31 ( V_699 . V_706 ) ;
return V_34 ;
}
static int F_348 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_716 * V_717 ;
char * V_718 ;
int V_719 ;
F_3 ( V_4 , 3 , L_298 ) ;
V_129 = (struct V_128 * ) V_116 ;
V_717 = (struct V_716 * ) V_124 -> V_383 ;
V_719 = V_129 -> V_116 . V_462 . V_132 . V_470 ;
V_718 = ( char * ) V_116 + 28 ;
if ( V_719 > ( V_717 -> V_720 - V_717 -> V_721 ) ) {
V_129 -> V_132 . V_138 = V_722 ;
return 0 ;
}
memcpy ( ( V_717 -> V_74 + V_717 -> V_721 ) , V_718 ,
V_719 ) ;
V_717 -> V_721 += V_719 ;
if ( V_129 -> V_116 . V_462 . V_132 . V_473 <
V_129 -> V_116 . V_462 . V_132 . V_472 )
return 1 ;
return 0 ;
}
int F_349 ( struct V_3 * V_4 , char T_4 * V_706 )
{
int V_34 = 0 ;
struct V_111 * V_112 ;
struct V_128 * V_129 ;
struct V_723 * V_724 ;
struct V_725 V_726 ;
struct V_716 V_717 ;
void T_4 * V_38 ;
F_3 ( V_4 , 3 , L_299 ) ;
if ( ! F_334 ( V_4 , V_727 ) ) {
V_34 = - V_339 ;
goto V_68;
}
if ( F_345 ( & V_726 , V_706 ,
sizeof( struct V_725 ) ) ) {
V_34 = - V_711 ;
goto V_68;
}
V_717 . V_720 = V_726 . V_720 ;
V_717 . V_721 = 0 ;
V_717 . V_74 = F_26 ( V_726 . V_720 , V_46 ) ;
if ( ! V_717 . V_74 ) {
V_34 = - V_47 ;
goto V_68;
}
V_112 = F_268 ( V_4 , V_727 ,
sizeof( struct V_654 ) +
sizeof( struct V_723 ) ) ;
V_129 = (struct V_128 * ) ( V_112 -> V_116 + V_387 ) ;
V_724 = & V_129 -> V_116 . V_462 . V_116 . V_728 ;
V_724 -> V_642 = V_726 . V_133 ;
V_34 = F_264 ( V_4 , V_112 , F_348 ,
& V_717 ) ;
if ( ! V_34 ) {
if ( F_350 () )
V_38 = F_351 ( V_726 . V_40 ) ;
else
V_38 = ( void T_4 * ) ( unsigned long ) V_726 . V_40 ;
if ( F_347 ( V_38 , V_717 . V_74 ,
V_717 . V_721 ) ) {
V_34 = - V_711 ;
goto V_729;
}
V_726 . V_721 = V_717 . V_721 ;
if ( F_347 ( V_706 , & V_726 ,
sizeof( struct V_725 ) ) )
V_34 = - V_711 ;
} else
if ( V_34 == V_722 )
V_34 = - V_711 ;
V_729:
F_31 ( V_717 . V_74 ) ;
V_68:
return V_34 ;
}
static int F_352 ( struct V_3 * V_4 ,
struct V_123 * V_124 , unsigned long V_116 )
{
struct V_128 * V_129 ;
struct V_730 * V_731 ;
struct V_732 * V_732 ;
F_3 ( V_4 , 2 , L_300 ) ;
V_732 = (struct V_732 * ) V_124 -> V_383 ;
V_129 = (struct V_128 * ) V_116 ;
V_731 = & V_129 -> V_116 . V_462 . V_116 . V_731 ;
if ( V_129 -> V_116 . V_462 . V_132 . V_138 == 0 ) {
V_732 -> V_733 = V_731 -> V_733 ;
V_732 -> V_734 = V_731 -> V_734 ;
V_732 -> V_735 = V_731 -> V_735 ;
}
F_266 ( V_4 , V_124 , ( unsigned long ) V_129 ) ;
return 0 ;
}
int V_730 ( struct V_3 * V_4 ,
struct V_732 * V_732 )
{
struct V_111 * V_112 ;
F_3 ( V_4 , 2 , L_301 ) ;
if ( ! F_334 ( V_4 , V_736 ) )
return - V_339 ;
V_112 = F_268 ( V_4 , V_736 ,
sizeof( struct V_654 ) ) ;
return F_264 ( V_4 , V_112 , F_352 ,
( void * ) V_732 ) ;
}
static inline int F_353 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_9 . type ) {
case V_12 :
return 2 ;
default:
return 0 ;
}
}
static void F_354 ( struct V_3 * V_4 )
{
int V_34 ;
int V_250 ;
char * V_345 ;
struct V_189 * V_737 ;
int V_738 = 0 ;
F_35 ( V_60 , 2 , L_302 ) ;
V_737 = F_37 ( V_4 ) ;
if ( ! V_737 -> V_739 ) {
V_738 = 1 ;
V_34 = F_355 ( V_737 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_68;
}
}
V_34 = F_159 ( V_4 , ( void * * ) & V_345 , & V_250 ) ;
if ( V_34 ) {
F_62 ( 2 , L_303 ,
F_63 ( & V_4 -> V_7 -> V_6 ) , V_34 ) ;
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_740;
}
F_162 ( V_4 , V_345 ) ;
if ( V_738 )
F_163 ( V_4 , V_345 ) ;
F_31 ( V_345 ) ;
V_34 = F_356 ( V_737 , & V_4 -> V_741 ) ;
if ( V_34 )
F_38 ( V_60 , 2 , L_188 , V_34 ) ;
F_38 ( V_60 , 2 , L_304 , V_4 -> V_741 . V_742 ) ;
F_38 ( V_60 , 2 , L_305 , V_4 -> V_741 . V_743 ) ;
F_38 ( V_60 , 2 , L_305 , V_4 -> V_741 . V_744 ) ;
F_38 ( V_60 , 2 , L_306 , V_4 -> V_741 . V_745 ) ;
if ( ! ( ( V_4 -> V_741 . V_742 != V_746 ) ||
( ( V_4 -> V_741 . V_743 & V_747 ) == 0 ) ||
( ( V_4 -> V_741 . V_744 & V_748 ) == 0 ) ) ) {
F_83 ( & V_4 -> V_7 -> V_6 ,
L_307 ) ;
} else {
V_4 -> V_57 . V_58 = V_550 ;
}
V_740:
if ( V_738 == 1 )
F_357 ( V_737 ) ;
V_68:
return;
}
static inline void F_358 ( struct V_3 * V_4 ,
struct V_64 * * V_749 ,
void (* * F_359) ( struct V_189 * , int , unsigned long ) ) {
int V_41 ;
if ( V_4 -> V_57 . V_58 == V_59 ) {
int V_179 = V_63 *
( V_4 -> V_43 . V_67 - 1 ) ;
V_41 = V_63 * ( V_4 -> V_43 . V_67 - 1 ) ;
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_749 [ V_179 + V_41 ] = (struct V_64 * )
F_302 ( V_4 -> V_43 . V_61 -> V_73 [ V_41 ] . V_74 ) ;
}
F_359 [ V_4 -> V_43 . V_67 - 1 ] = NULL ;
}
}
static int F_239 ( struct V_3 * V_4 )
{
struct V_750 V_751 ;
char * V_752 ;
struct V_64 * * V_749 ;
void (* * F_359) ( struct V_189 * , int , unsigned long );
struct V_64 * * V_753 ;
int V_41 , V_42 , V_754 ;
int V_34 = 0 ;
F_35 ( V_60 , 2 , L_308 ) ;
V_752 = F_26 ( V_63 * sizeof( char ) ,
V_46 ) ;
if ( ! V_752 ) {
V_34 = - V_47 ;
goto V_755;
}
F_228 ( V_4 , V_752 ) ;
F_232 ( V_4 , V_752 ) ;
V_749 = F_26 ( V_4 -> V_43 . V_67 *
V_63 * sizeof( void * ) ,
V_46 ) ;
if ( ! V_749 ) {
V_34 = - V_47 ;
goto V_756;
}
for ( V_41 = 0 ; V_41 < V_63 ; ++ V_41 ) {
V_749 [ V_41 ] = (struct V_64 * )
F_302 ( V_4 -> V_43 . V_255 -> V_73 [ V_41 ] . V_74 ) ;
}
F_359 = F_26 ( sizeof( void * ) * V_4 -> V_43 . V_67 ,
V_46 ) ;
if ( ! F_359 ) {
V_34 = - V_47 ;
goto V_757;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_43 . V_67 ; ++ V_41 )
F_359 [ V_41 ] = V_4 -> V_147 -> V_758 ;
F_358 ( V_4 , V_749 , F_359 ) ;
V_753 =
F_26 ( V_4 -> V_43 . V_76 * V_63 *
sizeof( void * ) , V_46 ) ;
if ( ! V_753 ) {
V_34 = - V_47 ;
goto V_759;
}
for ( V_41 = 0 , V_754 = 0 ; V_41 < V_4 -> V_43 . V_76 ; ++ V_41 )
for ( V_42 = 0 ; V_42 < V_63 ; ++ V_42 , ++ V_754 ) {
V_753 [ V_754 ] = (struct V_64 * ) F_302 (
V_4 -> V_43 . V_78 [ V_41 ] -> V_73 [ V_42 ] -> V_74 ) ;
}
memset ( & V_751 , 0 , sizeof( struct V_750 ) ) ;
V_751 . V_190 = F_37 ( V_4 ) ;
V_751 . V_760 = F_353 ( V_4 ) ;
V_751 . V_761 = 0 ;
V_751 . V_752 = V_752 ;
V_751 . V_762 = V_4 -> V_43 . V_67 ;
V_751 . V_763 = V_4 -> V_43 . V_76 ;
V_751 . V_764 = V_4 -> V_147 -> V_764 ;
V_751 . V_765 = V_4 -> V_147 -> V_765 ;
V_751 . V_766 = F_359 ;
V_751 . V_767 = ( unsigned long ) V_4 ;
V_751 . V_768 = ( void * * ) V_749 ;
V_751 . V_769 = ( void * * ) V_753 ;
V_751 . V_770 = V_4 -> V_43 . V_75 ;
V_751 . V_771 =
( V_4 -> V_9 . type == V_12 ) ? 1 : 32 ;
if ( F_53 ( & V_4 -> V_43 . V_52 , V_334 ,
V_330 ) == V_334 ) {
V_34 = F_360 ( & V_751 ) ;
if ( V_34 ) {
F_54 ( & V_4 -> V_43 . V_52 , V_334 ) ;
goto V_68;
}
V_34 = F_361 ( & V_751 ) ;
if ( V_34 ) {
F_54 ( & V_4 -> V_43 . V_52 , V_334 ) ;
F_240 ( F_37 ( V_4 ) ) ;
}
}
switch ( V_4 -> V_57 . V_58 ) {
case V_59 :
F_83 ( & V_4 -> V_7 -> V_6 , L_309 ) ;
break;
case V_278 :
F_83 ( & V_4 -> V_7 -> V_6 , L_310 ) ;
break;
default:
break;
}
V_68:
F_31 ( V_753 ) ;
V_759:
F_31 ( F_359 ) ;
V_757:
F_31 ( V_749 ) ;
V_756:
F_31 ( V_752 ) ;
V_755:
return V_34 ;
}
static void F_362 ( struct V_3 * V_4 )
{
F_35 ( V_60 , 2 , L_311 ) ;
F_40 ( V_60 , 2 , & V_4 , sizeof( void * ) ) ;
F_126 ( & V_4 -> V_113 ) ;
F_126 ( & V_4 -> V_153 ) ;
if ( V_4 -> V_6 )
F_363 ( V_4 -> V_6 ) ;
F_31 ( V_4 -> V_289 ) ;
F_123 ( V_4 ) ;
F_364 ( & V_4 -> V_300 ) ;
F_31 ( V_4 ) ;
}
void F_365 ( struct V_3 * V_4 )
{
F_3 ( V_4 , 2 , L_312 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_478 . V_466 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_478 . V_481 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_480 . V_466 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_480 . V_481 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_465 . V_466 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_57 . V_465 . V_481 ) ;
F_46 ( V_4 , 2 , L_313 , V_4 -> V_9 . V_484 ) ;
}
int F_366 ( struct V_3 * V_4 )
{
int V_772 = 3 ;
int V_34 ;
F_35 ( V_60 , 2 , L_314 ) ;
F_54 ( & V_4 -> V_517 , 0 ) ;
F_129 ( V_4 ) ;
V_773:
if ( V_772 < 3 )
F_62 ( 2 , L_315 ,
F_63 ( & V_4 -> V_7 -> V_6 ) ) ;
V_34 = F_157 ( V_4 , V_4 -> V_9 . type != V_12 ) ;
F_357 ( F_37 ( V_4 ) ) ;
F_357 ( F_367 ( V_4 ) ) ;
F_357 ( F_147 ( V_4 ) ) ;
F_240 ( F_37 ( V_4 ) ) ;
V_34 = F_355 ( F_147 ( V_4 ) ) ;
if ( V_34 )
goto V_774;
V_34 = F_355 ( F_367 ( V_4 ) ) ;
if ( V_34 )
goto V_774;
V_34 = F_355 ( F_37 ( V_4 ) ) ;
if ( V_34 )
goto V_774;
V_774:
if ( V_34 == - V_323 ) {
F_35 ( V_60 , 2 , L_316 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_37 , V_34 ) ;
if ( -- V_772 < 0 )
goto V_68;
else
goto V_773;
}
F_354 ( V_4 ) ;
F_164 ( V_4 ) ;
F_165 ( V_4 ) ;
V_34 = F_168 ( & V_4 -> V_113 , F_180 ) ;
if ( V_34 == - V_323 ) {
F_35 ( V_60 , 2 , L_317 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
if ( -- V_772 < 0 )
goto V_68;
else
goto V_773;
}
V_34 = F_168 ( & V_4 -> V_153 , F_177 ) ;
if ( V_34 == - V_323 ) {
F_35 ( V_60 , 2 , L_318 ) ;
return V_34 ;
} else if ( V_34 ) {
F_38 ( V_60 , 2 , L_186 , V_34 ) ;
if ( -- V_772 < 0 )
goto V_68;
else
goto V_773;
}
V_4 -> V_122 = 0 ;
V_34 = F_238 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_187 , V_34 ) ;
goto V_68;
}
V_4 -> V_57 . V_478 . V_466 = 0 ;
V_4 -> V_57 . V_465 . V_466 = 0 ;
V_4 -> V_57 . V_775 . V_466 = 0 ;
V_4 -> V_9 . V_484 = 0 ;
F_271 ( V_4 , V_390 ) ;
if ( F_327 ( V_4 , V_479 ) )
F_269 ( V_4 ) ;
if ( F_334 ( V_4 , V_776 ) )
F_273 ( V_4 ) ;
return 0 ;
V_68:
F_61 ( & V_4 -> V_7 -> V_6 , L_106
L_107 ) ;
F_62 ( 2 , L_319 ,
F_63 ( & V_4 -> V_7 -> V_6 ) , V_34 ) ;
return V_34 ;
}
static inline int F_368 ( struct V_439 * V_777 ,
struct V_778 * V_242 ,
struct V_229 * * V_779 , int V_179 , int * V_780 , int V_590 )
{
struct V_435 * V_435 = F_252 ( V_242 -> V_247 ) ;
if ( * V_779 == NULL ) {
if ( V_777 -> V_256 ) {
* V_779 = V_777 -> V_256 ;
V_777 -> V_256 = NULL ;
} else {
* V_779 = F_256 ( V_440 + V_441 ) ;
if ( ! ( * V_779 ) )
return - V_47 ;
}
F_369 ( * V_779 , V_441 ) ;
if ( V_590 <= V_440 ) {
memcpy ( F_370 ( * V_779 , V_590 ) , V_242 -> V_247 + V_179 ,
V_590 ) ;
} else {
F_371 ( V_435 ) ;
memcpy ( F_370 ( * V_779 , V_440 ) ,
V_242 -> V_247 + V_179 , V_440 ) ;
F_372 ( * V_779 , * V_780 , V_435 ,
V_179 + V_440 ,
V_590 - V_440 ) ;
( * V_779 ) -> V_590 += V_590 - V_440 ;
( * V_779 ) -> V_158 += V_590 - V_440 ;
( * V_779 ) -> V_781 += V_590 - V_440 ;
( * V_780 ) ++ ;
}
} else {
F_371 ( V_435 ) ;
F_372 ( * V_779 , * V_780 , V_435 , V_179 , V_590 ) ;
( * V_779 ) -> V_590 += V_590 ;
( * V_779 ) -> V_158 += V_590 ;
( * V_779 ) -> V_781 += V_590 ;
( * V_780 ) ++ ;
}
return 0 ;
}
struct V_229 * F_373 ( struct V_3 * V_4 ,
struct V_439 * V_777 ,
struct V_778 * * V_782 , int * V_783 ,
struct V_592 * * V_132 )
{
struct V_778 * V_242 = * V_782 ;
struct V_64 * V_74 = V_777 -> V_74 ;
int V_179 = * V_783 ;
struct V_229 * V_230 = NULL ;
int V_784 = 0 ;
void * V_785 ;
int V_590 ;
int V_786 = 0 ;
int V_787 = 0 ;
int V_583 = 0 ;
if ( V_242 -> V_250 < V_179 + sizeof( struct V_592 ) ) {
if ( F_374 ( V_242 ) )
return NULL ;
V_242 ++ ;
V_179 = 0 ;
if ( V_242 -> V_250 < sizeof( struct V_592 ) )
return NULL ;
}
* V_132 = V_242 -> V_247 + V_179 ;
V_179 += sizeof( struct V_592 ) ;
switch ( ( * V_132 ) -> V_132 . V_788 . V_313 ) {
case V_789 :
V_784 = ( * V_132 ) -> V_132 . V_788 . V_790 ;
break;
case V_791 :
V_784 = ( * V_132 ) -> V_132 . V_607 . V_250 ;
V_786 = V_441 ;
break;
case V_792 :
V_784 = ( * V_132 ) -> V_132 . V_793 . V_794 ;
V_786 = sizeof( struct V_592 ) ;
break;
default:
break;
}
if ( ! V_784 )
return NULL ;
if ( ( ( V_784 >= V_4 -> V_57 . V_274 ) &&
( ! ( V_4 -> V_9 . type == V_15 ) ) &&
( ! F_45 ( & V_4 -> V_517 ) ) ) ||
( V_4 -> V_57 . V_58 == V_59 ) ) {
V_787 = 1 ;
} else {
V_230 = F_256 ( V_784 + V_786 ) ;
if ( ! V_230 )
goto V_795;
if ( V_786 )
F_369 ( V_230 , V_786 ) ;
}
V_785 = V_242 -> V_247 + V_179 ;
while ( V_784 ) {
V_590 = F_207 ( V_784 , ( int ) ( V_242 -> V_250 - V_179 ) ) ;
if ( V_590 ) {
if ( V_787 ) {
if ( F_368 ( V_777 , V_242 ,
& V_230 , V_179 , & V_583 , V_590 ) )
goto V_795;
} else {
memcpy ( F_370 ( V_230 , V_590 ) , V_785 ,
V_590 ) ;
}
}
V_784 -= V_590 ;
if ( V_784 ) {
if ( F_374 ( V_242 ) ) {
F_3 ( V_4 , 4 , L_320 ) ;
F_375 ( V_4 , 2 , V_74 , sizeof( void * ) ) ;
F_120 ( V_230 ) ;
V_4 -> V_512 . V_686 ++ ;
return NULL ;
}
V_242 ++ ;
V_179 = 0 ;
V_785 = V_242 -> V_247 ;
} else {
V_179 += V_590 ;
}
}
* V_782 = V_242 ;
* V_783 = V_179 ;
if ( V_787 && V_4 -> V_57 . V_273 ) {
V_4 -> V_437 . V_796 ++ ;
V_4 -> V_437 . V_797 += F_310 ( V_230 ) -> V_584 ;
}
return V_230 ;
V_795:
if ( F_376 () ) {
F_3 ( V_4 , 2 , L_321 ) ;
}
V_4 -> V_512 . V_513 ++ ;
return NULL ;
}
static void F_377 ( void )
{
int V_798 ;
for ( V_798 = 0 ; V_798 < V_799 ; V_798 ++ ) {
F_378 ( V_800 [ V_798 ] . V_313 ) ;
V_800 [ V_798 ] . V_313 = NULL ;
}
}
void F_379 ( T_5 * V_313 , int V_372 , char * V_801 , ... )
{
char V_802 [ 32 ] ;
T_6 args ;
if ( ! F_380 ( V_313 , V_372 ) )
return;
va_start ( args , V_801 ) ;
vsnprintf ( V_802 , sizeof( V_802 ) , V_801 , args ) ;
va_end ( args ) ;
F_381 ( V_313 , V_372 , V_802 ) ;
}
static int F_382 ( void )
{
int V_337 ;
int V_798 ;
for ( V_798 = 0 ; V_798 < V_799 ; V_798 ++ ) {
V_800 [ V_798 ] . V_313 = F_383 ( V_800 [ V_798 ] . V_501 ,
V_800 [ V_798 ] . V_803 ,
V_800 [ V_798 ] . V_804 ,
V_800 [ V_798 ] . V_158 ) ;
if ( V_800 [ V_798 ] . V_313 == NULL ) {
F_377 () ;
return - V_47 ;
}
V_337 = F_384 ( V_800 [ V_798 ] . V_313 , V_800 [ V_798 ] . V_805 ) ;
if ( V_337 ) {
F_377 () ;
return V_337 ;
}
F_385 ( V_800 [ V_798 ] . V_313 , V_800 [ V_798 ] . V_372 ) ;
}
return 0 ;
}
int F_386 ( struct V_3 * V_4 ,
enum V_806 V_147 )
{
int V_34 = 0 ;
F_387 ( & V_807 ) ;
switch ( V_147 ) {
case V_808 :
V_4 -> V_147 = F_388 (
F_389 ( V_809 ) , L_322 ) ;
break;
case V_810 :
V_4 -> V_147 = F_388 (
F_389 ( V_811 ) , L_323 ) ;
break;
}
if ( ! V_4 -> V_147 ) {
F_41 ( & V_4 -> V_7 -> V_6 , L_324
L_325 , V_147 ) ;
V_34 = - V_402 ;
}
F_390 ( & V_807 ) ;
return V_34 ;
}
void F_391 ( struct V_3 * V_4 )
{
if ( V_4 -> V_57 . V_306 )
F_392 ( V_811 ) ;
else
F_392 ( V_809 ) ;
V_4 -> V_147 = NULL ;
}
static T_5 * F_393 ( char * V_501 )
{
struct V_812 * V_433 ;
T_5 * V_34 = NULL ;
F_387 ( & V_813 ) ;
F_245 (entry, &qeth_dbf_list, dbf_list) {
if ( strcmp ( V_433 -> V_814 , V_501 ) == 0 ) {
V_34 = V_433 -> V_815 ;
break;
}
}
F_390 ( & V_813 ) ;
return V_34 ;
}
static int F_394 ( struct V_3 * V_4 , char * V_501 )
{
struct V_812 * V_816 ;
V_4 -> V_817 = F_383 ( V_501 , 2 , 1 , 8 ) ;
if ( ! V_4 -> V_817 ) {
F_38 ( V_60 , 2 , L_191 , L_326 ) ;
goto V_818;
}
if ( F_384 ( V_4 -> V_817 , & V_819 ) )
goto V_820;
V_816 = F_26 ( sizeof( struct V_812 ) , V_46 ) ;
if ( ! V_816 )
goto V_820;
strncpy ( V_816 -> V_814 , V_501 , V_821 ) ;
V_816 -> V_815 = V_4 -> V_817 ;
F_387 ( & V_813 ) ;
F_32 ( & V_816 -> V_822 , & V_823 ) ;
F_390 ( & V_813 ) ;
return 0 ;
V_820:
F_378 ( V_4 -> V_817 ) ;
V_818:
return - V_47 ;
}
static void F_395 ( void )
{
struct V_812 * V_433 , * V_38 ;
F_387 ( & V_813 ) ;
F_23 (entry, tmp, &qeth_dbf_list, dbf_list) {
F_24 ( & V_433 -> V_822 ) ;
F_378 ( V_433 -> V_815 ) ;
F_31 ( V_433 ) ;
}
F_390 ( & V_813 ) ;
}
static int F_396 ( struct V_824 * V_7 )
{
struct V_3 * V_4 ;
struct V_825 * V_6 ;
int V_34 ;
unsigned long V_29 ;
char V_814 [ V_821 ] ;
F_35 ( V_60 , 2 , L_327 ) ;
V_6 = & V_7 -> V_6 ;
if ( ! F_397 ( V_6 ) )
return - V_826 ;
F_38 ( V_60 , 2 , L_191 , F_63 ( & V_7 -> V_6 ) ) ;
V_4 = F_144 () ;
if ( ! V_4 ) {
F_38 ( V_60 , 2 , L_37 , - V_47 ) ;
V_34 = - V_47 ;
goto V_827;
}
snprintf ( V_814 , sizeof( V_814 ) , L_328 ,
F_63 ( & V_7 -> V_6 ) ) ;
V_4 -> V_817 = F_393 ( V_814 ) ;
if ( ! V_4 -> V_817 ) {
V_34 = F_394 ( V_4 , V_814 ) ;
if ( V_34 )
goto V_828;
}
V_4 -> V_113 . V_118 = V_7 -> V_190 [ 0 ] ;
V_4 -> V_153 . V_118 = V_7 -> V_190 [ 1 ] ;
V_4 -> V_116 . V_118 = V_7 -> V_190 [ 2 ] ;
F_398 ( & V_7 -> V_6 , V_4 ) ;
V_4 -> V_7 = V_7 ;
V_7 -> V_190 [ 0 ] -> V_829 = F_111 ;
V_7 -> V_190 [ 1 ] -> V_829 = F_111 ;
V_7 -> V_190 [ 2 ] -> V_829 = F_111 ;
V_34 = F_146 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_141 , V_34 ) ;
goto V_828;
}
V_34 = F_137 ( V_4 ) ;
if ( V_34 ) {
F_38 ( V_60 , 2 , L_136 , V_34 ) ;
goto V_828;
}
if ( V_4 -> V_9 . type == V_15 )
V_7 -> V_6 . type = & V_830 ;
else
V_7 -> V_6 . type = & V_831 ;
switch ( V_4 -> V_9 . type ) {
case V_15 :
case V_13 :
V_34 = F_386 ( V_4 , V_810 ) ;
if ( V_34 )
goto V_828;
V_34 = V_4 -> V_147 -> V_832 ( V_4 -> V_7 ) ;
if ( V_34 )
goto V_833;
case V_11 :
case V_14 :
default:
break;
}
F_399 ( & V_834 . V_835 , V_29 ) ;
F_95 ( & V_4 -> V_39 , & V_834 . V_39 ) ;
F_400 ( & V_834 . V_835 , V_29 ) ;
F_354 ( V_4 ) ;
return 0 ;
V_833:
F_391 ( V_4 ) ;
V_828:
F_362 ( V_4 ) ;
V_827:
F_401 ( V_6 ) ;
return V_34 ;
}
static void F_402 ( struct V_824 * V_7 )
{
unsigned long V_29 ;
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
F_35 ( V_60 , 2 , L_329 ) ;
if ( V_4 -> V_147 ) {
V_4 -> V_147 -> remove ( V_7 ) ;
F_391 ( V_4 ) ;
}
F_399 ( & V_834 . V_835 , V_29 ) ;
F_24 ( & V_4 -> V_39 ) ;
F_400 ( & V_834 . V_835 , V_29 ) ;
F_362 ( V_4 ) ;
F_398 ( & V_7 -> V_6 , NULL ) ;
F_401 ( & V_7 -> V_6 ) ;
return;
}
static int F_404 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
int V_34 = 0 ;
int V_836 ;
if ( ! V_4 -> V_147 ) {
if ( V_4 -> V_9 . type == V_12 )
V_836 = V_808 ;
else
V_836 = V_810 ;
V_34 = F_386 ( V_4 , V_836 ) ;
if ( V_34 )
goto V_818;
V_34 = V_4 -> V_147 -> V_832 ( V_4 -> V_7 ) ;
if ( V_34 )
goto V_818;
}
V_34 = V_4 -> V_147 -> V_837 ( V_7 ) ;
V_818:
return V_34 ;
}
static int F_405 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
return V_4 -> V_147 -> V_838 ( V_7 ) ;
}
static void F_406 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_839 )
V_4 -> V_147 -> V_839 ( V_7 ) ;
}
static int F_407 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_840 )
return V_4 -> V_147 -> V_840 ( V_7 ) ;
return 0 ;
}
static void F_408 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_841 )
V_4 -> V_147 -> V_841 ( V_7 ) ;
}
static int F_409 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_842 )
return V_4 -> V_147 -> V_842 ( V_7 ) ;
return 0 ;
}
static int F_410 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_843 )
return V_4 -> V_147 -> V_843 ( V_7 ) ;
return 0 ;
}
static int F_411 ( struct V_824 * V_7 )
{
struct V_3 * V_4 = F_403 ( & V_7 -> V_6 ) ;
if ( V_4 -> V_147 && V_4 -> V_147 -> V_844 )
return V_4 -> V_147 -> V_844 ( V_7 ) ;
return 0 ;
}
static T_7 F_412 ( struct V_845 * V_846 ,
const char * V_228 , T_8 V_162 )
{
int V_818 ;
V_818 = F_413 ( V_847 ,
& V_848 , 3 , V_228 ) ;
return V_818 ? V_818 : V_162 ;
}
int F_414 ( struct V_620 * V_6 , int V_849 )
{
switch ( V_849 ) {
case V_850 :
return ( sizeof( V_851 ) / V_852 ) ;
default:
return - V_402 ;
}
}
void F_415 ( struct V_620 * V_6 ,
struct V_853 * V_512 , T_9 * V_116 )
{
struct V_3 * V_4 = V_6 -> V_625 ;
V_116 [ 0 ] = V_4 -> V_512 . V_854 -
V_4 -> V_437 . V_855 ;
V_116 [ 1 ] = V_4 -> V_437 . V_856 ;
V_116 [ 2 ] = V_4 -> V_512 . V_857 -
V_4 -> V_437 . V_858 ;
V_116 [ 3 ] = V_4 -> V_437 . V_541 ;
V_116 [ 4 ] = V_4 -> V_512 . V_857 - V_4 -> V_437 . V_858
- V_4 -> V_437 . V_611 ;
V_116 [ 5 ] = V_4 -> V_437 . V_541 - V_4 -> V_437 . V_545 ;
V_116 [ 6 ] = V_4 -> V_437 . V_611 ;
V_116 [ 7 ] = V_4 -> V_437 . V_545 ;
V_116 [ 8 ] = V_4 -> V_437 . V_859 ;
V_116 [ 9 ] = V_4 -> V_437 . V_860 ;
V_116 [ 10 ] = V_4 -> V_437 . V_796 ;
V_116 [ 11 ] = V_4 -> V_437 . V_797 ;
V_116 [ 12 ] = V_4 -> V_437 . V_438 ;
V_116 [ 13 ] = ( V_4 -> V_437 . V_861 >> 10 ) ;
V_116 [ 14 ] = V_4 -> V_437 . V_862 ;
V_116 [ 15 ] = V_4 -> V_437 . V_527 ;
V_116 [ 16 ] = V_4 -> V_437 . V_530 ;
V_116 [ 17 ] = V_529 ;
V_116 [ 18 ] = V_526 ;
V_116 [ 19 ] = F_45 ( & V_4 -> V_43 . V_78 [ 0 ] -> V_445 ) ;
V_116 [ 20 ] = ( V_4 -> V_43 . V_76 > 1 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 1 ] -> V_445 ) : 0 ;
V_116 [ 21 ] = ( V_4 -> V_43 . V_76 > 2 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 2 ] -> V_445 ) : 0 ;
V_116 [ 22 ] = ( V_4 -> V_43 . V_76 > 3 ) ?
F_45 ( & V_4 -> V_43 . V_78 [ 3 ] -> V_445 ) : 0 ;
V_116 [ 23 ] = V_4 -> V_437 . V_863 ;
V_116 [ 24 ] = V_4 -> V_437 . V_864 ;
V_116 [ 25 ] = V_4 -> V_437 . V_521 ;
V_116 [ 26 ] = V_4 -> V_437 . V_519 ;
V_116 [ 27 ] = V_4 -> V_437 . V_564 ;
V_116 [ 28 ] = V_4 -> V_437 . V_560 ;
V_116 [ 29 ] = V_4 -> V_437 . V_865 ;
V_116 [ 30 ] = V_4 -> V_437 . V_866 ;
V_116 [ 31 ] = V_4 -> V_437 . V_538 ;
V_116 [ 32 ] = V_4 -> V_437 . V_534 ;
V_116 [ 33 ] = V_4 -> V_437 . V_867 ;
V_116 [ 34 ] = V_4 -> V_437 . V_868 ;
V_116 [ 35 ] = V_4 -> V_437 . V_552 ;
V_116 [ 36 ] = V_4 -> V_437 . V_556 ;
}
void F_416 ( struct V_620 * V_6 , V_696 V_849 , V_279 * V_116 )
{
switch ( V_849 ) {
case V_850 :
memcpy ( V_116 , & V_851 ,
sizeof( V_851 ) ) ;
break;
default:
F_69 ( 1 ) ;
break;
}
}
void F_417 ( struct V_620 * V_6 ,
struct V_869 * V_9 )
{
struct V_3 * V_4 = V_6 -> V_625 ;
F_418 ( V_9 -> V_870 , V_4 -> V_57 . V_306 ? L_323 : L_322 ,
sizeof( V_9 -> V_870 ) ) ;
F_418 ( V_9 -> V_871 , L_330 , sizeof( V_9 -> V_871 ) ) ;
F_418 ( V_9 -> V_872 , V_4 -> V_9 . V_301 ,
sizeof( V_9 -> V_872 ) ) ;
snprintf ( V_9 -> V_873 , sizeof( V_9 -> V_873 ) , L_331 ,
F_419 ( V_4 ) , F_420 ( V_4 ) , F_421 ( V_4 ) ) ;
}
static void F_422 ( struct V_874 * V_875 ,
int V_876 , int V_877 )
{
int V_878 , V_879 , V_880 , V_881 ;
switch ( V_877 ) {
case V_882 :
V_878 = V_883 ;
V_879 = V_884 ;
break;
case V_885 :
V_878 = V_886 ;
V_879 = V_887 ;
break;
default:
V_878 = V_883 ;
V_879 = V_884 ;
F_48 ( 1 ) ;
}
V_880 = 0 ;
V_881 = 0 ;
switch ( V_876 ) {
case V_888 :
V_880 |= V_889 ;
V_881 |= V_890 ;
case V_891 :
V_880 |= V_892 | V_893 ;
V_881 |= V_894 |
V_895 ;
case V_896 :
V_880 |= V_897 | V_898 ;
V_881 |= V_899 | V_900 ;
case V_901 :
V_880 |= V_902 | V_903 ;
V_881 |= V_904 | V_905 ;
break;
default:
V_880 = V_902 | V_903 ;
V_881 = V_904 | V_905 ;
F_48 ( 1 ) ;
}
V_875 -> V_906 = V_907 | V_879 | V_881 ;
V_875 -> V_908 = V_909 | V_878 | V_880 ;
}
int F_423 ( struct V_620 * V_910 ,
struct V_874 * V_875 )
{
struct V_3 * V_4 = V_910 -> V_625 ;
enum V_447 V_16 ;
struct V_732 V_732 ;
V_696 V_911 ;
if ( ( V_4 -> V_9 . type == V_12 ) || ( V_4 -> V_9 . V_10 ) )
V_16 = V_20 ;
else
V_16 = V_4 -> V_9 . V_16 ;
V_875 -> V_912 = V_913 ;
V_875 -> V_914 = V_915 ;
V_875 -> V_916 = V_917 ;
switch ( V_16 ) {
case V_17 :
case V_21 :
F_422 ( V_875 , V_896 , V_882 ) ;
V_911 = V_896 ;
V_875 -> V_918 = V_882 ;
break;
case V_19 :
case V_23 :
F_422 ( V_875 , V_891 , V_885 ) ;
V_911 = V_891 ;
V_875 -> V_918 = V_885 ;
break;
case V_20 :
F_422 ( V_875 , V_888 , V_885 ) ;
V_911 = V_888 ;
V_875 -> V_918 = V_885 ;
break;
default:
F_422 ( V_875 , V_901 , V_882 ) ;
V_911 = V_901 ;
V_875 -> V_918 = V_882 ;
}
F_424 ( V_875 , V_911 ) ;
if ( V_730 ( V_4 , & V_732 ) != 0 )
return 0 ;
F_425 ( V_910 ,
L_332 ,
V_732 . V_733 ,
V_732 . V_734 ,
V_732 . V_735 ) ;
switch ( V_732 . V_733 ) {
case V_919 :
case V_920 :
F_422 ( V_875 , V_891 , V_882 ) ;
V_875 -> V_918 = V_882 ;
break;
case V_921 :
case V_922 :
F_422 ( V_875 , V_891 , V_885 ) ;
V_875 -> V_918 = V_885 ;
break;
case V_923 :
case V_924 :
F_422 ( V_875 , V_888 , V_885 ) ;
V_875 -> V_918 = V_885 ;
break;
}
switch ( V_732 . V_734 ) {
case V_925 :
V_875 -> V_914 = V_915 ;
break;
case V_926 :
V_875 -> V_914 = V_927 ;
break;
}
switch ( V_732 . V_735 ) {
case V_928 :
V_911 = V_901 ;
break;
case V_929 :
V_911 = V_896 ;
break;
case V_930 :
V_911 = V_891 ;
break;
case V_931 :
V_911 = V_888 ;
break;
}
F_424 ( V_875 , V_911 ) ;
return 0 ;
}
static int T_10 F_426 ( void )
{
int V_34 ;
F_427 ( L_333 ) ;
F_132 ( & V_834 . V_39 ) ;
F_132 ( & V_823 ) ;
F_428 ( & V_834 . V_835 ) ;
F_138 ( & V_807 ) ;
V_8 = F_429 ( L_334 ) ;
V_34 = F_382 () ;
if ( V_34 )
goto V_932;
V_847 = F_430 ( L_335 ) ;
V_34 = F_431 ( V_847 ) ;
if ( V_34 )
goto V_933;
V_249 = F_432 ( L_336 ,
sizeof( struct V_592 ) + V_441 , 64 , 0 , NULL ) ;
if ( ! V_249 ) {
V_34 = - V_47 ;
goto V_934;
}
V_100 = F_432 ( L_337 ,
sizeof( struct V_95 ) , 0 , 0 , NULL ) ;
if ( ! V_100 ) {
V_34 = - V_47 ;
goto V_935;
}
V_34 = F_433 ( & V_936 ) ;
if ( V_34 )
goto V_937;
V_848 . V_870 . V_938 = V_939 ;
V_34 = F_434 ( & V_848 ) ;
if ( V_34 )
goto V_940;
return 0 ;
V_940:
F_435 ( & V_936 ) ;
V_937:
F_436 ( V_100 ) ;
V_935:
F_436 ( V_249 ) ;
V_934:
F_437 ( V_847 ) ;
V_933:
F_377 () ;
V_932:
F_438 ( L_338 ) ;
return V_34 ;
}
static void T_11 F_439 ( void )
{
F_395 () ;
F_440 ( V_8 ) ;
F_441 ( & V_848 ) ;
F_435 ( & V_936 ) ;
F_436 ( V_100 ) ;
F_436 ( V_249 ) ;
F_437 ( V_847 ) ;
F_377 () ;
F_427 ( L_339 ) ;
}
