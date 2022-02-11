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
static void F_14 ( struct V_12 * V_13 , int V_44 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_13 -> V_45 != NULL )
F_15 ( V_13 -> V_45 ) ;
if ( V_44 )
F_16 ( V_2 -> V_32 , V_13 -> V_46 ,
V_13 -> V_47 , V_48 ) ;
V_13 -> V_45 = NULL ;
V_13 -> V_17 = V_18 ;
V_13 -> V_25 = V_2 -> V_26 ;
V_2 -> V_26 = V_13 ;
}
static int F_17 ( struct V_1 * V_2 , enum V_49 V_50 ,
void * V_51 , int V_52 , void * V_53 , int V_54 )
{
unsigned char * V_55 = ( unsigned char * ) V_51 ;
unsigned char * V_56 = ( unsigned char * ) V_53 ;
union V_57 V_58 ;
union V_59 V_60 ;
unsigned long V_61 = 0 ;
int V_62 = 0 , V_63 ;
long V_64 ;
if ( V_54 > 0 )
memset ( V_53 , 0 , V_54 ) ;
if ( ! V_2 -> V_65 )
F_18 ( V_61 ) ;
V_64 = 10000 ;
while ( -- V_64 >= 0 ) {
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_58 . V_67 . V_68 && ! V_58 . V_67 . V_69 )
break;
F_20 ( 100 ) ;
}
if ( V_64 < 0 ) {
V_70 =
L_9 ;
V_63 = - 2 ;
goto V_71;
}
V_2 -> V_72 = false ;
F_21 ( V_2 , V_50 ) ;
V_64 = 10000 ;
while ( V_52 > 0 && -- V_64 >= 0 ) {
F_20 ( 100 ) ;
V_60 . V_66 = F_22 ( V_2 ) ;
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_60 . V_73 . V_74 )
break;
if ( V_2 -> V_72 )
break;
if ( V_58 . V_67 . V_75 )
break;
if ( V_58 . V_67 . V_69 )
continue;
F_21 ( V_2 , * V_55 ++ ) ;
V_52 -- ;
}
if ( V_64 < 0 ) {
V_70 =
L_10 ;
V_63 = - 2 ;
goto V_71;
}
if ( V_50 == V_76 ) {
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_58 . V_67 . V_77 ) {
V_70 =
L_11 ;
V_63 = - 1 ;
goto V_71;
}
if ( V_78 . V_79 )
F_12 ( L_12 L_13 , V_2 , V_50 , V_58 . V_66 ) ;
V_63 = 0 ;
goto V_71;
}
switch ( V_50 ) {
case V_80 :
case V_81 :
case V_82 :
V_64 = 60 * 10000 ;
break;
default:
V_64 = 10000 ;
break;
}
while ( -- V_64 >= 0 ) {
V_60 . V_66 = F_22 ( V_2 ) ;
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_60 . V_73 . V_74 )
break;
if ( V_2 -> V_72 )
break;
if ( V_58 . V_67 . V_75 ) {
if ( ++ V_62 <= V_54 )
* V_56 ++ = F_23 ( V_2 ) ;
else
F_23 ( V_2 ) ;
}
if ( V_50 == V_83 &&
V_58 . V_67 . V_68 )
break;
F_20 ( 100 ) ;
}
if ( V_64 < 0 ) {
V_70 =
L_14 ;
V_63 = - 2 ;
goto V_71;
}
F_24 ( V_2 ) ;
if ( V_78 . V_79 ) {
int V_84 ;
F_12 ( L_15 ,
V_2 , V_50 , V_58 . V_66 , V_54 ,
V_62 ) ;
if ( V_54 > V_62 )
V_54 = V_62 ;
for ( V_84 = 0 ; V_84 < V_54 ; V_84 ++ )
F_12 ( L_16 , V_2 ,
( ( unsigned char * ) V_53 ) [ V_84 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
if ( V_58 . V_67 . V_77 ) {
F_20 ( 1000 ) ;
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_58 . V_67 . V_77 || V_58 . V_67 . V_85 ||
V_58 . V_67 . V_75 ||
V_58 . V_67 . V_69 ||
! V_58 . V_67 . V_68 ||
! V_58 . V_67 . V_86 ||
V_58 . V_67 . V_87 ||
V_58 . V_67 . V_88 ) {
F_25 ( V_2 ) ;
F_20 ( 1000 ) ;
}
V_70 = L_18 ;
V_63 = - 1 ;
goto V_71;
}
if ( V_52 > 0 ) {
V_70 = L_19 ;
V_63 = - 1 ;
goto V_71;
}
V_70 = NULL ;
V_63 = V_62 ;
V_71:
if ( ! V_2 -> V_65 )
F_26 ( V_61 ) ;
return V_63 ;
}
static void T_2 F_27 ( unsigned long V_89 )
{
struct V_90 * V_91 ;
if ( V_92 >= V_93 )
return;
V_91 = & V_94 [ V_92 ++ ] ;
V_91 -> V_95 = V_96 ;
V_91 -> V_97 = V_98 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_32 = NULL ;
}
static void T_2 F_28 ( struct V_1 * V_2 )
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
static void T_2 F_29 ( struct V_90
* V_108 , int V_109 )
{
int V_110 = V_109 - 1 , V_111 , V_112 ;
while ( V_110 > 0 ) {
V_111 = V_110 ;
V_110 = 0 ;
for ( V_112 = 0 ; V_112 < V_111 ; V_112 ++ ) {
struct V_90 * V_113 =
& V_108 [ V_112 ] ;
struct V_90 * V_114 =
& V_108 [ V_112 + 1 ] ;
if ( V_113 -> V_115 > V_114 -> V_115 ||
( V_113 -> V_115 == V_114 -> V_115 &&
( V_113 -> V_116 > V_114 -> V_116 ) ) ) {
struct V_90 V_117 ;
memcpy ( & V_117 , V_113 ,
sizeof( struct V_90 ) ) ;
memcpy ( V_113 , V_114 ,
sizeof( struct V_90 ) ) ;
memcpy ( V_114 , & V_117 ,
sizeof( struct V_90 ) ) ;
V_110 = V_112 ;
}
}
}
}
static int T_2 F_30 ( struct V_1 * V_2 )
{
struct V_90 * V_118 =
& V_94 [ V_92 ] ;
int V_119 = V_92 + 1 ;
int V_120 = 0 , V_121 = 0 ;
bool V_122 = false ;
bool V_123 = false ;
bool V_124 [ 6 ] ;
struct V_125 * V_32 = NULL ;
int V_84 ;
if ( V_92 >= V_93 )
return 0 ;
V_92 ++ ;
for ( V_84 = 0 ; V_84 < 6 ; V_84 ++ )
V_124 [ V_84 ] = false ;
V_118 -> V_89 = 0 ;
while ( ( V_32 = F_31 ( V_126 ,
V_127 ,
V_32 ) ) != NULL ) {
struct V_1 * V_128 = V_2 ;
struct V_129 V_130 ;
enum V_131 V_132 ;
unsigned char V_115 ;
unsigned char V_133 ;
unsigned int V_134 ;
unsigned long V_135 ;
unsigned long V_136 ;
unsigned long V_89 ;
unsigned long V_137 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_115 -> V_138 ;
V_133 = V_32 -> V_139 >> 3 ;
V_134 = V_32 -> V_140 ;
V_89 = V_135 = F_35 ( V_32 , 0 ) ;
V_137 = V_136 = F_35 ( V_32 , 1 ) ;
if ( F_36 ( V_32 , 0 ) & V_141 ) {
F_8 ( L_20 L_21 , NULL , V_135 ) ;
F_8 ( L_22 , NULL , V_115 , V_133 , V_89 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_142 ) {
F_8 ( L_23 L_21 , NULL , V_136 ) ;
F_8 ( L_24 , NULL , V_115 , V_133 , V_137 ) ;
continue;
}
if ( V_134 == 0 ) {
F_8 ( L_25 L_21 , NULL , V_134 ) ;
F_8 ( L_22 , NULL , V_115 , V_133 , V_89 ) ;
continue;
}
if ( V_78 . V_143 ) {
F_12 ( L_26 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_115 , V_133 , V_89 , V_137 ) ;
}
V_128 -> V_89 = V_89 ;
F_24 ( V_128 ) ;
if ( F_17 ( V_128 , V_144 , NULL , 0 ,
& V_130 , sizeof( V_130 ) ) ==
sizeof( V_130 ) ) {
if ( V_130 . V_145 < 6 )
V_124 [ V_130 . V_145 ] = true ;
} else
V_130 . V_145 = V_146 ;
V_132 = V_146 ;
F_17 ( V_128 , V_76 , & V_132 ,
sizeof( V_132 ) , NULL , 0 ) ;
if ( ! V_123 ) {
struct V_147 V_148 ;
struct V_149 V_150 ;
struct V_151 V_152 ;
V_148 . V_14 = V_153 + 45 ;
V_148 . V_154 = sizeof( V_150 ) ;
F_17 ( V_128 , V_83 ,
& V_148 , sizeof( V_148 ) ,
& V_150 ,
sizeof( V_150 ) ) ;
F_17 ( V_128 , V_155 , NULL , 0 ,
& V_152 , sizeof( V_152 ) ) ;
if ( V_152 . V_156 == '5' )
V_122 =
V_150 . V_122 ;
V_123 = true ;
}
if ( V_130 . V_145 == V_157 ) {
V_118 -> V_95 = V_96 ;
V_118 -> V_97 = V_158 ;
V_118 -> V_89 = V_89 ;
V_118 -> V_137 = V_137 ;
V_118 -> V_115 = V_115 ;
V_118 -> V_116 = V_133 ;
V_118 -> V_134 = V_134 ;
V_118 -> V_32 = F_37 ( V_32 ) ;
V_121 ++ ;
} else if ( V_92 < V_93 ) {
struct V_90 * V_91 =
& V_94 [ V_92 ++ ] ;
V_91 -> V_95 = V_96 ;
V_91 -> V_97 = V_158 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_137 = V_137 ;
V_91 -> V_115 = V_115 ;
V_91 -> V_116 = V_133 ;
V_91 -> V_134 = V_134 ;
V_91 -> V_32 = F_37 ( V_32 ) ;
V_120 ++ ;
V_121 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
}
if ( V_122 )
F_29 ( & V_94 [ V_119 ] ,
V_120 ) ;
if ( ! V_99 . V_100 )
if ( V_118 -> V_89 == 0 &&
( ! V_99 . V_101 ||
V_99 . V_102 ) ) {
V_118 -> V_95 = V_96 ;
V_118 -> V_97 = V_98 ;
V_118 -> V_89 = 0x330 ;
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
while ( ( V_32 = F_31 ( V_126 ,
V_159 ,
V_32 ) ) != NULL ) {
unsigned char V_115 ;
unsigned char V_133 ;
unsigned int V_134 ;
unsigned long V_89 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_115 -> V_138 ;
V_133 = V_32 -> V_139 >> 3 ;
V_134 = V_32 -> V_140 ;
V_89 = F_35 ( V_32 , 0 ) ;
if ( V_89 == 0 || V_134 == 0 )
continue;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
struct V_90 * V_91 =
& V_94 [ V_84 ] ;
if ( V_91 -> V_89 == V_89 &&
V_91 -> V_95 == V_96 ) {
V_91 -> V_97 = V_158 ;
V_91 -> V_137 = 0 ;
V_91 -> V_115 = V_115 ;
V_91 -> V_116 = V_133 ;
V_91 -> V_134 = V_134 ;
V_91 -> V_32 = F_37 ( V_32 ) ;
break;
}
}
}
return V_121 ;
}
static int T_2 F_39 ( struct V_1 * V_2 )
{
int V_160 = V_92 , V_161 = 0 ;
struct V_125 * V_32 = NULL ;
while ( ( V_32 = F_31 ( V_126 ,
V_162 ,
V_32 ) ) != NULL ) {
unsigned char V_115 ;
unsigned char V_133 ;
unsigned int V_134 ;
unsigned long V_135 ;
unsigned long V_136 ;
unsigned long V_89 ;
unsigned long V_137 ;
if ( F_32 ( V_32 ) )
continue;
if ( F_33 ( V_32 , F_34 ( 32 ) ) )
continue;
V_115 = V_32 -> V_115 -> V_138 ;
V_133 = V_32 -> V_139 >> 3 ;
V_134 = V_32 -> V_140 ;
V_89 = V_135 = F_35 ( V_32 , 0 ) ;
V_137 = V_136 = F_35 ( V_32 , 1 ) ;
#ifdef F_40
if ( F_36 ( V_32 , 0 ) & V_141 ) {
F_8 ( L_20 L_32 , NULL , V_135 ) ;
F_8 ( L_22 , NULL , V_115 , V_133 , V_89 ) ;
continue;
}
if ( F_36 ( V_32 , 1 ) & V_142 ) {
F_8 ( L_23 L_32 , NULL , V_136 ) ;
F_8 ( L_24 , NULL , V_115 , V_133 , V_137 ) ;
continue;
}
if ( V_134 == 0 ) {
F_8 ( L_25 L_32 , NULL , V_134 ) ;
F_8 ( L_22 , NULL , V_115 , V_133 , V_89 ) ;
continue;
}
if ( V_78 . V_143 ) {
F_12 ( L_33 L_27 , NULL ) ;
F_12 ( L_28 L_29 , NULL , V_115 , V_133 , V_89 , V_137 ) ;
}
if ( V_92 < V_93 ) {
struct V_90 * V_91 =
& V_94 [ V_92 ++ ] ;
V_91 -> V_95 = V_163 ;
V_91 -> V_97 = V_158 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_137 = V_137 ;
V_91 -> V_115 = V_115 ;
V_91 -> V_116 = V_133 ;
V_91 -> V_134 = V_134 ;
V_91 -> V_32 = F_37 ( V_32 ) ;
V_161 ++ ;
} else
F_38 ( L_30 L_31 , NULL ) ;
#else
F_8 ( L_34 L_35 , NULL , V_115 , V_133 ) ;
F_8 ( L_36 L_37 , NULL , V_89 , V_137 , V_134 ) ;
F_8 ( L_38 L_39 , NULL ) ;
#endif
}
F_29 ( & V_94 [ V_160 ] , V_161 ) ;
return V_161 ;
}
static void T_2 F_41 ( struct V_1 * V_2 )
{
if ( ! V_99 . V_164 ) {
if ( V_99 . V_165 ) {
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
} else if ( V_99 . V_166 ) {
F_39 ( V_2 ) ;
F_30 ( V_2 ) ;
} else {
int V_161 = F_39 ( V_2 ) ;
int V_121 = F_30 ( V_2 ) ;
if ( V_161 > 0 && V_121 > 0 ) {
struct V_90 * V_91 =
& V_94 [ V_161 ] ;
struct V_1 * V_167 = V_2 ;
struct V_147 V_148 ;
struct V_168 V_169 ;
while ( V_91 -> V_97 !=
V_158 )
V_91 ++ ;
V_167 -> V_89 = V_91 -> V_89 ;
V_148 . V_14 =
V_170 + V_171 ;
V_148 . V_154 = sizeof( V_169 ) ;
F_17 ( V_167 , V_83 ,
& V_148 ,
sizeof( V_148 ) ,
& V_169 ,
sizeof( V_169 ) ) ;
if ( V_169 . V_172 != V_173 ) {
struct V_90 V_174 [ V_93 ] ;
int V_121 = V_92 - V_161 ;
memcpy ( V_174 ,
V_94 ,
V_92 * sizeof( struct V_90 ) ) ;
memcpy ( & V_94 [ 0 ] ,
& V_174 [ V_161 ] ,
V_121 * sizeof( struct V_90 ) ) ;
memcpy ( & V_94 [ V_121 ] ,
& V_174 [ 0 ] ,
V_161 * sizeof( struct V_90 ) ) ;
}
}
}
} else {
F_28 ( V_2 ) ;
}
}
static bool F_42 ( struct V_1 * V_2 , char * V_175 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_97 == V_158 ) {
F_8 ( L_40 ,
V_2 ) ;
F_8 ( L_41 , V_2 , V_2 -> V_115 , V_2 -> V_116 , V_2 -> V_89 , V_2 -> V_137 ) ;
} else
F_8 ( L_42 L_43 , V_2 , V_2 -> V_89 ) ;
F_8 ( L_44 , V_2 , V_175 ) ;
if ( V_70 != NULL )
F_8 ( L_45 , V_2 ,
V_70 ) ;
return false ;
}
static bool T_2 F_43 ( struct V_1 * V_2 )
{
union V_57 V_58 ;
union V_59 V_60 ;
union V_176 V_177 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_24 -> V_23 = ( V_20 ) V_2 -> V_89 ;
V_24 -> V_134 = V_2 -> V_134 ;
V_24 -> V_179 = false ;
if ( ! ( F_44 ( V_24 ) == 0 &&
V_24 -> V_179 ) ) {
F_8 ( L_34 L_35 , V_2 , V_2 -> V_115 , V_2 -> V_116 ) ;
F_8 ( L_46 L_37 , V_2 , V_2 -> V_89 , V_2 -> V_137 ) ;
F_8 ( L_47 , V_2 ) ;
return false ;
}
if ( V_78 . V_143 )
F_12 ( L_48 , V_2 , V_2 -> V_89 ) ;
return true ;
}
V_58 . V_66 = F_19 ( V_2 ) ;
V_60 . V_66 = F_22 ( V_2 ) ;
V_177 . V_66 = F_45 ( V_2 ) ;
if ( V_78 . V_143 )
F_12 ( L_49 L_50 , V_2 , V_2 -> V_89 , V_58 . V_66 , V_60 . V_66 , V_177 . V_66 ) ;
if ( V_58 . V_66 == 0 || V_58 . V_67 . V_87 ||
V_58 . V_67 . V_69 || V_58 . V_67 . V_85 ||
V_58 . V_67 . V_77 || V_60 . V_73 . V_85 != 0 )
return false ;
if ( V_177 . V_66 == 0xFF )
return false ;
return true ;
}
static bool F_46 ( struct V_1 * V_2 , bool V_180 )
{
union V_57 V_58 ;
int V_64 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_24 -> V_181 = ! V_180 ;
V_24 -> V_182 = true ;
V_2 -> V_183 =
F_47 ( V_24 ) ;
if ( V_2 -> V_183 == ( void * ) V_184 )
return false ;
return true ;
}
if ( V_180 )
F_48 ( V_2 ) ;
else
F_25 ( V_2 ) ;
V_64 = 5 * 10000 ;
while ( -- V_64 >= 0 ) {
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_58 . V_67 . V_87 )
break;
F_20 ( 100 ) ;
}
if ( V_78 . V_185 )
F_12 ( L_51 L_52 , V_2 , V_2 -> V_89 , V_58 . V_66 ) ;
if ( V_64 < 0 )
return false ;
F_20 ( 100 ) ;
V_64 = 10 * 10000 ;
while ( -- V_64 >= 0 ) {
V_58 . V_66 = F_19 ( V_2 ) ;
if ( ! V_58 . V_67 . V_87 )
break;
F_20 ( 100 ) ;
}
if ( V_78 . V_185 )
F_12 ( L_53 L_52 , V_2 , V_2 -> V_89 , V_58 . V_66 ) ;
if ( V_64 < 0 )
return false ;
V_64 = 10000 ;
while ( -- V_64 >= 0 ) {
V_58 . V_66 = F_19 ( V_2 ) ;
if ( V_58 . V_67 . V_88 || V_58 . V_67 . V_68 ||
V_58 . V_67 . V_75 )
break;
F_20 ( 100 ) ;
}
if ( V_78 . V_185 )
F_12 ( L_54 L_52 , V_2 , V_2 -> V_89 , V_58 . V_66 ) ;
if ( V_64 < 0 )
return false ;
if ( V_58 . V_67 . V_88 || ! V_58 . V_67 . V_68 ) {
V_70 = NULL ;
F_42 ( V_2 , L_55 ) ;
F_8 ( L_56 , V_2 ,
V_58 . V_66 ) ;
if ( V_58 . V_67 . V_75 )
F_8 ( L_57 , V_2 ,
F_23 ( V_2 ) ) ;
return false ;
}
return true ;
}
static bool T_2 F_49 ( struct V_1 * V_2 )
{
struct V_186 V_187 ;
unsigned char V_188 ;
bool V_63 = true ;
if ( F_5 ( V_2 ) )
return true ;
V_188 = sizeof( V_187 ) ;
if ( F_17 ( V_2 , V_189 , & V_188 ,
sizeof( V_188 ) , & V_187 ,
sizeof( V_187 ) ) != sizeof( V_187 ) )
V_63 = false ;
if ( V_78 . V_143 )
F_12 ( L_58 , V_2 ,
V_2 -> V_89 ,
( V_63 ? L_59 : L_60 ) ) ;
return V_63 ;
}
static bool T_2 F_50 ( struct V_1 * V_2 )
{
struct V_151 V_152 ;
struct V_190 V_191 ;
struct V_192 V_193 ;
struct V_186 V_187 ;
unsigned char V_194 [ 5 ] ;
unsigned char V_195 ;
unsigned char V_196 ;
struct V_129 V_130 ;
struct V_147 V_148 ;
struct V_197 V_198 ;
union V_176 V_177 ;
unsigned char V_188 ;
unsigned char * V_199 , V_200 ;
int V_201 , V_84 ;
if ( F_5 ( V_2 ) ) {
struct V_178 * V_24 = & V_2 -> V_24 ;
V_199 = V_2 -> V_194 ;
* V_199 ++ = 'B' ;
* V_199 ++ = 'T' ;
* V_199 ++ = '-' ;
for ( V_84 = 0 ; V_84 < sizeof( V_24 -> V_194 ) ; V_84 ++ )
* V_199 ++ = V_24 -> V_194 [ V_84 ] ;
* V_199 ++ = '\0' ;
strcpy ( V_2 -> V_202 , V_203 ) ;
V_2 -> V_204 = V_24 -> V_204 ;
V_2 -> V_205 = V_24 -> V_205 ;
V_2 -> V_206 = V_24 -> V_206 ;
V_2 -> V_207 = ! V_24 -> V_181 ;
V_2 -> V_208 = true ;
V_2 -> V_209 = V_24 -> V_209 ;
V_2 -> V_210 = false ;
V_2 -> V_211 = true ;
V_2 -> V_212 = true ;
V_2 -> V_213 = true ;
V_2 -> V_214 = true ;
V_2 -> V_215 = V_24 -> V_215 ;
V_2 -> V_216 = V_24 -> V_216 ;
V_2 -> V_217 = V_24 -> V_217 ;
V_2 -> V_218 = V_24 -> V_218 ;
V_2 -> V_219 = V_220 ;
V_2 -> V_221 = ( V_2 -> V_209 ? 16 : 8 ) ;
V_2 -> V_222 = 32 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_38 = 255 ;
V_2 -> V_223 = V_2 -> V_38 ;
V_2 -> V_224 = V_24 -> V_224 ;
V_2 -> V_225 = V_24 -> V_225 ;
V_2 -> V_226 = V_24 -> V_226 ;
V_2 -> V_227 = V_24 -> V_227 ;
V_2 -> V_228 = V_24 -> V_228 ;
V_2 -> V_229 = 0xFFFF ;
goto V_230;
}
if ( F_17 ( V_2 , V_155 , NULL , 0 , & V_152 ,
sizeof( V_152 ) ) != sizeof( V_152 ) )
return F_42 ( V_2 , L_61 ) ;
if ( F_17 ( V_2 , V_231 , NULL , 0 , & V_191 ,
sizeof( V_191 ) )
!= sizeof( V_191 ) )
return F_42 ( V_2 , L_62 ) ;
V_188 = sizeof( V_193 ) ;
if ( F_17 ( V_2 , V_232 , & V_188 ,
sizeof( V_188 ) , & V_193 ,
sizeof( V_193 ) ) != sizeof( V_193 ) )
return F_42 ( V_2 , L_63 ) ;
V_188 = sizeof( V_187 ) ;
if ( F_17 ( V_2 , V_189 , & V_188 ,
sizeof( V_188 ) , & V_187 ,
sizeof( V_187 ) ) != sizeof( V_187 ) )
return F_42 ( V_2 ,
L_64 ) ;
V_195 = '\0' ;
if ( V_152 . V_156 > '0' )
if ( F_17 ( V_2 , V_233 , NULL , 0 ,
& V_195 ,
sizeof( V_195 ) ) != sizeof( V_195 ) )
return F_42 ( V_2 ,
L_65 ) ;
if ( V_187 . V_234 == 'A' && V_152 . V_156 == '2' )
strcpy ( V_194 , L_66 ) ;
else if ( V_187 . V_234 == 'E' && V_152 . V_156 == '2' &&
( V_152 . V_235 <= '1' || ( V_152 . V_235 == '2' &&
V_195 == '0' ) ) )
strcpy ( V_194 , L_67 ) ;
else if ( V_187 . V_234 == 'E' && V_152 . V_156 == '0' )
strcpy ( V_194 , L_68 ) ;
else {
V_188 = sizeof( V_194 ) ;
if ( F_17 ( V_2 , V_236 , & V_188 ,
sizeof( V_188 ) , & V_194 ,
sizeof( V_194 ) ) != sizeof( V_194 ) )
return F_42 ( V_2 ,
L_69 ) ;
}
V_199 = V_2 -> V_194 ;
* V_199 ++ = 'B' ;
* V_199 ++ = 'T' ;
* V_199 ++ = '-' ;
for ( V_84 = 0 ; V_84 < sizeof( V_194 ) ; V_84 ++ ) {
V_200 = V_194 [ V_84 ] ;
if ( V_200 == ' ' || V_200 == '\0' )
break;
* V_199 ++ = V_200 ;
}
* V_199 ++ = '\0' ;
V_199 = V_2 -> V_202 ;
* V_199 ++ = V_152 . V_156 ;
* V_199 ++ = '.' ;
* V_199 ++ = V_152 . V_235 ;
if ( V_195 != ' ' && V_195 != '\0' )
* V_199 ++ = V_195 ;
* V_199 = '\0' ;
if ( strcmp ( V_2 -> V_202 , L_70 ) >= 0 ) {
if ( F_17 ( V_2 , V_237 , NULL , 0 ,
& V_196 ,
sizeof( V_196 ) ) != sizeof( V_196 ) )
return F_42 ( V_2 ,
L_71 ) ;
if ( V_196 != ' ' && V_196 != '\0' )
* V_199 ++ = V_196 ;
* V_199 = '\0' ;
}
V_2 -> V_204 = V_191 . V_152 ;
V_2 -> V_97 =
V_238 [ V_2 -> V_194 [ 3 ] - '4' ] ;
if ( V_2 -> V_134 == 0 ) {
if ( V_191 . V_239 )
V_2 -> V_134 = 9 ;
else if ( V_191 . V_240 )
V_2 -> V_134 = 10 ;
else if ( V_191 . V_241 )
V_2 -> V_134 = 11 ;
else if ( V_191 . V_242 )
V_2 -> V_134 = 12 ;
else if ( V_191 . V_243 )
V_2 -> V_134 = 14 ;
else if ( V_191 . V_244 )
V_2 -> V_134 = 15 ;
}
if ( V_2 -> V_97 == V_98 ) {
if ( V_191 . V_245 )
V_2 -> V_246 = 5 ;
else if ( V_191 . V_247 )
V_2 -> V_246 = 6 ;
else if ( V_191 . V_248 )
V_2 -> V_246 = 7 ;
}
V_177 . V_66 = F_45 ( V_2 ) ;
V_2 -> V_205 = V_177 . V_249 . V_205 ;
V_2 -> V_250 = V_187 . V_251 ;
V_2 -> V_219 = V_2 -> V_250 ;
if ( V_2 -> V_250 > V_220 )
V_2 -> V_219 = V_220 ;
if ( V_187 . V_252 . V_208 )
V_2 -> V_208 = true ;
V_2 -> V_209 = V_187 . V_209 ;
V_2 -> V_210 = V_187 . V_210 ;
V_2 -> V_211 = V_187 . V_211 ;
V_2 -> V_212 = V_187 . V_212 ;
if ( V_2 -> V_202 [ 0 ] == '5' || ( V_2 -> V_202 [ 0 ] == '4' &&
V_2 -> V_209 ) )
V_2 -> V_213 = true ;
if ( V_2 -> V_202 [ 0 ] == '5' ) {
if ( F_17 ( V_2 , V_144 , NULL , 0 ,
& V_130 ,
sizeof( V_130 ) ) != sizeof( V_130 ) )
return F_42 ( V_2 ,
L_72 ) ;
if ( V_130 . V_253 ) {
V_2 -> V_214 = true ;
V_2 -> V_215 = V_130 . V_215 ;
V_2 -> V_216 = V_130 . V_216 ;
}
}
if ( V_2 -> V_202 [ 0 ] >= '4' ) {
V_148 . V_14 = V_153 ;
V_148 . V_154 = sizeof( V_198 ) ;
if ( F_17 ( V_2 , V_83 , & V_148 ,
sizeof( V_148 ) , & V_198 ,
sizeof( V_198 ) ) != sizeof( V_198 ) )
return F_42 ( V_2 ,
L_73 ) ;
V_2 -> V_206 = V_198 . V_206 ;
V_2 -> V_207 = V_198 . V_207 ;
if ( V_2 -> V_202 [ 0 ] == '4' ) {
V_2 -> V_214 = true ;
V_2 -> V_215 = V_198 . V_215 ;
V_2 -> V_216 = V_198 . V_216 ;
}
V_2 -> V_227 = V_198 . V_227 ;
V_2 -> V_225 = V_198 . V_225 ;
V_2 -> V_224 = V_198 . V_224 ;
V_2 -> V_228 = V_198 . V_228 ;
if ( V_2 -> V_212 )
V_2 -> V_226 = V_198 . V_226 ;
if ( V_2 -> V_211 ) {
V_2 -> V_217 = V_198 . V_217 ;
V_2 -> V_218 = V_198 . V_218 ;
}
}
if ( V_2 -> V_202 [ 0 ] < '4' ) {
if ( V_193 . V_254 ) {
V_2 -> V_224 = 0xFF ;
if ( V_2 -> V_97 == V_255 ) {
if ( V_187 . V_252 . V_256 )
V_2 -> V_225 = 0xFF ;
if ( strcmp ( V_2 -> V_194 , L_74 ) == 0 )
V_2 -> V_227 = 0xFF ;
}
}
V_2 -> V_228 = 0xFF ;
V_2 -> V_206 = V_193 . V_206 ;
V_2 -> V_207 = true ;
}
V_2 -> V_221 = ( V_2 -> V_209 ? 16 : 8 ) ;
V_2 -> V_222 = ( V_2 -> V_213 ? 32 : 8 ) ;
if ( V_2 -> V_202 [ 0 ] == '5' )
V_2 -> V_223 = 192 ;
else if ( V_2 -> V_202 [ 0 ] == '4' )
V_2 -> V_223 = ( V_2 -> V_97 !=
V_98 ? 100 : 50 ) ;
else
V_2 -> V_223 = 30 ;
if ( strcmp ( V_2 -> V_202 , L_75 ) >= 0 ) {
V_2 -> V_257 = true ;
V_2 -> V_258 = V_259 ;
} else {
V_2 -> V_257 = false ;
V_2 -> V_258 = 32 ;
}
V_2 -> V_38 = V_2 -> V_258 ;
V_2 -> V_31 = 4 * V_30 ;
V_2 -> V_43 = V_30 ;
V_2 -> V_229 = 0 ;
switch ( V_2 -> V_202 [ 0 ] ) {
case '5' :
V_2 -> V_229 = 0xFFFF ;
break;
case '4' :
if ( strcmp ( V_2 -> V_202 , L_76 ) >= 0 )
V_2 -> V_229 = 0xFFFF ;
break;
case '3' :
if ( strcmp ( V_2 -> V_202 , L_77 ) >= 0 )
V_2 -> V_229 = 0xFFFF ;
break;
}
V_2 -> V_260 = V_187 . V_260 << 12 ;
if ( V_2 -> V_97 == V_98 &&
( void * ) V_261 > ( void * ) V_262 )
V_2 -> V_263 = true ;
if ( V_2 -> V_260 > 0 && strcmp ( V_2 -> V_194 , L_78 ) == 0 &&
strcmp ( V_2 -> V_202 , L_79 ) < 0 &&
( void * ) V_261 > ( void * ) V_262 )
V_2 -> V_263 = true ;
V_230:
strcpy ( V_2 -> V_8 , L_80 ) ;
strcat ( V_2 -> V_8 , V_2 -> V_194 ) ;
for ( V_201 = 0 ; V_201 < V_264 ; V_201 ++ ) {
unsigned char V_265 = 0 ;
if ( V_2 -> V_266 != NULL &&
V_2 -> V_266 -> V_265 [ V_201 ] > 0 )
V_265 = V_2 -> V_266 -> V_265 [ V_201 ] ;
else if ( V_2 -> V_263 )
V_265 = V_267 ;
V_2 -> V_265 [ V_201 ] = V_265 ;
}
if ( V_2 -> V_263 )
V_2 -> V_268 = V_269 ;
else
V_2 -> V_268 = V_270 ;
if ( V_2 -> V_266 != NULL )
V_2 -> V_271 = V_2 -> V_266 -> V_271 ;
if ( V_2 -> V_271 > 0 &&
V_2 -> V_271 < V_2 -> V_268 )
V_2 -> V_268 = V_2 -> V_271 ;
V_2 -> V_229 &= V_2 -> V_228 ;
if ( V_2 -> V_266 != NULL )
V_2 -> V_229 = ( V_2 -> V_266 -> V_229 &
V_2 -> V_266 -> V_272 ) |
( V_2 -> V_229 & ~ V_2 -> V_266 -> V_272 ) ;
if ( V_2 -> V_266 != NULL &&
V_2 -> V_266 -> V_273 > 0 )
V_2 -> V_273 = V_2 -> V_266 -> V_273 ;
else
V_2 -> V_273 = V_274 ;
return true ;
}
static bool T_2 F_51 ( struct V_1 * V_2 )
{
unsigned short V_275 = ( 1 << V_2 -> V_221 ) - 1 ;
unsigned short V_224 , V_225 ;
unsigned short V_226 , V_227 ;
unsigned short V_228 , V_229 ;
bool V_276 , V_277 ;
char V_278 [ V_264 + 1 ] ;
char V_279 [ V_264 + 1 ] ;
char V_280 [ V_264 + 1 ] ;
char V_281 [ V_264 + 1 ] ;
char * V_282 = V_278 ;
char * V_283 = V_279 ;
char * V_284 = V_280 ;
char * V_285 = V_281 ;
int V_201 ;
F_52 ( L_81 , V_2 , V_2 -> V_194 , V_286 [ V_2 -> V_97 ] , ( V_2 -> V_209 ? L_82 : L_83 ) , ( V_2 -> V_210 ? L_84 : L_83 ) , ( V_2 -> V_212 ? L_85 : L_83 ) ) ;
F_52 ( L_86 L_87 , V_2 , V_2 -> V_202 , V_2 -> V_89 , V_2 -> V_134 , ( V_2 -> V_208 ? L_88 : L_89 ) ) ;
if ( V_2 -> V_97 != V_158 ) {
F_52 ( L_90 , V_2 ) ;
if ( V_2 -> V_246 > 0 )
F_52 ( L_91 , V_2 , V_2 -> V_246 ) ;
else
F_52 ( L_92 , V_2 ) ;
if ( V_2 -> V_260 > 0 )
F_52 ( L_93 , V_2 ,
V_2 -> V_260 ) ;
else
F_52 ( L_94 , V_2 ) ;
} else {
F_52 ( L_95 , V_2 ,
V_2 -> V_115 , V_2 -> V_116 ) ;
if ( V_2 -> V_137 > 0 )
F_52 ( L_96 , V_2 , V_2 -> V_137 ) ;
else
F_52 ( L_97 , V_2 ) ;
}
F_52 ( L_98 , V_2 , V_2 -> V_204 ) ;
F_52 ( L_99 ,
V_2 , ( V_2 -> V_206 ? L_100 : L_101 ) ,
( V_2 -> V_205 ? L_100 : L_101 ) ) ;
V_275 &= ~ ( 1 << V_2 -> V_204 ) ;
V_224 = V_2 -> V_224 & V_275 ;
V_225 = V_2 -> V_225 & V_275 ;
V_226 = V_2 -> V_226 & V_275 ;
if ( ( F_53 ( V_2 ) &&
( V_2 -> V_202 [ 0 ] >= '4' ||
V_2 -> V_97 == V_255 ) ) ||
F_5 ( V_2 ) ) {
V_276 = false ;
if ( V_224 == 0 ) {
V_282 = L_101 ;
V_276 = true ;
} else if ( V_224 == V_275 ) {
if ( V_225 == 0 ) {
V_282 = L_102 ;
V_276 = true ;
} else if ( V_225 == V_275 ) {
if ( V_226 == 0 ) {
V_282 = L_103 ;
V_276 = true ;
} else if ( V_226 == V_275 ) {
V_282 = L_104 ;
V_276 = true ;
}
}
}
if ( ! V_276 ) {
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_278 [ V_201 ] = ( ( ! ( V_224 & ( 1 << V_201 ) ) ) ? 'N' : ( ! ( V_225 & ( 1 << V_201 ) ) ? 'S' : ( ! ( V_226 & ( 1 << V_201 ) ) ? 'F' : 'U' ) ) ) ;
V_278 [ V_2 -> V_204 ] = '#' ;
V_278 [ V_2 -> V_221 ] = '\0' ;
}
} else
V_282 = ( V_224 == 0 ? L_101 : L_100 ) ;
V_227 = V_2 -> V_227 & V_275 ;
if ( V_227 == 0 )
V_283 = L_101 ;
else if ( V_227 == V_275 )
V_283 = L_100 ;
else {
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_279 [ V_201 ] = ( ( V_227 & ( 1 << V_201 ) ) ? 'Y' : 'N' ) ;
V_279 [ V_2 -> V_204 ] = '#' ;
V_279 [ V_2 -> V_221 ] = '\0' ;
}
V_228 = V_2 -> V_228 & V_275 ;
if ( V_228 == 0 )
V_284 = L_101 ;
else if ( V_228 == V_275 )
V_284 = L_100 ;
else {
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_280 [ V_201 ] = ( ( V_228 & ( 1 << V_201 ) ) ? 'Y' : 'N' ) ;
V_280 [ V_2 -> V_204 ] = '#' ;
V_280 [ V_2 -> V_221 ] = '\0' ;
}
V_229 = V_2 -> V_229 & V_275 ;
if ( V_229 == 0 )
V_285 = L_101 ;
else if ( V_229 == V_275 )
V_285 = L_100 ;
else {
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_281 [ V_201 ] = ( ( V_229 & ( 1 << V_201 ) ) ? 'Y' : 'N' ) ;
V_281 [ V_2 -> V_204 ] = '#' ;
V_281 [ V_2 -> V_221 ] = '\0' ;
}
F_52 ( L_105 ,
V_2 , V_282 , V_283 ) ;
F_52 ( L_106 , V_2 ,
V_284 , V_285 ) ;
if ( F_53 ( V_2 ) ) {
F_52 ( L_107 L_108 , V_2 , V_2 -> V_219 , V_2 -> V_250 , V_2 -> V_258 ) ;
F_52 ( L_109 L_110 , V_2 , V_2 -> V_38 , V_2 -> V_223 ) ;
} else
F_52 ( L_109 L_111 , V_2 , V_2 -> V_38 , V_2 -> V_219 ) ;
F_52 ( L_112 , V_2 ) ;
V_277 = true ;
for ( V_201 = 1 ; V_201 < V_2 -> V_221 ; V_201 ++ )
if ( V_2 -> V_265 [ V_201 ] != V_2 -> V_265 [ 0 ] ) {
V_277 = false ;
break;
}
if ( V_277 ) {
if ( V_2 -> V_265 [ 0 ] > 0 )
F_52 ( L_113 , V_2 , V_2 -> V_265 [ 0 ] ) ;
else
F_52 ( L_114 , V_2 ) ;
} else
F_52 ( L_115 , V_2 ) ;
F_52 ( L_116 , V_2 ,
V_2 -> V_268 ) ;
if ( V_2 -> V_214 ) {
if ( V_2 -> V_209 )
F_52 ( L_117 , V_2 ,
( V_2 -> V_215 ? ( V_2 -> V_216 ? L_118 : L_119 ) : ( V_2 -> V_216 ? L_120 : L_121 ) ) ) ;
else
F_52 ( L_117 , V_2 ,
( V_2 -> V_215 ? L_100 : L_101 ) ) ;
if ( V_2 -> V_211 )
F_52 ( L_122 , V_2 ,
( V_2 -> V_217 ? ( V_2 -> V_218 ? L_123 : L_124 ) : L_101 ) ) ;
F_52 ( L_17 , V_2 ) ;
}
return true ;
}
static bool T_2 F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_134 == 0 ) {
F_8 ( L_125 ,
V_2 ) ;
return false ;
}
if ( F_55 ( V_2 -> V_134 , V_287 , V_288 ,
V_2 -> V_8 , V_2 ) < 0 ) {
F_8 ( L_126 ,
V_2 , V_2 -> V_134 ) ;
return false ;
}
V_2 -> V_65 = true ;
if ( V_2 -> V_246 > 0 ) {
if ( F_56 ( V_2 -> V_246 , V_2 -> V_8 ) < 0 ) {
F_8 ( L_127 , V_2 , V_2 -> V_246 ) ;
return false ;
}
F_57 ( V_2 -> V_246 , V_289 ) ;
F_58 ( V_2 -> V_246 ) ;
V_2 -> V_290 = true ;
}
return true ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 )
F_60 ( V_2 -> V_134 , V_2 ) ;
if ( V_2 -> V_290 )
F_61 ( V_2 -> V_246 ) ;
if ( V_2 -> V_291 )
F_10 ( V_2 -> V_32 , V_2 -> V_292 ,
V_2 -> V_291 , V_2 -> V_293 ) ;
F_62 ( V_2 -> V_32 ) ;
V_2 -> V_291 = NULL ;
V_2 -> V_293 = 0 ;
V_2 -> V_292 = 0 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_294 V_295 ;
enum V_296 V_297 ;
enum V_298 V_299 ;
int V_201 ;
V_2 -> V_300 = NULL ;
V_2 -> V_34 = NULL ;
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ ) {
V_2 -> V_301 [ V_201 ] = NULL ;
V_2 -> V_302 [ V_201 ] . V_303 = false ;
V_2 -> V_302 [ V_201 ] . V_304 = false ;
V_2 -> V_305 [ V_201 ] = 0 ;
V_2 -> V_306 [ V_201 ] = 0 ;
}
if ( F_5 ( V_2 ) )
goto V_71;
V_2 -> V_292 = V_2 -> V_258 * ( sizeof( struct V_307 ) + sizeof( struct V_308 ) ) ;
V_2 -> V_291 = F_7 ( V_2 -> V_32 ,
V_2 -> V_292 , & V_2 -> V_293 ) ;
if ( V_2 -> V_291 == NULL )
return F_42 ( V_2 , L_128 ) ;
V_2 -> V_309 = (struct V_307 * ) V_2 -> V_291 ;
V_2 -> V_310 = V_2 -> V_309 + V_2 -> V_258 - 1 ;
V_2 -> V_311 = V_2 -> V_309 ;
V_2 -> V_312 = (struct V_308 * ) ( V_2 -> V_310 + 1 ) ;
V_2 -> V_313 = V_2 -> V_312 + V_2 -> V_258 - 1 ;
V_2 -> V_314 = V_2 -> V_312 ;
memset ( V_2 -> V_309 , 0 ,
V_2 -> V_258 * sizeof( struct V_307 ) ) ;
memset ( V_2 -> V_312 , 0 ,
V_2 -> V_258 * sizeof( struct V_308 ) ) ;
V_295 . V_258 = V_2 -> V_258 ;
V_295 . V_315 = ( V_20 ) V_2 -> V_293 ;
if ( F_17 ( V_2 , V_316 , & V_295 ,
sizeof( V_295 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_129 ) ;
if ( V_2 -> V_257 ) {
V_297 = V_317 ;
if ( F_17 ( V_2 , V_318 , & V_297 ,
sizeof( V_297 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 ,
L_130 ) ;
}
if ( V_2 -> V_213 ) {
V_299 = V_319 ;
if ( F_17 ( V_2 , V_320 , & V_299 ,
sizeof( V_299 ) , NULL , 0 ) < 0 )
return F_42 ( V_2 , L_131 ) ;
}
V_71:
if ( ! V_2 -> V_321 ) {
F_52 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
F_52 ( L_17 , V_2 ) ;
} else
F_38 ( L_132 , V_2 ,
V_2 -> V_8 ) ;
V_2 -> V_321 = true ;
return true ;
}
static bool T_2 F_64 ( struct V_1 * V_2 )
{
T_3 V_322 ;
T_4 V_323 [ 8 ] ;
struct V_192 V_193 ;
T_4 V_324 [ V_264 ] ;
unsigned char V_188 ;
int V_201 ;
F_65 ( V_2 -> V_273 ) ;
if ( F_5 ( V_2 ) )
return true ;
if ( V_2 -> V_266 != NULL && V_2 -> V_266 -> V_325 )
return true ;
if ( strcmp ( V_2 -> V_202 , L_133 ) >= 0 ) {
if ( F_17 ( V_2 , V_82 , NULL , 0 ,
& V_322 , sizeof( V_322 ) )
!= sizeof( V_322 ) )
return F_42 ( V_2 , L_134 ) ;
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_2 -> V_302 [ V_201 ] . V_326 =
( V_322 & ( 1 << V_201 ) ? true : false ) ;
} else {
if ( F_17 ( V_2 , V_80 , NULL , 0 ,
& V_323 , sizeof( V_323 ) )
!= sizeof( V_323 ) )
return F_42 ( V_2 ,
L_135 ) ;
for ( V_201 = 0 ; V_201 < 8 ; V_201 ++ )
V_2 -> V_302 [ V_201 ] . V_326 =
( V_323 [ V_201 ] != 0 ? true : false ) ;
}
V_188 = sizeof( V_193 ) ;
if ( F_17 ( V_2 , V_232 , & V_188 ,
sizeof( V_188 ) , & V_193 , sizeof( V_193 ) )
!= sizeof( V_193 ) )
return F_42 ( V_2 , L_63 ) ;
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_2 -> V_327 [ V_201 ] = ( V_201 < 8 ? V_193 . V_328 [ V_201 ] . V_14 : V_193 . V_329 [ V_201 - 8 ] . V_14 ) ;
if ( strcmp ( V_2 -> V_202 , L_136 ) >= 0 )
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_2 -> V_302 [ V_201 ] . V_330 = ( V_201 < 8 ? ( V_193 . V_331 & ( 1 << V_201 ) ? true : false ) : ( V_193 . V_332 & ( 1 << ( V_201 - 8 ) ) ? true : false ) ) ;
if ( V_2 -> V_202 [ 0 ] >= '3' ) {
V_188 = sizeof( V_324 ) ;
if ( F_17 ( V_2 , V_333 , & V_188 ,
sizeof( V_188 ) , & V_324 ,
sizeof( V_324 ) ) != sizeof( V_324 ) )
return F_42 ( V_2 ,
L_137 ) ;
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
V_2 -> V_324 [ V_201 ] = V_324 [ V_201 ] ;
} else
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
if ( V_193 . V_328 [ V_201 ] . V_14 > 0 )
V_2 -> V_324 [ V_201 ] = 20 + 5 * V_193 . V_328 [ V_201 ] . V_334 ;
return true ;
}
static void T_2 F_66 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
V_6 -> V_335 = V_2 -> V_221 ;
V_6 -> V_336 = V_2 -> V_222 ;
V_6 -> V_337 = 0 ;
V_6 -> V_338 = V_2 -> V_89 ;
V_6 -> V_339 = V_2 -> V_204 ;
V_6 -> V_41 = V_2 -> V_38 ;
V_6 -> V_340 = V_2 -> V_219 ;
V_6 -> V_341 = V_2 -> V_263 ;
V_6 -> V_342 = V_2 -> V_268 ;
}
static int F_67 ( struct V_343 * V_116 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_116 -> V_6 -> V_7 ;
int V_201 = V_116 -> V_152 ;
int V_265 = V_2 -> V_265 [ V_201 ] ;
if ( V_2 -> V_302 [ V_201 ] . V_229 &&
( V_2 -> V_229 & ( 1 << V_201 ) ) ) {
if ( V_265 == 0 )
V_265 = V_344 ;
V_2 -> V_265 [ V_201 ] = V_265 ;
F_68 ( V_116 , V_345 , V_265 ) ;
} else {
V_2 -> V_229 &= ~ ( 1 << V_201 ) ;
V_265 = V_2 -> V_268 ;
V_2 -> V_265 [ V_201 ] = V_265 ;
F_68 ( V_116 , 0 , V_265 ) ;
}
V_265 = 0 ;
for ( V_201 = 0 ; V_201 < V_2 -> V_221 ; V_201 ++ )
if ( V_2 -> V_302 [ V_201 ] . V_326 )
V_265 += V_2 -> V_265 [ V_201 ] ;
if ( V_265 > V_2 -> V_29 )
F_11 ( V_2 , V_265 - V_2 -> V_29 ,
false ) ;
return 0 ;
}
static int T_2 F_69 ( void )
{
int V_346 = 0 , V_347 = 0 , V_348 ;
struct V_1 * V_2 ;
int V_349 = 0 ;
#ifdef F_70
if ( V_350 )
F_71 ( V_350 ) ;
#endif
if ( V_99 . V_351 )
return - V_352 ;
V_94 =
F_72 ( V_93 * sizeof( struct V_90 ) ,
V_353 ) ;
if ( V_94 == NULL ) {
F_8 ( L_138 ,
NULL ) ;
return - V_354 ;
}
V_2 = F_72 ( sizeof( struct V_1 ) , V_353 ) ;
if ( V_2 == NULL ) {
F_73 ( V_94 ) ;
F_8 ( L_139 , NULL ) ;
return - V_354 ;
}
#ifdef F_70
if ( V_350 != NULL )
F_71 ( V_350 ) ;
#endif
F_41 ( V_2 ) ;
for ( V_348 = 0 ; V_348 < V_92 ; V_348 ++ ) {
struct V_90 * V_91 =
& V_94 [ V_348 ] ;
struct V_1 * V_167 = V_2 ;
struct V_5 * V_6 ;
if ( V_91 -> V_89 == 0 )
continue;
memset ( V_167 , 0 , sizeof( struct V_1 ) ) ;
V_167 -> V_95 = V_91 -> V_95 ;
V_167 -> V_97 = V_91 -> V_97 ;
V_167 -> V_89 = V_91 -> V_89 ;
V_167 -> V_137 = V_91 -> V_137 ;
V_167 -> V_115 = V_91 -> V_115 ;
V_167 -> V_116 = V_91 -> V_116 ;
V_167 -> V_32 = V_91 -> V_32 ;
V_167 -> V_134 = V_91 -> V_134 ;
V_167 -> V_355 =
V_356 [ V_167 -> V_95 ] ;
if ( ! F_74 ( V_167 -> V_89 , V_167 -> V_355 ,
L_140 ) )
continue;
if ( ! F_43 ( V_167 ) ) {
F_75 ( V_167 -> V_89 ,
V_167 -> V_355 ) ;
continue;
}
if ( ! F_46 ( V_167 , true ) ) {
F_75 ( V_167 -> V_89 ,
V_167 -> V_355 ) ;
continue;
}
if ( ! F_49 ( V_167 ) ) {
F_75 ( V_167 -> V_89 ,
V_167 -> V_355 ) ;
continue;
}
if ( V_347 < V_357 )
V_167 -> V_266 =
& V_358 [ V_347 ++ ] ;
F_1 ( V_167 ) ;
V_6 = F_76 ( & V_359 ,
sizeof( struct V_1 ) ) ;
if ( V_6 == NULL ) {
F_75 ( V_167 -> V_89 ,
V_167 -> V_355 ) ;
continue;
}
V_167 = (struct V_1 * ) V_6 -> V_7 ;
memcpy ( V_167 , V_2 , sizeof( struct V_1 ) ) ;
V_167 -> V_40 = V_6 ;
V_167 -> V_360 = V_6 -> V_360 ;
F_77 ( & V_167 -> V_361 , & V_362 ) ;
if ( F_50 ( V_167 ) &&
F_51 ( V_167 ) &&
F_54 ( V_167 ) &&
F_6 ( V_167 ) &&
F_63 ( V_167 ) &&
F_64 ( V_167 ) ) {
F_75 ( V_167 -> V_89 ,
V_167 -> V_355 ) ;
if ( ! F_74 ( V_167 -> V_89 ,
V_167 -> V_355 ,
V_167 -> V_8 ) ) {
F_78 ( V_363
L_141
L_142 ,
( unsigned long ) V_167 -> V_89 ) ;
F_9 ( V_167 ) ;
F_59 ( V_167 ) ;
F_79 ( & V_167 -> V_361 ) ;
F_80 ( V_6 ) ;
V_349 = - V_354 ;
} else {
F_66 ( V_167 ,
V_6 ) ;
if ( F_81 ( V_6 , V_167 -> V_32
? & V_167 -> V_32 -> V_116
: NULL ) ) {
F_78 ( V_363
L_143
L_144 ) ;
F_9 ( V_167 ) ;
F_59 ( V_167 ) ;
F_79 ( & V_167 -> V_361 ) ;
F_80 ( V_6 ) ;
V_349 = - V_352 ;
} else {
F_82 ( V_6 ) ;
V_346 ++ ;
}
}
} else {
F_9 ( V_167 ) ;
F_59 ( V_167 ) ;
F_79 ( & V_167 -> V_361 ) ;
F_80 ( V_6 ) ;
V_349 = - V_352 ;
}
}
F_73 ( V_2 ) ;
F_73 ( V_94 ) ;
V_94 = NULL ;
return V_349 ;
}
static int T_5 F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_40 ;
F_84 ( V_6 ) ;
if ( F_5 ( V_2 ) )
F_85 ( V_2 -> V_183 ) ;
F_9 ( V_2 ) ;
F_59 ( V_2 ) ;
F_75 ( V_2 -> V_89 , V_2 -> V_355 ) ;
F_79 ( & V_2 -> V_361 ) ;
F_80 ( V_6 ) ;
return 0 ;
}
static void V_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
V_13 -> V_17 = V_364 ;
V_13 -> V_25 = NULL ;
if ( V_2 -> V_300 == NULL ) {
V_2 -> V_300 = V_13 ;
V_2 -> V_34 = V_13 ;
} else {
V_2 -> V_34 -> V_25 = V_13 ;
V_2 -> V_34 = V_13 ;
}
V_2 -> V_305 [ V_13 -> V_201 ] -- ;
}
static int F_86 ( struct V_1 * V_2 ,
enum V_365 V_366 ,
enum V_367 V_368 )
{
int V_369 ;
switch ( V_366 ) {
case V_370 :
case V_371 :
case V_372 :
V_369 = V_373 ;
break;
case V_374 :
V_369 = V_375 ;
break;
case V_376 :
case V_377 :
case V_378 :
F_38 ( L_145 ,
V_2 , V_366 ) ;
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
case V_391 :
V_369 = V_392 ;
break;
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
V_369 = V_398 ;
break;
default:
F_38 ( L_146 , V_2 ,
V_366 ) ;
V_369 = V_392 ;
break;
}
return ( V_369 << 16 ) | V_368 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_308 * V_314 = V_2 -> V_314 ;
enum V_399 V_400 ;
while ( ( V_400 = V_314 -> V_400 ) != V_401 ) {
struct V_12 * V_13 =
(struct V_12 * ) F_88 ( V_314 -> V_13 ) ;
if ( V_400 != V_402 ) {
if ( V_13 -> V_17 == V_403 ||
V_13 -> V_17 == V_404 ) {
V_13 -> V_400 = V_400 ;
V_22 ( V_13 ) ;
} else {
F_38 ( L_147 L_148 , V_2 , V_13 -> V_42 , V_13 -> V_17 ) ;
}
}
V_314 -> V_400 = V_401 ;
if ( ++ V_314 > V_2 -> V_313 )
V_314 = V_2 -> V_312 ;
}
V_2 -> V_314 = V_314 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_405 )
return;
V_2 -> V_405 = true ;
while ( V_2 -> V_300 != NULL ) {
struct V_12 * V_13 = V_2 -> V_300 ;
struct V_406 * V_45 = V_13 -> V_45 ;
V_2 -> V_300 = V_13 -> V_25 ;
if ( V_2 -> V_300 == NULL )
V_2 -> V_34 = NULL ;
if ( V_13 -> V_50 == V_407 ) {
int V_201 = V_13 -> V_201 ;
F_38 ( L_149 L_150 , V_2 , V_13 -> V_42 , V_201 ) ;
F_90 ( & V_2 -> V_408 [ V_201 ] . V_409 ) ;
V_2 -> V_302 [ V_201 ] . V_303 = false ;
V_2 -> V_306 [ V_201 ] = 0 ;
V_2 -> V_410 [ V_201 ] = V_411 ;
F_14 ( V_13 , 1 ) ;
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
if ( V_13 -> V_17 == V_404 &&
V_13 -> V_201 == V_201 ) {
V_45 = V_13 -> V_45 ;
F_14 ( V_13 , 1 ) ;
V_2 -> V_305 [ V_201 ] -- ;
V_45 -> V_63 = V_398 << 16 ;
V_45 -> V_412 ( V_45 ) ;
}
V_2 -> V_301 [ V_201 ] = NULL ;
} else {
switch ( V_13 -> V_400 ) {
case V_401 :
case V_402 :
case V_413 :
F_38 ( L_151 , V_2 , V_13 -> V_42 , V_13 -> V_201 ) ;
break;
case V_414 :
V_2 -> V_408 [ V_13 -> V_201 ]
. V_415 ++ ;
V_2 -> V_302 [ V_13 -> V_201 ]
. V_304 = true ;
V_45 -> V_63 = V_373 << 16 ;
break;
case V_416 :
F_38 ( L_152 ,
V_2 , V_13 -> V_42 , V_13 -> V_201 ) ;
F_90 ( & V_2 -> V_408 [ V_13 -> V_201 ] . V_417 ) ;
V_45 -> V_63 = V_418 << 16 ;
break;
case V_419 :
V_45 -> V_63 = F_86 ( V_2 ,
V_13 -> V_366 , V_13 -> V_368 ) ;
if ( V_13 -> V_366 != V_374 ) {
V_2 -> V_408 [ V_13 -> V_201 ]
. V_415 ++ ;
if ( V_78 . V_420 ) {
int V_84 ;
F_12 ( L_153
L_154 L_155 , V_2 , V_13 -> V_42 , V_13 -> V_201 , V_45 -> V_63 , V_13 -> V_366 , V_13 -> V_368 ) ;
F_12 ( L_156 , V_2 ) ;
for ( V_84 = 0 ; V_84 < V_13 -> V_421 ; V_84 ++ )
F_12 ( L_16 , V_2 , V_13 -> V_422 [ V_84 ] ) ;
F_12 ( L_17 , V_2 ) ;
F_12 ( L_157 , V_2 ) ;
for ( V_84 = 0 ; V_84 < V_13 -> V_47 ; V_84 ++ )
F_12 ( L_16 , V_2 , V_45 -> V_423 [ V_84 ] ) ;
F_12 ( L_17 , V_2 ) ;
}
}
break;
}
if ( V_13 -> V_422 [ 0 ] == V_424 && V_13 -> V_422 [ 1 ] == 0 &&
V_13 -> V_366 == V_370 ) {
struct V_425 * V_302 =
& V_2 -> V_302 [ V_13 -> V_201 ] ;
struct V_426 * V_427 =
(struct V_426 * ) F_91 ( V_45 ) ;
V_302 -> V_326 = true ;
V_302 -> V_229 = V_427 -> V_428 ;
V_302 -> V_227 = V_427 -> V_429 ;
}
F_14 ( V_13 , 1 ) ;
V_45 -> V_412 ( V_45 ) ;
}
}
V_2 -> V_405 = false ;
}
static T_6 V_287 ( int V_134 , void * V_430 )
{
struct V_1 * V_2 = (struct V_1 * ) V_430 ;
unsigned long V_61 ;
F_92 ( V_2 -> V_40 -> V_431 , V_61 ) ;
if ( F_53 ( V_2 ) ) {
union V_59 V_60 ;
V_60 . V_66 = F_22 ( V_2 ) ;
if ( V_60 . V_73 . V_432 ) {
F_24 ( V_2 ) ;
if ( V_60 . V_73 . V_433 )
V_2 -> V_434 = true ;
else if ( V_60 . V_73 . V_435 )
F_87 ( V_2 ) ;
else if ( V_60 . V_73 . V_74 )
V_2 -> V_72 = true ;
}
} else {
if ( F_93 ( V_2 -> V_183 ) )
switch ( F_94 ( V_2 -> V_183 ) ) {
case V_436 :
break;
case V_437 :
V_2 -> V_434 = true ;
break;
case V_438 :
F_38 ( L_158 , V_2 ) ;
V_2 -> V_439 = true ;
break;
}
}
if ( V_2 -> V_300 != NULL )
F_89 ( V_2 ) ;
if ( V_2 -> V_434 ) {
F_38 ( L_159 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_440 ) ;
F_95 ( V_2 , false ) ;
V_2 -> V_434 = false ;
} else if ( V_2 -> V_439 ) {
F_38 ( L_160 , V_2 , V_2 -> V_8 ) ;
F_90 ( & V_2 -> V_441 ) ;
F_95 ( V_2 , true ) ;
V_2 -> V_439 = false ;
}
F_96 ( V_2 -> V_40 -> V_431 , V_61 ) ;
return V_442 ;
}
static bool F_97 ( struct V_1 * V_2 ,
enum V_443 V_444 , struct V_12 * V_13 )
{
struct V_307 * V_311 ;
V_311 = V_2 -> V_311 ;
if ( V_311 -> V_444 == V_445 ) {
V_13 -> V_17 = V_403 ;
V_311 -> V_13 = V_13 -> V_19 ;
V_311 -> V_444 = V_444 ;
F_98 ( V_2 ) ;
if ( ++ V_311 > V_2 -> V_310 )
V_311 = V_2 -> V_309 ;
V_2 -> V_311 = V_311 ;
if ( V_444 == V_446 ) {
V_2 -> V_305 [ V_13 -> V_201 ] ++ ;
if ( V_13 -> V_50 != V_407 )
V_2 -> V_408 [ V_13 -> V_201 ] . V_447 ++ ;
}
return true ;
}
return false ;
}
static int F_99 ( struct V_406 * V_448 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_448 -> V_133 -> V_6 -> V_7 ;
unsigned int V_152 = V_448 -> V_133 -> V_152 ;
struct V_449 * V_450 = & V_2 -> V_408 [ V_152 ] ;
int V_451 ;
F_100 ( V_448 -> V_133 -> V_6 -> V_431 ) ;
F_90 ( & V_450 -> V_452 ) ;
V_451 = F_95 ( V_2 , false ) ;
F_101 ( V_448 -> V_133 -> V_6 -> V_431 ) ;
return V_451 ;
}
static int F_102 ( struct V_406 * V_45 ,
void (* F_103) ( struct V_406 * ) )
{
struct V_1 * V_2 =
(struct V_1 * ) V_45 -> V_133 -> V_6 -> V_7 ;
struct V_425 * V_302 =
& V_2 -> V_302 [ V_45 -> V_133 -> V_152 ] ;
struct V_449 * V_408 = V_2 -> V_408 ;
unsigned char * V_422 = V_45 -> V_453 ;
int V_421 = V_45 -> V_454 ;
int V_201 = V_45 -> V_133 -> V_152 ;
int V_455 = V_45 -> V_133 -> V_455 ;
int V_456 = F_104 ( V_45 ) ;
int V_154 ;
struct V_12 * V_13 ;
T_1 V_457 ;
if ( V_422 [ 0 ] == V_458 && V_45 -> V_423 [ 0 ] != 0 ) {
V_45 -> V_63 = V_373 << 16 ;
F_103 ( V_45 ) ;
return 0 ;
}
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
F_101 ( V_2 -> V_40 -> V_431 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_431 ) ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 == NULL ) {
V_45 -> V_63 = V_392 << 16 ;
F_103 ( V_45 ) ;
return 0 ;
}
}
V_154 = F_105 ( V_45 ) ;
F_106 ( V_154 < 0 ) ;
if ( V_154 ) {
struct V_459 * V_460 ;
int V_84 ;
V_13 -> V_50 = V_461 ;
V_13 -> V_462 = V_154 * sizeof( struct V_463 ) ;
if ( F_53 ( V_2 ) )
V_13 -> V_464 = ( void * ) ( ( unsigned int ) V_13 -> V_19 +
( ( unsigned long ) & V_13 -> V_465 -
( unsigned long ) V_13 ) ) ;
else
V_13 -> V_464 = V_13 -> V_465 ;
F_107 (command, sg, count, i) {
V_13 -> V_465 [ V_84 ] . V_466 = F_108 ( V_460 ) ;
V_13 -> V_465 [ V_84 ] . V_467 = F_109 ( V_460 ) ;
}
} else if ( ! V_154 ) {
V_13 -> V_50 = V_468 ;
V_13 -> V_462 = V_456 ;
V_13 -> V_464 = 0 ;
}
switch ( V_422 [ 0 ] ) {
case V_469 :
case V_470 :
V_13 -> V_471 = V_472 ;
V_408 [ V_201 ] . V_473 ++ ;
F_110 ( & V_408 [ V_201 ] . V_474 , V_456 ) ;
F_111 ( V_408 [ V_201 ] . V_475 , V_456 ) ;
break;
case V_476 :
case V_477 :
V_13 -> V_471 = V_478 ;
V_408 [ V_201 ] . V_479 ++ ;
F_110 ( & V_408 [ V_201 ] . V_480 , V_456 ) ;
F_111 ( V_408 [ V_201 ] . V_481 , V_456 ) ;
break;
default:
V_13 -> V_471 = V_482 ;
break;
}
V_13 -> V_421 = V_421 ;
V_13 -> V_366 = 0 ;
V_13 -> V_368 = 0 ;
V_13 -> V_201 = V_201 ;
V_13 -> V_455 = V_455 ;
V_13 -> V_483 = false ;
V_13 -> V_484 = false ;
if ( V_2 -> V_306 [ V_201 ] ++ >= V_485 &&
! V_302 -> V_303 &&
V_2 -> V_305 [ V_201 ] == 0
&& V_302 -> V_229 &&
( V_2 -> V_229 & ( 1 << V_201 ) ) ) {
V_302 -> V_303 = true ;
F_12 ( L_161 ,
V_2 , V_201 ) ;
}
if ( V_302 -> V_303 ) {
enum V_486 V_487 = V_488 ;
if ( V_2 -> V_305 [ V_201 ] == 0 )
V_2 -> V_489 [ V_201 ] = V_411 ;
else if ( F_112 ( V_411 ,
V_2 -> V_489 [ V_201 ] + 4 * V_490 ) ) {
V_2 -> V_489 [ V_201 ] = V_411 ;
V_487 = V_491 ;
}
if ( V_2 -> V_213 ) {
V_13 -> V_483 = true ;
V_13 -> V_487 = V_487 ;
} else {
V_13 -> V_484 = true ;
V_13 -> V_492 = V_487 ;
}
}
memcpy ( V_13 -> V_422 , V_422 , V_421 ) ;
V_13 -> V_47 = V_493 ;
V_13 -> V_45 = V_45 ;
V_457 = F_113 ( V_2 -> V_32 ,
V_45 -> V_423 , V_13 -> V_47 ,
V_48 ) ;
if ( F_114 ( & V_2 -> V_32 -> V_116 , V_457 ) ) {
F_8 ( L_162 ,
V_2 ) ;
F_14 ( V_13 , 0 ) ;
return V_494 ;
}
V_13 -> V_46 = V_457 ;
V_45 -> V_412 = F_103 ;
if ( F_53 ( V_2 ) ) {
if ( ! F_97 ( V_2 , V_446 , V_13 ) ) {
F_101 ( V_2 -> V_40 -> V_431 ) ;
F_38 ( L_163 L_164 , V_2 ) ;
F_65 ( 1 ) ;
F_100 ( V_2 -> V_40 -> V_431 ) ;
if ( ! F_97 ( V_2 , V_446 ,
V_13 ) ) {
F_38 ( L_165 L_166 , V_2 ) ;
F_14 ( V_13 , 1 ) ;
V_45 -> V_63 = V_392 << 16 ;
V_45 -> V_412 ( V_45 ) ;
}
}
} else {
V_13 -> V_17 = V_403 ;
V_2 -> V_305 [ V_201 ] ++ ;
V_408 [ V_201 ] . V_447 ++ ;
F_115 ( V_2 -> V_183 , V_13 ) ;
if ( V_13 -> V_17 == V_364 )
F_89 ( V_2 ) ;
}
return 0 ;
}
int F_116 ( struct V_343 * V_495 , struct V_496 * V_116 ,
T_7 V_497 , int * V_498 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_495 -> V_6 -> V_7 ;
struct V_499 * V_500 = (struct V_499 * ) V_498 ;
unsigned char * V_501 ;
if ( V_2 -> V_205 && V_497 >= 2 * 1024 * 1024 ) {
if ( V_497 >= 4 * 1024 * 1024 ) {
V_500 -> V_502 = 255 ;
V_500 -> V_503 = 63 ;
} else {
V_500 -> V_502 = 128 ;
V_500 -> V_503 = 32 ;
}
} else {
V_500 -> V_502 = 64 ;
V_500 -> V_503 = 32 ;
}
V_500 -> V_504 = ( unsigned long ) V_497 / ( V_500 -> V_502 * V_500 -> V_503 ) ;
V_501 = F_117 ( V_116 ) ;
if ( V_501 == NULL )
return 0 ;
if ( * ( unsigned short * ) ( V_501 + 64 ) == 0xAA55 ) {
struct V_505 * V_506 = (struct V_505 * ) V_501 ;
struct V_505 * V_507 = V_506 ;
int V_508 = V_500 -> V_504 , V_509 ;
unsigned char V_510 = 0 , V_511 = 0 ;
for ( V_509 = 0 ; V_509 < 4 ; V_509 ++ ) {
V_510 = V_507 -> V_512 ;
V_511 = V_507 -> V_513 & 0x3F ;
if ( V_510 == 64 - 1 ) {
V_500 -> V_502 = 64 ;
V_500 -> V_503 = 32 ;
break;
} else if ( V_510 == 128 - 1 ) {
V_500 -> V_502 = 128 ;
V_500 -> V_503 = 32 ;
break;
} else if ( V_510 == 255 - 1 ) {
V_500 -> V_502 = 255 ;
V_500 -> V_503 = 63 ;
break;
}
V_507 ++ ;
}
if ( V_509 == 4 ) {
V_510 = V_506 -> V_512 ;
V_511 = V_506 -> V_513 & 0x3F ;
}
V_500 -> V_504 = ( unsigned long ) V_497 / ( V_500 -> V_502 * V_500 -> V_503 ) ;
if ( V_509 < 4 && V_511 == V_500 -> V_503 ) {
if ( V_500 -> V_504 != V_508 )
F_38 ( L_167 , V_2 , V_500 -> V_502 , V_500 -> V_503 ) ;
} else if ( V_510 > 0 || V_511 > 0 ) {
F_38 ( L_168 L_169 , V_2 , V_510 + 1 , V_511 ) ;
F_38 ( L_170 L_171 , V_2 , V_500 -> V_502 , V_500 -> V_503 ) ;
}
}
F_73 ( V_501 ) ;
return 0 ;
}
static int F_118 ( struct V_5 * V_514 , char * V_515 ,
int V_516 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_514 -> V_7 ;
struct V_449 * V_408 ;
V_408 = V_2 -> V_408 ;
V_2 -> V_440 = 0 ;
V_2 -> V_441 = 0 ;
memset ( V_408 , 0 , V_264 * sizeof( struct V_449 ) ) ;
return 0 ;
}
static int F_119 ( struct V_517 * V_518 , struct V_5 * V_514 )
{
struct V_1 * V_2 = (struct V_1 * ) V_514 -> V_7 ;
struct V_449 * V_408 ;
int V_199 ;
V_408 = V_2 -> V_408 ;
F_120 ( V_518 , V_2 -> V_519 , V_2 -> V_520 ) ;
F_121 ( V_518 , L_172 , V_2 -> V_38 , V_2 -> V_29 ) ;
F_121 ( V_518 , L_173 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_221 ; V_199 ++ ) {
struct V_425 * V_302 = & V_2 -> V_302 [ V_199 ] ;
if ( ! V_302 -> V_326 )
continue;
F_121 ( V_518 , L_174 , V_199 , ( V_302 -> V_229 ? ( V_302 -> V_303 ? L_175 : ( V_2 -> V_229 & ( 1 << V_199 )
? L_176 : L_177 ) )
: L_178 ) ) ;
F_121 ( V_518 ,
L_179 , V_2 -> V_265 [ V_199 ] , V_2 -> V_305 [ V_199 ] , V_408 [ V_199 ] . V_447 , V_408 [ V_199 ] . V_415 ) ;
}
F_121 ( V_518 , L_180 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_221 ; V_199 ++ ) {
struct V_425 * V_302 = & V_2 -> V_302 [ V_199 ] ;
if ( ! V_302 -> V_326 )
continue;
F_121 ( V_518 , L_181 , V_199 , V_408 [ V_199 ] . V_473 , V_408 [ V_199 ] . V_479 ) ;
if ( V_408 [ V_199 ] . V_474 . V_521 > 0 )
F_121 ( V_518 , L_182 , V_408 [ V_199 ] . V_474 . V_521 , V_408 [ V_199 ] . V_474 . V_522 ) ;
else
F_121 ( V_518 , L_183 , V_408 [ V_199 ] . V_474 . V_522 ) ;
if ( V_408 [ V_199 ] . V_480 . V_521 > 0 )
F_121 ( V_518 , L_184 , V_408 [ V_199 ] . V_480 . V_521 , V_408 [ V_199 ] . V_480 . V_522 ) ;
else
F_121 ( V_518 , L_185 , V_408 [ V_199 ] . V_480 . V_522 ) ;
}
F_121 ( V_518 , L_186 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_221 ; V_199 ++ ) {
struct V_425 * V_302 = & V_2 -> V_302 [ V_199 ] ;
if ( ! V_302 -> V_326 )
continue;
F_121 ( V_518 ,
L_187 , V_199 ,
V_408 [ V_199 ] . V_475 [ 0 ] ,
V_408 [ V_199 ] . V_475 [ 1 ] , V_408 [ V_199 ] . V_475 [ 2 ] , V_408 [ V_199 ] . V_475 [ 3 ] , V_408 [ V_199 ] . V_475 [ 4 ] ) ;
F_121 ( V_518 ,
L_188 , V_199 ,
V_408 [ V_199 ] . V_481 [ 0 ] ,
V_408 [ V_199 ] . V_481 [ 1 ] , V_408 [ V_199 ] . V_481 [ 2 ] , V_408 [ V_199 ] . V_481 [ 3 ] , V_408 [ V_199 ] . V_481 [ 4 ] ) ;
}
F_121 ( V_518 , L_189 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_221 ; V_199 ++ ) {
struct V_425 * V_302 = & V_2 -> V_302 [ V_199 ] ;
if ( ! V_302 -> V_326 )
continue;
F_121 ( V_518 ,
L_187 , V_199 ,
V_408 [ V_199 ] . V_475 [ 5 ] ,
V_408 [ V_199 ] . V_475 [ 6 ] , V_408 [ V_199 ] . V_475 [ 7 ] , V_408 [ V_199 ] . V_475 [ 8 ] , V_408 [ V_199 ] . V_475 [ 9 ] ) ;
F_121 ( V_518 ,
L_188 , V_199 ,
V_408 [ V_199 ] . V_481 [ 5 ] ,
V_408 [ V_199 ] . V_481 [ 6 ] , V_408 [ V_199 ] . V_481 [ 7 ] , V_408 [ V_199 ] . V_481 [ 8 ] , V_408 [ V_199 ] . V_481 [ 9 ] ) ;
}
F_121 ( V_518 , L_190 ) ;
for ( V_199 = 0 ; V_199 < V_2 -> V_221 ; V_199 ++ ) {
struct V_425 * V_302 = & V_2 -> V_302 [ V_199 ] ;
if ( ! V_302 -> V_326 )
continue;
F_121 ( V_518 , L_191 , V_199 , V_408 [ V_199 ] . V_523 , V_408 [ V_199 ] . V_524 , V_408 [ V_199 ] . V_417 , V_408 [ V_199 ] . V_525 , V_408 [ V_199 ] . V_526 , V_408 [ V_199 ] . V_409 , V_408 [ V_199 ] . V_452 , V_408 [ V_199 ] . V_527 , V_408 [ V_199 ] . V_528 ) ;
}
F_121 ( V_518 , L_192 , V_2 -> V_440 ) ;
F_121 ( V_518 , L_193 , V_2 -> V_441 ) ;
return 0 ;
}
static void F_122 ( enum V_529 V_530 , char * V_531 ,
struct V_1 * V_2 , ... )
{
static char V_501 [ V_532 ] ;
static bool V_533 = true ;
T_8 args ;
int V_534 = 0 ;
va_start ( args , V_2 ) ;
V_534 = vsprintf ( V_501 , V_531 , args ) ;
va_end ( args ) ;
if ( V_530 == V_535 ) {
static int V_536 = 0 ;
strcpy ( & V_2 -> V_519 [ V_2 -> V_520 ] , V_501 ) ;
V_2 -> V_520 += V_534 ;
if ( ++ V_536 <= 2 )
F_78 ( L_194 , V_537 [ V_530 ] , V_501 ) ;
} else if ( V_530 == V_538 ) {
strcpy ( & V_2 -> V_519 [ V_2 -> V_520 ] , V_501 ) ;
V_2 -> V_520 += V_534 ;
if ( V_533 ) {
if ( V_501 [ 0 ] != '\n' || V_534 > 1 )
F_78 ( L_195 , V_537 [ V_530 ] , V_2 -> V_360 , V_501 ) ;
} else
F_78 ( L_196 , V_501 ) ;
} else {
if ( V_533 ) {
if ( V_2 != NULL && V_2 -> V_321 )
F_78 ( L_195 , V_537 [ V_530 ] , V_2 -> V_360 , V_501 ) ;
else
F_78 ( L_197 , V_537 [ V_530 ] , V_501 ) ;
} else
F_78 ( L_196 , V_501 ) ;
}
V_533 = ( V_501 [ V_534 - 1 ] == '\n' ) ;
}
static bool T_2 F_123 ( char * * V_539 , char * V_540 )
{
char * V_541 = * V_539 ;
while ( * V_540 != '\0' ) {
char V_542 = * V_541 ++ ;
char V_543 = * V_540 ++ ;
if ( V_542 >= 'A' && V_542 <= 'Z' )
V_542 += 'a' - 'Z' ;
if ( V_543 >= 'A' && V_543 <= 'Z' )
V_543 += 'a' - 'Z' ;
if ( V_542 != V_543 )
return false ;
}
* V_539 = V_541 ;
return true ;
}
static int T_2 F_124 ( char * V_544 )
{
while ( true ) {
struct V_358 * V_266 =
& V_358 [ V_357 ++ ] ;
int V_201 ;
memset ( V_266 , 0 , sizeof( struct V_358 ) ) ;
while ( * V_544 != '\0' && * V_544 != ';' ) {
if ( F_123 ( & V_544 , L_198 ) ) {
unsigned long V_89 = F_125 ( V_544 ,
& V_544 , 0 ) ;
V_99 . V_101 = true ;
switch ( V_89 ) {
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
F_8 ( L_199 L_200 , NULL , V_89 ) ;
return 0 ;
}
} else if ( F_123 ( & V_544 , L_201 ) )
V_99 . V_100 = true ;
else if ( F_123 ( & V_544 , L_202 ) )
V_99 . V_164 = true ;
else if ( F_123 ( & V_544 , L_203 ) )
V_99 . V_351 = true ;
else if ( F_123 ( & V_544 , L_204 ) )
V_99 . V_545 = true ;
else if ( F_123 ( & V_544 , L_205 ) )
V_99 . V_165 = true ;
else if ( F_123 ( & V_544 , L_206 ) )
V_99 . V_166 = true ;
else if ( F_123 ( & V_544 , L_207 ) ||
F_123 ( & V_544 , L_208 ) ) {
for ( V_201 = 0 ; V_201 < V_264 ; V_201 ++ ) {
unsigned short V_265 = F_125 ( V_544 , & V_544 , 0 ) ;
if ( V_265 > V_485 ) {
F_8 ( L_199 L_209 , NULL , V_265 ) ;
return 0 ;
}
V_266 -> V_265 [ V_201 ] = V_265 ;
if ( * V_544 == ',' )
V_544 ++ ;
else if ( * V_544 == ']' )
break;
else {
F_8 ( L_199 L_210 , NULL , V_544 ) ;
return 0 ;
}
}
if ( * V_544 != ']' ) {
F_8 ( L_199 L_211 , NULL , V_544 ) ;
return 0 ;
} else
V_544 ++ ;
} else if ( F_123 ( & V_544 , L_212 ) || F_123 ( & V_544 , L_213 ) ) {
unsigned short V_265 = F_125 ( V_544 , & V_544 , 0 ) ;
if ( V_265 == 0 ||
V_265 > V_485 ) {
F_8 ( L_199 L_209 , NULL , V_265 ) ;
return 0 ;
}
V_266 -> V_271 = V_265 ;
for ( V_201 = 0 ; V_201 < V_264 ; V_201 ++ )
V_266 -> V_265 [ V_201 ] = V_265 ;
} else if ( F_123 ( & V_544 , L_214 ) ||
F_123 ( & V_544 , L_215 ) ) {
if ( F_123 ( & V_544 , L_216 ) ) {
V_266 -> V_229 = 0x0000 ;
V_266 -> V_272 = 0x0000 ;
} else if ( F_123 ( & V_544 , L_217 ) ) {
V_266 -> V_229 = 0xFFFF ;
V_266 -> V_272 = 0xFFFF ;
} else if ( F_123 ( & V_544 , L_218 ) ) {
V_266 -> V_229 = 0x0000 ;
V_266 -> V_272 = 0xFFFF ;
} else {
unsigned short V_546 ;
for ( V_201 = 0 , V_546 = 1 ;
V_201 < V_264 ;
V_201 ++ , V_546 <<= 1 )
switch ( * V_544 ++ ) {
case 'Y' :
V_266 -> V_229 |= V_546 ;
V_266 -> V_272 |= V_546 ;
break;
case 'N' :
V_266 -> V_229 &= ~ V_546 ;
V_266 -> V_272 |= V_546 ;
break;
case 'X' :
break;
default:
V_544 -- ;
V_201 = V_264 ;
break;
}
}
}
else if ( F_123 ( & V_544 , L_219 ) ||
F_123 ( & V_544 , L_220 ) ) {
unsigned short V_273 =
F_125 ( V_544 , & V_544 , 0 ) ;
if ( V_273 > 5 * 60 ) {
F_8 ( L_199 L_221 , NULL , V_273 ) ;
return 0 ;
}
V_266 -> V_273 = V_273 ;
} else if ( F_123 ( & V_544 ,
L_222 ) )
V_266 -> V_325 = true ;
else if ( F_123 ( & V_544 , L_223 ) )
V_78 . V_143 = true ;
else if ( F_123 ( & V_544 , L_224 ) )
V_78 . V_185 = true ;
else if ( F_123 ( & V_544 , L_225 ) )
V_78 . V_79 = true ;
else if ( F_123 ( & V_544 , L_226 ) )
V_78 . V_420 = true ;
else if ( F_123 ( & V_544 , L_227 ) ) {
V_78 . V_143 = true ;
V_78 . V_185 = true ;
V_78 . V_79 = true ;
V_78 . V_420 = true ;
}
if ( * V_544 == ',' )
V_544 ++ ;
else if ( * V_544 != ';' && * V_544 != '\0' ) {
F_8 ( L_228 L_229 , NULL , V_544 ) ;
* V_544 = '\0' ;
}
}
if ( ! ( V_357 == 0 ||
V_92 == 0 ||
V_357 == V_92 ) ) {
F_8 ( L_199 L_230 , NULL ) ;
return 0 ;
}
for ( V_201 = 0 ; V_201 < V_264 ; V_201 ++ )
if ( V_266 -> V_265 [ V_201 ] == 1 ) {
unsigned short V_546 = 1 << V_201 ;
V_266 -> V_229 &= ~ V_546 ;
V_266 -> V_272 |= V_546 ;
}
if ( * V_544 == ';' )
V_544 ++ ;
if ( * V_544 == '\0' )
return 0 ;
}
return 1 ;
}
static int T_2 F_71 ( char * V_539 )
{
int V_547 [ 3 ] ;
( void ) F_126 ( V_539 , F_127 ( V_547 ) , V_547 ) ;
if ( V_547 [ 0 ] != 0 ) {
F_8 ( L_231 L_232 , NULL ) ;
return 0 ;
}
if ( V_539 == NULL || * V_539 == '\0' )
return 0 ;
return F_124 ( V_539 ) ;
}
static void T_5 F_128 ( void )
{
struct V_1 * V_548 , * V_25 ;
F_129 (ha, next, &blogic_host_list, host_list)
F_83 ( V_548 ) ;
}
