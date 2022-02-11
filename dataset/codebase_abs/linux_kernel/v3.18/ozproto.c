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
if ( F_27 ( V_58 -> V_20 , V_49 ) ) {
V_57 = V_4 ;
V_4 = V_58 ;
break;
}
}
if ( V_4 != V_58 )
F_28 ( & V_4 -> V_62 , & V_63 ) ;
}
if ( V_4 == NULL ) {
F_29 ( & V_46 ) ;
return NULL ;
}
if ( V_4 -> V_10 != V_10 ) {
V_56 = V_4 -> V_10 ;
F_30 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
}
F_14 ( V_34 , L_4 , V_15 -> V_64 ) ;
V_4 -> V_65 = V_66 ;
V_4 -> V_30 = V_15 -> V_30 ;
V_4 -> V_67 = V_15 -> V_67 ;
if ( V_4 -> V_30 & V_68 ) {
V_4 -> V_69 = V_15 -> V_69 ;
if ( ! V_4 -> V_69 )
V_4 -> V_69 = 4 ;
switch ( V_15 -> V_70 & V_71 ) {
case V_72 :
V_4 -> V_73 = ( V_15 -> V_70 &
~ V_71 ) / V_4 -> V_69 ;
break;
case V_74 :
V_4 -> V_73 = ( ( V_15 -> V_70 &
~ V_71 ) * 10 ) / V_4 -> V_69 ;
break;
default:
V_4 -> V_73 = V_75 ;
}
}
if ( V_15 -> V_76 )
V_4 -> V_65 = ( ( T_2 ) V_15 -> V_76 ) << 4 ;
F_14 ( V_34 , L_5 ,
V_4 -> V_65 , V_4 -> V_69 ) ;
V_4 -> V_77 = 3 * 1024 ;
V_4 -> V_78 = V_79 ;
F_17 ( V_4 , V_15 -> V_43 , 0 ) ;
F_16 ( V_4 , V_15 -> V_36 ) ;
V_54 &= F_31 ( F_32 ( & V_15 -> V_33 ) ) ;
if ( ( V_54 & 0x1 ) && ( V_15 -> V_31 ) ) {
if ( V_4 -> V_31 ) {
if ( V_4 -> V_31 != V_15 -> V_31 ) {
V_51 = V_80 ;
goto V_81;
}
} else {
V_54 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
} else {
if ( V_4 -> V_31 && ! V_15 -> V_31 ) {
V_51 = V_82 ;
V_53 = 1 ;
} else {
V_54 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
}
V_81:
if ( V_51 == V_52 ) {
T_2 V_83 = V_54 & ~ V_4 -> V_32 & ~ 0x1 ;
T_2 V_84 = V_4 -> V_32 & ~ V_54 & ~ 0x1 ;
T_2 V_85 = V_54 & V_4 -> V_86 & ~ 0x1 ;
F_29 ( & V_46 ) ;
F_33 ( V_4 , V_87 ) ;
F_14 ( V_34 , L_6 ,
V_54 , V_4 -> V_32 , V_4 -> V_86 ) ;
if ( V_83 ) {
if ( F_34 ( V_4 , V_83 , 0 ) )
V_51 = V_88 ;
}
if ( V_85 )
if ( F_34 ( V_4 , V_85 , 1 ) )
V_51 = V_88 ;
if ( V_84 )
F_35 ( V_4 , V_84 , 0 ) ;
F_36 ( V_4 ) ;
} else {
F_29 ( & V_46 ) ;
}
F_2 ( V_4 , V_51 ) ;
if ( V_51 != V_52 ) {
if ( V_53 )
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
V_4 = NULL ;
}
if ( V_56 )
F_39 ( V_56 ) ;
if ( V_57 )
F_40 ( V_57 ) ;
return V_4 ;
}
static void F_41 ( struct V_3 * V_4 , T_1 V_89 , T_1 V_90 ,
const T_1 * V_91 , T_1 V_22 )
{
struct V_92 * V_93 ;
struct V_92 * V_94 ;
int V_95 = 0 ;
V_93 = F_42 ( sizeof( struct V_92 ) + V_22 , V_17 ) ;
if ( ! V_93 )
return;
V_93 -> V_89 = V_89 ;
V_93 -> V_90 = V_90 ;
V_93 -> V_22 = V_22 ;
memcpy ( V_93 -> V_91 , V_91 , V_22 ) ;
F_14 ( V_34 , L_7 ) ;
F_20 ( & V_46 ) ;
F_43 (f2, &pd->farewell_list, link) {
if ( ( V_94 -> V_89 == V_89 ) && ( V_94 -> V_90 == V_90 ) ) {
V_95 = 1 ;
F_44 ( & V_94 -> V_62 ) ;
break;
}
}
F_28 ( & V_93 -> V_62 , & V_4 -> V_96 ) ;
F_18 ( & V_46 ) ;
if ( V_95 )
F_45 ( V_94 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
T_1 * V_97 ;
T_1 * V_98 ;
struct V_12 * V_13 ;
int V_29 ;
struct V_3 * V_4 = NULL ;
struct V_11 * V_11 = (struct V_11 * ) F_47 ( V_7 ) ;
struct V_99 V_100 ;
int V_101 = 0 ;
T_3 V_27 ;
F_14 ( V_102 , L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_97 = F_48 ( V_7 ) ;
V_98 = & V_97 [ V_103 ] ;
V_29 = V_7 -> V_22 ;
if ( F_49 ( V_11 -> V_23 ) != V_24 ) {
F_14 ( V_34 , L_9 ,
F_49 ( V_11 -> V_23 ) ) ;
goto V_81;
}
V_27 = F_50 ( F_32 ( & V_11 -> V_27 ) ) ;
V_4 = F_51 ( V_98 ) ;
if ( V_4 ) {
if ( ! ( V_4 -> V_104 & V_87 ) )
F_33 ( V_4 , V_87 ) ;
F_24 ( & V_100 ) ;
if ( ( V_100 . V_105 != V_4 -> V_61 . V_105 ) ||
( V_4 -> V_43 < V_106 ) ) {
F_19 ( V_4 , V_47 , V_4 -> V_43 ) ;
V_4 -> V_61 = V_100 ;
}
if ( V_27 != V_4 -> V_107 ) {
V_4 -> V_107 = V_27 ;
} else {
V_101 = 1 ;
F_14 ( V_34 , L_10 ) ;
}
}
if ( V_4 && ! V_101 && ( ( V_4 -> V_30 & V_108 ) == V_109 ) ) {
F_14 ( V_102 , L_11 ) ;
V_4 -> V_110 = & V_4 -> V_111 ;
if ( V_11 -> V_23 & V_112 ) {
F_52 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_113 ) &&
( V_4 -> V_104 == V_87 ) ) {
int V_114 = V_4 -> V_115 ;
V_4 -> V_116 = V_27 ;
F_53 ( V_4 , V_114 ) ;
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
V_4 = F_21 ( V_4 , V_13 , V_98 , V_7 -> V_9 ) ;
break;
case V_118 :
F_14 ( V_34 , L_13 ) ;
if ( V_4 )
F_54 ( V_4 ) ;
break;
case V_119 : {
struct V_120 * V_15 =
(struct V_120 * ) ( V_13 + 1 ) ;
F_14 ( V_34 , L_14 ) ;
if ( V_4 && ( V_4 -> V_104 & V_87 ) ) {
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
F_41 ( V_4 , V_15 -> V_89 ,
V_15 -> V_90 , V_15 -> V_91 ,
V_13 -> V_29 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_124 :
if ( V_4 && ( V_4 -> V_104 & V_87 ) ) {
struct V_125 * V_126 =
(struct V_125 * ) ( V_13 + 1 ) ;
if ( V_101 )
break;
F_55 ( V_4 , V_126 -> V_127 , V_13 ) ;
}
break;
default:
F_14 ( V_34 , L_16 , V_13 -> type ) ;
}
V_13 = F_56 ( V_13 ) ;
}
V_81:
if ( V_4 )
F_38 ( V_4 ) ;
F_57 ( V_7 ) ;
}
void F_58 ( void )
{
struct V_128 * V_129 , * V_130 ;
F_22 ( & V_131 ) ;
F_59 (b, t, &g_binding, link) {
F_44 ( & V_129 -> V_62 ) ;
F_29 ( & V_131 ) ;
F_60 ( & V_129 -> V_132 ) ;
if ( V_129 -> V_132 . V_9 )
F_39 ( V_129 -> V_132 . V_9 ) ;
F_45 ( V_129 ) ;
F_22 ( & V_131 ) ;
}
F_29 ( & V_131 ) ;
F_22 ( & V_46 ) ;
while ( ! F_61 ( & V_63 ) ) {
struct V_3 * V_4 =
F_62 ( & V_63 , struct V_3 , V_62 ) ;
F_63 ( V_4 ) ;
F_29 ( & V_46 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
F_22 ( & V_46 ) ;
}
F_29 ( & V_46 ) ;
F_14 ( V_34 , L_17 ) ;
F_64 ( V_133 ) ;
F_64 ( V_134 ) ;
}
void F_65 ( unsigned long V_135 )
{
struct V_3 * V_4 = (struct V_3 * ) V_135 ;
T_2 V_33 = 0 ;
F_22 ( & V_46 ) ;
if ( V_4 -> V_104 & V_87 )
V_33 = V_4 -> V_32 ;
F_29 ( & V_46 ) ;
if ( V_33 )
F_66 ( V_4 , V_33 ) ;
F_38 ( V_4 ) ;
}
void F_67 ( unsigned long V_135 )
{
int type ;
struct V_3 * V_4 = (struct V_3 * ) V_135 ;
F_22 ( & V_46 ) ;
type = V_4 -> V_136 ;
F_29 ( & V_46 ) ;
switch ( type ) {
case V_47 :
F_54 ( V_4 ) ;
break;
case V_137 :
F_37 ( V_4 ) ;
break;
}
F_38 ( V_4 ) ;
}
enum V_138 F_68 ( struct V_139 * V_140 )
{
struct V_3 * V_4 ;
V_4 = F_69 ( V_140 , struct V_3 , V_141 ) ;
F_70 ( V_140 , F_71 ( V_4 -> V_78 /
V_106 , ( V_4 -> V_78 % V_106 ) * V_142 ) ) ;
F_63 ( V_4 ) ;
F_72 ( & V_4 -> V_143 ) ;
return V_144 ;
}
enum V_138 F_73 ( struct V_139 * V_140 )
{
struct V_3 * V_4 ;
V_4 = F_69 ( V_140 , struct V_3 , V_145 ) ;
F_63 ( V_4 ) ;
F_72 ( & V_4 -> V_146 ) ;
return V_147 ;
}
void F_19 ( struct V_3 * V_4 , int type , unsigned long V_148 )
{
F_22 ( & V_46 ) ;
switch ( type ) {
case V_47 :
case V_137 :
if ( F_74 ( & V_4 -> V_145 ) ) {
F_75 ( & V_4 -> V_145 , F_71 ( V_148 /
V_106 , ( V_148 % V_106 ) *
V_142 ) ) ;
F_76 ( & V_4 -> V_145 , V_149 ) ;
} else {
F_77 ( & V_4 -> V_145 , F_71 ( V_148 /
V_106 , ( V_148 % V_106 ) *
V_142 ) , V_149 ) ;
}
V_4 -> V_136 = type ;
break;
case V_150 :
if ( ! F_74 ( & V_4 -> V_141 ) )
F_77 ( & V_4 -> V_141 , F_71 ( V_148 /
V_106 , ( V_148 % V_106 ) *
V_142 ) , V_149 ) ;
break;
}
F_29 ( & V_46 ) ;
}
void F_36 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_150 , V_4 -> V_78 > 0 ?
V_4 -> V_78 : V_79 ) ;
}
struct V_3 * F_51 ( const T_1 * V_20 )
{
struct V_3 * V_4 ;
F_22 ( & V_46 ) ;
F_43 (pd, &g_pd_list, link) {
if ( F_27 ( V_4 -> V_20 , V_20 ) ) {
F_63 ( V_4 ) ;
F_29 ( & V_46 ) ;
return V_4 ;
}
}
F_29 ( & V_46 ) ;
return NULL ;
}
void F_78 ( int V_127 , int V_151 )
{
if ( V_127 < V_152 ) {
F_22 ( & V_46 ) ;
if ( V_151 )
V_55 |= ( 1 << V_127 ) ;
else
V_55 &= ~ ( 1 << V_127 ) ;
F_29 ( & V_46 ) ;
}
}
static int F_79 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_153 * V_154 , struct V_8 * V_155 )
{
V_7 = F_80 ( V_7 , V_17 ) ;
if ( V_7 == NULL )
return 0 ;
F_22 ( & V_156 . V_157 ) ;
if ( V_158 ) {
F_81 ( & V_156 , V_7 ) ;
F_29 ( & V_156 . V_157 ) ;
} else {
V_158 = 1 ;
do {
F_29 ( & V_156 . V_157 ) ;
F_46 ( V_7 ) ;
F_22 ( & V_156 . V_157 ) ;
if ( F_82 ( & V_156 ) ) {
V_158 = 0 ;
F_29 ( & V_156 . V_157 ) ;
break;
}
V_7 = F_83 ( & V_156 ) ;
} while ( 1 );
}
return 0 ;
}
void F_84 ( const char * V_10 )
{
struct V_128 * V_159 ;
V_159 = F_85 ( sizeof( struct V_128 ) , V_160 ) ;
if ( ! V_159 )
return;
V_159 -> V_132 . type = F_9 ( V_19 ) ;
V_159 -> V_132 . V_161 = F_79 ;
if ( V_10 && * V_10 ) {
memcpy ( V_159 -> V_162 , V_10 , V_163 ) ;
F_14 ( V_34 , L_18 , V_10 ) ;
V_159 -> V_132 . V_9 = F_86 ( & V_164 , V_10 ) ;
if ( V_159 -> V_132 . V_9 == NULL ) {
F_14 ( V_34 , L_19 , V_10 ) ;
F_45 ( V_159 ) ;
return;
}
}
F_87 ( & V_159 -> V_132 ) ;
F_22 ( & V_131 ) ;
F_28 ( & V_159 -> V_62 , & V_165 ) ;
F_29 ( & V_131 ) ;
}
static void F_88 ( struct V_8 * V_10 )
{
F_89 ( V_166 ) ;
struct V_3 * V_4 ;
struct V_3 * V_167 ;
F_22 ( & V_46 ) ;
F_59 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_90 ( & V_4 -> V_62 , & V_166 ) ;
F_63 ( V_4 ) ;
}
}
F_29 ( & V_46 ) ;
while ( ! F_61 ( & V_166 ) ) {
V_4 = F_62 ( & V_166 , struct V_3 , V_62 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
}
}
void F_91 ( const char * V_10 )
{
struct V_128 * V_159 ;
int V_95 = 0 ;
F_14 ( V_34 , L_20 , V_10 ) ;
F_22 ( & V_131 ) ;
F_43 (binding, &g_binding, link) {
if ( strncmp ( V_159 -> V_162 , V_10 , V_163 ) == 0 ) {
F_14 ( V_34 , L_21 , V_10 ) ;
V_95 = 1 ;
break;
}
}
F_29 ( & V_131 ) ;
if ( V_95 ) {
F_60 ( & V_159 -> V_132 ) ;
if ( V_159 -> V_132 . V_9 ) {
F_39 ( V_159 -> V_132 . V_9 ) ;
F_88 ( V_159 -> V_132 . V_9 ) ;
}
F_44 ( & V_159 -> V_62 ) ;
F_45 ( V_159 ) ;
}
}
static char * F_92 ( char * V_168 , char * V_169 , int V_170 )
{
while ( * V_168 == ',' )
V_168 ++ ;
while ( * V_168 && ( * V_168 != ',' ) && V_170 > 1 ) {
* V_169 ++ = * V_168 ++ ;
V_170 -- ;
}
* V_169 = 0 ;
return V_168 ;
}
int F_93 ( char * V_171 )
{
V_134 = F_94 ( V_172 , 0 ) ;
if ( ! V_134 )
return - V_173 ;
V_133 = F_94 ( V_174 , 0 ) ;
if ( ! V_133 ) {
F_64 ( V_134 ) ;
return - V_173 ;
}
F_95 ( & V_156 ) ;
if ( V_171 [ 0 ] == '*' ) {
F_84 ( NULL ) ;
} else {
char V_175 [ 32 ] ;
while ( * V_171 ) {
V_171 = F_92 ( V_171 , V_175 , sizeof( V_175 ) ) ;
if ( V_175 [ 0 ] )
F_84 ( V_175 ) ;
}
}
return 0 ;
}
int F_96 ( struct V_176 * V_177 , int V_178 )
{
struct V_3 * V_4 ;
int V_179 = 0 ;
F_22 ( & V_46 ) ;
F_43 (pd, &g_pd_list, link) {
if ( V_179 >= V_178 )
break;
F_97 ( ( T_1 * ) & V_177 [ V_179 ++ ] , V_4 -> V_20 ) ;
}
F_29 ( & V_46 ) ;
return V_179 ;
}
