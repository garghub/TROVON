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
V_6 = F_6 ( V_4 , V_15 ) ;
if ( F_7 ( V_6 ) ) {
V_7 = F_8 ( V_6 ) ;
goto V_14;
}
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
int V_17 ;
int V_7 ;
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
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_20 ( V_4 , V_2 , V_20 , V_21 , V_22 ) ;
goto V_19;
}
V_24 = F_21 ( V_6 , V_2 ) ;
if ( V_24 ) {
if ( V_24 -> V_25 > * V_22 )
goto V_26;
if ( V_24 -> V_25 > 0 && V_24 -> V_25 <= * V_22 ) {
V_17 = 0 ;
goto free;
}
if ( V_24 -> V_25 == 0 && * V_22 > 0 )
* V_22 = 0 ;
} else if ( * V_22 > 0 ) {
* V_22 = 0 ;
}
V_7 = F_22 ( V_6 , V_21 , V_2 ) ;
if ( V_7 && V_7 != - V_27 ) {
F_16 ( V_4 , V_6 , L_3 , V_7 ) ;
V_17 = V_7 ;
goto V_19;
}
if ( F_23 ( & V_6 -> V_28 ) && ! F_24 ( & V_6 -> V_29 ) ) {
if ( V_2 -> V_30 & V_31 ) {
V_17 = - V_32 ;
goto V_19;
}
F_9 ( & V_4 -> V_11 ) ;
if ( F_25 ( V_6 -> V_29 ,
( ! F_23 ( & V_6 -> V_28 ) ) ||
( ! F_26 ( V_6 ) ) ) ) {
if ( F_27 ( V_33 ) )
return - V_34 ;
return - V_35 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_26 ( V_6 ) ) {
V_17 = - V_27 ;
goto V_19;
}
}
V_24 = F_21 ( V_6 , V_2 ) ;
if ( ! V_24 ) {
if ( F_28 ( V_6 ) && V_4 -> V_36 ) {
V_24 = F_21 ( V_6 , NULL ) ;
if ( V_24 )
goto V_26;
}
V_17 = 0 ;
goto V_19;
}
V_26:
if ( V_24 -> V_37 ) {
V_17 = V_24 -> V_37 ;
F_16 ( V_4 , V_6 , L_4 , V_17 ) ;
goto free;
}
F_16 ( V_4 , V_6 , L_5 ,
V_24 -> V_38 . V_39 , V_24 -> V_25 ) ;
if ( V_21 == 0 || V_20 == NULL || * V_22 > V_24 -> V_25 ) {
V_17 = - V_40 ;
goto free;
}
V_21 = F_29 ( T_3 , V_21 , V_24 -> V_25 - * V_22 ) ;
if ( F_30 ( V_20 , V_24 -> V_38 . V_41 + * V_22 , V_21 ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_42 ;
goto free;
}
V_17 = V_21 ;
* V_22 += V_21 ;
if ( ( unsigned long ) * V_22 < V_24 -> V_25 )
goto V_19;
free:
F_31 ( V_24 ) ;
V_19:
F_16 ( V_4 , V_6 , L_7 , V_17 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_32 ( struct V_2 * V_2 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_23 * V_43 = NULL ;
struct V_3 * V_4 ;
unsigned long V_44 = 0 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_19;
}
if ( ! F_26 ( V_6 ) ) {
F_33 ( V_4 , V_6 , L_8 ) ;
V_17 = - V_10 ;
goto V_19;
}
if ( ! F_34 ( V_6 -> V_45 ) ) {
V_17 = - V_46 ;
goto V_19;
}
if ( V_21 > F_35 ( V_6 ) ) {
V_17 = - V_47 ;
goto V_19;
}
if ( V_21 == 0 ) {
V_17 = 0 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_43 = F_36 ( V_4 , V_2 ) ;
if ( V_43 ) {
V_44 = V_43 -> V_48 +
F_37 ( V_49 ) ;
if ( F_38 ( V_50 , V_44 ) ) {
* V_22 = 0 ;
F_31 ( V_43 ) ;
V_43 = NULL ;
}
}
}
* V_22 = 0 ;
V_43 = F_39 ( V_6 , V_21 , V_51 , V_2 ) ;
if ( ! V_43 ) {
V_17 = - V_52 ;
goto V_19;
}
V_17 = F_40 ( V_43 -> V_38 . V_41 , V_20 , V_21 ) ;
if ( V_17 ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_42 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_17 = F_41 ( V_6 , V_43 ) ;
if ( V_17 ) {
F_42 ( V_4 -> V_4 ,
L_10 , V_17 ) ;
goto V_19;
}
F_9 ( & V_4 -> V_11 ) ;
return V_21 ;
}
V_17 = F_43 ( V_6 , V_43 , false ) ;
V_19:
F_9 ( & V_4 -> V_11 ) ;
if ( V_17 < 0 )
F_31 ( V_43 ) ;
return V_17 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_53 * V_41 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
struct V_56 * V_45 ;
struct V_5 * V_6 ;
int V_17 ;
V_6 = V_2 -> V_16 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 )
return - V_10 ;
if ( V_6 -> V_57 != V_58 &&
V_6 -> V_57 != V_59 )
return - V_27 ;
V_45 = F_45 ( V_4 , & V_41 -> V_60 ) ;
if ( ! V_45 ||
( V_45 -> V_61 . V_62 && ! V_4 -> V_36 ) ) {
F_4 ( V_4 -> V_4 , L_11 ,
& V_41 -> V_60 ) ;
F_46 ( V_45 ) ;
return - V_46 ;
}
F_4 ( V_4 -> V_4 , L_12 ,
V_45 -> V_63 ) ;
F_4 ( V_4 -> V_4 , L_13 ,
V_45 -> V_61 . V_64 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_45 -> V_61 . V_65 ) ;
if ( F_47 ( V_41 -> V_60 , V_66 ) == 0 ) {
F_4 ( V_4 -> V_4 , L_15 ) ;
if ( ! F_26 ( & V_4 -> V_18 ) ) {
V_17 = - V_10 ;
goto V_67;
}
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
V_6 = NULL ;
V_4 -> V_68 ++ ;
V_2 -> V_16 = & V_4 -> V_18 ;
V_55 = & V_41 -> V_69 ;
V_55 -> V_65 = V_45 -> V_61 . V_65 ;
V_55 -> V_64 = V_45 -> V_61 . V_64 ;
V_17 = V_4 -> V_18 . V_37 ;
goto V_67;
}
V_55 = & V_41 -> V_69 ;
V_55 -> V_65 = V_45 -> V_61 . V_65 ;
V_55 -> V_64 = V_45 -> V_61 . V_64 ;
F_4 ( V_4 -> V_4 , L_16 ) ;
V_17 = F_48 ( V_6 , V_45 , V_2 ) ;
V_67:
F_46 ( V_45 ) ;
return V_17 ;
}
static int F_49 ( struct V_2 * V_2 , T_5 V_70 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( V_70 != V_71 &&
V_70 != V_72 )
return - V_73 ;
return F_50 ( V_6 , V_2 , ( V_74 ) V_70 ) ;
}
static int F_51 ( struct V_2 * V_2 , T_5 * V_75 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
bool V_76 ;
bool V_77 = ( V_2 -> V_30 & V_31 ) == 0 ;
int V_17 ;
V_17 = F_52 ( V_6 , V_77 , & V_76 ) ;
if ( V_17 )
return V_17 ;
* V_75 = V_76 ? 1 : 0 ;
return 0 ;
}
static long F_53 ( struct V_2 * V_2 , unsigned int V_78 , unsigned long V_41 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_53 V_79 ;
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
if ( F_40 ( & V_79 , ( char T_2 * ) V_41 ,
sizeof( struct V_53 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_42 ;
goto V_19;
}
V_17 = F_44 ( V_2 , & V_79 ) ;
if ( V_17 )
goto V_19;
if ( F_30 ( ( char T_2 * ) V_41 , & V_79 ,
sizeof( struct V_53 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_42 ;
goto V_19;
}
break;
case V_82 :
F_4 ( V_4 -> V_4 , L_19 ) ;
if ( F_40 ( & V_80 ,
( char T_2 * ) V_41 , sizeof( V_80 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_42 ;
goto V_19;
}
V_17 = F_49 ( V_2 , V_80 ) ;
break;
case V_83 :
F_4 ( V_4 -> V_4 , L_20 ) ;
V_17 = F_51 ( V_2 , & V_75 ) ;
if ( V_17 )
goto V_19;
F_4 ( V_4 -> V_4 , L_21 ) ;
if ( F_30 ( ( char T_2 * ) V_41 ,
& V_75 , sizeof( V_75 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_42 ;
goto V_19;
}
break;
default:
F_42 ( V_4 -> V_4 , L_22 , V_78 ) ;
V_17 = - V_84 ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static long F_54 ( struct V_2 * V_2 ,
unsigned int V_78 , unsigned long V_41 )
{
return F_53 ( V_2 , V_78 , ( unsigned long ) F_55 ( V_41 ) ) ;
}
static unsigned int F_56 ( struct V_2 * V_2 , T_6 * V_85 )
{
unsigned long V_86 = F_57 ( V_85 ) ;
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
! F_26 ( V_6 ) ) {
V_87 = V_89 ;
goto V_19;
}
if ( V_6 == & V_4 -> V_18 ) {
V_87 = F_58 ( V_4 , V_2 , V_85 ) ;
goto V_19;
}
if ( V_88 ) {
F_59 ( V_2 , & V_6 -> V_91 , V_85 ) ;
if ( V_6 -> V_76 )
V_87 |= V_90 ;
}
if ( V_86 & ( V_92 | V_93 ) ) {
F_59 ( V_2 , & V_6 -> V_29 , V_85 ) ;
if ( ! F_23 ( & V_6 -> V_28 ) )
V_87 |= V_92 | V_93 ;
else
F_22 ( V_6 , 0 , V_2 ) ;
}
V_19:
F_9 ( & V_4 -> V_11 ) ;
return V_87 ;
}
static int F_60 ( int V_94 , struct V_2 * V_2 , int V_95 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( ! F_26 ( V_6 ) )
return - V_10 ;
return F_61 ( V_94 , V_2 , V_95 , & V_6 -> V_96 ) ;
}
static T_1 F_62 ( struct V_97 * V_97 ,
struct V_98 * V_99 , char * V_38 )
{
struct V_3 * V_4 = F_63 ( V_97 ) ;
struct V_100 V_101 ;
int V_7 , V_102 ;
T_1 V_103 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_7 = V_100 ( V_4 , & V_101 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_7 ) {
F_42 ( V_97 , L_23 , V_7 ) ;
return V_7 ;
}
for ( V_102 = 0 ; V_102 < V_101 . V_104 ; V_102 ++ )
V_103 += F_64 ( V_38 + V_103 , V_105 - V_103 , L_24 ,
V_101 . V_37 [ V_102 ] ) ;
return V_103 ;
}
static int F_65 ( struct V_3 * V_4 )
{
int V_106 ;
F_3 ( & V_107 ) ;
V_106 = F_66 ( & V_108 , V_4 , 0 , V_109 , V_110 ) ;
if ( V_106 >= 0 )
V_4 -> V_111 = V_106 ;
else if ( V_106 == - V_112 )
F_42 ( V_4 -> V_4 , L_25 ) ;
F_9 ( & V_107 ) ;
return V_106 ;
}
static void F_67 ( struct V_3 * V_4 )
{
F_3 ( & V_107 ) ;
F_68 ( & V_108 , V_4 -> V_111 ) ;
F_9 ( & V_107 ) ;
}
int F_69 ( struct V_3 * V_4 , struct V_97 * V_113 )
{
struct V_97 * V_114 ;
int V_106 , V_115 ;
V_106 = F_65 ( V_4 ) ;
if ( V_106 < 0 )
return V_106 ;
V_115 = F_70 ( F_71 ( V_116 ) , V_4 -> V_111 ) ;
F_72 ( & V_4 -> V_9 , & V_117 ) ;
V_4 -> V_9 . V_118 = V_113 -> V_119 -> V_118 ;
V_106 = F_73 ( & V_4 -> V_9 , V_115 , 1 ) ;
if ( V_106 ) {
F_42 ( V_113 , L_26 ,
F_71 ( V_116 ) , V_4 -> V_111 ) ;
goto V_120;
}
V_114 = F_74 ( V_121 , V_113 , V_115 ,
V_4 , V_122 ,
L_27 , V_4 -> V_111 ) ;
if ( F_7 ( V_114 ) ) {
F_42 ( V_113 , L_28 ,
F_71 ( V_116 ) , V_4 -> V_111 ) ;
V_106 = F_8 ( V_114 ) ;
goto V_123;
}
V_106 = F_75 ( V_4 , F_76 ( V_114 ) ) ;
if ( V_106 ) {
F_42 ( V_114 , L_29 , V_106 ) ;
goto V_124;
}
return 0 ;
V_124:
F_77 ( V_121 , V_115 ) ;
V_123:
F_78 ( & V_4 -> V_9 ) ;
V_120:
F_67 ( V_4 ) ;
return V_106 ;
}
void F_79 ( struct V_3 * V_4 )
{
int V_115 ;
V_115 = V_4 -> V_9 . V_4 ;
F_78 ( & V_4 -> V_9 ) ;
F_80 ( V_4 ) ;
F_77 ( V_121 , V_115 ) ;
F_67 ( V_4 ) ;
}
static int T_7 F_81 ( void )
{
int V_106 ;
V_121 = F_82 ( V_125 , L_30 ) ;
if ( F_7 ( V_121 ) ) {
F_83 ( L_31 ) ;
V_106 = F_8 ( V_121 ) ;
goto V_7;
}
V_106 = F_84 ( & V_116 , 0 , V_109 , L_30 ) ;
if ( V_106 < 0 ) {
F_83 ( L_32 ) ;
goto V_126;
}
V_106 = F_85 () ;
if ( V_106 < 0 ) {
F_83 ( L_33 ) ;
goto V_127;
}
return 0 ;
V_127:
F_86 ( V_116 , V_109 ) ;
V_126:
F_87 ( V_121 ) ;
V_7:
return V_106 ;
}
static void T_8 F_88 ( void )
{
F_86 ( V_116 , V_109 ) ;
F_87 ( V_121 ) ;
F_89 () ;
}
