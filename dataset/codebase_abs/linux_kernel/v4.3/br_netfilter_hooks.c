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
V_8 -> V_51 = 1 ;
V_45 = V_41 -> V_52 ( V_41 , V_2 ) ;
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
return F_23 ( V_2 ) -> V_53 != V_8 -> V_54 ;
}
static int F_42 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_55 * V_56 ;
int V_57 ;
V_8 -> V_58 = F_30 ( V_2 ) -> V_58 ;
if ( V_8 -> V_59 ) {
V_2 -> V_60 = V_61 ;
V_8 -> V_59 = false ;
}
V_8 -> V_62 = 0 ;
if ( F_41 ( V_2 , V_8 ) ) {
if ( ( V_57 = F_43 ( V_2 , V_23 -> V_53 , V_23 -> V_63 , V_23 -> V_64 , V_10 ) ) ) {
struct V_65 * V_66 = F_44 ( V_10 ) ;
if ( V_57 != - V_67 || ! V_66 || F_45 ( V_66 ) )
goto V_44;
V_56 = F_46 ( F_28 ( V_10 ) , V_23 -> V_53 , 0 ,
F_47 ( V_23 -> V_64 ) , 0 ) ;
if ( ! F_48 ( V_56 ) ) {
if ( V_56 -> V_43 . V_10 == V_10 ) {
F_49 ( V_2 , & V_56 -> V_43 ) ;
goto V_51;
}
F_50 ( V_56 ) ;
}
V_44:
F_40 ( V_2 ) ;
return 0 ;
} else {
if ( F_33 ( V_2 ) -> V_10 == V_10 ) {
V_51:
V_2 -> V_10 = V_8 -> V_48 ;
F_31 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_68 ,
V_69 ,
V_39 , V_2 , V_2 -> V_10 , NULL ,
F_32 ,
1 ) ;
return 0 ;
}
F_53 ( F_54 ( V_2 ) -> V_70 , V_10 -> V_71 ) ;
V_2 -> V_60 = V_72 ;
}
} else {
V_56 = F_55 ( V_8 -> V_48 ) ;
if ( ! V_56 ) {
F_40 ( V_2 ) ;
return 0 ;
}
F_56 ( V_2 , & V_56 -> V_43 ) ;
}
V_2 -> V_10 = V_8 -> V_48 ;
F_31 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_68 , V_69 , V_39 , V_2 ,
V_2 -> V_10 , NULL ,
F_37 , 1 ) ;
return 0 ;
}
static struct V_9 * F_57 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_9 * V_73 , * V_13 ;
V_13 = F_9 ( V_10 ) ;
if ( V_74 == 0 || ! F_2 ( V_2 ) )
return V_13 ;
V_73 = F_58 ( V_13 , V_2 -> F_1 ,
F_59 ( V_2 ) & V_75 ) ;
return V_73 ? V_73 : V_13 ;
}
struct V_9 * F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_2 -> V_60 = V_72 ;
V_8 -> V_59 = true ;
}
V_8 -> V_62 = 1 ;
V_8 -> V_48 = V_2 -> V_10 ;
V_2 -> V_10 = F_57 ( V_2 , V_2 -> V_10 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_8 -> V_34 = V_35 ;
else if ( V_2 -> V_3 == F_3 ( V_18 ) )
V_8 -> V_34 = V_36 ;
F_61 ( V_2 ) ;
return V_2 -> V_10 ;
}
static unsigned int F_62 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_14 * V_8 ;
struct V_11 * V_80 ;
struct V_81 * V_13 ;
T_3 V_20 = F_15 ( V_2 ) ;
if ( F_24 ( ! F_22 ( V_2 , V_20 ) ) )
return V_82 ;
V_80 = F_10 ( V_79 -> V_83 ) ;
if ( V_80 == NULL )
return V_82 ;
V_13 = V_80 -> V_13 ;
if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) ) {
if ( ! V_84 && ! V_13 -> V_85 )
return V_86 ;
F_19 ( V_2 ) ;
return F_66 ( V_77 , V_2 , V_79 ) ;
}
if ( ! V_87 && ! V_13 -> V_88 )
return V_86 ;
if ( ! F_67 ( V_2 ) && ! F_68 ( V_2 ) && ! F_69 ( V_2 ) )
return V_86 ;
F_19 ( V_2 ) ;
if ( F_21 ( V_2 ) )
return V_82 ;
F_8 ( V_2 -> V_8 ) ;
if ( ! F_13 ( V_2 ) )
return V_82 ;
if ( ! F_60 ( V_2 ) )
return V_82 ;
V_8 = F_35 ( V_2 ) ;
V_8 -> V_54 = F_23 ( V_2 ) -> V_53 ;
V_2 -> V_3 = F_3 ( V_89 ) ;
F_70 ( V_90 , V_91 , V_79 -> V_39 , V_2 ,
V_2 -> V_10 , NULL ,
F_42 ) ;
return V_92 ;
}
static unsigned int F_71 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
F_72 ( V_2 ) ;
return V_86 ;
}
static int F_73 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_9 * V_83 ;
if ( ! F_74 ( V_2 ) && ! F_75 ( V_2 ) ) {
if ( V_2 -> V_3 == F_3 ( V_89 ) )
V_8 -> V_58 = F_30 ( V_2 ) -> V_58 ;
if ( V_2 -> V_3 == F_3 ( V_93 ) )
V_8 -> V_58 = F_76 ( V_2 ) -> V_58 ;
V_83 = V_8 -> V_48 ;
if ( V_8 -> V_59 ) {
V_2 -> V_60 = V_61 ;
V_8 -> V_59 = false ;
}
F_31 ( V_2 ) ;
} else {
V_83 = * ( (struct V_9 * * ) ( V_2 -> V_94 ) ) ;
}
F_51 ( V_2 ) ;
F_52 ( V_68 , V_95 , V_39 , V_2 ,
V_83 , V_2 -> V_10 , V_96 , 1 ) ;
return 0 ;
}
static unsigned int F_77 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_14 * V_8 ;
struct V_9 * V_97 ;
T_4 V_98 ;
if ( ! V_2 -> V_8 )
return V_86 ;
if ( ! F_11 ( V_2 ) )
return V_82 ;
V_8 = F_35 ( V_2 ) ;
if ( ! V_8 )
return V_82 ;
V_97 = F_9 ( V_79 -> V_99 ) ;
if ( ! V_97 )
return V_82 ;
if ( F_67 ( V_2 ) || F_68 ( V_2 ) || F_69 ( V_2 ) )
V_98 = V_90 ;
else if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) )
V_98 = V_100 ;
else
return V_86 ;
F_17 ( V_2 ) ;
if ( V_2 -> V_60 == V_61 ) {
V_2 -> V_60 = V_72 ;
V_8 -> V_59 = true ;
}
if ( V_98 == V_90 ) {
if ( F_21 ( V_2 ) )
return V_82 ;
F_30 ( V_2 ) -> V_58 = V_8 -> V_58 ;
}
if ( V_98 == V_100 ) {
if ( F_78 ( V_2 ) )
return V_82 ;
F_76 ( V_2 ) -> V_58 = V_8 -> V_58 ;
}
V_8 -> V_101 = V_2 -> V_10 ;
if ( V_98 == V_90 )
V_2 -> V_3 = F_3 ( V_89 ) ;
else
V_2 -> V_3 = F_3 ( V_93 ) ;
F_70 ( V_98 , V_102 , NULL , V_2 ,
F_57 ( V_2 , V_79 -> V_83 ) ,
V_97 , F_73 ) ;
return V_92 ;
}
static unsigned int F_79 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_11 * V_80 ;
struct V_81 * V_13 ;
struct V_9 * * V_103 = (struct V_9 * * ) ( V_2 -> V_94 ) ;
V_80 = F_10 ( V_79 -> V_99 ) ;
if ( V_80 == NULL )
return V_86 ;
V_13 = V_80 -> V_13 ;
if ( ! V_104 && ! V_13 -> V_105 )
return V_86 ;
if ( ! F_74 ( V_2 ) ) {
if ( ! F_75 ( V_2 ) )
return V_86 ;
F_17 ( V_2 ) ;
}
if ( F_80 ( V_2 ) -> V_106 != 4 ) {
if ( F_75 ( V_2 ) )
F_51 ( V_2 ) ;
return V_86 ;
}
* V_103 = V_79 -> V_83 ;
F_70 ( V_107 , V_108 , V_79 -> V_39 , V_2 ,
V_79 -> V_83 , V_79 -> V_99 , F_73 ) ;
return V_92 ;
}
static int F_81 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_109 * V_110 ;
int V_57 ;
V_110 = F_82 ( & V_111 ) ;
V_57 = F_83 ( V_2 , V_110 -> V_112 ) ;
if ( V_57 ) {
F_40 ( V_2 ) ;
return 0 ;
}
if ( V_110 -> V_113 ) {
V_2 -> V_113 = V_110 -> V_113 ;
V_2 -> F_1 = V_110 -> F_1 ;
}
F_84 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 , V_110 -> V_112 ) ;
F_85 ( V_2 , V_110 -> V_115 ) ;
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
}
static int F_87 ( struct V_38 * V_39 , struct V_1 * V_2 ,
int (* V_52)( struct V_38 * , struct V_1 * ) )
{
unsigned int V_116 = F_88 ( V_2 ) ;
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_55 * V_56 = F_89 ( V_2 ) ;
struct V_9 * V_10 = V_56 -> V_43 . V_10 ;
if ( F_24 ( ( ( V_23 -> V_117 & F_3 ( V_118 ) ) && ! V_2 -> V_119 ) ||
( F_30 ( V_2 ) -> V_58 &&
F_30 ( V_2 ) -> V_58 > V_116 ) ) ) {
F_90 ( F_28 ( V_10 ) , V_120 ) ;
F_40 ( V_2 ) ;
return - V_121 ;
}
return F_91 ( V_39 , V_2 , V_52 ) ;
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
unsigned int V_122 ;
V_122 = F_92 ( V_2 ) ;
if ( F_94 ( V_2 ) || V_2 -> V_20 + V_122 <= V_2 -> V_10 -> V_116 ) {
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
}
V_8 = F_35 ( V_2 ) ;
#if F_95 ( V_123 )
if ( V_2 -> V_3 == F_3 ( V_89 ) ) {
struct V_109 * V_110 ;
if ( F_21 ( V_2 ) )
goto V_30;
F_30 ( V_2 ) -> V_58 = V_8 -> V_58 ;
F_31 ( V_2 ) ;
V_110 = F_82 ( & V_111 ) ;
V_110 -> V_113 = V_2 -> V_113 ;
V_110 -> F_1 = V_2 -> F_1 ;
V_110 -> V_115 = F_15 ( V_2 ) ;
V_110 -> V_112 = V_6 + V_110 -> V_115 ;
F_38 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 ,
V_110 -> V_112 ) ;
return F_87 ( V_39 , V_2 , F_81 ) ;
}
#endif
#if F_95 ( V_124 )
if ( V_2 -> V_3 == F_3 ( V_93 ) ) {
const struct V_125 * V_126 = F_96 () ;
struct V_109 * V_110 ;
if ( F_78 ( V_2 ) )
goto V_30;
F_76 ( V_2 ) -> V_58 = V_8 -> V_58 ;
F_31 ( V_2 ) ;
V_110 = F_82 ( & V_111 ) ;
V_110 -> V_115 = F_15 ( V_2 ) ;
V_110 -> V_112 = V_6 + V_110 -> V_115 ;
F_38 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 ,
V_110 -> V_112 ) ;
if ( V_126 )
return V_126 -> V_127 ( V_39 , V_2 , F_81 ) ;
F_40 ( V_2 ) ;
return - V_121 ;
}
#endif
F_7 ( V_2 ) ;
return F_86 ( V_39 , V_2 ) ;
V_30:
F_40 ( V_2 ) ;
return 0 ;
}
static unsigned int F_97 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
struct V_9 * V_128 = F_9 ( V_2 -> V_10 ) ;
T_4 V_98 ;
if ( ! V_8 || ! V_8 -> V_101 )
return V_86 ;
if ( ! V_128 )
return V_82 ;
if ( F_67 ( V_2 ) || F_68 ( V_2 ) || F_69 ( V_2 ) )
V_98 = V_90 ;
else if ( F_63 ( V_2 ) || F_64 ( V_2 ) || F_65 ( V_2 ) )
V_98 = V_100 ;
else
return V_86 ;
if ( V_2 -> V_60 == V_61 ) {
V_2 -> V_60 = V_72 ;
V_8 -> V_59 = true ;
}
F_17 ( V_2 ) ;
if ( V_98 == V_90 )
V_2 -> V_3 = F_3 ( V_89 ) ;
else
V_2 -> V_3 = F_3 ( V_93 ) ;
F_70 ( V_98 , V_129 , V_79 -> V_39 , V_2 ,
NULL , V_128 ,
F_93 ) ;
return V_92 ;
}
static unsigned int F_98 ( const struct V_76 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
if ( V_2 -> V_8 && ! V_2 -> V_8 -> V_62 )
return V_130 ;
return V_86 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_35 ( V_2 ) ;
F_18 ( V_2 , V_6 ) ;
V_8 -> V_51 = 0 ;
F_100 ( sizeof( V_8 -> V_50 ) != ( V_6 - V_49 ) ) ;
F_84 ( V_2 , - ( V_6 - V_49 ) ,
V_8 -> V_50 ,
V_6 - V_49 ) ;
V_2 -> V_10 = V_8 -> V_48 ;
V_8 -> V_101 = NULL ;
F_37 ( NULL , V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 && V_2 -> V_8 -> V_51 ) {
F_99 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_102 ( void )
{
}
static
int F_103 ( struct V_131 * V_132 , int V_133 ,
void T_5 * V_134 , T_6 * V_135 , T_7 * V_136 )
{
int V_45 ;
V_45 = F_104 ( V_132 , V_133 , V_134 , V_135 , V_136 ) ;
if ( V_133 && * ( int * ) ( V_132 -> V_110 ) )
* ( int * ) ( V_132 -> V_110 ) = 1 ;
return V_45 ;
}
static int T_8 F_105 ( void )
{
int V_45 ;
V_45 = F_106 ( V_137 , F_107 ( V_137 ) ) ;
if ( V_45 < 0 )
return V_45 ;
#ifdef F_108
V_138 = F_109 ( & V_139 , L_1 , V_140 ) ;
if ( V_138 == NULL ) {
F_110 ( V_141
L_2 ) ;
F_111 ( V_137 , F_107 ( V_137 ) ) ;
return - V_142 ;
}
#endif
F_112 ( V_143 , & V_144 ) ;
F_110 ( V_145 L_3 ) ;
return 0 ;
}
static void T_9 F_113 ( void )
{
F_112 ( V_143 , NULL ) ;
F_111 ( V_137 , F_107 ( V_137 ) ) ;
#ifdef F_108
F_114 ( V_138 ) ;
#endif
}
