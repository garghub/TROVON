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
if ( ( V_7 -> V_9 != V_10 ) ||
( V_7 -> V_11 > V_12 ) ) {
F_4 ( L_1
L_2 ,
V_10 ,
V_12 ,
V_7 -> V_9 , V_7 -> V_11 , V_5 ) ;
V_8 = - V_2 ;
}
V_7 -> V_9 = V_10 ;
V_7 -> V_11 = V_12 ;
return V_8 ;
}
static struct V_6 *
F_5 ( struct V_6 T_2 * V_13 )
{
struct V_6 V_14 , * V_15 ;
if ( F_6 ( & V_14 , V_13 , V_16 ) )
return F_7 ( - V_17 ) ;
if ( V_14 . V_4 < V_16 )
return F_7 ( - V_2 ) ;
if ( V_14 . V_4 > V_16 + V_18 )
return F_7 ( - V_19 ) ;
V_15 = F_8 ( V_13 , V_14 . V_4 ) ;
if ( ! F_9 ( V_15 ) )
V_15 -> V_4 = V_14 . V_4 ;
return V_15 ;
}
static inline void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_7 ) ;
}
static int F_12 ( int V_5 , struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_8 ) {
F_4 ( L_3
L_4 , V_5 ) ;
goto V_20;
}
if ( V_7 -> V_4 > V_16 ) {
V_8 = F_2 ( V_7 -> V_21 , V_7 -> V_4 - V_16 ) ;
if ( V_8 ) {
F_4 (
L_5 ,
V_5 ) ;
goto V_20;
}
V_8 = F_1 ( V_7 -> V_21 ) ;
if ( V_8 ) {
F_4 ( L_6 ,
V_5 ) ;
goto V_20;
}
}
V_8 = 0 ;
V_20:
return V_8 ;
}
static struct V_22 * F_13 ( struct V_23 * V_24 )
{
struct V_22 * V_25 = NULL ;
struct V_26 * V_26 ;
if ( V_24 ) {
V_26 = F_14 ( V_24 ) ;
V_25 = F_15 ( V_26 -> V_27 ) ;
}
return V_25 ;
}
static int F_16 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_10 ;
V_7 -> V_11 = V_12 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
V_7 -> V_29 . V_30 = V_25 -> V_30 ;
return 0 ;
}
static int F_18 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
V_7 -> V_31 . V_32 = V_25 -> V_32 ;
return 0 ;
}
static int F_19 ( const char * V_33 ,
struct V_21 * V_15 ,
int F_20 ( const struct V_21 * V_21 , void * V_34 ) ,
void * V_34 )
{
struct V_21 V_21 ;
int V_8 ;
V_8 = F_21 ( V_35 , V_33 , & V_21 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = - V_36 ;
while ( V_21 . V_37 == V_21 . V_38 -> V_39 ) {
if ( V_21 . V_37 -> V_40 -> V_41 == V_42 ) {
if ( F_20 ( & V_21 , V_34 ) ) {
F_22 ( & V_21 ) ;
* V_15 = V_21 ;
V_8 = 0 ;
break;
}
}
if ( ! F_23 ( & V_21 ) )
break;
}
F_24 ( & V_21 ) ;
return V_8 ;
}
static int F_25 ( const struct V_21 * V_21 , void * V_43 )
{
return V_21 -> V_37 -> V_40 -> V_44 == * ( V_45 * ) V_43 ;
}
static int F_26 ( const struct V_21 * V_21 , void * V_43 )
{
struct V_46 * V_47 = F_27 ( V_21 -> V_37 ) ;
return V_47 && V_47 -> V_25 -> type & * ( unsigned * ) V_43 ;
}
static int F_28 ( const char * V_1 , V_45 V_48 )
{
int V_8 , V_49 ;
V_49 = F_29 ( V_50 ) ;
if ( F_30 ( V_49 >= 0 ) ) {
struct V_23 * V_51 ;
struct V_21 V_21 ;
V_8 = F_19 ( V_1 , & V_21 , F_25 , & V_48 ) ;
if ( V_8 )
goto V_20;
V_51 = F_31 ( & V_21 , V_52 , F_32 () ) ;
F_24 ( & V_21 ) ;
if ( F_9 ( V_51 ) ) {
V_8 = F_33 ( V_51 ) ;
goto V_20;
}
F_34 ( V_49 , V_51 ) ;
}
return V_49 ;
V_20:
F_35 ( V_49 ) ;
return V_8 ;
}
static int F_36 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
const char * V_21 ;
V_45 V_48 ;
int V_8 , V_49 ;
if ( ! V_7 -> V_53 . V_48 )
return - V_2 ;
V_7 -> V_54 = - 1 ;
V_21 = V_7 -> V_21 ;
V_48 = F_37 ( V_7 -> V_53 . V_48 ) ;
V_8 = 0 ;
V_49 = F_28 ( V_21 , V_48 ) ;
if ( F_38 ( V_49 < 0 ) ) {
V_8 = V_49 ;
goto V_20;
}
V_7 -> V_54 = V_49 ;
V_20:
return V_8 ;
}
static int F_39 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
return F_40 ( V_7 -> V_54 ) ;
}
static int F_41 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
T_3 V_55 ;
V_55 = ( T_3 ) V_7 -> V_56 . V_55 ;
return F_42 ( V_25 , V_55 , 0 ) ;
}
static int F_43 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
T_3 V_55 ;
int V_57 ;
V_55 = ( T_3 ) V_7 -> V_58 . V_55 ;
V_57 = V_7 -> V_58 . V_57 < 0 ? V_7 -> V_58 . V_57 : - V_36 ;
return F_42 ( V_25 , V_55 , V_57 ) ;
}
static int F_44 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
int V_59 ;
int V_8 = 0 ;
struct V_60 * V_61 = NULL ;
if ( V_7 -> V_62 . V_59 == - 1 )
return - V_2 ;
V_59 = V_7 -> V_62 . V_59 ;
F_45 ( & V_25 -> V_63 ) ;
if ( ! V_25 -> V_64 ) {
F_46 ( & V_25 -> V_63 ) ;
return - V_65 ;
} else {
struct V_23 * V_66 ;
V_61 = F_47 ( V_67 , V_68 ) ;
if ( F_48 ( V_61 ) != F_48 ( V_25 -> V_69 ) ) {
F_4 ( L_7 ) ;
V_8 = - V_2 ;
goto V_20;
}
V_66 = F_49 ( V_59 ) ;
if ( ! V_66 ) {
V_8 = - V_70 ;
goto V_20;
}
if ( F_50 ( V_66 ) < 0 ) {
V_8 = - V_71 ;
F_51 ( V_66 ) ;
goto V_20;
}
F_52 ( V_25 -> V_69 , V_61 ) ;
V_25 -> V_59 = V_59 ;
V_25 -> V_66 = V_66 ;
V_25 -> V_64 = 0 ;
}
V_20:
F_53 ( V_61 ) ;
F_46 ( & V_25 -> V_63 ) ;
return V_8 ;
}
static int F_54 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
F_55 ( V_25 ) ;
return 0 ;
}
static int F_56 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
unsigned long V_72 ;
V_72 = V_7 -> V_72 . V_72 ;
V_7 -> V_72 . V_72 = V_25 -> V_73 / V_74 ;
V_25 -> V_73 = V_72 * V_74 ;
return 0 ;
}
static int F_57 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
struct V_46 * V_47 ;
struct V_21 V_21 ;
V_45 V_48 ;
int V_8 = - V_36 ;
if ( V_7 -> V_4 <= V_16 ) {
V_8 = - V_2 ;
goto V_20;
}
V_48 = V_25 -> V_75 -> V_44 ;
V_7 -> V_76 . V_77 = V_7 -> V_76 . V_78 = - 1 ;
V_8 = F_19 ( V_7 -> V_21 , & V_21 , F_25 , & V_48 ) ;
if ( V_8 )
goto V_20;
V_47 = F_27 ( V_21 . V_37 ) ;
if ( V_47 ) {
V_8 = 0 ;
F_58 ( & V_21 , 0 ) ;
F_59 ( & V_25 -> V_79 ) ;
V_7 -> V_76 . V_77 =
F_60 ( F_61 () , V_47 -> V_77 ) ;
V_7 -> V_76 . V_78 =
F_62 ( F_61 () , V_47 -> V_78 ) ;
F_63 ( & V_25 -> V_79 ) ;
}
F_24 ( & V_21 ) ;
V_20:
return V_8 ;
}
static int F_64 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
struct V_80 * V_38 ;
int V_81 ;
V_81 = V_7 -> V_82 . V_81 ;
V_38 = V_28 -> V_83 . V_38 ;
return F_65 ( V_25 -> V_75 , V_38 , V_25 , V_81 ) ;
}
static int F_66 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
V_7 -> V_84 . V_85 = 0 ;
if ( V_85 ( V_28 -> V_83 . V_38 ) )
V_7 -> V_84 . V_85 = 1 ;
return 0 ;
}
static int F_67 ( struct V_23 * V_28 ,
struct V_22 * V_25 ,
struct V_6 * V_7 )
{
struct V_21 V_21 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_48 , V_86 ;
int V_8 = - V_36 ;
if ( V_7 -> V_4 <= V_16 ) {
V_8 = - V_2 ;
goto V_20;
}
V_1 = V_7 -> V_21 ;
type = V_7 -> V_87 . V_13 . type ;
V_7 -> V_87 . V_20 . V_48 = V_48 = 0 ;
V_7 -> V_87 . V_20 . V_86 = V_86 = 0 ;
if ( ! V_28 || V_7 -> V_54 == - 1 ) {
if ( F_68 ( type ) )
V_8 = F_21 ( V_35 ,
V_1 , & V_21 , V_88 ) ;
else
V_8 = F_19 ( V_1 , & V_21 ,
F_26 , & type ) ;
if ( V_8 )
goto V_20;
V_48 = F_69 ( V_21 . V_37 -> V_40 -> V_44 ) ;
V_8 = 0 ;
if ( V_21 . V_38 -> V_39 == V_21 . V_37 ) {
V_8 = 1 ;
V_86 = V_21 . V_37 -> V_40 -> V_41 ;
}
} else {
V_45 V_89 = V_25 -> V_75 -> V_44 ;
V_8 = F_19 ( V_1 , & V_21 , F_25 , & V_89 ) ;
if ( V_8 )
goto V_20;
V_48 = F_69 ( V_89 ) ;
V_8 = F_70 ( & V_21 ) ;
if ( F_71 ( & V_21 ) )
V_86 = V_21 . V_37 -> V_40 -> V_41 ;
}
V_7 -> V_87 . V_20 . V_48 = V_48 ;
V_7 -> V_87 . V_20 . V_86 = V_86 ;
F_24 ( & V_21 ) ;
V_20:
return V_8 ;
}
static T_4 F_72 ( unsigned int V_5 )
{
static T_4 V_90 [] = {
F_16 ,
F_17 ,
F_18 ,
F_36 ,
F_39 ,
F_41 ,
F_43 ,
F_44 ,
F_54 ,
F_56 ,
F_57 ,
F_64 ,
F_66 ,
F_67 ,
} ;
unsigned int V_91 = F_73 ( V_5 ) ;
return ( V_91 >= F_74 ( V_90 ) ) ? NULL : V_90 [ V_91 ] ;
}
static int F_75 ( unsigned int V_92 ,
struct V_6 T_2 * V_93 )
{
struct V_6 * V_7 ;
struct V_23 * V_28 ;
struct V_22 * V_25 ;
unsigned int V_94 , V_5 ;
T_4 V_95 = NULL ;
int V_8 = 0 ;
V_94 = F_76 ( V_96 ) ;
V_5 = F_76 ( V_92 ) ;
if ( F_77 ( V_92 ) != F_77 ( V_96 ) ||
V_5 - V_94 > V_97 ) {
return - V_98 ;
}
if ( V_5 != V_99 &&
V_5 != V_100 &&
! F_78 ( V_101 ) )
return - V_102 ;
V_7 = F_5 ( V_93 ) ;
if ( F_9 ( V_7 ) )
return F_33 ( V_7 ) ;
V_8 = F_12 ( V_92 , V_7 ) ;
if ( V_8 )
goto V_20;
V_95 = F_72 ( V_5 ) ;
if ( ! V_95 ) {
F_4 ( L_8 , V_92 ) ;
V_8 = - V_98 ;
goto V_20;
}
V_28 = NULL ;
V_25 = NULL ;
if ( V_5 != V_99 &&
V_5 != V_103 &&
V_5 != V_104 ) {
V_28 = F_49 ( V_7 -> V_54 ) ;
if ( ! V_28 ) {
if ( V_5 == V_100 )
goto V_105;
V_8 = - V_70 ;
goto V_20;
}
V_25 = F_13 ( V_28 ) ;
if ( ! V_25 || V_25 -> V_86 != V_106 ) {
V_8 = - V_2 ;
F_51 ( V_28 ) ;
goto V_20;
}
if ( ! F_79 ( V_25 ) &&
V_5 != V_107 ) {
V_8 = - V_108 ;
F_51 ( V_28 ) ;
goto V_20;
}
}
V_105:
V_8 = V_95 ( V_28 , V_25 , V_7 ) ;
if ( V_28 )
F_51 ( V_28 ) ;
if ( V_8 >= 0 && F_80 ( V_93 , V_7 , V_16 ) )
V_8 = - V_17 ;
V_20:
F_10 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_23 * V_23 , unsigned int V_92 ,
unsigned long V_109 )
{
int V_8 ;
V_8 = F_75 ( V_92 , (struct V_6 T_2 * ) V_109 ) ;
return ( long ) V_8 ;
}
static long F_81 ( struct V_23 * V_23 , unsigned int V_92 ,
unsigned long V_109 )
{
return V_6 ( V_23 , V_92 , ( unsigned long ) F_82 ( V_109 ) ) ;
}
int T_5 F_83 ( void )
{
int V_110 ;
V_110 = F_84 ( & V_111 ) ;
if ( V_110 ) {
F_85 ( L_9 ) ;
return V_110 ;
}
return 0 ;
}
void F_86 ( void )
{
F_87 ( & V_111 ) ;
}
