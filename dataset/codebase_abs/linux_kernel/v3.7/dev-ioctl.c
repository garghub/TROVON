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
static int F_25 ( const char * V_1 , V_43 V_46 )
{
int V_8 , V_47 ;
V_47 = F_26 ( V_48 ) ;
if ( F_27 ( V_47 >= 0 ) ) {
struct V_19 * V_49 ;
struct V_17 V_17 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_46 ) ;
if ( V_8 )
goto V_16;
V_49 = F_28 ( & V_17 , V_50 , F_29 () ) ;
F_20 ( & V_17 ) ;
if ( F_30 ( V_49 ) ) {
V_8 = F_31 ( V_49 ) ;
goto V_16;
}
F_32 ( V_47 , V_49 ) ;
}
return V_47 ;
V_16:
F_33 ( V_47 ) ;
return V_8 ;
}
static int F_34 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
const char * V_17 ;
V_43 V_46 ;
int V_8 , V_47 ;
if ( ! V_7 -> V_51 . V_46 )
return - V_2 ;
V_7 -> V_52 = - 1 ;
V_17 = V_7 -> V_17 ;
V_46 = F_35 ( V_7 -> V_51 . V_46 ) ;
V_8 = 0 ;
V_47 = F_25 ( V_17 , V_46 ) ;
if ( F_36 ( V_47 < 0 ) ) {
V_8 = V_47 ;
goto V_16;
}
V_7 -> V_52 = V_47 ;
V_16:
return V_8 ;
}
static int F_37 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
return F_38 ( V_7 -> V_52 ) ;
}
static int F_39 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_53 ;
V_53 = ( T_3 ) V_7 -> V_54 . V_53 ;
return F_40 ( V_21 , V_53 , 0 ) ;
}
static int F_41 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_53 ;
int V_55 ;
V_53 = ( T_3 ) V_7 -> V_56 . V_53 ;
V_55 = V_7 -> V_56 . V_55 ? V_7 -> V_56 . V_55 : - V_35 ;
return F_40 ( V_21 , V_53 , V_55 ) ;
}
static int F_42 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
int V_57 ;
int V_8 = 0 ;
if ( V_7 -> V_58 . V_57 == - 1 )
return - V_2 ;
V_57 = V_7 -> V_58 . V_57 ;
F_43 ( & V_21 -> V_59 ) ;
if ( ! V_21 -> V_60 ) {
F_44 ( & V_21 -> V_59 ) ;
return - V_61 ;
} else {
struct V_19 * V_62 = F_45 ( V_57 ) ;
if ( ! V_62 ) {
V_8 = - V_63 ;
goto V_16;
}
if ( F_46 ( V_62 ) < 0 ) {
V_8 = - V_64 ;
F_47 ( V_62 ) ;
goto V_16;
}
V_21 -> V_65 = F_48 ( V_66 ) ;
V_21 -> V_57 = V_57 ;
V_21 -> V_62 = V_62 ;
V_21 -> V_60 = 0 ;
}
V_16:
F_44 ( & V_21 -> V_59 ) ;
return V_8 ;
}
static int F_49 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
F_50 ( V_21 ) ;
return 0 ;
}
static int F_51 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
unsigned long V_67 ;
V_67 = V_7 -> V_67 . V_67 ;
V_7 -> V_67 . V_67 = V_21 -> V_68 / V_69 ;
V_21 -> V_68 = V_67 * V_69 ;
return 0 ;
}
static int F_52 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_44 * V_45 ;
struct V_17 V_17 ;
V_43 V_46 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_46 = V_21 -> V_70 -> V_42 ;
V_7 -> V_71 . V_72 = V_7 -> V_71 . V_73 = - 1 ;
V_8 = F_16 ( V_7 -> V_17 , & V_17 , F_22 , & V_46 ) ;
if ( V_8 )
goto V_16;
V_45 = F_24 ( V_17 . V_24 ) ;
if ( V_45 ) {
V_8 = 0 ;
F_53 ( V_17 . V_24 ) ;
F_54 ( & V_21 -> V_74 ) ;
V_7 -> V_71 . V_72 = V_45 -> V_72 ;
V_7 -> V_71 . V_73 = V_45 -> V_73 ;
F_55 ( & V_21 -> V_74 ) ;
}
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_56 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_75 * V_36 ;
int V_76 ;
V_76 = V_7 -> V_77 . V_76 ;
V_36 = V_27 -> V_23 . V_36 ;
return F_57 ( V_21 -> V_70 , V_36 , V_21 , V_76 ) ;
}
static int F_58 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_78 . V_79 = 0 ;
if ( V_79 ( V_27 -> V_23 . V_36 ) )
V_7 -> V_78 . V_79 = 1 ;
return 0 ;
}
static int F_59 ( struct V_19 * V_27 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_46 , V_80 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_81 . V_13 . type ;
V_7 -> V_81 . V_16 . V_46 = V_46 = 0 ;
V_7 -> V_81 . V_16 . V_80 = V_80 = 0 ;
if ( ! V_27 || V_7 -> V_52 == - 1 ) {
if ( F_60 ( type ) )
V_8 = F_18 ( V_1 , V_82 , & V_17 ) ;
else
V_8 = F_16 ( V_1 , & V_17 , F_23 , & type ) ;
if ( V_8 )
goto V_16;
V_46 = F_61 ( V_17 . V_24 -> V_38 -> V_42 ) ;
V_8 = 0 ;
if ( V_17 . V_36 -> V_37 == V_17 . V_24 ) {
V_8 = 1 ;
V_80 = V_17 . V_24 -> V_38 -> V_39 ;
}
} else {
V_43 V_83 = V_21 -> V_70 -> V_42 ;
V_8 = F_16 ( V_1 , & V_17 , F_22 , & V_83 ) ;
if ( V_8 )
goto V_16;
V_46 = F_61 ( V_83 ) ;
V_8 = F_62 ( V_17 . V_24 ) ;
if ( F_63 ( & V_17 ) )
V_80 = V_17 . V_24 -> V_38 -> V_39 ;
}
V_7 -> V_81 . V_16 . V_46 = V_46 ;
V_7 -> V_81 . V_16 . V_80 = V_80 ;
F_20 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_64 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_84 ;
} V_85 [] = {
{ F_65 ( V_86 ) , NULL } ,
{ F_65 ( V_87 ) ,
F_14 } ,
{ F_65 ( V_88 ) ,
F_15 } ,
{ F_65 ( V_89 ) ,
F_34 } ,
{ F_65 ( V_90 ) ,
F_37 } ,
{ F_65 ( V_91 ) ,
F_39 } ,
{ F_65 ( V_92 ) ,
F_41 } ,
{ F_65 ( V_93 ) ,
F_42 } ,
{ F_65 ( V_94 ) ,
F_49 } ,
{ F_65 ( V_95 ) ,
F_51 } ,
{ F_65 ( V_96 ) ,
F_52 } ,
{ F_65 ( V_97 ) ,
F_56 } ,
{ F_65 ( V_98 ) ,
F_58 } ,
{ F_65 ( V_99 ) ,
F_59 }
} ;
unsigned int V_100 = F_65 ( V_5 ) ;
return ( V_100 >= F_66 ( V_85 ) ) ? NULL : V_85 [ V_100 ] . V_84 ;
}
static int F_67 ( unsigned int V_101 , struct V_6 T_2 * V_102 )
{
struct V_6 * V_7 ;
struct V_19 * V_27 ;
struct V_18 * V_21 ;
unsigned int V_103 , V_5 ;
T_4 V_84 = NULL ;
int V_8 = 0 ;
if ( ! F_68 ( V_104 ) )
return - V_105 ;
V_103 = F_69 ( V_106 ) ;
V_5 = F_69 ( V_101 ) ;
if ( F_70 ( V_101 ) != F_70 ( V_106 ) ||
V_5 - V_103 >= V_107 ) {
return - V_108 ;
}
V_7 = F_5 ( V_102 ) ;
if ( F_30 ( V_7 ) )
return F_31 ( V_7 ) ;
V_8 = F_11 ( V_101 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_86 )
goto V_109;
V_84 = F_64 ( V_5 ) ;
if ( ! V_84 ) {
F_4 ( L_7 , V_101 ) ;
return - V_108 ;
}
V_27 = NULL ;
V_21 = NULL ;
if ( V_5 != V_89 &&
V_5 != V_90 ) {
V_27 = F_45 ( V_7 -> V_52 ) ;
if ( ! V_27 ) {
if ( V_5 == V_99 )
goto V_110;
V_8 = - V_63 ;
goto V_16;
}
if ( ! V_27 -> V_111 ) {
V_8 = - V_108 ;
F_47 ( V_27 ) ;
goto V_16;
}
V_21 = F_12 ( V_27 ) ;
if ( ! V_21 || V_21 -> V_80 != V_112 ) {
V_8 = - V_2 ;
F_47 ( V_27 ) ;
goto V_16;
}
if ( ! F_71 ( V_21 ) &&
V_5 != V_94 ) {
V_8 = - V_113 ;
F_47 ( V_27 ) ;
goto V_16;
}
}
V_110:
V_8 = V_84 ( V_27 , V_21 , V_7 ) ;
if ( V_27 )
F_47 ( V_27 ) ;
V_109:
if ( V_8 >= 0 && F_72 ( V_102 , V_7 , V_114 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_101 , T_6 V_115 )
{
int V_8 ;
V_8 = F_67 ( V_101 , (struct V_6 T_2 * ) V_115 ) ;
return ( long ) V_8 ;
}
static long F_73 ( struct V_19 * V_19 , T_5 V_101 , T_6 V_115 )
{
return ( long ) V_6 ( V_19 , V_101 , ( T_6 ) F_74 ( V_115 ) ) ;
}
int F_75 ( void )
{
int V_116 ;
V_116 = F_76 ( & V_117 ) ;
if ( V_116 ) {
F_77 ( L_8 ) ;
return V_116 ;
}
return 0 ;
}
void F_78 ( void )
{
F_79 ( & V_117 ) ;
return;
}
