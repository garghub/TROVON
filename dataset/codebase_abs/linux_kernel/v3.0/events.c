static struct V_1 * F_1 ( unsigned V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_3 ,
unsigned V_2 ,
enum V_4 type ,
unsigned short V_5 ,
unsigned short V_6 )
{
F_4 ( V_3 -> type != V_7 && V_3 -> type != type ) ;
V_3 -> type = type ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = V_6 ;
V_8 [ V_5 ] = V_2 ;
}
static void F_5 ( unsigned V_2 ,
unsigned short V_5 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_9 , V_5 , 0 ) ;
}
static void F_6 ( unsigned V_6 ,
unsigned V_2 ,
unsigned short V_5 ,
enum V_10 V_11 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_12 , V_5 , 0 ) ;
V_3 -> V_13 . V_11 = V_11 ;
F_7 ( V_14 , V_6 ) [ V_11 ] = V_2 ;
}
static void F_8 ( unsigned V_6 ,
unsigned V_2 ,
unsigned short V_5 ,
unsigned short V_15 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_16 , V_5 , 0 ) ;
V_3 -> V_13 . V_15 = V_15 ;
F_7 ( V_17 , V_6 ) [ V_15 ] = V_2 ;
}
static void F_9 ( unsigned V_2 ,
unsigned short V_5 ,
unsigned short V_18 ,
unsigned short V_19 ,
unsigned short V_20 ,
T_1 V_21 ,
unsigned char V_22 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_23 , V_5 , 0 ) ;
V_3 -> V_13 . V_18 . V_18 = V_18 ;
V_3 -> V_13 . V_18 . V_19 = V_19 ;
V_3 -> V_13 . V_18 . V_20 = V_20 ;
V_3 -> V_13 . V_18 . V_21 = V_21 ;
V_3 -> V_13 . V_18 . V_22 = V_22 ;
}
static unsigned int F_10 ( unsigned V_2 )
{
if ( F_11 ( F_12 ( V_2 < 0 || V_2 >= V_24 , L_1 , V_2 ) ) )
return 0 ;
return F_1 ( V_2 ) -> V_5 ;
}
unsigned F_13 ( unsigned int V_5 )
{
return V_8 [ V_5 ] ;
}
static enum V_10 F_14 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_12 ) ;
return V_3 -> V_13 . V_11 ;
}
static unsigned F_15 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_16 ) ;
return V_3 -> V_13 . V_15 ;
}
static unsigned F_16 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_23 ) ;
return V_3 -> V_13 . V_18 . V_18 ;
}
static enum V_4 F_17 ( unsigned V_2 )
{
return F_1 ( V_2 ) -> type ;
}
static unsigned F_18 ( unsigned V_2 )
{
return F_1 ( V_2 ) -> V_6 ;
}
static unsigned int F_19 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
unsigned V_25 = 0 ;
if ( V_2 != - 1 )
V_25 = F_18 ( V_2 ) ;
return V_25 ;
}
static bool F_20 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
return V_3 -> V_13 . V_18 . V_22 & V_26 ;
}
static inline unsigned long F_21 ( unsigned int V_6 ,
struct V_27 * V_28 ,
unsigned int V_29 )
{
return ( V_28 -> V_30 [ V_29 ] &
F_7 ( V_31 , V_6 ) [ V_29 ] &
~ V_28 -> V_32 [ V_29 ] ) ;
}
static void F_22 ( unsigned int V_33 , unsigned int V_6 )
{
int V_2 = V_8 [ V_33 ] ;
F_4 ( V_2 == - 1 ) ;
#ifdef F_23
F_24 ( F_25 ( V_2 ) -> V_34 . V_35 , F_26 ( V_6 ) ) ;
#endif
F_27 ( V_33 , F_7 ( V_31 , F_18 ( V_2 ) ) ) ;
F_28 ( V_33 , F_7 ( V_31 , V_6 ) ) ;
F_1 ( V_2 ) -> V_6 = V_6 ;
}
static void F_29 ( void )
{
int V_36 ;
#ifdef F_23
struct V_1 * V_3 ;
F_30 (info, &xen_irq_list_head, list) {
struct V_37 * V_38 = F_25 ( V_3 -> V_2 ) ;
F_24 ( V_38 -> V_34 . V_35 , F_26 ( 0 ) ) ;
}
#endif
F_31 (i)
memset ( F_7 ( V_31 , V_36 ) ,
( V_36 == 0 ) ? ~ 0 : 0 , sizeof( * F_7 ( V_31 , V_36 ) ) ) ;
}
static inline void F_32 ( int V_39 )
{
struct V_27 * V_40 = V_41 ;
F_33 ( V_39 , & V_40 -> V_30 [ 0 ] ) ;
}
static inline void F_34 ( int V_39 )
{
struct V_27 * V_40 = V_41 ;
F_35 ( V_39 , & V_40 -> V_30 [ 0 ] ) ;
}
static inline int F_36 ( int V_39 )
{
struct V_27 * V_40 = V_41 ;
return F_37 ( V_39 , & V_40 -> V_30 [ 0 ] ) ;
}
void F_38 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) )
F_40 ( V_5 ) ;
}
static void F_41 ( int V_39 )
{
struct V_27 * V_40 = V_41 ;
F_35 ( V_39 , & V_40 -> V_32 [ 0 ] ) ;
}
static void F_42 ( int V_39 )
{
struct V_27 * V_40 = V_41 ;
unsigned int V_6 = F_43 () ;
F_4 ( ! F_44 () ) ;
if ( F_11 ( V_6 != F_19 ( V_39 ) ) ) {
struct V_42 V_43 = { . V_39 = V_39 } ;
( void ) F_45 ( V_44 , & V_43 ) ;
} else {
struct V_45 * V_45 = F_46 ( V_46 ) ;
F_33 ( V_39 , & V_40 -> V_32 [ 0 ] ) ;
if ( F_37 ( V_39 , & V_40 -> V_30 [ 0 ] ) &&
! F_47 ( V_39 / V_47 ,
& V_45 -> V_48 ) )
V_45 -> V_49 = 1 ;
}
F_48 () ;
}
static void F_49 ( unsigned V_2 )
{
struct V_1 * V_3 ;
#ifdef F_23
struct V_37 * V_38 = F_25 ( V_2 ) ;
F_24 ( V_38 -> V_34 . V_35 , F_26 ( 0 ) ) ;
#endif
V_3 = F_50 ( sizeof( * V_3 ) , V_50 ) ;
if ( V_3 == NULL )
F_51 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
F_52 ( V_2 , V_3 ) ;
F_53 ( & V_3 -> V_51 , & V_52 ) ;
}
static int T_2 F_54 ( void )
{
int V_53 = 0 ;
int V_2 ;
#ifdef F_55
if ( F_56 () || F_57 () )
V_53 = F_58 () ;
#endif
V_2 = F_59 ( V_53 , - 1 ) ;
F_49 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_60 ( unsigned V_19 )
{
int V_2 ;
if ( F_61 () && ! F_56 () )
return F_54 () ;
if ( V_19 < V_54 )
V_2 = V_19 ;
else
V_2 = F_62 ( V_19 , - 1 ) ;
F_49 ( V_2 ) ;
return V_2 ;
}
static void F_63 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_64 ( & V_3 -> V_51 ) ;
F_52 ( V_2 , NULL ) ;
F_65 ( V_3 ) ;
if ( V_2 < V_54 )
return;
F_66 ( V_2 ) ;
}
static void F_67 ( int V_2 )
{
struct V_55 V_56 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
V_56 . V_2 = F_16 ( V_2 ) ;
if ( F_68 ( V_57 , & V_56 ) )
V_56 . V_22 = 0 ;
V_3 -> V_13 . V_18 . V_22 &= ~ V_26 ;
if ( V_56 . V_22 & V_58 )
V_3 -> V_13 . V_18 . V_22 |= V_26 ;
}
static bool F_69 ( int V_2 )
{
struct V_37 * V_38 = F_25 ( V_2 ) ;
return V_38 && V_38 -> V_59 == NULL ;
}
static void F_70 ( struct V_34 * V_60 )
{
int V_5 = F_10 ( V_60 -> V_2 ) ;
struct V_61 V_62 = { . V_2 = F_16 (data->irq) } ;
int V_63 = 0 ;
F_71 ( V_60 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
if ( F_20 ( V_60 -> V_2 ) ) {
V_63 = F_68 ( V_64 , & V_62 ) ;
F_72 ( V_63 ) ;
}
}
static void F_73 ( struct V_34 * V_60 )
{
F_74 ( V_60 ) ;
F_70 ( V_60 ) ;
}
static unsigned int F_75 ( unsigned int V_2 )
{
struct V_65 V_66 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
int V_63 ;
F_4 ( V_3 -> type != V_23 ) ;
if ( F_39 ( V_5 ) )
goto V_67;
V_66 . V_18 = F_16 ( V_2 ) ;
V_66 . V_22 = V_3 -> V_13 . V_18 . V_22 & V_68 ?
V_69 : 0 ;
V_63 = F_45 ( V_70 , & V_66 ) ;
if ( V_63 != 0 ) {
if ( ! F_69 ( V_2 ) )
F_76 ( V_71 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_66 . V_39 ;
F_67 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_22 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_67:
F_42 ( V_5 ) ;
F_70 ( F_77 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_78 ( struct V_34 * V_60 )
{
return F_75 ( V_60 -> V_2 ) ;
}
static void F_79 ( struct V_34 * V_60 )
{
struct V_72 V_73 ;
unsigned int V_2 = V_60 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
if ( ! F_39 ( V_5 ) )
return;
F_41 ( V_5 ) ;
V_73 . V_39 = V_5 ;
if ( F_45 ( V_74 , & V_73 ) != 0 )
F_80 () ;
F_22 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_81 ( struct V_34 * V_60 )
{
F_78 ( V_60 ) ;
}
static void F_82 ( struct V_34 * V_60 )
{
F_74 ( V_60 ) ;
}
static int F_83 ( unsigned V_19 )
{
struct V_1 * V_3 ;
F_30 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
if ( V_3 -> V_13 . V_18 . V_19 == V_19 )
return V_3 -> V_2 ;
}
return - 1 ;
}
int F_84 ( unsigned V_19 )
{
return V_19 ;
}
int F_85 ( unsigned V_19 ,
unsigned V_18 , int V_75 , char * V_76 )
{
int V_2 = - 1 ;
struct V_77 V_78 ;
F_86 ( & V_79 ) ;
V_2 = F_83 ( V_19 ) ;
if ( V_2 != - 1 ) {
F_76 ( V_71 L_4 ,
V_2 , V_19 ) ;
goto V_67;
}
V_2 = F_60 ( V_19 ) ;
if ( V_2 < 0 )
goto V_67;
V_78 . V_2 = V_2 ;
V_78 . V_20 = 0 ;
if ( F_56 () &&
F_68 ( V_80 , & V_78 ) ) {
F_63 ( V_2 ) ;
V_2 = - V_81 ;
goto V_67;
}
F_9 ( V_2 , 0 , V_18 , V_19 , V_78 . V_20 , V_82 ,
V_75 ? V_68 : 0 ) ;
F_67 ( V_2 ) ;
if ( V_75 )
F_87 ( V_2 , & V_83 ,
V_84 , V_76 ) ;
else
F_87 ( V_2 , & V_83 ,
V_85 , V_76 ) ;
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
}
int F_89 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
int V_63 ;
struct V_90 V_91 ;
V_91 . type = V_92 ;
V_63 = F_68 ( V_93 , & V_91 ) ;
F_90 ( V_63 == - V_94 ,
L_5 ) ;
return V_63 ? - 1 : V_91 . V_18 ;
}
int F_91 ( struct V_86 * V_87 , struct V_88 * V_89 ,
int V_18 , int V_20 , const char * V_76 ,
T_3 V_21 )
{
int V_2 , V_25 ;
F_86 ( & V_79 ) ;
V_2 = F_54 () ;
if ( V_2 == - 1 )
goto V_67;
F_87 ( V_2 , & V_83 , V_85 ,
V_76 ) ;
F_9 ( V_2 , 0 , V_18 , 0 , V_20 , V_21 , 0 ) ;
V_25 = F_92 ( V_2 , V_89 ) ;
if ( V_25 < 0 )
goto V_95;
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
V_95:
F_88 ( & V_79 ) ;
F_63 ( V_2 ) ;
return - 1 ;
}
int F_93 ( int V_2 )
{
struct V_37 * V_38 ;
struct V_96 V_97 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_63 = - V_98 ;
F_86 ( & V_79 ) ;
V_38 = F_25 ( V_2 ) ;
if ( ! V_38 )
goto V_67;
if ( F_56 () ) {
V_97 . V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_97 . V_21 = V_3 -> V_13 . V_18 . V_21 ;
V_63 = F_68 ( V_99 , & V_97 ) ;
if ( ( V_63 == - V_100 && V_3 -> V_13 . V_18 . V_21 != V_82 ) )
F_76 ( V_71 L_6 ,
V_3 -> V_13 . V_18 . V_21 , V_3 -> V_13 . V_18 . V_18 ) ;
else if ( V_63 ) {
F_76 ( V_101 L_7 , V_63 ) ;
goto V_67;
}
}
F_63 ( V_2 ) ;
V_67:
F_88 ( & V_79 ) ;
return V_63 ;
}
int F_94 ( unsigned V_18 )
{
int V_2 ;
struct V_1 * V_3 ;
F_86 ( & V_79 ) ;
F_30 (info, &xen_irq_list_head, list) {
if ( V_3 == NULL || V_3 -> type != V_23 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_13 . V_18 . V_18 == V_18 )
goto V_67;
}
V_2 = - 1 ;
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
}
int F_95 ( unsigned V_2 )
{
return F_16 ( V_2 ) ;
}
int F_96 ( unsigned int V_5 )
{
int V_2 ;
F_86 ( & V_79 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 == - 1 )
goto V_67;
F_87 ( V_2 , & V_102 ,
V_85 , L_8 ) ;
F_5 ( V_2 , V_5 ) ;
}
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
}
static int F_97 ( unsigned int V_11 , unsigned int V_6 )
{
struct V_103 V_104 ;
int V_5 , V_2 ;
F_86 ( & V_79 ) ;
V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 < 0 )
goto V_67;
F_87 ( V_2 , & V_105 ,
V_106 , L_9 ) ;
V_104 . V_107 = V_6 ;
if ( F_45 ( V_108 ,
& V_104 ) != 0 )
F_80 () ;
V_5 = V_104 . V_39 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_22 ( V_5 , V_6 ) ;
}
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
}
static int F_98 ( unsigned int V_109 ,
unsigned int V_110 )
{
struct V_111 V_112 ;
int V_113 ;
V_112 . V_114 = V_109 ;
V_112 . V_110 = V_110 ;
V_113 = F_45 ( V_115 ,
& V_112 ) ;
return V_113 ? : F_96 ( V_112 . V_116 ) ;
}
int F_99 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_117 V_118 ;
int V_5 , V_2 ;
F_86 ( & V_79 ) ;
V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 == - 1 )
goto V_67;
F_87 ( V_2 , & V_105 ,
V_106 , L_10 ) ;
V_118 . V_15 = V_15 ;
V_118 . V_107 = V_6 ;
if ( F_45 ( V_119 ,
& V_118 ) != 0 )
F_80 () ;
V_5 = V_118 . V_39 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_22 ( V_5 , V_6 ) ;
}
V_67:
F_88 ( & V_79 ) ;
return V_2 ;
}
static void F_100 ( unsigned int V_2 )
{
struct V_72 V_73 ;
int V_5 = F_10 ( V_2 ) ;
F_86 ( & V_79 ) ;
if ( F_39 ( V_5 ) ) {
V_73 . V_39 = V_5 ;
if ( F_45 ( V_74 , & V_73 ) != 0 )
F_80 () ;
switch ( F_17 ( V_2 ) ) {
case V_16 :
F_7 ( V_17 , F_19 ( V_5 ) )
[ F_15 ( V_2 ) ] = - 1 ;
break;
case V_12 :
F_7 ( V_14 , F_19 ( V_5 ) )
[ F_14 ( V_2 ) ] = - 1 ;
break;
default:
break;
}
F_22 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
}
F_4 ( F_1 ( V_2 ) -> type == V_7 ) ;
F_63 ( V_2 ) ;
F_88 ( & V_79 ) ;
}
int F_101 ( unsigned int V_5 ,
T_4 V_120 ,
unsigned long V_121 ,
const char * V_122 , void * V_123 )
{
int V_2 , V_124 ;
V_2 = F_96 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_124 = F_102 ( V_2 , V_120 , V_121 , V_122 , V_123 ) ;
if ( V_124 != 0 ) {
F_100 ( V_2 ) ;
return V_124 ;
}
return V_2 ;
}
int F_103 ( unsigned int V_109 ,
unsigned int V_110 ,
T_4 V_120 ,
unsigned long V_121 ,
const char * V_122 ,
void * V_123 )
{
int V_2 , V_124 ;
V_2 = F_98 ( V_109 , V_110 ) ;
if ( V_2 < 0 )
return V_2 ;
V_124 = F_102 ( V_2 , V_120 , V_121 , V_122 , V_123 ) ;
if ( V_124 != 0 ) {
F_100 ( V_2 ) ;
return V_124 ;
}
return V_2 ;
}
int F_104 ( unsigned int V_15 , unsigned int V_6 ,
T_4 V_120 ,
unsigned long V_121 , const char * V_122 , void * V_123 )
{
int V_2 , V_124 ;
V_2 = F_99 ( V_15 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_124 = F_102 ( V_2 , V_120 , V_121 , V_122 , V_123 ) ;
if ( V_124 != 0 ) {
F_100 ( V_2 ) ;
return V_124 ;
}
return V_2 ;
}
int F_105 ( enum V_10 V_11 ,
unsigned int V_6 ,
T_4 V_120 ,
unsigned long V_121 ,
const char * V_122 ,
void * V_123 )
{
int V_2 , V_124 ;
V_2 = F_97 ( V_11 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_121 |= V_125 | V_126 ;
V_124 = F_102 ( V_2 , V_120 , V_121 , V_122 , V_123 ) ;
if ( V_124 != 0 ) {
F_100 ( V_2 ) ;
return V_124 ;
}
return V_2 ;
}
void F_106 ( unsigned int V_2 , void * V_123 )
{
F_107 ( V_2 , V_123 ) ;
F_100 ( V_2 ) ;
}
void F_108 ( unsigned int V_6 , enum V_10 V_20 )
{
int V_2 = F_7 ( V_14 , V_6 ) [ V_20 ] ;
F_4 ( V_2 < 0 ) ;
F_38 ( V_2 ) ;
}
T_5 F_109 ( int V_2 , void * V_123 )
{
struct V_27 * V_28 = V_41 ;
int V_6 = F_110 () ;
unsigned long * V_127 = F_7 ( V_31 , V_6 ) ;
int V_36 ;
unsigned long V_22 ;
static F_111 ( V_128 ) ;
struct V_45 * V_129 ;
F_112 ( & V_128 , V_22 ) ;
F_76 ( L_11 , V_6 ) ;
F_113 (i) {
int V_130 ;
V_129 = F_7 ( V_46 , V_36 ) ;
V_130 = ( F_114 () && V_36 == V_6 )
? F_115 ( F_114 () )
: V_129 -> V_131 ;
F_76 ( L_12 , V_36 ,
V_130 , V_129 -> V_49 ,
( int ) ( sizeof( V_129 -> V_48 ) * 2 ) ,
V_129 -> V_48 ) ;
}
V_129 = F_7 ( V_46 , V_6 ) ;
F_76 ( L_13 ) ;
for ( V_36 = F_116 ( V_28 -> V_30 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) sizeof( V_28 -> V_30 [ 0 ] ) * 2 ,
V_28 -> V_30 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_17 ) ;
for ( V_36 = F_116 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 ,
( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_28 -> V_32 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_18 ) ;
for ( V_36 = F_116 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_28 -> V_30 [ V_36 ] & ~ V_28 -> V_32 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_19 , V_6 ) ;
for ( V_36 = ( V_132 / V_47 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) ( sizeof( V_127 [ 0 ] ) * 2 ) ,
V_127 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_20 ) ;
for ( V_36 = F_116 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- ) {
unsigned long V_130 = V_28 -> V_30 [ V_36 ]
& ~ V_28 -> V_32 [ V_36 ]
& V_127 [ V_36 ] ;
F_76 ( L_14 , ( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_130 , V_36 % 8 == 0 ? L_15 : L_16 ) ;
}
F_76 ( L_21 ) ;
for ( V_36 = 0 ; V_36 < V_132 ; V_36 ++ ) {
if ( F_37 ( V_36 , V_28 -> V_30 ) ) {
int V_133 = V_36 / V_47 ;
F_76 ( L_22 ,
F_19 ( V_36 ) , V_36 ,
V_8 [ V_36 ] ,
F_37 ( V_133 , & V_129 -> V_48 )
? L_23 : L_24 ,
! F_37 ( V_36 , V_28 -> V_32 )
? L_23 : L_25 ,
F_37 ( V_36 , V_127 )
? L_23 : L_26 ) ;
}
}
F_117 ( & V_128 , V_22 ) ;
return V_134 ;
}
static void F_118 ( void )
{
int V_135 , V_136 ;
int V_133 , V_137 ;
int V_36 ;
int V_6 = F_43 () ;
struct V_27 * V_40 = V_41 ;
struct V_45 * V_45 = F_46 ( V_46 ) ;
unsigned V_138 ;
do {
unsigned long V_139 ;
V_45 -> V_49 = 0 ;
if ( F_119 ( V_140 ) - 1 )
goto V_67;
#ifndef F_120
F_121 () ;
#endif
V_139 = F_122 ( & V_45 -> V_48 , 0 ) ;
V_135 = F_46 ( V_141 ) ;
V_136 = F_46 ( V_142 ) ;
V_133 = V_135 ;
for ( V_36 = 0 ; V_139 != 0 ; V_36 ++ ) {
unsigned long V_143 ;
unsigned long V_144 ;
V_144 = F_123 ( V_139 , V_133 ) ;
if ( V_144 == 0 ) {
V_133 = 0 ;
V_137 = 0 ;
continue;
}
V_133 = F_124 ( V_144 ) ;
V_143 = F_21 ( V_6 , V_40 , V_133 ) ;
V_137 = 0 ;
if ( V_133 == V_135 ) {
if ( V_36 == 0 )
V_137 = V_136 ;
else
V_137 &= ( 1UL << V_136 ) - 1 ;
}
do {
unsigned long V_145 ;
int V_39 , V_2 ;
struct V_37 * V_38 ;
V_145 = F_123 ( V_143 , V_137 ) ;
if ( V_145 == 0 )
break;
V_137 = F_124 ( V_145 ) ;
V_39 = ( V_133 * V_47 ) + V_137 ;
V_2 = V_8 [ V_39 ] ;
if ( V_2 != - 1 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 )
F_125 ( V_2 , V_38 ) ;
}
V_137 = ( V_137 + 1 ) % V_47 ;
F_126 ( V_141 ,
V_137 ? V_133 :
( V_133 + 1 ) % V_47 ) ;
F_126 ( V_142 , V_137 ) ;
} while ( V_137 != 0 );
if ( ( V_133 != V_135 ) || ( V_36 != 0 ) )
V_139 &= ~ ( 1UL << V_133 ) ;
V_133 = ( V_133 + 1 ) % V_47 ;
}
F_4 ( ! F_44 () ) ;
V_138 = F_46 ( V_140 ) ;
F_126 ( V_140 , 0 ) ;
} while ( V_138 != 1 || V_45 -> V_49 );
V_67:
F_48 () ;
}
void F_127 ( struct V_146 * V_147 )
{
struct V_146 * V_148 = F_128 ( V_147 ) ;
F_129 () ;
F_130 () ;
F_118 () ;
F_131 () ;
F_128 ( V_148 ) ;
}
void F_132 ( void )
{
F_118 () ;
}
void F_133 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_134 ( V_2 ) ;
F_86 ( & V_79 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_5 ( V_2 , V_5 ) ;
F_88 ( & V_79 ) ;
F_135 ( V_2 , F_26 ( 0 ) ) ;
F_136 ( V_2 ) ;
}
static int F_137 ( unsigned V_2 , unsigned V_149 )
{
struct V_150 V_151 ;
int V_5 = F_10 ( V_2 ) ;
if ( ! F_39 ( V_5 ) )
return - 1 ;
if ( F_57 () && ! V_152 )
return - 1 ;
V_151 . V_39 = V_5 ;
V_151 . V_107 = V_149 ;
if ( F_45 ( V_153 , & V_151 ) >= 0 )
F_22 ( V_5 , V_149 ) ;
return 0 ;
}
static int F_138 ( struct V_34 * V_60 , const struct V_154 * V_155 ,
bool V_156 )
{
unsigned V_149 = F_139 ( V_155 ) ;
return F_137 ( V_60 -> V_2 , V_149 ) ;
}
int F_140 ( unsigned int V_2 )
{
int V_157 , V_5 = F_10 ( V_2 ) ;
struct V_27 * V_40 = V_41 ;
if ( ! F_39 ( V_5 ) )
return 1 ;
V_157 = F_47 ( V_5 , V_40 -> V_32 ) ;
F_35 ( V_5 , V_40 -> V_30 ) ;
if ( ! V_157 )
F_42 ( V_5 ) ;
return 1 ;
}
static void F_141 ( struct V_34 * V_60 )
{
int V_5 = F_10 ( V_60 -> V_2 ) ;
if ( F_39 ( V_5 ) )
F_42 ( V_5 ) ;
}
static void F_74 ( struct V_34 * V_60 )
{
int V_5 = F_10 ( V_60 -> V_2 ) ;
if ( F_39 ( V_5 ) )
F_41 ( V_5 ) ;
}
static void F_142 ( struct V_34 * V_60 )
{
int V_5 = F_10 ( V_60 -> V_2 ) ;
F_71 ( V_60 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
}
static void F_143 ( struct V_34 * V_60 )
{
F_74 ( V_60 ) ;
F_142 ( V_60 ) ;
}
static int F_144 ( struct V_34 * V_60 )
{
int V_5 = F_10 ( V_60 -> V_2 ) ;
struct V_27 * V_28 = V_41 ;
int V_25 = 0 ;
if ( F_39 ( V_5 ) ) {
int V_157 ;
V_157 = F_47 ( V_5 , V_28 -> V_32 ) ;
F_35 ( V_5 , V_28 -> V_30 ) ;
if ( ! V_157 )
F_42 ( V_5 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_145 ( void )
{
int V_18 , V_63 , V_2 , V_19 ;
struct V_158 V_159 ;
struct V_1 * V_3 ;
F_30 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_19 = V_3 -> V_13 . V_18 . V_19 ;
V_2 = V_3 -> V_2 ;
if ( ! V_19 )
continue;
V_159 . V_21 = V_82 ;
V_159 . type = V_160 ;
V_159 . V_161 = V_19 ;
V_159 . V_18 = V_18 ;
V_63 = F_68 ( V_162 , & V_159 ) ;
if ( V_63 ) {
F_76 ( V_101 L_27 ,
V_19 , V_2 , V_18 , V_63 ) ;
F_63 ( V_2 ) ;
continue;
}
F_76 ( V_163 L_28 , V_2 , V_159 . V_18 ) ;
F_75 ( V_2 ) ;
}
}
static void F_146 ( unsigned int V_6 )
{
struct V_117 V_118 ;
int V_15 , V_2 , V_5 ;
for ( V_15 = 0 ; V_15 < V_164 ; V_15 ++ ) {
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_15 ) ;
V_118 . V_15 = V_15 ;
V_118 . V_107 = V_6 ;
if ( F_45 ( V_119 ,
& V_118 ) != 0 )
F_80 () ;
V_5 = V_118 . V_39 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_22 ( V_5 , V_6 ) ;
}
}
static void F_147 ( unsigned int V_6 )
{
struct V_103 V_104 ;
int V_11 , V_2 , V_5 ;
for ( V_11 = 0 ; V_11 < V_165 ; V_11 ++ ) {
if ( ( V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ) == - 1 )
continue;
F_4 ( F_14 ( V_2 ) != V_11 ) ;
V_104 . V_107 = V_6 ;
if ( F_45 ( V_108 ,
& V_104 ) != 0 )
F_80 () ;
V_5 = V_104 . V_39 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_22 ( V_5 , V_6 ) ;
}
}
void F_148 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
}
void F_149 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) )
F_34 ( V_5 ) ;
}
bool F_150 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
bool V_25 = false ;
if ( F_39 ( V_5 ) )
V_25 = F_36 ( V_5 ) ;
return V_25 ;
}
void F_151 ( int V_2 , T_6 V_166 )
{
T_7 V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) ) {
struct V_167 V_168 ;
V_168 . V_169 = 1 ;
V_168 . V_166 = V_166 ;
F_152 ( V_168 . V_170 , & V_5 ) ;
if ( F_153 ( V_171 , & V_168 ) != 0 )
F_80 () ;
}
}
void F_154 ( int V_2 )
{
F_151 ( V_2 , 0 ) ;
}
int F_155 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_55 V_56 = { . V_2 = V_3 -> V_13 . V_18 . V_18 } ;
if ( F_68 ( V_57 , & V_56 ) )
return 0 ;
return ! ( V_56 . V_22 & V_172 ) ;
}
void F_156 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_29 () ;
for ( V_5 = 0 ; V_5 < V_132 ; V_5 ++ )
F_41 ( V_5 ) ;
F_30 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_132 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_31 (cpu) {
F_146 ( V_6 ) ;
F_147 ( V_6 ) ;
}
F_145 () ;
}
int F_157 ( T_8 V_173 )
{
struct V_174 V_175 ;
V_175 . V_21 = V_82 ;
V_175 . V_161 = V_176 ;
V_175 . V_177 = V_173 ;
return F_158 ( V_178 , & V_175 ) ;
}
void F_159 ( void )
{
int V_63 ;
T_8 V_179 ;
if ( V_152 ) {
V_179 = F_160 ( V_180 ) ;
V_63 = F_157 ( V_179 ) ;
if ( V_63 ) {
F_76 ( V_181 L_29
L_30 ) ;
V_152 = 0 ;
return;
}
F_76 ( V_71 L_31
L_32 ) ;
if ( ! F_161 ( V_180 , V_182 ) )
F_162 ( V_180 , V_183 ) ;
}
}
void F_159 ( void ) {}
void T_9 F_163 ( void )
{
int V_36 ;
V_8 = F_164 ( V_132 , sizeof( * V_8 ) ,
V_50 ) ;
for ( V_36 = 0 ; V_36 < V_132 ; V_36 ++ )
V_8 [ V_36 ] = - 1 ;
F_29 () ;
for ( V_36 = 0 ; V_36 < V_132 ; V_36 ++ )
F_41 ( V_36 ) ;
if ( F_57 () ) {
F_159 () ;
F_165 () ;
F_166 () ;
} else {
F_167 ( F_110 () ) ;
if ( F_56 () )
F_168 () ;
}
}
