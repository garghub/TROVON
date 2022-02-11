static inline
struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
void * V_6 ;
V_6 = V_3 -> V_7 ;
V_6 += V_5 -> V_8 ;
return V_6 ;
}
static T_1 F_2 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
unsigned int V_12 , V_13 ;
T_3 V_14 ;
V_12 = V_3 -> V_7 -> V_15 ;
V_13 = V_3 -> V_7 -> V_16 ;
if ( ( V_12 > V_17 ) ||
( V_13 > V_18 ) )
return - V_19 ;
V_14 = F_3 ( V_3 , V_12 , V_13 ) ;
F_4 ( L_1 , V_14 ) ;
return V_11 ;
}
static int F_5 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_12 , V_13 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_2 , & V_12 , & V_13 ) ;
if ( V_20 != 2 )
return - V_21 ;
if ( V_12 > V_17 )
return - V_22 ;
if ( V_13 > V_18 )
return - V_22 ;
if ( V_12 == V_23 ) {
if ( ( V_13 % 2 ) != 0 )
return - V_22 ;
}
V_3 -> V_7 -> V_15 = V_12 ;
V_3 -> V_7 -> V_16 = V_13 ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_12 , V_13 , V_24 , V_25 ;
T_3 V_14 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_3 ,
& V_12 , & V_13 , & V_24 , & V_25 ) ;
if ( V_20 != 4 )
return - V_21 ;
if ( V_12 > V_17 )
return - V_22 ;
if ( V_13 > V_18 )
return - V_22 ;
if ( V_12 == V_23 ) {
if ( ( V_13 % 2 ) != 0 )
return - V_22 ;
}
if ( ( V_24 > 0xFFFF ) || ( V_25 > 0xFFFF ) )
return - V_26 ;
if ( V_24 == 0 )
V_14 = 0 ;
else
V_14 = F_3 ( V_3 , V_12 , V_13 ) ;
V_14 &= V_24 ;
V_14 |= V_25 ;
F_7 ( V_3 , V_12 , V_13 , V_14 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
unsigned int V_12 , V_13 ;
T_4 V_14 ;
V_12 = V_3 -> V_7 -> V_27 ;
V_13 = V_3 -> V_7 -> V_28 ;
if ( ( V_12 > V_17 ) ||
( V_13 > V_18 ) )
return - V_19 ;
V_14 = F_9 ( V_3 , V_12 , V_13 ) ;
F_4 ( L_4 , V_14 ) ;
return V_11 ;
}
static int F_10 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_12 , V_13 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_2 , & V_12 , & V_13 ) ;
if ( V_20 != 2 )
return - V_21 ;
if ( V_12 > V_17 )
return - V_22 ;
if ( V_13 > V_18 )
return - V_22 ;
if ( V_12 == V_23 ) {
if ( ( V_13 % 2 ) != 0 )
return - V_22 ;
}
V_3 -> V_7 -> V_27 = V_12 ;
V_3 -> V_7 -> V_28 = V_13 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_12 , V_13 , V_24 , V_25 ;
T_4 V_14 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_3 ,
& V_12 , & V_13 , & V_24 , & V_25 ) ;
if ( V_20 != 4 )
return - V_21 ;
if ( V_12 > V_17 )
return - V_22 ;
if ( V_13 > V_18 )
return - V_22 ;
if ( V_12 == V_23 ) {
if ( ( V_13 % 2 ) != 0 )
return - V_22 ;
}
if ( ( V_24 > 0xFFFFFFFF ) || ( V_25 > 0xFFFFFFFF ) )
return - V_26 ;
if ( V_24 == 0 )
V_14 = 0 ;
else
V_14 = F_9 ( V_3 , V_12 , V_13 ) ;
V_14 &= V_24 ;
V_14 |= V_25 ;
F_12 ( V_3 , V_12 , V_13 , V_14 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
unsigned int V_13 ;
T_3 V_14 ;
V_13 = V_3 -> V_7 -> V_29 ;
if ( V_13 > V_30 )
return - V_19 ;
V_14 = F_14 ( V_3 , V_13 ) ;
F_4 ( L_1 , V_14 ) ;
return V_11 ;
}
static int F_15 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_13 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_5 , & V_13 ) ;
if ( V_20 != 1 )
return - V_21 ;
if ( V_13 > V_30 )
return - V_22 ;
if ( ( V_13 % 2 ) != 0 )
return - V_21 ;
V_3 -> V_7 -> V_29 = V_13 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_13 , V_24 , V_25 ;
int V_20 ;
T_3 V_14 ;
V_20 = sscanf ( V_9 , L_6 , & V_13 , & V_24 , & V_25 ) ;
if ( V_20 != 3 )
return - V_21 ;
if ( V_13 > V_30 )
return - V_22 ;
if ( ( V_24 > 0xFFFF ) || ( V_25 > 0xFFFF ) )
return - V_26 ;
if ( ( V_13 % 2 ) != 0 )
return - V_21 ;
if ( V_24 == 0 )
V_14 = 0 ;
else
V_14 = F_14 ( V_3 , V_13 ) ;
V_14 &= V_24 ;
V_14 |= V_25 ;
F_17 ( V_3 , V_13 , V_14 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
unsigned int V_13 ;
T_4 V_14 ;
V_13 = V_3 -> V_7 -> V_31 ;
if ( V_13 > V_30 )
return - V_19 ;
V_14 = F_19 ( V_3 , V_13 ) ;
F_4 ( L_4 , V_14 ) ;
return V_11 ;
}
static int F_20 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_13 ;
int V_20 ;
V_20 = sscanf ( V_9 , L_5 , & V_13 ) ;
if ( V_20 != 1 )
return - V_21 ;
if ( V_13 > V_30 )
return - V_22 ;
if ( ( V_13 % 4 ) != 0 )
return - V_21 ;
V_3 -> V_7 -> V_31 = V_13 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
unsigned int V_13 , V_24 , V_25 ;
int V_20 ;
T_4 V_14 ;
V_20 = sscanf ( V_9 , L_6 , & V_13 , & V_24 , & V_25 ) ;
if ( V_20 != 3 )
return - V_21 ;
if ( V_13 > V_30 )
return - V_22 ;
if ( ( V_24 > 0xFFFFFFFF ) || ( V_25 > 0xFFFFFFFF ) )
return - V_26 ;
if ( ( V_13 % 4 ) != 0 )
return - V_21 ;
if ( V_24 == 0 )
V_14 = 0 ;
else
V_14 = F_19 ( V_3 , V_13 ) ;
V_14 &= V_24 ;
V_14 |= V_25 ;
F_22 ( V_3 , V_13 , V_14 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
struct V_32 * log = & V_3 -> V_7 -> V_33 ;
T_1 V_11 = 0 ;
int V_34 , V_35 ;
struct V_36 * V_37 ;
if ( log -> V_38 < 0 ) {
F_4 ( L_7 ) ;
goto V_39;
}
F_4 ( L_8
L_9
L_10
L_11 L_12 ) ;
V_34 = log -> V_38 + 1 ;
V_35 = 0 ;
while ( 1 ) {
if ( V_34 == V_40 )
V_34 = 0 ;
V_37 = & ( log -> log [ V_34 ] ) ;
if ( V_37 -> V_41 ) {
F_4 ( L_13
L_14
L_15
L_16
L_17 ,
V_35 ,
V_37 -> V_41 , V_37 -> V_42 , V_37 -> V_43 ,
V_37 -> V_44 , V_37 -> V_45 ,
V_37 -> V_46 , V_37 -> V_47 ,
V_37 -> V_48 , V_37 -> V_49 ,
V_37 -> V_50 ) ;
V_35 ++ ;
}
if ( V_34 == log -> V_38 )
break;
V_34 ++ ;
}
V_39:
return V_11 ;
}
static int F_24 ( struct V_2 * V_3 ,
const char * V_9 , T_2 V_11 )
{
int V_51 = 0 ;
if ( V_11 > 0 && V_9 [ 0 ] == '1' ) {
F_25 ( V_3 , L_18 ) ;
} else
V_51 = - V_21 ;
return V_51 ;
}
static unsigned long F_26 ( unsigned long V_52 ,
unsigned long time ,
unsigned long V_53 )
{
V_53 = time + V_53 ;
if ( F_27 ( V_52 , V_53 ) )
return 0 ;
if ( V_53 < V_52 ) {
V_53 -= V_54 ;
V_52 -= V_54 ;
}
F_28 ( V_53 < V_52 ) ;
return ( V_53 - V_52 ) / V_55 ;
}
static T_1 F_29 ( struct V_2 * V_3 ,
char * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
struct V_56 * V_57 ;
int V_34 , V_51 = 0 ;
struct V_58 * V_59 ;
unsigned long V_52 = V_60 ;
struct V_61 * V_62 = & V_3 -> V_62 ;
if ( V_62 -> type != V_63 ) {
F_4 ( L_19 ) ;
V_51 = - V_64 ;
goto V_39;
}
V_57 = V_62 -> V_65 -> V_66 ;
F_4 ( L_20 ) ;
F_4 ( L_21 ,
V_3 -> V_62 . V_67 ) ;
F_4 ( L_22 ,
V_57 -> V_68 , V_57 -> V_69 ,
F_26 ( V_52 , V_57 -> V_70 ,
V_71 ) ) ;
F_4 ( L_23 ,
( unsigned int ) ( ( V_57 -> V_72 & 0xFFFFFFFF00000000ULL ) >> 32 ) ,
( unsigned int ) ( V_57 -> V_72 & 0x00000000FFFFFFFFULL ) ,
F_26 ( V_52 , V_57 -> V_73 ,
V_74 ) ) ;
F_4 ( L_24 ) ;
F_30 (cal, &lo->calib_list, list) {
bool V_75 ;
V_75 = ( F_31 ( & V_59 -> V_76 , & V_62 -> V_65 -> V_76 ) &&
F_32 ( & V_59 -> V_77 , & V_62 -> V_65 -> V_77 ) ) ;
F_4 ( L_25
L_26 ,
V_59 -> V_76 . V_78 ,
V_59 -> V_77 . V_78 , V_59 -> V_77 . V_79 ,
V_59 -> V_80 . V_34 , V_59 -> V_80 . V_81 ,
F_26 ( V_52 , V_59 -> V_82 ,
V_83 ) ,
V_75 ? L_27 : L_28 ) ;
}
F_4 ( L_29 ) ;
for ( V_34 = 0 ; V_34 < V_57 -> V_84 . V_85 ; V_34 ++ ) {
F_4 ( L_30 ,
V_57 -> V_84 . V_86 [ V_34 ] . V_78 ,
V_57 -> V_84 . V_86 [ V_34 ] . V_79 ) ;
}
F_4 ( L_31 ) ;
F_4 ( L_32 ) ;
for ( V_34 = 0 ; V_34 < V_57 -> V_87 . V_85 ; V_34 ++ ) {
F_4 ( L_33 ,
V_57 -> V_87 . V_86 [ V_34 ] . V_78 ) ;
}
F_4 ( L_31 ) ;
V_39:
return V_51 ? V_51 : V_11 ;
}
static T_1 F_33 ( struct V_88 * V_88 , char T_5 * V_89 ,
T_2 V_11 , T_6 * V_90 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_91 ;
T_1 V_92 ( V_93 ) ;
char * V_9 ;
const T_2 V_10 = 1024 * 16 ;
const T_2 V_94 = F_34 ( V_10 ) ;
int V_51 = 0 ;
if ( ! V_11 )
return 0 ;
V_3 = V_88 -> V_95 ;
if ( ! V_3 )
return - V_64 ;
F_35 ( & V_3 -> V_96 -> V_97 ) ;
if ( F_36 ( V_3 ) < V_98 ) {
V_51 = - V_64 ;
goto V_99;
}
V_5 = F_37 ( V_88 -> V_100 , struct V_4 , V_101 ) ;
if ( ! V_5 -> V_102 ) {
V_51 = - V_103 ;
goto V_99;
}
V_91 = F_1 ( V_3 , V_5 ) ;
if ( ! V_91 -> V_104 ) {
V_9 = ( char * ) F_38 ( V_105 , V_94 ) ;
if ( ! V_9 ) {
V_51 = - V_106 ;
goto V_99;
}
memset ( V_9 , 0 , V_10 ) ;
V_93 = V_5 -> V_102 ( V_3 , V_9 , V_10 ) ;
if ( V_93 <= 0 ) {
F_39 ( ( unsigned long ) V_9 , V_94 ) ;
V_51 = V_93 ;
goto V_99;
}
V_91 -> V_107 = V_93 ;
V_91 -> V_104 = V_9 ;
}
V_93 = F_40 ( V_89 , V_11 , V_90 ,
V_91 -> V_104 ,
V_91 -> V_107 ) ;
if ( * V_90 >= V_91 -> V_107 ) {
F_39 ( ( unsigned long ) V_91 -> V_104 , V_94 ) ;
V_91 -> V_104 = NULL ;
V_91 -> V_107 = 0 ;
}
V_99:
F_41 ( & V_3 -> V_96 -> V_97 ) ;
return V_51 ? V_51 : V_93 ;
}
static T_1 F_42 ( struct V_88 * V_88 ,
const char T_5 * V_89 ,
T_2 V_11 , T_6 * V_90 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
char * V_9 ;
int V_51 = 0 ;
if ( ! V_11 )
return 0 ;
if ( V_11 > V_108 )
return - V_26 ;
V_3 = V_88 -> V_95 ;
if ( ! V_3 )
return - V_64 ;
F_35 ( & V_3 -> V_96 -> V_97 ) ;
if ( F_36 ( V_3 ) < V_98 ) {
V_51 = - V_64 ;
goto V_99;
}
V_5 = F_37 ( V_88 -> V_100 , struct V_4 , V_101 ) ;
if ( ! V_5 -> V_109 ) {
V_51 = - V_103 ;
goto V_99;
}
V_9 = ( char * ) F_43 ( V_105 ) ;
if ( ! V_9 ) {
V_51 = - V_106 ;
goto V_99;
}
if ( F_44 ( V_9 , V_89 , V_11 ) ) {
V_51 = - V_110 ;
goto V_111;
}
V_51 = V_5 -> V_109 ( V_3 , V_9 , V_11 ) ;
if ( V_51 )
goto V_111;
V_111:
F_45 ( ( unsigned long ) V_9 ) ;
V_99:
F_41 ( & V_3 -> V_96 -> V_97 ) ;
return V_51 ? V_51 : V_11 ;
}
bool F_46 ( struct V_2 * V_3 , enum V_112 V_113 )
{
bool V_114 ;
V_114 = ( V_3 -> V_7 && V_3 -> V_7 -> V_115 [ V_113 ] ) ;
if ( F_47 ( V_114 ) ) {
V_116 = V_117 ;
}
return V_114 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_7 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_120 ; V_34 ++ )
F_49 ( V_119 -> V_121 [ V_34 ] ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_7 ;
struct V_122 * V_123 ;
#define F_51 ( T_7 , T_8 , T_9 ) do { \
e->dyn_debug[id] = (initstate); \
d = debugfs_create_bool(name, 0600, e->subdir, \
&(e->dyn_debug[id])); \
if (!IS_ERR(d)) \
e->dyn_debug_dentries[id] = d; \
} while (0)
F_51 ( L_34 , V_124 , 0 ) ;
F_51 ( L_35 , V_125 , 0 ) ;
F_51 ( L_36 , V_126 , 0 ) ;
F_51 ( L_37 , V_127 , 0 ) ;
F_51 ( L_38 , V_128 , 0 ) ;
F_51 ( L_39 , V_129 , 0 ) ;
F_51 ( L_40 , V_130 , 0 ) ;
F_51 ( L_41 , V_131 , 0 ) ;
F_51 ( L_42 , V_132 , 0 ) ;
#undef F_51
}
void F_52 ( struct V_2 * V_3 )
{
struct V_118 * V_119 ;
struct V_32 * log ;
char V_133 [ 16 ] ;
F_28 ( ! V_3 ) ;
V_119 = F_53 ( sizeof( * V_119 ) , V_105 ) ;
if ( ! V_119 ) {
F_54 ( V_3 -> V_96 , L_43 ) ;
return;
}
V_119 -> V_3 = V_3 ;
log = & V_119 -> V_33 ;
log -> log = F_55 ( V_40 ,
sizeof( struct V_36 ) , V_105 ) ;
if ( ! log -> log ) {
F_54 ( V_3 -> V_96 , L_44 ) ;
F_56 ( V_119 ) ;
return;
}
log -> V_38 = - 1 ;
V_3 -> V_7 = V_119 ;
snprintf ( V_133 , sizeof( V_133 ) , L_45 , F_57 ( V_3 -> V_96 -> V_134 -> V_135 ) ) ;
V_119 -> V_136 = F_58 ( V_133 , V_137 ) ;
if ( ! V_119 -> V_136 || F_59 ( V_119 -> V_136 ) ) {
if ( V_119 -> V_136 == F_60 ( - V_64 ) ) {
F_61 ( V_3 -> V_96 , L_46
L_47 ) ;
} else {
F_54 ( V_3 -> V_96 , L_48 ,
V_133 ) ;
}
V_3 -> V_7 = NULL ;
F_56 ( log -> log ) ;
F_56 ( V_119 ) ;
return;
}
V_119 -> V_29 = 0xFFFF ;
V_119 -> V_31 = 0xFFFF ;
V_119 -> V_15 = 0xFFFFFFFF ;
V_119 -> V_16 = 0xFFFFFFFF ;
V_119 -> V_27 = 0xFFFFFFFF ;
V_119 -> V_28 = 0xFFFFFFFF ;
#define F_62 ( T_7 , T_10 ) \
do { \
struct dentry *d; \
d = debugfs_create_file(__stringify(name), \
mode, e->subdir, dev, \
&fops_##name.fops); \
e->file_##name.dentry = NULL; \
if (!IS_ERR(d)) \
e->file_##name.dentry = d; \
} while (0)
F_62 ( V_138 , 0600 ) ;
F_62 ( V_139 , 0200 ) ;
F_62 ( V_140 , 0600 ) ;
F_62 ( V_141 , 0200 ) ;
F_62 ( V_142 , 0600 ) ;
F_62 ( V_143 , 0200 ) ;
F_62 ( V_144 , 0600 ) ;
F_62 ( V_145 , 0200 ) ;
F_62 ( V_146 , 0400 ) ;
F_62 ( V_147 , 0200 ) ;
F_62 ( V_148 , 0400 ) ;
#undef F_62
F_50 ( V_3 ) ;
}
void F_63 ( struct V_2 * V_3 )
{
struct V_118 * V_119 ;
if ( ! V_3 )
return;
V_119 = V_3 -> V_7 ;
if ( ! V_119 )
return;
F_48 ( V_3 ) ;
F_49 ( V_119 -> V_149 . V_122 ) ;
F_49 ( V_119 -> V_150 . V_122 ) ;
F_49 ( V_119 -> V_151 . V_122 ) ;
F_49 ( V_119 -> V_152 . V_122 ) ;
F_49 ( V_119 -> V_153 . V_122 ) ;
F_49 ( V_119 -> V_154 . V_122 ) ;
F_49 ( V_119 -> V_155 . V_122 ) ;
F_49 ( V_119 -> V_156 . V_122 ) ;
F_49 ( V_119 -> V_157 . V_122 ) ;
F_49 ( V_119 -> V_158 . V_122 ) ;
F_49 ( V_119 -> V_159 . V_122 ) ;
F_49 ( V_119 -> V_136 ) ;
F_56 ( V_119 -> V_33 . log ) ;
F_56 ( V_119 ) ;
}
void F_64 ( struct V_2 * V_3 ,
const struct V_36 * V_160 )
{
struct V_118 * V_119 = V_3 -> V_7 ;
struct V_32 * log ;
struct V_36 * V_161 ;
int V_34 ;
if ( ! V_119 )
return;
log = & V_119 -> V_33 ;
V_34 = log -> V_38 + 1 ;
if ( V_34 == V_40 )
V_34 = 0 ;
log -> V_38 = V_34 ;
V_161 = & ( log -> log [ V_34 ] ) ;
memcpy ( V_161 , V_160 , sizeof( * V_161 ) ) ;
}
void F_65 ( void )
{
V_137 = F_58 ( V_162 , NULL ) ;
if ( F_59 ( V_137 ) )
V_137 = NULL ;
}
void F_66 ( void )
{
F_49 ( V_137 ) ;
}
