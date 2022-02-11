static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_1 -> V_8 , struct V_3 , V_9 ) ;
if ( ! V_4 )
return - V_10 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
F_4 ( V_4 -> V_4 , L_1 ,
F_5 ( V_4 -> V_12 ) ) ;
V_7 = - V_10 ;
goto V_14;
}
V_6 = F_6 ( V_4 ) ;
if ( F_7 ( V_6 ) ) {
V_7 = F_8 ( V_6 ) ;
goto V_14;
}
V_2 -> V_15 = V_6 ;
F_9 ( & V_4 -> V_11 ) ;
return F_10 ( V_1 , V_2 ) ;
V_14:
F_9 ( & V_4 -> V_11 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
struct V_3 * V_4 ;
int V_16 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_17 ) {
V_16 = F_13 ( V_4 , V_2 ) ;
goto V_18;
}
V_16 = F_14 ( V_6 ) ;
F_15 ( V_6 , V_2 ) ;
F_16 ( V_4 , V_6 , L_2 ) ;
F_17 ( V_6 ) ;
V_2 -> V_15 = NULL ;
F_18 ( V_6 ) ;
V_18:
F_9 ( & V_4 -> V_11 ) ;
return V_16 ;
}
static T_1 F_19 ( struct V_2 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
struct V_3 * V_4 ;
struct V_22 * V_23 = NULL ;
int V_16 ;
int V_7 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_16 = - V_10 ;
goto V_18;
}
if ( V_20 == 0 ) {
V_16 = 0 ;
goto V_18;
}
if ( V_19 == NULL ) {
V_16 = - V_24 ;
goto V_18;
}
if ( V_6 == & V_4 -> V_17 ) {
V_16 = F_20 ( V_4 , V_2 , V_19 , V_20 , V_21 ) ;
goto V_18;
}
V_23 = F_21 ( V_6 , V_2 ) ;
if ( V_23 )
goto V_25;
if ( * V_21 > 0 )
* V_21 = 0 ;
V_7 = F_22 ( V_6 , V_20 , V_2 ) ;
if ( V_7 && V_7 != - V_26 ) {
F_16 ( V_4 , V_6 , L_3 , V_7 ) ;
V_16 = V_7 ;
goto V_18;
}
if ( F_23 ( & V_6 -> V_27 ) && ! F_24 ( & V_6 -> V_28 ) ) {
if ( V_2 -> V_29 & V_30 ) {
V_16 = - V_31 ;
goto V_18;
}
F_9 ( & V_4 -> V_11 ) ;
if ( F_25 ( V_6 -> V_28 ,
( ! F_23 ( & V_6 -> V_27 ) ) ||
( ! F_26 ( V_6 ) ) ) ) {
if ( F_27 ( V_32 ) )
return - V_33 ;
return - V_34 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_26 ( V_6 ) ) {
V_16 = - V_26 ;
goto V_18;
}
}
V_23 = F_21 ( V_6 , V_2 ) ;
if ( ! V_23 ) {
V_16 = 0 ;
goto V_18;
}
V_25:
if ( V_23 -> V_35 ) {
V_16 = V_23 -> V_35 ;
F_16 ( V_4 , V_6 , L_4 , V_16 ) ;
goto free;
}
F_16 ( V_4 , V_6 , L_5 ,
V_23 -> V_36 . V_37 , V_23 -> V_38 , * V_21 ) ;
if ( * V_21 >= V_23 -> V_38 ) {
V_16 = 0 ;
goto free;
}
V_20 = F_28 ( T_3 , V_20 , V_23 -> V_38 - * V_21 ) ;
if ( F_29 ( V_19 , V_23 -> V_36 . V_39 + * V_21 , V_20 ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_16 = - V_40 ;
goto free;
}
V_16 = V_20 ;
* V_21 += V_20 ;
if ( * V_21 < V_23 -> V_38 )
goto V_18;
free:
F_30 ( V_23 ) ;
* V_21 = 0 ;
V_18:
F_16 ( V_4 , V_6 , L_7 , V_16 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_16 ;
}
static T_1 F_31 ( struct V_2 * V_2 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
struct V_22 * V_23 ;
struct V_3 * V_4 ;
int V_16 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_16 = - V_10 ;
goto V_18;
}
if ( ! F_26 ( V_6 ) ) {
F_32 ( V_4 , V_6 , L_8 ) ;
V_16 = - V_10 ;
goto V_18;
}
if ( ! F_33 ( V_6 -> V_41 ) ) {
V_16 = - V_42 ;
goto V_18;
}
if ( V_20 > F_34 ( V_6 ) ) {
V_16 = - V_43 ;
goto V_18;
}
if ( V_20 == 0 ) {
V_16 = 0 ;
goto V_18;
}
* V_21 = 0 ;
V_23 = F_35 ( V_6 , V_20 , V_44 , V_2 ) ;
if ( ! V_23 ) {
V_16 = - V_45 ;
goto V_18;
}
V_16 = F_36 ( V_23 -> V_36 . V_39 , V_19 , V_20 ) ;
if ( V_16 ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_16 = - V_40 ;
F_30 ( V_23 ) ;
goto V_18;
}
if ( V_6 == & V_4 -> V_17 ) {
V_16 = F_37 ( V_6 , V_23 ) ;
if ( ! V_16 )
V_16 = V_20 ;
goto V_18;
}
V_16 = F_38 ( V_6 , V_23 , false ) ;
V_18:
F_9 ( & V_4 -> V_11 ) ;
return V_16 ;
}
static int F_39 ( struct V_2 * V_2 ,
struct V_46 * V_39 )
{
struct V_3 * V_4 ;
struct V_47 * V_48 ;
struct V_49 * V_41 ;
struct V_5 * V_6 ;
int V_16 ;
V_6 = V_2 -> V_15 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 )
return - V_10 ;
if ( V_6 -> V_50 != V_51 &&
V_6 -> V_50 != V_52 )
return - V_26 ;
V_41 = F_40 ( V_4 , & V_39 -> V_53 ) ;
if ( ! V_41 ) {
F_4 ( V_4 -> V_4 , L_10 ,
& V_39 -> V_53 ) ;
V_16 = - V_42 ;
goto V_54;
}
if ( V_41 -> V_55 . V_56 ) {
bool V_57 = V_4 -> V_58 ?
! V_4 -> V_59 : ! V_4 -> V_60 ;
if ( V_57 ) {
F_4 ( V_4 -> V_4 , L_11 ,
& V_39 -> V_53 ) ;
V_16 = - V_42 ;
goto V_54;
}
}
F_4 ( V_4 -> V_4 , L_12 ,
V_41 -> V_61 ) ;
F_4 ( V_4 -> V_4 , L_13 ,
V_41 -> V_55 . V_62 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_41 -> V_55 . V_63 ) ;
if ( F_41 ( V_39 -> V_53 , V_64 ) == 0 ) {
F_4 ( V_4 -> V_4 , L_15 ) ;
if ( ! F_26 ( & V_4 -> V_17 ) ) {
V_16 = - V_10 ;
goto V_54;
}
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_65 ++ ;
V_2 -> V_15 = & V_4 -> V_17 ;
V_48 = & V_39 -> V_66 ;
V_48 -> V_63 = V_41 -> V_55 . V_63 ;
V_48 -> V_62 = V_41 -> V_55 . V_62 ;
V_16 = V_4 -> V_17 . V_35 ;
goto V_54;
}
V_48 = & V_39 -> V_66 ;
V_48 -> V_63 = V_41 -> V_55 . V_63 ;
V_48 -> V_62 = V_41 -> V_55 . V_62 ;
F_4 ( V_4 -> V_4 , L_16 ) ;
V_16 = F_42 ( V_6 , V_41 , V_2 ) ;
V_54:
F_43 ( V_41 ) ;
return V_16 ;
}
static int F_44 ( const struct V_2 * V_2 , T_5 V_67 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
if ( V_67 != V_68 &&
V_67 != V_69 )
return - V_70 ;
return F_45 ( V_6 , V_2 , ( V_71 ) V_67 ) ;
}
static int F_46 ( const struct V_2 * V_2 , T_5 * V_72 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
bool V_73 ;
bool V_74 = ( V_2 -> V_29 & V_30 ) == 0 ;
int V_16 ;
V_16 = F_47 ( V_6 , V_74 , & V_73 ) ;
if ( V_16 )
return V_16 ;
* V_72 = V_73 ? 1 : 0 ;
return 0 ;
}
static long F_48 ( struct V_2 * V_2 , unsigned int V_75 , unsigned long V_39 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_15 ;
struct V_46 V_76 ;
T_5 V_72 , V_77 ;
int V_16 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( V_4 -> V_4 , L_17 , V_75 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_16 = - V_10 ;
goto V_18;
}
switch ( V_75 ) {
case V_78 :
F_4 ( V_4 -> V_4 , L_18 ) ;
if ( F_36 ( & V_76 , ( char T_2 * ) V_39 ,
sizeof( struct V_46 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_16 = - V_40 ;
goto V_18;
}
V_16 = F_39 ( V_2 , & V_76 ) ;
if ( V_16 )
goto V_18;
if ( F_29 ( ( char T_2 * ) V_39 , & V_76 ,
sizeof( struct V_46 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_16 = - V_40 ;
goto V_18;
}
break;
case V_79 :
F_4 ( V_4 -> V_4 , L_19 ) ;
if ( F_36 ( & V_77 ,
( char T_2 * ) V_39 , sizeof( V_77 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_16 = - V_40 ;
goto V_18;
}
V_16 = F_44 ( V_2 , V_77 ) ;
break;
case V_80 :
F_4 ( V_4 -> V_4 , L_20 ) ;
V_16 = F_46 ( V_2 , & V_72 ) ;
if ( V_16 )
goto V_18;
F_4 ( V_4 -> V_4 , L_21 ) ;
if ( F_29 ( ( char T_2 * ) V_39 ,
& V_72 , sizeof( V_72 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_16 = - V_40 ;
goto V_18;
}
break;
default:
F_49 ( V_4 -> V_4 , L_22 , V_75 ) ;
V_16 = - V_81 ;
}
V_18:
F_9 ( & V_4 -> V_11 ) ;
return V_16 ;
}
static long F_50 ( struct V_2 * V_2 ,
unsigned int V_75 , unsigned long V_39 )
{
return F_48 ( V_2 , V_75 , ( unsigned long ) F_51 ( V_39 ) ) ;
}
static unsigned int F_52 ( struct V_2 * V_2 , T_6 * V_82 )
{
unsigned long V_83 = F_53 ( V_82 ) ;
struct V_5 * V_6 = V_2 -> V_15 ;
struct V_3 * V_4 ;
unsigned int V_84 = 0 ;
bool V_85 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_86 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
V_85 = V_6 -> V_85 && ( V_83 & V_87 ) ;
if ( V_4 -> V_12 != V_13 ||
! F_26 ( V_6 ) ) {
V_84 = V_86 ;
goto V_18;
}
if ( V_6 == & V_4 -> V_17 ) {
V_84 = F_54 ( V_4 , V_2 , V_82 ) ;
goto V_18;
}
if ( V_85 ) {
F_55 ( V_2 , & V_6 -> V_88 , V_82 ) ;
if ( V_6 -> V_73 )
V_84 |= V_87 ;
}
if ( V_83 & ( V_89 | V_90 ) ) {
F_55 ( V_2 , & V_6 -> V_28 , V_82 ) ;
if ( ! F_23 ( & V_6 -> V_27 ) )
V_84 |= V_89 | V_90 ;
else
F_22 ( V_6 , 0 , V_2 ) ;
}
V_18:
F_9 ( & V_4 -> V_11 ) ;
return V_84 ;
}
static int F_56 ( int V_91 , struct V_2 * V_2 , int V_92 )
{
struct V_5 * V_6 = V_2 -> V_15 ;
if ( ! F_26 ( V_6 ) )
return - V_10 ;
return F_57 ( V_91 , V_2 , V_92 , & V_6 -> V_93 ) ;
}
static T_1 F_58 ( struct V_94 * V_94 ,
struct V_95 * V_96 , char * V_36 )
{
struct V_3 * V_4 = F_59 ( V_94 ) ;
struct V_97 V_98 ;
int V_7 , V_99 ;
T_1 V_100 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_7 = V_97 ( V_4 , & V_98 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_7 ) {
F_49 ( V_94 , L_23 , V_7 ) ;
return V_7 ;
}
for ( V_99 = 0 ; V_99 < V_98 . V_101 ; V_99 ++ )
V_100 += F_60 ( V_36 + V_100 , V_102 - V_100 , L_24 ,
V_98 . V_35 [ V_99 ] ) ;
return V_100 ;
}
static int F_61 ( struct V_3 * V_4 )
{
int V_103 ;
F_3 ( & V_104 ) ;
V_103 = F_62 ( & V_105 , V_4 , 0 , V_106 , V_107 ) ;
if ( V_103 >= 0 )
V_4 -> V_108 = V_103 ;
else if ( V_103 == - V_109 )
F_49 ( V_4 -> V_4 , L_25 ) ;
F_9 ( & V_104 ) ;
return V_103 ;
}
static void F_63 ( struct V_3 * V_4 )
{
F_3 ( & V_104 ) ;
F_64 ( & V_105 , V_4 -> V_108 ) ;
F_9 ( & V_104 ) ;
}
int F_65 ( struct V_3 * V_4 , struct V_94 * V_110 )
{
struct V_94 * V_111 ;
int V_103 , V_112 ;
V_103 = F_61 ( V_4 ) ;
if ( V_103 < 0 )
return V_103 ;
V_112 = F_66 ( F_67 ( V_113 ) , V_4 -> V_108 ) ;
F_68 ( & V_4 -> V_9 , & V_114 ) ;
V_4 -> V_9 . V_115 = V_110 -> V_116 -> V_115 ;
V_103 = F_69 ( & V_4 -> V_9 , V_112 , 1 ) ;
if ( V_103 ) {
F_49 ( V_110 , L_26 ,
F_67 ( V_113 ) , V_4 -> V_108 ) ;
goto V_117;
}
V_111 = F_70 ( V_118 , V_110 , V_112 ,
V_4 , V_119 ,
L_27 , V_4 -> V_108 ) ;
if ( F_7 ( V_111 ) ) {
F_49 ( V_110 , L_28 ,
F_67 ( V_113 ) , V_4 -> V_108 ) ;
V_103 = F_8 ( V_111 ) ;
goto V_120;
}
V_103 = F_71 ( V_4 , F_72 ( V_111 ) ) ;
if ( V_103 ) {
F_49 ( V_111 , L_29 , V_103 ) ;
goto V_121;
}
return 0 ;
V_121:
F_73 ( V_118 , V_112 ) ;
V_120:
F_74 ( & V_4 -> V_9 ) ;
V_117:
F_63 ( V_4 ) ;
return V_103 ;
}
void F_75 ( struct V_3 * V_4 )
{
int V_112 ;
V_112 = V_4 -> V_9 . V_4 ;
F_74 ( & V_4 -> V_9 ) ;
F_76 ( V_4 ) ;
F_73 ( V_118 , V_112 ) ;
F_63 ( V_4 ) ;
}
static int T_7 F_77 ( void )
{
int V_103 ;
V_118 = F_78 ( V_122 , L_30 ) ;
if ( F_7 ( V_118 ) ) {
F_79 ( L_31 ) ;
V_103 = F_8 ( V_118 ) ;
goto V_7;
}
V_103 = F_80 ( & V_113 , 0 , V_106 , L_30 ) ;
if ( V_103 < 0 ) {
F_79 ( L_32 ) ;
goto V_123;
}
V_103 = F_81 () ;
if ( V_103 < 0 ) {
F_79 ( L_33 ) ;
goto V_124;
}
return 0 ;
V_124:
F_82 ( V_113 , V_106 ) ;
V_123:
F_83 ( V_118 ) ;
V_7:
return V_103 ;
}
static void T_8 F_84 ( void )
{
F_82 ( V_113 , V_106 ) ;
F_83 ( V_118 ) ;
F_85 () ;
}
