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
void F_55 ( struct V_1 * V_2 )
{
struct V_136 V_137 ;
struct V_118 V_138 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_139 ;
T_3 V_140 ;
if ( F_73 ( V_2 , false , & V_139 ) )
return;
V_140 = F_69 ( V_2 ) ;
if ( F_48 ( V_4 , V_141 ) &&
( V_4 -> V_142 [ 0 ] & V_143 ) )
V_140 |= 0x02 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . type = V_144 ;
V_137 . V_63 = F_41 ( V_4 -> V_145 ) ;
V_137 . V_65 = F_41 ( V_4 -> V_146 ) ;
V_137 . V_147 = V_139 ;
V_137 . V_140 = V_140 ;
F_46 ( V_2 , V_148 , sizeof( V_137 ) ,
& V_137 ) ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_56 = V_149 ;
V_138 . V_150 = V_151 ;
F_46 ( V_2 , V_120 , sizeof( V_138 ) ,
& V_138 ) ;
}
static T_3 F_74 ( struct V_3 * V_4 )
{
T_3 V_152 = V_4 -> V_153 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 )
return 0 ;
V_155 = F_75 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_156 ;
}
void F_76 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static T_5 F_77 ( struct V_3 * V_4 , T_3 V_152 )
{
T_5 V_11 ;
struct V_154 * V_155 ;
if ( V_152 == 0x00 ) {
V_11 = V_158 | V_159 ;
if ( F_48 ( V_4 , V_160 ) )
V_11 |= V_161 ;
return V_11 ;
}
V_155 = F_75 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
return V_155 -> V_11 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_162 V_84 ;
T_3 V_139 , V_56 = 0x01 ;
bool V_163 ;
T_5 V_11 ;
if ( F_79 ( V_4 , V_164 ) > 0 )
return;
if ( F_48 ( V_4 , V_165 ) )
F_76 ( V_2 ) ;
F_80 ( V_4 , V_165 ) ;
V_11 = F_77 ( V_4 , V_4 -> V_153 ) ;
V_163 = ( V_11 & V_161 ) ||
F_81 ( V_4 ) ;
if ( F_73 ( V_2 , ! V_163 , & V_139 ) < 0 )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_166 = F_41 ( V_4 -> V_167 ) ;
V_84 . V_168 = F_41 ( V_4 -> V_169 ) ;
if ( V_163 )
V_84 . type = V_170 ;
else if ( F_74 ( V_4 ) )
V_84 . type = V_171 ;
else
V_84 . type = V_172 ;
V_84 . V_147 = V_139 ;
V_84 . V_173 = V_4 -> V_174 ;
F_46 ( V_2 , V_175 , sizeof( V_84 ) , & V_84 ) ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static T_3 F_82 ( struct V_3 * V_4 , T_3 * V_88 )
{
T_3 V_176 = 0 ;
T_7 V_101 ;
V_101 = strlen ( V_4 -> V_85 ) ;
if ( V_101 > 0 ) {
T_7 V_177 = V_178 - V_176 - 2 ;
if ( V_101 > V_177 ) {
V_101 = V_177 ;
V_88 [ 1 ] = V_102 ;
} else
V_88 [ 1 ] = V_103 ;
V_88 [ 0 ] = V_101 + 1 ;
memcpy ( V_88 + 2 , V_4 -> V_85 , V_101 ) ;
V_176 += ( V_101 + 2 ) ;
V_88 += ( V_101 + 2 ) ;
}
return V_176 ;
}
static T_3 F_83 ( struct V_3 * V_4 , T_3 V_152 ,
T_3 * V_88 )
{
struct V_154 * V_155 ;
V_155 = F_75 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
memcpy ( V_88 , V_155 -> V_179 ,
V_155 -> V_156 ) ;
return V_155 -> V_156 ;
}
void F_84 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_180 V_84 ;
T_3 V_47 ;
if ( ! F_48 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_152 )
V_47 = F_83 ( V_4 , V_152 , V_84 . V_87 ) ;
else
V_47 = F_82 ( V_4 , V_84 . V_87 ) ;
if ( V_4 -> V_181 == V_47 &&
! memcmp ( V_84 . V_87 , V_4 -> V_179 , V_47 ) )
return;
memcpy ( V_4 -> V_179 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_181 = V_47 ;
V_84 . V_182 = V_47 ;
F_46 ( V_2 , V_183 , sizeof( V_84 ) , & V_84 ) ;
}
static T_3 F_85 ( struct V_3 * V_4 , T_3 V_152 , T_3 * V_88 )
{
struct V_154 * V_155 = NULL ;
T_3 V_176 = 0 , V_11 = 0 ;
T_5 V_184 ;
if ( V_152 ) {
V_155 = F_75 ( V_4 , V_152 ) ;
if ( ! V_155 )
return 0 ;
}
V_184 = F_77 ( V_4 , V_152 ) ;
if ( V_184 & V_185 )
V_11 |= V_186 ;
if ( V_184 & V_187 )
V_11 |= V_188 ;
if ( V_11 || ( V_184 & V_159 ) ) {
if ( ! V_11 )
V_11 |= F_86 ( V_4 ) ;
if ( ! F_48 ( V_4 , V_59 ) )
V_11 |= V_189 ;
if ( V_11 ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_190 ;
V_88 [ 2 ] = V_11 ;
V_176 += 3 ;
V_88 += 3 ;
}
}
if ( V_155 ) {
memcpy ( V_88 , V_155 -> V_191 ,
V_155 -> V_192 ) ;
V_176 += V_155 -> V_192 ;
V_88 += V_155 -> V_192 ;
}
if ( V_4 -> V_193 != V_105 &&
( V_184 & V_158 ) ) {
V_88 [ 0 ] = 0x02 ;
V_88 [ 1 ] = V_106 ;
V_88 [ 2 ] = ( T_3 ) V_4 -> V_193 ;
V_176 += 3 ;
V_88 += 3 ;
}
return V_176 ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_152 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_194 V_84 ;
T_3 V_47 ;
if ( ! F_48 ( V_4 , V_76 ) )
return;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_47 = F_85 ( V_4 , V_152 , V_84 . V_87 ) ;
if ( V_4 -> V_192 == V_47 &&
memcmp ( V_84 . V_87 , V_4 -> V_191 , V_47 ) == 0 )
return;
memcpy ( V_4 -> V_191 , V_84 . V_87 , sizeof( V_84 . V_87 ) ) ;
V_4 -> V_192 = V_47 ;
V_84 . V_182 = V_47 ;
F_46 ( V_2 , V_195 , sizeof( V_84 ) , & V_84 ) ;
}
int F_88 ( struct V_3 * V_4 , T_3 V_152 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_87 ( & V_2 , V_152 ) ;
return F_14 ( & V_2 , NULL ) ;
}
static void F_89 ( struct V_3 * V_4 , T_3 V_196 , T_4 V_22 )
{
F_4 ( L_12 , V_4 -> V_23 , V_196 ) ;
}
void F_90 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
if ( ! F_48 ( V_4 , V_197 ) &&
F_52 ( & V_4 -> V_198 ) )
return;
F_1 ( & V_2 , V_4 ) ;
if ( V_4 -> V_153 ) {
F_91 ( & V_2 , V_4 -> V_153 ,
true ) ;
} else {
F_87 ( & V_2 , 0x00 ) ;
F_84 ( & V_2 , 0x00 ) ;
F_78 ( & V_2 ) ;
}
F_14 ( & V_2 , F_89 ) ;
}
static void F_92 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
V_201 . V_200 ) ;
struct V_1 V_2 ;
T_3 V_152 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_94 ( V_4 ) ;
V_4 -> V_202 = 0 ;
V_152 = V_4 -> V_153 ;
if ( V_152 == 0x00 )
goto V_203;
F_1 ( & V_2 , V_4 ) ;
F_95 ( V_4 , & V_2 , V_152 , false ) ;
if ( F_52 ( & V_4 -> V_198 ) )
F_76 ( & V_2 ) ;
F_14 ( & V_2 , NULL ) ;
V_203:
F_96 ( V_4 ) ;
}
int F_91 ( struct V_1 * V_2 , T_3 V_152 ,
bool V_204 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_154 * V_155 = NULL ;
T_4 V_34 ;
if ( F_48 ( V_4 , V_197 ) ||
F_52 ( & V_4 -> V_198 ) )
return - V_205 ;
if ( V_4 -> V_202 )
return - V_206 ;
V_155 = F_75 ( V_4 , V_152 ) ;
if ( ! V_155 )
return - V_207 ;
if ( V_155 -> V_34 == 0 ||
V_155 -> V_208 <= V_155 -> V_209 )
V_34 = V_155 -> V_208 ;
else
V_34 = V_155 -> V_209 ;
if ( V_155 -> V_34 )
V_155 -> V_209 =
V_155 -> V_209 - V_34 ;
V_4 -> V_202 = V_34 ;
F_97 ( V_4 -> V_210 ,
& V_4 -> V_201 ,
F_98 ( V_34 * 1000 ) ) ;
if ( ! V_204 && V_4 -> V_153 == V_152 &&
F_48 ( V_4 , V_165 ) )
return 0 ;
V_4 -> V_153 = V_152 ;
F_87 ( V_2 , V_152 ) ;
F_84 ( V_2 , V_152 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static void F_99 ( struct V_3 * V_4 )
{
if ( V_4 -> V_202 ) {
V_4 -> V_202 = 0 ;
F_100 ( & V_4 -> V_201 ) ;
}
}
void F_95 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_3 V_152 , bool V_204 )
{
struct V_154 * V_155 , * V_211 , * V_212 = NULL ;
int V_6 ;
T_3 V_213 ;
if ( ! V_152 || V_4 -> V_153 == V_152 )
F_99 ( V_4 ) ;
if ( V_152 && V_4 -> V_153 == V_152 )
V_212 = F_101 ( V_4 , V_152 ) ;
if ( V_152 == 0x00 ) {
F_102 (adv_instance, n, &hdev->adv_instances,
list) {
if ( ! ( V_204 || V_155 -> V_34 ) )
continue;
V_213 = V_155 -> V_152 ;
V_6 = F_103 ( V_4 , V_213 ) ;
if ( ! V_6 )
F_104 ( NULL , V_4 , V_213 ) ;
}
} else {
V_155 = F_75 ( V_4 , V_152 ) ;
if ( V_204 || ( V_155 && V_155 -> V_34 &&
! V_155 -> V_209 ) ) {
if ( V_212 &&
V_212 -> V_152 == V_152 )
V_212 = NULL ;
V_6 = F_103 ( V_4 , V_152 ) ;
if ( ! V_6 )
F_104 ( NULL , V_4 , V_152 ) ;
}
}
if ( ! V_2 || ! F_65 ( V_4 ) ||
F_48 ( V_4 , V_197 ) )
return;
if ( V_212 )
F_91 ( V_2 , V_212 -> V_152 ,
false ) ;
}
static void F_105 ( struct V_1 * V_2 , T_9 * V_214 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_48 ( V_4 , V_165 ) ||
F_54 ( V_4 ) ) {
F_4 ( L_13 ) ;
F_106 ( V_4 , V_215 ) ;
return;
}
F_46 ( V_2 , V_216 , 6 , V_214 ) ;
}
int F_73 ( struct V_1 * V_2 , bool V_217 ,
T_3 * V_139 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( F_48 ( V_4 , V_141 ) ) {
int V_218 ;
* V_139 = V_219 ;
if ( ! F_107 ( V_4 , V_215 ) &&
! F_108 ( & V_4 -> V_220 , & V_4 -> V_214 ) )
return 0 ;
V_6 = F_109 ( V_4 , V_4 -> V_221 , & V_4 -> V_214 ) ;
if ( V_6 < 0 ) {
F_44 ( L_14 , V_4 -> V_23 ) ;
return V_6 ;
}
F_105 ( V_2 , & V_4 -> V_214 ) ;
V_218 = F_98 ( V_4 -> V_222 * 1000 ) ;
F_97 ( V_4 -> V_19 , & V_4 -> V_223 , V_218 ) ;
return 0 ;
}
if ( V_217 ) {
T_9 V_224 ;
while ( true ) {
F_110 ( & V_224 , 6 ) ;
V_224 . V_130 [ 5 ] &= 0x3f ;
if ( F_108 ( & V_4 -> V_126 , & V_224 ) )
break;
}
* V_139 = V_219 ;
F_105 ( V_2 , & V_224 ) ;
return 0 ;
}
if ( F_48 ( V_4 , V_225 ) ||
! F_108 ( & V_4 -> V_126 , V_226 ) ||
( ! F_48 ( V_4 , V_59 ) &&
F_108 ( & V_4 -> V_227 , V_226 ) ) ) {
* V_139 = V_219 ;
if ( F_108 ( & V_4 -> V_227 , & V_4 -> V_220 ) )
F_46 ( V_2 , V_216 , 6 ,
& V_4 -> V_227 ) ;
return 0 ;
}
* V_139 = V_228 ;
return 0 ;
}
static bool F_111 ( struct V_3 * V_4 )
{
struct V_129 * V_130 ;
F_58 (b, &hdev->whitelist, list) {
struct V_229 * V_230 ;
V_230 = F_112 ( V_4 , V_231 , & V_130 -> V_126 ) ;
if ( ! V_230 )
return true ;
if ( V_230 -> V_78 != V_232 && V_230 -> V_78 != V_233 )
return true ;
}
return false ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_234 ;
if ( ! F_48 ( V_4 , V_59 ) )
return;
if ( ! F_65 ( V_4 ) )
return;
if ( F_114 ( V_4 ) )
return;
if ( F_48 ( V_4 , V_235 ) ||
F_111 ( V_4 ) )
V_234 = V_236 ;
else
V_234 = V_237 ;
if ( F_48 ( V_4 , V_238 ) )
V_234 |= V_239 ;
if ( F_35 ( V_240 , & V_4 -> V_11 ) == ! ! ( V_234 & V_236 ) &&
F_35 ( V_241 , & V_4 -> V_11 ) == ! ! ( V_234 & V_239 ) )
return;
F_46 ( V_2 , V_242 , 1 , & V_234 ) ;
}
static int F_115 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_94 ( V_2 -> V_4 ) ;
F_113 ( V_2 ) ;
F_96 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_116 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 , V_243 ) ;
F_34 ( V_4 , F_115 , 0 , V_244 , NULL ) ;
}
static int F_117 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_94 ( V_4 ) ;
F_113 ( V_2 ) ;
if ( ! F_48 ( V_4 , V_59 ) )
F_87 ( V_2 , V_4 -> V_153 ) ;
if ( F_48 ( V_4 , V_197 ) ||
! F_52 ( & V_4 -> V_198 ) )
F_78 ( V_2 ) ;
F_50 ( V_2 ) ;
F_96 ( V_4 ) ;
return 0 ;
}
static void F_118 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_117 ) ;
T_3 V_196 ;
F_34 ( V_4 , F_117 , 0 , V_244 , & V_196 ) ;
F_119 ( V_4 , V_196 ) ;
}
static T_3 F_120 ( struct V_3 * V_4 )
{
struct V_90 * V_91 ;
T_3 V_245 = 0 ;
F_58 (uuid, &hdev->uuids, list)
V_245 |= V_91 -> V_246 ;
return V_245 ;
}
void F_121 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_247 [ 3 ] ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_65 ( V_4 ) )
return;
if ( ! F_48 ( V_4 , V_59 ) )
return;
if ( F_48 ( V_4 , V_115 ) )
return;
V_247 [ 0 ] = V_4 -> V_248 ;
V_247 [ 1 ] = V_4 -> V_249 ;
V_247 [ 2 ] = F_120 ( V_4 ) ;
if ( F_48 ( V_4 , V_250 ) )
V_247 [ 1 ] |= 0x20 ;
if ( memcmp ( V_247 , V_4 -> V_251 , 3 ) == 0 )
return;
F_46 ( V_2 , V_252 , sizeof( V_247 ) , V_247 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_253 V_84 ;
if ( ! F_48 ( V_4 , V_238 ) )
return;
if ( F_48 ( V_4 , V_250 ) ) {
V_84 . V_254 = F_123 ( T_3 , V_4 -> V_254 , 2 ) ;
V_84 . V_255 [ 0 ] = 0x00 ;
V_84 . V_255 [ 1 ] = 0x8b ;
V_84 . V_255 [ 2 ] = 0x9e ;
V_84 . V_255 [ 3 ] = 0x33 ;
V_84 . V_255 [ 4 ] = 0x8b ;
V_84 . V_255 [ 5 ] = 0x9e ;
} else {
V_84 . V_254 = 1 ;
V_84 . V_255 [ 0 ] = 0x33 ;
V_84 . V_255 [ 1 ] = 0x8b ;
V_84 . V_255 [ 2 ] = 0x9e ;
}
F_46 ( V_2 , V_256 ,
( V_84 . V_254 * 3 ) + 1 , & V_84 ) ;
}
static int F_124 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_94 ( V_4 ) ;
if ( F_48 ( V_4 , V_59 ) ) {
F_122 ( V_2 ) ;
F_113 ( V_2 ) ;
F_121 ( V_2 ) ;
}
if ( F_48 ( V_4 , V_197 ) )
F_87 ( V_2 , 0x00 ) ;
F_96 ( V_4 ) ;
return 0 ;
}
static void F_125 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_124 ) ;
T_3 V_196 ;
F_34 ( V_4 , F_124 , 0 , V_244 , & V_196 ) ;
F_126 ( V_4 , V_196 ) ;
}
void F_127 ( struct V_1 * V_2 , struct V_229 * V_230 ,
T_3 V_257 )
{
switch ( V_230 -> V_78 ) {
case V_232 :
case V_233 :
if ( V_230 -> type == V_258 ) {
struct V_259 V_84 ;
V_84 . V_260 = F_128 ( V_230 -> V_261 ) ;
V_84 . V_257 = V_257 ;
F_46 ( V_2 , V_262 , sizeof( V_84 ) ,
& V_84 ) ;
} else {
struct V_263 V_264 ;
V_264 . V_261 = F_41 ( V_230 -> V_261 ) ;
V_264 . V_257 = V_257 ;
F_46 ( V_2 , V_265 , sizeof( V_264 ) , & V_264 ) ;
}
V_230 -> V_78 = V_266 ;
break;
case V_267 :
if ( V_230 -> type == V_164 ) {
if ( F_35 ( V_268 , & V_230 -> V_11 ) )
break;
F_46 ( V_2 , V_269 ,
0 , NULL ) ;
} else if ( V_230 -> type == V_231 ) {
if ( V_2 -> V_4 -> V_60 < V_61 )
break;
F_46 ( V_2 , V_270 ,
6 , & V_230 -> V_271 ) ;
}
break;
case V_272 :
if ( V_230 -> type == V_231 ) {
struct V_273 V_274 ;
F_68 ( & V_274 . V_126 , & V_230 -> V_271 ) ;
V_274 . V_257 = V_257 ;
F_46 ( V_2 , V_275 ,
sizeof( V_274 ) , & V_274 ) ;
} else if ( V_230 -> type == V_276 || V_230 -> type == V_277 ) {
struct V_278 V_274 ;
F_68 ( & V_274 . V_126 , & V_230 -> V_271 ) ;
V_274 . V_257 = V_279 ;
F_46 ( V_2 , V_280 ,
sizeof( V_274 ) , & V_274 ) ;
}
break;
default:
V_230 -> V_78 = V_281 ;
break;
}
}
static void F_129 ( struct V_3 * V_4 , T_3 V_196 , T_4 V_22 )
{
if ( V_196 )
F_4 ( L_15 , V_196 ) ;
}
int F_130 ( struct V_229 * V_230 , T_3 V_257 )
{
struct V_1 V_2 ;
int V_6 ;
F_1 ( & V_2 , V_230 -> V_4 ) ;
F_127 ( & V_2 , V_230 , V_257 ) ;
V_6 = F_14 ( & V_2 , F_129 ) ;
if ( V_6 && V_6 != - V_12 ) {
F_44 ( L_16 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_94 ( V_2 -> V_4 ) ;
F_50 ( V_2 ) ;
F_96 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_132 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_132 ) ;
struct V_229 * V_230 ;
T_3 V_196 ;
int V_6 ;
V_6 = F_34 ( V_4 , F_131 , 0 , V_244 , & V_196 ) ;
if ( ! V_6 )
return;
F_94 ( V_4 ) ;
V_230 = F_133 ( V_4 , V_164 , V_267 ) ;
if ( V_230 )
F_134 ( V_230 , V_196 ) ;
F_96 ( V_4 ) ;
}
static int F_135 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_53 ( V_2 ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_3 V_182 = V_41 ;
const T_3 V_282 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
const T_3 V_283 [ 3 ] = { 0x00 , 0x8b , 0x9e } ;
struct V_284 V_84 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
F_94 ( V_2 -> V_4 ) ;
F_137 ( V_2 -> V_4 ) ;
F_96 ( V_2 -> V_4 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_2 -> V_4 -> V_77 . V_285 )
memcpy ( & V_84 . V_286 , V_283 , sizeof( V_84 . V_286 ) ) ;
else
memcpy ( & V_84 . V_286 , V_282 , sizeof( V_84 . V_286 ) ) ;
V_84 . V_182 = V_182 ;
F_46 ( V_2 , V_287 , sizeof( V_84 ) , & V_84 ) ;
return 0 ;
}
static void F_138 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_135 . V_200 ) ;
T_3 V_196 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( ! F_48 ( V_4 , V_82 ) )
return;
F_100 ( & V_4 -> V_288 ) ;
F_34 ( V_4 , F_135 , 0 , V_244 , & V_196 ) ;
if ( V_196 ) {
F_44 ( L_17 , V_196 ) ;
return;
}
V_4 -> V_77 . V_289 = 0 ;
if ( V_4 -> V_77 . type == V_290 )
goto V_291;
if ( V_4 -> V_77 . type != V_292 )
return;
if ( F_35 ( V_293 , & V_4 -> V_294 ) ) {
if ( ! F_35 ( V_295 , & V_4 -> V_11 ) &&
V_4 -> V_77 . V_78 != V_296 )
goto V_291;
return;
}
F_34 ( V_4 , F_136 , V_297 ,
V_244 , & V_196 ) ;
if ( V_196 ) {
F_44 ( L_18 , V_196 ) ;
goto V_291;
}
return;
V_291:
F_94 ( V_4 ) ;
F_139 ( V_4 , V_79 ) ;
F_96 ( V_4 ) ;
}
static int V_288 ( struct V_1 * V_2 , unsigned long V_41 )
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
static void F_140 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
V_288 . V_200 ) ;
unsigned long V_34 , V_208 , V_289 , V_298 ;
T_3 V_196 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_34 ( V_4 , V_288 , 0 , V_244 , & V_196 ) ;
if ( V_196 ) {
F_44 ( L_19 , V_196 ) ;
return;
}
F_94 ( V_4 ) ;
if ( ! F_35 ( V_299 , & V_4 -> V_294 ) ||
! V_4 -> V_77 . V_289 )
goto V_203;
V_208 = V_4 -> V_77 . V_300 ;
V_289 = V_4 -> V_77 . V_289 ;
V_298 = V_301 ;
if ( V_298 - V_289 <= V_208 ) {
int V_302 ;
if ( V_298 >= V_289 )
V_302 = V_298 - V_289 ;
else
V_302 = V_303 - V_289 + V_298 ;
V_34 = V_208 - V_302 ;
} else {
V_34 = 0 ;
}
F_97 ( V_4 -> V_210 ,
& V_4 -> F_135 , V_34 ) ;
V_203:
F_96 ( V_4 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
T_3 V_56 = 0x00 ;
F_46 ( V_2 , V_157 , sizeof( V_56 ) , & V_56 ) ;
}
static int F_142 ( struct V_1 * V_2 , unsigned long V_41 )
{
T_10 V_63 = V_41 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 V_137 ;
struct V_118 V_138 ;
T_3 V_139 ;
int V_6 ;
F_4 ( L_4 , V_4 -> V_23 ) ;
if ( F_48 ( V_4 , V_165 ) ) {
F_94 ( V_4 ) ;
if ( F_54 ( V_4 ) ) {
F_96 ( V_4 ) ;
return - V_206 ;
}
F_99 ( V_4 ) ;
F_96 ( V_4 ) ;
F_141 ( V_2 ) ;
}
if ( F_48 ( V_4 , V_82 ) )
F_53 ( V_2 ) ;
V_6 = F_73 ( V_2 , true , & V_139 ) ;
if ( V_6 < 0 )
V_139 = V_228 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . type = V_304 ;
V_137 . V_63 = F_41 ( V_63 ) ;
V_137 . V_65 = F_41 ( V_305 ) ;
V_137 . V_147 = V_139 ;
F_46 ( V_2 , V_148 , sizeof( V_137 ) ,
& V_137 ) ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_56 = V_149 ;
V_138 . V_150 = V_151 ;
F_46 ( V_2 , V_120 , sizeof( V_138 ) ,
& V_138 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 , unsigned long V_41 )
{
int V_6 ;
F_4 ( L_4 , V_2 -> V_4 -> V_23 ) ;
V_6 = F_142 ( V_2 , V_41 ) ;
if ( V_6 )
return V_6 ;
return F_136 ( V_2 , V_306 ) ;
}
static void F_144 ( struct V_3 * V_4 , T_3 * V_196 )
{
unsigned long V_34 ;
F_4 ( L_20 , V_4 -> V_23 , V_4 -> V_77 . type ) ;
switch ( V_4 -> V_77 . type ) {
case V_307 :
if ( ! F_48 ( V_4 , V_295 ) )
F_34 ( V_4 , F_136 ,
V_306 , V_244 ,
V_196 ) ;
return;
case V_292 :
if ( F_35 ( V_293 ,
& V_4 -> V_294 ) ) {
V_34 = F_98 ( V_308 ) ;
F_34 ( V_4 , F_143 ,
V_309 * 2 , V_244 ,
V_196 ) ;
break;
}
V_34 = F_98 ( V_4 -> V_310 ) ;
F_34 ( V_4 , F_142 , V_309 ,
V_244 , V_196 ) ;
break;
case V_290 :
V_34 = F_98 ( V_308 ) ;
F_34 ( V_4 , F_142 , V_309 ,
V_244 , V_196 ) ;
break;
default:
* V_196 = V_43 ;
return;
}
if ( * V_196 )
return;
F_4 ( L_21 , V_4 -> V_23 , F_145 ( V_34 ) ) ;
if ( F_35 ( V_299 , & V_4 -> V_294 ) &&
V_4 -> V_77 . V_311 ) {
V_4 -> V_77 . V_289 = V_301 ;
V_4 -> V_77 . V_300 = V_34 ;
}
F_97 ( V_4 -> V_210 , & V_4 -> F_135 ,
V_34 ) ;
}
bool F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_312 * V_313 = & V_4 -> V_77 ;
struct V_314 V_84 ;
struct V_315 * V_316 ;
bool V_44 = false ;
F_4 ( L_22 , V_4 -> V_23 , V_4 -> V_77 . V_78 ) ;
if ( V_313 -> V_78 == V_317 || V_313 -> V_78 == V_318 ) {
if ( F_35 ( V_295 , & V_4 -> V_11 ) )
F_46 ( V_2 , V_319 , 0 , NULL ) ;
if ( F_48 ( V_4 , V_82 ) ) {
F_100 ( & V_4 -> F_135 ) ;
F_53 ( V_2 ) ;
}
V_44 = true ;
} else {
if ( F_48 ( V_4 , V_82 ) ) {
F_53 ( V_2 ) ;
V_44 = true ;
}
}
if ( V_313 -> type == V_290 )
return V_44 ;
if ( V_313 -> V_78 == V_296 || V_313 -> V_78 == V_318 ) {
V_316 = F_147 ( V_4 , V_226 ,
V_320 ) ;
if ( ! V_316 )
return V_44 ;
F_68 ( & V_84 . V_126 , & V_316 -> V_87 . V_126 ) ;
F_46 ( V_2 , V_321 , sizeof( V_84 ) ,
& V_84 ) ;
V_44 = true ;
}
return V_44 ;
}
static int F_148 ( struct V_1 * V_2 , unsigned long V_41 )
{
F_94 ( V_2 -> V_4 ) ;
F_146 ( V_2 ) ;
F_96 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_149 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_149 ) ;
T_3 V_196 = 0 ;
switch ( V_4 -> V_77 . V_78 ) {
case V_322 :
F_144 ( V_4 , & V_196 ) ;
F_150 ( V_4 , V_196 ) ;
if ( V_196 )
F_139 ( V_4 , V_79 ) ;
else
F_139 ( V_4 , V_317 ) ;
break;
case V_318 :
F_34 ( V_4 , F_148 , 0 , V_244 , & V_196 ) ;
F_151 ( V_4 , V_196 ) ;
if ( ! V_196 )
F_139 ( V_4 , V_79 ) ;
break;
case V_79 :
default:
return;
}
}
static void F_152 ( struct V_199 * V_200 )
{
struct V_3 * V_4 = F_93 ( V_200 , struct V_3 ,
F_152 . V_200 ) ;
F_4 ( L_4 , V_4 -> V_23 ) ;
F_94 ( V_4 ) ;
F_80 ( V_4 , V_250 ) ;
F_80 ( V_4 , V_238 ) ;
V_4 -> V_323 = 0 ;
F_96 ( V_4 ) ;
F_34 ( V_4 , F_124 , 0 , V_244 , NULL ) ;
F_153 ( V_4 ) ;
}
static int F_154 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_324 ;
F_94 ( V_4 ) ;
if ( F_48 ( V_4 , V_114 ) &&
! F_155 ( V_4 ) ) {
T_3 V_325 = 0x01 ;
F_46 ( V_2 , V_326 , sizeof( V_325 ) , & V_325 ) ;
if ( F_156 ( V_4 ) && ! F_157 ( V_4 ) ) {
T_3 V_327 = 0x01 ;
F_46 ( V_2 , V_328 ,
sizeof( V_327 ) , & V_327 ) ;
}
}
if ( F_48 ( V_4 , V_76 ) &&
F_158 ( V_4 ) ) {
struct V_329 V_84 ;
V_84 . V_330 = 0x01 ;
V_84 . V_331 = 0x00 ;
if ( V_84 . V_330 != F_159 ( V_4 ) ||
V_84 . V_331 != F_160 ( V_4 ) )
F_46 ( V_2 , V_332 ,
sizeof( V_84 ) , & V_84 ) ;
}
if ( F_48 ( V_4 , V_76 ) ) {
if ( F_48 ( V_4 , V_197 ) ||
F_52 ( & V_4 -> V_198 ) ) {
F_87 ( V_2 , 0x00 ) ;
F_84 ( V_2 , 0x00 ) ;
if ( F_48 ( V_4 , V_197 ) )
F_78 ( V_2 ) ;
} else if ( ! F_52 ( & V_4 -> V_198 ) ) {
struct V_154 * V_155 ;
V_155 = F_161 ( & V_4 -> V_198 ,
struct V_154 , V_333 ) ;
F_91 ( V_2 ,
V_155 -> V_152 ,
true ) ;
}
}
V_324 = F_48 ( V_4 , V_334 ) ;
if ( V_324 != F_35 ( V_335 , & V_4 -> V_11 ) )
F_46 ( V_2 , V_336 ,
sizeof( V_324 ) , & V_324 ) ;
if ( F_158 ( V_4 ) ) {
if ( F_48 ( V_4 , V_337 ) )
F_47 ( V_2 , true ) ;
else
F_47 ( V_2 , false ) ;
F_113 ( V_2 ) ;
F_121 ( V_2 ) ;
F_56 ( V_2 ) ;
F_64 ( V_2 ) ;
}
F_96 ( V_4 ) ;
return 0 ;
}
int F_162 ( struct V_3 * V_4 )
{
F_163 ( V_4 ) ;
return F_32 ( V_4 , F_154 , 0 , V_244 ,
NULL ) ;
}
void F_164 ( struct V_3 * V_4 )
{
F_165 ( & V_4 -> F_149 , F_149 ) ;
F_165 ( & V_4 -> F_132 , F_132 ) ;
F_165 ( & V_4 -> V_243 , F_116 ) ;
F_165 ( & V_4 -> F_117 , F_118 ) ;
F_165 ( & V_4 -> F_124 , F_125 ) ;
F_166 ( & V_4 -> F_152 , F_152 ) ;
F_166 ( & V_4 -> F_135 , F_138 ) ;
F_166 ( & V_4 -> V_288 , F_140 ) ;
F_166 ( & V_4 -> V_201 , F_92 ) ;
}
void F_167 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_338 ) ;
F_168 ( & V_4 -> F_149 ) ;
F_168 ( & V_4 -> F_132 ) ;
F_168 ( & V_4 -> V_243 ) ;
F_168 ( & V_4 -> F_117 ) ;
F_168 ( & V_4 -> F_124 ) ;
F_169 ( & V_4 -> F_152 ) ;
F_169 ( & V_4 -> F_135 ) ;
F_169 ( & V_4 -> V_288 ) ;
if ( V_4 -> V_202 ) {
F_169 ( & V_4 -> V_201 ) ;
V_4 -> V_202 = 0 ;
}
}
