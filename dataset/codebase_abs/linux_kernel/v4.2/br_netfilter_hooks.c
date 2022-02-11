static inline T_1 F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_2 -> V_3 ;
else if ( V_2 -> V_3 == F_3 ( V_4 ) )
return F_4 ( V_2 ) -> V_5 ;
else
return 0 ;
}
static inline T_1 F_5 ( const struct V_1 * V_2 )
{
return * ( ( T_1 * ) ( F_6 ( V_2 ) + V_6 +
sizeof( struct V_7 ) ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_8 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
}
static inline struct V_9 * F_9 ( const struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_10 ( V_10 ) ;
return V_12 ? V_12 -> V_13 -> V_10 : NULL ;
}
static inline struct V_14 * F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = V_2 -> V_8 ;
if ( F_12 ( & V_8 -> V_15 ) > 1 ) {
struct V_14 * V_16 = F_13 ( V_2 ) ;
if ( V_16 ) {
memcpy ( V_16 , V_8 , sizeof( struct V_14 ) ) ;
F_14 ( & V_16 -> V_15 , 1 ) ;
}
F_8 ( V_8 ) ;
V_8 = V_16 ;
}
return V_8 ;
}
unsigned int F_15 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case F_16 ( V_4 ) :
return V_17 ;
case F_16 ( V_18 ) :
return V_19 ;
default:
return 0 ;
}
}
static inline void F_17 ( struct V_1 * V_2 )
{
unsigned int V_20 = F_15 ( V_2 ) ;
F_18 ( V_2 , V_20 ) ;
V_2 -> V_21 += V_20 ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
unsigned int V_20 = F_15 ( V_2 ) ;
F_20 ( V_2 , V_20 ) ;
V_2 -> V_21 += V_20 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_22 * V_23 ;
struct V_9 * V_10 = V_2 -> V_10 ;
T_2 V_20 ;
if ( ! F_22 ( V_2 , sizeof( struct V_22 ) ) )
goto V_24;
V_23 = F_23 ( V_2 ) ;
if ( V_23 -> V_25 < 5 || V_23 -> V_26 != 4 )
goto V_24;
if ( ! F_22 ( V_2 , V_23 -> V_25 * 4 ) )
goto V_24;
V_23 = F_23 ( V_2 ) ;
if ( F_24 ( F_25 ( ( V_27 * ) V_23 , V_23 -> V_25 ) ) )
goto V_24;
V_20 = F_26 ( V_23 -> V_28 ) ;
if ( V_2 -> V_20 < V_20 ) {
F_27 ( F_28 ( V_10 ) , V_29 ) ;
goto V_30;
} else if ( V_20 < ( V_23 -> V_25 * 4 ) )
goto V_24;
if ( F_29 ( V_2 , V_20 ) ) {
F_27 ( F_28 ( V_10 ) , V_31 ) ;
goto V_30;
}
memset ( F_30 ( V_2 ) , 0 , sizeof( struct V_32 ) ) ;
return 0 ;
V_24:
F_27 ( F_28 ( V_10 ) , V_33 ) ;
V_30:
return - 1 ;
}
void F_31 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_34 ) {
case V_35 :
V_2 -> V_3 = F_3 ( V_4 ) ;
break;
case V_36 :
V_2 -> V_3 = F_3 ( V_18 ) ;
break;
case V_37 :
break;
}
}
int F_32 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_2 -> V_10 = F_9 ( V_2 -> V_10 ) ;
if ( ! V_2 -> V_10 )
goto V_44;
V_43 = F_33 ( V_2 ) ;
V_41 = F_34 ( V_43 , V_2 ) ;
if ( V_41 ) {
struct V_14 * V_8 = F_35 ( V_2 ) ;
int V_45 ;
if ( V_41 -> V_46 . V_47 ) {
F_36 ( & V_41 -> V_46 , V_2 ) ;
V_2 -> V_10 = V_8 -> V_48 ;
V_45 = F_37 ( V_39 , V_2 ) ;
} else {
F_38 ( V_2 ,
- ( V_6 - V_49 ) ,
V_8 -> V_50 ,
V_6 - V_49 ) ;
V_8 -> V_51 |= V_52 ;
V_45 = V_41 -> V_53 ( V_41 , V_2 ) ;
}
F_39 ( V_41 ) ;
return V_45 ;
}
V_44:
F_40 ( V_2 ) ;
return 0 ;
}
static inline bool
F_41 ( const struct V_1 * V_2 ,
const struct V_14 * V_8 )
{
return F_23 ( V_2 ) -> V_54 != V_8 -> V_55 ;
}
static int F_42 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_56 * V_57 ;
int V_58 ;
V_8 -> V_59 = F_30 ( V_2 ) -> V_59 ;
if ( V_8 -> V_60 ) {
V_2 -> V_61 = V_62 ;
V_8 -> V_60 = false ;
}
V_8 -> V_51 &= ~ V_63 ;
if ( F_41 ( V_2 , V_8 ) ) {
if ( ( V_58 = F_43 ( V_2 , V_23 -> V_54 , V_23 -> V_64 , V_23 -> V_65 , V_10 ) ) ) {
struct V_66 * V_67 = F_44 ( V_10 ) ;
if ( V_58 != - V_68 || ! V_67 || F_45 ( V_67 ) )
goto V_44;
V_57 = F_46 ( F_28 ( V_10 ) , V_23 -> V_54 , 0 ,
F_47 ( V_23 -> V_65 ) , 0 ) ;
if ( ! F_48 ( V_57 ) ) {
if ( V_57 -> V_43 . V_10 == V_10 ) {
F_49 ( V_2 , & V_57 -> V_43 ) ;
goto V_69;
}
F_50 ( V_57 ) ;
}
V_44:
F_40 ( V_2 ) ;
return 0 ;
} else {
if ( F_33 ( V_2 ) -> V_10 == V_10 ) {
V_69:
V_2 -> V_10 = V_8 -> V_48 ;
F_31 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_70 ,
V_71 ,
V_39 , V_2 , V_2 -> V_10 , NULL ,
F_32 ,
1 ) ;
return 0 ;
}
F_53 ( F_54 ( V_2 ) -> V_72 , V_10 -> V_73 ) ;
V_2 -> V_61 = V_74 ;
}
} else {
V_57 = F_55 ( V_8 -> V_48 ) ;
if ( ! V_57 ) {
F_40 ( V_2 ) ;
return 0 ;
}
F_56 ( V_2 , & V_57 -> V_43 ) ;
}
V_2 -> V_10 = V_8 -> V_48 ;
F_31 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_70 , V_71 , V_39 , V_2 ,
V_2 -> V_10 , NULL ,
F_37 , 1 ) ;
return 0 ;
}
static struct V_9 * F_57 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_9 * V_75 , * V_13 ;
V_13 = F_9 ( V_10 ) ;
if ( V_76 == 0 || ! F_2 ( V_2 ) )
return V_13 ;
V_75 = F_58 ( V_13 , V_2 -> F_1 ,
F_59 ( V_2 ) & V_77 ) ;
return V_75 ? V_75 : V_13 ;
}
struct V_9 * F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_74 ;
V_8 -> V_60 = true ;
}
V_8 -> V_51 |= V_63 ;
V_8 -> V_48 = V_2 -> V_10 ;
V_2 -> V_10 = F_57 ( V_2 , V_2 -> V_10 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_8 -> V_34 = V_35 ;
else if ( V_2 -> V_3 == F_3 ( V_18 ) )
V_8 -> V_34 = V_36 ;
F_61 ( V_2 ) ;
return V_2 -> V_10 ;
}
static unsigned int F_62 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
struct V_14 * V_8 ;
struct V_11 * V_82 ;
struct V_83 * V_13 ;
T_3 V_20 = F_15 ( V_2 ) ;
if ( F_24 ( ! F_22 ( V_2 , V_20 ) ) )
return V_84 ;
V_82 = F_10 ( V_81 -> V_85 ) ;
if ( V_82 == NULL )
return V_84 ;
V_13 = V_82 -> V_13 ;
if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) ) {
if ( ! V_86 && ! V_13 -> V_87 )
return V_88 ;
F_19 ( V_2 ) ;
return F_66 ( V_79 , V_2 , V_81 ) ;
}
if ( ! V_89 && ! V_13 -> V_90 )
return V_88 ;
if ( ! F_67 ( V_2 ) && ! F_68 ( V_2 ) && ! F_69 ( V_2 ) )
return V_88 ;
F_19 ( V_2 ) ;
if ( F_21 ( V_2 ) )
return V_84 ;
F_8 ( V_2 -> V_8 ) ;
if ( ! F_13 ( V_2 ) )
return V_84 ;
if ( ! F_60 ( V_2 ) )
return V_84 ;
V_8 = F_35 ( V_2 ) ;
V_8 -> V_55 = F_23 ( V_2 ) -> V_54 ;
V_2 -> V_3 = F_3 ( V_91 ) ;
F_70 ( V_92 , V_93 , V_81 -> V_39 , V_2 ,
V_2 -> V_10 , NULL ,
F_42 ) ;
return V_94 ;
}
static unsigned int F_71 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
F_72 ( V_2 ) ;
return V_88 ;
}
static int F_73 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_9 * V_85 ;
if ( ! F_74 ( V_2 ) && ! F_75 ( V_2 ) ) {
if ( V_2 -> V_3 == F_3 ( V_91 ) )
V_8 -> V_59 = F_30 ( V_2 ) -> V_59 ;
if ( V_2 -> V_3 == F_3 ( V_95 ) )
V_8 -> V_59 = F_76 ( V_2 ) -> V_59 ;
V_85 = V_8 -> V_48 ;
if ( V_8 -> V_60 ) {
V_2 -> V_61 = V_62 ;
V_8 -> V_60 = false ;
}
F_31 ( V_2 ) ;
} else {
V_85 = * ( (struct V_9 * * ) ( V_2 -> V_96 ) ) ;
}
F_51 ( V_2 ) ;
F_52 ( V_70 , V_97 , V_39 , V_2 ,
V_85 , V_2 -> V_10 , V_98 , 1 ) ;
return 0 ;
}
static unsigned int F_77 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
struct V_14 * V_8 ;
struct V_9 * V_99 ;
T_4 V_100 ;
if ( ! V_2 -> V_8 )
return V_88 ;
if ( ! F_11 ( V_2 ) )
return V_84 ;
V_8 = F_35 ( V_2 ) ;
if ( ! V_8 )
return V_84 ;
V_99 = F_9 ( V_81 -> V_101 ) ;
if ( ! V_99 )
return V_84 ;
if ( F_67 ( V_2 ) || F_68 ( V_2 ) || F_69 ( V_2 ) )
V_100 = V_92 ;
else if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) )
V_100 = V_102 ;
else
return V_88 ;
F_17 ( V_2 ) ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_74 ;
V_8 -> V_60 = true ;
}
if ( V_100 == V_92 ) {
if ( F_21 ( V_2 ) )
return V_84 ;
F_30 ( V_2 ) -> V_59 = V_8 -> V_59 ;
}
if ( V_100 == V_102 ) {
if ( F_78 ( V_2 ) )
return V_84 ;
F_76 ( V_2 ) -> V_59 = V_8 -> V_59 ;
}
V_8 -> V_103 = V_2 -> V_10 ;
if ( V_100 == V_92 )
V_2 -> V_3 = F_3 ( V_91 ) ;
else
V_2 -> V_3 = F_3 ( V_95 ) ;
F_70 ( V_100 , V_104 , NULL , V_2 ,
F_57 ( V_2 , V_81 -> V_85 ) ,
V_99 , F_73 ) ;
return V_94 ;
}
static unsigned int F_79 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
struct V_11 * V_82 ;
struct V_83 * V_13 ;
struct V_9 * * V_105 = (struct V_9 * * ) ( V_2 -> V_96 ) ;
V_82 = F_10 ( V_81 -> V_101 ) ;
if ( V_82 == NULL )
return V_88 ;
V_13 = V_82 -> V_13 ;
if ( ! V_106 && ! V_13 -> V_107 )
return V_88 ;
if ( ! F_74 ( V_2 ) ) {
if ( ! F_75 ( V_2 ) )
return V_88 ;
F_17 ( V_2 ) ;
}
if ( F_80 ( V_2 ) -> V_108 != 4 ) {
if ( F_75 ( V_2 ) )
F_51 ( V_2 ) ;
return V_88 ;
}
* V_105 = V_81 -> V_85 ;
F_70 ( V_109 , V_110 , V_81 -> V_39 , V_2 ,
V_81 -> V_85 , V_81 -> V_101 , F_73 ) ;
return V_94 ;
}
static int F_81 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_111 * V_112 ;
int V_58 ;
V_112 = F_82 ( & V_113 ) ;
V_58 = F_83 ( V_2 , V_112 -> V_114 ) ;
if ( V_58 ) {
F_40 ( V_2 ) ;
return 0 ;
}
if ( V_112 -> V_115 ) {
V_2 -> V_115 = V_112 -> V_115 ;
V_2 -> F_1 = V_112 -> F_1 ;
}
F_84 ( V_2 , - V_112 -> V_114 , V_112 -> V_116 , V_112 -> V_114 ) ;
F_85 ( V_2 , V_112 -> V_117 ) ;
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
}
static int F_87 ( struct V_38 * V_39 , struct V_1 * V_2 ,
int (* V_53)( struct V_38 * , struct V_1 * ) )
{
unsigned int V_118 = F_88 ( V_2 ) ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_56 * V_57 = F_89 ( V_2 ) ;
struct V_9 * V_10 = V_57 -> V_43 . V_10 ;
if ( F_24 ( ( ( V_23 -> V_119 & F_3 ( V_120 ) ) && ! V_2 -> V_121 ) ||
( F_30 ( V_2 ) -> V_59 &&
F_30 ( V_2 ) -> V_59 > V_118 ) ) ) {
F_90 ( F_28 ( V_10 ) , V_122 ) ;
F_40 ( V_2 ) ;
return - V_123 ;
}
return F_91 ( V_39 , V_2 , V_53 ) ;
}
static unsigned int F_92 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_8 -> V_34 == V_36 )
return V_19 ;
return 0 ;
}
static int F_93 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_14 * V_8 ;
unsigned int V_124 ;
V_124 = F_92 ( V_2 ) ;
if ( F_94 ( V_2 ) || V_2 -> V_20 + V_124 <= V_2 -> V_10 -> V_118 ) {
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
}
V_8 = F_35 ( V_2 ) ;
#if F_95 ( V_125 )
if ( V_2 -> V_3 == F_3 ( V_91 ) ) {
struct V_111 * V_112 ;
if ( F_21 ( V_2 ) )
goto V_30;
F_30 ( V_2 ) -> V_59 = V_8 -> V_59 ;
F_31 ( V_2 ) ;
V_112 = F_82 ( & V_113 ) ;
V_112 -> V_115 = V_2 -> V_115 ;
V_112 -> F_1 = V_2 -> F_1 ;
V_112 -> V_117 = F_15 ( V_2 ) ;
V_112 -> V_114 = V_6 + V_112 -> V_117 ;
F_38 ( V_2 , - V_112 -> V_114 , V_112 -> V_116 ,
V_112 -> V_114 ) ;
return F_87 ( V_39 , V_2 , F_81 ) ;
}
#endif
#if F_95 ( V_126 )
if ( V_2 -> V_3 == F_3 ( V_95 ) ) {
const struct V_127 * V_128 = F_96 () ;
struct V_111 * V_112 ;
if ( F_78 ( V_2 ) )
goto V_30;
F_76 ( V_2 ) -> V_59 = V_8 -> V_59 ;
F_31 ( V_2 ) ;
V_112 = F_82 ( & V_113 ) ;
V_112 -> V_117 = F_15 ( V_2 ) ;
V_112 -> V_114 = V_6 + V_112 -> V_117 ;
F_38 ( V_2 , - V_112 -> V_114 , V_112 -> V_116 ,
V_112 -> V_114 ) ;
if ( V_128 )
return V_128 -> V_129 ( V_39 , V_2 , F_81 ) ;
F_40 ( V_2 ) ;
return - V_123 ;
}
#endif
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
V_30:
F_40 ( V_2 ) ;
return 0 ;
}
static unsigned int F_97 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_9 * V_130 = F_9 ( V_2 -> V_10 ) ;
T_4 V_100 ;
if ( ! V_8 || ! V_8 -> V_103 )
return V_88 ;
if ( ! V_130 )
return V_84 ;
if ( F_67 ( V_2 ) || F_68 ( V_2 ) || F_69 ( V_2 ) )
V_100 = V_92 ;
else if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) )
V_100 = V_102 ;
else
return V_88 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_74 ;
V_8 -> V_60 = true ;
}
F_17 ( V_2 ) ;
if ( V_100 == V_92 )
V_2 -> V_3 = F_3 ( V_91 ) ;
else
V_2 -> V_3 = F_3 ( V_95 ) ;
F_70 ( V_100 , V_131 , V_81 -> V_39 , V_2 ,
NULL , V_130 ,
F_93 ) ;
return V_94 ;
}
static unsigned int F_98 ( const struct V_78 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
if ( V_2 -> V_8 &&
! ( V_2 -> V_8 -> V_51 & V_63 ) ) {
return V_132 ;
}
return V_88 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
F_18 ( V_2 , V_6 ) ;
V_8 -> V_51 &= ~ V_52 ;
F_100 ( sizeof( V_8 -> V_50 ) != ( V_6 - V_49 ) ) ;
F_84 ( V_2 , - ( V_6 - V_49 ) ,
V_8 -> V_50 ,
V_6 - V_49 ) ;
V_2 -> V_10 = V_8 -> V_48 ;
V_8 -> V_103 = NULL ;
F_37 ( NULL , V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 && ( V_2 -> V_8 -> V_51 & V_52 ) ) {
F_99 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_102 ( void )
{
}
static
int F_103 ( struct V_133 * V_134 , int V_135 ,
void T_5 * V_136 , T_6 * V_137 , T_7 * V_138 )
{
int V_45 ;
V_45 = F_104 ( V_134 , V_135 , V_136 , V_137 , V_138 ) ;
if ( V_135 && * ( int * ) ( V_134 -> V_112 ) )
* ( int * ) ( V_134 -> V_112 ) = 1 ;
return V_45 ;
}
static int T_8 F_105 ( void )
{
int V_45 ;
V_45 = F_106 ( V_139 , F_107 ( V_139 ) ) ;
if ( V_45 < 0 )
return V_45 ;
#ifdef F_108
V_140 = F_109 ( & V_141 , L_1 , V_142 ) ;
if ( V_140 == NULL ) {
F_110 ( V_143
L_2 ) ;
F_111 ( V_139 , F_107 ( V_139 ) ) ;
return - V_144 ;
}
#endif
F_112 ( V_145 , & V_146 ) ;
F_110 ( V_147 L_3 ) ;
return 0 ;
}
static void T_9 F_113 ( void )
{
F_112 ( V_145 , NULL ) ;
F_111 ( V_139 , F_107 ( V_139 ) ) ;
#ifdef F_108
F_114 ( V_140 ) ;
#endif
}
