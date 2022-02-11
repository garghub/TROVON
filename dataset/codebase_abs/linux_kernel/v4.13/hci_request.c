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
F_30 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
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
V_50 = F_40 ( V_10 , V_48 ) ;
V_50 -> V_22 = F_41 ( V_22 ) ;
V_50 -> V_31 = V_31 ;
if ( V_31 )
F_42 ( V_10 , V_32 , V_31 ) ;
F_4 ( L_7 , V_10 -> V_47 ) ;
F_43 ( V_10 ) = V_52 ;
F_44 ( V_10 ) = V_22 ;
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
F_45 ( L_9 ,
V_4 -> V_23 , V_22 ) ;
V_2 -> V_6 = - V_53 ;
return;
}
if ( F_7 ( & V_2 -> V_5 ) )
F_9 ( V_10 ) -> V_13 . V_16 |= V_54 ;
F_9 ( V_10 ) -> V_13 . V_55 = V_33 ;
F_46 ( & V_2 -> V_5 , V_10 ) ;
}
void F_47 ( struct V_1 * V_2 , T_4 V_22 , T_5 V_31 ,
const void * V_32 )
{
F_22 ( V_2 , V_22 , V_31 , V_32 , 0 ) ;
}
void F_48 ( struct V_1 * V_2 , bool V_56 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 V_58 ;
T_3 type ;
if ( ! F_49 ( V_4 , V_59 ) )
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
if ( F_50 ( V_4 -> V_66 ) != V_58 . V_63 ||
F_50 ( V_4 -> V_67 ) != V_58 . V_65 )
F_47 ( V_2 , V_68 ,
sizeof( V_58 ) , & V_58 ) ;
if ( V_4 -> V_69 != type )
F_47 ( V_2 , V_70 , 1 , & type ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_35 ( V_45 , & V_4 -> V_11 ) ||
F_35 ( V_71 , & V_4 -> V_11 ) ||
F_49 ( V_4 , V_72 ) ||
F_49 ( V_4 , V_73 ) ||
F_49 ( V_4 , V_74 ) ||
F_49 ( V_4 , V_75 ) )
return;
if ( ! F_49 ( V_4 , V_76 ) )
return;
if ( V_4 -> V_77 . V_78 != V_79 )
return;
F_52 ( V_4 ) ;
if ( F_53 ( & V_4 -> V_80 ) &&
F_53 ( & V_4 -> V_81 ) ) {
if ( ! F_49 ( V_4 , V_82 ) )
return;
F_54 ( V_2 ) ;
F_4 ( L_10 , V_4 -> V_23 ) ;
} else {
if ( F_55 ( V_4 ) )
return;
if ( F_49 ( V_4 , V_82 ) )
F_54 ( V_2 ) ;
F_56 ( V_2 ) ;
F_4 ( L_11 , V_4 -> V_23 ) ;
}
}
void F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_83 V_84 ;
memcpy ( V_84 . V_23 , V_4 -> V_85 , sizeof( V_84 . V_23 ) ) ;
F_47 ( V_2 , V_86 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 * F_58 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 4 )
return V_88 ;
F_59 (uuid, &hdev->uuids, list) {
T_4 V_92 ;
if ( V_91 -> V_93 != 16 )
continue;
V_92 = F_60 ( & V_91 -> V_91 [ 12 ] ) ;
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
static T_3 * F_61 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 6 )
return V_88 ;
F_59 (uuid, &hdev->uuids, list) {
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
static T_3 * F_62 ( struct V_3 * V_4 , T_3 * V_87 , T_6 V_47 )
{
T_3 * V_88 = V_87 , * V_89 = NULL ;
struct V_90 * V_91 ;
if ( V_47 < 18 )
return V_88 ;
F_59 (uuid, &hdev->uuids, list) {
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
static void F_63 ( struct V_3 * V_4 , T_3 * V_87 )
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
F_64 ( V_4 -> V_107 , V_88 + 2 ) ;
F_64 ( V_4 -> V_109 , V_88 + 4 ) ;
F_64 ( V_4 -> V_110 , V_88 + 6 ) ;
F_64 ( V_4 -> V_111 , V_88 + 8 ) ;
V_88 += 10 ;
}
V_88 = F_58 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
V_88 = F_61 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
V_88 = F_62 ( V_4 , V_88 , V_112 - ( V_88 - V_87 ) ) ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_113 V_84 ;
if ( ! F_66 ( V_4 ) )
return;
if ( ! F_67 ( V_4 ) )
return;
if ( ! F_49 ( V_4 , V_114 ) )
return;
if ( F_49 ( V_4 , V_115 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_63 ( V_4 , V_84 . V_87 ) ;
if ( memcmp ( V_84 . V_87 , V_4 -> V_116 , sizeof( V_84 . V_87 ) ) == 0 )
return;
memcpy ( V_4 -> V_116 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
F_47 ( V_2 , V_117 , sizeof( V_84 ) , & V_84 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_118 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_56 = V_119 ;
F_47 ( V_2 , V_120 , sizeof( V_84 ) , & V_84 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_123 V_84 ;
V_84 . V_124 = V_122 -> V_125 ;
F_69 ( & V_84 . V_126 , & V_122 -> V_127 ) ;
F_47 ( V_2 , V_128 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_121 * V_122 ;
struct V_129 * V_130 ;
T_8 V_131 = 0 ;
F_59 (b, &hdev->le_white_list, list) {
if ( ! F_71 ( & V_4 -> V_80 ,
& V_130 -> V_126 , V_130 -> V_124 ) &&
! F_71 ( & V_4 -> V_81 ,
& V_130 -> V_126 , V_130 -> V_124 ) ) {
struct V_132 V_84 ;
V_84 . V_124 = V_130 -> V_124 ;
F_69 ( & V_84 . V_126 , & V_130 -> V_126 ) ;
F_47 ( V_2 , V_133 ,
sizeof( V_84 ) , & V_84 ) ;
continue;
}
if ( F_72 ( V_4 , & V_130 -> V_126 , V_130 -> V_124 ) ) {
return 0x00 ;
}
V_131 ++ ;
}
F_59 (params, &hdev->pend_le_conns, action) {
if ( F_73 ( & V_4 -> V_134 ,
& V_122 -> V_127 , V_122 -> V_125 ) )
continue;
if ( V_131 >= V_4 -> V_135 ) {
return 0x00 ;
}
if ( F_72 ( V_4 , & V_122 -> V_127 ,
V_122 -> V_125 ) ) {
return 0x00 ;
}
V_131 ++ ;
F_68 ( V_2 , V_122 ) ;
}
F_59 (params, &hdev->pend_le_reports, action) {
if ( F_73 ( & V_4 -> V_134 ,
& V_122 -> V_127 , V_122 -> V_125 ) )
continue;
if ( V_131 >= V_4 -> V_135 ) {
return 0x00 ;
}
if ( F_72 ( V_4 , & V_122 -> V_127 ,
V_122 -> V_125 ) ) {
return 0x00 ;
}
V_131 ++ ;
F_68 ( V_2 , V_122 ) ;
}
return 0x01 ;
}
static bool F_74 ( struct V_3 * V_4 )
{
return F_49 ( V_4 , V_136 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_137 V_138 ;
struct V_118 V_139 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_140 ;
T_3 V_141 ;
if ( F_75 ( V_2 , false , F_74 ( V_4 ) ,
& V_140 ) )
return;
V_141 = F_70 ( V_2 ) ;
if ( F_49 ( V_4 , V_136 ) &&
( V_4 -> V_142 [ 0 ] & V_143 ) )
V_141 |= 0x02 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . type = V_144 ;
V_138 . V_63 = F_41 ( V_4 -> V_145 ) ;
V_138 . V_65 = F_41 ( V_4 -> V_146 ) ;
V_138 . V_147 = V_140 ;
V_138 . V_141 = V_141 ;
F_47 ( V_2 , V_148 , sizeof( V_138 ) ,
& V_138 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_56 = V_149 ;
V_139 . V_150 = V_151 ;
F_47 ( V_2 , V_120 , sizeof( V_139 ) ,
& V_139 ) ;
}
static T_3 F_76 ( struct V_3 * V_4 )
{
T_3 V_152 = V_4 -> V_153 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 )
return 0 ;
V_155 = F_77 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_156 ;
}
void F_78 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_47 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static T_5 F_79 ( struct V_3 * V_4 , T_3 V_152 )
{
T_5 V_11 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 ) {
V_11 = V_158 | V_159 ;
if ( F_49 ( V_4 , V_160 ) )
V_11 |= V_161 ;
if ( F_49 ( V_4 , V_162 ) )
V_11 |= V_163 ;
else if ( F_49 ( V_4 , V_164 ) )
V_11 |= V_165 ;
return V_11 ;
}
V_155 = F_77 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_11 ;
}
static bool F_80 ( struct V_3 * V_4 , T_9 V_11 )
{
if ( ! F_49 ( V_4 , V_136 ) )
return false ;
if ( ! F_49 ( V_4 , V_166 ) )
return true ;
if ( ( V_11 & V_165 ) &&
F_49 ( V_4 , V_167 ) )
return false ;
return true ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_168 V_84 ;
T_3 V_140 , V_56 = 0x01 ;
bool V_169 ;
T_5 V_11 ;
if ( F_82 ( V_4 , V_170 ) > 0 )
return;
if ( F_49 ( V_4 , V_171 ) )
F_78 ( V_2 ) ;
F_83 ( V_4 , V_171 ) ;
V_11 = F_79 ( V_4 , V_4 -> V_153 ) ;
V_169 = ( V_11 & V_161 ) ||
F_84 ( V_4 ) ;
if ( F_75 ( V_2 , ! V_169 ,
F_80 ( V_4 , V_11 ) ,
& V_140 ) < 0 )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_172 = F_41 ( V_4 -> V_173 ) ;
V_84 . V_174 = F_41 ( V_4 -> V_175 ) ;
if ( V_169 )
V_84 . type = V_176 ;
else if ( F_76 ( V_4 ) )
V_84 . type = V_177 ;
else
V_84 . type = V_178 ;
V_84 . V_147 = V_140 ;
V_84 . V_179 = V_4 -> V_180 ;
F_47 ( V_2 , V_181 , sizeof( V_84 ) , & V_84 ) ;
F_47 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
T_3 F_85 ( struct V_3 * V_4 , T_3 * V_88 , T_3 V_182 )
{
T_7 V_183 ;
T_7 V_184 ;
if ( ( V_185 - V_182 ) < V_186 + 3 )
return V_182 ;
V_184 = strlen ( V_4 -> V_85 ) ;
if ( V_184 && V_184 <= V_186 )
return F_86 ( V_88 , V_182 , V_103 ,
V_4 -> V_85 , V_184 + 1 ) ;
V_183 = strlen ( V_4 -> V_187 ) ;
if ( V_183 )
return F_86 ( V_88 , V_182 , V_102 ,
V_4 -> V_187 , V_183 + 1 ) ;
if ( V_184 ) {
T_3 V_23 [ V_186 + 1 ] ;
memcpy ( V_23 , V_4 -> V_85 , V_186 ) ;
V_23 [ V_186 ] = '\0' ;
return F_86 ( V_88 , V_182 , V_102 , V_23 ,
sizeof( V_23 ) ) ;
}
return V_182 ;
}
static T_3 F_87 ( struct V_3 * V_4 , T_3 * V_88 , T_3 V_182 )
{
return F_88 ( V_88 , V_182 , V_188 , V_4 -> V_189 ) ;
}
static T_3 F_89 ( struct V_3 * V_4 , T_3 * V_88 )
{
T_3 V_156 = 0 ;
if ( V_4 -> V_189 ) {
V_156 = F_87 ( V_4 , V_88 , V_156 ) ;
}
return F_85 ( V_4 , V_88 , V_156 ) ;
}
static T_3 F_90 ( struct V_3 * V_4 , T_3 V_152 ,
T_3 * V_88 )
{
struct V_154 * V_155 ;
T_5 V_190 ;
T_3 V_156 = 0 ;
V_155 = F_77 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
V_190 = V_155 -> V_11 ;
if ( ( V_190 & V_191 ) && V_4 -> V_189 ) {
V_156 = F_87 ( V_4 , V_88 , V_156 ) ;
}
memcpy ( & V_88 [ V_156 ] , V_155 -> V_192 ,
V_155 -> V_156 ) ;
V_156 += V_155 -> V_156 ;
if ( V_190 & V_193 )
V_156 = F_85 ( V_4 , V_88 , V_156 ) ;
return V_156 ;
}
void F_91 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_194 V_84 ;
T_3 V_47 ;
if ( ! F_49 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_152 )
V_47 = F_90 ( V_4 , V_152 , V_84 . V_87 ) ;
else
V_47 = F_89 ( V_4 , V_84 . V_87 ) ;
if ( V_4 -> V_195 == V_47 &&
! memcmp ( V_84 . V_87 , V_4 -> V_192 , V_47 ) )
return;
memcpy ( V_4 -> V_192 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_195 = V_47 ;
V_84 . V_196 = V_47 ;
F_47 ( V_2 , V_197 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 F_92 ( struct V_3 * V_4 , T_3 V_152 , T_3 * V_88 )
{
struct V_154 * V_155 = NULL ;
T_3 V_182 = 0 , V_11 = 0 ;
T_5 V_190 ;
if ( V_152 ) {
V_155 = F_77 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
}
V_190 = F_79 ( V_4 , V_152 ) ;
if ( V_190 & V_165 )
V_11 |= V_198 ;
if ( V_190 & V_163 )
V_11 |= V_199 ;
if ( ! F_49 ( V_4 , V_59 ) )
V_11 |= V_200 ;
if ( V_11 || ( V_190 & V_159 ) ) {
if ( ! V_11 )
V_11 |= F_93 ( V_4 ) ;
if ( V_11 ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_201 ;
V_88 [ 2 ] = V_11 ;
V_182 += 3 ;
V_88 += 3 ;
}
}
if ( V_155 ) {
memcpy ( V_88 , V_155 -> V_202 ,
V_155 -> V_203 ) ;
V_182 += V_155 -> V_203 ;
V_88 += V_155 -> V_203 ;
}
if ( V_4 -> V_204 != V_105 &&
( V_190 & V_158 ) ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_106 ;
V_88 [ 2 ] = ( T_3 ) V_4 -> V_204 ;
V_182 += 3 ;
V_88 += 3 ;
}
return V_182 ;
}
void F_94 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_205 V_84 ;
T_3 V_47 ;
if ( ! F_49 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_47 = F_92 ( V_4 , V_152 , V_84 . V_87 ) ;
if ( V_4 -> V_203 == V_47 &&
memcmp ( V_84 . V_87 , V_4 -> V_202 , V_47 ) == 0 )
return;
memcpy ( V_4 -> V_202 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_203 = V_47 ;
V_84 . V_196 = V_47 ;
F_47 ( V_2 , V_206 , sizeof( V_84 ) , & V_84 ) ;
}
int F_95 ( struct V_3 * V_4 , T_3 V_152 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_94 ( & V_2 , V_152 ) ;
return F_14 ( & V_2 , NULL ) ;
}
static void F_96 ( struct V_3 * V_4 , T_3 V_207 , T_4 V_22 )
{
F_4 ( L_12 , V_4 -> V_23 , V_207 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
if ( ! F_49 ( V_4 , V_208 ) &&
F_53 ( & V_4 -> V_209 ) )
return;
F_1 ( & V_2 , V_4 ) ;
if ( V_4 -> V_153 ) {
F_98 ( & V_2 , V_4 -> V_153 ,
true ) ;
} else {
F_94 ( & V_2 , 0x00 ) ;
F_91 ( & V_2 , 0x00 ) ;
F_81 ( & V_2 ) ;
}
F_14 ( & V_2 , F_96 ) ;
}
static void F_99 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
V_212 . V_211 ) ;
struct V_1 V_2 ;
T_3 V_152 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_101 ( V_4 ) ;
V_4 -> V_213 = 0 ;
V_152 = V_4 -> V_153 ;
if ( V_152 == 0x00 )
goto V_214;
F_1 ( & V_2 , V_4 ) ;
F_102 ( V_4 , NULL , & V_2 , V_152 , false ) ;
if ( F_53 ( & V_4 -> V_209 ) )
F_78 ( & V_2 ) ;
F_14 ( & V_2 , NULL ) ;
V_214:
F_103 ( V_4 ) ;
}
int F_98 ( struct V_1 * V_2 , T_3 V_152 ,
bool V_215 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_154 * V_155 = NULL ;
T_4 V_34 ;
if ( F_49 ( V_4 , V_208 ) ||
F_53 ( & V_4 -> V_209 ) )
return - V_216 ;
if ( V_4 -> V_213 )
return - V_217 ;
V_155 = F_77 ( V_4 , V_152 ) ;
if ( ! V_155 )
return - V_218 ;
if ( V_155 -> V_34 == 0 ||
V_155 -> V_219 <= V_155 -> V_220 )
V_34 = V_155 -> V_219 ;
else
V_34 = V_155 -> V_220 ;
if ( V_155 -> V_34 )
V_155 -> V_220 =
V_155 -> V_220 - V_34 ;
V_4 -> V_213 = V_34 ;
F_104 ( V_4 -> V_221 ,
& V_4 -> V_212 ,
F_105 ( V_34 * 1000 ) ) ;
if ( ! V_215 && V_4 -> V_153 == V_152 &&
F_49 ( V_4 , V_171 ) )
return 0 ;
V_4 -> V_153 = V_152 ;
F_94 ( V_2 , V_152 ) ;
F_91 ( V_2 , V_152 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static void F_106 ( struct V_3 * V_4 )
{
if ( V_4 -> V_213 ) {
V_4 -> V_213 = 0 ;
F_107 ( & V_4 -> V_212 ) ;
}
}
void F_102 ( struct V_3 * V_4 , struct V_222 * V_223 ,
struct V_1 * V_2 , T_3 V_152 ,
bool V_215 )
{
struct V_154 * V_155 , * V_224 , * V_225 = NULL ;
int V_6 ;
T_3 V_226 ;
if ( ! V_152 || V_4 -> V_153 == V_152 )
F_106 ( V_4 ) ;
if ( V_152 && V_4 -> V_153 == V_152 )
V_225 = F_108 ( V_4 , V_152 ) ;
if ( V_152 == 0x00 ) {
F_109 (adv_instance, n, &hdev->adv_instances,
list) {
if ( ! ( V_215 || V_155 -> V_34 ) )
continue;
V_226 = V_155 -> V_152 ;
V_6 = F_110 ( V_4 , V_226 ) ;
if ( ! V_6 )
F_111 ( V_223 , V_4 , V_226 ) ;
}
} else {
V_155 = F_77 ( V_4 , V_152 ) ;
if ( V_215 || ( V_155 && V_155 -> V_34 &&
! V_155 -> V_220 ) ) {
if ( V_225 &&
V_225 -> V_152 == V_152 )
V_225 = NULL ;
V_6 = F_110 ( V_4 , V_152 ) ;
if ( ! V_6 )
F_111 ( V_223 , V_4 , V_152 ) ;
}
}
if ( ! V_2 || ! F_66 ( V_4 ) ||
F_49 ( V_4 , V_208 ) )
return;
if ( V_225 )
F_98 ( V_2 , V_225 -> V_152 ,
false ) ;
}
static void F_112 ( struct V_1 * V_2 , T_10 * V_227 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_49 ( V_4 , V_171 ) ||
F_55 ( V_4 ) ) {
F_4 ( L_13 ) ;
F_113 ( V_4 , V_228 ) ;
return;
}
F_47 ( V_2 , V_229 , 6 , V_227 ) ;
}
int F_75 ( struct V_1 * V_2 , bool V_230 ,
bool V_231 , T_3 * V_140 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( V_231 ) {
int V_232 ;
* V_140 = V_233 ;
if ( ! F_114 ( V_4 , V_228 ) &&
! F_115 ( & V_4 -> V_234 , & V_4 -> V_227 ) )
return 0 ;
V_6 = F_116 ( V_4 , V_4 -> V_235 , & V_4 -> V_227 ) ;
if ( V_6 < 0 ) {
F_45 ( L_14 , V_4 -> V_23 ) ;
return V_6 ;
}
F_112 ( V_2 , & V_4 -> V_227 ) ;
V_232 = F_105 ( V_4 -> V_236 * 1000 ) ;
F_104 ( V_4 -> V_19 , & V_4 -> V_237 , V_232 ) ;
return 0 ;
}
if ( V_230 ) {
T_10 V_238 ;
while ( true ) {
F_117 ( & V_238 , 6 ) ;
V_238 . V_130 [ 5 ] &= 0x3f ;
if ( F_115 ( & V_4 -> V_126 , & V_238 ) )
break;
}
* V_140 = V_233 ;
F_112 ( V_2 , & V_238 ) ;
return 0 ;
}
if ( F_49 ( V_4 , V_239 ) ||
! F_115 ( & V_4 -> V_126 , V_240 ) ||
( ! F_49 ( V_4 , V_59 ) &&
F_115 ( & V_4 -> V_241 , V_240 ) ) ) {
* V_140 = V_233 ;
if ( F_115 ( & V_4 -> V_241 , & V_4 -> V_234 ) )
F_47 ( V_2 , V_229 , 6 ,
& V_4 -> V_241 ) ;
return 0 ;
}
* V_140 = V_242 ;
return 0 ;
}
static bool F_118 ( struct V_3 * V_4 )
{
struct V_129 * V_130 ;
F_59 (b, &hdev->whitelist, list) {
struct V_243 * V_244 ;
V_244 = F_119 ( V_4 , V_245 , & V_130 -> V_126 ) ;
if ( ! V_244 )
return true ;
if ( V_244 -> V_78 != V_246 && V_244 -> V_78 != V_247 )
return true ;
}
return false ;
}
void F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_248 ;
if ( ! F_49 ( V_4 , V_59 ) )
return;
if ( ! F_66 ( V_4 ) )
return;
if ( F_121 ( V_4 ) )
return;
if ( F_49 ( V_4 , V_249 ) ||
F_118 ( V_4 ) )
V_248 = V_250 ;
else
V_248 = V_251 ;
if ( F_49 ( V_4 , V_164 ) )
V_248 |= V_252 ;
if ( F_35 ( V_253 , & V_4 -> V_11 ) == ! ! ( V_248 & V_250 ) &&
F_35 ( V_254 , & V_4 -> V_11 ) == ! ! ( V_248 & V_252 ) )
return;
F_47 ( V_2 , V_255 , 1 , & V_248 ) ;
}
static int F_122 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_101 ( V_2 -> V_4 ) ;
F_120 ( V_2 ) ;
F_103 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_123 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 , V_256 ) ;
F_34 ( V_4 , F_122 , 0 , V_257 , NULL ) ;
}
static int F_124 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_101 ( V_4 ) ;
F_120 ( V_2 ) ;
if ( ! F_49 ( V_4 , V_59 ) )
F_94 ( V_2 , V_4 -> V_153 ) ;
if ( F_49 ( V_4 , V_208 ) ||
! F_53 ( & V_4 -> V_209 ) )
F_81 ( V_2 ) ;
F_51 ( V_2 ) ;
F_103 ( V_4 ) ;
return 0 ;
}
static void F_125 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_124 ) ;
T_3 V_207 ;
F_34 ( V_4 , F_124 , 0 , V_257 , & V_207 ) ;
F_126 ( V_4 , V_207 ) ;
}
static T_3 F_127 ( struct V_3 * V_4 )
{
struct V_90 * V_91 ;
T_3 V_258 = 0 ;
F_59 (uuid, &hdev->uuids, list)
V_258 |= V_91 -> V_259 ;
return V_258 ;
}
void F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_260 [ 3 ] ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_66 ( V_4 ) )
return;
if ( ! F_49 ( V_4 , V_59 ) )
return;
if ( F_49 ( V_4 , V_115 ) )
return;
V_260 [ 0 ] = V_4 -> V_261 ;
V_260 [ 1 ] = V_4 -> V_262 ;
V_260 [ 2 ] = F_127 ( V_4 ) ;
if ( F_49 ( V_4 , V_162 ) )
V_260 [ 1 ] |= 0x20 ;
if ( memcmp ( V_260 , V_4 -> V_263 , 3 ) == 0 )
return;
F_47 ( V_2 , V_264 , sizeof( V_260 ) , V_260 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_265 V_84 ;
if ( ! F_49 ( V_4 , V_164 ) )
return;
if ( F_49 ( V_4 , V_162 ) ) {
V_84 . V_266 = F_130 ( T_3 , V_4 -> V_266 , 2 ) ;
V_84 . V_267 [ 0 ] = 0x00 ;
V_84 . V_267 [ 1 ] = 0x8b ;
V_84 . V_267 [ 2 ] = 0x9e ;
V_84 . V_267 [ 3 ] = 0x33 ;
V_84 . V_267 [ 4 ] = 0x8b ;
V_84 . V_267 [ 5 ] = 0x9e ;
} else {
V_84 . V_266 = 1 ;
V_84 . V_267 [ 0 ] = 0x33 ;
V_84 . V_267 [ 1 ] = 0x8b ;
V_84 . V_267 [ 2 ] = 0x9e ;
}
F_47 ( V_2 , V_268 ,
( V_84 . V_266 * 3 ) + 1 , & V_84 ) ;
}
static int F_131 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_101 ( V_4 ) ;
if ( F_49 ( V_4 , V_59 ) ) {
F_129 ( V_2 ) ;
F_120 ( V_2 ) ;
F_128 ( V_2 ) ;
}
if ( F_49 ( V_4 , V_208 ) ) {
F_94 ( V_2 , 0x00 ) ;
if ( F_49 ( V_4 , V_166 ) )
F_81 ( V_2 ) ;
}
F_103 ( V_4 ) ;
return 0 ;
}
static void F_132 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_131 ) ;
T_3 V_207 ;
F_34 ( V_4 , F_131 , 0 , V_257 , & V_207 ) ;
F_133 ( V_4 , V_207 ) ;
}
void F_134 ( struct V_1 * V_2 , struct V_243 * V_244 ,
T_3 V_269 )
{
switch ( V_244 -> V_78 ) {
case V_246 :
case V_247 :
if ( V_244 -> type == V_270 ) {
struct V_271 V_84 ;
V_84 . V_272 = F_135 ( V_244 -> V_273 ) ;
V_84 . V_269 = V_269 ;
F_47 ( V_2 , V_274 , sizeof( V_84 ) ,
& V_84 ) ;
} else {
struct V_275 V_276 ;
V_276 . V_273 = F_41 ( V_244 -> V_273 ) ;
V_276 . V_269 = V_269 ;
F_47 ( V_2 , V_277 , sizeof( V_276 ) , & V_276 ) ;
}
V_244 -> V_78 = V_278 ;
break;
case V_279 :
if ( V_244 -> type == V_170 ) {
if ( F_35 ( V_280 , & V_244 -> V_11 ) )
break;
F_47 ( V_2 , V_281 ,
0 , NULL ) ;
} else if ( V_244 -> type == V_245 ) {
if ( V_2 -> V_4 -> V_60 < V_61 )
break;
F_47 ( V_2 , V_282 ,
6 , & V_244 -> V_283 ) ;
}
break;
case V_284 :
if ( V_244 -> type == V_245 ) {
struct V_285 V_286 ;
F_69 ( & V_286 . V_126 , & V_244 -> V_283 ) ;
V_286 . V_269 = V_269 ;
F_47 ( V_2 , V_287 ,
sizeof( V_286 ) , & V_286 ) ;
} else if ( V_244 -> type == V_288 || V_244 -> type == V_289 ) {
struct V_290 V_286 ;
F_69 ( & V_286 . V_126 , & V_244 -> V_283 ) ;
V_286 . V_269 = V_291 ;
F_47 ( V_2 , V_292 ,
sizeof( V_286 ) , & V_286 ) ;
}
break;
default:
V_244 -> V_78 = V_293 ;
break;
}
}
static void F_136 ( struct V_3 * V_4 , T_3 V_207 , T_4 V_22 )
{
if ( V_207 )
F_4 ( L_15 , V_207 ) ;
}
int F_137 ( struct V_243 * V_244 , T_3 V_269 )
{
struct V_1 V_2 ;
int V_6 ;
F_1 ( & V_2 , V_244 -> V_4 ) ;
F_134 ( & V_2 , V_244 , V_269 ) ;
V_6 = F_14 ( & V_2 , F_136 ) ;
if ( V_6 && V_6 != - V_12 ) {
F_45 ( L_16 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_101 ( V_2 -> V_4 ) ;
F_51 ( V_2 ) ;
F_103 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_139 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_139 ) ;
struct V_243 * V_244 ;
T_3 V_207 ;
int V_6 ;
V_6 = F_34 ( V_4 , F_138 , 0 , V_257 , & V_207 ) ;
if ( ! V_6 )
return;
F_101 ( V_4 ) ;
V_244 = F_140 ( V_4 , V_170 , V_279 ) ;
if ( V_244 )
F_141 ( V_244 , V_207 ) ;
F_103 ( V_4 ) ;
}
static int F_142 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_54 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_3 V_196 = V_41 ;
const T_3 V_294 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
const T_3 V_295 [ 3 ] = { 0x00 , 0x8b , 0x9e } ;
struct V_296 V_84 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
F_101 ( V_2 -> V_4 ) ;
F_144 ( V_2 -> V_4 ) ;
F_103 ( V_2 -> V_4 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_2 -> V_4 -> V_77 . V_297 )
memcpy ( & V_84 . V_298 , V_295 , sizeof( V_84 . V_298 ) ) ;
else
memcpy ( & V_84 . V_298 , V_294 , sizeof( V_84 . V_298 ) ) ;
V_84 . V_196 = V_196 ;
F_47 ( V_2 , V_299 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
static void F_145 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_142 . V_211 ) ;
T_3 V_207 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_49 ( V_4 , V_82 ) )
return;
F_107 ( & V_4 -> V_300 ) ;
F_34 ( V_4 , F_142 , 0 , V_257 , & V_207 ) ;
if ( V_207 ) {
F_45 ( L_17 , V_207 ) ;
return;
}
V_4 -> V_77 . V_301 = 0 ;
if ( V_4 -> V_77 . type == V_302 )
goto V_303;
if ( V_4 -> V_77 . type != V_304 )
return;
if ( F_35 ( V_305 , & V_4 -> V_306 ) ) {
if ( ! F_35 ( V_307 , & V_4 -> V_11 ) &&
V_4 -> V_77 . V_78 != V_308 )
goto V_303;
return;
}
F_34 ( V_4 , F_143 , V_309 ,
V_257 , & V_207 ) ;
if ( V_207 ) {
F_45 ( L_18 , V_207 ) ;
goto V_303;
}
return;
V_303:
F_101 ( V_4 ) ;
F_146 ( V_4 , V_79 ) ;
F_103 ( V_4 ) ;
}
static int V_300 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_118 V_84 ;
if ( ! F_49 ( V_4 , V_82 ) )
return 0 ;
F_54 ( V_2 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_56 = V_149 ;
V_84 . V_150 = V_151 ;
F_47 ( V_2 , V_120 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
static void F_147 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
V_300 . V_211 ) ;
unsigned long V_34 , V_219 , V_301 , V_310 ;
T_3 V_207 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_34 ( V_4 , V_300 , 0 , V_257 , & V_207 ) ;
if ( V_207 ) {
F_45 ( L_19 , V_207 ) ;
return;
}
F_101 ( V_4 ) ;
if ( ! F_35 ( V_311 , & V_4 -> V_306 ) ||
! V_4 -> V_77 . V_301 )
goto V_214;
V_219 = V_4 -> V_77 . V_312 ;
V_301 = V_4 -> V_77 . V_301 ;
V_310 = V_313 ;
if ( V_310 - V_301 <= V_219 ) {
int V_314 ;
if ( V_310 >= V_301 )
V_314 = V_310 - V_301 ;
else
V_314 = V_315 - V_301 + V_310 ;
V_34 = V_219 - V_314 ;
} else {
V_34 = 0 ;
}
F_104 ( V_4 -> V_221 ,
& V_4 -> F_142 , V_34 ) ;
V_214:
F_103 ( V_4 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_47 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static int F_149 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_11 V_63 = V_41 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_137 V_138 ;
struct V_118 V_139 ;
T_3 V_140 ;
int V_6 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( F_49 ( V_4 , V_171 ) ) {
F_101 ( V_4 ) ;
if ( F_55 ( V_4 ) ) {
F_103 ( V_4 ) ;
return - V_217 ;
}
F_106 ( V_4 ) ;
F_103 ( V_4 ) ;
F_148 ( V_2 ) ;
}
if ( F_49 ( V_4 , V_82 ) )
F_54 ( V_2 ) ;
V_6 = F_75 ( V_2 , true , F_74 ( V_4 ) ,
& V_140 ) ;
if ( V_6 < 0 )
V_140 = V_242 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . type = V_316 ;
V_138 . V_63 = F_41 ( V_63 ) ;
V_138 . V_65 = F_41 ( V_317 ) ;
V_138 . V_147 = V_140 ;
F_47 ( V_2 , V_148 , sizeof( V_138 ) ,
& V_138 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_56 = V_149 ;
V_139 . V_150 = V_151 ;
F_47 ( V_2 , V_120 , sizeof( V_139 ) ,
& V_139 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , unsigned long V_41 )
{
int V_6 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
V_6 = F_149 ( V_2 , V_41 ) ;
if ( V_6 )
return V_6 ;
return F_143 ( V_2 , V_318 ) ;
}
static void F_151 ( struct V_3 * V_4 , T_3 * V_207 )
{
unsigned long V_34 ;
F_4 ( L_20 , V_4 -> V_23 , V_4 -> V_77 . type ) ;
switch ( V_4 -> V_77 . type ) {
case V_319 :
if ( ! F_49 ( V_4 , V_307 ) )
F_34 ( V_4 , F_143 ,
V_318 , V_257 ,
V_207 ) ;
return;
case V_304 :
if ( F_35 ( V_305 ,
& V_4 -> V_306 ) ) {
V_34 = F_105 ( V_320 ) ;
F_34 ( V_4 , F_150 ,
V_321 * 2 , V_257 ,
V_207 ) ;
break;
}
V_34 = F_105 ( V_4 -> V_322 ) ;
F_34 ( V_4 , F_149 , V_321 ,
V_257 , V_207 ) ;
break;
case V_302 :
V_34 = F_105 ( V_320 ) ;
F_34 ( V_4 , F_149 , V_321 ,
V_257 , V_207 ) ;
break;
default:
* V_207 = V_43 ;
return;
}
if ( * V_207 )
return;
F_4 ( L_21 , V_4 -> V_23 , F_152 ( V_34 ) ) ;
if ( F_35 ( V_311 , & V_4 -> V_306 ) &&
V_4 -> V_77 . V_323 ) {
V_4 -> V_77 . V_301 = V_313 ;
V_4 -> V_77 . V_312 = V_34 ;
}
F_104 ( V_4 -> V_221 , & V_4 -> F_142 ,
V_34 ) ;
}
bool F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_324 * V_325 = & V_4 -> V_77 ;
struct V_326 V_84 ;
struct V_327 * V_328 ;
bool V_44 = false ;
F_4 ( L_22 , V_4 -> V_23 , V_4 -> V_77 . V_78 ) ;
if ( V_325 -> V_78 == V_329 || V_325 -> V_78 == V_330 ) {
if ( F_35 ( V_307 , & V_4 -> V_11 ) )
F_47 ( V_2 , V_331 , 0 , NULL ) ;
if ( F_49 ( V_4 , V_82 ) ) {
F_107 ( & V_4 -> F_142 ) ;
F_54 ( V_2 ) ;
}
V_44 = true ;
} else {
if ( F_49 ( V_4 , V_82 ) ) {
F_54 ( V_2 ) ;
V_44 = true ;
}
}
if ( V_325 -> type == V_302 )
return V_44 ;
if ( V_325 -> V_78 == V_308 || V_325 -> V_78 == V_330 ) {
V_328 = F_154 ( V_4 , V_240 ,
V_332 ) ;
if ( ! V_328 )
return V_44 ;
F_69 ( & V_84 . V_126 , & V_328 -> V_87 . V_126 ) ;
F_47 ( V_2 , V_333 , sizeof( V_84 ) ,
& V_84 ) ;
V_44 = true ;
}
return V_44 ;
}
static int F_155 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_101 ( V_2 -> V_4 ) ;
F_153 ( V_2 ) ;
F_103 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_156 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_156 ) ;
T_3 V_207 = 0 ;
switch ( V_4 -> V_77 . V_78 ) {
case V_334 :
F_151 ( V_4 , & V_207 ) ;
F_157 ( V_4 , V_207 ) ;
if ( V_207 )
F_146 ( V_4 , V_79 ) ;
else
F_146 ( V_4 , V_329 ) ;
break;
case V_330 :
F_34 ( V_4 , F_155 , 0 , V_257 , & V_207 ) ;
F_158 ( V_4 , V_207 ) ;
if ( ! V_207 )
F_146 ( V_4 , V_79 ) ;
break;
case V_79 :
default:
return;
}
}
static void F_159 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = F_100 ( V_211 , struct V_3 ,
F_159 . V_211 ) ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_101 ( V_4 ) ;
F_83 ( V_4 , V_162 ) ;
F_83 ( V_4 , V_164 ) ;
V_4 -> V_335 = 0 ;
F_103 ( V_4 ) ;
F_34 ( V_4 , F_131 , 0 , V_257 , NULL ) ;
F_160 ( V_4 ) ;
}
static int F_161 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_336 ;
F_101 ( V_4 ) ;
if ( F_49 ( V_4 , V_114 ) &&
! F_162 ( V_4 ) ) {
T_3 V_337 = 0x01 ;
F_47 ( V_2 , V_338 , sizeof( V_337 ) , & V_337 ) ;
if ( F_163 ( V_4 ) && ! F_164 ( V_4 ) ) {
T_3 V_339 = 0x01 ;
F_47 ( V_2 , V_340 ,
sizeof( V_339 ) , & V_339 ) ;
}
}
if ( F_49 ( V_4 , V_76 ) &&
F_165 ( V_4 ) ) {
struct V_341 V_84 ;
V_84 . V_342 = 0x01 ;
V_84 . V_343 = 0x00 ;
if ( V_84 . V_342 != F_166 ( V_4 ) ||
V_84 . V_343 != F_167 ( V_4 ) )
F_47 ( V_2 , V_344 ,
sizeof( V_84 ) , & V_84 ) ;
}
if ( F_49 ( V_4 , V_76 ) ) {
if ( F_49 ( V_4 , V_208 ) ||
F_53 ( & V_4 -> V_209 ) ) {
F_94 ( V_2 , 0x00 ) ;
F_91 ( V_2 , 0x00 ) ;
if ( F_49 ( V_4 , V_208 ) )
F_81 ( V_2 ) ;
} else if ( ! F_53 ( & V_4 -> V_209 ) ) {
struct V_154 * V_155 ;
V_155 = F_168 ( & V_4 -> V_209 ,
struct V_154 , V_345 ) ;
F_98 ( V_2 ,
V_155 -> V_152 ,
true ) ;
}
}
V_336 = F_49 ( V_4 , V_346 ) ;
if ( V_336 != F_35 ( V_347 , & V_4 -> V_11 ) )
F_47 ( V_2 , V_348 ,
sizeof( V_336 ) , & V_336 ) ;
if ( F_165 ( V_4 ) ) {
if ( F_49 ( V_4 , V_349 ) )
F_48 ( V_2 , true ) ;
else
F_48 ( V_2 , false ) ;
F_120 ( V_2 ) ;
F_128 ( V_2 ) ;
F_57 ( V_2 ) ;
F_65 ( V_2 ) ;
}
F_103 ( V_4 ) ;
return 0 ;
}
int F_169 ( struct V_3 * V_4 )
{
F_170 ( V_4 ) ;
return F_32 ( V_4 , F_161 , 0 , V_257 ,
NULL ) ;
}
void F_171 ( struct V_3 * V_4 )
{
F_172 ( & V_4 -> F_156 , F_156 ) ;
F_172 ( & V_4 -> F_139 , F_139 ) ;
F_172 ( & V_4 -> V_256 , F_123 ) ;
F_172 ( & V_4 -> F_124 , F_125 ) ;
F_172 ( & V_4 -> F_131 , F_132 ) ;
F_173 ( & V_4 -> F_159 , F_159 ) ;
F_173 ( & V_4 -> F_142 , F_145 ) ;
F_173 ( & V_4 -> V_300 , F_147 ) ;
F_173 ( & V_4 -> V_212 , F_99 ) ;
}
void F_174 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_350 ) ;
F_175 ( & V_4 -> F_156 ) ;
F_175 ( & V_4 -> F_139 ) ;
F_175 ( & V_4 -> V_256 ) ;
F_175 ( & V_4 -> F_124 ) ;
F_175 ( & V_4 -> F_131 ) ;
F_176 ( & V_4 -> F_159 ) ;
F_176 ( & V_4 -> F_142 ) ;
F_176 ( & V_4 -> V_300 ) ;
if ( V_4 -> V_213 ) {
F_176 ( & V_4 -> V_212 ) ;
V_4 -> V_213 = 0 ;
}
}
