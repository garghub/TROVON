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
F_5 ( V_2 , V_9 | V_10 ) ;
}
static void F_6 ( unsigned V_2 ,
unsigned short V_5 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_11 , V_5 , 0 ) ;
}
static void F_7 ( unsigned V_6 ,
unsigned V_2 ,
unsigned short V_5 ,
enum V_12 V_13 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_14 , V_5 , 0 ) ;
V_3 -> V_15 . V_13 = V_13 ;
F_8 ( V_16 , V_6 ) [ V_13 ] = V_2 ;
}
static void F_9 ( unsigned V_6 ,
unsigned V_2 ,
unsigned short V_5 ,
unsigned short V_17 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_18 , V_5 , 0 ) ;
V_3 -> V_15 . V_17 = V_17 ;
F_8 ( V_19 , V_6 ) [ V_17 ] = V_2 ;
}
static void F_10 ( unsigned V_2 ,
unsigned short V_5 ,
unsigned short V_20 ,
unsigned short V_21 ,
T_1 V_22 ,
unsigned char V_23 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_3 ( V_3 , V_2 , V_24 , V_5 , 0 ) ;
V_3 -> V_15 . V_20 . V_20 = V_20 ;
V_3 -> V_15 . V_20 . V_21 = V_21 ;
V_3 -> V_15 . V_20 . V_22 = V_22 ;
V_3 -> V_15 . V_20 . V_23 = V_23 ;
}
static unsigned int F_11 ( unsigned V_2 )
{
if ( F_12 ( F_13 ( V_2 < 0 || V_2 >= V_25 , L_1 , V_2 ) ) )
return 0 ;
return F_1 ( V_2 ) -> V_5 ;
}
unsigned F_14 ( unsigned int V_5 )
{
return V_8 [ V_5 ] ;
}
static enum V_12 F_15 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_14 ) ;
return V_3 -> V_15 . V_13 ;
}
static unsigned F_16 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_18 ) ;
return V_3 -> V_15 . V_17 ;
}
static unsigned F_17 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 == NULL ) ;
F_4 ( V_3 -> type != V_24 ) ;
return V_3 -> V_15 . V_20 . V_20 ;
}
static enum V_4 F_18 ( unsigned V_2 )
{
return F_1 ( V_2 ) -> type ;
}
static unsigned F_19 ( unsigned V_2 )
{
return F_1 ( V_2 ) -> V_6 ;
}
static unsigned int F_20 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
unsigned V_26 = 0 ;
if ( V_2 != - 1 )
V_26 = F_19 ( V_2 ) ;
return V_26 ;
}
static bool F_21 ( unsigned V_2 )
{
return F_22 ( F_17 ( V_2 ) , V_27 ) ;
}
static bool F_23 ( unsigned V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_24 ) ;
return V_3 -> V_15 . V_20 . V_23 & V_28 ;
}
static inline T_2 F_24 ( unsigned int V_6 ,
struct V_29 * V_30 ,
unsigned int V_31 )
{
return V_30 -> V_32 [ V_31 ] &
F_8 ( V_33 , V_6 ) [ V_31 ] &
~ V_30 -> V_34 [ V_31 ] ;
}
static void F_25 ( unsigned int V_35 , unsigned int V_6 )
{
int V_2 = V_8 [ V_35 ] ;
F_4 ( V_2 == - 1 ) ;
#ifdef F_26
F_27 ( F_28 ( V_2 ) -> V_36 . V_37 , F_29 ( V_6 ) ) ;
#endif
F_30 ( V_35 , F_31 ( F_8 ( V_33 , F_19 ( V_2 ) ) ) ) ;
F_32 ( V_35 , F_31 ( F_8 ( V_33 , V_6 ) ) ) ;
F_1 ( V_2 ) -> V_6 = V_6 ;
}
static void F_33 ( void )
{
int V_38 ;
#ifdef F_26
struct V_1 * V_3 ;
F_34 (info, &xen_irq_list_head, list) {
struct V_39 * V_40 = F_28 ( V_3 -> V_2 ) ;
F_27 ( V_40 -> V_36 . V_37 , F_29 ( 0 ) ) ;
}
#endif
F_35 (i)
memset ( F_8 ( V_33 , V_38 ) ,
( V_38 == 0 ) ? ~ 0 : 0 , V_41 / 8 ) ;
}
static inline void F_36 ( int V_42 )
{
struct V_29 * V_43 = V_44 ;
F_37 ( V_42 , F_31 ( & V_43 -> V_32 [ 0 ] ) ) ;
}
static inline void F_38 ( int V_42 )
{
struct V_29 * V_43 = V_44 ;
F_39 ( V_42 , F_31 ( & V_43 -> V_32 [ 0 ] ) ) ;
}
static inline int F_40 ( int V_42 )
{
struct V_29 * V_43 = V_44 ;
return F_41 ( V_42 , F_31 ( & V_43 -> V_32 [ 0 ] ) ) ;
}
void F_42 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_44 ( V_5 ) ;
}
static void F_45 ( int V_42 )
{
struct V_29 * V_43 = V_44 ;
F_39 ( V_42 , F_31 ( & V_43 -> V_34 [ 0 ] ) ) ;
}
static void F_46 ( int V_42 )
{
struct V_29 * V_43 = V_44 ;
unsigned int V_6 = F_47 () ;
int V_45 = 0 , V_32 = 0 ;
F_4 ( ! F_48 () ) ;
if ( F_12 ( ( V_6 != F_20 ( V_42 ) ) ) )
V_45 = 1 ;
else {
F_37 ( V_42 , F_31 ( & V_43 -> V_34 [ 0 ] ) ) ;
V_32 = F_41 ( V_42 , F_31 ( & V_43 -> V_32 [ 0 ] ) ) ;
if ( F_12 ( V_32 && F_49 () ) ) {
F_39 ( V_42 , F_31 ( & V_43 -> V_34 [ 0 ] ) ) ;
V_45 = 1 ;
}
}
if ( V_45 ) {
struct V_46 V_47 = { . V_42 = V_42 } ;
( void ) F_50 ( V_48 , & V_47 ) ;
} else {
struct V_49 * V_49 = F_51 ( V_50 ) ;
if ( V_32 &&
! F_52 ( V_42 / V_51 ,
F_31 ( & V_49 -> V_52 ) ) )
V_49 -> V_53 = 1 ;
}
F_53 () ;
}
static void F_54 ( unsigned V_2 )
{
struct V_1 * V_3 ;
#ifdef F_26
struct V_39 * V_40 = F_28 ( V_2 ) ;
F_27 ( V_40 -> V_36 . V_37 , F_29 ( 0 ) ) ;
#endif
V_3 = F_55 ( sizeof( * V_3 ) , V_54 ) ;
if ( V_3 == NULL )
F_56 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
V_3 -> V_55 = - 1 ;
F_57 ( V_2 , V_3 ) ;
F_58 ( & V_3 -> V_56 , & V_57 ) ;
}
static int T_3 F_59 ( void )
{
int V_58 = 0 ;
int V_2 ;
#ifdef F_60
if ( F_61 () || F_49 () )
V_58 = F_62 () ;
#endif
V_2 = F_63 ( V_58 , - 1 ) ;
if ( V_2 >= 0 )
F_54 ( V_2 ) ;
return V_2 ;
}
static int T_3 F_64 ( unsigned V_21 )
{
int V_2 ;
if ( F_65 () && ! F_61 () )
return F_59 () ;
if ( V_21 < V_59 )
V_2 = V_21 ;
else
V_2 = F_66 ( V_21 , - 1 ) ;
F_54 ( V_2 ) ;
return V_2 ;
}
static void F_67 ( unsigned V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_69 ( & V_3 -> V_56 ) ;
F_57 ( V_2 , NULL ) ;
F_68 ( V_3 -> V_55 > 0 ) ;
F_70 ( V_3 ) ;
if ( V_2 < V_59 )
return;
F_71 ( V_2 ) ;
}
static void F_72 ( int V_2 )
{
struct V_60 V_61 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_24 ) ;
V_61 . V_2 = F_17 ( V_2 ) ;
if ( F_73 ( V_62 , & V_61 ) )
V_61 . V_23 = 0 ;
V_3 -> V_15 . V_20 . V_23 &= ~ V_28 ;
if ( V_61 . V_23 & V_63 )
V_3 -> V_15 . V_20 . V_23 |= V_28 ;
}
static bool F_74 ( int V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
return V_40 && V_40 -> V_64 == NULL ;
}
static void F_75 ( struct V_36 * V_65 )
{
int V_5 = F_11 ( V_65 -> V_2 ) ;
struct V_66 V_67 = { . V_2 = F_17 (data->irq) } ;
int V_68 = 0 ;
F_76 ( V_65 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
if ( F_77 ( V_65 -> V_2 ) ) {
V_68 = F_73 ( V_69 , & V_67 ) ;
F_68 ( V_68 ) ;
}
}
static void F_78 ( struct V_36 * V_65 )
{
F_79 ( V_65 ) ;
F_75 ( V_65 ) ;
}
static unsigned int F_80 ( unsigned int V_2 )
{
struct V_70 V_71 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_11 ( V_2 ) ;
int V_68 ;
F_4 ( V_3 -> type != V_24 ) ;
if ( F_43 ( V_5 ) )
goto V_72;
V_71 . V_20 = F_17 ( V_2 ) ;
V_71 . V_23 = V_3 -> V_15 . V_20 . V_23 & V_73 ?
V_74 : 0 ;
V_68 = F_50 ( V_75 , & V_71 ) ;
if ( V_68 != 0 ) {
if ( ! F_74 ( V_2 ) )
F_81 ( L_3 , V_2 ) ;
return 0 ;
}
V_5 = V_71 . V_42 ;
F_72 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_25 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_72:
F_46 ( V_5 ) ;
F_75 ( F_82 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_36 * V_65 )
{
return F_80 ( V_65 -> V_2 ) ;
}
static void F_84 ( struct V_36 * V_65 )
{
struct V_76 V_77 ;
unsigned int V_2 = V_65 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_11 ( V_2 ) ;
F_4 ( V_3 -> type != V_24 ) ;
if ( ! F_43 ( V_5 ) )
return;
F_45 ( V_5 ) ;
V_77 . V_42 = V_5 ;
if ( F_50 ( V_78 , & V_77 ) != 0 )
F_85 () ;
F_25 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_86 ( struct V_36 * V_65 )
{
F_83 ( V_65 ) ;
}
static void F_87 ( struct V_36 * V_65 )
{
F_79 ( V_65 ) ;
}
int F_88 ( unsigned V_21 )
{
struct V_1 * V_3 ;
F_34 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_24 )
continue;
if ( V_3 -> V_15 . V_20 . V_21 == V_21 )
return V_3 -> V_2 ;
}
return - 1 ;
}
int F_89 ( unsigned V_21 ,
unsigned V_20 , int V_79 , char * V_80 )
{
int V_2 = - 1 ;
struct V_81 V_82 ;
F_90 ( & V_83 ) ;
V_2 = F_88 ( V_21 ) ;
if ( V_2 != - 1 ) {
F_81 ( L_4 ,
V_84 , V_2 , V_21 ) ;
goto V_72;
}
V_2 = F_64 ( V_21 ) ;
if ( V_2 < 0 )
goto V_72;
V_82 . V_2 = V_2 ;
V_82 . V_85 = 0 ;
if ( F_61 () &&
F_73 ( V_86 , & V_82 ) ) {
F_67 ( V_2 ) ;
V_2 = - V_87 ;
goto V_72;
}
F_10 ( V_2 , 0 , V_20 , V_21 , V_88 ,
V_79 ? V_73 : 0 ) ;
F_72 ( V_2 ) ;
if ( V_79 )
F_91 ( V_2 , & V_89 ,
V_90 , V_80 ) ;
else
F_91 ( V_2 , & V_89 ,
V_91 , V_80 ) ;
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
}
int F_93 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
int V_68 ;
struct V_96 V_97 ;
V_97 . type = V_98 ;
V_68 = F_73 ( V_99 , & V_97 ) ;
F_94 ( V_68 == - V_100 ,
L_5 ) ;
return V_68 ? - 1 : V_97 . V_20 ;
}
int F_95 ( struct V_92 * V_93 , struct V_94 * V_95 ,
int V_20 , const char * V_80 , T_4 V_22 )
{
int V_2 , V_26 ;
F_90 ( & V_83 ) ;
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_72;
F_91 ( V_2 , & V_89 , V_91 ,
V_80 ) ;
F_10 ( V_2 , 0 , V_20 , 0 , V_22 , 0 ) ;
V_26 = F_96 ( V_2 , V_95 ) ;
if ( V_26 < 0 )
goto V_101;
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
V_101:
F_92 ( & V_83 ) ;
F_67 ( V_2 ) ;
return V_26 ;
}
int F_97 ( int V_2 )
{
struct V_39 * V_40 ;
struct V_102 V_103 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_68 = - V_104 ;
F_90 ( & V_83 ) ;
V_40 = F_28 ( V_2 ) ;
if ( ! V_40 )
goto V_72;
if ( F_61 () ) {
V_103 . V_20 = V_3 -> V_15 . V_20 . V_20 ;
V_103 . V_22 = V_3 -> V_15 . V_20 . V_22 ;
V_68 = F_73 ( V_105 , & V_103 ) ;
if ( ( V_68 == - V_106 && V_3 -> V_15 . V_20 . V_22 != V_88 ) )
F_81 ( L_6 ,
V_3 -> V_15 . V_20 . V_22 , V_3 -> V_15 . V_20 . V_20 ) ;
else if ( V_68 ) {
F_98 ( L_7 , V_68 ) ;
goto V_72;
}
}
F_67 ( V_2 ) ;
V_72:
F_92 ( & V_83 ) ;
return V_68 ;
}
int F_99 ( unsigned V_20 )
{
int V_2 ;
struct V_1 * V_3 ;
F_90 ( & V_83 ) ;
F_34 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_24 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_15 . V_20 . V_20 == V_20 )
goto V_72;
}
V_2 = - 1 ;
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
}
int F_100 ( unsigned V_2 )
{
return F_17 ( V_2 ) ;
}
int F_101 ( unsigned int V_5 )
{
int V_2 ;
F_90 ( & V_83 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_72;
F_91 ( V_2 , & V_107 ,
V_91 , L_8 ) ;
F_6 ( V_2 , V_5 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_11 ) ;
}
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
}
static int F_102 ( unsigned int V_13 , unsigned int V_6 )
{
struct V_108 V_109 ;
int V_5 , V_2 ;
F_90 ( & V_83 ) ;
V_2 = F_8 ( V_16 , V_6 ) [ V_13 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_72;
F_91 ( V_2 , & V_110 ,
V_111 , L_9 ) ;
V_109 . V_112 = V_6 ;
if ( F_50 ( V_113 ,
& V_109 ) != 0 )
F_85 () ;
V_5 = V_109 . V_42 ;
F_7 ( V_6 , V_2 , V_5 , V_13 ) ;
F_25 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_14 ) ;
}
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
}
static int F_103 ( unsigned int V_114 ,
unsigned int V_115 )
{
struct V_116 V_117 ;
int V_118 ;
V_117 . V_119 = V_114 ;
V_117 . V_115 = V_115 ;
V_118 = F_50 ( V_120 ,
& V_117 ) ;
return V_118 ? : F_101 ( V_117 . V_121 ) ;
}
static int F_104 ( unsigned int V_17 , unsigned int V_6 )
{
struct V_122 V_123 ;
int V_42 , V_68 = - V_104 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
for ( V_42 = 0 ; V_42 <= V_41 ; V_42 ++ ) {
V_123 . V_124 = V_88 ;
V_123 . V_42 = V_42 ;
V_68 = F_50 ( V_125 , & V_123 ) ;
if ( V_68 < 0 )
continue;
if ( V_123 . V_123 != V_126 )
continue;
if ( V_123 . V_15 . V_17 == V_17 && V_123 . V_112 == V_6 ) {
V_68 = V_42 ;
break;
}
}
return V_68 ;
}
int F_105 ( unsigned int V_17 , unsigned int V_6 )
{
struct V_127 V_128 ;
int V_5 , V_2 , V_26 ;
F_90 ( & V_83 ) ;
V_2 = F_8 ( V_19 , V_6 ) [ V_17 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_72;
F_91 ( V_2 , & V_110 ,
V_111 , L_10 ) ;
V_128 . V_17 = V_17 ;
V_128 . V_112 = V_6 ;
V_26 = F_50 ( V_129 ,
& V_128 ) ;
if ( V_26 == 0 )
V_5 = V_128 . V_42 ;
else {
if ( V_26 == - V_130 )
V_26 = F_104 ( V_17 , V_6 ) ;
F_4 ( V_26 < 0 ) ;
V_5 = V_26 ;
}
F_9 ( V_6 , V_2 , V_5 , V_17 ) ;
F_25 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_18 ) ;
}
V_72:
F_92 ( & V_83 ) ;
return V_2 ;
}
static void F_106 ( unsigned int V_2 )
{
struct V_76 V_77 ;
int V_5 = F_11 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_90 ( & V_83 ) ;
if ( V_3 -> V_55 > 0 ) {
V_3 -> V_55 -- ;
if ( V_3 -> V_55 != 0 )
goto V_131;
}
if ( F_43 ( V_5 ) ) {
V_77 . V_42 = V_5 ;
if ( F_50 ( V_78 , & V_77 ) != 0 )
F_85 () ;
switch ( F_18 ( V_2 ) ) {
case V_18 :
F_8 ( V_19 , F_20 ( V_5 ) )
[ F_16 ( V_2 ) ] = - 1 ;
break;
case V_14 :
F_8 ( V_16 , F_20 ( V_5 ) )
[ F_15 ( V_2 ) ] = - 1 ;
break;
default:
break;
}
F_25 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
}
F_4 ( F_1 ( V_2 ) -> type == V_7 ) ;
F_67 ( V_2 ) ;
V_131:
F_92 ( & V_83 ) ;
}
int F_107 ( unsigned int V_5 ,
T_5 V_132 ,
unsigned long V_133 ,
const char * V_134 , void * V_135 )
{
int V_2 , V_136 ;
V_2 = F_101 ( V_5 ) ;
if ( V_2 < 0 )
return V_2 ;
V_136 = F_108 ( V_2 , V_132 , V_133 , V_134 , V_135 ) ;
if ( V_136 != 0 ) {
F_106 ( V_2 ) ;
return V_136 ;
}
return V_2 ;
}
int F_109 ( unsigned int V_114 ,
unsigned int V_115 ,
T_5 V_132 ,
unsigned long V_133 ,
const char * V_134 ,
void * V_135 )
{
int V_2 , V_136 ;
V_2 = F_103 ( V_114 , V_115 ) ;
if ( V_2 < 0 )
return V_2 ;
V_136 = F_108 ( V_2 , V_132 , V_133 , V_134 , V_135 ) ;
if ( V_136 != 0 ) {
F_106 ( V_2 ) ;
return V_136 ;
}
return V_2 ;
}
int F_110 ( unsigned int V_17 , unsigned int V_6 ,
T_5 V_132 ,
unsigned long V_133 , const char * V_134 , void * V_135 )
{
int V_2 , V_136 ;
V_2 = F_105 ( V_17 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_136 = F_108 ( V_2 , V_132 , V_133 , V_134 , V_135 ) ;
if ( V_136 != 0 ) {
F_106 ( V_2 ) ;
return V_136 ;
}
return V_2 ;
}
int F_111 ( enum V_12 V_13 ,
unsigned int V_6 ,
T_5 V_132 ,
unsigned long V_133 ,
const char * V_134 ,
void * V_135 )
{
int V_2 , V_136 ;
V_2 = F_102 ( V_13 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_133 |= V_137 | V_138 | V_139 ;
V_136 = F_108 ( V_2 , V_132 , V_133 , V_134 , V_135 ) ;
if ( V_136 != 0 ) {
F_106 ( V_2 ) ;
return V_136 ;
}
return V_2 ;
}
void F_112 ( unsigned int V_2 , void * V_135 )
{
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_113 ( V_2 , V_135 ) ;
F_106 ( V_2 ) ;
}
int F_114 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_104 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_104 ;
F_68 ( V_3 -> V_55 != - 1 ) ;
V_3 -> V_55 = 1 ;
return 0 ;
}
int F_115 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_118 = - V_104 ;
if ( V_5 >= V_41 )
return - V_140 ;
F_90 ( & V_83 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 )
goto V_131;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
goto V_131;
V_118 = - V_140 ;
if ( V_3 -> V_55 <= 0 )
goto V_131;
V_3 -> V_55 ++ ;
V_118 = 0 ;
V_131:
F_92 ( & V_83 ) ;
return V_118 ;
}
void F_116 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_68 ( V_2 == - 1 ) )
return;
F_106 ( V_2 ) ;
}
void F_117 ( unsigned int V_6 , enum V_12 V_85 )
{
int V_2 = F_8 ( V_16 , V_6 ) [ V_85 ] ;
F_4 ( V_2 < 0 ) ;
F_42 ( V_2 ) ;
}
T_6 F_118 ( int V_2 , void * V_135 )
{
struct V_29 * V_30 = V_44 ;
int V_6 = F_119 () ;
T_2 * V_141 = F_8 ( V_33 , V_6 ) ;
int V_38 ;
unsigned long V_23 ;
static F_120 ( V_142 ) ;
struct V_49 * V_143 ;
F_121 ( & V_142 , V_23 ) ;
F_122 ( L_11 , V_6 ) ;
F_123 (i) {
int V_144 ;
V_143 = F_8 ( V_50 , V_38 ) ;
V_144 = ( F_124 () && V_38 == V_6 )
? F_125 ( F_124 () )
: V_143 -> V_145 ;
F_122 ( L_12 V_146 L_13 , V_38 ,
V_144 , V_143 -> V_53 ,
( int ) ( sizeof( V_143 -> V_52 ) * 2 ) ,
V_143 -> V_52 ) ;
}
V_143 = F_8 ( V_50 , V_6 ) ;
F_122 ( L_14 ) ;
for ( V_38 = F_126 ( V_30 -> V_32 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_122 ( L_15 V_146 L_16 ,
( int ) sizeof( V_30 -> V_32 [ 0 ] ) * 2 ,
V_30 -> V_32 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_122 ( L_19 ) ;
for ( V_38 = F_126 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_122 ( L_15 V_146 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_30 -> V_34 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_122 ( L_20 ) ;
for ( V_38 = F_126 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_122 ( L_15 V_146 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_30 -> V_32 [ V_38 ] & ~ V_30 -> V_34 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_122 ( L_21 , V_6 ) ;
for ( V_38 = ( V_41 / V_51 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_122 ( L_15 V_146 L_16 , ( int ) ( sizeof( V_141 [ 0 ] ) * 2 ) ,
V_141 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_122 ( L_22 ) ;
for ( V_38 = F_126 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- ) {
T_2 V_144 = V_30 -> V_32 [ V_38 ]
& ~ V_30 -> V_34 [ V_38 ]
& V_141 [ V_38 ] ;
F_122 ( L_15 V_146 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_144 , V_38 % 8 == 0 ? L_17 : L_18 ) ;
}
F_122 ( L_23 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ ) {
if ( F_41 ( V_38 , F_31 ( V_30 -> V_32 ) ) ) {
int V_147 = V_38 / V_51 ;
F_122 ( L_24 ,
F_20 ( V_38 ) , V_38 ,
V_8 [ V_38 ] ,
F_41 ( V_147 , F_31 ( & V_143 -> V_52 ) )
? L_25 : L_26 ,
! F_41 ( V_38 , F_31 ( V_30 -> V_34 ) )
? L_25 : L_27 ,
F_41 ( V_38 , F_31 ( V_141 ) )
? L_25 : L_28 ) ;
}
}
F_127 ( & V_142 , V_23 ) ;
return V_148 ;
}
static void F_128 ( void )
{
int V_149 , V_150 ;
int V_147 , V_151 ;
int V_38 , V_2 ;
int V_6 = F_47 () ;
struct V_29 * V_43 = V_44 ;
struct V_49 * V_49 = F_51 ( V_50 ) ;
unsigned V_152 ;
do {
T_2 V_153 ;
T_2 V_154 ;
struct V_39 * V_40 ;
V_49 -> V_53 = 0 ;
if ( F_129 ( V_155 ) - 1 )
goto V_72;
if ( ( V_2 = F_8 ( V_19 , V_6 ) [ V_156 ] ) != - 1 ) {
int V_5 = F_11 ( V_2 ) ;
V_147 = V_5 / V_157 ;
V_154 = V_5 % V_157 ;
if ( F_24 ( V_6 , V_43 , V_147 ) & ( 1ULL << V_154 ) ) {
V_40 = F_28 ( V_2 ) ;
if ( V_40 )
F_130 ( V_2 , V_40 ) ;
}
}
V_153 = F_131 ( & V_49 -> V_52 , 0 ) ;
V_149 = F_51 ( V_158 ) ;
V_150 = F_51 ( V_159 ) ;
V_147 = V_149 ;
for ( V_38 = 0 ; V_153 != 0 ; V_38 ++ ) {
T_2 V_160 ;
V_160 = F_132 ( V_153 , V_147 ) ;
if ( V_160 == 0 ) {
V_147 = 0 ;
V_151 = 0 ;
continue;
}
V_147 = F_133 ( V_160 ) ;
V_154 = F_24 ( V_6 , V_43 , V_147 ) ;
V_151 = 0 ;
if ( V_147 == V_149 ) {
if ( V_38 == 0 )
V_151 = V_150 ;
else
V_151 &= ( 1UL << V_150 ) - 1 ;
}
do {
T_2 V_161 ;
int V_42 ;
V_161 = F_132 ( V_154 , V_151 ) ;
if ( V_161 == 0 )
break;
V_151 = F_133 ( V_161 ) ;
V_42 = ( V_147 * V_51 ) + V_151 ;
V_2 = V_8 [ V_42 ] ;
if ( V_2 != - 1 ) {
V_40 = F_28 ( V_2 ) ;
if ( V_40 )
F_130 ( V_2 , V_40 ) ;
}
V_151 = ( V_151 + 1 ) % V_51 ;
F_134 ( V_158 ,
V_151 ? V_147 :
( V_147 + 1 ) % V_51 ) ;
F_134 ( V_159 , V_151 ) ;
} while ( V_151 != 0 );
if ( ( V_147 != V_149 ) || ( V_38 != 0 ) )
V_153 &= ~ ( 1UL << V_147 ) ;
V_147 = ( V_147 + 1 ) % V_51 ;
}
F_4 ( ! F_48 () ) ;
V_152 = F_51 ( V_155 ) ;
F_134 ( V_155 , 0 ) ;
} while ( V_152 != 1 || V_49 -> V_53 );
V_72:
F_53 () ;
}
void F_135 ( struct V_162 * V_163 )
{
struct V_162 * V_164 = F_136 ( V_163 ) ;
F_137 () ;
#ifdef F_138
F_139 () ;
#endif
F_128 () ;
F_140 () ;
F_136 ( V_164 ) ;
}
void F_141 ( void )
{
F_128 () ;
}
void F_142 ( int V_5 , int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_143 ( V_2 ) ;
F_90 ( & V_83 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_6 ( V_2 , V_5 ) ;
F_92 ( & V_83 ) ;
F_144 ( V_2 , F_29 ( 0 ) ) ;
F_145 ( V_2 ) ;
}
static int F_146 ( unsigned V_2 , unsigned V_165 )
{
struct V_29 * V_43 = V_44 ;
struct V_166 V_167 ;
int V_5 = F_11 ( V_2 ) ;
int V_168 ;
if ( ! F_43 ( V_5 ) )
return - 1 ;
if ( F_49 () && ! V_169 )
return - 1 ;
V_167 . V_42 = V_5 ;
V_167 . V_112 = V_165 ;
V_168 = F_52 ( V_5 , F_31 ( V_43 -> V_34 ) ) ;
if ( F_50 ( V_170 , & V_167 ) >= 0 )
F_25 ( V_5 , V_165 ) ;
if ( ! V_168 )
F_46 ( V_5 ) ;
return 0 ;
}
static int F_147 ( struct V_36 * V_65 , const struct V_171 * V_172 ,
bool V_173 )
{
unsigned V_165 = F_148 ( V_172 ) ;
return F_146 ( V_65 -> V_2 , V_165 ) ;
}
int F_149 ( unsigned int V_2 )
{
int V_168 , V_5 = F_11 ( V_2 ) ;
struct V_29 * V_43 = V_44 ;
if ( ! F_43 ( V_5 ) )
return 1 ;
V_168 = F_52 ( V_5 , F_31 ( V_43 -> V_34 ) ) ;
F_39 ( V_5 , F_31 ( V_43 -> V_32 ) ) ;
if ( ! V_168 )
F_46 ( V_5 ) ;
return 1 ;
}
static void F_150 ( struct V_36 * V_65 )
{
int V_5 = F_11 ( V_65 -> V_2 ) ;
if ( F_43 ( V_5 ) )
F_46 ( V_5 ) ;
}
static void F_79 ( struct V_36 * V_65 )
{
int V_5 = F_11 ( V_65 -> V_2 ) ;
if ( F_43 ( V_5 ) )
F_45 ( V_5 ) ;
}
static void F_151 ( struct V_36 * V_65 )
{
int V_5 = F_11 ( V_65 -> V_2 ) ;
F_76 ( V_65 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
}
static void F_152 ( struct V_36 * V_65 )
{
F_79 ( V_65 ) ;
F_151 ( V_65 ) ;
}
static int F_153 ( struct V_36 * V_65 )
{
int V_5 = F_11 ( V_65 -> V_2 ) ;
struct V_29 * V_30 = V_44 ;
int V_26 = 0 ;
if ( F_43 ( V_5 ) ) {
int V_168 ;
V_168 = F_52 ( V_5 , F_31 ( V_30 -> V_34 ) ) ;
F_39 ( V_5 , F_31 ( V_30 -> V_32 ) ) ;
if ( ! V_168 )
F_46 ( V_5 ) ;
V_26 = 1 ;
}
return V_26 ;
}
static void F_154 ( void )
{
int V_20 , V_68 , V_2 , V_21 ;
struct V_174 V_175 ;
struct V_1 * V_3 ;
F_34 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_24 )
continue;
V_20 = V_3 -> V_15 . V_20 . V_20 ;
V_21 = V_3 -> V_15 . V_20 . V_21 ;
V_2 = V_3 -> V_2 ;
if ( ! V_21 )
continue;
V_175 . V_22 = V_88 ;
V_175 . type = V_176 ;
V_175 . V_177 = V_21 ;
V_175 . V_20 = V_20 ;
V_68 = F_73 ( V_178 , & V_175 ) ;
if ( V_68 ) {
F_98 ( L_29 ,
V_21 , V_2 , V_20 , V_68 ) ;
F_67 ( V_2 ) ;
continue;
}
F_122 ( V_179 L_30 , V_2 , V_175 . V_20 ) ;
F_80 ( V_2 ) ;
}
}
static void F_155 ( unsigned int V_6 )
{
struct V_127 V_128 ;
int V_17 , V_2 , V_5 ;
for ( V_17 = 0 ; V_17 < V_180 ; V_17 ++ ) {
if ( ( V_2 = F_8 ( V_19 , V_6 ) [ V_17 ] ) == - 1 )
continue;
F_4 ( F_16 ( V_2 ) != V_17 ) ;
V_128 . V_17 = V_17 ;
V_128 . V_112 = V_6 ;
if ( F_50 ( V_129 ,
& V_128 ) != 0 )
F_85 () ;
V_5 = V_128 . V_42 ;
F_9 ( V_6 , V_2 , V_5 , V_17 ) ;
F_25 ( V_5 , V_6 ) ;
}
}
static void F_156 ( unsigned int V_6 )
{
struct V_108 V_109 ;
int V_13 , V_2 , V_5 ;
for ( V_13 = 0 ; V_13 < V_181 ; V_13 ++ ) {
if ( ( V_2 = F_8 ( V_16 , V_6 ) [ V_13 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_13 ) ;
V_109 . V_112 = V_6 ;
if ( F_50 ( V_113 ,
& V_109 ) != 0 )
F_85 () ;
V_5 = V_109 . V_42 ;
F_7 ( V_6 , V_2 , V_5 , V_13 ) ;
F_25 ( V_5 , V_6 ) ;
}
}
void F_157 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
}
void F_158 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_38 ( V_5 ) ;
}
bool F_159 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
bool V_26 = false ;
if ( F_43 ( V_5 ) )
V_26 = F_40 ( V_5 ) ;
return V_26 ;
}
void F_160 ( int V_2 , T_7 V_182 )
{
T_8 V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) ) {
struct V_183 V_184 ;
V_184 . V_185 = 1 ;
V_184 . V_182 = V_182 ;
F_161 ( V_184 . V_186 , & V_5 ) ;
if ( F_162 ( V_187 , & V_184 ) != 0 )
F_85 () ;
}
}
void F_163 ( int V_2 )
{
F_160 ( V_2 , 0 ) ;
}
int F_164 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_60 V_61 ;
if ( F_68 ( ! V_3 ) )
return - V_104 ;
V_61 . V_2 = V_3 -> V_15 . V_20 . V_20 ;
if ( F_73 ( V_62 , & V_61 ) )
return 0 ;
return ! ( V_61 . V_23 & V_188 ) ;
}
void F_165 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_33 () ;
for ( V_5 = 0 ; V_5 < V_41 ; V_5 ++ )
F_45 ( V_5 ) ;
F_34 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_41 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_35 (cpu) {
F_155 ( V_6 ) ;
F_156 ( V_6 ) ;
}
F_154 () ;
}
int F_166 ( T_9 V_189 )
{
struct V_190 V_191 ;
V_191 . V_22 = V_88 ;
V_191 . V_177 = V_192 ;
V_191 . V_193 = V_189 ;
return F_167 ( V_194 , & V_191 ) ;
}
void F_168 ( void )
{
int V_68 ;
T_9 V_195 ;
if ( V_169 ) {
V_195 = F_169 ( V_196 ) ;
V_68 = F_166 ( V_195 ) ;
if ( V_68 ) {
F_170 ( L_31 ) ;
V_169 = 0 ;
return;
}
F_81 ( L_32 ) ;
if ( ! F_22 ( V_196 , V_197 ) )
F_171 ( V_196 ,
V_198 ) ;
}
}
void F_168 ( void ) {}
void T_10 F_172 ( void )
{
int V_38 ;
V_8 = F_173 ( V_41 , sizeof( * V_8 ) ,
V_54 ) ;
F_4 ( ! V_8 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
V_8 [ V_38 ] = - 1 ;
F_33 () ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
F_45 ( V_38 ) ;
F_77 = F_23 ;
#ifdef F_138
if ( F_49 () ) {
F_168 () ;
F_174 () ;
F_175 () ;
} else {
int V_68 ;
struct V_199 V_200 ;
F_176 ( F_119 () ) ;
if ( F_61 () )
F_177 () ;
V_27 = ( void * ) F_178 ( V_54 | V_201 ) ;
V_200 . V_202 = F_179 ( V_27 ) ;
V_68 = F_73 ( V_203 , & V_200 ) ;
if ( V_68 != 0 ) {
F_180 ( ( unsigned long ) V_27 ) ;
V_27 = NULL ;
} else
F_77 = F_21 ;
}
#endif
}
