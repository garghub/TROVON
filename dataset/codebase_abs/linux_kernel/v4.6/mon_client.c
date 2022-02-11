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
const char * V_65 = V_66 [ V_5 ] ;
if ( ! V_23 -> V_63 [ V_5 ] . V_64 )
continue;
F_4 ( L_11 , V_41 , V_65 ,
F_39 ( V_23 -> V_63 [ V_5 ] . V_67 . V_68 ) ,
V_23 -> V_63 [ V_5 ] . V_67 . V_69 ) ;
F_40 ( & V_2 , V_3 , V_65 , strlen ( V_65 ) ) ;
memcpy ( V_2 , & V_23 -> V_63 [ V_5 ] . V_67 , sizeof( V_23 -> V_63 [ V_5 ] . V_67 ) ) ;
V_2 += sizeof( V_23 -> V_63 [ V_5 ] . V_67 ) ;
}
F_24 ( V_2 != ( V_3 - 35 - ( F_37 ( V_23 -> V_63 ) - V_62 ) * 19 ) ) ;
V_61 -> V_26 . V_27 = V_2 - V_61 -> V_26 . V_52 ;
V_61 -> V_28 . V_29 = F_15 ( V_61 -> V_26 . V_27 ) ;
F_16 ( V_61 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_61 ) ) ;
}
static void F_41 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
unsigned int V_70 ;
struct V_71 * V_72 = V_61 -> V_26 . V_52 ;
if ( V_61 -> V_26 . V_27 < sizeof( * V_72 ) )
goto V_14;
V_70 = F_42 ( V_72 -> V_73 ) ;
F_43 ( & V_23 -> V_74 ) ;
if ( V_23 -> V_50 ) {
V_23 -> V_48 = V_23 -> V_50 +
( V_70 >> 1 ) * V_75 - 1 ;
F_4 ( L_12 , V_41 ,
V_23 -> V_50 , V_70 , V_23 -> V_48 ) ;
V_23 -> V_50 = 0 ;
} else {
F_4 ( L_13 , V_41 ,
V_23 -> V_50 , V_23 -> V_48 ) ;
}
F_44 ( & V_23 -> V_74 ) ;
return;
V_14:
F_45 ( L_14 ) ;
F_46 ( V_61 ) ;
}
static bool F_47 ( struct V_22 * V_23 , int V_76 ,
T_1 V_10 , bool V_77 )
{
T_3 V_68 = F_48 ( V_10 ) ;
T_4 V_69 = ! V_77 ? V_78 : 0 ;
F_4 ( L_15 , V_41 , V_66 [ V_76 ] ,
V_10 , V_77 ) ;
if ( V_23 -> V_63 [ V_76 ] . V_64 &&
V_23 -> V_63 [ V_76 ] . V_67 . V_68 == V_68 &&
V_23 -> V_63 [ V_76 ] . V_67 . V_69 == V_69 )
return false ;
V_23 -> V_63 [ V_76 ] . V_67 . V_68 = V_68 ;
V_23 -> V_63 [ V_76 ] . V_67 . V_69 = V_69 ;
V_23 -> V_63 [ V_76 ] . V_64 = true ;
return true ;
}
bool F_49 ( struct V_22 * V_23 , int V_76 , T_1 V_10 ,
bool V_77 )
{
bool V_79 ;
F_43 ( & V_23 -> V_74 ) ;
V_79 = F_47 ( V_23 , V_76 , V_10 , V_77 ) ;
F_44 ( & V_23 -> V_74 ) ;
return V_79 ;
}
static void F_50 ( struct V_22 * V_23 , int V_76 ,
T_1 V_10 )
{
F_4 ( L_16 , V_41 , V_66 [ V_76 ] , V_10 ) ;
if ( V_23 -> V_63 [ V_76 ] . V_64 ) {
if ( V_23 -> V_63 [ V_76 ] . V_67 . V_69 & V_78 )
V_23 -> V_63 [ V_76 ] . V_64 = false ;
else
V_23 -> V_63 [ V_76 ] . V_67 . V_68 = F_48 ( V_10 + 1 ) ;
}
V_23 -> V_63 [ V_76 ] . V_80 = V_10 ;
}
void F_51 ( struct V_22 * V_23 , int V_76 , T_1 V_10 )
{
F_43 ( & V_23 -> V_74 ) ;
F_50 ( V_23 , V_76 , V_10 ) ;
F_44 ( & V_23 -> V_74 ) ;
}
void F_52 ( struct V_22 * V_23 )
{
F_4 ( L_17 , V_41 , V_23 -> V_63 [ V_81 ] . V_80 ) ;
F_43 ( & V_23 -> V_74 ) ;
if ( F_47 ( V_23 , V_81 ,
V_23 -> V_63 [ V_81 ] . V_80 + 1 , false ) )
F_35 ( V_23 ) ;
F_44 ( & V_23 -> V_74 ) ;
}
int F_53 ( struct V_22 * V_23 , T_1 V_10 ,
unsigned long V_82 )
{
unsigned long V_83 = V_49 ;
long V_42 ;
F_43 ( & V_23 -> V_74 ) ;
while ( V_23 -> V_63 [ V_81 ] . V_80 < V_10 ) {
F_44 ( & V_23 -> V_74 ) ;
if ( V_82 && F_54 ( V_49 , V_83 + V_82 ) )
return - V_84 ;
V_42 = F_55 ( V_23 -> V_85 -> V_86 ,
V_23 -> V_63 [ V_81 ] . V_80 >= V_10 ,
F_56 ( V_82 ) ) ;
if ( V_42 < 0 )
return V_42 ;
F_43 ( & V_23 -> V_74 ) ;
}
F_44 ( & V_23 -> V_74 ) ;
return 0 ;
}
int F_57 ( struct V_22 * V_23 )
{
F_43 ( & V_23 -> V_74 ) ;
F_47 ( V_23 , V_87 , 0 , true ) ;
F_47 ( V_23 , V_81 , 0 , false ) ;
F_26 ( V_23 ) ;
F_32 ( V_23 ) ;
F_44 ( & V_23 -> V_74 ) ;
return 0 ;
}
static void F_58 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_88 * V_85 = V_23 -> V_85 ;
struct V_1 * V_37 = NULL , * V_89 = V_23 -> V_37 ;
void * V_2 , * V_3 ;
F_43 ( & V_23 -> V_74 ) ;
F_4 ( L_18 ) ;
V_2 = V_61 -> V_26 . V_52 ;
V_3 = V_2 + V_61 -> V_26 . V_27 ;
V_37 = F_1 ( V_2 , V_3 ) ;
if ( F_59 ( V_37 ) ) {
F_45 ( L_19 ,
( int ) F_60 ( V_37 ) ) ;
goto V_90;
}
if ( F_61 ( V_23 -> V_85 , & V_37 -> V_9 ) < 0 ) {
F_12 ( V_37 ) ;
goto V_90;
}
V_85 -> V_23 . V_37 = V_37 ;
F_12 ( V_89 ) ;
F_50 ( V_23 , V_87 , V_23 -> V_37 -> V_10 ) ;
V_85 -> V_91 = true ;
V_90:
F_44 ( & V_23 -> V_74 ) ;
F_62 ( & V_85 -> V_86 ) ;
}
static struct V_92 * F_63 (
struct V_22 * V_23 , T_5 V_93 )
{
struct V_92 * V_94 ;
struct V_95 * V_40 = V_23 -> V_96 . V_95 ;
while ( V_40 ) {
V_94 = F_64 ( V_40 , struct V_92 , V_97 ) ;
if ( V_93 < V_94 -> V_93 )
V_40 = V_40 -> V_98 ;
else if ( V_93 > V_94 -> V_93 )
V_40 = V_40 -> V_99 ;
else
return V_94 ;
}
return NULL ;
}
static void F_65 ( struct V_22 * V_23 ,
struct V_92 * V_100 )
{
struct V_95 * * V_2 = & V_23 -> V_96 . V_95 ;
struct V_95 * V_101 = NULL ;
struct V_92 * V_94 = NULL ;
while ( * V_2 ) {
V_101 = * V_2 ;
V_94 = F_64 ( V_101 , struct V_92 , V_97 ) ;
if ( V_100 -> V_93 < V_94 -> V_93 )
V_2 = & ( * V_2 ) -> V_98 ;
else if ( V_100 -> V_93 > V_94 -> V_93 )
V_2 = & ( * V_2 ) -> V_99 ;
else
F_66 () ;
}
F_67 ( & V_100 -> V_97 , V_101 , V_2 ) ;
F_68 ( & V_100 -> V_97 , & V_23 -> V_96 ) ;
}
static void F_69 ( struct V_102 * V_102 )
{
struct V_92 * V_94 =
F_70 ( V_102 , struct V_92 , V_102 ) ;
if ( V_94 -> V_103 )
F_71 ( V_94 -> V_103 ) ;
if ( V_94 -> V_104 )
F_71 ( V_94 -> V_104 ) ;
F_12 ( V_94 ) ;
}
static void F_72 ( struct V_92 * V_94 )
{
F_73 ( & V_94 -> V_102 , F_69 ) ;
}
static void F_74 ( struct V_92 * V_94 )
{
F_75 ( & V_94 -> V_102 ) ;
}
static struct V_60 * F_76 ( struct V_105 * V_30 ,
struct V_106 * V_28 ,
int * V_107 )
{
struct V_22 * V_23 = V_30 -> V_108 ;
struct V_92 * V_94 ;
T_5 V_93 = F_39 ( V_28 -> V_93 ) ;
struct V_60 * V_4 ;
F_43 ( & V_23 -> V_74 ) ;
V_94 = F_63 ( V_23 , V_93 ) ;
if ( ! V_94 ) {
F_4 ( L_20 , V_93 ) ;
* V_107 = 1 ;
V_4 = NULL ;
} else {
F_4 ( L_21 , V_93 , V_94 -> V_103 ) ;
* V_107 = 0 ;
V_4 = F_17 ( V_94 -> V_103 ) ;
}
F_44 ( & V_23 -> V_74 ) ;
return V_4 ;
}
static int F_77 ( struct V_22 * V_23 , T_5 V_93 ,
struct V_92 * V_94 )
{
int V_6 ;
V_94 -> V_93 = V_93 != 0 ? V_93 : ++ V_23 -> V_109 ;
V_94 -> V_104 -> V_28 . V_93 = F_48 ( V_94 -> V_93 ) ;
F_65 ( V_23 , V_94 ) ;
V_23 -> V_110 ++ ;
F_18 ( & V_23 -> V_30 , F_17 ( V_94 -> V_104 ) ) ;
F_44 ( & V_23 -> V_74 ) ;
V_6 = F_78 ( & V_94 -> V_111 ) ;
F_43 ( & V_23 -> V_74 ) ;
F_79 ( & V_94 -> V_97 , & V_23 -> V_96 ) ;
V_23 -> V_110 -- ;
if ( ! V_6 )
V_6 = V_94 -> V_112 ;
return V_6 ;
}
static int F_80 ( struct V_22 * V_23 ,
struct V_92 * V_94 )
{
int V_6 ;
F_43 ( & V_23 -> V_74 ) ;
V_6 = F_77 ( V_23 , 0 , V_94 ) ;
F_44 ( & V_23 -> V_74 ) ;
return V_6 ;
}
static void F_81 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_92 * V_94 ;
struct V_113 * V_103 = V_61 -> V_26 . V_52 ;
T_5 V_93 = F_39 ( V_61 -> V_28 . V_93 ) ;
if ( V_61 -> V_26 . V_27 != sizeof( * V_103 ) )
goto V_14;
F_4 ( L_22 , V_61 , V_93 ) ;
F_43 ( & V_23 -> V_74 ) ;
V_94 = F_63 ( V_23 , V_93 ) ;
if ( V_94 ) {
* (struct V_114 * ) V_94 -> V_115 = V_103 -> V_116 ;
V_94 -> V_112 = 0 ;
F_74 ( V_94 ) ;
}
F_44 ( & V_23 -> V_74 ) ;
if ( V_94 ) {
F_82 ( & V_94 -> V_111 ) ;
F_72 ( V_94 ) ;
}
return;
V_14:
F_45 ( L_23 , V_93 ) ;
F_46 ( V_61 ) ;
}
int F_83 ( struct V_22 * V_23 , struct V_114 * V_115 )
{
struct V_92 * V_94 ;
struct V_117 * V_72 ;
int V_6 ;
V_94 = F_84 ( sizeof( * V_94 ) , V_17 ) ;
if ( ! V_94 )
return - V_18 ;
F_85 ( & V_94 -> V_102 ) ;
V_94 -> V_115 = V_115 ;
F_86 ( & V_94 -> V_111 ) ;
V_6 = - V_18 ;
V_94 -> V_104 = F_87 ( V_118 , sizeof( * V_72 ) , V_17 ,
true ) ;
if ( ! V_94 -> V_104 )
goto V_90;
V_94 -> V_103 = F_87 ( V_119 , 1024 , V_17 ,
true ) ;
if ( ! V_94 -> V_103 )
goto V_90;
V_72 = V_94 -> V_104 -> V_26 . V_52 ;
V_72 -> V_120 . V_121 = 0 ;
V_72 -> V_120 . V_122 = F_36 ( - 1 ) ;
V_72 -> V_120 . V_123 = 0 ;
V_72 -> V_9 = V_23 -> V_37 -> V_9 ;
V_6 = F_80 ( V_23 , V_94 ) ;
V_90:
F_72 ( V_94 ) ;
return V_6 ;
}
static void F_88 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
struct V_92 * V_94 ;
T_5 V_93 = F_39 ( V_61 -> V_28 . V_93 ) ;
void * V_2 = V_61 -> V_26 . V_52 ;
void * V_3 = V_2 + V_61 -> V_53 ;
T_5 V_124 ;
F_4 ( L_24 , V_41 , V_61 , V_93 ) ;
F_3 ( & V_2 , V_3 , 2 * sizeof( T_5 ) , V_14 ) ;
V_124 = F_89 ( & V_2 ) ;
if ( V_93 != 0 && V_93 != V_124 )
goto V_14;
F_43 ( & V_23 -> V_74 ) ;
V_94 = F_63 ( V_23 , V_124 ) ;
if ( V_94 ) {
* ( T_5 * ) V_94 -> V_115 = F_89 ( & V_2 ) ;
V_94 -> V_112 = 0 ;
F_74 ( V_94 ) ;
}
F_44 ( & V_23 -> V_74 ) ;
if ( V_94 ) {
F_82 ( & V_94 -> V_111 ) ;
F_72 ( V_94 ) ;
}
return;
V_14:
F_45 ( L_25 , V_93 ) ;
F_46 ( V_61 ) ;
}
int F_90 ( struct V_22 * V_23 , const char * V_125 ,
T_5 * V_126 )
{
struct V_92 * V_94 ;
void * V_2 , * V_3 ;
T_5 V_93 ;
int V_6 ;
V_94 = F_84 ( sizeof( * V_94 ) , V_17 ) ;
if ( ! V_94 )
return - V_18 ;
F_85 ( & V_94 -> V_102 ) ;
V_94 -> V_115 = V_126 ;
F_86 ( & V_94 -> V_111 ) ;
V_94 -> V_104 = F_87 ( V_127 ,
sizeof( T_5 ) + sizeof( T_1 ) + strlen ( V_125 ) ,
V_17 , true ) ;
if ( ! V_94 -> V_104 ) {
V_6 = - V_18 ;
goto V_90;
}
V_94 -> V_103 = F_87 ( V_128 , 1024 ,
V_17 , true ) ;
if ( ! V_94 -> V_103 ) {
V_6 = - V_18 ;
goto V_90;
}
V_2 = V_94 -> V_104 -> V_26 . V_52 ;
V_3 = V_2 + V_94 -> V_104 -> V_53 ;
F_43 ( & V_23 -> V_74 ) ;
V_93 = ++ V_23 -> V_109 ;
F_91 ( & V_2 , V_93 ) ;
F_40 ( & V_2 , V_3 , V_125 , strlen ( V_125 ) ) ;
V_6 = F_77 ( V_23 , V_93 , V_94 ) ;
F_44 ( & V_23 -> V_74 ) ;
V_90:
F_72 ( V_94 ) ;
return V_6 ;
}
static void F_92 ( struct V_22 * V_23 )
{
struct V_92 * V_94 ;
struct V_95 * V_2 ;
for ( V_2 = F_93 ( & V_23 -> V_96 ) ; V_2 ; V_2 = F_94 ( V_2 ) ) {
V_94 = F_64 ( V_2 , struct V_92 , V_97 ) ;
F_16 ( V_94 -> V_104 ) ;
F_20 ( V_94 -> V_103 ) ;
F_18 ( & V_23 -> V_30 , F_17 ( V_94 -> V_104 ) ) ;
}
}
static void V_59 ( struct V_129 * V_130 )
{
struct V_22 * V_23 =
F_70 ( V_130 , struct V_22 , V_59 . V_130 ) ;
F_4 ( L_26 ) ;
F_43 ( & V_23 -> V_74 ) ;
if ( V_23 -> V_43 ) {
F_4 ( L_27 , V_41 ) ;
F_30 ( V_23 ) ;
} else {
int V_131 = F_95 ( V_23 -> V_35 ) ;
if ( F_96 ( & V_23 -> V_30 ,
V_132 ) ) {
F_4 ( L_28 ) ;
V_131 = 0 ;
F_30 ( V_23 ) ;
}
if ( ! V_23 -> V_43 ) {
F_28 ( & V_23 -> V_30 ) ;
F_97 ( V_23 ) ;
}
if ( V_131 ) {
unsigned long V_133 = V_49 ;
F_4 ( L_29 ,
V_41 , V_133 , V_23 -> V_48 ) ;
if ( F_54 ( V_133 , V_23 -> V_48 ) )
F_35 ( V_23 ) ;
}
}
F_32 ( V_23 ) ;
F_44 ( & V_23 -> V_74 ) ;
}
static int F_98 ( struct V_22 * V_23 )
{
struct V_134 * V_135 = V_23 -> V_85 -> V_136 ;
struct V_21 * V_137 = V_135 -> V_137 ;
int V_11 = V_135 -> V_11 ;
int V_5 ;
V_23 -> V_37 = F_84 ( sizeof( * V_23 -> V_37 ) +
V_11 * sizeof( V_23 -> V_37 -> V_15 [ 0 ] ) ,
V_138 ) ;
if ( ! V_23 -> V_37 )
return - V_18 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 = V_137 [ V_5 ] ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_19 . V_139 = 0 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_140 . type =
V_51 ;
V_23 -> V_37 -> V_15 [ V_5 ] . V_140 . V_62 = F_48 ( V_5 ) ;
}
V_23 -> V_37 -> V_11 = V_11 ;
return 0 ;
}
int F_99 ( struct V_22 * V_23 , struct V_88 * V_141 )
{
int V_6 = 0 ;
F_4 ( L_30 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_85 = V_141 ;
V_23 -> V_37 = NULL ;
F_100 ( & V_23 -> V_74 ) ;
V_6 = F_98 ( V_23 ) ;
if ( V_6 )
goto V_90;
V_23 -> V_35 = F_101 ( V_141 -> V_136 -> V_140 ,
V_141 -> V_136 -> V_142 ) ;
if ( F_59 ( V_23 -> V_35 ) ) {
V_6 = F_60 ( V_23 -> V_35 ) ;
goto V_143;
}
V_23 -> V_35 -> V_144 =
V_145 | V_51 |
V_146 | V_147 ;
V_6 = - V_18 ;
V_23 -> V_34 = F_87 ( V_148 ,
sizeof( struct V_71 ) ,
V_17 , true ) ;
if ( ! V_23 -> V_34 )
goto V_149;
V_23 -> V_33 = F_87 ( V_150 , 96 , V_17 ,
true ) ;
if ( ! V_23 -> V_33 )
goto V_151;
V_23 -> V_32 = F_87 ( V_152 , 4096 , V_17 ,
true ) ;
if ( ! V_23 -> V_32 )
goto V_153;
V_23 -> V_25 = F_87 ( V_154 , 4096 , V_17 , true ) ;
V_23 -> V_24 = 0 ;
if ( ! V_23 -> V_25 )
goto V_155;
F_102 ( & V_23 -> V_30 , V_23 , & V_156 ,
& V_23 -> V_85 -> V_157 ) ;
V_23 -> V_31 = - 1 ;
V_23 -> V_44 = false ;
V_23 -> V_45 = 1 ;
F_103 ( & V_23 -> V_59 , V_59 ) ;
V_23 -> V_96 = V_158 ;
V_23 -> V_110 = 0 ;
V_23 -> V_109 = 0 ;
return 0 ;
V_155:
F_71 ( V_23 -> V_32 ) ;
V_153:
F_71 ( V_23 -> V_33 ) ;
V_151:
F_71 ( V_23 -> V_34 ) ;
V_149:
F_104 ( V_23 -> V_35 ) ;
V_143:
F_12 ( V_23 -> V_37 ) ;
V_90:
return V_6 ;
}
void F_105 ( struct V_22 * V_23 )
{
F_4 ( L_31 ) ;
F_106 ( & V_23 -> V_59 ) ;
F_43 ( & V_23 -> V_74 ) ;
F_19 ( V_23 ) ;
V_23 -> V_31 = - 1 ;
F_44 ( & V_23 -> V_74 ) ;
F_107 () ;
F_104 ( V_23 -> V_35 ) ;
F_71 ( V_23 -> V_25 ) ;
F_71 ( V_23 -> V_32 ) ;
F_71 ( V_23 -> V_33 ) ;
F_71 ( V_23 -> V_34 ) ;
F_12 ( V_23 -> V_37 ) ;
}
static void F_108 ( struct V_22 * V_23 )
{
if ( V_23 -> V_43 ) {
F_4 ( L_32 , V_41 , V_23 -> V_31 ) ;
V_23 -> V_43 = false ;
V_23 -> V_44 = true ;
V_23 -> V_45 /= 2 ;
if ( V_23 -> V_45 < 1 )
V_23 -> V_45 = 1 ;
}
}
static void F_109 ( struct V_22 * V_23 ,
struct V_60 * V_61 )
{
int V_42 ;
int V_159 = 0 ;
F_43 ( & V_23 -> V_74 ) ;
V_159 = F_95 ( V_23 -> V_35 ) ;
V_23 -> V_24 = 0 ;
V_42 = F_110 ( V_23 -> V_35 , V_61 -> V_26 . V_52 ,
V_61 -> V_26 . V_27 ,
V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 > 0 ) {
F_14 ( V_23 , V_42 ) ;
goto V_90;
}
F_108 ( V_23 ) ;
if ( V_42 < 0 ) {
V_23 -> V_85 -> V_160 = V_42 ;
} else if ( ! V_159 && F_95 ( V_23 -> V_35 ) ) {
F_4 ( L_33 ) ;
V_23 -> V_85 -> V_157 . V_161 . V_140 . type = V_162 ;
V_23 -> V_85 -> V_157 . V_161 . V_140 . V_62 =
F_48 ( V_23 -> V_35 -> V_163 ) ;
F_35 ( V_23 ) ;
F_92 ( V_23 ) ;
F_31 ( L_34 , V_23 -> V_31 ,
F_11 ( & V_23 -> V_30 . V_54 . V_20 ) ) ;
}
V_90:
F_44 ( & V_23 -> V_74 ) ;
if ( V_23 -> V_85 -> V_160 < 0 )
F_62 ( & V_23 -> V_85 -> V_86 ) ;
}
static int F_97 ( struct V_22 * V_23 )
{
int V_42 ;
if ( V_23 -> V_24 )
return 0 ;
V_42 = F_111 ( V_23 -> V_35 , V_23 -> V_25 -> V_26 . V_52 ,
V_23 -> V_25 -> V_53 ) ;
if ( V_42 <= 0 )
return V_42 ;
F_14 ( V_23 , V_42 ) ;
return 0 ;
}
int F_112 ( struct V_22 * V_23 )
{
int V_42 ;
F_43 ( & V_23 -> V_74 ) ;
V_42 = F_97 ( V_23 ) ;
F_44 ( & V_23 -> V_74 ) ;
return V_42 ;
}
static void F_113 ( struct V_105 * V_30 , struct V_60 * V_61 )
{
struct V_22 * V_23 = V_30 -> V_108 ;
int type = F_114 ( V_61 -> V_28 . type ) ;
if ( ! V_23 )
return;
switch ( type ) {
case V_152 :
F_109 ( V_23 , V_61 ) ;
break;
case V_148 :
F_41 ( V_23 , V_61 ) ;
break;
case V_119 :
F_81 ( V_23 , V_61 ) ;
break;
case V_128 :
F_88 ( V_23 , V_61 ) ;
break;
case V_164 :
F_58 ( V_23 , V_61 ) ;
break;
case V_165 :
F_115 ( & V_23 -> V_85 -> V_166 , V_61 ) ;
break;
default:
if ( V_23 -> V_85 -> V_167 &&
V_23 -> V_85 -> V_167 ( V_23 -> V_85 , V_61 ) == 0 )
break;
F_45 ( L_35 , type ,
F_116 ( type ) ) ;
}
F_71 ( V_61 ) ;
}
static struct V_60 * F_117 ( struct V_105 * V_30 ,
struct V_106 * V_28 ,
int * V_107 )
{
struct V_22 * V_23 = V_30 -> V_108 ;
int type = F_114 ( V_28 -> type ) ;
int V_29 = F_42 ( V_28 -> V_29 ) ;
struct V_60 * V_4 = NULL ;
* V_107 = 0 ;
switch ( type ) {
case V_148 :
V_4 = F_17 ( V_23 -> V_34 ) ;
break;
case V_119 :
return F_76 ( V_30 , V_28 , V_107 ) ;
case V_152 :
V_4 = F_17 ( V_23 -> V_32 ) ;
break;
case V_128 :
if ( F_39 ( V_28 -> V_93 ) != 0 )
return F_76 ( V_30 , V_28 , V_107 ) ;
case V_164 :
case V_168 :
case V_165 :
V_4 = F_87 ( type , V_29 , V_17 , false ) ;
if ( ! V_4 )
return NULL ;
break;
}
if ( ! V_4 ) {
F_31 ( L_36 , type ) ;
* V_107 = 1 ;
} else if ( V_29 > V_4 -> V_53 ) {
F_118 ( L_37 ,
V_29 , V_4 -> V_53 ,
( unsigned int ) V_30 -> V_169 . type ,
F_39 ( V_30 -> V_169 . V_62 ) ) ;
F_71 ( V_4 ) ;
V_4 = F_87 ( type , V_29 , V_17 , false ) ;
}
return V_4 ;
}
static void F_119 ( struct V_105 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_108 ;
F_43 ( & V_23 -> V_74 ) ;
F_4 ( L_38 , V_41 , V_23 -> V_31 ) ;
if ( V_23 -> V_31 >= 0 ) {
if ( ! V_23 -> V_43 ) {
F_4 ( L_39 , V_41 ) ;
F_30 ( V_23 ) ;
F_32 ( V_23 ) ;
} else {
F_4 ( L_40 , V_41 ) ;
}
}
F_44 ( & V_23 -> V_74 ) ;
}
static struct V_105 * F_120 ( struct V_105 * V_30 )
{
return V_30 ;
}
static void F_121 ( struct V_105 * V_30 )
{
}
