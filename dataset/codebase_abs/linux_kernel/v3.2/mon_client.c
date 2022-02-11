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
F_4 ( L_5 , V_23 -> V_31 ) ;
F_16 ( V_23 -> V_30 , V_23 -> V_25 ) ;
F_20 ( V_23 -> V_30 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_24 = 0 ;
F_21 ( V_23 -> V_32 ) ;
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
F_36 ( & V_23 -> V_61 ) ;
F_22 ( V_23 ) ;
F_29 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
return 0 ;
}
static void F_45 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_65 * V_66 = V_23 -> V_66 ;
struct V_1 * V_35 = NULL , * V_67 = V_23 -> V_35 ;
void * V_2 , * V_3 ;
F_36 ( & V_23 -> V_61 ) ;
F_4 ( L_20 ) ;
V_2 = V_49 -> V_26 . V_43 ;
V_3 = V_2 + V_49 -> V_26 . V_27 ;
V_35 = F_1 ( V_2 , V_3 ) ;
if ( F_46 ( V_35 ) ) {
F_39 ( L_21 ,
( int ) F_47 ( V_35 ) ) ;
goto V_68;
}
if ( F_48 ( V_23 -> V_66 , & V_35 -> V_9 ) < 0 ) {
F_12 ( V_35 ) ;
goto V_68;
}
V_66 -> V_23 . V_35 = V_35 ;
F_12 ( V_67 ) ;
V_68:
F_38 ( & V_23 -> V_61 ) ;
F_49 ( & V_66 -> V_69 ) ;
}
static struct V_70 * F_50 (
struct V_22 * V_23 , T_3 V_71 )
{
struct V_70 * V_72 ;
struct V_73 * V_74 = V_23 -> V_75 . V_73 ;
while ( V_74 ) {
V_72 = F_51 ( V_74 , struct V_70 , V_76 ) ;
if ( V_71 < V_72 -> V_71 )
V_74 = V_74 -> V_77 ;
else if ( V_71 > V_72 -> V_71 )
V_74 = V_74 -> V_78 ;
else
return V_72 ;
}
return NULL ;
}
static void F_52 ( struct V_22 * V_23 ,
struct V_70 * V_79 )
{
struct V_73 * * V_2 = & V_23 -> V_75 . V_73 ;
struct V_73 * V_80 = NULL ;
struct V_70 * V_72 = NULL ;
while ( * V_2 ) {
V_80 = * V_2 ;
V_72 = F_51 ( V_80 , struct V_70 , V_76 ) ;
if ( V_79 -> V_71 < V_72 -> V_71 )
V_2 = & ( * V_2 ) -> V_77 ;
else if ( V_79 -> V_71 > V_72 -> V_71 )
V_2 = & ( * V_2 ) -> V_78 ;
else
F_53 () ;
}
F_54 ( & V_79 -> V_76 , V_80 , V_2 ) ;
F_55 ( & V_79 -> V_76 , & V_23 -> V_75 ) ;
}
static void F_56 ( struct V_81 * V_81 )
{
struct V_70 * V_72 =
F_57 ( V_81 , struct V_70 , V_81 ) ;
if ( V_72 -> V_82 )
F_58 ( V_72 -> V_82 ) ;
if ( V_72 -> V_83 )
F_58 ( V_72 -> V_83 ) ;
F_12 ( V_72 ) ;
}
static void F_59 ( struct V_70 * V_72 )
{
F_60 ( & V_72 -> V_81 , F_56 ) ;
}
static void F_61 ( struct V_70 * V_72 )
{
F_62 ( & V_72 -> V_81 ) ;
}
static struct V_48 * F_63 ( struct V_84 * V_30 ,
struct V_85 * V_28 ,
int * V_86 )
{
struct V_22 * V_23 = V_30 -> V_87 ;
struct V_70 * V_72 ;
T_3 V_71 = F_64 ( V_28 -> V_71 ) ;
struct V_48 * V_4 ;
F_36 ( & V_23 -> V_61 ) ;
V_72 = F_50 ( V_23 , V_71 ) ;
if ( ! V_72 ) {
F_4 ( L_22 , V_71 ) ;
* V_86 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_23 , V_71 , V_72 -> V_82 ) ;
V_4 = F_17 ( V_72 -> V_82 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
return V_4 ;
}
static int F_65 ( struct V_22 * V_23 ,
struct V_70 * V_72 )
{
int V_6 ;
F_36 ( & V_23 -> V_61 ) ;
V_72 -> V_71 = ++ V_23 -> V_88 ;
V_72 -> V_83 -> V_28 . V_71 = F_24 ( V_72 -> V_71 ) ;
F_52 ( V_23 , V_72 ) ;
V_23 -> V_89 ++ ;
F_18 ( V_23 -> V_30 , F_17 ( V_72 -> V_83 ) ) ;
F_38 ( & V_23 -> V_61 ) ;
V_6 = F_66 ( & V_72 -> V_90 ) ;
F_36 ( & V_23 -> V_61 ) ;
F_67 ( & V_72 -> V_76 , & V_23 -> V_75 ) ;
V_23 -> V_89 -- ;
F_38 ( & V_23 -> V_61 ) ;
if ( ! V_6 )
V_6 = V_72 -> V_91 ;
return V_6 ;
}
static void F_68 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_70 * V_72 ;
struct V_92 * V_82 = V_49 -> V_26 . V_43 ;
T_3 V_71 = F_64 ( V_49 -> V_28 . V_71 ) ;
if ( V_49 -> V_26 . V_27 != sizeof( * V_82 ) )
goto V_14;
F_4 ( L_24 , V_49 , V_71 ) ;
F_36 ( & V_23 -> V_61 ) ;
V_72 = F_50 ( V_23 , V_71 ) ;
if ( V_72 ) {
* (struct V_93 * ) V_72 -> V_94 = V_82 -> V_95 ;
V_72 -> V_91 = 0 ;
F_61 ( V_72 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
if ( V_72 ) {
F_69 ( & V_72 -> V_90 ) ;
F_59 ( V_72 ) ;
}
return;
V_14:
F_39 ( L_25 , V_71 ) ;
F_40 ( V_49 ) ;
}
int F_70 ( struct V_22 * V_23 , struct V_93 * V_94 )
{
struct V_70 * V_72 ;
struct V_96 * V_59 ;
int V_6 ;
V_72 = F_71 ( sizeof( * V_72 ) , V_17 ) ;
if ( ! V_72 )
return - V_18 ;
F_72 ( & V_72 -> V_81 ) ;
V_72 -> V_94 = V_94 ;
V_72 -> V_97 = sizeof( * V_94 ) ;
F_73 ( & V_72 -> V_90 ) ;
V_6 = - V_18 ;
V_72 -> V_83 = F_74 ( V_98 , sizeof( * V_59 ) , V_17 ,
true ) ;
if ( ! V_72 -> V_83 )
goto V_68;
V_72 -> V_82 = F_74 ( V_99 , 1024 , V_17 ,
true ) ;
if ( ! V_72 -> V_82 )
goto V_68;
V_59 = V_72 -> V_83 -> V_26 . V_43 ;
V_59 -> V_100 . V_101 = 0 ;
V_59 -> V_100 . V_102 = F_75 ( - 1 ) ;
V_59 -> V_100 . V_103 = 0 ;
V_59 -> V_9 = V_23 -> V_35 -> V_9 ;
V_6 = F_65 ( V_23 , V_72 ) ;
V_68:
F_60 ( & V_72 -> V_81 , F_56 ) ;
return V_6 ;
}
static int F_76 ( const char * V_104 , T_4 V_105 ,
char * V_106 , T_4 V_107 )
{
T_1 V_97 ;
if ( V_105 != sizeof( T_1 ) + V_107 )
return - V_7 ;
V_97 = F_35 ( * ( T_1 * ) V_104 ) ;
if ( V_97 != V_107 )
return - V_7 ;
memcpy ( V_106 , V_104 + sizeof( T_1 ) , V_107 ) ;
return 0 ;
}
static void F_77 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
struct V_70 * V_72 ;
struct V_108 * V_82 = V_49 -> V_26 . V_43 ;
T_3 V_71 = F_64 ( V_49 -> V_28 . V_71 ) ;
if ( V_49 -> V_26 . V_27 < sizeof( * V_82 ) )
goto V_14;
F_4 ( L_26 , V_49 , V_71 ) ;
F_36 ( & V_23 -> V_61 ) ;
V_72 = F_50 ( V_23 , V_71 ) ;
if ( V_72 ) {
if ( V_72 -> V_97 &&
F_76 ( V_49 -> V_26 . V_43 + sizeof( * V_82 ) ,
V_49 -> V_26 . V_27 - sizeof( * V_82 ) ,
V_72 -> V_94 , V_72 -> V_97 ) < 0 ) {
F_38 ( & V_23 -> V_61 ) ;
goto V_14;
}
V_72 -> V_91 = F_35 ( V_82 -> V_109 ) ;
F_61 ( V_72 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
if ( V_72 ) {
F_78 ( & V_72 -> V_90 ) ;
F_59 ( V_72 ) ;
}
return;
V_14:
F_39 ( L_25 , V_71 ) ;
F_40 ( V_49 ) ;
}
int F_79 ( struct V_22 * V_23 , T_1 V_110 ,
T_1 V_111 , T_3 V_112 ,
char * V_94 , int V_13 )
{
struct V_70 * V_72 ;
struct V_113 * V_59 ;
int V_6 ;
V_72 = F_71 ( sizeof( * V_72 ) , V_17 ) ;
if ( ! V_72 )
return - V_18 ;
F_72 ( & V_72 -> V_81 ) ;
V_72 -> V_94 = V_94 ;
V_72 -> V_97 = V_13 ;
F_73 ( & V_72 -> V_90 ) ;
V_6 = - V_18 ;
V_72 -> V_83 = F_74 ( V_114 , sizeof( * V_59 ) , V_17 ,
true ) ;
if ( ! V_72 -> V_83 )
goto V_68;
V_72 -> V_82 = F_74 ( V_115 , 1024 , V_17 ,
true ) ;
if ( ! V_72 -> V_82 )
goto V_68;
V_72 -> V_83 -> V_28 . V_12 = F_75 ( 2 ) ;
V_59 = V_72 -> V_83 -> V_26 . V_43 ;
V_59 -> V_100 . V_101 = 0 ;
V_59 -> V_100 . V_102 = F_75 ( - 1 ) ;
V_59 -> V_100 . V_103 = 0 ;
V_59 -> V_9 = V_23 -> V_35 -> V_9 ;
V_59 -> V_111 = F_15 ( V_111 ) ;
V_59 -> V_110 = F_15 ( V_110 ) ;
V_59 -> V_116 = 0 ;
V_59 -> V_112 = F_24 ( V_112 ) ;
V_59 -> V_117 = 0 ;
V_6 = F_65 ( V_23 , V_72 ) ;
V_68:
F_60 ( & V_72 -> V_81 , F_56 ) ;
return V_6 ;
}
int F_80 ( struct V_22 * V_23 ,
T_1 V_111 , T_3 * V_112 )
{
return F_79 ( V_23 , V_118 ,
V_111 , 0 , ( char * ) V_112 , sizeof( * V_112 ) ) ;
}
int F_81 ( struct V_22 * V_23 ,
T_1 V_111 , T_3 V_112 )
{
return F_79 ( V_23 , V_118 ,
V_111 , V_112 , 0 , 0 ) ;
}
static void F_82 ( struct V_22 * V_23 )
{
struct V_70 * V_72 ;
struct V_73 * V_2 ;
for ( V_2 = F_83 ( & V_23 -> V_75 ) ; V_2 ; V_2 = F_84 ( V_2 ) ) {
V_72 = F_51 ( V_2 , struct V_70 , V_76 ) ;
F_16 ( V_23 -> V_30 , V_72 -> V_83 ) ;
F_18 ( V_23 -> V_30 , F_17 ( V_72 -> V_83 ) ) ;
}
}
static void V_47 ( struct V_119 * V_120 )
{
struct V_22 * V_23 =
F_57 ( V_120 , struct V_22 , V_47 . V_120 ) ;
F_4 ( L_27 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_62 ) {
F_19 ( V_23 ) ;
F_22 ( V_23 ) ;
} else {
F_85 ( V_23 -> V_30 ) ;
F_86 ( V_23 ) ;
if ( V_23 -> V_32 -> V_121 -> V_122 ( V_23 -> V_32 ) )
F_31 ( V_23 ) ;
}
F_29 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
}
static int F_87 ( struct V_22 * V_23 )
{
struct V_123 * V_124 = V_23 -> V_66 -> V_125 ;
struct V_21 * V_126 = V_124 -> V_126 ;
int V_11 = V_124 -> V_11 ;
int V_5 ;
V_23 -> V_35 = F_71 ( sizeof( * V_23 -> V_35 ) +
V_11 * sizeof( V_23 -> V_35 -> V_15 [ 0 ] ) ,
V_127 ) ;
if ( ! V_23 -> V_35 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_35 -> V_15 [ V_5 ] . V_19 = V_126 [ V_5 ] ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_19 . V_128 = 0 ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_129 . type =
V_41 ;
V_23 -> V_35 -> V_15 [ V_5 ] . V_129 . V_42 = F_24 ( V_5 ) ;
}
V_23 -> V_35 -> V_11 = V_11 ;
V_23 -> V_130 = false ;
return 0 ;
}
int F_88 ( struct V_22 * V_23 , struct V_65 * V_131 )
{
int V_6 = 0 ;
F_4 ( L_28 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_66 = V_131 ;
V_23 -> V_35 = NULL ;
F_89 ( & V_23 -> V_61 ) ;
V_6 = F_87 ( V_23 ) ;
if ( V_6 )
goto V_68;
V_23 -> V_30 = F_8 ( sizeof( * V_23 -> V_30 ) , V_127 ) ;
if ( ! V_23 -> V_30 )
goto V_132;
F_90 ( V_23 -> V_66 -> V_133 , V_23 -> V_30 ) ;
V_23 -> V_30 -> V_87 = V_23 ;
V_23 -> V_30 -> V_121 = & V_134 ;
V_23 -> V_32 = F_91 ( V_131 -> V_125 -> V_129 ,
V_131 -> V_125 -> V_135 ) ;
if ( F_46 ( V_23 -> V_32 ) ) {
V_6 = F_47 ( V_23 -> V_32 ) ;
goto V_136;
}
V_23 -> V_32 -> V_137 =
V_138 | V_41 |
V_139 | V_140 ;
V_6 = - V_18 ;
V_23 -> V_141 = F_74 ( V_142 ,
sizeof( struct V_58 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_141 )
goto V_143;
V_23 -> V_50 = F_74 ( V_144 , 96 , V_17 ,
true ) ;
if ( ! V_23 -> V_50 )
goto V_145;
V_23 -> V_146 = F_74 ( V_147 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_146 )
goto V_148;
V_23 -> V_25 = F_74 ( V_149 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_150;
V_23 -> V_31 = - 1 ;
V_23 -> V_62 = true ;
V_23 -> V_37 = V_38 ;
V_23 -> V_36 = 0 ;
F_92 ( & V_23 -> V_47 , V_47 ) ;
V_23 -> V_75 = V_151 ;
V_23 -> V_89 = 0 ;
V_23 -> V_88 = 0 ;
V_23 -> V_56 = 0 ;
V_23 -> V_53 = 0 ;
V_23 -> V_39 = 1 ;
return 0 ;
V_150:
F_58 ( V_23 -> V_146 ) ;
V_148:
F_58 ( V_23 -> V_50 ) ;
V_145:
F_58 ( V_23 -> V_141 ) ;
V_143:
F_93 ( V_23 -> V_32 ) ;
V_136:
V_23 -> V_30 -> V_121 -> V_152 ( V_23 -> V_30 ) ;
V_132:
F_12 ( V_23 -> V_35 ) ;
V_68:
return V_6 ;
}
void F_94 ( struct V_22 * V_23 )
{
F_4 ( L_29 ) ;
F_95 ( & V_23 -> V_47 ) ;
F_36 ( & V_23 -> V_61 ) ;
F_19 ( V_23 ) ;
V_23 -> V_30 -> V_87 = NULL ;
V_23 -> V_30 -> V_121 -> V_152 ( V_23 -> V_30 ) ;
V_23 -> V_30 = NULL ;
F_38 ( & V_23 -> V_61 ) ;
F_93 ( V_23 -> V_32 ) ;
F_58 ( V_23 -> V_25 ) ;
F_58 ( V_23 -> V_146 ) ;
F_58 ( V_23 -> V_50 ) ;
F_58 ( V_23 -> V_141 ) ;
F_12 ( V_23 -> V_35 ) ;
}
static void F_96 ( struct V_22 * V_23 ,
struct V_48 * V_49 )
{
int V_34 ;
int V_153 = 0 ;
F_36 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_32 -> V_121 )
V_153 = V_23 -> V_32 -> V_121 -> V_122 ( V_23 -> V_32 ) ;
V_23 -> V_24 = 0 ;
V_34 = F_97 ( V_23 -> V_32 , V_49 -> V_26 . V_43 ,
V_49 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_43 ,
V_23 -> V_25 -> V_44 ) ;
if ( V_34 < 0 ) {
V_23 -> V_66 -> V_154 = V_34 ;
F_49 ( & V_23 -> V_66 -> V_69 ) ;
} else if ( V_34 > 0 ) {
F_14 ( V_23 , V_34 ) ;
} else if ( ! V_153 && V_23 -> V_32 -> V_121 -> V_122 ( V_23 -> V_32 ) ) {
F_4 ( L_30 ) ;
V_23 -> V_66 -> V_133 -> V_155 . V_129 . type = V_156 ;
V_23 -> V_66 -> V_133 -> V_155 . V_129 . V_42 =
F_24 ( V_23 -> V_32 -> V_157 ) ;
F_31 ( V_23 ) ;
F_82 ( V_23 ) ;
}
F_38 ( & V_23 -> V_61 ) ;
}
static int F_86 ( struct V_22 * V_23 )
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
V_34 = F_86 ( V_23 ) ;
F_38 ( & V_23 -> V_61 ) ;
return V_34 ;
}
static void F_100 ( struct V_84 * V_30 , struct V_48 * V_49 )
{
struct V_22 * V_23 = V_30 -> V_87 ;
int type = F_101 ( V_49 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_147 :
F_96 ( V_23 , V_49 ) ;
break;
case V_142 :
F_34 ( V_23 , V_49 ) ;
break;
case V_99 :
F_68 ( V_23 , V_49 ) ;
break;
case V_115 :
F_77 ( V_23 , V_49 ) ;
break;
case V_158 :
F_45 ( V_23 , V_49 ) ;
break;
case V_159 :
F_102 ( & V_23 -> V_66 -> V_160 , V_49 ) ;
break;
default:
if ( V_23 -> V_66 -> V_161 &&
V_23 -> V_66 -> V_161 ( V_23 -> V_66 , V_49 ) == 0 )
break;
F_39 ( L_31 , type ,
F_103 ( type ) ) ;
}
F_58 ( V_49 ) ;
}
static struct V_48 * F_104 ( struct V_84 * V_30 ,
struct V_85 * V_28 ,
int * V_86 )
{
struct V_22 * V_23 = V_30 -> V_87 ;
int type = F_101 ( V_28 -> type ) ;
int V_29 = F_35 ( V_28 -> V_29 ) ;
struct V_48 * V_4 = NULL ;
* V_86 = 0 ;
switch ( type ) {
case V_142 :
V_4 = F_17 ( V_23 -> V_141 ) ;
break;
case V_115 :
case V_99 :
return F_63 ( V_30 , V_28 , V_86 ) ;
case V_147 :
V_4 = F_17 ( V_23 -> V_146 ) ;
break;
case V_158 :
case V_162 :
case V_159 :
V_4 = F_74 ( type , V_29 , V_17 , false ) ;
break;
}
if ( ! V_4 ) {
F_37 ( L_32 , type ) ;
* V_86 = 1 ;
}
return V_4 ;
}
static void F_105 ( struct V_84 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_87 ;
if ( ! V_23 )
return;
F_4 ( L_33 ) ;
F_36 ( & V_23 -> V_61 ) ;
if ( ! V_30 -> V_87 )
goto V_68;
if ( ! V_23 -> V_62 )
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
V_68:
F_38 ( & V_23 -> V_61 ) ;
}
