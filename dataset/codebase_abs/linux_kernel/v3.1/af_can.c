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
V_5 = F_17 ( V_17 , V_31 , V_32 , V_13 -> V_15 ) ;
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
int V_19 ;
if ( V_38 -> V_44 != sizeof( struct V_41 ) || V_42 -> V_45 > 8 ) {
F_22 ( V_38 ) ;
return - V_23 ;
}
if ( V_38 -> V_46 -> type != V_47 ) {
F_22 ( V_38 ) ;
return - V_48 ;
}
if ( ! ( V_38 -> V_46 -> V_49 & V_50 ) ) {
F_22 ( V_38 ) ;
return - V_51 ;
}
V_38 -> V_12 = F_23 ( V_52 ) ;
F_24 ( V_38 ) ;
F_25 ( V_38 ) ;
if ( V_39 ) {
V_38 -> V_53 = V_54 ;
if ( ! ( V_38 -> V_46 -> V_49 & V_55 ) ) {
V_40 = F_26 ( V_38 , V_56 ) ;
if ( ! V_40 ) {
F_22 ( V_38 ) ;
return - V_33 ;
}
V_40 -> V_5 = V_38 -> V_5 ;
V_40 -> V_57 = V_58 ;
V_40 -> V_53 = V_59 ;
}
} else {
V_38 -> V_53 = V_60 ;
}
V_19 = F_27 ( V_38 ) ;
if ( V_19 > 0 )
V_19 = F_28 ( V_19 ) ;
if ( V_19 ) {
F_22 ( V_40 ) ;
return V_19 ;
}
if ( V_40 )
F_29 ( V_40 ) ;
V_61 . V_62 ++ ;
V_61 . V_63 ++ ;
return 0 ;
}
static struct V_64 * F_30 ( struct V_65 * V_46 )
{
if ( ! V_46 )
return & V_66 ;
else
return (struct V_64 * ) V_46 -> V_67 ;
}
static struct V_68 * F_31 ( T_1 * V_69 , T_1 * V_70 ,
struct V_64 * V_71 )
{
T_1 V_72 = * V_69 & V_73 ;
if ( * V_70 & V_74 ) {
* V_70 &= V_75 ;
return & V_71 -> V_76 [ V_77 ] ;
}
#define F_32 (CAN_EFF_FLAG | CAN_RTR_FLAG)
if ( ( * V_70 & V_78 ) && ! ( * V_69 & V_78 ) )
* V_70 &= ( V_79 | F_32 ) ;
* V_69 &= * V_70 ;
if ( V_72 )
return & V_71 -> V_76 [ V_80 ] ;
if ( ! ( * V_70 ) )
return & V_71 -> V_76 [ V_81 ] ;
if ( ( ( * V_70 & F_32 ) == F_32 ) &&
! ( * V_69 & V_82 ) ) {
if ( * V_69 & V_78 ) {
if ( * V_70 == ( V_83 | F_32 ) ) {
return & V_71 -> V_76 [ V_84 ] ;
}
} else {
if ( * V_70 == ( V_79 | F_32 ) )
return & V_71 -> V_85 [ * V_69 ] ;
}
}
return & V_71 -> V_76 [ V_86 ] ;
}
int F_33 ( struct V_65 * V_46 , T_1 V_69 , T_1 V_70 ,
void (* F_34)( struct V_37 * , void * ) , void * V_43 ,
char * V_87 )
{
struct V_88 * V_89 ;
struct V_68 * V_90 ;
struct V_64 * V_71 ;
int V_19 = 0 ;
if ( V_46 && V_46 -> type != V_47 )
return - V_91 ;
V_89 = F_35 ( V_92 , V_32 ) ;
if ( ! V_89 )
return - V_33 ;
F_36 ( & V_93 ) ;
V_71 = F_30 ( V_46 ) ;
if ( V_71 ) {
V_90 = F_31 ( & V_69 , & V_70 , V_71 ) ;
V_89 -> V_69 = V_69 ;
V_89 -> V_70 = V_70 ;
V_89 -> V_94 = 0 ;
V_89 -> F_34 = F_34 ;
V_89 -> V_43 = V_43 ;
V_89 -> V_87 = V_87 ;
F_37 ( & V_89 -> V_95 , V_90 ) ;
V_71 -> V_96 ++ ;
V_97 . V_98 ++ ;
if ( V_97 . V_99 < V_97 . V_98 )
V_97 . V_99 = V_97 . V_98 ;
} else {
F_38 ( V_92 , V_89 ) ;
V_19 = - V_91 ;
}
F_39 ( & V_93 ) ;
return V_19 ;
}
static void F_40 ( struct V_100 * V_101 )
{
struct V_88 * V_89 = F_41 ( V_101 , struct V_88 , V_102 ) ;
F_38 ( V_92 , V_89 ) ;
}
void F_42 ( struct V_65 * V_46 , T_1 V_69 , T_1 V_70 ,
void (* F_34)( struct V_37 * , void * ) , void * V_43 )
{
struct V_88 * V_89 = NULL ;
struct V_68 * V_90 ;
struct V_103 * V_104 ;
struct V_64 * V_71 ;
if ( V_46 && V_46 -> type != V_47 )
return;
F_36 ( & V_93 ) ;
V_71 = F_30 ( V_46 ) ;
if ( ! V_71 ) {
F_43 ( V_26 L_4
L_5 ,
F_44 ( V_46 ) , V_69 , V_70 ) ;
goto V_105;
}
V_90 = F_31 ( & V_69 , & V_70 , V_71 ) ;
F_45 (r, next, rl, list) {
if ( V_89 -> V_69 == V_69 && V_89 -> V_70 == V_70 &&
V_89 -> F_34 == F_34 && V_89 -> V_43 == V_43 )
break;
}
if ( ! V_104 ) {
F_43 ( V_26 L_6
L_5 ,
F_44 ( V_46 ) , V_69 , V_70 ) ;
V_89 = NULL ;
goto V_105;
}
F_46 ( & V_89 -> V_95 ) ;
V_71 -> V_96 -- ;
if ( V_97 . V_98 > 0 )
V_97 . V_98 -- ;
if ( V_71 -> V_106 && ! V_71 -> V_96 ) {
F_47 ( V_71 ) ;
V_46 -> V_67 = NULL ;
}
V_105:
F_39 ( & V_93 ) ;
if ( V_89 )
F_48 ( & V_89 -> V_102 , F_40 ) ;
}
static inline void F_49 ( struct V_37 * V_38 , struct V_88 * V_89 )
{
V_89 -> F_34 ( V_38 , V_89 -> V_43 ) ;
V_89 -> V_94 ++ ;
}
static int F_50 ( struct V_64 * V_71 , struct V_37 * V_38 )
{
struct V_88 * V_89 ;
struct V_103 * V_107 ;
int V_94 = 0 ;
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
T_1 V_69 = V_42 -> V_69 ;
if ( V_71 -> V_96 == 0 )
return 0 ;
if ( V_69 & V_74 ) {
F_45 (r, n, &d->rx[RX_ERR], list) {
if ( V_69 & V_89 -> V_70 ) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
}
return V_94 ;
}
F_45 (r, n, &d->rx[RX_ALL], list) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
F_45 (r, n, &d->rx[RX_FIL], list) {
if ( ( V_69 & V_89 -> V_70 ) == V_89 -> V_69 ) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
}
F_45 (r, n, &d->rx[RX_INV], list) {
if ( ( V_69 & V_89 -> V_70 ) != V_89 -> V_69 ) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
}
if ( V_69 & V_82 )
return V_94 ;
if ( V_69 & V_78 ) {
F_45 (r, n, &d->rx[RX_EFF], list) {
if ( V_89 -> V_69 == V_69 ) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
}
} else {
V_69 &= V_79 ;
F_45 (r, n, &d->rx_sff[can_id], list) {
F_49 ( V_38 , V_89 ) ;
V_94 ++ ;
}
}
return V_94 ;
}
static int F_51 ( struct V_37 * V_38 , struct V_65 * V_46 ,
struct V_108 * V_109 , struct V_65 * V_110 )
{
struct V_64 * V_71 ;
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
int V_94 ;
if ( ! F_13 ( F_52 ( V_46 ) , & V_24 ) )
goto V_111;
if ( F_53 ( V_46 -> type != V_47 ||
V_38 -> V_44 != sizeof( struct V_41 ) ||
V_42 -> V_45 > 8 ,
L_7
L_8 ,
V_46 -> type , V_38 -> V_44 , V_42 -> V_45 ) )
goto V_111;
V_61 . V_112 ++ ;
V_61 . V_113 ++ ;
F_6 () ;
V_94 = F_50 ( & V_66 , V_38 ) ;
V_71 = F_30 ( V_46 ) ;
if ( V_71 )
V_94 += F_50 ( V_71 , V_38 ) ;
F_9 () ;
F_54 ( V_38 ) ;
if ( V_94 > 0 ) {
V_61 . V_94 ++ ;
V_61 . V_114 ++ ;
}
return V_115 ;
V_111:
F_22 ( V_38 ) ;
return V_116 ;
}
int F_55 ( const struct V_11 * V_13 )
{
int V_117 = V_13 -> V_12 ;
int V_19 = 0 ;
if ( V_117 < 0 || V_117 >= V_22 ) {
F_43 ( V_26 L_9 ,
V_117 ) ;
return - V_23 ;
}
V_19 = F_56 ( V_13 -> V_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
F_57 ( & V_118 ) ;
if ( V_14 [ V_117 ] ) {
F_43 ( V_26 L_10 ,
V_117 ) ;
V_19 = - V_119 ;
} else
F_58 ( V_14 [ V_117 ] , V_13 ) ;
F_59 ( & V_118 ) ;
if ( V_19 < 0 )
F_60 ( V_13 -> V_15 ) ;
return V_19 ;
}
void F_61 ( const struct V_11 * V_13 )
{
int V_117 = V_13 -> V_12 ;
F_57 ( & V_118 ) ;
F_62 ( V_14 [ V_117 ] != V_13 ) ;
F_58 ( V_14 [ V_117 ] , NULL ) ;
F_59 ( & V_118 ) ;
F_63 () ;
F_60 ( V_13 -> V_15 ) ;
}
static int F_64 ( struct V_120 * V_121 , unsigned long V_122 ,
void * V_43 )
{
struct V_65 * V_46 = (struct V_65 * ) V_43 ;
struct V_64 * V_71 ;
if ( ! F_13 ( F_52 ( V_46 ) , & V_24 ) )
return V_123 ;
if ( V_46 -> type != V_47 )
return V_123 ;
switch ( V_122 ) {
case V_124 :
V_71 = F_65 ( sizeof( * V_71 ) , V_32 ) ;
if ( ! V_71 ) {
F_43 ( V_26
L_11 ) ;
return V_123 ;
}
F_62 ( V_46 -> V_67 ) ;
V_46 -> V_67 = V_71 ;
break;
case V_125 :
F_36 ( & V_93 ) ;
V_71 = V_46 -> V_67 ;
if ( V_71 ) {
if ( V_71 -> V_96 )
V_71 -> V_106 = 1 ;
else {
F_47 ( V_71 ) ;
V_46 -> V_67 = NULL ;
}
} else
F_43 ( V_26 L_12
L_13 , V_46 -> V_126 ) ;
F_39 ( & V_93 ) ;
break;
}
return V_123 ;
}
static T_2 int F_66 ( void )
{
F_43 ( V_127 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_92 = F_67 ( L_14 , sizeof( struct V_88 ) ,
0 , 0 , NULL ) ;
if ( ! V_92 )
return - V_33 ;
if ( V_128 ) {
F_68 ( & V_129 , V_130 , 0 ) ;
F_69 ( & V_129 , F_70 ( V_131 + V_132 ) ) ;
} else
V_129 . V_133 = NULL ;
F_71 () ;
F_72 ( & V_134 ) ;
F_73 ( & V_135 ) ;
F_74 ( & V_136 ) ;
return 0 ;
}
static T_3 void F_75 ( void )
{
struct V_65 * V_46 ;
if ( V_128 )
F_76 ( & V_129 ) ;
F_77 () ;
F_78 ( & V_136 ) ;
F_79 ( & V_135 ) ;
F_80 ( V_31 ) ;
F_6 () ;
F_81 (&init_net, dev) {
if ( V_46 -> type == V_47 && V_46 -> V_67 ) {
struct V_64 * V_71 = V_46 -> V_67 ;
F_62 ( V_71 -> V_96 ) ;
F_47 ( V_71 ) ;
V_46 -> V_67 = NULL ;
}
}
F_9 () ;
F_82 () ;
F_83 ( V_92 ) ;
}
