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
return V_28 -> V_30 [ V_29 ] &
F_7 ( V_31 , V_6 ) [ V_29 ] &
~ V_28 -> V_32 [ V_29 ] ;
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
V_3 -> V_51 = - 1 ;
F_52 ( V_2 , V_3 ) ;
F_53 ( & V_3 -> V_52 , & V_53 ) ;
}
static int T_2 F_54 ( void )
{
int V_54 = 0 ;
int V_2 ;
#ifdef F_55
if ( F_56 () || F_57 () )
V_54 = F_58 () ;
#endif
V_2 = F_59 ( V_54 , - 1 ) ;
if ( V_2 >= 0 )
F_49 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_60 ( unsigned V_19 )
{
int V_2 ;
if ( F_61 () && ! F_56 () )
return F_54 () ;
if ( V_19 < V_55 )
V_2 = V_19 ;
else
V_2 = F_62 ( V_19 , - 1 ) ;
F_49 ( V_2 ) ;
return V_2 ;
}
static void F_63 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_64 ( & V_3 -> V_52 ) ;
F_52 ( V_2 , NULL ) ;
F_65 ( V_3 -> V_51 > 0 ) ;
F_66 ( V_3 ) ;
if ( V_2 < V_55 )
return;
F_67 ( V_2 ) ;
}
static void F_68 ( int V_2 )
{
struct V_56 V_57 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
V_57 . V_2 = F_16 ( V_2 ) ;
if ( F_69 ( V_58 , & V_57 ) )
V_57 . V_22 = 0 ;
V_3 -> V_13 . V_18 . V_22 &= ~ V_26 ;
if ( V_57 . V_22 & V_59 )
V_3 -> V_13 . V_18 . V_22 |= V_26 ;
}
static bool F_70 ( int V_2 )
{
struct V_37 * V_38 = F_25 ( V_2 ) ;
return V_38 && V_38 -> V_60 == NULL ;
}
static void F_71 ( struct V_34 * V_61 )
{
int V_5 = F_10 ( V_61 -> V_2 ) ;
struct V_62 V_63 = { . V_2 = F_16 (data->irq) } ;
int V_64 = 0 ;
F_72 ( V_61 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
if ( F_20 ( V_61 -> V_2 ) ) {
V_64 = F_69 ( V_65 , & V_63 ) ;
F_65 ( V_64 ) ;
}
}
static void F_73 ( struct V_34 * V_61 )
{
F_74 ( V_61 ) ;
F_71 ( V_61 ) ;
}
static unsigned int F_75 ( unsigned int V_2 )
{
struct V_66 V_67 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
int V_64 ;
F_4 ( V_3 -> type != V_23 ) ;
if ( F_39 ( V_5 ) )
goto V_68;
V_67 . V_18 = F_16 ( V_2 ) ;
V_67 . V_22 = V_3 -> V_13 . V_18 . V_22 & V_69 ?
V_70 : 0 ;
V_64 = F_45 ( V_71 , & V_67 ) ;
if ( V_64 != 0 ) {
if ( ! F_70 ( V_2 ) )
F_76 ( V_72 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_67 . V_39 ;
F_68 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_22 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_68:
F_42 ( V_5 ) ;
F_71 ( F_77 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_78 ( struct V_34 * V_61 )
{
return F_75 ( V_61 -> V_2 ) ;
}
static void F_79 ( struct V_34 * V_61 )
{
struct V_73 V_74 ;
unsigned int V_2 = V_61 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
if ( ! F_39 ( V_5 ) )
return;
F_41 ( V_5 ) ;
V_74 . V_39 = V_5 ;
if ( F_45 ( V_75 , & V_74 ) != 0 )
F_80 () ;
F_22 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_81 ( struct V_34 * V_61 )
{
F_78 ( V_61 ) ;
}
static void F_82 ( struct V_34 * V_61 )
{
F_74 ( V_61 ) ;
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
int F_84 ( unsigned V_19 ,
unsigned V_18 , int V_76 , char * V_77 )
{
int V_2 = - 1 ;
struct V_78 V_79 ;
F_85 ( & V_80 ) ;
V_2 = F_83 ( V_19 ) ;
if ( V_2 != - 1 ) {
F_76 ( V_72 L_4 ,
V_2 , V_19 ) ;
goto V_68;
}
V_2 = F_60 ( V_19 ) ;
if ( V_2 < 0 )
goto V_68;
V_79 . V_2 = V_2 ;
V_79 . V_20 = 0 ;
if ( F_56 () &&
F_69 ( V_81 , & V_79 ) ) {
F_63 ( V_2 ) ;
V_2 = - V_82 ;
goto V_68;
}
F_9 ( V_2 , 0 , V_18 , V_19 , V_79 . V_20 , V_83 ,
V_76 ? V_69 : 0 ) ;
F_68 ( V_2 ) ;
if ( V_76 )
F_86 ( V_2 , & V_84 ,
V_85 , V_77 ) ;
else
F_86 ( V_2 , & V_84 ,
V_86 , V_77 ) ;
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
}
int F_88 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
int V_64 ;
struct V_91 V_92 ;
V_92 . type = V_93 ;
V_64 = F_69 ( V_94 , & V_92 ) ;
F_89 ( V_64 == - V_95 ,
L_5 ) ;
return V_64 ? - 1 : V_92 . V_18 ;
}
int F_90 ( struct V_87 * V_88 , struct V_89 * V_90 ,
int V_18 , int V_20 , const char * V_77 ,
T_3 V_21 )
{
int V_2 , V_25 ;
F_85 ( & V_80 ) ;
V_2 = F_54 () ;
if ( V_2 < 0 )
goto V_68;
F_86 ( V_2 , & V_84 , V_86 ,
V_77 ) ;
F_9 ( V_2 , 0 , V_18 , 0 , V_20 , V_21 , 0 ) ;
V_25 = F_91 ( V_2 , V_90 ) ;
if ( V_25 < 0 )
goto V_96;
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
V_96:
F_87 ( & V_80 ) ;
F_63 ( V_2 ) ;
return V_25 ;
}
int F_92 ( int V_2 )
{
struct V_37 * V_38 ;
struct V_97 V_98 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_64 = - V_99 ;
F_85 ( & V_80 ) ;
V_38 = F_25 ( V_2 ) ;
if ( ! V_38 )
goto V_68;
if ( F_56 () ) {
V_98 . V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_98 . V_21 = V_3 -> V_13 . V_18 . V_21 ;
V_64 = F_69 ( V_100 , & V_98 ) ;
if ( ( V_64 == - V_101 && V_3 -> V_13 . V_18 . V_21 != V_83 ) )
F_76 ( V_72 L_6 ,
V_3 -> V_13 . V_18 . V_21 , V_3 -> V_13 . V_18 . V_18 ) ;
else if ( V_64 ) {
F_76 ( V_102 L_7 , V_64 ) ;
goto V_68;
}
}
F_63 ( V_2 ) ;
V_68:
F_87 ( & V_80 ) ;
return V_64 ;
}
int F_93 ( unsigned V_18 )
{
int V_2 ;
struct V_1 * V_3 ;
F_85 ( & V_80 ) ;
F_30 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_13 . V_18 . V_18 == V_18 )
goto V_68;
}
V_2 = - 1 ;
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
}
int F_94 ( unsigned V_2 )
{
return F_16 ( V_2 ) ;
}
int F_95 ( unsigned int V_5 )
{
int V_2 ;
F_85 ( & V_80 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 == - 1 )
goto V_68;
F_86 ( V_2 , & V_103 ,
V_86 , L_8 ) ;
F_5 ( V_2 , V_5 ) ;
}
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
}
static int F_96 ( unsigned int V_11 , unsigned int V_6 )
{
struct V_104 V_105 ;
int V_5 , V_2 ;
F_85 ( & V_80 ) ;
V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 < 0 )
goto V_68;
F_86 ( V_2 , & V_106 ,
V_107 , L_9 ) ;
V_105 . V_108 = V_6 ;
if ( F_45 ( V_109 ,
& V_105 ) != 0 )
F_80 () ;
V_5 = V_105 . V_39 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_22 ( V_5 , V_6 ) ;
}
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
}
static int F_97 ( unsigned int V_110 ,
unsigned int V_111 )
{
struct V_112 V_113 ;
int V_114 ;
V_113 . V_115 = V_110 ;
V_113 . V_111 = V_111 ;
V_114 = F_45 ( V_116 ,
& V_113 ) ;
return V_114 ? : F_95 ( V_113 . V_117 ) ;
}
static int F_98 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_118 V_119 ;
int V_39 , V_64 = - V_99 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
for ( V_39 = 0 ; V_39 <= V_120 ; V_39 ++ ) {
V_119 . V_121 = V_83 ;
V_119 . V_39 = V_39 ;
V_64 = F_45 ( V_122 , & V_119 ) ;
if ( V_64 < 0 )
continue;
if ( V_119 . V_119 != V_123 )
continue;
if ( V_119 . V_13 . V_15 == V_15 && V_119 . V_108 == V_6 ) {
V_64 = V_39 ;
break;
}
}
return V_64 ;
}
int F_99 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_124 V_125 ;
int V_5 , V_2 , V_25 ;
F_85 ( & V_80 ) ;
V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ;
if ( V_2 == - 1 ) {
V_2 = F_54 () ;
if ( V_2 == - 1 )
goto V_68;
F_86 ( V_2 , & V_106 ,
V_107 , L_10 ) ;
V_125 . V_15 = V_15 ;
V_125 . V_108 = V_6 ;
V_25 = F_45 ( V_126 ,
& V_125 ) ;
if ( V_25 == 0 )
V_5 = V_125 . V_39 ;
else {
if ( V_25 == - V_127 )
V_25 = F_98 ( V_15 , V_6 ) ;
F_4 ( V_25 < 0 ) ;
V_5 = V_25 ;
}
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_22 ( V_5 , V_6 ) ;
}
V_68:
F_87 ( & V_80 ) ;
return V_2 ;
}
static void F_100 ( unsigned int V_2 )
{
struct V_73 V_74 ;
int V_5 = F_10 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_85 ( & V_80 ) ;
if ( V_3 -> V_51 > 0 ) {
V_3 -> V_51 -- ;
if ( V_3 -> V_51 != 0 )
goto V_128;
}
if ( F_39 ( V_5 ) ) {
V_74 . V_39 = V_5 ;
if ( F_45 ( V_75 , & V_74 ) != 0 )
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
V_128:
F_87 ( & V_80 ) ;
}
int F_101 ( unsigned int V_5 ,
T_4 V_129 ,
unsigned long V_130 ,
const char * V_131 , void * V_132 )
{
int V_2 , V_133 ;
V_2 = F_95 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_133 = F_102 ( V_2 , V_129 , V_130 , V_131 , V_132 ) ;
if ( V_133 != 0 ) {
F_100 ( V_2 ) ;
return V_133 ;
}
return V_2 ;
}
int F_103 ( unsigned int V_110 ,
unsigned int V_111 ,
T_4 V_129 ,
unsigned long V_130 ,
const char * V_131 ,
void * V_132 )
{
int V_2 , V_133 ;
V_2 = F_97 ( V_110 , V_111 ) ;
if ( V_2 < 0 )
return V_2 ;
V_133 = F_102 ( V_2 , V_129 , V_130 , V_131 , V_132 ) ;
if ( V_133 != 0 ) {
F_100 ( V_2 ) ;
return V_133 ;
}
return V_2 ;
}
int F_104 ( unsigned int V_15 , unsigned int V_6 ,
T_4 V_129 ,
unsigned long V_130 , const char * V_131 , void * V_132 )
{
int V_2 , V_133 ;
V_2 = F_99 ( V_15 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_133 = F_102 ( V_2 , V_129 , V_130 , V_131 , V_132 ) ;
if ( V_133 != 0 ) {
F_100 ( V_2 ) ;
return V_133 ;
}
return V_2 ;
}
int F_105 ( enum V_10 V_11 ,
unsigned int V_6 ,
T_4 V_129 ,
unsigned long V_130 ,
const char * V_131 ,
void * V_132 )
{
int V_2 , V_133 ;
V_2 = F_96 ( V_11 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_130 |= V_134 | V_135 | V_136 ;
V_133 = F_102 ( V_2 , V_129 , V_130 , V_131 , V_132 ) ;
if ( V_133 != 0 ) {
F_100 ( V_2 ) ;
return V_133 ;
}
return V_2 ;
}
void F_106 ( unsigned int V_2 , void * V_132 )
{
F_107 ( V_2 , V_132 ) ;
F_100 ( V_2 ) ;
}
int F_108 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_99 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_99 ;
F_65 ( V_3 -> V_51 != - 1 ) ;
V_3 -> V_51 = 1 ;
return 0 ;
}
int F_109 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_114 = - V_99 ;
if ( V_5 >= V_120 )
return - V_137 ;
F_85 ( & V_80 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 )
goto V_128;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
goto V_128;
V_114 = - V_137 ;
if ( V_3 -> V_51 <= 0 )
goto V_128;
V_3 -> V_51 ++ ;
V_114 = 0 ;
V_128:
F_87 ( & V_80 ) ;
return V_114 ;
}
void F_110 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_65 ( V_2 == - 1 ) )
return;
F_100 ( V_2 ) ;
}
void F_111 ( unsigned int V_6 , enum V_10 V_20 )
{
int V_2 = F_7 ( V_14 , V_6 ) [ V_20 ] ;
F_4 ( V_2 < 0 ) ;
F_38 ( V_2 ) ;
}
T_5 F_112 ( int V_2 , void * V_132 )
{
struct V_27 * V_28 = V_41 ;
int V_6 = F_113 () ;
unsigned long * V_138 = F_7 ( V_31 , V_6 ) ;
int V_36 ;
unsigned long V_22 ;
static F_114 ( V_139 ) ;
struct V_45 * V_140 ;
F_115 ( & V_139 , V_22 ) ;
F_76 ( L_11 , V_6 ) ;
F_116 (i) {
int V_141 ;
V_140 = F_7 ( V_46 , V_36 ) ;
V_141 = ( F_117 () && V_36 == V_6 )
? F_118 ( F_117 () )
: V_140 -> V_142 ;
F_76 ( L_12 , V_36 ,
V_141 , V_140 -> V_49 ,
( int ) ( sizeof( V_140 -> V_48 ) * 2 ) ,
V_140 -> V_48 ) ;
}
V_140 = F_7 ( V_46 , V_6 ) ;
F_76 ( L_13 ) ;
for ( V_36 = F_119 ( V_28 -> V_30 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) sizeof( V_28 -> V_30 [ 0 ] ) * 2 ,
V_28 -> V_30 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_17 ) ;
for ( V_36 = F_119 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 ,
( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_28 -> V_32 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_18 ) ;
for ( V_36 = F_119 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_28 -> V_30 [ V_36 ] & ~ V_28 -> V_32 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_19 , V_6 ) ;
for ( V_36 = ( V_120 / V_47 ) - 1 ; V_36 >= 0 ; V_36 -- )
F_76 ( L_14 , ( int ) ( sizeof( V_138 [ 0 ] ) * 2 ) ,
V_138 [ V_36 ] ,
V_36 % 8 == 0 ? L_15 : L_16 ) ;
F_76 ( L_20 ) ;
for ( V_36 = F_119 ( V_28 -> V_32 ) - 1 ; V_36 >= 0 ; V_36 -- ) {
unsigned long V_141 = V_28 -> V_30 [ V_36 ]
& ~ V_28 -> V_32 [ V_36 ]
& V_138 [ V_36 ] ;
F_76 ( L_14 , ( int ) ( sizeof( V_28 -> V_32 [ 0 ] ) * 2 ) ,
V_141 , V_36 % 8 == 0 ? L_15 : L_16 ) ;
}
F_76 ( L_21 ) ;
for ( V_36 = 0 ; V_36 < V_120 ; V_36 ++ ) {
if ( F_37 ( V_36 , V_28 -> V_30 ) ) {
int V_143 = V_36 / V_47 ;
F_76 ( L_22 ,
F_19 ( V_36 ) , V_36 ,
V_8 [ V_36 ] ,
F_37 ( V_143 , & V_140 -> V_48 )
? L_23 : L_24 ,
! F_37 ( V_36 , V_28 -> V_32 )
? L_23 : L_25 ,
F_37 ( V_36 , V_138 )
? L_23 : L_26 ) ;
}
}
F_120 ( & V_139 , V_22 ) ;
return V_144 ;
}
static void F_121 ( void )
{
int V_145 , V_146 ;
int V_143 , V_147 ;
int V_36 ;
int V_6 = F_43 () ;
struct V_27 * V_40 = V_41 ;
struct V_45 * V_45 = F_46 ( V_46 ) ;
unsigned V_148 ;
do {
unsigned long V_149 ;
V_45 -> V_49 = 0 ;
if ( F_122 ( V_150 ) - 1 )
goto V_68;
#ifndef F_123
F_124 () ;
#endif
V_149 = F_125 ( & V_45 -> V_48 , 0 ) ;
V_145 = F_46 ( V_151 ) ;
V_146 = F_46 ( V_152 ) ;
V_143 = V_145 ;
for ( V_36 = 0 ; V_149 != 0 ; V_36 ++ ) {
unsigned long V_153 ;
unsigned long V_154 ;
V_154 = F_126 ( V_149 , V_143 ) ;
if ( V_154 == 0 ) {
V_143 = 0 ;
V_147 = 0 ;
continue;
}
V_143 = F_127 ( V_154 ) ;
V_153 = F_21 ( V_6 , V_40 , V_143 ) ;
V_147 = 0 ;
if ( V_143 == V_145 ) {
if ( V_36 == 0 )
V_147 = V_146 ;
else
V_147 &= ( 1UL << V_146 ) - 1 ;
}
do {
unsigned long V_155 ;
int V_39 , V_2 ;
struct V_37 * V_38 ;
V_155 = F_126 ( V_153 , V_147 ) ;
if ( V_155 == 0 )
break;
V_147 = F_127 ( V_155 ) ;
V_39 = ( V_143 * V_47 ) + V_147 ;
V_2 = V_8 [ V_39 ] ;
if ( V_2 != - 1 ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 )
F_128 ( V_2 , V_38 ) ;
}
V_147 = ( V_147 + 1 ) % V_47 ;
F_129 ( V_151 ,
V_147 ? V_143 :
( V_143 + 1 ) % V_47 ) ;
F_129 ( V_152 , V_147 ) ;
} while ( V_147 != 0 );
if ( ( V_143 != V_145 ) || ( V_36 != 0 ) )
V_149 &= ~ ( 1UL << V_143 ) ;
V_143 = ( V_143 + 1 ) % V_47 ;
}
F_4 ( ! F_44 () ) ;
V_148 = F_46 ( V_150 ) ;
F_129 ( V_150 , 0 ) ;
} while ( V_148 != 1 || V_45 -> V_49 );
V_68:
F_48 () ;
}
void F_130 ( struct V_156 * V_157 )
{
struct V_156 * V_158 = F_131 ( V_157 ) ;
F_132 () ;
F_133 () ;
F_121 () ;
F_134 () ;
F_131 ( V_158 ) ;
}
void F_135 ( void )
{
F_121 () ;
}
void F_136 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_137 ( V_2 ) ;
F_85 ( & V_80 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_5 ( V_2 , V_5 ) ;
F_87 ( & V_80 ) ;
F_138 ( V_2 , F_26 ( 0 ) ) ;
F_139 ( V_2 ) ;
}
static int F_140 ( unsigned V_2 , unsigned V_159 )
{
struct V_160 V_161 ;
int V_5 = F_10 ( V_2 ) ;
if ( ! F_39 ( V_5 ) )
return - 1 ;
if ( F_57 () && ! V_162 )
return - 1 ;
V_161 . V_39 = V_5 ;
V_161 . V_108 = V_159 ;
if ( F_45 ( V_163 , & V_161 ) >= 0 )
F_22 ( V_5 , V_159 ) ;
return 0 ;
}
static int F_141 ( struct V_34 * V_61 , const struct V_164 * V_165 ,
bool V_166 )
{
unsigned V_159 = F_142 ( V_165 ) ;
return F_140 ( V_61 -> V_2 , V_159 ) ;
}
int F_143 ( unsigned int V_2 )
{
int V_167 , V_5 = F_10 ( V_2 ) ;
struct V_27 * V_40 = V_41 ;
if ( ! F_39 ( V_5 ) )
return 1 ;
V_167 = F_47 ( V_5 , V_40 -> V_32 ) ;
F_35 ( V_5 , V_40 -> V_30 ) ;
if ( ! V_167 )
F_42 ( V_5 ) ;
return 1 ;
}
static void F_144 ( struct V_34 * V_61 )
{
int V_5 = F_10 ( V_61 -> V_2 ) ;
if ( F_39 ( V_5 ) )
F_42 ( V_5 ) ;
}
static void F_74 ( struct V_34 * V_61 )
{
int V_5 = F_10 ( V_61 -> V_2 ) ;
if ( F_39 ( V_5 ) )
F_41 ( V_5 ) ;
}
static void F_145 ( struct V_34 * V_61 )
{
int V_5 = F_10 ( V_61 -> V_2 ) ;
F_72 ( V_61 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
}
static void F_146 ( struct V_34 * V_61 )
{
F_74 ( V_61 ) ;
F_145 ( V_61 ) ;
}
static int F_147 ( struct V_34 * V_61 )
{
int V_5 = F_10 ( V_61 -> V_2 ) ;
struct V_27 * V_28 = V_41 ;
int V_25 = 0 ;
if ( F_39 ( V_5 ) ) {
int V_167 ;
V_167 = F_47 ( V_5 , V_28 -> V_32 ) ;
F_35 ( V_5 , V_28 -> V_30 ) ;
if ( ! V_167 )
F_42 ( V_5 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_148 ( void )
{
int V_18 , V_64 , V_2 , V_19 ;
struct V_168 V_169 ;
struct V_1 * V_3 ;
F_30 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_19 = V_3 -> V_13 . V_18 . V_19 ;
V_2 = V_3 -> V_2 ;
if ( ! V_19 )
continue;
V_169 . V_21 = V_83 ;
V_169 . type = V_170 ;
V_169 . V_171 = V_19 ;
V_169 . V_18 = V_18 ;
V_64 = F_69 ( V_172 , & V_169 ) ;
if ( V_64 ) {
F_76 ( V_102 L_27 ,
V_19 , V_2 , V_18 , V_64 ) ;
F_63 ( V_2 ) ;
continue;
}
F_76 ( V_173 L_28 , V_2 , V_169 . V_18 ) ;
F_75 ( V_2 ) ;
}
}
static void F_149 ( unsigned int V_6 )
{
struct V_124 V_125 ;
int V_15 , V_2 , V_5 ;
for ( V_15 = 0 ; V_15 < V_174 ; V_15 ++ ) {
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_15 ) ;
V_125 . V_15 = V_15 ;
V_125 . V_108 = V_6 ;
if ( F_45 ( V_126 ,
& V_125 ) != 0 )
F_80 () ;
V_5 = V_125 . V_39 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_22 ( V_5 , V_6 ) ;
}
}
static void F_150 ( unsigned int V_6 )
{
struct V_104 V_105 ;
int V_11 , V_2 , V_5 ;
for ( V_11 = 0 ; V_11 < V_175 ; V_11 ++ ) {
if ( ( V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ) == - 1 )
continue;
F_4 ( F_14 ( V_2 ) != V_11 ) ;
V_105 . V_108 = V_6 ;
if ( F_45 ( V_109 ,
& V_105 ) != 0 )
F_80 () ;
V_5 = V_105 . V_39 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_22 ( V_5 , V_6 ) ;
}
}
void F_151 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) )
F_32 ( V_5 ) ;
}
void F_152 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) )
F_34 ( V_5 ) ;
}
bool F_153 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
bool V_25 = false ;
if ( F_39 ( V_5 ) )
V_25 = F_36 ( V_5 ) ;
return V_25 ;
}
void F_154 ( int V_2 , T_6 V_176 )
{
T_7 V_5 = F_10 ( V_2 ) ;
if ( F_39 ( V_5 ) ) {
struct V_177 V_178 ;
V_178 . V_179 = 1 ;
V_178 . V_176 = V_176 ;
F_155 ( V_178 . V_180 , & V_5 ) ;
if ( F_156 ( V_181 , & V_178 ) != 0 )
F_80 () ;
}
}
void F_157 ( int V_2 )
{
F_154 ( V_2 , 0 ) ;
}
int F_158 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_56 V_57 = { . V_2 = V_3 -> V_13 . V_18 . V_18 } ;
if ( F_69 ( V_58 , & V_57 ) )
return 0 ;
return ! ( V_57 . V_22 & V_182 ) ;
}
void F_159 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_29 () ;
for ( V_5 = 0 ; V_5 < V_120 ; V_5 ++ )
F_41 ( V_5 ) ;
F_30 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_120 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_31 (cpu) {
F_149 ( V_6 ) ;
F_150 ( V_6 ) ;
}
F_148 () ;
}
int F_160 ( T_8 V_183 )
{
struct V_184 V_185 ;
V_185 . V_21 = V_83 ;
V_185 . V_171 = V_186 ;
V_185 . V_187 = V_183 ;
return F_161 ( V_188 , & V_185 ) ;
}
void F_162 ( void )
{
int V_64 ;
T_8 V_189 ;
if ( V_162 ) {
V_189 = F_163 ( V_190 ) ;
V_64 = F_160 ( V_189 ) ;
if ( V_64 ) {
F_76 ( V_191 L_29
L_30 ) ;
V_162 = 0 ;
return;
}
F_76 ( V_72 L_31
L_32 ) ;
if ( ! F_164 ( V_190 , V_192 ) )
F_165 ( V_190 , V_193 ) ;
}
}
void F_162 ( void ) {}
void T_9 F_166 ( void )
{
int V_36 ;
V_8 = F_167 ( V_120 , sizeof( * V_8 ) ,
V_50 ) ;
F_4 ( ! V_8 ) ;
for ( V_36 = 0 ; V_36 < V_120 ; V_36 ++ )
V_8 [ V_36 ] = - 1 ;
F_29 () ;
for ( V_36 = 0 ; V_36 < V_120 ; V_36 ++ )
F_41 ( V_36 ) ;
if ( F_57 () ) {
F_162 () ;
F_168 () ;
F_169 () ;
} else {
F_170 ( F_113 () ) ;
if ( F_56 () )
F_171 () ;
}
}
