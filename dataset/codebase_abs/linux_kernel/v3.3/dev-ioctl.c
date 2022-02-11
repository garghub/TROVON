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
F_30 ( V_46 , V_51 -> V_53 ) ;
F_31 ( & V_48 -> V_52 ) ;
}
static int F_32 ( const char * V_1 , V_43 V_54 )
{
int V_8 , V_46 ;
V_46 = F_33 () ;
if ( F_34 ( V_46 >= 0 ) ) {
struct V_19 * V_55 ;
struct V_17 V_17 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_54 ) ;
if ( V_8 )
goto V_16;
V_55 = F_35 ( V_17 . V_24 , V_17 . V_36 , V_56 ,
F_36 () ) ;
if ( F_37 ( V_55 ) ) {
V_8 = F_38 ( V_55 ) ;
goto V_16;
}
F_25 ( V_46 , V_55 ) ;
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
V_43 V_54 ;
int V_8 , V_46 ;
if ( ! V_7 -> V_57 . V_54 )
return - V_2 ;
V_7 -> V_58 = - 1 ;
V_17 = V_7 -> V_17 ;
V_54 = F_41 ( V_7 -> V_57 . V_54 ) ;
V_8 = 0 ;
V_46 = F_32 ( V_17 , V_54 ) ;
if ( F_42 ( V_46 < 0 ) ) {
V_8 = V_46 ;
goto V_16;
}
V_7 -> V_58 = V_46 ;
V_16:
return V_8 ;
}
static int F_43 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
return F_44 ( V_7 -> V_58 ) ;
}
static int F_45 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_59 ;
V_59 = ( T_3 ) V_7 -> V_60 . V_59 ;
return F_46 ( V_21 , V_59 , 0 ) ;
}
static int F_47 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_59 ;
int V_61 ;
V_59 = ( T_3 ) V_7 -> V_62 . V_59 ;
V_61 = V_7 -> V_62 . V_61 ? V_7 -> V_62 . V_61 : - V_35 ;
return F_46 ( V_21 , V_59 , V_61 ) ;
}
static int F_48 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
int V_63 ;
int V_8 = 0 ;
if ( V_7 -> V_64 . V_63 == - 1 )
return - V_2 ;
V_63 = V_7 -> V_64 . V_63 ;
F_49 ( & V_21 -> V_65 ) ;
if ( ! V_21 -> V_66 ) {
F_50 ( & V_21 -> V_65 ) ;
return - V_67 ;
} else {
struct V_19 * V_68 = F_51 ( V_63 ) ;
if ( ! V_68 ) {
V_8 = - V_69 ;
goto V_16;
}
if ( ! V_68 -> V_70 || ! V_68 -> V_70 -> V_71 ) {
V_8 = - V_72 ;
F_52 ( V_68 ) ;
goto V_16;
}
V_21 -> V_73 = F_53 ( V_49 ) ;
V_21 -> V_63 = V_63 ;
V_21 -> V_68 = V_68 ;
V_21 -> V_66 = 0 ;
V_21 -> V_74 = F_54 () ;
}
V_16:
F_50 ( & V_21 -> V_65 ) ;
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
unsigned long V_75 ;
V_75 = V_7 -> V_75 . V_75 ;
V_7 -> V_75 . V_75 = V_21 -> V_76 / V_77 ;
V_21 -> V_76 = V_75 * V_77 ;
return 0 ;
}
static int F_58 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_44 * V_45 ;
struct V_17 V_17 ;
V_43 V_54 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_54 = V_21 -> V_78 -> V_42 ;
V_7 -> V_79 . V_80 = V_7 -> V_79 . V_81 = - 1 ;
V_8 = F_16 ( V_7 -> V_17 , & V_17 , F_22 , & V_54 ) ;
if ( V_8 )
goto V_16;
V_45 = F_24 ( V_17 . V_24 ) ;
if ( V_45 ) {
V_8 = 0 ;
F_59 ( V_17 . V_24 ) ;
F_26 ( & V_21 -> V_82 ) ;
V_7 -> V_79 . V_80 = V_45 -> V_80 ;
V_7 -> V_79 . V_81 = V_45 -> V_81 ;
F_31 ( & V_21 -> V_82 ) ;
}
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_60 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_83 * V_36 ;
int V_84 ;
V_84 = V_7 -> V_85 . V_84 ;
V_36 = V_27 -> V_23 . V_36 ;
return F_61 ( V_21 -> V_78 , V_36 , V_21 , V_84 ) ;
}
static int F_62 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_86 . V_87 = 0 ;
if ( V_87 ( V_27 -> V_23 . V_36 ) )
V_7 -> V_86 . V_87 = 1 ;
return 0 ;
}
static int F_63 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_54 , V_88 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_89 . V_13 . type ;
V_7 -> V_89 . V_16 . V_54 = V_54 = 0 ;
V_7 -> V_89 . V_16 . V_88 = V_88 = 0 ;
if ( ! V_27 || V_7 -> V_58 == - 1 ) {
if ( F_64 ( type ) )
V_8 = F_18 ( V_1 , V_90 , & V_17 ) ;
else
V_8 = F_16 ( V_1 , & V_17 , F_23 , & type ) ;
if ( V_8 )
goto V_16;
V_54 = F_65 ( V_17 . V_24 -> V_38 -> V_42 ) ;
V_8 = 0 ;
if ( V_17 . V_36 -> V_37 == V_17 . V_24 ) {
V_8 = 1 ;
V_88 = V_17 . V_24 -> V_38 -> V_39 ;
}
} else {
V_43 V_91 = V_21 -> V_78 -> V_42 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_91 ) ;
if ( V_8 )
goto V_16;
V_54 = F_65 ( V_91 ) ;
V_8 = F_66 ( V_17 . V_24 ) ;
if ( F_67 ( & V_17 ) )
V_88 = V_17 . V_24 -> V_38 -> V_39 ;
}
V_7 -> V_89 . V_16 . V_54 = V_54 ;
V_7 -> V_89 . V_16 . V_88 = V_88 ;
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_68 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_92 ;
} V_93 [] = {
{ F_69 ( V_94 ) , NULL } ,
{ F_69 ( V_95 ) ,
F_14 } ,
{ F_69 ( V_96 ) ,
F_15 } ,
{ F_69 ( V_97 ) ,
F_40 } ,
{ F_69 ( V_98 ) ,
F_43 } ,
{ F_69 ( V_99 ) ,
F_45 } ,
{ F_69 ( V_100 ) ,
F_47 } ,
{ F_69 ( V_101 ) ,
F_48 } ,
{ F_69 ( V_102 ) ,
F_55 } ,
{ F_69 ( V_103 ) ,
F_57 } ,
{ F_69 ( V_104 ) ,
F_58 } ,
{ F_69 ( V_105 ) ,
F_60 } ,
{ F_69 ( V_106 ) ,
F_62 } ,
{ F_69 ( V_107 ) ,
F_63 }
} ;
unsigned int V_108 = F_69 ( V_5 ) ;
return ( V_108 >= F_70 ( V_93 ) ) ? NULL : V_93 [ V_108 ] . V_92 ;
}
static int F_71 ( unsigned int V_109 , struct V_6 T_2 * V_110 )
{
struct V_6 * V_7 ;
struct V_19 * V_27 ;
struct V_18 * V_21 ;
unsigned int V_111 , V_5 ;
T_4 V_92 = NULL ;
int V_8 = 0 ;
if ( ! F_72 ( V_112 ) )
return - V_113 ;
V_111 = F_73 ( V_114 ) ;
V_5 = F_73 ( V_109 ) ;
if ( F_74 ( V_109 ) != F_74 ( V_114 ) ||
V_5 - V_111 >= V_115 ) {
return - V_116 ;
}
V_7 = F_5 ( V_110 ) ;
if ( F_37 ( V_7 ) )
return F_38 ( V_7 ) ;
V_8 = F_11 ( V_109 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_94 )
goto V_117;
V_92 = F_68 ( V_5 ) ;
if ( ! V_92 ) {
F_4 ( L_7 , V_109 ) ;
return - V_116 ;
}
V_27 = NULL ;
V_21 = NULL ;
if ( V_5 != V_97 &&
V_5 != V_98 ) {
V_27 = F_51 ( V_7 -> V_58 ) ;
if ( ! V_27 ) {
if ( V_5 == V_107 )
goto V_118;
V_8 = - V_69 ;
goto V_16;
}
if ( ! V_27 -> V_70 ) {
V_8 = - V_116 ;
F_52 ( V_27 ) ;
goto V_16;
}
V_21 = F_12 ( V_27 ) ;
if ( ! V_21 || V_21 -> V_88 != V_119 ) {
V_8 = - V_2 ;
F_52 ( V_27 ) ;
goto V_16;
}
if ( ! F_75 ( V_21 ) &&
V_5 != V_102 ) {
V_8 = - V_120 ;
F_52 ( V_27 ) ;
goto V_16;
}
}
V_118:
V_8 = V_92 ( V_27 , V_21 , V_7 ) ;
if ( V_27 )
F_52 ( V_27 ) ;
V_117:
if ( V_8 >= 0 && F_76 ( V_110 , V_7 , V_121 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_109 , T_6 V_122 )
{
int V_8 ;
V_8 = F_71 ( V_109 , (struct V_6 T_2 * ) V_122 ) ;
return ( long ) V_8 ;
}
static long F_77 ( struct V_19 * V_19 , T_5 V_109 , T_6 V_122 )
{
return ( long ) V_6 ( V_19 , V_109 , ( T_6 ) F_78 ( V_122 ) ) ;
}
int F_79 ( void )
{
int V_123 ;
V_123 = F_80 ( & V_124 ) ;
if ( V_123 ) {
F_81 ( L_8 ) ;
return V_123 ;
}
return 0 ;
}
void F_82 ( void )
{
F_83 ( & V_124 ) ;
return;
}
