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
V_23 -> V_31 = - 1 ;
V_23 -> V_24 = 0 ;
F_22 ( V_23 -> V_35 ) ;
}
static int F_23 ( struct V_22 * V_23 )
{
char V_36 ;
int V_37 ;
if ( V_23 -> V_31 < 0 ) {
F_24 ( & V_36 , 1 ) ;
V_23 -> V_31 = V_36 % V_23 -> V_38 -> V_11 ;
F_4 ( L_6 ,
V_23 -> V_38 -> V_11 , V_36 , V_23 -> V_31 ) ;
V_23 -> V_39 = 0 ;
V_23 -> V_40 = V_41 ;
V_23 -> V_42 = ! ! V_23 -> V_42 ;
F_4 ( L_7 , V_23 -> V_31 ) ;
F_25 ( & V_23 -> V_30 ,
V_43 , V_23 -> V_31 ,
& V_23 -> V_38 -> V_15 [ V_23 -> V_31 ] . V_19 ) ;
V_37 = F_26 ( V_23 -> V_35 ,
V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
F_14 ( V_23 , V_37 ) ;
} else {
F_4 ( L_8 , V_23 -> V_31 ) ;
}
return 0 ;
}
static bool F_27 ( struct V_22 * V_23 )
{
return F_28 ( V_41 , V_23 -> V_40 ) ;
}
static void F_29 ( struct V_22 * V_23 )
{
unsigned int V_46 ;
if ( V_23 -> V_31 < 0 || F_27 ( V_23 ) )
V_46 = 10 * V_47 ;
else
V_46 = 20 * V_47 ;
F_4 ( L_9 , V_46 ) ;
F_30 ( & V_23 -> V_48 , V_46 ) ;
}
static void F_31 ( struct V_22 * V_23 )
{
F_4 ( L_10 ,
( unsigned int ) V_23 -> V_39 , F_27 ( V_23 ) ,
V_23 -> V_42 ) ;
if ( ( F_27 ( V_23 ) && ! V_23 -> V_39 ) ||
V_23 -> V_42 == 1 ) {
struct V_49 * V_50 = V_23 -> V_33 ;
struct V_51 * V_5 ;
void * V_2 , * V_3 ;
int V_52 ;
V_2 = V_50 -> V_26 . V_44 ;
V_3 = V_2 + V_50 -> V_45 ;
V_52 = 1 + ! ! V_23 -> V_42 + ! ! V_23 -> V_53 ;
F_32 ( & V_2 , V_52 ) ;
if ( V_23 -> V_42 ) {
F_4 ( L_11 ,
( unsigned int ) V_23 -> V_54 ) ;
F_33 ( & V_2 , V_3 , L_12 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_55 = F_34 ( V_23 -> V_54 ) ;
V_5 -> V_56 = 1 ;
V_2 += sizeof( * V_5 ) ;
V_23 -> V_42 = 2 ;
}
if ( V_23 -> V_53 ) {
F_4 ( L_13 ,
( unsigned int ) V_23 -> V_57 ) ;
F_33 ( & V_2 , V_3 , L_14 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_55 = F_34 ( V_23 -> V_57 ) ;
V_5 -> V_56 = 0 ;
V_2 += sizeof( * V_5 ) ;
}
F_33 ( & V_2 , V_3 , L_15 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_55 = 0 ;
V_5 -> V_56 = 0 ;
V_2 += sizeof( * V_5 ) ;
V_50 -> V_26 . V_27 = V_2 - V_50 -> V_26 . V_44 ;
V_50 -> V_28 . V_29 = F_15 ( V_50 -> V_26 . V_27 ) ;
F_16 ( V_50 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_50 ) ) ;
V_23 -> V_39 = V_41 | 1 ;
}
}
static void F_35 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
unsigned int V_58 ;
struct V_59 * V_60 = V_50 -> V_26 . V_44 ;
if ( V_50 -> V_26 . V_27 < sizeof( * V_60 ) )
goto V_14;
V_58 = F_36 ( V_60 -> V_61 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( V_23 -> V_63 ) {
F_38 ( L_16 ,
V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_64 . V_20 ) ) ;
V_23 -> V_63 = false ;
}
F_4 ( L_17 , V_58 ) ;
V_23 -> V_40 = V_23 -> V_39 + ( V_58 >> 1 ) * V_47 - 1 ;
V_23 -> V_39 = 0 ;
F_39 ( & V_23 -> V_62 ) ;
return;
V_14:
F_40 ( L_18 ) ;
F_41 ( V_50 ) ;
}
int F_42 ( struct V_22 * V_23 , T_1 V_65 )
{
F_37 ( & V_23 -> V_62 ) ;
V_23 -> V_57 = V_65 ;
F_39 ( & V_23 -> V_62 ) ;
return 0 ;
}
int F_43 ( struct V_22 * V_23 , T_1 V_65 )
{
F_37 ( & V_23 -> V_62 ) ;
V_23 -> V_54 = V_65 ;
V_23 -> V_42 = 0 ;
F_39 ( & V_23 -> V_62 ) ;
return 0 ;
}
void F_44 ( struct V_22 * V_23 )
{
F_4 ( L_19 , V_23 -> V_54 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( ! V_23 -> V_42 )
V_23 -> V_42 = 1 ;
if ( V_23 -> V_42 < 2 )
F_31 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
}
int F_45 ( struct V_22 * V_23 )
{
F_37 ( & V_23 -> V_62 ) ;
F_23 ( V_23 ) ;
F_29 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
return 0 ;
}
static bool F_46 ( struct V_22 * V_23 )
{
F_4 ( L_20 ,
( int ) V_23 -> V_66 -> V_67 , V_23 -> V_35 -> V_68 ) ;
return V_23 -> V_66 -> V_67 && V_23 -> V_35 -> V_68 > 0 ;
}
static void F_47 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_69 * V_66 = V_23 -> V_66 ;
struct V_1 * V_38 = NULL , * V_70 = V_23 -> V_38 ;
void * V_2 , * V_3 ;
int V_71 , V_72 = 0 ;
F_37 ( & V_23 -> V_62 ) ;
V_71 = F_46 ( V_23 ) ;
F_4 ( L_21 ) ;
V_2 = V_50 -> V_26 . V_44 ;
V_3 = V_2 + V_50 -> V_26 . V_27 ;
V_38 = F_1 ( V_2 , V_3 ) ;
if ( F_48 ( V_38 ) ) {
F_40 ( L_22 ,
( int ) F_49 ( V_38 ) ) ;
goto V_73;
}
if ( F_50 ( V_23 -> V_66 , & V_38 -> V_9 ) < 0 ) {
F_12 ( V_38 ) ;
goto V_73;
}
V_66 -> V_23 . V_38 = V_38 ;
F_12 ( V_70 ) ;
if ( ! V_66 -> V_67 ) {
V_66 -> V_67 = true ;
if ( ! V_71 && F_46 ( V_23 ) ) {
F_38 ( L_23 ,
F_51 ( V_23 -> V_66 ) ,
& V_23 -> V_66 -> V_9 ) ;
V_72 = 1 ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_72 ) {
F_52 ( V_23 -> V_66 ) ;
}
goto V_74;
}
V_73:
F_39 ( & V_23 -> V_62 ) ;
V_74:
F_53 ( & V_66 -> V_75 ) ;
}
static struct V_76 * F_54 (
struct V_22 * V_23 , T_3 V_77 )
{
struct V_76 * V_78 ;
struct V_79 * V_80 = V_23 -> V_81 . V_79 ;
while ( V_80 ) {
V_78 = F_55 ( V_80 , struct V_76 , V_82 ) ;
if ( V_77 < V_78 -> V_77 )
V_80 = V_80 -> V_83 ;
else if ( V_77 > V_78 -> V_77 )
V_80 = V_80 -> V_84 ;
else
return V_78 ;
}
return NULL ;
}
static void F_56 ( struct V_22 * V_23 ,
struct V_76 * V_85 )
{
struct V_79 * * V_2 = & V_23 -> V_81 . V_79 ;
struct V_79 * V_86 = NULL ;
struct V_76 * V_78 = NULL ;
while ( * V_2 ) {
V_86 = * V_2 ;
V_78 = F_55 ( V_86 , struct V_76 , V_82 ) ;
if ( V_85 -> V_77 < V_78 -> V_77 )
V_2 = & ( * V_2 ) -> V_83 ;
else if ( V_85 -> V_77 > V_78 -> V_77 )
V_2 = & ( * V_2 ) -> V_84 ;
else
F_57 () ;
}
F_58 ( & V_85 -> V_82 , V_86 , V_2 ) ;
F_59 ( & V_85 -> V_82 , & V_23 -> V_81 ) ;
}
static void F_60 ( struct V_87 * V_87 )
{
struct V_76 * V_78 =
F_61 ( V_87 , struct V_76 , V_87 ) ;
if ( V_78 -> V_88 )
F_62 ( V_78 -> V_88 ) ;
if ( V_78 -> V_89 )
F_62 ( V_78 -> V_89 ) ;
F_12 ( V_78 ) ;
}
static void F_63 ( struct V_76 * V_78 )
{
F_64 ( & V_78 -> V_87 , F_60 ) ;
}
static void F_65 ( struct V_76 * V_78 )
{
F_66 ( & V_78 -> V_87 ) ;
}
static struct V_49 * F_67 ( struct V_90 * V_30 ,
struct V_91 * V_28 ,
int * V_92 )
{
struct V_22 * V_23 = V_30 -> V_93 ;
struct V_76 * V_78 ;
T_3 V_77 = F_68 ( V_28 -> V_77 ) ;
struct V_49 * V_4 ;
F_37 ( & V_23 -> V_62 ) ;
V_78 = F_54 ( V_23 , V_77 ) ;
if ( ! V_78 ) {
F_4 ( L_24 , V_77 ) ;
* V_92 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_25 , V_77 , V_78 -> V_88 ) ;
* V_92 = 0 ;
V_4 = F_17 ( V_78 -> V_88 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
return V_4 ;
}
static int F_69 ( struct V_22 * V_23 ,
struct V_76 * V_78 )
{
int V_6 ;
F_37 ( & V_23 -> V_62 ) ;
V_78 -> V_77 = ++ V_23 -> V_94 ;
V_78 -> V_89 -> V_28 . V_77 = F_34 ( V_78 -> V_77 ) ;
F_56 ( V_23 , V_78 ) ;
V_23 -> V_95 ++ ;
F_18 ( & V_23 -> V_30 , F_17 ( V_78 -> V_89 ) ) ;
F_39 ( & V_23 -> V_62 ) ;
V_6 = F_70 ( & V_78 -> V_96 ) ;
F_37 ( & V_23 -> V_62 ) ;
F_71 ( & V_78 -> V_82 , & V_23 -> V_81 ) ;
V_23 -> V_95 -- ;
F_39 ( & V_23 -> V_62 ) ;
if ( ! V_6 )
V_6 = V_78 -> V_97 ;
return V_6 ;
}
static void F_72 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_76 * V_78 ;
struct V_98 * V_88 = V_50 -> V_26 . V_44 ;
T_3 V_77 = F_68 ( V_50 -> V_28 . V_77 ) ;
if ( V_50 -> V_26 . V_27 != sizeof( * V_88 ) )
goto V_14;
F_4 ( L_26 , V_50 , V_77 ) ;
F_37 ( & V_23 -> V_62 ) ;
V_78 = F_54 ( V_23 , V_77 ) ;
if ( V_78 ) {
* (struct V_99 * ) V_78 -> V_100 = V_88 -> V_101 ;
V_78 -> V_97 = 0 ;
F_65 ( V_78 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_78 ) {
F_73 ( & V_78 -> V_96 ) ;
F_63 ( V_78 ) ;
}
return;
V_14:
F_40 ( L_27 , V_77 ) ;
F_41 ( V_50 ) ;
}
int F_74 ( struct V_22 * V_23 , struct V_99 * V_100 )
{
struct V_76 * V_78 ;
struct V_102 * V_60 ;
int V_6 ;
V_78 = F_75 ( sizeof( * V_78 ) , V_17 ) ;
if ( ! V_78 )
return - V_18 ;
F_76 ( & V_78 -> V_87 ) ;
V_78 -> V_100 = V_100 ;
V_78 -> V_103 = sizeof( * V_100 ) ;
F_77 ( & V_78 -> V_96 ) ;
V_6 = - V_18 ;
V_78 -> V_89 = F_78 ( V_104 , sizeof( * V_60 ) , V_17 ,
true ) ;
if ( ! V_78 -> V_89 )
goto V_73;
V_78 -> V_88 = F_78 ( V_105 , 1024 , V_17 ,
true ) ;
if ( ! V_78 -> V_88 )
goto V_73;
V_60 = V_78 -> V_89 -> V_26 . V_44 ;
V_60 -> V_106 . V_107 = 0 ;
V_60 -> V_106 . V_108 = F_79 ( - 1 ) ;
V_60 -> V_106 . V_109 = 0 ;
V_60 -> V_9 = V_23 -> V_38 -> V_9 ;
V_6 = F_69 ( V_23 , V_78 ) ;
V_73:
F_64 ( & V_78 -> V_87 , F_60 ) ;
return V_6 ;
}
static int F_80 ( const char * V_110 , T_4 V_111 ,
char * V_112 , T_4 V_113 )
{
T_1 V_103 ;
if ( V_111 != sizeof( T_1 ) + V_113 )
return - V_7 ;
V_103 = F_36 ( * ( T_1 * ) V_110 ) ;
if ( V_103 != V_113 )
return - V_7 ;
memcpy ( V_112 , V_110 + sizeof( T_1 ) , V_113 ) ;
return 0 ;
}
static void F_81 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_76 * V_78 ;
struct V_114 * V_88 = V_50 -> V_26 . V_44 ;
T_3 V_77 = F_68 ( V_50 -> V_28 . V_77 ) ;
if ( V_50 -> V_26 . V_27 < sizeof( * V_88 ) )
goto V_14;
F_4 ( L_28 , V_50 , V_77 ) ;
F_37 ( & V_23 -> V_62 ) ;
V_78 = F_54 ( V_23 , V_77 ) ;
if ( V_78 ) {
if ( V_78 -> V_103 &&
F_80 ( V_50 -> V_26 . V_44 + sizeof( * V_88 ) ,
V_50 -> V_26 . V_27 - sizeof( * V_88 ) ,
V_78 -> V_100 , V_78 -> V_103 ) < 0 ) {
F_39 ( & V_23 -> V_62 ) ;
goto V_14;
}
V_78 -> V_97 = F_36 ( V_88 -> V_115 ) ;
F_65 ( V_78 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_78 ) {
F_82 ( & V_78 -> V_96 ) ;
F_63 ( V_78 ) ;
}
return;
V_14:
F_40 ( L_27 , V_77 ) ;
F_41 ( V_50 ) ;
}
static int F_83 ( struct V_22 * V_23 , T_1 V_116 ,
T_1 V_117 , T_3 V_118 ,
char * V_100 , int V_13 )
{
struct V_76 * V_78 ;
struct V_119 * V_60 ;
int V_6 ;
V_78 = F_75 ( sizeof( * V_78 ) , V_17 ) ;
if ( ! V_78 )
return - V_18 ;
F_76 ( & V_78 -> V_87 ) ;
V_78 -> V_100 = V_100 ;
V_78 -> V_103 = V_13 ;
F_77 ( & V_78 -> V_96 ) ;
V_6 = - V_18 ;
V_78 -> V_89 = F_78 ( V_120 , sizeof( * V_60 ) , V_17 ,
true ) ;
if ( ! V_78 -> V_89 )
goto V_73;
V_78 -> V_88 = F_78 ( V_121 , 1024 , V_17 ,
true ) ;
if ( ! V_78 -> V_88 )
goto V_73;
V_78 -> V_89 -> V_28 . V_12 = F_79 ( 2 ) ;
V_60 = V_78 -> V_89 -> V_26 . V_44 ;
V_60 -> V_106 . V_107 = 0 ;
V_60 -> V_106 . V_108 = F_79 ( - 1 ) ;
V_60 -> V_106 . V_109 = 0 ;
V_60 -> V_9 = V_23 -> V_38 -> V_9 ;
V_60 -> V_117 = F_15 ( V_117 ) ;
V_60 -> V_116 = F_15 ( V_116 ) ;
V_60 -> V_122 = 0 ;
V_60 -> V_118 = F_34 ( V_118 ) ;
V_60 -> V_123 = 0 ;
V_6 = F_69 ( V_23 , V_78 ) ;
V_73:
F_64 ( & V_78 -> V_87 , F_60 ) ;
return V_6 ;
}
int F_84 ( struct V_22 * V_23 ,
T_1 V_117 , T_3 * V_118 )
{
return F_83 ( V_23 , V_124 ,
V_117 , 0 , ( char * ) V_118 , sizeof( * V_118 ) ) ;
}
int F_85 ( struct V_22 * V_23 ,
T_1 V_117 , T_3 V_118 )
{
return F_83 ( V_23 , V_124 ,
V_117 , V_118 , 0 , 0 ) ;
}
static void F_86 ( struct V_22 * V_23 )
{
struct V_76 * V_78 ;
struct V_79 * V_2 ;
for ( V_2 = F_87 ( & V_23 -> V_81 ) ; V_2 ; V_2 = F_88 ( V_2 ) ) {
V_78 = F_55 ( V_2 , struct V_76 , V_82 ) ;
F_16 ( V_78 -> V_89 ) ;
F_20 ( V_78 -> V_88 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_78 -> V_89 ) ) ;
}
}
static void V_48 ( struct V_125 * V_126 )
{
struct V_22 * V_23 =
F_61 ( V_126 , struct V_22 , V_48 . V_126 ) ;
F_4 ( L_29 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( V_23 -> V_63 ) {
F_19 ( V_23 ) ;
F_23 ( V_23 ) ;
} else {
F_89 ( & V_23 -> V_30 ) ;
F_90 ( V_23 ) ;
if ( V_23 -> V_35 -> V_127 -> V_128 ( V_23 -> V_35 ) )
F_31 ( V_23 ) ;
}
F_29 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
}
static int F_91 ( struct V_22 * V_23 )
{
struct V_129 * V_130 = V_23 -> V_66 -> V_131 ;
struct V_21 * V_132 = V_130 -> V_132 ;
int V_11 = V_130 -> V_11 ;
int V_5 ;
V_23 -> V_38 = F_75 ( sizeof( * V_23 -> V_38 ) +
V_11 * sizeof( V_23 -> V_38 -> V_15 [ 0 ] ) ,
V_133 ) ;
if ( ! V_23 -> V_38 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 = V_132 [ V_5 ] ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 . V_134 = 0 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_135 . type =
V_43 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_135 . V_52 = F_34 ( V_5 ) ;
}
V_23 -> V_38 -> V_11 = V_11 ;
return 0 ;
}
int F_92 ( struct V_22 * V_23 , struct V_69 * V_136 )
{
int V_6 = 0 ;
F_4 ( L_30 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_66 = V_136 ;
V_23 -> V_38 = NULL ;
F_93 ( & V_23 -> V_62 ) ;
V_6 = F_91 ( V_23 ) ;
if ( V_6 )
goto V_73;
V_23 -> V_35 = F_94 ( V_136 -> V_131 -> V_135 ,
V_136 -> V_131 -> V_137 ) ;
if ( F_48 ( V_23 -> V_35 ) ) {
V_6 = F_49 ( V_23 -> V_35 ) ;
goto V_138;
}
V_23 -> V_35 -> V_139 =
V_140 | V_43 |
V_141 | V_142 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_78 ( V_143 ,
sizeof( struct V_59 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_34 )
goto V_144;
V_23 -> V_33 = F_78 ( V_145 , 96 , V_17 ,
true ) ;
if ( ! V_23 -> V_33 )
goto V_146;
V_23 -> V_32 = F_78 ( V_147 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_32 )
goto V_148;
V_23 -> V_25 = F_78 ( V_149 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_150;
F_95 ( & V_23 -> V_30 , V_23 , & V_151 ,
& V_23 -> V_66 -> V_152 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_63 = true ;
V_23 -> V_40 = V_41 ;
V_23 -> V_39 = 0 ;
F_96 ( & V_23 -> V_48 , V_48 ) ;
V_23 -> V_81 = V_153 ;
V_23 -> V_95 = 0 ;
V_23 -> V_94 = 0 ;
V_23 -> V_57 = 0 ;
V_23 -> V_54 = 0 ;
V_23 -> V_42 = 1 ;
return 0 ;
V_150:
F_62 ( V_23 -> V_32 ) ;
V_148:
F_62 ( V_23 -> V_33 ) ;
V_146:
F_62 ( V_23 -> V_34 ) ;
V_144:
F_97 ( V_23 -> V_35 ) ;
V_138:
F_12 ( V_23 -> V_38 ) ;
V_73:
return V_6 ;
}
void F_98 ( struct V_22 * V_23 )
{
F_4 ( L_31 ) ;
F_99 ( & V_23 -> V_48 ) ;
F_37 ( & V_23 -> V_62 ) ;
F_19 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
F_100 () ;
F_97 ( V_23 -> V_35 ) ;
F_62 ( V_23 -> V_25 ) ;
F_62 ( V_23 -> V_32 ) ;
F_62 ( V_23 -> V_33 ) ;
F_62 ( V_23 -> V_34 ) ;
F_12 ( V_23 -> V_38 ) ;
}
static void F_101 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
int V_37 ;
int V_154 = 0 ;
int V_71 , V_72 = 0 ;
F_37 ( & V_23 -> V_62 ) ;
V_71 = F_46 ( V_23 ) ;
if ( V_23 -> V_35 -> V_127 )
V_154 = V_23 -> V_35 -> V_127 -> V_128 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_37 = F_102 ( V_23 -> V_35 , V_50 -> V_26 . V_44 ,
V_50 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 < 0 ) {
V_23 -> V_66 -> V_155 = V_37 ;
F_53 ( & V_23 -> V_66 -> V_75 ) ;
} else if ( V_37 > 0 ) {
F_14 ( V_23 , V_37 ) ;
} else if ( ! V_154 && V_23 -> V_35 -> V_127 -> V_128 ( V_23 -> V_35 ) ) {
F_4 ( L_32 ) ;
V_23 -> V_66 -> V_152 . V_156 . V_135 . type = V_157 ;
V_23 -> V_66 -> V_152 . V_156 . V_135 . V_52 =
F_34 ( V_23 -> V_35 -> V_68 ) ;
F_31 ( V_23 ) ;
F_86 ( V_23 ) ;
}
if ( ! V_71 && F_46 ( V_23 ) ) {
F_38 ( L_23 ,
F_51 ( V_23 -> V_66 ) ,
& V_23 -> V_66 -> V_9 ) ;
V_72 = 1 ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_72 ) {
F_52 ( V_23 -> V_66 ) ;
}
}
static int F_90 ( struct V_22 * V_23 )
{
int V_37 ;
if ( V_23 -> V_24 )
return 0 ;
V_37 = F_103 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 <= 0 )
return V_37 ;
F_14 ( V_23 , V_37 ) ;
return 0 ;
}
int F_104 ( struct V_22 * V_23 )
{
int V_37 ;
F_37 ( & V_23 -> V_62 ) ;
V_37 = F_90 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
return V_37 ;
}
static void F_105 ( struct V_90 * V_30 , struct V_49 * V_50 )
{
struct V_22 * V_23 = V_30 -> V_93 ;
int type = F_106 ( V_50 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_147 :
F_101 ( V_23 , V_50 ) ;
break;
case V_143 :
F_35 ( V_23 , V_50 ) ;
break;
case V_105 :
F_72 ( V_23 , V_50 ) ;
break;
case V_121 :
F_81 ( V_23 , V_50 ) ;
break;
case V_158 :
F_47 ( V_23 , V_50 ) ;
break;
case V_159 :
F_107 ( & V_23 -> V_66 -> V_160 , V_50 ) ;
break;
default:
if ( V_23 -> V_66 -> V_161 &&
V_23 -> V_66 -> V_161 ( V_23 -> V_66 , V_50 ) == 0 )
break;
F_40 ( L_33 , type ,
F_108 ( type ) ) ;
}
F_62 ( V_50 ) ;
}
static struct V_49 * F_109 ( struct V_90 * V_30 ,
struct V_91 * V_28 ,
int * V_92 )
{
struct V_22 * V_23 = V_30 -> V_93 ;
int type = F_106 ( V_28 -> type ) ;
int V_29 = F_36 ( V_28 -> V_29 ) ;
struct V_49 * V_4 = NULL ;
* V_92 = 0 ;
switch ( type ) {
case V_143 :
V_4 = F_17 ( V_23 -> V_34 ) ;
break;
case V_121 :
case V_105 :
return F_67 ( V_30 , V_28 , V_92 ) ;
case V_147 :
V_4 = F_17 ( V_23 -> V_32 ) ;
break;
case V_158 :
case V_162 :
case V_159 :
V_4 = F_78 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_38 ( L_34 , type ) ;
* V_92 = 1 ;
}
return V_4 ;
}
static void F_110 ( struct V_90 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_93 ;
if ( ! V_23 )
return;
F_4 ( L_35 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( ! V_30 -> V_93 )
goto V_73;
if ( ! V_23 -> V_63 )
F_38 ( L_36
L_37 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_64 . V_20 ) ) ;
F_19 ( V_23 ) ;
if ( ! V_23 -> V_63 ) {
V_23 -> V_63 = true ;
F_23 ( V_23 ) ;
} else {
F_29 ( V_23 ) ;
}
V_73:
F_39 ( & V_23 -> V_62 ) ;
}
static struct V_90 * F_111 ( struct V_90 * V_30 )
{
return V_30 ;
}
static void F_112 ( struct V_90 * V_30 )
{
}
