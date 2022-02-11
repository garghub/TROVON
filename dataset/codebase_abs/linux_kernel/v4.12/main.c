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
V_17 = F_13 ( V_6 ) ;
F_14 ( V_6 , V_2 ) ;
F_15 ( V_4 , V_6 , L_2 ) ;
F_16 ( V_6 ) ;
V_2 -> V_16 = NULL ;
F_17 ( V_6 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_18 ( struct V_2 * V_2 , char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = NULL ;
bool V_23 = ! ! ( V_2 -> V_24 & V_25 ) ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_26;
}
if ( V_19 == 0 ) {
V_17 = 0 ;
goto V_26;
}
if ( V_18 == NULL ) {
V_17 = - V_27 ;
goto V_26;
}
V_22 = F_19 ( V_6 , V_2 ) ;
if ( V_22 )
goto V_28;
if ( * V_20 > 0 )
* V_20 = 0 ;
V_17 = F_20 ( V_6 , V_19 , V_2 ) ;
if ( V_17 && V_17 != - V_29 ) {
F_15 ( V_4 , V_6 , L_3 , V_17 ) ;
goto V_26;
}
if ( V_23 ) {
V_17 = - V_30 ;
goto V_26;
}
F_9 ( & V_4 -> V_11 ) ;
if ( F_21 ( V_6 -> V_31 ,
! F_22 ( & V_6 -> V_32 ) ||
! F_23 ( V_6 ) ) ) {
if ( F_24 ( V_33 ) )
return - V_34 ;
return - V_35 ;
}
F_3 ( & V_4 -> V_11 ) ;
if ( ! F_23 ( V_6 ) ) {
V_17 = - V_10 ;
goto V_26;
}
V_22 = F_19 ( V_6 , V_2 ) ;
if ( ! V_22 ) {
V_17 = 0 ;
goto V_26;
}
V_28:
if ( V_22 -> V_36 ) {
V_17 = V_22 -> V_36 ;
F_15 ( V_4 , V_6 , L_4 , V_17 ) ;
goto free;
}
F_15 ( V_4 , V_6 , L_5 ,
V_22 -> V_37 . V_38 , V_22 -> V_39 , * V_20 ) ;
if ( * V_20 >= V_22 -> V_39 ) {
V_17 = 0 ;
goto free;
}
V_19 = F_25 ( T_3 , V_19 , V_22 -> V_39 - * V_20 ) ;
if ( F_26 ( V_18 , V_22 -> V_37 . V_40 + * V_20 , V_19 ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_41 ;
goto free;
}
V_17 = V_19 ;
* V_20 += V_19 ;
if ( * V_20 < V_22 -> V_39 )
goto V_26;
free:
F_27 ( V_22 ) ;
* V_20 = 0 ;
V_26:
F_15 ( V_4 , V_6 , L_7 , V_17 ) ;
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static T_1 F_28 ( struct V_2 * V_2 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_26;
}
if ( ! F_23 ( V_6 ) ) {
F_29 ( V_4 , V_6 , L_8 ) ;
V_17 = - V_10 ;
goto V_26;
}
if ( ! F_30 ( V_6 -> V_42 ) ) {
V_17 = - V_43 ;
goto V_26;
}
if ( V_19 > F_31 ( V_6 ) ) {
V_17 = - V_44 ;
goto V_26;
}
if ( V_19 == 0 ) {
V_17 = 0 ;
goto V_26;
}
* V_20 = 0 ;
V_22 = F_32 ( V_6 , V_19 , V_45 , V_2 ) ;
if ( ! V_22 ) {
V_17 = - V_46 ;
goto V_26;
}
V_17 = F_33 ( V_22 -> V_37 . V_40 , V_18 , V_19 ) ;
if ( V_17 ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_41 ;
F_27 ( V_22 ) ;
goto V_26;
}
V_17 = F_34 ( V_6 , V_22 ) ;
V_26:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static int F_35 ( struct V_2 * V_2 ,
struct V_47 * V_40 )
{
struct V_3 * V_4 ;
struct V_48 * V_49 ;
struct V_50 * V_42 ;
struct V_5 * V_6 ;
int V_17 ;
V_6 = V_2 -> V_16 ;
V_4 = V_6 -> V_4 ;
if ( V_4 -> V_12 != V_13 )
return - V_10 ;
if ( V_6 -> V_51 != V_52 &&
V_6 -> V_51 != V_53 )
return - V_29 ;
V_42 = F_36 ( V_4 , & V_40 -> V_54 ) ;
if ( ! V_42 ) {
F_4 ( V_4 -> V_4 , L_10 ,
& V_40 -> V_54 ) ;
V_17 = - V_43 ;
goto V_55;
}
if ( V_42 -> V_56 . V_57 ) {
bool V_58 = V_4 -> V_59 ?
! V_4 -> V_60 : ! V_4 -> V_61 ;
if ( V_58 ) {
F_4 ( V_4 -> V_4 , L_11 ,
& V_40 -> V_54 ) ;
V_17 = - V_43 ;
goto V_55;
}
}
F_4 ( V_4 -> V_4 , L_12 ,
V_42 -> V_62 ) ;
F_4 ( V_4 -> V_4 , L_13 ,
V_42 -> V_56 . V_63 ) ;
F_4 ( V_4 -> V_4 , L_14 ,
V_42 -> V_56 . V_64 ) ;
V_49 = & V_40 -> V_65 ;
V_49 -> V_64 = V_42 -> V_56 . V_64 ;
V_49 -> V_63 = V_42 -> V_56 . V_63 ;
F_4 ( V_4 -> V_4 , L_15 ) ;
V_17 = F_37 ( V_6 , V_42 , V_2 ) ;
V_55:
F_38 ( V_42 ) ;
return V_17 ;
}
static int F_39 ( const struct V_2 * V_2 , T_5 V_66 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( V_66 != V_67 &&
V_66 != V_68 )
return - V_69 ;
return F_40 ( V_6 , V_2 , ( V_70 ) V_66 ) ;
}
static int F_41 ( const struct V_2 * V_2 , T_5 * V_71 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
bool V_72 ;
bool V_73 = ( V_2 -> V_24 & V_25 ) == 0 ;
int V_17 ;
V_17 = F_42 ( V_6 , V_73 , & V_72 ) ;
if ( V_17 )
return V_17 ;
* V_71 = V_72 ? 1 : 0 ;
return 0 ;
}
static long F_43 ( struct V_2 * V_2 , unsigned int V_74 , unsigned long V_40 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_47 V_75 ;
T_5 V_71 , V_76 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_4 ( V_4 -> V_4 , L_16 , V_74 ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 ) {
V_17 = - V_10 ;
goto V_26;
}
switch ( V_74 ) {
case V_77 :
F_4 ( V_4 -> V_4 , L_17 ) ;
if ( F_33 ( & V_75 , ( char T_2 * ) V_40 ,
sizeof( struct V_47 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_41 ;
goto V_26;
}
V_17 = F_35 ( V_2 , & V_75 ) ;
if ( V_17 )
goto V_26;
if ( F_26 ( ( char T_2 * ) V_40 , & V_75 ,
sizeof( struct V_47 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_41 ;
goto V_26;
}
break;
case V_78 :
F_4 ( V_4 -> V_4 , L_18 ) ;
if ( F_33 ( & V_76 ,
( char T_2 * ) V_40 , sizeof( V_76 ) ) ) {
F_4 ( V_4 -> V_4 , L_9 ) ;
V_17 = - V_41 ;
goto V_26;
}
V_17 = F_39 ( V_2 , V_76 ) ;
break;
case V_79 :
F_4 ( V_4 -> V_4 , L_19 ) ;
V_17 = F_41 ( V_2 , & V_71 ) ;
if ( V_17 )
goto V_26;
F_4 ( V_4 -> V_4 , L_20 ) ;
if ( F_26 ( ( char T_2 * ) V_40 ,
& V_71 , sizeof( V_71 ) ) ) {
F_4 ( V_4 -> V_4 , L_6 ) ;
V_17 = - V_41 ;
goto V_26;
}
break;
default:
F_44 ( V_4 -> V_4 , L_21 , V_74 ) ;
V_17 = - V_80 ;
}
V_26:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static long F_45 ( struct V_2 * V_2 ,
unsigned int V_74 , unsigned long V_40 )
{
return F_43 ( V_2 , V_74 , ( unsigned long ) F_46 ( V_40 ) ) ;
}
static unsigned int F_47 ( struct V_2 * V_2 , T_6 * V_81 )
{
unsigned long V_82 = F_48 ( V_81 ) ;
struct V_5 * V_6 = V_2 -> V_16 ;
struct V_3 * V_4 ;
unsigned int V_83 = 0 ;
bool V_84 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return V_85 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
V_84 = V_6 -> V_84 && ( V_82 & V_86 ) ;
if ( V_4 -> V_12 != V_13 ||
! F_23 ( V_6 ) ) {
V_83 = V_85 ;
goto V_26;
}
if ( V_84 ) {
F_49 ( V_2 , & V_6 -> V_87 , V_81 ) ;
if ( V_6 -> V_72 )
V_83 |= V_86 ;
}
if ( V_82 & ( V_88 | V_89 ) ) {
F_49 ( V_2 , & V_6 -> V_31 , V_81 ) ;
if ( ! F_22 ( & V_6 -> V_32 ) )
V_83 |= V_88 | V_89 ;
else
F_20 ( V_6 , F_31 ( V_6 ) , V_2 ) ;
}
V_26:
F_9 ( & V_4 -> V_11 ) ;
return V_83 ;
}
static bool F_50 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_21 * V_22 ;
F_51 (cb, &dev->write_list, list)
if ( V_22 -> V_6 == V_6 )
return true ;
F_51 (cb, &dev->write_waiting_list, list)
if ( V_22 -> V_6 == V_6 )
return true ;
return false ;
}
static int F_52 ( struct V_2 * V_15 , T_4 V_90 , T_4 V_55 , int V_91 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
struct V_3 * V_4 ;
int V_17 ;
if ( F_12 ( ! V_6 || ! V_6 -> V_4 ) )
return - V_10 ;
V_4 = V_6 -> V_4 ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 != V_13 || ! F_23 ( V_6 ) ) {
V_17 = - V_10 ;
goto V_26;
}
while ( F_50 ( V_6 ) ) {
F_9 ( & V_4 -> V_11 ) ;
V_17 = F_21 ( V_6 -> V_92 ,
V_6 -> V_93 == V_94 ||
! F_23 ( V_6 ) ) ;
F_3 ( & V_4 -> V_11 ) ;
if ( V_17 ) {
if ( F_24 ( V_33 ) )
V_17 = - V_34 ;
goto V_26;
}
if ( ! F_23 ( V_6 ) ) {
V_17 = - V_10 ;
goto V_26;
}
}
V_17 = 0 ;
V_26:
F_9 ( & V_4 -> V_11 ) ;
return V_17 ;
}
static int F_53 ( int V_95 , struct V_2 * V_2 , int V_96 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
if ( ! F_23 ( V_6 ) )
return - V_10 ;
return F_54 ( V_95 , V_2 , V_96 , & V_6 -> V_97 ) ;
}
static T_1 F_55 ( struct V_98 * V_98 ,
struct V_99 * V_100 , char * V_37 )
{
struct V_3 * V_4 = F_56 ( V_98 ) ;
struct V_101 V_102 ;
int V_7 , V_103 ;
T_1 V_104 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_7 = V_101 ( V_4 , & V_102 ) ;
F_9 ( & V_4 -> V_11 ) ;
if ( V_7 ) {
F_44 ( V_98 , L_22 , V_7 ) ;
return V_7 ;
}
for ( V_103 = 0 ; V_103 < V_102 . V_105 ; V_103 ++ )
V_104 += F_57 ( V_37 + V_104 , V_106 - V_104 , L_23 ,
V_102 . V_36 [ V_103 ] ) ;
return V_104 ;
}
static T_1 F_58 ( struct V_98 * V_98 ,
struct V_99 * V_100 , char * V_37 )
{
struct V_3 * V_4 = F_56 ( V_98 ) ;
struct V_107 V_108 ;
F_3 ( & V_4 -> V_11 ) ;
V_108 = V_4 -> V_109 ;
F_9 ( & V_4 -> V_11 ) ;
return sprintf ( V_37 , L_24 , V_108 . V_110 , V_108 . V_111 ) ;
}
static T_1 F_59 ( struct V_98 * V_98 ,
struct V_99 * V_100 , char * V_37 )
{
return sprintf ( V_37 , L_24 , V_112 , V_113 ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
int V_114 ;
F_3 ( & V_115 ) ;
V_114 = F_61 ( & V_116 , V_4 , 0 , V_117 , V_118 ) ;
if ( V_114 >= 0 )
V_4 -> V_119 = V_114 ;
else if ( V_114 == - V_120 )
F_44 ( V_4 -> V_4 , L_25 ) ;
F_9 ( & V_115 ) ;
return V_114 ;
}
static void F_62 ( struct V_3 * V_4 )
{
F_3 ( & V_115 ) ;
F_63 ( & V_116 , V_4 -> V_119 ) ;
F_9 ( & V_115 ) ;
}
int F_64 ( struct V_3 * V_4 , struct V_98 * V_121 )
{
struct V_98 * V_122 ;
int V_114 , V_123 ;
V_114 = F_60 ( V_4 ) ;
if ( V_114 < 0 )
return V_114 ;
V_123 = F_65 ( F_66 ( V_124 ) , V_4 -> V_119 ) ;
F_67 ( & V_4 -> V_9 , & V_125 ) ;
V_4 -> V_9 . V_126 = V_121 -> V_127 -> V_126 ;
V_114 = F_68 ( & V_4 -> V_9 , V_123 , 1 ) ;
if ( V_114 ) {
F_44 ( V_121 , L_26 ,
F_66 ( V_124 ) , V_4 -> V_119 ) ;
goto V_128;
}
V_122 = F_69 ( V_129 , V_121 , V_123 ,
V_4 , V_130 ,
L_27 , V_4 -> V_119 ) ;
if ( F_7 ( V_122 ) ) {
F_44 ( V_121 , L_28 ,
F_66 ( V_124 ) , V_4 -> V_119 ) ;
V_114 = F_8 ( V_122 ) ;
goto V_131;
}
V_114 = F_70 ( V_4 , F_71 ( V_122 ) ) ;
if ( V_114 ) {
F_44 ( V_122 , L_29 , V_114 ) ;
goto V_132;
}
return 0 ;
V_132:
F_72 ( V_129 , V_123 ) ;
V_131:
F_73 ( & V_4 -> V_9 ) ;
V_128:
F_62 ( V_4 ) ;
return V_114 ;
}
void F_74 ( struct V_3 * V_4 )
{
int V_123 ;
V_123 = V_4 -> V_9 . V_4 ;
F_73 ( & V_4 -> V_9 ) ;
F_75 ( V_4 ) ;
F_72 ( V_129 , V_123 ) ;
F_62 ( V_4 ) ;
}
static int T_7 F_76 ( void )
{
int V_114 ;
V_129 = F_77 ( V_133 , L_30 ) ;
if ( F_7 ( V_129 ) ) {
F_78 ( L_31 ) ;
V_114 = F_8 ( V_129 ) ;
goto V_7;
}
V_114 = F_79 ( & V_124 , 0 , V_117 , L_30 ) ;
if ( V_114 < 0 ) {
F_78 ( L_32 ) ;
goto V_134;
}
V_114 = F_80 () ;
if ( V_114 < 0 ) {
F_78 ( L_33 ) ;
goto V_135;
}
return 0 ;
V_135:
F_81 ( V_124 , V_117 ) ;
V_134:
F_82 ( V_129 ) ;
V_7:
return V_114 ;
}
static void T_8 F_83 ( void )
{
F_81 ( V_124 , V_117 ) ;
F_82 ( V_129 ) ;
F_84 () ;
}
