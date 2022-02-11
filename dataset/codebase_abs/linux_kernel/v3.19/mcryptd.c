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
static int F_45 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = F_39 ( V_45 ) ;
struct V_65 * V_49 = F_40 ( V_47 ) ;
struct V_66 * V_67 = & V_49 -> V_67 ;
struct V_68 * V_69 = F_46 ( V_45 ) ;
struct V_70 * V_71 ;
V_71 = F_47 ( V_67 ) ;
if ( F_48 ( V_71 ) )
return F_49 ( V_71 ) ;
V_69 -> V_72 = V_71 ;
F_50 ( F_51 ( V_45 ) ,
sizeof( struct V_27 ) +
F_52 ( V_71 ) ) ;
return 0 ;
}
static void F_53 ( struct V_44 * V_45 )
{
struct V_68 * V_69 = F_46 ( V_45 ) ;
F_54 ( V_69 -> V_72 ) ;
}
static int F_55 ( struct V_73 * V_74 ,
const T_1 * V_75 , unsigned int V_76 )
{
struct V_68 * V_69 = F_56 ( V_74 ) ;
struct V_70 * V_72 = V_69 -> V_72 ;
int V_29 ;
F_57 ( V_72 , V_77 ) ;
F_58 ( V_72 , F_59 ( V_74 ) &
V_77 ) ;
V_29 = F_60 ( V_72 , V_75 , V_76 ) ;
F_61 ( V_74 , F_62 ( V_72 ) &
V_78 ) ;
return V_29 ;
}
static int F_63 ( struct V_79 * V_35 ,
T_2 V_39 )
{
int V_80 ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
struct V_73 * V_45 = F_65 ( V_35 ) ;
struct V_15 * V_16 =
F_38 ( F_66 ( V_45 ) ) ;
V_28 -> V_39 = V_35 -> V_81 . V_39 ;
V_35 -> V_81 . V_39 = V_39 ;
V_80 = F_17 ( V_16 , & V_35 -> V_81 , V_28 ) ;
return V_80 ;
}
static void F_67 ( struct V_25 * V_82 , int V_29 )
{
struct V_68 * V_69 = F_46 ( V_82 -> V_45 ) ;
struct V_70 * V_72 = V_69 -> V_72 ;
struct V_79 * V_35 = F_68 ( V_82 ) ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
struct V_83 * V_84 = & V_28 -> V_84 ;
if ( F_69 ( V_29 == - V_40 ) )
goto V_64;
V_84 -> V_45 = V_72 ;
V_84 -> V_85 = V_86 ;
V_29 = F_70 ( V_84 ) ;
V_35 -> V_81 . V_39 = V_28 -> V_39 ;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_81 , V_29 ) ;
F_34 () ;
}
static int F_71 ( struct V_79 * V_35 )
{
return F_63 ( V_35 , F_67 ) ;
}
static void F_72 ( struct V_25 * V_82 , int V_29 )
{
struct V_79 * V_35 = F_68 ( V_82 ) ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
if ( F_69 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_73 ( V_35 , & V_28 -> V_84 ) ;
if ( V_29 ) {
V_35 -> V_81 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_81 , V_29 ) ;
F_34 () ;
}
static int F_74 ( struct V_79 * V_35 )
{
return F_63 ( V_35 , F_72 ) ;
}
static void F_75 ( struct V_25 * V_82 , int V_29 )
{
struct V_79 * V_35 = F_68 ( V_82 ) ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
if ( F_69 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_76 ( V_35 , & V_28 -> V_84 ) ;
if ( V_29 ) {
V_35 -> V_81 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_81 , V_29 ) ;
F_34 () ;
}
static int F_77 ( struct V_79 * V_35 )
{
return F_63 ( V_35 , F_75 ) ;
}
static void F_78 ( struct V_25 * V_82 , int V_29 )
{
struct V_79 * V_35 = F_68 ( V_82 ) ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
if ( F_69 ( V_29 == - V_40 ) )
goto V_64;
V_29 = F_79 ( V_35 , & V_28 -> V_84 ) ;
if ( V_29 ) {
V_35 -> V_81 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_81 , V_29 ) ;
F_34 () ;
}
static int F_80 ( struct V_79 * V_35 )
{
return F_63 ( V_35 , F_78 ) ;
}
static void F_81 ( struct V_25 * V_82 , int V_29 )
{
struct V_68 * V_69 = F_46 ( V_82 -> V_45 ) ;
struct V_70 * V_72 = V_69 -> V_72 ;
struct V_79 * V_35 = F_68 ( V_82 ) ;
struct V_27 * V_28 = F_64 ( V_35 ) ;
struct V_83 * V_84 = & V_28 -> V_84 ;
if ( F_69 ( V_29 == - V_40 ) )
goto V_64;
V_84 -> V_45 = V_72 ;
V_84 -> V_85 = V_86 ;
V_29 = F_82 ( V_35 , V_84 ) ;
if ( V_29 ) {
V_35 -> V_81 . V_39 = V_28 -> V_39 ;
goto V_64;
}
return;
V_64:
F_29 () ;
V_28 -> V_39 ( & V_35 -> V_81 , V_29 ) ;
F_34 () ;
}
static int F_83 ( struct V_79 * V_35 )
{
return F_63 ( V_35 , F_81 ) ;
}
static int F_84 ( struct V_79 * V_35 , void * V_64 )
{
struct V_27 * V_28 = F_64 ( V_35 ) ;
return F_85 ( & V_28 -> V_84 , V_64 ) ;
}
static int F_86 ( struct V_79 * V_35 , const void * V_87 )
{
struct V_27 * V_28 = F_64 ( V_35 ) ;
return F_87 ( & V_28 -> V_84 , V_87 ) ;
}
static int F_88 ( struct V_88 * V_89 , struct V_90 * * V_91 ,
struct V_15 * V_16 )
{
struct V_65 * V_69 ;
struct V_92 * V_47 ;
struct V_93 * V_94 ;
struct V_50 * V_51 ;
int V_29 ;
V_94 = F_89 ( V_91 [ 1 ] , 0 , 0 ) ;
if ( F_48 ( V_94 ) )
return F_49 ( V_94 ) ;
V_51 = & V_94 -> V_81 ;
F_10 ( L_6 , V_51 -> V_60 ) ;
V_47 = F_41 ( V_51 , F_90 () ,
sizeof( * V_69 ) ) ;
V_29 = F_49 ( V_47 ) ;
if ( F_48 ( V_47 ) )
goto V_95;
V_69 = F_91 ( V_47 ) ;
V_69 -> V_16 = V_16 ;
V_29 = F_92 ( & V_69 -> V_67 , V_94 ,
F_93 ( V_47 ) ) ;
if ( V_29 )
goto V_59;
V_47 -> V_51 . V_96 . V_81 . V_97 = V_98 ;
V_47 -> V_51 . V_96 . V_99 = V_94 -> V_99 ;
V_47 -> V_51 . V_96 . V_81 . V_100 = sizeof( struct V_68 ) ;
V_47 -> V_51 . V_96 . V_81 . V_101 = F_45 ;
V_47 -> V_51 . V_96 . V_81 . V_102 = F_53 ;
V_47 -> V_51 . V_103 = F_71 ;
V_47 -> V_51 . V_104 = F_74 ;
V_47 -> V_51 . V_105 = F_77 ;
V_47 -> V_51 . V_106 = F_80 ;
V_47 -> V_51 . V_107 = F_84 ;
V_47 -> V_51 . V_108 = F_86 ;
V_47 -> V_51 . V_109 = F_55 ;
V_47 -> V_51 . V_110 = F_83 ;
V_29 = F_94 ( V_89 , V_47 ) ;
if ( V_29 ) {
F_95 ( & V_69 -> V_67 ) ;
V_59:
F_44 ( V_47 ) ;
}
V_95:
F_96 ( V_51 ) ;
return V_29 ;
}
static int F_97 ( struct V_88 * V_89 , struct V_90 * * V_91 )
{
struct V_111 * V_112 ;
V_112 = F_98 ( V_91 ) ;
if ( F_48 ( V_112 ) )
return F_49 ( V_112 ) ;
switch ( V_112 -> type & V_112 -> V_113 & V_114 ) {
case V_115 :
return F_88 ( V_89 , V_91 , & V_116 ) ;
break;
}
return - V_117 ;
}
static void F_99 ( struct V_46 * V_47 )
{
struct V_48 * V_69 = F_40 ( V_47 ) ;
struct V_65 * V_118 = F_40 ( V_47 ) ;
switch ( V_47 -> V_51 . V_97 & V_114 ) {
case V_119 :
F_95 ( & V_118 -> V_67 ) ;
F_44 ( V_92 ( V_47 ) ) ;
return;
default:
F_100 ( & V_69 -> V_67 ) ;
F_44 ( V_47 ) ;
}
}
struct V_120 * F_101 ( const char * V_121 ,
T_3 type , T_3 V_113 )
{
char V_122 [ V_58 ] ;
struct V_73 * V_45 ;
if ( snprintf ( V_122 , V_58 ,
L_5 , V_121 ) >= V_58 )
return F_43 ( - V_117 ) ;
V_45 = F_102 ( V_122 , type , V_113 ) ;
if ( F_48 ( V_45 ) )
return F_103 ( V_45 ) ;
if ( V_45 -> V_81 . V_123 -> V_124 != V_125 ) {
F_104 ( V_45 ) ;
return F_43 ( - V_117 ) ;
}
return F_105 ( V_45 ) ;
}
int F_82 ( struct V_79 * V_35 ,
struct V_83 * V_84 )
{
int V_29 ;
V_29 = F_70 ( V_84 ) ? :
F_79 ( V_35 , V_84 ) ;
return V_29 ;
}
int F_73 ( struct V_79 * V_35 ,
struct V_83 * V_84 )
{
struct V_70 * V_45 = V_84 -> V_45 ;
struct V_93 * V_126 = F_106 ( V_45 ) ;
return V_126 -> V_104 ( V_84 , NULL , 0 ) ;
}
int F_79 ( struct V_79 * V_35 ,
struct V_83 * V_84 )
{
struct V_70 * V_45 = V_84 -> V_45 ;
struct V_93 * V_126 = F_106 ( V_45 ) ;
return V_126 -> V_106 ( V_84 , NULL , 0 , V_35 -> V_127 ) ;
}
int F_76 ( struct V_79 * V_35 ,
struct V_83 * V_84 )
{
struct V_70 * V_45 = V_84 -> V_45 ;
struct V_93 * V_126 = F_106 ( V_45 ) ;
return V_126 -> V_105 ( V_84 , V_35 -> V_127 ) ;
}
struct V_70 * F_107 ( struct V_120 * V_45 )
{
struct V_68 * V_69 = F_56 ( & V_45 -> V_81 ) ;
return V_69 -> V_72 ;
}
struct V_83 * F_108 ( struct V_79 * V_35 )
{
struct V_27 * V_28 = F_64 ( V_35 ) ;
return & V_28 -> V_84 ;
}
void F_109 ( struct V_120 * V_45 )
{
F_104 ( & V_45 -> V_81 ) ;
}
static int T_4 F_110 ( void )
{
int V_29 , V_18 ;
struct V_4 * V_5 ;
V_7 = F_9 ( struct V_4 ) ;
F_11 (cpu) {
V_5 = F_2 ( V_7 , V_18 ) ;
F_111 ( & V_5 -> V_10 ) ;
F_112 ( & V_5 -> V_8 ) ;
}
V_29 = F_8 ( & V_116 , V_128 ) ;
if ( V_29 ) {
F_16 ( V_7 ) ;
return V_29 ;
}
V_29 = F_113 ( & V_129 ) ;
if ( V_29 ) {
F_14 ( & V_116 ) ;
F_16 ( V_7 ) ;
}
return V_29 ;
}
static void T_5 F_114 ( void )
{
F_14 ( & V_116 ) ;
F_115 ( & V_129 ) ;
F_16 ( V_7 ) ;
}
