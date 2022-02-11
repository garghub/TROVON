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
static int F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_3 V_68 ;
int V_17 ;
V_17 = F_29 ( V_2 , V_8 -> V_60 ) ;
if ( V_17 )
goto V_69;
V_17 = F_30 ( V_2 , V_8 -> V_60 ,
& V_68 , NULL , NULL ) ;
if ( V_17 )
goto V_70;
if ( V_68 &
( 1 << V_71 ) )
V_2 -> V_72 |= V_73 ;
else
V_2 -> V_72 &= ~ V_73 ;
return 0 ;
V_70:
F_31 ( V_2 , V_63 ) ;
V_69:
return V_17 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_74 * V_75 = V_2 -> V_75 ;
int V_17 ;
if ( F_33 ( V_2 -> V_54 ) <= 0 ) {
F_28 ( V_2 ) ;
return 0 ;
}
V_17 = F_6 ( V_2 , V_63 ,
V_76 ) ;
if ( V_17 )
goto V_77;
V_17 = F_11 ( V_2 , V_63 ,
V_64 ,
V_39 , & V_8 -> V_60 ) ;
if ( V_17 )
goto V_78;
V_17 = F_23 ( V_2 , V_8 -> V_60 , V_75 -> V_79 ) ;
if ( V_17 )
goto V_80;
F_34 ( V_8 -> V_81 , V_75 -> V_79 ) ;
V_17 = F_28 ( V_2 ) ;
if ( V_17 )
goto V_82;
return 0 ;
V_82:
F_17 ( V_2 , V_8 -> V_60 , V_8 -> V_81 ) ;
F_18 ( V_8 -> V_81 ) ;
V_80:
F_14 ( V_2 , V_8 -> V_60 ) ;
V_8 -> V_60 = V_63 ;
V_78:
F_10 ( V_2 , V_63 ) ;
V_77:
return V_17 ;
}
int F_35 ( struct V_1 * V_2 )
{
return F_28 ( V_2 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_17 ;
if ( ! V_8 -> V_83 )
return 0 ;
V_17 = F_32 ( V_2 ) ;
if ( V_17 )
goto V_67;
V_17 = F_27 ( V_2 ) ;
if ( V_17 )
goto V_67;
V_8 -> V_83 = false ;
V_67:
return V_17 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_17 ;
if ( ! V_8 -> V_83 )
return 0 ;
V_17 = F_31 ( V_2 , V_63 ) ;
if ( V_17 )
return V_17 ;
V_8 -> V_83 = false ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_19 ( V_2 ) ;
F_31 ( V_2 , V_8 -> V_60 ) ;
if ( V_8 -> V_60 == V_63 )
return;
if ( ! F_16 ( V_8 -> V_81 ) ) {
F_17 ( V_2 , V_8 -> V_60 ,
V_2 -> V_75 -> V_79 ) ;
F_18 ( V_8 -> V_81 ) ;
}
F_14 ( V_2 , V_8 -> V_60 ) ;
V_8 -> V_60 = V_63 ;
if ( ! F_39 ( V_2 -> V_54 ) )
F_10 ( V_2 , V_8 -> V_60 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_63 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_84 )
{
int V_17 = 0 ;
struct V_54 * V_85 = V_2 -> V_54 ;
V_2 -> V_52 = V_84 ;
V_17 = F_24 ( V_2 ) ;
if ( V_17 )
goto V_77;
V_17 = F_42 ( V_85 , V_84 ) ;
if ( V_17 )
goto V_78;
return 0 ;
V_78:
F_19 ( V_2 ) ;
V_77:
V_2 -> V_52 = 0 ;
F_43 ( V_2 , V_86 , V_2 -> V_75 ,
L_1 ) ;
return V_17 ;
}
static int F_44 ( struct V_1 * V_2 , bool V_87 )
{
struct V_54 * V_85 = V_2 -> V_54 ;
unsigned int V_88 = 0 ;
V_88 = F_39 ( V_85 ) ;
if ( V_88 && ! V_87 ) {
F_45 ( V_2 , V_89 , V_2 -> V_75 , L_2
L_3 ) ;
return - V_90 ;
}
if ( ! V_88 )
F_46 ( V_85 ) ;
F_19 ( V_2 ) ;
V_2 -> V_52 = 0 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_84 )
{
if ( V_84 == 0 )
return F_44 ( V_2 , false ) ;
else
return F_41 ( V_2 , V_84 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_50 ;
int V_17 ;
if ( ! V_8 -> V_51 ) {
if ( F_50 ( V_2 -> V_54 ) && ! F_39 ( V_2 -> V_54 ) )
F_46 ( V_2 -> V_54 ) ;
return;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_52 ; ++ V_50 ) {
struct V_1 * V_91 = V_8 -> V_51 [ V_50 ] . V_2 ;
if ( V_91 )
V_91 -> V_54 -> V_92 -> remove ( V_91 -> V_54 ) ;
}
V_17 = F_44 ( V_2 , true ) ;
if ( V_17 )
F_51 ( V_2 , V_89 , V_2 -> V_75 ,
L_4 , V_17 ) ;
else
F_51 ( V_2 , V_89 , V_2 -> V_75 , L_5 ) ;
}
static int F_52 ( struct V_1 * V_2 , unsigned int V_3 ,
T_4 * V_59 )
{
F_2 ( V_5 , V_93 ) ;
F_53 ( V_33 ) ;
T_2 V_35 ;
int V_17 ;
F_3 ( V_5 , V_94 , V_3 ) ;
F_34 ( F_54 ( V_5 , V_95 ) , V_59 ) ;
V_17 = F_5 ( V_2 , V_96 , V_5 ,
sizeof( V_5 ) , V_33 , sizeof( V_33 ) , & V_35 ) ;
return V_17 ;
}
int F_55 ( struct V_1 * V_2 , int V_61 , T_4 * V_59 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
int V_17 ;
if ( ! V_8 -> V_51 )
return - V_62 ;
if ( V_61 >= V_2 -> V_52 )
return - V_97 ;
V_51 = V_8 -> V_51 + V_61 ;
if ( V_51 -> V_2 ) {
F_56 ( V_51 -> V_2 ) ;
F_57 ( V_51 -> V_2 -> V_75 ) ;
F_58 ( & V_51 -> V_2 -> V_98 ) ;
V_51 -> V_2 -> type -> V_99 ( V_51 -> V_2 ) ;
V_17 = F_31 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 ) {
F_59 ( & V_51 -> V_2 -> V_98 ) ;
return V_17 ;
}
}
V_17 = F_1 ( V_2 , V_58 , V_61 ) ;
if ( V_17 )
return V_17 ;
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_17 = F_52 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
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
F_34 ( V_51 -> V_2 -> V_75 -> V_79 , V_59 ) ;
}
F_34 ( V_51 -> V_59 , V_59 ) ;
V_17 = F_1 ( V_2 , V_51 -> V_60 , V_61 ) ;
if ( V_17 )
goto V_67;
if ( V_51 -> V_2 ) {
V_17 = F_29 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 ) {
F_59 ( & V_51 -> V_2 -> V_98 ) ;
return V_17 ;
}
V_51 -> V_2 -> type -> V_100 ( V_51 -> V_2 ) ;
F_59 ( & V_51 -> V_2 -> V_98 ) ;
F_60 ( V_51 -> V_2 -> V_75 ) ;
F_61 ( V_51 -> V_2 -> V_75 ) ;
}
return 0 ;
V_67:
memset ( V_51 -> V_59 , 0 , V_101 ) ;
return V_17 ;
}
int F_62 ( struct V_1 * V_2 , int V_61 , T_1 V_30 ,
T_4 V_102 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
T_1 V_103 , V_104 ;
int V_17 = 0 , V_105 = 0 ;
if ( V_61 >= V_2 -> V_52 )
return - V_97 ;
if ( V_102 != 0 )
return - V_97 ;
V_51 = V_8 -> V_51 + V_61 ;
V_104 = ( V_30 == 0 ) ? V_39 : V_30 ;
if ( V_104 == V_51 -> V_30 )
return 0 ;
if ( V_51 -> V_2 ) {
F_56 ( V_51 -> V_2 ) ;
F_57 ( V_51 -> V_2 -> V_75 ) ;
F_63 ( & V_51 -> V_2 -> V_106 ) ;
F_58 ( & V_51 -> V_2 -> V_98 ) ;
V_51 -> V_2 -> type -> V_99 ( V_51 -> V_2 ) ;
V_17 = F_31 ( V_51 -> V_2 , V_63 ) ;
if ( V_17 )
goto V_107;
}
if ( V_51 -> V_57 ) {
V_17 = F_1 ( V_2 , V_58 , V_61 ) ;
if ( V_17 ) {
F_64 ( V_2 , V_89 , V_2 -> V_75 ,
L_6 , V_61 ) ;
F_64 ( V_2 , V_89 , V_2 -> V_75 ,
L_7 ) ;
F_64 ( V_2 , V_89 , V_2 -> V_75 ,
L_8 ) ;
goto V_108;
}
V_51 -> V_57 = 0 ;
}
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_17 = F_17 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_17 )
goto V_109;
}
if ( V_51 -> V_60 ) {
V_17 = F_14 ( V_2 , V_51 -> V_60 ) ;
if ( V_17 )
goto V_110;
V_51 -> V_60 = 0 ;
}
V_103 = V_51 -> V_30 ;
V_51 -> V_30 = V_104 ;
V_17 = F_11 ( V_2 , V_63 ,
V_64 ,
V_51 -> V_30 , & V_51 -> V_60 ) ;
if ( V_17 )
goto V_111;
V_110:
if ( ! F_16 ( V_51 -> V_59 ) ) {
V_105 = F_23 ( V_2 , V_51 -> V_60 , V_51 -> V_59 ) ;
if ( V_105 ) {
F_18 ( V_51 -> V_59 ) ;
goto V_111;
}
}
V_109:
V_105 = F_1 ( V_2 , V_51 -> V_60 , V_61 ) ;
if ( V_105 )
goto V_111;
else
V_51 -> V_57 = 1 ;
V_108:
if ( V_51 -> V_2 ) {
V_105 = F_29 ( V_51 -> V_2 , V_63 ) ;
if ( V_105 )
goto V_111;
}
V_107:
if ( V_51 -> V_2 ) {
V_105 = V_51 -> V_2 -> type -> V_100 ( V_51 -> V_2 ) ;
if ( V_105 )
goto V_111;
F_59 ( & V_51 -> V_2 -> V_98 ) ;
F_65 ( & V_51 -> V_2 -> V_106 ) ;
F_59 ( & V_51 -> V_2 -> V_98 ) ;
V_105 = F_60 ( V_51 -> V_2 -> V_75 ) ;
if ( V_105 )
goto V_112;
F_61 ( V_51 -> V_2 -> V_75 ) ;
}
return V_17 ;
V_111:
if ( V_51 -> V_2 ) {
F_59 ( & V_51 -> V_2 -> V_98 ) ;
F_65 ( & V_51 -> V_2 -> V_106 ) ;
}
V_112:
if ( V_51 -> V_2 ) {
F_43 ( V_2 , V_89 , V_2 -> V_75 ,
L_9 ) ;
F_66 ( V_51 -> V_2 , V_113 ) ;
} else {
F_43 ( V_2 , V_89 , V_2 -> V_75 ,
L_10
L_11 ) ;
F_43 ( V_2 , V_89 , V_2 -> V_75 ,
L_12 ) ;
}
return V_17 ? V_17 : V_105 ;
}
int F_67 ( struct V_1 * V_2 , int V_61 ,
bool V_114 )
{
return V_114 ? - V_62 : 0 ;
}
int F_68 ( struct V_1 * V_2 , int V_61 ,
int V_115 )
{
F_2 ( V_5 , V_116 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_69 ( V_117 !=
V_118 ) ;
F_69 ( V_119 !=
V_120 ) ;
F_69 ( V_121 !=
V_122 ) ;
F_4 ( V_5 , V_123 ,
V_124 ,
V_8 -> V_12 ,
V_125 , V_61 ) ;
F_3 ( V_5 , V_126 , V_115 ) ;
return F_5 ( V_2 , V_127 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
int F_70 ( struct V_1 * V_2 , int V_61 ,
struct V_128 * V_129 )
{
F_2 ( V_5 , V_116 ) ;
F_2 ( V_33 , V_130 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_53 * V_51 ;
T_2 V_35 ;
int V_17 ;
if ( V_61 >= V_2 -> V_52 )
return - V_97 ;
if ( ! V_8 -> V_51 )
return - V_62 ;
V_51 = V_8 -> V_51 + V_61 ;
V_129 -> V_51 = V_61 ;
V_129 -> V_131 = 0 ;
V_129 -> V_132 = 0 ;
F_34 ( V_129 -> V_59 , V_51 -> V_59 ) ;
V_129 -> V_30 = ( V_51 -> V_30 == V_39 ) ? 0 : V_51 -> V_30 ;
V_129 -> V_102 = 0 ;
F_4 ( V_5 , V_123 ,
V_124 ,
V_8 -> V_12 ,
V_125 , V_61 ) ;
F_3 ( V_5 , V_126 ,
V_133 ) ;
V_17 = F_5 ( V_2 , V_127 , V_5 , sizeof( V_5 ) ,
V_33 , sizeof( V_33 ) , & V_35 ) ;
if ( V_17 )
return V_17 ;
if ( V_35 < V_130 )
return - V_45 ;
V_129 -> V_134 = F_13 ( V_33 , V_135 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! F_72 ( V_8 -> V_3 ) )
return - V_62 ;
V_137 -> V_138 = V_101 ;
memcpy ( V_137 -> V_139 , V_8 -> V_3 , V_137 -> V_138 ) ;
return 0 ;
}
