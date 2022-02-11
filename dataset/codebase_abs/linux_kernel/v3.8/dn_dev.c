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
if ( ! F_34 ( V_77 ) )
return - V_106 ;
if ( ! F_51 ( V_99 , & V_18 ) )
goto V_107;
V_27 = F_52 ( V_98 , sizeof( * V_105 ) , V_102 , V_103 , V_108 ) ;
if ( V_27 < 0 )
goto V_107;
V_27 = - V_81 ;
V_105 = F_53 ( V_98 ) ;
if ( ( V_26 = F_47 ( V_105 -> V_109 ) ) == NULL )
goto V_107;
V_27 = - V_84 ;
for ( V_44 = & V_26 -> V_54 ;
( V_42 = F_18 ( * V_44 ) ) != NULL ;
V_44 = & V_42 -> V_48 ) {
if ( V_102 [ V_110 ] &&
F_54 ( V_102 [ V_110 ] , & V_42 -> V_49 , 2 ) )
continue;
if ( V_102 [ V_111 ] && F_55 ( V_102 [ V_111 ] , V_42 -> V_83 ) )
continue;
F_17 ( V_26 , V_44 , 1 ) ;
return 0 ;
}
V_107:
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
if ( ! F_34 ( V_77 ) )
return - V_106 ;
if ( ! F_51 ( V_99 , & V_18 ) )
return - V_30 ;
V_27 = F_52 ( V_98 , sizeof( * V_105 ) , V_102 , V_103 , V_108 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_102 [ V_110 ] == NULL )
return - V_30 ;
V_105 = F_53 ( V_98 ) ;
if ( ( V_2 = F_48 ( & V_18 , V_105 -> V_109 ) ) == NULL )
return - V_81 ;
if ( ( V_26 = F_18 ( V_2 -> V_31 ) ) == NULL ) {
V_26 = F_30 ( V_2 , & V_27 ) ;
if ( ! V_26 )
return V_27 ;
}
if ( ( V_42 = F_13 () ) == NULL )
return - V_88 ;
if ( V_102 [ V_112 ] == NULL )
V_102 [ V_112 ] = V_102 [ V_110 ] ;
V_42 -> V_49 = F_57 ( V_102 [ V_110 ] ) ;
V_42 -> V_89 = F_57 ( V_102 [ V_112 ] ) ;
V_42 -> V_113 = V_105 -> V_113 ;
V_42 -> V_62 = V_105 -> V_62 ;
V_42 -> V_59 = V_26 ;
if ( V_102 [ V_111 ] )
F_58 ( V_42 -> V_83 , V_102 [ V_111 ] , V_9 ) ;
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
T_6 V_114 , T_6 V_115 , int V_116 , unsigned int V_60 )
{
struct V_104 * V_105 ;
struct V_97 * V_98 ;
V_98 = F_63 ( V_96 , V_114 , V_115 , V_116 , sizeof( * V_105 ) , V_60 ) ;
if ( V_98 == NULL )
return - V_117 ;
V_105 = F_53 ( V_98 ) ;
V_105 -> V_118 = V_80 ;
V_105 -> V_119 = 16 ;
V_105 -> V_113 = V_42 -> V_113 | V_120 ;
V_105 -> V_62 = V_42 -> V_62 ;
V_105 -> V_109 = V_42 -> V_59 -> V_2 -> V_94 ;
if ( ( V_42 -> V_89 &&
F_64 ( V_96 , V_112 , V_42 -> V_89 ) ) ||
( V_42 -> V_49 &&
F_64 ( V_96 , V_110 , V_42 -> V_49 ) ) ||
( V_42 -> V_83 [ 0 ] &&
F_65 ( V_96 , V_111 , V_42 -> V_83 ) ) )
goto V_121;
return F_66 ( V_96 , V_98 ) ;
V_121:
F_67 ( V_96 , V_98 ) ;
return - V_117 ;
}
static void F_23 ( int V_116 , struct V_41 * V_42 )
{
struct V_95 * V_96 ;
int V_27 = - V_88 ;
V_96 = F_68 ( F_59 () , V_11 ) ;
if ( V_96 == NULL )
goto V_107;
V_27 = F_62 ( V_96 , V_42 , 0 , 0 , V_116 , 0 ) ;
if ( V_27 < 0 ) {
F_69 ( V_27 == - V_117 ) ;
F_70 ( V_96 ) ;
goto V_107;
}
F_71 ( V_96 , & V_18 , 0 , V_122 , NULL , V_11 ) ;
return;
V_107:
if ( V_27 < 0 )
F_72 ( & V_18 , V_122 , V_27 ) ;
}
static int F_73 ( struct V_95 * V_96 , struct V_123 * V_124 )
{
struct V_99 * V_99 = F_50 ( V_96 -> V_100 ) ;
int V_125 , V_126 = 0 , V_127 , V_128 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
if ( ! F_51 ( V_99 , & V_18 ) )
return 0 ;
V_127 = V_124 -> args [ 0 ] ;
V_128 = V_124 -> args [ 1 ] ;
V_125 = 0 ;
F_74 () ;
F_75 (&init_net, dev) {
if ( V_125 < V_127 )
goto V_129;
else if ( V_125 > V_127 ) {
V_128 = 0 ;
}
if ( ( V_26 = F_76 ( V_2 -> V_31 ) ) == NULL )
goto V_129;
for ( V_42 = F_76 ( V_26 -> V_54 ) , V_126 = 0 ; V_42 ;
V_42 = F_76 ( V_42 -> V_48 ) , V_126 ++ ) {
if ( V_126 < V_128 )
continue;
if ( F_62 ( V_96 , V_42 , F_77 ( V_124 -> V_96 ) . V_114 ,
V_124 -> V_98 -> V_130 , V_56 ,
V_131 ) < 0 )
goto V_82;
}
V_129:
V_125 ++ ;
}
V_82:
F_78 () ;
V_124 -> args [ 0 ] = V_125 ;
V_124 -> args [ 1 ] = V_126 ;
return V_96 -> V_132 ;
}
static int F_79 ( struct V_1 * V_2 , V_85 * V_133 )
{
struct V_25 * V_26 ;
struct V_41 * V_42 ;
int V_58 = - V_81 ;
F_74 () ;
V_26 = F_76 ( V_2 -> V_31 ) ;
if ( V_26 == NULL )
goto V_134;
V_42 = F_76 ( V_26 -> V_54 ) ;
if ( V_42 != NULL ) {
* V_133 = V_42 -> V_49 ;
V_58 = 0 ;
}
V_134:
F_78 () ;
return V_58 ;
}
int F_80 ( V_85 * V_133 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_40 () ;
V_135:
if ( V_2 ) {
V_58 = F_79 ( V_2 , V_133 ) ;
F_45 ( V_2 ) ;
if ( V_58 == 0 || V_2 == V_18 . V_136 )
return V_58 ;
}
V_2 = V_18 . V_136 ;
F_42 ( V_2 ) ;
goto V_135;
}
static void F_81 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_137 * V_138 ;
struct V_95 * V_96 = NULL ;
V_85 * V_139 ;
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( ( V_96 = F_82 ( NULL , sizeof( * V_138 ) , V_140 ) ) == NULL )
return;
V_96 -> V_2 = V_2 ;
V_138 = (struct V_137 * ) F_83 ( V_96 , sizeof( * V_138 ) ) ;
V_138 -> V_141 = 0x0D ;
memcpy ( V_138 -> V_142 , V_143 , 3 ) ;
F_21 ( V_138 -> V_144 , V_42 -> V_49 ) ;
V_138 -> V_145 = V_146 ;
V_138 -> V_35 = F_84 ( F_12 ( V_2 ) ) ;
V_138 -> V_147 = 0x00 ;
memset ( V_138 -> V_148 , 0 , 8 ) ;
memcpy ( V_138 -> V_149 , V_150 , V_151 ) ;
if ( V_26 -> V_152 ) {
struct V_153 * V_154 = (struct V_153 * ) V_26 -> V_152 ;
F_21 ( V_138 -> V_149 , V_154 -> V_133 ) ;
}
V_138 -> V_155 = F_84 ( ( unsigned short ) V_26 -> V_4 . V_156 ) ;
V_138 -> V_157 = 0x00 ;
V_138 -> V_158 = 0x02 ;
memset ( V_138 -> V_14 , 0xAA , 2 ) ;
V_139 = ( V_85 * ) F_85 ( V_96 , 2 ) ;
* V_139 = F_84 ( V_96 -> V_132 - 2 ) ;
F_86 ( V_96 ) ;
F_87 ( V_96 , V_159 , V_138 -> V_144 ) ;
}
static int F_88 ( struct V_153 * V_154 , struct V_25 * V_26 , struct V_41 * V_42 )
{
if ( ( V_160 - V_26 -> V_161 ) < V_162 )
return 0 ;
if ( ! V_26 -> V_152 )
return 1 ;
if ( V_154 -> V_163 < V_26 -> V_4 . V_163 )
return 1 ;
if ( V_154 -> V_163 != V_26 -> V_4 . V_163 )
return 0 ;
if ( F_89 ( V_154 -> V_133 ) < F_89 ( V_42 -> V_49 ) )
return 1 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_164 ;
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
struct V_153 * V_154 = (struct V_153 * ) V_26 -> V_152 ;
struct V_95 * V_96 ;
T_3 V_165 ;
unsigned char * V_166 ;
unsigned char * V_167 , * V_168 ;
V_85 * V_139 ;
char * V_169 ;
if ( F_12 ( V_2 ) < ( 26 + 7 ) )
return;
V_164 = F_12 ( V_2 ) - 26 ;
V_164 /= 7 ;
if ( V_164 > 32 )
V_164 = 32 ;
V_165 = 2 + 26 + 7 * V_164 ;
if ( ( V_96 = F_82 ( NULL , V_165 , V_140 ) ) == NULL )
return;
V_96 -> V_2 = V_2 ;
V_166 = F_83 ( V_96 , V_165 ) ;
* V_166 ++ = V_170 | V_171 ;
* V_166 ++ = 2 ;
* V_166 ++ = 0 ;
* V_166 ++ = 0 ;
F_21 ( V_166 , V_42 -> V_49 ) ;
V_169 = V_166 ;
V_166 += V_151 ;
* V_166 ++ = V_26 -> V_4 . V_32 == 1 ?
V_172 : V_173 ;
* ( ( V_85 * ) V_166 ) = F_84 ( F_12 ( V_2 ) ) ;
V_166 += 2 ;
* V_166 ++ = V_26 -> V_4 . V_163 ;
* V_166 ++ = 0 ;
* ( ( V_85 * ) V_166 ) = F_84 ( ( unsigned short ) V_26 -> V_4 . V_156 ) ;
V_166 += 2 ;
* V_166 ++ = 0 ;
V_167 = V_166 ++ ;
memset ( V_166 , 0 , 7 ) ;
V_166 += 7 ;
V_168 = V_166 ++ ;
V_164 = F_91 ( V_2 , V_166 , V_164 ) ;
* V_168 = 7 * V_164 ;
* V_167 = 8 + * V_168 ;
F_92 ( V_96 , ( 27 + * V_168 ) ) ;
V_139 = ( V_85 * ) F_85 ( V_96 , 2 ) ;
* V_139 = F_84 ( V_96 -> V_132 - 2 ) ;
F_86 ( V_96 ) ;
if ( F_88 ( V_154 , V_26 , V_42 ) ) {
struct V_95 * V_174 = F_93 ( V_96 , V_140 ) ;
if ( V_174 ) {
F_87 ( V_174 , V_175 , V_169 ) ;
}
}
F_87 ( V_96 , V_159 , V_169 ) ;
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
int V_176 = 16 ;
int V_165 = V_2 -> V_177 + 2 + 4 + V_176 ;
struct V_95 * V_96 = F_82 ( NULL , V_165 , V_140 ) ;
int V_7 ;
unsigned char * V_166 ;
char V_169 [ V_151 ] ;
if ( V_96 == NULL )
return ;
V_96 -> V_2 = V_2 ;
F_85 ( V_96 , V_2 -> V_177 ) ;
V_166 = F_83 ( V_96 , 2 + 4 + V_176 ) ;
* V_166 ++ = V_178 ;
* ( ( V_85 * ) V_166 ) = V_42 -> V_49 ;
V_166 += 2 ;
* V_166 ++ = V_176 ;
for( V_7 = 0 ; V_7 < V_176 ; V_7 ++ )
* V_166 ++ = 0252 ;
F_21 ( V_169 , V_42 -> V_49 ) ;
F_87 ( V_96 , V_159 , V_169 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_27 ( V_2 , V_175 ) ;
else
F_27 ( V_2 , V_159 ) ;
V_26 -> V_179 = 1 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_22 ( V_2 , V_175 ) ;
else
F_22 ( V_2 , V_159 ) ;
}
static void F_98 ( unsigned long V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
F_74 () ;
V_26 = F_76 ( V_2 -> V_31 ) ;
if ( V_26 -> V_156 <= V_26 -> V_4 . V_180 ) {
if ( V_26 -> V_4 . V_181 ) {
for ( V_42 = F_76 ( V_26 -> V_54 ) ;
V_42 ;
V_42 = F_76 ( V_42 -> V_48 ) ) {
if ( ! ( V_42 -> V_113 & V_182 ) )
V_26 -> V_4 . V_181 ( V_2 , V_42 ) ;
}
}
V_26 -> V_156 = V_26 -> V_4 . V_156 ;
} else {
V_26 -> V_156 -= V_26 -> V_4 . V_180 ;
}
F_78 () ;
F_99 ( V_2 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_10 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_180 > V_26 -> V_4 . V_156 )
V_26 -> V_4 . V_180 = V_26 -> V_4 . V_156 ;
V_26 -> V_155 . V_14 = ( unsigned long ) V_2 ;
V_26 -> V_155 . V_183 = F_98 ;
V_26 -> V_155 . V_184 = V_160 + ( V_26 -> V_4 . V_180 * V_185 ) ;
F_100 ( & V_26 -> V_155 ) ;
}
static struct V_25 * F_30 ( struct V_1 * V_2 , int * V_27 )
{
int V_7 ;
struct V_3 * V_186 = V_187 ;
struct V_25 * V_26 ;
for( V_7 = 0 ; V_7 < V_188 ; V_7 ++ , V_186 ++ ) {
if ( V_186 -> type == V_2 -> type )
break;
}
* V_27 = - V_81 ;
if ( V_7 == V_188 )
return NULL ;
* V_27 = - V_88 ;
if ( ( V_26 = F_14 ( sizeof( struct V_25 ) , V_140 ) ) == NULL )
return NULL ;
memcpy ( & V_26 -> V_4 , V_186 , sizeof( struct V_3 ) ) ;
F_28 ( V_2 -> V_31 , V_26 ) ;
V_26 -> V_2 = V_2 ;
F_101 ( & V_26 -> V_155 ) ;
V_26 -> V_161 = V_160 ;
V_26 -> V_189 = F_102 ( V_2 , & V_190 ) ;
if ( ! V_26 -> V_189 ) {
F_103 ( V_2 -> V_31 , NULL ) ;
F_5 ( V_26 ) ;
return NULL ;
}
if ( V_26 -> V_4 . V_34 ) {
if ( V_26 -> V_4 . V_34 ( V_2 ) < 0 ) {
F_104 ( & V_190 , V_26 -> V_189 ) ;
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
V_85 V_133 = V_191 ;
int V_192 = 0 ;
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
if ( memcmp ( V_2 -> V_50 , V_150 , 4 ) != 0 )
return;
V_133 = F_20 ( V_2 -> V_50 ) ;
V_192 = 1 ;
}
if ( V_133 == 0 )
return;
if ( ( V_42 = F_13 () ) == NULL )
return;
V_42 -> V_49 = V_42 -> V_89 = V_133 ;
V_42 -> V_113 = 0 ;
V_42 -> V_62 = V_193 ;
strcpy ( V_42 -> V_83 , V_2 -> V_15 ) ;
F_29 ( V_2 , V_42 ) ;
if ( V_192 ) {
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
F_106 ( & V_26 -> V_155 ) ;
F_6 ( & V_26 -> V_4 ) ;
F_46 ( V_2 ) ;
F_107 ( & V_190 , V_2 ) ;
if ( V_26 -> V_4 . V_33 )
V_26 -> V_4 . V_33 ( V_2 ) ;
V_2 -> V_31 = NULL ;
F_104 ( & V_190 , V_26 -> V_189 ) ;
F_107 ( & V_190 , V_2 ) ;
if ( V_26 -> V_152 )
F_108 ( V_26 -> V_152 ) ;
if ( V_26 -> V_194 )
F_108 ( V_26 -> V_194 ) ;
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
if ( V_2 -> V_60 & V_195 )
F_105 ( V_2 ) ;
}
F_38 () ;
}
int F_116 ( struct V_196 * V_197 )
{
return F_117 ( & V_52 , V_197 ) ;
}
int F_118 ( struct V_196 * V_197 )
{
return F_119 ( & V_52 , V_197 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
return V_2 -> V_31 != NULL ;
}
static void * F_121 ( struct V_198 * V_115 , T_4 * V_199 )
__acquires( T_8 )
{
int V_7 ;
struct V_1 * V_2 ;
F_74 () ;
if ( * V_199 == 0 )
return V_200 ;
V_7 = 1 ;
F_75 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
if ( V_7 ++ == * V_199 )
return V_2 ;
}
return NULL ;
}
static void * F_122 ( struct V_198 * V_115 , void * V_201 , T_4 * V_199 )
{
struct V_1 * V_2 ;
++ * V_199 ;
V_2 = V_201 ;
if ( V_201 == V_200 )
V_2 = F_123 ( & V_18 . V_202 ) ;
F_124 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static void F_125 ( struct V_198 * V_115 , void * V_201 )
__releases( T_8 )
{
F_78 () ;
}
static char * F_126 ( char type )
{
switch ( type ) {
case V_203 :
return L_3 ;
case V_204 :
return L_4 ;
case V_205 :
return L_5 ;
}
return L_6 ;
}
static int F_127 ( struct V_198 * V_115 , void * V_201 )
{
if ( V_201 == V_200 )
F_128 ( V_115 , L_7 ) ;
else {
struct V_1 * V_2 = V_201 ;
char V_206 [ V_207 ] ;
char V_208 [ V_207 ] ;
struct V_25 * V_26 = F_76 ( V_2 -> V_31 ) ;
F_129 ( V_115 , L_8
L_9 ,
V_2 -> V_15 ? V_2 -> V_15 : L_10 ,
F_126 ( V_26 -> V_4 . V_209 ) ,
0 , 0 ,
V_26 -> V_156 , V_26 -> V_4 . V_156 ,
F_12 ( V_2 ) ,
V_26 -> V_4 . V_163 ,
V_26 -> V_4 . V_210 , V_26 -> V_4 . V_15 ,
V_26 -> V_152 ? F_130 ( F_89 ( * ( V_85 * ) V_26 -> V_152 -> V_211 ) , V_208 ) : L_11 ,
V_26 -> V_194 ? F_130 ( F_89 ( * ( V_85 * ) V_26 -> V_194 -> V_211 ) , V_206 ) : L_11 ) ;
}
return 0 ;
}
static int F_131 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_132 ( V_213 , & V_214 ) ;
}
void T_9 F_133 ( void )
{
if ( V_133 [ 0 ] > 63 || V_133 [ 0 ] < 0 ) {
F_134 ( V_215 L_12 ) ;
return;
}
if ( V_133 [ 1 ] > 1023 || V_133 [ 1 ] < 0 ) {
F_134 ( V_215 L_13 ) ;
return;
}
V_191 = F_84 ( ( V_133 [ 0 ] << 10 ) | V_133 [ 1 ] ) ;
F_115 () ;
F_135 ( V_216 , V_56 , F_56 , NULL , NULL ) ;
F_135 ( V_216 , V_51 , F_49 , NULL , NULL ) ;
F_135 ( V_216 , V_217 , NULL , F_73 , NULL ) ;
F_136 ( & V_18 , L_14 , V_218 , & V_219 ) ;
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_188 ; V_7 ++ )
F_1 ( NULL , & V_187 [ V_7 ] ) ;
}
#endif
}
void T_10 F_138 ( void )
{
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_188 ; V_7 ++ )
F_6 ( & V_187 [ V_7 ] ) ;
}
#endif
F_139 ( & V_18 , L_14 ) ;
F_113 () ;
}
