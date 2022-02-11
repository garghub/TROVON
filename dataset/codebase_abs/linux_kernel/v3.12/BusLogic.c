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
struct V_1 * V_127 = V_2 ;
struct V_128 V_129 ;
enum V_130 V_131 ;
unsigned char V_114 ;
unsigned char V_132 ;
unsigned int V_133 ;
unsigned long V_134 ;
unsigned long V_135 ;
unsigned long V_88 ;
unsigned long V_136 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_137 ;
V_132 = V_32 -> V_138 >> 3 ;
V_133 = V_32 -> V_139 ;
V_88 = V_134 = F_35 ( V_32 , 0 ) ;
V_136 = V_135 = F_35 ( V_32 , 1 ) ;
if ( F_36 ( V_32 , 0 ) & V_140 ) {
F_8 ( L_20 L_21 , NULL , V_134 ) ;
F_8 ( L_22 , NULL , V_114 , V_132 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_141 ) {
F_8 ( L_23 L_21 , NULL , V_135 ) ;
F_8 ( L_24 , NULL , V_114 , V_132 , V_136 ) ;
continue;
}
if ( V_133 == 0 ) {
F_8 ( L_25 L_21 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_114 , V_132 , V_88 ) ;
continue;
}
if ( V_77 . V_142 ) {
F_12 ( L_26 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_114 , V_132 , V_88 , V_136 ) ;
}
V_127 -> V_88 = V_88 ;
F_24 ( V_127 ) ;
if ( F_17 ( V_127 , V_143 , NULL , 0 ,
& V_129 , sizeof( V_129 ) ) ==
sizeof( V_129 ) ) {
if ( V_129 . V_144 < 6 )
V_123 [ V_129 . V_144 ] = true ;
} else
V_129 . V_144 = V_145 ;
V_131 = V_145 ;
F_17 ( V_127 , V_75 , & V_131 ,
sizeof( V_131 ) , NULL , 0 ) ;
if ( ! V_122 ) {
struct V_146 V_147 ;
struct V_148 V_149 ;
struct V_150 V_151 ;
V_147 . V_14 = V_152 + 45 ;
V_147 . V_153 = sizeof( V_149 ) ;
F_17 ( V_127 , V_82 ,
& V_147 , sizeof( V_147 ) ,
& V_149 ,
sizeof( V_149 ) ) ;
F_17 ( V_127 , V_154 , NULL , 0 ,
& V_151 , sizeof( V_151 ) ) ;
if ( V_151 . V_155 == '5' )
V_121 =
V_149 . V_121 ;
V_122 = true ;
}
if ( V_129 . V_144 == V_156 ) {
V_117 -> V_94 = V_95 ;
V_117 -> V_96 = V_157 ;
V_117 -> V_88 = V_88 ;
V_117 -> V_136 = V_136 ;
V_117 -> V_114 = V_114 ;
V_117 -> V_115 = V_132 ;
V_117 -> V_133 = V_133 ;
V_117 -> V_32 = F_37 ( V_32 ) ;
V_120 ++ ;
} else if ( V_91 < V_92 ) {
struct V_89 * V_90 =
& V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 = V_157 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_136 = V_136 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_132 ;
V_90 -> V_133 = V_133 ;
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
V_158 ,
V_32 ) ) != NULL ) {
unsigned char V_114 ;
unsigned char V_132 ;
unsigned int V_133 ;
unsigned long V_88 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_137 ;
V_132 = V_32 -> V_138 >> 3 ;
V_133 = V_32 -> V_139 ;
V_88 = F_35 ( V_32 , 0 ) ;
if ( V_88 == 0 || V_133 == 0 )
continue;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
struct V_89 * V_90 =
& V_93 [ V_83 ] ;
if ( V_90 -> V_88 == V_88 &&
V_90 -> V_94 == V_95 ) {
V_90 -> V_96 = V_157 ;
V_90 -> V_136 = 0 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_132 ;
V_90 -> V_133 = V_133 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
break;
}
}
}
return V_120 ;
}
static int T_2 F_39 ( struct V_1 * V_2 )
{
int V_159 = V_91 , V_160 = 0 ;
struct V_124 * V_32 = NULL ;
while ( ( V_32 = F_31 ( V_125 ,
V_161 ,
V_32 ) ) != NULL ) {
unsigned char V_114 ;
unsigned char V_132 ;
unsigned int V_133 ;
unsigned long V_134 ;
unsigned long V_135 ;
unsigned long V_88 ;
unsigned long V_136 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_114 = V_32 -> V_114 -> V_137 ;
V_132 = V_32 -> V_138 >> 3 ;
V_133 = V_32 -> V_139 ;
V_88 = V_134 = F_35 ( V_32 , 0 ) ;
V_136 = V_135 = F_35 ( V_32 , 1 ) ;
#ifdef F_40
if ( F_36 ( V_32 , 0 ) & V_140 ) {
F_8 ( L_20 L_32 , NULL , V_134 ) ;
F_8 ( L_22 , NULL , V_114 , V_132 , V_88 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_141 ) {
F_8 ( L_23 L_32 , NULL , V_135 ) ;
F_8 ( L_24 , NULL , V_114 , V_132 , V_136 ) ;
continue;
}
if ( V_133 == 0 ) {
F_8 ( L_25 L_32 , NULL , V_133 ) ;
F_8 ( L_22 , NULL , V_114 , V_132 , V_88 ) ;
continue;
}
if ( V_77 . V_142 ) {
F_12 ( L_33 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_114 , V_132 , V_88 , V_136 ) ;
}
if ( V_91 < V_92 ) {
struct V_89 * V_90 =
& V_93 [ V_91 ++ ] ;
V_90 -> V_94 = V_162 ;
V_90 -> V_96 = V_157 ;
V_90 -> V_88 = V_88 ;
V_90 -> V_136 = V_136 ;
V_90 -> V_114 = V_114 ;
V_90 -> V_115 = V_132 ;
V_90 -> V_133 = V_133 ;
V_90 -> V_32 = F_37 ( V_32 ) ;
V_160 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
#else
F_8 ( L_34 L_35 , NULL , V_114 , V_132 ) ;
F_8 ( L_36 L_37 , NULL , V_88 , V_136 , V_133 ) ;
F_8 ( L_38 L_39 , NULL ) ;
#endif
}
F_29 ( & V_93 [ V_159 ] , V_160 ) ;
return V_160 ;
}
static void T_2 F_41 ( struct V_1 * V_2 )
{
if ( ! V_98 . V_163 ) {
if ( V_98 . V_164 ) {
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
} else if ( V_98 . V_165 ) {
F_39 ( V_2 ) ;
F_30 ( V_2 ) ;
} else {
int V_160 = F_39 ( V_2 ) ;
int V_120 = F_30 ( V_2 ) ;
if ( V_160 > 0 && V_120 > 0 ) {
struct V_89 * V_90 =
& V_93 [ V_160 ] ;
struct V_1 * V_166 = V_2 ;
struct V_146 V_147 ;
struct V_167 V_168 ;
while ( V_90 -> V_96 !=
V_157 )
V_90 ++ ;
V_166 -> V_88 = V_90 -> V_88 ;
V_147 . V_14 =
V_169 + V_170 ;
V_147 . V_153 = sizeof( V_168 ) ;
F_17 ( V_166 , V_82 ,
& V_147 ,
sizeof( V_147 ) ,
& V_168 ,
sizeof( V_168 ) ) ;
if ( V_168 . V_171 != V_172 ) {
struct V_89 V_173 [ V_92 ] ;
int V_120 = V_91 - V_160 ;
memcpy ( V_173 ,
V_93 ,
V_91 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ 0 ] ,
& V_173 [ V_160 ] ,
V_120 * sizeof( struct V_89 ) ) ;
memcpy ( & V_93 [ V_120 ] ,
& V_173 [ 0 ] ,
V_160 * sizeof( struct V_89 ) ) ;
}
}
}
} else {
F_28 ( V_2 ) ;
}
}
static bool F_42 ( struct V_1 * V_2 , char * V_174 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_96 == V_157 ) {
F_8 ( L_40 ,
V_2 ) ;
F_8 ( L_41 , V_2 , V_2 -> V_114 , V_2 -> V_115 , V_2 -> V_88 , V_2 -> V_136 ) ;
} else
F_8 ( L_42 L_43 , V_2 , V_2 -> V_88 ) ;
F_8 ( L_44 , V_2 , V_174 ) ;
if ( V_69 != NULL )
F_8 ( L_45 , V_2 ,
V_69 ) ;
return false ;
}
static bool T_2 F_43 ( struct V_1 * V_2 )
{
union V_56 V_57 ;
union V_58 V_59 ;
union V_175 V_176 ;
if ( F_5 ( V_2 ) ) {
struct V_177 * V_24 = & V_2 -> V_24 ;
V_24 -> V_23 = ( V_20 ) V_2 -> V_88 ;
V_24 -> V_133 = V_2 -> V_133 ;
V_24 -> V_178 = false ;
if ( ! ( F_44 ( V_24 ) == 0 &&
V_24 -> V_178 ) ) {
F_8 ( L_34 L_35 , V_2 , V_2 -> V_114 , V_2 -> V_115 ) ;
F_8 ( L_46 L_37 , V_2 , V_2 -> V_88 , V_2 -> V_136 ) ;
F_8 ( L_47 , V_2 ) ;
return false ;
}
if ( V_77 . V_142 )
F_12 ( L_48 , V_2 , V_2 -> V_88 ) ;
return true ;
}
V_57 . V_65 = F_19 ( V_2 ) ;
V_59 . V_65 = F_22 ( V_2 ) ;
V_176 . V_65 = F_45 ( V_2 ) ;
if ( V_77 . V_142 )
F_12 ( L_49 L_50 , V_2 , V_2 -> V_88 , V_57 . V_65 , V_59 . V_65 , V_176 . V_65 ) ;
if ( V_57 . V_65 == 0 || V_57 . V_66 . V_86 ||
V_57 . V_66 . V_68 || V_57 . V_66 . V_84 ||
V_57 . V_66 . V_76 || V_59 . V_72 . V_84 != 0 )
return false ;
if ( V_176 . V_65 == 0xFF )
return false ;
return true ;
}
static bool F_46 ( struct V_1 * V_2 , bool V_179 )
{
union V_56 V_57 ;
int V_63 ;
if ( F_5 ( V_2 ) ) {
struct V_177 * V_24 = & V_2 -> V_24 ;
V_24 -> V_180 = ! V_179 ;
V_24 -> V_181 = true ;
V_2 -> V_182 =
F_47 ( V_24 ) ;
if ( V_2 -> V_182 == ( void * ) V_183 )
return false ;
return true ;
}
if ( V_179 )
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
if ( V_77 . V_184 )
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
if ( V_77 . V_184 )
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
if ( V_77 . V_184 )
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
struct V_185 V_186 ;
unsigned char V_187 ;
bool V_62 = true ;
if ( F_5 ( V_2 ) )
return true ;
V_187 = sizeof( V_186 ) ;
if ( F_17 ( V_2 , V_188 , & V_187 ,
sizeof( V_187 ) , & V_186 ,
sizeof( V_186 ) ) != sizeof( V_186 ) )
V_62 = false ;
if ( V_77 . V_142 )
F_12 ( L_58 , V_2 ,
V_2 -> V_88 ,
( V_62 ? L_59 : L_60 ) ) ;
return V_62 ;
}
static bool T_2 F_50 ( struct V_1 * V_2 )
{
struct V_150 V_151 ;
struct V_189 V_190 ;
struct V_191 V_192 ;
struct V_185 V_186 ;
unsigned char V_193 [ 5 ] ;
unsigned char V_194 ;
unsigned char V_195 ;
struct V_128 V_129 ;
struct V_146 V_147 ;
struct V_196 V_197 ;
union V_175 V_176 ;
unsigned char V_187 ;
unsigned char * V_198 , V_199 ;
int V_200 , V_83 ;
if ( F_5 ( V_2 ) ) {
struct V_177 * V_24 = & V_2 -> V_24 ;
V_198 = V_2 -> V_193 ;
* V_198 ++ = 'B' ;
* V_198 ++ = 'T' ;
* V_198 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_24 -> V_193 ) ; V_83 ++ )
* V_198 ++ = V_24 -> V_193 [ V_83 ] ;
* V_198 ++ = '\0' ;
strcpy ( V_2 -> V_201 , V_202 ) ;
V_2 -> V_203 = V_24 -> V_203 ;
V_2 -> V_204 = V_24 -> V_204 ;
V_2 -> V_205 = V_24 -> V_205 ;
V_2 -> V_206 = ! V_24 -> V_180 ;
V_2 -> V_207 = true ;
V_2 -> V_208 = V_24 -> V_208 ;
V_2 -> V_209 = false ;
V_2 -> V_210 = true ;
V_2 -> V_211 = true ;
V_2 -> V_212 = true ;
V_2 -> V_213 = true ;
V_2 -> V_214 = V_24 -> V_214 ;
V_2 -> V_215 = V_24 -> V_215 ;
V_2 -> V_216 = V_24 -> V_216 ;
V_2 -> V_217 = V_24 -> V_217 ;
V_2 -> V_218 = V_219 ;
V_2 -> V_220 = ( V_2 -> V_208 ? 16 : 8 ) ;
V_2 -> V_221 = 32 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_38 = 255 ;
V_2 -> V_222 = V_2 -> V_38 ;
V_2 -> V_223 = V_24 -> V_223 ;
V_2 -> V_224 = V_24 -> V_224 ;
V_2 -> V_225 = V_24 -> V_225 ;
V_2 -> V_226 = V_24 -> V_226 ;
V_2 -> V_227 = V_24 -> V_227 ;
V_2 -> V_228 = 0xFFFF ;
goto V_229;
}
if ( F_17 ( V_2 , V_154 , NULL , 0 , & V_151 ,
sizeof( V_151 ) ) != sizeof( V_151 ) )
return F_42 ( V_2 , L_61 ) ;
if ( F_17 ( V_2 , V_230 , NULL , 0 , & V_190 ,
sizeof( V_190 ) )
!= sizeof( V_190 ) )
return F_42 ( V_2 , L_62 ) ;
V_187 = sizeof( V_192 ) ;
if ( F_17 ( V_2 , V_231 , & V_187 ,
sizeof( V_187 ) , & V_192 ,
sizeof( V_192 ) ) != sizeof( V_192 ) )
return F_42 ( V_2 , L_63 ) ;
V_187 = sizeof( V_186 ) ;
if ( F_17 ( V_2 , V_188 , & V_187 ,
sizeof( V_187 ) , & V_186 ,
sizeof( V_186 ) ) != sizeof( V_186 ) )
return F_42 ( V_2 ,
L_64 ) ;
V_194 = '\0' ;
if ( V_151 . V_155 > '0' )
if ( F_17 ( V_2 , V_232 , NULL , 0 ,
& V_194 ,
sizeof( V_194 ) ) != sizeof( V_194 ) )
return F_42 ( V_2 ,
L_65 ) ;
if ( V_186 . V_233 == 'A' && V_151 . V_155 == '2' )
strcpy ( V_193 , L_66 ) ;
else if ( V_186 . V_233 == 'E' && V_151 . V_155 == '2' &&
( V_151 . V_234 <= '1' || ( V_151 . V_234 == '2' &&
V_194 == '0' ) ) )
strcpy ( V_193 , L_67 ) ;
else if ( V_186 . V_233 == 'E' && V_151 . V_155 == '0' )
strcpy ( V_193 , L_68 ) ;
else {
V_187 = sizeof( V_193 ) ;
if ( F_17 ( V_2 , V_235 , & V_187 ,
sizeof( V_187 ) , & V_193 ,
sizeof( V_193 ) ) != sizeof( V_193 ) )
return F_42 ( V_2 ,
L_69 ) ;
}
V_198 = V_2 -> V_193 ;
* V_198 ++ = 'B' ;
* V_198 ++ = 'T' ;
* V_198 ++ = '-' ;
for ( V_83 = 0 ; V_83 < sizeof( V_193 ) ; V_83 ++ ) {
V_199 = V_193 [ V_83 ] ;
if ( V_199 == ' ' || V_199 == '\0' )
break;
* V_198 ++ = V_199 ;
}
* V_198 ++ = '\0' ;
V_198 = V_2 -> V_201 ;
* V_198 ++ = V_151 . V_155 ;
* V_198 ++ = '.' ;
* V_198 ++ = V_151 . V_234 ;
if ( V_194 != ' ' && V_194 != '\0' )
* V_198 ++ = V_194 ;
* V_198 = '\0' ;
if ( strcmp ( V_2 -> V_201 , L_70 ) >= 0 ) {
if ( F_17 ( V_2 , V_236 , NULL , 0 ,
& V_195 ,
sizeof( V_195 ) ) != sizeof( V_195 ) )
return F_42 ( V_2 ,
L_71 ) ;
if ( V_195 != ' ' && V_195 != '\0' )
* V_198 ++ = V_195 ;
* V_198 = '\0' ;
}
V_2 -> V_203 = V_190 . V_151 ;
V_2 -> V_96 =
V_237 [ V_2 -> V_193 [ 3 ] - '4' ] ;
if ( V_2 -> V_133 == 0 ) {
if ( V_190 . V_238 )
V_2 -> V_133 = 9 ;
else if ( V_190 . V_239 )
V_2 -> V_133 = 10 ;
else if ( V_190 . V_240 )
V_2 -> V_133 = 11 ;
else if ( V_190 . V_241 )
V_2 -> V_133 = 12 ;
else if ( V_190 . V_242 )
V_2 -> V_133 = 14 ;
else if ( V_190 . V_243 )
V_2 -> V_133 = 15 ;
}
if ( V_2 -> V_96 == V_97 ) {
if ( V_190 . V_244 )
V_2 -> V_245 = 5 ;
else if ( V_190 . V_246 )
V_2 -> V_245 = 6 ;
else if ( V_190 . V_247 )
V_2 -> V_245 = 7 ;
}
V_176 . V_65 = F_45 ( V_2 ) ;
V_2 -> V_204 = V_176 . V_248 . V_204 ;
V_2 -> V_249 = V_186 . V_250 ;
V_2 -> V_218 = V_2 -> V_249 ;
if ( V_2 -> V_249 > V_219 )
V_2 -> V_218 = V_219 ;
if ( V_186 . V_251 . V_207 )
V_2 -> V_207 = true ;
V_2 -> V_208 = V_186 . V_208 ;
V_2 -> V_209 = V_186 . V_209 ;
V_2 -> V_210 = V_186 . V_210 ;
V_2 -> V_211 = V_186 . V_211 ;
if ( V_2 -> V_201 [ 0 ] == '5' || ( V_2 -> V_201 [ 0 ] == '4' &&
V_2 -> V_208 ) )
V_2 -> V_212 = true ;
if ( V_2 -> V_201 [ 0 ] == '5' ) {
if ( F_17 ( V_2 , V_143 , NULL , 0 ,
& V_129 ,
sizeof( V_129 ) ) != sizeof( V_129 ) )
return F_42 ( V_2 ,
L_72 ) ;
if ( V_129 . V_252 ) {
V_2 -> V_213 = true ;
V_2 -> V_214 = V_129 . V_214 ;
V_2 -> V_215 = V_129 . V_215 ;
}
}
if ( V_2 -> V_201 [ 0 ] >= '4' ) {
V_147 . V_14 = V_152 ;
V_147 . V_153 = sizeof( V_197 ) ;
if ( F_17 ( V_2 , V_82 , & V_147 ,
sizeof( V_147 ) , & V_197 ,
sizeof( V_197 ) ) != sizeof( V_197 ) )
return F_42 ( V_2 ,
L_73 ) ;
V_2 -> V_205 = V_197 . V_205 ;
V_2 -> V_206 = V_197 . V_206 ;
if ( V_2 -> V_201 [ 0 ] == '4' ) {
V_2 -> V_213 = true ;
V_2 -> V_214 = V_197 . V_214 ;
V_2 -> V_215 = V_197 . V_215 ;
}
V_2 -> V_226 = V_197 . V_226 ;
V_2 -> V_224 = V_197 . V_224 ;
V_2 -> V_223 = V_197 . V_223 ;
V_2 -> V_227 = V_197 . V_227 ;
if ( V_2 -> V_211 )
V_2 -> V_225 = V_197 . V_225 ;
if ( V_2 -> V_210 ) {
V_2 -> V_216 = V_197 . V_216 ;
V_2 -> V_217 = V_197 . V_217 ;
}
}
if ( V_2 -> V_201 [ 0 ] < '4' ) {
if ( V_192 . V_253 ) {
V_2 -> V_223 = 0xFF ;
if ( V_2 -> V_96 == V_254 ) {
if ( V_186 . V_251 . V_255 )
V_2 -> V_224 = 0xFF ;
if ( strcmp ( V_2 -> V_193 , L_74 ) == 0 )
V_2 -> V_226 = 0xFF ;
}
}
V_2 -> V_227 = 0xFF ;
V_2 -> V_205 = V_192 . V_205 ;
V_2 -> V_206 = true ;
}
V_2 -> V_220 = ( V_2 -> V_208 ? 16 : 8 ) ;
V_2 -> V_221 = ( V_2 -> V_212 ? 32 : 8 ) ;
if ( V_2 -> V_201 [ 0 ] == '5' )
V_2 -> V_222 = 192 ;
else if ( V_2 -> V_201 [ 0 ] == '4' )
V_2 -> V_222 = ( V_2 -> V_96 !=
V_97 ? 100 : 50 ) ;
else
V_2 -> V_222 = 30 ;
if ( strcmp ( V_2 -> V_201 , L_75 ) >= 0 ) {
V_2 -> V_256 = true ;
V_2 -> V_257 = V_258 ;
} else {
V_2 -> V_256 = false ;
V_2 -> V_257 = 32 ;
}
V_2 -> V_38 = V_2 -> V_257 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_228 = 0 ;
switch ( V_2 -> V_201 [ 0 ] ) {
case '5' :
V_2 -> V_228 = 0xFFFF ;
break;
case '4' :
if ( strcmp ( V_2 -> V_201 , L_76 ) >= 0 )
V_2 -> V_228 = 0xFFFF ;
break;
case '3' :
if ( strcmp ( V_2 -> V_201 , L_77 ) >= 0 )
V_2 -> V_228 = 0xFFFF ;
break;
}
V_2 -> V_259 = V_186 . V_259 << 12 ;
if ( V_2 -> V_96 == V_97 &&
( void * ) V_260 > ( void * ) V_261 )
V_2 -> V_262 = true ;
if ( V_2 -> V_259 > 0 && strcmp ( V_2 -> V_193 , L_78 ) == 0 &&
strcmp ( V_2 -> V_201 , L_79 ) < 0 &&
( void * ) V_260 > ( void * ) V_261 )
V_2 -> V_262 = true ;
V_229:
strcpy ( V_2 -> V_8 , L_80 ) ;
strcat ( V_2 -> V_8 , V_2 -> V_193 ) ;
for ( V_200 = 0 ; V_200 < V_263 ; V_200 ++ ) {
unsigned char V_264 = 0 ;
if ( V_2 -> V_265 != NULL &&
V_2 -> V_265 -> V_264 [ V_200 ] > 0 )
V_264 = V_2 -> V_265 -> V_264 [ V_200 ] ;
else if ( V_2 -> V_262 )
V_264 = V_266 ;
V_2 -> V_264 [ V_200 ] = V_264 ;
}
if ( V_2 -> V_262 )
V_2 -> V_267 = V_268 ;
else
V_2 -> V_267 = V_269 ;
if ( V_2 -> V_265 != NULL )
V_2 -> V_270 = V_2 -> V_265 -> V_270 ;
if ( V_2 -> V_270 > 0 &&
V_2 -> V_270 < V_2 -> V_267 )
V_2 -> V_267 = V_2 -> V_270 ;
V_2 -> V_228 &= V_2 -> V_227 ;
if ( V_2 -> V_265 != NULL )
V_2 -> V_228 = ( V_2 -> V_265 -> V_228 &
V_2 -> V_265 -> V_271 ) |
( V_2 -> V_228 & ~ V_2 -> V_265 -> V_271 ) ;
if ( V_2 -> V_265 != NULL &&
V_2 -> V_265 -> V_272 > 0 )
V_2 -> V_272 = V_2 -> V_265 -> V_272 ;
else
V_2 -> V_272 = V_273 ;
return true ;
}
static bool T_2 F_51 ( struct V_1 * V_2 )
{
unsigned short V_274 = ( 1 << V_2 -> V_220 ) - 1 ;
unsigned short V_223 , V_224 ;
unsigned short V_225 , V_226 ;
unsigned short V_227 , V_228 ;
bool V_275 , V_276 ;
char V_277 [ V_263 + 1 ] ;
char V_278 [ V_263 + 1 ] ;
char V_279 [ V_263 + 1 ] ;
char V_280 [ V_263 + 1 ] ;
char * V_281 = V_277 ;
char * V_282 = V_278 ;
char * V_283 = V_279 ;
char * V_284 = V_280 ;
int V_200 ;
F_52 ( L_81 , V_2 , V_2 -> V_193 , V_285 [ V_2 -> V_96 ] , ( V_2 -> V_208 ? L_82 : L_83 ) , ( V_2 -> V_209 ? L_84 : L_83 ) , ( V_2 -> V_211 ? L_85 : L_83 ) ) ;
F_52 ( L_86 L_87 , V_2 , V_2 -> V_201 , V_2 -> V_88 , V_2 -> V_133 , ( V_2 -> V_207 ? L_88 : L_89 ) ) ;
if ( V_2 -> V_96 != V_157 ) {
F_52 ( L_90 , V_2 ) ;
if ( V_2 -> V_245 > 0 )
F_52 ( L_91 , V_2 , V_2 -> V_245 ) ;
else
F_52 ( L_92 , V_2 ) ;
if ( V_2 -> V_259 > 0 )
F_52 ( L_93 , V_2 ,
V_2 -> V_259 ) ;
else
F_52 ( L_94 , V_2 ) ;
} else {
F_52 ( L_95 , V_2 ,
V_2 -> V_114 , V_2 -> V_115 ) ;
if ( V_2 -> V_136 > 0 )
F_52 ( L_96 , V_2 , V_2 -> V_136 ) ;
else
F_52 ( L_97 , V_2 ) ;
}
F_52 ( L_98 , V_2 , V_2 -> V_203 ) ;
F_52 ( L_99 ,
V_2 , ( V_2 -> V_205 ? L_100 : L_101 ) ,
( V_2 -> V_204 ? L_100 : L_101 ) ) ;
V_274 &= ~ ( 1 << V_2 -> V_203 ) ;
V_223 = V_2 -> V_223 & V_274 ;
V_224 = V_2 -> V_224 & V_274 ;
V_225 = V_2 -> V_225 & V_274 ;
if ( ( F_53 ( V_2 ) &&
( V_2 -> V_201 [ 0 ] >= '4' ||
V_2 -> V_96 == V_254 ) ) ||
F_5 ( V_2 ) ) {
V_275 = false ;
if ( V_223 == 0 ) {
V_281 = L_101 ;
V_275 = true ;
} else if ( V_223 == V_274 ) {
if ( V_224 == 0 ) {
V_281 = L_102 ;
V_275 = true ;
} else if ( V_224 == V_274 ) {
if ( V_225 == 0 ) {
V_281 = L_103 ;
V_275 = true ;
} else if ( V_225 == V_274 ) {
V_281 = L_104 ;
V_275 = true ;
}
}
}
if ( ! V_275 ) {
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_277 [ V_200 ] = ( ( ! ( V_223 & ( 1 << V_200 ) ) ) ? 'N' : ( ! ( V_224 & ( 1 << V_200 ) ) ? 'S' : ( ! ( V_225 & ( 1 << V_200 ) ) ? 'F' : 'U' ) ) ) ;
V_277 [ V_2 -> V_203 ] = '#' ;
V_277 [ V_2 -> V_220 ] = '\0' ;
}
} else
V_281 = ( V_223 == 0 ? L_101 : L_100 ) ;
V_226 = V_2 -> V_226 & V_274 ;
if ( V_226 == 0 )
V_282 = L_101 ;
else if ( V_226 == V_274 )
V_282 = L_100 ;
else {
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_278 [ V_200 ] = ( ( V_226 & ( 1 << V_200 ) ) ? 'Y' : 'N' ) ;
V_278 [ V_2 -> V_203 ] = '#' ;
V_278 [ V_2 -> V_220 ] = '\0' ;
}
V_227 = V_2 -> V_227 & V_274 ;
if ( V_227 == 0 )
V_283 = L_101 ;
else if ( V_227 == V_274 )
V_283 = L_100 ;
else {
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_279 [ V_200 ] = ( ( V_227 & ( 1 << V_200 ) ) ? 'Y' : 'N' ) ;
V_279 [ V_2 -> V_203 ] = '#' ;
V_279 [ V_2 -> V_220 ] = '\0' ;
}
V_228 = V_2 -> V_228 & V_274 ;
if ( V_228 == 0 )
V_284 = L_101 ;
else if ( V_228 == V_274 )
V_284 = L_100 ;
else {
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_280 [ V_200 ] = ( ( V_228 & ( 1 << V_200 ) ) ? 'Y' : 'N' ) ;
V_280 [ V_2 -> V_203 ] = '#' ;
V_280 [ V_2 -> V_220 ] = '\0' ;
}
F_52 ( L_105 ,
V_2 , V_281 , V_282 ) ;
F_52 ( L_106 , V_2 ,
V_283 , V_284 ) ;
if ( F_53 ( V_2 ) ) {
F_52 ( L_107 L_108 , V_2 , V_2 -> V_218 , V_2 -> V_249 , V_2 -> V_257 ) ;
F_52 ( L_109 L_110 , V_2 , V_2 -> V_38 , V_2 -> V_222 ) ;
} else
F_52 ( L_109 L_111 , V_2 , V_2 -> V_38 , V_2 -> V_218 ) ;
F_52 ( L_112 , V_2 ) ;
V_276 = true ;
for ( V_200 = 1 ; V_200 < V_2 -> V_220 ; V_200 ++ )
if ( V_2 -> V_264 [ V_200 ] != V_2 -> V_264 [ 0 ] ) {
V_276 = false ;
break;
}
if ( V_276 ) {
if ( V_2 -> V_264 [ 0 ] > 0 )
F_52 ( L_113 , V_2 , V_2 -> V_264 [ 0 ] ) ;
else
F_52 ( L_114 , V_2 ) ;
} else
F_52 ( L_115 , V_2 ) ;
F_52 ( L_116 , V_2 ,
V_2 -> V_267 ) ;
if ( V_2 -> V_213 ) {
if ( V_2 -> V_208 )
F_52 ( L_117 , V_2 ,
( V_2 -> V_214 ? ( V_2 -> V_215 ? L_118 : L_119 ) : ( V_2 -> V_215 ? L_120 : L_121 ) ) ) ;
else
F_52 ( L_117 , V_2 ,
( V_2 -> V_214 ? L_100 : L_101 ) ) ;
if ( V_2 -> V_210 )
F_52 ( L_122 , V_2 ,
( V_2 -> V_216 ? ( V_2 -> V_217 ? L_123 : L_124 ) : L_101 ) ) ;
F_52 ( L_17 , V_2 ) ;
}
return true ;
}
static bool T_2 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_133 == 0 ) {
F_8 ( L_125 ,
V_2 ) ;
return false ;
}
if ( F_55 ( V_2 -> V_133 , V_286 , V_287 ,
V_2 -> V_8 , V_2 ) < 0 ) {
F_8 ( L_126 ,
V_2 , V_2 -> V_133 ) ;
return false ;
}
V_2 -> V_64 = true ;
if ( V_2 -> V_245 > 0 ) {
if ( F_56 ( V_2 -> V_245 , V_2 -> V_8 ) < 0 ) {
F_8 ( L_127 , V_2 , V_2 -> V_245 ) ;
return false ;
}
F_57 ( V_2 -> V_245 , V_288 ) ;
F_58 ( V_2 -> V_245 ) ;
V_2 -> V_289 = true ;
}
return true ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_60 ( V_2 -> V_133 , V_2 ) ;
if ( V_2 -> V_289 )
F_61 ( V_2 -> V_245 ) ;
if ( V_2 -> V_290 )
F_10 ( V_2 -> V_32 , V_2 -> V_291 ,
V_2 -> V_290 , V_2 -> V_292 ) ;
F_62 ( V_2 -> V_32 ) ;
V_2 -> V_290 = NULL ;
V_2 -> V_292 = 0 ;
V_2 -> V_291 = 0 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_293 V_294 ;
enum V_295 V_296 ;
enum V_297 V_298 ;
int V_200 ;
V_2 -> V_299 = NULL ;
V_2 -> V_34 = NULL ;
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ ) {
V_2 -> V_300 [ V_200 ] = NULL ;
V_2 -> V_301 [ V_200 ] . V_302 = false ;
V_2 -> V_301 [ V_200 ] . V_303 = false ;
V_2 -> V_304 [ V_200 ] = 0 ;
V_2 -> V_305 [ V_200 ] = 0 ;
}
if ( F_5 ( V_2 ) )
goto V_70;
V_2 -> V_291 = V_2 -> V_257 * ( sizeof( struct V_306 ) + sizeof( struct V_307 ) ) ;
V_2 -> V_290 = F_7 ( V_2 -> V_32 ,
V_2 -> V_291 , & V_2 -> V_292 ) ;
if ( V_2 -> V_290 == NULL )
return F_42 ( V_2 , L_128 ) ;
V_2 -> V_308 = (struct V_306 * ) V_2 -> V_290 ;
V_2 -> V_309 = V_2 -> V_308 + V_2 -> V_257 - 1 ;
V_2 -> V_310 = V_2 -> V_308 ;
V_2 -> V_311 = (struct V_307 * ) ( V_2 -> V_309 + 1 ) ;
V_2 -> V_312 = V_2 -> V_311 + V_2 -> V_257 - 1 ;
V_2 -> V_313 = V_2 -> V_311 ;
memset ( V_2 -> V_308 , 0 ,
V_2 -> V_257 * sizeof( struct V_306 ) ) ;
memset ( V_2 -> V_311 , 0 ,
V_2 -> V_257 * sizeof( struct V_307 ) ) ;
V_294 . V_257 = V_2 -> V_257 ;
V_294 . V_314 = ( V_20 ) V_2 -> V_292 ;
if ( F_17 ( V_2 , V_315 , & V_294 ,
sizeof( V_294 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_129 ) ;
if ( V_2 -> V_256 ) {
V_296 = V_316 ;
if ( F_17 ( V_2 , V_317 , & V_296 ,
sizeof( V_296 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 ,
L_130 ) ;
}
if ( V_2 -> V_212 ) {
V_298 = V_318 ;
if ( F_17 ( V_2 , V_319 , & V_298 ,
sizeof( V_298 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_131 ) ;
}
V_70:
if ( ! V_2 -> V_320 ) {
F_52 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
F_52 ( L_17 , V_2 ) ;
} else
F_38 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
V_2 -> V_320 = true ;
return true ;
}
static bool T_2 F_64 ( struct V_1 * V_2 )
{
T_3 V_321 ;
T_4 V_322 [ 8 ] ;
struct V_191 V_192 ;
T_4 V_323 [ V_263 ] ;
unsigned char V_187 ;
int V_200 ;
F_65 ( V_2 -> V_272 ) ;
if ( F_5 ( V_2 ) )
return true ;
if ( V_2 -> V_265 != NULL && V_2 -> V_265 -> V_324 )
return true ;
if ( strcmp ( V_2 -> V_201 , L_133 ) >= 0 ) {
if ( F_17 ( V_2 , V_81 , NULL , 0 ,
& V_321 , sizeof( V_321 ) )
!= sizeof( V_321 ) )
return F_42 ( V_2 , L_134 ) ;
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_2 -> V_301 [ V_200 ] . V_325 =
( V_321 & ( 1 << V_200 ) ? true : false ) ;
} else {
if ( F_17 ( V_2 , V_79 , NULL , 0 ,
& V_322 , sizeof( V_322 ) )
!= sizeof( V_322 ) )
return F_42 ( V_2 ,
L_135 ) ;
for ( V_200 = 0 ; V_200 < 8 ; V_200 ++ )
V_2 -> V_301 [ V_200 ] . V_325 =
( V_322 [ V_200 ] != 0 ? true : false ) ;
}
V_187 = sizeof( V_192 ) ;
if ( F_17 ( V_2 , V_231 , & V_187 ,
sizeof( V_187 ) , & V_192 , sizeof( V_192 ) )
!= sizeof( V_192 ) )
return F_42 ( V_2 , L_63 ) ;
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_2 -> V_326 [ V_200 ] = ( V_200 < 8 ? V_192 . V_327 [ V_200 ] . V_14 : V_192 . V_328 [ V_200 - 8 ] . V_14 ) ;
if ( strcmp ( V_2 -> V_201 , L_136 ) >= 0 )
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_2 -> V_301 [ V_200 ] . V_329 = ( V_200 < 8 ? ( V_192 . V_330 & ( 1 << V_200 ) ? true : false ) : ( V_192 . V_331 & ( 1 << ( V_200 - 8 ) ) ? true : false ) ) ;
if ( V_2 -> V_201 [ 0 ] >= '3' ) {
V_187 = sizeof( V_323 ) ;
if ( F_17 ( V_2 , V_332 , & V_187 ,
sizeof( V_187 ) , & V_323 ,
sizeof( V_323 ) ) != sizeof( V_323 ) )
return F_42 ( V_2 ,
L_137 ) ;
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
V_2 -> V_323 [ V_200 ] = V_323 [ V_200 ] ;
} else
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
if ( V_192 . V_327 [ V_200 ] . V_14 > 0 )
V_2 -> V_323 [ V_200 ] = 20 + 5 * V_192 . V_327 [ V_200 ] . V_333 ;
return true ;
}
static void T_2 F_66 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
V_6 -> V_334 = V_2 -> V_220 ;
V_6 -> V_335 = V_2 -> V_221 ;
V_6 -> V_336 = 0 ;
V_6 -> V_337 = V_2 -> V_88 ;
V_6 -> V_338 = V_2 -> V_203 ;
V_6 -> V_41 = V_2 -> V_38 ;
V_6 -> V_339 = V_2 -> V_218 ;
V_6 -> V_340 = V_2 -> V_262 ;
V_6 -> V_341 = V_2 -> V_267 ;
}
static int F_67 ( struct V_342 * V_115 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_115 -> V_6 -> V_7 ;
int V_200 = V_115 -> V_151 ;
int V_264 = V_2 -> V_264 [ V_200 ] ;
if ( V_2 -> V_301 [ V_200 ] . V_228 &&
( V_2 -> V_228 & ( 1 << V_200 ) ) ) {
if ( V_264 == 0 )
V_264 = V_343 ;
V_2 -> V_264 [ V_200 ] = V_264 ;
F_68 ( V_115 , V_344 , V_264 ) ;
} else {
V_2 -> V_228 &= ~ ( 1 << V_200 ) ;
V_264 = V_2 -> V_267 ;
V_2 -> V_264 [ V_200 ] = V_264 ;
F_68 ( V_115 , 0 , V_264 ) ;
}
V_264 = 0 ;
for ( V_200 = 0 ; V_200 < V_2 -> V_220 ; V_200 ++ )
if ( V_2 -> V_301 [ V_200 ] . V_325 )
V_264 += V_2 -> V_264 [ V_200 ] ;
if ( V_264 > V_2 -> V_29 )
F_11 ( V_2 , V_264 - V_2 -> V_29 ,
false ) ;
return 0 ;
}
static int T_2 F_69 ( void )
{
int V_345 = 0 , V_346 = 0 , V_347 ;
struct V_1 * V_2 ;
int V_348 = 0 ;
#ifdef F_70
if ( V_349 )
F_71 ( V_349 ) ;
#endif
if ( V_98 . V_350 )
return - V_351 ;
V_93 =
F_72 ( V_92 * sizeof( struct V_89 ) ,
V_352 ) ;
if ( V_93 == NULL ) {
F_8 ( L_138 ,
NULL ) ;
return - V_353 ;
}
V_2 = F_72 ( sizeof( struct V_1 ) , V_352 ) ;
if ( V_2 == NULL ) {
F_73 ( V_93 ) ;
F_8 ( L_139 , NULL ) ;
return - V_353 ;
}
#ifdef F_70
if ( V_349 != NULL )
F_71 ( V_349 ) ;
#endif
F_41 ( V_2 ) ;
for ( V_347 = 0 ; V_347 < V_91 ; V_347 ++ ) {
struct V_89 * V_90 =
& V_93 [ V_347 ] ;
struct V_1 * V_166 = V_2 ;
struct V_5 * V_6 ;
if ( V_90 -> V_88 == 0 )
continue;
memset ( V_166 , 0 , sizeof( struct V_1 ) ) ;
V_166 -> V_94 = V_90 -> V_94 ;
V_166 -> V_96 = V_90 -> V_96 ;
V_166 -> V_88 = V_90 -> V_88 ;
V_166 -> V_136 = V_90 -> V_136 ;
V_166 -> V_114 = V_90 -> V_114 ;
V_166 -> V_115 = V_90 -> V_115 ;
V_166 -> V_32 = V_90 -> V_32 ;
V_166 -> V_133 = V_90 -> V_133 ;
V_166 -> V_354 =
V_355 [ V_166 -> V_94 ] ;
if ( ! F_74 ( V_166 -> V_88 , V_166 -> V_354 ,
L_140 ) )
continue;
if ( ! F_43 ( V_166 ) ) {
F_75 ( V_166 -> V_88 ,
V_166 -> V_354 ) ;
continue;
}
if ( ! F_46 ( V_166 , true ) ) {
F_75 ( V_166 -> V_88 ,
V_166 -> V_354 ) ;
continue;
}
if ( ! F_49 ( V_166 ) ) {
F_75 ( V_166 -> V_88 ,
V_166 -> V_354 ) ;
continue;
}
if ( V_346 < V_356 )
V_166 -> V_265 =
& V_357 [ V_346 ++ ] ;
F_1 ( V_166 ) ;
V_6 = F_76 ( & V_358 ,
sizeof( struct V_1 ) ) ;
if ( V_6 == NULL ) {
F_75 ( V_166 -> V_88 ,
V_166 -> V_354 ) ;
continue;
}
V_166 = (struct V_1 * ) V_6 -> V_7 ;
memcpy ( V_166 , V_2 , sizeof( struct V_1 ) ) ;
V_166 -> V_40 = V_6 ;
V_166 -> V_359 = V_6 -> V_359 ;
F_77 ( & V_166 -> V_360 , & V_361 ) ;
if ( F_50 ( V_166 ) &&
F_51 ( V_166 ) &&
F_54 ( V_166 ) &&
F_6 ( V_166 ) &&
F_63 ( V_166 ) &&
F_64 ( V_166 ) ) {
F_75 ( V_166 -> V_88 ,
V_166 -> V_354 ) ;
if ( ! F_74 ( V_166 -> V_88 ,
V_166 -> V_354 ,
V_166 -> V_8 ) ) {
F_78 ( V_362
L_141
L_142 ,
( unsigned long ) V_166 -> V_88 ) ;
F_9 ( V_166 ) ;
F_59 ( V_166 ) ;
F_79 ( & V_166 -> V_360 ) ;
F_80 ( V_6 ) ;
V_348 = - V_353 ;
} else {
F_66 ( V_166 ,
V_6 ) ;
if ( F_81 ( V_6 , V_166 -> V_32
? & V_166 -> V_32 -> V_115
: NULL ) ) {
F_78 ( V_362
L_143
L_144 ) ;
F_9 ( V_166 ) ;
F_59 ( V_166 ) ;
F_79 ( & V_166 -> V_360 ) ;
F_80 ( V_6 ) ;
V_348 = - V_351 ;
} else {
F_82 ( V_6 ) ;
V_345 ++ ;
}
}
} else {
F_9 ( V_166 ) ;
F_59 ( V_166 ) ;
F_79 ( & V_166 -> V_360 ) ;
F_80 ( V_6 ) ;
V_348 = - V_351 ;
}
}
F_73 ( V_2 ) ;
F_73 ( V_93 ) ;
V_93 = NULL ;
return V_348 ;
}
static int T_5 F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_40 ;
F_84 ( V_6 ) ;
if ( F_5 ( V_2 ) )
F_85 ( V_2 -> V_182 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_75 ( V_2 -> V_88 , V_2 -> V_354 ) ;
F_79 ( & V_2 -> V_360 ) ;
F_80 ( V_6 ) ;
return 0 ;
}
static void V_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
V_13 -> V_17 = V_363 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_299 == NULL ) {
V_2 -> V_299 = V_13 ;
V_2 -> V_34 = V_13 ;
} else {
V_2 -> V_34 -> V_25 = V_13 ;
V_2 -> V_34 = V_13 ;
}
V_2 -> V_304 [ V_13 -> V_200 ] -- ;
}
static int F_86 ( struct V_1 * V_2 ,
enum V_364 V_365 ,
enum V_366 V_367 )
{
int V_368 ;
switch ( V_365 ) {
case V_369 :
case V_370 :
case V_371 :
V_368 = V_372 ;
break;
case V_373 :
V_368 = V_374 ;
break;
case V_375 :
case V_376 :
case V_377 :
F_38 ( L_145 ,
V_2 , V_365 ) ;
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
case V_390 :
V_368 = V_391 ;
break;
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
V_368 = V_397 ;
break;
default:
F_38 ( L_146 , V_2 ,
V_365 ) ;
V_368 = V_391 ;
break;
}
return ( V_368 << 16 ) | V_367 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_307 * V_313 = V_2 -> V_313 ;
enum V_398 V_399 ;
while ( ( V_399 = V_313 -> V_399 ) != V_400 ) {
struct V_12 * V_13 =
(struct V_12 * ) F_88 ( V_313 -> V_13 ) ;
if ( V_399 != V_401 ) {
if ( V_13 -> V_17 == V_402 ||
V_13 -> V_17 == V_403 ) {
V_13 -> V_399 = V_399 ;
V_22 ( V_13 ) ;
} else {
F_38 ( L_147 L_148 , V_2 , V_13 -> V_42 , V_13 -> V_17 ) ;
}
}
V_313 -> V_399 = V_400 ;
if ( ++ V_313 > V_2 -> V_312 )
V_313 = V_2 -> V_311 ;
}
V_2 -> V_313 = V_313 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_404 )
return;
V_2 -> V_404 = true ;
while ( V_2 -> V_299 != NULL ) {
struct V_12 * V_13 = V_2 -> V_299 ;
struct V_405 * V_44 = V_13 -> V_44 ;
V_2 -> V_299 = V_13 -> V_25 ;
if ( V_2 -> V_299 == NULL )
V_2 -> V_34 = NULL ;
if ( V_13 -> V_49 == V_406 ) {
int V_200 = V_13 -> V_200 ;
F_38 ( L_149 L_150 , V_2 , V_13 -> V_42 , V_200 ) ;
F_90 ( & V_2 -> V_407 [ V_200 ] . V_408 ) ;
V_2 -> V_301 [ V_200 ] . V_302 = false ;
V_2 -> V_305 [ V_200 ] = 0 ;
V_2 -> V_409 [ V_200 ] = V_410 ;
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
if ( V_13 -> V_17 == V_403 &&
V_13 -> V_200 == V_200 ) {
V_44 = V_13 -> V_44 ;
F_14 ( V_13 ) ;
V_2 -> V_304 [ V_200 ] -- ;
V_44 -> V_62 = V_397 << 16 ;
V_44 -> V_411 ( V_44 ) ;
}
V_2 -> V_300 [ V_200 ] = NULL ;
} else {
switch ( V_13 -> V_399 ) {
case V_400 :
case V_401 :
case V_412 :
F_38 ( L_151 , V_2 , V_13 -> V_42 , V_13 -> V_200 ) ;
break;
case V_413 :
V_2 -> V_407 [ V_13 -> V_200 ]
. V_414 ++ ;
V_2 -> V_301 [ V_13 -> V_200 ]
. V_303 = true ;
V_44 -> V_62 = V_372 << 16 ;
break;
case V_415 :
F_38 ( L_152 ,
V_2 , V_13 -> V_42 , V_13 -> V_200 ) ;
F_90 ( & V_2 -> V_407 [ V_13 -> V_200 ] . V_416 ) ;
V_44 -> V_62 = V_417 << 16 ;
break;
case V_418 :
V_44 -> V_62 = F_86 ( V_2 ,
V_13 -> V_365 , V_13 -> V_367 ) ;
if ( V_13 -> V_365 != V_373 ) {
V_2 -> V_407 [ V_13 -> V_200 ]
. V_414 ++ ;
if ( V_77 . V_419 ) {
int V_83 ;
F_12 ( L_153
L_154 L_155 , V_2 , V_13 -> V_42 , V_13 -> V_200 , V_44 -> V_62 , V_13 -> V_365 , V_13 -> V_367 ) ;
F_12 ( L_156 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_420 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_13 -> V_421 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
F_12 ( L_157 , V_2 ) ;
for ( V_83 = 0 ; V_83 < V_13 -> V_46 ; V_83 ++ )
F_12 ( L_16 , V_2 , V_44 -> V_422 [ V_83 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
}
break;
}
if ( V_13 -> V_421 [ 0 ] == V_423 && V_13 -> V_421 [ 1 ] == 0 &&
V_13 -> V_365 == V_369 ) {
struct V_424 * V_301 =
& V_2 -> V_301 [ V_13 -> V_200 ] ;
struct V_425 * V_426 =
(struct V_425 * ) F_91 ( V_44 ) ;
V_301 -> V_325 = true ;
V_301 -> V_228 = V_426 -> V_427 ;
V_301 -> V_226 = V_426 -> V_428 ;
}
F_14 ( V_13 ) ;
V_44 -> V_411 ( V_44 ) ;
}
}
V_2 -> V_404 = false ;
}
static T_6 V_286 ( int V_133 , void * V_429 )
{
struct V_1 * V_2 = (struct V_1 * ) V_429 ;
unsigned long V_60 ;
F_92 ( V_2 -> V_40 -> V_430 , V_60 ) ;
if ( F_53 ( V_2 ) ) {
union V_58 V_59 ;
V_59 . V_65 = F_22 ( V_2 ) ;
if ( V_59 . V_72 . V_431 ) {
F_24 ( V_2 ) ;
if ( V_59 . V_72 . V_432 )
V_2 -> V_433 = true ;
else if ( V_59 . V_72 . V_434 )
F_87 ( V_2 ) ;
else if ( V_59 . V_72 . V_73 )
V_2 -> V_71 = true ;
}
} else {
if ( F_93 ( V_2 -> V_182 ) )
switch ( F_94 ( V_2 -> V_182 ) ) {
case V_435 :
break;
case V_436 :
V_2 -> V_433 = true ;
break;
case V_437 :
F_38 ( L_158 , V_2 ) ;
V_2 -> V_438 = true ;
break;
}
}
if ( V_2 -> V_299 != NULL )
F_89 ( V_2 ) ;
if ( V_2 -> V_433 ) {
F_38 ( L_159 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_439 ) ;
F_95 ( V_2 , false ) ;
V_2 -> V_433 = false ;
} else if ( V_2 -> V_438 ) {
F_38 ( L_160 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_440 ) ;
F_95 ( V_2 , true ) ;
V_2 -> V_438 = false ;
}
F_96 ( V_2 -> V_40 -> V_430 , V_60 ) ;
return V_441 ;
}
static bool F_97 ( struct V_1 * V_2 ,
enum V_442 V_443 , struct V_12 * V_13 )
{
struct V_306 * V_310 ;
V_310 = V_2 -> V_310 ;
if ( V_310 -> V_443 == V_444 ) {
V_13 -> V_17 = V_402 ;
V_310 -> V_13 = V_13 -> V_19 ;
V_310 -> V_443 = V_443 ;
F_98 ( V_2 ) ;
if ( ++ V_310 > V_2 -> V_309 )
V_310 = V_2 -> V_308 ;
V_2 -> V_310 = V_310 ;
if ( V_443 == V_445 ) {
V_2 -> V_304 [ V_13 -> V_200 ] ++ ;
if ( V_13 -> V_49 != V_406 )
V_2 -> V_407 [ V_13 -> V_200 ] . V_446 ++ ;
}
return true ;
}
return false ;
}
static int F_99 ( struct V_405 * V_447 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_447 -> V_132 -> V_6 -> V_7 ;
unsigned int V_151 = V_447 -> V_132 -> V_151 ;
struct V_448 * V_449 = & V_2 -> V_407 [ V_151 ] ;
int V_450 ;
F_100 ( V_447 -> V_132 -> V_6 -> V_430 ) ;
F_90 ( & V_449 -> V_451 ) ;
V_450 = F_95 ( V_2 , false ) ;
F_101 ( V_447 -> V_132 -> V_6 -> V_430 ) ;
return V_450 ;
}
static int F_102 ( struct V_405 * V_44 ,
void (* F_103) ( struct V_405 * ) )
{
struct V_1 * V_2 =
(struct V_1 * ) V_44 -> V_132 -> V_6 -> V_7 ;
struct V_424 * V_301 =
& V_2 -> V_301 [ V_44 -> V_132 -> V_151 ] ;
struct V_448 * V_407 = V_2 -> V_407 ;
unsigned char * V_421 = V_44 -> V_452 ;
int V_420 = V_44 -> V_453 ;
int V_200 = V_44 -> V_132 -> V_151 ;
int V_454 = V_44 -> V_132 -> V_454 ;
int V_455 = F_104 ( V_44 ) ;
int V_153 ;
struct V_12 * V_13 ;
if ( V_421 [ 0 ] == V_456 && V_44 -> V_422 [ 0 ] != 0 ) {
V_44 -> V_62 = V_372 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
F_101 ( V_2 -> V_40 -> V_430 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_430 ) ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
V_44 -> V_62 = V_391 << 16 ;
F_103 ( V_44 ) ;
return 0 ;
}
}
V_153 = F_105 ( V_44 ) ;
F_106 ( V_153 < 0 ) ;
if ( V_153 ) {
struct V_457 * V_458 ;
int V_83 ;
V_13 -> V_49 = V_459 ;
V_13 -> V_460 = V_153 * sizeof( struct V_461 ) ;
if ( F_53 ( V_2 ) )
V_13 -> V_462 = ( void * ) ( ( unsigned int ) V_13 -> V_19 +
( ( unsigned long ) & V_13 -> V_463 -
( unsigned long ) V_13 ) ) ;
else
V_13 -> V_462 = V_13 -> V_463 ;
F_107 (command, sg, count, i) {
V_13 -> V_463 [ V_83 ] . V_464 = F_108 ( V_458 ) ;
V_13 -> V_463 [ V_83 ] . V_465 = F_109 ( V_458 ) ;
}
} else if ( ! V_153 ) {
V_13 -> V_49 = V_466 ;
V_13 -> V_460 = V_455 ;
V_13 -> V_462 = 0 ;
}
switch ( V_421 [ 0 ] ) {
case V_467 :
case V_468 :
V_13 -> V_469 = V_470 ;
V_407 [ V_200 ] . V_471 ++ ;
F_110 ( & V_407 [ V_200 ] . V_472 , V_455 ) ;
F_111 ( V_407 [ V_200 ] . V_473 , V_455 ) ;
break;
case V_474 :
case V_475 :
V_13 -> V_469 = V_476 ;
V_407 [ V_200 ] . V_477 ++ ;
F_110 ( & V_407 [ V_200 ] . V_478 , V_455 ) ;
F_111 ( V_407 [ V_200 ] . V_479 , V_455 ) ;
break;
default:
V_13 -> V_469 = V_480 ;
break;
}
V_13 -> V_420 = V_420 ;
V_13 -> V_365 = 0 ;
V_13 -> V_367 = 0 ;
V_13 -> V_200 = V_200 ;
V_13 -> V_454 = V_454 ;
V_13 -> V_481 = false ;
V_13 -> V_482 = false ;
if ( V_2 -> V_305 [ V_200 ] ++ >= V_483 &&
! V_301 -> V_302 &&
V_2 -> V_304 [ V_200 ] == 0
&& V_301 -> V_228 &&
( V_2 -> V_228 & ( 1 << V_200 ) ) ) {
V_301 -> V_302 = true ;
F_12 ( L_161 ,
V_2 , V_200 ) ;
}
if ( V_301 -> V_302 ) {
enum V_484 V_485 = V_486 ;
if ( V_2 -> V_304 [ V_200 ] == 0 )
V_2 -> V_487 [ V_200 ] = V_410 ;
else if ( F_112 ( V_410 ,
V_2 -> V_487 [ V_200 ] + 4 * V_488 ) ) {
V_2 -> V_487 [ V_200 ] = V_410 ;
V_485 = V_489 ;
}
if ( V_2 -> V_212 ) {
V_13 -> V_481 = true ;
V_13 -> V_485 = V_485 ;
} else {
V_13 -> V_482 = true ;
V_13 -> V_490 = V_485 ;
}
}
memcpy ( V_13 -> V_421 , V_421 , V_420 ) ;
V_13 -> V_46 = V_491 ;
V_13 -> V_45 = F_113 ( V_2 -> V_32 ,
V_44 -> V_422 , V_13 -> V_46 ,
V_47 ) ;
V_13 -> V_44 = V_44 ;
V_44 -> V_411 = F_103 ;
if ( F_53 ( V_2 ) ) {
if ( ! F_97 ( V_2 , V_445 , V_13 ) ) {
F_101 ( V_2 -> V_40 -> V_430 ) ;
F_38 ( L_162 L_163 , V_2 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_430 ) ;
if ( ! F_97 ( V_2 , V_445 ,
V_13 ) ) {
F_38 ( L_164 L_165 , V_2 ) ;
F_14 ( V_13 ) ;
V_44 -> V_62 = V_391 << 16 ;
V_44 -> V_411 ( V_44 ) ;
}
}
} else {
V_13 -> V_17 = V_402 ;
V_2 -> V_304 [ V_200 ] ++ ;
V_407 [ V_200 ] . V_446 ++ ;
F_114 ( V_2 -> V_182 , V_13 ) ;
if ( V_13 -> V_17 == V_363 )
F_89 ( V_2 ) ;
}
return 0 ;
}
int F_115 ( struct V_342 * V_492 , struct V_493 * V_115 ,
T_7 V_494 , int * V_495 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_492 -> V_6 -> V_7 ;
struct V_496 * V_497 = (struct V_496 * ) V_495 ;
unsigned char * V_498 ;
if ( V_2 -> V_204 && V_494 >= 2 * 1024 * 1024 ) {
if ( V_494 >= 4 * 1024 * 1024 ) {
V_497 -> V_499 = 255 ;
V_497 -> V_500 = 63 ;
} else {
V_497 -> V_499 = 128 ;
V_497 -> V_500 = 32 ;
}
} else {
V_497 -> V_499 = 64 ;
V_497 -> V_500 = 32 ;
}
V_497 -> V_501 = ( unsigned long ) V_494 / ( V_497 -> V_499 * V_497 -> V_500 ) ;
V_498 = F_116 ( V_115 ) ;
if ( V_498 == NULL )
return 0 ;
if ( * ( unsigned short * ) ( V_498 + 64 ) == 0xAA55 ) {
struct V_502 * V_503 = (struct V_502 * ) V_498 ;
struct V_502 * V_504 = V_503 ;
int V_505 = V_497 -> V_501 , V_506 ;
unsigned char V_507 = 0 , V_508 = 0 ;
for ( V_506 = 0 ; V_506 < 4 ; V_506 ++ ) {
V_507 = V_504 -> V_509 ;
V_508 = V_504 -> V_510 & 0x3F ;
if ( V_507 == 64 - 1 ) {
V_497 -> V_499 = 64 ;
V_497 -> V_500 = 32 ;
break;
} else if ( V_507 == 128 - 1 ) {
V_497 -> V_499 = 128 ;
V_497 -> V_500 = 32 ;
break;
} else if ( V_507 == 255 - 1 ) {
V_497 -> V_499 = 255 ;
V_497 -> V_500 = 63 ;
break;
}
V_504 ++ ;
}
if ( V_506 == 4 ) {
V_507 = V_503 -> V_509 ;
V_508 = V_503 -> V_510 & 0x3F ;
}
V_497 -> V_501 = ( unsigned long ) V_494 / ( V_497 -> V_499 * V_497 -> V_500 ) ;
if ( V_506 < 4 && V_508 == V_497 -> V_500 ) {
if ( V_497 -> V_501 != V_505 )
F_38 ( L_166 , V_2 , V_497 -> V_499 , V_497 -> V_500 ) ;
} else if ( V_507 > 0 || V_508 > 0 ) {
F_38 ( L_167 L_168 , V_2 , V_507 + 1 , V_508 ) ;
F_38 ( L_169 L_170 , V_2 , V_497 -> V_499 , V_497 -> V_500 ) ;
}
}
F_73 ( V_498 ) ;
return 0 ;
}
static int F_117 ( struct V_5 * V_511 , char * V_512 ,
int V_513 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_511 -> V_7 ;
struct V_448 * V_407 ;
V_407 = V_2 -> V_407 ;
V_2 -> V_439 = 0 ;
V_2 -> V_440 = 0 ;
memset ( V_407 , 0 , V_263 * sizeof( struct V_448 ) ) ;
return 0 ;
}
static int F_118 ( struct V_514 * V_515 , struct V_5 * V_511 )
{
struct V_1 * V_2 = (struct V_1 * ) V_511 -> V_7 ;
struct V_448 * V_407 ;
int V_198 ;
V_407 = V_2 -> V_407 ;
F_119 ( V_515 , V_2 -> V_516 , V_2 -> V_517 ) ;
F_120 ( V_515 , L_171 , V_2 -> V_38 , V_2 -> V_29 ) ;
F_120 ( V_515 , L_172 ) ;
for ( V_198 = 0 ; V_198 < V_2 -> V_220 ; V_198 ++ ) {
struct V_424 * V_301 = & V_2 -> V_301 [ V_198 ] ;
if ( ! V_301 -> V_325 )
continue;
F_120 ( V_515 , L_173 , V_198 , ( V_301 -> V_228 ? ( V_301 -> V_302 ? L_174 : ( V_2 -> V_228 & ( 1 << V_198 )
? L_175 : L_176 ) )
: L_177 ) ) ;
F_120 ( V_515 ,
L_178 , V_2 -> V_264 [ V_198 ] , V_2 -> V_304 [ V_198 ] , V_407 [ V_198 ] . V_446 , V_407 [ V_198 ] . V_414 ) ;
}
F_120 ( V_515 , L_179 ) ;
for ( V_198 = 0 ; V_198 < V_2 -> V_220 ; V_198 ++ ) {
struct V_424 * V_301 = & V_2 -> V_301 [ V_198 ] ;
if ( ! V_301 -> V_325 )
continue;
F_120 ( V_515 , L_180 , V_198 , V_407 [ V_198 ] . V_471 , V_407 [ V_198 ] . V_477 ) ;
if ( V_407 [ V_198 ] . V_472 . V_518 > 0 )
F_120 ( V_515 , L_181 , V_407 [ V_198 ] . V_472 . V_518 , V_407 [ V_198 ] . V_472 . V_519 ) ;
else
F_120 ( V_515 , L_182 , V_407 [ V_198 ] . V_472 . V_519 ) ;
if ( V_407 [ V_198 ] . V_478 . V_518 > 0 )
F_120 ( V_515 , L_183 , V_407 [ V_198 ] . V_478 . V_518 , V_407 [ V_198 ] . V_478 . V_519 ) ;
else
F_120 ( V_515 , L_184 , V_407 [ V_198 ] . V_478 . V_519 ) ;
}
F_120 ( V_515 , L_185 ) ;
for ( V_198 = 0 ; V_198 < V_2 -> V_220 ; V_198 ++ ) {
struct V_424 * V_301 = & V_2 -> V_301 [ V_198 ] ;
if ( ! V_301 -> V_325 )
continue;
F_120 ( V_515 ,
L_186 , V_198 ,
V_407 [ V_198 ] . V_473 [ 0 ] ,
V_407 [ V_198 ] . V_473 [ 1 ] , V_407 [ V_198 ] . V_473 [ 2 ] , V_407 [ V_198 ] . V_473 [ 3 ] , V_407 [ V_198 ] . V_473 [ 4 ] ) ;
F_120 ( V_515 ,
L_187 , V_198 ,
V_407 [ V_198 ] . V_479 [ 0 ] ,
V_407 [ V_198 ] . V_479 [ 1 ] , V_407 [ V_198 ] . V_479 [ 2 ] , V_407 [ V_198 ] . V_479 [ 3 ] , V_407 [ V_198 ] . V_479 [ 4 ] ) ;
}
F_120 ( V_515 , L_188 ) ;
for ( V_198 = 0 ; V_198 < V_2 -> V_220 ; V_198 ++ ) {
struct V_424 * V_301 = & V_2 -> V_301 [ V_198 ] ;
if ( ! V_301 -> V_325 )
continue;
F_120 ( V_515 ,
L_186 , V_198 ,
V_407 [ V_198 ] . V_473 [ 5 ] ,
V_407 [ V_198 ] . V_473 [ 6 ] , V_407 [ V_198 ] . V_473 [ 7 ] , V_407 [ V_198 ] . V_473 [ 8 ] , V_407 [ V_198 ] . V_473 [ 9 ] ) ;
F_120 ( V_515 ,
L_187 , V_198 ,
V_407 [ V_198 ] . V_479 [ 5 ] ,
V_407 [ V_198 ] . V_479 [ 6 ] , V_407 [ V_198 ] . V_479 [ 7 ] , V_407 [ V_198 ] . V_479 [ 8 ] , V_407 [ V_198 ] . V_479 [ 9 ] ) ;
}
F_120 ( V_515 , L_189 ) ;
for ( V_198 = 0 ; V_198 < V_2 -> V_220 ; V_198 ++ ) {
struct V_424 * V_301 = & V_2 -> V_301 [ V_198 ] ;
if ( ! V_301 -> V_325 )
continue;
F_120 ( V_515 , L_190 , V_198 , V_407 [ V_198 ] . V_520 , V_407 [ V_198 ] . V_521 , V_407 [ V_198 ] . V_416 , V_407 [ V_198 ] . V_522 , V_407 [ V_198 ] . V_523 , V_407 [ V_198 ] . V_408 , V_407 [ V_198 ] . V_451 , V_407 [ V_198 ] . V_524 , V_407 [ V_198 ] . V_525 ) ;
}
F_120 ( V_515 , L_191 , V_2 -> V_439 ) ;
F_120 ( V_515 , L_192 , V_2 -> V_440 ) ;
return 0 ;
}
static void F_121 ( enum V_526 V_527 , char * V_528 ,
struct V_1 * V_2 , ... )
{
static char V_498 [ V_529 ] ;
static bool V_530 = true ;
T_8 args ;
int V_531 = 0 ;
va_start ( args , V_2 ) ;
V_531 = vsprintf ( V_498 , V_528 , args ) ;
va_end ( args ) ;
if ( V_527 == V_532 ) {
static int V_533 = 0 ;
strcpy ( & V_2 -> V_516 [ V_2 -> V_517 ] , V_498 ) ;
V_2 -> V_517 += V_531 ;
if ( ++ V_533 <= 2 )
F_78 ( L_193 , V_534 [ V_527 ] , V_498 ) ;
} else if ( V_527 == V_535 ) {
strcpy ( & V_2 -> V_516 [ V_2 -> V_517 ] , V_498 ) ;
V_2 -> V_517 += V_531 ;
if ( V_530 ) {
if ( V_498 [ 0 ] != '\n' || V_531 > 1 )
F_78 ( L_194 , V_534 [ V_527 ] , V_2 -> V_359 , V_498 ) ;
} else
F_78 ( L_195 , V_498 ) ;
} else {
if ( V_530 ) {
if ( V_2 != NULL && V_2 -> V_320 )
F_78 ( L_194 , V_534 [ V_527 ] , V_2 -> V_359 , V_498 ) ;
else
F_78 ( L_196 , V_534 [ V_527 ] , V_498 ) ;
} else
F_78 ( L_195 , V_498 ) ;
}
V_530 = ( V_498 [ V_531 - 1 ] == '\n' ) ;
}
static bool T_2 F_122 ( char * * V_536 , char * V_537 )
{
char * V_538 = * V_536 ;
while ( * V_537 != '\0' ) {
char V_539 = * V_538 ++ ;
char V_540 = * V_537 ++ ;
if ( V_539 >= 'A' && V_539 <= 'Z' )
V_539 += 'a' - 'Z' ;
if ( V_540 >= 'A' && V_540 <= 'Z' )
V_540 += 'a' - 'Z' ;
if ( V_539 != V_540 )
return false ;
}
* V_536 = V_538 ;
return true ;
}
static int T_2 F_123 ( char * V_541 )
{
while ( true ) {
struct V_357 * V_265 =
& V_357 [ V_356 ++ ] ;
int V_200 ;
memset ( V_265 , 0 , sizeof( struct V_357 ) ) ;
while ( * V_541 != '\0' && * V_541 != ';' ) {
if ( F_122 ( & V_541 , L_197 ) ) {
unsigned long V_88 = F_124 ( V_541 ,
& V_541 , 0 ) ;
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
} else if ( F_122 ( & V_541 , L_200 ) )
V_98 . V_99 = true ;
else if ( F_122 ( & V_541 , L_201 ) )
V_98 . V_163 = true ;
else if ( F_122 ( & V_541 , L_202 ) )
V_98 . V_350 = true ;
else if ( F_122 ( & V_541 , L_203 ) )
V_98 . V_542 = true ;
else if ( F_122 ( & V_541 , L_204 ) )
V_98 . V_164 = true ;
else if ( F_122 ( & V_541 , L_205 ) )
V_98 . V_165 = true ;
else if ( F_122 ( & V_541 , L_206 ) ||
F_122 ( & V_541 , L_207 ) ) {
for ( V_200 = 0 ; V_200 < V_263 ; V_200 ++ ) {
unsigned short V_264 = F_124 ( V_541 , & V_541 , 0 ) ;
if ( V_264 > V_483 ) {
F_8 ( L_198 L_208 , NULL , V_264 ) ;
return 0 ;
}
V_265 -> V_264 [ V_200 ] = V_264 ;
if ( * V_541 == ',' )
V_541 ++ ;
else if ( * V_541 == ']' )
break;
else {
F_8 ( L_198 L_209 , NULL , V_541 ) ;
return 0 ;
}
}
if ( * V_541 != ']' ) {
F_8 ( L_198 L_210 , NULL , V_541 ) ;
return 0 ;
} else
V_541 ++ ;
} else if ( F_122 ( & V_541 , L_211 ) || F_122 ( & V_541 , L_212 ) ) {
unsigned short V_264 = F_124 ( V_541 , & V_541 , 0 ) ;
if ( V_264 == 0 ||
V_264 > V_483 ) {
F_8 ( L_198 L_208 , NULL , V_264 ) ;
return 0 ;
}
V_265 -> V_270 = V_264 ;
for ( V_200 = 0 ; V_200 < V_263 ; V_200 ++ )
V_265 -> V_264 [ V_200 ] = V_264 ;
} else if ( F_122 ( & V_541 , L_213 ) ||
F_122 ( & V_541 , L_214 ) ) {
if ( F_122 ( & V_541 , L_215 ) ) {
V_265 -> V_228 = 0x0000 ;
V_265 -> V_271 = 0x0000 ;
} else if ( F_122 ( & V_541 , L_216 ) ) {
V_265 -> V_228 = 0xFFFF ;
V_265 -> V_271 = 0xFFFF ;
} else if ( F_122 ( & V_541 , L_217 ) ) {
V_265 -> V_228 = 0x0000 ;
V_265 -> V_271 = 0xFFFF ;
} else {
unsigned short V_543 ;
for ( V_200 = 0 , V_543 = 1 ;
V_200 < V_263 ;
V_200 ++ , V_543 <<= 1 )
switch ( * V_541 ++ ) {
case 'Y' :
V_265 -> V_228 |= V_543 ;
V_265 -> V_271 |= V_543 ;
break;
case 'N' :
V_265 -> V_228 &= ~ V_543 ;
V_265 -> V_271 |= V_543 ;
break;
case 'X' :
break;
default:
V_541 -- ;
V_200 = V_263 ;
break;
}
}
}
else if ( F_122 ( & V_541 , L_218 ) ||
F_122 ( & V_541 , L_219 ) ) {
unsigned short V_272 =
F_124 ( V_541 , & V_541 , 0 ) ;
if ( V_272 > 5 * 60 ) {
F_8 ( L_198 L_220 , NULL , V_272 ) ;
return 0 ;
}
V_265 -> V_272 = V_272 ;
} else if ( F_122 ( & V_541 ,
L_221 ) )
V_265 -> V_324 = true ;
else if ( F_122 ( & V_541 , L_222 ) )
V_77 . V_142 = true ;
else if ( F_122 ( & V_541 , L_223 ) )
V_77 . V_184 = true ;
else if ( F_122 ( & V_541 , L_224 ) )
V_77 . V_78 = true ;
else if ( F_122 ( & V_541 , L_225 ) )
V_77 . V_419 = true ;
else if ( F_122 ( & V_541 , L_226 ) ) {
V_77 . V_142 = true ;
V_77 . V_184 = true ;
V_77 . V_78 = true ;
V_77 . V_419 = true ;
}
if ( * V_541 == ',' )
V_541 ++ ;
else if ( * V_541 != ';' && * V_541 != '\0' ) {
F_8 ( L_227 L_228 , NULL , V_541 ) ;
* V_541 = '\0' ;
}
}
if ( ! ( V_356 == 0 ||
V_91 == 0 ||
V_356 == V_91 ) ) {
F_8 ( L_198 L_229 , NULL ) ;
return 0 ;
}
for ( V_200 = 0 ; V_200 < V_263 ; V_200 ++ )
if ( V_265 -> V_264 [ V_200 ] == 1 ) {
unsigned short V_543 = 1 << V_200 ;
V_265 -> V_228 &= ~ V_543 ;
V_265 -> V_271 |= V_543 ;
}
if ( * V_541 == ';' )
V_541 ++ ;
if ( * V_541 == '\0' )
return 0 ;
}
return 1 ;
}
static int T_2 F_71 ( char * V_536 )
{
int V_544 [ 3 ] ;
( void ) F_125 ( V_536 , F_126 ( V_544 ) , V_544 ) ;
if ( V_544 [ 0 ] != 0 ) {
F_8 ( L_230 L_231 , NULL ) ;
return 0 ;
}
if ( V_536 == NULL || * V_536 == '\0' )
return 0 ;
return F_123 ( V_536 ) ;
}
static void T_5 F_127 ( void )
{
struct V_1 * V_545 , * V_25 ;
F_128 (ha, next, &blogic_host_list, host_list)
F_83 ( V_545 ) ;
}
