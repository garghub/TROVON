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
if ( F_22 ( F_23 ( V_6 >= V_32 , L_1 , V_6 ) ) )
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
F_37 ( F_38 ( V_6 ) , F_39 ( V_13 ) ) ;
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
F_37 ( F_38 ( V_6 ) , F_39 ( 0 ) ) ;
#endif
V_11 = F_48 ( sizeof( * V_11 ) , V_8 ) ;
if ( V_11 == NULL )
F_49 ( L_2 , V_6 ) ;
V_11 -> type = V_15 ;
V_11 -> V_36 = - 1 ;
F_50 ( V_6 , V_11 ) ;
F_51 ( & V_11 -> V_37 , & V_38 ) ;
}
static int T_2 F_52 ( int V_39 )
{
int V_40 , V_6 = F_53 ( - 1 , 0 , V_39 , - 1 ) ;
if ( V_6 >= 0 ) {
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_47 ( V_6 + V_40 ) ;
}
return V_6 ;
}
static inline int T_2 F_54 ( void )
{
return F_52 ( 1 ) ;
}
static int T_2 F_55 ( unsigned V_28 )
{
int V_6 ;
if ( F_56 () && ! F_57 () )
return F_54 () ;
if ( V_28 < F_58 () )
V_6 = V_28 ;
else
V_6 = F_59 ( V_28 , - 1 ) ;
F_47 ( V_6 ) ;
return V_6 ;
}
static void F_60 ( unsigned V_6 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_61 ( ! V_11 ) )
return;
F_62 ( & V_11 -> V_37 ) ;
F_50 ( V_6 , NULL ) ;
F_61 ( V_11 -> V_36 > 0 ) ;
F_63 ( V_11 ) ;
if ( V_6 < F_58 () )
return;
F_64 ( V_6 ) ;
}
static void F_65 ( unsigned int V_41 )
{
struct V_42 V_43 ;
V_43 . V_41 = V_41 ;
if ( F_66 ( V_44 , & V_43 ) != 0 )
F_67 () ;
}
static void F_68 ( int V_6 )
{
struct V_45 V_46 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
V_46 . V_6 = F_28 ( V_6 ) ;
if ( F_69 ( V_47 , & V_46 ) )
V_46 . V_30 = 0 ;
V_11 -> V_21 . V_27 . V_30 &= ~ V_34 ;
if ( V_46 . V_30 & V_48 )
V_11 -> V_21 . V_27 . V_30 |= V_34 ;
}
static void F_70 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
struct V_51 V_52 = { . V_6 = F_28 (data->irq) } ;
int V_53 = 0 ;
F_71 ( V_50 ) ;
if ( F_45 ( V_5 ) )
F_72 ( V_5 ) ;
if ( F_73 ( V_50 -> V_6 ) ) {
V_53 = F_69 ( V_54 , & V_52 ) ;
F_61 ( V_53 ) ;
}
}
static void F_74 ( struct V_49 * V_50 )
{
F_75 ( V_50 ) ;
F_70 ( V_50 ) ;
}
static unsigned int F_76 ( unsigned int V_6 )
{
struct V_55 V_56 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_5 = F_21 ( V_6 ) ;
int V_53 ;
F_12 ( V_11 -> type != V_31 ) ;
if ( F_45 ( V_5 ) )
goto V_57;
V_56 . V_27 = F_28 ( V_6 ) ;
V_56 . V_30 = V_11 -> V_21 . V_27 . V_30 & V_58 ?
V_59 : 0 ;
V_53 = F_66 ( V_60 , & V_56 ) ;
if ( V_53 != 0 ) {
F_77 ( L_3 , V_6 ) ;
return 0 ;
}
V_5 = V_56 . V_41 ;
F_68 ( V_6 ) ;
V_53 = F_5 ( V_5 , V_6 ) ;
if ( V_53 )
goto V_61;
V_11 -> V_5 = V_5 ;
F_35 ( V_5 , 0 ) ;
V_53 = F_14 ( V_11 ) ;
if ( V_53 )
goto V_61;
V_57:
F_78 ( V_5 ) ;
F_70 ( F_79 ( V_6 ) ) ;
return 0 ;
V_61:
F_80 ( L_4 , V_6 , V_53 ) ;
F_65 ( V_5 ) ;
return 0 ;
}
static unsigned int F_81 ( struct V_49 * V_50 )
{
return F_76 ( V_50 -> V_6 ) ;
}
static void F_82 ( struct V_49 * V_50 )
{
unsigned int V_6 = V_50 -> V_6 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
unsigned V_5 = F_21 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
if ( ! F_45 ( V_5 ) )
return;
F_43 ( V_5 ) ;
F_65 ( V_5 ) ;
F_20 ( V_11 ) ;
}
static void F_83 ( struct V_49 * V_50 )
{
F_81 ( V_50 ) ;
}
static void F_84 ( struct V_49 * V_50 )
{
F_75 ( V_50 ) ;
}
int F_85 ( unsigned V_28 )
{
struct V_10 * V_11 ;
F_86 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
if ( V_11 -> V_21 . V_27 . V_28 == V_28 )
return V_11 -> V_6 ;
}
return - 1 ;
}
static void F_87 ( unsigned int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( V_11 -> V_36 > 0 ) {
V_11 -> V_36 -- ;
if ( V_11 -> V_36 != 0 )
return;
}
if ( F_45 ( V_5 ) ) {
unsigned int V_13 = F_30 ( V_6 ) ;
F_65 ( V_5 ) ;
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
F_60 ( V_6 ) ;
}
int F_88 ( unsigned V_28 ,
unsigned V_27 , int V_62 , char * V_63 )
{
int V_6 = - 1 ;
struct V_64 V_65 ;
int V_14 ;
F_89 ( & V_66 ) ;
V_6 = F_85 ( V_28 ) ;
if ( V_6 != - 1 ) {
F_90 ( L_5 ,
V_67 , V_6 , V_28 ) ;
goto V_57;
}
V_6 = F_55 ( V_28 ) ;
if ( V_6 < 0 )
goto V_57;
V_65 . V_6 = V_6 ;
V_65 . V_68 = 0 ;
if ( F_57 () &&
F_69 ( V_69 , & V_65 ) ) {
F_60 ( V_6 ) ;
V_6 = - V_70 ;
goto V_57;
}
V_14 = F_19 ( V_6 , 0 , V_27 , V_28 , V_71 ,
V_62 ? V_58 : 0 ) ;
if ( V_14 < 0 ) {
F_87 ( V_6 ) ;
V_6 = V_14 ;
goto V_57;
}
F_68 ( V_6 ) ;
if ( V_62 )
F_91 ( V_6 , & V_72 ,
V_73 , V_63 ) ;
else
F_91 ( V_6 , & V_72 ,
V_74 , V_63 ) ;
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
}
int F_93 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
int V_53 ;
struct V_79 V_80 ;
V_80 . type = V_81 ;
V_53 = F_69 ( V_82 , & V_80 ) ;
F_94 ( V_53 == - V_83 ,
L_6 ) ;
return V_53 ? - 1 : V_80 . V_27 ;
}
int F_95 ( struct V_75 * V_76 , struct V_77 * V_78 ,
int V_27 , int V_39 , const char * V_63 , T_3 V_29 )
{
int V_40 , V_6 , V_14 ;
F_89 ( & V_66 ) ;
V_6 = F_52 ( V_39 ) ;
if ( V_6 < 0 )
goto V_57;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
F_91 ( V_6 + V_40 , & V_72 , V_74 , V_63 ) ;
V_14 = F_19 ( V_6 + V_40 , 0 , V_27 + V_40 , 0 , V_29 ,
V_40 == 0 ? 0 : V_84 ) ;
if ( V_14 < 0 )
goto V_85;
}
V_14 = F_96 ( V_6 , V_78 ) ;
if ( V_14 < 0 )
goto V_85;
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
V_85:
for (; V_40 >= 0 ; V_40 -- )
F_87 ( V_6 + V_40 ) ;
F_92 ( & V_66 ) ;
return V_14 ;
}
int F_97 ( int V_6 )
{
struct V_86 V_87 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_53 = - V_88 ;
F_89 ( & V_66 ) ;
if ( F_57 () && ! ( V_11 -> V_21 . V_27 . V_30 & V_84 ) ) {
V_87 . V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_87 . V_29 = V_11 -> V_21 . V_27 . V_29 ;
V_53 = F_69 ( V_89 , & V_87 ) ;
if ( ( V_53 == - V_90 && V_11 -> V_21 . V_27 . V_29 != V_71 ) )
F_90 ( L_7 ,
V_11 -> V_21 . V_27 . V_29 , V_11 -> V_21 . V_27 . V_27 ) ;
else if ( V_53 ) {
F_77 ( L_8 , V_53 ) ;
goto V_57;
}
}
F_60 ( V_6 ) ;
V_57:
F_92 ( & V_66 ) ;
return V_53 ;
}
int F_98 ( unsigned V_27 )
{
int V_6 ;
struct V_10 * V_11 ;
F_89 ( & V_66 ) ;
F_86 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_6 = V_11 -> V_6 ;
if ( V_11 -> V_21 . V_27 . V_27 == V_27 )
goto V_57;
}
V_6 = - 1 ;
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
}
int F_99 ( unsigned V_6 )
{
return F_28 ( V_6 ) ;
}
int F_100 ( unsigned int V_5 )
{
int V_6 ;
int V_14 ;
if ( V_5 >= F_4 () )
return - V_9 ;
F_89 ( & V_66 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_57;
F_91 ( V_6 , & V_91 ,
V_74 , L_9 ) ;
V_14 = F_15 ( V_6 , V_5 ) ;
if ( V_14 < 0 ) {
F_87 ( V_6 ) ;
V_6 = V_14 ;
goto V_57;
}
F_35 ( V_5 , 0 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_18 ) ;
}
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
}
static int F_101 ( unsigned int V_20 , unsigned int V_13 )
{
struct V_92 V_93 ;
int V_5 , V_6 ;
int V_14 ;
F_89 ( & V_66 ) ;
V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_57;
F_91 ( V_6 , & V_94 ,
V_95 , L_10 ) ;
V_93 . V_96 = V_13 ;
if ( F_66 ( V_97 ,
& V_93 ) != 0 )
F_67 () ;
V_5 = V_93 . V_41 ;
V_14 = F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
if ( V_14 < 0 ) {
F_87 ( V_6 ) ;
V_6 = V_14 ;
goto V_57;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_23 ) ;
}
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
}
int F_102 ( unsigned int V_98 ,
unsigned int V_99 )
{
struct V_100 V_101 ;
int V_61 ;
V_101 . V_102 = V_98 ;
V_101 . V_99 = V_99 ;
V_61 = F_66 ( V_103 ,
& V_101 ) ;
return V_61 ? : F_100 ( V_101 . V_104 ) ;
}
static int F_103 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_105 V_106 ;
int V_41 , V_53 = - V_88 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
for ( V_41 = 0 ; V_41 < F_4 () ; V_41 ++ ) {
V_106 . V_107 = V_71 ;
V_106 . V_41 = V_41 ;
V_53 = F_66 ( V_108 , & V_106 ) ;
if ( V_53 < 0 )
continue;
if ( V_106 . V_106 != V_109 )
continue;
if ( V_106 . V_21 . V_24 == V_24 && V_106 . V_96 == V_13 ) {
V_53 = V_41 ;
break;
}
}
return V_53 ;
}
unsigned F_42 ( void )
{
return V_110 -> V_111 () ;
}
int F_104 ( unsigned int V_24 , unsigned int V_13 , bool V_112 )
{
struct V_113 V_114 ;
int V_5 , V_6 , V_14 ;
F_89 ( & V_66 ) ;
V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_57;
if ( V_112 )
F_91 ( V_6 , & V_94 ,
V_95 , L_11 ) ;
else
F_91 ( V_6 , & V_91 ,
V_74 , L_11 ) ;
V_114 . V_24 = V_24 ;
V_114 . V_96 = V_13 ;
V_14 = F_66 ( V_115 ,
& V_114 ) ;
if ( V_14 == 0 )
V_5 = V_114 . V_41 ;
else {
if ( V_14 == - V_116 )
V_14 = F_103 ( V_24 , V_13 ) ;
F_12 ( V_14 < 0 ) ;
V_5 = V_14 ;
}
V_14 = F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
if ( V_14 < 0 ) {
F_87 ( V_6 ) ;
V_6 = V_14 ;
goto V_57;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_26 ) ;
}
V_57:
F_92 ( & V_66 ) ;
return V_6 ;
}
static void F_105 ( unsigned int V_6 )
{
F_89 ( & V_66 ) ;
F_87 ( V_6 ) ;
F_92 ( & V_66 ) ;
}
int F_106 ( unsigned int V_5 ,
T_4 V_117 ,
unsigned long V_118 ,
const char * V_119 , void * V_120 )
{
int V_6 , V_121 ;
V_6 = F_100 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_121 = F_107 ( V_6 , V_117 , V_118 , V_119 , V_120 ) ;
if ( V_121 != 0 ) {
F_105 ( V_6 ) ;
return V_121 ;
}
return V_6 ;
}
int F_108 ( unsigned int V_98 ,
unsigned int V_99 ,
T_4 V_117 ,
unsigned long V_118 ,
const char * V_119 ,
void * V_120 )
{
int V_6 , V_121 ;
V_6 = F_102 ( V_98 , V_99 ) ;
if ( V_6 < 0 )
return V_6 ;
V_121 = F_107 ( V_6 , V_117 , V_118 , V_119 , V_120 ) ;
if ( V_121 != 0 ) {
F_105 ( V_6 ) ;
return V_121 ;
}
return V_6 ;
}
int F_109 ( unsigned int V_24 , unsigned int V_13 ,
T_4 V_117 ,
unsigned long V_118 , const char * V_119 , void * V_120 )
{
int V_6 , V_121 ;
V_6 = F_104 ( V_24 , V_13 , V_118 & V_122 ) ;
if ( V_6 < 0 )
return V_6 ;
V_121 = F_107 ( V_6 , V_117 , V_118 , V_119 , V_120 ) ;
if ( V_121 != 0 ) {
F_105 ( V_6 ) ;
return V_121 ;
}
return V_6 ;
}
int F_110 ( enum V_19 V_20 ,
unsigned int V_13 ,
T_4 V_117 ,
unsigned long V_118 ,
const char * V_119 ,
void * V_120 )
{
int V_6 , V_121 ;
V_6 = F_101 ( V_20 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_118 |= V_123 | V_124 | V_125 ;
V_121 = F_107 ( V_6 , V_117 , V_118 , V_119 , V_120 ) ;
if ( V_121 != 0 ) {
F_105 ( V_6 ) ;
return V_121 ;
}
return V_6 ;
}
void F_111 ( unsigned int V_6 , void * V_120 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_61 ( ! V_11 ) )
return;
F_112 ( V_6 , V_120 ) ;
F_105 ( V_6 ) ;
}
int F_113 ( unsigned V_6 , unsigned V_126 )
{
struct V_127 V_128 ;
V_128 . V_41 = F_21 ( V_6 ) ;
V_128 . V_126 = V_126 ;
return F_66 ( V_129 ,
& V_128 ) ;
}
int F_114 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
struct V_10 * V_11 ;
if ( V_6 == - 1 )
return - V_88 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_88 ;
F_61 ( V_11 -> V_36 != - 1 ) ;
V_11 -> V_36 = 1 ;
return 0 ;
}
int F_115 ( unsigned int V_5 )
{
int V_6 ;
struct V_10 * V_11 ;
int V_61 = - V_88 ;
if ( V_5 >= F_4 () )
return - V_7 ;
F_89 ( & V_66 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 )
goto V_130;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
goto V_130;
V_61 = - V_7 ;
if ( V_11 -> V_36 <= 0 )
goto V_130;
V_11 -> V_36 ++ ;
V_61 = 0 ;
V_130:
F_92 ( & V_66 ) ;
return V_61 ;
}
void F_116 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
if ( F_61 ( V_6 == - 1 ) )
return;
F_105 ( V_6 ) ;
}
void F_117 ( unsigned int V_13 , enum V_19 V_68 )
{
int V_6 ;
#ifdef F_118
if ( F_22 ( V_68 == V_131 ) ) {
int V_53 = F_119 ( V_132 , V_13 , NULL ) ;
if ( V_53 < 0 )
F_120 ( V_133 L_12 , V_13 , V_53 ) ;
return;
}
#endif
V_6 = F_17 ( V_22 , V_13 ) [ V_68 ] ;
F_12 ( V_6 < 0 ) ;
F_44 ( V_6 ) ;
}
static void F_121 ( void )
{
struct V_134 * V_134 = F_122 ( V_135 ) ;
int V_13 = F_123 () ;
unsigned V_136 ;
do {
V_134 -> V_137 = 0 ;
if ( F_124 ( V_138 ) - 1 )
goto V_57;
F_125 ( V_13 ) ;
F_12 ( ! F_126 () ) ;
V_136 = F_122 ( V_138 ) ;
F_127 ( V_138 , 0 ) ;
} while ( V_136 != 1 || V_134 -> V_137 );
V_57:
F_128 () ;
}
void F_129 ( struct V_139 * V_140 )
{
struct V_139 * V_141 = F_130 ( V_140 ) ;
F_131 () ;
#ifdef F_118
F_132 () ;
F_133 ( V_142 ) ;
#endif
F_121 () ;
F_134 () ;
F_130 ( V_141 ) ;
}
void F_135 ( void )
{
F_121 () ;
}
void F_136 ( int V_5 , int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
if ( F_61 ( ! V_11 ) )
return;
F_137 ( V_6 ) ;
F_89 ( & V_66 ) ;
F_12 ( F_8 ( V_5 ) != - 1 ) ;
F_12 ( V_11 -> type == V_15 ) ;
( void ) F_15 ( V_6 , V_5 ) ;
F_92 ( & V_66 ) ;
F_35 ( V_5 , V_11 -> V_13 ) ;
F_138 ( V_6 , F_39 ( V_11 -> V_13 ) ) ;
F_139 ( V_6 ) ;
}
static int F_140 ( unsigned V_6 , unsigned V_143 )
{
struct V_144 V_145 ;
int V_5 = F_21 ( V_6 ) ;
int V_146 ;
if ( ! F_45 ( V_5 ) )
return - 1 ;
if ( ! F_141 () )
return - 1 ;
V_145 . V_41 = V_5 ;
V_145 . V_96 = V_143 ;
V_146 = F_142 ( V_5 ) ;
if ( F_66 ( V_147 , & V_145 ) >= 0 )
F_35 ( V_5 , V_143 ) ;
if ( ! V_146 )
F_78 ( V_5 ) ;
return 0 ;
}
static int F_143 ( struct V_49 * V_50 , const struct V_148 * V_149 ,
bool V_150 )
{
unsigned V_143 = F_144 ( V_149 , V_151 ) ;
return F_140 ( V_50 -> V_6 , V_143 ) ;
}
static void F_145 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_78 ( V_5 ) ;
}
static void F_75 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_146 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
F_71 ( V_50 ) ;
if ( F_45 ( V_5 ) )
F_72 ( V_5 ) ;
}
static void F_147 ( struct V_49 * V_50 )
{
F_75 ( V_50 ) ;
F_146 ( V_50 ) ;
}
static int F_148 ( struct V_49 * V_50 )
{
unsigned int V_5 = F_21 ( V_50 -> V_6 ) ;
int V_146 ;
if ( ! F_45 ( V_5 ) )
return 0 ;
V_146 = F_142 ( V_5 ) ;
F_149 ( V_5 ) ;
if ( ! V_146 )
F_78 ( V_5 ) ;
return 1 ;
}
static void F_150 ( void )
{
int V_27 , V_53 , V_6 , V_28 ;
struct V_152 V_153 ;
struct V_10 * V_11 ;
F_86 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_28 = V_11 -> V_21 . V_27 . V_28 ;
V_6 = V_11 -> V_6 ;
if ( ! V_28 )
continue;
V_153 . V_29 = V_71 ;
V_153 . type = V_154 ;
V_153 . V_155 = V_28 ;
V_153 . V_27 = V_27 ;
V_53 = F_69 ( V_156 , & V_153 ) ;
if ( V_53 ) {
F_77 ( L_13 ,
V_28 , V_6 , V_27 , V_53 ) ;
F_60 ( V_6 ) ;
continue;
}
F_120 ( V_157 L_14 , V_6 , V_153 . V_27 ) ;
F_76 ( V_6 ) ;
}
}
static void F_151 ( unsigned int V_13 )
{
struct V_113 V_114 ;
int V_24 , V_6 , V_5 ;
for ( V_24 = 0 ; V_24 < V_158 ; V_24 ++ ) {
if ( ( V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ) == - 1 )
continue;
F_12 ( F_27 ( V_6 ) != V_24 ) ;
V_114 . V_24 = V_24 ;
V_114 . V_96 = V_13 ;
if ( F_66 ( V_115 ,
& V_114 ) != 0 )
F_67 () ;
V_5 = V_114 . V_41 ;
( void ) F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
static void F_152 ( unsigned int V_13 )
{
struct V_92 V_93 ;
int V_20 , V_6 , V_5 ;
for ( V_20 = 0 ; V_20 < V_159 ; V_20 ++ ) {
if ( ( V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ) == - 1 )
continue;
F_12 ( F_26 ( V_6 ) != V_20 ) ;
V_93 . V_96 = V_13 ;
if ( F_66 ( V_97 ,
& V_93 ) != 0 )
F_67 () ;
V_5 = V_93 . V_41 ;
( void ) F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
void F_153 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_72 ( V_5 ) ;
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
void F_157 ( int V_6 , T_5 V_160 )
{
T_6 V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) ) {
struct V_161 V_162 ;
V_162 . V_163 = 1 ;
V_162 . V_160 = V_160 ;
F_158 ( V_162 . V_164 , & V_5 ) ;
if ( F_159 ( V_165 , & V_162 ) != 0 )
F_67 () ;
}
}
void F_160 ( int V_6 )
{
F_157 ( V_6 , 0 ) ;
}
int F_161 ( int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
struct V_45 V_46 ;
if ( F_61 ( ! V_11 ) )
return - V_88 ;
V_46 . V_6 = V_11 -> V_21 . V_27 . V_27 ;
if ( F_69 ( V_47 , & V_46 ) )
return 0 ;
return ! ( V_46 . V_30 & V_166 ) ;
}
void F_162 ( void )
{
unsigned int V_13 ;
struct V_10 * V_11 ;
F_41 () ;
F_163 () ;
F_86 (info, &xen_irq_list_head, list)
V_11 -> V_5 = 0 ;
F_2 () ;
F_164 (cpu) {
F_151 ( V_13 ) ;
F_152 ( V_13 ) ;
}
F_150 () ;
}
int F_165 ( T_7 V_167 )
{
struct V_168 V_169 ;
V_169 . V_29 = V_71 ;
V_169 . V_155 = V_170 ;
V_169 . V_171 = V_167 ;
return F_166 ( V_172 , & V_169 ) ;
}
void F_167 ( void )
{
int V_53 ;
T_7 V_173 ;
if ( V_174 ) {
V_173 = F_168 ( V_175 ) ;
V_53 = F_165 ( V_173 ) ;
if ( V_53 ) {
F_80 ( L_15 ) ;
V_174 = 0 ;
return;
}
F_90 ( L_16 ) ;
if ( ! F_33 ( V_175 , V_176 ) )
F_169 ( V_175 ,
V_177 ) ;
}
}
void F_167 ( void ) {}
void T_8 F_170 ( void )
{
int V_14 = - V_7 ;
if ( V_178 )
V_14 = F_171 () ;
if ( V_14 < 0 )
F_172 () ;
V_4 = F_173 ( F_3 ( F_4 () ) ,
sizeof( * V_4 ) , V_8 ) ;
F_12 ( ! V_4 ) ;
F_41 () ;
F_73 = F_34 ;
#ifdef F_118
if ( F_56 () ) {
F_174 ( F_175 () ) ;
if ( F_57 () )
F_176 () ;
}
if ( F_177 ( V_179 ) )
F_167 () ;
if ( F_178 () ) {
F_179 () ;
F_180 () ;
} else {
int V_53 ;
struct V_180 V_181 ;
V_33 = ( void * ) F_181 ( V_8 | V_182 ) ;
V_181 . V_183 = F_182 ( V_33 ) ;
V_53 = F_69 ( V_184 , & V_181 ) ;
if ( V_53 != 0 ) {
F_183 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
} else
F_73 = F_32 ;
}
#endif
}
