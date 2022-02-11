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
if ( ! ( V_2 -> V_3 & V_4 ) && ! F_5 ( V_2 ) )
continue;
if ( F_6 ( V_2 , V_2 -> V_3 | V_16 ) < 0 )
F_7 ( L_2 , V_2 -> V_6 ) ;
}
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
int V_17 = 0 ;
if ( V_2 -> V_18 >= 364 )
V_17 |= V_19 ;
else
F_8 ( L_3 ,
V_2 -> V_6 , V_2 -> V_18 ) ;
if ( ! ( V_2 -> V_3 & V_20 ) )
V_17 |= V_21 ;
V_17 &= V_22 ;
if ( V_22 && ! V_17 )
continue;
V_12 = V_2 -> V_3 ;
if ( F_6 ( V_2 , V_12 | V_16 ) < 0 ) {
F_7 ( L_2 ,
V_2 -> V_6 ) ;
continue;
}
if ( ! ( V_10 = F_9 ( sizeof( struct V_9 ) , V_23 ) ) ) {
F_10 () ;
return - V_24 ;
}
V_10 -> V_2 = V_2 ;
* V_11 = V_10 ;
V_11 = & V_10 -> V_25 ;
V_10 -> V_3 = V_12 ;
V_10 -> V_17 = V_17 ;
if ( V_17 & V_19 )
F_11 ( & V_10 -> V_26 , sizeof( V_27 ) ) ;
else
V_10 -> V_26 = 0 ;
V_28 |= V_17 ;
F_12 ( ( L_4 ,
V_2 -> V_6 , V_17 , V_10 -> V_26 ) ) ;
}
}
if ( ! V_15 )
goto V_29;
V_13 = V_30 ;
V_14 = V_13 + F_13 ( V_31 / 12 ) ;
while ( F_14 ( V_30 , V_13 +
F_13 ( V_31 ) ) ) {
int V_32 , V_33 ;
F_4 (&init_net, dev)
if ( F_1 ( V_2 ) && F_15 ( V_2 ) )
goto V_29;
F_16 ( 1 ) ;
if ( F_14 ( V_30 , V_14 ) )
continue;
V_33 = F_17 ( V_30 - V_13 ) ;
V_32 = ( V_31 - V_33 + 500 ) / 1000 ;
F_18 ( L_5 , V_32 ) ;
V_14 = V_30 + F_13 ( V_31 / 12 ) ;
}
V_29:
F_10 () ;
* V_11 = NULL ;
if ( ! V_15 ) {
if ( V_5 [ 0 ] )
F_7 ( L_6 ,
V_5 ) ;
else
F_7 ( L_7 ) ;
return - V_34 ;
}
return 0 ;
}
static void T_1 F_19 ( void )
{
struct V_9 * V_10 , * V_25 ;
struct V_1 * V_2 ;
F_3 () ;
V_25 = V_15 ;
while ( ( V_10 = V_25 ) ) {
V_25 = V_10 -> V_25 ;
V_2 = V_10 -> V_2 ;
if ( V_2 != V_35 && ! F_5 ( V_2 ) ) {
F_12 ( ( L_8 , V_2 -> V_6 ) ) ;
F_6 ( V_2 , V_10 -> V_3 ) ;
}
F_20 ( V_10 ) ;
}
F_10 () ;
}
static inline void
F_21 ( struct V_36 * sin , V_27 V_37 , T_2 V_38 )
{
sin -> V_39 = V_40 ;
sin -> V_41 . V_42 = V_37 ;
sin -> V_43 = V_38 ;
}
static int T_1 F_22 ( unsigned int V_44 , struct V_45 * V_46 )
{
int V_47 ;
T_3 V_48 = F_23 () ;
F_24 ( F_25 () ) ;
V_47 = F_26 ( & V_49 , V_44 , (struct V_45 V_50 * ) V_46 ) ;
F_24 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_27 ( unsigned int V_44 , struct V_45 * V_46 )
{
int V_47 ;
T_3 V_48 = F_23 () ;
F_24 ( F_25 () ) ;
V_47 = F_28 ( & V_49 , V_44 , (struct V_45 V_50 * ) V_46 ) ;
F_24 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_29 ( unsigned int V_44 , struct V_51 * V_46 )
{
int V_47 ;
T_3 V_48 = F_23 () ;
F_24 ( F_25 () ) ;
V_47 = F_30 ( & V_49 , V_44 , ( void V_50 * ) V_46 ) ;
F_24 ( V_48 ) ;
return V_47 ;
}
static int T_1 F_31 ( void )
{
struct V_45 V_52 ;
struct V_36 * sin = ( void * ) & V_52 . V_53 . V_54 ;
int V_55 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
strcpy ( V_52 . V_56 . V_57 , V_35 -> V_6 ) ;
F_21 ( sin , V_58 , 0 ) ;
if ( ( V_55 = F_22 ( V_59 , & V_52 ) ) < 0 ) {
F_7 ( L_9 ,
V_55 ) ;
return - 1 ;
}
F_21 ( sin , V_60 , 0 ) ;
if ( ( V_55 = F_22 ( V_61 , & V_52 ) ) < 0 ) {
F_7 ( L_10 ,
V_55 ) ;
return - 1 ;
}
F_21 ( sin , V_58 | ~ V_60 , 0 ) ;
if ( ( V_55 = F_22 ( V_62 , & V_52 ) ) < 0 ) {
F_7 ( L_11 ,
V_55 ) ;
return - 1 ;
}
if ( V_63 != 0 ) {
strcpy ( V_52 . V_64 , V_35 -> V_6 ) ;
V_52 . V_65 = V_63 ;
if ( ( V_55 = F_27 ( V_66 , & V_52 ) ) < 0 )
F_7 ( L_12 ,
V_63 , V_55 ) ;
}
return 0 ;
}
static int T_1 F_32 ( void )
{
if ( V_67 != V_68 ) {
struct V_51 V_69 ;
int V_55 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( ( V_67 ^ V_58 ) & V_60 ) {
F_7 ( L_13 ) ;
return - 1 ;
}
F_21 ( (struct V_36 * ) & V_69 . V_70 , 0 , 0 ) ;
F_21 ( (struct V_36 * ) & V_69 . V_71 , 0 , 0 ) ;
F_21 ( (struct V_36 * ) & V_69 . V_72 , V_67 , 0 ) ;
V_69 . V_73 = V_74 | V_75 ;
if ( ( V_55 = F_29 ( V_76 , & V_69 ) ) < 0 ) {
F_7 ( L_14 ,
V_55 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_1 F_33 ( void )
{
if ( ! V_77 )
sprintf ( F_34 () -> V_78 , L_15 , & V_58 ) ;
if ( V_79 == V_68 )
V_79 = V_80 ;
if ( V_60 == V_68 ) {
if ( F_35 ( F_36 ( V_58 ) ) )
V_60 = F_37 ( V_81 ) ;
else if ( F_38 ( F_36 ( V_58 ) ) )
V_60 = F_37 ( V_82 ) ;
else if ( F_39 ( F_36 ( V_58 ) ) )
V_60 = F_37 ( V_83 ) ;
else {
F_7 ( L_16 ,
& V_58 ) ;
return - 1 ;
}
F_40 ( L_17 , & V_60 ) ;
}
return 0 ;
}
static inline void T_1 F_41 ( void )
{
F_42 ( & V_84 ) ;
}
static inline void T_1 F_43 ( void )
{
F_44 ( & V_84 ) ;
}
static int T_1
F_45 ( struct V_85 * V_86 , struct V_1 * V_2 , struct V_87 * V_88 , struct V_1 * V_89 )
{
struct V_90 * V_91 ;
unsigned char * V_92 ;
V_27 V_93 , V_94 ;
unsigned char * V_95 ;
struct V_9 * V_10 ;
if ( ! F_46 ( F_47 ( V_2 ) , & V_49 ) )
goto V_96;
V_86 = F_48 ( V_86 , V_97 ) ;
if ( ! V_86 )
return V_98 ;
if ( ! F_49 ( V_86 , sizeof( struct V_90 ) ) )
goto V_96;
V_91 = (struct V_90 * ) F_50 ( V_86 ) ;
if ( V_91 -> V_99 != V_2 -> V_100 || V_2 -> type != F_51 ( V_91 -> V_101 ) )
goto V_96;
if ( V_91 -> V_102 != F_52 ( V_103 ) )
goto V_96;
if ( V_91 -> V_104 != F_52 ( V_105 ) )
goto V_96;
if ( ! F_49 ( V_86 , F_53 ( V_2 ) ) )
goto V_96;
V_91 = (struct V_90 * ) F_50 ( V_86 ) ;
V_92 = ( unsigned char * ) ( V_91 + 1 ) ;
F_54 ( & V_106 ) ;
if ( V_107 )
goto V_108;
V_10 = V_15 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_25 ;
if ( ! V_10 )
goto V_108;
V_92 += V_2 -> V_100 ;
memcpy ( & V_93 , V_92 , 4 ) ;
V_92 += 4 ;
V_95 = V_92 ;
V_92 += V_2 -> V_100 ;
memcpy ( & V_94 , V_92 , 4 ) ;
if ( memcmp ( V_95 , V_2 -> V_109 , V_2 -> V_100 ) )
goto V_108;
if ( V_80 != V_68 && V_80 != V_93 )
goto V_108;
V_35 = V_2 ;
if ( V_58 == V_68 )
V_58 = V_94 ;
V_80 = V_93 ;
V_110 = V_93 ;
V_107 = V_21 ;
V_108:
F_55 ( & V_106 ) ;
V_96:
F_56 ( V_86 ) ;
return 0 ;
}
static void T_1 F_57 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_58 ( V_111 , V_112 , 0 , V_2 , 0 , NULL ,
V_2 -> V_109 , V_2 -> V_109 ) ;
}
static inline void T_1 F_59 ( void )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
V_115 [ V_113 ] = V_68 ;
}
static void T_1
F_60 ( T_4 * V_116 )
{
T_4 V_117 = ( ( V_80 == V_68 )
? V_118 : V_119 ) ;
T_4 * V_120 = V_116 ;
int V_121 ;
#ifdef F_61
F_40 ( L_18 , V_117 ) ;
#endif
memcpy ( V_120 , V_122 , 4 ) ;
V_120 += 4 ;
* V_120 ++ = 53 ;
* V_120 ++ = 1 ;
* V_120 ++ = V_117 ;
if ( V_117 == V_119 ) {
* V_120 ++ = 54 ;
* V_120 ++ = 4 ;
memcpy ( V_120 , & V_80 , 4 ) ;
V_120 += 4 ;
* V_120 ++ = 50 ;
* V_120 ++ = 4 ;
memcpy ( V_120 , & V_58 , 4 ) ;
V_120 += 4 ;
}
{
static const T_4 V_123 [] = {
1 ,
3 ,
6 ,
12 ,
15 ,
17 ,
26 ,
40 ,
} ;
* V_120 ++ = 55 ;
* V_120 ++ = sizeof( V_123 ) ;
memcpy ( V_120 , V_123 , sizeof( V_123 ) ) ;
V_120 += sizeof( V_123 ) ;
if ( V_77 ) {
* V_120 ++ = 12 ;
V_121 = strlen ( F_62 () -> V_78 ) ;
* V_120 ++ = V_121 ;
memcpy ( V_120 , F_62 () -> V_78 , V_121 ) ;
V_120 += V_121 ;
}
if ( * V_124 ) {
F_18 ( L_19 ,
V_124 ) ;
* V_120 ++ = 60 ;
V_121 = strlen ( V_124 ) ;
* V_120 ++ = V_121 ;
memcpy ( V_120 , V_124 , V_121 ) ;
V_120 += V_121 ;
}
V_121 = strlen ( V_125 + 1 ) ;
if ( V_121 >= 1 && V_121 < 312 - ( V_120 - V_116 ) - 1 ) {
* V_120 ++ = 61 ;
* V_120 ++ = V_121 + 1 ;
memcpy ( V_120 , V_125 , V_121 + 1 ) ;
V_120 += V_121 + 1 ;
}
}
* V_120 ++ = 255 ;
}
static void T_1 F_63 ( T_4 * V_120 )
{
memcpy ( V_120 , V_122 , 4 ) ;
V_120 += 4 ;
* V_120 ++ = 1 ;
* V_120 ++ = 4 ;
V_120 += 4 ;
* V_120 ++ = 3 ;
* V_120 ++ = 4 ;
V_120 += 4 ;
* V_120 ++ = 5 ;
* V_120 ++ = 8 ;
V_120 += 8 ;
* V_120 ++ = 12 ;
* V_120 ++ = 32 ;
V_120 += 32 ;
* V_120 ++ = 40 ;
* V_120 ++ = 32 ;
V_120 += 32 ;
* V_120 ++ = 17 ;
* V_120 ++ = 40 ;
V_120 += 40 ;
* V_120 ++ = 57 ;
* V_120 ++ = 2 ;
* V_120 ++ = 1 ;
* V_120 ++ = 150 ;
* V_120 ++ = 255 ;
}
static inline void T_1 F_64 ( void )
{
F_59 () ;
F_42 ( & V_126 ) ;
}
static inline void T_1 F_65 ( void )
{
F_44 ( & V_126 ) ;
}
static void T_1 F_66 ( struct V_9 * V_10 , unsigned long V_127 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_85 * V_86 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
int V_132 = F_67 ( V_2 ) ;
int V_133 = V_2 -> V_134 ;
V_86 = F_68 ( sizeof( struct V_128 ) + V_132 + V_133 + 15 ,
V_23 ) ;
if ( ! V_86 )
return;
F_69 ( V_86 , V_132 ) ;
V_129 = (struct V_128 * ) F_70 ( V_86 , sizeof( struct V_128 ) ) ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
F_71 ( V_86 ) ;
V_131 = F_72 ( V_86 ) ;
V_131 -> V_135 = 4 ;
V_131 -> V_136 = 5 ;
V_131 -> V_137 = F_52 ( sizeof( struct V_128 ) ) ;
V_131 -> V_138 = F_52 ( V_139 ) ;
V_131 -> V_140 = 64 ;
V_131 -> V_141 = V_142 ;
V_131 -> V_143 = F_37 ( V_144 ) ;
V_131 -> V_145 = F_73 ( ( unsigned char * ) V_131 , V_131 -> V_136 ) ;
V_129 -> V_146 . V_147 = F_52 ( 68 ) ;
V_129 -> V_146 . V_148 = F_52 ( 67 ) ;
V_129 -> V_146 . V_121 = F_52 ( sizeof( struct V_128 ) - sizeof( struct V_130 ) ) ;
V_129 -> V_149 = V_150 ;
if ( V_2 -> type < 256 )
V_129 -> V_151 = V_2 -> type ;
else if ( V_2 -> type == V_152 )
V_129 -> V_151 = V_153 ;
else {
F_40 ( L_20 , V_2 -> type , V_2 -> V_6 ) ;
V_129 -> V_151 = V_2 -> type ;
}
V_129 -> V_132 = V_2 -> V_100 ;
memcpy ( V_129 -> V_154 , V_2 -> V_109 , V_2 -> V_100 ) ;
V_129 -> V_155 = F_52 ( V_127 / V_156 ) ;
V_129 -> V_26 = V_10 -> V_26 ;
#ifdef F_74
if ( V_22 & V_157 )
F_60 ( V_129 -> V_158 ) ;
else
#endif
F_63 ( V_129 -> V_158 ) ;
V_86 -> V_2 = V_2 ;
V_86 -> V_141 = F_52 ( V_105 ) ;
if ( F_75 ( V_86 , V_2 , F_51 ( V_86 -> V_141 ) ,
V_2 -> V_159 , V_2 -> V_109 , V_86 -> V_121 ) < 0 ) {
F_56 ( V_86 ) ;
F_40 ( L_21 ) ;
return;
}
if ( F_76 ( V_86 ) < 0 )
F_40 ( L_21 ) ;
}
static int T_1 F_77 ( char * V_148 , char * V_160 , int V_121 , int V_161 )
{
if ( ! V_121 )
return 0 ;
if ( V_121 > V_161 - 1 )
V_121 = V_161 - 1 ;
memcpy ( V_148 , V_160 , V_121 ) ;
V_148 [ V_121 ] = '\0' ;
return 1 ;
}
static void T_1 F_78 ( T_4 * V_162 )
{
T_4 V_163 ;
int V_113 ;
T_2 V_18 ;
#ifdef F_61
T_4 * V_164 ;
F_40 ( L_22 , * V_162 ) ;
for ( V_164 = V_162 + 2 ; V_164 < V_162 + 2 + V_162 [ 1 ] ; V_164 ++ )
F_40 ( L_23 , * V_164 ) ;
F_40 ( L_24 ) ;
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
if ( V_163 > V_114 )
V_163 = V_114 ;
for ( V_113 = 0 ; V_113 < V_163 ; V_113 ++ ) {
if ( V_115 [ V_113 ] == V_68 )
memcpy ( & V_115 [ V_113 ] , V_162 + 1 + 4 * V_113 , 4 ) ;
}
break;
case 12 :
F_77 ( F_62 () -> V_78 , V_162 + 1 , * V_162 ,
V_165 ) ;
V_77 = 1 ;
break;
case 15 :
F_77 ( V_166 , V_162 + 1 , * V_162 , sizeof( V_166 ) ) ;
break;
case 17 :
if ( ! V_167 [ 0 ] )
F_77 ( V_167 , V_162 + 1 , * V_162 ,
sizeof( V_167 ) ) ;
break;
case 26 :
memcpy ( & V_18 , V_162 + 1 , sizeof( V_18 ) ) ;
V_63 = F_51 ( V_18 ) ;
break;
case 40 :
F_77 ( F_62 () -> V_168 , V_162 + 1 , * V_162 ,
V_165 ) ;
break;
}
}
static int T_1 F_79 ( struct V_85 * V_86 , struct V_1 * V_2 , struct V_87 * V_88 , struct V_1 * V_89 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_9 * V_10 ;
int V_121 , V_169 ;
if ( ! F_46 ( F_47 ( V_2 ) , & V_49 ) )
goto V_96;
if ( V_86 -> V_170 == V_171 )
goto V_96;
V_86 = F_48 ( V_86 , V_97 ) ;
if ( ! V_86 )
return V_98 ;
if ( ! F_49 ( V_86 ,
sizeof( struct V_130 ) +
sizeof( struct V_172 ) ) )
goto V_96;
V_129 = (struct V_128 * ) F_80 ( V_86 ) ;
V_131 = & V_129 -> V_173 ;
if ( V_131 -> V_136 != 5 || V_131 -> V_135 != 4 || V_131 -> V_141 != V_142 )
goto V_96;
if ( F_81 ( V_131 ) ) {
F_82 ( L_25 ) ;
goto V_96;
}
if ( V_86 -> V_121 < F_51 ( V_131 -> V_137 ) )
goto V_96;
if ( F_73 ( ( char * ) V_131 , V_131 -> V_136 ) )
goto V_96;
if ( V_129 -> V_146 . V_147 != F_52 ( 67 ) || V_129 -> V_146 . V_148 != F_52 ( 68 ) )
goto V_96;
if ( F_51 ( V_131 -> V_137 ) < F_51 ( V_129 -> V_146 . V_121 ) + sizeof( struct V_130 ) )
goto V_96;
V_121 = F_51 ( V_129 -> V_146 . V_121 ) - sizeof( struct V_172 ) ;
V_169 = V_121 - ( sizeof( * V_129 ) -
sizeof( struct V_130 ) -
sizeof( struct V_172 ) -
sizeof( V_129 -> V_158 ) ) ;
if ( V_169 < 0 )
goto V_96;
if ( ! F_49 ( V_86 , V_86 -> V_121 ) )
goto V_96;
V_129 = (struct V_128 * ) F_80 ( V_86 ) ;
V_131 = & V_129 -> V_173 ;
F_54 ( & V_106 ) ;
if ( V_107 )
goto V_108;
V_10 = V_15 ;
while ( V_10 && V_10 -> V_2 != V_2 )
V_10 = V_10 -> V_25 ;
if ( ! V_10 )
goto V_108;
if ( V_129 -> V_149 != V_174 ||
V_129 -> V_26 != V_10 -> V_26 ) {
F_82 ( L_26 ,
V_129 -> V_149 , V_129 -> V_26 ) ;
goto V_108;
}
if ( V_129 -> V_26 != V_175 ) {
F_82 ( L_27 ) ;
goto V_108;
}
if ( V_169 >= 4 &&
! memcmp ( V_129 -> V_158 , V_122 , 4 ) ) {
T_4 * V_176 = ( T_4 * ) V_129 + F_51 ( V_129 -> V_173 . V_137 ) ;
T_4 * V_162 ;
#ifdef F_74
if ( V_22 & V_157 ) {
V_27 V_177 = V_68 ;
int V_117 = 0 ;
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
V_117 = V_178 [ 2 ] ;
break;
case 54 :
if ( V_178 [ 1 ] >= 4 )
memcpy ( & V_177 , V_178 + 2 , 4 ) ;
break;
}
}
#ifdef F_61
F_40 ( L_28 , V_117 ) ;
#endif
switch ( V_117 ) {
case V_179 :
if ( V_58 != V_68 )
goto V_108;
V_58 = V_129 -> V_180 ;
V_80 = V_177 ;
#ifdef F_61
F_40 ( L_29 ,
& V_58 , & V_129 -> V_173 . V_181 ) ;
#endif
if ( ( V_177 != V_68 ) &&
( V_129 -> V_182 != V_177 ) )
V_129 -> V_182 = V_80 ;
break;
case V_183 :
if ( memcmp ( V_2 -> V_109 , V_129 -> V_154 , V_2 -> V_100 ) != 0 )
goto V_108;
break;
default:
V_58 = V_68 ;
V_80 = V_68 ;
goto V_108;
}
V_184 = V_117 ;
}
#endif
V_162 = & V_129 -> V_158 [ 4 ] ;
while ( V_162 < V_176 && * V_162 != 0xff ) {
T_4 * V_178 = V_162 ++ ;
if ( * V_178 == 0 )
continue;
V_162 += * V_162 + 1 ;
if ( V_162 < V_176 )
F_78 ( V_178 ) ;
}
}
V_35 = V_2 ;
V_58 = V_129 -> V_180 ;
V_80 = V_129 -> V_182 ;
V_110 = V_129 -> V_173 . V_181 ;
if ( V_67 == V_68 && V_129 -> V_185 )
V_67 = V_129 -> V_185 ;
if ( V_115 [ 0 ] == V_68 )
V_115 [ 0 ] = V_80 ;
V_107 = V_19 ;
V_108:
F_55 ( & V_106 ) ;
V_96:
F_56 ( V_86 ) ;
return 0 ;
}
static int T_1 F_83 ( void )
{
int V_186 ;
struct V_9 * V_10 ;
unsigned long V_187 , V_188 , V_189 ;
int V_190 = V_28 & V_19 ;
int V_191 = V_28 & V_21 ;
if ( ! V_22 ) {
F_7 ( L_30 ) ;
return - 1 ;
}
#ifdef F_84
if ( ( V_22 ^ V_28 ) & V_19 )
F_7 ( L_31 ) ;
#endif
#ifdef F_85
if ( ( V_22 ^ V_28 ) & V_21 )
F_7 ( L_32 ) ;
#endif
if ( ! V_28 )
return - 1 ;
#ifdef F_84
if ( V_190 )
F_64 () ;
#endif
#ifdef F_85
if ( V_191 )
F_41 () ;
#endif
F_86 ( L_33 ,
V_190
? ( ( V_22 & V_157 ) ? L_34 : L_35 ) : L_36 ,
( V_190 && V_191 ) ? L_37 : L_36 ,
V_191 ? L_38 : L_36 ) ;
V_187 = V_30 ;
V_10 = V_15 ;
V_186 = V_192 ;
F_11 ( & V_188 , sizeof( V_188 ) ) ;
V_188 = V_193 + ( V_188 % ( unsigned int ) V_194 ) ;
for (; ; ) {
#ifdef F_84
V_175 = V_10 -> V_26 ;
if ( V_190 && ( V_10 -> V_17 & V_19 ) )
F_66 ( V_10 , V_30 - V_187 ) ;
#endif
#ifdef F_85
if ( V_191 && ( V_10 -> V_17 & V_21 ) )
F_57 ( V_10 ) ;
#endif
V_189 = V_30 + ( V_10 -> V_25 ? V_195 : V_188 ) ;
while ( F_14 ( V_30 , V_189 ) && ! V_107 )
F_87 ( 1 ) ;
#ifdef F_74
if ( ( V_107 & V_19 ) &&
( V_22 & V_157 ) &&
V_184 != V_183 ) {
V_107 = 0 ;
F_88 ( L_39 ) ;
continue;
}
#endif
if ( V_107 ) {
F_88 ( L_40 ) ;
break;
}
if ( ( V_10 = V_10 -> V_25 ) )
continue;
if ( ! -- V_186 ) {
F_88 ( L_41 ) ;
break;
}
V_10 = V_15 ;
V_188 = V_188 V_196 ;
if ( V_188 > V_197 )
V_188 = V_197 ;
F_88 ( L_42 ) ;
}
#ifdef F_84
if ( V_190 )
F_65 () ;
#endif
#ifdef F_85
if ( V_191 )
F_43 () ;
#endif
if ( ! V_107 ) {
V_58 = V_68 ;
return - 1 ;
}
F_40 ( L_43 ,
( ( V_107 & V_21 ) ? L_38
: ( V_22 & V_157 ) ? L_34 : L_35 ) ,
& V_110 ) ;
F_88 ( L_44 , & V_58 ) ;
return 0 ;
}
static int F_89 ( struct V_198 * V_199 , void * V_200 )
{
int V_113 ;
if ( V_201 & V_202 )
F_90 ( V_199 , L_45 ,
( V_201 & V_21 ) ? L_38
: ( V_201 & V_157 ) ? L_34 : L_35 ) ;
else
F_91 ( V_199 , L_46 ) ;
if ( V_166 [ 0 ] )
F_90 ( V_199 ,
L_47 , V_166 ) ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
if ( V_115 [ V_113 ] != V_68 )
F_90 ( V_199 , L_48 ,
& V_115 [ V_113 ] ) ;
}
if ( V_80 != V_68 )
F_90 ( V_199 , L_49 ,
& V_80 ) ;
return 0 ;
}
static int F_92 ( struct V_203 * V_204 , struct V_205 * V_205 )
{
return F_93 ( V_205 , F_89 , NULL ) ;
}
V_27 T_1 F_94 ( char * V_6 )
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
V_37 = F_95 ( V_6 ) ;
memmove ( V_6 , V_207 , strlen ( V_207 ) + 1 ) ;
} else
V_37 = V_68 ;
return V_37 ;
}
static int T_1 F_96 ( void )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_209 ; V_113 ++ ) {
struct V_1 * V_2 ;
int V_210 = 0 ;
F_3 () ;
F_4 (&init_net, dev) {
if ( F_1 ( V_2 ) ) {
V_210 = 1 ;
break;
}
}
F_10 () ;
if ( V_210 )
return 0 ;
F_97 ( 1 ) ;
}
return - V_34 ;
}
static int T_1 F_98 ( void )
{
V_27 V_37 ;
#ifdef F_99
int V_186 = V_211 ;
#endif
int V_55 ;
unsigned int V_113 ;
#ifdef F_100
F_101 ( L_50 , V_212 , V_49 . V_213 , & V_214 ) ;
#endif
if ( ! V_215 )
return 0 ;
F_12 ( ( L_51 ) ) ;
#ifdef F_99
V_216:
#endif
V_55 = F_96 () ;
if ( V_55 )
return V_55 ;
V_55 = F_2 () ;
if ( V_55 )
return V_55 ;
F_16 ( V_217 ) ;
if ( V_58 == V_68 ||
#ifdef F_102
( V_79 == V_68 &&
V_80 == V_68 &&
V_218 == V_219 ) ||
#endif
V_15 -> V_25 ) {
#ifdef F_99
if ( F_83 () < 0 ) {
F_19 () ;
#ifdef F_102
if ( V_218 == V_219 ) {
F_7 ( L_52 ) ;
goto V_216;
}
#endif
if ( -- V_186 ) {
F_7 ( L_53 ) ;
goto V_216;
}
F_7 ( L_54 ) ;
return - 1 ;
}
#else
F_7 ( L_30 ) ;
F_19 () ;
return - 1 ;
#endif
} else {
V_35 = V_15 -> V_2 ;
}
V_37 = F_94 ( V_167 ) ;
if ( V_79 == V_68 )
V_79 = V_37 ;
if ( F_33 () < 0 )
return - 1 ;
F_19 () ;
if ( F_31 () < 0 || F_32 () < 0 )
return - 1 ;
#ifdef F_99
V_201 = V_107 | ( V_22 & V_157 ) ;
#endif
#ifndef F_103
F_18 ( L_55 ) ;
F_18 ( L_56 ,
V_35 -> V_6 , V_35 -> V_100 , V_35 -> V_109 ,
& V_58 , & V_60 , & V_67 ) ;
F_18 ( L_57 ,
F_62 () -> V_78 , V_166 , F_62 () -> V_168 ) ;
F_18 ( L_58 ,
& V_80 , & V_79 , V_167 ) ;
if ( V_63 )
F_88 ( L_59 , V_63 ) ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
if ( V_115 [ V_113 ] != V_68 ) {
F_18 ( L_60 ,
V_113 , & V_115 [ V_113 ] ) ;
break;
}
for ( V_113 ++ ; V_113 < V_114 ; V_113 ++ )
if ( V_115 [ V_113 ] != V_68 )
F_88 ( L_61 , V_113 , & V_115 [ V_113 ] ) ;
F_88 ( L_24 ) ;
#endif
return 0 ;
}
static int T_1 F_104 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_62 ) || ! strcmp ( V_6 , L_63 ) ) {
return 1 ;
}
if ( ! strcmp ( V_6 , L_64 ) || ! strcmp ( V_6 , L_65 ) ) {
return 0 ;
}
#ifdef F_105
else if ( ! strncmp ( V_6 , L_66 , 4 ) ) {
char * V_220 ;
V_22 &= ~ V_21 ;
V_220 = strstr ( V_6 , L_67 ) ;
if ( V_220 ) {
char * V_200 ;
V_220 = V_220 + 5 ;
V_200 = strchr ( V_220 , ',' ) ;
if ( ! V_200 )
return 1 ;
* V_200 = 0 ;
if ( F_106 ( V_220 , 0 , V_125 ) )
F_12 ( L_68 ) ;
strncpy ( V_125 + 1 , V_200 + 1 , 251 ) ;
* V_200 = ',' ;
}
return 1 ;
}
#endif
#ifdef F_107
else if ( ! strcmp ( V_6 , L_69 ) ) {
V_22 &= ~ ( V_21 | V_157 ) ;
return 1 ;
}
#endif
#ifdef F_108
else if ( ! strcmp ( V_6 , L_70 ) ) {
V_22 &= ~ ( V_19 | V_157 ) ;
return 1 ;
}
#endif
#ifdef F_99
else if ( ! strcmp ( V_6 , L_71 ) ) {
V_22 &= ~ V_157 ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_109 ( char * V_221 )
{
char * V_207 , * V_222 , * V_223 ;
int V_224 = 0 ;
V_225 = 1 ;
V_215 = 1 ;
if ( F_104 ( V_221 ) )
return 1 ;
if ( * V_221 == 0 ||
strcmp ( V_221 , L_64 ) == 0 ||
strcmp ( V_221 , L_65 ) == 0 ) {
V_215 = 0 ;
return 1 ;
}
F_59 () ;
V_222 = V_221 ;
while ( V_222 && * V_222 ) {
if ( ( V_207 = strchr ( V_222 , ':' ) ) )
* V_207 ++ = '\0' ;
if ( strlen ( V_222 ) > 0 ) {
F_12 ( ( L_72 , V_224 , V_222 ) ) ;
switch ( V_224 ) {
case 0 :
if ( ( V_58 = F_95 ( V_222 ) ) == V_226 )
V_58 = V_68 ;
break;
case 1 :
if ( ( V_80 = F_95 ( V_222 ) ) == V_226 )
V_80 = V_68 ;
break;
case 2 :
if ( ( V_67 = F_95 ( V_222 ) ) == V_226 )
V_67 = V_68 ;
break;
case 3 :
if ( ( V_60 = F_95 ( V_222 ) ) == V_226 )
V_60 = V_68 ;
break;
case 4 :
if ( ( V_223 = strchr ( V_222 , '.' ) ) ) {
* V_223 ++ = '\0' ;
F_110 ( F_62 () -> V_168 , V_223 ,
sizeof( F_62 () -> V_168 ) ) ;
}
F_110 ( F_62 () -> V_78 , V_222 ,
sizeof( F_62 () -> V_78 ) ) ;
V_77 = 1 ;
break;
case 5 :
F_110 ( V_5 , V_222 , sizeof( V_5 ) ) ;
break;
case 6 :
if ( F_104 ( V_222 ) == 0 &&
V_58 == V_68 ) {
V_215 = 0 ;
}
break;
case 7 :
if ( V_114 >= 1 ) {
V_115 [ 0 ] = F_95 ( V_222 ) ;
if ( V_115 [ 0 ] == V_226 )
V_115 [ 0 ] = V_68 ;
}
break;
case 8 :
if ( V_114 >= 2 ) {
V_115 [ 1 ] = F_95 ( V_222 ) ;
if ( V_115 [ 1 ] == V_226 )
V_115 [ 1 ] = V_68 ;
}
break;
}
}
V_222 = V_207 ;
V_224 ++ ;
}
return 1 ;
}
static int T_1 F_111 ( char * V_221 )
{
return F_109 ( V_221 ) ;
}
static int T_1 F_112 ( char * V_221 )
{
if ( F_110 ( V_124 , V_221 ,
sizeof( V_124 ) )
>= sizeof( V_124 ) )
F_8 ( L_73 ,
V_124 ) ;
return 1 ;
}
