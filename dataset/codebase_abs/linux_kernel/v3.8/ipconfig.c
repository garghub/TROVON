static bool T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return false ;
return V_5 [ 0 ] ? ! strcmp ( V_2 -> V_6 , V_5 ) :
( ! ( V_2 -> V_3 & V_4 ) &&
( V_2 -> V_3 & ( V_7 | V_8 ) ) &&
strncmp ( V_2 -> V_6 , L_1 , 5 ) ) ;
}
static int T_1 F_2 ( void )
{
struct V_9 * V_10 , * * V_11 ;
struct V_1 * V_2 ;
unsigned short V_12 ;
unsigned long V_13 ;
V_11 = & V_14 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( ! ( V_2 -> V_3 & V_4 ) )
continue;
if ( F_5 ( V_2 , V_2 -> V_3 | V_15 ) < 0 )
F_6 ( L_2 , V_2 -> V_6 ) ;
}
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
int V_16 = 0 ;
if ( V_2 -> V_17 >= 364 )
V_16 |= V_18 ;
else
F_7 ( L_3 ,
V_2 -> V_6 , V_2 -> V_17 ) ;
if ( ! ( V_2 -> V_3 & V_19 ) )
V_16 |= V_20 ;
V_16 &= V_21 ;
if ( V_21 && ! V_16 )
continue;
V_12 = V_2 -> V_3 ;
if ( F_5 ( V_2 , V_12 | V_15 ) < 0 ) {
F_6 ( L_2 ,
V_2 -> V_6 ) ;
continue;
}
if ( ! ( V_10 = F_8 ( sizeof( struct V_9 ) , V_22 ) ) ) {
F_9 () ;
return - V_23 ;
}
V_10 -> V_2 = V_2 ;
* V_11 = V_10 ;
V_11 = & V_10 -> V_24 ;
V_10 -> V_3 = V_12 ;
V_10 -> V_16 = V_16 ;
if ( V_16 & V_18 )
F_10 ( & V_10 -> V_25 , sizeof( V_26 ) ) ;
else
V_10 -> V_25 = 0 ;
V_27 |= V_16 ;
F_11 ( ( L_4 ,
V_2 -> V_6 , V_16 , V_10 -> V_25 ) ) ;
}
}
if ( ! V_14 )
goto V_28;
V_13 = V_29 ;
while ( V_29 - V_13 < F_12 ( V_30 ) ) {
F_4 (&init_net, dev)
if ( F_1 ( V_2 ) && F_13 ( V_2 ) )
goto V_28;
F_14 ( 1 ) ;
}
V_28:
F_9 () ;
* V_11 = NULL ;
if ( ! V_14 ) {
if ( V_5 [ 0 ] )
F_6 ( L_5 ,
V_5 ) ;
else
F_6 ( L_6 ) ;
return - V_31 ;
}
return 0 ;
}
static void T_1 F_15 ( void )
{
struct V_9 * V_10 , * V_24 ;
struct V_1 * V_2 ;
F_3 () ;
V_24 = V_14 ;
while ( ( V_10 = V_24 ) ) {
V_24 = V_10 -> V_24 ;
V_2 = V_10 -> V_2 ;
if ( V_2 != V_32 ) {
F_11 ( ( L_7 , V_2 -> V_6 ) ) ;
F_5 ( V_2 , V_10 -> V_3 ) ;
}
F_16 ( V_10 ) ;
}
F_9 () ;
}
static inline void
F_17 ( struct V_33 * sin , V_26 V_34 , T_2 V_35 )
{
sin -> V_36 = V_37 ;
sin -> V_38 . V_39 = V_34 ;
sin -> V_40 = V_35 ;
}
static int T_1 F_18 ( unsigned int V_41 , struct V_42 * V_43 )
{
int V_44 ;
T_3 V_45 = F_19 () ;
F_20 ( F_21 () ) ;
V_44 = F_22 ( & V_46 , V_41 , (struct V_42 V_47 * ) V_43 ) ;
F_20 ( V_45 ) ;
return V_44 ;
}
static int T_1 F_23 ( unsigned int V_41 , struct V_42 * V_43 )
{
int V_44 ;
T_3 V_45 = F_19 () ;
F_20 ( F_21 () ) ;
V_44 = F_24 ( & V_46 , V_41 , (struct V_42 V_47 * ) V_43 ) ;
F_20 ( V_45 ) ;
return V_44 ;
}
static int T_1 F_25 ( unsigned int V_41 , struct V_48 * V_43 )
{
int V_44 ;
T_3 V_45 = F_19 () ;
F_20 ( F_21 () ) ;
V_44 = F_26 ( & V_46 , V_41 , ( void V_47 * ) V_43 ) ;
F_20 ( V_45 ) ;
return V_44 ;
}
static int T_1 F_27 ( void )
{
struct V_42 V_49 ;
struct V_33 * sin = ( void * ) & V_49 . V_50 . V_51 ;
int V_52 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
strcpy ( V_49 . V_53 . V_54 , V_32 -> V_6 ) ;
F_17 ( sin , V_55 , 0 ) ;
if ( ( V_52 = F_18 ( V_56 , & V_49 ) ) < 0 ) {
F_6 ( L_8 ,
V_52 ) ;
return - 1 ;
}
F_17 ( sin , V_57 , 0 ) ;
if ( ( V_52 = F_18 ( V_58 , & V_49 ) ) < 0 ) {
F_6 ( L_9 ,
V_52 ) ;
return - 1 ;
}
F_17 ( sin , V_55 | ~ V_57 , 0 ) ;
if ( ( V_52 = F_18 ( V_59 , & V_49 ) ) < 0 ) {
F_6 ( L_10 ,
V_52 ) ;
return - 1 ;
}
if ( V_60 != 0 ) {
strcpy ( V_49 . V_61 , V_32 -> V_6 ) ;
V_49 . V_62 = V_60 ;
if ( ( V_52 = F_23 ( V_63 , & V_49 ) ) < 0 )
F_6 ( L_11 ,
V_60 , V_52 ) ;
}
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( V_64 != V_65 ) {
struct V_48 V_66 ;
int V_52 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( ( V_64 ^ V_55 ) & V_57 ) {
F_6 ( L_12 ) ;
return - 1 ;
}
F_17 ( (struct V_33 * ) & V_66 . V_67 , 0 , 0 ) ;
F_17 ( (struct V_33 * ) & V_66 . V_68 , 0 , 0 ) ;
F_17 ( (struct V_33 * ) & V_66 . V_69 , V_64 , 0 ) ;
V_66 . V_70 = V_71 | V_72 ;
if ( ( V_52 = F_25 ( V_73 , & V_66 ) ) < 0 ) {
F_6 ( L_13 ,
V_52 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_1 F_29 ( void )
{
if ( ! V_74 )
sprintf ( F_30 () -> V_75 , L_14 , & V_55 ) ;
if ( V_76 == V_65 )
V_76 = V_77 ;
if ( V_57 == V_65 ) {
if ( F_31 ( F_32 ( V_55 ) ) )
V_57 = F_33 ( V_78 ) ;
else if ( F_34 ( F_32 ( V_55 ) ) )
V_57 = F_33 ( V_79 ) ;
else if ( F_35 ( F_32 ( V_55 ) ) )
V_57 = F_33 ( V_80 ) ;
else {
F_6 ( L_15 ,
& V_55 ) ;
return - 1 ;
}
F_36 ( L_16 , & V_57 ) ;
}
return 0 ;
}
static inline void T_1 F_37 ( void )
{
F_38 ( & V_81 ) ;
}
static inline void T_1 F_39 ( void )
{
F_40 ( & V_81 ) ;
}
static int T_1
F_41 ( struct V_82 * V_83 , struct V_1 * V_2 , struct V_84 * V_85 , struct V_1 * V_86 )
{
struct V_87 * V_88 ;
unsigned char * V_89 ;
V_26 V_90 , V_91 ;
unsigned char * V_92 , * V_93 ;
struct V_9 * V_10 ;
if ( ! F_42 ( F_43 ( V_2 ) , & V_46 ) )
goto V_94;
if ( ( V_83 = F_44 ( V_83 , V_95 ) ) == NULL )
return V_96 ;
if ( ! F_45 ( V_83 , sizeof( struct V_87 ) ) )
goto V_94;
V_88 = (struct V_87 * ) F_46 ( V_83 ) ;
if ( V_88 -> V_97 != V_2 -> V_98 || V_2 -> type != F_47 ( V_88 -> V_99 ) )
goto V_94;
if ( V_88 -> V_100 != F_48 ( V_101 ) )
goto V_94;
if ( V_88 -> V_102 != F_48 ( V_103 ) )
goto V_94;
if ( ! F_45 ( V_83 , F_49 ( V_2 ) ) )
goto V_94;
V_88 = (struct V_87 * ) F_46 ( V_83 ) ;
V_89 = ( unsigned char * ) ( V_88 + 1 ) ;
F_50 ( & V_104 ) ;
if ( V_105 )
goto V_106;
V_10 = V_14 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_24 ;
if ( ! V_10 )
goto V_106;
V_92 = V_89 ;
V_89 += V_2 -> V_98 ;
memcpy ( & V_90 , V_89 , 4 ) ;
V_89 += 4 ;
V_93 = V_89 ;
V_89 += V_2 -> V_98 ;
memcpy ( & V_91 , V_89 , 4 ) ;
if ( memcmp ( V_93 , V_2 -> V_107 , V_2 -> V_98 ) )
goto V_106;
if ( V_77 != V_65 && V_77 != V_90 )
goto V_106;
V_32 = V_2 ;
if ( V_55 == V_65 )
V_55 = V_91 ;
V_77 = V_90 ;
V_108 = V_90 ;
V_105 = V_20 ;
V_106:
F_51 ( & V_104 ) ;
V_94:
F_52 ( V_83 ) ;
return 0 ;
}
static void T_1 F_53 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_54 ( V_109 , V_110 , 0 , V_2 , 0 , NULL ,
V_2 -> V_107 , V_2 -> V_107 ) ;
}
static inline void T_1 F_55 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
V_113 [ V_111 ] = V_65 ;
}
static void T_1
F_56 ( T_4 * V_114 )
{
T_4 V_115 = ( ( V_77 == V_65 )
? V_116 : V_117 ) ;
T_4 * V_118 = V_114 ;
int V_119 ;
#ifdef F_57
F_36 ( L_17 , V_115 ) ;
#endif
memcpy ( V_118 , V_120 , 4 ) ;
V_118 += 4 ;
* V_118 ++ = 53 ;
* V_118 ++ = 1 ;
* V_118 ++ = V_115 ;
if ( V_115 == V_117 ) {
* V_118 ++ = 54 ;
* V_118 ++ = 4 ;
memcpy ( V_118 , & V_77 , 4 ) ;
V_118 += 4 ;
* V_118 ++ = 50 ;
* V_118 ++ = 4 ;
memcpy ( V_118 , & V_55 , 4 ) ;
V_118 += 4 ;
}
{
static const T_4 V_121 [] = {
1 ,
3 ,
6 ,
12 ,
15 ,
17 ,
26 ,
40 ,
} ;
* V_118 ++ = 55 ;
* V_118 ++ = sizeof( V_121 ) ;
memcpy ( V_118 , V_121 , sizeof( V_121 ) ) ;
V_118 += sizeof( V_121 ) ;
if ( V_74 ) {
* V_118 ++ = 12 ;
V_119 = strlen ( F_58 () -> V_75 ) ;
* V_118 ++ = V_119 ;
memcpy ( V_118 , F_58 () -> V_75 , V_119 ) ;
V_118 += V_119 ;
}
if ( * V_122 ) {
F_59 ( L_18 ,
V_122 ) ;
* V_118 ++ = 60 ;
V_119 = strlen ( V_122 ) ;
* V_118 ++ = V_119 ;
memcpy ( V_118 , V_122 , V_119 ) ;
V_118 += V_119 ;
}
}
* V_118 ++ = 255 ;
}
static void T_1 F_60 ( T_4 * V_118 )
{
memcpy ( V_118 , V_120 , 4 ) ;
V_118 += 4 ;
* V_118 ++ = 1 ;
* V_118 ++ = 4 ;
V_118 += 4 ;
* V_118 ++ = 3 ;
* V_118 ++ = 4 ;
V_118 += 4 ;
* V_118 ++ = 5 ;
* V_118 ++ = 8 ;
V_118 += 8 ;
* V_118 ++ = 12 ;
* V_118 ++ = 32 ;
V_118 += 32 ;
* V_118 ++ = 40 ;
* V_118 ++ = 32 ;
V_118 += 32 ;
* V_118 ++ = 17 ;
* V_118 ++ = 40 ;
V_118 += 40 ;
* V_118 ++ = 57 ;
* V_118 ++ = 2 ;
* V_118 ++ = 1 ;
* V_118 ++ = 150 ;
* V_118 ++ = 255 ;
}
static inline void T_1 F_61 ( void )
{
F_55 () ;
F_38 ( & V_123 ) ;
}
static inline void T_1 F_62 ( void )
{
F_40 ( & V_123 ) ;
}
static void T_1 F_63 ( struct V_9 * V_10 , unsigned long V_124 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_82 * V_83 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_129 = F_64 ( V_2 ) ;
int V_130 = V_2 -> V_131 ;
V_83 = F_65 ( sizeof( struct V_125 ) + V_129 + V_130 + 15 ,
V_22 ) ;
if ( ! V_83 )
return;
F_66 ( V_83 , V_129 ) ;
V_126 = (struct V_125 * ) F_67 ( V_83 , sizeof( struct V_125 ) ) ;
memset ( V_126 , 0 , sizeof( struct V_125 ) ) ;
F_68 ( V_83 ) ;
V_128 = F_69 ( V_83 ) ;
V_128 -> V_132 = 4 ;
V_128 -> V_133 = 5 ;
V_128 -> V_134 = F_48 ( sizeof( struct V_125 ) ) ;
V_128 -> V_135 = F_48 ( V_136 ) ;
V_128 -> V_137 = 64 ;
V_128 -> V_138 = V_139 ;
V_128 -> V_140 = F_33 ( V_141 ) ;
V_128 -> V_142 = F_70 ( ( unsigned char * ) V_128 , V_128 -> V_133 ) ;
V_126 -> V_143 . V_144 = F_48 ( 68 ) ;
V_126 -> V_143 . V_145 = F_48 ( 67 ) ;
V_126 -> V_143 . V_119 = F_48 ( sizeof( struct V_125 ) - sizeof( struct V_127 ) ) ;
V_126 -> V_146 = V_147 ;
if ( V_2 -> type < 256 )
V_126 -> V_148 = V_2 -> type ;
else if ( V_2 -> type == V_149 )
V_126 -> V_148 = V_150 ;
else {
F_36 ( L_19 , V_2 -> type , V_2 -> V_6 ) ;
V_126 -> V_148 = V_2 -> type ;
}
V_126 -> V_129 = V_2 -> V_98 ;
memcpy ( V_126 -> V_151 , V_2 -> V_107 , V_2 -> V_98 ) ;
V_126 -> V_152 = F_48 ( V_124 / V_153 ) ;
V_126 -> V_25 = V_10 -> V_25 ;
#ifdef F_71
if ( V_21 & V_154 )
F_56 ( V_126 -> V_155 ) ;
else
#endif
F_60 ( V_126 -> V_155 ) ;
V_83 -> V_2 = V_2 ;
V_83 -> V_138 = F_48 ( V_103 ) ;
if ( F_72 ( V_83 , V_2 , F_47 ( V_83 -> V_138 ) ,
V_2 -> V_156 , V_2 -> V_107 , V_83 -> V_119 ) < 0 ) {
F_52 ( V_83 ) ;
F_36 ( L_20 ) ;
return;
}
if ( F_73 ( V_83 ) < 0 )
F_36 ( L_20 ) ;
}
static int T_1 F_74 ( char * V_145 , char * V_157 , int V_119 , int V_158 )
{
if ( ! V_119 )
return 0 ;
if ( V_119 > V_158 - 1 )
V_119 = V_158 - 1 ;
memcpy ( V_145 , V_157 , V_119 ) ;
V_145 [ V_119 ] = '\0' ;
return 1 ;
}
static void T_1 F_75 ( T_4 * V_159 )
{
T_4 V_160 ;
int V_111 ;
T_2 V_17 ;
#ifdef F_57
T_4 * V_161 ;
F_36 ( L_21 , * V_159 ) ;
for ( V_161 = V_159 + 2 ; V_161 < V_159 + 2 + V_159 [ 1 ] ; V_161 ++ )
F_36 ( L_22 , * V_161 ) ;
F_36 ( L_23 ) ;
#endif
switch ( * V_159 ++ ) {
case 1 :
if ( V_57 == V_65 )
memcpy ( & V_57 , V_159 + 1 , 4 ) ;
break;
case 3 :
if ( V_64 == V_65 )
memcpy ( & V_64 , V_159 + 1 , 4 ) ;
break;
case 6 :
V_160 = * V_159 / 4 ;
if ( V_160 > V_112 )
V_160 = V_112 ;
for ( V_111 = 0 ; V_111 < V_160 ; V_111 ++ ) {
if ( V_113 [ V_111 ] == V_65 )
memcpy ( & V_113 [ V_111 ] , V_159 + 1 + 4 * V_111 , 4 ) ;
}
break;
case 12 :
F_74 ( F_58 () -> V_75 , V_159 + 1 , * V_159 ,
V_162 ) ;
V_74 = 1 ;
break;
case 15 :
F_74 ( V_163 , V_159 + 1 , * V_159 , sizeof( V_163 ) ) ;
break;
case 17 :
if ( ! V_164 [ 0 ] )
F_74 ( V_164 , V_159 + 1 , * V_159 ,
sizeof( V_164 ) ) ;
break;
case 26 :
memcpy ( & V_17 , V_159 + 1 , sizeof( V_17 ) ) ;
V_60 = F_47 ( V_17 ) ;
break;
case 40 :
F_74 ( F_58 () -> V_165 , V_159 + 1 , * V_159 ,
V_162 ) ;
break;
}
}
static int T_1 F_76 ( struct V_82 * V_83 , struct V_1 * V_2 , struct V_84 * V_85 , struct V_1 * V_86 )
{
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_9 * V_10 ;
int V_119 , V_166 ;
if ( ! F_42 ( F_43 ( V_2 ) , & V_46 ) )
goto V_94;
if ( V_83 -> V_167 == V_168 )
goto V_94;
if ( ( V_83 = F_44 ( V_83 , V_95 ) ) == NULL )
return V_96 ;
if ( ! F_45 ( V_83 ,
sizeof( struct V_127 ) +
sizeof( struct V_169 ) ) )
goto V_94;
V_126 = (struct V_125 * ) F_77 ( V_83 ) ;
V_128 = & V_126 -> V_170 ;
if ( V_128 -> V_133 != 5 || V_128 -> V_132 != 4 || V_128 -> V_138 != V_139 )
goto V_94;
if ( F_78 ( V_128 ) ) {
F_79 ( L_24 ) ;
goto V_94;
}
if ( V_83 -> V_119 < F_47 ( V_128 -> V_134 ) )
goto V_94;
if ( F_70 ( ( char * ) V_128 , V_128 -> V_133 ) )
goto V_94;
if ( V_126 -> V_143 . V_144 != F_48 ( 67 ) || V_126 -> V_143 . V_145 != F_48 ( 68 ) )
goto V_94;
if ( F_47 ( V_128 -> V_134 ) < F_47 ( V_126 -> V_143 . V_119 ) + sizeof( struct V_127 ) )
goto V_94;
V_119 = F_47 ( V_126 -> V_143 . V_119 ) - sizeof( struct V_169 ) ;
V_166 = V_119 - ( sizeof( * V_126 ) -
sizeof( struct V_127 ) -
sizeof( struct V_169 ) -
sizeof( V_126 -> V_155 ) ) ;
if ( V_166 < 0 )
goto V_94;
if ( ! F_45 ( V_83 , V_83 -> V_119 ) )
goto V_94;
V_126 = (struct V_125 * ) F_77 ( V_83 ) ;
V_128 = & V_126 -> V_170 ;
F_50 ( & V_104 ) ;
if ( V_105 )
goto V_106;
V_10 = V_14 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_24 ;
if ( ! V_10 )
goto V_106;
if ( V_126 -> V_146 != V_171 ||
V_126 -> V_25 != V_10 -> V_25 ) {
F_79 ( L_25 ,
V_126 -> V_146 , V_126 -> V_25 ) ;
goto V_106;
}
if ( V_126 -> V_25 != V_172 ) {
F_79 ( L_26 ) ;
goto V_106;
}
if ( V_166 >= 4 &&
! memcmp ( V_126 -> V_155 , V_120 , 4 ) ) {
T_4 * V_173 = ( T_4 * ) V_126 + F_47 ( V_126 -> V_170 . V_134 ) ;
T_4 * V_159 ;
#ifdef F_71
if ( V_21 & V_154 ) {
V_26 V_174 = V_65 ;
int V_115 = 0 ;
V_159 = & V_126 -> V_155 [ 4 ] ;
while ( V_159 < V_173 && * V_159 != 0xff ) {
T_4 * V_175 = V_159 ++ ;
if ( * V_175 == 0 )
continue;
V_159 += * V_159 + 1 ;
if ( V_159 >= V_173 )
break;
switch ( * V_175 ) {
case 53 :
if ( V_175 [ 1 ] )
V_115 = V_175 [ 2 ] ;
break;
case 54 :
if ( V_175 [ 1 ] >= 4 )
memcpy ( & V_174 , V_175 + 2 , 4 ) ;
break;
}
}
#ifdef F_57
F_36 ( L_27 , V_115 ) ;
#endif
switch ( V_115 ) {
case V_176 :
if ( V_55 != V_65 )
goto V_106;
V_55 = V_126 -> V_177 ;
V_77 = V_174 ;
#ifdef F_57
F_36 ( L_28 ,
& V_55 , & V_126 -> V_170 . V_178 ) ;
#endif
if ( ( V_174 != V_65 ) &&
( V_126 -> V_179 != V_174 ) )
V_126 -> V_179 = V_77 ;
break;
case V_180 :
if ( memcmp ( V_2 -> V_107 , V_126 -> V_151 , V_2 -> V_98 ) != 0 )
goto V_106;
break;
default:
V_55 = V_65 ;
V_77 = V_65 ;
goto V_106;
}
V_181 = V_115 ;
}
#endif
V_159 = & V_126 -> V_155 [ 4 ] ;
while ( V_159 < V_173 && * V_159 != 0xff ) {
T_4 * V_175 = V_159 ++ ;
if ( * V_175 == 0 )
continue;
V_159 += * V_159 + 1 ;
if ( V_159 < V_173 )
F_75 ( V_175 ) ;
}
}
V_32 = V_2 ;
V_55 = V_126 -> V_177 ;
V_77 = V_126 -> V_179 ;
V_108 = V_126 -> V_170 . V_178 ;
if ( V_64 == V_65 && V_126 -> V_182 )
V_64 = V_126 -> V_182 ;
if ( V_113 [ 0 ] == V_65 )
V_113 [ 0 ] = V_77 ;
V_105 = V_18 ;
V_106:
F_51 ( & V_104 ) ;
V_94:
F_52 ( V_83 ) ;
return 0 ;
}
static int T_1 F_80 ( void )
{
int V_183 ;
struct V_9 * V_10 ;
unsigned long V_184 , V_185 , V_186 ;
int V_187 = V_27 & V_18 ;
int V_188 = V_27 & V_20 ;
if ( ! V_21 ) {
F_6 ( L_29 ) ;
return - 1 ;
}
#ifdef F_81
if ( ( V_21 ^ V_27 ) & V_18 )
F_6 ( L_30 ) ;
#endif
#ifdef F_82
if ( ( V_21 ^ V_27 ) & V_20 )
F_6 ( L_31 ) ;
#endif
if ( ! V_27 )
return - 1 ;
#ifdef F_81
if ( V_187 )
F_61 () ;
#endif
#ifdef F_82
if ( V_188 )
F_37 () ;
#endif
F_83 ( L_32 ,
V_187
? ( ( V_21 & V_154 ) ? L_33 : L_34 ) : L_35 ,
( V_187 && V_188 ) ? L_36 : L_35 ,
V_188 ? L_37 : L_35 ) ;
V_184 = V_29 ;
V_10 = V_14 ;
V_183 = V_189 ;
F_10 ( & V_185 , sizeof( V_185 ) ) ;
V_185 = V_190 + ( V_185 % ( unsigned int ) V_191 ) ;
for (; ; ) {
V_172 = V_10 -> V_25 ;
#ifdef F_81
if ( V_187 && ( V_10 -> V_16 & V_18 ) )
F_63 ( V_10 , V_29 - V_184 ) ;
#endif
#ifdef F_82
if ( V_188 && ( V_10 -> V_16 & V_20 ) )
F_53 ( V_10 ) ;
#endif
V_186 = V_29 + ( V_10 -> V_24 ? V_192 : V_185 ) ;
while ( F_84 ( V_29 , V_186 ) && ! V_105 )
F_85 ( 1 ) ;
#ifdef F_71
if ( ( V_105 & V_18 ) &&
( V_21 & V_154 ) &&
V_181 != V_180 ) {
V_105 = 0 ;
F_86 ( L_38 ) ;
continue;
}
#endif
if ( V_105 ) {
F_86 ( L_39 ) ;
break;
}
if ( ( V_10 = V_10 -> V_24 ) )
continue;
if ( ! -- V_183 ) {
F_86 ( L_40 ) ;
break;
}
V_10 = V_14 ;
V_185 = V_185 V_193 ;
if ( V_185 > V_194 )
V_185 = V_194 ;
F_86 ( L_41 ) ;
}
#ifdef F_81
if ( V_187 )
F_62 () ;
#endif
#ifdef F_82
if ( V_188 )
F_39 () ;
#endif
if ( ! V_105 ) {
V_55 = V_65 ;
return - 1 ;
}
F_36 ( L_42 ,
( ( V_105 & V_20 ) ? L_37
: ( V_21 & V_154 ) ? L_33 : L_34 ) ,
& V_108 ) ;
F_86 ( L_43 , & V_55 ) ;
return 0 ;
}
static int F_87 ( struct V_195 * V_196 , void * V_197 )
{
int V_111 ;
if ( V_198 & V_199 )
F_88 ( V_196 , L_44 ,
( V_198 & V_20 ) ? L_37
: ( V_198 & V_154 ) ? L_33 : L_34 ) ;
else
F_89 ( V_196 , L_45 ) ;
if ( V_163 [ 0 ] )
F_88 ( V_196 ,
L_46 , V_163 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
if ( V_113 [ V_111 ] != V_65 )
F_88 ( V_196 , L_47 ,
& V_113 [ V_111 ] ) ;
}
if ( V_77 != V_65 )
F_88 ( V_196 , L_48 ,
& V_77 ) ;
return 0 ;
}
static int F_90 ( struct V_200 * V_201 , struct V_202 * V_202 )
{
return F_91 ( V_202 , F_87 , NULL ) ;
}
V_26 T_1 F_92 ( char * V_6 )
{
V_26 V_34 ;
int V_203 = 0 ;
char * V_204 , * V_205 ;
V_204 = V_205 = V_6 ;
while ( V_203 < 4 ) {
while ( * V_204 >= '0' && * V_204 <= '9' )
V_204 ++ ;
if ( V_204 == V_205 || V_204 - V_205 > 3 )
break;
if ( * V_204 == '.' || V_203 == 3 )
V_203 ++ ;
if ( V_203 < 4 )
V_204 ++ ;
V_205 = V_204 ;
}
if ( V_203 == 4 && ( * V_204 == ':' || * V_204 == '\0' ) ) {
if ( * V_204 == ':' )
* V_204 ++ = '\0' ;
V_34 = F_93 ( V_6 ) ;
memmove ( V_6 , V_204 , strlen ( V_204 ) + 1 ) ;
} else
V_34 = V_65 ;
return V_34 ;
}
static int T_1 F_94 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_206 ; V_111 ++ ) {
struct V_1 * V_2 ;
int V_207 = 0 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
V_207 = 1 ;
break;
}
}
F_9 () ;
if ( V_207 )
return 0 ;
F_95 ( 1 ) ;
}
return - V_31 ;
}
static int T_1 F_96 ( void )
{
V_26 V_34 ;
#ifdef F_97
int V_183 = V_208 ;
#endif
int V_52 ;
unsigned int V_111 ;
#ifdef F_98
F_99 ( & V_46 , L_49 , V_209 , & V_210 ) ;
#endif
if ( ! V_211 )
return 0 ;
F_11 ( ( L_50 ) ) ;
#ifdef F_97
V_212:
#endif
V_52 = F_94 () ;
if ( V_52 )
return V_52 ;
V_52 = F_2 () ;
if ( V_52 )
return V_52 ;
F_14 ( V_213 ) ;
if ( V_55 == V_65 ||
#ifdef F_100
( V_76 == V_65 &&
V_77 == V_65 &&
V_214 == V_215 ) ||
#endif
V_14 -> V_24 ) {
#ifdef F_97
if ( F_80 () < 0 ) {
F_15 () ;
#ifdef F_100
if ( V_214 == V_215 ) {
F_6 ( L_51 ) ;
goto V_212;
}
#endif
if ( -- V_183 ) {
F_6 ( L_52 ) ;
goto V_212;
}
F_6 ( L_53 ) ;
return - 1 ;
}
#else
F_6 ( L_29 ) ;
F_15 () ;
return - 1 ;
#endif
} else {
V_32 = V_14 -> V_2 ;
}
V_34 = F_92 ( V_164 ) ;
if ( V_76 == V_65 )
V_76 = V_34 ;
if ( F_29 () < 0 )
return - 1 ;
F_15 () ;
if ( F_27 () < 0 || F_28 () < 0 )
return - 1 ;
#ifdef F_97
V_198 = V_105 | ( V_21 & V_154 ) ;
#endif
#ifndef F_101
F_59 ( L_54 ) ;
F_59 ( L_55 ,
V_32 -> V_6 , V_32 -> V_98 , V_32 -> V_107 ,
& V_55 , & V_57 , & V_64 ) ;
F_59 ( L_56 ,
F_58 () -> V_75 , V_163 , F_58 () -> V_165 ) ;
F_59 ( L_57 ,
& V_77 , & V_76 , V_164 ) ;
if ( V_60 )
F_86 ( L_58 , V_60 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
if ( V_113 [ V_111 ] != V_65 ) {
F_59 ( L_59 ,
V_111 , & V_113 [ V_111 ] ) ;
break;
}
for ( V_111 ++ ; V_111 < V_112 ; V_111 ++ )
if ( V_113 [ V_111 ] != V_65 )
F_86 ( L_60 , V_111 , & V_113 [ V_111 ] ) ;
#endif
return 0 ;
}
static int T_1 F_102 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_61 ) || ! strcmp ( V_6 , L_62 ) ) {
return 1 ;
}
if ( ! strcmp ( V_6 , L_63 ) || ! strcmp ( V_6 , L_64 ) ) {
return 0 ;
}
#ifdef F_103
else if ( ! strcmp ( V_6 , L_65 ) ) {
V_21 &= ~ V_20 ;
return 1 ;
}
#endif
#ifdef F_104
else if ( ! strcmp ( V_6 , L_66 ) ) {
V_21 &= ~ ( V_20 | V_154 ) ;
return 1 ;
}
#endif
#ifdef F_105
else if ( ! strcmp ( V_6 , L_67 ) ) {
V_21 &= ~ ( V_18 | V_154 ) ;
return 1 ;
}
#endif
#ifdef F_97
else if ( ! strcmp ( V_6 , L_68 ) ) {
V_21 &= ~ V_154 ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_106 ( char * V_216 )
{
char * V_204 , * V_217 , * V_218 ;
int V_219 = 0 ;
V_220 = 1 ;
V_211 = 1 ;
if ( F_102 ( V_216 ) )
return 1 ;
if ( * V_216 == 0 ||
strcmp ( V_216 , L_63 ) == 0 ||
strcmp ( V_216 , L_64 ) == 0 ) {
V_211 = 0 ;
return 1 ;
}
F_55 () ;
V_217 = V_216 ;
while ( V_217 && * V_217 ) {
if ( ( V_204 = strchr ( V_217 , ':' ) ) )
* V_204 ++ = '\0' ;
if ( strlen ( V_217 ) > 0 ) {
F_11 ( ( L_69 , V_219 , V_217 ) ) ;
switch ( V_219 ) {
case 0 :
if ( ( V_55 = F_93 ( V_217 ) ) == V_221 )
V_55 = V_65 ;
break;
case 1 :
if ( ( V_77 = F_93 ( V_217 ) ) == V_221 )
V_77 = V_65 ;
break;
case 2 :
if ( ( V_64 = F_93 ( V_217 ) ) == V_221 )
V_64 = V_65 ;
break;
case 3 :
if ( ( V_57 = F_93 ( V_217 ) ) == V_221 )
V_57 = V_65 ;
break;
case 4 :
if ( ( V_218 = strchr ( V_217 , '.' ) ) ) {
* V_218 ++ = '\0' ;
F_107 ( F_58 () -> V_165 , V_218 ,
sizeof( F_58 () -> V_165 ) ) ;
}
F_107 ( F_58 () -> V_75 , V_217 ,
sizeof( F_58 () -> V_75 ) ) ;
V_74 = 1 ;
break;
case 5 :
F_107 ( V_5 , V_217 , sizeof( V_5 ) ) ;
break;
case 6 :
if ( F_102 ( V_217 ) == 0 &&
V_55 == V_65 ) {
V_211 = 0 ;
}
break;
case 7 :
if ( V_112 >= 1 ) {
V_113 [ 0 ] = F_93 ( V_217 ) ;
if ( V_113 [ 0 ] == V_221 )
V_113 [ 0 ] = V_65 ;
}
break;
case 8 :
if ( V_112 >= 2 ) {
V_113 [ 1 ] = F_93 ( V_217 ) ;
if ( V_113 [ 1 ] == V_221 )
V_113 [ 1 ] = V_65 ;
}
break;
}
}
V_217 = V_204 ;
V_219 ++ ;
}
return 1 ;
}
static int T_1 F_108 ( char * V_216 )
{
return F_106 ( V_216 ) ;
}
static int T_1 F_109 ( char * V_216 )
{
if ( F_107 ( V_122 , V_216 ,
sizeof( V_122 ) )
>= sizeof( V_122 ) )
F_7 ( L_70 ,
V_122 ) ;
return 1 ;
}
