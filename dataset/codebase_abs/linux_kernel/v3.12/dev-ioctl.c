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
V_22 = F_13 ( V_20 ) ;
V_21 = F_14 ( V_22 -> V_23 ) ;
}
return V_21 ;
}
static int F_15 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_25 . V_26 = V_21 -> V_26 ;
return 0 ;
}
static int F_16 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_27 . V_28 = V_21 -> V_28 ;
return 0 ;
}
static int F_17 ( const char * V_29 ,
struct V_17 * V_30 ,
int F_18 ( struct V_17 * V_17 , void * V_31 ) ,
void * V_31 )
{
struct V_17 V_17 ;
int V_8 = F_19 ( V_32 , V_29 , & V_17 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = - V_33 ;
while ( V_17 . V_34 == V_17 . V_35 -> V_36 ) {
if ( V_17 . V_34 -> V_37 -> V_38 == V_39 ) {
if ( F_18 ( & V_17 , V_31 ) ) {
F_20 ( & V_17 ) ;
* V_30 = V_17 ;
V_8 = 0 ;
break;
}
}
if ( ! F_21 ( & V_17 ) )
break;
}
F_22 ( & V_17 ) ;
return V_8 ;
}
static int F_23 ( struct V_17 * V_17 , void * V_40 )
{
return V_17 -> V_34 -> V_37 -> V_41 == * ( V_42 * ) V_40 ;
}
static int F_24 ( struct V_17 * V_17 , void * V_40 )
{
struct V_43 * V_44 = F_25 ( V_17 -> V_34 ) ;
return V_44 && V_44 -> V_21 -> type & * ( unsigned * ) V_40 ;
}
static int F_26 ( const char * V_1 , V_42 V_45 )
{
int V_8 , V_46 ;
V_46 = F_27 ( V_47 ) ;
if ( F_28 ( V_46 >= 0 ) ) {
struct V_19 * V_48 ;
struct V_17 V_17 ;
V_8 = F_17 ( V_1 , & V_17 , F_23 , & V_45 ) ;
if ( V_8 )
goto V_16;
V_48 = F_29 ( & V_17 , V_49 , F_30 () ) ;
F_22 ( & V_17 ) ;
if ( F_31 ( V_48 ) ) {
V_8 = F_32 ( V_48 ) ;
goto V_16;
}
F_33 ( V_46 , V_48 ) ;
}
return V_46 ;
V_16:
F_34 ( V_46 ) ;
return V_8 ;
}
static int F_35 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
const char * V_17 ;
V_42 V_45 ;
int V_8 , V_46 ;
if ( ! V_7 -> V_50 . V_45 )
return - V_2 ;
V_7 -> V_51 = - 1 ;
V_17 = V_7 -> V_17 ;
V_45 = F_36 ( V_7 -> V_50 . V_45 ) ;
V_8 = 0 ;
V_46 = F_26 ( V_17 , V_45 ) ;
if ( F_37 ( V_46 < 0 ) ) {
V_8 = V_46 ;
goto V_16;
}
V_7 -> V_51 = V_46 ;
V_16:
return V_8 ;
}
static int F_38 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
return F_39 ( V_7 -> V_51 ) ;
}
static int F_40 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_52 ;
V_52 = ( T_3 ) V_7 -> V_53 . V_52 ;
return F_41 ( V_21 , V_52 , 0 ) ;
}
static int F_42 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_52 ;
int V_54 ;
V_52 = ( T_3 ) V_7 -> V_55 . V_52 ;
V_54 = V_7 -> V_55 . V_54 ? V_7 -> V_55 . V_54 : - V_33 ;
return F_41 ( V_21 , V_52 , V_54 ) ;
}
static int F_43 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
int V_56 ;
int V_8 = 0 ;
if ( V_7 -> V_57 . V_56 == - 1 )
return - V_2 ;
V_56 = V_7 -> V_57 . V_56 ;
F_44 ( & V_21 -> V_58 ) ;
if ( ! V_21 -> V_59 ) {
F_45 ( & V_21 -> V_58 ) ;
return - V_60 ;
} else {
struct V_19 * V_61 = F_46 ( V_56 ) ;
if ( ! V_61 ) {
V_8 = - V_62 ;
goto V_16;
}
if ( F_47 ( V_61 ) < 0 ) {
V_8 = - V_63 ;
F_48 ( V_61 ) ;
goto V_16;
}
V_21 -> V_64 = F_49 ( V_65 ) ;
V_21 -> V_56 = V_56 ;
V_21 -> V_61 = V_61 ;
V_21 -> V_59 = 0 ;
}
V_16:
F_45 ( & V_21 -> V_58 ) ;
return V_8 ;
}
static int F_50 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
F_51 ( V_21 ) ;
return 0 ;
}
static int F_52 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
unsigned long V_66 ;
V_66 = V_7 -> V_66 . V_66 ;
V_7 -> V_66 . V_66 = V_21 -> V_67 / V_68 ;
V_21 -> V_67 = V_66 * V_68 ;
return 0 ;
}
static int F_53 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_43 * V_44 ;
struct V_17 V_17 ;
V_42 V_45 ;
int V_8 = - V_33 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_45 = V_21 -> V_69 -> V_41 ;
V_7 -> V_70 . V_71 = V_7 -> V_70 . V_72 = - 1 ;
V_8 = F_17 ( V_7 -> V_17 , & V_17 , F_23 , & V_45 ) ;
if ( V_8 )
goto V_16;
V_44 = F_25 ( V_17 . V_34 ) ;
if ( V_44 ) {
V_8 = 0 ;
F_54 ( V_17 . V_34 ) ;
F_55 ( & V_21 -> V_73 ) ;
V_7 -> V_70 . V_71 = F_56 ( F_57 () , V_44 -> V_71 ) ;
V_7 -> V_70 . V_72 = F_58 ( F_57 () , V_44 -> V_72 ) ;
F_59 ( & V_21 -> V_73 ) ;
}
F_22 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_60 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_74 * V_35 ;
int V_75 ;
V_75 = V_7 -> V_76 . V_75 ;
V_35 = V_24 -> V_77 . V_35 ;
return F_61 ( V_21 -> V_69 , V_35 , V_21 , V_75 ) ;
}
static int F_62 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_78 . V_79 = 0 ;
if ( V_79 ( V_24 -> V_77 . V_35 ) )
V_7 -> V_78 . V_79 = 1 ;
return 0 ;
}
static int F_63 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_45 , V_80 ;
int V_8 = - V_33 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_81 . V_13 . type ;
V_7 -> V_81 . V_16 . V_45 = V_45 = 0 ;
V_7 -> V_81 . V_16 . V_80 = V_80 = 0 ;
if ( ! V_24 || V_7 -> V_51 == - 1 ) {
if ( F_64 ( type ) )
V_8 = F_19 ( V_32 ,
V_1 , & V_17 , V_82 ) ;
else
V_8 = F_17 ( V_1 , & V_17 ,
F_24 , & type ) ;
if ( V_8 )
goto V_16;
V_45 = F_65 ( V_17 . V_34 -> V_37 -> V_41 ) ;
V_8 = 0 ;
if ( V_17 . V_35 -> V_36 == V_17 . V_34 ) {
V_8 = 1 ;
V_80 = V_17 . V_34 -> V_37 -> V_38 ;
}
} else {
V_42 V_83 = V_21 -> V_69 -> V_41 ;
V_8 = F_17 ( V_1 , & V_17 , F_23 , & V_83 ) ;
if ( V_8 )
goto V_16;
V_45 = F_65 ( V_83 ) ;
V_8 = F_66 ( V_17 . V_34 ) ;
if ( F_67 ( & V_17 ) )
V_80 = V_17 . V_34 -> V_37 -> V_38 ;
}
V_7 -> V_81 . V_16 . V_45 = V_45 ;
V_7 -> V_81 . V_16 . V_80 = V_80 ;
F_22 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_68 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_84 ;
} V_85 [] = {
{ F_69 ( V_86 ) , NULL } ,
{ F_69 ( V_87 ) ,
F_15 } ,
{ F_69 ( V_88 ) ,
F_16 } ,
{ F_69 ( V_89 ) ,
F_35 } ,
{ F_69 ( V_90 ) ,
F_38 } ,
{ F_69 ( V_91 ) ,
F_40 } ,
{ F_69 ( V_92 ) ,
F_42 } ,
{ F_69 ( V_93 ) ,
F_43 } ,
{ F_69 ( V_94 ) ,
F_50 } ,
{ F_69 ( V_95 ) ,
F_52 } ,
{ F_69 ( V_96 ) ,
F_53 } ,
{ F_69 ( V_97 ) ,
F_60 } ,
{ F_69 ( V_98 ) ,
F_62 } ,
{ F_69 ( V_99 ) ,
F_63 }
} ;
unsigned int V_100 = F_69 ( V_5 ) ;
return ( V_100 >= F_70 ( V_85 ) ) ? NULL : V_85 [ V_100 ] . V_84 ;
}
static int F_71 ( unsigned int V_101 , struct V_6 T_2 * V_102 )
{
struct V_6 * V_7 ;
struct V_19 * V_24 ;
struct V_18 * V_21 ;
unsigned int V_103 , V_5 ;
T_4 V_84 = NULL ;
int V_8 = 0 ;
if ( ! F_72 ( V_104 ) )
return - V_105 ;
V_103 = F_73 ( V_106 ) ;
V_5 = F_73 ( V_101 ) ;
if ( F_74 ( V_101 ) != F_74 ( V_106 ) ||
V_5 - V_103 >= V_107 ) {
return - V_108 ;
}
V_7 = F_5 ( V_102 ) ;
if ( F_31 ( V_7 ) )
return F_32 ( V_7 ) ;
V_8 = F_11 ( V_101 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_86 )
goto V_109;
V_84 = F_68 ( V_5 ) ;
if ( ! V_84 ) {
F_4 ( L_7 , V_101 ) ;
return - V_108 ;
}
V_24 = NULL ;
V_21 = NULL ;
if ( V_5 != V_89 &&
V_5 != V_90 ) {
V_24 = F_46 ( V_7 -> V_51 ) ;
if ( ! V_24 ) {
if ( V_5 == V_99 )
goto V_110;
V_8 = - V_62 ;
goto V_16;
}
if ( ! V_24 -> V_111 ) {
V_8 = - V_108 ;
F_48 ( V_24 ) ;
goto V_16;
}
V_21 = F_12 ( V_24 ) ;
if ( ! V_21 || V_21 -> V_80 != V_112 ) {
V_8 = - V_2 ;
F_48 ( V_24 ) ;
goto V_16;
}
if ( ! F_75 ( V_21 ) &&
V_5 != V_94 ) {
V_8 = - V_113 ;
F_48 ( V_24 ) ;
goto V_16;
}
}
V_110:
V_8 = V_84 ( V_24 , V_21 , V_7 ) ;
if ( V_24 )
F_48 ( V_24 ) ;
V_109:
if ( V_8 >= 0 && F_76 ( V_102 , V_7 , V_114 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_101 , T_6 V_115 )
{
int V_8 ;
V_8 = F_71 ( V_101 , (struct V_6 T_2 * ) V_115 ) ;
return ( long ) V_8 ;
}
static long F_77 ( struct V_19 * V_19 , T_5 V_101 , T_6 V_115 )
{
return ( long ) V_6 ( V_19 , V_101 , ( T_6 ) F_78 ( V_115 ) ) ;
}
int F_79 ( void )
{
int V_116 ;
V_116 = F_80 ( & V_117 ) ;
if ( V_116 ) {
F_81 ( L_8 ) ;
return V_116 ;
}
return 0 ;
}
void F_82 ( void )
{
F_83 ( & V_117 ) ;
return;
}
