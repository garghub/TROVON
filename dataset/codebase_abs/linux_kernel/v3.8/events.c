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
int V_43 = 0 , V_31 = 0 ;
F_4 ( ! F_46 () ) ;
if ( F_11 ( ( V_6 != F_19 ( V_40 ) ) ) )
V_43 = 1 ;
else
V_31 = F_39 ( V_40 , & V_41 -> V_31 [ 0 ] ) ;
if ( F_11 ( V_31 && F_47 () ) )
V_43 = 1 ;
if ( V_43 ) {
struct V_44 V_45 = { . V_40 = V_40 } ;
( void ) F_48 ( V_46 , & V_45 ) ;
} else {
struct V_47 * V_47 = F_49 ( V_48 ) ;
F_35 ( V_40 , & V_41 -> V_33 [ 0 ] ) ;
if ( V_31 &&
! F_50 ( V_40 / V_49 ,
& V_47 -> V_50 ) )
V_47 -> V_51 = 1 ;
}
F_51 () ;
}
static void F_52 ( unsigned V_2 )
{
struct V_1 * V_3 ;
#ifdef F_25
struct V_38 * V_39 = F_27 ( V_2 ) ;
F_26 ( V_39 -> V_35 . V_36 , F_28 ( 0 ) ) ;
#endif
V_3 = F_53 ( sizeof( * V_3 ) , V_52 ) ;
if ( V_3 == NULL )
F_54 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
V_3 -> V_53 = - 1 ;
F_55 ( V_2 , V_3 ) ;
F_56 ( & V_3 -> V_54 , & V_55 ) ;
}
static int T_2 F_57 ( void )
{
int V_56 = 0 ;
int V_2 ;
#ifdef F_58
if ( F_59 () || F_47 () )
V_56 = F_60 () ;
#endif
V_2 = F_61 ( V_56 , - 1 ) ;
if ( V_2 >= 0 )
F_52 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_62 ( unsigned V_19 )
{
int V_2 ;
if ( F_63 () && ! F_59 () )
return F_57 () ;
if ( V_19 < V_57 )
V_2 = V_19 ;
else
V_2 = F_64 ( V_19 , - 1 ) ;
F_52 ( V_2 ) ;
return V_2 ;
}
static void F_65 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_66 ( & V_3 -> V_54 ) ;
F_55 ( V_2 , NULL ) ;
F_67 ( V_3 -> V_53 > 0 ) ;
F_68 ( V_3 ) ;
if ( V_2 < V_57 )
return;
F_69 ( V_2 ) ;
}
static void F_70 ( int V_2 )
{
struct V_58 V_59 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
V_59 . V_2 = F_16 ( V_2 ) ;
if ( F_71 ( V_60 , & V_59 ) )
V_59 . V_22 = 0 ;
V_3 -> V_13 . V_18 . V_22 &= ~ V_27 ;
if ( V_59 . V_22 & V_61 )
V_3 -> V_13 . V_18 . V_22 |= V_27 ;
}
static bool F_72 ( int V_2 )
{
struct V_38 * V_39 = F_27 ( V_2 ) ;
return V_39 && V_39 -> V_62 == NULL ;
}
static void F_73 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
struct V_64 V_65 = { . V_2 = F_16 (data->irq) } ;
int V_66 = 0 ;
F_74 ( V_63 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
if ( F_75 ( V_63 -> V_2 ) ) {
V_66 = F_71 ( V_67 , & V_65 ) ;
F_67 ( V_66 ) ;
}
}
static void F_76 ( struct V_35 * V_63 )
{
F_77 ( V_63 ) ;
F_73 ( V_63 ) ;
}
static unsigned int F_78 ( unsigned int V_2 )
{
struct V_68 V_69 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
int V_66 ;
F_4 ( V_3 -> type != V_23 ) ;
if ( F_41 ( V_5 ) )
goto V_70;
V_69 . V_18 = F_16 ( V_2 ) ;
V_69 . V_22 = V_3 -> V_13 . V_18 . V_22 & V_71 ?
V_72 : 0 ;
V_66 = F_48 ( V_73 , & V_69 ) ;
if ( V_66 != 0 ) {
if ( ! F_72 ( V_2 ) )
F_79 ( V_74 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_69 . V_40 ;
F_70 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_24 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_70:
F_44 ( V_5 ) ;
F_73 ( F_80 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_81 ( struct V_35 * V_63 )
{
return F_78 ( V_63 -> V_2 ) ;
}
static void F_82 ( struct V_35 * V_63 )
{
struct V_75 V_76 ;
unsigned int V_2 = V_63 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
if ( ! F_41 ( V_5 ) )
return;
F_43 ( V_5 ) ;
V_76 . V_40 = V_5 ;
if ( F_48 ( V_77 , & V_76 ) != 0 )
F_83 () ;
F_24 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_84 ( struct V_35 * V_63 )
{
F_81 ( V_63 ) ;
}
static void F_85 ( struct V_35 * V_63 )
{
F_77 ( V_63 ) ;
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
unsigned V_18 , int V_78 , char * V_79 )
{
int V_2 = - 1 ;
struct V_80 V_81 ;
F_88 ( & V_82 ) ;
V_2 = F_86 ( V_19 ) ;
if ( V_2 != - 1 ) {
F_79 ( V_74 L_4 ,
V_2 , V_19 ) ;
goto V_70;
}
V_2 = F_62 ( V_19 ) ;
if ( V_2 < 0 )
goto V_70;
V_81 . V_2 = V_2 ;
V_81 . V_20 = 0 ;
if ( F_59 () &&
F_71 ( V_83 , & V_81 ) ) {
F_65 ( V_2 ) ;
V_2 = - V_84 ;
goto V_70;
}
F_9 ( V_2 , 0 , V_18 , V_19 , V_81 . V_20 , V_85 ,
V_78 ? V_71 : 0 ) ;
F_70 ( V_2 ) ;
if ( V_78 )
F_89 ( V_2 , & V_86 ,
V_87 , V_79 ) ;
else
F_89 ( V_2 , & V_86 ,
V_88 , V_79 ) ;
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
}
int F_91 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
int V_66 ;
struct V_93 V_94 ;
V_94 . type = V_95 ;
V_66 = F_71 ( V_96 , & V_94 ) ;
F_92 ( V_66 == - V_97 ,
L_5 ) ;
return V_66 ? - 1 : V_94 . V_18 ;
}
int F_93 ( struct V_89 * V_90 , struct V_91 * V_92 ,
int V_18 , int V_20 , const char * V_79 ,
T_3 V_21 )
{
int V_2 , V_25 ;
F_88 ( & V_82 ) ;
V_2 = F_57 () ;
if ( V_2 < 0 )
goto V_70;
F_89 ( V_2 , & V_86 , V_88 ,
V_79 ) ;
F_9 ( V_2 , 0 , V_18 , 0 , V_20 , V_21 , 0 ) ;
V_25 = F_94 ( V_2 , V_92 ) ;
if ( V_25 < 0 )
goto V_98;
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
V_98:
F_90 ( & V_82 ) ;
F_65 ( V_2 ) ;
return V_25 ;
}
int F_95 ( int V_2 )
{
struct V_38 * V_39 ;
struct V_99 V_100 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_66 = - V_101 ;
F_88 ( & V_82 ) ;
V_39 = F_27 ( V_2 ) ;
if ( ! V_39 )
goto V_70;
if ( F_59 () ) {
V_100 . V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_100 . V_21 = V_3 -> V_13 . V_18 . V_21 ;
V_66 = F_71 ( V_102 , & V_100 ) ;
if ( ( V_66 == - V_103 && V_3 -> V_13 . V_18 . V_21 != V_85 ) )
F_79 ( V_74 L_6 ,
V_3 -> V_13 . V_18 . V_21 , V_3 -> V_13 . V_18 . V_18 ) ;
else if ( V_66 ) {
F_79 ( V_104 L_7 , V_66 ) ;
goto V_70;
}
}
F_65 ( V_2 ) ;
V_70:
F_90 ( & V_82 ) ;
return V_66 ;
}
int F_96 ( unsigned V_18 )
{
int V_2 ;
struct V_1 * V_3 ;
F_88 ( & V_82 ) ;
F_32 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_13 . V_18 . V_18 == V_18 )
goto V_70;
}
V_2 = - 1 ;
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
}
int F_97 ( unsigned V_2 )
{
return F_16 ( V_2 ) ;
}
int F_98 ( unsigned int V_5 )
{
int V_2 ;
F_88 ( & V_82 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_57 () ;
if ( V_2 < 0 )
goto V_70;
F_89 ( V_2 , & V_105 ,
V_88 , L_8 ) ;
F_5 ( V_2 , V_5 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_9 ) ;
}
F_99 ( V_2 , V_106 | V_107 ) ;
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
}
static int F_100 ( unsigned int V_11 , unsigned int V_6 )
{
struct V_108 V_109 ;
int V_5 , V_2 ;
F_88 ( & V_82 ) ;
V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ;
if ( V_2 == - 1 ) {
V_2 = F_57 () ;
if ( V_2 < 0 )
goto V_70;
F_89 ( V_2 , & V_110 ,
V_111 , L_9 ) ;
V_109 . V_112 = V_6 ;
if ( F_48 ( V_113 ,
& V_109 ) != 0 )
F_83 () ;
V_5 = V_109 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_12 ) ;
}
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
}
static int F_101 ( unsigned int V_114 ,
unsigned int V_115 )
{
struct V_116 V_117 ;
int V_118 ;
V_117 . V_119 = V_114 ;
V_117 . V_115 = V_115 ;
V_118 = F_48 ( V_120 ,
& V_117 ) ;
return V_118 ? : F_98 ( V_117 . V_121 ) ;
}
static int F_102 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_122 V_123 ;
int V_40 , V_66 = - V_101 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
for ( V_40 = 0 ; V_40 <= V_124 ; V_40 ++ ) {
V_123 . V_125 = V_85 ;
V_123 . V_40 = V_40 ;
V_66 = F_48 ( V_126 , & V_123 ) ;
if ( V_66 < 0 )
continue;
if ( V_123 . V_123 != V_127 )
continue;
if ( V_123 . V_13 . V_15 == V_15 && V_123 . V_112 == V_6 ) {
V_66 = V_40 ;
break;
}
}
return V_66 ;
}
int F_103 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_128 V_129 ;
int V_5 , V_2 , V_25 ;
F_88 ( & V_82 ) ;
V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ;
if ( V_2 == - 1 ) {
V_2 = F_57 () ;
if ( V_2 < 0 )
goto V_70;
F_89 ( V_2 , & V_110 ,
V_111 , L_10 ) ;
V_129 . V_15 = V_15 ;
V_129 . V_112 = V_6 ;
V_25 = F_48 ( V_130 ,
& V_129 ) ;
if ( V_25 == 0 )
V_5 = V_129 . V_40 ;
else {
if ( V_25 == - V_131 )
V_25 = F_102 ( V_15 , V_6 ) ;
F_4 ( V_25 < 0 ) ;
V_5 = V_25 ;
}
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_67 ( V_3 == NULL || V_3 -> type != V_16 ) ;
}
V_70:
F_90 ( & V_82 ) ;
return V_2 ;
}
static void F_104 ( unsigned int V_2 )
{
struct V_75 V_76 ;
int V_5 = F_10 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_88 ( & V_82 ) ;
if ( V_3 -> V_53 > 0 ) {
V_3 -> V_53 -- ;
if ( V_3 -> V_53 != 0 )
goto V_132;
}
if ( F_41 ( V_5 ) ) {
V_76 . V_40 = V_5 ;
if ( F_48 ( V_77 , & V_76 ) != 0 )
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
V_132:
F_90 ( & V_82 ) ;
}
int F_105 ( unsigned int V_5 ,
T_4 V_133 ,
unsigned long V_134 ,
const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_98 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_106 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_104 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_107 ( unsigned int V_114 ,
unsigned int V_115 ,
T_4 V_133 ,
unsigned long V_134 ,
const char * V_135 ,
void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_101 ( V_114 , V_115 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_106 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_104 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_108 ( unsigned int V_15 , unsigned int V_6 ,
T_4 V_133 ,
unsigned long V_134 , const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_103 ( V_15 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_106 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_104 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_109 ( enum V_10 V_11 ,
unsigned int V_6 ,
T_4 V_133 ,
unsigned long V_134 ,
const char * V_135 ,
void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_100 ( V_11 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_134 |= V_138 | V_139 | V_140 ;
V_137 = F_106 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_104 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
void F_110 ( unsigned int V_2 , void * V_136 )
{
F_111 ( V_2 , V_136 ) ;
F_104 ( V_2 ) ;
}
int F_112 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_101 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_101 ;
F_67 ( V_3 -> V_53 != - 1 ) ;
V_3 -> V_53 = 1 ;
return 0 ;
}
int F_113 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_118 = - V_101 ;
if ( V_5 >= V_124 )
return - V_141 ;
F_88 ( & V_82 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 )
goto V_132;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
goto V_132;
V_118 = - V_141 ;
if ( V_3 -> V_53 <= 0 )
goto V_132;
V_3 -> V_53 ++ ;
V_118 = 0 ;
V_132:
F_90 ( & V_82 ) ;
return V_118 ;
}
void F_114 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_67 ( V_2 == - 1 ) )
return;
F_104 ( V_2 ) ;
}
void F_115 ( unsigned int V_6 , enum V_10 V_20 )
{
int V_2 = F_7 ( V_14 , V_6 ) [ V_20 ] ;
F_4 ( V_2 < 0 ) ;
F_40 ( V_2 ) ;
}
T_5 F_116 ( int V_2 , void * V_136 )
{
struct V_28 * V_29 = V_42 ;
int V_6 = F_117 () ;
unsigned long * V_142 = F_7 ( V_32 , V_6 ) ;
int V_37 ;
unsigned long V_22 ;
static F_118 ( V_143 ) ;
struct V_47 * V_144 ;
F_119 ( & V_143 , V_22 ) ;
F_79 ( L_11 , V_6 ) ;
F_120 (i) {
int V_145 ;
V_144 = F_7 ( V_48 , V_37 ) ;
V_145 = ( F_121 () && V_37 == V_6 )
? F_122 ( F_121 () )
: V_144 -> V_146 ;
F_79 ( L_12 , V_37 ,
V_145 , V_144 -> V_51 ,
( int ) ( sizeof( V_144 -> V_50 ) * 2 ) ,
V_144 -> V_50 ) ;
}
V_144 = F_7 ( V_48 , V_6 ) ;
F_79 ( L_13 ) ;
for ( V_37 = F_123 ( V_29 -> V_31 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) sizeof( V_29 -> V_31 [ 0 ] ) * 2 ,
V_29 -> V_31 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_17 ) ;
for ( V_37 = F_123 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 ,
( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_18 ) ;
for ( V_37 = F_123 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_31 [ V_37 ] & ~ V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_19 , V_6 ) ;
for ( V_37 = ( V_124 / V_49 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_79 ( L_14 , ( int ) ( sizeof( V_142 [ 0 ] ) * 2 ) ,
V_142 [ V_37 ] ,
V_37 % 8 == 0 ? L_15 : L_16 ) ;
F_79 ( L_20 ) ;
for ( V_37 = F_123 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- ) {
unsigned long V_145 = V_29 -> V_31 [ V_37 ]
& ~ V_29 -> V_33 [ V_37 ]
& V_142 [ V_37 ] ;
F_79 ( L_14 , ( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_145 , V_37 % 8 == 0 ? L_15 : L_16 ) ;
}
F_79 ( L_21 ) ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ ) {
if ( F_39 ( V_37 , V_29 -> V_31 ) ) {
int V_147 = V_37 / V_49 ;
F_79 ( L_22 ,
F_19 ( V_37 ) , V_37 ,
V_8 [ V_37 ] ,
F_39 ( V_147 , & V_144 -> V_50 )
? L_23 : L_24 ,
! F_39 ( V_37 , V_29 -> V_33 )
? L_23 : L_25 ,
F_39 ( V_37 , V_142 )
? L_23 : L_26 ) ;
}
}
F_124 ( & V_143 , V_22 ) ;
return V_148 ;
}
static void F_125 ( void )
{
int V_149 , V_150 ;
int V_147 , V_151 ;
int V_37 ;
int V_6 = F_45 () ;
struct V_28 * V_41 = V_42 ;
struct V_47 * V_47 = F_49 ( V_48 ) ;
unsigned V_152 ;
do {
unsigned long V_153 ;
V_47 -> V_51 = 0 ;
if ( F_126 ( V_154 ) - 1 )
goto V_70;
#ifndef F_127
F_128 () ;
#endif
V_153 = F_129 ( & V_47 -> V_50 , 0 ) ;
V_149 = F_49 ( V_155 ) ;
V_150 = F_49 ( V_156 ) ;
V_147 = V_149 ;
for ( V_37 = 0 ; V_153 != 0 ; V_37 ++ ) {
unsigned long V_157 ;
unsigned long V_158 ;
V_158 = F_130 ( V_153 , V_147 ) ;
if ( V_158 == 0 ) {
V_147 = 0 ;
V_151 = 0 ;
continue;
}
V_147 = F_131 ( V_158 ) ;
V_157 = F_23 ( V_6 , V_41 , V_147 ) ;
V_151 = 0 ;
if ( V_147 == V_149 ) {
if ( V_37 == 0 )
V_151 = V_150 ;
else
V_151 &= ( 1UL << V_150 ) - 1 ;
}
do {
unsigned long V_159 ;
int V_40 , V_2 ;
struct V_38 * V_39 ;
V_159 = F_130 ( V_157 , V_151 ) ;
if ( V_159 == 0 )
break;
V_151 = F_131 ( V_159 ) ;
V_40 = ( V_147 * V_49 ) + V_151 ;
V_2 = V_8 [ V_40 ] ;
if ( V_2 != - 1 ) {
V_39 = F_27 ( V_2 ) ;
if ( V_39 )
F_132 ( V_2 , V_39 ) ;
}
V_151 = ( V_151 + 1 ) % V_49 ;
F_133 ( V_155 ,
V_151 ? V_147 :
( V_147 + 1 ) % V_49 ) ;
F_133 ( V_156 , V_151 ) ;
} while ( V_151 != 0 );
if ( ( V_147 != V_149 ) || ( V_37 != 0 ) )
V_153 &= ~ ( 1UL << V_147 ) ;
V_147 = ( V_147 + 1 ) % V_49 ;
}
F_4 ( ! F_46 () ) ;
V_152 = F_49 ( V_154 ) ;
F_133 ( V_154 , 0 ) ;
} while ( V_152 != 1 || V_47 -> V_51 );
V_70:
F_51 () ;
}
void F_134 ( struct V_160 * V_161 )
{
struct V_160 * V_162 = F_135 ( V_161 ) ;
F_136 () ;
#ifdef F_127
F_137 () ;
#endif
F_125 () ;
F_138 () ;
F_135 ( V_162 ) ;
}
void F_139 ( void )
{
F_125 () ;
}
void F_140 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_141 ( V_2 ) ;
F_88 ( & V_82 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_5 ( V_2 , V_5 ) ;
F_90 ( & V_82 ) ;
F_142 ( V_2 , F_28 ( 0 ) ) ;
F_143 ( V_2 ) ;
}
static int F_144 ( unsigned V_2 , unsigned V_163 )
{
struct V_164 V_165 ;
int V_5 = F_10 ( V_2 ) ;
if ( ! F_41 ( V_5 ) )
return - 1 ;
if ( F_47 () && ! V_166 )
return - 1 ;
V_165 . V_40 = V_5 ;
V_165 . V_112 = V_163 ;
if ( F_48 ( V_167 , & V_165 ) >= 0 )
F_24 ( V_5 , V_163 ) ;
return 0 ;
}
static int F_145 ( struct V_35 * V_63 , const struct V_168 * V_169 ,
bool V_170 )
{
unsigned V_163 = F_146 ( V_169 ) ;
return F_144 ( V_63 -> V_2 , V_163 ) ;
}
int F_147 ( unsigned int V_2 )
{
int V_171 , V_5 = F_10 ( V_2 ) ;
struct V_28 * V_41 = V_42 ;
if ( ! F_41 ( V_5 ) )
return 1 ;
V_171 = F_50 ( V_5 , V_41 -> V_33 ) ;
F_37 ( V_5 , V_41 -> V_31 ) ;
if ( ! V_171 )
F_44 ( V_5 ) ;
return 1 ;
}
static void F_148 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
if ( F_41 ( V_5 ) )
F_44 ( V_5 ) ;
}
static void F_77 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
if ( F_41 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_149 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
F_74 ( V_63 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
}
static void F_150 ( struct V_35 * V_63 )
{
F_77 ( V_63 ) ;
F_149 ( V_63 ) ;
}
static int F_151 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
struct V_28 * V_29 = V_42 ;
int V_25 = 0 ;
if ( F_41 ( V_5 ) ) {
int V_171 ;
V_171 = F_50 ( V_5 , V_29 -> V_33 ) ;
F_37 ( V_5 , V_29 -> V_31 ) ;
if ( ! V_171 )
F_44 ( V_5 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_152 ( void )
{
int V_18 , V_66 , V_2 , V_19 ;
struct V_172 V_173 ;
struct V_1 * V_3 ;
F_32 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_19 = V_3 -> V_13 . V_18 . V_19 ;
V_2 = V_3 -> V_2 ;
if ( ! V_19 )
continue;
V_173 . V_21 = V_85 ;
V_173 . type = V_174 ;
V_173 . V_175 = V_19 ;
V_173 . V_18 = V_18 ;
V_66 = F_71 ( V_176 , & V_173 ) ;
if ( V_66 ) {
F_79 ( V_104 L_27 ,
V_19 , V_2 , V_18 , V_66 ) ;
F_65 ( V_2 ) ;
continue;
}
F_79 ( V_177 L_28 , V_2 , V_173 . V_18 ) ;
F_78 ( V_2 ) ;
}
}
static void F_153 ( unsigned int V_6 )
{
struct V_128 V_129 ;
int V_15 , V_2 , V_5 ;
for ( V_15 = 0 ; V_15 < V_178 ; V_15 ++ ) {
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_15 ) ;
V_129 . V_15 = V_15 ;
V_129 . V_112 = V_6 ;
if ( F_48 ( V_130 ,
& V_129 ) != 0 )
F_83 () ;
V_5 = V_129 . V_40 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
static void F_154 ( unsigned int V_6 )
{
struct V_108 V_109 ;
int V_11 , V_2 , V_5 ;
for ( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
if ( ( V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ) == - 1 )
continue;
F_4 ( F_14 ( V_2 ) != V_11 ) ;
V_109 . V_112 = V_6 ;
if ( F_48 ( V_113 ,
& V_109 ) != 0 )
F_83 () ;
V_5 = V_109 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
void F_155 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) )
F_34 ( V_5 ) ;
}
void F_156 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) )
F_36 ( V_5 ) ;
}
bool F_157 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
bool V_25 = false ;
if ( F_41 ( V_5 ) )
V_25 = F_38 ( V_5 ) ;
return V_25 ;
}
void F_158 ( int V_2 , T_6 V_180 )
{
T_7 V_5 = F_10 ( V_2 ) ;
if ( F_41 ( V_5 ) ) {
struct V_181 V_182 ;
V_182 . V_183 = 1 ;
V_182 . V_180 = V_180 ;
F_159 ( V_182 . V_184 , & V_5 ) ;
if ( F_160 ( V_185 , & V_182 ) != 0 )
F_83 () ;
}
}
void F_161 ( int V_2 )
{
F_158 ( V_2 , 0 ) ;
}
int F_162 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_58 V_59 = { . V_2 = V_3 -> V_13 . V_18 . V_18 } ;
if ( F_71 ( V_60 , & V_59 ) )
return 0 ;
return ! ( V_59 . V_22 & V_186 ) ;
}
void F_163 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_31 () ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
F_43 ( V_5 ) ;
F_32 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_33 (cpu) {
F_153 ( V_6 ) ;
F_154 ( V_6 ) ;
}
F_152 () ;
}
int F_164 ( T_8 V_187 )
{
struct V_188 V_189 ;
V_189 . V_21 = V_85 ;
V_189 . V_175 = V_190 ;
V_189 . V_191 = V_187 ;
return F_165 ( V_192 , & V_189 ) ;
}
void F_166 ( void )
{
int V_66 ;
T_8 V_193 ;
if ( V_166 ) {
V_193 = F_167 ( V_194 ) ;
V_66 = F_164 ( V_193 ) ;
if ( V_66 ) {
F_79 ( V_195 L_29
L_30 ) ;
V_166 = 0 ;
return;
}
F_79 ( V_74 L_31
L_32 ) ;
if ( ! F_21 ( V_194 , V_196 ) )
F_168 ( V_194 , V_197 ) ;
}
}
void F_166 ( void ) {}
void T_9 F_169 ( void )
{
int V_37 ;
V_8 = F_170 ( V_124 , sizeof( * V_8 ) ,
V_52 ) ;
F_4 ( ! V_8 ) ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ )
V_8 [ V_37 ] = - 1 ;
F_31 () ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ )
F_43 ( V_37 ) ;
F_75 = F_22 ;
#ifdef F_127
if ( F_47 () ) {
F_166 () ;
F_171 () ;
F_172 () ;
} else {
int V_66 ;
struct V_198 V_199 ;
F_173 ( F_117 () ) ;
if ( F_59 () )
F_174 () ;
V_26 = ( void * ) F_175 ( V_52 | V_200 ) ;
V_199 . V_201 = F_176 ( V_26 ) ;
V_66 = F_71 ( V_202 , & V_199 ) ;
if ( V_66 != 0 ) {
F_177 ( ( unsigned long ) V_26 ) ;
V_26 = NULL ;
} else
F_75 = F_20 ;
}
#endif
}
