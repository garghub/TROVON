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
static void F_14 ( void * V_32 ,
const void T_2 * V_33 ,
T_1 V_29 ,
bool V_30 )
{
V_31 * V_27 = ( V_31 * ) V_32 ;
V_31 * V_28 = ( V_31 * ) V_33 ;
if ( V_30 ) {
V_29 /= sizeof( V_31 ) ;
while ( V_29 -- )
* V_27 ++ = F_15 ( V_28 ++ ) ;
} else {
F_16 ( V_32 , V_33 , V_29 ) ;
}
}
static T_1 F_17 ( struct V_1 * V_2 ,
void * V_34 , T_1 V_29 )
{
bool V_30 ;
unsigned V_19 ;
T_1 V_35 ;
V_30 = V_2 -> V_36 ;
V_19 = F_8 ( V_2 , V_19 ) ;
V_35 = F_18 ( T_1 , V_29 , V_2 -> V_21 - V_19 ) ;
if ( V_35 ) {
F_14 ( V_34 ,
V_2 -> V_37 + V_19 ,
V_35 ,
V_30 ) ;
}
if ( V_35 != V_29 ) {
F_14 ( V_34 + V_35 ,
V_2 -> V_37 ,
V_29 - V_35 ,
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
struct V_38 * V_39 = V_2 -> V_39 ;
unsigned V_19 ;
T_1 V_35 ;
void * V_40 ;
int V_41 ;
if ( ! V_2 -> V_42 )
return 0 ;
V_19 = F_8 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_21 ) {
V_40 = V_2 -> V_43 ;
V_35 = F_17 ( V_2 , V_40 , V_2 -> V_20 ) ;
} else {
V_40 = V_2 -> V_37 + V_19 ;
V_35 = V_2 -> V_20 ;
}
V_41 = V_2 -> V_42 ( V_39 , V_40 , V_35 ) ;
if ( V_41 < 0 )
return V_41 ;
F_19 ( V_2 , V_35 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
bool V_44 = false ;
int V_45 ;
T_3 V_46 ;
int V_47 ;
int V_41 ;
V_45 = F_8 ( V_2 , V_8 ) ;
if ( V_45 != V_2 -> V_45 ) {
V_2 -> V_45 = V_45 ;
V_44 = true ;
}
F_23 ( V_2 , V_16 , 0 ) ;
if ( ! F_24 ( V_2 , V_17 ) )
F_25 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_8 != V_23 )
goto V_49;
F_23 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_47 = F_7 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_47 >= V_50 ) {
F_17 ( V_2 , & V_46 , sizeof( V_46 ) ) ;
F_19 ( V_2 , V_50 ) ;
V_2 -> V_20 = F_26 ( V_46 ) ;
} else if ( V_2 -> V_20 && V_47 >= V_2 -> V_20 ) {
V_41 = F_21 ( V_2 ) ;
if ( V_41 )
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
V_49:
return V_44 ;
}
static T_4 F_29 ( int V_51 , void * V_52 )
{
struct V_3 * V_4 = V_52 ;
struct V_1 * V_2 ;
unsigned V_53 ;
bool V_54 = false ;
F_30 ( & V_4 -> V_55 ) ;
F_31 (channel, &edge->channels, list) {
F_30 ( & V_2 -> V_56 ) ;
V_54 |= F_22 ( V_2 ) ;
F_32 ( & V_2 -> V_56 ) ;
}
F_32 ( & V_4 -> V_55 ) ;
V_53 = F_33 ( V_4 -> V_57 ) ;
if ( V_53 != V_4 -> V_58 ) {
V_4 -> V_58 = V_53 ;
V_4 -> V_59 = true ;
V_54 = true ;
}
if ( V_54 )
F_34 ( & V_4 -> V_60 ) ;
return V_61 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_36 ( & V_2 -> V_56 , V_62 ) ;
F_22 ( V_2 ) ;
F_37 ( & V_2 -> V_56 , V_62 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_63 = V_2 -> V_21 - 1 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_19 = F_39 ( V_2 , V_19 ) ;
return V_63 - ( ( V_18 - V_19 ) & V_63 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const void * V_52 ,
T_1 V_29 )
{
bool V_30 ;
unsigned V_18 ;
T_1 V_35 ;
V_30 = V_2 -> V_36 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_35 = F_18 ( T_1 , V_29 , V_2 -> V_21 - V_18 ) ;
if ( V_35 ) {
F_11 ( V_2 -> V_64 + V_18 ,
V_52 ,
V_35 ,
V_30 ) ;
}
if ( V_35 != V_29 ) {
F_11 ( V_2 -> V_64 ,
V_52 + V_35 ,
V_29 - V_35 ,
V_30 ) ;
}
V_18 += V_29 ;
V_18 &= ( V_2 -> V_21 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_29 ;
}
int F_41 ( struct V_1 * V_2 , const void * V_52 , int V_35 )
{
T_3 V_65 [ 5 ] = { F_42 ( V_35 ) , } ;
int V_66 = sizeof( V_65 ) + V_35 ;
int V_41 ;
if ( V_2 -> V_36 && V_35 % 4 )
return - V_67 ;
if ( V_66 >= V_2 -> V_21 )
return - V_67 ;
V_41 = F_43 ( & V_2 -> V_68 ) ;
if ( V_41 )
return V_41 ;
while ( F_38 ( V_2 ) < V_66 ) {
if ( V_2 -> V_8 != V_23 ) {
V_41 = - V_69 ;
goto V_49;
}
F_6 ( V_2 , V_17 , 0 ) ;
V_41 = F_44 ( V_2 -> V_48 ,
F_38 ( V_2 ) >= V_66 ||
V_2 -> V_8 != V_23 ) ;
if ( V_41 )
goto V_49;
F_6 ( V_2 , V_17 , 1 ) ;
}
F_6 ( V_2 , V_15 , 0 ) ;
F_40 ( V_2 , V_65 , sizeof( V_65 ) ) ;
F_40 ( V_2 , V_52 , V_35 ) ;
F_6 ( V_2 , V_14 , 1 ) ;
F_28 () ;
F_1 ( V_2 ) ;
V_49:
F_45 ( & V_2 -> V_68 ) ;
return V_41 ;
}
static struct V_38 * F_46 ( struct V_70 * V_25 )
{
return F_47 ( V_25 , struct V_38 , V_25 ) ;
}
static struct V_71 * F_48 ( struct V_70 * V_25 )
{
struct V_38 * V_39 = F_46 ( V_25 ) ;
return F_47 ( V_39 -> V_25 . V_72 , struct V_71 , V_72 ) ;
}
static int F_49 ( struct V_70 * V_25 , struct V_73 * V_74 )
{
struct V_38 * V_39 = F_46 ( V_25 ) ;
struct V_71 * V_75 = F_47 ( V_74 , struct V_71 , V_72 ) ;
const struct V_76 * V_77 = V_75 -> V_78 ;
const char * V_26 = V_39 -> V_2 -> V_26 ;
if ( V_77 ) {
while ( V_77 -> V_26 [ 0 ] ) {
if ( ! strcmp ( V_77 -> V_26 , V_26 ) )
return 1 ;
V_77 ++ ;
}
}
return F_50 ( V_25 , V_74 ) ;
}
static int F_51 ( struct V_70 * V_25 )
{
struct V_38 * V_39 = F_46 ( V_25 ) ;
struct V_71 * V_75 = F_48 ( V_25 ) ;
struct V_1 * V_2 = V_39 -> V_2 ;
T_1 V_79 ;
int V_41 ;
V_79 = F_52 ( V_2 -> V_21 , V_80 ) ;
V_2 -> V_43 = F_53 ( V_79 , V_81 ) ;
if ( ! V_2 -> V_43 )
return - V_82 ;
V_2 -> V_42 = V_75 -> V_83 ;
F_9 ( V_2 , V_84 ) ;
F_9 ( V_2 , V_23 ) ;
V_41 = V_75 -> V_85 ( V_39 ) ;
if ( V_41 )
goto V_86;
F_35 ( V_2 ) ;
return 0 ;
V_86:
F_54 ( & V_39 -> V_25 , L_2 ) ;
V_2 -> V_42 = NULL ;
F_55 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_9 ( V_2 , V_9 ) ;
return V_41 ;
}
static int F_56 ( struct V_70 * V_25 )
{
struct V_38 * V_39 = F_46 ( V_25 ) ;
struct V_71 * V_75 = F_48 ( V_25 ) ;
struct V_1 * V_2 = V_39 -> V_2 ;
unsigned long V_62 ;
F_9 ( V_2 , V_87 ) ;
F_36 ( & V_2 -> V_56 , V_62 ) ;
V_2 -> V_42 = NULL ;
F_37 ( & V_2 -> V_56 , V_62 ) ;
F_25 ( & V_2 -> V_48 ) ;
if ( V_75 -> remove )
V_75 -> remove ( V_39 ) ;
V_2 -> V_39 = NULL ;
F_55 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_9 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_70 * V_25 )
{
struct V_38 * V_39 = F_46 ( V_25 ) ;
F_55 ( V_39 ) ;
}
static struct V_88 * F_58 ( struct V_88 * V_89 ,
const char * V_2 )
{
struct V_88 * V_90 ;
const char * V_26 ;
const char * V_91 ;
int V_41 ;
F_59 (edge_node, child) {
V_91 = L_3 ;
V_41 = F_60 ( V_90 , V_91 , & V_26 ) ;
if ( V_41 )
continue;
if ( strcmp ( V_26 , V_2 ) == 0 )
return V_90 ;
}
return NULL ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_92 ;
struct V_93 * V_24 = V_4 -> V_24 ;
int V_41 ;
if ( V_2 -> V_39 )
return - V_94 ;
F_10 ( V_24 -> V_25 , L_4 , V_2 -> V_26 ) ;
V_39 = F_62 ( sizeof( * V_39 ) , V_81 ) ;
if ( ! V_39 )
return - V_82 ;
V_92 = F_58 ( V_4 -> V_95 , V_2 -> V_26 ) ;
F_63 ( & V_39 -> V_25 , L_5 ,
V_4 -> V_95 -> V_26 ,
V_92 ? V_92 -> V_26 : V_2 -> V_26 ) ;
V_39 -> V_25 . V_96 = V_24 -> V_25 ;
V_39 -> V_25 . V_97 = & V_98 ;
V_39 -> V_25 . V_99 = F_57 ;
V_39 -> V_25 . V_95 = V_92 ;
V_39 -> V_2 = V_2 ;
V_2 -> V_39 = V_39 ;
V_41 = F_64 ( & V_39 -> V_25 ) ;
if ( V_41 ) {
F_54 ( V_24 -> V_25 , L_6 , V_41 ) ;
F_65 ( & V_39 -> V_25 ) ;
}
return V_41 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_70 * V_25 ;
F_67 ( ! V_2 -> V_39 ) ;
V_25 = & V_2 -> V_39 -> V_25 ;
F_68 ( V_25 ) ;
F_69 ( V_25 -> V_95 ) ;
F_65 ( V_25 ) ;
}
int F_70 ( struct V_71 * V_75 )
{
V_75 -> V_72 . V_97 = & V_98 ;
return F_71 ( & V_75 -> V_72 ) ;
}
void F_72 ( struct V_71 * V_75 )
{
F_73 ( & V_75 -> V_72 ) ;
}
static struct V_1 * F_74 ( struct V_3 * V_4 ,
unsigned V_100 ,
unsigned V_101 ,
char * V_26 )
{
struct V_1 * V_2 ;
struct V_93 * V_24 = V_4 -> V_24 ;
T_1 V_21 ;
T_1 V_102 ;
void * V_103 ;
void * V_104 ;
int V_41 ;
V_2 = F_75 ( V_24 -> V_25 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return F_76 ( - V_82 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_26 = F_77 ( V_24 -> V_25 , V_26 , V_81 ) ;
if ( ! V_2 -> V_26 )
return F_76 ( - V_82 ) ;
F_78 ( & V_2 -> V_68 ) ;
F_79 ( & V_2 -> V_56 ) ;
F_80 ( & V_2 -> V_48 ) ;
V_104 = F_81 ( V_4 -> V_57 , V_100 , & V_102 ) ;
if ( F_82 ( V_104 ) ) {
V_41 = F_83 ( V_104 ) ;
goto V_105;
}
if ( V_102 == 2 * sizeof( struct V_106 ) ) {
V_2 -> V_36 = V_104 ;
} else if ( V_102 == 2 * sizeof( struct V_107 ) ) {
V_2 -> V_104 = V_104 ;
} else {
F_54 ( V_24 -> V_25 ,
L_7 , V_102 ) ;
V_41 = - V_67 ;
goto V_105;
}
V_103 = F_81 ( V_4 -> V_57 , V_101 , & V_21 ) ;
if ( F_82 ( V_103 ) ) {
V_41 = F_83 ( V_103 ) ;
goto V_105;
}
V_21 /= 2 ;
F_10 ( V_24 -> V_25 , L_8 ,
V_26 , V_102 , V_21 ) ;
V_2 -> V_64 = V_103 ;
V_2 -> V_37 = V_103 + V_21 ;
V_2 -> V_21 = V_21 ;
F_4 ( V_2 ) ;
return V_2 ;
V_105:
F_84 ( V_24 -> V_25 , V_2 -> V_26 ) ;
F_84 ( V_24 -> V_25 , V_2 ) ;
return F_76 ( V_41 ) ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_108 * V_109 ;
struct V_108 * V_110 ;
struct V_1 * V_2 ;
struct V_93 * V_24 = V_4 -> V_24 ;
unsigned long V_62 ;
unsigned V_111 ;
unsigned V_112 ;
int V_113 ;
int V_114 ;
V_31 V_115 , V_116 ;
for ( V_113 = 0 ; V_113 < V_117 ; V_113 ++ ) {
V_109 = F_81 ( V_4 -> V_57 ,
V_118 [ V_113 ] . V_119 , NULL ) ;
if ( F_82 ( V_109 ) )
continue;
for ( V_114 = 0 ; V_114 < V_120 ; V_114 ++ ) {
V_110 = & V_109 [ V_114 ] ;
V_115 = F_26 ( V_110 -> V_62 ) ;
if ( F_86 ( V_114 , V_4 -> V_121 [ V_113 ] ) )
continue;
if ( V_110 -> V_122 == 0 )
continue;
if ( ! V_110 -> V_26 [ 0 ] )
continue;
if ( ! ( V_115 & V_123 ) )
continue;
if ( ( V_115 & V_124 ) != V_4 -> V_125 )
continue;
V_116 = F_26 ( V_110 -> V_116 ) ;
V_112 = V_118 [ V_113 ] . V_126 + V_116 ;
V_111 = V_118 [ V_113 ] . V_127 + V_116 ;
V_2 = F_74 ( V_4 , V_112 , V_111 , V_110 -> V_26 ) ;
if ( F_82 ( V_2 ) )
continue;
F_36 ( & V_4 -> V_55 , V_62 ) ;
F_87 ( & V_2 -> V_128 , & V_4 -> V_129 ) ;
F_37 ( & V_4 -> V_55 , V_62 ) ;
F_10 ( V_24 -> V_25 , L_9 , V_2 -> V_26 ) ;
F_88 ( V_114 , V_4 -> V_121 [ V_113 ] ) ;
}
}
F_34 ( & V_4 -> V_60 ) ;
}
static void F_89 ( struct V_130 * V_60 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_47 ( V_60 ,
struct V_3 ,
V_60 ) ;
unsigned V_45 ;
if ( V_4 -> V_59 ) {
V_4 -> V_59 = false ;
F_85 ( V_4 ) ;
}
F_31 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_45 = F_8 ( V_2 , V_8 ) ;
if ( V_45 != V_84 &&
V_45 != V_23 )
continue;
F_61 ( V_2 ) ;
}
F_31 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_84 &&
V_2 -> V_8 != V_23 )
continue;
V_45 = F_8 ( V_2 , V_8 ) ;
if ( V_45 == V_84 ||
V_45 == V_23 )
continue;
F_66 ( V_2 ) ;
}
}
static int F_90 ( struct V_70 * V_25 ,
struct V_88 * V_92 ,
struct V_3 * V_4 )
{
struct V_88 * V_131 ;
const char * V_91 ;
int V_51 ;
int V_41 ;
F_91 ( & V_4 -> V_129 ) ;
F_79 ( & V_4 -> V_55 ) ;
F_92 ( & V_4 -> V_60 , F_89 ) ;
V_4 -> V_95 = F_93 ( V_92 ) ;
V_51 = F_94 ( V_92 , 0 ) ;
if ( V_51 < 0 ) {
F_54 ( V_25 , L_10 ) ;
return - V_67 ;
}
V_41 = F_95 ( V_25 , V_51 ,
F_29 , V_132 ,
V_92 -> V_26 , V_4 ) ;
if ( V_41 ) {
F_54 ( V_25 , L_11 ) ;
return V_41 ;
}
V_4 -> V_51 = V_51 ;
V_91 = L_12 ;
V_41 = F_96 ( V_92 , V_91 , & V_4 -> V_125 ) ;
if ( V_41 ) {
F_54 ( V_25 , L_13 , V_91 ) ;
return - V_67 ;
}
V_4 -> V_57 = V_133 ;
V_91 = L_14 ;
F_96 ( V_92 , V_91 , & V_4 -> V_57 ) ;
V_131 = F_97 ( V_92 , L_15 , 0 ) ;
if ( ! V_131 ) {
F_54 ( V_25 , L_16 ) ;
return - V_134 ;
}
V_4 -> V_5 = F_98 ( V_131 ) ;
if ( F_82 ( V_4 -> V_5 ) )
return F_83 ( V_4 -> V_5 ) ;
V_91 = L_15 ;
V_41 = F_99 ( V_92 , V_91 , 1 , & V_4 -> V_6 ) ;
if ( V_41 < 0 ) {
F_54 ( V_25 , L_17 , V_91 ) ;
return - V_67 ;
}
V_41 = F_99 ( V_92 , V_91 , 2 , & V_4 -> V_7 ) ;
if ( V_41 < 0 ) {
F_54 ( V_25 , L_18 , V_91 ) ;
return - V_67 ;
}
return 0 ;
}
static int F_100 ( struct V_135 * V_136 )
{
struct V_3 * V_4 ;
struct V_88 * V_92 ;
struct V_93 * V_24 ;
T_1 V_137 ;
int V_138 ;
int V_41 ;
int V_114 = 0 ;
void * V_139 ;
V_139 = F_81 ( V_133 , V_118 [ 0 ] . V_119 , NULL ) ;
if ( F_83 ( V_139 ) == - V_140 )
return F_83 ( V_139 ) ;
V_138 = F_101 ( V_136 -> V_25 . V_95 ) ;
V_137 = sizeof( * V_24 ) + V_138 * sizeof( struct V_3 ) ;
V_24 = F_75 ( & V_136 -> V_25 , V_137 , V_81 ) ;
if ( ! V_24 )
return - V_82 ;
V_24 -> V_25 = & V_136 -> V_25 ;
V_24 -> V_138 = V_138 ;
F_59 (pdev->dev.of_node, node) {
V_4 = & V_24 -> V_141 [ V_114 ++ ] ;
V_4 -> V_24 = V_24 ;
V_41 = F_90 ( & V_136 -> V_25 , V_92 , V_4 ) ;
if ( V_41 )
continue;
V_4 -> V_59 = true ;
F_34 ( & V_4 -> V_60 ) ;
}
F_102 ( V_136 , V_24 ) ;
return 0 ;
}
static int F_103 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_93 * V_24 = F_104 ( V_136 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_24 -> V_138 ; V_114 ++ ) {
V_4 = & V_24 -> V_141 [ V_114 ] ;
F_105 ( V_4 -> V_51 ) ;
F_106 ( & V_4 -> V_60 ) ;
F_31 (channel, &edge->channels, list) {
if ( ! V_2 -> V_39 )
continue;
F_66 ( V_2 ) ;
}
}
return 0 ;
}
static int T_5 F_107 ( void )
{
int V_41 ;
V_41 = F_108 ( & V_98 ) ;
if ( V_41 ) {
F_109 ( L_19 , V_41 ) ;
return V_41 ;
}
return F_110 ( & V_71 ) ;
}
static void T_6 F_111 ( void )
{
F_112 ( & V_71 ) ;
F_113 ( & V_98 ) ;
}
