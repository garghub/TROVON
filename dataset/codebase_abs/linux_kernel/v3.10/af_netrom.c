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
static void F_5 ( struct V_10 * V_11 )
{
F_6 ( & V_12 ) ;
F_7 ( V_11 ) ;
F_8 ( & V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_13 ;
F_6 ( & V_12 ) ;
F_10 (s, &nr_list)
if ( F_11 ( V_13 ) -> V_14 == V_2 )
F_12 ( V_13 , V_15 ) ;
F_8 ( & V_12 ) ;
}
static int F_13 ( struct V_16 * V_17 , unsigned long V_18 , void * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
if ( ! F_14 ( F_15 ( V_2 ) , & V_20 ) )
return V_21 ;
if ( V_18 != V_22 )
return V_21 ;
F_9 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_21 ;
}
static void F_17 ( struct V_10 * V_11 )
{
F_6 ( & V_12 ) ;
F_18 ( V_11 , & V_23 ) ;
F_8 ( & V_12 ) ;
}
static struct V_10 * F_19 ( T_1 * V_24 )
{
struct V_10 * V_13 ;
F_6 ( & V_12 ) ;
F_10 (s, &nr_list)
if ( ! F_20 ( & F_11 ( V_13 ) -> V_25 , V_24 ) &&
V_13 -> V_26 == V_27 ) {
F_21 ( V_13 ) ;
goto V_28;
}
V_13 = NULL ;
V_28:
F_8 ( & V_12 ) ;
return V_13 ;
}
static struct V_10 * F_22 ( unsigned char V_29 , unsigned char V_30 )
{
struct V_10 * V_13 ;
F_6 ( & V_12 ) ;
F_10 (s, &nr_list) {
struct V_31 * V_32 = F_11 ( V_13 ) ;
if ( V_32 -> V_33 == V_29 && V_32 -> V_34 == V_30 ) {
F_21 ( V_13 ) ;
goto V_28;
}
}
V_13 = NULL ;
V_28:
F_8 ( & V_12 ) ;
return V_13 ;
}
static struct V_10 * F_23 ( unsigned char V_29 , unsigned char V_30 ,
T_1 * V_35 )
{
struct V_10 * V_13 ;
F_6 ( & V_12 ) ;
F_10 (s, &nr_list) {
struct V_31 * V_32 = F_11 ( V_13 ) ;
if ( V_32 -> V_36 == V_29 && V_32 -> V_37 == V_30 &&
! F_20 ( & V_32 -> V_38 , V_35 ) ) {
F_21 ( V_13 ) ;
goto V_28;
}
}
V_13 = NULL ;
V_28:
F_8 ( & V_12 ) ;
return V_13 ;
}
static unsigned short F_24 ( void )
{
unsigned short V_30 = V_39 ;
unsigned char V_40 , V_41 ;
struct V_10 * V_11 ;
for (; ; ) {
V_40 = V_30 / 256 ;
V_41 = V_30 % 256 ;
if ( V_40 != 0 && V_41 != 0 ) {
if ( ( V_11 = F_22 ( V_40 , V_41 ) ) == NULL )
break;
F_25 ( V_11 ) ;
}
V_30 ++ ;
}
return V_30 ;
}
static void F_26 ( unsigned long V_42 )
{
struct V_10 * V_11 = (struct V_10 * ) V_42 ;
F_21 ( V_11 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_25 ( V_11 ) ;
F_29 ( V_11 ) ;
}
void F_28 ( struct V_10 * V_11 )
{
struct V_43 * V_44 ;
F_5 ( V_11 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
while ( ( V_44 = F_36 ( & V_11 -> V_45 ) ) != NULL ) {
if ( V_44 -> V_11 != V_11 ) {
F_37 ( V_44 -> V_11 , V_46 ) ;
F_38 ( V_44 -> V_11 ) ;
F_11 ( V_44 -> V_11 ) -> V_47 = V_48 ;
}
F_39 ( V_44 ) ;
}
if ( F_40 ( V_11 ) ) {
V_11 -> V_49 . V_50 = F_26 ;
V_11 -> V_49 . V_51 = V_52 + 2 * V_53 ;
F_41 ( & V_11 -> V_49 ) ;
} else
F_29 ( V_11 ) ;
}
static int F_42 ( struct V_54 * V_10 , int V_55 , int V_56 ,
char T_2 * V_57 , unsigned int V_58 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
unsigned long V_59 ;
if ( V_55 != V_60 )
return - V_61 ;
if ( V_58 < sizeof( unsigned int ) )
return - V_62 ;
if ( F_43 ( V_59 , ( unsigned int T_2 * ) V_57 ) )
return - V_63 ;
switch ( V_56 ) {
case V_64 :
if ( V_59 < 1 || V_59 > V_65 / V_53 )
return - V_62 ;
V_32 -> V_66 = V_59 * V_53 ;
return 0 ;
case V_67 :
if ( V_59 < 1 || V_59 > V_65 / V_53 )
return - V_62 ;
V_32 -> V_68 = V_59 * V_53 ;
return 0 ;
case V_69 :
if ( V_59 < 1 || V_59 > 31 )
return - V_62 ;
V_32 -> V_70 = V_59 ;
return 0 ;
case V_71 :
if ( V_59 < 1 || V_59 > V_65 / V_53 )
return - V_62 ;
V_32 -> V_72 = V_59 * V_53 ;
return 0 ;
case V_73 :
if ( V_59 > V_65 / ( 60 * V_53 ) )
return - V_62 ;
V_32 -> V_74 = V_59 * 60 * V_53 ;
return 0 ;
default:
return - V_61 ;
}
}
static int F_44 ( struct V_54 * V_10 , int V_55 , int V_56 ,
char T_2 * V_57 , int T_2 * V_58 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
int V_75 = 0 ;
int V_76 ;
if ( V_55 != V_60 )
return - V_61 ;
if ( F_43 ( V_76 , V_58 ) )
return - V_63 ;
if ( V_76 < 0 )
return - V_62 ;
switch ( V_56 ) {
case V_64 :
V_75 = V_32 -> V_66 / V_53 ;
break;
case V_67 :
V_75 = V_32 -> V_68 / V_53 ;
break;
case V_69 :
V_75 = V_32 -> V_70 ;
break;
case V_71 :
V_75 = V_32 -> V_72 / V_53 ;
break;
case V_73 :
V_75 = V_32 -> V_74 / ( 60 * V_53 ) ;
break;
default:
return - V_61 ;
}
V_76 = F_45 (unsigned int, len, sizeof(int)) ;
if ( F_46 ( V_76 , V_58 ) )
return - V_63 ;
return F_47 ( V_57 , & V_75 , V_76 ) ? - V_63 : 0 ;
}
static int F_48 ( struct V_54 * V_10 , int V_77 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_26 != V_27 ) {
memset ( & F_11 ( V_11 ) -> V_78 , 0 , V_79 ) ;
V_11 -> V_80 = V_77 ;
V_11 -> V_26 = V_27 ;
F_50 ( V_11 ) ;
return 0 ;
}
F_50 ( V_11 ) ;
return - V_81 ;
}
static int F_51 ( struct V_82 * V_82 , struct V_54 * V_10 , int V_83 ,
int V_84 )
{
struct V_10 * V_11 ;
struct V_31 * V_32 ;
if ( ! F_14 ( V_82 , & V_20 ) )
return - V_85 ;
if ( V_10 -> type != V_86 || V_83 != 0 )
return - V_87 ;
V_11 = F_52 ( V_82 , V_88 , V_89 , & V_90 ) ;
if ( V_11 == NULL )
return - V_91 ;
V_32 = F_11 ( V_11 ) ;
F_53 ( V_10 , V_11 ) ;
V_10 -> V_92 = & V_93 ;
V_11 -> V_94 = V_83 ;
F_54 ( & V_32 -> V_95 ) ;
F_54 ( & V_32 -> V_96 ) ;
F_54 ( & V_32 -> V_97 ) ;
F_55 ( V_11 ) ;
V_32 -> V_66 =
F_56 ( V_98 ) ;
V_32 -> V_68 =
F_56 ( V_99 ) ;
V_32 -> V_70 =
F_56 ( V_100 ) ;
V_32 -> V_72 =
F_56 ( V_101 ) ;
V_32 -> V_74 =
F_56 ( V_102 ) ;
V_32 -> V_103 = V_104 ;
V_32 -> V_105 = 1 ;
V_32 -> V_47 = V_48 ;
return 0 ;
}
static struct V_10 * F_57 ( struct V_10 * V_106 )
{
struct V_10 * V_11 ;
struct V_31 * V_32 , * V_107 ;
if ( V_106 -> V_108 != V_86 )
return NULL ;
V_11 = F_52 ( F_58 ( V_106 ) , V_88 , V_89 , V_106 -> V_109 ) ;
if ( V_11 == NULL )
return NULL ;
V_32 = F_11 ( V_11 ) ;
F_53 ( NULL , V_11 ) ;
V_11 -> V_108 = V_106 -> V_108 ;
V_11 -> V_110 = V_106 -> V_110 ;
V_11 -> V_94 = V_106 -> V_94 ;
V_11 -> V_111 = V_106 -> V_111 ;
V_11 -> V_112 = V_106 -> V_112 ;
V_11 -> V_26 = V_113 ;
F_59 ( V_11 , V_106 ) ;
F_54 ( & V_32 -> V_95 ) ;
F_54 ( & V_32 -> V_96 ) ;
F_54 ( & V_32 -> V_97 ) ;
F_55 ( V_11 ) ;
V_107 = F_11 ( V_106 ) ;
V_32 -> V_66 = V_107 -> V_66 ;
V_32 -> V_68 = V_107 -> V_68 ;
V_32 -> V_70 = V_107 -> V_70 ;
V_32 -> V_72 = V_107 -> V_72 ;
V_32 -> V_74 = V_107 -> V_74 ;
V_32 -> V_103 = V_107 -> V_103 ;
V_32 -> V_14 = V_107 -> V_14 ;
V_32 -> V_105 = V_107 -> V_105 ;
return V_11 ;
}
static int F_60 ( struct V_54 * V_10 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 ;
if ( V_11 == NULL ) return 0 ;
F_27 ( V_11 ) ;
F_61 ( V_11 ) ;
F_49 ( V_11 ) ;
V_32 = F_11 ( V_11 ) ;
switch ( V_32 -> V_47 ) {
case V_48 :
case V_114 :
case V_115 :
F_12 ( V_11 , 0 ) ;
F_28 ( V_11 ) ;
break;
case V_116 :
F_35 ( V_11 ) ;
V_32 -> V_117 = 0 ;
F_62 ( V_11 , V_118 ) ;
F_63 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
V_32 -> V_47 = V_115 ;
V_11 -> V_26 = V_119 ;
V_11 -> V_120 |= V_121 ;
V_11 -> V_122 ( V_11 ) ;
F_37 ( V_11 , V_123 ) ;
break;
default:
break;
}
V_10 -> V_11 = NULL ;
F_50 ( V_11 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_54 * V_10 , struct V_124 * V_125 , int V_126 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
struct V_127 * V_24 = (struct V_127 * ) V_125 ;
struct V_1 * V_2 ;
T_3 * V_128 ;
T_1 * V_129 ;
F_49 ( V_11 ) ;
if ( ! F_65 ( V_11 , V_130 ) ) {
F_50 ( V_11 ) ;
return - V_62 ;
}
if ( V_126 < sizeof( struct V_131 ) || V_126 > sizeof( struct V_127 ) ) {
F_50 ( V_11 ) ;
return - V_62 ;
}
if ( V_126 < ( V_24 -> V_132 . V_133 * sizeof( T_1 ) + sizeof( struct V_131 ) ) ) {
F_50 ( V_11 ) ;
return - V_62 ;
}
if ( V_24 -> V_132 . V_134 != V_135 ) {
F_50 ( V_11 ) ;
return - V_62 ;
}
if ( ( V_2 = F_66 ( & V_24 -> V_132 . V_136 ) ) == NULL ) {
F_50 ( V_11 ) ;
return - V_137 ;
}
if ( V_24 -> V_132 . V_133 == 1 ) {
if ( ! F_67 ( V_138 ) ) {
F_68 ( V_2 ) ;
F_50 ( V_11 ) ;
return - V_139 ;
}
V_32 -> V_78 = V_24 -> V_140 [ 0 ] ;
V_32 -> V_25 = V_24 -> V_132 . V_136 ;
} else {
V_129 = & V_24 -> V_132 . V_136 ;
V_128 = F_69 ( F_70 () ) ;
if ( V_128 ) {
V_32 -> V_78 = V_128 -> V_141 ;
F_71 ( V_128 ) ;
} else {
if ( V_142 && ! F_67 ( V_138 ) ) {
F_50 ( V_11 ) ;
F_68 ( V_2 ) ;
return - V_139 ;
}
V_32 -> V_78 = * V_129 ;
}
V_32 -> V_25 = * V_129 ;
}
V_32 -> V_14 = V_2 ;
F_17 ( V_11 ) ;
F_72 ( V_11 , V_130 ) ;
F_68 ( V_2 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
static int F_73 ( struct V_54 * V_10 , struct V_124 * V_125 ,
int V_126 , int V_143 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
struct V_131 * V_24 = (struct V_131 * ) V_125 ;
T_1 * V_129 = NULL ;
T_3 * V_128 ;
struct V_1 * V_2 ;
int V_144 = 0 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_26 == V_113 && V_10 -> V_47 == V_145 ) {
V_10 -> V_47 = V_146 ;
goto V_147;
}
if ( V_11 -> V_26 == V_119 && V_10 -> V_47 == V_145 ) {
V_10 -> V_47 = V_148 ;
V_144 = - V_149 ;
goto V_147;
}
if ( V_11 -> V_26 == V_113 ) {
V_144 = - V_150 ;
goto V_147;
}
V_11 -> V_26 = V_119 ;
V_10 -> V_47 = V_148 ;
if ( V_126 != sizeof( struct V_131 ) && V_126 != sizeof( struct V_127 ) ) {
V_144 = - V_62 ;
goto V_147;
}
if ( V_24 -> V_134 != V_135 ) {
V_144 = - V_62 ;
goto V_147;
}
if ( F_65 ( V_11 , V_130 ) ) {
F_72 ( V_11 , V_130 ) ;
if ( ( V_2 = F_74 () ) == NULL ) {
V_144 = - V_15 ;
goto V_147;
}
V_129 = ( T_1 * ) V_2 -> V_151 ;
V_128 = F_69 ( F_70 () ) ;
if ( V_128 ) {
V_32 -> V_78 = V_128 -> V_141 ;
F_71 ( V_128 ) ;
} else {
if ( V_142 && ! F_67 ( V_152 ) ) {
F_68 ( V_2 ) ;
V_144 = - V_139 ;
goto V_147;
}
V_32 -> V_78 = * V_129 ;
}
V_32 -> V_25 = * V_129 ;
V_32 -> V_14 = V_2 ;
F_68 ( V_2 ) ;
F_17 ( V_11 ) ;
}
V_32 -> V_38 = V_24 -> V_136 ;
F_50 ( V_11 ) ;
V_39 = F_24 () ;
F_49 ( V_11 ) ;
V_32 -> V_33 = V_39 / 256 ;
V_32 -> V_34 = V_39 % 256 ;
V_39 ++ ;
V_10 -> V_47 = V_145 ;
V_11 -> V_26 = V_153 ;
F_75 ( V_11 ) ;
V_32 -> V_47 = V_114 ;
F_38 ( V_11 ) ;
if ( V_11 -> V_26 != V_113 && ( V_143 & V_154 ) ) {
V_144 = - V_155 ;
goto V_147;
}
if ( V_11 -> V_26 == V_153 ) {
F_76 ( V_156 ) ;
for (; ; ) {
F_77 ( F_78 ( V_11 ) , & V_156 ,
V_157 ) ;
if ( V_11 -> V_26 != V_153 )
break;
if ( ! F_79 ( V_158 ) ) {
F_50 ( V_11 ) ;
F_80 () ;
F_49 ( V_11 ) ;
continue;
}
V_144 = - V_159 ;
break;
}
F_81 ( F_78 ( V_11 ) , & V_156 ) ;
if ( V_144 )
goto V_147;
}
if ( V_11 -> V_26 != V_113 ) {
V_10 -> V_47 = V_148 ;
V_144 = F_82 ( V_11 ) ;
goto V_147;
}
V_10 -> V_47 = V_146 ;
V_147:
F_50 ( V_11 ) ;
return V_144 ;
}
static int F_83 ( struct V_54 * V_10 , struct V_54 * V_160 , int V_143 )
{
struct V_43 * V_44 ;
struct V_10 * V_161 ;
F_76 ( V_156 ) ;
struct V_10 * V_11 ;
int V_144 = 0 ;
if ( ( V_11 = V_10 -> V_11 ) == NULL )
return - V_62 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_108 != V_86 ) {
V_144 = - V_81 ;
goto V_147;
}
if ( V_11 -> V_26 != V_27 ) {
V_144 = - V_62 ;
goto V_147;
}
for (; ; ) {
F_77 ( F_78 ( V_11 ) , & V_156 , V_157 ) ;
V_44 = F_36 ( & V_11 -> V_45 ) ;
if ( V_44 )
break;
if ( V_143 & V_154 ) {
V_144 = - V_162 ;
break;
}
if ( ! F_79 ( V_158 ) ) {
F_50 ( V_11 ) ;
F_80 () ;
F_49 ( V_11 ) ;
continue;
}
V_144 = - V_159 ;
break;
}
F_81 ( F_78 ( V_11 ) , & V_156 ) ;
if ( V_144 )
goto V_147;
V_161 = V_44 -> V_11 ;
F_84 ( V_161 , V_160 ) ;
F_39 ( V_44 ) ;
F_85 ( V_11 ) ;
V_147:
F_50 ( V_11 ) ;
return V_144 ;
}
static int F_86 ( struct V_54 * V_10 , struct V_124 * V_125 ,
int * V_163 , int V_164 )
{
struct V_127 * V_165 = (struct V_127 * ) V_125 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
memset ( & V_165 -> V_132 , 0 , sizeof( struct V_131 ) ) ;
F_49 ( V_11 ) ;
if ( V_164 != 0 ) {
if ( V_11 -> V_26 != V_113 ) {
F_50 ( V_11 ) ;
return - V_166 ;
}
V_165 -> V_132 . V_134 = V_135 ;
V_165 -> V_132 . V_133 = 1 ;
V_165 -> V_132 . V_136 = V_32 -> V_78 ;
memset ( V_165 -> V_140 , 0 , sizeof( V_165 -> V_140 ) ) ;
V_165 -> V_140 [ 0 ] = V_32 -> V_38 ;
* V_163 = sizeof( struct V_127 ) ;
} else {
V_165 -> V_132 . V_134 = V_135 ;
V_165 -> V_132 . V_133 = 0 ;
V_165 -> V_132 . V_136 = V_32 -> V_25 ;
* V_163 = sizeof( struct V_131 ) ;
}
F_50 ( V_11 ) ;
return 0 ;
}
int F_87 ( struct V_43 * V_44 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_10 * V_167 ;
struct V_31 * V_168 ;
T_1 * V_169 , * V_35 , * V_128 ;
unsigned short V_170 , V_171 ;
unsigned short V_172 , V_173 ;
unsigned short V_174 , V_143 , V_103 , V_175 ;
int V_176 ;
V_44 -> V_11 = NULL ;
V_169 = ( T_1 * ) ( V_44 -> V_42 + 0 ) ;
V_35 = ( T_1 * ) ( V_44 -> V_42 + 7 ) ;
V_170 = V_44 -> V_42 [ 15 ] ;
V_171 = V_44 -> V_42 [ 16 ] ;
V_172 = V_44 -> V_42 [ 17 ] ;
V_173 = V_44 -> V_42 [ 18 ] ;
V_174 = V_44 -> V_42 [ 19 ] & 0x0F ;
V_143 = V_44 -> V_42 [ 19 ] & 0xF0 ;
if ( V_174 == V_177 &&
V_170 == V_178 && V_171 == V_178 ) {
F_88 ( V_44 , V_179 + V_180 ) ;
F_89 ( V_44 ) ;
return F_90 ( V_44 , V_2 ) ;
}
V_11 = NULL ;
if ( V_170 == 0 && V_171 == 0 ) {
if ( V_174 == V_181 && V_143 == V_182 )
V_11 = F_23 ( V_172 , V_173 , V_169 ) ;
} else {
if ( V_174 == V_183 )
V_11 = F_23 ( V_170 , V_171 , V_169 ) ;
else
V_11 = F_22 ( V_170 , V_171 ) ;
}
if ( V_11 != NULL ) {
F_89 ( V_44 ) ;
if ( V_174 == V_181 && V_44 -> V_76 == 22 )
F_11 ( V_11 ) -> V_105 = 1 ;
else
F_11 ( V_11 ) -> V_105 = 0 ;
V_176 = F_91 ( V_11 , V_44 ) ;
F_25 ( V_11 ) ;
return V_176 ;
}
if ( V_174 != V_183 ) {
if ( V_184 &&
( V_174 != V_185 || V_143 != 0 ) )
F_92 ( V_44 , 1 ) ;
return 0 ;
}
V_11 = F_19 ( V_35 ) ;
V_128 = ( T_1 * ) ( V_44 -> V_42 + 21 ) ;
if ( V_11 == NULL || F_93 ( V_11 ) ||
( V_167 = F_57 ( V_11 ) ) == NULL ) {
F_94 ( V_44 , 0 ) ;
if ( V_11 )
F_25 ( V_11 ) ;
return 0 ;
}
V_103 = V_44 -> V_42 [ 20 ] ;
V_44 -> V_11 = V_167 ;
V_167 -> V_26 = V_113 ;
V_168 = F_11 ( V_167 ) ;
V_168 -> V_25 = * V_35 ;
V_168 -> V_38 = * V_169 ;
V_168 -> V_78 = * V_128 ;
V_168 -> V_36 = V_170 ;
V_168 -> V_37 = V_171 ;
F_25 ( V_11 ) ;
V_39 = F_24 () ;
F_21 ( V_11 ) ;
V_168 -> V_33 = V_39 / 256 ;
V_168 -> V_34 = V_39 % 256 ;
V_39 ++ ;
if ( V_103 < V_168 -> V_103 )
V_168 -> V_103 = V_103 ;
if ( V_44 -> V_76 == 37 ) {
V_175 = V_44 -> V_42 [ 36 ] * 256 + V_44 -> V_42 [ 35 ] ;
if ( V_175 * V_53 < V_168 -> V_66 )
V_168 -> V_66 = V_175 * V_53 ;
V_168 -> V_105 = 1 ;
} else {
V_168 -> V_105 = 0 ;
}
F_62 ( V_167 , V_181 ) ;
V_168 -> V_186 = 0x00 ;
V_168 -> V_187 = 0 ;
V_168 -> V_188 = 0 ;
V_168 -> V_189 = 0 ;
V_168 -> V_190 = 0 ;
V_168 -> V_47 = V_116 ;
F_95 ( V_11 ) ;
F_96 ( & V_11 -> V_45 , V_44 ) ;
if ( ! F_65 ( V_11 , V_46 ) )
V_11 -> V_191 ( V_11 , V_44 -> V_76 ) ;
F_25 ( V_11 ) ;
F_17 ( V_167 ) ;
F_38 ( V_167 ) ;
F_97 ( V_167 ) ;
return 1 ;
}
static int F_98 ( struct V_192 * V_193 , struct V_54 * V_10 ,
struct V_194 * V_195 , T_4 V_76 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_31 * V_32 = F_11 ( V_11 ) ;
struct V_131 * V_196 = (struct V_131 * ) V_195 -> V_197 ;
int V_144 ;
struct V_131 V_165 ;
struct V_43 * V_44 ;
unsigned char * V_198 ;
int V_199 ;
if ( V_195 -> V_200 & ~ ( V_201 | V_202 | V_203 ) )
return - V_62 ;
F_49 ( V_11 ) ;
if ( F_65 ( V_11 , V_130 ) ) {
V_144 = - V_137 ;
goto V_204;
}
if ( V_11 -> V_120 & V_121 ) {
F_99 ( V_205 , V_158 , 0 ) ;
V_144 = - V_206 ;
goto V_204;
}
if ( V_32 -> V_14 == NULL ) {
V_144 = - V_15 ;
goto V_204;
}
if ( V_196 ) {
if ( V_195 -> V_207 < sizeof( V_165 ) ) {
V_144 = - V_62 ;
goto V_204;
}
V_165 = * V_196 ;
if ( F_20 ( & V_32 -> V_38 , & V_165 . V_136 ) != 0 ) {
V_144 = - V_150 ;
goto V_204;
}
if ( V_165 . V_134 != V_135 ) {
V_144 = - V_62 ;
goto V_204;
}
} else {
if ( V_11 -> V_26 != V_113 ) {
V_144 = - V_166 ;
goto V_204;
}
V_165 . V_134 = V_135 ;
V_165 . V_136 = V_32 -> V_38 ;
}
if ( V_76 > 65536 ) {
V_144 = - V_208 ;
goto V_204;
}
V_199 = V_76 + V_179 + V_180 ;
if ( ( V_44 = F_100 ( V_11 , V_199 , V_195 -> V_200 & V_201 , & V_144 ) ) == NULL )
goto V_204;
F_101 ( V_44 , V_199 - V_76 ) ;
F_89 ( V_44 ) ;
V_198 = F_102 ( V_44 , V_180 ) ;
* V_198 ++ = V_32 -> V_36 ;
* V_198 ++ = V_32 -> V_37 ;
* V_198 ++ = 0 ;
* V_198 ++ = 0 ;
* V_198 ++ = V_209 ;
F_103 ( V_44 , V_76 ) ;
if ( F_104 ( F_105 ( V_44 ) , V_195 -> V_210 , V_76 ) ) {
F_39 ( V_44 ) ;
V_144 = - V_63 ;
goto V_204;
}
if ( V_11 -> V_26 != V_113 ) {
F_39 ( V_44 ) ;
V_144 = - V_166 ;
goto V_204;
}
F_106 ( V_11 , V_44 ) ;
V_144 = V_76 ;
V_204:
F_50 ( V_11 ) ;
return V_144 ;
}
static int F_107 ( struct V_192 * V_193 , struct V_54 * V_10 ,
struct V_194 * V_195 , T_4 V_199 , int V_143 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_131 * V_165 = (struct V_131 * ) V_195 -> V_197 ;
T_4 V_211 ;
struct V_43 * V_44 ;
int V_212 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_26 != V_113 ) {
F_50 ( V_11 ) ;
return - V_166 ;
}
if ( ( V_44 = F_108 ( V_11 , V_143 & ~ V_201 , V_143 & V_201 , & V_212 ) ) == NULL ) {
F_50 ( V_11 ) ;
return V_212 ;
}
F_89 ( V_44 ) ;
V_211 = V_44 -> V_76 ;
if ( V_211 > V_199 ) {
V_211 = V_199 ;
V_195 -> V_200 |= V_213 ;
}
V_212 = F_109 ( V_44 , 0 , V_195 -> V_210 , V_211 ) ;
if ( V_212 < 0 ) {
F_110 ( V_11 , V_44 ) ;
F_50 ( V_11 ) ;
return V_212 ;
}
if ( V_165 != NULL ) {
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
V_165 -> V_134 = V_135 ;
F_111 ( V_44 , 7 , V_165 -> V_136 . V_214 ,
V_79 ) ;
}
V_195 -> V_207 = sizeof( * V_165 ) ;
F_110 ( V_11 , V_44 ) ;
F_50 ( V_11 ) ;
return V_211 ;
}
static int F_112 ( struct V_54 * V_10 , unsigned int V_215 , unsigned long V_216 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
void T_2 * V_217 = ( void T_2 * ) V_216 ;
int V_176 ;
switch ( V_215 ) {
case V_218 : {
long V_219 ;
F_49 ( V_11 ) ;
V_219 = V_11 -> V_112 - F_113 ( V_11 ) ;
if ( V_219 < 0 )
V_219 = 0 ;
F_50 ( V_11 ) ;
return F_46 ( V_219 , ( int T_2 * ) V_217 ) ;
}
case V_220 : {
struct V_43 * V_44 ;
long V_219 = 0L ;
F_49 ( V_11 ) ;
if ( ( V_44 = F_114 ( & V_11 -> V_45 ) ) != NULL )
V_219 = V_44 -> V_76 ;
F_50 ( V_11 ) ;
return F_46 ( V_219 , ( int T_2 * ) V_217 ) ;
}
case V_221 :
F_49 ( V_11 ) ;
V_176 = F_115 ( V_11 , V_217 ) ;
F_50 ( V_11 ) ;
return V_176 ;
case V_222 :
F_49 ( V_11 ) ;
V_176 = F_116 ( V_11 , V_217 ) ;
F_50 ( V_11 ) ;
return V_176 ;
case V_223 :
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
return - V_62 ;
case V_233 :
case V_234 :
case V_235 :
if ( ! F_67 ( V_152 ) )
return - V_139 ;
return F_117 ( V_215 , V_217 ) ;
default:
return - V_236 ;
}
return 0 ;
}
static void * F_118 ( struct V_237 * V_238 , T_5 * V_239 )
{
F_6 ( & V_12 ) ;
return F_119 ( & V_23 , * V_239 ) ;
}
static void * F_120 ( struct V_237 * V_238 , void * V_240 , T_5 * V_239 )
{
return F_121 ( V_240 , & V_23 , V_239 ) ;
}
static void F_122 ( struct V_237 * V_238 , void * V_240 )
{
F_8 ( & V_12 ) ;
}
static int F_123 ( struct V_237 * V_238 , void * V_240 )
{
struct V_10 * V_13 = F_124 ( V_240 ) ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
const char * V_241 ;
char V_242 [ 11 ] ;
if ( V_240 == V_243 )
F_125 ( V_238 ,
L_1 ) ;
else {
F_21 ( V_13 ) ;
V_32 = F_11 ( V_13 ) ;
if ( ( V_2 = V_32 -> V_14 ) == NULL )
V_241 = L_2 ;
else
V_241 = V_2 -> V_244 ;
F_126 ( V_238 , L_3 , F_127 ( V_242 , & V_32 -> V_78 ) ) ;
F_126 ( V_238 , L_3 , F_127 ( V_242 , & V_32 -> V_38 ) ) ;
F_126 ( V_238 ,
L_4 ,
F_127 ( V_242 , & V_32 -> V_25 ) ,
V_241 ,
V_32 -> V_33 ,
V_32 -> V_34 ,
V_32 -> V_36 ,
V_32 -> V_37 ,
V_32 -> V_47 ,
V_32 -> V_187 ,
V_32 -> V_189 ,
V_32 -> V_188 ,
F_128 ( & V_32 -> V_245 ) / V_53 ,
V_32 -> V_66 / V_53 ,
F_128 ( & V_32 -> V_246 ) / V_53 ,
V_32 -> V_68 / V_53 ,
F_128 ( & V_32 -> V_247 ) / V_53 ,
V_32 -> V_72 / V_53 ,
F_128 ( & V_32 -> V_248 ) / ( 60 * V_53 ) ,
V_32 -> V_74 / ( 60 * V_53 ) ,
V_32 -> V_117 ,
V_32 -> V_70 ,
V_32 -> V_103 ,
F_113 ( V_13 ) ,
F_129 ( V_13 ) ,
V_13 -> V_249 ? F_130 ( V_13 -> V_249 ) -> V_250 : 0L ) ;
F_25 ( V_13 ) ;
}
return 0 ;
}
static int F_131 ( struct V_251 * V_251 , struct V_252 * V_252 )
{
return F_132 ( V_252 , & V_253 ) ;
}
static int T_6 F_133 ( void )
{
int V_40 ;
int V_254 = F_134 ( & V_90 , 0 ) ;
if ( V_254 != 0 )
goto V_204;
if ( V_255 > 0x7fffffff / sizeof( struct V_1 * ) ) {
F_135 ( V_256 L_5 ) ;
return - 1 ;
}
V_257 = F_136 ( V_255 * sizeof( struct V_1 * ) , V_258 ) ;
if ( V_257 == NULL ) {
F_135 ( V_256 L_6 ) ;
return - 1 ;
}
for ( V_40 = 0 ; V_40 < V_255 ; V_40 ++ ) {
char V_244 [ V_259 ] ;
struct V_1 * V_2 ;
sprintf ( V_244 , L_7 , V_40 ) ;
V_2 = F_137 ( 0 , V_244 , V_260 ) ;
if ( ! V_2 ) {
F_135 ( V_256 L_8 ) ;
goto V_261;
}
V_2 -> V_262 = V_40 ;
if ( F_138 ( V_2 ) ) {
F_135 ( V_256 L_9 ) ;
F_139 ( V_2 ) ;
goto V_261;
}
F_3 ( V_2 ) ;
V_257 [ V_40 ] = V_2 ;
}
if ( F_140 ( & V_263 ) ) {
F_135 ( V_256 L_10 ) ;
goto V_261;
}
F_141 ( & V_264 ) ;
F_142 ( & V_265 ) ;
F_143 ( & V_266 ) ;
#ifdef F_144
F_145 () ;
#endif
F_146 () ;
F_147 ( L_11 , V_267 , V_20 . V_268 , & V_269 ) ;
F_147 ( L_12 , V_267 , V_20 . V_268 , & V_270 ) ;
F_147 ( L_13 , V_267 , V_20 . V_268 , & V_271 ) ;
V_204:
return V_254 ;
V_261:
while ( -- V_40 >= 0 ) {
F_148 ( V_257 [ V_40 ] ) ;
F_139 ( V_257 [ V_40 ] ) ;
}
F_149 ( V_257 ) ;
F_150 ( & V_90 ) ;
V_254 = - 1 ;
goto V_204;
}
static void T_7 F_151 ( void )
{
int V_40 ;
F_152 ( L_11 , V_20 . V_268 ) ;
F_152 ( L_12 , V_20 . V_268 ) ;
F_152 ( L_13 , V_20 . V_268 ) ;
F_153 () ;
F_154 () ;
#ifdef F_144
F_155 () ;
#endif
F_156 ( & V_266 ) ;
F_157 ( V_272 ) ;
F_158 ( & V_264 ) ;
F_159 ( V_88 ) ;
for ( V_40 = 0 ; V_40 < V_255 ; V_40 ++ ) {
struct V_1 * V_2 = V_257 [ V_40 ] ;
if ( V_2 ) {
F_148 ( V_2 ) ;
F_139 ( V_2 ) ;
}
}
F_149 ( V_257 ) ;
F_150 ( & V_90 ) ;
}
