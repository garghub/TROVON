static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_5 , V_6 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_3 ( V_5 , V_9 , V_3 ) ;
F_4 ( V_5 , V_10 ,
V_11 , V_8 -> V_12 ,
V_13 , V_4 ) ;
return F_5 ( V_2 , V_14 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 )
{
F_2 ( V_5 , V_16 ) ;
int V_17 ;
F_3 ( V_5 , V_18 , V_3 ) ;
F_3 ( V_5 , V_19 , V_15 ) ;
F_3 ( V_5 , V_20 , 2 ) ;
F_7 ( V_5 , V_21 ,
V_22 , 0 ) ;
V_17 = F_8 ( V_2 , V_23 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
if ( V_17 == - V_24 ) {
F_3 ( V_5 , V_20 , 1 ) ;
V_17 = F_5 ( V_2 , V_23 , V_5 ,
sizeof( V_5 ) , NULL , 0 , NULL ) ;
} else if ( V_17 ) {
F_9 ( V_2 , V_23 ,
V_16 ,
NULL , 0 , V_17 ) ;
}
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_5 , V_25 ) ;
F_3 ( V_5 , V_26 , V_3 ) ;
return F_5 ( V_2 , V_27 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_28 ,
unsigned int V_29 ,
T_1 V_30 ,
unsigned int * V_31 )
{
F_2 ( V_5 , V_32 ) ;
F_2 ( V_33 , V_34 ) ;
T_2 V_35 ;
int V_17 ;
F_12 ( ! V_31 ) ;
F_3 ( V_5 , V_36 , V_28 ) ;
F_3 ( V_5 , V_37 , V_29 ) ;
F_3 ( V_5 , V_38 ,
( V_30 != V_39 ) ) ;
F_7 ( V_5 , V_40 ,
V_41 , 0 ) ;
if ( V_30 != V_39 )
F_7 ( V_5 , V_42 ,
V_43 , V_30 ) ;
V_17 = F_5 ( V_2 , V_44 , V_5 , sizeof( V_5 ) ,
V_33 , sizeof( V_33 ) , & V_35 ) ;
if ( V_17 )
return V_17 ;
if ( V_35 < V_34 )
return - V_45 ;
* V_31 = F_13 ( V_33 , V_46 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_5 , V_47 ) ;
F_3 ( V_5 , V_48 , V_3 ) ;
return F_5 ( V_2 , V_49 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_50 ;
if ( ! V_8 -> V_51 )
return;
for ( V_50 = 0 ; V_50 < V_2 -> V_52 ; V_50 ++ ) {
struct V_53 * V_51 = V_8 -> V_51 + V_50 ;
if ( V_51 -> V_54 &&
V_51 -> V_54 -> V_55 & V_56 )
continue;
if ( V_51 -> V_57 ) {
F_1 ( V_2 , V_58 , V_50 ) ;
V_51 -> V_57 = 0 ;
}
if ( ! F_16 ( V_51 -> V_59 ) ) {
F_17 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
F_18 ( V_51 -> V_59 ) ;
}
if ( V_51 -> V_60 ) {
F_14 ( V_2 , V_51 -> V_60 ) ;
V_51 -> V_60 = 0 ;
}
V_51 -> V_2 = NULL ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_15 ( V_2 ) ;
F_20 ( V_8 -> V_51 ) ;
V_8 -> V_51 = NULL ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_61 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 = V_8 -> V_51 + V_61 ;
int V_17 ;
if ( F_22 ( ! V_8 -> V_51 ) )
return - V_62 ;
V_17 = F_11 ( V_2 , V_63 ,
V_64 ,
V_51 -> V_30 , & V_51 -> V_60 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_23 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_17 ) {
F_18 ( V_51 -> V_59 ) ;
return V_17 ;
}
V_17 = F_1 ( V_2 , V_51 -> V_60 , V_61 ) ;
if ( V_17 )
return V_17 ;
V_51 -> V_57 = 1 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_50 ;
int V_17 ;
V_8 -> V_51 = F_25 ( V_2 -> V_52 , sizeof( struct V_53 ) ,
V_65 ) ;
if ( ! V_8 -> V_51 )
return - V_66 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_52 ; V_50 ++ ) {
F_26 ( V_8 -> V_51 [ V_50 ] . V_59 ) ;
V_8 -> V_51 [ V_50 ] . V_2 = NULL ;
V_8 -> V_51 [ V_50 ] . V_30 = V_39 ;
V_17 = F_21 ( V_2 , V_50 ) ;
if ( V_17 )
goto V_67;
}
return 0 ;
V_67:
F_15 ( V_2 ) ;
F_20 ( V_8 -> V_51 ) ;
V_8 -> V_51 = NULL ;
return V_17 ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
int V_17 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_52 ; V_50 ++ ) {
V_17 = F_21 ( V_2 , V_50 ) ;
if ( V_17 )
goto V_67;
}
return 0 ;
V_67:
F_19 ( V_2 ) ;
return V_17 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_68 * V_69 = V_2 -> V_69 ;
int V_17 ;
if ( F_29 ( V_2 -> V_54 ) <= 0 ) {
F_30 ( V_2 , V_8 -> V_60 ) ;
return 0 ;
}
V_17 = F_6 ( V_2 , V_63 ,
V_70 ) ;
if ( V_17 )
goto V_71;
V_17 = F_11 ( V_2 , V_63 ,
V_64 ,
V_39 , & V_8 -> V_60 ) ;
if ( V_17 )
goto V_72;
V_17 = F_23 ( V_2 , V_8 -> V_60 , V_69 -> V_73 ) ;
if ( V_17 )
goto V_74;
F_31 ( V_8 -> V_75 , V_69 -> V_73 ) ;
V_17 = F_30 ( V_2 , V_8 -> V_60 ) ;
if ( V_17 )
goto V_76;
return 0 ;
V_76:
F_17 ( V_2 , V_8 -> V_60 , V_8 -> V_75 ) ;
F_18 ( V_8 -> V_75 ) ;
V_74:
F_14 ( V_2 , V_8 -> V_60 ) ;
V_8 -> V_60 = V_63 ;
V_72:
F_10 ( V_2 , V_63 ) ;
V_71:
return V_17 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
return F_30 ( V_2 , V_8 -> V_60 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_17 ;
if ( ! V_8 -> V_77 )
return 0 ;
V_17 = F_28 ( V_2 ) ;
if ( V_17 )
goto V_67;
V_17 = F_27 ( V_2 ) ;
if ( V_17 )
goto V_67;
V_8 -> V_77 = false ;
V_67:
return V_17 ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_17 ;
if ( ! V_8 -> V_77 )
return 0 ;
V_17 = F_35 ( V_2 , V_63 ) ;
if ( V_17 )
return V_17 ;
V_8 -> V_77 = false ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_19 ( V_2 ) ;
F_35 ( V_2 , V_8 -> V_60 ) ;
if ( V_8 -> V_60 == V_63 )
return;
if ( ! F_16 ( V_8 -> V_75 ) ) {
F_17 ( V_2 , V_8 -> V_60 ,
V_2 -> V_69 -> V_73 ) ;
F_18 ( V_8 -> V_75 ) ;
}
F_14 ( V_2 , V_8 -> V_60 ) ;
V_8 -> V_60 = V_63 ;
if ( ! F_37 ( V_2 -> V_54 ) )
F_10 ( V_2 , V_8 -> V_60 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_63 ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_78 )
{
int V_17 = 0 ;
struct V_54 * V_79 = V_2 -> V_54 ;
V_2 -> V_52 = V_78 ;
V_17 = F_24 ( V_2 ) ;
if ( V_17 )
goto V_71;
V_17 = F_40 ( V_79 , V_78 ) ;
if ( V_17 )
goto V_72;
return 0 ;
V_72:
F_19 ( V_2 ) ;
V_71:
V_2 -> V_52 = 0 ;
F_41 ( V_2 , V_80 , V_2 -> V_69 ,
L_1 ) ;
return V_17 ;
}
static int F_42 ( struct V_1 * V_2 , bool V_81 )
{
struct V_54 * V_79 = V_2 -> V_54 ;
unsigned int V_82 = 0 ;
V_82 = F_37 ( V_79 ) ;
if ( V_82 && ! V_81 ) {
F_43 ( V_2 , V_83 , V_2 -> V_69 , L_2
L_3 ) ;
return - V_84 ;
}
if ( ! V_82 )
F_44 ( V_79 ) ;
F_19 ( V_2 ) ;
V_2 -> V_52 = 0 ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , int V_78 )
{
if ( V_78 == 0 )
return F_42 ( V_2 , false ) ;
else
return F_39 ( V_2 , V_78 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_50 ;
int V_17 ;
if ( ! V_8 -> V_51 ) {
if ( F_48 ( V_2 -> V_54 ) && ! F_37 ( V_2 -> V_54 ) )
F_44 ( V_2 -> V_54 ) ;
return;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_52 ; ++ V_50 ) {
struct V_1 * V_85 = V_8 -> V_51 [ V_50 ] . V_2 ;
if ( V_85 )
V_85 -> V_54 -> V_86 -> remove ( V_85 -> V_54 ) ;
}
V_17 = F_42 ( V_2 , true ) ;
if ( V_17 )
F_49 ( V_2 , V_83 , V_2 -> V_69 ,
L_4 , V_17 ) ;
else
F_49 ( V_2 , V_83 , V_2 -> V_69 , L_5 ) ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_3 ,
T_3 * V_59 )
{
F_2 ( V_5 , V_87 ) ;
F_51 ( V_33 ) ;
T_2 V_35 ;
int V_17 ;
F_3 ( V_5 , V_88 , V_3 ) ;
F_31 ( F_52 ( V_5 , V_89 ) , V_59 ) ;
V_17 = F_5 ( V_2 , V_90 , V_5 ,
sizeof( V_5 ) , V_33 , sizeof( V_33 ) , & V_35 ) ;
return V_17 ;
}
int F_53 ( struct V_1 * V_2 , int V_61 , T_3 * V_59 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
int V_17 ;
if ( ! V_8 -> V_51 )
return - V_62 ;
if ( V_61 >= V_2 -> V_52 )
return - V_91 ;
V_51 = V_8 -> V_51 + V_61 ;
if ( V_51 -> V_2 ) {
F_54 ( V_51 -> V_2 ) ;
F_55 ( V_51 -> V_2 -> V_69 ) ;
F_56 ( & V_51 -> V_2 -> V_92 ) ;
V_51 -> V_2 -> type -> V_93 ( V_51 -> V_2 ) ;
V_17 = F_35 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 ) {
F_57 ( & V_51 -> V_2 -> V_92 ) ;
return V_17 ;
}
}
V_17 = F_1 ( V_2 , V_58 , V_61 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_17 = F_50 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_17 )
return V_17 ;
}
if ( ! F_16 ( V_59 ) ) {
V_17 = F_23 ( V_2 , V_51 -> V_60 , V_59 ) ;
if ( V_17 ) {
F_18 ( V_51 -> V_59 ) ;
goto V_67;
}
if ( V_51 -> V_2 )
F_31 ( V_51 -> V_2 -> V_69 -> V_73 , V_59 ) ;
}
F_31 ( V_51 -> V_59 , V_59 ) ;
V_17 = F_1 ( V_2 , V_51 -> V_60 , V_61 ) ;
if ( V_17 )
goto V_67;
if ( V_51 -> V_2 ) {
V_17 = F_30 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 ) {
F_57 ( & V_51 -> V_2 -> V_92 ) ;
return V_17 ;
}
V_51 -> V_2 -> type -> V_94 ( V_51 -> V_2 ) ;
F_57 ( & V_51 -> V_2 -> V_92 ) ;
F_58 ( V_51 -> V_2 -> V_69 ) ;
F_59 ( V_51 -> V_2 -> V_69 ) ;
}
return 0 ;
V_67:
memset ( V_51 -> V_59 , 0 , V_95 ) ;
return V_17 ;
}
int F_60 ( struct V_1 * V_2 , int V_61 , T_1 V_30 ,
T_3 V_96 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
T_1 V_97 , V_98 ;
int V_17 = 0 , V_99 = 0 ;
if ( V_61 >= V_2 -> V_52 )
return - V_91 ;
if ( V_96 != 0 )
return - V_91 ;
V_51 = V_8 -> V_51 + V_61 ;
V_98 = ( V_30 == 0 ) ? V_39 : V_30 ;
if ( V_98 == V_51 -> V_30 )
return 0 ;
if ( V_51 -> V_2 ) {
F_54 ( V_51 -> V_2 ) ;
F_55 ( V_51 -> V_2 -> V_69 ) ;
F_56 ( & V_51 -> V_2 -> V_92 ) ;
V_51 -> V_2 -> type -> V_93 ( V_51 -> V_2 ) ;
V_17 = F_35 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 )
goto V_100;
}
if ( V_51 -> V_57 ) {
V_17 = F_1 ( V_2 , V_58 , V_61 ) ;
if ( V_17 ) {
F_61 ( V_2 , V_83 , V_2 -> V_69 ,
L_6 , V_61 ) ;
F_61 ( V_2 , V_83 , V_2 -> V_69 ,
L_7 ) ;
F_61 ( V_2 , V_83 , V_2 -> V_69 ,
L_8 ) ;
goto V_101;
}
V_51 -> V_57 = 0 ;
}
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_17 = F_17 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_17 )
goto V_102;
}
if ( V_51 -> V_60 ) {
V_17 = F_14 ( V_2 , V_51 -> V_60 ) ;
if ( V_17 )
goto V_103;
V_51 -> V_60 = 0 ;
}
V_97 = V_51 -> V_30 ;
V_51 -> V_30 = V_98 ;
V_17 = F_11 ( V_2 , V_63 ,
V_64 ,
V_51 -> V_30 , & V_51 -> V_60 ) ;
if ( V_17 )
goto V_104;
V_103:
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_99 = F_23 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_99 ) {
F_18 ( V_51 -> V_59 ) ;
goto V_104;
}
}
V_102:
V_99 = F_1 ( V_2 , V_51 -> V_60 , V_61 ) ;
if ( V_99 )
goto V_104;
else
V_51 -> V_57 = 1 ;
V_101:
if ( V_51 -> V_2 ) {
V_99 = F_30 ( V_51 -> V_2 , V_63 ) ;
if ( V_99 )
goto V_104;
}
V_100:
if ( V_51 -> V_2 ) {
V_99 = V_51 -> V_2 -> type -> V_94 ( V_51 -> V_2 ) ;
if ( V_99 )
goto V_104;
F_57 ( & V_51 -> V_2 -> V_92 ) ;
F_57 ( & V_51 -> V_2 -> V_92 ) ;
V_99 = F_58 ( V_51 -> V_2 -> V_69 ) ;
if ( V_99 )
goto V_105;
F_59 ( V_51 -> V_2 -> V_69 ) ;
}
return V_17 ;
V_104:
if ( V_51 -> V_2 )
F_57 ( & V_51 -> V_2 -> V_92 ) ;
V_105:
if ( V_51 -> V_2 ) {
F_41 ( V_2 , V_83 , V_2 -> V_69 ,
L_9 ) ;
F_62 ( V_51 -> V_2 , V_106 ) ;
} else {
F_41 ( V_2 , V_83 , V_2 -> V_69 ,
L_10
L_11 ) ;
F_41 ( V_2 , V_83 , V_2 -> V_69 ,
L_12 ) ;
}
return V_17 ? V_17 : V_99 ;
}
int F_63 ( struct V_1 * V_2 , int V_61 ,
bool V_107 )
{
return V_107 ? - V_62 : 0 ;
}
int F_64 ( struct V_1 * V_2 , int V_61 ,
int V_108 )
{
F_2 ( V_5 , V_109 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_65 ( V_110 !=
V_111 ) ;
F_65 ( V_112 !=
V_113 ) ;
F_65 ( V_114 !=
V_115 ) ;
F_4 ( V_5 , V_116 ,
V_117 ,
V_8 -> V_12 ,
V_118 , V_61 ) ;
F_3 ( V_5 , V_119 , V_108 ) ;
return F_5 ( V_2 , V_120 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
int F_66 ( struct V_1 * V_2 , int V_61 ,
struct V_121 * V_122 )
{
F_2 ( V_5 , V_109 ) ;
F_2 ( V_33 , V_123 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
T_2 V_35 ;
int V_17 ;
if ( V_61 >= V_2 -> V_52 )
return - V_91 ;
if ( ! V_8 -> V_51 )
return - V_62 ;
V_51 = V_8 -> V_51 + V_61 ;
V_122 -> V_51 = V_61 ;
V_122 -> V_124 = 0 ;
V_122 -> V_125 = 0 ;
F_31 ( V_122 -> V_59 , V_51 -> V_59 ) ;
V_122 -> V_30 = ( V_51 -> V_30 == V_39 ) ? 0 : V_51 -> V_30 ;
V_122 -> V_96 = 0 ;
F_4 ( V_5 , V_116 ,
V_117 ,
V_8 -> V_12 ,
V_118 , V_61 ) ;
F_3 ( V_5 , V_119 ,
V_126 ) ;
V_17 = F_5 ( V_2 , V_120 , V_5 , sizeof( V_5 ) ,
V_33 , sizeof( V_33 ) , & V_35 ) ;
if ( V_17 )
return V_17 ;
if ( V_35 < V_123 )
return - V_45 ;
V_122 -> V_127 = F_13 ( V_33 , V_128 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! F_68 ( V_8 -> V_3 ) )
return - V_62 ;
V_130 -> V_131 = V_95 ;
memcpy ( V_130 -> V_132 , V_8 -> V_3 , V_130 -> V_131 ) ;
return 0 ;
}
