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
F_15 ( V_13 ) ;
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
T_1 error = V_18 -> V_27 ;
F_26 ( V_18 ) ;
if ( V_22 -> error )
return;
else if ( error ) {
V_22 -> error = error ;
return;
}
if ( V_22 -> V_23 -> V_17 != V_17 )
F_27 ( L_1 ) ;
F_28 ( V_22 -> V_23 , V_28 , V_24 ) ;
}
static struct V_21 * F_29 ( struct V_29 * V_30 )
{
return F_30 ( V_30 ) ;
}
static void F_31 ( struct V_2 * V_3 , struct V_29 * V_23 )
{
if ( F_32 ( F_33 ( & V_3 -> V_31 ) ) ) {
struct V_21 * V_22 = F_29 ( V_23 ) ;
V_22 -> V_32 = V_33 - V_22 -> V_32 ;
F_34 ( & V_3 -> V_31 , F_35 ( V_23 ) ,
F_36 ( V_23 ) , V_22 -> V_34 , true ,
V_22 -> V_32 , & V_22 -> V_35 ) ;
}
}
static void F_37 ( struct V_2 * V_3 , int V_36 , bool V_37 )
{
struct V_12 * V_13 = V_3 -> V_11 ;
unsigned long V_14 ;
F_38 ( & V_3 -> V_38 [ V_36 ] ) ;
if ( ! F_39 ( V_3 ) )
F_40 ( & V_3 -> V_39 ) ;
if ( ! V_13 -> V_16 && V_37 ) {
F_10 ( V_13 -> V_15 , V_14 ) ;
F_41 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
F_42 ( V_3 ) ;
}
static void F_43 ( struct V_29 * V_18 , T_1 error )
{
int V_36 = F_35 ( V_18 ) ;
struct V_21 * V_22 = V_18 -> V_40 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_29 * V_30 = V_22 -> V_23 ;
F_44 ( V_18 ) ;
V_22 -> V_41 -> type -> V_42 ( V_18 ) ;
F_31 ( V_3 , V_30 ) ;
if ( ! V_30 -> V_13 -> V_16 )
F_45 ( V_30 , error ) ;
else
F_46 ( V_30 , error ) ;
F_37 ( V_3 , V_36 , true ) ;
}
static void F_47 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_48 ( V_13 , V_30 ) ;
F_41 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_49 ( struct V_12 * V_13 , unsigned long V_43 )
{
F_50 ( V_13 , V_43 ) ;
}
void F_51 ( struct V_2 * V_3 )
{
F_49 ( F_52 ( V_3 ) , 0 ) ;
}
static void F_53 ( struct V_29 * V_30 , unsigned long V_43 )
{
F_54 ( V_30 , false ) ;
F_49 ( V_30 -> V_13 , V_43 ) ;
}
static void F_55 ( struct V_21 * V_22 , bool V_44 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_29 * V_30 = V_22 -> V_23 ;
int V_36 = F_35 ( V_30 ) ;
F_31 ( V_3 , V_30 ) ;
if ( V_22 -> V_18 ) {
F_44 ( V_22 -> V_18 ) ;
V_22 -> V_41 -> type -> V_42 ( V_22 -> V_18 ) ;
}
if ( ! V_30 -> V_13 -> V_16 )
F_47 ( V_30 ) ;
else
F_53 ( V_30 , V_44 ? 100 : 0 ) ;
F_37 ( V_3 , V_36 , false ) ;
}
static void F_56 ( struct V_29 * V_18 , T_1 error , bool V_45 )
{
int V_46 = V_47 ;
struct V_21 * V_22 = V_18 -> V_40 ;
T_2 V_48 = NULL ;
if ( V_22 -> V_41 ) {
V_48 = V_22 -> V_41 -> type -> V_48 ;
if ( V_45 && V_48 )
V_46 = V_48 ( V_22 -> V_41 , V_18 , error , & V_22 -> V_20 ) ;
}
if ( F_32 ( error == V_49 ) ) {
if ( F_57 ( V_18 ) == V_50 &&
! V_18 -> V_13 -> V_51 . V_52 )
F_58 ( V_22 -> V_3 ) ;
if ( F_57 ( V_18 ) == V_53 &&
! V_18 -> V_13 -> V_51 . V_54 )
F_59 ( V_22 -> V_3 ) ;
}
switch ( V_46 ) {
case V_47 :
F_43 ( V_18 , error ) ;
break;
case V_55 :
return;
case V_56 :
F_55 ( V_22 , false ) ;
break;
default:
F_60 ( L_2 , V_46 ) ;
F_61 () ;
}
}
static void F_62 ( struct V_29 * V_30 )
{
bool V_45 = true ;
struct V_21 * V_22 = F_29 ( V_30 ) ;
struct V_29 * V_18 = V_22 -> V_18 ;
int V_36 ;
if ( ! V_18 ) {
struct V_2 * V_3 = V_22 -> V_3 ;
F_31 ( V_3 , V_30 ) ;
V_36 = F_35 ( V_30 ) ;
if ( ! V_30 -> V_13 -> V_16 )
F_45 ( V_30 , V_22 -> error ) ;
else
F_46 ( V_30 , V_22 -> error ) ;
F_37 ( V_3 , V_36 , false ) ;
return;
}
if ( V_30 -> V_57 & V_58 )
V_45 = false ;
F_56 ( V_18 , V_22 -> error , V_45 ) ;
}
static void F_63 ( struct V_29 * V_30 , T_1 error )
{
struct V_21 * V_22 = F_29 ( V_30 ) ;
V_22 -> error = error ;
if ( ! V_30 -> V_13 -> V_16 )
F_64 ( V_30 ) ;
else
F_65 ( V_30 ) ;
}
static void F_66 ( struct V_29 * V_30 , T_1 error )
{
V_30 -> V_57 |= V_58 ;
F_63 ( V_30 , error ) ;
}
static void F_67 ( struct V_29 * V_18 , T_1 error )
{
struct V_21 * V_22 = V_18 -> V_40 ;
F_63 ( V_22 -> V_23 , error ) ;
}
static void F_68 ( struct V_29 * V_18 , struct V_29 * V_30 )
{
T_1 V_46 ;
if ( F_69 ( V_18 -> V_13 ) )
V_18 -> V_57 |= V_59 ;
V_18 -> V_60 = V_33 ;
V_46 = F_70 ( V_18 -> V_13 , V_18 ) ;
if ( V_46 )
F_63 ( V_30 , V_46 ) ;
}
static int F_71 ( struct V_17 * V_17 , struct V_17 * V_61 ,
void * V_62 )
{
struct V_21 * V_22 = V_62 ;
struct V_19 * V_20 =
F_25 ( V_17 , struct V_19 , V_18 ) ;
V_20 -> V_23 = V_61 ;
V_20 -> V_22 = V_22 ;
V_17 -> V_63 = F_24 ;
return 0 ;
}
static int F_72 ( struct V_29 * V_18 , struct V_29 * V_30 ,
struct V_21 * V_22 , T_3 V_64 )
{
int V_46 ;
V_46 = F_73 ( V_18 , V_30 , V_22 -> V_3 -> V_65 , V_64 ,
F_71 , V_22 ) ;
if ( V_46 )
return V_46 ;
V_18 -> V_66 = F_67 ;
V_18 -> V_40 = V_22 ;
V_22 -> V_18 = V_18 ;
return 0 ;
}
static void F_74 ( struct V_21 * V_22 , struct V_29 * V_30 ,
struct V_2 * V_3 )
{
V_22 -> V_3 = V_3 ;
V_22 -> V_41 = NULL ;
V_22 -> V_18 = NULL ;
V_22 -> V_23 = V_30 ;
V_22 -> error = 0 ;
if ( ! V_3 -> V_67 )
memset ( & V_22 -> V_20 , 0 , sizeof( V_22 -> V_20 ) ) ;
if ( V_3 -> V_68 )
F_75 ( & V_22 -> V_69 , V_70 ) ;
}
static int F_76 ( struct V_21 * V_22 )
{
int V_46 ;
struct V_71 * V_41 = V_22 -> V_41 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_29 * V_30 = V_22 -> V_23 ;
struct V_29 * V_18 = NULL ;
V_46 = V_41 -> type -> V_72 ( V_41 , V_30 , & V_22 -> V_20 , & V_18 ) ;
switch ( V_46 ) {
case V_73 :
break;
case V_74 :
if ( F_72 ( V_18 , V_30 , V_22 , V_75 ) ) {
V_41 -> type -> V_42 ( V_18 ) ;
return V_76 ;
}
F_77 ( V_18 -> V_13 , V_18 , F_78 ( F_79 ( V_3 ) ) ,
F_36 ( V_30 ) ) ;
F_68 ( V_18 , V_30 ) ;
break;
case V_76 :
break;
case V_77 :
F_55 ( V_22 , true ) ;
break;
case V_78 :
F_66 ( V_30 , V_79 ) ;
break;
default:
F_60 ( L_3 , V_46 ) ;
F_61 () ;
}
return V_46 ;
}
static void F_80 ( struct V_2 * V_3 , struct V_29 * V_23 )
{
if ( ! V_23 -> V_13 -> V_16 )
F_81 ( V_23 ) ;
else
F_82 ( V_23 ) ;
F_83 ( & V_3 -> V_38 [ F_35 ( V_23 ) ] ) ;
if ( V_3 -> V_80 ) {
V_3 -> V_81 = F_84 ( V_23 ) ;
V_3 -> V_82 = F_35 ( V_23 ) ;
V_3 -> V_83 = F_85 () ;
}
if ( F_32 ( F_33 ( & V_3 -> V_31 ) ) ) {
struct V_21 * V_22 = F_29 ( V_23 ) ;
V_22 -> V_32 = V_33 ;
V_22 -> V_34 = F_86 ( V_23 ) ;
F_34 ( & V_3 -> V_31 , F_35 ( V_23 ) ,
F_36 ( V_23 ) , V_22 -> V_34 , false , 0 ,
& V_22 -> V_35 ) ;
}
F_87 ( V_3 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
struct V_21 * V_22 = F_30 ( V_30 ) ;
V_22 -> V_3 = V_3 ;
if ( V_3 -> V_67 ) {
V_22 -> V_20 . V_84 = V_22 + 1 ;
}
return 0 ;
}
static int F_89 ( struct V_12 * V_13 , struct V_29 * V_30 , T_3 V_85 )
{
return F_88 ( V_13 -> V_86 , V_30 ) ;
}
static void V_70 ( struct V_87 * V_69 )
{
struct V_21 * V_22 = F_25 ( V_69 , struct V_21 , V_69 ) ;
if ( F_76 ( V_22 ) == V_76 )
F_55 ( V_22 , false ) ;
}
T_4 F_90 ( struct V_2 * V_3 , char * V_88 )
{
return sprintf ( V_88 , L_4 , V_3 -> V_80 ) ;
}
T_4 F_91 ( struct V_2 * V_3 ,
const char * V_88 , T_5 V_89 )
{
unsigned V_90 ;
if ( F_92 ( V_3 ) != V_91 )
return V_89 ;
if ( F_93 ( V_88 , 10 , & V_90 ) )
return - V_92 ;
if ( V_90 > V_93 )
V_90 = V_93 ;
V_3 -> V_80 = V_90 ;
return V_89 ;
}
static bool F_94 ( struct V_2 * V_3 )
{
T_6 V_94 ;
if ( ! V_3 -> V_80 )
return false ;
V_94 = F_95 ( ( V_95 ) V_3 -> V_80 * V_96 ) ;
V_94 = F_96 ( V_3 -> V_83 , V_94 ) ;
return ! F_97 ( F_85 () , V_94 ) ;
}
static void F_98 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_97 ;
struct V_71 * V_41 = V_3 -> V_98 ;
struct V_29 * V_30 ;
struct V_21 * V_22 ;
T_7 V_99 = 0 ;
if ( F_32 ( ! V_41 ) ) {
int V_100 ;
struct V_101 * V_102 = F_99 ( V_3 , & V_100 ) ;
if ( F_32 ( ! V_102 ) ) {
F_100 ( V_3 , V_100 ) ;
return;
}
V_41 = F_101 ( V_102 , V_99 ) ;
F_100 ( V_3 , V_100 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_30 = F_102 ( V_13 ) ;
if ( ! V_30 )
return;
V_99 = 0 ;
if ( F_57 ( V_30 ) != V_103 )
V_99 = F_36 ( V_30 ) ;
if ( ( F_94 ( V_3 ) &&
F_39 ( V_3 ) && V_30 -> V_17 && ! F_103 ( V_30 -> V_17 ) &&
V_3 -> V_81 == V_99 && V_3 -> V_82 == F_35 ( V_30 ) ) ||
( V_41 -> type -> V_104 && V_41 -> type -> V_104 ( V_41 ) ) ) {
F_104 ( V_13 , 10 ) ;
return;
}
F_80 ( V_3 , V_30 ) ;
V_22 = F_29 ( V_30 ) ;
F_74 ( V_22 , V_30 , V_3 ) ;
V_22 -> V_41 = V_41 ;
F_105 ( & V_3 -> V_105 , & V_22 -> V_69 ) ;
F_106 ( ! F_107 () ) ;
}
}
int F_108 ( struct V_2 * V_3 , struct V_101 * V_106 )
{
struct V_71 * V_107 ;
V_3 -> V_11 -> V_108 = sizeof( struct V_21 ) ;
V_3 -> V_11 -> V_86 = V_3 ;
V_3 -> V_11 -> V_109 = F_98 ;
V_3 -> V_11 -> V_110 = F_89 ;
V_107 = F_109 ( V_106 ) ;
if ( V_107 && V_107 -> V_111 ) {
V_3 -> V_11 -> V_108 += V_107 -> V_111 ;
V_3 -> V_67 = true ;
}
if ( F_110 ( V_3 -> V_11 ) < 0 )
return - V_92 ;
V_3 -> V_80 = 0 ;
F_111 ( V_3 ) ;
F_112 ( V_3 -> V_11 , F_62 ) ;
F_113 ( & V_3 -> V_105 ) ;
V_3 -> V_68 = F_114 ( V_112 , & V_3 -> V_105 ,
L_5 , F_115 ( V_3 ) ) ;
if ( F_116 ( V_3 -> V_68 ) ) {
int error = F_117 ( V_3 -> V_68 ) ;
V_3 -> V_68 = NULL ;
return error ;
}
F_118 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_119 ( struct V_113 * V_114 , struct V_29 * V_30 ,
unsigned int V_115 , unsigned int V_116 )
{
return F_88 ( V_114 -> V_117 , V_30 ) ;
}
static T_1 F_120 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_29 * V_30 = V_121 -> V_30 ;
struct V_21 * V_22 = F_30 ( V_30 ) ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_71 * V_41 = V_3 -> V_98 ;
if ( F_32 ( ! V_41 ) ) {
int V_100 ;
struct V_101 * V_102 = F_99 ( V_3 , & V_100 ) ;
V_41 = F_101 ( V_102 , 0 ) ;
F_100 ( V_3 , V_100 ) ;
}
if ( V_41 -> type -> V_104 && V_41 -> type -> V_104 ( V_41 ) )
return V_122 ;
F_80 ( V_3 , V_30 ) ;
F_74 ( V_22 , V_30 , V_3 ) ;
V_22 -> V_41 = V_41 ;
if ( F_76 ( V_22 ) == V_76 ) {
F_31 ( V_3 , V_30 ) ;
F_37 ( V_3 , F_35 ( V_30 ) , false ) ;
F_121 ( V_119 , 100 ) ;
return V_122 ;
}
return V_28 ;
}
int F_122 ( struct V_2 * V_3 , struct V_101 * V_106 )
{
struct V_12 * V_13 ;
struct V_71 * V_107 ;
int V_123 ;
if ( ! F_123 ( V_106 ) ) {
F_27 ( L_6 ) ;
return - V_92 ;
}
V_3 -> V_124 = F_124 ( sizeof( struct V_113 ) , V_125 , V_3 -> V_126 ) ;
if ( ! V_3 -> V_124 )
return - V_127 ;
V_3 -> V_124 -> V_128 = & V_129 ;
V_3 -> V_124 -> V_130 = F_6 () ;
V_3 -> V_124 -> V_116 = V_3 -> V_126 ;
V_3 -> V_124 -> V_14 = V_131 | V_132 ;
V_3 -> V_124 -> V_133 = F_5 () ;
V_3 -> V_124 -> V_117 = V_3 ;
V_3 -> V_124 -> V_108 = sizeof( struct V_21 ) ;
V_107 = F_109 ( V_106 ) ;
if ( V_107 && V_107 -> V_111 ) {
V_3 -> V_124 -> V_108 += V_107 -> V_111 ;
V_3 -> V_67 = true ;
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
