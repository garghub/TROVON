static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 -> V_5 , V_4 -> V_6 , F_3 ( V_4 -> V_7 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_8 , V_9 ) ;
F_5 ( V_2 , V_10 , 0 ) ;
F_5 ( V_2 , V_11 , 0 ) ;
F_5 ( V_2 , V_12 , 0 ) ;
F_5 ( V_2 , V_13 , 0 ) ;
F_5 ( V_2 , V_14 , 0 ) ;
F_5 ( V_2 , V_15 , 0 ) ;
F_5 ( V_2 , V_16 , 1 ) ;
F_5 ( V_2 , V_17 , 1 ) ;
F_5 ( V_2 , V_18 , 0 ) ;
F_5 ( V_2 , V_19 , 0 ) ;
F_1 ( V_2 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_20 = 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
V_18 = F_7 ( V_2 , V_18 ) ;
V_19 = F_7 ( V_2 , V_19 ) ;
return ( V_18 - V_19 ) & ( V_2 -> V_21 - 1 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_22 = V_8 == V_23 ;
if ( V_2 -> V_8 == V_8 )
return;
F_9 ( V_4 -> V_24 -> V_25 , L_1 , V_2 -> V_26 , V_8 ) ;
F_5 ( V_2 , V_10 , V_22 ) ;
F_5 ( V_2 , V_11 , V_22 ) ;
F_5 ( V_2 , V_12 , V_22 ) ;
F_5 ( V_2 , V_8 , V_8 ) ;
F_5 ( V_2 , V_16 , 1 ) ;
V_2 -> V_8 = V_8 ;
F_1 ( V_2 ) ;
}
static void F_10 ( void T_2 * V_27 ,
const void * V_28 ,
T_1 V_29 ,
bool V_30 )
{
T_3 * V_31 = ( T_3 * ) V_27 ;
T_3 * V_32 = ( T_3 * ) V_28 ;
if ( V_30 ) {
V_29 /= sizeof( T_3 ) ;
while ( V_29 -- )
F_11 ( * V_32 ++ , V_31 ++ ) ;
} else {
F_12 ( V_27 , V_28 , V_29 ) ;
}
}
static void F_13 ( void * V_27 ,
const void T_2 * V_28 ,
T_1 V_29 ,
bool V_30 )
{
T_3 * V_31 = ( T_3 * ) V_27 ;
T_3 * V_32 = ( T_3 * ) V_28 ;
if ( V_30 ) {
V_29 /= sizeof( T_3 ) ;
while ( V_29 -- )
* V_31 ++ = F_14 ( V_32 ++ ) ;
} else {
F_15 ( V_27 , V_28 , V_29 ) ;
}
}
static T_1 F_16 ( struct V_1 * V_2 ,
void * V_33 , T_1 V_29 )
{
bool V_30 ;
unsigned V_19 ;
T_1 V_34 ;
V_30 = V_2 -> V_35 != NULL ;
V_19 = F_7 ( V_2 , V_19 ) ;
V_34 = F_17 ( T_1 , V_29 , V_2 -> V_21 - V_19 ) ;
if ( V_34 ) {
F_13 ( V_33 ,
V_2 -> V_36 + V_19 ,
V_34 ,
V_30 ) ;
}
if ( V_34 != V_29 ) {
F_13 ( V_33 + V_34 ,
V_2 -> V_36 ,
V_29 - V_34 ,
V_30 ) ;
}
return V_29 ;
}
static void F_18 ( struct V_1 * V_2 ,
T_1 V_29 )
{
unsigned V_19 ;
V_19 = F_7 ( V_2 , V_19 ) ;
V_19 += V_29 ;
V_19 &= ( V_2 -> V_21 - 1 ) ;
F_19 ( V_2 , V_19 , V_19 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
unsigned V_19 ;
T_1 V_34 ;
void * V_39 ;
int V_40 ;
if ( ! V_2 -> V_41 )
return 0 ;
V_19 = F_7 ( V_2 , V_19 ) ;
if ( V_19 + V_2 -> V_20 >= V_2 -> V_21 ) {
V_39 = V_2 -> V_42 ;
V_34 = F_16 ( V_2 , V_39 , V_2 -> V_20 ) ;
} else {
V_39 = V_2 -> V_36 + V_19 ;
V_34 = V_2 -> V_20 ;
}
V_40 = V_2 -> V_41 ( V_38 , V_39 , V_34 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( V_2 , V_34 ) ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
bool V_43 = false ;
int V_44 ;
T_3 V_45 ;
int V_46 ;
int V_40 ;
V_44 = F_7 ( V_2 , V_8 ) ;
if ( V_44 != V_2 -> V_44 ) {
V_2 -> V_44 = V_44 ;
V_43 = true ;
}
F_19 ( V_2 , V_16 , 0 ) ;
if ( ! F_22 ( V_2 , V_17 ) )
F_23 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_8 != V_23 )
goto V_48;
F_19 ( V_2 , V_14 , 0 ) ;
for (; ; ) {
V_46 = F_6 ( V_2 ) ;
if ( ! V_2 -> V_20 && V_46 >= V_49 ) {
F_16 ( V_2 , & V_45 , sizeof( V_45 ) ) ;
F_18 ( V_2 , V_49 ) ;
V_2 -> V_20 = V_45 ;
} else if ( V_2 -> V_20 && V_46 >= V_2 -> V_20 ) {
V_40 = F_20 ( V_2 ) ;
if ( V_40 )
break;
} else {
break;
}
}
F_19 ( V_2 , V_15 , 1 ) ;
if ( ! F_7 ( V_2 , V_17 ) ) {
F_24 () ;
F_1 ( V_2 ) ;
}
V_48:
return V_43 ;
}
static T_4 F_25 ( int V_50 , void * V_51 )
{
struct V_3 * V_4 = V_51 ;
struct V_1 * V_2 ;
unsigned V_52 ;
bool V_53 = false ;
F_26 ( & V_4 -> V_54 ) ;
F_27 (channel, &edge->channels, list) {
F_26 ( & V_2 -> V_55 ) ;
V_53 |= F_21 ( V_2 ) ;
F_28 ( & V_2 -> V_55 ) ;
}
F_28 ( & V_4 -> V_54 ) ;
V_52 = F_29 ( V_4 -> V_56 ) ;
if ( V_52 != V_4 -> V_57 ) {
V_4 -> V_57 = V_52 ;
V_4 -> V_58 = true ;
V_53 = true ;
}
if ( V_53 )
F_30 ( & V_4 -> V_59 ) ;
return V_60 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned long V_61 ;
F_32 ( & V_2 -> V_55 , V_61 ) ;
F_21 ( V_2 ) ;
F_33 ( & V_2 -> V_55 , V_61 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_62 = V_2 -> V_21 - 1 ;
V_18 = F_22 ( V_2 , V_18 ) ;
V_19 = F_22 ( V_2 , V_19 ) ;
return V_62 - ( ( V_18 - V_19 ) & V_62 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
const void * V_51 ,
T_1 V_29 )
{
bool V_30 ;
unsigned V_18 ;
T_1 V_34 ;
V_30 = V_2 -> V_63 != NULL ;
V_18 = F_22 ( V_2 , V_18 ) ;
V_34 = F_17 ( T_1 , V_29 , V_2 -> V_21 - V_18 ) ;
if ( V_34 ) {
F_10 ( V_2 -> V_64 + V_18 ,
V_51 ,
V_34 ,
V_30 ) ;
}
if ( V_34 != V_29 ) {
F_10 ( V_2 -> V_64 ,
V_51 + V_34 ,
V_29 - V_34 ,
V_30 ) ;
}
V_18 += V_29 ;
V_18 &= ( V_2 -> V_21 - 1 ) ;
F_5 ( V_2 , V_18 , V_18 ) ;
return V_29 ;
}
int F_36 ( struct V_1 * V_2 , const void * V_51 , int V_34 )
{
T_3 V_65 [ 5 ] = { V_34 ,} ;
int V_66 = sizeof( V_65 ) + V_34 ;
int V_40 ;
if ( V_2 -> V_35 != NULL && V_34 % 4 )
return - V_67 ;
V_40 = F_37 ( & V_2 -> V_68 ) ;
if ( V_40 )
return V_40 ;
while ( F_34 ( V_2 ) < V_66 ) {
if ( V_2 -> V_8 != V_23 ) {
V_40 = - V_69 ;
goto V_48;
}
F_5 ( V_2 , V_17 , 0 ) ;
V_40 = F_38 ( V_2 -> V_47 ,
F_34 ( V_2 ) >= V_66 ||
V_2 -> V_8 != V_23 ) ;
if ( V_40 )
goto V_48;
F_5 ( V_2 , V_17 , 1 ) ;
}
F_5 ( V_2 , V_15 , 0 ) ;
F_35 ( V_2 , V_65 , sizeof( V_65 ) ) ;
F_35 ( V_2 , V_51 , V_34 ) ;
F_5 ( V_2 , V_14 , 1 ) ;
F_24 () ;
F_1 ( V_2 ) ;
V_48:
F_39 ( & V_2 -> V_68 ) ;
return V_40 ;
}
static struct V_37 * F_40 ( struct V_70 * V_25 )
{
return F_41 ( V_25 , struct V_37 , V_25 ) ;
}
static struct V_71 * F_42 ( struct V_70 * V_25 )
{
struct V_37 * V_38 = F_40 ( V_25 ) ;
return F_41 ( V_38 -> V_25 . V_72 , struct V_71 , V_72 ) ;
}
static int F_43 ( struct V_70 * V_25 , struct V_73 * V_74 )
{
return F_44 ( V_25 , V_74 ) ;
}
static int F_45 ( struct V_70 * V_25 )
{
struct V_37 * V_38 = F_40 ( V_25 ) ;
struct V_71 * V_75 = F_42 ( V_25 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
T_1 V_76 ;
int V_40 ;
V_76 = F_46 ( V_2 -> V_21 , V_77 ) ;
V_2 -> V_42 = F_47 ( V_76 , V_78 ) ;
if ( ! V_2 -> V_42 )
return - V_79 ;
V_2 -> V_41 = V_75 -> V_80 ;
F_8 ( V_2 , V_81 ) ;
F_8 ( V_2 , V_23 ) ;
V_40 = V_75 -> V_82 ( V_38 ) ;
if ( V_40 )
goto V_83;
F_31 ( V_2 ) ;
return 0 ;
V_83:
F_48 ( & V_38 -> V_25 , L_2 ) ;
V_2 -> V_41 = NULL ;
F_49 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
F_8 ( V_2 , V_9 ) ;
return V_40 ;
}
static int F_50 ( struct V_70 * V_25 )
{
struct V_37 * V_38 = F_40 ( V_25 ) ;
struct V_71 * V_75 = F_42 ( V_25 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
unsigned long V_61 ;
F_8 ( V_2 , V_84 ) ;
F_32 ( & V_2 -> V_55 , V_61 ) ;
V_2 -> V_41 = NULL ;
F_33 ( & V_2 -> V_55 , V_61 ) ;
F_23 ( & V_2 -> V_47 ) ;
if ( V_75 -> remove )
V_75 -> remove ( V_38 ) ;
V_2 -> V_38 = NULL ;
F_49 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
F_8 ( V_2 , V_9 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_70 * V_25 )
{
struct V_37 * V_38 = F_40 ( V_25 ) ;
F_49 ( V_38 ) ;
}
static struct V_85 * F_52 ( struct V_85 * V_86 ,
const char * V_2 )
{
struct V_85 * V_87 ;
const char * V_26 ;
const char * V_88 ;
int V_40 ;
F_53 (edge_node, child) {
V_88 = L_3 ;
V_40 = F_54 ( V_87 , V_88 , & V_26 ) ;
if ( V_40 ) {
F_55 ( V_87 ) ;
continue;
}
if ( strcmp ( V_26 , V_2 ) == 0 )
return V_87 ;
}
return NULL ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_85 * V_89 ;
struct V_90 * V_24 = V_4 -> V_24 ;
int V_40 ;
if ( V_2 -> V_38 )
return - V_91 ;
V_89 = F_52 ( V_4 -> V_92 , V_2 -> V_26 ) ;
if ( ! V_89 ) {
F_9 ( V_24 -> V_25 , L_4 , V_2 -> V_26 ) ;
return - V_93 ;
}
F_9 ( V_24 -> V_25 , L_5 , V_2 -> V_26 ) ;
V_38 = F_57 ( sizeof( * V_38 ) , V_78 ) ;
if ( ! V_38 )
return - V_79 ;
F_58 ( & V_38 -> V_25 , L_6 , V_4 -> V_92 -> V_26 , V_89 -> V_26 ) ;
V_38 -> V_25 . V_94 = V_24 -> V_25 ;
V_38 -> V_25 . V_95 = & V_96 ;
V_38 -> V_25 . V_97 = F_51 ;
V_38 -> V_25 . V_92 = V_89 ;
V_38 -> V_2 = V_2 ;
V_2 -> V_38 = V_38 ;
V_40 = F_59 ( & V_38 -> V_25 ) ;
if ( V_40 ) {
F_48 ( V_24 -> V_25 , L_7 , V_40 ) ;
F_60 ( & V_38 -> V_25 ) ;
}
return V_40 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_70 * V_25 ;
F_62 ( ! V_2 -> V_38 ) ;
V_25 = & V_2 -> V_38 -> V_25 ;
F_63 ( V_25 ) ;
F_55 ( V_25 -> V_92 ) ;
F_60 ( V_25 ) ;
}
int F_64 ( struct V_71 * V_75 )
{
V_75 -> V_72 . V_95 = & V_96 ;
return F_65 ( & V_75 -> V_72 ) ;
}
void F_66 ( struct V_71 * V_75 )
{
F_67 ( & V_75 -> V_72 ) ;
}
static struct V_1 * F_68 ( struct V_3 * V_4 ,
unsigned V_98 ,
unsigned V_99 ,
char * V_26 )
{
struct V_1 * V_2 ;
struct V_90 * V_24 = V_4 -> V_24 ;
T_1 V_21 ;
T_1 V_100 ;
void * V_101 ;
void * V_102 ;
int V_40 ;
V_2 = F_69 ( V_24 -> V_25 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return F_70 ( - V_79 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_26 = F_71 ( V_24 -> V_25 , V_26 , V_78 ) ;
if ( ! V_2 -> V_26 )
return F_70 ( - V_79 ) ;
F_72 ( & V_2 -> V_68 ) ;
F_73 ( & V_2 -> V_55 ) ;
F_74 ( & V_2 -> V_47 ) ;
V_40 = F_75 ( V_4 -> V_56 , V_98 , ( void * * ) & V_102 ,
& V_100 ) ;
if ( V_40 )
goto V_103;
if ( V_100 == 2 * sizeof( struct V_104 ) ) {
V_2 -> V_63 = V_102 ;
V_2 -> V_35 = V_102 + sizeof( struct V_104 ) ;
} else if ( V_100 == 2 * sizeof( struct V_105 ) ) {
V_2 -> V_106 = V_102 ;
V_2 -> V_107 = V_102 + sizeof( struct V_105 ) ;
} else {
F_48 ( V_24 -> V_25 ,
L_8 , V_100 ) ;
V_40 = - V_67 ;
goto V_103;
}
V_40 = F_75 ( V_4 -> V_56 , V_99 , & V_101 ,
& V_21 ) ;
if ( V_40 )
goto V_103;
V_21 /= 2 ;
F_9 ( V_24 -> V_25 , L_9 ,
V_26 , V_100 , V_21 ) ;
V_2 -> V_64 = V_101 ;
V_2 -> V_36 = V_101 + V_21 ;
V_2 -> V_21 = V_21 ;
F_4 ( V_2 ) ;
return V_2 ;
V_103:
F_76 ( V_24 -> V_25 , V_2 -> V_26 ) ;
F_76 ( V_24 -> V_25 , V_2 ) ;
return F_70 ( V_40 ) ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_108 * V_109 ;
struct V_108 * V_110 ;
struct V_1 * V_2 ;
struct V_90 * V_24 = V_4 -> V_24 ;
unsigned long V_61 ;
unsigned V_111 ;
unsigned V_112 ;
int V_40 ;
int V_113 ;
int V_114 ;
for ( V_113 = 0 ; V_113 < V_115 ; V_113 ++ ) {
V_40 = F_75 ( V_4 -> V_56 ,
V_116 [ V_113 ] . V_117 ,
( void * * ) & V_109 ,
NULL ) ;
if ( V_40 < 0 )
continue;
for ( V_114 = 0 ; V_114 < V_118 ; V_114 ++ ) {
V_110 = & V_109 [ V_114 ] ;
if ( F_78 ( V_114 , V_4 -> V_119 [ V_113 ] ) )
continue;
if ( V_110 -> V_120 == 0 )
continue;
if ( ! V_110 -> V_26 [ 0 ] )
continue;
if ( ! ( V_110 -> V_61 & V_121 ) )
continue;
if ( ( V_110 -> V_61 & V_122 ) != V_4 -> V_123 )
continue;
V_112 = V_116 [ V_113 ] . V_124 + V_110 -> V_125 ;
V_111 = V_116 [ V_113 ] . V_126 + V_110 -> V_125 ;
V_2 = F_68 ( V_4 , V_112 , V_111 , V_110 -> V_26 ) ;
if ( F_79 ( V_2 ) )
continue;
F_32 ( & V_4 -> V_54 , V_61 ) ;
F_80 ( & V_2 -> V_127 , & V_4 -> V_128 ) ;
F_33 ( & V_4 -> V_54 , V_61 ) ;
F_9 ( V_24 -> V_25 , L_10 , V_2 -> V_26 ) ;
F_81 ( V_114 , V_4 -> V_119 [ V_113 ] ) ;
}
}
F_30 ( & V_4 -> V_59 ) ;
}
static void F_82 ( struct V_129 * V_59 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_41 ( V_59 ,
struct V_3 ,
V_59 ) ;
unsigned V_44 ;
if ( V_4 -> V_58 ) {
V_4 -> V_58 = false ;
F_77 ( V_4 ) ;
}
F_27 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_9 )
continue;
V_44 = F_7 ( V_2 , V_8 ) ;
if ( V_44 != V_81 &&
V_44 != V_23 )
continue;
F_56 ( V_2 ) ;
}
F_27 (channel, &edge->channels, list) {
if ( V_2 -> V_8 != V_81 &&
V_2 -> V_8 != V_23 )
continue;
V_44 = F_7 ( V_2 , V_8 ) ;
if ( V_44 == V_81 ||
V_44 == V_23 )
continue;
F_61 ( V_2 ) ;
}
}
static int F_83 ( struct V_70 * V_25 ,
struct V_85 * V_89 ,
struct V_3 * V_4 )
{
struct V_85 * V_130 ;
const char * V_88 ;
int V_50 ;
int V_40 ;
F_84 ( & V_4 -> V_128 ) ;
F_73 ( & V_4 -> V_54 ) ;
F_85 ( & V_4 -> V_59 , F_82 ) ;
V_4 -> V_92 = F_86 ( V_89 ) ;
V_50 = F_87 ( V_89 , 0 ) ;
if ( V_50 < 0 ) {
F_48 ( V_25 , L_11 ) ;
return - V_67 ;
}
V_40 = F_88 ( V_25 , V_50 ,
F_25 , V_131 ,
V_89 -> V_26 , V_4 ) ;
if ( V_40 ) {
F_48 ( V_25 , L_12 ) ;
return V_40 ;
}
V_4 -> V_50 = V_50 ;
V_88 = L_13 ;
V_40 = F_89 ( V_89 , V_88 , & V_4 -> V_123 ) ;
if ( V_40 ) {
F_48 ( V_25 , L_14 , V_88 ) ;
return - V_67 ;
}
V_4 -> V_56 = V_132 ;
V_88 = L_15 ;
F_89 ( V_89 , V_88 , & V_4 -> V_56 ) ;
V_130 = F_90 ( V_89 , L_16 , 0 ) ;
if ( ! V_130 ) {
F_48 ( V_25 , L_17 ) ;
return - V_133 ;
}
V_4 -> V_5 = F_91 ( V_130 ) ;
if ( F_79 ( V_4 -> V_5 ) )
return F_92 ( V_4 -> V_5 ) ;
V_88 = L_16 ;
V_40 = F_93 ( V_89 , V_88 , 1 , & V_4 -> V_6 ) ;
if ( V_40 < 0 ) {
F_48 ( V_25 , L_18 , V_88 ) ;
return - V_67 ;
}
V_40 = F_93 ( V_89 , V_88 , 2 , & V_4 -> V_7 ) ;
if ( V_40 < 0 ) {
F_48 ( V_25 , L_19 , V_88 ) ;
return - V_67 ;
}
return 0 ;
}
static int F_94 ( struct V_134 * V_135 )
{
struct V_3 * V_4 ;
struct V_85 * V_89 ;
struct V_90 * V_24 ;
T_1 V_136 ;
int V_137 ;
int V_40 ;
int V_114 = 0 ;
V_40 = F_75 ( V_132 , V_116 [ 0 ] . V_117 , NULL , NULL ) ;
if ( V_40 == - V_138 )
return V_40 ;
V_137 = F_95 ( V_135 -> V_25 . V_92 ) ;
V_136 = sizeof( * V_24 ) + V_137 * sizeof( struct V_3 ) ;
V_24 = F_69 ( & V_135 -> V_25 , V_136 , V_78 ) ;
if ( ! V_24 )
return - V_79 ;
V_24 -> V_25 = & V_135 -> V_25 ;
V_24 -> V_137 = V_137 ;
F_53 (pdev->dev.of_node, node) {
V_4 = & V_24 -> V_139 [ V_114 ++ ] ;
V_4 -> V_24 = V_24 ;
V_40 = F_83 ( & V_135 -> V_25 , V_89 , V_4 ) ;
if ( V_40 )
continue;
V_4 -> V_58 = true ;
F_30 ( & V_4 -> V_59 ) ;
}
F_96 ( V_135 , V_24 ) ;
return 0 ;
}
static int F_97 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_90 * V_24 = F_98 ( V_135 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_24 -> V_137 ; V_114 ++ ) {
V_4 = & V_24 -> V_139 [ V_114 ] ;
F_99 ( V_4 -> V_50 ) ;
F_100 ( & V_4 -> V_59 ) ;
F_27 (channel, &edge->channels, list) {
if ( ! V_2 -> V_38 )
continue;
F_61 ( V_2 ) ;
}
}
return 0 ;
}
static int T_5 F_101 ( void )
{
int V_40 ;
V_40 = F_102 ( & V_96 ) ;
if ( V_40 ) {
F_103 ( L_20 , V_40 ) ;
return V_40 ;
}
return F_104 ( & V_71 ) ;
}
static void T_6 F_105 ( void )
{
F_106 ( & V_71 ) ;
F_107 ( & V_96 ) ;
}
