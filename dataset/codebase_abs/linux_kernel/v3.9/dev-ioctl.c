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
int V_8 = F_19 ( V_29 , 0 , & V_17 ) ;
if ( V_8 )
return V_8 ;
V_8 = - V_32 ;
while ( V_17 . V_33 == V_17 . V_34 -> V_35 ) {
if ( V_17 . V_33 -> V_36 -> V_37 == V_38 ) {
if ( F_18 ( & V_17 , V_31 ) ) {
F_20 ( & V_17 ) ;
if ( ! V_8 )
F_21 ( V_30 ) ;
* V_30 = V_17 ;
V_8 = 0 ;
}
}
if ( ! F_22 ( & V_17 ) )
break;
}
F_21 ( & V_17 ) ;
return V_8 ;
}
static int F_23 ( struct V_17 * V_17 , void * V_39 )
{
return V_17 -> V_33 -> V_36 -> V_40 == * ( V_41 * ) V_39 ;
}
static int F_24 ( struct V_17 * V_17 , void * V_39 )
{
struct V_42 * V_43 = F_25 ( V_17 -> V_33 ) ;
return V_43 && V_43 -> V_21 -> type & * ( unsigned * ) V_39 ;
}
static int F_26 ( const char * V_1 , V_41 V_44 )
{
int V_8 , V_45 ;
V_45 = F_27 ( V_46 ) ;
if ( F_28 ( V_45 >= 0 ) ) {
struct V_19 * V_47 ;
struct V_17 V_17 ;
V_8 = F_17 ( V_1 , & V_17 , F_23 , & V_44 ) ;
if ( V_8 )
goto V_16;
V_47 = F_29 ( & V_17 , V_48 , F_30 () ) ;
F_21 ( & V_17 ) ;
if ( F_31 ( V_47 ) ) {
V_8 = F_32 ( V_47 ) ;
goto V_16;
}
F_33 ( V_45 , V_47 ) ;
}
return V_45 ;
V_16:
F_34 ( V_45 ) ;
return V_8 ;
}
static int F_35 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
const char * V_17 ;
V_41 V_44 ;
int V_8 , V_45 ;
if ( ! V_7 -> V_49 . V_44 )
return - V_2 ;
V_7 -> V_50 = - 1 ;
V_17 = V_7 -> V_17 ;
V_44 = F_36 ( V_7 -> V_49 . V_44 ) ;
V_8 = 0 ;
V_45 = F_26 ( V_17 , V_44 ) ;
if ( F_37 ( V_45 < 0 ) ) {
V_8 = V_45 ;
goto V_16;
}
V_7 -> V_50 = V_45 ;
V_16:
return V_8 ;
}
static int F_38 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
return F_39 ( V_7 -> V_50 ) ;
}
static int F_40 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_51 ;
V_51 = ( T_3 ) V_7 -> V_52 . V_51 ;
return F_41 ( V_21 , V_51 , 0 ) ;
}
static int F_42 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
T_3 V_51 ;
int V_53 ;
V_51 = ( T_3 ) V_7 -> V_54 . V_51 ;
V_53 = V_7 -> V_54 . V_53 ? V_7 -> V_54 . V_53 : - V_32 ;
return F_41 ( V_21 , V_51 , V_53 ) ;
}
static int F_43 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
int V_55 ;
int V_8 = 0 ;
if ( V_7 -> V_56 . V_55 == - 1 )
return - V_2 ;
V_55 = V_7 -> V_56 . V_55 ;
F_44 ( & V_21 -> V_57 ) ;
if ( ! V_21 -> V_58 ) {
F_45 ( & V_21 -> V_57 ) ;
return - V_59 ;
} else {
struct V_19 * V_60 = F_46 ( V_55 ) ;
if ( ! V_60 ) {
V_8 = - V_61 ;
goto V_16;
}
if ( F_47 ( V_60 ) < 0 ) {
V_8 = - V_62 ;
F_48 ( V_60 ) ;
goto V_16;
}
V_21 -> V_63 = F_49 ( V_64 ) ;
V_21 -> V_55 = V_55 ;
V_21 -> V_60 = V_60 ;
V_21 -> V_58 = 0 ;
}
V_16:
F_45 ( & V_21 -> V_57 ) ;
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
unsigned long V_65 ;
V_65 = V_7 -> V_65 . V_65 ;
V_7 -> V_65 . V_65 = V_21 -> V_66 / V_67 ;
V_21 -> V_66 = V_65 * V_67 ;
return 0 ;
}
static int F_53 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_42 * V_43 ;
struct V_17 V_17 ;
V_41 V_44 ;
int V_8 = - V_32 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_44 = V_21 -> V_68 -> V_40 ;
V_7 -> V_69 . V_70 = V_7 -> V_69 . V_71 = - 1 ;
V_8 = F_17 ( V_7 -> V_17 , & V_17 , F_23 , & V_44 ) ;
if ( V_8 )
goto V_16;
V_43 = F_25 ( V_17 . V_33 ) ;
if ( V_43 ) {
V_8 = 0 ;
F_54 ( V_17 . V_33 ) ;
F_55 ( & V_21 -> V_72 ) ;
V_7 -> V_69 . V_70 = F_56 ( F_57 () , V_43 -> V_70 ) ;
V_7 -> V_69 . V_71 = F_58 ( F_57 () , V_43 -> V_71 ) ;
F_59 ( & V_21 -> V_72 ) ;
}
F_21 ( & V_17 ) ;
V_16:
return V_8 ;
}
static int F_60 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_73 * V_34 ;
int V_74 ;
V_74 = V_7 -> V_75 . V_74 ;
V_34 = V_24 -> V_76 . V_34 ;
return F_61 ( V_21 -> V_68 , V_34 , V_21 , V_74 ) ;
}
static int F_62 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
V_7 -> V_77 . V_78 = 0 ;
if ( V_78 ( V_24 -> V_76 . V_34 ) )
V_7 -> V_77 . V_78 = 1 ;
return 0 ;
}
static int F_63 ( struct V_19 * V_24 ,
struct V_18 * V_21 ,
struct V_6 * V_7 )
{
struct V_17 V_17 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_44 , V_79 ;
int V_8 = - V_32 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_16;
}
V_1 = V_7 -> V_17 ;
type = V_7 -> V_80 . V_13 . type ;
V_7 -> V_80 . V_16 . V_44 = V_44 = 0 ;
V_7 -> V_80 . V_16 . V_79 = V_79 = 0 ;
if ( ! V_24 || V_7 -> V_50 == - 1 ) {
if ( F_64 ( type ) )
V_8 = F_19 ( V_1 , V_81 , & V_17 ) ;
else
V_8 = F_17 ( V_1 , & V_17 , F_24 , & type ) ;
if ( V_8 )
goto V_16;
V_44 = F_65 ( V_17 . V_33 -> V_36 -> V_40 ) ;
V_8 = 0 ;
if ( V_17 . V_34 -> V_35 == V_17 . V_33 ) {
V_8 = 1 ;
V_79 = V_17 . V_33 -> V_36 -> V_37 ;
}
} else {
V_41 V_82 = V_21 -> V_68 -> V_40 ;
V_8 = F_17 ( V_1 , & V_17 , F_23 , & V_82 ) ;
if ( V_8 )
goto V_16;
V_44 = F_65 ( V_82 ) ;
V_8 = F_66 ( V_17 . V_33 ) ;
if ( F_67 ( & V_17 ) )
V_79 = V_17 . V_33 -> V_36 -> V_37 ;
}
V_7 -> V_80 . V_16 . V_44 = V_44 ;
V_7 -> V_80 . V_16 . V_79 = V_79 ;
F_21 ( & V_17 ) ;
V_16:
return V_8 ;
}
static T_4 F_68 ( unsigned int V_5 )
{
static struct {
int V_5 ;
T_4 V_83 ;
} V_84 [] = {
{ F_69 ( V_85 ) , NULL } ,
{ F_69 ( V_86 ) ,
F_15 } ,
{ F_69 ( V_87 ) ,
F_16 } ,
{ F_69 ( V_88 ) ,
F_35 } ,
{ F_69 ( V_89 ) ,
F_38 } ,
{ F_69 ( V_90 ) ,
F_40 } ,
{ F_69 ( V_91 ) ,
F_42 } ,
{ F_69 ( V_92 ) ,
F_43 } ,
{ F_69 ( V_93 ) ,
F_50 } ,
{ F_69 ( V_94 ) ,
F_52 } ,
{ F_69 ( V_95 ) ,
F_53 } ,
{ F_69 ( V_96 ) ,
F_60 } ,
{ F_69 ( V_97 ) ,
F_62 } ,
{ F_69 ( V_98 ) ,
F_63 }
} ;
unsigned int V_99 = F_69 ( V_5 ) ;
return ( V_99 >= F_70 ( V_84 ) ) ? NULL : V_84 [ V_99 ] . V_83 ;
}
static int F_71 ( unsigned int V_100 , struct V_6 T_2 * V_101 )
{
struct V_6 * V_7 ;
struct V_19 * V_24 ;
struct V_18 * V_21 ;
unsigned int V_102 , V_5 ;
T_4 V_83 = NULL ;
int V_8 = 0 ;
if ( ! F_72 ( V_103 ) )
return - V_104 ;
V_102 = F_73 ( V_105 ) ;
V_5 = F_73 ( V_100 ) ;
if ( F_74 ( V_100 ) != F_74 ( V_105 ) ||
V_5 - V_102 >= V_106 ) {
return - V_107 ;
}
V_7 = F_5 ( V_101 ) ;
if ( F_31 ( V_7 ) )
return F_32 ( V_7 ) ;
V_8 = F_11 ( V_100 , V_7 ) ;
if ( V_8 )
goto V_16;
if ( V_5 == V_85 )
goto V_108;
V_83 = F_68 ( V_5 ) ;
if ( ! V_83 ) {
F_4 ( L_7 , V_100 ) ;
return - V_107 ;
}
V_24 = NULL ;
V_21 = NULL ;
if ( V_5 != V_88 &&
V_5 != V_89 ) {
V_24 = F_46 ( V_7 -> V_50 ) ;
if ( ! V_24 ) {
if ( V_5 == V_98 )
goto V_109;
V_8 = - V_61 ;
goto V_16;
}
if ( ! V_24 -> V_110 ) {
V_8 = - V_107 ;
F_48 ( V_24 ) ;
goto V_16;
}
V_21 = F_12 ( V_24 ) ;
if ( ! V_21 || V_21 -> V_79 != V_111 ) {
V_8 = - V_2 ;
F_48 ( V_24 ) ;
goto V_16;
}
if ( ! F_75 ( V_21 ) &&
V_5 != V_93 ) {
V_8 = - V_112 ;
F_48 ( V_24 ) ;
goto V_16;
}
}
V_109:
V_8 = V_83 ( V_24 , V_21 , V_7 ) ;
if ( V_24 )
F_48 ( V_24 ) ;
V_108:
if ( V_8 >= 0 && F_76 ( V_101 , V_7 , V_113 ) )
V_8 = - V_15 ;
V_16:
F_9 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_19 * V_19 , T_5 V_100 , T_6 V_114 )
{
int V_8 ;
V_8 = F_71 ( V_100 , (struct V_6 T_2 * ) V_114 ) ;
return ( long ) V_8 ;
}
static long F_77 ( struct V_19 * V_19 , T_5 V_100 , T_6 V_114 )
{
return ( long ) V_6 ( V_19 , V_100 , ( T_6 ) F_78 ( V_114 ) ) ;
}
int F_79 ( void )
{
int V_115 ;
V_115 = F_80 ( & V_116 ) ;
if ( V_115 ) {
F_81 ( L_8 ) ;
return V_115 ;
}
return 0 ;
}
void F_82 ( void )
{
F_83 ( & V_116 ) ;
return;
}
