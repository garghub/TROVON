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
F_13 ( V_17 ) ;
}
struct V_24 *
F_14 ( void )
{
struct V_24 * V_8 ;
V_8 = F_7 ( sizeof( struct V_24 ) , V_9 ) ;
if ( V_8 ) {
F_8 ( & V_25 ) ;
V_8 -> V_26 = V_12 ;
++ V_8 -> V_27 ;
F_9 ( & V_8 -> V_28 ) ;
F_9 ( & V_8 -> V_15 ) ;
#ifdef F_15
F_16 ( & V_8 -> V_29 ) ;
#endif
}
return V_8 ;
}
void
F_17 ( struct V_24 * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_3 ) ;
return;
}
F_12 ( & V_25 ) ;
F_13 ( V_17 -> V_30 ) ;
if ( V_17 -> V_21 ) {
memset ( V_17 -> V_21 , 0 , strlen ( V_17 -> V_21 ) ) ;
F_13 ( V_17 -> V_21 ) ;
}
F_13 ( V_17 ) ;
}
struct V_31 *
F_18 ( void )
{
struct V_31 * V_8 = NULL ;
T_1 V_32 = sizeof( struct V_31 ) ;
#ifdef F_19
V_32 = sizeof( struct V_33 ) ;
#endif
V_8 = F_20 ( V_34 , V_35 ) ;
if ( V_8 ) {
memset ( V_8 , 0 , V_32 + 3 ) ;
F_8 ( & V_36 ) ;
#ifdef F_21
F_8 ( & V_37 ) ;
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
F_23 ( V_17 , V_34 ) ;
F_12 ( & V_36 ) ;
return;
}
struct V_31 *
F_24 ( void )
{
struct V_31 * V_8 = NULL ;
V_8 = F_20 ( V_38 , V_35 ) ;
if ( V_8 ) {
F_8 ( & V_39 ) ;
#ifdef F_21
F_8 ( & V_40 ) ;
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
F_23 ( V_17 , V_38 ) ;
F_12 ( & V_39 ) ;
return;
}
void
F_26 ( struct V_31 * V_41 , char V_42 ,
const struct V_24 * V_43 , int V_44
)
{
char * V_45 = ( char * ) V_41 ;
memset ( V_45 , 0 , 256 ) ;
V_41 -> V_46 = F_27 (
( 2 * V_44 ) + sizeof( struct V_31 ) -
4 +
2 ) ;
V_41 -> V_47 [ 0 ] = 0xFF ;
V_41 -> V_47 [ 1 ] = 'S' ;
V_41 -> V_47 [ 2 ] = 'M' ;
V_41 -> V_47 [ 3 ] = 'B' ;
V_41 -> V_48 = V_42 ;
V_41 -> V_49 = 0x00 ;
V_41 -> V_50 = V_51 ;
V_41 -> V_52 = F_28 ( ( V_53 ) V_54 -> V_55 ) ;
V_41 -> V_56 = F_28 ( ( V_53 ) ( V_54 -> V_55 >> 16 ) ) ;
if ( V_43 ) {
V_41 -> V_57 = V_43 -> V_58 ;
if ( V_43 -> V_59 ) {
if ( V_43 -> V_59 -> V_60 & V_61 )
V_41 -> V_50 |= V_62 ;
if ( V_43 -> V_59 -> V_60 & V_63 )
V_41 -> V_50 |= V_64 ;
V_41 -> V_65 = V_43 -> V_59 -> V_66 ;
V_41 -> V_67 = F_29 ( V_43 -> V_59 -> V_68 ) ;
}
if ( V_43 -> V_49 & V_69 )
V_41 -> V_50 |= V_70 ;
if ( V_43 -> V_71 )
V_41 -> V_49 |= V_72 ;
if ( ( V_43 -> V_59 ) && ( V_43 -> V_59 -> V_68 ) )
if ( V_43 -> V_59 -> V_68 -> V_73 &
( V_74 | V_75 ) )
V_41 -> V_50 |= V_76 ;
}
V_41 -> V_77 = ( char ) V_44 ;
return;
}
static int
F_30 ( struct V_31 * V_78 , V_53 V_79 )
{
if ( * ( V_80 * ) V_78 -> V_47 != F_31 ( 0x424d53ff ) ) {
F_3 ( V_81 , L_5 ,
* ( unsigned int * ) V_78 -> V_47 ) ;
return 1 ;
}
if ( V_79 != V_78 -> V_67 ) {
F_3 ( V_81 , L_6 ,
V_78 -> V_67 , V_79 ) ;
return 1 ;
}
if ( V_78 -> V_49 & V_82 )
return 0 ;
if ( V_78 -> V_48 == V_83 )
return 0 ;
F_3 ( V_81 , L_7 , V_78 -> V_67 ) ;
return 1 ;
}
int
F_32 ( char * V_84 , unsigned int V_85 )
{
struct V_31 * V_78 = (struct V_31 * ) V_84 ;
V_53 V_79 = V_78 -> V_67 ;
T_2 V_86 = F_33 ( V_78 -> V_46 ) ;
T_2 V_87 ;
F_3 ( V_5 , L_8 ,
V_85 , V_86 ) ;
if ( V_85 < 2 + sizeof( struct V_31 ) ) {
if ( ( V_85 >= sizeof( struct V_31 ) - 1 )
&& ( V_78 -> V_88 . V_89 != 0 ) ) {
V_78 -> V_77 = 0 ;
return 0 ;
} else if ( ( V_85 == sizeof( struct V_31 ) + 1 ) &&
( V_78 -> V_77 == 0 ) ) {
char * V_90 = ( char * ) V_78 ;
if ( V_90 [ sizeof( struct V_31 ) ] == 0 ) {
V_90 [ sizeof( struct V_31 ) + 1 ] = 0 ;
return 0 ;
}
F_3 ( V_81 , L_9 ) ;
} else {
F_3 ( V_81 , L_10 ) ;
}
return - V_91 ;
}
if ( F_30 ( V_78 , V_79 ) )
return - V_91 ;
V_87 = F_34 ( V_78 ) ;
if ( 4 + V_86 != V_85 ) {
F_3 ( V_81 , L_11 ,
V_86 ) ;
return - V_91 ;
}
if ( 4 + V_86 != V_87 ) {
if ( ( V_86 > 64 * 1024 ) && ( V_86 > V_87 ) ) {
if ( ( ( 4 + V_86 ) & 0xFFFF ) == ( V_87 & 0xFFFF ) )
return 0 ;
}
F_3 ( V_5 , L_12 ,
V_87 , 4 + V_86 , V_78 -> V_67 ) ;
if ( 4 + V_86 < V_87 ) {
F_3 ( V_81 , L_13 ,
V_86 , V_78 -> V_67 ) ;
return - V_91 ;
} else if ( V_86 > V_87 + 512 ) {
F_3 ( V_81 , L_14 ,
V_86 , V_78 -> V_67 ) ;
return - V_91 ;
}
}
return 0 ;
}
bool
F_35 ( char * V_41 , struct V_92 * V_93 )
{
struct V_31 * V_84 = (struct V_31 * ) V_41 ;
struct V_94 * V_95 = (struct V_94 * ) V_84 ;
struct V_96 * V_90 , * V_97 , * V_98 ;
struct V_7 * V_59 ;
struct V_24 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
F_3 ( V_5 , L_15 ) ;
if ( ( V_95 -> V_104 . V_48 == V_105 ) &&
( V_95 -> V_104 . V_49 & V_82 ) ) {
struct V_106 * V_107 =
(struct V_106 * ) V_84 ;
struct V_108 * V_109 ;
T_2 V_110 = 0 ;
if ( F_36 ( V_84 ) > sizeof( struct V_108 ) ) {
V_110 = F_37 ( V_107 -> V_111 ) ;
V_109 = (struct V_108 * )
( ( char * ) & V_107 -> V_104 . V_47 + V_110 ) ;
F_3 ( V_5 , L_16 ,
V_109 -> V_112 , V_109 -> V_113 ) ;
return true ;
}
if ( V_107 -> V_104 . V_88 . V_89 ) {
F_3 ( V_5 , L_17 ,
V_107 -> V_104 . V_88 . V_89 ) ;
return true ;
}
return false ;
}
if ( V_95 -> V_104 . V_48 != V_83 )
return false ;
if ( V_95 -> V_104 . V_49 & V_82 ) {
if ( ( V_114 ) ==
F_37 ( V_95 -> V_104 . V_88 . V_89 ) ) {
F_3 ( V_5 , L_18 ) ;
return true ;
} else if ( V_115 ==
F_38 ( V_95 -> V_104 . V_88 . V_116 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_95 -> V_104 . V_77 != 8 )
return false ;
F_3 ( V_5 , L_19 ,
V_95 -> V_117 , V_95 -> V_118 ) ;
if ( ! ( V_95 -> V_117 & V_119 ) )
return false ;
F_2 ( & V_120 ) ;
F_39 (tmp, &srv->smb_ses_list) {
V_59 = F_40 ( V_90 , struct V_7 , V_14 ) ;
F_39 (tmp1, &ses->tcon_list) {
V_99 = F_40 ( V_97 , struct V_24 , V_15 ) ;
if ( V_99 -> V_58 != V_84 -> V_57 )
continue;
F_41 ( & V_99 -> V_121 . V_122 . V_123 ) ;
F_2 ( & V_124 ) ;
F_39 (tmp2, &tcon->openFileList) {
V_103 = F_40 ( V_98 , struct V_102 ,
V_125 ) ;
if ( V_95 -> V_126 != V_103 -> V_127 . V_128 )
continue;
F_3 ( V_5 , L_20 ) ;
V_101 = F_42 ( V_103 -> V_129 -> V_130 ) ;
F_43 ( V_101 ,
V_95 -> V_118 ? V_131 : 0 ) ;
F_44 ( V_132 ,
& V_103 -> V_133 ) ;
V_103 -> V_134 = false ;
F_4 ( & V_124 ) ;
F_4 ( & V_120 ) ;
return true ;
}
F_4 ( & V_124 ) ;
F_4 ( & V_120 ) ;
F_3 ( V_5 , L_21 ) ;
return true ;
}
}
F_4 ( & V_120 ) ;
F_3 ( V_5 , L_22 ) ;
return true ;
}
void
F_45 ( void * V_84 , int V_46 )
{
int V_135 , V_136 ;
char V_137 [ 17 ] ;
unsigned char * V_41 = V_84 ;
if ( V_138 == 0 )
return;
for ( V_135 = 0 , V_136 = 0 ; V_135 < V_46 ; V_135 ++ , V_136 ++ ) {
if ( V_135 % 8 == 0 ) {
F_46 ( V_139 L_23 ) ;
V_136 = 0 ;
}
F_46 ( L_24 , V_41 [ V_135 ] ) ;
V_137 [ 2 * V_136 ] = ' ' ;
if ( isprint ( V_41 [ V_135 ] ) )
V_137 [ 1 + ( 2 * V_136 ) ] = V_41 [ V_135 ] ;
else
V_137 [ 1 + ( 2 * V_136 ) ] = '_' ;
if ( V_135 % 8 == 7 ) {
V_137 [ 16 ] = 0 ;
F_46 ( L_25 , V_137 ) ;
}
}
for (; V_136 < 8 ; V_136 ++ ) {
F_46 ( L_26 ) ;
V_137 [ 2 * V_136 ] = ' ' ;
V_137 [ 1 + ( 2 * V_136 ) ] = ' ' ;
}
F_46 ( L_25 , V_137 ) ;
return;
}
void
F_47 ( struct V_140 * V_141 )
{
if ( V_141 -> V_142 & V_143 ) {
V_141 -> V_142 &= ~ V_143 ;
F_3 ( V_81 , L_27 ,
F_48 ( V_141 ) -> V_144 ) ;
}
}
void F_43 ( struct V_100 * V_145 , T_2 V_146 )
{
V_146 &= 0xF ;
if ( V_146 == V_147 ) {
V_145 -> V_148 = true ;
V_145 -> V_149 = true ;
F_3 ( V_5 , L_28 ,
& V_145 -> V_150 ) ;
} else if ( V_146 == V_131 ) {
V_145 -> V_148 = false ;
V_145 -> V_149 = true ;
F_3 ( V_5 , L_29 ,
& V_145 -> V_150 ) ;
} else {
V_145 -> V_148 = false ;
V_145 -> V_149 = false ;
}
}
bool
F_49 ( struct V_140 * V_141 )
{
if ( V_141 -> V_142 & V_151 ) {
if ( F_50 ( V_141 -> V_152 , F_51 () ) )
return true ;
}
if ( V_141 -> V_142 & V_153 ) {
if ( F_52 ( V_141 -> V_154 ) )
return true ;
}
return false ;
}
void
F_53 ( struct V_155 * V_156 )
{
F_2 ( & V_124 ) ;
F_54 ( & V_156 -> V_157 ) ;
F_4 ( & V_124 ) ;
}
void
F_55 ( struct V_158 * V_127 , struct V_159 * V_160 ,
struct V_155 * V_156 )
{
#ifdef F_19
memcpy ( V_156 -> V_161 , V_127 -> V_161 , V_162 ) ;
#endif
V_156 -> V_146 = V_163 ;
V_156 -> V_160 = V_160 ;
V_127 -> V_164 = V_156 ;
F_56 ( & V_156 -> V_157 , & F_57 ( V_160 ) -> V_165 ) ;
}
void
F_58 ( struct V_158 * V_127 , struct V_159 * V_160 ,
struct V_155 * V_156 )
{
F_2 ( & V_124 ) ;
F_55 ( V_127 , V_160 , V_156 ) ;
F_4 ( & V_124 ) ;
}
