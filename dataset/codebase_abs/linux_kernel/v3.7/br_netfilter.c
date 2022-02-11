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
static void F_7 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_2 , T_2 V_12 )
{
}
static void F_8 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_2 )
{
}
static T_2 * F_9 ( struct V_8 * V_9 , unsigned long V_13 )
{
return NULL ;
}
static struct V_14 * F_10 ( const struct V_8 * V_9 ,
struct V_1 * V_2 ,
const void * V_15 )
{
return NULL ;
}
static unsigned int F_11 ( const struct V_8 * V_9 )
{
return V_9 -> V_16 -> V_12 ;
}
void F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 ;
F_13 ( & V_20 -> V_9 . V_22 , 1 ) ;
V_20 -> V_9 . V_16 = V_18 -> V_16 ;
V_20 -> V_9 . V_23 = & V_20 -> V_9 ;
F_14 ( & V_20 -> V_9 , V_24 , true ) ;
V_20 -> V_9 . V_25 = V_26 | V_27 | V_28 ;
V_20 -> V_9 . V_29 = & V_30 ;
}
static inline struct V_19 * F_15 ( const struct V_31 * V_16 )
{
struct V_32 * V_33 ;
V_33 = F_16 ( V_16 ) ;
return V_33 ? & V_33 -> V_18 -> V_21 : NULL ;
}
static inline struct V_31 * F_17 ( const struct V_31 * V_16 )
{
struct V_32 * V_33 ;
V_33 = F_16 ( V_16 ) ;
return V_33 ? V_33 -> V_18 -> V_16 : NULL ;
}
static inline struct V_34 * F_18 ( struct V_1 * V_2 )
{
V_2 -> V_35 = F_19 ( sizeof( struct V_34 ) , V_36 ) ;
if ( F_20 ( V_2 -> V_35 ) )
F_13 ( & ( V_2 -> V_35 -> V_37 ) , 1 ) ;
return V_2 -> V_35 ;
}
static inline struct V_34 * F_21 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
if ( F_22 ( & V_35 -> V_37 ) > 1 ) {
struct V_34 * V_38 = F_18 ( V_2 ) ;
if ( V_38 ) {
memcpy ( V_38 , V_35 , sizeof( struct V_34 ) ) ;
F_13 ( & V_38 -> V_37 , 1 ) ;
}
F_23 ( V_35 ) ;
V_35 = V_38 ;
}
return V_35 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
unsigned int V_39 = F_25 ( V_2 ) ;
F_26 ( V_2 , V_39 ) ;
V_2 -> V_40 -= V_39 ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
unsigned int V_39 = F_25 ( V_2 ) ;
F_28 ( V_2 , V_39 ) ;
V_2 -> V_40 += V_39 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
unsigned int V_39 = F_25 ( V_2 ) ;
F_30 ( V_2 , V_39 ) ;
V_2 -> V_40 += V_39 ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
int V_41 = V_6 + F_25 ( V_2 ) ;
F_32 ( V_2 , - V_41 ,
V_2 -> V_35 -> V_42 , V_41 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 -> V_43 & V_44 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_35 -> V_43 & V_45 )
V_2 -> V_3 = F_3 ( V_46 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
const struct V_49 * V_50 ;
struct V_31 * V_16 = V_2 -> V_16 ;
T_2 V_39 ;
if ( ! F_35 ( V_2 , sizeof( struct V_49 ) ) )
goto V_51;
V_50 = F_36 ( V_2 ) ;
V_48 = & ( F_37 ( V_2 ) -> V_48 ) ;
if ( V_50 -> V_52 < 5 || V_50 -> V_53 != 4 )
goto V_51;
if ( ! F_35 ( V_2 , V_50 -> V_52 * 4 ) )
goto V_51;
V_50 = F_36 ( V_2 ) ;
if ( F_38 ( F_39 ( ( V_54 * ) V_50 , V_50 -> V_52 ) ) )
goto V_51;
V_39 = F_40 ( V_50 -> V_55 ) ;
if ( V_2 -> V_39 < V_39 ) {
F_41 ( F_42 ( V_16 ) , V_56 ) ;
goto V_57;
} else if ( V_39 < ( V_50 -> V_52 * 4 ) )
goto V_51;
if ( F_43 ( V_2 , V_39 ) ) {
F_41 ( F_42 ( V_16 ) , V_58 ) ;
goto V_57;
}
memset ( F_37 ( V_2 ) , 0 , sizeof( struct V_59 ) ) ;
if ( V_50 -> V_52 == 5 )
return 0 ;
V_48 -> V_60 = V_50 -> V_52 * 4 - sizeof( struct V_49 ) ;
if ( F_44 ( F_42 ( V_16 ) , V_48 , V_2 ) )
goto V_51;
if ( F_38 ( V_48 -> V_61 ) ) {
struct V_62 * V_63 = F_45 ( V_16 ) ;
if ( V_63 && ! F_46 ( V_63 ) )
goto V_57;
if ( F_47 ( V_2 ) )
goto V_57;
}
return 0 ;
V_51:
F_41 ( F_42 ( V_16 ) , V_64 ) ;
V_57:
return - 1 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_65 ;
unsigned int V_41 ;
F_33 ( V_2 ) ;
V_41 = V_6 + F_25 ( V_2 ) ;
V_65 = F_49 ( V_2 , V_41 ) ;
if ( V_65 )
return V_65 ;
F_50 ( V_2 , - V_41 ,
V_2 -> V_35 -> V_42 , V_41 ) ;
F_51 ( V_2 , F_25 ( V_2 ) ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_19 * V_20 ;
if ( V_35 -> V_43 & V_66 ) {
V_2 -> V_67 = V_68 ;
V_35 -> V_43 ^= V_66 ;
}
V_35 -> V_43 ^= V_69 ;
V_20 = F_15 ( V_35 -> V_70 ) ;
if ( ! V_20 ) {
F_53 ( V_2 ) ;
return 0 ;
}
F_54 ( V_2 , & V_20 -> V_9 ) ;
V_2 -> V_16 = V_35 -> V_70 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_71 , V_72 , V_2 , V_2 -> V_16 , NULL ,
V_73 , 1 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_14 * V_74 ;
struct V_8 * V_9 ;
V_2 -> V_16 = F_17 ( V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_75;
V_9 = F_57 ( V_2 ) ;
V_74 = F_58 ( V_9 , V_2 ) ;
if ( V_74 ) {
int V_76 ;
if ( V_74 -> V_77 . V_78 ) {
F_59 ( & V_74 -> V_77 , V_2 ) ;
V_2 -> V_16 = V_35 -> V_70 ;
V_76 = V_73 ( V_2 ) ;
} else {
F_32 ( V_2 ,
- ( V_6 - V_79 ) ,
V_2 -> V_35 -> V_42 ,
V_6 - V_79 ) ;
V_35 -> V_43 |= V_80 ;
V_76 = V_74 -> V_81 ( V_74 , V_2 ) ;
}
F_60 ( V_74 ) ;
return V_76 ;
}
V_75:
F_53 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_31 * V_16 = V_2 -> V_16 ;
struct V_49 * V_50 = F_36 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_19 * V_20 ;
int V_65 ;
if ( V_35 -> V_43 & V_66 ) {
V_2 -> V_67 = V_68 ;
V_35 -> V_43 ^= V_66 ;
}
V_35 -> V_43 ^= V_69 ;
if ( F_62 ( V_2 ) ) {
if ( ( V_65 = F_63 ( V_2 , V_50 -> V_15 , V_50 -> V_82 , V_50 -> V_83 , V_16 ) ) ) {
struct V_62 * V_63 = F_45 ( V_16 ) ;
if ( V_65 != - V_84 || ! V_63 || F_64 ( V_63 ) )
goto V_75;
V_20 = F_65 ( F_42 ( V_16 ) , V_50 -> V_15 , 0 ,
F_66 ( V_50 -> V_83 ) , 0 ) ;
if ( ! F_67 ( V_20 ) ) {
if ( V_20 -> V_9 . V_16 == V_16 ) {
F_68 ( V_2 , & V_20 -> V_9 ) ;
goto V_85;
}
F_69 ( V_20 ) ;
}
V_75:
F_53 ( V_2 ) ;
return 0 ;
} else {
if ( F_57 ( V_2 ) -> V_16 == V_16 ) {
V_85:
V_2 -> V_16 = V_35 -> V_70 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_71 ,
V_72 ,
V_2 , V_2 -> V_16 , NULL ,
F_56 ,
1 ) ;
return 0 ;
}
memcpy ( F_70 ( V_2 ) -> V_86 , V_16 -> V_87 , V_79 ) ;
V_2 -> V_67 = V_88 ;
}
} else {
V_20 = F_15 ( V_35 -> V_70 ) ;
if ( ! V_20 ) {
F_53 ( V_2 ) ;
return 0 ;
}
F_54 ( V_2 , & V_20 -> V_9 ) ;
}
V_2 -> V_16 = V_35 -> V_70 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_71 , V_72 , V_2 , V_2 -> V_16 , NULL ,
V_73 , 1 ) ;
return 0 ;
}
static struct V_31 * F_71 ( struct V_1 * V_2 , const struct V_31 * V_16 )
{
struct V_31 * V_89 , * V_18 ;
V_18 = F_17 ( V_16 ) ;
if ( V_90 == 0 || ! F_2 ( V_2 ) )
return V_18 ;
V_89 = F_72 ( V_18 , F_73 ( V_2 ) & V_91 ) ;
return V_89 ? V_89 : V_18 ;
}
static struct V_31 * F_74 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
if ( V_2 -> V_67 == V_68 ) {
V_2 -> V_67 = V_88 ;
V_35 -> V_43 |= V_66 ;
}
V_35 -> V_43 |= V_69 ;
V_35 -> V_70 = V_2 -> V_16 ;
V_2 -> V_16 = F_71 ( V_2 , V_2 -> V_16 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_35 -> V_43 |= V_44 ;
else if ( V_2 -> V_3 == F_3 ( V_46 ) )
V_35 -> V_43 |= V_45 ;
return V_2 -> V_16 ;
}
static int F_75 ( struct V_1 * V_2 )
{
unsigned char * V_92 = ( V_54 * ) ( F_76 ( V_2 ) + 1 ) ;
T_2 V_93 ;
const unsigned char * V_94 = F_77 ( V_2 ) ;
int V_95 = V_92 - V_94 ;
int V_39 = ( V_92 [ 1 ] + 1 ) << 3 ;
if ( ( V_92 + V_39 ) - V_2 -> V_42 > F_78 ( V_2 ) )
goto V_96;
V_95 += 2 ;
V_39 -= 2 ;
while ( V_39 > 0 ) {
int V_60 = V_94 [ V_95 + 1 ] + 2 ;
switch ( V_94 [ V_95 ] ) {
case V_97 :
V_60 = 1 ;
break;
case V_98 :
break;
case V_99 :
if ( V_94 [ V_95 + 1 ] != 4 || ( V_95 & 3 ) != 2 )
goto V_96;
V_93 = F_79 ( * ( V_100 * ) ( V_94 + V_95 + 2 ) ) ;
if ( V_93 <= V_101 ||
F_76 ( V_2 ) -> V_102 )
goto V_96;
if ( V_93 > V_2 -> V_39 - sizeof( struct V_103 ) )
goto V_96;
if ( F_43 ( V_2 ,
V_93 + sizeof( struct V_103 ) ) )
goto V_96;
V_94 = F_77 ( V_2 ) ;
break;
default:
if ( V_60 > V_39 )
goto V_96;
break;
}
V_95 += V_60 ;
V_39 -= V_60 ;
}
if ( V_39 == 0 )
return 0 ;
V_96:
return - 1 ;
}
static unsigned int F_80 ( unsigned int V_104 ,
struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
const struct V_103 * V_107 ;
T_2 V_93 ;
if ( V_2 -> V_39 < sizeof( struct V_103 ) )
return V_108 ;
if ( ! F_35 ( V_2 , sizeof( struct V_103 ) ) )
return V_108 ;
V_107 = F_76 ( V_2 ) ;
if ( V_107 -> V_53 != 6 )
return V_108 ;
V_93 = F_40 ( V_107 -> V_102 ) ;
if ( V_93 || V_107 -> V_109 != V_110 ) {
if ( V_93 + sizeof( struct V_103 ) > V_2 -> V_39 )
return V_108 ;
if ( F_43 ( V_2 , V_93 + sizeof( struct V_103 ) ) )
return V_108 ;
}
if ( V_107 -> V_109 == V_110 && F_75 ( V_2 ) )
return V_108 ;
F_23 ( V_2 -> V_35 ) ;
if ( ! F_18 ( V_2 ) )
return V_108 ;
if ( ! F_74 ( V_2 ) )
return V_108 ;
V_2 -> V_3 = F_3 ( V_111 ) ;
F_82 ( V_112 , V_113 , V_2 , V_2 -> V_16 , NULL ,
F_52 ) ;
return V_114 ;
}
static unsigned int F_83 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
struct V_32 * V_115 ;
struct V_17 * V_18 ;
T_3 V_39 = F_25 ( V_2 ) ;
if ( F_38 ( ! F_35 ( V_2 , V_39 ) ) )
return V_108 ;
V_115 = F_16 ( V_105 ) ;
if ( V_115 == NULL )
return V_108 ;
V_18 = V_115 -> V_18 ;
if ( F_84 ( V_2 ) || F_85 ( V_2 ) || F_86 ( V_2 ) ) {
if ( ! V_116 && ! V_18 -> V_117 )
return V_118 ;
F_29 ( V_2 ) ;
return F_80 ( V_104 , V_2 , V_105 , V_106 , F_81 ) ;
}
if ( ! V_119 && ! V_18 -> V_120 )
return V_118 ;
if ( ! F_87 ( V_2 ) && ! F_88 ( V_2 ) && ! F_89 ( V_2 ) )
return V_118 ;
F_29 ( V_2 ) ;
if ( F_34 ( V_2 ) )
return V_108 ;
F_23 ( V_2 -> V_35 ) ;
if ( ! F_18 ( V_2 ) )
return V_108 ;
if ( ! F_74 ( V_2 ) )
return V_108 ;
F_90 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_121 ) ;
F_82 ( V_122 , V_113 , V_2 , V_2 -> V_16 , NULL ,
F_61 ) ;
return V_114 ;
}
static unsigned int F_91 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
F_92 ( V_2 ) ;
return V_118 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_31 * V_105 ;
if ( ! F_94 ( V_2 ) && ! F_95 ( V_2 ) ) {
V_105 = V_35 -> V_70 ;
if ( V_35 -> V_43 & V_66 ) {
V_2 -> V_67 = V_68 ;
V_35 -> V_43 ^= V_66 ;
}
F_33 ( V_2 ) ;
} else {
V_105 = * ( (struct V_31 * * ) ( V_2 -> V_123 ) ) ;
}
F_24 ( V_2 ) ;
F_55 ( V_71 , V_124 , V_2 , V_105 ,
V_2 -> V_16 , V_125 , 1 ) ;
return 0 ;
}
static unsigned int F_96 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
struct V_34 * V_35 ;
struct V_31 * V_126 ;
T_4 V_127 ;
if ( ! V_2 -> V_35 )
return V_118 ;
if ( ! F_21 ( V_2 ) )
return V_108 ;
V_126 = F_17 ( V_106 ) ;
if ( ! V_126 )
return V_108 ;
if ( F_87 ( V_2 ) || F_88 ( V_2 ) || F_89 ( V_2 ) )
V_127 = V_122 ;
else if ( F_84 ( V_2 ) || F_85 ( V_2 ) || F_86 ( V_2 ) )
V_127 = V_112 ;
else
return V_118 ;
F_27 ( V_2 ) ;
V_35 = V_2 -> V_35 ;
if ( V_2 -> V_67 == V_68 ) {
V_2 -> V_67 = V_88 ;
V_35 -> V_43 |= V_66 ;
}
if ( V_127 == V_122 && F_34 ( V_2 ) )
return V_108 ;
V_35 -> V_43 |= V_128 ;
V_35 -> V_129 = V_2 -> V_16 ;
if ( V_127 == V_122 )
V_2 -> V_3 = F_3 ( V_121 ) ;
else
V_2 -> V_3 = F_3 ( V_111 ) ;
F_82 ( V_127 , V_130 , V_2 , F_71 ( V_2 , V_105 ) , V_126 ,
F_93 ) ;
return V_114 ;
}
static unsigned int F_97 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
struct V_32 * V_115 ;
struct V_17 * V_18 ;
struct V_31 * * V_131 = (struct V_31 * * ) ( V_2 -> V_123 ) ;
V_115 = F_16 ( V_106 ) ;
if ( V_115 == NULL )
return V_118 ;
V_18 = V_115 -> V_18 ;
if ( ! V_132 && ! V_18 -> V_133 )
return V_118 ;
if ( ! F_94 ( V_2 ) ) {
if ( ! F_95 ( V_2 ) )
return V_118 ;
F_27 ( V_2 ) ;
}
if ( F_98 ( V_2 ) -> V_134 != 4 ) {
if ( F_95 ( V_2 ) )
F_24 ( V_2 ) ;
return V_118 ;
}
* V_131 = (struct V_31 * ) V_105 ;
F_82 ( V_135 , V_136 , V_2 , (struct V_31 * ) V_105 ,
(struct V_31 * ) V_106 , F_93 ) ;
return V_114 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_76 ;
if ( V_2 -> V_137 != NULL && V_2 -> V_3 == F_3 ( V_121 ) &&
V_2 -> V_39 + F_100 ( V_2 ) > V_2 -> V_16 -> V_12 &&
! F_101 ( V_2 ) ) {
if ( F_34 ( V_2 ) )
return V_108 ;
V_76 = F_102 ( V_2 , V_138 ) ;
} else
V_76 = V_138 ( V_2 ) ;
return V_76 ;
}
static int F_99 ( struct V_1 * V_2 )
{
return V_138 ( V_2 ) ;
}
static unsigned int F_103 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_31 * V_139 = F_17 ( V_2 -> V_16 ) ;
T_4 V_127 ;
if ( ! V_35 || ! ( V_35 -> V_43 & V_128 ) )
return V_118 ;
if ( ! V_139 )
return V_108 ;
if ( F_87 ( V_2 ) || F_88 ( V_2 ) || F_89 ( V_2 ) )
V_127 = V_122 ;
else if ( F_84 ( V_2 ) || F_85 ( V_2 ) || F_86 ( V_2 ) )
V_127 = V_112 ;
else
return V_118 ;
if ( V_2 -> V_67 == V_68 ) {
V_2 -> V_67 = V_88 ;
V_35 -> V_43 |= V_66 ;
}
F_27 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( V_127 == V_122 )
V_2 -> V_3 = F_3 ( V_121 ) ;
else
V_2 -> V_3 = F_3 ( V_111 ) ;
F_82 ( V_127 , V_140 , V_2 , NULL , V_139 ,
F_99 ) ;
return V_114 ;
}
static unsigned int F_104 ( unsigned int V_104 , struct V_1 * V_2 ,
const struct V_31 * V_105 ,
const struct V_31 * V_106 ,
int (* F_81)( struct V_1 * ) )
{
if ( V_2 -> V_35 &&
! ( V_2 -> V_35 -> V_43 & V_69 ) ) {
return V_141 ;
}
return V_118 ;
}
static
int F_105 ( T_5 * V_142 , int V_143 ,
void T_6 * V_144 , T_7 * V_145 , T_8 * V_146 )
{
int V_76 ;
V_76 = F_106 ( V_142 , V_143 , V_144 , V_145 , V_146 ) ;
if ( V_143 && * ( int * ) ( V_142 -> V_42 ) )
* ( int * ) ( V_142 -> V_42 ) = 1 ;
return V_76 ;
}
int T_9 F_107 ( void )
{
int V_76 ;
V_76 = F_108 ( & V_30 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_109 ( V_147 , F_110 ( V_147 ) ) ;
if ( V_76 < 0 ) {
F_111 ( & V_30 ) ;
return V_76 ;
}
#ifdef F_112
V_148 = F_113 ( & V_149 , L_1 , V_150 ) ;
if ( V_148 == NULL ) {
F_114 ( V_151
L_2 ) ;
F_115 ( V_147 , F_110 ( V_147 ) ) ;
F_111 ( & V_30 ) ;
return - V_152 ;
}
#endif
F_114 ( V_153 L_3 ) ;
return 0 ;
}
void F_116 ( void )
{
F_115 ( V_147 , F_110 ( V_147 ) ) ;
#ifdef F_112
F_117 ( V_148 ) ;
#endif
F_111 ( & V_30 ) ;
}
