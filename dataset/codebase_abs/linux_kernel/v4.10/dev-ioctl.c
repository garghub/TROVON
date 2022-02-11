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
if ( F_6 ( & V_14 , V_13 , sizeof( V_14 ) ) )
return F_7 ( - V_16 ) ;
if ( V_14 . V_4 < sizeof( V_14 ) )
return F_7 ( - V_2 ) ;
if ( V_14 . V_4 > ( V_17 + sizeof( V_14 ) ) )
return F_7 ( - V_18 ) ;
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
goto V_19;
}
if ( V_7 -> V_4 > sizeof( * V_7 ) ) {
V_8 = F_2 ( V_7 -> V_20 , V_7 -> V_4 - sizeof( * V_7 ) ) ;
if ( V_8 ) {
F_4 (
L_5 ,
V_5 ) ;
goto V_19;
}
V_8 = F_1 ( V_7 -> V_20 ) ;
if ( V_8 ) {
F_4 ( L_6 ,
V_5 ) ;
goto V_19;
}
}
V_8 = 0 ;
V_19:
return V_8 ;
}
static struct V_21 * F_13 ( struct V_22 * V_23 )
{
struct V_21 * V_24 = NULL ;
struct V_25 * V_25 ;
if ( V_23 ) {
V_25 = F_14 ( V_23 ) ;
V_24 = F_15 ( V_25 -> V_26 ) ;
}
return V_24 ;
}
static int F_16 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
V_7 -> V_9 = V_10 ;
V_7 -> V_11 = V_12 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
V_7 -> V_28 . V_29 = V_24 -> V_29 ;
return 0 ;
}
static int F_18 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
V_7 -> V_30 . V_31 = V_24 -> V_31 ;
return 0 ;
}
static int F_19 ( const char * V_32 ,
struct V_20 * V_15 ,
int F_20 ( const struct V_20 * V_20 , void * V_33 ) ,
void * V_33 )
{
struct V_20 V_20 ;
int V_8 ;
V_8 = F_21 ( V_34 , V_32 , & V_20 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = - V_35 ;
while ( V_20 . V_36 == V_20 . V_37 -> V_38 ) {
if ( V_20 . V_36 -> V_39 -> V_40 == V_41 ) {
if ( F_20 ( & V_20 , V_33 ) ) {
F_22 ( & V_20 ) ;
* V_15 = V_20 ;
V_8 = 0 ;
break;
}
}
if ( ! F_23 ( & V_20 ) )
break;
}
F_24 ( & V_20 ) ;
return V_8 ;
}
static int F_25 ( const struct V_20 * V_20 , void * V_42 )
{
return V_20 -> V_36 -> V_39 -> V_43 == * ( V_44 * ) V_42 ;
}
static int F_26 ( const struct V_20 * V_20 , void * V_42 )
{
struct V_45 * V_46 = F_27 ( V_20 -> V_36 ) ;
return V_46 && V_46 -> V_24 -> type & * ( unsigned * ) V_42 ;
}
static int F_28 ( const char * V_1 , V_44 V_47 )
{
int V_8 , V_48 ;
V_48 = F_29 ( V_49 ) ;
if ( F_30 ( V_48 >= 0 ) ) {
struct V_22 * V_50 ;
struct V_20 V_20 ;
V_8 = F_19 ( V_1 , & V_20 , F_25 , & V_47 ) ;
if ( V_8 )
goto V_19;
V_50 = F_31 ( & V_20 , V_51 , F_32 () ) ;
F_24 ( & V_20 ) ;
if ( F_9 ( V_50 ) ) {
V_8 = F_33 ( V_50 ) ;
goto V_19;
}
F_34 ( V_48 , V_50 ) ;
}
return V_48 ;
V_19:
F_35 ( V_48 ) ;
return V_8 ;
}
static int F_36 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
const char * V_20 ;
V_44 V_47 ;
int V_8 , V_48 ;
if ( ! V_7 -> V_52 . V_47 )
return - V_2 ;
V_7 -> V_53 = - 1 ;
V_20 = V_7 -> V_20 ;
V_47 = F_37 ( V_7 -> V_52 . V_47 ) ;
V_8 = 0 ;
V_48 = F_28 ( V_20 , V_47 ) ;
if ( F_38 ( V_48 < 0 ) ) {
V_8 = V_48 ;
goto V_19;
}
V_7 -> V_53 = V_48 ;
V_19:
return V_8 ;
}
static int F_39 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
return F_40 ( V_7 -> V_53 ) ;
}
static int F_41 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
T_3 V_54 ;
V_54 = ( T_3 ) V_7 -> V_55 . V_54 ;
return F_42 ( V_24 , V_54 , 0 ) ;
}
static int F_43 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
T_3 V_54 ;
int V_56 ;
V_54 = ( T_3 ) V_7 -> V_57 . V_54 ;
V_56 = V_7 -> V_57 . V_56 ? V_7 -> V_57 . V_56 : - V_35 ;
return F_42 ( V_24 , V_54 , V_56 ) ;
}
static int F_44 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
int V_58 ;
int V_8 = 0 ;
struct V_59 * V_60 = NULL ;
if ( V_7 -> V_61 . V_58 == - 1 )
return - V_2 ;
V_58 = V_7 -> V_61 . V_58 ;
F_45 ( & V_24 -> V_62 ) ;
if ( ! V_24 -> V_63 ) {
F_46 ( & V_24 -> V_62 ) ;
return - V_64 ;
} else {
struct V_22 * V_65 ;
V_60 = F_47 ( V_66 , V_67 ) ;
if ( F_48 ( V_60 ) != F_48 ( V_24 -> V_68 ) ) {
F_4 ( L_7 ) ;
V_8 = - V_2 ;
goto V_19;
}
V_65 = F_49 ( V_58 ) ;
if ( ! V_65 ) {
V_8 = - V_69 ;
goto V_19;
}
if ( F_50 ( V_65 ) < 0 ) {
V_8 = - V_70 ;
F_51 ( V_65 ) ;
goto V_19;
}
F_52 ( V_24 -> V_68 , V_60 ) ;
V_24 -> V_58 = V_58 ;
V_24 -> V_65 = V_65 ;
V_24 -> V_63 = 0 ;
}
V_19:
F_53 ( V_60 ) ;
F_46 ( & V_24 -> V_62 ) ;
return V_8 ;
}
static int F_54 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
F_55 ( V_24 ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
unsigned long V_71 ;
V_71 = V_7 -> V_71 . V_71 ;
V_7 -> V_71 . V_71 = V_24 -> V_72 / V_73 ;
V_24 -> V_72 = V_71 * V_73 ;
return 0 ;
}
static int F_57 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
struct V_45 * V_46 ;
struct V_20 V_20 ;
V_44 V_47 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_19;
}
V_47 = V_24 -> V_74 -> V_43 ;
V_7 -> V_75 . V_76 = V_7 -> V_75 . V_77 = - 1 ;
V_8 = F_19 ( V_7 -> V_20 , & V_20 , F_25 , & V_47 ) ;
if ( V_8 )
goto V_19;
V_46 = F_27 ( V_20 . V_36 ) ;
if ( V_46 ) {
V_8 = 0 ;
F_58 ( & V_20 , 0 ) ;
F_59 ( & V_24 -> V_78 ) ;
V_7 -> V_75 . V_76 =
F_60 ( F_61 () , V_46 -> V_76 ) ;
V_7 -> V_75 . V_77 =
F_62 ( F_61 () , V_46 -> V_77 ) ;
F_63 ( & V_24 -> V_78 ) ;
}
F_24 ( & V_20 ) ;
V_19:
return V_8 ;
}
static int F_64 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
struct V_79 * V_37 ;
int V_80 ;
V_80 = V_7 -> V_81 . V_80 ;
V_37 = V_27 -> V_82 . V_37 ;
return F_65 ( V_24 -> V_74 , V_37 , V_24 , V_80 ) ;
}
static int F_66 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
V_7 -> V_83 . V_84 = 0 ;
if ( V_84 ( V_27 -> V_82 . V_37 ) )
V_7 -> V_83 . V_84 = 1 ;
return 0 ;
}
static int F_67 ( struct V_22 * V_27 ,
struct V_21 * V_24 ,
struct V_6 * V_7 )
{
struct V_20 V_20 ;
const char * V_1 ;
unsigned int type ;
unsigned int V_47 , V_85 ;
int V_8 = - V_35 ;
if ( V_7 -> V_4 <= sizeof( * V_7 ) ) {
V_8 = - V_2 ;
goto V_19;
}
V_1 = V_7 -> V_20 ;
type = V_7 -> V_86 . V_13 . type ;
V_7 -> V_86 . V_19 . V_47 = V_47 = 0 ;
V_7 -> V_86 . V_19 . V_85 = V_85 = 0 ;
if ( ! V_27 || V_7 -> V_53 == - 1 ) {
if ( F_68 ( type ) )
V_8 = F_21 ( V_34 ,
V_1 , & V_20 , V_87 ) ;
else
V_8 = F_19 ( V_1 , & V_20 ,
F_26 , & type ) ;
if ( V_8 )
goto V_19;
V_47 = F_69 ( V_20 . V_36 -> V_39 -> V_43 ) ;
V_8 = 0 ;
if ( V_20 . V_37 -> V_38 == V_20 . V_36 ) {
V_8 = 1 ;
V_85 = V_20 . V_36 -> V_39 -> V_40 ;
}
} else {
V_44 V_88 = V_24 -> V_74 -> V_43 ;
V_8 = F_19 ( V_1 , & V_20 , F_25 , & V_88 ) ;
if ( V_8 )
goto V_19;
V_47 = F_69 ( V_88 ) ;
V_8 = F_70 ( & V_20 ) ;
if ( F_71 ( & V_20 ) )
V_85 = V_20 . V_36 -> V_39 -> V_40 ;
}
V_7 -> V_86 . V_19 . V_47 = V_47 ;
V_7 -> V_86 . V_19 . V_85 = V_85 ;
F_24 ( & V_20 ) ;
V_19:
return V_8 ;
}
static T_4 F_72 ( unsigned int V_5 )
{
static T_4 V_89 [] = {
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
unsigned int V_90 = F_73 ( V_5 ) ;
return ( V_90 >= F_74 ( V_89 ) ) ? NULL : V_89 [ V_90 ] ;
}
static int F_75 ( unsigned int V_91 ,
struct V_6 T_2 * V_92 )
{
struct V_6 * V_7 ;
struct V_22 * V_27 ;
struct V_21 * V_24 ;
unsigned int V_93 , V_5 ;
T_4 V_94 = NULL ;
int V_8 = 0 ;
if ( ! F_76 ( V_95 ) )
return - V_96 ;
V_93 = F_77 ( V_97 ) ;
V_5 = F_77 ( V_91 ) ;
if ( F_78 ( V_91 ) != F_78 ( V_97 ) ||
V_5 - V_93 > V_98 ) {
return - V_99 ;
}
V_7 = F_5 ( V_92 ) ;
if ( F_9 ( V_7 ) )
return F_33 ( V_7 ) ;
V_8 = F_12 ( V_91 , V_7 ) ;
if ( V_8 )
goto V_19;
V_94 = F_72 ( V_5 ) ;
if ( ! V_94 ) {
F_4 ( L_8 , V_91 ) ;
V_8 = - V_99 ;
goto V_19;
}
V_27 = NULL ;
V_24 = NULL ;
if ( V_5 != V_100 &&
V_5 != V_101 &&
V_5 != V_102 ) {
V_27 = F_49 ( V_7 -> V_53 ) ;
if ( ! V_27 ) {
if ( V_5 == V_103 )
goto V_104;
V_8 = - V_69 ;
goto V_19;
}
V_24 = F_13 ( V_27 ) ;
if ( ! V_24 || V_24 -> V_85 != V_105 ) {
V_8 = - V_2 ;
F_51 ( V_27 ) ;
goto V_19;
}
if ( ! F_79 ( V_24 ) &&
V_5 != V_106 ) {
V_8 = - V_107 ;
F_51 ( V_27 ) ;
goto V_19;
}
}
V_104:
V_8 = V_94 ( V_27 , V_24 , V_7 ) ;
if ( V_27 )
F_51 ( V_27 ) ;
if ( V_8 >= 0 && F_80 ( V_92 , V_7 , V_108 ) )
V_8 = - V_16 ;
V_19:
F_10 ( V_7 ) ;
return V_8 ;
}
static long V_6 ( struct V_22 * V_22 , T_5 V_91 , T_6 V_109 )
{
int V_8 ;
V_8 = F_75 ( V_91 , (struct V_6 T_2 * ) V_109 ) ;
return ( long ) V_8 ;
}
static long F_81 ( struct V_22 * V_22 , T_5 V_91 , T_6 V_109 )
{
return ( long ) V_6 ( V_22 , V_91 , ( T_6 ) F_82 ( V_109 ) ) ;
}
int T_7 F_83 ( void )
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
