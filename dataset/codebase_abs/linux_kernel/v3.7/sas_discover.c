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
V_47 ) ;
break;
case V_8 :
V_17 = F_16 ( V_13 -> V_13 ,
V_48 ) ;
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
V_17 -> V_49 . V_50 = V_15 -> V_15 -> V_49 . V_50 ;
memcpy ( V_2 -> V_51 , V_13 -> V_52 , V_53 ) ;
F_18 ( V_2 , V_17 ) ;
F_19 ( V_2 -> V_54 , V_2 -> V_51 ) ;
V_13 -> V_55 = V_2 ;
V_2 -> V_56 = V_13 -> V_56 ;
V_2 -> V_57 = V_13 -> V_56 ;
V_2 -> V_58 = V_13 -> V_56 ;
V_2 -> V_59 = V_13 -> V_60 ;
memset ( V_13 -> V_61 . V_62 , 0 , V_53 ) ;
memset ( V_13 -> V_61 . V_63 , 0 , V_53 ) ;
memset ( V_13 -> V_61 . V_64 , 0 , V_53 ) ;
V_13 -> V_61 . V_65 = 0 ;
F_20 ( V_2 , V_13 -> V_13 ) ;
V_2 -> V_17 = V_17 ;
F_21 ( & V_2 -> V_17 -> V_2 ) ;
if ( F_22 ( V_2 ) || V_2 -> V_3 == V_4 )
F_23 ( & V_2 -> V_66 , & V_13 -> V_67 ) ;
else {
F_6 ( & V_13 -> V_68 ) ;
F_23 ( & V_2 -> V_69 , & V_13 -> V_70 ) ;
F_8 ( & V_13 -> V_68 ) ;
}
F_6 ( & V_13 -> V_21 ) ;
F_24 (phy, &port->phy_list, port_phy_el)
F_25 ( V_15 , V_2 ) ;
F_8 ( & V_13 -> V_21 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
struct V_72 * V_73 = V_2 -> V_13 -> V_74 ;
struct V_75 * V_76 = V_73 -> V_77 . V_76 ;
struct V_78 * V_79 = F_27 ( V_76 -> V_80 ) ;
if ( ! V_79 -> V_81 -> V_82 )
return 0 ;
V_71 = V_79 -> V_81 -> V_82 ( V_2 ) ;
if ( V_71 ) {
F_17 ( L_2
L_3 ,
F_28 ( V_73 -> V_2 ) ,
F_29 ( V_2 -> V_51 ) , V_71 ) ;
}
F_30 ( V_83 , & V_2 -> V_84 ) ;
F_31 ( & V_2 -> V_85 ) ;
return V_71 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = V_2 -> V_13 -> V_74 ;
struct V_75 * V_76 = V_73 -> V_77 . V_76 ;
struct V_78 * V_79 = F_27 ( V_76 -> V_80 ) ;
if ( ! V_79 -> V_81 -> V_86 )
return;
if ( F_33 ( V_83 , & V_2 -> V_84 ) ) {
V_79 -> V_81 -> V_86 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
static void F_34 ( struct V_87 * V_88 )
{
struct V_1 * V_2 , * V_89 ;
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_36 ( V_92 , & V_13 -> V_61 . V_93 ) ;
F_24 (dev, &port->disco_list, disco_list_node) {
F_6 ( & V_13 -> V_68 ) ;
F_23 ( & V_2 -> V_69 , & V_13 -> V_70 ) ;
F_8 ( & V_13 -> V_68 ) ;
}
F_37 ( V_13 ) ;
F_38 (dev, n, &port->disco_list, disco_list_node) {
int V_94 ;
V_94 = F_39 ( V_2 -> V_17 ) ;
if ( V_94 )
F_40 ( V_2 , V_95 , V_94 ) ;
else
F_41 ( & V_2 -> V_66 ) ;
}
}
static void F_42 ( struct V_87 * V_88 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
struct V_75 * V_76 = V_13 -> V_74 -> V_77 . V_76 ;
struct V_78 * V_96 = F_27 ( V_76 -> V_80 ) ;
F_36 ( V_97 , & V_13 -> V_61 . V_93 ) ;
F_43 ( V_13 ) ;
F_24 (dev, &port->dev_list, dev_list_node)
F_32 ( V_2 ) ;
F_24 (phy, &port->phy_list, port_phy_el) {
if ( V_96 -> V_81 -> V_98 )
V_96 -> V_81 -> V_99 ( V_15 ) ;
V_15 -> V_100 = 1 ;
V_13 -> V_100 = 1 ;
}
}
static void F_44 ( struct V_87 * V_88 )
{
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_36 ( V_101 , & V_13 -> V_61 . V_93 ) ;
F_45 ( V_13 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_71 ;
V_71 = F_26 ( V_2 ) ;
if ( V_71 )
return V_71 ;
F_47 ( V_2 -> V_13 , V_92 ) ;
return 0 ;
}
void F_48 ( struct V_85 * V_85 )
{
struct V_1 * V_2 = F_10 ( V_85 , F_49 ( * V_2 ) , V_85 ) ;
F_50 ( & V_2 -> V_17 -> V_2 ) ;
V_2 -> V_17 = NULL ;
if ( V_2 -> V_102 )
F_9 ( V_2 -> V_102 ) ;
F_51 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_3 == V_7 || V_2 -> V_3 == V_8 )
F_52 ( V_2 -> V_9 . V_103 ) ;
if ( F_22 ( V_2 ) && V_2 -> V_104 . V_105 ) {
F_53 ( V_2 -> V_104 . V_105 ) ;
V_2 -> V_104 . V_105 = NULL ;
}
F_52 ( V_2 ) ;
}
static void F_54 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_72 * V_74 = V_13 -> V_74 ;
F_32 ( V_2 ) ;
if ( ! V_2 -> V_102 )
V_2 -> V_13 -> V_55 = NULL ;
else
F_41 ( & V_2 -> V_106 ) ;
F_6 ( & V_13 -> V_68 ) ;
F_41 ( & V_2 -> V_69 ) ;
if ( F_22 ( V_2 ) )
F_55 ( V_2 -> V_104 . V_105 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_6 ( & V_74 -> V_107 ) ;
if ( V_2 -> V_3 == V_4 &&
! F_7 ( & V_2 -> V_5 . V_6 ) ) {
F_41 ( & V_2 -> V_5 . V_6 ) ;
V_74 -> V_108 -- ;
}
F_8 ( & V_74 -> V_107 ) ;
F_9 ( V_2 ) ;
}
static void F_56 ( struct V_87 * V_88 )
{
struct V_1 * V_2 , * V_89 ;
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_36 ( V_109 , & V_13 -> V_61 . V_93 ) ;
F_38 (dev, n, &port->destroy_list, disco_list_node) {
F_41 ( & V_2 -> V_66 ) ;
F_57 ( & V_2 -> V_17 -> V_2 ) ;
F_58 ( V_2 -> V_17 ) ;
F_54 ( V_13 , V_2 ) ;
}
}
void F_59 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
if ( ! F_60 ( V_110 , & V_2 -> V_84 ) &&
! F_7 ( & V_2 -> V_66 ) ) {
F_41 ( & V_2 -> V_66 ) ;
F_61 ( V_2 -> V_17 ) ;
F_54 ( V_13 , V_2 ) ;
return;
}
if ( ! F_62 ( V_110 , & V_2 -> V_84 ) ) {
F_63 ( V_2 -> V_17 ) ;
F_64 ( & V_2 -> V_66 , & V_13 -> V_111 ) ;
F_47 ( V_2 -> V_13 , V_109 ) ;
}
}
void F_65 ( struct V_12 * V_13 , int V_112 )
{
struct V_1 * V_2 , * V_89 ;
F_66 (dev, n, &port->dev_list, dev_list_node) {
if ( V_112 )
F_30 ( V_113 , & V_2 -> V_84 ) ;
F_59 ( V_13 , V_2 ) ;
}
F_38 (dev, n, &port->disco_list, disco_list_node)
F_59 ( V_13 , V_2 ) ;
V_13 -> V_13 -> V_17 = NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_114 * V_13 )
{
struct V_72 * V_74 ;
struct V_115 * V_116 ;
if ( ! V_2 )
return;
V_74 = V_2 -> V_13 -> V_74 ;
V_116 = F_67 ( V_13 ) ;
F_6 ( & V_74 -> V_117 ) ;
if ( V_116 ) {
F_51 ( V_2 -> V_15 ) ;
V_2 -> V_15 = V_116 ;
}
F_8 ( & V_74 -> V_117 ) ;
}
static void F_68 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
int error = 0 ;
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_36 ( V_118 , & V_13 -> V_61 . V_93 ) ;
if ( V_13 -> V_55 )
return;
error = F_4 ( V_13 ) ;
if ( error )
return;
V_2 = V_13 -> V_55 ;
F_69 ( L_4 , V_13 -> V_43 ,
F_70 ( V_119 ) ) ;
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
error = - V_120 ;
F_69 ( L_6 , V_2 -> V_3 ) ;
break;
}
if ( error ) {
F_61 ( V_2 -> V_17 ) ;
F_41 ( & V_2 -> V_66 ) ;
F_6 ( & V_13 -> V_68 ) ;
F_41 ( & V_2 -> V_69 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_9 ( V_2 ) ;
V_13 -> V_55 = NULL ;
}
F_69 ( L_7 , V_13 -> V_43 ,
F_70 ( V_119 ) , error ) ;
}
static void F_74 ( struct V_87 * V_88 )
{
int V_71 = 0 ;
struct V_90 * V_91 = F_35 ( V_88 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
struct V_72 * V_74 = V_13 -> V_74 ;
F_75 ( & V_74 -> V_121 ) ;
if ( F_60 ( V_122 , & V_74 -> V_84 ) ) {
F_69 ( L_8 ,
V_13 -> V_43 , F_70 ( V_119 ) ) ;
goto V_123;
}
F_36 ( V_124 , & V_13 -> V_61 . V_93 ) ;
F_69 ( L_9 , V_13 -> V_43 ,
F_70 ( V_119 ) ) ;
if ( V_13 -> V_55 )
V_71 = F_76 ( V_13 -> V_55 ) ;
F_69 ( L_10 ,
V_13 -> V_43 , F_70 ( V_119 ) , V_71 ) ;
V_123:
F_77 ( & V_74 -> V_121 ) ;
}
static void F_78 ( struct V_72 * V_74 , struct V_125 * V_126 )
{
F_79 ( V_74 -> V_77 . V_76 , & V_126 -> V_88 ) ;
}
static void F_80 ( int V_127 , unsigned long * V_93 ,
struct V_125 * V_126 ,
struct V_72 * V_74 )
{
if ( ! F_62 ( V_127 , V_93 ) ) {
unsigned long V_128 ;
F_81 ( & V_74 -> V_107 , V_128 ) ;
F_78 ( V_74 , V_126 ) ;
F_82 ( & V_74 -> V_107 , V_128 ) ;
}
}
int F_47 ( struct V_12 * V_13 , enum V_129 V_91 )
{
struct V_130 * V_61 ;
if ( ! V_13 )
return 0 ;
V_61 = & V_13 -> V_61 ;
F_83 ( V_91 >= V_131 ) ;
F_80 ( V_91 , & V_61 -> V_93 , & V_61 -> V_132 [ V_91 ] . V_88 , V_13 -> V_74 ) ;
return 0 ;
}
void F_84 ( struct V_130 * V_61 , struct V_12 * V_13 )
{
int V_79 ;
static const T_1 V_133 [ V_131 ] = {
[ V_118 ] = F_68 ,
[ V_124 ] = F_74 ,
[ V_92 ] = F_34 ,
[ V_97 ] = F_42 ,
[ V_101 ] = F_44 ,
[ V_109 ] = F_56 ,
} ;
V_61 -> V_93 = 0 ;
for ( V_79 = 0 ; V_79 < V_131 ; V_79 ++ ) {
F_85 ( & V_61 -> V_132 [ V_79 ] . V_88 , V_133 [ V_79 ] ) ;
V_61 -> V_132 [ V_79 ] . V_13 = V_13 ;
}
}
