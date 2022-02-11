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
void F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_18 ;
F_11 ( & V_17 -> V_9 . V_19 , 1 ) ;
V_17 -> V_9 . V_20 = V_15 -> V_20 ;
V_17 -> V_9 . V_21 = & V_17 -> V_9 ;
F_12 ( & V_17 -> V_9 , V_22 , true ) ;
V_17 -> V_9 . V_23 = V_24 ;
V_17 -> V_9 . V_25 = & V_26 ;
}
static inline struct V_16 * F_13 ( const struct V_27 * V_20 )
{
struct V_28 * V_29 ;
V_29 = F_14 ( V_20 ) ;
return V_29 ? & V_29 -> V_15 -> V_18 : NULL ;
}
static inline struct V_27 * F_15 ( const struct V_27 * V_20 )
{
struct V_28 * V_29 ;
V_29 = F_14 ( V_20 ) ;
return V_29 ? V_29 -> V_15 -> V_20 : NULL ;
}
static inline struct V_30 * F_16 ( struct V_1 * V_2 )
{
V_2 -> V_31 = F_17 ( sizeof( struct V_30 ) , V_32 ) ;
if ( F_18 ( V_2 -> V_31 ) )
F_11 ( & ( V_2 -> V_31 -> V_33 ) , 1 ) ;
return V_2 -> V_31 ;
}
static inline struct V_30 * F_19 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
if ( F_20 ( & V_31 -> V_33 ) > 1 ) {
struct V_30 * V_34 = F_16 ( V_2 ) ;
if ( V_34 ) {
memcpy ( V_34 , V_31 , sizeof( struct V_30 ) ) ;
F_11 ( & V_34 -> V_33 , 1 ) ;
}
F_21 ( V_31 ) ;
V_31 = V_34 ;
}
return V_31 ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
unsigned int V_35 = F_23 ( V_2 ) ;
F_24 ( V_2 , V_35 ) ;
V_2 -> V_36 -= V_35 ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
unsigned int V_35 = F_23 ( V_2 ) ;
F_26 ( V_2 , V_35 ) ;
V_2 -> V_36 += V_35 ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
unsigned int V_35 = F_23 ( V_2 ) ;
F_28 ( V_2 , V_35 ) ;
V_2 -> V_36 += V_35 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
int V_37 = V_6 + F_23 ( V_2 ) ;
F_30 ( V_2 , - V_37 ,
V_2 -> V_31 -> V_38 , V_37 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 -> V_39 & V_40 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_31 -> V_39 & V_41 )
V_2 -> V_3 = F_3 ( V_42 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
struct V_27 * V_20 = V_2 -> V_20 ;
T_2 V_35 ;
V_46 = F_33 ( V_2 ) ;
V_44 = & ( F_34 ( V_2 ) -> V_44 ) ;
if ( V_46 -> V_47 < 5 || V_46 -> V_48 != 4 )
goto V_49;
if ( ! F_35 ( V_2 , V_46 -> V_47 * 4 ) )
goto V_49;
V_46 = F_33 ( V_2 ) ;
if ( F_36 ( F_37 ( ( V_50 * ) V_46 , V_46 -> V_47 ) ) )
goto V_49;
V_35 = F_38 ( V_46 -> V_51 ) ;
if ( V_2 -> V_35 < V_35 ) {
F_39 ( F_40 ( V_20 ) , V_52 ) ;
goto V_53;
} else if ( V_35 < ( V_46 -> V_47 * 4 ) )
goto V_49;
if ( F_41 ( V_2 , V_35 ) ) {
F_39 ( F_40 ( V_20 ) , V_54 ) ;
goto V_53;
}
memset ( F_34 ( V_2 ) , 0 , sizeof( struct V_55 ) ) ;
if ( V_46 -> V_47 == 5 )
return 0 ;
V_44 -> V_56 = V_46 -> V_47 * 4 - sizeof( struct V_45 ) ;
if ( F_42 ( F_40 ( V_20 ) , V_44 , V_2 ) )
goto V_49;
if ( F_36 ( V_44 -> V_57 ) ) {
struct V_58 * V_59 = F_43 ( V_20 ) ;
if ( V_59 && ! F_44 ( V_59 ) )
goto V_53;
if ( F_45 ( V_2 ) )
goto V_53;
}
return 0 ;
V_49:
F_39 ( F_40 ( V_20 ) , V_60 ) ;
V_53:
return - 1 ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_61 ;
unsigned int V_37 ;
F_31 ( V_2 ) ;
V_37 = V_6 + F_23 ( V_2 ) ;
V_61 = F_47 ( V_2 , V_37 ) ;
if ( V_61 )
return V_61 ;
F_48 ( V_2 , - V_37 ,
V_2 -> V_31 -> V_38 , V_37 ) ;
F_49 ( V_2 , F_23 ( V_2 ) ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_16 * V_17 ;
if ( V_31 -> V_39 & V_62 ) {
V_2 -> V_63 = V_64 ;
V_31 -> V_39 ^= V_62 ;
}
V_31 -> V_39 ^= V_65 ;
V_17 = F_13 ( V_31 -> V_66 ) ;
if ( ! V_17 ) {
F_51 ( V_2 ) ;
return 0 ;
}
F_52 ( V_2 , & V_17 -> V_9 ) ;
V_2 -> V_20 = V_31 -> V_66 ;
F_31 ( V_2 ) ;
F_22 ( V_2 ) ;
F_53 ( V_67 , V_68 , V_2 , V_2 -> V_20 , NULL ,
V_69 , 1 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_12 * V_70 ;
struct V_8 * V_9 ;
V_2 -> V_20 = F_15 ( V_2 -> V_20 ) ;
if ( ! V_2 -> V_20 )
goto V_71;
V_9 = F_55 ( V_2 ) ;
V_70 = F_56 ( V_9 ) ;
if ( V_70 -> V_72 . V_73 ) {
F_57 ( & V_70 -> V_72 , V_2 ) ;
V_2 -> V_20 = V_31 -> V_66 ;
return V_69 ( V_2 ) ;
} else {
F_30 ( V_2 , - ( V_6 - V_74 ) , V_2 -> V_31 -> V_38 , V_6 - V_74 ) ;
V_31 -> V_39 |= V_75 ;
return V_70 -> V_76 ( V_70 , V_2 ) ;
}
V_71:
F_51 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_27 * V_20 = V_2 -> V_20 ;
struct V_45 * V_46 = F_33 ( V_2 ) ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_16 * V_17 ;
int V_61 ;
if ( V_31 -> V_39 & V_62 ) {
V_2 -> V_63 = V_64 ;
V_31 -> V_39 ^= V_62 ;
}
V_31 -> V_39 ^= V_65 ;
if ( F_59 ( V_2 ) ) {
if ( ( V_61 = F_60 ( V_2 , V_46 -> V_13 , V_46 -> V_77 , V_46 -> V_78 , V_20 ) ) ) {
struct V_58 * V_59 = F_43 ( V_20 ) ;
if ( V_61 != - V_79 || ! V_59 || F_61 ( V_59 ) )
goto V_71;
V_17 = F_62 ( F_40 ( V_20 ) , V_46 -> V_13 , 0 ,
F_63 ( V_46 -> V_78 ) , 0 ) ;
if ( ! F_64 ( V_17 ) ) {
if ( V_17 -> V_9 . V_20 == V_20 ) {
F_65 ( V_2 , & V_17 -> V_9 ) ;
goto V_80;
}
F_66 ( V_17 ) ;
}
V_71:
F_51 ( V_2 ) ;
return 0 ;
} else {
if ( F_55 ( V_2 ) -> V_20 == V_20 ) {
V_80:
V_2 -> V_20 = V_31 -> V_66 ;
F_31 ( V_2 ) ;
F_22 ( V_2 ) ;
F_53 ( V_67 ,
V_68 ,
V_2 , V_2 -> V_20 , NULL ,
F_54 ,
1 ) ;
return 0 ;
}
memcpy ( F_67 ( V_2 ) -> V_81 , V_20 -> V_82 , V_74 ) ;
V_2 -> V_63 = V_83 ;
}
} else {
V_17 = F_13 ( V_31 -> V_66 ) ;
if ( ! V_17 ) {
F_51 ( V_2 ) ;
return 0 ;
}
F_52 ( V_2 , & V_17 -> V_9 ) ;
}
V_2 -> V_20 = V_31 -> V_66 ;
F_31 ( V_2 ) ;
F_22 ( V_2 ) ;
F_53 ( V_67 , V_68 , V_2 , V_2 -> V_20 , NULL ,
V_69 , 1 ) ;
return 0 ;
}
static struct V_27 * F_68 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
if ( V_2 -> V_63 == V_64 ) {
V_2 -> V_63 = V_83 ;
V_31 -> V_39 |= V_62 ;
}
V_31 -> V_39 |= V_65 ;
V_31 -> V_66 = V_2 -> V_20 ;
V_2 -> V_20 = F_15 ( V_2 -> V_20 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_31 -> V_39 |= V_40 ;
else if ( V_2 -> V_3 == F_3 ( V_42 ) )
V_31 -> V_39 |= V_41 ;
return V_2 -> V_20 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned char * V_84 = ( V_50 * ) ( F_70 ( V_2 ) + 1 ) ;
T_2 V_85 ;
const unsigned char * V_86 = F_71 ( V_2 ) ;
int V_87 = V_84 - V_86 ;
int V_35 = ( V_84 [ 1 ] + 1 ) << 3 ;
if ( ( V_84 + V_35 ) - V_2 -> V_38 > F_72 ( V_2 ) )
goto V_88;
V_87 += 2 ;
V_35 -= 2 ;
while ( V_35 > 0 ) {
int V_56 = V_86 [ V_87 + 1 ] + 2 ;
switch ( V_86 [ V_87 ] ) {
case V_89 :
V_56 = 1 ;
break;
case V_90 :
break;
case V_91 :
if ( V_86 [ V_87 + 1 ] != 4 || ( V_87 & 3 ) != 2 )
goto V_88;
V_85 = F_73 ( * ( V_92 * ) ( V_86 + V_87 + 2 ) ) ;
if ( V_85 <= V_93 ||
F_70 ( V_2 ) -> V_94 )
goto V_88;
if ( V_85 > V_2 -> V_35 - sizeof( struct V_95 ) )
goto V_88;
if ( F_41 ( V_2 ,
V_85 + sizeof( struct V_95 ) ) )
goto V_88;
V_86 = F_71 ( V_2 ) ;
break;
default:
if ( V_56 > V_35 )
goto V_88;
break;
}
V_87 += V_56 ;
V_35 -= V_56 ;
}
if ( V_35 == 0 )
return 0 ;
V_88:
return - 1 ;
}
static unsigned int F_74 ( unsigned int V_96 ,
struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
const struct V_95 * V_99 ;
T_2 V_85 ;
if ( V_2 -> V_35 < sizeof( struct V_95 ) )
return V_100 ;
if ( ! F_35 ( V_2 , sizeof( struct V_95 ) ) )
return V_100 ;
V_99 = F_70 ( V_2 ) ;
if ( V_99 -> V_48 != 6 )
return V_100 ;
V_85 = F_38 ( V_99 -> V_94 ) ;
if ( V_85 || V_99 -> V_101 != V_102 ) {
if ( V_85 + sizeof( struct V_95 ) > V_2 -> V_35 )
return V_100 ;
if ( F_41 ( V_2 , V_85 + sizeof( struct V_95 ) ) )
return V_100 ;
}
if ( V_99 -> V_101 == V_102 && F_69 ( V_2 ) )
return V_100 ;
F_21 ( V_2 -> V_31 ) ;
if ( ! F_16 ( V_2 ) )
return V_100 ;
if ( ! F_68 ( V_2 ) )
return V_100 ;
V_2 -> V_3 = F_3 ( V_103 ) ;
F_76 ( V_104 , V_105 , V_2 , V_2 -> V_20 , NULL ,
F_50 ) ;
return V_106 ;
}
static unsigned int F_77 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
struct V_28 * V_107 ;
struct V_14 * V_15 ;
T_3 V_35 = F_23 ( V_2 ) ;
if ( F_36 ( ! F_35 ( V_2 , V_35 ) ) )
return V_100 ;
V_107 = F_14 ( V_97 ) ;
if ( V_107 == NULL )
return V_100 ;
V_15 = V_107 -> V_15 ;
if ( V_2 -> V_3 == F_3 ( V_103 ) || F_78 ( V_2 ) ||
F_79 ( V_2 ) ) {
if ( ! V_108 && ! V_15 -> V_109 )
return V_110 ;
F_27 ( V_2 ) ;
return F_74 ( V_96 , V_2 , V_97 , V_98 , F_75 ) ;
}
if ( ! V_111 && ! V_15 -> V_112 )
return V_110 ;
if ( V_2 -> V_3 != F_3 ( V_113 ) && ! F_80 ( V_2 ) &&
! F_81 ( V_2 ) )
return V_110 ;
F_27 ( V_2 ) ;
if ( F_32 ( V_2 ) )
return V_100 ;
F_21 ( V_2 -> V_31 ) ;
if ( ! F_16 ( V_2 ) )
return V_100 ;
if ( ! F_68 ( V_2 ) )
return V_100 ;
F_82 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_113 ) ;
F_76 ( V_114 , V_105 , V_2 , V_2 -> V_20 , NULL ,
F_58 ) ;
return V_106 ;
}
static unsigned int F_83 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
struct V_16 * V_17 = F_84 ( V_2 ) ;
if ( V_17 && V_17 == F_13 ( V_97 ) )
F_85 ( V_2 ) ;
return V_110 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_27 * V_97 ;
if ( V_2 -> V_3 != F_3 ( V_115 ) && ! F_87 ( V_2 ) ) {
V_97 = V_31 -> V_66 ;
if ( V_31 -> V_39 & V_62 ) {
V_2 -> V_63 = V_64 ;
V_31 -> V_39 ^= V_62 ;
}
F_31 ( V_2 ) ;
} else {
V_97 = * ( (struct V_27 * * ) ( V_2 -> V_116 ) ) ;
}
F_22 ( V_2 ) ;
F_53 ( V_67 , V_117 , V_2 , V_97 ,
V_2 -> V_20 , V_118 , 1 ) ;
return 0 ;
}
static unsigned int F_88 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
struct V_30 * V_31 ;
struct V_27 * V_119 ;
T_4 V_120 ;
if ( ! V_2 -> V_31 )
return V_110 ;
if ( ! F_19 ( V_2 ) )
return V_100 ;
V_119 = F_15 ( V_98 ) ;
if ( ! V_119 )
return V_100 ;
if ( V_2 -> V_3 == F_3 ( V_113 ) || F_80 ( V_2 ) ||
F_81 ( V_2 ) )
V_120 = V_121 ;
else if ( V_2 -> V_3 == F_3 ( V_103 ) || F_78 ( V_2 ) ||
F_79 ( V_2 ) )
V_120 = V_122 ;
else
return V_110 ;
F_25 ( V_2 ) ;
V_31 = V_2 -> V_31 ;
if ( V_2 -> V_63 == V_64 ) {
V_2 -> V_63 = V_83 ;
V_31 -> V_39 |= V_62 ;
}
if ( V_120 == V_121 && F_32 ( V_2 ) )
return V_100 ;
V_31 -> V_39 |= V_123 ;
V_31 -> V_124 = V_2 -> V_20 ;
if ( V_120 == V_121 )
V_2 -> V_3 = F_3 ( V_113 ) ;
else
V_2 -> V_3 = F_3 ( V_103 ) ;
F_76 ( V_120 , V_125 , V_2 , F_15 ( V_97 ) , V_119 ,
F_86 ) ;
return V_106 ;
}
static unsigned int F_89 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
struct V_28 * V_107 ;
struct V_14 * V_15 ;
struct V_27 * * V_126 = (struct V_27 * * ) ( V_2 -> V_116 ) ;
V_107 = F_14 ( V_98 ) ;
if ( V_107 == NULL )
return V_110 ;
V_15 = V_107 -> V_15 ;
if ( ! V_127 && ! V_15 -> V_128 )
return V_110 ;
if ( V_2 -> V_3 != F_3 ( V_115 ) ) {
if ( ! F_87 ( V_2 ) )
return V_110 ;
F_25 ( V_2 ) ;
}
if ( F_90 ( V_2 ) -> V_129 != 4 ) {
if ( F_87 ( V_2 ) )
F_22 ( V_2 ) ;
return V_110 ;
}
* V_126 = (struct V_27 * ) V_97 ;
F_76 ( V_130 , V_131 , V_2 , (struct V_27 * ) V_97 ,
(struct V_27 * ) V_98 , F_86 ) ;
return V_106 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_2 -> V_133 != NULL && V_2 -> V_3 == F_3 ( V_113 ) &&
V_2 -> V_35 + F_92 ( V_2 ) > V_2 -> V_20 -> V_10 &&
! F_93 ( V_2 ) ) {
if ( F_32 ( V_2 ) )
return V_100 ;
V_132 = F_94 ( V_2 , V_134 ) ;
} else
V_132 = V_134 ( V_2 ) ;
return V_132 ;
}
static int F_91 ( struct V_1 * V_2 )
{
return V_134 ( V_2 ) ;
}
static unsigned int F_95 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_27 * V_135 = F_15 ( V_2 -> V_20 ) ;
T_4 V_120 ;
if ( ! V_31 || ! ( V_31 -> V_39 & V_123 ) )
return V_110 ;
if ( ! V_135 )
return V_100 ;
if ( V_2 -> V_3 == F_3 ( V_113 ) || F_80 ( V_2 ) ||
F_81 ( V_2 ) )
V_120 = V_121 ;
else if ( V_2 -> V_3 == F_3 ( V_103 ) || F_78 ( V_2 ) ||
F_79 ( V_2 ) )
V_120 = V_122 ;
else
return V_110 ;
if ( V_2 -> V_63 == V_64 ) {
V_2 -> V_63 = V_83 ;
V_31 -> V_39 |= V_62 ;
}
F_25 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( V_120 == V_121 )
V_2 -> V_3 = F_3 ( V_113 ) ;
else
V_2 -> V_3 = F_3 ( V_103 ) ;
F_76 ( V_120 , V_136 , V_2 , NULL , V_135 ,
F_91 ) ;
return V_106 ;
}
static unsigned int F_96 ( unsigned int V_96 , struct V_1 * V_2 ,
const struct V_27 * V_97 ,
const struct V_27 * V_98 ,
int (* F_75)( struct V_1 * ) )
{
if ( V_2 -> V_31 &&
! ( V_2 -> V_31 -> V_39 & V_65 ) ) {
return V_137 ;
}
return V_110 ;
}
static
int F_97 ( T_5 * V_138 , int V_139 ,
void T_6 * V_140 , T_7 * V_141 , T_8 * V_142 )
{
int V_132 ;
V_132 = F_98 ( V_138 , V_139 , V_140 , V_141 , V_142 ) ;
if ( V_139 && * ( int * ) ( V_138 -> V_38 ) )
* ( int * ) ( V_138 -> V_38 ) = 1 ;
return V_132 ;
}
int T_9 F_99 ( void )
{
int V_132 ;
V_132 = F_100 ( & V_26 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_101 ( V_143 , F_102 ( V_143 ) ) ;
if ( V_132 < 0 ) {
F_103 ( & V_26 ) ;
return V_132 ;
}
#ifdef F_104
V_144 = F_105 ( V_145 , V_146 ) ;
if ( V_144 == NULL ) {
F_106 ( V_147
L_1 ) ;
F_107 ( V_143 , F_102 ( V_143 ) ) ;
F_103 ( & V_26 ) ;
return - V_148 ;
}
#endif
F_106 ( V_149 L_2 ) ;
return 0 ;
}
void F_108 ( void )
{
F_107 ( V_143 , F_102 ( V_143 ) ) ;
#ifdef F_104
F_109 ( V_144 ) ;
#endif
F_103 ( & V_26 ) ;
}
