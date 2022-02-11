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
F_26 ( & V_23 -> V_30 ) ;
V_37 = F_27 ( V_23 -> V_35 ,
V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
F_14 ( V_23 , V_37 ) ;
} else {
F_4 ( L_8 , V_23 -> V_31 ) ;
}
return 0 ;
}
static bool F_28 ( struct V_22 * V_23 )
{
return F_29 ( V_41 , V_23 -> V_40 ) ;
}
static void F_30 ( struct V_22 * V_23 )
{
struct V_46 * V_47 = V_23 -> V_48 -> V_49 ;
unsigned long V_50 ;
if ( V_23 -> V_31 < 0 || F_28 ( V_23 ) ) {
V_50 = 10 * V_51 ;
} else {
V_50 = 20 * V_51 ;
if ( V_47 -> V_52 > 0 )
V_50 = F_31 ( V_50 , V_47 -> V_52 / 3 ) ;
}
F_4 ( L_9 , V_50 ) ;
F_32 ( & V_23 -> V_53 ,
F_33 ( V_50 ) ) ;
}
static void F_34 ( struct V_22 * V_23 )
{
F_4 ( L_10 ,
( unsigned int ) V_23 -> V_39 , F_28 ( V_23 ) ,
V_23 -> V_42 ) ;
if ( ( F_28 ( V_23 ) && ! V_23 -> V_39 ) ||
V_23 -> V_42 == 1 ) {
struct V_54 * V_55 = V_23 -> V_33 ;
struct V_56 * V_5 ;
void * V_2 , * V_3 ;
int V_57 ;
V_2 = V_55 -> V_26 . V_44 ;
V_3 = V_2 + V_55 -> V_45 ;
V_57 = 1 + ! ! V_23 -> V_42 + ! ! V_23 -> V_58 ;
F_35 ( & V_2 , V_57 ) ;
if ( V_23 -> V_42 ) {
F_4 ( L_11 ,
( unsigned int ) V_23 -> V_59 ) ;
F_36 ( & V_2 , V_3 , L_12 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_60 = F_37 ( V_23 -> V_59 ) ;
V_5 -> V_61 = 1 ;
V_2 += sizeof( * V_5 ) ;
V_23 -> V_42 = 2 ;
}
if ( V_23 -> V_58 ) {
F_4 ( L_13 ,
( unsigned int ) V_23 -> V_62 ) ;
F_36 ( & V_2 , V_3 , L_14 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_60 = F_37 ( V_23 -> V_62 ) ;
V_5 -> V_61 = 0 ;
V_2 += sizeof( * V_5 ) ;
}
F_36 ( & V_2 , V_3 , L_15 , 6 ) ;
V_5 = V_2 ;
V_5 -> V_60 = 0 ;
V_5 -> V_61 = 0 ;
V_2 += sizeof( * V_5 ) ;
V_55 -> V_26 . V_27 = V_2 - V_55 -> V_26 . V_44 ;
V_55 -> V_28 . V_29 = F_15 ( V_55 -> V_26 . V_27 ) ;
F_16 ( V_55 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_55 ) ) ;
V_23 -> V_39 = V_41 | 1 ;
}
}
static void F_38 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
unsigned int V_63 ;
struct V_64 * V_65 = V_55 -> V_26 . V_44 ;
if ( V_55 -> V_26 . V_27 < sizeof( * V_65 ) )
goto V_14;
V_63 = F_39 ( V_65 -> V_66 ) ;
F_40 ( & V_23 -> V_67 ) ;
if ( V_23 -> V_68 ) {
F_41 ( L_16 ,
V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_69 . V_20 ) ) ;
V_23 -> V_68 = false ;
}
F_4 ( L_17 , V_63 ) ;
V_23 -> V_40 = V_23 -> V_39 + ( V_63 >> 1 ) * V_51 - 1 ;
V_23 -> V_39 = 0 ;
F_42 ( & V_23 -> V_67 ) ;
return;
V_14:
F_43 ( L_18 ) ;
F_44 ( V_55 ) ;
}
int F_45 ( struct V_22 * V_23 , T_1 V_70 )
{
F_40 ( & V_23 -> V_67 ) ;
V_23 -> V_62 = V_70 ;
F_42 ( & V_23 -> V_67 ) ;
return 0 ;
}
int F_46 ( struct V_22 * V_23 , T_1 V_70 )
{
F_40 ( & V_23 -> V_67 ) ;
V_23 -> V_59 = V_70 ;
V_23 -> V_42 = 0 ;
F_42 ( & V_23 -> V_67 ) ;
return 0 ;
}
void F_47 ( struct V_22 * V_23 )
{
F_4 ( L_19 , V_23 -> V_59 ) ;
F_40 ( & V_23 -> V_67 ) ;
if ( ! V_23 -> V_42 )
V_23 -> V_42 = 1 ;
if ( V_23 -> V_42 < 2 )
F_34 ( V_23 ) ;
F_42 ( & V_23 -> V_67 ) ;
}
int F_48 ( struct V_22 * V_23 , T_1 V_10 ,
unsigned long V_71 )
{
unsigned long V_72 = V_41 ;
long V_37 ;
F_40 ( & V_23 -> V_67 ) ;
while ( V_23 -> V_59 < V_10 ) {
F_42 ( & V_23 -> V_67 ) ;
if ( V_71 && F_29 ( V_41 , V_72 + V_71 ) )
return - V_73 ;
V_37 = F_49 ( V_23 -> V_48 -> V_74 ,
V_23 -> V_59 >= V_10 ,
F_50 ( V_71 ) ) ;
if ( V_37 < 0 )
return V_37 ;
F_40 ( & V_23 -> V_67 ) ;
}
F_42 ( & V_23 -> V_67 ) ;
return 0 ;
}
int F_51 ( struct V_22 * V_23 )
{
F_40 ( & V_23 -> V_67 ) ;
F_23 ( V_23 ) ;
F_30 ( V_23 ) ;
F_42 ( & V_23 -> V_67 ) ;
return 0 ;
}
static bool F_52 ( struct V_22 * V_23 )
{
F_4 ( L_20 ,
( int ) V_23 -> V_48 -> V_75 , V_23 -> V_35 -> V_76 ) ;
return V_23 -> V_48 -> V_75 && V_23 -> V_35 -> V_76 > 0 ;
}
static void F_53 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
struct V_77 * V_48 = V_23 -> V_48 ;
struct V_1 * V_38 = NULL , * V_78 = V_23 -> V_38 ;
void * V_2 , * V_3 ;
int V_79 , V_80 = 0 ;
F_40 ( & V_23 -> V_67 ) ;
V_79 = F_52 ( V_23 ) ;
F_4 ( L_21 ) ;
V_2 = V_55 -> V_26 . V_44 ;
V_3 = V_2 + V_55 -> V_26 . V_27 ;
V_38 = F_1 ( V_2 , V_3 ) ;
if ( F_54 ( V_38 ) ) {
F_43 ( L_22 ,
( int ) F_55 ( V_38 ) ) ;
goto V_81;
}
if ( F_56 ( V_23 -> V_48 , & V_38 -> V_9 ) < 0 ) {
F_12 ( V_38 ) ;
goto V_81;
}
V_48 -> V_23 . V_38 = V_38 ;
F_12 ( V_78 ) ;
if ( ! V_48 -> V_75 ) {
V_48 -> V_75 = true ;
if ( ! V_79 && F_52 ( V_23 ) ) {
F_41 ( L_23 ,
F_57 ( V_23 -> V_48 ) ,
& V_23 -> V_48 -> V_9 ) ;
V_80 = 1 ;
}
F_42 ( & V_23 -> V_67 ) ;
if ( V_80 ) {
F_58 ( V_23 -> V_48 ) ;
}
goto V_82;
}
V_81:
F_42 ( & V_23 -> V_67 ) ;
V_82:
F_59 ( & V_48 -> V_74 ) ;
}
static struct V_83 * F_60 (
struct V_22 * V_23 , T_3 V_84 )
{
struct V_83 * V_85 ;
struct V_86 * V_87 = V_23 -> V_88 . V_86 ;
while ( V_87 ) {
V_85 = F_61 ( V_87 , struct V_83 , V_89 ) ;
if ( V_84 < V_85 -> V_84 )
V_87 = V_87 -> V_90 ;
else if ( V_84 > V_85 -> V_84 )
V_87 = V_87 -> V_91 ;
else
return V_85 ;
}
return NULL ;
}
static void F_62 ( struct V_22 * V_23 ,
struct V_83 * V_92 )
{
struct V_86 * * V_2 = & V_23 -> V_88 . V_86 ;
struct V_86 * V_93 = NULL ;
struct V_83 * V_85 = NULL ;
while ( * V_2 ) {
V_93 = * V_2 ;
V_85 = F_61 ( V_93 , struct V_83 , V_89 ) ;
if ( V_92 -> V_84 < V_85 -> V_84 )
V_2 = & ( * V_2 ) -> V_90 ;
else if ( V_92 -> V_84 > V_85 -> V_84 )
V_2 = & ( * V_2 ) -> V_91 ;
else
F_63 () ;
}
F_64 ( & V_92 -> V_89 , V_93 , V_2 ) ;
F_65 ( & V_92 -> V_89 , & V_23 -> V_88 ) ;
}
static void F_66 ( struct V_94 * V_94 )
{
struct V_83 * V_85 =
F_67 ( V_94 , struct V_83 , V_94 ) ;
if ( V_85 -> V_95 )
F_68 ( V_85 -> V_95 ) ;
if ( V_85 -> V_96 )
F_68 ( V_85 -> V_96 ) ;
F_12 ( V_85 ) ;
}
static void F_69 ( struct V_83 * V_85 )
{
F_70 ( & V_85 -> V_94 , F_66 ) ;
}
static void F_71 ( struct V_83 * V_85 )
{
F_72 ( & V_85 -> V_94 ) ;
}
static struct V_54 * F_73 ( struct V_97 * V_30 ,
struct V_98 * V_28 ,
int * V_99 )
{
struct V_22 * V_23 = V_30 -> V_100 ;
struct V_83 * V_85 ;
T_3 V_84 = F_74 ( V_28 -> V_84 ) ;
struct V_54 * V_4 ;
F_40 ( & V_23 -> V_67 ) ;
V_85 = F_60 ( V_23 , V_84 ) ;
if ( ! V_85 ) {
F_4 ( L_24 , V_84 ) ;
* V_99 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_25 , V_84 , V_85 -> V_95 ) ;
* V_99 = 0 ;
V_4 = F_17 ( V_85 -> V_95 ) ;
}
F_42 ( & V_23 -> V_67 ) ;
return V_4 ;
}
static int F_75 ( struct V_22 * V_23 , T_3 V_84 ,
struct V_83 * V_85 )
{
int V_6 ;
V_85 -> V_84 = V_84 != 0 ? V_84 : ++ V_23 -> V_101 ;
V_85 -> V_96 -> V_28 . V_84 = F_37 ( V_85 -> V_84 ) ;
F_62 ( V_23 , V_85 ) ;
V_23 -> V_102 ++ ;
F_18 ( & V_23 -> V_30 , F_17 ( V_85 -> V_96 ) ) ;
F_42 ( & V_23 -> V_67 ) ;
V_6 = F_76 ( & V_85 -> V_103 ) ;
F_40 ( & V_23 -> V_67 ) ;
F_77 ( & V_85 -> V_89 , & V_23 -> V_88 ) ;
V_23 -> V_102 -- ;
if ( ! V_6 )
V_6 = V_85 -> V_104 ;
return V_6 ;
}
static int F_78 ( struct V_22 * V_23 ,
struct V_83 * V_85 )
{
int V_6 ;
F_40 ( & V_23 -> V_67 ) ;
V_6 = F_75 ( V_23 , 0 , V_85 ) ;
F_42 ( & V_23 -> V_67 ) ;
return V_6 ;
}
static void F_79 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
struct V_83 * V_85 ;
struct V_105 * V_95 = V_55 -> V_26 . V_44 ;
T_3 V_84 = F_74 ( V_55 -> V_28 . V_84 ) ;
if ( V_55 -> V_26 . V_27 != sizeof( * V_95 ) )
goto V_14;
F_4 ( L_26 , V_55 , V_84 ) ;
F_40 ( & V_23 -> V_67 ) ;
V_85 = F_60 ( V_23 , V_84 ) ;
if ( V_85 ) {
* (struct V_106 * ) V_85 -> V_107 = V_95 -> V_108 ;
V_85 -> V_104 = 0 ;
F_71 ( V_85 ) ;
}
F_42 ( & V_23 -> V_67 ) ;
if ( V_85 ) {
F_80 ( & V_85 -> V_103 ) ;
F_69 ( V_85 ) ;
}
return;
V_14:
F_43 ( L_27 , V_84 ) ;
F_44 ( V_55 ) ;
}
int F_81 ( struct V_22 * V_23 , struct V_106 * V_107 )
{
struct V_83 * V_85 ;
struct V_109 * V_65 ;
int V_6 ;
V_85 = F_82 ( sizeof( * V_85 ) , V_17 ) ;
if ( ! V_85 )
return - V_18 ;
F_83 ( & V_85 -> V_94 ) ;
V_85 -> V_107 = V_107 ;
F_84 ( & V_85 -> V_103 ) ;
V_6 = - V_18 ;
V_85 -> V_96 = F_85 ( V_110 , sizeof( * V_65 ) , V_17 ,
true ) ;
if ( ! V_85 -> V_96 )
goto V_81;
V_85 -> V_95 = F_85 ( V_111 , 1024 , V_17 ,
true ) ;
if ( ! V_85 -> V_95 )
goto V_81;
V_65 = V_85 -> V_96 -> V_26 . V_44 ;
V_65 -> V_112 . V_113 = 0 ;
V_65 -> V_112 . V_114 = F_86 ( - 1 ) ;
V_65 -> V_112 . V_115 = 0 ;
V_65 -> V_9 = V_23 -> V_38 -> V_9 ;
V_6 = F_78 ( V_23 , V_85 ) ;
V_81:
F_69 ( V_85 ) ;
return V_6 ;
}
static void F_87 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
struct V_83 * V_85 ;
T_3 V_84 = F_74 ( V_55 -> V_28 . V_84 ) ;
void * V_2 = V_55 -> V_26 . V_44 ;
void * V_3 = V_2 + V_55 -> V_45 ;
T_3 V_116 ;
F_4 ( L_28 , V_117 , V_55 , V_84 ) ;
F_3 ( & V_2 , V_3 , 2 * sizeof( T_3 ) , V_14 ) ;
V_116 = F_88 ( & V_2 ) ;
if ( V_84 != 0 && V_84 != V_116 )
goto V_14;
F_40 ( & V_23 -> V_67 ) ;
V_85 = F_60 ( V_23 , V_116 ) ;
if ( V_85 ) {
* ( T_3 * ) V_85 -> V_107 = F_88 ( & V_2 ) ;
V_85 -> V_104 = 0 ;
F_71 ( V_85 ) ;
}
F_42 ( & V_23 -> V_67 ) ;
if ( V_85 ) {
F_80 ( & V_85 -> V_103 ) ;
F_69 ( V_85 ) ;
}
return;
V_14:
F_43 ( L_29 , V_84 ) ;
F_44 ( V_55 ) ;
}
int F_89 ( struct V_22 * V_23 , const char * V_118 ,
T_3 * V_119 )
{
struct V_83 * V_85 ;
void * V_2 , * V_3 ;
T_3 V_84 ;
int V_6 ;
V_85 = F_82 ( sizeof( * V_85 ) , V_17 ) ;
if ( ! V_85 )
return - V_18 ;
F_83 ( & V_85 -> V_94 ) ;
V_85 -> V_107 = V_119 ;
F_84 ( & V_85 -> V_103 ) ;
V_85 -> V_96 = F_85 ( V_120 ,
sizeof( T_3 ) + sizeof( T_1 ) + strlen ( V_118 ) ,
V_17 , true ) ;
if ( ! V_85 -> V_96 ) {
V_6 = - V_18 ;
goto V_81;
}
V_85 -> V_95 = F_85 ( V_121 , 1024 ,
V_17 , true ) ;
if ( ! V_85 -> V_95 ) {
V_6 = - V_18 ;
goto V_81;
}
V_2 = V_85 -> V_96 -> V_26 . V_44 ;
V_3 = V_2 + V_85 -> V_96 -> V_45 ;
F_40 ( & V_23 -> V_67 ) ;
V_84 = ++ V_23 -> V_101 ;
F_90 ( & V_2 , V_84 ) ;
F_36 ( & V_2 , V_3 , V_118 , strlen ( V_118 ) ) ;
V_6 = F_75 ( V_23 , V_84 , V_85 ) ;
F_42 ( & V_23 -> V_67 ) ;
V_81:
F_69 ( V_85 ) ;
return V_6 ;
}
static void F_91 ( struct V_22 * V_23 )
{
struct V_83 * V_85 ;
struct V_86 * V_2 ;
for ( V_2 = F_92 ( & V_23 -> V_88 ) ; V_2 ; V_2 = F_93 ( V_2 ) ) {
V_85 = F_61 ( V_2 , struct V_83 , V_89 ) ;
F_16 ( V_85 -> V_96 ) ;
F_20 ( V_85 -> V_95 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_85 -> V_96 ) ) ;
}
}
static void V_53 ( struct V_122 * V_123 )
{
struct V_22 * V_23 =
F_67 ( V_123 , struct V_22 , V_53 . V_123 ) ;
F_4 ( L_30 ) ;
F_40 ( & V_23 -> V_67 ) ;
if ( V_23 -> V_68 ) {
F_19 ( V_23 ) ;
F_23 ( V_23 ) ;
} else {
struct V_46 * V_47 = V_23 -> V_48 -> V_49 ;
int V_124 = F_94 ( V_23 -> V_35 ) ;
if ( F_95 ( & V_23 -> V_30 ,
V_47 -> V_52 ) ) {
F_4 ( L_31 ) ;
V_124 = 0 ;
F_19 ( V_23 ) ;
V_23 -> V_68 = true ;
F_23 ( V_23 ) ;
}
if ( ! V_23 -> V_68 ) {
F_26 ( & V_23 -> V_30 ) ;
F_96 ( V_23 ) ;
}
if ( V_124 )
F_34 ( V_23 ) ;
}
F_30 ( V_23 ) ;
F_42 ( & V_23 -> V_67 ) ;
}
static int F_97 ( struct V_22 * V_23 )
{
struct V_46 * V_47 = V_23 -> V_48 -> V_49 ;
struct V_21 * V_125 = V_47 -> V_125 ;
int V_11 = V_47 -> V_11 ;
int V_5 ;
V_23 -> V_38 = F_82 ( sizeof( * V_23 -> V_38 ) +
V_11 * sizeof( V_23 -> V_38 -> V_15 [ 0 ] ) ,
V_126 ) ;
if ( ! V_23 -> V_38 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 = V_125 [ V_5 ] ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_19 . V_127 = 0 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_128 . type =
V_43 ;
V_23 -> V_38 -> V_15 [ V_5 ] . V_128 . V_57 = F_37 ( V_5 ) ;
}
V_23 -> V_38 -> V_11 = V_11 ;
return 0 ;
}
int F_98 ( struct V_22 * V_23 , struct V_77 * V_129 )
{
int V_6 = 0 ;
F_4 ( L_32 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_48 = V_129 ;
V_23 -> V_38 = NULL ;
F_99 ( & V_23 -> V_67 ) ;
V_6 = F_97 ( V_23 ) ;
if ( V_6 )
goto V_81;
V_23 -> V_35 = F_100 ( V_129 -> V_49 -> V_128 ,
V_129 -> V_49 -> V_130 ) ;
if ( F_54 ( V_23 -> V_35 ) ) {
V_6 = F_55 ( V_23 -> V_35 ) ;
goto V_131;
}
V_23 -> V_35 -> V_132 =
V_133 | V_43 |
V_134 | V_135 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_85 ( V_136 ,
sizeof( struct V_64 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_34 )
goto V_137;
V_23 -> V_33 = F_85 ( V_138 , 96 , V_17 ,
true ) ;
if ( ! V_23 -> V_33 )
goto V_139;
V_23 -> V_32 = F_85 ( V_140 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_32 )
goto V_141;
V_23 -> V_25 = F_85 ( V_142 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_143;
F_101 ( & V_23 -> V_30 , V_23 , & V_144 ,
& V_23 -> V_48 -> V_145 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_68 = true ;
V_23 -> V_40 = V_41 ;
V_23 -> V_39 = 0 ;
F_102 ( & V_23 -> V_53 , V_53 ) ;
V_23 -> V_88 = V_146 ;
V_23 -> V_102 = 0 ;
V_23 -> V_101 = 0 ;
V_23 -> V_62 = 0 ;
V_23 -> V_59 = 0 ;
V_23 -> V_42 = 1 ;
return 0 ;
V_143:
F_68 ( V_23 -> V_32 ) ;
V_141:
F_68 ( V_23 -> V_33 ) ;
V_139:
F_68 ( V_23 -> V_34 ) ;
V_137:
F_103 ( V_23 -> V_35 ) ;
V_131:
F_12 ( V_23 -> V_38 ) ;
V_81:
return V_6 ;
}
void F_104 ( struct V_22 * V_23 )
{
F_4 ( L_33 ) ;
F_105 ( & V_23 -> V_53 ) ;
F_40 ( & V_23 -> V_67 ) ;
F_19 ( V_23 ) ;
F_42 ( & V_23 -> V_67 ) ;
F_106 () ;
F_103 ( V_23 -> V_35 ) ;
F_68 ( V_23 -> V_25 ) ;
F_68 ( V_23 -> V_32 ) ;
F_68 ( V_23 -> V_33 ) ;
F_68 ( V_23 -> V_34 ) ;
F_12 ( V_23 -> V_38 ) ;
}
static void F_107 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
int V_37 ;
int V_147 = 0 ;
int V_79 , V_80 = 0 ;
F_40 ( & V_23 -> V_67 ) ;
V_79 = F_52 ( V_23 ) ;
V_147 = F_94 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_37 = F_108 ( V_23 -> V_35 , V_55 -> V_26 . V_44 ,
V_55 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 < 0 ) {
V_23 -> V_48 -> V_148 = V_37 ;
F_59 ( & V_23 -> V_48 -> V_74 ) ;
} else if ( V_37 > 0 ) {
F_14 ( V_23 , V_37 ) ;
} else if ( ! V_147 && F_94 ( V_23 -> V_35 ) ) {
F_4 ( L_34 ) ;
V_23 -> V_48 -> V_145 . V_149 . V_128 . type = V_150 ;
V_23 -> V_48 -> V_145 . V_149 . V_128 . V_57 =
F_37 ( V_23 -> V_35 -> V_76 ) ;
F_34 ( V_23 ) ;
F_91 ( V_23 ) ;
}
if ( ! V_79 && F_52 ( V_23 ) ) {
F_41 ( L_23 ,
F_57 ( V_23 -> V_48 ) ,
& V_23 -> V_48 -> V_9 ) ;
V_80 = 1 ;
}
F_42 ( & V_23 -> V_67 ) ;
if ( V_80 ) {
F_58 ( V_23 -> V_48 ) ;
}
}
static int F_96 ( struct V_22 * V_23 )
{
int V_37 ;
if ( V_23 -> V_24 )
return 0 ;
V_37 = F_109 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_44 ,
V_23 -> V_25 -> V_45 ) ;
if ( V_37 <= 0 )
return V_37 ;
F_14 ( V_23 , V_37 ) ;
return 0 ;
}
int F_110 ( struct V_22 * V_23 )
{
int V_37 ;
F_40 ( & V_23 -> V_67 ) ;
V_37 = F_96 ( V_23 ) ;
F_42 ( & V_23 -> V_67 ) ;
return V_37 ;
}
static void F_111 ( struct V_97 * V_30 , struct V_54 * V_55 )
{
struct V_22 * V_23 = V_30 -> V_100 ;
int type = F_112 ( V_55 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_140 :
F_107 ( V_23 , V_55 ) ;
break;
case V_136 :
F_38 ( V_23 , V_55 ) ;
break;
case V_111 :
F_79 ( V_23 , V_55 ) ;
break;
case V_121 :
F_87 ( V_23 , V_55 ) ;
break;
case V_151 :
F_53 ( V_23 , V_55 ) ;
break;
case V_152 :
F_113 ( & V_23 -> V_48 -> V_153 , V_55 ) ;
break;
default:
if ( V_23 -> V_48 -> V_154 &&
V_23 -> V_48 -> V_154 ( V_23 -> V_48 , V_55 ) == 0 )
break;
F_43 ( L_35 , type ,
F_114 ( type ) ) ;
}
F_68 ( V_55 ) ;
}
static struct V_54 * F_115 ( struct V_97 * V_30 ,
struct V_98 * V_28 ,
int * V_99 )
{
struct V_22 * V_23 = V_30 -> V_100 ;
int type = F_112 ( V_28 -> type ) ;
int V_29 = F_39 ( V_28 -> V_29 ) ;
struct V_54 * V_4 = NULL ;
* V_99 = 0 ;
switch ( type ) {
case V_136 :
V_4 = F_17 ( V_23 -> V_34 ) ;
break;
case V_111 :
return F_73 ( V_30 , V_28 , V_99 ) ;
case V_140 :
V_4 = F_17 ( V_23 -> V_32 ) ;
break;
case V_121 :
if ( F_74 ( V_28 -> V_84 ) != 0 )
return F_73 ( V_30 , V_28 , V_99 ) ;
case V_151 :
case V_155 :
case V_152 :
V_4 = F_85 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_41 ( L_36 , type ) ;
* V_99 = 1 ;
} else if ( V_29 > V_4 -> V_45 ) {
F_116 ( L_37 ,
V_29 , V_4 -> V_45 ,
( unsigned int ) V_30 -> V_156 . type ,
F_74 ( V_30 -> V_156 . V_57 ) ) ;
F_68 ( V_4 ) ;
V_4 = F_85 ( type , V_29 , V_17 , false ) ;
}
return V_4 ;
}
static void F_117 ( struct V_97 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_100 ;
if ( ! V_23 )
return;
F_4 ( L_38 ) ;
F_40 ( & V_23 -> V_67 ) ;
if ( ! V_30 -> V_100 )
goto V_81;
if ( ! V_23 -> V_68 )
F_41 ( L_39
L_40 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_69 . V_20 ) ) ;
F_19 ( V_23 ) ;
if ( ! V_23 -> V_68 ) {
V_23 -> V_68 = true ;
F_23 ( V_23 ) ;
} else {
F_30 ( V_23 ) ;
}
V_81:
F_42 ( & V_23 -> V_67 ) ;
}
static struct V_97 * F_118 ( struct V_97 * V_30 )
{
return V_30 ;
}
static void F_119 ( struct V_97 * V_30 )
{
}
