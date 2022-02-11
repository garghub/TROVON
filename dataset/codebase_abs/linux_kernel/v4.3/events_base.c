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
if ( V_28 < V_41 )
V_6 = V_28 ;
else
V_6 = F_58 ( V_28 , - 1 ) ;
F_47 ( V_6 ) ;
return V_6 ;
}
static void F_59 ( unsigned V_6 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_60 ( ! V_11 ) )
return;
F_61 ( & V_11 -> V_37 ) ;
F_50 ( V_6 , NULL ) ;
F_60 ( V_11 -> V_36 > 0 ) ;
F_62 ( V_11 ) ;
if ( V_6 < V_41 )
return;
F_63 ( V_6 ) ;
}
static void F_64 ( unsigned int V_42 )
{
struct V_43 V_44 ;
V_44 . V_42 = V_42 ;
if ( F_65 ( V_45 , & V_44 ) != 0 )
F_66 () ;
}
static void F_67 ( int V_6 )
{
struct V_46 V_47 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
V_47 . V_6 = F_28 ( V_6 ) ;
if ( F_68 ( V_48 , & V_47 ) )
V_47 . V_30 = 0 ;
V_11 -> V_21 . V_27 . V_30 &= ~ V_34 ;
if ( V_47 . V_30 & V_49 )
V_11 -> V_21 . V_27 . V_30 |= V_34 ;
}
static void F_69 ( struct V_50 * V_51 )
{
int V_5 = F_21 ( V_51 -> V_6 ) ;
struct V_52 V_53 = { . V_6 = F_28 (data->irq) } ;
int V_54 = 0 ;
F_70 ( V_51 ) ;
if ( F_45 ( V_5 ) )
F_71 ( V_5 ) ;
if ( F_72 ( V_51 -> V_6 ) ) {
V_54 = F_68 ( V_55 , & V_53 ) ;
F_60 ( V_54 ) ;
}
}
static void F_73 ( struct V_50 * V_51 )
{
F_74 ( V_51 ) ;
F_69 ( V_51 ) ;
}
static unsigned int F_75 ( unsigned int V_6 )
{
struct V_56 V_57 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_5 = F_21 ( V_6 ) ;
int V_54 ;
F_12 ( V_11 -> type != V_31 ) ;
if ( F_45 ( V_5 ) )
goto V_58;
V_57 . V_27 = F_28 ( V_6 ) ;
V_57 . V_30 = V_11 -> V_21 . V_27 . V_30 & V_59 ?
V_60 : 0 ;
V_54 = F_65 ( V_61 , & V_57 ) ;
if ( V_54 != 0 ) {
F_76 ( L_3 , V_6 ) ;
return 0 ;
}
V_5 = V_57 . V_42 ;
F_67 ( V_6 ) ;
V_54 = F_5 ( V_5 , V_6 ) ;
if ( V_54 )
goto V_62;
V_11 -> V_5 = V_5 ;
F_35 ( V_5 , 0 ) ;
V_54 = F_14 ( V_11 ) ;
if ( V_54 )
goto V_62;
V_58:
F_77 ( V_5 ) ;
F_69 ( F_78 ( V_6 ) ) ;
return 0 ;
V_62:
F_79 ( L_4 , V_6 , V_54 ) ;
F_64 ( V_5 ) ;
return 0 ;
}
static unsigned int F_80 ( struct V_50 * V_51 )
{
return F_75 ( V_51 -> V_6 ) ;
}
static void F_81 ( struct V_50 * V_51 )
{
unsigned int V_6 = V_51 -> V_6 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
unsigned V_5 = F_21 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
if ( ! F_45 ( V_5 ) )
return;
F_43 ( V_5 ) ;
F_64 ( V_5 ) ;
F_20 ( V_11 ) ;
}
static void F_82 ( struct V_50 * V_51 )
{
F_80 ( V_51 ) ;
}
static void F_83 ( struct V_50 * V_51 )
{
F_74 ( V_51 ) ;
}
int F_84 ( unsigned V_28 )
{
struct V_10 * V_11 ;
F_85 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
if ( V_11 -> V_21 . V_27 . V_28 == V_28 )
return V_11 -> V_6 ;
}
return - 1 ;
}
static void F_86 ( unsigned int V_6 )
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
F_64 ( V_5 ) ;
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
F_59 ( V_6 ) ;
}
int F_87 ( unsigned V_28 ,
unsigned V_27 , int V_63 , char * V_64 )
{
int V_6 = - 1 ;
struct V_65 V_66 ;
int V_14 ;
F_88 ( & V_67 ) ;
V_6 = F_84 ( V_28 ) ;
if ( V_6 != - 1 ) {
F_89 ( L_5 ,
V_68 , V_6 , V_28 ) ;
goto V_58;
}
V_6 = F_55 ( V_28 ) ;
if ( V_6 < 0 )
goto V_58;
V_66 . V_6 = V_6 ;
V_66 . V_69 = 0 ;
if ( F_57 () &&
F_68 ( V_70 , & V_66 ) ) {
F_59 ( V_6 ) ;
V_6 = - V_71 ;
goto V_58;
}
V_14 = F_19 ( V_6 , 0 , V_27 , V_28 , V_72 ,
V_63 ? V_59 : 0 ) ;
if ( V_14 < 0 ) {
F_86 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_67 ( V_6 ) ;
if ( V_63 )
F_90 ( V_6 , & V_73 ,
V_74 , V_64 ) ;
else
F_90 ( V_6 , & V_73 ,
V_75 , V_64 ) ;
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
}
int F_92 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
int V_54 ;
struct V_80 V_81 ;
V_81 . type = V_82 ;
V_54 = F_68 ( V_83 , & V_81 ) ;
F_93 ( V_54 == - V_84 ,
L_6 ) ;
return V_54 ? - 1 : V_81 . V_27 ;
}
int F_94 ( struct V_76 * V_77 , struct V_78 * V_79 ,
int V_27 , int V_39 , const char * V_64 , T_3 V_29 )
{
int V_40 , V_6 , V_14 ;
F_88 ( & V_67 ) ;
V_6 = F_52 ( V_39 ) ;
if ( V_6 < 0 )
goto V_58;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
F_90 ( V_6 + V_40 , & V_73 , V_75 , V_64 ) ;
V_14 = F_19 ( V_6 + V_40 , 0 , V_27 + V_40 , 0 , V_29 ,
V_40 == 0 ? 0 : V_85 ) ;
if ( V_14 < 0 )
goto V_86;
}
V_14 = F_95 ( V_6 , V_79 ) ;
if ( V_14 < 0 )
goto V_86;
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
V_86:
for (; V_40 >= 0 ; V_40 -- )
F_86 ( V_6 + V_40 ) ;
F_91 ( & V_67 ) ;
return V_14 ;
}
int F_96 ( int V_6 )
{
struct V_87 V_88 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_54 = - V_89 ;
F_88 ( & V_67 ) ;
if ( F_57 () && ! ( V_11 -> V_21 . V_27 . V_30 & V_85 ) ) {
V_88 . V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_88 . V_29 = V_11 -> V_21 . V_27 . V_29 ;
V_54 = F_68 ( V_90 , & V_88 ) ;
if ( ( V_54 == - V_91 && V_11 -> V_21 . V_27 . V_29 != V_72 ) )
F_89 ( L_7 ,
V_11 -> V_21 . V_27 . V_29 , V_11 -> V_21 . V_27 . V_27 ) ;
else if ( V_54 ) {
F_76 ( L_8 , V_54 ) ;
goto V_58;
}
}
F_59 ( V_6 ) ;
V_58:
F_91 ( & V_67 ) ;
return V_54 ;
}
int F_97 ( unsigned V_27 )
{
int V_6 ;
struct V_10 * V_11 ;
F_88 ( & V_67 ) ;
F_85 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_6 = V_11 -> V_6 ;
if ( V_11 -> V_21 . V_27 . V_27 == V_27 )
goto V_58;
}
V_6 = - 1 ;
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
}
int F_98 ( unsigned V_6 )
{
return F_28 ( V_6 ) ;
}
int F_99 ( unsigned int V_5 )
{
int V_6 ;
int V_14 ;
if ( V_5 >= F_4 () )
return - V_9 ;
F_88 ( & V_67 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
F_90 ( V_6 , & V_92 ,
V_75 , L_9 ) ;
V_14 = F_15 ( V_6 , V_5 ) ;
if ( V_14 < 0 ) {
F_86 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , 0 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_60 ( V_11 == NULL || V_11 -> type != V_18 ) ;
}
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
}
static int F_100 ( unsigned int V_20 , unsigned int V_13 )
{
struct V_93 V_94 ;
int V_5 , V_6 ;
int V_14 ;
F_88 ( & V_67 ) ;
V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
F_90 ( V_6 , & V_95 ,
V_96 , L_10 ) ;
V_94 . V_97 = V_13 ;
if ( F_65 ( V_98 ,
& V_94 ) != 0 )
F_66 () ;
V_5 = V_94 . V_42 ;
V_14 = F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
if ( V_14 < 0 ) {
F_86 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_60 ( V_11 == NULL || V_11 -> type != V_23 ) ;
}
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
}
int F_101 ( unsigned int V_99 ,
unsigned int V_100 )
{
struct V_101 V_102 ;
int V_62 ;
V_102 . V_103 = V_99 ;
V_102 . V_100 = V_100 ;
V_62 = F_65 ( V_104 ,
& V_102 ) ;
return V_62 ? : F_99 ( V_102 . V_105 ) ;
}
static int F_102 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_106 V_107 ;
int V_42 , V_54 = - V_89 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
for ( V_42 = 0 ; V_42 < F_4 () ; V_42 ++ ) {
V_107 . V_108 = V_72 ;
V_107 . V_42 = V_42 ;
V_54 = F_65 ( V_109 , & V_107 ) ;
if ( V_54 < 0 )
continue;
if ( V_107 . V_107 != V_110 )
continue;
if ( V_107 . V_21 . V_24 == V_24 && V_107 . V_97 == V_13 ) {
V_54 = V_42 ;
break;
}
}
return V_54 ;
}
unsigned F_42 ( void )
{
return V_111 -> V_112 () ;
}
int F_103 ( unsigned int V_24 , unsigned int V_13 , bool V_113 )
{
struct V_114 V_115 ;
int V_5 , V_6 , V_14 ;
F_88 ( & V_67 ) ;
V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ;
if ( V_6 == - 1 ) {
V_6 = F_54 () ;
if ( V_6 < 0 )
goto V_58;
if ( V_113 )
F_90 ( V_6 , & V_95 ,
V_96 , L_11 ) ;
else
F_90 ( V_6 , & V_92 ,
V_75 , L_11 ) ;
V_115 . V_24 = V_24 ;
V_115 . V_97 = V_13 ;
V_14 = F_65 ( V_116 ,
& V_115 ) ;
if ( V_14 == 0 )
V_5 = V_115 . V_42 ;
else {
if ( V_14 == - V_117 )
V_14 = F_102 ( V_24 , V_13 ) ;
F_12 ( V_14 < 0 ) ;
V_5 = V_14 ;
}
V_14 = F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
if ( V_14 < 0 ) {
F_86 ( V_6 ) ;
V_6 = V_14 ;
goto V_58;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_60 ( V_11 == NULL || V_11 -> type != V_26 ) ;
}
V_58:
F_91 ( & V_67 ) ;
return V_6 ;
}
static void F_104 ( unsigned int V_6 )
{
F_88 ( & V_67 ) ;
F_86 ( V_6 ) ;
F_91 ( & V_67 ) ;
}
int F_105 ( unsigned int V_5 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 , void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_99 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_106 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_104 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_107 ( unsigned int V_99 ,
unsigned int V_100 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 ,
void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_101 ( V_99 , V_100 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_106 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_104 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_108 ( unsigned int V_24 , unsigned int V_13 ,
T_4 V_118 ,
unsigned long V_119 , const char * V_120 , void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_103 ( V_24 , V_13 , V_119 & V_123 ) ;
if ( V_6 < 0 )
return V_6 ;
V_122 = F_106 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_104 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
int F_109 ( enum V_19 V_20 ,
unsigned int V_13 ,
T_4 V_118 ,
unsigned long V_119 ,
const char * V_120 ,
void * V_121 )
{
int V_6 , V_122 ;
V_6 = F_100 ( V_20 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_119 |= V_124 | V_125 | V_126 ;
V_122 = F_106 ( V_6 , V_118 , V_119 , V_120 , V_121 ) ;
if ( V_122 != 0 ) {
F_104 ( V_6 ) ;
return V_122 ;
}
return V_6 ;
}
void F_110 ( unsigned int V_6 , void * V_121 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_60 ( ! V_11 ) )
return;
F_111 ( V_6 , V_121 ) ;
F_104 ( V_6 ) ;
}
int F_112 ( unsigned V_6 , unsigned V_127 )
{
struct V_128 V_129 ;
V_129 . V_42 = F_21 ( V_6 ) ;
V_129 . V_127 = V_127 ;
return F_65 ( V_130 ,
& V_129 ) ;
}
int F_113 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
struct V_10 * V_11 ;
if ( V_6 == - 1 )
return - V_89 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_89 ;
F_60 ( V_11 -> V_36 != - 1 ) ;
V_11 -> V_36 = 1 ;
return 0 ;
}
int F_114 ( unsigned int V_5 )
{
int V_6 ;
struct V_10 * V_11 ;
int V_62 = - V_89 ;
if ( V_5 >= F_4 () )
return - V_7 ;
F_88 ( & V_67 ) ;
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
F_91 ( & V_67 ) ;
return V_62 ;
}
void F_115 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
if ( F_60 ( V_6 == - 1 ) )
return;
F_104 ( V_6 ) ;
}
void F_116 ( unsigned int V_13 , enum V_19 V_69 )
{
int V_6 ;
#ifdef F_117
if ( F_22 ( V_69 == V_132 ) ) {
int V_54 = F_118 ( V_133 , V_13 , NULL ) ;
if ( V_54 < 0 )
F_119 ( V_134 L_12 , V_13 , V_54 ) ;
return;
}
#endif
V_6 = F_17 ( V_22 , V_13 ) [ V_69 ] ;
F_12 ( V_6 < 0 ) ;
F_44 ( V_6 ) ;
}
static void F_120 ( void )
{
struct V_135 * V_135 = F_121 ( V_136 ) ;
int V_13 = F_122 () ;
unsigned V_137 ;
do {
V_135 -> V_138 = 0 ;
if ( F_123 ( V_139 ) - 1 )
goto V_58;
F_124 ( V_13 ) ;
F_12 ( ! F_125 () ) ;
V_137 = F_121 ( V_139 ) ;
F_126 ( V_139 , 0 ) ;
} while ( V_137 != 1 || V_135 -> V_138 );
V_58:
F_127 () ;
}
void F_128 ( struct V_140 * V_141 )
{
struct V_140 * V_142 = F_129 ( V_141 ) ;
F_130 () ;
#ifdef F_117
F_131 () ;
F_132 ( V_143 ) ;
#endif
F_120 () ;
F_133 () ;
F_129 ( V_142 ) ;
}
void F_134 ( void )
{
F_120 () ;
}
void F_135 ( int V_5 , int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
if ( F_60 ( ! V_11 ) )
return;
F_136 ( V_6 ) ;
F_88 ( & V_67 ) ;
F_12 ( F_8 ( V_5 ) != - 1 ) ;
F_12 ( V_11 -> type == V_15 ) ;
( void ) F_15 ( V_6 , V_5 ) ;
F_91 ( & V_67 ) ;
F_35 ( V_5 , V_11 -> V_13 ) ;
F_137 ( V_6 , F_39 ( V_11 -> V_13 ) ) ;
F_138 ( V_6 ) ;
}
static int F_139 ( unsigned V_6 , unsigned V_144 )
{
struct V_145 V_146 ;
int V_5 = F_21 ( V_6 ) ;
int V_147 ;
if ( ! F_45 ( V_5 ) )
return - 1 ;
if ( ! F_140 () )
return - 1 ;
V_146 . V_42 = V_5 ;
V_146 . V_97 = V_144 ;
V_147 = F_141 ( V_5 ) ;
if ( F_65 ( V_148 , & V_146 ) >= 0 )
F_35 ( V_5 , V_144 ) ;
if ( ! V_147 )
F_77 ( V_5 ) ;
return 0 ;
}
static int F_142 ( struct V_50 * V_51 , const struct V_149 * V_150 ,
bool V_151 )
{
unsigned V_144 = F_143 ( V_150 , V_152 ) ;
return F_139 ( V_51 -> V_6 , V_144 ) ;
}
static void F_144 ( struct V_50 * V_51 )
{
int V_5 = F_21 ( V_51 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_77 ( V_5 ) ;
}
static void F_74 ( struct V_50 * V_51 )
{
int V_5 = F_21 ( V_51 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_145 ( struct V_50 * V_51 )
{
int V_5 = F_21 ( V_51 -> V_6 ) ;
F_70 ( V_51 ) ;
if ( F_45 ( V_5 ) )
F_71 ( V_5 ) ;
}
static void F_146 ( struct V_50 * V_51 )
{
F_74 ( V_51 ) ;
F_145 ( V_51 ) ;
}
static int F_147 ( struct V_50 * V_51 )
{
unsigned int V_5 = F_21 ( V_51 -> V_6 ) ;
int V_147 ;
if ( ! F_45 ( V_5 ) )
return 0 ;
V_147 = F_141 ( V_5 ) ;
F_148 ( V_5 ) ;
if ( ! V_147 )
F_77 ( V_5 ) ;
return 1 ;
}
static void F_149 ( void )
{
int V_27 , V_54 , V_6 , V_28 ;
struct V_153 V_154 ;
struct V_10 * V_11 ;
F_85 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_28 = V_11 -> V_21 . V_27 . V_28 ;
V_6 = V_11 -> V_6 ;
if ( ! V_28 )
continue;
V_154 . V_29 = V_72 ;
V_154 . type = V_155 ;
V_154 . V_156 = V_28 ;
V_154 . V_27 = V_27 ;
V_54 = F_68 ( V_157 , & V_154 ) ;
if ( V_54 ) {
F_76 ( L_13 ,
V_28 , V_6 , V_27 , V_54 ) ;
F_59 ( V_6 ) ;
continue;
}
F_119 ( V_158 L_14 , V_6 , V_154 . V_27 ) ;
F_75 ( V_6 ) ;
}
}
static void F_150 ( unsigned int V_13 )
{
struct V_114 V_115 ;
int V_24 , V_6 , V_5 ;
for ( V_24 = 0 ; V_24 < V_159 ; V_24 ++ ) {
if ( ( V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ) == - 1 )
continue;
F_12 ( F_27 ( V_6 ) != V_24 ) ;
V_115 . V_24 = V_24 ;
V_115 . V_97 = V_13 ;
if ( F_65 ( V_116 ,
& V_115 ) != 0 )
F_66 () ;
V_5 = V_115 . V_42 ;
( void ) F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
static void F_151 ( unsigned int V_13 )
{
struct V_93 V_94 ;
int V_20 , V_6 , V_5 ;
for ( V_20 = 0 ; V_20 < V_160 ; V_20 ++ ) {
if ( ( V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ) == - 1 )
continue;
F_12 ( F_26 ( V_6 ) != V_20 ) ;
V_94 . V_97 = V_13 ;
if ( F_65 ( V_98 ,
& V_94 ) != 0 )
F_66 () ;
V_5 = V_94 . V_42 ;
( void ) F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
void F_152 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_71 ( V_5 ) ;
}
void F_153 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_148 ( V_5 ) ;
}
bool F_154 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
bool V_14 = false ;
if ( F_45 ( V_5 ) )
V_14 = F_155 ( V_5 ) ;
return V_14 ;
}
void F_156 ( int V_6 , T_5 V_161 )
{
T_6 V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) ) {
struct V_162 V_163 ;
V_163 . V_164 = 1 ;
V_163 . V_161 = V_161 ;
F_157 ( V_163 . V_165 , & V_5 ) ;
if ( F_158 ( V_166 , & V_163 ) != 0 )
F_66 () ;
}
}
void F_159 ( int V_6 )
{
F_156 ( V_6 , 0 ) ;
}
int F_160 ( int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
struct V_46 V_47 ;
if ( F_60 ( ! V_11 ) )
return - V_89 ;
V_47 . V_6 = V_11 -> V_21 . V_27 . V_27 ;
if ( F_68 ( V_48 , & V_47 ) )
return 0 ;
return ! ( V_47 . V_30 & V_167 ) ;
}
void F_161 ( void )
{
unsigned int V_13 ;
struct V_10 * V_11 ;
F_41 () ;
F_162 () ;
F_85 (info, &xen_irq_list_head, list)
V_11 -> V_5 = 0 ;
F_2 () ;
F_163 (cpu) {
F_150 ( V_13 ) ;
F_151 ( V_13 ) ;
}
F_149 () ;
}
int F_164 ( T_7 V_168 )
{
struct V_169 V_170 ;
V_170 . V_29 = V_72 ;
V_170 . V_156 = V_171 ;
V_170 . V_172 = V_168 ;
return F_165 ( V_173 , & V_170 ) ;
}
void F_166 ( void )
{
int V_54 ;
T_7 V_174 ;
if ( V_175 ) {
V_174 = F_167 ( V_176 ) ;
V_54 = F_164 ( V_174 ) ;
if ( V_54 ) {
F_79 ( L_15 ) ;
V_175 = 0 ;
return;
}
F_89 ( L_16 ) ;
if ( ! F_33 ( V_176 , V_177 ) )
F_168 ( V_176 ,
V_178 ) ;
}
}
void F_166 ( void ) {}
void T_8 F_169 ( void )
{
int V_14 = - V_7 ;
if ( V_179 )
V_14 = F_170 () ;
if ( V_14 < 0 )
F_171 () ;
V_4 = F_172 ( F_3 ( F_4 () ) ,
sizeof( * V_4 ) , V_8 ) ;
F_12 ( ! V_4 ) ;
F_41 () ;
F_72 = F_34 ;
#ifdef F_117
if ( F_56 () ) {
F_173 ( F_174 () ) ;
if ( F_57 () )
F_175 () ;
}
if ( F_176 ( V_180 ) )
F_166 () ;
if ( F_177 () ) {
F_178 () ;
F_179 () ;
} else {
int V_54 ;
struct V_181 V_182 ;
V_33 = ( void * ) F_180 ( V_8 | V_183 ) ;
V_182 . V_184 = F_181 ( V_33 ) ;
V_54 = F_68 ( V_185 , & V_182 ) ;
if ( V_54 != 0 ) {
F_182 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
} else
F_72 = F_32 ;
}
#endif
}
