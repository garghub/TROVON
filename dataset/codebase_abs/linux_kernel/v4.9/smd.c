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
F_7 ( V_2 , V_19 , 0 ) ;
F_1 ( V_2 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_20 = 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_21 )
{
unsigned long V_22 ;
F_9 ( & V_2 -> V_23 , V_22 ) ;
V_2 -> V_21 = V_21 ;
F_10 ( & V_2 -> V_23 , V_22 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
V_18 = F_12 ( V_2 , V_18 ) ;
V_19 = F_12 ( V_2 , V_19 ) ;
return ( V_18 - V_19 ) & ( V_2 -> V_24 - 1 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_25 = V_8 == V_26 ;
if ( V_2 -> V_8 == V_8 )
return;
F_14 ( & V_4 -> V_27 , L_1 , V_2 -> V_28 , V_8 ) ;
F_6 ( V_2 , V_10 , V_25 ) ;
F_6 ( V_2 , V_11 , V_25 ) ;
F_6 ( V_2 , V_12 , V_25 ) ;
F_5 ( V_2 , V_8 , V_8 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
V_2 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_15 ( void T_3 * V_29 ,
const void * V_30 ,
T_2 V_31 ,
bool V_32 )
{
if ( V_32 ) {
F_16 ( V_29 , V_30 , V_31 / sizeof( V_33 ) ) ;
} else {
F_17 ( V_29 , V_30 , V_31 ) ;
}
}
static void F_18 ( void * V_29 ,
const void T_3 * V_30 ,
T_2 V_31 ,
bool V_32 )
{
if ( V_32 ) {
F_19 ( V_29 , V_30 , V_31 / sizeof( V_33 ) ) ;
} else {
F_20 ( V_29 , V_30 , V_31 ) ;
}
}
static T_2 F_21 ( struct V_1 * V_2 ,
void * V_34 , T_2 V_31 )
{
bool V_32 ;
unsigned V_19 ;
T_2 V_35 ;
V_32 = V_2 -> V_36 ;
V_19 = F_12 ( V_2 , V_19 ) ;
V_35 = F_22 ( T_2 , V_31 , V_2 -> V_24 - V_19 ) ;
if ( V_35 ) {
F_18 ( V_34 ,
V_2 -> V_37 + V_19 ,
V_35 ,
V_32 ) ;
}
if ( V_35 != V_31 ) {
F_18 ( V_34 + V_35 ,
V_2 -> V_37 ,
V_31 - V_35 ,
V_32 ) ;
}
return V_31 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_2 V_31 )
{
unsigned V_19 ;
V_19 = F_12 ( V_2 , V_19 ) ;
V_19 += V_31 ;
V_19 &= ( V_2 -> V_24 - 1 ) ;
F_7 ( V_2 , V_19 , V_19 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned V_19 ;
T_2 V_35 ;
void * V_38 ;
int V_39 ;
if ( ! V_2 -> V_21 )
return 0 ;
V_19 = F_12 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_24 ) {
V_38 = V_2 -> V_40 ;
V_35 = F_21 ( V_2 , V_38 , V_2 -> V_20 ) ;
} else {
V_38 = V_2 -> V_37 + V_19 ;
V_35 = V_2 -> V_20 ;
}
V_39 = V_2 -> V_21 ( V_2 , V_38 , V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
F_23 ( V_2 , V_35 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_25 ( struct V_1 * V_2 )
{
bool V_41 = false ;
int V_42 ;
T_4 V_43 ;
int V_44 ;
int V_39 ;
V_42 = F_12 ( V_2 , V_8 ) ;
if ( V_42 != V_2 -> V_42 ) {
V_2 -> V_42 = V_42 ;
V_41 = true ;
}
F_26 ( V_2 , V_16 , 0 ) ;
if ( ! F_27 ( V_2 , V_17 ) )
F_28 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_8 != V_26 )
goto V_46;
F_26 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_44 = F_11 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_44 >= V_47 ) {
F_21 ( V_2 , & V_43 , sizeof( V_43 ) ) ;
F_23 ( V_2 , V_47 ) ;
V_2 -> V_20 = F_29 ( V_43 ) ;
} else if ( V_2 -> V_20 && V_44 >= V_2 -> V_20 ) {
V_39 = F_24 ( V_2 ) ;
if ( V_39 )
break;
} else {
break;
}
}
F_26 ( V_2 , V_15 , 1 ) ;
if ( ! F_30 ( V_2 , V_17 ) ) {
F_31 () ;
F_1 ( V_2 ) ;
}
V_46:
return V_41 ;
}
static T_5 F_32 ( int V_48 , void * V_49 )
{
struct V_3 * V_4 = V_49 ;
struct V_1 * V_2 ;
unsigned V_50 ;
bool V_51 = false ;
bool V_52 = false ;
F_33 ( & V_4 -> V_53 ) ;
F_34 (channel, &edge->channels, list) {
F_33 ( & V_2 -> V_23 ) ;
V_52 |= F_25 ( V_2 ) ;
F_35 ( & V_2 -> V_23 ) ;
}
F_35 ( & V_4 -> V_53 ) ;
V_50 = F_36 ( V_4 -> V_54 ) ;
if ( V_50 != V_4 -> V_55 ) {
V_4 -> V_55 = V_50 ;
V_51 = true ;
}
if ( V_51 )
F_37 ( & V_4 -> V_56 ) ;
if ( V_52 )
F_37 ( & V_4 -> V_57 ) ;
return V_58 ;
}
static void F_38 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_9 ( & V_2 -> V_23 , V_22 ) ;
F_25 ( V_2 ) ;
F_10 ( & V_2 -> V_23 , V_22 ) ;
}
static T_2 F_39 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_59 = V_2 -> V_24 - 1 ;
V_18 = F_40 ( V_2 , V_18 ) ;
V_19 = F_40 ( V_2 , V_19 ) ;
return V_59 - ( ( V_18 - V_19 ) & V_59 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
const void * V_49 ,
T_2 V_31 )
{
bool V_32 ;
unsigned V_18 ;
T_2 V_35 ;
V_32 = V_2 -> V_36 ;
V_18 = F_40 ( V_2 , V_18 ) ;
V_35 = F_22 ( T_2 , V_31 , V_2 -> V_24 - V_18 ) ;
if ( V_35 ) {
F_15 ( V_2 -> V_60 + V_18 ,
V_49 ,
V_35 ,
V_32 ) ;
}
if ( V_35 != V_31 ) {
F_15 ( V_2 -> V_60 ,
V_49 + V_35 ,
V_31 - V_35 ,
V_32 ) ;
}
V_18 += V_31 ;
V_18 &= ( V_2 -> V_24 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_31 ;
}
int F_42 ( struct V_1 * V_2 , const void * V_49 , int V_35 )
{
T_4 V_61 [ 5 ] = { F_43 ( V_35 ) , } ;
int V_62 = sizeof( V_61 ) + V_35 ;
int V_39 ;
if ( V_2 -> V_36 && V_35 % 4 )
return - V_63 ;
if ( V_62 >= V_2 -> V_24 )
return - V_63 ;
V_39 = F_44 ( & V_2 -> V_64 ) ;
if ( V_39 )
return V_39 ;
while ( F_39 ( V_2 ) < V_62 ) {
if ( V_2 -> V_8 != V_26 ) {
V_39 = - V_65 ;
goto V_46;
}
F_6 ( V_2 , V_17 , 0 ) ;
V_39 = F_45 ( V_2 -> V_45 ,
F_39 ( V_2 ) >= V_62 ||
V_2 -> V_8 != V_26 ) ;
if ( V_39 )
goto V_46;
F_6 ( V_2 , V_17 , 1 ) ;
}
F_6 ( V_2 , V_15 , 0 ) ;
F_41 ( V_2 , V_61 , sizeof( V_61 ) ) ;
F_41 ( V_2 , V_49 , V_35 ) ;
F_6 ( V_2 , V_14 , 1 ) ;
F_31 () ;
F_1 ( V_2 ) ;
V_46:
F_46 ( & V_2 -> V_64 ) ;
return V_39 ;
}
static struct V_66 * F_47 ( struct V_67 * V_27 )
{
return F_48 ( V_27 , struct V_66 , V_27 ) ;
}
static struct V_68 * F_49 ( struct V_67 * V_27 )
{
struct V_66 * V_69 = F_47 ( V_27 ) ;
return F_48 ( V_69 -> V_27 . V_70 , struct V_68 , V_70 ) ;
}
static int F_50 ( struct V_67 * V_27 , struct V_71 * V_72 )
{
struct V_66 * V_69 = F_47 ( V_27 ) ;
struct V_68 * V_73 = F_48 ( V_72 , struct V_68 , V_70 ) ;
const struct V_74 * V_75 = V_73 -> V_76 ;
const char * V_28 = V_69 -> V_2 -> V_28 ;
if ( V_75 ) {
while ( V_75 -> V_28 [ 0 ] ) {
if ( ! strcmp ( V_75 -> V_28 , V_28 ) )
return 1 ;
V_75 ++ ;
}
}
return F_51 ( V_27 , V_72 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
T_1 V_21 )
{
T_2 V_77 ;
V_77 = F_53 ( V_2 -> V_24 , V_78 ) ;
V_2 -> V_40 = F_54 ( V_77 , V_79 ) ;
if ( ! V_2 -> V_40 )
return - V_80 ;
F_8 ( V_2 , V_21 ) ;
F_13 ( V_2 , V_81 ) ;
F_13 ( V_2 , V_26 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_8 ( V_2 , NULL ) ;
F_56 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
F_13 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
}
static int F_57 ( struct V_67 * V_27 )
{
struct V_66 * V_69 = F_47 ( V_27 ) ;
struct V_68 * V_73 = F_49 ( V_27 ) ;
struct V_1 * V_2 = V_69 -> V_2 ;
int V_39 ;
V_39 = F_52 ( V_2 , V_73 -> V_82 ) ;
if ( V_39 )
return V_39 ;
V_39 = V_73 -> V_83 ( V_69 ) ;
if ( V_39 )
goto V_84;
F_38 ( V_2 ) ;
return 0 ;
V_84:
F_58 ( & V_69 -> V_27 , L_2 ) ;
F_55 ( V_2 ) ;
return V_39 ;
}
static int F_59 ( struct V_67 * V_27 )
{
struct V_66 * V_69 = F_47 ( V_27 ) ;
struct V_68 * V_73 = F_49 ( V_27 ) ;
struct V_1 * V_2 = V_69 -> V_2 ;
F_13 ( V_2 , V_85 ) ;
F_8 ( V_2 , NULL ) ;
F_28 ( & V_2 -> V_45 ) ;
if ( V_73 -> remove )
V_73 -> remove ( V_69 ) ;
F_55 ( V_2 ) ;
V_2 -> V_69 = NULL ;
return 0 ;
}
static void F_60 ( struct V_67 * V_27 )
{
struct V_66 * V_69 = F_47 ( V_27 ) ;
F_56 ( V_69 ) ;
}
static struct V_86 * F_61 ( struct V_86 * V_87 ,
const char * V_2 )
{
struct V_86 * V_88 ;
const char * V_28 ;
const char * V_89 ;
int V_39 ;
F_62 (edge_node, child) {
V_89 = L_3 ;
V_39 = F_63 ( V_88 , V_89 , & V_28 ) ;
if ( V_39 )
continue;
if ( strcmp ( V_28 , V_2 ) == 0 )
return V_88 ;
}
return NULL ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_66 * V_69 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_86 * V_90 ;
int V_39 ;
if ( V_2 -> V_69 )
return - V_91 ;
F_14 ( & V_4 -> V_27 , L_4 , V_2 -> V_28 ) ;
V_69 = F_65 ( sizeof( * V_69 ) , V_79 ) ;
if ( ! V_69 )
return - V_80 ;
V_90 = F_61 ( V_4 -> V_92 , V_2 -> V_28 ) ;
F_66 ( & V_69 -> V_27 , L_5 ,
V_4 -> V_92 -> V_28 ,
V_90 ? V_90 -> V_28 : V_2 -> V_28 ) ;
V_69 -> V_27 . V_93 = & V_4 -> V_27 ;
V_69 -> V_27 . V_94 = & V_95 ;
V_69 -> V_27 . V_96 = F_60 ;
V_69 -> V_27 . V_92 = V_90 ;
V_69 -> V_2 = V_2 ;
V_2 -> V_69 = V_69 ;
V_39 = F_67 ( & V_69 -> V_27 ) ;
if ( V_39 ) {
F_58 ( & V_4 -> V_27 , L_6 , V_39 ) ;
F_68 ( & V_69 -> V_27 ) ;
}
return V_39 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_67 * V_27 ;
F_70 ( ! V_2 -> V_69 ) ;
V_27 = & V_2 -> V_69 -> V_27 ;
F_71 ( V_27 ) ;
F_72 ( V_27 -> V_92 ) ;
F_68 ( V_27 ) ;
}
int F_73 ( struct V_68 * V_73 )
{
V_73 -> V_70 . V_94 = & V_95 ;
return F_74 ( & V_73 -> V_70 ) ;
}
void * F_75 ( struct V_1 * V_2 )
{
return V_2 -> V_97 ;
}
void F_76 ( struct V_1 * V_2 , void * V_49 )
{
V_2 -> V_97 = V_49 ;
}
void F_77 ( struct V_68 * V_73 )
{
F_78 ( & V_73 -> V_70 ) ;
}
static struct V_1 *
F_79 ( struct V_3 * V_4 , const char * V_28 )
{
struct V_1 * V_2 ;
struct V_1 * V_39 = NULL ;
unsigned long V_22 ;
unsigned V_8 ;
F_9 ( & V_4 -> V_53 , V_22 ) ;
F_34 (channel, &edge->channels, list) {
if ( strcmp ( V_2 -> V_28 , V_28 ) )
continue;
V_8 = F_12 ( V_2 , V_8 ) ;
if ( V_8 != V_81 &&
V_8 != V_26 )
continue;
V_39 = V_2 ;
break;
}
F_10 ( & V_4 -> V_53 , V_22 ) ;
return V_39 ;
}
struct V_1 * F_80 ( struct V_1 * V_93 ,
const char * V_28 ,
T_1 V_21 )
{
struct V_1 * V_2 ;
struct V_66 * V_98 = V_93 -> V_69 ;
struct V_3 * V_4 = V_93 -> V_4 ;
int V_39 ;
V_39 = F_81 ( V_4 -> V_99 ,
( V_2 = F_79 ( V_4 , V_28 ) ) != NULL ,
V_100 ) ;
if ( ! V_39 )
return F_82 ( - V_101 ) ;
if ( V_2 -> V_8 != V_9 ) {
F_58 ( & V_98 -> V_27 , L_7 , V_2 -> V_28 ) ;
return F_82 ( - V_102 ) ;
}
V_2 -> V_69 = V_98 ;
V_39 = F_52 ( V_2 , V_21 ) ;
if ( V_39 ) {
V_2 -> V_69 = NULL ;
return F_82 ( V_39 ) ;
}
return V_2 ;
}
void F_83 ( struct V_1 * V_2 )
{
F_55 ( V_2 ) ;
V_2 -> V_69 = NULL ;
}
static struct V_1 * F_84 ( struct V_3 * V_4 ,
unsigned V_103 ,
unsigned V_104 ,
char * V_28 )
{
struct V_1 * V_2 ;
T_2 V_24 ;
T_2 V_105 ;
void * V_106 ;
void * V_107 ;
int V_39 ;
V_2 = F_85 ( & V_4 -> V_27 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_82 ( - V_80 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_28 = F_86 ( & V_4 -> V_27 , V_28 , V_79 ) ;
if ( ! V_2 -> V_28 )
return F_82 ( - V_80 ) ;
F_87 ( & V_2 -> V_64 ) ;
F_88 ( & V_2 -> V_23 ) ;
F_89 ( & V_2 -> V_45 ) ;
V_107 = F_90 ( V_4 -> V_54 , V_103 , & V_105 ) ;
if ( F_91 ( V_107 ) ) {
V_39 = F_92 ( V_107 ) ;
goto V_108;
}
if ( V_105 == 2 * sizeof( struct V_109 ) ) {
V_2 -> V_36 = V_107 ;
} else if ( V_105 == 2 * sizeof( struct V_110 ) ) {
V_2 -> V_107 = V_107 ;
} else {
F_58 ( & V_4 -> V_27 ,
L_8 , V_105 ) ;
V_39 = - V_63 ;
goto V_108;
}
V_106 = F_90 ( V_4 -> V_54 , V_104 , & V_24 ) ;
if ( F_91 ( V_106 ) ) {
V_39 = F_92 ( V_106 ) ;
goto V_108;
}
V_24 /= 2 ;
F_14 ( & V_4 -> V_27 , L_9 ,
V_28 , V_105 , V_24 ) ;
V_2 -> V_60 = V_106 ;
V_2 -> V_37 = V_106 + V_24 ;
V_2 -> V_24 = V_24 ;
F_4 ( V_2 ) ;
return V_2 ;
V_108:
F_93 ( & V_4 -> V_27 , V_2 -> V_28 ) ;
F_93 ( & V_4 -> V_27 , V_2 ) ;
return F_82 ( V_39 ) ;
}
static void F_94 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_48 ( V_112 , struct V_3 , V_56 ) ;
struct V_113 * V_114 ;
struct V_113 * V_115 ;
struct V_1 * V_2 ;
unsigned long V_22 ;
unsigned V_116 ;
unsigned V_117 ;
int V_118 ;
int V_119 ;
V_33 V_120 , V_121 ;
for ( V_118 = 0 ; V_118 < V_122 ; V_118 ++ ) {
V_114 = F_90 ( V_4 -> V_54 ,
V_123 [ V_118 ] . V_124 , NULL ) ;
if ( F_91 ( V_114 ) )
continue;
for ( V_119 = 0 ; V_119 < V_125 ; V_119 ++ ) {
V_115 = & V_114 [ V_119 ] ;
V_120 = F_29 ( V_115 -> V_22 ) ;
if ( F_95 ( V_119 , V_4 -> V_126 [ V_118 ] ) )
continue;
if ( V_115 -> V_127 == 0 )
continue;
if ( ! V_115 -> V_28 [ 0 ] )
continue;
if ( ! ( V_120 & V_128 ) )
continue;
if ( ( V_120 & V_129 ) != V_4 -> V_130 )
continue;
V_121 = F_29 ( V_115 -> V_121 ) ;
V_117 = V_123 [ V_118 ] . V_131 + V_121 ;
V_116 = V_123 [ V_118 ] . V_132 + V_121 ;
V_2 = F_84 ( V_4 , V_117 , V_116 , V_115 -> V_28 ) ;
if ( F_91 ( V_2 ) )
continue;
F_9 ( & V_4 -> V_53 , V_22 ) ;
F_96 ( & V_2 -> V_133 , & V_4 -> V_134 ) ;
F_10 ( & V_4 -> V_53 , V_22 ) ;
F_14 ( & V_4 -> V_27 , L_10 , V_2 -> V_28 ) ;
F_97 ( V_119 , V_4 -> V_126 [ V_118 ] ) ;
F_28 ( & V_4 -> V_99 ) ;
}
}
F_37 ( & V_4 -> V_57 ) ;
}
static void F_98 ( struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_48 ( V_112 ,
struct V_3 ,
V_57 ) ;
unsigned V_42 ;
unsigned long V_22 ;
F_9 ( & V_4 -> V_53 , V_22 ) ;
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_42 = F_12 ( V_2 , V_8 ) ;
if ( V_42 != V_81 &&
V_42 != V_26 )
continue;
F_10 ( & V_4 -> V_53 , V_22 ) ;
F_64 ( V_2 ) ;
F_9 ( & V_4 -> V_53 , V_22 ) ;
}
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_81 &&
V_2 -> V_8 != V_26 )
continue;
V_42 = F_12 ( V_2 , V_8 ) ;
if ( V_42 == V_81 ||
V_42 == V_26 )
continue;
F_10 ( & V_4 -> V_53 , V_22 ) ;
F_69 ( V_2 ) ;
F_9 ( & V_4 -> V_53 , V_22 ) ;
}
F_10 ( & V_4 -> V_53 , V_22 ) ;
}
static int F_99 ( struct V_67 * V_27 ,
struct V_86 * V_90 ,
struct V_3 * V_4 )
{
struct V_86 * V_135 ;
const char * V_89 ;
int V_48 ;
int V_39 ;
F_100 ( & V_4 -> V_134 ) ;
F_88 ( & V_4 -> V_53 ) ;
F_101 ( & V_4 -> V_56 , F_94 ) ;
F_101 ( & V_4 -> V_57 , F_98 ) ;
V_4 -> V_92 = F_102 ( V_90 ) ;
V_89 = L_11 ;
V_39 = F_103 ( V_90 , V_89 , & V_4 -> V_130 ) ;
if ( V_39 ) {
F_58 ( V_27 , L_12 , V_89 ) ;
return - V_63 ;
}
V_4 -> V_54 = V_136 ;
V_89 = L_13 ;
F_103 ( V_90 , V_89 , & V_4 -> V_54 ) ;
V_135 = F_104 ( V_90 , L_14 , 0 ) ;
if ( ! V_135 ) {
F_58 ( V_27 , L_15 ) ;
return - V_137 ;
}
V_4 -> V_5 = F_105 ( V_135 ) ;
if ( F_91 ( V_4 -> V_5 ) )
return F_92 ( V_4 -> V_5 ) ;
V_89 = L_14 ;
V_39 = F_106 ( V_90 , V_89 , 1 , & V_4 -> V_6 ) ;
if ( V_39 < 0 ) {
F_58 ( V_27 , L_16 , V_89 ) ;
return - V_63 ;
}
V_39 = F_106 ( V_90 , V_89 , 2 , & V_4 -> V_7 ) ;
if ( V_39 < 0 ) {
F_58 ( V_27 , L_17 , V_89 ) ;
return - V_63 ;
}
V_48 = F_107 ( V_90 , 0 ) ;
if ( V_48 < 0 ) {
F_58 ( V_27 , L_18 ) ;
return - V_63 ;
}
V_39 = F_108 ( V_27 , V_48 ,
F_32 , V_138 ,
V_90 -> V_28 , V_4 ) ;
if ( V_39 ) {
F_58 ( V_27 , L_19 ) ;
return V_39 ;
}
V_4 -> V_48 = V_48 ;
return 0 ;
}
static void F_109 ( struct V_67 * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_110 ( V_27 ) ;
F_34 (channel, &edge->channels, list) {
F_7 ( V_2 , V_8 , V_9 ) ;
F_7 ( V_2 , V_18 , 0 ) ;
F_7 ( V_2 , V_19 , 0 ) ;
}
F_56 ( V_4 ) ;
}
struct V_3 * F_111 ( struct V_67 * V_93 ,
struct V_86 * V_90 )
{
struct V_3 * V_4 ;
int V_39 ;
V_4 = F_65 ( sizeof( * V_4 ) , V_79 ) ;
if ( ! V_4 )
return F_82 ( - V_80 ) ;
F_89 ( & V_4 -> V_99 ) ;
V_4 -> V_27 . V_93 = V_93 ;
V_4 -> V_27 . V_96 = F_109 ;
F_66 ( & V_4 -> V_27 , L_20 , F_112 ( V_93 ) , V_90 -> V_28 ) ;
V_39 = F_67 ( & V_4 -> V_27 ) ;
if ( V_39 ) {
F_113 ( L_21 ) ;
return F_82 ( V_39 ) ;
}
V_39 = F_99 ( & V_4 -> V_27 , V_90 , V_4 ) ;
if ( V_39 ) {
F_58 ( & V_4 -> V_27 , L_22 ) ;
goto V_139;
}
F_37 ( & V_4 -> V_56 ) ;
return V_4 ;
V_139:
F_68 ( & V_4 -> V_27 ) ;
return F_82 ( V_39 ) ;
}
static int F_114 ( struct V_67 * V_27 , void * V_49 )
{
F_71 ( V_27 ) ;
F_72 ( V_27 -> V_92 ) ;
F_68 ( V_27 ) ;
return 0 ;
}
int F_115 ( struct V_3 * V_4 )
{
int V_39 ;
F_116 ( V_4 -> V_48 ) ;
F_117 ( & V_4 -> V_56 ) ;
F_117 ( & V_4 -> V_57 ) ;
V_39 = F_118 ( & V_4 -> V_27 , NULL , F_114 ) ;
if ( V_39 )
F_119 ( & V_4 -> V_27 , L_23 , V_39 ) ;
F_71 ( & V_4 -> V_27 ) ;
return 0 ;
}
static int F_120 ( struct V_140 * V_141 )
{
struct V_86 * V_90 ;
void * V_142 ;
V_142 = F_90 ( V_136 , V_123 [ 0 ] . V_124 , NULL ) ;
if ( F_92 ( V_142 ) == - V_143 )
return F_92 ( V_142 ) ;
F_62 (pdev->dev.of_node, node)
F_111 ( & V_141 -> V_27 , V_90 ) ;
return 0 ;
}
static int F_121 ( struct V_67 * V_27 , void * V_49 )
{
struct V_3 * V_4 = F_110 ( V_27 ) ;
return F_115 ( V_4 ) ;
}
static int F_122 ( struct V_140 * V_141 )
{
int V_39 ;
V_39 = F_118 ( & V_141 -> V_27 , NULL , F_121 ) ;
if ( V_39 )
F_119 ( & V_141 -> V_27 , L_23 , V_39 ) ;
return V_39 ;
}
static int T_6 F_123 ( void )
{
int V_39 ;
V_39 = F_124 ( & V_95 ) ;
if ( V_39 ) {
F_113 ( L_24 , V_39 ) ;
return V_39 ;
}
return F_125 ( & V_68 ) ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_68 ) ;
F_128 ( & V_95 ) ;
}
