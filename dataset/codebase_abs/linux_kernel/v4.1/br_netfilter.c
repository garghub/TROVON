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
static struct V_8 * F_7 ( const struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
static inline struct V_10 * F_8 ( const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_9 ( V_12 ) ;
return V_14 ? & V_14 -> V_15 -> V_16 : NULL ;
}
static inline struct V_11 * F_10 ( const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_9 ( V_12 ) ;
return V_14 ? V_14 -> V_15 -> V_12 : NULL ;
}
static inline struct V_8 * F_11 ( struct V_1 * V_2 )
{
V_2 -> V_9 = F_12 ( sizeof( struct V_8 ) , V_17 ) ;
if ( F_13 ( V_2 -> V_9 ) )
F_14 ( & ( V_2 -> V_9 -> V_18 ) , 1 ) ;
return V_2 -> V_9 ;
}
static inline struct V_8 * F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_16 ( & V_9 -> V_18 ) > 1 ) {
struct V_8 * V_19 = F_11 ( V_2 ) ;
if ( V_19 ) {
memcpy ( V_19 , V_9 , sizeof( struct V_8 ) ) ;
F_14 ( & V_19 -> V_18 , 1 ) ;
}
F_17 ( V_9 ) ;
V_9 = V_19 ;
}
return V_9 ;
}
static unsigned int F_18 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case F_19 ( V_4 ) :
return V_20 ;
case F_19 ( V_21 ) :
return V_22 ;
default:
return 0 ;
}
}
static inline void F_20 ( struct V_1 * V_2 )
{
unsigned int V_23 = F_18 ( V_2 ) ;
F_21 ( V_2 , V_23 ) ;
V_2 -> V_24 -= V_23 ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
unsigned int V_23 = F_18 ( V_2 ) ;
F_23 ( V_2 , V_23 ) ;
V_2 -> V_24 += V_23 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
unsigned int V_23 = F_18 ( V_2 ) ;
F_25 ( V_2 , V_23 ) ;
V_2 -> V_24 += V_23 ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_2 V_23 ;
if ( ! F_27 ( V_2 , sizeof( struct V_25 ) ) )
goto V_27;
V_26 = F_28 ( V_2 ) ;
if ( V_26 -> V_28 < 5 || V_26 -> V_29 != 4 )
goto V_27;
if ( ! F_27 ( V_2 , V_26 -> V_28 * 4 ) )
goto V_27;
V_26 = F_28 ( V_2 ) ;
if ( F_29 ( F_30 ( ( V_30 * ) V_26 , V_26 -> V_28 ) ) )
goto V_27;
V_23 = F_31 ( V_26 -> V_31 ) ;
if ( V_2 -> V_23 < V_23 ) {
F_32 ( F_33 ( V_12 ) , V_32 ) ;
goto V_33;
} else if ( V_23 < ( V_26 -> V_28 * 4 ) )
goto V_27;
if ( F_34 ( V_2 , V_23 ) ) {
F_32 ( F_33 ( V_12 ) , V_34 ) ;
goto V_33;
}
memset ( F_35 ( V_2 ) , 0 , sizeof( struct V_35 ) ) ;
return 0 ;
V_27:
F_32 ( F_33 ( V_12 ) , V_36 ) ;
V_33:
return - 1 ;
}
static void F_36 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 -> V_37 ) {
case V_38 :
V_2 -> V_3 = F_3 ( V_4 ) ;
break;
case V_39 :
V_2 -> V_3 = F_3 ( V_21 ) ;
break;
case V_40 :
break;
}
}
static int F_37 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_10 * V_43 ;
if ( V_9 -> V_44 ) {
V_2 -> V_45 = V_46 ;
V_9 -> V_44 = false ;
}
V_9 -> V_47 ^= V_48 ;
V_43 = F_8 ( V_9 -> V_49 ) ;
if ( ! V_43 ) {
F_38 ( V_2 ) ;
return 0 ;
}
F_39 ( V_2 , & V_43 -> V_50 ) ;
V_2 -> V_12 = V_9 -> V_49 ;
F_36 ( V_2 ) ;
F_20 ( V_2 ) ;
F_40 ( V_51 , V_52 , V_42 , V_2 ,
V_2 -> V_12 , NULL ,
V_53 , 1 ) ;
return 0 ;
}
static int F_41 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_54 * V_55 ;
struct V_56 * V_50 ;
V_2 -> V_12 = F_10 ( V_2 -> V_12 ) ;
if ( ! V_2 -> V_12 )
goto V_57;
V_50 = F_42 ( V_2 ) ;
V_55 = F_43 ( V_50 , V_2 ) ;
if ( V_55 ) {
struct V_8 * V_9 = F_7 ( V_2 ) ;
int V_58 ;
if ( V_55 -> V_59 . V_60 ) {
F_44 ( & V_55 -> V_59 , V_2 ) ;
V_2 -> V_12 = V_9 -> V_49 ;
V_58 = V_53 ( V_42 , V_2 ) ;
} else {
F_45 ( V_2 ,
- ( V_6 - V_61 ) ,
V_9 -> V_62 ,
V_6 - V_61 ) ;
V_9 -> V_47 |= V_63 ;
V_58 = V_55 -> V_64 ( V_55 , V_2 ) ;
}
F_46 ( V_55 ) ;
return V_58 ;
}
V_57:
F_38 ( V_2 ) ;
return 0 ;
}
static bool F_47 ( const struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
return F_28 ( V_2 ) -> V_65 != V_9 -> V_66 ;
}
static int F_48 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_25 * V_26 = F_28 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_10 * V_43 ;
int V_67 ;
int V_68 ;
V_68 = F_35 ( V_2 ) -> V_68 ;
F_49 ( V_2 ) -> V_68 = V_68 ;
if ( V_9 -> V_44 ) {
V_2 -> V_45 = V_46 ;
V_9 -> V_44 = false ;
}
V_9 -> V_47 ^= V_48 ;
if ( F_47 ( V_2 , V_9 ) ) {
if ( ( V_67 = F_50 ( V_2 , V_26 -> V_65 , V_26 -> V_69 , V_26 -> V_70 , V_12 ) ) ) {
struct V_71 * V_72 = F_51 ( V_12 ) ;
if ( V_67 != - V_73 || ! V_72 || F_52 ( V_72 ) )
goto V_57;
V_43 = F_53 ( F_33 ( V_12 ) , V_26 -> V_65 , 0 ,
F_54 ( V_26 -> V_70 ) , 0 ) ;
if ( ! F_55 ( V_43 ) ) {
if ( V_43 -> V_50 . V_12 == V_12 ) {
F_56 ( V_2 , & V_43 -> V_50 ) ;
goto V_74;
}
F_57 ( V_43 ) ;
}
V_57:
F_38 ( V_2 ) ;
return 0 ;
} else {
if ( F_42 ( V_2 ) -> V_12 == V_12 ) {
V_74:
V_2 -> V_12 = V_9 -> V_49 ;
F_36 ( V_2 ) ;
F_20 ( V_2 ) ;
F_40 ( V_51 ,
V_52 ,
V_42 , V_2 , V_2 -> V_12 , NULL ,
F_41 ,
1 ) ;
return 0 ;
}
F_58 ( F_59 ( V_2 ) -> V_75 , V_12 -> V_76 ) ;
V_2 -> V_45 = V_77 ;
}
} else {
V_43 = F_8 ( V_9 -> V_49 ) ;
if ( ! V_43 ) {
F_38 ( V_2 ) ;
return 0 ;
}
F_39 ( V_2 , & V_43 -> V_50 ) ;
}
V_2 -> V_12 = V_9 -> V_49 ;
F_36 ( V_2 ) ;
F_20 ( V_2 ) ;
F_40 ( V_51 , V_52 , V_42 , V_2 ,
V_2 -> V_12 , NULL ,
V_53 , 1 ) ;
return 0 ;
}
static struct V_11 * F_60 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
struct V_11 * V_78 , * V_15 ;
V_15 = F_10 ( V_12 ) ;
if ( V_79 == 0 || ! F_2 ( V_2 ) )
return V_15 ;
V_78 = F_61 ( V_15 , V_2 -> F_1 ,
F_62 ( V_2 ) & V_80 ) ;
return V_78 ? V_78 : V_15 ;
}
static struct V_11 * F_63 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_77 ;
V_9 -> V_44 = true ;
}
V_9 -> V_47 |= V_48 ;
V_9 -> V_49 = V_2 -> V_12 ;
V_2 -> V_12 = F_60 ( V_2 , V_2 -> V_12 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_9 -> V_37 = V_38 ;
else if ( V_2 -> V_3 == F_3 ( V_21 ) )
V_9 -> V_37 = V_39 ;
F_64 ( V_2 ) ;
return V_2 -> V_12 ;
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned char * V_81 = ( V_30 * ) ( F_66 ( V_2 ) + 1 ) ;
T_2 V_82 ;
const unsigned char * V_83 = F_67 ( V_2 ) ;
int V_84 = V_81 - V_83 ;
int V_23 = ( V_81 [ 1 ] + 1 ) << 3 ;
if ( ( V_81 + V_23 ) - V_2 -> V_85 > F_68 ( V_2 ) )
goto V_86;
V_84 += 2 ;
V_23 -= 2 ;
while ( V_23 > 0 ) {
int V_87 = V_83 [ V_84 + 1 ] + 2 ;
switch ( V_83 [ V_84 ] ) {
case V_88 :
V_87 = 1 ;
break;
case V_89 :
break;
case V_90 :
if ( V_83 [ V_84 + 1 ] != 4 || ( V_84 & 3 ) != 2 )
goto V_86;
V_82 = F_69 ( * ( V_91 * ) ( V_83 + V_84 + 2 ) ) ;
if ( V_82 <= V_92 ||
F_66 ( V_2 ) -> V_93 )
goto V_86;
if ( V_82 > V_2 -> V_23 - sizeof( struct V_94 ) )
goto V_86;
if ( F_34 ( V_2 ,
V_82 + sizeof( struct V_94 ) ) )
goto V_86;
V_83 = F_67 ( V_2 ) ;
break;
default:
if ( V_87 > V_23 )
goto V_86;
break;
}
V_84 += V_87 ;
V_23 -= V_87 ;
}
if ( V_23 == 0 )
return 0 ;
V_86:
return - 1 ;
}
static unsigned int F_70 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
const struct V_94 * V_99 ;
T_2 V_82 ;
if ( V_2 -> V_23 < sizeof( struct V_94 ) )
return V_100 ;
if ( ! F_27 ( V_2 , sizeof( struct V_94 ) ) )
return V_100 ;
V_99 = F_66 ( V_2 ) ;
if ( V_99 -> V_29 != 6 )
return V_100 ;
V_82 = F_31 ( V_99 -> V_93 ) ;
if ( V_82 || V_99 -> V_101 != V_102 ) {
if ( V_82 + sizeof( struct V_94 ) > V_2 -> V_23 )
return V_100 ;
if ( F_34 ( V_2 , V_82 + sizeof( struct V_94 ) ) )
return V_100 ;
}
if ( V_99 -> V_101 == V_102 && F_65 ( V_2 ) )
return V_100 ;
F_17 ( V_2 -> V_9 ) ;
if ( ! F_11 ( V_2 ) )
return V_100 ;
if ( ! F_63 ( V_2 ) )
return V_100 ;
V_2 -> V_3 = F_3 ( V_103 ) ;
F_71 ( V_104 , V_105 , V_98 -> V_42 , V_2 ,
V_2 -> V_12 , NULL ,
F_37 ) ;
return V_106 ;
}
static unsigned int F_72 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
struct V_8 * V_9 ;
struct V_13 * V_107 ;
struct V_108 * V_15 ;
T_3 V_23 = F_18 ( V_2 ) ;
if ( F_29 ( ! F_27 ( V_2 , V_23 ) ) )
return V_100 ;
V_107 = F_9 ( V_98 -> V_109 ) ;
if ( V_107 == NULL )
return V_100 ;
V_15 = V_107 -> V_15 ;
if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) ) {
if ( ! V_110 && ! V_15 -> V_111 )
return V_112 ;
F_24 ( V_2 ) ;
return F_70 ( V_96 , V_2 , V_98 ) ;
}
if ( ! V_113 && ! V_15 -> V_114 )
return V_112 ;
if ( ! F_76 ( V_2 ) && ! F_77 ( V_2 ) && ! F_78 ( V_2 ) )
return V_112 ;
F_24 ( V_2 ) ;
if ( F_26 ( V_2 ) )
return V_100 ;
F_17 ( V_2 -> V_9 ) ;
if ( ! F_11 ( V_2 ) )
return V_100 ;
if ( ! F_63 ( V_2 ) )
return V_100 ;
V_9 = F_7 ( V_2 ) ;
V_9 -> V_66 = F_28 ( V_2 ) -> V_65 ;
V_2 -> V_3 = F_3 ( V_115 ) ;
F_71 ( V_116 , V_105 , V_98 -> V_42 , V_2 ,
V_2 -> V_12 , NULL ,
F_48 ) ;
return V_106 ;
}
static unsigned int F_79 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
F_80 ( V_2 ) ;
return V_112 ;
}
static int F_81 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_11 * V_109 ;
if ( ! F_82 ( V_2 ) && ! F_83 ( V_2 ) ) {
int V_68 ;
if ( V_2 -> V_3 == F_3 ( V_115 ) ) {
V_68 = F_35 ( V_2 ) -> V_68 ;
F_49 ( V_2 ) -> V_68 = V_68 ;
}
V_109 = V_9 -> V_49 ;
if ( V_9 -> V_44 ) {
V_2 -> V_45 = V_46 ;
V_9 -> V_44 = false ;
}
F_36 ( V_2 ) ;
} else {
V_109 = * ( (struct V_11 * * ) ( V_2 -> V_117 ) ) ;
}
F_20 ( V_2 ) ;
F_40 ( V_51 , V_118 , V_42 , V_2 ,
V_109 , V_2 -> V_12 , V_119 , 1 ) ;
return 0 ;
}
static unsigned int F_84 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
struct V_8 * V_9 ;
struct V_11 * V_120 ;
T_4 V_121 ;
if ( ! V_2 -> V_9 )
return V_112 ;
if ( ! F_15 ( V_2 ) )
return V_100 ;
V_9 = F_7 ( V_2 ) ;
if ( ! V_9 )
return V_100 ;
V_120 = F_10 ( V_98 -> V_122 ) ;
if ( ! V_120 )
return V_100 ;
if ( F_76 ( V_2 ) || F_77 ( V_2 ) || F_78 ( V_2 ) )
V_121 = V_116 ;
else if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) )
V_121 = V_104 ;
else
return V_112 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_77 ;
V_9 -> V_44 = true ;
}
if ( V_121 == V_116 ) {
int V_123 = F_49 ( V_2 ) -> V_68 ;
if ( F_26 ( V_2 ) )
return V_100 ;
F_35 ( V_2 ) -> V_68 = V_123 ;
}
V_9 -> V_124 = V_2 -> V_12 ;
if ( V_121 == V_116 )
V_2 -> V_3 = F_3 ( V_115 ) ;
else
V_2 -> V_3 = F_3 ( V_103 ) ;
F_71 ( V_121 , V_125 , NULL , V_2 ,
F_60 ( V_2 , V_98 -> V_109 ) ,
V_120 , F_81 ) ;
return V_106 ;
}
static unsigned int F_85 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
struct V_13 * V_107 ;
struct V_108 * V_15 ;
struct V_11 * * V_126 = (struct V_11 * * ) ( V_2 -> V_117 ) ;
V_107 = F_9 ( V_98 -> V_122 ) ;
if ( V_107 == NULL )
return V_112 ;
V_15 = V_107 -> V_15 ;
if ( ! V_127 && ! V_15 -> V_128 )
return V_112 ;
if ( ! F_82 ( V_2 ) ) {
if ( ! F_83 ( V_2 ) )
return V_112 ;
F_22 ( V_2 ) ;
}
if ( F_86 ( V_2 ) -> V_129 != 4 ) {
if ( F_83 ( V_2 ) )
F_20 ( V_2 ) ;
return V_112 ;
}
* V_126 = V_98 -> V_109 ;
F_71 ( V_130 , V_131 , V_98 -> V_42 , V_2 ,
V_98 -> V_109 , V_98 -> V_122 , F_81 ) ;
return V_106 ;
}
static int F_87 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
struct V_132 * V_85 ;
int V_67 ;
V_85 = F_88 ( & V_133 ) ;
V_67 = F_89 ( V_2 , V_85 -> V_134 ) ;
if ( V_67 ) {
F_38 ( V_2 ) ;
return 0 ;
}
F_90 ( V_2 , - V_85 -> V_134 , V_85 -> V_135 , V_85 -> V_134 ) ;
F_91 ( V_2 , V_85 -> V_136 ) ;
return F_92 ( V_42 , V_2 ) ;
}
static int F_93 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
int V_58 ;
int V_68 ;
unsigned int V_137 ;
if ( F_94 ( V_2 ) || V_2 -> V_3 != F_3 ( V_115 ) )
return F_92 ( V_42 , V_2 ) ;
V_137 = F_95 ( V_2 ) ;
if ( V_2 -> V_23 + V_137 > V_2 -> V_12 -> V_138 ) {
struct V_132 * V_85 ;
V_68 = F_49 ( V_2 ) -> V_68 ;
if ( F_26 ( V_2 ) )
return V_100 ;
F_35 ( V_2 ) -> V_68 = V_68 ;
F_36 ( V_2 ) ;
V_85 = F_88 ( & V_133 ) ;
V_85 -> V_136 = F_18 ( V_2 ) ;
V_85 -> V_134 = V_6 + V_85 -> V_136 ;
F_45 ( V_2 , - V_85 -> V_134 , V_85 -> V_135 ,
V_85 -> V_134 ) ;
V_58 = F_96 ( V_42 , V_2 , F_87 ) ;
} else {
V_58 = F_92 ( V_42 , V_2 ) ;
}
return V_58 ;
}
static int F_93 ( struct V_41 * V_42 , struct V_1 * V_2 )
{
return F_92 ( V_42 , V_2 ) ;
}
static unsigned int F_97 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_11 * V_139 = F_10 ( V_2 -> V_12 ) ;
T_4 V_121 ;
if ( ! V_9 || ! V_9 -> V_124 )
return V_112 ;
if ( ! V_139 )
return V_100 ;
if ( F_76 ( V_2 ) || F_77 ( V_2 ) || F_78 ( V_2 ) )
V_121 = V_116 ;
else if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) )
V_121 = V_104 ;
else
return V_112 ;
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_77 ;
V_9 -> V_44 = true ;
}
F_22 ( V_2 ) ;
if ( V_121 == V_116 )
V_2 -> V_3 = F_3 ( V_115 ) ;
else
V_2 -> V_3 = F_3 ( V_103 ) ;
F_71 ( V_121 , V_140 , V_98 -> V_42 , V_2 ,
NULL , V_139 ,
F_93 ) ;
return V_106 ;
}
static unsigned int F_98 ( const struct V_95 * V_96 ,
struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
if ( V_2 -> V_9 &&
! ( V_2 -> V_9 -> V_47 & V_48 ) ) {
return V_141 ;
}
return V_112 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_23 ( V_2 , V_6 ) ;
V_9 -> V_47 &= ~ V_63 ;
F_100 ( sizeof( V_9 -> V_62 ) != ( V_6 - V_61 ) ) ;
F_90 ( V_2 , - ( V_6 - V_61 ) ,
V_9 -> V_62 ,
V_6 - V_61 ) ;
V_2 -> V_12 = V_9 -> V_49 ;
V_53 ( NULL , V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 && ( V_2 -> V_9 -> V_47 & V_63 ) ) {
F_99 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_102 ( void )
{
}
static
int F_103 ( struct V_142 * V_143 , int V_144 ,
void T_5 * V_145 , T_6 * V_146 , T_7 * V_147 )
{
int V_58 ;
V_58 = F_104 ( V_143 , V_144 , V_145 , V_146 , V_147 ) ;
if ( V_144 && * ( int * ) ( V_143 -> V_85 ) )
* ( int * ) ( V_143 -> V_85 ) = 1 ;
return V_58 ;
}
static int T_8 F_105 ( void )
{
int V_58 ;
V_58 = F_106 ( V_148 , F_107 ( V_148 ) ) ;
if ( V_58 < 0 )
return V_58 ;
#ifdef F_108
V_149 = F_109 ( & V_150 , L_1 , V_151 ) ;
if ( V_149 == NULL ) {
F_110 ( V_152
L_2 ) ;
F_111 ( V_148 , F_107 ( V_148 ) ) ;
return - V_153 ;
}
#endif
F_112 ( V_154 , & V_155 ) ;
F_110 ( V_156 L_3 ) ;
return 0 ;
}
static void T_9 F_113 ( void )
{
F_112 ( V_154 , NULL ) ;
F_111 ( V_148 , F_107 ( V_148 ) ) ;
#ifdef F_108
F_114 ( V_149 ) ;
#endif
}
