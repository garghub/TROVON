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
static inline T_2 F_23 ( unsigned int V_6 ,
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
F_29 ( V_34 , F_30 ( F_7 ( V_32 , F_18 ( V_2 ) ) ) ) ;
F_31 ( V_34 , F_30 ( F_7 ( V_32 , V_6 ) ) ) ;
F_1 ( V_2 ) -> V_6 = V_6 ;
}
static void F_32 ( void )
{
int V_37 ;
#ifdef F_25
struct V_1 * V_3 ;
F_33 (info, &xen_irq_list_head, list) {
struct V_38 * V_39 = F_27 ( V_3 -> V_2 ) ;
F_26 ( V_39 -> V_35 . V_36 , F_28 ( 0 ) ) ;
}
#endif
F_34 (i)
memset ( F_7 ( V_32 , V_37 ) ,
( V_37 == 0 ) ? ~ 0 : 0 , sizeof( * F_7 ( V_32 , V_37 ) ) ) ;
}
static inline void F_35 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_36 ( V_40 , F_30 ( & V_41 -> V_31 [ 0 ] ) ) ;
}
static inline void F_37 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_38 ( V_40 , F_30 ( & V_41 -> V_31 [ 0 ] ) ) ;
}
static inline int F_39 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
return F_40 ( V_40 , F_30 ( & V_41 -> V_31 [ 0 ] ) ) ;
}
void F_41 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_42 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_44 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
F_38 ( V_40 , F_30 ( & V_41 -> V_33 [ 0 ] ) ) ;
}
static void F_45 ( int V_40 )
{
struct V_28 * V_41 = V_42 ;
unsigned int V_6 = F_46 () ;
int V_43 = 0 , V_31 = 0 ;
F_4 ( ! F_47 () ) ;
if ( F_11 ( ( V_6 != F_19 ( V_40 ) ) ) )
V_43 = 1 ;
else {
F_36 ( V_40 , F_30 ( & V_41 -> V_33 [ 0 ] ) ) ;
V_31 = F_40 ( V_40 , F_30 ( & V_41 -> V_31 [ 0 ] ) ) ;
if ( F_11 ( V_31 && F_48 () ) ) {
F_38 ( V_40 , F_30 ( & V_41 -> V_33 [ 0 ] ) ) ;
V_43 = 1 ;
}
}
if ( V_43 ) {
struct V_44 V_45 = { . V_40 = V_40 } ;
( void ) F_49 ( V_46 , & V_45 ) ;
} else {
struct V_47 * V_47 = F_50 ( V_48 ) ;
if ( V_31 &&
! F_51 ( V_40 / V_49 ,
F_30 ( & V_47 -> V_50 ) ) )
V_47 -> V_51 = 1 ;
}
F_52 () ;
}
static void F_53 ( unsigned V_2 )
{
struct V_1 * V_3 ;
#ifdef F_25
struct V_38 * V_39 = F_27 ( V_2 ) ;
F_26 ( V_39 -> V_35 . V_36 , F_28 ( 0 ) ) ;
#endif
V_3 = F_54 ( sizeof( * V_3 ) , V_52 ) ;
if ( V_3 == NULL )
F_55 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
V_3 -> V_53 = - 1 ;
F_56 ( V_2 , V_3 ) ;
F_57 ( & V_3 -> V_54 , & V_55 ) ;
}
static int T_3 F_58 ( void )
{
int V_56 = 0 ;
int V_2 ;
#ifdef F_59
if ( F_60 () || F_48 () )
V_56 = F_61 () ;
#endif
V_2 = F_62 ( V_56 , - 1 ) ;
if ( V_2 >= 0 )
F_53 ( V_2 ) ;
return V_2 ;
}
static int T_3 F_63 ( unsigned V_19 )
{
int V_2 ;
if ( F_64 () && ! F_60 () )
return F_58 () ;
if ( V_19 < V_57 )
V_2 = V_19 ;
else
V_2 = F_65 ( V_19 , - 1 ) ;
F_53 ( V_2 ) ;
return V_2 ;
}
static void F_66 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_67 ( & V_3 -> V_54 ) ;
F_56 ( V_2 , NULL ) ;
F_68 ( V_3 -> V_53 > 0 ) ;
F_69 ( V_3 ) ;
if ( V_2 < V_57 )
return;
F_70 ( V_2 ) ;
}
static void F_71 ( int V_2 )
{
struct V_58 V_59 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
V_59 . V_2 = F_16 ( V_2 ) ;
if ( F_72 ( V_60 , & V_59 ) )
V_59 . V_22 = 0 ;
V_3 -> V_13 . V_18 . V_22 &= ~ V_27 ;
if ( V_59 . V_22 & V_61 )
V_3 -> V_13 . V_18 . V_22 |= V_27 ;
}
static bool F_73 ( int V_2 )
{
struct V_38 * V_39 = F_27 ( V_2 ) ;
return V_39 && V_39 -> V_62 == NULL ;
}
static void F_74 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
struct V_64 V_65 = { . V_2 = F_16 (data->irq) } ;
int V_66 = 0 ;
F_75 ( V_63 ) ;
if ( F_42 ( V_5 ) )
F_35 ( V_5 ) ;
if ( F_76 ( V_63 -> V_2 ) ) {
V_66 = F_72 ( V_67 , & V_65 ) ;
F_68 ( V_66 ) ;
}
}
static void F_77 ( struct V_35 * V_63 )
{
F_78 ( V_63 ) ;
F_74 ( V_63 ) ;
}
static unsigned int F_79 ( unsigned int V_2 )
{
struct V_68 V_69 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
int V_66 ;
F_4 ( V_3 -> type != V_23 ) ;
if ( F_42 ( V_5 ) )
goto V_70;
V_69 . V_18 = F_16 ( V_2 ) ;
V_69 . V_22 = V_3 -> V_13 . V_18 . V_22 & V_71 ?
V_72 : 0 ;
V_66 = F_49 ( V_73 , & V_69 ) ;
if ( V_66 != 0 ) {
if ( ! F_73 ( V_2 ) )
F_80 ( V_74 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_69 . V_40 ;
F_71 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_24 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_70:
F_45 ( V_5 ) ;
F_74 ( F_81 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_82 ( struct V_35 * V_63 )
{
return F_79 ( V_63 -> V_2 ) ;
}
static void F_83 ( struct V_35 * V_63 )
{
struct V_75 V_76 ;
unsigned int V_2 = V_63 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_10 ( V_2 ) ;
F_4 ( V_3 -> type != V_23 ) ;
if ( ! F_42 ( V_5 ) )
return;
F_44 ( V_5 ) ;
V_76 . V_40 = V_5 ;
if ( F_49 ( V_77 , & V_76 ) != 0 )
F_84 () ;
F_24 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_85 ( struct V_35 * V_63 )
{
F_82 ( V_63 ) ;
}
static void F_86 ( struct V_35 * V_63 )
{
F_78 ( V_63 ) ;
}
int F_87 ( unsigned V_19 )
{
struct V_1 * V_3 ;
F_33 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
if ( V_3 -> V_13 . V_18 . V_19 == V_19 )
return V_3 -> V_2 ;
}
return - 1 ;
}
int F_88 ( unsigned V_19 ,
unsigned V_18 , int V_78 , char * V_79 )
{
int V_2 = - 1 ;
struct V_80 V_81 ;
F_89 ( & V_82 ) ;
V_2 = F_87 ( V_19 ) ;
if ( V_2 != - 1 ) {
F_80 ( V_74 L_4 ,
V_2 , V_19 ) ;
goto V_70;
}
V_2 = F_63 ( V_19 ) ;
if ( V_2 < 0 )
goto V_70;
V_81 . V_2 = V_2 ;
V_81 . V_20 = 0 ;
if ( F_60 () &&
F_72 ( V_83 , & V_81 ) ) {
F_66 ( V_2 ) ;
V_2 = - V_84 ;
goto V_70;
}
F_9 ( V_2 , 0 , V_18 , V_19 , V_81 . V_20 , V_85 ,
V_78 ? V_71 : 0 ) ;
F_71 ( V_2 ) ;
if ( V_78 )
F_90 ( V_2 , & V_86 ,
V_87 , V_79 ) ;
else
F_90 ( V_2 , & V_86 ,
V_88 , V_79 ) ;
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
}
int F_92 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
int V_66 ;
struct V_93 V_94 ;
V_94 . type = V_95 ;
V_66 = F_72 ( V_96 , & V_94 ) ;
F_93 ( V_66 == - V_97 ,
L_5 ) ;
return V_66 ? - 1 : V_94 . V_18 ;
}
int F_94 ( struct V_89 * V_90 , struct V_91 * V_92 ,
int V_18 , int V_20 , const char * V_79 ,
T_4 V_21 )
{
int V_2 , V_25 ;
F_89 ( & V_82 ) ;
V_2 = F_58 () ;
if ( V_2 < 0 )
goto V_70;
F_90 ( V_2 , & V_86 , V_88 ,
V_79 ) ;
F_9 ( V_2 , 0 , V_18 , 0 , V_20 , V_21 , 0 ) ;
V_25 = F_95 ( V_2 , V_92 ) ;
if ( V_25 < 0 )
goto V_98;
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
V_98:
F_91 ( & V_82 ) ;
F_66 ( V_2 ) ;
return V_25 ;
}
int F_96 ( int V_2 )
{
struct V_38 * V_39 ;
struct V_99 V_100 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_66 = - V_101 ;
F_89 ( & V_82 ) ;
V_39 = F_27 ( V_2 ) ;
if ( ! V_39 )
goto V_70;
if ( F_60 () ) {
V_100 . V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_100 . V_21 = V_3 -> V_13 . V_18 . V_21 ;
V_66 = F_72 ( V_102 , & V_100 ) ;
if ( ( V_66 == - V_103 && V_3 -> V_13 . V_18 . V_21 != V_85 ) )
F_80 ( V_74 L_6 ,
V_3 -> V_13 . V_18 . V_21 , V_3 -> V_13 . V_18 . V_18 ) ;
else if ( V_66 ) {
F_80 ( V_104 L_7 , V_66 ) ;
goto V_70;
}
}
F_66 ( V_2 ) ;
V_70:
F_91 ( & V_82 ) ;
return V_66 ;
}
int F_97 ( unsigned V_18 )
{
int V_2 ;
struct V_1 * V_3 ;
F_89 ( & V_82 ) ;
F_33 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_13 . V_18 . V_18 == V_18 )
goto V_70;
}
V_2 = - 1 ;
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
}
int F_98 ( unsigned V_2 )
{
return F_16 ( V_2 ) ;
}
int F_99 ( unsigned int V_5 )
{
int V_2 ;
F_89 ( & V_82 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_58 () ;
if ( V_2 < 0 )
goto V_70;
F_90 ( V_2 , & V_105 ,
V_88 , L_8 ) ;
F_5 ( V_2 , V_5 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_9 ) ;
}
F_100 ( V_2 , V_106 | V_107 ) ;
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
}
static int F_101 ( unsigned int V_11 , unsigned int V_6 )
{
struct V_108 V_109 ;
int V_5 , V_2 ;
F_89 ( & V_82 ) ;
V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ;
if ( V_2 == - 1 ) {
V_2 = F_58 () ;
if ( V_2 < 0 )
goto V_70;
F_90 ( V_2 , & V_110 ,
V_111 , L_9 ) ;
V_109 . V_112 = V_6 ;
if ( F_49 ( V_113 ,
& V_109 ) != 0 )
F_84 () ;
V_5 = V_109 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_12 ) ;
}
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
}
static int F_102 ( unsigned int V_114 ,
unsigned int V_115 )
{
struct V_116 V_117 ;
int V_118 ;
V_117 . V_119 = V_114 ;
V_117 . V_115 = V_115 ;
V_118 = F_49 ( V_120 ,
& V_117 ) ;
return V_118 ? : F_99 ( V_117 . V_121 ) ;
}
static int F_103 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_122 V_123 ;
int V_40 , V_66 = - V_101 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
for ( V_40 = 0 ; V_40 <= V_124 ; V_40 ++ ) {
V_123 . V_125 = V_85 ;
V_123 . V_40 = V_40 ;
V_66 = F_49 ( V_126 , & V_123 ) ;
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
int F_104 ( unsigned int V_15 , unsigned int V_6 )
{
struct V_128 V_129 ;
int V_5 , V_2 , V_25 ;
F_89 ( & V_82 ) ;
V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ;
if ( V_2 == - 1 ) {
V_2 = F_58 () ;
if ( V_2 < 0 )
goto V_70;
F_90 ( V_2 , & V_110 ,
V_111 , L_10 ) ;
V_129 . V_15 = V_15 ;
V_129 . V_112 = V_6 ;
V_25 = F_49 ( V_130 ,
& V_129 ) ;
if ( V_25 == 0 )
V_5 = V_129 . V_40 ;
else {
if ( V_25 == - V_131 )
V_25 = F_103 ( V_15 , V_6 ) ;
F_4 ( V_25 < 0 ) ;
V_5 = V_25 ;
}
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_16 ) ;
}
V_70:
F_91 ( & V_82 ) ;
return V_2 ;
}
static void F_105 ( unsigned int V_2 )
{
struct V_75 V_76 ;
int V_5 = F_10 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
F_89 ( & V_82 ) ;
if ( V_3 -> V_53 > 0 ) {
V_3 -> V_53 -- ;
if ( V_3 -> V_53 != 0 )
goto V_132;
}
if ( F_42 ( V_5 ) ) {
V_76 . V_40 = V_5 ;
if ( F_49 ( V_77 , & V_76 ) != 0 )
F_84 () ;
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
F_66 ( V_2 ) ;
V_132:
F_91 ( & V_82 ) ;
}
int F_106 ( unsigned int V_5 ,
T_5 V_133 ,
unsigned long V_134 ,
const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_99 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_107 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_105 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_108 ( unsigned int V_114 ,
unsigned int V_115 ,
T_5 V_133 ,
unsigned long V_134 ,
const char * V_135 ,
void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_102 ( V_114 , V_115 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_107 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_105 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_109 ( unsigned int V_15 , unsigned int V_6 ,
T_5 V_133 ,
unsigned long V_134 , const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_104 ( V_15 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_107 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_105 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_110 ( enum V_10 V_11 ,
unsigned int V_6 ,
T_5 V_133 ,
unsigned long V_134 ,
const char * V_135 ,
void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_101 ( V_11 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_134 |= V_138 | V_139 | V_140 ;
V_137 = F_107 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_105 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
void F_111 ( unsigned int V_2 , void * V_136 )
{
F_112 ( V_2 , V_136 ) ;
F_105 ( V_2 ) ;
}
int F_113 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_101 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_101 ;
F_68 ( V_3 -> V_53 != - 1 ) ;
V_3 -> V_53 = 1 ;
return 0 ;
}
int F_114 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_118 = - V_101 ;
if ( V_5 >= V_124 )
return - V_141 ;
F_89 ( & V_82 ) ;
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
F_91 ( & V_82 ) ;
return V_118 ;
}
void F_115 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_68 ( V_2 == - 1 ) )
return;
F_105 ( V_2 ) ;
}
void F_116 ( unsigned int V_6 , enum V_10 V_20 )
{
int V_2 = F_7 ( V_14 , V_6 ) [ V_20 ] ;
F_4 ( V_2 < 0 ) ;
F_41 ( V_2 ) ;
}
T_6 F_117 ( int V_2 , void * V_136 )
{
struct V_28 * V_29 = V_42 ;
int V_6 = F_118 () ;
T_2 * V_142 = F_7 ( V_32 , V_6 ) ;
int V_37 ;
unsigned long V_22 ;
static F_119 ( V_143 ) ;
struct V_47 * V_144 ;
F_120 ( & V_143 , V_22 ) ;
F_80 ( L_11 , V_6 ) ;
F_121 (i) {
int V_145 ;
V_144 = F_7 ( V_48 , V_37 ) ;
V_145 = ( F_122 () && V_37 == V_6 )
? F_123 ( F_122 () )
: V_144 -> V_146 ;
F_80 ( L_12 V_147 L_13 , V_37 ,
V_145 , V_144 -> V_51 ,
( int ) ( sizeof( V_144 -> V_50 ) * 2 ) ,
V_144 -> V_50 ) ;
}
V_144 = F_7 ( V_48 , V_6 ) ;
F_80 ( L_14 ) ;
for ( V_37 = F_124 ( V_29 -> V_31 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_80 ( L_15 V_147 L_16 ,
( int ) sizeof( V_29 -> V_31 [ 0 ] ) * 2 ,
V_29 -> V_31 [ V_37 ] ,
V_37 % 8 == 0 ? L_17 : L_18 ) ;
F_80 ( L_19 ) ;
for ( V_37 = F_124 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_80 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_17 : L_18 ) ;
F_80 ( L_20 ) ;
for ( V_37 = F_124 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_80 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_29 -> V_31 [ V_37 ] & ~ V_29 -> V_33 [ V_37 ] ,
V_37 % 8 == 0 ? L_17 : L_18 ) ;
F_80 ( L_21 , V_6 ) ;
for ( V_37 = ( V_124 / V_49 ) - 1 ; V_37 >= 0 ; V_37 -- )
F_80 ( L_15 V_147 L_16 , ( int ) ( sizeof( V_142 [ 0 ] ) * 2 ) ,
V_142 [ V_37 ] ,
V_37 % 8 == 0 ? L_17 : L_18 ) ;
F_80 ( L_22 ) ;
for ( V_37 = F_124 ( V_29 -> V_33 ) - 1 ; V_37 >= 0 ; V_37 -- ) {
T_2 V_145 = V_29 -> V_31 [ V_37 ]
& ~ V_29 -> V_33 [ V_37 ]
& V_142 [ V_37 ] ;
F_80 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_29 -> V_33 [ 0 ] ) * 2 ) ,
V_145 , V_37 % 8 == 0 ? L_17 : L_18 ) ;
}
F_80 ( L_23 ) ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ ) {
if ( F_40 ( V_37 , F_30 ( V_29 -> V_31 ) ) ) {
int V_148 = V_37 / V_49 ;
F_80 ( L_24 ,
F_19 ( V_37 ) , V_37 ,
V_8 [ V_37 ] ,
F_40 ( V_148 , F_30 ( & V_144 -> V_50 ) )
? L_25 : L_26 ,
! F_40 ( V_37 , F_30 ( V_29 -> V_33 ) )
? L_25 : L_27 ,
F_40 ( V_37 , F_30 ( V_142 ) )
? L_25 : L_28 ) ;
}
}
F_125 ( & V_143 , V_22 ) ;
return V_149 ;
}
static void F_126 ( void )
{
int V_150 , V_151 ;
int V_148 , V_152 ;
int V_37 , V_2 ;
int V_6 = F_46 () ;
struct V_28 * V_41 = V_42 ;
struct V_47 * V_47 = F_50 ( V_48 ) ;
unsigned V_153 ;
do {
T_2 V_154 ;
T_2 V_155 ;
struct V_38 * V_39 ;
V_47 -> V_51 = 0 ;
if ( F_127 ( V_156 ) - 1 )
goto V_70;
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_157 ] ) != - 1 ) {
int V_5 = F_10 ( V_2 ) ;
V_148 = V_5 / V_158 ;
V_155 = V_5 % V_158 ;
if ( F_23 ( V_6 , V_41 , V_148 ) & ( 1ULL << V_155 ) ) {
V_39 = F_27 ( V_2 ) ;
if ( V_39 )
F_128 ( V_2 , V_39 ) ;
}
}
V_154 = F_129 ( & V_47 -> V_50 , 0 ) ;
V_150 = F_50 ( V_159 ) ;
V_151 = F_50 ( V_160 ) ;
V_148 = V_150 ;
for ( V_37 = 0 ; V_154 != 0 ; V_37 ++ ) {
T_2 V_161 ;
V_161 = F_130 ( V_154 , V_148 ) ;
if ( V_161 == 0 ) {
V_148 = 0 ;
V_152 = 0 ;
continue;
}
V_148 = F_131 ( V_161 ) ;
V_155 = F_23 ( V_6 , V_41 , V_148 ) ;
V_152 = 0 ;
if ( V_148 == V_150 ) {
if ( V_37 == 0 )
V_152 = V_151 ;
else
V_152 &= ( 1UL << V_151 ) - 1 ;
}
do {
T_2 V_162 ;
int V_40 ;
V_162 = F_130 ( V_155 , V_152 ) ;
if ( V_162 == 0 )
break;
V_152 = F_131 ( V_162 ) ;
V_40 = ( V_148 * V_49 ) + V_152 ;
V_2 = V_8 [ V_40 ] ;
if ( V_2 != - 1 ) {
V_39 = F_27 ( V_2 ) ;
if ( V_39 )
F_128 ( V_2 , V_39 ) ;
}
V_152 = ( V_152 + 1 ) % V_49 ;
F_132 ( V_159 ,
V_152 ? V_148 :
( V_148 + 1 ) % V_49 ) ;
F_132 ( V_160 , V_152 ) ;
} while ( V_152 != 0 );
if ( ( V_148 != V_150 ) || ( V_37 != 0 ) )
V_154 &= ~ ( 1UL << V_148 ) ;
V_148 = ( V_148 + 1 ) % V_49 ;
}
F_4 ( ! F_47 () ) ;
V_153 = F_50 ( V_156 ) ;
F_132 ( V_156 , 0 ) ;
} while ( V_153 != 1 || V_47 -> V_51 );
V_70:
F_52 () ;
}
void F_133 ( struct V_163 * V_164 )
{
struct V_163 * V_165 = F_134 ( V_164 ) ;
F_135 () ;
#ifdef F_136
F_137 () ;
#endif
F_126 () ;
F_138 () ;
F_134 ( V_165 ) ;
}
void F_139 ( void )
{
F_126 () ;
}
void F_140 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_141 ( V_2 ) ;
F_89 ( & V_82 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_5 ( V_2 , V_5 ) ;
F_91 ( & V_82 ) ;
F_142 ( V_2 , F_28 ( 0 ) ) ;
F_143 ( V_2 ) ;
}
static int F_144 ( unsigned V_2 , unsigned V_166 )
{
struct V_167 V_168 ;
int V_5 = F_10 ( V_2 ) ;
if ( ! F_42 ( V_5 ) )
return - 1 ;
if ( F_48 () && ! V_169 )
return - 1 ;
V_168 . V_40 = V_5 ;
V_168 . V_112 = V_166 ;
if ( F_49 ( V_170 , & V_168 ) >= 0 )
F_24 ( V_5 , V_166 ) ;
return 0 ;
}
static int F_145 ( struct V_35 * V_63 , const struct V_171 * V_172 ,
bool V_173 )
{
unsigned V_166 = F_146 ( V_172 ) ;
return F_144 ( V_63 -> V_2 , V_166 ) ;
}
int F_147 ( unsigned int V_2 )
{
int V_174 , V_5 = F_10 ( V_2 ) ;
struct V_28 * V_41 = V_42 ;
if ( ! F_42 ( V_5 ) )
return 1 ;
V_174 = F_51 ( V_5 , F_30 ( V_41 -> V_33 ) ) ;
F_38 ( V_5 , F_30 ( V_41 -> V_31 ) ) ;
if ( ! V_174 )
F_45 ( V_5 ) ;
return 1 ;
}
static void F_148 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
if ( F_42 ( V_5 ) )
F_45 ( V_5 ) ;
}
static void F_78 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
if ( F_42 ( V_5 ) )
F_44 ( V_5 ) ;
}
static void F_149 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
F_75 ( V_63 ) ;
if ( F_42 ( V_5 ) )
F_35 ( V_5 ) ;
}
static void F_150 ( struct V_35 * V_63 )
{
F_78 ( V_63 ) ;
F_149 ( V_63 ) ;
}
static int F_151 ( struct V_35 * V_63 )
{
int V_5 = F_10 ( V_63 -> V_2 ) ;
struct V_28 * V_29 = V_42 ;
int V_25 = 0 ;
if ( F_42 ( V_5 ) ) {
int V_174 ;
V_174 = F_51 ( V_5 , F_30 ( V_29 -> V_33 ) ) ;
F_38 ( V_5 , F_30 ( V_29 -> V_31 ) ) ;
if ( ! V_174 )
F_45 ( V_5 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_152 ( void )
{
int V_18 , V_66 , V_2 , V_19 ;
struct V_175 V_176 ;
struct V_1 * V_3 ;
F_33 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_23 )
continue;
V_18 = V_3 -> V_13 . V_18 . V_18 ;
V_19 = V_3 -> V_13 . V_18 . V_19 ;
V_2 = V_3 -> V_2 ;
if ( ! V_19 )
continue;
V_176 . V_21 = V_85 ;
V_176 . type = V_177 ;
V_176 . V_178 = V_19 ;
V_176 . V_18 = V_18 ;
V_66 = F_72 ( V_179 , & V_176 ) ;
if ( V_66 ) {
F_80 ( V_104 L_29 ,
V_19 , V_2 , V_18 , V_66 ) ;
F_66 ( V_2 ) ;
continue;
}
F_80 ( V_180 L_30 , V_2 , V_176 . V_18 ) ;
F_79 ( V_2 ) ;
}
}
static void F_153 ( unsigned int V_6 )
{
struct V_128 V_129 ;
int V_15 , V_2 , V_5 ;
for ( V_15 = 0 ; V_15 < V_181 ; V_15 ++ ) {
if ( ( V_2 = F_7 ( V_17 , V_6 ) [ V_15 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_15 ) ;
V_129 . V_15 = V_15 ;
V_129 . V_112 = V_6 ;
if ( F_49 ( V_130 ,
& V_129 ) != 0 )
F_84 () ;
V_5 = V_129 . V_40 ;
F_8 ( V_6 , V_2 , V_5 , V_15 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
static void F_154 ( unsigned int V_6 )
{
struct V_108 V_109 ;
int V_11 , V_2 , V_5 ;
for ( V_11 = 0 ; V_11 < V_182 ; V_11 ++ ) {
if ( ( V_2 = F_7 ( V_14 , V_6 ) [ V_11 ] ) == - 1 )
continue;
F_4 ( F_14 ( V_2 ) != V_11 ) ;
V_109 . V_112 = V_6 ;
if ( F_49 ( V_113 ,
& V_109 ) != 0 )
F_84 () ;
V_5 = V_109 . V_40 ;
F_6 ( V_6 , V_2 , V_5 , V_11 ) ;
F_24 ( V_5 , V_6 ) ;
}
}
void F_155 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_42 ( V_5 ) )
F_35 ( V_5 ) ;
}
void F_156 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( F_42 ( V_5 ) )
F_37 ( V_5 ) ;
}
bool F_157 ( int V_2 )
{
int V_5 = F_10 ( V_2 ) ;
bool V_25 = false ;
if ( F_42 ( V_5 ) )
V_25 = F_39 ( V_5 ) ;
return V_25 ;
}
void F_158 ( int V_2 , T_7 V_183 )
{
T_8 V_5 = F_10 ( V_2 ) ;
if ( F_42 ( V_5 ) ) {
struct V_184 V_185 ;
V_185 . V_186 = 1 ;
V_185 . V_183 = V_183 ;
F_159 ( V_185 . V_187 , & V_5 ) ;
if ( F_160 ( V_188 , & V_185 ) != 0 )
F_84 () ;
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
if ( F_72 ( V_60 , & V_59 ) )
return 0 ;
return ! ( V_59 . V_22 & V_189 ) ;
}
void F_163 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_32 () ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
F_44 ( V_5 ) ;
F_33 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_34 (cpu) {
F_153 ( V_6 ) ;
F_154 ( V_6 ) ;
}
F_152 () ;
}
int F_164 ( T_9 V_190 )
{
struct V_191 V_192 ;
V_192 . V_21 = V_85 ;
V_192 . V_178 = V_193 ;
V_192 . V_194 = V_190 ;
return F_165 ( V_195 , & V_192 ) ;
}
void F_166 ( void )
{
int V_66 ;
T_9 V_196 ;
if ( V_169 ) {
V_196 = F_167 ( V_197 ) ;
V_66 = F_164 ( V_196 ) ;
if ( V_66 ) {
F_80 ( V_198 L_31
L_32 ) ;
V_169 = 0 ;
return;
}
F_80 ( V_74 L_33
L_34 ) ;
if ( ! F_21 ( V_197 , V_199 ) )
F_168 ( V_197 ,
V_200 ) ;
}
}
void F_166 ( void ) {}
void T_10 F_169 ( void )
{
int V_37 ;
V_8 = F_170 ( V_124 , sizeof( * V_8 ) ,
V_52 ) ;
F_4 ( ! V_8 ) ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ )
V_8 [ V_37 ] = - 1 ;
F_32 () ;
for ( V_37 = 0 ; V_37 < V_124 ; V_37 ++ )
F_44 ( V_37 ) ;
F_76 = F_22 ;
#ifdef F_136
if ( F_48 () ) {
F_166 () ;
F_171 () ;
F_172 () ;
} else {
int V_66 ;
struct V_201 V_202 ;
F_173 ( F_118 () ) ;
if ( F_60 () )
F_174 () ;
V_26 = ( void * ) F_175 ( V_52 | V_203 ) ;
V_202 . V_204 = F_176 ( V_26 ) ;
V_66 = F_72 ( V_205 , & V_202 ) ;
if ( V_66 != 0 ) {
F_177 ( ( unsigned long ) V_26 ) ;
V_26 = NULL ;
} else
F_76 = F_20 ;
}
#endif
}
