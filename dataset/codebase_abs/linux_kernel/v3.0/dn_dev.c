static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
#define F_2 3
struct V_8 V_9 [] = {
{ . V_10 = L_1 , } ,
{ . V_10 = L_2 , } ,
{ . V_10 = L_3 , } ,
{ } ,
{ } ,
} ;
V_6 = F_3 ( & V_11 , sizeof( * V_6 ) , V_12 ) ;
if ( V_6 == NULL )
return;
for( V_7 = 0 ; V_7 < F_4 ( V_6 -> V_13 ) - 1 ; V_7 ++ ) {
long V_14 = ( long ) V_6 -> V_13 [ V_7 ] . V_15 ;
V_6 -> V_13 [ V_7 ] . V_15 = ( ( char * ) V_4 ) + V_14 ;
}
if ( V_2 ) {
V_9 [ F_2 ] . V_10 = V_2 -> V_16 ;
} else {
V_9 [ F_2 ] . V_10 = V_4 -> V_16 ;
}
V_6 -> V_13 [ 0 ] . V_17 = ( void * ) V_2 ;
V_6 -> V_18 = F_5 ( V_9 , V_6 -> V_13 ) ;
if ( V_6 -> V_18 == NULL )
F_6 ( V_6 ) ;
else
V_4 -> V_19 = V_6 ;
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_19 ) {
struct V_5 * V_6 = V_4 -> V_19 ;
V_4 -> V_19 = NULL ;
F_8 ( V_6 -> V_18 ) ;
F_6 ( V_6 ) ;
}
}
static int F_9 ( T_1 * V_20 , int V_21 ,
void T_2 * V_22 ,
T_3 * V_23 , T_4 * V_24 )
{
#ifdef F_10
struct V_1 * V_2 = V_20 -> V_17 ;
struct V_25 * V_26 ;
int V_27 ;
int V_28 , V_29 ;
if ( V_20 -> V_17 == NULL )
return - V_30 ;
V_26 = F_11 ( V_2 -> V_31 ) ;
V_29 = V_26 -> V_4 . V_32 ;
V_27 = F_12 ( V_20 , V_21 , V_22 , V_23 , V_24 ) ;
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
static void F_7 ( struct V_3 * V_4 )
{
}
static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static inline T_5 F_13 ( struct V_1 * V_2 )
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
static struct V_41 * F_14 ( void )
{
struct V_41 * V_42 ;
V_42 = F_15 ( sizeof( * V_42 ) , V_12 ) ;
return V_42 ;
}
static void F_16 ( struct V_41 * V_42 )
{
F_17 ( V_42 , V_43 ) ;
}
static void F_18 ( struct V_25 * V_26 , struct V_41 T_7 * * V_44 , int V_45 )
{
struct V_41 * V_46 = F_19 ( * V_44 ) ;
unsigned char V_47 [ 6 ] ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_20 () ;
* V_44 = V_46 -> V_48 ;
if ( V_26 -> V_2 -> type == V_37 ) {
if ( V_46 -> V_49 != F_21 ( V_2 -> V_50 ) ) {
F_22 ( V_47 , V_46 -> V_49 ) ;
F_23 ( V_2 , V_47 ) ;
}
}
F_24 ( V_51 , V_46 ) ;
F_25 ( & V_52 , V_53 , V_46 ) ;
if ( V_45 ) {
F_16 ( V_46 ) ;
if ( V_26 -> V_54 == NULL )
F_26 ( V_26 -> V_2 ) ;
}
}
static int F_27 ( struct V_25 * V_26 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_41 * V_46 ;
unsigned char V_47 [ 6 ] ;
F_20 () ;
for ( V_46 = F_19 ( V_26 -> V_54 ) ;
V_46 != NULL ;
V_46 = F_19 ( V_46 -> V_48 ) ) {
if ( V_46 -> V_49 == V_42 -> V_49 )
return - V_55 ;
}
if ( V_2 -> type == V_37 ) {
if ( V_42 -> V_49 != F_21 ( V_2 -> V_50 ) ) {
F_22 ( V_47 , V_42 -> V_49 ) ;
F_28 ( V_2 , V_47 ) ;
}
}
V_42 -> V_48 = V_26 -> V_54 ;
F_29 ( V_26 -> V_54 , V_42 ) ;
F_24 ( V_56 , V_42 ) ;
F_25 ( & V_52 , V_57 , V_42 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_25 * V_26 = F_19 ( V_2 -> V_31 ) ;
int V_58 ;
if ( V_26 == NULL ) {
int V_27 ;
V_26 = F_31 ( V_2 , & V_27 ) ;
if ( V_26 == NULL )
return V_27 ;
}
V_42 -> V_59 = V_26 ;
if ( V_2 -> V_60 & V_61 )
V_42 -> V_62 = V_63 ;
V_58 = F_27 ( V_26 , V_42 ) ;
if ( V_58 )
F_16 ( V_42 ) ;
return V_58 ;
}
int F_32 ( unsigned int V_64 , void T_2 * V_65 )
{
char V_22 [ V_66 ] ;
struct V_67 * V_68 = (struct V_67 * ) V_22 ;
struct V_69 * V_70 = (struct V_69 * ) & V_68 -> V_71 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_41 * V_42 = NULL ;
struct V_41 T_7 * * V_44 = NULL ;
int V_72 = 0 ;
if ( F_33 ( V_68 , V_65 , V_66 ) )
return - V_73 ;
V_68 -> V_74 [ V_75 - 1 ] = 0 ;
F_34 ( & V_76 , V_68 -> V_74 ) ;
switch( V_64 ) {
case V_77 :
break;
case V_78 :
if ( ! F_35 ( V_79 ) )
return - V_80 ;
if ( V_70 -> V_81 != V_82 )
return - V_30 ;
break;
default:
return - V_30 ;
}
F_36 () ;
if ( ( V_2 = F_37 ( & V_76 , V_68 -> V_74 ) ) == NULL ) {
V_72 = - V_83 ;
goto V_84;
}
if ( ( V_26 = F_19 ( V_2 -> V_31 ) ) != NULL ) {
for ( V_44 = & V_26 -> V_54 ;
( V_42 = F_19 ( * V_44 ) ) != NULL ;
V_44 = & V_42 -> V_48 )
if ( strcmp ( V_68 -> V_74 , V_42 -> V_85 ) == 0 )
break;
}
if ( V_42 == NULL && V_64 != V_78 ) {
V_72 = - V_86 ;
goto V_84;
}
switch( V_64 ) {
case V_77 :
* ( ( V_87 * ) V_70 -> V_88 ) = V_42 -> V_49 ;
goto V_89;
case V_78 :
if ( ! V_42 ) {
if ( ( V_42 = F_14 () ) == NULL ) {
V_72 = - V_90 ;
break;
}
memcpy ( V_42 -> V_85 , V_2 -> V_16 , V_75 ) ;
} else {
if ( V_42 -> V_49 == F_38 ( V_70 ) )
break;
F_18 ( V_26 , V_44 , 0 ) ;
}
V_42 -> V_49 = V_42 -> V_91 = F_38 ( V_70 ) ;
V_72 = F_30 ( V_2 , V_42 ) ;
}
V_84:
F_39 () ;
return V_72 ;
V_89:
if ( F_40 ( V_65 , V_68 , V_66 ) )
V_72 = - V_73 ;
goto V_84;
}
struct V_1 * F_41 ( void )
{
struct V_1 * V_2 ;
F_42 ( & V_92 ) ;
V_2 = V_93 ;
if ( V_2 ) {
if ( V_2 -> V_31 )
F_43 ( V_2 ) ;
else
V_2 = NULL ;
}
F_44 ( & V_92 ) ;
return V_2 ;
}
int F_45 ( struct V_1 * V_2 , int V_94 )
{
struct V_1 * V_29 = NULL ;
int V_58 = - V_95 ;
if ( ! V_2 -> V_31 )
return - V_83 ;
F_42 ( & V_92 ) ;
if ( V_94 || V_93 == NULL ) {
V_29 = V_93 ;
V_93 = V_2 ;
V_58 = 0 ;
}
F_44 ( & V_92 ) ;
if ( V_29 )
F_46 ( V_29 ) ;
return V_58 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_42 ( & V_92 ) ;
if ( V_2 == V_93 ) {
V_93 = NULL ;
} else {
V_2 = NULL ;
}
F_44 ( & V_92 ) ;
if ( V_2 )
F_46 ( V_2 ) ;
}
static struct V_25 * F_48 ( int V_96 )
{
struct V_1 * V_2 ;
struct V_25 * V_25 = NULL ;
V_2 = F_49 ( & V_76 , V_96 ) ;
if ( V_2 )
V_25 = F_19 ( V_2 -> V_31 ) ;
return V_25 ;
}
static int F_50 ( struct V_97 * V_98 , struct V_99 * V_100 , void * V_65 )
{
struct V_101 * V_101 = F_51 ( V_98 -> V_102 ) ;
struct V_103 * V_104 [ V_105 + 1 ] ;
struct V_25 * V_26 ;
struct V_106 * V_107 ;
struct V_41 * V_42 ;
struct V_41 T_7 * * V_44 ;
int V_27 = - V_30 ;
if ( ! F_52 ( V_101 , & V_76 ) )
goto V_108;
V_27 = F_53 ( V_100 , sizeof( * V_107 ) , V_104 , V_105 , V_109 ) ;
if ( V_27 < 0 )
goto V_108;
V_27 = - V_83 ;
V_107 = F_54 ( V_100 ) ;
if ( ( V_26 = F_48 ( V_107 -> V_110 ) ) == NULL )
goto V_108;
V_27 = - V_86 ;
for ( V_44 = & V_26 -> V_54 ;
( V_42 = F_19 ( * V_44 ) ) != NULL ;
V_44 = & V_42 -> V_48 ) {
if ( V_104 [ V_111 ] &&
F_55 ( V_104 [ V_111 ] , & V_42 -> V_49 , 2 ) )
continue;
if ( V_104 [ V_112 ] && F_56 ( V_104 [ V_112 ] , V_42 -> V_85 ) )
continue;
F_18 ( V_26 , V_44 , 1 ) ;
return 0 ;
}
V_108:
return V_27 ;
}
static int F_57 ( struct V_97 * V_98 , struct V_99 * V_100 , void * V_65 )
{
struct V_101 * V_101 = F_51 ( V_98 -> V_102 ) ;
struct V_103 * V_104 [ V_105 + 1 ] ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_106 * V_107 ;
struct V_41 * V_42 ;
int V_27 ;
if ( ! F_52 ( V_101 , & V_76 ) )
return - V_30 ;
V_27 = F_53 ( V_100 , sizeof( * V_107 ) , V_104 , V_105 , V_109 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_104 [ V_111 ] == NULL )
return - V_30 ;
V_107 = F_54 ( V_100 ) ;
if ( ( V_2 = F_49 ( & V_76 , V_107 -> V_110 ) ) == NULL )
return - V_83 ;
if ( ( V_26 = F_19 ( V_2 -> V_31 ) ) == NULL ) {
V_26 = F_31 ( V_2 , & V_27 ) ;
if ( ! V_26 )
return V_27 ;
}
if ( ( V_42 = F_14 () ) == NULL )
return - V_90 ;
if ( V_104 [ V_113 ] == NULL )
V_104 [ V_113 ] = V_104 [ V_111 ] ;
V_42 -> V_49 = F_58 ( V_104 [ V_111 ] ) ;
V_42 -> V_91 = F_58 ( V_104 [ V_113 ] ) ;
V_42 -> V_114 = V_107 -> V_114 ;
V_42 -> V_62 = V_107 -> V_62 ;
V_42 -> V_59 = V_26 ;
if ( V_104 [ V_112 ] )
F_59 ( V_42 -> V_85 , V_104 [ V_112 ] , V_75 ) ;
else
memcpy ( V_42 -> V_85 , V_2 -> V_16 , V_75 ) ;
V_27 = F_27 ( V_26 , V_42 ) ;
if ( V_27 )
F_16 ( V_42 ) ;
return V_27 ;
}
static inline T_3 F_60 ( void )
{
return F_61 ( sizeof( struct V_106 ) )
+ F_62 ( V_75 )
+ F_62 ( 2 )
+ F_62 ( 2 ) ;
}
static int F_63 ( struct V_97 * V_98 , struct V_41 * V_42 ,
T_6 V_115 , T_6 V_116 , int V_117 , unsigned int V_60 )
{
struct V_106 * V_107 ;
struct V_99 * V_100 ;
V_100 = F_64 ( V_98 , V_115 , V_116 , V_117 , sizeof( * V_107 ) , V_60 ) ;
if ( V_100 == NULL )
return - V_118 ;
V_107 = F_54 ( V_100 ) ;
V_107 -> V_119 = V_82 ;
V_107 -> V_120 = 16 ;
V_107 -> V_114 = V_42 -> V_114 | V_121 ;
V_107 -> V_62 = V_42 -> V_62 ;
V_107 -> V_110 = V_42 -> V_59 -> V_2 -> V_96 ;
if ( V_42 -> V_91 )
F_65 ( V_98 , V_113 , V_42 -> V_91 ) ;
if ( V_42 -> V_49 )
F_65 ( V_98 , V_111 , V_42 -> V_49 ) ;
if ( V_42 -> V_85 [ 0 ] )
F_66 ( V_98 , V_112 , V_42 -> V_85 ) ;
return F_67 ( V_98 , V_100 ) ;
V_122:
F_68 ( V_98 , V_100 ) ;
return - V_118 ;
}
static void F_24 ( int V_117 , struct V_41 * V_42 )
{
struct V_97 * V_98 ;
int V_27 = - V_90 ;
V_98 = F_69 ( F_60 () , V_12 ) ;
if ( V_98 == NULL )
goto V_108;
V_27 = F_63 ( V_98 , V_42 , 0 , 0 , V_117 , 0 ) ;
if ( V_27 < 0 ) {
F_70 ( V_27 == - V_118 ) ;
F_71 ( V_98 ) ;
goto V_108;
}
F_72 ( V_98 , & V_76 , 0 , V_123 , NULL , V_12 ) ;
return;
V_108:
if ( V_27 < 0 )
F_73 ( & V_76 , V_123 , V_27 ) ;
}
static int F_74 ( struct V_97 * V_98 , struct V_124 * V_125 )
{
struct V_101 * V_101 = F_51 ( V_98 -> V_102 ) ;
int V_126 , V_127 = 0 , V_128 , V_129 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
if ( ! F_52 ( V_101 , & V_76 ) )
return 0 ;
V_128 = V_125 -> args [ 0 ] ;
V_129 = V_125 -> args [ 1 ] ;
V_126 = 0 ;
F_75 () ;
F_76 (&init_net, dev) {
if ( V_126 < V_128 )
goto V_130;
else if ( V_126 > V_128 ) {
V_129 = 0 ;
}
if ( ( V_26 = F_77 ( V_2 -> V_31 ) ) == NULL )
goto V_130;
for ( V_42 = F_77 ( V_26 -> V_54 ) , V_127 = 0 ; V_42 ;
V_42 = F_77 ( V_42 -> V_48 ) , V_127 ++ ) {
if ( V_127 < V_129 )
continue;
if ( F_63 ( V_98 , V_42 , F_78 ( V_125 -> V_98 ) . V_115 ,
V_125 -> V_100 -> V_131 , V_56 ,
V_132 ) < 0 )
goto V_84;
}
V_130:
V_126 ++ ;
}
V_84:
F_79 () ;
V_125 -> args [ 0 ] = V_126 ;
V_125 -> args [ 1 ] = V_127 ;
return V_98 -> V_133 ;
}
static int F_80 ( struct V_1 * V_2 , V_87 * V_134 )
{
struct V_25 * V_26 ;
struct V_41 * V_42 ;
int V_58 = - V_83 ;
F_75 () ;
V_26 = F_77 ( V_2 -> V_31 ) ;
if ( V_26 == NULL )
goto V_135;
V_42 = F_77 ( V_26 -> V_54 ) ;
if ( V_42 != NULL ) {
* V_134 = V_42 -> V_49 ;
V_58 = 0 ;
}
V_135:
F_79 () ;
return V_58 ;
}
int F_81 ( V_87 * V_134 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_41 () ;
V_136:
if ( V_2 ) {
V_58 = F_80 ( V_2 , V_134 ) ;
F_46 ( V_2 ) ;
if ( V_58 == 0 || V_2 == V_76 . V_137 )
return V_58 ;
}
V_2 = V_76 . V_137 ;
F_43 ( V_2 ) ;
goto V_136;
}
static void F_82 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_138 * V_139 ;
struct V_97 * V_98 = NULL ;
V_87 * V_140 ;
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
if ( ( V_98 = F_83 ( NULL , sizeof( * V_139 ) , V_141 ) ) == NULL )
return;
V_98 -> V_2 = V_2 ;
V_139 = (struct V_138 * ) F_84 ( V_98 , sizeof( * V_139 ) ) ;
V_139 -> V_142 = 0x0D ;
memcpy ( V_139 -> V_143 , V_144 , 3 ) ;
F_22 ( V_139 -> V_145 , V_42 -> V_49 ) ;
V_139 -> V_146 = V_147 ;
V_139 -> V_35 = F_85 ( F_13 ( V_2 ) ) ;
V_139 -> V_148 = 0x00 ;
memset ( V_139 -> V_149 , 0 , 8 ) ;
memcpy ( V_139 -> V_150 , V_151 , V_152 ) ;
if ( V_26 -> V_153 ) {
struct V_154 * V_155 = (struct V_154 * ) V_26 -> V_153 ;
F_22 ( V_139 -> V_150 , V_155 -> V_134 ) ;
}
V_139 -> V_156 = F_85 ( ( unsigned short ) V_26 -> V_4 . V_157 ) ;
V_139 -> V_158 = 0x00 ;
V_139 -> V_159 = 0x02 ;
memset ( V_139 -> V_15 , 0xAA , 2 ) ;
V_140 = ( V_87 * ) F_86 ( V_98 , 2 ) ;
* V_140 = F_85 ( V_98 -> V_133 - 2 ) ;
F_87 ( V_98 ) ;
F_88 ( V_98 , V_160 , V_139 -> V_145 ) ;
}
static int F_89 ( struct V_154 * V_155 , struct V_25 * V_26 , struct V_41 * V_42 )
{
if ( ( V_161 - V_26 -> V_162 ) < V_163 )
return 0 ;
if ( ! V_26 -> V_153 )
return 1 ;
if ( V_155 -> V_164 < V_26 -> V_4 . V_164 )
return 1 ;
if ( V_155 -> V_164 != V_26 -> V_4 . V_164 )
return 0 ;
if ( F_90 ( V_155 -> V_134 ) < F_90 ( V_42 -> V_49 ) )
return 1 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_165 ;
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
struct V_154 * V_155 = (struct V_154 * ) V_26 -> V_153 ;
struct V_97 * V_98 ;
T_3 V_166 ;
unsigned char * V_167 ;
unsigned char * V_168 , * V_169 ;
V_87 * V_140 ;
char * V_170 ;
if ( F_13 ( V_2 ) < ( 26 + 7 ) )
return;
V_165 = F_13 ( V_2 ) - 26 ;
V_165 /= 7 ;
if ( V_165 > 32 )
V_165 = 32 ;
V_166 = 2 + 26 + 7 * V_165 ;
if ( ( V_98 = F_83 ( NULL , V_166 , V_141 ) ) == NULL )
return;
V_98 -> V_2 = V_2 ;
V_167 = F_84 ( V_98 , V_166 ) ;
* V_167 ++ = V_171 | V_172 ;
* V_167 ++ = 2 ;
* V_167 ++ = 0 ;
* V_167 ++ = 0 ;
F_22 ( V_167 , V_42 -> V_49 ) ;
V_170 = V_167 ;
V_167 += V_152 ;
* V_167 ++ = V_26 -> V_4 . V_32 == 1 ?
V_173 : V_174 ;
* ( ( V_87 * ) V_167 ) = F_85 ( F_13 ( V_2 ) ) ;
V_167 += 2 ;
* V_167 ++ = V_26 -> V_4 . V_164 ;
* V_167 ++ = 0 ;
* ( ( V_87 * ) V_167 ) = F_85 ( ( unsigned short ) V_26 -> V_4 . V_157 ) ;
V_167 += 2 ;
* V_167 ++ = 0 ;
V_168 = V_167 ++ ;
memset ( V_167 , 0 , 7 ) ;
V_167 += 7 ;
V_169 = V_167 ++ ;
V_165 = F_92 ( V_2 , V_167 , V_165 ) ;
* V_169 = 7 * V_165 ;
* V_168 = 8 + * V_169 ;
F_93 ( V_98 , ( 27 + * V_169 ) ) ;
V_140 = ( V_87 * ) F_86 ( V_98 , 2 ) ;
* V_140 = F_85 ( V_98 -> V_133 - 2 ) ;
F_87 ( V_98 ) ;
if ( F_89 ( V_155 , V_26 , V_42 ) ) {
struct V_97 * V_175 = F_94 ( V_98 , V_141 ) ;
if ( V_175 ) {
F_88 ( V_175 , V_176 , V_170 ) ;
}
}
F_88 ( V_98 , V_160 , V_170 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_82 ( V_2 , V_42 ) ;
else
F_91 ( V_2 , V_42 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_177 = 16 ;
int V_166 = V_2 -> V_178 + 2 + 4 + V_177 ;
struct V_97 * V_98 = F_83 ( NULL , V_166 , V_141 ) ;
int V_7 ;
unsigned char * V_167 ;
char V_170 [ V_152 ] ;
if ( V_98 == NULL )
return ;
V_98 -> V_2 = V_2 ;
F_86 ( V_98 , V_2 -> V_178 ) ;
V_167 = F_84 ( V_98 , 2 + 4 + V_177 ) ;
* V_167 ++ = V_179 ;
* ( ( V_87 * ) V_167 ) = V_42 -> V_49 ;
V_167 += 2 ;
* V_167 ++ = V_177 ;
for( V_7 = 0 ; V_7 < V_177 ; V_7 ++ )
* V_167 ++ = 0252 ;
F_22 ( V_170 , V_42 -> V_49 ) ;
F_88 ( V_98 , V_160 , V_170 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_28 ( V_2 , V_176 ) ;
else
F_28 ( V_2 , V_160 ) ;
V_26 -> V_180 = 1 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_32 == 0 )
F_23 ( V_2 , V_176 ) ;
else
F_23 ( V_2 , V_160 ) ;
}
static void F_99 ( unsigned long V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
F_75 () ;
V_26 = F_77 ( V_2 -> V_31 ) ;
if ( V_26 -> V_157 <= V_26 -> V_4 . V_181 ) {
if ( V_26 -> V_4 . V_182 ) {
for ( V_42 = F_77 ( V_26 -> V_54 ) ;
V_42 ;
V_42 = F_77 ( V_42 -> V_48 ) ) {
if ( ! ( V_42 -> V_114 & V_183 ) )
V_26 -> V_4 . V_182 ( V_2 , V_42 ) ;
}
}
V_26 -> V_157 = V_26 -> V_4 . V_157 ;
} else {
V_26 -> V_157 -= V_26 -> V_4 . V_181 ;
}
F_79 () ;
F_100 ( V_2 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_11 ( V_2 -> V_31 ) ;
if ( V_26 -> V_4 . V_181 > V_26 -> V_4 . V_157 )
V_26 -> V_4 . V_181 = V_26 -> V_4 . V_157 ;
V_26 -> V_156 . V_15 = ( unsigned long ) V_2 ;
V_26 -> V_156 . V_184 = F_99 ;
V_26 -> V_156 . V_185 = V_161 + ( V_26 -> V_4 . V_181 * V_186 ) ;
F_101 ( & V_26 -> V_156 ) ;
}
static struct V_25 * F_31 ( struct V_1 * V_2 , int * V_27 )
{
int V_7 ;
struct V_3 * V_187 = V_188 ;
struct V_25 * V_26 ;
for( V_7 = 0 ; V_7 < V_189 ; V_7 ++ , V_187 ++ ) {
if ( V_187 -> type == V_2 -> type )
break;
}
* V_27 = - V_83 ;
if ( V_7 == V_189 )
return NULL ;
* V_27 = - V_90 ;
if ( ( V_26 = F_15 ( sizeof( struct V_25 ) , V_141 ) ) == NULL )
return NULL ;
memcpy ( & V_26 -> V_4 , V_187 , sizeof( struct V_3 ) ) ;
F_29 ( V_2 -> V_31 , V_26 ) ;
V_26 -> V_2 = V_2 ;
F_102 ( & V_26 -> V_156 ) ;
V_26 -> V_162 = V_161 ;
V_26 -> V_190 = F_103 ( V_2 , & V_191 ) ;
if ( ! V_26 -> V_190 ) {
F_29 ( V_2 -> V_31 , NULL ) ;
F_6 ( V_26 ) ;
return NULL ;
}
if ( V_26 -> V_4 . V_34 ) {
if ( V_26 -> V_4 . V_34 ( V_2 ) < 0 ) {
F_104 ( & V_191 , V_26 -> V_190 ) ;
V_2 -> V_31 = NULL ;
F_6 ( V_26 ) ;
return NULL ;
}
}
F_1 ( V_2 , & V_26 -> V_4 ) ;
F_100 ( V_2 ) ;
* V_27 = 0 ;
return V_26 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
V_87 V_134 = V_192 ;
int V_193 = 0 ;
struct V_25 * V_26 = F_19 ( V_2 -> V_31 ) ;
if ( ( V_2 -> type != V_37 ) && ( V_2 -> type != V_40 ) )
return;
if ( V_26 == NULL ) {
int V_27 ;
V_26 = F_31 ( V_2 , & V_27 ) ;
if ( V_26 == NULL )
return;
}
if ( V_2 -> type == V_37 ) {
if ( memcmp ( V_2 -> V_50 , V_151 , 4 ) != 0 )
return;
V_134 = F_21 ( V_2 -> V_50 ) ;
V_193 = 1 ;
}
if ( V_134 == 0 )
return;
if ( ( V_42 = F_14 () ) == NULL )
return;
V_42 -> V_49 = V_42 -> V_91 = V_134 ;
V_42 -> V_114 = 0 ;
V_42 -> V_62 = V_194 ;
strcpy ( V_42 -> V_85 , V_2 -> V_16 ) ;
F_30 ( V_2 , V_42 ) ;
if ( V_193 ) {
F_43 ( V_2 ) ;
if ( F_45 ( V_2 , 0 ) )
F_46 ( V_2 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_19 ( V_2 -> V_31 ) ;
if ( V_26 == NULL )
return;
F_106 ( & V_26 -> V_156 ) ;
F_7 ( & V_26 -> V_4 ) ;
F_47 ( V_2 ) ;
F_107 ( & V_191 , V_2 ) ;
if ( V_26 -> V_4 . V_33 )
V_26 -> V_4 . V_33 ( V_2 ) ;
V_2 -> V_31 = NULL ;
F_104 ( & V_191 , V_26 -> V_190 ) ;
F_107 ( & V_191 , V_2 ) ;
if ( V_26 -> V_153 )
F_108 ( V_26 -> V_153 ) ;
if ( V_26 -> V_195 )
F_108 ( V_26 -> V_195 ) ;
F_6 ( V_26 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_19 ( V_2 -> V_31 ) ;
struct V_41 * V_42 ;
if ( V_26 == NULL )
return;
while ( ( V_42 = F_19 ( V_26 -> V_54 ) ) != NULL ) {
F_18 ( V_26 , & V_26 -> V_54 , 0 ) ;
F_16 ( V_42 ) ;
}
F_26 ( V_2 ) ;
}
void F_110 ( struct V_97 * V_98 )
{
}
void F_111 ( struct V_97 * V_98 )
{
}
void F_112 ( struct V_97 * V_98 )
{
}
void F_113 ( void )
{
struct V_1 * V_2 ;
F_36 () ;
F_114 (&init_net, dev)
F_109 ( V_2 ) ;
F_39 () ;
}
void F_115 ( void )
{
struct V_1 * V_2 ;
F_36 () ;
F_114 (&init_net, dev) {
if ( V_2 -> V_60 & V_196 )
F_105 ( V_2 ) ;
}
F_39 () ;
}
int F_116 ( struct V_197 * V_198 )
{
return F_117 ( & V_52 , V_198 ) ;
}
int F_118 ( struct V_197 * V_198 )
{
return F_119 ( & V_52 , V_198 ) ;
}
static inline int F_120 ( struct V_1 * V_2 )
{
return V_2 -> V_31 != NULL ;
}
static void * F_121 ( struct V_199 * V_116 , T_4 * V_200 )
__acquires( T_8 )
{
int V_7 ;
struct V_1 * V_2 ;
F_75 () ;
if ( * V_200 == 0 )
return V_201 ;
V_7 = 1 ;
F_76 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
if ( V_7 ++ == * V_200 )
return V_2 ;
}
return NULL ;
}
static void * F_122 ( struct V_199 * V_116 , void * V_202 , T_4 * V_200 )
{
struct V_1 * V_2 ;
++ * V_200 ;
V_2 = (struct V_1 * ) V_202 ;
if ( V_202 == V_201 )
V_2 = F_123 ( & V_76 . V_203 ) ;
F_124 (&init_net, dev) {
if ( ! F_120 ( V_2 ) )
continue;
return V_2 ;
}
return NULL ;
}
static void F_125 ( struct V_199 * V_116 , void * V_202 )
__releases( T_8 )
{
F_79 () ;
}
static char * F_126 ( char type )
{
switch( type ) {
case V_204 :
return L_4 ;
case V_205 :
return L_5 ;
case V_206 :
return L_6 ;
}
return L_7 ;
}
static int F_127 ( struct V_199 * V_116 , void * V_202 )
{
if ( V_202 == V_201 )
F_128 ( V_116 , L_8 ) ;
else {
struct V_1 * V_2 = V_202 ;
char V_207 [ V_208 ] ;
char V_209 [ V_208 ] ;
struct V_25 * V_26 = F_77 ( V_2 -> V_31 ) ;
F_129 ( V_116 , L_9
L_10 ,
V_2 -> V_16 ? V_2 -> V_16 : L_11 ,
F_126 ( V_26 -> V_4 . V_210 ) ,
0 , 0 ,
V_26 -> V_157 , V_26 -> V_4 . V_157 ,
F_13 ( V_2 ) ,
V_26 -> V_4 . V_164 ,
V_26 -> V_4 . V_211 , V_26 -> V_4 . V_16 ,
V_26 -> V_153 ? F_130 ( F_90 ( * ( V_87 * ) V_26 -> V_153 -> V_212 ) , V_209 ) : L_12 ,
V_26 -> V_195 ? F_130 ( F_90 ( * ( V_87 * ) V_26 -> V_195 -> V_212 ) , V_207 ) : L_12 ) ;
}
return 0 ;
}
static int F_131 ( struct V_213 * V_213 , struct V_214 * V_214 )
{
return F_132 ( V_214 , & V_215 ) ;
}
void T_9 F_133 ( void )
{
if ( V_134 [ 0 ] > 63 || V_134 [ 0 ] < 0 ) {
F_134 ( V_216 L_13 ) ;
return;
}
if ( V_134 [ 1 ] > 1023 || V_134 [ 1 ] < 0 ) {
F_134 ( V_216 L_14 ) ;
return;
}
V_192 = F_85 ( ( V_134 [ 0 ] << 10 ) | V_134 [ 1 ] ) ;
F_115 () ;
F_135 ( V_217 , V_56 , F_57 , NULL ) ;
F_135 ( V_217 , V_51 , F_50 , NULL ) ;
F_135 ( V_217 , V_218 , NULL , F_74 ) ;
F_136 ( & V_76 , L_15 , V_219 , & V_220 ) ;
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_189 ; V_7 ++ )
F_1 ( NULL , & V_188 [ V_7 ] ) ;
}
#endif
}
void T_10 F_138 ( void )
{
#ifdef F_137
{
int V_7 ;
for( V_7 = 0 ; V_7 < V_189 ; V_7 ++ )
F_7 ( & V_188 [ V_7 ] ) ;
}
#endif
F_139 ( & V_76 , L_15 ) ;
F_113 () ;
}
