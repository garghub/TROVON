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
int F_45 ( struct V_22 * V_23 , T_1 V_10 ,
unsigned long V_66 )
{
unsigned long V_67 = V_41 ;
int V_37 ;
F_37 ( & V_23 -> V_62 ) ;
while ( V_23 -> V_54 < V_10 ) {
F_39 ( & V_23 -> V_62 ) ;
if ( V_66 != 0 && F_28 ( V_41 , V_67 + V_66 ) )
return - V_68 ;
V_37 = F_46 ( V_23 -> V_69 -> V_70 ,
V_23 -> V_54 >= V_10 , V_66 ) ;
if ( V_37 < 0 )
return V_37 ;
F_37 ( & V_23 -> V_62 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
return 0 ;
}
int F_47 ( struct V_22 * V_23 )
{
F_37 ( & V_23 -> V_62 ) ;
F_23 ( V_23 ) ;
F_29 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
return 0 ;
}
static bool F_48 ( struct V_22 * V_23 )
{
F_4 ( L_20 ,
( int ) V_23 -> V_69 -> V_71 , V_23 -> V_35 -> V_72 ) ;
return V_23 -> V_69 -> V_71 && V_23 -> V_35 -> V_72 > 0 ;
}
static void F_49 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_73 * V_69 = V_23 -> V_69 ;
struct V_1 * V_38 = NULL , * V_74 = V_23 -> V_38 ;
void * V_2 , * V_3 ;
int V_75 , V_76 = 0 ;
F_37 ( & V_23 -> V_62 ) ;
V_75 = F_48 ( V_23 ) ;
F_4 ( L_21 ) ;
V_2 = V_50 -> V_26 . V_44 ;
V_3 = V_2 + V_50 -> V_26 . V_27 ;
V_38 = F_1 ( V_2 , V_3 ) ;
if ( F_50 ( V_38 ) ) {
F_40 ( L_22 ,
( int ) F_51 ( V_38 ) ) ;
goto V_77;
}
if ( F_52 ( V_23 -> V_69 , & V_38 -> V_9 ) < 0 ) {
F_12 ( V_38 ) ;
goto V_77;
}
V_69 -> V_23 . V_38 = V_38 ;
F_12 ( V_74 ) ;
if ( ! V_69 -> V_71 ) {
V_69 -> V_71 = true ;
if ( ! V_75 && F_48 ( V_23 ) ) {
F_38 ( L_23 ,
F_53 ( V_23 -> V_69 ) ,
& V_23 -> V_69 -> V_9 ) ;
V_76 = 1 ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_76 ) {
F_54 ( V_23 -> V_69 ) ;
}
goto V_78;
}
V_77:
F_39 ( & V_23 -> V_62 ) ;
V_78:
F_55 ( & V_69 -> V_70 ) ;
}
static struct V_79 * F_56 (
struct V_22 * V_23 , T_3 V_80 )
{
struct V_79 * V_81 ;
struct V_82 * V_83 = V_23 -> V_84 . V_82 ;
while ( V_83 ) {
V_81 = F_57 ( V_83 , struct V_79 , V_85 ) ;
if ( V_80 < V_81 -> V_80 )
V_83 = V_83 -> V_86 ;
else if ( V_80 > V_81 -> V_80 )
V_83 = V_83 -> V_87 ;
else
return V_81 ;
}
return NULL ;
}
static void F_58 ( struct V_22 * V_23 ,
struct V_79 * V_88 )
{
struct V_82 * * V_2 = & V_23 -> V_84 . V_82 ;
struct V_82 * V_89 = NULL ;
struct V_79 * V_81 = NULL ;
while ( * V_2 ) {
V_89 = * V_2 ;
V_81 = F_57 ( V_89 , struct V_79 , V_85 ) ;
if ( V_88 -> V_80 < V_81 -> V_80 )
V_2 = & ( * V_2 ) -> V_86 ;
else if ( V_88 -> V_80 > V_81 -> V_80 )
V_2 = & ( * V_2 ) -> V_87 ;
else
F_59 () ;
}
F_60 ( & V_88 -> V_85 , V_89 , V_2 ) ;
F_61 ( & V_88 -> V_85 , & V_23 -> V_84 ) ;
}
static void F_62 ( struct V_90 * V_90 )
{
struct V_79 * V_81 =
F_63 ( V_90 , struct V_79 , V_90 ) ;
if ( V_81 -> V_91 )
F_64 ( V_81 -> V_91 ) ;
if ( V_81 -> V_92 )
F_64 ( V_81 -> V_92 ) ;
F_12 ( V_81 ) ;
}
static void F_65 ( struct V_79 * V_81 )
{
F_66 ( & V_81 -> V_90 , F_62 ) ;
}
static void F_67 ( struct V_79 * V_81 )
{
F_68 ( & V_81 -> V_90 ) ;
}
static struct V_49 * F_69 ( struct V_93 * V_30 ,
struct V_94 * V_28 ,
int * V_95 )
{
struct V_22 * V_23 = V_30 -> V_96 ;
struct V_79 * V_81 ;
T_3 V_80 = F_70 ( V_28 -> V_80 ) ;
struct V_49 * V_4 ;
F_37 ( & V_23 -> V_62 ) ;
V_81 = F_56 ( V_23 , V_80 ) ;
if ( ! V_81 ) {
F_4 ( L_24 , V_80 ) ;
* V_95 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_25 , V_80 , V_81 -> V_91 ) ;
* V_95 = 0 ;
V_4 = F_17 ( V_81 -> V_91 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
return V_4 ;
}
static int F_71 ( struct V_22 * V_23 , T_3 V_80 ,
struct V_79 * V_81 )
{
int V_6 ;
V_81 -> V_80 = V_80 != 0 ? V_80 : ++ V_23 -> V_97 ;
V_81 -> V_92 -> V_28 . V_80 = F_34 ( V_81 -> V_80 ) ;
F_58 ( V_23 , V_81 ) ;
V_23 -> V_98 ++ ;
F_18 ( & V_23 -> V_30 , F_17 ( V_81 -> V_92 ) ) ;
F_39 ( & V_23 -> V_62 ) ;
V_6 = F_72 ( & V_81 -> V_99 ) ;
F_37 ( & V_23 -> V_62 ) ;
F_73 ( & V_81 -> V_85 , & V_23 -> V_84 ) ;
V_23 -> V_98 -- ;
if ( ! V_6 )
V_6 = V_81 -> V_100 ;
return V_6 ;
}
static int F_74 ( struct V_22 * V_23 ,
struct V_79 * V_81 )
{
int V_6 ;
F_37 ( & V_23 -> V_62 ) ;
V_6 = F_71 ( V_23 , 0 , V_81 ) ;
F_39 ( & V_23 -> V_62 ) ;
return V_6 ;
}
static void F_75 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_79 * V_81 ;
struct V_101 * V_91 = V_50 -> V_26 . V_44 ;
T_3 V_80 = F_70 ( V_50 -> V_28 . V_80 ) ;
if ( V_50 -> V_26 . V_27 != sizeof( * V_91 ) )
goto V_14;
F_4 ( L_26 , V_50 , V_80 ) ;
F_37 ( & V_23 -> V_62 ) ;
V_81 = F_56 ( V_23 , V_80 ) ;
if ( V_81 ) {
* (struct V_102 * ) V_81 -> V_103 = V_91 -> V_104 ;
V_81 -> V_100 = 0 ;
F_67 ( V_81 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_81 ) {
F_76 ( & V_81 -> V_99 ) ;
F_65 ( V_81 ) ;
}
return;
V_14:
F_40 ( L_27 , V_80 ) ;
F_41 ( V_50 ) ;
}
int F_77 ( struct V_22 * V_23 , struct V_102 * V_103 )
{
struct V_79 * V_81 ;
struct V_105 * V_60 ;
int V_6 ;
V_81 = F_78 ( sizeof( * V_81 ) , V_17 ) ;
if ( ! V_81 )
return - V_18 ;
F_79 ( & V_81 -> V_90 ) ;
V_81 -> V_103 = V_103 ;
V_81 -> V_106 = sizeof( * V_103 ) ;
F_80 ( & V_81 -> V_99 ) ;
V_6 = - V_18 ;
V_81 -> V_92 = F_81 ( V_107 , sizeof( * V_60 ) , V_17 ,
true ) ;
if ( ! V_81 -> V_92 )
goto V_77;
V_81 -> V_91 = F_81 ( V_108 , 1024 , V_17 ,
true ) ;
if ( ! V_81 -> V_91 )
goto V_77;
V_60 = V_81 -> V_92 -> V_26 . V_44 ;
V_60 -> V_109 . V_110 = 0 ;
V_60 -> V_109 . V_111 = F_82 ( - 1 ) ;
V_60 -> V_109 . V_112 = 0 ;
V_60 -> V_9 = V_23 -> V_38 -> V_9 ;
V_6 = F_74 ( V_23 , V_81 ) ;
V_77:
F_66 ( & V_81 -> V_90 , F_62 ) ;
return V_6 ;
}
static void F_83 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_79 * V_81 ;
T_3 V_80 = F_70 ( V_50 -> V_28 . V_80 ) ;
void * V_2 = V_50 -> V_26 . V_44 ;
void * V_3 = V_2 + V_50 -> V_45 ;
T_3 V_113 ;
F_4 ( L_28 , V_114 , V_50 , V_80 ) ;
F_3 ( & V_2 , V_3 , 2 * sizeof( T_3 ) , V_14 ) ;
V_113 = F_84 ( & V_2 ) ;
if ( V_80 != 0 && V_80 != V_113 )
goto V_14;
F_37 ( & V_23 -> V_62 ) ;
V_81 = F_56 ( V_23 , V_113 ) ;
if ( V_81 ) {
* ( T_3 * ) V_81 -> V_103 = F_84 ( & V_2 ) ;
V_81 -> V_100 = 0 ;
F_67 ( V_81 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_81 ) {
F_76 ( & V_81 -> V_99 ) ;
F_65 ( V_81 ) ;
}
return;
V_14:
F_40 ( L_29 ) ;
F_41 ( V_50 ) ;
}
int F_85 ( struct V_22 * V_23 , const char * V_115 ,
T_3 * V_116 )
{
struct V_79 * V_81 ;
void * V_2 , * V_3 ;
T_3 V_80 ;
int V_6 ;
V_81 = F_78 ( sizeof( * V_81 ) , V_17 ) ;
if ( ! V_81 )
return - V_18 ;
F_79 ( & V_81 -> V_90 ) ;
V_81 -> V_103 = V_116 ;
V_81 -> V_106 = sizeof( * V_116 ) ;
F_80 ( & V_81 -> V_99 ) ;
V_81 -> V_92 = F_81 ( V_117 ,
sizeof( T_3 ) + sizeof( T_1 ) + strlen ( V_115 ) ,
V_17 , true ) ;
if ( ! V_81 -> V_92 ) {
V_6 = - V_18 ;
goto V_77;
}
V_81 -> V_91 = F_81 ( V_118 , 1024 ,
V_17 , true ) ;
if ( ! V_81 -> V_91 ) {
V_6 = - V_18 ;
goto V_77;
}
V_2 = V_81 -> V_92 -> V_26 . V_44 ;
V_3 = V_2 + V_81 -> V_92 -> V_45 ;
F_37 ( & V_23 -> V_62 ) ;
V_80 = ++ V_23 -> V_97 ;
F_86 ( & V_2 , V_80 ) ;
F_33 ( & V_2 , V_3 , V_115 , strlen ( V_115 ) ) ;
V_6 = F_71 ( V_23 , V_80 , V_81 ) ;
F_39 ( & V_23 -> V_62 ) ;
V_77:
F_66 ( & V_81 -> V_90 , F_62 ) ;
return V_6 ;
}
static int F_87 ( const char * V_119 , T_4 V_120 ,
char * V_121 , T_4 V_122 )
{
T_1 V_106 ;
if ( V_120 != sizeof( T_1 ) + V_122 )
return - V_7 ;
V_106 = F_36 ( * ( T_1 * ) V_119 ) ;
if ( V_106 != V_122 )
return - V_7 ;
memcpy ( V_121 , V_119 + sizeof( T_1 ) , V_122 ) ;
return 0 ;
}
static void F_88 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_79 * V_81 ;
struct V_123 * V_91 = V_50 -> V_26 . V_44 ;
T_3 V_80 = F_70 ( V_50 -> V_28 . V_80 ) ;
if ( V_50 -> V_26 . V_27 < sizeof( * V_91 ) )
goto V_14;
F_4 ( L_30 , V_50 , V_80 ) ;
F_37 ( & V_23 -> V_62 ) ;
V_81 = F_56 ( V_23 , V_80 ) ;
if ( V_81 ) {
if ( V_81 -> V_106 &&
F_87 ( V_50 -> V_26 . V_44 + sizeof( * V_91 ) ,
V_50 -> V_26 . V_27 - sizeof( * V_91 ) ,
V_81 -> V_103 , V_81 -> V_106 ) < 0 ) {
F_39 ( & V_23 -> V_62 ) ;
goto V_14;
}
V_81 -> V_100 = F_36 ( V_91 -> V_124 ) ;
F_67 ( V_81 ) ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_81 ) {
F_89 ( & V_81 -> V_99 ) ;
F_65 ( V_81 ) ;
}
return;
V_14:
F_40 ( L_27 , V_80 ) ;
F_41 ( V_50 ) ;
}
static int F_90 ( struct V_22 * V_23 , T_1 V_125 ,
T_1 V_126 , T_3 V_127 ,
char * V_103 , int V_13 )
{
struct V_79 * V_81 ;
struct V_128 * V_60 ;
int V_6 ;
V_81 = F_78 ( sizeof( * V_81 ) , V_17 ) ;
if ( ! V_81 )
return - V_18 ;
F_79 ( & V_81 -> V_90 ) ;
V_81 -> V_103 = V_103 ;
V_81 -> V_106 = V_13 ;
F_80 ( & V_81 -> V_99 ) ;
V_6 = - V_18 ;
V_81 -> V_92 = F_81 ( V_129 , sizeof( * V_60 ) , V_17 ,
true ) ;
if ( ! V_81 -> V_92 )
goto V_77;
V_81 -> V_91 = F_81 ( V_130 , 1024 , V_17 ,
true ) ;
if ( ! V_81 -> V_91 )
goto V_77;
V_81 -> V_92 -> V_28 . V_12 = F_82 ( 2 ) ;
V_60 = V_81 -> V_92 -> V_26 . V_44 ;
V_60 -> V_109 . V_110 = 0 ;
V_60 -> V_109 . V_111 = F_82 ( - 1 ) ;
V_60 -> V_109 . V_112 = 0 ;
V_60 -> V_9 = V_23 -> V_38 -> V_9 ;
V_60 -> V_126 = F_15 ( V_126 ) ;
V_60 -> V_125 = F_15 ( V_125 ) ;
V_60 -> V_131 = 0 ;
V_60 -> V_127 = F_34 ( V_127 ) ;
V_60 -> V_132 = 0 ;
V_6 = F_74 ( V_23 , V_81 ) ;
V_77:
F_66 ( & V_81 -> V_90 , F_62 ) ;
return V_6 ;
}
int F_91 ( struct V_22 * V_23 ,
T_1 V_126 , T_3 * V_127 )
{
return F_90 ( V_23 , V_133 ,
V_126 , 0 , ( char * ) V_127 , sizeof( * V_127 ) ) ;
}
int F_92 ( struct V_22 * V_23 ,
T_1 V_126 , T_3 V_127 )
{
return F_90 ( V_23 , V_133 ,
V_126 , V_127 , NULL , 0 ) ;
}
static void F_93 ( struct V_22 * V_23 )
{
struct V_79 * V_81 ;
struct V_82 * V_2 ;
for ( V_2 = F_94 ( & V_23 -> V_84 ) ; V_2 ; V_2 = F_95 ( V_2 ) ) {
V_81 = F_57 ( V_2 , struct V_79 , V_85 ) ;
F_16 ( V_81 -> V_92 ) ;
F_20 ( V_81 -> V_91 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_81 -> V_92 ) ) ;
}
}
static void V_48 ( struct V_134 * V_135 )
{
struct V_22 * V_23 =
F_63 ( V_135 , struct V_22 , V_48 . V_135 ) ;
F_4 ( L_31 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( V_23 -> V_63 ) {
F_19 ( V_23 ) ;
F_23 ( V_23 ) ;
} else {
F_96 ( & V_23 -> V_30 ) ;
F_97 ( V_23 ) ;
if ( F_98 ( V_23 -> V_35 ) )
F_31 ( V_23 ) ;
}
F_29 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
}
static int F_99 ( struct V_22 * V_23 )
{
struct V_136 * V_137 = V_23 -> V_69 -> V_138 ;
struct V_21 * V_139 = V_137 -> V_139 ;
int V_11 = V_137 -> V_11 ;
int V_5 ;
V_23 -> V_38 = F_78 ( sizeof( * V_23 -> V_38 ) +
V_11 * sizeof( V_23 -> V_38 -> V_15 [ 0 ] ) ,
V_140 ) ;
if ( ! V_23 -> V_38 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 = V_139 [ V_5 ] ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 . V_141 = 0 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_142 . type =
V_43 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_142 . V_52 = F_34 ( V_5 ) ;
}
V_23 -> V_38 -> V_11 = V_11 ;
return 0 ;
}
int F_100 ( struct V_22 * V_23 , struct V_73 * V_143 )
{
int V_6 = 0 ;
F_4 ( L_32 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_69 = V_143 ;
V_23 -> V_38 = NULL ;
F_101 ( & V_23 -> V_62 ) ;
V_6 = F_99 ( V_23 ) ;
if ( V_6 )
goto V_77;
V_23 -> V_35 = F_102 ( V_143 -> V_138 -> V_142 ,
V_143 -> V_138 -> V_144 ) ;
if ( F_50 ( V_23 -> V_35 ) ) {
V_6 = F_51 ( V_23 -> V_35 ) ;
goto V_145;
}
V_23 -> V_35 -> V_146 =
V_147 | V_43 |
V_148 | V_149 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_81 ( V_150 ,
sizeof( struct V_59 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_34 )
goto V_151;
V_23 -> V_33 = F_81 ( V_152 , 96 , V_17 ,
true ) ;
if ( ! V_23 -> V_33 )
goto V_153;
V_23 -> V_32 = F_81 ( V_154 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_32 )
goto V_155;
V_23 -> V_25 = F_81 ( V_156 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_157;
F_103 ( & V_23 -> V_30 , V_23 , & V_158 ,
& V_23 -> V_69 -> V_159 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_63 = true ;
V_23 -> V_40 = V_41 ;
V_23 -> V_39 = 0 ;
F_104 ( & V_23 -> V_48 , V_48 ) ;
V_23 -> V_84 = V_160 ;
V_23 -> V_98 = 0 ;
V_23 -> V_97 = 0 ;
V_23 -> V_57 = 0 ;
V_23 -> V_54 = 0 ;
V_23 -> V_42 = 1 ;
return 0 ;
V_157:
F_64 ( V_23 -> V_32 ) ;
V_155:
F_64 ( V_23 -> V_33 ) ;
V_153:
F_64 ( V_23 -> V_34 ) ;
V_151:
F_105 ( V_23 -> V_35 ) ;
V_145:
F_12 ( V_23 -> V_38 ) ;
V_77:
return V_6 ;
}
void F_106 ( struct V_22 * V_23 )
{
F_4 ( L_33 ) ;
F_107 ( & V_23 -> V_48 ) ;
F_37 ( & V_23 -> V_62 ) ;
F_19 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
F_108 () ;
F_105 ( V_23 -> V_35 ) ;
F_64 ( V_23 -> V_25 ) ;
F_64 ( V_23 -> V_32 ) ;
F_64 ( V_23 -> V_33 ) ;
F_64 ( V_23 -> V_34 ) ;
F_12 ( V_23 -> V_38 ) ;
}
static void F_109 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
int V_37 ;
int V_161 = 0 ;
int V_75 , V_76 = 0 ;
F_37 ( & V_23 -> V_62 ) ;
V_75 = F_48 ( V_23 ) ;
V_161 = F_98 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_37 = F_110 ( V_23 -> V_35 , V_50 -> V_26 . V_44 ,
V_50 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 < 0 ) {
V_23 -> V_69 -> V_162 = V_37 ;
F_55 ( & V_23 -> V_69 -> V_70 ) ;
} else if ( V_37 > 0 ) {
F_14 ( V_23 , V_37 ) ;
} else if ( ! V_161 && F_98 ( V_23 -> V_35 ) ) {
F_4 ( L_34 ) ;
V_23 -> V_69 -> V_159 . V_163 . V_142 . type = V_164 ;
V_23 -> V_69 -> V_159 . V_163 . V_142 . V_52 =
F_34 ( V_23 -> V_35 -> V_72 ) ;
F_31 ( V_23 ) ;
F_93 ( V_23 ) ;
}
if ( ! V_75 && F_48 ( V_23 ) ) {
F_38 ( L_23 ,
F_53 ( V_23 -> V_69 ) ,
& V_23 -> V_69 -> V_9 ) ;
V_76 = 1 ;
}
F_39 ( & V_23 -> V_62 ) ;
if ( V_76 ) {
F_54 ( V_23 -> V_69 ) ;
}
}
static int F_97 ( struct V_22 * V_23 )
{
int V_37 ;
if ( V_23 -> V_24 )
return 0 ;
V_37 = F_111 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 <= 0 )
return V_37 ;
F_14 ( V_23 , V_37 ) ;
return 0 ;
}
int F_112 ( struct V_22 * V_23 )
{
int V_37 ;
F_37 ( & V_23 -> V_62 ) ;
V_37 = F_97 ( V_23 ) ;
F_39 ( & V_23 -> V_62 ) ;
return V_37 ;
}
static void F_113 ( struct V_93 * V_30 , struct V_49 * V_50 )
{
struct V_22 * V_23 = V_30 -> V_96 ;
int type = F_114 ( V_50 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_154 :
F_109 ( V_23 , V_50 ) ;
break;
case V_150 :
F_35 ( V_23 , V_50 ) ;
break;
case V_108 :
F_75 ( V_23 , V_50 ) ;
break;
case V_118 :
F_83 ( V_23 , V_50 ) ;
break;
case V_130 :
F_88 ( V_23 , V_50 ) ;
break;
case V_165 :
F_49 ( V_23 , V_50 ) ;
break;
case V_166 :
F_115 ( & V_23 -> V_69 -> V_167 , V_50 ) ;
break;
default:
if ( V_23 -> V_69 -> V_168 &&
V_23 -> V_69 -> V_168 ( V_23 -> V_69 , V_50 ) == 0 )
break;
F_40 ( L_35 , type ,
F_116 ( type ) ) ;
}
F_64 ( V_50 ) ;
}
static struct V_49 * F_117 ( struct V_93 * V_30 ,
struct V_94 * V_28 ,
int * V_95 )
{
struct V_22 * V_23 = V_30 -> V_96 ;
int type = F_114 ( V_28 -> type ) ;
int V_29 = F_36 ( V_28 -> V_29 ) ;
struct V_49 * V_4 = NULL ;
* V_95 = 0 ;
switch ( type ) {
case V_150 :
V_4 = F_17 ( V_23 -> V_34 ) ;
break;
case V_130 :
case V_108 :
return F_69 ( V_30 , V_28 , V_95 ) ;
case V_154 :
V_4 = F_17 ( V_23 -> V_32 ) ;
break;
case V_118 :
if ( F_70 ( V_28 -> V_80 ) != 0 )
return F_69 ( V_30 , V_28 , V_95 ) ;
case V_165 :
case V_169 :
case V_166 :
V_4 = F_81 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_38 ( L_36 , type ) ;
* V_95 = 1 ;
} else if ( V_29 > V_4 -> V_45 ) {
F_118 ( L_37 ,
V_29 , V_4 -> V_45 ,
( unsigned int ) V_30 -> V_170 . type ,
F_70 ( V_30 -> V_170 . V_52 ) ) ;
F_64 ( V_4 ) ;
V_4 = F_81 ( type , V_29 , V_17 , false ) ;
}
return V_4 ;
}
static void F_119 ( struct V_93 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_96 ;
if ( ! V_23 )
return;
F_4 ( L_38 ) ;
F_37 ( & V_23 -> V_62 ) ;
if ( ! V_30 -> V_96 )
goto V_77;
if ( ! V_23 -> V_63 )
F_38 ( L_39
L_40 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_64 . V_20 ) ) ;
F_19 ( V_23 ) ;
if ( ! V_23 -> V_63 ) {
V_23 -> V_63 = true ;
F_23 ( V_23 ) ;
} else {
F_29 ( V_23 ) ;
}
V_77:
F_39 ( & V_23 -> V_62 ) ;
}
static struct V_93 * F_120 ( struct V_93 * V_30 )
{
return V_30 ;
}
static void F_121 ( struct V_93 * V_30 )
{
}
