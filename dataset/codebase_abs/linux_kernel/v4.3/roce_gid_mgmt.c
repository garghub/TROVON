static void F_1 ( enum V_1 V_2 , struct V_3 * V_4 ,
T_1 V_5 , union V_6 * V_7 ,
struct V_8 * V_9 )
{
switch ( V_2 ) {
case V_10 :
F_2 ( V_4 , V_5 , V_7 , V_9 ) ;
break;
case V_11 :
F_3 ( V_4 , V_5 , V_7 , V_9 ) ;
break;
}
}
static enum V_12 F_4 ( struct V_13 * V_14 ,
struct V_13 * V_15 )
{
if ( V_15 && F_5 ( V_15 ) ) {
struct V_13 * V_16 =
F_6 ( F_7 ( V_15 ) ) ;
if ( V_16 )
return V_14 == V_16 ? V_17 :
V_18 ;
}
return V_19 ;
}
static bool F_8 ( struct V_13 * V_14 , struct V_13 * V_15 )
{
struct V_13 * V_20 = NULL ;
struct V_21 * V_22 ;
F_9 (dev, _upper, iter)
if ( V_20 == V_15 )
break;
return V_20 == V_15 ;
}
static int F_10 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_25 = (struct V_13 * ) V_24 ;
struct V_13 * V_26 ;
int V_27 ;
if ( ! V_23 )
return 0 ;
F_11 () ;
V_26 = F_12 ( V_25 ) ;
if ( ! V_26 )
V_26 = V_25 ;
V_27 = ( ( F_8 ( V_23 , V_25 ) &&
( F_4 ( V_23 , V_26 ) &
V_28 ) ) ||
V_26 == V_23 ) ;
F_13 () ;
return V_27 ;
}
static int F_14 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_29 ;
int V_27 ;
if ( ! V_23 )
return 0 ;
F_11 () ;
V_29 = F_15 ( V_23 ) ;
V_27 = F_4 ( V_23 , V_29 ) ==
V_18 ;
F_13 () ;
return V_27 ;
}
static int F_16 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
return 1 ;
}
static int F_17 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_25 = (struct V_13 * ) V_24 ;
int V_27 ;
if ( ! V_23 )
return 0 ;
if ( V_23 == V_25 )
return 1 ;
F_11 () ;
V_27 = F_8 ( V_23 , V_25 ) ;
F_13 () ;
return V_27 ;
}
static void F_18 ( enum V_1 V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , struct V_13 * V_30 ,
struct V_31 * V_32 )
{
union V_6 V_7 ;
struct V_8 V_9 ;
F_19 ( V_32 , & V_7 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_30 = V_30 ;
F_1 ( V_2 , V_4 , V_5 , & V_7 , & V_9 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
T_1 V_5 , struct V_13 * V_25 ,
struct V_13 * V_23 )
{
F_11 () ;
if ( ! V_23 ||
( ( V_23 != V_25 &&
! F_8 ( V_23 , V_25 ) ) ||
F_4 ( V_23 ,
F_15 ( V_23 ) ) ==
V_18 ) ) {
F_13 () ;
return;
}
F_13 () ;
F_21 ( V_4 , V_5 , V_23 ,
V_33 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_13 * V_25 ,
struct V_13 * V_23 )
{
struct V_13 * V_26 = F_12 ( V_25 ) ;
if ( ! V_23 )
return;
if ( ! V_26 )
V_26 = V_25 ;
F_11 () ;
if ( F_8 ( V_23 , V_25 ) &&
F_4 ( V_23 , V_26 ) ==
V_18 ) {
F_13 () ;
F_21 ( V_4 , V_5 , V_23 ,
V_34 ) ;
} else {
F_13 () ;
}
}
static void F_23 ( struct V_3 * V_4 ,
T_1 V_5 , struct V_13 * V_30 )
{
struct V_35 * V_36 ;
struct V_37 {
struct V_21 V_38 ;
struct V_39 V_40 ;
};
struct V_37 * V_41 ;
struct V_37 * V_42 ;
F_24 ( V_37 ) ;
if ( V_30 -> V_43 >= V_44 )
return;
F_11 () ;
V_36 = F_25 ( V_30 ) ;
if ( ! V_36 ) {
F_13 () ;
return;
}
F_26 (in_dev) {
struct V_37 * V_45 = F_27 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 ) {
F_28 ( L_1 ) ;
continue;
}
V_45 -> V_40 . V_47 = V_48 ;
V_45 -> V_40 . V_49 . V_50 = V_51 -> V_52 ;
F_29 ( & V_45 -> V_38 , & V_37 ) ;
}
F_30 ( V_36 ) ;
F_13 () ;
F_31 (sin_iter, sin_temp, &sin_list, list) {
F_18 ( V_10 , V_4 , V_5 , V_30 ,
(struct V_31 * ) & V_41 -> V_40 ) ;
F_32 ( & V_41 -> V_38 ) ;
F_33 ( V_41 ) ;
}
}
static void F_34 ( struct V_3 * V_4 ,
T_1 V_5 , struct V_13 * V_30 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 {
struct V_21 V_38 ;
struct V_58 V_59 ;
};
struct V_57 * V_60 ;
struct V_57 * V_61 ;
struct V_8 V_9 = { . V_30 = V_30 } ;
F_24 ( V_57 ) ;
if ( V_30 -> V_43 >= V_44 )
return;
V_56 = F_35 ( V_30 ) ;
if ( ! V_56 )
return;
F_36 ( & V_56 -> V_62 ) ;
F_37 (ifp, &in6_dev->addr_list, if_list) {
struct V_57 * V_45 = F_27 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 ) {
F_28 ( L_2 ) ;
continue;
}
V_45 -> V_59 . V_63 = V_64 ;
V_45 -> V_59 . V_65 = V_54 -> V_32 ;
F_29 ( & V_45 -> V_38 , & V_57 ) ;
}
F_38 ( & V_56 -> V_62 ) ;
F_39 ( V_56 ) ;
F_31 (sin6_iter, sin6_temp, &sin6_list, list) {
union V_6 V_7 ;
F_19 ( (struct V_31 * ) & V_60 -> V_59 , & V_7 ) ;
F_1 ( V_10 , V_4 , V_5 , & V_7 , & V_9 ) ;
F_32 ( & V_60 -> V_38 ) ;
F_33 ( V_60 ) ;
}
}
static void F_40 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_30 )
{
F_23 ( V_4 , V_5 , V_30 ) ;
if ( F_41 ( V_66 ) )
F_34 ( V_4 , V_5 , V_30 ) ;
}
static void F_42 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_25 = (struct V_13 * ) V_24 ;
F_20 ( V_4 , V_5 , V_25 , V_23 ) ;
F_40 ( V_4 , V_5 , V_25 ) ;
}
static void F_43 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_25 = (struct V_13 * ) V_24 ;
F_44 ( V_4 , V_5 , V_25 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_13 * V_23 ,
void * V_24 )
{
struct V_67 * V_67 ;
struct V_13 * V_30 ;
F_46 () ;
F_47 (net)
F_48 (net, ndev)
if ( F_10 ( V_4 , V_5 , V_23 , V_30 ) )
F_42 ( V_4 , V_5 , V_23 , V_30 ) ;
F_49 () ;
}
int F_50 ( struct V_3 * V_4 )
{
F_51 ( V_4 , F_16 , NULL ,
F_45 , NULL ) ;
return 0 ;
}
static void F_52 ( struct V_3 * V_68 ,
T_1 V_5 ,
struct V_13 * V_23 ,
void * V_24 )
{
struct V_69 * V_70 = V_24 ;
return F_1 ( V_70 -> V_2 , V_68 ,
V_5 , & V_70 -> V_7 ,
& V_70 -> V_9 ) ;
}
static void F_53 ( struct V_3 * V_4 , T_1 V_5 ,
void * V_24 ,
void (* F_54)( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_13 * V_30 ) )
{
struct V_13 * V_30 = (struct V_13 * ) V_24 ;
struct V_71 {
struct V_21 V_38 ;
struct V_13 * V_15 ;
};
struct V_13 * V_15 ;
struct V_21 * V_22 ;
struct V_71 * V_72 ;
struct V_71 * V_73 ;
F_24 ( V_71 ) ;
F_11 () ;
F_9 (ndev, upper, iter) {
struct V_71 * V_45 = F_55 ( sizeof( * V_45 ) ,
V_46 ) ;
if ( ! V_45 ) {
F_56 ( L_3 ) ;
continue;
}
F_29 ( & V_45 -> V_38 , & V_71 ) ;
F_57 ( V_15 ) ;
V_45 -> V_15 = V_15 ;
}
F_13 () ;
F_54 ( V_4 , V_5 , V_30 ) ;
F_31 (upper_iter, upper_temp, &upper_list,
list) {
F_54 ( V_4 , V_5 , V_72 -> V_15 ) ;
F_58 ( V_72 -> V_15 ) ;
F_32 ( & V_72 -> V_38 ) ;
F_33 ( V_72 ) ;
}
}
static void F_59 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_25 )
{
F_44 ( V_4 , V_5 , V_25 ) ;
}
static void F_60 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
F_53 ( V_4 , V_5 , V_24 , F_59 ) ;
}
static void F_61 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
F_53 ( V_4 , V_5 , V_24 , F_40 ) ;
}
static void F_62 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 ,
void * V_24 )
{
struct V_13 * V_74 ;
F_11 () ;
V_74 = F_15 ( V_23 ) ;
if ( V_74 )
F_57 ( V_74 ) ;
F_13 () ;
if ( V_74 ) {
F_22 ( V_4 , V_5 , V_74 ,
V_23 ) ;
F_58 ( V_74 ) ;
}
}
static void F_63 ( struct V_3 * V_4 , T_1 V_5 ,
struct V_13 * V_23 , void * V_24 )
{
struct V_13 * V_25 = (struct V_13 * ) V_24 ;
F_22 ( V_4 , V_5 , V_25 , V_23 ) ;
}
static void F_64 ( struct V_75 * V_76 )
{
struct V_77 * V_78 =
F_65 ( V_76 , struct V_77 , V_78 ) ;
unsigned int V_79 ;
for ( V_79 = 0 ; V_79 < F_66 ( V_78 -> V_80 ) && V_78 -> V_80 [ V_79 ] . V_81 ; V_79 ++ ) {
F_67 ( V_78 -> V_80 [ V_79 ] . V_82 ,
V_78 -> V_80 [ V_79 ] . V_83 ,
V_78 -> V_80 [ V_79 ] . V_81 ,
V_78 -> V_80 [ V_79 ] . V_30 ) ;
F_58 ( V_78 -> V_80 [ V_79 ] . V_30 ) ;
F_58 ( V_78 -> V_80 [ V_79 ] . V_83 ) ;
}
F_33 ( V_78 ) ;
}
static int F_68 ( struct V_84 * V_80 ,
struct V_13 * V_30 )
{
unsigned int V_79 ;
struct V_77 * V_85 =
F_55 ( sizeof( * V_85 ) , V_86 ) ;
if ( ! V_85 ) {
F_28 ( L_4 ) ;
return V_87 ;
}
memcpy ( V_85 -> V_80 , V_80 , sizeof( V_85 -> V_80 ) ) ;
for ( V_79 = 0 ; V_79 < F_66 ( V_85 -> V_80 ) && V_85 -> V_80 [ V_79 ] . V_81 ; V_79 ++ ) {
if ( ! V_85 -> V_80 [ V_79 ] . V_30 )
V_85 -> V_80 [ V_79 ] . V_30 = V_30 ;
if ( ! V_85 -> V_80 [ V_79 ] . V_83 )
V_85 -> V_80 [ V_79 ] . V_83 = V_30 ;
F_57 ( V_85 -> V_80 [ V_79 ] . V_30 ) ;
F_57 ( V_85 -> V_80 [ V_79 ] . V_83 ) ;
}
F_69 ( & V_85 -> V_78 , F_64 ) ;
F_70 ( V_88 , & V_85 -> V_78 ) ;
return V_87 ;
}
static void F_71 ( struct V_89 * V_90 ,
struct V_84 * V_80 )
{
static const struct V_84 V_91 = {
. V_81 = F_60 , . V_82 = F_17 } ;
static const struct V_84 V_92 = {
. V_81 = F_63 , . V_82 = F_14 } ;
if ( V_90 -> V_93 == false ) {
V_80 [ 0 ] = V_91 ;
V_80 [ 0 ] . V_30 = V_90 -> V_94 ;
V_80 [ 1 ] = V_95 ;
} else {
V_80 [ 0 ] = V_92 ;
V_80 [ 0 ] . V_30 = V_90 -> V_94 ;
V_80 [ 1 ] = V_96 ;
V_80 [ 1 ] . V_30 = V_90 -> V_94 ;
V_80 [ 1 ] . V_83 = V_90 -> V_94 ;
}
}
static int F_72 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
static const struct V_84 V_101 = {
. V_81 = F_43 , . V_82 = F_16 } ;
static const struct V_84 V_102 = {
. V_81 = F_62 , . V_82 = F_14 } ;
static const struct V_84 V_103 = {
. V_81 = F_63 , . V_82 = F_16 } ;
static const struct V_84 V_104 = {
. V_81 = F_60 , . V_82 = F_17 } ;
struct V_13 * V_30 = F_73 ( V_100 ) ;
struct V_84 V_80 [ V_105 ] = { { NULL } } ;
if ( V_30 -> type != V_106 )
return V_87 ;
switch ( V_99 ) {
case V_107 :
case V_108 :
V_80 [ 0 ] = V_102 ;
V_80 [ 1 ] = V_95 ;
break;
case V_109 :
if ( V_30 -> V_43 < V_110 )
V_80 [ 0 ] = V_101 ;
else
return V_87 ;
break;
case V_111 :
V_80 [ 0 ] = V_103 ;
V_80 [ 1 ] = V_95 ;
break;
case V_112 :
F_71 (
F_65 ( V_100 , struct V_89 , V_113 ) ,
V_80 ) ;
break;
case V_114 :
V_80 [ 0 ] = V_104 ;
V_80 [ 1 ] = V_102 ;
V_80 [ 2 ] = V_96 ;
break;
default:
return V_87 ;
}
return F_68 ( V_80 , V_30 ) ;
}
static void F_74 ( struct V_75 * V_76 )
{
struct V_69 * V_78 =
F_65 ( V_76 , struct V_69 , V_78 ) ;
F_67 ( F_10 , V_78 -> V_9 . V_30 ,
F_52 , V_78 ) ;
F_58 ( V_78 -> V_9 . V_30 ) ;
F_33 ( V_78 ) ;
}
static int F_75 ( struct V_97 * V_98 , unsigned long V_99 ,
struct V_31 * V_115 , struct V_13 * V_30 )
{
struct V_69 * V_78 ;
enum V_1 V_2 ;
if ( V_30 -> type != V_106 )
return V_87 ;
switch ( V_99 ) {
case V_108 :
V_2 = V_10 ;
break;
case V_116 :
V_2 = V_11 ;
break;
default:
return V_87 ;
}
V_78 = F_55 ( sizeof( * V_78 ) , V_46 ) ;
if ( ! V_78 ) {
F_28 ( L_5 ) ;
return V_87 ;
}
F_69 ( & V_78 -> V_78 , F_74 ) ;
F_19 ( V_115 , & V_78 -> V_7 ) ;
V_78 -> V_2 = V_2 ;
memset ( & V_78 -> V_9 , 0 , sizeof( V_78 -> V_9 ) ) ;
F_57 ( V_30 ) ;
V_78 -> V_9 . V_30 = V_30 ;
F_70 ( V_88 , & V_78 -> V_78 ) ;
return V_87 ;
}
static int F_76 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
struct V_39 V_117 ;
struct V_13 * V_30 ;
struct V_118 * V_51 = V_100 ;
V_117 . V_47 = V_48 ;
V_117 . V_49 . V_50 = V_51 -> V_52 ;
V_30 = V_51 -> V_119 -> V_14 ;
return F_75 ( V_98 , V_99 , (struct V_31 * ) & V_117 , V_30 ) ;
}
static int F_77 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
struct V_58 V_120 ;
struct V_13 * V_30 ;
struct V_53 * V_121 = V_100 ;
V_120 . V_63 = V_64 ;
V_120 . V_65 = V_121 -> V_32 ;
V_30 = V_121 -> V_122 -> V_14 ;
return F_75 ( V_98 , V_99 , (struct V_31 * ) & V_120 , V_30 ) ;
}
int T_2 F_78 ( void )
{
F_79 ( & V_123 ) ;
if ( F_41 ( V_66 ) )
F_80 ( & V_124 ) ;
F_81 ( & V_125 ) ;
return 0 ;
}
void T_3 F_82 ( void )
{
if ( F_41 ( V_66 ) )
F_83 ( & V_124 ) ;
F_84 ( & V_123 ) ;
F_85 ( & V_125 ) ;
}
