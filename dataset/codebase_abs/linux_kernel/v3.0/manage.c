static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 0 ;
}
void F_2 ( unsigned int V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
bool V_6 ;
if ( ! V_5 )
return;
do {
unsigned long V_7 ;
while ( F_4 ( & V_5 -> V_8 ) )
F_5 () ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_6 = F_4 ( & V_5 -> V_8 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
} while ( V_6 );
F_8 ( V_5 -> V_10 , ! F_9 ( & V_5 -> V_11 ) ) ;
}
int F_10 ( unsigned int V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( ! V_5 || ! F_11 ( & V_5 -> V_8 ) ||
! V_5 -> V_8 . V_12 || ! V_5 -> V_8 . V_12 -> V_13 )
return 0 ;
return 1 ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
while ( V_15 ) {
if ( V_15 -> V_16 )
F_13 ( V_17 , & V_15 -> V_18 ) ;
V_15 = V_15 -> V_19 ;
}
}
static inline bool F_14 ( struct V_8 * V_20 )
{
return F_15 ( V_20 ) ;
}
static inline bool F_16 ( struct V_8 * V_20 )
{
return F_17 ( V_20 ) ;
}
static inline void
F_18 ( struct V_4 * V_5 , const struct V_21 * V_22 )
{
F_19 ( V_5 -> V_23 , V_22 ) ;
}
static inline void
F_20 ( struct V_21 * V_22 , struct V_4 * V_5 )
{
F_19 ( V_22 , V_5 -> V_23 ) ;
}
static inline bool F_14 ( struct V_8 * V_20 ) { return true ; }
static inline bool F_16 ( struct V_8 * V_20 ) { return false ; }
static inline void
F_18 ( struct V_4 * V_5 , const struct V_21 * V_22 ) { }
static inline void
F_20 ( struct V_21 * V_22 , struct V_4 * V_5 ) { }
int F_21 ( struct V_8 * V_20 , const struct V_21 * V_22 )
{
struct V_24 * V_12 = F_22 ( V_20 ) ;
struct V_4 * V_5 = F_23 ( V_20 ) ;
int V_25 = 0 ;
if ( ! V_12 || ! V_12 -> V_13 )
return - V_26 ;
if ( F_14 ( V_20 ) ) {
V_25 = V_12 -> V_13 ( V_20 , V_22 , false ) ;
switch ( V_25 ) {
case V_27 :
F_19 ( V_20 -> V_28 , V_22 ) ;
case V_29 :
F_12 ( V_5 ) ;
V_25 = 0 ;
}
} else {
F_24 ( V_20 ) ;
F_18 ( V_5 , V_22 ) ;
}
if ( V_5 -> V_30 ) {
F_25 ( & V_5 -> V_30 -> V_31 ) ;
F_26 ( & V_5 -> V_30 -> V_32 ) ;
}
F_27 ( V_20 , V_33 ) ;
return V_25 ;
}
int V_13 ( unsigned int V_3 , const struct V_21 * V_22 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_7 ;
int V_25 ;
if ( ! V_5 )
return - V_26 ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_25 = F_21 ( F_28 ( V_5 ) , V_22 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
return V_25 ;
}
int F_29 ( unsigned int V_3 , const struct V_21 * V_34 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_30 ( V_3 , & V_7 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_35 = V_34 ;
F_31 ( V_5 , V_7 ) ;
return 0 ;
}
static void F_32 ( struct V_36 * V_32 )
{
struct F_32 * V_37 =
F_33 ( V_32 , struct F_32 , V_32 ) ;
struct V_4 * V_5 = F_3 ( V_37 -> V_3 ) ;
T_2 V_21 ;
unsigned long V_7 ;
if ( ! V_5 || ! F_34 ( & V_21 , V_38 ) )
goto V_39;
F_6 ( & V_5 -> V_9 , V_7 ) ;
if ( F_16 ( & V_5 -> V_8 ) )
F_20 ( V_21 , V_5 ) ;
else
F_19 ( V_21 , V_5 -> V_8 . V_28 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
V_37 -> V_37 ( V_37 , V_21 ) ;
F_35 ( V_21 ) ;
V_39:
F_36 ( & V_37 -> V_31 , V_37 -> V_40 ) ;
}
int
F_37 ( unsigned int V_3 , struct F_32 * V_37 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct F_32 * V_41 ;
unsigned long V_7 ;
F_38 () ;
if ( ! V_5 )
return - V_26 ;
if ( V_37 ) {
V_37 -> V_3 = V_3 ;
F_39 ( & V_37 -> V_31 ) ;
F_40 ( & V_37 -> V_32 , F_32 ) ;
}
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_41 = V_5 -> V_30 ;
V_5 -> V_30 = V_37 ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
if ( V_41 )
F_36 ( & V_41 -> V_31 , V_41 -> V_40 ) ;
return 0 ;
}
static int
F_41 ( unsigned int V_3 , struct V_4 * V_5 , struct V_21 * V_22 )
{
struct V_24 * V_12 = F_42 ( V_5 ) ;
struct V_21 * V_42 = V_43 ;
int V_25 ;
if ( ! F_10 ( V_3 ) )
return 0 ;
if ( F_43 ( & V_5 -> V_8 , V_33 ) ) {
if ( F_44 ( V_5 -> V_8 . V_28 ,
V_44 ) )
V_42 = V_5 -> V_8 . V_28 ;
else
F_45 ( & V_5 -> V_8 , V_33 ) ;
}
F_46 ( V_22 , V_44 , V_42 ) ;
V_25 = V_12 -> V_13 ( & V_5 -> V_8 , V_22 , false ) ;
switch ( V_25 ) {
case V_27 :
F_19 ( V_5 -> V_8 . V_28 , V_22 ) ;
case V_29 :
F_12 ( V_5 ) ;
}
return 0 ;
}
static inline int
F_41 ( unsigned int V_3 , struct V_4 * V_45 , struct V_21 * V_22 )
{
return F_47 ( V_3 ) ;
}
int F_48 ( unsigned int V_3 , struct V_21 * V_22 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned long V_7 ;
int V_25 ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_25 = F_41 ( V_3 , V_5 , V_22 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
return V_25 ;
}
static inline int
F_41 ( unsigned int V_3 , struct V_4 * V_5 , struct V_21 * V_22 )
{
return 0 ;
}
void F_49 ( struct V_4 * V_5 , unsigned int V_3 , bool V_46 )
{
if ( V_46 ) {
if ( ! V_5 -> V_15 || ( V_5 -> V_15 -> V_7 & V_47 ) )
return;
V_5 -> V_48 |= V_49 ;
}
if ( ! V_5 -> V_50 ++ )
F_50 ( V_5 ) ;
}
static int F_51 ( unsigned int V_3 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 ) ;
if ( ! V_5 )
return - V_26 ;
F_49 ( V_5 , V_3 , false ) ;
F_53 ( V_5 , V_7 ) ;
return 0 ;
}
void F_54 ( unsigned int V_3 )
{
F_51 ( V_3 ) ;
}
void F_55 ( unsigned int V_3 )
{
if ( ! F_51 ( V_3 ) )
F_2 ( V_3 ) ;
}
void F_56 ( struct V_4 * V_5 , unsigned int V_3 , bool V_51 )
{
if ( V_51 ) {
if ( ! ( V_5 -> V_48 & V_49 ) ) {
if ( ! V_5 -> V_15 )
return;
if ( ! ( V_5 -> V_15 -> V_7 & V_52 ) )
return;
V_5 -> V_50 ++ ;
}
V_5 -> V_48 &= ~ V_49 ;
}
switch ( V_5 -> V_50 ) {
case 0 :
V_53:
F_57 ( 1 , V_54 L_1 , V_3 ) ;
break;
case 1 : {
if ( V_5 -> V_48 & V_49 )
goto V_53;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
F_60 ( V_5 , V_3 ) ;
}
default:
V_5 -> V_50 -- ;
}
}
void F_61 ( unsigned int V_3 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 ) ;
if ( ! V_5 )
return;
if ( F_57 ( ! V_5 -> V_8 . V_12 ,
V_55 L_2 , V_3 ) )
goto V_39;
F_56 ( V_5 , V_3 , false ) ;
V_39:
F_53 ( V_5 , V_7 ) ;
}
static int F_62 ( unsigned int V_3 , unsigned int V_56 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_25 = - V_57 ;
if ( V_5 -> V_8 . V_12 -> V_58 )
V_25 = V_5 -> V_8 . V_12 -> V_58 ( & V_5 -> V_8 , V_56 ) ;
return V_25 ;
}
int F_63 ( unsigned int V_3 , unsigned int V_56 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 ) ;
int V_25 = 0 ;
if ( ! V_5 )
return - V_26 ;
if ( V_56 ) {
if ( V_5 -> V_59 ++ == 0 ) {
V_25 = F_62 ( V_3 , V_56 ) ;
if ( V_25 )
V_5 -> V_59 = 0 ;
else
F_27 ( & V_5 -> V_8 , V_60 ) ;
}
} else {
if ( V_5 -> V_59 == 0 ) {
F_57 ( 1 , L_3 , V_3 ) ;
} else if ( -- V_5 -> V_59 == 0 ) {
V_25 = F_62 ( V_3 , V_56 ) ;
if ( V_25 )
V_5 -> V_59 = 1 ;
else
F_45 ( & V_5 -> V_8 , V_60 ) ;
}
}
F_53 ( V_5 , V_7 ) ;
return V_25 ;
}
int F_64 ( unsigned int V_3 , unsigned long V_61 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_30 ( V_3 , & V_7 ) ;
int V_62 = 0 ;
if ( ! V_5 )
return 0 ;
if ( F_65 ( V_5 ) ) {
if ( V_5 -> V_15 )
if ( V_61 & V_5 -> V_15 -> V_7 & V_63 )
V_62 = 1 ;
}
F_31 ( V_5 , V_7 ) ;
return V_62 ;
}
int F_66 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned long V_7 )
{
struct V_24 * V_12 = V_5 -> V_8 . V_12 ;
int V_25 , V_64 = 0 ;
if ( ! V_12 || ! V_12 -> V_65 ) {
F_67 ( L_4 , V_3 ,
V_12 ? ( V_12 -> V_66 ? : L_5 ) : L_5 ) ;
return 0 ;
}
V_7 &= V_67 ;
if ( V_12 -> V_7 & V_68 ) {
if ( ! F_68 ( & V_5 -> V_8 ) )
F_69 ( V_5 ) ;
if ( ! F_70 ( & V_5 -> V_8 ) )
V_64 = 1 ;
}
V_25 = V_12 -> V_65 ( & V_5 -> V_8 , V_7 ) ;
switch ( V_25 ) {
case V_27 :
F_45 ( & V_5 -> V_8 , V_69 ) ;
F_27 ( & V_5 -> V_8 , V_7 ) ;
case V_29 :
V_7 = F_71 ( & V_5 -> V_8 ) ;
F_72 ( V_5 , V_7 ) ;
F_45 ( & V_5 -> V_8 , V_70 ) ;
F_73 ( V_5 ) ;
if ( V_7 & V_71 ) {
F_74 ( V_5 ) ;
F_27 ( & V_5 -> V_8 , V_70 ) ;
}
V_25 = 0 ;
break;
default:
F_75 ( L_6 ,
V_7 , V_3 , V_12 -> V_65 ) ;
}
if ( V_64 )
F_76 ( V_5 ) ;
return V_25 ;
}
static T_3 F_77 ( int V_3 , void * V_72 )
{
return V_73 ;
}
static T_3 F_78 ( int V_3 , void * V_72 )
{
F_57 ( 1 , L_7 , V_3 ) ;
return V_74 ;
}
static int F_79 ( struct V_14 * V_15 )
{
while ( ! F_80 () ) {
F_81 ( V_75 ) ;
if ( F_82 ( V_76 ,
& V_15 -> V_18 ) ) {
F_83 ( V_77 ) ;
return 0 ;
}
F_84 () ;
}
return - 1 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_14 * V_15 , bool V_78 )
{
if ( ! ( V_5 -> V_48 & V_79 ) )
return;
V_80:
F_86 ( V_5 ) ;
F_87 ( & V_5 -> V_9 ) ;
if ( F_88 ( F_4 ( & V_5 -> V_8 ) ) ) {
F_89 ( & V_5 -> V_9 ) ;
F_90 ( V_5 ) ;
F_5 () ;
goto V_80;
}
if ( ! V_78 && F_91 ( V_76 , & V_15 -> V_18 ) )
goto V_81;
V_5 -> V_82 &= ~ V_15 -> V_83 ;
if ( ! V_5 -> V_82 && ! F_70 ( & V_5 -> V_8 ) &&
F_68 ( & V_5 -> V_8 ) )
F_76 ( V_5 ) ;
V_81:
F_89 ( & V_5 -> V_9 ) ;
F_90 ( V_5 ) ;
}
static void
F_92 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
T_2 V_22 ;
if ( ! F_82 ( V_17 , & V_15 -> V_18 ) )
return;
if ( ! F_34 ( & V_22 , V_38 ) ) {
F_13 ( V_17 , & V_15 -> V_18 ) ;
return;
}
F_87 ( & V_5 -> V_9 ) ;
F_19 ( V_22 , V_5 -> V_8 . V_28 ) ;
F_89 ( & V_5 -> V_9 ) ;
F_93 ( V_84 , V_22 ) ;
F_35 ( V_22 ) ;
}
static inline void
F_92 ( struct V_4 * V_5 , struct V_14 * V_15 ) { }
static T_3
F_94 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
T_3 V_25 ;
F_95 () ;
V_25 = V_15 -> V_85 ( V_15 -> V_3 , V_15 -> V_72 ) ;
F_85 ( V_5 , V_15 , false ) ;
F_96 () ;
return V_25 ;
}
static T_3 F_97 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
T_3 V_25 ;
V_25 = V_15 -> V_85 ( V_15 -> V_3 , V_15 -> V_72 ) ;
F_85 ( V_5 , V_15 , false ) ;
return V_25 ;
}
static int F_98 ( void * V_20 )
{
static const struct V_86 V_87 = {
. V_88 = V_89 / 2 ,
} ;
struct V_14 * V_15 = V_20 ;
struct V_4 * V_5 = F_3 ( V_15 -> V_3 ) ;
T_3 (* F_99)( struct V_4 * V_5 ,
struct V_14 * V_15 );
int V_90 ;
if ( V_2 & F_91 ( V_91 ,
& V_15 -> V_18 ) )
F_99 = F_94 ;
else
F_99 = F_97 ;
F_100 ( V_84 , V_92 , & V_87 ) ;
V_84 -> V_14 = V_15 ;
while ( ! F_79 ( V_15 ) ) {
F_92 ( V_5 , V_15 ) ;
F_101 ( & V_5 -> V_11 ) ;
F_87 ( & V_5 -> V_9 ) ;
if ( F_88 ( F_70 ( & V_5 -> V_8 ) ) ) {
V_5 -> V_48 |= V_93 ;
F_89 ( & V_5 -> V_9 ) ;
} else {
T_3 V_94 ;
F_89 ( & V_5 -> V_9 ) ;
V_94 = F_99 ( V_5 , V_15 ) ;
if ( ! V_95 )
F_102 ( V_15 -> V_3 , V_5 , V_94 ) ;
}
V_90 = F_103 ( & V_5 -> V_11 ) ;
if ( V_90 && F_104 ( & V_5 -> V_10 ) )
F_105 ( & V_5 -> V_10 ) ;
}
F_85 ( V_5 , V_15 , true ) ;
V_84 -> V_14 = NULL ;
return 0 ;
}
void F_106 ( void )
{
struct V_96 * V_97 = V_84 ;
struct V_4 * V_5 ;
if ( ! V_97 -> V_14 )
return;
F_107 ( V_55
L_8 ,
V_97 -> V_98 ? V_97 -> V_98 : L_9 , V_97 -> V_99 , V_97 -> V_14 -> V_3 ) ;
V_5 = F_3 ( V_97 -> V_14 -> V_3 ) ;
F_85 ( V_5 , V_97 -> V_14 , true ) ;
F_13 ( V_100 , & V_97 -> V_14 -> V_7 ) ;
}
static void F_108 ( struct V_14 * V_101 )
{
if ( ! V_2 )
return;
if ( V_101 -> V_7 & ( V_102 | V_103 | V_104 ) )
return;
V_101 -> V_7 |= V_104 ;
if ( ! V_101 -> V_85 ) {
F_13 ( V_91 , & V_101 -> V_18 ) ;
V_101 -> V_85 = V_101 -> V_105 ;
V_101 -> V_105 = F_77 ;
}
}
static int
F_109 ( unsigned int V_3 , struct V_4 * V_5 , struct V_14 * V_101 )
{
struct V_14 * V_106 , * * V_107 ;
const char * V_108 = NULL ;
unsigned long V_7 , V_83 = 0 ;
int V_25 , V_109 , V_110 = 0 ;
T_2 V_22 ;
if ( ! V_5 )
return - V_26 ;
if ( V_5 -> V_8 . V_12 == & V_111 )
return - V_112 ;
if ( V_101 -> V_7 & V_113 ) {
F_110 ( V_3 ) ;
}
V_109 = F_111 ( V_5 ) ;
if ( V_109 ) {
if ( ! V_101 -> V_85 )
return - V_26 ;
V_101 -> V_105 = F_78 ;
} else {
if ( F_112 ( V_5 ) )
F_108 ( V_101 ) ;
}
if ( V_101 -> V_85 && ! V_109 ) {
struct V_96 * V_114 ;
V_114 = F_113 ( F_98 , V_101 , L_10 , V_3 ,
V_101 -> V_66 ) ;
if ( F_114 ( V_114 ) )
return F_115 ( V_114 ) ;
F_116 ( V_114 ) ;
V_101 -> V_16 = V_114 ;
}
if ( ! F_34 ( & V_22 , V_38 ) ) {
V_25 = - V_115 ;
goto V_116;
}
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_107 = & V_5 -> V_15 ;
V_106 = * V_107 ;
if ( V_106 ) {
if ( ! ( ( V_106 -> V_7 & V_101 -> V_7 ) & V_63 ) ||
( ( V_106 -> V_7 ^ V_101 -> V_7 ) & V_117 ) ||
( ( V_106 -> V_7 ^ V_101 -> V_7 ) & V_104 ) ) {
V_108 = V_106 -> V_66 ;
goto V_118;
}
if ( ( V_106 -> V_7 & V_103 ) !=
( V_101 -> V_7 & V_103 ) )
goto V_118;
do {
V_83 |= V_106 -> V_83 ;
V_107 = & V_106 -> V_19 ;
V_106 = * V_107 ;
} while ( V_106 );
V_110 = 1 ;
}
if ( V_101 -> V_7 & V_104 && V_83 == ~ 0UL ) {
V_25 = - V_119 ;
goto V_120;
}
V_101 -> V_83 = 1 << F_117 ( V_83 ) ;
if ( ! V_110 ) {
F_118 ( & V_5 -> V_10 ) ;
if ( V_101 -> V_7 & V_117 ) {
V_25 = F_66 ( V_5 , V_3 ,
V_101 -> V_7 & V_117 ) ;
if ( V_25 )
goto V_120;
}
V_5 -> V_48 &= ~ ( V_121 | V_122 | \
V_79 | V_123 ) ;
F_45 ( & V_5 -> V_8 , V_124 ) ;
if ( V_101 -> V_7 & V_103 ) {
F_27 ( & V_5 -> V_8 , V_125 ) ;
F_119 ( V_5 ) ;
}
if ( V_101 -> V_7 & V_104 )
V_5 -> V_48 |= V_79 ;
if ( F_120 ( V_5 ) )
F_121 ( V_5 ) ;
else
V_5 -> V_50 = 1 ;
if ( V_101 -> V_7 & V_126 ) {
F_122 ( V_5 ) ;
F_27 ( & V_5 -> V_8 , V_127 ) ;
}
F_41 ( V_3 , V_5 , V_22 ) ;
} else if ( V_101 -> V_7 & V_117 ) {
unsigned int V_128 = V_101 -> V_7 & V_117 ;
unsigned int V_129 = F_123 ( V_5 ) ;
if ( V_128 != V_129 )
F_124 ( L_11 ,
V_3 , V_128 , V_129 ) ;
}
V_101 -> V_3 = V_3 ;
* V_107 = V_101 ;
V_5 -> V_130 = 0 ;
V_5 -> V_131 = 0 ;
if ( V_110 && ( V_5 -> V_48 & V_122 ) ) {
V_5 -> V_48 &= ~ V_122 ;
F_56 ( V_5 , V_3 , false ) ;
}
F_7 ( & V_5 -> V_9 , V_7 ) ;
if ( V_101 -> V_16 )
F_125 ( V_101 -> V_16 ) ;
F_126 ( V_3 , V_5 ) ;
V_101 -> V_132 = NULL ;
F_127 ( V_3 , V_101 ) ;
F_35 ( V_22 ) ;
return 0 ;
V_118:
#ifdef F_128
if ( ! ( V_101 -> V_7 & V_133 ) ) {
F_107 ( V_55 L_12 , V_3 ) ;
if ( V_108 )
F_107 ( V_55 L_13 , V_108 ) ;
F_129 () ;
}
#endif
V_25 = - V_119 ;
V_120:
F_7 ( & V_5 -> V_9 , V_7 ) ;
F_35 ( V_22 ) ;
V_116:
if ( V_101 -> V_16 ) {
struct V_96 * V_114 = V_101 -> V_16 ;
V_101 -> V_16 = NULL ;
if ( F_130 ( ! F_91 ( V_100 , & V_101 -> V_18 ) ) )
F_131 ( V_114 ) ;
F_132 ( V_114 ) ;
}
return V_25 ;
}
int F_133 ( unsigned int V_3 , struct V_14 * V_134 )
{
int V_135 ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_86 ( V_5 ) ;
V_135 = F_109 ( V_3 , V_5 , V_134 ) ;
F_90 ( V_5 ) ;
return V_135 ;
}
static struct V_14 * F_134 ( unsigned int V_3 , void * V_72 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_14 * V_15 , * * V_136 ;
unsigned long V_7 ;
F_57 ( F_135 () , L_14 , V_3 ) ;
if ( ! V_5 )
return NULL ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_136 = & V_5 -> V_15 ;
for (; ; ) {
V_15 = * V_136 ;
if ( ! V_15 ) {
F_57 ( 1 , L_15 , V_3 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
return NULL ;
}
if ( V_15 -> V_72 == V_72 )
break;
V_136 = & V_15 -> V_19 ;
}
* V_136 = V_15 -> V_19 ;
#ifdef F_136
if ( V_5 -> V_8 . V_12 -> V_40 )
V_5 -> V_8 . V_12 -> V_40 ( V_3 , V_72 ) ;
#endif
if ( ! V_5 -> V_15 )
F_137 ( V_5 ) ;
#ifdef F_138
if ( F_139 ( V_5 -> V_35 ) )
V_5 -> V_35 = NULL ;
#endif
F_7 ( & V_5 -> V_9 , V_7 ) ;
F_140 ( V_3 , V_15 ) ;
F_2 ( V_3 ) ;
#ifdef F_128
if ( V_15 -> V_7 & V_63 ) {
F_141 ( V_7 ) ;
V_15 -> V_105 ( V_3 , V_72 ) ;
F_142 ( V_7 ) ;
}
#endif
if ( V_15 -> V_16 ) {
if ( ! F_91 ( V_100 , & V_15 -> V_18 ) )
F_131 ( V_15 -> V_16 ) ;
F_132 ( V_15 -> V_16 ) ;
}
return V_15 ;
}
void F_143 ( unsigned int V_3 , struct V_14 * V_134 )
{
F_134 ( V_3 , V_134 -> V_72 ) ;
}
void F_144 ( unsigned int V_3 , void * V_72 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return;
#ifdef F_138
if ( F_145 ( V_5 -> V_30 ) )
V_5 -> V_30 = NULL ;
#endif
F_86 ( V_5 ) ;
F_146 ( F_134 ( V_3 , V_72 ) ) ;
F_90 ( V_5 ) ;
}
int F_147 ( unsigned int V_3 , T_4 V_105 ,
T_4 V_85 , unsigned long V_61 ,
const char * V_137 , void * V_72 )
{
struct V_14 * V_15 ;
struct V_4 * V_5 ;
int V_135 ;
if ( ( V_61 & V_63 ) && ! V_72 )
return - V_26 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return - V_26 ;
if ( ! F_65 ( V_5 ) )
return - V_26 ;
if ( ! V_105 ) {
if ( ! V_85 )
return - V_26 ;
V_105 = F_77 ;
}
V_15 = F_148 ( sizeof( struct V_14 ) , V_38 ) ;
if ( ! V_15 )
return - V_115 ;
V_15 -> V_105 = V_105 ;
V_15 -> V_85 = V_85 ;
V_15 -> V_7 = V_61 ;
V_15 -> V_66 = V_137 ;
V_15 -> V_72 = V_72 ;
F_86 ( V_5 ) ;
V_135 = F_109 ( V_3 , V_5 , V_15 ) ;
F_90 ( V_5 ) ;
if ( V_135 )
F_146 ( V_15 ) ;
#ifdef F_149
if ( ! V_135 && ( V_61 & V_63 ) ) {
unsigned long V_7 ;
F_55 ( V_3 ) ;
F_141 ( V_7 ) ;
V_105 ( V_3 , V_72 ) ;
F_142 ( V_7 ) ;
F_61 ( V_3 ) ;
}
#endif
return V_135 ;
}
int F_150 ( unsigned int V_3 , T_4 V_105 ,
unsigned long V_7 , const char * V_66 , void * V_72 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_25 ;
if ( ! V_5 )
return - V_26 ;
if ( F_111 ( V_5 ) ) {
V_25 = F_147 ( V_3 , NULL , V_105 ,
V_7 , V_66 , V_72 ) ;
return ! V_25 ? V_138 : V_25 ;
}
V_25 = F_151 ( V_3 , V_105 , V_7 , V_66 , V_72 ) ;
return ! V_25 ? V_139 : V_25 ;
}
