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
struct V_57 * V_58 = NULL ;
if ( V_7 -> V_59 . V_56 == - 1 )
return - V_2 ;
V_56 = V_7 -> V_59 . V_56 ;
F_44 ( & V_21 -> V_60 ) ;
if ( ! V_21 -> V_61 ) {
F_45 ( & V_21 -> V_60 ) ;
return - V_62 ;
} else {
struct V_19 * V_63 ;
V_58 = F_46 ( V_64 , V_65 ) ;
if ( F_47 ( V_58 ) != F_47 ( V_21 -> V_66 ) ) {
F_4 ( L_7 ) ;
V_8 = - V_2 ;
goto V_16;
}
V_63 = F_48 ( V_56 ) ;
if ( ! V_63 ) {
V_8 = - V_67 ;
goto V_16;
}
if ( F_49 ( V_63 ) < 0 ) {
V_8 = - V_68 ;
F_50 ( V_63 ) ;
goto V_16;
}
F_51 ( V_21 -> V_66 , V_58 ) ;
V_21 -> V_56 = V_56 ;
V_21 -> V_63 = V_63 ;
V_21 -> V_61 = 0 ;
}
V_16:
F_52 ( V_58 ) ;
F_45 ( & V_21 -> V_60 ) ;
return V_8 ;
}
static int F_53 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
F_54 ( V_21 ) ;
return 0 ;
}
static int F_55 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
unsigned long V_69 ;
V_69 = V_7 -> V_69 . V_69 ;
V_7 -> V_69 . V_69 = V_21 -> V_70 / V_71 ;
V_21 -> V_70 = V_69 * V_71 ;
return 0 ;
}
static int F_56 ( struct V_19 * V_24 ,
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
V_45 = V_21 -> V_72 -> V_41 ;
V_7 -> V_73 . V_74 = V_7 -> V_73 . V_75 = - 1 ;
V_8 = F_17 ( V_7 -> V_17 , & V_17 , F_23 , & V_45 ) ;
if ( V_8 )
goto V_16;
V_44 = F_25 ( V_17 . V_34 ) ;
if ( V_44 ) {
V_8 = 0 ;
F_57 ( V_17 . V_34 ) ;
F_58 ( & V_21 -> V_76 ) ;
V_7 -> V_73 . V_74 = F_59 ( F_60 () , V_44 -> V_74 ) ;
V_7 -> V_73 . V_75 = F_61 ( F_60 () , V_44 -> V_75 ) ;
F_62 ( & V_21 -> V_76 ) ;
}
F_22 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_63 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_77 * V_35 ;
int V_78 ;
V_78 = V_7 -> V_79 . V_78 ;
V_35 = V_24 -> V_80 . V_35 ;
return F_64 ( V_21 -> V_72 , V_35 , V_21 , V_78 ) ;
}
static int F_65 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_81 . V_82 = 0 ;
if ( V_82 ( V_24 -> V_80 . V_35 ) )
V_7 -> V_81 . V_82 = 1 ;
return 0 ;
}
static int F_66 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_45 , V_83 ;
int V_8 = - V_33 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_84 . V_13 . type ;
V_7 -> V_84 . V_16 . V_45 = V_45 = 0 ;
V_7 -> V_84 . V_16 . V_83 = V_83 = 0 ;
if ( ! V_24 || V_7 -> V_51 == - 1 ) {
if ( F_67 ( type ) )
V_8 = F_19 ( V_32 ,
V_1 , & V_17 , V_85 ) ;
else
V_8 = F_17 ( V_1 , & V_17 ,
F_24 , & type ) ;
if ( V_8 )
goto V_16;
V_45 = F_68 ( V_17 . V_34 -> V_37 -> V_41 ) ;
V_8 = 0 ;
if ( V_17 . V_35 -> V_36 == V_17 . V_34 ) {
V_8 = 1 ;
V_83 = V_17 . V_34 -> V_37 -> V_38 ;
}
} else {
V_42 V_86 = V_21 -> V_72 -> V_41 ;
V_8 = F_17 ( V_1 , & V_17 , F_23 , & V_86 ) ;
if ( V_8 )
goto V_16;
V_45 = F_68 ( V_86 ) ;
V_8 = F_69 ( V_17 . V_34 ) ;
if ( F_70 ( & V_17 ) )
V_83 = V_17 . V_34 -> V_37 -> V_38 ;
}
V_7 -> V_84 . V_16 . V_45 = V_45 ;
V_7 -> V_84 . V_16 . V_83 = V_83 ;
F_22 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_71 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_87 ;
} V_88 [] = {
{ F_72 ( V_89 ) , NULL } ,
{ F_72 ( V_90 ) ,
F_15 } ,
{ F_72 ( V_91 ) ,
F_16 } ,
{ F_72 ( V_92 ) ,
F_35 } ,
{ F_72 ( V_93 ) ,
F_38 } ,
{ F_72 ( V_94 ) ,
F_40 } ,
{ F_72 ( V_95 ) ,
F_42 } ,
{ F_72 ( V_96 ) ,
F_43 } ,
{ F_72 ( V_97 ) ,
F_53 } ,
{ F_72 ( V_98 ) ,
F_55 } ,
{ F_72 ( V_99 ) ,
F_56 } ,
{ F_72 ( V_100 ) ,
F_63 } ,
{ F_72 ( V_101 ) ,
F_65 } ,
{ F_72 ( V_102 ) ,
F_66 }
} ;
unsigned int V_103 = F_72 ( V_5 ) ;
return ( V_103 >= F_73 ( V_88 ) ) ? NULL : V_88 [ V_103 ] . V_87 ;
}
static int F_74 ( unsigned int V_104 , struct V_6 T_2 * V_105 )
{
struct V_6 * V_7 ;
struct V_19 * V_24 ;
struct V_18 * V_21 ;
unsigned int V_106 , V_5 ;
T_4 V_87 = NULL ;
int V_8 = 0 ;
if ( ! F_75 ( V_107 ) )
return - V_108 ;
V_106 = F_76 ( V_109 ) ;
V_5 = F_76 ( V_104 ) ;
if ( F_77 ( V_104 ) != F_77 ( V_109 ) ||
V_5 - V_106 >= V_110 ) {
return - V_111 ;
}
V_7 = F_5 ( V_105 ) ;
if ( F_31 ( V_7 ) )
return F_32 ( V_7 ) ;
V_8 = F_11 ( V_104 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_89 )
goto V_112;
V_87 = F_71 ( V_5 ) ;
if ( ! V_87 ) {
F_4 ( L_8 , V_104 ) ;
return - V_111 ;
}
V_24 = NULL ;
V_21 = NULL ;
if ( V_5 != V_92 &&
V_5 != V_93 ) {
V_24 = F_48 ( V_7 -> V_51 ) ;
if ( ! V_24 ) {
if ( V_5 == V_102 )
goto V_113;
V_8 = - V_67 ;
goto V_16;
}
V_21 = F_12 ( V_24 ) ;
if ( ! V_21 || V_21 -> V_83 != V_114 ) {
V_8 = - V_2 ;
F_50 ( V_24 ) ;
goto V_16;
}
if ( ! F_78 ( V_21 ) &&
V_5 != V_97 ) {
V_8 = - V_115 ;
F_50 ( V_24 ) ;
goto V_16;
}
}
V_113:
V_8 = V_87 ( V_24 , V_21 , V_7 ) ;
if ( V_24 )
F_50 ( V_24 ) ;
V_112:
if ( V_8 >= 0 && F_79 ( V_105 , V_7 , V_116 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_104 , T_6 V_117 )
{
int V_8 ;
V_8 = F_74 ( V_104 , (struct V_6 T_2 * ) V_117 ) ;
return ( long ) V_8 ;
}
static long F_80 ( struct V_19 * V_19 , T_5 V_104 , T_6 V_117 )
{
return ( long ) V_6 ( V_19 , V_104 , ( T_6 ) F_81 ( V_117 ) ) ;
}
int F_82 ( void )
{
int V_118 ;
V_118 = F_83 ( & V_119 ) ;
if ( V_118 ) {
F_84 ( L_9 ) ;
return V_118 ;
}
return 0 ;
}
void F_85 ( void )
{
F_86 ( & V_119 ) ;
return;
}
