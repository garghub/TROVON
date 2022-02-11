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
V_20 -> V_9 . V_25 = V_26 | V_27 ;
V_20 -> V_9 . V_28 = & V_29 ;
}
static inline struct V_19 * F_15 ( const struct V_30 * V_16 )
{
struct V_31 * V_32 ;
V_32 = F_16 ( V_16 ) ;
return V_32 ? & V_32 -> V_18 -> V_21 : NULL ;
}
static inline struct V_30 * F_17 ( const struct V_30 * V_16 )
{
struct V_31 * V_32 ;
V_32 = F_16 ( V_16 ) ;
return V_32 ? V_32 -> V_18 -> V_16 : NULL ;
}
static inline struct V_33 * F_18 ( struct V_1 * V_2 )
{
V_2 -> V_34 = F_19 ( sizeof( struct V_33 ) , V_35 ) ;
if ( F_20 ( V_2 -> V_34 ) )
F_13 ( & ( V_2 -> V_34 -> V_36 ) , 1 ) ;
return V_2 -> V_34 ;
}
static inline struct V_33 * F_21 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
if ( F_22 ( & V_34 -> V_36 ) > 1 ) {
struct V_33 * V_37 = F_18 ( V_2 ) ;
if ( V_37 ) {
memcpy ( V_37 , V_34 , sizeof( struct V_33 ) ) ;
F_13 ( & V_37 -> V_36 , 1 ) ;
}
F_23 ( V_34 ) ;
V_34 = V_37 ;
}
return V_34 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
unsigned int V_38 = F_25 ( V_2 ) ;
F_26 ( V_2 , V_38 ) ;
V_2 -> V_39 -= V_38 ;
}
static inline void F_27 ( struct V_1 * V_2 )
{
unsigned int V_38 = F_25 ( V_2 ) ;
F_28 ( V_2 , V_38 ) ;
V_2 -> V_39 += V_38 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
unsigned int V_38 = F_25 ( V_2 ) ;
F_30 ( V_2 , V_38 ) ;
V_2 -> V_39 += V_38 ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
int V_40 = V_6 + F_25 ( V_2 ) ;
F_32 ( V_2 , - V_40 ,
V_2 -> V_34 -> V_41 , V_40 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 -> V_42 & V_43 )
V_2 -> V_3 = F_3 ( V_4 ) ;
else if ( V_2 -> V_34 -> V_42 & V_44 )
V_2 -> V_3 = F_3 ( V_45 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
const struct V_48 * V_49 ;
struct V_30 * V_16 = V_2 -> V_16 ;
T_2 V_38 ;
if ( ! F_35 ( V_2 , sizeof( struct V_48 ) ) )
goto V_50;
V_49 = F_36 ( V_2 ) ;
V_47 = & ( F_37 ( V_2 ) -> V_47 ) ;
if ( V_49 -> V_51 < 5 || V_49 -> V_52 != 4 )
goto V_50;
if ( ! F_35 ( V_2 , V_49 -> V_51 * 4 ) )
goto V_50;
V_49 = F_36 ( V_2 ) ;
if ( F_38 ( F_39 ( ( V_53 * ) V_49 , V_49 -> V_51 ) ) )
goto V_50;
V_38 = F_40 ( V_49 -> V_54 ) ;
if ( V_2 -> V_38 < V_38 ) {
F_41 ( F_42 ( V_16 ) , V_55 ) ;
goto V_56;
} else if ( V_38 < ( V_49 -> V_51 * 4 ) )
goto V_50;
if ( F_43 ( V_2 , V_38 ) ) {
F_41 ( F_42 ( V_16 ) , V_57 ) ;
goto V_56;
}
memset ( F_37 ( V_2 ) , 0 , sizeof( struct V_58 ) ) ;
if ( V_49 -> V_51 == 5 )
return 0 ;
V_47 -> V_59 = V_49 -> V_51 * 4 - sizeof( struct V_48 ) ;
if ( F_44 ( F_42 ( V_16 ) , V_47 , V_2 ) )
goto V_50;
if ( F_38 ( V_47 -> V_60 ) ) {
struct V_61 * V_62 = F_45 ( V_16 ) ;
if ( V_62 && ! F_46 ( V_62 ) )
goto V_56;
if ( F_47 ( V_2 ) )
goto V_56;
}
return 0 ;
V_50:
F_41 ( F_42 ( V_16 ) , V_63 ) ;
V_56:
return - 1 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_64 ;
unsigned int V_40 ;
F_33 ( V_2 ) ;
V_40 = V_6 + F_25 ( V_2 ) ;
V_64 = F_49 ( V_2 , V_40 ) ;
if ( V_64 )
return V_64 ;
F_50 ( V_2 , - V_40 ,
V_2 -> V_34 -> V_41 , V_40 ) ;
F_51 ( V_2 , F_25 ( V_2 ) ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_19 * V_20 ;
if ( V_34 -> V_42 & V_65 ) {
V_2 -> V_66 = V_67 ;
V_34 -> V_42 ^= V_65 ;
}
V_34 -> V_42 ^= V_68 ;
V_20 = F_15 ( V_34 -> V_69 ) ;
if ( ! V_20 ) {
F_53 ( V_2 ) ;
return 0 ;
}
F_54 ( V_2 , & V_20 -> V_9 ) ;
V_2 -> V_16 = V_34 -> V_69 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_70 , V_71 , V_2 , V_2 -> V_16 , NULL ,
V_72 , 1 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_14 * V_73 ;
struct V_8 * V_9 ;
V_2 -> V_16 = F_17 ( V_2 -> V_16 ) ;
if ( ! V_2 -> V_16 )
goto V_74;
V_9 = F_57 ( V_2 ) ;
V_73 = F_58 ( V_9 , V_2 ) ;
if ( V_73 ) {
int V_75 ;
if ( V_73 -> V_76 . V_77 ) {
F_59 ( & V_73 -> V_76 , V_2 ) ;
V_2 -> V_16 = V_34 -> V_69 ;
V_75 = V_72 ( V_2 ) ;
} else {
F_32 ( V_2 ,
- ( V_6 - V_78 ) ,
V_2 -> V_34 -> V_41 ,
V_6 - V_78 ) ;
V_34 -> V_42 |= V_79 ;
V_75 = V_73 -> V_80 ( V_73 , V_2 ) ;
}
F_60 ( V_73 ) ;
return V_75 ;
}
V_74:
F_53 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_30 * V_16 = V_2 -> V_16 ;
struct V_48 * V_49 = F_36 ( V_2 ) ;
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_19 * V_20 ;
int V_64 ;
if ( V_34 -> V_42 & V_65 ) {
V_2 -> V_66 = V_67 ;
V_34 -> V_42 ^= V_65 ;
}
V_34 -> V_42 ^= V_68 ;
if ( F_62 ( V_2 ) ) {
if ( ( V_64 = F_63 ( V_2 , V_49 -> V_15 , V_49 -> V_81 , V_49 -> V_82 , V_16 ) ) ) {
struct V_61 * V_62 = F_45 ( V_16 ) ;
if ( V_64 != - V_83 || ! V_62 || F_64 ( V_62 ) )
goto V_74;
V_20 = F_65 ( F_42 ( V_16 ) , V_49 -> V_15 , 0 ,
F_66 ( V_49 -> V_82 ) , 0 ) ;
if ( ! F_67 ( V_20 ) ) {
if ( V_20 -> V_9 . V_16 == V_16 ) {
F_68 ( V_2 , & V_20 -> V_9 ) ;
goto V_84;
}
F_69 ( V_20 ) ;
}
V_74:
F_53 ( V_2 ) ;
return 0 ;
} else {
if ( F_57 ( V_2 ) -> V_16 == V_16 ) {
V_84:
V_2 -> V_16 = V_34 -> V_69 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_70 ,
V_71 ,
V_2 , V_2 -> V_16 , NULL ,
F_56 ,
1 ) ;
return 0 ;
}
F_70 ( F_71 ( V_2 ) -> V_85 , V_16 -> V_86 ) ;
V_2 -> V_66 = V_87 ;
}
} else {
V_20 = F_15 ( V_34 -> V_69 ) ;
if ( ! V_20 ) {
F_53 ( V_2 ) ;
return 0 ;
}
F_54 ( V_2 , & V_20 -> V_9 ) ;
}
V_2 -> V_16 = V_34 -> V_69 ;
F_33 ( V_2 ) ;
F_24 ( V_2 ) ;
F_55 ( V_70 , V_71 , V_2 , V_2 -> V_16 , NULL ,
V_72 , 1 ) ;
return 0 ;
}
static struct V_30 * F_72 ( struct V_1 * V_2 , const struct V_30 * V_16 )
{
struct V_30 * V_88 , * V_18 ;
V_18 = F_17 ( V_16 ) ;
if ( V_89 == 0 || ! F_2 ( V_2 ) )
return V_18 ;
V_88 = F_73 ( V_18 , V_2 -> F_1 ,
F_74 ( V_2 ) & V_90 ) ;
return V_88 ? V_88 : V_18 ;
}
static struct V_30 * F_75 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
if ( V_2 -> V_66 == V_67 ) {
V_2 -> V_66 = V_87 ;
V_34 -> V_42 |= V_65 ;
}
V_34 -> V_42 |= V_68 ;
V_34 -> V_69 = V_2 -> V_16 ;
V_2 -> V_16 = F_72 ( V_2 , V_2 -> V_16 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_34 -> V_42 |= V_43 ;
else if ( V_2 -> V_3 == F_3 ( V_45 ) )
V_34 -> V_42 |= V_44 ;
F_76 ( V_2 ) ;
return V_2 -> V_16 ;
}
static int F_77 ( struct V_1 * V_2 )
{
unsigned char * V_91 = ( V_53 * ) ( F_78 ( V_2 ) + 1 ) ;
T_2 V_92 ;
const unsigned char * V_93 = F_79 ( V_2 ) ;
int V_94 = V_91 - V_93 ;
int V_38 = ( V_91 [ 1 ] + 1 ) << 3 ;
if ( ( V_91 + V_38 ) - V_2 -> V_41 > F_80 ( V_2 ) )
goto V_95;
V_94 += 2 ;
V_38 -= 2 ;
while ( V_38 > 0 ) {
int V_59 = V_93 [ V_94 + 1 ] + 2 ;
switch ( V_93 [ V_94 ] ) {
case V_96 :
V_59 = 1 ;
break;
case V_97 :
break;
case V_98 :
if ( V_93 [ V_94 + 1 ] != 4 || ( V_94 & 3 ) != 2 )
goto V_95;
V_92 = F_81 ( * ( V_99 * ) ( V_93 + V_94 + 2 ) ) ;
if ( V_92 <= V_100 ||
F_78 ( V_2 ) -> V_101 )
goto V_95;
if ( V_92 > V_2 -> V_38 - sizeof( struct V_102 ) )
goto V_95;
if ( F_43 ( V_2 ,
V_92 + sizeof( struct V_102 ) ) )
goto V_95;
V_93 = F_79 ( V_2 ) ;
break;
default:
if ( V_59 > V_38 )
goto V_95;
break;
}
V_94 += V_59 ;
V_38 -= V_59 ;
}
if ( V_38 == 0 )
return 0 ;
V_95:
return - 1 ;
}
static unsigned int F_82 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
const struct V_102 * V_106 ;
T_2 V_92 ;
if ( V_2 -> V_38 < sizeof( struct V_102 ) )
return V_107 ;
if ( ! F_35 ( V_2 , sizeof( struct V_102 ) ) )
return V_107 ;
V_106 = F_78 ( V_2 ) ;
if ( V_106 -> V_52 != 6 )
return V_107 ;
V_92 = F_40 ( V_106 -> V_101 ) ;
if ( V_92 || V_106 -> V_108 != V_109 ) {
if ( V_92 + sizeof( struct V_102 ) > V_2 -> V_38 )
return V_107 ;
if ( F_43 ( V_2 , V_92 + sizeof( struct V_102 ) ) )
return V_107 ;
}
if ( V_106 -> V_108 == V_109 && F_77 ( V_2 ) )
return V_107 ;
F_23 ( V_2 -> V_34 ) ;
if ( ! F_18 ( V_2 ) )
return V_107 ;
if ( ! F_75 ( V_2 ) )
return V_107 ;
V_2 -> V_3 = F_3 ( V_110 ) ;
F_84 ( V_111 , V_112 , V_2 , V_2 -> V_16 , NULL ,
F_52 ) ;
return V_113 ;
}
static unsigned int F_85 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
struct V_31 * V_114 ;
struct V_17 * V_18 ;
T_3 V_38 = F_25 ( V_2 ) ;
if ( F_38 ( ! F_35 ( V_2 , V_38 ) ) )
return V_107 ;
V_114 = F_16 ( V_104 ) ;
if ( V_114 == NULL )
return V_107 ;
V_18 = V_114 -> V_18 ;
if ( F_86 ( V_2 ) || F_87 ( V_2 ) || F_88 ( V_2 ) ) {
if ( ! V_115 && ! V_18 -> V_116 )
return V_117 ;
F_29 ( V_2 ) ;
return F_82 ( V_28 , V_2 , V_104 , V_105 , F_83 ) ;
}
if ( ! V_118 && ! V_18 -> V_119 )
return V_117 ;
if ( ! F_89 ( V_2 ) && ! F_90 ( V_2 ) && ! F_91 ( V_2 ) )
return V_117 ;
F_29 ( V_2 ) ;
if ( F_34 ( V_2 ) )
return V_107 ;
F_23 ( V_2 -> V_34 ) ;
if ( ! F_18 ( V_2 ) )
return V_107 ;
if ( ! F_75 ( V_2 ) )
return V_107 ;
F_92 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_120 ) ;
F_84 ( V_121 , V_112 , V_2 , V_2 -> V_16 , NULL ,
F_61 ) ;
return V_113 ;
}
static unsigned int F_93 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
F_94 ( V_2 ) ;
return V_117 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_30 * V_104 ;
if ( ! F_96 ( V_2 ) && ! F_97 ( V_2 ) ) {
V_104 = V_34 -> V_69 ;
if ( V_34 -> V_42 & V_65 ) {
V_2 -> V_66 = V_67 ;
V_34 -> V_42 ^= V_65 ;
}
F_33 ( V_2 ) ;
} else {
V_104 = * ( (struct V_30 * * ) ( V_2 -> V_122 ) ) ;
}
F_24 ( V_2 ) ;
F_55 ( V_70 , V_123 , V_2 , V_104 ,
V_2 -> V_16 , V_124 , 1 ) ;
return 0 ;
}
static unsigned int F_98 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
struct V_33 * V_34 ;
struct V_30 * V_125 ;
T_4 V_126 ;
if ( ! V_2 -> V_34 )
return V_117 ;
if ( ! F_21 ( V_2 ) )
return V_107 ;
V_125 = F_17 ( V_105 ) ;
if ( ! V_125 )
return V_107 ;
if ( F_89 ( V_2 ) || F_90 ( V_2 ) || F_91 ( V_2 ) )
V_126 = V_121 ;
else if ( F_86 ( V_2 ) || F_87 ( V_2 ) || F_88 ( V_2 ) )
V_126 = V_111 ;
else
return V_117 ;
F_27 ( V_2 ) ;
V_34 = V_2 -> V_34 ;
if ( V_2 -> V_66 == V_67 ) {
V_2 -> V_66 = V_87 ;
V_34 -> V_42 |= V_65 ;
}
if ( V_126 == V_121 && F_34 ( V_2 ) )
return V_107 ;
V_34 -> V_42 |= V_127 ;
V_34 -> V_128 = V_2 -> V_16 ;
if ( V_126 == V_121 )
V_2 -> V_3 = F_3 ( V_120 ) ;
else
V_2 -> V_3 = F_3 ( V_110 ) ;
F_84 ( V_126 , V_129 , V_2 , F_72 ( V_2 , V_104 ) , V_125 ,
F_95 ) ;
return V_113 ;
}
static unsigned int F_99 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
struct V_31 * V_114 ;
struct V_17 * V_18 ;
struct V_30 * * V_130 = (struct V_30 * * ) ( V_2 -> V_122 ) ;
V_114 = F_16 ( V_105 ) ;
if ( V_114 == NULL )
return V_117 ;
V_18 = V_114 -> V_18 ;
if ( ! V_131 && ! V_18 -> V_132 )
return V_117 ;
if ( ! F_96 ( V_2 ) ) {
if ( ! F_97 ( V_2 ) )
return V_117 ;
F_27 ( V_2 ) ;
}
if ( F_100 ( V_2 ) -> V_133 != 4 ) {
if ( F_97 ( V_2 ) )
F_24 ( V_2 ) ;
return V_117 ;
}
* V_130 = (struct V_30 * ) V_104 ;
F_84 ( V_134 , V_135 , V_2 , (struct V_30 * ) V_104 ,
(struct V_30 * ) V_105 , F_95 ) ;
return V_113 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_75 ;
if ( V_2 -> V_3 == F_3 ( V_120 ) &&
V_2 -> V_38 + F_102 ( V_2 ) > V_2 -> V_16 -> V_12 &&
! F_103 ( V_2 ) ) {
if ( F_34 ( V_2 ) )
return V_107 ;
V_75 = F_104 ( V_2 , V_136 ) ;
} else
V_75 = V_136 ( V_2 ) ;
return V_75 ;
}
static int F_101 ( struct V_1 * V_2 )
{
return V_136 ( V_2 ) ;
}
static unsigned int F_105 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_30 * V_137 = F_17 ( V_2 -> V_16 ) ;
T_4 V_126 ;
if ( ! V_34 || ! ( V_34 -> V_42 & V_127 ) )
return V_117 ;
if ( ! V_137 )
return V_107 ;
if ( F_89 ( V_2 ) || F_90 ( V_2 ) || F_91 ( V_2 ) )
V_126 = V_121 ;
else if ( F_86 ( V_2 ) || F_87 ( V_2 ) || F_88 ( V_2 ) )
V_126 = V_111 ;
else
return V_117 ;
if ( V_2 -> V_66 == V_67 ) {
V_2 -> V_66 = V_87 ;
V_34 -> V_42 |= V_65 ;
}
F_27 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( V_126 == V_121 )
V_2 -> V_3 = F_3 ( V_120 ) ;
else
V_2 -> V_3 = F_3 ( V_110 ) ;
F_84 ( V_126 , V_138 , V_2 , NULL , V_137 ,
F_101 ) ;
return V_113 ;
}
static unsigned int F_106 ( const struct V_103 * V_28 ,
struct V_1 * V_2 ,
const struct V_30 * V_104 ,
const struct V_30 * V_105 ,
int (* F_83)( struct V_1 * ) )
{
if ( V_2 -> V_34 &&
! ( V_2 -> V_34 -> V_42 & V_68 ) ) {
return V_139 ;
}
return V_117 ;
}
static
int F_107 ( struct V_140 * V_141 , int V_142 ,
void T_5 * V_143 , T_6 * V_144 , T_7 * V_145 )
{
int V_75 ;
V_75 = F_108 ( V_141 , V_142 , V_143 , V_144 , V_145 ) ;
if ( V_142 && * ( int * ) ( V_141 -> V_41 ) )
* ( int * ) ( V_141 -> V_41 ) = 1 ;
return V_75 ;
}
int T_8 F_109 ( void )
{
int V_75 ;
V_75 = F_110 ( & V_29 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_111 ( V_146 , F_112 ( V_146 ) ) ;
if ( V_75 < 0 ) {
F_113 ( & V_29 ) ;
return V_75 ;
}
#ifdef F_114
V_147 = F_115 ( & V_148 , L_1 , V_149 ) ;
if ( V_147 == NULL ) {
F_116 ( V_150
L_2 ) ;
F_117 ( V_146 , F_112 ( V_146 ) ) ;
F_113 ( & V_29 ) ;
return - V_151 ;
}
#endif
F_116 ( V_152 L_3 ) ;
return 0 ;
}
void F_118 ( void )
{
F_117 ( V_146 , F_112 ( V_146 ) ) ;
#ifdef F_114
F_119 ( V_147 ) ;
#endif
F_113 ( & V_29 ) ;
}
