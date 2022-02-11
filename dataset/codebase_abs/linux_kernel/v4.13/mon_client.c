struct V_1 * F_1 ( void * V_2 , void * V_3 )
{
struct V_1 * V_4 = NULL ;
int V_5 , V_6 = - V_7 ;
struct V_8 V_9 ;
T_1 V_10 , V_11 ;
T_1 V_12 ;
F_2 ( & V_2 , V_3 , V_12 , V_13 ) ;
F_3 ( & V_2 , V_3 , V_12 , V_13 ) ;
F_4 ( L_1 , V_2 , V_3 , ( int ) ( V_3 - V_2 ) ) ;
V_2 += sizeof( V_14 ) ;
F_3 ( & V_2 , V_3 , sizeof( V_9 ) + 2 * sizeof( T_1 ) , V_13 ) ;
F_5 ( & V_2 , & V_9 , sizeof( V_9 ) ) ;
V_10 = F_6 ( & V_2 ) ;
V_11 = F_6 ( & V_2 ) ;
F_3 ( & V_2 , V_3 , V_11 * sizeof( V_4 -> V_15 [ 0 ] ) , V_13 ) ;
if ( V_11 >= V_16 )
goto V_13;
V_4 = F_7 ( sizeof( * V_4 ) + sizeof( V_4 -> V_15 [ 0 ] ) * V_11 , V_17 ) ;
if ( V_4 == NULL )
return F_8 ( - V_18 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
F_5 ( & V_2 , V_4 -> V_15 , V_11 * sizeof( V_4 -> V_15 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ )
F_9 ( & V_4 -> V_15 [ V_5 ] . V_19 ) ;
F_4 ( L_2 , V_4 -> V_10 ,
V_4 -> V_11 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_11 ; V_5 ++ )
F_4 ( L_3 , V_5 ,
F_10 ( & V_4 -> V_15 [ V_5 ] . V_19 . V_20 ) ) ;
return V_4 ;
V_13:
F_4 ( L_4 , V_6 ) ;
F_11 ( V_4 ) ;
return F_8 ( V_6 ) ;
}
int F_12 ( struct V_1 * V_4 , struct V_21 * V_19 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_11 ; V_5 ++ )
if ( memcmp ( V_19 , & V_4 -> V_15 [ V_5 ] . V_19 , sizeof( * V_19 ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_13 ( struct V_22 * V_23 , int V_12 )
{
V_23 -> V_24 = 1 ;
V_23 -> V_25 -> V_26 . V_27 = V_12 ;
V_23 -> V_25 -> V_28 . V_29 = F_14 ( V_12 ) ;
F_15 ( V_23 -> V_25 ) ;
F_16 ( V_23 -> V_25 ) ;
F_17 ( & V_23 -> V_30 , V_23 -> V_25 ) ;
}
static void F_18 ( struct V_22 * V_23 )
{
F_4 ( L_5 , V_23 -> V_31 ) ;
F_15 ( V_23 -> V_25 ) ;
F_19 ( V_23 -> V_32 ) ;
F_15 ( V_23 -> V_33 ) ;
F_19 ( V_23 -> V_34 ) ;
F_20 ( & V_23 -> V_30 ) ;
V_23 -> V_24 = 0 ;
F_21 ( V_23 -> V_35 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
int V_36 = V_23 -> V_31 ;
F_23 ( V_23 -> V_37 -> V_11 < 1 ) ;
if ( V_23 -> V_37 -> V_11 == 1 ) {
V_23 -> V_31 = 0 ;
} else {
int V_38 = V_23 -> V_37 -> V_11 ;
int V_39 = - 1 ;
int V_40 ;
if ( V_23 -> V_31 >= 0 ) {
if ( V_23 -> V_31 < V_23 -> V_37 -> V_11 )
V_39 = V_23 -> V_31 ;
if ( V_39 >= 0 )
V_38 -- ;
}
V_40 = F_24 () % V_38 ;
if ( V_39 >= 0 && V_40 >= V_39 )
V_40 ++ ;
V_23 -> V_31 = V_40 ;
}
F_4 ( L_6 , V_41 , V_36 ,
V_23 -> V_31 , V_23 -> V_37 -> V_11 ) ;
}
static void F_25 ( struct V_22 * V_23 )
{
int V_42 ;
F_22 ( V_23 ) ;
V_23 -> V_43 = true ;
if ( V_23 -> V_44 ) {
V_23 -> V_45 *= V_46 ;
if ( V_23 -> V_45 > V_47 )
V_23 -> V_45 = V_47 ;
}
V_23 -> V_48 = V_49 ;
V_23 -> V_50 = 0 ;
F_4 ( L_7 , V_41 , V_23 -> V_31 ) ;
F_26 ( & V_23 -> V_30 , V_51 , V_23 -> V_31 ,
& V_23 -> V_37 -> V_15 [ V_23 -> V_31 ] . V_19 ) ;
F_27 ( & V_23 -> V_30 ) ;
V_42 = F_28 ( V_23 -> V_35 ,
V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
F_23 ( V_42 <= 0 ) ;
F_13 ( V_23 , V_42 ) ;
}
static void F_29 ( struct V_22 * V_23 )
{
if ( ! V_23 -> V_43 )
F_30 ( L_8 ,
V_23 -> V_31 , F_10 ( & V_23 -> V_30 . V_54 . V_20 ) ) ;
F_18 ( V_23 ) ;
F_25 ( V_23 ) ;
}
static void F_31 ( struct V_22 * V_23 )
{
unsigned long V_55 ;
if ( V_23 -> V_43 )
V_55 = V_56 * V_23 -> V_45 ;
else
V_55 = V_57 ;
F_4 ( L_9 , V_55 ) ;
F_32 ( V_58 , & V_23 -> V_59 ,
F_33 ( V_55 ) ) ;
}
static void F_34 ( struct V_22 * V_23 )
{
struct V_60 * V_61 = V_23 -> V_33 ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_61 -> V_53 ;
int V_62 = 0 ;
int V_5 ;
F_4 ( L_10 , V_41 , V_23 -> V_50 ) ;
F_23 ( V_23 -> V_31 < 0 ) ;
if ( ! V_23 -> V_50 )
V_23 -> V_50 = V_49 | 1 ;
V_61 -> V_28 . V_63 = F_35 ( 2 ) ;
for ( V_5 = 0 ; V_5 < F_36 ( V_23 -> V_64 ) ; V_5 ++ ) {
if ( V_23 -> V_64 [ V_5 ] . V_65 )
V_62 ++ ;
}
F_23 ( V_62 < 1 ) ;
F_37 ( & V_2 , V_62 ) ;
for ( V_5 = 0 ; V_5 < F_36 ( V_23 -> V_64 ) ; V_5 ++ ) {
char V_66 [ 32 ] ;
int V_12 ;
if ( ! V_23 -> V_64 [ V_5 ] . V_65 )
continue;
V_12 = sprintf ( V_66 , L_11 , V_67 [ V_5 ] ) ;
if ( V_5 == V_68 &&
V_23 -> V_69 != V_70 )
V_12 += sprintf ( V_66 + V_12 , L_12 , V_23 -> V_69 ) ;
F_4 ( L_13 , V_41 , V_66 ,
F_38 ( V_23 -> V_64 [ V_5 ] . V_71 . V_72 ) ,
V_23 -> V_64 [ V_5 ] . V_71 . V_73 ) ;
F_39 ( & V_2 , V_3 , V_66 , V_12 ) ;
memcpy ( V_2 , & V_23 -> V_64 [ V_5 ] . V_71 , sizeof( V_23 -> V_64 [ V_5 ] . V_71 ) ) ;
V_2 += sizeof( V_23 -> V_64 [ V_5 ] . V_71 ) ;
}
F_23 ( V_2 > V_3 ) ;
V_61 -> V_26 . V_27 = V_2 - V_61 -> V_26 . V_52 ;
V_61 -> V_28 . V_29 = F_14 ( V_61 -> V_26 . V_27 ) ;
F_15 ( V_61 ) ;
F_17 ( & V_23 -> V_30 , F_16 ( V_61 ) ) ;
}
static void F_40 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
unsigned int V_74 ;
struct V_75 * V_76 = V_61 -> V_26 . V_52 ;
if ( V_61 -> V_26 . V_27 < sizeof( * V_76 ) )
goto V_13;
V_74 = F_41 ( V_76 -> V_77 ) ;
F_42 ( & V_23 -> V_78 ) ;
if ( V_23 -> V_50 ) {
V_23 -> V_48 = V_23 -> V_50 +
( V_74 >> 1 ) * V_79 - 1 ;
F_4 ( L_14 , V_41 ,
V_23 -> V_50 , V_74 , V_23 -> V_48 ) ;
V_23 -> V_50 = 0 ;
} else {
F_4 ( L_15 , V_41 ,
V_23 -> V_50 , V_23 -> V_48 ) ;
}
F_43 ( & V_23 -> V_78 ) ;
return;
V_13:
F_44 ( L_16 ) ;
F_45 ( V_61 ) ;
}
static bool F_46 ( struct V_22 * V_23 , int V_80 ,
T_1 V_10 , bool V_81 )
{
T_2 V_72 = F_47 ( V_10 ) ;
T_3 V_73 = ! V_81 ? V_82 : 0 ;
F_4 ( L_17 , V_41 , V_67 [ V_80 ] ,
V_10 , V_81 ) ;
if ( V_23 -> V_64 [ V_80 ] . V_65 &&
V_23 -> V_64 [ V_80 ] . V_71 . V_72 == V_72 &&
V_23 -> V_64 [ V_80 ] . V_71 . V_73 == V_73 )
return false ;
V_23 -> V_64 [ V_80 ] . V_71 . V_72 = V_72 ;
V_23 -> V_64 [ V_80 ] . V_71 . V_73 = V_73 ;
V_23 -> V_64 [ V_80 ] . V_65 = true ;
return true ;
}
bool F_48 ( struct V_22 * V_23 , int V_80 , T_1 V_10 ,
bool V_81 )
{
bool V_83 ;
F_42 ( & V_23 -> V_78 ) ;
V_83 = F_46 ( V_23 , V_80 , V_10 , V_81 ) ;
F_43 ( & V_23 -> V_78 ) ;
return V_83 ;
}
static void F_49 ( struct V_22 * V_23 , int V_80 ,
T_1 V_10 )
{
F_4 ( L_18 , V_41 , V_67 [ V_80 ] , V_10 ) ;
if ( V_23 -> V_64 [ V_80 ] . V_65 ) {
if ( V_23 -> V_64 [ V_80 ] . V_71 . V_73 & V_82 )
V_23 -> V_64 [ V_80 ] . V_65 = false ;
else
V_23 -> V_64 [ V_80 ] . V_71 . V_72 = F_47 ( V_10 + 1 ) ;
}
V_23 -> V_64 [ V_80 ] . V_84 = V_10 ;
}
void F_50 ( struct V_22 * V_23 , int V_80 , T_1 V_10 )
{
F_42 ( & V_23 -> V_78 ) ;
F_49 ( V_23 , V_80 , V_10 ) ;
F_43 ( & V_23 -> V_78 ) ;
}
void F_51 ( struct V_22 * V_23 )
{
F_42 ( & V_23 -> V_78 ) ;
F_34 ( V_23 ) ;
F_43 ( & V_23 -> V_78 ) ;
}
int F_52 ( struct V_22 * V_23 , T_1 V_10 ,
unsigned long V_85 )
{
unsigned long V_86 = V_49 ;
long V_42 ;
F_42 ( & V_23 -> V_78 ) ;
while ( V_23 -> V_64 [ V_87 ] . V_84 < V_10 ) {
F_43 ( & V_23 -> V_78 ) ;
if ( V_85 && F_53 ( V_49 , V_86 + V_85 ) )
return - V_88 ;
V_42 = F_54 ( V_23 -> V_89 -> V_90 ,
V_23 -> V_64 [ V_87 ] . V_84 >= V_10 ,
F_55 ( V_85 ) ) ;
if ( V_42 < 0 )
return V_42 ;
F_42 ( & V_23 -> V_78 ) ;
}
F_43 ( & V_23 -> V_78 ) ;
return 0 ;
}
int F_56 ( struct V_22 * V_23 )
{
F_42 ( & V_23 -> V_78 ) ;
F_46 ( V_23 , V_91 , 0 , true ) ;
F_46 ( V_23 , V_87 , 0 , false ) ;
F_25 ( V_23 ) ;
F_31 ( V_23 ) ;
F_43 ( & V_23 -> V_78 ) ;
return 0 ;
}
static void F_57 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_92 * V_89 = V_23 -> V_89 ;
struct V_1 * V_37 = NULL , * V_93 = V_23 -> V_37 ;
void * V_2 , * V_3 ;
F_42 ( & V_23 -> V_78 ) ;
F_4 ( L_19 ) ;
V_2 = V_61 -> V_26 . V_52 ;
V_3 = V_2 + V_61 -> V_26 . V_27 ;
V_37 = F_1 ( V_2 , V_3 ) ;
if ( F_58 ( V_37 ) ) {
F_44 ( L_20 ,
( int ) F_59 ( V_37 ) ) ;
goto V_94;
}
if ( F_60 ( V_23 -> V_89 , & V_37 -> V_9 ) < 0 ) {
F_11 ( V_37 ) ;
goto V_94;
}
V_89 -> V_23 . V_37 = V_37 ;
F_11 ( V_93 ) ;
F_49 ( V_23 , V_91 , V_23 -> V_37 -> V_10 ) ;
V_89 -> V_95 = true ;
V_94:
F_43 ( & V_23 -> V_78 ) ;
F_61 ( & V_89 -> V_90 ) ;
}
static void F_62 ( struct V_96 * V_96 )
{
struct V_97 * V_98 =
F_63 ( V_96 , struct V_97 , V_96 ) ;
F_4 ( L_21 , V_41 , V_98 , V_98 -> V_99 ,
V_98 -> V_100 ) ;
F_64 ( ! F_65 ( & V_98 -> V_101 ) ) ;
if ( V_98 -> V_100 )
F_66 ( V_98 -> V_100 ) ;
if ( V_98 -> V_99 )
F_66 ( V_98 -> V_99 ) ;
F_11 ( V_98 ) ;
}
static void F_67 ( struct V_97 * V_98 )
{
if ( V_98 )
F_68 ( & V_98 -> V_96 , F_62 ) ;
}
static void F_69 ( struct V_97 * V_98 )
{
F_70 ( & V_98 -> V_96 ) ;
}
static struct V_97 *
F_71 ( struct V_22 * V_23 , T_4 V_102 )
{
struct V_97 * V_98 ;
V_98 = F_72 ( sizeof( * V_98 ) , V_102 ) ;
if ( ! V_98 )
return NULL ;
V_98 -> V_23 = V_23 ;
F_73 ( & V_98 -> V_96 ) ;
F_74 ( & V_98 -> V_101 ) ;
F_75 ( & V_98 -> V_103 ) ;
F_4 ( L_22 , V_41 , V_98 ) ;
return V_98 ;
}
static void F_76 ( struct V_97 * V_98 )
{
struct V_22 * V_23 = V_98 -> V_23 ;
F_64 ( V_98 -> V_104 ) ;
F_69 ( V_98 ) ;
V_98 -> V_104 = ++ V_23 -> V_105 ;
F_77 ( & V_23 -> V_106 , V_98 ) ;
}
static void F_78 ( struct V_22 * V_23 ,
struct V_97 * V_98 )
{
F_64 ( ! V_98 -> V_104 ) ;
F_4 ( L_23 , V_41 , V_98 , V_98 -> V_104 ) ;
V_98 -> V_99 -> V_28 . V_104 = F_47 ( V_98 -> V_104 ) ;
F_17 ( & V_23 -> V_30 , F_16 ( V_98 -> V_99 ) ) ;
}
static void F_79 ( struct V_97 * V_98 )
{
struct V_22 * V_23 = V_98 -> V_23 ;
F_4 ( L_23 , V_41 , V_98 , V_98 -> V_104 ) ;
F_80 ( & V_23 -> V_106 , V_98 ) ;
F_15 ( V_98 -> V_99 ) ;
F_19 ( V_98 -> V_100 ) ;
}
static void F_81 ( struct V_97 * V_98 )
{
F_79 ( V_98 ) ;
F_67 ( V_98 ) ;
}
static void F_82 ( struct V_97 * V_98 )
{
if ( V_98 -> V_107 )
V_98 -> V_107 ( V_98 ) ;
else
F_83 ( & V_98 -> V_103 ) ;
F_67 ( V_98 ) ;
}
static void F_84 ( struct V_97 * V_98 )
{
struct V_22 * V_23 = V_98 -> V_23 ;
struct V_97 * V_108 ;
F_4 ( L_23 , V_41 , V_98 , V_98 -> V_104 ) ;
F_42 ( & V_23 -> V_78 ) ;
V_108 = F_85 ( & V_23 -> V_106 ,
V_98 -> V_104 ) ;
if ( V_108 ) {
F_64 ( V_108 != V_98 ) ;
F_81 ( V_98 ) ;
}
F_43 ( & V_23 -> V_78 ) ;
}
static int F_86 ( struct V_97 * V_98 )
{
int V_42 ;
F_4 ( L_23 , V_41 , V_98 , V_98 -> V_104 ) ;
V_42 = F_87 ( & V_98 -> V_103 ) ;
if ( V_42 )
F_84 ( V_98 ) ;
else
V_42 = V_98 -> V_109 ;
return V_42 ;
}
static struct V_60 * F_88 ( struct V_110 * V_30 ,
struct V_111 * V_28 ,
int * V_112 )
{
struct V_22 * V_23 = V_30 -> V_113 ;
struct V_97 * V_98 ;
T_5 V_104 = F_38 ( V_28 -> V_104 ) ;
struct V_60 * V_4 ;
F_42 ( & V_23 -> V_78 ) ;
V_98 = F_85 ( & V_23 -> V_106 , V_104 ) ;
if ( ! V_98 ) {
F_4 ( L_24 , V_104 ) ;
* V_112 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_25 , V_104 , V_98 -> V_100 ) ;
* V_112 = 0 ;
V_4 = F_16 ( V_98 -> V_100 ) ;
}
F_43 ( & V_23 -> V_78 ) ;
return V_4 ;
}
static void F_89 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_97 * V_98 ;
struct V_114 * V_100 = V_61 -> V_26 . V_52 ;
T_5 V_104 = F_38 ( V_61 -> V_28 . V_104 ) ;
F_4 ( L_26 , V_41 , V_61 , V_104 ) ;
if ( V_61 -> V_26 . V_27 != sizeof( * V_100 ) )
goto V_13;
F_42 ( & V_23 -> V_78 ) ;
V_98 = F_85 ( & V_23 -> V_106 , V_104 ) ;
if ( ! V_98 ) {
F_43 ( & V_23 -> V_78 ) ;
return;
}
V_98 -> V_109 = 0 ;
* V_98 -> V_115 . V_116 = V_100 -> V_116 ;
F_79 ( V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
F_82 ( V_98 ) ;
return;
V_13:
F_44 ( L_27 , V_104 ) ;
F_45 ( V_61 ) ;
}
int F_90 ( struct V_22 * V_23 , struct V_117 * V_66 )
{
struct V_97 * V_98 ;
struct V_118 * V_76 ;
int V_42 = - V_18 ;
V_98 = F_71 ( V_23 , V_17 ) ;
if ( ! V_98 )
goto V_94;
V_98 -> V_99 = F_91 ( V_119 , sizeof( * V_76 ) , V_17 ,
true ) ;
if ( ! V_98 -> V_99 )
goto V_94;
V_98 -> V_100 = F_91 ( V_120 , 64 , V_17 , true ) ;
if ( ! V_98 -> V_100 )
goto V_94;
V_98 -> V_115 . V_116 = V_66 ;
F_42 ( & V_23 -> V_78 ) ;
F_76 ( V_98 ) ;
V_76 = V_98 -> V_99 -> V_26 . V_52 ;
V_76 -> V_121 . V_122 = 0 ;
V_76 -> V_121 . V_123 = F_35 ( - 1 ) ;
V_76 -> V_121 . V_124 = 0 ;
V_76 -> V_9 = V_23 -> V_37 -> V_9 ;
F_78 ( V_23 , V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
V_42 = F_86 ( V_98 ) ;
V_94:
F_67 ( V_98 ) ;
return V_42 ;
}
static void F_92 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_97 * V_98 ;
T_5 V_104 = F_38 ( V_61 -> V_28 . V_104 ) ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * V_3 = V_2 + V_61 -> V_53 ;
T_5 V_125 ;
F_4 ( L_26 , V_41 , V_61 , V_104 ) ;
F_3 ( & V_2 , V_3 , 2 * sizeof( T_5 ) , V_13 ) ;
V_125 = F_93 ( & V_2 ) ;
if ( V_104 != 0 && V_104 != V_125 )
goto V_13;
F_42 ( & V_23 -> V_78 ) ;
V_98 = F_85 ( & V_23 -> V_106 , V_125 ) ;
if ( ! V_98 ) {
F_43 ( & V_23 -> V_78 ) ;
return;
}
V_98 -> V_109 = 0 ;
V_98 -> V_115 . V_126 = F_93 ( & V_2 ) ;
F_79 ( V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
F_82 ( V_98 ) ;
return;
V_13:
F_44 ( L_28 , V_104 ) ;
F_45 ( V_61 ) ;
}
static struct V_97 *
F_94 ( struct V_22 * V_23 , const char * V_127 ,
T_6 V_128 , T_5 V_129 )
{
struct V_97 * V_98 ;
V_98 = F_71 ( V_23 , V_130 ) ;
if ( ! V_98 )
goto V_131;
V_98 -> V_99 = F_91 ( V_132 ,
sizeof( T_5 ) + sizeof( T_1 ) + strlen ( V_127 ) ,
V_130 , true ) ;
if ( ! V_98 -> V_99 )
goto V_131;
V_98 -> V_100 = F_91 ( V_133 , 32 , V_130 ,
true ) ;
if ( ! V_98 -> V_100 )
goto V_131;
V_98 -> V_107 = V_128 ;
V_98 -> V_129 = V_129 ;
F_42 ( & V_23 -> V_78 ) ;
F_76 ( V_98 ) ;
{
void * V_2 = V_98 -> V_99 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_98 -> V_99 -> V_53 ;
F_95 ( & V_2 , V_98 -> V_104 ) ;
F_39 ( & V_2 , V_3 , V_127 , strlen ( V_127 ) ) ;
F_64 ( V_2 != V_3 ) ;
}
F_78 ( V_23 , V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
return V_98 ;
V_131:
F_67 ( V_98 ) ;
return F_8 ( - V_18 ) ;
}
int F_96 ( struct V_22 * V_23 , const char * V_127 ,
T_5 * V_126 )
{
struct V_97 * V_98 ;
int V_42 ;
V_98 = F_94 ( V_23 , V_127 , NULL , 0 ) ;
if ( F_58 ( V_98 ) )
return F_59 ( V_98 ) ;
V_42 = F_86 ( V_98 ) ;
if ( ! V_42 )
* V_126 = V_98 -> V_115 . V_126 ;
F_67 ( V_98 ) ;
return V_42 ;
}
int F_97 ( struct V_22 * V_23 , const char * V_127 ,
T_6 V_128 , T_5 V_129 )
{
struct V_97 * V_98 ;
V_98 = F_94 ( V_23 , V_127 , V_128 , V_129 ) ;
if ( F_58 ( V_98 ) )
return F_59 ( V_98 ) ;
F_67 ( V_98 ) ;
return 0 ;
}
static void F_98 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_97 * V_98 ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_61 -> V_53 ;
T_5 V_104 = F_38 ( V_61 -> V_28 . V_104 ) ;
F_4 ( L_26 , V_41 , V_61 , V_104 ) ;
F_3 ( & V_2 , V_3 , sizeof( struct V_134 ) +
sizeof( T_1 ) , V_13 ) ;
V_2 += sizeof( struct V_134 ) ;
F_42 ( & V_23 -> V_78 ) ;
V_98 = F_85 ( & V_23 -> V_106 , V_104 ) ;
if ( ! V_98 ) {
F_43 ( & V_23 -> V_78 ) ;
return;
}
V_98 -> V_109 = F_6 ( & V_2 ) ;
F_79 ( V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
F_82 ( V_98 ) ;
return;
V_13:
F_44 ( L_29 , V_104 ) ;
F_45 ( V_61 ) ;
}
int F_99 ( struct V_22 * V_23 ,
struct V_21 * V_135 )
{
struct V_97 * V_98 ;
struct V_136 * V_76 ;
int V_42 = - V_18 ;
int V_12 ;
V_98 = F_71 ( V_23 , V_130 ) ;
if ( ! V_98 )
goto V_94;
V_98 -> V_99 = F_91 ( V_137 , 256 , V_130 , true ) ;
if ( ! V_98 -> V_99 )
goto V_94;
V_98 -> V_100 = F_91 ( V_138 , 512 , V_130 ,
true ) ;
if ( ! V_98 -> V_100 )
goto V_94;
F_42 ( & V_23 -> V_78 ) ;
F_76 ( V_98 ) ;
V_76 = V_98 -> V_99 -> V_26 . V_52 ;
V_76 -> V_121 . V_122 = 0 ;
V_76 -> V_121 . V_123 = F_35 ( - 1 ) ;
V_76 -> V_121 . V_124 = 0 ;
V_76 -> V_9 = V_23 -> V_37 -> V_9 ;
V_76 -> V_139 = F_14 ( 1 ) ;
V_12 = sprintf ( V_76 -> V_140 , L_30 ,
& V_135 -> V_20 , F_41 ( V_135 -> V_141 ) ) ;
V_76 -> V_142 = F_14 ( V_12 ) ;
F_78 ( V_23 , V_98 ) ;
F_43 ( & V_23 -> V_78 ) ;
V_42 = F_86 ( V_98 ) ;
V_94:
F_67 ( V_98 ) ;
return V_42 ;
}
static void F_100 ( struct V_22 * V_23 )
{
struct V_97 * V_98 ;
struct V_143 * V_2 ;
for ( V_2 = F_101 ( & V_23 -> V_106 ) ; V_2 ; V_2 = F_102 ( V_2 ) ) {
V_98 = F_103 ( V_2 , struct V_97 , V_101 ) ;
F_15 ( V_98 -> V_99 ) ;
F_19 ( V_98 -> V_100 ) ;
F_17 ( & V_23 -> V_30 , F_16 ( V_98 -> V_99 ) ) ;
}
}
static void V_59 ( struct V_144 * V_145 )
{
struct V_22 * V_23 =
F_63 ( V_145 , struct V_22 , V_59 . V_145 ) ;
F_4 ( L_31 ) ;
F_42 ( & V_23 -> V_78 ) ;
if ( V_23 -> V_43 ) {
F_4 ( L_32 , V_41 ) ;
F_29 ( V_23 ) ;
} else {
int V_146 = F_104 ( V_23 -> V_35 ) ;
if ( F_105 ( & V_23 -> V_30 ,
V_147 ) ) {
F_4 ( L_33 ) ;
V_146 = 0 ;
F_29 ( V_23 ) ;
}
if ( ! V_23 -> V_43 ) {
F_27 ( & V_23 -> V_30 ) ;
F_106 ( V_23 ) ;
}
if ( V_146 &&
! ( V_23 -> V_30 . V_148 & V_149 ) ) {
unsigned long V_150 = V_49 ;
F_4 ( L_34 ,
V_41 , V_150 , V_23 -> V_48 ) ;
if ( F_53 ( V_150 , V_23 -> V_48 ) )
F_34 ( V_23 ) ;
}
}
F_31 ( V_23 ) ;
F_43 ( & V_23 -> V_78 ) ;
}
static int F_107 ( struct V_22 * V_23 )
{
struct V_151 * V_152 = V_23 -> V_89 -> V_153 ;
struct V_21 * V_154 = V_152 -> V_154 ;
int V_11 = V_152 -> V_11 ;
int V_5 ;
V_23 -> V_37 = F_72 ( sizeof( * V_23 -> V_37 ) +
V_11 * sizeof( V_23 -> V_37 -> V_15 [ 0 ] ) ,
V_155 ) ;
if ( ! V_23 -> V_37 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 = V_154 [ V_5 ] ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 . V_141 = 0 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_156 . type =
V_51 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_156 . V_62 = F_47 ( V_5 ) ;
}
V_23 -> V_37 -> V_11 = V_11 ;
return 0 ;
}
int F_108 ( struct V_22 * V_23 , struct V_92 * V_157 )
{
int V_6 = 0 ;
F_4 ( L_35 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_89 = V_157 ;
V_23 -> V_37 = NULL ;
F_109 ( & V_23 -> V_78 ) ;
V_6 = F_107 ( V_23 ) ;
if ( V_6 )
goto V_94;
V_23 -> V_35 = F_110 ( V_157 -> V_153 -> V_156 ,
V_157 -> V_153 -> V_158 ) ;
if ( F_58 ( V_23 -> V_35 ) ) {
V_6 = F_59 ( V_23 -> V_35 ) ;
goto V_159;
}
V_23 -> V_35 -> V_160 =
V_161 | V_51 |
V_162 | V_163 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_91 ( V_164 ,
sizeof( struct V_75 ) ,
V_155 , true ) ;
if ( ! V_23 -> V_34 )
goto V_165;
V_23 -> V_33 = F_91 ( V_166 , 128 ,
V_155 , true ) ;
if ( ! V_23 -> V_33 )
goto V_167;
V_23 -> V_32 = F_91 ( V_168 , 4096 ,
V_155 , true ) ;
if ( ! V_23 -> V_32 )
goto V_169;
V_23 -> V_25 = F_91 ( V_170 , 4096 , V_155 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_171;
F_111 ( & V_23 -> V_30 , V_23 , & V_172 ,
& V_23 -> V_89 -> V_173 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_44 = false ;
V_23 -> V_45 = 1 ;
F_112 ( & V_23 -> V_59 , V_59 ) ;
V_23 -> V_106 = V_174 ;
V_23 -> V_105 = 0 ;
V_23 -> V_69 = V_70 ;
return 0 ;
V_171:
F_66 ( V_23 -> V_32 ) ;
V_169:
F_66 ( V_23 -> V_33 ) ;
V_167:
F_66 ( V_23 -> V_34 ) ;
V_165:
F_113 ( V_23 -> V_35 ) ;
V_159:
F_11 ( V_23 -> V_37 ) ;
V_94:
return V_6 ;
}
void F_114 ( struct V_22 * V_23 )
{
F_4 ( L_36 ) ;
F_115 ( & V_23 -> V_59 ) ;
F_42 ( & V_23 -> V_78 ) ;
F_18 ( V_23 ) ;
V_23 -> V_31 = - 1 ;
F_43 ( & V_23 -> V_78 ) ;
F_116 () ;
F_113 ( V_23 -> V_35 ) ;
F_64 ( ! F_117 ( & V_23 -> V_106 ) ) ;
F_66 ( V_23 -> V_25 ) ;
F_66 ( V_23 -> V_32 ) ;
F_66 ( V_23 -> V_33 ) ;
F_66 ( V_23 -> V_34 ) ;
F_11 ( V_23 -> V_37 ) ;
}
static void F_118 ( struct V_22 * V_23 )
{
if ( V_23 -> V_43 ) {
F_4 ( L_37 , V_41 , V_23 -> V_31 ) ;
V_23 -> V_43 = false ;
V_23 -> V_44 = true ;
V_23 -> V_45 /= 2 ;
if ( V_23 -> V_45 < 1 )
V_23 -> V_45 = 1 ;
}
}
static void F_119 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
int V_42 ;
int V_175 = 0 ;
F_42 ( & V_23 -> V_78 ) ;
V_175 = F_104 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_42 = F_120 ( V_23 -> V_35 , V_61 -> V_26 . V_52 ,
V_61 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 > 0 ) {
F_13 ( V_23 , V_42 ) ;
goto V_94;
}
F_118 ( V_23 ) ;
if ( V_42 < 0 ) {
V_23 -> V_89 -> V_176 = V_42 ;
} else if ( ! V_175 && F_104 ( V_23 -> V_35 ) ) {
F_4 ( L_38 ) ;
V_23 -> V_89 -> V_173 . V_177 . V_156 . type = V_178 ;
V_23 -> V_89 -> V_173 . V_177 . V_156 . V_62 =
F_47 ( V_23 -> V_35 -> V_179 ) ;
F_34 ( V_23 ) ;
F_100 ( V_23 ) ;
F_30 ( L_39 , V_23 -> V_31 ,
F_10 ( & V_23 -> V_30 . V_54 . V_20 ) ) ;
}
V_94:
F_43 ( & V_23 -> V_78 ) ;
if ( V_23 -> V_89 -> V_176 < 0 )
F_61 ( & V_23 -> V_89 -> V_90 ) ;
}
static int F_106 ( struct V_22 * V_23 )
{
int V_42 ;
if ( V_23 -> V_24 )
return 0 ;
V_42 = F_121 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 <= 0 )
return V_42 ;
F_13 ( V_23 , V_42 ) ;
return 0 ;
}
int F_122 ( struct V_22 * V_23 )
{
int V_42 ;
F_42 ( & V_23 -> V_78 ) ;
V_42 = F_106 ( V_23 ) ;
F_43 ( & V_23 -> V_78 ) ;
return V_42 ;
}
static void F_123 ( struct V_110 * V_30 , struct V_60 * V_61 )
{
struct V_22 * V_23 = V_30 -> V_113 ;
int type = F_124 ( V_61 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_168 :
F_119 ( V_23 , V_61 ) ;
break;
case V_164 :
F_40 ( V_23 , V_61 ) ;
break;
case V_120 :
F_89 ( V_23 , V_61 ) ;
break;
case V_133 :
F_92 ( V_23 , V_61 ) ;
break;
case V_138 :
F_98 ( V_23 , V_61 ) ;
break;
case V_180 :
F_57 ( V_23 , V_61 ) ;
break;
case V_181 :
F_125 ( & V_23 -> V_89 -> V_182 , V_61 ) ;
break;
default:
if ( V_23 -> V_89 -> V_183 &&
V_23 -> V_89 -> V_183 ( V_23 -> V_89 , V_61 ) == 0 )
break;
F_44 ( L_40 , type ,
F_126 ( type ) ) ;
}
F_66 ( V_61 ) ;
}
static struct V_60 * F_127 ( struct V_110 * V_30 ,
struct V_111 * V_28 ,
int * V_112 )
{
struct V_22 * V_23 = V_30 -> V_113 ;
int type = F_124 ( V_28 -> type ) ;
int V_29 = F_41 ( V_28 -> V_29 ) ;
struct V_60 * V_4 = NULL ;
* V_112 = 0 ;
switch ( type ) {
case V_164 :
V_4 = F_16 ( V_23 -> V_34 ) ;
break;
case V_120 :
case V_138 :
return F_88 ( V_30 , V_28 , V_112 ) ;
case V_168 :
V_4 = F_16 ( V_23 -> V_32 ) ;
break;
case V_133 :
if ( F_38 ( V_28 -> V_104 ) != 0 )
return F_88 ( V_30 , V_28 , V_112 ) ;
case V_180 :
case V_184 :
case V_181 :
case V_185 :
V_4 = F_91 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_30 ( L_41 , type ) ;
* V_112 = 1 ;
} else if ( V_29 > V_4 -> V_53 ) {
F_128 ( L_42 ,
V_29 , V_4 -> V_53 ,
( unsigned int ) V_30 -> V_186 . type ,
F_38 ( V_30 -> V_186 . V_62 ) ) ;
F_66 ( V_4 ) ;
V_4 = F_91 ( type , V_29 , V_17 , false ) ;
}
return V_4 ;
}
static void F_129 ( struct V_110 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_113 ;
F_42 ( & V_23 -> V_78 ) ;
F_4 ( L_43 , V_41 , V_23 -> V_31 ) ;
if ( V_23 -> V_31 >= 0 ) {
if ( ! V_23 -> V_43 ) {
F_4 ( L_44 , V_41 ) ;
F_29 ( V_23 ) ;
F_31 ( V_23 ) ;
} else {
F_4 ( L_45 , V_41 ) ;
}
}
F_43 ( & V_23 -> V_78 ) ;
}
static struct V_110 * F_130 ( struct V_110 * V_30 )
{
return V_30 ;
}
static void F_131 ( struct V_110 * V_30 )
{
}
