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
static void F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
}
static T_2 * F_8 ( struct V_8 * V_9 , unsigned long V_11 )
{
return NULL ;
}
static struct V_12 * F_9 ( const struct V_8 * V_9 , const void * V_13 )
{
return NULL ;
}
static unsigned int F_10 ( const struct V_8 * V_9 )
{
return V_9 -> V_14 -> V_10 ;
}
void F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 ;
F_12 ( & V_18 -> V_9 . V_20 , 1 ) ;
V_18 -> V_9 . V_14 = V_16 -> V_14 ;
V_18 -> V_9 . V_21 = & V_18 -> V_9 ;
F_13 ( & V_18 -> V_9 , V_22 , true ) ;
V_18 -> V_9 . V_23 = V_24 | V_25 ;
V_18 -> V_9 . V_26 = & V_27 ;
}
static inline struct V_17 * F_14 ( const struct V_28 * V_14 )
{
struct V_29 * V_30 ;
V_30 = F_15 ( V_14 ) ;
return V_30 ? & V_30 -> V_16 -> V_19 : NULL ;
}
static inline struct V_28 * F_16 ( const struct V_28 * V_14 )
{
struct V_29 * V_30 ;
V_30 = F_15 ( V_14 ) ;
return V_30 ? V_30 -> V_16 -> V_14 : NULL ;
}
static inline struct V_31 * F_17 ( struct V_1 * V_2 )
{
V_2 -> V_32 = F_18 ( sizeof( struct V_31 ) , V_33 ) ;
if ( F_19 ( V_2 -> V_32 ) )
F_12 ( & ( V_2 -> V_32 -> V_34 ) , 1 ) ;
return V_2 -> V_32 ;
}
static inline struct V_31 * F_20 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
if ( F_21 ( & V_32 -> V_34 ) > 1 ) {
struct V_31 * V_35 = F_17 ( V_2 ) ;
if ( V_35 ) {
memcpy ( V_35 , V_32 , sizeof( struct V_31 ) ) ;
F_12 ( & V_35 -> V_34 , 1 ) ;
}
F_22 ( V_32 ) ;
V_32 = V_35 ;
}
return V_32 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_24 ( V_2 ) ;
F_25 ( V_2 , V_36 ) ;
V_2 -> V_37 -= V_36 ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_24 ( V_2 ) ;
F_27 ( V_2 , V_36 ) ;
V_2 -> V_37 += V_36 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_24 ( V_2 ) ;
F_29 ( V_2 , V_36 ) ;
V_2 -> V_37 += V_36 ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
int V_38 = V_6 + F_24 ( V_2 ) ;
F_31 ( V_2 , - V_38 ,
V_2 -> V_32 -> V_39 , V_38 ) ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 -> V_40 & V_41 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_32 -> V_40 & V_42 )
V_2 -> V_3 = F_3 ( V_43 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
struct V_28 * V_14 = V_2 -> V_14 ;
T_2 V_36 ;
V_47 = F_34 ( V_2 ) ;
V_45 = & ( F_35 ( V_2 ) -> V_45 ) ;
if ( V_47 -> V_48 < 5 || V_47 -> V_49 != 4 )
goto V_50;
if ( ! F_36 ( V_2 , V_47 -> V_48 * 4 ) )
goto V_50;
V_47 = F_34 ( V_2 ) ;
if ( F_37 ( F_38 ( ( V_51 * ) V_47 , V_47 -> V_48 ) ) )
goto V_50;
V_36 = F_39 ( V_47 -> V_52 ) ;
if ( V_2 -> V_36 < V_36 ) {
F_40 ( F_41 ( V_14 ) , V_53 ) ;
goto V_54;
} else if ( V_36 < ( V_47 -> V_48 * 4 ) )
goto V_50;
if ( F_42 ( V_2 , V_36 ) ) {
F_40 ( F_41 ( V_14 ) , V_55 ) ;
goto V_54;
}
memset ( F_35 ( V_2 ) , 0 , sizeof( struct V_56 ) ) ;
if ( V_47 -> V_48 == 5 )
return 0 ;
V_45 -> V_57 = V_47 -> V_48 * 4 - sizeof( struct V_46 ) ;
if ( F_43 ( F_41 ( V_14 ) , V_45 , V_2 ) )
goto V_50;
if ( F_37 ( V_45 -> V_58 ) ) {
struct V_59 * V_60 = F_44 ( V_14 ) ;
if ( V_60 && ! F_45 ( V_60 ) )
goto V_54;
if ( F_46 ( V_2 ) )
goto V_54;
}
return 0 ;
V_50:
F_40 ( F_41 ( V_14 ) , V_61 ) ;
V_54:
return - 1 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_62 ;
unsigned int V_38 ;
F_32 ( V_2 ) ;
V_38 = V_6 + F_24 ( V_2 ) ;
V_62 = F_48 ( V_2 , V_38 ) ;
if ( V_62 )
return V_62 ;
F_49 ( V_2 , - V_38 ,
V_2 -> V_32 -> V_39 , V_38 ) ;
F_50 ( V_2 , F_24 ( V_2 ) ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_17 * V_18 ;
if ( V_32 -> V_40 & V_63 ) {
V_2 -> V_64 = V_65 ;
V_32 -> V_40 ^= V_63 ;
}
V_32 -> V_40 ^= V_66 ;
V_18 = F_14 ( V_32 -> V_67 ) ;
if ( ! V_18 ) {
F_52 ( V_2 ) ;
return 0 ;
}
F_53 ( V_2 , & V_18 -> V_9 ) ;
V_2 -> V_14 = V_32 -> V_67 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_68 , V_69 , V_2 , V_2 -> V_14 , NULL ,
V_70 , 1 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_12 * V_71 ;
struct V_8 * V_9 ;
V_2 -> V_14 = F_16 ( V_2 -> V_14 ) ;
if ( ! V_2 -> V_14 )
goto V_72;
V_9 = F_56 ( V_2 ) ;
V_71 = F_57 ( V_9 ) ;
if ( V_71 -> V_73 . V_74 ) {
F_58 ( & V_71 -> V_73 , V_2 ) ;
V_2 -> V_14 = V_32 -> V_67 ;
return V_70 ( V_2 ) ;
} else {
F_31 ( V_2 , - ( V_6 - V_75 ) , V_2 -> V_32 -> V_39 , V_6 - V_75 ) ;
V_32 -> V_40 |= V_76 ;
return V_71 -> V_77 ( V_71 , V_2 ) ;
}
V_72:
F_52 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_28 * V_14 = V_2 -> V_14 ;
struct V_46 * V_47 = F_34 ( V_2 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_17 * V_18 ;
int V_62 ;
if ( V_32 -> V_40 & V_63 ) {
V_2 -> V_64 = V_65 ;
V_32 -> V_40 ^= V_63 ;
}
V_32 -> V_40 ^= V_66 ;
if ( F_60 ( V_2 ) ) {
if ( ( V_62 = F_61 ( V_2 , V_47 -> V_13 , V_47 -> V_78 , V_47 -> V_79 , V_14 ) ) ) {
struct V_59 * V_60 = F_44 ( V_14 ) ;
if ( V_62 != - V_80 || ! V_60 || F_62 ( V_60 ) )
goto V_72;
V_18 = F_63 ( F_41 ( V_14 ) , V_47 -> V_13 , 0 ,
F_64 ( V_47 -> V_79 ) , 0 ) ;
if ( ! F_65 ( V_18 ) ) {
if ( V_18 -> V_9 . V_14 == V_14 ) {
F_66 ( V_2 , & V_18 -> V_9 ) ;
goto V_81;
}
F_67 ( V_18 ) ;
}
V_72:
F_52 ( V_2 ) ;
return 0 ;
} else {
if ( F_56 ( V_2 ) -> V_14 == V_14 ) {
V_81:
V_2 -> V_14 = V_32 -> V_67 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_68 ,
V_69 ,
V_2 , V_2 -> V_14 , NULL ,
F_55 ,
1 ) ;
return 0 ;
}
memcpy ( F_68 ( V_2 ) -> V_82 , V_14 -> V_83 , V_75 ) ;
V_2 -> V_64 = V_84 ;
}
} else {
V_18 = F_14 ( V_32 -> V_67 ) ;
if ( ! V_18 ) {
F_52 ( V_2 ) ;
return 0 ;
}
F_53 ( V_2 , & V_18 -> V_9 ) ;
}
V_2 -> V_14 = V_32 -> V_67 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_68 , V_69 , V_2 , V_2 -> V_14 , NULL ,
V_70 , 1 ) ;
return 0 ;
}
static struct V_28 * F_69 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_2 -> V_64 == V_65 ) {
V_2 -> V_64 = V_84 ;
V_32 -> V_40 |= V_63 ;
}
V_32 -> V_40 |= V_66 ;
V_32 -> V_67 = V_2 -> V_14 ;
V_2 -> V_14 = F_16 ( V_2 -> V_14 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_32 -> V_40 |= V_41 ;
else if ( V_2 -> V_3 == F_3 ( V_43 ) )
V_32 -> V_40 |= V_42 ;
return V_2 -> V_14 ;
}
static int F_70 ( struct V_1 * V_2 )
{
unsigned char * V_85 = ( V_51 * ) ( F_71 ( V_2 ) + 1 ) ;
T_2 V_86 ;
const unsigned char * V_87 = F_72 ( V_2 ) ;
int V_88 = V_85 - V_87 ;
int V_36 = ( V_85 [ 1 ] + 1 ) << 3 ;
if ( ( V_85 + V_36 ) - V_2 -> V_39 > F_73 ( V_2 ) )
goto V_89;
V_88 += 2 ;
V_36 -= 2 ;
while ( V_36 > 0 ) {
int V_57 = V_87 [ V_88 + 1 ] + 2 ;
switch ( V_87 [ V_88 ] ) {
case V_90 :
V_57 = 1 ;
break;
case V_91 :
break;
case V_92 :
if ( V_87 [ V_88 + 1 ] != 4 || ( V_88 & 3 ) != 2 )
goto V_89;
V_86 = F_74 ( * ( V_93 * ) ( V_87 + V_88 + 2 ) ) ;
if ( V_86 <= V_94 ||
F_71 ( V_2 ) -> V_95 )
goto V_89;
if ( V_86 > V_2 -> V_36 - sizeof( struct V_96 ) )
goto V_89;
if ( F_42 ( V_2 ,
V_86 + sizeof( struct V_96 ) ) )
goto V_89;
V_87 = F_72 ( V_2 ) ;
break;
default:
if ( V_57 > V_36 )
goto V_89;
break;
}
V_88 += V_57 ;
V_36 -= V_57 ;
}
if ( V_36 == 0 )
return 0 ;
V_89:
return - 1 ;
}
static unsigned int F_75 ( unsigned int V_97 ,
struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
const struct V_96 * V_100 ;
T_2 V_86 ;
if ( V_2 -> V_36 < sizeof( struct V_96 ) )
return V_101 ;
if ( ! F_36 ( V_2 , sizeof( struct V_96 ) ) )
return V_101 ;
V_100 = F_71 ( V_2 ) ;
if ( V_100 -> V_49 != 6 )
return V_101 ;
V_86 = F_39 ( V_100 -> V_95 ) ;
if ( V_86 || V_100 -> V_102 != V_103 ) {
if ( V_86 + sizeof( struct V_96 ) > V_2 -> V_36 )
return V_101 ;
if ( F_42 ( V_2 , V_86 + sizeof( struct V_96 ) ) )
return V_101 ;
}
if ( V_100 -> V_102 == V_103 && F_70 ( V_2 ) )
return V_101 ;
F_22 ( V_2 -> V_32 ) ;
if ( ! F_17 ( V_2 ) )
return V_101 ;
if ( ! F_69 ( V_2 ) )
return V_101 ;
V_2 -> V_3 = F_3 ( V_104 ) ;
F_77 ( V_105 , V_106 , V_2 , V_2 -> V_14 , NULL ,
F_51 ) ;
return V_107 ;
}
static unsigned int F_78 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
struct V_29 * V_108 ;
struct V_15 * V_16 ;
T_3 V_36 = F_24 ( V_2 ) ;
if ( F_37 ( ! F_36 ( V_2 , V_36 ) ) )
return V_101 ;
V_108 = F_15 ( V_98 ) ;
if ( V_108 == NULL )
return V_101 ;
V_16 = V_108 -> V_16 ;
if ( V_2 -> V_3 == F_3 ( V_104 ) || F_79 ( V_2 ) ||
F_80 ( V_2 ) ) {
if ( ! V_109 && ! V_16 -> V_110 )
return V_111 ;
F_28 ( V_2 ) ;
return F_75 ( V_97 , V_2 , V_98 , V_99 , F_76 ) ;
}
if ( ! V_112 && ! V_16 -> V_113 )
return V_111 ;
if ( V_2 -> V_3 != F_3 ( V_114 ) && ! F_81 ( V_2 ) &&
! F_82 ( V_2 ) )
return V_111 ;
F_28 ( V_2 ) ;
if ( F_33 ( V_2 ) )
return V_101 ;
F_22 ( V_2 -> V_32 ) ;
if ( ! F_17 ( V_2 ) )
return V_101 ;
if ( ! F_69 ( V_2 ) )
return V_101 ;
F_83 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_114 ) ;
F_77 ( V_115 , V_106 , V_2 , V_2 -> V_14 , NULL ,
F_59 ) ;
return V_107 ;
}
static unsigned int F_84 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
struct V_17 * V_18 = F_85 ( V_2 ) ;
if ( V_18 && V_18 == F_14 ( V_98 ) )
F_86 ( V_2 ) ;
return V_111 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_28 * V_98 ;
if ( V_2 -> V_3 != F_3 ( V_116 ) && ! F_88 ( V_2 ) ) {
V_98 = V_32 -> V_67 ;
if ( V_32 -> V_40 & V_63 ) {
V_2 -> V_64 = V_65 ;
V_32 -> V_40 ^= V_63 ;
}
F_32 ( V_2 ) ;
} else {
V_98 = * ( (struct V_28 * * ) ( V_2 -> V_117 ) ) ;
}
F_23 ( V_2 ) ;
F_54 ( V_68 , V_118 , V_2 , V_98 ,
V_2 -> V_14 , V_119 , 1 ) ;
return 0 ;
}
static unsigned int F_89 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
struct V_31 * V_32 ;
struct V_28 * V_120 ;
T_4 V_121 ;
if ( ! V_2 -> V_32 )
return V_111 ;
if ( ! F_20 ( V_2 ) )
return V_101 ;
V_120 = F_16 ( V_99 ) ;
if ( ! V_120 )
return V_101 ;
if ( V_2 -> V_3 == F_3 ( V_114 ) || F_81 ( V_2 ) ||
F_82 ( V_2 ) )
V_121 = V_122 ;
else if ( V_2 -> V_3 == F_3 ( V_104 ) || F_79 ( V_2 ) ||
F_80 ( V_2 ) )
V_121 = V_123 ;
else
return V_111 ;
F_26 ( V_2 ) ;
V_32 = V_2 -> V_32 ;
if ( V_2 -> V_64 == V_65 ) {
V_2 -> V_64 = V_84 ;
V_32 -> V_40 |= V_63 ;
}
if ( V_121 == V_122 && F_33 ( V_2 ) )
return V_101 ;
V_32 -> V_40 |= V_124 ;
V_32 -> V_125 = V_2 -> V_14 ;
if ( V_121 == V_122 )
V_2 -> V_3 = F_3 ( V_114 ) ;
else
V_2 -> V_3 = F_3 ( V_104 ) ;
F_77 ( V_121 , V_126 , V_2 , F_16 ( V_98 ) , V_120 ,
F_87 ) ;
return V_107 ;
}
static unsigned int F_90 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
struct V_29 * V_108 ;
struct V_15 * V_16 ;
struct V_28 * * V_127 = (struct V_28 * * ) ( V_2 -> V_117 ) ;
V_108 = F_15 ( V_99 ) ;
if ( V_108 == NULL )
return V_111 ;
V_16 = V_108 -> V_16 ;
if ( ! V_128 && ! V_16 -> V_129 )
return V_111 ;
if ( V_2 -> V_3 != F_3 ( V_116 ) ) {
if ( ! F_88 ( V_2 ) )
return V_111 ;
F_26 ( V_2 ) ;
}
if ( F_91 ( V_2 ) -> V_130 != 4 ) {
if ( F_88 ( V_2 ) )
F_23 ( V_2 ) ;
return V_111 ;
}
* V_127 = (struct V_28 * ) V_98 ;
F_77 ( V_131 , V_132 , V_2 , (struct V_28 * ) V_98 ,
(struct V_28 * ) V_99 , F_87 ) ;
return V_107 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_133 ;
if ( V_2 -> V_134 != NULL && V_2 -> V_3 == F_3 ( V_114 ) &&
V_2 -> V_36 + F_93 ( V_2 ) > V_2 -> V_14 -> V_10 &&
! F_94 ( V_2 ) ) {
if ( F_33 ( V_2 ) )
return V_101 ;
V_133 = F_95 ( V_2 , V_135 ) ;
} else
V_133 = V_135 ( V_2 ) ;
return V_133 ;
}
static int F_92 ( struct V_1 * V_2 )
{
return V_135 ( V_2 ) ;
}
static unsigned int F_96 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_28 * V_136 = F_16 ( V_2 -> V_14 ) ;
T_4 V_121 ;
if ( ! V_32 || ! ( V_32 -> V_40 & V_124 ) )
return V_111 ;
if ( ! V_136 )
return V_101 ;
if ( V_2 -> V_3 == F_3 ( V_114 ) || F_81 ( V_2 ) ||
F_82 ( V_2 ) )
V_121 = V_122 ;
else if ( V_2 -> V_3 == F_3 ( V_104 ) || F_79 ( V_2 ) ||
F_80 ( V_2 ) )
V_121 = V_123 ;
else
return V_111 ;
if ( V_2 -> V_64 == V_65 ) {
V_2 -> V_64 = V_84 ;
V_32 -> V_40 |= V_63 ;
}
F_26 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( V_121 == V_122 )
V_2 -> V_3 = F_3 ( V_114 ) ;
else
V_2 -> V_3 = F_3 ( V_104 ) ;
F_77 ( V_121 , V_137 , V_2 , NULL , V_136 ,
F_92 ) ;
return V_107 ;
}
static unsigned int F_97 ( unsigned int V_97 , struct V_1 * V_2 ,
const struct V_28 * V_98 ,
const struct V_28 * V_99 ,
int (* F_76)( struct V_1 * ) )
{
if ( V_2 -> V_32 &&
! ( V_2 -> V_32 -> V_40 & V_66 ) ) {
return V_138 ;
}
return V_111 ;
}
static
int F_98 ( T_5 * V_139 , int V_140 ,
void T_6 * V_141 , T_7 * V_142 , T_8 * V_143 )
{
int V_133 ;
V_133 = F_99 ( V_139 , V_140 , V_141 , V_142 , V_143 ) ;
if ( V_140 && * ( int * ) ( V_139 -> V_39 ) )
* ( int * ) ( V_139 -> V_39 ) = 1 ;
return V_133 ;
}
int T_9 F_100 ( void )
{
int V_133 ;
V_133 = F_101 ( & V_27 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_102 ( V_144 , F_103 ( V_144 ) ) ;
if ( V_133 < 0 ) {
F_104 ( & V_27 ) ;
return V_133 ;
}
#ifdef F_105
V_145 = F_106 ( V_146 , V_147 ) ;
if ( V_145 == NULL ) {
F_107 ( V_148
L_1 ) ;
F_108 ( V_144 , F_103 ( V_144 ) ) ;
F_104 ( & V_27 ) ;
return - V_149 ;
}
#endif
F_107 ( V_150 L_2 ) ;
return 0 ;
}
void F_109 ( void )
{
F_108 ( V_144 , F_103 ( V_144 ) ) ;
#ifdef F_105
F_110 ( V_145 ) ;
#endif
F_104 ( & V_27 ) ;
}
