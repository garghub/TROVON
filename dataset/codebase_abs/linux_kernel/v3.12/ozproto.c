static T_1 F_1 ( T_1 V_1 )
{
if ( ++ V_2 == 0 )
V_2 = 1 ;
if ( V_2 == V_1 ) {
if ( ++ V_2 == 0 )
V_2 = 1 ;
}
return V_2 ;
}
static void F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = sizeof( struct V_11 ) + sizeof( struct V_12 ) +
sizeof( struct V_14 ) ;
V_7 = F_3 ( V_16 + F_4 ( V_9 ) , V_17 ) ;
if ( V_7 == NULL )
return;
F_5 ( V_7 , F_6 ( V_9 ) ) ;
F_7 ( V_7 ) ;
V_11 = (struct V_11 * ) F_8 ( V_7 , V_16 ) ;
V_13 = (struct V_12 * ) ( V_11 + 1 ) ;
V_15 = (struct V_14 * ) ( V_13 + 1 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_18 = F_9 ( V_19 ) ;
if ( F_10 ( V_7 , V_9 , V_19 , V_4 -> V_20 ,
V_9 -> V_21 , V_7 -> V_22 ) < 0 ) {
F_11 ( V_7 ) ;
return;
}
V_11 -> V_23 = ( V_24 << V_25 ) ;
V_11 -> V_26 = 0 ;
F_12 ( 0 , & V_11 -> V_27 ) ;
V_13 -> type = V_28 ;
V_13 -> V_29 = sizeof( struct V_14 ) ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 -> V_5 = V_5 ;
if ( V_5 == 0 ) {
V_15 -> V_30 = V_4 -> V_30 ;
V_15 -> V_31 = V_4 -> V_31 ;
F_12 ( F_13 ( V_4 -> V_32 ) , & V_15 -> V_33 ) ;
}
F_14 ( V_34 , L_1 , V_5 ) ;
F_15 ( V_7 ) ;
return;
}
static void F_16 ( struct V_3 * V_4 , T_1 V_35 )
{
unsigned long V_36 = V_35 & V_37 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_4 -> V_36 = V_36 * 1000 * 60 * 60 * 24 * 20 ;
break;
case V_40 :
V_4 -> V_36 = V_36 * 1000 ;
break;
case V_41 :
V_4 -> V_36 = V_36 * 1000 * 60 ;
break;
case V_42 :
V_4 -> V_36 = V_36 * 1000 * 60 * 60 ;
break;
default:
V_4 -> V_36 = 0 ;
}
F_14 ( V_34 , L_2 , V_4 -> V_36 ) ;
}
static void F_17 ( struct V_3 * V_4 , T_1 V_43 , T_1 V_44 )
{
if ( V_43 )
V_4 -> V_43 = V_43 * 100 ;
else
V_4 -> V_43 = V_45 ;
if ( V_44 ) {
F_18 ( & V_46 ) ;
F_19 ( V_4 , V_47 , V_4 -> V_43 ) ;
F_20 ( & V_46 ) ;
}
F_14 ( V_34 , L_3 , V_4 -> V_43 ) ;
}
static struct V_3 * F_21 ( struct V_3 * V_48 , struct V_12 * V_13 ,
const T_1 * V_49 , struct V_8 * V_10 )
{
struct V_3 * V_4 ;
struct V_50 * V_15 =
(struct V_50 * ) ( V_13 + 1 ) ;
T_1 V_51 = V_52 ;
T_1 V_53 = 0 ;
T_2 V_54 = V_55 ;
struct V_8 * V_56 = NULL ;
struct V_3 * V_57 = NULL ;
if ( V_48 ) {
V_4 = V_48 ;
F_22 ( & V_46 ) ;
} else {
struct V_3 * V_58 = NULL ;
struct V_59 * V_60 ;
V_4 = F_23 ( V_49 ) ;
if ( V_4 == NULL )
return NULL ;
F_24 ( & V_4 -> V_61 ) ;
F_22 ( & V_46 ) ;
F_25 (e, &g_pd_list) {
V_58 = F_26 ( V_60 , struct V_3 , V_62 ) ;
if ( memcmp ( V_58 -> V_20 , V_49 , V_63 ) == 0 ) {
V_57 = V_4 ;
V_4 = V_58 ;
break;
}
}
if ( V_4 != V_58 )
F_27 ( & V_4 -> V_62 , & V_64 ) ;
}
if ( V_4 == NULL ) {
F_28 ( & V_46 ) ;
return NULL ;
}
if ( V_4 -> V_10 != V_10 ) {
V_56 = V_4 -> V_10 ;
F_29 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
}
F_14 ( V_34 , L_4 , V_15 -> V_65 ) ;
V_4 -> V_66 = V_67 ;
V_4 -> V_30 = V_15 -> V_30 ;
V_4 -> V_68 = V_15 -> V_68 ;
if ( V_4 -> V_30 & V_69 ) {
V_4 -> V_70 = V_15 -> V_70 ;
if ( ! V_4 -> V_70 )
V_4 -> V_70 = 4 ;
switch ( V_15 -> V_71 & V_72 ) {
case V_73 :
V_4 -> V_74 = ( V_15 -> V_71 &
~ V_72 ) / V_4 -> V_70 ;
break;
case V_75 :
V_4 -> V_74 = ( ( V_15 -> V_71 &
~ V_72 ) * 10 ) / V_4 -> V_70 ;
break;
default:
V_4 -> V_74 = V_76 ;
}
}
if ( V_15 -> V_77 )
V_4 -> V_66 = ( ( T_2 ) V_15 -> V_77 ) << 4 ;
F_14 ( V_34 , L_5 ,
V_4 -> V_66 , V_4 -> V_70 ) ;
V_4 -> V_78 = 3 * 1024 ;
V_4 -> V_79 = V_80 ;
F_17 ( V_4 , V_15 -> V_43 , 0 ) ;
F_16 ( V_4 , V_15 -> V_36 ) ;
V_54 &= F_30 ( F_31 ( & V_15 -> V_33 ) ) ;
if ( ( V_54 & 0x1 ) && ( V_15 -> V_31 ) ) {
if ( V_4 -> V_31 ) {
if ( V_4 -> V_31 != V_15 -> V_31 ) {
V_51 = V_81 ;
goto V_82;
}
} else {
V_54 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
} else {
if ( V_4 -> V_31 && ! V_15 -> V_31 ) {
V_51 = V_83 ;
V_53 = 1 ;
} else {
V_54 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
}
V_82:
if ( V_51 == V_52 ) {
T_2 V_84 = V_54 & ~ V_4 -> V_32 & ~ 0x1 ;
T_2 V_85 = V_4 -> V_32 & ~ V_54 & ~ 0x1 ;
T_2 V_86 = V_54 & V_4 -> V_87 & ~ 0x1 ;
F_28 ( & V_46 ) ;
F_32 ( V_4 , V_88 ) ;
F_14 ( V_34 , L_6 ,
V_54 , V_4 -> V_32 , V_4 -> V_87 ) ;
if ( V_84 ) {
if ( F_33 ( V_4 , V_84 , 0 ) )
V_51 = V_89 ;
}
if ( V_86 )
if ( F_33 ( V_4 , V_86 , 1 ) )
V_51 = V_89 ;
if ( V_85 )
F_34 ( V_4 , V_85 , 0 ) ;
F_35 ( V_4 ) ;
} else {
F_28 ( & V_46 ) ;
}
F_2 ( V_4 , V_51 ) ;
if ( V_51 != V_52 ) {
if ( V_53 )
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
V_4 = NULL ;
}
if ( V_56 )
F_38 ( V_56 ) ;
if ( V_57 )
F_39 ( V_57 ) ;
return V_4 ;
}
static void F_40 ( struct V_3 * V_4 , T_1 V_90 , T_1 V_91 ,
const T_1 * V_92 , T_1 V_22 )
{
struct V_93 * V_94 ;
struct V_93 * V_95 ;
int V_96 = 0 ;
V_94 = F_41 ( sizeof( struct V_93 ) + V_22 , V_17 ) ;
if ( ! V_94 )
return;
V_94 -> V_90 = V_90 ;
V_94 -> V_91 = V_91 ;
V_94 -> V_22 = V_22 ;
memcpy ( V_94 -> V_92 , V_92 , V_22 ) ;
F_14 ( V_34 , L_7 ) ;
F_20 ( & V_46 ) ;
F_42 (f2, &pd->farewell_list, link) {
if ( ( V_95 -> V_90 == V_90 ) && ( V_95 -> V_91 == V_91 ) ) {
V_96 = 1 ;
F_43 ( & V_95 -> V_62 ) ;
break;
}
}
F_27 ( & V_94 -> V_62 , & V_4 -> V_97 ) ;
F_18 ( & V_46 ) ;
if ( V_96 )
F_44 ( V_95 ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
T_1 * V_98 ;
T_1 * V_99 ;
struct V_12 * V_13 ;
int V_29 ;
struct V_3 * V_4 = NULL ;
struct V_11 * V_11 = (struct V_11 * ) F_46 ( V_7 ) ;
struct V_100 V_101 ;
int V_102 = 0 ;
T_3 V_27 ;
F_14 ( V_103 , L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_98 = F_47 ( V_7 ) ;
V_99 = & V_98 [ V_63 ] ;
V_29 = V_7 -> V_22 ;
if ( F_48 ( V_11 -> V_23 ) != V_24 ) {
F_14 ( V_34 , L_9 ,
F_48 ( V_11 -> V_23 ) ) ;
goto V_82;
}
V_27 = F_49 ( F_31 ( & V_11 -> V_27 ) ) ;
V_4 = F_50 ( V_99 ) ;
if ( V_4 ) {
if ( ! ( V_4 -> V_104 & V_88 ) )
F_32 ( V_4 , V_88 ) ;
F_24 ( & V_101 ) ;
if ( ( V_101 . V_105 != V_4 -> V_61 . V_105 ) ||
( V_4 -> V_43 < V_106 ) ) {
F_19 ( V_4 , V_47 , V_4 -> V_43 ) ;
V_4 -> V_61 = V_101 ;
}
if ( V_27 != V_4 -> V_107 ) {
V_4 -> V_107 = V_27 ;
} else {
V_102 = 1 ;
F_14 ( V_34 , L_10 ) ;
}
}
if ( V_4 && ! V_102 && ( ( V_4 -> V_30 & V_108 ) == V_109 ) ) {
F_14 ( V_103 , L_11 ) ;
V_4 -> V_110 = & V_4 -> V_111 ;
if ( V_11 -> V_23 & V_112 ) {
F_51 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_113 ) &&
( V_4 -> V_104 == V_88 ) ) {
int V_114 = V_4 -> V_115 ;
V_4 -> V_116 = V_27 ;
F_52 ( V_4 , V_114 ) ;
}
}
V_29 -= sizeof( struct V_11 ) ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_11 + sizeof( struct V_11 ) ) ;
while ( V_29 >= sizeof( struct V_12 ) ) {
V_29 -= sizeof( struct V_12 ) + V_13 -> V_29 ;
if ( V_29 < 0 )
break;
switch ( V_13 -> type ) {
case V_117 :
F_14 ( V_34 , L_12 ) ;
V_4 = F_21 ( V_4 , V_13 , V_99 , V_7 -> V_9 ) ;
break;
case V_118 :
F_14 ( V_34 , L_13 ) ;
if ( V_4 )
F_53 ( V_4 ) ;
break;
case V_119 : {
struct V_120 * V_15 =
(struct V_120 * ) ( V_13 + 1 ) ;
F_14 ( V_34 , L_14 ) ;
if ( V_4 && ( V_4 -> V_104 & V_88 ) ) {
F_20 ( & V_46 ) ;
F_16 ( V_4 , V_15 -> V_121 ) ;
F_17 ( V_4 , V_15 -> V_43 , 1 ) ;
F_18 ( & V_46 ) ;
}
}
break;
case V_122 : {
struct V_123 * V_15 =
(struct V_123 * ) ( V_13 + 1 ) ;
F_14 ( V_34 , L_15 ) ;
F_40 ( V_4 , V_15 -> V_90 ,
V_15 -> V_91 , V_15 -> V_92 ,
V_13 -> V_29 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_124 :
if ( V_4 && ( V_4 -> V_104 & V_88 ) ) {
struct V_125 * V_126 =
(struct V_125 * ) ( V_13 + 1 ) ;
if ( V_102 )
break;
F_54 ( V_4 , V_126 -> V_127 , V_13 ) ;
}
break;
default:
F_14 ( V_34 , L_16 , V_13 -> type ) ;
}
V_13 = F_55 ( V_13 ) ;
}
V_82:
if ( V_4 )
F_37 ( V_4 ) ;
F_56 ( V_7 ) ;
}
void F_57 ( void )
{
struct V_128 * V_129 , * V_130 ;
F_22 ( & V_131 ) ;
F_58 (b, t, &g_binding, link) {
F_43 ( & V_129 -> V_62 ) ;
F_28 ( & V_131 ) ;
F_59 ( & V_129 -> V_132 ) ;
if ( V_129 -> V_132 . V_9 )
F_38 ( V_129 -> V_132 . V_9 ) ;
F_44 ( V_129 ) ;
F_22 ( & V_131 ) ;
}
F_28 ( & V_131 ) ;
F_22 ( & V_46 ) ;
while ( ! F_60 ( & V_64 ) ) {
struct V_3 * V_4 =
F_61 ( & V_64 , struct V_3 , V_62 ) ;
F_62 ( V_4 ) ;
F_28 ( & V_46 ) ;
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
F_22 ( & V_46 ) ;
}
F_28 ( & V_46 ) ;
F_14 ( V_34 , L_17 ) ;
}
void F_63 ( unsigned long V_133 )
{
struct V_3 * V_4 = (struct V_3 * ) V_133 ;
T_2 V_33 = 0 ;
F_22 ( & V_46 ) ;
if ( V_4 -> V_104 & V_88 )
V_33 = V_4 -> V_32 ;
F_28 ( & V_46 ) ;
if ( V_33 )
F_64 ( V_4 , V_33 ) ;
F_37 ( V_4 ) ;
}
void F_65 ( unsigned long V_133 )
{
int type ;
struct V_3 * V_4 = (struct V_3 * ) V_133 ;
F_22 ( & V_46 ) ;
type = V_4 -> V_134 ;
F_28 ( & V_46 ) ;
switch ( type ) {
case V_47 :
F_53 ( V_4 ) ;
break;
case V_135 :
F_36 ( V_4 ) ;
break;
}
F_37 ( V_4 ) ;
}
enum V_136 F_66 ( struct V_137 * V_138 )
{
struct V_3 * V_4 ;
V_4 = F_26 ( V_138 , struct V_3 , V_139 ) ;
F_67 ( V_138 , F_68 ( V_4 -> V_79 /
V_106 , ( V_4 -> V_79 % V_106 ) * V_140 ) ) ;
F_62 ( V_4 ) ;
F_69 ( & V_4 -> V_141 ) ;
return V_142 ;
}
enum V_136 F_70 ( struct V_137 * V_138 )
{
struct V_3 * V_4 ;
V_4 = F_26 ( V_138 , struct V_3 , V_143 ) ;
F_62 ( V_4 ) ;
F_69 ( & V_4 -> V_144 ) ;
return V_145 ;
}
void F_19 ( struct V_3 * V_4 , int type , unsigned long V_146 )
{
F_22 ( & V_46 ) ;
switch ( type ) {
case V_47 :
case V_135 :
if ( F_71 ( & V_4 -> V_143 ) ) {
F_72 ( & V_4 -> V_143 , F_68 ( V_146 /
V_106 , ( V_146 % V_106 ) *
V_140 ) ) ;
F_73 ( & V_4 -> V_143 , V_147 ) ;
} else {
F_74 ( & V_4 -> V_143 , F_68 ( V_146 /
V_106 , ( V_146 % V_106 ) *
V_140 ) , V_147 ) ;
}
V_4 -> V_134 = type ;
break;
case V_148 :
if ( ! F_71 ( & V_4 -> V_139 ) )
F_74 ( & V_4 -> V_139 , F_68 ( V_146 /
V_106 , ( V_146 % V_106 ) *
V_140 ) , V_147 ) ;
break;
}
F_28 ( & V_46 ) ;
}
void F_35 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_148 , V_4 -> V_79 > 0 ?
V_4 -> V_79 : V_80 ) ;
}
struct V_3 * F_50 ( const T_1 * V_20 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
F_22 ( & V_46 ) ;
F_25 (e, &g_pd_list) {
V_4 = F_26 ( V_60 , struct V_3 , V_62 ) ;
if ( memcmp ( V_4 -> V_20 , V_20 , V_63 ) == 0 ) {
F_75 ( & V_4 -> V_149 ) ;
F_28 ( & V_46 ) ;
return V_4 ;
}
}
F_28 ( & V_46 ) ;
return NULL ;
}
void F_76 ( int V_127 , int V_150 )
{
if ( V_127 <= V_151 ) {
F_22 ( & V_46 ) ;
if ( V_150 )
V_55 |= ( 1 << V_127 ) ;
else
V_55 &= ~ ( 1 << V_127 ) ;
F_28 ( & V_46 ) ;
}
}
static int F_77 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_152 * V_153 , struct V_8 * V_154 )
{
V_7 = F_78 ( V_7 , V_17 ) ;
if ( V_7 == NULL )
return 0 ;
F_22 ( & V_155 . V_156 ) ;
if ( V_157 ) {
F_79 ( & V_155 , V_7 ) ;
F_28 ( & V_155 . V_156 ) ;
} else {
V_157 = 1 ;
do {
F_28 ( & V_155 . V_156 ) ;
F_45 ( V_7 ) ;
F_22 ( & V_155 . V_156 ) ;
if ( F_80 ( & V_155 ) ) {
V_157 = 0 ;
F_28 ( & V_155 . V_156 ) ;
break;
}
V_7 = F_81 ( & V_155 ) ;
} while ( 1 );
}
return 0 ;
}
void F_82 ( const char * V_10 )
{
struct V_128 * V_158 ;
V_158 = F_41 ( sizeof( struct V_128 ) , V_159 ) ;
if ( V_158 ) {
V_158 -> V_132 . type = F_83 ( V_19 ) ;
V_158 -> V_132 . V_160 = F_77 ;
memcpy ( V_158 -> V_161 , V_10 , V_162 ) ;
if ( V_10 && * V_10 ) {
F_14 ( V_34 , L_18 , V_10 ) ;
V_158 -> V_132 . V_9 =
F_84 ( & V_163 , V_10 ) ;
if ( V_158 -> V_132 . V_9 == NULL ) {
F_14 ( V_34 , L_19 , V_10 ) ;
F_44 ( V_158 ) ;
V_158 = NULL ;
}
} else {
F_14 ( V_34 , L_20 ) ;
V_158 -> V_132 . V_9 = NULL ;
}
if ( V_158 ) {
F_85 ( & V_158 -> V_132 ) ;
F_22 ( & V_131 ) ;
F_27 ( & V_158 -> V_62 , & V_164 ) ;
F_28 ( & V_131 ) ;
}
}
}
static void F_86 ( struct V_8 * V_10 )
{
struct V_59 V_165 ;
struct V_3 * V_4 ;
struct V_3 * V_166 ;
F_87 ( & V_165 ) ;
F_22 ( & V_46 ) ;
F_58 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_88 ( & V_4 -> V_62 , & V_165 ) ;
F_62 ( V_4 ) ;
}
}
F_28 ( & V_46 ) ;
while ( ! F_60 ( & V_165 ) ) {
V_4 = F_61 ( & V_165 , struct V_3 , V_62 ) ;
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
}
}
void F_89 ( const char * V_10 )
{
struct V_128 * V_158 ;
int V_96 = 0 ;
F_14 ( V_34 , L_21 , V_10 ) ;
F_22 ( & V_131 ) ;
F_42 (binding, &g_binding, link) {
if ( strncmp ( V_158 -> V_161 , V_10 , V_162 ) == 0 ) {
F_14 ( V_34 , L_22 , V_10 ) ;
V_96 = 1 ;
break;
}
}
F_28 ( & V_131 ) ;
if ( V_96 ) {
F_59 ( & V_158 -> V_132 ) ;
if ( V_158 -> V_132 . V_9 ) {
F_38 ( V_158 -> V_132 . V_9 ) ;
F_86 ( V_158 -> V_132 . V_9 ) ;
}
F_43 ( & V_158 -> V_62 ) ;
F_44 ( V_158 ) ;
}
}
static char * F_90 ( char * V_167 , char * V_168 , int V_169 )
{
while ( * V_167 == ',' )
V_167 ++ ;
while ( * V_167 && ( * V_167 != ',' ) && V_169 > 1 ) {
* V_168 ++ = * V_167 ++ ;
V_169 -- ;
}
* V_168 = 0 ;
return V_167 ;
}
int F_91 ( char * V_170 )
{
F_92 ( & V_155 ) ;
if ( V_170 && ( V_170 [ 0 ] == '*' ) ) {
F_82 ( NULL ) ;
} else {
char V_171 [ 32 ] ;
while ( * V_170 ) {
V_170 = F_90 ( V_170 , V_171 , sizeof( V_171 ) ) ;
if ( V_171 [ 0 ] )
F_82 ( V_171 ) ;
}
}
return 0 ;
}
int F_93 ( struct V_172 * V_173 , int V_174 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
int V_175 = 0 ;
F_22 ( & V_46 ) ;
F_25 (e, &g_pd_list) {
if ( V_175 >= V_174 )
break;
V_4 = F_26 ( V_60 , struct V_3 , V_62 ) ;
memcpy ( & V_173 [ V_175 ++ ] , V_4 -> V_20 , V_63 ) ;
}
F_28 ( & V_46 ) ;
return V_175 ;
}
void F_94 ( void )
{
F_22 ( & V_46 ) ;
}
void F_95 ( void )
{
F_28 ( & V_46 ) ;
}
