static struct
V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
int F_12 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_1 * V_6 ;
int V_11 ;
V_31 = V_27 -> V_32 ;
V_6 = V_31 -> V_33 -> V_34 -> V_35 ;
if ( V_6 == NULL ) {
F_9 (
L_4 ) ;
return - V_36 ;
}
V_11 = F_13 ( V_27 , V_29 , & V_6 -> V_5 . V_3 ) ;
#if 0
if (unlikely(r != 0))
return r;
if (unlikely(ttm_vm_ops == NULL)) {
ttm_vm_ops = vma->vm_ops;
virtio_gpu_ttm_vm_ops = *ttm_vm_ops;
virtio_gpu_ttm_vm_ops.fault = &virtio_gpu_ttm_fault;
}
vma->vm_ops = &virtio_gpu_ttm_vm_ops;
return 0;
#else
return V_11 ;
#endif
}
static int F_14 ( struct V_2 * V_3 ,
T_1 V_37 )
{
return 0 ;
}
static int F_15 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
const struct V_42 * V_43 ,
struct V_44 * V_45 )
{
V_45 -> V_46 = ( void * ) 1 ;
return 0 ;
}
static void F_16 ( struct V_38 * V_39 ,
struct V_44 * V_45 )
{
V_45 -> V_46 = ( void * ) NULL ;
return;
}
static int F_17 ( struct V_38 * V_39 ,
unsigned long V_47 )
{
return 0 ;
}
static int F_18 ( struct V_38 * V_39 )
{
return 0 ;
}
static void F_19 ( struct V_38 * V_39 ,
struct V_48 * V_49 )
{
}
static int F_20 ( struct V_2 * V_3 , T_1 type ,
struct V_38 * V_39 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_50 :
V_39 -> V_37 = V_51 ;
V_39 -> V_52 = V_53 ;
V_39 -> V_54 = V_55 ;
break;
case V_56 :
V_39 -> V_57 = & V_58 ;
V_39 -> V_37 = V_51 ;
V_39 -> V_52 = V_53 ;
V_39 -> V_54 = V_55 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_36 ;
}
return 0 ;
}
static void F_21 ( struct V_40 * V_41 ,
struct V_59 * V_60 )
{
static const struct V_42 V_61 = {
. V_62 = 0 ,
. V_63 = 0 ,
. V_37 = V_53 | V_64 ,
} ;
V_60 -> V_60 = & V_61 ;
V_60 -> V_65 = & V_61 ;
V_60 -> V_66 = 1 ;
V_60 -> V_67 = 1 ;
return;
}
static int F_22 ( struct V_40 * V_41 ,
struct V_26 * V_27 )
{
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_38 * V_39 = & V_3 -> V_39 [ V_45 -> V_68 ] ;
V_45 -> V_69 . V_70 = NULL ;
V_45 -> V_69 . V_71 = 0 ;
V_45 -> V_69 . V_16 = V_45 -> V_72 << V_73 ;
V_45 -> V_69 . V_74 = 0 ;
V_45 -> V_69 . V_75 = false ;
if ( ! ( V_39 -> V_37 & V_51 ) )
return - V_36 ;
switch ( V_45 -> V_68 ) {
case V_50 :
case V_56 :
return 0 ;
default:
return - V_36 ;
}
return 0 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
}
static int F_25 ( struct V_76 * V_77 ,
struct V_44 * V_78 )
{
struct V_79 * V_80 = ( void * ) V_77 ;
V_80 -> V_71 = ( unsigned long ) ( V_78 -> V_81 << V_73 ) ;
if ( ! V_77 -> V_72 )
F_26 ( 1 , L_6 ,
V_77 -> V_72 , V_78 , V_77 ) ;
return 0 ;
}
static int F_27 ( struct V_76 * V_77 )
{
return 0 ;
}
static void F_28 ( struct V_76 * V_77 )
{
struct V_79 * V_80 = ( void * ) V_77 ;
F_29 ( & V_80 -> V_77 ) ;
F_30 ( V_80 ) ;
}
static int F_31 ( struct V_76 * V_77 )
{
if ( V_77 -> V_82 != V_83 )
return 0 ;
return F_32 ( V_77 ) ;
}
static void F_33 ( struct V_76 * V_77 )
{
F_34 ( V_77 ) ;
}
static struct V_76 * F_35 ( struct V_2 * V_3 ,
unsigned long V_16 ,
T_1 V_84 ,
struct V_85 * V_86 )
{
struct V_1 * V_6 ;
struct V_79 * V_80 ;
V_6 = F_1 ( V_3 ) ;
V_80 = F_36 ( sizeof( struct V_79 ) , V_87 ) ;
if ( V_80 == NULL )
return NULL ;
V_80 -> V_77 . V_77 . V_57 = & V_88 ;
V_80 -> V_6 = V_6 ;
if ( F_37 ( & V_80 -> V_77 , V_3 , V_16 , V_84 ,
V_86 ) ) {
F_30 ( V_80 ) ;
return NULL ;
}
return & V_80 -> V_77 . V_77 ;
}
static void F_38 ( struct V_40 * V_41 ,
struct V_44 * V_89 )
{
struct V_44 * V_90 = & V_41 -> V_45 ;
F_39 ( V_90 -> V_46 != NULL ) ;
* V_90 = * V_89 ;
V_89 -> V_46 = NULL ;
}
static int F_40 ( struct V_40 * V_41 ,
bool V_91 , bool V_92 ,
bool V_93 ,
struct V_44 * V_89 )
{
int V_94 ;
V_94 = F_41 ( V_41 , V_92 , V_93 ) ;
if ( V_94 )
return V_94 ;
F_38 ( V_41 , V_89 ) ;
return 0 ;
}
static void F_42 ( struct V_40 * V_95 ,
bool V_91 ,
struct V_44 * V_89 )
{
struct V_96 * V_41 ;
struct V_1 * V_6 ;
V_41 = F_2 ( V_95 , struct V_96 , V_95 ) ;
V_6 = (struct V_1 * ) V_41 -> V_97 . V_34 -> V_35 ;
if ( ! V_89 || ( V_89 -> V_60 & V_64 ) ) {
if ( V_41 -> V_98 )
F_43 ( V_6 ,
V_41 -> V_98 ) ;
} else if ( V_89 -> V_60 & V_99 ) {
if ( V_41 -> V_98 ) {
F_44 ( V_6 , V_41 , V_41 -> V_98 ,
NULL ) ;
}
}
}
static void F_45 ( struct V_40 * V_95 )
{
struct V_96 * V_41 ;
struct V_1 * V_6 ;
V_41 = F_2 ( V_95 , struct V_96 , V_95 ) ;
V_6 = (struct V_1 * ) V_41 -> V_97 . V_34 -> V_35 ;
if ( V_41 -> V_100 )
F_46 ( V_41 ) ;
}
int F_47 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_48 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_101 ,
V_6 -> V_102 -> V_103 -> V_104 ,
V_105 , 0 ) ;
if ( V_11 ) {
F_9 ( L_7 , V_11 ) ;
goto V_106;
}
V_11 = F_49 ( & V_6 -> V_5 . V_3 , V_56 , 0 ) ;
if ( V_11 ) {
F_9 ( L_8 ) ;
goto V_107;
}
return 0 ;
V_107:
F_50 ( & V_6 -> V_5 . V_3 ) ;
V_106:
F_11 ( V_6 ) ;
return V_11 ;
}
void F_51 ( struct V_1 * V_6 )
{
F_50 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_52 ( L_9 ) ;
}
