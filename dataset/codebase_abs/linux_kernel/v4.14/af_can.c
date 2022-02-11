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
V_13 = F_5 ( V_12 ) ;
#ifdef F_13
if ( ! V_13 ) {
V_19 = F_14 ( L_1 , V_12 ) ;
if ( V_19 )
F_15 ( V_24 L_2
L_3 , V_12 ) ;
V_13 = F_5 ( V_12 ) ;
}
#endif
if ( ! V_13 )
return - V_25 ;
if ( V_13 -> type != V_2 -> type ) {
V_19 = - V_26 ;
goto V_27;
}
V_2 -> V_28 = V_13 -> V_28 ;
V_5 = F_16 ( V_17 , V_29 , V_30 , V_13 -> V_15 , V_18 ) ;
if ( ! V_5 ) {
V_19 = - V_31 ;
goto V_27;
}
F_17 ( V_2 , V_5 ) ;
V_5 -> V_32 = F_3 ;
if ( V_5 -> V_33 -> V_34 )
V_19 = V_5 -> V_33 -> V_34 ( V_5 ) ;
if ( V_19 ) {
F_18 ( V_5 ) ;
F_19 ( V_5 ) ;
}
V_27:
F_10 ( V_13 ) ;
return V_19 ;
}
int F_20 ( struct V_35 * V_36 , int V_37 )
{
struct V_35 * V_38 = NULL ;
struct V_39 * V_40 = (struct V_39 * ) V_36 -> V_41 ;
struct V_42 * V_43 = F_21 ( V_36 -> V_44 ) -> V_45 . V_43 ;
int V_19 = - V_23 ;
if ( V_36 -> V_46 == V_47 ) {
V_36 -> V_12 = F_22 ( V_48 ) ;
if ( F_23 ( V_40 -> V_46 > V_49 ) )
goto V_50;
} else if ( V_36 -> V_46 == V_51 ) {
V_36 -> V_12 = F_22 ( V_52 ) ;
if ( F_23 ( V_40 -> V_46 > V_53 ) )
goto V_50;
} else
goto V_50;
if ( F_23 ( V_36 -> V_46 > V_36 -> V_44 -> V_54 && V_40 -> V_46 > V_49 ) ) {
V_19 = - V_55 ;
goto V_50;
}
if ( F_23 ( V_36 -> V_44 -> type != V_56 ) ) {
V_19 = - V_57 ;
goto V_50;
}
if ( F_23 ( ! ( V_36 -> V_44 -> V_58 & V_59 ) ) ) {
V_19 = - V_60 ;
goto V_50;
}
V_36 -> V_61 = V_62 ;
F_24 ( V_36 ) ;
F_25 ( V_36 ) ;
F_26 ( V_36 ) ;
if ( V_37 ) {
V_36 -> V_63 = V_64 ;
if ( ! ( V_36 -> V_44 -> V_58 & V_65 ) ) {
V_38 = F_27 ( V_36 , V_66 ) ;
if ( ! V_38 ) {
F_28 ( V_36 ) ;
return - V_31 ;
}
F_29 ( V_38 , V_36 -> V_5 ) ;
V_38 -> V_61 = V_62 ;
V_38 -> V_63 = V_67 ;
}
} else {
V_36 -> V_63 = V_68 ;
}
V_19 = F_30 ( V_36 ) ;
if ( V_19 > 0 )
V_19 = F_31 ( V_19 ) ;
if ( V_19 ) {
F_28 ( V_38 ) ;
return V_19 ;
}
if ( V_38 )
F_32 ( V_38 ) ;
V_43 -> V_69 ++ ;
V_43 -> V_70 ++ ;
return 0 ;
V_50:
F_28 ( V_36 ) ;
return V_19 ;
}
static struct V_71 * F_33 ( struct V_17 * V_17 ,
struct V_72 * V_44 )
{
if ( ! V_44 )
return V_17 -> V_45 . V_73 ;
else
return (struct V_71 * ) V_44 -> V_74 ;
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
int F_37 ( struct V_17 * V_17 , struct V_72 * V_44 , T_1 V_75 ,
T_1 V_79 , void (* F_38)( struct V_35 * , void * ) ,
void * V_41 , char * V_96 , struct V_2 * V_5 )
{
struct V_97 * V_98 ;
struct V_78 * V_99 ;
struct V_71 * V_80 ;
struct V_100 * V_101 = V_17 -> V_45 . V_101 ;
int V_19 = 0 ;
if ( V_44 && V_44 -> type != V_56 )
return - V_102 ;
if ( V_44 && ! F_39 ( V_17 , F_21 ( V_44 ) ) )
return - V_102 ;
V_98 = F_40 ( V_103 , V_30 ) ;
if ( ! V_98 )
return - V_31 ;
F_41 ( & V_17 -> V_45 . V_104 ) ;
V_80 = F_33 ( V_17 , V_44 ) ;
if ( V_80 ) {
V_99 = F_35 ( & V_75 , & V_79 , V_80 ) ;
V_98 -> V_75 = V_75 ;
V_98 -> V_79 = V_79 ;
V_98 -> V_105 = 0 ;
V_98 -> F_38 = F_38 ;
V_98 -> V_41 = V_41 ;
V_98 -> V_96 = V_96 ;
V_98 -> V_5 = V_5 ;
F_42 ( & V_98 -> V_106 , V_99 ) ;
V_80 -> V_107 ++ ;
V_101 -> V_108 ++ ;
if ( V_101 -> V_109 < V_101 -> V_108 )
V_101 -> V_109 = V_101 -> V_108 ;
} else {
F_43 ( V_103 , V_98 ) ;
V_19 = - V_102 ;
}
F_44 ( & V_17 -> V_45 . V_104 ) ;
return V_19 ;
}
static void F_45 ( struct V_110 * V_111 )
{
struct V_97 * V_98 = F_46 ( V_111 , struct V_97 , V_112 ) ;
struct V_2 * V_5 = V_98 -> V_5 ;
F_43 ( V_103 , V_98 ) ;
if ( V_5 )
F_19 ( V_5 ) ;
}
void F_47 ( struct V_17 * V_17 , struct V_72 * V_44 , T_1 V_75 ,
T_1 V_79 , void (* F_38)( struct V_35 * , void * ) ,
void * V_41 )
{
struct V_97 * V_98 = NULL ;
struct V_78 * V_99 ;
struct V_100 * V_101 = V_17 -> V_45 . V_101 ;
struct V_71 * V_80 ;
if ( V_44 && V_44 -> type != V_56 )
return;
if ( V_44 && ! F_39 ( V_17 , F_21 ( V_44 ) ) )
return;
F_41 ( & V_17 -> V_45 . V_104 ) ;
V_80 = F_33 ( V_17 , V_44 ) ;
if ( ! V_80 ) {
F_48 ( L_4
L_5 ,
F_49 ( V_44 ) , V_75 , V_79 ) ;
goto V_113;
}
V_99 = F_35 ( & V_75 , & V_79 , V_80 ) ;
F_50 (r, rl, list) {
if ( V_98 -> V_75 == V_75 && V_98 -> V_79 == V_79 &&
V_98 -> F_38 == F_38 && V_98 -> V_41 == V_41 )
break;
}
if ( ! V_98 ) {
F_51 ( 1 , L_6
L_7 , F_49 ( V_44 ) , V_75 , V_79 ) ;
goto V_113;
}
F_52 ( & V_98 -> V_106 ) ;
V_80 -> V_107 -- ;
if ( V_101 -> V_108 > 0 )
V_101 -> V_108 -- ;
if ( V_80 -> V_114 && ! V_80 -> V_107 ) {
F_53 ( V_80 ) ;
V_44 -> V_74 = NULL ;
}
V_113:
F_44 ( & V_17 -> V_45 . V_104 ) ;
if ( V_98 ) {
if ( V_98 -> V_5 )
F_54 ( V_98 -> V_5 ) ;
F_55 ( & V_98 -> V_112 , F_45 ) ;
}
}
static inline void F_56 ( struct V_35 * V_36 , struct V_97 * V_98 )
{
V_98 -> F_38 ( V_36 , V_98 -> V_41 ) ;
V_98 -> V_105 ++ ;
}
static int F_57 ( struct V_71 * V_80 , struct V_35 * V_36 )
{
struct V_97 * V_98 ;
int V_105 = 0 ;
struct V_115 * V_116 = (struct V_115 * ) V_36 -> V_41 ;
T_1 V_75 = V_116 -> V_75 ;
if ( V_80 -> V_107 == 0 )
return 0 ;
if ( V_75 & V_83 ) {
F_50 (r, &d->rx[RX_ERR], list) {
if ( V_75 & V_98 -> V_79 ) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
}
return V_105 ;
}
F_50 (r, &d->rx[RX_ALL], list) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
F_50 (r, &d->rx[RX_FIL], list) {
if ( ( V_75 & V_98 -> V_79 ) == V_98 -> V_75 ) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
}
F_50 (r, &d->rx[RX_INV], list) {
if ( ( V_75 & V_98 -> V_79 ) != V_98 -> V_75 ) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
}
if ( V_75 & V_91 )
return V_105 ;
if ( V_75 & V_87 ) {
F_50 (r, &d->rx_eff[effhash(can_id)], list) {
if ( V_98 -> V_75 == V_75 ) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
}
} else {
V_75 &= V_88 ;
F_50 (r, &d->rx_sff[can_id], list) {
F_56 ( V_36 , V_98 ) ;
V_105 ++ ;
}
}
return V_105 ;
}
static void F_58 ( struct V_35 * V_36 , struct V_72 * V_44 )
{
struct V_71 * V_80 ;
struct V_17 * V_17 = F_21 ( V_44 ) ;
struct V_42 * V_43 = V_17 -> V_45 . V_43 ;
int V_105 ;
V_43 -> V_117 ++ ;
V_43 -> V_118 ++ ;
while ( ! ( F_59 ( V_36 ) -> V_119 ) )
F_59 ( V_36 ) -> V_119 = F_60 ( & V_120 ) ;
F_6 () ;
V_105 = F_57 ( V_17 -> V_45 . V_73 , V_36 ) ;
V_80 = F_33 ( V_17 , V_44 ) ;
if ( V_80 )
V_105 += F_57 ( V_80 , V_36 ) ;
F_9 () ;
F_61 ( V_36 ) ;
if ( V_105 > 0 ) {
V_43 -> V_105 ++ ;
V_43 -> V_121 ++ ;
}
}
static int F_62 ( struct V_35 * V_36 , struct V_72 * V_44 ,
struct V_122 * V_123 , struct V_72 * V_124 )
{
struct V_39 * V_40 = (struct V_39 * ) V_36 -> V_41 ;
if ( F_63 ( V_44 -> type != V_56 ||
V_36 -> V_46 != V_47 ||
V_40 -> V_46 > V_49 ,
L_8
L_9 ,
V_44 -> type , V_36 -> V_46 , V_40 -> V_46 ) )
goto V_125;
F_58 ( V_36 , V_44 ) ;
return V_126 ;
V_125:
F_28 ( V_36 ) ;
return V_127 ;
}
static int F_64 ( struct V_35 * V_36 , struct V_72 * V_44 ,
struct V_122 * V_123 , struct V_72 * V_124 )
{
struct V_39 * V_40 = (struct V_39 * ) V_36 -> V_41 ;
if ( F_63 ( V_44 -> type != V_56 ||
V_36 -> V_46 != V_51 ||
V_40 -> V_46 > V_53 ,
L_10
L_9 ,
V_44 -> type , V_36 -> V_46 , V_40 -> V_46 ) )
goto V_125;
F_58 ( V_36 , V_44 ) ;
return V_126 ;
V_125:
F_28 ( V_36 ) ;
return V_127 ;
}
int F_65 ( const struct V_11 * V_13 )
{
int V_128 = V_13 -> V_12 ;
int V_19 = 0 ;
if ( V_128 < 0 || V_128 >= V_22 ) {
F_48 ( L_11 , V_128 ) ;
return - V_23 ;
}
V_19 = F_66 ( V_13 -> V_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
F_67 ( & V_129 ) ;
if ( F_68 ( V_14 [ V_128 ] ) ) {
F_48 ( L_12 , V_128 ) ;
V_19 = - V_130 ;
} else
F_69 ( V_14 [ V_128 ] , V_13 ) ;
F_70 ( & V_129 ) ;
if ( V_19 < 0 )
F_71 ( V_13 -> V_15 ) ;
return V_19 ;
}
void F_72 ( const struct V_11 * V_13 )
{
int V_128 = V_13 -> V_12 ;
F_67 ( & V_129 ) ;
F_73 ( F_68 ( V_14 [ V_128 ] ) != V_13 ) ;
F_69 ( V_14 [ V_128 ] , NULL ) ;
F_70 ( & V_129 ) ;
F_74 () ;
F_71 ( V_13 -> V_15 ) ;
}
static int F_75 ( struct V_131 * V_132 , unsigned long V_133 ,
void * V_134 )
{
struct V_72 * V_44 = F_76 ( V_134 ) ;
struct V_71 * V_80 ;
if ( V_44 -> type != V_56 )
return V_135 ;
switch ( V_133 ) {
case V_136 :
V_80 = F_77 ( sizeof( * V_80 ) , V_30 ) ;
if ( ! V_80 )
return V_135 ;
F_73 ( V_44 -> V_74 ) ;
V_44 -> V_74 = V_80 ;
break;
case V_137 :
F_41 ( & F_21 ( V_44 ) -> V_45 . V_104 ) ;
V_80 = V_44 -> V_74 ;
if ( V_80 ) {
if ( V_80 -> V_107 )
V_80 -> V_114 = 1 ;
else {
F_53 ( V_80 ) ;
V_44 -> V_74 = NULL ;
}
} else
F_48 ( L_13
L_14 , V_44 -> V_138 ) ;
F_44 ( & F_21 ( V_44 ) -> V_45 . V_104 ) ;
break;
}
return V_135 ;
}
static int F_78 ( struct V_17 * V_17 )
{
F_79 ( & V_17 -> V_45 . V_104 ) ;
V_17 -> V_45 . V_73 =
F_77 ( sizeof( struct V_71 ) , V_30 ) ;
if ( ! V_17 -> V_45 . V_73 )
goto V_113;
V_17 -> V_45 . V_43 = F_77 ( sizeof( struct V_42 ) , V_30 ) ;
if ( ! V_17 -> V_45 . V_43 )
goto V_139;
V_17 -> V_45 . V_101 = F_77 ( sizeof( struct V_100 ) , V_30 ) ;
if ( ! V_17 -> V_45 . V_101 )
goto V_140;
if ( F_80 ( V_141 ) ) {
if ( V_142 ) {
F_81 ( & V_17 -> V_45 . V_143 , V_144 ,
( unsigned long ) V_17 ) ;
F_82 ( & V_17 -> V_45 . V_143 ,
F_83 ( V_145 + V_146 ) ) ;
}
V_17 -> V_45 . V_43 -> V_147 = V_145 ;
F_84 ( V_17 ) ;
}
return 0 ;
V_140:
F_53 ( V_17 -> V_45 . V_43 ) ;
V_139:
F_53 ( V_17 -> V_45 . V_73 ) ;
V_113:
return - V_31 ;
}
static void F_85 ( struct V_17 * V_17 )
{
struct V_72 * V_44 ;
if ( F_80 ( V_141 ) ) {
F_86 ( V_17 ) ;
if ( V_142 )
F_87 ( & V_17 -> V_45 . V_143 ) ;
}
F_6 () ;
F_88 (net, dev) {
if ( V_44 -> type == V_56 && V_44 -> V_74 ) {
struct V_71 * V_80 = V_44 -> V_74 ;
F_73 ( V_80 -> V_107 ) ;
F_53 ( V_80 ) ;
V_44 -> V_74 = NULL ;
}
}
F_9 () ;
F_53 ( V_17 -> V_45 . V_73 ) ;
F_53 ( V_17 -> V_45 . V_43 ) ;
F_53 ( V_17 -> V_45 . V_101 ) ;
}
static T_2 int F_89 ( void )
{
F_90 ( F_91 ( struct V_115 , V_148 ) !=
F_91 ( struct V_39 , V_46 ) ||
F_91 ( struct V_115 , V_41 ) !=
F_91 ( struct V_39 , V_41 ) ) ;
F_92 ( L_15 V_149 L_16 ) ;
V_103 = F_93 ( L_17 , sizeof( struct V_97 ) ,
0 , 0 , NULL ) ;
if ( ! V_103 )
return - V_31 ;
F_94 ( & V_150 ) ;
F_95 ( & V_151 ) ;
F_96 ( & V_152 ) ;
F_97 ( & V_153 ) ;
F_97 ( & V_154 ) ;
return 0 ;
}
static T_3 void F_98 ( void )
{
F_99 ( & V_154 ) ;
F_99 ( & V_153 ) ;
F_100 ( & V_152 ) ;
F_101 ( V_29 ) ;
F_102 ( & V_150 ) ;
F_103 () ;
F_104 ( V_103 ) ;
}
