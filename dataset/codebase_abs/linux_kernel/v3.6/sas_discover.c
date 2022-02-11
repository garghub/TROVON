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
if ( V_79 -> V_81 -> V_82 ) {
V_71 = V_79 -> V_81 -> V_82 ( V_2 ) ;
if ( V_71 ) {
F_17 ( L_2
L_3 ,
F_28 ( V_73 -> V_2 ) ,
F_29 ( V_2 -> V_51 ) , V_71 ) ;
}
F_30 ( & V_2 -> V_83 ) ;
}
return V_71 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = V_2 -> V_13 -> V_74 ;
struct V_75 * V_76 = V_73 -> V_77 . V_76 ;
struct V_78 * V_79 = F_27 ( V_76 -> V_80 ) ;
if ( V_79 -> V_81 -> V_84 ) {
V_79 -> V_81 -> V_84 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
static void F_32 ( struct V_85 * V_86 )
{
struct V_1 * V_2 , * V_87 ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_34 ( V_90 , & V_13 -> V_61 . V_91 ) ;
F_24 (dev, &port->disco_list, disco_list_node) {
F_6 ( & V_13 -> V_68 ) ;
F_23 ( & V_2 -> V_69 , & V_13 -> V_70 ) ;
F_8 ( & V_13 -> V_68 ) ;
}
F_35 ( V_13 ) ;
F_36 (dev, n, &port->disco_list, disco_list_node) {
int V_92 ;
V_92 = F_37 ( V_2 -> V_17 ) ;
if ( V_92 )
F_38 ( V_2 , V_93 , V_92 ) ;
else
F_39 ( & V_2 -> V_66 ) ;
}
}
int F_40 ( struct V_1 * V_2 )
{
int V_71 ;
V_71 = F_26 ( V_2 ) ;
if ( V_71 )
return V_71 ;
F_41 ( V_2 -> V_13 , V_90 ) ;
return 0 ;
}
void F_42 ( struct V_83 * V_83 )
{
struct V_1 * V_2 = F_10 ( V_83 , F_43 ( * V_2 ) , V_83 ) ;
F_44 ( & V_2 -> V_17 -> V_2 ) ;
V_2 -> V_17 = NULL ;
if ( V_2 -> V_94 )
F_9 ( V_2 -> V_94 ) ;
F_45 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_3 == V_7 || V_2 -> V_3 == V_8 )
F_46 ( V_2 -> V_9 . V_95 ) ;
if ( F_22 ( V_2 ) && V_2 -> V_96 . V_97 ) {
F_47 ( V_2 -> V_96 . V_97 ) ;
V_2 -> V_96 . V_97 = NULL ;
}
F_46 ( V_2 ) ;
}
static void F_48 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_72 * V_74 = V_13 -> V_74 ;
F_31 ( V_2 ) ;
if ( ! V_2 -> V_94 )
V_2 -> V_13 -> V_55 = NULL ;
else
F_39 ( & V_2 -> V_98 ) ;
F_6 ( & V_13 -> V_68 ) ;
F_39 ( & V_2 -> V_69 ) ;
if ( F_22 ( V_2 ) )
F_49 ( V_2 -> V_96 . V_97 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_6 ( & V_74 -> V_99 ) ;
if ( V_2 -> V_3 == V_4 &&
! F_7 ( & V_2 -> V_5 . V_6 ) ) {
F_39 ( & V_2 -> V_5 . V_6 ) ;
V_74 -> V_100 -- ;
}
F_8 ( & V_74 -> V_99 ) ;
F_9 ( V_2 ) ;
}
static void F_50 ( struct V_85 * V_86 )
{
struct V_1 * V_2 , * V_87 ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_34 ( V_101 , & V_13 -> V_61 . V_91 ) ;
F_36 (dev, n, &port->destroy_list, disco_list_node) {
F_39 ( & V_2 -> V_66 ) ;
F_51 ( & V_2 -> V_17 -> V_2 ) ;
F_52 ( V_2 -> V_17 ) ;
F_48 ( V_13 , V_2 ) ;
}
}
void F_53 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
if ( ! F_54 ( V_102 , & V_2 -> V_103 ) &&
! F_7 ( & V_2 -> V_66 ) ) {
F_39 ( & V_2 -> V_66 ) ;
F_55 ( V_2 -> V_17 ) ;
F_48 ( V_13 , V_2 ) ;
return;
}
if ( ! F_56 ( V_102 , & V_2 -> V_103 ) ) {
F_57 ( V_2 -> V_17 ) ;
F_58 ( & V_2 -> V_66 , & V_13 -> V_104 ) ;
F_41 ( V_2 -> V_13 , V_101 ) ;
}
}
void F_59 ( struct V_12 * V_13 , int V_105 )
{
struct V_1 * V_2 , * V_87 ;
F_60 (dev, n, &port->dev_list, dev_list_node) {
if ( V_105 )
F_61 ( V_106 , & V_2 -> V_103 ) ;
F_53 ( V_13 , V_2 ) ;
}
F_36 (dev, n, &port->disco_list, disco_list_node)
F_53 ( V_13 , V_2 ) ;
V_13 -> V_13 -> V_17 = NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_107 * V_13 )
{
struct V_72 * V_74 ;
struct V_108 * V_109 ;
if ( ! V_2 )
return;
V_74 = V_2 -> V_13 -> V_74 ;
V_109 = F_62 ( V_13 ) ;
F_6 ( & V_74 -> V_110 ) ;
if ( V_109 ) {
F_45 ( V_2 -> V_15 ) ;
V_2 -> V_15 = V_109 ;
}
F_8 ( & V_74 -> V_110 ) ;
}
static void F_63 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
int error = 0 ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
F_34 ( V_111 , & V_13 -> V_61 . V_91 ) ;
if ( V_13 -> V_55 )
return;
error = F_4 ( V_13 ) ;
if ( error )
return;
V_2 = V_13 -> V_55 ;
F_64 ( L_4 , V_13 -> V_43 ,
F_65 ( V_112 ) ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
error = F_40 ( V_2 ) ;
break;
case V_7 :
case V_8 :
error = F_66 ( V_2 ) ;
break;
case V_39 :
case V_38 :
#ifdef F_67
error = F_68 ( V_2 ) ;
break;
#else
F_64 ( L_5 ) ;
#endif
default:
error = - V_113 ;
F_64 ( L_6 , V_2 -> V_3 ) ;
break;
}
if ( error ) {
F_55 ( V_2 -> V_17 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_6 ( & V_13 -> V_68 ) ;
F_39 ( & V_2 -> V_69 ) ;
F_8 ( & V_13 -> V_68 ) ;
F_9 ( V_2 ) ;
V_13 -> V_55 = NULL ;
}
F_64 ( L_7 , V_13 -> V_43 ,
F_65 ( V_112 ) , error ) ;
}
static void F_69 ( struct V_85 * V_86 )
{
int V_71 = 0 ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_12 * V_13 = V_89 -> V_13 ;
struct V_72 * V_74 = V_13 -> V_74 ;
F_70 ( & V_74 -> V_114 ) ;
if ( F_54 ( V_115 , & V_74 -> V_103 ) ) {
F_64 ( L_8 ,
V_13 -> V_43 , F_65 ( V_112 ) ) ;
goto V_116;
}
F_34 ( V_117 , & V_13 -> V_61 . V_91 ) ;
F_64 ( L_9 , V_13 -> V_43 ,
F_65 ( V_112 ) ) ;
if ( V_13 -> V_55 )
V_71 = F_71 ( V_13 -> V_55 ) ;
F_64 ( L_10 ,
V_13 -> V_43 , F_65 ( V_112 ) , V_71 ) ;
V_116:
F_72 ( & V_74 -> V_114 ) ;
}
static void F_73 ( struct V_72 * V_74 , struct V_118 * V_119 )
{
F_74 ( V_74 -> V_77 . V_76 , & V_119 -> V_86 ) ;
}
static void F_75 ( int V_120 , unsigned long * V_91 ,
struct V_118 * V_119 ,
struct V_72 * V_74 )
{
if ( ! F_56 ( V_120 , V_91 ) ) {
unsigned long V_121 ;
F_76 ( & V_74 -> V_99 , V_121 ) ;
F_73 ( V_74 , V_119 ) ;
F_77 ( & V_74 -> V_99 , V_121 ) ;
}
}
int F_41 ( struct V_12 * V_13 , enum V_122 V_89 )
{
struct V_123 * V_61 ;
if ( ! V_13 )
return 0 ;
V_61 = & V_13 -> V_61 ;
F_78 ( V_89 >= V_124 ) ;
F_75 ( V_89 , & V_61 -> V_91 , & V_61 -> V_125 [ V_89 ] . V_86 , V_13 -> V_74 ) ;
return 0 ;
}
void F_79 ( struct V_123 * V_61 , struct V_12 * V_13 )
{
int V_79 ;
static const T_1 V_126 [ V_124 ] = {
[ V_111 ] = F_63 ,
[ V_117 ] = F_69 ,
[ V_90 ] = F_32 ,
[ V_101 ] = F_50 ,
} ;
V_61 -> V_91 = 0 ;
for ( V_79 = 0 ; V_79 < V_124 ; V_79 ++ ) {
F_80 ( & V_61 -> V_125 [ V_79 ] . V_86 , V_126 [ V_79 ] ) ;
V_61 -> V_125 [ V_79 ] . V_13 = V_13 ;
}
}
