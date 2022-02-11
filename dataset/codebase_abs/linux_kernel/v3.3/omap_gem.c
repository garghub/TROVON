static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , struct V_5 * V_6 )
{
if ( V_2 -> V_7 -> V_8 ) {
T_1 V_9 = V_10 * V_11 [ V_4 ] . V_12 ;
T_2 V_13 = F_2 ( V_2 ) +
( V_6 -> V_14 << V_15 ) ;
F_3 ( V_2 -> V_7 -> V_8 , V_13 , V_9 , 1 ) ;
}
V_6 -> V_2 = NULL ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
if ( V_17 -> V_18 & V_19 ) {
enum V_3 V_4 = F_6 ( V_17 -> V_18 ) ;
int V_20 ;
if ( ! V_11 )
return;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_5 * V_6 = & V_11 [ V_4 ] . V_6 [ V_20 ] ;
if ( V_6 -> V_2 == V_2 )
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_22 != NULL ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
struct V_23 * * V_24 ;
F_9 ( V_17 -> V_24 ) ;
V_24 = F_10 ( V_2 , V_25 ) ;
if ( F_11 ( V_24 ) ) {
F_12 ( V_2 -> V_7 -> V_7 , L_1 , F_13 ( V_24 ) ) ;
return F_13 ( V_24 ) ;
}
if ( V_17 -> V_18 & ( V_26 | V_27 ) ) {
int V_20 , V_28 = V_2 -> V_9 >> V_15 ;
T_3 * V_29 = F_14 ( V_28 * sizeof( V_29 ) , V_25 ) ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
V_29 [ V_20 ] = F_15 ( V_2 -> V_7 -> V_7 , V_24 [ V_20 ] ,
0 , V_10 , V_30 ) ;
}
V_17 -> V_29 = V_29 ;
}
V_17 -> V_24 = V_24 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
if ( V_17 -> V_18 & ( V_26 | V_27 ) ) {
int V_20 , V_28 = V_2 -> V_9 >> V_15 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
F_17 ( V_2 -> V_7 -> V_7 , V_17 -> V_29 [ V_20 ] ,
V_10 , V_30 ) ;
}
F_18 ( V_17 -> V_29 ) ;
V_17 -> V_29 = NULL ;
}
F_19 ( V_2 , V_17 -> V_24 , true , false ) ;
V_17 -> V_24 = NULL ;
}
static T_4 F_2 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 . V_32 ) {
T_1 V_9 = F_20 ( V_2 ) ;
int V_33 = F_21 ( V_2 , V_9 ) ;
if ( V_33 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_2 ) ;
return 0 ;
}
}
return ( T_4 ) V_2 -> V_31 . V_34 . V_35 << V_15 ;
}
T_4 F_22 ( struct V_1 * V_2 )
{
T_4 V_36 ;
F_23 ( & V_2 -> V_7 -> V_37 ) ;
V_36 = F_2 ( V_2 ) ;
F_24 ( & V_2 -> V_7 -> V_37 ) ;
return V_36 ;
}
T_1 F_20 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
T_1 V_9 = V_2 -> V_9 ;
if ( V_17 -> V_18 & V_19 ) {
V_9 = F_25 ( F_6 ( V_17 -> V_18 ) ,
V_17 -> V_38 , V_17 -> V_12 ) ;
}
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
unsigned long V_43 ;
T_5 V_44 ;
V_44 = ( ( unsigned long ) V_42 -> V_45 -
V_40 -> V_46 ) >> V_15 ;
if ( V_17 -> V_24 ) {
V_43 = F_27 ( V_17 -> V_24 [ V_44 ] ) ;
} else {
F_28 ( ! ( V_17 -> V_18 & V_47 ) ) ;
V_43 = ( V_17 -> V_48 >> V_15 ) + V_44 ;
}
F_29 ( L_3 , V_42 -> V_45 ,
V_43 , V_43 << V_15 ) ;
return F_30 ( V_40 , ( unsigned long ) V_42 -> V_45 , V_43 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_17 -> V_18 ) ;
struct V_23 * V_24 [ 64 ] ;
unsigned long V_43 ;
T_5 V_44 , V_49 ;
void T_6 * V_50 ;
int V_20 , V_33 , V_51 ;
if ( ! V_11 )
return - V_52 ;
V_44 = ( ( unsigned long ) V_42 -> V_45 -
V_40 -> V_46 ) >> V_15 ;
V_49 = F_32 ( V_44 , V_11 [ V_4 ] . V_12 ) ;
V_50 = V_42 -> V_45 - ( ( V_44 - V_49 ) << V_15 ) ;
V_6 = & V_11 [ V_4 ] . V_6 [ V_11 [ V_4 ] . V_53 ] ;
V_51 = V_17 -> V_38 >> V_11 [ V_4 ] . V_54 ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_14 = V_49 ;
V_49 = ( V_49 >> V_11 [ V_4 ] . V_55 ) * V_51 ;
memcpy ( V_24 , & V_17 -> V_24 [ V_49 ] ,
sizeof( struct V_23 * ) * V_51 ) ;
memset ( V_24 + V_51 , 0 ,
sizeof( struct V_23 * ) * ( V_11 [ V_4 ] . V_12 - V_51 ) ) ;
V_33 = F_33 ( V_6 -> V_56 , V_24 , F_34 ( V_24 ) , 0 , true ) ;
if ( V_33 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_4 , V_33 ) ;
return V_33 ;
}
V_20 = V_11 [ V_4 ] . V_12 ;
V_43 = V_6 -> V_48 >> V_15 ;
F_29 ( L_3 , V_42 -> V_45 ,
V_43 , V_43 << V_15 ) ;
while ( V_20 -- ) {
F_30 ( V_40 , ( unsigned long ) V_50 , V_43 ) ;
V_43 += V_11 [ V_4 ] . V_57 ;
V_50 += V_10 ;
}
V_11 [ V_4 ] . V_53 = ( V_11 [ V_4 ] . V_53 + 1 ) % V_21 ;
return 0 ;
}
int F_35 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_40 -> V_58 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
struct V_59 * V_7 = V_2 -> V_7 ;
struct V_23 * * V_24 ;
int V_33 ;
F_23 ( & V_7 -> V_37 ) ;
V_33 = F_36 ( V_2 , & V_24 ) ;
if ( V_33 ) {
goto V_60;
}
if ( V_17 -> V_18 & V_19 )
V_33 = F_31 ( V_2 , V_40 , V_42 ) ;
else
V_33 = F_26 ( V_2 , V_40 , V_42 ) ;
V_60:
F_24 ( & V_7 -> V_37 ) ;
switch ( V_33 ) {
case 0 :
case - V_61 :
case - V_62 :
return V_63 ;
case - V_64 :
return V_65 ;
default:
return V_66 ;
}
}
int F_37 ( struct V_67 * V_22 , struct V_39 * V_40 )
{
struct V_16 * V_17 ;
int V_33 ;
V_33 = F_38 ( V_22 , V_40 ) ;
if ( V_33 ) {
F_39 ( L_5 , V_33 ) ;
return V_33 ;
}
V_17 = F_5 ( V_40 -> V_58 ) ;
V_40 -> V_68 &= ~ V_69 ;
V_40 -> V_68 |= V_70 ;
if ( V_17 -> V_18 & V_26 ) {
V_40 -> V_71 = F_40 ( F_41 ( V_40 -> V_68 ) ) ;
} else if ( V_17 -> V_18 & V_27 ) {
V_40 -> V_71 = F_42 ( F_41 ( V_40 -> V_68 ) ) ;
} else {
V_40 -> V_71 = F_41 ( V_40 -> V_68 ) ;
}
return V_33 ;
}
int F_43 ( struct V_72 * V_67 , struct V_59 * V_7 ,
struct V_73 * args )
{
union V_74 V_75 ;
args -> V_76 = F_44 ( args -> V_76 , args -> V_38 , args -> V_77 ) ;
args -> V_9 = F_45 ( args -> V_76 * args -> V_12 ) ;
V_75 = (union V_74 ) {
. V_78 = args -> V_9 ,
} ;
return F_46 ( V_7 , V_67 , V_75 ,
V_79 | V_26 , & args -> V_80 ) ;
}
int F_47 ( struct V_72 * V_67 , struct V_59 * V_7 ,
T_7 V_80 )
{
return F_48 ( V_67 , V_80 ) ;
}
int F_49 ( struct V_72 * V_67 , struct V_59 * V_7 ,
T_7 V_80 , T_4 * V_36 )
{
struct V_1 * V_2 ;
int V_33 = 0 ;
V_2 = F_50 ( V_7 , V_67 , V_80 ) ;
if ( V_2 == NULL ) {
V_33 = - V_81 ;
goto V_60;
}
* V_36 = F_22 ( V_2 ) ;
F_51 ( V_2 ) ;
V_60:
return V_33 ;
}
int F_52 ( struct V_1 * V_2 , T_7 V_82 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
T_7 V_28 = V_2 -> V_9 >> V_15 ;
int V_33 = 0 ;
if ( V_82 > V_28 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_6 , V_82 ) ;
return - V_83 ;
}
V_17 -> V_82 = V_82 ;
if ( F_53 () || F_54 ( & V_2 -> V_7 -> V_37 ) ) {
return 0 ;
}
F_23 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_17 -> V_56 ) {
struct V_23 * * V_24 ;
V_33 = F_36 ( V_2 , & V_24 ) ;
if ( V_33 )
goto V_60;
V_33 = F_33 ( V_17 -> V_56 , V_24 , V_28 , V_82 , true ) ;
if ( V_33 )
F_12 ( V_2 -> V_7 -> V_7 , L_7 , V_33 ) ;
}
V_60:
F_24 ( & V_2 -> V_7 -> V_37 ) ;
return V_33 ;
}
int F_55 ( struct V_1 * V_2 ,
T_3 * V_48 , bool V_84 )
{
struct V_85 * V_86 = V_2 -> V_7 -> V_87 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
F_23 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_84 && F_7 ( V_2 ) && V_86 -> V_88 ) {
if ( V_17 -> V_89 == 0 ) {
struct V_23 * * V_24 ;
T_7 V_28 = V_2 -> V_9 >> V_15 ;
enum V_3 V_4 = F_6 ( V_17 -> V_18 ) ;
struct V_90 * V_56 ;
F_28 ( V_17 -> V_56 ) ;
V_33 = F_36 ( V_2 , & V_24 ) ;
if ( V_33 )
goto V_60;
if ( V_17 -> V_18 & V_19 ) {
V_56 = F_56 ( V_4 ,
V_17 -> V_38 ,
V_17 -> V_12 , 0 ) ;
} else {
V_56 = F_57 ( V_2 -> V_9 ) ;
}
if ( F_11 ( V_56 ) ) {
V_33 = F_13 ( V_56 ) ;
F_12 ( V_2 -> V_7 -> V_7 ,
L_8 , V_33 , V_4 ) ;
goto V_60;
}
V_33 = F_33 ( V_56 , V_24 , V_28 ,
V_17 -> V_82 , true ) ;
if ( V_33 ) {
F_58 ( V_56 ) ;
F_12 ( V_2 -> V_7 -> V_7 ,
L_9 , V_33 ) ;
goto V_60;
}
V_17 -> V_48 = F_59 ( V_56 ) ;
V_17 -> V_56 = V_56 ;
F_39 ( L_10 , V_17 -> V_48 ) ;
}
V_17 -> V_89 ++ ;
* V_48 = V_17 -> V_48 ;
} else if ( V_17 -> V_18 & V_47 ) {
* V_48 = V_17 -> V_48 ;
} else {
V_33 = - V_83 ;
}
V_60:
F_24 ( & V_2 -> V_7 -> V_37 ) ;
return V_33 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
F_23 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_17 -> V_89 > 0 ) {
V_17 -> V_89 -- ;
if ( V_17 -> V_89 == 0 ) {
V_33 = F_61 ( V_17 -> V_56 ) ;
if ( V_33 ) {
F_12 ( V_2 -> V_7 -> V_7 ,
L_11 , V_33 ) ;
goto V_60;
}
V_33 = F_58 ( V_17 -> V_56 ) ;
if ( V_33 ) {
F_12 ( V_2 -> V_7 -> V_7 ,
L_12 , V_33 ) ;
}
V_17 -> V_56 = NULL ;
}
}
V_60:
F_24 ( & V_2 -> V_7 -> V_37 ) ;
return V_33 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_23 * * * V_24 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
if ( F_7 ( V_2 ) && ! V_17 -> V_24 ) {
V_33 = F_8 ( V_2 ) ;
if ( V_33 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_13 ) ;
return V_33 ;
}
}
* V_24 = V_17 -> V_24 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 , struct V_23 * * * V_24 )
{
int V_33 ;
F_23 ( & V_2 -> V_7 -> V_37 ) ;
V_33 = F_36 ( V_2 , V_24 ) ;
F_24 ( & V_2 -> V_7 -> V_37 ) ;
return V_33 ;
}
int F_63 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
F_9 ( ! F_54 ( & V_2 -> V_7 -> V_37 ) ) ;
if ( ! V_17 -> V_50 ) {
struct V_23 * * V_24 ;
int V_33 = F_36 ( V_2 , & V_24 ) ;
if ( V_33 )
return F_65 ( V_33 ) ;
V_17 -> V_50 = F_66 ( V_24 , V_2 -> V_9 >> V_15 ,
V_91 , F_40 ( V_92 ) ) ;
}
return V_17 -> V_50 ;
}
static inline bool F_67 ( struct V_93 * V_94 )
{
struct V_16 * V_17 = V_94 -> V_17 ;
if ( ( V_94 -> V_95 & V_96 ) &&
( V_17 -> V_97 -> V_98 < V_94 -> V_99 ) )
return true ;
if ( ( V_94 -> V_95 & V_100 ) &&
( V_17 -> V_97 -> V_101 < V_94 -> V_102 ) )
return true ;
return false ;
}
static void F_68 ( void )
{
struct V_93 * V_94 , * V_103 ;
F_69 (waiter, n, &waiters, list) {
if ( ! F_67 ( V_94 ) ) {
F_70 ( & V_94 -> V_104 ) ;
F_71 ( L_14 , V_94 ) ;
V_94 -> V_105 ( V_94 -> V_106 ) ;
F_18 ( V_94 ) ;
}
}
}
static inline int F_72 ( struct V_1 * V_2 ,
enum V_107 V_95 , bool V_108 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
F_73 ( & V_109 ) ;
if ( ! V_17 -> V_97 ) {
V_17 -> V_97 = F_74 ( sizeof( * V_17 -> V_97 ) , V_110 ) ;
if ( ! V_17 -> V_97 ) {
V_33 = - V_64 ;
goto V_111;
}
}
if ( V_108 ) {
if ( V_95 & V_96 )
V_17 -> V_97 -> V_112 ++ ;
if ( V_95 & V_100 )
V_17 -> V_97 -> V_113 ++ ;
} else {
if ( V_95 & V_96 )
V_17 -> V_97 -> V_98 ++ ;
if ( V_95 & V_100 )
V_17 -> V_97 -> V_101 ++ ;
F_68 () ;
}
V_111:
F_75 ( & V_109 ) ;
return V_33 ;
}
void F_76 ( void )
{
F_73 ( & V_109 ) ;
F_68 () ;
F_75 ( & V_109 ) ;
}
int F_77 ( struct V_1 * V_2 , enum V_107 V_95 )
{
return F_72 ( V_2 , V_95 , true ) ;
}
int F_78 ( struct V_1 * V_2 , enum V_107 V_95 )
{
return F_72 ( V_2 , V_95 , false ) ;
}
static void F_79 ( void * V_106 )
{
struct V_114 * * V_115 = V_106 ;
* V_115 = NULL ;
F_80 ( & V_116 ) ;
}
int F_81 ( struct V_1 * V_2 , enum V_107 V_95 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
if ( V_17 -> V_97 ) {
struct V_114 * V_115 = V_117 ;
struct V_93 * V_94 =
F_74 ( sizeof( * V_94 ) , V_25 ) ;
if ( ! V_94 ) {
return - V_64 ;
}
V_94 -> V_17 = V_17 ;
V_94 -> V_95 = V_95 ;
V_94 -> V_99 = V_17 -> V_97 -> V_112 ;
V_94 -> V_102 = V_17 -> V_97 -> V_113 ;
V_94 -> V_105 = F_79 ;
V_94 -> V_106 = & V_115 ;
F_73 ( & V_109 ) ;
if ( F_67 ( V_94 ) ) {
F_71 ( L_15 , V_94 ) ;
F_82 ( & V_94 -> V_104 , & V_118 ) ;
F_75 ( & V_109 ) ;
V_33 = F_83 ( V_116 ,
( V_115 == NULL ) ) ;
F_73 ( & V_109 ) ;
if ( V_115 ) {
F_71 ( L_16 , V_94 ) ;
F_70 ( & V_94 -> V_104 ) ;
V_115 = NULL ;
} else {
V_94 = NULL ;
}
}
F_75 ( & V_109 ) ;
if ( V_94 ) {
F_18 ( V_94 ) ;
}
}
return V_33 ;
}
int F_84 ( struct V_1 * V_2 , enum V_107 V_95 ,
void (* F_85)( void * V_106 ) , void * V_106 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
if ( V_17 -> V_97 ) {
struct V_93 * V_94 =
F_74 ( sizeof( * V_94 ) , V_110 ) ;
if ( ! V_94 ) {
return - V_64 ;
}
V_94 -> V_17 = V_17 ;
V_94 -> V_95 = V_95 ;
V_94 -> V_99 = V_17 -> V_97 -> V_112 ;
V_94 -> V_102 = V_17 -> V_97 -> V_113 ;
V_94 -> V_105 = F_85 ;
V_94 -> V_106 = V_106 ;
F_73 ( & V_109 ) ;
if ( F_67 ( V_94 ) ) {
F_71 ( L_15 , V_94 ) ;
F_82 ( & V_94 -> V_104 , & V_118 ) ;
F_75 ( & V_109 ) ;
return 0 ;
}
F_75 ( & V_109 ) ;
}
F_85 ( V_106 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , void * V_119 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_33 = 0 ;
F_73 ( & V_109 ) ;
if ( ( V_17 -> V_18 & V_120 ) && ! V_119 ) {
V_119 = F_74 ( sizeof( * V_17 -> V_97 ) , V_110 ) ;
if ( ! V_119 ) {
V_33 = - V_64 ;
goto V_111;
}
memcpy ( V_119 , V_17 -> V_97 , sizeof( * V_17 -> V_97 ) ) ;
V_17 -> V_18 &= ~ V_120 ;
V_17 -> V_97 = V_119 ;
} else if ( V_119 && ! ( V_17 -> V_18 & V_120 ) ) {
if ( V_17 -> V_97 ) {
memcpy ( V_119 , V_17 -> V_97 , sizeof( * V_17 -> V_97 ) ) ;
F_18 ( V_17 -> V_97 ) ;
}
V_17 -> V_18 |= V_120 ;
V_17 -> V_97 = V_119 ;
}
V_111:
F_75 ( & V_109 ) ;
return V_33 ;
}
int F_87 ( struct V_1 * V_2 )
{
return - V_83 ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_59 * V_7 = V_2 -> V_7 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_31 . V_32 ) {
F_89 ( V_2 ) ;
}
F_9 ( V_17 -> V_89 > 0 ) ;
if ( ! ( V_17 -> V_18 & V_121 ) ) {
if ( V_17 -> V_24 ) {
F_16 ( V_2 ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_90 ( V_7 -> V_7 , V_2 -> V_9 ,
V_17 -> V_50 , V_17 -> V_48 ) ;
} else if ( V_17 -> V_50 ) {
F_91 ( V_17 -> V_50 ) ;
}
}
if ( ! ( V_17 -> V_18 & V_120 ) ) {
F_18 ( V_17 -> V_97 ) ;
}
F_92 ( V_2 ) ;
F_18 ( V_2 ) ;
}
int F_46 ( struct V_59 * V_7 , struct V_72 * V_67 ,
union V_74 V_75 , T_7 V_18 , T_7 * V_80 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_93 ( V_7 , V_75 , V_18 ) ;
if ( ! V_2 )
return - V_64 ;
V_33 = F_94 ( V_67 , V_2 , V_80 ) ;
if ( V_33 ) {
F_92 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_33 ;
}
F_51 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_93 ( struct V_59 * V_7 ,
union V_74 V_75 , T_7 V_18 )
{
struct V_85 * V_86 = V_7 -> V_87 ;
struct V_16 * V_17 ;
struct V_1 * V_2 = NULL ;
T_1 V_9 ;
int V_33 ;
if ( V_18 & V_19 ) {
if ( ! V_11 ) {
F_12 ( V_7 -> V_7 , L_17 ) ;
goto V_60;
}
V_18 &= ~ V_79 ;
V_18 &= ~ ( V_122 | V_27 ) ;
V_18 |= V_26 ;
F_95 ( F_6 ( V_18 ) ,
& V_75 . V_123 . V_38 , & V_75 . V_123 . V_12 ) ;
V_9 = F_96 ( F_6 ( V_18 ) ,
V_75 . V_123 . V_38 , V_75 . V_123 . V_12 ) ;
} else {
V_9 = F_45 ( V_75 . V_78 ) ;
}
V_17 = F_74 ( sizeof( * V_17 ) , V_25 ) ;
if ( ! V_17 ) {
F_12 ( V_7 -> V_7 , L_18 ) ;
goto V_60;
}
V_2 = & V_17 -> V_124 ;
if ( ( V_18 & V_79 ) && ! V_86 -> V_88 ) {
V_17 -> V_50 = F_97 ( V_7 -> V_7 , V_9 ,
& V_17 -> V_48 , V_25 ) ;
if ( V_17 -> V_50 ) {
V_18 |= V_47 ;
}
}
V_17 -> V_18 = V_18 ;
if ( V_18 & V_19 ) {
V_17 -> V_38 = V_75 . V_123 . V_38 ;
V_17 -> V_12 = V_75 . V_123 . V_12 ;
}
if ( V_18 & ( V_47 | V_121 ) ) {
V_33 = F_98 ( V_7 , V_2 , V_9 ) ;
} else {
V_33 = F_99 ( V_7 , V_2 , V_9 ) ;
}
if ( V_33 ) {
goto V_60;
}
return V_2 ;
V_60:
if ( V_2 ) {
F_88 ( V_2 ) ;
}
return NULL ;
}
void F_100 ( struct V_59 * V_7 )
{
struct V_85 * V_86 = V_7 -> V_87 ;
const enum V_3 V_125 [] = {
V_126 , V_127 , V_128
} ;
int V_20 , V_129 , V_33 ;
V_33 = F_101 ( V_7 ) ;
if ( V_33 ) {
F_102 ( V_7 -> V_7 , L_19 ) ;
return;
}
V_11 = F_74 ( 3 * sizeof( * V_11 ) , V_25 ) ;
if ( ! V_11 ) {
F_102 ( V_7 -> V_7 , L_20 ) ;
return;
}
for ( V_20 = 0 ; V_20 < F_34 ( V_125 ) ; V_20 ++ ) {
T_8 V_130 = 1 , V_131 = V_10 >> V_20 ;
F_95 ( V_125 [ V_20 ] , & V_131 , & V_130 ) ;
V_11 [ V_20 ] . V_12 = V_130 ;
V_11 [ V_20 ] . V_55 = F_103 ( V_130 ) ;
V_11 [ V_20 ] . V_57 = F_104 ( V_125 [ V_20 ] ) >> V_15 ;
V_11 [ V_20 ] . V_54 = F_103 ( ( V_10 / V_130 ) >> V_20 ) ;
for ( V_129 = 0 ; V_129 < V_21 ; V_129 ++ ) {
struct V_5 * V_6 = & V_11 [ V_20 ] . V_6 [ V_129 ] ;
struct V_90 * V_56 =
F_56 ( V_125 [ V_20 ] , V_131 , V_130 ,
V_10 ) ;
if ( F_11 ( V_56 ) ) {
F_12 ( V_7 -> V_7 ,
L_21 ,
V_20 , V_129 , F_13 ( V_56 ) ) ;
return;
}
V_6 -> V_48 = F_59 ( V_56 ) ;
V_6 -> V_56 = V_56 ;
F_39 ( L_22 , V_20 , V_129 , V_131 , V_130 ,
V_6 -> V_48 ,
V_11 [ V_20 ] . V_57 << V_15 ) ;
}
}
V_86 -> V_88 = true ;
}
void F_105 ( struct V_59 * V_7 )
{
F_106 () ;
F_18 ( V_11 ) ;
}
