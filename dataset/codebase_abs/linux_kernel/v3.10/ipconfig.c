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
unsigned long V_13 , V_14 ;
V_11 = & V_15 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( ! ( V_2 -> V_3 & V_4 ) )
continue;
if ( F_5 ( V_2 , V_2 -> V_3 | V_16 ) < 0 )
F_6 ( L_2 , V_2 -> V_6 ) ;
}
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
int V_17 = 0 ;
if ( V_2 -> V_18 >= 364 )
V_17 |= V_19 ;
else
F_7 ( L_3 ,
V_2 -> V_6 , V_2 -> V_18 ) ;
if ( ! ( V_2 -> V_3 & V_20 ) )
V_17 |= V_21 ;
V_17 &= V_22 ;
if ( V_22 && ! V_17 )
continue;
V_12 = V_2 -> V_3 ;
if ( F_5 ( V_2 , V_12 | V_16 ) < 0 ) {
F_6 ( L_2 ,
V_2 -> V_6 ) ;
continue;
}
if ( ! ( V_10 = F_8 ( sizeof( struct V_9 ) , V_23 ) ) ) {
F_9 () ;
return - V_24 ;
}
V_10 -> V_2 = V_2 ;
* V_11 = V_10 ;
V_11 = & V_10 -> V_25 ;
V_10 -> V_3 = V_12 ;
V_10 -> V_17 = V_17 ;
if ( V_17 & V_19 )
F_10 ( & V_10 -> V_26 , sizeof( V_27 ) ) ;
else
V_10 -> V_26 = 0 ;
V_28 |= V_17 ;
F_11 ( ( L_4 ,
V_2 -> V_6 , V_17 , V_10 -> V_26 ) ) ;
}
}
if ( ! V_15 )
goto V_29;
V_13 = V_30 ;
V_14 = V_13 + F_12 ( V_31 / 12 ) ;
while ( V_30 - V_13 < F_12 ( V_31 ) ) {
int V_32 , V_33 ;
F_4 (&init_net, dev)
if ( F_1 ( V_2 ) && F_13 ( V_2 ) )
goto V_29;
F_14 ( 1 ) ;
if time_before( V_30 , V_14 )
continue;
V_33 = F_15 ( V_30 - V_13 ) ;
V_32 = ( V_31 - V_33 + 500 ) / 1000 ;
F_16 ( L_5 , V_32 ) ;
V_14 = V_30 + F_12 ( V_31 / 12 ) ;
}
V_29:
F_9 () ;
* V_11 = NULL ;
if ( ! V_15 ) {
if ( V_5 [ 0 ] )
F_6 ( L_6 ,
V_5 ) ;
else
F_6 ( L_7 ) ;
return - V_34 ;
}
return 0 ;
}
static void T_1 F_17 ( void )
{
struct V_9 * V_10 , * V_25 ;
struct V_1 * V_2 ;
F_3 () ;
V_25 = V_15 ;
while ( ( V_10 = V_25 ) ) {
V_25 = V_10 -> V_25 ;
V_2 = V_10 -> V_2 ;
if ( V_2 != V_35 ) {
F_11 ( ( L_8 , V_2 -> V_6 ) ) ;
F_5 ( V_2 , V_10 -> V_3 ) ;
}
F_18 ( V_10 ) ;
}
F_9 () ;
}
static inline void
F_19 ( struct V_36 * sin , V_27 V_37 , T_2 V_38 )
{
sin -> V_39 = V_40 ;
sin -> V_41 . V_42 = V_37 ;
sin -> V_43 = V_38 ;
}
static int T_1 F_20 ( unsigned int V_44 , struct V_45 * V_46 )
{
int V_47 ;
T_3 V_48 = F_21 () ;
F_22 ( F_23 () ) ;
V_47 = F_24 ( & V_49 , V_44 , (struct V_45 V_50 * ) V_46 ) ;
F_22 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_25 ( unsigned int V_44 , struct V_45 * V_46 )
{
int V_47 ;
T_3 V_48 = F_21 () ;
F_22 ( F_23 () ) ;
V_47 = F_26 ( & V_49 , V_44 , (struct V_45 V_50 * ) V_46 ) ;
F_22 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_27 ( unsigned int V_44 , struct V_51 * V_46 )
{
int V_47 ;
T_3 V_48 = F_21 () ;
F_22 ( F_23 () ) ;
V_47 = F_28 ( & V_49 , V_44 , ( void V_50 * ) V_46 ) ;
F_22 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_29 ( void )
{
struct V_45 V_52 ;
struct V_36 * sin = ( void * ) & V_52 . V_53 . V_54 ;
int V_55 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
strcpy ( V_52 . V_56 . V_57 , V_35 -> V_6 ) ;
F_19 ( sin , V_58 , 0 ) ;
if ( ( V_55 = F_20 ( V_59 , & V_52 ) ) < 0 ) {
F_6 ( L_9 ,
V_55 ) ;
return - 1 ;
}
F_19 ( sin , V_60 , 0 ) ;
if ( ( V_55 = F_20 ( V_61 , & V_52 ) ) < 0 ) {
F_6 ( L_10 ,
V_55 ) ;
return - 1 ;
}
F_19 ( sin , V_58 | ~ V_60 , 0 ) ;
if ( ( V_55 = F_20 ( V_62 , & V_52 ) ) < 0 ) {
F_6 ( L_11 ,
V_55 ) ;
return - 1 ;
}
if ( V_63 != 0 ) {
strcpy ( V_52 . V_64 , V_35 -> V_6 ) ;
V_52 . V_65 = V_63 ;
if ( ( V_55 = F_25 ( V_66 , & V_52 ) ) < 0 )
F_6 ( L_12 ,
V_63 , V_55 ) ;
}
return 0 ;
}
static int T_1 F_30 ( void )
{
if ( V_67 != V_68 ) {
struct V_51 V_69 ;
int V_55 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( ( V_67 ^ V_58 ) & V_60 ) {
F_6 ( L_13 ) ;
return - 1 ;
}
F_19 ( (struct V_36 * ) & V_69 . V_70 , 0 , 0 ) ;
F_19 ( (struct V_36 * ) & V_69 . V_71 , 0 , 0 ) ;
F_19 ( (struct V_36 * ) & V_69 . V_72 , V_67 , 0 ) ;
V_69 . V_73 = V_74 | V_75 ;
if ( ( V_55 = F_27 ( V_76 , & V_69 ) ) < 0 ) {
F_6 ( L_14 ,
V_55 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_1 F_31 ( void )
{
if ( ! V_77 )
sprintf ( F_32 () -> V_78 , L_15 , & V_58 ) ;
if ( V_79 == V_68 )
V_79 = V_80 ;
if ( V_60 == V_68 ) {
if ( F_33 ( F_34 ( V_58 ) ) )
V_60 = F_35 ( V_81 ) ;
else if ( F_36 ( F_34 ( V_58 ) ) )
V_60 = F_35 ( V_82 ) ;
else if ( F_37 ( F_34 ( V_58 ) ) )
V_60 = F_35 ( V_83 ) ;
else {
F_6 ( L_16 ,
& V_58 ) ;
return - 1 ;
}
F_38 ( L_17 , & V_60 ) ;
}
return 0 ;
}
static inline void T_1 F_39 ( void )
{
F_40 ( & V_84 ) ;
}
static inline void T_1 F_41 ( void )
{
F_42 ( & V_84 ) ;
}
static int T_1
F_43 ( struct V_85 * V_86 , struct V_1 * V_2 , struct V_87 * V_88 , struct V_1 * V_89 )
{
struct V_90 * V_91 ;
unsigned char * V_92 ;
V_27 V_93 , V_94 ;
unsigned char * V_95 , * V_96 ;
struct V_9 * V_10 ;
if ( ! F_44 ( F_45 ( V_2 ) , & V_49 ) )
goto V_97;
if ( ( V_86 = F_46 ( V_86 , V_98 ) ) == NULL )
return V_99 ;
if ( ! F_47 ( V_86 , sizeof( struct V_90 ) ) )
goto V_97;
V_91 = (struct V_90 * ) F_48 ( V_86 ) ;
if ( V_91 -> V_100 != V_2 -> V_101 || V_2 -> type != F_49 ( V_91 -> V_102 ) )
goto V_97;
if ( V_91 -> V_103 != F_50 ( V_104 ) )
goto V_97;
if ( V_91 -> V_105 != F_50 ( V_106 ) )
goto V_97;
if ( ! F_47 ( V_86 , F_51 ( V_2 ) ) )
goto V_97;
V_91 = (struct V_90 * ) F_48 ( V_86 ) ;
V_92 = ( unsigned char * ) ( V_91 + 1 ) ;
F_52 ( & V_107 ) ;
if ( V_108 )
goto V_109;
V_10 = V_15 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_25 ;
if ( ! V_10 )
goto V_109;
V_95 = V_92 ;
V_92 += V_2 -> V_101 ;
memcpy ( & V_93 , V_92 , 4 ) ;
V_92 += 4 ;
V_96 = V_92 ;
V_92 += V_2 -> V_101 ;
memcpy ( & V_94 , V_92 , 4 ) ;
if ( memcmp ( V_96 , V_2 -> V_110 , V_2 -> V_101 ) )
goto V_109;
if ( V_80 != V_68 && V_80 != V_93 )
goto V_109;
V_35 = V_2 ;
if ( V_58 == V_68 )
V_58 = V_94 ;
V_80 = V_93 ;
V_111 = V_93 ;
V_108 = V_21 ;
V_109:
F_53 ( & V_107 ) ;
V_97:
F_54 ( V_86 ) ;
return 0 ;
}
static void T_1 F_55 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_56 ( V_112 , V_113 , 0 , V_2 , 0 , NULL ,
V_2 -> V_110 , V_2 -> V_110 ) ;
}
static inline void T_1 F_57 ( void )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
V_116 [ V_114 ] = V_68 ;
}
static void T_1
F_58 ( T_4 * V_117 )
{
T_4 V_118 = ( ( V_80 == V_68 )
? V_119 : V_120 ) ;
T_4 * V_121 = V_117 ;
int V_122 ;
#ifdef F_59
F_38 ( L_18 , V_118 ) ;
#endif
memcpy ( V_121 , V_123 , 4 ) ;
V_121 += 4 ;
* V_121 ++ = 53 ;
* V_121 ++ = 1 ;
* V_121 ++ = V_118 ;
if ( V_118 == V_120 ) {
* V_121 ++ = 54 ;
* V_121 ++ = 4 ;
memcpy ( V_121 , & V_80 , 4 ) ;
V_121 += 4 ;
* V_121 ++ = 50 ;
* V_121 ++ = 4 ;
memcpy ( V_121 , & V_58 , 4 ) ;
V_121 += 4 ;
}
{
static const T_4 V_124 [] = {
1 ,
3 ,
6 ,
12 ,
15 ,
17 ,
26 ,
40 ,
} ;
* V_121 ++ = 55 ;
* V_121 ++ = sizeof( V_124 ) ;
memcpy ( V_121 , V_124 , sizeof( V_124 ) ) ;
V_121 += sizeof( V_124 ) ;
if ( V_77 ) {
* V_121 ++ = 12 ;
V_122 = strlen ( F_60 () -> V_78 ) ;
* V_121 ++ = V_122 ;
memcpy ( V_121 , F_60 () -> V_78 , V_122 ) ;
V_121 += V_122 ;
}
if ( * V_125 ) {
F_16 ( L_19 ,
V_125 ) ;
* V_121 ++ = 60 ;
V_122 = strlen ( V_125 ) ;
* V_121 ++ = V_122 ;
memcpy ( V_121 , V_125 , V_122 ) ;
V_121 += V_122 ;
}
}
* V_121 ++ = 255 ;
}
static void T_1 F_61 ( T_4 * V_121 )
{
memcpy ( V_121 , V_123 , 4 ) ;
V_121 += 4 ;
* V_121 ++ = 1 ;
* V_121 ++ = 4 ;
V_121 += 4 ;
* V_121 ++ = 3 ;
* V_121 ++ = 4 ;
V_121 += 4 ;
* V_121 ++ = 5 ;
* V_121 ++ = 8 ;
V_121 += 8 ;
* V_121 ++ = 12 ;
* V_121 ++ = 32 ;
V_121 += 32 ;
* V_121 ++ = 40 ;
* V_121 ++ = 32 ;
V_121 += 32 ;
* V_121 ++ = 17 ;
* V_121 ++ = 40 ;
V_121 += 40 ;
* V_121 ++ = 57 ;
* V_121 ++ = 2 ;
* V_121 ++ = 1 ;
* V_121 ++ = 150 ;
* V_121 ++ = 255 ;
}
static inline void T_1 F_62 ( void )
{
F_57 () ;
F_40 ( & V_126 ) ;
}
static inline void T_1 F_63 ( void )
{
F_42 ( & V_126 ) ;
}
static void T_1 F_64 ( struct V_9 * V_10 , unsigned long V_127 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_85 * V_86 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
int V_132 = F_65 ( V_2 ) ;
int V_133 = V_2 -> V_134 ;
V_86 = F_66 ( sizeof( struct V_128 ) + V_132 + V_133 + 15 ,
V_23 ) ;
if ( ! V_86 )
return;
F_67 ( V_86 , V_132 ) ;
V_129 = (struct V_128 * ) F_68 ( V_86 , sizeof( struct V_128 ) ) ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
F_69 ( V_86 ) ;
V_131 = F_70 ( V_86 ) ;
V_131 -> V_135 = 4 ;
V_131 -> V_136 = 5 ;
V_131 -> V_137 = F_50 ( sizeof( struct V_128 ) ) ;
V_131 -> V_138 = F_50 ( V_139 ) ;
V_131 -> V_140 = 64 ;
V_131 -> V_141 = V_142 ;
V_131 -> V_143 = F_35 ( V_144 ) ;
V_131 -> V_145 = F_71 ( ( unsigned char * ) V_131 , V_131 -> V_136 ) ;
V_129 -> V_146 . V_147 = F_50 ( 68 ) ;
V_129 -> V_146 . V_148 = F_50 ( 67 ) ;
V_129 -> V_146 . V_122 = F_50 ( sizeof( struct V_128 ) - sizeof( struct V_130 ) ) ;
V_129 -> V_149 = V_150 ;
if ( V_2 -> type < 256 )
V_129 -> V_151 = V_2 -> type ;
else if ( V_2 -> type == V_152 )
V_129 -> V_151 = V_153 ;
else {
F_38 ( L_20 , V_2 -> type , V_2 -> V_6 ) ;
V_129 -> V_151 = V_2 -> type ;
}
V_129 -> V_132 = V_2 -> V_101 ;
memcpy ( V_129 -> V_154 , V_2 -> V_110 , V_2 -> V_101 ) ;
V_129 -> V_155 = F_50 ( V_127 / V_156 ) ;
V_129 -> V_26 = V_10 -> V_26 ;
#ifdef F_72
if ( V_22 & V_157 )
F_58 ( V_129 -> V_158 ) ;
else
#endif
F_61 ( V_129 -> V_158 ) ;
V_86 -> V_2 = V_2 ;
V_86 -> V_141 = F_50 ( V_106 ) ;
if ( F_73 ( V_86 , V_2 , F_49 ( V_86 -> V_141 ) ,
V_2 -> V_159 , V_2 -> V_110 , V_86 -> V_122 ) < 0 ) {
F_54 ( V_86 ) ;
F_38 ( L_21 ) ;
return;
}
if ( F_74 ( V_86 ) < 0 )
F_38 ( L_21 ) ;
}
static int T_1 F_75 ( char * V_148 , char * V_160 , int V_122 , int V_161 )
{
if ( ! V_122 )
return 0 ;
if ( V_122 > V_161 - 1 )
V_122 = V_161 - 1 ;
memcpy ( V_148 , V_160 , V_122 ) ;
V_148 [ V_122 ] = '\0' ;
return 1 ;
}
static void T_1 F_76 ( T_4 * V_162 )
{
T_4 V_163 ;
int V_114 ;
T_2 V_18 ;
#ifdef F_59
T_4 * V_164 ;
F_38 ( L_22 , * V_162 ) ;
for ( V_164 = V_162 + 2 ; V_164 < V_162 + 2 + V_162 [ 1 ] ; V_164 ++ )
F_38 ( L_23 , * V_164 ) ;
F_38 ( L_24 ) ;
#endif
switch ( * V_162 ++ ) {
case 1 :
if ( V_60 == V_68 )
memcpy ( & V_60 , V_162 + 1 , 4 ) ;
break;
case 3 :
if ( V_67 == V_68 )
memcpy ( & V_67 , V_162 + 1 , 4 ) ;
break;
case 6 :
V_163 = * V_162 / 4 ;
if ( V_163 > V_115 )
V_163 = V_115 ;
for ( V_114 = 0 ; V_114 < V_163 ; V_114 ++ ) {
if ( V_116 [ V_114 ] == V_68 )
memcpy ( & V_116 [ V_114 ] , V_162 + 1 + 4 * V_114 , 4 ) ;
}
break;
case 12 :
F_75 ( F_60 () -> V_78 , V_162 + 1 , * V_162 ,
V_165 ) ;
V_77 = 1 ;
break;
case 15 :
F_75 ( V_166 , V_162 + 1 , * V_162 , sizeof( V_166 ) ) ;
break;
case 17 :
if ( ! V_167 [ 0 ] )
F_75 ( V_167 , V_162 + 1 , * V_162 ,
sizeof( V_167 ) ) ;
break;
case 26 :
memcpy ( & V_18 , V_162 + 1 , sizeof( V_18 ) ) ;
V_63 = F_49 ( V_18 ) ;
break;
case 40 :
F_75 ( F_60 () -> V_168 , V_162 + 1 , * V_162 ,
V_165 ) ;
break;
}
}
static int T_1 F_77 ( struct V_85 * V_86 , struct V_1 * V_2 , struct V_87 * V_88 , struct V_1 * V_89 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_9 * V_10 ;
int V_122 , V_169 ;
if ( ! F_44 ( F_45 ( V_2 ) , & V_49 ) )
goto V_97;
if ( V_86 -> V_170 == V_171 )
goto V_97;
if ( ( V_86 = F_46 ( V_86 , V_98 ) ) == NULL )
return V_99 ;
if ( ! F_47 ( V_86 ,
sizeof( struct V_130 ) +
sizeof( struct V_172 ) ) )
goto V_97;
V_129 = (struct V_128 * ) F_78 ( V_86 ) ;
V_131 = & V_129 -> V_173 ;
if ( V_131 -> V_136 != 5 || V_131 -> V_135 != 4 || V_131 -> V_141 != V_142 )
goto V_97;
if ( F_79 ( V_131 ) ) {
F_80 ( L_25 ) ;
goto V_97;
}
if ( V_86 -> V_122 < F_49 ( V_131 -> V_137 ) )
goto V_97;
if ( F_71 ( ( char * ) V_131 , V_131 -> V_136 ) )
goto V_97;
if ( V_129 -> V_146 . V_147 != F_50 ( 67 ) || V_129 -> V_146 . V_148 != F_50 ( 68 ) )
goto V_97;
if ( F_49 ( V_131 -> V_137 ) < F_49 ( V_129 -> V_146 . V_122 ) + sizeof( struct V_130 ) )
goto V_97;
V_122 = F_49 ( V_129 -> V_146 . V_122 ) - sizeof( struct V_172 ) ;
V_169 = V_122 - ( sizeof( * V_129 ) -
sizeof( struct V_130 ) -
sizeof( struct V_172 ) -
sizeof( V_129 -> V_158 ) ) ;
if ( V_169 < 0 )
goto V_97;
if ( ! F_47 ( V_86 , V_86 -> V_122 ) )
goto V_97;
V_129 = (struct V_128 * ) F_78 ( V_86 ) ;
V_131 = & V_129 -> V_173 ;
F_52 ( & V_107 ) ;
if ( V_108 )
goto V_109;
V_10 = V_15 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_25 ;
if ( ! V_10 )
goto V_109;
if ( V_129 -> V_149 != V_174 ||
V_129 -> V_26 != V_10 -> V_26 ) {
F_80 ( L_26 ,
V_129 -> V_149 , V_129 -> V_26 ) ;
goto V_109;
}
if ( V_129 -> V_26 != V_175 ) {
F_80 ( L_27 ) ;
goto V_109;
}
if ( V_169 >= 4 &&
! memcmp ( V_129 -> V_158 , V_123 , 4 ) ) {
T_4 * V_176 = ( T_4 * ) V_129 + F_49 ( V_129 -> V_173 . V_137 ) ;
T_4 * V_162 ;
#ifdef F_72
if ( V_22 & V_157 ) {
V_27 V_177 = V_68 ;
int V_118 = 0 ;
V_162 = & V_129 -> V_158 [ 4 ] ;
while ( V_162 < V_176 && * V_162 != 0xff ) {
T_4 * V_178 = V_162 ++ ;
if ( * V_178 == 0 )
continue;
V_162 += * V_162 + 1 ;
if ( V_162 >= V_176 )
break;
switch ( * V_178 ) {
case 53 :
if ( V_178 [ 1 ] )
V_118 = V_178 [ 2 ] ;
break;
case 54 :
if ( V_178 [ 1 ] >= 4 )
memcpy ( & V_177 , V_178 + 2 , 4 ) ;
break;
}
}
#ifdef F_59
F_38 ( L_28 , V_118 ) ;
#endif
switch ( V_118 ) {
case V_179 :
if ( V_58 != V_68 )
goto V_109;
V_58 = V_129 -> V_180 ;
V_80 = V_177 ;
#ifdef F_59
F_38 ( L_29 ,
& V_58 , & V_129 -> V_173 . V_181 ) ;
#endif
if ( ( V_177 != V_68 ) &&
( V_129 -> V_182 != V_177 ) )
V_129 -> V_182 = V_80 ;
break;
case V_183 :
if ( memcmp ( V_2 -> V_110 , V_129 -> V_154 , V_2 -> V_101 ) != 0 )
goto V_109;
break;
default:
V_58 = V_68 ;
V_80 = V_68 ;
goto V_109;
}
V_184 = V_118 ;
}
#endif
V_162 = & V_129 -> V_158 [ 4 ] ;
while ( V_162 < V_176 && * V_162 != 0xff ) {
T_4 * V_178 = V_162 ++ ;
if ( * V_178 == 0 )
continue;
V_162 += * V_162 + 1 ;
if ( V_162 < V_176 )
F_76 ( V_178 ) ;
}
}
V_35 = V_2 ;
V_58 = V_129 -> V_180 ;
V_80 = V_129 -> V_182 ;
V_111 = V_129 -> V_173 . V_181 ;
if ( V_67 == V_68 && V_129 -> V_185 )
V_67 = V_129 -> V_185 ;
if ( V_116 [ 0 ] == V_68 )
V_116 [ 0 ] = V_80 ;
V_108 = V_19 ;
V_109:
F_53 ( & V_107 ) ;
V_97:
F_54 ( V_86 ) ;
return 0 ;
}
static int T_1 F_81 ( void )
{
int V_186 ;
struct V_9 * V_10 ;
unsigned long V_187 , V_188 , V_189 ;
int V_190 = V_28 & V_19 ;
int V_191 = V_28 & V_21 ;
if ( ! V_22 ) {
F_6 ( L_30 ) ;
return - 1 ;
}
#ifdef F_82
if ( ( V_22 ^ V_28 ) & V_19 )
F_6 ( L_31 ) ;
#endif
#ifdef F_83
if ( ( V_22 ^ V_28 ) & V_21 )
F_6 ( L_32 ) ;
#endif
if ( ! V_28 )
return - 1 ;
#ifdef F_82
if ( V_190 )
F_62 () ;
#endif
#ifdef F_83
if ( V_191 )
F_39 () ;
#endif
F_84 ( L_33 ,
V_190
? ( ( V_22 & V_157 ) ? L_34 : L_35 ) : L_36 ,
( V_190 && V_191 ) ? L_37 : L_36 ,
V_191 ? L_38 : L_36 ) ;
V_187 = V_30 ;
V_10 = V_15 ;
V_186 = V_192 ;
F_10 ( & V_188 , sizeof( V_188 ) ) ;
V_188 = V_193 + ( V_188 % ( unsigned int ) V_194 ) ;
for (; ; ) {
V_175 = V_10 -> V_26 ;
#ifdef F_82
if ( V_190 && ( V_10 -> V_17 & V_19 ) )
F_64 ( V_10 , V_30 - V_187 ) ;
#endif
#ifdef F_83
if ( V_191 && ( V_10 -> V_17 & V_21 ) )
F_55 ( V_10 ) ;
#endif
V_189 = V_30 + ( V_10 -> V_25 ? V_195 : V_188 ) ;
while ( F_85 ( V_30 , V_189 ) && ! V_108 )
F_86 ( 1 ) ;
#ifdef F_72
if ( ( V_108 & V_19 ) &&
( V_22 & V_157 ) &&
V_184 != V_183 ) {
V_108 = 0 ;
F_87 ( L_39 ) ;
continue;
}
#endif
if ( V_108 ) {
F_87 ( L_40 ) ;
break;
}
if ( ( V_10 = V_10 -> V_25 ) )
continue;
if ( ! -- V_186 ) {
F_87 ( L_41 ) ;
break;
}
V_10 = V_15 ;
V_188 = V_188 V_196 ;
if ( V_188 > V_197 )
V_188 = V_197 ;
F_87 ( L_42 ) ;
}
#ifdef F_82
if ( V_190 )
F_63 () ;
#endif
#ifdef F_83
if ( V_191 )
F_41 () ;
#endif
if ( ! V_108 ) {
V_58 = V_68 ;
return - 1 ;
}
F_38 ( L_43 ,
( ( V_108 & V_21 ) ? L_38
: ( V_22 & V_157 ) ? L_34 : L_35 ) ,
& V_111 ) ;
F_87 ( L_44 , & V_58 ) ;
return 0 ;
}
static int F_88 ( struct V_198 * V_199 , void * V_200 )
{
int V_114 ;
if ( V_201 & V_202 )
F_89 ( V_199 , L_45 ,
( V_201 & V_21 ) ? L_38
: ( V_201 & V_157 ) ? L_34 : L_35 ) ;
else
F_90 ( V_199 , L_46 ) ;
if ( V_166 [ 0 ] )
F_89 ( V_199 ,
L_47 , V_166 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ ) {
if ( V_116 [ V_114 ] != V_68 )
F_89 ( V_199 , L_48 ,
& V_116 [ V_114 ] ) ;
}
if ( V_80 != V_68 )
F_89 ( V_199 , L_49 ,
& V_80 ) ;
return 0 ;
}
static int F_91 ( struct V_203 * V_204 , struct V_205 * V_205 )
{
return F_92 ( V_205 , F_88 , NULL ) ;
}
V_27 T_1 F_93 ( char * V_6 )
{
V_27 V_37 ;
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
V_37 = F_94 ( V_6 ) ;
memmove ( V_6 , V_207 , strlen ( V_207 ) + 1 ) ;
} else
V_37 = V_68 ;
return V_37 ;
}
static int T_1 F_95 ( void )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_209 ; V_114 ++ ) {
struct V_1 * V_2 ;
int V_210 = 0 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
V_210 = 1 ;
break;
}
}
F_9 () ;
if ( V_210 )
return 0 ;
F_96 ( 1 ) ;
}
return - V_34 ;
}
static int T_1 F_97 ( void )
{
V_27 V_37 ;
#ifdef F_98
int V_186 = V_211 ;
#endif
int V_55 ;
unsigned int V_114 ;
#ifdef F_99
F_100 ( L_50 , V_212 , V_49 . V_213 , & V_214 ) ;
#endif
if ( ! V_215 )
return 0 ;
F_11 ( ( L_51 ) ) ;
#ifdef F_98
V_216:
#endif
V_55 = F_95 () ;
if ( V_55 )
return V_55 ;
V_55 = F_2 () ;
if ( V_55 )
return V_55 ;
F_14 ( V_217 ) ;
if ( V_58 == V_68 ||
#ifdef F_101
( V_79 == V_68 &&
V_80 == V_68 &&
V_218 == V_219 ) ||
#endif
V_15 -> V_25 ) {
#ifdef F_98
if ( F_81 () < 0 ) {
F_17 () ;
#ifdef F_101
if ( V_218 == V_219 ) {
F_6 ( L_52 ) ;
goto V_216;
}
#endif
if ( -- V_186 ) {
F_6 ( L_53 ) ;
goto V_216;
}
F_6 ( L_54 ) ;
return - 1 ;
}
#else
F_6 ( L_30 ) ;
F_17 () ;
return - 1 ;
#endif
} else {
V_35 = V_15 -> V_2 ;
}
V_37 = F_93 ( V_167 ) ;
if ( V_79 == V_68 )
V_79 = V_37 ;
if ( F_31 () < 0 )
return - 1 ;
F_17 () ;
if ( F_29 () < 0 || F_30 () < 0 )
return - 1 ;
#ifdef F_98
V_201 = V_108 | ( V_22 & V_157 ) ;
#endif
#ifndef F_102
F_16 ( L_55 ) ;
F_16 ( L_56 ,
V_35 -> V_6 , V_35 -> V_101 , V_35 -> V_110 ,
& V_58 , & V_60 , & V_67 ) ;
F_16 ( L_57 ,
F_60 () -> V_78 , V_166 , F_60 () -> V_168 ) ;
F_16 ( L_58 ,
& V_80 , & V_79 , V_167 ) ;
if ( V_63 )
F_87 ( L_59 , V_63 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
if ( V_116 [ V_114 ] != V_68 ) {
F_16 ( L_60 ,
V_114 , & V_116 [ V_114 ] ) ;
break;
}
for ( V_114 ++ ; V_114 < V_115 ; V_114 ++ )
if ( V_116 [ V_114 ] != V_68 )
F_87 ( L_61 , V_114 , & V_116 [ V_114 ] ) ;
F_87 ( L_24 ) ;
#endif
return 0 ;
}
static int T_1 F_103 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_62 ) || ! strcmp ( V_6 , L_63 ) ) {
return 1 ;
}
if ( ! strcmp ( V_6 , L_64 ) || ! strcmp ( V_6 , L_65 ) ) {
return 0 ;
}
#ifdef F_104
else if ( ! strcmp ( V_6 , L_66 ) ) {
V_22 &= ~ V_21 ;
return 1 ;
}
#endif
#ifdef F_105
else if ( ! strcmp ( V_6 , L_67 ) ) {
V_22 &= ~ ( V_21 | V_157 ) ;
return 1 ;
}
#endif
#ifdef F_106
else if ( ! strcmp ( V_6 , L_68 ) ) {
V_22 &= ~ ( V_19 | V_157 ) ;
return 1 ;
}
#endif
#ifdef F_98
else if ( ! strcmp ( V_6 , L_69 ) ) {
V_22 &= ~ V_157 ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_107 ( char * V_220 )
{
char * V_207 , * V_221 , * V_222 ;
int V_223 = 0 ;
V_224 = 1 ;
V_215 = 1 ;
if ( F_103 ( V_220 ) )
return 1 ;
if ( * V_220 == 0 ||
strcmp ( V_220 , L_64 ) == 0 ||
strcmp ( V_220 , L_65 ) == 0 ) {
V_215 = 0 ;
return 1 ;
}
F_57 () ;
V_221 = V_220 ;
while ( V_221 && * V_221 ) {
if ( ( V_207 = strchr ( V_221 , ':' ) ) )
* V_207 ++ = '\0' ;
if ( strlen ( V_221 ) > 0 ) {
F_11 ( ( L_70 , V_223 , V_221 ) ) ;
switch ( V_223 ) {
case 0 :
if ( ( V_58 = F_94 ( V_221 ) ) == V_225 )
V_58 = V_68 ;
break;
case 1 :
if ( ( V_80 = F_94 ( V_221 ) ) == V_225 )
V_80 = V_68 ;
break;
case 2 :
if ( ( V_67 = F_94 ( V_221 ) ) == V_225 )
V_67 = V_68 ;
break;
case 3 :
if ( ( V_60 = F_94 ( V_221 ) ) == V_225 )
V_60 = V_68 ;
break;
case 4 :
if ( ( V_222 = strchr ( V_221 , '.' ) ) ) {
* V_222 ++ = '\0' ;
F_108 ( F_60 () -> V_168 , V_222 ,
sizeof( F_60 () -> V_168 ) ) ;
}
F_108 ( F_60 () -> V_78 , V_221 ,
sizeof( F_60 () -> V_78 ) ) ;
V_77 = 1 ;
break;
case 5 :
F_108 ( V_5 , V_221 , sizeof( V_5 ) ) ;
break;
case 6 :
if ( F_103 ( V_221 ) == 0 &&
V_58 == V_68 ) {
V_215 = 0 ;
}
break;
case 7 :
if ( V_115 >= 1 ) {
V_116 [ 0 ] = F_94 ( V_221 ) ;
if ( V_116 [ 0 ] == V_225 )
V_116 [ 0 ] = V_68 ;
}
break;
case 8 :
if ( V_115 >= 2 ) {
V_116 [ 1 ] = F_94 ( V_221 ) ;
if ( V_116 [ 1 ] == V_225 )
V_116 [ 1 ] = V_68 ;
}
break;
}
}
V_221 = V_207 ;
V_223 ++ ;
}
return 1 ;
}
static int T_1 F_109 ( char * V_220 )
{
return F_107 ( V_220 ) ;
}
static int T_1 F_110 ( char * V_220 )
{
if ( F_108 ( V_125 , V_220 ,
sizeof( V_125 ) )
>= sizeof( V_125 ) )
F_7 ( L_71 ,
V_125 ) ;
return 1 ;
}
