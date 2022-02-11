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
static int F_21 ( struct V_22 * V_22 , struct V_1 * V_2 )
{
const struct V_23 * V_24 ;
T_2 V_20 ;
if ( ! F_22 ( V_2 , sizeof( struct V_23 ) ) )
goto V_25;
V_24 = F_23 ( V_2 ) ;
if ( V_24 -> V_26 < 5 || V_24 -> V_27 != 4 )
goto V_25;
if ( ! F_22 ( V_2 , V_24 -> V_26 * 4 ) )
goto V_25;
V_24 = F_23 ( V_2 ) ;
if ( F_24 ( F_25 ( ( V_28 * ) V_24 , V_24 -> V_26 ) ) )
goto V_25;
V_20 = F_26 ( V_24 -> V_29 ) ;
if ( V_2 -> V_20 < V_20 ) {
F_27 ( V_22 , V_30 ) ;
goto V_31;
} else if ( V_20 < ( V_24 -> V_26 * 4 ) )
goto V_25;
if ( F_28 ( V_2 , V_20 ) ) {
F_27 ( V_22 , V_32 ) ;
goto V_31;
}
memset ( F_29 ( V_2 ) , 0 , sizeof( struct V_33 ) ) ;
return 0 ;
V_25:
F_27 ( V_22 , V_34 ) ;
V_31:
return - 1 ;
}
void F_30 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_35 ) {
case V_36 :
V_2 -> V_3 = F_3 ( V_4 ) ;
break;
case V_37 :
V_2 -> V_3 = F_3 ( V_18 ) ;
break;
case V_38 :
break;
}
}
int F_31 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_2 -> V_10 = F_9 ( V_2 -> V_10 ) ;
if ( ! V_2 -> V_10 )
goto V_45;
V_44 = F_32 ( V_2 ) ;
V_42 = F_33 ( V_44 , V_2 ) ;
if ( V_42 ) {
struct V_14 * V_8 = F_34 ( V_2 ) ;
int V_46 ;
if ( V_42 -> V_47 . V_48 ) {
F_35 ( & V_42 -> V_47 , V_2 ) ;
V_2 -> V_10 = V_8 -> V_49 ;
V_46 = F_36 ( V_22 , V_40 , V_2 ) ;
} else {
F_37 ( V_2 ,
- ( V_6 - V_50 ) ,
V_8 -> V_51 ,
V_6 - V_50 ) ;
V_8 -> V_52 = 1 ;
V_46 = V_42 -> V_53 ( V_42 , V_2 ) ;
}
F_38 ( V_42 ) ;
return V_46 ;
}
V_45:
F_39 ( V_2 ) ;
return 0 ;
}
static inline bool
F_40 ( const struct V_1 * V_2 ,
const struct V_14 * V_8 )
{
return F_23 ( V_2 ) -> V_54 != V_8 -> V_55 ;
}
static int F_41 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_23 * V_24 = F_23 ( V_2 ) ;
struct V_14 * V_8 = F_34 ( V_2 ) ;
struct V_56 * V_57 ;
int V_58 ;
V_8 -> V_59 = F_29 ( V_2 ) -> V_59 ;
if ( V_8 -> V_60 ) {
V_2 -> V_61 = V_62 ;
V_8 -> V_60 = false ;
}
V_8 -> V_63 = 0 ;
if ( F_40 ( V_2 , V_8 ) ) {
if ( ( V_58 = F_42 ( V_2 , V_24 -> V_54 , V_24 -> V_64 , V_24 -> V_65 , V_10 ) ) ) {
struct V_66 * V_67 = F_43 ( V_10 ) ;
if ( V_58 != - V_68 || ! V_67 || F_44 ( V_67 ) )
goto V_45;
V_57 = F_45 ( V_22 , V_24 -> V_54 , 0 ,
F_46 ( V_24 -> V_65 ) , 0 ) ;
if ( ! F_47 ( V_57 ) ) {
if ( V_57 -> V_44 . V_10 == V_10 ) {
F_48 ( V_2 , & V_57 -> V_44 ) ;
goto V_52;
}
F_49 ( V_57 ) ;
}
V_45:
F_39 ( V_2 ) ;
return 0 ;
} else {
if ( F_32 ( V_2 ) -> V_10 == V_10 ) {
V_52:
V_2 -> V_10 = V_8 -> V_49 ;
F_30 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_69 ,
V_70 ,
V_22 , V_40 , V_2 , V_2 -> V_10 , NULL ,
F_31 ,
1 ) ;
return 0 ;
}
F_52 ( F_53 ( V_2 ) -> V_71 , V_10 -> V_72 ) ;
V_2 -> V_61 = V_73 ;
}
} else {
V_57 = F_54 ( V_8 -> V_49 ) ;
if ( ! V_57 ) {
F_39 ( V_2 ) ;
return 0 ;
}
F_55 ( V_2 , & V_57 -> V_44 ) ;
}
V_2 -> V_10 = V_8 -> V_49 ;
F_30 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( V_69 , V_70 , V_22 , V_40 , V_2 ,
V_2 -> V_10 , NULL ,
F_36 , 1 ) ;
return 0 ;
}
static struct V_9 * F_56 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_9 * V_74 , * V_13 ;
V_13 = F_9 ( V_10 ) ;
if ( V_75 == 0 || ! F_2 ( V_2 ) )
return V_13 ;
V_74 = F_57 ( V_13 , V_2 -> F_1 ,
F_58 ( V_2 ) & V_76 ) ;
return V_74 ? V_74 : V_13 ;
}
struct V_9 * F_59 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_34 ( V_2 ) ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_73 ;
V_8 -> V_60 = true ;
}
V_8 -> V_63 = 1 ;
V_8 -> V_49 = V_2 -> V_10 ;
V_2 -> V_10 = F_56 ( V_2 , V_2 -> V_10 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_8 -> V_35 = V_36 ;
else if ( V_2 -> V_3 == F_3 ( V_18 ) )
V_8 -> V_35 = V_37 ;
F_60 ( V_2 ) ;
return V_2 -> V_10 ;
}
static unsigned int F_61 ( void * V_77 ,
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
if ( F_62 ( V_2 ) || F_63 ( V_2 ) || F_64 ( V_2 ) ) {
if ( ! V_84 && ! V_13 -> V_85 )
return V_86 ;
F_19 ( V_2 ) ;
return F_65 ( V_77 , V_2 , V_79 ) ;
}
if ( ! V_87 && ! V_13 -> V_88 )
return V_86 ;
if ( ! F_66 ( V_2 ) && ! F_67 ( V_2 ) && ! F_68 ( V_2 ) )
return V_86 ;
F_19 ( V_2 ) ;
if ( F_21 ( V_79 -> V_22 , V_2 ) )
return V_82 ;
F_8 ( V_2 -> V_8 ) ;
if ( ! F_13 ( V_2 ) )
return V_82 ;
if ( ! F_59 ( V_2 ) )
return V_82 ;
V_8 = F_34 ( V_2 ) ;
V_8 -> V_55 = F_23 ( V_2 ) -> V_54 ;
V_2 -> V_3 = F_3 ( V_89 ) ;
F_69 ( V_90 , V_91 , V_79 -> V_22 , V_79 -> V_40 , V_2 ,
V_2 -> V_10 , NULL ,
F_41 ) ;
return V_92 ;
}
static unsigned int F_70 ( void * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
F_71 ( V_2 ) ;
return V_86 ;
}
static int F_72 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_14 * V_8 = F_34 ( V_2 ) ;
struct V_9 * V_83 ;
if ( ! F_73 ( V_2 ) && ! F_74 ( V_2 ) ) {
if ( V_2 -> V_3 == F_3 ( V_89 ) )
V_8 -> V_59 = F_29 ( V_2 ) -> V_59 ;
if ( V_2 -> V_3 == F_3 ( V_93 ) )
V_8 -> V_59 = F_75 ( V_2 ) -> V_59 ;
V_83 = V_8 -> V_49 ;
if ( V_8 -> V_60 ) {
V_2 -> V_61 = V_62 ;
V_8 -> V_60 = false ;
}
F_30 ( V_2 ) ;
} else {
V_83 = * ( (struct V_9 * * ) ( V_2 -> V_94 ) ) ;
}
F_50 ( V_2 ) ;
F_51 ( V_69 , V_95 , V_22 , V_40 , V_2 ,
V_83 , V_2 -> V_10 , V_96 , 1 ) ;
return 0 ;
}
static unsigned int F_76 ( void * V_77 ,
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
V_8 = F_34 ( V_2 ) ;
if ( ! V_8 )
return V_82 ;
V_97 = F_9 ( V_79 -> V_99 ) ;
if ( ! V_97 )
return V_82 ;
if ( F_66 ( V_2 ) || F_67 ( V_2 ) || F_68 ( V_2 ) )
V_98 = V_90 ;
else if ( F_62 ( V_2 ) || F_63 ( V_2 ) || F_64 ( V_2 ) )
V_98 = V_100 ;
else
return V_86 ;
F_17 ( V_2 ) ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_73 ;
V_8 -> V_60 = true ;
}
if ( V_98 == V_90 ) {
if ( F_21 ( V_79 -> V_22 , V_2 ) )
return V_82 ;
F_29 ( V_2 ) -> V_59 = V_8 -> V_59 ;
}
if ( V_98 == V_100 ) {
if ( F_77 ( V_79 -> V_22 , V_2 ) )
return V_82 ;
F_75 ( V_2 ) -> V_59 = V_8 -> V_59 ;
}
V_8 -> V_101 = V_2 -> V_10 ;
if ( V_98 == V_90 )
V_2 -> V_3 = F_3 ( V_89 ) ;
else
V_2 -> V_3 = F_3 ( V_93 ) ;
F_69 ( V_98 , V_102 , V_79 -> V_22 , NULL , V_2 ,
F_56 ( V_2 , V_79 -> V_83 ) ,
V_97 , F_72 ) ;
return V_92 ;
}
static unsigned int F_78 ( void * V_77 ,
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
if ( ! F_73 ( V_2 ) ) {
if ( ! F_74 ( V_2 ) )
return V_86 ;
F_17 ( V_2 ) ;
}
if ( F_79 ( V_2 ) -> V_106 != 4 ) {
if ( F_74 ( V_2 ) )
F_50 ( V_2 ) ;
return V_86 ;
}
* V_103 = V_79 -> V_83 ;
F_69 ( V_107 , V_108 , V_79 -> V_22 , V_79 -> V_40 , V_2 ,
V_79 -> V_83 , V_79 -> V_99 , F_72 ) ;
return V_92 ;
}
static int F_80 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_109 * V_110 ;
int V_58 ;
V_110 = F_81 ( & V_111 ) ;
V_58 = F_82 ( V_2 , V_110 -> V_112 ) ;
if ( V_58 ) {
F_39 ( V_2 ) ;
return 0 ;
}
if ( V_110 -> V_113 ) {
V_2 -> V_113 = V_110 -> V_113 ;
V_2 -> F_1 = V_110 -> F_1 ;
}
F_83 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 , V_110 -> V_112 ) ;
F_84 ( V_2 , V_110 -> V_115 ) ;
F_7 ( V_2 ) ;
return F_85 ( V_22 , V_40 , V_2 ) ;
}
static int
F_86 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 ,
int (* V_53)( struct V_22 * , struct V_39 * , struct V_1 * ) )
{
unsigned int V_116 = F_87 ( V_2 ) ;
struct V_23 * V_24 = F_23 ( V_2 ) ;
if ( F_24 ( ( ( V_24 -> V_117 & F_3 ( V_118 ) ) && ! V_2 -> V_119 ) ||
( F_29 ( V_2 ) -> V_59 &&
F_29 ( V_2 ) -> V_59 > V_116 ) ) ) {
F_88 ( V_22 , V_120 ) ;
F_39 ( V_2 ) ;
return - V_121 ;
}
return F_89 ( V_22 , V_40 , V_2 , V_53 ) ;
}
static unsigned int F_90 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_8 -> V_35 == V_37 )
return V_19 ;
return 0 ;
}
static int F_91 ( struct V_22 * V_22 , struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_14 * V_8 ;
unsigned int V_122 ;
V_122 = F_90 ( V_2 ) ;
if ( F_92 ( V_2 ) || V_2 -> V_20 + V_122 <= V_2 -> V_10 -> V_116 ) {
F_7 ( V_2 ) ;
return F_85 ( V_22 , V_40 , V_2 ) ;
}
V_8 = F_34 ( V_2 ) ;
if ( F_93 ( V_123 ) &&
V_2 -> V_3 == F_3 ( V_89 ) ) {
struct V_109 * V_110 ;
if ( F_21 ( V_22 , V_2 ) )
goto V_31;
F_29 ( V_2 ) -> V_59 = V_8 -> V_59 ;
F_30 ( V_2 ) ;
V_110 = F_81 ( & V_111 ) ;
V_110 -> V_113 = V_2 -> V_113 ;
V_110 -> F_1 = V_2 -> F_1 ;
V_110 -> V_115 = F_15 ( V_2 ) ;
V_110 -> V_112 = V_6 + V_110 -> V_115 ;
F_37 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 ,
V_110 -> V_112 ) ;
return F_86 ( V_22 , V_40 , V_2 , F_80 ) ;
}
if ( F_93 ( V_124 ) &&
V_2 -> V_3 == F_3 ( V_93 ) ) {
const struct V_125 * V_126 = F_94 () ;
struct V_109 * V_110 ;
if ( F_77 ( V_22 , V_2 ) )
goto V_31;
F_75 ( V_2 ) -> V_59 = V_8 -> V_59 ;
F_30 ( V_2 ) ;
V_110 = F_81 ( & V_111 ) ;
V_110 -> V_115 = F_15 ( V_2 ) ;
V_110 -> V_112 = V_6 + V_110 -> V_115 ;
F_37 ( V_2 , - V_110 -> V_112 , V_110 -> V_114 ,
V_110 -> V_112 ) ;
if ( V_126 )
return V_126 -> V_127 ( V_22 , V_40 , V_2 , F_80 ) ;
F_39 ( V_2 ) ;
return - V_121 ;
}
F_7 ( V_2 ) ;
return F_85 ( V_22 , V_40 , V_2 ) ;
V_31:
F_39 ( V_2 ) ;
return 0 ;
}
static unsigned int F_95 ( void * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
struct V_14 * V_8 = F_34 ( V_2 ) ;
struct V_9 * V_128 = F_9 ( V_2 -> V_10 ) ;
T_4 V_98 ;
if ( ! V_8 || ! V_8 -> V_101 )
return V_86 ;
if ( ! V_128 )
return V_82 ;
if ( F_66 ( V_2 ) || F_67 ( V_2 ) || F_68 ( V_2 ) )
V_98 = V_90 ;
else if ( F_62 ( V_2 ) || F_63 ( V_2 ) || F_64 ( V_2 ) )
V_98 = V_100 ;
else
return V_86 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_73 ;
V_8 -> V_60 = true ;
}
F_17 ( V_2 ) ;
if ( V_98 == V_90 )
V_2 -> V_3 = F_3 ( V_89 ) ;
else
V_2 -> V_3 = F_3 ( V_93 ) ;
F_69 ( V_98 , V_129 , V_79 -> V_22 , V_79 -> V_40 , V_2 ,
NULL , V_128 ,
F_91 ) ;
return V_92 ;
}
static unsigned int F_96 ( void * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
if ( V_2 -> V_8 && ! V_2 -> V_8 -> V_63 )
return V_130 ;
return V_86 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_14 * V_8 = F_34 ( V_2 ) ;
F_18 ( V_2 , V_6 ) ;
V_8 -> V_52 = 0 ;
F_98 ( sizeof( V_8 -> V_51 ) != ( V_6 - V_50 ) ) ;
F_83 ( V_2 , - ( V_6 - V_50 ) ,
V_8 -> V_51 ,
V_6 - V_50 ) ;
V_2 -> V_10 = V_8 -> V_49 ;
V_8 -> V_101 = NULL ;
F_36 ( F_99 ( V_2 -> V_10 ) , NULL , V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 && V_2 -> V_8 -> V_52 ) {
F_97 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_101 ( void )
{
}
static int F_102 ( struct V_131 * V_132 , unsigned long V_133 ,
void * V_134 )
{
struct V_9 * V_10 = F_103 ( V_134 ) ;
struct V_135 * V_136 ;
struct V_22 * V_22 ;
int V_46 ;
if ( V_133 != V_137 || ! ( V_10 -> V_138 & V_139 ) )
return V_140 ;
F_104 () ;
V_22 = F_99 ( V_10 ) ;
V_136 = F_105 ( V_22 , V_141 ) ;
if ( V_136 -> V_142 )
return V_143 ;
V_46 = F_106 ( V_22 , V_144 , F_107 ( V_144 ) ) ;
if ( V_46 )
return V_145 ;
V_136 -> V_142 = true ;
return V_143 ;
}
static void T_5 F_108 ( struct V_22 * V_22 )
{
struct V_135 * V_136 = F_105 ( V_22 , V_141 ) ;
if ( ! V_136 -> V_142 )
return;
F_109 ( V_22 , V_144 , F_107 ( V_144 ) ) ;
V_136 -> V_142 = false ;
}
static
int F_110 ( struct V_146 * V_147 , int V_148 ,
void T_6 * V_149 , T_7 * V_150 , T_8 * V_151 )
{
int V_46 ;
V_46 = F_111 ( V_147 , V_148 , V_149 , V_150 , V_151 ) ;
if ( V_148 && * ( int * ) ( V_147 -> V_110 ) )
* ( int * ) ( V_147 -> V_110 ) = 1 ;
return V_46 ;
}
static int T_9 F_112 ( void )
{
int V_46 ;
V_46 = F_113 ( & V_152 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_114 ( & V_153 ) ;
if ( V_46 < 0 ) {
F_115 ( & V_152 ) ;
return V_46 ;
}
#ifdef F_116
V_154 = F_117 ( & V_155 , L_1 , V_156 ) ;
if ( V_154 == NULL ) {
F_118 ( V_157
L_2 ) ;
F_119 ( & V_153 ) ;
F_115 ( & V_152 ) ;
return - V_158 ;
}
#endif
F_120 ( V_159 , & V_160 ) ;
F_118 ( V_161 L_3 ) ;
return 0 ;
}
static void T_10 F_121 ( void )
{
F_120 ( V_159 , NULL ) ;
F_119 ( & V_153 ) ;
F_115 ( & V_152 ) ;
#ifdef F_116
F_122 ( V_154 ) ;
#endif
}
