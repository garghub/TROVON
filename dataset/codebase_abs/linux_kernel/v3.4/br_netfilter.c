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
V_18 -> V_9 . V_23 = V_24 | V_25 | V_26 ;
V_18 -> V_9 . V_27 = & V_28 ;
}
static inline struct V_17 * F_14 ( const struct V_29 * V_14 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_14 ) ;
return V_31 ? & V_31 -> V_16 -> V_19 : NULL ;
}
static inline struct V_29 * F_16 ( const struct V_29 * V_14 )
{
struct V_30 * V_31 ;
V_31 = F_15 ( V_14 ) ;
return V_31 ? V_31 -> V_16 -> V_14 : NULL ;
}
static inline struct V_32 * F_17 ( struct V_1 * V_2 )
{
V_2 -> V_33 = F_18 ( sizeof( struct V_32 ) , V_34 ) ;
if ( F_19 ( V_2 -> V_33 ) )
F_12 ( & ( V_2 -> V_33 -> V_35 ) , 1 ) ;
return V_2 -> V_33 ;
}
static inline struct V_32 * F_20 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
if ( F_21 ( & V_33 -> V_35 ) > 1 ) {
struct V_32 * V_36 = F_17 ( V_2 ) ;
if ( V_36 ) {
memcpy ( V_36 , V_33 , sizeof( struct V_32 ) ) ;
F_12 ( & V_36 -> V_35 , 1 ) ;
}
F_22 ( V_33 ) ;
V_33 = V_36 ;
}
return V_33 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
unsigned int V_37 = F_24 ( V_2 ) ;
F_25 ( V_2 , V_37 ) ;
V_2 -> V_38 -= V_37 ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
unsigned int V_37 = F_24 ( V_2 ) ;
F_27 ( V_2 , V_37 ) ;
V_2 -> V_38 += V_37 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
unsigned int V_37 = F_24 ( V_2 ) ;
F_29 ( V_2 , V_37 ) ;
V_2 -> V_38 += V_37 ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
int V_39 = V_6 + F_24 ( V_2 ) ;
F_31 ( V_2 , - V_39 ,
V_2 -> V_33 -> V_40 , V_39 ) ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 -> V_41 & V_42 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_33 -> V_41 & V_43 )
V_2 -> V_3 = F_3 ( V_44 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
const struct V_47 * V_48 ;
struct V_29 * V_14 = V_2 -> V_14 ;
T_2 V_37 ;
V_48 = F_34 ( V_2 ) ;
V_46 = & ( F_35 ( V_2 ) -> V_46 ) ;
if ( V_48 -> V_49 < 5 || V_48 -> V_50 != 4 )
goto V_51;
if ( ! F_36 ( V_2 , V_48 -> V_49 * 4 ) )
goto V_51;
V_48 = F_34 ( V_2 ) ;
if ( F_37 ( F_38 ( ( V_52 * ) V_48 , V_48 -> V_49 ) ) )
goto V_51;
V_37 = F_39 ( V_48 -> V_53 ) ;
if ( V_2 -> V_37 < V_37 ) {
F_40 ( F_41 ( V_14 ) , V_54 ) ;
goto V_55;
} else if ( V_37 < ( V_48 -> V_49 * 4 ) )
goto V_51;
if ( F_42 ( V_2 , V_37 ) ) {
F_40 ( F_41 ( V_14 ) , V_56 ) ;
goto V_55;
}
memset ( F_35 ( V_2 ) , 0 , sizeof( struct V_57 ) ) ;
if ( V_48 -> V_49 == 5 )
return 0 ;
V_46 -> V_58 = V_48 -> V_49 * 4 - sizeof( struct V_47 ) ;
if ( F_43 ( F_41 ( V_14 ) , V_46 , V_2 ) )
goto V_51;
if ( F_37 ( V_46 -> V_59 ) ) {
struct V_60 * V_61 = F_44 ( V_14 ) ;
if ( V_61 && ! F_45 ( V_61 ) )
goto V_55;
if ( F_46 ( V_2 ) )
goto V_55;
}
return 0 ;
V_51:
F_40 ( F_41 ( V_14 ) , V_62 ) ;
V_55:
return - 1 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_63 ;
unsigned int V_39 ;
F_32 ( V_2 ) ;
V_39 = V_6 + F_24 ( V_2 ) ;
V_63 = F_48 ( V_2 , V_39 ) ;
if ( V_63 )
return V_63 ;
F_49 ( V_2 , - V_39 ,
V_2 -> V_33 -> V_40 , V_39 ) ;
F_50 ( V_2 , F_24 ( V_2 ) ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_17 * V_18 ;
if ( V_33 -> V_41 & V_64 ) {
V_2 -> V_65 = V_66 ;
V_33 -> V_41 ^= V_64 ;
}
V_33 -> V_41 ^= V_67 ;
V_18 = F_14 ( V_33 -> V_68 ) ;
if ( ! V_18 ) {
F_52 ( V_2 ) ;
return 0 ;
}
F_53 ( V_2 , & V_18 -> V_9 ) ;
V_2 -> V_14 = V_33 -> V_68 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_69 , V_70 , V_2 , V_2 -> V_14 , NULL ,
V_71 , 1 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_12 * V_72 ;
struct V_8 * V_9 ;
V_2 -> V_14 = F_16 ( V_2 -> V_14 ) ;
if ( ! V_2 -> V_14 )
goto V_73;
V_9 = F_56 ( V_2 ) ;
V_72 = F_57 ( V_9 ) ;
if ( V_72 -> V_74 . V_75 ) {
F_58 ( & V_72 -> V_74 , V_2 ) ;
V_2 -> V_14 = V_33 -> V_68 ;
return V_71 ( V_2 ) ;
} else {
F_31 ( V_2 , - ( V_6 - V_76 ) , V_2 -> V_33 -> V_40 , V_6 - V_76 ) ;
V_33 -> V_41 |= V_77 ;
return V_72 -> V_78 ( V_72 , V_2 ) ;
}
V_73:
F_52 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_14 = V_2 -> V_14 ;
struct V_47 * V_48 = F_34 ( V_2 ) ;
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_17 * V_18 ;
int V_63 ;
if ( V_33 -> V_41 & V_64 ) {
V_2 -> V_65 = V_66 ;
V_33 -> V_41 ^= V_64 ;
}
V_33 -> V_41 ^= V_67 ;
if ( F_60 ( V_2 ) ) {
if ( ( V_63 = F_61 ( V_2 , V_48 -> V_13 , V_48 -> V_79 , V_48 -> V_80 , V_14 ) ) ) {
struct V_60 * V_61 = F_44 ( V_14 ) ;
if ( V_63 != - V_81 || ! V_61 || F_62 ( V_61 ) )
goto V_73;
V_18 = F_63 ( F_41 ( V_14 ) , V_48 -> V_13 , 0 ,
F_64 ( V_48 -> V_80 ) , 0 ) ;
if ( ! F_65 ( V_18 ) ) {
if ( V_18 -> V_9 . V_14 == V_14 ) {
F_66 ( V_2 , & V_18 -> V_9 ) ;
goto V_82;
}
F_67 ( V_18 ) ;
}
V_73:
F_52 ( V_2 ) ;
return 0 ;
} else {
if ( F_56 ( V_2 ) -> V_14 == V_14 ) {
V_82:
V_2 -> V_14 = V_33 -> V_68 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_69 ,
V_70 ,
V_2 , V_2 -> V_14 , NULL ,
F_55 ,
1 ) ;
return 0 ;
}
memcpy ( F_68 ( V_2 ) -> V_83 , V_14 -> V_84 , V_76 ) ;
V_2 -> V_65 = V_85 ;
}
} else {
V_18 = F_14 ( V_33 -> V_68 ) ;
if ( ! V_18 ) {
F_52 ( V_2 ) ;
return 0 ;
}
F_53 ( V_2 , & V_18 -> V_9 ) ;
}
V_2 -> V_14 = V_33 -> V_68 ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
F_54 ( V_69 , V_70 , V_2 , V_2 -> V_14 , NULL ,
V_71 , 1 ) ;
return 0 ;
}
static struct V_29 * F_69 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
if ( V_2 -> V_65 == V_66 ) {
V_2 -> V_65 = V_85 ;
V_33 -> V_41 |= V_64 ;
}
V_33 -> V_41 |= V_67 ;
V_33 -> V_68 = V_2 -> V_14 ;
V_2 -> V_14 = F_16 ( V_2 -> V_14 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_33 -> V_41 |= V_42 ;
else if ( V_2 -> V_3 == F_3 ( V_44 ) )
V_33 -> V_41 |= V_43 ;
return V_2 -> V_14 ;
}
static int F_70 ( struct V_1 * V_2 )
{
unsigned char * V_86 = ( V_52 * ) ( F_71 ( V_2 ) + 1 ) ;
T_2 V_87 ;
const unsigned char * V_88 = F_72 ( V_2 ) ;
int V_89 = V_86 - V_88 ;
int V_37 = ( V_86 [ 1 ] + 1 ) << 3 ;
if ( ( V_86 + V_37 ) - V_2 -> V_40 > F_73 ( V_2 ) )
goto V_90;
V_89 += 2 ;
V_37 -= 2 ;
while ( V_37 > 0 ) {
int V_58 = V_88 [ V_89 + 1 ] + 2 ;
switch ( V_88 [ V_89 ] ) {
case V_91 :
V_58 = 1 ;
break;
case V_92 :
break;
case V_93 :
if ( V_88 [ V_89 + 1 ] != 4 || ( V_89 & 3 ) != 2 )
goto V_90;
V_87 = F_74 ( * ( V_94 * ) ( V_88 + V_89 + 2 ) ) ;
if ( V_87 <= V_95 ||
F_71 ( V_2 ) -> V_96 )
goto V_90;
if ( V_87 > V_2 -> V_37 - sizeof( struct V_97 ) )
goto V_90;
if ( F_42 ( V_2 ,
V_87 + sizeof( struct V_97 ) ) )
goto V_90;
V_88 = F_72 ( V_2 ) ;
break;
default:
if ( V_58 > V_37 )
goto V_90;
break;
}
V_89 += V_58 ;
V_37 -= V_58 ;
}
if ( V_37 == 0 )
return 0 ;
V_90:
return - 1 ;
}
static unsigned int F_75 ( unsigned int V_98 ,
struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
const struct V_97 * V_101 ;
T_2 V_87 ;
if ( V_2 -> V_37 < sizeof( struct V_97 ) )
return V_102 ;
if ( ! F_36 ( V_2 , sizeof( struct V_97 ) ) )
return V_102 ;
V_101 = F_71 ( V_2 ) ;
if ( V_101 -> V_50 != 6 )
return V_102 ;
V_87 = F_39 ( V_101 -> V_96 ) ;
if ( V_87 || V_101 -> V_103 != V_104 ) {
if ( V_87 + sizeof( struct V_97 ) > V_2 -> V_37 )
return V_102 ;
if ( F_42 ( V_2 , V_87 + sizeof( struct V_97 ) ) )
return V_102 ;
}
if ( V_101 -> V_103 == V_104 && F_70 ( V_2 ) )
return V_102 ;
F_22 ( V_2 -> V_33 ) ;
if ( ! F_17 ( V_2 ) )
return V_102 ;
if ( ! F_69 ( V_2 ) )
return V_102 ;
V_2 -> V_3 = F_3 ( V_105 ) ;
F_77 ( V_106 , V_107 , V_2 , V_2 -> V_14 , NULL ,
F_51 ) ;
return V_108 ;
}
static unsigned int F_78 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
struct V_30 * V_109 ;
struct V_15 * V_16 ;
T_3 V_37 = F_24 ( V_2 ) ;
if ( F_37 ( ! F_36 ( V_2 , V_37 ) ) )
return V_102 ;
V_109 = F_15 ( V_99 ) ;
if ( V_109 == NULL )
return V_102 ;
V_16 = V_109 -> V_16 ;
if ( F_79 ( V_2 ) || F_80 ( V_2 ) || F_81 ( V_2 ) ) {
if ( ! V_110 && ! V_16 -> V_111 )
return V_112 ;
F_28 ( V_2 ) ;
return F_75 ( V_98 , V_2 , V_99 , V_100 , F_76 ) ;
}
if ( ! V_113 && ! V_16 -> V_114 )
return V_112 ;
if ( ! F_82 ( V_2 ) && ! F_83 ( V_2 ) && ! F_84 ( V_2 ) )
return V_112 ;
F_28 ( V_2 ) ;
if ( F_33 ( V_2 ) )
return V_102 ;
F_22 ( V_2 -> V_33 ) ;
if ( ! F_17 ( V_2 ) )
return V_102 ;
if ( ! F_69 ( V_2 ) )
return V_102 ;
F_85 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_115 ) ;
F_77 ( V_116 , V_107 , V_2 , V_2 -> V_14 , NULL ,
F_59 ) ;
return V_108 ;
}
static unsigned int F_86 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
F_87 ( V_2 ) ;
return V_112 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_29 * V_99 ;
if ( ! F_89 ( V_2 ) && ! F_90 ( V_2 ) ) {
V_99 = V_33 -> V_68 ;
if ( V_33 -> V_41 & V_64 ) {
V_2 -> V_65 = V_66 ;
V_33 -> V_41 ^= V_64 ;
}
F_32 ( V_2 ) ;
} else {
V_99 = * ( (struct V_29 * * ) ( V_2 -> V_117 ) ) ;
}
F_23 ( V_2 ) ;
F_54 ( V_69 , V_118 , V_2 , V_99 ,
V_2 -> V_14 , V_119 , 1 ) ;
return 0 ;
}
static unsigned int F_91 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
struct V_32 * V_33 ;
struct V_29 * V_120 ;
T_4 V_121 ;
if ( ! V_2 -> V_33 )
return V_112 ;
if ( ! F_20 ( V_2 ) )
return V_102 ;
V_120 = F_16 ( V_100 ) ;
if ( ! V_120 )
return V_102 ;
if ( F_82 ( V_2 ) || F_83 ( V_2 ) || F_84 ( V_2 ) )
V_121 = V_122 ;
else if ( F_79 ( V_2 ) || F_80 ( V_2 ) || F_81 ( V_2 ) )
V_121 = V_123 ;
else
return V_112 ;
F_26 ( V_2 ) ;
V_33 = V_2 -> V_33 ;
if ( V_2 -> V_65 == V_66 ) {
V_2 -> V_65 = V_85 ;
V_33 -> V_41 |= V_64 ;
}
if ( V_121 == V_122 && F_33 ( V_2 ) )
return V_102 ;
V_33 -> V_41 |= V_124 ;
V_33 -> V_125 = V_2 -> V_14 ;
if ( V_121 == V_122 )
V_2 -> V_3 = F_3 ( V_115 ) ;
else
V_2 -> V_3 = F_3 ( V_105 ) ;
F_77 ( V_121 , V_126 , V_2 , F_16 ( V_99 ) , V_120 ,
F_88 ) ;
return V_108 ;
}
static unsigned int F_92 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
struct V_30 * V_109 ;
struct V_15 * V_16 ;
struct V_29 * * V_127 = (struct V_29 * * ) ( V_2 -> V_117 ) ;
V_109 = F_15 ( V_100 ) ;
if ( V_109 == NULL )
return V_112 ;
V_16 = V_109 -> V_16 ;
if ( ! V_128 && ! V_16 -> V_129 )
return V_112 ;
if ( ! F_89 ( V_2 ) ) {
if ( ! F_90 ( V_2 ) )
return V_112 ;
F_26 ( V_2 ) ;
}
if ( F_93 ( V_2 ) -> V_130 != 4 ) {
if ( F_90 ( V_2 ) )
F_23 ( V_2 ) ;
return V_112 ;
}
* V_127 = (struct V_29 * ) V_99 ;
F_77 ( V_131 , V_132 , V_2 , (struct V_29 * ) V_99 ,
(struct V_29 * ) V_100 , F_88 ) ;
return V_108 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_133 ;
if ( V_2 -> V_134 != NULL && V_2 -> V_3 == F_3 ( V_115 ) &&
V_2 -> V_37 + F_95 ( V_2 ) > V_2 -> V_14 -> V_10 &&
! F_96 ( V_2 ) ) {
if ( F_33 ( V_2 ) )
return V_102 ;
V_133 = F_97 ( V_2 , V_135 ) ;
} else
V_133 = V_135 ( V_2 ) ;
return V_133 ;
}
static int F_94 ( struct V_1 * V_2 )
{
return V_135 ( V_2 ) ;
}
static unsigned int F_98 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_29 * V_136 = F_16 ( V_2 -> V_14 ) ;
T_4 V_121 ;
if ( ! V_33 || ! ( V_33 -> V_41 & V_124 ) )
return V_112 ;
if ( ! V_136 )
return V_102 ;
if ( F_82 ( V_2 ) || F_83 ( V_2 ) || F_84 ( V_2 ) )
V_121 = V_122 ;
else if ( F_79 ( V_2 ) || F_80 ( V_2 ) || F_81 ( V_2 ) )
V_121 = V_123 ;
else
return V_112 ;
if ( V_2 -> V_65 == V_66 ) {
V_2 -> V_65 = V_85 ;
V_33 -> V_41 |= V_64 ;
}
F_26 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( V_121 == V_122 )
V_2 -> V_3 = F_3 ( V_115 ) ;
else
V_2 -> V_3 = F_3 ( V_105 ) ;
F_77 ( V_121 , V_137 , V_2 , NULL , V_136 ,
F_94 ) ;
return V_108 ;
}
static unsigned int F_99 ( unsigned int V_98 , struct V_1 * V_2 ,
const struct V_29 * V_99 ,
const struct V_29 * V_100 ,
int (* F_76)( struct V_1 * ) )
{
if ( V_2 -> V_33 &&
! ( V_2 -> V_33 -> V_41 & V_67 ) ) {
return V_138 ;
}
return V_112 ;
}
static
int F_100 ( T_5 * V_139 , int V_140 ,
void T_6 * V_141 , T_7 * V_142 , T_8 * V_143 )
{
int V_133 ;
V_133 = F_101 ( V_139 , V_140 , V_141 , V_142 , V_143 ) ;
if ( V_140 && * ( int * ) ( V_139 -> V_40 ) )
* ( int * ) ( V_139 -> V_40 ) = 1 ;
return V_133 ;
}
int T_9 F_102 ( void )
{
int V_133 ;
V_133 = F_103 ( & V_28 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_104 ( V_144 , F_105 ( V_144 ) ) ;
if ( V_133 < 0 ) {
F_106 ( & V_28 ) ;
return V_133 ;
}
#ifdef F_107
V_145 = F_108 ( V_146 , V_147 ) ;
if ( V_145 == NULL ) {
F_109 ( V_148
L_1 ) ;
F_110 ( V_144 , F_105 ( V_144 ) ) ;
F_106 ( & V_28 ) ;
return - V_149 ;
}
#endif
F_109 ( V_150 L_2 ) ;
return 0 ;
}
void F_111 ( void )
{
F_110 ( V_144 , F_105 ( V_144 ) ) ;
#ifdef F_107
F_112 ( V_145 ) ;
#endif
F_106 ( & V_28 ) ;
}
