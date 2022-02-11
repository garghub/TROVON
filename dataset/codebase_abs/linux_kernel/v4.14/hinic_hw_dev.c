static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 , V_8 , V_9 ;
if ( ! F_2 ( V_2 -> V_10 ) && ! F_3 ( V_2 -> V_10 ) )
return - V_11 ;
if ( V_4 -> V_12 != V_13 )
return - V_14 ;
V_7 = F_4 ( V_2 -> V_10 ) ;
V_8 = F_5 ( V_2 -> V_10 ) ;
V_9 = F_6 ( V_2 -> V_10 ) ;
V_6 -> V_15 = ( V_9 - ( V_7 + V_8 ) ) / 2 ;
if ( V_6 -> V_15 > V_16 )
V_6 -> V_15 = V_16 ;
V_6 -> V_15 = F_7 ( F_8 ( V_6 -> V_15 ) - 1 ) ;
V_6 -> V_17 = V_4 -> V_18 + 1 ;
if ( V_6 -> V_17 != ( V_4 -> V_19 + 1 ) )
return - V_14 ;
if ( V_6 -> V_15 > V_6 -> V_17 )
V_6 -> V_15 = V_6 -> V_17 ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_3 V_4 ;
T_1 V_25 , V_26 ;
int V_27 ;
V_25 = 0 ;
V_26 = sizeof( V_4 ) ;
V_27 = F_10 ( & V_21 -> V_28 , V_29 ,
V_30 , & V_4 , V_25 , & V_4 ,
& V_26 , V_31 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_1 ) ;
return V_27 ;
}
return F_1 ( V_2 , & V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
int V_27 ;
switch ( F_13 ( V_10 ) ) {
case V_33 :
case V_34 :
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_27 = F_9 ( V_21 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_1 ) ;
return V_27 ;
}
break;
default:
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
int V_35 , V_7 , V_8 ;
T_2 V_36 ;
int V_37 , V_27 ;
V_7 = F_4 ( V_10 ) ;
V_8 = F_5 ( V_10 ) ;
V_35 = F_16 ( V_38 , V_7 , V_8 ) ;
if ( V_35 > F_6 ( V_10 ) )
V_35 = F_6 ( V_10 ) ;
V_36 = V_35 * sizeof( * V_2 -> V_39 ) ;
V_2 -> V_39 = F_17 ( & V_24 -> V_32 , V_36 ,
V_40 ) ;
if ( ! V_2 -> V_39 )
return - V_41 ;
for ( V_37 = 0 ; V_37 < V_35 ; V_37 ++ )
V_2 -> V_39 [ V_37 ] . V_42 = V_37 ;
V_27 = F_18 ( V_24 , V_2 -> V_39 , V_35 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_3 ) ;
return V_27 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
F_20 ( V_24 ) ;
}
int F_21 ( struct V_1 * V_2 , enum V_43 V_44 ,
void * V_45 , T_1 V_46 , void * V_47 , T_1 * V_48 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_4 ) ;
return - V_11 ;
}
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
return F_10 ( & V_21 -> V_28 , V_49 , V_44 ,
V_45 , V_46 , V_47 , V_48 ,
V_31 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_50 V_51 ;
struct V_20 * V_21 ;
T_1 V_48 ;
int V_27 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_51 . V_52 = F_23 ( V_10 ) ;
V_51 . V_53 = V_54 ;
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_27 = F_21 ( V_2 , V_55 ,
& V_51 , sizeof( V_51 ) ,
& V_51 , & V_48 ) ;
if ( V_27 || ( V_48 != sizeof( V_51 ) ) || V_51 . V_56 ) {
F_11 ( & V_24 -> V_32 , L_5 ,
V_51 . V_56 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_57 ,
unsigned int V_58 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_59 V_60 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_60 . V_52 = F_23 ( V_10 ) ;
V_60 . V_61 = V_62 ;
V_60 . V_63 = 0 ;
V_60 . V_57 = F_25 ( V_57 ) ;
V_60 . V_64 = V_65 ;
V_60 . V_58 = F_25 ( V_58 ) ;
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
return F_10 ( & V_21 -> V_28 , V_66 ,
V_67 ,
& V_60 , sizeof( V_60 ) , NULL ,
NULL , V_31 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
enum V_68 V_69 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
unsigned long V_70 ;
V_70 = V_71 + F_27 ( V_72 ) ;
do {
V_69 = F_28 ( V_10 ) ;
if ( V_69 == V_73 )
return 0 ;
F_29 ( 20 ) ;
} while ( F_30 ( V_71 , V_70 ) );
F_11 ( & V_24 -> V_32 , L_6 ) ;
return - V_14 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
enum V_74 V_75 ;
unsigned long V_70 ;
V_70 = V_71 + F_27 ( V_76 ) ;
do {
V_75 = F_32 ( V_10 ) ;
if ( V_75 == V_77 )
return 0 ;
F_29 ( 20 ) ;
} while ( F_30 ( V_71 , V_70 ) );
F_11 ( & V_24 -> V_32 , L_7 ) ;
return - V_14 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_78 V_79 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
unsigned long V_70 ;
T_1 V_48 ;
int V_27 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_79 . V_52 = F_23 ( V_10 ) ;
V_70 = V_71 + F_27 ( V_80 ) ;
do {
V_27 = F_10 ( & V_21 -> V_28 , V_66 ,
V_81 ,
& V_79 , sizeof( V_79 ) ,
& V_79 , & V_48 ,
V_31 ) ;
if ( ( V_27 ) || ( V_48 != sizeof( V_79 ) ) ) {
F_11 ( & V_24 -> V_32 , L_8 ,
V_27 ) ;
return V_27 ;
}
if ( V_79 . V_56 == V_82 ) {
F_34 ( & V_24 -> V_32 , L_9 ) ;
return 0 ;
}
F_29 ( 20 ) ;
} while ( F_30 ( V_71 , V_70 ) );
F_11 ( & V_24 -> V_32 , L_10 ) ;
return - V_83 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_84 V_85 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
int V_27 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_27 = F_33 ( V_2 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_11 ) ;
return V_27 ;
}
V_85 . V_52 = F_23 ( V_10 ) ;
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_27 = F_10 ( & V_21 -> V_28 , V_66 ,
V_86 , & V_85 ,
sizeof( V_85 ) , NULL , NULL ,
V_31 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_12 ) ;
return V_27 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_87 V_88 )
{
struct V_89 V_90 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_90 . V_52 = F_23 ( V_10 ) ;
V_90 . V_88 = V_88 ;
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
return F_10 ( & V_21 -> V_28 ,
V_66 ,
V_91 ,
& V_90 , sizeof( V_90 ) , NULL ,
NULL , V_31 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 * V_92 )
{
struct V_93 V_94 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
T_1 V_48 ;
int V_27 ;
V_94 . V_52 = F_23 ( V_10 ) ;
V_27 = F_21 ( V_2 , V_95 ,
& V_94 , sizeof( V_94 ) ,
& V_94 , & V_48 ) ;
if ( V_27 || ( V_48 != sizeof( V_94 ) ) || V_94 . V_56 ) {
F_11 ( & V_24 -> V_32 , L_13 ,
V_94 . V_56 ) ;
return - V_14 ;
}
* V_92 = V_94 . V_96 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_22 * V_10 = V_2 -> V_10 ;
int V_27 , V_7 , V_8 , V_15 ;
struct V_99 * V_100 ;
struct V_99 * V_101 ;
struct V_99 * V_102 ;
struct V_23 * V_24 = V_10 -> V_24 ;
T_1 V_92 ;
V_27 = F_37 ( V_2 , & V_92 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_14 ) ;
return V_27 ;
}
V_7 = F_4 ( V_10 ) ;
V_8 = F_5 ( V_10 ) ;
V_100 = & V_2 -> V_39 [ V_7 ] ;
V_27 = F_39 ( V_98 , V_10 , V_6 -> V_17 , V_8 ,
V_100 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_15 ) ;
return V_27 ;
}
V_15 = V_6 -> V_15 ;
V_101 = & V_2 -> V_39 [ V_7 + V_8 ] ;
V_102 = & V_2 -> V_39 [ V_7 + V_8 + V_15 ] ;
V_27 = F_40 ( V_98 , V_92 , V_15 ,
V_101 , V_102 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_16 ) ;
goto V_103;
}
V_27 = F_31 ( V_2 ) ;
if ( V_27 ) {
F_41 ( & V_24 -> V_32 , L_17 ) ;
F_42 ( V_10 , V_77 ) ;
}
V_27 = F_24 ( V_2 , V_104 , V_105 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_18 ) ;
goto V_106;
}
return 0 ;
V_106:
F_43 ( V_98 , V_15 ) ;
V_103:
F_44 ( V_98 ) ;
return V_27 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_35 ( V_2 ) ;
F_43 ( V_98 , V_6 -> V_15 ) ;
F_44 ( V_98 ) ;
}
void F_46 ( struct V_1 * V_2 ,
enum V_107 V_44 , void * V_108 ,
void (* F_47)( void * V_108 , void * V_45 ,
T_1 V_46 , void * V_47 ,
T_1 * V_48 ) )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
struct V_109 * V_110 ;
T_3 V_111 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_4 ) ;
return;
}
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_111 = V_44 - V_112 ;
V_110 = & V_21 -> V_110 [ V_111 ] ;
V_110 -> F_47 = F_47 ;
V_110 -> V_108 = V_108 ;
V_110 -> V_113 = V_114 ;
}
void F_48 ( struct V_1 * V_2 ,
enum V_107 V_44 )
{
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
struct V_109 * V_110 ;
T_3 V_111 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_4 ) ;
return;
}
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
V_111 = V_44 - V_112 ;
V_110 = & V_21 -> V_110 [ V_111 ] ;
V_110 -> V_113 &= ~ V_114 ;
while ( V_110 -> V_113 & V_115 )
F_49 () ;
V_110 -> F_47 = NULL ;
}
static void F_50 ( void * V_108 , T_3 V_44 , void * V_45 ,
T_1 V_46 , void * V_47 , T_1 * V_48 )
{
struct V_20 * V_21 = V_108 ;
enum V_116 V_113 ;
struct V_109 * V_110 ;
struct V_1 * V_2 ;
struct V_22 * V_10 ;
struct V_23 * V_24 ;
T_3 V_111 ;
V_2 = & V_21 -> V_2 ;
V_10 = V_2 -> V_10 ;
V_24 = V_10 -> V_24 ;
if ( ( V_44 < V_112 ) ||
( V_44 >= V_117 ) ) {
F_11 ( & V_24 -> V_32 , L_19 , V_44 ) ;
return;
}
V_111 = V_44 - V_112 ;
V_110 = & V_21 -> V_110 [ V_111 ] ;
V_113 = F_51 ( & V_110 -> V_113 ,
V_114 ,
V_114 | V_115 ) ;
if ( ( V_113 == V_114 ) && ( V_110 -> F_47 ) )
V_110 -> F_47 ( V_110 -> V_108 , V_45 ,
V_46 , V_47 , V_48 ) ;
else
F_11 ( & V_24 -> V_32 , L_20 , V_44 ) ;
V_110 -> V_113 &= ~ V_115 ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
int V_27 ;
V_27 = F_53 ( & V_21 -> V_28 , V_10 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_21 ) ;
return V_27 ;
}
F_54 ( & V_21 -> V_28 , V_49 ,
V_21 , F_50 ) ;
F_55 ( V_10 , V_118 ) ;
return 0 ;
}
static void F_56 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
F_55 ( V_2 -> V_10 , V_119 ) ;
F_57 ( & V_21 -> V_28 , V_49 ) ;
F_58 ( & V_21 -> V_28 ) ;
}
struct V_1 * F_59 ( struct V_23 * V_24 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_10 ;
int V_27 , V_7 ;
V_10 = F_17 ( & V_24 -> V_32 , sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
return F_60 ( - V_41 ) ;
V_27 = F_61 ( V_10 , V_24 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_22 ) ;
return F_60 ( V_27 ) ;
}
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
V_27 = - V_14 ;
goto V_120;
}
V_21 = F_17 ( & V_24 -> V_32 , sizeof( * V_21 ) , V_40 ) ;
if ( ! V_21 ) {
V_27 = - V_41 ;
goto V_121;
}
V_2 = & V_21 -> V_2 ;
V_2 -> V_10 = V_10 ;
V_27 = F_15 ( V_2 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_23 ) ;
goto V_122;
}
V_27 = F_26 ( V_2 ) ;
if ( V_27 ) {
F_41 ( & V_24 -> V_32 , L_24 ) ;
F_62 ( V_10 , V_73 ) ;
}
V_7 = F_4 ( V_10 ) ;
V_27 = F_63 ( & V_2 -> V_123 , V_10 , V_7 ,
V_124 , V_125 ,
V_2 -> V_39 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_25 ) ;
goto V_126;
}
V_27 = F_52 ( V_21 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_26 ) ;
goto V_127;
}
V_27 = F_12 ( V_2 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_27 ) ;
goto V_128;
}
V_27 = F_22 ( V_2 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_28 ) ;
goto V_129;
}
V_27 = F_36 ( V_2 , V_130 ) ;
if ( V_27 ) {
F_11 ( & V_24 -> V_32 , L_29 ) ;
goto V_131;
}
return V_2 ;
V_131:
V_129:
V_128:
F_56 ( V_21 ) ;
V_127:
F_64 ( & V_2 -> V_123 ) ;
V_126:
F_19 ( V_2 ) ;
V_122:
V_121:
V_120:
F_65 ( V_10 ) ;
return F_60 ( V_27 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_14 ( V_2 ,
struct V_20 ,
V_2 ) ;
F_36 ( V_2 , V_132 ) ;
F_56 ( V_21 ) ;
F_64 ( & V_2 -> V_123 ) ;
F_19 ( V_2 ) ;
F_65 ( V_2 -> V_10 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
return V_6 -> V_15 ;
}
struct V_133 * F_68 ( struct V_1 * V_2 , int V_37 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_134 * V_135 = & V_98 -> V_136 [ V_37 ] ;
if ( V_37 >= F_67 ( V_2 ) )
return NULL ;
return & V_135 -> V_137 ;
}
struct V_138 * F_69 ( struct V_1 * V_2 , int V_37 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_134 * V_135 = & V_98 -> V_136 [ V_37 ] ;
if ( V_37 >= F_67 ( V_2 ) )
return NULL ;
return & V_135 -> V_139 ;
}
int F_70 ( struct V_1 * V_2 , T_1 V_140 )
{
return F_71 ( V_2 -> V_10 , V_140 ) ;
}
int F_72 ( struct V_1 * V_2 , T_1 V_140 ,
T_3 V_141 , T_3 V_142 ,
T_3 V_143 , T_3 V_144 ,
T_3 V_145 )
{
return F_73 ( V_2 -> V_10 , V_140 ,
V_141 , V_142 ,
V_143 , V_144 ,
V_145 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_133 * V_137 ,
T_3 V_141 , T_3 V_142 )
{
struct V_134 * V_135 = F_14 ( V_137 , struct V_134 , V_137 ) ;
struct V_22 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_24 ;
struct V_20 * V_21 ;
struct V_146 V_147 ;
if ( ! F_2 ( V_10 ) && ! F_3 ( V_10 ) ) {
F_11 ( & V_24 -> V_32 , L_2 ) ;
return - V_11 ;
}
V_147 . V_148 = 0 ;
V_147 . V_141 = V_141 ;
V_147 . V_142 = V_142 ;
V_147 . V_149 = 1 ;
V_147 . V_150 = V_137 -> V_99 ;
V_147 . V_52 = F_23 ( V_10 ) ;
V_147 . V_151 = V_135 -> V_152 ;
V_147 . V_153 = F_75 ( V_137 -> V_154 ) ;
V_21 = F_14 ( V_2 , struct V_20 , V_2 ) ;
return F_10 ( & V_21 -> V_28 ,
V_66 ,
V_155 ,
& V_147 , sizeof( V_147 ) , NULL ,
NULL , V_31 ) ;
}
