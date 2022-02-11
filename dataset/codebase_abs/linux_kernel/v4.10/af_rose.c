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
F_9 ( & V_20 ) ;
F_13 (s, &rose_list) {
struct V_24 * V_25 = F_14 ( V_23 ) ;
if ( V_25 -> V_26 == V_22 ) {
F_15 ( V_23 , V_27 , V_28 , 0 ) ;
V_25 -> V_26 -> V_29 -- ;
V_25 -> V_26 = NULL ;
}
}
F_11 ( & V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_23 ;
F_9 ( & V_20 ) ;
F_13 (s, &rose_list) {
struct V_24 * V_25 = F_14 ( V_23 ) ;
if ( V_25 -> V_30 == V_2 ) {
F_15 ( V_23 , V_27 , V_28 , 0 ) ;
if ( V_25 -> V_26 )
V_25 -> V_26 -> V_29 -- ;
V_25 -> V_30 = NULL ;
}
}
F_11 ( & V_20 ) ;
}
static int F_17 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_1 * V_2 = F_18 ( V_34 ) ;
if ( ! F_19 ( F_20 ( V_2 ) , & V_35 ) )
return V_36 ;
if ( V_33 != V_37 )
return V_36 ;
switch ( V_2 -> type ) {
case V_38 :
F_16 ( V_2 ) ;
break;
case V_39 :
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
}
return V_36 ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_9 ( & V_20 ) ;
F_24 ( V_19 , & V_40 ) ;
F_11 ( & V_20 ) ;
}
static struct V_18 * F_25 ( T_1 * V_11 , T_2 * V_41 )
{
struct V_18 * V_23 ;
F_9 ( & V_20 ) ;
F_13 (s, &rose_list) {
struct V_24 * V_25 = F_14 ( V_23 ) ;
if ( ! F_6 ( & V_25 -> V_42 , V_11 ) &&
! F_26 ( & V_25 -> V_43 , V_41 ) &&
! V_25 -> V_44 && V_23 -> V_45 == V_46 )
goto V_47;
}
F_13 (s, &rose_list) {
struct V_24 * V_25 = F_14 ( V_23 ) ;
if ( ! F_6 ( & V_25 -> V_42 , V_11 ) &&
! F_26 ( & V_25 -> V_43 , & V_48 ) &&
V_23 -> V_45 == V_46 )
goto V_47;
}
V_23 = NULL ;
V_47:
F_11 ( & V_20 ) ;
return V_23 ;
}
struct V_18 * F_27 ( unsigned int V_49 , struct V_21 * V_22 )
{
struct V_18 * V_23 ;
F_9 ( & V_20 ) ;
F_13 (s, &rose_list) {
struct V_24 * V_25 = F_14 ( V_23 ) ;
if ( V_25 -> V_49 == V_49 && V_25 -> V_26 == V_22 )
goto V_47;
}
V_23 = NULL ;
V_47:
F_11 ( & V_20 ) ;
return V_23 ;
}
unsigned int F_28 ( struct V_21 * V_22 )
{
int V_49 ;
if ( V_22 -> V_50 ) {
for ( V_49 = 1 ; V_49 <= V_51 ; V_49 ++ )
if ( F_27 ( V_49 , V_22 ) == NULL && F_29 ( V_49 , V_22 ) == NULL )
return V_49 ;
} else {
for ( V_49 = V_51 ; V_49 > 0 ; V_49 -- )
if ( F_27 ( V_49 , V_22 ) == NULL && F_29 ( V_49 , V_22 ) == NULL )
return V_49 ;
}
return 0 ;
}
static void F_30 ( unsigned long V_52 )
{
F_31 ( (struct V_18 * ) V_52 ) ;
}
void F_31 ( struct V_18 * V_19 )
{
struct V_53 * V_54 ;
F_8 ( V_19 ) ;
F_32 ( V_19 ) ;
F_33 ( V_19 ) ;
F_34 ( V_19 ) ;
F_35 ( V_19 ) ;
while ( ( V_54 = F_36 ( & V_19 -> V_55 ) ) != NULL ) {
if ( V_54 -> V_19 != V_19 ) {
F_37 ( V_54 -> V_19 , V_56 ) ;
F_38 ( V_54 -> V_19 ) ;
F_14 ( V_54 -> V_19 ) -> V_57 = V_58 ;
}
F_39 ( V_54 ) ;
}
if ( F_40 ( V_19 ) ) {
F_41 ( & V_19 -> V_59 , F_30 ,
( unsigned long ) V_19 ) ;
V_19 -> V_59 . V_60 = V_61 + 10 * V_62 ;
F_42 ( & V_19 -> V_59 ) ;
} else
F_43 ( V_19 ) ;
}
static int F_44 ( struct V_63 * V_18 , int V_64 , int V_65 ,
char T_3 * V_66 , unsigned int V_67 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
int V_68 ;
if ( V_64 != V_69 )
return - V_70 ;
if ( V_67 < sizeof( int ) )
return - V_71 ;
if ( F_45 ( V_68 , ( int T_3 * ) V_66 ) )
return - V_72 ;
switch ( V_65 ) {
case V_73 :
V_25 -> V_74 = V_68 ? 1 : 0 ;
return 0 ;
case V_75 :
if ( V_68 < 1 )
return - V_71 ;
V_25 -> V_76 = V_68 * V_62 ;
return 0 ;
case V_77 :
if ( V_68 < 1 )
return - V_71 ;
V_25 -> V_78 = V_68 * V_62 ;
return 0 ;
case V_79 :
if ( V_68 < 1 )
return - V_71 ;
V_25 -> V_80 = V_68 * V_62 ;
return 0 ;
case V_81 :
if ( V_68 < 1 )
return - V_71 ;
V_25 -> V_82 = V_68 * V_62 ;
return 0 ;
case V_83 :
if ( V_68 < 0 )
return - V_71 ;
V_25 -> V_84 = V_68 * 60 * V_62 ;
return 0 ;
case V_85 :
V_25 -> V_86 = V_68 ? 1 : 0 ;
return 0 ;
default:
return - V_70 ;
}
}
static int F_46 ( struct V_63 * V_18 , int V_64 , int V_65 ,
char T_3 * V_66 , int T_3 * V_67 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
int V_87 = 0 ;
int V_88 ;
if ( V_64 != V_69 )
return - V_70 ;
if ( F_45 ( V_88 , V_67 ) )
return - V_72 ;
if ( V_88 < 0 )
return - V_71 ;
switch ( V_65 ) {
case V_73 :
V_87 = V_25 -> V_74 ;
break;
case V_75 :
V_87 = V_25 -> V_76 / V_62 ;
break;
case V_77 :
V_87 = V_25 -> V_78 / V_62 ;
break;
case V_79 :
V_87 = V_25 -> V_80 / V_62 ;
break;
case V_81 :
V_87 = V_25 -> V_82 / V_62 ;
break;
case V_83 :
V_87 = V_25 -> V_84 / ( 60 * V_62 ) ;
break;
case V_85 :
V_87 = V_25 -> V_86 ;
break;
default:
return - V_70 ;
}
V_88 = F_47 (unsigned int, len, sizeof(int)) ;
if ( F_48 ( V_88 , V_67 ) )
return - V_72 ;
return F_49 ( V_66 , & V_87 , V_88 ) ? - V_72 : 0 ;
}
static int F_50 ( struct V_63 * V_18 , int V_89 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
if ( V_19 -> V_45 != V_46 ) {
struct V_24 * V_25 = F_14 ( V_19 ) ;
V_25 -> V_90 = 0 ;
memset ( & V_25 -> V_91 , 0 , V_92 ) ;
memset ( & V_25 -> V_93 , 0 , V_94 ) ;
memset ( V_25 -> V_95 , 0 , V_94 * V_96 ) ;
V_19 -> V_97 = V_89 ;
V_19 -> V_45 = V_46 ;
return 0 ;
}
return - V_98 ;
}
static int F_51 ( struct V_99 * V_99 , struct V_63 * V_18 , int V_100 ,
int V_101 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
if ( ! F_19 ( V_99 , & V_35 ) )
return - V_102 ;
if ( V_18 -> type != V_103 || V_100 != 0 )
return - V_104 ;
V_19 = F_52 ( V_99 , V_105 , V_106 , & V_107 , V_101 ) ;
if ( V_19 == NULL )
return - V_108 ;
V_25 = F_14 ( V_19 ) ;
F_53 ( V_18 , V_19 ) ;
F_54 ( & V_25 -> V_109 ) ;
#ifdef F_55
F_54 ( & V_25 -> V_110 ) ;
V_25 -> V_111 = 0 ;
#endif
V_18 -> V_112 = & V_113 ;
V_19 -> V_114 = V_100 ;
F_56 ( & V_25 -> V_115 ) ;
F_56 ( & V_25 -> V_116 ) ;
V_25 -> V_76 = F_57 ( V_117 ) ;
V_25 -> V_78 = F_57 ( V_118 ) ;
V_25 -> V_80 = F_57 ( V_119 ) ;
V_25 -> V_82 = F_57 ( V_120 ) ;
V_25 -> V_84 = F_57 ( V_121 ) ;
V_25 -> V_57 = V_58 ;
return 0 ;
}
static struct V_18 * F_58 ( struct V_18 * V_122 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 , * V_123 ;
if ( V_122 -> V_124 != V_103 )
return NULL ;
V_19 = F_52 ( F_59 ( V_122 ) , V_105 , V_106 , & V_107 , 0 ) ;
if ( V_19 == NULL )
return NULL ;
V_25 = F_14 ( V_19 ) ;
F_53 ( NULL , V_19 ) ;
F_54 ( & V_25 -> V_109 ) ;
#ifdef F_55
F_54 ( & V_25 -> V_110 ) ;
V_25 -> V_111 = 0 ;
#endif
V_19 -> V_124 = V_122 -> V_124 ;
V_19 -> V_125 = V_122 -> V_125 ;
V_19 -> V_114 = V_122 -> V_114 ;
V_19 -> V_126 = V_122 -> V_126 ;
V_19 -> V_127 = V_122 -> V_127 ;
V_19 -> V_45 = V_128 ;
F_60 ( V_19 , V_122 ) ;
F_56 ( & V_25 -> V_115 ) ;
F_56 ( & V_25 -> V_116 ) ;
V_123 = F_14 ( V_122 ) ;
V_25 -> V_76 = V_123 -> V_76 ;
V_25 -> V_78 = V_123 -> V_78 ;
V_25 -> V_80 = V_123 -> V_80 ;
V_25 -> V_82 = V_123 -> V_82 ;
V_25 -> V_84 = V_123 -> V_84 ;
V_25 -> V_74 = V_123 -> V_74 ;
V_25 -> V_30 = V_123 -> V_30 ;
V_25 -> V_86 = V_123 -> V_86 ;
return V_19 ;
}
static int F_61 ( struct V_63 * V_18 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 ;
if ( V_19 == NULL ) return 0 ;
F_62 ( V_19 ) ;
F_63 ( V_19 ) ;
F_64 ( V_19 ) ;
V_25 = F_14 ( V_19 ) ;
switch ( V_25 -> V_57 ) {
case V_58 :
F_65 ( V_19 ) ;
F_15 ( V_19 , 0 , - 1 , - 1 ) ;
F_64 ( V_19 ) ;
F_31 ( V_19 ) ;
break;
case V_129 :
V_25 -> V_26 -> V_29 -- ;
F_65 ( V_19 ) ;
F_15 ( V_19 , 0 , - 1 , - 1 ) ;
F_64 ( V_19 ) ;
F_31 ( V_19 ) ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
F_35 ( V_19 ) ;
F_33 ( V_19 ) ;
F_66 ( V_19 , V_134 ) ;
F_67 ( V_19 ) ;
V_25 -> V_57 = V_129 ;
V_19 -> V_45 = V_135 ;
V_19 -> V_136 |= V_137 ;
V_19 -> V_138 ( V_19 ) ;
F_37 ( V_19 , V_56 ) ;
F_37 ( V_19 , V_139 ) ;
break;
default:
break;
}
V_18 -> V_19 = NULL ;
F_65 ( V_19 ) ;
F_43 ( V_19 ) ;
return 0 ;
}
static int F_68 ( struct V_63 * V_18 , struct V_140 * V_141 , int V_142 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
struct V_143 * V_11 = (struct V_143 * ) V_141 ;
struct V_1 * V_2 ;
T_2 * V_144 ;
T_4 * V_145 ;
int V_146 ;
if ( ! F_69 ( V_19 , V_147 ) )
return - V_71 ;
if ( V_142 != sizeof( struct V_143 ) && V_142 != sizeof( struct V_148 ) )
return - V_71 ;
if ( V_11 -> V_149 != V_150 )
return - V_71 ;
if ( V_142 == sizeof( struct V_143 ) && V_11 -> V_151 > 1 )
return - V_71 ;
if ( ( unsigned int ) V_11 -> V_151 > V_96 )
return - V_71 ;
if ( ( V_2 = F_70 ( & V_11 -> V_152 ) ) == NULL )
return - V_153 ;
V_144 = & V_11 -> V_154 ;
V_145 = F_71 ( F_72 () ) ;
if ( V_145 ) {
V_25 -> V_43 = V_145 -> V_41 ;
F_73 ( V_145 ) ;
} else {
if ( V_155 && ! F_74 ( V_156 ) )
return - V_157 ;
V_25 -> V_43 = * V_144 ;
}
V_25 -> V_42 = V_11 -> V_152 ;
V_25 -> V_30 = V_2 ;
V_25 -> V_44 = V_11 -> V_151 ;
if ( V_142 == sizeof( struct V_148 ) ) {
struct V_148 * V_158 = (struct V_148 * ) V_141 ;
for ( V_146 = 0 ; V_146 < V_11 -> V_151 ; V_146 ++ )
V_25 -> V_159 [ V_146 ] = V_158 -> V_160 [ V_146 ] ;
} else {
if ( V_25 -> V_44 == 1 ) {
V_25 -> V_159 [ 0 ] = V_11 -> V_161 ;
}
}
F_23 ( V_19 ) ;
F_75 ( V_19 , V_147 ) ;
return 0 ;
}
static int F_76 ( struct V_63 * V_18 , struct V_140 * V_141 , int V_142 , int V_162 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
struct V_143 * V_11 = (struct V_143 * ) V_141 ;
unsigned char V_163 , V_164 ;
struct V_1 * V_2 ;
T_4 * V_145 ;
int V_146 , V_165 = 0 ;
if ( V_142 != sizeof( struct V_143 ) && V_142 != sizeof( struct V_148 ) )
return - V_71 ;
if ( V_11 -> V_149 != V_150 )
return - V_71 ;
if ( V_142 == sizeof( struct V_143 ) && V_11 -> V_151 > 1 )
return - V_71 ;
if ( ( unsigned int ) V_11 -> V_151 > V_96 )
return - V_71 ;
if ( ( V_25 -> V_44 + V_11 -> V_151 ) > V_96 )
return - V_71 ;
F_64 ( V_19 ) ;
if ( V_19 -> V_45 == V_128 && V_18 -> V_57 == V_166 ) {
V_18 -> V_57 = V_167 ;
goto V_168;
}
if ( V_19 -> V_45 == V_135 && V_18 -> V_57 == V_166 ) {
V_18 -> V_57 = V_169 ;
V_165 = - V_170 ;
goto V_168;
}
if ( V_19 -> V_45 == V_128 ) {
V_165 = - V_171 ;
goto V_168;
}
V_19 -> V_45 = V_135 ;
V_18 -> V_57 = V_169 ;
V_25 -> V_26 = F_77 ( & V_11 -> V_152 , & V_163 ,
& V_164 , 0 ) ;
if ( ! V_25 -> V_26 ) {
V_165 = - V_27 ;
goto V_168;
}
V_25 -> V_49 = F_28 ( V_25 -> V_26 ) ;
if ( ! V_25 -> V_49 ) {
V_165 = - V_27 ;
goto V_168;
}
if ( F_69 ( V_19 , V_147 ) ) {
F_75 ( V_19 , V_147 ) ;
if ( ( V_2 = F_78 () ) == NULL ) {
V_165 = - V_27 ;
goto V_168;
}
V_145 = F_71 ( F_72 () ) ;
if ( ! V_145 ) {
V_165 = - V_71 ;
goto V_168;
}
memcpy ( & V_25 -> V_42 , V_2 -> V_172 , V_92 ) ;
V_25 -> V_43 = V_145 -> V_41 ;
V_25 -> V_30 = V_2 ;
F_73 ( V_145 ) ;
F_23 ( V_19 ) ;
}
V_25 -> V_91 = V_11 -> V_152 ;
V_25 -> V_93 = V_11 -> V_154 ;
V_25 -> rand = ( ( long ) V_25 & 0xFFFF ) + V_25 -> V_49 ;
V_25 -> V_90 = V_11 -> V_151 ;
if ( V_142 == sizeof( struct V_148 ) ) {
struct V_148 * V_158 = (struct V_148 * ) V_141 ;
for ( V_146 = 0 ; V_146 < V_11 -> V_151 ; V_146 ++ )
V_25 -> V_95 [ V_146 ] = V_158 -> V_160 [ V_146 ] ;
} else {
if ( V_25 -> V_90 == 1 ) {
V_25 -> V_95 [ 0 ] = V_11 -> V_161 ;
}
}
V_18 -> V_57 = V_166 ;
V_19 -> V_45 = V_173 ;
V_25 -> V_57 = V_130 ;
V_25 -> V_26 -> V_29 ++ ;
F_66 ( V_19 , V_174 ) ;
F_38 ( V_19 ) ;
F_79 ( V_19 ) ;
if ( V_19 -> V_45 != V_128 && ( V_162 & V_175 ) ) {
V_165 = - V_176 ;
goto V_168;
}
if ( V_19 -> V_45 == V_173 ) {
F_80 ( V_177 ) ;
for (; ; ) {
F_81 ( F_82 ( V_19 ) , & V_177 ,
V_178 ) ;
if ( V_19 -> V_45 != V_173 )
break;
if ( ! F_83 ( V_179 ) ) {
F_65 ( V_19 ) ;
F_84 () ;
F_64 ( V_19 ) ;
continue;
}
V_165 = - V_180 ;
break;
}
F_85 ( F_82 ( V_19 ) , & V_177 ) ;
if ( V_165 )
goto V_168;
}
if ( V_19 -> V_45 != V_128 ) {
V_18 -> V_57 = V_169 ;
V_165 = F_86 ( V_19 ) ;
goto V_168;
}
V_18 -> V_57 = V_167 ;
V_168:
F_65 ( V_19 ) ;
return V_165 ;
}
static int F_87 ( struct V_63 * V_18 , struct V_63 * V_181 , int V_162 )
{
struct V_53 * V_54 ;
struct V_18 * V_182 ;
F_80 ( V_177 ) ;
struct V_18 * V_19 ;
int V_165 = 0 ;
if ( ( V_19 = V_18 -> V_19 ) == NULL )
return - V_71 ;
F_64 ( V_19 ) ;
if ( V_19 -> V_124 != V_103 ) {
V_165 = - V_98 ;
goto V_168;
}
if ( V_19 -> V_45 != V_46 ) {
V_165 = - V_71 ;
goto V_168;
}
for (; ; ) {
F_81 ( F_82 ( V_19 ) , & V_177 , V_178 ) ;
V_54 = F_36 ( & V_19 -> V_55 ) ;
if ( V_54 )
break;
if ( V_162 & V_175 ) {
V_165 = - V_183 ;
break;
}
if ( ! F_83 ( V_179 ) ) {
F_65 ( V_19 ) ;
F_84 () ;
F_64 ( V_19 ) ;
continue;
}
V_165 = - V_180 ;
break;
}
F_85 ( F_82 ( V_19 ) , & V_177 ) ;
if ( V_165 )
goto V_168;
V_182 = V_54 -> V_19 ;
F_88 ( V_182 , V_181 ) ;
V_54 -> V_19 = NULL ;
F_39 ( V_54 ) ;
V_19 -> V_184 -- ;
V_168:
F_65 ( V_19 ) ;
return V_165 ;
}
static int F_89 ( struct V_63 * V_18 , struct V_140 * V_141 ,
int * V_185 , int V_186 )
{
struct V_148 * V_187 = (struct V_148 * ) V_141 ;
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
int V_146 ;
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
if ( V_186 != 0 ) {
if ( V_19 -> V_45 != V_128 )
return - V_188 ;
V_187 -> V_149 = V_150 ;
V_187 -> V_152 = V_25 -> V_91 ;
V_187 -> V_154 = V_25 -> V_93 ;
V_187 -> V_151 = V_25 -> V_90 ;
for ( V_146 = 0 ; V_146 < V_25 -> V_90 ; V_146 ++ )
V_187 -> V_160 [ V_146 ] = V_25 -> V_95 [ V_146 ] ;
} else {
V_187 -> V_149 = V_150 ;
V_187 -> V_152 = V_25 -> V_42 ;
V_187 -> V_154 = V_25 -> V_43 ;
V_187 -> V_151 = V_25 -> V_44 ;
for ( V_146 = 0 ; V_146 < V_25 -> V_44 ; V_146 ++ )
V_187 -> V_160 [ V_146 ] = V_25 -> V_159 [ V_146 ] ;
}
* V_185 = sizeof( struct V_148 ) ;
return 0 ;
}
int F_90 ( struct V_53 * V_54 , struct V_1 * V_2 , struct V_21 * V_22 , unsigned int V_49 )
{
struct V_18 * V_19 ;
struct V_18 * V_189 ;
struct V_24 * V_190 ;
struct V_191 V_192 ;
int V_146 ;
V_54 -> V_19 = NULL ;
memset ( & V_192 , 0x00 , sizeof( struct V_191 ) ) ;
if ( ! F_91 ( V_54 -> V_52 + V_193 ,
V_54 -> V_88 - V_193 ,
& V_192 ) ) {
F_92 ( V_22 , V_49 , V_194 , 76 ) ;
return 0 ;
}
V_19 = F_25 ( & V_192 . V_42 , & V_192 . V_43 ) ;
if ( V_19 == NULL || F_93 ( V_19 ) ||
( V_189 = F_58 ( V_19 ) ) == NULL ) {
F_92 ( V_22 , V_49 , V_195 , 120 ) ;
return 0 ;
}
V_54 -> V_19 = V_189 ;
V_189 -> V_45 = V_128 ;
V_190 = F_14 ( V_189 ) ;
V_190 -> V_49 = V_49 ;
V_190 -> V_91 = V_192 . V_91 ;
V_190 -> V_93 = V_192 . V_93 ;
V_190 -> V_90 = V_192 . V_90 ;
for ( V_146 = 0 ; V_146 < V_192 . V_90 ; V_146 ++ )
V_190 -> V_95 [ V_146 ] = V_192 . V_95 [ V_146 ] ;
V_190 -> V_42 = V_192 . V_42 ;
V_190 -> V_43 = V_192 . V_43 ;
V_190 -> V_44 = V_192 . V_44 ;
for ( V_146 = 0 ; V_146 < V_192 . V_44 ; V_146 ++ )
V_190 -> V_159 [ V_146 ] = V_192 . V_159 [ V_146 ] ;
V_190 -> V_26 = V_22 ;
V_190 -> V_30 = V_2 ;
V_190 -> V_192 = V_192 ;
V_190 -> V_26 -> V_29 ++ ;
if ( F_14 ( V_19 ) -> V_74 ) {
V_190 -> V_57 = V_133 ;
} else {
F_66 ( V_189 , V_196 ) ;
V_190 -> V_57 = V_131 ;
F_94 ( V_189 ) ;
}
V_190 -> V_197 = 0x00 ;
V_190 -> V_198 = 0 ;
V_190 -> V_199 = 0 ;
V_190 -> V_200 = 0 ;
V_190 -> V_201 = 0 ;
V_19 -> V_184 ++ ;
F_23 ( V_189 ) ;
F_95 ( & V_19 -> V_55 , V_54 ) ;
F_38 ( V_189 ) ;
if ( ! F_69 ( V_19 , V_56 ) )
V_19 -> V_202 ( V_19 ) ;
return 1 ;
}
static int F_96 ( struct V_63 * V_18 , struct V_203 * V_204 , T_5 V_88 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
F_97 ( struct V_143 * , V_205 , V_204 -> V_206 ) ;
int V_165 ;
struct V_148 V_187 ;
struct V_53 * V_54 ;
unsigned char * V_207 ;
int V_146 , V_208 , V_209 = 0 ;
if ( V_204 -> V_210 & ~ ( V_211 | V_212 | V_213 ) )
return - V_71 ;
if ( F_69 ( V_19 , V_147 ) )
return - V_153 ;
if ( V_19 -> V_136 & V_137 ) {
F_98 ( V_214 , V_179 , 0 ) ;
return - V_215 ;
}
if ( V_25 -> V_26 == NULL || V_25 -> V_30 == NULL )
return - V_27 ;
if ( V_205 != NULL ) {
if ( V_204 -> V_216 != sizeof( struct V_143 ) && V_204 -> V_216 != sizeof( struct V_148 ) )
return - V_71 ;
memset ( & V_187 , 0 , sizeof( struct V_148 ) ) ;
memcpy ( & V_187 , V_205 , V_204 -> V_216 ) ;
if ( F_6 ( & V_25 -> V_91 , & V_187 . V_152 ) != 0 ||
F_26 ( & V_25 -> V_93 , & V_187 . V_154 ) != 0 )
return - V_171 ;
if ( V_187 . V_151 != V_25 -> V_90 )
return - V_171 ;
if ( V_187 . V_151 == V_25 -> V_90 ) {
for ( V_146 = 0 ; V_146 < V_187 . V_151 ; V_146 ++ )
if ( F_26 ( & V_25 -> V_95 [ V_146 ] ,
& V_187 . V_160 [ V_146 ] ) )
return - V_171 ;
}
if ( V_187 . V_149 != V_150 )
return - V_71 ;
} else {
if ( V_19 -> V_45 != V_128 )
return - V_188 ;
V_187 . V_149 = V_150 ;
V_187 . V_152 = V_25 -> V_91 ;
V_187 . V_154 = V_25 -> V_93 ;
V_187 . V_151 = V_25 -> V_90 ;
for ( V_146 = 0 ; V_146 < V_25 -> V_90 ; V_146 ++ )
V_187 . V_160 [ V_146 ] = V_25 -> V_95 [ V_146 ] ;
}
if ( V_88 > 65535 )
return - V_217 ;
V_208 = V_88 + V_218 + V_219 + V_220 ;
if ( ( V_54 = F_99 ( V_19 , V_208 , V_204 -> V_210 & V_211 , & V_165 ) ) == NULL )
return V_165 ;
F_100 ( V_54 , V_218 + V_219 + V_220 ) ;
F_101 ( V_54 ) ;
F_102 ( V_54 , V_88 ) ;
V_165 = F_103 ( F_104 ( V_54 ) , V_204 , V_88 ) ;
if ( V_165 ) {
F_39 ( V_54 ) ;
return V_165 ;
}
if ( V_25 -> V_86 ) {
V_209 = V_54 -> V_52 [ 0 ] ;
F_105 ( V_54 , 1 ) ;
}
V_207 = F_106 ( V_54 , V_220 ) ;
V_207 [ 0 ] = ( ( V_25 -> V_49 >> 8 ) & 0x0F ) | V_221 ;
V_207 [ 1 ] = ( V_25 -> V_49 >> 0 ) & 0xFF ;
V_207 [ 2 ] = V_222 ;
if ( V_209 )
V_207 [ 0 ] |= V_223 ;
if ( V_19 -> V_45 != V_128 ) {
F_39 ( V_54 ) ;
return - V_188 ;
}
#ifdef F_55
#define F_107 (256-ROSE_MIN_LEN)
if ( V_54 -> V_88 - V_220 > F_107 ) {
unsigned char V_224 [ V_220 ] ;
struct V_53 * V_225 ;
int V_226 ;
int V_227 ;
F_108 ( V_54 , V_224 , V_220 ) ;
F_105 ( V_54 , V_220 ) ;
V_226 = F_109 ( V_54 ) ;
while ( V_54 -> V_88 > 0 ) {
if ( ( V_225 = F_99 ( V_19 , V_226 + F_107 , 0 , & V_165 ) ) == NULL ) {
F_39 ( V_54 ) ;
return V_165 ;
}
V_225 -> V_19 = V_19 ;
V_225 -> free = 1 ;
V_225 -> V_228 = 1 ;
F_100 ( V_225 , V_226 ) ;
V_227 = ( F_107 > V_54 -> V_88 ) ? V_54 -> V_88 : F_107 ;
F_108 ( V_54 , F_102 ( V_225 , V_227 ) , V_227 ) ;
F_105 ( V_54 , V_227 ) ;
F_106 ( V_225 , V_220 ) ;
F_110 ( V_225 , V_224 , V_220 ) ;
if ( V_54 -> V_88 > 0 )
V_225 -> V_52 [ 2 ] |= F_55 ;
F_111 ( & V_19 -> V_229 , V_225 ) ;
}
V_54 -> free = 1 ;
F_39 ( V_54 ) ;
} else {
F_111 ( & V_19 -> V_229 , V_54 ) ;
}
#else
F_111 ( & V_19 -> V_229 , V_54 ) ;
#endif
F_112 ( V_19 ) ;
return V_88 ;
}
static int F_113 ( struct V_63 * V_18 , struct V_203 * V_204 , T_5 V_208 ,
int V_162 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
T_5 V_230 ;
unsigned char * V_207 ;
struct V_53 * V_54 ;
int V_146 , V_231 , V_209 ;
if ( V_19 -> V_45 != V_128 )
return - V_188 ;
if ( ( V_54 = F_114 ( V_19 , V_162 & ~ V_211 , V_162 & V_211 , & V_231 ) ) == NULL )
return V_231 ;
V_209 = ( V_54 -> V_52 [ 0 ] & V_223 ) == V_223 ;
F_105 ( V_54 , V_220 ) ;
if ( V_25 -> V_86 ) {
V_207 = F_106 ( V_54 , 1 ) ;
* V_207 = V_209 ;
}
F_101 ( V_54 ) ;
V_230 = V_54 -> V_88 ;
if ( V_230 > V_208 ) {
V_230 = V_208 ;
V_204 -> V_210 |= V_232 ;
}
F_115 ( V_54 , 0 , V_204 , V_230 ) ;
if ( V_204 -> V_206 ) {
struct V_143 * V_187 ;
F_97 ( struct V_148 * , V_233 ,
V_204 -> V_206 ) ;
memset ( V_204 -> V_206 , 0 , sizeof( struct V_148 ) ) ;
V_187 = V_204 -> V_206 ;
V_187 -> V_149 = V_150 ;
V_187 -> V_152 = V_25 -> V_91 ;
V_187 -> V_154 = V_25 -> V_93 ;
V_187 -> V_151 = V_25 -> V_90 ;
for ( V_146 = 0 ; V_146 < V_25 -> V_90 ; V_146 ++ )
V_233 -> V_160 [ V_146 ] = V_25 -> V_95 [ V_146 ] ;
V_204 -> V_216 = sizeof( struct V_148 ) ;
}
F_116 ( V_19 , V_54 ) ;
return V_230 ;
}
static int F_117 ( struct V_63 * V_18 , unsigned int V_234 , unsigned long V_235 )
{
struct V_18 * V_19 = V_18 -> V_19 ;
struct V_24 * V_25 = F_14 ( V_19 ) ;
void T_3 * V_236 = ( void T_3 * ) V_235 ;
switch ( V_234 ) {
case V_237 : {
long V_238 ;
V_238 = V_19 -> V_127 - F_118 ( V_19 ) ;
if ( V_238 < 0 )
V_238 = 0 ;
return F_48 ( V_238 , ( unsigned int T_3 * ) V_236 ) ;
}
case V_239 : {
struct V_53 * V_54 ;
long V_238 = 0L ;
if ( ( V_54 = F_119 ( & V_19 -> V_55 ) ) != NULL )
V_238 = V_54 -> V_88 ;
return F_48 ( V_238 , ( unsigned int T_3 * ) V_236 ) ;
}
case V_240 :
return F_120 ( V_19 , (struct V_241 T_3 * ) V_236 ) ;
case V_242 :
return F_121 ( V_19 , (struct V_243 T_3 * ) V_236 ) ;
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
return - V_71 ;
case V_254 :
case V_255 :
case V_256 :
if ( ! F_74 ( V_257 ) )
return - V_258 ;
return F_122 ( V_234 , V_236 ) ;
case V_259 : {
struct V_260 V_261 ;
V_261 . V_163 = V_25 -> V_163 ;
V_261 . V_164 = V_25 -> V_164 ;
return F_49 ( V_236 , & V_261 , sizeof( struct V_260 ) ) ? - V_72 : 0 ;
}
case V_262 : {
struct V_260 V_261 ;
if ( F_123 ( & V_261 , V_236 , sizeof( struct V_260 ) ) )
return - V_72 ;
V_25 -> V_163 = V_261 . V_163 ;
V_25 -> V_164 = V_261 . V_164 ;
return 0 ;
}
case V_263 :
if ( ! F_74 ( V_257 ) ) return - V_258 ;
if ( F_26 ( & V_264 , & V_48 ) != 0 )
F_124 ( & V_264 , NULL ) ;
if ( F_123 ( & V_264 , V_236 , sizeof( T_2 ) ) )
return - V_72 ;
if ( F_26 ( & V_264 , & V_48 ) != 0 )
return F_125 ( & V_264 , NULL ) ;
return 0 ;
case V_265 :
return F_49 ( V_236 , & V_264 , sizeof( T_2 ) ) ? - V_72 : 0 ;
case V_266 :
if ( V_25 -> V_57 == V_133 ) {
F_66 ( V_19 , V_196 ) ;
F_94 ( V_19 ) ;
V_25 -> V_197 = 0x00 ;
V_25 -> V_198 = 0 ;
V_25 -> V_199 = 0 ;
V_25 -> V_200 = 0 ;
V_25 -> V_201 = 0 ;
V_25 -> V_57 = V_131 ;
}
return 0 ;
default:
return - V_267 ;
}
return 0 ;
}
static void * F_126 ( struct V_268 * V_269 , T_6 * V_270 )
__acquires( V_20 )
{
F_9 ( & V_20 ) ;
return F_127 ( & V_40 , * V_270 ) ;
}
static void * F_128 ( struct V_268 * V_269 , void * V_271 , T_6 * V_270 )
{
return F_129 ( V_271 , & V_40 , V_270 ) ;
}
static void F_130 ( struct V_268 * V_269 , void * V_271 )
__releases( V_20 )
{
F_11 ( & V_20 ) ;
}
static int F_131 ( struct V_268 * V_269 , void * V_271 )
{
char V_10 [ 11 ] , V_272 [ 11 ] ;
if ( V_271 == V_273 )
F_132 ( V_269 ,
L_3 ) ;
else {
struct V_18 * V_23 = F_133 ( V_271 ) ;
struct V_24 * V_25 = F_14 ( V_23 ) ;
const char * V_274 , * V_275 ;
const struct V_1 * V_2 = V_25 -> V_30 ;
if ( ! V_2 )
V_274 = L_4 ;
else
V_274 = V_2 -> V_276 ;
F_134 ( V_269 , L_5 ,
F_5 ( V_272 , & V_25 -> V_91 ) ,
F_135 ( V_10 , & V_25 -> V_93 ) ) ;
if ( F_26 ( & V_25 -> V_43 , & V_48 ) == 0 )
V_275 = L_6 ;
else
V_275 = F_135 ( V_10 , & V_25 -> V_43 ) ;
F_134 ( V_269 ,
L_7 ,
F_5 ( V_272 , & V_25 -> V_42 ) ,
V_275 ,
V_274 ,
V_25 -> V_49 & 0x0FFF ,
( V_25 -> V_26 ) ? V_25 -> V_26 -> V_277 : 0 ,
V_25 -> V_57 ,
V_25 -> V_198 ,
V_25 -> V_200 ,
V_25 -> V_199 ,
F_136 ( & V_25 -> V_115 ) / V_62 ,
V_25 -> V_76 / V_62 ,
V_25 -> V_78 / V_62 ,
V_25 -> V_80 / V_62 ,
V_25 -> V_82 / V_62 ,
F_136 ( & V_25 -> V_116 ) / ( 60 * V_62 ) ,
V_25 -> V_84 / ( 60 * V_62 ) ,
F_118 ( V_23 ) ,
F_137 ( V_23 ) ,
V_23 -> V_278 ? F_138 ( V_23 -> V_278 ) -> V_279 : 0L ) ;
}
return 0 ;
}
static int F_139 ( struct V_280 * V_280 , struct V_281 * V_281 )
{
return F_140 ( V_281 , & V_282 ) ;
}
static int T_7 F_141 ( void )
{
int V_15 ;
int V_283 ;
if ( V_284 > 0x7FFFFFFF / sizeof( struct V_1 * ) ) {
F_142 ( V_285 L_8 ) ;
V_283 = - V_71 ;
goto V_286;
}
V_283 = F_143 ( & V_107 , 0 ) ;
if ( V_283 != 0 )
goto V_286;
V_264 = V_48 ;
V_287 = F_144 ( V_284 * sizeof( struct V_1 * ) , V_288 ) ;
if ( V_287 == NULL ) {
F_142 ( V_285 L_9 ) ;
V_283 = - V_108 ;
goto V_289;
}
for ( V_15 = 0 ; V_15 < V_284 ; V_15 ++ ) {
struct V_1 * V_2 ;
char V_276 [ V_290 ] ;
sprintf ( V_276 , L_10 , V_15 ) ;
V_2 = F_145 ( 0 , V_276 , V_291 , V_292 ) ;
if ( ! V_2 ) {
F_142 ( V_285 L_11 ) ;
V_283 = - V_108 ;
goto V_293;
}
V_283 = F_146 ( V_2 ) ;
if ( V_283 ) {
F_142 ( V_285 L_12 ) ;
F_147 ( V_2 ) ;
goto V_293;
}
F_3 ( V_2 ) ;
V_287 [ V_15 ] = V_2 ;
}
F_148 ( & V_294 ) ;
F_149 ( & V_295 ) ;
F_150 ( & V_296 ) ;
F_151 ( & V_297 ) ;
#ifdef F_152
F_153 () ;
#endif
F_154 () ;
F_155 () ;
F_156 ( L_13 , V_298 , V_35 . V_299 , & V_300 ) ;
F_156 ( L_14 , V_298 , V_35 . V_299 ,
& V_301 ) ;
F_156 ( L_15 , V_298 , V_35 . V_299 ,
& V_302 ) ;
F_156 ( L_16 , V_298 , V_35 . V_299 ,
& V_303 ) ;
V_286:
return V_283 ;
V_293:
while ( -- V_15 >= 0 ) {
F_157 ( V_287 [ V_15 ] ) ;
F_147 ( V_287 [ V_15 ] ) ;
}
F_158 ( V_287 ) ;
V_289:
F_159 ( & V_107 ) ;
goto V_286;
}
static void T_8 F_160 ( void )
{
int V_15 ;
F_161 ( L_13 , V_35 . V_299 ) ;
F_161 ( L_14 , V_35 . V_299 ) ;
F_161 ( L_15 , V_35 . V_299 ) ;
F_161 ( L_16 , V_35 . V_299 ) ;
F_162 () ;
F_163 () ;
F_164 ( V_304 ) ;
F_165 ( & V_297 ) ;
if ( F_26 ( & V_264 , & V_48 ) != 0 )
F_124 ( & V_264 , NULL ) ;
#ifdef F_152
F_166 () ;
#endif
F_167 ( & V_295 ) ;
F_168 ( V_105 ) ;
for ( V_15 = 0 ; V_15 < V_284 ; V_15 ++ ) {
struct V_1 * V_2 = V_287 [ V_15 ] ;
if ( V_2 ) {
F_157 ( V_2 ) ;
F_147 ( V_2 ) ;
}
}
F_158 ( V_287 ) ;
F_159 ( & V_107 ) ;
}
