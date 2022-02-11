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
void
F_25 ( struct V_30 * V_38 , char V_39 ,
const struct V_23 * V_40 , int V_41
)
{
char * V_42 = ( char * ) V_38 ;
memset ( V_42 , 0 , 256 ) ;
V_38 -> V_43 = F_26 (
( 2 * V_41 ) + sizeof( struct V_30 ) -
4 +
2 ) ;
V_38 -> V_44 [ 0 ] = 0xFF ;
V_38 -> V_44 [ 1 ] = 'S' ;
V_38 -> V_44 [ 2 ] = 'M' ;
V_38 -> V_44 [ 3 ] = 'B' ;
V_38 -> V_45 = V_39 ;
V_38 -> V_46 = 0x00 ;
V_38 -> V_47 = V_48 ;
V_38 -> V_49 = F_27 ( ( V_50 ) V_51 -> V_52 ) ;
V_38 -> V_53 = F_27 ( ( V_50 ) ( V_51 -> V_52 >> 16 ) ) ;
if ( V_40 ) {
V_38 -> V_54 = V_40 -> V_55 ;
if ( V_40 -> V_56 ) {
if ( V_40 -> V_56 -> V_57 & V_58 )
V_38 -> V_47 |= V_59 ;
if ( V_40 -> V_56 -> V_57 & V_60 )
V_38 -> V_47 |= V_61 ;
V_38 -> V_62 = V_40 -> V_56 -> V_63 ;
V_38 -> V_64 = F_28 ( V_40 -> V_56 -> V_65 ) ;
}
if ( V_40 -> V_46 & V_66 )
V_38 -> V_47 |= V_67 ;
if ( V_40 -> V_68 )
V_38 -> V_46 |= V_69 ;
if ( ( V_40 -> V_56 ) && ( V_40 -> V_56 -> V_65 ) )
if ( V_40 -> V_56 -> V_65 -> V_70 &
( V_71 | V_72 ) )
V_38 -> V_47 |= V_73 ;
}
V_38 -> V_74 = ( char ) V_41 ;
return;
}
static int
F_29 ( struct V_30 * V_75 , V_50 V_76 )
{
if ( * ( V_77 * ) V_75 -> V_44 != F_30 ( 0x424d53ff ) ) {
F_31 ( 1 , L_5 ,
* ( unsigned int * ) V_75 -> V_44 ) ;
return 1 ;
}
if ( V_76 != V_75 -> V_64 ) {
F_31 ( 1 , L_6 ,
V_75 -> V_64 , V_76 ) ;
return 1 ;
}
if ( V_75 -> V_46 & V_78 )
return 0 ;
if ( V_75 -> V_45 == V_79 )
return 0 ;
F_31 ( 1 , L_7 , V_75 -> V_64 ) ;
return 1 ;
}
int
F_32 ( char * V_80 , unsigned int V_81 )
{
struct V_30 * V_75 = (struct V_30 * ) V_80 ;
V_50 V_76 = V_75 -> V_64 ;
T_1 V_82 = F_33 ( V_75 -> V_43 ) ;
T_1 V_83 ;
F_3 ( 0 , L_8 ,
V_81 , V_82 ) ;
if ( V_81 < 2 + sizeof( struct V_30 ) ) {
if ( ( V_81 >= sizeof( struct V_30 ) - 1 )
&& ( V_75 -> V_84 . V_85 != 0 ) ) {
V_75 -> V_74 = 0 ;
return 0 ;
} else if ( ( V_81 == sizeof( struct V_30 ) + 1 ) &&
( V_75 -> V_74 == 0 ) ) {
char * V_86 = ( char * ) V_75 ;
if ( V_86 [ sizeof( struct V_30 ) ] == 0 ) {
V_86 [ sizeof( struct V_30 ) + 1 ] = 0 ;
return 0 ;
}
F_31 ( 1 , L_9 ) ;
} else {
F_31 ( 1 , L_10 ) ;
}
return - V_87 ;
}
if ( F_29 ( V_75 , V_76 ) )
return - V_87 ;
V_83 = F_34 ( V_75 ) ;
if ( 4 + V_82 != V_81 ) {
F_31 ( 1 , L_11 ,
V_82 ) ;
return - V_87 ;
}
if ( 4 + V_82 != V_83 ) {
if ( ( V_82 > 64 * 1024 ) && ( V_82 > V_83 ) ) {
if ( ( ( 4 + V_82 ) & 0xFFFF ) == ( V_83 & 0xFFFF ) )
return 0 ;
}
F_3 ( 1 , L_12 ,
V_83 , 4 + V_82 , V_75 -> V_64 ) ;
if ( 4 + V_82 < V_83 ) {
F_31 ( 1 , L_13 ,
V_82 , V_75 -> V_64 ) ;
return - V_87 ;
} else if ( V_82 > V_83 + 512 ) {
F_31 ( 1 , L_14
L_15 , V_82 , V_75 -> V_64 ) ;
return - V_87 ;
}
}
return 0 ;
}
bool
F_35 ( char * V_38 , struct V_88 * V_89 )
{
struct V_30 * V_80 = (struct V_30 * ) V_38 ;
struct V_90 * V_91 = (struct V_90 * ) V_80 ;
struct V_92 * V_86 , * V_93 , * V_94 ;
struct V_6 * V_56 ;
struct V_23 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
F_3 ( 1 , L_16 ) ;
if ( ( V_91 -> V_100 . V_45 == V_101 ) &&
( V_91 -> V_100 . V_46 & V_78 ) ) {
struct V_102 * V_103 =
(struct V_102 * ) V_80 ;
struct V_104 * V_105 ;
T_1 V_106 = 0 ;
if ( F_36 ( V_80 ) > sizeof( struct V_104 ) ) {
V_106 = F_37 ( V_103 -> V_107 ) ;
V_105 = (struct V_104 * )
( ( char * ) & V_103 -> V_100 . V_44 + V_106 ) ;
F_3 ( 1 , L_17 ,
V_105 -> V_108 , V_105 -> V_109 ) ;
return true ;
}
if ( V_103 -> V_100 . V_84 . V_85 ) {
F_3 ( 1 , L_18 ,
V_103 -> V_100 . V_84 . V_85 ) ;
return true ;
}
return false ;
}
if ( V_91 -> V_100 . V_45 != V_79 )
return false ;
if ( V_91 -> V_100 . V_46 & V_78 ) {
if ( ( V_110 ) ==
F_37 ( V_91 -> V_100 . V_84 . V_85 ) ) {
F_3 ( 1 , L_19 ) ;
return true ;
} else if ( V_111 ==
F_38 ( V_91 -> V_100 . V_84 . V_112 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_91 -> V_100 . V_74 != 8 )
return false ;
F_3 ( 1 , L_20 ,
V_91 -> V_113 , V_91 -> V_114 ) ;
if ( ! ( V_91 -> V_113 & V_115 ) )
return false ;
F_2 ( & V_116 ) ;
F_39 (tmp, &srv->smb_ses_list) {
V_56 = F_40 ( V_86 , struct V_6 , V_13 ) ;
F_39 (tmp1, &ses->tcon_list) {
V_95 = F_40 ( V_93 , struct V_23 , V_14 ) ;
if ( V_95 -> V_55 != V_80 -> V_54 )
continue;
F_41 ( & V_95 -> V_117 ) ;
F_2 ( & V_118 ) ;
F_39 (tmp2, &tcon->openFileList) {
V_99 = F_40 ( V_94 , struct V_98 ,
V_119 ) ;
if ( V_91 -> V_120 != V_99 -> V_121 )
continue;
F_3 ( 1 , L_21 ) ;
V_97 = F_42 ( V_99 -> V_122 -> V_123 ) ;
F_43 ( V_97 ,
V_91 -> V_114 ? V_124 : 0 ) ;
F_44 ( V_125 ,
& V_99 -> V_126 ) ;
V_99 -> V_127 = false ;
F_4 ( & V_118 ) ;
F_4 ( & V_116 ) ;
return true ;
}
F_4 ( & V_118 ) ;
F_4 ( & V_116 ) ;
F_3 ( 1 , L_22 ) ;
return true ;
}
}
F_4 ( & V_116 ) ;
F_3 ( 1 , L_23 ) ;
return true ;
}
void
F_45 ( void * V_80 , int V_43 )
{
int V_128 , V_129 ;
char V_130 [ 17 ] ;
unsigned char * V_38 = V_80 ;
if ( V_131 == 0 )
return;
for ( V_128 = 0 , V_129 = 0 ; V_128 < V_43 ; V_128 ++ , V_129 ++ ) {
if ( V_128 % 8 == 0 ) {
F_46 ( V_132 L_24 ) ;
V_129 = 0 ;
}
F_46 ( L_25 , V_38 [ V_128 ] ) ;
V_130 [ 2 * V_129 ] = ' ' ;
if ( isprint ( V_38 [ V_128 ] ) )
V_130 [ 1 + ( 2 * V_129 ) ] = V_38 [ V_128 ] ;
else
V_130 [ 1 + ( 2 * V_129 ) ] = '_' ;
if ( V_128 % 8 == 7 ) {
V_130 [ 16 ] = 0 ;
F_46 ( L_26 , V_130 ) ;
}
}
for (; V_129 < 8 ; V_129 ++ ) {
F_46 ( L_27 ) ;
V_130 [ 2 * V_129 ] = ' ' ;
V_130 [ 1 + ( 2 * V_129 ) ] = ' ' ;
}
F_46 ( L_26 , V_130 ) ;
return;
}
void
F_47 ( struct V_133 * V_134 )
{
if ( V_134 -> V_135 & V_136 ) {
V_134 -> V_135 &= ~ V_136 ;
F_31 ( 1 , L_28
L_29
L_30
L_31
L_32 ,
F_48 ( V_134 ) -> V_137 ) ;
}
}
void F_43 ( struct V_96 * V_138 , T_1 V_139 )
{
V_139 &= 0xF ;
if ( V_139 == V_140 ) {
V_138 -> V_141 = true ;
V_138 -> V_142 = true ;
F_3 ( 1 , L_33 ,
& V_138 -> V_143 ) ;
} else if ( V_139 == V_124 ) {
V_138 -> V_141 = false ;
V_138 -> V_142 = true ;
F_3 ( 1 , L_34 ,
& V_138 -> V_143 ) ;
} else {
V_138 -> V_141 = false ;
V_138 -> V_142 = false ;
}
}
bool
F_49 ( struct V_133 * V_134 )
{
if ( V_134 -> V_135 & V_144 ) {
if ( V_134 -> V_145 == F_50 () )
return true ;
}
if ( V_134 -> V_135 & V_146 ) {
if ( F_51 ( V_134 -> V_147 ) )
return true ;
}
return false ;
}
