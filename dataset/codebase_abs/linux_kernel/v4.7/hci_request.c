void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_7 ,
T_2 V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
F_4 ( L_1 , F_5 ( & V_2 -> V_5 ) ) ;
if ( V_2 -> V_6 ) {
F_6 ( & V_2 -> V_5 ) ;
return V_2 -> V_6 ;
}
if ( F_7 ( & V_2 -> V_5 ) )
return - V_12 ;
V_10 = F_8 ( & V_2 -> V_5 ) ;
if ( V_7 ) {
F_9 ( V_10 ) -> V_13 . V_14 = V_7 ;
} else if ( V_8 ) {
F_9 ( V_10 ) -> V_13 . V_15 = V_8 ;
F_9 ( V_10 ) -> V_13 . V_16 |= V_17 ;
}
F_10 ( & V_4 -> V_5 . V_18 , V_11 ) ;
F_11 ( & V_2 -> V_5 , & V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_5 . V_18 , V_11 ) ;
F_13 ( V_4 -> V_19 , & V_4 -> V_20 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_7 )
{
return F_3 ( V_2 , V_7 , NULL ) ;
}
int F_15 ( struct V_1 * V_2 , T_2 V_7 )
{
return F_3 ( V_2 , NULL , V_7 ) ;
}
static void F_16 ( struct V_3 * V_4 , T_3 V_21 , T_4 V_22 ,
struct V_9 * V_10 )
{
F_4 ( L_2 , V_4 -> V_23 , V_21 ) ;
if ( V_4 -> V_24 == V_25 ) {
V_4 -> V_26 = V_21 ;
V_4 -> V_24 = V_27 ;
if ( V_10 )
V_4 -> V_28 = F_17 ( V_10 ) ;
F_18 ( & V_4 -> V_29 ) ;
}
}
void F_19 ( struct V_3 * V_4 , int V_6 )
{
F_4 ( L_3 , V_4 -> V_23 , V_6 ) ;
if ( V_4 -> V_24 == V_25 ) {
V_4 -> V_26 = V_6 ;
V_4 -> V_24 = V_30 ;
F_18 ( & V_4 -> V_29 ) ;
}
}
struct V_9 * F_20 ( struct V_3 * V_4 , T_4 V_22 , T_5 V_31 ,
const void * V_32 , T_3 V_33 , T_5 V_34 )
{
F_21 ( V_35 , V_36 ) ;
struct V_1 V_2 ;
struct V_9 * V_10 ;
int V_6 = 0 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_1 ( & V_2 , V_4 ) ;
F_22 ( & V_2 , V_22 , V_31 , V_32 , V_33 ) ;
V_4 -> V_24 = V_25 ;
F_23 ( & V_4 -> V_29 , & V_35 ) ;
F_24 ( V_37 ) ;
V_6 = F_15 ( & V_2 , F_16 ) ;
if ( V_6 < 0 ) {
F_25 ( & V_4 -> V_29 , & V_35 ) ;
F_24 ( V_38 ) ;
return F_26 ( V_6 ) ;
}
F_27 ( V_34 ) ;
F_25 ( & V_4 -> V_29 , & V_35 ) ;
if ( F_28 ( V_36 ) )
return F_26 ( - V_39 ) ;
switch ( V_4 -> V_24 ) {
case V_27 :
V_6 = - F_29 ( V_4 -> V_26 ) ;
break;
case V_30 :
V_6 = - V_4 -> V_26 ;
break;
default:
V_6 = - V_40 ;
break;
}
V_4 -> V_24 = V_4 -> V_26 = 0 ;
V_10 = V_4 -> V_28 ;
V_4 -> V_28 = NULL ;
F_4 ( L_5 , V_4 -> V_23 , V_6 ) ;
if ( V_6 < 0 ) {
F_30 ( V_10 ) ;
return F_26 ( V_6 ) ;
}
if ( ! V_10 )
return F_26 ( - V_12 ) ;
return V_10 ;
}
struct V_9 * F_31 ( struct V_3 * V_4 , T_4 V_22 , T_5 V_31 ,
const void * V_32 , T_5 V_34 )
{
return F_20 ( V_4 , V_22 , V_31 , V_32 , 0 , V_34 ) ;
}
int F_32 ( struct V_3 * V_4 , int (* F_33)( struct V_1 * V_2 ,
unsigned long V_41 ) ,
unsigned long V_41 , T_5 V_34 , T_3 * V_42 )
{
struct V_1 V_2 ;
F_21 ( V_35 , V_36 ) ;
int V_6 = 0 ;
F_4 ( L_6 , V_4 -> V_23 ) ;
F_1 ( & V_2 , V_4 ) ;
V_4 -> V_24 = V_25 ;
V_6 = F_33 ( & V_2 , V_41 ) ;
if ( V_6 ) {
if ( V_42 )
* V_42 = V_43 ;
return V_6 ;
}
F_23 ( & V_4 -> V_29 , & V_35 ) ;
F_24 ( V_37 ) ;
V_6 = F_15 ( & V_2 , F_16 ) ;
if ( V_6 < 0 ) {
V_4 -> V_24 = 0 ;
F_25 ( & V_4 -> V_29 , & V_35 ) ;
F_24 ( V_38 ) ;
if ( V_6 == - V_12 ) {
if ( V_42 )
* V_42 = 0 ;
return 0 ;
}
if ( V_42 )
* V_42 = V_43 ;
return V_6 ;
}
F_27 ( V_34 ) ;
F_25 ( & V_4 -> V_29 , & V_35 ) ;
if ( F_28 ( V_36 ) )
return - V_39 ;
switch ( V_4 -> V_24 ) {
case V_27 :
V_6 = - F_29 ( V_4 -> V_26 ) ;
if ( V_42 )
* V_42 = V_4 -> V_26 ;
break;
case V_30 :
V_6 = - V_4 -> V_26 ;
if ( V_42 )
* V_42 = V_43 ;
break;
default:
V_6 = - V_40 ;
if ( V_42 )
* V_42 = V_43 ;
break;
}
V_4 -> V_24 = V_4 -> V_26 = 0 ;
F_4 ( L_5 , V_4 -> V_23 , V_6 ) ;
return V_6 ;
}
int F_34 ( struct V_3 * V_4 , int (* V_2)( struct V_1 * V_2 ,
unsigned long V_41 ) ,
unsigned long V_41 , T_5 V_34 , T_3 * V_42 )
{
int V_44 ;
if ( ! F_35 ( V_45 , & V_4 -> V_11 ) )
return - V_46 ;
F_36 ( V_4 ) ;
V_44 = F_32 ( V_4 , V_2 , V_41 , V_34 , V_42 ) ;
F_37 ( V_4 ) ;
return V_44 ;
}
struct V_9 * F_38 ( struct V_3 * V_4 , T_4 V_22 , T_5 V_31 ,
const void * V_32 )
{
int V_47 = V_48 + V_31 ;
struct V_49 * V_50 ;
struct V_9 * V_10 ;
V_10 = F_39 ( V_47 , V_51 ) ;
if ( ! V_10 )
return NULL ;
V_50 = (struct V_49 * ) F_40 ( V_10 , V_48 ) ;
V_50 -> V_22 = F_41 ( V_22 ) ;
V_50 -> V_31 = V_31 ;
if ( V_31 )
memcpy ( F_40 ( V_10 , V_31 ) , V_32 , V_31 ) ;
F_4 ( L_7 , V_10 -> V_47 ) ;
F_42 ( V_10 ) = V_52 ;
F_43 ( V_10 ) = V_22 ;
return V_10 ;
}
void F_22 ( struct V_1 * V_2 , T_4 V_22 , T_5 V_31 ,
const void * V_32 , T_3 V_33 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
F_4 ( L_8 , V_4 -> V_23 , V_22 , V_31 ) ;
if ( V_2 -> V_6 )
return;
V_10 = F_38 ( V_4 , V_22 , V_31 , V_32 ) ;
if ( ! V_10 ) {
F_44 ( L_9 ,
V_4 -> V_23 , V_22 ) ;
V_2 -> V_6 = - V_53 ;
return;
}
if ( F_7 ( & V_2 -> V_5 ) )
F_9 ( V_10 ) -> V_13 . V_16 |= V_54 ;
F_9 ( V_10 ) -> V_13 . V_55 = V_33 ;
F_45 ( & V_2 -> V_5 , V_10 ) ;
}
void F_46 ( struct V_1 * V_2 , T_4 V_22 , T_5 V_31 ,
const void * V_32 )
{
F_22 ( V_2 , V_22 , V_31 , V_32 , 0 ) ;
}
void F_47 ( struct V_1 * V_2 , bool V_56 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 V_58 ;
T_3 type ;
if ( ! F_48 ( V_4 , V_59 ) )
return;
if ( V_4 -> V_60 < V_61 )
return;
if ( V_56 ) {
type = V_62 ;
V_58 . V_63 = F_41 ( 0x0100 ) ;
} else {
type = V_64 ;
V_58 . V_63 = F_41 ( 0x0800 ) ;
}
V_58 . V_65 = F_41 ( 0x0012 ) ;
if ( F_49 ( V_4 -> V_66 ) != V_58 . V_63 ||
F_49 ( V_4 -> V_67 ) != V_58 . V_65 )
F_46 ( V_2 , V_68 ,
sizeof( V_58 ) , & V_58 ) ;
if ( V_4 -> V_69 != type )
F_46 ( V_2 , V_70 , 1 , & type ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_35 ( V_45 , & V_4 -> V_11 ) ||
F_35 ( V_71 , & V_4 -> V_11 ) ||
F_48 ( V_4 , V_72 ) ||
F_48 ( V_4 , V_73 ) ||
F_48 ( V_4 , V_74 ) ||
F_48 ( V_4 , V_75 ) )
return;
if ( ! F_48 ( V_4 , V_76 ) )
return;
if ( V_4 -> V_77 . V_78 != V_79 )
return;
F_51 ( V_4 ) ;
if ( F_52 ( & V_4 -> V_80 ) &&
F_52 ( & V_4 -> V_81 ) ) {
if ( ! F_48 ( V_4 , V_82 ) )
return;
F_53 ( V_2 ) ;
F_4 ( L_10 , V_4 -> V_23 ) ;
} else {
if ( F_54 ( V_4 ) )
return;
if ( F_48 ( V_4 , V_82 ) )
F_53 ( V_2 ) ;
F_55 ( V_2 ) ;
F_4 ( L_11 , V_4 -> V_23 ) ;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_83 V_84 ;
memcpy ( V_84 . V_23 , V_4 -> V_85 , sizeof( V_84 . V_23 ) ) ;
F_46 ( V_2 , V_86 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 * F_57 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 4 )
return V_88 ;
F_58 (uuid, &hdev->uuids, list) {
T_4 V_92 ;
if ( V_91 -> V_93 != 16 )
continue;
V_92 = F_59 ( & V_91 -> V_91 [ 12 ] ) ;
if ( V_92 < 0x1100 )
continue;
if ( V_92 == V_94 )
continue;
if ( ! V_89 ) {
V_89 = V_88 ;
V_89 [ 0 ] = 1 ;
V_89 [ 1 ] = V_95 ;
V_88 += 2 ;
}
if ( ( V_88 - V_87 ) + sizeof( T_4 ) > V_47 ) {
V_89 [ 1 ] = V_96 ;
break;
}
* V_88 ++ = ( V_92 & 0x00ff ) ;
* V_88 ++ = ( V_92 & 0xff00 ) >> 8 ;
V_89 [ 0 ] += sizeof( V_92 ) ;
}
return V_88 ;
}
static T_3 * F_60 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 6 )
return V_88 ;
F_58 (uuid, &hdev->uuids, list) {
if ( V_91 -> V_93 != 32 )
continue;
if ( ! V_89 ) {
V_89 = V_88 ;
V_89 [ 0 ] = 1 ;
V_89 [ 1 ] = V_97 ;
V_88 += 2 ;
}
if ( ( V_88 - V_87 ) + sizeof( T_5 ) > V_47 ) {
V_89 [ 1 ] = V_98 ;
break;
}
memcpy ( V_88 , & V_91 -> V_91 [ 12 ] , sizeof( T_5 ) ) ;
V_88 += sizeof( T_5 ) ;
V_89 [ 0 ] += sizeof( T_5 ) ;
}
return V_88 ;
}
static T_3 * F_61 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 18 )
return V_88 ;
F_58 (uuid, &hdev->uuids, list) {
if ( V_91 -> V_93 != 128 )
continue;
if ( ! V_89 ) {
V_89 = V_88 ;
V_89 [ 0 ] = 1 ;
V_89 [ 1 ] = V_99 ;
V_88 += 2 ;
}
if ( ( V_88 - V_87 ) + 16 > V_47 ) {
V_89 [ 1 ] = V_100 ;
break;
}
memcpy ( V_88 , V_91 -> V_91 , 16 ) ;
V_88 += 16 ;
V_89 [ 0 ] += 16 ;
}
return V_88 ;
}
static void F_62 ( struct V_3 * V_4 , T_3 * V_87 )
{
T_3 * V_88 = V_87 ;
T_7 V_101 ;
V_101 = strlen ( V_4 -> V_85 ) ;
if ( V_101 > 0 ) {
if ( V_101 > 48 ) {
V_101 = 48 ;
V_88 [ 1 ] = V_102 ;
} else
V_88 [ 1 ] = V_103 ;
V_88 [ 0 ] = V_101 + 1 ;
memcpy ( V_88 + 2 , V_4 -> V_85 , V_101 ) ;
V_88 += ( V_101 + 2 ) ;
}
if ( V_4 -> V_104 != V_105 ) {
V_88 [ 0 ] = 2 ;
V_88 [ 1 ] = V_106 ;
V_88 [ 2 ] = ( T_3 ) V_4 -> V_104 ;
V_88 += 3 ;
}
if ( V_4 -> V_107 > 0 ) {
V_88 [ 0 ] = 9 ;
V_88 [ 1 ] = V_108 ;
F_63 ( V_4 -> V_107 , V_88 + 2 ) ;
F_63 ( V_4 -> V_109 , V_88 + 4 ) ;
F_63 ( V_4 -> V_110 , V_88 + 6 ) ;
F_63 ( V_4 -> V_111 , V_88 + 8 ) ;
V_88 += 10 ;
}
V_88 = F_57 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
V_88 = F_60 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
V_88 = F_61 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_113 V_84 ;
if ( ! F_65 ( V_4 ) )
return;
if ( ! F_66 ( V_4 ) )
return;
if ( ! F_48 ( V_4 , V_114 ) )
return;
if ( F_48 ( V_4 , V_115 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_62 ( V_4 , V_84 . V_87 ) ;
if ( memcmp ( V_84 . V_87 , V_4 -> V_116 , sizeof( V_84 . V_87 ) ) == 0 )
return;
memcpy ( V_4 -> V_116 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
F_46 ( V_2 , V_117 , sizeof( V_84 ) , & V_84 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_118 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_56 = V_119 ;
F_46 ( V_2 , V_120 , sizeof( V_84 ) , & V_84 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_123 V_84 ;
V_84 . V_124 = V_122 -> V_125 ;
F_68 ( & V_84 . V_126 , & V_122 -> V_127 ) ;
F_46 ( V_2 , V_128 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_121 * V_122 ;
struct V_129 * V_130 ;
T_8 V_131 = 0 ;
F_58 (b, &hdev->le_white_list, list) {
if ( ! F_70 ( & V_4 -> V_80 ,
& V_130 -> V_126 , V_130 -> V_124 ) &&
! F_70 ( & V_4 -> V_81 ,
& V_130 -> V_126 , V_130 -> V_124 ) ) {
struct V_132 V_84 ;
V_84 . V_124 = V_130 -> V_124 ;
F_68 ( & V_84 . V_126 , & V_130 -> V_126 ) ;
F_46 ( V_2 , V_133 ,
sizeof( V_84 ) , & V_84 ) ;
continue;
}
if ( F_71 ( V_4 , & V_130 -> V_126 , V_130 -> V_124 ) ) {
return 0x00 ;
}
V_131 ++ ;
}
F_58 (params, &hdev->pend_le_conns, action) {
if ( F_72 ( & V_4 -> V_134 ,
& V_122 -> V_127 , V_122 -> V_125 ) )
continue;
if ( V_131 >= V_4 -> V_135 ) {
return 0x00 ;
}
if ( F_71 ( V_4 , & V_122 -> V_127 ,
V_122 -> V_125 ) ) {
return 0x00 ;
}
V_131 ++ ;
F_67 ( V_2 , V_122 ) ;
}
F_58 (params, &hdev->pend_le_reports, action) {
if ( F_72 ( & V_4 -> V_134 ,
& V_122 -> V_127 , V_122 -> V_125 ) )
continue;
if ( V_131 >= V_4 -> V_135 ) {
return 0x00 ;
}
if ( F_71 ( V_4 , & V_122 -> V_127 ,
V_122 -> V_125 ) ) {
return 0x00 ;
}
V_131 ++ ;
F_67 ( V_2 , V_122 ) ;
}
return 0x01 ;
}
static bool F_73 ( struct V_3 * V_4 )
{
return F_48 ( V_4 , V_136 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_137 V_138 ;
struct V_118 V_139 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_140 ;
T_3 V_141 ;
if ( F_74 ( V_2 , false , F_73 ( V_4 ) ,
& V_140 ) )
return;
V_141 = F_69 ( V_2 ) ;
if ( F_48 ( V_4 , V_136 ) &&
( V_4 -> V_142 [ 0 ] & V_143 ) )
V_141 |= 0x02 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . type = V_144 ;
V_138 . V_63 = F_41 ( V_4 -> V_145 ) ;
V_138 . V_65 = F_41 ( V_4 -> V_146 ) ;
V_138 . V_147 = V_140 ;
V_138 . V_141 = V_141 ;
F_46 ( V_2 , V_148 , sizeof( V_138 ) ,
& V_138 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_56 = V_149 ;
V_139 . V_150 = V_151 ;
F_46 ( V_2 , V_120 , sizeof( V_139 ) ,
& V_139 ) ;
}
static T_3 F_75 ( struct V_3 * V_4 )
{
T_3 V_152 = V_4 -> V_153 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 )
return 0 ;
V_155 = F_76 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_156 ;
}
void F_77 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static T_5 F_78 ( struct V_3 * V_4 , T_3 V_152 )
{
T_5 V_11 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 ) {
V_11 = V_158 | V_159 ;
if ( F_48 ( V_4 , V_160 ) )
V_11 |= V_161 ;
if ( F_48 ( V_4 , V_162 ) )
V_11 |= V_163 ;
else if ( F_48 ( V_4 , V_164 ) )
V_11 |= V_165 ;
return V_11 ;
}
V_155 = F_76 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_11 ;
}
static bool F_79 ( struct V_3 * V_4 , T_9 V_11 )
{
if ( ! F_48 ( V_4 , V_136 ) )
return false ;
if ( ! F_48 ( V_4 , V_166 ) )
return true ;
if ( ( V_11 & V_165 ) &&
F_48 ( V_4 , V_167 ) )
return false ;
return true ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_168 V_84 ;
T_3 V_140 , V_56 = 0x01 ;
bool V_169 ;
T_5 V_11 ;
if ( F_81 ( V_4 , V_170 ) > 0 )
return;
if ( F_48 ( V_4 , V_171 ) )
F_77 ( V_2 ) ;
F_82 ( V_4 , V_171 ) ;
V_11 = F_78 ( V_4 , V_4 -> V_153 ) ;
V_169 = ( V_11 & V_161 ) ||
F_83 ( V_4 ) ;
if ( F_74 ( V_2 , ! V_169 ,
F_79 ( V_4 , V_11 ) ,
& V_140 ) < 0 )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_172 = F_41 ( V_4 -> V_173 ) ;
V_84 . V_174 = F_41 ( V_4 -> V_175 ) ;
if ( V_169 )
V_84 . type = V_176 ;
else if ( F_75 ( V_4 ) )
V_84 . type = V_177 ;
else
V_84 . type = V_178 ;
V_84 . V_147 = V_140 ;
V_84 . V_179 = V_4 -> V_180 ;
F_46 ( V_2 , V_181 , sizeof( V_84 ) , & V_84 ) ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static T_3 F_84 ( struct V_3 * V_4 , T_3 * V_88 )
{
T_3 V_182 = 0 ;
T_7 V_101 ;
V_101 = strlen ( V_4 -> V_85 ) ;
if ( V_101 > 0 ) {
T_7 V_183 = V_184 - V_182 - 2 ;
if ( V_101 > V_183 ) {
V_101 = V_183 ;
V_88 [ 1 ] = V_102 ;
} else
V_88 [ 1 ] = V_103 ;
V_88 [ 0 ] = V_101 + 1 ;
memcpy ( V_88 + 2 , V_4 -> V_85 , V_101 ) ;
V_182 += ( V_101 + 2 ) ;
V_88 += ( V_101 + 2 ) ;
}
return V_182 ;
}
static T_3 F_85 ( struct V_3 * V_4 , T_3 V_152 ,
T_3 * V_88 )
{
struct V_154 * V_155 ;
V_155 = F_76 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
memcpy ( V_88 , V_155 -> V_185 ,
V_155 -> V_156 ) ;
return V_155 -> V_156 ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_186 V_84 ;
T_3 V_47 ;
if ( ! F_48 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_152 )
V_47 = F_85 ( V_4 , V_152 , V_84 . V_87 ) ;
else
V_47 = F_84 ( V_4 , V_84 . V_87 ) ;
if ( V_4 -> V_187 == V_47 &&
! memcmp ( V_84 . V_87 , V_4 -> V_185 , V_47 ) )
return;
memcpy ( V_4 -> V_185 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_187 = V_47 ;
V_84 . V_188 = V_47 ;
F_46 ( V_2 , V_189 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 F_87 ( struct V_3 * V_4 , T_3 V_152 , T_3 * V_88 )
{
struct V_154 * V_155 = NULL ;
T_3 V_182 = 0 , V_11 = 0 ;
T_5 V_190 ;
if ( V_152 ) {
V_155 = F_76 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
}
V_190 = F_78 ( V_4 , V_152 ) ;
if ( V_190 & V_165 )
V_11 |= V_191 ;
if ( V_190 & V_163 )
V_11 |= V_192 ;
if ( ! F_48 ( V_4 , V_59 ) )
V_11 |= V_193 ;
if ( V_11 || ( V_190 & V_159 ) ) {
if ( ! V_11 )
V_11 |= F_88 ( V_4 ) ;
if ( V_11 ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_194 ;
V_88 [ 2 ] = V_11 ;
V_182 += 3 ;
V_88 += 3 ;
}
}
if ( V_155 ) {
memcpy ( V_88 , V_155 -> V_195 ,
V_155 -> V_196 ) ;
V_182 += V_155 -> V_196 ;
V_88 += V_155 -> V_196 ;
}
if ( V_4 -> V_197 != V_105 &&
( V_190 & V_158 ) ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_106 ;
V_88 [ 2 ] = ( T_3 ) V_4 -> V_197 ;
V_182 += 3 ;
V_88 += 3 ;
}
return V_182 ;
}
void F_89 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_198 V_84 ;
T_3 V_47 ;
if ( ! F_48 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_47 = F_87 ( V_4 , V_152 , V_84 . V_87 ) ;
if ( V_4 -> V_196 == V_47 &&
memcmp ( V_84 . V_87 , V_4 -> V_195 , V_47 ) == 0 )
return;
memcpy ( V_4 -> V_195 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_196 = V_47 ;
V_84 . V_188 = V_47 ;
F_46 ( V_2 , V_199 , sizeof( V_84 ) , & V_84 ) ;
}
int F_90 ( struct V_3 * V_4 , T_3 V_152 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_89 ( & V_2 , V_152 ) ;
return F_14 ( & V_2 , NULL ) ;
}
static void F_91 ( struct V_3 * V_4 , T_3 V_200 , T_4 V_22 )
{
F_4 ( L_12 , V_4 -> V_23 , V_200 ) ;
}
void F_92 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
if ( ! F_48 ( V_4 , V_201 ) &&
F_52 ( & V_4 -> V_202 ) )
return;
F_1 ( & V_2 , V_4 ) ;
if ( V_4 -> V_153 ) {
F_93 ( & V_2 , V_4 -> V_153 ,
true ) ;
} else {
F_89 ( & V_2 , 0x00 ) ;
F_86 ( & V_2 , 0x00 ) ;
F_80 ( & V_2 ) ;
}
F_14 ( & V_2 , F_91 ) ;
}
static void F_94 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
V_205 . V_204 ) ;
struct V_1 V_2 ;
T_3 V_152 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_96 ( V_4 ) ;
V_4 -> V_206 = 0 ;
V_152 = V_4 -> V_153 ;
if ( V_152 == 0x00 )
goto V_207;
F_1 ( & V_2 , V_4 ) ;
F_97 ( V_4 , & V_2 , V_152 , false ) ;
if ( F_52 ( & V_4 -> V_202 ) )
F_77 ( & V_2 ) ;
F_14 ( & V_2 , NULL ) ;
V_207:
F_98 ( V_4 ) ;
}
int F_93 ( struct V_1 * V_2 , T_3 V_152 ,
bool V_208 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_154 * V_155 = NULL ;
T_4 V_34 ;
if ( F_48 ( V_4 , V_201 ) ||
F_52 ( & V_4 -> V_202 ) )
return - V_209 ;
if ( V_4 -> V_206 )
return - V_210 ;
V_155 = F_76 ( V_4 , V_152 ) ;
if ( ! V_155 )
return - V_211 ;
if ( V_155 -> V_34 == 0 ||
V_155 -> V_212 <= V_155 -> V_213 )
V_34 = V_155 -> V_212 ;
else
V_34 = V_155 -> V_213 ;
if ( V_155 -> V_34 )
V_155 -> V_213 =
V_155 -> V_213 - V_34 ;
V_4 -> V_206 = V_34 ;
F_99 ( V_4 -> V_214 ,
& V_4 -> V_205 ,
F_100 ( V_34 * 1000 ) ) ;
if ( ! V_208 && V_4 -> V_153 == V_152 &&
F_48 ( V_4 , V_171 ) )
return 0 ;
V_4 -> V_153 = V_152 ;
F_89 ( V_2 , V_152 ) ;
F_86 ( V_2 , V_152 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static void F_101 ( struct V_3 * V_4 )
{
if ( V_4 -> V_206 ) {
V_4 -> V_206 = 0 ;
F_102 ( & V_4 -> V_205 ) ;
}
}
void F_97 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_3 V_152 , bool V_208 )
{
struct V_154 * V_155 , * V_215 , * V_216 = NULL ;
int V_6 ;
T_3 V_217 ;
if ( ! V_152 || V_4 -> V_153 == V_152 )
F_101 ( V_4 ) ;
if ( V_152 && V_4 -> V_153 == V_152 )
V_216 = F_103 ( V_4 , V_152 ) ;
if ( V_152 == 0x00 ) {
F_104 (adv_instance, n, &hdev->adv_instances,
list) {
if ( ! ( V_208 || V_155 -> V_34 ) )
continue;
V_217 = V_155 -> V_152 ;
V_6 = F_105 ( V_4 , V_217 ) ;
if ( ! V_6 )
F_106 ( NULL , V_4 , V_217 ) ;
}
} else {
V_155 = F_76 ( V_4 , V_152 ) ;
if ( V_208 || ( V_155 && V_155 -> V_34 &&
! V_155 -> V_213 ) ) {
if ( V_216 &&
V_216 -> V_152 == V_152 )
V_216 = NULL ;
V_6 = F_105 ( V_4 , V_152 ) ;
if ( ! V_6 )
F_106 ( NULL , V_4 , V_152 ) ;
}
}
if ( ! V_2 || ! F_65 ( V_4 ) ||
F_48 ( V_4 , V_201 ) )
return;
if ( V_216 )
F_93 ( V_2 , V_216 -> V_152 ,
false ) ;
}
static void F_107 ( struct V_1 * V_2 , T_10 * V_218 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_48 ( V_4 , V_171 ) ||
F_54 ( V_4 ) ) {
F_4 ( L_13 ) ;
F_108 ( V_4 , V_219 ) ;
return;
}
F_46 ( V_2 , V_220 , 6 , V_218 ) ;
}
int F_74 ( struct V_1 * V_2 , bool V_221 ,
bool V_222 , T_3 * V_140 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( V_222 ) {
int V_223 ;
* V_140 = V_224 ;
if ( ! F_109 ( V_4 , V_219 ) &&
! F_110 ( & V_4 -> V_225 , & V_4 -> V_218 ) )
return 0 ;
V_6 = F_111 ( V_4 , V_4 -> V_226 , & V_4 -> V_218 ) ;
if ( V_6 < 0 ) {
F_44 ( L_14 , V_4 -> V_23 ) ;
return V_6 ;
}
F_107 ( V_2 , & V_4 -> V_218 ) ;
V_223 = F_100 ( V_4 -> V_227 * 1000 ) ;
F_99 ( V_4 -> V_19 , & V_4 -> V_228 , V_223 ) ;
return 0 ;
}
if ( V_221 ) {
T_10 V_229 ;
while ( true ) {
F_112 ( & V_229 , 6 ) ;
V_229 . V_130 [ 5 ] &= 0x3f ;
if ( F_110 ( & V_4 -> V_126 , & V_229 ) )
break;
}
* V_140 = V_224 ;
F_107 ( V_2 , & V_229 ) ;
return 0 ;
}
if ( F_48 ( V_4 , V_230 ) ||
! F_110 ( & V_4 -> V_126 , V_231 ) ||
( ! F_48 ( V_4 , V_59 ) &&
F_110 ( & V_4 -> V_232 , V_231 ) ) ) {
* V_140 = V_224 ;
if ( F_110 ( & V_4 -> V_232 , & V_4 -> V_225 ) )
F_46 ( V_2 , V_220 , 6 ,
& V_4 -> V_232 ) ;
return 0 ;
}
* V_140 = V_233 ;
return 0 ;
}
static bool F_113 ( struct V_3 * V_4 )
{
struct V_129 * V_130 ;
F_58 (b, &hdev->whitelist, list) {
struct V_234 * V_235 ;
V_235 = F_114 ( V_4 , V_236 , & V_130 -> V_126 ) ;
if ( ! V_235 )
return true ;
if ( V_235 -> V_78 != V_237 && V_235 -> V_78 != V_238 )
return true ;
}
return false ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_239 ;
if ( ! F_48 ( V_4 , V_59 ) )
return;
if ( ! F_65 ( V_4 ) )
return;
if ( F_116 ( V_4 ) )
return;
if ( F_48 ( V_4 , V_240 ) ||
F_113 ( V_4 ) )
V_239 = V_241 ;
else
V_239 = V_242 ;
if ( F_48 ( V_4 , V_164 ) )
V_239 |= V_243 ;
if ( F_35 ( V_244 , & V_4 -> V_11 ) == ! ! ( V_239 & V_241 ) &&
F_35 ( V_245 , & V_4 -> V_11 ) == ! ! ( V_239 & V_243 ) )
return;
F_46 ( V_2 , V_246 , 1 , & V_239 ) ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_96 ( V_2 -> V_4 ) ;
F_115 ( V_2 ) ;
F_98 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_118 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 , V_247 ) ;
F_34 ( V_4 , F_117 , 0 , V_248 , NULL ) ;
}
static int F_119 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_96 ( V_4 ) ;
F_115 ( V_2 ) ;
if ( ! F_48 ( V_4 , V_59 ) )
F_89 ( V_2 , V_4 -> V_153 ) ;
if ( F_48 ( V_4 , V_201 ) ||
! F_52 ( & V_4 -> V_202 ) )
F_80 ( V_2 ) ;
F_50 ( V_2 ) ;
F_98 ( V_4 ) ;
return 0 ;
}
static void F_120 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_119 ) ;
T_3 V_200 ;
F_34 ( V_4 , F_119 , 0 , V_248 , & V_200 ) ;
F_121 ( V_4 , V_200 ) ;
}
static T_3 F_122 ( struct V_3 * V_4 )
{
struct V_90 * V_91 ;
T_3 V_249 = 0 ;
F_58 (uuid, &hdev->uuids, list)
V_249 |= V_91 -> V_250 ;
return V_249 ;
}
void F_123 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_251 [ 3 ] ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_65 ( V_4 ) )
return;
if ( ! F_48 ( V_4 , V_59 ) )
return;
if ( F_48 ( V_4 , V_115 ) )
return;
V_251 [ 0 ] = V_4 -> V_252 ;
V_251 [ 1 ] = V_4 -> V_253 ;
V_251 [ 2 ] = F_122 ( V_4 ) ;
if ( F_48 ( V_4 , V_162 ) )
V_251 [ 1 ] |= 0x20 ;
if ( memcmp ( V_251 , V_4 -> V_254 , 3 ) == 0 )
return;
F_46 ( V_2 , V_255 , sizeof( V_251 ) , V_251 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_256 V_84 ;
if ( ! F_48 ( V_4 , V_164 ) )
return;
if ( F_48 ( V_4 , V_162 ) ) {
V_84 . V_257 = F_125 ( T_3 , V_4 -> V_257 , 2 ) ;
V_84 . V_258 [ 0 ] = 0x00 ;
V_84 . V_258 [ 1 ] = 0x8b ;
V_84 . V_258 [ 2 ] = 0x9e ;
V_84 . V_258 [ 3 ] = 0x33 ;
V_84 . V_258 [ 4 ] = 0x8b ;
V_84 . V_258 [ 5 ] = 0x9e ;
} else {
V_84 . V_257 = 1 ;
V_84 . V_258 [ 0 ] = 0x33 ;
V_84 . V_258 [ 1 ] = 0x8b ;
V_84 . V_258 [ 2 ] = 0x9e ;
}
F_46 ( V_2 , V_259 ,
( V_84 . V_257 * 3 ) + 1 , & V_84 ) ;
}
static int F_126 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_96 ( V_4 ) ;
if ( F_48 ( V_4 , V_59 ) ) {
F_124 ( V_2 ) ;
F_115 ( V_2 ) ;
F_123 ( V_2 ) ;
}
if ( F_48 ( V_4 , V_201 ) ) {
F_89 ( V_2 , 0x00 ) ;
if ( F_48 ( V_4 , V_166 ) )
F_80 ( V_2 ) ;
}
F_98 ( V_4 ) ;
return 0 ;
}
static void F_127 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_126 ) ;
T_3 V_200 ;
F_34 ( V_4 , F_126 , 0 , V_248 , & V_200 ) ;
F_128 ( V_4 , V_200 ) ;
}
void F_129 ( struct V_1 * V_2 , struct V_234 * V_235 ,
T_3 V_260 )
{
switch ( V_235 -> V_78 ) {
case V_237 :
case V_238 :
if ( V_235 -> type == V_261 ) {
struct V_262 V_84 ;
V_84 . V_263 = F_130 ( V_235 -> V_264 ) ;
V_84 . V_260 = V_260 ;
F_46 ( V_2 , V_265 , sizeof( V_84 ) ,
& V_84 ) ;
} else {
struct V_266 V_267 ;
V_267 . V_264 = F_41 ( V_235 -> V_264 ) ;
V_267 . V_260 = V_260 ;
F_46 ( V_2 , V_268 , sizeof( V_267 ) , & V_267 ) ;
}
V_235 -> V_78 = V_269 ;
break;
case V_270 :
if ( V_235 -> type == V_170 ) {
if ( F_35 ( V_271 , & V_235 -> V_11 ) )
break;
F_46 ( V_2 , V_272 ,
0 , NULL ) ;
} else if ( V_235 -> type == V_236 ) {
if ( V_2 -> V_4 -> V_60 < V_61 )
break;
F_46 ( V_2 , V_273 ,
6 , & V_235 -> V_274 ) ;
}
break;
case V_275 :
if ( V_235 -> type == V_236 ) {
struct V_276 V_277 ;
F_68 ( & V_277 . V_126 , & V_235 -> V_274 ) ;
V_277 . V_260 = V_260 ;
F_46 ( V_2 , V_278 ,
sizeof( V_277 ) , & V_277 ) ;
} else if ( V_235 -> type == V_279 || V_235 -> type == V_280 ) {
struct V_281 V_277 ;
F_68 ( & V_277 . V_126 , & V_235 -> V_274 ) ;
V_277 . V_260 = V_282 ;
F_46 ( V_2 , V_283 ,
sizeof( V_277 ) , & V_277 ) ;
}
break;
default:
V_235 -> V_78 = V_284 ;
break;
}
}
static void F_131 ( struct V_3 * V_4 , T_3 V_200 , T_4 V_22 )
{
if ( V_200 )
F_4 ( L_15 , V_200 ) ;
}
int F_132 ( struct V_234 * V_235 , T_3 V_260 )
{
struct V_1 V_2 ;
int V_6 ;
F_1 ( & V_2 , V_235 -> V_4 ) ;
F_129 ( & V_2 , V_235 , V_260 ) ;
V_6 = F_14 ( & V_2 , F_131 ) ;
if ( V_6 && V_6 != - V_12 ) {
F_44 ( L_16 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_96 ( V_2 -> V_4 ) ;
F_50 ( V_2 ) ;
F_98 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_134 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_134 ) ;
struct V_234 * V_235 ;
T_3 V_200 ;
int V_6 ;
V_6 = F_34 ( V_4 , F_133 , 0 , V_248 , & V_200 ) ;
if ( ! V_6 )
return;
F_96 ( V_4 ) ;
V_235 = F_135 ( V_4 , V_170 , V_270 ) ;
if ( V_235 )
F_136 ( V_235 , V_200 ) ;
F_98 ( V_4 ) ;
}
static int F_137 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_53 ( V_2 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_3 V_188 = V_41 ;
const T_3 V_285 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
const T_3 V_286 [ 3 ] = { 0x00 , 0x8b , 0x9e } ;
struct V_287 V_84 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
F_96 ( V_2 -> V_4 ) ;
F_139 ( V_2 -> V_4 ) ;
F_98 ( V_2 -> V_4 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_2 -> V_4 -> V_77 . V_288 )
memcpy ( & V_84 . V_289 , V_286 , sizeof( V_84 . V_289 ) ) ;
else
memcpy ( & V_84 . V_289 , V_285 , sizeof( V_84 . V_289 ) ) ;
V_84 . V_188 = V_188 ;
F_46 ( V_2 , V_290 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
static void F_140 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_137 . V_204 ) ;
T_3 V_200 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_48 ( V_4 , V_82 ) )
return;
F_102 ( & V_4 -> V_291 ) ;
F_34 ( V_4 , F_137 , 0 , V_248 , & V_200 ) ;
if ( V_200 ) {
F_44 ( L_17 , V_200 ) ;
return;
}
V_4 -> V_77 . V_292 = 0 ;
if ( V_4 -> V_77 . type == V_293 )
goto V_294;
if ( V_4 -> V_77 . type != V_295 )
return;
if ( F_35 ( V_296 , & V_4 -> V_297 ) ) {
if ( ! F_35 ( V_298 , & V_4 -> V_11 ) &&
V_4 -> V_77 . V_78 != V_299 )
goto V_294;
return;
}
F_34 ( V_4 , F_138 , V_300 ,
V_248 , & V_200 ) ;
if ( V_200 ) {
F_44 ( L_18 , V_200 ) ;
goto V_294;
}
return;
V_294:
F_96 ( V_4 ) ;
F_141 ( V_4 , V_79 ) ;
F_98 ( V_4 ) ;
}
static int V_291 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_118 V_84 ;
if ( ! F_48 ( V_4 , V_82 ) )
return 0 ;
F_53 ( V_2 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_56 = V_149 ;
V_84 . V_150 = V_151 ;
F_46 ( V_2 , V_120 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
static void F_142 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
V_291 . V_204 ) ;
unsigned long V_34 , V_212 , V_292 , V_301 ;
T_3 V_200 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_34 ( V_4 , V_291 , 0 , V_248 , & V_200 ) ;
if ( V_200 ) {
F_44 ( L_19 , V_200 ) ;
return;
}
F_96 ( V_4 ) ;
if ( ! F_35 ( V_302 , & V_4 -> V_297 ) ||
! V_4 -> V_77 . V_292 )
goto V_207;
V_212 = V_4 -> V_77 . V_303 ;
V_292 = V_4 -> V_77 . V_292 ;
V_301 = V_304 ;
if ( V_301 - V_292 <= V_212 ) {
int V_305 ;
if ( V_301 >= V_292 )
V_305 = V_301 - V_292 ;
else
V_305 = V_306 - V_292 + V_301 ;
V_34 = V_212 - V_305 ;
} else {
V_34 = 0 ;
}
F_99 ( V_4 -> V_214 ,
& V_4 -> F_137 , V_34 ) ;
V_207:
F_98 ( V_4 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static int F_144 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_11 V_63 = V_41 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_137 V_138 ;
struct V_118 V_139 ;
T_3 V_140 ;
int V_6 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( F_48 ( V_4 , V_171 ) ) {
F_96 ( V_4 ) ;
if ( F_54 ( V_4 ) ) {
F_98 ( V_4 ) ;
return - V_210 ;
}
F_101 ( V_4 ) ;
F_98 ( V_4 ) ;
F_143 ( V_2 ) ;
}
if ( F_48 ( V_4 , V_82 ) )
F_53 ( V_2 ) ;
V_6 = F_74 ( V_2 , true , F_73 ( V_4 ) ,
& V_140 ) ;
if ( V_6 < 0 )
V_140 = V_233 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . type = V_307 ;
V_138 . V_63 = F_41 ( V_63 ) ;
V_138 . V_65 = F_41 ( V_308 ) ;
V_138 . V_147 = V_140 ;
F_46 ( V_2 , V_148 , sizeof( V_138 ) ,
& V_138 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_56 = V_149 ;
V_139 . V_150 = V_151 ;
F_46 ( V_2 , V_120 , sizeof( V_139 ) ,
& V_139 ) ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 , unsigned long V_41 )
{
int V_6 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
V_6 = F_144 ( V_2 , V_41 ) ;
if ( V_6 )
return V_6 ;
return F_138 ( V_2 , V_309 ) ;
}
static void F_146 ( struct V_3 * V_4 , T_3 * V_200 )
{
unsigned long V_34 ;
F_4 ( L_20 , V_4 -> V_23 , V_4 -> V_77 . type ) ;
switch ( V_4 -> V_77 . type ) {
case V_310 :
if ( ! F_48 ( V_4 , V_298 ) )
F_34 ( V_4 , F_138 ,
V_309 , V_248 ,
V_200 ) ;
return;
case V_295 :
if ( F_35 ( V_296 ,
& V_4 -> V_297 ) ) {
V_34 = F_100 ( V_311 ) ;
F_34 ( V_4 , F_145 ,
V_312 * 2 , V_248 ,
V_200 ) ;
break;
}
V_34 = F_100 ( V_4 -> V_313 ) ;
F_34 ( V_4 , F_144 , V_312 ,
V_248 , V_200 ) ;
break;
case V_293 :
V_34 = F_100 ( V_311 ) ;
F_34 ( V_4 , F_144 , V_312 ,
V_248 , V_200 ) ;
break;
default:
* V_200 = V_43 ;
return;
}
if ( * V_200 )
return;
F_4 ( L_21 , V_4 -> V_23 , F_147 ( V_34 ) ) ;
if ( F_35 ( V_302 , & V_4 -> V_297 ) &&
V_4 -> V_77 . V_314 ) {
V_4 -> V_77 . V_292 = V_304 ;
V_4 -> V_77 . V_303 = V_34 ;
}
F_99 ( V_4 -> V_214 , & V_4 -> F_137 ,
V_34 ) ;
}
bool F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_315 * V_316 = & V_4 -> V_77 ;
struct V_317 V_84 ;
struct V_318 * V_319 ;
bool V_44 = false ;
F_4 ( L_22 , V_4 -> V_23 , V_4 -> V_77 . V_78 ) ;
if ( V_316 -> V_78 == V_320 || V_316 -> V_78 == V_321 ) {
if ( F_35 ( V_298 , & V_4 -> V_11 ) )
F_46 ( V_2 , V_322 , 0 , NULL ) ;
if ( F_48 ( V_4 , V_82 ) ) {
F_102 ( & V_4 -> F_137 ) ;
F_53 ( V_2 ) ;
}
V_44 = true ;
} else {
if ( F_48 ( V_4 , V_82 ) ) {
F_53 ( V_2 ) ;
V_44 = true ;
}
}
if ( V_316 -> type == V_293 )
return V_44 ;
if ( V_316 -> V_78 == V_299 || V_316 -> V_78 == V_321 ) {
V_319 = F_149 ( V_4 , V_231 ,
V_323 ) ;
if ( ! V_319 )
return V_44 ;
F_68 ( & V_84 . V_126 , & V_319 -> V_87 . V_126 ) ;
F_46 ( V_2 , V_324 , sizeof( V_84 ) ,
& V_84 ) ;
V_44 = true ;
}
return V_44 ;
}
static int F_150 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_96 ( V_2 -> V_4 ) ;
F_148 ( V_2 ) ;
F_98 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_151 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_151 ) ;
T_3 V_200 = 0 ;
switch ( V_4 -> V_77 . V_78 ) {
case V_325 :
F_146 ( V_4 , & V_200 ) ;
F_152 ( V_4 , V_200 ) ;
if ( V_200 )
F_141 ( V_4 , V_79 ) ;
else
F_141 ( V_4 , V_320 ) ;
break;
case V_321 :
F_34 ( V_4 , F_150 , 0 , V_248 , & V_200 ) ;
F_153 ( V_4 , V_200 ) ;
if ( ! V_200 )
F_141 ( V_4 , V_79 ) ;
break;
case V_79 :
default:
return;
}
}
static void F_154 ( struct V_203 * V_204 )
{
struct V_3 * V_4 = F_95 ( V_204 , struct V_3 ,
F_154 . V_204 ) ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_96 ( V_4 ) ;
F_82 ( V_4 , V_162 ) ;
F_82 ( V_4 , V_164 ) ;
V_4 -> V_326 = 0 ;
F_98 ( V_4 ) ;
F_34 ( V_4 , F_126 , 0 , V_248 , NULL ) ;
F_155 ( V_4 ) ;
}
static int F_156 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_327 ;
F_96 ( V_4 ) ;
if ( F_48 ( V_4 , V_114 ) &&
! F_157 ( V_4 ) ) {
T_3 V_328 = 0x01 ;
F_46 ( V_2 , V_329 , sizeof( V_328 ) , & V_328 ) ;
if ( F_158 ( V_4 ) && ! F_159 ( V_4 ) ) {
T_3 V_330 = 0x01 ;
F_46 ( V_2 , V_331 ,
sizeof( V_330 ) , & V_330 ) ;
}
}
if ( F_48 ( V_4 , V_76 ) &&
F_160 ( V_4 ) ) {
struct V_332 V_84 ;
V_84 . V_333 = 0x01 ;
V_84 . V_334 = 0x00 ;
if ( V_84 . V_333 != F_161 ( V_4 ) ||
V_84 . V_334 != F_162 ( V_4 ) )
F_46 ( V_2 , V_335 ,
sizeof( V_84 ) , & V_84 ) ;
}
if ( F_48 ( V_4 , V_76 ) ) {
if ( F_48 ( V_4 , V_201 ) ||
F_52 ( & V_4 -> V_202 ) ) {
F_89 ( V_2 , 0x00 ) ;
F_86 ( V_2 , 0x00 ) ;
if ( F_48 ( V_4 , V_201 ) )
F_80 ( V_2 ) ;
} else if ( ! F_52 ( & V_4 -> V_202 ) ) {
struct V_154 * V_155 ;
V_155 = F_163 ( & V_4 -> V_202 ,
struct V_154 , V_336 ) ;
F_93 ( V_2 ,
V_155 -> V_152 ,
true ) ;
}
}
V_327 = F_48 ( V_4 , V_337 ) ;
if ( V_327 != F_35 ( V_338 , & V_4 -> V_11 ) )
F_46 ( V_2 , V_339 ,
sizeof( V_327 ) , & V_327 ) ;
if ( F_160 ( V_4 ) ) {
if ( F_48 ( V_4 , V_340 ) )
F_47 ( V_2 , true ) ;
else
F_47 ( V_2 , false ) ;
F_115 ( V_2 ) ;
F_123 ( V_2 ) ;
F_56 ( V_2 ) ;
F_64 ( V_2 ) ;
}
F_98 ( V_4 ) ;
return 0 ;
}
int F_164 ( struct V_3 * V_4 )
{
F_165 ( V_4 ) ;
return F_32 ( V_4 , F_156 , 0 , V_248 ,
NULL ) ;
}
void F_166 ( struct V_3 * V_4 )
{
F_167 ( & V_4 -> F_151 , F_151 ) ;
F_167 ( & V_4 -> F_134 , F_134 ) ;
F_167 ( & V_4 -> V_247 , F_118 ) ;
F_167 ( & V_4 -> F_119 , F_120 ) ;
F_167 ( & V_4 -> F_126 , F_127 ) ;
F_168 ( & V_4 -> F_154 , F_154 ) ;
F_168 ( & V_4 -> F_137 , F_140 ) ;
F_168 ( & V_4 -> V_291 , F_142 ) ;
F_168 ( & V_4 -> V_205 , F_94 ) ;
}
void F_169 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_341 ) ;
F_170 ( & V_4 -> F_151 ) ;
F_170 ( & V_4 -> F_134 ) ;
F_170 ( & V_4 -> V_247 ) ;
F_170 ( & V_4 -> F_119 ) ;
F_170 ( & V_4 -> F_126 ) ;
F_171 ( & V_4 -> F_154 ) ;
F_171 ( & V_4 -> F_137 ) ;
F_171 ( & V_4 -> V_291 ) ;
if ( V_4 -> V_206 ) {
F_171 ( & V_4 -> V_205 ) ;
V_4 -> V_206 = 0 ;
}
}
