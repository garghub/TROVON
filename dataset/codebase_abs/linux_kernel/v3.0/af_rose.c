static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 )
{
F_2 ( & V_4 -> V_6 , & V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 , & V_9 ) ;
F_4 ( V_2 , F_1 , NULL ) ;
}
char * F_5 ( char * V_10 , const T_1 * V_11 )
{
if ( V_11 -> V_12 [ 0 ] == 0x00 && V_11 -> V_12 [ 1 ] == 0x00 &&
V_11 -> V_12 [ 2 ] == 0x00 && V_11 -> V_12 [ 3 ] == 0x00 &&
V_11 -> V_12 [ 4 ] == 0x00 ) {
strcpy ( V_10 , L_1 ) ;
} else {
sprintf ( V_10 , L_2 , V_11 -> V_12 [ 0 ] & 0xFF ,
V_11 -> V_12 [ 1 ] & 0xFF ,
V_11 -> V_12 [ 2 ] & 0xFF ,
V_11 -> V_12 [ 3 ] & 0xFF ,
V_11 -> V_12 [ 4 ] & 0xFF ) ;
}
return V_10 ;
}
int F_6 ( T_1 * V_13 , T_1 * V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 5 ; V_15 ++ )
if ( V_13 -> V_12 [ V_15 ] != V_14 -> V_12 [ V_15 ] )
return 1 ;
return 0 ;
}
int F_7 ( T_1 * V_13 , T_1 * V_14 , unsigned short V_16 )
{
unsigned int V_15 , V_17 ;
if ( V_16 > 10 )
return 1 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_17 = V_15 / 2 ;
if ( ( V_15 % 2 ) != 0 ) {
if ( ( V_13 -> V_12 [ V_17 ] & 0x0F ) != ( V_14 -> V_12 [ V_17 ] & 0x0F ) )
return 1 ;
} else {
if ( ( V_13 -> V_12 [ V_17 ] & 0xF0 ) != ( V_14 -> V_12 [ V_17 ] & 0xF0 ) )
return 1 ;
}
}
return 0 ;
}
static void F_8 ( struct V_18 * V_19 )
{
F_9 ( & V_20 ) ;
F_10 ( V_19 ) ;
F_11 ( & V_20 ) ;
}
void F_12 ( struct V_21 * V_22 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_9 ( & V_20 ) ;
F_13 (s, node, &rose_list) {
struct V_26 * V_27 = F_14 ( V_23 ) ;
if ( V_27 -> V_28 == V_22 ) {
F_15 ( V_23 , V_29 , V_30 , 0 ) ;
V_27 -> V_28 -> V_31 -- ;
V_27 -> V_28 = NULL ;
}
}
F_11 ( & V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_9 ( & V_20 ) ;
F_13 (s, node, &rose_list) {
struct V_26 * V_27 = F_14 ( V_23 ) ;
if ( V_27 -> V_32 == V_2 ) {
F_15 ( V_23 , V_29 , V_30 , 0 ) ;
V_27 -> V_28 -> V_31 -- ;
V_27 -> V_32 = NULL ;
}
}
F_11 ( & V_20 ) ;
}
static int F_17 ( struct V_33 * V_34 , unsigned long V_35 ,
void * V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
if ( ! F_18 ( F_19 ( V_2 ) , & V_37 ) )
return V_38 ;
if ( V_35 != V_39 )
return V_38 ;
switch ( V_2 -> type ) {
case V_40 :
F_16 ( V_2 ) ;
break;
case V_41 :
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
break;
}
return V_38 ;
}
static void F_22 ( struct V_18 * V_19 )
{
F_9 ( & V_20 ) ;
F_23 ( V_19 , & V_42 ) ;
F_11 ( & V_20 ) ;
}
static struct V_18 * F_24 ( T_1 * V_11 , T_2 * V_43 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_9 ( & V_20 ) ;
F_13 (s, node, &rose_list) {
struct V_26 * V_27 = F_14 ( V_23 ) ;
if ( ! F_6 ( & V_27 -> V_44 , V_11 ) &&
! F_25 ( & V_27 -> V_45 , V_43 ) &&
! V_27 -> V_46 && V_23 -> V_47 == V_48 )
goto V_49;
}
F_13 (s, node, &rose_list) {
struct V_26 * V_27 = F_14 ( V_23 ) ;
if ( ! F_6 ( & V_27 -> V_44 , V_11 ) &&
! F_25 ( & V_27 -> V_45 , & V_50 ) &&
V_23 -> V_47 == V_48 )
goto V_49;
}
V_23 = NULL ;
V_49:
F_11 ( & V_20 ) ;
return V_23 ;
}
struct V_18 * F_26 ( unsigned int V_51 , struct V_21 * V_22 )
{
struct V_18 * V_23 ;
struct V_24 * V_25 ;
F_9 ( & V_20 ) ;
F_13 (s, node, &rose_list) {
struct V_26 * V_27 = F_14 ( V_23 ) ;
if ( V_27 -> V_51 == V_51 && V_27 -> V_28 == V_22 )
goto V_49;
}
V_23 = NULL ;
V_49:
F_11 ( & V_20 ) ;
return V_23 ;
}
unsigned int F_27 ( struct V_21 * V_22 )
{
int V_51 ;
if ( V_22 -> V_52 ) {
for ( V_51 = 1 ; V_51 <= V_53 ; V_51 ++ )
if ( F_26 ( V_51 , V_22 ) == NULL && F_28 ( V_51 , V_22 ) == NULL )
return V_51 ;
} else {
for ( V_51 = V_53 ; V_51 > 0 ; V_51 -- )
if ( F_26 ( V_51 , V_22 ) == NULL && F_28 ( V_51 , V_22 ) == NULL )
return V_51 ;
}
return 0 ;
}
static void F_29 ( unsigned long V_54 )
{
F_30 ( (struct V_18 * ) V_54 ) ;
}
void F_30 ( struct V_18 * V_19 )
{
struct V_55 * V_56 ;
F_8 ( V_19 ) ;
F_31 ( V_19 ) ;
F_32 ( V_19 ) ;
F_33 ( V_19 ) ;
F_34 ( V_19 ) ;
while ( ( V_56 = F_35 ( & V_19 -> V_57 ) ) != NULL ) {
if ( V_56 -> V_19 != V_19 ) {
F_36 ( V_56 -> V_19 , V_58 ) ;
F_37 ( V_56 -> V_19 ) ;
F_14 ( V_56 -> V_19 ) -> V_59 = V_60 ;
}
F_38 ( V_56 ) ;
}
if ( F_39 ( V_19 ) ) {
F_40 ( & V_19 -> V_61 , F_29 ,
( unsigned long ) V_19 ) ;
V_19 -> V_61 . V_62 = V_63 + 10 * V_64 ;
F_41 ( & V_19 -> V_61 ) ;
} else
F_42 ( V_19 ) ;
}
static int F_43 ( struct V_65 * V_18 , int V_66 , int V_67 ,
char T_3 * V_68 , unsigned int V_69 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
int V_70 ;
if ( V_66 != V_71 )
return - V_72 ;
if ( V_69 < sizeof( int ) )
return - V_73 ;
if ( F_44 ( V_70 , ( int T_3 * ) V_68 ) )
return - V_74 ;
switch ( V_67 ) {
case V_75 :
V_27 -> V_76 = V_70 ? 1 : 0 ;
return 0 ;
case V_77 :
if ( V_70 < 1 )
return - V_73 ;
V_27 -> V_78 = V_70 * V_64 ;
return 0 ;
case V_79 :
if ( V_70 < 1 )
return - V_73 ;
V_27 -> V_80 = V_70 * V_64 ;
return 0 ;
case V_81 :
if ( V_70 < 1 )
return - V_73 ;
V_27 -> V_82 = V_70 * V_64 ;
return 0 ;
case V_83 :
if ( V_70 < 1 )
return - V_73 ;
V_27 -> V_84 = V_70 * V_64 ;
return 0 ;
case V_85 :
if ( V_70 < 0 )
return - V_73 ;
V_27 -> V_86 = V_70 * 60 * V_64 ;
return 0 ;
case V_87 :
V_27 -> V_88 = V_70 ? 1 : 0 ;
return 0 ;
default:
return - V_72 ;
}
}
static int F_45 ( struct V_65 * V_18 , int V_66 , int V_67 ,
char T_3 * V_68 , int T_3 * V_69 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
int V_89 = 0 ;
int V_90 ;
if ( V_66 != V_71 )
return - V_72 ;
if ( F_44 ( V_90 , V_69 ) )
return - V_74 ;
if ( V_90 < 0 )
return - V_73 ;
switch ( V_67 ) {
case V_75 :
V_89 = V_27 -> V_76 ;
break;
case V_77 :
V_89 = V_27 -> V_78 / V_64 ;
break;
case V_79 :
V_89 = V_27 -> V_80 / V_64 ;
break;
case V_81 :
V_89 = V_27 -> V_82 / V_64 ;
break;
case V_83 :
V_89 = V_27 -> V_84 / V_64 ;
break;
case V_85 :
V_89 = V_27 -> V_86 / ( 60 * V_64 ) ;
break;
case V_87 :
V_89 = V_27 -> V_88 ;
break;
default:
return - V_72 ;
}
V_90 = F_46 (unsigned int, len, sizeof(int)) ;
if ( F_47 ( V_90 , V_69 ) )
return - V_74 ;
return F_48 ( V_68 , & V_89 , V_90 ) ? - V_74 : 0 ;
}
static int F_49 ( struct V_65 * V_18 , int V_91 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
if ( V_19 -> V_47 != V_48 ) {
struct V_26 * V_27 = F_14 ( V_19 ) ;
V_27 -> V_92 = 0 ;
memset ( & V_27 -> V_93 , 0 , V_94 ) ;
memset ( & V_27 -> V_95 , 0 , V_96 ) ;
memset ( V_27 -> V_97 , 0 , V_96 * V_98 ) ;
V_19 -> V_99 = V_91 ;
V_19 -> V_47 = V_48 ;
return 0 ;
}
return - V_100 ;
}
static int F_50 ( struct V_101 * V_101 , struct V_65 * V_18 , int V_102 ,
int V_103 )
{
struct V_18 * V_19 ;
struct V_26 * V_27 ;
if ( ! F_18 ( V_101 , & V_37 ) )
return - V_104 ;
if ( V_18 -> type != V_105 || V_102 != 0 )
return - V_106 ;
V_19 = F_51 ( V_101 , V_107 , V_108 , & V_109 ) ;
if ( V_19 == NULL )
return - V_110 ;
V_27 = F_14 ( V_19 ) ;
F_52 ( V_18 , V_19 ) ;
F_53 ( & V_27 -> V_111 ) ;
#ifdef F_54
F_53 ( & V_27 -> V_112 ) ;
V_27 -> V_113 = 0 ;
#endif
V_18 -> V_114 = & V_115 ;
V_19 -> V_116 = V_102 ;
F_55 ( & V_27 -> V_117 ) ;
F_55 ( & V_27 -> V_118 ) ;
V_27 -> V_78 = F_56 ( V_119 ) ;
V_27 -> V_80 = F_56 ( V_120 ) ;
V_27 -> V_82 = F_56 ( V_121 ) ;
V_27 -> V_84 = F_56 ( V_122 ) ;
V_27 -> V_86 = F_56 ( V_123 ) ;
V_27 -> V_59 = V_60 ;
return 0 ;
}
static struct V_18 * F_57 ( struct V_18 * V_124 )
{
struct V_18 * V_19 ;
struct V_26 * V_27 , * V_125 ;
if ( V_124 -> V_126 != V_105 )
return NULL ;
V_19 = F_51 ( F_58 ( V_124 ) , V_107 , V_108 , & V_109 ) ;
if ( V_19 == NULL )
return NULL ;
V_27 = F_14 ( V_19 ) ;
F_52 ( NULL , V_19 ) ;
F_53 ( & V_27 -> V_111 ) ;
#ifdef F_54
F_53 ( & V_27 -> V_112 ) ;
V_27 -> V_113 = 0 ;
#endif
V_19 -> V_126 = V_124 -> V_126 ;
V_19 -> V_127 = V_124 -> V_127 ;
V_19 -> V_116 = V_124 -> V_116 ;
V_19 -> V_128 = V_124 -> V_128 ;
V_19 -> V_129 = V_124 -> V_129 ;
V_19 -> V_47 = V_130 ;
F_59 ( V_19 , V_124 ) ;
F_55 ( & V_27 -> V_117 ) ;
F_55 ( & V_27 -> V_118 ) ;
V_125 = F_14 ( V_124 ) ;
V_27 -> V_78 = V_125 -> V_78 ;
V_27 -> V_80 = V_125 -> V_80 ;
V_27 -> V_82 = V_125 -> V_82 ;
V_27 -> V_84 = V_125 -> V_84 ;
V_27 -> V_86 = V_125 -> V_86 ;
V_27 -> V_76 = V_125 -> V_76 ;
V_27 -> V_32 = V_125 -> V_32 ;
V_27 -> V_88 = V_125 -> V_88 ;
return V_19 ;
}
static int F_60 ( struct V_65 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 ;
if ( V_19 == NULL ) return 0 ;
F_61 ( V_19 ) ;
F_62 ( V_19 ) ;
F_63 ( V_19 ) ;
V_27 = F_14 ( V_19 ) ;
switch ( V_27 -> V_59 ) {
case V_60 :
F_64 ( V_19 ) ;
F_15 ( V_19 , 0 , - 1 , - 1 ) ;
F_63 ( V_19 ) ;
F_30 ( V_19 ) ;
break;
case V_131 :
V_27 -> V_28 -> V_31 -- ;
F_64 ( V_19 ) ;
F_15 ( V_19 , 0 , - 1 , - 1 ) ;
F_63 ( V_19 ) ;
F_30 ( V_19 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_34 ( V_19 ) ;
F_32 ( V_19 ) ;
F_65 ( V_19 , V_136 ) ;
F_66 ( V_19 ) ;
V_27 -> V_59 = V_131 ;
V_19 -> V_47 = V_137 ;
V_19 -> V_138 |= V_139 ;
V_19 -> V_140 ( V_19 ) ;
F_36 ( V_19 , V_58 ) ;
F_36 ( V_19 , V_141 ) ;
break;
default:
break;
}
V_18 -> V_19 = NULL ;
F_64 ( V_19 ) ;
F_42 ( V_19 ) ;
return 0 ;
}
static int F_67 ( struct V_65 * V_18 , struct V_142 * V_143 , int V_144 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
struct V_145 * V_11 = (struct V_145 * ) V_143 ;
struct V_1 * V_2 ;
T_2 * V_146 ;
T_4 * V_147 ;
int V_148 ;
if ( ! F_68 ( V_19 , V_149 ) )
return - V_73 ;
if ( V_144 != sizeof( struct V_145 ) && V_144 != sizeof( struct V_150 ) )
return - V_73 ;
if ( V_11 -> V_151 != V_152 )
return - V_73 ;
if ( V_144 == sizeof( struct V_145 ) && V_11 -> V_153 > 1 )
return - V_73 ;
if ( ( unsigned int ) V_11 -> V_153 > V_98 )
return - V_73 ;
if ( ( V_2 = F_69 ( & V_11 -> V_154 ) ) == NULL )
return - V_155 ;
V_146 = & V_11 -> V_156 ;
V_147 = F_70 ( F_71 () ) ;
if ( V_147 ) {
V_27 -> V_45 = V_147 -> V_43 ;
F_72 ( V_147 ) ;
} else {
if ( V_157 && ! F_73 ( V_158 ) )
return - V_159 ;
V_27 -> V_45 = * V_146 ;
}
V_27 -> V_44 = V_11 -> V_154 ;
V_27 -> V_32 = V_2 ;
V_27 -> V_46 = V_11 -> V_153 ;
if ( V_144 == sizeof( struct V_150 ) ) {
struct V_150 * V_160 = (struct V_150 * ) V_143 ;
for ( V_148 = 0 ; V_148 < V_11 -> V_153 ; V_148 ++ )
V_27 -> V_161 [ V_148 ] = V_160 -> V_162 [ V_148 ] ;
} else {
if ( V_27 -> V_46 == 1 ) {
V_27 -> V_161 [ 0 ] = V_11 -> V_163 ;
}
}
F_22 ( V_19 ) ;
F_74 ( V_19 , V_149 ) ;
return 0 ;
}
static int F_75 ( struct V_65 * V_18 , struct V_142 * V_143 , int V_144 , int V_164 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
struct V_145 * V_11 = (struct V_145 * ) V_143 ;
unsigned char V_165 , V_166 ;
struct V_1 * V_2 ;
T_4 * V_147 ;
int V_148 , V_167 = 0 ;
if ( V_144 != sizeof( struct V_145 ) && V_144 != sizeof( struct V_150 ) )
return - V_73 ;
if ( V_11 -> V_151 != V_152 )
return - V_73 ;
if ( V_144 == sizeof( struct V_145 ) && V_11 -> V_153 > 1 )
return - V_73 ;
if ( ( unsigned int ) V_11 -> V_153 > V_98 )
return - V_73 ;
if ( ( V_27 -> V_46 + V_11 -> V_153 ) > V_98 )
return - V_73 ;
F_63 ( V_19 ) ;
if ( V_19 -> V_47 == V_130 && V_18 -> V_59 == V_168 ) {
V_18 -> V_59 = V_169 ;
goto V_170;
}
if ( V_19 -> V_47 == V_137 && V_18 -> V_59 == V_168 ) {
V_18 -> V_59 = V_171 ;
V_167 = - V_172 ;
goto V_170;
}
if ( V_19 -> V_47 == V_130 ) {
V_167 = - V_173 ;
goto V_170;
}
V_19 -> V_47 = V_137 ;
V_18 -> V_59 = V_171 ;
V_27 -> V_28 = F_76 ( & V_11 -> V_154 , & V_165 ,
& V_166 , 0 ) ;
if ( ! V_27 -> V_28 ) {
V_167 = - V_29 ;
goto V_170;
}
V_27 -> V_51 = F_27 ( V_27 -> V_28 ) ;
if ( ! V_27 -> V_51 ) {
V_167 = - V_29 ;
goto V_170;
}
if ( F_68 ( V_19 , V_149 ) ) {
F_74 ( V_19 , V_149 ) ;
if ( ( V_2 = F_77 () ) == NULL ) {
V_167 = - V_29 ;
goto V_170;
}
V_147 = F_70 ( F_71 () ) ;
if ( ! V_147 ) {
V_167 = - V_73 ;
goto V_170;
}
memcpy ( & V_27 -> V_44 , V_2 -> V_174 , V_94 ) ;
V_27 -> V_45 = V_147 -> V_43 ;
V_27 -> V_32 = V_2 ;
F_72 ( V_147 ) ;
F_22 ( V_19 ) ;
}
V_27 -> V_93 = V_11 -> V_154 ;
V_27 -> V_95 = V_11 -> V_156 ;
V_27 -> rand = ( ( long ) V_27 & 0xFFFF ) + V_27 -> V_51 ;
V_27 -> V_92 = V_11 -> V_153 ;
if ( V_144 == sizeof( struct V_150 ) ) {
struct V_150 * V_160 = (struct V_150 * ) V_143 ;
for ( V_148 = 0 ; V_148 < V_11 -> V_153 ; V_148 ++ )
V_27 -> V_97 [ V_148 ] = V_160 -> V_162 [ V_148 ] ;
} else {
if ( V_27 -> V_92 == 1 ) {
V_27 -> V_97 [ 0 ] = V_11 -> V_163 ;
}
}
V_18 -> V_59 = V_168 ;
V_19 -> V_47 = V_175 ;
V_27 -> V_59 = V_132 ;
V_27 -> V_28 -> V_31 ++ ;
F_65 ( V_19 , V_176 ) ;
F_37 ( V_19 ) ;
F_78 ( V_19 ) ;
if ( V_19 -> V_47 != V_130 && ( V_164 & V_177 ) ) {
V_167 = - V_178 ;
goto V_170;
}
if ( V_19 -> V_47 == V_175 ) {
F_79 ( V_179 ) ;
for (; ; ) {
F_80 ( F_81 ( V_19 ) , & V_179 ,
V_180 ) ;
if ( V_19 -> V_47 != V_175 )
break;
if ( ! F_82 ( V_181 ) ) {
F_64 ( V_19 ) ;
F_83 () ;
F_63 ( V_19 ) ;
continue;
}
V_167 = - V_182 ;
break;
}
F_84 ( F_81 ( V_19 ) , & V_179 ) ;
if ( V_167 )
goto V_170;
}
if ( V_19 -> V_47 != V_130 ) {
V_18 -> V_59 = V_171 ;
V_167 = F_85 ( V_19 ) ;
goto V_170;
}
V_18 -> V_59 = V_169 ;
V_170:
F_64 ( V_19 ) ;
return V_167 ;
}
static int F_86 ( struct V_65 * V_18 , struct V_65 * V_183 , int V_164 )
{
struct V_55 * V_56 ;
struct V_18 * V_184 ;
F_79 ( V_179 ) ;
struct V_18 * V_19 ;
int V_167 = 0 ;
if ( ( V_19 = V_18 -> V_19 ) == NULL )
return - V_73 ;
F_63 ( V_19 ) ;
if ( V_19 -> V_126 != V_105 ) {
V_167 = - V_100 ;
goto V_170;
}
if ( V_19 -> V_47 != V_48 ) {
V_167 = - V_73 ;
goto V_170;
}
for (; ; ) {
F_80 ( F_81 ( V_19 ) , & V_179 , V_180 ) ;
V_56 = F_35 ( & V_19 -> V_57 ) ;
if ( V_56 )
break;
if ( V_164 & V_177 ) {
V_167 = - V_185 ;
break;
}
if ( ! F_82 ( V_181 ) ) {
F_64 ( V_19 ) ;
F_83 () ;
F_63 ( V_19 ) ;
continue;
}
V_167 = - V_182 ;
break;
}
F_84 ( F_81 ( V_19 ) , & V_179 ) ;
if ( V_167 )
goto V_170;
V_184 = V_56 -> V_19 ;
F_87 ( V_184 , V_183 ) ;
V_56 -> V_19 = NULL ;
F_38 ( V_56 ) ;
V_19 -> V_186 -- ;
V_170:
F_64 ( V_19 ) ;
return V_167 ;
}
static int F_88 ( struct V_65 * V_18 , struct V_142 * V_143 ,
int * V_187 , int V_188 )
{
struct V_150 * V_189 = (struct V_150 * ) V_143 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
int V_148 ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
if ( V_188 != 0 ) {
if ( V_19 -> V_47 != V_130 )
return - V_190 ;
V_189 -> V_151 = V_152 ;
V_189 -> V_154 = V_27 -> V_93 ;
V_189 -> V_156 = V_27 -> V_95 ;
V_189 -> V_153 = V_27 -> V_92 ;
for ( V_148 = 0 ; V_148 < V_27 -> V_92 ; V_148 ++ )
V_189 -> V_162 [ V_148 ] = V_27 -> V_97 [ V_148 ] ;
} else {
V_189 -> V_151 = V_152 ;
V_189 -> V_154 = V_27 -> V_44 ;
V_189 -> V_156 = V_27 -> V_45 ;
V_189 -> V_153 = V_27 -> V_46 ;
for ( V_148 = 0 ; V_148 < V_27 -> V_46 ; V_148 ++ )
V_189 -> V_162 [ V_148 ] = V_27 -> V_161 [ V_148 ] ;
}
* V_187 = sizeof( struct V_150 ) ;
return 0 ;
}
int F_89 ( struct V_55 * V_56 , struct V_1 * V_2 , struct V_21 * V_22 , unsigned int V_51 )
{
struct V_18 * V_19 ;
struct V_18 * V_191 ;
struct V_26 * V_192 ;
struct V_193 V_194 ;
int V_148 ;
V_56 -> V_19 = NULL ;
memset ( & V_194 , 0x00 , sizeof( struct V_193 ) ) ;
if ( ! F_90 ( V_56 -> V_54 + V_195 ,
V_56 -> V_90 - V_195 ,
& V_194 ) ) {
F_91 ( V_22 , V_51 , V_196 , 76 ) ;
return 0 ;
}
V_19 = F_24 ( & V_194 . V_44 , & V_194 . V_45 ) ;
if ( V_19 == NULL || F_92 ( V_19 ) ||
( V_191 = F_57 ( V_19 ) ) == NULL ) {
F_91 ( V_22 , V_51 , V_197 , 120 ) ;
return 0 ;
}
V_56 -> V_19 = V_191 ;
V_191 -> V_47 = V_130 ;
V_192 = F_14 ( V_191 ) ;
V_192 -> V_51 = V_51 ;
V_192 -> V_93 = V_194 . V_93 ;
V_192 -> V_95 = V_194 . V_95 ;
V_192 -> V_92 = V_194 . V_92 ;
for ( V_148 = 0 ; V_148 < V_194 . V_92 ; V_148 ++ )
V_192 -> V_97 [ V_148 ] = V_194 . V_97 [ V_148 ] ;
V_192 -> V_44 = V_194 . V_44 ;
V_192 -> V_45 = V_194 . V_45 ;
V_192 -> V_46 = V_194 . V_46 ;
for ( V_148 = 0 ; V_148 < V_194 . V_46 ; V_148 ++ )
V_192 -> V_161 [ V_148 ] = V_194 . V_161 [ V_148 ] ;
V_192 -> V_28 = V_22 ;
V_192 -> V_32 = V_2 ;
V_192 -> V_194 = V_194 ;
V_192 -> V_28 -> V_31 ++ ;
if ( F_14 ( V_19 ) -> V_76 ) {
V_192 -> V_59 = V_135 ;
} else {
F_65 ( V_191 , V_198 ) ;
V_192 -> V_59 = V_133 ;
F_93 ( V_191 ) ;
}
V_192 -> V_199 = 0x00 ;
V_192 -> V_200 = 0 ;
V_192 -> V_201 = 0 ;
V_192 -> V_202 = 0 ;
V_192 -> V_203 = 0 ;
V_19 -> V_186 ++ ;
F_22 ( V_191 ) ;
F_94 ( & V_19 -> V_57 , V_56 ) ;
F_37 ( V_191 ) ;
if ( ! F_68 ( V_19 , V_58 ) )
V_19 -> V_204 ( V_19 , V_56 -> V_90 ) ;
return 1 ;
}
static int F_95 ( struct V_205 * V_206 , struct V_65 * V_18 ,
struct V_207 * V_208 , T_5 V_90 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
struct V_145 * V_209 = (struct V_145 * ) V_208 -> V_210 ;
int V_167 ;
struct V_150 V_189 ;
struct V_55 * V_56 ;
unsigned char * V_211 ;
int V_148 , V_212 , V_213 = 0 ;
if ( V_208 -> V_214 & ~ ( V_215 | V_216 | V_217 ) )
return - V_73 ;
if ( F_68 ( V_19 , V_149 ) )
return - V_155 ;
if ( V_19 -> V_138 & V_139 ) {
F_96 ( V_218 , V_181 , 0 ) ;
return - V_219 ;
}
if ( V_27 -> V_28 == NULL || V_27 -> V_32 == NULL )
return - V_29 ;
if ( V_209 != NULL ) {
if ( V_208 -> V_220 != sizeof( struct V_145 ) && V_208 -> V_220 != sizeof( struct V_150 ) )
return - V_73 ;
memset ( & V_189 , 0 , sizeof( struct V_150 ) ) ;
memcpy ( & V_189 , V_209 , V_208 -> V_220 ) ;
if ( F_6 ( & V_27 -> V_93 , & V_189 . V_154 ) != 0 ||
F_25 ( & V_27 -> V_95 , & V_189 . V_156 ) != 0 )
return - V_173 ;
if ( V_189 . V_153 != V_27 -> V_92 )
return - V_173 ;
if ( V_189 . V_153 == V_27 -> V_92 ) {
for ( V_148 = 0 ; V_148 < V_189 . V_153 ; V_148 ++ )
if ( F_25 ( & V_27 -> V_97 [ V_148 ] ,
& V_189 . V_162 [ V_148 ] ) )
return - V_173 ;
}
if ( V_189 . V_151 != V_152 )
return - V_73 ;
} else {
if ( V_19 -> V_47 != V_130 )
return - V_190 ;
V_189 . V_151 = V_152 ;
V_189 . V_154 = V_27 -> V_93 ;
V_189 . V_156 = V_27 -> V_95 ;
V_189 . V_153 = V_27 -> V_92 ;
for ( V_148 = 0 ; V_148 < V_27 -> V_92 ; V_148 ++ )
V_189 . V_162 [ V_148 ] = V_27 -> V_97 [ V_148 ] ;
}
if ( V_90 > 65535 )
return - V_221 ;
V_212 = V_90 + V_222 + V_223 + V_224 ;
if ( ( V_56 = F_97 ( V_19 , V_212 , V_208 -> V_214 & V_215 , & V_167 ) ) == NULL )
return V_167 ;
F_98 ( V_56 , V_222 + V_223 + V_224 ) ;
F_99 ( V_56 ) ;
F_100 ( V_56 , V_90 ) ;
V_167 = F_101 ( F_102 ( V_56 ) , V_208 -> V_225 , V_90 ) ;
if ( V_167 ) {
F_38 ( V_56 ) ;
return V_167 ;
}
if ( V_27 -> V_88 ) {
V_213 = V_56 -> V_54 [ 0 ] ;
F_103 ( V_56 , 1 ) ;
}
V_211 = F_104 ( V_56 , V_224 ) ;
V_211 [ 0 ] = ( ( V_27 -> V_51 >> 8 ) & 0x0F ) | V_226 ;
V_211 [ 1 ] = ( V_27 -> V_51 >> 0 ) & 0xFF ;
V_211 [ 2 ] = V_227 ;
if ( V_213 )
V_211 [ 0 ] |= V_228 ;
if ( V_19 -> V_47 != V_130 ) {
F_38 ( V_56 ) ;
return - V_190 ;
}
#ifdef F_54
#define F_105 (256-ROSE_MIN_LEN)
if ( V_56 -> V_90 - V_224 > F_105 ) {
unsigned char V_229 [ V_224 ] ;
struct V_55 * V_230 ;
int V_231 ;
int V_232 ;
F_106 ( V_56 , V_229 , V_224 ) ;
F_103 ( V_56 , V_224 ) ;
V_231 = F_107 ( V_56 ) ;
while ( V_56 -> V_90 > 0 ) {
if ( ( V_230 = F_97 ( V_19 , V_231 + F_105 , 0 , & V_167 ) ) == NULL ) {
F_38 ( V_56 ) ;
return V_167 ;
}
V_230 -> V_19 = V_19 ;
V_230 -> free = 1 ;
V_230 -> V_233 = 1 ;
F_98 ( V_230 , V_231 ) ;
V_232 = ( F_105 > V_56 -> V_90 ) ? V_56 -> V_90 : F_105 ;
F_106 ( V_56 , F_100 ( V_230 , V_232 ) , V_232 ) ;
F_103 ( V_56 , V_232 ) ;
F_104 ( V_230 , V_224 ) ;
F_108 ( V_230 , V_229 , V_224 ) ;
if ( V_56 -> V_90 > 0 )
V_230 -> V_54 [ 2 ] |= F_54 ;
F_109 ( & V_19 -> V_234 , V_230 ) ;
}
V_56 -> free = 1 ;
F_38 ( V_56 ) ;
} else {
F_109 ( & V_19 -> V_234 , V_56 ) ;
}
#else
F_109 ( & V_19 -> V_234 , V_56 ) ;
#endif
F_110 ( V_19 ) ;
return V_90 ;
}
static int F_111 ( struct V_205 * V_206 , struct V_65 * V_18 ,
struct V_207 * V_208 , T_5 V_212 , int V_164 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
struct V_145 * V_189 = (struct V_145 * ) V_208 -> V_210 ;
T_5 V_235 ;
unsigned char * V_211 ;
struct V_55 * V_56 ;
int V_148 , V_236 , V_213 ;
if ( V_19 -> V_47 != V_130 )
return - V_190 ;
if ( ( V_56 = F_112 ( V_19 , V_164 & ~ V_215 , V_164 & V_215 , & V_236 ) ) == NULL )
return V_236 ;
V_213 = ( V_56 -> V_54 [ 0 ] & V_228 ) == V_228 ;
F_103 ( V_56 , V_224 ) ;
if ( V_27 -> V_88 ) {
V_211 = F_104 ( V_56 , 1 ) ;
* V_211 = V_213 ;
}
F_99 ( V_56 ) ;
V_235 = V_56 -> V_90 ;
if ( V_235 > V_212 ) {
V_235 = V_212 ;
V_208 -> V_214 |= V_237 ;
}
F_113 ( V_56 , 0 , V_208 -> V_225 , V_235 ) ;
if ( V_189 != NULL ) {
V_189 -> V_151 = V_152 ;
V_189 -> V_154 = V_27 -> V_93 ;
V_189 -> V_156 = V_27 -> V_95 ;
V_189 -> V_153 = V_27 -> V_92 ;
if ( V_208 -> V_220 >= sizeof( struct V_150 ) ) {
struct V_150 * V_238 = (struct V_150 * ) V_208 -> V_210 ;
for ( V_148 = 0 ; V_148 < V_27 -> V_92 ; V_148 ++ )
V_238 -> V_162 [ V_148 ] = V_27 -> V_97 [ V_148 ] ;
V_208 -> V_220 = sizeof( struct V_150 ) ;
} else {
if ( V_27 -> V_92 >= 1 ) {
V_189 -> V_153 = 1 ;
V_189 -> V_163 = V_27 -> V_97 [ 0 ] ;
}
V_208 -> V_220 = sizeof( struct V_145 ) ;
}
}
F_114 ( V_19 , V_56 ) ;
return V_235 ;
}
static int F_115 ( struct V_65 * V_18 , unsigned int V_239 , unsigned long V_240 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_26 * V_27 = F_14 ( V_19 ) ;
void T_3 * V_241 = ( void T_3 * ) V_240 ;
switch ( V_239 ) {
case V_242 : {
long V_243 ;
V_243 = V_19 -> V_129 - F_116 ( V_19 ) ;
if ( V_243 < 0 )
V_243 = 0 ;
return F_47 ( V_243 , ( unsigned int T_3 * ) V_241 ) ;
}
case V_244 : {
struct V_55 * V_56 ;
long V_243 = 0L ;
if ( ( V_56 = F_117 ( & V_19 -> V_57 ) ) != NULL )
V_243 = V_56 -> V_90 ;
return F_47 ( V_243 , ( unsigned int T_3 * ) V_241 ) ;
}
case V_245 :
return F_118 ( V_19 , (struct V_246 T_3 * ) V_241 ) ;
case V_247 :
return F_119 ( V_19 , (struct V_248 T_3 * ) V_241 ) ;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
return - V_73 ;
case V_259 :
case V_260 :
case V_261 :
if ( ! F_73 ( V_262 ) )
return - V_263 ;
return F_120 ( V_239 , V_241 ) ;
case V_264 : {
struct V_265 V_266 ;
V_266 . V_165 = V_27 -> V_165 ;
V_266 . V_166 = V_27 -> V_166 ;
return F_48 ( V_241 , & V_266 , sizeof( struct V_265 ) ) ? - V_74 : 0 ;
}
case V_267 : {
struct V_265 V_266 ;
if ( F_121 ( & V_266 , V_241 , sizeof( struct V_265 ) ) )
return - V_74 ;
V_27 -> V_165 = V_266 . V_165 ;
V_27 -> V_166 = V_266 . V_166 ;
return 0 ;
}
case V_268 :
if ( ! F_73 ( V_262 ) ) return - V_263 ;
if ( F_25 ( & V_269 , & V_50 ) != 0 )
F_122 ( & V_269 , NULL ) ;
if ( F_121 ( & V_269 , V_241 , sizeof( T_2 ) ) )
return - V_74 ;
if ( F_25 ( & V_269 , & V_50 ) != 0 )
return F_123 ( & V_269 , NULL ) ;
return 0 ;
case V_270 :
return F_48 ( V_241 , & V_269 , sizeof( T_2 ) ) ? - V_74 : 0 ;
case V_271 :
if ( V_27 -> V_59 == V_135 ) {
F_65 ( V_19 , V_198 ) ;
F_93 ( V_19 ) ;
V_27 -> V_199 = 0x00 ;
V_27 -> V_200 = 0 ;
V_27 -> V_201 = 0 ;
V_27 -> V_202 = 0 ;
V_27 -> V_203 = 0 ;
V_27 -> V_59 = V_133 ;
}
return 0 ;
default:
return - V_272 ;
}
return 0 ;
}
static void * F_124 ( struct V_273 * V_274 , T_6 * V_275 )
__acquires( V_20 )
{
F_9 ( & V_20 ) ;
return F_125 ( & V_42 , * V_275 ) ;
}
static void * F_126 ( struct V_273 * V_274 , void * V_276 , T_6 * V_275 )
{
return F_127 ( V_276 , & V_42 , V_275 ) ;
}
static void F_128 ( struct V_273 * V_274 , void * V_276 )
__releases( V_20 )
{
F_11 ( & V_20 ) ;
}
static int F_129 ( struct V_273 * V_274 , void * V_276 )
{
char V_10 [ 11 ] , V_277 [ 11 ] ;
if ( V_276 == V_278 )
F_130 ( V_274 ,
L_3 ) ;
else {
struct V_18 * V_23 = F_131 ( V_276 ) ;
struct V_26 * V_27 = F_14 ( V_23 ) ;
const char * V_279 , * V_280 ;
const struct V_1 * V_2 = V_27 -> V_32 ;
if ( ! V_2 )
V_279 = L_4 ;
else
V_279 = V_2 -> V_281 ;
F_132 ( V_274 , L_5 ,
F_5 ( V_277 , & V_27 -> V_93 ) ,
F_133 ( V_10 , & V_27 -> V_95 ) ) ;
if ( F_25 ( & V_27 -> V_45 , & V_50 ) == 0 )
V_280 = L_6 ;
else
V_280 = F_133 ( V_10 , & V_27 -> V_45 ) ;
F_132 ( V_274 ,
L_7 ,
F_5 ( V_277 , & V_27 -> V_44 ) ,
V_280 ,
V_279 ,
V_27 -> V_51 & 0x0FFF ,
( V_27 -> V_28 ) ? V_27 -> V_28 -> V_282 : 0 ,
V_27 -> V_59 ,
V_27 -> V_200 ,
V_27 -> V_202 ,
V_27 -> V_201 ,
F_134 ( & V_27 -> V_117 ) / V_64 ,
V_27 -> V_78 / V_64 ,
V_27 -> V_80 / V_64 ,
V_27 -> V_82 / V_64 ,
V_27 -> V_84 / V_64 ,
F_134 ( & V_27 -> V_118 ) / ( 60 * V_64 ) ,
V_27 -> V_86 / ( 60 * V_64 ) ,
F_116 ( V_23 ) ,
F_135 ( V_23 ) ,
V_23 -> V_283 ? F_136 ( V_23 -> V_283 ) -> V_284 : 0L ) ;
}
return 0 ;
}
static int F_137 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
return F_138 ( V_286 , & V_287 ) ;
}
static int T_7 F_139 ( void )
{
int V_15 ;
int V_288 ;
if ( V_289 > 0x7FFFFFFF / sizeof( struct V_1 * ) ) {
F_140 ( V_290 L_8 ) ;
V_288 = - V_73 ;
goto V_291;
}
V_288 = F_141 ( & V_109 , 0 ) ;
if ( V_288 != 0 )
goto V_291;
V_269 = V_50 ;
V_292 = F_142 ( V_289 * sizeof( struct V_1 * ) , V_293 ) ;
if ( V_292 == NULL ) {
F_140 ( V_290 L_9 ) ;
V_288 = - V_110 ;
goto V_294;
}
for ( V_15 = 0 ; V_15 < V_289 ; V_15 ++ ) {
struct V_1 * V_2 ;
char V_281 [ V_295 ] ;
sprintf ( V_281 , L_10 , V_15 ) ;
V_2 = F_143 ( 0 , V_281 , V_296 ) ;
if ( ! V_2 ) {
F_140 ( V_290 L_11 ) ;
V_288 = - V_110 ;
goto V_297;
}
V_288 = F_144 ( V_2 ) ;
if ( V_288 ) {
F_140 ( V_290 L_12 ) ;
F_145 ( V_2 ) ;
goto V_297;
}
F_3 ( V_2 ) ;
V_292 [ V_15 ] = V_2 ;
}
F_146 ( & V_298 ) ;
F_147 ( & V_299 ) ;
F_148 ( & V_300 ) ;
F_149 ( & V_301 ) ;
#ifdef F_150
F_151 () ;
#endif
F_152 () ;
F_153 () ;
F_154 ( & V_37 , L_13 , V_302 , & V_303 ) ;
F_154 ( & V_37 , L_14 , V_302 , & V_304 ) ;
F_154 ( & V_37 , L_15 , V_302 , & V_305 ) ;
F_154 ( & V_37 , L_16 , V_302 , & V_306 ) ;
V_291:
return V_288 ;
V_297:
while ( -- V_15 >= 0 ) {
F_155 ( V_292 [ V_15 ] ) ;
F_145 ( V_292 [ V_15 ] ) ;
}
F_156 ( V_292 ) ;
V_294:
F_157 ( & V_109 ) ;
goto V_291;
}
static void T_8 F_158 ( void )
{
int V_15 ;
F_159 ( & V_37 , L_13 ) ;
F_159 ( & V_37 , L_14 ) ;
F_159 ( & V_37 , L_15 ) ;
F_159 ( & V_37 , L_16 ) ;
F_160 () ;
F_161 () ;
F_162 ( V_307 ) ;
F_163 ( & V_301 ) ;
if ( F_25 ( & V_269 , & V_50 ) != 0 )
F_122 ( & V_269 , NULL ) ;
#ifdef F_150
F_164 () ;
#endif
F_165 ( & V_299 ) ;
F_166 ( V_107 ) ;
for ( V_15 = 0 ; V_15 < V_289 ; V_15 ++ ) {
struct V_1 * V_2 = V_292 [ V_15 ] ;
if ( V_2 ) {
F_155 ( V_2 ) ;
F_145 ( V_2 ) ;
}
}
F_156 ( V_292 ) ;
F_157 ( & V_109 ) ;
}
