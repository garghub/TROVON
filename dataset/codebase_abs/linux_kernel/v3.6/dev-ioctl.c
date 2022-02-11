static int F_1 ( const char * V_1 )
{
if ( ! strchr ( V_1 , '/' ) )
return - V_2 ;
return 0 ;
}
static int F_2 ( char * V_3 , T_1 V_4 )
{
if ( memchr ( V_3 , 0 , V_4 ) )
return 0 ;
return - V_2 ;
}
static int F_3 ( int V_5 , struct V_6 * V_7 )
{
int V_8 = 0 ;
if ( ( V_9 != V_7 -> V_10 ) ||
( V_11 < V_7 -> V_12 ) ) {
F_4 ( L_1
L_2 ,
V_9 ,
V_11 ,
V_7 -> V_10 , V_7 -> V_12 , V_5 ) ;
V_8 = - V_2 ;
}
V_7 -> V_10 = V_9 ;
V_7 -> V_12 = V_11 ;
return V_8 ;
}
static struct V_6 * F_5 ( struct V_6 T_2 * V_13 )
{
struct V_6 V_14 ;
if ( F_6 ( & V_14 , V_13 , sizeof( V_14 ) ) )
return F_7 ( - V_15 ) ;
if ( V_14 . V_4 < sizeof( V_14 ) )
return F_7 ( - V_2 ) ;
return F_8 ( V_13 , V_14 . V_4 ) ;
}
static inline void F_9 ( struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
return;
}
static int F_11 ( int V_5 , struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_8 ) {
F_4 ( L_3
L_4 , V_5 ) ;
goto V_16;
}
if ( V_7 -> V_4 > sizeof( * V_7 ) ) {
V_8 = F_2 ( V_7 -> V_17 , V_7 -> V_4 - sizeof( * V_7 ) ) ;
if ( V_8 ) {
F_4 (
L_5 ,
V_5 ) ;
goto V_16;
}
V_8 = F_1 ( V_7 -> V_17 ) ;
if ( V_8 ) {
F_4 ( L_6 ,
V_5 ) ;
goto V_16;
}
}
V_8 = 0 ;
V_16:
return V_8 ;
}
static struct V_18 * F_12 ( struct V_19 * V_20 )
{
struct V_18 * V_21 = NULL ;
struct V_22 * V_22 ;
if ( V_20 ) {
V_22 = V_20 -> V_23 . V_24 -> V_25 ;
V_21 = F_13 ( V_22 -> V_26 ) ;
}
return V_21 ;
}
static int F_14 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_28 . V_29 = V_21 -> V_29 ;
return 0 ;
}
static int F_15 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_30 . V_31 = V_21 -> V_31 ;
return 0 ;
}
static int F_16 ( const char * V_32 ,
struct V_17 * V_33 ,
int F_17 ( struct V_17 * V_17 , void * V_34 ) ,
void * V_34 )
{
struct V_17 V_17 ;
int V_8 = F_18 ( V_32 , 0 , & V_17 ) ;
if ( V_8 )
return V_8 ;
V_8 = - V_35 ;
while ( V_17 . V_24 == V_17 . V_36 -> V_37 ) {
if ( V_17 . V_24 -> V_38 -> V_39 == V_40 ) {
if ( F_17 ( & V_17 , V_34 ) ) {
F_19 ( & V_17 ) ;
if ( ! V_8 )
F_20 ( V_33 ) ;
* V_33 = V_17 ;
V_8 = 0 ;
}
}
if ( ! F_21 ( & V_17 ) )
break;
}
F_20 ( & V_17 ) ;
return V_8 ;
}
static int F_22 ( struct V_17 * V_17 , void * V_41 )
{
return V_17 -> V_24 -> V_38 -> V_42 == * ( V_43 * ) V_41 ;
}
static int F_23 ( struct V_17 * V_17 , void * V_41 )
{
struct V_44 * V_45 = F_24 ( V_17 -> V_24 ) ;
return V_45 && V_45 -> V_21 -> type & * ( unsigned * ) V_41 ;
}
static void F_25 ( unsigned int V_46 , struct V_19 * V_19 )
{
struct V_47 * V_48 = V_49 -> V_48 ;
struct V_50 * V_51 ;
F_26 ( & V_48 -> V_52 ) ;
V_51 = F_27 ( V_48 ) ;
F_28 ( V_51 -> V_46 [ V_46 ] != NULL ) ;
F_29 ( V_51 -> V_46 [ V_46 ] , V_19 ) ;
F_30 ( V_46 , V_51 ) ;
F_31 ( & V_48 -> V_52 ) ;
}
static int F_32 ( const char * V_1 , V_43 V_53 )
{
int V_8 , V_46 ;
V_46 = F_33 () ;
if ( F_34 ( V_46 >= 0 ) ) {
struct V_19 * V_54 ;
struct V_17 V_17 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_53 ) ;
if ( V_8 )
goto V_16;
V_54 = F_35 ( & V_17 , V_55 , F_36 () ) ;
F_20 ( & V_17 ) ;
if ( F_37 ( V_54 ) ) {
V_8 = F_38 ( V_54 ) ;
goto V_16;
}
F_25 ( V_46 , V_54 ) ;
}
return V_46 ;
V_16:
F_39 ( V_46 ) ;
return V_8 ;
}
static int F_40 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
const char * V_17 ;
V_43 V_53 ;
int V_8 , V_46 ;
if ( ! V_7 -> V_56 . V_53 )
return - V_2 ;
V_7 -> V_57 = - 1 ;
V_17 = V_7 -> V_17 ;
V_53 = F_41 ( V_7 -> V_56 . V_53 ) ;
V_8 = 0 ;
V_46 = F_32 ( V_17 , V_53 ) ;
if ( F_42 ( V_46 < 0 ) ) {
V_8 = V_46 ;
goto V_16;
}
V_7 -> V_57 = V_46 ;
V_16:
return V_8 ;
}
static int F_43 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
return F_44 ( V_7 -> V_57 ) ;
}
static int F_45 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_58 ;
V_58 = ( T_3 ) V_7 -> V_59 . V_58 ;
return F_46 ( V_21 , V_58 , 0 ) ;
}
static int F_47 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_58 ;
int V_60 ;
V_58 = ( T_3 ) V_7 -> V_61 . V_58 ;
V_60 = V_7 -> V_61 . V_60 ? V_7 -> V_61 . V_60 : - V_35 ;
return F_46 ( V_21 , V_58 , V_60 ) ;
}
static int F_48 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
int V_62 ;
int V_8 = 0 ;
if ( V_7 -> V_63 . V_62 == - 1 )
return - V_2 ;
V_62 = V_7 -> V_63 . V_62 ;
F_49 ( & V_21 -> V_64 ) ;
if ( ! V_21 -> V_65 ) {
F_50 ( & V_21 -> V_64 ) ;
return - V_66 ;
} else {
struct V_19 * V_67 = F_51 ( V_62 ) ;
if ( ! V_67 ) {
V_8 = - V_68 ;
goto V_16;
}
if ( F_52 ( V_67 ) < 0 ) {
V_8 = - V_69 ;
F_53 ( V_67 ) ;
goto V_16;
}
V_21 -> V_70 = F_54 ( V_49 ) ;
V_21 -> V_62 = V_62 ;
V_21 -> V_67 = V_67 ;
V_21 -> V_65 = 0 ;
}
V_16:
F_50 ( & V_21 -> V_64 ) ;
return V_8 ;
}
static int F_55 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
F_56 ( V_21 ) ;
return 0 ;
}
static int F_57 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
unsigned long V_71 ;
V_71 = V_7 -> V_71 . V_71 ;
V_7 -> V_71 . V_71 = V_21 -> V_72 / V_73 ;
V_21 -> V_72 = V_71 * V_73 ;
return 0 ;
}
static int F_58 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_44 * V_45 ;
struct V_17 V_17 ;
V_43 V_53 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_53 = V_21 -> V_74 -> V_42 ;
V_7 -> V_75 . V_76 = V_7 -> V_75 . V_77 = - 1 ;
V_8 = F_16 ( V_7 -> V_17 , & V_17 , F_22 , & V_53 ) ;
if ( V_8 )
goto V_16;
V_45 = F_24 ( V_17 . V_24 ) ;
if ( V_45 ) {
V_8 = 0 ;
F_59 ( V_17 . V_24 ) ;
F_26 ( & V_21 -> V_78 ) ;
V_7 -> V_75 . V_76 = V_45 -> V_76 ;
V_7 -> V_75 . V_77 = V_45 -> V_77 ;
F_31 ( & V_21 -> V_78 ) ;
}
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_60 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_79 * V_36 ;
int V_80 ;
V_80 = V_7 -> V_81 . V_80 ;
V_36 = V_27 -> V_23 . V_36 ;
return F_61 ( V_21 -> V_74 , V_36 , V_21 , V_80 ) ;
}
static int F_62 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_82 . V_83 = 0 ;
if ( V_83 ( V_27 -> V_23 . V_36 ) )
V_7 -> V_82 . V_83 = 1 ;
return 0 ;
}
static int F_63 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_53 , V_84 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_85 . V_13 . type ;
V_7 -> V_85 . V_16 . V_53 = V_53 = 0 ;
V_7 -> V_85 . V_16 . V_84 = V_84 = 0 ;
if ( ! V_27 || V_7 -> V_57 == - 1 ) {
if ( F_64 ( type ) )
V_8 = F_18 ( V_1 , V_86 , & V_17 ) ;
else
V_8 = F_16 ( V_1 , & V_17 , F_23 , & type ) ;
if ( V_8 )
goto V_16;
V_53 = F_65 ( V_17 . V_24 -> V_38 -> V_42 ) ;
V_8 = 0 ;
if ( V_17 . V_36 -> V_37 == V_17 . V_24 ) {
V_8 = 1 ;
V_84 = V_17 . V_24 -> V_38 -> V_39 ;
}
} else {
V_43 V_87 = V_21 -> V_74 -> V_42 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_87 ) ;
if ( V_8 )
goto V_16;
V_53 = F_65 ( V_87 ) ;
V_8 = F_66 ( V_17 . V_24 ) ;
if ( F_67 ( & V_17 ) )
V_84 = V_17 . V_24 -> V_38 -> V_39 ;
}
V_7 -> V_85 . V_16 . V_53 = V_53 ;
V_7 -> V_85 . V_16 . V_84 = V_84 ;
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_68 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_88 ;
} V_89 [] = {
{ F_69 ( V_90 ) , NULL } ,
{ F_69 ( V_91 ) ,
F_14 } ,
{ F_69 ( V_92 ) ,
F_15 } ,
{ F_69 ( V_93 ) ,
F_40 } ,
{ F_69 ( V_94 ) ,
F_43 } ,
{ F_69 ( V_95 ) ,
F_45 } ,
{ F_69 ( V_96 ) ,
F_47 } ,
{ F_69 ( V_97 ) ,
F_48 } ,
{ F_69 ( V_98 ) ,
F_55 } ,
{ F_69 ( V_99 ) ,
F_57 } ,
{ F_69 ( V_100 ) ,
F_58 } ,
{ F_69 ( V_101 ) ,
F_60 } ,
{ F_69 ( V_102 ) ,
F_62 } ,
{ F_69 ( V_103 ) ,
F_63 }
} ;
unsigned int V_104 = F_69 ( V_5 ) ;
return ( V_104 >= F_70 ( V_89 ) ) ? NULL : V_89 [ V_104 ] . V_88 ;
}
static int F_71 ( unsigned int V_105 , struct V_6 T_2 * V_106 )
{
struct V_6 * V_7 ;
struct V_19 * V_27 ;
struct V_18 * V_21 ;
unsigned int V_107 , V_5 ;
T_4 V_88 = NULL ;
int V_8 = 0 ;
if ( ! F_72 ( V_108 ) )
return - V_109 ;
V_107 = F_73 ( V_110 ) ;
V_5 = F_73 ( V_105 ) ;
if ( F_74 ( V_105 ) != F_74 ( V_110 ) ||
V_5 - V_107 >= V_111 ) {
return - V_112 ;
}
V_7 = F_5 ( V_106 ) ;
if ( F_37 ( V_7 ) )
return F_38 ( V_7 ) ;
V_8 = F_11 ( V_105 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_90 )
goto V_113;
V_88 = F_68 ( V_5 ) ;
if ( ! V_88 ) {
F_4 ( L_7 , V_105 ) ;
return - V_112 ;
}
V_27 = NULL ;
V_21 = NULL ;
if ( V_5 != V_93 &&
V_5 != V_94 ) {
V_27 = F_51 ( V_7 -> V_57 ) ;
if ( ! V_27 ) {
if ( V_5 == V_103 )
goto V_114;
V_8 = - V_68 ;
goto V_16;
}
if ( ! V_27 -> V_115 ) {
V_8 = - V_112 ;
F_53 ( V_27 ) ;
goto V_16;
}
V_21 = F_12 ( V_27 ) ;
if ( ! V_21 || V_21 -> V_84 != V_116 ) {
V_8 = - V_2 ;
F_53 ( V_27 ) ;
goto V_16;
}
if ( ! F_75 ( V_21 ) &&
V_5 != V_98 ) {
V_8 = - V_117 ;
F_53 ( V_27 ) ;
goto V_16;
}
}
V_114:
V_8 = V_88 ( V_27 , V_21 , V_7 ) ;
if ( V_27 )
F_53 ( V_27 ) ;
V_113:
if ( V_8 >= 0 && F_76 ( V_106 , V_7 , V_118 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_105 , T_6 V_119 )
{
int V_8 ;
V_8 = F_71 ( V_105 , (struct V_6 T_2 * ) V_119 ) ;
return ( long ) V_8 ;
}
static long F_77 ( struct V_19 * V_19 , T_5 V_105 , T_6 V_119 )
{
return ( long ) V_6 ( V_19 , V_105 , ( T_6 ) F_78 ( V_119 ) ) ;
}
int F_79 ( void )
{
int V_120 ;
V_120 = F_80 ( & V_121 ) ;
if ( V_120 ) {
F_81 ( L_8 ) ;
return V_120 ;
}
return 0 ;
}
void F_82 ( void )
{
F_83 ( & V_121 ) ;
return;
}
