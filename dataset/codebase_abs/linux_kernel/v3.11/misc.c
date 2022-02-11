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
if ( V_43 -> V_59 -> V_68 -> V_73 )
V_41 -> V_50 |= V_74 ;
}
V_41 -> V_75 = ( char ) V_44 ;
return;
}
static int
F_30 ( struct V_31 * V_76 , V_53 V_77 )
{
if ( * ( V_78 * ) V_76 -> V_47 != F_31 ( 0x424d53ff ) ) {
F_3 ( V_79 , L_5 ,
* ( unsigned int * ) V_76 -> V_47 ) ;
return 1 ;
}
if ( V_77 != V_76 -> V_67 ) {
F_3 ( V_79 , L_6 ,
V_76 -> V_67 , V_77 ) ;
return 1 ;
}
if ( V_76 -> V_49 & V_80 )
return 0 ;
if ( V_76 -> V_48 == V_81 )
return 0 ;
F_3 ( V_79 , L_7 , V_76 -> V_67 ) ;
return 1 ;
}
int
F_32 ( char * V_82 , unsigned int V_83 )
{
struct V_31 * V_76 = (struct V_31 * ) V_82 ;
V_53 V_77 = V_76 -> V_67 ;
T_2 V_84 = F_33 ( V_76 -> V_46 ) ;
T_2 V_85 ;
F_3 ( V_5 , L_8 ,
V_83 , V_84 ) ;
if ( V_83 < 2 + sizeof( struct V_31 ) ) {
if ( ( V_83 >= sizeof( struct V_31 ) - 1 )
&& ( V_76 -> V_86 . V_87 != 0 ) ) {
V_76 -> V_75 = 0 ;
return 0 ;
} else if ( ( V_83 == sizeof( struct V_31 ) + 1 ) &&
( V_76 -> V_75 == 0 ) ) {
char * V_88 = ( char * ) V_76 ;
if ( V_88 [ sizeof( struct V_31 ) ] == 0 ) {
V_88 [ sizeof( struct V_31 ) + 1 ] = 0 ;
return 0 ;
}
F_3 ( V_79 , L_9 ) ;
} else {
F_3 ( V_79 , L_10 ) ;
}
return - V_89 ;
}
if ( F_30 ( V_76 , V_77 ) )
return - V_89 ;
V_85 = F_34 ( V_76 ) ;
if ( 4 + V_84 != V_83 ) {
F_3 ( V_79 , L_11 ,
V_84 ) ;
return - V_89 ;
}
if ( 4 + V_84 != V_85 ) {
if ( ( V_84 > 64 * 1024 ) && ( V_84 > V_85 ) ) {
if ( ( ( 4 + V_84 ) & 0xFFFF ) == ( V_85 & 0xFFFF ) )
return 0 ;
}
F_3 ( V_5 , L_12 ,
V_85 , 4 + V_84 , V_76 -> V_67 ) ;
if ( 4 + V_84 < V_85 ) {
F_3 ( V_79 , L_13 ,
V_84 , V_76 -> V_67 ) ;
return - V_89 ;
} else if ( V_84 > V_85 + 512 ) {
F_3 ( V_79 , L_14 ,
V_84 , V_76 -> V_67 ) ;
return - V_89 ;
}
}
return 0 ;
}
bool
F_35 ( char * V_41 , struct V_90 * V_91 )
{
struct V_31 * V_82 = (struct V_31 * ) V_41 ;
struct V_92 * V_93 = (struct V_92 * ) V_82 ;
struct V_94 * V_88 , * V_95 , * V_96 ;
struct V_7 * V_59 ;
struct V_24 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
F_3 ( V_5 , L_15 ) ;
if ( ( V_93 -> V_102 . V_48 == V_103 ) &&
( V_93 -> V_102 . V_49 & V_80 ) ) {
struct V_104 * V_105 =
(struct V_104 * ) V_82 ;
struct V_106 * V_107 ;
T_2 V_108 = 0 ;
if ( F_36 ( V_82 ) > sizeof( struct V_106 ) ) {
V_108 = F_37 ( V_105 -> V_109 ) ;
V_107 = (struct V_106 * )
( ( char * ) & V_105 -> V_102 . V_47 + V_108 ) ;
F_3 ( V_5 , L_16 ,
V_107 -> V_110 , V_107 -> V_111 ) ;
return true ;
}
if ( V_105 -> V_102 . V_86 . V_87 ) {
F_3 ( V_5 , L_17 ,
V_105 -> V_102 . V_86 . V_87 ) ;
return true ;
}
return false ;
}
if ( V_93 -> V_102 . V_48 != V_81 )
return false ;
if ( V_93 -> V_102 . V_49 & V_80 ) {
if ( ( V_112 ) ==
F_37 ( V_93 -> V_102 . V_86 . V_87 ) ) {
F_3 ( V_5 , L_18 ) ;
return true ;
} else if ( V_113 ==
F_38 ( V_93 -> V_102 . V_86 . V_114 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_93 -> V_102 . V_75 != 8 )
return false ;
F_3 ( V_5 , L_19 ,
V_93 -> V_115 , V_93 -> V_116 ) ;
if ( ! ( V_93 -> V_115 & V_117 ) )
return false ;
F_2 ( & V_118 ) ;
F_39 (tmp, &srv->smb_ses_list) {
V_59 = F_40 ( V_88 , struct V_7 , V_14 ) ;
F_39 (tmp1, &ses->tcon_list) {
V_97 = F_40 ( V_95 , struct V_24 , V_15 ) ;
if ( V_97 -> V_58 != V_82 -> V_57 )
continue;
F_41 ( & V_97 -> V_119 . V_120 . V_121 ) ;
F_2 ( & V_122 ) ;
F_39 (tmp2, &tcon->openFileList) {
V_101 = F_40 ( V_96 , struct V_100 ,
V_123 ) ;
if ( V_93 -> V_124 != V_101 -> V_125 . V_126 )
continue;
F_3 ( V_5 , L_20 ) ;
V_99 = F_42 ( V_101 -> V_127 -> V_128 ) ;
F_43 ( V_99 ,
V_93 -> V_116 ? V_129 : 0 ) ;
F_44 ( V_130 ,
& V_101 -> V_131 ) ;
V_101 -> V_132 = false ;
F_4 ( & V_122 ) ;
F_4 ( & V_118 ) ;
return true ;
}
F_4 ( & V_122 ) ;
F_4 ( & V_118 ) ;
F_3 ( V_5 , L_21 ) ;
return true ;
}
}
F_4 ( & V_118 ) ;
F_3 ( V_5 , L_22 ) ;
return true ;
}
void
F_45 ( void * V_82 , int V_46 )
{
int V_133 , V_134 ;
char V_135 [ 17 ] ;
unsigned char * V_41 = V_82 ;
if ( V_136 == 0 )
return;
for ( V_133 = 0 , V_134 = 0 ; V_133 < V_46 ; V_133 ++ , V_134 ++ ) {
if ( V_133 % 8 == 0 ) {
F_46 ( V_137 L_23 ) ;
V_134 = 0 ;
}
F_46 ( L_24 , V_41 [ V_133 ] ) ;
V_135 [ 2 * V_134 ] = ' ' ;
if ( isprint ( V_41 [ V_133 ] ) )
V_135 [ 1 + ( 2 * V_134 ) ] = V_41 [ V_133 ] ;
else
V_135 [ 1 + ( 2 * V_134 ) ] = '_' ;
if ( V_133 % 8 == 7 ) {
V_135 [ 16 ] = 0 ;
F_46 ( L_25 , V_135 ) ;
}
}
for (; V_134 < 8 ; V_134 ++ ) {
F_46 ( L_26 ) ;
V_135 [ 2 * V_134 ] = ' ' ;
V_135 [ 1 + ( 2 * V_134 ) ] = ' ' ;
}
F_46 ( L_25 , V_135 ) ;
return;
}
void
F_47 ( struct V_138 * V_139 )
{
if ( V_139 -> V_140 & V_141 ) {
V_139 -> V_140 &= ~ V_141 ;
F_3 ( V_79 , L_27 ,
F_48 ( V_139 ) -> V_142 ) ;
}
}
void F_43 ( struct V_98 * V_143 , T_2 V_144 )
{
V_144 &= 0xF ;
if ( V_144 == V_145 ) {
V_143 -> V_146 = true ;
V_143 -> V_147 = true ;
F_3 ( V_5 , L_28 ,
& V_143 -> V_148 ) ;
} else if ( V_144 == V_129 ) {
V_143 -> V_146 = false ;
V_143 -> V_147 = true ;
F_3 ( V_5 , L_29 ,
& V_143 -> V_148 ) ;
} else {
V_143 -> V_146 = false ;
V_143 -> V_147 = false ;
}
}
bool
F_49 ( struct V_138 * V_139 )
{
if ( V_139 -> V_140 & V_149 ) {
if ( F_50 ( V_139 -> V_150 , F_51 () ) )
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
