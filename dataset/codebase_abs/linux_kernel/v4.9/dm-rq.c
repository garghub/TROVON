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
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
F_15 ( V_16 , V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
F_16 ( V_13 , true ) ;
F_17 ( V_13 ) ;
}
void F_18 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_17 )
F_9 ( V_13 ) ;
else
F_14 ( V_13 ) ;
}
static void F_19 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( ! F_11 ( V_13 ) )
F_20 ( V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
static void F_21 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( F_11 ( V_13 ) ) {
F_13 ( V_13 -> V_15 , V_14 ) ;
return;
}
F_22 ( V_16 , V_13 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
F_23 ( V_13 ) ;
F_24 ( V_13 ) ;
}
void F_25 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_17 )
F_19 ( V_13 ) ;
else
F_21 ( V_13 ) ;
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
return ( V_24 -> V_13 -> V_17 ? F_38 ( V_24 ) : V_24 -> V_34 ) ;
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
if ( ! V_3 -> V_11 -> V_17 && V_41 )
F_49 ( V_3 -> V_11 ) ;
F_50 ( V_3 ) ;
}
static void F_51 ( struct V_22 * V_26 )
{
struct V_18 * V_21 = V_26 -> V_44 ;
struct V_2 * V_3 = V_21 -> V_3 ;
F_52 ( V_26 ) ;
if ( V_26 -> V_13 && V_26 -> V_13 -> V_17 )
V_21 -> V_45 -> type -> V_46 ( V_26 ) ;
else if ( ! V_3 -> V_11 -> V_17 )
F_31 ( V_3 , V_26 ) ;
if ( ! V_3 -> V_11 -> V_17 )
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
if ( ! V_24 -> V_13 -> V_17 )
F_54 ( V_24 , error ) ;
else
F_55 ( V_24 , error ) ;
F_45 ( V_3 , V_40 , true ) ;
}
static void F_56 ( struct V_22 * V_24 )
{
struct V_18 * V_21 = F_37 ( V_24 ) ;
struct V_22 * V_26 = V_21 -> V_26 ;
if ( ! V_24 -> V_13 -> V_17 ) {
V_24 -> V_34 = NULL ;
V_24 -> V_53 &= ~ V_54 ;
}
if ( V_26 )
F_51 ( V_26 ) ;
else if ( ! V_21 -> V_3 -> V_11 -> V_17 )
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
static void F_59 ( struct V_12 * V_13 , unsigned long V_55 )
{
unsigned long V_14 ;
F_10 ( V_13 -> V_15 , V_14 ) ;
if ( ! F_11 ( V_13 ) )
F_60 ( V_13 , V_55 ) ;
F_13 ( V_13 -> V_15 , V_14 ) ;
}
void F_61 ( struct V_2 * V_3 )
{
F_59 ( F_62 ( V_3 ) , 0 ) ;
}
static void F_63 ( struct V_22 * V_24 , unsigned long V_55 )
{
F_64 ( V_24 ) ;
F_59 ( V_24 -> V_13 , V_55 ) ;
}
static void F_65 ( struct V_18 * V_21 , bool V_56 )
{
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_22 * V_24 = V_21 -> V_29 ;
int V_40 = F_43 ( V_24 ) ;
F_39 ( V_3 , V_24 ) ;
F_56 ( V_24 ) ;
if ( ! V_24 -> V_13 -> V_17 )
F_57 ( V_24 ) ;
else
F_63 ( V_24 , V_56 ? 5000 : 0 ) ;
F_45 ( V_3 , V_40 , false ) ;
}
static void F_66 ( struct V_22 * V_26 , int error , bool V_57 )
{
int V_58 = error ;
struct V_18 * V_21 = V_26 -> V_44 ;
T_2 V_59 = NULL ;
if ( V_21 -> V_45 ) {
V_59 = V_21 -> V_45 -> type -> V_59 ;
if ( V_57 && V_59 )
V_58 = V_59 ( V_21 -> V_45 , V_26 , error , & V_21 -> V_28 ) ;
}
if ( F_40 ( V_58 == - V_60 && ( F_67 ( V_26 ) == V_61 ) &&
! V_26 -> V_13 -> V_62 . V_63 ) )
F_68 ( V_21 -> V_3 ) ;
if ( V_58 <= 0 )
F_53 ( V_26 , V_58 ) ;
else if ( V_58 == V_64 )
return;
else if ( V_58 == V_65 )
F_65 ( V_21 , false ) ;
else {
F_69 ( L_2 , V_58 ) ;
F_70 () ;
}
}
static void F_71 ( struct V_22 * V_24 )
{
bool V_57 = true ;
struct V_18 * V_21 = F_37 ( V_24 ) ;
struct V_22 * V_26 = V_21 -> V_26 ;
int V_40 ;
if ( ! V_26 ) {
F_39 ( V_21 -> V_3 , V_24 ) ;
V_40 = F_43 ( V_24 ) ;
if ( ! V_24 -> V_13 -> V_17 ) {
F_54 ( V_24 , V_21 -> error ) ;
F_45 ( V_21 -> V_3 , V_40 , false ) ;
F_28 ( V_21 ) ;
} else {
F_55 ( V_24 , V_21 -> error ) ;
F_45 ( V_21 -> V_3 , V_40 , false ) ;
}
return;
}
if ( V_24 -> V_53 & V_66 )
V_57 = false ;
F_66 ( V_26 , V_21 -> error , V_57 ) ;
}
static void F_72 ( struct V_22 * V_24 , int error )
{
struct V_18 * V_21 = F_37 ( V_24 ) ;
V_21 -> error = error ;
if ( ! V_24 -> V_13 -> V_17 )
F_73 ( V_24 ) ;
else
F_74 ( V_24 , error ) ;
}
static void F_75 ( struct V_22 * V_24 , int error )
{
V_24 -> V_53 |= V_66 ;
F_72 ( V_24 , error ) ;
}
static void F_76 ( struct V_22 * V_26 , int error )
{
struct V_18 * V_21 = V_26 -> V_44 ;
if ( ! V_26 -> V_13 -> V_17 ) {
F_77 ( V_26 -> V_13 , V_26 ) ;
}
F_72 ( V_21 -> V_29 , error ) ;
}
static void F_78 ( struct V_22 * V_26 , struct V_22 * V_24 )
{
int V_58 ;
if ( F_79 ( V_26 -> V_13 ) )
V_26 -> V_53 |= V_67 ;
V_26 -> V_68 = V_37 ;
V_58 = F_80 ( V_26 -> V_13 , V_26 ) ;
if ( V_58 )
F_72 ( V_24 , V_58 ) ;
}
static int F_81 ( struct V_25 * V_25 , struct V_25 * V_69 ,
void * V_70 )
{
struct V_18 * V_21 = V_70 ;
struct V_27 * V_28 =
F_33 ( V_25 , struct V_27 , V_26 ) ;
V_28 -> V_29 = V_69 ;
V_28 -> V_21 = V_21 ;
V_25 -> V_71 = F_32 ;
return 0 ;
}
static int F_82 ( struct V_22 * V_26 , struct V_22 * V_24 ,
struct V_18 * V_21 , T_1 V_19 )
{
int V_58 ;
V_58 = F_83 ( V_26 , V_24 , V_21 -> V_3 -> V_72 , V_19 ,
F_81 , V_21 ) ;
if ( V_58 )
return V_58 ;
V_26 -> V_73 = V_24 -> V_73 ;
V_26 -> V_74 = V_24 -> V_74 ;
V_26 -> V_51 = V_24 -> V_51 ;
V_26 -> V_75 = F_76 ;
V_26 -> V_44 = V_21 ;
V_21 -> V_26 = V_26 ;
return 0 ;
}
static struct V_22 * F_84 ( struct V_22 * V_24 , struct V_2 * V_3 ,
struct V_18 * V_21 , T_1 V_19 )
{
struct V_22 * V_26 ;
V_26 = F_30 ( V_3 , V_19 ) ;
if ( ! V_26 )
return NULL ;
F_85 ( NULL , V_26 ) ;
if ( F_82 ( V_26 , V_24 , V_21 , V_19 ) ) {
F_31 ( V_3 , V_26 ) ;
return NULL ;
}
return V_26 ;
}
static void F_86 ( struct V_18 * V_21 , struct V_22 * V_24 ,
struct V_2 * V_3 )
{
V_21 -> V_3 = V_3 ;
V_21 -> V_45 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_29 = V_24 ;
V_21 -> error = 0 ;
if ( ! V_3 -> V_76 )
memset ( & V_21 -> V_28 , 0 , sizeof( V_21 -> V_28 ) ) ;
if ( V_3 -> V_77 )
F_87 ( & V_21 -> V_78 , V_79 ) ;
}
static struct V_18 * F_88 ( struct V_22 * V_24 ,
struct V_2 * V_3 ,
T_1 V_19 )
{
struct V_18 * V_21 ;
int V_80 ;
struct V_81 * V_82 ;
V_21 = F_26 ( V_3 , V_19 ) ;
if ( ! V_21 )
return NULL ;
F_86 ( V_21 , V_24 , V_3 ) ;
V_82 = F_89 ( V_3 , & V_80 ) ;
if ( ! F_90 ( V_82 ) ) {
if ( ! F_84 ( V_24 , V_3 , V_21 , V_19 ) ) {
F_91 ( V_3 , V_80 ) ;
F_28 ( V_21 ) ;
return NULL ;
}
}
F_91 ( V_3 , V_80 ) ;
return V_21 ;
}
static int F_92 ( struct V_12 * V_13 , struct V_22 * V_24 )
{
struct V_2 * V_3 = V_13 -> V_83 ;
struct V_18 * V_21 ;
if ( F_40 ( V_24 -> V_34 ) ) {
F_69 ( L_3 ) ;
return V_84 ;
}
V_21 = F_88 ( V_24 , V_3 , V_85 ) ;
if ( ! V_21 )
return V_86 ;
V_24 -> V_34 = V_21 ;
V_24 -> V_53 |= V_54 ;
return V_87 ;
}
static int F_93 ( struct V_18 * V_21 )
{
int V_58 ;
struct V_88 * V_45 = V_21 -> V_45 ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_22 * V_24 = V_21 -> V_29 ;
struct V_22 * V_26 = NULL ;
if ( V_21 -> V_26 ) {
V_26 = V_21 -> V_26 ;
V_58 = V_45 -> type -> V_89 ( V_45 , V_26 , & V_21 -> V_28 ) ;
if ( V_58 == V_90 )
return V_91 ;
} else {
V_58 = V_45 -> type -> V_92 ( V_45 , V_24 , & V_21 -> V_28 , & V_26 ) ;
if ( V_58 < 0 ) {
F_75 ( V_24 , V_58 ) ;
return V_58 ;
}
if ( V_58 == V_93 &&
F_82 ( V_26 , V_24 , V_21 , V_85 ) ) {
V_45 -> type -> V_46 ( V_26 ) ;
return V_91 ;
}
}
switch ( V_58 ) {
case V_94 :
break;
case V_93 :
F_94 ( V_26 -> V_13 , V_26 , F_95 ( F_96 ( V_3 ) ) ,
F_44 ( V_24 ) ) ;
F_78 ( V_26 , V_24 ) ;
break;
case V_91 :
break;
case V_90 :
F_65 ( V_21 , true ) ;
break;
default:
if ( V_58 > 0 ) {
F_69 ( L_4 , V_58 ) ;
F_70 () ;
}
F_75 ( V_24 , V_58 ) ;
}
return V_58 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_22 * V_29 )
{
if ( ! V_29 -> V_13 -> V_17 )
F_98 ( V_29 ) ;
else
F_99 ( V_29 ) ;
F_100 ( & V_3 -> V_42 [ F_43 ( V_29 ) ] ) ;
if ( V_3 -> V_95 ) {
V_3 -> V_96 = F_101 ( V_29 ) ;
V_3 -> V_97 = F_43 ( V_29 ) ;
V_3 -> V_98 = F_102 () ;
}
if ( F_40 ( F_41 ( & V_3 -> V_35 ) ) ) {
struct V_18 * V_21 = F_37 ( V_29 ) ;
V_21 -> V_36 = V_37 ;
V_21 -> V_38 = F_103 ( V_29 ) ;
F_42 ( & V_3 -> V_35 , F_43 ( V_29 ) ,
F_44 ( V_29 ) , V_21 -> V_38 , false , 0 ,
& V_21 -> V_39 ) ;
}
F_104 ( V_3 ) ;
}
static void V_79 ( struct V_99 * V_78 )
{
struct V_18 * V_21 = F_33 ( V_78 , struct V_18 , V_78 ) ;
if ( F_93 ( V_21 ) == V_91 )
F_65 ( V_21 , false ) ;
}
T_3 F_105 ( struct V_2 * V_3 , char * V_100 )
{
return sprintf ( V_100 , L_5 , V_3 -> V_95 ) ;
}
T_3 F_106 ( struct V_2 * V_3 ,
const char * V_100 , T_4 V_101 )
{
unsigned V_102 ;
if ( F_107 ( V_3 ) != V_103 )
return V_101 ;
if ( F_108 ( V_100 , 10 , & V_102 ) )
return - V_104 ;
if ( V_102 > V_105 )
V_102 = V_105 ;
V_3 -> V_95 = V_102 ;
return V_101 ;
}
static bool F_109 ( struct V_2 * V_3 )
{
T_5 V_106 ;
if ( ! V_3 -> V_95 )
return false ;
V_106 = F_110 ( ( V_107 ) V_3 -> V_95 * V_108 ) ;
V_106 = F_111 ( V_3 -> V_98 , V_106 ) ;
return ! F_112 ( F_102 () , V_106 ) ;
}
static void F_113 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_83 ;
struct V_88 * V_45 = V_3 -> V_109 ;
struct V_22 * V_24 ;
struct V_18 * V_21 ;
T_6 V_110 = 0 ;
if ( F_40 ( ! V_45 ) ) {
int V_80 ;
struct V_81 * V_111 = F_89 ( V_3 , & V_80 ) ;
V_45 = F_114 ( V_111 , V_110 ) ;
F_91 ( V_3 , V_80 ) ;
}
while ( ! F_11 ( V_13 ) ) {
V_24 = F_115 ( V_13 ) ;
if ( ! V_24 )
return;
V_110 = 0 ;
if ( F_67 ( V_24 ) != V_112 )
V_110 = F_44 ( V_24 ) ;
if ( ( F_109 ( V_3 ) &&
F_47 ( V_3 ) && V_24 -> V_25 && V_24 -> V_25 -> V_113 == 1 &&
V_3 -> V_96 == V_110 && V_3 -> V_97 == F_43 ( V_24 ) ) ||
( V_45 -> type -> V_114 && V_45 -> type -> V_114 ( V_45 ) ) ) {
F_116 ( V_13 , 10 ) ;
return;
}
F_97 ( V_3 , V_24 ) ;
V_21 = F_37 ( V_24 ) ;
V_21 -> V_45 = V_45 ;
F_117 ( & V_3 -> V_115 , & V_21 -> V_78 ) ;
F_118 ( ! F_119 () ) ;
}
}
int F_120 ( struct V_2 * V_3 )
{
if ( ! F_121 ( V_3 -> V_11 , F_113 , NULL ) )
return - V_104 ;
V_3 -> V_95 = 0 ;
F_122 ( V_3 ) ;
F_123 ( V_3 -> V_11 , F_71 ) ;
F_124 ( V_3 -> V_11 , F_92 ) ;
F_125 ( & V_3 -> V_115 ) ;
V_3 -> V_77 = F_126 ( V_116 , & V_3 -> V_115 ,
L_6 , F_127 ( V_3 ) ) ;
if ( F_128 ( V_3 -> V_77 ) ) {
int error = F_129 ( V_3 -> V_77 ) ;
V_3 -> V_77 = NULL ;
return error ;
}
F_130 ( V_3 -> V_11 ) ;
return 0 ;
}
static int F_131 ( void * V_70 , struct V_22 * V_24 ,
unsigned int V_117 , unsigned int V_118 ,
unsigned int V_119 )
{
struct V_2 * V_3 = V_70 ;
struct V_18 * V_21 = F_38 ( V_24 ) ;
V_21 -> V_3 = V_3 ;
if ( V_3 -> V_76 ) {
V_21 -> V_28 . V_120 = V_21 + 1 ;
}
return 0 ;
}
static int F_132 ( struct V_121 * V_122 ,
const struct V_123 * V_124 )
{
struct V_22 * V_24 = V_124 -> V_24 ;
struct V_18 * V_21 = F_38 ( V_24 ) ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_88 * V_45 = V_3 -> V_109 ;
if ( F_40 ( ! V_45 ) ) {
int V_80 ;
struct V_81 * V_111 = F_89 ( V_3 , & V_80 ) ;
V_45 = F_114 ( V_111 , 0 ) ;
F_91 ( V_3 , V_80 ) ;
}
if ( F_40 ( F_133 ( V_125 , & V_122 -> V_126 ) ) )
return V_127 ;
if ( V_45 -> type -> V_114 && V_45 -> type -> V_114 ( V_45 ) )
return V_127 ;
F_97 ( V_3 , V_24 ) ;
F_86 ( V_21 , V_24 , V_3 ) ;
V_21 -> V_45 = V_45 ;
if ( F_93 ( V_21 ) == V_91 ) {
F_39 ( V_3 , V_24 ) ;
F_45 ( V_3 , F_43 ( V_24 ) , false ) ;
return V_127 ;
}
return V_128 ;
}
int F_134 ( struct V_2 * V_3 , struct V_81 * V_129 )
{
struct V_12 * V_13 ;
struct V_88 * V_130 ;
int V_131 ;
if ( ! F_90 ( V_129 ) ) {
F_35 ( L_7 ) ;
return - V_104 ;
}
V_3 -> V_132 = F_135 ( sizeof( struct V_133 ) , V_134 , V_3 -> V_135 ) ;
if ( ! V_3 -> V_132 )
return - V_136 ;
V_3 -> V_132 -> V_137 = & V_138 ;
V_3 -> V_132 -> V_139 = F_6 () ;
V_3 -> V_132 -> V_119 = V_3 -> V_135 ;
V_3 -> V_132 -> V_14 = V_140 | V_141 ;
V_3 -> V_132 -> V_142 = F_5 () ;
V_3 -> V_132 -> V_143 = V_3 ;
V_3 -> V_132 -> V_144 = sizeof( struct V_18 ) ;
V_130 = F_136 ( V_129 ) ;
if ( V_130 && V_130 -> V_145 ) {
V_3 -> V_132 -> V_144 += V_130 -> V_145 ;
V_3 -> V_76 = true ;
}
V_131 = F_137 ( V_3 -> V_132 ) ;
if ( V_131 )
goto V_146;
V_13 = F_138 ( V_3 -> V_132 , V_3 -> V_11 ) ;
if ( F_128 ( V_13 ) ) {
V_131 = F_129 ( V_13 ) ;
goto V_147;
}
F_139 ( V_3 ) ;
F_140 ( F_141 ( V_3 -> V_148 ) , V_13 ) ;
return 0 ;
V_147:
F_142 ( V_3 -> V_132 ) ;
V_146:
F_143 ( V_3 -> V_132 ) ;
return V_131 ;
}
void F_144 ( struct V_2 * V_3 )
{
if ( V_3 -> V_132 ) {
F_142 ( V_3 -> V_132 ) ;
F_143 ( V_3 -> V_132 ) ;
}
}
