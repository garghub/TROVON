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
void F_14 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_16 )
F_9 ( V_13 ) ;
else {
F_15 ( V_17 , V_13 ) ;
F_16 ( V_13 , true ) ;
F_17 ( V_13 ) ;
}
}
static void F_18 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( F_11 ( V_13 ) ) {
F_13 ( V_13 -> V_15 , V_14 ) ;
return;
}
F_19 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
void F_20 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_16 )
F_18 ( V_13 ) ;
else {
F_21 ( V_13 -> V_15 ) ;
F_22 ( V_17 , V_13 ) ;
F_23 ( V_13 -> V_15 ) ;
F_24 ( V_13 ) ;
F_25 ( V_13 ) ;
}
}
static struct V_18 * F_26 ( struct V_2 * V_3 ,
T_1 V_19 )
{
return F_27 ( V_3 -> V_20 , V_19 ) ;
}
static void F_28 ( struct V_18 * V_21 )
{
F_29 ( V_21 , V_21 -> V_3 -> V_20 ) ;
}
static struct V_22 * F_30 ( struct V_2 * V_3 ,
T_1 V_19 )
{
return F_27 ( V_3 -> V_23 , V_19 ) ;
}
static void F_31 ( struct V_2 * V_3 , struct V_22 * V_24 )
{
F_29 ( V_24 , V_3 -> V_23 ) ;
}
static void F_32 ( struct V_25 * V_26 )
{
struct V_27 * V_28 =
F_33 ( V_26 , struct V_27 , V_26 ) ;
struct V_18 * V_21 = V_28 -> V_21 ;
struct V_25 * V_25 = V_28 -> V_29 ;
unsigned int V_30 = V_28 -> V_29 -> V_31 . V_32 ;
int error = V_26 -> V_33 ;
F_34 ( V_26 ) ;
if ( V_21 -> error )
return;
else if ( error ) {
V_21 -> error = error ;
return;
}
if ( V_21 -> V_29 -> V_25 != V_25 )
F_35 ( L_1 ) ;
F_36 ( V_21 -> V_29 , 0 , V_30 ) ;
}
static struct V_18 * F_37 ( struct V_22 * V_24 )
{
return ( V_24 -> V_13 -> V_16 ? F_38 ( V_24 ) : V_24 -> V_34 ) ;
}
static void F_39 ( struct V_2 * V_3 , struct V_22 * V_29 )
{
if ( F_40 ( F_41 ( & V_3 -> V_35 ) ) ) {
struct V_18 * V_21 = F_37 ( V_29 ) ;
V_21 -> V_36 = V_37 - V_21 -> V_36 ;
F_42 ( & V_3 -> V_35 , F_43 ( V_29 ) ,
F_44 ( V_29 ) , V_21 -> V_38 , true ,
V_21 -> V_36 , & V_21 -> V_39 ) ;
}
}
static void F_45 ( struct V_2 * V_3 , int V_40 , bool V_41 )
{
F_46 ( & V_3 -> V_42 [ V_40 ] ) ;
if ( ! F_47 ( V_3 ) )
F_48 ( & V_3 -> V_43 ) ;
if ( ! V_3 -> V_11 -> V_16 && V_41 )
F_49 ( V_3 -> V_11 ) ;
F_50 ( V_3 ) ;
}
static void F_51 ( struct V_22 * V_26 )
{
struct V_18 * V_21 = V_26 -> V_44 ;
struct V_2 * V_3 = V_21 -> V_3 ;
F_52 ( V_26 ) ;
if ( V_26 -> V_13 && V_26 -> V_13 -> V_16 )
V_21 -> V_45 -> type -> V_46 ( V_26 ) ;
else if ( ! V_3 -> V_11 -> V_16 )
F_31 ( V_3 , V_26 ) ;
if ( ! V_3 -> V_11 -> V_16 )
F_28 ( V_21 ) ;
}
static void F_53 ( struct V_22 * V_26 , int error )
{
int V_40 = F_43 ( V_26 ) ;
struct V_18 * V_21 = V_26 -> V_44 ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_22 * V_24 = V_21 -> V_29 ;
if ( V_24 -> V_47 == V_48 ) {
V_24 -> V_49 = V_26 -> V_49 ;
V_24 -> V_50 = V_26 -> V_50 ;
if ( V_24 -> V_51 )
V_24 -> V_52 = V_26 -> V_52 ;
}
F_51 ( V_26 ) ;
F_39 ( V_3 , V_24 ) ;
if ( ! V_24 -> V_13 -> V_16 )
F_54 ( V_24 , error ) ;
else
F_55 ( V_24 , error ) ;
F_45 ( V_3 , V_40 , true ) ;
}
static void F_56 ( struct V_22 * V_24 )
{
struct V_18 * V_21 = F_37 ( V_24 ) ;
struct V_22 * V_26 = V_21 -> V_26 ;
if ( ! V_24 -> V_13 -> V_16 ) {
V_24 -> V_34 = NULL ;
V_24 -> V_53 &= ~ V_54 ;
}
if ( V_26 )
F_51 ( V_26 ) ;
else if ( ! V_21 -> V_3 -> V_11 -> V_16 )
F_28 ( V_21 ) ;
}
static void F_57 ( struct V_22 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_13 ;
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_58 ( V_13 , V_24 ) ;
F_49 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_59 ( struct V_22 * V_24 )
{
struct V_12 * V_13 = V_24 -> V_13 ;
unsigned long V_14 ;
F_60 ( V_24 ) ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( ! F_11 ( V_13 ) )
F_17 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_22 * V_24 )
{
int V_40 = F_43 ( V_24 ) ;
F_39 ( V_3 , V_24 ) ;
F_56 ( V_24 ) ;
if ( ! V_24 -> V_13 -> V_16 )
F_57 ( V_24 ) ;
else
F_59 ( V_24 ) ;
F_45 ( V_3 , V_40 , false ) ;
}
static void F_62 ( struct V_22 * V_26 , int error , bool V_55 )
{
int V_56 = error ;
struct V_18 * V_21 = V_26 -> V_44 ;
T_2 V_57 = NULL ;
if ( V_21 -> V_45 ) {
V_57 = V_21 -> V_45 -> type -> V_57 ;
if ( V_55 && V_57 )
V_56 = V_57 ( V_21 -> V_45 , V_26 , error , & V_21 -> V_28 ) ;
}
if ( F_40 ( V_56 == - V_58 && ( F_63 ( V_26 ) == V_59 ) &&
! V_26 -> V_13 -> V_60 . V_61 ) )
F_64 ( V_21 -> V_3 ) ;
if ( V_56 <= 0 )
F_53 ( V_26 , V_56 ) ;
else if ( V_56 == V_62 )
return;
else if ( V_56 == V_63 )
F_61 ( V_21 -> V_3 , V_21 -> V_29 ) ;
else {
F_65 ( L_2 , V_56 ) ;
F_66 () ;
}
}
static void F_67 ( struct V_22 * V_24 )
{
bool V_55 = true ;
struct V_18 * V_21 = F_37 ( V_24 ) ;
struct V_22 * V_26 = V_21 -> V_26 ;
int V_40 ;
if ( ! V_26 ) {
F_39 ( V_21 -> V_3 , V_24 ) ;
V_40 = F_43 ( V_24 ) ;
if ( ! V_24 -> V_13 -> V_16 ) {
F_54 ( V_24 , V_21 -> error ) ;
F_45 ( V_21 -> V_3 , V_40 , false ) ;
F_28 ( V_21 ) ;
} else {
F_55 ( V_24 , V_21 -> error ) ;
F_45 ( V_21 -> V_3 , V_40 , false ) ;
}
return;
}
if ( V_24 -> V_53 & V_64 )
V_55 = false ;
F_62 ( V_26 , V_21 -> error , V_55 ) ;
}
static void F_68 ( struct V_22 * V_24 , int error )
{
struct V_18 * V_21 = F_37 ( V_24 ) ;
V_21 -> error = error ;
if ( ! V_24 -> V_13 -> V_16 )
F_69 ( V_24 ) ;
else
F_70 ( V_24 , error ) ;
}
static void F_71 ( struct V_22 * V_24 , int error )
{
V_24 -> V_53 |= V_64 ;
F_68 ( V_24 , error ) ;
}
static void F_72 ( struct V_22 * V_26 , int error )
{
struct V_18 * V_21 = V_26 -> V_44 ;
if ( ! V_26 -> V_13 -> V_16 ) {
F_73 ( V_26 -> V_13 , V_26 ) ;
}
F_68 ( V_21 -> V_29 , error ) ;
}
static void F_74 ( struct V_22 * V_26 , struct V_22 * V_24 )
{
int V_56 ;
if ( F_75 ( V_26 -> V_13 ) )
V_26 -> V_53 |= V_65 ;
V_26 -> V_66 = V_37 ;
V_56 = F_76 ( V_26 -> V_13 , V_26 ) ;
if ( V_56 )
F_68 ( V_24 , V_56 ) ;
}
static int F_77 ( struct V_25 * V_25 , struct V_25 * V_67 ,
void * V_68 )
{
struct V_18 * V_21 = V_68 ;
struct V_27 * V_28 =
F_33 ( V_25 , struct V_27 , V_26 ) ;
V_28 -> V_29 = V_67 ;
V_28 -> V_21 = V_21 ;
V_25 -> V_69 = F_32 ;
return 0 ;
}
static int F_78 ( struct V_22 * V_26 , struct V_22 * V_24 ,
struct V_18 * V_21 , T_1 V_19 )
{
int V_56 ;
V_56 = F_79 ( V_26 , V_24 , V_21 -> V_3 -> V_70 , V_19 ,
F_77 , V_21 ) ;
if ( V_56 )
return V_56 ;
V_26 -> V_71 = V_24 -> V_71 ;
V_26 -> V_72 = V_24 -> V_72 ;
V_26 -> V_51 = V_24 -> V_51 ;
V_26 -> V_73 = F_72 ;
V_26 -> V_44 = V_21 ;
V_21 -> V_26 = V_26 ;
return 0 ;
}
static struct V_22 * F_80 ( struct V_22 * V_24 , struct V_2 * V_3 ,
struct V_18 * V_21 , T_1 V_19 )
{
struct V_22 * V_26 ;
V_26 = F_30 ( V_3 , V_19 ) ;
if ( ! V_26 )
return NULL ;
F_81 ( NULL , V_26 ) ;
if ( F_78 ( V_26 , V_24 , V_21 , V_19 ) ) {
F_31 ( V_3 , V_26 ) ;
return NULL ;
}
return V_26 ;
}
static void F_82 ( struct V_18 * V_21 , struct V_22 * V_24 ,
struct V_2 * V_3 )
{
V_21 -> V_3 = V_3 ;
V_21 -> V_45 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_29 = V_24 ;
V_21 -> error = 0 ;
if ( ! V_3 -> V_74 )
memset ( & V_21 -> V_28 , 0 , sizeof( V_21 -> V_28 ) ) ;
if ( V_3 -> V_75 )
F_83 ( & V_21 -> V_76 , V_77 ) ;
}
static struct V_18 * F_84 ( struct V_22 * V_24 ,
struct V_2 * V_3 ,
T_1 V_19 )
{
struct V_18 * V_21 ;
int V_78 ;
struct V_79 * V_80 ;
V_21 = F_26 ( V_3 , V_19 ) ;
if ( ! V_21 )
return NULL ;
F_82 ( V_21 , V_24 , V_3 ) ;
V_80 = F_85 ( V_3 , & V_78 ) ;
if ( ! F_86 ( V_80 ) ) {
if ( ! F_80 ( V_24 , V_3 , V_21 , V_19 ) ) {
F_87 ( V_3 , V_78 ) ;
F_28 ( V_21 ) ;
return NULL ;
}
}
F_87 ( V_3 , V_78 ) ;
return V_21 ;
}
static int F_88 ( struct V_12 * V_13 , struct V_22 * V_24 )
{
struct V_2 * V_3 = V_13 -> V_81 ;
struct V_18 * V_21 ;
if ( F_40 ( V_24 -> V_34 ) ) {
F_65 ( L_3 ) ;
return V_82 ;
}
V_21 = F_84 ( V_24 , V_3 , V_83 ) ;
if ( ! V_21 )
return V_84 ;
V_24 -> V_34 = V_21 ;
V_24 -> V_53 |= V_54 ;
return V_85 ;
}
static int F_89 ( struct V_18 * V_21 , struct V_22 * V_24 ,
struct V_2 * V_3 )
{
int V_56 ;
struct V_86 * V_45 = V_21 -> V_45 ;
struct V_22 * V_26 = NULL ;
if ( V_21 -> V_26 ) {
V_26 = V_21 -> V_26 ;
V_56 = V_45 -> type -> V_87 ( V_45 , V_26 , & V_21 -> V_28 ) ;
} else {
V_56 = V_45 -> type -> V_88 ( V_45 , V_24 , & V_21 -> V_28 , & V_26 ) ;
if ( V_56 < 0 ) {
F_71 ( V_24 , V_56 ) ;
return V_56 ;
}
if ( V_56 != V_89 )
return V_56 ;
if ( F_78 ( V_26 , V_24 , V_21 , V_83 ) ) {
V_45 -> type -> V_46 ( V_26 ) ;
return V_90 ;
}
}
switch ( V_56 ) {
case V_91 :
break;
case V_89 :
F_90 ( V_26 -> V_13 , V_26 , F_91 ( F_92 ( V_3 ) ) ,
F_44 ( V_24 ) ) ;
F_74 ( V_26 , V_24 ) ;
break;
case V_90 :
F_61 ( V_3 , V_21 -> V_29 ) ;
break;
default:
if ( V_56 > 0 ) {
F_65 ( L_4 , V_56 ) ;
F_66 () ;
}
F_71 ( V_24 , V_56 ) ;
return V_56 ;
}
return 0 ;
}
static void F_93 ( struct V_2 * V_3 , struct V_22 * V_29 )
{
if ( ! V_29 -> V_13 -> V_16 )
F_94 ( V_29 ) ;
else
F_95 ( V_29 ) ;
F_96 ( & V_3 -> V_42 [ F_43 ( V_29 ) ] ) ;
if ( V_3 -> V_92 ) {
V_3 -> V_93 = F_97 ( V_29 ) ;
V_3 -> V_94 = F_43 ( V_29 ) ;
V_3 -> V_95 = F_98 () ;
}
if ( F_40 ( F_41 ( & V_3 -> V_35 ) ) ) {
struct V_18 * V_21 = F_37 ( V_29 ) ;
V_21 -> V_36 = V_37 ;
V_21 -> V_38 = F_99 ( V_29 ) ;
F_42 ( & V_3 -> V_35 , F_43 ( V_29 ) ,
F_44 ( V_29 ) , V_21 -> V_38 , false , 0 ,
& V_21 -> V_39 ) ;
}
F_100 ( V_3 ) ;
}
static void V_77 ( struct V_96 * V_76 )
{
struct V_18 * V_21 = F_33 ( V_76 , struct V_18 , V_76 ) ;
struct V_22 * V_24 = V_21 -> V_29 ;
struct V_2 * V_3 = V_21 -> V_3 ;
if ( F_89 ( V_21 , V_24 , V_3 ) == V_90 )
F_61 ( V_3 , V_24 ) ;
}
T_3 F_101 ( struct V_2 * V_3 , char * V_97 )
{
return sprintf ( V_97 , L_5 , V_3 -> V_92 ) ;
}
T_3 F_102 ( struct V_2 * V_3 ,
const char * V_97 , T_4 V_98 )
{
unsigned V_99 ;
if ( F_103 ( V_3 ) != V_100 )
return V_98 ;
if ( F_104 ( V_97 , 10 , & V_99 ) )
return - V_101 ;
if ( V_99 > V_102 )
V_99 = V_102 ;
V_3 -> V_92 = V_99 ;
return V_98 ;
}
static bool F_105 ( struct V_2 * V_3 )
{
T_5 V_103 ;
if ( ! V_3 -> V_92 )
return false ;
V_103 = F_106 ( ( V_104 ) V_3 -> V_92 * V_105 ) ;
V_103 = F_107 ( V_3 -> V_95 , V_103 ) ;
return ! F_108 ( F_98 () , V_103 ) ;
}
static void F_109 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_81 ;
struct V_86 * V_45 = V_3 -> V_106 ;
struct V_22 * V_24 ;
struct V_18 * V_21 ;
T_6 V_107 = 0 ;
if ( F_40 ( ! V_45 ) ) {
int V_78 ;
struct V_79 * V_108 = F_85 ( V_3 , & V_78 ) ;
V_45 = F_110 ( V_108 , V_107 ) ;
F_87 ( V_3 , V_78 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_24 = F_111 ( V_13 ) ;
if ( ! V_24 )
return;
V_107 = 0 ;
if ( F_63 ( V_24 ) != V_109 )
V_107 = F_44 ( V_24 ) ;
if ( ( F_105 ( V_3 ) &&
F_47 ( V_3 ) && V_24 -> V_25 && V_24 -> V_25 -> V_110 == 1 &&
V_3 -> V_93 == V_107 && V_3 -> V_94 == F_43 ( V_24 ) ) ||
( V_45 -> type -> V_111 && V_45 -> type -> V_111 ( V_45 ) ) ) {
F_112 ( V_13 , 10 ) ;
return;
}
F_93 ( V_3 , V_24 ) ;
V_21 = F_37 ( V_24 ) ;
V_21 -> V_45 = V_45 ;
F_113 ( & V_3 -> V_112 , & V_21 -> V_76 ) ;
F_114 ( ! F_115 () ) ;
}
}
int F_116 ( struct V_2 * V_3 )
{
if ( ! F_117 ( V_3 -> V_11 , F_109 , NULL ) )
return - V_101 ;
V_3 -> V_92 = 0 ;
F_118 ( V_3 ) ;
F_119 ( V_3 -> V_11 , F_67 ) ;
F_120 ( V_3 -> V_11 , F_88 ) ;
F_121 ( & V_3 -> V_112 ) ;
V_3 -> V_75 = F_122 ( V_113 , & V_3 -> V_112 ,
L_6 , F_123 ( V_3 ) ) ;
if ( F_124 ( V_3 -> V_75 ) )
return F_125 ( V_3 -> V_75 ) ;
F_126 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_127 ( void * V_68 , struct V_22 * V_24 ,
unsigned int V_114 , unsigned int V_115 ,
unsigned int V_116 )
{
struct V_2 * V_3 = V_68 ;
struct V_18 * V_21 = F_38 ( V_24 ) ;
V_21 -> V_3 = V_3 ;
if ( V_3 -> V_74 ) {
V_21 -> V_28 . V_117 = V_21 + 1 ;
}
return 0 ;
}
static int F_128 ( struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_22 * V_24 = V_121 -> V_24 ;
struct V_18 * V_21 = F_38 ( V_24 ) ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_86 * V_45 = V_3 -> V_106 ;
if ( F_40 ( ! V_45 ) ) {
int V_78 ;
struct V_79 * V_108 = F_85 ( V_3 , & V_78 ) ;
V_45 = F_110 ( V_108 , 0 ) ;
F_87 ( V_3 , V_78 ) ;
}
if ( F_40 ( F_129 ( V_122 , & V_119 -> V_123 ) ) )
return V_124 ;
if ( V_45 -> type -> V_111 && V_45 -> type -> V_111 ( V_45 ) )
return V_124 ;
F_93 ( V_3 , V_24 ) ;
F_82 ( V_21 , V_24 , V_3 ) ;
V_21 -> V_45 = V_45 ;
if ( F_89 ( V_21 , V_24 , V_3 ) == V_90 ) {
F_39 ( V_3 , V_24 ) ;
F_45 ( V_3 , F_43 ( V_24 ) , false ) ;
return V_124 ;
}
return V_125 ;
}
int F_130 ( struct V_2 * V_3 , struct V_79 * V_126 )
{
struct V_12 * V_13 ;
struct V_86 * V_127 ;
int V_128 ;
if ( ! F_86 ( V_126 ) ) {
F_35 ( L_7 ) ;
return - V_101 ;
}
V_3 -> V_129 = F_131 ( sizeof( struct V_130 ) , V_131 , V_3 -> V_132 ) ;
if ( ! V_3 -> V_129 )
return - V_133 ;
V_3 -> V_129 -> V_134 = & V_135 ;
V_3 -> V_129 -> V_136 = F_6 () ;
V_3 -> V_129 -> V_116 = V_3 -> V_132 ;
V_3 -> V_129 -> V_14 = V_137 | V_138 ;
V_3 -> V_129 -> V_139 = F_5 () ;
V_3 -> V_129 -> V_140 = V_3 ;
V_3 -> V_129 -> V_141 = sizeof( struct V_18 ) ;
V_127 = F_132 ( V_126 ) ;
if ( V_127 && V_127 -> V_142 ) {
V_3 -> V_129 -> V_141 += V_127 -> V_142 ;
V_3 -> V_74 = true ;
}
V_128 = F_133 ( V_3 -> V_129 ) ;
if ( V_128 )
goto V_143;
V_13 = F_134 ( V_3 -> V_129 , V_3 -> V_11 ) ;
if ( F_124 ( V_13 ) ) {
V_128 = F_125 ( V_13 ) ;
goto V_144;
}
F_135 ( V_3 ) ;
F_136 ( V_3 -> V_145 ) ;
return 0 ;
V_144:
F_137 ( V_3 -> V_129 ) ;
V_143:
F_138 ( V_3 -> V_129 ) ;
return V_128 ;
}
void F_139 ( struct V_2 * V_3 )
{
if ( V_3 -> V_129 ) {
F_137 ( V_3 -> V_129 ) ;
F_138 ( V_3 -> V_129 ) ;
}
}
