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
F_6 ( V_16 L_2 , V_2 -> V_6 ) ;
}
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
int V_17 = 0 ;
if ( V_2 -> V_18 >= 364 )
V_17 |= V_19 ;
else
F_6 ( V_20 L_3 , V_2 -> V_6 , V_2 -> V_18 ) ;
if ( ! ( V_2 -> V_3 & V_21 ) )
V_17 |= V_22 ;
V_17 &= V_23 ;
if ( V_23 && ! V_17 )
continue;
V_12 = V_2 -> V_3 ;
if ( F_5 ( V_2 , V_12 | V_15 ) < 0 ) {
F_6 ( V_16 L_2 , V_2 -> V_6 ) ;
continue;
}
if ( ! ( V_10 = F_7 ( sizeof( struct V_9 ) , V_24 ) ) ) {
F_8 () ;
return - V_25 ;
}
V_10 -> V_2 = V_2 ;
* V_11 = V_10 ;
V_11 = & V_10 -> V_26 ;
V_10 -> V_3 = V_12 ;
V_10 -> V_17 = V_17 ;
if ( V_17 & V_19 )
F_9 ( & V_10 -> V_27 , sizeof( V_28 ) ) ;
else
V_10 -> V_27 = 0 ;
V_29 |= V_17 ;
F_10 ( ( L_4 ,
V_2 -> V_6 , V_17 , V_10 -> V_27 ) ) ;
}
}
V_13 = V_30 ;
while ( V_30 - V_13 < F_11 ( V_31 ) ) {
F_4 (&init_net, dev)
if ( F_1 ( V_2 ) && F_12 ( V_2 ) )
goto V_32;
F_13 ( 1 ) ;
}
V_32:
F_8 () ;
* V_11 = NULL ;
if ( ! V_14 ) {
if ( V_5 [ 0 ] )
F_6 ( V_16 L_5 , V_5 ) ;
else
F_6 ( V_16 L_6 ) ;
return - V_33 ;
}
return 0 ;
}
static void T_1 F_14 ( void )
{
struct V_9 * V_10 , * V_26 ;
struct V_1 * V_2 ;
F_3 () ;
V_26 = V_14 ;
while ( ( V_10 = V_26 ) ) {
V_26 = V_10 -> V_26 ;
V_2 = V_10 -> V_2 ;
if ( V_2 != V_34 ) {
F_10 ( ( L_7 , V_2 -> V_6 ) ) ;
F_5 ( V_2 , V_10 -> V_3 ) ;
}
F_15 ( V_10 ) ;
}
F_8 () ;
}
static inline void
F_16 ( struct V_35 * sin , V_28 V_36 , T_2 V_37 )
{
sin -> V_38 = V_39 ;
sin -> V_40 . V_41 = V_36 ;
sin -> V_42 = V_37 ;
}
static int T_1 F_17 ( unsigned int V_43 , struct V_44 * V_45 )
{
int V_46 ;
T_3 V_47 = F_18 () ;
F_19 ( F_20 () ) ;
V_46 = F_21 ( & V_48 , V_43 , (struct V_44 V_49 * ) V_45 ) ;
F_19 ( V_47 ) ;
return V_46 ;
}
static int T_1 F_22 ( unsigned int V_43 , struct V_44 * V_45 )
{
int V_46 ;
T_3 V_47 = F_18 () ;
F_19 ( F_20 () ) ;
V_46 = F_23 ( & V_48 , V_43 , (struct V_44 V_49 * ) V_45 ) ;
F_19 ( V_47 ) ;
return V_46 ;
}
static int T_1 F_24 ( unsigned int V_43 , struct V_50 * V_45 )
{
int V_46 ;
T_3 V_47 = F_18 () ;
F_19 ( F_20 () ) ;
V_46 = F_25 ( & V_48 , V_43 , ( void V_49 * ) V_45 ) ;
F_19 ( V_47 ) ;
return V_46 ;
}
static int T_1 F_26 ( void )
{
struct V_44 V_51 ;
struct V_35 * sin = ( void * ) & V_51 . V_52 . V_53 ;
int V_54 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
strcpy ( V_51 . V_55 . V_56 , V_34 -> V_6 ) ;
F_16 ( sin , V_57 , 0 ) ;
if ( ( V_54 = F_17 ( V_58 , & V_51 ) ) < 0 ) {
F_6 ( V_16 L_8 , V_54 ) ;
return - 1 ;
}
F_16 ( sin , V_59 , 0 ) ;
if ( ( V_54 = F_17 ( V_60 , & V_51 ) ) < 0 ) {
F_6 ( V_16 L_9 , V_54 ) ;
return - 1 ;
}
F_16 ( sin , V_57 | ~ V_59 , 0 ) ;
if ( ( V_54 = F_17 ( V_61 , & V_51 ) ) < 0 ) {
F_6 ( V_16 L_10 , V_54 ) ;
return - 1 ;
}
if ( V_62 != 0 ) {
strcpy ( V_51 . V_63 , V_34 -> V_6 ) ;
V_51 . V_64 = V_62 ;
if ( ( V_54 = F_22 ( V_65 , & V_51 ) ) < 0 )
F_6 ( V_16 L_11 ,
V_62 , V_54 ) ;
}
return 0 ;
}
static int T_1 F_27 ( void )
{
if ( V_66 != V_67 ) {
struct V_50 V_68 ;
int V_54 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( ( V_66 ^ V_57 ) & V_59 ) {
F_6 ( V_16 L_12 ) ;
return - 1 ;
}
F_16 ( (struct V_35 * ) & V_68 . V_69 , 0 , 0 ) ;
F_16 ( (struct V_35 * ) & V_68 . V_70 , 0 , 0 ) ;
F_16 ( (struct V_35 * ) & V_68 . V_71 , V_66 , 0 ) ;
V_68 . V_72 = V_73 | V_74 ;
if ( ( V_54 = F_24 ( V_75 , & V_68 ) ) < 0 ) {
F_6 ( V_16 L_13 , V_54 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( ! V_76 )
sprintf ( F_29 () -> V_77 , L_14 , & V_57 ) ;
if ( V_78 == V_67 )
V_78 = V_79 ;
if ( V_59 == V_67 ) {
if ( F_30 ( F_31 ( V_57 ) ) )
V_59 = F_32 ( V_80 ) ;
else if ( F_33 ( F_31 ( V_57 ) ) )
V_59 = F_32 ( V_81 ) ;
else if ( F_34 ( F_31 ( V_57 ) ) )
V_59 = F_32 ( V_82 ) ;
else {
F_6 ( V_16 L_15 ,
& V_57 ) ;
return - 1 ;
}
F_6 ( L_16 , & V_59 ) ;
}
return 0 ;
}
static inline void T_1 F_35 ( void )
{
F_36 ( & V_83 ) ;
}
static inline void T_1 F_37 ( void )
{
F_38 ( & V_83 ) ;
}
static int T_1
F_39 ( struct V_84 * V_85 , struct V_1 * V_2 , struct V_86 * V_87 , struct V_1 * V_88 )
{
struct V_89 * V_90 ;
unsigned char * V_91 ;
V_28 V_92 , V_93 ;
unsigned char * V_94 , * V_95 ;
struct V_9 * V_10 ;
if ( ! F_40 ( F_41 ( V_2 ) , & V_48 ) )
goto V_96;
if ( ( V_85 = F_42 ( V_85 , V_97 ) ) == NULL )
return V_98 ;
if ( ! F_43 ( V_85 , sizeof( struct V_89 ) ) )
goto V_96;
V_90 = (struct V_89 * ) F_44 ( V_85 ) ;
if ( V_90 -> V_99 != V_2 -> V_100 || V_2 -> type != F_45 ( V_90 -> V_101 ) )
goto V_96;
if ( V_90 -> V_102 != F_46 ( V_103 ) )
goto V_96;
if ( V_90 -> V_104 != F_46 ( V_105 ) )
goto V_96;
if ( ! F_43 ( V_85 , F_47 ( V_2 ) ) )
goto V_96;
V_90 = (struct V_89 * ) F_44 ( V_85 ) ;
V_91 = ( unsigned char * ) ( V_90 + 1 ) ;
F_48 ( & V_106 ) ;
if ( V_107 )
goto V_108;
V_10 = V_14 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_26 ;
if ( ! V_10 )
goto V_108;
V_94 = V_91 ;
V_91 += V_2 -> V_100 ;
memcpy ( & V_92 , V_91 , 4 ) ;
V_91 += 4 ;
V_95 = V_91 ;
V_91 += V_2 -> V_100 ;
memcpy ( & V_93 , V_91 , 4 ) ;
if ( memcmp ( V_95 , V_2 -> V_109 , V_2 -> V_100 ) )
goto V_108;
if ( V_79 != V_67 && V_79 != V_92 )
goto V_108;
V_34 = V_2 ;
if ( V_57 == V_67 )
V_57 = V_93 ;
V_79 = V_92 ;
V_107 = V_22 ;
V_108:
F_49 ( & V_106 ) ;
V_96:
F_50 ( V_85 ) ;
return 0 ;
}
static void T_1 F_51 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_52 ( V_110 , V_111 , 0 , V_2 , 0 , NULL ,
V_2 -> V_109 , V_2 -> V_109 ) ;
}
static void T_1
F_53 ( T_4 * V_112 )
{
T_4 V_113 = ( ( V_79 == V_67 )
? V_114 : V_115 ) ;
T_4 * V_116 = V_112 ;
int V_117 ;
#ifdef F_54
F_6 ( L_17 , V_113 ) ;
#endif
memcpy ( V_116 , V_118 , 4 ) ;
V_116 += 4 ;
* V_116 ++ = 53 ;
* V_116 ++ = 1 ;
* V_116 ++ = V_113 ;
if ( V_113 == V_115 ) {
* V_116 ++ = 54 ;
* V_116 ++ = 4 ;
memcpy ( V_116 , & V_79 , 4 ) ;
V_116 += 4 ;
* V_116 ++ = 50 ;
* V_116 ++ = 4 ;
memcpy ( V_116 , & V_57 , 4 ) ;
V_116 += 4 ;
}
{
static const T_4 V_119 [] = {
1 ,
3 ,
6 ,
12 ,
15 ,
17 ,
26 ,
40 ,
} ;
* V_116 ++ = 55 ;
* V_116 ++ = sizeof( V_119 ) ;
memcpy ( V_116 , V_119 , sizeof( V_119 ) ) ;
V_116 += sizeof( V_119 ) ;
if ( V_76 ) {
* V_116 ++ = 12 ;
V_117 = strlen ( F_55 () -> V_77 ) ;
* V_116 ++ = V_117 ;
memcpy ( V_116 , F_55 () -> V_77 , V_117 ) ;
V_116 += V_117 ;
}
if ( * V_120 ) {
F_6 ( V_121 L_18 ,
V_120 ) ;
* V_116 ++ = 60 ;
V_117 = strlen ( V_120 ) ;
* V_116 ++ = V_117 ;
memcpy ( V_116 , V_120 , V_117 ) ;
V_116 += V_117 ;
}
}
* V_116 ++ = 255 ;
}
static void T_1 F_56 ( T_4 * V_116 )
{
memcpy ( V_116 , V_118 , 4 ) ;
V_116 += 4 ;
* V_116 ++ = 1 ;
* V_116 ++ = 4 ;
V_116 += 4 ;
* V_116 ++ = 3 ;
* V_116 ++ = 4 ;
V_116 += 4 ;
* V_116 ++ = 5 ;
* V_116 ++ = 8 ;
V_116 += 8 ;
* V_116 ++ = 12 ;
* V_116 ++ = 32 ;
V_116 += 32 ;
* V_116 ++ = 40 ;
* V_116 ++ = 32 ;
V_116 += 32 ;
* V_116 ++ = 17 ;
* V_116 ++ = 40 ;
V_116 += 40 ;
* V_116 ++ = 57 ;
* V_116 ++ = 2 ;
* V_116 ++ = 1 ;
* V_116 ++ = 150 ;
* V_116 ++ = 255 ;
}
static inline void T_1 F_57 ( void )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
V_124 [ V_122 ] = V_67 ;
F_36 ( & V_125 ) ;
}
static inline void T_1 F_58 ( void )
{
F_38 ( & V_125 ) ;
}
static void T_1 F_59 ( struct V_9 * V_10 , unsigned long V_126 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_84 * V_85 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
V_85 = F_60 ( sizeof( struct V_127 ) + F_61 ( V_2 ) + 15 ,
V_24 ) ;
if ( ! V_85 )
return;
F_62 ( V_85 , F_63 ( V_2 ) ) ;
V_128 = (struct V_127 * ) F_64 ( V_85 , sizeof( struct V_127 ) ) ;
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
F_65 ( V_85 ) ;
V_130 = F_66 ( V_85 ) ;
V_130 -> V_131 = 4 ;
V_130 -> V_132 = 5 ;
V_130 -> V_133 = F_46 ( sizeof( struct V_127 ) ) ;
V_130 -> V_134 = F_46 ( V_135 ) ;
V_130 -> V_136 = 64 ;
V_130 -> V_137 = V_138 ;
V_130 -> V_139 = F_32 ( V_140 ) ;
V_130 -> V_141 = F_67 ( ( unsigned char * ) V_130 , V_130 -> V_132 ) ;
V_128 -> V_142 . V_143 = F_46 ( 68 ) ;
V_128 -> V_142 . V_144 = F_46 ( 67 ) ;
V_128 -> V_142 . V_117 = F_46 ( sizeof( struct V_127 ) - sizeof( struct V_129 ) ) ;
V_128 -> V_145 = V_146 ;
if ( V_2 -> type < 256 )
V_128 -> V_147 = V_2 -> type ;
else if ( V_2 -> type == V_148 )
V_128 -> V_147 = V_149 ;
else if ( V_2 -> type == V_150 )
V_128 -> V_147 = V_151 ;
else {
F_6 ( L_19 , V_2 -> type , V_2 -> V_6 ) ;
V_128 -> V_147 = V_2 -> type ;
}
V_128 -> V_152 = V_2 -> V_100 ;
memcpy ( V_128 -> V_153 , V_2 -> V_109 , V_2 -> V_100 ) ;
V_128 -> V_154 = F_46 ( V_126 / V_155 ) ;
V_128 -> V_27 = V_10 -> V_27 ;
#ifdef F_68
if ( V_23 & V_156 )
F_53 ( V_128 -> V_157 ) ;
else
#endif
F_56 ( V_128 -> V_157 ) ;
V_85 -> V_2 = V_2 ;
V_85 -> V_137 = F_46 ( V_105 ) ;
if ( F_69 ( V_85 , V_2 , F_45 ( V_85 -> V_137 ) ,
V_2 -> V_158 , V_2 -> V_109 , V_85 -> V_117 ) < 0 ||
F_70 ( V_85 ) < 0 )
F_6 ( L_20 ) ;
}
static int T_1 F_71 ( char * V_144 , char * V_159 , int V_117 , int V_160 )
{
if ( ! V_117 )
return 0 ;
if ( V_117 > V_160 - 1 )
V_117 = V_160 - 1 ;
memcpy ( V_144 , V_159 , V_117 ) ;
V_144 [ V_117 ] = '\0' ;
return 1 ;
}
static void T_1 F_72 ( T_4 * V_161 )
{
T_4 V_162 ;
int V_122 ;
T_5 V_18 ;
#ifdef F_54
T_4 * V_163 ;
F_6 ( L_21 , * V_161 ) ;
for ( V_163 = V_161 + 2 ; V_163 < V_161 + 2 + V_161 [ 1 ] ; V_163 ++ )
F_6 ( L_22 , * V_163 ) ;
F_6 ( L_23 ) ;
#endif
switch ( * V_161 ++ ) {
case 1 :
if ( V_59 == V_67 )
memcpy ( & V_59 , V_161 + 1 , 4 ) ;
break;
case 3 :
if ( V_66 == V_67 )
memcpy ( & V_66 , V_161 + 1 , 4 ) ;
break;
case 6 :
V_162 = * V_161 / 4 ;
if ( V_162 > V_123 )
V_162 = V_123 ;
for ( V_122 = 0 ; V_122 < V_162 ; V_122 ++ ) {
if ( V_124 [ V_122 ] == V_67 )
memcpy ( & V_124 [ V_122 ] , V_161 + 1 + 4 * V_122 , 4 ) ;
}
break;
case 12 :
F_71 ( F_55 () -> V_77 , V_161 + 1 , * V_161 ,
V_164 ) ;
V_76 = 1 ;
break;
case 15 :
F_71 ( V_165 , V_161 + 1 , * V_161 , sizeof( V_165 ) ) ;
break;
case 17 :
if ( ! V_166 [ 0 ] )
F_71 ( V_166 , V_161 + 1 , * V_161 ,
sizeof( V_166 ) ) ;
break;
case 26 :
memcpy ( & V_18 , V_161 + 1 , sizeof( V_18 ) ) ;
V_62 = F_45 ( V_18 ) ;
break;
case 40 :
F_71 ( F_55 () -> V_167 , V_161 + 1 , * V_161 ,
V_164 ) ;
break;
}
}
static int T_1 F_73 ( struct V_84 * V_85 , struct V_1 * V_2 , struct V_86 * V_87 , struct V_1 * V_88 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_9 * V_10 ;
int V_117 , V_168 ;
if ( ! F_40 ( F_41 ( V_2 ) , & V_48 ) )
goto V_96;
if ( V_85 -> V_169 == V_170 )
goto V_96;
if ( ( V_85 = F_42 ( V_85 , V_97 ) ) == NULL )
return V_98 ;
if ( ! F_43 ( V_85 ,
sizeof( struct V_129 ) +
sizeof( struct V_171 ) ) )
goto V_96;
V_128 = (struct V_127 * ) F_74 ( V_85 ) ;
V_130 = & V_128 -> V_172 ;
if ( V_130 -> V_132 != 5 || V_130 -> V_131 != 4 || V_130 -> V_137 != V_138 )
goto V_96;
if ( F_75 ( V_130 ) ) {
if ( F_76 () )
F_6 ( V_16 L_24
L_25 ) ;
goto V_96;
}
if ( V_85 -> V_117 < F_45 ( V_130 -> V_133 ) )
goto V_96;
if ( F_67 ( ( char * ) V_130 , V_130 -> V_132 ) )
goto V_96;
if ( V_128 -> V_142 . V_143 != F_46 ( 67 ) || V_128 -> V_142 . V_144 != F_46 ( 68 ) )
goto V_96;
if ( F_45 ( V_130 -> V_133 ) < F_45 ( V_128 -> V_142 . V_117 ) + sizeof( struct V_129 ) )
goto V_96;
V_117 = F_45 ( V_128 -> V_142 . V_117 ) - sizeof( struct V_171 ) ;
V_168 = V_117 - ( sizeof( * V_128 ) -
sizeof( struct V_129 ) -
sizeof( struct V_171 ) -
sizeof( V_128 -> V_157 ) ) ;
if ( V_168 < 0 )
goto V_96;
if ( ! F_43 ( V_85 , V_85 -> V_117 ) )
goto V_96;
V_128 = (struct V_127 * ) F_74 ( V_85 ) ;
V_130 = & V_128 -> V_172 ;
F_48 ( & V_106 ) ;
if ( V_107 )
goto V_108;
V_10 = V_14 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_26 ;
if ( ! V_10 )
goto V_108;
if ( V_128 -> V_145 != V_173 ||
V_128 -> V_27 != V_10 -> V_27 ) {
if ( F_76 () )
F_6 ( V_16 L_26
L_27 ,
V_128 -> V_145 , V_128 -> V_27 ) ;
goto V_108;
}
if ( V_128 -> V_27 != V_174 ) {
if ( F_76 () )
F_6 ( V_16 L_28 ) ;
goto V_108;
}
if ( V_168 >= 4 &&
! memcmp ( V_128 -> V_157 , V_118 , 4 ) ) {
T_4 * V_175 = ( T_4 * ) V_128 + F_45 ( V_128 -> V_172 . V_133 ) ;
T_4 * V_161 ;
#ifdef F_68
if ( V_23 & V_156 ) {
V_28 V_176 = V_67 ;
int V_113 = 0 ;
V_161 = & V_128 -> V_157 [ 4 ] ;
while ( V_161 < V_175 && * V_161 != 0xff ) {
T_4 * V_177 = V_161 ++ ;
if ( * V_177 == 0 )
continue;
V_161 += * V_161 + 1 ;
if ( V_161 >= V_175 )
break;
switch ( * V_177 ) {
case 53 :
if ( V_177 [ 1 ] )
V_113 = V_177 [ 2 ] ;
break;
case 54 :
if ( V_177 [ 1 ] >= 4 )
memcpy ( & V_176 , V_177 + 2 , 4 ) ;
break;
}
}
#ifdef F_54
F_6 ( L_29 , V_113 ) ;
#endif
switch ( V_113 ) {
case V_178 :
if ( V_57 != V_67 )
goto V_108;
V_57 = V_128 -> V_179 ;
V_79 = V_176 ;
#ifdef F_54
F_6 ( L_30 ,
& V_57 , & V_79 ) ;
#endif
if ( ( V_176 != V_67 ) &&
( V_128 -> V_180 != V_176 ) )
V_128 -> V_180 = V_79 ;
break;
case V_181 :
if ( memcmp ( V_2 -> V_109 , V_128 -> V_153 , V_2 -> V_100 ) != 0 )
goto V_108;
break;
default:
V_57 = V_67 ;
V_79 = V_67 ;
goto V_108;
}
V_182 = V_113 ;
}
#endif
V_161 = & V_128 -> V_157 [ 4 ] ;
while ( V_161 < V_175 && * V_161 != 0xff ) {
T_4 * V_177 = V_161 ++ ;
if ( * V_177 == 0 )
continue;
V_161 += * V_161 + 1 ;
if ( V_161 < V_175 )
F_72 ( V_177 ) ;
}
}
V_34 = V_2 ;
V_57 = V_128 -> V_179 ;
V_79 = V_128 -> V_180 ;
if ( V_66 == V_67 && V_128 -> V_183 )
V_66 = V_128 -> V_183 ;
if ( V_124 [ 0 ] == V_67 )
V_124 [ 0 ] = V_79 ;
V_107 = V_19 ;
V_108:
F_49 ( & V_106 ) ;
V_96:
F_50 ( V_85 ) ;
return 0 ;
}
static int T_1 F_77 ( void )
{
int V_184 ;
struct V_9 * V_10 ;
unsigned long V_185 , V_186 , V_187 ;
int V_188 = V_29 & V_19 ;
int V_189 = V_29 & V_22 ;
if ( ! V_23 ) {
F_6 ( V_16 L_31 ) ;
return - 1 ;
}
#ifdef F_78
if ( ( V_23 ^ V_29 ) & V_19 )
F_6 ( V_16 L_32 ) ;
#endif
#ifdef F_79
if ( ( V_23 ^ V_29 ) & V_22 )
F_6 ( V_16 L_33 ) ;
#endif
if ( ! V_29 )
return - 1 ;
#ifdef F_78
if ( V_188 )
F_57 () ;
#endif
#ifdef F_79
if ( V_189 )
F_35 () ;
#endif
F_6 ( V_190 L_34 ,
V_188
? ( ( V_23 & V_156 ) ? L_35 : L_36 ) : L_37 ,
( V_188 && V_189 ) ? L_38 : L_37 ,
V_189 ? L_39 : L_37 ) ;
V_185 = V_30 ;
V_10 = V_14 ;
V_184 = V_191 ;
F_9 ( & V_186 , sizeof( V_186 ) ) ;
V_186 = V_192 + ( V_186 % ( unsigned ) V_193 ) ;
for (; ; ) {
V_174 = V_10 -> V_27 ;
#ifdef F_78
if ( V_188 && ( V_10 -> V_17 & V_19 ) )
F_59 ( V_10 , V_30 - V_185 ) ;
#endif
#ifdef F_79
if ( V_189 && ( V_10 -> V_17 & V_22 ) )
F_51 ( V_10 ) ;
#endif
V_187 = V_30 + ( V_10 -> V_26 ? V_194 : V_186 ) ;
while ( F_80 ( V_30 , V_187 ) && ! V_107 )
F_81 ( 1 ) ;
#ifdef F_68
if ( ( V_107 & V_19 ) &&
( V_23 & V_156 ) &&
V_182 != V_181 ) {
V_107 = 0 ;
F_6 ( V_195 L_40 ) ;
continue;
}
#endif
if ( V_107 ) {
F_6 ( V_195 L_41 ) ;
break;
}
if ( ( V_10 = V_10 -> V_26 ) )
continue;
if ( ! -- V_184 ) {
F_6 ( V_195 L_42 ) ;
break;
}
V_10 = V_14 ;
V_186 = V_186 V_196 ;
if ( V_186 > V_197 )
V_186 = V_197 ;
F_6 ( V_195 L_43 ) ;
}
#ifdef F_78
if ( V_188 )
F_58 () ;
#endif
#ifdef F_79
if ( V_189 )
F_37 () ;
#endif
if ( ! V_107 ) {
V_57 = V_67 ;
return - 1 ;
}
F_6 ( L_44 ,
( ( V_107 & V_22 ) ? L_39
: ( V_23 & V_156 ) ? L_35 : L_36 ) ,
& V_79 ) ;
F_6 ( V_195 L_45 , & V_57 ) ;
return 0 ;
}
static int F_82 ( struct V_198 * V_199 , void * V_200 )
{
int V_122 ;
if ( V_201 & V_202 )
F_83 ( V_199 , L_46 ,
( V_201 & V_22 ) ? L_39
: ( V_201 & V_156 ) ? L_35 : L_36 ) ;
else
F_84 ( V_199 , L_47 ) ;
if ( V_165 [ 0 ] )
F_83 ( V_199 ,
L_48 , V_165 ) ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ ) {
if ( V_124 [ V_122 ] != V_67 )
F_83 ( V_199 , L_49 ,
& V_124 [ V_122 ] ) ;
}
if ( V_79 != V_67 )
F_83 ( V_199 , L_50 ,
& V_79 ) ;
return 0 ;
}
static int F_85 ( struct V_203 * V_204 , struct V_205 * V_205 )
{
return F_86 ( V_205 , F_82 , NULL ) ;
}
V_28 T_1 F_87 ( char * V_6 )
{
V_28 V_36 ;
int V_206 = 0 ;
char * V_207 , * V_208 ;
V_207 = V_208 = V_6 ;
while ( V_206 < 4 ) {
while ( * V_207 >= '0' && * V_207 <= '9' )
V_207 ++ ;
if ( V_207 == V_208 || V_207 - V_208 > 3 )
break;
if ( * V_207 == '.' || V_206 == 3 )
V_206 ++ ;
if ( V_206 < 4 )
V_207 ++ ;
V_208 = V_207 ;
}
if ( V_206 == 4 && ( * V_207 == ':' || * V_207 == '\0' ) ) {
if ( * V_207 == ':' )
* V_207 ++ = '\0' ;
V_36 = F_88 ( V_6 ) ;
memmove ( V_6 , V_207 , strlen ( V_207 ) + 1 ) ;
} else
V_36 = V_67 ;
return V_36 ;
}
static int T_1 F_89 ( void )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_209 ; V_122 ++ ) {
struct V_1 * V_2 ;
int V_210 = 0 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
V_210 = 1 ;
break;
}
}
F_8 () ;
if ( V_210 )
return 0 ;
F_90 ( 1 ) ;
}
return - V_33 ;
}
static int T_1 F_91 ( void )
{
V_28 V_36 ;
#ifdef F_92
int V_184 = V_211 ;
#endif
int V_54 ;
#ifdef F_93
F_94 ( & V_48 , L_51 , V_212 , & V_213 ) ;
#endif
if ( ! V_214 )
return 0 ;
F_10 ( ( L_52 ) ) ;
#ifdef F_92
V_215:
#endif
V_54 = F_89 () ;
if ( V_54 )
return V_54 ;
V_54 = F_2 () ;
if ( V_54 )
return V_54 ;
F_13 ( V_216 ) ;
if ( V_57 == V_67 ||
#ifdef F_95
( V_78 == V_67 &&
V_79 == V_67 &&
V_217 == V_218 ) ||
#endif
V_14 -> V_26 ) {
#ifdef F_92
if ( F_77 () < 0 ) {
F_14 () ;
#ifdef F_95
if ( V_217 == V_218 ) {
F_6 ( V_16
L_53 ) ;
goto V_215;
}
#endif
if ( -- V_184 ) {
F_6 ( V_16
L_54 ) ;
goto V_215;
}
F_6 ( V_16 L_55 ) ;
return - 1 ;
}
#else
F_6 ( V_16 L_31 ) ;
F_14 () ;
return - 1 ;
#endif
} else {
V_34 = V_14 -> V_2 ;
}
V_36 = F_87 ( V_166 ) ;
if ( V_78 == V_67 )
V_78 = V_36 ;
if ( F_28 () < 0 )
return - 1 ;
F_14 () ;
if ( F_26 () < 0 || F_27 () < 0 )
return - 1 ;
#ifdef F_92
V_201 = V_107 | ( V_23 & V_156 ) ;
#endif
#ifndef F_96
F_6 ( L_56 ) ;
F_6 ( L_57 , V_34 -> V_6 ) ;
F_6 ( V_195 L_58 , & V_57 ) ;
F_6 ( V_195 L_59 , & V_59 ) ;
F_6 ( V_195 L_60 , & V_66 ) ;
F_6 ( V_195 L_61 ,
F_55 () -> V_77 , V_165 , F_55 () -> V_167 ) ;
F_6 ( V_195 L_62 , & V_79 ) ;
F_6 ( V_195 L_63 , & V_78 ) ;
F_6 ( V_195 L_64 , V_166 ) ;
if ( V_62 )
F_6 ( V_195 L_65 , V_62 ) ;
F_6 ( V_195 L_23 ) ;
#endif
return 0 ;
}
static int T_1 F_97 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_66 ) || ! strcmp ( V_6 , L_67 ) ) {
return 1 ;
}
if ( ! strcmp ( V_6 , L_68 ) || ! strcmp ( V_6 , L_69 ) ) {
return 0 ;
}
#ifdef F_98
else if ( ! strcmp ( V_6 , L_70 ) ) {
V_23 &= ~ V_22 ;
return 1 ;
}
#endif
#ifdef F_99
else if ( ! strcmp ( V_6 , L_71 ) ) {
V_23 &= ~ ( V_22 | V_156 ) ;
return 1 ;
}
#endif
#ifdef F_100
else if ( ! strcmp ( V_6 , L_72 ) ) {
V_23 &= ~ ( V_19 | V_156 ) ;
return 1 ;
}
#endif
#ifdef F_92
else if ( ! strcmp ( V_6 , L_73 ) ) {
V_23 &= ~ V_156 ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_101 ( char * V_219 )
{
char * V_207 , * V_220 , * V_221 ;
int V_222 = 0 ;
V_223 = 1 ;
V_214 = 1 ;
if ( F_97 ( V_219 ) )
return 1 ;
if ( * V_219 == 0 ||
strcmp ( V_219 , L_68 ) == 0 ||
strcmp ( V_219 , L_69 ) == 0 ) {
V_214 = 0 ;
return 1 ;
}
V_220 = V_219 ;
while ( V_220 && * V_220 ) {
if ( ( V_207 = strchr ( V_220 , ':' ) ) )
* V_207 ++ = '\0' ;
if ( strlen ( V_220 ) > 0 ) {
F_10 ( ( L_74 , V_222 , V_220 ) ) ;
switch ( V_222 ) {
case 0 :
if ( ( V_57 = F_88 ( V_220 ) ) == V_224 )
V_57 = V_67 ;
break;
case 1 :
if ( ( V_79 = F_88 ( V_220 ) ) == V_224 )
V_79 = V_67 ;
break;
case 2 :
if ( ( V_66 = F_88 ( V_220 ) ) == V_224 )
V_66 = V_67 ;
break;
case 3 :
if ( ( V_59 = F_88 ( V_220 ) ) == V_224 )
V_59 = V_67 ;
break;
case 4 :
if ( ( V_221 = strchr ( V_220 , '.' ) ) ) {
* V_221 ++ = '\0' ;
F_102 ( F_55 () -> V_167 , V_221 ,
sizeof( F_55 () -> V_167 ) ) ;
}
F_102 ( F_55 () -> V_77 , V_220 ,
sizeof( F_55 () -> V_77 ) ) ;
V_76 = 1 ;
break;
case 5 :
F_102 ( V_5 , V_220 , sizeof( V_5 ) ) ;
break;
case 6 :
if ( F_97 ( V_220 ) == 0 &&
V_57 == V_67 ) {
V_214 = 0 ;
}
break;
}
}
V_220 = V_207 ;
V_222 ++ ;
}
return 1 ;
}
static int T_1 F_103 ( char * V_219 )
{
return F_101 ( V_219 ) ;
}
static int T_1 F_104 ( char * V_219 )
{
if ( F_102 ( V_120 , V_219 ,
sizeof( V_120 ) )
>= sizeof( V_120 ) )
F_6 ( V_20 L_75 ,
V_120 ) ;
return 1 ;
}
