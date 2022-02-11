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
V_2 = F_25 ( & V_5 -> V_10 ,
struct V_1 , V_9 ) ;
if ( ! V_2 || ! V_2 -> V_6 ) {
F_7 ( & V_5 -> V_8 ) ;
return;
}
F_26 ( & V_2 -> V_9 ) ;
V_2 -> V_6 = false ;
F_7 ( & V_5 -> V_8 ) ;
V_2 -> V_31 -> V_32 ( V_2 ) ;
}
}
static void V_23 ( struct V_33 * V_22 )
{
struct V_19 * V_20 ;
struct V_25 * V_34 , * V_35 ;
int V_36 ;
V_20 = F_27 ( V_22 , struct V_19 , V_22 ) ;
V_36 = 0 ;
while ( V_36 < V_37 || F_24 () ) {
F_28 () ;
F_29 () ;
V_35 = F_30 ( & V_20 -> V_16 ) ;
V_34 = F_31 ( & V_20 -> V_16 ) ;
F_32 () ;
F_33 () ;
if ( ! V_34 ) {
F_23 () ;
return;
}
if ( V_35 )
V_35 -> V_38 ( V_35 , - V_39 ) ;
V_34 -> V_38 ( V_34 , 0 ) ;
if ( ! V_20 -> V_16 . V_24 )
return;
++ V_36 ;
}
if ( V_20 -> V_16 . V_24 )
F_34 ( V_13 , & V_20 -> V_22 ) ;
}
void F_35 ( struct V_33 * V_40 )
{
struct V_1 * V_41 ;
struct V_42 * V_31 ;
struct V_4 * V_5 ;
int V_18 ;
V_18 = F_3 () ;
V_41 = F_27 ( F_36 ( V_40 ) ,
struct V_1 , V_14 ) ;
V_31 = V_41 -> V_31 ;
if ( V_41 -> V_18 != V_18 )
F_10 ( L_4 ,
V_18 , V_41 -> V_18 ) ;
if ( V_41 -> V_6 ) {
V_5 = F_2 ( V_7 , V_18 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_26 ( & V_41 -> V_9 ) ;
V_41 -> V_6 = false ;
F_7 ( & V_5 -> V_8 ) ;
V_31 -> V_32 ( V_41 ) ;
}
}
static inline struct V_15 * F_37 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_38 ( V_44 ) ;
struct V_47 * V_48 = F_39 ( V_46 ) ;
return V_48 -> V_16 ;
}
static void * F_40 ( struct V_49 * V_50 , unsigned int V_51 ,
unsigned int V_52 )
{
char * V_53 ;
struct V_45 * V_46 ;
int V_29 ;
V_53 = F_41 ( V_51 + sizeof( * V_46 ) + V_52 , V_54 ) ;
if ( ! V_53 )
return F_42 ( - V_21 ) ;
V_46 = ( void * ) ( V_53 + V_51 ) ;
V_29 = - V_55 ;
if ( snprintf ( V_46 -> V_50 . V_56 , V_57 ,
L_5 , V_50 -> V_56 ) >= V_57 )
goto V_58;
memcpy ( V_46 -> V_50 . V_59 , V_50 -> V_59 , V_57 ) ;
V_46 -> V_50 . V_60 = V_50 -> V_60 + 50 ;
V_46 -> V_50 . V_61 = V_50 -> V_61 ;
V_46 -> V_50 . V_62 = V_50 -> V_62 ;
V_63:
return V_53 ;
V_58:
F_43 ( V_53 ) ;
V_53 = F_42 ( V_29 ) ;
goto V_63;
}
static inline bool F_44 ( struct V_64 * * V_65 , T_1 * type ,
T_1 * V_66 )
{
struct V_67 * V_68 ;
V_68 = F_45 ( V_65 ) ;
if ( F_46 ( V_68 ) )
return false ;
* type |= V_68 -> type & V_69 ;
* V_66 |= V_68 -> V_66 & V_69 ;
if ( * type & * V_66 & V_69 )
return true ;
else
return false ;
}
static int F_47 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_38 ( V_44 ) ;
struct V_70 * V_48 = F_39 ( V_46 ) ;
struct V_71 * V_72 = & V_48 -> V_72 ;
struct V_73 * V_74 = F_48 ( V_44 ) ;
struct V_75 * V_76 ;
V_76 = F_49 ( V_72 ) ;
if ( F_46 ( V_76 ) )
return F_50 ( V_76 ) ;
V_74 -> V_77 = V_76 ;
F_51 ( F_52 ( V_44 ) ,
sizeof( struct V_27 ) +
F_53 ( V_76 ) ) ;
return 0 ;
}
static void F_54 ( struct V_43 * V_44 )
{
struct V_73 * V_74 = F_48 ( V_44 ) ;
F_55 ( V_74 -> V_77 ) ;
}
static int F_56 ( struct V_75 * V_78 ,
const T_2 * V_79 , unsigned int V_80 )
{
struct V_73 * V_74 = F_57 ( V_78 ) ;
struct V_75 * V_77 = V_74 -> V_77 ;
int V_29 ;
F_58 ( V_77 , V_81 ) ;
F_59 ( V_77 , F_60 ( V_78 ) &
V_81 ) ;
V_29 = F_61 ( V_77 , V_79 , V_80 ) ;
F_59 ( V_78 , F_60 ( V_77 ) &
V_82 ) ;
return V_29 ;
}
static int F_62 ( struct V_83 * V_34 ,
T_3 V_38 )
{
int V_84 ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
struct V_75 * V_44 = F_64 ( V_34 ) ;
struct V_15 * V_16 =
F_37 ( F_65 ( V_44 ) ) ;
V_28 -> V_38 = V_34 -> V_85 . V_38 ;
V_34 -> V_85 . V_38 = V_38 ;
V_84 = F_17 ( V_16 , & V_34 -> V_85 , V_28 ) ;
return V_84 ;
}
static void F_66 ( struct V_25 * V_86 , int V_29 )
{
struct V_73 * V_74 = F_48 ( V_86 -> V_44 ) ;
struct V_75 * V_77 = V_74 -> V_77 ;
struct V_83 * V_34 = F_67 ( V_86 ) ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
struct V_83 * V_87 = & V_28 -> V_88 ;
if ( F_68 ( V_29 == - V_39 ) )
goto V_63;
F_69 ( V_87 , V_77 ) ;
F_70 ( V_87 , V_89 ,
V_28 -> V_38 , V_86 ) ;
V_28 -> V_63 = V_34 -> V_90 ;
V_29 = F_71 ( V_87 ) ;
V_63:
F_28 () ;
V_28 -> V_38 ( & V_34 -> V_85 , V_29 ) ;
F_33 () ;
}
static int F_72 ( struct V_83 * V_34 )
{
return F_62 ( V_34 , F_66 ) ;
}
static void F_73 ( struct V_25 * V_86 , int V_29 )
{
struct V_83 * V_34 = F_67 ( V_86 ) ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
if ( F_68 ( V_29 == - V_39 ) )
goto V_63;
V_28 -> V_63 = V_34 -> V_90 ;
V_29 = F_74 ( & V_28 -> V_88 ) ;
if ( V_29 ) {
V_34 -> V_85 . V_38 = V_28 -> V_38 ;
goto V_63;
}
return;
V_63:
F_28 () ;
V_28 -> V_38 ( & V_34 -> V_85 , V_29 ) ;
F_33 () ;
}
static int F_75 ( struct V_83 * V_34 )
{
return F_62 ( V_34 , F_73 ) ;
}
static void F_76 ( struct V_25 * V_86 , int V_29 )
{
struct V_83 * V_34 = F_67 ( V_86 ) ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
if ( F_68 ( V_29 == - V_39 ) )
goto V_63;
V_28 -> V_63 = V_34 -> V_90 ;
V_29 = F_77 ( & V_28 -> V_88 ) ;
if ( V_29 ) {
V_34 -> V_85 . V_38 = V_28 -> V_38 ;
goto V_63;
}
return;
V_63:
F_28 () ;
V_28 -> V_38 ( & V_34 -> V_85 , V_29 ) ;
F_33 () ;
}
static int F_78 ( struct V_83 * V_34 )
{
return F_62 ( V_34 , F_76 ) ;
}
static void F_79 ( struct V_25 * V_86 , int V_29 )
{
struct V_83 * V_34 = F_67 ( V_86 ) ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
if ( F_68 ( V_29 == - V_39 ) )
goto V_63;
V_28 -> V_63 = V_34 -> V_90 ;
V_29 = F_80 ( & V_28 -> V_88 ) ;
if ( V_29 ) {
V_34 -> V_85 . V_38 = V_28 -> V_38 ;
goto V_63;
}
return;
V_63:
F_28 () ;
V_28 -> V_38 ( & V_34 -> V_85 , V_29 ) ;
F_33 () ;
}
static int F_81 ( struct V_83 * V_34 )
{
return F_62 ( V_34 , F_79 ) ;
}
static void F_82 ( struct V_25 * V_86 , int V_29 )
{
struct V_73 * V_74 = F_48 ( V_86 -> V_44 ) ;
struct V_75 * V_77 = V_74 -> V_77 ;
struct V_83 * V_34 = F_67 ( V_86 ) ;
struct V_27 * V_28 = F_63 ( V_34 ) ;
struct V_83 * V_87 = & V_28 -> V_88 ;
if ( F_68 ( V_29 == - V_39 ) )
goto V_63;
F_69 ( V_87 , V_77 ) ;
F_70 ( V_87 , V_89 ,
V_28 -> V_38 , V_86 ) ;
V_28 -> V_63 = V_34 -> V_90 ;
V_29 = F_83 ( V_87 ) ;
V_63:
F_28 () ;
V_28 -> V_38 ( & V_34 -> V_85 , V_29 ) ;
F_33 () ;
}
static int F_84 ( struct V_83 * V_34 )
{
return F_62 ( V_34 , F_82 ) ;
}
static int F_85 ( struct V_83 * V_34 , void * V_63 )
{
struct V_27 * V_28 = F_63 ( V_34 ) ;
return F_86 ( & V_28 -> V_88 , V_63 ) ;
}
static int F_87 ( struct V_83 * V_34 , const void * V_91 )
{
struct V_27 * V_28 = F_63 ( V_34 ) ;
return F_88 ( & V_28 -> V_88 , V_91 ) ;
}
static int F_89 ( struct V_92 * V_93 , struct V_64 * * V_65 ,
struct V_15 * V_16 )
{
struct V_70 * V_74 ;
struct V_94 * V_46 ;
struct V_95 * V_96 ;
struct V_49 * V_50 ;
T_1 type = 0 ;
T_1 V_66 = 0 ;
int V_29 ;
if ( ! F_44 ( V_65 , & type , & V_66 ) )
return - V_97 ;
V_96 = F_90 ( V_65 [ 1 ] , type , V_66 ) ;
if ( F_46 ( V_96 ) )
return F_50 ( V_96 ) ;
V_50 = & V_96 -> V_85 ;
F_10 ( L_6 , V_50 -> V_59 ) ;
V_46 = F_40 ( V_50 , F_91 () ,
sizeof( * V_74 ) ) ;
V_29 = F_50 ( V_46 ) ;
if ( F_46 ( V_46 ) )
goto V_98;
V_74 = F_92 ( V_46 ) ;
V_74 -> V_16 = V_16 ;
V_29 = F_93 ( & V_74 -> V_72 , V_96 ,
F_94 ( V_46 ) ) ;
if ( V_29 )
goto V_58;
type = V_99 ;
if ( V_50 -> V_100 & V_69 )
type |= V_69 ;
V_46 -> V_50 . V_96 . V_85 . V_100 = type ;
V_46 -> V_50 . V_96 . V_101 = V_96 -> V_101 ;
V_46 -> V_50 . V_96 . V_102 = V_96 -> V_102 ;
V_46 -> V_50 . V_96 . V_85 . V_103 = sizeof( struct V_73 ) ;
V_46 -> V_50 . V_96 . V_85 . V_104 = F_47 ;
V_46 -> V_50 . V_96 . V_85 . V_105 = F_54 ;
V_46 -> V_50 . V_106 = F_72 ;
V_46 -> V_50 . V_107 = F_75 ;
V_46 -> V_50 . V_108 = F_78 ;
V_46 -> V_50 . V_109 = F_81 ;
V_46 -> V_50 . V_110 = F_85 ;
V_46 -> V_50 . V_111 = F_87 ;
V_46 -> V_50 . V_112 = F_56 ;
V_46 -> V_50 . V_113 = F_84 ;
V_29 = F_95 ( V_93 , V_46 ) ;
if ( V_29 ) {
F_96 ( & V_74 -> V_72 ) ;
V_58:
F_43 ( V_46 ) ;
}
V_98:
F_97 ( V_50 ) ;
return V_29 ;
}
static int F_98 ( struct V_92 * V_93 , struct V_64 * * V_65 )
{
struct V_67 * V_68 ;
V_68 = F_45 ( V_65 ) ;
if ( F_46 ( V_68 ) )
return F_50 ( V_68 ) ;
switch ( V_68 -> type & V_68 -> V_66 & V_114 ) {
case V_115 :
return F_89 ( V_93 , V_65 , & V_116 ) ;
break;
}
return - V_97 ;
}
static void F_99 ( struct V_45 * V_46 )
{
struct V_47 * V_74 = F_39 ( V_46 ) ;
struct V_70 * V_117 = F_39 ( V_46 ) ;
switch ( V_46 -> V_50 . V_100 & V_114 ) {
case V_118 :
F_96 ( & V_117 -> V_72 ) ;
F_43 ( V_94 ( V_46 ) ) ;
return;
default:
F_100 ( & V_74 -> V_72 ) ;
F_43 ( V_46 ) ;
}
}
struct V_119 * F_101 ( const char * V_120 ,
T_1 type , T_1 V_66 )
{
char V_121 [ V_57 ] ;
struct V_75 * V_44 ;
if ( snprintf ( V_121 , V_57 ,
L_5 , V_120 ) >= V_57 )
return F_42 ( - V_97 ) ;
V_44 = F_102 ( V_121 , type , V_66 ) ;
if ( F_46 ( V_44 ) )
return F_103 ( V_44 ) ;
if ( V_44 -> V_85 . V_122 -> V_123 != V_124 ) {
F_55 ( V_44 ) ;
return F_42 ( - V_97 ) ;
}
return F_104 ( V_44 ) ;
}
int F_83 ( struct V_83 * V_87 )
{
return F_71 ( V_87 ) ? : F_80 ( V_87 ) ;
}
int F_74 ( struct V_83 * V_87 )
{
return F_105 ( V_87 ) ;
}
int F_80 ( struct V_83 * V_87 )
{
return F_106 ( V_87 ) ;
}
int F_77 ( struct V_83 * V_87 )
{
return F_107 ( V_87 ) ;
}
struct V_75 * F_108 ( struct V_119 * V_44 )
{
struct V_73 * V_74 = F_57 ( & V_44 -> V_85 ) ;
return V_74 -> V_77 ;
}
struct V_83 * F_109 ( struct V_83 * V_34 )
{
struct V_27 * V_28 = F_63 ( V_34 ) ;
return & V_28 -> V_88 ;
}
void F_110 ( struct V_119 * V_44 )
{
F_55 ( & V_44 -> V_85 ) ;
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
V_29 = F_8 ( & V_116 , V_125 ) ;
if ( V_29 ) {
F_16 ( V_7 ) ;
return V_29 ;
}
V_29 = F_114 ( & V_126 ) ;
if ( V_29 ) {
F_14 ( & V_116 ) ;
F_16 ( V_7 ) ;
}
return V_29 ;
}
static void T_5 F_115 ( void )
{
F_14 ( & V_116 ) ;
F_116 ( & V_126 ) ;
F_16 ( V_7 ) ;
}
