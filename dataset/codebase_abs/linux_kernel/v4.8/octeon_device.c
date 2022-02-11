static void F_1 ( int V_1 , int V_2 )
{
if ( V_2 < 0 || V_2 > ( V_3 - 1 ) )
V_2 = V_4 ;
V_5 [ V_1 ] . V_2 = V_2 ;
}
void F_2 ( int V_2 )
{
int V_6 ;
memset ( V_7 , 0 , ( sizeof( void * ) * V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_1 ( V_6 , V_2 ) ;
}
static void * F_3 ( struct V_7 * V_9 ,
T_1 V_10 )
{
T_2 V_1 = V_9 -> V_11 ;
void * V_12 = NULL ;
switch ( V_5 [ V_1 ] . V_2 ) {
case V_4 :
if ( V_9 -> V_13 == V_14 ) {
V_12 = ( void * ) & V_15 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_17 ) ) {
V_12 = ( void * ) & V_18 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_19 ) ) {
V_12 = ( void * ) & V_20 ;
}
break;
default:
break;
}
return V_12 ;
}
static int F_4 ( struct V_7 * V_9 , void * V_21 )
{
switch ( V_9 -> V_13 ) {
case V_14 :
case V_16 :
return F_5 ( V_9 , V_21 ) ;
default:
break;
}
return 1 ;
}
void * F_6 ( struct V_7 * V_9 , T_1 V_10 )
{
void * V_21 = NULL ;
V_21 = F_3 ( V_9 , V_10 ) ;
if ( ! V_21 )
return NULL ;
if ( F_4 ( V_9 , V_21 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_1 ) ;
return NULL ;
}
return V_21 ;
}
char * F_8 ( T_3 * V_24 )
{
T_4 V_25 = ( T_4 ) F_9 ( V_24 ) ;
if ( V_25 > V_26 || V_25 < 0 )
return V_27 [ V_28 ] ;
return V_27 [ V_25 ] ;
}
static char * F_10 ( T_2 V_29 )
{
if ( V_29 <= V_30 )
return V_31 [ V_29 - V_32 ] ;
return V_31 [ V_33 - V_32 ] ;
}
int F_11 ( struct V_7 * V_9 , const T_5 * V_34 ,
T_6 V_35 )
{
int V_12 = 0 ;
T_5 * V_36 = V_37 ;
T_2 V_38 ;
T_7 V_39 ;
T_2 V_40 ;
struct V_41 * V_42 ;
T_2 V_6 , V_43 , V_44 = strlen ( V_45 ) ;
char * V_46 ;
if ( V_35 < sizeof( struct V_41 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_2 ,
( T_2 ) V_35 ,
( T_2 ) sizeof( struct V_41 ) ) ;
return - V_47 ;
}
V_42 = (struct V_41 * ) V_34 ;
if ( F_12 ( V_42 -> V_48 ) != V_49 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_3 ) ;
return - V_47 ;
}
V_38 = F_13 ( ( unsigned int ) ~ 0 , V_34 ,
sizeof( struct V_41 ) -
sizeof( T_2 ) ) ^ ~ 0U ;
if ( V_38 != F_12 ( V_42 -> F_13 ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_4 ,
V_38 , F_12 ( V_42 -> F_13 ) ) ;
return - V_47 ;
}
if ( strncmp ( V_50 , V_42 -> V_51 , strlen ( V_50 ) ) ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_5 ,
V_50 , V_42 -> V_51 ) ;
return - V_47 ;
}
V_46 = V_42 -> V_51 + strlen ( V_50 ) ;
V_12 = memcmp ( V_45 , V_46 , V_44 ) ;
if ( V_12 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_6 ,
V_45 , V_46 ) ;
return - V_47 ;
}
if ( F_12 ( V_42 -> V_52 ) > V_53 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_7 ,
F_12 ( V_42 -> V_52 ) ) ;
return - V_47 ;
}
F_14 ( & V_9 -> V_22 -> V_23 , L_8 , V_42 -> V_51 ) ;
snprintf ( V_9 -> V_54 . V_55 , 32 , L_9 ,
V_42 -> V_51 ) ;
V_34 += sizeof( struct V_41 ) ;
F_14 ( & V_9 -> V_22 -> V_23 , L_10 , V_56 ,
F_12 ( V_42 -> V_52 ) ) ;
for ( V_6 = 0 ; V_6 < F_12 ( V_42 -> V_52 ) ; V_6 ++ ) {
V_39 = F_15 ( V_42 -> V_57 [ V_6 ] . V_58 ) ;
V_40 = F_12 ( V_42 -> V_57 [ V_6 ] . V_59 ) ;
F_14 ( & V_9 -> V_22 -> V_23 , L_11 ,
V_40 , V_39 ) ;
V_43 = V_40 ;
while ( V_43 ) {
if ( V_43 < ( 4 * 1024 * 1024 ) )
V_35 = V_43 ;
else
V_35 = 4 * 1024 * 1024 ;
memcpy ( V_36 , V_34 , V_35 ) ;
F_16 ( V_9 , V_39 , V_36 , ( T_2 ) V_35 ) ;
V_34 += V_35 ;
V_43 -= ( T_2 ) V_35 ;
V_39 += V_35 ;
}
}
F_14 ( & V_9 -> V_22 -> V_23 , L_12 ,
V_42 -> V_60 ) ;
V_12 = F_17 ( V_9 , V_42 -> V_60 , 50 ) ;
return 0 ;
}
void F_18 ( struct V_7 * V_9 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_19 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_61 . V_62 & ( 1ULL << V_6 ) )
F_20 ( V_9 -> V_63 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < F_21 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_61 . V_64 & ( 1ULL << V_6 ) )
F_20 ( V_9 -> V_65 [ V_6 ] ) ;
}
V_6 = V_9 -> V_11 ;
F_20 ( V_9 ) ;
V_7 [ V_6 ] = NULL ;
V_66 -- ;
}
static struct V_7 * F_22 ( T_2 V_67 ,
T_2 V_68 )
{
struct V_7 * V_9 ;
T_5 * V_69 = NULL ;
T_2 V_70 = 0 , V_71 = 0 , V_35 ;
switch ( V_67 ) {
case V_16 :
case V_14 :
V_71 = sizeof( struct V_72 ) ;
break;
default:
F_23 ( L_13 ,
V_56 ,
V_67 ) ;
return NULL ;
}
if ( V_71 & 0x7 )
V_71 += ( 8 - ( V_71 & 0x7 ) ) ;
V_70 = sizeof( struct V_7 ) ;
if ( V_70 & 0x7 )
V_70 += ( 8 - ( V_70 & 0x7 ) ) ;
if ( V_68 & 0x7 )
V_68 += ( 8 - ( V_68 & 0x7 ) ) ;
V_35 = V_70 + V_68 + V_71 +
( sizeof( struct V_73 ) * V_74 ) ;
V_69 = F_24 ( V_35 ) ;
if ( ! V_69 )
return NULL ;
memset ( V_69 , 0 , V_35 ) ;
V_9 = (struct V_7 * ) V_69 ;
V_9 -> V_75 = ( void * ) ( V_69 + V_70 ) ;
V_9 -> V_76 = ( void * ) ( V_69 + V_70 + V_68 ) ;
V_9 -> V_77 . V_78 = (struct V_73 * )
( V_69 + V_70 + V_68 + V_71 ) ;
return V_9 ;
}
struct V_7 * F_25 ( T_2 V_67 ,
T_2 V_68 )
{
T_2 V_79 = 0 ;
struct V_7 * V_9 = NULL ;
for ( V_79 = 0 ; V_79 < V_8 ; V_79 ++ )
if ( ! V_7 [ V_79 ] )
break;
if ( V_79 == V_8 )
return NULL ;
V_9 = F_22 ( V_67 , V_68 ) ;
if ( ! V_9 )
return NULL ;
F_26 ( & V_9 -> V_80 ) ;
F_26 ( & V_9 -> V_81 ) ;
V_66 ++ ;
V_7 [ V_79 ] = V_9 ;
V_9 -> V_11 = V_79 ;
snprintf ( V_9 -> V_82 , sizeof( V_9 -> V_82 ) ,
L_14 , ( V_9 -> V_11 ) ) ;
return V_9 ;
}
int F_27 ( struct V_7 * V_9 )
{
T_2 V_83 = 0 ;
T_2 V_84 = 0 ;
union V_85 V_86 ;
int V_87 = F_28 ( V_84 % F_29 () ) ;
if ( F_30 ( V_9 ) )
V_83 =
F_31 ( F_32 ( V_9 , V_88 , V_21 ) ) ;
V_9 -> V_89 = 0 ;
V_9 -> V_65 [ 0 ] = F_33 ( sizeof( * V_9 -> V_65 [ 0 ] ) ,
V_87 ) ;
if ( ! V_9 -> V_65 [ 0 ] )
V_9 -> V_65 [ 0 ] =
F_24 ( sizeof( struct V_90 ) ) ;
if ( ! V_9 -> V_65 [ 0 ] )
return 1 ;
memset ( V_9 -> V_65 [ 0 ] , 0 , sizeof( struct V_90 ) ) ;
V_9 -> V_65 [ 0 ] -> V_91 = 0 ;
V_9 -> V_65 [ 0 ] -> V_92 = ( void * ) ( T_6 ) 0 ;
V_9 -> V_65 [ 0 ] -> V_93 = 0 ;
V_86 . T_7 = 0 ;
V_86 . V_94 . V_95 = V_84 ;
V_86 . V_94 . V_96 = 0 ;
V_86 . V_94 . V_97 = 0 ;
if ( F_34 ( V_9 , V_86 , V_83 ) ) {
F_20 ( V_9 -> V_65 [ 0 ] ) ;
return 1 ;
}
V_9 -> V_89 ++ ;
return 0 ;
}
int F_35 ( struct V_7 * V_9 )
{
T_2 V_83 = 0 ;
T_2 V_98 = 0 ;
T_2 V_99 = 0 ;
int V_87 = F_28 ( V_99 % F_29 () ) ;
if ( F_30 ( V_9 ) ) {
V_83 =
F_36 ( F_32 ( V_9 , V_88 , V_21 ) ) ;
V_98 =
F_37 ( F_32 ( V_9 , V_88 , V_21 ) ) ;
}
V_9 -> V_100 = 0 ;
V_9 -> V_63 [ 0 ] = F_33 ( sizeof( * V_9 -> V_63 [ 0 ] ) , V_87 ) ;
if ( ! V_9 -> V_63 [ 0 ] )
V_9 -> V_63 [ 0 ] = F_24 ( sizeof( * V_9 -> V_63 [ 0 ] ) ) ;
if ( ! V_9 -> V_63 [ 0 ] )
return 1 ;
if ( F_38 ( V_9 , V_99 , V_83 , V_98 , NULL ) )
return 1 ;
V_9 -> V_100 ++ ;
return 0 ;
}
void F_39 ( struct V_7 * V_9 )
{
F_40 ( V_9 , V_101 , 0 ) ;
F_40 ( V_9 , V_102 , 0 ) ;
}
void F_41 ( struct V_7 * V_9 ,
T_2 V_95 ,
T_2 V_103 )
{
T_2 V_104 = 0 ;
V_104 = F_42 ( V_9 , V_102 ) ;
if ( V_103 )
V_104 = V_104 | ( 1 << V_95 ) ;
else
V_104 = V_104 & ( ~ ( 1 << V_95 ) ) ;
F_40 ( V_9 , V_102 , V_104 ) ;
}
int F_43 ( struct V_7 * V_9 )
{
T_2 V_6 ;
V_9 -> V_77 . V_105 = 0 ;
for ( V_6 = 0 ; V_6 < V_74 ; V_6 ++ ) {
V_9 -> V_77 . V_78 [ V_6 ] . V_106 = 0 ;
F_44 ( & V_9 -> V_77 . V_78 [ V_6 ] . V_107 ) ;
}
for ( V_6 = 0 ; V_6 <= V_108 ; V_6 ++ )
F_45 ( V_9 , V_6 , NULL ) ;
F_26 ( & V_9 -> V_77 . V_109 ) ;
return 0 ;
}
void F_46 ( struct V_7 * V_9 )
{
T_2 V_6 ;
struct V_110 V_111 , * V_112 , * V_113 ;
F_44 ( & V_111 ) ;
F_47 ( & V_9 -> V_77 . V_109 ) ;
for ( V_6 = 0 ; V_6 < V_74 ; V_6 ++ ) {
struct V_110 * V_77 ;
V_77 = & V_9 -> V_77 . V_78 [ V_6 ] . V_107 ;
while ( V_77 -> V_114 != V_77 ) {
V_112 = V_77 -> V_114 ;
F_48 ( V_112 ) ;
F_49 ( V_112 , & V_111 ) ;
}
V_9 -> V_77 . V_78 [ V_6 ] . V_106 = 0 ;
}
V_9 -> V_77 . V_105 = 0 ;
F_50 ( & V_9 -> V_77 . V_109 ) ;
F_51 (temp, tmp2, &freelist) {
F_48 ( V_112 ) ;
F_20 ( V_112 ) ;
}
}
T_8
F_52 ( struct V_7 * V_115 , T_1 V_106 ,
T_1 V_116 )
{
T_2 V_117 ;
struct V_110 * V_77 ;
T_8 V_118 = NULL ;
T_1 V_119 = F_53 ( V_106 , V_116 ) ;
V_117 = V_119 & V_120 ;
F_47 ( & V_115 -> V_77 . V_109 ) ;
if ( V_115 -> V_77 . V_105 == 0 ) {
F_50 ( & V_115 -> V_77 . V_109 ) ;
return NULL ;
}
if ( ! ( V_115 -> V_77 . V_78 [ V_117 ] . V_106 ) ) {
F_50 ( & V_115 -> V_77 . V_109 ) ;
return NULL ;
}
if ( V_115 -> V_77 . V_78 [ V_117 ] . V_106 == V_119 ) {
V_118 = V_115 -> V_77 . V_78 [ V_117 ] . V_121 ;
} else {
F_54 (dispatch,
&octeon_dev->dispatch.dlist[idx].list) {
if ( ( (struct V_73 * ) V_77 ) -> V_106 ==
V_119 ) {
V_118 = ( (struct V_73 * )
V_77 ) -> V_121 ;
break;
}
}
}
F_50 ( & V_115 -> V_77 . V_109 ) ;
return V_118 ;
}
int
F_55 ( struct V_7 * V_9 ,
T_1 V_106 ,
T_1 V_116 ,
T_8 V_118 , void * V_122 )
{
T_2 V_117 ;
T_8 V_123 ;
T_1 V_119 = F_53 ( V_106 , V_116 ) ;
V_117 = V_119 & V_120 ;
F_47 ( & V_9 -> V_77 . V_109 ) ;
if ( V_9 -> V_77 . V_78 [ V_117 ] . V_106 == 0 ) {
V_9 -> V_77 . V_78 [ V_117 ] . V_106 = V_119 ;
V_9 -> V_77 . V_78 [ V_117 ] . V_121 = V_118 ;
V_9 -> V_77 . V_78 [ V_117 ] . V_124 = V_122 ;
V_9 -> V_77 . V_105 ++ ;
F_50 ( & V_9 -> V_77 . V_109 ) ;
return 0 ;
}
F_50 ( & V_9 -> V_77 . V_109 ) ;
V_123 = F_52 ( V_9 , V_106 , V_116 ) ;
if ( ! V_123 ) {
struct V_73 * V_77 ;
F_56 ( & V_9 -> V_22 -> V_23 ,
L_15 ) ;
V_77 = (struct V_73 * )
F_24 ( sizeof( struct V_73 ) ) ;
if ( ! V_77 ) {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_16 ) ;
return 1 ;
}
V_77 -> V_106 = V_119 ;
V_77 -> V_121 = V_118 ;
V_77 -> V_124 = V_122 ;
F_47 ( & V_9 -> V_77 . V_109 ) ;
F_57 ( & V_77 -> V_107 , & V_9 -> V_77 . V_78 [ V_117 ] . V_107 ) ;
V_9 -> V_77 . V_105 ++ ;
F_50 ( & V_9 -> V_77 . V_109 ) ;
} else {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_17 ,
V_106 , V_116 ) ;
return 1 ;
}
return 0 ;
}
int F_58 ( struct V_125 * V_126 , void * V_69 )
{
T_2 V_6 ;
char V_127 [ 16 ] ;
struct V_7 * V_9 = (struct V_7 * ) V_69 ;
struct V_128 * V_129 = V_126 -> V_129 ;
struct V_130 * V_131 = NULL ;
T_2 V_132 = 0 ;
if ( F_30 ( V_9 ) )
V_132 =
F_59 ( F_32 ( V_9 , V_88 , V_21 ) ) ;
if ( F_9 ( & V_9 -> V_133 ) >= V_134 ) {
F_7 ( & V_9 -> V_22 -> V_23 , L_18 ,
F_9 ( & V_9 -> V_133 ) ) ;
goto V_135;
}
strncpy ( V_127 ,
F_10 (
( T_2 ) V_129 -> V_136 . V_137 . V_29 ) ,
sizeof( V_127 ) - 1 ) ;
V_9 -> V_29 = ( T_2 ) V_129 -> V_136 . V_137 . V_29 ;
if ( V_129 -> V_136 . V_137 . V_29 == V_138 ) {
V_9 -> V_54 . V_139 =
( T_2 ) V_129 -> V_136 . V_137 . V_139 ;
V_9 -> V_54 . V_140 =
( T_2 ) V_129 -> V_136 . V_137 . V_140 ;
}
if ( V_9 -> V_54 . V_139 < V_132 ) {
F_7 ( & V_9 -> V_22 -> V_23 ,
L_19 ,
V_132 , V_9 -> V_54 . V_139 ) ;
goto V_135;
}
V_9 -> V_54 . V_141 = V_129 -> V_136 . V_137 . V_141 ;
V_9 -> V_54 . V_29 = ( T_2 ) V_129 -> V_136 . V_137 . V_29 ;
F_60 ( & V_9 -> V_133 , V_142 ) ;
V_131 = & V_143 [ V_9 -> V_11 ] ;
if ( V_129 -> V_144 [ 0 ] != sizeof( * V_131 ) ) {
F_56 ( & V_9 -> V_22 -> V_23 , L_20 ,
( T_2 ) sizeof( * V_131 ) ,
V_129 -> V_144 [ 0 ] ) ;
}
memcpy ( V_131 , F_61 ( V_129 -> V_145 [ 0 ] ) , sizeof( * V_131 ) ) ;
strncpy ( V_9 -> V_146 . V_147 , V_131 -> V_148 , V_149 ) ;
strncpy ( V_9 -> V_146 . V_150 , V_131 -> V_151 ,
V_152 ) ;
F_62 ( ( T_7 * ) V_131 , ( sizeof( * V_131 ) >> 3 ) ) ;
V_9 -> V_146 . V_153 = V_131 -> V_154 ;
V_9 -> V_146 . V_155 = V_131 -> V_156 ;
F_14 ( & V_9 -> V_22 -> V_23 ,
L_21 ,
V_127 , F_63 ( V_131 -> V_157 ) ) ;
V_135:
for ( V_6 = 0 ; V_6 < V_129 -> V_158 ; V_6 ++ )
F_64 ( V_129 -> V_145 [ V_6 ] ) ;
F_65 ( V_126 ) ;
return 0 ;
}
int F_66 ( struct V_7 * V_9 , T_2 V_95 )
{
if ( V_9 && ( V_95 < F_21 ( V_9 ) ) &&
( V_9 -> V_61 . V_64 & ( 1ULL << V_95 ) ) )
return V_9 -> V_65 [ V_95 ] -> V_159 ;
return - 1 ;
}
int F_67 ( struct V_7 * V_9 , T_2 V_95 )
{
if ( V_9 && ( V_95 < F_19 ( V_9 ) ) &&
( V_9 -> V_61 . V_62 & ( 1ULL << V_95 ) ) )
return V_9 -> V_63 [ V_95 ] -> V_159 ;
return - 1 ;
}
struct V_160 * F_68 ( struct V_7 * V_9 )
{
struct V_160 * V_161 = NULL ;
if ( F_30 ( V_9 ) ) {
V_161 =
(struct V_160 * ) ( F_32 ( V_9 , V_88 , V_21 ) ) ;
}
return V_161 ;
}
struct V_7 * F_69 ( T_2 V_11 )
{
if ( V_11 >= V_8 )
return NULL ;
else
return V_7 [ V_11 ] ;
}
T_7 F_70 ( struct V_7 * V_9 , T_7 V_58 )
{
T_7 V_162 ;
unsigned long V_163 ;
T_2 V_164 , V_165 ;
F_71 ( & V_9 -> V_80 , V_163 ) ;
V_165 = ( V_58 >> 32 ) ;
if ( ( V_9 -> V_13 == V_14 ) || ( V_9 -> V_13 == V_16 ) )
V_165 |= 0x00060000 ;
F_72 ( V_165 , V_9 -> V_166 . V_167 ) ;
V_164 = F_73 ( V_9 -> V_166 . V_167 ) ;
F_72 ( V_58 & 0xffffffff , V_9 -> V_166 . V_168 ) ;
V_164 = F_73 ( V_9 -> V_166 . V_168 ) ;
V_162 = F_74 ( V_9 -> V_166 . V_169 ) ;
F_75 ( & V_9 -> V_80 , V_163 ) ;
return V_162 ;
}
void F_76 ( struct V_7 * V_9 ,
T_7 V_170 ,
T_7 V_58 )
{
T_2 V_164 ;
unsigned long V_163 ;
F_71 ( & V_9 -> V_80 , V_163 ) ;
F_77 ( V_58 , V_9 -> V_166 . V_171 ) ;
F_72 ( V_170 >> 32 , V_9 -> V_166 . V_172 ) ;
V_164 = F_73 ( V_9 -> V_166 . V_172 ) ;
F_72 ( V_170 & 0xffffffff , V_9 -> V_166 . V_173 ) ;
F_75 ( & V_9 -> V_80 , V_163 ) ;
}
int F_78 ( struct V_7 * V_9 )
{
T_7 V_174 = 0 ;
T_7 V_175 ;
V_175 = F_70 ( V_9 , V_176 ) ;
V_174 = ( V_175 & V_177 ) ;
return V_174 ? 0 : 1 ;
}
int F_79 ( struct V_7 * V_9 , T_2 * V_178 )
{
int V_12 = 1 ;
T_2 V_179 ;
if ( ! V_178 )
return V_12 ;
for ( V_179 = 0 ; ( V_12 != 0 ) && ( ( * V_178 == 0 ) || ( V_179 <= * V_178 ) ) ;
V_179 += V_180 / 10 ) {
V_12 = F_78 ( V_9 ) ;
if ( V_12 )
F_80 ( V_180 / 10 ) ;
}
return V_12 ;
}
int F_81 ( void * V_23 )
{
struct V_7 * V_115 = (struct V_7 * ) V_23 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( V_7 [ V_6 ] == V_115 )
return V_115 -> V_11 ;
return - 1 ;
}
