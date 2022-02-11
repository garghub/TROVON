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
} ;
unsigned long V_30 , V_31 ;
T_1 * V_32 ;
int V_11 ;
int V_33 ;
V_32 = ( T_1 * ) F_30 ( V_24 ) ;
F_28 ( V_32 ) ;
if ( V_34 )
V_26 . V_34 = true ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_30 = V_36 [ V_33 ] . V_37 << V_19 ;
V_31 = V_36 [ V_33 ] . V_38 << V_19 ;
V_11 = F_31 ( & V_26 ,
V_32 , V_30 , V_31 ) ;
if ( V_11 )
return V_11 ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_39 ; V_33 ++ ) {
V_30 = V_2 -> V_40 [ V_33 ] . V_41 ;
V_31 = V_30 + V_2 -> V_40 [ V_33 ] . V_42 ;
V_11 = F_31 ( & V_26 ,
V_32 , V_30 , V_31 ) ;
if ( V_11 )
return V_11 ;
}
return F_3 ( V_2 , V_32 ) ;
}
static void F_32 ( void * V_43 , T_6 V_44 )
{
struct V_45 V_46 ;
V_46 . V_47 = V_44 ;
V_46 . V_48 = ( unsigned long ) V_43 ;
__asm__ __volatile__ (
"lidtq %0\n"
: : "m" (curidt)
);
}
static void F_33 ( void * V_49 , T_6 V_44 )
{
struct V_45 V_50 ;
V_50 . V_47 = V_44 ;
V_50 . V_48 = ( unsigned long ) V_49 ;
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
int V_51 = 0 ;
if ( ! V_2 -> V_52 )
return 0 ;
if ( V_2 -> type == V_53 ) {
V_51 = F_36 ( V_2 ,
L_1 ,
& V_2 -> V_3 . V_54 ,
sizeof( V_2 -> V_3 . V_54 ) , 0 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_36 ( V_2 ,
L_2 ,
& V_2 -> V_3 . V_55 ,
sizeof( V_2 -> V_3 . V_55 ) , 0 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_36 ( V_2 ,
L_3 ,
& V_2 -> V_3 . V_56 ,
sizeof( V_2 -> V_3 . V_56 ) , 0 ) ;
if ( V_51 )
return V_51 ;
}
return V_51 ;
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
unsigned long V_57 [ V_58 ] ;
void * V_59 ;
int V_60 ;
#ifdef F_41
if ( V_2 -> V_61 )
F_42 () ;
#endif
V_60 = F_43 () ;
F_44 () ;
F_45 () ;
if ( V_2 -> V_61 ) {
#ifdef F_46
F_47 () ;
#endif
}
V_59 = F_5 ( V_2 -> V_14 ) + V_15 ;
memcpy ( V_59 , V_13 , V_62 ) ;
V_57 [ V_63 ] = F_48 ( V_59 ) ;
V_57 [ V_64 ] = ( unsigned long ) V_59 ;
V_57 [ V_65 ] =
( unsigned long ) F_4 ( F_5 ( V_2 -> V_14 ) ) ;
if ( V_2 -> type == V_66 )
V_57 [ V_67 ] = ( F_38 ( V_2 -> V_68 )
<< V_19 ) ;
F_34 () ;
F_33 ( F_49 ( 0 ) , 0 ) ;
F_32 ( F_49 ( 0 ) , 0 ) ;
V_2 -> V_37 = V_13 ( ( unsigned long ) V_2 -> V_69 ,
( unsigned long ) V_57 ,
V_2 -> V_37 ,
V_2 -> V_61 ) ;
#ifdef F_41
if ( V_2 -> V_61 )
F_50 () ;
#endif
F_51 ( V_60 ) ;
}
void F_52 ( void )
{
F_53 ( V_70 ) ;
F_54 ( V_71 ) ;
#ifdef F_55
F_54 ( V_72 ) ;
F_56 ( V_72 , V_73 ) ;
#endif
F_57 ( L_4 ,
F_58 () ) ;
F_53 ( V_74 ) ;
}
int F_59 ( struct V_1 * V_2 , void * V_75 ,
unsigned long V_76 )
{
int V_33 , V_51 = - V_77 ;
struct V_78 * V_79 ;
for ( V_33 = 0 ; V_33 < F_60 ( V_80 ) ; V_33 ++ ) {
V_79 = V_80 [ V_33 ] ;
if ( ! V_79 || ! V_79 -> V_81 )
continue;
V_51 = V_79 -> V_81 ( V_75 , V_76 ) ;
if ( ! V_51 ) {
V_2 -> V_79 = V_79 ;
return V_51 ;
}
}
return V_51 ;
}
void * F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_3 . V_82 ) ;
V_2 -> V_3 . V_82 = NULL ;
if ( ! V_2 -> V_79 || ! V_2 -> V_79 -> V_83 )
return F_63 ( - V_77 ) ;
return V_2 -> V_79 -> V_83 ( V_2 , V_2 -> V_84 ,
V_2 -> V_85 , V_2 -> V_86 ,
V_2 -> V_87 , V_2 -> V_88 ,
V_2 -> V_89 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_79 || ! V_2 -> V_79 -> V_90 )
return 0 ;
return V_2 -> V_79 -> V_90 ( V_2 -> V_91 ) ;
}
int F_65 ( struct V_1 * V_2 , void * V_92 ,
unsigned long V_93 )
{
if ( ! V_2 -> V_79 || ! V_2 -> V_79 -> V_94 ) {
F_66 ( L_5 ) ;
return - V_95 ;
}
return V_2 -> V_79 -> V_94 ( V_92 , V_93 ) ;
}
int F_67 ( const T_7 * V_96 ,
T_8 * V_97 , unsigned int V_98 )
{
unsigned int V_33 ;
T_9 * V_99 ;
T_10 * V_100 ;
void * V_101 ;
T_8 * V_102 , * V_103 ;
unsigned long V_48 , V_104 , V_105 ;
const char * V_106 , * V_107 , * V_108 ;
V_99 = ( void * ) V_97 [ V_98 ] . V_109 ;
V_102 = & V_97 [ V_97 [ V_98 ] . V_110 ] ;
F_66 ( L_6 , V_98 ,
V_97 [ V_98 ] . V_110 ) ;
V_103 = & V_97 [ V_97 [ V_98 ] . V_111 ] ;
if ( V_103 -> V_111 >= V_96 -> V_112 ) {
F_68 ( L_7 ,
V_103 -> V_111 ) ;
return - V_77 ;
}
V_106 = ( char * ) V_97 [ V_103 -> V_111 ] . V_109 ;
V_108 = ( char * ) V_97 [ V_96 -> V_113 ] . V_109 ;
for ( V_33 = 0 ; V_33 < V_97 [ V_98 ] . V_114 / sizeof( * V_99 ) ; V_33 ++ ) {
V_101 = ( void * ) ( V_102 -> V_109 + V_99 [ V_33 ] . V_115 ) ;
V_48 = V_102 -> V_116 + V_99 [ V_33 ] . V_115 ;
V_100 = ( T_10 * ) V_103 -> V_109 +
F_69 ( V_99 [ V_33 ] . V_117 ) ;
if ( V_100 -> V_118 )
V_107 = V_106 + V_100 -> V_118 ;
else
V_107 = V_108 + V_97 [ V_100 -> V_119 ] . V_120 ;
F_66 ( L_8 ,
V_107 , V_100 -> V_121 , V_100 -> V_119 , V_100 -> V_122 ,
V_100 -> V_123 ) ;
if ( V_100 -> V_119 == V_124 ) {
F_68 ( L_9 , V_107 ) ;
return - V_77 ;
}
if ( V_100 -> V_119 == V_125 ) {
F_68 ( L_10 , V_107 ) ;
return - V_77 ;
}
if ( V_100 -> V_119 == V_126 )
V_104 = 0 ;
else if ( V_100 -> V_119 >= V_96 -> V_112 ) {
F_68 ( L_11 ,
V_100 -> V_119 , V_107 ) ;
return - V_77 ;
} else
V_104 = V_97 [ V_100 -> V_119 ] . V_116 ;
V_105 = V_100 -> V_122 ;
V_105 += V_104 ;
V_105 += V_99 [ V_33 ] . V_127 ;
switch ( F_70 ( V_99 [ V_33 ] . V_117 ) ) {
case V_128 :
break;
case V_129 :
* ( V_130 * ) V_101 = V_105 ;
break;
case V_131 :
* ( V_132 * ) V_101 = V_105 ;
if ( V_105 != * ( V_132 * ) V_101 )
goto V_133;
break;
case V_134 :
* ( V_135 * ) V_101 = V_105 ;
if ( ( V_136 ) V_105 != * ( V_135 * ) V_101 )
goto V_133;
break;
case V_137 :
V_105 -= ( V_130 ) V_48 ;
* ( V_132 * ) V_101 = V_105 ;
break;
default:
F_68 ( L_12 ,
F_70 ( V_99 [ V_33 ] . V_117 ) ) ;
return - V_77 ;
}
}
return 0 ;
V_133:
F_68 ( L_13 ,
( int ) F_70 ( V_99 [ V_33 ] . V_117 ) , V_105 ) ;
return - V_77 ;
}
static int
F_71 ( unsigned long V_37 , unsigned long V_38 , bool V_138 )
{
struct V_22 * V_22 ;
unsigned int V_139 ;
if ( ! V_38 || V_37 > V_38 )
return 0 ;
V_22 = F_72 ( V_37 >> V_19 ) ;
V_139 = ( V_38 >> V_19 ) - ( V_37 >> V_19 ) + 1 ;
if ( V_138 )
return F_73 ( V_22 , V_139 ) ;
else
return F_74 ( V_22 , V_139 ) ;
}
static void F_75 ( bool V_138 )
{
unsigned long V_140 ;
F_71 ( V_141 . V_37 , V_141 . V_38 , V_138 ) ;
V_140 = F_76 ( F_38 ( V_142 -> V_14 ) ) ;
F_71 ( V_143 . V_37 , V_140 + V_15 - 1 , V_138 ) ;
V_140 += V_144 ;
F_71 ( V_140 , V_143 . V_38 , V_138 ) ;
}
void F_77 ( void )
{
F_75 ( true ) ;
}
void F_78 ( void )
{
F_75 ( false ) ;
}
