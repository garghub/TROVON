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
} else if ( V_9 -> V_13 == V_21 ) {
V_12 = ( void * ) & V_22 ;
}
break;
default:
break;
}
return V_12 ;
}
static int F_4 ( struct V_7 * V_9 , void * V_23 )
{
switch ( V_9 -> V_13 ) {
case V_14 :
case V_16 :
return F_5 ( V_9 , V_23 ) ;
case V_21 :
return 0 ;
default:
break;
}
return 1 ;
}
void * F_6 ( struct V_7 * V_9 , T_1 V_10 )
{
void * V_23 = NULL ;
V_23 = F_3 ( V_9 , V_10 ) ;
if ( ! V_23 )
return NULL ;
if ( F_4 ( V_9 , V_23 ) ) {
F_7 ( & V_9 -> V_24 -> V_25 , L_1 ) ;
return NULL ;
}
return V_23 ;
}
char * F_8 ( T_3 * V_26 )
{
T_4 V_27 = ( T_4 ) F_9 ( V_26 ) ;
if ( V_27 > V_28 || V_27 < 0 )
return V_29 [ V_30 ] ;
return V_29 [ V_27 ] ;
}
static char * F_10 ( T_2 V_31 )
{
if ( V_31 <= V_32 )
return V_33 [ V_31 - V_34 ] ;
return V_33 [ V_35 - V_34 ] ;
}
void F_11 ( struct V_7 * V_9 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_12 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_36 . V_37 & ( 1ULL << V_6 ) )
F_13 ( V_9 -> V_38 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < F_14 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_36 . V_39 & ( 1ULL << V_6 ) )
F_13 ( V_9 -> V_40 [ V_6 ] ) ;
}
V_6 = V_9 -> V_11 ;
F_13 ( V_9 ) ;
V_7 [ V_6 ] = NULL ;
V_41 -- ;
}
static struct V_7 * F_15 ( T_2 V_42 ,
T_2 V_43 )
{
struct V_7 * V_9 ;
T_5 * V_44 = NULL ;
T_2 V_45 = 0 , V_46 = 0 , V_47 ;
switch ( V_42 ) {
case V_16 :
case V_14 :
V_46 = sizeof( struct V_48 ) ;
break;
case V_21 :
V_46 = sizeof( struct V_49 ) ;
break;
default:
F_16 ( L_2 ,
V_50 ,
V_42 ) ;
return NULL ;
}
if ( V_46 & 0x7 )
V_46 += ( 8 - ( V_46 & 0x7 ) ) ;
V_45 = sizeof( struct V_7 ) ;
if ( V_45 & 0x7 )
V_45 += ( 8 - ( V_45 & 0x7 ) ) ;
if ( V_43 & 0x7 )
V_43 += ( 8 - ( V_43 & 0x7 ) ) ;
V_47 = V_45 + V_43 + V_46 +
( sizeof( struct V_51 ) * V_52 ) ;
V_44 = F_17 ( V_47 ) ;
if ( ! V_44 )
return NULL ;
memset ( V_44 , 0 , V_47 ) ;
V_9 = (struct V_7 * ) V_44 ;
V_9 -> V_53 = ( void * ) ( V_44 + V_45 ) ;
V_9 -> V_54 = ( void * ) ( V_44 + V_45 + V_43 ) ;
V_9 -> V_55 . V_56 = (struct V_51 * )
( V_44 + V_45 + V_43 + V_46 ) ;
return V_9 ;
}
struct V_7 * F_18 ( T_2 V_42 ,
T_2 V_43 )
{
T_2 V_57 = 0 ;
struct V_7 * V_9 = NULL ;
for ( V_57 = 0 ; V_57 < V_8 ; V_57 ++ )
if ( ! V_7 [ V_57 ] )
break;
if ( V_57 == V_8 )
return NULL ;
V_9 = F_15 ( V_42 , V_43 ) ;
if ( ! V_9 )
return NULL ;
F_19 ( & V_9 -> V_58 ) ;
F_19 ( & V_9 -> V_59 ) ;
V_41 ++ ;
V_7 [ V_57 ] = V_9 ;
V_9 -> V_11 = V_57 ;
snprintf ( V_9 -> V_60 , sizeof( V_9 -> V_60 ) ,
L_3 , ( V_9 -> V_11 ) ) ;
return V_9 ;
}
int
F_20 ( struct V_7 * V_9 )
{
int V_6 , V_61 = 0 ;
struct V_62 * V_63 ;
int V_64 ;
int V_47 ;
if ( F_21 ( V_9 ) )
V_61 = V_9 -> V_65 . V_66 ;
V_47 = sizeof( struct V_62 ) * V_61 ;
V_9 -> V_63 = F_17 ( V_47 ) ;
if ( ! V_9 -> V_63 )
return 1 ;
memset ( V_9 -> V_63 , 0 , V_47 ) ;
for ( V_6 = 0 ; V_6 < V_61 ; V_6 ++ ) {
V_63 = & V_9 -> V_63 [ V_6 ] ;
V_63 -> V_67 = V_9 ;
V_63 -> V_68 = V_6 ;
V_63 -> V_69 = V_6 ;
V_64 = V_6 % F_22 () ;
F_23 ( V_64 , & V_63 -> V_70 ) ;
if ( V_9 -> V_13 == V_21 )
V_63 -> V_71 = V_6 + V_9 -> V_65 . V_72 ;
else
V_63 -> V_71 = V_6 ;
}
return 0 ;
}
void
F_24 ( struct V_7 * V_9 )
{
F_13 ( V_9 -> V_63 ) ;
}
int F_25 ( struct V_7 * V_9 )
{
T_2 V_73 = 0 ;
T_2 V_74 = 0 ;
union V_75 V_76 ;
int V_77 = F_26 ( V_74 % F_22 () ) ;
if ( F_27 ( V_9 ) )
V_73 =
F_28 ( F_29 ( V_9 , V_78 , V_23 ) ) ;
else if ( F_21 ( V_9 ) )
V_73 = F_28 ( F_29 ( V_9 , V_79 ,
V_23 ) ) ;
V_9 -> V_80 = 0 ;
V_9 -> V_40 [ 0 ] = F_30 ( sizeof( * V_9 -> V_40 [ 0 ] ) ,
V_77 ) ;
if ( ! V_9 -> V_40 [ 0 ] )
V_9 -> V_40 [ 0 ] =
F_17 ( sizeof( struct V_81 ) ) ;
if ( ! V_9 -> V_40 [ 0 ] )
return 1 ;
memset ( V_9 -> V_40 [ 0 ] , 0 , sizeof( struct V_81 ) ) ;
V_9 -> V_40 [ 0 ] -> V_82 = 0 ;
V_9 -> V_40 [ 0 ] -> V_83 = ( void * ) ( V_84 ) 0 ;
V_9 -> V_40 [ 0 ] -> V_85 = 0 ;
V_76 . V_86 = 0 ;
V_76 . V_87 . V_88 = V_74 ;
V_76 . V_87 . V_89 = V_9 -> V_90 . V_89 ;
V_76 . V_87 . V_91 = 0 ;
V_76 . V_87 . V_92 = 0 ;
if ( F_31 ( V_9 , V_76 , V_73 ) ) {
F_13 ( V_9 -> V_40 [ 0 ] ) ;
return 1 ;
}
V_9 -> V_80 ++ ;
return 0 ;
}
int F_32 ( struct V_7 * V_9 )
{
T_2 V_73 = 0 ;
T_2 V_93 = 0 ;
T_2 V_94 = 0 ;
int V_77 = F_26 ( V_94 % F_22 () ) ;
if ( F_27 ( V_9 ) ) {
V_73 =
F_33 ( F_29 ( V_9 , V_78 , V_23 ) ) ;
V_93 =
F_34 ( F_29 ( V_9 , V_78 , V_23 ) ) ;
} else if ( F_21 ( V_9 ) ) {
V_73 = F_33 ( F_29 ( V_9 , V_79 ,
V_23 ) ) ;
V_93 = F_34 ( F_29 ( V_9 , V_79 ,
V_23 ) ) ;
}
V_9 -> V_95 = 0 ;
V_9 -> V_38 [ 0 ] = F_30 ( sizeof( * V_9 -> V_38 [ 0 ] ) , V_77 ) ;
if ( ! V_9 -> V_38 [ 0 ] )
V_9 -> V_38 [ 0 ] = F_17 ( sizeof( * V_9 -> V_38 [ 0 ] ) ) ;
if ( ! V_9 -> V_38 [ 0 ] )
return 1 ;
if ( F_35 ( V_9 , V_94 , V_73 , V_93 , NULL ) )
return 1 ;
V_9 -> V_95 ++ ;
return 0 ;
}
void F_36 ( struct V_7 * V_9 )
{
if ( F_27 ( V_9 ) ) {
F_37 ( V_9 , V_96 , 0 ) ;
F_37 ( V_9 , V_97 , 0 ) ;
}
}
void F_38 ( struct V_7 * V_9 ,
T_2 V_88 ,
T_2 V_98 )
{
T_2 V_99 = 0 ;
if ( F_27 ( V_9 ) ) {
V_99 = F_39 ( V_9 , V_97 ) ;
if ( V_98 )
V_99 = V_99 | ( 1 << V_88 ) ;
else
V_99 = V_99 & ( ~ ( 1 << V_88 ) ) ;
F_37 ( V_9 , V_97 , V_99 ) ;
}
}
int F_40 ( struct V_7 * V_9 )
{
T_2 V_6 ;
V_9 -> V_55 . V_100 = 0 ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ ) {
V_9 -> V_55 . V_56 [ V_6 ] . V_101 = 0 ;
F_41 ( & V_9 -> V_55 . V_56 [ V_6 ] . V_102 ) ;
}
for ( V_6 = 0 ; V_6 <= V_103 ; V_6 ++ )
F_42 ( V_9 , V_6 , NULL ) ;
F_19 ( & V_9 -> V_55 . V_104 ) ;
return 0 ;
}
void F_43 ( struct V_7 * V_9 )
{
T_2 V_6 ;
struct V_105 V_106 , * V_107 , * V_108 ;
F_41 ( & V_106 ) ;
F_44 ( & V_9 -> V_55 . V_104 ) ;
for ( V_6 = 0 ; V_6 < V_52 ; V_6 ++ ) {
struct V_105 * V_55 ;
V_55 = & V_9 -> V_55 . V_56 [ V_6 ] . V_102 ;
while ( V_55 -> V_109 != V_55 ) {
V_107 = V_55 -> V_109 ;
F_45 ( V_107 ) ;
F_46 ( V_107 , & V_106 ) ;
}
V_9 -> V_55 . V_56 [ V_6 ] . V_101 = 0 ;
}
V_9 -> V_55 . V_100 = 0 ;
F_47 ( & V_9 -> V_55 . V_104 ) ;
F_48 (temp, tmp2, &freelist) {
F_45 ( V_107 ) ;
F_13 ( V_107 ) ;
}
}
T_6
F_49 ( struct V_7 * V_110 , T_1 V_101 ,
T_1 V_111 )
{
T_2 V_112 ;
struct V_105 * V_55 ;
T_6 V_113 = NULL ;
T_1 V_114 = F_50 ( V_101 , V_111 ) ;
V_112 = V_114 & V_115 ;
F_44 ( & V_110 -> V_55 . V_104 ) ;
if ( V_110 -> V_55 . V_100 == 0 ) {
F_47 ( & V_110 -> V_55 . V_104 ) ;
return NULL ;
}
if ( ! ( V_110 -> V_55 . V_56 [ V_112 ] . V_101 ) ) {
F_47 ( & V_110 -> V_55 . V_104 ) ;
return NULL ;
}
if ( V_110 -> V_55 . V_56 [ V_112 ] . V_101 == V_114 ) {
V_113 = V_110 -> V_55 . V_56 [ V_112 ] . V_116 ;
} else {
F_51 (dispatch,
&octeon_dev->dispatch.dlist[idx].list) {
if ( ( (struct V_51 * ) V_55 ) -> V_101 ==
V_114 ) {
V_113 = ( (struct V_51 * )
V_55 ) -> V_116 ;
break;
}
}
}
F_47 ( & V_110 -> V_55 . V_104 ) ;
return V_113 ;
}
int
F_52 ( struct V_7 * V_9 ,
T_1 V_101 ,
T_1 V_111 ,
T_6 V_113 , void * V_117 )
{
T_2 V_112 ;
T_6 V_118 ;
T_1 V_114 = F_50 ( V_101 , V_111 ) ;
V_112 = V_114 & V_115 ;
F_44 ( & V_9 -> V_55 . V_104 ) ;
if ( V_9 -> V_55 . V_56 [ V_112 ] . V_101 == 0 ) {
V_9 -> V_55 . V_56 [ V_112 ] . V_101 = V_114 ;
V_9 -> V_55 . V_56 [ V_112 ] . V_116 = V_113 ;
V_9 -> V_55 . V_56 [ V_112 ] . V_119 = V_117 ;
V_9 -> V_55 . V_100 ++ ;
F_47 ( & V_9 -> V_55 . V_104 ) ;
return 0 ;
}
F_47 ( & V_9 -> V_55 . V_104 ) ;
V_118 = F_49 ( V_9 , V_101 , V_111 ) ;
if ( ! V_118 ) {
struct V_51 * V_55 ;
F_53 ( & V_9 -> V_24 -> V_25 ,
L_4 ) ;
V_55 = (struct V_51 * )
F_17 ( sizeof( struct V_51 ) ) ;
if ( ! V_55 ) {
F_7 ( & V_9 -> V_24 -> V_25 ,
L_5 ) ;
return 1 ;
}
V_55 -> V_101 = V_114 ;
V_55 -> V_116 = V_113 ;
V_55 -> V_119 = V_117 ;
F_44 ( & V_9 -> V_55 . V_104 ) ;
F_54 ( & V_55 -> V_102 , & V_9 -> V_55 . V_56 [ V_112 ] . V_102 ) ;
V_9 -> V_55 . V_100 ++ ;
F_47 ( & V_9 -> V_55 . V_104 ) ;
} else {
F_7 ( & V_9 -> V_24 -> V_25 ,
L_6 ,
V_101 , V_111 ) ;
return 1 ;
}
return 0 ;
}
int F_55 ( struct V_120 * V_121 , void * V_44 )
{
T_2 V_6 ;
char V_122 [ 16 ] ;
struct V_7 * V_9 = (struct V_7 * ) V_44 ;
struct V_123 * V_124 = V_121 -> V_124 ;
struct V_125 * V_126 = NULL ;
T_2 V_127 = 0 ;
if ( F_27 ( V_9 ) )
V_127 =
F_56 ( F_29 ( V_9 , V_78 , V_23 ) ) ;
else if ( F_21 ( V_9 ) )
V_127 =
F_56 ( F_29 ( V_9 , V_79 , V_23 ) ) ;
if ( F_9 ( & V_9 -> V_128 ) >= V_129 ) {
F_7 ( & V_9 -> V_24 -> V_25 , L_7 ,
F_9 ( & V_9 -> V_128 ) ) ;
goto V_130;
}
strncpy ( V_122 ,
F_10 (
( T_2 ) V_124 -> V_131 . V_132 . V_31 ) ,
sizeof( V_122 ) - 1 ) ;
V_9 -> V_31 = ( T_2 ) V_124 -> V_131 . V_132 . V_31 ;
if ( V_124 -> V_131 . V_132 . V_31 == V_133 ) {
V_9 -> V_134 . V_135 =
( T_2 ) V_124 -> V_131 . V_132 . V_135 ;
V_9 -> V_134 . V_136 =
( T_2 ) V_124 -> V_131 . V_132 . V_136 ;
}
if ( V_9 -> V_134 . V_135 < V_127 ) {
F_7 ( & V_9 -> V_24 -> V_25 ,
L_8 ,
V_127 , V_9 -> V_134 . V_135 ) ;
goto V_130;
}
V_9 -> V_134 . V_137 = V_124 -> V_131 . V_132 . V_137 ;
V_9 -> V_134 . V_31 = ( T_2 ) V_124 -> V_131 . V_132 . V_31 ;
V_9 -> V_90 . V_31 = ( T_2 ) V_124 -> V_131 . V_132 . V_31 ;
V_9 -> V_90 . V_89 = V_124 -> V_131 . V_132 . V_89 ;
for ( V_6 = 0 ; V_6 < V_9 -> V_80 ; V_6 ++ )
V_9 -> V_40 [ V_6 ] -> V_76 . V_87 . V_89 = V_9 -> V_90 . V_89 ;
F_57 ( & V_9 -> V_128 , V_138 ) ;
V_126 = & V_139 [ V_9 -> V_11 ] ;
if ( V_124 -> V_140 [ 0 ] != sizeof( * V_126 ) ) {
F_53 ( & V_9 -> V_24 -> V_25 , L_9 ,
( T_2 ) sizeof( * V_126 ) ,
V_124 -> V_140 [ 0 ] ) ;
}
memcpy ( V_126 , F_58 ( V_124 -> V_141 [ 0 ] ) , sizeof( * V_126 ) ) ;
strncpy ( V_9 -> V_142 . V_143 , V_126 -> V_144 , V_145 ) ;
strncpy ( V_9 -> V_142 . V_146 , V_126 -> V_147 ,
V_148 ) ;
F_59 ( ( V_86 * ) V_126 , ( sizeof( * V_126 ) >> 3 ) ) ;
V_9 -> V_142 . V_149 = V_126 -> V_150 ;
V_9 -> V_142 . V_151 = V_126 -> V_152 ;
F_60 ( & V_9 -> V_24 -> V_25 ,
L_10 ,
V_122 , F_61 ( V_126 -> V_153 ) ) ;
V_130:
for ( V_6 = 0 ; V_6 < V_124 -> V_154 ; V_6 ++ )
F_62 ( V_124 -> V_141 [ V_6 ] ) ;
F_63 ( V_121 ) ;
return 0 ;
}
int F_64 ( struct V_7 * V_9 , T_2 V_88 )
{
if ( V_9 && ( V_88 < F_14 ( V_9 ) ) &&
( V_9 -> V_36 . V_39 & ( 1ULL << V_88 ) ) )
return V_9 -> V_40 [ V_88 ] -> V_155 ;
return - 1 ;
}
int F_65 ( struct V_7 * V_9 , T_2 V_88 )
{
if ( V_9 && ( V_88 < F_12 ( V_9 ) ) &&
( V_9 -> V_36 . V_37 & ( 1ULL << V_88 ) ) )
return V_9 -> V_38 [ V_88 ] -> V_155 ;
return - 1 ;
}
struct V_156 * F_66 ( struct V_7 * V_9 )
{
struct V_156 * V_157 = NULL ;
if ( F_27 ( V_9 ) ) {
V_157 =
(struct V_156 * ) ( F_29 ( V_9 , V_78 , V_23 ) ) ;
} else if ( F_21 ( V_9 ) ) {
V_157 = (struct V_156 * )
( F_29 ( V_9 , V_79 , V_23 ) ) ;
}
return V_157 ;
}
struct V_7 * F_67 ( T_2 V_11 )
{
if ( V_11 >= V_8 )
return NULL ;
else
return V_7 [ V_11 ] ;
}
V_86 F_68 ( struct V_7 * V_9 , V_86 V_158 )
{
V_86 V_159 ;
unsigned long V_160 ;
T_2 V_161 , V_162 ;
F_69 ( & V_9 -> V_58 , V_160 ) ;
V_162 = ( V_158 >> 32 ) ;
if ( ( V_9 -> V_13 == V_14 ) ||
( V_9 -> V_13 == V_16 ) ||
( V_9 -> V_13 == V_21 ) )
V_162 |= 0x00060000 ;
F_70 ( V_162 , V_9 -> V_163 . V_164 ) ;
V_161 = F_71 ( V_9 -> V_163 . V_164 ) ;
F_70 ( V_158 & 0xffffffff , V_9 -> V_163 . V_165 ) ;
V_161 = F_71 ( V_9 -> V_163 . V_165 ) ;
V_159 = F_72 ( V_9 -> V_163 . V_166 ) ;
F_73 ( & V_9 -> V_58 , V_160 ) ;
return V_159 ;
}
void F_74 ( struct V_7 * V_9 ,
V_86 V_167 ,
V_86 V_158 )
{
T_2 V_161 ;
unsigned long V_160 ;
F_69 ( & V_9 -> V_58 , V_160 ) ;
F_75 ( V_158 , V_9 -> V_163 . V_168 ) ;
F_70 ( V_167 >> 32 , V_9 -> V_163 . V_169 ) ;
V_161 = F_71 ( V_9 -> V_163 . V_169 ) ;
F_70 ( V_167 & 0xffffffff , V_9 -> V_163 . V_170 ) ;
F_73 ( & V_9 -> V_58 , V_160 ) ;
}
int F_76 ( struct V_7 * V_9 )
{
V_86 V_171 = 0 ;
V_86 V_172 ;
if ( F_21 ( V_9 ) ) {
V_172 = F_68 ( V_9 , V_173 ) ;
V_171 =
( V_172 & V_174 ) ;
} else {
V_172 = F_68 ( V_9 , V_175 ) ;
V_171 =
( V_172 & V_176 ) ;
}
return V_171 ? 0 : 1 ;
}
int F_77 ( struct V_7 * V_9 , T_2 * V_177 )
{
int V_12 = 1 ;
T_2 V_178 ;
if ( ! V_177 )
return V_12 ;
for ( V_178 = 0 ; ( V_12 != 0 ) && ( ( * V_177 == 0 ) || ( V_178 <= * V_177 ) ) ;
V_178 += V_179 / 10 ) {
V_12 = F_76 ( V_9 ) ;
if ( V_12 )
F_78 ( V_179 / 10 ) ;
}
return V_12 ;
}
int F_79 ( void * V_25 )
{
struct V_7 * V_110 = (struct V_7 * ) V_25 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( V_7 [ V_6 ] == V_110 )
return V_110 -> V_11 ;
return - 1 ;
}
void F_80 ( struct V_180 * V_38 , struct V_81 * V_39 )
{
V_86 V_181 ;
struct V_7 * V_9 = NULL ;
if ( V_38 ) {
F_44 ( & V_38 -> V_104 ) ;
F_70 ( V_38 -> V_182 , V_38 -> V_183 ) ;
V_38 -> V_182 = 0 ;
F_47 ( & V_38 -> V_104 ) ;
V_9 = V_38 -> V_67 ;
}
if ( V_39 ) {
F_44 ( & V_39 -> V_104 ) ;
F_70 ( V_39 -> V_184 , V_39 -> V_185 ) ;
V_39 -> V_184 = 0 ;
F_47 ( & V_39 -> V_104 ) ;
V_9 = V_39 -> V_67 ;
}
if ( V_9 && F_21 ( V_9 ) ) {
if ( V_38 )
F_75 ( V_186 , V_38 -> V_183 ) ;
else if ( V_39 ) {
V_181 = F_72 ( V_39 -> V_185 ) ;
F_75 ( ( ( V_181 & 0xFFFFFFFF00000000ULL ) |
V_186 ) ,
V_39 -> V_185 ) ;
}
}
}
