struct V_1 * F_1 ( void * V_2 , void * V_3 )
{
struct V_1 * V_4 = NULL ;
int V_5 , V_6 = - V_7 ;
struct V_8 V_9 ;
T_1 V_10 , V_11 ;
T_2 V_12 ;
T_1 V_13 ;
F_2 ( & V_2 , V_3 , V_13 , V_14 ) ;
F_3 ( & V_2 , V_3 , V_13 , V_14 ) ;
F_4 ( L_1 , V_2 , V_3 , ( int ) ( V_3 - V_2 ) ) ;
F_5 ( & V_2 , V_3 , V_12 , V_14 ) ;
F_3 ( & V_2 , V_3 , sizeof( V_9 ) + 2 * sizeof( T_1 ) , V_14 ) ;
F_6 ( & V_2 , & V_9 , sizeof( V_9 ) ) ;
V_10 = F_7 ( & V_2 ) ;
V_11 = F_7 ( & V_2 ) ;
F_3 ( & V_2 , V_3 , V_11 * sizeof( V_4 -> V_15 [ 0 ] ) , V_14 ) ;
if ( V_11 >= V_16 )
goto V_14;
V_4 = F_8 ( sizeof( * V_4 ) + sizeof( V_4 -> V_15 [ 0 ] ) * V_11 , V_17 ) ;
if ( V_4 == NULL )
return F_9 ( - V_18 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
F_6 ( & V_2 , V_4 -> V_15 , V_11 * sizeof( V_4 -> V_15 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ )
F_10 ( & V_4 -> V_15 [ V_5 ] . V_19 ) ;
F_4 ( L_2 , V_4 -> V_10 ,
V_4 -> V_11 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_11 ; V_5 ++ )
F_4 ( L_3 , V_5 ,
F_11 ( & V_4 -> V_15 [ V_5 ] . V_19 . V_20 ) ) ;
return V_4 ;
V_14:
F_4 ( L_4 , V_6 ) ;
F_12 ( V_4 ) ;
return F_9 ( V_6 ) ;
}
int F_13 ( struct V_1 * V_4 , struct V_21 * V_19 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_11 ; V_5 ++ )
if ( memcmp ( V_19 , & V_4 -> V_15 [ V_5 ] . V_19 , sizeof( * V_19 ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_14 ( struct V_22 * V_23 , int V_13 )
{
V_23 -> V_24 = 1 ;
V_23 -> V_25 -> V_26 . V_27 = V_13 ;
V_23 -> V_25 -> V_28 . V_29 = F_15 ( V_13 ) ;
F_16 ( V_23 -> V_25 ) ;
F_17 ( V_23 -> V_25 ) ;
F_18 ( & V_23 -> V_30 , V_23 -> V_25 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_4 ( L_5 , V_23 -> V_31 ) ;
F_16 ( V_23 -> V_25 ) ;
F_20 ( V_23 -> V_32 ) ;
F_16 ( V_23 -> V_33 ) ;
F_20 ( V_23 -> V_34 ) ;
F_21 ( & V_23 -> V_30 ) ;
V_23 -> V_24 = 0 ;
F_22 ( V_23 -> V_35 ) ;
}
static void F_23 ( struct V_22 * V_23 )
{
int V_36 = V_23 -> V_31 ;
F_24 ( V_23 -> V_37 -> V_11 < 1 ) ;
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
V_40 = F_25 () % V_38 ;
if ( V_39 >= 0 && V_40 >= V_39 )
V_40 ++ ;
V_23 -> V_31 = V_40 ;
}
F_4 ( L_6 , V_41 , V_36 ,
V_23 -> V_31 , V_23 -> V_37 -> V_11 ) ;
}
static void F_26 ( struct V_22 * V_23 )
{
int V_42 ;
F_23 ( V_23 ) ;
V_23 -> V_43 = true ;
if ( V_23 -> V_44 ) {
V_23 -> V_45 *= V_46 ;
if ( V_23 -> V_45 > V_47 )
V_23 -> V_45 = V_47 ;
}
V_23 -> V_48 = V_49 ;
V_23 -> V_50 = 0 ;
F_4 ( L_7 , V_41 , V_23 -> V_31 ) ;
F_27 ( & V_23 -> V_30 , V_51 , V_23 -> V_31 ,
& V_23 -> V_37 -> V_15 [ V_23 -> V_31 ] . V_19 ) ;
F_28 ( & V_23 -> V_30 ) ;
V_42 = F_29 ( V_23 -> V_35 ,
V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
F_24 ( V_42 <= 0 ) ;
F_14 ( V_23 , V_42 ) ;
}
static void F_30 ( struct V_22 * V_23 )
{
if ( ! V_23 -> V_43 )
F_31 ( L_8 ,
V_23 -> V_31 , F_11 ( & V_23 -> V_30 . V_54 . V_20 ) ) ;
F_19 ( V_23 ) ;
F_26 ( V_23 ) ;
}
static void F_32 ( struct V_22 * V_23 )
{
unsigned long V_55 ;
if ( V_23 -> V_43 )
V_55 = V_56 * V_23 -> V_45 ;
else
V_55 = V_57 ;
F_4 ( L_9 , V_55 ) ;
F_33 ( V_58 , & V_23 -> V_59 ,
F_34 ( V_55 ) ) ;
}
static void F_35 ( struct V_22 * V_23 )
{
struct V_60 * V_61 = V_23 -> V_33 ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_61 -> V_53 ;
int V_62 = 0 ;
int V_5 ;
F_4 ( L_10 , V_41 , V_23 -> V_50 ) ;
F_24 ( V_23 -> V_31 < 0 ) ;
if ( ! V_23 -> V_50 )
V_23 -> V_50 = V_49 | 1 ;
V_61 -> V_28 . V_12 = F_36 ( 2 ) ;
for ( V_5 = 0 ; V_5 < F_37 ( V_23 -> V_63 ) ; V_5 ++ ) {
if ( V_23 -> V_63 [ V_5 ] . V_64 )
V_62 ++ ;
}
F_24 ( V_62 < 1 ) ;
F_38 ( & V_2 , V_62 ) ;
for ( V_5 = 0 ; V_5 < F_37 ( V_23 -> V_63 ) ; V_5 ++ ) {
char V_65 [ 32 ] ;
int V_13 ;
if ( ! V_23 -> V_63 [ V_5 ] . V_64 )
continue;
V_13 = sprintf ( V_65 , L_11 , V_66 [ V_5 ] ) ;
if ( V_5 == V_67 &&
V_23 -> V_68 != V_69 )
V_13 += sprintf ( V_65 + V_13 , L_12 , V_23 -> V_68 ) ;
F_4 ( L_13 , V_41 , V_65 ,
F_39 ( V_23 -> V_63 [ V_5 ] . V_70 . V_71 ) ,
V_23 -> V_63 [ V_5 ] . V_70 . V_72 ) ;
F_40 ( & V_2 , V_3 , V_65 , V_13 ) ;
memcpy ( V_2 , & V_23 -> V_63 [ V_5 ] . V_70 , sizeof( V_23 -> V_63 [ V_5 ] . V_70 ) ) ;
V_2 += sizeof( V_23 -> V_63 [ V_5 ] . V_70 ) ;
}
F_24 ( V_2 > V_3 ) ;
V_61 -> V_26 . V_27 = V_2 - V_61 -> V_26 . V_52 ;
V_61 -> V_28 . V_29 = F_15 ( V_61 -> V_26 . V_27 ) ;
F_16 ( V_61 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_61 ) ) ;
}
static void F_41 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
unsigned int V_73 ;
struct V_74 * V_75 = V_61 -> V_26 . V_52 ;
if ( V_61 -> V_26 . V_27 < sizeof( * V_75 ) )
goto V_14;
V_73 = F_42 ( V_75 -> V_76 ) ;
F_43 ( & V_23 -> V_77 ) ;
if ( V_23 -> V_50 ) {
V_23 -> V_48 = V_23 -> V_50 +
( V_73 >> 1 ) * V_78 - 1 ;
F_4 ( L_14 , V_41 ,
V_23 -> V_50 , V_73 , V_23 -> V_48 ) ;
V_23 -> V_50 = 0 ;
} else {
F_4 ( L_15 , V_41 ,
V_23 -> V_50 , V_23 -> V_48 ) ;
}
F_44 ( & V_23 -> V_77 ) ;
return;
V_14:
F_45 ( L_16 ) ;
F_46 ( V_61 ) ;
}
static bool F_47 ( struct V_22 * V_23 , int V_79 ,
T_1 V_10 , bool V_80 )
{
T_3 V_71 = F_48 ( V_10 ) ;
T_4 V_72 = ! V_80 ? V_81 : 0 ;
F_4 ( L_17 , V_41 , V_66 [ V_79 ] ,
V_10 , V_80 ) ;
if ( V_23 -> V_63 [ V_79 ] . V_64 &&
V_23 -> V_63 [ V_79 ] . V_70 . V_71 == V_71 &&
V_23 -> V_63 [ V_79 ] . V_70 . V_72 == V_72 )
return false ;
V_23 -> V_63 [ V_79 ] . V_70 . V_71 = V_71 ;
V_23 -> V_63 [ V_79 ] . V_70 . V_72 = V_72 ;
V_23 -> V_63 [ V_79 ] . V_64 = true ;
return true ;
}
bool F_49 ( struct V_22 * V_23 , int V_79 , T_1 V_10 ,
bool V_80 )
{
bool V_82 ;
F_43 ( & V_23 -> V_77 ) ;
V_82 = F_47 ( V_23 , V_79 , V_10 , V_80 ) ;
F_44 ( & V_23 -> V_77 ) ;
return V_82 ;
}
static void F_50 ( struct V_22 * V_23 , int V_79 ,
T_1 V_10 )
{
F_4 ( L_18 , V_41 , V_66 [ V_79 ] , V_10 ) ;
if ( V_23 -> V_63 [ V_79 ] . V_64 ) {
if ( V_23 -> V_63 [ V_79 ] . V_70 . V_72 & V_81 )
V_23 -> V_63 [ V_79 ] . V_64 = false ;
else
V_23 -> V_63 [ V_79 ] . V_70 . V_71 = F_48 ( V_10 + 1 ) ;
}
V_23 -> V_63 [ V_79 ] . V_83 = V_10 ;
}
void F_51 ( struct V_22 * V_23 , int V_79 , T_1 V_10 )
{
F_43 ( & V_23 -> V_77 ) ;
F_50 ( V_23 , V_79 , V_10 ) ;
F_44 ( & V_23 -> V_77 ) ;
}
void F_52 ( struct V_22 * V_23 )
{
F_43 ( & V_23 -> V_77 ) ;
F_35 ( V_23 ) ;
F_44 ( & V_23 -> V_77 ) ;
}
int F_53 ( struct V_22 * V_23 , T_1 V_10 ,
unsigned long V_84 )
{
unsigned long V_85 = V_49 ;
long V_42 ;
F_43 ( & V_23 -> V_77 ) ;
while ( V_23 -> V_63 [ V_86 ] . V_83 < V_10 ) {
F_44 ( & V_23 -> V_77 ) ;
if ( V_84 && F_54 ( V_49 , V_85 + V_84 ) )
return - V_87 ;
V_42 = F_55 ( V_23 -> V_88 -> V_89 ,
V_23 -> V_63 [ V_86 ] . V_83 >= V_10 ,
F_56 ( V_84 ) ) ;
if ( V_42 < 0 )
return V_42 ;
F_43 ( & V_23 -> V_77 ) ;
}
F_44 ( & V_23 -> V_77 ) ;
return 0 ;
}
int F_57 ( struct V_22 * V_23 )
{
F_43 ( & V_23 -> V_77 ) ;
F_47 ( V_23 , V_90 , 0 , true ) ;
F_47 ( V_23 , V_86 , 0 , false ) ;
F_26 ( V_23 ) ;
F_32 ( V_23 ) ;
F_44 ( & V_23 -> V_77 ) ;
return 0 ;
}
static void F_58 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_91 * V_88 = V_23 -> V_88 ;
struct V_1 * V_37 = NULL , * V_92 = V_23 -> V_37 ;
void * V_2 , * V_3 ;
F_43 ( & V_23 -> V_77 ) ;
F_4 ( L_19 ) ;
V_2 = V_61 -> V_26 . V_52 ;
V_3 = V_2 + V_61 -> V_26 . V_27 ;
V_37 = F_1 ( V_2 , V_3 ) ;
if ( F_59 ( V_37 ) ) {
F_45 ( L_20 ,
( int ) F_60 ( V_37 ) ) ;
goto V_93;
}
if ( F_61 ( V_23 -> V_88 , & V_37 -> V_9 ) < 0 ) {
F_12 ( V_37 ) ;
goto V_93;
}
V_88 -> V_23 . V_37 = V_37 ;
F_12 ( V_92 ) ;
F_50 ( V_23 , V_90 , V_23 -> V_37 -> V_10 ) ;
V_88 -> V_94 = true ;
V_93:
F_44 ( & V_23 -> V_77 ) ;
F_62 ( & V_88 -> V_89 ) ;
}
static void F_63 ( struct V_95 * V_95 )
{
struct V_96 * V_97 =
F_64 ( V_95 , struct V_96 , V_95 ) ;
F_4 ( L_21 , V_41 , V_97 , V_97 -> V_98 ,
V_97 -> V_99 ) ;
F_65 ( ! F_66 ( & V_97 -> V_100 ) ) ;
if ( V_97 -> V_99 )
F_67 ( V_97 -> V_99 ) ;
if ( V_97 -> V_98 )
F_67 ( V_97 -> V_98 ) ;
F_12 ( V_97 ) ;
}
static void F_68 ( struct V_96 * V_97 )
{
if ( V_97 )
F_69 ( & V_97 -> V_95 , F_63 ) ;
}
static void F_70 ( struct V_96 * V_97 )
{
F_71 ( & V_97 -> V_95 ) ;
}
static struct V_96 *
F_72 ( struct V_22 * V_23 , T_5 V_101 )
{
struct V_96 * V_97 ;
V_97 = F_73 ( sizeof( * V_97 ) , V_101 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_23 = V_23 ;
F_74 ( & V_97 -> V_95 ) ;
F_75 ( & V_97 -> V_100 ) ;
F_76 ( & V_97 -> V_102 ) ;
F_4 ( L_22 , V_41 , V_97 ) ;
return V_97 ;
}
static void F_77 ( struct V_96 * V_97 )
{
struct V_22 * V_23 = V_97 -> V_23 ;
F_65 ( V_97 -> V_103 ) ;
F_70 ( V_97 ) ;
V_97 -> V_103 = ++ V_23 -> V_104 ;
F_78 ( & V_23 -> V_105 , V_97 ) ;
}
static void F_79 ( struct V_22 * V_23 ,
struct V_96 * V_97 )
{
F_65 ( ! V_97 -> V_103 ) ;
F_4 ( L_23 , V_41 , V_97 , V_97 -> V_103 ) ;
V_97 -> V_98 -> V_28 . V_103 = F_48 ( V_97 -> V_103 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_97 -> V_98 ) ) ;
}
static void F_80 ( struct V_96 * V_97 )
{
struct V_22 * V_23 = V_97 -> V_23 ;
F_4 ( L_23 , V_41 , V_97 , V_97 -> V_103 ) ;
F_81 ( & V_23 -> V_105 , V_97 ) ;
F_16 ( V_97 -> V_98 ) ;
F_20 ( V_97 -> V_99 ) ;
}
static void F_82 ( struct V_96 * V_97 )
{
F_80 ( V_97 ) ;
F_68 ( V_97 ) ;
}
static void F_83 ( struct V_96 * V_97 )
{
if ( V_97 -> V_106 )
V_97 -> V_106 ( V_97 ) ;
else
F_84 ( & V_97 -> V_102 ) ;
F_68 ( V_97 ) ;
}
static void F_85 ( struct V_96 * V_97 )
{
struct V_22 * V_23 = V_97 -> V_23 ;
struct V_96 * V_107 ;
F_4 ( L_23 , V_41 , V_97 , V_97 -> V_103 ) ;
F_43 ( & V_23 -> V_77 ) ;
V_107 = F_86 ( & V_23 -> V_105 ,
V_97 -> V_103 ) ;
if ( V_107 ) {
F_65 ( V_107 != V_97 ) ;
F_82 ( V_97 ) ;
}
F_44 ( & V_23 -> V_77 ) ;
}
static int F_87 ( struct V_96 * V_97 )
{
int V_42 ;
F_4 ( L_23 , V_41 , V_97 , V_97 -> V_103 ) ;
V_42 = F_88 ( & V_97 -> V_102 ) ;
if ( V_42 )
F_85 ( V_97 ) ;
else
V_42 = V_97 -> V_108 ;
return V_42 ;
}
static struct V_60 * F_89 ( struct V_109 * V_30 ,
struct V_110 * V_28 ,
int * V_111 )
{
struct V_22 * V_23 = V_30 -> V_112 ;
struct V_96 * V_97 ;
T_6 V_103 = F_39 ( V_28 -> V_103 ) ;
struct V_60 * V_4 ;
F_43 ( & V_23 -> V_77 ) ;
V_97 = F_86 ( & V_23 -> V_105 , V_103 ) ;
if ( ! V_97 ) {
F_4 ( L_24 , V_103 ) ;
* V_111 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_25 , V_103 , V_97 -> V_99 ) ;
* V_111 = 0 ;
V_4 = F_17 ( V_97 -> V_99 ) ;
}
F_44 ( & V_23 -> V_77 ) ;
return V_4 ;
}
static void F_90 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_96 * V_97 ;
struct V_113 * V_99 = V_61 -> V_26 . V_52 ;
T_6 V_103 = F_39 ( V_61 -> V_28 . V_103 ) ;
F_4 ( L_26 , V_41 , V_61 , V_103 ) ;
if ( V_61 -> V_26 . V_27 != sizeof( * V_99 ) )
goto V_14;
F_43 ( & V_23 -> V_77 ) ;
V_97 = F_86 ( & V_23 -> V_105 , V_103 ) ;
if ( ! V_97 ) {
F_44 ( & V_23 -> V_77 ) ;
return;
}
V_97 -> V_108 = 0 ;
* V_97 -> V_114 . V_115 = V_99 -> V_115 ;
F_80 ( V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
F_83 ( V_97 ) ;
return;
V_14:
F_45 ( L_27 , V_103 ) ;
F_46 ( V_61 ) ;
}
int F_91 ( struct V_22 * V_23 , struct V_116 * V_65 )
{
struct V_96 * V_97 ;
struct V_117 * V_75 ;
int V_42 = - V_18 ;
V_97 = F_72 ( V_23 , V_17 ) ;
if ( ! V_97 )
goto V_93;
V_97 -> V_98 = F_92 ( V_118 , sizeof( * V_75 ) , V_17 ,
true ) ;
if ( ! V_97 -> V_98 )
goto V_93;
V_97 -> V_99 = F_92 ( V_119 , 64 , V_17 , true ) ;
if ( ! V_97 -> V_99 )
goto V_93;
V_97 -> V_114 . V_115 = V_65 ;
F_43 ( & V_23 -> V_77 ) ;
F_77 ( V_97 ) ;
V_75 = V_97 -> V_98 -> V_26 . V_52 ;
V_75 -> V_120 . V_121 = 0 ;
V_75 -> V_120 . V_122 = F_36 ( - 1 ) ;
V_75 -> V_120 . V_123 = 0 ;
V_75 -> V_9 = V_23 -> V_37 -> V_9 ;
F_79 ( V_23 , V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
V_42 = F_87 ( V_97 ) ;
V_93:
F_68 ( V_97 ) ;
return V_42 ;
}
static void F_93 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_96 * V_97 ;
T_6 V_103 = F_39 ( V_61 -> V_28 . V_103 ) ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * V_3 = V_2 + V_61 -> V_53 ;
T_6 V_124 ;
F_4 ( L_26 , V_41 , V_61 , V_103 ) ;
F_3 ( & V_2 , V_3 , 2 * sizeof( T_6 ) , V_14 ) ;
V_124 = F_94 ( & V_2 ) ;
if ( V_103 != 0 && V_103 != V_124 )
goto V_14;
F_43 ( & V_23 -> V_77 ) ;
V_97 = F_86 ( & V_23 -> V_105 , V_124 ) ;
if ( ! V_97 ) {
F_44 ( & V_23 -> V_77 ) ;
return;
}
V_97 -> V_108 = 0 ;
V_97 -> V_114 . V_125 = F_94 ( & V_2 ) ;
F_80 ( V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
F_83 ( V_97 ) ;
return;
V_14:
F_45 ( L_28 , V_103 ) ;
F_46 ( V_61 ) ;
}
static struct V_96 *
F_95 ( struct V_22 * V_23 , const char * V_126 ,
T_7 V_127 , T_6 V_128 )
{
struct V_96 * V_97 ;
V_97 = F_72 ( V_23 , V_129 ) ;
if ( ! V_97 )
goto V_130;
V_97 -> V_98 = F_92 ( V_131 ,
sizeof( T_6 ) + sizeof( T_1 ) + strlen ( V_126 ) ,
V_129 , true ) ;
if ( ! V_97 -> V_98 )
goto V_130;
V_97 -> V_99 = F_92 ( V_132 , 32 , V_129 ,
true ) ;
if ( ! V_97 -> V_99 )
goto V_130;
V_97 -> V_106 = V_127 ;
V_97 -> V_128 = V_128 ;
F_43 ( & V_23 -> V_77 ) ;
F_77 ( V_97 ) ;
{
void * V_2 = V_97 -> V_98 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_97 -> V_98 -> V_53 ;
F_96 ( & V_2 , V_97 -> V_103 ) ;
F_40 ( & V_2 , V_3 , V_126 , strlen ( V_126 ) ) ;
F_65 ( V_2 != V_3 ) ;
}
F_79 ( V_23 , V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
return V_97 ;
V_130:
F_68 ( V_97 ) ;
return F_9 ( - V_18 ) ;
}
int F_97 ( struct V_22 * V_23 , const char * V_126 ,
T_6 * V_125 )
{
struct V_96 * V_97 ;
int V_42 ;
V_97 = F_95 ( V_23 , V_126 , NULL , 0 ) ;
if ( F_59 ( V_97 ) )
return F_60 ( V_97 ) ;
V_42 = F_87 ( V_97 ) ;
if ( ! V_42 )
* V_125 = V_97 -> V_114 . V_125 ;
F_68 ( V_97 ) ;
return V_42 ;
}
int F_98 ( struct V_22 * V_23 , const char * V_126 ,
T_7 V_127 , T_6 V_128 )
{
struct V_96 * V_97 ;
V_97 = F_95 ( V_23 , V_126 , V_127 , V_128 ) ;
if ( F_59 ( V_97 ) )
return F_60 ( V_97 ) ;
F_68 ( V_97 ) ;
return 0 ;
}
static void F_99 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_96 * V_97 ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * const V_3 = V_2 + V_61 -> V_53 ;
T_6 V_103 = F_39 ( V_61 -> V_28 . V_103 ) ;
F_4 ( L_26 , V_41 , V_61 , V_103 ) ;
F_3 ( & V_2 , V_3 , sizeof( struct V_133 ) +
sizeof( T_1 ) , V_14 ) ;
V_2 += sizeof( struct V_133 ) ;
F_43 ( & V_23 -> V_77 ) ;
V_97 = F_86 ( & V_23 -> V_105 , V_103 ) ;
if ( ! V_97 ) {
F_44 ( & V_23 -> V_77 ) ;
return;
}
V_97 -> V_108 = F_7 ( & V_2 ) ;
F_80 ( V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
F_83 ( V_97 ) ;
return;
V_14:
F_45 ( L_29 , V_103 ) ;
F_46 ( V_61 ) ;
}
int F_100 ( struct V_22 * V_23 ,
struct V_21 * V_134 )
{
struct V_96 * V_97 ;
struct V_135 * V_75 ;
int V_42 = - V_18 ;
int V_13 ;
V_97 = F_72 ( V_23 , V_129 ) ;
if ( ! V_97 )
goto V_93;
V_97 -> V_98 = F_92 ( V_136 , 256 , V_129 , true ) ;
if ( ! V_97 -> V_98 )
goto V_93;
V_97 -> V_99 = F_92 ( V_137 , 512 , V_129 ,
true ) ;
if ( ! V_97 -> V_99 )
goto V_93;
F_43 ( & V_23 -> V_77 ) ;
F_77 ( V_97 ) ;
V_75 = V_97 -> V_98 -> V_26 . V_52 ;
V_75 -> V_120 . V_121 = 0 ;
V_75 -> V_120 . V_122 = F_36 ( - 1 ) ;
V_75 -> V_120 . V_123 = 0 ;
V_75 -> V_9 = V_23 -> V_37 -> V_9 ;
V_75 -> V_138 = F_15 ( 1 ) ;
V_13 = sprintf ( V_75 -> V_139 , L_30 ,
& V_134 -> V_20 , F_42 ( V_134 -> V_140 ) ) ;
V_75 -> V_141 = F_15 ( V_13 ) ;
F_79 ( V_23 , V_97 ) ;
F_44 ( & V_23 -> V_77 ) ;
V_42 = F_87 ( V_97 ) ;
V_93:
F_68 ( V_97 ) ;
return V_42 ;
}
static void F_101 ( struct V_22 * V_23 )
{
struct V_96 * V_97 ;
struct V_142 * V_2 ;
for ( V_2 = F_102 ( & V_23 -> V_105 ) ; V_2 ; V_2 = F_103 ( V_2 ) ) {
V_97 = F_104 ( V_2 , struct V_96 , V_100 ) ;
F_16 ( V_97 -> V_98 ) ;
F_20 ( V_97 -> V_99 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_97 -> V_98 ) ) ;
}
}
static void V_59 ( struct V_143 * V_144 )
{
struct V_22 * V_23 =
F_64 ( V_144 , struct V_22 , V_59 . V_144 ) ;
F_4 ( L_31 ) ;
F_43 ( & V_23 -> V_77 ) ;
if ( V_23 -> V_43 ) {
F_4 ( L_32 , V_41 ) ;
F_30 ( V_23 ) ;
} else {
int V_145 = F_105 ( V_23 -> V_35 ) ;
if ( F_106 ( & V_23 -> V_30 ,
V_146 ) ) {
F_4 ( L_33 ) ;
V_145 = 0 ;
F_30 ( V_23 ) ;
}
if ( ! V_23 -> V_43 ) {
F_28 ( & V_23 -> V_30 ) ;
F_107 ( V_23 ) ;
}
if ( V_145 ) {
unsigned long V_147 = V_49 ;
F_4 ( L_34 ,
V_41 , V_147 , V_23 -> V_48 ) ;
if ( F_54 ( V_147 , V_23 -> V_48 ) )
F_35 ( V_23 ) ;
}
}
F_32 ( V_23 ) ;
F_44 ( & V_23 -> V_77 ) ;
}
static int F_108 ( struct V_22 * V_23 )
{
struct V_148 * V_149 = V_23 -> V_88 -> V_150 ;
struct V_21 * V_151 = V_149 -> V_151 ;
int V_11 = V_149 -> V_11 ;
int V_5 ;
V_23 -> V_37 = F_73 ( sizeof( * V_23 -> V_37 ) +
V_11 * sizeof( V_23 -> V_37 -> V_15 [ 0 ] ) ,
V_152 ) ;
if ( ! V_23 -> V_37 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 = V_151 [ V_5 ] ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 . V_140 = 0 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_153 . type =
V_51 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_153 . V_62 = F_48 ( V_5 ) ;
}
V_23 -> V_37 -> V_11 = V_11 ;
return 0 ;
}
int F_109 ( struct V_22 * V_23 , struct V_91 * V_154 )
{
int V_6 = 0 ;
F_4 ( L_35 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_88 = V_154 ;
V_23 -> V_37 = NULL ;
F_110 ( & V_23 -> V_77 ) ;
V_6 = F_108 ( V_23 ) ;
if ( V_6 )
goto V_93;
V_23 -> V_35 = F_111 ( V_154 -> V_150 -> V_153 ,
V_154 -> V_150 -> V_155 ) ;
if ( F_59 ( V_23 -> V_35 ) ) {
V_6 = F_60 ( V_23 -> V_35 ) ;
goto V_156;
}
V_23 -> V_35 -> V_157 =
V_158 | V_51 |
V_159 | V_160 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_92 ( V_161 ,
sizeof( struct V_74 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_34 )
goto V_162;
V_23 -> V_33 = F_92 ( V_163 , 128 , V_17 ,
true ) ;
if ( ! V_23 -> V_33 )
goto V_164;
V_23 -> V_32 = F_92 ( V_165 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_32 )
goto V_166;
V_23 -> V_25 = F_92 ( V_167 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_168;
F_112 ( & V_23 -> V_30 , V_23 , & V_169 ,
& V_23 -> V_88 -> V_170 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_44 = false ;
V_23 -> V_45 = 1 ;
F_113 ( & V_23 -> V_59 , V_59 ) ;
V_23 -> V_105 = V_171 ;
V_23 -> V_104 = 0 ;
V_23 -> V_68 = V_69 ;
return 0 ;
V_168:
F_67 ( V_23 -> V_32 ) ;
V_166:
F_67 ( V_23 -> V_33 ) ;
V_164:
F_67 ( V_23 -> V_34 ) ;
V_162:
F_114 ( V_23 -> V_35 ) ;
V_156:
F_12 ( V_23 -> V_37 ) ;
V_93:
return V_6 ;
}
void F_115 ( struct V_22 * V_23 )
{
F_4 ( L_36 ) ;
F_116 ( & V_23 -> V_59 ) ;
F_43 ( & V_23 -> V_77 ) ;
F_19 ( V_23 ) ;
V_23 -> V_31 = - 1 ;
F_44 ( & V_23 -> V_77 ) ;
F_117 () ;
F_114 ( V_23 -> V_35 ) ;
F_65 ( ! F_118 ( & V_23 -> V_105 ) ) ;
F_67 ( V_23 -> V_25 ) ;
F_67 ( V_23 -> V_32 ) ;
F_67 ( V_23 -> V_33 ) ;
F_67 ( V_23 -> V_34 ) ;
F_12 ( V_23 -> V_37 ) ;
}
static void F_119 ( struct V_22 * V_23 )
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
static void F_120 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
int V_42 ;
int V_172 = 0 ;
F_43 ( & V_23 -> V_77 ) ;
V_172 = F_105 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_42 = F_121 ( V_23 -> V_35 , V_61 -> V_26 . V_52 ,
V_61 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 > 0 ) {
F_14 ( V_23 , V_42 ) ;
goto V_93;
}
F_119 ( V_23 ) ;
if ( V_42 < 0 ) {
V_23 -> V_88 -> V_173 = V_42 ;
} else if ( ! V_172 && F_105 ( V_23 -> V_35 ) ) {
F_4 ( L_38 ) ;
V_23 -> V_88 -> V_170 . V_174 . V_153 . type = V_175 ;
V_23 -> V_88 -> V_170 . V_174 . V_153 . V_62 =
F_48 ( V_23 -> V_35 -> V_176 ) ;
F_35 ( V_23 ) ;
F_101 ( V_23 ) ;
F_31 ( L_39 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_54 . V_20 ) ) ;
}
V_93:
F_44 ( & V_23 -> V_77 ) ;
if ( V_23 -> V_88 -> V_173 < 0 )
F_62 ( & V_23 -> V_88 -> V_89 ) ;
}
static int F_107 ( struct V_22 * V_23 )
{
int V_42 ;
if ( V_23 -> V_24 )
return 0 ;
V_42 = F_122 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 <= 0 )
return V_42 ;
F_14 ( V_23 , V_42 ) ;
return 0 ;
}
int F_123 ( struct V_22 * V_23 )
{
int V_42 ;
F_43 ( & V_23 -> V_77 ) ;
V_42 = F_107 ( V_23 ) ;
F_44 ( & V_23 -> V_77 ) ;
return V_42 ;
}
static void F_124 ( struct V_109 * V_30 , struct V_60 * V_61 )
{
struct V_22 * V_23 = V_30 -> V_112 ;
int type = F_125 ( V_61 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_165 :
F_120 ( V_23 , V_61 ) ;
break;
case V_161 :
F_41 ( V_23 , V_61 ) ;
break;
case V_119 :
F_90 ( V_23 , V_61 ) ;
break;
case V_132 :
F_93 ( V_23 , V_61 ) ;
break;
case V_137 :
F_99 ( V_23 , V_61 ) ;
break;
case V_177 :
F_58 ( V_23 , V_61 ) ;
break;
case V_178 :
F_126 ( & V_23 -> V_88 -> V_179 , V_61 ) ;
break;
default:
if ( V_23 -> V_88 -> V_180 &&
V_23 -> V_88 -> V_180 ( V_23 -> V_88 , V_61 ) == 0 )
break;
F_45 ( L_40 , type ,
F_127 ( type ) ) ;
}
F_67 ( V_61 ) ;
}
static struct V_60 * F_128 ( struct V_109 * V_30 ,
struct V_110 * V_28 ,
int * V_111 )
{
struct V_22 * V_23 = V_30 -> V_112 ;
int type = F_125 ( V_28 -> type ) ;
int V_29 = F_42 ( V_28 -> V_29 ) ;
struct V_60 * V_4 = NULL ;
* V_111 = 0 ;
switch ( type ) {
case V_161 :
V_4 = F_17 ( V_23 -> V_34 ) ;
break;
case V_119 :
case V_137 :
return F_89 ( V_30 , V_28 , V_111 ) ;
case V_165 :
V_4 = F_17 ( V_23 -> V_32 ) ;
break;
case V_132 :
if ( F_39 ( V_28 -> V_103 ) != 0 )
return F_89 ( V_30 , V_28 , V_111 ) ;
case V_177 :
case V_181 :
case V_178 :
case V_182 :
V_4 = F_92 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_31 ( L_41 , type ) ;
* V_111 = 1 ;
} else if ( V_29 > V_4 -> V_53 ) {
F_129 ( L_42 ,
V_29 , V_4 -> V_53 ,
( unsigned int ) V_30 -> V_183 . type ,
F_39 ( V_30 -> V_183 . V_62 ) ) ;
F_67 ( V_4 ) ;
V_4 = F_92 ( type , V_29 , V_17 , false ) ;
}
return V_4 ;
}
static void F_130 ( struct V_109 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_112 ;
F_43 ( & V_23 -> V_77 ) ;
F_4 ( L_43 , V_41 , V_23 -> V_31 ) ;
if ( V_23 -> V_31 >= 0 ) {
if ( ! V_23 -> V_43 ) {
F_4 ( L_44 , V_41 ) ;
F_30 ( V_23 ) ;
F_32 ( V_23 ) ;
} else {
F_4 ( L_45 , V_41 ) ;
}
}
F_44 ( & V_23 -> V_77 ) ;
}
static struct V_109 * F_131 ( struct V_109 * V_30 )
{
return V_30 ;
}
static void F_132 ( struct V_109 * V_30 )
{
}
