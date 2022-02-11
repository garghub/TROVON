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
F_37 ( F_38 ( V_6 ) -> V_36 . V_37 , F_39 ( V_13 ) ) ;
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
struct V_38 * V_39 = F_38 ( V_6 ) ;
F_37 ( V_39 -> V_36 . V_37 , F_39 ( 0 ) ) ;
#endif
V_11 = F_48 ( sizeof( * V_11 ) , V_8 ) ;
if ( V_11 == NULL )
F_49 ( L_2 , V_6 ) ;
V_11 -> type = V_15 ;
V_11 -> V_40 = - 1 ;
F_50 ( V_6 , V_11 ) ;
F_51 ( & V_11 -> V_41 , & V_42 ) ;
}
static int T_2 F_52 ( void )
{
int V_43 = 0 ;
int V_6 ;
#ifdef F_53
if ( F_54 () || F_55 () )
V_43 = F_56 () ;
#endif
V_6 = F_57 ( V_43 , - 1 ) ;
if ( V_6 >= 0 )
F_47 ( V_6 ) ;
return V_6 ;
}
static int T_2 F_58 ( unsigned V_28 )
{
int V_6 ;
if ( F_59 () && ! F_54 () )
return F_52 () ;
if ( V_28 < V_44 )
V_6 = V_28 ;
else
V_6 = F_60 ( V_28 , - 1 ) ;
F_47 ( V_6 ) ;
return V_6 ;
}
static void F_61 ( unsigned V_6 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_62 ( ! V_11 ) )
return;
F_63 ( & V_11 -> V_41 ) ;
F_50 ( V_6 , NULL ) ;
F_62 ( V_11 -> V_40 > 0 ) ;
F_64 ( V_11 ) ;
if ( V_6 < V_44 )
return;
F_65 ( V_6 ) ;
}
static void F_66 ( unsigned int V_45 )
{
struct V_46 V_47 ;
V_47 . V_45 = V_45 ;
if ( F_67 ( V_48 , & V_47 ) != 0 )
F_68 () ;
F_35 ( V_45 , 0 ) ;
}
static void F_69 ( int V_6 )
{
struct V_49 V_50 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
V_50 . V_6 = F_28 ( V_6 ) ;
if ( F_70 ( V_51 , & V_50 ) )
V_50 . V_30 = 0 ;
V_11 -> V_21 . V_27 . V_30 &= ~ V_34 ;
if ( V_50 . V_30 & V_52 )
V_11 -> V_21 . V_27 . V_30 |= V_34 ;
}
static bool F_71 ( int V_6 )
{
struct V_38 * V_39 = F_38 ( V_6 ) ;
return V_39 && V_39 -> V_53 == NULL ;
}
static void F_72 ( struct V_36 * V_54 )
{
int V_5 = F_21 ( V_54 -> V_6 ) ;
struct V_55 V_56 = { . V_6 = F_28 (data->irq) } ;
int V_57 = 0 ;
F_73 ( V_54 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
if ( F_75 ( V_54 -> V_6 ) ) {
V_57 = F_70 ( V_58 , & V_56 ) ;
F_62 ( V_57 ) ;
}
}
static void F_76 ( struct V_36 * V_54 )
{
F_77 ( V_54 ) ;
F_72 ( V_54 ) ;
}
static unsigned int F_78 ( unsigned int V_6 )
{
struct V_59 V_60 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_5 = F_21 ( V_6 ) ;
int V_57 ;
F_12 ( V_11 -> type != V_31 ) ;
if ( F_45 ( V_5 ) )
goto V_61;
V_60 . V_27 = F_28 ( V_6 ) ;
V_60 . V_30 = V_11 -> V_21 . V_27 . V_30 & V_62 ?
V_63 : 0 ;
V_57 = F_67 ( V_64 , & V_60 ) ;
if ( V_57 != 0 ) {
if ( ! F_71 ( V_6 ) )
F_79 ( L_3 , V_6 ) ;
return 0 ;
}
V_5 = V_60 . V_45 ;
F_69 ( V_6 ) ;
V_57 = F_5 ( V_5 , V_6 ) ;
if ( V_57 != 0 ) {
F_80 ( L_4 ,
V_6 , V_57 ) ;
F_66 ( V_5 ) ;
return 0 ;
}
F_35 ( V_5 , 0 ) ;
V_11 -> V_5 = V_5 ;
V_61:
F_81 ( V_5 ) ;
F_72 ( F_82 ( V_6 ) ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_36 * V_54 )
{
return F_78 ( V_54 -> V_6 ) ;
}
static void F_84 ( struct V_36 * V_54 )
{
unsigned int V_6 = V_54 -> V_6 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
unsigned V_5 = F_21 ( V_6 ) ;
F_12 ( V_11 -> type != V_31 ) ;
if ( ! F_45 ( V_5 ) )
return;
F_43 ( V_5 ) ;
F_66 ( V_5 ) ;
F_20 ( V_11 ) ;
}
static void F_85 ( struct V_36 * V_54 )
{
F_83 ( V_54 ) ;
}
static void F_86 ( struct V_36 * V_54 )
{
F_77 ( V_54 ) ;
}
int F_87 ( unsigned V_28 )
{
struct V_10 * V_11 ;
F_88 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
if ( V_11 -> V_21 . V_27 . V_28 == V_28 )
return V_11 -> V_6 ;
}
return - 1 ;
}
static void F_89 ( unsigned int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( V_11 -> V_40 > 0 ) {
V_11 -> V_40 -- ;
if ( V_11 -> V_40 != 0 )
return;
}
if ( F_45 ( V_5 ) ) {
unsigned int V_13 = F_30 ( V_6 ) ;
F_66 ( V_5 ) ;
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
F_61 ( V_6 ) ;
}
int F_90 ( unsigned V_28 ,
unsigned V_27 , int V_65 , char * V_66 )
{
int V_6 = - 1 ;
struct V_67 V_68 ;
int V_14 ;
F_91 ( & V_69 ) ;
V_6 = F_87 ( V_28 ) ;
if ( V_6 != - 1 ) {
F_79 ( L_5 ,
V_70 , V_6 , V_28 ) ;
goto V_61;
}
V_6 = F_58 ( V_28 ) ;
if ( V_6 < 0 )
goto V_61;
V_68 . V_6 = V_6 ;
V_68 . V_71 = 0 ;
if ( F_54 () &&
F_70 ( V_72 , & V_68 ) ) {
F_61 ( V_6 ) ;
V_6 = - V_73 ;
goto V_61;
}
V_14 = F_19 ( V_6 , 0 , V_27 , V_28 , V_74 ,
V_65 ? V_62 : 0 ) ;
if ( V_14 < 0 ) {
F_89 ( V_6 ) ;
V_6 = V_14 ;
goto V_61;
}
F_69 ( V_6 ) ;
if ( V_65 )
F_92 ( V_6 , & V_75 ,
V_76 , V_66 ) ;
else
F_92 ( V_6 , & V_75 ,
V_77 , V_66 ) ;
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
}
int F_94 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
int V_57 ;
struct V_82 V_83 ;
V_83 . type = V_84 ;
V_57 = F_70 ( V_85 , & V_83 ) ;
F_95 ( V_57 == - V_86 ,
L_6 ) ;
return V_57 ? - 1 : V_83 . V_27 ;
}
int F_96 ( struct V_78 * V_79 , struct V_80 * V_81 ,
int V_27 , const char * V_66 , T_3 V_29 )
{
int V_6 , V_14 ;
F_91 ( & V_69 ) ;
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_61;
F_92 ( V_6 , & V_75 , V_77 ,
V_66 ) ;
V_14 = F_19 ( V_6 , 0 , V_27 , 0 , V_29 , 0 ) ;
if ( V_14 < 0 )
goto V_87;
V_14 = F_97 ( V_6 , V_81 ) ;
if ( V_14 < 0 )
goto V_87;
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
V_87:
F_89 ( V_6 ) ;
F_93 ( & V_69 ) ;
return V_14 ;
}
int F_98 ( int V_6 )
{
struct V_38 * V_39 ;
struct V_88 V_89 ;
struct V_10 * V_11 = F_9 ( V_6 ) ;
int V_57 = - V_90 ;
F_91 ( & V_69 ) ;
V_39 = F_38 ( V_6 ) ;
if ( ! V_39 )
goto V_61;
if ( F_54 () ) {
V_89 . V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_89 . V_29 = V_11 -> V_21 . V_27 . V_29 ;
V_57 = F_70 ( V_91 , & V_89 ) ;
if ( ( V_57 == - V_92 && V_11 -> V_21 . V_27 . V_29 != V_74 ) )
F_79 ( L_7 ,
V_11 -> V_21 . V_27 . V_29 , V_11 -> V_21 . V_27 . V_27 ) ;
else if ( V_57 ) {
F_99 ( L_8 , V_57 ) ;
goto V_61;
}
}
F_61 ( V_6 ) ;
V_61:
F_93 ( & V_69 ) ;
return V_57 ;
}
int F_100 ( unsigned V_27 )
{
int V_6 ;
struct V_10 * V_11 ;
F_91 ( & V_69 ) ;
F_88 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_6 = V_11 -> V_6 ;
if ( V_11 -> V_21 . V_27 . V_27 == V_27 )
goto V_61;
}
V_6 = - 1 ;
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
}
int F_101 ( unsigned V_6 )
{
return F_28 ( V_6 ) ;
}
int F_102 ( unsigned int V_5 )
{
int V_6 ;
int V_14 ;
if ( V_5 >= F_4 () )
return - V_9 ;
F_91 ( & V_69 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 ) {
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_61;
F_92 ( V_6 , & V_93 ,
V_77 , L_9 ) ;
V_14 = F_15 ( V_6 , V_5 ) ;
if ( V_14 < 0 ) {
F_89 ( V_6 ) ;
V_6 = V_14 ;
goto V_61;
}
F_35 ( V_5 , 0 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_62 ( V_11 == NULL || V_11 -> type != V_18 ) ;
}
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
}
static int F_103 ( unsigned int V_20 , unsigned int V_13 )
{
struct V_94 V_95 ;
int V_5 , V_6 ;
int V_14 ;
F_91 ( & V_69 ) ;
V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ;
if ( V_6 == - 1 ) {
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_61;
F_92 ( V_6 , & V_96 ,
V_97 , L_10 ) ;
V_95 . V_98 = V_13 ;
if ( F_67 ( V_99 ,
& V_95 ) != 0 )
F_68 () ;
V_5 = V_95 . V_45 ;
V_14 = F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
if ( V_14 < 0 ) {
F_89 ( V_6 ) ;
V_6 = V_14 ;
goto V_61;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_62 ( V_11 == NULL || V_11 -> type != V_23 ) ;
}
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
}
static int F_104 ( unsigned int V_100 ,
unsigned int V_101 )
{
struct V_102 V_103 ;
int V_104 ;
V_103 . V_105 = V_100 ;
V_103 . V_101 = V_101 ;
V_104 = F_67 ( V_106 ,
& V_103 ) ;
return V_104 ? : F_102 ( V_103 . V_107 ) ;
}
static int F_105 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_108 V_109 ;
int V_45 , V_57 = - V_90 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
for ( V_45 = 0 ; V_45 < F_4 () ; V_45 ++ ) {
V_109 . V_110 = V_74 ;
V_109 . V_45 = V_45 ;
V_57 = F_67 ( V_111 , & V_109 ) ;
if ( V_57 < 0 )
continue;
if ( V_109 . V_109 != V_112 )
continue;
if ( V_109 . V_21 . V_24 == V_24 && V_109 . V_98 == V_13 ) {
V_57 = V_45 ;
break;
}
}
return V_57 ;
}
unsigned F_42 ( void )
{
return V_113 -> V_114 () ;
}
int F_106 ( unsigned int V_24 , unsigned int V_13 )
{
struct V_115 V_116 ;
int V_5 , V_6 , V_14 ;
F_91 ( & V_69 ) ;
V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ;
if ( V_6 == - 1 ) {
V_6 = F_52 () ;
if ( V_6 < 0 )
goto V_61;
F_92 ( V_6 , & V_96 ,
V_97 , L_11 ) ;
V_116 . V_24 = V_24 ;
V_116 . V_98 = V_13 ;
V_14 = F_67 ( V_117 ,
& V_116 ) ;
if ( V_14 == 0 )
V_5 = V_116 . V_45 ;
else {
if ( V_14 == - V_118 )
V_14 = F_105 ( V_24 , V_13 ) ;
F_12 ( V_14 < 0 ) ;
V_5 = V_14 ;
}
V_14 = F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
if ( V_14 < 0 ) {
F_89 ( V_6 ) ;
V_6 = V_14 ;
goto V_61;
}
F_35 ( V_5 , V_13 ) ;
} else {
struct V_10 * V_11 = F_9 ( V_6 ) ;
F_62 ( V_11 == NULL || V_11 -> type != V_26 ) ;
}
V_61:
F_93 ( & V_69 ) ;
return V_6 ;
}
static void F_107 ( unsigned int V_6 )
{
F_91 ( & V_69 ) ;
F_89 ( V_6 ) ;
F_93 ( & V_69 ) ;
}
int F_108 ( unsigned int V_5 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 , void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_102 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_109 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_107 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_110 ( unsigned int V_100 ,
unsigned int V_101 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 ,
void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_104 ( V_100 , V_101 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_109 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_107 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_111 ( unsigned int V_24 , unsigned int V_13 ,
T_4 V_119 ,
unsigned long V_120 , const char * V_121 , void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_106 ( V_24 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_123 = F_109 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_107 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
int F_112 ( enum V_19 V_20 ,
unsigned int V_13 ,
T_4 V_119 ,
unsigned long V_120 ,
const char * V_121 ,
void * V_122 )
{
int V_6 , V_123 ;
V_6 = F_103 ( V_20 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_120 |= V_124 | V_125 | V_126 ;
V_123 = F_109 ( V_6 , V_119 , V_120 , V_121 , V_122 ) ;
if ( V_123 != 0 ) {
F_107 ( V_6 ) ;
return V_123 ;
}
return V_6 ;
}
void F_113 ( unsigned int V_6 , void * V_122 )
{
struct V_10 * V_11 = F_10 ( V_6 ) ;
if ( F_62 ( ! V_11 ) )
return;
F_114 ( V_6 , V_122 ) ;
F_107 ( V_6 ) ;
}
int F_115 ( unsigned V_6 , unsigned V_127 )
{
struct V_128 V_129 ;
V_129 . V_45 = F_21 ( V_6 ) ;
V_129 . V_127 = V_127 ;
return F_67 ( V_130 ,
& V_129 ) ;
}
int F_116 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
struct V_10 * V_11 ;
if ( V_6 == - 1 )
return - V_90 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_90 ;
F_62 ( V_11 -> V_40 != - 1 ) ;
V_11 -> V_40 = 1 ;
return 0 ;
}
int F_117 ( unsigned int V_5 )
{
int V_6 ;
struct V_10 * V_11 ;
int V_104 = - V_90 ;
if ( V_5 >= F_4 () )
return - V_7 ;
F_91 ( & V_69 ) ;
V_6 = F_8 ( V_5 ) ;
if ( V_6 == - 1 )
goto V_131;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
goto V_131;
V_104 = - V_7 ;
if ( V_11 -> V_40 <= 0 )
goto V_131;
V_11 -> V_40 ++ ;
V_104 = 0 ;
V_131:
F_93 ( & V_69 ) ;
return V_104 ;
}
void F_118 ( unsigned int V_5 )
{
int V_6 = F_8 ( V_5 ) ;
if ( F_62 ( V_6 == - 1 ) )
return;
F_107 ( V_6 ) ;
}
void F_119 ( unsigned int V_13 , enum V_19 V_71 )
{
int V_6 ;
#ifdef F_120
if ( F_22 ( V_71 == V_132 ) ) {
int V_57 = F_121 ( V_133 , V_13 , NULL ) ;
if ( V_57 < 0 )
F_122 ( V_134 L_12 , V_13 , V_57 ) ;
return;
}
#endif
V_6 = F_17 ( V_22 , V_13 ) [ V_71 ] ;
F_12 ( V_6 < 0 ) ;
F_44 ( V_6 ) ;
}
static void F_123 ( void )
{
struct V_135 * V_135 = F_124 ( V_136 ) ;
int V_13 = F_125 () ;
unsigned V_137 ;
do {
V_135 -> V_138 = 0 ;
if ( F_126 ( V_139 ) - 1 )
goto V_61;
F_127 ( V_13 ) ;
F_12 ( ! F_128 () ) ;
V_137 = F_124 ( V_139 ) ;
F_129 ( V_139 , 0 ) ;
} while ( V_137 != 1 || V_135 -> V_138 );
V_61:
F_130 () ;
}
void F_131 ( struct V_140 * V_141 )
{
struct V_140 * V_142 = F_132 ( V_141 ) ;
F_133 () ;
#ifdef F_120
F_134 () ;
#endif
F_123 () ;
F_135 () ;
F_132 ( V_142 ) ;
}
void F_136 ( void )
{
F_123 () ;
}
void F_137 ( int V_5 , int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
if ( F_62 ( ! V_11 ) )
return;
F_138 ( V_6 ) ;
F_91 ( & V_69 ) ;
F_12 ( F_8 ( V_5 ) != - 1 ) ;
F_12 ( V_11 -> type == V_15 ) ;
( void ) F_15 ( V_6 , V_5 ) ;
F_93 ( & V_69 ) ;
F_139 ( V_6 , F_39 ( 0 ) ) ;
F_140 ( V_6 ) ;
}
static int F_141 ( unsigned V_6 , unsigned V_143 )
{
struct V_144 V_145 ;
int V_5 = F_21 ( V_6 ) ;
int V_146 ;
if ( ! F_45 ( V_5 ) )
return - 1 ;
if ( F_55 () && ! V_147 )
return - 1 ;
V_145 . V_45 = V_5 ;
V_145 . V_98 = V_143 ;
V_146 = F_142 ( V_5 ) ;
if ( F_67 ( V_148 , & V_145 ) >= 0 )
F_35 ( V_5 , V_143 ) ;
if ( ! V_146 )
F_81 ( V_5 ) ;
return 0 ;
}
static int F_143 ( struct V_36 * V_54 , const struct V_149 * V_150 ,
bool V_151 )
{
unsigned V_143 = F_144 ( V_150 ) ;
return F_141 ( V_54 -> V_6 , V_143 ) ;
}
static int F_145 ( int V_5 )
{
int V_146 ;
if ( ! F_45 ( V_5 ) )
return 0 ;
V_146 = F_142 ( V_5 ) ;
F_146 ( V_5 ) ;
if ( ! V_146 )
F_81 ( V_5 ) ;
return 1 ;
}
int F_147 ( unsigned int V_6 )
{
return F_145 ( F_21 ( V_6 ) ) ;
}
static void F_148 ( struct V_36 * V_54 )
{
int V_5 = F_21 ( V_54 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_81 ( V_5 ) ;
}
static void F_77 ( struct V_36 * V_54 )
{
int V_5 = F_21 ( V_54 -> V_6 ) ;
if ( F_45 ( V_5 ) )
F_43 ( V_5 ) ;
}
static void F_149 ( struct V_36 * V_54 )
{
int V_5 = F_21 ( V_54 -> V_6 ) ;
F_73 ( V_54 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
}
static void F_150 ( struct V_36 * V_54 )
{
F_77 ( V_54 ) ;
F_149 ( V_54 ) ;
}
static int F_151 ( struct V_36 * V_54 )
{
return F_145 ( F_21 ( V_54 -> V_6 ) ) ;
}
static void F_152 ( void )
{
int V_27 , V_57 , V_6 , V_28 ;
struct V_152 V_153 ;
struct V_10 * V_11 ;
F_88 (info, &xen_irq_list_head, list) {
if ( V_11 -> type != V_31 )
continue;
V_27 = V_11 -> V_21 . V_27 . V_27 ;
V_28 = V_11 -> V_21 . V_27 . V_28 ;
V_6 = V_11 -> V_6 ;
if ( ! V_28 )
continue;
V_153 . V_29 = V_74 ;
V_153 . type = V_154 ;
V_153 . V_155 = V_28 ;
V_153 . V_27 = V_27 ;
V_57 = F_70 ( V_156 , & V_153 ) ;
if ( V_57 ) {
F_99 ( L_13 ,
V_28 , V_6 , V_27 , V_57 ) ;
F_61 ( V_6 ) ;
continue;
}
F_122 ( V_157 L_14 , V_6 , V_153 . V_27 ) ;
F_78 ( V_6 ) ;
}
}
static void F_153 ( unsigned int V_13 )
{
struct V_115 V_116 ;
int V_24 , V_6 , V_5 ;
for ( V_24 = 0 ; V_24 < V_158 ; V_24 ++ ) {
if ( ( V_6 = F_17 ( V_25 , V_13 ) [ V_24 ] ) == - 1 )
continue;
F_12 ( F_27 ( V_6 ) != V_24 ) ;
V_116 . V_24 = V_24 ;
V_116 . V_98 = V_13 ;
if ( F_67 ( V_117 ,
& V_116 ) != 0 )
F_68 () ;
V_5 = V_116 . V_45 ;
( void ) F_18 ( V_13 , V_6 , V_5 , V_24 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
static void F_154 ( unsigned int V_13 )
{
struct V_94 V_95 ;
int V_20 , V_6 , V_5 ;
for ( V_20 = 0 ; V_20 < V_159 ; V_20 ++ ) {
if ( ( V_6 = F_17 ( V_22 , V_13 ) [ V_20 ] ) == - 1 )
continue;
F_12 ( F_26 ( V_6 ) != V_20 ) ;
V_95 . V_98 = V_13 ;
if ( F_67 ( V_99 ,
& V_95 ) != 0 )
F_68 () ;
V_5 = V_95 . V_45 ;
( void ) F_16 ( V_13 , V_6 , V_5 , V_20 ) ;
F_35 ( V_5 , V_13 ) ;
}
}
void F_155 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_74 ( V_5 ) ;
}
void F_156 ( int V_6 )
{
int V_5 = F_21 ( V_6 ) ;
if ( F_45 ( V_5 ) )
F_146 ( V_5 ) ;
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
F_68 () ;
}
}
void F_162 ( int V_6 )
{
F_159 ( V_6 , 0 ) ;
}
int F_163 ( int V_6 )
{
struct V_10 * V_11 = F_9 ( V_6 ) ;
struct V_49 V_50 ;
if ( F_62 ( ! V_11 ) )
return - V_90 ;
V_50 . V_6 = V_11 -> V_21 . V_27 . V_27 ;
if ( F_70 ( V_51 , & V_50 ) )
return 0 ;
return ! ( V_50 . V_30 & V_166 ) ;
}
void F_164 ( void )
{
unsigned int V_13 ;
struct V_10 * V_11 ;
F_41 () ;
F_165 () ;
F_88 (info, &xen_irq_list_head, list)
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
V_169 . V_29 = V_74 ;
V_169 . V_155 = V_170 ;
V_169 . V_171 = V_167 ;
return F_168 ( V_172 , & V_169 ) ;
}
void F_169 ( void )
{
int V_57 ;
T_7 V_173 ;
if ( V_147 ) {
V_173 = F_170 ( V_174 ) ;
V_57 = F_167 ( V_173 ) ;
if ( V_57 ) {
F_80 ( L_15 ) ;
V_147 = 0 ;
return;
}
F_79 ( L_16 ) ;
if ( ! F_33 ( V_174 , V_175 ) )
F_171 ( V_174 ,
V_176 ) ;
}
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
F_75 = F_34 ;
#ifdef F_120
if ( F_59 () ) {
F_176 ( F_177 () ) ;
if ( F_54 () )
F_178 () ;
}
if ( F_179 ( V_178 ) )
F_169 () ;
if ( F_55 () ) {
F_180 () ;
F_181 () ;
} else {
int V_57 ;
struct V_179 V_180 ;
V_33 = ( void * ) F_182 ( V_8 | V_181 ) ;
V_180 . V_182 = F_183 ( V_33 ) ;
V_57 = F_70 ( V_183 , & V_180 ) ;
if ( V_57 != 0 ) {
F_184 ( ( unsigned long ) V_33 ) ;
V_33 = NULL ;
} else
F_75 = F_32 ;
}
#endif
}
