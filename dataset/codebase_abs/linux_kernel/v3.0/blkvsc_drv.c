static int F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
V_5 = (struct V_4 * ) V_3 ;
V_5 -> V_7 = V_8 ;
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 != 0 )
return V_6 ;
V_5 -> V_9 = V_2 -> V_10 . V_11 [ 3 ] << 24 |
V_2 -> V_10 . V_11 [ 2 ] << 16 |
V_2 -> V_10 . V_11 [ 1 ] << 8 |
V_2 -> V_10 . V_11 [ 0 ] ;
V_5 -> V_12 = V_2 -> V_10 . V_11 [ 5 ] << 8 |
V_2 -> V_10 . V_11 [ 4 ] ;
return V_6 ;
}
static int F_3 ( struct V_13 * V_14 ,
void (* F_4)( struct V_15 * ) )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_15 * V_19 ;
struct V_20 * V_21 ;
int V_6 ;
V_19 = & V_14 -> V_22 ;
V_21 = & V_19 -> V_23 . V_21 ;
V_21 -> V_24 = V_14 -> V_25 ? V_26 : V_27 ;
V_19 -> V_28 = F_4 ;
V_19 -> V_29 = V_14 ;
V_21 -> V_30 = V_17 -> V_31 ;
V_21 -> V_9 = V_17 -> V_32 ;
V_21 -> V_12 = V_17 -> V_33 ;
V_21 -> V_34 = 0 ;
V_21 -> V_35 = V_14 -> V_36 ;
memcpy ( V_21 -> V_37 , V_14 -> V_38 , V_21 -> V_35 ) ;
V_19 -> V_39 = V_14 -> V_39 ;
V_6 = F_5 ( V_17 -> V_40 ,
& V_14 -> V_22 ) ;
if ( V_6 == 0 )
V_17 -> V_41 ++ ;
return V_6 ;
}
static int F_6 ( struct V_42 * V_43 , T_1 V_44 )
{
struct V_16 * V_17 = V_43 -> V_45 -> V_46 ;
unsigned long V_47 ;
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_49 ++ ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_42 * V_50 , struct V_51 * V_52 )
{
T_2 V_53 = F_10 ( V_50 -> V_45 ) ;
T_2 V_54 = V_53 ;
V_52 -> V_55 = 0xff ;
V_52 -> V_56 = 0x3f ;
F_11 ( V_54 , V_52 -> V_55 * V_52 -> V_56 ) ;
V_52 -> V_54 = V_54 ;
if ( ( T_2 ) ( V_52 -> V_54 + 1 ) * V_52 -> V_55 * V_52 -> V_56 < V_53 )
V_52 -> V_54 = 0xffff ;
return 0 ;
}
static void F_12 ( struct V_13 * V_14 )
{
V_14 -> V_36 = 16 ;
if ( F_13 ( V_14 -> V_57 ) ) {
V_14 -> V_25 = 1 ;
V_14 -> V_38 [ 0 ] = V_58 ;
} else {
V_14 -> V_25 = 0 ;
V_14 -> V_38 [ 0 ] = V_59 ;
}
V_14 -> V_38 [ 1 ] |=
( V_14 -> V_57 -> V_60 & V_61 ) ? 0x8 : 0 ;
* ( unsigned long long * ) & V_14 -> V_38 [ 2 ] =
F_14 ( V_14 -> V_62 ) ;
* ( unsigned int * ) & V_14 -> V_38 [ 10 ] =
F_15 ( V_14 -> V_63 ) ;
}
static int F_16 ( struct V_42 * V_50 , T_1 V_44 ,
unsigned V_64 , unsigned long V_65 )
{
struct V_16 * V_17 = V_50 -> V_45 -> V_46 ;
int V_6 = 0 ;
switch ( V_64 ) {
case V_66 :
if ( F_17 ( ( void V_67 * ) V_65 , V_17 -> V_68 ,
V_17 -> V_69 ) )
V_6 = - V_70 ;
break;
default:
V_6 = - V_71 ;
break;
}
return V_6 ;
}
static void F_18 ( struct V_15 * V_22 )
{
struct V_13 * V_14 =
(struct V_13 * ) V_22 -> V_29 ;
struct V_16 * V_17 =
(struct V_16 * ) V_14 -> V_18 ;
struct V_72 V_73 ;
struct V_20 * V_21 ;
unsigned long V_47 ;
V_21 = & V_14 -> V_22 . V_23 . V_21 ;
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_41 -- ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
if ( V_21 -> V_74 )
if ( F_19 ( V_14 -> V_39 ,
V_75 , & V_73 ) )
F_20 ( L_1 , & V_73 ) ;
F_21 ( & V_14 -> V_22 . V_76 ) ;
}
static int F_22 ( struct V_16 * V_17 ,
enum V_77 V_78 )
{
struct V_13 * V_14 ;
struct V_79 * V_80 ;
unsigned char * V_81 ;
unsigned char V_82 ;
struct V_72 V_73 ;
struct V_20 * V_21 ;
unsigned long V_47 ;
int V_6 = 0 ;
V_14 = F_23 ( V_17 -> V_83 , V_84 ) ;
if ( ! V_14 )
return - V_85 ;
V_80 = F_24 ( V_84 ) ;
if ( ! V_80 ) {
F_25 ( V_14 -> V_18 -> V_83 , V_14 ) ;
return - V_85 ;
}
V_21 = & V_14 -> V_22 . V_23 . V_21 ;
F_26 ( & V_14 -> V_22 . V_76 ) ;
V_14 -> V_18 = V_17 ;
V_14 -> V_57 = NULL ;
V_14 -> V_25 = 0 ;
V_14 -> V_22 . V_86 . V_87 [ 0 ] =
F_27 ( V_80 ) ;
V_14 -> V_22 . V_86 . V_88 = 0 ;
switch ( V_78 ) {
case V_89 :
V_14 -> V_38 [ 0 ] = V_90 ;
V_14 -> V_38 [ 1 ] = 0x1 ;
V_14 -> V_38 [ 2 ] = 0x83 ;
V_14 -> V_38 [ 4 ] = 64 ;
V_14 -> V_36 = 6 ;
V_14 -> V_22 . V_86 . V_91 = 64 ;
break;
case V_92 :
V_17 -> V_93 = 0 ;
V_17 -> V_94 = 0 ;
V_14 -> V_38 [ 0 ] = V_95 ;
V_14 -> V_36 = 16 ;
V_14 -> V_22 . V_86 . V_91 = 8 ;
break;
case V_96 :
V_14 -> V_38 [ 0 ] = V_97 ;
V_14 -> V_36 = 10 ;
V_14 -> V_22 . V_86 . V_87 [ 0 ] = 0 ;
V_14 -> V_22 . V_86 . V_91 = 0 ;
break;
default:
V_6 = - V_71 ;
goto V_98;
}
F_7 ( & V_17 -> V_48 , V_47 ) ;
F_3 ( V_14 , F_18 ) ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
F_28 ( & V_14 -> V_22 . V_76 ) ;
if ( V_21 -> V_74 ) {
F_19 ( V_14 -> V_39 ,
V_75 , & V_73 ) ;
return 0 ;
}
V_81 = F_29 ( V_80 ) ;
switch ( V_78 ) {
case V_89 :
V_82 = V_81 [ 0 ] & 0x1F ;
if ( V_82 == 0x0 )
V_17 -> V_82 = V_99 ;
else
V_17 -> V_82 = V_100 ;
V_17 -> V_69 = V_81 [ 7 ] ;
if ( V_17 -> V_69 > 64 )
V_17 -> V_69 = 64 ;
memcpy ( V_17 -> V_68 , & V_81 [ 8 ] , V_17 -> V_69 ) ;
break;
case V_92 :
V_17 -> V_94 =
( ( V_81 [ 0 ] << 24 ) | ( V_81 [ 1 ] << 16 ) |
( V_81 [ 2 ] << 8 ) | V_81 [ 3 ] ) + 1 ;
V_17 -> V_93 =
( V_81 [ 4 ] << 24 ) | ( V_81 [ 5 ] << 16 ) |
( V_81 [ 6 ] << 8 ) | V_81 [ 7 ] ;
break;
default:
break;
}
V_98:
F_30 ( V_80 ) ;
F_31 ( V_80 ) ;
F_25 ( V_14 -> V_18 -> V_83 , V_14 ) ;
return V_6 ;
}
static int F_32 ( struct V_16 * V_17 )
{
struct V_13 * V_101 , * V_102 ;
struct V_13 * V_103 , * V_104 ;
struct V_20 * V_21 ;
int V_6 = 0 ;
F_33 (pend_req, tmp, &blkdev->pending_list,
pend_entry) {
F_33 (comp_req, tmp2,
&pend_req->group->blkvsc_req_list,
req_entry) {
if ( V_103 == V_101 )
break;
F_34 ( & V_103 -> V_105 ) ;
if ( V_103 -> V_57 ) {
V_21 =
& V_103 -> V_22 . V_23 .
V_21 ;
V_6 = F_35 ( V_103 -> V_57 ,
( ! V_21 -> V_74 ? 0 : - V_106 ) ,
V_103 -> V_63 *
V_17 -> V_93 ) ;
if ( V_6 )
goto V_107;
}
F_25 ( V_17 -> V_83 , V_103 ) ;
}
F_34 ( & V_101 -> V_108 ) ;
F_34 ( & V_101 -> V_105 ) ;
if ( V_103 -> V_57 ) {
if ( ! F_35 ( V_101 -> V_57 , - V_106 ,
V_101 -> V_63 *
V_17 -> V_93 ) ) {
F_25 ( V_17 -> V_83 ,
V_101 -> V_109 ) ;
}
}
F_25 ( V_17 -> V_83 , V_101 ) ;
}
V_107:
return V_6 ;
}
static int F_36 ( struct V_1 * V_18 )
{
struct V_16 * V_17 = F_37 ( & V_18 -> V_2 ) ;
unsigned long V_47 ;
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_110 = 1 ;
F_38 ( V_17 -> V_111 -> V_112 ) ;
F_32 ( V_17 ) ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
F_22 ( V_17 , V_96 ) ;
F_39 ( V_17 -> V_111 -> V_112 ) ;
F_40 ( V_18 ) ;
F_41 ( V_17 -> V_111 ) ;
F_42 ( V_17 -> V_83 ) ;
F_43 ( V_17 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_18 )
{
struct V_16 * V_17 = F_37 ( & V_18 -> V_2 ) ;
unsigned long V_47 ;
if ( ! V_17 )
return;
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_110 = 1 ;
F_38 ( V_17 -> V_111 -> V_112 ) ;
F_32 ( V_17 ) ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
F_22 ( V_17 , V_96 ) ;
F_45 ( (struct V_113 * ) V_18 -> V_114 ) ;
}
static int F_46 ( struct V_115 * V_116 , T_1 V_44 )
{
struct V_16 * V_17 = V_116 -> V_46 ;
unsigned long V_47 ;
if ( V_17 -> V_49 == 1 ) {
F_22 ( V_17 , V_96 ) ;
}
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_49 -- ;
F_8 ( & V_17 -> V_48 , V_47 ) ;
return 0 ;
}
static int F_47 ( struct V_16 * V_17 ,
struct V_22 * V_57 )
{
struct V_117 * V_117 = NULL ;
struct V_118 * V_119 = NULL ;
struct V_118 * V_120 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_13 * V_102 ;
int V_121 = 0 ;
int V_122 = 0 ;
T_2 V_123 ;
unsigned long V_124 = 0 ;
int V_6 = 0 ;
int V_125 = 0 ;
struct V_126 * V_109 = NULL ;
V_109 = F_23 ( V_17 -> V_83 , V_127 ) ;
if ( ! V_109 )
return - V_85 ;
F_48 ( & V_109 -> V_128 ) ;
V_109 -> V_129 = V_109 -> V_130 = 0 ;
V_123 = F_49 ( V_57 ) ;
if ( V_57 -> V_117 ) {
for ( V_117 = V_57 -> V_117 ; V_117 ; V_117 = V_117 -> V_131 ) {
F_50 (bvec, bio, seg_idx) {
if ( ( ! V_14 ) ||
( V_121 >= V_132 )
|| ( V_119 -> V_133 != 0 ) ||
( V_120 &&
( V_120 -> V_134 != V_135 ) ) ) {
if ( V_14 ) {
V_14 -> V_62 =
V_123 ;
F_11 (
V_14 -> V_62 ,
( V_17 -> V_93 >> 9 ) ) ;
V_14 -> V_63 =
V_124 /
( V_17 -> V_93 >> 9 ) ;
F_12 ( V_14 ) ;
}
V_14 =
F_23 (
V_17 -> V_83 , V_127 ) ;
if ( ! V_14 ) {
F_33 (
blkvsc_req, tmp,
&group->blkvsc_req_list,
req_entry) {
F_34 (
& V_14 -> V_105 ) ;
F_25 (
V_17 -> V_83 ,
V_14 ) ;
}
F_25 (
V_17 -> V_83 , V_109 ) ;
return - V_85 ;
}
memset ( V_14 , 0 ,
sizeof( struct V_13 ) ) ;
V_14 -> V_18 = V_17 ;
V_14 -> V_57 = V_57 ;
V_14 -> V_22 .
V_86 . V_88
= V_119 -> V_133 ;
V_14 -> V_22 .
V_86 . V_91 = 0 ;
V_14 -> V_109 = V_109 ;
V_14 -> V_109 -> V_129 ++ ;
F_51 ( & V_14 -> V_105 ,
& V_14 -> V_109 -> V_128 ) ;
V_123 += V_124 ;
V_124 = 0 ;
V_121 = 0 ;
}
V_14 -> V_22 . V_86 .
V_87 [ V_121 ]
= F_27 ( V_119 -> V_136 ) ;
V_14 -> V_22 . V_86 . V_91
+= V_119 -> V_134 ;
V_120 = V_119 ;
V_121 ++ ;
V_124 += V_119 -> V_134 >> 9 ;
}
}
}
if ( V_14 ) {
V_14 -> V_62 = V_123 ;
F_11 ( V_14 -> V_62 ,
( V_17 -> V_93 >> 9 ) ) ;
V_14 -> V_63 = V_124 /
( V_17 -> V_93 >> 9 ) ;
F_12 ( V_14 ) ;
}
F_52 (blkvsc_req, &group->blkvsc_req_list, req_entry) {
if ( V_125 ) {
F_51 ( & V_14 -> V_108 ,
& V_17 -> V_137 ) ;
} else {
V_6 = F_3 ( V_14 ,
V_138 ) ;
if ( V_6 == - 1 ) {
V_125 = 1 ;
F_51 ( & V_14 -> V_108 ,
& V_17 -> V_137 ) ;
}
}
}
return V_125 ;
}
static int F_53 ( struct V_16 * V_17 )
{
struct V_13 * V_101 , * V_102 ;
int V_6 = 0 ;
F_33 (pend_req, tmp, &blkdev->pending_list,
pend_entry) {
V_6 = F_3 ( V_101 ,
V_138 ) ;
if ( V_6 != 0 )
break;
else
F_34 ( & V_101 -> V_108 ) ;
}
return V_6 ;
}
static void V_13 ( struct V_139 * V_112 )
{
struct V_16 * V_17 = NULL ;
struct V_22 * V_57 ;
int V_6 = 0 ;
while ( ( V_57 = F_54 ( V_112 ) ) != NULL ) {
V_17 = V_57 -> V_140 -> V_46 ;
if ( V_17 -> V_110 || V_57 -> V_141 != V_142 ) {
F_55 ( V_57 , 0 ) ;
continue;
}
V_6 = F_53 ( V_17 ) ;
if ( V_6 != 0 ) {
F_38 ( V_112 ) ;
break;
}
F_56 ( V_57 ) ;
V_6 = F_47 ( V_17 , V_57 ) ;
if ( V_6 > 0 ) {
F_38 ( V_112 ) ;
break;
} else if ( V_6 < 0 ) {
F_57 ( V_112 , V_57 ) ;
F_38 ( V_112 ) ;
break;
}
}
}
static int F_58 ( void )
{
struct V_143 * V_144 = & V_145 ;
int V_6 ;
F_59 ( sizeof( T_2 ) != 8 ) ;
memcpy ( & V_144 -> V_146 , & V_146 , sizeof( struct V_147 ) ) ;
V_144 -> V_148 = V_149 ;
V_144 -> V_150 . V_148 = V_149 ;
V_6 = F_60 ( & V_144 -> V_150 ) ;
return V_6 ;
}
static void F_61 ( void )
{
F_62 ( & V_145 . V_150 ) ;
}
static int F_63 ( struct V_1 * V_18 )
{
struct V_16 * V_17 = NULL ;
struct V_4 V_5 ;
struct V_151 V_152 ;
int V_6 = 0 ;
V_17 = F_64 ( sizeof( struct V_16 ) , V_84 ) ;
if ( ! V_17 ) {
V_6 = - V_85 ;
goto V_98;
}
F_48 ( & V_17 -> V_137 ) ;
F_65 ( & V_17 -> V_48 ) ;
V_17 -> V_83 = F_66 ( F_67 ( & V_18 -> V_2 ) ,
sizeof( struct V_13 ) , 0 ,
V_153 , NULL ) ;
if ( ! V_17 -> V_83 ) {
V_6 = - V_85 ;
goto V_98;
}
V_6 = F_1 ( V_18 , & V_5 ) ;
if ( V_6 != 0 )
goto V_98;
V_17 -> V_40 = V_18 ;
V_17 -> V_33 = V_5 . V_12 ;
V_17 -> V_32 = V_5 . V_9 ;
F_68 ( & V_18 -> V_2 , V_17 ) ;
V_6 = F_69 ( & V_5 , & V_152 ) ;
if ( V_6 )
goto V_98;
if ( V_152 . V_154 ) {
V_6 = F_70 ( V_152 . V_155 , V_152 . V_156 ) ;
if ( V_6 != 0 ) {
F_71 ( V_157 ,
L_2 , V_6 ) ;
goto remove;
}
}
F_72 ( V_157 , L_3 ,
V_152 . V_155 ) ;
V_17 -> V_111 = F_73 ( V_158 ) ;
if ( ! V_17 -> V_111 ) {
V_6 = - 1 ;
goto V_98;
}
V_17 -> V_111 -> V_112 = F_74 ( V_13 , & V_17 -> V_48 ) ;
F_75 ( V_17 -> V_111 -> V_112 , V_135 ) ;
F_76 ( V_17 -> V_111 -> V_112 , V_132 ) ;
F_77 ( V_17 -> V_111 -> V_112 , V_135 - 1 ) ;
F_78 ( V_17 -> V_111 -> V_112 , V_159 ) ;
F_79 ( V_17 -> V_111 -> V_112 , 511 ) ;
V_17 -> V_111 -> V_155 = V_152 . V_155 ;
if ( V_152 . V_160 == 1 || V_152 . V_160 == 3 )
V_17 -> V_111 -> V_161 = V_158 ;
else
V_17 -> V_111 -> V_161 = 0 ;
V_17 -> V_111 -> V_162 = & V_163 ;
V_17 -> V_111 -> V_164 = V_165 ;
V_17 -> V_111 -> V_46 = V_17 ;
V_17 -> V_111 -> V_166 = & ( V_17 -> V_40 -> V_2 ) ;
sprintf ( V_17 -> V_111 -> V_167 , L_4 , 'a' + V_152 . V_160 ) ;
F_22 ( V_17 , V_89 ) ;
F_22 ( V_17 , V_92 ) ;
F_80 ( V_17 -> V_111 , V_17 -> V_94 * ( V_17 -> V_93 / 512 ) ) ;
F_81 ( V_17 -> V_111 -> V_112 , V_17 -> V_93 ) ;
F_82 ( V_17 -> V_111 ) ;
F_72 ( V_157 , L_5 ,
V_17 -> V_111 -> V_167 , ( unsigned long ) V_17 -> V_94 ,
V_17 -> V_93 ) ;
return V_6 ;
remove:
F_40 ( V_18 ) ;
V_98:
if ( V_17 ) {
if ( V_17 -> V_83 ) {
F_42 ( V_17 -> V_83 ) ;
V_17 -> V_83 = NULL ;
}
F_43 ( V_17 ) ;
V_17 = NULL ;
}
return V_6 ;
}
static void V_138 ( struct V_15 * V_22 )
{
struct V_13 * V_14 =
(struct V_13 * ) V_22 -> V_29 ;
struct V_16 * V_17 =
(struct V_16 * ) V_14 -> V_18 ;
unsigned long V_47 ;
struct V_13 * V_103 , * V_102 ;
struct V_20 * V_21 ;
F_7 ( & V_17 -> V_48 , V_47 ) ;
V_17 -> V_41 -- ;
V_14 -> V_109 -> V_129 -- ;
if ( V_14 -> V_109 -> V_129 == 0 ) {
F_33 (comp_req, tmp,
&blkvsc_req->group->blkvsc_req_list,
req_entry) {
F_34 ( & V_103 -> V_105 ) ;
V_21 =
& V_103 -> V_22 . V_23 . V_21 ;
if ( ! F_35 ( V_103 -> V_57 ,
( ! V_21 -> V_74 ? 0 : - V_106 ) ,
V_103 -> V_63 * V_17 -> V_93 ) ) {
F_25 ( V_17 -> V_83 ,
V_103 -> V_109 ) ;
}
F_25 ( V_17 -> V_83 , V_103 ) ;
}
if ( ! V_17 -> V_110 ) {
F_53 ( V_17 ) ;
F_83 ( V_17 -> V_111 -> V_112 ) ;
V_13 ( V_17 -> V_111 -> V_112 ) ;
}
}
F_8 ( & V_17 -> V_48 , V_47 ) ;
}
static void T_3 F_84 ( void )
{
F_61 () ;
}
