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
static void F_20 ( struct V_7 * V_19 )
{
#ifdef F_21
const struct V_20 * V_21 = F_22 ( V_19 ) ;
struct V_22 * V_12 = F_23 ( V_19 ) ;
if ( ! F_24 ( V_21 ) )
return;
F_25 ( L_1 ,
V_12 -> V_23 , V_19 -> V_9 ) ;
#endif
}
int F_26 ( struct V_7 * V_19 , const struct V_20 * V_24 ,
bool V_25 )
{
struct V_3 * V_4 = F_27 ( V_19 ) ;
struct V_22 * V_12 = F_23 ( V_19 ) ;
int V_26 ;
if ( ! V_12 || ! V_12 -> V_13 )
return - V_27 ;
V_26 = V_12 -> V_13 ( V_19 , V_24 , V_25 ) ;
switch ( V_26 ) {
case V_28 :
case V_29 :
F_28 ( V_4 -> V_30 . V_31 , V_24 ) ;
case V_32 :
F_20 ( V_19 ) ;
F_17 ( V_4 ) ;
V_26 = 0 ;
}
return V_26 ;
}
int F_29 ( struct V_7 * V_19 , const struct V_20 * V_24 ,
bool V_25 )
{
struct V_22 * V_12 = F_23 ( V_19 ) ;
struct V_3 * V_4 = F_27 ( V_19 ) ;
int V_26 = 0 ;
if ( ! V_12 || ! V_12 -> V_13 )
return - V_27 ;
if ( F_30 ( V_19 ) ) {
V_26 = F_26 ( V_19 , V_24 , V_25 ) ;
} else {
F_31 ( V_19 ) ;
F_32 ( V_4 , V_24 ) ;
}
if ( V_4 -> V_33 ) {
F_33 ( & V_4 -> V_33 -> V_34 ) ;
F_34 ( & V_4 -> V_33 -> V_35 ) ;
}
F_35 ( V_19 , V_36 ) ;
return V_26 ;
}
int F_36 ( unsigned int V_9 , const struct V_20 * V_24 , bool V_25 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
unsigned long V_6 ;
int V_26 ;
if ( ! V_4 )
return - V_27 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_26 = F_29 ( F_37 ( V_4 ) , V_24 , V_25 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
return V_26 ;
}
int F_38 ( unsigned int V_9 , const struct V_20 * V_21 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , V_37 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_38 = V_21 ;
F_40 ( V_4 , V_6 ) ;
if ( V_21 )
F_36 ( V_9 , V_21 , false ) ;
return 0 ;
}
static void F_41 ( struct V_39 * V_35 )
{
struct F_41 * V_40 =
F_42 ( V_35 , struct F_41 , V_35 ) ;
struct V_3 * V_4 = F_8 ( V_40 -> V_9 ) ;
T_2 V_20 ;
unsigned long V_6 ;
if ( ! V_4 || ! F_43 ( & V_20 , V_41 ) )
goto V_42;
F_5 ( & V_4 -> V_8 , V_6 ) ;
if ( F_44 ( & V_4 -> V_7 ) )
F_45 ( V_20 , V_4 ) ;
else
F_28 ( V_20 , V_4 -> V_30 . V_31 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
V_40 -> V_40 ( V_40 , V_20 ) ;
F_46 ( V_20 ) ;
V_42:
F_47 ( & V_40 -> V_34 , V_40 -> V_43 ) ;
}
int
F_48 ( unsigned int V_9 , struct F_41 * V_40 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct F_41 * V_44 ;
unsigned long V_6 ;
F_49 () ;
if ( ! V_4 )
return - V_27 ;
if ( V_40 ) {
V_40 -> V_9 = V_9 ;
F_50 ( & V_40 -> V_34 ) ;
F_51 ( & V_40 -> V_35 , F_41 ) ;
}
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_44 = V_4 -> V_33 ;
V_4 -> V_33 = V_40 ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
if ( V_44 )
F_47 ( & V_44 -> V_34 , V_44 -> V_43 ) ;
return 0 ;
}
int F_52 ( struct V_3 * V_4 )
{
struct V_20 * V_45 = V_46 ;
int V_26 , V_47 = F_53 ( V_4 ) ;
static F_54 ( V_48 ) ;
static struct V_20 V_24 ;
if ( ! F_12 ( V_4 ) )
return 0 ;
F_55 ( & V_48 ) ;
if ( F_16 ( & V_4 -> V_7 ) ||
F_56 ( & V_4 -> V_7 , V_36 ) ) {
if ( F_57 ( V_4 -> V_30 . V_31 ,
V_49 ) )
V_45 = V_4 -> V_30 . V_31 ;
else
F_58 ( & V_4 -> V_7 , V_36 ) ;
}
F_59 ( & V_24 , V_49 , V_45 ) ;
if ( V_47 != V_50 ) {
const struct V_20 * V_51 = F_60 ( V_47 ) ;
if ( F_57 ( & V_24 , V_51 ) )
F_59 ( & V_24 , & V_24 , V_51 ) ;
}
V_26 = F_26 ( & V_4 -> V_7 , & V_24 , false ) ;
F_61 ( & V_48 ) ;
return V_26 ;
}
int F_52 ( struct V_3 * V_4 )
{
return F_62 ( F_63 ( V_4 ) ) ;
}
int F_64 ( unsigned int V_9 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
unsigned long V_6 ;
int V_26 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_26 = F_52 ( V_4 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
return V_26 ;
}
int F_65 ( unsigned int V_9 , void * V_52 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , 0 ) ;
struct V_7 * V_19 ;
struct V_22 * V_12 ;
int V_26 = - V_53 ;
if ( ! V_4 )
return - V_27 ;
V_19 = F_37 ( V_4 ) ;
do {
V_12 = F_23 ( V_19 ) ;
if ( V_12 && V_12 -> F_65 )
break;
#ifdef F_66
V_19 = V_19 -> V_54 ;
#else
V_19 = NULL ;
#endif
} while ( V_19 );
if ( V_19 )
V_26 = V_12 -> F_65 ( V_19 , V_52 ) ;
F_40 ( V_4 , V_6 ) ;
return V_26 ;
}
void F_67 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_55 ++ )
F_68 ( V_4 ) ;
}
static int F_69 ( unsigned int V_9 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_70 ( V_9 , & V_6 , V_37 ) ;
if ( ! V_4 )
return - V_27 ;
F_67 ( V_4 ) ;
F_71 ( V_4 , V_6 ) ;
return 0 ;
}
void F_72 ( unsigned int V_9 )
{
F_69 ( V_9 ) ;
}
void F_73 ( unsigned int V_9 )
{
if ( ! F_69 ( V_9 ) )
F_10 ( V_9 ) ;
}
bool F_74 ( unsigned int V_9 )
{
if ( ! F_69 ( V_9 ) )
return F_7 ( V_9 ) ;
return false ;
}
void F_75 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_55 ) {
case 0 :
V_56:
F_76 ( 1 , V_57 L_2 ,
F_63 ( V_4 ) ) ;
break;
case 1 : {
if ( V_4 -> V_58 & V_59 )
goto V_56;
F_77 ( V_4 ) ;
F_78 ( V_4 , V_60 , V_61 ) ;
break;
}
default:
V_4 -> V_55 -- ;
}
}
void F_79 ( unsigned int V_9 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_70 ( V_9 , & V_6 , V_37 ) ;
if ( ! V_4 )
return;
if ( F_76 ( ! V_4 -> V_7 . V_12 ,
V_62 L_3 , V_9 ) )
goto V_42;
F_75 ( V_4 ) ;
V_42:
F_71 ( V_4 , V_6 ) ;
}
static int F_80 ( unsigned int V_9 , unsigned int V_63 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
int V_26 = - V_64 ;
if ( F_81 ( V_4 ) -> V_6 & V_65 )
return 0 ;
if ( V_4 -> V_7 . V_12 -> V_66 )
V_26 = V_4 -> V_7 . V_12 -> V_66 ( & V_4 -> V_7 , V_63 ) ;
return V_26 ;
}
int F_82 ( unsigned int V_9 , unsigned int V_63 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_70 ( V_9 , & V_6 , V_37 ) ;
int V_26 = 0 ;
if ( ! V_4 )
return - V_27 ;
if ( V_63 ) {
if ( V_4 -> V_67 ++ == 0 ) {
V_26 = F_80 ( V_9 , V_63 ) ;
if ( V_26 )
V_4 -> V_67 = 0 ;
else
F_35 ( & V_4 -> V_7 , V_68 ) ;
}
} else {
if ( V_4 -> V_67 == 0 ) {
F_76 ( 1 , L_4 , V_9 ) ;
} else if ( -- V_4 -> V_67 == 0 ) {
V_26 = F_80 ( V_9 , V_63 ) ;
if ( V_26 )
V_4 -> V_67 = 1 ;
else
F_58 ( & V_4 -> V_7 , V_68 ) ;
}
}
F_71 ( V_4 , V_6 ) ;
return V_26 ;
}
int F_83 ( unsigned int V_9 , unsigned long V_69 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , 0 ) ;
int V_70 = 0 ;
if ( ! V_4 )
return 0 ;
if ( F_84 ( V_4 ) ) {
if ( ! V_4 -> V_15 ||
V_69 & V_4 -> V_15 -> V_6 & V_71 )
V_70 = 1 ;
}
F_40 ( V_4 , V_6 ) ;
return V_70 ;
}
int F_85 ( struct V_3 * V_4 , unsigned long V_6 )
{
struct V_22 * V_12 = V_4 -> V_7 . V_12 ;
int V_26 , V_72 = 0 ;
if ( ! V_12 || ! V_12 -> V_73 ) {
F_86 ( L_5 ,
F_63 ( V_4 ) ,
V_12 ? ( V_12 -> V_23 ? : L_6 ) : L_6 ) ;
return 0 ;
}
if ( V_12 -> V_6 & V_74 ) {
if ( ! F_87 ( & V_4 -> V_7 ) )
F_88 ( V_4 ) ;
if ( ! F_89 ( & V_4 -> V_7 ) )
V_72 = 1 ;
}
V_6 &= V_75 ;
V_26 = V_12 -> V_73 ( & V_4 -> V_7 , V_6 ) ;
switch ( V_26 ) {
case V_28 :
case V_29 :
F_58 ( & V_4 -> V_7 , V_76 ) ;
F_35 ( & V_4 -> V_7 , V_6 ) ;
case V_32 :
V_6 = F_90 ( & V_4 -> V_7 ) ;
F_91 ( V_4 , V_6 ) ;
F_58 ( & V_4 -> V_7 , V_77 ) ;
F_92 ( V_4 ) ;
if ( V_6 & V_78 ) {
F_93 ( V_4 ) ;
F_35 ( & V_4 -> V_7 , V_77 ) ;
}
V_26 = 0 ;
break;
default:
F_94 ( L_7 ,
V_6 , F_63 ( V_4 ) , V_12 -> V_73 ) ;
}
if ( V_72 )
F_95 ( V_4 ) ;
return V_26 ;
}
int F_96 ( int V_9 , int V_79 )
{
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_79 = V_79 ;
F_40 ( V_4 , V_6 ) ;
return 0 ;
}
static T_3 F_97 ( int V_9 , void * V_80 )
{
return V_81 ;
}
static T_3 F_98 ( int V_9 , void * V_80 )
{
F_76 ( 1 , L_8 , V_9 ) ;
return V_82 ;
}
static T_3 F_99 ( int V_9 , void * V_80 )
{
F_76 ( 1 , L_9 , V_9 ) ;
return V_82 ;
}
static int F_100 ( struct V_14 * V_15 )
{
F_101 ( V_83 ) ;
while ( ! F_102 () ) {
if ( F_103 ( V_84 ,
& V_15 -> V_18 ) ) {
F_104 ( V_85 ) ;
return 0 ;
}
F_105 () ;
F_101 ( V_83 ) ;
}
F_104 ( V_85 ) ;
return - 1 ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
if ( ! ( V_4 -> V_58 & V_86 ) ||
V_15 -> V_87 == F_99 )
return;
V_88:
F_107 ( V_4 ) ;
F_108 ( & V_4 -> V_8 ) ;
if ( F_109 ( F_3 ( & V_4 -> V_7 ) ) ) {
F_110 ( & V_4 -> V_8 ) ;
F_111 ( V_4 ) ;
F_4 () ;
goto V_88;
}
if ( F_112 ( V_84 , & V_15 -> V_18 ) )
goto V_89;
V_4 -> V_90 &= ~ V_15 -> V_91 ;
if ( ! V_4 -> V_90 && ! F_89 ( & V_4 -> V_7 ) &&
F_87 ( & V_4 -> V_7 ) )
F_113 ( V_4 ) ;
V_89:
F_110 ( & V_4 -> V_8 ) ;
F_111 ( V_4 ) ;
}
static void
F_114 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_24 ;
bool V_92 = true ;
if ( ! F_103 ( V_17 , & V_15 -> V_18 ) )
return;
if ( ! F_43 ( & V_24 , V_41 ) ) {
F_19 ( V_17 , & V_15 -> V_18 ) ;
return;
}
F_108 ( & V_4 -> V_8 ) ;
if ( F_115 ( V_4 -> V_30 . V_31 ) )
F_28 ( V_24 , V_4 -> V_30 . V_31 ) ;
else
V_92 = false ;
F_110 ( & V_4 -> V_8 ) ;
if ( V_92 )
F_116 ( V_93 , V_24 ) ;
F_46 ( V_24 ) ;
}
static inline void
F_114 ( struct V_3 * V_4 , struct V_14 * V_15 ) { }
static T_3
F_117 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_3 V_26 ;
F_118 () ;
V_26 = V_15 -> V_94 ( V_15 -> V_9 , V_15 -> V_80 ) ;
F_106 ( V_4 , V_15 ) ;
F_119 () ;
return V_26 ;
}
static T_3 F_120 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
T_3 V_26 ;
V_26 = V_15 -> V_94 ( V_15 -> V_9 , V_15 -> V_80 ) ;
F_106 ( V_4 , V_15 ) ;
return V_26 ;
}
static void F_121 ( struct V_3 * V_4 )
{
if ( F_122 ( & V_4 -> V_10 ) )
F_123 ( & V_4 -> V_11 ) ;
}
static void F_124 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_93 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
if ( F_125 ( ! ( V_93 -> V_6 & V_99 ) ) )
return;
V_15 = F_126 ( V_98 ) ;
F_94 ( L_10 ,
V_98 -> V_100 , V_98 -> V_101 , V_15 -> V_9 ) ;
V_4 = F_8 ( V_15 -> V_9 ) ;
if ( F_103 ( V_84 , & V_15 -> V_18 ) )
F_121 ( V_4 ) ;
F_106 ( V_4 , V_15 ) ;
}
static void F_127 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
struct V_14 * V_102 = V_15 -> V_102 ;
if ( F_125 ( ! V_102 ) )
return;
F_108 ( & V_4 -> V_8 ) ;
F_128 ( V_4 , V_102 ) ;
F_110 ( & V_4 -> V_8 ) ;
}
static int F_129 ( void * V_19 )
{
struct V_95 V_103 ;
struct V_14 * V_15 = V_19 ;
struct V_3 * V_4 = F_8 ( V_15 -> V_9 ) ;
T_3 (* F_130)( struct V_3 * V_4 ,
struct V_14 * V_15 );
if ( V_2 && F_112 ( V_104 ,
& V_15 -> V_18 ) )
F_130 = F_117 ;
else
F_130 = F_120 ;
F_131 ( & V_103 , F_124 ) ;
F_132 ( V_93 , & V_103 , false ) ;
F_114 ( V_4 , V_15 ) ;
while ( ! F_100 ( V_15 ) ) {
T_3 V_105 ;
F_114 ( V_4 , V_15 ) ;
V_105 = F_130 ( V_4 , V_15 ) ;
if ( V_105 == V_106 )
F_133 ( & V_4 -> V_107 ) ;
if ( V_105 == V_81 )
F_127 ( V_4 , V_15 ) ;
F_121 ( V_4 ) ;
}
F_134 ( V_93 , F_124 ) ;
return 0 ;
}
void F_135 ( unsigned int V_9 , void * V_80 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
unsigned long V_6 ;
if ( ! V_4 || F_136 ( F_137 ( V_4 ) ) )
return;
F_5 ( & V_4 -> V_8 , V_6 ) ;
F_18 (desc, action) {
if ( V_15 -> V_80 == V_80 ) {
if ( V_15 -> V_16 )
F_128 ( V_4 , V_15 ) ;
break;
}
}
F_6 ( & V_4 -> V_8 , V_6 ) ;
}
static int F_138 ( struct V_14 * V_108 )
{
if ( ! V_2 )
return 0 ;
if ( V_108 -> V_6 & ( V_109 | V_110 | V_111 ) )
return 0 ;
V_108 -> V_6 |= V_111 ;
if ( V_108 -> V_87 != F_97 && V_108 -> V_94 ) {
V_108 -> V_102 = F_139 ( sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_108 -> V_102 )
return - V_112 ;
V_108 -> V_102 -> V_87 = F_99 ;
V_108 -> V_102 -> V_94 = V_108 -> V_94 ;
V_108 -> V_102 -> V_80 = V_108 -> V_80 ;
V_108 -> V_102 -> V_9 = V_108 -> V_9 ;
V_108 -> V_102 -> V_23 = V_108 -> V_23 ;
}
F_19 ( V_104 , & V_108 -> V_18 ) ;
V_108 -> V_94 = V_108 -> V_87 ;
V_108 -> V_87 = F_97 ;
return 0 ;
}
static int F_140 ( struct V_3 * V_4 )
{
struct V_7 * V_113 = & V_4 -> V_7 ;
struct V_22 * V_114 = V_113 -> V_12 ;
return V_114 -> F_140 ? V_114 -> F_140 ( V_113 ) : 0 ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_7 * V_113 = & V_4 -> V_7 ;
struct V_22 * V_114 = V_113 -> V_12 ;
if ( V_114 -> F_141 )
V_114 -> F_141 ( V_113 ) ;
}
static int
F_142 ( struct V_14 * V_108 , unsigned int V_9 , bool V_102 )
{
struct V_97 * V_115 ;
struct V_116 V_117 = {
. V_118 = V_119 / 2 ,
} ;
if ( ! V_102 ) {
V_115 = F_143 ( F_129 , V_108 , L_11 , V_9 ,
V_108 -> V_23 ) ;
} else {
V_115 = F_143 ( F_129 , V_108 , L_12 , V_9 ,
V_108 -> V_23 ) ;
V_117 . V_118 -= 1 ;
}
if ( F_144 ( V_115 ) )
return F_145 ( V_115 ) ;
F_146 ( V_115 , V_120 , & V_117 ) ;
F_147 ( V_115 ) ;
V_108 -> V_16 = V_115 ;
F_19 ( V_17 , & V_108 -> V_18 ) ;
return 0 ;
}
static int
F_148 ( unsigned int V_9 , struct V_3 * V_4 , struct V_14 * V_108 )
{
struct V_14 * V_121 , * * V_122 ;
unsigned long V_6 , V_91 = 0 ;
int V_26 , V_123 , V_124 = 0 ;
if ( ! V_4 )
return - V_27 ;
if ( V_4 -> V_7 . V_12 == & V_125 )
return - V_53 ;
if ( ! F_149 ( V_4 -> V_126 ) )
return - V_127 ;
V_108 -> V_9 = V_9 ;
if ( ! ( V_108 -> V_6 & V_128 ) )
V_108 -> V_6 |= F_90 ( & V_4 -> V_7 ) ;
V_123 = F_150 ( V_4 ) ;
if ( V_123 ) {
if ( ! V_108 -> V_94 ) {
V_26 = - V_27 ;
goto V_129;
}
V_108 -> V_87 = F_98 ;
} else {
if ( F_151 ( V_4 ) ) {
V_26 = F_138 ( V_108 ) ;
if ( V_26 )
goto V_129;
}
}
if ( V_108 -> V_94 && ! V_123 ) {
V_26 = F_142 ( V_108 , V_9 , false ) ;
if ( V_26 )
goto V_129;
if ( V_108 -> V_102 ) {
V_26 = F_142 ( V_108 -> V_102 , V_9 , true ) ;
if ( V_26 )
goto V_130;
}
}
if ( V_4 -> V_7 . V_12 -> V_6 & V_131 )
V_108 -> V_6 &= ~ V_111 ;
F_152 ( & V_4 -> V_132 ) ;
F_107 ( V_4 ) ;
if ( ! V_4 -> V_15 ) {
V_26 = F_140 ( V_4 ) ;
if ( V_26 ) {
F_94 ( L_13 ,
V_108 -> V_23 , V_9 , V_4 -> V_7 . V_12 -> V_23 ) ;
goto V_133;
}
}
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_122 = & V_4 -> V_15 ;
V_121 = * V_122 ;
if ( V_121 ) {
unsigned int V_134 = F_90 ( & V_4 -> V_7 ) ;
if ( ! ( ( V_121 -> V_6 & V_108 -> V_6 ) & V_71 ) ||
( V_134 != ( V_108 -> V_6 & V_128 ) ) ||
( ( V_121 -> V_6 ^ V_108 -> V_6 ) & V_111 ) )
goto V_135;
if ( ( V_121 -> V_6 & V_110 ) !=
( V_108 -> V_6 & V_110 ) )
goto V_135;
do {
V_91 |= V_121 -> V_91 ;
V_122 = & V_121 -> V_136 ;
V_121 = * V_122 ;
} while ( V_121 );
V_124 = 1 ;
}
if ( V_108 -> V_6 & V_111 ) {
if ( V_91 == ~ 0UL ) {
V_26 = - V_137 ;
goto V_89;
}
V_108 -> V_91 = 1 << F_153 ( V_91 ) ;
} else if ( V_108 -> V_87 == F_97 &&
! ( V_4 -> V_7 . V_12 -> V_6 & V_131 ) ) {
F_94 ( L_14 ,
V_9 ) ;
V_26 = - V_27 ;
goto V_89;
}
if ( ! V_124 ) {
F_154 ( & V_4 -> V_11 ) ;
if ( V_108 -> V_6 & V_128 ) {
V_26 = F_85 ( V_4 ,
V_108 -> V_6 & V_128 ) ;
if ( V_26 )
goto V_89;
}
V_4 -> V_58 &= ~ ( V_138 | V_139 | \
V_86 | V_140 ) ;
F_58 ( & V_4 -> V_7 , V_141 ) ;
if ( V_108 -> V_6 & V_110 ) {
F_35 ( & V_4 -> V_7 , V_142 ) ;
F_155 ( V_4 ) ;
}
if ( V_108 -> V_6 & V_111 )
V_4 -> V_58 |= V_86 ;
if ( V_108 -> V_6 & V_143 ) {
F_156 ( V_4 ) ;
F_35 ( & V_4 -> V_7 , V_144 ) ;
}
if ( F_157 ( V_4 ) ) {
F_78 ( V_4 , V_60 , V_61 ) ;
} else {
F_125 ( V_108 -> V_6 & V_71 ) ;
V_4 -> V_55 = 1 ;
}
} else if ( V_108 -> V_6 & V_128 ) {
unsigned int V_145 = V_108 -> V_6 & V_128 ;
unsigned int V_146 = F_90 ( & V_4 -> V_7 ) ;
if ( V_145 != V_146 )
F_158 ( L_15 ,
V_9 , V_146 , V_145 ) ;
}
* V_122 = V_108 ;
F_159 ( V_4 , V_108 ) ;
V_4 -> V_147 = 0 ;
V_4 -> V_148 = 0 ;
if ( V_124 && ( V_4 -> V_58 & V_139 ) ) {
V_4 -> V_58 &= ~ V_139 ;
F_75 ( V_4 ) ;
}
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_111 ( V_4 ) ;
F_160 ( & V_4 -> V_132 ) ;
F_161 ( V_4 , V_108 ) ;
if ( V_108 -> V_16 )
F_162 ( V_108 -> V_16 ) ;
if ( V_108 -> V_102 )
F_162 ( V_108 -> V_102 -> V_16 ) ;
F_163 ( V_9 , V_4 ) ;
F_164 ( V_9 , V_4 ) ;
V_108 -> V_149 = NULL ;
F_165 ( V_9 , V_108 ) ;
return 0 ;
V_135:
if ( ! ( V_108 -> V_6 & V_150 ) ) {
F_94 ( L_16 ,
V_9 , V_108 -> V_6 , V_108 -> V_23 , V_121 -> V_6 , V_121 -> V_23 ) ;
#ifdef F_166
F_167 () ;
#endif
}
V_26 = - V_137 ;
V_89:
F_6 ( & V_4 -> V_8 , V_6 ) ;
if ( ! V_4 -> V_15 )
F_141 ( V_4 ) ;
V_133:
F_111 ( V_4 ) ;
F_160 ( & V_4 -> V_132 ) ;
V_130:
if ( V_108 -> V_16 ) {
struct V_97 * V_115 = V_108 -> V_16 ;
V_108 -> V_16 = NULL ;
F_168 ( V_115 ) ;
F_169 ( V_115 ) ;
}
if ( V_108 -> V_102 && V_108 -> V_102 -> V_16 ) {
struct V_97 * V_115 = V_108 -> V_102 -> V_16 ;
V_108 -> V_102 -> V_16 = NULL ;
F_168 ( V_115 ) ;
F_169 ( V_115 ) ;
}
V_129:
F_170 ( V_4 -> V_126 ) ;
return V_26 ;
}
int F_171 ( unsigned int V_9 , struct V_14 * V_151 )
{
int V_152 ;
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || F_136 ( F_137 ( V_4 ) ) )
return - V_27 ;
V_152 = F_172 ( & V_4 -> V_7 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_148 ( V_9 , V_4 , V_151 ) ;
if ( V_152 )
F_173 ( & V_4 -> V_7 ) ;
return V_152 ;
}
static struct V_14 * F_174 ( unsigned int V_9 , void * V_80 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 , * * V_153 ;
unsigned long V_6 ;
F_76 ( F_175 () , L_17 , V_9 ) ;
if ( ! V_4 )
return NULL ;
F_152 ( & V_4 -> V_132 ) ;
F_107 ( V_4 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_153 = & V_4 -> V_15 ;
for (; ; ) {
V_15 = * V_153 ;
if ( ! V_15 ) {
F_76 ( 1 , L_18 , V_9 ) ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_111 ( V_4 ) ;
F_160 ( & V_4 -> V_132 ) ;
return NULL ;
}
if ( V_15 -> V_80 == V_80 )
break;
V_153 = & V_15 -> V_136 ;
}
* V_153 = V_15 -> V_136 ;
F_176 ( V_4 , V_15 ) ;
if ( ! V_4 -> V_15 ) {
F_177 ( V_4 ) ;
F_178 ( V_4 ) ;
}
#ifdef F_179
if ( F_125 ( V_4 -> V_38 ) )
V_4 -> V_38 = NULL ;
#endif
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_111 ( V_4 ) ;
F_180 ( V_9 , V_15 ) ;
F_10 ( V_9 ) ;
#ifdef F_166
if ( V_15 -> V_6 & V_71 ) {
F_181 ( V_6 ) ;
V_15 -> V_87 ( V_9 , V_80 ) ;
F_182 ( V_6 ) ;
}
#endif
if ( V_15 -> V_16 ) {
F_168 ( V_15 -> V_16 ) ;
F_169 ( V_15 -> V_16 ) ;
if ( V_15 -> V_102 && V_15 -> V_102 -> V_16 ) {
F_168 ( V_15 -> V_102 -> V_16 ) ;
F_169 ( V_15 -> V_102 -> V_16 ) ;
}
}
if ( ! V_4 -> V_15 ) {
F_107 ( V_4 ) ;
F_141 ( V_4 ) ;
F_111 ( V_4 ) ;
F_183 ( V_4 ) ;
}
F_160 ( & V_4 -> V_132 ) ;
F_173 ( & V_4 -> V_7 ) ;
F_170 ( V_4 -> V_126 ) ;
F_184 ( V_15 -> V_102 ) ;
return V_15 ;
}
void F_185 ( unsigned int V_9 , struct V_14 * V_151 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 && ! F_136 ( F_137 ( V_4 ) ) )
F_174 ( V_9 , V_151 -> V_80 ) ;
}
const void * F_186 ( unsigned int V_9 , void * V_80 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
const char * V_154 ;
if ( ! V_4 || F_136 ( F_137 ( V_4 ) ) )
return NULL ;
#ifdef F_179
if ( F_136 ( V_4 -> V_33 ) )
V_4 -> V_33 = NULL ;
#endif
V_15 = F_174 ( V_9 , V_80 ) ;
if ( ! V_15 )
return NULL ;
V_154 = V_15 -> V_23 ;
F_184 ( V_15 ) ;
return V_154 ;
}
int F_187 ( unsigned int V_9 , T_4 V_87 ,
T_4 V_94 , unsigned long V_69 ,
const char * V_154 , void * V_80 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_152 ;
if ( V_9 == V_155 )
return - V_156 ;
if ( ( ( V_69 & V_71 ) && ! V_80 ) ||
( ! ( V_69 & V_71 ) && ( V_69 & V_157 ) ) ||
( ( V_69 & V_158 ) && ( V_69 & V_157 ) ) )
return - V_27 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 )
return - V_27 ;
if ( ! F_84 ( V_4 ) ||
F_136 ( F_137 ( V_4 ) ) )
return - V_27 ;
if ( ! V_87 ) {
if ( ! V_94 )
return - V_27 ;
V_87 = F_97 ;
}
V_15 = F_139 ( sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_15 )
return - V_112 ;
V_15 -> V_87 = V_87 ;
V_15 -> V_94 = V_94 ;
V_15 -> V_6 = V_69 ;
V_15 -> V_23 = V_154 ;
V_15 -> V_80 = V_80 ;
V_152 = F_172 ( & V_4 -> V_7 ) ;
if ( V_152 < 0 ) {
F_184 ( V_15 ) ;
return V_152 ;
}
V_152 = F_148 ( V_9 , V_4 , V_15 ) ;
if ( V_152 ) {
F_173 ( & V_4 -> V_7 ) ;
F_184 ( V_15 -> V_102 ) ;
F_184 ( V_15 ) ;
}
#ifdef F_188
if ( ! V_152 && ( V_69 & V_71 ) ) {
unsigned long V_6 ;
F_73 ( V_9 ) ;
F_181 ( V_6 ) ;
V_87 ( V_9 , V_80 ) ;
F_182 ( V_6 ) ;
F_79 ( V_9 ) ;
}
#endif
return V_152 ;
}
int F_189 ( unsigned int V_9 , T_4 V_87 ,
unsigned long V_6 , const char * V_23 , void * V_80 )
{
struct V_3 * V_4 ;
int V_26 ;
if ( V_9 == V_155 )
return - V_156 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 )
return - V_27 ;
if ( F_150 ( V_4 ) ) {
V_26 = F_187 ( V_9 , NULL , V_87 ,
V_6 , V_23 , V_80 ) ;
return ! V_26 ? V_159 : V_26 ;
}
V_26 = F_190 ( V_9 , V_87 , V_6 , V_23 , V_80 ) ;
return ! V_26 ? V_160 : V_26 ;
}
void F_191 ( unsigned int V_9 , unsigned int type )
{
unsigned int V_161 = F_192 () ;
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , V_162 ) ;
if ( ! V_4 )
return;
type &= V_75 ;
if ( type == V_163 )
type = F_90 ( & V_4 -> V_7 ) ;
if ( type != V_163 ) {
int V_26 ;
V_26 = F_85 ( V_4 , type ) ;
if ( V_26 ) {
F_76 ( 1 , L_19 , V_9 ) ;
goto V_42;
}
}
F_193 ( V_4 , V_161 ) ;
V_42:
F_40 ( V_4 , V_6 ) ;
}
bool F_194 ( unsigned int V_9 )
{
unsigned int V_161 = F_192 () ;
struct V_3 * V_4 ;
unsigned long V_6 ;
bool V_164 ;
V_4 = F_39 ( V_9 , & V_6 , V_162 ) ;
if ( ! V_4 )
return false ;
V_164 = F_195 ( V_161 , V_4 -> V_165 ) ;
F_40 ( V_4 , V_6 ) ;
return V_164 ;
}
void F_196 ( unsigned int V_9 )
{
unsigned int V_161 = F_192 () ;
unsigned long V_6 ;
struct V_3 * V_4 = F_39 ( V_9 , & V_6 , V_162 ) ;
if ( ! V_4 )
return;
F_197 ( V_4 , V_161 ) ;
F_40 ( V_4 , V_6 ) ;
}
static struct V_14 * F_198 ( unsigned int V_9 , void T_5 * V_80 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
struct V_14 * V_15 ;
unsigned long V_6 ;
F_76 ( F_175 () , L_17 , V_9 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_15 = V_4 -> V_15 ;
if ( ! V_15 || V_15 -> V_166 != V_80 ) {
F_76 ( 1 , L_18 , V_9 ) ;
goto V_167;
}
if ( ! F_24 ( V_4 -> V_165 ) ) {
F_76 ( 1 , L_20 ,
V_9 , F_199 ( V_4 -> V_165 ) ) ;
goto V_167;
}
V_4 -> V_15 = NULL ;
F_6 ( & V_4 -> V_8 , V_6 ) ;
F_180 ( V_9 , V_15 ) ;
F_173 ( & V_4 -> V_7 ) ;
F_170 ( V_4 -> V_126 ) ;
return V_15 ;
V_167:
F_6 ( & V_4 -> V_8 , V_6 ) ;
return NULL ;
}
void F_200 ( unsigned int V_9 , struct V_14 * V_151 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( V_4 && F_137 ( V_4 ) )
F_198 ( V_9 , V_151 -> V_166 ) ;
}
void F_201 ( unsigned int V_9 , void T_5 * V_80 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || ! F_137 ( V_4 ) )
return;
F_107 ( V_4 ) ;
F_184 ( F_198 ( V_9 , V_80 ) ) ;
F_111 ( V_4 ) ;
}
int F_202 ( unsigned int V_9 , struct V_14 * V_151 )
{
struct V_3 * V_4 = F_8 ( V_9 ) ;
int V_152 ;
if ( ! V_4 || ! F_137 ( V_4 ) )
return - V_27 ;
V_152 = F_172 ( & V_4 -> V_7 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_148 ( V_9 , V_4 , V_151 ) ;
if ( V_152 )
F_173 ( & V_4 -> V_7 ) ;
return V_152 ;
}
int F_203 ( unsigned int V_9 , T_4 V_87 ,
unsigned long V_6 , const char * V_154 ,
void T_5 * V_80 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_152 ;
if ( ! V_80 )
return - V_27 ;
V_4 = F_8 ( V_9 ) ;
if ( ! V_4 || ! F_84 ( V_4 ) ||
! F_137 ( V_4 ) )
return - V_27 ;
if ( V_6 && V_6 != V_168 )
return - V_27 ;
V_15 = F_139 ( sizeof( struct V_14 ) , V_41 ) ;
if ( ! V_15 )
return - V_112 ;
V_15 -> V_87 = V_87 ;
V_15 -> V_6 = V_6 | V_110 | V_158 ;
V_15 -> V_23 = V_154 ;
V_15 -> V_166 = V_80 ;
V_152 = F_172 ( & V_4 -> V_7 ) ;
if ( V_152 < 0 ) {
F_184 ( V_15 ) ;
return V_152 ;
}
V_152 = F_148 ( V_9 , V_4 , V_15 ) ;
if ( V_152 ) {
F_173 ( & V_4 -> V_7 ) ;
F_184 ( V_15 ) ;
}
return V_152 ;
}
int F_204 ( unsigned int V_9 , enum V_169 V_170 ,
bool * V_171 )
{
struct V_3 * V_4 ;
struct V_7 * V_19 ;
struct V_22 * V_12 ;
unsigned long V_6 ;
int V_172 = - V_27 ;
V_4 = F_70 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return V_172 ;
V_19 = F_37 ( V_4 ) ;
do {
V_12 = F_23 ( V_19 ) ;
if ( V_12 -> F_204 )
break;
#ifdef F_66
V_19 = V_19 -> V_54 ;
#else
V_19 = NULL ;
#endif
} while ( V_19 );
if ( V_19 )
V_172 = V_12 -> F_204 ( V_19 , V_170 , V_171 ) ;
F_71 ( V_4 , V_6 ) ;
return V_172 ;
}
int F_205 ( unsigned int V_9 , enum V_169 V_170 ,
bool V_173 )
{
struct V_3 * V_4 ;
struct V_7 * V_19 ;
struct V_22 * V_12 ;
unsigned long V_6 ;
int V_172 = - V_27 ;
V_4 = F_70 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
return V_172 ;
V_19 = F_37 ( V_4 ) ;
do {
V_12 = F_23 ( V_19 ) ;
if ( V_12 -> F_205 )
break;
#ifdef F_66
V_19 = V_19 -> V_54 ;
#else
V_19 = NULL ;
#endif
} while ( V_19 );
if ( V_19 )
V_172 = V_12 -> F_205 ( V_19 , V_170 , V_173 ) ;
F_71 ( V_4 , V_6 ) ;
return V_172 ;
}
