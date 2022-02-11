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
static void F_7 ( struct V_1 * V_2 ,
T_1 V_21 )
{
unsigned long V_22 ;
F_8 ( & V_2 -> V_23 , V_22 ) ;
V_2 -> V_21 = V_21 ;
F_9 ( & V_2 -> V_23 , V_22 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
V_18 = F_11 ( V_2 , V_18 ) ;
V_19 = F_11 ( V_2 , V_19 ) ;
return ( V_18 - V_19 ) & ( V_2 -> V_24 - 1 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_25 = V_8 == V_26 ;
if ( V_2 -> V_8 == V_8 )
return;
F_13 ( V_4 -> V_27 -> V_28 , L_1 , V_2 -> V_29 , V_8 ) ;
F_6 ( V_2 , V_10 , V_25 ) ;
F_6 ( V_2 , V_11 , V_25 ) ;
F_6 ( V_2 , V_12 , V_25 ) ;
F_5 ( V_2 , V_8 , V_8 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
V_2 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_14 ( void T_3 * V_30 ,
const void * V_31 ,
T_2 V_32 ,
bool V_33 )
{
if ( V_33 ) {
F_15 ( V_30 , V_31 , V_32 / sizeof( V_34 ) ) ;
} else {
F_16 ( V_30 , V_31 , V_32 ) ;
}
}
static void F_17 ( void * V_30 ,
const void T_3 * V_31 ,
T_2 V_32 ,
bool V_33 )
{
if ( V_33 ) {
F_18 ( V_30 , V_31 , V_32 / sizeof( V_34 ) ) ;
} else {
F_19 ( V_30 , V_31 , V_32 ) ;
}
}
static T_2 F_20 ( struct V_1 * V_2 ,
void * V_35 , T_2 V_32 )
{
bool V_33 ;
unsigned V_19 ;
T_2 V_36 ;
V_33 = V_2 -> V_37 ;
V_19 = F_11 ( V_2 , V_19 ) ;
V_36 = F_21 ( T_2 , V_32 , V_2 -> V_24 - V_19 ) ;
if ( V_36 ) {
F_17 ( V_35 ,
V_2 -> V_38 + V_19 ,
V_36 ,
V_33 ) ;
}
if ( V_36 != V_32 ) {
F_17 ( V_35 + V_36 ,
V_2 -> V_38 ,
V_32 - V_36 ,
V_33 ) ;
}
return V_32 ;
}
static void F_22 ( struct V_1 * V_2 ,
T_2 V_32 )
{
unsigned V_19 ;
V_19 = F_11 ( V_2 , V_19 ) ;
V_19 += V_32 ;
V_19 &= ( V_2 -> V_24 - 1 ) ;
F_23 ( V_2 , V_19 , V_19 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned V_19 ;
T_2 V_36 ;
void * V_39 ;
int V_40 ;
if ( ! V_2 -> V_21 )
return 0 ;
V_19 = F_11 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_24 ) {
V_39 = V_2 -> V_41 ;
V_36 = F_20 ( V_2 , V_39 , V_2 -> V_20 ) ;
} else {
V_39 = V_2 -> V_38 + V_19 ;
V_36 = V_2 -> V_20 ;
}
V_40 = V_2 -> V_21 ( V_2 , V_39 , V_36 ) ;
if ( V_40 < 0 )
return V_40 ;
F_22 ( V_2 , V_36 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_25 ( struct V_1 * V_2 )
{
bool V_42 = false ;
int V_43 ;
T_4 V_44 ;
int V_45 ;
int V_40 ;
V_43 = F_11 ( V_2 , V_8 ) ;
if ( V_43 != V_2 -> V_43 ) {
V_2 -> V_43 = V_43 ;
V_42 = true ;
}
F_26 ( V_2 , V_16 , 0 ) ;
if ( ! F_27 ( V_2 , V_17 ) )
F_28 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_8 != V_26 )
goto V_47;
F_26 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_45 = F_10 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_45 >= V_48 ) {
F_20 ( V_2 , & V_44 , sizeof( V_44 ) ) ;
F_22 ( V_2 , V_48 ) ;
V_2 -> V_20 = F_29 ( V_44 ) ;
} else if ( V_2 -> V_20 && V_45 >= V_2 -> V_20 ) {
V_40 = F_24 ( V_2 ) ;
if ( V_40 )
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
V_47:
return V_42 ;
}
static T_5 F_32 ( int V_49 , void * V_50 )
{
struct V_3 * V_4 = V_50 ;
struct V_1 * V_2 ;
unsigned V_51 ;
bool V_52 = false ;
bool V_53 = false ;
F_33 ( & V_4 -> V_54 ) ;
F_34 (channel, &edge->channels, list) {
F_33 ( & V_2 -> V_23 ) ;
V_53 |= F_25 ( V_2 ) ;
F_35 ( & V_2 -> V_23 ) ;
}
F_35 ( & V_4 -> V_54 ) ;
V_51 = F_36 ( V_4 -> V_55 ) ;
if ( V_51 != V_4 -> V_56 ) {
V_4 -> V_56 = V_51 ;
V_52 = true ;
}
if ( V_52 )
F_37 ( & V_4 -> V_57 ) ;
if ( V_53 )
F_37 ( & V_4 -> V_58 ) ;
return V_59 ;
}
static void F_38 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_8 ( & V_2 -> V_23 , V_22 ) ;
F_25 ( V_2 ) ;
F_9 ( & V_2 -> V_23 , V_22 ) ;
}
static T_2 F_39 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_60 = V_2 -> V_24 - 1 ;
V_18 = F_40 ( V_2 , V_18 ) ;
V_19 = F_40 ( V_2 , V_19 ) ;
return V_60 - ( ( V_18 - V_19 ) & V_60 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
const void * V_50 ,
T_2 V_32 )
{
bool V_33 ;
unsigned V_18 ;
T_2 V_36 ;
V_33 = V_2 -> V_37 ;
V_18 = F_40 ( V_2 , V_18 ) ;
V_36 = F_21 ( T_2 , V_32 , V_2 -> V_24 - V_18 ) ;
if ( V_36 ) {
F_14 ( V_2 -> V_61 + V_18 ,
V_50 ,
V_36 ,
V_33 ) ;
}
if ( V_36 != V_32 ) {
F_14 ( V_2 -> V_61 ,
V_50 + V_36 ,
V_32 - V_36 ,
V_33 ) ;
}
V_18 += V_32 ;
V_18 &= ( V_2 -> V_24 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_32 ;
}
int F_42 ( struct V_1 * V_2 , const void * V_50 , int V_36 )
{
T_4 V_62 [ 5 ] = { F_43 ( V_36 ) , } ;
int V_63 = sizeof( V_62 ) + V_36 ;
int V_40 ;
if ( V_2 -> V_37 && V_36 % 4 )
return - V_64 ;
if ( V_63 >= V_2 -> V_24 )
return - V_64 ;
V_40 = F_44 ( & V_2 -> V_65 ) ;
if ( V_40 )
return V_40 ;
while ( F_39 ( V_2 ) < V_63 ) {
if ( V_2 -> V_8 != V_26 ) {
V_40 = - V_66 ;
goto V_47;
}
F_6 ( V_2 , V_17 , 0 ) ;
V_40 = F_45 ( V_2 -> V_46 ,
F_39 ( V_2 ) >= V_63 ||
V_2 -> V_8 != V_26 ) ;
if ( V_40 )
goto V_47;
F_6 ( V_2 , V_17 , 1 ) ;
}
F_6 ( V_2 , V_15 , 0 ) ;
F_41 ( V_2 , V_62 , sizeof( V_62 ) ) ;
F_41 ( V_2 , V_50 , V_36 ) ;
F_6 ( V_2 , V_14 , 1 ) ;
F_31 () ;
F_1 ( V_2 ) ;
V_47:
F_46 ( & V_2 -> V_65 ) ;
return V_40 ;
}
static struct V_67 * F_47 ( struct V_68 * V_28 )
{
return F_48 ( V_28 , struct V_67 , V_28 ) ;
}
static struct V_69 * F_49 ( struct V_68 * V_28 )
{
struct V_67 * V_70 = F_47 ( V_28 ) ;
return F_48 ( V_70 -> V_28 . V_71 , struct V_69 , V_71 ) ;
}
static int F_50 ( struct V_68 * V_28 , struct V_72 * V_73 )
{
struct V_67 * V_70 = F_47 ( V_28 ) ;
struct V_69 * V_74 = F_48 ( V_73 , struct V_69 , V_71 ) ;
const struct V_75 * V_76 = V_74 -> V_77 ;
const char * V_29 = V_70 -> V_2 -> V_29 ;
if ( V_76 ) {
while ( V_76 -> V_29 [ 0 ] ) {
if ( ! strcmp ( V_76 -> V_29 , V_29 ) )
return 1 ;
V_76 ++ ;
}
}
return F_51 ( V_28 , V_73 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
T_1 V_21 )
{
T_2 V_78 ;
V_78 = F_53 ( V_2 -> V_24 , V_79 ) ;
V_2 -> V_41 = F_54 ( V_78 , V_80 ) ;
if ( ! V_2 -> V_41 )
return - V_81 ;
F_7 ( V_2 , V_21 ) ;
F_12 ( V_2 , V_82 ) ;
F_12 ( V_2 , V_26 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_7 ( V_2 , NULL ) ;
F_56 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
F_12 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
}
static int F_57 ( struct V_68 * V_28 )
{
struct V_67 * V_70 = F_47 ( V_28 ) ;
struct V_69 * V_74 = F_49 ( V_28 ) ;
struct V_1 * V_2 = V_70 -> V_2 ;
int V_40 ;
V_40 = F_52 ( V_2 , V_74 -> V_83 ) ;
if ( V_40 )
return V_40 ;
V_40 = V_74 -> V_84 ( V_70 ) ;
if ( V_40 )
goto V_85;
F_38 ( V_2 ) ;
return 0 ;
V_85:
F_58 ( & V_70 -> V_28 , L_2 ) ;
F_55 ( V_2 ) ;
return V_40 ;
}
static int F_59 ( struct V_68 * V_28 )
{
struct V_67 * V_70 = F_47 ( V_28 ) ;
struct V_69 * V_74 = F_49 ( V_28 ) ;
struct V_1 * V_2 = V_70 -> V_2 ;
struct V_1 * V_86 ;
struct V_1 * V_87 ;
F_12 ( V_2 , V_88 ) ;
F_7 ( V_2 , NULL ) ;
F_28 ( & V_2 -> V_46 ) ;
if ( V_74 -> remove )
V_74 -> remove ( V_70 ) ;
F_60 (ch, tmp, &channel->dev_list, dev_list) {
F_55 ( V_87 ) ;
F_61 ( & V_87 -> V_89 ) ;
V_87 -> V_70 = NULL ;
}
return 0 ;
}
static void F_62 ( struct V_68 * V_28 )
{
struct V_67 * V_70 = F_47 ( V_28 ) ;
F_56 ( V_70 ) ;
}
static struct V_90 * F_63 ( struct V_90 * V_91 ,
const char * V_2 )
{
struct V_90 * V_92 ;
const char * V_29 ;
const char * V_93 ;
int V_40 ;
F_64 (edge_node, child) {
V_93 = L_3 ;
V_40 = F_65 ( V_92 , V_93 , & V_29 ) ;
if ( V_40 )
continue;
if ( strcmp ( V_29 , V_2 ) == 0 )
return V_92 ;
}
return NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_67 * V_70 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_90 * V_94 ;
struct V_95 * V_27 = V_4 -> V_27 ;
int V_40 ;
if ( V_2 -> V_70 )
return - V_96 ;
F_13 ( V_27 -> V_28 , L_4 , V_2 -> V_29 ) ;
V_70 = F_67 ( sizeof( * V_70 ) , V_80 ) ;
if ( ! V_70 )
return - V_81 ;
V_94 = F_63 ( V_4 -> V_97 , V_2 -> V_29 ) ;
F_68 ( & V_70 -> V_28 , L_5 ,
V_4 -> V_97 -> V_29 ,
V_94 ? V_94 -> V_29 : V_2 -> V_29 ) ;
V_70 -> V_28 . V_98 = V_27 -> V_28 ;
V_70 -> V_28 . V_99 = & V_100 ;
V_70 -> V_28 . V_101 = F_62 ;
V_70 -> V_28 . V_97 = V_94 ;
V_70 -> V_2 = V_2 ;
V_2 -> V_70 = V_70 ;
V_40 = F_69 ( & V_70 -> V_28 ) ;
if ( V_40 ) {
F_58 ( V_27 -> V_28 , L_6 , V_40 ) ;
F_70 ( & V_70 -> V_28 ) ;
}
return V_40 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_68 * V_28 ;
F_72 ( ! V_2 -> V_70 ) ;
V_28 = & V_2 -> V_70 -> V_28 ;
F_73 ( V_28 ) ;
F_74 ( V_28 -> V_97 ) ;
F_70 ( V_28 ) ;
}
int F_75 ( struct V_69 * V_74 )
{
V_74 -> V_71 . V_99 = & V_100 ;
return F_76 ( & V_74 -> V_71 ) ;
}
void * F_77 ( struct V_1 * V_2 )
{
return V_2 -> V_102 ;
}
void F_78 ( struct V_1 * V_2 , void * V_50 )
{
V_2 -> V_102 = V_50 ;
}
void F_79 ( struct V_69 * V_74 )
{
F_80 ( & V_74 -> V_71 ) ;
}
static struct V_1 *
F_81 ( struct V_3 * V_4 , const char * V_29 )
{
struct V_1 * V_2 ;
struct V_1 * V_40 = NULL ;
unsigned long V_22 ;
unsigned V_8 ;
F_8 ( & V_4 -> V_54 , V_22 ) ;
F_34 (channel, &edge->channels, list) {
if ( strcmp ( V_2 -> V_29 , V_29 ) )
continue;
V_8 = F_11 ( V_2 , V_8 ) ;
if ( V_8 != V_82 &&
V_8 != V_26 )
continue;
V_40 = V_2 ;
break;
}
F_9 ( & V_4 -> V_54 , V_22 ) ;
return V_40 ;
}
struct V_1 * F_82 ( struct V_1 * V_98 ,
const char * V_29 ,
T_1 V_21 )
{
struct V_1 * V_2 ;
struct V_67 * V_103 = V_98 -> V_70 ;
struct V_3 * V_4 = V_98 -> V_4 ;
int V_40 ;
V_40 = F_83 ( V_4 -> V_104 ,
( V_2 = F_81 ( V_4 , V_29 ) ) != NULL ,
V_105 ) ;
if ( ! V_40 )
return F_84 ( - V_106 ) ;
if ( V_2 -> V_8 != V_9 ) {
F_58 ( & V_103 -> V_28 , L_7 , V_2 -> V_29 ) ;
return F_84 ( - V_107 ) ;
}
V_2 -> V_70 = V_103 ;
V_40 = F_52 ( V_2 , V_21 ) ;
if ( V_40 ) {
V_2 -> V_70 = NULL ;
return F_84 ( V_40 ) ;
}
F_85 ( & V_2 -> V_89 , & V_103 -> V_2 -> V_89 ) ;
return V_2 ;
}
static struct V_1 * F_86 ( struct V_3 * V_4 ,
unsigned V_108 ,
unsigned V_109 ,
char * V_29 )
{
struct V_1 * V_2 ;
struct V_95 * V_27 = V_4 -> V_27 ;
T_2 V_24 ;
T_2 V_110 ;
void * V_111 ;
void * V_112 ;
int V_40 ;
V_2 = F_87 ( V_27 -> V_28 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return F_84 ( - V_81 ) ;
F_88 ( & V_2 -> V_89 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = F_89 ( V_27 -> V_28 , V_29 , V_80 ) ;
if ( ! V_2 -> V_29 )
return F_84 ( - V_81 ) ;
F_90 ( & V_2 -> V_65 ) ;
F_91 ( & V_2 -> V_23 ) ;
F_92 ( & V_2 -> V_46 ) ;
V_112 = F_93 ( V_4 -> V_55 , V_108 , & V_110 ) ;
if ( F_94 ( V_112 ) ) {
V_40 = F_95 ( V_112 ) ;
goto V_113;
}
if ( V_110 == 2 * sizeof( struct V_114 ) ) {
V_2 -> V_37 = V_112 ;
} else if ( V_110 == 2 * sizeof( struct V_115 ) ) {
V_2 -> V_112 = V_112 ;
} else {
F_58 ( V_27 -> V_28 ,
L_8 , V_110 ) ;
V_40 = - V_64 ;
goto V_113;
}
V_111 = F_93 ( V_4 -> V_55 , V_109 , & V_24 ) ;
if ( F_94 ( V_111 ) ) {
V_40 = F_95 ( V_111 ) ;
goto V_113;
}
V_24 /= 2 ;
F_13 ( V_27 -> V_28 , L_9 ,
V_29 , V_110 , V_24 ) ;
V_2 -> V_61 = V_111 ;
V_2 -> V_38 = V_111 + V_24 ;
V_2 -> V_24 = V_24 ;
F_4 ( V_2 ) ;
return V_2 ;
V_113:
F_96 ( V_27 -> V_28 , V_2 -> V_29 ) ;
F_96 ( V_27 -> V_28 , V_2 ) ;
return F_84 ( V_40 ) ;
}
static void F_97 ( struct V_116 * V_117 )
{
struct V_3 * V_4 = F_48 ( V_117 , struct V_3 , V_57 ) ;
struct V_118 * V_119 ;
struct V_118 * V_120 ;
struct V_1 * V_2 ;
struct V_95 * V_27 = V_4 -> V_27 ;
unsigned long V_22 ;
unsigned V_121 ;
unsigned V_122 ;
int V_123 ;
int V_124 ;
V_34 V_125 , V_126 ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ ) {
V_119 = F_93 ( V_4 -> V_55 ,
V_128 [ V_123 ] . V_129 , NULL ) ;
if ( F_94 ( V_119 ) )
continue;
for ( V_124 = 0 ; V_124 < V_130 ; V_124 ++ ) {
V_120 = & V_119 [ V_124 ] ;
V_125 = F_29 ( V_120 -> V_22 ) ;
if ( F_98 ( V_124 , V_4 -> V_131 [ V_123 ] ) )
continue;
if ( V_120 -> V_132 == 0 )
continue;
if ( ! V_120 -> V_29 [ 0 ] )
continue;
if ( ! ( V_125 & V_133 ) )
continue;
if ( ( V_125 & V_134 ) != V_4 -> V_135 )
continue;
V_126 = F_29 ( V_120 -> V_126 ) ;
V_122 = V_128 [ V_123 ] . V_136 + V_126 ;
V_121 = V_128 [ V_123 ] . V_137 + V_126 ;
V_2 = F_86 ( V_4 , V_122 , V_121 , V_120 -> V_29 ) ;
if ( F_94 ( V_2 ) )
continue;
F_8 ( & V_4 -> V_54 , V_22 ) ;
F_99 ( & V_2 -> V_138 , & V_4 -> V_139 ) ;
F_9 ( & V_4 -> V_54 , V_22 ) ;
F_13 ( V_27 -> V_28 , L_10 , V_2 -> V_29 ) ;
F_100 ( V_124 , V_4 -> V_131 [ V_123 ] ) ;
F_28 ( & V_4 -> V_104 ) ;
}
}
F_37 ( & V_4 -> V_58 ) ;
}
static void F_101 ( struct V_116 * V_117 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_48 ( V_117 ,
struct V_3 ,
V_58 ) ;
unsigned V_43 ;
unsigned long V_22 ;
F_8 ( & V_4 -> V_54 , V_22 ) ;
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_43 = F_11 ( V_2 , V_8 ) ;
if ( V_43 != V_82 &&
V_43 != V_26 )
continue;
F_9 ( & V_4 -> V_54 , V_22 ) ;
F_66 ( V_2 ) ;
F_8 ( & V_4 -> V_54 , V_22 ) ;
}
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_82 &&
V_2 -> V_8 != V_26 )
continue;
V_43 = F_11 ( V_2 , V_8 ) ;
if ( V_43 == V_82 ||
V_43 == V_26 )
continue;
F_9 ( & V_4 -> V_54 , V_22 ) ;
F_71 ( V_2 ) ;
F_8 ( & V_4 -> V_54 , V_22 ) ;
}
F_9 ( & V_4 -> V_54 , V_22 ) ;
}
static int F_102 ( struct V_68 * V_28 ,
struct V_90 * V_94 ,
struct V_3 * V_4 )
{
struct V_90 * V_140 ;
const char * V_93 ;
int V_49 ;
int V_40 ;
F_88 ( & V_4 -> V_139 ) ;
F_91 ( & V_4 -> V_54 ) ;
F_103 ( & V_4 -> V_57 , F_97 ) ;
F_103 ( & V_4 -> V_58 , F_101 ) ;
V_4 -> V_97 = F_104 ( V_94 ) ;
V_49 = F_105 ( V_94 , 0 ) ;
if ( V_49 < 0 ) {
F_58 ( V_28 , L_11 ) ;
return - V_64 ;
}
V_40 = F_106 ( V_28 , V_49 ,
F_32 , V_141 ,
V_94 -> V_29 , V_4 ) ;
if ( V_40 ) {
F_58 ( V_28 , L_12 ) ;
return V_40 ;
}
V_4 -> V_49 = V_49 ;
V_93 = L_13 ;
V_40 = F_107 ( V_94 , V_93 , & V_4 -> V_135 ) ;
if ( V_40 ) {
F_58 ( V_28 , L_14 , V_93 ) ;
return - V_64 ;
}
V_4 -> V_55 = V_142 ;
V_93 = L_15 ;
F_107 ( V_94 , V_93 , & V_4 -> V_55 ) ;
V_140 = F_108 ( V_94 , L_16 , 0 ) ;
if ( ! V_140 ) {
F_58 ( V_28 , L_17 ) ;
return - V_143 ;
}
V_4 -> V_5 = F_109 ( V_140 ) ;
if ( F_94 ( V_4 -> V_5 ) )
return F_95 ( V_4 -> V_5 ) ;
V_93 = L_16 ;
V_40 = F_110 ( V_94 , V_93 , 1 , & V_4 -> V_6 ) ;
if ( V_40 < 0 ) {
F_58 ( V_28 , L_18 , V_93 ) ;
return - V_64 ;
}
V_40 = F_110 ( V_94 , V_93 , 2 , & V_4 -> V_7 ) ;
if ( V_40 < 0 ) {
F_58 ( V_28 , L_19 , V_93 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_111 ( struct V_144 * V_145 )
{
struct V_3 * V_4 ;
struct V_90 * V_94 ;
struct V_95 * V_27 ;
T_2 V_146 ;
int V_147 ;
int V_40 ;
int V_124 = 0 ;
void * V_148 ;
V_148 = F_93 ( V_142 , V_128 [ 0 ] . V_129 , NULL ) ;
if ( F_95 ( V_148 ) == - V_149 )
return F_95 ( V_148 ) ;
V_147 = F_112 ( V_145 -> V_28 . V_97 ) ;
V_146 = sizeof( * V_27 ) + V_147 * sizeof( struct V_3 ) ;
V_27 = F_87 ( & V_145 -> V_28 , V_146 , V_80 ) ;
if ( ! V_27 )
return - V_81 ;
V_27 -> V_28 = & V_145 -> V_28 ;
V_27 -> V_147 = V_147 ;
F_64 (pdev->dev.of_node, node) {
V_4 = & V_27 -> V_150 [ V_124 ++ ] ;
V_4 -> V_27 = V_27 ;
F_92 ( & V_4 -> V_104 ) ;
V_40 = F_102 ( & V_145 -> V_28 , V_94 , V_4 ) ;
if ( V_40 )
continue;
F_37 ( & V_4 -> V_57 ) ;
}
F_113 ( V_145 , V_27 ) ;
return 0 ;
}
static int F_114 ( struct V_144 * V_145 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_95 * V_27 = F_115 ( V_145 ) ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_27 -> V_147 ; V_124 ++ ) {
V_4 = & V_27 -> V_150 [ V_124 ] ;
F_116 ( V_4 -> V_49 ) ;
F_117 ( & V_4 -> V_57 ) ;
F_117 ( & V_4 -> V_58 ) ;
F_34 (channel, &edge->channels, list) {
if ( ! V_2 -> V_70 )
continue;
F_71 ( V_2 ) ;
}
}
return 0 ;
}
static int T_6 F_118 ( void )
{
int V_40 ;
V_40 = F_119 ( & V_100 ) ;
if ( V_40 ) {
F_120 ( L_20 , V_40 ) ;
return V_40 ;
}
return F_121 ( & V_69 ) ;
}
static void T_7 F_122 ( void )
{
F_123 ( & V_69 ) ;
F_124 ( & V_100 ) ;
}
