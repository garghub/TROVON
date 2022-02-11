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
if ( ! F_45 ( V_5 ) )
return;
if ( F_22 ( F_71 ( V_50 ) ) &&
F_72 ( ! F_73 ( V_50 ) ) ) {
int V_54 = F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
F_76 ( V_50 ) ;
if ( ! V_54 )
F_77 ( V_5 ) ;
} else
F_75 ( V_5 ) ;
if ( F_78 ( V_50 -> V_6 ) ) {
V_53 = F_69 ( V_55 , & V_52 ) ;
F_61 ( V_53 ) ;
}
}
static void F_79 ( struct V_49 * V_50 )
{
F_80 ( V_50 ) ;
F_70 ( V_50 ) ;
}
static unsigned int F_81 ( unsigned int V_6 )
{
struct V_56 V_57 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_5 = F_21 ( V_6 ) ;
int V_53 ;
F_12 ( V_11 -> type != V_31 ) ;
if ( F_45 ( V_5 ) )
goto V_58;
V_57 . V_27 = F_28 ( V_6 ) ;
V_57 . V_30 = V_11 -> V_21 . V_27 . V_30 & V_59 ?
V_60 : 0 ;
V_53 = F_66 ( V_61 , & V_57 ) ;
if ( V_53 != 0 ) {
F_82 ( L_3 , V_6 ) ;
return 0 ;
}
V_5 = V_57 . V_41 ;
F_68 ( V_6 ) ;
V_53 = F_5 ( V_5 , V_6 ) ;
if ( V_53 )
goto V_62;
V_11 -> V_5 = V_5 ;
F_35 ( V_5 , 0 ) ;
V_53 = F_14 ( V_11 ) ;
if ( V_53 )
goto V_62;
V_58:
F_77 ( V_5 ) ;
F_70 ( F_83 ( V_6 ) ) ;
return 0 ;
V_62:
F_84 ( L_4 , V_6 , V_53 ) ;
F_65 ( V_5 ) ;
return 0 ;
}
static unsigned int F_85 ( struct V_49 * V_50 )
{
return F_81 ( V_50 -> V_6 ) ;
}
static void F_86 ( struct V_49 * V_50 )
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
static void F_87 ( struct V_49 * V_50 )
{
F_85 ( V_50 ) ;
}
static void F_88 ( struct V_49 * V_50 )
{
F_80 ( V_50 ) ;
}
int F_89 ( unsigned V_28 )
{
struct V_10 * V_11 ;
F_90 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
if ( V_11 -> V_21 . V_27 . V_28 == V_28 )
return V_11 -> V_6 ;
}
return - 1 ;
}
static void F_91 ( unsigned int V_6 )
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
int F_92 ( unsigned V_28 ,
unsigned V_27 , int V_63 , char * V_64 )
{
int V_6 = - 1 ;
struct V_65 V_66 ;
int V_14 ;
F_93 ( & V_67 ) ;
V_6 = F_89 ( V_28 ) ;
if ( V_6 != - 1 ) {
F_94 ( L_5 ,
V_68 , V_6 , V_28 ) ;
goto V_58;
}
V_6 = F_55 ( V_28 ) ;
if ( V_6 < 0 )
goto V_58;
V_66 . V_6 = V_6 ;
V_66 . V_69 = 0 ;
if ( F_57 () &&
F_69 ( V_70 , & V_66 ) ) {
F_60 ( V_6 ) ;
V_6 = - V_71 ;
goto V_58;
}
V_14 = F_19 ( V_6 , 0 , V_27 , V_28 , V_72 ,
V_63 ? V_59 : 0 ) ;
if ( V_14 < 0 ) {
F_91 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_68 ( V_6 ) ;
if ( V_63 )
F_95 ( V_6 , & V_73 ,
V_74 , V_64 ) ;
else
F_95 ( V_6 , & V_73 ,
V_75 , V_64 ) ;
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
}
int F_97 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
int V_53 ;
struct V_80 V_81 ;
V_81 . type = V_82 ;
V_53 = F_69 ( V_83 , & V_81 ) ;
F_98 ( V_53 == - V_84 ,
L_6 ) ;
return V_53 ? - 1 : V_81 . V_27 ;
}
int F_99 ( struct V_76 * V_77 , struct V_78 * V_79 ,
int V_27 , int V_39 , const char * V_64 , T_3 V_29 )
{
int V_40 , V_6 , V_14 ;
F_93 ( & V_67 ) ;
V_6 = F_52 ( V_39 ) ;
if ( V_6 < 0 )
goto V_58;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
F_95 ( V_6 + V_40 , & V_73 , V_75 , V_64 ) ;
V_14 = F_19 ( V_6 + V_40 , 0 , V_27 + V_40 , 0 , V_29 ,
V_40 == 0 ? 0 : V_85 ) ;
if ( V_14 < 0 )
goto V_86;
}
V_14 = F_100 ( V_6 , V_79 ) ;
if ( V_14 < 0 )
goto V_86;
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
V_86:
for (; V_40 >= 0 ; V_40 -- )
F_91 ( V_6 + V_40 ) ;
F_96 ( & V_67 ) ;
return V_14 ;
}
int F_101 ( int V_6 )
{
struct V_87 V_88 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_53 = - V_89 ;
F_93 ( & V_67 ) ;
if ( F_57 () && ! ( V_11 -> V_21 . V_27 . V_30 & V_85 ) ) {
V_88 . V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_88 . V_29 = V_11 -> V_21 . V_27 . V_29 ;
V_53 = F_69 ( V_90 , & V_88 ) ;
if ( ( V_53 == - V_91 && V_11 -> V_21 . V_27 . V_29 != V_72 ) )
F_94 ( L_7 ,
V_11 -> V_21 . V_27 . V_29 , V_11 -> V_21 . V_27 . V_27 ) ;
else if ( V_53 ) {
F_82 ( L_8 , V_53 ) ;
goto V_58;
}
}
F_60 ( V_6 ) ;
V_58:
F_96 ( & V_67 ) ;
return V_53 ;
}
int F_102 ( unsigned V_27 )
{
int V_6 ;
struct V_10 * V_11 ;
F_93 ( & V_67 ) ;
F_90 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_6 = V_11 -> V_6 ;
if ( V_11 -> V_21 . V_27 . V_27 == V_27 )
goto V_58;
}
V_6 = - 1 ;
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
}
int F_103 ( unsigned V_6 )
{
return F_28 ( V_6 ) ;
}
int F_104 ( unsigned int V_5 )
{
int V_6 ;
int V_14 ;
if ( V_5 >= F_4 () )
return - V_9 ;
F_93 ( & V_67 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
F_95 ( V_6 , & V_92 ,
V_75 , L_9 ) ;
V_14 = F_15 ( V_6 , V_5 ) ;
if ( V_14 < 0 ) {
F_91 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , 0 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_18 ) ;
}
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
}
static int F_105 ( unsigned int V_20 , unsigned int V_13 )
{
struct V_93 V_94 ;
int V_5 , V_6 ;
int V_14 ;
F_93 ( & V_67 ) ;
V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
F_95 ( V_6 , & V_95 ,
V_96 , L_10 ) ;
V_94 . V_97 = F_106 ( V_13 ) ;
if ( F_66 ( V_98 ,
& V_94 ) != 0 )
F_67 () ;
V_5 = V_94 . V_41 ;
V_14 = F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
if ( V_14 < 0 ) {
F_91 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_23 ) ;
}
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
}
int F_107 ( unsigned int V_99 ,
unsigned int V_100 )
{
struct V_101 V_102 ;
int V_62 ;
V_102 . V_103 = V_99 ;
V_102 . V_100 = V_100 ;
V_62 = F_66 ( V_104 ,
& V_102 ) ;
return V_62 ? : F_104 ( V_102 . V_105 ) ;
}
static int F_108 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_106 V_107 ;
int V_41 , V_53 = - V_89 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
for ( V_41 = 0 ; V_41 < F_4 () ; V_41 ++ ) {
V_107 . V_108 = V_72 ;
V_107 . V_41 = V_41 ;
V_53 = F_66 ( V_109 , & V_107 ) ;
if ( V_53 < 0 )
continue;
if ( V_107 . V_107 != V_110 )
continue;
if ( V_107 . V_21 . V_24 == V_24 && V_107 . V_97 == F_106 ( V_13 ) ) {
V_53 = V_41 ;
break;
}
}
return V_53 ;
}
unsigned F_42 ( void )
{
return V_111 -> V_112 () ;
}
int F_109 ( unsigned int V_24 , unsigned int V_13 , bool V_113 )
{
struct V_114 V_115 ;
int V_5 , V_6 , V_14 ;
F_93 ( & V_67 ) ;
V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
if ( V_113 )
F_95 ( V_6 , & V_95 ,
V_96 , L_11 ) ;
else
F_95 ( V_6 , & V_92 ,
V_75 , L_11 ) ;
V_115 . V_24 = V_24 ;
V_115 . V_97 = F_106 ( V_13 ) ;
V_14 = F_66 ( V_116 ,
& V_115 ) ;
if ( V_14 == 0 )
V_5 = V_115 . V_41 ;
else {
if ( V_14 == - V_117 )
V_14 = F_108 ( V_24 , V_13 ) ;
F_12 ( V_14 < 0 ) ;
V_5 = V_14 ;
}
V_14 = F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
if ( V_14 < 0 ) {
F_91 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_61 ( V_11 == NULL || V_11 -> type != V_26 ) ;
}
V_58:
F_96 ( & V_67 ) ;
return V_6 ;
}
static void F_110 ( unsigned int V_6 )
{
F_93 ( & V_67 ) ;
F_91 ( V_6 ) ;
F_96 ( & V_67 ) ;
}
int F_111 ( unsigned int V_5 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 , void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_104 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_112 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_110 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_113 ( unsigned int V_99 ,
unsigned int V_100 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 ,
void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_107 ( V_99 , V_100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_112 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_110 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_114 ( unsigned int V_24 , unsigned int V_13 ,
T_4 V_118 ,
unsigned long V_119 , const char * V_120 , void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_109 ( V_24 , V_13 , V_119 & V_123 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_112 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_110 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_115 ( enum V_19 V_20 ,
unsigned int V_13 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 ,
void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_105 ( V_20 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_119 |= V_124 | V_125 | V_126 ;
V_122 = F_112 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_110 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
void F_116 ( unsigned int V_6 , void * V_121 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_61 ( ! V_11 ) )
return;
F_117 ( V_6 , V_121 ) ;
F_110 ( V_6 ) ;
}
int F_118 ( unsigned V_6 , unsigned V_127 )
{
struct V_128 V_129 ;
V_129 . V_41 = F_21 ( V_6 ) ;
V_129 . V_127 = V_127 ;
return F_66 ( V_130 ,
& V_129 ) ;
}
int F_119 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
struct V_10 * V_11 ;
if ( V_6 == - 1 )
return - V_89 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_89 ;
F_61 ( V_11 -> V_36 != - 1 ) ;
V_11 -> V_36 = 1 ;
return 0 ;
}
int F_120 ( unsigned int V_5 )
{
int V_6 ;
struct V_10 * V_11 ;
int V_62 = - V_89 ;
if ( V_5 >= F_4 () )
return - V_7 ;
F_93 ( & V_67 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 )
goto V_131;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
goto V_131;
V_62 = - V_7 ;
if ( V_11 -> V_36 <= 0 )
goto V_131;
V_11 -> V_36 ++ ;
V_62 = 0 ;
V_131:
F_96 ( & V_67 ) ;
return V_62 ;
}
void F_121 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
if ( F_61 ( V_6 == - 1 ) )
return;
F_110 ( V_6 ) ;
}
void F_122 ( unsigned int V_13 , enum V_19 V_69 )
{
int V_6 ;
#ifdef F_123
if ( F_22 ( V_69 == V_132 ) ) {
int V_53 = F_124 ( V_133 , F_106 ( V_13 ) ,
NULL ) ;
if ( V_53 < 0 )
F_125 ( V_134 L_12 , V_13 , V_53 ) ;
return;
}
#endif
V_6 = F_17 ( V_22 , V_13 ) [ V_69 ] ;
F_12 ( V_6 < 0 ) ;
F_44 ( V_6 ) ;
}
static void F_126 ( void )
{
struct V_135 * V_135 = F_127 ( V_136 ) ;
int V_13 = F_128 () ;
unsigned V_137 ;
do {
V_135 -> V_138 = 0 ;
if ( F_129 ( V_139 ) - 1 )
goto V_58;
F_130 ( V_13 ) ;
F_12 ( ! F_131 () ) ;
V_137 = F_127 ( V_139 ) ;
F_132 ( V_139 , 0 ) ;
} while ( V_137 != 1 || V_135 -> V_138 );
V_58:
F_133 () ;
}
void F_134 ( struct V_140 * V_141 )
{
struct V_140 * V_142 = F_135 ( V_141 ) ;
F_136 () ;
#ifdef F_123
F_137 ( V_143 ) ;
#endif
F_126 () ;
F_138 () ;
F_135 ( V_142 ) ;
}
void F_139 ( void )
{
F_126 () ;
}
void F_140 ( int V_5 , int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
if ( F_61 ( ! V_11 ) )
return;
F_141 ( V_6 ) ;
F_93 ( & V_67 ) ;
F_12 ( F_8 ( V_5 ) != - 1 ) ;
F_12 ( V_11 -> type == V_15 ) ;
( void ) F_15 ( V_6 , V_5 ) ;
F_96 ( & V_67 ) ;
F_35 ( V_5 , V_11 -> V_13 ) ;
F_142 ( V_6 , F_39 ( V_11 -> V_13 ) ) ;
F_143 ( V_6 ) ;
}
static int F_144 ( unsigned V_6 , unsigned V_144 )
{
struct V_145 V_146 ;
int V_5 = F_21 ( V_6 ) ;
int V_54 ;
if ( ! F_45 ( V_5 ) )
return - 1 ;
V_146 . V_41 = V_5 ;
V_146 . V_97 = F_106 ( V_144 ) ;
V_54 = F_74 ( V_5 ) ;
if ( F_66 ( V_147 , & V_146 ) >= 0 )
F_35 ( V_5 , V_144 ) ;
if ( ! V_54 )
F_77 ( V_5 ) ;
return 0 ;
}
static int F_145 ( struct V_49 * V_50 , const struct V_148 * V_149 ,
bool V_150 )
{
unsigned V_144 = F_146 ( V_149 , V_151 ) ;
return F_144 ( V_50 -> V_6 , V_144 ) ;
}
static void F_147 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_77 ( V_5 ) ;
}
static void F_80 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_148 ( struct V_49 * V_50 )
{
int V_5 = F_21 ( V_50 -> V_6 ) ;
if ( ! F_45 ( V_5 ) )
return;
if ( F_22 ( F_71 ( V_50 ) ) &&
F_72 ( ! F_73 ( V_50 ) ) ) {
int V_54 = F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
F_76 ( V_50 ) ;
if ( ! V_54 )
F_77 ( V_5 ) ;
} else
F_75 ( V_5 ) ;
}
static void F_149 ( struct V_49 * V_50 )
{
F_80 ( V_50 ) ;
F_148 ( V_50 ) ;
}
static int F_150 ( struct V_49 * V_50 )
{
unsigned int V_5 = F_21 ( V_50 -> V_6 ) ;
int V_54 ;
if ( ! F_45 ( V_5 ) )
return 0 ;
V_54 = F_74 ( V_5 ) ;
F_151 ( V_5 ) ;
if ( ! V_54 )
F_77 ( V_5 ) ;
return 1 ;
}
static void F_152 ( void )
{
int V_27 , V_53 , V_6 , V_28 ;
struct V_152 V_153 ;
struct V_10 * V_11 ;
F_90 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_28 = V_11 -> V_21 . V_27 . V_28 ;
V_6 = V_11 -> V_6 ;
if ( ! V_28 )
continue;
V_153 . V_29 = V_72 ;
V_153 . type = V_154 ;
V_153 . V_155 = V_28 ;
V_153 . V_27 = V_27 ;
V_53 = F_69 ( V_156 , & V_153 ) ;
if ( V_53 ) {
F_82 ( L_13 ,
V_28 , V_6 , V_27 , V_53 ) ;
F_60 ( V_6 ) ;
continue;
}
F_125 ( V_157 L_14 , V_6 , V_153 . V_27 ) ;
F_81 ( V_6 ) ;
}
}
static void F_153 ( unsigned int V_13 )
{
struct V_114 V_115 ;
int V_24 , V_6 , V_5 ;
for ( V_24 = 0 ; V_24 < V_158 ; V_24 ++ ) {
if ( ( V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ) == - 1 )
continue;
F_12 ( F_27 ( V_6 ) != V_24 ) ;
V_115 . V_24 = V_24 ;
V_115 . V_97 = F_106 ( V_13 ) ;
if ( F_66 ( V_116 ,
& V_115 ) != 0 )
F_67 () ;
V_5 = V_115 . V_41 ;
( void ) F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
static void F_154 ( unsigned int V_13 )
{
struct V_93 V_94 ;
int V_20 , V_6 , V_5 ;
for ( V_20 = 0 ; V_20 < V_159 ; V_20 ++ ) {
if ( ( V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ) == - 1 )
continue;
F_12 ( F_26 ( V_6 ) != V_20 ) ;
V_94 . V_97 = F_106 ( V_13 ) ;
if ( F_66 ( V_98 ,
& V_94 ) != 0 )
F_67 () ;
V_5 = V_94 . V_41 ;
( void ) F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
void F_155 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_75 ( V_5 ) ;
}
void F_156 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_151 ( V_5 ) ;
}
bool F_157 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
bool V_14 = false ;
if ( F_45 ( V_5 ) )
V_14 = F_158 ( V_5 ) ;
return V_14 ;
}
void F_159 ( int V_6 , T_5 V_160 )
{
T_6 V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) ) {
struct V_161 V_162 ;
V_162 . V_163 = 1 ;
V_162 . V_160 = V_160 ;
F_160 ( V_162 . V_164 , & V_5 ) ;
if ( F_161 ( V_165 , & V_162 ) != 0 )
F_67 () ;
}
}
void F_162 ( int V_6 )
{
F_159 ( V_6 , 0 ) ;
}
int F_163 ( int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
struct V_45 V_46 ;
if ( F_61 ( ! V_11 ) )
return - V_89 ;
V_46 . V_6 = V_11 -> V_21 . V_27 . V_27 ;
if ( F_69 ( V_47 , & V_46 ) )
return 0 ;
return ! ( V_46 . V_30 & V_166 ) ;
}
void F_164 ( void )
{
unsigned int V_13 ;
struct V_10 * V_11 ;
F_41 () ;
F_165 () ;
F_90 (info, &xen_irq_list_head, list)
V_11 -> V_5 = 0 ;
F_2 () ;
F_166 (cpu) {
F_153 ( V_13 ) ;
F_154 ( V_13 ) ;
}
F_152 () ;
}
int F_167 ( T_7 V_167 )
{
struct V_168 V_169 ;
V_169 . V_29 = V_72 ;
V_169 . V_155 = V_170 ;
V_169 . V_171 = V_167 ;
return F_168 ( V_172 , & V_169 ) ;
}
void F_169 ( void )
{
int V_53 ;
T_7 V_173 ;
V_173 = F_170 ( V_174 ) ;
V_53 = F_167 ( V_173 ) ;
F_12 ( V_53 ) ;
F_94 ( L_15 ) ;
if ( ! F_33 ( V_174 , V_175 ) )
F_171 ( V_174 ,
V_176 ) ;
}
void F_169 ( void ) {}
void T_8 F_172 ( void )
{
int V_14 = - V_7 ;
if ( V_177 )
V_14 = F_173 () ;
if ( V_14 < 0 )
F_174 () ;
V_4 = F_175 ( F_3 ( F_4 () ) ,
sizeof( * V_4 ) , V_8 ) ;
F_12 ( ! V_4 ) ;
F_41 () ;
F_78 = F_34 ;
#ifdef F_123
if ( F_56 () ) {
F_176 ( F_177 () ) ;
if ( F_57 () )
F_178 () ;
}
if ( F_179 ( V_178 ) )
F_169 () ;
if ( F_180 () ) {
F_181 () ;
F_182 () ;
} else {
int V_53 ;
struct V_179 V_180 ;
V_33 = ( void * ) F_183 ( V_8 | V_181 ) ;
V_180 . V_182 = F_184 ( V_33 ) ;
V_53 = F_69 ( V_183 , & V_180 ) ;
if ( V_53 != 0 ) {
F_185 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
} else
F_78 = F_32 ;
}
#endif
}
