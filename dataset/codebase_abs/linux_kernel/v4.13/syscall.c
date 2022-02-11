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
static int F_20 ( struct V_1 * V_4 )
{
int V_29 ;
F_21 ( & V_30 ) ;
V_29 = F_22 ( & V_31 , V_4 , 1 , V_32 , V_33 ) ;
if ( V_29 > 0 )
V_4 -> V_29 = V_29 ;
F_23 ( & V_30 ) ;
if ( F_24 ( ! V_29 ) )
return - V_34 ;
return V_29 > 0 ? 0 : V_29 ;
}
static void F_25 ( struct V_1 * V_4 , bool V_35 )
{
if ( V_35 )
F_21 ( & V_30 ) ;
else
F_26 ( & V_30 ) ;
F_27 ( & V_31 , V_4 -> V_29 ) ;
if ( V_35 )
F_23 ( & V_30 ) ;
else
F_28 ( & V_30 ) ;
}
static void F_29 ( struct V_36 * V_37 )
{
struct V_1 * V_4 = F_30 ( V_37 , struct V_1 , V_37 ) ;
F_19 ( V_4 ) ;
V_4 -> V_8 -> V_38 ( V_4 ) ;
}
static void F_31 ( struct V_1 * V_4 )
{
if ( F_32 ( & V_4 -> V_39 ) ) {
if ( V_4 -> V_5 == V_40 )
F_33 ( V_4 ) ;
}
}
static void F_34 ( struct V_1 * V_4 , bool V_35 )
{
if ( F_32 ( & V_4 -> V_41 ) ) {
F_25 ( V_4 , V_35 ) ;
F_35 ( & V_4 -> V_37 , F_29 ) ;
F_36 ( & V_4 -> V_37 ) ;
}
}
void F_37 ( struct V_1 * V_4 )
{
F_34 ( V_4 , true ) ;
}
void F_38 ( struct V_1 * V_4 )
{
F_31 ( V_4 ) ;
F_37 ( V_4 ) ;
}
static int F_39 ( struct V_42 * V_42 , struct V_43 * V_44 )
{
struct V_1 * V_4 = V_44 -> V_45 ;
if ( V_4 -> V_8 -> V_46 )
V_4 -> V_8 -> V_46 ( V_4 , V_44 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static void F_40 ( struct V_47 * V_48 , struct V_43 * V_44 )
{
const struct V_1 * V_4 = V_44 -> V_45 ;
const struct V_49 * V_50 ;
T_3 V_51 = 0 ;
T_3 V_52 = 0 ;
if ( V_4 -> V_5 == V_40 ) {
V_50 = F_30 ( V_4 , struct V_49 , V_4 ) ;
V_51 = V_50 -> V_51 ;
V_52 = V_50 -> V_52 ;
}
F_41 ( V_48 ,
L_1
L_2
L_3
L_4
L_5
L_6 ,
V_4 -> V_5 ,
V_4 -> V_53 ,
V_4 -> V_54 ,
V_4 -> V_55 ,
V_4 -> V_56 ,
V_4 -> V_20 * 1ULL << V_26 ) ;
if ( V_51 ) {
F_41 ( V_48 , L_7 ,
V_51 ) ;
F_41 ( V_48 , L_8 ,
V_52 ) ;
}
}
int F_42 ( struct V_1 * V_4 )
{
return F_43 ( L_9 , & V_57 , V_4 ,
V_58 | V_59 ) ;
}
static int F_44 ( union V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_60 ;
V_60 = F_45 ( V_61 ) ;
if ( V_60 )
return - V_7 ;
V_4 = F_1 ( V_3 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
F_47 ( & V_4 -> V_41 , 1 ) ;
F_47 ( & V_4 -> V_39 , 1 ) ;
V_60 = F_16 ( V_4 ) ;
if ( V_60 )
goto V_62;
V_60 = F_20 ( V_4 ) ;
if ( V_60 )
goto V_63;
V_60 = F_42 ( V_4 ) ;
if ( V_60 < 0 ) {
F_37 ( V_4 ) ;
return V_60 ;
}
F_48 ( V_4 , V_60 ) ;
return V_60 ;
V_63:
F_19 ( V_4 ) ;
V_62:
V_4 -> V_8 -> V_38 ( V_4 ) ;
return V_60 ;
}
struct V_1 * F_49 ( struct V_64 V_65 )
{
if ( ! V_65 . V_43 )
return F_3 ( - V_66 ) ;
if ( V_65 . V_43 -> V_67 != & V_57 ) {
F_50 ( V_65 ) ;
return F_3 ( - V_7 ) ;
}
return V_65 . V_43 -> V_45 ;
}
struct V_1 * F_51 ( struct V_1 * V_4 , bool V_68 )
{
if ( F_52 ( & V_4 -> V_41 ) > V_69 ) {
F_53 ( & V_4 -> V_41 ) ;
return F_3 ( - V_70 ) ;
}
if ( V_68 )
F_54 ( & V_4 -> V_39 ) ;
return V_4 ;
}
struct V_1 * F_55 ( T_3 V_71 )
{
struct V_64 V_65 = F_56 ( V_71 ) ;
struct V_1 * V_4 ;
V_4 = F_49 ( V_65 ) ;
if ( F_5 ( V_4 ) )
return V_4 ;
V_4 = F_51 ( V_4 , true ) ;
F_50 ( V_65 ) ;
return V_4 ;
}
static struct V_1 * F_57 ( struct V_1 * V_4 ,
bool V_68 )
{
int V_72 ;
V_72 = F_58 ( & V_4 -> V_41 , 1 , 0 ) ;
if ( V_72 >= V_69 ) {
F_34 ( V_4 , false ) ;
return F_3 ( - V_70 ) ;
}
if ( ! V_72 )
return F_3 ( - V_73 ) ;
if ( V_68 )
F_54 ( & V_4 -> V_39 ) ;
return V_4 ;
}
int __weak F_59 ( struct V_1 * V_4 , void * V_74 , void * V_75 )
{
return - V_76 ;
}
static int F_60 ( union V_2 * V_3 )
{
void T_4 * V_77 = F_61 ( V_3 -> V_74 ) ;
void T_4 * V_78 = F_61 ( V_3 -> V_75 ) ;
int V_71 = V_3 -> V_79 ;
struct V_1 * V_4 ;
void * V_74 , * V_75 , * V_80 ;
T_3 V_54 ;
struct V_64 V_65 ;
int V_60 ;
if ( F_45 ( V_81 ) )
return - V_7 ;
V_65 = F_56 ( V_71 ) ;
V_4 = F_49 ( V_65 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
V_74 = F_62 ( V_77 , V_4 -> V_53 ) ;
if ( F_5 ( V_74 ) ) {
V_60 = F_46 ( V_74 ) ;
goto V_82;
}
if ( V_4 -> V_5 == V_83 ||
V_4 -> V_5 == V_84 ||
V_4 -> V_5 == V_85 )
V_54 = F_63 ( V_4 -> V_54 , 8 ) * F_64 () ;
else if ( F_65 ( V_4 ) )
V_54 = sizeof( T_3 ) ;
else
V_54 = V_4 -> V_54 ;
V_60 = - V_86 ;
V_75 = F_7 ( V_54 , V_17 | V_11 ) ;
if ( ! V_75 )
goto V_87;
if ( V_4 -> V_5 == V_83 ||
V_4 -> V_5 == V_84 ) {
V_60 = F_66 ( V_4 , V_74 , V_75 ) ;
} else if ( V_4 -> V_5 == V_85 ) {
V_60 = F_67 ( V_4 , V_74 , V_75 ) ;
} else if ( V_4 -> V_5 == V_88 ) {
V_60 = F_59 ( V_4 , V_74 , V_75 ) ;
} else if ( F_68 ( V_4 ) ) {
V_60 = F_69 ( V_4 , V_74 , V_75 ) ;
} else if ( F_70 ( V_4 ) ) {
V_60 = F_71 ( V_4 , V_74 , V_75 ) ;
} else {
F_72 () ;
V_80 = V_4 -> V_8 -> F_60 ( V_4 , V_74 ) ;
if ( V_80 )
memcpy ( V_75 , V_80 , V_54 ) ;
F_73 () ;
V_60 = V_80 ? 0 : - V_73 ;
}
if ( V_60 )
goto V_89;
V_60 = - V_90 ;
if ( F_74 ( V_78 , V_75 , V_54 ) != 0 )
goto V_89;
F_75 ( V_4 , V_71 , V_74 , V_75 ) ;
V_60 = 0 ;
V_89:
F_76 ( V_75 ) ;
V_87:
F_76 ( V_74 ) ;
V_82:
F_50 ( V_65 ) ;
return V_60 ;
}
static int F_77 ( union V_2 * V_3 )
{
void T_4 * V_77 = F_61 ( V_3 -> V_74 ) ;
void T_4 * V_78 = F_61 ( V_3 -> V_75 ) ;
int V_71 = V_3 -> V_79 ;
struct V_1 * V_4 ;
void * V_74 , * V_75 ;
T_3 V_54 ;
struct V_64 V_65 ;
int V_60 ;
if ( F_45 ( V_91 ) )
return - V_7 ;
V_65 = F_56 ( V_71 ) ;
V_4 = F_49 ( V_65 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
V_74 = F_62 ( V_77 , V_4 -> V_53 ) ;
if ( F_5 ( V_74 ) ) {
V_60 = F_46 ( V_74 ) ;
goto V_82;
}
if ( V_4 -> V_5 == V_83 ||
V_4 -> V_5 == V_84 ||
V_4 -> V_5 == V_85 )
V_54 = F_63 ( V_4 -> V_54 , 8 ) * F_64 () ;
else
V_54 = V_4 -> V_54 ;
V_60 = - V_86 ;
V_75 = F_7 ( V_54 , V_17 | V_11 ) ;
if ( ! V_75 )
goto V_87;
V_60 = - V_90 ;
if ( F_78 ( V_75 , V_78 , V_54 ) != 0 )
goto V_89;
F_79 () ;
F_80 ( V_92 ) ;
if ( V_4 -> V_5 == V_83 ||
V_4 -> V_5 == V_84 ) {
V_60 = F_81 ( V_4 , V_74 , V_75 , V_3 -> V_10 ) ;
} else if ( V_4 -> V_5 == V_85 ) {
V_60 = F_82 ( V_4 , V_74 , V_75 , V_3 -> V_10 ) ;
} else if ( V_4 -> V_5 == V_93 ||
V_4 -> V_5 == V_40 ||
V_4 -> V_5 == V_94 ||
V_4 -> V_5 == V_95 ) {
F_72 () ;
V_60 = F_83 ( V_4 , V_65 . V_43 , V_74 , V_75 ,
V_3 -> V_10 ) ;
F_73 () ;
} else if ( V_4 -> V_5 == V_96 ) {
F_72 () ;
V_60 = F_84 ( V_4 , V_65 . V_43 , V_74 , V_75 ,
V_3 -> V_10 ) ;
F_73 () ;
} else {
F_72 () ;
V_60 = V_4 -> V_8 -> F_77 ( V_4 , V_74 , V_75 , V_3 -> V_10 ) ;
F_73 () ;
}
F_85 ( V_92 ) ;
F_86 () ;
if ( ! V_60 )
F_87 ( V_4 , V_71 , V_74 , V_75 ) ;
V_89:
F_76 ( V_75 ) ;
V_87:
F_76 ( V_74 ) ;
V_82:
F_50 ( V_65 ) ;
return V_60 ;
}
static int F_88 ( union V_2 * V_3 )
{
void T_4 * V_77 = F_61 ( V_3 -> V_74 ) ;
int V_71 = V_3 -> V_79 ;
struct V_1 * V_4 ;
struct V_64 V_65 ;
void * V_74 ;
int V_60 ;
if ( F_45 ( V_97 ) )
return - V_7 ;
V_65 = F_56 ( V_71 ) ;
V_4 = F_49 ( V_65 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
V_74 = F_62 ( V_77 , V_4 -> V_53 ) ;
if ( F_5 ( V_74 ) ) {
V_60 = F_46 ( V_74 ) ;
goto V_82;
}
F_79 () ;
F_80 ( V_92 ) ;
F_72 () ;
V_60 = V_4 -> V_8 -> F_88 ( V_4 , V_74 ) ;
F_73 () ;
F_85 ( V_92 ) ;
F_86 () ;
if ( ! V_60 )
F_89 ( V_4 , V_71 , V_74 ) ;
F_76 ( V_74 ) ;
V_82:
F_50 ( V_65 ) ;
return V_60 ;
}
static int F_90 ( union V_2 * V_3 )
{
void T_4 * V_77 = F_61 ( V_3 -> V_74 ) ;
void T_4 * V_98 = F_61 ( V_3 -> V_99 ) ;
int V_71 = V_3 -> V_79 ;
struct V_1 * V_4 ;
void * V_74 , * V_99 ;
struct V_64 V_65 ;
int V_60 ;
if ( F_45 ( V_100 ) )
return - V_7 ;
V_65 = F_56 ( V_71 ) ;
V_4 = F_49 ( V_65 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
if ( V_77 ) {
V_74 = F_62 ( V_77 , V_4 -> V_53 ) ;
if ( F_5 ( V_74 ) ) {
V_60 = F_46 ( V_74 ) ;
goto V_82;
}
} else {
V_74 = NULL ;
}
V_60 = - V_86 ;
V_99 = F_7 ( V_4 -> V_53 , V_17 ) ;
if ( ! V_99 )
goto V_87;
F_72 () ;
V_60 = V_4 -> V_8 -> F_90 ( V_4 , V_74 , V_99 ) ;
F_73 () ;
if ( V_60 )
goto V_101;
V_60 = - V_90 ;
if ( F_74 ( V_98 , V_99 , V_4 -> V_53 ) != 0 )
goto V_101;
F_91 ( V_4 , V_71 , V_74 , V_99 ) ;
V_60 = 0 ;
V_101:
F_76 ( V_99 ) ;
V_87:
F_76 ( V_74 ) ;
V_82:
F_50 ( V_65 ) ;
return V_60 ;
}
static int F_92 ( enum V_102 type , struct V_103 * V_104 )
{
if ( type >= F_2 ( V_105 ) || ! V_105 [ type ] )
return - V_7 ;
V_104 -> V_106 -> V_8 = V_105 [ type ] ;
V_104 -> type = type ;
return 0 ;
}
static void F_93 ( struct V_107 * V_106 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_106 -> V_109 ; V_108 ++ )
F_37 ( V_106 -> V_110 [ V_108 ] ) ;
F_76 ( V_106 -> V_110 ) ;
}
int F_94 ( struct V_21 * V_22 , T_3 V_20 )
{
unsigned long V_23 = F_13 ( V_25 ) >> V_26 ;
unsigned long V_111 ;
if ( V_22 ) {
V_111 = F_95 ( V_20 , & V_22 -> V_27 ) ;
if ( V_111 > V_23 ) {
F_18 ( V_20 , & V_22 -> V_27 ) ;
return - V_28 ;
}
}
return 0 ;
}
void F_96 ( struct V_21 * V_22 , T_3 V_20 )
{
if ( V_22 )
F_18 ( V_20 , & V_22 -> V_27 ) ;
}
static int F_97 ( struct V_103 * V_104 )
{
struct V_21 * V_22 = F_12 () ;
int V_112 ;
V_112 = F_94 ( V_22 , V_104 -> V_20 ) ;
if ( V_112 ) {
F_15 ( V_22 ) ;
return V_112 ;
}
V_104 -> V_106 -> V_22 = V_22 ;
return 0 ;
}
static void F_98 ( struct V_103 * V_104 )
{
struct V_21 * V_22 = V_104 -> V_106 -> V_22 ;
F_96 ( V_22 , V_104 -> V_20 ) ;
F_15 ( V_22 ) ;
}
static int F_99 ( struct V_103 * V_104 )
{
int V_29 ;
F_21 ( & V_113 ) ;
V_29 = F_22 ( & V_114 , V_104 , 1 , V_32 , V_33 ) ;
if ( V_29 > 0 )
V_104 -> V_106 -> V_29 = V_29 ;
F_23 ( & V_113 ) ;
if ( F_24 ( ! V_29 ) )
return - V_34 ;
return V_29 > 0 ? 0 : V_29 ;
}
static void F_100 ( struct V_103 * V_104 , bool V_35 )
{
if ( ! V_104 -> V_106 -> V_29 )
return;
if ( V_35 )
F_21 ( & V_113 ) ;
else
F_26 ( & V_113 ) ;
F_27 ( & V_114 , V_104 -> V_106 -> V_29 ) ;
if ( V_35 )
F_23 ( & V_113 ) ;
else
F_28 ( & V_113 ) ;
}
static void F_101 ( struct V_115 * V_116 )
{
struct V_107 * V_106 = F_30 ( V_116 , struct V_107 , V_116 ) ;
F_93 ( V_106 ) ;
F_98 ( V_106 -> V_104 ) ;
F_102 ( V_106 -> V_104 ) ;
}
static void F_103 ( struct V_103 * V_104 , bool V_35 )
{
if ( F_32 ( & V_104 -> V_106 -> V_41 ) ) {
F_104 ( V_104 ) ;
F_100 ( V_104 , V_35 ) ;
F_105 ( V_104 ) ;
F_106 ( & V_104 -> V_106 -> V_116 , F_101 ) ;
}
}
void F_107 ( struct V_103 * V_104 )
{
F_103 ( V_104 , true ) ;
}
static int F_108 ( struct V_42 * V_42 , struct V_43 * V_44 )
{
struct V_103 * V_104 = V_44 -> V_45 ;
F_107 ( V_104 ) ;
return 0 ;
}
static void F_109 ( struct V_47 * V_48 , struct V_43 * V_44 )
{
const struct V_103 * V_104 = V_44 -> V_45 ;
char V_117 [ sizeof( V_104 -> V_118 ) * 2 + 1 ] = { } ;
F_110 ( V_117 , V_104 -> V_118 , sizeof( V_104 -> V_118 ) ) ;
F_41 ( V_48 ,
L_10
L_11
L_12
L_6 ,
V_104 -> type ,
V_104 -> V_119 ,
V_117 ,
V_104 -> V_20 * 1ULL << V_26 ) ;
}
int F_111 ( struct V_103 * V_104 )
{
return F_43 ( L_13 , & V_120 , V_104 ,
V_58 | V_59 ) ;
}
static struct V_103 * F_112 ( struct V_64 V_65 )
{
if ( ! V_65 . V_43 )
return F_3 ( - V_66 ) ;
if ( V_65 . V_43 -> V_67 != & V_120 ) {
F_50 ( V_65 ) ;
return F_3 ( - V_7 ) ;
}
return V_65 . V_43 -> V_45 ;
}
struct V_103 * F_113 ( struct V_103 * V_104 , int V_108 )
{
if ( F_114 ( V_108 , & V_104 -> V_106 -> V_41 ) > V_69 ) {
F_115 ( V_108 , & V_104 -> V_106 -> V_41 ) ;
return F_3 ( - V_70 ) ;
}
return V_104 ;
}
void F_116 ( struct V_103 * V_104 , int V_108 )
{
F_117 ( F_118 ( V_108 , & V_104 -> V_106 -> V_41 ) == 0 ) ;
}
struct V_103 * F_119 ( struct V_103 * V_104 )
{
return F_113 ( V_104 , 1 ) ;
}
static struct V_103 * F_120 ( struct V_103 * V_104 )
{
int V_72 ;
V_72 = F_58 ( & V_104 -> V_106 -> V_41 , 1 , 0 ) ;
if ( V_72 >= V_69 ) {
F_103 ( V_104 , false ) ;
return F_3 ( - V_70 ) ;
}
if ( ! V_72 )
return F_3 ( - V_73 ) ;
return V_104 ;
}
static struct V_103 * F_121 ( T_3 V_71 , enum V_102 * type )
{
struct V_64 V_65 = F_56 ( V_71 ) ;
struct V_103 * V_104 ;
V_104 = F_112 ( V_65 ) ;
if ( F_5 ( V_104 ) )
return V_104 ;
if ( type && V_104 -> type != * type ) {
V_104 = F_3 ( - V_7 ) ;
goto V_121;
}
V_104 = F_119 ( V_104 ) ;
V_121:
F_50 ( V_65 ) ;
return V_104 ;
}
struct V_103 * F_122 ( T_3 V_71 )
{
return F_121 ( V_71 , NULL ) ;
}
struct V_103 * F_123 ( T_3 V_71 , enum V_102 type )
{
struct V_103 * V_104 = F_121 ( V_71 , & type ) ;
if ( ! F_5 ( V_104 ) )
F_124 ( V_104 ) ;
return V_104 ;
}
static int F_125 ( union V_2 * V_3 )
{
enum V_102 type = V_3 -> V_122 ;
struct V_103 * V_104 ;
int V_60 ;
char V_123 [ 128 ] ;
bool V_124 ;
if ( F_45 ( V_125 ) )
return - V_7 ;
if ( V_3 -> V_126 & ~ V_127 )
return - V_7 ;
if ( F_126 ( V_123 , F_61 ( V_3 -> V_123 ) ,
sizeof( V_123 ) - 1 ) < 0 )
return - V_90 ;
V_123 [ sizeof( V_123 ) - 1 ] = 0 ;
V_124 = F_127 ( V_123 ) ;
if ( V_3 -> V_128 == 0 || V_3 -> V_128 > V_129 )
return - V_130 ;
if ( type == V_131 &&
V_3 -> V_132 != V_133 )
return - V_7 ;
if ( type != V_134 &&
type != V_135 &&
! F_128 ( V_136 ) )
return - V_28 ;
V_104 = F_129 ( F_130 ( V_3 -> V_128 ) , V_17 ) ;
if ( ! V_104 )
return - V_86 ;
V_60 = F_97 ( V_104 ) ;
if ( V_60 )
goto V_137;
V_104 -> V_138 = V_3 -> V_128 ;
V_60 = - V_90 ;
if ( F_78 ( V_104 -> V_139 , F_61 ( V_3 -> V_139 ) ,
F_131 ( V_104 ) ) != 0 )
goto V_140;
V_104 -> V_141 = NULL ;
V_104 -> V_119 = 0 ;
F_47 ( & V_104 -> V_106 -> V_41 , 1 ) ;
V_104 -> V_142 = V_124 ? 1 : 0 ;
V_60 = F_92 ( type , V_104 ) ;
if ( V_60 < 0 )
goto V_140;
V_60 = F_132 ( & V_104 , V_3 ) ;
if ( V_60 < 0 )
goto F_93;
V_104 = F_133 ( V_104 , & V_60 ) ;
if ( V_60 < 0 )
goto F_93;
V_60 = F_99 ( V_104 ) ;
if ( V_60 )
goto F_93;
V_60 = F_111 ( V_104 ) ;
if ( V_60 < 0 ) {
F_107 ( V_104 ) ;
return V_60 ;
}
F_134 ( V_104 ) ;
F_135 ( V_104 , V_60 ) ;
return V_60 ;
F_93:
F_93 ( V_104 -> V_106 ) ;
V_140:
F_98 ( V_104 ) ;
V_137:
F_102 ( V_104 ) ;
return V_60 ;
}
static int F_136 ( const union V_2 * V_3 )
{
if ( F_45 ( V_143 ) )
return - V_7 ;
return F_137 ( V_3 -> V_144 , F_61 ( V_3 -> V_145 ) ) ;
}
static int F_138 ( const union V_2 * V_3 )
{
if ( F_45 ( V_143 ) || V_3 -> V_144 != 0 )
return - V_7 ;
return F_139 ( F_61 ( V_3 -> V_145 ) ) ;
}
static int F_140 ( const union V_2 * V_3 )
{
enum V_102 V_146 ;
struct V_103 * V_104 ;
struct V_147 * V_148 ;
int V_112 ;
if ( ! F_128 ( V_149 ) )
return - V_28 ;
if ( F_45 ( V_150 ) )
return - V_7 ;
if ( V_3 -> V_151 & ~ V_152 )
return - V_7 ;
switch ( V_3 -> V_153 ) {
case V_154 :
case V_155 :
V_146 = V_135 ;
break;
case V_156 :
V_146 = V_157 ;
break;
case V_158 :
V_146 = V_159 ;
break;
default:
return - V_7 ;
}
V_104 = F_123 ( V_3 -> V_160 , V_146 ) ;
if ( F_5 ( V_104 ) )
return F_46 ( V_104 ) ;
V_148 = F_141 ( V_3 -> V_161 ) ;
if ( F_5 ( V_148 ) ) {
F_107 ( V_104 ) ;
return F_46 ( V_148 ) ;
}
V_112 = F_142 ( V_148 , V_104 , V_3 -> V_153 ,
V_3 -> V_151 & V_152 ) ;
if ( V_112 )
F_107 ( V_104 ) ;
F_143 ( V_148 ) ;
return V_112 ;
}
static int F_144 ( const union V_2 * V_3 )
{
struct V_147 * V_148 ;
int V_112 ;
if ( ! F_128 ( V_149 ) )
return - V_28 ;
if ( F_45 ( V_162 ) )
return - V_7 ;
switch ( V_3 -> V_153 ) {
case V_154 :
case V_155 :
case V_156 :
case V_158 :
V_148 = F_141 ( V_3 -> V_161 ) ;
if ( F_5 ( V_148 ) )
return F_46 ( V_148 ) ;
V_112 = F_142 ( V_148 , NULL , V_3 -> V_153 , false ) ;
F_143 ( V_148 ) ;
break;
default:
return - V_7 ;
}
return V_112 ;
}
static int F_145 ( const union V_2 * V_3 ,
union V_2 T_4 * V_163 )
{
struct V_103 * V_104 ;
int V_112 = - V_76 ;
if ( F_45 ( V_164 ) )
return - V_7 ;
V_104 = F_122 ( V_3 -> V_165 . V_166 ) ;
if ( F_5 ( V_104 ) )
return F_46 ( V_104 ) ;
if ( V_104 -> V_106 -> V_8 -> V_167 )
V_112 = V_104 -> V_106 -> V_8 -> V_167 ( V_104 , V_3 , V_163 ) ;
F_107 ( V_104 ) ;
return V_112 ;
}
static int F_146 ( const union V_2 * V_3 ,
union V_2 T_4 * V_163 ,
struct V_168 * V_168 ,
T_5 * V_169 )
{
T_3 V_170 = V_3 -> V_171 ;
int V_60 = 0 ;
if ( F_45 ( V_172 ) || V_170 >= V_32 )
return - V_7 ;
if ( ! F_128 ( V_136 ) )
return - V_28 ;
V_170 ++ ;
F_21 ( V_169 ) ;
if ( ! F_147 ( V_168 , & V_170 ) )
V_60 = - V_73 ;
F_23 ( V_169 ) ;
if ( ! V_60 )
V_60 = F_148 ( V_170 , & V_163 -> V_170 ) ;
return V_60 ;
}
static int F_149 ( const union V_2 * V_3 )
{
struct V_103 * V_104 ;
T_3 V_29 = V_3 -> V_173 ;
int V_64 ;
if ( F_45 ( V_174 ) )
return - V_7 ;
if ( ! F_128 ( V_136 ) )
return - V_28 ;
F_21 ( & V_113 ) ;
V_104 = F_150 ( & V_114 , V_29 ) ;
if ( V_104 )
V_104 = F_120 ( V_104 ) ;
else
V_104 = F_3 ( - V_73 ) ;
F_23 ( & V_113 ) ;
if ( F_5 ( V_104 ) )
return F_46 ( V_104 ) ;
V_64 = F_111 ( V_104 ) ;
if ( V_64 < 0 )
F_107 ( V_104 ) ;
return V_64 ;
}
static int F_151 ( const union V_2 * V_3 )
{
struct V_1 * V_4 ;
T_3 V_29 = V_3 -> V_175 ;
int V_64 ;
if ( F_45 ( V_176 ) )
return - V_7 ;
if ( ! F_128 ( V_136 ) )
return - V_28 ;
F_21 ( & V_30 ) ;
V_4 = F_150 ( & V_31 , V_29 ) ;
if ( V_4 )
V_4 = F_57 ( V_4 , true ) ;
else
V_4 = F_3 ( - V_73 ) ;
F_23 ( & V_30 ) ;
if ( F_5 ( V_4 ) )
return F_46 ( V_4 ) ;
V_64 = F_42 ( V_4 ) ;
if ( V_64 < 0 )
F_37 ( V_4 ) ;
return V_64 ;
}
static int F_152 ( void T_4 * V_177 ,
T_1 V_178 ,
T_1 V_179 )
{
unsigned char T_4 * V_180 ;
unsigned char T_4 * V_181 ;
unsigned char V_182 ;
int V_60 ;
if ( V_179 <= V_178 )
return 0 ;
V_180 = V_177 + V_178 ;
V_181 = V_177 + V_179 ;
for (; V_180 < V_181 ; V_180 ++ ) {
V_60 = F_153 ( V_182 , V_180 ) ;
if ( V_60 )
return V_60 ;
if ( V_182 )
return - V_130 ;
}
return 0 ;
}
static int F_154 ( struct V_103 * V_104 ,
const union V_2 * V_3 ,
union V_2 T_4 * V_163 )
{
struct V_183 T_4 * V_184 = F_61 ( V_3 -> V_185 . V_185 ) ;
struct V_183 V_185 = {} ;
T_3 V_186 = V_3 -> V_185 . V_186 ;
char T_4 * V_187 ;
T_3 V_188 ;
int V_60 ;
V_60 = F_152 ( V_184 , sizeof( V_185 ) , V_186 ) ;
if ( V_60 )
return V_60 ;
V_186 = F_155 ( T_3 , sizeof( V_185 ) , V_186 ) ;
if ( F_78 ( & V_185 , V_184 , V_186 ) )
return - V_90 ;
V_185 . type = V_104 -> type ;
V_185 . V_29 = V_104 -> V_106 -> V_29 ;
memcpy ( V_185 . V_118 , V_104 -> V_118 , sizeof( V_104 -> V_118 ) ) ;
if ( ! F_128 ( V_136 ) ) {
V_185 . V_189 = 0 ;
V_185 . V_190 = 0 ;
goto V_191;
}
V_188 = V_185 . V_189 ;
V_185 . V_189 = V_104 -> V_192 ;
if ( V_185 . V_189 && V_188 ) {
V_187 = F_61 ( V_185 . V_193 ) ;
V_188 = F_155 ( T_3 , V_185 . V_189 , V_188 ) ;
if ( F_74 ( V_187 , V_104 -> V_194 , V_188 ) )
return - V_90 ;
}
V_188 = V_185 . V_190 ;
V_185 . V_190 = F_131 ( V_104 ) ;
if ( V_185 . V_190 && V_188 ) {
V_187 = F_61 ( V_185 . V_195 ) ;
V_188 = F_155 ( T_3 , V_185 . V_190 , V_188 ) ;
if ( F_74 ( V_187 , V_104 -> V_196 , V_188 ) )
return - V_90 ;
}
V_191:
if ( F_74 ( V_184 , & V_185 , V_186 ) ||
F_148 ( V_186 , & V_163 -> V_185 . V_186 ) )
return - V_90 ;
return 0 ;
}
static int F_156 ( struct V_1 * V_4 ,
const union V_2 * V_3 ,
union V_2 T_4 * V_163 )
{
struct V_197 T_4 * V_184 = F_61 ( V_3 -> V_185 . V_185 ) ;
struct V_197 V_185 = {} ;
T_3 V_186 = V_3 -> V_185 . V_186 ;
int V_60 ;
V_60 = F_152 ( V_184 , sizeof( V_185 ) , V_186 ) ;
if ( V_60 )
return V_60 ;
V_186 = F_155 ( T_3 , sizeof( V_185 ) , V_186 ) ;
V_185 . type = V_4 -> V_5 ;
V_185 . V_29 = V_4 -> V_29 ;
V_185 . V_53 = V_4 -> V_53 ;
V_185 . V_54 = V_4 -> V_54 ;
V_185 . V_55 = V_4 -> V_55 ;
V_185 . V_56 = V_4 -> V_56 ;
if ( F_74 ( V_184 , & V_185 , V_186 ) ||
F_148 ( V_186 , & V_163 -> V_185 . V_186 ) )
return - V_90 ;
return 0 ;
}
static int F_157 ( const union V_2 * V_3 ,
union V_2 T_4 * V_163 )
{
int V_71 = V_3 -> V_185 . V_144 ;
struct V_64 V_65 ;
int V_60 ;
if ( F_45 ( V_198 ) )
return - V_7 ;
V_65 = F_56 ( V_71 ) ;
if ( ! V_65 . V_43 )
return - V_199 ;
if ( V_65 . V_43 -> V_67 == & V_120 )
V_60 = F_154 ( V_65 . V_43 -> V_45 , V_3 ,
V_163 ) ;
else if ( V_65 . V_43 -> V_67 == & V_57 )
V_60 = F_156 ( V_65 . V_43 -> V_45 , V_3 ,
V_163 ) ;
else
V_60 = - V_7 ;
F_50 ( V_65 ) ;
return V_60 ;
}
