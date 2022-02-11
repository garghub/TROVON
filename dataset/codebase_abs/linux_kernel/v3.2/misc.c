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
T_1 V_41 ;
bool V_42 ;
F_2 ( & V_2 ) ;
V_41 = V_39 -> V_43 ;
V_39 -> V_43 ++ ;
while ( V_39 -> V_43 != V_41 ) {
struct V_44 * V_45 ;
unsigned int V_46 ;
V_42 = false ;
if ( V_39 -> V_43 == 0 )
V_39 -> V_43 ++ ;
V_46 = 0 ;
F_26 (mid_entry, &server->pending_mid_q, qhead) {
++ V_46 ;
if ( V_45 -> V_40 == V_39 -> V_43 &&
V_45 -> V_47 == V_48 ) {
V_42 = true ;
break;
}
}
if ( V_46 > 32768 )
V_39 -> V_49 = V_50 ;
if ( ! V_42 ) {
V_40 = V_39 -> V_43 ;
break;
}
V_39 -> V_43 ++ ;
}
F_4 ( & V_2 ) ;
return V_40 ;
}
void
F_27 ( struct V_30 * V_51 , char V_52 ,
const struct V_23 * V_53 , int V_54
)
{
struct V_55 * V_56 ;
struct V_6 * V_57 ;
char * V_58 = ( char * ) V_51 ;
memset ( V_58 , 0 , 256 ) ;
V_51 -> V_59 = F_28 (
( 2 * V_54 ) + sizeof( struct V_30 ) -
4 +
2 ) ;
V_51 -> V_60 [ 0 ] = 0xFF ;
V_51 -> V_60 [ 1 ] = 'S' ;
V_51 -> V_60 [ 2 ] = 'M' ;
V_51 -> V_60 [ 3 ] = 'B' ;
V_51 -> V_61 = V_52 ;
V_51 -> V_62 = 0x00 ;
V_51 -> V_63 = V_64 ;
V_51 -> V_65 = F_29 ( ( T_1 ) V_66 -> V_67 ) ;
V_51 -> V_68 = F_29 ( ( T_1 ) ( V_66 -> V_67 >> 16 ) ) ;
if ( V_53 ) {
V_51 -> V_69 = V_53 -> V_70 ;
if ( V_53 -> V_57 ) {
if ( V_53 -> V_57 -> V_71 & V_72 )
V_51 -> V_63 |= V_73 ;
if ( V_53 -> V_57 -> V_71 & V_74 )
V_51 -> V_63 |= V_75 ;
V_51 -> V_76 = V_53 -> V_57 -> V_77 ;
V_51 -> V_78 = F_25 ( V_53 -> V_57 -> V_39 ) ;
if ( V_79 != 0 ) {
if ( F_30 () != V_53 -> V_57 -> V_80 ) {
F_3 ( 1 , L_5
L_6 ) ;
F_2 ( & V_81 ) ;
F_31 (temp_item, &treeCon->ses->server->smb_ses_list) {
V_57 = F_32 ( V_56 , struct V_6 , V_13 ) ;
if ( V_57 -> V_80 == F_30 () ) {
if ( V_57 -> V_39 == V_53 -> V_57 -> V_39 ) {
F_3 ( 1 , L_7 ) ;
V_51 -> V_76 = V_57 -> V_77 ;
break;
} else {
F_3 ( 1 , L_8 ) ;
}
}
}
F_4 ( & V_81 ) ;
}
}
}
if ( V_53 -> V_62 & V_82 )
V_51 -> V_63 |= V_83 ;
if ( V_53 -> V_84 )
V_51 -> V_62 |= V_85 ;
if ( ( V_53 -> V_57 ) && ( V_53 -> V_57 -> V_39 ) )
if ( V_53 -> V_57 -> V_39 -> V_86 &
( V_87 | V_88 ) )
V_51 -> V_63 |= V_89 ;
}
V_51 -> V_90 = ( char ) V_54 ;
return;
}
static int
F_33 ( struct V_30 * V_91 , T_1 V_40 )
{
if ( * ( V_92 * ) V_91 -> V_60 != F_34 ( 0x424d53ff ) ) {
F_35 ( 1 , L_9 ,
* ( unsigned int * ) V_91 -> V_60 ) ;
return 1 ;
}
if ( V_40 != V_91 -> V_78 ) {
F_35 ( 1 , L_10 ,
V_91 -> V_78 , V_40 ) ;
return 1 ;
}
if ( V_91 -> V_62 & V_93 )
return 0 ;
if ( V_91 -> V_61 == V_94 )
return 0 ;
F_35 ( 1 , L_11 , V_91 -> V_78 ) ;
return 1 ;
}
int
F_36 ( struct V_30 * V_91 , T_1 V_40 , unsigned int V_95 )
{
T_2 V_96 = F_37 ( V_91 -> V_59 ) ;
T_2 V_97 ;
F_3 ( 0 , L_12 ,
V_95 , V_96 ) ;
if ( V_95 < 2 + sizeof( struct V_30 ) ) {
if ( ( V_95 >= sizeof( struct V_30 ) - 1 )
&& ( V_91 -> V_98 . V_99 != 0 ) ) {
V_91 -> V_90 = 0 ;
return 0 ;
} else if ( ( V_95 == sizeof( struct V_30 ) + 1 ) &&
( V_91 -> V_90 == 0 ) ) {
char * V_100 = ( char * ) V_91 ;
if ( V_100 [ sizeof( struct V_30 ) ] == 0 ) {
V_100 [ sizeof( struct V_30 ) + 1 ] = 0 ;
return 0 ;
}
F_35 ( 1 , L_13 ) ;
} else {
F_35 ( 1 , L_14 ) ;
}
return - V_101 ;
}
if ( F_33 ( V_91 , V_40 ) )
return - V_101 ;
V_97 = F_38 ( V_91 ) ;
if ( 4 + V_96 != V_95 ) {
F_35 ( 1 , L_15 ,
V_96 ) ;
return - V_101 ;
}
if ( 4 + V_96 != V_97 ) {
if ( ( V_96 > 64 * 1024 ) && ( V_96 > V_97 ) ) {
if ( ( ( 4 + V_96 ) & 0xFFFF ) == ( V_97 & 0xFFFF ) )
return 0 ;
}
F_3 ( 1 , L_16 ,
V_97 , 4 + V_96 , V_91 -> V_78 ) ;
if ( 4 + V_96 < V_97 ) {
F_35 ( 1 , L_17 ,
V_96 , V_91 -> V_78 ) ;
return - V_101 ;
} else if ( V_96 > V_97 + 512 ) {
F_35 ( 1 , L_18
L_19 , V_96 , V_91 -> V_78 ) ;
return - V_101 ;
}
}
return 0 ;
}
bool
F_39 ( struct V_30 * V_102 , struct V_38 * V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_55 * V_100 , * V_106 , * V_107 ;
struct V_6 * V_57 ;
struct V_23 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
F_3 ( 1 , L_20 ) ;
if ( ( V_105 -> V_113 . V_61 == V_114 ) &&
( V_105 -> V_113 . V_62 & V_93 ) ) {
struct V_115 * V_116 =
(struct V_115 * ) V_102 ;
struct V_117 * V_118 ;
T_2 V_119 = 0 ;
if ( F_40 ( V_102 ) > sizeof( struct V_117 ) ) {
V_119 = F_41 ( V_116 -> V_120 ) ;
V_118 = (struct V_117 * )
( ( char * ) & V_116 -> V_113 . V_60 + V_119 ) ;
F_3 ( 1 , L_21 ,
V_118 -> V_121 , V_118 -> V_122 ) ;
return true ;
}
if ( V_116 -> V_113 . V_98 . V_99 ) {
F_3 ( 1 , L_22 ,
V_116 -> V_113 . V_98 . V_99 ) ;
return true ;
}
return false ;
}
if ( V_105 -> V_113 . V_61 != V_94 )
return false ;
if ( V_105 -> V_113 . V_62 & V_93 ) {
if ( ( V_123 ) ==
F_41 ( V_105 -> V_113 . V_98 . V_99 ) ) {
F_3 ( 1 , L_23 ) ;
return true ;
} else if ( V_124 ==
F_42 ( V_105 -> V_113 . V_98 . V_125 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_105 -> V_113 . V_90 != 8 )
return false ;
F_3 ( 1 , L_24 ,
V_105 -> V_126 , V_105 -> V_127 ) ;
if ( ! ( V_105 -> V_126 & V_128 ) )
return false ;
F_2 ( & V_81 ) ;
F_31 (tmp, &srv->smb_ses_list) {
V_57 = F_32 ( V_100 , struct V_6 , V_13 ) ;
F_31 (tmp1, &ses->tcon_list) {
V_108 = F_32 ( V_106 , struct V_23 , V_14 ) ;
if ( V_108 -> V_70 != V_102 -> V_69 )
continue;
F_43 ( & V_108 -> V_129 ) ;
F_2 ( & V_130 ) ;
F_31 (tmp2, &tcon->openFileList) {
V_112 = F_32 ( V_107 , struct V_111 ,
V_131 ) ;
if ( V_105 -> V_132 != V_112 -> V_133 )
continue;
F_3 ( 1 , L_25 ) ;
V_110 = F_44 ( V_112 -> V_134 -> V_135 ) ;
F_45 ( V_110 ,
V_105 -> V_127 ? V_136 : 0 ) ;
F_46 ( V_137 ,
& V_112 -> V_138 ) ;
V_112 -> V_139 = false ;
F_4 ( & V_130 ) ;
F_4 ( & V_81 ) ;
return true ;
}
F_4 ( & V_130 ) ;
F_4 ( & V_81 ) ;
F_3 ( 1 , L_26 ) ;
return true ;
}
}
F_4 ( & V_81 ) ;
F_3 ( 1 , L_27 ) ;
return true ;
}
void
F_47 ( struct V_30 * V_140 , int V_59 )
{
int V_141 , V_142 ;
char V_143 [ 17 ] ;
unsigned char * V_51 ;
if ( V_144 == 0 )
return;
V_51 = ( unsigned char * ) V_140 ;
for ( V_141 = 0 , V_142 = 0 ; V_141 < V_59 ; V_141 ++ , V_142 ++ ) {
if ( V_141 % 8 == 0 ) {
F_48 ( V_145 L_28 ) ;
V_142 = 0 ;
}
F_48 ( L_29 , V_51 [ V_141 ] ) ;
V_143 [ 2 * V_142 ] = ' ' ;
if ( isprint ( V_51 [ V_141 ] ) )
V_143 [ 1 + ( 2 * V_142 ) ] = V_51 [ V_141 ] ;
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
void F_45 ( struct V_109 * V_151 , T_2 V_152 )
{
V_152 &= 0xF ;
if ( V_152 == V_153 ) {
V_151 -> V_154 = true ;
V_151 -> V_155 = true ;
F_3 ( 1 , L_37 ,
& V_151 -> V_156 ) ;
} else if ( V_152 == V_136 ) {
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
