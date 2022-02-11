unsigned int
F_1 ( void )
{
unsigned int V_1 ;
F_2 ( & V_2 ) ;
V_3 ++ ;
if ( V_3 > V_4 )
V_4 = V_3 ;
if ( V_3 > 65000 )
F_3 ( 1 , L_1 ) ;
V_1 = V_5 ++ ;
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
struct V_6 *
F_6 ( void )
{
struct V_6 * V_7 ;
V_7 = F_7 ( sizeof( struct V_6 ) , V_8 ) ;
if ( V_7 ) {
F_8 ( & V_9 ) ;
V_7 -> V_10 = V_11 ;
++ V_7 -> V_12 ;
F_9 ( & V_7 -> V_13 ) ;
F_9 ( & V_7 -> V_14 ) ;
F_10 ( & V_7 -> V_15 ) ;
}
return V_7 ;
}
void
F_11 ( struct V_6 * V_16 )
{
if ( V_16 == NULL ) {
F_3 ( 1 , L_2 ) ;
return;
}
F_12 ( & V_9 ) ;
F_13 ( V_16 -> V_17 ) ;
F_13 ( V_16 -> V_18 ) ;
F_13 ( V_16 -> V_19 ) ;
if ( V_16 -> V_20 ) {
memset ( V_16 -> V_20 , 0 , strlen ( V_16 -> V_20 ) ) ;
F_13 ( V_16 -> V_20 ) ;
}
F_13 ( V_16 -> V_21 ) ;
F_13 ( V_16 -> V_22 ) ;
F_13 ( V_16 ) ;
}
struct V_23 *
F_14 ( void )
{
struct V_23 * V_7 ;
V_7 = F_7 ( sizeof( struct V_23 ) , V_8 ) ;
if ( V_7 ) {
F_8 ( & V_24 ) ;
V_7 -> V_25 = V_11 ;
++ V_7 -> V_26 ;
F_9 ( & V_7 -> V_27 ) ;
F_9 ( & V_7 -> V_14 ) ;
#ifdef F_15
F_16 ( & V_7 -> V_28 ) ;
#endif
}
return V_7 ;
}
void
F_17 ( struct V_23 * V_16 )
{
if ( V_16 == NULL ) {
F_3 ( 1 , L_3 ) ;
return;
}
F_12 ( & V_24 ) ;
F_13 ( V_16 -> V_29 ) ;
if ( V_16 -> V_20 ) {
memset ( V_16 -> V_20 , 0 , strlen ( V_16 -> V_20 ) ) ;
F_13 ( V_16 -> V_20 ) ;
}
F_13 ( V_16 ) ;
}
struct V_30 *
F_18 ( void )
{
struct V_30 * V_7 = NULL ;
T_1 V_31 = sizeof( struct V_30 ) ;
#ifdef F_19
V_31 = sizeof( struct V_32 ) ;
#endif
V_7 = F_20 ( V_33 , V_34 ) ;
if ( V_7 ) {
memset ( V_7 , 0 , V_31 + 3 ) ;
F_8 ( & V_35 ) ;
#ifdef F_21
F_8 ( & V_36 ) ;
#endif
}
return V_7 ;
}
void
F_22 ( void * V_16 )
{
if ( V_16 == NULL ) {
return;
}
F_23 ( V_16 , V_33 ) ;
F_12 ( & V_35 ) ;
return;
}
struct V_30 *
F_24 ( void )
{
struct V_30 * V_7 = NULL ;
V_7 = F_20 ( V_37 , V_34 ) ;
if ( V_7 ) {
F_8 ( & V_38 ) ;
#ifdef F_21
F_8 ( & V_39 ) ;
#endif
}
return V_7 ;
}
void
F_25 ( void * V_16 )
{
if ( V_16 == NULL ) {
F_3 ( 1 , L_4 ) ;
return;
}
F_23 ( V_16 , V_37 ) ;
F_12 ( & V_38 ) ;
return;
}
void
F_26 ( struct V_30 * V_40 , char V_41 ,
const struct V_23 * V_42 , int V_43
)
{
char * V_44 = ( char * ) V_40 ;
memset ( V_44 , 0 , 256 ) ;
V_40 -> V_45 = F_27 (
( 2 * V_43 ) + sizeof( struct V_30 ) -
4 +
2 ) ;
V_40 -> V_46 [ 0 ] = 0xFF ;
V_40 -> V_46 [ 1 ] = 'S' ;
V_40 -> V_46 [ 2 ] = 'M' ;
V_40 -> V_46 [ 3 ] = 'B' ;
V_40 -> V_47 = V_41 ;
V_40 -> V_48 = 0x00 ;
V_40 -> V_49 = V_50 ;
V_40 -> V_51 = F_28 ( ( V_52 ) V_53 -> V_54 ) ;
V_40 -> V_55 = F_28 ( ( V_52 ) ( V_53 -> V_54 >> 16 ) ) ;
if ( V_42 ) {
V_40 -> V_56 = V_42 -> V_57 ;
if ( V_42 -> V_58 ) {
if ( V_42 -> V_58 -> V_59 & V_60 )
V_40 -> V_49 |= V_61 ;
if ( V_42 -> V_58 -> V_59 & V_62 )
V_40 -> V_49 |= V_63 ;
V_40 -> V_64 = V_42 -> V_58 -> V_65 ;
V_40 -> V_66 = F_29 ( V_42 -> V_58 -> V_67 ) ;
}
if ( V_42 -> V_48 & V_68 )
V_40 -> V_49 |= V_69 ;
if ( V_42 -> V_70 )
V_40 -> V_48 |= V_71 ;
if ( ( V_42 -> V_58 ) && ( V_42 -> V_58 -> V_67 ) )
if ( V_42 -> V_58 -> V_67 -> V_72 &
( V_73 | V_74 ) )
V_40 -> V_49 |= V_75 ;
}
V_40 -> V_76 = ( char ) V_43 ;
return;
}
static int
F_30 ( struct V_30 * V_77 , V_52 V_78 )
{
if ( * ( V_79 * ) V_77 -> V_46 != F_31 ( 0x424d53ff ) ) {
F_32 ( 1 , L_5 ,
* ( unsigned int * ) V_77 -> V_46 ) ;
return 1 ;
}
if ( V_78 != V_77 -> V_66 ) {
F_32 ( 1 , L_6 ,
V_77 -> V_66 , V_78 ) ;
return 1 ;
}
if ( V_77 -> V_48 & V_80 )
return 0 ;
if ( V_77 -> V_47 == V_81 )
return 0 ;
F_32 ( 1 , L_7 , V_77 -> V_66 ) ;
return 1 ;
}
int
F_33 ( char * V_82 , unsigned int V_83 )
{
struct V_30 * V_77 = (struct V_30 * ) V_82 ;
V_52 V_78 = V_77 -> V_66 ;
T_2 V_84 = F_34 ( V_77 -> V_45 ) ;
T_2 V_85 ;
F_3 ( 0 , L_8 ,
V_83 , V_84 ) ;
if ( V_83 < 2 + sizeof( struct V_30 ) ) {
if ( ( V_83 >= sizeof( struct V_30 ) - 1 )
&& ( V_77 -> V_86 . V_87 != 0 ) ) {
V_77 -> V_76 = 0 ;
return 0 ;
} else if ( ( V_83 == sizeof( struct V_30 ) + 1 ) &&
( V_77 -> V_76 == 0 ) ) {
char * V_88 = ( char * ) V_77 ;
if ( V_88 [ sizeof( struct V_30 ) ] == 0 ) {
V_88 [ sizeof( struct V_30 ) + 1 ] = 0 ;
return 0 ;
}
F_32 ( 1 , L_9 ) ;
} else {
F_32 ( 1 , L_10 ) ;
}
return - V_89 ;
}
if ( F_30 ( V_77 , V_78 ) )
return - V_89 ;
V_85 = F_35 ( V_77 ) ;
if ( 4 + V_84 != V_83 ) {
F_32 ( 1 , L_11 ,
V_84 ) ;
return - V_89 ;
}
if ( 4 + V_84 != V_85 ) {
if ( ( V_84 > 64 * 1024 ) && ( V_84 > V_85 ) ) {
if ( ( ( 4 + V_84 ) & 0xFFFF ) == ( V_85 & 0xFFFF ) )
return 0 ;
}
F_3 ( 1 , L_12 ,
V_85 , 4 + V_84 , V_77 -> V_66 ) ;
if ( 4 + V_84 < V_85 ) {
F_32 ( 1 , L_13 ,
V_84 , V_77 -> V_66 ) ;
return - V_89 ;
} else if ( V_84 > V_85 + 512 ) {
F_32 ( 1 , L_14
L_15 , V_84 , V_77 -> V_66 ) ;
return - V_89 ;
}
}
return 0 ;
}
bool
F_36 ( char * V_40 , struct V_90 * V_91 )
{
struct V_30 * V_82 = (struct V_30 * ) V_40 ;
struct V_92 * V_93 = (struct V_92 * ) V_82 ;
struct V_94 * V_88 , * V_95 , * V_96 ;
struct V_6 * V_58 ;
struct V_23 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
F_3 ( 1 , L_16 ) ;
if ( ( V_93 -> V_102 . V_47 == V_103 ) &&
( V_93 -> V_102 . V_48 & V_80 ) ) {
struct V_104 * V_105 =
(struct V_104 * ) V_82 ;
struct V_106 * V_107 ;
T_2 V_108 = 0 ;
if ( F_37 ( V_82 ) > sizeof( struct V_106 ) ) {
V_108 = F_38 ( V_105 -> V_109 ) ;
V_107 = (struct V_106 * )
( ( char * ) & V_105 -> V_102 . V_46 + V_108 ) ;
F_3 ( 1 , L_17 ,
V_107 -> V_110 , V_107 -> V_111 ) ;
return true ;
}
if ( V_105 -> V_102 . V_86 . V_87 ) {
F_3 ( 1 , L_18 ,
V_105 -> V_102 . V_86 . V_87 ) ;
return true ;
}
return false ;
}
if ( V_93 -> V_102 . V_47 != V_81 )
return false ;
if ( V_93 -> V_102 . V_48 & V_80 ) {
if ( ( V_112 ) ==
F_38 ( V_93 -> V_102 . V_86 . V_87 ) ) {
F_3 ( 1 , L_19 ) ;
return true ;
} else if ( V_113 ==
F_39 ( V_93 -> V_102 . V_86 . V_114 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_93 -> V_102 . V_76 != 8 )
return false ;
F_3 ( 1 , L_20 ,
V_93 -> V_115 , V_93 -> V_116 ) ;
if ( ! ( V_93 -> V_115 & V_117 ) )
return false ;
F_2 ( & V_118 ) ;
F_40 (tmp, &srv->smb_ses_list) {
V_58 = F_41 ( V_88 , struct V_6 , V_13 ) ;
F_40 (tmp1, &ses->tcon_list) {
V_97 = F_41 ( V_95 , struct V_23 , V_14 ) ;
if ( V_97 -> V_57 != V_82 -> V_56 )
continue;
F_42 ( & V_97 -> V_119 . V_120 . V_121 ) ;
F_2 ( & V_122 ) ;
F_40 (tmp2, &tcon->openFileList) {
V_101 = F_41 ( V_96 , struct V_100 ,
V_123 ) ;
if ( V_93 -> V_124 != V_101 -> V_125 . V_126 )
continue;
F_3 ( 1 , L_21 ) ;
V_99 = F_43 ( V_101 -> V_127 -> V_128 ) ;
F_44 ( V_99 ,
V_93 -> V_116 ? V_129 : 0 ) ;
F_45 ( V_130 ,
& V_101 -> V_131 ) ;
V_101 -> V_132 = false ;
F_4 ( & V_122 ) ;
F_4 ( & V_118 ) ;
return true ;
}
F_4 ( & V_122 ) ;
F_4 ( & V_118 ) ;
F_3 ( 1 , L_22 ) ;
return true ;
}
}
F_4 ( & V_118 ) ;
F_3 ( 1 , L_23 ) ;
return true ;
}
void
F_46 ( void * V_82 , int V_45 )
{
int V_133 , V_134 ;
char V_135 [ 17 ] ;
unsigned char * V_40 = V_82 ;
if ( V_136 == 0 )
return;
for ( V_133 = 0 , V_134 = 0 ; V_133 < V_45 ; V_133 ++ , V_134 ++ ) {
if ( V_133 % 8 == 0 ) {
F_47 ( V_137 L_24 ) ;
V_134 = 0 ;
}
F_47 ( L_25 , V_40 [ V_133 ] ) ;
V_135 [ 2 * V_134 ] = ' ' ;
if ( isprint ( V_40 [ V_133 ] ) )
V_135 [ 1 + ( 2 * V_134 ) ] = V_40 [ V_133 ] ;
else
V_135 [ 1 + ( 2 * V_134 ) ] = '_' ;
if ( V_133 % 8 == 7 ) {
V_135 [ 16 ] = 0 ;
F_47 ( L_26 , V_135 ) ;
}
}
for (; V_134 < 8 ; V_134 ++ ) {
F_47 ( L_27 ) ;
V_135 [ 2 * V_134 ] = ' ' ;
V_135 [ 1 + ( 2 * V_134 ) ] = ' ' ;
}
F_47 ( L_26 , V_135 ) ;
return;
}
void
F_48 ( struct V_138 * V_139 )
{
if ( V_139 -> V_140 & V_141 ) {
V_139 -> V_140 &= ~ V_141 ;
F_32 ( 1 , L_28
L_29
L_30
L_31
L_32 ,
F_49 ( V_139 ) -> V_142 ) ;
}
}
void F_44 ( struct V_98 * V_143 , T_2 V_144 )
{
V_144 &= 0xF ;
if ( V_144 == V_145 ) {
V_143 -> V_146 = true ;
V_143 -> V_147 = true ;
F_3 ( 1 , L_33 ,
& V_143 -> V_148 ) ;
} else if ( V_144 == V_129 ) {
V_143 -> V_146 = false ;
V_143 -> V_147 = true ;
F_3 ( 1 , L_34 ,
& V_143 -> V_148 ) ;
} else {
V_143 -> V_146 = false ;
V_143 -> V_147 = false ;
}
}
bool
F_50 ( struct V_138 * V_139 )
{
if ( V_139 -> V_140 & V_149 ) {
if ( V_139 -> V_150 == F_51 () )
return true ;
}
if ( V_139 -> V_140 & V_151 ) {
if ( F_52 ( V_139 -> V_152 ) )
return true ;
}
return false ;
}
void
F_53 ( struct V_153 * V_154 )
{
F_2 ( & V_122 ) ;
F_54 ( & V_154 -> V_155 ) ;
F_4 ( & V_122 ) ;
}
void
F_55 ( struct V_156 * V_125 , struct V_157 * V_158 ,
struct V_153 * V_154 )
{
#ifdef F_19
memcpy ( V_154 -> V_159 , V_125 -> V_159 , V_160 ) ;
#endif
V_154 -> V_144 = V_161 ;
V_154 -> V_158 = V_158 ;
V_125 -> V_162 = V_154 ;
F_56 ( & V_154 -> V_155 , & F_57 ( V_158 ) -> V_163 ) ;
}
void
F_58 ( struct V_156 * V_125 , struct V_157 * V_158 ,
struct V_153 * V_154 )
{
F_2 ( & V_122 ) ;
F_55 ( V_125 , V_158 , V_154 ) ;
F_4 ( & V_122 ) ;
}
