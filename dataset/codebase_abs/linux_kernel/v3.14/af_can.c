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
F_24 ( V_38 ) ;
F_25 ( V_38 ) ;
if ( V_39 ) {
V_38 -> V_60 = V_61 ;
if ( ! ( V_38 -> V_52 -> V_57 & V_62 ) ) {
V_40 = F_26 ( V_38 , V_63 ) ;
if ( ! V_40 ) {
F_27 ( V_38 ) ;
return - V_33 ;
}
F_28 ( V_40 , V_38 -> V_5 ) ;
V_40 -> V_64 = V_65 ;
V_40 -> V_60 = V_66 ;
}
} else {
V_38 -> V_60 = V_67 ;
}
V_19 = F_29 ( V_38 ) ;
if ( V_19 > 0 )
V_19 = F_30 ( V_19 ) ;
if ( V_19 ) {
F_27 ( V_40 ) ;
return V_19 ;
}
if ( V_40 )
F_31 ( V_40 ) ;
V_68 . V_69 ++ ;
V_68 . V_70 ++ ;
return 0 ;
V_48:
F_27 ( V_38 ) ;
return V_19 ;
}
static struct V_71 * F_32 ( struct V_72 * V_52 )
{
if ( ! V_52 )
return & V_73 ;
else
return (struct V_71 * ) V_52 -> V_74 ;
}
static struct V_75 * F_33 ( T_1 * V_76 , T_1 * V_77 ,
struct V_71 * V_78 )
{
T_1 V_79 = * V_76 & V_80 ;
if ( * V_77 & V_81 ) {
* V_77 &= V_82 ;
return & V_78 -> V_83 [ V_84 ] ;
}
#define F_34 (CAN_EFF_FLAG | CAN_RTR_FLAG)
if ( ( * V_77 & V_85 ) && ! ( * V_76 & V_85 ) )
* V_77 &= ( V_86 | F_34 ) ;
* V_76 &= * V_77 ;
if ( V_79 )
return & V_78 -> V_83 [ V_87 ] ;
if ( ! ( * V_77 ) )
return & V_78 -> V_83 [ V_88 ] ;
if ( ( ( * V_77 & F_34 ) == F_34 ) &&
! ( * V_76 & V_89 ) ) {
if ( * V_76 & V_85 ) {
if ( * V_77 == ( V_90 | F_34 ) ) {
return & V_78 -> V_83 [ V_91 ] ;
}
} else {
if ( * V_77 == ( V_86 | F_34 ) )
return & V_78 -> V_92 [ * V_76 ] ;
}
}
return & V_78 -> V_83 [ V_93 ] ;
}
int F_35 ( struct V_72 * V_52 , T_1 V_76 , T_1 V_77 ,
void (* F_36)( struct V_37 * , void * ) , void * V_43 ,
char * V_94 )
{
struct V_95 * V_96 ;
struct V_75 * V_97 ;
struct V_71 * V_78 ;
int V_19 = 0 ;
if ( V_52 && V_52 -> type != V_55 )
return - V_98 ;
V_96 = F_37 ( V_99 , V_32 ) ;
if ( ! V_96 )
return - V_33 ;
F_38 ( & V_100 ) ;
V_78 = F_32 ( V_52 ) ;
if ( V_78 ) {
V_97 = F_33 ( & V_76 , & V_77 , V_78 ) ;
V_96 -> V_76 = V_76 ;
V_96 -> V_77 = V_77 ;
V_96 -> V_101 = 0 ;
V_96 -> F_36 = F_36 ;
V_96 -> V_43 = V_43 ;
V_96 -> V_94 = V_94 ;
F_39 ( & V_96 -> V_102 , V_97 ) ;
V_78 -> V_103 ++ ;
V_104 . V_105 ++ ;
if ( V_104 . V_106 < V_104 . V_105 )
V_104 . V_106 = V_104 . V_105 ;
} else {
F_40 ( V_99 , V_96 ) ;
V_19 = - V_98 ;
}
F_41 ( & V_100 ) ;
return V_19 ;
}
static void F_42 ( struct V_107 * V_108 )
{
struct V_95 * V_96 = F_43 ( V_108 , struct V_95 , V_109 ) ;
F_40 ( V_99 , V_96 ) ;
}
void F_44 ( struct V_72 * V_52 , T_1 V_76 , T_1 V_77 ,
void (* F_36)( struct V_37 * , void * ) , void * V_43 )
{
struct V_95 * V_96 = NULL ;
struct V_75 * V_97 ;
struct V_71 * V_78 ;
if ( V_52 && V_52 -> type != V_55 )
return;
F_38 ( & V_100 ) ;
V_78 = F_32 ( V_52 ) ;
if ( ! V_78 ) {
F_45 ( L_4
L_5 ,
F_46 ( V_52 ) , V_76 , V_77 ) ;
goto V_110;
}
V_97 = F_33 ( & V_76 , & V_77 , V_78 ) ;
F_47 (r, rl, list) {
if ( V_96 -> V_76 == V_76 && V_96 -> V_77 == V_77 &&
V_96 -> F_36 == F_36 && V_96 -> V_43 == V_43 )
break;
}
if ( ! V_96 ) {
F_48 ( 1 , L_6
L_7 , F_46 ( V_52 ) , V_76 , V_77 ) ;
goto V_110;
}
F_49 ( & V_96 -> V_102 ) ;
V_78 -> V_103 -- ;
if ( V_104 . V_105 > 0 )
V_104 . V_105 -- ;
if ( V_78 -> V_111 && ! V_78 -> V_103 ) {
F_50 ( V_78 ) ;
V_52 -> V_74 = NULL ;
}
V_110:
F_41 ( & V_100 ) ;
if ( V_96 )
F_51 ( & V_96 -> V_109 , F_42 ) ;
}
static inline void F_52 ( struct V_37 * V_38 , struct V_95 * V_96 )
{
V_96 -> F_36 ( V_38 , V_96 -> V_43 ) ;
V_96 -> V_101 ++ ;
}
static int F_53 ( struct V_71 * V_78 , struct V_37 * V_38 )
{
struct V_95 * V_96 ;
int V_101 = 0 ;
struct V_112 * V_113 = (struct V_112 * ) V_38 -> V_43 ;
T_1 V_76 = V_113 -> V_76 ;
if ( V_78 -> V_103 == 0 )
return 0 ;
if ( V_76 & V_81 ) {
F_47 (r, &d->rx[RX_ERR], list) {
if ( V_76 & V_96 -> V_77 ) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
}
return V_101 ;
}
F_47 (r, &d->rx[RX_ALL], list) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
F_47 (r, &d->rx[RX_FIL], list) {
if ( ( V_76 & V_96 -> V_77 ) == V_96 -> V_76 ) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
}
F_47 (r, &d->rx[RX_INV], list) {
if ( ( V_76 & V_96 -> V_77 ) != V_96 -> V_76 ) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
}
if ( V_76 & V_89 )
return V_101 ;
if ( V_76 & V_85 ) {
F_47 (r, &d->rx[RX_EFF], list) {
if ( V_96 -> V_76 == V_76 ) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
}
} else {
V_76 &= V_86 ;
F_47 (r, &d->rx_sff[can_id], list) {
F_52 ( V_38 , V_96 ) ;
V_101 ++ ;
}
}
return V_101 ;
}
static void F_54 ( struct V_37 * V_38 , struct V_72 * V_52 )
{
struct V_71 * V_78 ;
int V_101 ;
V_68 . V_114 ++ ;
V_68 . V_115 ++ ;
F_6 () ;
V_101 = F_53 ( & V_73 , V_38 ) ;
V_78 = F_32 ( V_52 ) ;
if ( V_78 )
V_101 += F_53 ( V_78 , V_38 ) ;
F_9 () ;
F_55 ( V_38 ) ;
if ( V_101 > 0 ) {
V_68 . V_101 ++ ;
V_68 . V_116 ++ ;
}
}
static int F_56 ( struct V_37 * V_38 , struct V_72 * V_52 ,
struct V_117 * V_118 , struct V_72 * V_119 )
{
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
if ( F_23 ( ! F_13 ( F_57 ( V_52 ) , & V_24 ) ) )
goto V_120;
if ( F_58 ( V_52 -> type != V_55 ||
V_38 -> V_44 != V_45 ||
V_42 -> V_44 > V_47 ,
L_8
L_9 ,
V_52 -> type , V_38 -> V_44 , V_42 -> V_44 ) )
goto V_120;
F_54 ( V_38 , V_52 ) ;
return V_121 ;
V_120:
F_27 ( V_38 ) ;
return V_122 ;
}
static int F_59 ( struct V_37 * V_38 , struct V_72 * V_52 ,
struct V_117 * V_118 , struct V_72 * V_119 )
{
struct V_41 * V_42 = (struct V_41 * ) V_38 -> V_43 ;
if ( F_23 ( ! F_13 ( F_57 ( V_52 ) , & V_24 ) ) )
goto V_120;
if ( F_58 ( V_52 -> type != V_55 ||
V_38 -> V_44 != V_49 ||
V_42 -> V_44 > V_51 ,
L_10
L_9 ,
V_52 -> type , V_38 -> V_44 , V_42 -> V_44 ) )
goto V_120;
F_54 ( V_38 , V_52 ) ;
return V_121 ;
V_120:
F_27 ( V_38 ) ;
return V_122 ;
}
int F_60 ( const struct V_11 * V_13 )
{
int V_123 = V_13 -> V_12 ;
int V_19 = 0 ;
if ( V_123 < 0 || V_123 >= V_22 ) {
F_45 ( L_11 , V_123 ) ;
return - V_23 ;
}
V_19 = F_61 ( V_13 -> V_15 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
F_62 ( & V_124 ) ;
if ( V_14 [ V_123 ] ) {
F_45 ( L_12 , V_123 ) ;
V_19 = - V_125 ;
} else
F_63 ( V_14 [ V_123 ] , V_13 ) ;
F_64 ( & V_124 ) ;
if ( V_19 < 0 )
F_65 ( V_13 -> V_15 ) ;
return V_19 ;
}
void F_66 ( const struct V_11 * V_13 )
{
int V_123 = V_13 -> V_12 ;
F_62 ( & V_124 ) ;
F_67 ( V_14 [ V_123 ] != V_13 ) ;
F_63 ( V_14 [ V_123 ] , NULL ) ;
F_64 ( & V_124 ) ;
F_68 () ;
F_65 ( V_13 -> V_15 ) ;
}
static int F_69 ( struct V_126 * V_127 , unsigned long V_128 ,
void * V_129 )
{
struct V_72 * V_52 = F_70 ( V_129 ) ;
struct V_71 * V_78 ;
if ( ! F_13 ( F_57 ( V_52 ) , & V_24 ) )
return V_130 ;
if ( V_52 -> type != V_55 )
return V_130 ;
switch ( V_128 ) {
case V_131 :
V_78 = F_71 ( sizeof( * V_78 ) , V_32 ) ;
if ( ! V_78 )
return V_130 ;
F_67 ( V_52 -> V_74 ) ;
V_52 -> V_74 = V_78 ;
break;
case V_132 :
F_38 ( & V_100 ) ;
V_78 = V_52 -> V_74 ;
if ( V_78 ) {
if ( V_78 -> V_103 )
V_78 -> V_111 = 1 ;
else {
F_50 ( V_78 ) ;
V_52 -> V_74 = NULL ;
}
} else
F_45 ( L_13
L_14 , V_52 -> V_133 ) ;
F_41 ( & V_100 ) ;
break;
}
return V_130 ;
}
static T_2 int F_72 ( void )
{
F_73 ( F_74 ( struct V_112 , V_134 ) !=
F_74 ( struct V_41 , V_44 ) ||
F_74 ( struct V_112 , V_43 ) !=
F_74 ( struct V_41 , V_43 ) ) ;
F_75 ( V_135 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_99 = F_76 ( L_15 , sizeof( struct V_95 ) ,
0 , 0 , NULL ) ;
if ( ! V_99 )
return - V_33 ;
if ( V_136 ) {
F_77 ( & V_137 , V_138 , 0 ) ;
F_78 ( & V_137 , F_79 ( V_139 + V_140 ) ) ;
} else
V_137 . V_141 = NULL ;
F_80 () ;
F_81 ( & V_142 ) ;
F_82 ( & V_143 ) ;
F_83 ( & V_144 ) ;
F_83 ( & V_145 ) ;
return 0 ;
}
static T_3 void F_84 ( void )
{
struct V_72 * V_52 ;
if ( V_136 )
F_85 ( & V_137 ) ;
F_86 () ;
F_87 ( & V_145 ) ;
F_87 ( & V_144 ) ;
F_88 ( & V_143 ) ;
F_89 ( V_31 ) ;
F_6 () ;
F_90 (&init_net, dev) {
if ( V_52 -> type == V_55 && V_52 -> V_74 ) {
struct V_71 * V_78 = V_52 -> V_74 ;
F_67 ( V_78 -> V_103 ) ;
F_50 ( V_78 ) ;
V_52 -> V_74 = NULL ;
}
}
F_9 () ;
F_91 () ;
F_92 ( V_99 ) ;
}
