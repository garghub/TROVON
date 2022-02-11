static void F_1 ( unsigned V_1 )
{
unsigned V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_4 [ V_1 ] [ V_2 ] = - 1 ;
}
static void F_2 ( void )
{
unsigned V_1 ;
for ( V_1 = 0 ; V_1 < F_3 ( F_4 () ) ; V_1 ++ ) {
if ( V_4 [ V_1 ] == NULL )
continue;
F_1 ( V_1 ) ;
}
}
static int F_5 ( unsigned V_5 , unsigned V_6 )
{
unsigned V_1 ;
unsigned V_2 ;
if ( V_5 >= F_4 () )
return - V_7 ;
V_1 = F_3 ( V_5 ) ;
V_2 = F_6 ( V_5 ) ;
if ( V_4 [ V_1 ] == NULL ) {
if ( V_6 == - 1 )
return 0 ;
V_4 [ V_1 ] = ( int * ) F_7 ( V_8 ) ;
if ( V_4 [ V_1 ] == NULL )
return - V_9 ;
F_1 ( V_1 ) ;
}
V_4 [ F_3 ( V_5 ) ] [ F_6 ( V_5 ) ] = V_6 ;
return 0 ;
}
int F_8 ( unsigned V_5 )
{
if ( V_5 >= F_4 () )
return - 1 ;
if ( V_4 [ F_3 ( V_5 ) ] == NULL )
return - 1 ;
return V_4 [ F_3 ( V_5 ) ] [ F_6 ( V_5 ) ] ;
}
struct V_10 * F_9 ( unsigned V_6 )
{
return F_10 ( V_6 ) ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned V_6 ,
enum V_12 type ,
unsigned V_5 ,
unsigned short V_13 )
{
int V_14 ;
F_12 ( V_11 -> type != V_15 && V_11 -> type != type ) ;
V_11 -> type = type ;
V_11 -> V_6 = V_6 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_13 = V_13 ;
V_14 = F_5 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( V_6 , V_16 | V_17 ) ;
return F_14 ( V_11 ) ;
}
static int F_15 ( unsigned V_6 ,
unsigned V_5 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
return F_11 ( V_11 , V_6 , V_18 , V_5 , 0 ) ;
}
static int F_16 ( unsigned V_13 ,
unsigned V_6 ,
unsigned V_5 ,
enum V_19 V_20 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
V_11 -> V_21 . V_20 = V_20 ;
F_17 ( V_22 , V_13 ) [ V_20 ] = V_6 ;
return F_11 ( V_11 , V_6 , V_23 , V_5 , 0 ) ;
}
static int F_18 ( unsigned V_13 ,
unsigned V_6 ,
unsigned V_5 ,
unsigned V_24 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
V_11 -> V_21 . V_24 = V_24 ;
F_17 ( V_25 , V_13 ) [ V_24 ] = V_6 ;
return F_11 ( V_11 , V_6 , V_26 , V_5 , 0 ) ;
}
static int F_19 ( unsigned V_6 ,
unsigned V_5 ,
unsigned V_27 ,
unsigned V_28 ,
T_1 V_29 ,
unsigned char V_30 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
V_11 -> V_21 . V_27 . V_27 = V_27 ;
V_11 -> V_21 . V_27 . V_28 = V_28 ;
V_11 -> V_21 . V_27 . V_29 = V_29 ;
V_11 -> V_21 . V_27 . V_30 = V_30 ;
return F_11 ( V_11 , V_6 , V_31 , V_5 , 0 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
F_5 ( V_11 -> V_5 , - 1 ) ;
V_11 -> V_5 = 0 ;
}
unsigned int F_21 ( unsigned V_6 )
{
if ( F_22 ( F_23 ( V_6 < 0 || V_6 >= V_32 , L_1 , V_6 ) ) )
return 0 ;
return F_9 ( V_6 ) -> V_5 ;
}
unsigned F_24 ( unsigned int V_5 )
{
return F_8 ( V_5 ) ;
}
int F_25 ( unsigned int V_13 , unsigned int V_24 )
{
return F_17 ( V_25 , V_13 ) [ V_24 ] ;
}
static enum V_19 F_26 ( unsigned V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 == NULL ) ;
F_12 ( V_11 -> type != V_23 ) ;
return V_11 -> V_21 . V_20 ;
}
static unsigned F_27 ( unsigned V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 == NULL ) ;
F_12 ( V_11 -> type != V_26 ) ;
return V_11 -> V_21 . V_24 ;
}
static unsigned F_28 ( unsigned V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 == NULL ) ;
F_12 ( V_11 -> type != V_31 ) ;
return V_11 -> V_21 . V_27 . V_27 ;
}
static enum V_12 F_29 ( unsigned V_6 )
{
return F_9 ( V_6 ) -> type ;
}
unsigned F_30 ( unsigned V_6 )
{
return F_9 ( V_6 ) -> V_13 ;
}
unsigned int F_31 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
unsigned V_14 = 0 ;
if ( V_6 != - 1 )
V_14 = F_30 ( V_6 ) ;
return V_14 ;
}
static bool F_32 ( unsigned V_6 )
{
return F_33 ( F_28 ( V_6 ) , V_33 ) ;
}
static bool F_34 ( unsigned V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
return V_11 -> V_21 . V_27 . V_30 & V_34 ;
}
static void F_35 ( unsigned int V_35 , unsigned int V_13 )
{
int V_6 = F_8 ( V_35 ) ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_6 == - 1 ) ;
#ifdef F_36
F_37 ( F_38 ( V_6 ) -> V_36 , F_39 ( V_13 ) ) ;
#endif
F_40 ( V_11 , V_13 ) ;
V_11 -> V_13 = V_13 ;
}
static void F_41 ( void )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_42 () ; V_5 ++ )
F_43 ( V_5 ) ;
}
void F_44 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_46 ( V_5 ) ;
}
static void F_47 ( unsigned V_6 )
{
struct V_10 * V_11 ;
#ifdef F_36
F_37 ( F_38 ( V_6 ) -> V_36 , F_39 ( 0 ) ) ;
#endif
V_11 = F_48 ( sizeof( * V_11 ) , V_8 ) ;
if ( V_11 == NULL )
F_49 ( L_2 , V_6 ) ;
V_11 -> type = V_15 ;
V_11 -> V_37 = - 1 ;
F_50 ( V_6 , V_11 ) ;
F_51 ( & V_11 -> V_38 , & V_39 ) ;
}
static int T_2 F_52 ( int V_40 )
{
int V_41 = 0 ;
int V_42 , V_6 ;
#ifdef F_53
if ( F_54 () || F_55 () )
V_41 = F_56 () ;
#endif
V_6 = F_57 ( V_41 , V_40 , - 1 ) ;
if ( V_6 >= 0 ) {
for ( V_42 = 0 ; V_42 < V_40 ; V_42 ++ )
F_47 ( V_6 + V_42 ) ;
}
return V_6 ;
}
static inline int T_2 F_58 ( void )
{
return F_52 ( 1 ) ;
}
static int T_2 F_59 ( unsigned V_28 )
{
int V_6 ;
if ( F_60 () && ! F_54 () )
return F_58 () ;
if ( V_28 < V_43 )
V_6 = V_28 ;
else
V_6 = F_61 ( V_28 , - 1 ) ;
F_47 ( V_6 ) ;
return V_6 ;
}
static void F_62 ( unsigned V_6 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_63 ( ! V_11 ) )
return;
F_64 ( & V_11 -> V_38 ) ;
F_50 ( V_6 , NULL ) ;
F_63 ( V_11 -> V_37 > 0 ) ;
F_65 ( V_11 ) ;
if ( V_6 < V_43 )
return;
F_66 ( V_6 ) ;
}
static void F_67 ( unsigned int V_44 )
{
struct V_45 V_46 ;
V_46 . V_44 = V_44 ;
if ( F_68 ( V_47 , & V_46 ) != 0 )
F_69 () ;
}
static void F_70 ( int V_6 )
{
struct V_48 V_49 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
V_49 . V_6 = F_28 ( V_6 ) ;
if ( F_71 ( V_50 , & V_49 ) )
V_49 . V_30 = 0 ;
V_11 -> V_21 . V_27 . V_30 &= ~ V_34 ;
if ( V_49 . V_30 & V_51 )
V_11 -> V_21 . V_27 . V_30 |= V_34 ;
}
static void F_72 ( struct V_52 * V_53 )
{
int V_5 = F_21 ( V_53 -> V_6 ) ;
struct V_54 V_55 = { . V_6 = F_28 (data->irq) } ;
int V_56 = 0 ;
F_73 ( V_53 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
if ( F_75 ( V_53 -> V_6 ) ) {
V_56 = F_71 ( V_57 , & V_55 ) ;
F_63 ( V_56 ) ;
}
}
static void F_76 ( struct V_52 * V_53 )
{
F_77 ( V_53 ) ;
F_72 ( V_53 ) ;
}
static unsigned int F_78 ( unsigned int V_6 )
{
struct V_58 V_59 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_5 = F_21 ( V_6 ) ;
int V_56 ;
F_12 ( V_11 -> type != V_31 ) ;
if ( F_45 ( V_5 ) )
goto V_60;
V_59 . V_27 = F_28 ( V_6 ) ;
V_59 . V_30 = V_11 -> V_21 . V_27 . V_30 & V_61 ?
V_62 : 0 ;
V_56 = F_68 ( V_63 , & V_59 ) ;
if ( V_56 != 0 ) {
F_79 ( L_3 , V_6 ) ;
return 0 ;
}
V_5 = V_59 . V_44 ;
F_70 ( V_6 ) ;
V_56 = F_5 ( V_5 , V_6 ) ;
if ( V_56 != 0 ) {
F_80 ( L_4 ,
V_6 , V_56 ) ;
F_67 ( V_5 ) ;
return 0 ;
}
F_35 ( V_5 , 0 ) ;
V_11 -> V_5 = V_5 ;
V_60:
F_81 ( V_5 ) ;
F_72 ( F_38 ( V_6 ) ) ;
return 0 ;
}
static unsigned int F_82 ( struct V_52 * V_53 )
{
return F_78 ( V_53 -> V_6 ) ;
}
static void F_83 ( struct V_52 * V_53 )
{
unsigned int V_6 = V_53 -> V_6 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
unsigned V_5 = F_21 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
if ( ! F_45 ( V_5 ) )
return;
F_43 ( V_5 ) ;
F_67 ( V_5 ) ;
F_20 ( V_11 ) ;
}
static void F_84 ( struct V_52 * V_53 )
{
F_82 ( V_53 ) ;
}
static void F_85 ( struct V_52 * V_53 )
{
F_77 ( V_53 ) ;
}
int F_86 ( unsigned V_28 )
{
struct V_10 * V_11 ;
F_87 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
if ( V_11 -> V_21 . V_27 . V_28 == V_28 )
return V_11 -> V_6 ;
}
return - 1 ;
}
static void F_88 ( unsigned int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( V_11 -> V_37 > 0 ) {
V_11 -> V_37 -- ;
if ( V_11 -> V_37 != 0 )
return;
}
if ( F_45 ( V_5 ) ) {
unsigned int V_13 = F_30 ( V_6 ) ;
F_67 ( V_5 ) ;
switch ( F_29 ( V_6 ) ) {
case V_26 :
F_17 ( V_25 , V_13 ) [ F_27 ( V_6 ) ] = - 1 ;
break;
case V_23 :
F_17 ( V_22 , V_13 ) [ F_26 ( V_6 ) ] = - 1 ;
break;
default:
break;
}
F_20 ( V_11 ) ;
}
F_12 ( F_9 ( V_6 ) -> type == V_15 ) ;
F_62 ( V_6 ) ;
}
int F_89 ( unsigned V_28 ,
unsigned V_27 , int V_64 , char * V_65 )
{
int V_6 = - 1 ;
struct V_66 V_67 ;
int V_14 ;
F_90 ( & V_68 ) ;
V_6 = F_86 ( V_28 ) ;
if ( V_6 != - 1 ) {
F_91 ( L_5 ,
V_69 , V_6 , V_28 ) ;
goto V_60;
}
V_6 = F_59 ( V_28 ) ;
if ( V_6 < 0 )
goto V_60;
V_67 . V_6 = V_6 ;
V_67 . V_70 = 0 ;
if ( F_54 () &&
F_71 ( V_71 , & V_67 ) ) {
F_62 ( V_6 ) ;
V_6 = - V_72 ;
goto V_60;
}
V_14 = F_19 ( V_6 , 0 , V_27 , V_28 , V_73 ,
V_64 ? V_61 : 0 ) ;
if ( V_14 < 0 ) {
F_88 ( V_6 ) ;
V_6 = V_14 ;
goto V_60;
}
F_70 ( V_6 ) ;
if ( V_64 )
F_92 ( V_6 , & V_74 ,
V_75 , V_65 ) ;
else
F_92 ( V_6 , & V_74 ,
V_76 , V_65 ) ;
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
}
int F_94 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
int V_56 ;
struct V_81 V_82 ;
V_82 . type = V_83 ;
V_56 = F_71 ( V_84 , & V_82 ) ;
F_95 ( V_56 == - V_85 ,
L_6 ) ;
return V_56 ? - 1 : V_82 . V_27 ;
}
int F_96 ( struct V_77 * V_78 , struct V_79 * V_80 ,
int V_27 , int V_40 , const char * V_65 , T_3 V_29 )
{
int V_42 , V_6 , V_14 ;
F_90 ( & V_68 ) ;
V_6 = F_52 ( V_40 ) ;
if ( V_6 < 0 )
goto V_60;
for ( V_42 = 0 ; V_42 < V_40 ; V_42 ++ ) {
F_92 ( V_6 + V_42 , & V_74 , V_76 , V_65 ) ;
V_14 = F_19 ( V_6 + V_42 , 0 , V_27 + V_42 , 0 , V_29 ,
V_42 == 0 ? 0 : V_86 ) ;
if ( V_14 < 0 )
goto V_87;
}
V_14 = F_97 ( V_6 , V_80 ) ;
if ( V_14 < 0 )
goto V_87;
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
V_87:
for (; V_42 >= 0 ; V_42 -- )
F_88 ( V_6 + V_42 ) ;
F_93 ( & V_68 ) ;
return V_14 ;
}
int F_98 ( int V_6 )
{
struct V_88 V_89 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_56 = - V_90 ;
F_90 ( & V_68 ) ;
if ( F_54 () && ! ( V_11 -> V_21 . V_27 . V_30 & V_86 ) ) {
V_89 . V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_89 . V_29 = V_11 -> V_21 . V_27 . V_29 ;
V_56 = F_71 ( V_91 , & V_89 ) ;
if ( ( V_56 == - V_92 && V_11 -> V_21 . V_27 . V_29 != V_73 ) )
F_91 ( L_7 ,
V_11 -> V_21 . V_27 . V_29 , V_11 -> V_21 . V_27 . V_27 ) ;
else if ( V_56 ) {
F_79 ( L_8 , V_56 ) ;
goto V_60;
}
}
F_62 ( V_6 ) ;
V_60:
F_93 ( & V_68 ) ;
return V_56 ;
}
int F_99 ( unsigned V_27 )
{
int V_6 ;
struct V_10 * V_11 ;
F_90 ( & V_68 ) ;
F_87 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_6 = V_11 -> V_6 ;
if ( V_11 -> V_21 . V_27 . V_27 == V_27 )
goto V_60;
}
V_6 = - 1 ;
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
}
int F_100 ( unsigned V_6 )
{
return F_28 ( V_6 ) ;
}
int F_101 ( unsigned int V_5 )
{
int V_6 ;
int V_14 ;
if ( V_5 >= F_4 () )
return - V_9 ;
F_90 ( & V_68 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 ) {
V_6 = F_58 () ;
if ( V_6 < 0 )
goto V_60;
F_92 ( V_6 , & V_93 ,
V_76 , L_9 ) ;
V_14 = F_15 ( V_6 , V_5 ) ;
if ( V_14 < 0 ) {
F_88 ( V_6 ) ;
V_6 = V_14 ;
goto V_60;
}
F_35 ( V_5 , 0 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_63 ( V_11 == NULL || V_11 -> type != V_18 ) ;
}
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
}
static int F_102 ( unsigned int V_20 , unsigned int V_13 )
{
struct V_94 V_95 ;
int V_5 , V_6 ;
int V_14 ;
F_90 ( & V_68 ) ;
V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ;
if ( V_6 == - 1 ) {
V_6 = F_58 () ;
if ( V_6 < 0 )
goto V_60;
F_92 ( V_6 , & V_96 ,
V_97 , L_10 ) ;
V_95 . V_98 = V_13 ;
if ( F_68 ( V_99 ,
& V_95 ) != 0 )
F_69 () ;
V_5 = V_95 . V_44 ;
V_14 = F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
if ( V_14 < 0 ) {
F_88 ( V_6 ) ;
V_6 = V_14 ;
goto V_60;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_63 ( V_11 == NULL || V_11 -> type != V_23 ) ;
}
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
}
static int F_103 ( unsigned int V_100 ,
unsigned int V_101 )
{
struct V_102 V_103 ;
int V_104 ;
V_103 . V_105 = V_100 ;
V_103 . V_101 = V_101 ;
V_104 = F_68 ( V_106 ,
& V_103 ) ;
return V_104 ? : F_101 ( V_103 . V_107 ) ;
}
static int F_104 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_108 V_109 ;
int V_44 , V_56 = - V_90 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
for ( V_44 = 0 ; V_44 < F_4 () ; V_44 ++ ) {
V_109 . V_110 = V_73 ;
V_109 . V_44 = V_44 ;
V_56 = F_68 ( V_111 , & V_109 ) ;
if ( V_56 < 0 )
continue;
if ( V_109 . V_109 != V_112 )
continue;
if ( V_109 . V_21 . V_24 == V_24 && V_109 . V_98 == V_13 ) {
V_56 = V_44 ;
break;
}
}
return V_56 ;
}
unsigned F_42 ( void )
{
return V_113 -> V_114 () ;
}
int F_105 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_115 V_116 ;
int V_5 , V_6 , V_14 ;
F_90 ( & V_68 ) ;
V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ;
if ( V_6 == - 1 ) {
V_6 = F_58 () ;
if ( V_6 < 0 )
goto V_60;
F_92 ( V_6 , & V_96 ,
V_97 , L_11 ) ;
V_116 . V_24 = V_24 ;
V_116 . V_98 = V_13 ;
V_14 = F_68 ( V_117 ,
& V_116 ) ;
if ( V_14 == 0 )
V_5 = V_116 . V_44 ;
else {
if ( V_14 == - V_118 )
V_14 = F_104 ( V_24 , V_13 ) ;
F_12 ( V_14 < 0 ) ;
V_5 = V_14 ;
}
V_14 = F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
if ( V_14 < 0 ) {
F_88 ( V_6 ) ;
V_6 = V_14 ;
goto V_60;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_63 ( V_11 == NULL || V_11 -> type != V_26 ) ;
}
V_60:
F_93 ( & V_68 ) ;
return V_6 ;
}
static void F_106 ( unsigned int V_6 )
{
F_90 ( & V_68 ) ;
F_88 ( V_6 ) ;
F_93 ( & V_68 ) ;
}
int F_107 ( unsigned int V_5 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 , void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_101 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_108 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_106 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_109 ( unsigned int V_100 ,
unsigned int V_101 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 ,
void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_103 ( V_100 , V_101 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_108 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_106 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_110 ( unsigned int V_24 , unsigned int V_13 ,
T_4 V_119 ,
unsigned long V_120 , const char * V_121 , void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_105 ( V_24 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_108 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_106 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_111 ( enum V_19 V_20 ,
unsigned int V_13 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 ,
void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_102 ( V_20 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_120 |= V_124 | V_125 | V_126 ;
V_123 = F_108 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_106 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
void F_112 ( unsigned int V_6 , void * V_122 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_63 ( ! V_11 ) )
return;
F_113 ( V_6 , V_122 ) ;
F_106 ( V_6 ) ;
}
int F_114 ( unsigned V_6 , unsigned V_127 )
{
struct V_128 V_129 ;
V_129 . V_44 = F_21 ( V_6 ) ;
V_129 . V_127 = V_127 ;
return F_68 ( V_130 ,
& V_129 ) ;
}
int F_115 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
struct V_10 * V_11 ;
if ( V_6 == - 1 )
return - V_90 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_90 ;
F_63 ( V_11 -> V_37 != - 1 ) ;
V_11 -> V_37 = 1 ;
return 0 ;
}
int F_116 ( unsigned int V_5 )
{
int V_6 ;
struct V_10 * V_11 ;
int V_104 = - V_90 ;
if ( V_5 >= F_4 () )
return - V_7 ;
F_90 ( & V_68 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 )
goto V_131;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
goto V_131;
V_104 = - V_7 ;
if ( V_11 -> V_37 <= 0 )
goto V_131;
V_11 -> V_37 ++ ;
V_104 = 0 ;
V_131:
F_93 ( & V_68 ) ;
return V_104 ;
}
void F_117 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
if ( F_63 ( V_6 == - 1 ) )
return;
F_106 ( V_6 ) ;
}
void F_118 ( unsigned int V_13 , enum V_19 V_70 )
{
int V_6 ;
#ifdef F_119
if ( F_22 ( V_70 == V_132 ) ) {
int V_56 = F_120 ( V_133 , V_13 , NULL ) ;
if ( V_56 < 0 )
F_121 ( V_134 L_12 , V_13 , V_56 ) ;
return;
}
#endif
V_6 = F_17 ( V_22 , V_13 ) [ V_70 ] ;
F_12 ( V_6 < 0 ) ;
F_44 ( V_6 ) ;
}
static void F_122 ( void )
{
struct V_135 * V_135 = F_123 ( V_136 ) ;
int V_13 = F_124 () ;
unsigned V_137 ;
do {
V_135 -> V_138 = 0 ;
if ( F_125 ( V_139 ) - 1 )
goto V_60;
F_126 ( V_13 ) ;
F_12 ( ! F_127 () ) ;
V_137 = F_123 ( V_139 ) ;
F_128 ( V_139 , 0 ) ;
} while ( V_137 != 1 || V_135 -> V_138 );
V_60:
F_129 () ;
}
void F_130 ( struct V_140 * V_141 )
{
struct V_140 * V_142 = F_131 ( V_141 ) ;
F_132 () ;
#ifdef F_119
F_133 () ;
F_134 ( V_143 ) ;
#endif
F_122 () ;
F_135 () ;
F_131 ( V_142 ) ;
}
void F_136 ( void )
{
F_122 () ;
}
void F_137 ( int V_5 , int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
if ( F_63 ( ! V_11 ) )
return;
F_138 ( V_6 ) ;
F_90 ( & V_68 ) ;
F_12 ( F_8 ( V_5 ) != - 1 ) ;
F_12 ( V_11 -> type == V_15 ) ;
( void ) F_15 ( V_6 , V_5 ) ;
F_93 ( & V_68 ) ;
F_139 ( V_6 , F_39 ( 0 ) ) ;
F_140 ( V_6 ) ;
}
static int F_141 ( unsigned V_6 , unsigned V_144 )
{
struct V_145 V_146 ;
int V_5 = F_21 ( V_6 ) ;
int V_147 ;
if ( ! F_45 ( V_5 ) )
return - 1 ;
if ( F_55 () && ! V_148 )
return - 1 ;
V_146 . V_44 = V_5 ;
V_146 . V_98 = V_144 ;
V_147 = F_142 ( V_5 ) ;
if ( F_68 ( V_149 , & V_146 ) >= 0 )
F_35 ( V_5 , V_144 ) ;
if ( ! V_147 )
F_81 ( V_5 ) ;
return 0 ;
}
static int F_143 ( struct V_52 * V_53 , const struct V_150 * V_151 ,
bool V_152 )
{
unsigned V_144 = F_144 ( V_151 , V_153 ) ;
return F_141 ( V_53 -> V_6 , V_144 ) ;
}
static void F_145 ( struct V_52 * V_53 )
{
int V_5 = F_21 ( V_53 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_81 ( V_5 ) ;
}
static void F_77 ( struct V_52 * V_53 )
{
int V_5 = F_21 ( V_53 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_146 ( struct V_52 * V_53 )
{
int V_5 = F_21 ( V_53 -> V_6 ) ;
F_73 ( V_53 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
}
static void F_147 ( struct V_52 * V_53 )
{
F_77 ( V_53 ) ;
F_146 ( V_53 ) ;
}
static int F_148 ( struct V_52 * V_53 )
{
unsigned int V_5 = F_21 ( V_53 -> V_6 ) ;
int V_147 ;
if ( ! F_45 ( V_5 ) )
return 0 ;
V_147 = F_142 ( V_5 ) ;
F_149 ( V_5 ) ;
if ( ! V_147 )
F_81 ( V_5 ) ;
return 1 ;
}
static void F_150 ( void )
{
int V_27 , V_56 , V_6 , V_28 ;
struct V_154 V_155 ;
struct V_10 * V_11 ;
F_87 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_28 = V_11 -> V_21 . V_27 . V_28 ;
V_6 = V_11 -> V_6 ;
if ( ! V_28 )
continue;
V_155 . V_29 = V_73 ;
V_155 . type = V_156 ;
V_155 . V_157 = V_28 ;
V_155 . V_27 = V_27 ;
V_56 = F_71 ( V_158 , & V_155 ) ;
if ( V_56 ) {
F_79 ( L_13 ,
V_28 , V_6 , V_27 , V_56 ) ;
F_62 ( V_6 ) ;
continue;
}
F_121 ( V_159 L_14 , V_6 , V_155 . V_27 ) ;
F_78 ( V_6 ) ;
}
}
static void F_151 ( unsigned int V_13 )
{
struct V_115 V_116 ;
int V_24 , V_6 , V_5 ;
for ( V_24 = 0 ; V_24 < V_160 ; V_24 ++ ) {
if ( ( V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ) == - 1 )
continue;
F_12 ( F_27 ( V_6 ) != V_24 ) ;
V_116 . V_24 = V_24 ;
V_116 . V_98 = V_13 ;
if ( F_68 ( V_117 ,
& V_116 ) != 0 )
F_69 () ;
V_5 = V_116 . V_44 ;
( void ) F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
static void F_152 ( unsigned int V_13 )
{
struct V_94 V_95 ;
int V_20 , V_6 , V_5 ;
for ( V_20 = 0 ; V_20 < V_161 ; V_20 ++ ) {
if ( ( V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ) == - 1 )
continue;
F_12 ( F_26 ( V_6 ) != V_20 ) ;
V_95 . V_98 = V_13 ;
if ( F_68 ( V_99 ,
& V_95 ) != 0 )
F_69 () ;
V_5 = V_95 . V_44 ;
( void ) F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
void F_153 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
}
void F_154 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_149 ( V_5 ) ;
}
bool F_155 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
bool V_14 = false ;
if ( F_45 ( V_5 ) )
V_14 = F_156 ( V_5 ) ;
return V_14 ;
}
void F_157 ( int V_6 , T_5 V_162 )
{
T_6 V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) ) {
struct V_163 V_164 ;
V_164 . V_165 = 1 ;
V_164 . V_162 = V_162 ;
F_158 ( V_164 . V_166 , & V_5 ) ;
if ( F_159 ( V_167 , & V_164 ) != 0 )
F_69 () ;
}
}
void F_160 ( int V_6 )
{
F_157 ( V_6 , 0 ) ;
}
int F_161 ( int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
struct V_48 V_49 ;
if ( F_63 ( ! V_11 ) )
return - V_90 ;
V_49 . V_6 = V_11 -> V_21 . V_27 . V_27 ;
if ( F_71 ( V_50 , & V_49 ) )
return 0 ;
return ! ( V_49 . V_30 & V_168 ) ;
}
void F_162 ( void )
{
unsigned int V_13 ;
struct V_10 * V_11 ;
F_41 () ;
F_163 () ;
F_87 (info, &xen_irq_list_head, list)
V_11 -> V_5 = 0 ;
F_2 () ;
F_164 (cpu) {
F_151 ( V_13 ) ;
F_152 ( V_13 ) ;
}
F_150 () ;
}
int F_165 ( T_7 V_169 )
{
struct V_170 V_171 ;
V_171 . V_29 = V_73 ;
V_171 . V_157 = V_172 ;
V_171 . V_173 = V_169 ;
return F_166 ( V_174 , & V_171 ) ;
}
void F_167 ( void )
{
int V_56 ;
T_7 V_175 ;
if ( V_148 ) {
V_175 = F_168 ( V_176 ) ;
V_56 = F_165 ( V_175 ) ;
if ( V_56 ) {
F_80 ( L_15 ) ;
V_148 = 0 ;
return;
}
F_91 ( L_16 ) ;
if ( ! F_33 ( V_176 , V_177 ) )
F_169 ( V_176 ,
V_178 ) ;
}
}
void F_167 ( void ) {}
void T_8 F_170 ( void )
{
int V_14 = - V_7 ;
if ( V_179 )
V_14 = F_171 () ;
if ( V_14 < 0 )
F_172 () ;
V_4 = F_173 ( F_3 ( F_4 () ) ,
sizeof( * V_4 ) , V_8 ) ;
F_12 ( ! V_4 ) ;
F_41 () ;
F_75 = F_34 ;
#ifdef F_119
if ( F_60 () ) {
F_174 ( F_175 () ) ;
if ( F_54 () )
F_176 () ;
}
if ( F_177 ( V_180 ) )
F_167 () ;
if ( F_55 () ) {
F_178 () ;
F_179 () ;
} else {
int V_56 ;
struct V_181 V_182 ;
V_33 = ( void * ) F_180 ( V_8 | V_183 ) ;
V_182 . V_184 = F_181 ( V_33 ) ;
V_56 = F_71 ( V_185 , & V_182 ) ;
if ( V_56 != 0 ) {
F_182 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
} else
F_75 = F_32 ;
}
#endif
}
