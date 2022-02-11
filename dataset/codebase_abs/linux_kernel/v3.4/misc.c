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
V_7 = F_19 ( V_31 , V_32 ) ;
if ( V_7 ) {
memset ( V_7 , 0 , sizeof( struct V_30 ) + 3 ) ;
F_8 ( & V_33 ) ;
#ifdef F_20
F_8 ( & V_34 ) ;
#endif
}
return V_7 ;
}
void
F_21 ( void * V_16 )
{
if ( V_16 == NULL ) {
return;
}
F_22 ( V_16 , V_31 ) ;
F_12 ( & V_33 ) ;
return;
}
struct V_30 *
F_23 ( void )
{
struct V_30 * V_7 = NULL ;
V_7 = F_19 ( V_35 , V_32 ) ;
if ( V_7 ) {
F_8 ( & V_36 ) ;
#ifdef F_20
F_8 ( & V_37 ) ;
#endif
}
return V_7 ;
}
void
F_24 ( void * V_16 )
{
if ( V_16 == NULL ) {
F_3 ( 1 , L_4 ) ;
return;
}
F_22 ( V_16 , V_35 ) ;
F_12 ( & V_36 ) ;
return;
}
T_1 F_25 ( struct V_38 * V_39 )
{
T_1 V_40 = 0 ;
T_2 V_41 , V_42 ;
bool V_43 ;
F_2 ( & V_2 ) ;
V_42 = ( T_2 ) ( ( V_39 -> V_44 ) & 0xffff ) ;
V_41 = V_42 ;
V_42 ++ ;
while ( V_42 != V_41 ) {
struct V_45 * V_46 ;
unsigned int V_47 ;
V_43 = false ;
if ( V_42 == 0 )
V_42 ++ ;
V_47 = 0 ;
F_26 (mid_entry, &server->pending_mid_q, qhead) {
++ V_47 ;
if ( V_46 -> V_40 == V_42 &&
V_46 -> V_48 == V_49 ) {
V_43 = true ;
break;
}
}
if ( V_47 > 32768 )
V_39 -> V_50 = V_51 ;
if ( ! V_43 ) {
V_40 = ( T_1 ) V_42 ;
V_39 -> V_44 = V_40 ;
break;
}
V_42 ++ ;
}
F_4 ( & V_2 ) ;
return V_40 ;
}
void
F_27 ( struct V_30 * V_52 , char V_53 ,
const struct V_23 * V_54 , int V_55
)
{
struct V_56 * V_57 ;
struct V_6 * V_58 ;
char * V_59 = ( char * ) V_52 ;
memset ( V_59 , 0 , 256 ) ;
V_52 -> V_60 = F_28 (
( 2 * V_55 ) + sizeof( struct V_30 ) -
4 +
2 ) ;
V_52 -> V_61 [ 0 ] = 0xFF ;
V_52 -> V_61 [ 1 ] = 'S' ;
V_52 -> V_61 [ 2 ] = 'M' ;
V_52 -> V_61 [ 3 ] = 'B' ;
V_52 -> V_62 = V_53 ;
V_52 -> V_63 = 0x00 ;
V_52 -> V_64 = V_65 ;
V_52 -> V_66 = F_29 ( ( T_2 ) V_67 -> V_68 ) ;
V_52 -> V_69 = F_29 ( ( T_2 ) ( V_67 -> V_68 >> 16 ) ) ;
if ( V_54 ) {
V_52 -> V_70 = V_54 -> V_71 ;
if ( V_54 -> V_58 ) {
if ( V_54 -> V_58 -> V_72 & V_73 )
V_52 -> V_64 |= V_74 ;
if ( V_54 -> V_58 -> V_72 & V_75 )
V_52 -> V_64 |= V_76 ;
V_52 -> V_77 = V_54 -> V_58 -> V_78 ;
V_52 -> V_79 = F_25 ( V_54 -> V_58 -> V_39 ) ;
if ( V_80 != 0 ) {
if ( F_30 () != V_54 -> V_58 -> V_81 ) {
F_3 ( 1 , L_5
L_6 ) ;
F_2 ( & V_82 ) ;
F_31 (temp_item, &treeCon->ses->server->smb_ses_list) {
V_58 = F_32 ( V_57 , struct V_6 , V_13 ) ;
if ( V_58 -> V_81 == F_30 () ) {
if ( V_58 -> V_39 == V_54 -> V_58 -> V_39 ) {
F_3 ( 1 , L_7 ) ;
V_52 -> V_77 = V_58 -> V_78 ;
break;
} else {
F_3 ( 1 , L_8 ) ;
}
}
}
F_4 ( & V_82 ) ;
}
}
}
if ( V_54 -> V_63 & V_83 )
V_52 -> V_64 |= V_84 ;
if ( V_54 -> V_85 )
V_52 -> V_63 |= V_86 ;
if ( ( V_54 -> V_58 ) && ( V_54 -> V_58 -> V_39 ) )
if ( V_54 -> V_58 -> V_39 -> V_87 &
( V_88 | V_89 ) )
V_52 -> V_64 |= V_90 ;
}
V_52 -> V_91 = ( char ) V_55 ;
return;
}
static int
F_33 ( struct V_30 * V_92 , T_2 V_40 )
{
if ( * ( V_93 * ) V_92 -> V_61 != F_34 ( 0x424d53ff ) ) {
F_35 ( 1 , L_9 ,
* ( unsigned int * ) V_92 -> V_61 ) ;
return 1 ;
}
if ( V_40 != V_92 -> V_79 ) {
F_35 ( 1 , L_10 ,
V_92 -> V_79 , V_40 ) ;
return 1 ;
}
if ( V_92 -> V_63 & V_94 )
return 0 ;
if ( V_92 -> V_62 == V_95 )
return 0 ;
F_35 ( 1 , L_11 , V_92 -> V_79 ) ;
return 1 ;
}
int
F_36 ( char * V_96 , unsigned int V_97 )
{
struct V_30 * V_92 = (struct V_30 * ) V_96 ;
T_2 V_40 = V_92 -> V_79 ;
T_3 V_98 = F_37 ( V_92 -> V_60 ) ;
T_3 V_99 ;
F_3 ( 0 , L_12 ,
V_97 , V_98 ) ;
if ( V_97 < 2 + sizeof( struct V_30 ) ) {
if ( ( V_97 >= sizeof( struct V_30 ) - 1 )
&& ( V_92 -> V_100 . V_101 != 0 ) ) {
V_92 -> V_91 = 0 ;
return 0 ;
} else if ( ( V_97 == sizeof( struct V_30 ) + 1 ) &&
( V_92 -> V_91 == 0 ) ) {
char * V_102 = ( char * ) V_92 ;
if ( V_102 [ sizeof( struct V_30 ) ] == 0 ) {
V_102 [ sizeof( struct V_30 ) + 1 ] = 0 ;
return 0 ;
}
F_35 ( 1 , L_13 ) ;
} else {
F_35 ( 1 , L_14 ) ;
}
return - V_103 ;
}
if ( F_33 ( V_92 , V_40 ) )
return - V_103 ;
V_99 = F_38 ( V_92 ) ;
if ( 4 + V_98 != V_97 ) {
F_35 ( 1 , L_15 ,
V_98 ) ;
return - V_103 ;
}
if ( 4 + V_98 != V_99 ) {
if ( ( V_98 > 64 * 1024 ) && ( V_98 > V_99 ) ) {
if ( ( ( 4 + V_98 ) & 0xFFFF ) == ( V_99 & 0xFFFF ) )
return 0 ;
}
F_3 ( 1 , L_16 ,
V_99 , 4 + V_98 , V_92 -> V_79 ) ;
if ( 4 + V_98 < V_99 ) {
F_35 ( 1 , L_17 ,
V_98 , V_92 -> V_79 ) ;
return - V_103 ;
} else if ( V_98 > V_99 + 512 ) {
F_35 ( 1 , L_18
L_19 , V_98 , V_92 -> V_79 ) ;
return - V_103 ;
}
}
return 0 ;
}
bool
F_39 ( char * V_52 , struct V_38 * V_104 )
{
struct V_30 * V_96 = (struct V_30 * ) V_52 ;
struct V_105 * V_106 = (struct V_105 * ) V_96 ;
struct V_56 * V_102 , * V_107 , * V_108 ;
struct V_6 * V_58 ;
struct V_23 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
F_3 ( 1 , L_20 ) ;
if ( ( V_106 -> V_114 . V_62 == V_115 ) &&
( V_106 -> V_114 . V_63 & V_94 ) ) {
struct V_116 * V_117 =
(struct V_116 * ) V_96 ;
struct V_118 * V_119 ;
T_3 V_120 = 0 ;
if ( F_40 ( V_96 ) > sizeof( struct V_118 ) ) {
V_120 = F_41 ( V_117 -> V_121 ) ;
V_119 = (struct V_118 * )
( ( char * ) & V_117 -> V_114 . V_61 + V_120 ) ;
F_3 ( 1 , L_21 ,
V_119 -> V_122 , V_119 -> V_123 ) ;
return true ;
}
if ( V_117 -> V_114 . V_100 . V_101 ) {
F_3 ( 1 , L_22 ,
V_117 -> V_114 . V_100 . V_101 ) ;
return true ;
}
return false ;
}
if ( V_106 -> V_114 . V_62 != V_95 )
return false ;
if ( V_106 -> V_114 . V_63 & V_94 ) {
if ( ( V_124 ) ==
F_41 ( V_106 -> V_114 . V_100 . V_101 ) ) {
F_3 ( 1 , L_23 ) ;
return true ;
} else if ( V_125 ==
F_42 ( V_106 -> V_114 . V_100 . V_126 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_106 -> V_114 . V_91 != 8 )
return false ;
F_3 ( 1 , L_24 ,
V_106 -> V_127 , V_106 -> V_128 ) ;
if ( ! ( V_106 -> V_127 & V_129 ) )
return false ;
F_2 ( & V_82 ) ;
F_31 (tmp, &srv->smb_ses_list) {
V_58 = F_32 ( V_102 , struct V_6 , V_13 ) ;
F_31 (tmp1, &ses->tcon_list) {
V_109 = F_32 ( V_107 , struct V_23 , V_14 ) ;
if ( V_109 -> V_71 != V_96 -> V_70 )
continue;
F_43 ( & V_109 -> V_130 ) ;
F_2 ( & V_131 ) ;
F_31 (tmp2, &tcon->openFileList) {
V_113 = F_32 ( V_108 , struct V_112 ,
V_132 ) ;
if ( V_106 -> V_133 != V_113 -> V_134 )
continue;
F_3 ( 1 , L_25 ) ;
V_111 = F_44 ( V_113 -> V_135 -> V_136 ) ;
F_45 ( V_111 ,
V_106 -> V_128 ? V_137 : 0 ) ;
F_46 ( V_138 ,
& V_113 -> V_139 ) ;
V_113 -> V_140 = false ;
F_4 ( & V_131 ) ;
F_4 ( & V_82 ) ;
return true ;
}
F_4 ( & V_131 ) ;
F_4 ( & V_82 ) ;
F_3 ( 1 , L_26 ) ;
return true ;
}
}
F_4 ( & V_82 ) ;
F_3 ( 1 , L_27 ) ;
return true ;
}
void
F_47 ( void * V_96 , int V_60 )
{
int V_141 , V_142 ;
char V_143 [ 17 ] ;
unsigned char * V_52 = V_96 ;
if ( V_144 == 0 )
return;
for ( V_141 = 0 , V_142 = 0 ; V_141 < V_60 ; V_141 ++ , V_142 ++ ) {
if ( V_141 % 8 == 0 ) {
F_48 ( V_145 L_28 ) ;
V_142 = 0 ;
}
F_48 ( L_29 , V_52 [ V_141 ] ) ;
V_143 [ 2 * V_142 ] = ' ' ;
if ( isprint ( V_52 [ V_141 ] ) )
V_143 [ 1 + ( 2 * V_142 ) ] = V_52 [ V_141 ] ;
else
V_143 [ 1 + ( 2 * V_142 ) ] = '_' ;
if ( V_141 % 8 == 7 ) {
V_143 [ 16 ] = 0 ;
F_48 ( L_30 , V_143 ) ;
}
}
for (; V_142 < 8 ; V_142 ++ ) {
F_48 ( L_31 ) ;
V_143 [ 2 * V_142 ] = ' ' ;
V_143 [ 1 + ( 2 * V_142 ) ] = ' ' ;
}
F_48 ( L_30 , V_143 ) ;
return;
}
void
F_49 ( struct V_146 * V_147 )
{
if ( V_147 -> V_148 & V_149 ) {
V_147 -> V_148 &= ~ V_149 ;
F_35 ( 1 , L_32
L_33
L_34
L_35
L_36 ,
F_50 ( V_147 ) -> V_150 ) ;
}
}
void F_45 ( struct V_110 * V_151 , T_3 V_152 )
{
V_152 &= 0xF ;
if ( V_152 == V_153 ) {
V_151 -> V_154 = true ;
V_151 -> V_155 = true ;
F_3 ( 1 , L_37 ,
& V_151 -> V_156 ) ;
} else if ( V_152 == V_137 ) {
V_151 -> V_154 = false ;
V_151 -> V_155 = true ;
F_3 ( 1 , L_38 ,
& V_151 -> V_156 ) ;
} else {
V_151 -> V_154 = false ;
V_151 -> V_155 = false ;
}
}
bool
F_51 ( struct V_146 * V_147 )
{
if ( V_147 -> V_148 & V_157 ) {
if ( V_147 -> V_158 == F_30 () )
return true ;
}
if ( V_147 -> V_148 & V_159 ) {
if ( F_52 ( V_147 -> V_160 ) )
return true ;
}
return false ;
}
void
F_53 ( struct V_38 * V_39 , const unsigned int V_161 )
{
F_2 ( & V_39 -> V_162 ) ;
V_39 -> V_163 += V_161 ;
V_39 -> V_164 -- ;
F_4 ( & V_39 -> V_162 ) ;
F_54 ( & V_39 -> V_165 ) ;
}
void
F_55 ( struct V_38 * V_39 , const int V_166 )
{
F_2 ( & V_39 -> V_162 ) ;
V_39 -> V_163 = V_166 ;
V_39 -> V_167 = V_166 > 1 ? V_168 : false ;
F_4 ( & V_39 -> V_162 ) ;
}
