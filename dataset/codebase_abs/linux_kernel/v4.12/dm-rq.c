bool F_1 ( void )
{
return V_1 ;
}
bool F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_1 ;
}
unsigned F_3 ( void )
{
return F_4 ( & V_4 ,
V_5 , V_6 ) ;
}
static unsigned F_5 ( void )
{
return F_4 ( & V_7 , 1 , 32 ) ;
}
static unsigned F_6 ( void )
{
return F_4 ( & V_8 ,
V_9 , V_10 ) ;
}
int F_7 ( struct V_2 * V_3 )
{
return F_8 ( V_3 -> V_11 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( F_11 ( V_13 ) )
F_12 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_14 ( struct V_12 * V_13 )
{
F_15 ( V_13 , true ) ;
F_16 ( V_13 ) ;
}
void F_17 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_16 )
F_9 ( V_13 ) ;
else
F_14 ( V_13 ) ;
}
static void F_18 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( ! F_11 ( V_13 ) )
F_19 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
if ( F_21 ( V_13 ) )
return;
F_22 ( V_13 ) ;
}
void F_23 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_16 )
F_18 ( V_13 ) ;
else
F_20 ( V_13 ) ;
}
static void F_24 ( struct V_17 * V_18 )
{
struct V_19 * V_20 =
F_25 ( V_18 , struct V_19 , V_18 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
struct V_17 * V_17 = V_20 -> V_23 ;
unsigned int V_24 = V_20 -> V_23 -> V_25 . V_26 ;
int error = V_18 -> V_27 ;
F_26 ( V_18 ) ;
if ( V_22 -> error )
return;
else if ( error ) {
V_22 -> error = error ;
return;
}
if ( V_22 -> V_23 -> V_17 != V_17 )
F_27 ( L_1 ) ;
F_28 ( V_22 -> V_23 , 0 , V_24 ) ;
}
static struct V_21 * F_29 ( struct V_28 * V_29 )
{
return F_30 ( V_29 ) ;
}
static void F_31 ( struct V_2 * V_3 , struct V_28 * V_23 )
{
if ( F_32 ( F_33 ( & V_3 -> V_30 ) ) ) {
struct V_21 * V_22 = F_29 ( V_23 ) ;
V_22 -> V_31 = V_32 - V_22 -> V_31 ;
F_34 ( & V_3 -> V_30 , F_35 ( V_23 ) ,
F_36 ( V_23 ) , V_22 -> V_33 , true ,
V_22 -> V_31 , & V_22 -> V_34 ) ;
}
}
static void F_37 ( struct V_2 * V_3 , int V_35 , bool V_36 )
{
struct V_12 * V_13 = V_3 -> V_11 ;
unsigned long V_14 ;
F_38 ( & V_3 -> V_37 [ V_35 ] ) ;
if ( ! F_39 ( V_3 ) )
F_40 ( & V_3 -> V_38 ) ;
if ( ! V_13 -> V_16 && V_36 ) {
F_10 ( V_13 -> V_15 , V_14 ) ;
F_41 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
F_42 ( V_3 ) ;
}
static void F_43 ( struct V_28 * V_18 , int error )
{
int V_35 = F_35 ( V_18 ) ;
struct V_21 * V_22 = V_18 -> V_39 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_28 * V_29 = V_22 -> V_23 ;
F_44 ( V_18 ) ;
V_22 -> V_40 -> type -> V_41 ( V_18 ) ;
F_31 ( V_3 , V_29 ) ;
if ( ! V_29 -> V_13 -> V_16 )
F_45 ( V_29 , error ) ;
else
F_46 ( V_29 , error ) ;
F_37 ( V_3 , V_35 , true ) ;
}
static void F_47 ( struct V_28 * V_29 )
{
struct V_12 * V_13 = V_29 -> V_13 ;
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_48 ( V_13 , V_29 ) ;
F_41 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_49 ( struct V_12 * V_13 , unsigned long V_42 )
{
F_50 ( V_13 , V_42 ) ;
}
void F_51 ( struct V_2 * V_3 )
{
F_49 ( F_52 ( V_3 ) , 0 ) ;
}
static void F_53 ( struct V_28 * V_29 , unsigned long V_42 )
{
F_54 ( V_29 , false ) ;
F_49 ( V_29 -> V_13 , V_42 ) ;
}
static void F_55 ( struct V_21 * V_22 , bool V_43 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_28 * V_29 = V_22 -> V_23 ;
int V_35 = F_35 ( V_29 ) ;
F_31 ( V_3 , V_29 ) ;
if ( V_22 -> V_18 ) {
F_44 ( V_22 -> V_18 ) ;
V_22 -> V_40 -> type -> V_41 ( V_22 -> V_18 ) ;
}
if ( ! V_29 -> V_13 -> V_16 )
F_47 ( V_29 ) ;
else
F_53 ( V_29 , V_43 ? 100 : 0 ) ;
F_37 ( V_3 , V_35 , false ) ;
}
static void F_56 ( struct V_28 * V_18 , int error , bool V_44 )
{
int V_45 = V_46 ;
struct V_21 * V_22 = V_18 -> V_39 ;
T_1 V_47 = NULL ;
if ( V_22 -> V_40 ) {
V_47 = V_22 -> V_40 -> type -> V_47 ;
if ( V_44 && V_47 )
V_45 = V_47 ( V_22 -> V_40 , V_18 , error , & V_22 -> V_20 ) ;
}
if ( F_32 ( error == - V_48 ) ) {
if ( F_57 ( V_18 ) == V_49 &&
! V_18 -> V_13 -> V_50 . V_51 )
F_58 ( V_22 -> V_3 ) ;
if ( F_57 ( V_18 ) == V_52 &&
! V_18 -> V_13 -> V_50 . V_53 )
F_59 ( V_22 -> V_3 ) ;
}
switch ( V_45 ) {
case V_46 :
F_43 ( V_18 , error ) ;
break;
case V_54 :
return;
case V_55 :
F_55 ( V_22 , false ) ;
break;
default:
F_60 ( L_2 , V_45 ) ;
F_61 () ;
}
}
static void F_62 ( struct V_28 * V_29 )
{
bool V_44 = true ;
struct V_21 * V_22 = F_29 ( V_29 ) ;
struct V_28 * V_18 = V_22 -> V_18 ;
int V_35 ;
if ( ! V_18 ) {
struct V_2 * V_3 = V_22 -> V_3 ;
F_31 ( V_3 , V_29 ) ;
V_35 = F_35 ( V_29 ) ;
if ( ! V_29 -> V_13 -> V_16 )
F_45 ( V_29 , V_22 -> error ) ;
else
F_46 ( V_29 , V_22 -> error ) ;
F_37 ( V_3 , V_35 , false ) ;
return;
}
if ( V_29 -> V_56 & V_57 )
V_44 = false ;
F_56 ( V_18 , V_22 -> error , V_44 ) ;
}
static void F_63 ( struct V_28 * V_29 , int error )
{
struct V_21 * V_22 = F_29 ( V_29 ) ;
V_22 -> error = error ;
if ( ! V_29 -> V_13 -> V_16 )
F_64 ( V_29 ) ;
else
F_65 ( V_29 ) ;
}
static void F_66 ( struct V_28 * V_29 , int error )
{
V_29 -> V_56 |= V_57 ;
F_63 ( V_29 , error ) ;
}
static void F_67 ( struct V_28 * V_18 , int error )
{
struct V_21 * V_22 = V_18 -> V_39 ;
F_63 ( V_22 -> V_23 , error ) ;
}
static void F_68 ( struct V_28 * V_18 , struct V_28 * V_29 )
{
int V_45 ;
if ( F_69 ( V_18 -> V_13 ) )
V_18 -> V_56 |= V_58 ;
V_18 -> V_59 = V_32 ;
V_45 = F_70 ( V_18 -> V_13 , V_18 ) ;
if ( V_45 )
F_63 ( V_29 , V_45 ) ;
}
static int F_71 ( struct V_17 * V_17 , struct V_17 * V_60 ,
void * V_61 )
{
struct V_21 * V_22 = V_61 ;
struct V_19 * V_20 =
F_25 ( V_17 , struct V_19 , V_18 ) ;
V_20 -> V_23 = V_60 ;
V_20 -> V_22 = V_22 ;
V_17 -> V_62 = F_24 ;
return 0 ;
}
static int F_72 ( struct V_28 * V_18 , struct V_28 * V_29 ,
struct V_21 * V_22 , T_2 V_63 )
{
int V_45 ;
V_45 = F_73 ( V_18 , V_29 , V_22 -> V_3 -> V_64 , V_63 ,
F_71 , V_22 ) ;
if ( V_45 )
return V_45 ;
V_18 -> V_65 = F_67 ;
V_18 -> V_39 = V_22 ;
V_22 -> V_18 = V_18 ;
return 0 ;
}
static void F_74 ( struct V_21 * V_22 , struct V_28 * V_29 ,
struct V_2 * V_3 )
{
V_22 -> V_3 = V_3 ;
V_22 -> V_40 = NULL ;
V_22 -> V_18 = NULL ;
V_22 -> V_23 = V_29 ;
V_22 -> error = 0 ;
if ( ! V_3 -> V_66 )
memset ( & V_22 -> V_20 , 0 , sizeof( V_22 -> V_20 ) ) ;
if ( V_3 -> V_67 )
F_75 ( & V_22 -> V_68 , V_69 ) ;
}
static int F_76 ( struct V_21 * V_22 )
{
int V_45 ;
struct V_70 * V_40 = V_22 -> V_40 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_28 * V_29 = V_22 -> V_23 ;
struct V_28 * V_18 = NULL ;
V_45 = V_40 -> type -> V_71 ( V_40 , V_29 , & V_22 -> V_20 , & V_18 ) ;
switch ( V_45 ) {
case V_72 :
break;
case V_73 :
if ( F_72 ( V_18 , V_29 , V_22 , V_74 ) ) {
V_40 -> type -> V_41 ( V_18 ) ;
return V_75 ;
}
F_77 ( V_18 -> V_13 , V_18 , F_78 ( F_79 ( V_3 ) ) ,
F_36 ( V_29 ) ) ;
F_68 ( V_18 , V_29 ) ;
break;
case V_75 :
break;
case V_76 :
F_55 ( V_22 , true ) ;
break;
case V_77 :
F_66 ( V_29 , - V_78 ) ;
break;
default:
F_60 ( L_3 , V_45 ) ;
F_61 () ;
}
return V_45 ;
}
static void F_80 ( struct V_2 * V_3 , struct V_28 * V_23 )
{
if ( ! V_23 -> V_13 -> V_16 )
F_81 ( V_23 ) ;
else
F_82 ( V_23 ) ;
F_83 ( & V_3 -> V_37 [ F_35 ( V_23 ) ] ) ;
if ( V_3 -> V_79 ) {
V_3 -> V_80 = F_84 ( V_23 ) ;
V_3 -> V_81 = F_35 ( V_23 ) ;
V_3 -> V_82 = F_85 () ;
}
if ( F_32 ( F_33 ( & V_3 -> V_30 ) ) ) {
struct V_21 * V_22 = F_29 ( V_23 ) ;
V_22 -> V_31 = V_32 ;
V_22 -> V_33 = F_86 ( V_23 ) ;
F_34 ( & V_3 -> V_30 , F_35 ( V_23 ) ,
F_36 ( V_23 ) , V_22 -> V_33 , false , 0 ,
& V_22 -> V_34 ) ;
}
F_87 ( V_3 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
struct V_21 * V_22 = F_30 ( V_29 ) ;
V_22 -> V_3 = V_3 ;
if ( V_3 -> V_66 ) {
V_22 -> V_20 . V_83 = V_22 + 1 ;
}
return 0 ;
}
static int F_89 ( struct V_12 * V_13 , struct V_28 * V_29 , T_2 V_84 )
{
return F_88 ( V_13 -> V_85 , V_29 ) ;
}
static void V_69 ( struct V_86 * V_68 )
{
struct V_21 * V_22 = F_25 ( V_68 , struct V_21 , V_68 ) ;
if ( F_76 ( V_22 ) == V_75 )
F_55 ( V_22 , false ) ;
}
T_3 F_90 ( struct V_2 * V_3 , char * V_87 )
{
return sprintf ( V_87 , L_4 , V_3 -> V_79 ) ;
}
T_3 F_91 ( struct V_2 * V_3 ,
const char * V_87 , T_4 V_88 )
{
unsigned V_89 ;
if ( F_92 ( V_3 ) != V_90 )
return V_88 ;
if ( F_93 ( V_87 , 10 , & V_89 ) )
return - V_91 ;
if ( V_89 > V_92 )
V_89 = V_92 ;
V_3 -> V_79 = V_89 ;
return V_88 ;
}
static bool F_94 ( struct V_2 * V_3 )
{
T_5 V_93 ;
if ( ! V_3 -> V_79 )
return false ;
V_93 = F_95 ( ( V_94 ) V_3 -> V_79 * V_95 ) ;
V_93 = F_96 ( V_3 -> V_82 , V_93 ) ;
return ! F_97 ( F_85 () , V_93 ) ;
}
static void F_98 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_96 ;
struct V_70 * V_40 = V_3 -> V_97 ;
struct V_28 * V_29 ;
struct V_21 * V_22 ;
T_6 V_98 = 0 ;
if ( F_32 ( ! V_40 ) ) {
int V_99 ;
struct V_100 * V_101 = F_99 ( V_3 , & V_99 ) ;
if ( F_32 ( ! V_101 ) ) {
F_100 ( V_3 , V_99 ) ;
return;
}
V_40 = F_101 ( V_101 , V_98 ) ;
F_100 ( V_3 , V_99 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_29 = F_102 ( V_13 ) ;
if ( ! V_29 )
return;
V_98 = 0 ;
if ( F_57 ( V_29 ) != V_102 )
V_98 = F_36 ( V_29 ) ;
if ( ( F_94 ( V_3 ) &&
F_39 ( V_3 ) && V_29 -> V_17 && ! F_103 ( V_29 -> V_17 ) &&
V_3 -> V_80 == V_98 && V_3 -> V_81 == F_35 ( V_29 ) ) ||
( V_40 -> type -> V_103 && V_40 -> type -> V_103 ( V_40 ) ) ) {
F_104 ( V_13 , 10 ) ;
return;
}
F_80 ( V_3 , V_29 ) ;
V_22 = F_29 ( V_29 ) ;
F_74 ( V_22 , V_29 , V_3 ) ;
V_22 -> V_40 = V_40 ;
F_105 ( & V_3 -> V_104 , & V_22 -> V_68 ) ;
F_106 ( ! F_107 () ) ;
}
}
int F_108 ( struct V_2 * V_3 , struct V_100 * V_105 )
{
struct V_70 * V_106 ;
V_3 -> V_11 -> V_107 = sizeof( struct V_21 ) ;
V_3 -> V_11 -> V_85 = V_3 ;
V_3 -> V_11 -> V_108 = F_98 ;
V_3 -> V_11 -> V_109 = F_89 ;
V_106 = F_109 ( V_105 ) ;
if ( V_106 && V_106 -> V_110 ) {
V_3 -> V_11 -> V_107 += V_106 -> V_110 ;
V_3 -> V_66 = true ;
}
if ( F_110 ( V_3 -> V_11 ) < 0 )
return - V_91 ;
V_3 -> V_79 = 0 ;
F_111 ( V_3 ) ;
F_112 ( V_3 -> V_11 , F_62 ) ;
F_113 ( & V_3 -> V_104 ) ;
V_3 -> V_67 = F_114 ( V_111 , & V_3 -> V_104 ,
L_5 , F_115 ( V_3 ) ) ;
if ( F_116 ( V_3 -> V_67 ) ) {
int error = F_117 ( V_3 -> V_67 ) ;
V_3 -> V_67 = NULL ;
return error ;
}
F_118 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_119 ( struct V_112 * V_113 , struct V_28 * V_29 ,
unsigned int V_114 , unsigned int V_115 )
{
return F_88 ( V_113 -> V_116 , V_29 ) ;
}
static int F_120 ( struct V_117 * V_118 ,
const struct V_119 * V_120 )
{
struct V_28 * V_29 = V_120 -> V_29 ;
struct V_21 * V_22 = F_30 ( V_29 ) ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_70 * V_40 = V_3 -> V_97 ;
if ( F_32 ( ! V_40 ) ) {
int V_99 ;
struct V_100 * V_101 = F_99 ( V_3 , & V_99 ) ;
V_40 = F_101 ( V_101 , 0 ) ;
F_100 ( V_3 , V_99 ) ;
}
if ( V_40 -> type -> V_103 && V_40 -> type -> V_103 ( V_40 ) )
return V_121 ;
F_80 ( V_3 , V_29 ) ;
F_74 ( V_22 , V_29 , V_3 ) ;
V_22 -> V_40 = V_40 ;
if ( F_76 ( V_22 ) == V_75 ) {
F_31 ( V_3 , V_29 ) ;
F_37 ( V_3 , F_35 ( V_29 ) , false ) ;
F_121 ( V_118 , 100 ) ;
return V_121 ;
}
return V_122 ;
}
int F_122 ( struct V_2 * V_3 , struct V_100 * V_105 )
{
struct V_12 * V_13 ;
struct V_70 * V_106 ;
int V_123 ;
if ( ! F_123 ( V_105 ) ) {
F_27 ( L_6 ) ;
return - V_91 ;
}
V_3 -> V_124 = F_124 ( sizeof( struct V_112 ) , V_125 , V_3 -> V_126 ) ;
if ( ! V_3 -> V_124 )
return - V_127 ;
V_3 -> V_124 -> V_128 = & V_129 ;
V_3 -> V_124 -> V_130 = F_6 () ;
V_3 -> V_124 -> V_115 = V_3 -> V_126 ;
V_3 -> V_124 -> V_14 = V_131 | V_132 ;
V_3 -> V_124 -> V_133 = F_5 () ;
V_3 -> V_124 -> V_116 = V_3 ;
V_3 -> V_124 -> V_107 = sizeof( struct V_21 ) ;
V_106 = F_109 ( V_105 ) ;
if ( V_106 && V_106 -> V_110 ) {
V_3 -> V_124 -> V_107 += V_106 -> V_110 ;
V_3 -> V_66 = true ;
}
V_123 = F_125 ( V_3 -> V_124 ) ;
if ( V_123 )
goto V_134;
V_13 = F_126 ( V_3 -> V_124 , V_3 -> V_11 ) ;
if ( F_116 ( V_13 ) ) {
V_123 = F_117 ( V_13 ) ;
goto V_135;
}
F_127 ( V_3 ) ;
V_123 = F_128 ( F_129 ( V_3 -> V_136 ) , V_13 ) ;
if ( V_123 )
goto V_137;
return 0 ;
V_137:
F_130 ( V_13 ) ;
V_135:
F_131 ( V_3 -> V_124 ) ;
V_134:
F_132 ( V_3 -> V_124 ) ;
return V_123 ;
}
void F_133 ( struct V_2 * V_3 )
{
if ( V_3 -> V_124 ) {
F_131 ( V_3 -> V_124 ) ;
F_132 ( V_3 -> V_124 ) ;
}
}
