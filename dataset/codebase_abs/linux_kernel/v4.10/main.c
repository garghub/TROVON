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
V_6 -> V_15 = V_2 ;
V_2 -> V_16 = V_6 ;
F_9 ( & V_4 -> V_11 ) ;
return F_10 ( V_1 , V_2 ) ;
V_14:
F_9 ( & V_4 -> V_11 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_13 ( V_4 , V_2 ) ;
goto V_19;
}
V_17 = F_14 ( V_6 ) ;
F_15 ( V_6 , V_2 ) ;
F_16 ( V_4 , V_6 , L_2 ) ;
F_17 ( V_6 ) ;
V_2 -> V_16 = NULL ;
F_18 ( V_6 ) ;
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_19 ( struct V_2 * V_2 , char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
struct V_23 * V_24 = NULL ;
bool V_25 = ! ! ( V_2 -> V_26 & V_27 ) ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
if ( V_21 == 0 ) {
V_17 = 0 ;
goto V_19;
}
if ( V_20 == NULL ) {
V_17 = - V_28 ;
goto V_19;
}
V_24 = F_20 ( V_6 , V_2 ) ;
if ( V_24 )
goto V_29;
if ( * V_22 > 0 )
* V_22 = 0 ;
V_17 = F_21 ( V_6 , V_21 , V_2 ) ;
if ( V_17 && V_17 != - V_30 ) {
F_16 ( V_4 , V_6 , L_3 , V_17 ) ;
goto V_19;
}
if ( V_25 ) {
V_17 = - V_31 ;
goto V_19;
}
if ( V_17 == - V_30 &&
! F_22 ( V_6 , V_21 , V_32 , V_2 ) ) {
V_17 = - V_33 ;
goto V_19;
}
do {
F_9 ( & V_4 -> V_11 ) ;
if ( F_23 ( V_6 -> V_34 ,
( ! F_24 ( & V_6 -> V_35 ) ) ||
( ! F_25 ( V_6 ) ) ) ) {
if ( F_26 ( V_36 ) )
return - V_37 ;
return - V_38 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_25 ( V_6 ) ) {
V_17 = - V_10 ;
goto V_19;
}
V_24 = F_20 ( V_6 , V_2 ) ;
} while ( ! V_24 );
V_29:
if ( V_24 -> V_39 ) {
V_17 = V_24 -> V_39 ;
F_16 ( V_4 , V_6 , L_4 , V_17 ) ;
goto free;
}
F_16 ( V_4 , V_6 , L_5 ,
V_24 -> V_40 . V_41 , V_24 -> V_42 , * V_22 ) ;
if ( * V_22 >= V_24 -> V_42 ) {
V_17 = 0 ;
goto free;
}
V_21 = F_27 ( T_3 , V_21 , V_24 -> V_42 - * V_22 ) ;
if ( F_28 ( V_20 , V_24 -> V_40 . V_43 + * V_22 , V_21 ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_44 ;
goto free;
}
V_17 = V_21 ;
* V_22 += V_21 ;
if ( * V_22 < V_24 -> V_42 )
goto V_19;
free:
F_29 ( V_24 ) ;
* V_22 = 0 ;
V_19:
F_16 ( V_4 , V_6 , L_7 , V_17 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_30 ( struct V_2 * V_2 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_23 * V_24 ;
struct V_3 * V_4 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
if ( ! F_25 ( V_6 ) ) {
F_31 ( V_4 , V_6 , L_8 ) ;
V_17 = - V_10 ;
goto V_19;
}
if ( ! F_32 ( V_6 -> V_45 ) ) {
V_17 = - V_46 ;
goto V_19;
}
if ( V_21 > F_33 ( V_6 ) ) {
V_17 = - V_47 ;
goto V_19;
}
if ( V_21 == 0 ) {
V_17 = 0 ;
goto V_19;
}
* V_22 = 0 ;
V_24 = F_34 ( V_6 , V_21 , V_48 , V_2 ) ;
if ( ! V_24 ) {
V_17 = - V_33 ;
goto V_19;
}
V_17 = F_35 ( V_24 -> V_40 . V_43 , V_20 , V_21 ) ;
if ( V_17 ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_44 ;
F_29 ( V_24 ) ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_36 ( V_6 , V_24 ) ;
if ( ! V_17 )
V_17 = V_21 ;
goto V_19;
}
V_17 = F_37 ( V_6 , V_24 ) ;
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static int F_38 ( struct V_2 * V_2 ,
struct V_49 * V_43 )
{
struct V_3 * V_4 ;
struct V_50 * V_51 ;
struct V_52 * V_45 ;
struct V_5 * V_6 ;
int V_17 ;
V_6 = V_2 -> V_16 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 )
return - V_10 ;
if ( V_6 -> V_53 != V_54 &&
V_6 -> V_53 != V_55 )
return - V_30 ;
V_45 = F_39 ( V_4 , & V_43 -> V_56 ) ;
if ( ! V_45 ) {
F_4 ( V_4 -> V_4 , L_10 ,
& V_43 -> V_56 ) ;
V_17 = - V_46 ;
goto V_57;
}
if ( V_45 -> V_58 . V_59 ) {
bool V_60 = V_4 -> V_61 ?
! V_4 -> V_62 : ! V_4 -> V_63 ;
if ( V_60 ) {
F_4 ( V_4 -> V_4 , L_11 ,
& V_43 -> V_56 ) ;
V_17 = - V_46 ;
goto V_57;
}
}
F_4 ( V_4 -> V_4 , L_12 ,
V_45 -> V_64 ) ;
F_4 ( V_4 -> V_4 , L_13 ,
V_45 -> V_58 . V_65 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_45 -> V_58 . V_66 ) ;
if ( F_40 ( V_43 -> V_56 , V_67 ) == 0 ) {
F_4 ( V_4 -> V_4 , L_15 ) ;
if ( ! F_25 ( & V_4 -> V_18 ) ) {
V_17 = - V_10 ;
goto V_57;
}
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_68 ++ ;
V_2 -> V_16 = & V_4 -> V_18 ;
V_51 = & V_43 -> V_69 ;
V_51 -> V_66 = V_45 -> V_58 . V_66 ;
V_51 -> V_65 = V_45 -> V_58 . V_65 ;
V_17 = V_4 -> V_18 . V_39 ;
goto V_57;
}
V_51 = & V_43 -> V_69 ;
V_51 -> V_66 = V_45 -> V_58 . V_66 ;
V_51 -> V_65 = V_45 -> V_58 . V_65 ;
F_4 ( V_4 -> V_4 , L_16 ) ;
V_17 = F_41 ( V_6 , V_45 , V_2 ) ;
V_57:
F_42 ( V_45 ) ;
return V_17 ;
}
static int F_43 ( const struct V_2 * V_2 , T_5 V_70 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( V_70 != V_71 &&
V_70 != V_72 )
return - V_73 ;
return F_44 ( V_6 , V_2 , ( V_74 ) V_70 ) ;
}
static int F_45 ( const struct V_2 * V_2 , T_5 * V_75 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
bool V_76 ;
bool V_77 = ( V_2 -> V_26 & V_27 ) == 0 ;
int V_17 ;
V_17 = F_46 ( V_6 , V_77 , & V_76 ) ;
if ( V_17 )
return V_17 ;
* V_75 = V_76 ? 1 : 0 ;
return 0 ;
}
static long F_47 ( struct V_2 * V_2 , unsigned int V_78 , unsigned long V_43 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_49 V_79 ;
T_5 V_75 , V_80 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( V_4 -> V_4 , L_17 , V_78 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
switch ( V_78 ) {
case V_81 :
F_4 ( V_4 -> V_4 , L_18 ) ;
if ( F_35 ( & V_79 , ( char T_2 * ) V_43 ,
sizeof( struct V_49 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_44 ;
goto V_19;
}
V_17 = F_38 ( V_2 , & V_79 ) ;
if ( V_17 )
goto V_19;
if ( F_28 ( ( char T_2 * ) V_43 , & V_79 ,
sizeof( struct V_49 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_44 ;
goto V_19;
}
break;
case V_82 :
F_4 ( V_4 -> V_4 , L_19 ) ;
if ( F_35 ( & V_80 ,
( char T_2 * ) V_43 , sizeof( V_80 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_44 ;
goto V_19;
}
V_17 = F_43 ( V_2 , V_80 ) ;
break;
case V_83 :
F_4 ( V_4 -> V_4 , L_20 ) ;
V_17 = F_45 ( V_2 , & V_75 ) ;
if ( V_17 )
goto V_19;
F_4 ( V_4 -> V_4 , L_21 ) ;
if ( F_28 ( ( char T_2 * ) V_43 ,
& V_75 , sizeof( V_75 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_44 ;
goto V_19;
}
break;
default:
F_48 ( V_4 -> V_4 , L_22 , V_78 ) ;
V_17 = - V_84 ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static long F_49 ( struct V_2 * V_2 ,
unsigned int V_78 , unsigned long V_43 )
{
return F_47 ( V_2 , V_78 , ( unsigned long ) F_50 ( V_43 ) ) ;
}
static unsigned int F_51 ( struct V_2 * V_2 , T_6 * V_85 )
{
unsigned long V_86 = F_52 ( V_85 ) ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
unsigned int V_87 = 0 ;
bool V_88 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_89 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
V_88 = V_6 -> V_88 && ( V_86 & V_90 ) ;
if ( V_4 -> V_12 != V_13 ||
! F_25 ( V_6 ) ) {
V_87 = V_89 ;
goto V_19;
}
if ( V_88 ) {
F_53 ( V_2 , & V_6 -> V_91 , V_85 ) ;
if ( V_6 -> V_76 )
V_87 |= V_90 ;
}
if ( V_6 == & V_4 -> V_18 ) {
V_87 |= F_54 ( V_2 , V_85 ) ;
goto V_19;
}
if ( V_86 & ( V_92 | V_93 ) ) {
F_53 ( V_2 , & V_6 -> V_34 , V_85 ) ;
if ( ! F_24 ( & V_6 -> V_35 ) )
V_87 |= V_92 | V_93 ;
else
F_21 ( V_6 , F_33 ( V_6 ) , V_2 ) ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_87 ;
}
static int F_55 ( int V_94 , struct V_2 * V_2 , int V_95 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( ! F_25 ( V_6 ) )
return - V_10 ;
return F_56 ( V_94 , V_2 , V_95 , & V_6 -> V_96 ) ;
}
static T_1 F_57 ( struct V_97 * V_97 ,
struct V_98 * V_99 , char * V_40 )
{
struct V_3 * V_4 = F_58 ( V_97 ) ;
struct V_100 V_101 ;
int V_7 , V_102 ;
T_1 V_103 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_7 = V_100 ( V_4 , & V_101 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_7 ) {
F_48 ( V_97 , L_23 , V_7 ) ;
return V_7 ;
}
for ( V_102 = 0 ; V_102 < V_101 . V_104 ; V_102 ++ )
V_103 += F_59 ( V_40 + V_103 , V_105 - V_103 , L_24 ,
V_101 . V_39 [ V_102 ] ) ;
return V_103 ;
}
static T_1 F_60 ( struct V_97 * V_97 ,
struct V_98 * V_99 , char * V_40 )
{
struct V_3 * V_4 = F_58 ( V_97 ) ;
struct V_106 V_107 ;
F_3 ( & V_4 -> V_11 ) ;
V_107 = V_4 -> V_108 ;
F_9 ( & V_4 -> V_11 ) ;
return sprintf ( V_40 , L_25 , V_107 . V_109 , V_107 . V_110 ) ;
}
static T_1 F_61 ( struct V_97 * V_97 ,
struct V_98 * V_99 , char * V_40 )
{
return sprintf ( V_40 , L_25 , V_111 , V_112 ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
int V_113 ;
F_3 ( & V_114 ) ;
V_113 = F_63 ( & V_115 , V_4 , 0 , V_116 , V_117 ) ;
if ( V_113 >= 0 )
V_4 -> V_118 = V_113 ;
else if ( V_113 == - V_119 )
F_48 ( V_4 -> V_4 , L_26 ) ;
F_9 ( & V_114 ) ;
return V_113 ;
}
static void F_64 ( struct V_3 * V_4 )
{
F_3 ( & V_114 ) ;
F_65 ( & V_115 , V_4 -> V_118 ) ;
F_9 ( & V_114 ) ;
}
int F_66 ( struct V_3 * V_4 , struct V_97 * V_120 )
{
struct V_97 * V_121 ;
int V_113 , V_122 ;
V_113 = F_62 ( V_4 ) ;
if ( V_113 < 0 )
return V_113 ;
V_122 = F_67 ( F_68 ( V_123 ) , V_4 -> V_118 ) ;
F_69 ( & V_4 -> V_9 , & V_124 ) ;
V_4 -> V_9 . V_125 = V_120 -> V_126 -> V_125 ;
V_113 = F_70 ( & V_4 -> V_9 , V_122 , 1 ) ;
if ( V_113 ) {
F_48 ( V_120 , L_27 ,
F_68 ( V_123 ) , V_4 -> V_118 ) ;
goto V_127;
}
V_121 = F_71 ( V_128 , V_120 , V_122 ,
V_4 , V_129 ,
L_28 , V_4 -> V_118 ) ;
if ( F_7 ( V_121 ) ) {
F_48 ( V_120 , L_29 ,
F_68 ( V_123 ) , V_4 -> V_118 ) ;
V_113 = F_8 ( V_121 ) ;
goto V_130;
}
V_113 = F_72 ( V_4 , F_73 ( V_121 ) ) ;
if ( V_113 ) {
F_48 ( V_121 , L_30 , V_113 ) ;
goto V_131;
}
return 0 ;
V_131:
F_74 ( V_128 , V_122 ) ;
V_130:
F_75 ( & V_4 -> V_9 ) ;
V_127:
F_64 ( V_4 ) ;
return V_113 ;
}
void F_76 ( struct V_3 * V_4 )
{
int V_122 ;
V_122 = V_4 -> V_9 . V_4 ;
F_75 ( & V_4 -> V_9 ) ;
F_77 ( V_4 ) ;
F_74 ( V_128 , V_122 ) ;
F_64 ( V_4 ) ;
}
static int T_7 F_78 ( void )
{
int V_113 ;
V_128 = F_79 ( V_132 , L_31 ) ;
if ( F_7 ( V_128 ) ) {
F_80 ( L_32 ) ;
V_113 = F_8 ( V_128 ) ;
goto V_7;
}
V_113 = F_81 ( & V_123 , 0 , V_116 , L_31 ) ;
if ( V_113 < 0 ) {
F_80 ( L_33 ) ;
goto V_133;
}
V_113 = F_82 () ;
if ( V_113 < 0 ) {
F_80 ( L_34 ) ;
goto V_134;
}
return 0 ;
V_134:
F_83 ( V_123 , V_116 ) ;
V_133:
F_84 ( V_128 ) ;
V_7:
return V_113 ;
}
static void T_8 F_85 ( void )
{
F_83 ( V_123 , V_116 ) ;
F_84 ( V_128 ) ;
F_86 () ;
}
