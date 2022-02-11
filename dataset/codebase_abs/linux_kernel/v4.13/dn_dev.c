static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
char V_8 [ sizeof( L_1 ) + V_9 ] ;
V_6 = F_2 ( & V_10 , sizeof( * V_6 ) , V_11 ) ;
if ( V_6 == NULL )
return;
for( V_7 = 0 ; V_7 < F_3 ( V_6 -> V_12 ) - 1 ; V_7 ++ ) {
long V_13 = ( long ) V_6 -> V_12 [ V_7 ] . V_14 ;
V_6 -> V_12 [ V_7 ] . V_14 = ( ( char * ) V_4 ) + V_13 ;
}
snprintf ( V_8 , sizeof( V_8 ) , L_2 ,
V_2 ? V_2 -> V_15 : V_4 -> V_15 ) ;
V_6 -> V_12 [ 0 ] . V_16 = ( void * ) V_2 ;
V_6 -> V_17 = F_4 ( & V_18 , V_8 , V_6 -> V_12 ) ;
if ( V_6 -> V_17 == NULL )
F_5 ( V_6 ) ;
else
V_4 -> V_19 = V_6 ;
}
static void F_6 ( struct V_3 * V_4 )
{
if ( V_4 -> V_19 ) {
struct V_5 * V_6 = V_4 -> V_19 ;
V_4 -> V_19 = NULL ;
F_7 ( V_6 -> V_17 ) ;
F_5 ( V_6 ) ;
}
}
static int F_8 ( struct V_20 * V_21 , int V_22 ,
void T_1 * V_23 ,
T_2 * V_24 , T_3 * V_25 )
{
#ifdef F_9
struct V_1 * V_2 = V_21 -> V_16 ;
struct V_26 * V_27 ;
int V_28 ;
int V_29 , V_30 ;
if ( V_21 -> V_16 == NULL )
return - V_31 ;
V_27 = F_10 ( V_2 -> V_32 ) ;
V_30 = V_27 -> V_4 . V_33 ;
V_28 = F_11 ( V_21 , V_22 , V_23 , V_24 , V_25 ) ;
if ( ( V_28 >= 0 ) && V_22 ) {
if ( V_27 -> V_4 . V_33 < 0 )
V_27 -> V_4 . V_33 = 0 ;
if ( V_27 -> V_4 . V_33 > 2 )
V_27 -> V_4 . V_33 = 2 ;
V_29 = V_27 -> V_4 . V_33 ;
V_27 -> V_4 . V_33 = V_30 ;
if ( V_27 -> V_4 . V_34 )
V_27 -> V_4 . V_34 ( V_2 ) ;
V_27 -> V_4 . V_33 = V_29 ;
if ( V_27 -> V_4 . V_35 )
V_27 -> V_4 . V_35 ( V_2 ) ;
}
return V_28 ;
#else
return - V_31 ;
#endif
}
static void F_6 ( struct V_3 * V_4 )
{
}
static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static inline T_4 F_12 ( struct V_1 * V_2 )
{
T_5 V_36 = V_2 -> V_37 ;
if ( V_36 > 0xffff )
V_36 = 0xffff ;
if ( V_2 -> type == V_38 ||
V_2 -> type == V_39 ||
V_2 -> type == V_40 ||
V_2 -> type == V_41 )
V_36 -= 2 ;
return ( T_4 ) V_36 ;
}
static struct V_42 * F_13 ( void )
{
struct V_42 * V_43 ;
V_43 = F_14 ( sizeof( * V_43 ) , V_11 ) ;
return V_43 ;
}
static void F_15 ( struct V_42 * V_43 )
{
F_16 ( V_43 , V_44 ) ;
}
static void F_17 ( struct V_26 * V_27 , struct V_42 T_6 * * V_45 , int V_46 )
{
struct V_42 * V_47 = F_18 ( * V_45 ) ;
unsigned char V_48 [ 6 ] ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_19 () ;
* V_45 = V_47 -> V_49 ;
if ( V_27 -> V_2 -> type == V_38 ) {
if ( V_47 -> V_50 != F_20 ( V_2 -> V_51 ) ) {
F_21 ( V_48 , V_47 -> V_50 ) ;
F_22 ( V_2 , V_48 ) ;
}
}
F_23 ( V_52 , V_47 ) ;
F_24 ( & V_53 , V_54 , V_47 ) ;
if ( V_46 ) {
F_15 ( V_47 ) ;
if ( V_27 -> V_55 == NULL )
F_25 ( V_27 -> V_2 ) ;
}
}
static int F_26 ( struct V_26 * V_27 , struct V_42 * V_43 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_42 * V_47 ;
unsigned char V_48 [ 6 ] ;
F_19 () ;
for ( V_47 = F_18 ( V_27 -> V_55 ) ;
V_47 != NULL ;
V_47 = F_18 ( V_47 -> V_49 ) ) {
if ( V_47 -> V_50 == V_43 -> V_50 )
return - V_56 ;
}
if ( V_2 -> type == V_38 ) {
if ( V_43 -> V_50 != F_20 ( V_2 -> V_51 ) ) {
F_21 ( V_48 , V_43 -> V_50 ) ;
F_27 ( V_2 , V_48 ) ;
}
}
V_43 -> V_49 = V_27 -> V_55 ;
F_28 ( V_27 -> V_55 , V_43 ) ;
F_23 ( V_57 , V_43 ) ;
F_24 ( & V_53 , V_58 , V_43 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_26 * V_27 = F_18 ( V_2 -> V_32 ) ;
int V_59 ;
if ( V_27 == NULL ) {
int V_28 ;
V_27 = F_30 ( V_2 , & V_28 ) ;
if ( V_27 == NULL )
return V_28 ;
}
V_43 -> V_60 = V_27 ;
if ( V_2 -> V_61 & V_62 )
V_43 -> V_63 = V_64 ;
V_59 = F_26 ( V_27 , V_43 ) ;
if ( V_59 )
F_15 ( V_43 ) ;
return V_59 ;
}
int F_31 ( unsigned int V_65 , void T_1 * V_66 )
{
char V_23 [ V_67 ] ;
struct V_68 * V_69 = (struct V_68 * ) V_23 ;
struct V_70 * V_71 = (struct V_70 * ) & V_69 -> V_72 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_42 * V_43 = NULL ;
struct V_42 T_6 * * V_45 = NULL ;
int V_73 = 0 ;
if ( F_32 ( V_69 , V_66 , V_67 ) )
return - V_74 ;
V_69 -> V_75 [ V_9 - 1 ] = 0 ;
F_33 ( & V_18 , V_69 -> V_75 ) ;
switch ( V_65 ) {
case V_76 :
break;
case V_77 :
if ( ! F_34 ( V_78 ) )
return - V_79 ;
if ( V_71 -> V_80 != V_81 )
return - V_31 ;
break;
default:
return - V_31 ;
}
F_35 () ;
if ( ( V_2 = F_36 ( & V_18 , V_69 -> V_75 ) ) == NULL ) {
V_73 = - V_82 ;
goto V_83;
}
if ( ( V_27 = F_18 ( V_2 -> V_32 ) ) != NULL ) {
for ( V_45 = & V_27 -> V_55 ;
( V_43 = F_18 ( * V_45 ) ) != NULL ;
V_45 = & V_43 -> V_49 )
if ( strcmp ( V_69 -> V_75 , V_43 -> V_84 ) == 0 )
break;
}
if ( V_43 == NULL && V_65 != V_77 ) {
V_73 = - V_85 ;
goto V_83;
}
switch ( V_65 ) {
case V_76 :
* ( ( V_86 * ) V_71 -> V_87 ) = V_43 -> V_50 ;
goto V_88;
case V_77 :
if ( ! V_43 ) {
if ( ( V_43 = F_13 () ) == NULL ) {
V_73 = - V_89 ;
break;
}
memcpy ( V_43 -> V_84 , V_2 -> V_15 , V_9 ) ;
} else {
if ( V_43 -> V_50 == F_37 ( V_71 ) )
break;
F_17 ( V_27 , V_45 , 0 ) ;
}
V_43 -> V_50 = V_43 -> V_90 = F_37 ( V_71 ) ;
V_73 = F_29 ( V_2 , V_43 ) ;
}
V_83:
F_38 () ;
return V_73 ;
V_88:
if ( F_39 ( V_66 , V_69 , V_67 ) )
V_73 = - V_74 ;
goto V_83;
}
struct V_1 * F_40 ( void )
{
struct V_1 * V_2 ;
F_41 ( & V_91 ) ;
V_2 = V_92 ;
if ( V_2 ) {
if ( V_2 -> V_32 )
F_42 ( V_2 ) ;
else
V_2 = NULL ;
}
F_43 ( & V_91 ) ;
return V_2 ;
}
int F_44 ( struct V_1 * V_2 , int V_93 )
{
struct V_1 * V_30 = NULL ;
int V_59 = - V_94 ;
if ( ! V_2 -> V_32 )
return - V_82 ;
F_41 ( & V_91 ) ;
if ( V_93 || V_92 == NULL ) {
V_30 = V_92 ;
V_92 = V_2 ;
V_59 = 0 ;
}
F_43 ( & V_91 ) ;
if ( V_30 )
F_45 ( V_30 ) ;
return V_59 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_41 ( & V_91 ) ;
if ( V_2 == V_92 ) {
V_92 = NULL ;
} else {
V_2 = NULL ;
}
F_43 ( & V_91 ) ;
if ( V_2 )
F_45 ( V_2 ) ;
}
static struct V_26 * F_47 ( int V_95 )
{
struct V_1 * V_2 ;
struct V_26 * V_26 = NULL ;
V_2 = F_48 ( & V_18 , V_95 ) ;
if ( V_2 )
V_26 = F_18 ( V_2 -> V_32 ) ;
return V_26 ;
}
static int F_49 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_102 * V_102 = F_50 ( V_97 -> V_103 ) ;
struct V_104 * V_105 [ V_106 + 1 ] ;
struct V_26 * V_27 ;
struct V_107 * V_108 ;
struct V_42 * V_43 ;
struct V_42 T_6 * * V_45 ;
int V_28 = - V_31 ;
if ( ! F_51 ( V_97 , V_78 ) )
return - V_109 ;
if ( ! F_52 ( V_102 , & V_18 ) )
goto V_110;
V_28 = F_53 ( V_99 , sizeof( * V_108 ) , V_105 , V_106 , V_111 ,
V_101 ) ;
if ( V_28 < 0 )
goto V_110;
V_28 = - V_82 ;
V_108 = F_54 ( V_99 ) ;
if ( ( V_27 = F_47 ( V_108 -> V_112 ) ) == NULL )
goto V_110;
V_28 = - V_85 ;
for ( V_45 = & V_27 -> V_55 ;
( V_43 = F_18 ( * V_45 ) ) != NULL ;
V_45 = & V_43 -> V_49 ) {
if ( V_105 [ V_113 ] &&
F_55 ( V_105 [ V_113 ] , & V_43 -> V_50 , 2 ) )
continue;
if ( V_105 [ V_114 ] && F_56 ( V_105 [ V_114 ] , V_43 -> V_84 ) )
continue;
F_17 ( V_27 , V_45 , 1 ) ;
return 0 ;
}
V_110:
return V_28 ;
}
static int F_57 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_102 * V_102 = F_50 ( V_97 -> V_103 ) ;
struct V_104 * V_105 [ V_106 + 1 ] ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_107 * V_108 ;
struct V_42 * V_43 ;
int V_28 ;
if ( ! F_51 ( V_97 , V_78 ) )
return - V_109 ;
if ( ! F_52 ( V_102 , & V_18 ) )
return - V_31 ;
V_28 = F_53 ( V_99 , sizeof( * V_108 ) , V_105 , V_106 , V_111 ,
V_101 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_105 [ V_113 ] == NULL )
return - V_31 ;
V_108 = F_54 ( V_99 ) ;
if ( ( V_2 = F_48 ( & V_18 , V_108 -> V_112 ) ) == NULL )
return - V_82 ;
if ( ( V_27 = F_18 ( V_2 -> V_32 ) ) == NULL ) {
V_27 = F_30 ( V_2 , & V_28 ) ;
if ( ! V_27 )
return V_28 ;
}
if ( ( V_43 = F_13 () ) == NULL )
return - V_89 ;
if ( V_105 [ V_115 ] == NULL )
V_105 [ V_115 ] = V_105 [ V_113 ] ;
V_43 -> V_50 = F_58 ( V_105 [ V_113 ] ) ;
V_43 -> V_90 = F_58 ( V_105 [ V_115 ] ) ;
V_43 -> V_116 = V_105 [ V_117 ] ? F_59 ( V_105 [ V_117 ] ) :
V_108 -> V_116 ;
V_43 -> V_63 = V_108 -> V_63 ;
V_43 -> V_60 = V_27 ;
if ( V_105 [ V_114 ] )
F_60 ( V_43 -> V_84 , V_105 [ V_114 ] , V_9 ) ;
else
memcpy ( V_43 -> V_84 , V_2 -> V_15 , V_9 ) ;
V_28 = F_26 ( V_27 , V_43 ) ;
if ( V_28 )
F_15 ( V_43 ) ;
return V_28 ;
}
static inline T_2 F_61 ( void )
{
return F_62 ( sizeof( struct V_107 ) )
+ F_63 ( V_9 )
+ F_63 ( 2 )
+ F_63 ( 2 )
+ F_63 ( 4 ) ;
}
static int F_64 ( struct V_96 * V_97 , struct V_42 * V_43 ,
T_5 V_118 , T_5 V_119 , int V_120 , unsigned int V_61 )
{
struct V_107 * V_108 ;
struct V_98 * V_99 ;
T_5 V_116 = V_43 -> V_116 | V_121 ;
V_99 = F_65 ( V_97 , V_118 , V_119 , V_120 , sizeof( * V_108 ) , V_61 ) ;
if ( V_99 == NULL )
return - V_122 ;
V_108 = F_54 ( V_99 ) ;
V_108 -> V_123 = V_81 ;
V_108 -> V_124 = 16 ;
V_108 -> V_116 = V_116 ;
V_108 -> V_63 = V_43 -> V_63 ;
V_108 -> V_112 = V_43 -> V_60 -> V_2 -> V_95 ;
if ( ( V_43 -> V_90 &&
F_66 ( V_97 , V_115 , V_43 -> V_90 ) ) ||
( V_43 -> V_50 &&
F_66 ( V_97 , V_113 , V_43 -> V_50 ) ) ||
( V_43 -> V_84 [ 0 ] &&
F_67 ( V_97 , V_114 , V_43 -> V_84 ) ) ||
F_68 ( V_97 , V_117 , V_116 ) )
goto V_125;
F_69 ( V_97 , V_99 ) ;
return 0 ;
V_125:
F_70 ( V_97 , V_99 ) ;
return - V_122 ;
}
static void F_23 ( int V_120 , struct V_42 * V_43 )
{
struct V_96 * V_97 ;
int V_28 = - V_89 ;
V_97 = F_71 ( F_61 () , V_11 ) ;
if ( V_97 == NULL )
goto V_110;
V_28 = F_64 ( V_97 , V_43 , 0 , 0 , V_120 , 0 ) ;
if ( V_28 < 0 ) {
F_72 ( V_28 == - V_122 ) ;
F_73 ( V_97 ) ;
goto V_110;
}
F_74 ( V_97 , & V_18 , 0 , V_126 , NULL , V_11 ) ;
return;
V_110:
if ( V_28 < 0 )
F_75 ( & V_18 , V_126 , V_28 ) ;
}
static int F_76 ( struct V_96 * V_97 , struct V_127 * V_128 )
{
struct V_102 * V_102 = F_50 ( V_97 -> V_103 ) ;
int V_129 , V_130 = 0 , V_131 , V_132 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_42 * V_43 ;
if ( ! F_52 ( V_102 , & V_18 ) )
return 0 ;
V_131 = V_128 -> args [ 0 ] ;
V_132 = V_128 -> args [ 1 ] ;
V_129 = 0 ;
F_77 () ;
F_78 (&init_net, dev) {
if ( V_129 < V_131 )
goto V_133;
else if ( V_129 > V_131 ) {
V_132 = 0 ;
}
if ( ( V_27 = F_79 ( V_2 -> V_32 ) ) == NULL )
goto V_133;
for ( V_43 = F_79 ( V_27 -> V_55 ) , V_130 = 0 ; V_43 ;
V_43 = F_79 ( V_43 -> V_49 ) , V_130 ++ ) {
if ( V_130 < V_132 )
continue;
if ( F_64 ( V_97 , V_43 , F_80 ( V_128 -> V_97 ) . V_118 ,
V_128 -> V_99 -> V_134 , V_57 ,
V_135 ) < 0 )
goto V_83;
}
V_133:
V_129 ++ ;
}
V_83:
F_81 () ;
V_128 -> args [ 0 ] = V_129 ;
V_128 -> args [ 1 ] = V_130 ;
return V_97 -> V_136 ;
}
static int F_82 ( struct V_1 * V_2 , V_86 * V_137 )
{
struct V_26 * V_27 ;
struct V_42 * V_43 ;
int V_59 = - V_82 ;
F_77 () ;
V_27 = F_79 ( V_2 -> V_32 ) ;
if ( V_27 == NULL )
goto V_138;
V_43 = F_79 ( V_27 -> V_55 ) ;
if ( V_43 != NULL ) {
* V_137 = V_43 -> V_50 ;
V_59 = 0 ;
}
V_138:
F_81 () ;
return V_59 ;
}
int F_83 ( V_86 * V_137 )
{
struct V_1 * V_2 ;
int V_59 ;
V_2 = F_40 () ;
V_139:
if ( V_2 ) {
V_59 = F_82 ( V_2 , V_137 ) ;
F_45 ( V_2 ) ;
if ( V_59 == 0 || V_2 == V_18 . V_140 )
return V_59 ;
}
V_2 = V_18 . V_140 ;
F_42 ( V_2 ) ;
goto V_139;
}
static void F_84 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_141 * V_142 ;
struct V_96 * V_97 = NULL ;
V_86 * V_143 ;
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( ( V_97 = F_85 ( NULL , sizeof( * V_142 ) , V_144 ) ) == NULL )
return;
V_97 -> V_2 = V_2 ;
V_142 = F_86 ( V_97 , sizeof( * V_142 ) ) ;
V_142 -> V_145 = 0x0D ;
memcpy ( V_142 -> V_146 , V_147 , 3 ) ;
F_21 ( V_142 -> V_148 , V_43 -> V_50 ) ;
V_142 -> V_149 = V_150 ;
V_142 -> V_36 = F_87 ( F_12 ( V_2 ) ) ;
V_142 -> V_151 = 0x00 ;
memset ( V_142 -> V_152 , 0 , 8 ) ;
memcpy ( V_142 -> V_153 , V_154 , V_155 ) ;
if ( V_27 -> V_156 ) {
struct V_157 * V_158 = (struct V_157 * ) V_27 -> V_156 ;
F_21 ( V_142 -> V_153 , V_158 -> V_137 ) ;
}
V_142 -> V_159 = F_87 ( ( unsigned short ) V_27 -> V_4 . V_160 ) ;
V_142 -> V_161 = 0x00 ;
V_142 -> V_162 = 0x02 ;
memset ( V_142 -> V_14 , 0xAA , 2 ) ;
V_143 = F_88 ( V_97 , 2 ) ;
* V_143 = F_87 ( V_97 -> V_136 - 2 ) ;
F_89 ( V_97 ) ;
F_90 ( V_97 , V_163 , V_142 -> V_148 ) ;
}
static int F_91 ( struct V_157 * V_158 , struct V_26 * V_27 , struct V_42 * V_43 )
{
if ( F_92 ( V_164 , V_27 -> V_165 + V_166 ) )
return 0 ;
if ( ! V_27 -> V_156 )
return 1 ;
if ( V_158 -> V_167 < V_27 -> V_4 . V_167 )
return 1 ;
if ( V_158 -> V_167 != V_27 -> V_4 . V_167 )
return 0 ;
if ( F_93 ( V_158 -> V_137 ) < F_93 ( V_43 -> V_50 ) )
return 1 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
int V_168 ;
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
struct V_157 * V_158 = (struct V_157 * ) V_27 -> V_156 ;
struct V_96 * V_97 ;
T_2 V_169 ;
unsigned char * V_170 ;
unsigned char * V_171 , * V_172 ;
V_86 * V_143 ;
char * V_173 ;
if ( F_12 ( V_2 ) < ( 26 + 7 ) )
return;
V_168 = F_12 ( V_2 ) - 26 ;
V_168 /= 7 ;
if ( V_168 > 32 )
V_168 = 32 ;
V_169 = 2 + 26 + 7 * V_168 ;
if ( ( V_97 = F_85 ( NULL , V_169 , V_144 ) ) == NULL )
return;
V_97 -> V_2 = V_2 ;
V_170 = F_86 ( V_97 , V_169 ) ;
* V_170 ++ = V_174 | V_175 ;
* V_170 ++ = 2 ;
* V_170 ++ = 0 ;
* V_170 ++ = 0 ;
F_21 ( V_170 , V_43 -> V_50 ) ;
V_173 = V_170 ;
V_170 += V_155 ;
* V_170 ++ = V_27 -> V_4 . V_33 == 1 ?
V_176 : V_177 ;
* ( ( V_86 * ) V_170 ) = F_87 ( F_12 ( V_2 ) ) ;
V_170 += 2 ;
* V_170 ++ = V_27 -> V_4 . V_167 ;
* V_170 ++ = 0 ;
* ( ( V_86 * ) V_170 ) = F_87 ( ( unsigned short ) V_27 -> V_4 . V_160 ) ;
V_170 += 2 ;
* V_170 ++ = 0 ;
V_171 = V_170 ++ ;
memset ( V_170 , 0 , 7 ) ;
V_170 += 7 ;
V_172 = V_170 ++ ;
V_168 = F_95 ( V_2 , V_170 , V_168 ) ;
* V_172 = 7 * V_168 ;
* V_171 = 8 + * V_172 ;
F_96 ( V_97 , ( 27 + * V_172 ) ) ;
V_143 = F_88 ( V_97 , 2 ) ;
* V_143 = F_87 ( V_97 -> V_136 - 2 ) ;
F_89 ( V_97 ) ;
if ( F_91 ( V_158 , V_27 , V_43 ) ) {
struct V_96 * V_178 = F_97 ( V_97 , V_144 ) ;
if ( V_178 ) {
F_90 ( V_178 , V_179 , V_173 ) ;
}
}
F_90 ( V_97 , V_163 , V_173 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_84 ( V_2 , V_43 ) ;
else
F_94 ( V_2 , V_43 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
int V_180 = 16 ;
int V_169 = V_2 -> V_181 + 2 + 4 + V_180 ;
struct V_96 * V_97 = F_85 ( NULL , V_169 , V_144 ) ;
int V_7 ;
unsigned char * V_170 ;
char V_173 [ V_155 ] ;
if ( V_97 == NULL )
return ;
V_97 -> V_2 = V_2 ;
F_88 ( V_97 , V_2 -> V_181 ) ;
V_170 = F_86 ( V_97 , 2 + 4 + V_180 ) ;
* V_170 ++ = V_182 ;
* ( ( V_86 * ) V_170 ) = V_43 -> V_50 ;
V_170 += 2 ;
* V_170 ++ = V_180 ;
for( V_7 = 0 ; V_7 < V_180 ; V_7 ++ )
* V_170 ++ = 0252 ;
F_21 ( V_173 , V_43 -> V_50 ) ;
F_90 ( V_97 , V_163 , V_173 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_27 ( V_2 , V_179 ) ;
else
F_27 ( V_2 , V_163 ) ;
V_27 -> V_183 = 1 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_22 ( V_2 , V_179 ) ;
else
F_22 ( V_2 , V_163 ) ;
}
static void F_102 ( unsigned long V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
struct V_26 * V_27 ;
struct V_42 * V_43 ;
F_77 () ;
V_27 = F_79 ( V_2 -> V_32 ) ;
if ( V_27 -> V_160 <= V_27 -> V_4 . V_184 ) {
if ( V_27 -> V_4 . V_185 ) {
for ( V_43 = F_79 ( V_27 -> V_55 ) ;
V_43 ;
V_43 = F_79 ( V_43 -> V_49 ) ) {
if ( ! ( V_43 -> V_116 & V_186 ) )
V_27 -> V_4 . V_185 ( V_2 , V_43 ) ;
}
}
V_27 -> V_160 = V_27 -> V_4 . V_160 ;
} else {
V_27 -> V_160 -= V_27 -> V_4 . V_184 ;
}
F_81 () ;
F_103 ( V_2 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_184 > V_27 -> V_4 . V_160 )
V_27 -> V_4 . V_184 = V_27 -> V_4 . V_160 ;
V_27 -> V_159 . V_14 = ( unsigned long ) V_2 ;
V_27 -> V_159 . V_187 = F_102 ;
V_27 -> V_159 . V_188 = V_164 + ( V_27 -> V_4 . V_184 * V_189 ) ;
F_104 ( & V_27 -> V_159 ) ;
}
static struct V_26 * F_30 ( struct V_1 * V_2 , int * V_28 )
{
int V_7 ;
struct V_3 * V_190 = V_191 ;
struct V_26 * V_27 ;
for( V_7 = 0 ; V_7 < V_192 ; V_7 ++ , V_190 ++ ) {
if ( V_190 -> type == V_2 -> type )
break;
}
* V_28 = - V_82 ;
if ( V_7 == V_192 )
return NULL ;
* V_28 = - V_89 ;
if ( ( V_27 = F_14 ( sizeof( struct V_26 ) , V_144 ) ) == NULL )
return NULL ;
memcpy ( & V_27 -> V_4 , V_190 , sizeof( struct V_3 ) ) ;
F_28 ( V_2 -> V_32 , V_27 ) ;
V_27 -> V_2 = V_2 ;
F_105 ( & V_27 -> V_159 ) ;
V_27 -> V_165 = V_164 ;
V_27 -> V_193 = F_106 ( V_2 , & V_194 ) ;
if ( ! V_27 -> V_193 ) {
F_107 ( V_2 -> V_32 , NULL ) ;
F_5 ( V_27 ) ;
return NULL ;
}
if ( V_27 -> V_4 . V_35 ) {
if ( V_27 -> V_4 . V_35 ( V_2 ) < 0 ) {
F_108 ( & V_194 , V_27 -> V_193 ) ;
V_2 -> V_32 = NULL ;
F_5 ( V_27 ) ;
return NULL ;
}
}
F_1 ( V_2 , & V_27 -> V_4 ) ;
F_103 ( V_2 ) ;
* V_28 = 0 ;
return V_27 ;
}
void F_109 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_86 V_137 = V_195 ;
int V_196 = 0 ;
struct V_26 * V_27 = F_18 ( V_2 -> V_32 ) ;
if ( ( V_2 -> type != V_38 ) && ( V_2 -> type != V_41 ) )
return;
if ( V_27 == NULL ) {
int V_28 ;
V_27 = F_30 ( V_2 , & V_28 ) ;
if ( V_27 == NULL )
return;
}
if ( V_2 -> type == V_38 ) {
if ( memcmp ( V_2 -> V_51 , V_154 , 4 ) != 0 )
return;
V_137 = F_20 ( V_2 -> V_51 ) ;
V_196 = 1 ;
}
if ( V_137 == 0 )
return;
if ( ( V_43 = F_13 () ) == NULL )
return;
V_43 -> V_50 = V_43 -> V_90 = V_137 ;
V_43 -> V_116 = 0 ;
V_43 -> V_63 = V_197 ;
strcpy ( V_43 -> V_84 , V_2 -> V_15 ) ;
F_29 ( V_2 , V_43 ) ;
if ( V_196 ) {
F_42 ( V_2 ) ;
if ( F_44 ( V_2 , 0 ) )
F_45 ( V_2 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_18 ( V_2 -> V_32 ) ;
if ( V_27 == NULL )
return;
F_110 ( & V_27 -> V_159 ) ;
F_6 ( & V_27 -> V_4 ) ;
F_46 ( V_2 ) ;
F_111 ( & V_194 , V_2 ) ;
if ( V_27 -> V_4 . V_34 )
V_27 -> V_4 . V_34 ( V_2 ) ;
V_2 -> V_32 = NULL ;
F_108 ( & V_194 , V_27 -> V_193 ) ;
F_111 ( & V_194 , V_2 ) ;
if ( V_27 -> V_156 )
F_112 ( V_27 -> V_156 ) ;
if ( V_27 -> V_198 )
F_112 ( V_27 -> V_198 ) ;
F_5 ( V_27 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_18 ( V_2 -> V_32 ) ;
struct V_42 * V_43 ;
if ( V_27 == NULL )
return;
while ( ( V_43 = F_18 ( V_27 -> V_55 ) ) != NULL ) {
F_17 ( V_27 , & V_27 -> V_55 , 0 ) ;
F_15 ( V_43 ) ;
}
F_25 ( V_2 ) ;
}
void F_114 ( struct V_96 * V_97 )
{
}
void F_115 ( struct V_96 * V_97 )
{
}
void F_116 ( struct V_96 * V_97 )
{
}
void F_117 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_118 (&init_net, dev)
F_113 ( V_2 ) ;
F_38 () ;
}
void F_119 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_118 (&init_net, dev) {
if ( V_2 -> V_61 & V_199 )
F_109 ( V_2 ) ;
}
F_38 () ;
}
int F_120 ( struct V_200 * V_201 )
{
return F_121 ( & V_53 , V_201 ) ;
}
int F_122 ( struct V_200 * V_201 )
{
return F_123 ( & V_53 , V_201 ) ;
}
static inline int F_124 ( struct V_1 * V_2 )
{
return V_2 -> V_32 != NULL ;
}
static void * F_125 ( struct V_202 * V_119 , T_3 * V_203 )
__acquires( T_7 )
{
int V_7 ;
struct V_1 * V_2 ;
F_77 () ;
if ( * V_203 == 0 )
return V_204 ;
V_7 = 1 ;
F_78 (&init_net, dev) {
if ( ! F_124 ( V_2 ) )
continue;
if ( V_7 ++ == * V_203 )
return V_2 ;
}
return NULL ;
}
static void * F_126 ( struct V_202 * V_119 , void * V_205 , T_3 * V_203 )
{
struct V_1 * V_2 ;
++ * V_203 ;
V_2 = V_205 ;
if ( V_205 == V_204 )
V_2 = F_127 ( & V_18 . V_206 ) ;
F_128 (&init_net, dev) {
if ( ! F_124 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static void F_129 ( struct V_202 * V_119 , void * V_205 )
__releases( T_7 )
{
F_81 () ;
}
static char * F_130 ( char type )
{
switch ( type ) {
case V_207 :
return L_3 ;
case V_208 :
return L_4 ;
case V_209 :
return L_5 ;
}
return L_6 ;
}
static int F_131 ( struct V_202 * V_119 , void * V_205 )
{
if ( V_205 == V_204 )
F_132 ( V_119 , L_7 ) ;
else {
struct V_1 * V_2 = V_205 ;
char V_210 [ V_211 ] ;
char V_212 [ V_211 ] ;
struct V_26 * V_27 = F_79 ( V_2 -> V_32 ) ;
F_133 ( V_119 , L_8
L_9 ,
V_2 -> V_15 ? V_2 -> V_15 : L_10 ,
F_130 ( V_27 -> V_4 . V_213 ) ,
0 , 0 ,
V_27 -> V_160 , V_27 -> V_4 . V_160 ,
F_12 ( V_2 ) ,
V_27 -> V_4 . V_167 ,
V_27 -> V_4 . V_214 , V_27 -> V_4 . V_15 ,
V_27 -> V_156 ? F_134 ( F_93 ( * ( V_86 * ) V_27 -> V_156 -> V_215 ) , V_212 ) : L_11 ,
V_27 -> V_198 ? F_134 ( F_93 ( * ( V_86 * ) V_27 -> V_198 -> V_215 ) , V_210 ) : L_11 ) ;
}
return 0 ;
}
static int F_135 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_136 ( V_217 , & V_218 ) ;
}
void T_8 F_137 ( void )
{
if ( V_137 [ 0 ] > 63 || V_137 [ 0 ] < 0 ) {
F_138 ( V_219 L_12 ) ;
return;
}
if ( V_137 [ 1 ] > 1023 || V_137 [ 1 ] < 0 ) {
F_138 ( V_219 L_13 ) ;
return;
}
V_195 = F_87 ( ( V_137 [ 0 ] << 10 ) | V_137 [ 1 ] ) ;
F_119 () ;
F_139 ( V_220 , V_57 , F_57 , NULL , NULL ) ;
F_139 ( V_220 , V_52 , F_49 , NULL , NULL ) ;
F_139 ( V_220 , V_221 , NULL , F_76 , NULL ) ;
F_140 ( L_14 , V_222 , V_18 . V_223 , & V_224 ) ;
#ifdef F_141
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_192 ; V_7 ++ )
F_1 ( NULL , & V_191 [ V_7 ] ) ;
}
#endif
}
void T_9 F_142 ( void )
{
#ifdef F_141
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_192 ; V_7 ++ )
F_6 ( & V_191 [ V_7 ] ) ;
}
#endif
F_143 ( L_14 , V_18 . V_223 ) ;
F_117 () ;
}
