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
F_9 ( V_10 ) -> V_13 . V_14 = V_7 ;
F_9 ( V_10 ) -> V_13 . V_15 = V_8 ;
F_10 ( & V_4 -> V_5 . V_16 , V_11 ) ;
F_11 ( & V_2 -> V_5 , & V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_5 . V_16 , V_11 ) ;
F_13 ( V_4 -> V_17 , & V_4 -> V_18 ) ;
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
struct V_9 * F_16 ( struct V_3 * V_4 , T_3 V_19 , T_4 V_20 ,
const void * V_21 )
{
int V_22 = V_23 + V_20 ;
struct V_24 * V_25 ;
struct V_9 * V_10 ;
V_10 = F_17 ( V_22 , V_26 ) ;
if ( ! V_10 )
return NULL ;
V_25 = (struct V_24 * ) F_18 ( V_10 , V_23 ) ;
V_25 -> V_19 = F_19 ( V_19 ) ;
V_25 -> V_20 = V_20 ;
if ( V_20 )
memcpy ( F_18 ( V_10 , V_20 ) , V_21 , V_20 ) ;
F_4 ( L_2 , V_10 -> V_22 ) ;
F_9 ( V_10 ) -> V_27 = V_28 ;
F_9 ( V_10 ) -> V_13 . V_19 = V_19 ;
return V_10 ;
}
void F_20 ( struct V_1 * V_2 , T_3 V_19 , T_4 V_20 ,
const void * V_21 , T_5 V_29 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
F_4 ( L_3 , V_4 -> V_30 , V_19 , V_20 ) ;
if ( V_2 -> V_6 )
return;
V_10 = F_16 ( V_4 , V_19 , V_20 , V_21 ) ;
if ( ! V_10 ) {
F_21 ( L_4 ,
V_4 -> V_30 , V_19 ) ;
V_2 -> V_6 = - V_31 ;
return;
}
if ( F_7 ( & V_2 -> V_5 ) )
F_9 ( V_10 ) -> V_13 . V_32 = true ;
F_9 ( V_10 ) -> V_13 . V_33 = V_29 ;
F_22 ( & V_2 -> V_5 , V_10 ) ;
}
void F_23 ( struct V_1 * V_2 , T_3 V_19 , T_4 V_20 ,
const void * V_21 )
{
F_20 ( V_2 , V_19 , V_20 , V_21 , 0 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_34 V_35 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_36 = V_37 ;
F_23 ( V_2 , V_38 , sizeof( V_35 ) , & V_35 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_41 V_35 ;
V_35 . V_42 = V_40 -> V_43 ;
F_26 ( & V_35 . V_44 , & V_40 -> V_45 ) ;
F_23 ( V_2 , V_46 , sizeof( V_35 ) , & V_35 ) ;
}
static T_5 F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_40 ;
struct V_47 * V_48 ;
T_6 V_49 = 0 ;
F_28 (b, &hdev->le_white_list, list) {
struct V_50 V_35 ;
if ( F_29 ( & V_4 -> V_51 ,
& V_48 -> V_44 , V_48 -> V_42 ) ||
F_29 ( & V_4 -> V_52 ,
& V_48 -> V_44 , V_48 -> V_42 ) ) {
V_49 ++ ;
continue;
}
V_35 . V_42 = V_48 -> V_42 ;
F_26 ( & V_35 . V_44 , & V_48 -> V_44 ) ;
F_23 ( V_2 , V_53 ,
sizeof( V_35 ) , & V_35 ) ;
}
F_28 (params, &hdev->pend_le_conns, action) {
if ( F_30 ( & V_4 -> V_54 ,
& V_40 -> V_45 , V_40 -> V_43 ) )
continue;
if ( V_49 >= V_4 -> V_55 ) {
return 0x00 ;
}
if ( F_31 ( V_4 , & V_40 -> V_45 ,
V_40 -> V_43 ) ) {
return 0x00 ;
}
V_49 ++ ;
F_25 ( V_2 , V_40 ) ;
}
F_28 (params, &hdev->pend_le_reports, action) {
if ( F_30 ( & V_4 -> V_54 ,
& V_40 -> V_45 , V_40 -> V_43 ) )
continue;
if ( V_49 >= V_4 -> V_55 ) {
return 0x00 ;
}
if ( F_31 ( V_4 , & V_40 -> V_45 ,
V_40 -> V_43 ) ) {
return 0x00 ;
}
V_49 ++ ;
F_25 ( V_2 , V_40 ) ;
}
return 0x01 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_56 V_57 ;
struct V_34 V_58 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_59 ;
T_5 V_60 ;
if ( F_33 ( V_2 , false , & V_59 ) )
return;
V_60 = F_27 ( V_2 ) ;
if ( F_34 ( V_4 , V_61 ) &&
( V_4 -> V_62 [ 0 ] & V_63 ) )
V_60 |= 0x02 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . type = V_64 ;
V_57 . V_65 = F_19 ( V_4 -> V_66 ) ;
V_57 . V_67 = F_19 ( V_4 -> V_68 ) ;
V_57 . V_69 = V_59 ;
V_57 . V_60 = V_60 ;
F_23 ( V_2 , V_70 , sizeof( V_57 ) ,
& V_57 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_36 = V_71 ;
V_58 . V_72 = V_73 ;
F_23 ( V_2 , V_38 , sizeof( V_58 ) ,
& V_58 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_7 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_34 ( V_4 , V_75 ) ||
F_36 ( V_4 ) ) {
F_4 ( L_5 ) ;
F_37 ( V_4 , V_76 ) ;
return;
}
F_23 ( V_2 , V_77 , 6 , V_74 ) ;
}
int F_33 ( struct V_1 * V_2 , bool V_78 ,
T_5 * V_59 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( F_34 ( V_4 , V_61 ) ) {
int V_79 ;
* V_59 = V_80 ;
if ( ! F_38 ( V_4 , V_76 ) &&
! F_39 ( & V_4 -> V_81 , & V_4 -> V_74 ) )
return 0 ;
V_6 = F_40 ( V_4 , V_4 -> V_82 , & V_4 -> V_74 ) ;
if ( V_6 < 0 ) {
F_21 ( L_6 , V_4 -> V_30 ) ;
return V_6 ;
}
F_35 ( V_2 , & V_4 -> V_74 ) ;
V_79 = F_41 ( V_4 -> V_83 * 1000 ) ;
F_42 ( V_4 -> V_17 , & V_4 -> V_84 , V_79 ) ;
return 0 ;
}
if ( V_78 ) {
T_7 V_85 ;
while ( true ) {
F_43 ( & V_85 , 6 ) ;
V_85 . V_48 [ 5 ] &= 0x3f ;
if ( F_39 ( & V_4 -> V_44 , & V_85 ) )
break;
}
* V_59 = V_80 ;
F_35 ( V_2 , & V_85 ) ;
return 0 ;
}
if ( F_34 ( V_4 , V_86 ) ||
! F_39 ( & V_4 -> V_44 , V_87 ) ||
( ! F_34 ( V_4 , V_88 ) &&
F_39 ( & V_4 -> V_89 , V_87 ) ) ) {
* V_59 = V_80 ;
if ( F_39 ( & V_4 -> V_89 , & V_4 -> V_81 ) )
F_23 ( V_2 , V_77 , 6 ,
& V_4 -> V_89 ) ;
return 0 ;
}
* V_59 = V_90 ;
return 0 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
struct V_47 * V_48 ;
F_28 (b, &hdev->whitelist, list) {
struct V_91 * V_92 ;
V_92 = F_45 ( V_4 , V_93 , & V_48 -> V_44 ) ;
if ( ! V_92 )
return true ;
if ( V_92 -> V_94 != V_95 && V_92 -> V_94 != V_96 )
return true ;
}
return false ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_97 ;
if ( ! F_34 ( V_4 , V_88 ) )
return;
if ( ! F_47 ( V_4 ) )
return;
if ( F_48 ( V_4 ) )
return;
if ( F_34 ( V_4 , V_98 ) ||
F_44 ( V_4 ) )
V_97 = V_99 ;
else
V_97 = V_100 ;
if ( F_49 ( V_101 , & V_4 -> V_11 ) == ! ! ( V_97 & V_99 ) )
return;
if ( F_34 ( V_4 , V_102 ) )
V_97 |= V_103 ;
F_23 ( V_2 , V_104 , 1 , & V_97 ) ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_46 ( & V_2 ) ;
F_14 ( & V_2 , NULL ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_49 ( V_105 , & V_4 -> V_11 ) ||
F_49 ( V_106 , & V_4 -> V_11 ) ||
F_34 ( V_4 , V_107 ) ||
F_34 ( V_4 , V_108 ) ||
F_34 ( V_4 , V_109 ) ||
F_34 ( V_4 , V_110 ) )
return;
if ( ! F_34 ( V_4 , V_111 ) )
return;
if ( V_4 -> V_112 . V_94 != V_113 )
return;
F_52 ( V_4 ) ;
if ( F_53 ( & V_4 -> V_51 ) &&
F_53 ( & V_4 -> V_52 ) ) {
if ( ! F_34 ( V_4 , V_114 ) )
return;
F_24 ( V_2 ) ;
F_4 ( L_7 , V_4 -> V_30 ) ;
} else {
if ( F_36 ( V_4 ) )
return;
if ( F_34 ( V_4 , V_114 ) )
F_24 ( V_2 ) ;
F_32 ( V_2 ) ;
F_4 ( L_8 , V_4 -> V_30 ) ;
}
}
static void F_54 ( struct V_3 * V_4 , T_5 V_115 ,
T_3 V_19 )
{
if ( V_115 )
F_4 ( L_9
L_10 , V_115 ) ;
}
void F_55 ( struct V_3 * V_4 )
{
int V_6 ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_51 ( & V_2 ) ;
V_6 = F_14 ( & V_2 , F_54 ) ;
if ( V_6 && V_6 != - V_12 )
F_21 ( L_11 , V_6 ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_91 * V_92 ,
T_5 V_116 )
{
switch ( V_92 -> V_94 ) {
case V_95 :
case V_96 :
if ( V_92 -> type == V_117 ) {
struct V_118 V_35 ;
V_35 . V_119 = F_57 ( V_92 -> V_120 ) ;
V_35 . V_116 = V_116 ;
F_23 ( V_2 , V_121 , sizeof( V_35 ) ,
& V_35 ) ;
} else {
struct V_122 V_123 ;
V_123 . V_120 = F_19 ( V_92 -> V_120 ) ;
V_123 . V_116 = V_116 ;
F_23 ( V_2 , V_124 , sizeof( V_123 ) , & V_123 ) ;
}
V_92 -> V_94 = V_125 ;
break;
case V_126 :
if ( V_92 -> type == V_127 ) {
if ( F_49 ( V_128 , & V_92 -> V_11 ) )
break;
F_23 ( V_2 , V_129 ,
0 , NULL ) ;
} else if ( V_92 -> type == V_93 ) {
if ( V_2 -> V_4 -> V_130 < V_131 )
break;
F_23 ( V_2 , V_132 ,
6 , & V_92 -> V_133 ) ;
}
break;
case V_134 :
if ( V_92 -> type == V_93 ) {
struct V_135 V_136 ;
F_26 ( & V_136 . V_44 , & V_92 -> V_133 ) ;
V_136 . V_116 = V_116 ;
F_23 ( V_2 , V_137 ,
sizeof( V_136 ) , & V_136 ) ;
} else if ( V_92 -> type == V_138 || V_92 -> type == V_139 ) {
struct V_140 V_136 ;
F_26 ( & V_136 . V_44 , & V_92 -> V_133 ) ;
V_136 . V_116 = V_141 ;
F_23 ( V_2 , V_142 ,
sizeof( V_136 ) , & V_136 ) ;
}
break;
default:
V_92 -> V_94 = V_143 ;
break;
}
}
static void F_58 ( struct V_3 * V_4 , T_5 V_115 , T_3 V_19 )
{
if ( V_115 )
F_4 ( L_12 , V_115 ) ;
}
int F_59 ( struct V_91 * V_92 , T_5 V_116 )
{
struct V_1 V_2 ;
int V_6 ;
F_1 ( & V_2 , V_92 -> V_4 ) ;
F_56 ( & V_2 , V_92 , V_116 ) ;
V_6 = F_14 ( & V_2 , F_58 ) ;
if ( V_6 && V_6 != - V_12 ) {
F_21 ( L_11 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
