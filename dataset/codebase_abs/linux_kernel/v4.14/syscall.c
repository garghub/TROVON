static int F_1 ( void T_1 * V_1 ,
T_2 V_2 ,
T_2 V_3 )
{
unsigned char T_1 * V_4 ;
unsigned char T_1 * V_5 ;
unsigned char V_6 ;
int V_7 ;
if ( F_2 ( V_3 > V_8 ) )
return - V_9 ;
if ( F_2 ( ! F_3 ( V_10 , V_1 , V_3 ) ) )
return - V_11 ;
if ( V_3 <= V_2 )
return 0 ;
V_4 = V_1 + V_2 ;
V_5 = V_1 + V_3 ;
for (; V_4 < V_5 ; V_4 ++ ) {
V_7 = F_4 ( V_6 , V_4 ) ;
if ( V_7 )
return V_7 ;
if ( V_6 )
return - V_9 ;
}
return 0 ;
}
static struct V_12 * F_5 ( union V_13 * V_14 )
{
struct V_12 * V_15 ;
if ( V_14 -> V_16 >= F_6 ( V_17 ) ||
! V_17 [ V_14 -> V_16 ] )
return F_7 ( - V_18 ) ;
V_15 = V_17 [ V_14 -> V_16 ] -> F_8 ( V_14 ) ;
if ( F_9 ( V_15 ) )
return V_15 ;
V_15 -> V_19 = V_17 [ V_14 -> V_16 ] ;
V_15 -> V_16 = V_14 -> V_16 ;
return V_15 ;
}
void * F_10 ( T_2 V_20 , int V_21 )
{
const T_3 V_22 = V_23 | V_24 | V_25 ;
void * V_26 ;
if ( V_20 <= ( V_8 << V_27 ) ) {
V_26 = F_11 ( V_20 , V_28 | V_22 , V_21 ) ;
if ( V_26 != NULL )
return V_26 ;
}
return F_12 ( V_20 , V_21 , V_29 | V_22 ,
F_13 ( 0 ) ) ;
}
void F_14 ( void * V_26 )
{
F_15 ( V_26 ) ;
}
int F_16 ( T_4 V_30 )
{
struct V_31 * V_32 = F_17 () ;
unsigned long V_33 , V_34 ;
V_33 = F_18 ( V_35 ) >> V_36 ;
V_34 = F_19 ( & V_32 -> V_37 ) ;
F_20 ( V_32 ) ;
if ( V_34 + V_30 > V_33 )
return - V_38 ;
return 0 ;
}
static int F_21 ( struct V_12 * V_15 )
{
struct V_31 * V_32 = F_17 () ;
unsigned long V_33 ;
V_33 = F_18 ( V_35 ) >> V_36 ;
F_22 ( V_15 -> V_30 , & V_32 -> V_37 ) ;
if ( F_19 ( & V_32 -> V_37 ) > V_33 ) {
F_23 ( V_15 -> V_30 , & V_32 -> V_37 ) ;
F_20 ( V_32 ) ;
return - V_38 ;
}
V_15 -> V_32 = V_32 ;
return 0 ;
}
static void F_24 ( struct V_12 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_32 ;
F_23 ( V_15 -> V_30 , & V_32 -> V_37 ) ;
F_20 ( V_32 ) ;
}
static int F_25 ( struct V_12 * V_15 )
{
int V_39 ;
F_26 ( & V_40 ) ;
V_39 = F_27 ( & V_41 , V_15 , 1 , V_42 , V_43 ) ;
if ( V_39 > 0 )
V_15 -> V_39 = V_39 ;
F_28 ( & V_40 ) ;
if ( F_29 ( ! V_39 ) )
return - V_44 ;
return V_39 > 0 ? 0 : V_39 ;
}
static void F_30 ( struct V_12 * V_15 , bool V_45 )
{
unsigned long V_22 ;
if ( V_45 )
F_31 ( & V_40 , V_22 ) ;
else
F_32 ( & V_40 ) ;
F_33 ( & V_41 , V_15 -> V_39 ) ;
if ( V_45 )
F_34 ( & V_40 , V_22 ) ;
else
F_35 ( & V_40 ) ;
}
static void F_36 ( struct V_46 * V_47 )
{
struct V_12 * V_15 = F_37 ( V_47 , struct V_12 , V_47 ) ;
F_24 ( V_15 ) ;
V_15 -> V_19 -> V_48 ( V_15 ) ;
}
static void F_38 ( struct V_12 * V_15 )
{
if ( F_39 ( & V_15 -> V_49 ) ) {
if ( V_15 -> V_16 == V_50 )
F_40 ( V_15 ) ;
}
}
static void F_41 ( struct V_12 * V_15 , bool V_45 )
{
if ( F_39 ( & V_15 -> V_51 ) ) {
F_30 ( V_15 , V_45 ) ;
F_42 ( & V_15 -> V_47 , F_36 ) ;
F_43 ( & V_15 -> V_47 ) ;
}
}
void F_44 ( struct V_12 * V_15 )
{
F_41 ( V_15 , true ) ;
}
void F_45 ( struct V_12 * V_15 )
{
F_38 ( V_15 ) ;
F_44 ( V_15 ) ;
}
static int F_46 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_12 * V_15 = V_54 -> V_55 ;
if ( V_15 -> V_19 -> V_56 )
V_15 -> V_19 -> V_56 ( V_15 , V_54 ) ;
F_45 ( V_15 ) ;
return 0 ;
}
static void F_47 ( struct V_57 * V_58 , struct V_53 * V_54 )
{
const struct V_12 * V_15 = V_54 -> V_55 ;
const struct V_59 * V_60 ;
T_4 V_61 = 0 ;
T_4 V_62 = 0 ;
if ( V_15 -> V_16 == V_50 ) {
V_60 = F_37 ( V_15 , struct V_59 , V_15 ) ;
V_61 = V_60 -> V_61 ;
V_62 = V_60 -> V_62 ;
}
F_48 ( V_58 ,
L_1
L_2
L_3
L_4
L_5
L_6 ,
V_15 -> V_16 ,
V_15 -> V_63 ,
V_15 -> V_64 ,
V_15 -> V_65 ,
V_15 -> V_66 ,
V_15 -> V_30 * 1ULL << V_36 ) ;
if ( V_61 ) {
F_48 ( V_58 , L_7 ,
V_61 ) ;
F_48 ( V_58 , L_8 ,
V_62 ) ;
}
}
int F_49 ( struct V_12 * V_15 )
{
return F_50 ( L_9 , & V_67 , V_15 ,
V_68 | V_69 ) ;
}
static int F_51 ( union V_13 * V_14 )
{
int V_21 = F_52 ( V_14 ) ;
struct V_12 * V_15 ;
int V_7 ;
V_7 = F_53 ( V_70 ) ;
if ( V_7 )
return - V_18 ;
if ( V_21 != V_71 &&
( ( unsigned int ) V_21 >= V_72 ||
! F_54 ( V_21 ) ) )
return - V_18 ;
V_15 = F_5 ( V_14 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
F_56 ( & V_15 -> V_51 , 1 ) ;
F_56 ( & V_15 -> V_49 , 1 ) ;
V_7 = F_21 ( V_15 ) ;
if ( V_7 )
goto V_73;
V_7 = F_25 ( V_15 ) ;
if ( V_7 )
goto V_74;
V_7 = F_49 ( V_15 ) ;
if ( V_7 < 0 ) {
F_44 ( V_15 ) ;
return V_7 ;
}
F_57 ( V_15 , V_7 ) ;
return V_7 ;
V_74:
F_24 ( V_15 ) ;
V_73:
V_15 -> V_19 -> V_48 ( V_15 ) ;
return V_7 ;
}
struct V_12 * F_58 ( struct V_75 V_76 )
{
if ( ! V_76 . V_53 )
return F_7 ( - V_77 ) ;
if ( V_76 . V_53 -> V_78 != & V_67 ) {
F_59 ( V_76 ) ;
return F_7 ( - V_18 ) ;
}
return V_76 . V_53 -> V_55 ;
}
struct V_12 * F_60 ( struct V_12 * V_15 , bool V_79 )
{
if ( F_61 ( & V_15 -> V_51 ) > V_80 ) {
F_62 ( & V_15 -> V_51 ) ;
return F_7 ( - V_81 ) ;
}
if ( V_79 )
F_63 ( & V_15 -> V_49 ) ;
return V_15 ;
}
struct V_12 * F_64 ( T_4 V_82 )
{
struct V_75 V_76 = F_65 ( V_82 ) ;
struct V_12 * V_15 ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return V_15 ;
V_15 = F_60 ( V_15 , true ) ;
F_59 ( V_76 ) ;
return V_15 ;
}
static struct V_12 * F_66 ( struct V_12 * V_15 ,
bool V_79 )
{
int V_83 ;
V_83 = F_67 ( & V_15 -> V_51 , 1 , 0 ) ;
if ( V_83 >= V_80 ) {
F_41 ( V_15 , false ) ;
return F_7 ( - V_81 ) ;
}
if ( ! V_83 )
return F_7 ( - V_84 ) ;
if ( V_79 )
F_63 ( & V_15 -> V_49 ) ;
return V_15 ;
}
int __weak F_68 ( struct V_12 * V_15 , void * V_85 , void * V_86 )
{
return - V_87 ;
}
static int F_69 ( union V_13 * V_14 )
{
void T_1 * V_88 = F_70 ( V_14 -> V_85 ) ;
void T_1 * V_89 = F_70 ( V_14 -> V_86 ) ;
int V_82 = V_14 -> V_90 ;
struct V_12 * V_15 ;
void * V_85 , * V_86 , * V_91 ;
T_4 V_64 ;
struct V_75 V_76 ;
int V_7 ;
if ( F_53 ( V_92 ) )
return - V_18 ;
V_76 = F_65 ( V_82 ) ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
V_85 = F_71 ( V_88 , V_15 -> V_63 ) ;
if ( F_9 ( V_85 ) ) {
V_7 = F_55 ( V_85 ) ;
goto V_93;
}
if ( V_15 -> V_16 == V_94 ||
V_15 -> V_16 == V_95 ||
V_15 -> V_16 == V_96 )
V_64 = F_72 ( V_15 -> V_64 , 8 ) * F_73 () ;
else if ( F_74 ( V_15 ) )
V_64 = sizeof( T_4 ) ;
else
V_64 = V_15 -> V_64 ;
V_7 = - V_97 ;
V_86 = F_75 ( V_64 , V_28 | V_23 ) ;
if ( ! V_86 )
goto V_98;
if ( V_15 -> V_16 == V_94 ||
V_15 -> V_16 == V_95 ) {
V_7 = F_76 ( V_15 , V_85 , V_86 ) ;
} else if ( V_15 -> V_16 == V_96 ) {
V_7 = F_77 ( V_15 , V_85 , V_86 ) ;
} else if ( V_15 -> V_16 == V_99 ) {
V_7 = F_68 ( V_15 , V_85 , V_86 ) ;
} else if ( F_78 ( V_15 ) ) {
V_7 = F_79 ( V_15 , V_85 , V_86 ) ;
} else if ( F_80 ( V_15 ) ) {
V_7 = F_81 ( V_15 , V_85 , V_86 ) ;
} else {
F_82 () ;
V_91 = V_15 -> V_19 -> F_69 ( V_15 , V_85 ) ;
if ( V_91 )
memcpy ( V_86 , V_91 , V_64 ) ;
F_83 () ;
V_7 = V_91 ? 0 : - V_84 ;
}
if ( V_7 )
goto V_100;
V_7 = - V_11 ;
if ( F_84 ( V_89 , V_86 , V_64 ) != 0 )
goto V_100;
F_85 ( V_15 , V_82 , V_85 , V_86 ) ;
V_7 = 0 ;
V_100:
F_86 ( V_86 ) ;
V_98:
F_86 ( V_85 ) ;
V_93:
F_59 ( V_76 ) ;
return V_7 ;
}
static int F_87 ( union V_13 * V_14 )
{
void T_1 * V_88 = F_70 ( V_14 -> V_85 ) ;
void T_1 * V_89 = F_70 ( V_14 -> V_86 ) ;
int V_82 = V_14 -> V_90 ;
struct V_12 * V_15 ;
void * V_85 , * V_86 ;
T_4 V_64 ;
struct V_75 V_76 ;
int V_7 ;
if ( F_53 ( V_101 ) )
return - V_18 ;
V_76 = F_65 ( V_82 ) ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
V_85 = F_71 ( V_88 , V_15 -> V_63 ) ;
if ( F_9 ( V_85 ) ) {
V_7 = F_55 ( V_85 ) ;
goto V_93;
}
if ( V_15 -> V_16 == V_94 ||
V_15 -> V_16 == V_95 ||
V_15 -> V_16 == V_96 )
V_64 = F_72 ( V_15 -> V_64 , 8 ) * F_73 () ;
else
V_64 = V_15 -> V_64 ;
V_7 = - V_97 ;
V_86 = F_75 ( V_64 , V_28 | V_23 ) ;
if ( ! V_86 )
goto V_98;
V_7 = - V_11 ;
if ( F_88 ( V_86 , V_89 , V_64 ) != 0 )
goto V_100;
F_89 () ;
F_90 ( V_102 ) ;
if ( V_15 -> V_16 == V_94 ||
V_15 -> V_16 == V_95 ) {
V_7 = F_91 ( V_15 , V_85 , V_86 , V_14 -> V_22 ) ;
} else if ( V_15 -> V_16 == V_96 ) {
V_7 = F_92 ( V_15 , V_85 , V_86 , V_14 -> V_22 ) ;
} else if ( V_15 -> V_16 == V_103 ||
V_15 -> V_16 == V_50 ||
V_15 -> V_16 == V_104 ||
V_15 -> V_16 == V_105 ) {
F_82 () ;
V_7 = F_93 ( V_15 , V_76 . V_53 , V_85 , V_86 ,
V_14 -> V_22 ) ;
F_83 () ;
} else if ( V_15 -> V_16 == V_106 ) {
F_82 () ;
V_7 = F_94 ( V_15 , V_76 . V_53 , V_85 , V_86 ,
V_14 -> V_22 ) ;
F_83 () ;
} else {
F_82 () ;
V_7 = V_15 -> V_19 -> F_87 ( V_15 , V_85 , V_86 , V_14 -> V_22 ) ;
F_83 () ;
}
F_95 ( V_102 ) ;
F_96 () ;
if ( ! V_7 )
F_97 ( V_15 , V_82 , V_85 , V_86 ) ;
V_100:
F_86 ( V_86 ) ;
V_98:
F_86 ( V_85 ) ;
V_93:
F_59 ( V_76 ) ;
return V_7 ;
}
static int F_98 ( union V_13 * V_14 )
{
void T_1 * V_88 = F_70 ( V_14 -> V_85 ) ;
int V_82 = V_14 -> V_90 ;
struct V_12 * V_15 ;
struct V_75 V_76 ;
void * V_85 ;
int V_7 ;
if ( F_53 ( V_107 ) )
return - V_18 ;
V_76 = F_65 ( V_82 ) ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
V_85 = F_71 ( V_88 , V_15 -> V_63 ) ;
if ( F_9 ( V_85 ) ) {
V_7 = F_55 ( V_85 ) ;
goto V_93;
}
F_89 () ;
F_90 ( V_102 ) ;
F_82 () ;
V_7 = V_15 -> V_19 -> F_98 ( V_15 , V_85 ) ;
F_83 () ;
F_95 ( V_102 ) ;
F_96 () ;
if ( ! V_7 )
F_99 ( V_15 , V_82 , V_85 ) ;
F_86 ( V_85 ) ;
V_93:
F_59 ( V_76 ) ;
return V_7 ;
}
static int F_100 ( union V_13 * V_14 )
{
void T_1 * V_88 = F_70 ( V_14 -> V_85 ) ;
void T_1 * V_108 = F_70 ( V_14 -> V_109 ) ;
int V_82 = V_14 -> V_90 ;
struct V_12 * V_15 ;
void * V_85 , * V_109 ;
struct V_75 V_76 ;
int V_7 ;
if ( F_53 ( V_110 ) )
return - V_18 ;
V_76 = F_65 ( V_82 ) ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
if ( V_88 ) {
V_85 = F_71 ( V_88 , V_15 -> V_63 ) ;
if ( F_9 ( V_85 ) ) {
V_7 = F_55 ( V_85 ) ;
goto V_93;
}
} else {
V_85 = NULL ;
}
V_7 = - V_97 ;
V_109 = F_75 ( V_15 -> V_63 , V_28 ) ;
if ( ! V_109 )
goto V_98;
F_82 () ;
V_7 = V_15 -> V_19 -> F_100 ( V_15 , V_85 , V_109 ) ;
F_83 () ;
if ( V_7 )
goto V_111;
V_7 = - V_11 ;
if ( F_84 ( V_108 , V_109 , V_15 -> V_63 ) != 0 )
goto V_111;
F_101 ( V_15 , V_82 , V_85 , V_109 ) ;
V_7 = 0 ;
V_111:
F_86 ( V_109 ) ;
V_98:
F_86 ( V_85 ) ;
V_93:
F_59 ( V_76 ) ;
return V_7 ;
}
static int F_102 ( enum V_112 type , struct V_113 * V_114 )
{
if ( type >= F_6 ( V_115 ) || ! V_115 [ type ] )
return - V_18 ;
V_114 -> V_116 -> V_19 = V_115 [ type ] ;
V_114 -> type = type ;
return 0 ;
}
static void F_103 ( struct V_117 * V_116 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_116 -> V_119 ; V_118 ++ )
F_44 ( V_116 -> V_120 [ V_118 ] ) ;
F_86 ( V_116 -> V_120 ) ;
}
int F_104 ( struct V_31 * V_32 , T_4 V_30 )
{
unsigned long V_33 = F_18 ( V_35 ) >> V_36 ;
unsigned long V_121 ;
if ( V_32 ) {
V_121 = F_105 ( V_30 , & V_32 -> V_37 ) ;
if ( V_121 > V_33 ) {
F_23 ( V_30 , & V_32 -> V_37 ) ;
return - V_38 ;
}
}
return 0 ;
}
void F_106 ( struct V_31 * V_32 , T_4 V_30 )
{
if ( V_32 )
F_23 ( V_30 , & V_32 -> V_37 ) ;
}
static int F_107 ( struct V_113 * V_114 )
{
struct V_31 * V_32 = F_17 () ;
int V_122 ;
V_122 = F_104 ( V_32 , V_114 -> V_30 ) ;
if ( V_122 ) {
F_20 ( V_32 ) ;
return V_122 ;
}
V_114 -> V_116 -> V_32 = V_32 ;
return 0 ;
}
static void F_108 ( struct V_113 * V_114 )
{
struct V_31 * V_32 = V_114 -> V_116 -> V_32 ;
F_106 ( V_32 , V_114 -> V_30 ) ;
F_20 ( V_32 ) ;
}
static int F_109 ( struct V_113 * V_114 )
{
int V_39 ;
F_26 ( & V_123 ) ;
V_39 = F_27 ( & V_124 , V_114 , 1 , V_42 , V_43 ) ;
if ( V_39 > 0 )
V_114 -> V_116 -> V_39 = V_39 ;
F_28 ( & V_123 ) ;
if ( F_29 ( ! V_39 ) )
return - V_44 ;
return V_39 > 0 ? 0 : V_39 ;
}
static void F_110 ( struct V_113 * V_114 , bool V_45 )
{
if ( ! V_114 -> V_116 -> V_39 )
return;
if ( V_45 )
F_26 ( & V_123 ) ;
else
F_32 ( & V_123 ) ;
F_33 ( & V_124 , V_114 -> V_116 -> V_39 ) ;
if ( V_45 )
F_28 ( & V_123 ) ;
else
F_35 ( & V_123 ) ;
}
static void F_111 ( struct V_125 * V_126 )
{
struct V_117 * V_116 = F_37 ( V_126 , struct V_117 , V_126 ) ;
F_103 ( V_116 ) ;
F_108 ( V_116 -> V_114 ) ;
F_112 ( V_116 -> V_114 ) ;
}
static void F_113 ( struct V_113 * V_114 , bool V_45 )
{
if ( F_39 ( & V_114 -> V_116 -> V_51 ) ) {
F_114 ( V_114 ) ;
F_110 ( V_114 , V_45 ) ;
F_115 ( V_114 ) ;
F_116 ( & V_114 -> V_116 -> V_126 , F_111 ) ;
}
}
void F_117 ( struct V_113 * V_114 )
{
F_113 ( V_114 , true ) ;
}
static int F_118 ( struct V_52 * V_52 , struct V_53 * V_54 )
{
struct V_113 * V_114 = V_54 -> V_55 ;
F_117 ( V_114 ) ;
return 0 ;
}
static void F_119 ( struct V_57 * V_58 , struct V_53 * V_54 )
{
const struct V_113 * V_114 = V_54 -> V_55 ;
char V_127 [ sizeof( V_114 -> V_128 ) * 2 + 1 ] = { } ;
F_120 ( V_127 , V_114 -> V_128 , sizeof( V_114 -> V_128 ) ) ;
F_48 ( V_58 ,
L_10
L_11
L_12
L_6 ,
V_114 -> type ,
V_114 -> V_129 ,
V_127 ,
V_114 -> V_30 * 1ULL << V_36 ) ;
}
int F_121 ( struct V_113 * V_114 )
{
return F_50 ( L_13 , & V_130 , V_114 ,
V_68 | V_69 ) ;
}
static struct V_113 * F_122 ( struct V_75 V_76 )
{
if ( ! V_76 . V_53 )
return F_7 ( - V_77 ) ;
if ( V_76 . V_53 -> V_78 != & V_130 ) {
F_59 ( V_76 ) ;
return F_7 ( - V_18 ) ;
}
return V_76 . V_53 -> V_55 ;
}
struct V_113 * F_123 ( struct V_113 * V_114 , int V_118 )
{
if ( F_124 ( V_118 , & V_114 -> V_116 -> V_51 ) > V_80 ) {
F_125 ( V_118 , & V_114 -> V_116 -> V_51 ) ;
return F_7 ( - V_81 ) ;
}
return V_114 ;
}
void F_126 ( struct V_113 * V_114 , int V_118 )
{
F_127 ( F_128 ( V_118 , & V_114 -> V_116 -> V_51 ) == 0 ) ;
}
struct V_113 * F_129 ( struct V_113 * V_114 )
{
return F_123 ( V_114 , 1 ) ;
}
struct V_113 * F_130 ( struct V_113 * V_114 )
{
int V_83 ;
V_83 = F_67 ( & V_114 -> V_116 -> V_51 , 1 , 0 ) ;
if ( V_83 >= V_80 ) {
F_113 ( V_114 , false ) ;
return F_7 ( - V_81 ) ;
}
if ( ! V_83 )
return F_7 ( - V_84 ) ;
return V_114 ;
}
static struct V_113 * F_131 ( T_4 V_82 , enum V_112 * type )
{
struct V_75 V_76 = F_65 ( V_82 ) ;
struct V_113 * V_114 ;
V_114 = F_122 ( V_76 ) ;
if ( F_9 ( V_114 ) )
return V_114 ;
if ( type && V_114 -> type != * type ) {
V_114 = F_7 ( - V_18 ) ;
goto V_131;
}
V_114 = F_129 ( V_114 ) ;
V_131:
F_59 ( V_76 ) ;
return V_114 ;
}
struct V_113 * F_132 ( T_4 V_82 )
{
return F_131 ( V_82 , NULL ) ;
}
struct V_113 * F_133 ( T_4 V_82 , enum V_112 type )
{
struct V_113 * V_114 = F_131 ( V_82 , & type ) ;
if ( ! F_9 ( V_114 ) )
F_134 ( V_114 ) ;
return V_114 ;
}
static int F_135 ( union V_13 * V_14 )
{
enum V_112 type = V_14 -> V_132 ;
struct V_113 * V_114 ;
int V_7 ;
char V_133 [ 128 ] ;
bool V_134 ;
if ( F_53 ( V_135 ) )
return - V_18 ;
if ( V_14 -> V_136 & ~ V_137 )
return - V_18 ;
if ( F_136 ( V_133 , F_70 ( V_14 -> V_133 ) ,
sizeof( V_133 ) - 1 ) < 0 )
return - V_11 ;
V_133 [ sizeof( V_133 ) - 1 ] = 0 ;
V_134 = F_137 ( V_133 ) ;
if ( V_14 -> V_138 == 0 || V_14 -> V_138 > V_139 )
return - V_9 ;
if ( type == V_140 &&
V_14 -> V_141 != V_142 )
return - V_18 ;
if ( type != V_143 &&
type != V_144 &&
! F_138 ( V_145 ) )
return - V_38 ;
V_114 = F_139 ( F_140 ( V_14 -> V_138 ) , V_28 ) ;
if ( ! V_114 )
return - V_97 ;
V_7 = F_107 ( V_114 ) ;
if ( V_7 )
goto V_146;
V_114 -> V_147 = V_14 -> V_138 ;
V_7 = - V_11 ;
if ( F_88 ( V_114 -> V_148 , F_70 ( V_14 -> V_148 ) ,
F_141 ( V_114 ) ) != 0 )
goto V_149;
V_114 -> V_150 = NULL ;
V_114 -> V_129 = 0 ;
F_56 ( & V_114 -> V_116 -> V_51 , 1 ) ;
V_114 -> V_151 = V_134 ? 1 : 0 ;
V_7 = F_102 ( type , V_114 ) ;
if ( V_7 < 0 )
goto V_149;
V_7 = F_142 ( & V_114 , V_14 ) ;
if ( V_7 < 0 )
goto F_103;
V_114 = F_143 ( V_114 , & V_7 ) ;
if ( V_7 < 0 )
goto F_103;
V_7 = F_109 ( V_114 ) ;
if ( V_7 )
goto F_103;
V_7 = F_121 ( V_114 ) ;
if ( V_7 < 0 ) {
F_117 ( V_114 ) ;
return V_7 ;
}
F_144 ( V_114 ) ;
F_145 ( V_114 , V_7 ) ;
return V_7 ;
F_103:
F_103 ( V_114 -> V_116 ) ;
V_149:
F_108 ( V_114 ) ;
V_146:
F_112 ( V_114 ) ;
return V_7 ;
}
static int F_146 ( const union V_13 * V_14 )
{
if ( F_53 ( V_152 ) )
return - V_18 ;
return F_147 ( V_14 -> V_153 , F_70 ( V_14 -> V_154 ) ) ;
}
static int F_148 ( const union V_13 * V_14 )
{
if ( F_53 ( V_152 ) || V_14 -> V_153 != 0 )
return - V_18 ;
return F_149 ( F_70 ( V_14 -> V_154 ) ) ;
}
static int F_150 ( const union V_13 * V_14 , bool V_155 )
{
struct V_113 * V_114 = NULL ;
int V_82 = V_14 -> V_156 ;
struct V_12 * V_15 ;
struct V_75 V_76 ;
int V_7 ;
V_76 = F_65 ( V_82 ) ;
V_15 = F_58 ( V_76 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
if ( V_155 ) {
V_114 = F_133 ( V_14 -> V_157 ,
V_158 ) ;
if ( F_9 ( V_114 ) ) {
F_59 ( V_76 ) ;
return F_55 ( V_114 ) ;
}
}
V_7 = F_151 ( V_15 , V_114 , V_14 -> V_159 ) ;
if ( V_7 ) {
F_59 ( V_76 ) ;
if ( V_114 )
F_117 ( V_114 ) ;
return V_7 ;
}
F_59 ( V_76 ) ;
return 0 ;
}
static int F_152 ( const union V_13 * V_14 )
{
enum V_112 V_160 ;
struct V_113 * V_114 ;
struct V_161 * V_162 ;
int V_122 ;
if ( ! F_138 ( V_163 ) )
return - V_38 ;
if ( F_53 ( V_164 ) )
return - V_18 ;
if ( V_14 -> V_165 & ~ V_166 )
return - V_18 ;
switch ( V_14 -> V_159 ) {
case V_167 :
case V_168 :
V_160 = V_144 ;
break;
case V_169 :
V_160 = V_170 ;
break;
case V_171 :
V_160 = V_172 ;
break;
case V_173 :
case V_174 :
return F_150 ( V_14 , true ) ;
default:
return - V_18 ;
}
V_114 = F_133 ( V_14 -> V_157 , V_160 ) ;
if ( F_9 ( V_114 ) )
return F_55 ( V_114 ) ;
V_162 = F_153 ( V_14 -> V_156 ) ;
if ( F_9 ( V_162 ) ) {
F_117 ( V_114 ) ;
return F_55 ( V_162 ) ;
}
V_122 = F_154 ( V_162 , V_114 , V_14 -> V_159 ,
V_14 -> V_165 & V_166 ) ;
if ( V_122 )
F_117 ( V_114 ) ;
F_155 ( V_162 ) ;
return V_122 ;
}
static int F_156 ( const union V_13 * V_14 )
{
struct V_161 * V_162 ;
int V_122 ;
if ( ! F_138 ( V_163 ) )
return - V_38 ;
if ( F_53 ( V_175 ) )
return - V_18 ;
switch ( V_14 -> V_159 ) {
case V_167 :
case V_168 :
case V_169 :
case V_171 :
V_162 = F_153 ( V_14 -> V_156 ) ;
if ( F_9 ( V_162 ) )
return F_55 ( V_162 ) ;
V_122 = F_154 ( V_162 , NULL , V_14 -> V_159 , false ) ;
F_155 ( V_162 ) ;
break;
case V_173 :
case V_174 :
V_122 = F_150 ( V_14 , false ) ;
break;
default:
return - V_18 ;
}
return V_122 ;
}
static int F_157 ( const union V_13 * V_14 ,
union V_13 T_1 * V_176 )
{
struct V_113 * V_114 ;
int V_122 = - V_87 ;
if ( F_53 ( V_177 ) )
return - V_18 ;
V_114 = F_132 ( V_14 -> V_178 . V_179 ) ;
if ( F_9 ( V_114 ) )
return F_55 ( V_114 ) ;
if ( V_114 -> V_116 -> V_19 -> V_180 )
V_122 = V_114 -> V_116 -> V_19 -> V_180 ( V_114 , V_14 , V_176 ) ;
F_117 ( V_114 ) ;
return V_122 ;
}
static int F_158 ( const union V_13 * V_14 ,
union V_13 T_1 * V_176 ,
struct V_181 * V_181 ,
T_5 * V_182 )
{
T_4 V_183 = V_14 -> V_184 ;
int V_7 = 0 ;
if ( F_53 ( V_185 ) || V_183 >= V_42 )
return - V_18 ;
if ( ! F_138 ( V_145 ) )
return - V_38 ;
V_183 ++ ;
F_26 ( V_182 ) ;
if ( ! F_159 ( V_181 , & V_183 ) )
V_7 = - V_84 ;
F_28 ( V_182 ) ;
if ( ! V_7 )
V_7 = F_160 ( V_183 , & V_176 -> V_183 ) ;
return V_7 ;
}
static int F_161 ( const union V_13 * V_14 )
{
struct V_113 * V_114 ;
T_4 V_39 = V_14 -> V_186 ;
int V_75 ;
if ( F_53 ( V_187 ) )
return - V_18 ;
if ( ! F_138 ( V_145 ) )
return - V_38 ;
F_26 ( & V_123 ) ;
V_114 = F_162 ( & V_124 , V_39 ) ;
if ( V_114 )
V_114 = F_130 ( V_114 ) ;
else
V_114 = F_7 ( - V_84 ) ;
F_28 ( & V_123 ) ;
if ( F_9 ( V_114 ) )
return F_55 ( V_114 ) ;
V_75 = F_121 ( V_114 ) ;
if ( V_75 < 0 )
F_117 ( V_114 ) ;
return V_75 ;
}
static int F_163 ( const union V_13 * V_14 )
{
struct V_12 * V_15 ;
T_4 V_39 = V_14 -> V_188 ;
int V_75 ;
if ( F_53 ( V_189 ) )
return - V_18 ;
if ( ! F_138 ( V_145 ) )
return - V_38 ;
F_26 ( & V_40 ) ;
V_15 = F_162 ( & V_41 , V_39 ) ;
if ( V_15 )
V_15 = F_66 ( V_15 , true ) ;
else
V_15 = F_7 ( - V_84 ) ;
F_28 ( & V_40 ) ;
if ( F_9 ( V_15 ) )
return F_55 ( V_15 ) ;
V_75 = F_49 ( V_15 ) ;
if ( V_75 < 0 )
F_44 ( V_15 ) ;
return V_75 ;
}
static int F_164 ( struct V_113 * V_114 ,
const union V_13 * V_14 ,
union V_13 T_1 * V_176 )
{
struct V_190 T_1 * V_191 = F_70 ( V_14 -> V_192 . V_192 ) ;
struct V_190 V_192 = {} ;
T_4 V_193 = V_14 -> V_192 . V_193 ;
char T_1 * V_194 ;
T_4 V_195 ;
int V_7 ;
V_7 = F_1 ( V_191 , sizeof( V_192 ) , V_193 ) ;
if ( V_7 )
return V_7 ;
V_193 = F_165 ( T_4 , sizeof( V_192 ) , V_193 ) ;
if ( F_88 ( & V_192 , V_191 , V_193 ) )
return - V_11 ;
V_192 . type = V_114 -> type ;
V_192 . V_39 = V_114 -> V_116 -> V_39 ;
memcpy ( V_192 . V_128 , V_114 -> V_128 , sizeof( V_114 -> V_128 ) ) ;
if ( ! F_138 ( V_145 ) ) {
V_192 . V_196 = 0 ;
V_192 . V_197 = 0 ;
goto V_198;
}
V_195 = V_192 . V_196 ;
V_192 . V_196 = V_114 -> V_199 ;
if ( V_192 . V_196 && V_195 ) {
V_194 = F_70 ( V_192 . V_200 ) ;
V_195 = F_165 ( T_4 , V_192 . V_196 , V_195 ) ;
if ( F_84 ( V_194 , V_114 -> V_201 , V_195 ) )
return - V_11 ;
}
V_195 = V_192 . V_197 ;
V_192 . V_197 = F_141 ( V_114 ) ;
if ( V_192 . V_197 && V_195 ) {
V_194 = F_70 ( V_192 . V_202 ) ;
V_195 = F_165 ( T_4 , V_192 . V_197 , V_195 ) ;
if ( F_84 ( V_194 , V_114 -> V_203 , V_195 ) )
return - V_11 ;
}
V_198:
if ( F_84 ( V_191 , & V_192 , V_193 ) ||
F_160 ( V_193 , & V_176 -> V_192 . V_193 ) )
return - V_11 ;
return 0 ;
}
static int F_166 ( struct V_12 * V_15 ,
const union V_13 * V_14 ,
union V_13 T_1 * V_176 )
{
struct V_204 T_1 * V_191 = F_70 ( V_14 -> V_192 . V_192 ) ;
struct V_204 V_192 = {} ;
T_4 V_193 = V_14 -> V_192 . V_193 ;
int V_7 ;
V_7 = F_1 ( V_191 , sizeof( V_192 ) , V_193 ) ;
if ( V_7 )
return V_7 ;
V_193 = F_165 ( T_4 , sizeof( V_192 ) , V_193 ) ;
V_192 . type = V_15 -> V_16 ;
V_192 . V_39 = V_15 -> V_39 ;
V_192 . V_63 = V_15 -> V_63 ;
V_192 . V_64 = V_15 -> V_64 ;
V_192 . V_65 = V_15 -> V_65 ;
V_192 . V_66 = V_15 -> V_66 ;
if ( F_84 ( V_191 , & V_192 , V_193 ) ||
F_160 ( V_193 , & V_176 -> V_192 . V_193 ) )
return - V_11 ;
return 0 ;
}
static int F_167 ( const union V_13 * V_14 ,
union V_13 T_1 * V_176 )
{
int V_82 = V_14 -> V_192 . V_153 ;
struct V_75 V_76 ;
int V_7 ;
if ( F_53 ( V_205 ) )
return - V_18 ;
V_76 = F_65 ( V_82 ) ;
if ( ! V_76 . V_53 )
return - V_206 ;
if ( V_76 . V_53 -> V_78 == & V_130 )
V_7 = F_164 ( V_76 . V_53 -> V_55 , V_14 ,
V_176 ) ;
else if ( V_76 . V_53 -> V_78 == & V_67 )
V_7 = F_166 ( V_76 . V_53 -> V_55 , V_14 ,
V_176 ) ;
else
V_7 = - V_18 ;
F_59 ( V_76 ) ;
return V_7 ;
}
