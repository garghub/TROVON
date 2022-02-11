static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 T_1 * V_6 )
{
struct V_5 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_4 ( V_7 . V_8 , V_4 -> V_4 -> V_8 -> V_9 , sizeof( V_7 . V_8 ) ) ;
F_4 ( V_7 . V_10 , V_4 -> V_10 , sizeof( V_7 . V_10 ) ) ;
F_4 ( V_7 . V_11 , V_4 -> V_11 , sizeof( V_7 . V_11 ) ) ;
F_4 ( V_7 . V_12 , V_4 -> V_12 , sizeof( V_7 . V_12 ) ) ;
V_7 . V_13 = V_14 ;
V_7 . V_15 = V_4 -> V_15 ;
V_7 . V_16 = V_4 -> V_16 ;
if ( F_5 ( V_6 , & V_7 , sizeof( * V_6 ) ) )
return - V_17 ;
return 0 ;
}
static struct V_18 * F_6 ( struct V_3 * V_19 , T_2 V_20 )
{
struct V_18 * V_21 ;
int V_22 = V_20 & V_23 ;
V_20 &= ~ V_23 ;
F_7 ( & V_19 -> V_24 ) ;
F_8 (entity, mdev) {
if ( ( ( F_9 ( V_21 ) == V_20 ) && ! V_22 ) ||
( ( F_9 ( V_21 ) > V_20 ) && V_22 ) ) {
F_10 ( & V_19 -> V_24 ) ;
return V_21 ;
}
}
F_10 ( & V_19 -> V_24 ) ;
return NULL ;
}
static long F_11 ( struct V_3 * V_19 ,
struct V_25 T_1 * V_26 )
{
struct V_18 * V_27 ;
struct V_25 V_28 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( F_12 ( & V_28 . V_20 , & V_26 -> V_20 , sizeof( V_28 . V_20 ) ) )
return - V_17 ;
V_27 = F_6 ( V_19 , V_28 . V_20 ) ;
if ( V_27 == NULL )
return - V_29 ;
V_28 . V_20 = F_9 ( V_27 ) ;
if ( V_27 -> V_9 )
F_4 ( V_28 . V_9 , V_27 -> V_9 , sizeof( V_28 . V_9 ) ) ;
V_28 . type = V_27 -> V_30 ;
V_28 . V_31 = 0 ;
V_28 . V_32 = V_27 -> V_32 ;
V_28 . V_33 = 0 ;
V_28 . V_34 = V_27 -> V_35 ;
V_28 . V_36 = V_27 -> V_37 - V_27 -> V_38 ;
if ( V_27 -> V_30 < V_39 ||
V_27 -> V_30 > V_40 ) {
if ( F_13 ( V_27 ) )
V_28 . type = V_41 ;
else if ( V_27 -> V_30 != V_42 )
V_28 . type = V_40 ;
}
memcpy ( & V_28 . V_43 , & V_27 -> V_7 , sizeof( V_27 -> V_7 ) ) ;
if ( F_5 ( V_26 , & V_28 , sizeof( V_28 ) ) )
return - V_17 ;
return 0 ;
}
static void F_14 ( const struct V_44 * V_45 ,
struct V_46 * V_47 )
{
V_47 -> V_21 = F_9 ( V_45 -> V_21 ) ;
V_47 -> V_48 = V_45 -> V_48 ;
V_47 -> V_32 = V_45 -> V_32 ;
}
static long F_15 ( struct V_3 * V_19 ,
struct V_49 * V_36 )
{
struct V_18 * V_21 ;
V_21 = F_6 ( V_19 , V_36 -> V_21 ) ;
if ( V_21 == NULL )
return - V_29 ;
if ( V_36 -> V_34 ) {
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_21 -> V_35 ; V_50 ++ ) {
struct V_46 V_51 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
F_14 ( & V_21 -> V_34 [ V_50 ] , & V_51 ) ;
if ( F_5 ( & V_36 -> V_34 [ V_50 ] , & V_51 , sizeof( V_51 ) ) )
return - V_17 ;
}
}
if ( V_36 -> V_36 ) {
struct V_52 * V_53 ;
struct V_54 T_1 * V_55 = V_36 -> V_36 ;
F_16 (link, &entity->links, list) {
struct V_54 V_56 ;
if ( V_53 -> V_57 -> V_21 != V_21 )
continue;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_14 ( V_53 -> V_57 ,
& V_56 . V_57 ) ;
F_14 ( V_53 -> V_58 ,
& V_56 . V_58 ) ;
V_56 . V_32 = V_53 -> V_32 ;
if ( F_5 ( V_55 , & V_56 ,
sizeof( * V_55 ) ) )
return - V_17 ;
V_55 ++ ;
}
}
return 0 ;
}
static long F_17 ( struct V_3 * V_19 ,
struct V_49 T_1 * V_59 )
{
struct V_49 V_36 ;
int V_60 ;
if ( F_12 ( & V_36 , V_59 , sizeof( V_36 ) ) )
return - V_17 ;
V_60 = F_15 ( V_19 , & V_36 ) ;
if ( V_60 < 0 )
return V_60 ;
if ( F_5 ( V_59 , & V_36 , sizeof( * V_59 ) ) )
return - V_17 ;
return 0 ;
}
static long F_18 ( struct V_3 * V_19 ,
struct V_54 T_1 * V_61 )
{
struct V_52 * V_53 = NULL ;
struct V_54 V_62 ;
struct V_18 * V_57 ;
struct V_18 * V_58 ;
int V_63 ;
if ( F_12 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_17 ;
V_57 = F_6 ( V_19 , V_62 . V_57 . V_21 ) ;
V_58 = F_6 ( V_19 , V_62 . V_58 . V_21 ) ;
if ( V_57 == NULL || V_58 == NULL )
return - V_29 ;
if ( V_62 . V_57 . V_48 >= V_57 -> V_35 ||
V_62 . V_58 . V_48 >= V_58 -> V_35 )
return - V_29 ;
V_53 = F_19 ( & V_57 -> V_34 [ V_62 . V_57 . V_48 ] ,
& V_58 -> V_34 [ V_62 . V_58 . V_48 ] ) ;
if ( V_53 == NULL )
return - V_29 ;
V_63 = F_20 ( V_53 , V_62 . V_32 ) ;
if ( F_5 ( V_61 , & V_62 , sizeof( V_62 ) ) )
return - V_17 ;
return V_63 ;
}
static long F_21 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_66 * V_67 = F_22 ( V_2 ) ;
struct V_3 * V_4 = F_23 ( V_67 ) ;
long V_63 ;
switch ( V_64 ) {
case V_68 :
V_63 = F_3 ( V_4 ,
(struct V_5 T_1 * ) V_65 ) ;
break;
case V_69 :
V_63 = F_11 ( V_4 ,
(struct V_25 T_1 * ) V_65 ) ;
break;
case V_70 :
F_24 ( & V_4 -> V_71 ) ;
V_63 = F_17 ( V_4 ,
(struct V_49 T_1 * ) V_65 ) ;
F_25 ( & V_4 -> V_71 ) ;
break;
case V_72 :
F_24 ( & V_4 -> V_71 ) ;
V_63 = F_18 ( V_4 ,
(struct V_54 T_1 * ) V_65 ) ;
F_25 ( & V_4 -> V_71 ) ;
break;
#if 0
case MEDIA_IOC_G_TOPOLOGY:
mutex_lock(&dev->graph_mutex);
ret = media_device_get_topology(dev,
(struct media_v2_topology __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
#endif
default:
V_63 = - V_73 ;
}
return V_63 ;
}
static long F_26 ( struct V_3 * V_19 ,
struct V_74 T_1 * V_59 )
{
struct V_49 V_36 ;
T_3 V_75 , V_76 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( F_27 ( V_36 . V_21 , & V_59 -> V_21 )
|| F_27 ( V_75 , & V_59 -> V_34 )
|| F_27 ( V_76 , & V_59 -> V_36 ) )
return - V_17 ;
V_36 . V_34 = F_28 ( V_75 ) ;
V_36 . V_36 = F_28 ( V_76 ) ;
return F_15 ( V_19 , & V_36 ) ;
}
static long F_29 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_66 * V_67 = F_22 ( V_2 ) ;
struct V_3 * V_4 = F_23 ( V_67 ) ;
long V_63 ;
switch ( V_64 ) {
case V_68 :
case V_69 :
case V_72 :
#if 0
case MEDIA_IOC_G_TOPOLOGY:
#endif
return F_21 ( V_2 , V_64 , V_65 ) ;
case V_77 :
F_24 ( & V_4 -> V_71 ) ;
V_63 = F_26 ( V_4 ,
(struct V_74 T_1 * ) V_65 ) ;
F_25 ( & V_4 -> V_71 ) ;
break;
default:
V_63 = - V_73 ;
}
return V_63 ;
}
static T_4 F_30 ( struct V_78 * V_79 ,
struct V_80 * V_81 , char * V_82 )
{
struct V_3 * V_19 = F_23 ( F_31 ( V_79 ) ) ;
return sprintf ( V_82 , L_1 , ( int ) sizeof( V_19 -> V_10 ) , V_19 -> V_10 ) ;
}
static void F_32 ( struct V_66 * V_19 )
{
F_33 ( V_19 -> V_83 , L_2 ) ;
}
int T_5 F_34 ( struct V_3 * V_19 ,
struct V_18 * V_21 )
{
unsigned int V_84 ;
int V_63 ;
if ( V_21 -> V_30 == V_41 ||
V_21 -> V_30 == V_85 )
F_35 ( V_19 -> V_4 ,
L_3 ,
V_21 -> V_9 ) ;
F_36 ( V_21 -> V_86 . V_19 != NULL ) ;
V_21 -> V_86 . V_19 = V_19 ;
F_37 ( & V_21 -> V_36 ) ;
V_21 -> V_37 = 0 ;
V_21 -> V_38 = 0 ;
if ( ! F_38 ( & V_19 -> V_87 , V_88 ) )
return - V_89 ;
F_7 ( & V_19 -> V_24 ) ;
V_63 = F_39 ( & V_19 -> V_87 , 1 ,
& V_21 -> V_90 ) ;
if ( V_63 < 0 ) {
F_10 ( & V_19 -> V_24 ) ;
return V_63 ;
}
V_19 -> V_91 =
F_40 ( V_19 -> V_91 , V_21 -> V_90 ) ;
F_41 ( V_19 , V_92 , & V_21 -> V_86 ) ;
for ( V_84 = 0 ; V_84 < V_21 -> V_35 ; V_84 ++ )
F_41 ( V_19 , V_93 ,
& V_21 -> V_34 [ V_84 ] . V_86 ) ;
F_10 ( & V_19 -> V_24 ) ;
return 0 ;
}
static void F_42 ( struct V_18 * V_21 )
{
struct V_3 * V_19 = V_21 -> V_86 . V_19 ;
struct V_52 * V_53 , * V_94 ;
struct V_95 * V_96 ;
unsigned int V_84 ;
F_43 ( & V_19 -> V_87 , V_21 -> V_90 ) ;
F_16 (intf, &mdev->interfaces, graph_obj.list) {
F_44 (link, tmp, &intf->links, list) {
if ( V_53 -> V_21 == V_21 )
F_45 ( V_53 ) ;
}
}
F_46 ( V_21 ) ;
for ( V_84 = 0 ; V_84 < V_21 -> V_35 ; V_84 ++ )
F_47 ( & V_21 -> V_34 [ V_84 ] . V_86 ) ;
F_47 ( & V_21 -> V_86 ) ;
V_21 -> V_86 . V_19 = NULL ;
}
void F_48 ( struct V_18 * V_21 )
{
struct V_3 * V_19 = V_21 -> V_86 . V_19 ;
if ( V_19 == NULL )
return;
F_7 ( & V_19 -> V_24 ) ;
F_42 ( V_21 ) ;
F_10 ( & V_19 -> V_24 ) ;
}
void F_49 ( struct V_3 * V_19 )
{
F_37 ( & V_19 -> V_97 ) ;
F_37 ( & V_19 -> V_98 ) ;
F_37 ( & V_19 -> V_34 ) ;
F_37 ( & V_19 -> V_36 ) ;
F_50 ( & V_19 -> V_24 ) ;
F_51 ( & V_19 -> V_71 ) ;
F_52 ( & V_19 -> V_87 ) ;
F_33 ( V_19 -> V_4 , L_4 ) ;
}
void F_53 ( struct V_3 * V_19 )
{
F_54 ( & V_19 -> V_87 ) ;
V_19 -> V_91 = 0 ;
F_55 ( & V_19 -> V_71 ) ;
}
int T_5 F_56 ( struct V_3 * V_19 ,
struct V_99 * V_100 )
{
int V_63 ;
V_19 -> V_67 . V_101 = & V_102 ;
V_19 -> V_67 . V_83 = V_19 -> V_4 ;
V_19 -> V_67 . V_103 = F_32 ;
V_19 -> V_104 = 0 ;
V_63 = F_57 ( & V_19 -> V_67 , V_100 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_58 ( & V_19 -> V_67 . V_4 , & V_105 ) ;
if ( V_63 < 0 ) {
F_59 ( & V_19 -> V_67 ) ;
return V_63 ;
}
F_33 ( V_19 -> V_4 , L_5 ) ;
return 0 ;
}
void F_60 ( struct V_3 * V_19 )
{
struct V_18 * V_21 ;
struct V_18 * V_22 ;
struct V_95 * V_96 , * V_106 ;
if ( V_19 == NULL )
return;
F_7 ( & V_19 -> V_24 ) ;
if ( ! F_61 ( & V_19 -> V_67 ) ) {
F_10 ( & V_19 -> V_24 ) ;
return;
}
F_44 (entity, next, &mdev->entities, graph_obj.list)
F_42 ( V_21 ) ;
F_44 (intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
F_62 ( V_96 ) ;
F_47 ( & V_96 -> V_86 ) ;
F_63 ( V_96 ) ;
}
F_10 ( & V_19 -> V_24 ) ;
F_64 ( & V_19 -> V_67 . V_4 , & V_105 ) ;
F_59 ( & V_19 -> V_67 ) ;
F_33 ( V_19 -> V_4 , L_6 ) ;
}
static void F_65 ( struct V_78 * V_4 , void * V_107 )
{
}
struct V_3 * F_66 ( struct V_78 * V_4 )
{
struct V_3 * V_19 ;
V_19 = F_67 ( V_4 , F_65 , NULL , NULL ) ;
if ( V_19 )
return V_19 ;
V_19 = F_68 ( F_65 ,
sizeof( struct V_3 ) , V_88 ) ;
if ( ! V_19 )
return NULL ;
return F_69 ( V_4 , V_19 , NULL , NULL ) ;
}
struct V_3 * F_70 ( struct V_78 * V_4 )
{
return F_67 ( V_4 , F_65 , NULL , NULL ) ;
}
