unsigned long F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
unsigned int V_5 = 0 ;
if ( ! F_2 ( V_2 , V_3 ) )
return 1UL << V_6 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
if ( V_8 [ V_4 ] . F_3 ( V_2 , V_3 ) )
V_5 |= 1UL << V_8 [ V_4 ] . V_9 ;
return V_5 ;
}
static void F_4 ( enum V_10 V_11 , struct V_1 * V_2 ,
T_1 V_3 , union V_12 * V_13 ,
struct V_14 * V_15 )
{
int V_4 ;
unsigned long V_16 = F_1 ( V_2 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
if ( ( 1UL << V_4 ) & V_16 ) {
V_15 -> V_9 = V_4 ;
switch ( V_11 ) {
case V_18 :
F_5 ( V_2 , V_3 ,
V_13 , V_15 ) ;
break;
case V_19 :
F_6 ( V_2 , V_3 ,
V_13 , V_15 ) ;
break;
}
}
}
}
static enum V_20 F_7 ( struct V_21 * V_22 ,
struct V_21 * V_23 )
{
if ( V_23 && F_8 ( V_23 ) ) {
struct V_21 * V_24 =
F_9 ( F_10 ( V_23 ) ) ;
if ( V_24 )
return V_22 == V_24 ? V_25 :
V_26 ;
}
return V_27 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_29 ;
struct V_21 * V_31 ;
int V_32 ;
if ( ! V_28 )
return 0 ;
F_12 () ;
V_31 = F_13 ( V_30 ) ;
if ( ! V_31 )
V_31 = V_30 ;
V_32 = ( ( F_14 ( V_28 , V_30 ) &&
( F_7 ( V_28 , V_31 ) &
V_33 ) ) ||
V_31 == V_28 ) ;
F_15 () ;
return V_32 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_34 ;
int V_32 ;
if ( ! V_28 )
return 0 ;
F_12 () ;
V_34 = F_17 ( V_28 ) ;
V_32 = F_7 ( V_28 , V_34 ) ==
V_26 ;
F_15 () ;
return V_32 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
return 1 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_29 ;
int V_32 ;
if ( ! V_28 )
return 0 ;
if ( V_28 == V_30 )
return 1 ;
F_12 () ;
V_32 = F_14 ( V_28 , V_30 ) ;
F_15 () ;
return V_32 ;
}
static void F_20 ( enum V_10 V_11 ,
struct V_1 * V_2 ,
T_1 V_3 , struct V_21 * V_35 ,
struct V_36 * V_37 )
{
union V_12 V_13 ;
struct V_14 V_15 ;
F_21 ( V_37 , & V_13 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_35 = V_35 ;
F_4 ( V_11 , V_2 , V_3 , & V_13 , & V_15 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_21 * V_30 ,
struct V_21 * V_28 )
{
unsigned long V_16 ;
F_12 () ;
if ( ! V_28 ||
( ( V_28 != V_30 &&
! F_14 ( V_28 , V_30 ) ) ||
F_7 ( V_28 ,
F_17 ( V_28 ) ) ==
V_26 ) ) {
F_15 () ;
return;
}
F_15 () ;
V_16 = F_1 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_3 , V_28 , V_16 ,
V_38 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_21 * V_30 ,
struct V_21 * V_28 )
{
struct V_21 * V_31 = F_13 ( V_30 ) ;
if ( ! V_28 )
return;
if ( ! V_31 )
V_31 = V_30 ;
F_12 () ;
if ( F_14 ( V_28 , V_30 ) &&
F_7 ( V_28 , V_31 ) ==
V_26 ) {
unsigned long V_16 ;
F_15 () ;
V_16 = F_1 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_3 , V_28 ,
V_16 ,
V_39 ) ;
} else {
F_15 () ;
}
}
static void F_25 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_21 * V_35 )
{
struct V_40 * V_41 ;
struct V_42 {
struct V_43 V_44 ;
struct V_45 V_46 ;
};
struct V_42 * V_47 ;
struct V_42 * V_48 ;
F_26 ( V_42 ) ;
if ( V_35 -> V_49 >= V_50 )
return;
F_12 () ;
V_41 = F_27 ( V_35 ) ;
if ( ! V_41 ) {
F_15 () ;
return;
}
F_28 (in_dev) {
struct V_42 * V_51 = F_29 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
continue;
V_51 -> V_46 . V_53 = V_54 ;
V_51 -> V_46 . V_55 . V_56 = V_57 -> V_58 ;
F_30 ( & V_51 -> V_44 , & V_42 ) ;
}
F_31 ( V_41 ) ;
F_15 () ;
F_32 (sin_iter, sin_temp, &sin_list, list) {
F_20 ( V_18 , V_2 , V_3 , V_35 ,
(struct V_36 * ) & V_47 -> V_46 ) ;
F_33 ( & V_47 -> V_44 ) ;
F_34 ( V_47 ) ;
}
}
static void F_35 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_21 * V_35 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_63 {
struct V_43 V_44 ;
struct V_64 V_65 ;
};
struct V_63 * V_66 ;
struct V_63 * V_67 ;
struct V_14 V_15 = { . V_35 = V_35 } ;
F_26 ( V_63 ) ;
if ( V_35 -> V_49 >= V_50 )
return;
V_62 = F_36 ( V_35 ) ;
if ( ! V_62 )
return;
F_37 ( & V_62 -> V_68 ) ;
F_38 (ifp, &in6_dev->addr_list, if_list) {
struct V_63 * V_51 = F_29 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
continue;
V_51 -> V_65 . V_69 = V_70 ;
V_51 -> V_65 . V_71 = V_60 -> V_37 ;
F_30 ( & V_51 -> V_44 , & V_63 ) ;
}
F_39 ( & V_62 -> V_68 ) ;
F_40 ( V_62 ) ;
F_32 (sin6_iter, sin6_temp, &sin6_list, list) {
union V_12 V_13 ;
F_21 ( (struct V_36 * ) & V_66 -> V_65 , & V_13 ) ;
F_4 ( V_18 , V_2 , V_3 , & V_13 , & V_15 ) ;
F_33 ( & V_66 -> V_44 ) ;
F_34 ( V_66 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_35 )
{
F_25 ( V_2 , V_3 , V_35 ) ;
if ( F_42 ( V_72 ) )
F_35 ( V_2 , V_3 , V_35 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_29 ;
F_22 ( V_2 , V_3 , V_30 , V_28 ) ;
F_41 ( V_2 , V_3 , V_30 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_29 ;
F_45 ( V_2 , V_3 , V_30 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_21 * V_28 ,
void * V_29 )
{
struct V_73 * V_73 ;
struct V_21 * V_35 ;
F_47 () ;
F_48 (net)
F_49 (net, ndev)
if ( F_11 ( V_2 , V_3 , V_28 , V_35 ) )
F_43 ( V_2 , V_3 , V_28 , V_35 ) ;
F_50 () ;
}
int F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 , F_18 , NULL ,
F_46 , NULL ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_74 ,
T_1 V_3 ,
struct V_21 * V_28 ,
void * V_29 )
{
struct V_75 * V_76 = V_29 ;
return F_4 ( V_76 -> V_11 , V_74 ,
V_3 , & V_76 -> V_13 ,
& V_76 -> V_15 ) ;
}
static int F_54 ( struct V_21 * V_23 , void * V_77 )
{
struct V_78 * V_51 = F_55 ( sizeof( * V_51 ) , V_52 ) ;
struct V_43 * V_78 = V_77 ;
if ( ! V_51 )
return 0 ;
F_30 ( & V_51 -> V_44 , V_78 ) ;
F_56 ( V_23 ) ;
V_51 -> V_23 = V_23 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_29 ,
void (* F_58)( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_21 * V_35 ) )
{
struct V_21 * V_35 = (struct V_21 * ) V_29 ;
struct V_78 * V_79 ;
struct V_78 * V_80 ;
F_26 ( V_78 ) ;
F_12 () ;
F_59 ( V_35 , F_54 , & V_78 ) ;
F_15 () ;
F_58 ( V_2 , V_3 , V_35 ) ;
F_32 (upper_iter, upper_temp, &upper_list,
list) {
F_58 ( V_2 , V_3 , V_79 -> V_23 ) ;
F_60 ( V_79 -> V_23 ) ;
F_33 ( & V_79 -> V_44 ) ;
F_34 ( V_79 ) ;
}
}
static void F_61 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_30 )
{
F_45 ( V_2 , V_3 , V_30 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
F_57 ( V_2 , V_3 , V_29 , F_61 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
F_57 ( V_2 , V_3 , V_29 , F_41 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 ,
void * V_29 )
{
struct V_21 * V_81 ;
F_12 () ;
V_81 = F_17 ( V_28 ) ;
if ( V_81 )
F_56 ( V_81 ) ;
F_15 () ;
if ( V_81 ) {
F_24 ( V_2 , V_3 , V_81 ,
V_28 ) ;
F_60 ( V_81 ) ;
}
}
static void F_65 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_28 , void * V_29 )
{
struct V_21 * V_30 = (struct V_21 * ) V_29 ;
F_24 ( V_2 , V_3 , V_30 , V_28 ) ;
}
static void F_66 ( struct V_82 * V_83 )
{
struct V_84 * V_85 =
F_67 ( V_83 , struct V_84 , V_85 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_68 ( V_85 -> V_86 ) && V_85 -> V_86 [ V_4 ] . V_87 ; V_4 ++ ) {
F_69 ( V_85 -> V_86 [ V_4 ] . V_88 ,
V_85 -> V_86 [ V_4 ] . V_89 ,
V_85 -> V_86 [ V_4 ] . V_87 ,
V_85 -> V_86 [ V_4 ] . V_35 ) ;
F_60 ( V_85 -> V_86 [ V_4 ] . V_35 ) ;
F_60 ( V_85 -> V_86 [ V_4 ] . V_89 ) ;
}
F_34 ( V_85 ) ;
}
static int F_70 ( struct V_90 * V_86 ,
struct V_21 * V_35 )
{
unsigned int V_4 ;
struct V_84 * V_91 =
F_55 ( sizeof( * V_91 ) , V_92 ) ;
if ( ! V_91 )
return V_93 ;
memcpy ( V_91 -> V_86 , V_86 , sizeof( V_91 -> V_86 ) ) ;
for ( V_4 = 0 ; V_4 < F_68 ( V_91 -> V_86 ) && V_91 -> V_86 [ V_4 ] . V_87 ; V_4 ++ ) {
if ( ! V_91 -> V_86 [ V_4 ] . V_35 )
V_91 -> V_86 [ V_4 ] . V_35 = V_35 ;
if ( ! V_91 -> V_86 [ V_4 ] . V_89 )
V_91 -> V_86 [ V_4 ] . V_89 = V_35 ;
F_56 ( V_91 -> V_86 [ V_4 ] . V_35 ) ;
F_56 ( V_91 -> V_86 [ V_4 ] . V_89 ) ;
}
F_71 ( & V_91 -> V_85 , F_66 ) ;
F_72 ( V_94 , & V_91 -> V_85 ) ;
return V_93 ;
}
static void F_73 ( struct V_95 * V_96 ,
struct V_90 * V_86 )
{
static const struct V_90 V_97 = {
. V_87 = F_62 , . V_88 = F_19 } ;
static const struct V_90 V_98 = {
. V_87 = F_65 , . V_88 = F_16 } ;
if ( V_96 -> V_99 == false ) {
V_86 [ 0 ] = V_97 ;
V_86 [ 0 ] . V_35 = V_96 -> V_100 ;
V_86 [ 1 ] = V_101 ;
} else {
V_86 [ 0 ] = V_98 ;
V_86 [ 0 ] . V_35 = V_96 -> V_100 ;
V_86 [ 1 ] = V_102 ;
V_86 [ 1 ] . V_35 = V_96 -> V_100 ;
V_86 [ 1 ] . V_89 = V_96 -> V_100 ;
}
}
static int F_74 ( struct V_103 * V_104 , unsigned long V_105 ,
void * V_106 )
{
static const struct V_90 V_107 = {
. V_87 = F_44 , . V_88 = F_18 } ;
static const struct V_90 V_108 = {
. V_87 = F_64 , . V_88 = F_16 } ;
static const struct V_90 V_109 = {
. V_87 = F_65 , . V_88 = F_18 } ;
static const struct V_90 V_110 = {
. V_87 = F_62 , . V_88 = F_19 } ;
struct V_21 * V_35 = F_75 ( V_106 ) ;
struct V_90 V_86 [ V_111 ] = { { NULL } } ;
if ( V_35 -> type != V_112 )
return V_93 ;
switch ( V_105 ) {
case V_113 :
case V_114 :
V_86 [ 0 ] = V_108 ;
V_86 [ 1 ] = V_101 ;
break;
case V_115 :
if ( V_35 -> V_49 < V_116 )
V_86 [ 0 ] = V_107 ;
else
return V_93 ;
break;
case V_117 :
V_86 [ 0 ] = V_109 ;
V_86 [ 1 ] = V_101 ;
break;
case V_118 :
F_73 (
F_67 ( V_106 , struct V_95 , V_119 ) ,
V_86 ) ;
break;
case V_120 :
V_86 [ 0 ] = V_110 ;
V_86 [ 1 ] = V_108 ;
V_86 [ 2 ] = V_102 ;
break;
default:
return V_93 ;
}
return F_70 ( V_86 , V_35 ) ;
}
static void F_76 ( struct V_82 * V_83 )
{
struct V_75 * V_85 =
F_67 ( V_83 , struct V_75 , V_85 ) ;
F_69 ( F_11 , V_85 -> V_15 . V_35 ,
F_53 , V_85 ) ;
F_60 ( V_85 -> V_15 . V_35 ) ;
F_34 ( V_85 ) ;
}
static int F_77 ( struct V_103 * V_104 , unsigned long V_105 ,
struct V_36 * V_121 , struct V_21 * V_35 )
{
struct V_75 * V_85 ;
enum V_10 V_11 ;
if ( V_35 -> type != V_112 )
return V_93 ;
switch ( V_105 ) {
case V_114 :
V_11 = V_18 ;
break;
case V_122 :
V_11 = V_19 ;
break;
default:
return V_93 ;
}
V_85 = F_55 ( sizeof( * V_85 ) , V_52 ) ;
if ( ! V_85 )
return V_93 ;
F_71 ( & V_85 -> V_85 , F_76 ) ;
F_21 ( V_121 , & V_85 -> V_13 ) ;
V_85 -> V_11 = V_11 ;
memset ( & V_85 -> V_15 , 0 , sizeof( V_85 -> V_15 ) ) ;
F_56 ( V_35 ) ;
V_85 -> V_15 . V_35 = V_35 ;
F_72 ( V_94 , & V_85 -> V_85 ) ;
return V_93 ;
}
static int F_78 ( struct V_103 * V_104 , unsigned long V_105 ,
void * V_106 )
{
struct V_45 V_123 ;
struct V_21 * V_35 ;
struct V_124 * V_57 = V_106 ;
V_123 . V_53 = V_54 ;
V_123 . V_55 . V_56 = V_57 -> V_58 ;
V_35 = V_57 -> V_125 -> V_22 ;
return F_77 ( V_104 , V_105 , (struct V_36 * ) & V_123 , V_35 ) ;
}
static int F_79 ( struct V_103 * V_104 , unsigned long V_105 ,
void * V_106 )
{
struct V_64 V_126 ;
struct V_21 * V_35 ;
struct V_59 * V_127 = V_106 ;
V_126 . V_69 = V_70 ;
V_126 . V_71 = V_127 -> V_37 ;
V_35 = V_127 -> V_128 -> V_22 ;
return F_77 ( V_104 , V_105 , (struct V_36 * ) & V_126 , V_35 ) ;
}
int T_2 F_80 ( void )
{
F_81 ( & V_129 ) ;
if ( F_42 ( V_72 ) )
F_82 ( & V_130 ) ;
F_83 ( & V_131 ) ;
return 0 ;
}
void T_3 F_84 ( void )
{
if ( F_42 ( V_72 ) )
F_85 ( & V_130 ) ;
F_86 ( & V_129 ) ;
F_87 ( & V_131 ) ;
}
