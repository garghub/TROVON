static bool F_1 ( const T_1 * V_1 )
{
return ! memcmp ( & V_1 -> V_2 [ 4 ] , & V_3 . V_2 [ 4 ] , sizeof( T_1 ) - 4 ) ;
}
static unsigned int F_2 ( const T_1 * V_4 )
{
return * ( ( unsigned int * ) V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , const T_1 * V_4 )
{
unsigned int V_7 = F_2 ( V_4 ) ;
F_4 ( V_6 , V_8 , V_7 ) ;
}
static void F_5 ( struct V_5 * V_9 ,
struct V_5 * V_10 )
{
static T_2 V_11 = V_12 ;
struct V_13 * V_14 ;
F_4 ( V_9 , V_8 , V_15 ) ;
while ( 1 ) {
if ( V_11 < V_12 ||
V_11 == V_15 )
V_11 = V_12 ;
V_9 -> V_16 = V_11 ++ ;
V_14 = F_6 ( V_9 , V_10 ) ;
if ( ! V_14 ) {
return;
}
F_7 ( V_14 ) ;
}
}
static void F_8 ( struct V_17 * V_18 )
{
F_9 ( V_18 ,
F_10 ( V_19 ) ) ;
F_11 () ;
}
static void F_12 ( struct V_17 * V_18 )
{
F_9 ( V_18 , 0 ) ;
F_11 () ;
}
static bool F_13 ( struct V_17 * V_18 )
{
T_2 V_20 = F_14 ( & V_18 -> V_21 ) ;
return V_20 >= F_10 ( 0 ) ;
}
static int F_15 ( struct V_17 * V_18 )
{
T_2 V_20 = F_14 ( & V_18 -> V_21 ) ;
if ( V_20 > F_10 ( 0 ) ) {
return 1 ;
}
if ( V_20 == F_10 ( 0 ) ) {
return 0 ;
}
return - 1 ;
}
static T_3 F_16 ( struct V_17 * V_18 )
{
T_2 V_22 = F_17 ( & V_18 -> V_23 ) ;
T_3 V_24 ;
if ( V_22 <= F_10 ( 1 ) + F_10 ( 0 ) )
return 0 ;
V_24 = V_22 - F_10 ( 1 ) - F_10 ( 0 ) ;
return F_18 ( V_24 , 8 ) ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_25 * V_26 , T_3 V_27 )
{
V_26 -> V_28 . V_29 = 1 ;
V_26 -> V_28 . V_30 = V_27 ;
return F_20 ( V_18 , & V_26 -> V_28 ,
sizeof( V_26 -> V_28 ) + V_27 ,
0 , V_31 , 0 ) ;
}
static void F_21 ( void * V_32 )
{
struct V_13 * V_14 = (struct V_13 * ) V_32 ;
struct V_33 * V_34 = F_22 ( V_14 ) ;
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_17 * V_18 = V_36 -> V_18 ;
if ( F_13 ( V_18 ) )
V_14 -> V_38 ( V_14 ) ;
if ( F_17 ( & V_18 -> V_23 ) > 0 )
V_14 -> V_39 ( V_14 ) ;
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_13 * V_14 = F_24 ( V_18 ) ;
struct V_33 * V_34 = F_22 ( V_14 ) ;
F_25 ( V_14 ) ;
V_14 -> V_40 = V_41 ;
F_26 ( V_14 , V_42 ) ;
V_34 -> V_43 |= V_44 | V_45 ;
V_14 -> V_46 ( V_14 ) ;
F_27 ( V_14 ) ;
}
static void F_28 ( struct V_17 * V_18 )
{
T_1 * V_47 , * V_48 ;
unsigned char V_49 ;
struct V_5 V_6 ;
struct V_13 * V_14 , * V_50 = NULL ;
struct V_33 * V_51 ;
struct V_35 * V_36 , * V_52 ;
int V_24 ;
V_48 = & V_18 -> V_53 . V_54 . V_48 ;
V_47 = & V_18 -> V_53 . V_54 . V_47 ;
V_49 = V_18 -> V_53 . V_54 . V_55 . V_56 . V_57 [ 0 ] ;
if ( ! F_1 ( V_48 ) ||
F_2 ( V_48 ) > V_58 )
return;
F_3 ( & V_6 , V_49 ? V_48 : V_47 ) ;
V_14 = F_29 ( & V_6 ) ;
if ( ! V_14 )
return;
F_25 ( V_14 ) ;
if ( ( V_49 && V_14 -> V_40 != V_59 ) ||
( ! V_49 && V_14 -> V_40 != V_60 ) )
goto V_61;
if ( V_49 ) {
if ( V_14 -> V_62 >= V_14 -> V_63 )
goto V_61;
V_50 = F_30 ( F_31 ( V_14 ) , NULL , V_14 , V_64 ,
V_14 -> V_65 , 0 ) ;
if ( ! V_50 )
goto V_61;
V_50 -> V_40 = V_60 ;
V_51 = F_22 ( V_50 ) ;
V_52 = V_51 -> V_37 ;
V_52 -> V_18 = V_18 ;
} else {
V_36 = F_22 ( V_14 ) -> V_37 ;
V_36 -> V_18 = V_18 ;
}
F_32 ( V_18 , V_66 ) ;
V_24 = F_33 ( V_18 , V_67 ,
V_68 , NULL , 0 ,
F_21 , V_49 ? V_50 : V_14 ) ;
if ( V_24 != 0 ) {
if ( V_49 ) {
V_52 -> V_18 = NULL ;
F_7 ( V_50 ) ;
} else {
V_36 -> V_18 = NULL ;
}
goto V_61;
}
F_34 ( V_18 , V_49 ? V_50 : V_14 ) ;
F_35 ( V_18 , F_23 ) ;
if ( V_49 ) {
V_50 -> V_40 = V_69 ;
V_14 -> V_62 ++ ;
F_3 ( & V_51 -> V_70 , V_48 ) ;
F_5 ( & V_51 -> V_71 , & V_51 -> V_70 ) ;
V_52 -> V_72 = * V_48 ;
V_52 -> V_73 = * V_47 ;
F_36 ( V_51 ) ;
F_37 ( V_14 , V_50 ) ;
} else {
V_14 -> V_40 = V_69 ;
V_14 -> V_74 -> V_75 = V_69 ;
F_36 ( F_22 ( V_14 ) ) ;
}
V_14 -> V_46 ( V_14 ) ;
V_61:
F_7 ( V_14 ) ;
F_27 ( V_14 ) ;
}
static T_2 F_38 ( void )
{
return V_8 ;
}
static int F_39 ( struct V_33 * V_34 , struct V_33 * V_76 )
{
struct V_35 * V_36 ;
V_36 = F_40 ( sizeof( * V_36 ) , V_64 ) ;
if ( ! V_36 )
return - V_77 ;
V_34 -> V_37 = V_36 ;
V_36 -> V_34 = V_34 ;
return 0 ;
}
static int F_41 ( struct V_33 * V_34 )
{
union V_78 V_79 , V_80 ;
struct V_35 * V_81 = V_34 -> V_37 ;
V_79 . V_82 = V_3 ;
V_79 . V_16 = V_34 -> V_70 . V_16 ;
V_81 -> V_72 = V_79 . V_82 ;
V_80 . V_82 = V_3 ;
V_80 . V_16 = V_34 -> V_71 . V_16 ;
V_81 -> V_73 = V_80 . V_82 ;
return F_42 ( & V_81 -> V_72 , & V_81 -> V_73 ) ;
}
static int F_43 ( struct V_33 * V_34 , int V_83 )
{
struct V_13 * V_14 = F_44 ( V_34 ) ;
struct V_84 V_28 ;
struct V_25 * V_26 ;
struct V_35 * V_36 ;
if ( ! ( V_83 & V_44 ) )
return 0 ;
F_25 ( V_14 ) ;
V_36 = V_34 -> V_37 ;
if ( V_36 -> V_85 )
goto V_61;
V_26 = (struct V_25 * ) & V_28 ;
( void ) F_19 ( V_36 -> V_18 , V_26 , 0 ) ;
V_36 -> V_85 = true ;
V_61:
F_27 ( V_14 ) ;
return 0 ;
}
static void F_45 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_44 ( V_34 ) ;
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_17 * V_18 ;
F_25 ( V_14 ) ;
V_14 -> V_40 = V_86 ;
F_46 ( V_34 ) ;
F_27 ( V_14 ) ;
V_18 = V_36 -> V_18 ;
if ( V_18 )
F_43 ( V_34 , V_45 | V_44 ) ;
}
static void F_47 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_17 * V_18 = V_36 -> V_18 ;
if ( V_18 )
F_48 ( V_18 ) ;
F_49 ( V_36 ) ;
}
static int F_50 ( struct V_33 * V_34 , struct V_5 * V_6 )
{
return - V_87 ;
}
static int F_51 ( struct V_33 * V_34 , struct V_88 * V_89 ,
T_3 V_90 , int V_91 )
{
return - V_87 ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_5 * V_9 , struct V_88 * V_89 ,
T_3 V_92 )
{
return - V_87 ;
}
static bool F_53 ( T_2 V_93 , T_2 V_7 )
{
return false ;
}
static int F_54 ( struct V_35 * V_36 )
{
struct V_94 * V_95 ;
T_2 V_96 ;
V_95 = (struct V_94 * ) ( V_36 -> V_97 + 1 ) ;
V_96 = V_95 -> V_28 . V_30 ;
if ( V_96 > V_98 )
return - V_99 ;
if ( V_96 == 0 )
V_36 -> V_34 -> V_43 |= V_44 ;
V_36 -> V_100 = V_96 ;
V_36 -> V_101 = 0 ;
return 0 ;
}
static T_4 F_55 ( struct V_33 * V_34 , struct V_88 * V_89 ,
T_3 V_90 , int V_91 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
bool V_102 = ! V_36 -> V_97 ;
struct V_94 * V_95 ;
T_2 V_103 ;
int V_24 ;
if ( V_91 & V_104 )
return - V_87 ;
if ( V_102 ) {
V_36 -> V_97 = F_56 ( V_36 -> V_18 ) ;
V_24 = F_54 ( V_36 ) ;
if ( V_24 )
return V_24 ;
}
V_95 = (struct V_94 * ) ( V_36 -> V_97 + 1 ) ;
V_103 = F_57 ( T_2 , V_90 , V_36 -> V_100 ) ;
V_24 = F_58 ( V_89 , V_95 -> V_105 + V_36 -> V_101 , V_103 ) ;
if ( V_24 != 0 )
return V_24 ;
V_36 -> V_100 -= V_103 ;
if ( V_36 -> V_100 == 0 ) {
V_36 -> V_97 = F_59 ( V_36 -> V_18 , V_36 -> V_97 ) ;
if ( V_36 -> V_97 ) {
V_24 = F_54 ( V_36 ) ;
if ( V_24 )
return V_24 ;
}
} else {
V_36 -> V_101 += V_103 ;
}
return V_103 ;
}
static T_4 F_60 ( struct V_33 * V_34 , struct V_88 * V_89 ,
T_3 V_90 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_17 * V_18 = V_36 -> V_18 ;
struct V_25 * V_26 ;
T_4 V_27 , V_106 , V_24 ;
F_61 ( sizeof( * V_26 ) != V_107 ) ;
V_26 = F_62 ( sizeof( * V_26 ) , V_64 ) ;
if ( ! V_26 )
return - V_77 ;
V_106 = F_16 ( V_18 ) ;
V_27 = F_57 ( T_4 , V_90 , V_106 ) ;
V_27 = F_57 ( T_4 , V_27 , V_19 ) ;
V_24 = F_63 ( V_26 -> V_105 , V_89 , V_27 ) ;
if ( V_24 < 0 )
goto V_61;
V_24 = F_19 ( V_36 -> V_18 , V_26 , V_27 ) ;
if ( V_24 < 0 )
goto V_61;
V_24 = V_27 ;
V_61:
F_49 ( V_26 ) ;
return V_24 ;
}
static T_5 F_64 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
T_5 V_24 ;
if ( V_36 -> V_100 > 0 )
return 1 ;
switch ( F_15 ( V_36 -> V_18 ) ) {
case 1 :
V_24 = 1 ;
break;
case 0 :
V_34 -> V_43 |= V_44 ;
V_24 = 0 ;
break;
default:
V_24 = 0 ;
break;
}
return V_24 ;
}
static T_5 F_65 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_17 * V_18 = V_36 -> V_18 ;
T_5 V_24 ;
V_24 = F_16 ( V_18 ) ;
if ( V_24 > 0 ) {
F_12 ( V_18 ) ;
} else {
F_8 ( V_18 ) ;
V_24 = F_16 ( V_18 ) ;
if ( V_24 > 0 )
F_12 ( V_18 ) ;
}
return V_24 ;
}
static T_6 F_66 ( struct V_33 * V_34 )
{
return V_98 + 1 ;
}
static bool F_67 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
return V_36 -> V_18 != NULL ;
}
static bool F_68 ( T_2 V_93 , T_2 V_7 )
{
if ( V_7 > V_108 )
return false ;
if ( V_93 == V_109 )
return true ;
return false ;
}
static
int F_69 ( struct V_33 * V_34 , T_3 V_110 , bool * V_20 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
* V_20 = F_13 ( V_36 -> V_18 ) ;
return 0 ;
}
static
int F_70 ( struct V_33 * V_34 , T_3 V_110 , bool * V_111 )
{
* V_111 = F_65 ( V_34 ) > 0 ;
return 0 ;
}
static
int F_71 ( struct V_33 * V_34 , T_3 V_110 ,
struct V_112 * V_113 )
{
return 0 ;
}
static
int F_72 ( struct V_33 * V_34 , T_3 V_110 ,
struct V_112 * V_113 )
{
return 0 ;
}
static
int F_73 ( struct V_33 * V_34 , T_3 V_110 ,
struct V_112 * V_113 )
{
return 0 ;
}
static
int F_74 ( struct V_33 * V_34 , T_3 V_110 ,
T_4 V_114 , bool V_115 ,
struct V_112 * V_113 )
{
return 0 ;
}
static
int F_75 ( struct V_33 * V_34 ,
struct V_116 * V_113 )
{
return 0 ;
}
static
int F_76 ( struct V_33 * V_34 ,
struct V_116 * V_113 )
{
return 0 ;
}
static
int F_77 ( struct V_33 * V_34 ,
struct V_116 * V_113 )
{
return 0 ;
}
static
int F_78 ( struct V_33 * V_34 , T_4 V_117 ,
struct V_116 * V_113 )
{
return 0 ;
}
static void F_79 ( struct V_33 * V_34 , T_6 V_118 )
{
}
static void F_80 ( struct V_33 * V_34 , T_6 V_118 )
{
}
static void F_81 ( struct V_33 * V_34 , T_6 V_118 )
{
}
static T_6 F_82 ( struct V_33 * V_34 )
{
return - V_119 ;
}
static T_6 F_83 ( struct V_33 * V_34 )
{
return - V_119 ;
}
static T_6 F_84 ( struct V_33 * V_34 )
{
return - V_119 ;
}
static int F_85 ( struct V_120 * V_121 ,
const struct V_122 * V_123 )
{
struct V_17 * V_18 = V_121 -> V_124 ;
F_28 ( V_18 ) ;
return 0 ;
}
static int F_86 ( struct V_120 * V_121 )
{
struct V_17 * V_18 = V_121 -> V_124 ;
F_87 ( V_18 ) ;
return 0 ;
}
static int T_7 F_88 ( void )
{
int V_24 ;
if ( V_125 < V_126 )
return - V_127 ;
V_24 = F_89 ( & V_128 ) ;
if ( V_24 != 0 )
return V_24 ;
V_24 = F_90 ( & V_129 ) ;
if ( V_24 ) {
F_91 ( & V_128 ) ;
return V_24 ;
}
return 0 ;
}
static void T_8 F_92 ( void )
{
F_93 () ;
F_91 ( & V_128 ) ;
}
