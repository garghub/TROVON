int F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned long V_4 )
{
struct V_2 * V_5 = V_2 -> V_5 ;
switch ( V_3 ) {
case V_6 :
return F_2 ( V_5 , (struct V_7 V_8 * ) V_4 ) ;
default:
return - V_9 ;
}
}
static void F_3 ( struct V_2 * V_5 )
{
F_4 ( & V_5 -> V_10 ) ;
}
static const struct V_11 * F_5 ( int V_12 )
{
const struct V_11 * V_13 ;
F_6 () ;
V_13 = F_7 ( V_14 [ V_12 ] ) ;
if ( V_13 && ! F_8 ( V_13 -> V_15 -> V_16 ) )
V_13 = NULL ;
F_9 () ;
return V_13 ;
}
static inline void F_10 ( const struct V_11 * V_13 )
{
F_11 ( V_13 -> V_15 -> V_16 ) ;
}
static int F_12 ( struct V_17 * V_17 , struct V_1 * V_2 , int V_12 ,
int V_18 )
{
struct V_2 * V_5 ;
const struct V_11 * V_13 ;
int V_19 = 0 ;
V_2 -> V_20 = V_21 ;
if ( V_12 < 0 || V_12 >= V_22 )
return - V_23 ;
if ( ! F_13 ( V_17 , & V_24 ) )
return - V_25 ;
V_13 = F_5 ( V_12 ) ;
#ifdef F_14
if ( ! V_13 ) {
V_19 = F_15 ( L_1 , V_12 ) ;
if ( V_19 )
F_16 ( V_26 L_2
L_3 , V_12 ) ;
V_13 = F_5 ( V_12 ) ;
}
#endif
if ( ! V_13 )
return - V_27 ;
if ( V_13 -> type != V_2 -> type ) {
V_19 = - V_28 ;
goto V_29;
}
V_2 -> V_30 = V_13 -> V_30 ;
V_5 = F_17 ( V_17 , V_31 , V_32 , V_13 -> V_15 , V_18 ) ;
if ( ! V_5 ) {
V_19 = - V_33 ;
goto V_29;
}
F_18 ( V_2 , V_5 ) ;
V_5 -> V_34 = F_3 ;
if ( V_5 -> V_35 -> V_36 )
V_19 = V_5 -> V_35 -> V_36 ( V_5 ) ;
if ( V_19 ) {
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
}
V_29:
F_10 ( V_13 ) ;
return V_19 ;
}
int F_21 ( struct V_37 * V_38 , int V_39 )
{
struct V_37 * V_40 = NULL ;
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
int V_19 = - V_23 ;
if ( V_38 -> V_44 == V_45 ) {
V_38 -> V_12 = F_22 ( V_46 ) ;
if ( F_23 ( V_42 -> V_44 > V_47 ) )
goto V_48;
} else if ( V_38 -> V_44 == V_49 ) {
V_38 -> V_12 = F_22 ( V_50 ) ;
if ( F_23 ( V_42 -> V_44 > V_51 ) )
goto V_48;
} else
goto V_48;
if ( F_23 ( V_38 -> V_44 > V_38 -> V_52 -> V_53 && V_42 -> V_44 > V_47 ) ) {
V_19 = - V_54 ;
goto V_48;
}
if ( F_23 ( V_38 -> V_52 -> type != V_55 ) ) {
V_19 = - V_56 ;
goto V_48;
}
if ( F_23 ( ! ( V_38 -> V_52 -> V_57 & V_58 ) ) ) {
V_19 = - V_59 ;
goto V_48;
}
V_38 -> V_60 = V_61 ;
F_24 ( V_38 ) ;
F_25 ( V_38 ) ;
F_26 ( V_38 ) ;
if ( V_39 ) {
V_38 -> V_62 = V_63 ;
if ( ! ( V_38 -> V_52 -> V_57 & V_64 ) ) {
V_40 = F_27 ( V_38 , V_65 ) ;
if ( ! V_40 ) {
F_28 ( V_38 ) ;
return - V_33 ;
}
F_29 ( V_40 , V_38 -> V_5 ) ;
V_40 -> V_60 = V_61 ;
V_40 -> V_62 = V_66 ;
}
} else {
V_38 -> V_62 = V_67 ;
}
V_19 = F_30 ( V_38 ) ;
if ( V_19 > 0 )
V_19 = F_31 ( V_19 ) ;
if ( V_19 ) {
F_28 ( V_40 ) ;
return V_19 ;
}
if ( V_40 )
F_32 ( V_40 ) ;
V_68 . V_69 ++ ;
V_68 . V_70 ++ ;
return 0 ;
V_48:
F_28 ( V_38 ) ;
return V_19 ;
}
static struct V_71 * F_33 ( struct V_72 * V_52 )
{
if ( ! V_52 )
return & V_73 ;
else
return (struct V_71 * ) V_52 -> V_74 ;
}
static unsigned int F_34 ( T_1 V_75 )
{
unsigned int V_76 ;
V_76 = V_75 ;
V_76 ^= V_75 >> V_77 ;
V_76 ^= V_75 >> ( 2 * V_77 ) ;
return V_76 & ( ( 1 << V_77 ) - 1 ) ;
}
static struct V_78 * F_35 ( T_1 * V_75 , T_1 * V_79 ,
struct V_71 * V_80 )
{
T_1 V_81 = * V_75 & V_82 ;
if ( * V_79 & V_83 ) {
* V_79 &= V_84 ;
return & V_80 -> V_85 [ V_86 ] ;
}
#define F_36 (CAN_EFF_FLAG | CAN_RTR_FLAG)
if ( ( * V_79 & V_87 ) && ! ( * V_75 & V_87 ) )
* V_79 &= ( V_88 | F_36 ) ;
* V_75 &= * V_79 ;
if ( V_81 )
return & V_80 -> V_85 [ V_89 ] ;
if ( ! ( * V_79 ) )
return & V_80 -> V_85 [ V_90 ] ;
if ( ( ( * V_79 & F_36 ) == F_36 ) &&
! ( * V_75 & V_91 ) ) {
if ( * V_75 & V_87 ) {
if ( * V_79 == ( V_92 | F_36 ) )
return & V_80 -> V_93 [ F_34 ( * V_75 ) ] ;
} else {
if ( * V_79 == ( V_88 | F_36 ) )
return & V_80 -> V_94 [ * V_75 ] ;
}
}
return & V_80 -> V_85 [ V_95 ] ;
}
int F_37 ( struct V_72 * V_52 , T_1 V_75 , T_1 V_79 ,
void (* F_38)( struct V_37 * , void * ) , void * V_43 ,
char * V_96 )
{
struct V_97 * V_98 ;
struct V_78 * V_99 ;
struct V_71 * V_80 ;
int V_19 = 0 ;
if ( V_52 && V_52 -> type != V_55 )
return - V_100 ;
V_98 = F_39 ( V_101 , V_32 ) ;
if ( ! V_98 )
return - V_33 ;
F_40 ( & V_102 ) ;
V_80 = F_33 ( V_52 ) ;
if ( V_80 ) {
V_99 = F_35 ( & V_75 , & V_79 , V_80 ) ;
V_98 -> V_75 = V_75 ;
V_98 -> V_79 = V_79 ;
V_98 -> V_103 = 0 ;
V_98 -> F_38 = F_38 ;
V_98 -> V_43 = V_43 ;
V_98 -> V_96 = V_96 ;
F_41 ( & V_98 -> V_104 , V_99 ) ;
V_80 -> V_105 ++ ;
V_106 . V_107 ++ ;
if ( V_106 . V_108 < V_106 . V_107 )
V_106 . V_108 = V_106 . V_107 ;
} else {
F_42 ( V_101 , V_98 ) ;
V_19 = - V_100 ;
}
F_43 ( & V_102 ) ;
return V_19 ;
}
static void F_44 ( struct V_109 * V_110 )
{
struct V_97 * V_98 = F_45 ( V_110 , struct V_97 , V_111 ) ;
F_42 ( V_101 , V_98 ) ;
}
void F_46 ( struct V_72 * V_52 , T_1 V_75 , T_1 V_79 ,
void (* F_38)( struct V_37 * , void * ) , void * V_43 )
{
struct V_97 * V_98 = NULL ;
struct V_78 * V_99 ;
struct V_71 * V_80 ;
if ( V_52 && V_52 -> type != V_55 )
return;
F_40 ( & V_102 ) ;
V_80 = F_33 ( V_52 ) ;
if ( ! V_80 ) {
F_47 ( L_4
L_5 ,
F_48 ( V_52 ) , V_75 , V_79 ) ;
goto V_112;
}
V_99 = F_35 ( & V_75 , & V_79 , V_80 ) ;
F_49 (r, rl, list) {
if ( V_98 -> V_75 == V_75 && V_98 -> V_79 == V_79 &&
V_98 -> F_38 == F_38 && V_98 -> V_43 == V_43 )
break;
}
if ( ! V_98 ) {
F_50 ( 1 , L_6
L_7 , F_48 ( V_52 ) , V_75 , V_79 ) ;
goto V_112;
}
F_51 ( & V_98 -> V_104 ) ;
V_80 -> V_105 -- ;
if ( V_106 . V_107 > 0 )
V_106 . V_107 -- ;
if ( V_80 -> V_113 && ! V_80 -> V_105 ) {
F_52 ( V_80 ) ;
V_52 -> V_74 = NULL ;
}
V_112:
F_43 ( & V_102 ) ;
if ( V_98 )
F_53 ( & V_98 -> V_111 , F_44 ) ;
}
static inline void F_54 ( struct V_37 * V_38 , struct V_97 * V_98 )
{
V_98 -> F_38 ( V_38 , V_98 -> V_43 ) ;
V_98 -> V_103 ++ ;
}
static int F_55 ( struct V_71 * V_80 , struct V_37 * V_38 )
{
struct V_97 * V_98 ;
int V_103 = 0 ;
struct V_114 * V_115 = (struct V_114 * ) V_38 -> V_43 ;
T_1 V_75 = V_115 -> V_75 ;
if ( V_80 -> V_105 == 0 )
return 0 ;
if ( V_75 & V_83 ) {
F_49 (r, &d->rx[RX_ERR], list) {
if ( V_75 & V_98 -> V_79 ) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
}
return V_103 ;
}
F_49 (r, &d->rx[RX_ALL], list) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
F_49 (r, &d->rx[RX_FIL], list) {
if ( ( V_75 & V_98 -> V_79 ) == V_98 -> V_75 ) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
}
F_49 (r, &d->rx[RX_INV], list) {
if ( ( V_75 & V_98 -> V_79 ) != V_98 -> V_75 ) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
}
if ( V_75 & V_91 )
return V_103 ;
if ( V_75 & V_87 ) {
F_49 (r, &d->rx_eff[effhash(can_id)], list) {
if ( V_98 -> V_75 == V_75 ) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
}
} else {
V_75 &= V_88 ;
F_49 (r, &d->rx_sff[can_id], list) {
F_54 ( V_38 , V_98 ) ;
V_103 ++ ;
}
}
return V_103 ;
}
static void F_56 ( struct V_37 * V_38 , struct V_72 * V_52 )
{
struct V_71 * V_80 ;
int V_103 ;
V_68 . V_116 ++ ;
V_68 . V_117 ++ ;
while ( ! ( F_57 ( V_38 ) -> V_118 ) )
F_57 ( V_38 ) -> V_118 = F_58 ( & V_119 ) ;
F_6 () ;
V_103 = F_55 ( & V_73 , V_38 ) ;
V_80 = F_33 ( V_52 ) ;
if ( V_80 )
V_103 += F_55 ( V_80 , V_38 ) ;
F_9 () ;
F_59 ( V_38 ) ;
if ( V_103 > 0 ) {
V_68 . V_103 ++ ;
V_68 . V_120 ++ ;
}
}
static int F_60 ( struct V_37 * V_38 , struct V_72 * V_52 ,
struct V_121 * V_122 , struct V_72 * V_123 )
{
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
if ( F_23 ( ! F_13 ( F_61 ( V_52 ) , & V_24 ) ) )
goto V_124;
if ( F_62 ( V_52 -> type != V_55 ||
V_38 -> V_44 != V_45 ||
V_42 -> V_44 > V_47 ,
L_8
L_9 ,
V_52 -> type , V_38 -> V_44 , V_42 -> V_44 ) )
goto V_124;
F_56 ( V_38 , V_52 ) ;
return V_125 ;
V_124:
F_28 ( V_38 ) ;
return V_126 ;
}
static int F_63 ( struct V_37 * V_38 , struct V_72 * V_52 ,
struct V_121 * V_122 , struct V_72 * V_123 )
{
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
if ( F_23 ( ! F_13 ( F_61 ( V_52 ) , & V_24 ) ) )
goto V_124;
if ( F_62 ( V_52 -> type != V_55 ||
V_38 -> V_44 != V_49 ||
V_42 -> V_44 > V_51 ,
L_10
L_9 ,
V_52 -> type , V_38 -> V_44 , V_42 -> V_44 ) )
goto V_124;
F_56 ( V_38 , V_52 ) ;
return V_125 ;
V_124:
F_28 ( V_38 ) ;
return V_126 ;
}
int F_64 ( const struct V_11 * V_13 )
{
int V_127 = V_13 -> V_12 ;
int V_19 = 0 ;
if ( V_127 < 0 || V_127 >= V_22 ) {
F_47 ( L_11 , V_127 ) ;
return - V_23 ;
}
V_19 = F_65 ( V_13 -> V_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
F_66 ( & V_128 ) ;
if ( V_14 [ V_127 ] ) {
F_47 ( L_12 , V_127 ) ;
V_19 = - V_129 ;
} else
F_67 ( V_14 [ V_127 ] , V_13 ) ;
F_68 ( & V_128 ) ;
if ( V_19 < 0 )
F_69 ( V_13 -> V_15 ) ;
return V_19 ;
}
void F_70 ( const struct V_11 * V_13 )
{
int V_127 = V_13 -> V_12 ;
F_66 ( & V_128 ) ;
F_71 ( V_14 [ V_127 ] != V_13 ) ;
F_67 ( V_14 [ V_127 ] , NULL ) ;
F_68 ( & V_128 ) ;
F_72 () ;
F_69 ( V_13 -> V_15 ) ;
}
static int F_73 ( struct V_130 * V_131 , unsigned long V_132 ,
void * V_133 )
{
struct V_72 * V_52 = F_74 ( V_133 ) ;
struct V_71 * V_80 ;
if ( ! F_13 ( F_61 ( V_52 ) , & V_24 ) )
return V_134 ;
if ( V_52 -> type != V_55 )
return V_134 ;
switch ( V_132 ) {
case V_135 :
V_80 = F_75 ( sizeof( * V_80 ) , V_32 ) ;
if ( ! V_80 )
return V_134 ;
F_71 ( V_52 -> V_74 ) ;
V_52 -> V_74 = V_80 ;
break;
case V_136 :
F_40 ( & V_102 ) ;
V_80 = V_52 -> V_74 ;
if ( V_80 ) {
if ( V_80 -> V_105 )
V_80 -> V_113 = 1 ;
else {
F_52 ( V_80 ) ;
V_52 -> V_74 = NULL ;
}
} else
F_47 ( L_13
L_14 , V_52 -> V_137 ) ;
F_43 ( & V_102 ) ;
break;
}
return V_134 ;
}
static T_2 int F_76 ( void )
{
F_77 ( F_78 ( struct V_114 , V_138 ) !=
F_78 ( struct V_41 , V_44 ) ||
F_78 ( struct V_114 , V_43 ) !=
F_78 ( struct V_41 , V_43 ) ) ;
F_79 ( L_15 V_139 L_16 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_101 = F_80 ( L_17 , sizeof( struct V_97 ) ,
0 , 0 , NULL ) ;
if ( ! V_101 )
return - V_33 ;
if ( F_81 ( V_140 ) ) {
if ( V_141 ) {
F_82 ( & V_142 , V_143 , 0 ) ;
F_83 ( & V_142 , F_84 ( V_144 + V_145 ) ) ;
}
F_85 () ;
}
F_86 ( & V_146 ) ;
F_87 ( & V_147 ) ;
F_88 ( & V_148 ) ;
F_88 ( & V_149 ) ;
return 0 ;
}
static T_3 void F_89 ( void )
{
struct V_72 * V_52 ;
if ( F_81 ( V_140 ) ) {
if ( V_141 )
F_90 ( & V_142 ) ;
F_91 () ;
}
F_92 ( & V_149 ) ;
F_92 ( & V_148 ) ;
F_93 ( & V_147 ) ;
F_94 ( V_31 ) ;
F_6 () ;
F_95 (&init_net, dev) {
if ( V_52 -> type == V_55 && V_52 -> V_74 ) {
struct V_71 * V_80 = V_52 -> V_74 ;
F_71 ( V_80 -> V_105 ) ;
F_52 ( V_80 ) ;
V_52 -> V_74 = NULL ;
}
}
F_9 () ;
F_96 () ;
F_97 ( V_101 ) ;
}
