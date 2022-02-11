unsigned int
F_1 ( void )
{
unsigned int V_1 ;
F_2 ( & V_2 ) ;
V_3 ++ ;
if ( V_3 > V_4 )
V_4 = V_3 ;
if ( V_3 > 65000 )
F_3 ( V_5 , L_1 ) ;
V_1 = V_6 ++ ;
F_4 ( & V_2 ) ;
return V_1 ;
}
void
F_5 ( unsigned int V_1 )
{
F_2 ( & V_2 ) ;
V_3 -- ;
F_4 ( & V_2 ) ;
}
struct V_7 *
F_6 ( void )
{
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( struct V_7 ) , V_9 ) ;
if ( V_8 ) {
F_8 ( & V_10 ) ;
V_8 -> V_11 = V_12 ;
++ V_8 -> V_13 ;
F_9 ( & V_8 -> V_14 ) ;
F_9 ( & V_8 -> V_15 ) ;
F_10 ( & V_8 -> V_16 ) ;
}
return V_8 ;
}
void
F_11 ( struct V_7 * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_2 ) ;
return;
}
F_12 ( & V_10 ) ;
F_13 ( V_17 -> V_18 ) ;
F_13 ( V_17 -> V_19 ) ;
F_13 ( V_17 -> V_20 ) ;
if ( V_17 -> V_21 ) {
memset ( V_17 -> V_21 , 0 , strlen ( V_17 -> V_21 ) ) ;
F_13 ( V_17 -> V_21 ) ;
}
F_13 ( V_17 -> V_22 ) ;
F_13 ( V_17 -> V_23 ) ;
F_13 ( V_17 -> V_24 . V_25 ) ;
F_13 ( V_17 ) ;
}
struct V_26 *
F_14 ( void )
{
struct V_26 * V_8 ;
V_8 = F_7 ( sizeof( struct V_26 ) , V_9 ) ;
if ( V_8 ) {
F_8 ( & V_27 ) ;
V_8 -> V_28 = V_12 ;
++ V_8 -> V_29 ;
F_9 ( & V_8 -> V_30 ) ;
F_9 ( & V_8 -> V_15 ) ;
#ifdef F_15
F_16 ( & V_8 -> V_31 ) ;
#endif
}
return V_8 ;
}
void
F_17 ( struct V_26 * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_3 ) ;
return;
}
F_12 ( & V_27 ) ;
F_13 ( V_17 -> V_32 ) ;
if ( V_17 -> V_21 ) {
memset ( V_17 -> V_21 , 0 , strlen ( V_17 -> V_21 ) ) ;
F_13 ( V_17 -> V_21 ) ;
}
F_13 ( V_17 ) ;
}
struct V_33 *
F_18 ( void )
{
struct V_33 * V_8 = NULL ;
T_1 V_34 = sizeof( struct V_33 ) ;
#ifdef F_19
V_34 = sizeof( struct V_35 ) ;
#endif
V_8 = F_20 ( V_36 , V_37 ) ;
if ( V_8 ) {
memset ( V_8 , 0 , V_34 + 3 ) ;
F_8 ( & V_38 ) ;
#ifdef F_21
F_8 ( & V_39 ) ;
#endif
}
return V_8 ;
}
void
F_22 ( void * V_17 )
{
if ( V_17 == NULL ) {
return;
}
F_23 ( V_17 , V_36 ) ;
F_12 ( & V_38 ) ;
return;
}
struct V_33 *
F_24 ( void )
{
struct V_33 * V_8 = NULL ;
V_8 = F_20 ( V_40 , V_37 ) ;
if ( V_8 ) {
F_8 ( & V_41 ) ;
#ifdef F_21
F_8 ( & V_42 ) ;
#endif
}
return V_8 ;
}
void
F_25 ( void * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_4 ) ;
return;
}
F_23 ( V_17 , V_40 ) ;
F_12 ( & V_41 ) ;
return;
}
void
F_26 ( struct V_33 * V_43 , char V_44 ,
const struct V_26 * V_45 , int V_46
)
{
char * V_47 = ( char * ) V_43 ;
memset ( V_47 , 0 , 256 ) ;
V_43 -> V_48 = F_27 (
( 2 * V_46 ) + sizeof( struct V_33 ) -
4 +
2 ) ;
V_43 -> V_49 [ 0 ] = 0xFF ;
V_43 -> V_49 [ 1 ] = 'S' ;
V_43 -> V_49 [ 2 ] = 'M' ;
V_43 -> V_49 [ 3 ] = 'B' ;
V_43 -> V_50 = V_44 ;
V_43 -> V_51 = 0x00 ;
V_43 -> V_52 = V_53 ;
V_43 -> V_54 = F_28 ( ( V_55 ) V_56 -> V_57 ) ;
V_43 -> V_58 = F_28 ( ( V_55 ) ( V_56 -> V_57 >> 16 ) ) ;
if ( V_45 ) {
V_43 -> V_59 = V_45 -> V_60 ;
if ( V_45 -> V_61 ) {
if ( V_45 -> V_61 -> V_62 & V_63 )
V_43 -> V_52 |= V_64 ;
if ( V_45 -> V_61 -> V_62 & V_65 )
V_43 -> V_52 |= V_66 ;
V_43 -> V_67 = V_45 -> V_61 -> V_68 ;
V_43 -> V_69 = F_29 ( V_45 -> V_61 -> V_70 ) ;
}
if ( V_45 -> V_51 & V_71 )
V_43 -> V_52 |= V_72 ;
if ( V_45 -> V_73 )
V_43 -> V_51 |= V_74 ;
if ( ( V_45 -> V_61 ) && ( V_45 -> V_61 -> V_70 ) )
if ( V_45 -> V_61 -> V_70 -> V_75 )
V_43 -> V_52 |= V_76 ;
}
V_43 -> V_77 = ( char ) V_46 ;
return;
}
static int
F_30 ( struct V_33 * V_78 )
{
if ( * ( V_79 * ) V_78 -> V_49 != F_31 ( 0x424d53ff ) ) {
F_3 ( V_80 , L_5 ,
* ( unsigned int * ) V_78 -> V_49 ) ;
return 1 ;
}
if ( V_78 -> V_51 & V_81 )
return 0 ;
if ( V_78 -> V_50 == V_82 )
return 0 ;
F_3 ( V_80 , L_6 ,
F_32 ( V_78 ) ) ;
return 1 ;
}
int
F_33 ( char * V_83 , unsigned int V_84 )
{
struct V_33 * V_78 = (struct V_33 * ) V_83 ;
T_2 V_85 = F_34 ( V_78 -> V_48 ) ;
T_2 V_86 ;
F_3 ( V_5 , L_7 ,
V_84 , V_85 ) ;
if ( V_84 < 2 + sizeof( struct V_33 ) ) {
if ( ( V_84 >= sizeof( struct V_33 ) - 1 )
&& ( V_78 -> V_87 . V_88 != 0 ) ) {
V_78 -> V_77 = 0 ;
return 0 ;
} else if ( ( V_84 == sizeof( struct V_33 ) + 1 ) &&
( V_78 -> V_77 == 0 ) ) {
char * V_89 = ( char * ) V_78 ;
if ( V_89 [ sizeof( struct V_33 ) ] == 0 ) {
V_89 [ sizeof( struct V_33 ) + 1 ] = 0 ;
return 0 ;
}
F_3 ( V_80 , L_8 ) ;
} else {
F_3 ( V_80 , L_9 ) ;
}
return - V_90 ;
}
if ( F_30 ( V_78 ) )
return - V_90 ;
V_86 = F_35 ( V_78 ) ;
if ( 4 + V_85 != V_84 ) {
F_3 ( V_80 , L_10 ,
V_85 ) ;
return - V_90 ;
}
if ( 4 + V_85 != V_86 ) {
V_55 V_91 = F_32 ( V_78 ) ;
if ( ( V_85 > 64 * 1024 ) && ( V_85 > V_86 ) ) {
if ( ( ( 4 + V_85 ) & 0xFFFF ) == ( V_86 & 0xFFFF ) )
return 0 ;
}
F_3 ( V_5 , L_11 ,
V_86 , 4 + V_85 , V_91 ) ;
if ( 4 + V_85 < V_86 ) {
F_3 ( V_80 , L_12 ,
V_85 , V_91 ) ;
return - V_90 ;
} else if ( V_85 > V_86 + 512 ) {
F_3 ( V_80 , L_13 ,
V_85 , V_91 ) ;
return - V_90 ;
}
}
return 0 ;
}
bool
F_36 ( char * V_43 , struct V_92 * V_93 )
{
struct V_33 * V_83 = (struct V_33 * ) V_43 ;
struct V_94 * V_95 = (struct V_94 * ) V_83 ;
struct V_96 * V_89 , * V_97 , * V_98 ;
struct V_7 * V_61 ;
struct V_26 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
F_3 ( V_5 , L_14 ) ;
if ( ( V_95 -> V_104 . V_50 == V_105 ) &&
( V_95 -> V_104 . V_51 & V_81 ) ) {
struct V_106 * V_107 =
(struct V_106 * ) V_83 ;
struct V_108 * V_109 ;
T_2 V_110 = 0 ;
if ( F_37 ( V_83 ) > sizeof( struct V_108 ) ) {
V_110 = F_38 ( V_107 -> V_111 ) ;
V_109 = (struct V_108 * )
( ( char * ) & V_107 -> V_104 . V_49 + V_110 ) ;
F_3 ( V_5 , L_15 ,
V_109 -> V_112 , V_109 -> V_113 ) ;
return true ;
}
if ( V_107 -> V_104 . V_87 . V_88 ) {
F_3 ( V_5 , L_16 ,
V_107 -> V_104 . V_87 . V_88 ) ;
return true ;
}
return false ;
}
if ( V_95 -> V_104 . V_50 != V_82 )
return false ;
if ( V_95 -> V_104 . V_51 & V_81 ) {
if ( ( V_114 ) ==
F_38 ( V_95 -> V_104 . V_87 . V_88 ) ) {
F_3 ( V_5 , L_17 ) ;
return true ;
} else if ( V_115 ==
F_39 ( V_95 -> V_104 . V_87 . V_116 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_95 -> V_104 . V_77 != 8 )
return false ;
F_3 ( V_5 , L_18 ,
V_95 -> V_117 , V_95 -> V_118 ) ;
if ( ! ( V_95 -> V_117 & V_119 ) )
return false ;
F_2 ( & V_120 ) ;
F_40 (tmp, &srv->smb_ses_list) {
V_61 = F_41 ( V_89 , struct V_7 , V_14 ) ;
F_40 (tmp1, &ses->tcon_list) {
V_99 = F_41 ( V_97 , struct V_26 , V_15 ) ;
if ( V_99 -> V_60 != V_83 -> V_59 )
continue;
F_42 ( & V_99 -> V_121 . V_122 . V_123 ) ;
F_2 ( & V_124 ) ;
F_40 (tmp2, &tcon->openFileList) {
V_103 = F_41 ( V_98 , struct V_102 ,
V_125 ) ;
if ( V_95 -> V_126 != V_103 -> V_127 . V_128 )
continue;
F_3 ( V_5 , L_19 ) ;
V_101 = F_43 ( V_103 -> V_129 -> V_130 ) ;
F_44 ( V_131 ,
& V_101 -> V_132 ) ;
if ( V_95 -> V_118 )
F_44 (
V_133 ,
& V_101 -> V_132 ) ;
else
F_45 (
V_133 ,
& V_101 -> V_132 ) ;
F_46 ( V_134 ,
& V_103 -> V_135 ) ;
V_103 -> V_136 = false ;
F_4 ( & V_124 ) ;
F_4 ( & V_120 ) ;
return true ;
}
F_4 ( & V_124 ) ;
F_4 ( & V_120 ) ;
F_3 ( V_5 , L_20 ) ;
return true ;
}
}
F_4 ( & V_120 ) ;
F_3 ( V_5 , L_21 ) ;
return true ;
}
void
F_47 ( void * V_83 , int V_48 )
{
int V_137 , V_138 ;
char V_139 [ 17 ] ;
unsigned char * V_43 = V_83 ;
if ( V_140 == 0 )
return;
for ( V_137 = 0 , V_138 = 0 ; V_137 < V_48 ; V_137 ++ , V_138 ++ ) {
if ( V_137 % 8 == 0 ) {
F_48 ( V_141 L_22 ) ;
V_138 = 0 ;
}
F_48 ( L_23 , V_43 [ V_137 ] ) ;
V_139 [ 2 * V_138 ] = ' ' ;
if ( isprint ( V_43 [ V_137 ] ) )
V_139 [ 1 + ( 2 * V_138 ) ] = V_43 [ V_137 ] ;
else
V_139 [ 1 + ( 2 * V_138 ) ] = '_' ;
if ( V_137 % 8 == 7 ) {
V_139 [ 16 ] = 0 ;
F_48 ( L_24 , V_139 ) ;
}
}
for (; V_138 < 8 ; V_138 ++ ) {
F_48 ( L_25 ) ;
V_139 [ 2 * V_138 ] = ' ' ;
V_139 [ 1 + ( 2 * V_138 ) ] = ' ' ;
}
F_48 ( L_24 , V_139 ) ;
return;
}
void
F_49 ( struct V_142 * V_143 )
{
if ( V_143 -> V_144 & V_145 ) {
V_143 -> V_144 &= ~ V_145 ;
F_3 ( V_80 , L_26 ,
F_50 ( V_143 ) -> V_146 ) ;
}
}
void F_51 ( struct V_100 * V_147 , T_2 V_148 )
{
V_148 &= 0xF ;
if ( V_148 == V_149 ) {
V_147 -> V_148 = V_150 | V_151 ;
F_3 ( V_5 , L_27 ,
& V_147 -> V_152 ) ;
} else if ( V_148 == V_153 ) {
V_147 -> V_148 = V_151 ;
F_3 ( V_5 , L_28 ,
& V_147 -> V_152 ) ;
} else
V_147 -> V_148 = 0 ;
}
static int
F_52 ( void * V_154 )
{
F_53 () ;
return F_54 ( V_56 ) ? - V_155 : 0 ;
}
int F_55 ( struct V_100 * V_147 )
{
int V_156 ;
V_157:
V_156 = F_56 ( & V_147 -> V_132 , V_131 ,
F_52 , V_158 ) ;
if ( V_156 )
return V_156 ;
F_2 ( & V_147 -> V_159 ) ;
if ( ! V_147 -> V_160 )
F_44 ( V_161 , & V_147 -> V_132 ) ;
V_147 -> V_160 ++ ;
if ( F_57 ( V_131 , & V_147 -> V_132 ) ) {
V_147 -> V_160 -- ;
if ( V_147 -> V_160 == 0 ) {
F_45 ( V_161 , & V_147 -> V_132 ) ;
F_58 ( & V_147 -> V_132 , V_161 ) ;
}
F_4 ( & V_147 -> V_159 ) ;
goto V_157;
}
F_4 ( & V_147 -> V_159 ) ;
return 0 ;
}
void F_59 ( struct V_100 * V_147 )
{
F_2 ( & V_147 -> V_159 ) ;
V_147 -> V_160 -- ;
if ( V_147 -> V_160 == 0 ) {
F_45 ( V_161 , & V_147 -> V_132 ) ;
F_58 ( & V_147 -> V_132 , V_161 ) ;
}
F_4 ( & V_147 -> V_159 ) ;
}
void F_60 ( struct V_100 * V_147 )
{
F_45 ( V_131 , & V_147 -> V_132 ) ;
F_58 ( & V_147 -> V_132 , V_131 ) ;
}
bool
F_61 ( struct V_142 * V_143 )
{
if ( V_143 -> V_144 & V_162 ) {
if ( F_62 ( V_143 -> V_163 , F_63 () ) )
return true ;
}
if ( V_143 -> V_144 & V_164 ) {
if ( F_64 ( V_143 -> V_165 ) )
return true ;
}
return false ;
}
void
F_65 ( struct V_166 * V_167 )
{
F_2 ( & V_124 ) ;
F_66 ( & V_167 -> V_168 ) ;
F_4 ( & V_124 ) ;
}
void
F_67 ( struct V_169 * V_127 , struct V_170 * V_171 ,
struct V_166 * V_167 )
{
#ifdef F_19
memcpy ( V_167 -> V_172 , V_127 -> V_172 , V_173 ) ;
#endif
V_167 -> V_148 = V_174 ;
V_167 -> V_171 = V_171 ;
V_127 -> V_175 = V_167 ;
F_68 ( & V_167 -> V_168 , & F_69 ( V_171 ) -> V_176 ) ;
}
void
F_70 ( struct V_169 * V_127 , struct V_170 * V_171 ,
struct V_166 * V_167 )
{
F_2 ( & V_124 ) ;
F_67 ( V_127 , V_171 , V_167 ) ;
F_4 ( & V_124 ) ;
}
