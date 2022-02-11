void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
F_2 ( & V_2 -> V_5 . V_6 ) ;
break;
case V_7 :
case V_8 :
F_2 ( & V_2 -> V_9 . V_10 ) ;
F_3 ( & V_2 -> V_9 . V_11 ) ;
break;
default:
break;
}
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_18 = - V_19 ;
V_2 = F_5 () ;
if ( ! V_2 )
return - V_20 ;
F_6 ( & V_13 -> V_21 ) ;
if ( F_7 ( & V_13 -> V_22 ) ) {
F_8 ( & V_13 -> V_21 ) ;
F_9 ( V_2 ) ;
return - V_19 ;
}
V_15 = F_10 ( V_13 -> V_22 . V_23 , struct V_14 , V_24 ) ;
F_11 ( & V_15 -> V_25 ) ;
memcpy ( V_2 -> V_26 , V_15 -> V_26 , F_12 ( sizeof( V_2 -> V_26 ) ,
( V_27 ) V_15 -> V_28 ) ) ;
F_13 ( & V_15 -> V_25 ) ;
F_8 ( & V_13 -> V_21 ) ;
if ( V_2 -> V_26 [ 0 ] == 0x34 && V_13 -> V_29 == V_30 ) {
struct V_31 * V_32 =
(struct V_31 * ) V_2 -> V_26 ;
if ( V_32 -> V_33 == 1 && V_32 -> V_34 == 1 &&
V_32 -> V_35 == 0x69 && V_32 -> V_36 == 0x96
&& ( V_32 -> V_37 & ~ 0x10 ) == 0 )
V_2 -> V_3 = V_38 ;
else
V_2 -> V_3 = V_39 ;
V_2 -> V_40 = V_41 ;
} else {
struct V_42 * V_43 =
(struct V_42 * ) V_2 -> V_26 ;
V_2 -> V_3 = V_43 -> V_3 ;
V_2 -> V_44 = V_43 -> V_45 ;
V_2 -> V_40 = V_43 -> V_46 ;
}
F_1 ( V_2 ) ;
V_2 -> V_13 = V_13 ;
switch ( V_2 -> V_3 ) {
case V_39 :
V_18 = F_14 ( V_2 ) ;
if ( V_18 ) {
V_17 = NULL ;
break;
}
case V_4 :
V_17 = F_15 ( V_13 -> V_13 ) ;
break;
case V_7 :
V_17 = F_16 ( V_13 -> V_13 ,
V_7 ) ;
break;
case V_8 :
V_17 = F_16 ( V_13 -> V_13 ,
V_8 ) ;
break;
default:
F_17 ( L_1 , V_2 -> V_3 ) ;
V_17 = NULL ;
break;
}
if ( ! V_17 ) {
F_9 ( V_2 ) ;
return V_18 ;
}
V_17 -> V_47 . V_48 = V_15 -> V_15 -> V_47 . V_48 ;
memcpy ( V_2 -> V_49 , V_13 -> V_50 , V_51 ) ;
F_18 ( V_2 , V_17 ) ;
F_19 ( V_2 -> V_52 , V_2 -> V_49 ) ;
V_13 -> V_53 = V_2 ;
V_2 -> V_54 = V_13 -> V_54 ;
V_2 -> V_55 = V_13 -> V_54 ;
V_2 -> V_56 = V_13 -> V_54 ;
V_2 -> V_57 = V_13 -> V_58 ;
memset ( V_13 -> V_59 . V_60 , 0 , V_51 ) ;
memset ( V_13 -> V_59 . V_61 , 0 , V_51 ) ;
memset ( V_13 -> V_59 . V_62 , 0 , V_51 ) ;
V_13 -> V_59 . V_63 = 0 ;
F_20 ( V_2 , V_13 -> V_13 ) ;
V_2 -> V_17 = V_17 ;
F_21 ( & V_2 -> V_17 -> V_2 ) ;
if ( F_22 ( V_2 ) || V_2 -> V_3 == V_4 )
F_23 ( & V_2 -> V_64 , & V_13 -> V_65 ) ;
else {
F_6 ( & V_13 -> V_66 ) ;
F_23 ( & V_2 -> V_67 , & V_13 -> V_68 ) ;
F_8 ( & V_13 -> V_66 ) ;
}
F_6 ( & V_13 -> V_21 ) ;
F_24 (phy, &port->phy_list, port_phy_el)
F_25 ( V_15 , V_2 ) ;
F_8 ( & V_13 -> V_21 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_69 = 0 ;
struct V_70 * V_71 = V_2 -> V_13 -> V_72 ;
struct V_73 * V_74 = V_71 -> V_75 . V_74 ;
struct V_76 * V_77 = F_27 ( V_74 -> V_78 ) ;
if ( ! V_77 -> V_79 -> V_80 )
return 0 ;
V_69 = V_77 -> V_79 -> V_80 ( V_2 ) ;
if ( V_69 ) {
F_17 ( L_2
L_3 ,
F_28 ( V_71 -> V_2 ) ,
F_29 ( V_2 -> V_49 ) , V_69 ) ;
}
F_30 ( V_81 , & V_2 -> V_82 ) ;
F_31 ( & V_2 -> V_83 ) ;
return V_69 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = V_2 -> V_13 -> V_72 ;
struct V_73 * V_74 = V_71 -> V_75 . V_74 ;
struct V_76 * V_77 = F_27 ( V_74 -> V_78 ) ;
if ( ! V_77 -> V_79 -> V_84 )
return;
if ( F_33 ( V_81 , & V_2 -> V_82 ) ) {
V_77 -> V_79 -> V_84 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
static void F_34 ( struct V_85 * V_86 )
{
struct V_1 * V_2 , * V_87 ;
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_36 ( V_90 , & V_13 -> V_59 . V_91 ) ;
F_24 (dev, &port->disco_list, disco_list_node) {
F_6 ( & V_13 -> V_66 ) ;
F_23 ( & V_2 -> V_67 , & V_13 -> V_68 ) ;
F_8 ( & V_13 -> V_66 ) ;
}
F_37 ( V_13 ) ;
F_38 (dev, n, &port->disco_list, disco_list_node) {
int V_92 ;
V_92 = F_39 ( V_2 -> V_17 ) ;
if ( V_92 )
F_40 ( V_2 , V_93 , V_92 ) ;
else
F_41 ( & V_2 -> V_64 ) ;
}
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
struct V_73 * V_74 = V_13 -> V_72 -> V_75 . V_74 ;
struct V_76 * V_94 = F_27 ( V_74 -> V_78 ) ;
F_36 ( V_95 , & V_13 -> V_59 . V_91 ) ;
F_43 ( V_13 ) ;
F_24 (dev, &port->dev_list, dev_list_node)
F_32 ( V_2 ) ;
F_24 (phy, &port->phy_list, port_phy_el) {
if ( V_94 -> V_79 -> V_96 )
V_94 -> V_79 -> V_97 ( V_15 ) ;
V_15 -> V_98 = 1 ;
V_13 -> V_98 = 1 ;
}
}
static void F_44 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_36 ( V_99 , & V_13 -> V_59 . V_91 ) ;
F_45 ( V_13 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_69 ;
V_69 = F_26 ( V_2 ) ;
if ( V_69 )
return V_69 ;
F_47 ( V_2 -> V_13 , V_90 ) ;
return 0 ;
}
void F_48 ( struct V_83 * V_83 )
{
struct V_1 * V_2 = F_10 ( V_83 , F_49 ( * V_2 ) , V_83 ) ;
F_50 ( & V_2 -> V_17 -> V_2 ) ;
V_2 -> V_17 = NULL ;
if ( V_2 -> V_100 )
F_9 ( V_2 -> V_100 ) ;
F_51 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_3 == V_7 || V_2 -> V_3 == V_8 )
F_52 ( V_2 -> V_9 . V_101 ) ;
if ( F_22 ( V_2 ) && V_2 -> V_102 . V_103 ) {
F_53 ( V_2 -> V_102 . V_103 ) ;
V_2 -> V_102 . V_103 = NULL ;
}
F_52 ( V_2 ) ;
}
static void F_54 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_70 * V_72 = V_13 -> V_72 ;
F_32 ( V_2 ) ;
if ( ! V_2 -> V_100 )
V_2 -> V_13 -> V_53 = NULL ;
else
F_41 ( & V_2 -> V_104 ) ;
F_6 ( & V_13 -> V_66 ) ;
F_41 ( & V_2 -> V_67 ) ;
if ( F_22 ( V_2 ) )
F_55 ( V_2 -> V_102 . V_103 ) ;
F_8 ( & V_13 -> V_66 ) ;
F_6 ( & V_72 -> V_105 ) ;
if ( V_2 -> V_3 == V_4 &&
! F_7 ( & V_2 -> V_5 . V_6 ) ) {
F_41 ( & V_2 -> V_5 . V_6 ) ;
V_72 -> V_106 -- ;
}
F_8 ( & V_72 -> V_105 ) ;
F_9 ( V_2 ) ;
}
static void F_56 ( struct V_85 * V_86 )
{
struct V_1 * V_2 , * V_87 ;
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_36 ( V_107 , & V_13 -> V_59 . V_91 ) ;
F_38 (dev, n, &port->destroy_list, disco_list_node) {
F_41 ( & V_2 -> V_64 ) ;
F_57 ( & V_2 -> V_17 -> V_2 ) ;
F_58 ( V_2 -> V_17 ) ;
F_54 ( V_13 , V_2 ) ;
}
}
void F_59 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
if ( ! F_60 ( V_108 , & V_2 -> V_82 ) &&
! F_7 ( & V_2 -> V_64 ) ) {
F_41 ( & V_2 -> V_64 ) ;
F_61 ( V_2 -> V_17 ) ;
F_54 ( V_13 , V_2 ) ;
return;
}
if ( ! F_62 ( V_108 , & V_2 -> V_82 ) ) {
F_63 ( V_2 -> V_17 ) ;
F_64 ( & V_2 -> V_64 , & V_13 -> V_109 ) ;
F_47 ( V_2 -> V_13 , V_107 ) ;
}
}
void F_65 ( struct V_12 * V_13 , int V_110 )
{
struct V_1 * V_2 , * V_87 ;
F_66 (dev, n, &port->dev_list, dev_list_node) {
if ( V_110 )
F_30 ( V_111 , & V_2 -> V_82 ) ;
F_59 ( V_13 , V_2 ) ;
}
F_38 (dev, n, &port->disco_list, disco_list_node)
F_59 ( V_13 , V_2 ) ;
V_13 -> V_13 -> V_17 = NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_112 * V_13 )
{
struct V_70 * V_72 ;
struct V_113 * V_114 ;
if ( ! V_2 )
return;
V_72 = V_2 -> V_13 -> V_72 ;
V_114 = F_67 ( V_13 ) ;
F_6 ( & V_72 -> V_115 ) ;
if ( V_114 ) {
F_51 ( V_2 -> V_15 ) ;
V_2 -> V_15 = V_114 ;
}
F_8 ( & V_72 -> V_115 ) ;
}
static void F_68 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
int error = 0 ;
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_36 ( V_116 , & V_13 -> V_59 . V_91 ) ;
if ( V_13 -> V_53 )
return;
error = F_4 ( V_13 ) ;
if ( error )
return;
V_2 = V_13 -> V_53 ;
F_69 ( L_4 , V_13 -> V_43 ,
F_70 ( V_117 ) ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
error = F_46 ( V_2 ) ;
break;
case V_7 :
case V_8 :
error = F_71 ( V_2 ) ;
break;
case V_39 :
case V_38 :
#ifdef F_72
error = F_73 ( V_2 ) ;
break;
#else
F_69 ( L_5 ) ;
#endif
default:
error = - V_118 ;
F_69 ( L_6 , V_2 -> V_3 ) ;
break;
}
if ( error ) {
F_61 ( V_2 -> V_17 ) ;
F_41 ( & V_2 -> V_64 ) ;
F_6 ( & V_13 -> V_66 ) ;
F_41 ( & V_2 -> V_67 ) ;
F_8 ( & V_13 -> V_66 ) ;
F_9 ( V_2 ) ;
V_13 -> V_53 = NULL ;
}
F_69 ( L_7 , V_13 -> V_43 ,
F_70 ( V_117 ) , error ) ;
}
static void F_74 ( struct V_85 * V_86 )
{
int V_69 = 0 ;
struct V_88 * V_89 = F_35 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
struct V_70 * V_72 = V_13 -> V_72 ;
F_75 ( & V_72 -> V_119 ) ;
if ( F_60 ( V_120 , & V_72 -> V_82 ) ) {
F_69 ( L_8 ,
V_13 -> V_43 , F_70 ( V_117 ) ) ;
goto V_121;
}
F_36 ( V_122 , & V_13 -> V_59 . V_91 ) ;
F_69 ( L_9 , V_13 -> V_43 ,
F_70 ( V_117 ) ) ;
if ( V_13 -> V_53 )
V_69 = F_76 ( V_13 -> V_53 ) ;
F_69 ( L_10 ,
V_13 -> V_43 , F_70 ( V_117 ) , V_69 ) ;
V_121:
F_77 ( & V_72 -> V_119 ) ;
}
static void F_78 ( struct V_70 * V_72 , struct V_123 * V_124 )
{
F_79 ( V_72 -> V_75 . V_74 , & V_124 -> V_86 ) ;
}
static void F_80 ( int V_125 , unsigned long * V_91 ,
struct V_123 * V_124 ,
struct V_70 * V_72 )
{
if ( ! F_62 ( V_125 , V_91 ) ) {
unsigned long V_126 ;
F_81 ( & V_72 -> V_105 , V_126 ) ;
F_78 ( V_72 , V_124 ) ;
F_82 ( & V_72 -> V_105 , V_126 ) ;
}
}
int F_47 ( struct V_12 * V_13 , enum V_127 V_89 )
{
struct V_128 * V_59 ;
if ( ! V_13 )
return 0 ;
V_59 = & V_13 -> V_59 ;
F_83 ( V_89 >= V_129 ) ;
F_80 ( V_89 , & V_59 -> V_91 , & V_59 -> V_130 [ V_89 ] . V_86 , V_13 -> V_72 ) ;
return 0 ;
}
void F_84 ( struct V_128 * V_59 , struct V_12 * V_13 )
{
int V_77 ;
static const T_1 V_131 [ V_129 ] = {
[ V_116 ] = F_68 ,
[ V_122 ] = F_74 ,
[ V_90 ] = F_34 ,
[ V_95 ] = F_42 ,
[ V_99 ] = F_44 ,
[ V_107 ] = F_56 ,
} ;
V_59 -> V_91 = 0 ;
for ( V_77 = 0 ; V_77 < V_129 ; V_77 ++ ) {
F_85 ( & V_59 -> V_130 [ V_77 ] . V_86 , V_131 [ V_77 ] ) ;
V_59 -> V_130 [ V_77 ] . V_13 = V_13 ;
}
}
