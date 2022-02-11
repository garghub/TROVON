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
void F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_16 ;
F_10 ( & V_15 -> V_9 . V_17 , 1 ) ;
V_15 -> V_9 . V_18 = V_13 -> V_18 ;
V_15 -> V_9 . V_19 = & V_15 -> V_9 ;
F_11 ( & V_15 -> V_9 , V_20 , true ) ;
V_15 -> V_9 . V_21 = V_22 ;
V_15 -> V_9 . V_23 = & V_24 ;
}
static inline struct V_14 * F_12 ( const struct V_25 * V_18 )
{
struct V_26 * V_27 ;
V_27 = F_13 ( V_18 ) ;
return V_27 ? & V_27 -> V_13 -> V_16 : NULL ;
}
static inline struct V_25 * F_14 ( const struct V_25 * V_18 )
{
struct V_26 * V_27 ;
V_27 = F_13 ( V_18 ) ;
return V_27 ? V_27 -> V_13 -> V_18 : NULL ;
}
static inline struct V_28 * F_15 ( struct V_1 * V_2 )
{
V_2 -> V_29 = F_16 ( sizeof( struct V_28 ) , V_30 ) ;
if ( F_17 ( V_2 -> V_29 ) )
F_10 ( & ( V_2 -> V_29 -> V_31 ) , 1 ) ;
return V_2 -> V_29 ;
}
static inline struct V_28 * F_18 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
if ( F_19 ( & V_29 -> V_31 ) > 1 ) {
struct V_28 * V_32 = F_15 ( V_2 ) ;
if ( V_32 ) {
memcpy ( V_32 , V_29 , sizeof( struct V_28 ) ) ;
F_10 ( & V_32 -> V_31 , 1 ) ;
}
F_20 ( V_29 ) ;
V_29 = V_32 ;
}
return V_29 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
unsigned int V_33 = F_22 ( V_2 ) ;
F_23 ( V_2 , V_33 ) ;
V_2 -> V_34 -= V_33 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
unsigned int V_33 = F_22 ( V_2 ) ;
F_25 ( V_2 , V_33 ) ;
V_2 -> V_34 += V_33 ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
unsigned int V_33 = F_22 ( V_2 ) ;
F_27 ( V_2 , V_33 ) ;
V_2 -> V_34 += V_33 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
int V_35 = V_6 + F_22 ( V_2 ) ;
F_29 ( V_2 , - V_35 ,
V_2 -> V_29 -> V_36 , V_35 ) ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 -> V_37 & V_38 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_29 -> V_37 & V_39 )
V_2 -> V_3 = F_3 ( V_40 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_25 * V_18 = V_2 -> V_18 ;
T_2 V_33 ;
V_44 = F_32 ( V_2 ) ;
V_42 = & ( F_33 ( V_2 ) -> V_42 ) ;
if ( V_44 -> V_45 < 5 || V_44 -> V_46 != 4 )
goto V_47;
if ( ! F_34 ( V_2 , V_44 -> V_45 * 4 ) )
goto V_47;
V_44 = F_32 ( V_2 ) ;
if ( F_35 ( F_36 ( ( V_48 * ) V_44 , V_44 -> V_45 ) ) )
goto V_47;
V_33 = F_37 ( V_44 -> V_49 ) ;
if ( V_2 -> V_33 < V_33 ) {
F_38 ( F_39 ( V_18 ) , V_50 ) ;
goto V_51;
} else if ( V_33 < ( V_44 -> V_45 * 4 ) )
goto V_47;
if ( F_40 ( V_2 , V_33 ) ) {
F_38 ( F_39 ( V_18 ) , V_52 ) ;
goto V_51;
}
memset ( F_33 ( V_2 ) , 0 , sizeof( struct V_53 ) ) ;
if ( V_44 -> V_45 == 5 )
return 0 ;
V_42 -> V_54 = V_44 -> V_45 * 4 - sizeof( struct V_43 ) ;
if ( F_41 ( F_39 ( V_18 ) , V_42 , V_2 ) )
goto V_47;
if ( F_35 ( V_42 -> V_55 ) ) {
struct V_56 * V_57 = F_42 ( V_18 ) ;
if ( V_57 && ! F_43 ( V_57 ) )
goto V_51;
if ( F_44 ( V_2 ) )
goto V_51;
}
return 0 ;
V_47:
F_38 ( F_39 ( V_18 ) , V_58 ) ;
V_51:
return - 1 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_59 ;
unsigned int V_35 ;
F_30 ( V_2 ) ;
V_35 = V_6 + F_22 ( V_2 ) ;
V_59 = F_46 ( V_2 , V_35 ) ;
if ( V_59 )
return V_59 ;
F_47 ( V_2 , - V_35 ,
V_2 -> V_29 -> V_36 , V_35 ) ;
F_48 ( V_2 , F_22 ( V_2 ) ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_14 * V_15 ;
if ( V_29 -> V_37 & V_60 ) {
V_2 -> V_61 = V_62 ;
V_29 -> V_37 ^= V_60 ;
}
V_29 -> V_37 ^= V_63 ;
V_15 = F_12 ( V_29 -> V_64 ) ;
if ( ! V_15 ) {
F_50 ( V_2 ) ;
return 0 ;
}
F_51 ( V_2 , & V_15 -> V_9 ) ;
V_2 -> V_18 = V_29 -> V_64 ;
F_30 ( V_2 ) ;
F_21 ( V_2 ) ;
F_52 ( V_65 , V_66 , V_2 , V_2 -> V_18 , NULL ,
V_67 , 1 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_8 * V_9 ;
V_2 -> V_18 = F_14 ( V_2 -> V_18 ) ;
if ( ! V_2 -> V_18 )
goto V_68;
V_9 = F_54 ( V_2 ) ;
if ( V_9 -> V_69 ) {
F_55 ( V_9 -> V_69 , V_2 ) ;
V_2 -> V_18 = V_29 -> V_64 ;
return V_67 ( V_2 ) ;
} else if ( V_9 -> V_70 ) {
F_29 ( V_2 , - ( V_6 - V_71 ) , V_2 -> V_29 -> V_36 , V_6 - V_71 ) ;
V_29 -> V_37 |= V_72 ;
return V_9 -> V_70 -> V_73 ( V_2 ) ;
}
V_68:
F_50 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_25 * V_18 = V_2 -> V_18 ;
struct V_43 * V_44 = F_32 ( V_2 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_14 * V_15 ;
int V_59 ;
if ( V_29 -> V_37 & V_60 ) {
V_2 -> V_61 = V_62 ;
V_29 -> V_37 ^= V_60 ;
}
V_29 -> V_37 ^= V_63 ;
if ( F_57 ( V_2 ) ) {
if ( ( V_59 = F_58 ( V_2 , V_44 -> V_74 , V_44 -> V_75 , V_44 -> V_76 , V_18 ) ) ) {
struct V_56 * V_57 = F_42 ( V_18 ) ;
if ( V_59 != - V_77 || ! V_57 || F_59 ( V_57 ) )
goto V_68;
V_15 = F_60 ( F_39 ( V_18 ) , V_44 -> V_74 , 0 ,
F_61 ( V_44 -> V_76 ) , 0 ) ;
if ( ! F_62 ( V_15 ) ) {
if ( V_15 -> V_9 . V_18 == V_18 ) {
F_63 ( V_2 , & V_15 -> V_9 ) ;
goto V_78;
}
F_64 ( V_15 ) ;
}
V_68:
F_50 ( V_2 ) ;
return 0 ;
} else {
if ( F_54 ( V_2 ) -> V_18 == V_18 ) {
V_78:
V_2 -> V_18 = V_29 -> V_64 ;
F_30 ( V_2 ) ;
F_21 ( V_2 ) ;
F_52 ( V_65 ,
V_66 ,
V_2 , V_2 -> V_18 , NULL ,
F_53 ,
1 ) ;
return 0 ;
}
memcpy ( F_65 ( V_2 ) -> V_79 , V_18 -> V_80 , V_71 ) ;
V_2 -> V_61 = V_81 ;
}
} else {
V_15 = F_12 ( V_29 -> V_64 ) ;
if ( ! V_15 ) {
F_50 ( V_2 ) ;
return 0 ;
}
F_51 ( V_2 , & V_15 -> V_9 ) ;
}
V_2 -> V_18 = V_29 -> V_64 ;
F_30 ( V_2 ) ;
F_21 ( V_2 ) ;
F_52 ( V_65 , V_66 , V_2 , V_2 -> V_18 , NULL ,
V_67 , 1 ) ;
return 0 ;
}
static struct V_25 * F_66 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_81 ;
V_29 -> V_37 |= V_60 ;
}
V_29 -> V_37 |= V_63 ;
V_29 -> V_64 = V_2 -> V_18 ;
V_2 -> V_18 = F_14 ( V_2 -> V_18 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_29 -> V_37 |= V_38 ;
else if ( V_2 -> V_3 == F_3 ( V_40 ) )
V_29 -> V_37 |= V_39 ;
return V_2 -> V_18 ;
}
static int F_67 ( struct V_1 * V_2 )
{
unsigned char * V_82 = ( V_48 * ) ( F_68 ( V_2 ) + 1 ) ;
T_2 V_83 ;
const unsigned char * V_84 = F_69 ( V_2 ) ;
int V_85 = V_82 - V_84 ;
int V_33 = ( V_82 [ 1 ] + 1 ) << 3 ;
if ( ( V_82 + V_33 ) - V_2 -> V_36 > F_70 ( V_2 ) )
goto V_86;
V_85 += 2 ;
V_33 -= 2 ;
while ( V_33 > 0 ) {
int V_54 = V_84 [ V_85 + 1 ] + 2 ;
switch ( V_84 [ V_85 ] ) {
case V_87 :
V_54 = 1 ;
break;
case V_88 :
break;
case V_89 :
if ( V_84 [ V_85 + 1 ] != 4 || ( V_85 & 3 ) != 2 )
goto V_86;
V_83 = F_71 ( * ( V_90 * ) ( V_84 + V_85 + 2 ) ) ;
if ( V_83 <= V_91 ||
F_68 ( V_2 ) -> V_92 )
goto V_86;
if ( V_83 > V_2 -> V_33 - sizeof( struct V_93 ) )
goto V_86;
if ( F_40 ( V_2 ,
V_83 + sizeof( struct V_93 ) ) )
goto V_86;
V_84 = F_69 ( V_2 ) ;
break;
default:
if ( V_54 > V_33 )
goto V_86;
break;
}
V_85 += V_54 ;
V_33 -= V_54 ;
}
if ( V_33 == 0 )
return 0 ;
V_86:
return - 1 ;
}
static unsigned int F_72 ( unsigned int V_94 ,
struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
const struct V_93 * V_97 ;
T_2 V_83 ;
if ( V_2 -> V_33 < sizeof( struct V_93 ) )
return V_98 ;
if ( ! F_34 ( V_2 , sizeof( struct V_93 ) ) )
return V_98 ;
V_97 = F_68 ( V_2 ) ;
if ( V_97 -> V_46 != 6 )
return V_98 ;
V_83 = F_37 ( V_97 -> V_92 ) ;
if ( V_83 || V_97 -> V_99 != V_100 ) {
if ( V_83 + sizeof( struct V_93 ) > V_2 -> V_33 )
return V_98 ;
if ( F_40 ( V_2 , V_83 + sizeof( struct V_93 ) ) )
return V_98 ;
}
if ( V_97 -> V_99 == V_100 && F_67 ( V_2 ) )
return V_98 ;
F_20 ( V_2 -> V_29 ) ;
if ( ! F_15 ( V_2 ) )
return V_98 ;
if ( ! F_66 ( V_2 ) )
return V_98 ;
V_2 -> V_3 = F_3 ( V_101 ) ;
F_74 ( V_102 , V_103 , V_2 , V_2 -> V_18 , NULL ,
F_49 ) ;
return V_104 ;
}
static unsigned int F_75 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
struct V_26 * V_105 ;
struct V_12 * V_13 ;
T_3 V_33 = F_22 ( V_2 ) ;
if ( F_35 ( ! F_34 ( V_2 , V_33 ) ) )
return V_98 ;
V_105 = F_13 ( V_95 ) ;
if ( V_105 == NULL )
return V_98 ;
V_13 = V_105 -> V_13 ;
if ( V_2 -> V_3 == F_3 ( V_101 ) || F_76 ( V_2 ) ||
F_77 ( V_2 ) ) {
if ( ! V_106 && ! V_13 -> V_107 )
return V_108 ;
F_26 ( V_2 ) ;
return F_72 ( V_94 , V_2 , V_95 , V_96 , F_73 ) ;
}
if ( ! V_109 && ! V_13 -> V_110 )
return V_108 ;
if ( V_2 -> V_3 != F_3 ( V_111 ) && ! F_78 ( V_2 ) &&
! F_79 ( V_2 ) )
return V_108 ;
F_26 ( V_2 ) ;
if ( F_31 ( V_2 ) )
return V_98 ;
F_20 ( V_2 -> V_29 ) ;
if ( ! F_15 ( V_2 ) )
return V_98 ;
if ( ! F_66 ( V_2 ) )
return V_98 ;
F_80 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_111 ) ;
F_74 ( V_112 , V_103 , V_2 , V_2 -> V_18 , NULL ,
F_56 ) ;
return V_104 ;
}
static unsigned int F_81 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
struct V_14 * V_15 = F_82 ( V_2 ) ;
if ( V_15 && V_15 == F_12 ( V_95 ) )
F_83 ( V_2 ) ;
return V_108 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_25 * V_95 ;
if ( V_2 -> V_3 != F_3 ( V_113 ) && ! F_85 ( V_2 ) ) {
V_95 = V_29 -> V_64 ;
if ( V_29 -> V_37 & V_60 ) {
V_2 -> V_61 = V_62 ;
V_29 -> V_37 ^= V_60 ;
}
F_30 ( V_2 ) ;
} else {
V_95 = * ( (struct V_25 * * ) ( V_2 -> V_114 ) ) ;
}
F_21 ( V_2 ) ;
F_52 ( V_65 , V_115 , V_2 , V_95 ,
V_2 -> V_18 , V_116 , 1 ) ;
return 0 ;
}
static unsigned int F_86 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
struct V_28 * V_29 ;
struct V_25 * V_117 ;
T_4 V_118 ;
if ( ! V_2 -> V_29 )
return V_108 ;
if ( ! F_18 ( V_2 ) )
return V_98 ;
V_117 = F_14 ( V_96 ) ;
if ( ! V_117 )
return V_98 ;
if ( V_2 -> V_3 == F_3 ( V_111 ) || F_78 ( V_2 ) ||
F_79 ( V_2 ) )
V_118 = V_119 ;
else if ( V_2 -> V_3 == F_3 ( V_101 ) || F_76 ( V_2 ) ||
F_77 ( V_2 ) )
V_118 = V_120 ;
else
return V_108 ;
F_24 ( V_2 ) ;
V_29 = V_2 -> V_29 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_81 ;
V_29 -> V_37 |= V_60 ;
}
if ( V_118 == V_119 && F_31 ( V_2 ) )
return V_98 ;
V_29 -> V_37 |= V_121 ;
V_29 -> V_122 = V_2 -> V_18 ;
if ( V_118 == V_119 )
V_2 -> V_3 = F_3 ( V_111 ) ;
else
V_2 -> V_3 = F_3 ( V_101 ) ;
F_74 ( V_118 , V_123 , V_2 , F_14 ( V_95 ) , V_117 ,
F_84 ) ;
return V_104 ;
}
static unsigned int F_87 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
struct V_26 * V_105 ;
struct V_12 * V_13 ;
struct V_25 * * V_124 = (struct V_25 * * ) ( V_2 -> V_114 ) ;
V_105 = F_13 ( V_96 ) ;
if ( V_105 == NULL )
return V_108 ;
V_13 = V_105 -> V_13 ;
if ( ! V_125 && ! V_13 -> V_126 )
return V_108 ;
if ( V_2 -> V_3 != F_3 ( V_113 ) ) {
if ( ! F_85 ( V_2 ) )
return V_108 ;
F_24 ( V_2 ) ;
}
if ( F_88 ( V_2 ) -> V_127 != 4 ) {
if ( F_85 ( V_2 ) )
F_21 ( V_2 ) ;
return V_108 ;
}
* V_124 = (struct V_25 * ) V_95 ;
F_74 ( V_128 , V_129 , V_2 , (struct V_25 * ) V_95 ,
(struct V_25 * ) V_96 , F_84 ) ;
return V_104 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_130 ;
if ( V_2 -> V_131 != NULL && V_2 -> V_3 == F_3 ( V_111 ) &&
V_2 -> V_33 + F_90 ( V_2 ) > V_2 -> V_18 -> V_10 &&
! F_91 ( V_2 ) ) {
if ( F_31 ( V_2 ) )
return V_98 ;
V_130 = F_92 ( V_2 , V_132 ) ;
} else
V_130 = V_132 ( V_2 ) ;
return V_130 ;
}
static int F_89 ( struct V_1 * V_2 )
{
return V_132 ( V_2 ) ;
}
static unsigned int F_93 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_25 * V_133 = F_14 ( V_2 -> V_18 ) ;
T_4 V_118 ;
if ( ! V_29 || ! ( V_29 -> V_37 & V_121 ) )
return V_108 ;
if ( ! V_133 )
return V_98 ;
if ( V_2 -> V_3 == F_3 ( V_111 ) || F_78 ( V_2 ) ||
F_79 ( V_2 ) )
V_118 = V_119 ;
else if ( V_2 -> V_3 == F_3 ( V_101 ) || F_76 ( V_2 ) ||
F_77 ( V_2 ) )
V_118 = V_120 ;
else
return V_108 ;
if ( V_2 -> V_61 == V_62 ) {
V_2 -> V_61 = V_81 ;
V_29 -> V_37 |= V_60 ;
}
F_24 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_118 == V_119 )
V_2 -> V_3 = F_3 ( V_111 ) ;
else
V_2 -> V_3 = F_3 ( V_101 ) ;
F_74 ( V_118 , V_134 , V_2 , NULL , V_133 ,
F_89 ) ;
return V_104 ;
}
static unsigned int F_94 ( unsigned int V_94 , struct V_1 * V_2 ,
const struct V_25 * V_95 ,
const struct V_25 * V_96 ,
int (* F_73)( struct V_1 * ) )
{
if ( V_2 -> V_29 &&
! ( V_2 -> V_29 -> V_37 & V_63 ) ) {
return V_135 ;
}
return V_108 ;
}
static
int F_95 ( T_5 * V_136 , int V_137 ,
void T_6 * V_138 , T_7 * V_139 , T_8 * V_140 )
{
int V_130 ;
V_130 = F_96 ( V_136 , V_137 , V_138 , V_139 , V_140 ) ;
if ( V_137 && * ( int * ) ( V_136 -> V_36 ) )
* ( int * ) ( V_136 -> V_36 ) = 1 ;
return V_130 ;
}
int T_9 F_97 ( void )
{
int V_130 ;
V_130 = F_98 ( & V_24 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_99 ( V_141 , F_100 ( V_141 ) ) ;
if ( V_130 < 0 ) {
F_101 ( & V_24 ) ;
return V_130 ;
}
#ifdef F_102
V_142 = F_103 ( V_143 , V_144 ) ;
if ( V_142 == NULL ) {
F_104 ( V_145
L_1 ) ;
F_105 ( V_141 , F_100 ( V_141 ) ) ;
F_101 ( & V_24 ) ;
return - V_146 ;
}
#endif
F_104 ( V_147 L_2 ) ;
return 0 ;
}
void F_106 ( void )
{
F_105 ( V_141 , F_100 ( V_141 ) ) ;
#ifdef F_102
F_107 ( V_142 ) ;
#endif
F_101 ( & V_24 ) ;
}
