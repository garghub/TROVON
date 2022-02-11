static struct V_1 * F_1 ( union V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_5 >= F_2 ( V_6 ) ||
! V_6 [ V_3 -> V_5 ] )
return F_3 ( - V_7 ) ;
V_4 = V_6 [ V_3 -> V_5 ] -> F_4 ( V_3 ) ;
if ( F_5 ( V_4 ) )
return V_4 ;
V_4 -> V_8 = V_6 [ V_3 -> V_5 ] ;
V_4 -> V_5 = V_3 -> V_5 ;
return V_4 ;
}
void * F_6 ( T_1 V_9 )
{
const T_2 V_10 = V_11 | V_12 | V_13 ;
void * V_14 ;
if ( V_9 <= ( V_15 << V_16 ) ) {
V_14 = F_7 ( V_9 , V_17 | V_10 ) ;
if ( V_14 != NULL )
return V_14 ;
}
return F_8 ( V_9 , V_18 | V_10 , V_19 ) ;
}
void F_9 ( void * V_14 )
{
F_10 ( V_14 ) ;
}
int F_11 ( T_3 V_20 )
{
struct V_21 * V_22 = F_12 () ;
unsigned long V_23 , V_24 ;
V_23 = F_13 ( V_25 ) >> V_26 ;
V_24 = F_14 ( & V_22 -> V_27 ) ;
F_15 ( V_22 ) ;
if ( V_24 + V_20 > V_23 )
return - V_28 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_4 )
{
struct V_21 * V_22 = F_12 () ;
unsigned long V_23 ;
V_23 = F_13 ( V_25 ) >> V_26 ;
F_17 ( V_4 -> V_20 , & V_22 -> V_27 ) ;
if ( F_14 ( & V_22 -> V_27 ) > V_23 ) {
F_18 ( V_4 -> V_20 , & V_22 -> V_27 ) ;
F_15 ( V_22 ) ;
return - V_28 ;
}
V_4 -> V_22 = V_22 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_22 ;
F_18 ( V_4 -> V_20 , & V_22 -> V_27 ) ;
F_15 ( V_22 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_1 * V_4 = F_21 ( V_30 , struct V_1 , V_30 ) ;
F_19 ( V_4 ) ;
V_4 -> V_8 -> V_31 ( V_4 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
if ( F_23 ( & V_4 -> V_32 ) ) {
if ( V_4 -> V_5 == V_33 )
F_24 ( V_4 ) ;
}
}
void F_25 ( struct V_1 * V_4 )
{
if ( F_23 ( & V_4 -> V_34 ) ) {
F_26 ( & V_4 -> V_30 , F_20 ) ;
F_27 ( & V_4 -> V_30 ) ;
}
}
void F_28 ( struct V_1 * V_4 )
{
F_22 ( V_4 ) ;
F_25 ( V_4 ) ;
}
static int F_29 ( struct V_35 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_4 = V_37 -> V_38 ;
if ( V_4 -> V_8 -> V_39 )
V_4 -> V_8 -> V_39 ( V_4 , V_37 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static void F_30 ( struct V_40 * V_41 , struct V_36 * V_37 )
{
const struct V_1 * V_4 = V_37 -> V_38 ;
const struct V_42 * V_43 ;
T_3 V_44 = 0 ;
if ( V_4 -> V_5 == V_33 ) {
V_43 = F_21 ( V_4 , struct V_42 , V_4 ) ;
V_44 = V_43 -> V_44 ;
}
F_31 ( V_41 ,
L_1
L_2
L_3
L_4
L_5
L_6 ,
V_4 -> V_5 ,
V_4 -> V_45 ,
V_4 -> V_46 ,
V_4 -> V_47 ,
V_4 -> V_48 ,
V_4 -> V_20 * 1ULL << V_26 ) ;
if ( V_44 )
F_31 ( V_41 , L_7 ,
V_44 ) ;
}
int F_32 ( struct V_1 * V_4 )
{
return F_33 ( L_8 , & V_49 , V_4 ,
V_50 | V_51 ) ;
}
static int F_34 ( union V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_52 ;
V_52 = F_35 ( V_53 ) ;
if ( V_52 )
return - V_7 ;
V_4 = F_1 ( V_3 ) ;
if ( F_5 ( V_4 ) )
return F_36 ( V_4 ) ;
F_37 ( & V_4 -> V_34 , 1 ) ;
F_37 ( & V_4 -> V_32 , 1 ) ;
V_52 = F_16 ( V_4 ) ;
if ( V_52 )
goto V_54;
V_52 = F_32 ( V_4 ) ;
if ( V_52 < 0 )
goto V_55;
F_38 ( V_4 , V_52 ) ;
return V_52 ;
V_55:
F_19 ( V_4 ) ;
V_54:
V_4 -> V_8 -> V_31 ( V_4 ) ;
return V_52 ;
}
struct V_1 * F_39 ( struct V_56 V_57 )
{
if ( ! V_57 . V_36 )
return F_3 ( - V_58 ) ;
if ( V_57 . V_36 -> V_59 != & V_49 ) {
F_40 ( V_57 ) ;
return F_3 ( - V_7 ) ;
}
return V_57 . V_36 -> V_38 ;
}
struct V_1 * F_41 ( struct V_1 * V_4 , bool V_60 )
{
if ( F_42 ( & V_4 -> V_34 ) > V_61 ) {
F_43 ( & V_4 -> V_34 ) ;
return F_3 ( - V_62 ) ;
}
if ( V_60 )
F_44 ( & V_4 -> V_32 ) ;
return V_4 ;
}
struct V_1 * F_45 ( T_3 V_63 )
{
struct V_56 V_57 = F_46 ( V_63 ) ;
struct V_1 * V_4 ;
V_4 = F_39 ( V_57 ) ;
if ( F_5 ( V_4 ) )
return V_4 ;
V_4 = F_41 ( V_4 , true ) ;
F_40 ( V_57 ) ;
return V_4 ;
}
int __weak F_47 ( struct V_1 * V_4 , void * V_64 , void * V_65 )
{
return - V_66 ;
}
static int F_48 ( union V_2 * V_3 )
{
void T_4 * V_67 = F_49 ( V_3 -> V_64 ) ;
void T_4 * V_68 = F_49 ( V_3 -> V_65 ) ;
int V_63 = V_3 -> V_69 ;
struct V_1 * V_4 ;
void * V_64 , * V_65 , * V_70 ;
T_3 V_46 ;
struct V_56 V_57 ;
int V_52 ;
if ( F_35 ( V_71 ) )
return - V_7 ;
V_57 = F_46 ( V_63 ) ;
V_4 = F_39 ( V_57 ) ;
if ( F_5 ( V_4 ) )
return F_36 ( V_4 ) ;
V_52 = - V_72 ;
V_64 = F_7 ( V_4 -> V_45 , V_17 ) ;
if ( ! V_64 )
goto V_73;
V_52 = - V_74 ;
if ( F_50 ( V_64 , V_67 , V_4 -> V_45 ) != 0 )
goto V_75;
if ( V_4 -> V_5 == V_76 ||
V_4 -> V_5 == V_77 ||
V_4 -> V_5 == V_78 )
V_46 = F_51 ( V_4 -> V_46 , 8 ) * F_52 () ;
else
V_46 = V_4 -> V_46 ;
V_52 = - V_72 ;
V_65 = F_7 ( V_46 , V_17 | V_11 ) ;
if ( ! V_65 )
goto V_75;
if ( V_4 -> V_5 == V_76 ||
V_4 -> V_5 == V_77 ) {
V_52 = F_53 ( V_4 , V_64 , V_65 ) ;
} else if ( V_4 -> V_5 == V_78 ) {
V_52 = F_54 ( V_4 , V_64 , V_65 ) ;
} else if ( V_4 -> V_5 == V_79 ) {
V_52 = F_47 ( V_4 , V_64 , V_65 ) ;
} else if ( V_4 -> V_5 == V_80 ||
V_4 -> V_5 == V_81 ) {
V_52 = - V_66 ;
} else {
F_55 () ;
V_70 = V_4 -> V_8 -> F_48 ( V_4 , V_64 ) ;
if ( V_70 )
memcpy ( V_65 , V_70 , V_46 ) ;
F_56 () ;
V_52 = V_70 ? 0 : - V_82 ;
}
if ( V_52 )
goto V_83;
V_52 = - V_74 ;
if ( F_57 ( V_68 , V_65 , V_46 ) != 0 )
goto V_83;
F_58 ( V_4 , V_63 , V_64 , V_65 ) ;
V_52 = 0 ;
V_83:
F_59 ( V_65 ) ;
V_75:
F_59 ( V_64 ) ;
V_73:
F_40 ( V_57 ) ;
return V_52 ;
}
static int F_60 ( union V_2 * V_3 )
{
void T_4 * V_67 = F_49 ( V_3 -> V_64 ) ;
void T_4 * V_68 = F_49 ( V_3 -> V_65 ) ;
int V_63 = V_3 -> V_69 ;
struct V_1 * V_4 ;
void * V_64 , * V_65 ;
T_3 V_46 ;
struct V_56 V_57 ;
int V_52 ;
if ( F_35 ( V_84 ) )
return - V_7 ;
V_57 = F_46 ( V_63 ) ;
V_4 = F_39 ( V_57 ) ;
if ( F_5 ( V_4 ) )
return F_36 ( V_4 ) ;
V_52 = - V_72 ;
V_64 = F_7 ( V_4 -> V_45 , V_17 ) ;
if ( ! V_64 )
goto V_73;
V_52 = - V_74 ;
if ( F_50 ( V_64 , V_67 , V_4 -> V_45 ) != 0 )
goto V_75;
if ( V_4 -> V_5 == V_76 ||
V_4 -> V_5 == V_77 ||
V_4 -> V_5 == V_78 )
V_46 = F_51 ( V_4 -> V_46 , 8 ) * F_52 () ;
else
V_46 = V_4 -> V_46 ;
V_52 = - V_72 ;
V_65 = F_7 ( V_46 , V_17 | V_11 ) ;
if ( ! V_65 )
goto V_75;
V_52 = - V_74 ;
if ( F_50 ( V_65 , V_68 , V_46 ) != 0 )
goto V_83;
F_61 () ;
F_62 ( V_85 ) ;
if ( V_4 -> V_5 == V_76 ||
V_4 -> V_5 == V_77 ) {
V_52 = F_63 ( V_4 , V_64 , V_65 , V_3 -> V_10 ) ;
} else if ( V_4 -> V_5 == V_78 ) {
V_52 = F_64 ( V_4 , V_64 , V_65 , V_3 -> V_10 ) ;
} else if ( V_4 -> V_5 == V_86 ||
V_4 -> V_5 == V_33 ||
V_4 -> V_5 == V_87 ||
V_4 -> V_5 == V_80 ) {
F_55 () ;
V_52 = F_65 ( V_4 , V_57 . V_36 , V_64 , V_65 ,
V_3 -> V_10 ) ;
F_56 () ;
} else if ( V_4 -> V_5 == V_81 ) {
F_55 () ;
V_52 = F_66 ( V_4 , V_57 . V_36 , V_64 , V_65 ,
V_3 -> V_10 ) ;
F_56 () ;
} else {
F_55 () ;
V_52 = V_4 -> V_8 -> F_60 ( V_4 , V_64 , V_65 , V_3 -> V_10 ) ;
F_56 () ;
}
F_67 ( V_85 ) ;
F_68 () ;
if ( ! V_52 )
F_69 ( V_4 , V_63 , V_64 , V_65 ) ;
V_83:
F_59 ( V_65 ) ;
V_75:
F_59 ( V_64 ) ;
V_73:
F_40 ( V_57 ) ;
return V_52 ;
}
static int F_70 ( union V_2 * V_3 )
{
void T_4 * V_67 = F_49 ( V_3 -> V_64 ) ;
int V_63 = V_3 -> V_69 ;
struct V_1 * V_4 ;
struct V_56 V_57 ;
void * V_64 ;
int V_52 ;
if ( F_35 ( V_88 ) )
return - V_7 ;
V_57 = F_46 ( V_63 ) ;
V_4 = F_39 ( V_57 ) ;
if ( F_5 ( V_4 ) )
return F_36 ( V_4 ) ;
V_52 = - V_72 ;
V_64 = F_7 ( V_4 -> V_45 , V_17 ) ;
if ( ! V_64 )
goto V_73;
V_52 = - V_74 ;
if ( F_50 ( V_64 , V_67 , V_4 -> V_45 ) != 0 )
goto V_75;
F_61 () ;
F_62 ( V_85 ) ;
F_55 () ;
V_52 = V_4 -> V_8 -> F_70 ( V_4 , V_64 ) ;
F_56 () ;
F_67 ( V_85 ) ;
F_68 () ;
if ( ! V_52 )
F_71 ( V_4 , V_63 , V_64 ) ;
V_75:
F_59 ( V_64 ) ;
V_73:
F_40 ( V_57 ) ;
return V_52 ;
}
static int F_72 ( union V_2 * V_3 )
{
void T_4 * V_67 = F_49 ( V_3 -> V_64 ) ;
void T_4 * V_89 = F_49 ( V_3 -> V_90 ) ;
int V_63 = V_3 -> V_69 ;
struct V_1 * V_4 ;
void * V_64 , * V_90 ;
struct V_56 V_57 ;
int V_52 ;
if ( F_35 ( V_91 ) )
return - V_7 ;
V_57 = F_46 ( V_63 ) ;
V_4 = F_39 ( V_57 ) ;
if ( F_5 ( V_4 ) )
return F_36 ( V_4 ) ;
if ( V_67 ) {
V_52 = - V_72 ;
V_64 = F_7 ( V_4 -> V_45 , V_17 ) ;
if ( ! V_64 )
goto V_73;
V_52 = - V_74 ;
if ( F_50 ( V_64 , V_67 , V_4 -> V_45 ) != 0 )
goto V_75;
} else {
V_64 = NULL ;
}
V_52 = - V_72 ;
V_90 = F_7 ( V_4 -> V_45 , V_17 ) ;
if ( ! V_90 )
goto V_75;
F_55 () ;
V_52 = V_4 -> V_8 -> F_72 ( V_4 , V_64 , V_90 ) ;
F_56 () ;
if ( V_52 )
goto V_92;
V_52 = - V_74 ;
if ( F_57 ( V_89 , V_90 , V_4 -> V_45 ) != 0 )
goto V_92;
F_73 ( V_4 , V_63 , V_64 , V_90 ) ;
V_52 = 0 ;
V_92:
F_59 ( V_90 ) ;
V_75:
F_59 ( V_64 ) ;
V_73:
F_40 ( V_57 ) ;
return V_52 ;
}
static int F_74 ( enum V_93 type , struct V_94 * V_95 )
{
if ( type >= F_2 ( V_96 ) || ! V_96 [ type ] )
return - V_7 ;
V_95 -> V_97 -> V_8 = V_96 [ type ] ;
V_95 -> type = type ;
return 0 ;
}
static void F_75 ( struct V_98 * V_97 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_97 -> V_100 ; V_99 ++ )
F_25 ( V_97 -> V_101 [ V_99 ] ) ;
F_59 ( V_97 -> V_101 ) ;
}
int F_76 ( struct V_21 * V_22 , T_3 V_20 )
{
unsigned long V_23 = F_13 ( V_25 ) >> V_26 ;
unsigned long V_102 ;
if ( V_22 ) {
V_102 = F_77 ( V_20 , & V_22 -> V_27 ) ;
if ( V_102 > V_23 ) {
F_18 ( V_20 , & V_22 -> V_27 ) ;
return - V_28 ;
}
}
return 0 ;
}
void F_78 ( struct V_21 * V_22 , T_3 V_20 )
{
if ( V_22 )
F_18 ( V_20 , & V_22 -> V_27 ) ;
}
static int F_79 ( struct V_94 * V_95 )
{
struct V_21 * V_22 = F_12 () ;
int V_103 ;
V_103 = F_76 ( V_22 , V_95 -> V_20 ) ;
if ( V_103 ) {
F_15 ( V_22 ) ;
return V_103 ;
}
V_95 -> V_97 -> V_22 = V_22 ;
return 0 ;
}
static void F_80 ( struct V_94 * V_95 )
{
struct V_21 * V_22 = V_95 -> V_97 -> V_22 ;
F_78 ( V_22 , V_95 -> V_20 ) ;
F_15 ( V_22 ) ;
}
static void F_81 ( struct V_104 * V_105 )
{
struct V_98 * V_97 = F_21 ( V_105 , struct V_98 , V_105 ) ;
F_75 ( V_97 ) ;
F_80 ( V_97 -> V_95 ) ;
F_82 ( V_97 -> V_95 ) ;
}
void F_83 ( struct V_94 * V_95 )
{
if ( F_23 ( & V_95 -> V_97 -> V_34 ) ) {
F_84 ( V_95 ) ;
F_85 ( V_95 ) ;
F_86 ( & V_95 -> V_97 -> V_105 , F_81 ) ;
}
}
static int F_87 ( struct V_35 * V_35 , struct V_36 * V_37 )
{
struct V_94 * V_95 = V_37 -> V_38 ;
F_83 ( V_95 ) ;
return 0 ;
}
static void F_88 ( struct V_40 * V_41 , struct V_36 * V_37 )
{
const struct V_94 * V_95 = V_37 -> V_38 ;
char V_106 [ sizeof( V_95 -> V_107 ) * 2 + 1 ] = { } ;
F_89 ( V_106 , V_95 -> V_107 , sizeof( V_95 -> V_107 ) ) ;
F_31 ( V_41 ,
L_9
L_10
L_11
L_6 ,
V_95 -> type ,
V_95 -> V_108 ,
V_106 ,
V_95 -> V_20 * 1ULL << V_26 ) ;
}
int F_90 ( struct V_94 * V_95 )
{
return F_33 ( L_12 , & V_109 , V_95 ,
V_50 | V_51 ) ;
}
static struct V_94 * F_91 ( struct V_56 V_57 )
{
if ( ! V_57 . V_36 )
return F_3 ( - V_58 ) ;
if ( V_57 . V_36 -> V_59 != & V_109 ) {
F_40 ( V_57 ) ;
return F_3 ( - V_7 ) ;
}
return V_57 . V_36 -> V_38 ;
}
struct V_94 * F_92 ( struct V_94 * V_95 , int V_99 )
{
if ( F_93 ( V_99 , & V_95 -> V_97 -> V_34 ) > V_61 ) {
F_94 ( V_99 , & V_95 -> V_97 -> V_34 ) ;
return F_3 ( - V_62 ) ;
}
return V_95 ;
}
void F_95 ( struct V_94 * V_95 , int V_99 )
{
F_96 ( F_97 ( V_99 , & V_95 -> V_97 -> V_34 ) == 0 ) ;
}
struct V_94 * F_98 ( struct V_94 * V_95 )
{
return F_92 ( V_95 , 1 ) ;
}
static struct V_94 * F_99 ( T_3 V_63 , enum V_93 * type )
{
struct V_56 V_57 = F_46 ( V_63 ) ;
struct V_94 * V_95 ;
V_95 = F_91 ( V_57 ) ;
if ( F_5 ( V_95 ) )
return V_95 ;
if ( type && V_95 -> type != * type ) {
V_95 = F_3 ( - V_7 ) ;
goto V_110;
}
V_95 = F_98 ( V_95 ) ;
V_110:
F_40 ( V_57 ) ;
return V_95 ;
}
struct V_94 * F_100 ( T_3 V_63 )
{
return F_99 ( V_63 , NULL ) ;
}
struct V_94 * F_101 ( T_3 V_63 , enum V_93 type )
{
struct V_94 * V_95 = F_99 ( V_63 , & type ) ;
if ( ! F_5 ( V_95 ) )
F_102 ( V_95 ) ;
return V_95 ;
}
static int F_103 ( union V_2 * V_3 )
{
enum V_93 type = V_3 -> V_111 ;
struct V_94 * V_95 ;
int V_52 ;
char V_112 [ 128 ] ;
bool V_113 ;
if ( F_35 ( V_114 ) )
return - V_7 ;
if ( V_3 -> V_115 & ~ V_116 )
return - V_7 ;
if ( F_104 ( V_112 , F_49 ( V_3 -> V_112 ) ,
sizeof( V_112 ) - 1 ) < 0 )
return - V_74 ;
V_112 [ sizeof( V_112 ) - 1 ] = 0 ;
V_113 = F_105 ( V_112 ) ;
if ( V_3 -> V_117 == 0 || V_3 -> V_117 > V_118 )
return - V_119 ;
if ( type == V_120 &&
V_3 -> V_121 != V_122 )
return - V_7 ;
if ( type != V_123 && ! F_106 ( V_124 ) )
return - V_28 ;
V_95 = F_107 ( F_108 ( V_3 -> V_117 ) , V_17 ) ;
if ( ! V_95 )
return - V_72 ;
V_52 = F_79 ( V_95 ) ;
if ( V_52 )
goto V_125;
V_95 -> V_126 = V_3 -> V_117 ;
V_52 = - V_74 ;
if ( F_50 ( V_95 -> V_127 , F_49 ( V_3 -> V_127 ) ,
F_109 ( V_95 ) ) != 0 )
goto V_128;
V_95 -> V_129 = NULL ;
V_95 -> V_108 = 0 ;
F_37 ( & V_95 -> V_97 -> V_34 , 1 ) ;
V_95 -> V_130 = V_113 ? 1 : 0 ;
V_52 = F_74 ( type , V_95 ) ;
if ( V_52 < 0 )
goto V_128;
V_52 = F_110 ( & V_95 , V_3 ) ;
if ( V_52 < 0 )
goto F_75;
V_95 = F_111 ( V_95 , & V_52 ) ;
if ( V_52 < 0 )
goto F_75;
V_52 = F_90 ( V_95 ) ;
if ( V_52 < 0 )
goto F_75;
F_112 ( V_95 ) ;
F_113 ( V_95 , V_52 ) ;
return V_52 ;
F_75:
F_75 ( V_95 -> V_97 ) ;
V_128:
F_80 ( V_95 ) ;
V_125:
F_82 ( V_95 ) ;
return V_52 ;
}
static int F_114 ( const union V_2 * V_3 )
{
if ( F_35 ( V_131 ) )
return - V_7 ;
return F_115 ( V_3 -> V_132 , F_49 ( V_3 -> V_133 ) ) ;
}
static int F_116 ( const union V_2 * V_3 )
{
if ( F_35 ( V_131 ) || V_3 -> V_132 != 0 )
return - V_7 ;
return F_117 ( F_49 ( V_3 -> V_133 ) ) ;
}
static int F_118 ( const union V_2 * V_3 )
{
enum V_93 V_134 ;
struct V_94 * V_95 ;
struct V_135 * V_136 ;
int V_103 ;
if ( ! F_106 ( V_137 ) )
return - V_28 ;
if ( F_35 ( V_138 ) )
return - V_7 ;
if ( V_3 -> V_139 & ~ V_140 )
return - V_7 ;
switch ( V_3 -> V_141 ) {
case V_142 :
case V_143 :
V_134 = V_144 ;
break;
case V_145 :
V_134 = V_146 ;
break;
default:
return - V_7 ;
}
V_95 = F_101 ( V_3 -> V_147 , V_134 ) ;
if ( F_5 ( V_95 ) )
return F_36 ( V_95 ) ;
V_136 = F_119 ( V_3 -> V_148 ) ;
if ( F_5 ( V_136 ) ) {
F_83 ( V_95 ) ;
return F_36 ( V_136 ) ;
}
V_103 = F_120 ( V_136 , V_95 , V_3 -> V_141 ,
V_3 -> V_139 & V_140 ) ;
if ( V_103 )
F_83 ( V_95 ) ;
F_121 ( V_136 ) ;
return V_103 ;
}
static int F_122 ( const union V_2 * V_3 )
{
struct V_135 * V_136 ;
int V_103 ;
if ( ! F_106 ( V_137 ) )
return - V_28 ;
if ( F_35 ( V_149 ) )
return - V_7 ;
switch ( V_3 -> V_141 ) {
case V_142 :
case V_143 :
case V_145 :
V_136 = F_119 ( V_3 -> V_148 ) ;
if ( F_5 ( V_136 ) )
return F_36 ( V_136 ) ;
V_103 = F_120 ( V_136 , NULL , V_3 -> V_141 , false ) ;
F_121 ( V_136 ) ;
break;
default:
return - V_7 ;
}
return V_103 ;
}
static int F_123 ( const union V_2 * V_3 ,
union V_2 T_4 * V_150 )
{
struct V_94 * V_95 ;
int V_103 = - V_66 ;
if ( F_35 ( V_151 ) )
return - V_7 ;
V_95 = F_100 ( V_3 -> V_152 . V_153 ) ;
if ( F_5 ( V_95 ) )
return F_36 ( V_95 ) ;
if ( V_95 -> V_97 -> V_8 -> V_154 )
V_103 = V_95 -> V_97 -> V_8 -> V_154 ( V_95 , V_3 , V_150 ) ;
F_83 ( V_95 ) ;
return V_103 ;
}
