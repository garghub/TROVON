static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 V_3 L_2 V_4 L_3 , V_2 ) ;
F_2 ( L_4 L_5 , V_2 ) ;
}
static const char * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_6 -> V_7 ;
return V_2 -> V_8 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_9 ,
int V_10 , T_1 V_11 )
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
V_9 = F_7 ( V_2 -> V_32 ,
V_10 , & V_11 ) ;
if ( V_9 == NULL ) {
F_8 ( L_6 ,
V_2 ) ;
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
F_10 ( V_2 -> V_32 ,
V_34 -> V_16 , V_34 ,
V_34 -> V_15 ) ;
V_34 = V_13 ;
}
}
if ( V_34 )
F_10 ( V_2 -> V_32 , V_34 -> V_16 ,
V_34 , V_34 -> V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
int V_35 , bool V_36 )
{
int V_10 = V_30 * sizeof( struct V_12 ) ;
int V_37 = V_2 -> V_29 ;
void * V_9 ;
T_1 V_11 ;
if ( V_35 <= 0 )
return;
while ( V_2 -> V_29 - V_37 < V_35 ) {
V_9 = F_7 ( V_2 -> V_32 ,
V_10 , & V_11 ) ;
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
static struct V_12 * F_13 ( struct V_1 * V_2 )
{
static unsigned long V_42 ;
struct V_12 * V_13 ;
V_13 = V_2 -> V_26 ;
if ( V_13 != NULL ) {
V_13 -> V_42 = ++ V_42 ;
V_2 -> V_26 = V_13 -> V_25 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_26 == NULL )
F_11 ( V_2 , V_2 -> V_43 ,
true ) ;
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
static int F_17 ( struct V_1 * V_2 , enum V_48 V_49 ,
void * V_50 , int V_51 , void * V_52 , int V_53 )
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
V_69 =
L_9 ;
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
V_69 =
L_10 ;
V_62 = - 2 ;
goto V_70;
}
if ( V_49 == V_75 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_76 ) {
V_69 =
L_11 ;
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
if ( V_49 == V_82 &&
V_57 . V_66 . V_67 )
break;
F_20 ( 100 ) ;
}
if ( V_63 < 0 ) {
V_69 =
L_14 ;
V_62 = - 2 ;
goto V_70;
}
F_24 ( V_2 ) ;
if ( V_77 . V_78 ) {
int V_83 ;
F_12 ( L_15 ,
V_2 , V_49 , V_57 . V_65 , V_53 ,
V_61 ) ;
if ( V_53 > V_61 )
V_53 = V_61 ;
for ( V_83 = 0 ; V_83 < V_53 ; V_83 ++ )
F_12 ( L_16 , V_2 ,
( ( unsigned char * ) V_52 ) [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
if ( V_57 . V_66 . V_76 ) {
F_20 ( 1000 ) ;
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_76 || V_57 . V_66 . V_84 ||
V_57 . V_66 . V_74 ||
V_57 . V_66 . V_68 ||
! V_57 . V_66 . V_67 ||
! V_57 . V_66 . V_85 ||
V_57 . V_66 . V_86 ||
V_57 . V_66 . V_87 ) {
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
static void T_2 F_28 ( struct V_1 * V_2 )
{
if ( V_98 . V_99 )
return;
if ( ! V_98 . V_100 || V_98 . V_101 )
F_27 ( 0x330 ) ;
if ( ! V_98 . V_100 || V_98 . V_102 )
F_27 ( 0x334 ) ;
if ( ! V_98 . V_100 || V_98 . V_103 )
F_27 ( 0x230 ) ;
if ( ! V_98 . V_100 || V_98 . V_104 )
F_27 ( 0x234 ) ;
if ( ! V_98 . V_100 || V_98 . V_105 )
F_27 ( 0x130 ) ;
if ( ! V_98 . V_100 || V_98 . V_106 )
F_27 ( 0x134 ) ;
}
static void T_2 F_29 ( struct V_89
* V_107 , int V_108 )
{
int V_109 = V_108 - 1 , V_110 , V_111 ;
while ( V_109 > 0 ) {
V_110 = V_109 ;
V_109 = 0 ;
for ( V_111 = 0 ; V_111 < V_110 ; V_111 ++ ) {
struct V_89 * V_112 =
& V_107 [ V_111 ] ;
struct V_89 * V_113 =
& V_107 [ V_111 + 1 ] ;
if ( V_112 -> V_114 > V_113 -> V_114 ||
( V_112 -> V_114 == V_113 -> V_114 &&
( V_112 -> V_115 > V_113 -> V_115 ) ) ) {
struct V_89 V_116 ;
memcpy ( & V_116 , V_112 ,
sizeof( struct V_89 ) ) ;
memcpy ( V_112 , V_113 ,
sizeof( struct V_89 ) ) ;
memcpy ( V_113 , & V_116 ,
sizeof( struct V_89 ) ) ;
V_109 = V_111 ;
}
}
}
}
static int T_2 F_30 ( struct V_1 * V_2 )
{
struct V_89 * V_117 =
& V_93 [ V_91 ] ;
int V_118 = V_91 + 1 ;
int V_119 = 0 , V_120 = 0 ;
bool V_121 = false ;
bool V_122 = false ;
bool V_123 [ 6 ] ;
struct V_124 * V_32 = NULL ;
int V_83 ;
if ( V_91 >= V_92 )
return 0 ;
V_91 ++ ;
for ( V_83 = 0 ; V_83 < 6 ; V_83 ++ )
V_123 [ V_83 ] = false ;
V_117 -> V_88 = 0 ;
while ( ( V_32 = F_31 ( V_125 ,
V_126 ,
V_32 ) ) != NULL ) {
struct V_1 * V_2 = V_2 ;
struct V_127 V_128 ;
enum V_129 V_130 ;
unsigned char V_114 ;
unsigned char V_131 ;
unsigned int V_132 ;
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_88 ;
unsigned long V_135 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_136 ;
V_131 = V_32 -> V_137 >> 3 ;
V_132 = V_32 -> V_138 ;
V_88 = V_133 = F_35 ( V_32 , 0 ) ;
V_135 = V_134 = F_35 ( V_32 , 1 ) ;
if ( F_36 ( V_32 , 0 ) & V_139 ) {
F_8 ( L_20 L_21 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_114 , V_131 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_140 ) {
F_8 ( L_23 L_21 , NULL , V_134 ) ;
F_8 ( L_24 , NULL , V_114 , V_131 , V_135 ) ;
continue;
}
if ( V_132 == 0 ) {
F_8 ( L_25 L_21 , NULL , V_132 ) ;
F_8 ( L_22 , NULL , V_114 , V_131 , V_88 ) ;
continue;
}
if ( V_77 . V_141 ) {
F_12 ( L_26 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_114 , V_131 , V_88 , V_135 ) ;
}
V_2 -> V_88 = V_88 ;
F_24 ( V_2 ) ;
if ( F_17 ( V_2 , V_142 , NULL , 0 ,
& V_128 , sizeof( V_128 ) ) ==
sizeof( V_128 ) ) {
if ( V_128 . V_143 < 6 )
V_123 [ V_128 . V_143 ] = true ;
} else
V_128 . V_143 = V_144 ;
V_130 = V_144 ;
F_17 ( V_2 , V_75 , & V_130 ,
sizeof( V_130 ) , NULL , 0 ) ;
if ( ! V_122 ) {
struct V_145 V_146 ;
struct V_147 V_148 ;
struct V_149 V_150 ;
V_146 . V_14 = V_151 + 45 ;
V_146 . V_152 = sizeof( V_148 ) ;
F_17 ( V_2 , V_82 ,
& V_146 , sizeof( V_146 ) ,
& V_148 ,
sizeof( V_148 ) ) ;
F_17 ( V_2 , V_153 , NULL , 0 , & V_150 ,
sizeof( V_150 ) ) ;
if ( V_150 . V_154 == '5' )
V_121 =
V_148 . V_121 ;
V_122 = true ;
}
if ( V_128 . V_143 == V_155 ) {
V_117 -> V_94 = V_95 ;
V_117 -> V_96 = V_156 ;
V_117 -> V_88 = V_88 ;
V_117 -> V_135 = V_135 ;
V_117 -> V_114 = V_114 ;
V_117 -> V_115 = V_131 ;
V_117 -> V_132 = V_132 ;
V_117 -> V_32 = F_37 ( V_32 ) ;
V_120 ++ ;
} else if ( V_91 < V_92 ) {
struct V_89 * V_90 =
& V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 = V_156 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_135 = V_135 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_131 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
V_119 ++ ;
V_120 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
}
if ( V_121 )
F_29 ( & V_93 [ V_118 ] ,
V_119 ) ;
if ( ! V_98 . V_99 )
if ( V_117 -> V_88 == 0 &&
( ! V_98 . V_100 ||
V_98 . V_101 ) ) {
V_117 -> V_94 = V_95 ;
V_117 -> V_96 = V_97 ;
V_117 -> V_88 = 0x330 ;
}
if ( ! V_98 . V_99 ) {
if ( ! V_123 [ 1 ] &&
( ! V_98 . V_100 ||
V_98 . V_102 ) )
F_27 ( 0x334 ) ;
if ( ! V_123 [ 2 ] &&
( ! V_98 . V_100 ||
V_98 . V_103 ) )
F_27 ( 0x230 ) ;
if ( ! V_123 [ 3 ] &&
( ! V_98 . V_100 ||
V_98 . V_104 ) )
F_27 ( 0x234 ) ;
if ( ! V_123 [ 4 ] &&
( ! V_98 . V_100 ||
V_98 . V_105 ) )
F_27 ( 0x130 ) ;
if ( ! V_123 [ 5 ] &&
( ! V_98 . V_100 ||
V_98 . V_106 ) )
F_27 ( 0x134 ) ;
}
V_32 = NULL ;
while ( ( V_32 = F_31 ( V_125 ,
V_157 ,
V_32 ) ) != NULL ) {
unsigned char V_114 ;
unsigned char V_131 ;
unsigned int V_132 ;
unsigned long V_88 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_136 ;
V_131 = V_32 -> V_137 >> 3 ;
V_132 = V_32 -> V_138 ;
V_88 = F_35 ( V_32 , 0 ) ;
if ( V_88 == 0 || V_132 == 0 )
continue;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
struct V_89 * V_90 =
& V_93 [ V_83 ] ;
if ( V_90 -> V_88 == V_88 &&
V_90 -> V_94 == V_95 ) {
V_90 -> V_96 = V_156 ;
V_90 -> V_135 = 0 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_131 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
break;
}
}
}
return V_120 ;
}
static int T_2 F_39 ( struct V_1 * V_2 )
{
int V_158 = V_91 , V_159 = 0 ;
struct V_124 * V_32 = NULL ;
while ( ( V_32 = F_31 ( V_125 ,
V_160 ,
V_32 ) ) != NULL ) {
unsigned char V_114 ;
unsigned char V_131 ;
unsigned int V_132 ;
unsigned long V_133 ;
unsigned long V_134 ;
unsigned long V_88 ;
unsigned long V_135 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_136 ;
V_131 = V_32 -> V_137 >> 3 ;
V_132 = V_32 -> V_138 ;
V_88 = V_133 = F_35 ( V_32 , 0 ) ;
V_135 = V_134 = F_35 ( V_32 , 1 ) ;
#ifdef F_40
if ( F_36 ( V_32 , 0 ) & V_139 ) {
F_8 ( L_20 L_32 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_114 , V_131 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_140 ) {
F_8 ( L_23 L_32 , NULL , V_134 ) ;
F_8 ( L_24 , NULL , V_114 , V_131 , V_135 ) ;
continue;
}
if ( V_132 == 0 ) {
F_8 ( L_25 L_32 , NULL , V_132 ) ;
F_8 ( L_22 , NULL , V_114 , V_131 , V_88 ) ;
continue;
}
if ( V_77 . V_141 ) {
F_12 ( L_33 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_114 , V_131 , V_88 , V_135 ) ;
}
if ( V_91 < V_92 ) {
struct V_89 * V_90 =
& V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_161 ;
V_90 -> V_96 = V_156 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_135 = V_135 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_131 ;
V_90 -> V_132 = V_132 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
V_159 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
#else
F_8 ( L_34 L_35 , NULL , V_114 , V_131 ) ;
F_8 ( L_36 L_37 , NULL , V_88 , V_135 , V_132 ) ;
F_8 ( L_38 L_39 , NULL ) ;
#endif
}
F_29 ( & V_93 [ V_158 ] , V_159 ) ;
return V_159 ;
}
static void T_2 F_41 ( struct V_1 * V_2 )
{
if ( ! V_98 . V_162 ) {
if ( V_98 . V_163 ) {
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
} else if ( V_98 . V_164 ) {
F_39 ( V_2 ) ;
F_30 ( V_2 ) ;
} else {
int V_159 = F_39 ( V_2 ) ;
int V_120 = F_30 ( V_2 ) ;
if ( V_159 > 0 && V_120 > 0 ) {
struct V_89 * V_90 =
& V_93 [ V_159 ] ;
struct V_1 * V_165 = V_2 ;
struct V_145 V_146 ;
struct V_166 V_167 ;
while ( V_90 -> V_96 !=
V_156 )
V_90 ++ ;
V_165 -> V_88 = V_90 -> V_88 ;
V_146 . V_14 =
V_168 + V_169 ;
V_146 . V_152 = sizeof( V_167 ) ;
F_17 ( V_165 , V_82 ,
& V_146 ,
sizeof( V_146 ) ,
& V_167 ,
sizeof( V_167 ) ) ;
if ( V_167 . V_170 != V_171 ) {
struct V_89 V_172 [ V_92 ] ;
int V_120 = V_91 - V_159 ;
memcpy ( V_172 ,
V_93 ,
V_91 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ 0 ] ,
& V_172 [ V_159 ] ,
V_120 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ V_120 ] ,
& V_172 [ 0 ] ,
V_159 * sizeof( struct V_89 ) ) ;
}
}
}
} else {
F_28 ( V_2 ) ;
}
}
static bool F_42 ( struct V_1 * V_2 , char * V_173 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_96 == V_156 ) {
F_8 ( L_40 ,
V_2 ) ;
F_8 ( L_41 , V_2 , V_2 -> V_114 , V_2 -> V_115 , V_2 -> V_88 , V_2 -> V_135 ) ;
} else
F_8 ( L_42 L_43 , V_2 , V_2 -> V_88 ) ;
F_8 ( L_44 , V_2 , V_173 ) ;
if ( V_69 != NULL )
F_8 ( L_45 , V_2 ,
V_69 ) ;
return false ;
}
static bool T_2 F_43 ( struct V_1 * V_2 )
{
union V_56 V_57 ;
union V_58 V_59 ;
union V_174 V_175 ;
if ( F_5 ( V_2 ) ) {
struct V_176 * V_24 = & V_2 -> V_24 ;
V_24 -> V_23 = ( V_20 ) V_2 -> V_88 ;
V_24 -> V_132 = V_2 -> V_132 ;
V_24 -> V_177 = false ;
if ( ! ( F_44 ( V_24 ) == 0 &&
V_24 -> V_177 ) ) {
F_8 ( L_34 L_35 , V_2 , V_2 -> V_114 , V_2 -> V_115 ) ;
F_8 ( L_46 L_37 , V_2 , V_2 -> V_88 , V_2 -> V_135 ) ;
F_8 ( L_47 , V_2 ) ;
return false ;
}
if ( V_77 . V_141 )
F_12 ( L_48 , V_2 , V_2 -> V_88 ) ;
return true ;
}
V_57 . V_65 = F_19 ( V_2 ) ;
V_59 . V_65 = F_22 ( V_2 ) ;
V_175 . V_65 = F_45 ( V_2 ) ;
if ( V_77 . V_141 )
F_12 ( L_49 L_50 , V_2 , V_2 -> V_88 , V_57 . V_65 , V_59 . V_65 , V_175 . V_65 ) ;
if ( V_57 . V_65 == 0 || V_57 . V_66 . V_86 ||
V_57 . V_66 . V_68 || V_57 . V_66 . V_84 ||
V_57 . V_66 . V_76 || V_59 . V_72 . V_84 != 0 )
return false ;
if ( V_175 . V_65 == 0xFF )
return false ;
return true ;
}
static bool F_46 ( struct V_1 * V_2 , bool V_178 )
{
union V_56 V_57 ;
int V_63 ;
if ( F_5 ( V_2 ) ) {
struct V_176 * V_24 = & V_2 -> V_24 ;
V_24 -> V_179 = ! V_178 ;
V_24 -> V_180 = true ;
V_2 -> V_181 =
F_47 ( V_24 ) ;
if ( V_2 -> V_181 == ( void * ) V_182 )
return false ;
return true ;
}
if ( V_178 )
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
if ( V_77 . V_183 )
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
if ( V_77 . V_183 )
F_12 ( L_53 L_52 , V_2 , V_2 -> V_88 , V_57 . V_65 ) ;
if ( V_63 < 0 )
return false ;
V_63 = 10000 ;
while ( -- V_63 >= 0 ) {
V_57 . V_65 = F_19 ( V_2 ) ;
if ( V_57 . V_66 . V_87 || V_57 . V_66 . V_67 ||
V_57 . V_66 . V_74 )
break;
F_20 ( 100 ) ;
}
if ( V_77 . V_183 )
F_12 ( L_54 L_52 , V_2 , V_2 -> V_88 , V_57 . V_65 ) ;
if ( V_63 < 0 )
return false ;
if ( V_57 . V_66 . V_87 || ! V_57 . V_66 . V_67 ) {
V_69 = NULL ;
F_42 ( V_2 , L_55 ) ;
F_8 ( L_56 , V_2 ,
V_57 . V_65 ) ;
if ( V_57 . V_66 . V_74 )
F_8 ( L_57 , V_2 ,
F_23 ( V_2 ) ) ;
return false ;
}
return true ;
}
static bool T_2 F_49 ( struct V_1 * V_2 )
{
struct V_184 V_185 ;
unsigned char V_186 ;
bool V_62 = true ;
if ( F_5 ( V_2 ) )
return true ;
V_186 = sizeof( V_185 ) ;
if ( F_17 ( V_2 , V_187 , & V_186 ,
sizeof( V_186 ) , & V_185 ,
sizeof( V_185 ) ) != sizeof( V_185 ) )
V_62 = false ;
if ( V_77 . V_141 )
F_12 ( L_58 , V_2 ,
V_2 -> V_88 ,
( V_62 ? L_59 : L_60 ) ) ;
return V_62 ;
}
static bool T_2 F_50 ( struct V_1 * V_2 )
{
struct V_149 V_150 ;
struct V_188 V_189 ;
struct V_190 V_191 ;
struct V_184 V_185 ;
unsigned char V_192 [ 5 ] ;
unsigned char V_193 ;
unsigned char V_194 ;
struct V_127 V_128 ;
struct V_145 V_146 ;
struct V_195 V_196 ;
union V_174 V_175 ;
unsigned char V_186 ;
unsigned char * V_197 , V_198 ;
int V_199 , V_83 ;
if ( F_5 ( V_2 ) ) {
struct V_176 * V_24 = & V_2 -> V_24 ;
V_197 = V_2 -> V_192 ;
* V_197 ++ = 'B' ;
* V_197 ++ = 'T' ;
* V_197 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_24 -> V_192 ) ; V_83 ++ )
* V_197 ++ = V_24 -> V_192 [ V_83 ] ;
* V_197 ++ = '\0' ;
strcpy ( V_2 -> V_200 , V_201 ) ;
V_2 -> V_202 = V_24 -> V_202 ;
V_2 -> V_203 = V_24 -> V_203 ;
V_2 -> V_204 = V_24 -> V_204 ;
V_2 -> V_205 = ! V_24 -> V_179 ;
V_2 -> V_206 = true ;
V_2 -> V_207 = V_24 -> V_207 ;
V_2 -> V_208 = false ;
V_2 -> V_209 = true ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = true ;
V_2 -> V_213 = V_24 -> V_213 ;
V_2 -> V_214 = V_24 -> V_214 ;
V_2 -> V_215 = V_24 -> V_215 ;
V_2 -> V_216 = V_24 -> V_216 ;
V_2 -> V_217 = V_218 ;
V_2 -> V_219 = ( V_2 -> V_207 ? 16 : 8 ) ;
V_2 -> V_220 = 32 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_38 = 255 ;
V_2 -> V_221 = V_2 -> V_38 ;
V_2 -> V_222 = V_24 -> V_222 ;
V_2 -> V_223 = V_24 -> V_223 ;
V_2 -> V_224 = V_24 -> V_224 ;
V_2 -> V_225 = V_24 -> V_225 ;
V_2 -> V_226 = V_24 -> V_226 ;
V_2 -> V_227 = 0xFFFF ;
goto V_228;
}
if ( F_17 ( V_2 , V_153 , NULL , 0 , & V_150 ,
sizeof( V_150 ) ) != sizeof( V_150 ) )
return F_42 ( V_2 , L_61 ) ;
if ( F_17 ( V_2 , V_229 , NULL , 0 , & V_189 ,
sizeof( V_189 ) )
!= sizeof( V_189 ) )
return F_42 ( V_2 , L_62 ) ;
V_186 = sizeof( V_191 ) ;
if ( F_17 ( V_2 , V_230 , & V_186 ,
sizeof( V_186 ) , & V_191 ,
sizeof( V_191 ) ) != sizeof( V_191 ) )
return F_42 ( V_2 , L_63 ) ;
V_186 = sizeof( V_185 ) ;
if ( F_17 ( V_2 , V_187 , & V_186 ,
sizeof( V_186 ) , & V_185 ,
sizeof( V_185 ) ) != sizeof( V_185 ) )
return F_42 ( V_2 ,
L_64 ) ;
V_193 = '\0' ;
if ( V_150 . V_154 > '0' )
if ( F_17 ( V_2 , V_231 , NULL , 0 ,
& V_193 ,
sizeof( V_193 ) ) != sizeof( V_193 ) )
return F_42 ( V_2 ,
L_65 ) ;
if ( V_185 . V_232 == 'A' && V_150 . V_154 == '2' )
strcpy ( V_192 , L_66 ) ;
else if ( V_185 . V_232 == 'E' && V_150 . V_154 == '2' &&
( V_150 . V_233 <= '1' || ( V_150 . V_233 == '2' &&
V_193 == '0' ) ) )
strcpy ( V_192 , L_67 ) ;
else if ( V_185 . V_232 == 'E' && V_150 . V_154 == '0' )
strcpy ( V_192 , L_68 ) ;
else {
V_186 = sizeof( V_192 ) ;
if ( F_17 ( V_2 , V_234 , & V_186 ,
sizeof( V_186 ) , & V_192 ,
sizeof( V_192 ) ) != sizeof( V_192 ) )
return F_42 ( V_2 ,
L_69 ) ;
}
V_197 = V_2 -> V_192 ;
* V_197 ++ = 'B' ;
* V_197 ++ = 'T' ;
* V_197 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_192 ) ; V_83 ++ ) {
V_198 = V_192 [ V_83 ] ;
if ( V_198 == ' ' || V_198 == '\0' )
break;
* V_197 ++ = V_198 ;
}
* V_197 ++ = '\0' ;
V_197 = V_2 -> V_200 ;
* V_197 ++ = V_150 . V_154 ;
* V_197 ++ = '.' ;
* V_197 ++ = V_150 . V_233 ;
if ( V_193 != ' ' && V_193 != '\0' )
* V_197 ++ = V_193 ;
* V_197 = '\0' ;
if ( strcmp ( V_2 -> V_200 , L_70 ) >= 0 ) {
if ( F_17 ( V_2 , V_235 , NULL , 0 ,
& V_194 ,
sizeof( V_194 ) ) != sizeof( V_194 ) )
return F_42 ( V_2 ,
L_71 ) ;
if ( V_194 != ' ' && V_194 != '\0' )
* V_197 ++ = V_194 ;
* V_197 = '\0' ;
}
V_2 -> V_202 = V_189 . V_150 ;
V_2 -> V_96 =
V_236 [ V_2 -> V_192 [ 3 ] - '4' ] ;
if ( V_2 -> V_132 == 0 ) {
if ( V_189 . V_237 )
V_2 -> V_132 = 9 ;
else if ( V_189 . V_238 )
V_2 -> V_132 = 10 ;
else if ( V_189 . V_239 )
V_2 -> V_132 = 11 ;
else if ( V_189 . V_240 )
V_2 -> V_132 = 12 ;
else if ( V_189 . V_241 )
V_2 -> V_132 = 14 ;
else if ( V_189 . V_242 )
V_2 -> V_132 = 15 ;
}
if ( V_2 -> V_96 == V_97 ) {
if ( V_189 . V_243 )
V_2 -> V_244 = 5 ;
else if ( V_189 . V_245 )
V_2 -> V_244 = 6 ;
else if ( V_189 . V_246 )
V_2 -> V_244 = 7 ;
}
V_175 . V_65 = F_45 ( V_2 ) ;
V_2 -> V_203 = V_175 . V_247 . V_203 ;
V_2 -> V_248 = V_185 . V_249 ;
V_2 -> V_217 = V_2 -> V_248 ;
if ( V_2 -> V_248 > V_218 )
V_2 -> V_217 = V_218 ;
if ( V_185 . V_250 . V_206 )
V_2 -> V_206 = true ;
V_2 -> V_207 = V_185 . V_207 ;
V_2 -> V_208 = V_185 . V_208 ;
V_2 -> V_209 = V_185 . V_209 ;
V_2 -> V_210 = V_185 . V_210 ;
if ( V_2 -> V_200 [ 0 ] == '5' || ( V_2 -> V_200 [ 0 ] == '4' &&
V_2 -> V_207 ) )
V_2 -> V_211 = true ;
if ( V_2 -> V_200 [ 0 ] == '5' ) {
if ( F_17 ( V_2 , V_142 , NULL , 0 ,
& V_128 ,
sizeof( V_128 ) ) != sizeof( V_128 ) )
return F_42 ( V_2 ,
L_72 ) ;
if ( V_128 . V_251 ) {
V_2 -> V_212 = true ;
V_2 -> V_213 = V_128 . V_213 ;
V_2 -> V_214 = V_128 . V_214 ;
}
}
if ( V_2 -> V_200 [ 0 ] >= '4' ) {
V_146 . V_14 = V_151 ;
V_146 . V_152 = sizeof( V_196 ) ;
if ( F_17 ( V_2 , V_82 , & V_146 ,
sizeof( V_146 ) , & V_196 ,
sizeof( V_196 ) ) != sizeof( V_196 ) )
return F_42 ( V_2 ,
L_73 ) ;
V_2 -> V_204 = V_196 . V_204 ;
V_2 -> V_205 = V_196 . V_205 ;
if ( V_2 -> V_200 [ 0 ] == '4' ) {
V_2 -> V_212 = true ;
V_2 -> V_213 = V_196 . V_213 ;
V_2 -> V_214 = V_196 . V_214 ;
}
V_2 -> V_225 = V_196 . V_225 ;
V_2 -> V_223 = V_196 . V_223 ;
V_2 -> V_222 = V_196 . V_222 ;
V_2 -> V_226 = V_196 . V_226 ;
if ( V_2 -> V_210 )
V_2 -> V_224 = V_196 . V_224 ;
if ( V_2 -> V_209 ) {
V_2 -> V_215 = V_196 . V_215 ;
V_2 -> V_216 = V_196 . V_216 ;
}
}
if ( V_2 -> V_200 [ 0 ] < '4' ) {
if ( V_191 . V_252 ) {
V_2 -> V_222 = 0xFF ;
if ( V_2 -> V_96 == V_253 ) {
if ( V_185 . V_250 . V_254 )
V_2 -> V_223 = 0xFF ;
if ( strcmp ( V_2 -> V_192 , L_74 ) == 0 )
V_2 -> V_225 = 0xFF ;
}
}
V_2 -> V_226 = 0xFF ;
V_2 -> V_204 = V_191 . V_204 ;
V_2 -> V_205 = true ;
}
V_2 -> V_219 = ( V_2 -> V_207 ? 16 : 8 ) ;
V_2 -> V_220 = ( V_2 -> V_211 ? 32 : 8 ) ;
if ( V_2 -> V_200 [ 0 ] == '5' )
V_2 -> V_221 = 192 ;
else if ( V_2 -> V_200 [ 0 ] == '4' )
V_2 -> V_221 = ( V_2 -> V_96 !=
V_97 ? 100 : 50 ) ;
else
V_2 -> V_221 = 30 ;
if ( strcmp ( V_2 -> V_200 , L_75 ) >= 0 ) {
V_2 -> V_255 = true ;
V_2 -> V_256 = V_257 ;
} else {
V_2 -> V_255 = false ;
V_2 -> V_256 = 32 ;
}
V_2 -> V_38 = V_2 -> V_256 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_227 = 0 ;
switch ( V_2 -> V_200 [ 0 ] ) {
case '5' :
V_2 -> V_227 = 0xFFFF ;
break;
case '4' :
if ( strcmp ( V_2 -> V_200 , L_76 ) >= 0 )
V_2 -> V_227 = 0xFFFF ;
break;
case '3' :
if ( strcmp ( V_2 -> V_200 , L_77 ) >= 0 )
V_2 -> V_227 = 0xFFFF ;
break;
}
V_2 -> V_258 = V_185 . V_258 << 12 ;
if ( V_2 -> V_96 == V_97 &&
( void * ) V_259 > ( void * ) V_260 )
V_2 -> V_261 = true ;
if ( V_2 -> V_258 > 0 && strcmp ( V_2 -> V_192 , L_78 ) == 0 &&
strcmp ( V_2 -> V_200 , L_79 ) < 0 &&
( void * ) V_259 > ( void * ) V_260 )
V_2 -> V_261 = true ;
V_228:
strcpy ( V_2 -> V_8 , L_80 ) ;
strcat ( V_2 -> V_8 , V_2 -> V_192 ) ;
for ( V_199 = 0 ; V_199 < V_262 ; V_199 ++ ) {
unsigned char V_263 = 0 ;
if ( V_2 -> V_264 != NULL &&
V_2 -> V_264 -> V_263 [ V_199 ] > 0 )
V_263 = V_2 -> V_264 -> V_263 [ V_199 ] ;
else if ( V_2 -> V_261 )
V_263 = V_265 ;
V_2 -> V_263 [ V_199 ] = V_263 ;
}
if ( V_2 -> V_261 )
V_2 -> V_266 = V_267 ;
else
V_2 -> V_266 = V_268 ;
if ( V_2 -> V_264 != NULL )
V_2 -> V_269 = V_2 -> V_264 -> V_269 ;
if ( V_2 -> V_269 > 0 &&
V_2 -> V_269 < V_2 -> V_266 )
V_2 -> V_266 = V_2 -> V_269 ;
V_2 -> V_227 &= V_2 -> V_226 ;
if ( V_2 -> V_264 != NULL )
V_2 -> V_227 = ( V_2 -> V_264 -> V_227 &
V_2 -> V_264 -> V_270 ) |
( V_2 -> V_227 & ~ V_2 -> V_264 -> V_270 ) ;
if ( V_2 -> V_264 != NULL &&
V_2 -> V_264 -> V_271 > 0 )
V_2 -> V_271 = V_2 -> V_264 -> V_271 ;
else
V_2 -> V_271 = V_272 ;
return true ;
}
static bool T_2 F_51 ( struct V_1 * V_2 )
{
unsigned short V_273 = ( 1 << V_2 -> V_219 ) - 1 ;
unsigned short V_222 , V_223 ;
unsigned short V_224 , V_225 ;
unsigned short V_226 , V_227 ;
bool V_274 , V_275 ;
char V_276 [ V_262 + 1 ] ;
char V_277 [ V_262 + 1 ] ;
char V_278 [ V_262 + 1 ] ;
char V_279 [ V_262 + 1 ] ;
char * V_280 = V_276 ;
char * V_281 = V_277 ;
char * V_282 = V_278 ;
char * V_283 = V_279 ;
int V_199 ;
F_52 ( L_81 , V_2 , V_2 -> V_192 , V_284 [ V_2 -> V_96 ] , ( V_2 -> V_207 ? L_82 : L_83 ) , ( V_2 -> V_208 ? L_84 : L_83 ) , ( V_2 -> V_210 ? L_85 : L_83 ) ) ;
F_52 ( L_86 L_87 , V_2 , V_2 -> V_200 , V_2 -> V_88 , V_2 -> V_132 , ( V_2 -> V_206 ? L_88 : L_89 ) ) ;
if ( V_2 -> V_96 != V_156 ) {
F_52 ( L_90 , V_2 ) ;
if ( V_2 -> V_244 > 0 )
F_52 ( L_91 , V_2 , V_2 -> V_244 ) ;
else
F_52 ( L_92 , V_2 ) ;
if ( V_2 -> V_258 > 0 )
F_52 ( L_93 , V_2 ,
V_2 -> V_258 ) ;
else
F_52 ( L_94 , V_2 ) ;
} else {
F_52 ( L_95 , V_2 ,
V_2 -> V_114 , V_2 -> V_115 ) ;
if ( V_2 -> V_135 > 0 )
F_52 ( L_96 , V_2 , V_2 -> V_135 ) ;
else
F_52 ( L_97 , V_2 ) ;
}
F_52 ( L_98 , V_2 , V_2 -> V_202 ) ;
F_52 ( L_99 ,
V_2 , ( V_2 -> V_204 ? L_100 : L_101 ) ,
( V_2 -> V_203 ? L_100 : L_101 ) ) ;
V_273 &= ~ ( 1 << V_2 -> V_202 ) ;
V_222 = V_2 -> V_222 & V_273 ;
V_223 = V_2 -> V_223 & V_273 ;
V_224 = V_2 -> V_224 & V_273 ;
if ( ( F_53 ( V_2 ) &&
( V_2 -> V_200 [ 0 ] >= '4' ||
V_2 -> V_96 == V_253 ) ) ||
F_5 ( V_2 ) ) {
V_274 = false ;
if ( V_222 == 0 ) {
V_280 = L_101 ;
V_274 = true ;
} else if ( V_222 == V_273 ) {
if ( V_223 == 0 ) {
V_280 = L_102 ;
V_274 = true ;
} else if ( V_223 == V_273 ) {
if ( V_224 == 0 ) {
V_280 = L_103 ;
V_274 = true ;
} else if ( V_224 == V_273 ) {
V_280 = L_104 ;
V_274 = true ;
}
}
}
if ( ! V_274 ) {
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_276 [ V_199 ] = ( ( ! ( V_222 & ( 1 << V_199 ) ) ) ? 'N' : ( ! ( V_223 & ( 1 << V_199 ) ) ? 'S' : ( ! ( V_224 & ( 1 << V_199 ) ) ? 'F' : 'U' ) ) ) ;
V_276 [ V_2 -> V_202 ] = '#' ;
V_276 [ V_2 -> V_219 ] = '\0' ;
}
} else
V_280 = ( V_222 == 0 ? L_101 : L_100 ) ;
V_225 = V_2 -> V_225 & V_273 ;
if ( V_225 == 0 )
V_281 = L_101 ;
else if ( V_225 == V_273 )
V_281 = L_100 ;
else {
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_277 [ V_199 ] = ( ( V_225 & ( 1 << V_199 ) ) ? 'Y' : 'N' ) ;
V_277 [ V_2 -> V_202 ] = '#' ;
V_277 [ V_2 -> V_219 ] = '\0' ;
}
V_226 = V_2 -> V_226 & V_273 ;
if ( V_226 == 0 )
V_282 = L_101 ;
else if ( V_226 == V_273 )
V_282 = L_100 ;
else {
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_278 [ V_199 ] = ( ( V_226 & ( 1 << V_199 ) ) ? 'Y' : 'N' ) ;
V_278 [ V_2 -> V_202 ] = '#' ;
V_278 [ V_2 -> V_219 ] = '\0' ;
}
V_227 = V_2 -> V_227 & V_273 ;
if ( V_227 == 0 )
V_283 = L_101 ;
else if ( V_227 == V_273 )
V_283 = L_100 ;
else {
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_279 [ V_199 ] = ( ( V_227 & ( 1 << V_199 ) ) ? 'Y' : 'N' ) ;
V_279 [ V_2 -> V_202 ] = '#' ;
V_279 [ V_2 -> V_219 ] = '\0' ;
}
F_52 ( L_105 ,
V_2 , V_280 , V_281 ) ;
F_52 ( L_106 , V_2 ,
V_282 , V_283 ) ;
if ( F_53 ( V_2 ) ) {
F_52 ( L_107 L_108 , V_2 , V_2 -> V_217 , V_2 -> V_248 , V_2 -> V_256 ) ;
F_52 ( L_109 L_110 , V_2 , V_2 -> V_38 , V_2 -> V_221 ) ;
} else
F_52 ( L_109 L_111 , V_2 , V_2 -> V_38 , V_2 -> V_217 ) ;
F_52 ( L_112 , V_2 ) ;
V_275 = true ;
for ( V_199 = 1 ; V_199 < V_2 -> V_219 ; V_199 ++ )
if ( V_2 -> V_263 [ V_199 ] != V_2 -> V_263 [ 0 ] ) {
V_275 = false ;
break;
}
if ( V_275 ) {
if ( V_2 -> V_263 [ 0 ] > 0 )
F_52 ( L_113 , V_2 , V_2 -> V_263 [ 0 ] ) ;
else
F_52 ( L_114 , V_2 ) ;
} else
F_52 ( L_115 , V_2 ) ;
F_52 ( L_116 , V_2 ,
V_2 -> V_266 ) ;
if ( V_2 -> V_212 ) {
if ( V_2 -> V_207 )
F_52 ( L_117 , V_2 ,
( V_2 -> V_213 ? ( V_2 -> V_214 ? L_118 : L_119 ) : ( V_2 -> V_214 ? L_120 : L_121 ) ) ) ;
else
F_52 ( L_117 , V_2 ,
( V_2 -> V_213 ? L_100 : L_101 ) ) ;
if ( V_2 -> V_209 )
F_52 ( L_122 , V_2 ,
( V_2 -> V_215 ? ( V_2 -> V_216 ? L_123 : L_124 ) : L_101 ) ) ;
F_52 ( L_17 , V_2 ) ;
}
return true ;
}
static bool T_2 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_132 == 0 ) {
F_8 ( L_125 ,
V_2 ) ;
return false ;
}
if ( F_55 ( V_2 -> V_132 , V_285 , V_286 ,
V_2 -> V_8 , V_2 ) < 0 ) {
F_8 ( L_126 ,
V_2 , V_2 -> V_132 ) ;
return false ;
}
V_2 -> V_64 = true ;
if ( V_2 -> V_244 > 0 ) {
if ( F_56 ( V_2 -> V_244 , V_2 -> V_8 ) < 0 ) {
F_8 ( L_127 , V_2 , V_2 -> V_244 ) ;
return false ;
}
F_57 ( V_2 -> V_244 , V_287 ) ;
F_58 ( V_2 -> V_244 ) ;
V_2 -> V_288 = true ;
}
return true ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_60 ( V_2 -> V_132 , V_2 ) ;
if ( V_2 -> V_288 )
F_61 ( V_2 -> V_244 ) ;
if ( V_2 -> V_289 )
F_10 ( V_2 -> V_32 , V_2 -> V_290 ,
V_2 -> V_289 , V_2 -> V_291 ) ;
F_62 ( V_2 -> V_32 ) ;
V_2 -> V_289 = NULL ;
V_2 -> V_291 = 0 ;
V_2 -> V_290 = 0 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_292 V_293 ;
enum V_294 V_295 ;
enum V_296 V_297 ;
int V_199 ;
V_2 -> V_298 = NULL ;
V_2 -> V_34 = NULL ;
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ ) {
V_2 -> V_299 [ V_199 ] = NULL ;
V_2 -> V_300 [ V_199 ] . V_301 = false ;
V_2 -> V_300 [ V_199 ] . V_302 = false ;
V_2 -> V_303 [ V_199 ] = 0 ;
V_2 -> V_304 [ V_199 ] = 0 ;
}
if ( F_5 ( V_2 ) )
goto V_70;
V_2 -> V_290 = V_2 -> V_256 * ( sizeof( struct V_305 ) + sizeof( struct V_306 ) ) ;
V_2 -> V_289 = F_7 ( V_2 -> V_32 ,
V_2 -> V_290 , & V_2 -> V_291 ) ;
if ( V_2 -> V_289 == NULL )
return F_42 ( V_2 , L_128 ) ;
V_2 -> V_307 = (struct V_305 * ) V_2 -> V_289 ;
V_2 -> V_308 = V_2 -> V_307 + V_2 -> V_256 - 1 ;
V_2 -> V_309 = V_2 -> V_307 ;
V_2 -> V_310 = (struct V_306 * ) ( V_2 -> V_308 + 1 ) ;
V_2 -> V_311 = V_2 -> V_310 + V_2 -> V_256 - 1 ;
V_2 -> V_312 = V_2 -> V_310 ;
memset ( V_2 -> V_307 , 0 ,
V_2 -> V_256 * sizeof( struct V_305 ) ) ;
memset ( V_2 -> V_310 , 0 ,
V_2 -> V_256 * sizeof( struct V_306 ) ) ;
V_293 . V_256 = V_2 -> V_256 ;
V_293 . V_313 = ( V_20 ) V_2 -> V_291 ;
if ( F_17 ( V_2 , V_314 , & V_293 ,
sizeof( V_293 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_129 ) ;
if ( V_2 -> V_255 ) {
V_295 = V_315 ;
if ( F_17 ( V_2 , V_316 , & V_295 ,
sizeof( V_295 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 ,
L_130 ) ;
}
if ( V_2 -> V_211 ) {
V_297 = V_317 ;
if ( F_17 ( V_2 , V_318 , & V_297 ,
sizeof( V_297 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_131 ) ;
}
V_70:
if ( ! V_2 -> V_319 ) {
F_52 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
F_52 ( L_17 , V_2 ) ;
} else
F_38 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
V_2 -> V_319 = true ;
return true ;
}
static bool T_2 F_64 ( struct V_1 * V_2 )
{
T_3 V_320 ;
T_4 V_321 [ 8 ] ;
struct V_190 V_191 ;
T_4 V_322 [ V_262 ] ;
unsigned char V_186 ;
int V_199 ;
F_65 ( V_2 -> V_271 ) ;
if ( F_5 ( V_2 ) )
return true ;
if ( V_2 -> V_264 != NULL && V_2 -> V_264 -> V_323 )
return true ;
if ( strcmp ( V_2 -> V_200 , L_133 ) >= 0 ) {
if ( F_17 ( V_2 , V_81 , NULL , 0 ,
& V_320 , sizeof( V_320 ) )
!= sizeof( V_320 ) )
return F_42 ( V_2 , L_134 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_2 -> V_300 [ V_199 ] . V_324 =
( V_320 & ( 1 << V_199 ) ? true : false ) ;
} else {
if ( F_17 ( V_2 , V_79 , NULL , 0 ,
& V_321 , sizeof( V_321 ) )
!= sizeof( V_321 ) )
return F_42 ( V_2 ,
L_135 ) ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ )
V_2 -> V_300 [ V_199 ] . V_324 =
( V_321 [ V_199 ] != 0 ? true : false ) ;
}
V_186 = sizeof( V_191 ) ;
if ( F_17 ( V_2 , V_230 , & V_186 ,
sizeof( V_186 ) , & V_191 , sizeof( V_191 ) )
!= sizeof( V_191 ) )
return F_42 ( V_2 , L_63 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_2 -> V_325 [ V_199 ] = ( V_199 < 8 ? V_191 . V_326 [ V_199 ] . V_14 : V_191 . V_327 [ V_199 - 8 ] . V_14 ) ;
if ( strcmp ( V_2 -> V_200 , L_136 ) >= 0 )
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_2 -> V_300 [ V_199 ] . V_328 = ( V_199 < 8 ? ( V_191 . V_329 & ( 1 << V_199 ) ? true : false ) : ( V_191 . V_330 & ( 1 << ( V_199 - 8 ) ) ? true : false ) ) ;
if ( V_2 -> V_200 [ 0 ] >= '3' ) {
V_186 = sizeof( V_322 ) ;
if ( F_17 ( V_2 , V_331 , & V_186 ,
sizeof( V_186 ) , & V_322 ,
sizeof( V_322 ) ) != sizeof( V_322 ) )
return F_42 ( V_2 ,
L_137 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
V_2 -> V_322 [ V_199 ] = V_322 [ V_199 ] ;
} else
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
if ( V_191 . V_326 [ V_199 ] . V_14 > 0 )
V_2 -> V_322 [ V_199 ] = 20 + 5 * V_191 . V_326 [ V_199 ] . V_332 ;
return true ;
}
static void T_2 F_66 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
V_6 -> V_333 = V_2 -> V_219 ;
V_6 -> V_334 = V_2 -> V_220 ;
V_6 -> V_335 = 0 ;
V_6 -> V_336 = V_2 -> V_88 ;
V_6 -> V_337 = V_2 -> V_202 ;
V_6 -> V_41 = V_2 -> V_38 ;
V_6 -> V_338 = V_2 -> V_217 ;
V_6 -> V_339 = V_2 -> V_261 ;
V_6 -> V_340 = V_2 -> V_266 ;
}
static int F_67 ( struct V_341 * V_115 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_115 -> V_6 -> V_7 ;
int V_199 = V_115 -> V_150 ;
int V_263 = V_2 -> V_263 [ V_199 ] ;
if ( V_2 -> V_300 [ V_199 ] . V_227 &&
( V_2 -> V_227 & ( 1 << V_199 ) ) ) {
if ( V_263 == 0 )
V_263 = V_342 ;
V_2 -> V_263 [ V_199 ] = V_263 ;
F_68 ( V_115 , V_343 , V_263 ) ;
} else {
V_2 -> V_227 &= ~ ( 1 << V_199 ) ;
V_263 = V_2 -> V_266 ;
V_2 -> V_263 [ V_199 ] = V_263 ;
F_68 ( V_115 , 0 , V_263 ) ;
}
V_263 = 0 ;
for ( V_199 = 0 ; V_199 < V_2 -> V_219 ; V_199 ++ )
if ( V_2 -> V_300 [ V_199 ] . V_324 )
V_263 += V_2 -> V_263 [ V_199 ] ;
if ( V_263 > V_2 -> V_29 )
F_11 ( V_2 , V_263 - V_2 -> V_29 ,
false ) ;
return 0 ;
}
static int T_2 F_69 ( void )
{
int V_344 = 0 , V_345 = 0 , V_346 ;
struct V_1 * V_2 ;
int V_347 = 0 ;
#ifdef F_70
if ( V_348 )
F_71 ( V_348 ) ;
#endif
if ( V_98 . V_349 )
return - V_350 ;
V_93 =
F_72 ( V_92 * sizeof( struct V_89 ) ,
V_351 ) ;
if ( V_93 == NULL ) {
F_8 ( L_138 ,
NULL ) ;
return - V_352 ;
}
V_2 = F_72 ( sizeof( struct V_1 ) , V_351 ) ;
if ( V_2 == NULL ) {
F_73 ( V_93 ) ;
F_8 ( L_139 , NULL ) ;
return - V_352 ;
}
#ifdef F_70
if ( V_348 != NULL )
F_71 ( V_348 ) ;
#endif
F_41 ( V_2 ) ;
for ( V_346 = 0 ; V_346 < V_91 ; V_346 ++ ) {
struct V_89 * V_90 =
& V_93 [ V_346 ] ;
struct V_1 * V_165 = V_2 ;
struct V_5 * V_6 ;
if ( V_90 -> V_88 == 0 )
continue;
memset ( V_165 , 0 , sizeof( struct V_1 ) ) ;
V_165 -> V_94 = V_90 -> V_94 ;
V_165 -> V_96 = V_90 -> V_96 ;
V_165 -> V_88 = V_90 -> V_88 ;
V_165 -> V_135 = V_90 -> V_135 ;
V_165 -> V_114 = V_90 -> V_114 ;
V_165 -> V_115 = V_90 -> V_115 ;
V_165 -> V_32 = V_90 -> V_32 ;
V_165 -> V_132 = V_90 -> V_132 ;
V_165 -> V_353 =
V_354 [ V_165 -> V_94 ] ;
if ( ! F_74 ( V_165 -> V_88 , V_165 -> V_353 ,
L_140 ) )
continue;
if ( ! F_43 ( V_165 ) ) {
F_75 ( V_165 -> V_88 ,
V_165 -> V_353 ) ;
continue;
}
if ( ! F_46 ( V_165 , true ) ) {
F_75 ( V_165 -> V_88 ,
V_165 -> V_353 ) ;
continue;
}
if ( ! F_49 ( V_165 ) ) {
F_75 ( V_165 -> V_88 ,
V_165 -> V_353 ) ;
continue;
}
if ( V_345 < V_355 )
V_165 -> V_264 =
& V_356 [ V_345 ++ ] ;
F_1 ( V_165 ) ;
V_6 = F_76 ( & V_357 ,
sizeof( struct V_1 ) ) ;
if ( V_6 == NULL ) {
F_75 ( V_165 -> V_88 ,
V_165 -> V_353 ) ;
continue;
}
V_165 = (struct V_1 * ) V_6 -> V_7 ;
memcpy ( V_165 , V_2 , sizeof( struct V_1 ) ) ;
V_165 -> V_40 = V_6 ;
V_165 -> V_358 = V_6 -> V_358 ;
F_77 ( & V_165 -> V_359 , & V_360 ) ;
if ( F_50 ( V_165 ) &&
F_51 ( V_165 ) &&
F_54 ( V_165 ) &&
F_6 ( V_165 ) &&
F_63 ( V_165 ) &&
F_64 ( V_165 ) ) {
F_75 ( V_165 -> V_88 ,
V_165 -> V_353 ) ;
if ( ! F_74 ( V_165 -> V_88 ,
V_165 -> V_353 ,
V_165 -> V_8 ) ) {
F_78 ( V_361
L_141
L_142 ,
( unsigned long ) V_165 -> V_88 ) ;
F_9 ( V_165 ) ;
F_59 ( V_165 ) ;
F_79 ( & V_165 -> V_359 ) ;
F_80 ( V_6 ) ;
V_347 = - V_352 ;
} else {
F_66 ( V_165 ,
V_6 ) ;
if ( F_81 ( V_6 , V_165 -> V_32
? & V_165 -> V_32 -> V_115
: NULL ) ) {
F_78 ( V_361
L_143
L_144 ) ;
F_9 ( V_165 ) ;
F_59 ( V_165 ) ;
F_79 ( & V_165 -> V_359 ) ;
F_80 ( V_6 ) ;
V_347 = - V_350 ;
} else {
F_82 ( V_6 ) ;
V_344 ++ ;
}
}
} else {
F_9 ( V_165 ) ;
F_59 ( V_165 ) ;
F_79 ( & V_165 -> V_359 ) ;
F_80 ( V_6 ) ;
V_347 = - V_350 ;
}
}
F_73 ( V_2 ) ;
F_73 ( V_93 ) ;
V_93 = NULL ;
return V_347 ;
}
static int T_5 F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_40 ;
F_84 ( V_6 ) ;
if ( F_5 ( V_2 ) )
F_85 ( V_2 -> V_181 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_75 ( V_2 -> V_88 , V_2 -> V_353 ) ;
F_79 ( & V_2 -> V_359 ) ;
F_80 ( V_6 ) ;
return 0 ;
}
static void V_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
V_13 -> V_17 = V_362 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_298 == NULL ) {
V_2 -> V_298 = V_13 ;
V_2 -> V_34 = V_13 ;
} else {
V_2 -> V_34 -> V_25 = V_13 ;
V_2 -> V_34 = V_13 ;
}
V_2 -> V_303 [ V_13 -> V_199 ] -- ;
}
static int F_86 ( struct V_1 * V_2 ,
enum V_363 V_364 ,
enum V_365 V_366 )
{
int V_367 ;
switch ( V_364 ) {
case V_368 :
case V_369 :
case V_370 :
V_367 = V_371 ;
break;
case V_372 :
V_367 = V_373 ;
break;
case V_374 :
case V_375 :
case V_376 :
F_38 ( L_145 ,
V_2 , V_364 ) ;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
V_367 = V_390 ;
break;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
V_367 = V_396 ;
break;
default:
F_38 ( L_146 , V_2 ,
V_364 ) ;
V_367 = V_390 ;
break;
}
return ( V_367 << 16 ) | V_366 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_306 * V_312 = V_2 -> V_312 ;
enum V_397 V_398 ;
while ( ( V_398 = V_312 -> V_398 ) != V_399 ) {
struct V_12 * V_13 =
(struct V_12 * ) F_88 ( V_312 -> V_13 ) ;
if ( V_398 != V_400 ) {
if ( V_13 -> V_17 == V_401 ||
V_13 -> V_17 == V_402 ) {
V_13 -> V_398 = V_398 ;
V_22 ( V_13 ) ;
} else {
F_38 ( L_147 L_148 , V_2 , V_13 -> V_42 , V_13 -> V_17 ) ;
}
}
V_312 -> V_398 = V_399 ;
if ( ++ V_312 > V_2 -> V_311 )
V_312 = V_2 -> V_310 ;
}
V_2 -> V_312 = V_312 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_403 )
return;
V_2 -> V_403 = true ;
while ( V_2 -> V_298 != NULL ) {
struct V_12 * V_13 = V_2 -> V_298 ;
struct V_404 * V_44 = V_13 -> V_44 ;
V_2 -> V_298 = V_13 -> V_25 ;
if ( V_2 -> V_298 == NULL )
V_2 -> V_34 = NULL ;
if ( V_13 -> V_49 == V_405 ) {
int V_199 = V_13 -> V_199 ;
F_38 ( L_149 L_150 , V_2 , V_13 -> V_42 , V_199 ) ;
F_90 ( & V_2 -> V_406 [ V_199 ] . V_407 ) ;
V_2 -> V_300 [ V_199 ] . V_301 = false ;
V_2 -> V_304 [ V_199 ] = 0 ;
V_2 -> V_408 [ V_199 ] = V_409 ;
F_14 ( V_13 ) ;
#if 0
while (command != NULL) {
struct scsi_cmnd *nxt_cmd =
command->reset_chain;
command->reset_chain = NULL;
command->result = DID_RESET << 16;
command->scsi_done(command);
command = nxt_cmd;
}
#endif
for ( V_13 = V_2 -> V_28 ; V_13 != NULL ;
V_13 = V_13 -> V_27 )
if ( V_13 -> V_17 == V_402 &&
V_13 -> V_199 == V_199 ) {
V_44 = V_13 -> V_44 ;
F_14 ( V_13 ) ;
V_2 -> V_303 [ V_199 ] -- ;
V_44 -> V_62 = V_396 << 16 ;
V_44 -> V_410 ( V_44 ) ;
}
V_2 -> V_299 [ V_199 ] = NULL ;
} else {
switch ( V_13 -> V_398 ) {
case V_399 :
case V_400 :
case V_411 :
F_38 ( L_151 , V_2 , V_13 -> V_42 , V_13 -> V_199 ) ;
break;
case V_412 :
V_2 -> V_406 [ V_13 -> V_199 ]
. V_413 ++ ;
V_2 -> V_300 [ V_13 -> V_199 ]
. V_302 = true ;
V_44 -> V_62 = V_371 << 16 ;
break;
case V_414 :
F_38 ( L_152 ,
V_2 , V_13 -> V_42 , V_13 -> V_199 ) ;
F_90 ( & V_2 -> V_406 [ V_13 -> V_199 ] . V_415 ) ;
V_44 -> V_62 = V_416 << 16 ;
break;
case V_417 :
V_44 -> V_62 = F_86 ( V_2 ,
V_13 -> V_364 , V_13 -> V_366 ) ;
if ( V_13 -> V_364 != V_372 ) {
V_2 -> V_406 [ V_13 -> V_199 ]
. V_413 ++ ;
if ( V_77 . V_418 ) {
int V_83 ;
F_12 ( L_153
L_154 L_155 , V_2 , V_13 -> V_42 , V_13 -> V_199 , V_44 -> V_62 , V_13 -> V_364 , V_13 -> V_366 ) ;
F_12 ( L_156 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_419 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_13 -> V_420 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
F_12 ( L_157 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_46 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_44 -> V_421 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
}
break;
}
if ( V_13 -> V_420 [ 0 ] == V_422 && V_13 -> V_420 [ 1 ] == 0 &&
V_13 -> V_364 == V_368 ) {
struct V_423 * V_300 =
& V_2 -> V_300 [ V_13 -> V_199 ] ;
struct V_424 * V_425 =
(struct V_424 * ) F_91 ( V_44 ) ;
V_300 -> V_324 = true ;
V_300 -> V_227 = V_425 -> V_426 ;
V_300 -> V_225 = V_425 -> V_427 ;
}
F_14 ( V_13 ) ;
V_44 -> V_410 ( V_44 ) ;
}
}
V_2 -> V_403 = false ;
}
static T_6 V_285 ( int V_132 , void * V_428 )
{
struct V_1 * V_2 = (struct V_1 * ) V_428 ;
unsigned long V_60 ;
F_92 ( V_2 -> V_40 -> V_429 , V_60 ) ;
if ( F_53 ( V_2 ) ) {
union V_58 V_59 ;
V_59 . V_65 = F_22 ( V_2 ) ;
if ( V_59 . V_72 . V_430 ) {
F_24 ( V_2 ) ;
if ( V_59 . V_72 . V_431 )
V_2 -> V_432 = true ;
else if ( V_59 . V_72 . V_433 )
F_87 ( V_2 ) ;
else if ( V_59 . V_72 . V_73 )
V_2 -> V_71 = true ;
}
} else {
if ( F_93 ( V_2 -> V_181 ) )
switch ( F_94 ( V_2 -> V_181 ) ) {
case V_434 :
break;
case V_435 :
V_2 -> V_432 = true ;
break;
case V_436 :
F_38 ( L_158 , V_2 ) ;
V_2 -> V_437 = true ;
break;
}
}
if ( V_2 -> V_298 != NULL )
F_89 ( V_2 ) ;
if ( V_2 -> V_432 ) {
F_38 ( L_159 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_438 ) ;
F_95 ( V_2 , false ) ;
V_2 -> V_432 = false ;
} else if ( V_2 -> V_437 ) {
F_38 ( L_160 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_439 ) ;
F_95 ( V_2 , true ) ;
V_2 -> V_437 = false ;
}
F_96 ( V_2 -> V_40 -> V_429 , V_60 ) ;
return V_440 ;
}
static bool F_97 ( struct V_1 * V_2 ,
enum V_441 V_442 , struct V_12 * V_13 )
{
struct V_305 * V_309 ;
V_309 = V_2 -> V_309 ;
if ( V_309 -> V_442 == V_443 ) {
V_13 -> V_17 = V_401 ;
V_309 -> V_13 = V_13 -> V_19 ;
V_309 -> V_442 = V_442 ;
F_98 ( V_2 ) ;
if ( ++ V_309 > V_2 -> V_308 )
V_309 = V_2 -> V_307 ;
V_2 -> V_309 = V_309 ;
if ( V_442 == V_444 ) {
V_2 -> V_303 [ V_13 -> V_199 ] ++ ;
if ( V_13 -> V_49 != V_405 )
V_2 -> V_406 [ V_13 -> V_199 ] . V_445 ++ ;
}
return true ;
}
return false ;
}
static int F_99 ( struct V_404 * V_446 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_446 -> V_131 -> V_6 -> V_7 ;
unsigned int V_150 = V_446 -> V_131 -> V_150 ;
struct V_447 * V_448 = & V_2 -> V_406 [ V_150 ] ;
int V_449 ;
F_100 ( V_446 -> V_131 -> V_6 -> V_429 ) ;
F_90 ( & V_448 -> V_450 ) ;
V_449 = F_95 ( V_2 , false ) ;
F_101 ( V_446 -> V_131 -> V_6 -> V_429 ) ;
return V_449 ;
}
static int F_102 ( struct V_404 * V_44 ,
void (* F_103) ( struct V_404 * ) )
{
struct V_1 * V_2 =
(struct V_1 * ) V_44 -> V_131 -> V_6 -> V_7 ;
struct V_423 * V_300 =
& V_2 -> V_300 [ V_44 -> V_131 -> V_150 ] ;
struct V_447 * V_406 = V_2 -> V_406 ;
unsigned char * V_420 = V_44 -> V_451 ;
int V_419 = V_44 -> V_452 ;
int V_199 = V_44 -> V_131 -> V_150 ;
int V_453 = V_44 -> V_131 -> V_453 ;
int V_454 = F_104 ( V_44 ) ;
int V_152 ;
struct V_12 * V_13 ;
if ( V_420 [ 0 ] == V_455 && V_44 -> V_421 [ 0 ] != 0 ) {
V_44 -> V_62 = V_371 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
F_101 ( V_2 -> V_40 -> V_429 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_429 ) ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
V_44 -> V_62 = V_390 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
}
V_152 = F_105 ( V_44 ) ;
F_106 ( V_152 < 0 ) ;
if ( V_152 ) {
struct V_456 * V_457 ;
int V_83 ;
V_13 -> V_49 = V_458 ;
V_13 -> V_459 = V_152 * sizeof( struct V_460 ) ;
if ( F_53 ( V_2 ) )
V_13 -> V_461 = ( void * ) ( ( unsigned int ) V_13 -> V_19 +
( ( unsigned long ) & V_13 -> V_462 -
( unsigned long ) V_13 ) ) ;
else
V_13 -> V_461 = V_13 -> V_462 ;
F_107 (command, sg, count, i) {
V_13 -> V_462 [ V_83 ] . V_463 = F_108 ( V_457 ) ;
V_13 -> V_462 [ V_83 ] . V_464 = F_109 ( V_457 ) ;
}
} else if ( ! V_152 ) {
V_13 -> V_49 = V_465 ;
V_13 -> V_459 = V_454 ;
V_13 -> V_461 = 0 ;
}
switch ( V_420 [ 0 ] ) {
case V_466 :
case V_467 :
V_13 -> V_468 = V_469 ;
V_406 [ V_199 ] . V_470 ++ ;
F_110 ( & V_406 [ V_199 ] . V_471 , V_454 ) ;
F_111 ( V_406 [ V_199 ] . V_472 , V_454 ) ;
break;
case V_473 :
case V_474 :
V_13 -> V_468 = V_475 ;
V_406 [ V_199 ] . V_476 ++ ;
F_110 ( & V_406 [ V_199 ] . V_477 , V_454 ) ;
F_111 ( V_406 [ V_199 ] . V_478 , V_454 ) ;
break;
default:
V_13 -> V_468 = V_479 ;
break;
}
V_13 -> V_419 = V_419 ;
V_13 -> V_364 = 0 ;
V_13 -> V_366 = 0 ;
V_13 -> V_199 = V_199 ;
V_13 -> V_453 = V_453 ;
V_13 -> V_480 = false ;
V_13 -> V_481 = false ;
if ( V_2 -> V_304 [ V_199 ] ++ >= V_482 &&
! V_300 -> V_301 &&
V_2 -> V_303 [ V_199 ] == 0
&& V_300 -> V_227 &&
( V_2 -> V_227 & ( 1 << V_199 ) ) ) {
V_300 -> V_301 = true ;
F_12 ( L_161 ,
V_2 , V_199 ) ;
}
if ( V_300 -> V_301 ) {
enum V_483 V_484 = V_485 ;
if ( V_2 -> V_303 [ V_199 ] == 0 )
V_2 -> V_486 [ V_199 ] = V_409 ;
else if ( F_112 ( V_409 ,
V_2 -> V_486 [ V_199 ] + 4 * V_487 ) ) {
V_2 -> V_486 [ V_199 ] = V_409 ;
V_484 = V_488 ;
}
if ( V_2 -> V_211 ) {
V_13 -> V_480 = true ;
V_13 -> V_484 = V_484 ;
} else {
V_13 -> V_481 = true ;
V_13 -> V_489 = V_484 ;
}
}
memcpy ( V_13 -> V_420 , V_420 , V_419 ) ;
V_13 -> V_46 = V_490 ;
V_13 -> V_45 = F_113 ( V_2 -> V_32 ,
V_44 -> V_421 , V_13 -> V_46 ,
V_47 ) ;
V_13 -> V_44 = V_44 ;
V_44 -> V_410 = F_103 ;
if ( F_53 ( V_2 ) ) {
if ( ! F_97 ( V_2 , V_444 , V_13 ) ) {
F_101 ( V_2 -> V_40 -> V_429 ) ;
F_38 ( L_162 L_163 , V_2 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_429 ) ;
if ( ! F_97 ( V_2 , V_444 ,
V_13 ) ) {
F_38 ( L_164 L_165 , V_2 ) ;
F_14 ( V_13 ) ;
V_44 -> V_62 = V_390 << 16 ;
V_44 -> V_410 ( V_44 ) ;
}
}
} else {
V_13 -> V_17 = V_401 ;
V_2 -> V_303 [ V_199 ] ++ ;
V_406 [ V_199 ] . V_445 ++ ;
F_114 ( V_2 -> V_181 , V_13 ) ;
if ( V_13 -> V_17 == V_362 )
F_89 ( V_2 ) ;
}
return 0 ;
}
int F_115 ( struct V_341 * V_491 , struct V_492 * V_115 ,
T_7 V_493 , int * V_494 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_491 -> V_6 -> V_7 ;
struct V_495 * V_496 = (struct V_495 * ) V_494 ;
unsigned char * V_497 ;
if ( V_2 -> V_203 && V_493 >= 2 * 1024 * 1024 ) {
if ( V_493 >= 4 * 1024 * 1024 ) {
V_496 -> V_498 = 255 ;
V_496 -> V_499 = 63 ;
} else {
V_496 -> V_498 = 128 ;
V_496 -> V_499 = 32 ;
}
} else {
V_496 -> V_498 = 64 ;
V_496 -> V_499 = 32 ;
}
V_496 -> V_500 = ( unsigned long ) V_493 / ( V_496 -> V_498 * V_496 -> V_499 ) ;
V_497 = F_116 ( V_115 ) ;
if ( V_497 == NULL )
return 0 ;
if ( * ( unsigned short * ) ( V_497 + 64 ) == 0xAA55 ) {
struct V_501 * V_502 = (struct V_501 * ) V_497 ;
struct V_501 * V_503 = V_502 ;
int V_504 = V_496 -> V_500 , V_505 ;
unsigned char V_506 = 0 , V_507 = 0 ;
for ( V_505 = 0 ; V_505 < 4 ; V_505 ++ ) {
V_506 = V_503 -> V_508 ;
V_507 = V_503 -> V_509 & 0x3F ;
if ( V_506 == 64 - 1 ) {
V_496 -> V_498 = 64 ;
V_496 -> V_499 = 32 ;
break;
} else if ( V_506 == 128 - 1 ) {
V_496 -> V_498 = 128 ;
V_496 -> V_499 = 32 ;
break;
} else if ( V_506 == 255 - 1 ) {
V_496 -> V_498 = 255 ;
V_496 -> V_499 = 63 ;
break;
}
V_503 ++ ;
}
if ( V_505 == 4 ) {
V_506 = V_502 -> V_508 ;
V_507 = V_502 -> V_509 & 0x3F ;
}
V_496 -> V_500 = ( unsigned long ) V_493 / ( V_496 -> V_498 * V_496 -> V_499 ) ;
if ( V_505 < 4 && V_507 == V_496 -> V_499 ) {
if ( V_496 -> V_500 != V_504 )
F_38 ( L_166 , V_2 , V_496 -> V_498 , V_496 -> V_499 ) ;
} else if ( V_506 > 0 || V_507 > 0 ) {
F_38 ( L_167 L_168 , V_2 , V_506 + 1 , V_507 ) ;
F_38 ( L_169 L_170 , V_2 , V_496 -> V_498 , V_496 -> V_499 ) ;
}
}
F_73 ( V_497 ) ;
return 0 ;
}
static int F_117 ( struct V_5 * V_510 , char * V_511 ,
int V_512 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_510 -> V_7 ;
struct V_447 * V_406 ;
V_406 = V_2 -> V_406 ;
V_2 -> V_438 = 0 ;
V_2 -> V_439 = 0 ;
memset ( V_406 , 0 , V_262 * sizeof( struct V_447 ) ) ;
return 0 ;
}
static int F_118 ( struct V_513 * V_514 , struct V_5 * V_510 )
{
struct V_1 * V_2 = (struct V_1 * ) V_510 -> V_7 ;
struct V_447 * V_406 ;
int V_197 ;
V_406 = V_2 -> V_406 ;
F_119 ( V_514 , V_2 -> V_515 , V_2 -> V_516 ) ;
F_120 ( V_514 , L_171 , V_2 -> V_38 , V_2 -> V_29 ) ;
F_120 ( V_514 , L_172 ) ;
for ( V_197 = 0 ; V_197 < V_2 -> V_219 ; V_197 ++ ) {
struct V_423 * V_300 = & V_2 -> V_300 [ V_197 ] ;
if ( ! V_300 -> V_324 )
continue;
F_120 ( V_514 , L_173 , V_197 , ( V_300 -> V_227 ? ( V_300 -> V_301 ? L_174 : ( V_2 -> V_227 & ( 1 << V_197 )
? L_175 : L_176 ) )
: L_177 ) ) ;
F_120 ( V_514 ,
L_178 , V_2 -> V_263 [ V_197 ] , V_2 -> V_303 [ V_197 ] , V_406 [ V_197 ] . V_445 , V_406 [ V_197 ] . V_413 ) ;
}
F_120 ( V_514 , L_179 ) ;
for ( V_197 = 0 ; V_197 < V_2 -> V_219 ; V_197 ++ ) {
struct V_423 * V_300 = & V_2 -> V_300 [ V_197 ] ;
if ( ! V_300 -> V_324 )
continue;
F_120 ( V_514 , L_180 , V_197 , V_406 [ V_197 ] . V_470 , V_406 [ V_197 ] . V_476 ) ;
if ( V_406 [ V_197 ] . V_471 . V_517 > 0 )
F_120 ( V_514 , L_181 , V_406 [ V_197 ] . V_471 . V_517 , V_406 [ V_197 ] . V_471 . V_518 ) ;
else
F_120 ( V_514 , L_182 , V_406 [ V_197 ] . V_471 . V_518 ) ;
if ( V_406 [ V_197 ] . V_477 . V_517 > 0 )
F_120 ( V_514 , L_183 , V_406 [ V_197 ] . V_477 . V_517 , V_406 [ V_197 ] . V_477 . V_518 ) ;
else
F_120 ( V_514 , L_184 , V_406 [ V_197 ] . V_477 . V_518 ) ;
}
F_120 ( V_514 , L_185 ) ;
for ( V_197 = 0 ; V_197 < V_2 -> V_219 ; V_197 ++ ) {
struct V_423 * V_300 = & V_2 -> V_300 [ V_197 ] ;
if ( ! V_300 -> V_324 )
continue;
F_120 ( V_514 ,
L_186 , V_197 ,
V_406 [ V_197 ] . V_472 [ 0 ] ,
V_406 [ V_197 ] . V_472 [ 1 ] , V_406 [ V_197 ] . V_472 [ 2 ] , V_406 [ V_197 ] . V_472 [ 3 ] , V_406 [ V_197 ] . V_472 [ 4 ] ) ;
F_120 ( V_514 ,
L_187 , V_197 ,
V_406 [ V_197 ] . V_478 [ 0 ] ,
V_406 [ V_197 ] . V_478 [ 1 ] , V_406 [ V_197 ] . V_478 [ 2 ] , V_406 [ V_197 ] . V_478 [ 3 ] , V_406 [ V_197 ] . V_478 [ 4 ] ) ;
}
F_120 ( V_514 , L_188 ) ;
for ( V_197 = 0 ; V_197 < V_2 -> V_219 ; V_197 ++ ) {
struct V_423 * V_300 = & V_2 -> V_300 [ V_197 ] ;
if ( ! V_300 -> V_324 )
continue;
F_120 ( V_514 ,
L_186 , V_197 ,
V_406 [ V_197 ] . V_472 [ 5 ] ,
V_406 [ V_197 ] . V_472 [ 6 ] , V_406 [ V_197 ] . V_472 [ 7 ] , V_406 [ V_197 ] . V_472 [ 8 ] , V_406 [ V_197 ] . V_472 [ 9 ] ) ;
F_120 ( V_514 ,
L_187 , V_197 ,
V_406 [ V_197 ] . V_478 [ 5 ] ,
V_406 [ V_197 ] . V_478 [ 6 ] , V_406 [ V_197 ] . V_478 [ 7 ] , V_406 [ V_197 ] . V_478 [ 8 ] , V_406 [ V_197 ] . V_478 [ 9 ] ) ;
}
F_120 ( V_514 , L_189 ) ;
for ( V_197 = 0 ; V_197 < V_2 -> V_219 ; V_197 ++ ) {
struct V_423 * V_300 = & V_2 -> V_300 [ V_197 ] ;
if ( ! V_300 -> V_324 )
continue;
F_120 ( V_514 , L_190 , V_197 , V_406 [ V_197 ] . V_519 , V_406 [ V_197 ] . V_520 , V_406 [ V_197 ] . V_415 , V_406 [ V_197 ] . V_521 , V_406 [ V_197 ] . V_522 , V_406 [ V_197 ] . V_407 , V_406 [ V_197 ] . V_450 , V_406 [ V_197 ] . V_523 , V_406 [ V_197 ] . V_524 ) ;
}
F_120 ( V_514 , L_191 , V_2 -> V_438 ) ;
F_120 ( V_514 , L_192 , V_2 -> V_439 ) ;
return 0 ;
}
static void F_121 ( enum V_525 V_526 , char * V_527 ,
struct V_1 * V_2 , ... )
{
static char V_497 [ V_528 ] ;
static bool V_529 = true ;
T_8 args ;
int V_530 = 0 ;
va_start ( args , V_2 ) ;
V_530 = vsprintf ( V_497 , V_527 , args ) ;
va_end ( args ) ;
if ( V_526 == V_531 ) {
static int V_532 = 0 ;
strcpy ( & V_2 -> V_515 [ V_2 -> V_516 ] , V_497 ) ;
V_2 -> V_516 += V_530 ;
if ( ++ V_532 <= 2 )
F_78 ( L_193 , V_533 [ V_526 ] , V_497 ) ;
} else if ( V_526 == V_534 ) {
strcpy ( & V_2 -> V_515 [ V_2 -> V_516 ] , V_497 ) ;
V_2 -> V_516 += V_530 ;
if ( V_529 ) {
if ( V_497 [ 0 ] != '\n' || V_530 > 1 )
F_78 ( L_194 , V_533 [ V_526 ] , V_2 -> V_358 , V_497 ) ;
} else
F_78 ( L_195 , V_497 ) ;
} else {
if ( V_529 ) {
if ( V_2 != NULL && V_2 -> V_319 )
F_78 ( L_194 , V_533 [ V_526 ] , V_2 -> V_358 , V_497 ) ;
else
F_78 ( L_196 , V_533 [ V_526 ] , V_497 ) ;
} else
F_78 ( L_195 , V_497 ) ;
}
V_529 = ( V_497 [ V_530 - 1 ] == '\n' ) ;
}
static bool T_2 F_122 ( char * * V_535 , char * V_536 )
{
char * V_537 = * V_535 ;
while ( * V_536 != '\0' ) {
char V_538 = * V_537 ++ ;
char V_539 = * V_536 ++ ;
if ( V_538 >= 'A' && V_538 <= 'Z' )
V_538 += 'a' - 'Z' ;
if ( V_539 >= 'A' && V_539 <= 'Z' )
V_539 += 'a' - 'Z' ;
if ( V_538 != V_539 )
return false ;
}
* V_535 = V_537 ;
return true ;
}
static int T_2 F_123 ( char * V_540 )
{
while ( true ) {
struct V_356 * V_264 =
& V_356 [ V_355 ++ ] ;
int V_199 ;
memset ( V_264 , 0 , sizeof( struct V_356 ) ) ;
while ( * V_540 != '\0' && * V_540 != ';' ) {
if ( F_122 ( & V_540 , L_197 ) ) {
unsigned long V_88 = F_124 ( V_540 ,
& V_540 , 0 ) ;
V_98 . V_100 = true ;
switch ( V_88 ) {
case 0x330 :
V_98 . V_101 = true ;
break;
case 0x334 :
V_98 . V_102 = true ;
break;
case 0x230 :
V_98 . V_103 = true ;
break;
case 0x234 :
V_98 . V_104 = true ;
break;
case 0x130 :
V_98 . V_105 = true ;
break;
case 0x134 :
V_98 . V_106 = true ;
break;
default:
F_8 ( L_198 L_199 , NULL , V_88 ) ;
return 0 ;
}
} else if ( F_122 ( & V_540 , L_200 ) )
V_98 . V_99 = true ;
else if ( F_122 ( & V_540 , L_201 ) )
V_98 . V_162 = true ;
else if ( F_122 ( & V_540 , L_202 ) )
V_98 . V_349 = true ;
else if ( F_122 ( & V_540 , L_203 ) )
V_98 . V_541 = true ;
else if ( F_122 ( & V_540 , L_204 ) )
V_98 . V_163 = true ;
else if ( F_122 ( & V_540 , L_205 ) )
V_98 . V_164 = true ;
else if ( F_122 ( & V_540 , L_206 ) ||
F_122 ( & V_540 , L_207 ) ) {
for ( V_199 = 0 ; V_199 < V_262 ; V_199 ++ ) {
unsigned short V_263 = F_124 ( V_540 , & V_540 , 0 ) ;
if ( V_263 > V_482 ) {
F_8 ( L_198 L_208 , NULL , V_263 ) ;
return 0 ;
}
V_264 -> V_263 [ V_199 ] = V_263 ;
if ( * V_540 == ',' )
V_540 ++ ;
else if ( * V_540 == ']' )
break;
else {
F_8 ( L_198 L_209 , NULL , V_540 ) ;
return 0 ;
}
}
if ( * V_540 != ']' ) {
F_8 ( L_198 L_210 , NULL , V_540 ) ;
return 0 ;
} else
V_540 ++ ;
} else if ( F_122 ( & V_540 , L_211 ) || F_122 ( & V_540 , L_212 ) ) {
unsigned short V_263 = F_124 ( V_540 , & V_540 , 0 ) ;
if ( V_263 == 0 ||
V_263 > V_482 ) {
F_8 ( L_198 L_208 , NULL , V_263 ) ;
return 0 ;
}
V_264 -> V_269 = V_263 ;
for ( V_199 = 0 ; V_199 < V_262 ; V_199 ++ )
V_264 -> V_263 [ V_199 ] = V_263 ;
} else if ( F_122 ( & V_540 , L_213 ) ||
F_122 ( & V_540 , L_214 ) ) {
if ( F_122 ( & V_540 , L_215 ) ) {
V_264 -> V_227 = 0x0000 ;
V_264 -> V_270 = 0x0000 ;
} else if ( F_122 ( & V_540 , L_216 ) ) {
V_264 -> V_227 = 0xFFFF ;
V_264 -> V_270 = 0xFFFF ;
} else if ( F_122 ( & V_540 , L_217 ) ) {
V_264 -> V_227 = 0x0000 ;
V_264 -> V_270 = 0xFFFF ;
} else {
unsigned short V_542 ;
for ( V_199 = 0 , V_542 = 1 ;
V_199 < V_262 ;
V_199 ++ , V_542 <<= 1 )
switch ( * V_540 ++ ) {
case 'Y' :
V_264 -> V_227 |= V_542 ;
V_264 -> V_270 |= V_542 ;
break;
case 'N' :
V_264 -> V_227 &= ~ V_542 ;
V_264 -> V_270 |= V_542 ;
break;
case 'X' :
break;
default:
V_540 -- ;
V_199 = V_262 ;
break;
}
}
}
else if ( F_122 ( & V_540 , L_218 ) ||
F_122 ( & V_540 , L_219 ) ) {
unsigned short V_271 =
F_124 ( V_540 , & V_540 , 0 ) ;
if ( V_271 > 5 * 60 ) {
F_8 ( L_198 L_220 , NULL , V_271 ) ;
return 0 ;
}
V_264 -> V_271 = V_271 ;
} else if ( F_122 ( & V_540 ,
L_221 ) )
V_264 -> V_323 = true ;
else if ( F_122 ( & V_540 , L_222 ) )
V_77 . V_141 = true ;
else if ( F_122 ( & V_540 , L_223 ) )
V_77 . V_183 = true ;
else if ( F_122 ( & V_540 , L_224 ) )
V_77 . V_78 = true ;
else if ( F_122 ( & V_540 , L_225 ) )
V_77 . V_418 = true ;
else if ( F_122 ( & V_540 , L_226 ) ) {
V_77 . V_141 = true ;
V_77 . V_183 = true ;
V_77 . V_78 = true ;
V_77 . V_418 = true ;
}
if ( * V_540 == ',' )
V_540 ++ ;
else if ( * V_540 != ';' && * V_540 != '\0' ) {
F_8 ( L_227 L_228 , NULL , V_540 ) ;
* V_540 = '\0' ;
}
}
if ( ! ( V_355 == 0 ||
V_91 == 0 ||
V_355 == V_91 ) ) {
F_8 ( L_198 L_229 , NULL ) ;
return 0 ;
}
for ( V_199 = 0 ; V_199 < V_262 ; V_199 ++ )
if ( V_264 -> V_263 [ V_199 ] == 1 ) {
unsigned short V_542 = 1 << V_199 ;
V_264 -> V_227 &= ~ V_542 ;
V_264 -> V_270 |= V_542 ;
}
if ( * V_540 == ';' )
V_540 ++ ;
if ( * V_540 == '\0' )
return 0 ;
}
return 1 ;
}
static int T_2 F_71 ( char * V_535 )
{
int V_543 [ 3 ] ;
( void ) F_125 ( V_535 , F_126 ( V_543 ) , V_543 ) ;
if ( V_543 [ 0 ] != 0 ) {
F_8 ( L_230 L_231 , NULL ) ;
return 0 ;
}
if ( V_535 == NULL || * V_535 == '\0' )
return 0 ;
return F_123 ( V_535 ) ;
}
static void T_5 F_127 ( void )
{
struct V_1 * V_544 , * V_25 ;
F_128 (ha, next, &blogic_host_list, host_list)
F_83 ( V_544 ) ;
}
