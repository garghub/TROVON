void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = 0 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_4 ( L_1 , F_5 ( & V_2 -> V_5 ) ) ;
if ( V_2 -> V_6 ) {
F_6 ( & V_2 -> V_5 ) ;
return V_2 -> V_6 ;
}
if ( F_7 ( & V_2 -> V_5 ) )
return - V_11 ;
V_9 = F_8 ( & V_2 -> V_5 ) ;
F_9 ( V_9 ) -> V_2 . V_7 = V_7 ;
F_10 ( & V_4 -> V_5 . V_12 , V_10 ) ;
F_11 ( & V_2 -> V_5 , & V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_5 . V_12 , V_10 ) ;
F_13 ( V_4 -> V_13 , & V_4 -> V_14 ) ;
return 0 ;
}
struct V_8 * F_14 ( struct V_3 * V_4 , T_2 V_15 , T_3 V_16 ,
const void * V_17 )
{
int V_18 = V_19 + V_16 ;
struct V_20 * V_21 ;
struct V_8 * V_9 ;
V_9 = F_15 ( V_18 , V_22 ) ;
if ( ! V_9 )
return NULL ;
V_21 = (struct V_20 * ) F_16 ( V_9 , V_19 ) ;
V_21 -> V_15 = F_17 ( V_15 ) ;
V_21 -> V_16 = V_16 ;
if ( V_16 )
memcpy ( F_16 ( V_9 , V_16 ) , V_17 , V_16 ) ;
F_4 ( L_2 , V_9 -> V_18 ) ;
F_9 ( V_9 ) -> V_23 = V_24 ;
F_9 ( V_9 ) -> V_15 = V_15 ;
return V_9 ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_15 , T_3 V_16 ,
const void * V_17 , T_4 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
F_4 ( L_3 , V_4 -> V_26 , V_15 , V_16 ) ;
if ( V_2 -> V_6 )
return;
V_9 = F_14 ( V_4 , V_15 , V_16 , V_17 ) ;
if ( ! V_9 ) {
F_19 ( L_4 ,
V_4 -> V_26 , V_15 ) ;
V_2 -> V_6 = - V_27 ;
return;
}
if ( F_7 ( & V_2 -> V_5 ) )
F_9 ( V_9 ) -> V_2 . V_28 = true ;
F_9 ( V_9 ) -> V_2 . V_25 = V_25 ;
F_20 ( & V_2 -> V_5 , V_9 ) ;
}
void F_21 ( struct V_1 * V_2 , T_2 V_15 , T_3 V_16 ,
const void * V_17 )
{
F_18 ( V_2 , V_15 , V_16 , V_17 , 0 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_29 V_30 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_31 = V_32 ;
F_21 ( V_2 , V_33 , sizeof( V_30 ) , & V_30 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_36 V_30 ;
V_30 . V_37 = V_35 -> V_38 ;
F_24 ( & V_30 . V_39 , & V_35 -> V_40 ) ;
F_21 ( V_2 , V_41 , sizeof( V_30 ) , & V_30 ) ;
}
static T_4 F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_34 * V_35 ;
struct V_42 * V_43 ;
T_5 V_44 = 0 ;
F_26 (b, &hdev->le_white_list, list) {
struct V_45 V_30 ;
if ( F_27 ( & V_4 -> V_46 ,
& V_43 -> V_39 , V_43 -> V_37 ) ||
F_27 ( & V_4 -> V_47 ,
& V_43 -> V_39 , V_43 -> V_37 ) ) {
V_44 ++ ;
continue;
}
V_30 . V_37 = V_43 -> V_37 ;
F_24 ( & V_30 . V_39 , & V_43 -> V_39 ) ;
F_21 ( V_2 , V_48 ,
sizeof( V_30 ) , & V_30 ) ;
}
F_26 (params, &hdev->pend_le_conns, action) {
if ( F_28 ( & V_4 -> V_49 ,
& V_35 -> V_40 , V_35 -> V_38 ) )
continue;
if ( V_44 >= V_4 -> V_50 ) {
return 0x00 ;
}
if ( F_29 ( V_4 , & V_35 -> V_40 ,
V_35 -> V_38 ) ) {
return 0x00 ;
}
V_44 ++ ;
F_23 ( V_2 , V_35 ) ;
}
F_26 (params, &hdev->pend_le_reports, action) {
if ( F_28 ( & V_4 -> V_49 ,
& V_35 -> V_40 , V_35 -> V_38 ) )
continue;
if ( V_44 >= V_4 -> V_50 ) {
return 0x00 ;
}
if ( F_29 ( V_4 , & V_35 -> V_40 ,
V_35 -> V_38 ) ) {
return 0x00 ;
}
V_44 ++ ;
F_23 ( V_2 , V_35 ) ;
}
return 0x01 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_51 V_52 ;
struct V_29 V_53 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_4 V_54 ;
T_4 V_55 ;
if ( F_31 ( V_2 , false , & V_54 ) )
return;
V_55 = F_25 ( V_2 ) ;
if ( F_32 ( V_56 , & V_4 -> V_57 ) &&
( V_4 -> V_58 [ 0 ] & V_59 ) )
V_55 |= 0x02 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . type = V_60 ;
V_52 . V_61 = F_17 ( V_4 -> V_62 ) ;
V_52 . V_63 = F_17 ( V_4 -> V_64 ) ;
V_52 . V_65 = V_54 ;
V_52 . V_55 = V_55 ;
F_21 ( V_2 , V_66 , sizeof( V_52 ) ,
& V_52 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_31 = V_67 ;
V_53 . V_68 = V_69 ;
F_21 ( V_2 , V_33 , sizeof( V_53 ) ,
& V_53 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_6 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_32 ( V_71 , & V_4 -> V_57 ) ||
F_34 ( V_4 , V_72 , V_73 ) ) {
F_4 ( L_5 ) ;
F_35 ( V_74 , & V_4 -> V_57 ) ;
return;
}
F_21 ( V_2 , V_75 , 6 , V_70 ) ;
}
int F_31 ( struct V_1 * V_2 , bool V_76 ,
T_4 * V_54 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( F_32 ( V_56 , & V_4 -> V_57 ) ) {
int V_77 ;
* V_54 = V_78 ;
if ( ! F_36 ( V_74 , & V_4 -> V_57 ) &&
! F_37 ( & V_4 -> V_79 , & V_4 -> V_70 ) )
return 0 ;
V_6 = F_38 ( V_4 , V_4 -> V_80 , & V_4 -> V_70 ) ;
if ( V_6 < 0 ) {
F_19 ( L_6 , V_4 -> V_26 ) ;
return V_6 ;
}
F_33 ( V_2 , & V_4 -> V_70 ) ;
V_77 = F_39 ( V_4 -> V_81 * 1000 ) ;
F_40 ( V_4 -> V_13 , & V_4 -> V_82 , V_77 ) ;
return 0 ;
}
if ( V_76 ) {
T_6 V_83 ;
while ( true ) {
F_41 ( & V_83 , 6 ) ;
V_83 . V_43 [ 5 ] &= 0x3f ;
if ( F_37 ( & V_4 -> V_39 , & V_83 ) )
break;
}
* V_54 = V_78 ;
F_33 ( V_2 , & V_83 ) ;
return 0 ;
}
if ( F_32 ( V_84 , & V_4 -> V_85 ) ||
! F_37 ( & V_4 -> V_39 , V_86 ) ||
( ! F_32 ( V_87 , & V_4 -> V_57 ) &&
F_37 ( & V_4 -> V_88 , V_86 ) ) ) {
* V_54 = V_78 ;
if ( F_37 ( & V_4 -> V_88 , & V_4 -> V_79 ) )
F_21 ( V_2 , V_75 , 6 ,
& V_4 -> V_88 ) ;
return 0 ;
}
* V_54 = V_89 ;
return 0 ;
}
static bool F_42 ( struct V_3 * V_4 )
{
struct V_42 * V_43 ;
F_26 (b, &hdev->whitelist, list) {
struct V_90 * V_91 ;
V_91 = F_43 ( V_4 , V_92 , & V_43 -> V_39 ) ;
if ( ! V_91 )
return true ;
if ( V_91 -> V_93 != V_94 && V_91 -> V_93 != V_95 )
return true ;
}
return false ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_4 V_96 ;
if ( ! F_32 ( V_87 , & V_4 -> V_57 ) )
return;
if ( ! F_45 ( V_4 ) )
return;
if ( F_46 ( V_4 ) )
return;
if ( F_32 ( V_97 , & V_4 -> V_57 ) ||
F_42 ( V_4 ) )
V_96 = V_98 ;
else
V_96 = V_99 ;
if ( F_32 ( V_100 , & V_4 -> V_10 ) == ! ! ( V_96 & V_98 ) )
return;
if ( F_32 ( V_101 , & V_4 -> V_57 ) )
V_96 |= V_102 ;
F_21 ( V_2 , V_103 , 1 , & V_96 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_44 ( & V_2 ) ;
F_3 ( & V_2 , NULL ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_90 * V_91 ;
if ( ! F_32 ( V_104 , & V_4 -> V_10 ) ||
F_32 ( V_105 , & V_4 -> V_10 ) ||
F_32 ( V_106 , & V_4 -> V_57 ) ||
F_32 ( V_107 , & V_4 -> V_57 ) ||
F_32 ( V_108 , & V_4 -> V_57 ) ||
F_32 ( V_109 , & V_4 -> V_57 ) )
return;
if ( ! F_32 ( V_110 , & V_4 -> V_57 ) )
return;
if ( V_4 -> V_111 . V_93 != V_112 )
return;
F_49 ( V_4 ) ;
if ( F_50 ( & V_4 -> V_46 ) &&
F_50 ( & V_4 -> V_47 ) ) {
if ( ! F_32 ( V_113 , & V_4 -> V_57 ) )
return;
F_22 ( V_2 ) ;
F_4 ( L_7 , V_4 -> V_26 ) ;
} else {
V_91 = F_34 ( V_4 , V_72 , V_73 ) ;
if ( V_91 )
return;
if ( F_32 ( V_113 , & V_4 -> V_57 ) )
F_22 ( V_2 ) ;
F_30 ( V_2 ) ;
F_4 ( L_8 , V_4 -> V_26 ) ;
}
}
static void F_51 ( struct V_3 * V_4 , T_4 V_114 ,
T_2 V_15 )
{
if ( V_114 )
F_4 ( L_9
L_10 , V_114 ) ;
}
void F_52 ( struct V_3 * V_4 )
{
int V_6 ;
struct V_1 V_2 ;
F_1 ( & V_2 , V_4 ) ;
F_48 ( & V_2 ) ;
V_6 = F_3 ( & V_2 , F_51 ) ;
if ( V_6 && V_6 != - V_11 )
F_19 ( L_11 , V_6 ) ;
}
