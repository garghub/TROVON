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
F_14 ( L_1 , V_5 ) ;
F_15 ( V_7 ) ;
return;
}
static void F_16 ( struct V_3 * V_4 , T_1 V_34 )
{
unsigned long V_35 = V_34 & V_36 ;
switch ( V_34 & V_37 ) {
case V_38 :
V_4 -> V_39 =
F_17 ( V_35 * 1000 * 60 * 60 * 24 * 20 ) ;
break;
case V_40 :
V_4 -> V_39 = F_17 ( V_35 * 1000 ) ;
break;
case V_41 :
V_4 -> V_39 = F_17 ( V_35 * 1000 * 60 ) ;
break;
case V_42 :
V_4 -> V_39 = F_17 ( V_35 * 1000 * 60 * 60 ) ;
break;
default:
V_4 -> V_39 = 0 ;
}
F_14 ( L_2 , V_4 -> V_39 ) ;
}
static void F_18 ( struct V_3 * V_4 , T_1 V_43 )
{
if ( V_43 )
V_4 -> V_44 = F_17 ( V_43 * 100 ) ;
else
V_4 -> V_44 = V_45 ;
F_14 ( L_3 , V_4 -> V_44 ) ;
}
static struct V_3 * F_19 ( struct V_3 * V_46 , struct V_12 * V_13 ,
const T_1 * V_47 , struct V_8 * V_10 )
{
struct V_3 * V_4 ;
struct V_48 * V_15 =
(struct V_48 * ) ( V_13 + 1 ) ;
T_1 V_49 = V_50 ;
T_1 V_51 = 0 ;
T_2 V_52 = V_53 ;
struct V_8 * V_54 = NULL ;
struct V_3 * V_55 = NULL ;
if ( V_46 ) {
V_4 = V_46 ;
F_20 ( & V_56 ) ;
} else {
struct V_3 * V_57 = NULL ;
struct V_58 * V_59 ;
V_4 = F_21 ( V_47 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_60 = V_61 ;
F_20 ( & V_56 ) ;
F_22 (e, &g_pd_list) {
V_57 = F_23 ( V_59 , struct V_3 , V_62 ) ;
if ( memcmp ( V_57 -> V_20 , V_47 , V_63 ) == 0 ) {
V_55 = V_4 ;
V_4 = V_57 ;
break;
}
}
if ( V_4 != V_57 )
F_24 ( & V_4 -> V_62 , & V_64 ) ;
}
if ( V_4 == NULL ) {
F_25 ( & V_56 ) ;
return NULL ;
}
if ( V_4 -> V_10 != V_10 ) {
V_54 = V_4 -> V_10 ;
F_26 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
}
F_14 ( L_4 , V_15 -> V_65 ) ;
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
F_14 ( L_5 ,
V_4 -> V_66 , V_4 -> V_70 ) ;
V_4 -> V_78 = 3 * 1024 ;
V_4 -> V_79 = V_61 + V_80 ;
V_4 -> V_81 = V_82 ;
F_18 ( V_4 , V_15 -> V_43 ) ;
F_16 ( V_4 , V_15 -> V_35 ) ;
V_52 &= F_27 ( F_28 ( & V_15 -> V_33 ) ) ;
if ( ( V_52 & 0x1 ) && ( V_15 -> V_31 ) ) {
if ( V_4 -> V_31 ) {
if ( V_4 -> V_31 != V_15 -> V_31 ) {
V_49 = V_83 ;
goto V_84;
}
} else {
V_52 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
} else {
if ( V_4 -> V_31 && ! V_15 -> V_31 ) {
V_49 = V_85 ;
V_51 = 1 ;
} else {
V_52 &= ~ 0x1 ;
V_4 -> V_31 =
F_1 ( V_15 -> V_31 ) ;
}
}
V_84:
if ( V_49 == V_50 ) {
T_2 V_86 = V_52 & ~ V_4 -> V_32 & ~ 0x1 ;
T_2 V_87 = V_4 -> V_32 & ~ V_52 & ~ 0x1 ;
T_2 V_88 = V_52 & V_4 -> V_89 & ~ 0x1 ;
F_25 ( & V_56 ) ;
F_29 ( V_4 , V_90 ) ;
F_30 ( V_4 , V_91 ) ;
F_14 ( L_6 ,
V_52 , V_4 -> V_32 , V_4 -> V_89 ) ;
if ( V_86 ) {
if ( F_31 ( V_4 , V_86 , 0 ) )
V_49 = V_92 ;
}
if ( V_88 )
if ( F_31 ( V_4 , V_88 , 1 ) )
V_49 = V_92 ;
if ( V_87 )
F_32 ( V_4 , V_87 , 0 ) ;
F_33 ( V_4 ) ;
} else {
F_25 ( & V_56 ) ;
}
F_2 ( V_4 , V_49 ) ;
if ( V_49 != V_50 ) {
if ( V_51 )
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
V_4 = NULL ;
}
if ( V_54 )
F_36 ( V_54 ) ;
if ( V_55 )
F_37 ( V_55 ) ;
return V_4 ;
}
static void F_38 ( struct V_3 * V_4 , T_1 V_93 , T_1 V_94 ,
const T_1 * V_95 , T_1 V_22 )
{
struct V_96 * V_97 ;
struct V_96 * V_98 ;
int V_99 = 0 ;
V_97 = F_39 ( sizeof( struct V_96 ) + V_22 - 1 , V_17 ) ;
if ( ! V_97 )
return;
V_97 -> V_93 = V_93 ;
V_97 -> V_94 = V_94 ;
memcpy ( V_97 -> V_95 , V_95 , V_22 ) ;
F_14 ( L_7 ) ;
F_40 ( & V_56 ) ;
F_41 (f2, &pd->farewell_list, link) {
if ( ( V_98 -> V_93 == V_93 ) && ( V_98 -> V_94 == V_94 ) ) {
V_99 = 1 ;
F_42 ( & V_98 -> V_62 ) ;
break;
}
}
F_24 ( & V_97 -> V_62 , & V_4 -> V_100 ) ;
F_43 ( & V_56 ) ;
if ( V_99 )
F_44 ( V_98 ) ;
}
static void F_45 ( struct V_6 * V_7 )
{
T_1 * V_101 ;
T_1 * V_102 ;
struct V_12 * V_13 ;
int V_29 ;
struct V_3 * V_4 = NULL ;
struct V_11 * V_11 = (struct V_11 * ) F_46 ( V_7 ) ;
int V_103 = 0 ;
T_3 V_27 ;
F_47 ( V_104 ,
L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_101 = F_48 ( V_7 ) ;
V_102 = & V_101 [ V_63 ] ;
V_29 = V_7 -> V_22 ;
if ( F_49 ( V_11 -> V_23 ) != V_24 ) {
F_14 ( L_9 ,
F_49 ( V_11 -> V_23 ) ) ;
goto V_84;
}
V_27 = F_50 ( F_28 ( & V_11 -> V_27 ) ) ;
V_4 = F_51 ( V_102 ) ;
if ( V_4 ) {
V_4 -> V_60 = V_61 ;
F_52 ( V_4 , V_105 ,
V_4 -> V_60 + V_4 -> V_44 , 1 ) ;
if ( V_27 != V_4 -> V_106 ) {
V_4 -> V_106 = V_27 ;
} else {
V_103 = 1 ;
F_14 ( L_10 ) ;
}
}
if ( V_4 && ! V_103 && ( ( V_4 -> V_30 & V_107 ) == V_108 ) ) {
F_47 ( V_104 , L_11 ) ;
V_4 -> V_109 = & V_4 -> V_110 ;
if ( V_11 -> V_23 & V_111 ) {
F_53 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_112 ) &&
( V_4 -> V_113 == V_90 ) ) {
int V_114 = V_4 -> V_115 ;
V_4 -> V_116 = V_27 ;
F_54 ( V_4 , V_114 ) ;
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
F_14 ( L_12 ) ;
V_4 = F_19 ( V_4 , V_13 , V_102 , V_7 -> V_9 ) ;
break;
case V_118 :
F_14 ( L_13 ) ;
if ( V_4 )
F_55 ( V_4 ) ;
break;
case V_119 : {
struct V_120 * V_15 =
(struct V_120 * ) ( V_13 + 1 ) ;
F_14 ( L_14 ) ;
if ( V_4 && ( V_4 -> V_113 & V_90 ) ) {
F_40 ( & V_56 ) ;
F_16 ( V_4 , V_15 -> V_121 ) ;
F_18 ( V_4 , V_15 -> V_43 ) ;
F_43 ( & V_56 ) ;
}
}
break;
case V_122 : {
struct V_123 * V_15 =
(struct V_123 * ) ( V_13 + 1 ) ;
F_14 ( L_15 ) ;
F_38 ( V_4 , V_15 -> V_93 ,
V_15 -> V_94 , V_15 -> V_95 ,
V_13 -> V_29 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_124 :
if ( V_4 && ( V_4 -> V_113 & V_90 ) ) {
struct V_125 * V_126 =
(struct V_125 * ) ( V_13 + 1 ) ;
if ( V_103 )
break;
F_56 ( V_4 , V_126 -> V_127 , V_13 ) ;
}
break;
default:
F_14 ( L_16 , V_13 -> type ) ;
}
V_13 = F_57 ( V_13 ) ;
}
V_84:
if ( V_4 )
F_35 ( V_4 ) ;
F_58 ( V_7 ) ;
}
void F_59 ( void )
{
struct V_58 * V_128 ;
F_60 ( & V_129 ) ;
F_20 ( & V_130 ) ;
while ( V_131 ) {
struct V_132 * V_133 = V_131 ;
V_131 = V_133 -> V_134 ;
F_25 ( & V_130 ) ;
F_61 ( & V_133 -> V_135 ) ;
if ( V_133 -> V_135 . V_9 )
F_36 ( V_133 -> V_135 . V_9 ) ;
F_44 ( V_133 ) ;
F_20 ( & V_130 ) ;
}
F_25 ( & V_130 ) ;
F_20 ( & V_56 ) ;
while ( ! F_62 ( & V_64 ) ) {
struct V_3 * V_4 =
F_63 ( & V_64 , struct V_3 , V_62 ) ;
F_64 ( V_4 ) ;
F_25 ( & V_56 ) ;
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
F_20 ( & V_56 ) ;
}
V_128 = V_136 ;
V_136 = NULL ;
F_25 ( & V_56 ) ;
while ( V_128 ) {
struct V_137 * V_138 = F_23 ( V_128 , struct V_137 , V_62 ) ;
V_128 = V_128 -> V_134 ;
F_44 ( V_138 ) ;
}
F_14 ( L_17 ) ;
}
static void F_65 ( struct V_3 * V_4 , int type )
{
switch ( type ) {
case V_105 :
F_55 ( V_4 ) ;
break;
case V_91 :
F_34 ( V_4 ) ;
break;
case V_139 : {
T_2 V_33 = 0 ;
F_20 ( & V_56 ) ;
V_4 -> V_140 = 0 ;
if ( V_4 -> V_113 & V_90 )
V_33 = V_4 -> V_32 ;
F_25 ( & V_56 ) ;
if ( V_33 )
F_66 ( V_4 , V_33 ) ;
}
break;
}
}
static void F_67 ( unsigned long V_141 )
{
struct V_137 * V_138 ;
struct V_137 * V_142 ;
struct V_3 * V_4 ;
F_20 ( & V_56 ) ;
if ( ! V_143 ) {
F_25 ( & V_56 ) ;
return;
}
V_144 = V_145 ;
V_138 = V_143 ;
V_143 = NULL ;
F_42 ( & V_138 -> V_62 ) ;
F_25 ( & V_56 ) ;
do {
V_4 = V_138 -> V_4 ;
F_65 ( V_4 , V_138 -> type ) ;
F_20 ( & V_56 ) ;
if ( V_146 < V_147 ) {
V_138 -> V_62 . V_134 = V_136 ;
V_136 = & V_138 -> V_62 ;
V_146 ++ ;
V_138 = NULL ;
}
if ( ! F_62 ( & V_148 ) ) {
V_142 = F_23 ( V_148 . V_134 ,
struct V_137 , V_62 ) ;
if ( F_68 ( V_142 -> V_149 , V_61 ) )
F_42 ( & V_142 -> V_62 ) ;
else
V_142 = NULL ;
} else {
V_142 = NULL ;
}
F_25 ( & V_56 ) ;
F_35 ( V_4 ) ;
F_44 ( V_138 ) ;
V_138 = V_142 ;
} while ( V_138 );
V_144 = V_150 ;
F_69 () ;
}
static void F_69 ( void )
{
F_20 ( & V_56 ) ;
if ( ! F_62 ( & V_148 ) ) {
V_143 =
F_23 ( V_148 . V_134 , struct V_137 , V_62 ) ;
if ( V_144 == V_151 ) {
F_70 ( & V_129 , V_143 -> V_149 ) ;
} else {
V_129 . V_152 = V_143 -> V_149 ;
V_129 . V_153 = F_67 ;
V_129 . V_154 = 0 ;
F_71 ( & V_129 ) ;
}
V_144 = V_151 ;
} else {
F_14 ( L_18 ) ;
}
F_25 ( & V_56 ) ;
}
void F_52 ( struct V_3 * V_4 , int type , unsigned long V_149 ,
int remove )
{
struct V_58 * V_59 ;
struct V_137 * V_138 = NULL ;
int V_155 = 0 ;
F_40 ( & V_56 ) ;
if ( remove ) {
F_22 (e, &g_timer_list) {
V_138 = F_23 ( V_59 , struct V_137 , V_62 ) ;
if ( ( V_138 -> V_4 == V_4 ) && ( V_138 -> type == type ) ) {
if ( V_143 == V_138 ) {
V_155 = 1 ;
V_143 = NULL ;
}
F_42 ( V_59 ) ;
break;
}
V_138 = NULL ;
}
}
if ( ! V_138 ) {
if ( V_136 ) {
V_138 = F_23 ( V_136 , struct V_137 , V_62 ) ;
V_136 = V_136 -> V_134 ;
V_146 -- ;
} else {
V_138 = F_39 ( sizeof( struct V_137 ) , V_17 ) ;
}
if ( V_138 ) {
V_138 -> V_4 = V_4 ;
V_138 -> type = type ;
F_64 ( V_4 ) ;
}
}
if ( V_138 ) {
struct V_137 * V_142 ;
V_138 -> V_149 = V_149 ;
F_22 (e, &g_timer_list) {
V_142 = F_23 ( V_59 , struct V_137 , V_62 ) ;
if ( F_72 ( V_149 , V_142 -> V_149 ) ) {
if ( V_142 == V_143 ) {
V_143 = NULL ;
V_155 = 1 ;
}
break;
}
}
F_24 ( & V_138 -> V_62 , V_59 ) ;
}
if ( V_144 == V_150 )
V_155 = 1 ;
else if ( V_144 == V_145 )
V_155 = 0 ;
F_43 ( & V_56 ) ;
if ( V_155 )
F_69 () ;
}
void F_30 ( struct V_3 * V_4 , int type )
{
struct V_58 * V_128 = NULL ;
struct V_137 * V_138 ;
struct V_137 * V_156 ;
int V_155 = 0 ;
int V_157 = 0 ;
F_40 ( & V_56 ) ;
F_73 (t, n, &g_timer_list, link) {
if ( ( V_138 -> V_4 == V_4 ) && ( ( type == 0 ) || ( V_138 -> type == type ) ) ) {
if ( V_143 == V_138 ) {
V_155 = 1 ;
V_143 = NULL ;
F_74 ( & V_129 ) ;
}
F_42 ( & V_138 -> V_62 ) ;
V_157 ++ ;
if ( V_146 < V_147 ) {
V_138 -> V_62 . V_134 = V_136 ;
V_136 = & V_138 -> V_62 ;
V_146 ++ ;
} else {
V_138 -> V_62 . V_134 = V_128 ;
V_128 = & V_138 -> V_62 ;
}
if ( type )
break;
}
}
if ( V_144 == V_145 )
V_155 = 0 ;
else if ( V_155 )
V_144 = V_150 ;
F_43 ( & V_56 ) ;
if ( V_155 )
F_69 () ;
while ( V_157 -- )
F_35 ( V_4 ) ;
while ( V_128 ) {
V_138 = F_23 ( V_128 , struct V_137 , V_62 ) ;
V_128 = V_128 -> V_134 ;
F_44 ( V_138 ) ;
}
}
void F_33 ( struct V_3 * V_4 )
{
unsigned long V_158 = V_61 ;
unsigned long V_138 ;
F_40 ( & V_56 ) ;
if ( V_4 -> V_140 ) {
F_43 ( & V_56 ) ;
return;
}
if ( V_4 -> V_81 )
V_138 = ( ( V_158 / V_4 -> V_81 ) + 1 ) * V_4 -> V_81 ;
else
V_138 = V_158 + 1 ;
V_4 -> V_140 = 1 ;
F_43 ( & V_56 ) ;
F_52 ( V_4 , V_139 , V_138 , 0 ) ;
}
struct V_3 * F_51 ( const T_1 * V_20 )
{
struct V_3 * V_4 ;
struct V_58 * V_59 ;
F_20 ( & V_56 ) ;
F_22 (e, &g_pd_list) {
V_4 = F_23 ( V_59 , struct V_3 , V_62 ) ;
if ( memcmp ( V_4 -> V_20 , V_20 , V_63 ) == 0 ) {
F_75 ( & V_4 -> V_159 ) ;
F_25 ( & V_56 ) ;
return V_4 ;
}
}
F_25 ( & V_56 ) ;
return NULL ;
}
void F_76 ( int V_127 , int V_160 )
{
if ( V_127 <= V_161 ) {
F_20 ( & V_56 ) ;
if ( V_160 )
V_53 |= ( 1 << V_127 ) ;
else
V_53 &= ~ ( 1 << V_127 ) ;
F_25 ( & V_56 ) ;
}
}
static int F_77 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_162 * V_163 , struct V_8 * V_164 )
{
V_7 = F_78 ( V_7 , V_17 ) ;
if ( V_7 == NULL )
return 0 ;
F_20 ( & V_165 . V_166 ) ;
if ( V_167 ) {
F_79 ( & V_165 , V_7 ) ;
F_25 ( & V_165 . V_166 ) ;
} else {
V_167 = 1 ;
do {
F_25 ( & V_165 . V_166 ) ;
F_45 ( V_7 ) ;
F_20 ( & V_165 . V_166 ) ;
if ( F_80 ( & V_165 ) ) {
V_167 = 0 ;
F_25 ( & V_165 . V_166 ) ;
break;
}
V_7 = F_81 ( & V_165 ) ;
} while ( 1 );
}
return 0 ;
}
void F_82 ( char * V_10 )
{
struct V_132 * V_168 ;
V_168 = F_39 ( sizeof( struct V_132 ) , V_169 ) ;
if ( V_168 ) {
V_168 -> V_135 . type = F_83 ( V_19 ) ;
V_168 -> V_135 . V_170 = F_77 ;
memcpy ( V_168 -> V_171 , V_10 , V_172 ) ;
if ( V_10 && * V_10 ) {
F_14 ( L_19 , V_10 ) ;
V_168 -> V_135 . V_9 =
F_84 ( & V_173 , V_10 ) ;
if ( V_168 -> V_135 . V_9 == NULL ) {
F_14 ( L_20 , V_10 ) ;
F_44 ( V_168 ) ;
V_168 = NULL ;
}
} else {
F_14 ( L_21 ) ;
V_168 -> V_135 . V_9 = NULL ;
}
if ( V_168 ) {
F_85 ( & V_168 -> V_135 ) ;
F_20 ( & V_130 ) ;
V_168 -> V_134 = V_131 ;
V_131 = V_168 ;
F_25 ( & V_130 ) ;
}
}
}
static int F_86 ( char * V_174 , char * V_175 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
if ( * V_174 != * V_175 )
return 0 ;
if ( ! * V_174 ++ )
return 1 ;
V_175 ++ ;
}
return 1 ;
}
static void F_87 ( struct V_8 * V_10 )
{
struct V_58 V_177 ;
struct V_3 * V_4 ;
struct V_3 * V_156 ;
F_88 ( & V_177 ) ;
F_20 ( & V_56 ) ;
F_73 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_89 ( & V_4 -> V_62 , & V_177 ) ;
F_64 ( V_4 ) ;
}
}
F_25 ( & V_56 ) ;
while ( ! F_62 ( & V_177 ) ) {
V_4 = F_63 ( & V_177 , struct V_3 , V_62 ) ;
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
}
}
void F_90 ( char * V_10 )
{
struct V_132 * V_168 ;
struct V_132 * * V_62 ;
F_14 ( L_22 , V_10 ) ;
F_20 ( & V_130 ) ;
V_168 = V_131 ;
V_62 = & V_131 ;
while ( V_168 ) {
if ( F_86 ( V_168 -> V_171 , V_10 ) ) {
F_14 ( L_23 , V_10 ) ;
* V_62 = V_168 -> V_134 ;
break;
} else {
V_62 = & V_168 ;
V_168 = V_168 -> V_134 ;
}
}
F_25 ( & V_130 ) ;
if ( V_168 ) {
F_61 ( & V_168 -> V_135 ) ;
if ( V_168 -> V_135 . V_9 ) {
F_36 ( V_168 -> V_135 . V_9 ) ;
F_87 ( V_168 -> V_135 . V_9 ) ;
}
F_44 ( V_168 ) ;
}
}
static char * F_91 ( char * V_178 , char * V_179 , int V_180 )
{
while ( * V_178 == ',' )
V_178 ++ ;
while ( * V_178 && ( * V_178 != ',' ) && V_180 > 1 ) {
* V_179 ++ = * V_178 ++ ;
V_180 -- ;
}
* V_179 = 0 ;
return V_178 ;
}
int F_92 ( char * V_181 )
{
F_93 ( & V_165 ) ;
if ( V_181 && ( V_181 [ 0 ] == '*' ) ) {
F_82 ( NULL ) ;
} else {
char V_182 [ 32 ] ;
while ( * V_181 ) {
V_181 = F_91 ( V_181 , V_182 , sizeof( V_182 ) ) ;
if ( V_182 [ 0 ] )
F_82 ( V_182 ) ;
}
}
F_94 ( & V_129 ) ;
return 0 ;
}
int F_95 ( struct V_183 * V_184 , int V_185 )
{
struct V_3 * V_4 ;
struct V_58 * V_59 ;
int V_186 = 0 ;
F_20 ( & V_56 ) ;
F_22 (e, &g_pd_list) {
if ( V_186 >= V_185 )
break;
V_4 = F_23 ( V_59 , struct V_3 , V_62 ) ;
memcpy ( & V_184 [ V_186 ++ ] , V_4 -> V_20 , V_63 ) ;
}
F_25 ( & V_56 ) ;
return V_186 ;
}
void F_96 ( void )
{
F_20 ( & V_56 ) ;
}
void F_97 ( void )
{
F_25 ( & V_56 ) ;
}
