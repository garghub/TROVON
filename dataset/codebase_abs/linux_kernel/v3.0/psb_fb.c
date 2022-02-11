void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_2 -> V_5 ;
return V_4 -> V_6 ;
}
static int F_2 ( unsigned V_7 , unsigned V_8 , unsigned V_9 ,
unsigned V_10 , unsigned V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
T_1 V_20 ;
if ( ! V_18 )
return - V_21 ;
if ( V_7 > 255 )
return 1 ;
V_8 = F_3 ( V_8 , V_13 -> V_22 . V_8 . V_23 ) ;
V_10 = F_3 ( V_10 , V_13 -> V_22 . V_10 . V_23 ) ;
V_9 = F_3 ( V_9 , V_13 -> V_22 . V_9 . V_23 ) ;
V_11 = F_3 ( V_11 , V_13 -> V_22 . V_11 . V_23 ) ;
V_20 = ( V_8 << V_13 -> V_22 . V_8 . V_24 ) |
( V_9 << V_13 -> V_22 . V_9 . V_24 ) |
( V_10 << V_13 -> V_22 . V_10 . V_24 ) |
( V_11 << V_13 -> V_22 . V_11 . V_24 ) ;
if ( V_7 < 16 ) {
switch ( V_18 -> V_25 ) {
case 16 :
( ( T_1 * ) V_13 -> V_26 ) [ V_7 ] = V_20 ;
break;
case 24 :
case 32 :
( ( T_1 * ) V_13 -> V_26 ) [ V_7 ] = V_20 ;
break;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_27 )
{
struct V_17 * V_18 = 0 ;
struct V_28 * V_29 = F_5 ( V_18 ) ;
F_6 ( L_1 ) ;
F_7 ( & V_2 -> V_30 . V_31 ) ;
F_8 (fb, &dev->mode_config.fb_list, head) {
struct V_12 * V_13 = V_29 -> V_15 ;
if ( V_27 ) {
F_9 ( V_13 , 1 ) ;
F_10 ( V_32 , V_13 ) ;
}
}
F_11 ( & V_2 -> V_30 . V_31 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_33 ,
struct V_34 * V_35 )
{
int V_36 ;
if ( V_37 )
return 0 ;
F_13 () ;
V_36 = F_4 ( V_2 , 0 ) ;
F_14 () ;
return V_36 ;
}
static int F_15 ( struct V_1 * V_2 , int V_38 )
{
struct V_17 * V_18 = 0 ;
struct V_28 * V_29 = F_5 ( V_18 ) ;
F_6 ( L_2 ) ;
F_7 ( & V_2 -> V_30 . V_31 ) ;
F_8 (fb, &dev->mode_config.fb_list, head) {
struct V_12 * V_13 = V_29 -> V_15 ;
if ( V_38 ) {
F_9 ( V_13 , 0 ) ;
F_10 ( V_39 , V_13 ) ;
}
}
F_11 ( & V_2 -> V_30 . V_31 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , void * V_33 ,
struct V_34 * V_35 )
{
int V_36 ;
if ( V_37 )
return 0 ;
F_13 () ;
V_36 = F_15 ( V_2 , 0 ) ;
F_14 () ;
F_17 ( V_2 ) ;
return V_36 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_13 () ;
F_4 ( V_2 , 1 ) ;
F_14 () ;
}
void F_19 ( struct V_1 * V_2 )
{
F_13 () ;
F_15 ( V_2 , 1 ) ;
F_14 () ;
F_17 ( V_2 ) ;
}
static int F_20 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
int V_44 = 0 ;
int V_45 ;
unsigned long V_46 = 0 ;
int V_36 ;
unsigned long V_47 ;
struct V_28 * V_29 = V_41 -> V_48 ;
struct V_1 * V_2 = V_29 -> V_49 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_50 = ( unsigned long ) V_4 -> V_51 ;
V_44 = ( V_41 -> V_52 - V_41 -> V_53 ) >> V_54 ;
V_46 = ( unsigned long ) V_43 -> V_55 ;
V_41 -> V_56 = F_21 ( V_41 -> V_56 ) ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
V_47 = ( V_50 >> V_54 ) ;
V_36 = F_22 ( V_41 , V_46 , V_47 ) ;
if ( F_23 ( ( V_36 == - V_57 ) || ( V_36 != 0 && V_45 > 0 ) ) )
break;
else if ( F_23 ( V_36 != 0 ) ) {
V_36 = ( V_36 == - V_21 ) ? V_58 : V_59 ;
return V_36 ;
}
V_46 += V_60 ;
V_50 += V_60 ;
}
return V_61 ;
}
static void F_24 ( struct V_40 * V_41 )
{
F_6 ( L_3 ) ;
}
static void F_25 ( struct V_40 * V_41 )
{
F_6 ( L_4 ) ;
}
static int F_26 ( struct V_12 * V_13 , struct V_40 * V_41 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_28 * V_29 = V_15 -> V_62 ;
char * V_63 = NULL ;
struct V_1 * V_2 = V_29 -> V_49 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_41 -> V_64 != 0 )
return - V_65 ;
if ( V_41 -> V_64 > ( ~ 0UL >> V_54 ) )
return - V_65 ;
if ( ! V_29 -> V_66 )
V_29 -> V_66 = V_41 -> V_67 -> V_68 ;
V_63 = ( char * ) V_13 -> V_69 ;
F_6 ( L_5 ,
V_41 -> V_64 , V_63 ,
V_4 -> V_70 ) ;
if ( 1 || V_63 == V_4 -> V_70 ) {
V_41 -> V_71 = & V_72 ;
V_41 -> V_48 = ( void * ) V_29 ;
V_41 -> V_73 |= V_74 | V_75 |
V_76 | V_77 ;
} else {
}
return 0 ;
}
static int F_27 ( struct V_12 * V_13 , unsigned int V_78 , unsigned long V_79 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_28 * V_29 = V_15 -> V_62 ;
struct V_1 * V_2 = V_29 -> V_49 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 T_3 * V_80 = ( T_2 T_3 * ) V_79 ;
T_2 V_81 ;
T_2 V_82 [ 32 ] ;
switch ( V_78 ) {
case 0x12345678 :
if ( ! F_28 ( V_83 ) )
return - V_84 ;
if ( F_29 ( V_81 , V_80 ) )
return - V_85 ;
if ( V_81 > 32 )
return - V_86 ;
if ( F_30 ( V_82 , V_80 + 1 , V_81 * sizeof( T_2 ) ) )
return - V_85 ;
F_31 ( V_4 , V_82 , V_81 ) ;
return 0 ;
default:
return - V_87 ;
}
}
static struct V_17 * F_32
( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_28 * V_18 ;
int V_36 ;
V_18 = F_33 ( sizeof( * V_18 ) , V_92 ) ;
if ( ! V_18 )
return NULL ;
V_36 = F_34 ( V_2 , & V_18 -> V_49 , & V_93 ) ;
if ( V_36 )
goto V_94;
F_35 ( & V_18 -> V_49 , V_89 ) ;
V_18 -> V_95 = V_91 ;
return & V_18 -> V_49 ;
V_94:
F_36 ( V_18 ) ;
return NULL ;
}
static struct V_90 * F_37 ( struct V_1 * V_2 , int V_96 )
{
struct V_90 * V_97 ;
V_97 = F_38 ( V_2 , V_96 , L_6 , 1 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_38 ( V_2 , V_96 , L_7 , 0 ) ;
if ( V_97 == NULL )
return NULL ;
if ( F_39 ( V_2 , & V_97 -> V_98 , V_96 ) != 0 ) {
F_40 ( V_2 , V_97 ) ;
return NULL ;
}
return V_97 ;
}
static int F_41 ( struct V_14 * V_15 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_15 -> V_19 . V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 ;
struct V_17 * V_18 ;
struct V_28 * V_29 ;
struct V_88 V_101 ;
struct V_102 * V_102 = & V_2 -> V_103 -> V_2 ;
int V_104 , V_96 ;
int V_36 ;
struct V_90 * V_97 ;
V_101 . V_105 = V_100 -> V_106 ;
V_101 . V_107 = V_100 -> V_108 ;
V_101 . V_109 = 32 ;
V_101 . V_110 = F_42 ( V_101 . V_105 * ( ( V_101 . V_109 + 1 ) / 8 ) , 64 ) ;
V_101 . V_111 = 24 ;
V_104 = V_101 . V_110 * V_101 . V_107 ;
V_96 = F_42 ( V_104 , V_60 ) ;
V_97 = F_37 ( V_2 , V_96 ) ;
if ( V_97 == NULL )
return - V_21 ;
F_7 ( & V_2 -> V_112 ) ;
V_18 = F_32 ( V_2 , & V_101 , V_97 ) ;
if ( ! V_18 ) {
F_43 ( L_8 ) ;
V_36 = - V_21 ;
goto V_113;
}
V_29 = F_5 ( V_18 ) ;
V_13 = F_44 ( sizeof( struct V_14 ) , V_102 ) ;
if ( ! V_13 ) {
V_36 = - V_21 ;
goto V_114;
}
V_13 -> V_16 = V_15 ;
V_29 -> V_15 = V_13 ;
V_15 -> V_19 . V_18 = V_18 ;
V_15 -> V_19 . V_15 = V_13 ;
V_15 -> V_62 = V_29 ;
strcpy ( V_13 -> V_115 . V_116 , L_9 ) ;
V_13 -> V_117 = V_118 ;
V_13 -> V_119 = & V_120 ;
V_13 -> V_115 . V_121 = V_2 -> V_30 . V_122 ;
V_13 -> V_115 . V_123 = V_104 ;
V_13 -> V_69 = ( char * ) V_4 -> V_70 + V_97 -> V_24 ;
V_13 -> V_124 = V_104 ;
memset ( V_13 -> V_69 , 0 , V_104 ) ;
if ( V_4 -> V_125 -> V_126 ) {
V_13 -> V_127 = F_45 ( 1 ) ;
if ( ! V_13 -> V_127 ) {
V_36 = - V_21 ;
goto V_114;
}
V_13 -> V_127 -> V_128 [ 0 ] . V_49 = V_2 -> V_30 . V_122 ;
V_13 -> V_127 -> V_128 [ 0 ] . V_104 = V_4 -> V_125 -> V_126 ;
}
F_46 ( V_13 , V_18 -> V_110 , V_18 -> V_111 ) ;
F_47 ( V_13 , & V_15 -> V_19 ,
V_100 -> V_129 , V_100 -> V_130 ) ;
V_13 -> V_115 . V_131 = F_48 ( V_2 -> V_103 , 0 ) ;
V_13 -> V_115 . V_132 = F_49 ( V_2 -> V_103 , 0 ) ;
V_13 -> V_133 . V_104 = 64 * 1024 ;
V_13 -> V_133 . V_134 = 8 ;
V_13 -> V_133 . V_135 = 32 ;
V_13 -> V_133 . V_117 = V_136 ;
V_13 -> V_133 . V_137 = 1 ;
F_6 ( L_10 , V_18 -> V_111 ) ;
F_6 ( L_11 , V_18 -> V_110 ) ;
F_50 ( V_138 L_12 ,
V_29 -> V_49 . V_105 , V_29 -> V_49 . V_107 ) ;
F_11 ( & V_2 -> V_112 ) ;
return 0 ;
V_114:
V_18 -> V_139 -> V_140 ( V_18 ) ;
V_113:
F_11 ( & V_2 -> V_112 ) ;
F_40 ( V_2 , V_97 ) ;
return V_36 ;
}
static struct V_17 * F_51
( struct V_1 * V_2 , struct V_34 * V_141 ,
struct V_88 * V_78 )
{
struct V_90 * V_89 ;
struct V_142 * V_143 ;
struct V_28 * V_29 ;
V_143 = F_52 ( V_2 , V_141 , V_78 -> V_144 ) ;
if ( V_143 == NULL )
return F_53 ( - V_145 ) ;
V_29 = F_33 ( sizeof( * V_29 ) , V_92 ) ;
if ( V_29 == NULL ) {
F_54 ( V_143 ) ;
return F_53 ( - V_21 ) ;
}
V_89 = F_55 ( V_143 , struct V_90 , V_98 ) ;
if ( F_32 ( V_2 , V_78 , V_89 ) == NULL ) {
F_54 ( V_143 ) ;
F_36 ( V_29 ) ;
return F_53 ( - V_65 ) ;
}
return & V_29 -> V_49 ;
}
static void F_56 ( struct V_146 * V_147 , T_4 V_8 , T_4 V_9 ,
T_4 V_10 , int V_7 )
{
F_6 ( L_13 , V_148 ) ;
}
static void F_57 ( struct V_146 * V_147 , T_4 * V_8 ,
T_4 * V_9 , T_4 * V_10 , int V_7 )
{
F_6 ( L_13 , V_148 ) ;
}
static int F_58 ( struct V_149 * V_150 ,
struct V_99 * V_100 )
{
struct V_14 * V_14 = (struct V_14 * ) V_150 ;
int V_151 = 0 ;
int V_36 ;
F_6 ( L_13 , V_148 ) ;
if ( ! V_150 -> V_18 ) {
V_36 = F_41 ( V_14 , V_100 ) ;
if ( V_36 )
return V_36 ;
V_151 = 1 ;
}
return V_151 ;
}
int F_59 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_28 * V_29 = V_15 -> V_62 ;
if ( V_15 -> V_19 . V_15 ) {
V_13 = V_15 -> V_19 . V_15 ;
if ( V_29 -> V_95 -> V_152 )
F_40 ( V_2 , V_29 -> V_95 ) ;
else
F_60 ( & V_29 -> V_95 -> V_98 ) ;
F_61 ( V_13 ) ;
F_62 ( V_13 -> V_69 ) ;
F_63 ( V_13 ) ;
}
F_64 ( & V_15 -> V_19 ) ;
F_65 ( & V_29 -> V_49 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_153 ;
V_15 = F_33 ( sizeof( struct V_14 ) , V_92 ) ;
if ( ! V_15 ) {
F_43 ( L_14 ) ;
return - V_21 ;
}
V_4 -> V_15 = V_15 ;
V_15 -> V_19 . V_139 = & V_154 ;
V_153 = 2 ;
F_67 ( V_2 , & V_15 -> V_19 , V_153 ,
V_155 ) ;
F_68 ( & V_15 -> V_19 ) ;
F_69 ( & V_15 -> V_19 , 32 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_15 )
return;
F_59 ( V_2 , V_4 -> V_15 ) ;
F_36 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_14 * V_15 = (struct V_14 * ) V_4 -> V_15 ;
F_72 ( & V_15 -> V_19 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_12 * V_13 ;
struct V_28 * V_29 = F_5 ( V_18 ) ;
if ( V_37 )
return 0 ;
V_13 = V_29 -> V_15 ;
if ( V_13 )
F_63 ( V_13 ) ;
return 0 ;
}
static int F_74 ( struct V_17 * V_18 ,
struct V_34 * V_35 ,
unsigned int * V_144 )
{
struct V_28 * V_29 = F_5 ( V_18 ) ;
struct V_90 * V_89 = V_29 -> V_95 ;
if ( V_89 -> V_152 )
return - V_156 ;
return F_75 ( V_35 , & V_89 -> V_98 , V_144 ) ;
}
static void F_76 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_28 * V_29 = F_5 ( V_18 ) ;
struct V_90 * V_89 = V_29 -> V_95 ;
if ( V_29 -> V_15 )
F_73 ( V_2 , V_18 ) ;
F_65 ( V_18 ) ;
F_54 ( & V_89 -> V_98 ) ;
F_36 ( V_18 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4
= (struct V_3 * ) V_2 -> V_5 ;
struct V_157 * V_158 ;
if ( V_4 -> V_159 )
return 0 ;
V_158 = F_78 ( V_2 ,
V_160 ,
L_15 ,
2 ) ;
V_158 -> V_161 [ 0 ] = 0 ;
V_158 -> V_161 [ 1 ] = 100 ;
V_4 -> V_159 = V_158 ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_162 * V_163 ;
F_80 ( L_16 ) ;
F_81 ( V_2 ) ;
F_77 ( V_2 ) ;
if ( F_82 ( V_2 ) ) {
if ( V_4 -> V_164 )
F_83 ( V_2 , & V_4 -> V_165 ) ;
else
F_43 ( L_17 ) ;
} else {
F_84 ( V_2 , & V_4 -> V_165 ) ;
F_85 ( V_2 , V_166 ) ;
}
F_8 (connector, &dev->mode_config.connector_list,
head) {
struct V_167 * V_167 =
F_86 ( V_163 ) ;
struct V_168 * V_169 = & V_167 -> V_170 ;
int V_171 = 0 , V_172 = 0 ;
switch ( V_167 -> type ) {
case V_173 :
V_171 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_172 = ( 1 << V_173 ) ;
break;
case V_174 :
F_80 ( L_18 ) ;
if ( F_82 ( V_2 ) )
V_171 = ( 1 << 0 ) ;
else
V_171 = ( 1 << 1 ) ;
V_172 = ( 1 << V_174 ) ;
break;
case V_175 :
F_80 ( L_19 ) ;
V_171 = ( 1 << 0 ) ;
V_172 = ( 1 << V_175 ) ;
break;
case V_176 :
F_80 ( L_20 ) ;
V_171 = ( 1 << 2 ) ;
V_172 = ( 1 << V_176 ) ;
break;
case V_177 :
F_80 ( L_21 ) ;
V_171 = ( 1 << 1 ) ;
V_172 = ( 1 << V_177 ) ;
break;
}
V_169 -> V_178 = V_171 ;
V_169 -> V_179 =
F_87 ( V_2 , V_172 ) ;
}
}
void F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 -> V_5 ;
struct V_180 * V_165 = & V_4 -> V_165 ;
int V_45 ;
F_80 ( L_16 ) ;
F_89 ( V_2 ) ;
V_2 -> V_30 . V_181 = 0 ;
V_2 -> V_30 . V_182 = 0 ;
V_2 -> V_30 . V_139 = ( void * ) & V_183 ;
F_90 ( V_2 -> V_103 , V_184 , ( T_2 * )
& ( V_2 -> V_30 . V_122 ) ) ;
for ( V_45 = 0 ; V_45 < V_4 -> V_185 ; V_45 ++ )
F_91 ( V_2 , V_45 , V_165 ) ;
V_2 -> V_30 . V_186 = 2048 ;
V_2 -> V_30 . V_187 = 2048 ;
F_79 ( V_2 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_112 ) ;
F_93 ( V_2 ) ;
F_70 ( V_2 ) ;
F_94 ( V_2 ) ;
F_11 ( & V_2 -> V_112 ) ;
}
