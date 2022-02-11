void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
break;
case V_5 :
case V_6 :
F_2 ( & V_2 -> V_7 . V_8 ) ;
F_3 ( & V_2 -> V_7 . V_9 ) ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_2 ( & V_2 -> V_14 . V_8 ) ;
break;
default:
break;
}
}
static int F_4 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
int V_21 = - V_22 ;
V_2 = F_5 () ;
if ( ! V_2 )
return - V_23 ;
F_6 ( & V_16 -> V_24 ) ;
if ( F_7 ( & V_16 -> V_25 ) ) {
F_8 ( & V_16 -> V_24 ) ;
F_9 ( V_2 ) ;
return - V_22 ;
}
V_18 = F_10 ( V_16 -> V_25 . V_26 , struct V_17 , V_27 ) ;
F_11 ( & V_18 -> V_28 ) ;
memcpy ( V_2 -> V_29 , V_18 -> V_29 , F_12 ( sizeof( V_2 -> V_29 ) ,
( V_30 ) V_18 -> V_31 ) ) ;
F_13 ( & V_18 -> V_28 ) ;
F_8 ( & V_16 -> V_24 ) ;
if ( V_2 -> V_29 [ 0 ] == 0x34 && V_16 -> V_32 == V_33 ) {
struct V_34 * V_35 =
(struct V_34 * ) V_2 -> V_29 ;
if ( V_35 -> V_36 == 1 && V_35 -> V_37 == 1 &&
V_35 -> V_38 == 0x69 && V_35 -> V_39 == 0x96
&& ( V_35 -> V_40 & ~ 0x10 ) == 0 )
V_2 -> V_3 = V_11 ;
else
V_2 -> V_3 = V_10 ;
V_2 -> V_41 = V_42 ;
} else {
struct V_43 * V_44 =
(struct V_43 * ) V_2 -> V_29 ;
V_2 -> V_3 = V_44 -> V_3 ;
V_2 -> V_45 = V_44 -> V_46 ;
V_2 -> V_41 = V_44 -> V_47 ;
}
F_1 ( V_2 ) ;
V_2 -> V_16 = V_16 ;
switch ( V_2 -> V_3 ) {
case V_10 :
V_21 = F_14 ( V_2 ) ;
if ( V_21 ) {
V_20 = NULL ;
break;
}
case V_4 :
V_20 = F_15 ( V_16 -> V_16 ) ;
break;
case V_5 :
V_20 = F_16 ( V_16 -> V_16 ,
V_48 ) ;
break;
case V_6 :
V_20 = F_16 ( V_16 -> V_16 ,
V_49 ) ;
break;
default:
F_17 ( L_1 , V_2 -> V_3 ) ;
V_20 = NULL ;
break;
}
if ( ! V_20 ) {
F_9 ( V_2 ) ;
return V_21 ;
}
V_20 -> V_50 . V_51 = V_18 -> V_18 -> V_50 . V_51 ;
memcpy ( V_2 -> V_52 , V_16 -> V_53 , V_54 ) ;
F_18 ( V_2 , V_20 ) ;
F_19 ( V_2 -> V_55 , V_2 -> V_52 ) ;
V_16 -> V_56 = V_2 ;
V_2 -> V_57 = V_16 -> V_57 ;
V_2 -> V_58 = V_16 -> V_57 ;
V_2 -> V_59 = V_16 -> V_57 ;
V_2 -> V_60 = V_16 -> V_61 ;
memset ( V_16 -> V_62 . V_63 , 0 , V_54 ) ;
memset ( V_16 -> V_62 . V_64 , 0 , V_54 ) ;
memset ( V_16 -> V_62 . V_65 , 0 , V_54 ) ;
V_16 -> V_62 . V_66 = 0 ;
F_20 ( V_2 , V_16 -> V_16 ) ;
V_2 -> V_20 = V_20 ;
F_21 ( & V_2 -> V_20 -> V_2 ) ;
if ( F_22 ( V_2 ) || V_2 -> V_3 == V_4 )
F_23 ( & V_2 -> V_67 , & V_16 -> V_68 ) ;
else {
F_6 ( & V_16 -> V_69 ) ;
F_23 ( & V_2 -> V_70 , & V_16 -> V_71 ) ;
F_8 ( & V_16 -> V_69 ) ;
}
F_6 ( & V_16 -> V_24 ) ;
F_24 (phy, &port->phy_list, port_phy_el)
F_25 ( V_18 , V_2 ) ;
F_8 ( & V_16 -> V_24 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_72 = 0 ;
struct V_73 * V_74 = V_2 -> V_16 -> V_75 ;
struct V_76 * V_77 = V_74 -> V_78 . V_77 ;
struct V_79 * V_80 = F_27 ( V_77 -> V_81 ) ;
if ( V_80 -> V_82 -> V_83 ) {
V_72 = V_80 -> V_82 -> V_83 ( V_2 ) ;
if ( V_72 ) {
F_17 ( L_2
L_3 ,
F_28 ( V_74 -> V_2 ) ,
F_29 ( V_2 -> V_52 ) , V_72 ) ;
}
F_30 ( & V_2 -> V_84 ) ;
}
return V_72 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = V_2 -> V_16 -> V_75 ;
struct V_76 * V_77 = V_74 -> V_78 . V_77 ;
struct V_79 * V_80 = F_27 ( V_77 -> V_81 ) ;
if ( V_80 -> V_82 -> V_85 ) {
V_80 -> V_82 -> V_85 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
static void F_32 ( struct V_86 * V_87 )
{
struct V_1 * V_2 , * V_88 ;
struct V_89 * V_90 = F_33 ( V_87 ) ;
struct V_15 * V_16 = V_90 -> V_16 ;
F_34 ( V_91 , & V_16 -> V_62 . V_92 ) ;
F_24 (dev, &port->disco_list, disco_list_node) {
F_6 ( & V_16 -> V_69 ) ;
F_23 ( & V_2 -> V_70 , & V_16 -> V_71 ) ;
F_8 ( & V_16 -> V_69 ) ;
}
F_35 ( V_16 ) ;
F_36 (dev, n, &port->disco_list, disco_list_node) {
int V_93 ;
V_93 = F_37 ( V_2 -> V_20 ) ;
if ( V_93 )
F_38 ( V_2 , V_94 , V_93 ) ;
else
F_39 ( & V_2 -> V_67 ) ;
}
}
int F_40 ( struct V_1 * V_2 )
{
int V_72 ;
V_72 = F_26 ( V_2 ) ;
if ( V_72 )
return V_72 ;
F_41 ( V_2 -> V_16 , V_91 ) ;
return 0 ;
}
void F_42 ( struct V_84 * V_84 )
{
struct V_1 * V_2 = F_10 ( V_84 , F_43 ( * V_2 ) , V_84 ) ;
F_44 ( & V_2 -> V_20 -> V_2 ) ;
V_2 -> V_20 = NULL ;
if ( V_2 -> V_95 )
F_9 ( V_2 -> V_95 ) ;
F_45 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
if ( V_2 -> V_3 == V_5 || V_2 -> V_3 == V_6 )
F_46 ( V_2 -> V_7 . V_96 ) ;
if ( F_22 ( V_2 ) && V_2 -> V_14 . V_97 ) {
F_47 ( V_2 -> V_14 . V_97 ) ;
V_2 -> V_14 . V_97 = NULL ;
}
F_46 ( V_2 ) ;
}
static void F_48 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
if ( ! V_2 -> V_95 )
V_2 -> V_16 -> V_56 = NULL ;
else
F_39 ( & V_2 -> V_98 ) ;
F_6 ( & V_16 -> V_69 ) ;
F_39 ( & V_2 -> V_70 ) ;
F_8 ( & V_16 -> V_69 ) ;
F_9 ( V_2 ) ;
}
static void F_49 ( struct V_86 * V_87 )
{
struct V_1 * V_2 , * V_88 ;
struct V_89 * V_90 = F_33 ( V_87 ) ;
struct V_15 * V_16 = V_90 -> V_16 ;
F_34 ( V_99 , & V_16 -> V_62 . V_92 ) ;
F_36 (dev, n, &port->destroy_list, disco_list_node) {
F_39 ( & V_2 -> V_67 ) ;
F_50 ( & V_2 -> V_20 -> V_2 ) ;
F_51 ( V_2 -> V_20 ) ;
F_48 ( V_16 , V_2 ) ;
}
}
void F_52 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
if ( ! F_53 ( V_100 , & V_2 -> V_101 ) &&
! F_7 ( & V_2 -> V_67 ) ) {
F_39 ( & V_2 -> V_67 ) ;
F_54 ( V_2 -> V_20 ) ;
F_48 ( V_16 , V_2 ) ;
return;
}
if ( ! F_55 ( V_100 , & V_2 -> V_101 ) ) {
F_56 ( V_2 -> V_20 ) ;
F_57 ( & V_2 -> V_67 , & V_16 -> V_102 ) ;
F_41 ( V_2 -> V_16 , V_99 ) ;
}
}
void F_58 ( struct V_15 * V_16 , int V_103 )
{
struct V_1 * V_2 , * V_88 ;
F_59 (dev, n, &port->dev_list, dev_list_node) {
if ( V_103 )
F_60 ( V_104 , & V_2 -> V_101 ) ;
F_52 ( V_16 , V_2 ) ;
}
F_36 (dev, n, &port->disco_list, disco_list_node)
F_52 ( V_16 , V_2 ) ;
V_16 -> V_16 -> V_20 = NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_105 * V_16 )
{
struct V_73 * V_75 ;
struct V_106 * V_107 ;
if ( ! V_2 )
return;
V_75 = V_2 -> V_16 -> V_75 ;
V_107 = F_61 ( V_16 ) ;
F_6 ( & V_75 -> V_108 ) ;
if ( V_107 ) {
F_45 ( V_2 -> V_18 ) ;
V_2 -> V_18 = V_107 ;
}
F_8 ( & V_75 -> V_108 ) ;
}
static void F_62 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
int error = 0 ;
struct V_89 * V_90 = F_33 ( V_87 ) ;
struct V_15 * V_16 = V_90 -> V_16 ;
F_34 ( V_109 , & V_16 -> V_62 . V_92 ) ;
if ( V_16 -> V_56 )
return;
error = F_4 ( V_16 ) ;
if ( error )
return;
V_2 = V_16 -> V_56 ;
F_63 ( L_4 , V_16 -> V_44 ,
F_64 ( V_110 ) ) ;
switch ( V_2 -> V_3 ) {
case V_4 :
error = F_40 ( V_2 ) ;
break;
case V_5 :
case V_6 :
error = F_65 ( V_2 ) ;
break;
case V_10 :
case V_11 :
#ifdef F_66
error = F_67 ( V_2 ) ;
break;
#else
F_63 ( L_5 ) ;
#endif
default:
error = - V_111 ;
F_63 ( L_6 , V_2 -> V_3 ) ;
break;
}
if ( error ) {
F_54 ( V_2 -> V_20 ) ;
F_39 ( & V_2 -> V_67 ) ;
F_6 ( & V_16 -> V_69 ) ;
F_39 ( & V_2 -> V_70 ) ;
F_8 ( & V_16 -> V_69 ) ;
F_9 ( V_2 ) ;
V_16 -> V_56 = NULL ;
}
F_63 ( L_7 , V_16 -> V_44 ,
F_64 ( V_110 ) , error ) ;
}
static void F_68 ( struct V_86 * V_87 )
{
int V_72 = 0 ;
struct V_89 * V_90 = F_33 ( V_87 ) ;
struct V_15 * V_16 = V_90 -> V_16 ;
struct V_73 * V_75 = V_16 -> V_75 ;
F_69 ( & V_75 -> V_112 ) ;
if ( F_53 ( V_113 , & V_75 -> V_101 ) ) {
F_63 ( L_8 ,
V_16 -> V_44 , F_64 ( V_110 ) ) ;
goto V_114;
}
F_34 ( V_115 , & V_16 -> V_62 . V_92 ) ;
F_63 ( L_9 , V_16 -> V_44 ,
F_64 ( V_110 ) ) ;
if ( V_16 -> V_56 )
V_72 = F_70 ( V_16 -> V_56 ) ;
F_63 ( L_10 ,
V_16 -> V_44 , F_64 ( V_110 ) , V_72 ) ;
V_114:
F_71 ( & V_75 -> V_112 ) ;
}
static void F_72 ( struct V_73 * V_75 , struct V_116 * V_117 )
{
F_73 ( V_75 -> V_78 . V_77 , & V_117 -> V_87 ) ;
}
static void F_74 ( int V_118 , unsigned long * V_92 ,
struct V_116 * V_117 ,
struct V_73 * V_75 )
{
if ( ! F_55 ( V_118 , V_92 ) ) {
unsigned long V_119 ;
F_75 ( & V_75 -> V_120 , V_119 ) ;
F_72 ( V_75 , V_117 ) ;
F_76 ( & V_75 -> V_120 , V_119 ) ;
}
}
int F_41 ( struct V_15 * V_16 , enum V_121 V_90 )
{
struct V_122 * V_62 ;
if ( ! V_16 )
return 0 ;
V_62 = & V_16 -> V_62 ;
F_77 ( V_90 >= V_123 ) ;
F_74 ( V_90 , & V_62 -> V_92 , & V_62 -> V_124 [ V_90 ] . V_87 , V_16 -> V_75 ) ;
return 0 ;
}
void F_78 ( struct V_122 * V_62 , struct V_15 * V_16 )
{
int V_80 ;
static const T_1 V_125 [ V_123 ] = {
[ V_109 ] = F_62 ,
[ V_115 ] = F_68 ,
[ V_91 ] = F_32 ,
[ V_99 ] = F_49 ,
} ;
V_62 -> V_92 = 0 ;
for ( V_80 = 0 ; V_80 < V_123 ; V_80 ++ ) {
F_79 ( & V_62 -> V_124 [ V_80 ] . V_87 , V_125 [ V_80 ] ) ;
V_62 -> V_124 [ V_80 ] . V_16 = V_16 ;
}
}
