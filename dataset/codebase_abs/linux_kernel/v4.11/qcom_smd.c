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
struct V_22 * V_23 = & V_2 -> V_24 -> V_23 ;
unsigned long V_25 ;
F_9 ( & V_2 -> V_26 , V_25 ) ;
V_23 -> V_21 = V_21 ;
F_10 ( & V_2 -> V_26 , V_25 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
V_18 = F_12 ( V_2 , V_18 ) ;
V_19 = F_12 ( V_2 , V_19 ) ;
return ( V_18 - V_19 ) & ( V_2 -> V_27 - 1 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_28 = V_8 == V_29 ;
if ( V_2 -> V_8 == V_8 )
return;
F_14 ( & V_4 -> V_30 , L_1 , V_2 -> V_31 , V_8 ) ;
F_6 ( V_2 , V_10 , V_28 ) ;
F_6 ( V_2 , V_11 , V_28 ) ;
F_6 ( V_2 , V_12 , V_28 ) ;
F_5 ( V_2 , V_8 , V_8 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
V_2 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_15 ( void T_3 * V_32 ,
const void * V_33 ,
T_2 V_34 ,
bool V_35 )
{
if ( V_35 ) {
F_16 ( V_32 , V_33 , V_34 / sizeof( V_36 ) ) ;
} else {
F_17 ( V_32 , V_33 , V_34 ) ;
}
}
static void F_18 ( void * V_32 ,
const void T_3 * V_33 ,
T_2 V_34 ,
bool V_35 )
{
if ( V_35 ) {
F_19 ( V_32 , V_33 , V_34 / sizeof( V_36 ) ) ;
} else {
F_20 ( V_32 , V_33 , V_34 ) ;
}
}
static T_2 F_21 ( struct V_1 * V_2 ,
void * V_37 , T_2 V_34 )
{
bool V_35 ;
unsigned V_19 ;
T_2 V_38 ;
V_35 = V_2 -> V_39 ;
V_19 = F_12 ( V_2 , V_19 ) ;
V_38 = F_22 ( T_2 , V_34 , V_2 -> V_27 - V_19 ) ;
if ( V_38 ) {
F_18 ( V_37 ,
V_2 -> V_40 + V_19 ,
V_38 ,
V_35 ) ;
}
if ( V_38 != V_34 ) {
F_18 ( V_37 + V_38 ,
V_2 -> V_40 ,
V_34 - V_38 ,
V_35 ) ;
}
return V_34 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_2 V_34 )
{
unsigned V_19 ;
V_19 = F_12 ( V_2 , V_19 ) ;
V_19 += V_34 ;
V_19 &= ( V_2 -> V_27 - 1 ) ;
F_7 ( V_2 , V_19 , V_19 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = & V_2 -> V_24 -> V_23 ;
unsigned V_19 ;
T_2 V_38 ;
void * V_41 ;
int V_42 ;
V_19 = F_12 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_27 ) {
V_41 = V_2 -> V_43 ;
V_38 = F_21 ( V_2 , V_41 , V_2 -> V_20 ) ;
} else {
V_41 = V_2 -> V_40 + V_19 ;
V_38 = V_2 -> V_20 ;
}
V_42 = V_23 -> V_21 ( V_23 -> V_44 , V_41 , V_38 , V_23 -> V_45 , V_46 ) ;
if ( V_42 < 0 )
return V_42 ;
F_23 ( V_2 , V_38 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_25 ( struct V_1 * V_2 )
{
bool V_47 = false ;
int V_48 ;
T_4 V_49 ;
int V_50 ;
int V_42 ;
V_48 = F_12 ( V_2 , V_8 ) ;
if ( V_48 != V_2 -> V_48 ) {
V_2 -> V_48 = V_48 ;
V_47 = true ;
}
F_26 ( V_2 , V_16 , 0 ) ;
if ( ! F_27 ( V_2 , V_17 ) )
F_28 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_8 != V_29 )
goto V_52;
F_26 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_50 = F_11 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_50 >= V_53 ) {
F_21 ( V_2 , & V_49 , sizeof( V_49 ) ) ;
F_23 ( V_2 , V_53 ) ;
V_2 -> V_20 = F_29 ( V_49 ) ;
} else if ( V_2 -> V_20 && V_50 >= V_2 -> V_20 ) {
V_42 = F_24 ( V_2 ) ;
if ( V_42 )
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
V_52:
return V_47 ;
}
static T_5 F_32 ( int V_54 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
struct V_1 * V_2 ;
unsigned V_56 ;
bool V_57 = false ;
bool V_58 = false ;
F_33 ( & V_4 -> V_59 ) ;
F_34 (channel, &edge->channels, list) {
F_33 ( & V_2 -> V_26 ) ;
V_58 |= F_25 ( V_2 ) ;
F_35 ( & V_2 -> V_26 ) ;
}
F_35 ( & V_4 -> V_59 ) ;
V_56 = F_36 ( V_4 -> V_60 ) ;
if ( V_56 != V_4 -> V_61 ) {
V_4 -> V_61 = V_56 ;
V_57 = true ;
}
if ( V_57 )
F_37 ( & V_4 -> V_62 ) ;
if ( V_58 )
F_37 ( & V_4 -> V_63 ) ;
return V_64 ;
}
static T_2 F_38 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_65 = V_2 -> V_27 - 1 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_19 = F_39 ( V_2 , V_19 ) ;
return V_65 - ( ( V_18 - V_19 ) & V_65 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const void * V_55 ,
T_2 V_34 )
{
bool V_35 ;
unsigned V_18 ;
T_2 V_38 ;
V_35 = V_2 -> V_39 ;
V_18 = F_39 ( V_2 , V_18 ) ;
V_38 = F_22 ( T_2 , V_34 , V_2 -> V_27 - V_18 ) ;
if ( V_38 ) {
F_15 ( V_2 -> V_66 + V_18 ,
V_55 ,
V_38 ,
V_35 ) ;
}
if ( V_38 != V_34 ) {
F_15 ( V_2 -> V_66 ,
V_55 + V_38 ,
V_34 - V_38 ,
V_35 ) ;
}
V_18 += V_34 ;
V_18 &= ( V_2 -> V_27 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_34 ;
}
static int F_41 ( struct V_1 * V_2 , const void * V_55 ,
int V_38 , bool V_67 )
{
T_4 V_68 [ 5 ] = { F_42 ( V_38 ) , } ;
int V_69 = sizeof( V_68 ) + V_38 ;
int V_42 ;
if ( V_2 -> V_39 && V_38 % 4 )
return - V_70 ;
if ( V_69 >= V_2 -> V_27 )
return - V_70 ;
V_42 = F_43 ( & V_2 -> V_71 ) ;
if ( V_42 )
return V_42 ;
while ( F_38 ( V_2 ) < V_69 ) {
if ( ! V_67 ) {
V_42 = - V_72 ;
goto V_52;
}
if ( V_2 -> V_8 != V_29 ) {
V_42 = - V_73 ;
goto V_52;
}
F_6 ( V_2 , V_17 , 0 ) ;
V_42 = F_44 ( V_2 -> V_51 ,
F_38 ( V_2 ) >= V_69 ||
V_2 -> V_8 != V_29 ) ;
if ( V_42 )
goto V_52;
F_6 ( V_2 , V_17 , 1 ) ;
}
F_6 ( V_2 , V_15 , 0 ) ;
F_40 ( V_2 , V_68 , sizeof( V_68 ) ) ;
F_40 ( V_2 , V_55 , V_38 ) ;
F_6 ( V_2 , V_14 , 1 ) ;
F_31 () ;
F_1 ( V_2 ) ;
V_52:
F_45 ( & V_2 -> V_71 ) ;
return V_42 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_1 V_21 )
{
T_2 V_74 ;
V_74 = F_47 ( V_2 -> V_27 , V_75 ) ;
V_2 -> V_43 = F_48 ( V_74 , V_76 ) ;
if ( ! V_2 -> V_43 )
return - V_77 ;
F_8 ( V_2 , V_21 ) ;
F_13 ( V_2 , V_78 ) ;
F_13 ( V_2 , V_29 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_8 ( V_2 , NULL ) ;
F_50 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_13 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
}
static struct V_1 *
F_51 ( struct V_3 * V_4 , const char * V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_42 = NULL ;
unsigned long V_25 ;
F_9 ( & V_4 -> V_59 , V_25 ) ;
F_34 (channel, &edge->channels, list) {
if ( ! strcmp ( V_2 -> V_31 , V_31 ) ) {
V_42 = V_2 ;
break;
}
}
F_10 ( & V_4 -> V_59 , V_25 ) ;
return V_42 ;
}
static void F_52 ( struct V_79 * V_79 )
{
struct V_22 * V_23 = F_53 ( V_79 , struct V_22 ,
V_80 ) ;
F_50 ( F_54 ( V_23 ) ) ;
}
static struct V_22 * F_55 ( struct V_81 * V_44 ,
T_1 V_21 , void * V_45 ,
struct V_82 V_83 )
{
struct V_84 * V_24 ;
struct V_1 * V_2 ;
struct V_85 * V_86 = F_56 ( V_44 ) ;
struct V_3 * V_4 = V_86 -> V_4 ;
struct V_22 * V_23 ;
const char * V_31 = V_83 . V_31 ;
int V_42 ;
V_42 = F_57 ( V_4 -> V_87 ,
( V_2 = F_51 ( V_4 , V_31 ) ) != NULL ,
V_88 ) ;
if ( ! V_42 )
return NULL ;
if ( V_2 -> V_8 != V_9 ) {
F_58 ( & V_44 -> V_30 , L_2 , V_2 -> V_31 ) ;
return NULL ;
}
V_24 = F_59 ( sizeof( * V_24 ) , V_76 ) ;
if ( ! V_24 )
return NULL ;
V_23 = & V_24 -> V_23 ;
F_60 ( & V_23 -> V_80 ) ;
V_23 -> V_44 = V_44 ;
V_23 -> V_21 = V_21 ;
V_23 -> V_45 = V_45 ;
V_23 -> V_89 = & V_90 ;
V_2 -> V_24 = V_24 ;
V_24 -> V_91 = V_2 ;
V_42 = F_46 ( V_2 , V_21 ) ;
if ( V_42 )
goto V_92;
return V_23 ;
V_92:
V_2 -> V_24 = NULL ;
F_61 ( & V_23 -> V_80 , F_52 ) ;
return NULL ;
}
static void F_62 ( struct V_22 * V_23 )
{
struct V_84 * V_24 = F_54 ( V_23 ) ;
struct V_1 * V_93 = V_24 -> V_91 ;
F_49 ( V_93 ) ;
V_93 -> V_24 = NULL ;
F_61 ( & V_23 -> V_80 , F_52 ) ;
}
static int F_63 ( struct V_22 * V_23 , void * V_55 , int V_38 )
{
struct V_84 * V_24 = F_54 ( V_23 ) ;
return F_41 ( V_24 -> V_91 , V_55 , V_38 , true ) ;
}
static int F_64 ( struct V_22 * V_23 , void * V_55 , int V_38 )
{
struct V_84 * V_24 = F_54 ( V_23 ) ;
return F_41 ( V_24 -> V_91 , V_55 , V_38 , false ) ;
}
static unsigned int F_65 ( struct V_22 * V_23 ,
struct V_94 * V_95 , T_6 * V_67 )
{
struct V_84 * V_24 = F_54 ( V_23 ) ;
struct V_1 * V_2 = V_24 -> V_91 ;
unsigned int V_65 = 0 ;
F_66 ( V_95 , & V_2 -> V_51 , V_67 ) ;
if ( F_38 ( V_2 ) > 20 )
V_65 |= V_96 | V_97 ;
return V_65 ;
}
static struct V_98 * F_67 ( struct V_98 * V_99 ,
const char * V_2 )
{
struct V_98 * V_100 ;
const char * V_31 ;
const char * V_101 ;
int V_42 ;
F_68 (edge_node, child) {
V_101 = L_3 ;
V_42 = F_69 ( V_100 , V_101 , & V_31 ) ;
if ( V_42 )
continue;
if ( strcmp ( V_31 , V_2 ) == 0 )
return V_100 ;
}
return NULL ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_85 * V_86 ;
struct V_81 * V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_14 ( & V_4 -> V_30 , L_4 , V_2 -> V_31 ) ;
V_86 = F_59 ( sizeof( * V_86 ) , V_76 ) ;
if ( ! V_86 )
return - V_77 ;
V_86 -> V_4 = V_4 ;
V_86 -> V_44 . V_89 = & V_102 ;
V_44 = & V_86 -> V_44 ;
strncpy ( V_44 -> V_103 . V_31 , V_2 -> V_31 , V_104 ) ;
V_44 -> V_33 = V_46 ;
V_44 -> V_32 = V_46 ;
V_44 -> V_30 . V_105 = F_67 ( V_4 -> V_105 , V_2 -> V_31 ) ;
V_44 -> V_30 . V_106 = & V_4 -> V_30 ;
return F_71 ( V_44 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_85 * V_86 ;
V_86 = F_59 ( sizeof( * V_86 ) , V_76 ) ;
if ( ! V_86 )
return - V_77 ;
V_86 -> V_4 = V_4 ;
V_86 -> V_44 . V_89 = & V_102 ;
V_86 -> V_44 . V_30 . V_106 = & V_4 -> V_30 ;
return F_73 ( & V_86 -> V_44 ) ;
}
static struct V_1 * F_74 ( struct V_3 * V_4 ,
unsigned V_107 ,
unsigned V_108 ,
char * V_31 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
T_2 V_109 ;
void * V_110 ;
void * V_111 ;
int V_42 ;
V_2 = F_75 ( & V_4 -> V_30 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return F_76 ( - V_77 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_31 = F_77 ( & V_4 -> V_30 , V_31 , V_76 ) ;
if ( ! V_2 -> V_31 )
return F_76 ( - V_77 ) ;
F_78 ( & V_2 -> V_71 ) ;
F_79 ( & V_2 -> V_26 ) ;
F_80 ( & V_2 -> V_51 ) ;
V_111 = F_81 ( V_4 -> V_60 , V_107 , & V_109 ) ;
if ( F_82 ( V_111 ) ) {
V_42 = F_83 ( V_111 ) ;
goto V_112;
}
if ( V_109 == 2 * sizeof( struct V_113 ) ) {
V_2 -> V_39 = V_111 ;
} else if ( V_109 == 2 * sizeof( struct V_114 ) ) {
V_2 -> V_111 = V_111 ;
} else {
F_58 ( & V_4 -> V_30 ,
L_5 , V_109 ) ;
V_42 = - V_70 ;
goto V_112;
}
V_110 = F_81 ( V_4 -> V_60 , V_108 , & V_27 ) ;
if ( F_82 ( V_110 ) ) {
V_42 = F_83 ( V_110 ) ;
goto V_112;
}
V_27 /= 2 ;
F_14 ( & V_4 -> V_30 , L_6 ,
V_31 , V_109 , V_27 ) ;
V_2 -> V_66 = V_110 ;
V_2 -> V_40 = V_110 + V_27 ;
V_2 -> V_27 = V_27 ;
F_4 ( V_2 ) ;
return V_2 ;
V_112:
F_84 ( & V_4 -> V_30 , V_2 -> V_31 ) ;
F_84 ( & V_4 -> V_30 , V_2 ) ;
return F_76 ( V_42 ) ;
}
static void F_85 ( struct V_115 * V_116 )
{
struct V_3 * V_4 = F_53 ( V_116 , struct V_3 , V_62 ) ;
struct V_117 * V_118 ;
struct V_117 * V_119 ;
struct V_1 * V_2 ;
unsigned long V_25 ;
unsigned V_120 ;
unsigned V_121 ;
int V_122 ;
int V_123 ;
V_36 V_124 , V_125 ;
for ( V_122 = 0 ; V_122 < V_126 ; V_122 ++ ) {
V_118 = F_81 ( V_4 -> V_60 ,
V_127 [ V_122 ] . V_128 , NULL ) ;
if ( F_82 ( V_118 ) )
continue;
for ( V_123 = 0 ; V_123 < V_129 ; V_123 ++ ) {
V_119 = & V_118 [ V_123 ] ;
V_124 = F_29 ( V_119 -> V_25 ) ;
if ( F_86 ( V_123 , V_4 -> V_130 [ V_122 ] ) )
continue;
if ( V_119 -> V_131 == 0 )
continue;
if ( ! V_119 -> V_31 [ 0 ] )
continue;
if ( ! ( V_124 & V_132 ) )
continue;
if ( ( V_124 & V_133 ) != V_4 -> V_134 )
continue;
V_125 = F_29 ( V_119 -> V_125 ) ;
V_121 = V_127 [ V_122 ] . V_135 + V_125 ;
V_120 = V_127 [ V_122 ] . V_136 + V_125 ;
V_2 = F_74 ( V_4 , V_121 , V_120 , V_119 -> V_31 ) ;
if ( F_82 ( V_2 ) )
continue;
F_9 ( & V_4 -> V_59 , V_25 ) ;
F_87 ( & V_2 -> V_137 , & V_4 -> V_138 ) ;
F_10 ( & V_4 -> V_59 , V_25 ) ;
F_14 ( & V_4 -> V_30 , L_7 , V_2 -> V_31 ) ;
F_88 ( V_123 , V_4 -> V_130 [ V_122 ] ) ;
F_28 ( & V_4 -> V_87 ) ;
}
}
F_37 ( & V_4 -> V_63 ) ;
}
static void F_89 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_53 ( V_116 ,
struct V_3 ,
V_63 ) ;
struct V_82 V_83 ;
unsigned V_48 ;
unsigned long V_25 ;
F_9 ( & V_4 -> V_59 , V_25 ) ;
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_48 = F_12 ( V_2 , V_8 ) ;
if ( V_48 != V_78 &&
V_48 != V_29 )
continue;
if ( V_2 -> V_139 )
continue;
F_10 ( & V_4 -> V_59 , V_25 ) ;
F_70 ( V_2 ) ;
V_2 -> V_139 = true ;
F_9 ( & V_4 -> V_59 , V_25 ) ;
V_2 -> V_139 = true ;
}
F_34 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_78 &&
V_2 -> V_8 != V_29 )
continue;
V_48 = F_12 ( V_2 , V_8 ) ;
if ( V_48 == V_78 ||
V_48 == V_29 )
continue;
F_10 ( & V_4 -> V_59 , V_25 ) ;
strncpy ( V_83 . V_31 , V_2 -> V_31 , sizeof( V_83 . V_31 ) ) ;
V_83 . V_33 = V_46 ;
V_83 . V_32 = V_46 ;
F_90 ( & V_4 -> V_30 , & V_83 ) ;
V_2 -> V_139 = false ;
F_9 ( & V_4 -> V_59 , V_25 ) ;
}
F_10 ( & V_4 -> V_59 , V_25 ) ;
}
static int F_91 ( struct V_140 * V_30 ,
struct V_98 * V_141 ,
struct V_3 * V_4 )
{
struct V_98 * V_142 ;
const char * V_101 ;
int V_54 ;
int V_42 ;
F_92 ( & V_4 -> V_138 ) ;
F_79 ( & V_4 -> V_59 ) ;
F_93 ( & V_4 -> V_62 , F_85 ) ;
F_93 ( & V_4 -> V_63 , F_89 ) ;
V_4 -> V_105 = F_94 ( V_141 ) ;
V_101 = L_8 ;
V_42 = F_95 ( V_141 , V_101 , & V_4 -> V_134 ) ;
if ( V_42 ) {
F_58 ( V_30 , L_9 , V_101 ) ;
return - V_70 ;
}
V_4 -> V_60 = V_143 ;
V_101 = L_10 ;
F_95 ( V_141 , V_101 , & V_4 -> V_60 ) ;
V_142 = F_96 ( V_141 , L_11 , 0 ) ;
if ( ! V_142 ) {
F_58 ( V_30 , L_12 ) ;
return - V_144 ;
}
V_4 -> V_5 = F_97 ( V_142 ) ;
if ( F_82 ( V_4 -> V_5 ) )
return F_83 ( V_4 -> V_5 ) ;
V_101 = L_11 ;
V_42 = F_98 ( V_141 , V_101 , 1 , & V_4 -> V_6 ) ;
if ( V_42 < 0 ) {
F_58 ( V_30 , L_13 , V_101 ) ;
return - V_70 ;
}
V_42 = F_98 ( V_141 , V_101 , 2 , & V_4 -> V_7 ) ;
if ( V_42 < 0 ) {
F_58 ( V_30 , L_14 , V_101 ) ;
return - V_70 ;
}
V_42 = F_69 ( V_141 , L_15 , & V_4 -> V_31 ) ;
if ( V_42 < 0 )
V_4 -> V_31 = V_141 -> V_31 ;
V_54 = F_99 ( V_141 , 0 ) ;
if ( V_54 < 0 ) {
F_58 ( V_30 , L_16 ) ;
return - V_70 ;
}
V_42 = F_100 ( V_30 , V_54 ,
F_32 , V_145 ,
V_141 -> V_31 , V_4 ) ;
if ( V_42 ) {
F_58 ( V_30 , L_17 ) ;
return V_42 ;
}
V_4 -> V_54 = V_54 ;
return 0 ;
}
static void F_101 ( struct V_140 * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_102 ( V_30 ) ;
F_34 (channel, &edge->channels, list) {
F_7 ( V_2 , V_8 , V_9 ) ;
F_7 ( V_2 , V_18 , 0 ) ;
F_7 ( V_2 , V_19 , 0 ) ;
}
F_50 ( V_4 ) ;
}
static T_7 F_103 ( struct V_140 * V_30 ,
struct V_146 * V_147 , char * V_37 )
{
struct V_3 * V_4 = F_102 ( V_30 ) ;
return sprintf ( V_37 , L_18 , V_4 -> V_31 ) ;
}
struct V_3 * F_104 ( struct V_140 * V_106 ,
struct V_98 * V_141 )
{
struct V_3 * V_4 ;
int V_42 ;
V_4 = F_59 ( sizeof( * V_4 ) , V_76 ) ;
if ( ! V_4 )
return F_76 ( - V_77 ) ;
F_80 ( & V_4 -> V_87 ) ;
V_4 -> V_30 . V_106 = V_106 ;
V_4 -> V_30 . V_148 = F_101 ;
V_4 -> V_30 . V_149 = V_150 ;
F_105 ( & V_4 -> V_30 , L_19 , F_106 ( V_106 ) , V_141 -> V_31 ) ;
V_42 = F_107 ( & V_4 -> V_30 ) ;
if ( V_42 ) {
F_108 ( L_20 ) ;
return F_76 ( V_42 ) ;
}
V_42 = F_91 ( & V_4 -> V_30 , V_141 , V_4 ) ;
if ( V_42 ) {
F_58 ( & V_4 -> V_30 , L_21 ) ;
goto V_151;
}
V_42 = F_72 ( V_4 ) ;
if ( V_42 ) {
F_58 ( & V_4 -> V_30 , L_22 ) ;
goto V_151;
}
F_37 ( & V_4 -> V_62 ) ;
return V_4 ;
V_151:
F_109 ( & V_4 -> V_30 ) ;
return F_76 ( V_42 ) ;
}
static int F_110 ( struct V_140 * V_30 , void * V_55 )
{
F_111 ( V_30 ) ;
return 0 ;
}
int F_112 ( struct V_3 * V_4 )
{
int V_42 ;
F_113 ( V_4 -> V_54 ) ;
F_114 ( & V_4 -> V_62 ) ;
F_114 ( & V_4 -> V_63 ) ;
V_42 = F_115 ( & V_4 -> V_30 , NULL , F_110 ) ;
if ( V_42 )
F_116 ( & V_4 -> V_30 , L_23 , V_42 ) ;
F_111 ( & V_4 -> V_30 ) ;
return 0 ;
}
static int F_117 ( struct V_152 * V_153 )
{
struct V_98 * V_141 ;
void * V_154 ;
V_154 = F_81 ( V_143 , V_127 [ 0 ] . V_128 , NULL ) ;
if ( F_83 ( V_154 ) == - V_155 )
return F_83 ( V_154 ) ;
F_68 (pdev->dev.of_node, node)
F_104 ( & V_153 -> V_30 , V_141 ) ;
return 0 ;
}
static int F_118 ( struct V_140 * V_30 , void * V_55 )
{
struct V_3 * V_4 = F_102 ( V_30 ) ;
return F_112 ( V_4 ) ;
}
static int F_119 ( struct V_152 * V_153 )
{
int V_42 ;
V_42 = F_115 ( & V_153 -> V_30 , NULL , F_118 ) ;
if ( V_42 )
F_116 ( & V_153 -> V_30 , L_23 , V_42 ) ;
return V_42 ;
}
static int T_8 F_120 ( void )
{
return F_121 ( & V_156 ) ;
}
static void T_9 F_122 ( void )
{
F_123 ( & V_156 ) ;
}
