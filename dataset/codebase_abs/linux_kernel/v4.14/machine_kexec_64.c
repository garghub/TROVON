static void F_1 ( struct V_1 * V_2 )
{
F_2 ( ( unsigned long ) V_2 -> V_3 . V_4 ) ;
F_2 ( ( unsigned long ) V_2 -> V_3 . V_5 ) ;
F_2 ( ( unsigned long ) V_2 -> V_3 . V_6 ) ;
F_2 ( ( unsigned long ) V_2 -> V_3 . V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_8 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
T_5 * V_7 ;
unsigned long V_9 , V_10 ;
int V_11 = - V_12 ;
V_9 = ( unsigned long ) V_13 ;
V_10 = F_4 ( F_5 ( V_2 -> V_14 ) + V_15 ) ;
V_8 += F_6 ( V_9 ) ;
if ( ! F_7 ( * V_8 ) ) {
V_4 = ( T_2 * ) F_8 ( V_16 ) ;
if ( ! V_4 )
goto V_17;
V_2 -> V_3 . V_4 = V_4 ;
F_9 ( V_8 , F_10 ( F_4 ( V_4 ) | V_18 ) ) ;
}
V_4 = F_11 ( V_8 , V_9 ) ;
if ( ! F_12 ( * V_4 ) ) {
V_5 = ( T_3 * ) F_8 ( V_16 ) ;
if ( ! V_5 )
goto V_17;
V_2 -> V_3 . V_5 = V_5 ;
F_13 ( V_4 , F_14 ( F_4 ( V_5 ) | V_18 ) ) ;
}
V_5 = F_15 ( V_4 , V_9 ) ;
if ( ! F_16 ( * V_5 ) ) {
V_6 = ( T_4 * ) F_8 ( V_16 ) ;
if ( ! V_6 )
goto V_17;
V_2 -> V_3 . V_6 = V_6 ;
F_17 ( V_5 , F_18 ( F_4 ( V_6 ) | V_18 ) ) ;
}
V_6 = F_19 ( V_5 , V_9 ) ;
if ( ! F_20 ( * V_6 ) ) {
V_7 = ( T_5 * ) F_8 ( V_16 ) ;
if ( ! V_7 )
goto V_17;
V_2 -> V_3 . V_7 = V_7 ;
F_21 ( V_6 , F_22 ( F_4 ( V_7 ) | V_18 ) ) ;
}
V_7 = F_23 ( V_6 , V_9 ) ;
F_24 ( V_7 , F_25 ( V_10 >> V_19 , V_20 ) ) ;
return 0 ;
V_17:
F_1 ( V_2 ) ;
return V_11 ;
}
static void * F_26 ( void * V_21 )
{
struct V_1 * V_2 = (struct V_1 * ) V_21 ;
struct V_22 * V_22 ;
void * V_23 = NULL ;
V_22 = F_27 ( V_2 , 0 ) ;
if ( V_22 ) {
V_23 = F_5 ( V_22 ) ;
F_28 ( V_23 ) ;
}
return V_23 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_24 )
{
struct V_25 V_26 = {
. F_26 = F_26 ,
. V_27 = V_2 ,
. V_28 = V_29 ,
. V_30 = V_31 ,
} ;
unsigned long V_32 , V_33 ;
T_1 * V_34 ;
int V_11 ;
int V_35 ;
V_34 = ( T_1 * ) F_30 ( V_24 ) ;
F_28 ( V_34 ) ;
if ( V_36 )
V_26 . V_36 = true ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
V_32 = V_38 [ V_35 ] . V_39 << V_19 ;
V_33 = V_38 [ V_35 ] . V_40 << V_19 ;
V_11 = F_31 ( & V_26 ,
V_34 , V_32 , V_33 ) ;
if ( V_11 )
return V_11 ;
}
for ( V_35 = 0 ; V_35 < V_2 -> V_41 ; V_35 ++ ) {
V_32 = V_2 -> V_42 [ V_35 ] . V_43 ;
V_33 = V_32 + V_2 -> V_42 [ V_35 ] . V_44 ;
V_11 = F_31 ( & V_26 ,
V_34 , V_32 , V_33 ) ;
if ( V_11 )
return V_11 ;
}
return F_3 ( V_2 , V_34 ) ;
}
static void F_32 ( void * V_45 , T_6 V_46 )
{
struct V_47 V_48 ;
V_48 . V_49 = V_46 ;
V_48 . V_50 = ( unsigned long ) V_45 ;
__asm__ __volatile__ (
"lidtq %0\n"
: : "m" (curidt)
);
}
static void F_33 ( void * V_51 , T_6 V_46 )
{
struct V_47 V_52 ;
V_52 . V_49 = V_46 ;
V_52 . V_50 = ( unsigned long ) V_51 ;
__asm__ __volatile__ (
"lgdtq %0\n"
: : "m" (curgdt)
);
}
static void F_34 ( void )
{
__asm__ __volatile__ (
"\tmovl %0,%%ds\n"
"\tmovl %0,%%es\n"
"\tmovl %0,%%ss\n"
"\tmovl %0,%%fs\n"
"\tmovl %0,%%gs\n"
: : "a" (__KERNEL_DS) : "memory"
);
}
static int F_35 ( struct V_1 * V_2 )
{
int V_53 = 0 ;
if ( ! V_2 -> V_54 )
return 0 ;
if ( V_2 -> type == V_55 ) {
V_53 = F_36 ( V_2 ,
L_1 ,
& V_2 -> V_3 . V_56 ,
sizeof( V_2 -> V_3 . V_56 ) , 0 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_36 ( V_2 ,
L_2 ,
& V_2 -> V_3 . V_57 ,
sizeof( V_2 -> V_3 . V_57 ) , 0 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_36 ( V_2 ,
L_3 ,
& V_2 -> V_3 . V_58 ,
sizeof( V_2 -> V_3 . V_58 ) , 0 ) ;
if ( V_53 )
return V_53 ;
}
return V_53 ;
}
static inline int F_35 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
int V_11 ;
V_24 = F_38 ( V_2 -> V_14 ) << V_19 ;
V_11 = F_29 ( V_2 , V_24 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_35 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
unsigned long V_59 [ V_60 ] ;
void * V_61 ;
int V_62 ;
#ifdef F_41
if ( V_2 -> V_63 )
F_42 () ;
#endif
V_62 = F_43 () ;
F_44 () ;
F_45 () ;
if ( V_2 -> V_63 ) {
#ifdef F_46
F_47 () ;
#endif
}
V_61 = F_5 ( V_2 -> V_14 ) + V_15 ;
memcpy ( V_61 , V_13 , V_64 ) ;
V_59 [ V_65 ] = F_48 ( V_61 ) ;
V_59 [ V_66 ] = ( unsigned long ) V_61 ;
V_59 [ V_67 ] =
( unsigned long ) F_4 ( F_5 ( V_2 -> V_14 ) ) ;
if ( V_2 -> type == V_68 )
V_59 [ V_69 ] = ( F_38 ( V_2 -> V_70 )
<< V_19 ) ;
F_34 () ;
F_33 ( F_49 ( 0 ) , 0 ) ;
F_32 ( F_49 ( 0 ) , 0 ) ;
V_2 -> V_39 = V_13 ( ( unsigned long ) V_2 -> V_71 ,
( unsigned long ) V_59 ,
V_2 -> V_39 ,
V_2 -> V_63 ,
F_50 () ) ;
#ifdef F_41
if ( V_2 -> V_63 )
F_51 () ;
#endif
F_52 ( V_62 ) ;
}
void F_53 ( void )
{
F_54 ( V_72 ) ;
F_55 ( V_73 ) ;
#ifdef F_56
F_55 ( V_74 ) ;
F_57 ( V_74 , V_75 ) ;
#endif
F_58 ( L_4 ,
F_59 () ) ;
F_54 ( V_76 ) ;
}
int F_60 ( struct V_1 * V_2 , void * V_77 ,
unsigned long V_78 )
{
int V_35 , V_53 = - V_79 ;
struct V_80 * V_81 ;
for ( V_35 = 0 ; V_35 < F_61 ( V_82 ) ; V_35 ++ ) {
V_81 = V_82 [ V_35 ] ;
if ( ! V_81 || ! V_81 -> V_83 )
continue;
V_53 = V_81 -> V_83 ( V_77 , V_78 ) ;
if ( ! V_53 ) {
V_2 -> V_81 = V_81 ;
return V_53 ;
}
}
return V_53 ;
}
void * F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_3 . V_84 ) ;
V_2 -> V_3 . V_84 = NULL ;
if ( ! V_2 -> V_81 || ! V_2 -> V_81 -> V_85 )
return F_64 ( - V_79 ) ;
return V_2 -> V_81 -> V_85 ( V_2 , V_2 -> V_86 ,
V_2 -> V_87 , V_2 -> V_88 ,
V_2 -> V_89 , V_2 -> V_90 ,
V_2 -> V_91 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_81 || ! V_2 -> V_81 -> V_92 )
return 0 ;
return V_2 -> V_81 -> V_92 ( V_2 -> V_93 ) ;
}
int F_66 ( struct V_1 * V_2 , void * V_94 ,
unsigned long V_95 )
{
if ( ! V_2 -> V_81 || ! V_2 -> V_81 -> V_96 ) {
F_67 ( L_5 ) ;
return - V_97 ;
}
return V_2 -> V_81 -> V_96 ( V_94 , V_95 ) ;
}
int F_68 ( const T_7 * V_98 ,
T_8 * V_99 , unsigned int V_100 )
{
unsigned int V_35 ;
T_9 * V_101 ;
T_10 * V_102 ;
void * V_103 ;
T_8 * V_104 , * V_105 ;
unsigned long V_50 , V_106 , V_107 ;
const char * V_108 , * V_109 , * V_110 ;
V_101 = ( void * ) V_99 [ V_100 ] . V_111 ;
V_104 = & V_99 [ V_99 [ V_100 ] . V_112 ] ;
F_67 ( L_6 , V_100 ,
V_99 [ V_100 ] . V_112 ) ;
V_105 = & V_99 [ V_99 [ V_100 ] . V_113 ] ;
if ( V_105 -> V_113 >= V_98 -> V_114 ) {
F_69 ( L_7 ,
V_105 -> V_113 ) ;
return - V_79 ;
}
V_108 = ( char * ) V_99 [ V_105 -> V_113 ] . V_111 ;
V_110 = ( char * ) V_99 [ V_98 -> V_115 ] . V_111 ;
for ( V_35 = 0 ; V_35 < V_99 [ V_100 ] . V_116 / sizeof( * V_101 ) ; V_35 ++ ) {
V_103 = ( void * ) ( V_104 -> V_111 + V_101 [ V_35 ] . V_117 ) ;
V_50 = V_104 -> V_118 + V_101 [ V_35 ] . V_117 ;
V_102 = ( T_10 * ) V_105 -> V_111 +
F_70 ( V_101 [ V_35 ] . V_119 ) ;
if ( V_102 -> V_120 )
V_109 = V_108 + V_102 -> V_120 ;
else
V_109 = V_110 + V_99 [ V_102 -> V_121 ] . V_122 ;
F_67 ( L_8 ,
V_109 , V_102 -> V_123 , V_102 -> V_121 , V_102 -> V_124 ,
V_102 -> V_125 ) ;
if ( V_102 -> V_121 == V_126 ) {
F_69 ( L_9 , V_109 ) ;
return - V_79 ;
}
if ( V_102 -> V_121 == V_127 ) {
F_69 ( L_10 , V_109 ) ;
return - V_79 ;
}
if ( V_102 -> V_121 == V_128 )
V_106 = 0 ;
else if ( V_102 -> V_121 >= V_98 -> V_114 ) {
F_69 ( L_11 ,
V_102 -> V_121 , V_109 ) ;
return - V_79 ;
} else
V_106 = V_99 [ V_102 -> V_121 ] . V_118 ;
V_107 = V_102 -> V_124 ;
V_107 += V_106 ;
V_107 += V_101 [ V_35 ] . V_129 ;
switch ( F_71 ( V_101 [ V_35 ] . V_119 ) ) {
case V_130 :
break;
case V_131 :
* ( V_132 * ) V_103 = V_107 ;
break;
case V_133 :
* ( V_134 * ) V_103 = V_107 ;
if ( V_107 != * ( V_134 * ) V_103 )
goto V_135;
break;
case V_136 :
* ( V_137 * ) V_103 = V_107 ;
if ( ( V_138 ) V_107 != * ( V_137 * ) V_103 )
goto V_135;
break;
case V_139 :
V_107 -= ( V_132 ) V_50 ;
* ( V_134 * ) V_103 = V_107 ;
break;
default:
F_69 ( L_12 ,
F_71 ( V_101 [ V_35 ] . V_119 ) ) ;
return - V_79 ;
}
}
return 0 ;
V_135:
F_69 ( L_13 ,
( int ) F_71 ( V_101 [ V_35 ] . V_119 ) , V_107 ) ;
return - V_79 ;
}
static int
F_72 ( unsigned long V_39 , unsigned long V_40 , bool V_140 )
{
struct V_22 * V_22 ;
unsigned int V_141 ;
if ( ! V_40 || V_39 > V_40 )
return 0 ;
V_22 = F_73 ( V_39 >> V_19 ) ;
V_141 = ( V_40 >> V_19 ) - ( V_39 >> V_19 ) + 1 ;
if ( V_140 )
return F_74 ( V_22 , V_141 ) ;
else
return F_75 ( V_22 , V_141 ) ;
}
static void F_76 ( bool V_140 )
{
unsigned long V_142 ;
F_72 ( V_143 . V_39 , V_143 . V_40 , V_140 ) ;
V_142 = F_77 ( F_38 ( V_144 -> V_14 ) ) ;
F_72 ( V_145 . V_39 , V_142 + V_15 - 1 , V_140 ) ;
V_142 += V_146 ;
F_72 ( V_142 , V_145 . V_40 , V_140 ) ;
}
void F_78 ( void )
{
F_76 ( true ) ;
}
void F_79 ( void )
{
F_76 ( false ) ;
}
int F_80 ( void * V_9 , unsigned int V_147 , T_11 V_148 )
{
return F_81 ( ( unsigned long ) V_9 , V_147 ) ;
}
void F_82 ( void * V_9 , unsigned int V_147 )
{
F_83 ( ( unsigned long ) V_9 , V_147 ) ;
}
