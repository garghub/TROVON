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
F_9 ( V_10 ) -> V_2 . V_7 = V_7 ;
F_9 ( V_10 ) -> V_2 . V_8 = V_8 ;
F_10 ( & V_4 -> V_5 . V_13 , V_11 ) ;
F_11 ( & V_2 -> V_5 , & V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_5 . V_13 , V_11 ) ;
F_13 ( V_4 -> V_14 , & V_4 -> V_15 ) ;
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
struct V_9 * F_16 ( struct V_3 * V_4 , T_3 V_16 , T_4 V_17 ,
const void * V_18 )
{
int V_19 = V_20 + V_17 ;
struct V_21 * V_22 ;
struct V_9 * V_10 ;
V_10 = F_17 ( V_19 , V_23 ) ;
if ( ! V_10 )
return NULL ;
V_22 = (struct V_21 * ) F_18 ( V_10 , V_20 ) ;
V_22 -> V_16 = F_19 ( V_16 ) ;
V_22 -> V_17 = V_17 ;
if ( V_17 )
memcpy ( F_18 ( V_10 , V_17 ) , V_18 , V_17 ) ;
F_4 ( L_2 , V_10 -> V_19 ) ;
F_9 ( V_10 ) -> V_24 = V_25 ;
F_9 ( V_10 ) -> V_16 = V_16 ;
return V_10 ;
}
void F_20 ( struct V_1 * V_2 , T_3 V_16 , T_4 V_17 ,
const void * V_18 , T_5 V_26 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
F_4 ( L_3 , V_4 -> V_27 , V_16 , V_17 ) ;
if ( V_2 -> V_6 )
return;
V_10 = F_16 ( V_4 , V_16 , V_17 , V_18 ) ;
if ( ! V_10 ) {
F_21 ( L_4 ,
V_4 -> V_27 , V_16 ) ;
V_2 -> V_6 = - V_28 ;
return;
}
if ( F_7 ( & V_2 -> V_5 ) )
F_9 ( V_10 ) -> V_2 . V_29 = true ;
F_9 ( V_10 ) -> V_2 . V_26 = V_26 ;
F_22 ( & V_2 -> V_5 , V_10 ) ;
}
void F_23 ( struct V_1 * V_2 , T_3 V_16 , T_4 V_17 ,
const void * V_18 )
{
F_20 ( V_2 , V_16 , V_17 , V_18 , 0 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = V_33 ;
F_23 ( V_2 , V_34 , sizeof( V_31 ) , & V_31 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_37 V_31 ;
V_31 . V_38 = V_36 -> V_39 ;
F_26 ( & V_31 . V_40 , & V_36 -> V_41 ) ;
F_23 ( V_2 , V_42 , sizeof( V_31 ) , & V_31 ) ;
}
static T_5 F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_35 * V_36 ;
struct V_43 * V_44 ;
T_6 V_45 = 0 ;
F_28 (b, &hdev->le_white_list, list) {
struct V_46 V_31 ;
if ( F_29 ( & V_4 -> V_47 ,
& V_44 -> V_40 , V_44 -> V_38 ) ||
F_29 ( & V_4 -> V_48 ,
& V_44 -> V_40 , V_44 -> V_38 ) ) {
V_45 ++ ;
continue;
}
V_31 . V_38 = V_44 -> V_38 ;
F_26 ( & V_31 . V_40 , & V_44 -> V_40 ) ;
F_23 ( V_2 , V_49 ,
sizeof( V_31 ) , & V_31 ) ;
}
F_28 (params, &hdev->pend_le_conns, action) {
if ( F_30 ( & V_4 -> V_50 ,
& V_36 -> V_41 , V_36 -> V_39 ) )
continue;
if ( V_45 >= V_4 -> V_51 ) {
return 0x00 ;
}
if ( F_31 ( V_4 , & V_36 -> V_41 ,
V_36 -> V_39 ) ) {
return 0x00 ;
}
V_45 ++ ;
F_25 ( V_2 , V_36 ) ;
}
F_28 (params, &hdev->pend_le_reports, action) {
if ( F_30 ( & V_4 -> V_50 ,
& V_36 -> V_41 , V_36 -> V_39 ) )
continue;
if ( V_45 >= V_4 -> V_51 ) {
return 0x00 ;
}
if ( F_31 ( V_4 , & V_36 -> V_41 ,
V_36 -> V_39 ) ) {
return 0x00 ;
}
V_45 ++ ;
F_25 ( V_2 , V_36 ) ;
}
return 0x01 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_52 V_53 ;
struct V_30 V_54 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_55 ;
T_5 V_56 ;
if ( F_33 ( V_2 , false , & V_55 ) )
return;
V_56 = F_27 ( V_2 ) ;
if ( F_34 ( V_4 , V_57 ) &&
( V_4 -> V_58 [ 0 ] & V_59 ) )
V_56 |= 0x02 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . type = V_60 ;
V_53 . V_61 = F_19 ( V_4 -> V_62 ) ;
V_53 . V_63 = F_19 ( V_4 -> V_64 ) ;
V_53 . V_65 = V_55 ;
V_53 . V_56 = V_56 ;
F_23 ( V_2 , V_66 , sizeof( V_53 ) ,
& V_53 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_32 = V_67 ;
V_54 . V_68 = V_69 ;
F_23 ( V_2 , V_34 , sizeof( V_54 ) ,
& V_54 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_7 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_34 ( V_4 , V_71 ) ||
F_36 ( V_4 ) ) {
F_4 ( L_5 ) ;
F_37 ( V_4 , V_72 ) ;
return;
}
F_23 ( V_2 , V_73 , 6 , V_70 ) ;
}
int F_33 ( struct V_1 * V_2 , bool V_74 ,
T_5 * V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
if ( F_34 ( V_4 , V_57 ) ) {
int V_75 ;
* V_55 = V_76 ;
if ( ! F_38 ( V_4 , V_72 ) &&
! F_39 ( & V_4 -> V_77 , & V_4 -> V_70 ) )
return 0 ;
V_6 = F_40 ( V_4 , V_4 -> V_78 , & V_4 -> V_70 ) ;
if ( V_6 < 0 ) {
F_21 ( L_6 , V_4 -> V_27 ) ;
return V_6 ;
}
F_35 ( V_2 , & V_4 -> V_70 ) ;
V_75 = F_41 ( V_4 -> V_79 * 1000 ) ;
F_42 ( V_4 -> V_14 , & V_4 -> V_80 , V_75 ) ;
return 0 ;
}
if ( V_74 ) {
T_7 V_81 ;
while ( true ) {
F_43 ( & V_81 , 6 ) ;
V_81 . V_44 [ 5 ] &= 0x3f ;
if ( F_39 ( & V_4 -> V_40 , & V_81 ) )
break;
}
* V_55 = V_76 ;
F_35 ( V_2 , & V_81 ) ;
return 0 ;
}
if ( F_34 ( V_4 , V_82 ) ||
! F_39 ( & V_4 -> V_40 , V_83 ) ||
( ! F_34 ( V_4 , V_84 ) &&
F_39 ( & V_4 -> V_85 , V_83 ) ) ) {
* V_55 = V_76 ;
if ( F_39 ( & V_4 -> V_85 , & V_4 -> V_77 ) )
F_23 ( V_2 , V_73 , 6 ,
& V_4 -> V_85 ) ;
return 0 ;
}
* V_55 = V_86 ;
return 0 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
F_28 (b, &hdev->whitelist, list) {
struct V_87 * V_88 ;
V_88 = F_45 ( V_4 , V_89 , & V_44 -> V_40 ) ;
if ( ! V_88 )
return true ;
if ( V_88 -> V_90 != V_91 && V_88 -> V_90 != V_92 )
return true ;
}
return false ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_5 V_93 ;
if ( ! F_34 ( V_4 , V_84 ) )
return;
if ( ! F_47 ( V_4 ) )
return;
if ( F_48 ( V_4 ) )
return;
if ( F_34 ( V_4 , V_94 ) ||
F_44 ( V_4 ) )
V_93 = V_95 ;
else
V_93 = V_96 ;
if ( F_49 ( V_97 , & V_4 -> V_11 ) == ! ! ( V_93 & V_95 ) )
return;
if ( F_34 ( V_4 , V_98 ) )
V_93 |= V_99 ;
F_23 ( V_2 , V_100 , 1 , & V_93 ) ;
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
if ( ! F_49 ( V_101 , & V_4 -> V_11 ) ||
F_49 ( V_102 , & V_4 -> V_11 ) ||
F_34 ( V_4 , V_103 ) ||
F_34 ( V_4 , V_104 ) ||
F_34 ( V_4 , V_105 ) ||
F_34 ( V_4 , V_106 ) )
return;
if ( ! F_34 ( V_4 , V_107 ) )
return;
if ( V_4 -> V_108 . V_90 != V_109 )
return;
F_52 ( V_4 ) ;
if ( F_53 ( & V_4 -> V_47 ) &&
F_53 ( & V_4 -> V_48 ) ) {
if ( ! F_34 ( V_4 , V_110 ) )
return;
F_24 ( V_2 ) ;
F_4 ( L_7 , V_4 -> V_27 ) ;
} else {
if ( F_36 ( V_4 ) )
return;
if ( F_34 ( V_4 , V_110 ) )
F_24 ( V_2 ) ;
F_32 ( V_2 ) ;
F_4 ( L_8 , V_4 -> V_27 ) ;
}
}
static void F_54 ( struct V_3 * V_4 , T_5 V_111 ,
T_3 V_16 )
{
if ( V_111 )
F_4 ( L_9
L_10 , V_111 ) ;
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
