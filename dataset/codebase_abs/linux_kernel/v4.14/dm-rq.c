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
unsigned int V_23 = V_20 -> V_24 -> V_25 . V_26 ;
T_1 error = V_18 -> V_27 ;
bool V_28 = ! V_18 -> V_29 ;
F_26 ( V_18 ) ;
if ( V_22 -> error )
return;
else if ( error ) {
V_22 -> error = error ;
goto exit;
}
V_22 -> V_30 += V_23 ;
if ( V_28 )
exit:
F_27 ( V_22 -> V_24 , V_31 , V_22 -> V_30 ) ;
}
static struct V_21 * F_28 ( struct V_32 * V_33 )
{
return F_29 ( V_33 ) ;
}
static void F_30 ( struct V_2 * V_3 , struct V_32 * V_24 )
{
if ( F_31 ( F_32 ( & V_3 -> V_34 ) ) ) {
struct V_21 * V_22 = F_28 ( V_24 ) ;
V_22 -> V_35 = V_36 - V_22 -> V_35 ;
F_33 ( & V_3 -> V_34 , F_34 ( V_24 ) ,
F_35 ( V_24 ) , V_22 -> V_37 , true ,
V_22 -> V_35 , & V_22 -> V_38 ) ;
}
}
static void F_36 ( struct V_2 * V_3 , int V_39 , bool V_40 )
{
struct V_12 * V_13 = V_3 -> V_11 ;
unsigned long V_14 ;
F_37 ( & V_3 -> V_41 [ V_39 ] ) ;
if ( ! F_38 ( V_3 ) )
F_39 ( & V_3 -> V_42 ) ;
if ( ! V_13 -> V_16 && V_40 ) {
F_10 ( V_13 -> V_15 , V_14 ) ;
F_40 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
F_41 ( V_3 ) ;
}
static void F_42 ( struct V_32 * V_18 , T_1 error )
{
int V_39 = F_34 ( V_18 ) ;
struct V_21 * V_22 = V_18 -> V_43 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_32 * V_33 = V_22 -> V_24 ;
F_43 ( V_18 ) ;
V_22 -> V_44 -> type -> V_45 ( V_18 ) ;
F_30 ( V_3 , V_33 ) ;
if ( ! V_33 -> V_13 -> V_16 )
F_44 ( V_33 , error ) ;
else
F_45 ( V_33 , error ) ;
F_36 ( V_3 , V_39 , true ) ;
}
static void F_46 ( struct V_32 * V_33 , unsigned long V_46 )
{
struct V_12 * V_13 = V_33 -> V_13 ;
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_47 ( V_13 , V_33 ) ;
F_48 ( V_13 , V_46 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_49 ( struct V_12 * V_13 , unsigned long V_47 )
{
F_50 ( V_13 , V_47 ) ;
}
void F_51 ( struct V_2 * V_3 )
{
F_49 ( F_52 ( V_3 ) , 0 ) ;
}
static void F_53 ( struct V_32 * V_33 , unsigned long V_47 )
{
F_54 ( V_33 , false ) ;
F_49 ( V_33 -> V_13 , V_47 ) ;
}
static void F_55 ( struct V_21 * V_22 , bool V_48 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_32 * V_33 = V_22 -> V_24 ;
int V_39 = F_34 ( V_33 ) ;
unsigned long V_46 = V_48 ? 100 : 0 ;
F_30 ( V_3 , V_33 ) ;
if ( V_22 -> V_18 ) {
F_43 ( V_22 -> V_18 ) ;
V_22 -> V_44 -> type -> V_45 ( V_22 -> V_18 ) ;
}
if ( ! V_33 -> V_13 -> V_16 )
F_46 ( V_33 , V_46 ) ;
else
F_53 ( V_33 , V_46 ) ;
F_36 ( V_3 , V_39 , false ) ;
}
static void F_56 ( struct V_32 * V_18 , T_1 error , bool V_49 )
{
int V_50 = V_51 ;
struct V_21 * V_22 = V_18 -> V_43 ;
T_2 V_52 = NULL ;
if ( V_22 -> V_44 ) {
V_52 = V_22 -> V_44 -> type -> V_52 ;
if ( V_49 && V_52 )
V_50 = V_52 ( V_22 -> V_44 , V_18 , error , & V_22 -> V_20 ) ;
}
if ( F_31 ( error == V_53 ) ) {
if ( F_57 ( V_18 ) == V_54 &&
! V_18 -> V_13 -> V_55 . V_56 )
F_58 ( V_22 -> V_3 ) ;
if ( F_57 ( V_18 ) == V_57 &&
! V_18 -> V_13 -> V_55 . V_58 )
F_59 ( V_22 -> V_3 ) ;
}
switch ( V_50 ) {
case V_51 :
F_42 ( V_18 , error ) ;
break;
case V_59 :
return;
case V_60 :
F_55 ( V_22 , false ) ;
break;
default:
F_60 ( L_1 , V_50 ) ;
F_61 () ;
}
}
static void F_62 ( struct V_32 * V_33 )
{
bool V_49 = true ;
struct V_21 * V_22 = F_28 ( V_33 ) ;
struct V_32 * V_18 = V_22 -> V_18 ;
int V_39 ;
if ( ! V_18 ) {
struct V_2 * V_3 = V_22 -> V_3 ;
F_30 ( V_3 , V_33 ) ;
V_39 = F_34 ( V_33 ) ;
if ( ! V_33 -> V_13 -> V_16 )
F_44 ( V_33 , V_22 -> error ) ;
else
F_45 ( V_33 , V_22 -> error ) ;
F_36 ( V_3 , V_39 , false ) ;
return;
}
if ( V_33 -> V_61 & V_62 )
V_49 = false ;
F_56 ( V_18 , V_22 -> error , V_49 ) ;
}
static void F_63 ( struct V_32 * V_33 , T_1 error )
{
struct V_21 * V_22 = F_28 ( V_33 ) ;
V_22 -> error = error ;
if ( ! V_33 -> V_13 -> V_16 )
F_64 ( V_33 ) ;
else
F_65 ( V_33 ) ;
}
static void F_66 ( struct V_32 * V_33 , T_1 error )
{
V_33 -> V_61 |= V_62 ;
F_63 ( V_33 , error ) ;
}
static void F_67 ( struct V_32 * V_18 , T_1 error )
{
struct V_21 * V_22 = V_18 -> V_43 ;
F_63 ( V_22 -> V_24 , error ) ;
}
static void F_68 ( struct V_32 * V_18 , struct V_32 * V_33 )
{
T_1 V_50 ;
if ( F_69 ( V_18 -> V_13 ) )
V_18 -> V_61 |= V_63 ;
V_18 -> V_64 = V_36 ;
V_50 = F_70 ( V_18 -> V_13 , V_18 ) ;
if ( V_50 )
F_63 ( V_33 , V_50 ) ;
}
static int F_71 ( struct V_17 * V_17 , struct V_17 * V_65 ,
void * V_66 )
{
struct V_21 * V_22 = V_66 ;
struct V_19 * V_20 =
F_25 ( V_17 , struct V_19 , V_18 ) ;
V_20 -> V_24 = V_65 ;
V_20 -> V_22 = V_22 ;
V_17 -> V_67 = F_24 ;
return 0 ;
}
static int F_72 ( struct V_32 * V_18 , struct V_32 * V_33 ,
struct V_21 * V_22 , T_3 V_68 )
{
int V_50 ;
V_50 = F_73 ( V_18 , V_33 , V_22 -> V_3 -> V_69 , V_68 ,
F_71 , V_22 ) ;
if ( V_50 )
return V_50 ;
V_18 -> V_70 = F_67 ;
V_18 -> V_43 = V_22 ;
V_22 -> V_18 = V_18 ;
return 0 ;
}
static void F_74 ( struct V_21 * V_22 , struct V_32 * V_33 ,
struct V_2 * V_3 )
{
V_22 -> V_3 = V_3 ;
V_22 -> V_44 = NULL ;
V_22 -> V_18 = NULL ;
V_22 -> V_24 = V_33 ;
V_22 -> error = 0 ;
V_22 -> V_30 = 0 ;
if ( ! V_3 -> V_71 )
memset ( & V_22 -> V_20 , 0 , sizeof( V_22 -> V_20 ) ) ;
if ( V_3 -> V_72 )
F_75 ( & V_22 -> V_73 , V_74 ) ;
}
static int F_76 ( struct V_21 * V_22 )
{
int V_50 ;
struct V_75 * V_44 = V_22 -> V_44 ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_32 * V_33 = V_22 -> V_24 ;
struct V_32 * V_18 = NULL ;
V_50 = V_44 -> type -> V_76 ( V_44 , V_33 , & V_22 -> V_20 , & V_18 ) ;
switch ( V_50 ) {
case V_77 :
break;
case V_78 :
if ( F_72 ( V_18 , V_33 , V_22 , V_79 ) ) {
V_44 -> type -> V_45 ( V_18 ) ;
return V_80 ;
}
F_77 ( V_18 -> V_13 , V_18 , F_78 ( F_79 ( V_3 ) ) ,
F_35 ( V_33 ) ) ;
F_68 ( V_18 , V_33 ) ;
break;
case V_80 :
break;
case V_81 :
F_55 ( V_22 , true ) ;
break;
case V_82 :
F_66 ( V_33 , V_83 ) ;
break;
default:
F_60 ( L_2 , V_50 ) ;
F_61 () ;
}
return V_50 ;
}
static void F_80 ( struct V_2 * V_3 , struct V_32 * V_24 )
{
if ( ! V_24 -> V_13 -> V_16 )
F_81 ( V_24 ) ;
else
F_82 ( V_24 ) ;
F_83 ( & V_3 -> V_41 [ F_34 ( V_24 ) ] ) ;
if ( V_3 -> V_84 ) {
V_3 -> V_85 = F_84 ( V_24 ) ;
V_3 -> V_86 = F_34 ( V_24 ) ;
V_3 -> V_87 = F_85 () ;
}
if ( F_31 ( F_32 ( & V_3 -> V_34 ) ) ) {
struct V_21 * V_22 = F_28 ( V_24 ) ;
V_22 -> V_35 = V_36 ;
V_22 -> V_37 = F_86 ( V_24 ) ;
F_33 ( & V_3 -> V_34 , F_34 ( V_24 ) ,
F_35 ( V_24 ) , V_22 -> V_37 , false , 0 ,
& V_22 -> V_38 ) ;
}
F_87 ( V_3 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_21 * V_22 = F_29 ( V_33 ) ;
V_22 -> V_3 = V_3 ;
if ( V_3 -> V_71 ) {
V_22 -> V_20 . V_88 = V_22 + 1 ;
}
return 0 ;
}
static int F_89 ( struct V_12 * V_13 , struct V_32 * V_33 , T_3 V_89 )
{
return F_88 ( V_13 -> V_90 , V_33 ) ;
}
static void V_74 ( struct V_91 * V_73 )
{
struct V_21 * V_22 = F_25 ( V_73 , struct V_21 , V_73 ) ;
if ( F_76 ( V_22 ) == V_80 )
F_55 ( V_22 , false ) ;
}
T_4 F_90 ( struct V_2 * V_3 , char * V_92 )
{
return sprintf ( V_92 , L_3 , V_3 -> V_84 ) ;
}
T_4 F_91 ( struct V_2 * V_3 ,
const char * V_92 , T_5 V_93 )
{
unsigned V_94 ;
if ( F_92 ( V_3 ) != V_95 )
return V_93 ;
if ( F_93 ( V_92 , 10 , & V_94 ) )
return - V_96 ;
if ( V_94 > V_97 )
V_94 = V_97 ;
V_3 -> V_84 = V_94 ;
return V_93 ;
}
static bool F_94 ( struct V_2 * V_3 )
{
T_6 V_98 ;
if ( ! V_3 -> V_84 )
return false ;
V_98 = F_95 ( ( V_99 ) V_3 -> V_84 * V_100 ) ;
V_98 = F_96 ( V_3 -> V_87 , V_98 ) ;
return ! F_97 ( F_85 () , V_98 ) ;
}
static void F_98 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_101 ;
struct V_75 * V_44 = V_3 -> V_102 ;
struct V_32 * V_33 ;
struct V_21 * V_22 ;
T_7 V_103 = 0 ;
if ( F_31 ( ! V_44 ) ) {
int V_104 ;
struct V_105 * V_106 = F_99 ( V_3 , & V_104 ) ;
if ( F_31 ( ! V_106 ) ) {
F_100 ( V_3 , V_104 ) ;
return;
}
V_44 = F_101 ( V_106 , V_103 ) ;
F_100 ( V_3 , V_104 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_33 = F_102 ( V_13 ) ;
if ( ! V_33 )
return;
V_103 = 0 ;
if ( F_57 ( V_33 ) != V_107 )
V_103 = F_35 ( V_33 ) ;
if ( ( F_94 ( V_3 ) &&
F_38 ( V_3 ) && V_33 -> V_17 && ! F_103 ( V_33 -> V_17 ) &&
V_3 -> V_85 == V_103 && V_3 -> V_86 == F_34 ( V_33 ) ) ||
( V_44 -> type -> V_108 && V_44 -> type -> V_108 ( V_44 ) ) ) {
F_48 ( V_13 , 10 ) ;
return;
}
F_80 ( V_3 , V_33 ) ;
V_22 = F_28 ( V_33 ) ;
F_74 ( V_22 , V_33 , V_3 ) ;
V_22 -> V_44 = V_44 ;
F_104 ( & V_3 -> V_109 , & V_22 -> V_73 ) ;
F_105 ( ! F_106 () ) ;
}
}
int F_107 ( struct V_2 * V_3 , struct V_105 * V_110 )
{
struct V_75 * V_111 ;
V_3 -> V_11 -> V_112 = sizeof( struct V_21 ) ;
V_3 -> V_11 -> V_90 = V_3 ;
V_3 -> V_11 -> V_113 = F_98 ;
V_3 -> V_11 -> V_114 = F_89 ;
V_111 = F_108 ( V_110 ) ;
if ( V_111 && V_111 -> V_115 ) {
V_3 -> V_11 -> V_112 += V_111 -> V_115 ;
V_3 -> V_71 = true ;
}
if ( F_109 ( V_3 -> V_11 ) < 0 )
return - V_96 ;
V_3 -> V_84 = 0 ;
F_110 ( V_3 ) ;
F_111 ( V_3 -> V_11 , F_62 ) ;
F_112 ( & V_3 -> V_109 ) ;
V_3 -> V_72 = F_113 ( V_116 , & V_3 -> V_109 ,
L_4 , F_114 ( V_3 ) ) ;
if ( F_115 ( V_3 -> V_72 ) ) {
int error = F_116 ( V_3 -> V_72 ) ;
V_3 -> V_72 = NULL ;
return error ;
}
F_117 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_118 ( struct V_117 * V_118 , struct V_32 * V_33 ,
unsigned int V_119 , unsigned int V_120 )
{
return F_88 ( V_118 -> V_121 , V_33 ) ;
}
static T_1 F_119 ( struct V_122 * V_123 ,
const struct V_124 * V_125 )
{
struct V_32 * V_33 = V_125 -> V_33 ;
struct V_21 * V_22 = F_29 ( V_33 ) ;
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_75 * V_44 = V_3 -> V_102 ;
if ( F_31 ( ! V_44 ) ) {
int V_104 ;
struct V_105 * V_106 = F_99 ( V_3 , & V_104 ) ;
V_44 = F_101 ( V_106 , 0 ) ;
F_100 ( V_3 , V_104 ) ;
}
if ( V_44 -> type -> V_108 && V_44 -> type -> V_108 ( V_44 ) )
return V_126 ;
F_80 ( V_3 , V_33 ) ;
F_74 ( V_22 , V_33 , V_3 ) ;
V_22 -> V_44 = V_44 ;
if ( F_76 ( V_22 ) == V_80 ) {
F_30 ( V_3 , V_33 ) ;
F_36 ( V_3 , F_34 ( V_33 ) , false ) ;
F_120 ( V_123 , 100 ) ;
return V_126 ;
}
return V_31 ;
}
int F_121 ( struct V_2 * V_3 , struct V_105 * V_110 )
{
struct V_12 * V_13 ;
struct V_75 * V_111 ;
int V_127 ;
if ( ! F_122 ( V_110 ) ) {
F_123 ( L_5 ) ;
return - V_96 ;
}
V_3 -> V_128 = F_124 ( sizeof( struct V_117 ) , V_129 , V_3 -> V_130 ) ;
if ( ! V_3 -> V_128 )
return - V_131 ;
V_3 -> V_128 -> V_132 = & V_133 ;
V_3 -> V_128 -> V_134 = F_6 () ;
V_3 -> V_128 -> V_120 = V_3 -> V_130 ;
V_3 -> V_128 -> V_14 = V_135 | V_136 ;
V_3 -> V_128 -> V_137 = F_5 () ;
V_3 -> V_128 -> V_121 = V_3 ;
V_3 -> V_128 -> V_112 = sizeof( struct V_21 ) ;
V_111 = F_108 ( V_110 ) ;
if ( V_111 && V_111 -> V_115 ) {
V_3 -> V_128 -> V_112 += V_111 -> V_115 ;
V_3 -> V_71 = true ;
}
V_127 = F_125 ( V_3 -> V_128 ) ;
if ( V_127 )
goto V_138;
V_13 = F_126 ( V_3 -> V_128 , V_3 -> V_11 ) ;
if ( F_115 ( V_13 ) ) {
V_127 = F_116 ( V_13 ) ;
goto V_139;
}
F_127 ( V_3 ) ;
V_127 = F_128 ( F_129 ( V_3 -> V_140 ) , V_13 ) ;
if ( V_127 )
goto V_141;
return 0 ;
V_141:
F_130 ( V_13 ) ;
V_139:
F_131 ( V_3 -> V_128 ) ;
V_138:
F_132 ( V_3 -> V_128 ) ;
return V_127 ;
}
void F_133 ( struct V_2 * V_3 )
{
if ( V_3 -> V_128 ) {
F_131 ( V_3 -> V_128 ) ;
F_132 ( V_3 -> V_128 ) ;
}
}
