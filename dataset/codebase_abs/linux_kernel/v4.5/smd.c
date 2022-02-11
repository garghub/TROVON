static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 -> V_5 , V_4 -> V_6 , F_3 ( V_4 -> V_7 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_8 , V_9 ) ;
F_6 ( V_2 , V_10 , 0 ) ;
F_6 ( V_2 , V_11 , 0 ) ;
F_6 ( V_2 , V_12 , 0 ) ;
F_6 ( V_2 , V_13 , 0 ) ;
F_6 ( V_2 , V_14 , 0 ) ;
F_6 ( V_2 , V_15 , 0 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
F_6 ( V_2 , V_17 , 1 ) ;
F_5 ( V_2 , V_18 , 0 ) ;
F_5 ( V_2 , V_19 , 0 ) ;
F_1 ( V_2 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_20 = 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
V_18 = F_8 ( V_2 , V_18 ) ;
V_19 = F_8 ( V_2 , V_19 ) ;
return ( V_18 - V_19 ) & ( V_2 -> V_21 - 1 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_22 = V_8 == V_23 ;
if ( V_2 -> V_8 == V_8 )
return;
F_10 ( V_4 -> V_24 -> V_25 , L_1 , V_2 -> V_26 , V_8 ) ;
F_6 ( V_2 , V_10 , V_22 ) ;
F_6 ( V_2 , V_11 , V_22 ) ;
F_6 ( V_2 , V_12 , V_22 ) ;
F_5 ( V_2 , V_8 , V_8 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
V_2 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_11 ( void T_2 * V_27 ,
const void * V_28 ,
T_1 V_29 ,
bool V_30 )
{
if ( V_30 ) {
F_12 ( V_27 , V_28 , V_29 / sizeof( V_31 ) ) ;
} else {
F_13 ( V_27 , V_28 , V_29 ) ;
}
}
static void F_14 ( void * V_27 ,
const void T_2 * V_28 ,
T_1 V_29 ,
bool V_30 )
{
if ( V_30 ) {
F_15 ( V_27 , V_28 , V_29 / sizeof( V_31 ) ) ;
} else {
F_16 ( V_27 , V_28 , V_29 ) ;
}
}
static T_1 F_17 ( struct V_1 * V_2 ,
void * V_32 , T_1 V_29 )
{
bool V_30 ;
unsigned V_19 ;
T_1 V_33 ;
V_30 = V_2 -> V_34 ;
V_19 = F_8 ( V_2 , V_19 ) ;
V_33 = F_18 ( T_1 , V_29 , V_2 -> V_21 - V_19 ) ;
if ( V_33 ) {
F_14 ( V_32 ,
V_2 -> V_35 + V_19 ,
V_33 ,
V_30 ) ;
}
if ( V_33 != V_29 ) {
F_14 ( V_32 + V_33 ,
V_2 -> V_35 ,
V_29 - V_33 ,
V_30 ) ;
}
return V_29 ;
}
static void F_19 ( struct V_1 * V_2 ,
T_1 V_29 )
{
unsigned V_19 ;
V_19 = F_8 ( V_2 , V_19 ) ;
V_19 += V_29 ;
V_19 &= ( V_2 -> V_21 - 1 ) ;
F_20 ( V_2 , V_19 , V_19 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
unsigned V_19 ;
T_1 V_33 ;
void * V_38 ;
int V_39 ;
if ( ! V_2 -> V_40 )
return 0 ;
V_19 = F_8 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_21 ) {
V_38 = V_2 -> V_41 ;
V_33 = F_17 ( V_2 , V_38 , V_2 -> V_20 ) ;
} else {
V_38 = V_2 -> V_35 + V_19 ;
V_33 = V_2 -> V_20 ;
}
V_39 = V_2 -> V_40 ( V_37 , V_38 , V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
F_19 ( V_2 , V_33 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
bool V_42 = false ;
int V_43 ;
T_3 V_44 ;
int V_45 ;
int V_39 ;
V_43 = F_8 ( V_2 , V_8 ) ;
if ( V_43 != V_2 -> V_43 ) {
V_2 -> V_43 = V_43 ;
V_42 = true ;
}
F_23 ( V_2 , V_16 , 0 ) ;
if ( ! F_24 ( V_2 , V_17 ) )
F_25 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_8 != V_23 )
goto V_47;
F_23 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_45 = F_7 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_45 >= V_48 ) {
F_17 ( V_2 , & V_44 , sizeof( V_44 ) ) ;
F_19 ( V_2 , V_48 ) ;
V_2 -> V_20 = F_26 ( V_44 ) ;
} else if ( V_2 -> V_20 && V_45 >= V_2 -> V_20 ) {
V_39 = F_21 ( V_2 ) ;
if ( V_39 )
break;
} else {
break;
}
}
F_23 ( V_2 , V_15 , 1 ) ;
if ( ! F_27 ( V_2 , V_17 ) ) {
F_28 () ;
F_1 ( V_2 ) ;
}
V_47:
return V_42 ;
}
static T_4 F_29 ( int V_49 , void * V_50 )
{
struct V_3 * V_4 = V_50 ;
struct V_1 * V_2 ;
unsigned V_51 ;
bool V_52 = false ;
F_30 ( & V_4 -> V_53 ) ;
F_31 (channel, &edge->channels, list) {
F_30 ( & V_2 -> V_54 ) ;
V_52 |= F_22 ( V_2 ) ;
F_32 ( & V_2 -> V_54 ) ;
}
F_32 ( & V_4 -> V_53 ) ;
V_51 = F_33 ( V_4 -> V_55 ) ;
if ( V_51 != V_4 -> V_56 ) {
V_4 -> V_56 = V_51 ;
V_4 -> V_57 = true ;
V_52 = true ;
}
if ( V_52 )
F_34 ( & V_4 -> V_58 ) ;
return V_59 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned long V_60 ;
F_36 ( & V_2 -> V_54 , V_60 ) ;
F_22 ( V_2 ) ;
F_37 ( & V_2 -> V_54 , V_60 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_61 = V_2 -> V_21 - 1 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_19 = F_39 ( V_2 , V_19 ) ;
return V_61 - ( ( V_18 - V_19 ) & V_61 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const void * V_50 ,
T_1 V_29 )
{
bool V_30 ;
unsigned V_18 ;
T_1 V_33 ;
V_30 = V_2 -> V_34 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_33 = F_18 ( T_1 , V_29 , V_2 -> V_21 - V_18 ) ;
if ( V_33 ) {
F_11 ( V_2 -> V_62 + V_18 ,
V_50 ,
V_33 ,
V_30 ) ;
}
if ( V_33 != V_29 ) {
F_11 ( V_2 -> V_62 ,
V_50 + V_33 ,
V_29 - V_33 ,
V_30 ) ;
}
V_18 += V_29 ;
V_18 &= ( V_2 -> V_21 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_29 ;
}
int F_41 ( struct V_1 * V_2 , const void * V_50 , int V_33 )
{
T_3 V_63 [ 5 ] = { F_42 ( V_33 ) , } ;
int V_64 = sizeof( V_63 ) + V_33 ;
int V_39 ;
if ( V_2 -> V_34 && V_33 % 4 )
return - V_65 ;
if ( V_64 >= V_2 -> V_21 )
return - V_65 ;
V_39 = F_43 ( & V_2 -> V_66 ) ;
if ( V_39 )
return V_39 ;
while ( F_38 ( V_2 ) < V_64 ) {
if ( V_2 -> V_8 != V_23 ) {
V_39 = - V_67 ;
goto V_47;
}
F_6 ( V_2 , V_17 , 0 ) ;
V_39 = F_44 ( V_2 -> V_46 ,
F_38 ( V_2 ) >= V_64 ||
V_2 -> V_8 != V_23 ) ;
if ( V_39 )
goto V_47;
F_6 ( V_2 , V_17 , 1 ) ;
}
F_6 ( V_2 , V_15 , 0 ) ;
F_40 ( V_2 , V_63 , sizeof( V_63 ) ) ;
F_40 ( V_2 , V_50 , V_33 ) ;
F_6 ( V_2 , V_14 , 1 ) ;
F_28 () ;
F_1 ( V_2 ) ;
V_47:
F_45 ( & V_2 -> V_66 ) ;
return V_39 ;
}
static struct V_36 * F_46 ( struct V_68 * V_25 )
{
return F_47 ( V_25 , struct V_36 , V_25 ) ;
}
static struct V_69 * F_48 ( struct V_68 * V_25 )
{
struct V_36 * V_37 = F_46 ( V_25 ) ;
return F_47 ( V_37 -> V_25 . V_70 , struct V_69 , V_70 ) ;
}
static int F_49 ( struct V_68 * V_25 , struct V_71 * V_72 )
{
struct V_36 * V_37 = F_46 ( V_25 ) ;
struct V_69 * V_73 = F_47 ( V_72 , struct V_69 , V_70 ) ;
const struct V_74 * V_75 = V_73 -> V_76 ;
const char * V_26 = V_37 -> V_2 -> V_26 ;
if ( V_75 ) {
while ( V_75 -> V_26 [ 0 ] ) {
if ( ! strcmp ( V_75 -> V_26 , V_26 ) )
return 1 ;
V_75 ++ ;
}
}
return F_50 ( V_25 , V_72 ) ;
}
static int F_51 ( struct V_68 * V_25 )
{
struct V_36 * V_37 = F_46 ( V_25 ) ;
struct V_69 * V_73 = F_48 ( V_25 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_77 ;
int V_39 ;
V_77 = F_52 ( V_2 -> V_21 , V_78 ) ;
V_2 -> V_41 = F_53 ( V_77 , V_79 ) ;
if ( ! V_2 -> V_41 )
return - V_80 ;
V_2 -> V_40 = V_73 -> V_81 ;
F_9 ( V_2 , V_82 ) ;
F_9 ( V_2 , V_23 ) ;
V_39 = V_73 -> V_83 ( V_37 ) ;
if ( V_39 )
goto V_84;
F_35 ( V_2 ) ;
return 0 ;
V_84:
F_54 ( & V_37 -> V_25 , L_2 ) ;
V_2 -> V_40 = NULL ;
F_55 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
F_9 ( V_2 , V_9 ) ;
return V_39 ;
}
static int F_56 ( struct V_68 * V_25 )
{
struct V_36 * V_37 = F_46 ( V_25 ) ;
struct V_69 * V_73 = F_48 ( V_25 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
unsigned long V_60 ;
F_9 ( V_2 , V_85 ) ;
F_36 ( & V_2 -> V_54 , V_60 ) ;
V_2 -> V_40 = NULL ;
F_37 ( & V_2 -> V_54 , V_60 ) ;
F_25 ( & V_2 -> V_46 ) ;
if ( V_73 -> remove )
V_73 -> remove ( V_37 ) ;
V_2 -> V_37 = NULL ;
F_55 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
F_9 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_68 * V_25 )
{
struct V_36 * V_37 = F_46 ( V_25 ) ;
F_55 ( V_37 ) ;
}
static struct V_86 * F_58 ( struct V_86 * V_87 ,
const char * V_2 )
{
struct V_86 * V_88 ;
const char * V_26 ;
const char * V_89 ;
int V_39 ;
F_59 (edge_node, child) {
V_89 = L_3 ;
V_39 = F_60 ( V_88 , V_89 , & V_26 ) ;
if ( V_39 )
continue;
if ( strcmp ( V_26 , V_2 ) == 0 )
return V_88 ;
}
return NULL ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_86 * V_90 ;
struct V_91 * V_24 = V_4 -> V_24 ;
int V_39 ;
if ( V_2 -> V_37 )
return - V_92 ;
F_10 ( V_24 -> V_25 , L_4 , V_2 -> V_26 ) ;
V_37 = F_62 ( sizeof( * V_37 ) , V_79 ) ;
if ( ! V_37 )
return - V_80 ;
V_90 = F_58 ( V_4 -> V_93 , V_2 -> V_26 ) ;
F_63 ( & V_37 -> V_25 , L_5 ,
V_4 -> V_93 -> V_26 ,
V_90 ? V_90 -> V_26 : V_2 -> V_26 ) ;
V_37 -> V_25 . V_94 = V_24 -> V_25 ;
V_37 -> V_25 . V_95 = & V_96 ;
V_37 -> V_25 . V_97 = F_57 ;
V_37 -> V_25 . V_93 = V_90 ;
V_37 -> V_2 = V_2 ;
V_2 -> V_37 = V_37 ;
V_39 = F_64 ( & V_37 -> V_25 ) ;
if ( V_39 ) {
F_54 ( V_24 -> V_25 , L_6 , V_39 ) ;
F_65 ( & V_37 -> V_25 ) ;
}
return V_39 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_68 * V_25 ;
F_67 ( ! V_2 -> V_37 ) ;
V_25 = & V_2 -> V_37 -> V_25 ;
F_68 ( V_25 ) ;
F_69 ( V_25 -> V_93 ) ;
F_65 ( V_25 ) ;
}
int F_70 ( struct V_69 * V_73 )
{
V_73 -> V_70 . V_95 = & V_96 ;
return F_71 ( & V_73 -> V_70 ) ;
}
void F_72 ( struct V_69 * V_73 )
{
F_73 ( & V_73 -> V_70 ) ;
}
static struct V_1 * F_74 ( struct V_3 * V_4 ,
unsigned V_98 ,
unsigned V_99 ,
char * V_26 )
{
struct V_1 * V_2 ;
struct V_91 * V_24 = V_4 -> V_24 ;
T_1 V_21 ;
T_1 V_100 ;
void * V_101 ;
void * V_102 ;
int V_39 ;
V_2 = F_75 ( V_24 -> V_25 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_76 ( - V_80 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_26 = F_77 ( V_24 -> V_25 , V_26 , V_79 ) ;
if ( ! V_2 -> V_26 )
return F_76 ( - V_80 ) ;
F_78 ( & V_2 -> V_66 ) ;
F_79 ( & V_2 -> V_54 ) ;
F_80 ( & V_2 -> V_46 ) ;
V_102 = F_81 ( V_4 -> V_55 , V_98 , & V_100 ) ;
if ( F_82 ( V_102 ) ) {
V_39 = F_83 ( V_102 ) ;
goto V_103;
}
if ( V_100 == 2 * sizeof( struct V_104 ) ) {
V_2 -> V_34 = V_102 ;
} else if ( V_100 == 2 * sizeof( struct V_105 ) ) {
V_2 -> V_102 = V_102 ;
} else {
F_54 ( V_24 -> V_25 ,
L_7 , V_100 ) ;
V_39 = - V_65 ;
goto V_103;
}
V_101 = F_81 ( V_4 -> V_55 , V_99 , & V_21 ) ;
if ( F_82 ( V_101 ) ) {
V_39 = F_83 ( V_101 ) ;
goto V_103;
}
V_21 /= 2 ;
F_10 ( V_24 -> V_25 , L_8 ,
V_26 , V_100 , V_21 ) ;
V_2 -> V_62 = V_101 ;
V_2 -> V_35 = V_101 + V_21 ;
V_2 -> V_21 = V_21 ;
F_4 ( V_2 ) ;
return V_2 ;
V_103:
F_84 ( V_24 -> V_25 , V_2 -> V_26 ) ;
F_84 ( V_24 -> V_25 , V_2 ) ;
return F_76 ( V_39 ) ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_106 * V_107 ;
struct V_106 * V_108 ;
struct V_1 * V_2 ;
struct V_91 * V_24 = V_4 -> V_24 ;
unsigned long V_60 ;
unsigned V_109 ;
unsigned V_110 ;
int V_111 ;
int V_112 ;
V_31 V_113 , V_114 ;
for ( V_111 = 0 ; V_111 < V_115 ; V_111 ++ ) {
V_107 = F_81 ( V_4 -> V_55 ,
V_116 [ V_111 ] . V_117 , NULL ) ;
if ( F_82 ( V_107 ) )
continue;
for ( V_112 = 0 ; V_112 < V_118 ; V_112 ++ ) {
V_108 = & V_107 [ V_112 ] ;
V_113 = F_26 ( V_108 -> V_60 ) ;
if ( F_86 ( V_112 , V_4 -> V_119 [ V_111 ] ) )
continue;
if ( V_108 -> V_120 == 0 )
continue;
if ( ! V_108 -> V_26 [ 0 ] )
continue;
if ( ! ( V_113 & V_121 ) )
continue;
if ( ( V_113 & V_122 ) != V_4 -> V_123 )
continue;
V_114 = F_26 ( V_108 -> V_114 ) ;
V_110 = V_116 [ V_111 ] . V_124 + V_114 ;
V_109 = V_116 [ V_111 ] . V_125 + V_114 ;
V_2 = F_74 ( V_4 , V_110 , V_109 , V_108 -> V_26 ) ;
if ( F_82 ( V_2 ) )
continue;
F_36 ( & V_4 -> V_53 , V_60 ) ;
F_87 ( & V_2 -> V_126 , & V_4 -> V_127 ) ;
F_37 ( & V_4 -> V_53 , V_60 ) ;
F_10 ( V_24 -> V_25 , L_9 , V_2 -> V_26 ) ;
F_88 ( V_112 , V_4 -> V_119 [ V_111 ] ) ;
}
}
F_34 ( & V_4 -> V_58 ) ;
}
static void F_89 ( struct V_128 * V_58 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_47 ( V_58 ,
struct V_3 ,
V_58 ) ;
unsigned V_43 ;
if ( V_4 -> V_57 ) {
V_4 -> V_57 = false ;
F_85 ( V_4 ) ;
}
F_31 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_43 = F_8 ( V_2 , V_8 ) ;
if ( V_43 != V_82 &&
V_43 != V_23 )
continue;
F_61 ( V_2 ) ;
}
F_31 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_82 &&
V_2 -> V_8 != V_23 )
continue;
V_43 = F_8 ( V_2 , V_8 ) ;
if ( V_43 == V_82 ||
V_43 == V_23 )
continue;
F_66 ( V_2 ) ;
}
}
static int F_90 ( struct V_68 * V_25 ,
struct V_86 * V_90 ,
struct V_3 * V_4 )
{
struct V_86 * V_129 ;
const char * V_89 ;
int V_49 ;
int V_39 ;
F_91 ( & V_4 -> V_127 ) ;
F_79 ( & V_4 -> V_53 ) ;
F_92 ( & V_4 -> V_58 , F_89 ) ;
V_4 -> V_93 = F_93 ( V_90 ) ;
V_49 = F_94 ( V_90 , 0 ) ;
if ( V_49 < 0 ) {
F_54 ( V_25 , L_10 ) ;
return - V_65 ;
}
V_39 = F_95 ( V_25 , V_49 ,
F_29 , V_130 ,
V_90 -> V_26 , V_4 ) ;
if ( V_39 ) {
F_54 ( V_25 , L_11 ) ;
return V_39 ;
}
V_4 -> V_49 = V_49 ;
V_89 = L_12 ;
V_39 = F_96 ( V_90 , V_89 , & V_4 -> V_123 ) ;
if ( V_39 ) {
F_54 ( V_25 , L_13 , V_89 ) ;
return - V_65 ;
}
V_4 -> V_55 = V_131 ;
V_89 = L_14 ;
F_96 ( V_90 , V_89 , & V_4 -> V_55 ) ;
V_129 = F_97 ( V_90 , L_15 , 0 ) ;
if ( ! V_129 ) {
F_54 ( V_25 , L_16 ) ;
return - V_132 ;
}
V_4 -> V_5 = F_98 ( V_129 ) ;
if ( F_82 ( V_4 -> V_5 ) )
return F_83 ( V_4 -> V_5 ) ;
V_89 = L_15 ;
V_39 = F_99 ( V_90 , V_89 , 1 , & V_4 -> V_6 ) ;
if ( V_39 < 0 ) {
F_54 ( V_25 , L_17 , V_89 ) ;
return - V_65 ;
}
V_39 = F_99 ( V_90 , V_89 , 2 , & V_4 -> V_7 ) ;
if ( V_39 < 0 ) {
F_54 ( V_25 , L_18 , V_89 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_100 ( struct V_133 * V_134 )
{
struct V_3 * V_4 ;
struct V_86 * V_90 ;
struct V_91 * V_24 ;
T_1 V_135 ;
int V_136 ;
int V_39 ;
int V_112 = 0 ;
void * V_137 ;
V_137 = F_81 ( V_131 , V_116 [ 0 ] . V_117 , NULL ) ;
if ( F_83 ( V_137 ) == - V_138 )
return F_83 ( V_137 ) ;
V_136 = F_101 ( V_134 -> V_25 . V_93 ) ;
V_135 = sizeof( * V_24 ) + V_136 * sizeof( struct V_3 ) ;
V_24 = F_75 ( & V_134 -> V_25 , V_135 , V_79 ) ;
if ( ! V_24 )
return - V_80 ;
V_24 -> V_25 = & V_134 -> V_25 ;
V_24 -> V_136 = V_136 ;
F_59 (pdev->dev.of_node, node) {
V_4 = & V_24 -> V_139 [ V_112 ++ ] ;
V_4 -> V_24 = V_24 ;
V_39 = F_90 ( & V_134 -> V_25 , V_90 , V_4 ) ;
if ( V_39 )
continue;
V_4 -> V_57 = true ;
F_34 ( & V_4 -> V_58 ) ;
}
F_102 ( V_134 , V_24 ) ;
return 0 ;
}
static int F_103 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_91 * V_24 = F_104 ( V_134 ) ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_24 -> V_136 ; V_112 ++ ) {
V_4 = & V_24 -> V_139 [ V_112 ] ;
F_105 ( V_4 -> V_49 ) ;
F_106 ( & V_4 -> V_58 ) ;
F_31 (channel, &edge->channels, list) {
if ( ! V_2 -> V_37 )
continue;
F_66 ( V_2 ) ;
}
}
return 0 ;
}
static int T_5 F_107 ( void )
{
int V_39 ;
V_39 = F_108 ( & V_96 ) ;
if ( V_39 ) {
F_109 ( L_19 , V_39 ) ;
return V_39 ;
}
return F_110 ( & V_69 ) ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_69 ) ;
F_113 ( & V_96 ) ;
}
