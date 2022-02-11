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
struct V_4 * V_5 = F_30 ( V_3 , & V_7 , V_35 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_36 = V_34 ;
F_31 ( V_5 , V_7 ) ;
return 0 ;
}
static void F_32 ( struct V_37 * V_32 )
{
struct F_32 * V_38 =
F_33 ( V_32 , struct F_32 , V_32 ) ;
struct V_4 * V_5 = F_3 ( V_38 -> V_3 ) ;
T_2 V_21 ;
unsigned long V_7 ;
if ( ! V_5 || ! F_34 ( & V_21 , V_39 ) )
goto V_40;
F_6 ( & V_5 -> V_9 , V_7 ) ;
if ( F_16 ( & V_5 -> V_8 ) )
F_20 ( V_21 , V_5 ) ;
else
F_19 ( V_21 , V_5 -> V_8 . V_28 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
V_38 -> V_38 ( V_38 , V_21 ) ;
F_35 ( V_21 ) ;
V_40:
F_36 ( & V_38 -> V_31 , V_38 -> V_41 ) ;
}
int
F_37 ( unsigned int V_3 , struct F_32 * V_38 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct F_32 * V_42 ;
unsigned long V_7 ;
F_38 () ;
if ( ! V_5 )
return - V_26 ;
if ( V_38 ) {
V_38 -> V_3 = V_3 ;
F_39 ( & V_38 -> V_31 ) ;
F_40 ( & V_38 -> V_32 , F_32 ) ;
}
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_42 = V_5 -> V_30 ;
V_5 -> V_30 = V_38 ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
if ( V_42 )
F_36 ( & V_42 -> V_31 , V_42 -> V_41 ) ;
return 0 ;
}
static int
F_41 ( unsigned int V_3 , struct V_4 * V_5 , struct V_21 * V_22 )
{
struct V_24 * V_12 = F_42 ( V_5 ) ;
struct V_21 * V_43 = V_44 ;
int V_25 ;
if ( ! F_10 ( V_3 ) )
return 0 ;
if ( F_43 ( & V_5 -> V_8 , V_33 ) ) {
if ( F_44 ( V_5 -> V_8 . V_28 ,
V_45 ) )
V_43 = V_5 -> V_8 . V_28 ;
else
F_45 ( & V_5 -> V_8 , V_33 ) ;
}
F_46 ( V_22 , V_45 , V_43 ) ;
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
F_41 ( unsigned int V_3 , struct V_4 * V_46 , struct V_21 * V_22 )
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
void F_49 ( struct V_4 * V_5 , unsigned int V_3 , bool V_47 )
{
if ( V_47 ) {
if ( ! V_5 -> V_15 || ( V_5 -> V_15 -> V_7 & V_48 ) )
return;
V_5 -> V_49 |= V_50 ;
}
if ( ! V_5 -> V_51 ++ )
F_50 ( V_5 ) ;
}
static int F_51 ( unsigned int V_3 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 , V_35 ) ;
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
void F_56 ( struct V_4 * V_5 , unsigned int V_3 , bool V_52 )
{
if ( V_52 ) {
if ( ! ( V_5 -> V_49 & V_50 ) ) {
if ( ! V_5 -> V_15 )
return;
if ( ! ( V_5 -> V_15 -> V_7 & V_53 ) )
return;
V_5 -> V_51 ++ ;
}
V_5 -> V_49 &= ~ V_50 ;
}
switch ( V_5 -> V_51 ) {
case 0 :
V_54:
F_57 ( 1 , V_55 L_1 , V_3 ) ;
break;
case 1 : {
if ( V_5 -> V_49 & V_50 )
goto V_54;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
F_60 ( V_5 , V_3 ) ;
}
default:
V_5 -> V_51 -- ;
}
}
void F_61 ( unsigned int V_3 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 , V_35 ) ;
if ( ! V_5 )
return;
if ( F_57 ( ! V_5 -> V_8 . V_12 ,
V_56 L_2 , V_3 ) )
goto V_40;
F_56 ( V_5 , V_3 , false ) ;
V_40:
F_53 ( V_5 , V_7 ) ;
}
static int F_62 ( unsigned int V_3 , unsigned int V_57 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_25 = - V_58 ;
if ( F_42 ( V_5 ) -> V_7 & V_59 )
return 0 ;
if ( V_5 -> V_8 . V_12 -> V_60 )
V_25 = V_5 -> V_8 . V_12 -> V_60 ( & V_5 -> V_8 , V_57 ) ;
return V_25 ;
}
int F_63 ( unsigned int V_3 , unsigned int V_57 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_52 ( V_3 , & V_7 , V_35 ) ;
int V_25 = 0 ;
if ( ! V_5 )
return - V_26 ;
if ( V_57 ) {
if ( V_5 -> V_61 ++ == 0 ) {
V_25 = F_62 ( V_3 , V_57 ) ;
if ( V_25 )
V_5 -> V_61 = 0 ;
else
F_27 ( & V_5 -> V_8 , V_62 ) ;
}
} else {
if ( V_5 -> V_61 == 0 ) {
F_57 ( 1 , L_3 , V_3 ) ;
} else if ( -- V_5 -> V_61 == 0 ) {
V_25 = F_62 ( V_3 , V_57 ) ;
if ( V_25 )
V_5 -> V_61 = 1 ;
else
F_45 ( & V_5 -> V_8 , V_62 ) ;
}
}
F_53 ( V_5 , V_7 ) ;
return V_25 ;
}
int F_64 ( unsigned int V_3 , unsigned long V_63 )
{
unsigned long V_7 ;
struct V_4 * V_5 = F_30 ( V_3 , & V_7 , 0 ) ;
int V_64 = 0 ;
if ( ! V_5 )
return 0 ;
if ( F_65 ( V_5 ) ) {
if ( V_5 -> V_15 )
if ( V_63 & V_5 -> V_15 -> V_7 & V_65 )
V_64 = 1 ;
}
F_31 ( V_5 , V_7 ) ;
return V_64 ;
}
int F_66 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned long V_7 )
{
struct V_24 * V_12 = V_5 -> V_8 . V_12 ;
int V_25 , V_66 = 0 ;
if ( ! V_12 || ! V_12 -> V_67 ) {
F_67 ( L_4 , V_3 ,
V_12 ? ( V_12 -> V_68 ? : L_5 ) : L_5 ) ;
return 0 ;
}
V_7 &= V_69 ;
if ( V_12 -> V_7 & V_70 ) {
if ( ! F_68 ( & V_5 -> V_8 ) )
F_69 ( V_5 ) ;
if ( ! F_70 ( & V_5 -> V_8 ) )
V_66 = 1 ;
}
V_25 = V_12 -> V_67 ( & V_5 -> V_8 , V_7 ) ;
switch ( V_25 ) {
case V_27 :
F_45 ( & V_5 -> V_8 , V_71 ) ;
F_27 ( & V_5 -> V_8 , V_7 ) ;
case V_29 :
V_7 = F_71 ( & V_5 -> V_8 ) ;
F_72 ( V_5 , V_7 ) ;
F_45 ( & V_5 -> V_8 , V_72 ) ;
F_73 ( V_5 ) ;
if ( V_7 & V_73 ) {
F_74 ( V_5 ) ;
F_27 ( & V_5 -> V_8 , V_72 ) ;
}
V_25 = 0 ;
break;
default:
F_75 ( L_6 ,
V_7 , V_3 , V_12 -> V_67 ) ;
}
if ( V_66 )
F_76 ( V_5 ) ;
return V_25 ;
}
static T_3 F_77 ( int V_3 , void * V_74 )
{
return V_75 ;
}
static T_3 F_78 ( int V_3 , void * V_74 )
{
F_57 ( 1 , L_7 , V_3 ) ;
return V_76 ;
}
static int F_79 ( struct V_14 * V_15 )
{
F_80 ( V_77 ) ;
while ( ! F_81 () ) {
if ( F_82 ( V_78 ,
& V_15 -> V_18 ) ) {
F_83 ( V_79 ) ;
return 0 ;
}
F_84 () ;
F_80 ( V_77 ) ;
}
F_83 ( V_79 ) ;
return - 1 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_14 * V_15 , bool V_80 )
{
if ( ! ( V_5 -> V_49 & V_81 ) )
return;
V_82:
F_86 ( V_5 ) ;
F_87 ( & V_5 -> V_9 ) ;
if ( F_88 ( F_4 ( & V_5 -> V_8 ) ) ) {
F_89 ( & V_5 -> V_9 ) ;
F_90 ( V_5 ) ;
F_5 () ;
goto V_82;
}
if ( ! V_80 && F_91 ( V_78 , & V_15 -> V_18 ) )
goto V_83;
V_5 -> V_84 &= ~ V_15 -> V_85 ;
if ( ! V_5 -> V_84 && ! F_70 ( & V_5 -> V_8 ) &&
F_68 ( & V_5 -> V_8 ) )
F_76 ( V_5 ) ;
V_83:
F_89 ( & V_5 -> V_9 ) ;
F_90 ( V_5 ) ;
}
static void
F_92 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
T_2 V_22 ;
if ( ! F_82 ( V_17 , & V_15 -> V_18 ) )
return;
if ( ! F_34 ( & V_22 , V_39 ) ) {
F_13 ( V_17 , & V_15 -> V_18 ) ;
return;
}
F_87 ( & V_5 -> V_9 ) ;
F_19 ( V_22 , V_5 -> V_8 . V_28 ) ;
F_89 ( & V_5 -> V_9 ) ;
F_93 ( V_86 , V_22 ) ;
F_35 ( V_22 ) ;
}
static inline void
F_92 ( struct V_4 * V_5 , struct V_14 * V_15 ) { }
static T_3
F_94 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
T_3 V_25 ;
F_95 () ;
V_25 = V_15 -> V_87 ( V_15 -> V_3 , V_15 -> V_74 ) ;
F_85 ( V_5 , V_15 , false ) ;
F_96 () ;
return V_25 ;
}
static T_3 F_97 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
T_3 V_25 ;
V_25 = V_15 -> V_87 ( V_15 -> V_3 , V_15 -> V_74 ) ;
F_85 ( V_5 , V_15 , false ) ;
return V_25 ;
}
static int F_98 ( void * V_20 )
{
static const struct V_88 V_89 = {
. V_90 = V_91 / 2 ,
} ;
struct V_14 * V_15 = V_20 ;
struct V_4 * V_5 = F_3 ( V_15 -> V_3 ) ;
T_3 (* F_99)( struct V_4 * V_5 ,
struct V_14 * V_15 );
int V_92 ;
if ( V_2 & F_91 ( V_93 ,
& V_15 -> V_18 ) )
F_99 = F_94 ;
else
F_99 = F_97 ;
F_100 ( V_86 , V_94 , & V_89 ) ;
V_86 -> V_14 = V_15 ;
while ( ! F_79 ( V_15 ) ) {
F_92 ( V_5 , V_15 ) ;
F_101 ( & V_5 -> V_11 ) ;
F_87 ( & V_5 -> V_9 ) ;
if ( F_88 ( F_70 ( & V_5 -> V_8 ) ) ) {
V_5 -> V_49 |= V_95 ;
F_89 ( & V_5 -> V_9 ) ;
} else {
T_3 V_96 ;
F_89 ( & V_5 -> V_9 ) ;
V_96 = F_99 ( V_5 , V_15 ) ;
if ( ! V_97 )
F_102 ( V_15 -> V_3 , V_5 , V_96 ) ;
}
V_92 = F_103 ( & V_5 -> V_11 ) ;
if ( V_92 && F_104 ( & V_5 -> V_10 ) )
F_105 ( & V_5 -> V_10 ) ;
}
F_85 ( V_5 , V_15 , true ) ;
V_86 -> V_14 = NULL ;
return 0 ;
}
void F_106 ( void )
{
struct V_98 * V_99 = V_86 ;
struct V_4 * V_5 ;
if ( ! V_99 -> V_14 )
return;
F_107 ( V_56
L_8 ,
V_99 -> V_100 ? V_99 -> V_100 : L_9 , V_99 -> V_101 , V_99 -> V_14 -> V_3 ) ;
V_5 = F_3 ( V_99 -> V_14 -> V_3 ) ;
F_85 ( V_5 , V_99 -> V_14 , true ) ;
F_13 ( V_102 , & V_99 -> V_14 -> V_7 ) ;
}
static void F_108 ( struct V_14 * V_103 )
{
if ( ! V_2 )
return;
if ( V_103 -> V_7 & ( V_104 | V_105 | V_106 ) )
return;
V_103 -> V_7 |= V_106 ;
if ( ! V_103 -> V_87 ) {
F_13 ( V_93 , & V_103 -> V_18 ) ;
V_103 -> V_87 = V_103 -> V_107 ;
V_103 -> V_107 = F_77 ;
}
}
static int
F_109 ( unsigned int V_3 , struct V_4 * V_5 , struct V_14 * V_103 )
{
struct V_14 * V_108 , * * V_109 ;
const char * V_110 = NULL ;
unsigned long V_7 , V_85 = 0 ;
int V_25 , V_111 , V_112 = 0 ;
T_2 V_22 ;
if ( ! V_5 )
return - V_26 ;
if ( V_5 -> V_8 . V_12 == & V_113 )
return - V_114 ;
if ( ! F_110 ( V_5 -> V_115 ) )
return - V_116 ;
if ( V_103 -> V_7 & V_117 ) {
F_111 ( V_3 ) ;
}
V_111 = F_112 ( V_5 ) ;
if ( V_111 ) {
if ( ! V_103 -> V_87 ) {
V_25 = - V_26 ;
goto V_118;
}
V_103 -> V_107 = F_78 ;
} else {
if ( F_113 ( V_5 ) )
F_108 ( V_103 ) ;
}
if ( V_103 -> V_87 && ! V_111 ) {
struct V_98 * V_119 ;
V_119 = F_114 ( F_98 , V_103 , L_10 , V_3 ,
V_103 -> V_68 ) ;
if ( F_115 ( V_119 ) ) {
V_25 = F_116 ( V_119 ) ;
goto V_118;
}
F_117 ( V_119 ) ;
V_103 -> V_16 = V_119 ;
}
if ( ! F_34 ( & V_22 , V_39 ) ) {
V_25 = - V_120 ;
goto V_121;
}
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_109 = & V_5 -> V_15 ;
V_108 = * V_109 ;
if ( V_108 ) {
if ( ! ( ( V_108 -> V_7 & V_103 -> V_7 ) & V_65 ) ||
( ( V_108 -> V_7 ^ V_103 -> V_7 ) & V_122 ) ||
( ( V_108 -> V_7 ^ V_103 -> V_7 ) & V_106 ) ) {
V_110 = V_108 -> V_68 ;
goto V_123;
}
if ( ( V_108 -> V_7 & V_105 ) !=
( V_103 -> V_7 & V_105 ) )
goto V_123;
do {
V_85 |= V_108 -> V_85 ;
V_109 = & V_108 -> V_19 ;
V_108 = * V_109 ;
} while ( V_108 );
V_112 = 1 ;
}
if ( V_103 -> V_7 & V_106 ) {
if ( V_85 == ~ 0UL ) {
V_25 = - V_124 ;
goto V_125;
}
V_103 -> V_85 = 1 << F_118 ( V_85 ) ;
}
if ( ! V_112 ) {
F_119 ( & V_5 -> V_10 ) ;
if ( V_103 -> V_7 & V_122 ) {
V_25 = F_66 ( V_5 , V_3 ,
V_103 -> V_7 & V_122 ) ;
if ( V_25 )
goto V_125;
}
V_5 -> V_49 &= ~ ( V_126 | V_127 | \
V_81 | V_128 ) ;
F_45 ( & V_5 -> V_8 , V_129 ) ;
if ( V_103 -> V_7 & V_105 ) {
F_27 ( & V_5 -> V_8 , V_130 ) ;
F_120 ( V_5 ) ;
}
if ( V_103 -> V_7 & V_106 )
V_5 -> V_49 |= V_81 ;
if ( F_121 ( V_5 ) )
F_122 ( V_5 , true ) ;
else
V_5 -> V_51 = 1 ;
if ( V_103 -> V_7 & V_131 ) {
F_123 ( V_5 ) ;
F_27 ( & V_5 -> V_8 , V_132 ) ;
}
F_41 ( V_3 , V_5 , V_22 ) ;
} else if ( V_103 -> V_7 & V_122 ) {
unsigned int V_133 = V_103 -> V_7 & V_122 ;
unsigned int V_134 = F_124 ( V_5 ) ;
if ( V_133 != V_134 )
F_125 ( L_11 ,
V_3 , V_133 , V_134 ) ;
}
V_103 -> V_3 = V_3 ;
* V_109 = V_103 ;
V_5 -> V_135 = 0 ;
V_5 -> V_136 = 0 ;
if ( V_112 && ( V_5 -> V_49 & V_127 ) ) {
V_5 -> V_49 &= ~ V_127 ;
F_56 ( V_5 , V_3 , false ) ;
}
F_7 ( & V_5 -> V_9 , V_7 ) ;
if ( V_103 -> V_16 )
F_126 ( V_103 -> V_16 ) ;
F_127 ( V_3 , V_5 ) ;
V_103 -> V_137 = NULL ;
F_128 ( V_3 , V_103 ) ;
F_35 ( V_22 ) ;
return 0 ;
V_123:
#ifdef F_129
if ( ! ( V_103 -> V_7 & V_138 ) ) {
F_107 ( V_56 L_12 , V_3 ) ;
if ( V_110 )
F_107 ( V_56 L_13 , V_110 ) ;
F_130 () ;
}
#endif
V_25 = - V_124 ;
V_125:
F_7 ( & V_5 -> V_9 , V_7 ) ;
F_35 ( V_22 ) ;
V_121:
if ( V_103 -> V_16 ) {
struct V_98 * V_119 = V_103 -> V_16 ;
V_103 -> V_16 = NULL ;
if ( F_131 ( ! F_91 ( V_102 , & V_103 -> V_18 ) ) )
F_132 ( V_119 ) ;
F_133 ( V_119 ) ;
}
V_118:
F_134 ( V_5 -> V_115 ) ;
return V_25 ;
}
int F_135 ( unsigned int V_3 , struct V_14 * V_139 )
{
int V_140 ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( F_136 ( F_137 ( V_5 ) ) )
return - V_26 ;
F_86 ( V_5 ) ;
V_140 = F_109 ( V_3 , V_5 , V_139 ) ;
F_90 ( V_5 ) ;
return V_140 ;
}
static struct V_14 * F_138 ( unsigned int V_3 , void * V_74 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_14 * V_15 , * * V_141 ;
unsigned long V_7 ;
F_57 ( F_139 () , L_14 , V_3 ) ;
if ( ! V_5 )
return NULL ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_141 = & V_5 -> V_15 ;
for (; ; ) {
V_15 = * V_141 ;
if ( ! V_15 ) {
F_57 ( 1 , L_15 , V_3 ) ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
return NULL ;
}
if ( V_15 -> V_74 == V_74 )
break;
V_141 = & V_15 -> V_19 ;
}
* V_141 = V_15 -> V_19 ;
#ifdef F_140
if ( V_5 -> V_8 . V_12 -> V_41 )
V_5 -> V_8 . V_12 -> V_41 ( V_3 , V_74 ) ;
#endif
if ( ! V_5 -> V_15 )
F_141 ( V_5 ) ;
#ifdef F_142
if ( F_143 ( V_5 -> V_36 ) )
V_5 -> V_36 = NULL ;
#endif
F_7 ( & V_5 -> V_9 , V_7 ) ;
F_144 ( V_3 , V_15 ) ;
F_2 ( V_3 ) ;
#ifdef F_129
if ( V_15 -> V_7 & V_65 ) {
F_145 ( V_7 ) ;
V_15 -> V_107 ( V_3 , V_74 ) ;
F_146 ( V_7 ) ;
}
#endif
if ( V_15 -> V_16 ) {
if ( ! F_91 ( V_102 , & V_15 -> V_18 ) )
F_132 ( V_15 -> V_16 ) ;
F_133 ( V_15 -> V_16 ) ;
}
F_134 ( V_5 -> V_115 ) ;
return V_15 ;
}
void F_147 ( unsigned int V_3 , struct V_14 * V_139 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_5 && ! F_136 ( F_137 ( V_5 ) ) )
F_138 ( V_3 , V_139 -> V_74 ) ;
}
void F_148 ( unsigned int V_3 , void * V_74 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( ! V_5 || F_136 ( F_137 ( V_5 ) ) )
return;
#ifdef F_142
if ( F_136 ( V_5 -> V_30 ) )
V_5 -> V_30 = NULL ;
#endif
F_86 ( V_5 ) ;
F_149 ( F_138 ( V_3 , V_74 ) ) ;
F_90 ( V_5 ) ;
}
int F_150 ( unsigned int V_3 , T_4 V_107 ,
T_4 V_87 , unsigned long V_63 ,
const char * V_142 , void * V_74 )
{
struct V_14 * V_15 ;
struct V_4 * V_5 ;
int V_140 ;
if ( ( V_63 & V_65 ) && ! V_74 )
return - V_26 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return - V_26 ;
if ( ! F_65 ( V_5 ) ||
F_136 ( F_137 ( V_5 ) ) )
return - V_26 ;
if ( ! V_107 ) {
if ( ! V_87 )
return - V_26 ;
V_107 = F_77 ;
}
V_15 = F_151 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_15 )
return - V_120 ;
V_15 -> V_107 = V_107 ;
V_15 -> V_87 = V_87 ;
V_15 -> V_7 = V_63 ;
V_15 -> V_68 = V_142 ;
V_15 -> V_74 = V_74 ;
F_86 ( V_5 ) ;
V_140 = F_109 ( V_3 , V_5 , V_15 ) ;
F_90 ( V_5 ) ;
if ( V_140 )
F_149 ( V_15 ) ;
#ifdef F_152
if ( ! V_140 && ( V_63 & V_65 ) ) {
unsigned long V_7 ;
F_55 ( V_3 ) ;
F_145 ( V_7 ) ;
V_107 ( V_3 , V_74 ) ;
F_146 ( V_7 ) ;
F_61 ( V_3 ) ;
}
#endif
return V_140 ;
}
int F_153 ( unsigned int V_3 , T_4 V_107 ,
unsigned long V_7 , const char * V_68 , void * V_74 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_25 ;
if ( ! V_5 )
return - V_26 ;
if ( F_112 ( V_5 ) ) {
V_25 = F_150 ( V_3 , NULL , V_107 ,
V_7 , V_68 , V_74 ) ;
return ! V_25 ? V_143 : V_25 ;
}
V_25 = F_154 ( V_3 , V_107 , V_7 , V_68 , V_74 ) ;
return ! V_25 ? V_144 : V_25 ;
}
void F_155 ( unsigned int V_3 , unsigned int type )
{
unsigned int V_145 = F_156 () ;
unsigned long V_7 ;
struct V_4 * V_5 = F_30 ( V_3 , & V_7 , V_146 ) ;
if ( ! V_5 )
return;
type &= V_69 ;
if ( type != V_147 ) {
int V_25 ;
V_25 = F_66 ( V_5 , V_3 , type ) ;
if ( V_25 ) {
F_57 ( 1 , L_16 , V_3 ) ;
goto V_40;
}
}
F_157 ( V_5 , V_145 ) ;
V_40:
F_31 ( V_5 , V_7 ) ;
}
void F_158 ( unsigned int V_3 )
{
unsigned int V_145 = F_156 () ;
unsigned long V_7 ;
struct V_4 * V_5 = F_30 ( V_3 , & V_7 , V_146 ) ;
if ( ! V_5 )
return;
F_159 ( V_5 , V_145 ) ;
F_31 ( V_5 , V_7 ) ;
}
static struct V_14 * F_160 ( unsigned int V_3 , void T_5 * V_74 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_14 * V_15 ;
unsigned long V_7 ;
F_57 ( F_139 () , L_14 , V_3 ) ;
if ( ! V_5 )
return NULL ;
F_6 ( & V_5 -> V_9 , V_7 ) ;
V_15 = V_5 -> V_15 ;
if ( ! V_15 || V_15 -> V_148 != V_74 ) {
F_57 ( 1 , L_15 , V_3 ) ;
goto V_149;
}
if ( ! F_161 ( V_5 -> V_150 ) ) {
F_57 ( 1 , L_17 ,
V_3 , F_162 ( V_5 -> V_150 ) ) ;
goto V_149;
}
V_5 -> V_15 = NULL ;
F_7 ( & V_5 -> V_9 , V_7 ) ;
F_144 ( V_3 , V_15 ) ;
F_134 ( V_5 -> V_115 ) ;
return V_15 ;
V_149:
F_7 ( & V_5 -> V_9 , V_7 ) ;
return NULL ;
}
void F_163 ( unsigned int V_3 , struct V_14 * V_139 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( V_5 && F_137 ( V_5 ) )
F_160 ( V_3 , V_139 -> V_148 ) ;
}
void F_164 ( unsigned int V_3 , void T_5 * V_74 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
if ( ! V_5 || ! F_137 ( V_5 ) )
return;
F_86 ( V_5 ) ;
F_149 ( F_160 ( V_3 , V_74 ) ) ;
F_90 ( V_5 ) ;
}
int F_165 ( unsigned int V_3 , struct V_14 * V_139 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_140 ;
if ( ! V_5 || ! F_137 ( V_5 ) )
return - V_26 ;
F_86 ( V_5 ) ;
V_140 = F_109 ( V_3 , V_5 , V_139 ) ;
F_90 ( V_5 ) ;
return V_140 ;
}
int F_166 ( unsigned int V_3 , T_4 V_107 ,
const char * V_142 , void T_5 * V_74 )
{
struct V_14 * V_15 ;
struct V_4 * V_5 ;
int V_140 ;
if ( ! V_74 )
return - V_26 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 || ! F_65 ( V_5 ) ||
! F_137 ( V_5 ) )
return - V_26 ;
V_15 = F_151 ( sizeof( struct V_14 ) , V_39 ) ;
if ( ! V_15 )
return - V_120 ;
V_15 -> V_107 = V_107 ;
V_15 -> V_7 = V_105 | V_48 ;
V_15 -> V_68 = V_142 ;
V_15 -> V_148 = V_74 ;
F_86 ( V_5 ) ;
V_140 = F_109 ( V_3 , V_5 , V_15 ) ;
F_90 ( V_5 ) ;
if ( V_140 )
F_149 ( V_15 ) ;
return V_140 ;
}
