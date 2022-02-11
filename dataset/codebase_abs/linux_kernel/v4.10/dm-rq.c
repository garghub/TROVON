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
static struct V_17 * F_24 ( struct V_2 * V_3 ,
T_1 V_18 )
{
return F_25 ( V_3 -> V_19 , V_18 ) ;
}
static void F_26 ( struct V_17 * V_20 )
{
F_27 ( V_20 , V_20 -> V_3 -> V_19 ) ;
}
static struct V_21 * F_28 ( struct V_2 * V_3 ,
T_1 V_18 )
{
return F_25 ( V_3 -> V_22 , V_18 ) ;
}
static void F_29 ( struct V_2 * V_3 , struct V_21 * V_23 )
{
F_27 ( V_23 , V_3 -> V_22 ) ;
}
static void F_30 ( struct V_24 * V_25 )
{
struct V_26 * V_27 =
F_31 ( V_25 , struct V_26 , V_25 ) ;
struct V_17 * V_20 = V_27 -> V_20 ;
struct V_24 * V_24 = V_27 -> V_28 ;
unsigned int V_29 = V_27 -> V_28 -> V_30 . V_31 ;
int error = V_25 -> V_32 ;
F_32 ( V_25 ) ;
if ( V_20 -> error )
return;
else if ( error ) {
V_20 -> error = error ;
return;
}
if ( V_20 -> V_28 -> V_24 != V_24 )
F_33 ( L_1 ) ;
F_34 ( V_20 -> V_28 , 0 , V_29 ) ;
}
static struct V_17 * F_35 ( struct V_21 * V_23 )
{
return ( V_23 -> V_13 -> V_16 ? F_36 ( V_23 ) : V_23 -> V_33 ) ;
}
static void F_37 ( struct V_2 * V_3 , struct V_21 * V_28 )
{
if ( F_38 ( F_39 ( & V_3 -> V_34 ) ) ) {
struct V_17 * V_20 = F_35 ( V_28 ) ;
V_20 -> V_35 = V_36 - V_20 -> V_35 ;
F_40 ( & V_3 -> V_34 , F_41 ( V_28 ) ,
F_42 ( V_28 ) , V_20 -> V_37 , true ,
V_20 -> V_35 , & V_20 -> V_38 ) ;
}
}
static void F_43 ( struct V_2 * V_3 , int V_39 , bool V_40 )
{
struct V_12 * V_13 = V_3 -> V_11 ;
unsigned long V_14 ;
F_44 ( & V_3 -> V_41 [ V_39 ] ) ;
if ( ! F_45 ( V_3 ) )
F_46 ( & V_3 -> V_42 ) ;
if ( ! V_13 -> V_16 && V_40 ) {
F_10 ( V_13 -> V_15 , V_14 ) ;
F_47 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
F_48 ( V_3 ) ;
}
static void F_49 ( struct V_21 * V_25 )
{
struct V_17 * V_20 = V_25 -> V_43 ;
struct V_2 * V_3 = V_20 -> V_3 ;
F_50 ( V_25 ) ;
if ( V_25 -> V_13 && V_25 -> V_13 -> V_16 )
V_20 -> V_44 -> type -> V_45 ( V_25 ) ;
else if ( ! V_3 -> V_11 -> V_16 )
F_29 ( V_3 , V_25 ) ;
if ( ! V_3 -> V_11 -> V_16 )
F_26 ( V_20 ) ;
}
static void F_51 ( struct V_21 * V_25 , int error )
{
int V_39 = F_41 ( V_25 ) ;
struct V_17 * V_20 = V_25 -> V_43 ;
struct V_2 * V_3 = V_20 -> V_3 ;
struct V_21 * V_23 = V_20 -> V_28 ;
if ( V_23 -> V_46 == V_47 ) {
V_23 -> V_48 = V_25 -> V_48 ;
V_23 -> V_49 = V_25 -> V_49 ;
if ( V_23 -> V_50 )
V_23 -> V_51 = V_25 -> V_51 ;
}
F_49 ( V_25 ) ;
F_37 ( V_3 , V_23 ) ;
if ( ! V_23 -> V_13 -> V_16 )
F_52 ( V_23 , error ) ;
else
F_53 ( V_23 , error ) ;
F_43 ( V_3 , V_39 , true ) ;
}
static void F_54 ( struct V_21 * V_23 )
{
struct V_17 * V_20 = F_35 ( V_23 ) ;
struct V_21 * V_25 = V_20 -> V_25 ;
if ( ! V_23 -> V_13 -> V_16 ) {
V_23 -> V_33 = NULL ;
V_23 -> V_52 &= ~ V_53 ;
}
if ( V_25 )
F_49 ( V_25 ) ;
else if ( ! V_20 -> V_3 -> V_11 -> V_16 )
F_26 ( V_20 ) ;
}
static void F_55 ( struct V_21 * V_23 )
{
struct V_12 * V_13 = V_23 -> V_13 ;
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_56 ( V_13 , V_23 ) ;
F_47 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_57 ( struct V_12 * V_13 , unsigned long V_54 )
{
F_58 ( V_13 , V_54 ) ;
}
void F_59 ( struct V_2 * V_3 )
{
F_57 ( F_60 ( V_3 ) , 0 ) ;
}
static void F_61 ( struct V_21 * V_23 , unsigned long V_54 )
{
F_62 ( V_23 , false ) ;
F_57 ( V_23 -> V_13 , V_54 ) ;
}
static void F_63 ( struct V_17 * V_20 , bool V_55 )
{
struct V_2 * V_3 = V_20 -> V_3 ;
struct V_21 * V_23 = V_20 -> V_28 ;
int V_39 = F_41 ( V_23 ) ;
F_37 ( V_3 , V_23 ) ;
F_54 ( V_23 ) ;
if ( ! V_23 -> V_13 -> V_16 )
F_55 ( V_23 ) ;
else
F_61 ( V_23 , V_55 ? 5000 : 0 ) ;
F_43 ( V_3 , V_39 , false ) ;
}
static void F_64 ( struct V_21 * V_25 , int error , bool V_56 )
{
int V_57 = error ;
struct V_17 * V_20 = V_25 -> V_43 ;
T_2 V_58 = NULL ;
if ( V_20 -> V_44 ) {
V_58 = V_20 -> V_44 -> type -> V_58 ;
if ( V_56 && V_58 )
V_57 = V_58 ( V_20 -> V_44 , V_25 , error , & V_20 -> V_27 ) ;
}
if ( F_38 ( V_57 == - V_59 && ( F_65 ( V_25 ) == V_60 ) &&
! V_25 -> V_13 -> V_61 . V_62 ) )
F_66 ( V_20 -> V_3 ) ;
if ( V_57 <= 0 )
F_51 ( V_25 , V_57 ) ;
else if ( V_57 == V_63 )
return;
else if ( V_57 == V_64 )
F_63 ( V_20 , false ) ;
else {
F_67 ( L_2 , V_57 ) ;
F_68 () ;
}
}
static void F_69 ( struct V_21 * V_23 )
{
bool V_56 = true ;
struct V_17 * V_20 = F_35 ( V_23 ) ;
struct V_21 * V_25 = V_20 -> V_25 ;
int V_39 ;
if ( ! V_25 ) {
F_37 ( V_20 -> V_3 , V_23 ) ;
V_39 = F_41 ( V_23 ) ;
if ( ! V_23 -> V_13 -> V_16 ) {
F_52 ( V_23 , V_20 -> error ) ;
F_43 ( V_20 -> V_3 , V_39 , false ) ;
F_26 ( V_20 ) ;
} else {
F_53 ( V_23 , V_20 -> error ) ;
F_43 ( V_20 -> V_3 , V_39 , false ) ;
}
return;
}
if ( V_23 -> V_52 & V_65 )
V_56 = false ;
F_64 ( V_25 , V_20 -> error , V_56 ) ;
}
static void F_70 ( struct V_21 * V_23 , int error )
{
struct V_17 * V_20 = F_35 ( V_23 ) ;
V_20 -> error = error ;
if ( ! V_23 -> V_13 -> V_16 )
F_71 ( V_23 ) ;
else
F_72 ( V_23 , error ) ;
}
static void F_73 ( struct V_21 * V_23 , int error )
{
V_23 -> V_52 |= V_65 ;
F_70 ( V_23 , error ) ;
}
static void F_74 ( struct V_21 * V_25 , int error )
{
struct V_17 * V_20 = V_25 -> V_43 ;
if ( ! V_25 -> V_13 -> V_16 ) {
F_75 ( V_25 -> V_13 , V_25 ) ;
}
F_70 ( V_20 -> V_28 , error ) ;
}
static void F_76 ( struct V_21 * V_25 , struct V_21 * V_23 )
{
int V_57 ;
if ( F_77 ( V_25 -> V_13 ) )
V_25 -> V_52 |= V_66 ;
V_25 -> V_67 = V_36 ;
V_57 = F_78 ( V_25 -> V_13 , V_25 ) ;
if ( V_57 )
F_70 ( V_23 , V_57 ) ;
}
static int F_79 ( struct V_24 * V_24 , struct V_24 * V_68 ,
void * V_69 )
{
struct V_17 * V_20 = V_69 ;
struct V_26 * V_27 =
F_31 ( V_24 , struct V_26 , V_25 ) ;
V_27 -> V_28 = V_68 ;
V_27 -> V_20 = V_20 ;
V_24 -> V_70 = F_30 ;
return 0 ;
}
static int F_80 ( struct V_21 * V_25 , struct V_21 * V_23 ,
struct V_17 * V_20 , T_1 V_18 )
{
int V_57 ;
V_57 = F_81 ( V_25 , V_23 , V_20 -> V_3 -> V_71 , V_18 ,
F_79 , V_20 ) ;
if ( V_57 )
return V_57 ;
V_25 -> V_72 = V_23 -> V_72 ;
V_25 -> V_73 = V_23 -> V_73 ;
V_25 -> V_50 = V_23 -> V_50 ;
V_25 -> V_74 = F_74 ;
V_25 -> V_43 = V_20 ;
V_20 -> V_25 = V_25 ;
return 0 ;
}
static struct V_21 * F_82 ( struct V_21 * V_23 , struct V_2 * V_3 ,
struct V_17 * V_20 , T_1 V_18 )
{
struct V_21 * V_25 ;
V_25 = F_28 ( V_3 , V_18 ) ;
if ( ! V_25 )
return NULL ;
F_83 ( NULL , V_25 ) ;
if ( F_80 ( V_25 , V_23 , V_20 , V_18 ) ) {
F_29 ( V_3 , V_25 ) ;
return NULL ;
}
return V_25 ;
}
static void F_84 ( struct V_17 * V_20 , struct V_21 * V_23 ,
struct V_2 * V_3 )
{
V_20 -> V_3 = V_3 ;
V_20 -> V_44 = NULL ;
V_20 -> V_25 = NULL ;
V_20 -> V_28 = V_23 ;
V_20 -> error = 0 ;
if ( ! V_3 -> V_75 )
memset ( & V_20 -> V_27 , 0 , sizeof( V_20 -> V_27 ) ) ;
if ( V_3 -> V_76 )
F_85 ( & V_20 -> V_77 , V_78 ) ;
}
static struct V_17 * F_86 ( struct V_21 * V_23 ,
struct V_2 * V_3 ,
T_1 V_18 )
{
struct V_17 * V_20 ;
int V_79 ;
struct V_80 * V_81 ;
V_20 = F_24 ( V_3 , V_18 ) ;
if ( ! V_20 )
return NULL ;
F_84 ( V_20 , V_23 , V_3 ) ;
V_81 = F_87 ( V_3 , & V_79 ) ;
if ( ! F_88 ( V_81 ) ) {
if ( ! F_82 ( V_23 , V_3 , V_20 , V_18 ) ) {
F_89 ( V_3 , V_79 ) ;
F_26 ( V_20 ) ;
return NULL ;
}
}
F_89 ( V_3 , V_79 ) ;
return V_20 ;
}
static int F_90 ( struct V_12 * V_13 , struct V_21 * V_23 )
{
struct V_2 * V_3 = V_13 -> V_82 ;
struct V_17 * V_20 ;
if ( F_38 ( V_23 -> V_33 ) ) {
F_67 ( L_3 ) ;
return V_83 ;
}
V_20 = F_86 ( V_23 , V_3 , V_84 ) ;
if ( ! V_20 )
return V_85 ;
V_23 -> V_33 = V_20 ;
V_23 -> V_52 |= V_53 ;
return V_86 ;
}
static int F_91 ( struct V_17 * V_20 )
{
int V_57 ;
struct V_87 * V_44 = V_20 -> V_44 ;
struct V_2 * V_3 = V_20 -> V_3 ;
struct V_21 * V_23 = V_20 -> V_28 ;
struct V_21 * V_25 = NULL ;
if ( V_20 -> V_25 ) {
V_25 = V_20 -> V_25 ;
V_57 = V_44 -> type -> V_88 ( V_44 , V_25 , & V_20 -> V_27 ) ;
if ( V_57 == V_89 )
return V_90 ;
} else {
V_57 = V_44 -> type -> V_91 ( V_44 , V_23 , & V_20 -> V_27 , & V_25 ) ;
if ( V_57 < 0 ) {
F_73 ( V_23 , V_57 ) ;
return V_57 ;
}
if ( V_57 == V_92 &&
F_80 ( V_25 , V_23 , V_20 , V_84 ) ) {
V_44 -> type -> V_45 ( V_25 ) ;
return V_90 ;
}
}
switch ( V_57 ) {
case V_93 :
break;
case V_92 :
F_92 ( V_25 -> V_13 , V_25 , F_93 ( F_94 ( V_3 ) ) ,
F_42 ( V_23 ) ) ;
F_76 ( V_25 , V_23 ) ;
break;
case V_90 :
break;
case V_89 :
F_63 ( V_20 , true ) ;
break;
default:
if ( V_57 > 0 ) {
F_67 ( L_4 , V_57 ) ;
F_68 () ;
}
F_73 ( V_23 , V_57 ) ;
}
return V_57 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_21 * V_28 )
{
if ( ! V_28 -> V_13 -> V_16 )
F_96 ( V_28 ) ;
else
F_97 ( V_28 ) ;
F_98 ( & V_3 -> V_41 [ F_41 ( V_28 ) ] ) ;
if ( V_3 -> V_94 ) {
V_3 -> V_95 = F_99 ( V_28 ) ;
V_3 -> V_96 = F_41 ( V_28 ) ;
V_3 -> V_97 = F_100 () ;
}
if ( F_38 ( F_39 ( & V_3 -> V_34 ) ) ) {
struct V_17 * V_20 = F_35 ( V_28 ) ;
V_20 -> V_35 = V_36 ;
V_20 -> V_37 = F_101 ( V_28 ) ;
F_40 ( & V_3 -> V_34 , F_41 ( V_28 ) ,
F_42 ( V_28 ) , V_20 -> V_37 , false , 0 ,
& V_20 -> V_38 ) ;
}
F_102 ( V_3 ) ;
}
static void V_78 ( struct V_98 * V_77 )
{
struct V_17 * V_20 = F_31 ( V_77 , struct V_17 , V_77 ) ;
if ( F_91 ( V_20 ) == V_90 )
F_63 ( V_20 , false ) ;
}
T_3 F_103 ( struct V_2 * V_3 , char * V_99 )
{
return sprintf ( V_99 , L_5 , V_3 -> V_94 ) ;
}
T_3 F_104 ( struct V_2 * V_3 ,
const char * V_99 , T_4 V_100 )
{
unsigned V_101 ;
if ( F_105 ( V_3 ) != V_102 )
return V_100 ;
if ( F_106 ( V_99 , 10 , & V_101 ) )
return - V_103 ;
if ( V_101 > V_104 )
V_101 = V_104 ;
V_3 -> V_94 = V_101 ;
return V_100 ;
}
static bool F_107 ( struct V_2 * V_3 )
{
T_5 V_105 ;
if ( ! V_3 -> V_94 )
return false ;
V_105 = F_108 ( ( V_106 ) V_3 -> V_94 * V_107 ) ;
V_105 = F_109 ( V_3 -> V_97 , V_105 ) ;
return ! F_110 ( F_100 () , V_105 ) ;
}
static void F_111 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_82 ;
struct V_87 * V_44 = V_3 -> V_108 ;
struct V_21 * V_23 ;
struct V_17 * V_20 ;
T_6 V_109 = 0 ;
if ( F_38 ( ! V_44 ) ) {
int V_79 ;
struct V_80 * V_110 = F_87 ( V_3 , & V_79 ) ;
if ( F_38 ( ! V_110 ) ) {
F_89 ( V_3 , V_79 ) ;
return;
}
V_44 = F_112 ( V_110 , V_109 ) ;
F_89 ( V_3 , V_79 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_23 = F_113 ( V_13 ) ;
if ( ! V_23 )
return;
V_109 = 0 ;
if ( F_65 ( V_23 ) != V_111 )
V_109 = F_42 ( V_23 ) ;
if ( ( F_107 ( V_3 ) &&
F_45 ( V_3 ) && V_23 -> V_24 && ! F_114 ( V_23 -> V_24 ) &&
V_3 -> V_95 == V_109 && V_3 -> V_96 == F_41 ( V_23 ) ) ||
( V_44 -> type -> V_112 && V_44 -> type -> V_112 ( V_44 ) ) ) {
F_115 ( V_13 , 10 ) ;
return;
}
F_95 ( V_3 , V_23 ) ;
V_20 = F_35 ( V_23 ) ;
V_20 -> V_44 = V_44 ;
F_116 ( & V_3 -> V_113 , & V_20 -> V_77 ) ;
F_117 ( ! F_118 () ) ;
}
}
int F_119 ( struct V_2 * V_3 )
{
if ( ! F_120 ( V_3 -> V_11 , F_111 , NULL ) )
return - V_103 ;
V_3 -> V_94 = 0 ;
F_121 ( V_3 ) ;
F_122 ( V_3 -> V_11 , F_69 ) ;
F_123 ( V_3 -> V_11 , F_90 ) ;
F_124 ( & V_3 -> V_113 ) ;
V_3 -> V_76 = F_125 ( V_114 , & V_3 -> V_113 ,
L_6 , F_126 ( V_3 ) ) ;
if ( F_127 ( V_3 -> V_76 ) ) {
int error = F_128 ( V_3 -> V_76 ) ;
V_3 -> V_76 = NULL ;
return error ;
}
F_129 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_130 ( void * V_69 , struct V_21 * V_23 ,
unsigned int V_115 , unsigned int V_116 ,
unsigned int V_117 )
{
struct V_2 * V_3 = V_69 ;
struct V_17 * V_20 = F_36 ( V_23 ) ;
V_20 -> V_3 = V_3 ;
if ( V_3 -> V_75 ) {
V_20 -> V_27 . V_118 = V_20 + 1 ;
}
return 0 ;
}
static int F_131 ( struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
struct V_21 * V_23 = V_122 -> V_23 ;
struct V_17 * V_20 = F_36 ( V_23 ) ;
struct V_2 * V_3 = V_20 -> V_3 ;
struct V_87 * V_44 = V_3 -> V_108 ;
if ( F_38 ( ! V_44 ) ) {
int V_79 ;
struct V_80 * V_110 = F_87 ( V_3 , & V_79 ) ;
V_44 = F_112 ( V_110 , 0 ) ;
F_89 ( V_3 , V_79 ) ;
}
if ( V_44 -> type -> V_112 && V_44 -> type -> V_112 ( V_44 ) )
return V_123 ;
F_95 ( V_3 , V_23 ) ;
F_84 ( V_20 , V_23 , V_3 ) ;
V_20 -> V_44 = V_44 ;
if ( F_91 ( V_20 ) == V_90 ) {
F_37 ( V_3 , V_23 ) ;
F_43 ( V_3 , F_41 ( V_23 ) , false ) ;
return V_123 ;
}
return V_124 ;
}
int F_132 ( struct V_2 * V_3 , struct V_80 * V_125 )
{
struct V_12 * V_13 ;
struct V_87 * V_126 ;
int V_127 ;
if ( ! F_88 ( V_125 ) ) {
F_33 ( L_7 ) ;
return - V_103 ;
}
V_3 -> V_128 = F_133 ( sizeof( struct V_129 ) , V_130 , V_3 -> V_131 ) ;
if ( ! V_3 -> V_128 )
return - V_132 ;
V_3 -> V_128 -> V_133 = & V_134 ;
V_3 -> V_128 -> V_135 = F_6 () ;
V_3 -> V_128 -> V_117 = V_3 -> V_131 ;
V_3 -> V_128 -> V_14 = V_136 | V_137 ;
V_3 -> V_128 -> V_138 = F_5 () ;
V_3 -> V_128 -> V_139 = V_3 ;
V_3 -> V_128 -> V_140 = sizeof( struct V_17 ) ;
V_126 = F_134 ( V_125 ) ;
if ( V_126 && V_126 -> V_141 ) {
V_3 -> V_128 -> V_140 += V_126 -> V_141 ;
V_3 -> V_75 = true ;
}
V_127 = F_135 ( V_3 -> V_128 ) ;
if ( V_127 )
goto V_142;
V_13 = F_136 ( V_3 -> V_128 , V_3 -> V_11 ) ;
if ( F_127 ( V_13 ) ) {
V_127 = F_128 ( V_13 ) ;
goto V_143;
}
F_137 ( V_3 ) ;
F_138 ( F_139 ( V_3 -> V_144 ) , V_13 ) ;
return 0 ;
V_143:
F_140 ( V_3 -> V_128 ) ;
V_142:
F_141 ( V_3 -> V_128 ) ;
return V_127 ;
}
void F_142 ( struct V_2 * V_3 )
{
if ( V_3 -> V_128 ) {
F_140 ( V_3 -> V_128 ) ;
F_141 ( V_3 -> V_128 ) ;
}
}
