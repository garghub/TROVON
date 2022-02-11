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
static int F_49 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_100 * V_100 = F_50 ( V_97 -> V_101 ) ;
struct V_102 * V_103 [ V_104 + 1 ] ;
struct V_26 * V_27 ;
struct V_105 * V_106 ;
struct V_42 * V_43 ;
struct V_42 T_6 * * V_45 ;
int V_28 = - V_31 ;
if ( ! F_34 ( V_78 ) )
return - V_107 ;
if ( ! F_51 ( V_100 , & V_18 ) )
goto V_108;
V_28 = F_52 ( V_99 , sizeof( * V_106 ) , V_103 , V_104 , V_109 ) ;
if ( V_28 < 0 )
goto V_108;
V_28 = - V_82 ;
V_106 = F_53 ( V_99 ) ;
if ( ( V_27 = F_47 ( V_106 -> V_110 ) ) == NULL )
goto V_108;
V_28 = - V_85 ;
for ( V_45 = & V_27 -> V_55 ;
( V_43 = F_18 ( * V_45 ) ) != NULL ;
V_45 = & V_43 -> V_49 ) {
if ( V_103 [ V_111 ] &&
F_54 ( V_103 [ V_111 ] , & V_43 -> V_50 , 2 ) )
continue;
if ( V_103 [ V_112 ] && F_55 ( V_103 [ V_112 ] , V_43 -> V_84 ) )
continue;
F_17 ( V_27 , V_45 , 1 ) ;
return 0 ;
}
V_108:
return V_28 ;
}
static int F_56 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_100 * V_100 = F_50 ( V_97 -> V_101 ) ;
struct V_102 * V_103 [ V_104 + 1 ] ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_105 * V_106 ;
struct V_42 * V_43 ;
int V_28 ;
if ( ! F_34 ( V_78 ) )
return - V_107 ;
if ( ! F_51 ( V_100 , & V_18 ) )
return - V_31 ;
V_28 = F_52 ( V_99 , sizeof( * V_106 ) , V_103 , V_104 , V_109 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_103 [ V_111 ] == NULL )
return - V_31 ;
V_106 = F_53 ( V_99 ) ;
if ( ( V_2 = F_48 ( & V_18 , V_106 -> V_110 ) ) == NULL )
return - V_82 ;
if ( ( V_27 = F_18 ( V_2 -> V_32 ) ) == NULL ) {
V_27 = F_30 ( V_2 , & V_28 ) ;
if ( ! V_27 )
return V_28 ;
}
if ( ( V_43 = F_13 () ) == NULL )
return - V_89 ;
if ( V_103 [ V_113 ] == NULL )
V_103 [ V_113 ] = V_103 [ V_111 ] ;
V_43 -> V_50 = F_57 ( V_103 [ V_111 ] ) ;
V_43 -> V_90 = F_57 ( V_103 [ V_113 ] ) ;
V_43 -> V_114 = V_103 [ V_115 ] ? F_58 ( V_103 [ V_115 ] ) :
V_106 -> V_114 ;
V_43 -> V_63 = V_106 -> V_63 ;
V_43 -> V_60 = V_27 ;
if ( V_103 [ V_112 ] )
F_59 ( V_43 -> V_84 , V_103 [ V_112 ] , V_9 ) ;
else
memcpy ( V_43 -> V_84 , V_2 -> V_15 , V_9 ) ;
V_28 = F_26 ( V_27 , V_43 ) ;
if ( V_28 )
F_15 ( V_43 ) ;
return V_28 ;
}
static inline T_2 F_60 ( void )
{
return F_61 ( sizeof( struct V_105 ) )
+ F_62 ( V_9 )
+ F_62 ( 2 )
+ F_62 ( 2 )
+ F_62 ( 4 ) ;
}
static int F_63 ( struct V_96 * V_97 , struct V_42 * V_43 ,
T_5 V_116 , T_5 V_117 , int V_118 , unsigned int V_61 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
T_5 V_114 = V_43 -> V_114 | V_119 ;
V_99 = F_64 ( V_97 , V_116 , V_117 , V_118 , sizeof( * V_106 ) , V_61 ) ;
if ( V_99 == NULL )
return - V_120 ;
V_106 = F_53 ( V_99 ) ;
V_106 -> V_121 = V_81 ;
V_106 -> V_122 = 16 ;
V_106 -> V_114 = V_114 ;
V_106 -> V_63 = V_43 -> V_63 ;
V_106 -> V_110 = V_43 -> V_60 -> V_2 -> V_95 ;
if ( ( V_43 -> V_90 &&
F_65 ( V_97 , V_113 , V_43 -> V_90 ) ) ||
( V_43 -> V_50 &&
F_65 ( V_97 , V_111 , V_43 -> V_50 ) ) ||
( V_43 -> V_84 [ 0 ] &&
F_66 ( V_97 , V_112 , V_43 -> V_84 ) ) ||
F_67 ( V_97 , V_115 , V_114 ) )
goto V_123;
return F_68 ( V_97 , V_99 ) ;
V_123:
F_69 ( V_97 , V_99 ) ;
return - V_120 ;
}
static void F_23 ( int V_118 , struct V_42 * V_43 )
{
struct V_96 * V_97 ;
int V_28 = - V_89 ;
V_97 = F_70 ( F_60 () , V_11 ) ;
if ( V_97 == NULL )
goto V_108;
V_28 = F_63 ( V_97 , V_43 , 0 , 0 , V_118 , 0 ) ;
if ( V_28 < 0 ) {
F_71 ( V_28 == - V_120 ) ;
F_72 ( V_97 ) ;
goto V_108;
}
F_73 ( V_97 , & V_18 , 0 , V_124 , NULL , V_11 ) ;
return;
V_108:
if ( V_28 < 0 )
F_74 ( & V_18 , V_124 , V_28 ) ;
}
static int F_75 ( struct V_96 * V_97 , struct V_125 * V_126 )
{
struct V_100 * V_100 = F_50 ( V_97 -> V_101 ) ;
int V_127 , V_128 = 0 , V_129 , V_130 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_42 * V_43 ;
if ( ! F_51 ( V_100 , & V_18 ) )
return 0 ;
V_129 = V_126 -> args [ 0 ] ;
V_130 = V_126 -> args [ 1 ] ;
V_127 = 0 ;
F_76 () ;
F_77 (&init_net, dev) {
if ( V_127 < V_129 )
goto V_131;
else if ( V_127 > V_129 ) {
V_130 = 0 ;
}
if ( ( V_27 = F_78 ( V_2 -> V_32 ) ) == NULL )
goto V_131;
for ( V_43 = F_78 ( V_27 -> V_55 ) , V_128 = 0 ; V_43 ;
V_43 = F_78 ( V_43 -> V_49 ) , V_128 ++ ) {
if ( V_128 < V_130 )
continue;
if ( F_63 ( V_97 , V_43 , F_79 ( V_126 -> V_97 ) . V_116 ,
V_126 -> V_99 -> V_132 , V_57 ,
V_133 ) < 0 )
goto V_83;
}
V_131:
V_127 ++ ;
}
V_83:
F_80 () ;
V_126 -> args [ 0 ] = V_127 ;
V_126 -> args [ 1 ] = V_128 ;
return V_97 -> V_134 ;
}
static int F_81 ( struct V_1 * V_2 , V_86 * V_135 )
{
struct V_26 * V_27 ;
struct V_42 * V_43 ;
int V_59 = - V_82 ;
F_76 () ;
V_27 = F_78 ( V_2 -> V_32 ) ;
if ( V_27 == NULL )
goto V_136;
V_43 = F_78 ( V_27 -> V_55 ) ;
if ( V_43 != NULL ) {
* V_135 = V_43 -> V_50 ;
V_59 = 0 ;
}
V_136:
F_80 () ;
return V_59 ;
}
int F_82 ( V_86 * V_135 )
{
struct V_1 * V_2 ;
int V_59 ;
V_2 = F_40 () ;
V_137:
if ( V_2 ) {
V_59 = F_81 ( V_2 , V_135 ) ;
F_45 ( V_2 ) ;
if ( V_59 == 0 || V_2 == V_18 . V_138 )
return V_59 ;
}
V_2 = V_18 . V_138 ;
F_42 ( V_2 ) ;
goto V_137;
}
static void F_83 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_139 * V_140 ;
struct V_96 * V_97 = NULL ;
V_86 * V_141 ;
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( ( V_97 = F_84 ( NULL , sizeof( * V_140 ) , V_142 ) ) == NULL )
return;
V_97 -> V_2 = V_2 ;
V_140 = (struct V_139 * ) F_85 ( V_97 , sizeof( * V_140 ) ) ;
V_140 -> V_143 = 0x0D ;
memcpy ( V_140 -> V_144 , V_145 , 3 ) ;
F_21 ( V_140 -> V_146 , V_43 -> V_50 ) ;
V_140 -> V_147 = V_148 ;
V_140 -> V_36 = F_86 ( F_12 ( V_2 ) ) ;
V_140 -> V_149 = 0x00 ;
memset ( V_140 -> V_150 , 0 , 8 ) ;
memcpy ( V_140 -> V_151 , V_152 , V_153 ) ;
if ( V_27 -> V_154 ) {
struct V_155 * V_156 = (struct V_155 * ) V_27 -> V_154 ;
F_21 ( V_140 -> V_151 , V_156 -> V_135 ) ;
}
V_140 -> V_157 = F_86 ( ( unsigned short ) V_27 -> V_4 . V_158 ) ;
V_140 -> V_159 = 0x00 ;
V_140 -> V_160 = 0x02 ;
memset ( V_140 -> V_14 , 0xAA , 2 ) ;
V_141 = ( V_86 * ) F_87 ( V_97 , 2 ) ;
* V_141 = F_86 ( V_97 -> V_134 - 2 ) ;
F_88 ( V_97 ) ;
F_89 ( V_97 , V_161 , V_140 -> V_146 ) ;
}
static int F_90 ( struct V_155 * V_156 , struct V_26 * V_27 , struct V_42 * V_43 )
{
if ( ( V_162 - V_27 -> V_163 ) < V_164 )
return 0 ;
if ( ! V_27 -> V_154 )
return 1 ;
if ( V_156 -> V_165 < V_27 -> V_4 . V_165 )
return 1 ;
if ( V_156 -> V_165 != V_27 -> V_4 . V_165 )
return 0 ;
if ( F_91 ( V_156 -> V_135 ) < F_91 ( V_43 -> V_50 ) )
return 1 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
int V_166 ;
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
struct V_155 * V_156 = (struct V_155 * ) V_27 -> V_154 ;
struct V_96 * V_97 ;
T_2 V_167 ;
unsigned char * V_168 ;
unsigned char * V_169 , * V_170 ;
V_86 * V_141 ;
char * V_171 ;
if ( F_12 ( V_2 ) < ( 26 + 7 ) )
return;
V_166 = F_12 ( V_2 ) - 26 ;
V_166 /= 7 ;
if ( V_166 > 32 )
V_166 = 32 ;
V_167 = 2 + 26 + 7 * V_166 ;
if ( ( V_97 = F_84 ( NULL , V_167 , V_142 ) ) == NULL )
return;
V_97 -> V_2 = V_2 ;
V_168 = F_85 ( V_97 , V_167 ) ;
* V_168 ++ = V_172 | V_173 ;
* V_168 ++ = 2 ;
* V_168 ++ = 0 ;
* V_168 ++ = 0 ;
F_21 ( V_168 , V_43 -> V_50 ) ;
V_171 = V_168 ;
V_168 += V_153 ;
* V_168 ++ = V_27 -> V_4 . V_33 == 1 ?
V_174 : V_175 ;
* ( ( V_86 * ) V_168 ) = F_86 ( F_12 ( V_2 ) ) ;
V_168 += 2 ;
* V_168 ++ = V_27 -> V_4 . V_165 ;
* V_168 ++ = 0 ;
* ( ( V_86 * ) V_168 ) = F_86 ( ( unsigned short ) V_27 -> V_4 . V_158 ) ;
V_168 += 2 ;
* V_168 ++ = 0 ;
V_169 = V_168 ++ ;
memset ( V_168 , 0 , 7 ) ;
V_168 += 7 ;
V_170 = V_168 ++ ;
V_166 = F_93 ( V_2 , V_168 , V_166 ) ;
* V_170 = 7 * V_166 ;
* V_169 = 8 + * V_170 ;
F_94 ( V_97 , ( 27 + * V_170 ) ) ;
V_141 = ( V_86 * ) F_87 ( V_97 , 2 ) ;
* V_141 = F_86 ( V_97 -> V_134 - 2 ) ;
F_88 ( V_97 ) ;
if ( F_90 ( V_156 , V_27 , V_43 ) ) {
struct V_96 * V_176 = F_95 ( V_97 , V_142 ) ;
if ( V_176 ) {
F_89 ( V_176 , V_177 , V_171 ) ;
}
}
F_89 ( V_97 , V_161 , V_171 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_83 ( V_2 , V_43 ) ;
else
F_92 ( V_2 , V_43 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
int V_178 = 16 ;
int V_167 = V_2 -> V_179 + 2 + 4 + V_178 ;
struct V_96 * V_97 = F_84 ( NULL , V_167 , V_142 ) ;
int V_7 ;
unsigned char * V_168 ;
char V_171 [ V_153 ] ;
if ( V_97 == NULL )
return ;
V_97 -> V_2 = V_2 ;
F_87 ( V_97 , V_2 -> V_179 ) ;
V_168 = F_85 ( V_97 , 2 + 4 + V_178 ) ;
* V_168 ++ = V_180 ;
* ( ( V_86 * ) V_168 ) = V_43 -> V_50 ;
V_168 += 2 ;
* V_168 ++ = V_178 ;
for( V_7 = 0 ; V_7 < V_178 ; V_7 ++ )
* V_168 ++ = 0252 ;
F_21 ( V_171 , V_43 -> V_50 ) ;
F_89 ( V_97 , V_161 , V_171 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_27 ( V_2 , V_177 ) ;
else
F_27 ( V_2 , V_161 ) ;
V_27 -> V_181 = 1 ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_33 == 0 )
F_22 ( V_2 , V_177 ) ;
else
F_22 ( V_2 , V_161 ) ;
}
static void F_100 ( unsigned long V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
struct V_26 * V_27 ;
struct V_42 * V_43 ;
F_76 () ;
V_27 = F_78 ( V_2 -> V_32 ) ;
if ( V_27 -> V_158 <= V_27 -> V_4 . V_182 ) {
if ( V_27 -> V_4 . V_183 ) {
for ( V_43 = F_78 ( V_27 -> V_55 ) ;
V_43 ;
V_43 = F_78 ( V_43 -> V_49 ) ) {
if ( ! ( V_43 -> V_114 & V_184 ) )
V_27 -> V_4 . V_183 ( V_2 , V_43 ) ;
}
}
V_27 -> V_158 = V_27 -> V_4 . V_158 ;
} else {
V_27 -> V_158 -= V_27 -> V_4 . V_182 ;
}
F_80 () ;
F_101 ( V_2 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_10 ( V_2 -> V_32 ) ;
if ( V_27 -> V_4 . V_182 > V_27 -> V_4 . V_158 )
V_27 -> V_4 . V_182 = V_27 -> V_4 . V_158 ;
V_27 -> V_157 . V_14 = ( unsigned long ) V_2 ;
V_27 -> V_157 . V_185 = F_100 ;
V_27 -> V_157 . V_186 = V_162 + ( V_27 -> V_4 . V_182 * V_187 ) ;
F_102 ( & V_27 -> V_157 ) ;
}
static struct V_26 * F_30 ( struct V_1 * V_2 , int * V_28 )
{
int V_7 ;
struct V_3 * V_188 = V_189 ;
struct V_26 * V_27 ;
for( V_7 = 0 ; V_7 < V_190 ; V_7 ++ , V_188 ++ ) {
if ( V_188 -> type == V_2 -> type )
break;
}
* V_28 = - V_82 ;
if ( V_7 == V_190 )
return NULL ;
* V_28 = - V_89 ;
if ( ( V_27 = F_14 ( sizeof( struct V_26 ) , V_142 ) ) == NULL )
return NULL ;
memcpy ( & V_27 -> V_4 , V_188 , sizeof( struct V_3 ) ) ;
F_28 ( V_2 -> V_32 , V_27 ) ;
V_27 -> V_2 = V_2 ;
F_103 ( & V_27 -> V_157 ) ;
V_27 -> V_163 = V_162 ;
V_27 -> V_191 = F_104 ( V_2 , & V_192 ) ;
if ( ! V_27 -> V_191 ) {
F_105 ( V_2 -> V_32 , NULL ) ;
F_5 ( V_27 ) ;
return NULL ;
}
if ( V_27 -> V_4 . V_35 ) {
if ( V_27 -> V_4 . V_35 ( V_2 ) < 0 ) {
F_106 ( & V_192 , V_27 -> V_191 ) ;
V_2 -> V_32 = NULL ;
F_5 ( V_27 ) ;
return NULL ;
}
}
F_1 ( V_2 , & V_27 -> V_4 ) ;
F_101 ( V_2 ) ;
* V_28 = 0 ;
return V_27 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_86 V_135 = V_193 ;
int V_194 = 0 ;
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
if ( memcmp ( V_2 -> V_51 , V_152 , 4 ) != 0 )
return;
V_135 = F_20 ( V_2 -> V_51 ) ;
V_194 = 1 ;
}
if ( V_135 == 0 )
return;
if ( ( V_43 = F_13 () ) == NULL )
return;
V_43 -> V_50 = V_43 -> V_90 = V_135 ;
V_43 -> V_114 = 0 ;
V_43 -> V_63 = V_195 ;
strcpy ( V_43 -> V_84 , V_2 -> V_15 ) ;
F_29 ( V_2 , V_43 ) ;
if ( V_194 ) {
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
F_108 ( & V_27 -> V_157 ) ;
F_6 ( & V_27 -> V_4 ) ;
F_46 ( V_2 ) ;
F_109 ( & V_192 , V_2 ) ;
if ( V_27 -> V_4 . V_34 )
V_27 -> V_4 . V_34 ( V_2 ) ;
V_2 -> V_32 = NULL ;
F_106 ( & V_192 , V_27 -> V_191 ) ;
F_109 ( & V_192 , V_2 ) ;
if ( V_27 -> V_154 )
F_110 ( V_27 -> V_154 ) ;
if ( V_27 -> V_196 )
F_110 ( V_27 -> V_196 ) ;
F_5 ( V_27 ) ;
}
void F_111 ( struct V_1 * V_2 )
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
void F_112 ( struct V_96 * V_97 )
{
}
void F_113 ( struct V_96 * V_97 )
{
}
void F_114 ( struct V_96 * V_97 )
{
}
void F_115 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_116 (&init_net, dev)
F_111 ( V_2 ) ;
F_38 () ;
}
void F_117 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_116 (&init_net, dev) {
if ( V_2 -> V_61 & V_197 )
F_107 ( V_2 ) ;
}
F_38 () ;
}
int F_118 ( struct V_198 * V_199 )
{
return F_119 ( & V_53 , V_199 ) ;
}
int F_120 ( struct V_198 * V_199 )
{
return F_121 ( & V_53 , V_199 ) ;
}
static inline int F_122 ( struct V_1 * V_2 )
{
return V_2 -> V_32 != NULL ;
}
static void * F_123 ( struct V_200 * V_117 , T_3 * V_201 )
__acquires( T_7 )
{
int V_7 ;
struct V_1 * V_2 ;
F_76 () ;
if ( * V_201 == 0 )
return V_202 ;
V_7 = 1 ;
F_77 (&init_net, dev) {
if ( ! F_122 ( V_2 ) )
continue;
if ( V_7 ++ == * V_201 )
return V_2 ;
}
return NULL ;
}
static void * F_124 ( struct V_200 * V_117 , void * V_203 , T_3 * V_201 )
{
struct V_1 * V_2 ;
++ * V_201 ;
V_2 = V_203 ;
if ( V_203 == V_202 )
V_2 = F_125 ( & V_18 . V_204 ) ;
F_126 (&init_net, dev) {
if ( ! F_122 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static void F_127 ( struct V_200 * V_117 , void * V_203 )
__releases( T_7 )
{
F_80 () ;
}
static char * F_128 ( char type )
{
switch ( type ) {
case V_205 :
return L_3 ;
case V_206 :
return L_4 ;
case V_207 :
return L_5 ;
}
return L_6 ;
}
static int F_129 ( struct V_200 * V_117 , void * V_203 )
{
if ( V_203 == V_202 )
F_130 ( V_117 , L_7 ) ;
else {
struct V_1 * V_2 = V_203 ;
char V_208 [ V_209 ] ;
char V_210 [ V_209 ] ;
struct V_26 * V_27 = F_78 ( V_2 -> V_32 ) ;
F_131 ( V_117 , L_8
L_9 ,
V_2 -> V_15 ? V_2 -> V_15 : L_10 ,
F_128 ( V_27 -> V_4 . V_211 ) ,
0 , 0 ,
V_27 -> V_158 , V_27 -> V_4 . V_158 ,
F_12 ( V_2 ) ,
V_27 -> V_4 . V_165 ,
V_27 -> V_4 . V_212 , V_27 -> V_4 . V_15 ,
V_27 -> V_154 ? F_132 ( F_91 ( * ( V_86 * ) V_27 -> V_154 -> V_213 ) , V_210 ) : L_11 ,
V_27 -> V_196 ? F_132 ( F_91 ( * ( V_86 * ) V_27 -> V_196 -> V_213 ) , V_208 ) : L_11 ) ;
}
return 0 ;
}
static int F_133 ( struct V_214 * V_214 , struct V_215 * V_215 )
{
return F_134 ( V_215 , & V_216 ) ;
}
void T_8 F_135 ( void )
{
if ( V_135 [ 0 ] > 63 || V_135 [ 0 ] < 0 ) {
F_136 ( V_217 L_12 ) ;
return;
}
if ( V_135 [ 1 ] > 1023 || V_135 [ 1 ] < 0 ) {
F_136 ( V_217 L_13 ) ;
return;
}
V_193 = F_86 ( ( V_135 [ 0 ] << 10 ) | V_135 [ 1 ] ) ;
F_117 () ;
F_137 ( V_218 , V_57 , F_56 , NULL , NULL ) ;
F_137 ( V_218 , V_52 , F_49 , NULL , NULL ) ;
F_137 ( V_218 , V_219 , NULL , F_75 , NULL ) ;
F_138 ( L_14 , V_220 , V_18 . V_221 , & V_222 ) ;
#ifdef F_139
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_190 ; V_7 ++ )
F_1 ( NULL , & V_189 [ V_7 ] ) ;
}
#endif
}
void T_9 F_140 ( void )
{
#ifdef F_139
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_190 ; V_7 ++ )
F_6 ( & V_189 [ V_7 ] ) ;
}
#endif
F_141 ( L_14 , V_18 . V_221 ) ;
F_115 () ;
}
