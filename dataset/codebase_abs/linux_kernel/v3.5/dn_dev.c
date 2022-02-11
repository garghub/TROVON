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
static int F_8 ( T_1 * V_20 , int V_21 ,
void T_2 * V_22 ,
T_3 * V_23 , T_4 * V_24 )
{
#ifdef F_9
struct V_1 * V_2 = V_20 -> V_16 ;
struct V_25 * V_26 ;
int V_27 ;
int V_28 , V_29 ;
if ( V_20 -> V_16 == NULL )
return - V_30 ;
V_26 = F_10 ( V_2 -> V_31 ) ;
V_29 = V_26 -> V_4 . V_32 ;
V_27 = F_11 ( V_20 , V_21 , V_22 , V_23 , V_24 ) ;
if ( ( V_27 >= 0 ) && V_21 ) {
if ( V_26 -> V_4 . V_32 < 0 )
V_26 -> V_4 . V_32 = 0 ;
if ( V_26 -> V_4 . V_32 > 2 )
V_26 -> V_4 . V_32 = 2 ;
V_28 = V_26 -> V_4 . V_32 ;
V_26 -> V_4 . V_32 = V_29 ;
if ( V_26 -> V_4 . V_33 )
V_26 -> V_4 . V_33 ( V_2 ) ;
V_26 -> V_4 . V_32 = V_28 ;
if ( V_26 -> V_4 . V_34 )
V_26 -> V_4 . V_34 ( V_2 ) ;
}
return V_27 ;
#else
return - V_30 ;
#endif
}
static void F_6 ( struct V_3 * V_4 )
{
}
static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static inline T_5 F_12 ( struct V_1 * V_2 )
{
T_6 V_35 = V_2 -> V_36 ;
if ( V_35 > 0xffff )
V_35 = 0xffff ;
if ( V_2 -> type == V_37 ||
V_2 -> type == V_38 ||
V_2 -> type == V_39 ||
V_2 -> type == V_40 )
V_35 -= 2 ;
return ( T_5 ) V_35 ;
}
static struct V_41 * F_13 ( void )
{
struct V_41 * V_42 ;
V_42 = F_14 ( sizeof( * V_42 ) , V_11 ) ;
return V_42 ;
}
static void F_15 ( struct V_41 * V_42 )
{
F_16 ( V_42 , V_43 ) ;
}
static void F_17 ( struct V_25 * V_26 , struct V_41 T_7 * * V_44 , int V_45 )
{
struct V_41 * V_46 = F_18 ( * V_44 ) ;
unsigned char V_47 [ 6 ] ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_19 () ;
* V_44 = V_46 -> V_48 ;
if ( V_26 -> V_2 -> type == V_37 ) {
if ( V_46 -> V_49 != F_20 ( V_2 -> V_50 ) ) {
F_21 ( V_47 , V_46 -> V_49 ) ;
F_22 ( V_2 , V_47 ) ;
}
}
F_23 ( V_51 , V_46 ) ;
F_24 ( & V_52 , V_53 , V_46 ) ;
if ( V_45 ) {
F_15 ( V_46 ) ;
if ( V_26 -> V_54 == NULL )
F_25 ( V_26 -> V_2 ) ;
}
}
static int F_26 ( struct V_25 * V_26 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_41 * V_46 ;
unsigned char V_47 [ 6 ] ;
F_19 () ;
for ( V_46 = F_18 ( V_26 -> V_54 ) ;
V_46 != NULL ;
V_46 = F_18 ( V_46 -> V_48 ) ) {
if ( V_46 -> V_49 == V_42 -> V_49 )
return - V_55 ;
}
if ( V_2 -> type == V_37 ) {
if ( V_42 -> V_49 != F_20 ( V_2 -> V_50 ) ) {
F_21 ( V_47 , V_42 -> V_49 ) ;
F_27 ( V_2 , V_47 ) ;
}
}
V_42 -> V_48 = V_26 -> V_54 ;
F_28 ( V_26 -> V_54 , V_42 ) ;
F_23 ( V_56 , V_42 ) ;
F_24 ( & V_52 , V_57 , V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_25 * V_26 = F_18 ( V_2 -> V_31 ) ;
int V_58 ;
if ( V_26 == NULL ) {
int V_27 ;
V_26 = F_30 ( V_2 , & V_27 ) ;
if ( V_26 == NULL )
return V_27 ;
}
V_42 -> V_59 = V_26 ;
if ( V_2 -> V_60 & V_61 )
V_42 -> V_62 = V_63 ;
V_58 = F_26 ( V_26 , V_42 ) ;
if ( V_58 )
F_15 ( V_42 ) ;
return V_58 ;
}
int F_31 ( unsigned int V_64 , void T_2 * V_65 )
{
char V_22 [ V_66 ] ;
struct V_67 * V_68 = (struct V_67 * ) V_22 ;
struct V_69 * V_70 = (struct V_69 * ) & V_68 -> V_71 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_41 * V_42 = NULL ;
struct V_41 T_7 * * V_44 = NULL ;
int V_72 = 0 ;
if ( F_32 ( V_68 , V_65 , V_66 ) )
return - V_73 ;
V_68 -> V_74 [ V_9 - 1 ] = 0 ;
F_33 ( & V_18 , V_68 -> V_74 ) ;
switch ( V_64 ) {
case V_75 :
break;
case V_76 :
if ( ! F_34 ( V_77 ) )
return - V_78 ;
if ( V_70 -> V_79 != V_80 )
return - V_30 ;
break;
default:
return - V_30 ;
}
F_35 () ;
if ( ( V_2 = F_36 ( & V_18 , V_68 -> V_74 ) ) == NULL ) {
V_72 = - V_81 ;
goto V_82;
}
if ( ( V_26 = F_18 ( V_2 -> V_31 ) ) != NULL ) {
for ( V_44 = & V_26 -> V_54 ;
( V_42 = F_18 ( * V_44 ) ) != NULL ;
V_44 = & V_42 -> V_48 )
if ( strcmp ( V_68 -> V_74 , V_42 -> V_83 ) == 0 )
break;
}
if ( V_42 == NULL && V_64 != V_76 ) {
V_72 = - V_84 ;
goto V_82;
}
switch ( V_64 ) {
case V_75 :
* ( ( V_85 * ) V_70 -> V_86 ) = V_42 -> V_49 ;
goto V_87;
case V_76 :
if ( ! V_42 ) {
if ( ( V_42 = F_13 () ) == NULL ) {
V_72 = - V_88 ;
break;
}
memcpy ( V_42 -> V_83 , V_2 -> V_15 , V_9 ) ;
} else {
if ( V_42 -> V_49 == F_37 ( V_70 ) )
break;
F_17 ( V_26 , V_44 , 0 ) ;
}
V_42 -> V_49 = V_42 -> V_89 = F_37 ( V_70 ) ;
V_72 = F_29 ( V_2 , V_42 ) ;
}
V_82:
F_38 () ;
return V_72 ;
V_87:
if ( F_39 ( V_65 , V_68 , V_66 ) )
V_72 = - V_73 ;
goto V_82;
}
struct V_1 * F_40 ( void )
{
struct V_1 * V_2 ;
F_41 ( & V_90 ) ;
V_2 = V_91 ;
if ( V_2 ) {
if ( V_2 -> V_31 )
F_42 ( V_2 ) ;
else
V_2 = NULL ;
}
F_43 ( & V_90 ) ;
return V_2 ;
}
int F_44 ( struct V_1 * V_2 , int V_92 )
{
struct V_1 * V_29 = NULL ;
int V_58 = - V_93 ;
if ( ! V_2 -> V_31 )
return - V_81 ;
F_41 ( & V_90 ) ;
if ( V_92 || V_91 == NULL ) {
V_29 = V_91 ;
V_91 = V_2 ;
V_58 = 0 ;
}
F_43 ( & V_90 ) ;
if ( V_29 )
F_45 ( V_29 ) ;
return V_58 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_41 ( & V_90 ) ;
if ( V_2 == V_91 ) {
V_91 = NULL ;
} else {
V_2 = NULL ;
}
F_43 ( & V_90 ) ;
if ( V_2 )
F_45 ( V_2 ) ;
}
static struct V_25 * F_47 ( int V_94 )
{
struct V_1 * V_2 ;
struct V_25 * V_25 = NULL ;
V_2 = F_48 ( & V_18 , V_94 ) ;
if ( V_2 )
V_25 = F_18 ( V_2 -> V_31 ) ;
return V_25 ;
}
static int F_49 ( struct V_95 * V_96 , struct V_97 * V_98 , void * V_65 )
{
struct V_99 * V_99 = F_50 ( V_96 -> V_100 ) ;
struct V_101 * V_102 [ V_103 + 1 ] ;
struct V_25 * V_26 ;
struct V_104 * V_105 ;
struct V_41 * V_42 ;
struct V_41 T_7 * * V_44 ;
int V_27 = - V_30 ;
if ( ! F_51 ( V_99 , & V_18 ) )
goto V_106;
V_27 = F_52 ( V_98 , sizeof( * V_105 ) , V_102 , V_103 , V_107 ) ;
if ( V_27 < 0 )
goto V_106;
V_27 = - V_81 ;
V_105 = F_53 ( V_98 ) ;
if ( ( V_26 = F_47 ( V_105 -> V_108 ) ) == NULL )
goto V_106;
V_27 = - V_84 ;
for ( V_44 = & V_26 -> V_54 ;
( V_42 = F_18 ( * V_44 ) ) != NULL ;
V_44 = & V_42 -> V_48 ) {
if ( V_102 [ V_109 ] &&
F_54 ( V_102 [ V_109 ] , & V_42 -> V_49 , 2 ) )
continue;
if ( V_102 [ V_110 ] && F_55 ( V_102 [ V_110 ] , V_42 -> V_83 ) )
continue;
F_17 ( V_26 , V_44 , 1 ) ;
return 0 ;
}
V_106:
return V_27 ;
}
static int F_56 ( struct V_95 * V_96 , struct V_97 * V_98 , void * V_65 )
{
struct V_99 * V_99 = F_50 ( V_96 -> V_100 ) ;
struct V_101 * V_102 [ V_103 + 1 ] ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_104 * V_105 ;
struct V_41 * V_42 ;
int V_27 ;
if ( ! F_51 ( V_99 , & V_18 ) )
return - V_30 ;
V_27 = F_52 ( V_98 , sizeof( * V_105 ) , V_102 , V_103 , V_107 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_102 [ V_109 ] == NULL )
return - V_30 ;
V_105 = F_53 ( V_98 ) ;
if ( ( V_2 = F_48 ( & V_18 , V_105 -> V_108 ) ) == NULL )
return - V_81 ;
if ( ( V_26 = F_18 ( V_2 -> V_31 ) ) == NULL ) {
V_26 = F_30 ( V_2 , & V_27 ) ;
if ( ! V_26 )
return V_27 ;
}
if ( ( V_42 = F_13 () ) == NULL )
return - V_88 ;
if ( V_102 [ V_111 ] == NULL )
V_102 [ V_111 ] = V_102 [ V_109 ] ;
V_42 -> V_49 = F_57 ( V_102 [ V_109 ] ) ;
V_42 -> V_89 = F_57 ( V_102 [ V_111 ] ) ;
V_42 -> V_112 = V_105 -> V_112 ;
V_42 -> V_62 = V_105 -> V_62 ;
V_42 -> V_59 = V_26 ;
if ( V_102 [ V_110 ] )
F_58 ( V_42 -> V_83 , V_102 [ V_110 ] , V_9 ) ;
else
memcpy ( V_42 -> V_83 , V_2 -> V_15 , V_9 ) ;
V_27 = F_26 ( V_26 , V_42 ) ;
if ( V_27 )
F_15 ( V_42 ) ;
return V_27 ;
}
static inline T_3 F_59 ( void )
{
return F_60 ( sizeof( struct V_104 ) )
+ F_61 ( V_9 )
+ F_61 ( 2 )
+ F_61 ( 2 ) ;
}
static int F_62 ( struct V_95 * V_96 , struct V_41 * V_42 ,
T_6 V_113 , T_6 V_114 , int V_115 , unsigned int V_60 )
{
struct V_104 * V_105 ;
struct V_97 * V_98 ;
V_98 = F_63 ( V_96 , V_113 , V_114 , V_115 , sizeof( * V_105 ) , V_60 ) ;
if ( V_98 == NULL )
return - V_116 ;
V_105 = F_53 ( V_98 ) ;
V_105 -> V_117 = V_80 ;
V_105 -> V_118 = 16 ;
V_105 -> V_112 = V_42 -> V_112 | V_119 ;
V_105 -> V_62 = V_42 -> V_62 ;
V_105 -> V_108 = V_42 -> V_59 -> V_2 -> V_94 ;
if ( ( V_42 -> V_89 &&
F_64 ( V_96 , V_111 , V_42 -> V_89 ) ) ||
( V_42 -> V_49 &&
F_64 ( V_96 , V_109 , V_42 -> V_49 ) ) ||
( V_42 -> V_83 [ 0 ] &&
F_65 ( V_96 , V_110 , V_42 -> V_83 ) ) )
goto V_120;
return F_66 ( V_96 , V_98 ) ;
V_120:
F_67 ( V_96 , V_98 ) ;
return - V_116 ;
}
static void F_23 ( int V_115 , struct V_41 * V_42 )
{
struct V_95 * V_96 ;
int V_27 = - V_88 ;
V_96 = F_68 ( F_59 () , V_11 ) ;
if ( V_96 == NULL )
goto V_106;
V_27 = F_62 ( V_96 , V_42 , 0 , 0 , V_115 , 0 ) ;
if ( V_27 < 0 ) {
F_69 ( V_27 == - V_116 ) ;
F_70 ( V_96 ) ;
goto V_106;
}
F_71 ( V_96 , & V_18 , 0 , V_121 , NULL , V_11 ) ;
return;
V_106:
if ( V_27 < 0 )
F_72 ( & V_18 , V_121 , V_27 ) ;
}
static int F_73 ( struct V_95 * V_96 , struct V_122 * V_123 )
{
struct V_99 * V_99 = F_50 ( V_96 -> V_100 ) ;
int V_124 , V_125 = 0 , V_126 , V_127 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
if ( ! F_51 ( V_99 , & V_18 ) )
return 0 ;
V_126 = V_123 -> args [ 0 ] ;
V_127 = V_123 -> args [ 1 ] ;
V_124 = 0 ;
F_74 () ;
F_75 (&init_net, dev) {
if ( V_124 < V_126 )
goto V_128;
else if ( V_124 > V_126 ) {
V_127 = 0 ;
}
if ( ( V_26 = F_76 ( V_2 -> V_31 ) ) == NULL )
goto V_128;
for ( V_42 = F_76 ( V_26 -> V_54 ) , V_125 = 0 ; V_42 ;
V_42 = F_76 ( V_42 -> V_48 ) , V_125 ++ ) {
if ( V_125 < V_127 )
continue;
if ( F_62 ( V_96 , V_42 , F_77 ( V_123 -> V_96 ) . V_113 ,
V_123 -> V_98 -> V_129 , V_56 ,
V_130 ) < 0 )
goto V_82;
}
V_128:
V_124 ++ ;
}
V_82:
F_78 () ;
V_123 -> args [ 0 ] = V_124 ;
V_123 -> args [ 1 ] = V_125 ;
return V_96 -> V_131 ;
}
static int F_79 ( struct V_1 * V_2 , V_85 * V_132 )
{
struct V_25 * V_26 ;
struct V_41 * V_42 ;
int V_58 = - V_81 ;
F_74 () ;
V_26 = F_76 ( V_2 -> V_31 ) ;
if ( V_26 == NULL )
goto V_133;
V_42 = F_76 ( V_26 -> V_54 ) ;
if ( V_42 != NULL ) {
* V_132 = V_42 -> V_49 ;
V_58 = 0 ;
}
V_133:
F_78 () ;
return V_58 ;
}
int F_80 ( V_85 * V_132 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_40 () ;
V_134:
if ( V_2 ) {
V_58 = F_79 ( V_2 , V_132 ) ;
F_45 ( V_2 ) ;
if ( V_58 == 0 || V_2 == V_18 . V_135 )
return V_58 ;
}
V_2 = V_18 . V_135 ;
F_42 ( V_2 ) ;
goto V_134;
}
static void F_81 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_136 * V_137 ;
struct V_95 * V_96 = NULL ;
V_85 * V_138 ;
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( ( V_96 = F_82 ( NULL , sizeof( * V_137 ) , V_139 ) ) == NULL )
return;
V_96 -> V_2 = V_2 ;
V_137 = (struct V_136 * ) F_83 ( V_96 , sizeof( * V_137 ) ) ;
V_137 -> V_140 = 0x0D ;
memcpy ( V_137 -> V_141 , V_142 , 3 ) ;
F_21 ( V_137 -> V_143 , V_42 -> V_49 ) ;
V_137 -> V_144 = V_145 ;
V_137 -> V_35 = F_84 ( F_12 ( V_2 ) ) ;
V_137 -> V_146 = 0x00 ;
memset ( V_137 -> V_147 , 0 , 8 ) ;
memcpy ( V_137 -> V_148 , V_149 , V_150 ) ;
if ( V_26 -> V_151 ) {
struct V_152 * V_153 = (struct V_152 * ) V_26 -> V_151 ;
F_21 ( V_137 -> V_148 , V_153 -> V_132 ) ;
}
V_137 -> V_154 = F_84 ( ( unsigned short ) V_26 -> V_4 . V_155 ) ;
V_137 -> V_156 = 0x00 ;
V_137 -> V_157 = 0x02 ;
memset ( V_137 -> V_14 , 0xAA , 2 ) ;
V_138 = ( V_85 * ) F_85 ( V_96 , 2 ) ;
* V_138 = F_84 ( V_96 -> V_131 - 2 ) ;
F_86 ( V_96 ) ;
F_87 ( V_96 , V_158 , V_137 -> V_143 ) ;
}
static int F_88 ( struct V_152 * V_153 , struct V_25 * V_26 , struct V_41 * V_42 )
{
if ( ( V_159 - V_26 -> V_160 ) < V_161 )
return 0 ;
if ( ! V_26 -> V_151 )
return 1 ;
if ( V_153 -> V_162 < V_26 -> V_4 . V_162 )
return 1 ;
if ( V_153 -> V_162 != V_26 -> V_4 . V_162 )
return 0 ;
if ( F_89 ( V_153 -> V_132 ) < F_89 ( V_42 -> V_49 ) )
return 1 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_163 ;
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
struct V_152 * V_153 = (struct V_152 * ) V_26 -> V_151 ;
struct V_95 * V_96 ;
T_3 V_164 ;
unsigned char * V_165 ;
unsigned char * V_166 , * V_167 ;
V_85 * V_138 ;
char * V_168 ;
if ( F_12 ( V_2 ) < ( 26 + 7 ) )
return;
V_163 = F_12 ( V_2 ) - 26 ;
V_163 /= 7 ;
if ( V_163 > 32 )
V_163 = 32 ;
V_164 = 2 + 26 + 7 * V_163 ;
if ( ( V_96 = F_82 ( NULL , V_164 , V_139 ) ) == NULL )
return;
V_96 -> V_2 = V_2 ;
V_165 = F_83 ( V_96 , V_164 ) ;
* V_165 ++ = V_169 | V_170 ;
* V_165 ++ = 2 ;
* V_165 ++ = 0 ;
* V_165 ++ = 0 ;
F_21 ( V_165 , V_42 -> V_49 ) ;
V_168 = V_165 ;
V_165 += V_150 ;
* V_165 ++ = V_26 -> V_4 . V_32 == 1 ?
V_171 : V_172 ;
* ( ( V_85 * ) V_165 ) = F_84 ( F_12 ( V_2 ) ) ;
V_165 += 2 ;
* V_165 ++ = V_26 -> V_4 . V_162 ;
* V_165 ++ = 0 ;
* ( ( V_85 * ) V_165 ) = F_84 ( ( unsigned short ) V_26 -> V_4 . V_155 ) ;
V_165 += 2 ;
* V_165 ++ = 0 ;
V_166 = V_165 ++ ;
memset ( V_165 , 0 , 7 ) ;
V_165 += 7 ;
V_167 = V_165 ++ ;
V_163 = F_91 ( V_2 , V_165 , V_163 ) ;
* V_167 = 7 * V_163 ;
* V_166 = 8 + * V_167 ;
F_92 ( V_96 , ( 27 + * V_167 ) ) ;
V_138 = ( V_85 * ) F_85 ( V_96 , 2 ) ;
* V_138 = F_84 ( V_96 -> V_131 - 2 ) ;
F_86 ( V_96 ) ;
if ( F_88 ( V_153 , V_26 , V_42 ) ) {
struct V_95 * V_173 = F_93 ( V_96 , V_139 ) ;
if ( V_173 ) {
F_87 ( V_173 , V_174 , V_168 ) ;
}
}
F_87 ( V_96 , V_158 , V_168 ) ;
}
static void F_94 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_81 ( V_2 , V_42 ) ;
else
F_90 ( V_2 , V_42 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_175 = 16 ;
int V_164 = V_2 -> V_176 + 2 + 4 + V_175 ;
struct V_95 * V_96 = F_82 ( NULL , V_164 , V_139 ) ;
int V_7 ;
unsigned char * V_165 ;
char V_168 [ V_150 ] ;
if ( V_96 == NULL )
return ;
V_96 -> V_2 = V_2 ;
F_85 ( V_96 , V_2 -> V_176 ) ;
V_165 = F_83 ( V_96 , 2 + 4 + V_175 ) ;
* V_165 ++ = V_177 ;
* ( ( V_85 * ) V_165 ) = V_42 -> V_49 ;
V_165 += 2 ;
* V_165 ++ = V_175 ;
for( V_7 = 0 ; V_7 < V_175 ; V_7 ++ )
* V_165 ++ = 0252 ;
F_21 ( V_168 , V_42 -> V_49 ) ;
F_87 ( V_96 , V_158 , V_168 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_27 ( V_2 , V_174 ) ;
else
F_27 ( V_2 , V_158 ) ;
V_26 -> V_178 = 1 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_22 ( V_2 , V_174 ) ;
else
F_22 ( V_2 , V_158 ) ;
}
static void F_98 ( unsigned long V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
F_74 () ;
V_26 = F_76 ( V_2 -> V_31 ) ;
if ( V_26 -> V_155 <= V_26 -> V_4 . V_179 ) {
if ( V_26 -> V_4 . V_180 ) {
for ( V_42 = F_76 ( V_26 -> V_54 ) ;
V_42 ;
V_42 = F_76 ( V_42 -> V_48 ) ) {
if ( ! ( V_42 -> V_112 & V_181 ) )
V_26 -> V_4 . V_180 ( V_2 , V_42 ) ;
}
}
V_26 -> V_155 = V_26 -> V_4 . V_155 ;
} else {
V_26 -> V_155 -= V_26 -> V_4 . V_179 ;
}
F_78 () ;
F_99 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_179 > V_26 -> V_4 . V_155 )
V_26 -> V_4 . V_179 = V_26 -> V_4 . V_155 ;
V_26 -> V_154 . V_14 = ( unsigned long ) V_2 ;
V_26 -> V_154 . V_182 = F_98 ;
V_26 -> V_154 . V_183 = V_159 + ( V_26 -> V_4 . V_179 * V_184 ) ;
F_100 ( & V_26 -> V_154 ) ;
}
static struct V_25 * F_30 ( struct V_1 * V_2 , int * V_27 )
{
int V_7 ;
struct V_3 * V_185 = V_186 ;
struct V_25 * V_26 ;
for( V_7 = 0 ; V_7 < V_187 ; V_7 ++ , V_185 ++ ) {
if ( V_185 -> type == V_2 -> type )
break;
}
* V_27 = - V_81 ;
if ( V_7 == V_187 )
return NULL ;
* V_27 = - V_88 ;
if ( ( V_26 = F_14 ( sizeof( struct V_25 ) , V_139 ) ) == NULL )
return NULL ;
memcpy ( & V_26 -> V_4 , V_185 , sizeof( struct V_3 ) ) ;
F_28 ( V_2 -> V_31 , V_26 ) ;
V_26 -> V_2 = V_2 ;
F_101 ( & V_26 -> V_154 ) ;
V_26 -> V_160 = V_159 ;
V_26 -> V_188 = F_102 ( V_2 , & V_189 ) ;
if ( ! V_26 -> V_188 ) {
F_103 ( V_2 -> V_31 , NULL ) ;
F_5 ( V_26 ) ;
return NULL ;
}
if ( V_26 -> V_4 . V_34 ) {
if ( V_26 -> V_4 . V_34 ( V_2 ) < 0 ) {
F_104 ( & V_189 , V_26 -> V_188 ) ;
V_2 -> V_31 = NULL ;
F_5 ( V_26 ) ;
return NULL ;
}
}
F_1 ( V_2 , & V_26 -> V_4 ) ;
F_99 ( V_2 ) ;
* V_27 = 0 ;
return V_26 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
V_85 V_132 = V_190 ;
int V_191 = 0 ;
struct V_25 * V_26 = F_18 ( V_2 -> V_31 ) ;
if ( ( V_2 -> type != V_37 ) && ( V_2 -> type != V_40 ) )
return;
if ( V_26 == NULL ) {
int V_27 ;
V_26 = F_30 ( V_2 , & V_27 ) ;
if ( V_26 == NULL )
return;
}
if ( V_2 -> type == V_37 ) {
if ( memcmp ( V_2 -> V_50 , V_149 , 4 ) != 0 )
return;
V_132 = F_20 ( V_2 -> V_50 ) ;
V_191 = 1 ;
}
if ( V_132 == 0 )
return;
if ( ( V_42 = F_13 () ) == NULL )
return;
V_42 -> V_49 = V_42 -> V_89 = V_132 ;
V_42 -> V_112 = 0 ;
V_42 -> V_62 = V_192 ;
strcpy ( V_42 -> V_83 , V_2 -> V_15 ) ;
F_29 ( V_2 , V_42 ) ;
if ( V_191 ) {
F_42 ( V_2 ) ;
if ( F_44 ( V_2 , 0 ) )
F_45 ( V_2 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_18 ( V_2 -> V_31 ) ;
if ( V_26 == NULL )
return;
F_106 ( & V_26 -> V_154 ) ;
F_6 ( & V_26 -> V_4 ) ;
F_46 ( V_2 ) ;
F_107 ( & V_189 , V_2 ) ;
if ( V_26 -> V_4 . V_33 )
V_26 -> V_4 . V_33 ( V_2 ) ;
V_2 -> V_31 = NULL ;
F_104 ( & V_189 , V_26 -> V_188 ) ;
F_107 ( & V_189 , V_2 ) ;
if ( V_26 -> V_151 )
F_108 ( V_26 -> V_151 ) ;
if ( V_26 -> V_193 )
F_108 ( V_26 -> V_193 ) ;
F_5 ( V_26 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_18 ( V_2 -> V_31 ) ;
struct V_41 * V_42 ;
if ( V_26 == NULL )
return;
while ( ( V_42 = F_18 ( V_26 -> V_54 ) ) != NULL ) {
F_17 ( V_26 , & V_26 -> V_54 , 0 ) ;
F_15 ( V_42 ) ;
}
F_25 ( V_2 ) ;
}
void F_110 ( struct V_95 * V_96 )
{
}
void F_111 ( struct V_95 * V_96 )
{
}
void F_112 ( struct V_95 * V_96 )
{
}
void F_113 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_114 (&init_net, dev)
F_109 ( V_2 ) ;
F_38 () ;
}
void F_115 ( void )
{
struct V_1 * V_2 ;
F_35 () ;
F_114 (&init_net, dev) {
if ( V_2 -> V_60 & V_194 )
F_105 ( V_2 ) ;
}
F_38 () ;
}
int F_116 ( struct V_195 * V_196 )
{
return F_117 ( & V_52 , V_196 ) ;
}
int F_118 ( struct V_195 * V_196 )
{
return F_119 ( & V_52 , V_196 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
return V_2 -> V_31 != NULL ;
}
static void * F_121 ( struct V_197 * V_114 , T_4 * V_198 )
__acquires( T_8 )
{
int V_7 ;
struct V_1 * V_2 ;
F_74 () ;
if ( * V_198 == 0 )
return V_199 ;
V_7 = 1 ;
F_75 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
if ( V_7 ++ == * V_198 )
return V_2 ;
}
return NULL ;
}
static void * F_122 ( struct V_197 * V_114 , void * V_200 , T_4 * V_198 )
{
struct V_1 * V_2 ;
++ * V_198 ;
V_2 = V_200 ;
if ( V_200 == V_199 )
V_2 = F_123 ( & V_18 . V_201 ) ;
F_124 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static void F_125 ( struct V_197 * V_114 , void * V_200 )
__releases( T_8 )
{
F_78 () ;
}
static char * F_126 ( char type )
{
switch ( type ) {
case V_202 :
return L_3 ;
case V_203 :
return L_4 ;
case V_204 :
return L_5 ;
}
return L_6 ;
}
static int F_127 ( struct V_197 * V_114 , void * V_200 )
{
if ( V_200 == V_199 )
F_128 ( V_114 , L_7 ) ;
else {
struct V_1 * V_2 = V_200 ;
char V_205 [ V_206 ] ;
char V_207 [ V_206 ] ;
struct V_25 * V_26 = F_76 ( V_2 -> V_31 ) ;
F_129 ( V_114 , L_8
L_9 ,
V_2 -> V_15 ? V_2 -> V_15 : L_10 ,
F_126 ( V_26 -> V_4 . V_208 ) ,
0 , 0 ,
V_26 -> V_155 , V_26 -> V_4 . V_155 ,
F_12 ( V_2 ) ,
V_26 -> V_4 . V_162 ,
V_26 -> V_4 . V_209 , V_26 -> V_4 . V_15 ,
V_26 -> V_151 ? F_130 ( F_89 ( * ( V_85 * ) V_26 -> V_151 -> V_210 ) , V_207 ) : L_11 ,
V_26 -> V_193 ? F_130 ( F_89 ( * ( V_85 * ) V_26 -> V_193 -> V_210 ) , V_205 ) : L_11 ) ;
}
return 0 ;
}
static int F_131 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_132 ( V_212 , & V_213 ) ;
}
void T_9 F_133 ( void )
{
if ( V_132 [ 0 ] > 63 || V_132 [ 0 ] < 0 ) {
F_134 ( V_214 L_12 ) ;
return;
}
if ( V_132 [ 1 ] > 1023 || V_132 [ 1 ] < 0 ) {
F_134 ( V_214 L_13 ) ;
return;
}
V_190 = F_84 ( ( V_132 [ 0 ] << 10 ) | V_132 [ 1 ] ) ;
F_115 () ;
F_135 ( V_215 , V_56 , F_56 , NULL , NULL ) ;
F_135 ( V_215 , V_51 , F_49 , NULL , NULL ) ;
F_135 ( V_215 , V_216 , NULL , F_73 , NULL ) ;
F_136 ( & V_18 , L_14 , V_217 , & V_218 ) ;
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_187 ; V_7 ++ )
F_1 ( NULL , & V_186 [ V_7 ] ) ;
}
#endif
}
void T_10 F_138 ( void )
{
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_187 ; V_7 ++ )
F_6 ( & V_186 [ V_7 ] ) ;
}
#endif
F_139 ( & V_18 , L_14 ) ;
F_113 () ;
}
