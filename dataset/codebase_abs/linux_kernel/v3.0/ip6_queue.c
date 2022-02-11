static inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_4 ) ;
V_5 ++ ;
}
static inline int
F_3 ( unsigned char V_6 , unsigned int V_7 )
{
int V_8 = 0 ;
switch( V_6 ) {
case V_9 :
case V_10 :
V_11 = V_6 ;
V_12 = 0 ;
break;
case V_13 :
if ( V_7 > 0xFFFF )
V_7 = 0xFFFF ;
V_12 = V_7 ;
V_11 = V_6 ;
break;
default:
V_8 = - V_14 ;
}
return V_8 ;
}
static inline void
F_4 ( void )
{
V_15 = 0 ;
F_5 () ;
F_3 ( V_9 , 0 ) ;
F_6 ( NULL , 0 ) ;
}
static struct V_1 *
F_7 ( unsigned long V_16 )
{
struct V_1 * V_2 = NULL , * V_17 ;
F_8 ( & V_18 ) ;
F_9 (i, &queue_list, list) {
if ( ( unsigned long ) V_17 == V_16 ) {
V_2 = V_17 ;
break;
}
}
if ( V_2 ) {
F_10 ( & V_2 -> V_3 ) ;
V_5 -- ;
}
F_11 ( & V_18 ) ;
return V_2 ;
}
static void
F_6 ( T_1 V_19 , unsigned long V_20 )
{
struct V_1 * V_2 , * V_21 ;
F_12 (entry, next, &queue_list, list) {
if ( ! V_19 || V_19 ( V_2 , V_20 ) ) {
F_10 ( & V_2 -> V_3 ) ;
V_5 -- ;
F_13 ( V_2 , V_22 ) ;
}
}
}
static void
F_14 ( T_1 V_19 , unsigned long V_20 )
{
F_8 ( & V_18 ) ;
F_6 ( V_19 , V_20 ) ;
F_11 ( & V_18 ) ;
}
static struct V_23 *
F_15 ( struct V_1 * V_2 , int * V_24 )
{
T_2 V_25 ;
T_3 V_26 = 0 ;
T_3 V_27 = 0 ;
struct V_23 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
switch ( F_16 ( V_11 ) ) {
case V_10 :
case V_9 :
V_26 = F_17 ( sizeof( * V_30 ) ) ;
break;
case V_13 :
if ( V_2 -> V_28 -> V_35 == V_36 &&
( * V_24 = F_18 ( V_2 -> V_28 ) ) )
return NULL ;
V_27 = F_16 ( V_12 ) ;
if ( V_27 == 0 || V_27 > V_2 -> V_28 -> V_37 )
V_27 = V_2 -> V_28 -> V_37 ;
V_26 = F_17 ( sizeof( * V_30 ) + V_27 ) ;
break;
default:
* V_24 = - V_14 ;
return NULL ;
}
V_28 = F_19 ( V_26 , V_38 ) ;
if ( ! V_28 )
goto V_39;
V_25 = V_28 -> V_40 ;
V_32 = F_20 ( V_28 , 0 , 0 , V_41 , V_26 - sizeof( * V_32 ) ) ;
V_30 = F_21 ( V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_42 = ( unsigned long ) V_2 ;
V_30 -> V_27 = V_27 ;
V_34 = F_22 ( V_2 -> V_28 -> V_43 ) ;
V_30 -> V_44 = V_34 . V_45 ;
V_30 -> V_46 = V_34 . V_47 ;
V_30 -> V_48 = V_2 -> V_28 -> V_48 ;
V_30 -> V_49 = V_2 -> V_49 ;
V_30 -> V_50 = V_2 -> V_28 -> V_51 ;
if ( V_2 -> V_52 )
strcpy ( V_30 -> V_53 , V_2 -> V_52 -> V_54 ) ;
else
V_30 -> V_53 [ 0 ] = '\0' ;
if ( V_2 -> V_55 )
strcpy ( V_30 -> V_56 , V_2 -> V_55 -> V_54 ) ;
else
V_30 -> V_56 [ 0 ] = '\0' ;
if ( V_2 -> V_52 && V_2 -> V_28 -> V_57 &&
V_2 -> V_28 -> V_58 != V_2 -> V_28 -> V_59 ) {
V_30 -> V_60 = V_2 -> V_28 -> V_57 -> type ;
V_30 -> V_61 = F_23 ( V_2 -> V_28 , V_30 -> V_62 ) ;
}
if ( V_27 )
if ( F_24 ( V_2 -> V_28 , 0 , V_30 -> V_63 , V_27 ) )
F_25 () ;
V_32 -> V_64 = V_28 -> V_40 - V_25 ;
return V_28 ;
V_39:
* V_24 = - V_14 ;
F_26 ( V_65 L_1 ) ;
return NULL ;
}
static int
F_27 ( struct V_1 * V_2 , unsigned int V_66 )
{
int V_8 = - V_14 ;
struct V_23 * V_67 ;
if ( V_11 == V_9 )
return - V_68 ;
V_67 = F_15 ( V_2 , & V_8 ) ;
if ( V_67 == NULL )
return V_8 ;
F_8 ( & V_18 ) ;
if ( ! V_15 )
goto V_69;
if ( V_5 >= V_70 ) {
V_71 ++ ;
V_8 = - V_72 ;
if ( F_28 () )
F_26 ( V_73 L_2
L_3 , V_5 ,
V_71 ) ;
goto V_69;
}
V_8 = F_29 ( V_74 , V_67 , V_15 , V_75 ) ;
if ( V_8 < 0 ) {
V_76 ++ ;
goto V_77;
}
F_1 ( V_2 ) ;
F_11 ( & V_18 ) ;
return V_8 ;
V_69:
F_30 ( V_67 ) ;
V_77:
F_11 ( & V_18 ) ;
return V_8 ;
}
static int
F_31 ( T_4 * V_78 , struct V_1 * V_79 )
{
int V_80 ;
struct V_81 * V_82 = (struct V_81 * ) V_78 -> V_63 ;
struct V_23 * V_67 ;
if ( V_78 -> V_27 < sizeof( * V_82 ) )
return 0 ;
V_80 = V_78 -> V_27 - V_79 -> V_28 -> V_37 ;
if ( V_80 < 0 ) {
if ( F_32 ( V_79 -> V_28 , V_78 -> V_27 ) )
return - V_83 ;
} else if ( V_80 > 0 ) {
if ( V_78 -> V_27 > 0xFFFF )
return - V_14 ;
if ( V_80 > F_33 ( V_79 -> V_28 ) ) {
V_67 = F_34 ( V_79 -> V_28 , F_35 ( V_79 -> V_28 ) ,
V_80 , V_38 ) ;
if ( ! V_67 ) {
F_26 ( V_73 L_4
L_5 ) ;
return - V_83 ;
}
F_30 ( V_79 -> V_28 ) ;
V_79 -> V_28 = V_67 ;
}
F_36 ( V_79 -> V_28 , V_80 ) ;
}
if ( ! F_37 ( V_79 -> V_28 , V_78 -> V_27 ) )
return - V_83 ;
F_38 ( V_79 -> V_28 , V_78 -> V_63 , V_78 -> V_27 ) ;
V_79 -> V_28 -> V_35 = V_84 ;
return 0 ;
}
static int
F_39 ( struct V_85 * V_86 , unsigned int V_37 )
{
struct V_1 * V_2 ;
if ( V_86 -> V_87 > V_88 )
return - V_14 ;
V_2 = F_7 ( V_86 -> V_16 ) ;
if ( V_2 == NULL )
return - V_89 ;
else {
int V_90 = V_86 -> V_87 ;
if ( V_86 -> V_27 && V_86 -> V_27 == V_37 )
if ( F_31 ( V_86 , V_2 ) < 0 )
V_90 = V_22 ;
F_13 ( V_2 , V_90 ) ;
return 0 ;
}
}
static int
F_40 ( unsigned char V_6 , unsigned int V_7 )
{
int V_8 ;
F_8 ( & V_18 ) ;
V_8 = F_3 ( V_6 , V_7 ) ;
F_11 ( & V_18 ) ;
return V_8 ;
}
static int
F_41 ( struct V_91 * V_30 ,
unsigned char type , unsigned int V_37 )
{
int V_8 = 0 ;
if ( V_37 < sizeof( * V_30 ) )
return - V_14 ;
switch ( type ) {
case V_92 :
V_8 = F_40 ( V_30 -> V_93 . V_6 . V_87 ,
V_30 -> V_93 . V_6 . V_7 ) ;
break;
case V_94 :
if ( V_30 -> V_93 . V_90 . V_87 > V_88 )
V_8 = - V_14 ;
else
V_8 = F_39 ( & V_30 -> V_93 . V_90 ,
V_37 - sizeof( * V_30 ) ) ;
break;
default:
V_8 = - V_14 ;
}
return V_8 ;
}
static int
F_42 ( struct V_1 * V_2 , unsigned long V_95 )
{
if ( V_2 -> V_52 )
if ( V_2 -> V_52 -> V_95 == V_95 )
return 1 ;
if ( V_2 -> V_55 )
if ( V_2 -> V_55 -> V_95 == V_95 )
return 1 ;
#ifdef F_43
if ( V_2 -> V_28 -> V_96 ) {
if ( V_2 -> V_28 -> V_96 -> V_97 &&
V_2 -> V_28 -> V_96 -> V_97 -> V_95 == V_95 )
return 1 ;
if ( V_2 -> V_28 -> V_96 -> V_98 &&
V_2 -> V_28 -> V_96 -> V_98 -> V_95 == V_95 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_44 ( int V_95 )
{
F_14 ( F_42 , V_95 ) ;
}
static inline void
F_45 ( struct V_23 * V_28 )
{
int V_8 , type , V_99 , V_100 ;
unsigned int V_101 , V_102 ;
struct V_31 * V_32 ;
V_102 = V_28 -> V_37 ;
if ( V_102 < sizeof( * V_32 ) )
return;
V_32 = F_46 ( V_28 ) ;
V_101 = V_32 -> V_64 ;
if ( V_101 < sizeof( * V_32 ) || V_102 < V_101 )
return;
V_99 = V_32 -> V_103 ;
V_100 = V_32 -> V_104 ;
if( V_99 <= 0 || ! ( V_100 & V_105 ) || V_100 & V_106 )
F_47 ( - V_14 ) ;
if ( V_100 & V_107 )
F_47 ( - V_108 ) ;
type = V_32 -> V_109 ;
if ( type < V_110 || type >= V_111 )
F_47 ( - V_14 ) ;
if ( type <= V_112 )
return;
if ( F_48 ( V_28 , V_113 ) )
F_47 ( - V_114 ) ;
F_8 ( & V_18 ) ;
if ( V_15 ) {
if ( V_15 != V_99 ) {
F_11 ( & V_18 ) ;
F_47 ( - V_115 ) ;
}
} else {
F_49 () ;
V_15 = V_99 ;
}
F_11 ( & V_18 ) ;
V_8 = F_41 ( F_21 ( V_32 ) , type ,
V_101 - F_50 ( 0 ) ) ;
if ( V_8 < 0 )
F_47 ( V_8 ) ;
if ( V_100 & V_116 )
F_51 ( V_28 , V_32 , 0 ) ;
}
static void
F_52 ( struct V_23 * V_28 )
{
F_53 ( & V_117 ) ;
F_45 ( V_28 ) ;
F_54 ( & V_117 ) ;
}
static int
F_55 ( struct V_118 * V_119 ,
unsigned long V_120 , void * V_121 )
{
struct V_122 * V_57 = V_121 ;
if ( ! F_56 ( F_57 ( V_57 ) , & V_123 ) )
return V_124 ;
if ( V_120 == V_125 )
F_44 ( V_57 -> V_95 ) ;
return V_124 ;
}
static int
F_58 ( struct V_118 * V_119 ,
unsigned long V_120 , void * V_121 )
{
struct V_126 * V_127 = V_121 ;
if ( V_120 == V_128 && V_127 -> V_51 == V_129 ) {
F_8 ( & V_18 ) ;
if ( ( F_56 ( V_127 -> V_130 , & V_123 ) ) && ( V_127 -> V_99 == V_15 ) )
F_4 () ;
F_11 ( & V_18 ) ;
}
return V_124 ;
}
static int F_59 ( struct V_131 * V_132 , void * V_78 )
{
F_8 ( & V_18 ) ;
F_60 ( V_132 ,
L_6
L_7
L_8
L_9
L_10
L_11
L_12 ,
V_15 ,
V_11 ,
V_12 ,
V_5 ,
V_70 ,
V_71 ,
V_76 ) ;
F_11 ( & V_18 ) ;
return 0 ;
}
static int F_61 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_62 ( V_134 , F_59 , NULL ) ;
}
static int T_5 F_63 ( void )
{
int V_8 = - V_83 ;
struct V_135 * T_6 V_136 ;
F_64 ( & V_137 ) ;
V_74 = F_65 ( & V_123 , V_129 , 0 ,
F_52 , NULL , V_138 ) ;
if ( V_74 == NULL ) {
F_26 ( V_65 L_13 ) ;
goto V_139;
}
#ifdef F_66
T_6 = F_67 ( V_140 , 0 , V_123 . V_141 ,
& V_142 ) ;
if ( ! T_6 ) {
F_26 ( V_65 L_14 ) ;
goto V_143;
}
#endif
F_68 ( & V_144 ) ;
#ifdef F_69
V_145 = F_70 ( V_146 , V_147 ) ;
#endif
V_8 = F_71 ( V_148 , & V_149 ) ;
if ( V_8 < 0 ) {
F_26 ( V_65 L_15 ) ;
goto V_150;
}
return V_8 ;
V_150:
#ifdef F_69
F_72 ( V_145 ) ;
#endif
F_73 ( & V_144 ) ;
F_74 ( & V_123 , V_140 ) ;
V_143: V_136
V_151 ( V_74 ) ;
F_53 ( & V_117 ) ;
F_54 ( & V_117 ) ;
V_139:
F_75 ( & V_137 ) ;
return V_8 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_149 ) ;
F_14 ( NULL , 0 ) ;
#ifdef F_69
F_72 ( V_145 ) ;
#endif
F_73 ( & V_144 ) ;
F_74 ( & V_123 , V_140 ) ;
V_151 ( V_74 ) ;
F_53 ( & V_117 ) ;
F_54 ( & V_117 ) ;
F_75 ( & V_137 ) ;
}
