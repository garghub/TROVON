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
F_16 ( V_23 -> V_30 , V_23 -> V_25 ) ;
F_17 ( V_23 -> V_25 ) ;
F_18 ( V_23 -> V_30 , V_23 -> V_25 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
if ( V_23 -> V_30 ) {
F_4 ( L_5 , V_23 -> V_31 ) ;
F_16 ( V_23 -> V_30 , V_23 -> V_25 ) ;
F_20 ( V_23 -> V_30 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_24 = 0 ;
F_21 ( V_23 -> V_32 ) ;
}
}
static int F_22 ( struct V_22 * V_23 )
{
char V_33 ;
int V_34 ;
if ( V_23 -> V_31 < 0 ) {
F_23 ( & V_33 , 1 ) ;
V_23 -> V_31 = V_33 % V_23 -> V_35 -> V_11 ;
F_4 ( L_6 ,
V_23 -> V_35 -> V_11 , V_33 , V_23 -> V_31 ) ;
V_23 -> V_36 = 0 ;
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = ! ! V_23 -> V_39 ;
F_4 ( L_7 , V_23 -> V_31 ) ;
V_23 -> V_30 -> V_40 . type = V_41 ;
V_23 -> V_30 -> V_40 . V_42 = F_24 ( V_23 -> V_31 ) ;
F_25 ( V_23 -> V_30 ,
& V_23 -> V_35 -> V_15 [ V_23 -> V_31 ] . V_19 ) ;
V_34 = F_26 ( V_23 -> V_32 ,
V_23 -> V_25 -> V_26 . V_43 ,
V_23 -> V_25 -> V_44 ) ;
F_14 ( V_23 , V_34 ) ;
} else {
F_4 ( L_8 , V_23 -> V_31 ) ;
}
return 0 ;
}
static bool F_27 ( struct V_22 * V_23 )
{
return F_28 ( V_38 , V_23 -> V_37 ) ;
}
static void F_29 ( struct V_22 * V_23 )
{
unsigned V_45 ;
if ( V_23 -> V_31 < 0 || F_27 ( V_23 ) )
V_45 = 10 * V_46 ;
else
V_45 = 20 * V_46 ;
F_4 ( L_9 , V_45 ) ;
F_30 ( & V_23 -> V_47 , V_45 ) ;
}
static void F_31 ( struct V_22 * V_23 )
{
F_4 ( L_10 ,
( unsigned ) V_23 -> V_36 , F_27 ( V_23 ) ,
V_23 -> V_39 ) ;
if ( ( F_27 ( V_23 ) && ! V_23 -> V_36 ) ||
V_23 -> V_39 == 1 ) {
struct V_48 * V_49 = V_23 -> V_50 ;
struct V_51 * V_5 ;
void * V_2 , * V_3 ;
int V_42 ;
V_2 = V_49 -> V_26 . V_43 ;
V_3 = V_2 + V_49 -> V_44 ;
V_42 = 1 + ! ! V_23 -> V_39 + ! ! V_23 -> V_52 ;
F_32 ( & V_2 , V_42 ) ;
if ( V_23 -> V_39 ) {
F_4 ( L_11 ,
( unsigned ) V_23 -> V_53 ) ;
F_33 ( & V_2 , V_3 , L_12 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_54 = F_24 ( V_23 -> V_53 ) ;
V_5 -> V_55 = 1 ;
V_2 += sizeof( * V_5 ) ;
V_23 -> V_39 = 2 ;
}
if ( V_23 -> V_52 ) {
F_4 ( L_13 ,
( unsigned ) V_23 -> V_56 ) ;
F_33 ( & V_2 , V_3 , L_14 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_54 = F_24 ( V_23 -> V_56 ) ;
V_5 -> V_55 = 0 ;
V_2 += sizeof( * V_5 ) ;
}
F_33 ( & V_2 , V_3 , L_15 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_54 = 0 ;
V_5 -> V_55 = 0 ;
V_2 += sizeof( * V_5 ) ;
V_49 -> V_26 . V_27 = V_2 - V_49 -> V_26 . V_43 ;
V_49 -> V_28 . V_29 = F_15 ( V_49 -> V_26 . V_27 ) ;
F_16 ( V_23 -> V_30 , V_49 ) ;
F_18 ( V_23 -> V_30 , F_17 ( V_49 ) ) ;
V_23 -> V_36 = V_38 | 1 ;
}
}
static void F_34 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
unsigned V_57 ;
struct V_58 * V_59 = V_49 -> V_26 . V_43 ;
if ( V_49 -> V_26 . V_27 < sizeof( * V_59 ) )
goto V_14;
V_57 = F_35 ( V_59 -> V_60 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_62 ) {
F_37 ( L_16 ,
V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 -> V_63 . V_20 ) ) ;
V_23 -> V_62 = false ;
}
F_4 ( L_17 , V_57 ) ;
V_23 -> V_37 = V_23 -> V_36 + ( V_57 >> 1 ) * V_46 - 1 ;
V_23 -> V_36 = 0 ;
F_38 ( & V_23 -> V_61 ) ;
return;
V_14:
F_39 ( L_18 ) ;
F_40 ( V_49 ) ;
}
int F_41 ( struct V_22 * V_23 , T_1 V_64 )
{
F_36 ( & V_23 -> V_61 ) ;
V_23 -> V_56 = V_64 ;
F_38 ( & V_23 -> V_61 ) ;
return 0 ;
}
int F_42 ( struct V_22 * V_23 , T_1 V_64 )
{
F_36 ( & V_23 -> V_61 ) ;
V_23 -> V_53 = V_64 ;
V_23 -> V_39 = 0 ;
F_38 ( & V_23 -> V_61 ) ;
return 0 ;
}
void F_43 ( struct V_22 * V_23 )
{
F_4 ( L_19 , V_23 -> V_53 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( ! V_23 -> V_39 )
V_23 -> V_39 = 1 ;
if ( V_23 -> V_39 < 2 )
F_31 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
}
int F_44 ( struct V_22 * V_23 )
{
if ( ! V_23 -> V_30 ) {
V_23 -> V_30 = F_8 ( sizeof( * V_23 -> V_30 ) , V_65 ) ;
if ( ! V_23 -> V_30 )
return - V_18 ;
F_45 ( V_23 -> V_66 -> V_67 , V_23 -> V_30 ) ;
V_23 -> V_30 -> V_68 = V_23 ;
V_23 -> V_30 -> V_69 = & V_70 ;
}
F_36 ( & V_23 -> V_61 ) ;
F_22 ( V_23 ) ;
F_29 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
return 0 ;
}
static void F_46 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_71 * V_66 = V_23 -> V_66 ;
struct V_1 * V_35 = NULL , * V_72 = V_23 -> V_35 ;
void * V_2 , * V_3 ;
F_36 ( & V_23 -> V_61 ) ;
F_4 ( L_20 ) ;
V_2 = V_49 -> V_26 . V_43 ;
V_3 = V_2 + V_49 -> V_26 . V_27 ;
V_35 = F_1 ( V_2 , V_3 ) ;
if ( F_47 ( V_35 ) ) {
F_39 ( L_21 ,
( int ) F_48 ( V_35 ) ) ;
goto V_73;
}
if ( F_49 ( V_23 -> V_66 , & V_35 -> V_9 ) < 0 ) {
F_12 ( V_35 ) ;
goto V_73;
}
V_66 -> V_23 . V_35 = V_35 ;
F_12 ( V_72 ) ;
V_73:
F_38 ( & V_23 -> V_61 ) ;
F_50 ( & V_66 -> V_74 ) ;
}
static struct V_75 * F_51 (
struct V_22 * V_23 , T_3 V_76 )
{
struct V_75 * V_77 ;
struct V_78 * V_79 = V_23 -> V_80 . V_78 ;
while ( V_79 ) {
V_77 = F_52 ( V_79 , struct V_75 , V_81 ) ;
if ( V_76 < V_77 -> V_76 )
V_79 = V_79 -> V_82 ;
else if ( V_76 > V_77 -> V_76 )
V_79 = V_79 -> V_83 ;
else
return V_77 ;
}
return NULL ;
}
static void F_53 ( struct V_22 * V_23 ,
struct V_75 * V_84 )
{
struct V_78 * * V_2 = & V_23 -> V_80 . V_78 ;
struct V_78 * V_85 = NULL ;
struct V_75 * V_77 = NULL ;
while ( * V_2 ) {
V_85 = * V_2 ;
V_77 = F_52 ( V_85 , struct V_75 , V_81 ) ;
if ( V_84 -> V_76 < V_77 -> V_76 )
V_2 = & ( * V_2 ) -> V_82 ;
else if ( V_84 -> V_76 > V_77 -> V_76 )
V_2 = & ( * V_2 ) -> V_83 ;
else
F_54 () ;
}
F_55 ( & V_84 -> V_81 , V_85 , V_2 ) ;
F_56 ( & V_84 -> V_81 , & V_23 -> V_80 ) ;
}
static void F_57 ( struct V_86 * V_86 )
{
struct V_75 * V_77 =
F_58 ( V_86 , struct V_75 , V_86 ) ;
if ( V_77 -> V_87 )
F_59 ( V_77 -> V_87 ) ;
if ( V_77 -> V_88 )
F_59 ( V_77 -> V_88 ) ;
F_12 ( V_77 ) ;
}
static void F_60 ( struct V_75 * V_77 )
{
F_61 ( & V_77 -> V_86 , F_57 ) ;
}
static void F_62 ( struct V_75 * V_77 )
{
F_63 ( & V_77 -> V_86 ) ;
}
static struct V_48 * F_64 ( struct V_89 * V_30 ,
struct V_90 * V_28 ,
int * V_91 )
{
struct V_22 * V_23 = V_30 -> V_68 ;
struct V_75 * V_77 ;
T_3 V_76 = F_65 ( V_28 -> V_76 ) ;
struct V_48 * V_4 ;
F_36 ( & V_23 -> V_61 ) ;
V_77 = F_51 ( V_23 , V_76 ) ;
if ( ! V_77 ) {
F_4 ( L_22 , V_76 ) ;
* V_91 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_23 , V_76 , V_77 -> V_87 ) ;
V_4 = F_17 ( V_77 -> V_87 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
return V_4 ;
}
static int F_66 ( struct V_22 * V_23 ,
struct V_75 * V_77 )
{
int V_6 ;
F_36 ( & V_23 -> V_61 ) ;
V_77 -> V_76 = ++ V_23 -> V_92 ;
V_77 -> V_88 -> V_28 . V_76 = F_24 ( V_77 -> V_76 ) ;
F_53 ( V_23 , V_77 ) ;
V_23 -> V_93 ++ ;
F_18 ( V_23 -> V_30 , F_17 ( V_77 -> V_88 ) ) ;
F_38 ( & V_23 -> V_61 ) ;
V_6 = F_67 ( & V_77 -> V_94 ) ;
F_36 ( & V_23 -> V_61 ) ;
F_68 ( & V_77 -> V_81 , & V_23 -> V_80 ) ;
V_23 -> V_93 -- ;
F_38 ( & V_23 -> V_61 ) ;
if ( ! V_6 )
V_6 = V_77 -> V_95 ;
return V_6 ;
}
static void F_69 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_75 * V_77 ;
struct V_96 * V_87 = V_49 -> V_26 . V_43 ;
T_3 V_76 = F_65 ( V_49 -> V_28 . V_76 ) ;
if ( V_49 -> V_26 . V_27 != sizeof( * V_87 ) )
goto V_14;
F_4 ( L_24 , V_49 , V_76 ) ;
F_36 ( & V_23 -> V_61 ) ;
V_77 = F_51 ( V_23 , V_76 ) ;
if ( V_77 ) {
* (struct V_97 * ) V_77 -> V_98 = V_87 -> V_99 ;
V_77 -> V_95 = 0 ;
F_62 ( V_77 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
if ( V_77 ) {
F_70 ( & V_77 -> V_94 ) ;
F_60 ( V_77 ) ;
}
return;
V_14:
F_39 ( L_25 , V_76 ) ;
F_40 ( V_49 ) ;
}
int F_71 ( struct V_22 * V_23 , struct V_97 * V_98 )
{
struct V_75 * V_77 ;
struct V_100 * V_59 ;
int V_6 ;
V_77 = F_72 ( sizeof( * V_77 ) , V_17 ) ;
if ( ! V_77 )
return - V_18 ;
F_73 ( & V_77 -> V_86 ) ;
V_77 -> V_98 = V_98 ;
V_77 -> V_101 = sizeof( * V_98 ) ;
F_74 ( & V_77 -> V_94 ) ;
V_6 = - V_18 ;
V_77 -> V_88 = F_75 ( V_102 , sizeof( * V_59 ) , V_17 ) ;
if ( ! V_77 -> V_88 )
goto V_73;
V_77 -> V_87 = F_75 ( V_103 , 1024 , V_17 ) ;
if ( ! V_77 -> V_87 )
goto V_73;
V_59 = V_77 -> V_88 -> V_26 . V_43 ;
V_59 -> V_104 . V_105 = 0 ;
V_59 -> V_104 . V_106 = F_76 ( - 1 ) ;
V_59 -> V_104 . V_107 = 0 ;
V_59 -> V_9 = V_23 -> V_35 -> V_9 ;
V_6 = F_66 ( V_23 , V_77 ) ;
V_73:
F_61 ( & V_77 -> V_86 , F_57 ) ;
return V_6 ;
}
static int F_77 ( const char * V_108 , T_4 V_109 ,
char * V_110 , T_4 V_111 )
{
T_1 V_101 ;
if ( V_109 != sizeof( T_1 ) + V_111 )
return - V_7 ;
V_101 = F_35 ( * ( T_1 * ) V_108 ) ;
if ( V_101 != V_111 )
return - V_7 ;
memcpy ( V_110 , V_108 + sizeof( T_1 ) , V_111 ) ;
return 0 ;
}
static void F_78 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_75 * V_77 ;
struct V_112 * V_87 = V_49 -> V_26 . V_43 ;
T_3 V_76 = F_65 ( V_49 -> V_28 . V_76 ) ;
if ( V_49 -> V_26 . V_27 < sizeof( * V_87 ) )
goto V_14;
F_4 ( L_26 , V_49 , V_76 ) ;
F_36 ( & V_23 -> V_61 ) ;
V_77 = F_51 ( V_23 , V_76 ) ;
if ( V_77 ) {
if ( V_77 -> V_101 &&
F_77 ( V_49 -> V_26 . V_43 + sizeof( * V_87 ) ,
V_49 -> V_26 . V_27 - sizeof( * V_87 ) ,
V_77 -> V_98 , V_77 -> V_101 ) < 0 ) {
F_38 ( & V_23 -> V_61 ) ;
goto V_14;
}
V_77 -> V_95 = F_35 ( V_87 -> V_113 ) ;
F_62 ( V_77 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
if ( V_77 ) {
F_79 ( & V_77 -> V_94 ) ;
F_60 ( V_77 ) ;
}
return;
V_14:
F_39 ( L_25 , V_76 ) ;
F_40 ( V_49 ) ;
}
int F_80 ( struct V_22 * V_23 , T_1 V_114 ,
T_1 V_115 , T_3 V_116 ,
char * V_98 , int V_13 )
{
struct V_75 * V_77 ;
struct V_117 * V_59 ;
int V_6 ;
V_77 = F_72 ( sizeof( * V_77 ) , V_17 ) ;
if ( ! V_77 )
return - V_18 ;
F_73 ( & V_77 -> V_86 ) ;
V_77 -> V_98 = V_98 ;
V_77 -> V_101 = V_13 ;
F_74 ( & V_77 -> V_94 ) ;
V_6 = - V_18 ;
V_77 -> V_88 = F_75 ( V_118 , sizeof( * V_59 ) , V_17 ) ;
if ( ! V_77 -> V_88 )
goto V_73;
V_77 -> V_87 = F_75 ( V_119 , 1024 , V_17 ) ;
if ( ! V_77 -> V_87 )
goto V_73;
V_77 -> V_88 -> V_28 . V_12 = F_76 ( 2 ) ;
V_59 = V_77 -> V_88 -> V_26 . V_43 ;
V_59 -> V_104 . V_105 = 0 ;
V_59 -> V_104 . V_106 = F_76 ( - 1 ) ;
V_59 -> V_104 . V_107 = 0 ;
V_59 -> V_9 = V_23 -> V_35 -> V_9 ;
V_59 -> V_115 = F_15 ( V_115 ) ;
V_59 -> V_114 = F_15 ( V_114 ) ;
V_59 -> V_120 = 0 ;
V_59 -> V_116 = F_24 ( V_116 ) ;
V_59 -> V_121 = 0 ;
V_6 = F_66 ( V_23 , V_77 ) ;
V_73:
F_61 ( & V_77 -> V_86 , F_57 ) ;
return V_6 ;
}
int F_81 ( struct V_22 * V_23 ,
T_1 V_115 , T_3 * V_116 )
{
return F_80 ( V_23 , V_122 ,
V_115 , 0 , ( char * ) V_116 , sizeof( * V_116 ) ) ;
}
int F_82 ( struct V_22 * V_23 ,
T_1 V_115 , T_3 V_116 )
{
return F_80 ( V_23 , V_122 ,
V_115 , V_116 , 0 , 0 ) ;
}
static void F_83 ( struct V_22 * V_23 )
{
struct V_75 * V_77 ;
struct V_78 * V_2 ;
for ( V_2 = F_84 ( & V_23 -> V_80 ) ; V_2 ; V_2 = F_85 ( V_2 ) ) {
V_77 = F_52 ( V_2 , struct V_75 , V_81 ) ;
F_16 ( V_23 -> V_30 , V_77 -> V_88 ) ;
F_18 ( V_23 -> V_30 , F_17 ( V_77 -> V_88 ) ) ;
}
}
static void V_47 ( struct V_123 * V_124 )
{
struct V_22 * V_23 =
F_58 ( V_124 , struct V_22 , V_47 . V_124 ) ;
F_4 ( L_27 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_62 ) {
F_19 ( V_23 ) ;
F_22 ( V_23 ) ;
} else {
F_86 ( V_23 -> V_30 ) ;
F_87 ( V_23 ) ;
if ( V_23 -> V_32 -> V_69 -> V_125 ( V_23 -> V_32 ) )
F_31 ( V_23 ) ;
}
F_29 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
}
static int F_88 ( struct V_22 * V_23 )
{
struct V_126 * V_127 = V_23 -> V_66 -> V_128 ;
struct V_21 * V_129 = V_127 -> V_129 ;
int V_11 = V_127 -> V_11 ;
int V_5 ;
V_23 -> V_35 = F_72 ( sizeof( * V_23 -> V_35 ) +
V_11 * sizeof( V_23 -> V_35 -> V_15 [ 0 ] ) ,
V_65 ) ;
if ( ! V_23 -> V_35 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_35 -> V_15 [ V_5 ] . V_19 = V_129 [ V_5 ] ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_19 . V_130 = 0 ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_131 . type =
V_41 ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_131 . V_42 = F_24 ( V_5 ) ;
}
V_23 -> V_35 -> V_11 = V_11 ;
V_23 -> V_132 = false ;
return 0 ;
}
int F_89 ( struct V_22 * V_23 , struct V_71 * V_133 )
{
int V_6 = 0 ;
F_4 ( L_28 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_66 = V_133 ;
V_23 -> V_35 = NULL ;
F_90 ( & V_23 -> V_61 ) ;
V_6 = F_88 ( V_23 ) ;
if ( V_6 )
goto V_73;
V_23 -> V_30 = NULL ;
V_23 -> V_32 = F_91 ( V_133 -> V_128 -> V_131 ,
V_133 -> V_128 -> V_134 ) ;
if ( F_47 ( V_23 -> V_32 ) )
return F_48 ( V_23 -> V_32 ) ;
V_23 -> V_32 -> V_135 =
V_136 | V_41 |
V_137 | V_138 ;
V_6 = - V_18 ;
V_23 -> V_139 = F_75 ( V_140 ,
sizeof( struct V_58 ) ,
V_17 ) ;
if ( ! V_23 -> V_139 )
goto V_141;
V_23 -> V_50 = F_75 ( V_142 , 96 , V_17 ) ;
if ( ! V_23 -> V_50 )
goto V_143;
V_23 -> V_144 = F_75 ( V_145 , 4096 , V_17 ) ;
if ( ! V_23 -> V_144 )
goto V_146;
V_23 -> V_25 = F_75 ( V_147 , 4096 , V_17 ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_148;
V_23 -> V_31 = - 1 ;
V_23 -> V_62 = true ;
V_23 -> V_37 = V_38 ;
V_23 -> V_36 = 0 ;
F_92 ( & V_23 -> V_47 , V_47 ) ;
V_23 -> V_80 = V_149 ;
V_23 -> V_93 = 0 ;
V_23 -> V_92 = 0 ;
V_23 -> V_56 = 0 ;
V_23 -> V_53 = 0 ;
V_23 -> V_39 = 1 ;
return 0 ;
V_148:
F_59 ( V_23 -> V_144 ) ;
V_146:
F_59 ( V_23 -> V_50 ) ;
V_143:
F_59 ( V_23 -> V_139 ) ;
V_141:
F_12 ( V_23 -> V_35 ) ;
V_73:
return V_6 ;
}
void F_93 ( struct V_22 * V_23 )
{
F_4 ( L_29 ) ;
F_94 ( & V_23 -> V_47 ) ;
F_36 ( & V_23 -> V_61 ) ;
F_19 ( V_23 ) ;
if ( V_23 -> V_30 ) {
V_23 -> V_30 -> V_68 = NULL ;
V_23 -> V_30 -> V_69 -> V_150 ( V_23 -> V_30 ) ;
V_23 -> V_30 = NULL ;
}
F_38 ( & V_23 -> V_61 ) ;
F_95 ( V_23 -> V_32 ) ;
F_59 ( V_23 -> V_25 ) ;
F_59 ( V_23 -> V_144 ) ;
F_59 ( V_23 -> V_50 ) ;
F_59 ( V_23 -> V_139 ) ;
F_12 ( V_23 -> V_35 ) ;
}
static void F_96 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
int V_34 ;
int V_151 = 0 ;
F_36 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_32 -> V_69 )
V_151 = V_23 -> V_32 -> V_69 -> V_125 ( V_23 -> V_32 ) ;
V_23 -> V_24 = 0 ;
V_34 = F_97 ( V_23 -> V_32 , V_49 -> V_26 . V_43 ,
V_49 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_43 ,
V_23 -> V_25 -> V_44 ) ;
if ( V_34 < 0 ) {
V_23 -> V_66 -> V_152 = V_34 ;
F_50 ( & V_23 -> V_66 -> V_74 ) ;
} else if ( V_34 > 0 ) {
F_14 ( V_23 , V_34 ) ;
} else if ( ! V_151 && V_23 -> V_32 -> V_69 -> V_125 ( V_23 -> V_32 ) ) {
F_4 ( L_30 ) ;
V_23 -> V_66 -> V_67 -> V_153 . V_131 . type = V_154 ;
V_23 -> V_66 -> V_67 -> V_153 . V_131 . V_42 =
F_24 ( V_23 -> V_32 -> V_155 ) ;
F_31 ( V_23 ) ;
F_83 ( V_23 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
}
static int F_87 ( struct V_22 * V_23 )
{
int V_34 ;
if ( V_23 -> V_24 )
return 0 ;
V_34 = F_98 ( V_23 -> V_32 , V_23 -> V_25 -> V_26 . V_43 ,
V_23 -> V_25 -> V_44 ) ;
if ( V_34 <= 0 )
return V_34 ;
F_14 ( V_23 , V_34 ) ;
return 0 ;
}
int F_99 ( struct V_22 * V_23 )
{
int V_34 ;
F_36 ( & V_23 -> V_61 ) ;
V_34 = F_87 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
return V_34 ;
}
static void F_100 ( struct V_89 * V_30 , struct V_48 * V_49 )
{
struct V_22 * V_23 = V_30 -> V_68 ;
int type = F_101 ( V_49 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_145 :
F_96 ( V_23 , V_49 ) ;
break;
case V_140 :
F_34 ( V_23 , V_49 ) ;
break;
case V_103 :
F_69 ( V_23 , V_49 ) ;
break;
case V_119 :
F_78 ( V_23 , V_49 ) ;
break;
case V_156 :
F_46 ( V_23 , V_49 ) ;
break;
case V_157 :
F_102 ( & V_23 -> V_66 -> V_158 , V_49 ) ;
break;
default:
if ( V_23 -> V_66 -> V_159 &&
V_23 -> V_66 -> V_159 ( V_23 -> V_66 , V_49 ) == 0 )
break;
F_39 ( L_31 , type ,
F_103 ( type ) ) ;
}
F_59 ( V_49 ) ;
}
static struct V_48 * F_104 ( struct V_89 * V_30 ,
struct V_90 * V_28 ,
int * V_91 )
{
struct V_22 * V_23 = V_30 -> V_68 ;
int type = F_101 ( V_28 -> type ) ;
int V_29 = F_35 ( V_28 -> V_29 ) ;
struct V_48 * V_4 = NULL ;
* V_91 = 0 ;
switch ( type ) {
case V_140 :
V_4 = F_17 ( V_23 -> V_139 ) ;
break;
case V_119 :
case V_103 :
return F_64 ( V_30 , V_28 , V_91 ) ;
case V_145 :
V_4 = F_17 ( V_23 -> V_144 ) ;
break;
case V_156 :
case V_160 :
case V_157 :
V_4 = F_75 ( type , V_29 , V_17 ) ;
break;
}
if ( ! V_4 ) {
F_37 ( L_32 , type ) ;
* V_91 = 1 ;
}
return V_4 ;
}
static void F_105 ( struct V_89 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_68 ;
if ( ! V_23 )
return;
F_4 ( L_33 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( ! V_30 -> V_68 )
goto V_73;
if ( V_23 -> V_30 && ! V_23 -> V_62 )
F_37 ( L_34
L_35 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 -> V_63 . V_20 ) ) ;
F_19 ( V_23 ) ;
if ( ! V_23 -> V_62 ) {
V_23 -> V_62 = true ;
F_22 ( V_23 ) ;
} else {
F_29 ( V_23 ) ;
}
V_73:
F_38 ( & V_23 -> V_61 ) ;
}
