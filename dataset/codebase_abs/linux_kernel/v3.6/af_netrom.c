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
struct V_14 * V_15 ;
F_6 ( & V_12 ) ;
F_10 (s, node, &nr_list)
if ( F_11 ( V_13 ) -> V_16 == V_2 )
F_12 ( V_13 , V_17 ) ;
F_8 ( & V_12 ) ;
}
static int F_13 ( struct V_18 * V_19 , unsigned long V_20 , void * V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 ;
if ( ! F_14 ( F_15 ( V_2 ) , & V_22 ) )
return V_23 ;
if ( V_20 != V_24 )
return V_23 ;
F_9 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_23 ;
}
static void F_17 ( struct V_10 * V_11 )
{
F_6 ( & V_12 ) ;
F_18 ( V_11 , & V_25 ) ;
F_8 ( & V_12 ) ;
}
static struct V_10 * F_19 ( T_1 * V_26 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
F_6 ( & V_12 ) ;
F_10 (s, node, &nr_list)
if ( ! F_20 ( & F_11 ( V_13 ) -> V_27 , V_26 ) &&
V_13 -> V_28 == V_29 ) {
F_21 ( V_13 ) ;
goto V_30;
}
V_13 = NULL ;
V_30:
F_8 ( & V_12 ) ;
return V_13 ;
}
static struct V_10 * F_22 ( unsigned char V_31 , unsigned char V_32 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
F_6 ( & V_12 ) ;
F_10 (s, node, &nr_list) {
struct V_33 * V_34 = F_11 ( V_13 ) ;
if ( V_34 -> V_35 == V_31 && V_34 -> V_36 == V_32 ) {
F_21 ( V_13 ) ;
goto V_30;
}
}
V_13 = NULL ;
V_30:
F_8 ( & V_12 ) ;
return V_13 ;
}
static struct V_10 * F_23 ( unsigned char V_31 , unsigned char V_32 ,
T_1 * V_37 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
F_6 ( & V_12 ) ;
F_10 (s, node, &nr_list) {
struct V_33 * V_34 = F_11 ( V_13 ) ;
if ( V_34 -> V_38 == V_31 && V_34 -> V_39 == V_32 &&
! F_20 ( & V_34 -> V_40 , V_37 ) ) {
F_21 ( V_13 ) ;
goto V_30;
}
}
V_13 = NULL ;
V_30:
F_8 ( & V_12 ) ;
return V_13 ;
}
static unsigned short F_24 ( void )
{
unsigned short V_32 = V_41 ;
unsigned char V_42 , V_43 ;
struct V_10 * V_11 ;
for (; ; ) {
V_42 = V_32 / 256 ;
V_43 = V_32 % 256 ;
if ( V_42 != 0 && V_43 != 0 ) {
if ( ( V_11 = F_22 ( V_42 , V_43 ) ) == NULL )
break;
F_25 ( V_11 ) ;
}
V_32 ++ ;
}
return V_32 ;
}
static void F_26 ( unsigned long V_44 )
{
struct V_10 * V_11 = (struct V_10 * ) V_44 ;
F_21 ( V_11 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_25 ( V_11 ) ;
F_29 ( V_11 ) ;
}
void F_28 ( struct V_10 * V_11 )
{
struct V_45 * V_46 ;
F_5 ( V_11 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
while ( ( V_46 = F_36 ( & V_11 -> V_47 ) ) != NULL ) {
if ( V_46 -> V_11 != V_11 ) {
F_37 ( V_46 -> V_11 , V_48 ) ;
F_38 ( V_46 -> V_11 ) ;
F_11 ( V_46 -> V_11 ) -> V_49 = V_50 ;
}
F_39 ( V_46 ) ;
}
if ( F_40 ( V_11 ) ) {
V_11 -> V_51 . V_52 = F_26 ;
V_11 -> V_51 . V_53 = V_54 + 2 * V_55 ;
F_41 ( & V_11 -> V_51 ) ;
} else
F_29 ( V_11 ) ;
}
static int F_42 ( struct V_56 * V_10 , int V_57 , int V_58 ,
char T_2 * V_59 , unsigned int V_60 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
unsigned long V_61 ;
if ( V_57 != V_62 )
return - V_63 ;
if ( V_60 < sizeof( unsigned int ) )
return - V_64 ;
if ( F_43 ( V_61 , ( unsigned int T_2 * ) V_59 ) )
return - V_65 ;
switch ( V_58 ) {
case V_66 :
if ( V_61 < 1 || V_61 > V_67 / V_55 )
return - V_64 ;
V_34 -> V_68 = V_61 * V_55 ;
return 0 ;
case V_69 :
if ( V_61 < 1 || V_61 > V_67 / V_55 )
return - V_64 ;
V_34 -> V_70 = V_61 * V_55 ;
return 0 ;
case V_71 :
if ( V_61 < 1 || V_61 > 31 )
return - V_64 ;
V_34 -> V_72 = V_61 ;
return 0 ;
case V_73 :
if ( V_61 < 1 || V_61 > V_67 / V_55 )
return - V_64 ;
V_34 -> V_74 = V_61 * V_55 ;
return 0 ;
case V_75 :
if ( V_61 > V_67 / ( 60 * V_55 ) )
return - V_64 ;
V_34 -> V_76 = V_61 * 60 * V_55 ;
return 0 ;
default:
return - V_63 ;
}
}
static int F_44 ( struct V_56 * V_10 , int V_57 , int V_58 ,
char T_2 * V_59 , int T_2 * V_60 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
int V_77 = 0 ;
int V_78 ;
if ( V_57 != V_62 )
return - V_63 ;
if ( F_43 ( V_78 , V_60 ) )
return - V_65 ;
if ( V_78 < 0 )
return - V_64 ;
switch ( V_58 ) {
case V_66 :
V_77 = V_34 -> V_68 / V_55 ;
break;
case V_69 :
V_77 = V_34 -> V_70 / V_55 ;
break;
case V_71 :
V_77 = V_34 -> V_72 ;
break;
case V_73 :
V_77 = V_34 -> V_74 / V_55 ;
break;
case V_75 :
V_77 = V_34 -> V_76 / ( 60 * V_55 ) ;
break;
default:
return - V_63 ;
}
V_78 = F_45 (unsigned int, len, sizeof(int)) ;
if ( F_46 ( V_78 , V_60 ) )
return - V_65 ;
return F_47 ( V_59 , & V_77 , V_78 ) ? - V_65 : 0 ;
}
static int F_48 ( struct V_56 * V_10 , int V_79 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_28 != V_29 ) {
memset ( & F_11 ( V_11 ) -> V_80 , 0 , V_81 ) ;
V_11 -> V_82 = V_79 ;
V_11 -> V_28 = V_29 ;
F_50 ( V_11 ) ;
return 0 ;
}
F_50 ( V_11 ) ;
return - V_83 ;
}
static int F_51 ( struct V_84 * V_84 , struct V_56 * V_10 , int V_85 ,
int V_86 )
{
struct V_10 * V_11 ;
struct V_33 * V_34 ;
if ( ! F_14 ( V_84 , & V_22 ) )
return - V_87 ;
if ( V_10 -> type != V_88 || V_85 != 0 )
return - V_89 ;
V_11 = F_52 ( V_84 , V_90 , V_91 , & V_92 ) ;
if ( V_11 == NULL )
return - V_93 ;
V_34 = F_11 ( V_11 ) ;
F_53 ( V_10 , V_11 ) ;
V_10 -> V_94 = & V_95 ;
V_11 -> V_96 = V_85 ;
F_54 ( & V_34 -> V_97 ) ;
F_54 ( & V_34 -> V_98 ) ;
F_54 ( & V_34 -> V_99 ) ;
F_55 ( V_11 ) ;
V_34 -> V_68 =
F_56 ( V_100 ) ;
V_34 -> V_70 =
F_56 ( V_101 ) ;
V_34 -> V_72 =
F_56 ( V_102 ) ;
V_34 -> V_74 =
F_56 ( V_103 ) ;
V_34 -> V_76 =
F_56 ( V_104 ) ;
V_34 -> V_105 = V_106 ;
V_34 -> V_107 = 1 ;
V_34 -> V_49 = V_50 ;
return 0 ;
}
static struct V_10 * F_57 ( struct V_10 * V_108 )
{
struct V_10 * V_11 ;
struct V_33 * V_34 , * V_109 ;
if ( V_108 -> V_110 != V_88 )
return NULL ;
V_11 = F_52 ( F_58 ( V_108 ) , V_90 , V_91 , V_108 -> V_111 ) ;
if ( V_11 == NULL )
return NULL ;
V_34 = F_11 ( V_11 ) ;
F_53 ( NULL , V_11 ) ;
V_11 -> V_110 = V_108 -> V_110 ;
V_11 -> V_112 = V_108 -> V_112 ;
V_11 -> V_96 = V_108 -> V_96 ;
V_11 -> V_113 = V_108 -> V_113 ;
V_11 -> V_114 = V_108 -> V_114 ;
V_11 -> V_28 = V_115 ;
F_59 ( V_11 , V_108 ) ;
F_54 ( & V_34 -> V_97 ) ;
F_54 ( & V_34 -> V_98 ) ;
F_54 ( & V_34 -> V_99 ) ;
F_55 ( V_11 ) ;
V_109 = F_11 ( V_108 ) ;
V_34 -> V_68 = V_109 -> V_68 ;
V_34 -> V_70 = V_109 -> V_70 ;
V_34 -> V_72 = V_109 -> V_72 ;
V_34 -> V_74 = V_109 -> V_74 ;
V_34 -> V_76 = V_109 -> V_76 ;
V_34 -> V_105 = V_109 -> V_105 ;
V_34 -> V_16 = V_109 -> V_16 ;
V_34 -> V_107 = V_109 -> V_107 ;
return V_11 ;
}
static int F_60 ( struct V_56 * V_10 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 ;
if ( V_11 == NULL ) return 0 ;
F_27 ( V_11 ) ;
F_61 ( V_11 ) ;
F_49 ( V_11 ) ;
V_34 = F_11 ( V_11 ) ;
switch ( V_34 -> V_49 ) {
case V_50 :
case V_116 :
case V_117 :
F_12 ( V_11 , 0 ) ;
F_28 ( V_11 ) ;
break;
case V_118 :
F_35 ( V_11 ) ;
V_34 -> V_119 = 0 ;
F_62 ( V_11 , V_120 ) ;
F_63 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
V_34 -> V_49 = V_117 ;
V_11 -> V_28 = V_121 ;
V_11 -> V_122 |= V_123 ;
V_11 -> V_124 ( V_11 ) ;
F_37 ( V_11 , V_125 ) ;
break;
default:
break;
}
V_10 -> V_11 = NULL ;
F_50 ( V_11 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_56 * V_10 , struct V_126 * V_127 , int V_128 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
struct V_129 * V_26 = (struct V_129 * ) V_127 ;
struct V_1 * V_2 ;
T_3 * V_130 ;
T_1 * V_131 ;
F_49 ( V_11 ) ;
if ( ! F_65 ( V_11 , V_132 ) ) {
F_50 ( V_11 ) ;
return - V_64 ;
}
if ( V_128 < sizeof( struct V_133 ) || V_128 > sizeof( struct V_129 ) ) {
F_50 ( V_11 ) ;
return - V_64 ;
}
if ( V_128 < ( V_26 -> V_134 . V_135 * sizeof( T_1 ) + sizeof( struct V_133 ) ) ) {
F_50 ( V_11 ) ;
return - V_64 ;
}
if ( V_26 -> V_134 . V_136 != V_137 ) {
F_50 ( V_11 ) ;
return - V_64 ;
}
if ( ( V_2 = F_66 ( & V_26 -> V_134 . V_138 ) ) == NULL ) {
F_50 ( V_11 ) ;
return - V_139 ;
}
if ( V_26 -> V_134 . V_135 == 1 ) {
if ( ! F_67 ( V_140 ) ) {
F_68 ( V_2 ) ;
F_50 ( V_11 ) ;
return - V_141 ;
}
V_34 -> V_80 = V_26 -> V_142 [ 0 ] ;
V_34 -> V_27 = V_26 -> V_134 . V_138 ;
} else {
V_131 = & V_26 -> V_134 . V_138 ;
V_130 = F_69 ( F_70 () ) ;
if ( V_130 ) {
V_34 -> V_80 = V_130 -> V_143 ;
F_71 ( V_130 ) ;
} else {
if ( V_144 && ! F_67 ( V_140 ) ) {
F_50 ( V_11 ) ;
F_68 ( V_2 ) ;
return - V_141 ;
}
V_34 -> V_80 = * V_131 ;
}
V_34 -> V_27 = * V_131 ;
}
V_34 -> V_16 = V_2 ;
F_17 ( V_11 ) ;
F_72 ( V_11 , V_132 ) ;
F_68 ( V_2 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
static int F_73 ( struct V_56 * V_10 , struct V_126 * V_127 ,
int V_128 , int V_145 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
struct V_133 * V_26 = (struct V_133 * ) V_127 ;
T_1 * V_131 = NULL ;
T_3 * V_130 ;
struct V_1 * V_2 ;
int V_146 = 0 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_28 == V_115 && V_10 -> V_49 == V_147 ) {
V_10 -> V_49 = V_148 ;
goto V_149;
}
if ( V_11 -> V_28 == V_121 && V_10 -> V_49 == V_147 ) {
V_10 -> V_49 = V_150 ;
V_146 = - V_151 ;
goto V_149;
}
if ( V_11 -> V_28 == V_115 ) {
V_146 = - V_152 ;
goto V_149;
}
V_11 -> V_28 = V_121 ;
V_10 -> V_49 = V_150 ;
if ( V_128 != sizeof( struct V_133 ) && V_128 != sizeof( struct V_129 ) ) {
V_146 = - V_64 ;
goto V_149;
}
if ( V_26 -> V_136 != V_137 ) {
V_146 = - V_64 ;
goto V_149;
}
if ( F_65 ( V_11 , V_132 ) ) {
F_72 ( V_11 , V_132 ) ;
if ( ( V_2 = F_74 () ) == NULL ) {
V_146 = - V_17 ;
goto V_149;
}
V_131 = ( T_1 * ) V_2 -> V_153 ;
V_130 = F_69 ( F_70 () ) ;
if ( V_130 ) {
V_34 -> V_80 = V_130 -> V_143 ;
F_71 ( V_130 ) ;
} else {
if ( V_144 && ! F_67 ( V_154 ) ) {
F_68 ( V_2 ) ;
V_146 = - V_141 ;
goto V_149;
}
V_34 -> V_80 = * V_131 ;
}
V_34 -> V_27 = * V_131 ;
V_34 -> V_16 = V_2 ;
F_68 ( V_2 ) ;
F_17 ( V_11 ) ;
}
V_34 -> V_40 = V_26 -> V_138 ;
F_50 ( V_11 ) ;
V_41 = F_24 () ;
F_49 ( V_11 ) ;
V_34 -> V_35 = V_41 / 256 ;
V_34 -> V_36 = V_41 % 256 ;
V_41 ++ ;
V_10 -> V_49 = V_147 ;
V_11 -> V_28 = V_155 ;
F_75 ( V_11 ) ;
V_34 -> V_49 = V_116 ;
F_38 ( V_11 ) ;
if ( V_11 -> V_28 != V_115 && ( V_145 & V_156 ) ) {
V_146 = - V_157 ;
goto V_149;
}
if ( V_11 -> V_28 == V_155 ) {
F_76 ( V_158 ) ;
for (; ; ) {
F_77 ( F_78 ( V_11 ) , & V_158 ,
V_159 ) ;
if ( V_11 -> V_28 != V_155 )
break;
if ( ! F_79 ( V_160 ) ) {
F_50 ( V_11 ) ;
F_80 () ;
F_49 ( V_11 ) ;
continue;
}
V_146 = - V_161 ;
break;
}
F_81 ( F_78 ( V_11 ) , & V_158 ) ;
if ( V_146 )
goto V_149;
}
if ( V_11 -> V_28 != V_115 ) {
V_10 -> V_49 = V_150 ;
V_146 = F_82 ( V_11 ) ;
goto V_149;
}
V_10 -> V_49 = V_148 ;
V_149:
F_50 ( V_11 ) ;
return V_146 ;
}
static int F_83 ( struct V_56 * V_10 , struct V_56 * V_162 , int V_145 )
{
struct V_45 * V_46 ;
struct V_10 * V_163 ;
F_76 ( V_158 ) ;
struct V_10 * V_11 ;
int V_146 = 0 ;
if ( ( V_11 = V_10 -> V_11 ) == NULL )
return - V_64 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_110 != V_88 ) {
V_146 = - V_83 ;
goto V_149;
}
if ( V_11 -> V_28 != V_29 ) {
V_146 = - V_64 ;
goto V_149;
}
for (; ; ) {
F_77 ( F_78 ( V_11 ) , & V_158 , V_159 ) ;
V_46 = F_36 ( & V_11 -> V_47 ) ;
if ( V_46 )
break;
if ( V_145 & V_156 ) {
V_146 = - V_164 ;
break;
}
if ( ! F_79 ( V_160 ) ) {
F_50 ( V_11 ) ;
F_80 () ;
F_49 ( V_11 ) ;
continue;
}
V_146 = - V_161 ;
break;
}
F_81 ( F_78 ( V_11 ) , & V_158 ) ;
if ( V_146 )
goto V_149;
V_163 = V_46 -> V_11 ;
F_84 ( V_163 , V_162 ) ;
F_39 ( V_46 ) ;
F_85 ( V_11 ) ;
V_149:
F_50 ( V_11 ) ;
return V_146 ;
}
static int F_86 ( struct V_56 * V_10 , struct V_126 * V_127 ,
int * V_165 , int V_166 )
{
struct V_129 * V_167 = (struct V_129 * ) V_127 ;
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
F_49 ( V_11 ) ;
if ( V_166 != 0 ) {
if ( V_11 -> V_28 != V_115 ) {
F_50 ( V_11 ) ;
return - V_168 ;
}
V_167 -> V_134 . V_136 = V_137 ;
V_167 -> V_134 . V_135 = 1 ;
V_167 -> V_134 . V_138 = V_34 -> V_80 ;
memset ( V_167 -> V_142 , 0 , sizeof( V_167 -> V_142 ) ) ;
V_167 -> V_142 [ 0 ] = V_34 -> V_40 ;
* V_165 = sizeof( struct V_129 ) ;
} else {
V_167 -> V_134 . V_136 = V_137 ;
V_167 -> V_134 . V_135 = 0 ;
V_167 -> V_134 . V_138 = V_34 -> V_27 ;
* V_165 = sizeof( struct V_133 ) ;
}
F_50 ( V_11 ) ;
return 0 ;
}
int F_87 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_10 * V_169 ;
struct V_33 * V_170 ;
T_1 * V_171 , * V_37 , * V_130 ;
unsigned short V_172 , V_173 ;
unsigned short V_174 , V_175 ;
unsigned short V_176 , V_145 , V_105 , V_177 ;
int V_178 ;
V_46 -> V_11 = NULL ;
V_171 = ( T_1 * ) ( V_46 -> V_44 + 0 ) ;
V_37 = ( T_1 * ) ( V_46 -> V_44 + 7 ) ;
V_172 = V_46 -> V_44 [ 15 ] ;
V_173 = V_46 -> V_44 [ 16 ] ;
V_174 = V_46 -> V_44 [ 17 ] ;
V_175 = V_46 -> V_44 [ 18 ] ;
V_176 = V_46 -> V_44 [ 19 ] & 0x0F ;
V_145 = V_46 -> V_44 [ 19 ] & 0xF0 ;
if ( V_176 == V_179 &&
V_172 == V_180 && V_173 == V_180 ) {
F_88 ( V_46 , V_181 + V_182 ) ;
F_89 ( V_46 ) ;
return F_90 ( V_46 , V_2 ) ;
}
V_11 = NULL ;
if ( V_172 == 0 && V_173 == 0 ) {
if ( V_176 == V_183 && V_145 == V_184 )
V_11 = F_23 ( V_174 , V_175 , V_171 ) ;
} else {
if ( V_176 == V_185 )
V_11 = F_23 ( V_172 , V_173 , V_171 ) ;
else
V_11 = F_22 ( V_172 , V_173 ) ;
}
if ( V_11 != NULL ) {
F_89 ( V_46 ) ;
if ( V_176 == V_183 && V_46 -> V_78 == 22 )
F_11 ( V_11 ) -> V_107 = 1 ;
else
F_11 ( V_11 ) -> V_107 = 0 ;
V_178 = F_91 ( V_11 , V_46 ) ;
F_25 ( V_11 ) ;
return V_178 ;
}
if ( V_176 != V_185 ) {
if ( V_186 &&
( V_176 != V_187 || V_145 != 0 ) )
F_92 ( V_46 , 1 ) ;
return 0 ;
}
V_11 = F_19 ( V_37 ) ;
V_130 = ( T_1 * ) ( V_46 -> V_44 + 21 ) ;
if ( V_11 == NULL || F_93 ( V_11 ) ||
( V_169 = F_57 ( V_11 ) ) == NULL ) {
F_94 ( V_46 , 0 ) ;
if ( V_11 )
F_25 ( V_11 ) ;
return 0 ;
}
V_105 = V_46 -> V_44 [ 20 ] ;
V_46 -> V_11 = V_169 ;
V_169 -> V_28 = V_115 ;
V_170 = F_11 ( V_169 ) ;
V_170 -> V_27 = * V_37 ;
V_170 -> V_40 = * V_171 ;
V_170 -> V_80 = * V_130 ;
V_170 -> V_38 = V_172 ;
V_170 -> V_39 = V_173 ;
F_25 ( V_11 ) ;
V_41 = F_24 () ;
F_21 ( V_11 ) ;
V_170 -> V_35 = V_41 / 256 ;
V_170 -> V_36 = V_41 % 256 ;
V_41 ++ ;
if ( V_105 < V_170 -> V_105 )
V_170 -> V_105 = V_105 ;
if ( V_46 -> V_78 == 37 ) {
V_177 = V_46 -> V_44 [ 36 ] * 256 + V_46 -> V_44 [ 35 ] ;
if ( V_177 * V_55 < V_170 -> V_68 )
V_170 -> V_68 = V_177 * V_55 ;
V_170 -> V_107 = 1 ;
} else {
V_170 -> V_107 = 0 ;
}
F_62 ( V_169 , V_183 ) ;
V_170 -> V_188 = 0x00 ;
V_170 -> V_189 = 0 ;
V_170 -> V_190 = 0 ;
V_170 -> V_191 = 0 ;
V_170 -> V_192 = 0 ;
V_170 -> V_49 = V_118 ;
F_95 ( V_11 ) ;
F_96 ( & V_11 -> V_47 , V_46 ) ;
if ( ! F_65 ( V_11 , V_48 ) )
V_11 -> V_193 ( V_11 , V_46 -> V_78 ) ;
F_25 ( V_11 ) ;
F_17 ( V_169 ) ;
F_38 ( V_169 ) ;
F_97 ( V_169 ) ;
return 1 ;
}
static int F_98 ( struct V_194 * V_195 , struct V_56 * V_10 ,
struct V_196 * V_197 , T_4 V_78 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_33 * V_34 = F_11 ( V_11 ) ;
struct V_133 * V_198 = (struct V_133 * ) V_197 -> V_199 ;
int V_146 ;
struct V_133 V_167 ;
struct V_45 * V_46 ;
unsigned char * V_200 ;
int V_201 ;
if ( V_197 -> V_202 & ~ ( V_203 | V_204 | V_205 ) )
return - V_64 ;
F_49 ( V_11 ) ;
if ( F_65 ( V_11 , V_132 ) ) {
V_146 = - V_139 ;
goto V_206;
}
if ( V_11 -> V_122 & V_123 ) {
F_99 ( V_207 , V_160 , 0 ) ;
V_146 = - V_208 ;
goto V_206;
}
if ( V_34 -> V_16 == NULL ) {
V_146 = - V_17 ;
goto V_206;
}
if ( V_198 ) {
if ( V_197 -> V_209 < sizeof( V_167 ) ) {
V_146 = - V_64 ;
goto V_206;
}
V_167 = * V_198 ;
if ( F_20 ( & V_34 -> V_40 , & V_167 . V_138 ) != 0 ) {
V_146 = - V_152 ;
goto V_206;
}
if ( V_167 . V_136 != V_137 ) {
V_146 = - V_64 ;
goto V_206;
}
} else {
if ( V_11 -> V_28 != V_115 ) {
V_146 = - V_168 ;
goto V_206;
}
V_167 . V_136 = V_137 ;
V_167 . V_138 = V_34 -> V_40 ;
}
if ( V_78 > 65536 ) {
V_146 = - V_210 ;
goto V_206;
}
V_201 = V_78 + V_181 + V_182 ;
if ( ( V_46 = F_100 ( V_11 , V_201 , V_197 -> V_202 & V_203 , & V_146 ) ) == NULL )
goto V_206;
F_101 ( V_46 , V_201 - V_78 ) ;
F_89 ( V_46 ) ;
V_200 = F_102 ( V_46 , V_182 ) ;
* V_200 ++ = V_34 -> V_38 ;
* V_200 ++ = V_34 -> V_39 ;
* V_200 ++ = 0 ;
* V_200 ++ = 0 ;
* V_200 ++ = V_211 ;
F_103 ( V_46 , V_78 ) ;
if ( F_104 ( F_105 ( V_46 ) , V_197 -> V_212 , V_78 ) ) {
F_39 ( V_46 ) ;
V_146 = - V_65 ;
goto V_206;
}
if ( V_11 -> V_28 != V_115 ) {
F_39 ( V_46 ) ;
V_146 = - V_168 ;
goto V_206;
}
F_106 ( V_11 , V_46 ) ;
V_146 = V_78 ;
V_206:
F_50 ( V_11 ) ;
return V_146 ;
}
static int F_107 ( struct V_194 * V_195 , struct V_56 * V_10 ,
struct V_196 * V_197 , T_4 V_201 , int V_145 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
struct V_133 * V_167 = (struct V_133 * ) V_197 -> V_199 ;
T_4 V_213 ;
struct V_45 * V_46 ;
int V_214 ;
F_49 ( V_11 ) ;
if ( V_11 -> V_28 != V_115 ) {
F_50 ( V_11 ) ;
return - V_168 ;
}
if ( ( V_46 = F_108 ( V_11 , V_145 & ~ V_203 , V_145 & V_203 , & V_214 ) ) == NULL ) {
F_50 ( V_11 ) ;
return V_214 ;
}
F_89 ( V_46 ) ;
V_213 = V_46 -> V_78 ;
if ( V_213 > V_201 ) {
V_213 = V_201 ;
V_197 -> V_202 |= V_215 ;
}
V_214 = F_109 ( V_46 , 0 , V_197 -> V_212 , V_213 ) ;
if ( V_214 < 0 ) {
F_110 ( V_11 , V_46 ) ;
F_50 ( V_11 ) ;
return V_214 ;
}
if ( V_167 != NULL ) {
V_167 -> V_136 = V_137 ;
F_111 ( V_46 , 7 , V_167 -> V_138 . V_216 ,
V_81 ) ;
}
V_197 -> V_209 = sizeof( * V_167 ) ;
F_110 ( V_11 , V_46 ) ;
F_50 ( V_11 ) ;
return V_213 ;
}
static int F_112 ( struct V_56 * V_10 , unsigned int V_217 , unsigned long V_218 )
{
struct V_10 * V_11 = V_10 -> V_11 ;
void T_2 * V_219 = ( void T_2 * ) V_218 ;
int V_178 ;
switch ( V_217 ) {
case V_220 : {
long V_221 ;
F_49 ( V_11 ) ;
V_221 = V_11 -> V_114 - F_113 ( V_11 ) ;
if ( V_221 < 0 )
V_221 = 0 ;
F_50 ( V_11 ) ;
return F_46 ( V_221 , ( int T_2 * ) V_219 ) ;
}
case V_222 : {
struct V_45 * V_46 ;
long V_221 = 0L ;
F_49 ( V_11 ) ;
if ( ( V_46 = F_114 ( & V_11 -> V_47 ) ) != NULL )
V_221 = V_46 -> V_78 ;
F_50 ( V_11 ) ;
return F_46 ( V_221 , ( int T_2 * ) V_219 ) ;
}
case V_223 :
F_49 ( V_11 ) ;
V_178 = F_115 ( V_11 , V_219 ) ;
F_50 ( V_11 ) ;
return V_178 ;
case V_224 :
F_49 ( V_11 ) ;
V_178 = F_116 ( V_11 , V_219 ) ;
F_50 ( V_11 ) ;
return V_178 ;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
return - V_64 ;
case V_235 :
case V_236 :
case V_237 :
if ( ! F_67 ( V_154 ) )
return - V_141 ;
return F_117 ( V_217 , V_219 ) ;
default:
return - V_238 ;
}
return 0 ;
}
static void * F_118 ( struct V_239 * V_240 , T_5 * V_241 )
{
F_6 ( & V_12 ) ;
return F_119 ( & V_25 , * V_241 ) ;
}
static void * F_120 ( struct V_239 * V_240 , void * V_242 , T_5 * V_241 )
{
return F_121 ( V_242 , & V_25 , V_241 ) ;
}
static void F_122 ( struct V_239 * V_240 , void * V_242 )
{
F_8 ( & V_12 ) ;
}
static int F_123 ( struct V_239 * V_240 , void * V_242 )
{
struct V_10 * V_13 = F_124 ( V_242 ) ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
const char * V_243 ;
char V_244 [ 11 ] ;
if ( V_242 == V_245 )
F_125 ( V_240 ,
L_1 ) ;
else {
F_21 ( V_13 ) ;
V_34 = F_11 ( V_13 ) ;
if ( ( V_2 = V_34 -> V_16 ) == NULL )
V_243 = L_2 ;
else
V_243 = V_2 -> V_246 ;
F_126 ( V_240 , L_3 , F_127 ( V_244 , & V_34 -> V_80 ) ) ;
F_126 ( V_240 , L_3 , F_127 ( V_244 , & V_34 -> V_40 ) ) ;
F_126 ( V_240 ,
L_4 ,
F_127 ( V_244 , & V_34 -> V_27 ) ,
V_243 ,
V_34 -> V_35 ,
V_34 -> V_36 ,
V_34 -> V_38 ,
V_34 -> V_39 ,
V_34 -> V_49 ,
V_34 -> V_189 ,
V_34 -> V_191 ,
V_34 -> V_190 ,
F_128 ( & V_34 -> V_247 ) / V_55 ,
V_34 -> V_68 / V_55 ,
F_128 ( & V_34 -> V_248 ) / V_55 ,
V_34 -> V_70 / V_55 ,
F_128 ( & V_34 -> V_249 ) / V_55 ,
V_34 -> V_74 / V_55 ,
F_128 ( & V_34 -> V_250 ) / ( 60 * V_55 ) ,
V_34 -> V_76 / ( 60 * V_55 ) ,
V_34 -> V_119 ,
V_34 -> V_72 ,
V_34 -> V_105 ,
F_113 ( V_13 ) ,
F_129 ( V_13 ) ,
V_13 -> V_251 ? F_130 ( V_13 -> V_251 ) -> V_252 : 0L ) ;
F_25 ( V_13 ) ;
}
return 0 ;
}
static int F_131 ( struct V_253 * V_253 , struct V_254 * V_254 )
{
return F_132 ( V_254 , & V_255 ) ;
}
static int T_6 F_133 ( void )
{
int V_42 ;
int V_256 = F_134 ( & V_92 , 0 ) ;
if ( V_256 != 0 )
goto V_206;
if ( V_257 > 0x7fffffff / sizeof( struct V_1 * ) ) {
F_135 ( V_258 L_5 ) ;
return - 1 ;
}
V_259 = F_136 ( V_257 * sizeof( struct V_1 * ) , V_260 ) ;
if ( V_259 == NULL ) {
F_135 ( V_258 L_6 ) ;
return - 1 ;
}
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
char V_246 [ V_261 ] ;
struct V_1 * V_2 ;
sprintf ( V_246 , L_7 , V_42 ) ;
V_2 = F_137 ( 0 , V_246 , V_262 ) ;
if ( ! V_2 ) {
F_135 ( V_258 L_8 ) ;
goto V_263;
}
V_2 -> V_264 = V_42 ;
if ( F_138 ( V_2 ) ) {
F_135 ( V_258 L_9 ) ;
F_139 ( V_2 ) ;
goto V_263;
}
F_3 ( V_2 ) ;
V_259 [ V_42 ] = V_2 ;
}
if ( F_140 ( & V_265 ) ) {
F_135 ( V_258 L_10 ) ;
goto V_263;
}
F_141 ( & V_266 ) ;
F_142 ( & V_267 ) ;
F_143 ( & V_268 ) ;
#ifdef F_144
F_145 () ;
#endif
F_146 () ;
F_147 ( & V_22 , L_11 , V_269 , & V_270 ) ;
F_147 ( & V_22 , L_12 , V_269 , & V_271 ) ;
F_147 ( & V_22 , L_13 , V_269 , & V_272 ) ;
V_206:
return V_256 ;
V_263:
while ( -- V_42 >= 0 ) {
F_148 ( V_259 [ V_42 ] ) ;
F_139 ( V_259 [ V_42 ] ) ;
}
F_149 ( V_259 ) ;
F_150 ( & V_92 ) ;
V_256 = - 1 ;
goto V_206;
}
static void T_7 F_151 ( void )
{
int V_42 ;
F_152 ( & V_22 , L_11 ) ;
F_152 ( & V_22 , L_12 ) ;
F_152 ( & V_22 , L_13 ) ;
F_153 () ;
F_154 () ;
#ifdef F_144
F_155 () ;
#endif
F_156 ( & V_268 ) ;
F_157 ( V_273 ) ;
F_158 ( & V_266 ) ;
F_159 ( V_90 ) ;
for ( V_42 = 0 ; V_42 < V_257 ; V_42 ++ ) {
struct V_1 * V_2 = V_259 [ V_42 ] ;
if ( V_2 ) {
F_148 ( V_2 ) ;
F_139 ( V_2 ) ;
}
}
F_149 ( V_259 ) ;
F_150 ( & V_92 ) ;
}
