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
return F_21 ( F_16 ( V_2 ) , V_26 ) ;
}
static bool F_22 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
return V_3 -> V_13 . V_18 . V_22 & V_27 ;
}
static inline unsigned long F_23 ( unsigned int V_6 ,
struct V_28 * V_29 ,
unsigned int V_30 )
{
return V_29 -> V_31 [ V_30 ] &
F_7 ( V_32 , V_6 ) [ V_30 ] &
~ V_29 -> V_33 [ V_30 ] ;
}
static void F_24 ( unsigned int V_34 , unsigned int V_6 )
{
int V_2 = V_8 [ V_34 ] ;
F_4 ( V_2 == - 1 ) ;
#ifdef F_25
F_26 ( F_27 ( V_2 ) -> V_35 . V_36 , F_28 ( V_6 ) ) ;
#endif
F_29 ( V_34 , F_7 ( V_32 , F_18 ( V_2 ) ) ) ;
F_30 ( V_34 , F_7 ( V_32 , V_6 ) ) ;
F_1 ( V_2 ) -> V_6 = V_6 ;
}
static void F_31 ( void )
{
int V_37 ;
#ifdef F_25
struct V_1 * V_3 ;
F_32 (info, &xen_irq_list_head, list) {
struct V_38 * V_39 = F_27 ( V_3 -> V_2 ) ;
F_26 ( V_39 -> V_35 . V_36 , F_28 ( 0 ) ) ;
}
#endif
F_33 (i)
memset ( F_7 ( V_32 , V_37 ) ,
( V_37 == 0 ) ? ~ 0 : 0 , sizeof( * F_7 ( V_32 , V_37 ) ) ) ;
}
static inline void F_34 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_35 ( V_40 , & V_41 -> V_31 [ 0 ] ) ;
}
static inline void F_36 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_37 ( V_40 , & V_41 -> V_31 [ 0 ] ) ;
}
static inline int F_38 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
return F_39 ( V_40 , & V_41 -> V_31 [ 0 ] ) ;
}
void F_40 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) )
F_42 ( V_5 ) ;
}
static void F_43 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_37 ( V_40 , & V_41 -> V_33 [ 0 ] ) ;
}
static void F_44 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
unsigned int V_6 = F_45 () ;
F_4 ( ! F_46 () ) ;
if ( F_11 ( V_6 != F_19 ( V_40 ) ) ) {
struct V_43 V_44 = { . V_40 = V_40 } ;
( void ) F_47 ( V_45 , & V_44 ) ;
} else {
struct V_46 * V_46 = F_48 ( V_47 ) ;
F_35 ( V_40 , & V_41 -> V_33 [ 0 ] ) ;
if ( F_39 ( V_40 , & V_41 -> V_31 [ 0 ] ) &&
! F_49 ( V_40 / V_48 ,
& V_46 -> V_49 ) )
V_46 -> V_50 = 1 ;
}
F_50 () ;
}
static void F_51 ( unsigned V_2 )
{
struct V_1 * V_3 ;
#ifdef F_25
struct V_38 * V_39 = F_27 ( V_2 ) ;
F_26 ( V_39 -> V_35 . V_36 , F_28 ( 0 ) ) ;
#endif
V_3 = F_52 ( sizeof( * V_3 ) , V_51 ) ;
if ( V_3 == NULL )
F_53 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
V_3 -> V_52 = - 1 ;
F_54 ( V_2 , V_3 ) ;
F_55 ( & V_3 -> V_53 , & V_54 ) ;
}
static int T_2 F_56 ( void )
{
int V_55 = 0 ;
int V_2 ;
#ifdef F_57
if ( F_58 () || F_59 () )
V_55 = F_60 () ;
#endif
V_2 = F_61 ( V_55 , - 1 ) ;
if ( V_2 >= 0 )
F_51 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_62 ( unsigned V_19 )
{
int V_2 ;
if ( F_63 () && ! F_58 () )
return F_56 () ;
if ( V_19 < V_56 )
V_2 = V_19 ;
else
V_2 = F_64 ( V_19 , - 1 ) ;
F_51 ( V_2 ) ;
return V_2 ;
}
static void F_65 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_66 ( & V_3 -> V_53 ) ;
F_54 ( V_2 , NULL ) ;
F_67 ( V_3 -> V_52 > 0 ) ;
F_68 ( V_3 ) ;
if ( V_2 < V_56 )
return;
F_69 ( V_2 ) ;
}
static void F_70 ( int V_2 )
{
struct V_57 V_58 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
V_58 . V_2 = F_16 ( V_2 ) ;
if ( F_71 ( V_59 , & V_58 ) )
V_58 . V_22 = 0 ;
V_3 -> V_13 . V_18 . V_22 &= ~ V_27 ;
if ( V_58 . V_22 & V_60 )
V_3 -> V_13 . V_18 . V_22 |= V_27 ;
}
static bool F_72 ( int V_2 )
{
struct V_38 * V_39 = F_27 ( V_2 ) ;
return V_39 && V_39 -> V_61 == NULL ;
}
static void F_73 ( struct V_35 * V_62 )
{
int V_5 = F_10 ( V_62 -> V_2 ) ;
struct V_63 V_64 = { . V_2 = F_16 (data->irq) } ;
int V_65 = 0 ;
F_74 ( V_62 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
if ( F_75 ( V_62 -> V_2 ) ) {
V_65 = F_71 ( V_66 , & V_64 ) ;
F_67 ( V_65 ) ;
}
}
static void F_76 ( struct V_35 * V_62 )
{
F_77 ( V_62 ) ;
F_73 ( V_62 ) ;
}
static unsigned int F_78 ( unsigned int V_2 )
{
struct V_67 V_68 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
int V_65 ;
F_4 ( V_3 -> type != V_23 ) ;
if ( F_41 ( V_5 ) )
goto V_69;
V_68 . V_18 = F_16 ( V_2 ) ;
V_68 . V_22 = V_3 -> V_13 . V_18 . V_22 & V_70 ?
V_71 : 0 ;
V_65 = F_47 ( V_72 , & V_68 ) ;
if ( V_65 != 0 ) {
if ( ! F_72 ( V_2 ) )
F_79 ( V_73 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_68 . V_40 ;
F_70 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_24 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_69:
F_44 ( V_5 ) ;
F_73 ( F_80 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_81 ( struct V_35 * V_62 )
{
return F_78 ( V_62 -> V_2 ) ;
}
static void F_82 ( struct V_35 * V_62 )
{
struct V_74 V_75 ;
unsigned int V_2 = V_62 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
if ( ! F_41 ( V_5 ) )
return;
F_43 ( V_5 ) ;
V_75 . V_40 = V_5 ;
if ( F_47 ( V_76 , & V_75 ) != 0 )
F_83 () ;
F_24 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_84 ( struct V_35 * V_62 )
{
F_81 ( V_62 ) ;
}
static void F_85 ( struct V_35 * V_62 )
{
F_77 ( V_62 ) ;
}
int F_86 ( unsigned V_19 )
{
struct V_1 * V_3 ;
F_32 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
if ( V_3 -> V_13 . V_18 . V_19 == V_19 )
return V_3 -> V_2 ;
}
return - 1 ;
}
int F_87 ( unsigned V_19 ,
unsigned V_18 , int V_77 , char * V_78 )
{
int V_2 = - 1 ;
struct V_79 V_80 ;
F_88 ( & V_81 ) ;
V_2 = F_86 ( V_19 ) ;
if ( V_2 != - 1 ) {
F_79 ( V_73 L_4 ,
V_2 , V_19 ) ;
goto V_69;
}
V_2 = F_62 ( V_19 ) ;
if ( V_2 < 0 )
goto V_69;
V_80 . V_2 = V_2 ;
V_80 . V_20 = 0 ;
if ( F_58 () &&
F_71 ( V_82 , & V_80 ) ) {
F_65 ( V_2 ) ;
V_2 = - V_83 ;
goto V_69;
}
F_9 ( V_2 , 0 , V_18 , V_19 , V_80 . V_20 , V_84 ,
V_77 ? V_70 : 0 ) ;
F_70 ( V_2 ) ;
if ( V_77 )
F_89 ( V_2 , & V_85 ,
V_86 , V_78 ) ;
else
F_89 ( V_2 , & V_85 ,
V_87 , V_78 ) ;
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
}
int F_91 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
int V_65 ;
struct V_92 V_93 ;
V_93 . type = V_94 ;
V_65 = F_71 ( V_95 , & V_93 ) ;
F_92 ( V_65 == - V_96 ,
L_5 ) ;
return V_65 ? - 1 : V_93 . V_18 ;
}
int F_93 ( struct V_88 * V_89 , struct V_90 * V_91 ,
int V_18 , int V_20 , const char * V_78 ,
T_3 V_21 )
{
int V_2 , V_25 ;
F_88 ( & V_81 ) ;
V_2 = F_56 () ;
if ( V_2 < 0 )
goto V_69;
F_89 ( V_2 , & V_85 , V_87 ,
V_78 ) ;
F_9 ( V_2 , 0 , V_18 , 0 , V_20 , V_21 , 0 ) ;
V_25 = F_94 ( V_2 , V_91 ) ;
if ( V_25 < 0 )
goto V_97;
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
V_97:
F_90 ( & V_81 ) ;
F_65 ( V_2 ) ;
return V_25 ;
}
int F_95 ( int V_2 )
{
struct V_38 * V_39 ;
struct V_98 V_99 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_65 = - V_100 ;
F_88 ( & V_81 ) ;
V_39 = F_27 ( V_2 ) ;
if ( ! V_39 )
goto V_69;
if ( F_58 () ) {
V_99 . V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_99 . V_21 = V_3 -> V_13 . V_18 . V_21 ;
V_65 = F_71 ( V_101 , & V_99 ) ;
if ( ( V_65 == - V_102 && V_3 -> V_13 . V_18 . V_21 != V_84 ) )
F_79 ( V_73 L_6 ,
V_3 -> V_13 . V_18 . V_21 , V_3 -> V_13 . V_18 . V_18 ) ;
else if ( V_65 ) {
F_79 ( V_103 L_7 , V_65 ) ;
goto V_69;
}
}
F_65 ( V_2 ) ;
V_69:
F_90 ( & V_81 ) ;
return V_65 ;
}
int F_96 ( unsigned V_18 )
{
int V_2 ;
struct V_1 * V_3 ;
F_88 ( & V_81 ) ;
F_32 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_13 . V_18 . V_18 == V_18 )
goto V_69;
}
V_2 = - 1 ;
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
}
int F_97 ( unsigned V_2 )
{
return F_16 ( V_2 ) ;
}
int F_98 ( unsigned int V_5 )
{
int V_2 ;
F_88 ( & V_81 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_56 () ;
if ( V_2 == - 1 )
goto V_69;
F_89 ( V_2 , & V_104 ,
V_87 , L_8 ) ;
F_5 ( V_2 , V_5 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_9 ) ;
}
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
}
static int F_99 ( unsigned int V_11 , unsigned int V_6 )
{
struct V_105 V_106 ;
int V_5 , V_2 ;
F_88 ( & V_81 ) ;
V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ;
if ( V_2 == - 1 ) {
V_2 = F_56 () ;
if ( V_2 < 0 )
goto V_69;
F_89 ( V_2 , & V_107 ,
V_108 , L_9 ) ;
V_106 . V_109 = V_6 ;
if ( F_47 ( V_110 ,
& V_106 ) != 0 )
F_83 () ;
V_5 = V_106 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_12 ) ;
}
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
}
static int F_100 ( unsigned int V_111 ,
unsigned int V_112 )
{
struct V_113 V_114 ;
int V_115 ;
V_114 . V_116 = V_111 ;
V_114 . V_112 = V_112 ;
V_115 = F_47 ( V_117 ,
& V_114 ) ;
return V_115 ? : F_98 ( V_114 . V_118 ) ;
}
static int F_101 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_119 V_120 ;
int V_40 , V_65 = - V_100 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
for ( V_40 = 0 ; V_40 <= V_121 ; V_40 ++ ) {
V_120 . V_122 = V_84 ;
V_120 . V_40 = V_40 ;
V_65 = F_47 ( V_123 , & V_120 ) ;
if ( V_65 < 0 )
continue;
if ( V_120 . V_120 != V_124 )
continue;
if ( V_120 . V_13 . V_15 == V_15 && V_120 . V_109 == V_6 ) {
V_65 = V_40 ;
break;
}
}
return V_65 ;
}
int F_102 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_125 V_126 ;
int V_5 , V_2 , V_25 ;
F_88 ( & V_81 ) ;
V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ;
if ( V_2 == - 1 ) {
V_2 = F_56 () ;
if ( V_2 == - 1 )
goto V_69;
F_89 ( V_2 , & V_107 ,
V_108 , L_10 ) ;
V_126 . V_15 = V_15 ;
V_126 . V_109 = V_6 ;
V_25 = F_47 ( V_127 ,
& V_126 ) ;
if ( V_25 == 0 )
V_5 = V_126 . V_40 ;
else {
if ( V_25 == - V_128 )
V_25 = F_101 ( V_15 , V_6 ) ;
F_4 ( V_25 < 0 ) ;
V_5 = V_25 ;
}
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_16 ) ;
}
V_69:
F_90 ( & V_81 ) ;
return V_2 ;
}
static void F_103 ( unsigned int V_2 )
{
struct V_74 V_75 ;
int V_5 = F_10 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_88 ( & V_81 ) ;
if ( V_3 -> V_52 > 0 ) {
V_3 -> V_52 -- ;
if ( V_3 -> V_52 != 0 )
goto V_129;
}
if ( F_41 ( V_5 ) ) {
V_75 . V_40 = V_5 ;
if ( F_47 ( V_76 , & V_75 ) != 0 )
F_83 () ;
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
F_24 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
}
F_4 ( F_1 ( V_2 ) -> type == V_7 ) ;
F_65 ( V_2 ) ;
V_129:
F_90 ( & V_81 ) ;
}
int F_104 ( unsigned int V_5 ,
T_4 V_130 ,
unsigned long V_131 ,
const char * V_132 , void * V_133 )
{
int V_2 , V_134 ;
V_2 = F_98 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_134 = F_105 ( V_2 , V_130 , V_131 , V_132 , V_133 ) ;
if ( V_134 != 0 ) {
F_103 ( V_2 ) ;
return V_134 ;
}
return V_2 ;
}
int F_106 ( unsigned int V_111 ,
unsigned int V_112 ,
T_4 V_130 ,
unsigned long V_131 ,
const char * V_132 ,
void * V_133 )
{
int V_2 , V_134 ;
V_2 = F_100 ( V_111 , V_112 ) ;
if ( V_2 < 0 )
return V_2 ;
V_134 = F_105 ( V_2 , V_130 , V_131 , V_132 , V_133 ) ;
if ( V_134 != 0 ) {
F_103 ( V_2 ) ;
return V_134 ;
}
return V_2 ;
}
int F_107 ( unsigned int V_15 , unsigned int V_6 ,
T_4 V_130 ,
unsigned long V_131 , const char * V_132 , void * V_133 )
{
int V_2 , V_134 ;
V_2 = F_102 ( V_15 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_134 = F_105 ( V_2 , V_130 , V_131 , V_132 , V_133 ) ;
if ( V_134 != 0 ) {
F_103 ( V_2 ) ;
return V_134 ;
}
return V_2 ;
}
int F_108 ( enum V_10 V_11 ,
unsigned int V_6 ,
T_4 V_130 ,
unsigned long V_131 ,
const char * V_132 ,
void * V_133 )
{
int V_2 , V_134 ;
V_2 = F_99 ( V_11 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_131 |= V_135 | V_136 | V_137 ;
V_134 = F_105 ( V_2 , V_130 , V_131 , V_132 , V_133 ) ;
if ( V_134 != 0 ) {
F_103 ( V_2 ) ;
return V_134 ;
}
return V_2 ;
}
void F_109 ( unsigned int V_2 , void * V_133 )
{
F_110 ( V_2 , V_133 ) ;
F_103 ( V_2 ) ;
}
int F_111 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_100 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_100 ;
F_67 ( V_3 -> V_52 != - 1 ) ;
V_3 -> V_52 = 1 ;
return 0 ;
}
int F_112 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_115 = - V_100 ;
if ( V_5 >= V_121 )
return - V_138 ;
F_88 ( & V_81 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 )
goto V_129;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
goto V_129;
V_115 = - V_138 ;
if ( V_3 -> V_52 <= 0 )
goto V_129;
V_3 -> V_52 ++ ;
V_115 = 0 ;
V_129:
F_90 ( & V_81 ) ;
return V_115 ;
}
void F_113 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_67 ( V_2 == - 1 ) )
return;
F_103 ( V_2 ) ;
}
void F_114 ( unsigned int V_6 , enum V_10 V_20 )
{
int V_2 = F_7 ( V_14 , V_6 ) [ V_20 ] ;
F_4 ( V_2 < 0 ) ;
F_40 ( V_2 ) ;
}
T_5 F_115 ( int V_2 , void * V_133 )
{
struct V_28 * V_29 = V_42 ;
int V_6 = F_116 () ;
unsigned long * V_139 = F_7 ( V_32 , V_6 ) ;
int V_37 ;
unsigned long V_22 ;
static F_117 ( V_140 ) ;
struct V_46 * V_141 ;
F_118 ( & V_140 , V_22 ) ;
F_79 ( L_11 , V_6 ) ;
F_119 (i) {
int V_142 ;
V_141 = F_7 ( V_47 , V_37 ) ;
V_142 = ( F_120 () && V_37 == V_6 )
? F_121 ( F_120 () )
: V_141 -> V_143 ;
F_79 ( L_12 , V_37 ,
V_142 , V_141 -> V_50 ,
( int ) ( sizeof( V_141 -> V_49 ) * 2 ) ,
V_141 -> V_49 ) ;
}
V_141 = F_7 ( V_47 , V_6 ) ;
F_79 ( L_13 ) ;
for ( V_37 = F_122 ( V_29 -> V_31 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) sizeof( V_29 -> V_31 [ 0 ] ) * 2 ,
V_29 -> V_31 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_17 ) ;
for ( V_37 = F_122 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 ,
( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_18 ) ;
for ( V_37 = F_122 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_31 [ V_37 ] & ~ V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_19 , V_6 ) ;
for ( V_37 = ( V_121 / V_48 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) ( sizeof( V_139 [ 0 ] ) * 2 ) ,
V_139 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_20 ) ;
for ( V_37 = F_122 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- ) {
unsigned long V_142 = V_29 -> V_31 [ V_37 ]
& ~ V_29 -> V_33 [ V_37 ]
& V_139 [ V_37 ] ;
F_79 ( L_14 , ( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_142 , V_37 % 8 == 0 ? L_15 : L_16 ) ;
}
F_79 ( L_21 ) ;
for ( V_37 = 0 ; V_37 < V_121 ; V_37 ++ ) {
if ( F_39 ( V_37 , V_29 -> V_31 ) ) {
int V_144 = V_37 / V_48 ;
F_79 ( L_22 ,
F_19 ( V_37 ) , V_37 ,
V_8 [ V_37 ] ,
F_39 ( V_144 , & V_141 -> V_49 )
? L_23 : L_24 ,
! F_39 ( V_37 , V_29 -> V_33 )
? L_23 : L_25 ,
F_39 ( V_37 , V_139 )
? L_23 : L_26 ) ;
}
}
F_123 ( & V_140 , V_22 ) ;
return V_145 ;
}
static void F_124 ( void )
{
int V_146 , V_147 ;
int V_144 , V_148 ;
int V_37 ;
int V_6 = F_45 () ;
struct V_28 * V_41 = V_42 ;
struct V_46 * V_46 = F_48 ( V_47 ) ;
unsigned V_149 ;
do {
unsigned long V_150 ;
V_46 -> V_50 = 0 ;
if ( F_125 ( V_151 ) - 1 )
goto V_69;
#ifndef F_126
F_127 () ;
#endif
V_150 = F_128 ( & V_46 -> V_49 , 0 ) ;
V_146 = F_48 ( V_152 ) ;
V_147 = F_48 ( V_153 ) ;
V_144 = V_146 ;
for ( V_37 = 0 ; V_150 != 0 ; V_37 ++ ) {
unsigned long V_154 ;
unsigned long V_155 ;
V_155 = F_129 ( V_150 , V_144 ) ;
if ( V_155 == 0 ) {
V_144 = 0 ;
V_148 = 0 ;
continue;
}
V_144 = F_130 ( V_155 ) ;
V_154 = F_23 ( V_6 , V_41 , V_144 ) ;
V_148 = 0 ;
if ( V_144 == V_146 ) {
if ( V_37 == 0 )
V_148 = V_147 ;
else
V_148 &= ( 1UL << V_147 ) - 1 ;
}
do {
unsigned long V_156 ;
int V_40 , V_2 ;
struct V_38 * V_39 ;
V_156 = F_129 ( V_154 , V_148 ) ;
if ( V_156 == 0 )
break;
V_148 = F_130 ( V_156 ) ;
V_40 = ( V_144 * V_48 ) + V_148 ;
V_2 = V_8 [ V_40 ] ;
if ( V_2 != - 1 ) {
V_39 = F_27 ( V_2 ) ;
if ( V_39 )
F_131 ( V_2 , V_39 ) ;
}
V_148 = ( V_148 + 1 ) % V_48 ;
F_132 ( V_152 ,
V_148 ? V_144 :
( V_144 + 1 ) % V_48 ) ;
F_132 ( V_153 , V_148 ) ;
} while ( V_148 != 0 );
if ( ( V_144 != V_146 ) || ( V_37 != 0 ) )
V_150 &= ~ ( 1UL << V_144 ) ;
V_144 = ( V_144 + 1 ) % V_48 ;
}
F_4 ( ! F_46 () ) ;
V_149 = F_48 ( V_151 ) ;
F_132 ( V_151 , 0 ) ;
} while ( V_149 != 1 || V_46 -> V_50 );
V_69:
F_50 () ;
}
void F_133 ( struct V_157 * V_158 )
{
struct V_157 * V_159 = F_134 ( V_158 ) ;
F_135 () ;
F_136 () ;
F_124 () ;
F_137 () ;
F_134 ( V_159 ) ;
}
void F_138 ( void )
{
F_124 () ;
}
void F_139 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_140 ( V_2 ) ;
F_88 ( & V_81 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_5 ( V_2 , V_5 ) ;
F_90 ( & V_81 ) ;
F_141 ( V_2 , F_28 ( 0 ) ) ;
F_142 ( V_2 ) ;
}
static int F_143 ( unsigned V_2 , unsigned V_160 )
{
struct V_161 V_162 ;
int V_5 = F_10 ( V_2 ) ;
if ( ! F_41 ( V_5 ) )
return - 1 ;
if ( F_59 () && ! V_163 )
return - 1 ;
V_162 . V_40 = V_5 ;
V_162 . V_109 = V_160 ;
if ( F_47 ( V_164 , & V_162 ) >= 0 )
F_24 ( V_5 , V_160 ) ;
return 0 ;
}
static int F_144 ( struct V_35 * V_62 , const struct V_165 * V_166 ,
bool V_167 )
{
unsigned V_160 = F_145 ( V_166 ) ;
return F_143 ( V_62 -> V_2 , V_160 ) ;
}
int F_146 ( unsigned int V_2 )
{
int V_168 , V_5 = F_10 ( V_2 ) ;
struct V_28 * V_41 = V_42 ;
if ( ! F_41 ( V_5 ) )
return 1 ;
V_168 = F_49 ( V_5 , V_41 -> V_33 ) ;
F_37 ( V_5 , V_41 -> V_31 ) ;
if ( ! V_168 )
F_44 ( V_5 ) ;
return 1 ;
}
static void F_147 ( struct V_35 * V_62 )
{
int V_5 = F_10 ( V_62 -> V_2 ) ;
if ( F_41 ( V_5 ) )
F_44 ( V_5 ) ;
}
static void F_77 ( struct V_35 * V_62 )
{
int V_5 = F_10 ( V_62 -> V_2 ) ;
if ( F_41 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_148 ( struct V_35 * V_62 )
{
int V_5 = F_10 ( V_62 -> V_2 ) ;
F_74 ( V_62 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
}
static void F_149 ( struct V_35 * V_62 )
{
F_77 ( V_62 ) ;
F_148 ( V_62 ) ;
}
static int F_150 ( struct V_35 * V_62 )
{
int V_5 = F_10 ( V_62 -> V_2 ) ;
struct V_28 * V_29 = V_42 ;
int V_25 = 0 ;
if ( F_41 ( V_5 ) ) {
int V_168 ;
V_168 = F_49 ( V_5 , V_29 -> V_33 ) ;
F_37 ( V_5 , V_29 -> V_31 ) ;
if ( ! V_168 )
F_44 ( V_5 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_151 ( void )
{
int V_18 , V_65 , V_2 , V_19 ;
struct V_169 V_170 ;
struct V_1 * V_3 ;
F_32 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_19 = V_3 -> V_13 . V_18 . V_19 ;
V_2 = V_3 -> V_2 ;
if ( ! V_19 )
continue;
V_170 . V_21 = V_84 ;
V_170 . type = V_171 ;
V_170 . V_172 = V_19 ;
V_170 . V_18 = V_18 ;
V_65 = F_71 ( V_173 , & V_170 ) ;
if ( V_65 ) {
F_79 ( V_103 L_27 ,
V_19 , V_2 , V_18 , V_65 ) ;
F_65 ( V_2 ) ;
continue;
}
F_79 ( V_174 L_28 , V_2 , V_170 . V_18 ) ;
F_78 ( V_2 ) ;
}
}
static void F_152 ( unsigned int V_6 )
{
struct V_125 V_126 ;
int V_15 , V_2 , V_5 ;
for ( V_15 = 0 ; V_15 < V_175 ; V_15 ++ ) {
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_15 ) ;
V_126 . V_15 = V_15 ;
V_126 . V_109 = V_6 ;
if ( F_47 ( V_127 ,
& V_126 ) != 0 )
F_83 () ;
V_5 = V_126 . V_40 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
static void F_153 ( unsigned int V_6 )
{
struct V_105 V_106 ;
int V_11 , V_2 , V_5 ;
for ( V_11 = 0 ; V_11 < V_176 ; V_11 ++ ) {
if ( ( V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ) == - 1 )
continue;
F_4 ( F_14 ( V_2 ) != V_11 ) ;
V_106 . V_109 = V_6 ;
if ( F_47 ( V_110 ,
& V_106 ) != 0 )
F_83 () ;
V_5 = V_106 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
void F_154 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
}
void F_155 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) )
F_36 ( V_5 ) ;
}
bool F_156 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
bool V_25 = false ;
if ( F_41 ( V_5 ) )
V_25 = F_38 ( V_5 ) ;
return V_25 ;
}
void F_157 ( int V_2 , T_6 V_177 )
{
T_7 V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) ) {
struct V_178 V_179 ;
V_179 . V_180 = 1 ;
V_179 . V_177 = V_177 ;
F_158 ( V_179 . V_181 , & V_5 ) ;
if ( F_159 ( V_182 , & V_179 ) != 0 )
F_83 () ;
}
}
void F_160 ( int V_2 )
{
F_157 ( V_2 , 0 ) ;
}
int F_161 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_57 V_58 = { . V_2 = V_3 -> V_13 . V_18 . V_18 } ;
if ( F_71 ( V_59 , & V_58 ) )
return 0 ;
return ! ( V_58 . V_22 & V_183 ) ;
}
void F_162 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_31 () ;
for ( V_5 = 0 ; V_5 < V_121 ; V_5 ++ )
F_43 ( V_5 ) ;
F_32 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_121 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_33 (cpu) {
F_152 ( V_6 ) ;
F_153 ( V_6 ) ;
}
F_151 () ;
}
int F_163 ( T_8 V_184 )
{
struct V_185 V_186 ;
V_186 . V_21 = V_84 ;
V_186 . V_172 = V_187 ;
V_186 . V_188 = V_184 ;
return F_164 ( V_189 , & V_186 ) ;
}
void F_165 ( void )
{
int V_65 ;
T_8 V_190 ;
if ( V_163 ) {
V_190 = F_166 ( V_191 ) ;
V_65 = F_163 ( V_190 ) ;
if ( V_65 ) {
F_79 ( V_192 L_29
L_30 ) ;
V_163 = 0 ;
return;
}
F_79 ( V_73 L_31
L_32 ) ;
if ( ! F_21 ( V_191 , V_193 ) )
F_167 ( V_191 , V_194 ) ;
}
}
void F_165 ( void ) {}
void T_9 F_168 ( void )
{
int V_37 , V_65 ;
V_8 = F_169 ( V_121 , sizeof( * V_8 ) ,
V_51 ) ;
F_4 ( ! V_8 ) ;
for ( V_37 = 0 ; V_37 < V_121 ; V_37 ++ )
V_8 [ V_37 ] = - 1 ;
F_31 () ;
for ( V_37 = 0 ; V_37 < V_121 ; V_37 ++ )
F_43 ( V_37 ) ;
F_75 = F_22 ;
if ( F_59 () ) {
F_165 () ;
F_170 () ;
F_171 () ;
} else {
struct V_195 V_196 ;
F_172 ( F_116 () ) ;
if ( F_58 () )
F_173 () ;
V_26 = ( void * ) F_174 ( V_51 | V_197 ) ;
V_196 . V_198 = F_175 ( V_26 ) ;
V_65 = F_71 ( V_199 , & V_196 ) ;
if ( V_65 != 0 ) {
F_176 ( ( unsigned long ) V_26 ) ;
V_26 = NULL ;
} else
F_75 = F_20 ;
}
}
