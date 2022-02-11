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
const char * V_48 )
{
}
static int F_20 ( struct V_2 * V_3 , T_1 type ,
struct V_38 * V_39 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_49 :
V_39 -> V_37 = V_50 ;
V_39 -> V_51 = V_52 ;
V_39 -> V_53 = V_54 ;
break;
case V_55 :
V_39 -> V_56 = & V_57 ;
V_39 -> V_37 = V_50 ;
V_39 -> V_51 = V_52 ;
V_39 -> V_53 = V_54 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_36 ;
}
return 0 ;
}
static void F_21 ( struct V_40 * V_41 ,
struct V_58 * V_59 )
{
static struct V_42 V_60 = {
. V_61 = 0 ,
. V_62 = 0 ,
. V_37 = V_52 | V_63 ,
} ;
V_59 -> V_59 = & V_60 ;
V_59 -> V_64 = & V_60 ;
V_59 -> V_65 = 1 ;
V_59 -> V_66 = 1 ;
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
struct V_38 * V_39 = & V_3 -> V_39 [ V_45 -> V_67 ] ;
V_45 -> V_68 . V_69 = NULL ;
V_45 -> V_68 . V_70 = 0 ;
V_45 -> V_68 . V_16 = V_45 -> V_71 << V_72 ;
V_45 -> V_68 . V_73 = 0 ;
V_45 -> V_68 . V_74 = false ;
if ( ! ( V_39 -> V_37 & V_50 ) )
return - V_36 ;
switch ( V_45 -> V_67 ) {
case V_49 :
case V_55 :
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
static int F_25 ( struct V_75 * V_76 ,
struct V_44 * V_77 )
{
struct V_78 * V_79 = ( void * ) V_76 ;
V_79 -> V_70 = ( unsigned long ) ( V_77 -> V_80 << V_72 ) ;
if ( ! V_76 -> V_71 )
F_26 ( 1 , L_6 ,
V_76 -> V_71 , V_77 , V_76 ) ;
return 0 ;
}
static int F_27 ( struct V_75 * V_76 )
{
return 0 ;
}
static void F_28 ( struct V_75 * V_76 )
{
struct V_78 * V_79 = ( void * ) V_76 ;
F_29 ( & V_79 -> V_76 ) ;
F_30 ( V_79 ) ;
}
static int F_31 ( struct V_75 * V_76 )
{
if ( V_76 -> V_81 != V_82 )
return 0 ;
return F_32 ( V_76 ) ;
}
static void F_33 ( struct V_75 * V_76 )
{
F_34 ( V_76 ) ;
}
static struct V_75 * F_35 ( struct V_2 * V_3 ,
unsigned long V_16 ,
T_1 V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_6 ;
struct V_78 * V_79 ;
V_6 = F_1 ( V_3 ) ;
V_79 = F_36 ( sizeof( struct V_78 ) , V_86 ) ;
if ( V_79 == NULL )
return NULL ;
V_79 -> V_76 . V_76 . V_56 = & V_87 ;
V_79 -> V_6 = V_6 ;
if ( F_37 ( & V_79 -> V_76 , V_3 , V_16 , V_83 ,
V_85 ) ) {
F_30 ( V_79 ) ;
return NULL ;
}
return & V_79 -> V_76 . V_76 ;
}
static void F_38 ( struct V_40 * V_41 ,
struct V_44 * V_88 )
{
struct V_44 * V_89 = & V_41 -> V_45 ;
F_39 ( V_89 -> V_46 != NULL ) ;
* V_89 = * V_88 ;
V_88 -> V_46 = NULL ;
}
static int F_40 ( struct V_40 * V_41 ,
bool V_90 , bool V_91 ,
bool V_92 ,
struct V_44 * V_88 )
{
int V_93 ;
V_93 = F_41 ( V_41 , V_91 , V_92 ) ;
if ( V_93 )
return V_93 ;
F_38 ( V_41 , V_88 ) ;
return 0 ;
}
static void F_42 ( struct V_40 * V_94 ,
struct V_44 * V_88 )
{
struct V_95 * V_41 ;
struct V_1 * V_6 ;
V_41 = F_2 ( V_94 , struct V_95 , V_94 ) ;
V_6 = (struct V_1 * ) V_41 -> V_96 . V_34 -> V_35 ;
if ( ! V_88 || ( V_88 -> V_59 & V_63 ) ) {
if ( V_41 -> V_97 )
F_43 ( V_6 ,
V_41 -> V_97 ) ;
} else if ( V_88 -> V_59 & V_98 ) {
if ( V_41 -> V_97 ) {
F_44 ( V_6 , V_41 , V_41 -> V_97 ,
NULL ) ;
}
}
}
static void F_45 ( struct V_40 * V_94 )
{
struct V_95 * V_41 ;
struct V_1 * V_6 ;
V_41 = F_2 ( V_94 , struct V_95 , V_94 ) ;
V_6 = (struct V_1 * ) V_41 -> V_96 . V_34 -> V_35 ;
if ( V_41 -> V_99 )
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
& V_100 ,
V_6 -> V_101 -> V_102 -> V_103 ,
V_104 , 0 ) ;
if ( V_11 ) {
F_9 ( L_7 , V_11 ) ;
goto V_105;
}
V_11 = F_49 ( & V_6 -> V_5 . V_3 , V_55 , 0 ) ;
if ( V_11 ) {
F_9 ( L_8 ) ;
goto V_106;
}
return 0 ;
V_106:
F_50 ( & V_6 -> V_5 . V_3 ) ;
V_105:
F_11 ( V_6 ) ;
return V_11 ;
}
void F_51 ( struct V_1 * V_6 )
{
F_50 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_52 ( L_9 ) ;
}
