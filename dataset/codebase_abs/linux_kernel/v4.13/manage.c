static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 )
{
bool V_5 ;
do {
unsigned long V_6 ;
while ( F_3 ( & V_4 -> V_7 ) )
F_4 () ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_5 = F_3 ( & V_4 -> V_7 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
} while ( V_5 );
}
bool F_7 ( unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 ) {
F_2 ( V_4 ) ;
return ! F_9 ( & V_4 -> V_10 ) ;
}
return true ;
}
void F_10 ( unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 ) {
F_2 ( V_4 ) ;
F_11 ( V_4 -> V_11 ,
! F_9 ( & V_4 -> V_10 ) ) ;
}
}
static bool F_12 ( struct V_3 * V_4 )
{
if ( ! V_4 || ! F_13 ( & V_4 -> V_7 ) ||
! V_4 -> V_7 . V_12 || ! V_4 -> V_7 . V_12 -> V_13 )
return false ;
return true ;
}
int F_14 ( unsigned int V_9 )
{
return F_12 ( F_8 ( V_9 ) ) ;
}
bool F_15 ( unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
return F_12 ( V_4 ) &&
! F_16 ( & V_4 -> V_7 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
F_18 (desc, action)
if ( V_15 -> V_16 )
F_19 ( V_17 , & V_15 -> V_18 ) ;
}
int F_20 ( struct V_7 * V_19 , const struct V_20 * V_21 ,
bool V_22 )
{
struct V_3 * V_4 = F_21 ( V_19 ) ;
struct V_23 * V_12 = F_22 ( V_19 ) ;
int V_24 ;
V_24 = V_12 -> V_13 ( V_19 , V_21 , V_22 ) ;
switch ( V_24 ) {
case V_25 :
case V_26 :
F_23 ( V_4 -> V_27 . V_28 , V_21 ) ;
case V_29 :
F_17 ( V_4 ) ;
V_24 = 0 ;
}
return V_24 ;
}
int F_24 ( struct V_7 * V_19 , const struct V_20 * V_21 ,
bool V_22 )
{
struct V_23 * V_12 = F_22 ( V_19 ) ;
struct V_3 * V_4 = F_21 ( V_19 ) ;
int V_24 = 0 ;
if ( ! V_12 || ! V_12 -> V_13 )
return - V_30 ;
if ( F_25 ( V_19 ) ) {
V_24 = F_20 ( V_19 , V_21 , V_22 ) ;
} else {
F_26 ( V_19 ) ;
F_27 ( V_4 , V_21 ) ;
}
if ( V_4 -> V_31 ) {
F_28 ( & V_4 -> V_31 -> V_32 ) ;
F_29 ( & V_4 -> V_31 -> V_33 ) ;
}
F_30 ( V_19 , V_34 ) ;
return V_24 ;
}
int F_31 ( unsigned int V_9 , const struct V_20 * V_21 , bool V_22 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
unsigned long V_6 ;
int V_24 ;
if ( ! V_4 )
return - V_30 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_24 = F_24 ( F_32 ( V_4 ) , V_21 , V_22 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
return V_24 ;
}
int F_33 ( unsigned int V_9 , const struct V_20 * V_35 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , V_36 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_37 = V_35 ;
F_35 ( V_4 , V_6 ) ;
if ( V_35 )
F_31 ( V_9 , V_35 , false ) ;
return 0 ;
}
static void F_36 ( struct V_38 * V_33 )
{
struct F_36 * V_39 =
F_37 ( V_33 , struct F_36 , V_33 ) ;
struct V_3 * V_4 = F_8 ( V_39 -> V_9 ) ;
T_2 V_20 ;
unsigned long V_6 ;
if ( ! V_4 || ! F_38 ( & V_20 , V_40 ) )
goto V_41;
F_5 ( & V_4 -> V_8 , V_6 ) ;
if ( F_39 ( & V_4 -> V_7 ) )
F_40 ( V_20 , V_4 ) ;
else
F_23 ( V_20 , V_4 -> V_27 . V_28 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
V_39 -> V_39 ( V_39 , V_20 ) ;
F_41 ( V_20 ) ;
V_41:
F_42 ( & V_39 -> V_32 , V_39 -> V_42 ) ;
}
int
F_43 ( unsigned int V_9 , struct F_36 * V_39 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct F_36 * V_43 ;
unsigned long V_6 ;
F_44 () ;
if ( ! V_4 )
return - V_30 ;
if ( V_39 ) {
V_39 -> V_9 = V_9 ;
F_45 ( & V_39 -> V_32 ) ;
F_46 ( & V_39 -> V_33 , F_36 ) ;
}
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_43 = V_4 -> V_31 ;
V_4 -> V_31 = V_39 ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
if ( V_43 )
F_42 ( & V_43 -> V_32 , V_43 -> V_42 ) ;
return 0 ;
}
int F_47 ( struct V_3 * V_4 )
{
struct V_20 * V_44 = V_45 ;
int V_24 , V_46 = F_48 ( V_4 ) ;
static F_49 ( V_47 ) ;
static struct V_20 V_21 ;
if ( ! F_12 ( V_4 ) )
return 0 ;
F_50 ( & V_47 ) ;
if ( F_16 ( & V_4 -> V_7 ) ||
F_51 ( & V_4 -> V_7 , V_34 ) ) {
if ( F_52 ( V_4 -> V_27 . V_28 ,
V_48 ) )
V_44 = V_4 -> V_27 . V_28 ;
else
F_53 ( & V_4 -> V_7 , V_34 ) ;
}
F_54 ( & V_21 , V_48 , V_44 ) ;
if ( V_46 != V_49 ) {
const struct V_20 * V_50 = F_55 ( V_46 ) ;
if ( F_52 ( & V_21 , V_50 ) )
F_54 ( & V_21 , & V_21 , V_50 ) ;
}
V_24 = F_20 ( & V_4 -> V_7 , & V_21 , false ) ;
F_56 ( & V_47 ) ;
return V_24 ;
}
int F_47 ( struct V_3 * V_4 )
{
return F_57 ( F_58 ( V_4 ) ) ;
}
int F_59 ( unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
unsigned long V_6 ;
int V_24 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_24 = F_47 ( V_4 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
return V_24 ;
}
int F_60 ( unsigned int V_9 , void * V_51 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , 0 ) ;
struct V_7 * V_19 ;
struct V_23 * V_12 ;
int V_24 = - V_52 ;
if ( ! V_4 )
return - V_30 ;
V_19 = F_32 ( V_4 ) ;
V_12 = F_22 ( V_19 ) ;
if ( V_12 && V_12 -> F_60 )
V_24 = V_12 -> F_60 ( V_19 , V_51 ) ;
F_35 ( V_4 , V_6 ) ;
return V_24 ;
}
void F_61 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_53 ++ )
F_62 ( V_4 ) ;
}
static int F_63 ( unsigned int V_9 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_64 ( V_9 , & V_6 , V_36 ) ;
if ( ! V_4 )
return - V_30 ;
F_61 ( V_4 ) ;
F_65 ( V_4 , V_6 ) ;
return 0 ;
}
void F_66 ( unsigned int V_9 )
{
F_63 ( V_9 ) ;
}
void F_67 ( unsigned int V_9 )
{
if ( ! F_63 ( V_9 ) )
F_10 ( V_9 ) ;
}
bool F_68 ( unsigned int V_9 )
{
if ( ! F_63 ( V_9 ) )
return F_7 ( V_9 ) ;
return false ;
}
void F_69 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_53 ) {
case 0 :
V_54:
F_70 ( 1 , V_55 L_1 ,
F_58 ( V_4 ) ) ;
break;
case 1 : {
if ( V_4 -> V_56 & V_57 )
goto V_54;
F_71 ( V_4 ) ;
F_72 ( V_4 , V_58 , V_59 ) ;
break;
}
default:
V_4 -> V_53 -- ;
}
}
void F_73 ( unsigned int V_9 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_64 ( V_9 , & V_6 , V_36 ) ;
if ( ! V_4 )
return;
if ( F_70 ( ! V_4 -> V_7 . V_12 ,
V_60 L_2 , V_9 ) )
goto V_41;
F_69 ( V_4 ) ;
V_41:
F_65 ( V_4 , V_6 ) ;
}
static int F_74 ( unsigned int V_9 , unsigned int V_61 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
int V_24 = - V_62 ;
if ( F_75 ( V_4 ) -> V_6 & V_63 )
return 0 ;
if ( V_4 -> V_7 . V_12 -> V_64 )
V_24 = V_4 -> V_7 . V_12 -> V_64 ( & V_4 -> V_7 , V_61 ) ;
return V_24 ;
}
int F_76 ( unsigned int V_9 , unsigned int V_61 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_64 ( V_9 , & V_6 , V_36 ) ;
int V_24 = 0 ;
if ( ! V_4 )
return - V_30 ;
if ( V_61 ) {
if ( V_4 -> V_65 ++ == 0 ) {
V_24 = F_74 ( V_9 , V_61 ) ;
if ( V_24 )
V_4 -> V_65 = 0 ;
else
F_30 ( & V_4 -> V_7 , V_66 ) ;
}
} else {
if ( V_4 -> V_65 == 0 ) {
F_70 ( 1 , L_3 , V_9 ) ;
} else if ( -- V_4 -> V_65 == 0 ) {
V_24 = F_74 ( V_9 , V_61 ) ;
if ( V_24 )
V_4 -> V_65 = 1 ;
else
F_53 ( & V_4 -> V_7 , V_66 ) ;
}
}
F_65 ( V_4 , V_6 ) ;
return V_24 ;
}
int F_77 ( unsigned int V_9 , unsigned long V_67 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , 0 ) ;
int V_68 = 0 ;
if ( ! V_4 )
return 0 ;
if ( F_78 ( V_4 ) ) {
if ( ! V_4 -> V_15 ||
V_67 & V_4 -> V_15 -> V_6 & V_69 )
V_68 = 1 ;
}
F_35 ( V_4 , V_6 ) ;
return V_68 ;
}
int F_79 ( struct V_3 * V_4 , unsigned long V_6 )
{
struct V_23 * V_12 = V_4 -> V_7 . V_12 ;
int V_24 , V_70 = 0 ;
if ( ! V_12 || ! V_12 -> V_71 ) {
F_80 ( L_4 ,
F_58 ( V_4 ) ,
V_12 ? ( V_12 -> V_72 ? : L_5 ) : L_5 ) ;
return 0 ;
}
if ( V_12 -> V_6 & V_73 ) {
if ( ! F_81 ( & V_4 -> V_7 ) )
F_82 ( V_4 ) ;
if ( ! F_83 ( & V_4 -> V_7 ) )
V_70 = 1 ;
}
V_6 &= V_74 ;
V_24 = V_12 -> V_71 ( & V_4 -> V_7 , V_6 ) ;
switch ( V_24 ) {
case V_25 :
case V_26 :
F_53 ( & V_4 -> V_7 , V_75 ) ;
F_30 ( & V_4 -> V_7 , V_6 ) ;
case V_29 :
V_6 = F_84 ( & V_4 -> V_7 ) ;
F_85 ( V_4 , V_6 ) ;
F_53 ( & V_4 -> V_7 , V_76 ) ;
F_86 ( V_4 ) ;
if ( V_6 & V_77 ) {
F_87 ( V_4 ) ;
F_30 ( & V_4 -> V_7 , V_76 ) ;
}
V_24 = 0 ;
break;
default:
F_88 ( L_6 ,
V_6 , F_58 ( V_4 ) , V_12 -> V_71 ) ;
}
if ( V_70 )
F_89 ( V_4 ) ;
return V_24 ;
}
int F_90 ( int V_9 , int V_78 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_78 = V_78 ;
F_35 ( V_4 , V_6 ) ;
return 0 ;
}
static T_3 F_91 ( int V_9 , void * V_79 )
{
return V_80 ;
}
static T_3 F_92 ( int V_9 , void * V_79 )
{
F_70 ( 1 , L_7 , V_9 ) ;
return V_81 ;
}
static T_3 F_93 ( int V_9 , void * V_79 )
{
F_70 ( 1 , L_8 , V_9 ) ;
return V_81 ;
}
static int F_94 ( struct V_14 * V_15 )
{
F_95 ( V_82 ) ;
while ( ! F_96 () ) {
if ( F_97 ( V_83 ,
& V_15 -> V_18 ) ) {
F_98 ( V_84 ) ;
return 0 ;
}
F_99 () ;
F_95 ( V_82 ) ;
}
F_98 ( V_84 ) ;
return - 1 ;
}
static void F_100 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
if ( ! ( V_4 -> V_56 & V_85 ) ||
V_15 -> V_86 == F_93 )
return;
V_87:
F_101 ( V_4 ) ;
F_102 ( & V_4 -> V_8 ) ;
if ( F_103 ( F_3 ( & V_4 -> V_7 ) ) ) {
F_104 ( & V_4 -> V_8 ) ;
F_105 ( V_4 ) ;
F_4 () ;
goto V_87;
}
if ( F_106 ( V_83 , & V_15 -> V_18 ) )
goto V_88;
V_4 -> V_89 &= ~ V_15 -> V_90 ;
if ( ! V_4 -> V_89 && ! F_83 ( & V_4 -> V_7 ) &&
F_81 ( & V_4 -> V_7 ) )
F_107 ( V_4 ) ;
V_88:
F_104 ( & V_4 -> V_8 ) ;
F_105 ( V_4 ) ;
}
static void
F_108 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_21 ;
bool V_91 = true ;
if ( ! F_97 ( V_17 , & V_15 -> V_18 ) )
return;
if ( ! F_38 ( & V_21 , V_40 ) ) {
F_19 ( V_17 , & V_15 -> V_18 ) ;
return;
}
F_102 ( & V_4 -> V_8 ) ;
if ( F_109 ( V_4 -> V_27 . V_28 ) )
F_23 ( V_21 , V_4 -> V_27 . V_28 ) ;
else
V_91 = false ;
F_104 ( & V_4 -> V_8 ) ;
if ( V_91 )
F_110 ( V_92 , V_21 ) ;
F_41 ( V_21 ) ;
}
static inline void
F_108 ( struct V_3 * V_4 , struct V_14 * V_15 ) { }
static T_3
F_111 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_3 V_24 ;
F_112 () ;
V_24 = V_15 -> V_93 ( V_15 -> V_9 , V_15 -> V_79 ) ;
F_100 ( V_4 , V_15 ) ;
F_113 () ;
return V_24 ;
}
static T_3 F_114 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
T_3 V_24 ;
V_24 = V_15 -> V_93 ( V_15 -> V_9 , V_15 -> V_79 ) ;
F_100 ( V_4 , V_15 ) ;
return V_24 ;
}
static void F_115 ( struct V_3 * V_4 )
{
if ( F_116 ( & V_4 -> V_10 ) )
F_117 ( & V_4 -> V_11 ) ;
}
static void F_118 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_92 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
if ( F_119 ( ! ( V_92 -> V_6 & V_98 ) ) )
return;
V_15 = F_120 ( V_97 ) ;
F_88 ( L_9 ,
V_97 -> V_99 , V_97 -> V_100 , V_15 -> V_9 ) ;
V_4 = F_8 ( V_15 -> V_9 ) ;
if ( F_97 ( V_83 , & V_15 -> V_18 ) )
F_115 ( V_4 ) ;
F_100 ( V_4 , V_15 ) ;
}
static void F_121 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
struct V_14 * V_101 = V_15 -> V_101 ;
if ( F_119 ( ! V_101 ) )
return;
F_102 ( & V_4 -> V_8 ) ;
F_122 ( V_4 , V_101 ) ;
F_104 ( & V_4 -> V_8 ) ;
}
static int F_123 ( void * V_19 )
{
struct V_94 V_102 ;
struct V_14 * V_15 = V_19 ;
struct V_3 * V_4 = F_8 ( V_15 -> V_9 ) ;
T_3 (* F_124)( struct V_3 * V_4 ,
struct V_14 * V_15 );
if ( V_2 && F_106 ( V_103 ,
& V_15 -> V_18 ) )
F_124 = F_111 ;
else
F_124 = F_114 ;
F_125 ( & V_102 , F_118 ) ;
F_126 ( V_92 , & V_102 , false ) ;
F_108 ( V_4 , V_15 ) ;
while ( ! F_94 ( V_15 ) ) {
T_3 V_104 ;
F_108 ( V_4 , V_15 ) ;
V_104 = F_124 ( V_4 , V_15 ) ;
if ( V_104 == V_105 )
F_127 ( & V_4 -> V_106 ) ;
if ( V_104 == V_80 )
F_121 ( V_4 , V_15 ) ;
F_115 ( V_4 ) ;
}
F_128 ( V_92 , F_118 ) ;
return 0 ;
}
void F_129 ( unsigned int V_9 , void * V_79 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
unsigned long V_6 ;
if ( ! V_4 || F_130 ( F_131 ( V_4 ) ) )
return;
F_5 ( & V_4 -> V_8 , V_6 ) ;
F_18 (desc, action) {
if ( V_15 -> V_79 == V_79 ) {
if ( V_15 -> V_16 )
F_122 ( V_4 , V_15 ) ;
break;
}
}
F_6 ( & V_4 -> V_8 , V_6 ) ;
}
static int F_132 ( struct V_14 * V_107 )
{
if ( ! V_2 )
return 0 ;
if ( V_107 -> V_6 & ( V_108 | V_109 | V_110 ) )
return 0 ;
V_107 -> V_6 |= V_110 ;
if ( V_107 -> V_86 != F_91 && V_107 -> V_93 ) {
V_107 -> V_101 = F_133 ( sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_107 -> V_101 )
return - V_111 ;
V_107 -> V_101 -> V_86 = F_93 ;
V_107 -> V_101 -> V_93 = V_107 -> V_93 ;
V_107 -> V_101 -> V_79 = V_107 -> V_79 ;
V_107 -> V_101 -> V_9 = V_107 -> V_9 ;
V_107 -> V_101 -> V_72 = V_107 -> V_72 ;
}
F_19 ( V_103 , & V_107 -> V_18 ) ;
V_107 -> V_93 = V_107 -> V_86 ;
V_107 -> V_86 = F_91 ;
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_7 * V_112 = & V_4 -> V_7 ;
struct V_23 * V_113 = V_112 -> V_12 ;
return V_113 -> F_134 ? V_113 -> F_134 ( V_112 ) : 0 ;
}
static void F_135 ( struct V_3 * V_4 )
{
struct V_7 * V_112 = & V_4 -> V_7 ;
struct V_23 * V_113 = V_112 -> V_12 ;
if ( V_113 -> F_135 )
V_113 -> F_135 ( V_112 ) ;
}
static int
F_136 ( struct V_14 * V_107 , unsigned int V_9 , bool V_101 )
{
struct V_96 * V_114 ;
struct V_115 V_116 = {
. V_117 = V_118 / 2 ,
} ;
if ( ! V_101 ) {
V_114 = F_137 ( F_123 , V_107 , L_10 , V_9 ,
V_107 -> V_72 ) ;
} else {
V_114 = F_137 ( F_123 , V_107 , L_11 , V_9 ,
V_107 -> V_72 ) ;
V_116 . V_117 -= 1 ;
}
if ( F_138 ( V_114 ) )
return F_139 ( V_114 ) ;
F_140 ( V_114 , V_119 , & V_116 ) ;
F_141 ( V_114 ) ;
V_107 -> V_16 = V_114 ;
F_19 ( V_17 , & V_107 -> V_18 ) ;
return 0 ;
}
static int
F_142 ( unsigned int V_9 , struct V_3 * V_4 , struct V_14 * V_107 )
{
struct V_14 * V_120 , * * V_121 ;
unsigned long V_6 , V_90 = 0 ;
int V_24 , V_122 , V_123 = 0 ;
if ( ! V_4 )
return - V_30 ;
if ( V_4 -> V_7 . V_12 == & V_124 )
return - V_52 ;
if ( ! F_143 ( V_4 -> V_125 ) )
return - V_126 ;
V_107 -> V_9 = V_9 ;
if ( ! ( V_107 -> V_6 & V_127 ) )
V_107 -> V_6 |= F_84 ( & V_4 -> V_7 ) ;
V_122 = F_144 ( V_4 ) ;
if ( V_122 ) {
if ( ! V_107 -> V_93 ) {
V_24 = - V_30 ;
goto V_128;
}
V_107 -> V_86 = F_92 ;
} else {
if ( F_145 ( V_4 ) ) {
V_24 = F_132 ( V_107 ) ;
if ( V_24 )
goto V_128;
}
}
if ( V_107 -> V_93 && ! V_122 ) {
V_24 = F_136 ( V_107 , V_9 , false ) ;
if ( V_24 )
goto V_128;
if ( V_107 -> V_101 ) {
V_24 = F_136 ( V_107 -> V_101 , V_9 , true ) ;
if ( V_24 )
goto V_129;
}
}
if ( V_4 -> V_7 . V_12 -> V_6 & V_130 )
V_107 -> V_6 &= ~ V_110 ;
F_146 ( & V_4 -> V_131 ) ;
F_101 ( V_4 ) ;
if ( ! V_4 -> V_15 ) {
V_24 = F_134 ( V_4 ) ;
if ( V_24 ) {
F_88 ( L_12 ,
V_107 -> V_72 , V_9 , V_4 -> V_7 . V_12 -> V_72 ) ;
goto V_132;
}
}
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_121 = & V_4 -> V_15 ;
V_120 = * V_121 ;
if ( V_120 ) {
unsigned int V_133 = F_84 ( & V_4 -> V_7 ) ;
if ( ! ( ( V_120 -> V_6 & V_107 -> V_6 ) & V_69 ) ||
( V_133 != ( V_107 -> V_6 & V_127 ) ) ||
( ( V_120 -> V_6 ^ V_107 -> V_6 ) & V_110 ) )
goto V_134;
if ( ( V_120 -> V_6 & V_109 ) !=
( V_107 -> V_6 & V_109 ) )
goto V_134;
do {
V_90 |= V_120 -> V_90 ;
V_121 = & V_120 -> V_135 ;
V_120 = * V_121 ;
} while ( V_120 );
V_123 = 1 ;
}
if ( V_107 -> V_6 & V_110 ) {
if ( V_90 == ~ 0UL ) {
V_24 = - V_136 ;
goto V_88;
}
V_107 -> V_90 = 1 << F_147 ( V_90 ) ;
} else if ( V_107 -> V_86 == F_91 &&
! ( V_4 -> V_7 . V_12 -> V_6 & V_130 ) ) {
F_88 ( L_13 ,
V_9 ) ;
V_24 = - V_30 ;
goto V_88;
}
if ( ! V_123 ) {
F_148 ( & V_4 -> V_11 ) ;
if ( V_107 -> V_6 & V_127 ) {
V_24 = F_79 ( V_4 ,
V_107 -> V_6 & V_127 ) ;
if ( V_24 )
goto V_88;
}
V_4 -> V_56 &= ~ ( V_137 | V_138 | \
V_85 | V_139 ) ;
F_53 ( & V_4 -> V_7 , V_140 ) ;
if ( V_107 -> V_6 & V_109 ) {
F_30 ( & V_4 -> V_7 , V_141 ) ;
F_149 ( V_4 ) ;
}
if ( V_107 -> V_6 & V_110 )
V_4 -> V_56 |= V_85 ;
if ( V_107 -> V_6 & V_142 ) {
F_150 ( V_4 ) ;
F_30 ( & V_4 -> V_7 , V_143 ) ;
}
if ( F_151 ( V_4 ) ) {
F_72 ( V_4 , V_58 , V_59 ) ;
} else {
F_119 ( V_107 -> V_6 & V_69 ) ;
V_4 -> V_53 = 1 ;
}
} else if ( V_107 -> V_6 & V_127 ) {
unsigned int V_144 = V_107 -> V_6 & V_127 ;
unsigned int V_145 = F_84 ( & V_4 -> V_7 ) ;
if ( V_144 != V_145 )
F_152 ( L_14 ,
V_9 , V_145 , V_144 ) ;
}
* V_121 = V_107 ;
F_153 ( V_4 , V_107 ) ;
V_4 -> V_146 = 0 ;
V_4 -> V_147 = 0 ;
if ( V_123 && ( V_4 -> V_56 & V_138 ) ) {
V_4 -> V_56 &= ~ V_138 ;
F_69 ( V_4 ) ;
}
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_105 ( V_4 ) ;
F_154 ( & V_4 -> V_131 ) ;
F_155 ( V_4 , V_107 ) ;
if ( V_107 -> V_16 )
F_156 ( V_107 -> V_16 ) ;
if ( V_107 -> V_101 )
F_156 ( V_107 -> V_101 -> V_16 ) ;
F_157 ( V_9 , V_4 ) ;
F_158 ( V_9 , V_4 ) ;
V_107 -> V_148 = NULL ;
F_159 ( V_9 , V_107 ) ;
return 0 ;
V_134:
if ( ! ( V_107 -> V_6 & V_149 ) ) {
F_88 ( L_15 ,
V_9 , V_107 -> V_6 , V_107 -> V_72 , V_120 -> V_6 , V_120 -> V_72 ) ;
#ifdef F_160
F_161 () ;
#endif
}
V_24 = - V_136 ;
V_88:
F_6 ( & V_4 -> V_8 , V_6 ) ;
if ( ! V_4 -> V_15 )
F_135 ( V_4 ) ;
V_132:
F_105 ( V_4 ) ;
F_154 ( & V_4 -> V_131 ) ;
V_129:
if ( V_107 -> V_16 ) {
struct V_96 * V_114 = V_107 -> V_16 ;
V_107 -> V_16 = NULL ;
F_162 ( V_114 ) ;
F_163 ( V_114 ) ;
}
if ( V_107 -> V_101 && V_107 -> V_101 -> V_16 ) {
struct V_96 * V_114 = V_107 -> V_101 -> V_16 ;
V_107 -> V_101 -> V_16 = NULL ;
F_162 ( V_114 ) ;
F_163 ( V_114 ) ;
}
V_128:
F_164 ( V_4 -> V_125 ) ;
return V_24 ;
}
int F_165 ( unsigned int V_9 , struct V_14 * V_150 )
{
int V_151 ;
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || F_130 ( F_131 ( V_4 ) ) )
return - V_30 ;
V_151 = F_166 ( & V_4 -> V_7 ) ;
if ( V_151 < 0 )
return V_151 ;
V_151 = F_142 ( V_9 , V_4 , V_150 ) ;
if ( V_151 )
F_167 ( & V_4 -> V_7 ) ;
return V_151 ;
}
static struct V_14 * F_168 ( unsigned int V_9 , void * V_79 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 , * * V_152 ;
unsigned long V_6 ;
F_70 ( F_169 () , L_16 , V_9 ) ;
if ( ! V_4 )
return NULL ;
F_146 ( & V_4 -> V_131 ) ;
F_101 ( V_4 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_152 = & V_4 -> V_15 ;
for (; ; ) {
V_15 = * V_152 ;
if ( ! V_15 ) {
F_70 ( 1 , L_17 , V_9 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_105 ( V_4 ) ;
F_154 ( & V_4 -> V_131 ) ;
return NULL ;
}
if ( V_15 -> V_79 == V_79 )
break;
V_152 = & V_15 -> V_135 ;
}
* V_152 = V_15 -> V_135 ;
F_170 ( V_4 , V_15 ) ;
if ( ! V_4 -> V_15 ) {
F_171 ( V_4 ) ;
F_172 ( V_4 ) ;
}
#ifdef F_173
if ( F_119 ( V_4 -> V_37 ) )
V_4 -> V_37 = NULL ;
#endif
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_105 ( V_4 ) ;
F_174 ( V_9 , V_15 ) ;
F_10 ( V_9 ) ;
#ifdef F_160
if ( V_15 -> V_6 & V_69 ) {
F_175 ( V_6 ) ;
V_15 -> V_86 ( V_9 , V_79 ) ;
F_176 ( V_6 ) ;
}
#endif
if ( V_15 -> V_16 ) {
F_162 ( V_15 -> V_16 ) ;
F_163 ( V_15 -> V_16 ) ;
if ( V_15 -> V_101 && V_15 -> V_101 -> V_16 ) {
F_162 ( V_15 -> V_101 -> V_16 ) ;
F_163 ( V_15 -> V_101 -> V_16 ) ;
}
}
if ( ! V_4 -> V_15 ) {
F_101 ( V_4 ) ;
F_135 ( V_4 ) ;
F_105 ( V_4 ) ;
F_177 ( V_4 ) ;
}
F_154 ( & V_4 -> V_131 ) ;
F_167 ( & V_4 -> V_7 ) ;
F_164 ( V_4 -> V_125 ) ;
F_178 ( V_15 -> V_101 ) ;
return V_15 ;
}
void F_179 ( unsigned int V_9 , struct V_14 * V_150 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 && ! F_130 ( F_131 ( V_4 ) ) )
F_168 ( V_9 , V_150 -> V_79 ) ;
}
const void * F_180 ( unsigned int V_9 , void * V_79 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
const char * V_153 ;
if ( ! V_4 || F_130 ( F_131 ( V_4 ) ) )
return NULL ;
#ifdef F_173
if ( F_130 ( V_4 -> V_31 ) )
V_4 -> V_31 = NULL ;
#endif
V_15 = F_168 ( V_9 , V_79 ) ;
V_153 = V_15 -> V_72 ;
F_178 ( V_15 ) ;
return V_153 ;
}
int F_181 ( unsigned int V_9 , T_4 V_86 ,
T_4 V_93 , unsigned long V_67 ,
const char * V_153 , void * V_79 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_151 ;
if ( V_9 == V_154 )
return - V_155 ;
if ( ( ( V_67 & V_69 ) && ! V_79 ) ||
( ! ( V_67 & V_69 ) && ( V_67 & V_156 ) ) ||
( ( V_67 & V_157 ) && ( V_67 & V_156 ) ) )
return - V_30 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 )
return - V_30 ;
if ( ! F_78 ( V_4 ) ||
F_130 ( F_131 ( V_4 ) ) )
return - V_30 ;
if ( ! V_86 ) {
if ( ! V_93 )
return - V_30 ;
V_86 = F_91 ;
}
V_15 = F_133 ( sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_15 )
return - V_111 ;
V_15 -> V_86 = V_86 ;
V_15 -> V_93 = V_93 ;
V_15 -> V_6 = V_67 ;
V_15 -> V_72 = V_153 ;
V_15 -> V_79 = V_79 ;
V_151 = F_166 ( & V_4 -> V_7 ) ;
if ( V_151 < 0 ) {
F_178 ( V_15 ) ;
return V_151 ;
}
V_151 = F_142 ( V_9 , V_4 , V_15 ) ;
if ( V_151 ) {
F_167 ( & V_4 -> V_7 ) ;
F_178 ( V_15 -> V_101 ) ;
F_178 ( V_15 ) ;
}
#ifdef F_182
if ( ! V_151 && ( V_67 & V_69 ) ) {
unsigned long V_6 ;
F_67 ( V_9 ) ;
F_175 ( V_6 ) ;
V_86 ( V_9 , V_79 ) ;
F_176 ( V_6 ) ;
F_73 ( V_9 ) ;
}
#endif
return V_151 ;
}
int F_183 ( unsigned int V_9 , T_4 V_86 ,
unsigned long V_6 , const char * V_72 , void * V_79 )
{
struct V_3 * V_4 ;
int V_24 ;
if ( V_9 == V_154 )
return - V_155 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 )
return - V_30 ;
if ( F_144 ( V_4 ) ) {
V_24 = F_181 ( V_9 , NULL , V_86 ,
V_6 , V_72 , V_79 ) ;
return ! V_24 ? V_158 : V_24 ;
}
V_24 = F_184 ( V_9 , V_86 , V_6 , V_72 , V_79 ) ;
return ! V_24 ? V_159 : V_24 ;
}
void F_185 ( unsigned int V_9 , unsigned int type )
{
unsigned int V_160 = F_186 () ;
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , V_161 ) ;
if ( ! V_4 )
return;
type &= V_74 ;
if ( type == V_162 )
type = F_84 ( & V_4 -> V_7 ) ;
if ( type != V_162 ) {
int V_24 ;
V_24 = F_79 ( V_4 , type ) ;
if ( V_24 ) {
F_70 ( 1 , L_18 , V_9 ) ;
goto V_41;
}
}
F_187 ( V_4 , V_160 ) ;
V_41:
F_35 ( V_4 , V_6 ) ;
}
bool F_188 ( unsigned int V_9 )
{
unsigned int V_160 = F_186 () ;
struct V_3 * V_4 ;
unsigned long V_6 ;
bool V_163 ;
V_4 = F_34 ( V_9 , & V_6 , V_161 ) ;
if ( ! V_4 )
return false ;
V_163 = F_189 ( V_160 , V_4 -> V_164 ) ;
F_35 ( V_4 , V_6 ) ;
return V_163 ;
}
void F_190 ( unsigned int V_9 )
{
unsigned int V_160 = F_186 () ;
unsigned long V_6 ;
struct V_3 * V_4 = F_34 ( V_9 , & V_6 , V_161 ) ;
if ( ! V_4 )
return;
F_191 ( V_4 , V_160 ) ;
F_35 ( V_4 , V_6 ) ;
}
static struct V_14 * F_192 ( unsigned int V_9 , void T_5 * V_79 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
unsigned long V_6 ;
F_70 ( F_169 () , L_16 , V_9 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_15 = V_4 -> V_15 ;
if ( ! V_15 || V_15 -> V_165 != V_79 ) {
F_70 ( 1 , L_17 , V_9 ) ;
goto V_166;
}
if ( ! F_193 ( V_4 -> V_164 ) ) {
F_70 ( 1 , L_19 ,
V_9 , F_194 ( V_4 -> V_164 ) ) ;
goto V_166;
}
V_4 -> V_15 = NULL ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_174 ( V_9 , V_15 ) ;
F_167 ( & V_4 -> V_7 ) ;
F_164 ( V_4 -> V_125 ) ;
return V_15 ;
V_166:
F_6 ( & V_4 -> V_8 , V_6 ) ;
return NULL ;
}
void F_195 ( unsigned int V_9 , struct V_14 * V_150 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 && F_131 ( V_4 ) )
F_192 ( V_9 , V_150 -> V_165 ) ;
}
void F_196 ( unsigned int V_9 , void T_5 * V_79 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || ! F_131 ( V_4 ) )
return;
F_101 ( V_4 ) ;
F_178 ( F_192 ( V_9 , V_79 ) ) ;
F_105 ( V_4 ) ;
}
int F_197 ( unsigned int V_9 , struct V_14 * V_150 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
int V_151 ;
if ( ! V_4 || ! F_131 ( V_4 ) )
return - V_30 ;
V_151 = F_166 ( & V_4 -> V_7 ) ;
if ( V_151 < 0 )
return V_151 ;
V_151 = F_142 ( V_9 , V_4 , V_150 ) ;
if ( V_151 )
F_167 ( & V_4 -> V_7 ) ;
return V_151 ;
}
int F_198 ( unsigned int V_9 , T_4 V_86 ,
unsigned long V_6 , const char * V_153 ,
void T_5 * V_79 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_151 ;
if ( ! V_79 )
return - V_30 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || ! F_78 ( V_4 ) ||
! F_131 ( V_4 ) )
return - V_30 ;
if ( V_6 && V_6 != V_167 )
return - V_30 ;
V_15 = F_133 ( sizeof( struct V_14 ) , V_40 ) ;
if ( ! V_15 )
return - V_111 ;
V_15 -> V_86 = V_86 ;
V_15 -> V_6 = V_6 | V_109 | V_157 ;
V_15 -> V_72 = V_153 ;
V_15 -> V_165 = V_79 ;
V_151 = F_166 ( & V_4 -> V_7 ) ;
if ( V_151 < 0 ) {
F_178 ( V_15 ) ;
return V_151 ;
}
V_151 = F_142 ( V_9 , V_4 , V_15 ) ;
if ( V_151 ) {
F_167 ( & V_4 -> V_7 ) ;
F_178 ( V_15 ) ;
}
return V_151 ;
}
int F_199 ( unsigned int V_9 , enum V_168 V_169 ,
bool * V_170 )
{
struct V_3 * V_4 ;
struct V_7 * V_19 ;
struct V_23 * V_12 ;
unsigned long V_6 ;
int V_171 = - V_30 ;
V_4 = F_64 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return V_171 ;
V_19 = F_32 ( V_4 ) ;
do {
V_12 = F_22 ( V_19 ) ;
if ( V_12 -> F_199 )
break;
#ifdef F_200
V_19 = V_19 -> V_172 ;
#else
V_19 = NULL ;
#endif
} while ( V_19 );
if ( V_19 )
V_171 = V_12 -> F_199 ( V_19 , V_169 , V_170 ) ;
F_65 ( V_4 , V_6 ) ;
return V_171 ;
}
int F_201 ( unsigned int V_9 , enum V_168 V_169 ,
bool V_173 )
{
struct V_3 * V_4 ;
struct V_7 * V_19 ;
struct V_23 * V_12 ;
unsigned long V_6 ;
int V_171 = - V_30 ;
V_4 = F_64 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return V_171 ;
V_19 = F_32 ( V_4 ) ;
do {
V_12 = F_22 ( V_19 ) ;
if ( V_12 -> F_201 )
break;
#ifdef F_200
V_19 = V_19 -> V_172 ;
#else
V_19 = NULL ;
#endif
} while ( V_19 );
if ( V_19 )
V_171 = V_12 -> F_201 ( V_19 , V_169 , V_173 ) ;
F_65 ( V_4 , V_6 ) ;
return V_171 ;
}
