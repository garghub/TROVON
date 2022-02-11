static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 V_3 L_2 V_4 L_3 , V_2 ) ;
F_2 ( L_4 L_5 , V_2 ) ;
}
static const char * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 -> V_7 ;
return V_2 -> V_8 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_9 , int V_10 , T_1 V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_9 ;
unsigned int V_14 = 0 ;
memset ( V_9 , 0 , V_10 ) ;
V_13 -> V_15 = V_11 ;
V_13 -> V_16 = V_10 ;
while ( ( V_10 -= sizeof( struct V_12 ) ) >= 0 ) {
V_13 -> V_17 = V_18 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_19 = ( V_20 ) V_11 + V_14 ;
if ( F_5 ( V_2 ) ) {
V_13 -> V_21 = V_22 ;
V_13 -> V_23 = V_2 -> V_24 . V_23 ;
}
V_13 -> V_25 = V_2 -> V_26 ;
V_13 -> V_27 = V_2 -> V_28 ;
V_2 -> V_26 = V_13 ;
V_2 -> V_28 = V_13 ;
V_2 -> V_29 ++ ;
V_13 ++ ;
V_14 += sizeof( struct V_12 ) ;
}
}
static bool T_2 F_6 ( struct V_1 * V_2 )
{
int V_10 = V_30 * sizeof( struct V_12 ) ;
void * V_9 ;
T_1 V_11 ;
while ( V_2 -> V_29 < V_2 -> V_31 ) {
V_9 = F_7 ( V_2 -> V_32 , V_10 , & V_11 ) ;
if ( V_9 == NULL ) {
F_8 ( L_6 , V_2 ) ;
return false ;
}
F_4 ( V_2 , V_9 , V_10 , V_11 ) ;
}
return true ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_12 * V_33 = V_2 -> V_28 , * V_13 , * V_34 = NULL ;
V_2 -> V_28 = NULL ;
V_2 -> V_26 = NULL ;
while ( ( V_13 = V_33 ) != NULL ) {
V_33 = V_13 -> V_27 ;
if ( V_13 -> V_15 ) {
if ( V_34 )
F_10 ( V_2 -> V_32 , V_34 -> V_16 , V_34 , V_34 -> V_15 ) ;
V_34 = V_13 ;
}
}
if ( V_34 )
F_10 ( V_2 -> V_32 , V_34 -> V_16 , V_34 , V_34 -> V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_35 , bool V_36 )
{
int V_10 = V_30 * sizeof( struct V_12 ) ;
int V_37 = V_2 -> V_29 ;
void * V_9 ;
T_1 V_11 ;
if ( V_35 <= 0 )
return;
while ( V_2 -> V_29 - V_37 < V_35 ) {
V_9 = F_7 ( V_2 -> V_32 , V_10 , & V_11 ) ;
if ( V_9 == NULL )
break;
F_4 ( V_2 , V_9 , V_10 , V_11 ) ;
}
if ( V_2 -> V_29 > V_37 ) {
if ( V_36 )
F_12 ( L_7 , V_2 , V_2 -> V_29 - V_37 , V_2 -> V_29 ) ;
return;
}
F_12 ( L_8 , V_2 ) ;
if ( V_2 -> V_38 > V_2 -> V_29 - V_2 -> V_39 ) {
V_2 -> V_38 = V_2 -> V_29 - V_2 -> V_39 ;
V_2 -> V_40 -> V_41 = V_2 -> V_38 ;
}
}
static struct V_12 * F_13 ( struct V_1
* V_2 )
{
static unsigned long V_42 = 0 ;
struct V_12 * V_13 ;
V_13 = V_2 -> V_26 ;
if ( V_13 != NULL ) {
V_13 -> V_42 = ++ V_42 ;
V_2 -> V_26 = V_13 -> V_25 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_26 == NULL )
F_11 ( V_2 , V_2 -> V_43 , true ) ;
return V_13 ;
}
F_11 ( V_2 , V_2 -> V_43 , true ) ;
V_13 = V_2 -> V_26 ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_42 = ++ V_42 ;
V_2 -> V_26 = V_13 -> V_25 ;
V_13 -> V_25 = NULL ;
return V_13 ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
F_15 ( V_13 -> V_44 ) ;
F_16 ( V_2 -> V_32 , V_13 -> V_45 ,
V_13 -> V_46 , V_47 ) ;
V_13 -> V_44 = NULL ;
V_13 -> V_17 = V_18 ;
V_13 -> V_25 = V_2 -> V_26 ;
V_2 -> V_26 = V_13 ;
}
static int F_17 ( struct V_1 * V_2 , enum V_48 V_49 , void * V_50 , int V_51 , void * V_52 , int V_53 )
{
unsigned char * V_54 = ( unsigned char * ) V_50 ;
unsigned char * V_55 = ( unsigned char * ) V_52 ;
union V_56 V_57 ;
union V_58 V_59 ;
unsigned long V_60 = 0 ;
int V_61 = 0 , V_62 ;
long V_63 ;
if ( V_53 > 0 )
memset ( V_52 , 0 , V_53 ) ;
if ( ! V_2 -> V_64 )
F_18 ( V_60 ) ;
V_63 = 10000 ;
while ( -- V_63 >= 0 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_67 && ! V_57 . V_66 . V_68 )
break;
F_20 ( 100 ) ;
}
if ( V_63 < 0 ) {
V_69 = L_9 ;
V_62 = - 2 ;
goto V_70;
}
V_2 -> V_71 = false ;
F_21 ( V_2 , V_49 ) ;
V_63 = 10000 ;
while ( V_51 > 0 && -- V_63 >= 0 ) {
F_20 ( 100 ) ;
V_59 . V_65 = F_22 ( V_2 ) ;
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_59 . V_72 . V_73 )
break;
if ( V_2 -> V_71 )
break;
if ( V_57 . V_66 . V_74 )
break;
if ( V_57 . V_66 . V_68 )
continue;
F_21 ( V_2 , * V_54 ++ ) ;
V_51 -- ;
}
if ( V_63 < 0 ) {
V_69 = L_10 ;
V_62 = - 2 ;
goto V_70;
}
if ( V_49 == V_75 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_76 ) {
V_69 = L_11 ;
V_62 = - 1 ;
goto V_70;
}
if ( V_77 . V_78 )
F_12 ( L_12 L_13 , V_2 , V_49 , V_57 . V_65 ) ;
V_62 = 0 ;
goto V_70;
}
switch ( V_49 ) {
case V_79 :
case V_80 :
case V_81 :
V_63 = 60 * 10000 ;
break;
default:
V_63 = 10000 ;
break;
}
while ( -- V_63 >= 0 ) {
V_59 . V_65 = F_22 ( V_2 ) ;
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_59 . V_72 . V_73 )
break;
if ( V_2 -> V_71 )
break;
if ( V_57 . V_66 . V_74 ) {
if ( ++ V_61 <= V_53 )
* V_55 ++ = F_23 ( V_2 ) ;
else
F_23 ( V_2 ) ;
}
if ( V_49 == V_82 && V_57 . V_66 . V_67 )
break;
F_20 ( 100 ) ;
}
if ( V_63 < 0 ) {
V_69 = L_14 ;
V_62 = - 2 ;
goto V_70;
}
F_24 ( V_2 ) ;
if ( V_77 . V_78 ) {
int V_83 ;
F_12 ( L_15 , V_2 , V_49 , V_57 . V_65 , V_53 , V_61 ) ;
if ( V_53 > V_61 )
V_53 = V_61 ;
for ( V_83 = 0 ; V_83 < V_53 ; V_83 ++ )
F_12 ( L_16 , V_2 , ( ( unsigned char * ) V_52 ) [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
if ( V_57 . V_66 . V_76 ) {
F_20 ( 1000 ) ;
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_76 ||
V_57 . V_66 . V_84 ||
V_57 . V_66 . V_74 ||
V_57 . V_66 . V_68 || ! V_57 . V_66 . V_67 || ! V_57 . V_66 . V_85 || V_57 . V_66 . V_86 || V_57 . V_66 . V_87 ) {
F_25 ( V_2 ) ;
F_20 ( 1000 ) ;
}
V_69 = L_18 ;
V_62 = - 1 ;
goto V_70;
}
if ( V_51 > 0 ) {
V_69 = L_19 ;
V_62 = - 1 ;
goto V_70;
}
V_69 = NULL ;
V_62 = V_61 ;
V_70:
if ( ! V_2 -> V_64 )
F_26 ( V_60 ) ;
return V_62 ;
}
static void T_2 F_27 ( unsigned long V_88 )
{
struct V_89 * V_90 ;
if ( V_91 >= V_92 )
return;
V_90 = & V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 = V_97 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_32 = NULL ;
}
static void T_2 F_28 ( struct V_1
* V_98 )
{
if ( V_99 . V_100 )
return;
if ( ! V_99 . V_101 || V_99 . V_102 )
F_27 ( 0x330 ) ;
if ( ! V_99 . V_101 || V_99 . V_103 )
F_27 ( 0x334 ) ;
if ( ! V_99 . V_101 || V_99 . V_104 )
F_27 ( 0x230 ) ;
if ( ! V_99 . V_101 || V_99 . V_105 )
F_27 ( 0x234 ) ;
if ( ! V_99 . V_101 || V_99 . V_106 )
F_27 ( 0x130 ) ;
if ( ! V_99 . V_101 || V_99 . V_107 )
F_27 ( 0x134 ) ;
}
static void T_2 F_29 ( struct V_89 * V_108 , int V_109 )
{
int V_110 = V_109 - 1 , V_111 , V_112 ;
while ( V_110 > 0 ) {
V_111 = V_110 ;
V_110 = 0 ;
for ( V_112 = 0 ; V_112 < V_111 ; V_112 ++ ) {
struct V_89 * V_113 = & V_108 [ V_112 ] ;
struct V_89 * V_114 = & V_108 [ V_112 + 1 ] ;
if ( V_113 -> V_115 > V_114 -> V_115 || ( V_113 -> V_115 == V_114 -> V_115 && ( V_113 -> V_116 > V_114 -> V_116 ) ) ) {
struct V_89 V_117 ;
memcpy ( & V_117 , V_113 , sizeof( struct V_89 ) ) ;
memcpy ( V_113 , V_114 , sizeof( struct V_89 ) ) ;
memcpy ( V_114 , & V_117 , sizeof( struct V_89 ) ) ;
V_110 = V_112 ;
}
}
}
}
static int T_2 F_30 ( struct V_1
* V_98 )
{
struct V_89 * V_118 = & V_93 [ V_91 ] ;
int V_119 = V_91 + 1 ;
int V_120 = 0 , V_121 = 0 ;
bool V_122 = false ;
bool V_123 = false ;
bool V_124 [ 6 ] ;
struct V_125 * V_32 = NULL ;
int V_83 ;
if ( V_91 >= V_92 )
return 0 ;
V_91 ++ ;
for ( V_83 = 0 ; V_83 < 6 ; V_83 ++ )
V_124 [ V_83 ] = false ;
V_118 -> V_88 = 0 ;
while ( ( V_32 = F_31 ( V_126 , V_127 , V_32 ) ) != NULL ) {
struct V_1 * V_2 = V_98 ;
struct V_128 V_129 ;
enum V_130 V_131 ;
unsigned char V_115 ;
unsigned char V_116 ;
unsigned int V_132 ;
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_88 ;
unsigned long V_135 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_136 -> V_137 ;
V_116 = V_32 -> V_138 >> 3 ;
V_132 = V_32 -> V_139 ;
V_88 = V_133 = F_35 ( V_32 , 0 ) ;
V_135 = V_134 = F_35 ( V_32 , 1 ) ;
if ( F_36 ( V_32 , 0 ) & V_140 ) {
F_8 ( L_20 L_21 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_115 , V_116 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_141 ) {
F_8 ( L_23 L_21 , NULL , V_134 ) ;
F_8 ( L_24 , NULL , V_115 , V_116 , V_135 ) ;
continue;
}
if ( V_132 == 0 ) {
F_8 ( L_25 L_21 , NULL , V_132 ) ;
F_8 ( L_22 , NULL , V_115 , V_116 , V_88 ) ;
continue;
}
if ( V_77 . V_142 ) {
F_12 ( L_26 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_115 , V_116 , V_88 , V_135 ) ;
}
V_2 -> V_88 = V_88 ;
F_24 ( V_2 ) ;
if ( F_17 ( V_2 , V_143 , NULL , 0 , & V_129 , sizeof( V_129 ) )
== sizeof( V_129 ) ) {
if ( V_129 . V_144 < 6 )
V_124 [ V_129 . V_144 ] = true ;
} else
V_129 . V_144 = V_145 ;
V_131 = V_145 ;
F_17 ( V_2 , V_75 , & V_131 , sizeof( V_131 ) , NULL , 0 ) ;
if ( ! V_123 ) {
struct V_146 V_147 ;
struct V_148 V_149 ;
struct V_150 V_151 ;
V_147 . V_152 = V_153 + 45 ;
V_147 . V_154 = sizeof( V_149 ) ;
F_17 ( V_2 , V_82 , & V_147 , sizeof( V_147 ) , & V_149 , sizeof( V_149 ) ) ;
F_17 ( V_2 , V_155 , NULL , 0 , & V_151 , sizeof( V_151 ) ) ;
if ( V_151 . V_156 == '5' )
V_122 = V_149 . V_122 ;
V_123 = true ;
}
if ( V_129 . V_144 == V_157 ) {
V_118 -> V_94 = V_95 ;
V_118 -> V_96 = V_158 ;
V_118 -> V_88 = V_88 ;
V_118 -> V_135 = V_135 ;
V_118 -> V_115 = V_115 ;
V_118 -> V_116 = V_116 ;
V_118 -> V_132 = V_132 ;
V_118 -> V_32 = F_37 ( V_32 ) ;
V_121 ++ ;
} else if ( V_91 < V_92 ) {
struct V_89 * V_90 = & V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 = V_158 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_135 = V_135 ;
V_90 -> V_115 = V_115 ;
V_90 -> V_116 = V_116 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
V_120 ++ ;
V_121 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
}
if ( V_122 )
F_29 ( & V_93 [ V_119 ] , V_120 ) ;
if ( ! V_99 . V_100 )
if ( V_118 -> V_88 == 0 &&
( ! V_99 . V_101 ||
V_99 . V_102 ) ) {
V_118 -> V_94 = V_95 ;
V_118 -> V_96 = V_97 ;
V_118 -> V_88 = 0x330 ;
}
if ( ! V_99 . V_100 ) {
if ( ! V_124 [ 1 ] &&
( ! V_99 . V_101 ||
V_99 . V_103 ) )
F_27 ( 0x334 ) ;
if ( ! V_124 [ 2 ] &&
( ! V_99 . V_101 ||
V_99 . V_104 ) )
F_27 ( 0x230 ) ;
if ( ! V_124 [ 3 ] &&
( ! V_99 . V_101 ||
V_99 . V_105 ) )
F_27 ( 0x234 ) ;
if ( ! V_124 [ 4 ] &&
( ! V_99 . V_101 ||
V_99 . V_106 ) )
F_27 ( 0x130 ) ;
if ( ! V_124 [ 5 ] &&
( ! V_99 . V_101 ||
V_99 . V_107 ) )
F_27 ( 0x134 ) ;
}
V_32 = NULL ;
while ( ( V_32 = F_31 ( V_126 , V_159 , V_32 ) ) != NULL ) {
unsigned char V_115 ;
unsigned char V_116 ;
unsigned int V_132 ;
unsigned long V_88 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_136 -> V_137 ;
V_116 = V_32 -> V_138 >> 3 ;
V_132 = V_32 -> V_139 ;
V_88 = F_35 ( V_32 , 0 ) ;
if ( V_88 == 0 || V_132 == 0 )
continue;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
struct V_89 * V_90 = & V_93 [ V_83 ] ;
if ( V_90 -> V_88 == V_88 && V_90 -> V_94 == V_95 ) {
V_90 -> V_96 = V_158 ;
V_90 -> V_135 = 0 ;
V_90 -> V_115 = V_115 ;
V_90 -> V_116 = V_116 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
break;
}
}
}
return V_121 ;
}
static int T_2 F_39 ( struct V_1
* V_98 )
{
int V_160 = V_91 , V_161 = 0 ;
struct V_125 * V_32 = NULL ;
while ( ( V_32 = F_31 ( V_126 , V_162 , V_32 ) ) != NULL ) {
unsigned char V_115 ;
unsigned char V_116 ;
unsigned int V_132 ;
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_88 ;
unsigned long V_135 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_136 -> V_137 ;
V_116 = V_32 -> V_138 >> 3 ;
V_132 = V_32 -> V_139 ;
V_88 = V_133 = F_35 ( V_32 , 0 ) ;
V_135 = V_134 = F_35 ( V_32 , 1 ) ;
#ifdef F_40
if ( F_36 ( V_32 , 0 ) & V_140 ) {
F_8 ( L_20 L_32 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_115 , V_116 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_141 ) {
F_8 ( L_23 L_32 , NULL , V_134 ) ;
F_8 ( L_24 , NULL , V_115 , V_116 , V_135 ) ;
continue;
}
if ( V_132 == 0 ) {
F_8 ( L_25 L_32 , NULL , V_132 ) ;
F_8 ( L_22 , NULL , V_115 , V_116 , V_88 ) ;
continue;
}
if ( V_77 . V_142 ) {
F_12 ( L_33 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_115 , V_116 , V_88 , V_135 ) ;
}
if ( V_91 < V_92 ) {
struct V_89 * V_90 = & V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_163 ;
V_90 -> V_96 = V_158 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_135 = V_135 ;
V_90 -> V_115 = V_115 ;
V_90 -> V_116 = V_116 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
V_161 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
#else
F_8 ( L_34 L_35 , NULL , V_115 , V_116 ) ;
F_8 ( L_36 L_37 , NULL , V_88 , V_135 , V_132 ) ;
F_8 ( L_38 L_39 , NULL ) ;
#endif
}
F_29 ( & V_93 [ V_160 ] , V_161 ) ;
return V_161 ;
}
static void T_2 F_41 ( struct V_1
* V_98 )
{
if ( ! V_99 . V_164 ) {
if ( V_99 . V_165 ) {
F_30 ( V_98 ) ;
F_39 ( V_98 ) ;
} else if ( V_99 . V_166 ) {
F_39 ( V_98 ) ;
F_30 ( V_98 ) ;
} else {
int V_161 = F_39 ( V_98 ) ;
int V_121 = F_30 ( V_98 ) ;
if ( V_161 > 0 && V_121 > 0 ) {
struct V_89 * V_90 = & V_93 [ V_161 ] ;
struct V_1 * V_2 = V_98 ;
struct V_146 V_147 ;
struct V_167 V_168 ;
while ( V_90 -> V_96 != V_158 )
V_90 ++ ;
V_2 -> V_88 = V_90 -> V_88 ;
V_147 . V_152 = V_169 + V_170 + 0 ;
V_147 . V_154 = sizeof( V_168 ) ;
F_17 ( V_2 , V_82 , & V_147 , sizeof( V_147 ) , & V_168 , sizeof( V_168 ) ) ;
if ( V_168 . V_171 != V_172 ) {
struct V_89 V_173 [ V_92 ] ;
int V_174 = V_91 - V_161 ;
memcpy ( V_173 , V_93 , V_91 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ 0 ] , & V_173 [ V_161 ] , V_174 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ V_174 ] , & V_173 [ 0 ] , V_161 * sizeof( struct V_89 ) ) ;
}
}
}
} else
F_28 ( V_98 ) ;
}
static bool F_42 ( struct V_1 * V_2 , char * V_175 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_96 == V_158 ) {
F_8 ( L_40 , V_2 ) ;
F_8 ( L_41 , V_2 , V_2 -> V_115 , V_2 -> V_116 , V_2 -> V_88 , V_2 -> V_135 ) ;
} else
F_8 ( L_42 L_43 , V_2 , V_2 -> V_88 ) ;
F_8 ( L_44 , V_2 , V_175 ) ;
if ( V_69 != NULL )
F_8 ( L_45 , V_2 , V_69 ) ;
return false ;
}
static bool T_2 F_43 ( struct V_1 * V_2 )
{
union V_56 V_57 ;
union V_58 V_59 ;
union V_176 V_177 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_24 -> V_23 = ( V_20 ) V_2 -> V_88 ;
V_24 -> V_132 = V_2 -> V_132 ;
V_24 -> V_179 = false ;
if ( ! ( F_44 ( V_24 ) == 0 && V_24 -> V_179 ) ) {
F_8 ( L_34 L_35 , V_2 , V_2 -> V_115 , V_2 -> V_116 ) ;
F_8 ( L_46 L_37 , V_2 , V_2 -> V_88 , V_2 -> V_135 ) ;
F_8 ( L_47 , V_2 ) ;
return false ;
}
if ( V_77 . V_142 )
F_12 ( L_48 , V_2 , V_2 -> V_88 ) ;
return true ;
}
V_57 . V_65 = F_19 ( V_2 ) ;
V_59 . V_65 = F_22 ( V_2 ) ;
V_177 . V_65 = F_45 ( V_2 ) ;
if ( V_77 . V_142 )
F_12 ( L_49 L_50 , V_2 , V_2 -> V_88 , V_57 . V_65 , V_59 . V_65 , V_177 . V_65 ) ;
if ( V_57 . V_65 == 0 || V_57 . V_66 . V_86 || V_57 . V_66 . V_68 || V_57 . V_66 . V_84 || V_57 . V_66 . V_76 || V_59 . V_72 . V_84 != 0 )
return false ;
if ( V_177 . V_65 == 0xFF )
return false ;
return true ;
}
static bool F_46 ( struct V_1
* V_2 , bool V_180 )
{
union V_56 V_57 ;
int V_63 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_24 -> V_181 = ! V_180 ;
V_24 -> V_182 = true ;
V_2 -> V_183 = F_47 ( V_24 ) ;
if ( V_2 -> V_183 == V_184 )
return false ;
return true ;
}
if ( V_180 )
F_48 ( V_2 ) ;
else
F_25 ( V_2 ) ;
V_63 = 5 * 10000 ;
while ( -- V_63 >= 0 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_86 )
break;
F_20 ( 100 ) ;
}
if ( V_77 . V_185 )
F_12 ( L_51 L_52 , V_2 , V_2 -> V_88 , V_57 . V_65 ) ;
if ( V_63 < 0 )
return false ;
F_20 ( 100 ) ;
V_63 = 10 * 10000 ;
while ( -- V_63 >= 0 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( ! V_57 . V_66 . V_86 )
break;
F_20 ( 100 ) ;
}
if ( V_77 . V_185 )
F_12 ( L_53 L_52 , V_2 , V_2 -> V_88 , V_57 . V_65 ) ;
if ( V_63 < 0 )
return false ;
V_63 = 10000 ;
while ( -- V_63 >= 0 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_87 || V_57 . V_66 . V_67 || V_57 . V_66 . V_74 )
break;
F_20 ( 100 ) ;
}
if ( V_77 . V_185 )
F_12 ( L_54 L_52 , V_2 , V_2 -> V_88 , V_57 . V_65 ) ;
if ( V_63 < 0 )
return false ;
if ( V_57 . V_66 . V_87 || ! V_57 . V_66 . V_67 ) {
V_69 = NULL ;
F_42 ( V_2 , L_55 ) ;
F_8 ( L_56 , V_2 , V_57 . V_65 ) ;
if ( V_57 . V_66 . V_74 ) {
unsigned char V_186 = F_23 ( V_2 ) ;
F_8 ( L_57 , V_2 , V_186 ) ;
}
return false ;
}
return true ;
}
static bool T_2 F_49 ( struct V_1 * V_2 )
{
struct V_187 V_188 ;
unsigned char V_189 ;
bool V_62 = true ;
if ( F_5 ( V_2 ) )
return true ;
V_189 = sizeof( V_188 ) ;
if ( F_17 ( V_2 , V_190 , & V_189 , sizeof( V_189 ) , & V_188 , sizeof( V_188 ) )
!= sizeof( V_188 ) )
V_62 = false ;
if ( V_77 . V_142 )
F_12 ( L_58 , V_2 , V_2 -> V_88 , ( V_62 ? L_59 : L_60 ) ) ;
return V_62 ;
}
static bool T_2 F_50 ( struct V_1
* V_2 )
{
struct V_150 V_151 ;
struct V_191 V_192 ;
struct V_193 V_194 ;
struct V_187 V_188 ;
unsigned char V_195 [ 5 ] ;
unsigned char V_196 ;
unsigned char V_197 ;
struct V_128 V_129 ;
struct V_146 V_147 ;
struct V_198 V_199 ;
union V_176 V_177 ;
unsigned char V_189 ;
unsigned char * V_200 , V_201 ;
int V_202 , V_83 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_200 = V_2 -> V_203 ;
* V_200 ++ = 'B' ;
* V_200 ++ = 'T' ;
* V_200 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_24 -> V_204 ) ; V_83 ++ )
* V_200 ++ = V_24 -> V_204 [ V_83 ] ;
* V_200 ++ = '\0' ;
strcpy ( V_2 -> V_205 , V_206 ) ;
V_2 -> V_207 = V_24 -> V_207 ;
V_2 -> V_208 = V_24 -> V_208 ;
V_2 -> V_209 = V_24 -> V_209 ;
V_2 -> V_210 = ! V_24 -> V_181 ;
V_2 -> V_211 = true ;
V_2 -> V_212 = V_24 -> V_212 ;
V_2 -> V_213 = false ;
V_2 -> V_214 = true ;
V_2 -> V_215 = true ;
V_2 -> V_216 = true ;
V_2 -> V_217 = true ;
V_2 -> V_218 = V_24 -> V_218 ;
V_2 -> V_219 = V_24 -> V_219 ;
V_2 -> V_220 = V_24 -> V_220 ;
V_2 -> V_221 = V_24 -> V_221 ;
V_2 -> V_222 = V_223 ;
V_2 -> V_224 = ( V_2 -> V_212 ? 16 : 8 ) ;
V_2 -> V_225 = 32 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_38 = 255 ;
V_2 -> V_226 = V_2 -> V_38 ;
V_2 -> V_227 = V_24 -> V_227 ;
V_2 -> V_228 = V_24 -> V_228 ;
V_2 -> V_229 = V_24 -> V_229 ;
V_2 -> V_230 = V_24 -> V_230 ;
V_2 -> V_231 = V_24 -> V_231 ;
V_2 -> V_232 = 0xFFFF ;
goto V_233;
}
if ( F_17 ( V_2 , V_155 , NULL , 0 , & V_151 , sizeof( V_151 ) ) != sizeof( V_151 ) )
return F_42 ( V_2 , L_61 ) ;
if ( F_17 ( V_2 , V_234 , NULL , 0 , & V_192 , sizeof( V_192 ) )
!= sizeof( V_192 ) )
return F_42 ( V_2 , L_62 ) ;
V_189 = sizeof( V_194 ) ;
if ( F_17 ( V_2 , V_235 , & V_189 , sizeof( V_189 ) , & V_194 , sizeof( V_194 ) )
!= sizeof( V_194 ) )
return F_42 ( V_2 , L_63 ) ;
V_189 = sizeof( V_188 ) ;
if ( F_17 ( V_2 , V_190 , & V_189 , sizeof( V_189 ) , & V_188 , sizeof( V_188 ) )
!= sizeof( V_188 ) )
return F_42 ( V_2 , L_64 ) ;
V_196 = '\0' ;
if ( V_151 . V_156 > '0' )
if ( F_17 ( V_2 , V_236 , NULL , 0 , & V_196 , sizeof( V_196 ) )
!= sizeof( V_196 ) )
return F_42 ( V_2 , L_65 ) ;
if ( V_188 . V_237 == 'A' && V_151 . V_156 == '2' )
strcpy ( V_195 , L_66 ) ;
else if ( V_188 . V_237 == 'E' && V_151 . V_156 == '2' && ( V_151 . V_238 <= '1' || ( V_151 . V_238 == '2' && V_196 == '0' ) ) )
strcpy ( V_195 , L_67 ) ;
else if ( V_188 . V_237 == 'E' && V_151 . V_156 == '0' )
strcpy ( V_195 , L_68 ) ;
else {
V_189 = sizeof( V_195 ) ;
if ( F_17 ( V_2 , V_239 , & V_189 , sizeof( V_189 ) , & V_195 , sizeof( V_195 ) )
!= sizeof( V_195 ) )
return F_42 ( V_2 , L_69 ) ;
}
V_200 = V_2 -> V_203 ;
* V_200 ++ = 'B' ;
* V_200 ++ = 'T' ;
* V_200 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_195 ) ; V_83 ++ ) {
V_201 = V_195 [ V_83 ] ;
if ( V_201 == ' ' || V_201 == '\0' )
break;
* V_200 ++ = V_201 ;
}
* V_200 ++ = '\0' ;
V_200 = V_2 -> V_205 ;
* V_200 ++ = V_151 . V_156 ;
* V_200 ++ = '.' ;
* V_200 ++ = V_151 . V_238 ;
if ( V_196 != ' ' && V_196 != '\0' )
* V_200 ++ = V_196 ;
* V_200 = '\0' ;
if ( strcmp ( V_2 -> V_205 , L_70 ) >= 0 ) {
if ( F_17 ( V_2 , V_240 , NULL , 0 , & V_197 , sizeof( V_197 ) )
!= sizeof( V_197 ) )
return F_42 ( V_2 , L_71 ) ;
if ( V_197 != ' ' && V_197 != '\0' )
* V_200 ++ = V_197 ;
* V_200 = '\0' ;
}
V_2 -> V_207 = V_192 . V_241 ;
V_2 -> V_96 = V_242 [ V_2 -> V_203 [ 3 ] - '4' ] ;
if ( V_2 -> V_132 == 0 ) {
if ( V_192 . V_243 )
V_2 -> V_132 = 9 ;
else if ( V_192 . V_244 )
V_2 -> V_132 = 10 ;
else if ( V_192 . V_245 )
V_2 -> V_132 = 11 ;
else if ( V_192 . V_246 )
V_2 -> V_132 = 12 ;
else if ( V_192 . V_247 )
V_2 -> V_132 = 14 ;
else if ( V_192 . V_248 )
V_2 -> V_132 = 15 ;
}
if ( V_2 -> V_96 == V_97 ) {
if ( V_192 . V_249 )
V_2 -> V_250 = 5 ;
else if ( V_192 . V_251 )
V_2 -> V_250 = 6 ;
else if ( V_192 . V_252 )
V_2 -> V_250 = 7 ;
}
V_177 . V_65 = F_45 ( V_2 ) ;
V_2 -> V_208 = V_177 . V_253 . V_208 ;
V_2 -> V_254 = V_188 . V_255 ;
V_2 -> V_222 = V_2 -> V_254 ;
if ( V_2 -> V_254 > V_223 )
V_2 -> V_222 = V_223 ;
if ( V_188 . V_256 . V_211 )
V_2 -> V_211 = true ;
V_2 -> V_212 = V_188 . V_212 ;
V_2 -> V_213 = V_188 . V_213 ;
V_2 -> V_214 = V_188 . V_214 ;
V_2 -> V_215 = V_188 . V_215 ;
if ( V_2 -> V_205 [ 0 ] == '5' || ( V_2 -> V_205 [ 0 ] == '4' && V_2 -> V_212 ) )
V_2 -> V_216 = true ;
if ( V_2 -> V_205 [ 0 ] == '5' ) {
if ( F_17 ( V_2 , V_143 , NULL , 0 , & V_129 , sizeof( V_129 ) )
!= sizeof( V_129 ) )
return F_42 ( V_2 , L_72 ) ;
if ( V_129 . V_257 ) {
V_2 -> V_217 = true ;
V_2 -> V_218 = V_129 . V_218 ;
V_2 -> V_219 = V_129 . V_219 ;
}
}
if ( V_2 -> V_205 [ 0 ] >= '4' ) {
V_147 . V_152 = V_153 ;
V_147 . V_154 = sizeof( V_199 ) ;
if ( F_17 ( V_2 , V_82 , & V_147 , sizeof( V_147 ) , & V_199 , sizeof( V_199 ) )
!= sizeof( V_199 ) )
return F_42 ( V_2 , L_73 ) ;
V_2 -> V_209 = V_199 . V_209 ;
V_2 -> V_210 = V_199 . V_210 ;
if ( V_2 -> V_205 [ 0 ] == '4' ) {
V_2 -> V_217 = true ;
V_2 -> V_218 = V_199 . V_218 ;
V_2 -> V_219 = V_199 . V_219 ;
}
V_2 -> V_230 = V_199 . V_230 ;
V_2 -> V_228 = V_199 . V_228 ;
V_2 -> V_227 = V_199 . V_227 ;
V_2 -> V_231 = V_199 . V_231 ;
if ( V_2 -> V_215 )
V_2 -> V_229 = V_199 . V_229 ;
if ( V_2 -> V_214 ) {
V_2 -> V_220 = V_199 . V_220 ;
V_2 -> V_221 = V_199 . V_221 ;
}
}
if ( V_2 -> V_205 [ 0 ] < '4' ) {
if ( V_194 . V_258 ) {
V_2 -> V_227 = 0xFF ;
if ( V_2 -> V_96 == V_259 ) {
if ( V_188 . V_256 . V_260 )
V_2 -> V_228 = 0xFF ;
if ( strcmp ( V_2 -> V_203 , L_74 ) == 0 )
V_2 -> V_230 = 0xFF ;
}
}
V_2 -> V_231 = 0xFF ;
V_2 -> V_209 = V_194 . V_209 ;
V_2 -> V_210 = true ;
}
V_2 -> V_224 = ( V_2 -> V_212 ? 16 : 8 ) ;
V_2 -> V_225 = ( V_2 -> V_216 ? 32 : 8 ) ;
if ( V_2 -> V_205 [ 0 ] == '5' )
V_2 -> V_226 = 192 ;
else if ( V_2 -> V_205 [ 0 ] == '4' )
V_2 -> V_226 = ( V_2 -> V_96 != V_97 ? 100 : 50 ) ;
else
V_2 -> V_226 = 30 ;
if ( strcmp ( V_2 -> V_205 , L_75 ) >= 0 ) {
V_2 -> V_261 = true ;
V_2 -> V_262 = V_263 ;
} else {
V_2 -> V_261 = false ;
V_2 -> V_262 = 32 ;
}
V_2 -> V_38 = V_2 -> V_262 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_232 = 0 ;
switch ( V_2 -> V_205 [ 0 ] ) {
case '5' :
V_2 -> V_232 = 0xFFFF ;
break;
case '4' :
if ( strcmp ( V_2 -> V_205 , L_76 ) >= 0 )
V_2 -> V_232 = 0xFFFF ;
break;
case '3' :
if ( strcmp ( V_2 -> V_205 , L_77 ) >= 0 )
V_2 -> V_232 = 0xFFFF ;
break;
}
V_2 -> V_264 = V_188 . V_264 << 12 ;
if ( V_2 -> V_96 == V_97 && ( void * ) V_265 > ( void * ) V_266 )
V_2 -> V_267 = true ;
if ( V_2 -> V_264 > 0 && strcmp ( V_2 -> V_203 , L_78 ) == 0 && strcmp ( V_2 -> V_205 , L_79 ) < 0 && ( void * ) V_265 > ( void * ) V_266 )
V_2 -> V_267 = true ;
V_233:
strcpy ( V_2 -> V_8 , L_80 ) ;
strcat ( V_2 -> V_8 , V_2 -> V_203 ) ;
for ( V_202 = 0 ; V_202 < V_268 ; V_202 ++ ) {
unsigned char V_269 = 0 ;
if ( V_2 -> V_270 != NULL && V_2 -> V_270 -> V_269 [ V_202 ] > 0 )
V_269 = V_2 -> V_270 -> V_269 [ V_202 ] ;
else if ( V_2 -> V_267 )
V_269 = V_271 ;
V_2 -> V_269 [ V_202 ] = V_269 ;
}
if ( V_2 -> V_267 )
V_2 -> V_272 = V_273 ;
else
V_2 -> V_272 = V_274 ;
if ( V_2 -> V_270 != NULL )
V_2 -> V_275 = V_2 -> V_270 -> V_275 ;
if ( V_2 -> V_275 > 0 && V_2 -> V_275 < V_2 -> V_272 )
V_2 -> V_272 = V_2 -> V_275 ;
V_2 -> V_232 &= V_2 -> V_231 ;
if ( V_2 -> V_270 != NULL )
V_2 -> V_232 =
( V_2 -> V_270 -> V_232 & V_2 -> V_270 -> V_276 ) | ( V_2 -> V_232 & ~ V_2 -> V_270 -> V_276 ) ;
if ( V_2 -> V_270 != NULL && V_2 -> V_270 -> V_277 > 0 )
V_2 -> V_277 = V_2 -> V_270 -> V_277 ;
else
V_2 -> V_277 = V_278 ;
return true ;
}
static bool T_2 F_51 ( struct V_1
* V_2 )
{
unsigned short V_279 = ( 1 << V_2 -> V_224 ) - 1 ;
unsigned short V_227 , V_228 ;
unsigned short V_229 , V_230 ;
unsigned short V_231 , V_232 ;
bool V_280 , V_281 ;
char V_282 [ V_268 + 1 ] ;
char V_283 [ V_268 + 1 ] ;
char V_284 [ V_268 + 1 ] ;
char V_285 [ V_268 + 1 ] ;
char * V_286 = V_282 ;
char * V_287 = V_283 ;
char * V_288 = V_284 ;
char * V_289 = V_285 ;
int V_202 ;
F_52 ( L_81 ,
V_2 , V_2 -> V_203 ,
V_290 [ V_2 -> V_96 ] , ( V_2 -> V_212 ? L_82 : L_83 ) , ( V_2 -> V_213 ? L_84 : L_83 ) , ( V_2 -> V_215 ? L_85 : L_83 ) ) ;
F_52 ( L_86 L_87 , V_2 , V_2 -> V_205 , V_2 -> V_88 , V_2 -> V_132 , ( V_2 -> V_211 ? L_88 : L_89 ) ) ;
if ( V_2 -> V_96 != V_158 ) {
F_52 ( L_90 , V_2 ) ;
if ( V_2 -> V_250 > 0 )
F_52 ( L_91 , V_2 , V_2 -> V_250 ) ;
else
F_52 ( L_92 , V_2 ) ;
if ( V_2 -> V_264 > 0 )
F_52 ( L_93 , V_2 , V_2 -> V_264 ) ;
else
F_52 ( L_94 , V_2 ) ;
} else {
F_52 ( L_95 , V_2 , V_2 -> V_115 , V_2 -> V_116 ) ;
if ( V_2 -> V_135 > 0 )
F_52 ( L_96 , V_2 , V_2 -> V_135 ) ;
else
F_52 ( L_97 , V_2 ) ;
}
F_52 ( L_98 , V_2 , V_2 -> V_207 ) ;
F_52 ( L_99 , V_2 , ( V_2 -> V_209 ? L_100 : L_101 ) , ( V_2 -> V_208 ? L_100 : L_101 ) ) ;
V_279 &= ~ ( 1 << V_2 -> V_207 ) ;
V_227 = V_2 -> V_227 & V_279 ;
V_228 = V_2 -> V_228 & V_279 ;
V_229 = V_2 -> V_229 & V_279 ;
if ( ( F_53 ( V_2 ) && ( V_2 -> V_205 [ 0 ] >= '4' || V_2 -> V_96 == V_259 ) ) || F_5 ( V_2 ) ) {
V_280 = false ;
if ( V_227 == 0 ) {
V_286 = L_101 ;
V_280 = true ;
} else if ( V_227 == V_279 ) {
if ( V_228 == 0 ) {
V_286 = L_102 ;
V_280 = true ;
} else if ( V_228 == V_279 ) {
if ( V_229 == 0 ) {
V_286 = L_103 ;
V_280 = true ;
} else if ( V_229 == V_279 ) {
V_286 = L_104 ;
V_280 = true ;
}
}
}
if ( ! V_280 ) {
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_282 [ V_202 ] = ( ( ! ( V_227 & ( 1 << V_202 ) ) ) ? 'N' : ( ! ( V_228 & ( 1 << V_202 ) ) ? 'S' : ( ! ( V_229 & ( 1 << V_202 ) ) ? 'F' : 'U' ) ) ) ;
V_282 [ V_2 -> V_207 ] = '#' ;
V_282 [ V_2 -> V_224 ] = '\0' ;
}
} else
V_286 = ( V_227 == 0 ? L_101 : L_100 ) ;
V_230 = V_2 -> V_230 & V_279 ;
if ( V_230 == 0 )
V_287 = L_101 ;
else if ( V_230 == V_279 )
V_287 = L_100 ;
else {
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_283 [ V_202 ] = ( ( V_230 & ( 1 << V_202 ) ) ? 'Y' : 'N' ) ;
V_283 [ V_2 -> V_207 ] = '#' ;
V_283 [ V_2 -> V_224 ] = '\0' ;
}
V_231 = V_2 -> V_231 & V_279 ;
if ( V_231 == 0 )
V_288 = L_101 ;
else if ( V_231 == V_279 )
V_288 = L_100 ;
else {
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_284 [ V_202 ] = ( ( V_231 & ( 1 << V_202 ) ) ? 'Y' : 'N' ) ;
V_284 [ V_2 -> V_207 ] = '#' ;
V_284 [ V_2 -> V_224 ] = '\0' ;
}
V_232 = V_2 -> V_232 & V_279 ;
if ( V_232 == 0 )
V_289 = L_101 ;
else if ( V_232 == V_279 )
V_289 = L_100 ;
else {
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_285 [ V_202 ] = ( ( V_232 & ( 1 << V_202 ) ) ? 'Y' : 'N' ) ;
V_285 [ V_2 -> V_207 ] = '#' ;
V_285 [ V_2 -> V_224 ] = '\0' ;
}
F_52 ( L_105 , V_2 , V_286 , V_287 ) ;
F_52 ( L_106 , V_2 , V_288 , V_289 ) ;
if ( F_53 ( V_2 ) ) {
F_52 ( L_107 L_108 , V_2 , V_2 -> V_222 , V_2 -> V_254 , V_2 -> V_262 ) ;
F_52 ( L_109 L_110 , V_2 , V_2 -> V_38 , V_2 -> V_226 ) ;
} else
F_52 ( L_109 L_111 , V_2 , V_2 -> V_38 , V_2 -> V_222 ) ;
F_52 ( L_112 , V_2 ) ;
V_281 = true ;
for ( V_202 = 1 ; V_202 < V_2 -> V_224 ; V_202 ++ )
if ( V_2 -> V_269 [ V_202 ] != V_2 -> V_269 [ 0 ] ) {
V_281 = false ;
break;
}
if ( V_281 ) {
if ( V_2 -> V_269 [ 0 ] > 0 )
F_52 ( L_113 , V_2 , V_2 -> V_269 [ 0 ] ) ;
else
F_52 ( L_114 , V_2 ) ;
} else
F_52 ( L_115 , V_2 ) ;
F_52 ( L_116 , V_2 , V_2 -> V_272 ) ;
if ( V_2 -> V_217 ) {
if ( V_2 -> V_212 )
F_52 ( L_117 , V_2 , ( V_2 -> V_218 ? ( V_2 -> V_219 ? L_118 : L_119 )
: ( V_2 -> V_219 ? L_120 : L_121 ) ) ) ;
else
F_52 ( L_117 , V_2 , ( V_2 -> V_218 ? L_100 : L_101 ) ) ;
if ( V_2 -> V_214 )
F_52 ( L_122 , V_2 , ( V_2 -> V_220 ? ( V_2 -> V_221 ? L_123 : L_124 )
: L_101 ) ) ;
F_52 ( L_17 , V_2 ) ;
}
return true ;
}
static bool T_2 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_132 == 0 ) {
F_8 ( L_125 , V_2 ) ;
return false ;
}
if ( F_55 ( V_2 -> V_132 , V_291 , V_292 , V_2 -> V_8 , V_2 ) < 0 ) {
F_8 ( L_126 , V_2 , V_2 -> V_132 ) ;
return false ;
}
V_2 -> V_64 = true ;
if ( V_2 -> V_250 > 0 ) {
if ( F_56 ( V_2 -> V_250 , V_2 -> V_8 ) < 0 ) {
F_8 ( L_127 , V_2 , V_2 -> V_250 ) ;
return false ;
}
F_57 ( V_2 -> V_250 , V_293 ) ;
F_58 ( V_2 -> V_250 ) ;
V_2 -> V_294 = true ;
}
return true ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_60 ( V_2 -> V_132 , V_2 ) ;
if ( V_2 -> V_294 )
F_61 ( V_2 -> V_250 ) ;
if ( V_2 -> V_295 )
F_10 ( V_2 -> V_32 , V_2 -> V_296 , V_2 -> V_295 , V_2 -> V_297 ) ;
F_62 ( V_2 -> V_32 ) ;
V_2 -> V_295 = NULL ;
V_2 -> V_297 = 0 ;
V_2 -> V_296 = 0 ;
}
static bool F_63 ( struct V_1
* V_2 )
{
struct V_298 V_299 ;
enum V_300 V_301 ;
enum V_302 V_303 ;
int V_202 ;
V_2 -> V_304 = NULL ;
V_2 -> V_305 = NULL ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
V_2 -> V_306 [ V_202 ] = NULL ;
V_2 -> V_307 [ V_202 ] . V_308 = false ;
V_2 -> V_307 [ V_202 ] . V_309 = false ;
V_2 -> V_310 [ V_202 ] = 0 ;
V_2 -> V_311 [ V_202 ] = 0 ;
}
if ( F_5 ( V_2 ) )
goto V_70;
V_2 -> V_296 = V_2 -> V_262 * ( sizeof( struct V_312 ) + sizeof( struct V_313 ) ) ;
V_2 -> V_295 = F_7 ( V_2 -> V_32 , V_2 -> V_296 , & V_2 -> V_297 ) ;
if ( V_2 -> V_295 == NULL )
return F_42 ( V_2 , L_128 ) ;
V_2 -> V_314 = (struct V_312 * ) V_2 -> V_295 ;
V_2 -> V_315 = V_2 -> V_314 + V_2 -> V_262 - 1 ;
V_2 -> V_316 = V_2 -> V_314 ;
V_2 -> V_317 = (struct V_313 * ) ( V_2 -> V_315 + 1 ) ;
V_2 -> V_318 = V_2 -> V_317 + V_2 -> V_262 - 1 ;
V_2 -> V_319 = V_2 -> V_317 ;
memset ( V_2 -> V_314 , 0 , V_2 -> V_262 * sizeof( struct V_312 ) ) ;
memset ( V_2 -> V_317 , 0 , V_2 -> V_262 * sizeof( struct V_313 ) ) ;
V_299 . V_262 = V_2 -> V_262 ;
V_299 . V_320 = ( V_20 ) V_2 -> V_297 ;
if ( F_17 ( V_2 , V_321 , & V_299 , sizeof( V_299 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_129 ) ;
if ( V_2 -> V_261 ) {
V_301 = V_322 ;
if ( F_17 ( V_2 , V_323 , & V_301 , sizeof( V_301 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_130 ) ;
}
if ( V_2 -> V_216 ) {
V_303 = V_324 ;
if ( F_17 ( V_2 , V_325 , & V_303 , sizeof( V_303 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_131 ) ;
}
V_70:
if ( ! V_2 -> V_326 ) {
F_52 ( L_132 , V_2 , V_2 -> V_8 ) ;
F_52 ( L_17 , V_2 ) ;
} else
F_38 ( L_132 , V_2 , V_2 -> V_8 ) ;
V_2 -> V_326 = true ;
return true ;
}
static bool T_2 F_64 ( struct V_1
* V_2 )
{
T_3 V_327 ;
T_4 V_328 [ 8 ] ;
struct V_193 V_194 ;
T_4 V_329 [ V_268 ] ;
unsigned char V_189 ;
int V_202 ;
F_65 ( V_2 -> V_277 ) ;
if ( F_5 ( V_2 ) )
return true ;
if ( V_2 -> V_270 != NULL && V_2 -> V_270 -> V_330 . V_331 )
return true ;
if ( strcmp ( V_2 -> V_205 , L_133 ) >= 0 ) {
if ( F_17 ( V_2 , V_81 , NULL , 0 , & V_327 , sizeof( V_327 ) )
!= sizeof( V_327 ) )
return F_42 ( V_2 , L_134 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_2 -> V_307 [ V_202 ] . V_332 = ( V_327 & ( 1 << V_202 ) ? true : false ) ;
} else {
if ( F_17 ( V_2 , V_79 , NULL , 0 , & V_328 , sizeof( V_328 ) )
!= sizeof( V_328 ) )
return F_42 ( V_2 , L_135 ) ;
for ( V_202 = 0 ; V_202 < 8 ; V_202 ++ )
V_2 -> V_307 [ V_202 ] . V_332 = ( V_328 [ V_202 ] != 0 ? true : false ) ;
}
V_189 = sizeof( V_194 ) ;
if ( F_17 ( V_2 , V_235 , & V_189 , sizeof( V_189 ) , & V_194 , sizeof( V_194 ) )
!= sizeof( V_194 ) )
return F_42 ( V_2 , L_63 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_2 -> V_333 [ V_202 ] = ( V_202 < 8 ? V_194 . V_334 [ V_202 ] . V_335 : V_194 . V_336 [ V_202 - 8 ] . V_335 ) ;
if ( strcmp ( V_2 -> V_205 , L_136 ) >= 0 )
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_2 -> V_307 [ V_202 ] . V_337 = ( V_202 < 8 ? ( V_194 . V_338 & ( 1 << V_202 )
? true : false )
: ( V_194 . V_339 & ( 1 << ( V_202 - 8 ) )
? true : false ) ) ;
if ( V_2 -> V_205 [ 0 ] >= '3' ) {
V_189 = sizeof( V_329 ) ;
if ( F_17 ( V_2 , V_340 , & V_189 , sizeof( V_189 ) , & V_329 , sizeof( V_329 ) )
!= sizeof( V_329 ) )
return F_42 ( V_2 , L_137 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
V_2 -> V_329 [ V_202 ] = V_329 [ V_202 ] ;
} else
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
if ( V_194 . V_334 [ V_202 ] . V_335 > 0 )
V_2 -> V_329 [ V_202 ] = 20 + 5 * V_194 . V_334 [ V_202 ]
. V_341 ;
return true ;
}
static void T_2 F_66 ( struct V_1
* V_2 , struct V_5 * V_6 )
{
V_6 -> V_342 = V_2 -> V_224 ;
V_6 -> V_343 = V_2 -> V_225 ;
V_6 -> V_344 = 0 ;
V_6 -> V_345 = V_2 -> V_88 ;
V_6 -> V_346 = V_2 -> V_207 ;
V_6 -> V_41 = V_2 -> V_38 ;
V_6 -> V_347 = V_2 -> V_222 ;
V_6 -> V_348 = V_2 -> V_267 ;
V_6 -> V_349 = V_2 -> V_272 ;
}
static int F_67 ( struct V_350 * V_116 )
{
struct V_1 * V_2 = (struct V_1 * ) V_116 -> V_351 -> V_7 ;
int V_202 = V_116 -> V_352 ;
int V_269 = V_2 -> V_269 [ V_202 ] ;
if ( V_2 -> V_307 [ V_202 ] . V_353 && ( V_2 -> V_232 & ( 1 << V_202 ) ) ) {
if ( V_269 == 0 )
V_269 = V_354 ;
V_2 -> V_269 [ V_202 ] = V_269 ;
F_68 ( V_116 , V_355 , V_269 ) ;
} else {
V_2 -> V_232 &= ~ ( 1 << V_202 ) ;
V_269 = V_2 -> V_272 ;
V_2 -> V_269 [ V_202 ] = V_269 ;
F_68 ( V_116 , 0 , V_269 ) ;
}
V_269 = 0 ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ )
if ( V_2 -> V_307 [ V_202 ] . V_332 ) {
V_269 += V_2 -> V_269 [ V_202 ] ;
}
if ( V_269 > V_2 -> V_29 )
F_11 ( V_2 , V_269 - V_2 -> V_29 , false ) ;
return 0 ;
}
static int T_2 F_69 ( void )
{
int V_356 = 0 , V_357 = 0 , V_358 ;
struct V_1 * V_98 ;
int V_359 = 0 ;
#ifdef F_70
if ( V_360 )
F_71 ( V_360 ) ;
#endif
if ( V_99 . V_361 )
return - V_362 ;
V_93 =
F_72 ( V_92 * sizeof( struct V_89 ) , V_363 ) ;
if ( V_93 == NULL ) {
F_8 ( L_138 , NULL ) ;
return - V_364 ;
}
V_98 =
F_72 ( sizeof( struct V_1 ) , V_363 ) ;
if ( V_98 == NULL ) {
F_73 ( V_93 ) ;
F_8 ( L_139 L_140 , NULL ) ;
return - V_364 ;
}
#ifdef F_70
if ( V_360 != NULL )
F_71 ( V_360 ) ;
#endif
F_41 ( V_98 ) ;
for ( V_358 = 0 ; V_358 < V_91 ; V_358 ++ ) {
struct V_89 * V_90 = & V_93 [ V_358 ] ;
struct V_1 * V_2 = V_98 ;
struct V_5 * V_6 ;
if ( V_90 -> V_88 == 0 )
continue;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_94 = V_90 -> V_94 ;
V_2 -> V_96 = V_90 -> V_96 ;
V_2 -> V_88 = V_90 -> V_88 ;
V_2 -> V_135 = V_90 -> V_135 ;
V_2 -> V_115 = V_90 -> V_115 ;
V_2 -> V_116 = V_90 -> V_116 ;
V_2 -> V_32 = V_90 -> V_32 ;
V_2 -> V_132 = V_90 -> V_132 ;
V_2 -> V_365 = V_366 [ V_2 -> V_94 ] ;
if ( ! F_74 ( V_2 -> V_88 , V_2 -> V_365 ,
L_141 ) )
continue;
if ( ! F_43 ( V_2 ) ) {
F_75 ( V_2 -> V_88 , V_2 -> V_365 ) ;
continue;
}
if ( ! F_46 ( V_2 , true ) ) {
F_75 ( V_2 -> V_88 , V_2 -> V_365 ) ;
continue;
}
if ( ! F_49 ( V_2 ) ) {
F_75 ( V_2 -> V_88 , V_2 -> V_365 ) ;
continue;
}
if ( V_357 < V_367 )
V_2 -> V_270 = & V_368 [ V_357 ++ ] ;
F_1 ( V_2 ) ;
V_6 = F_76 ( & V_369 , sizeof( struct V_1 ) ) ;
if ( V_6 == NULL ) {
F_75 ( V_2 -> V_88 , V_2 -> V_365 ) ;
continue;
}
V_2 = (struct V_1 * ) V_6 -> V_7 ;
memcpy ( V_2 , V_98 , sizeof( struct V_1 ) ) ;
V_2 -> V_40 = V_6 ;
V_2 -> V_370 = V_6 -> V_371 ;
F_77 ( & V_2 -> V_372 , & V_373 ) ;
if ( F_50 ( V_2 ) &&
F_51 ( V_2 ) &&
F_54 ( V_2 ) &&
F_6 ( V_2 ) &&
F_63 ( V_2 ) &&
F_64 ( V_2 ) ) {
F_75 ( V_2 -> V_88 ,
V_2 -> V_365 ) ;
if ( ! F_74 ( V_2 -> V_88 ,
V_2 -> V_365 ,
V_2 -> V_8 ) ) {
F_78 ( V_374
L_142
L_143 ,
( unsigned long ) V_2 -> V_88 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_79 ( & V_2 -> V_372 ) ;
F_80 ( V_6 ) ;
V_359 = - V_364 ;
} else {
F_66 ( V_2 ,
V_6 ) ;
if ( F_81 ( V_6 , V_2 -> V_32
? & V_2 -> V_32 -> V_375
: NULL ) ) {
F_78 ( V_374
L_144
L_145 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_79 ( & V_2 -> V_372 ) ;
F_80 ( V_6 ) ;
V_359 = - V_362 ;
} else {
F_82 ( V_6 ) ;
V_356 ++ ;
}
}
} else {
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_79 ( & V_2 -> V_372 ) ;
F_80 ( V_6 ) ;
V_359 = - V_362 ;
}
}
F_73 ( V_98 ) ;
F_73 ( V_93 ) ;
V_93 = NULL ;
return V_359 ;
}
static int T_5 F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_40 ;
F_84 ( V_6 ) ;
if ( F_5 ( V_2 ) )
F_85 ( V_2 -> V_183 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_75 ( V_2 -> V_88 , V_2 -> V_365 ) ;
F_79 ( & V_2 -> V_372 ) ;
F_80 ( V_6 ) ;
return 0 ;
}
static void V_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
V_13 -> V_17 = V_376 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_304 == NULL ) {
V_2 -> V_304 = V_13 ;
V_2 -> V_305 = V_13 ;
} else {
V_2 -> V_305 -> V_25 = V_13 ;
V_2 -> V_305 = V_13 ;
}
V_2 -> V_310 [ V_13 -> V_202 ] -- ;
}
static int F_86 ( struct V_1 * V_2 , enum V_377 V_378 , enum V_379 V_380 )
{
int V_381 ;
switch ( V_378 ) {
case V_382 :
case V_383 :
case V_384 :
V_381 = V_385 ;
break;
case V_386 :
V_381 = V_387 ;
break;
case V_388 :
case V_389 :
case V_390 :
F_38 ( L_146 , V_2 , V_378 ) ;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
V_381 = V_404 ;
break;
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
V_381 = V_410 ;
break;
default:
F_38 ( L_147 , V_2 , V_378 ) ;
V_381 = V_404 ;
break;
}
return ( V_381 << 16 ) | V_380 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_313 * V_319 = V_2 -> V_319 ;
enum V_411 V_412 ;
while ( ( V_412 = V_319 -> V_412 ) != V_413 ) {
struct V_12 * V_13 = (struct V_12 * ) F_88 ( V_319 -> V_13 ) ;
if ( V_412 != V_414 ) {
if ( V_13 -> V_17 == V_415 || V_13 -> V_17 == V_416 ) {
V_13 -> V_412 = V_412 ;
V_22 ( V_13 ) ;
} else {
F_38 ( L_148 L_149 , V_2 , V_13 -> V_42 , V_13 -> V_17 ) ;
}
}
V_319 -> V_412 = V_413 ;
if ( ++ V_319 > V_2 -> V_318 )
V_319 = V_2 -> V_317 ;
}
V_2 -> V_319 = V_319 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_417 )
return;
V_2 -> V_417 = true ;
while ( V_2 -> V_304 != NULL ) {
struct V_12 * V_13 = V_2 -> V_304 ;
struct V_418 * V_44 = V_13 -> V_44 ;
V_2 -> V_304 = V_13 -> V_25 ;
if ( V_2 -> V_304 == NULL )
V_2 -> V_305 = NULL ;
if ( V_13 -> V_419 == V_420 ) {
int V_202 = V_13 -> V_202 ;
F_38 ( L_150 L_151 , V_2 , V_13 -> V_42 , V_202 ) ;
F_90 ( & V_2 -> V_421 [ V_202 ] . V_422 ) ;
V_2 -> V_307 [ V_202 ] . V_308 = false ;
V_2 -> V_311 [ V_202 ] = 0 ;
V_2 -> V_423 [ V_202 ] = V_424 ;
F_14 ( V_13 ) ;
#if 0
while (Command != NULL) {
struct scsi_cmnd *NextCommand = Command->reset_chain;
Command->reset_chain = NULL;
Command->result = DID_RESET << 16;
Command->scsi_done(Command);
Command = NextCommand;
}
#endif
for ( V_13 = V_2 -> V_28 ; V_13 != NULL ; V_13 = V_13 -> V_27 )
if ( V_13 -> V_17 == V_416 && V_13 -> V_202 == V_202 ) {
V_44 = V_13 -> V_44 ;
F_14 ( V_13 ) ;
V_2 -> V_310 [ V_202 ] -- ;
V_44 -> V_425 = V_410 << 16 ;
V_44 -> V_426 ( V_44 ) ;
}
V_2 -> V_306 [ V_202 ] = NULL ;
} else {
switch ( V_13 -> V_412 ) {
case V_413 :
case V_414 :
case V_427 :
F_38 ( L_152 , V_2 , V_13 -> V_42 , V_13 -> V_202 ) ;
break;
case V_428 :
V_2 -> V_421 [ V_13 -> V_202 ]
. V_429 ++ ;
V_2 -> V_307 [ V_13 -> V_202 ]
. V_309 = true ;
V_44 -> V_425 = V_385 << 16 ;
break;
case V_430 :
F_38 ( L_153 , V_2 , V_13 -> V_42 , V_13 -> V_202 ) ;
F_90 ( & V_2 -> V_421 [ V_13 -> V_202 ]
. V_431 ) ;
V_44 -> V_425 = V_432 << 16 ;
break;
case V_433 :
V_44 -> V_425 = F_86 ( V_2 , V_13 -> V_378 , V_13 -> V_380 ) ;
if ( V_13 -> V_378 != V_386 ) {
V_2 -> V_421 [ V_13 -> V_202 ]
. V_429 ++ ;
if ( V_77 . V_434 ) {
int V_83 ;
F_12 ( L_154
L_155 L_156 , V_2 , V_13 -> V_42 , V_13 -> V_202 , V_44 -> V_425 , V_13 -> V_378 , V_13 -> V_380 ) ;
F_12 ( L_157 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_435 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_13 -> V_436 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
F_12 ( L_158 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_46 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_44 -> V_437 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
}
break;
}
if ( V_13 -> V_436 [ 0 ] == V_438 && V_13 -> V_436 [ 1 ] == 0 && V_13 -> V_378 == V_382 ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_13 -> V_202 ] ;
struct V_440 * V_441 =
(struct V_440 * ) F_91 ( V_44 ) ;
V_307 -> V_332 = true ;
V_307 -> V_353 = V_441 -> V_442 ;
V_307 -> V_443 = V_441 -> V_444 ;
}
F_14 ( V_13 ) ;
V_44 -> V_426 ( V_44 ) ;
}
}
V_2 -> V_417 = false ;
}
static T_6 V_291 ( int V_132 , void * V_445 )
{
struct V_1 * V_2 = (struct V_1 * ) V_445 ;
unsigned long V_60 ;
F_92 ( V_2 -> V_40 -> V_446 , V_60 ) ;
if ( F_53 ( V_2 ) ) {
union V_58 V_59 ;
V_59 . V_65 = F_22 ( V_2 ) ;
if ( V_59 . V_72 . V_447 ) {
F_24 ( V_2 ) ;
if ( V_59 . V_72 . V_448 )
V_2 -> V_449 = true ;
else if ( V_59 . V_72 . V_450 )
F_87 ( V_2 ) ;
else if ( V_59 . V_72 . V_73 )
V_2 -> V_71 = true ;
}
} else {
if ( F_93 ( V_2 -> V_183 ) )
switch ( F_94 ( V_2 -> V_183 ) ) {
case V_451 :
break;
case V_452 :
V_2 -> V_449 = true ;
break;
case V_453 :
F_38 ( L_159 L_160 , V_2 ) ;
V_2 -> V_454 = true ;
break;
}
}
if ( V_2 -> V_304 != NULL )
F_89 ( V_2 ) ;
if ( V_2 -> V_449 ) {
F_38 ( L_161 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_455 ) ;
F_95 ( V_2 , false ) ;
V_2 -> V_449 = false ;
} else if ( V_2 -> V_454 ) {
F_38 ( L_162 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_456 ) ;
F_95 ( V_2 , true ) ;
V_2 -> V_454 = false ;
}
F_96 ( V_2 -> V_40 -> V_446 , V_60 ) ;
return V_457 ;
}
static bool F_97 ( struct V_1
* V_2 , enum V_458 V_459 , struct V_12 * V_13 )
{
struct V_312 * V_316 ;
V_316 = V_2 -> V_316 ;
if ( V_316 -> V_459 == V_460 ) {
V_13 -> V_17 = V_415 ;
V_316 -> V_13 = V_13 -> V_19 ;
V_316 -> V_459 = V_459 ;
F_98 ( V_2 ) ;
if ( ++ V_316 > V_2 -> V_315 )
V_316 = V_2 -> V_314 ;
V_2 -> V_316 = V_316 ;
if ( V_459 == V_461 ) {
V_2 -> V_310 [ V_13 -> V_202 ] ++ ;
if ( V_13 -> V_419 != V_420 )
V_2 -> V_421 [ V_13 -> V_202 ] . V_462 ++ ;
}
return true ;
}
return false ;
}
static int F_99 ( struct V_418 * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_463 -> V_464 -> V_351 -> V_7 ;
unsigned int V_352 = V_463 -> V_464 -> V_352 ;
struct V_465 * V_466 = & V_2 -> V_421 [ V_352 ] ;
int V_467 ;
F_100 ( V_463 -> V_464 -> V_351 -> V_446 ) ;
F_90 ( & V_466 -> V_468 ) ;
V_467 = F_95 ( V_2 , false ) ;
F_101 ( V_463 -> V_464 -> V_351 -> V_446 ) ;
return V_467 ;
}
static int F_102 ( struct V_418 * V_44 , void (* F_103) ( struct V_418 * ) )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 -> V_464 -> V_351 -> V_7 ;
struct V_439 * V_307 = & V_2 -> V_307 [ V_44 -> V_464 -> V_352 ] ;
struct V_465 * V_421 = V_2 -> V_421 ;
unsigned char * V_436 = V_44 -> V_469 ;
int V_435 = V_44 -> V_470 ;
int V_202 = V_44 -> V_464 -> V_352 ;
int V_471 = V_44 -> V_464 -> V_472 ;
int V_473 = F_104 ( V_44 ) ;
int V_474 ;
struct V_12 * V_13 ;
if ( V_436 [ 0 ] == V_475 && V_44 -> V_437 [ 0 ] != 0 ) {
V_44 -> V_425 = V_385 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
F_101 ( V_2 -> V_40 -> V_446 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_446 ) ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
V_44 -> V_425 = V_404 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
}
V_474 = F_105 ( V_44 ) ;
F_106 ( V_474 < 0 ) ;
if ( V_474 ) {
struct V_476 * V_477 ;
int V_83 ;
V_13 -> V_419 = V_478 ;
V_13 -> V_479 = V_474 * sizeof( struct V_480 ) ;
if ( F_53 ( V_2 ) )
V_13 -> V_481 = ( unsigned int ) V_13 -> V_19 + ( ( unsigned long ) & V_13 -> V_482 - ( unsigned long ) V_13 ) ;
else
V_13 -> V_481 = F_107 ( V_13 -> V_482 ) ;
F_108 (Command, sg, Count, i) {
V_13 -> V_482 [ V_83 ] . V_483 =
F_109 ( V_477 ) ;
V_13 -> V_482 [ V_83 ] . V_484 =
F_110 ( V_477 ) ;
}
} else if ( ! V_474 ) {
V_13 -> V_419 = V_485 ;
V_13 -> V_479 = V_473 ;
V_13 -> V_481 = 0 ;
}
switch ( V_436 [ 0 ] ) {
case V_486 :
case V_487 :
V_13 -> V_488 = V_489 ;
V_421 [ V_202 ] . V_490 ++ ;
F_111 ( & V_421 [ V_202 ] . V_491 , V_473 ) ;
F_112 ( V_421 [ V_202 ] . V_492 , V_473 ) ;
break;
case V_493 :
case V_494 :
V_13 -> V_488 = V_495 ;
V_421 [ V_202 ] . V_496 ++ ;
F_111 ( & V_421 [ V_202 ] . V_497 , V_473 ) ;
F_112 ( V_421 [ V_202 ] . V_498 , V_473 ) ;
break;
default:
V_13 -> V_488 = V_499 ;
break;
}
V_13 -> V_435 = V_435 ;
V_13 -> V_378 = 0 ;
V_13 -> V_380 = 0 ;
V_13 -> V_202 = V_202 ;
V_13 -> V_471 = V_471 ;
V_13 -> V_500 = false ;
V_13 -> V_501 = false ;
if ( V_2 -> V_311 [ V_202 ] ++ >=
V_502 && ! V_307 -> V_308 && V_2 -> V_310 [ V_202 ] == 0 && V_307 -> V_353 && ( V_2 -> V_232 & ( 1 << V_202 ) ) ) {
V_307 -> V_308 = true ;
F_12 ( L_163 , V_2 , V_202 ) ;
}
if ( V_307 -> V_308 ) {
enum V_503 V_504 = V_505 ;
if ( V_2 -> V_310 [ V_202 ] == 0 )
V_2 -> V_506 [ V_202 ] = V_424 ;
else if ( F_113 ( V_424 , V_2 -> V_506 [ V_202 ] + 4 * V_507 ) ) {
V_2 -> V_506 [ V_202 ] = V_424 ;
V_504 = V_508 ;
}
if ( V_2 -> V_216 ) {
V_13 -> V_500 = true ;
V_13 -> V_504 = V_504 ;
} else {
V_13 -> V_501 = true ;
V_13 -> V_509 = V_504 ;
}
}
memcpy ( V_13 -> V_436 , V_436 , V_435 ) ;
V_13 -> V_46 = V_510 ;
V_13 -> V_45 = F_114 ( V_2 -> V_32 , V_44 -> V_437 , V_13 -> V_46 , V_47 ) ;
V_13 -> V_44 = V_44 ;
V_44 -> V_426 = F_103 ;
if ( F_53 ( V_2 ) ) {
if ( ! F_97 ( V_2 , V_461 , V_13 ) ) {
F_101 ( V_2 -> V_40 -> V_446 ) ;
F_38 ( L_164 L_165 , V_2 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_446 ) ;
if ( ! F_97 ( V_2 , V_461 , V_13 ) ) {
F_38 ( L_166 L_167 , V_2 ) ;
F_14 ( V_13 ) ;
V_44 -> V_425 = V_404 << 16 ;
V_44 -> V_426 ( V_44 ) ;
}
}
} else {
V_13 -> V_17 = V_415 ;
V_2 -> V_310 [ V_202 ] ++ ;
V_421 [ V_202 ] . V_462 ++ ;
F_115 ( V_2 -> V_183 , V_13 ) ;
if ( V_13 -> V_17 == V_376 )
F_89 ( V_2 ) ;
}
return 0 ;
}
int F_116 ( struct V_350 * V_511 , struct V_512 * V_116 , T_7 V_513 , int * V_514 )
{
struct V_1 * V_2 = (struct V_1 * ) V_511 -> V_351 -> V_7 ;
struct V_515 * V_516 = (struct V_515 * ) V_514 ;
unsigned char * V_517 ;
if ( V_2 -> V_208 && V_513 >= 2 * 1024 * 1024 ) {
if ( V_513 >= 4 * 1024 * 1024 ) {
V_516 -> V_518 = 255 ;
V_516 -> V_519 = 63 ;
} else {
V_516 -> V_518 = 128 ;
V_516 -> V_519 = 32 ;
}
} else {
V_516 -> V_518 = 64 ;
V_516 -> V_519 = 32 ;
}
V_516 -> V_520 = ( unsigned long ) V_513 / ( V_516 -> V_518 * V_516 -> V_519 ) ;
V_517 = F_117 ( V_116 ) ;
if ( V_517 == NULL )
return 0 ;
if ( * ( unsigned short * ) ( V_517 + 64 ) == 0xAA55 ) {
struct V_521 * V_522 = (struct V_521 * ) V_517 ;
struct V_521 * V_523 = V_522 ;
int V_524 = V_516 -> V_520 , V_525 ;
unsigned char V_526 = 0 , V_527 = 0 ;
for ( V_525 = 0 ; V_525 < 4 ; V_525 ++ ) {
V_526 = V_523 -> V_528 ;
V_527 = V_523 -> V_529 & 0x3F ;
if ( V_526 == 64 - 1 ) {
V_516 -> V_518 = 64 ;
V_516 -> V_519 = 32 ;
break;
} else if ( V_526 == 128 - 1 ) {
V_516 -> V_518 = 128 ;
V_516 -> V_519 = 32 ;
break;
} else if ( V_526 == 255 - 1 ) {
V_516 -> V_518 = 255 ;
V_516 -> V_519 = 63 ;
break;
}
V_523 ++ ;
}
if ( V_525 == 4 ) {
V_526 = V_522 -> V_528 ;
V_527 = V_522 -> V_529 & 0x3F ;
}
V_516 -> V_520 = ( unsigned long ) V_513 / ( V_516 -> V_518 * V_516 -> V_519 ) ;
if ( V_525 < 4 && V_527 == V_516 -> V_519 ) {
if ( V_516 -> V_520 != V_524 )
F_38 ( L_168 , V_2 , V_516 -> V_518 , V_516 -> V_519 ) ;
} else if ( V_526 > 0 || V_527 > 0 ) {
F_38 ( L_169 L_170 , V_2 , V_526 + 1 , V_527 ) ;
F_38 ( L_171 L_172 , V_2 , V_516 -> V_518 , V_516 -> V_519 ) ;
}
}
F_73 ( V_517 ) ;
return 0 ;
}
static int F_118 ( struct V_5 * V_530 , char * V_531 , int V_532 )
{
struct V_1 * V_2 = (struct V_1 * ) V_530 -> V_7 ;
struct V_465 * V_421 ;
V_421 = V_2 -> V_421 ;
V_2 -> V_455 = 0 ;
V_2 -> V_456 = 0 ;
memset ( V_421 , 0 , V_268 * sizeof( struct V_465 ) ) ;
return 0 ;
}
static int F_119 ( struct V_533 * V_534 , struct V_5 * V_530 )
{
struct V_1 * V_2 = (struct V_1 * ) V_530 -> V_7 ;
struct V_465 * V_421 ;
int V_202 ;
V_421 = V_2 -> V_421 ;
F_120 ( V_534 , V_2 -> V_535 , V_2 -> V_536 ) ;
F_121 ( V_534 , L_173 , V_2 -> V_38 , V_2 -> V_29 ) ;
F_121 ( V_534 , L_174 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_202 ] ;
if ( ! V_307 -> V_332 )
continue;
F_121 ( V_534 , L_175 , V_202 , ( V_307 -> V_353 ? ( V_307 -> V_308 ? L_176 : ( V_2 -> V_232 & ( 1 << V_202 )
? L_177 : L_178 ) )
: L_179 ) ) ;
F_121 ( V_534 ,
L_180 , V_2 -> V_269 [ V_202 ] , V_2 -> V_310 [ V_202 ] , V_421 [ V_202 ] . V_462 , V_421 [ V_202 ] . V_429 ) ;
}
F_121 ( V_534 , L_181 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_202 ] ;
if ( ! V_307 -> V_332 )
continue;
F_121 ( V_534 , L_182 , V_202 , V_421 [ V_202 ] . V_490 , V_421 [ V_202 ] . V_496 ) ;
if ( V_421 [ V_202 ] . V_491 . V_537 > 0 )
F_121 ( V_534 , L_183 , V_421 [ V_202 ] . V_491 . V_537 , V_421 [ V_202 ] . V_491 . V_538 ) ;
else
F_121 ( V_534 , L_184 , V_421 [ V_202 ] . V_491 . V_538 ) ;
if ( V_421 [ V_202 ] . V_497 . V_537 > 0 )
F_121 ( V_534 , L_185 , V_421 [ V_202 ] . V_497 . V_537 , V_421 [ V_202 ] . V_497 . V_538 ) ;
else
F_121 ( V_534 , L_186 , V_421 [ V_202 ] . V_497 . V_538 ) ;
}
F_121 ( V_534 , L_187 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_202 ] ;
if ( ! V_307 -> V_332 )
continue;
F_121 ( V_534 ,
L_188 , V_202 ,
V_421 [ V_202 ] . V_492 [ 0 ] ,
V_421 [ V_202 ] . V_492 [ 1 ] , V_421 [ V_202 ] . V_492 [ 2 ] , V_421 [ V_202 ] . V_492 [ 3 ] , V_421 [ V_202 ] . V_492 [ 4 ] ) ;
F_121 ( V_534 ,
L_189 , V_202 ,
V_421 [ V_202 ] . V_498 [ 0 ] ,
V_421 [ V_202 ] . V_498 [ 1 ] , V_421 [ V_202 ] . V_498 [ 2 ] , V_421 [ V_202 ] . V_498 [ 3 ] , V_421 [ V_202 ] . V_498 [ 4 ] ) ;
}
F_121 ( V_534 , L_190 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_202 ] ;
if ( ! V_307 -> V_332 )
continue;
F_121 ( V_534 ,
L_188 , V_202 ,
V_421 [ V_202 ] . V_492 [ 5 ] ,
V_421 [ V_202 ] . V_492 [ 6 ] , V_421 [ V_202 ] . V_492 [ 7 ] , V_421 [ V_202 ] . V_492 [ 8 ] , V_421 [ V_202 ] . V_492 [ 9 ] ) ;
F_121 ( V_534 ,
L_189 , V_202 ,
V_421 [ V_202 ] . V_498 [ 5 ] ,
V_421 [ V_202 ] . V_498 [ 6 ] , V_421 [ V_202 ] . V_498 [ 7 ] , V_421 [ V_202 ] . V_498 [ 8 ] , V_421 [ V_202 ] . V_498 [ 9 ] ) ;
}
F_121 ( V_534 , L_191 ) ;
for ( V_202 = 0 ; V_202 < V_2 -> V_224 ; V_202 ++ ) {
struct V_439 * V_307 = & V_2 -> V_307 [ V_202 ] ;
if ( ! V_307 -> V_332 )
continue;
F_121 ( V_534 , L_192 , V_202 , V_421 [ V_202 ] . V_539 , V_421 [ V_202 ] . V_540 , V_421 [ V_202 ] . V_431 , V_421 [ V_202 ] . V_541 , V_421 [ V_202 ] . V_542 , V_421 [ V_202 ] . V_422 , V_421 [ V_202 ] . V_468 , V_421 [ V_202 ] . V_543 , V_421 [ V_202 ] . V_544 ) ;
}
F_121 ( V_534 , L_193 , V_2 -> V_455 ) ;
F_121 ( V_534 , L_194 , V_2 -> V_456 ) ;
return 0 ;
}
static void F_122 ( enum V_545 V_546 , char * V_547 , struct V_1 * V_2 , ... )
{
static char V_548 [ V_549 ] ;
static bool V_550 = true ;
T_8 V_551 ;
int V_552 = 0 ;
va_start ( V_551 , V_2 ) ;
V_552 = vsprintf ( V_548 , V_547 , V_551 ) ;
va_end ( V_551 ) ;
if ( V_546 == V_553 ) {
static int V_554 = 0 ;
strcpy ( & V_2 -> V_535 [ V_2 -> V_536 ] , V_548 ) ;
V_2 -> V_536 += V_552 ;
if ( ++ V_554 <= 2 )
F_78 ( L_195 , V_555 [ V_546 ] , V_548 ) ;
} else if ( V_546 == V_556 ) {
strcpy ( & V_2 -> V_535 [ V_2 -> V_536 ] , V_548 ) ;
V_2 -> V_536 += V_552 ;
if ( V_550 ) {
if ( V_548 [ 0 ] != '\n' || V_552 > 1 )
F_78 ( L_196 , V_555 [ V_546 ] , V_2 -> V_370 , V_548 ) ;
} else
F_78 ( L_197 , V_548 ) ;
} else {
if ( V_550 ) {
if ( V_2 != NULL && V_2 -> V_326 )
F_78 ( L_196 , V_555 [ V_546 ] , V_2 -> V_370 , V_548 ) ;
else
F_78 ( L_198 , V_555 [ V_546 ] , V_548 ) ;
} else
F_78 ( L_197 , V_548 ) ;
}
V_550 = ( V_548 [ V_552 - 1 ] == '\n' ) ;
}
static bool T_2 F_123 ( char * * V_557 , char * V_558 )
{
char * V_559 = * V_557 ;
while ( * V_558 != '\0' ) {
char V_560 = * V_559 ++ ;
char V_561 = * V_558 ++ ;
if ( V_560 >= 'A' && V_560 <= 'Z' )
V_560 += 'a' - 'Z' ;
if ( V_561 >= 'A' && V_561 <= 'Z' )
V_561 += 'a' - 'Z' ;
if ( V_560 != V_561 )
return false ;
}
* V_557 = V_559 ;
return true ;
}
static int T_2 F_124 ( char * V_562 )
{
while ( true ) {
struct V_368 * V_270 = & V_368 [ V_367 ++ ] ;
int V_202 ;
memset ( V_270 , 0 , sizeof( struct V_368 ) ) ;
while ( * V_562 != '\0' && * V_562 != ';' ) {
if ( F_123 ( & V_562 , L_199 ) ) {
unsigned long V_88 = F_125 ( V_562 , & V_562 , 0 ) ;
V_99 . V_101 = true ;
switch ( V_88 ) {
case 0x330 :
V_99 . V_102 = true ;
break;
case 0x334 :
V_99 . V_103 = true ;
break;
case 0x230 :
V_99 . V_104 = true ;
break;
case 0x234 :
V_99 . V_105 = true ;
break;
case 0x130 :
V_99 . V_106 = true ;
break;
case 0x134 :
V_99 . V_107 = true ;
break;
default:
F_8 ( L_200 L_201 , NULL , V_88 ) ;
return 0 ;
}
} else if ( F_123 ( & V_562 , L_202 ) )
V_99 . V_100 = true ;
else if ( F_123 ( & V_562 , L_203 ) )
V_99 . V_164 = true ;
else if ( F_123 ( & V_562 , L_204 ) )
V_99 . V_361 = true ;
else if ( F_123 ( & V_562 , L_205 ) )
V_99 . V_563 = true ;
else if ( F_123 ( & V_562 , L_206 ) )
V_99 . V_165 = true ;
else if ( F_123 ( & V_562 , L_207 ) )
V_99 . V_166 = true ;
else if ( F_123 ( & V_562 , L_208 ) || F_123 ( & V_562 , L_209 ) ) {
for ( V_202 = 0 ; V_202 < V_268 ; V_202 ++ ) {
unsigned short V_269 = F_125 ( V_562 , & V_562 , 0 ) ;
if ( V_269 > V_502 ) {
F_8 ( L_200 L_210 , NULL , V_269 ) ;
return 0 ;
}
V_270 -> V_269 [ V_202 ] = V_269 ;
if ( * V_562 == ',' )
V_562 ++ ;
else if ( * V_562 == ']' )
break;
else {
F_8 ( L_200 L_211 , NULL , V_562 ) ;
return 0 ;
}
}
if ( * V_562 != ']' ) {
F_8 ( L_200 L_212 , NULL , V_562 ) ;
return 0 ;
} else
V_562 ++ ;
} else if ( F_123 ( & V_562 , L_213 ) || F_123 ( & V_562 , L_214 ) ) {
unsigned short V_269 = F_125 ( V_562 , & V_562 , 0 ) ;
if ( V_269 == 0 || V_269 > V_502 ) {
F_8 ( L_200 L_210 , NULL , V_269 ) ;
return 0 ;
}
V_270 -> V_275 = V_269 ;
for ( V_202 = 0 ; V_202 < V_268 ; V_202 ++ )
V_270 -> V_269 [ V_202 ] = V_269 ;
} else if ( F_123 ( & V_562 , L_215 ) || F_123 ( & V_562 , L_216 ) ) {
if ( F_123 ( & V_562 , L_217 ) ) {
V_270 -> V_232 = 0x0000 ;
V_270 -> V_276 = 0x0000 ;
} else if ( F_123 ( & V_562 , L_218 ) ) {
V_270 -> V_232 = 0xFFFF ;
V_270 -> V_276 = 0xFFFF ;
} else if ( F_123 ( & V_562 , L_219 ) ) {
V_270 -> V_232 = 0x0000 ;
V_270 -> V_276 = 0xFFFF ;
} else {
unsigned short V_564 ;
for ( V_202 = 0 , V_564 = 1 ; V_202 < V_268 ; V_202 ++ , V_564 <<= 1 )
switch ( * V_562 ++ ) {
case 'Y' :
V_270 -> V_232 |= V_564 ;
V_270 -> V_276 |= V_564 ;
break;
case 'N' :
V_270 -> V_232 &= ~ V_564 ;
V_270 -> V_276 |= V_564 ;
break;
case 'X' :
break;
default:
V_562 -- ;
V_202 = V_268 ;
break;
}
}
}
else if ( F_123 ( & V_562 , L_220 ) || F_123 ( & V_562 , L_221 ) ) {
unsigned short V_277 = F_125 ( V_562 , & V_562 , 0 ) ;
if ( V_277 > 5 * 60 ) {
F_8 ( L_200 L_222 , NULL , V_277 ) ;
return 0 ;
}
V_270 -> V_277 = V_277 ;
} else if ( F_123 ( & V_562 , L_223 ) )
V_270 -> V_330 . V_331 = true ;
else if ( F_123 ( & V_562 , L_224 ) )
V_77 . V_142 = true ;
else if ( F_123 ( & V_562 , L_225 ) )
V_77 . V_185 = true ;
else if ( F_123 ( & V_562 , L_226 ) )
V_77 . V_78 = true ;
else if ( F_123 ( & V_562 , L_227 ) )
V_77 . V_434 = true ;
else if ( F_123 ( & V_562 , L_228 ) ) {
V_77 . V_142 = true ;
V_77 . V_185 = true ;
V_77 . V_78 = true ;
V_77 . V_434 = true ;
}
if ( * V_562 == ',' )
V_562 ++ ;
else if ( * V_562 != ';' && * V_562 != '\0' ) {
F_8 ( L_229 L_230 , NULL , V_562 ) ;
* V_562 = '\0' ;
}
}
if ( ! ( V_367 == 0 || V_91 == 0 || V_367 == V_91 ) ) {
F_8 ( L_200 L_231 , NULL ) ;
return 0 ;
}
for ( V_202 = 0 ; V_202 < V_268 ; V_202 ++ )
if ( V_270 -> V_269 [ V_202 ] == 1 ) {
unsigned short V_564 = 1 << V_202 ;
V_270 -> V_232 &= ~ V_564 ;
V_270 -> V_276 |= V_564 ;
}
if ( * V_562 == ';' )
V_562 ++ ;
if ( * V_562 == '\0' )
return 0 ;
}
return 1 ;
}
static int T_2 F_71 ( char * V_565 )
{
int V_566 [ 3 ] ;
( void ) F_126 ( V_565 , F_127 ( V_566 ) , V_566 ) ;
if ( V_566 [ 0 ] != 0 ) {
F_8 ( L_232 L_233 , NULL ) ;
return 0 ;
}
if ( V_565 == NULL || * V_565 == '\0' )
return 0 ;
return F_124 ( V_565 ) ;
}
static void T_5 F_128 ( void )
{
struct V_1 * V_567 , * V_568 ;
F_129 (ha, next, &BusLogic_host_list, host_list)
F_83 ( V_567 ) ;
}
