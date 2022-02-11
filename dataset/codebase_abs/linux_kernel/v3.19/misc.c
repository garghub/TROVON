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
F_26 ( int V_43 , void * V_44 )
{
if ( V_43 == V_45 )
F_25 ( V_44 ) ;
else if ( V_43 == V_46 )
F_22 ( V_44 ) ;
}
void
F_27 ( struct V_33 * V_47 , char V_48 ,
const struct V_26 * V_49 , int V_50
)
{
char * V_51 = ( char * ) V_47 ;
memset ( V_51 , 0 , 256 ) ;
V_47 -> V_52 = F_28 (
( 2 * V_50 ) + sizeof( struct V_33 ) -
4 +
2 ) ;
V_47 -> V_53 [ 0 ] = 0xFF ;
V_47 -> V_53 [ 1 ] = 'S' ;
V_47 -> V_53 [ 2 ] = 'M' ;
V_47 -> V_53 [ 3 ] = 'B' ;
V_47 -> V_54 = V_48 ;
V_47 -> V_55 = 0x00 ;
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = F_29 ( ( V_59 ) V_60 -> V_61 ) ;
V_47 -> V_62 = F_29 ( ( V_59 ) ( V_60 -> V_61 >> 16 ) ) ;
if ( V_49 ) {
V_47 -> V_63 = V_49 -> V_64 ;
if ( V_49 -> V_65 ) {
if ( V_49 -> V_65 -> V_66 & V_67 )
V_47 -> V_56 |= V_68 ;
if ( V_49 -> V_65 -> V_66 & V_69 )
V_47 -> V_56 |= V_70 ;
V_47 -> V_71 = V_49 -> V_65 -> V_72 ;
V_47 -> V_73 = F_30 ( V_49 -> V_65 -> V_74 ) ;
}
if ( V_49 -> V_55 & V_75 )
V_47 -> V_56 |= V_76 ;
if ( V_49 -> V_77 )
V_47 -> V_55 |= V_78 ;
if ( ( V_49 -> V_65 ) && ( V_49 -> V_65 -> V_74 ) )
if ( V_49 -> V_65 -> V_74 -> V_79 )
V_47 -> V_56 |= V_80 ;
}
V_47 -> V_81 = ( char ) V_50 ;
return;
}
static int
F_31 ( struct V_33 * V_82 )
{
if ( * ( V_83 * ) V_82 -> V_53 != F_32 ( 0x424d53ff ) ) {
F_3 ( V_84 , L_5 ,
* ( unsigned int * ) V_82 -> V_53 ) ;
return 1 ;
}
if ( V_82 -> V_55 & V_85 )
return 0 ;
if ( V_82 -> V_54 == V_86 )
return 0 ;
F_3 ( V_84 , L_6 ,
F_33 ( V_82 ) ) ;
return 1 ;
}
int
F_34 ( char * V_87 , unsigned int V_88 )
{
struct V_33 * V_82 = (struct V_33 * ) V_87 ;
T_2 V_89 = F_35 ( V_82 -> V_52 ) ;
T_2 V_90 ;
F_3 ( V_5 , L_7 ,
V_88 , V_89 ) ;
if ( V_88 < 2 + sizeof( struct V_33 ) ) {
if ( ( V_88 >= sizeof( struct V_33 ) - 1 )
&& ( V_82 -> V_91 . V_92 != 0 ) ) {
V_82 -> V_81 = 0 ;
return 0 ;
} else if ( ( V_88 == sizeof( struct V_33 ) + 1 ) &&
( V_82 -> V_81 == 0 ) ) {
char * V_93 = ( char * ) V_82 ;
if ( V_93 [ sizeof( struct V_33 ) ] == 0 ) {
V_93 [ sizeof( struct V_33 ) + 1 ] = 0 ;
return 0 ;
}
F_3 ( V_84 , L_8 ) ;
} else {
F_3 ( V_84 , L_9 ) ;
}
return - V_94 ;
}
if ( F_31 ( V_82 ) )
return - V_94 ;
V_90 = F_36 ( V_82 ) ;
if ( 4 + V_89 != V_88 ) {
F_3 ( V_84 , L_10 ,
V_89 ) ;
return - V_94 ;
}
if ( 4 + V_89 != V_90 ) {
V_59 V_95 = F_33 ( V_82 ) ;
if ( ( V_89 > 64 * 1024 ) && ( V_89 > V_90 ) ) {
if ( ( ( 4 + V_89 ) & 0xFFFF ) == ( V_90 & 0xFFFF ) )
return 0 ;
}
F_3 ( V_5 , L_11 ,
V_90 , 4 + V_89 , V_95 ) ;
if ( 4 + V_89 < V_90 ) {
F_3 ( V_84 , L_12 ,
V_89 , V_95 ) ;
return - V_94 ;
} else if ( V_89 > V_90 + 512 ) {
F_3 ( V_84 , L_13 ,
V_89 , V_95 ) ;
return - V_94 ;
}
}
return 0 ;
}
bool
F_37 ( char * V_47 , struct V_96 * V_97 )
{
struct V_33 * V_87 = (struct V_33 * ) V_47 ;
struct V_98 * V_99 = (struct V_98 * ) V_87 ;
struct V_100 * V_93 , * V_101 , * V_102 ;
struct V_7 * V_65 ;
struct V_26 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
F_3 ( V_5 , L_14 ) ;
if ( ( V_99 -> V_108 . V_54 == V_109 ) &&
( V_99 -> V_108 . V_55 & V_85 ) ) {
struct V_110 * V_111 =
(struct V_110 * ) V_87 ;
struct V_112 * V_113 ;
T_2 V_114 = 0 ;
if ( F_38 ( V_87 ) > sizeof( struct V_112 ) ) {
V_114 = F_39 ( V_111 -> V_115 ) ;
V_113 = (struct V_112 * )
( ( char * ) & V_111 -> V_108 . V_53 + V_114 ) ;
F_3 ( V_5 , L_15 ,
V_113 -> V_116 , V_113 -> V_117 ) ;
return true ;
}
if ( V_111 -> V_108 . V_91 . V_92 ) {
F_3 ( V_5 , L_16 ,
V_111 -> V_108 . V_91 . V_92 ) ;
return true ;
}
return false ;
}
if ( V_99 -> V_108 . V_54 != V_86 )
return false ;
if ( V_99 -> V_108 . V_55 & V_85 ) {
if ( ( V_118 ) ==
F_39 ( V_99 -> V_108 . V_91 . V_92 ) ) {
F_3 ( V_5 , L_17 ) ;
return true ;
} else if ( V_119 ==
F_40 ( V_99 -> V_108 . V_91 . V_120 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_99 -> V_108 . V_81 != 8 )
return false ;
F_3 ( V_5 , L_18 ,
V_99 -> V_121 , V_99 -> V_122 ) ;
if ( ! ( V_99 -> V_121 & V_123 ) )
return false ;
F_2 ( & V_124 ) ;
F_41 (tmp, &srv->smb_ses_list) {
V_65 = F_42 ( V_93 , struct V_7 , V_14 ) ;
F_41 (tmp1, &ses->tcon_list) {
V_103 = F_42 ( V_101 , struct V_26 , V_15 ) ;
if ( V_103 -> V_64 != V_87 -> V_63 )
continue;
F_43 ( & V_103 -> V_125 . V_126 . V_127 ) ;
F_2 ( & V_128 ) ;
F_41 (tmp2, &tcon->openFileList) {
V_107 = F_42 ( V_102 , struct V_106 ,
V_129 ) ;
if ( V_99 -> V_130 != V_107 -> V_131 . V_132 )
continue;
F_3 ( V_5 , L_19 ) ;
V_105 = F_44 ( V_107 -> V_133 -> V_134 ) ;
F_45 ( V_135 ,
& V_105 -> V_136 ) ;
if ( V_99 -> V_122 )
F_45 (
V_137 ,
& V_105 -> V_136 ) ;
else
F_46 (
V_137 ,
& V_105 -> V_136 ) ;
F_47 ( V_138 ,
& V_107 -> V_139 ) ;
V_107 -> V_140 = false ;
F_4 ( & V_128 ) ;
F_4 ( & V_124 ) ;
return true ;
}
F_4 ( & V_128 ) ;
F_4 ( & V_124 ) ;
F_3 ( V_5 , L_20 ) ;
return true ;
}
}
F_4 ( & V_124 ) ;
F_3 ( V_5 , L_21 ) ;
return true ;
}
void
F_48 ( void * V_87 , int V_52 )
{
if ( V_141 == 0 )
return;
F_49 ( V_142 , L_22 , V_143 , 8 , 2 , V_87 ,
V_52 , true ) ;
}
void
F_50 ( struct V_144 * V_145 )
{
if ( V_145 -> V_146 & V_147 ) {
V_145 -> V_146 &= ~ V_147 ;
F_3 ( V_84 , L_23 ,
F_51 ( V_145 ) -> V_148 ) ;
}
}
void F_52 ( struct V_104 * V_149 , T_2 V_150 )
{
V_150 &= 0xF ;
if ( V_150 == V_151 ) {
V_149 -> V_150 = V_152 | V_153 ;
F_3 ( V_5 , L_24 ,
& V_149 -> V_154 ) ;
} else if ( V_150 == V_155 ) {
V_149 -> V_150 = V_153 ;
F_3 ( V_5 , L_25 ,
& V_149 -> V_154 ) ;
} else
V_149 -> V_150 = 0 ;
}
int F_53 ( struct V_104 * V_149 )
{
int V_156 ;
V_157:
V_156 = F_54 ( & V_149 -> V_136 , V_135 ,
V_158 ) ;
if ( V_156 )
return V_156 ;
F_2 ( & V_149 -> V_159 ) ;
if ( ! V_149 -> V_160 )
F_45 ( V_161 , & V_149 -> V_136 ) ;
V_149 -> V_160 ++ ;
if ( F_55 ( V_135 , & V_149 -> V_136 ) ) {
V_149 -> V_160 -- ;
if ( V_149 -> V_160 == 0 ) {
F_46 ( V_161 , & V_149 -> V_136 ) ;
F_56 ( & V_149 -> V_136 , V_161 ) ;
}
F_4 ( & V_149 -> V_159 ) ;
goto V_157;
}
F_4 ( & V_149 -> V_159 ) ;
return 0 ;
}
void F_57 ( struct V_104 * V_149 )
{
F_2 ( & V_149 -> V_159 ) ;
V_149 -> V_160 -- ;
if ( V_149 -> V_160 == 0 ) {
F_46 ( V_161 , & V_149 -> V_136 ) ;
F_56 ( & V_149 -> V_136 , V_161 ) ;
}
F_4 ( & V_149 -> V_159 ) ;
}
void F_58 ( struct V_104 * V_149 )
{
F_46 ( V_135 , & V_149 -> V_136 ) ;
F_56 ( & V_149 -> V_136 , V_135 ) ;
}
bool
F_59 ( struct V_144 * V_145 )
{
if ( V_145 -> V_146 & V_162 ) {
if ( F_60 ( V_145 -> V_163 , F_61 () ) )
return true ;
}
if ( V_145 -> V_146 & V_164 ) {
if ( F_62 ( V_145 -> V_165 ) )
return true ;
}
return false ;
}
void
F_63 ( struct V_166 * V_167 )
{
F_2 ( & V_128 ) ;
F_64 ( & V_167 -> V_168 ) ;
F_4 ( & V_128 ) ;
}
void
F_65 ( struct V_169 * V_131 , struct V_170 * V_171 ,
struct V_166 * V_167 )
{
#ifdef F_19
memcpy ( V_167 -> V_172 , V_131 -> V_172 , V_173 ) ;
#endif
V_167 -> V_150 = V_174 ;
V_167 -> V_171 = V_171 ;
V_131 -> V_175 = V_167 ;
F_66 ( & V_167 -> V_168 , & F_67 ( V_171 ) -> V_176 ) ;
}
void
F_68 ( struct V_169 * V_131 , struct V_170 * V_171 ,
struct V_166 * V_167 )
{
F_2 ( & V_128 ) ;
F_65 ( V_131 , V_171 , V_167 ) ;
F_4 ( & V_128 ) ;
}
