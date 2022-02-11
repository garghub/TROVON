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
( V_38 == 0 ) ? ~ 0 : 0 , sizeof( * F_8 ( V_33 , V_38 ) ) ) ;
}
static inline void F_36 ( int V_41 )
{
struct V_29 * V_42 = V_43 ;
F_37 ( V_41 , F_31 ( & V_42 -> V_32 [ 0 ] ) ) ;
}
static inline void F_38 ( int V_41 )
{
struct V_29 * V_42 = V_43 ;
F_39 ( V_41 , F_31 ( & V_42 -> V_32 [ 0 ] ) ) ;
}
static inline int F_40 ( int V_41 )
{
struct V_29 * V_42 = V_43 ;
return F_41 ( V_41 , F_31 ( & V_42 -> V_32 [ 0 ] ) ) ;
}
void F_42 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_44 ( V_5 ) ;
}
static void F_45 ( int V_41 )
{
struct V_29 * V_42 = V_43 ;
F_39 ( V_41 , F_31 ( & V_42 -> V_34 [ 0 ] ) ) ;
}
static void F_46 ( int V_41 )
{
struct V_29 * V_42 = V_43 ;
unsigned int V_6 = F_47 () ;
int V_44 = 0 , V_32 = 0 ;
F_4 ( ! F_48 () ) ;
if ( F_12 ( ( V_6 != F_20 ( V_41 ) ) ) )
V_44 = 1 ;
else {
F_37 ( V_41 , F_31 ( & V_42 -> V_34 [ 0 ] ) ) ;
V_32 = F_41 ( V_41 , F_31 ( & V_42 -> V_32 [ 0 ] ) ) ;
if ( F_12 ( V_32 && F_49 () ) ) {
F_39 ( V_41 , F_31 ( & V_42 -> V_34 [ 0 ] ) ) ;
V_44 = 1 ;
}
}
if ( V_44 ) {
struct V_45 V_46 = { . V_41 = V_41 } ;
( void ) F_50 ( V_47 , & V_46 ) ;
} else {
struct V_48 * V_48 = F_51 ( V_49 ) ;
if ( V_32 &&
! F_52 ( V_41 / V_50 ,
F_31 ( & V_48 -> V_51 ) ) )
V_48 -> V_52 = 1 ;
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
V_3 = F_55 ( sizeof( * V_3 ) , V_53 ) ;
if ( V_3 == NULL )
F_56 ( L_2 , V_2 ) ;
V_3 -> type = V_7 ;
V_3 -> V_54 = - 1 ;
F_57 ( V_2 , V_3 ) ;
F_58 ( & V_3 -> V_55 , & V_56 ) ;
}
static int T_3 F_59 ( void )
{
int V_57 = 0 ;
int V_2 ;
#ifdef F_60
if ( F_61 () || F_49 () )
V_57 = F_62 () ;
#endif
V_2 = F_63 ( V_57 , - 1 ) ;
if ( V_2 >= 0 )
F_54 ( V_2 ) ;
return V_2 ;
}
static int T_3 F_64 ( unsigned V_21 )
{
int V_2 ;
if ( F_65 () && ! F_61 () )
return F_59 () ;
if ( V_21 < V_58 )
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
F_69 ( & V_3 -> V_55 ) ;
F_57 ( V_2 , NULL ) ;
F_68 ( V_3 -> V_54 > 0 ) ;
F_70 ( V_3 ) ;
if ( V_2 < V_58 )
return;
F_71 ( V_2 ) ;
}
static void F_72 ( int V_2 )
{
struct V_59 V_60 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_4 ( V_3 -> type != V_24 ) ;
V_60 . V_2 = F_17 ( V_2 ) ;
if ( F_73 ( V_61 , & V_60 ) )
V_60 . V_23 = 0 ;
V_3 -> V_15 . V_20 . V_23 &= ~ V_28 ;
if ( V_60 . V_23 & V_62 )
V_3 -> V_15 . V_20 . V_23 |= V_28 ;
}
static bool F_74 ( int V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
return V_40 && V_40 -> V_63 == NULL ;
}
static void F_75 ( struct V_36 * V_64 )
{
int V_5 = F_11 ( V_64 -> V_2 ) ;
struct V_65 V_66 = { . V_2 = F_17 (data->irq) } ;
int V_67 = 0 ;
F_76 ( V_64 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
if ( F_77 ( V_64 -> V_2 ) ) {
V_67 = F_73 ( V_68 , & V_66 ) ;
F_68 ( V_67 ) ;
}
}
static void F_78 ( struct V_36 * V_64 )
{
F_79 ( V_64 ) ;
F_75 ( V_64 ) ;
}
static unsigned int F_80 ( unsigned int V_2 )
{
struct V_69 V_70 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_11 ( V_2 ) ;
int V_67 ;
F_4 ( V_3 -> type != V_24 ) ;
if ( F_43 ( V_5 ) )
goto V_71;
V_70 . V_20 = F_17 ( V_2 ) ;
V_70 . V_23 = V_3 -> V_15 . V_20 . V_23 & V_72 ?
V_73 : 0 ;
V_67 = F_50 ( V_74 , & V_70 ) ;
if ( V_67 != 0 ) {
if ( ! F_74 ( V_2 ) )
F_81 ( V_75 L_3 ,
V_2 ) ;
return 0 ;
}
V_5 = V_70 . V_41 ;
F_72 ( V_2 ) ;
V_8 [ V_5 ] = V_2 ;
F_25 ( V_5 , 0 ) ;
V_3 -> V_5 = V_5 ;
V_71:
F_46 ( V_5 ) ;
F_75 ( F_82 ( V_2 ) ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_36 * V_64 )
{
return F_80 ( V_64 -> V_2 ) ;
}
static void F_84 ( struct V_36 * V_64 )
{
struct V_76 V_77 ;
unsigned int V_2 = V_64 -> V_2 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_5 = F_11 ( V_2 ) ;
F_4 ( V_3 -> type != V_24 ) ;
if ( ! F_43 ( V_5 ) )
return;
F_45 ( V_5 ) ;
V_77 . V_41 = V_5 ;
if ( F_50 ( V_78 , & V_77 ) != 0 )
F_85 () ;
F_25 ( V_5 , 0 ) ;
V_8 [ V_5 ] = - 1 ;
V_3 -> V_5 = 0 ;
}
static void F_86 ( struct V_36 * V_64 )
{
F_83 ( V_64 ) ;
}
static void F_87 ( struct V_36 * V_64 )
{
F_79 ( V_64 ) ;
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
F_81 ( V_75 L_4 ,
V_2 , V_21 ) ;
goto V_71;
}
V_2 = F_64 ( V_21 ) ;
if ( V_2 < 0 )
goto V_71;
V_82 . V_2 = V_2 ;
V_82 . V_84 = 0 ;
if ( F_61 () &&
F_73 ( V_85 , & V_82 ) ) {
F_67 ( V_2 ) ;
V_2 = - V_86 ;
goto V_71;
}
F_10 ( V_2 , 0 , V_20 , V_21 , V_87 ,
V_79 ? V_72 : 0 ) ;
F_72 ( V_2 ) ;
if ( V_79 )
F_91 ( V_2 , & V_88 ,
V_89 , V_80 ) ;
else
F_91 ( V_2 , & V_88 ,
V_90 , V_80 ) ;
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
}
int F_93 ( struct V_91 * V_92 , struct V_93 * V_94 )
{
int V_67 ;
struct V_95 V_96 ;
V_96 . type = V_97 ;
V_67 = F_73 ( V_98 , & V_96 ) ;
F_94 ( V_67 == - V_99 ,
L_5 ) ;
return V_67 ? - 1 : V_96 . V_20 ;
}
int F_95 ( struct V_91 * V_92 , struct V_93 * V_94 ,
int V_20 , const char * V_80 , T_4 V_22 )
{
int V_2 , V_26 ;
F_90 ( & V_83 ) ;
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_71;
F_91 ( V_2 , & V_88 , V_90 ,
V_80 ) ;
F_10 ( V_2 , 0 , V_20 , 0 , V_22 , 0 ) ;
V_26 = F_96 ( V_2 , V_94 ) ;
if ( V_26 < 0 )
goto V_100;
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
V_100:
F_92 ( & V_83 ) ;
F_67 ( V_2 ) ;
return V_26 ;
}
int F_97 ( int V_2 )
{
struct V_39 * V_40 ;
struct V_101 V_102 ;
struct V_1 * V_3 = F_1 ( V_2 ) ;
int V_67 = - V_103 ;
F_90 ( & V_83 ) ;
V_40 = F_28 ( V_2 ) ;
if ( ! V_40 )
goto V_71;
if ( F_61 () ) {
V_102 . V_20 = V_3 -> V_15 . V_20 . V_20 ;
V_102 . V_22 = V_3 -> V_15 . V_20 . V_22 ;
V_67 = F_73 ( V_104 , & V_102 ) ;
if ( ( V_67 == - V_105 && V_3 -> V_15 . V_20 . V_22 != V_87 ) )
F_81 ( V_75 L_6 ,
V_3 -> V_15 . V_20 . V_22 , V_3 -> V_15 . V_20 . V_20 ) ;
else if ( V_67 ) {
F_81 ( V_106 L_7 , V_67 ) ;
goto V_71;
}
}
F_67 ( V_2 ) ;
V_71:
F_92 ( & V_83 ) ;
return V_67 ;
}
int F_98 ( unsigned V_20 )
{
int V_2 ;
struct V_1 * V_3 ;
F_90 ( & V_83 ) ;
F_34 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_24 )
continue;
V_2 = V_3 -> V_2 ;
if ( V_3 -> V_15 . V_20 . V_20 == V_20 )
goto V_71;
}
V_2 = - 1 ;
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
}
int F_99 ( unsigned V_2 )
{
return F_17 ( V_2 ) ;
}
int F_100 ( unsigned int V_5 )
{
int V_2 ;
F_90 ( & V_83 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_71;
F_91 ( V_2 , & V_107 ,
V_90 , L_8 ) ;
F_6 ( V_2 , V_5 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_11 ) ;
}
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
}
static int F_101 ( unsigned int V_13 , unsigned int V_6 )
{
struct V_108 V_109 ;
int V_5 , V_2 ;
F_90 ( & V_83 ) ;
V_2 = F_8 ( V_16 , V_6 ) [ V_13 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_71;
F_91 ( V_2 , & V_110 ,
V_111 , L_9 ) ;
V_109 . V_112 = V_6 ;
if ( F_50 ( V_113 ,
& V_109 ) != 0 )
F_85 () ;
V_5 = V_109 . V_41 ;
F_7 ( V_6 , V_2 , V_5 , V_13 ) ;
F_25 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_14 ) ;
}
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
}
static int F_102 ( unsigned int V_114 ,
unsigned int V_115 )
{
struct V_116 V_117 ;
int V_118 ;
V_117 . V_119 = V_114 ;
V_117 . V_115 = V_115 ;
V_118 = F_50 ( V_120 ,
& V_117 ) ;
return V_118 ? : F_100 ( V_117 . V_121 ) ;
}
static int F_103 ( unsigned int V_17 , unsigned int V_6 )
{
struct V_122 V_123 ;
int V_41 , V_67 = - V_103 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
for ( V_41 = 0 ; V_41 <= V_124 ; V_41 ++ ) {
V_123 . V_125 = V_87 ;
V_123 . V_41 = V_41 ;
V_67 = F_50 ( V_126 , & V_123 ) ;
if ( V_67 < 0 )
continue;
if ( V_123 . V_123 != V_127 )
continue;
if ( V_123 . V_15 . V_17 == V_17 && V_123 . V_112 == V_6 ) {
V_67 = V_41 ;
break;
}
}
return V_67 ;
}
int F_104 ( unsigned int V_17 , unsigned int V_6 )
{
struct V_128 V_129 ;
int V_5 , V_2 , V_26 ;
F_90 ( & V_83 ) ;
V_2 = F_8 ( V_19 , V_6 ) [ V_17 ] ;
if ( V_2 == - 1 ) {
V_2 = F_59 () ;
if ( V_2 < 0 )
goto V_71;
F_91 ( V_2 , & V_110 ,
V_111 , L_10 ) ;
V_129 . V_17 = V_17 ;
V_129 . V_112 = V_6 ;
V_26 = F_50 ( V_130 ,
& V_129 ) ;
if ( V_26 == 0 )
V_5 = V_129 . V_41 ;
else {
if ( V_26 == - V_131 )
V_26 = F_103 ( V_17 , V_6 ) ;
F_4 ( V_26 < 0 ) ;
V_5 = V_26 ;
}
F_9 ( V_6 , V_2 , V_5 , V_17 ) ;
F_25 ( V_5 , V_6 ) ;
} else {
struct V_1 * V_3 = F_1 ( V_2 ) ;
F_68 ( V_3 == NULL || V_3 -> type != V_18 ) ;
}
V_71:
F_92 ( & V_83 ) ;
return V_2 ;
}
static void F_105 ( unsigned int V_2 )
{
struct V_76 V_77 ;
int V_5 = F_11 ( V_2 ) ;
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_90 ( & V_83 ) ;
if ( V_3 -> V_54 > 0 ) {
V_3 -> V_54 -- ;
if ( V_3 -> V_54 != 0 )
goto V_132;
}
if ( F_43 ( V_5 ) ) {
V_77 . V_41 = V_5 ;
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
V_132:
F_92 ( & V_83 ) ;
}
int F_106 ( unsigned int V_5 ,
T_5 V_133 ,
unsigned long V_134 ,
const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_100 ( V_5 ) ;
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
int F_109 ( unsigned int V_17 , unsigned int V_6 ,
T_5 V_133 ,
unsigned long V_134 , const char * V_135 , void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_104 ( V_17 , V_6 ) ;
if ( V_2 < 0 )
return V_2 ;
V_137 = F_107 ( V_2 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_137 != 0 ) {
F_105 ( V_2 ) ;
return V_137 ;
}
return V_2 ;
}
int F_110 ( enum V_12 V_13 ,
unsigned int V_6 ,
T_5 V_133 ,
unsigned long V_134 ,
const char * V_135 ,
void * V_136 )
{
int V_2 , V_137 ;
V_2 = F_101 ( V_13 , V_6 ) ;
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
struct V_1 * V_3 = F_2 ( V_2 ) ;
if ( F_68 ( ! V_3 ) )
return;
F_112 ( V_2 , V_136 ) ;
F_105 ( V_2 ) ;
}
int F_113 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
struct V_1 * V_3 ;
if ( V_2 == - 1 )
return - V_103 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return - V_103 ;
F_68 ( V_3 -> V_54 != - 1 ) ;
V_3 -> V_54 = 1 ;
return 0 ;
}
int F_114 ( unsigned int V_5 )
{
int V_2 ;
struct V_1 * V_3 ;
int V_118 = - V_103 ;
if ( V_5 >= V_124 )
return - V_141 ;
F_90 ( & V_83 ) ;
V_2 = V_8 [ V_5 ] ;
if ( V_2 == - 1 )
goto V_132;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
goto V_132;
V_118 = - V_141 ;
if ( V_3 -> V_54 <= 0 )
goto V_132;
V_3 -> V_54 ++ ;
V_118 = 0 ;
V_132:
F_92 ( & V_83 ) ;
return V_118 ;
}
void F_115 ( unsigned int V_5 )
{
int V_2 = V_8 [ V_5 ] ;
if ( F_68 ( V_2 == - 1 ) )
return;
F_105 ( V_2 ) ;
}
void F_116 ( unsigned int V_6 , enum V_12 V_84 )
{
int V_2 = F_8 ( V_16 , V_6 ) [ V_84 ] ;
F_4 ( V_2 < 0 ) ;
F_42 ( V_2 ) ;
}
T_6 F_117 ( int V_2 , void * V_136 )
{
struct V_29 * V_30 = V_43 ;
int V_6 = F_118 () ;
T_2 * V_142 = F_8 ( V_33 , V_6 ) ;
int V_38 ;
unsigned long V_23 ;
static F_119 ( V_143 ) ;
struct V_48 * V_144 ;
F_120 ( & V_143 , V_23 ) ;
F_81 ( L_11 , V_6 ) ;
F_121 (i) {
int V_145 ;
V_144 = F_8 ( V_49 , V_38 ) ;
V_145 = ( F_122 () && V_38 == V_6 )
? F_123 ( F_122 () )
: V_144 -> V_146 ;
F_81 ( L_12 V_147 L_13 , V_38 ,
V_145 , V_144 -> V_52 ,
( int ) ( sizeof( V_144 -> V_51 ) * 2 ) ,
V_144 -> V_51 ) ;
}
V_144 = F_8 ( V_49 , V_6 ) ;
F_81 ( L_14 ) ;
for ( V_38 = F_124 ( V_30 -> V_32 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_81 ( L_15 V_147 L_16 ,
( int ) sizeof( V_30 -> V_32 [ 0 ] ) * 2 ,
V_30 -> V_32 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_81 ( L_19 ) ;
for ( V_38 = F_124 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_81 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_30 -> V_34 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_81 ( L_20 ) ;
for ( V_38 = F_124 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_81 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_30 -> V_32 [ V_38 ] & ~ V_30 -> V_34 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_81 ( L_21 , V_6 ) ;
for ( V_38 = ( V_124 / V_50 ) - 1 ; V_38 >= 0 ; V_38 -- )
F_81 ( L_15 V_147 L_16 , ( int ) ( sizeof( V_142 [ 0 ] ) * 2 ) ,
V_142 [ V_38 ] ,
V_38 % 8 == 0 ? L_17 : L_18 ) ;
F_81 ( L_22 ) ;
for ( V_38 = F_124 ( V_30 -> V_34 ) - 1 ; V_38 >= 0 ; V_38 -- ) {
T_2 V_145 = V_30 -> V_32 [ V_38 ]
& ~ V_30 -> V_34 [ V_38 ]
& V_142 [ V_38 ] ;
F_81 ( L_15 V_147 L_16 ,
( int ) ( sizeof( V_30 -> V_34 [ 0 ] ) * 2 ) ,
V_145 , V_38 % 8 == 0 ? L_17 : L_18 ) ;
}
F_81 ( L_23 ) ;
for ( V_38 = 0 ; V_38 < V_124 ; V_38 ++ ) {
if ( F_41 ( V_38 , F_31 ( V_30 -> V_32 ) ) ) {
int V_148 = V_38 / V_50 ;
F_81 ( L_24 ,
F_20 ( V_38 ) , V_38 ,
V_8 [ V_38 ] ,
F_41 ( V_148 , F_31 ( & V_144 -> V_51 ) )
? L_25 : L_26 ,
! F_41 ( V_38 , F_31 ( V_30 -> V_34 ) )
? L_25 : L_27 ,
F_41 ( V_38 , F_31 ( V_142 ) )
? L_25 : L_28 ) ;
}
}
F_125 ( & V_143 , V_23 ) ;
return V_149 ;
}
static void F_126 ( void )
{
int V_150 , V_151 ;
int V_148 , V_152 ;
int V_38 , V_2 ;
int V_6 = F_47 () ;
struct V_29 * V_42 = V_43 ;
struct V_48 * V_48 = F_51 ( V_49 ) ;
unsigned V_153 ;
do {
T_2 V_154 ;
T_2 V_155 ;
struct V_39 * V_40 ;
V_48 -> V_52 = 0 ;
if ( F_127 ( V_156 ) - 1 )
goto V_71;
if ( ( V_2 = F_8 ( V_19 , V_6 ) [ V_157 ] ) != - 1 ) {
int V_5 = F_11 ( V_2 ) ;
V_148 = V_5 / V_158 ;
V_155 = V_5 % V_158 ;
if ( F_24 ( V_6 , V_42 , V_148 ) & ( 1ULL << V_155 ) ) {
V_40 = F_28 ( V_2 ) ;
if ( V_40 )
F_128 ( V_2 , V_40 ) ;
}
}
V_154 = F_129 ( & V_48 -> V_51 , 0 ) ;
V_150 = F_51 ( V_159 ) ;
V_151 = F_51 ( V_160 ) ;
V_148 = V_150 ;
for ( V_38 = 0 ; V_154 != 0 ; V_38 ++ ) {
T_2 V_161 ;
V_161 = F_130 ( V_154 , V_148 ) ;
if ( V_161 == 0 ) {
V_148 = 0 ;
V_152 = 0 ;
continue;
}
V_148 = F_131 ( V_161 ) ;
V_155 = F_24 ( V_6 , V_42 , V_148 ) ;
V_152 = 0 ;
if ( V_148 == V_150 ) {
if ( V_38 == 0 )
V_152 = V_151 ;
else
V_152 &= ( 1UL << V_151 ) - 1 ;
}
do {
T_2 V_162 ;
int V_41 ;
V_162 = F_130 ( V_155 , V_152 ) ;
if ( V_162 == 0 )
break;
V_152 = F_131 ( V_162 ) ;
V_41 = ( V_148 * V_50 ) + V_152 ;
V_2 = V_8 [ V_41 ] ;
if ( V_2 != - 1 ) {
V_40 = F_28 ( V_2 ) ;
if ( V_40 )
F_128 ( V_2 , V_40 ) ;
}
V_152 = ( V_152 + 1 ) % V_50 ;
F_132 ( V_159 ,
V_152 ? V_148 :
( V_148 + 1 ) % V_50 ) ;
F_132 ( V_160 , V_152 ) ;
} while ( V_152 != 0 );
if ( ( V_148 != V_150 ) || ( V_38 != 0 ) )
V_154 &= ~ ( 1UL << V_148 ) ;
V_148 = ( V_148 + 1 ) % V_50 ;
}
F_4 ( ! F_48 () ) ;
V_153 = F_51 ( V_156 ) ;
F_132 ( V_156 , 0 ) ;
} while ( V_153 != 1 || V_48 -> V_52 );
V_71:
F_53 () ;
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
if ( F_68 ( ! V_3 ) )
return;
F_141 ( V_2 ) ;
F_90 ( & V_83 ) ;
F_4 ( V_8 [ V_5 ] != - 1 ) ;
F_4 ( V_3 -> type == V_7 ) ;
F_6 ( V_2 , V_5 ) ;
F_92 ( & V_83 ) ;
F_142 ( V_2 , F_29 ( 0 ) ) ;
F_143 ( V_2 ) ;
}
static int F_144 ( unsigned V_2 , unsigned V_166 )
{
struct V_167 V_168 ;
int V_5 = F_11 ( V_2 ) ;
if ( ! F_43 ( V_5 ) )
return - 1 ;
if ( F_49 () && ! V_169 )
return - 1 ;
V_168 . V_41 = V_5 ;
V_168 . V_112 = V_166 ;
if ( F_50 ( V_170 , & V_168 ) >= 0 )
F_25 ( V_5 , V_166 ) ;
return 0 ;
}
static int F_145 ( struct V_36 * V_64 , const struct V_171 * V_172 ,
bool V_173 )
{
unsigned V_166 = F_146 ( V_172 ) ;
return F_144 ( V_64 -> V_2 , V_166 ) ;
}
int F_147 ( unsigned int V_2 )
{
int V_174 , V_5 = F_11 ( V_2 ) ;
struct V_29 * V_42 = V_43 ;
if ( ! F_43 ( V_5 ) )
return 1 ;
V_174 = F_52 ( V_5 , F_31 ( V_42 -> V_34 ) ) ;
F_39 ( V_5 , F_31 ( V_42 -> V_32 ) ) ;
if ( ! V_174 )
F_46 ( V_5 ) ;
return 1 ;
}
static void F_148 ( struct V_36 * V_64 )
{
int V_5 = F_11 ( V_64 -> V_2 ) ;
if ( F_43 ( V_5 ) )
F_46 ( V_5 ) ;
}
static void F_79 ( struct V_36 * V_64 )
{
int V_5 = F_11 ( V_64 -> V_2 ) ;
if ( F_43 ( V_5 ) )
F_45 ( V_5 ) ;
}
static void F_149 ( struct V_36 * V_64 )
{
int V_5 = F_11 ( V_64 -> V_2 ) ;
F_76 ( V_64 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
}
static void F_150 ( struct V_36 * V_64 )
{
F_79 ( V_64 ) ;
F_149 ( V_64 ) ;
}
static int F_151 ( struct V_36 * V_64 )
{
int V_5 = F_11 ( V_64 -> V_2 ) ;
struct V_29 * V_30 = V_43 ;
int V_26 = 0 ;
if ( F_43 ( V_5 ) ) {
int V_174 ;
V_174 = F_52 ( V_5 , F_31 ( V_30 -> V_34 ) ) ;
F_39 ( V_5 , F_31 ( V_30 -> V_32 ) ) ;
if ( ! V_174 )
F_46 ( V_5 ) ;
V_26 = 1 ;
}
return V_26 ;
}
static void F_152 ( void )
{
int V_20 , V_67 , V_2 , V_21 ;
struct V_175 V_176 ;
struct V_1 * V_3 ;
F_34 (info, &xen_irq_list_head, list) {
if ( V_3 -> type != V_24 )
continue;
V_20 = V_3 -> V_15 . V_20 . V_20 ;
V_21 = V_3 -> V_15 . V_20 . V_21 ;
V_2 = V_3 -> V_2 ;
if ( ! V_21 )
continue;
V_176 . V_22 = V_87 ;
V_176 . type = V_177 ;
V_176 . V_178 = V_21 ;
V_176 . V_20 = V_20 ;
V_67 = F_73 ( V_179 , & V_176 ) ;
if ( V_67 ) {
F_81 ( V_106 L_29 ,
V_21 , V_2 , V_20 , V_67 ) ;
F_67 ( V_2 ) ;
continue;
}
F_81 ( V_180 L_30 , V_2 , V_176 . V_20 ) ;
F_80 ( V_2 ) ;
}
}
static void F_153 ( unsigned int V_6 )
{
struct V_128 V_129 ;
int V_17 , V_2 , V_5 ;
for ( V_17 = 0 ; V_17 < V_181 ; V_17 ++ ) {
if ( ( V_2 = F_8 ( V_19 , V_6 ) [ V_17 ] ) == - 1 )
continue;
F_4 ( F_16 ( V_2 ) != V_17 ) ;
V_129 . V_17 = V_17 ;
V_129 . V_112 = V_6 ;
if ( F_50 ( V_130 ,
& V_129 ) != 0 )
F_85 () ;
V_5 = V_129 . V_41 ;
F_9 ( V_6 , V_2 , V_5 , V_17 ) ;
F_25 ( V_5 , V_6 ) ;
}
}
static void F_154 ( unsigned int V_6 )
{
struct V_108 V_109 ;
int V_13 , V_2 , V_5 ;
for ( V_13 = 0 ; V_13 < V_182 ; V_13 ++ ) {
if ( ( V_2 = F_8 ( V_16 , V_6 ) [ V_13 ] ) == - 1 )
continue;
F_4 ( F_15 ( V_2 ) != V_13 ) ;
V_109 . V_112 = V_6 ;
if ( F_50 ( V_113 ,
& V_109 ) != 0 )
F_85 () ;
V_5 = V_109 . V_41 ;
F_7 ( V_6 , V_2 , V_5 , V_13 ) ;
F_25 ( V_5 , V_6 ) ;
}
}
void F_155 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_36 ( V_5 ) ;
}
void F_156 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) )
F_38 ( V_5 ) ;
}
bool F_157 ( int V_2 )
{
int V_5 = F_11 ( V_2 ) ;
bool V_26 = false ;
if ( F_43 ( V_5 ) )
V_26 = F_40 ( V_5 ) ;
return V_26 ;
}
void F_158 ( int V_2 , T_7 V_183 )
{
T_8 V_5 = F_11 ( V_2 ) ;
if ( F_43 ( V_5 ) ) {
struct V_184 V_185 ;
V_185 . V_186 = 1 ;
V_185 . V_183 = V_183 ;
F_159 ( V_185 . V_187 , & V_5 ) ;
if ( F_160 ( V_188 , & V_185 ) != 0 )
F_85 () ;
}
}
void F_161 ( int V_2 )
{
F_158 ( V_2 , 0 ) ;
}
int F_162 ( int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
struct V_59 V_60 ;
if ( F_68 ( ! V_3 ) )
return - V_103 ;
V_60 . V_2 = V_3 -> V_15 . V_20 . V_20 ;
if ( F_73 ( V_61 , & V_60 ) )
return 0 ;
return ! ( V_60 . V_23 & V_189 ) ;
}
void F_163 ( void )
{
unsigned int V_6 , V_5 ;
struct V_1 * V_3 ;
F_33 () ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
F_45 ( V_5 ) ;
F_34 (info, &xen_irq_list_head, list)
V_3 -> V_5 = 0 ;
for ( V_5 = 0 ; V_5 < V_124 ; V_5 ++ )
V_8 [ V_5 ] = - 1 ;
F_35 (cpu) {
F_153 ( V_6 ) ;
F_154 ( V_6 ) ;
}
F_152 () ;
}
int F_164 ( T_9 V_190 )
{
struct V_191 V_192 ;
V_192 . V_22 = V_87 ;
V_192 . V_178 = V_193 ;
V_192 . V_194 = V_190 ;
return F_165 ( V_195 , & V_192 ) ;
}
void F_166 ( void )
{
int V_67 ;
T_9 V_196 ;
if ( V_169 ) {
V_196 = F_167 ( V_197 ) ;
V_67 = F_164 ( V_196 ) ;
if ( V_67 ) {
F_81 ( V_198 L_31
L_32 ) ;
V_169 = 0 ;
return;
}
F_81 ( V_75 L_33
L_34 ) ;
if ( ! F_22 ( V_197 , V_199 ) )
F_168 ( V_197 ,
V_200 ) ;
}
}
void F_166 ( void ) {}
void T_10 F_169 ( void )
{
int V_38 ;
V_8 = F_170 ( V_124 , sizeof( * V_8 ) ,
V_53 ) ;
F_4 ( ! V_8 ) ;
for ( V_38 = 0 ; V_38 < V_124 ; V_38 ++ )
V_8 [ V_38 ] = - 1 ;
F_33 () ;
for ( V_38 = 0 ; V_38 < V_124 ; V_38 ++ )
F_45 ( V_38 ) ;
F_77 = F_23 ;
#ifdef F_136
if ( F_49 () ) {
F_166 () ;
F_171 () ;
F_172 () ;
} else {
int V_67 ;
struct V_201 V_202 ;
F_173 ( F_118 () ) ;
if ( F_61 () )
F_174 () ;
V_27 = ( void * ) F_175 ( V_53 | V_203 ) ;
V_202 . V_204 = F_176 ( V_27 ) ;
V_67 = F_73 ( V_205 , & V_202 ) ;
if ( V_67 != 0 ) {
F_177 ( ( unsigned long ) V_27 ) ;
V_27 = NULL ;
} else
F_77 = F_21 ;
}
#endif
}
