void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 -> V_6 ) {
V_5 = F_2 ( V_7 , F_3 () ) ;
F_4 ( & V_5 -> V_8 ) ;
F_5 ( & V_2 -> V_9 , & V_5 -> V_10 ) ;
V_2 -> V_6 = true ;
V_2 -> V_11 = V_12 + V_3 ;
F_6 ( F_3 () , V_13 ,
& V_2 -> V_14 , V_3 ) ;
F_7 ( & V_5 -> V_8 ) ;
}
}
static int F_8 ( struct V_15 * V_16 ,
unsigned int V_17 )
{
int V_18 ;
struct V_19 * V_20 ;
V_16 -> V_20 = F_9 ( struct V_19 ) ;
F_10 ( L_1 , V_16 , V_16 -> V_20 ) ;
if ( ! V_16 -> V_20 )
return - V_21 ;
F_11 (cpu) {
V_20 = F_2 ( V_16 -> V_20 , V_18 ) ;
F_10 ( L_2 , V_18 , V_16 -> V_20 ) ;
F_12 ( & V_20 -> V_16 , V_17 ) ;
F_13 ( & V_20 -> V_22 , V_23 ) ;
}
return 0 ;
}
static void F_14 ( struct V_15 * V_16 )
{
int V_18 ;
struct V_19 * V_20 ;
F_11 (cpu) {
V_20 = F_2 ( V_16 -> V_20 , V_18 ) ;
F_15 ( V_20 -> V_16 . V_24 ) ;
}
F_16 ( V_16 -> V_20 ) ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
int V_18 , V_29 ;
struct V_19 * V_20 ;
V_18 = F_18 () ;
V_20 = F_19 ( V_16 -> V_20 ) ;
V_28 -> V_30 . V_18 = V_18 ;
V_29 = F_20 ( & V_20 -> V_16 , V_26 ) ;
F_10 ( L_3 ,
V_18 , V_20 , V_26 ) ;
F_21 ( V_18 , V_13 , & V_20 -> V_22 ) ;
F_22 () ;
return V_29 ;
}
static void F_23 ( void )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_2 ( V_7 , F_3 () ) ;
while ( F_24 () ) {
F_4 ( & V_5 -> V_8 ) ;
if ( F_25 ( & V_5 -> V_10 ) ) {
F_7 ( & V_5 -> V_8 ) ;
return;
}
V_2 = F_26 ( V_5 -> V_10 . V_31 ,
struct V_1 , V_9 ) ;
if ( ! V_2 -> V_6 ) {
F_7 ( & V_5 -> V_8 ) ;
return;
}
F_27 ( & V_2 -> V_9 ) ;
V_2 -> V_6 = false ;
F_7 ( & V_5 -> V_8 ) ;
V_2 -> V_32 -> V_33 ( V_2 ) ;
}
}
static void V_23 ( struct V_34 * V_22 )
{
struct V_19 * V_20 ;
struct V_25 * V_35 , * V_36 ;
int V_37 ;
V_20 = F_28 ( V_22 , struct V_19 , V_22 ) ;
V_37 = 0 ;
while ( V_37 < V_38 || F_24 () ) {
F_29 () ;
F_30 () ;
V_36 = F_31 ( & V_20 -> V_16 ) ;
V_35 = F_32 ( & V_20 -> V_16 ) ;
F_33 () ;
F_34 () ;
if ( ! V_35 ) {
F_23 () ;
return;
}
if ( V_36 )
V_36 -> V_39 ( V_36 , - V_40 ) ;
V_35 -> V_39 ( V_35 , 0 ) ;
if ( ! V_20 -> V_16 . V_24 )
return;
++ V_37 ;
}
if ( V_20 -> V_16 . V_24 )
F_35 ( V_13 , & V_20 -> V_22 ) ;
}
void F_36 ( struct V_34 * V_41 )
{
struct V_1 * V_42 ;
struct V_43 * V_32 ;
struct V_4 * V_5 ;
int V_18 ;
V_18 = F_3 () ;
V_42 = F_28 ( F_37 ( V_41 ) ,
struct V_1 , V_14 ) ;
V_32 = V_42 -> V_32 ;
if ( V_42 -> V_18 != V_18 )
F_10 ( L_4 ,
V_18 , V_42 -> V_18 ) ;
if ( V_42 -> V_6 ) {
V_5 = F_2 ( V_7 , V_18 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_27 ( & V_42 -> V_9 ) ;
V_42 -> V_6 = false ;
F_7 ( & V_5 -> V_8 ) ;
V_32 -> V_33 ( V_42 ) ;
}
}
static inline struct V_15 * F_38 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_39 ( V_45 ) ;
struct V_48 * V_49 = F_40 ( V_47 ) ;
return V_49 -> V_16 ;
}
static void * F_41 ( struct V_50 * V_51 , unsigned int V_52 ,
unsigned int V_53 )
{
char * V_54 ;
struct V_46 * V_47 ;
int V_29 ;
V_54 = F_42 ( V_52 + sizeof( * V_47 ) + V_53 , V_55 ) ;
if ( ! V_54 )
return F_43 ( - V_21 ) ;
V_47 = ( void * ) ( V_54 + V_52 ) ;
V_29 = - V_56 ;
if ( snprintf ( V_47 -> V_51 . V_57 , V_58 ,
L_5 , V_51 -> V_57 ) >= V_58 )
goto V_59;
memcpy ( V_47 -> V_51 . V_60 , V_51 -> V_60 , V_58 ) ;
V_47 -> V_51 . V_61 = V_51 -> V_61 + 50 ;
V_47 -> V_51 . V_62 = V_51 -> V_62 ;
V_47 -> V_51 . V_63 = V_51 -> V_63 ;
V_64:
return V_54 ;
V_59:
F_44 ( V_54 ) ;
V_54 = F_43 ( V_29 ) ;
goto V_64;
}
static inline void F_45 ( struct V_65 * * V_66 , T_1 * type ,
T_1 * V_67 )
{
struct V_68 * V_69 ;
V_69 = F_46 ( V_66 ) ;
if ( F_47 ( V_69 ) )
return;
if ( ( V_69 -> type & V_70 ) )
* type |= V_70 ;
if ( ( V_69 -> V_67 & V_70 ) )
* V_67 |= V_70 ;
}
static int F_48 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_39 ( V_45 ) ;
struct V_71 * V_49 = F_40 ( V_47 ) ;
struct V_72 * V_73 = & V_49 -> V_73 ;
struct V_74 * V_75 = F_49 ( V_45 ) ;
struct V_76 * V_77 ;
V_77 = F_50 ( V_73 ) ;
if ( F_47 ( V_77 ) )
return F_51 ( V_77 ) ;
V_75 -> V_78 = V_77 ;
F_52 ( F_53 ( V_45 ) ,
sizeof( struct V_27 ) +
F_54 ( V_77 ) ) ;
return 0 ;
}
static void F_55 ( struct V_44 * V_45 )
{
struct V_74 * V_75 = F_49 ( V_45 ) ;
F_56 ( V_75 -> V_78 ) ;
}
static int F_57 ( struct V_79 * V_80 ,
const T_2 * V_81 , unsigned int V_82 )
{
struct V_74 * V_75 = F_58 ( V_80 ) ;
struct V_76 * V_78 = V_75 -> V_78 ;
int V_29 ;
F_59 ( V_78 , V_83 ) ;
F_60 ( V_78 , F_61 ( V_80 ) &
V_83 ) ;
V_29 = F_62 ( V_78 , V_81 , V_82 ) ;
F_63 ( V_80 , F_64 ( V_78 ) &
V_84 ) ;
return V_29 ;
}
static int F_65 ( struct V_85 * V_35 ,
T_3 V_39 )
{
int V_86 ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
struct V_79 * V_45 = F_67 ( V_35 ) ;
struct V_15 * V_16 =
F_38 ( F_68 ( V_45 ) ) ;
V_28 -> V_39 = V_35 -> V_87 . V_39 ;
V_35 -> V_87 . V_39 = V_39 ;
V_86 = F_17 ( V_16 , & V_35 -> V_87 , V_28 ) ;
return V_86 ;
}
static void F_69 ( struct V_25 * V_88 , int V_29 )
{
struct V_74 * V_75 = F_49 ( V_88 -> V_45 ) ;
struct V_76 * V_78 = V_75 -> V_78 ;
struct V_85 * V_35 = F_70 ( V_88 ) ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
struct V_89 * V_90 = & V_28 -> V_90 ;
if ( F_71 ( V_29 == - V_40 ) )
goto V_64;
V_90 -> V_45 = V_78 ;
V_90 -> V_91 = V_92 ;
V_29 = F_72 ( V_90 ) ;
V_35 -> V_87 . V_39 = V_28 -> V_39 ;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_87 , V_29 ) ;
F_34 () ;
}
static int F_73 ( struct V_85 * V_35 )
{
return F_65 ( V_35 , F_69 ) ;
}
static void F_74 ( struct V_25 * V_88 , int V_29 )
{
struct V_85 * V_35 = F_70 ( V_88 ) ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
if ( F_71 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_75 ( V_35 , & V_28 -> V_90 ) ;
if ( V_29 ) {
V_35 -> V_87 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_87 , V_29 ) ;
F_34 () ;
}
static int F_76 ( struct V_85 * V_35 )
{
return F_65 ( V_35 , F_74 ) ;
}
static void F_77 ( struct V_25 * V_88 , int V_29 )
{
struct V_85 * V_35 = F_70 ( V_88 ) ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
if ( F_71 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_78 ( V_35 , & V_28 -> V_90 ) ;
if ( V_29 ) {
V_35 -> V_87 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_87 , V_29 ) ;
F_34 () ;
}
static int F_79 ( struct V_85 * V_35 )
{
return F_65 ( V_35 , F_77 ) ;
}
static void F_80 ( struct V_25 * V_88 , int V_29 )
{
struct V_85 * V_35 = F_70 ( V_88 ) ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
if ( F_71 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_81 ( V_35 , & V_28 -> V_90 ) ;
if ( V_29 ) {
V_35 -> V_87 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_87 , V_29 ) ;
F_34 () ;
}
static int F_82 ( struct V_85 * V_35 )
{
return F_65 ( V_35 , F_80 ) ;
}
static void F_83 ( struct V_25 * V_88 , int V_29 )
{
struct V_74 * V_75 = F_49 ( V_88 -> V_45 ) ;
struct V_76 * V_78 = V_75 -> V_78 ;
struct V_85 * V_35 = F_70 ( V_88 ) ;
struct V_27 * V_28 = F_66 ( V_35 ) ;
struct V_89 * V_90 = & V_28 -> V_90 ;
if ( F_71 ( V_29 == - V_40 ) )
goto V_64;
V_90 -> V_45 = V_78 ;
V_90 -> V_91 = V_92 ;
V_29 = F_84 ( V_35 , V_90 ) ;
if ( V_29 ) {
V_35 -> V_87 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_87 , V_29 ) ;
F_34 () ;
}
static int F_85 ( struct V_85 * V_35 )
{
return F_65 ( V_35 , F_83 ) ;
}
static int F_86 ( struct V_85 * V_35 , void * V_64 )
{
struct V_27 * V_28 = F_66 ( V_35 ) ;
return F_87 ( & V_28 -> V_90 , V_64 ) ;
}
static int F_88 ( struct V_85 * V_35 , const void * V_93 )
{
struct V_27 * V_28 = F_66 ( V_35 ) ;
return F_89 ( & V_28 -> V_90 , V_93 ) ;
}
static int F_90 ( struct V_94 * V_95 , struct V_65 * * V_66 ,
struct V_15 * V_16 )
{
struct V_71 * V_75 ;
struct V_96 * V_47 ;
struct V_97 * V_98 ;
struct V_50 * V_51 ;
T_1 type = 0 ;
T_1 V_67 = 0 ;
int V_29 ;
F_45 ( V_66 , & type , & V_67 ) ;
V_98 = F_91 ( V_66 [ 1 ] , type , V_67 ) ;
if ( F_47 ( V_98 ) )
return F_51 ( V_98 ) ;
V_51 = & V_98 -> V_87 ;
F_10 ( L_6 , V_51 -> V_60 ) ;
V_47 = F_41 ( V_51 , F_92 () ,
sizeof( * V_75 ) ) ;
V_29 = F_51 ( V_47 ) ;
if ( F_47 ( V_47 ) )
goto V_99;
V_75 = F_93 ( V_47 ) ;
V_75 -> V_16 = V_16 ;
V_29 = F_94 ( & V_75 -> V_73 , V_98 ,
F_95 ( V_47 ) ) ;
if ( V_29 )
goto V_59;
type = V_100 ;
if ( V_51 -> V_101 & V_70 )
type |= V_70 ;
V_47 -> V_51 . V_102 . V_87 . V_101 = type ;
V_47 -> V_51 . V_102 . V_103 = V_98 -> V_103 ;
V_47 -> V_51 . V_102 . V_87 . V_104 = sizeof( struct V_74 ) ;
V_47 -> V_51 . V_102 . V_87 . V_105 = F_48 ;
V_47 -> V_51 . V_102 . V_87 . V_106 = F_55 ;
V_47 -> V_51 . V_107 = F_73 ;
V_47 -> V_51 . V_108 = F_76 ;
V_47 -> V_51 . V_109 = F_79 ;
V_47 -> V_51 . V_110 = F_82 ;
V_47 -> V_51 . V_111 = F_86 ;
V_47 -> V_51 . V_112 = F_88 ;
V_47 -> V_51 . V_113 = F_57 ;
V_47 -> V_51 . V_114 = F_85 ;
V_29 = F_96 ( V_95 , V_47 ) ;
if ( V_29 ) {
F_97 ( & V_75 -> V_73 ) ;
V_59:
F_44 ( V_47 ) ;
}
V_99:
F_98 ( V_51 ) ;
return V_29 ;
}
static int F_99 ( struct V_94 * V_95 , struct V_65 * * V_66 )
{
struct V_68 * V_69 ;
V_69 = F_46 ( V_66 ) ;
if ( F_47 ( V_69 ) )
return F_51 ( V_69 ) ;
switch ( V_69 -> type & V_69 -> V_67 & V_115 ) {
case V_116 :
return F_90 ( V_95 , V_66 , & V_117 ) ;
break;
}
return - V_118 ;
}
static void F_100 ( struct V_46 * V_47 )
{
struct V_48 * V_75 = F_40 ( V_47 ) ;
struct V_71 * V_119 = F_40 ( V_47 ) ;
switch ( V_47 -> V_51 . V_101 & V_115 ) {
case V_120 :
F_97 ( & V_119 -> V_73 ) ;
F_44 ( V_96 ( V_47 ) ) ;
return;
default:
F_101 ( & V_75 -> V_73 ) ;
F_44 ( V_47 ) ;
}
}
struct V_121 * F_102 ( const char * V_122 ,
T_1 type , T_1 V_67 )
{
char V_123 [ V_58 ] ;
struct V_79 * V_45 ;
if ( snprintf ( V_123 , V_58 ,
L_5 , V_122 ) >= V_58 )
return F_43 ( - V_118 ) ;
V_45 = F_103 ( V_123 , type , V_67 ) ;
if ( F_47 ( V_45 ) )
return F_104 ( V_45 ) ;
if ( V_45 -> V_87 . V_124 -> V_125 != V_126 ) {
F_105 ( V_45 ) ;
return F_43 ( - V_118 ) ;
}
return F_106 ( V_45 ) ;
}
int F_84 ( struct V_85 * V_35 ,
struct V_89 * V_90 )
{
int V_29 ;
V_29 = F_72 ( V_90 ) ? :
F_81 ( V_35 , V_90 ) ;
return V_29 ;
}
int F_75 ( struct V_85 * V_35 ,
struct V_89 * V_90 )
{
struct V_76 * V_45 = V_90 -> V_45 ;
struct V_97 * V_127 = F_107 ( V_45 ) ;
return V_127 -> V_108 ( V_90 , NULL , 0 ) ;
}
int F_81 ( struct V_85 * V_35 ,
struct V_89 * V_90 )
{
struct V_76 * V_45 = V_90 -> V_45 ;
struct V_97 * V_127 = F_107 ( V_45 ) ;
return V_127 -> V_110 ( V_90 , NULL , 0 , V_35 -> V_128 ) ;
}
int F_78 ( struct V_85 * V_35 ,
struct V_89 * V_90 )
{
struct V_76 * V_45 = V_90 -> V_45 ;
struct V_97 * V_127 = F_107 ( V_45 ) ;
return V_127 -> V_109 ( V_90 , V_35 -> V_128 ) ;
}
struct V_76 * F_108 ( struct V_121 * V_45 )
{
struct V_74 * V_75 = F_58 ( & V_45 -> V_87 ) ;
return V_75 -> V_78 ;
}
struct V_89 * F_109 ( struct V_85 * V_35 )
{
struct V_27 * V_28 = F_66 ( V_35 ) ;
return & V_28 -> V_90 ;
}
void F_110 ( struct V_121 * V_45 )
{
F_105 ( & V_45 -> V_87 ) ;
}
static int T_4 F_111 ( void )
{
int V_29 , V_18 ;
struct V_4 * V_5 ;
V_7 = F_9 ( struct V_4 ) ;
F_11 (cpu) {
V_5 = F_2 ( V_7 , V_18 ) ;
F_112 ( & V_5 -> V_10 ) ;
F_113 ( & V_5 -> V_8 ) ;
}
V_29 = F_8 ( & V_117 , V_129 ) ;
if ( V_29 ) {
F_16 ( V_7 ) ;
return V_29 ;
}
V_29 = F_114 ( & V_130 ) ;
if ( V_29 ) {
F_14 ( & V_117 ) ;
F_16 ( V_7 ) ;
}
return V_29 ;
}
static void T_5 F_115 ( void )
{
F_14 ( & V_117 ) ;
F_116 ( & V_130 ) ;
F_16 ( V_7 ) ;
}
