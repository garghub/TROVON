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
F_54 ( V_108 , V_109 , 0 , V_2 , 0 , NULL ,
V_2 -> V_107 , V_2 -> V_107 ) ;
}
static void T_1
F_55 ( T_4 * V_110 )
{
T_4 V_111 = ( ( V_77 == V_65 )
? V_112 : V_113 ) ;
T_4 * V_114 = V_110 ;
int V_115 ;
#ifdef F_56
F_36 ( L_17 , V_111 ) ;
#endif
memcpy ( V_114 , V_116 , 4 ) ;
V_114 += 4 ;
* V_114 ++ = 53 ;
* V_114 ++ = 1 ;
* V_114 ++ = V_111 ;
if ( V_111 == V_113 ) {
* V_114 ++ = 54 ;
* V_114 ++ = 4 ;
memcpy ( V_114 , & V_77 , 4 ) ;
V_114 += 4 ;
* V_114 ++ = 50 ;
* V_114 ++ = 4 ;
memcpy ( V_114 , & V_55 , 4 ) ;
V_114 += 4 ;
}
{
static const T_4 V_117 [] = {
1 ,
3 ,
6 ,
12 ,
15 ,
17 ,
26 ,
40 ,
} ;
* V_114 ++ = 55 ;
* V_114 ++ = sizeof( V_117 ) ;
memcpy ( V_114 , V_117 , sizeof( V_117 ) ) ;
V_114 += sizeof( V_117 ) ;
if ( V_74 ) {
* V_114 ++ = 12 ;
V_115 = strlen ( F_57 () -> V_75 ) ;
* V_114 ++ = V_115 ;
memcpy ( V_114 , F_57 () -> V_75 , V_115 ) ;
V_114 += V_115 ;
}
if ( * V_118 ) {
F_58 ( L_18 ,
V_118 ) ;
* V_114 ++ = 60 ;
V_115 = strlen ( V_118 ) ;
* V_114 ++ = V_115 ;
memcpy ( V_114 , V_118 , V_115 ) ;
V_114 += V_115 ;
}
}
* V_114 ++ = 255 ;
}
static void T_1 F_59 ( T_4 * V_114 )
{
memcpy ( V_114 , V_116 , 4 ) ;
V_114 += 4 ;
* V_114 ++ = 1 ;
* V_114 ++ = 4 ;
V_114 += 4 ;
* V_114 ++ = 3 ;
* V_114 ++ = 4 ;
V_114 += 4 ;
* V_114 ++ = 5 ;
* V_114 ++ = 8 ;
V_114 += 8 ;
* V_114 ++ = 12 ;
* V_114 ++ = 32 ;
V_114 += 32 ;
* V_114 ++ = 40 ;
* V_114 ++ = 32 ;
V_114 += 32 ;
* V_114 ++ = 17 ;
* V_114 ++ = 40 ;
V_114 += 40 ;
* V_114 ++ = 57 ;
* V_114 ++ = 2 ;
* V_114 ++ = 1 ;
* V_114 ++ = 150 ;
* V_114 ++ = 255 ;
}
static inline void T_1 F_60 ( void )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ )
V_121 [ V_119 ] = V_65 ;
F_38 ( & V_122 ) ;
}
static inline void T_1 F_61 ( void )
{
F_40 ( & V_122 ) ;
}
static void T_1 F_62 ( struct V_9 * V_10 , unsigned long V_123 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_82 * V_83 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_128 = F_63 ( V_2 ) ;
int V_129 = V_2 -> V_130 ;
V_83 = F_64 ( sizeof( struct V_124 ) + V_128 + V_129 + 15 ,
V_22 ) ;
if ( ! V_83 )
return;
F_65 ( V_83 , V_128 ) ;
V_125 = (struct V_124 * ) F_66 ( V_83 , sizeof( struct V_124 ) ) ;
memset ( V_125 , 0 , sizeof( struct V_124 ) ) ;
F_67 ( V_83 ) ;
V_127 = F_68 ( V_83 ) ;
V_127 -> V_131 = 4 ;
V_127 -> V_132 = 5 ;
V_127 -> V_133 = F_48 ( sizeof( struct V_124 ) ) ;
V_127 -> V_134 = F_48 ( V_135 ) ;
V_127 -> V_136 = 64 ;
V_127 -> V_137 = V_138 ;
V_127 -> V_139 = F_33 ( V_140 ) ;
V_127 -> V_141 = F_69 ( ( unsigned char * ) V_127 , V_127 -> V_132 ) ;
V_125 -> V_142 . V_143 = F_48 ( 68 ) ;
V_125 -> V_142 . V_144 = F_48 ( 67 ) ;
V_125 -> V_142 . V_115 = F_48 ( sizeof( struct V_124 ) - sizeof( struct V_126 ) ) ;
V_125 -> V_145 = V_146 ;
if ( V_2 -> type < 256 )
V_125 -> V_147 = V_2 -> type ;
else if ( V_2 -> type == V_148 )
V_125 -> V_147 = V_149 ;
else if ( V_2 -> type == V_150 )
V_125 -> V_147 = V_151 ;
else {
F_36 ( L_19 , V_2 -> type , V_2 -> V_6 ) ;
V_125 -> V_147 = V_2 -> type ;
}
V_125 -> V_128 = V_2 -> V_98 ;
memcpy ( V_125 -> V_152 , V_2 -> V_107 , V_2 -> V_98 ) ;
V_125 -> V_153 = F_48 ( V_123 / V_154 ) ;
V_125 -> V_25 = V_10 -> V_25 ;
#ifdef F_70
if ( V_21 & V_155 )
F_55 ( V_125 -> V_156 ) ;
else
#endif
F_59 ( V_125 -> V_156 ) ;
V_83 -> V_2 = V_2 ;
V_83 -> V_137 = F_48 ( V_103 ) ;
if ( F_71 ( V_83 , V_2 , F_47 ( V_83 -> V_137 ) ,
V_2 -> V_157 , V_2 -> V_107 , V_83 -> V_115 ) < 0 ) {
F_52 ( V_83 ) ;
F_36 ( L_20 ) ;
return;
}
if ( F_72 ( V_83 ) < 0 )
F_36 ( L_20 ) ;
}
static int T_1 F_73 ( char * V_144 , char * V_158 , int V_115 , int V_159 )
{
if ( ! V_115 )
return 0 ;
if ( V_115 > V_159 - 1 )
V_115 = V_159 - 1 ;
memcpy ( V_144 , V_158 , V_115 ) ;
V_144 [ V_115 ] = '\0' ;
return 1 ;
}
static void T_1 F_74 ( T_4 * V_160 )
{
T_4 V_161 ;
int V_119 ;
T_2 V_17 ;
#ifdef F_56
T_4 * V_162 ;
F_36 ( L_21 , * V_160 ) ;
for ( V_162 = V_160 + 2 ; V_162 < V_160 + 2 + V_160 [ 1 ] ; V_162 ++ )
F_36 ( L_22 , * V_162 ) ;
F_36 ( L_23 ) ;
#endif
switch ( * V_160 ++ ) {
case 1 :
if ( V_57 == V_65 )
memcpy ( & V_57 , V_160 + 1 , 4 ) ;
break;
case 3 :
if ( V_64 == V_65 )
memcpy ( & V_64 , V_160 + 1 , 4 ) ;
break;
case 6 :
V_161 = * V_160 / 4 ;
if ( V_161 > V_120 )
V_161 = V_120 ;
for ( V_119 = 0 ; V_119 < V_161 ; V_119 ++ ) {
if ( V_121 [ V_119 ] == V_65 )
memcpy ( & V_121 [ V_119 ] , V_160 + 1 + 4 * V_119 , 4 ) ;
}
break;
case 12 :
F_73 ( F_57 () -> V_75 , V_160 + 1 , * V_160 ,
V_163 ) ;
V_74 = 1 ;
break;
case 15 :
F_73 ( V_164 , V_160 + 1 , * V_160 , sizeof( V_164 ) ) ;
break;
case 17 :
if ( ! V_165 [ 0 ] )
F_73 ( V_165 , V_160 + 1 , * V_160 ,
sizeof( V_165 ) ) ;
break;
case 26 :
memcpy ( & V_17 , V_160 + 1 , sizeof( V_17 ) ) ;
V_60 = F_47 ( V_17 ) ;
break;
case 40 :
F_73 ( F_57 () -> V_166 , V_160 + 1 , * V_160 ,
V_163 ) ;
break;
}
}
static int T_1 F_75 ( struct V_82 * V_83 , struct V_1 * V_2 , struct V_84 * V_85 , struct V_1 * V_86 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_9 * V_10 ;
int V_115 , V_167 ;
if ( ! F_42 ( F_43 ( V_2 ) , & V_46 ) )
goto V_94;
if ( V_83 -> V_168 == V_169 )
goto V_94;
if ( ( V_83 = F_44 ( V_83 , V_95 ) ) == NULL )
return V_96 ;
if ( ! F_45 ( V_83 ,
sizeof( struct V_126 ) +
sizeof( struct V_170 ) ) )
goto V_94;
V_125 = (struct V_124 * ) F_76 ( V_83 ) ;
V_127 = & V_125 -> V_171 ;
if ( V_127 -> V_132 != 5 || V_127 -> V_131 != 4 || V_127 -> V_137 != V_138 )
goto V_94;
if ( F_77 ( V_127 ) ) {
if ( F_78 () )
F_6 ( L_24 ) ;
goto V_94;
}
if ( V_83 -> V_115 < F_47 ( V_127 -> V_133 ) )
goto V_94;
if ( F_69 ( ( char * ) V_127 , V_127 -> V_132 ) )
goto V_94;
if ( V_125 -> V_142 . V_143 != F_48 ( 67 ) || V_125 -> V_142 . V_144 != F_48 ( 68 ) )
goto V_94;
if ( F_47 ( V_127 -> V_133 ) < F_47 ( V_125 -> V_142 . V_115 ) + sizeof( struct V_126 ) )
goto V_94;
V_115 = F_47 ( V_125 -> V_142 . V_115 ) - sizeof( struct V_170 ) ;
V_167 = V_115 - ( sizeof( * V_125 ) -
sizeof( struct V_126 ) -
sizeof( struct V_170 ) -
sizeof( V_125 -> V_156 ) ) ;
if ( V_167 < 0 )
goto V_94;
if ( ! F_45 ( V_83 , V_83 -> V_115 ) )
goto V_94;
V_125 = (struct V_124 * ) F_76 ( V_83 ) ;
V_127 = & V_125 -> V_171 ;
F_50 ( & V_104 ) ;
if ( V_105 )
goto V_106;
V_10 = V_14 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_24 ;
if ( ! V_10 )
goto V_106;
if ( V_125 -> V_145 != V_172 ||
V_125 -> V_25 != V_10 -> V_25 ) {
if ( F_78 () )
F_6 ( L_25 ,
V_125 -> V_145 , V_125 -> V_25 ) ;
goto V_106;
}
if ( V_125 -> V_25 != V_173 ) {
if ( F_78 () )
F_6 ( L_26 ) ;
goto V_106;
}
if ( V_167 >= 4 &&
! memcmp ( V_125 -> V_156 , V_116 , 4 ) ) {
T_4 * V_174 = ( T_4 * ) V_125 + F_47 ( V_125 -> V_171 . V_133 ) ;
T_4 * V_160 ;
#ifdef F_70
if ( V_21 & V_155 ) {
V_26 V_175 = V_65 ;
int V_111 = 0 ;
V_160 = & V_125 -> V_156 [ 4 ] ;
while ( V_160 < V_174 && * V_160 != 0xff ) {
T_4 * V_176 = V_160 ++ ;
if ( * V_176 == 0 )
continue;
V_160 += * V_160 + 1 ;
if ( V_160 >= V_174 )
break;
switch ( * V_176 ) {
case 53 :
if ( V_176 [ 1 ] )
V_111 = V_176 [ 2 ] ;
break;
case 54 :
if ( V_176 [ 1 ] >= 4 )
memcpy ( & V_175 , V_176 + 2 , 4 ) ;
break;
}
}
#ifdef F_56
F_36 ( L_27 , V_111 ) ;
#endif
switch ( V_111 ) {
case V_177 :
if ( V_55 != V_65 )
goto V_106;
V_55 = V_125 -> V_178 ;
V_77 = V_175 ;
#ifdef F_56
F_36 ( L_28 ,
& V_55 , & V_77 ) ;
#endif
if ( ( V_175 != V_65 ) &&
( V_125 -> V_179 != V_175 ) )
V_125 -> V_179 = V_77 ;
break;
case V_180 :
if ( memcmp ( V_2 -> V_107 , V_125 -> V_152 , V_2 -> V_98 ) != 0 )
goto V_106;
break;
default:
V_55 = V_65 ;
V_77 = V_65 ;
goto V_106;
}
V_181 = V_111 ;
}
#endif
V_160 = & V_125 -> V_156 [ 4 ] ;
while ( V_160 < V_174 && * V_160 != 0xff ) {
T_4 * V_176 = V_160 ++ ;
if ( * V_176 == 0 )
continue;
V_160 += * V_160 + 1 ;
if ( V_160 < V_174 )
F_74 ( V_176 ) ;
}
}
V_32 = V_2 ;
V_55 = V_125 -> V_178 ;
V_77 = V_125 -> V_179 ;
if ( V_64 == V_65 && V_125 -> V_182 )
V_64 = V_125 -> V_182 ;
if ( V_121 [ 0 ] == V_65 )
V_121 [ 0 ] = V_77 ;
V_105 = V_18 ;
V_106:
F_51 ( & V_104 ) ;
V_94:
F_52 ( V_83 ) ;
return 0 ;
}
static int T_1 F_79 ( void )
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
#ifdef F_80
if ( ( V_21 ^ V_27 ) & V_18 )
F_6 ( L_30 ) ;
#endif
#ifdef F_81
if ( ( V_21 ^ V_27 ) & V_20 )
F_6 ( L_31 ) ;
#endif
if ( ! V_27 )
return - 1 ;
#ifdef F_80
if ( V_187 )
F_60 () ;
#endif
#ifdef F_81
if ( V_188 )
F_37 () ;
#endif
F_82 ( L_32 ,
V_187
? ( ( V_21 & V_155 ) ? L_33 : L_34 ) : L_35 ,
( V_187 && V_188 ) ? L_36 : L_35 ,
V_188 ? L_37 : L_35 ) ;
V_184 = V_29 ;
V_10 = V_14 ;
V_183 = V_189 ;
F_10 ( & V_185 , sizeof( V_185 ) ) ;
V_185 = V_190 + ( V_185 % ( unsigned ) V_191 ) ;
for (; ; ) {
V_173 = V_10 -> V_25 ;
#ifdef F_80
if ( V_187 && ( V_10 -> V_16 & V_18 ) )
F_62 ( V_10 , V_29 - V_184 ) ;
#endif
#ifdef F_81
if ( V_188 && ( V_10 -> V_16 & V_20 ) )
F_53 ( V_10 ) ;
#endif
V_186 = V_29 + ( V_10 -> V_24 ? V_192 : V_185 ) ;
while ( F_83 ( V_29 , V_186 ) && ! V_105 )
F_84 ( 1 ) ;
#ifdef F_70
if ( ( V_105 & V_18 ) &&
( V_21 & V_155 ) &&
V_181 != V_180 ) {
V_105 = 0 ;
F_85 ( L_38 ) ;
continue;
}
#endif
if ( V_105 ) {
F_85 ( L_39 ) ;
break;
}
if ( ( V_10 = V_10 -> V_24 ) )
continue;
if ( ! -- V_183 ) {
F_85 ( L_40 ) ;
break;
}
V_10 = V_14 ;
V_185 = V_185 V_193 ;
if ( V_185 > V_194 )
V_185 = V_194 ;
F_85 ( L_41 ) ;
}
#ifdef F_80
if ( V_187 )
F_61 () ;
#endif
#ifdef F_81
if ( V_188 )
F_39 () ;
#endif
if ( ! V_105 ) {
V_55 = V_65 ;
return - 1 ;
}
F_36 ( L_42 ,
( ( V_105 & V_20 ) ? L_37
: ( V_21 & V_155 ) ? L_33 : L_34 ) ,
& V_77 ) ;
F_85 ( L_43 , & V_55 ) ;
return 0 ;
}
static int F_86 ( struct V_195 * V_196 , void * V_197 )
{
int V_119 ;
if ( V_198 & V_199 )
F_87 ( V_196 , L_44 ,
( V_198 & V_20 ) ? L_37
: ( V_198 & V_155 ) ? L_33 : L_34 ) ;
else
F_88 ( V_196 , L_45 ) ;
if ( V_164 [ 0 ] )
F_87 ( V_196 ,
L_46 , V_164 ) ;
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ ) {
if ( V_121 [ V_119 ] != V_65 )
F_87 ( V_196 , L_47 ,
& V_121 [ V_119 ] ) ;
}
if ( V_77 != V_65 )
F_87 ( V_196 , L_48 ,
& V_77 ) ;
return 0 ;
}
static int F_89 ( struct V_200 * V_201 , struct V_202 * V_202 )
{
return F_90 ( V_202 , F_86 , NULL ) ;
}
V_26 T_1 F_91 ( char * V_6 )
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
V_34 = F_92 ( V_6 ) ;
memmove ( V_6 , V_204 , strlen ( V_204 ) + 1 ) ;
} else
V_34 = V_65 ;
return V_34 ;
}
static int T_1 F_93 ( void )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_206 ; V_119 ++ ) {
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
F_94 ( 1 ) ;
}
return - V_31 ;
}
static int T_1 F_95 ( void )
{
V_26 V_34 ;
#ifdef F_96
int V_183 = V_208 ;
#endif
int V_52 ;
#ifdef F_97
F_98 ( & V_46 , L_49 , V_209 , & V_210 ) ;
#endif
if ( ! V_211 )
return 0 ;
F_11 ( ( L_50 ) ) ;
#ifdef F_96
V_212:
#endif
V_52 = F_93 () ;
if ( V_52 )
return V_52 ;
V_52 = F_2 () ;
if ( V_52 )
return V_52 ;
F_14 ( V_213 ) ;
if ( V_55 == V_65 ||
#ifdef F_99
( V_76 == V_65 &&
V_77 == V_65 &&
V_214 == V_215 ) ||
#endif
V_14 -> V_24 ) {
#ifdef F_96
if ( F_79 () < 0 ) {
F_15 () ;
#ifdef F_99
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
V_34 = F_91 ( V_165 ) ;
if ( V_76 == V_65 )
V_76 = V_34 ;
if ( F_29 () < 0 )
return - 1 ;
F_15 () ;
if ( F_27 () < 0 || F_28 () < 0 )
return - 1 ;
#ifdef F_96
V_198 = V_105 | ( V_21 & V_155 ) ;
#endif
#ifndef F_100
F_58 ( L_54 ) ;
F_58 ( L_55 ,
V_32 -> V_6 , & V_55 , & V_57 , & V_64 ) ;
F_58 ( L_56 ,
F_57 () -> V_75 , V_164 , F_57 () -> V_166 ) ;
F_58 ( L_57 ,
& V_77 , & V_76 , V_165 ) ;
if ( V_60 )
F_85 ( L_58 , V_60 ) ;
F_85 ( L_23 ) ;
#endif
return 0 ;
}
static int T_1 F_101 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_59 ) || ! strcmp ( V_6 , L_60 ) ) {
return 1 ;
}
if ( ! strcmp ( V_6 , L_61 ) || ! strcmp ( V_6 , L_62 ) ) {
return 0 ;
}
#ifdef F_102
else if ( ! strcmp ( V_6 , L_63 ) ) {
V_21 &= ~ V_20 ;
return 1 ;
}
#endif
#ifdef F_103
else if ( ! strcmp ( V_6 , L_64 ) ) {
V_21 &= ~ ( V_20 | V_155 ) ;
return 1 ;
}
#endif
#ifdef F_104
else if ( ! strcmp ( V_6 , L_65 ) ) {
V_21 &= ~ ( V_18 | V_155 ) ;
return 1 ;
}
#endif
#ifdef F_96
else if ( ! strcmp ( V_6 , L_66 ) ) {
V_21 &= ~ V_155 ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_105 ( char * V_216 )
{
char * V_204 , * V_217 , * V_218 ;
int V_219 = 0 ;
V_220 = 1 ;
V_211 = 1 ;
if ( F_101 ( V_216 ) )
return 1 ;
if ( * V_216 == 0 ||
strcmp ( V_216 , L_61 ) == 0 ||
strcmp ( V_216 , L_62 ) == 0 ) {
V_211 = 0 ;
return 1 ;
}
V_217 = V_216 ;
while ( V_217 && * V_217 ) {
if ( ( V_204 = strchr ( V_217 , ':' ) ) )
* V_204 ++ = '\0' ;
if ( strlen ( V_217 ) > 0 ) {
F_11 ( ( L_67 , V_219 , V_217 ) ) ;
switch ( V_219 ) {
case 0 :
if ( ( V_55 = F_92 ( V_217 ) ) == V_221 )
V_55 = V_65 ;
break;
case 1 :
if ( ( V_77 = F_92 ( V_217 ) ) == V_221 )
V_77 = V_65 ;
break;
case 2 :
if ( ( V_64 = F_92 ( V_217 ) ) == V_221 )
V_64 = V_65 ;
break;
case 3 :
if ( ( V_57 = F_92 ( V_217 ) ) == V_221 )
V_57 = V_65 ;
break;
case 4 :
if ( ( V_218 = strchr ( V_217 , '.' ) ) ) {
* V_218 ++ = '\0' ;
F_106 ( F_57 () -> V_166 , V_218 ,
sizeof( F_57 () -> V_166 ) ) ;
}
F_106 ( F_57 () -> V_75 , V_217 ,
sizeof( F_57 () -> V_75 ) ) ;
V_74 = 1 ;
break;
case 5 :
F_106 ( V_5 , V_217 , sizeof( V_5 ) ) ;
break;
case 6 :
if ( F_101 ( V_217 ) == 0 &&
V_55 == V_65 ) {
V_211 = 0 ;
}
break;
}
}
V_217 = V_204 ;
V_219 ++ ;
}
return 1 ;
}
static int T_1 F_107 ( char * V_216 )
{
return F_105 ( V_216 ) ;
}
static int T_1 F_108 ( char * V_216 )
{
if ( F_106 ( V_118 , V_216 ,
sizeof( V_118 ) )
>= sizeof( V_118 ) )
F_7 ( L_68 ,
V_118 ) ;
return 1 ;
}
