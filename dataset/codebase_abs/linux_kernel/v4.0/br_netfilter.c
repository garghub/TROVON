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
static inline struct V_8 * F_7 ( const struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_8 ( V_10 ) ;
return V_12 ? & V_12 -> V_13 -> V_14 : NULL ;
}
static inline struct V_9 * F_9 ( const struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_8 ( V_10 ) ;
return V_12 ? V_12 -> V_13 -> V_10 : NULL ;
}
static inline struct V_15 * F_10 ( struct V_1 * V_2 )
{
V_2 -> V_16 = F_11 ( sizeof( struct V_15 ) , V_17 ) ;
if ( F_12 ( V_2 -> V_16 ) )
F_13 ( & ( V_2 -> V_16 -> V_18 ) , 1 ) ;
return V_2 -> V_16 ;
}
static inline struct V_15 * F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_15 ( & V_16 -> V_18 ) > 1 ) {
struct V_15 * V_19 = F_10 ( V_2 ) ;
if ( V_19 ) {
memcpy ( V_19 , V_16 , sizeof( struct V_15 ) ) ;
F_13 ( & V_19 -> V_18 , 1 ) ;
}
F_16 ( V_16 ) ;
V_16 = V_19 ;
}
return V_16 ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
unsigned int V_20 = F_18 ( V_2 ) ;
F_19 ( V_2 , V_20 ) ;
V_2 -> V_21 -= V_20 ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
unsigned int V_20 = F_18 ( V_2 ) ;
F_21 ( V_2 , V_20 ) ;
V_2 -> V_21 += V_20 ;
}
static inline void F_22 ( struct V_1 * V_2 )
{
unsigned int V_20 = F_18 ( V_2 ) ;
F_23 ( V_2 , V_20 ) ;
V_2 -> V_21 += V_20 ;
}
static inline void F_24 ( struct V_1 * V_2 )
{
int V_22 = V_6 + F_18 ( V_2 ) ;
F_25 ( V_2 , - V_22 ,
V_2 -> V_16 -> V_23 , V_22 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_24 * V_25 ;
struct V_9 * V_10 = V_2 -> V_10 ;
T_2 V_20 ;
if ( ! F_27 ( V_2 , sizeof( struct V_24 ) ) )
goto V_26;
V_25 = F_28 ( V_2 ) ;
if ( V_25 -> V_27 < 5 || V_25 -> V_28 != 4 )
goto V_26;
if ( ! F_27 ( V_2 , V_25 -> V_27 * 4 ) )
goto V_26;
V_25 = F_28 ( V_2 ) ;
if ( F_29 ( F_30 ( ( V_29 * ) V_25 , V_25 -> V_27 ) ) )
goto V_26;
V_20 = F_31 ( V_25 -> V_30 ) ;
if ( V_2 -> V_20 < V_20 ) {
F_32 ( F_33 ( V_10 ) , V_31 ) ;
goto V_32;
} else if ( V_20 < ( V_25 -> V_27 * 4 ) )
goto V_26;
if ( F_34 ( V_2 , V_20 ) ) {
F_32 ( F_33 ( V_10 ) , V_33 ) ;
goto V_32;
}
memset ( F_35 ( V_2 ) , 0 , sizeof( struct V_34 ) ) ;
return 0 ;
V_26:
F_32 ( F_33 ( V_10 ) , V_35 ) ;
V_32:
return - 1 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_8 * V_36 ;
if ( V_16 -> V_37 & V_38 ) {
V_2 -> V_39 = V_40 ;
V_16 -> V_37 ^= V_38 ;
}
V_16 -> V_37 ^= V_41 ;
V_36 = F_7 ( V_16 -> V_42 ) ;
if ( ! V_36 ) {
F_37 ( V_2 ) ;
return 0 ;
}
F_38 ( V_2 , & V_36 -> V_43 ) ;
V_2 -> V_10 = V_16 -> V_42 ;
F_39 ( V_2 ) ;
F_17 ( V_2 ) ;
F_40 ( V_44 , V_45 , V_2 , V_2 -> V_10 , NULL ,
V_46 , 1 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_47 * V_48 ;
struct V_49 * V_43 ;
V_2 -> V_10 = F_9 ( V_2 -> V_10 ) ;
if ( ! V_2 -> V_10 )
goto V_50;
V_43 = F_42 ( V_2 ) ;
V_48 = F_43 ( V_43 , V_2 ) ;
if ( V_48 ) {
int V_51 ;
if ( V_48 -> V_52 . V_53 ) {
F_44 ( & V_48 -> V_52 , V_2 ) ;
V_2 -> V_10 = V_16 -> V_42 ;
V_51 = V_46 ( V_2 ) ;
} else {
F_25 ( V_2 ,
- ( V_6 - V_54 ) ,
V_2 -> V_16 -> V_23 ,
V_6 - V_54 ) ;
V_16 -> V_37 |= V_55 ;
V_51 = V_48 -> V_56 ( V_48 , V_2 ) ;
}
F_45 ( V_48 ) ;
return V_51 ;
}
V_50:
F_37 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_24 * V_25 = F_28 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_8 * V_36 ;
int V_57 ;
int V_58 ;
V_58 = F_35 ( V_2 ) -> V_58 ;
F_47 ( V_2 ) -> V_58 = V_58 ;
if ( V_16 -> V_37 & V_38 ) {
V_2 -> V_39 = V_40 ;
V_16 -> V_37 ^= V_38 ;
}
V_16 -> V_37 ^= V_41 ;
if ( F_48 ( V_2 ) ) {
if ( ( V_57 = F_49 ( V_2 , V_25 -> V_59 , V_25 -> V_60 , V_25 -> V_61 , V_10 ) ) ) {
struct V_62 * V_63 = F_50 ( V_10 ) ;
if ( V_57 != - V_64 || ! V_63 || F_51 ( V_63 ) )
goto V_50;
V_36 = F_52 ( F_33 ( V_10 ) , V_25 -> V_59 , 0 ,
F_53 ( V_25 -> V_61 ) , 0 ) ;
if ( ! F_54 ( V_36 ) ) {
if ( V_36 -> V_43 . V_10 == V_10 ) {
F_55 ( V_2 , & V_36 -> V_43 ) ;
goto V_65;
}
F_56 ( V_36 ) ;
}
V_50:
F_37 ( V_2 ) ;
return 0 ;
} else {
if ( F_42 ( V_2 ) -> V_10 == V_10 ) {
V_65:
V_2 -> V_10 = V_16 -> V_42 ;
F_39 ( V_2 ) ;
F_17 ( V_2 ) ;
F_40 ( V_44 ,
V_45 ,
V_2 , V_2 -> V_10 , NULL ,
F_41 ,
1 ) ;
return 0 ;
}
F_57 ( F_58 ( V_2 ) -> V_66 , V_10 -> V_67 ) ;
V_2 -> V_39 = V_68 ;
}
} else {
V_36 = F_7 ( V_16 -> V_42 ) ;
if ( ! V_36 ) {
F_37 ( V_2 ) ;
return 0 ;
}
F_38 ( V_2 , & V_36 -> V_43 ) ;
}
V_2 -> V_10 = V_16 -> V_42 ;
F_39 ( V_2 ) ;
F_17 ( V_2 ) ;
F_40 ( V_44 , V_45 , V_2 , V_2 -> V_10 , NULL ,
V_46 , 1 ) ;
return 0 ;
}
static struct V_9 * F_59 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_9 * V_69 , * V_13 ;
V_13 = F_9 ( V_10 ) ;
if ( V_70 == 0 || ! F_2 ( V_2 ) )
return V_13 ;
V_69 = F_60 ( V_13 , V_2 -> F_1 ,
F_61 ( V_2 ) & V_71 ) ;
return V_69 ? V_69 : V_13 ;
}
static struct V_9 * F_62 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_2 -> V_39 == V_40 ) {
V_2 -> V_39 = V_68 ;
V_16 -> V_37 |= V_38 ;
}
V_16 -> V_37 |= V_41 ;
V_16 -> V_42 = V_2 -> V_10 ;
V_2 -> V_10 = F_59 ( V_2 , V_2 -> V_10 ) ;
if ( V_2 -> V_3 == F_3 ( V_4 ) )
V_16 -> V_37 |= V_72 ;
else if ( V_2 -> V_3 == F_3 ( V_73 ) )
V_16 -> V_37 |= V_74 ;
F_63 ( V_2 ) ;
return V_2 -> V_10 ;
}
static int F_64 ( struct V_1 * V_2 )
{
unsigned char * V_75 = ( V_29 * ) ( F_65 ( V_2 ) + 1 ) ;
T_2 V_76 ;
const unsigned char * V_77 = F_66 ( V_2 ) ;
int V_78 = V_75 - V_77 ;
int V_20 = ( V_75 [ 1 ] + 1 ) << 3 ;
if ( ( V_75 + V_20 ) - V_2 -> V_23 > F_67 ( V_2 ) )
goto V_79;
V_78 += 2 ;
V_20 -= 2 ;
while ( V_20 > 0 ) {
int V_80 = V_77 [ V_78 + 1 ] + 2 ;
switch ( V_77 [ V_78 ] ) {
case V_81 :
V_80 = 1 ;
break;
case V_82 :
break;
case V_83 :
if ( V_77 [ V_78 + 1 ] != 4 || ( V_78 & 3 ) != 2 )
goto V_79;
V_76 = F_68 ( * ( V_84 * ) ( V_77 + V_78 + 2 ) ) ;
if ( V_76 <= V_85 ||
F_65 ( V_2 ) -> V_86 )
goto V_79;
if ( V_76 > V_2 -> V_20 - sizeof( struct V_87 ) )
goto V_79;
if ( F_34 ( V_2 ,
V_76 + sizeof( struct V_87 ) ) )
goto V_79;
V_77 = F_66 ( V_2 ) ;
break;
default:
if ( V_80 > V_20 )
goto V_79;
break;
}
V_78 += V_80 ;
V_20 -= V_80 ;
}
if ( V_20 == 0 )
return 0 ;
V_79:
return - 1 ;
}
static unsigned int F_69 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
const struct V_87 * V_92 ;
T_2 V_76 ;
if ( V_2 -> V_20 < sizeof( struct V_87 ) )
return V_93 ;
if ( ! F_27 ( V_2 , sizeof( struct V_87 ) ) )
return V_93 ;
V_92 = F_65 ( V_2 ) ;
if ( V_92 -> V_28 != 6 )
return V_93 ;
V_76 = F_31 ( V_92 -> V_86 ) ;
if ( V_76 || V_92 -> V_94 != V_95 ) {
if ( V_76 + sizeof( struct V_87 ) > V_2 -> V_20 )
return V_93 ;
if ( F_34 ( V_2 , V_76 + sizeof( struct V_87 ) ) )
return V_93 ;
}
if ( V_92 -> V_94 == V_95 && F_64 ( V_2 ) )
return V_93 ;
F_16 ( V_2 -> V_16 ) ;
if ( ! F_10 ( V_2 ) )
return V_93 ;
if ( ! F_62 ( V_2 ) )
return V_93 ;
V_2 -> V_3 = F_3 ( V_96 ) ;
F_71 ( V_97 , V_98 , V_2 , V_2 -> V_10 , NULL ,
F_36 ) ;
return V_99 ;
}
static unsigned int F_72 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
struct V_11 * V_100 ;
struct V_101 * V_13 ;
T_3 V_20 = F_18 ( V_2 ) ;
if ( F_29 ( ! F_27 ( V_2 , V_20 ) ) )
return V_93 ;
V_100 = F_8 ( V_90 ) ;
if ( V_100 == NULL )
return V_93 ;
V_13 = V_100 -> V_13 ;
if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) ) {
if ( ! V_102 && ! V_13 -> V_103 )
return V_104 ;
F_22 ( V_2 ) ;
return F_69 ( V_89 , V_2 , V_90 , V_91 , F_70 ) ;
}
if ( ! V_105 && ! V_13 -> V_106 )
return V_104 ;
if ( ! F_76 ( V_2 ) && ! F_77 ( V_2 ) && ! F_78 ( V_2 ) )
return V_104 ;
F_22 ( V_2 ) ;
if ( F_26 ( V_2 ) )
return V_93 ;
F_16 ( V_2 -> V_16 ) ;
if ( ! F_10 ( V_2 ) )
return V_93 ;
if ( ! F_62 ( V_2 ) )
return V_93 ;
F_79 ( V_2 ) ;
V_2 -> V_3 = F_3 ( V_107 ) ;
F_71 ( V_108 , V_98 , V_2 , V_2 -> V_10 , NULL ,
F_46 ) ;
return V_99 ;
}
static unsigned int F_80 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
F_81 ( V_2 ) ;
return V_104 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_9 * V_90 ;
if ( ! F_83 ( V_2 ) && ! F_84 ( V_2 ) ) {
V_90 = V_16 -> V_42 ;
if ( V_16 -> V_37 & V_38 ) {
V_2 -> V_39 = V_40 ;
V_16 -> V_37 ^= V_38 ;
}
F_39 ( V_2 ) ;
} else {
V_90 = * ( (struct V_9 * * ) ( V_2 -> V_109 ) ) ;
}
F_17 ( V_2 ) ;
F_40 ( V_44 , V_110 , V_2 , V_90 ,
V_2 -> V_10 , V_111 , 1 ) ;
return 0 ;
}
static unsigned int F_85 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
struct V_15 * V_16 ;
struct V_9 * V_112 ;
T_4 V_113 ;
if ( ! V_2 -> V_16 )
return V_104 ;
if ( ! F_14 ( V_2 ) )
return V_93 ;
V_112 = F_9 ( V_91 ) ;
if ( ! V_112 )
return V_93 ;
if ( F_76 ( V_2 ) || F_77 ( V_2 ) || F_78 ( V_2 ) )
V_113 = V_108 ;
else if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) )
V_113 = V_97 ;
else
return V_104 ;
F_20 ( V_2 ) ;
V_16 = V_2 -> V_16 ;
if ( V_2 -> V_39 == V_40 ) {
V_2 -> V_39 = V_68 ;
V_16 -> V_37 |= V_38 ;
}
if ( V_113 == V_108 && F_26 ( V_2 ) )
return V_93 ;
V_16 -> V_37 |= V_114 ;
V_16 -> V_115 = V_2 -> V_10 ;
if ( V_113 == V_108 )
V_2 -> V_3 = F_3 ( V_107 ) ;
else
V_2 -> V_3 = F_3 ( V_96 ) ;
F_71 ( V_113 , V_116 , V_2 , F_59 ( V_2 , V_90 ) , V_112 ,
F_82 ) ;
return V_99 ;
}
static unsigned int F_86 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
struct V_11 * V_100 ;
struct V_101 * V_13 ;
struct V_9 * * V_117 = (struct V_9 * * ) ( V_2 -> V_109 ) ;
V_100 = F_8 ( V_91 ) ;
if ( V_100 == NULL )
return V_104 ;
V_13 = V_100 -> V_13 ;
if ( ! V_118 && ! V_13 -> V_119 )
return V_104 ;
if ( ! F_83 ( V_2 ) ) {
if ( ! F_84 ( V_2 ) )
return V_104 ;
F_20 ( V_2 ) ;
}
if ( F_87 ( V_2 ) -> V_120 != 4 ) {
if ( F_84 ( V_2 ) )
F_17 ( V_2 ) ;
return V_104 ;
}
* V_117 = (struct V_9 * ) V_90 ;
F_71 ( V_121 , V_122 , V_2 , (struct V_9 * ) V_90 ,
(struct V_9 * ) V_91 , F_82 ) ;
return V_99 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_51 ;
int V_58 ;
if ( V_2 -> V_3 == F_3 ( V_107 ) &&
V_2 -> V_20 + F_89 ( V_2 ) > V_2 -> V_10 -> V_123 &&
! F_90 ( V_2 ) ) {
V_58 = F_47 ( V_2 ) -> V_58 ;
if ( F_26 ( V_2 ) )
return V_93 ;
F_35 ( V_2 ) -> V_58 = V_58 ;
V_51 = F_91 ( V_2 , V_124 ) ;
} else
V_51 = V_124 ( V_2 ) ;
return V_51 ;
}
static int F_88 ( struct V_1 * V_2 )
{
return V_124 ( V_2 ) ;
}
static unsigned int F_92 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_9 * V_125 = F_9 ( V_2 -> V_10 ) ;
T_4 V_113 ;
if ( ! V_16 || ! ( V_16 -> V_37 & V_114 ) )
return V_104 ;
if ( ! V_125 )
return V_93 ;
if ( F_76 ( V_2 ) || F_77 ( V_2 ) || F_78 ( V_2 ) )
V_113 = V_108 ;
else if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_75 ( V_2 ) )
V_113 = V_97 ;
else
return V_104 ;
if ( V_2 -> V_39 == V_40 ) {
V_2 -> V_39 = V_68 ;
V_16 -> V_37 |= V_38 ;
}
F_20 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_113 == V_108 )
V_2 -> V_3 = F_3 ( V_107 ) ;
else
V_2 -> V_3 = F_3 ( V_96 ) ;
F_71 ( V_113 , V_126 , V_2 , NULL , V_125 ,
F_88 ) ;
return V_99 ;
}
static unsigned int F_93 ( const struct V_88 * V_89 ,
struct V_1 * V_2 ,
const struct V_9 * V_90 ,
const struct V_9 * V_91 ,
int (* F_70)( struct V_1 * ) )
{
if ( V_2 -> V_16 &&
! ( V_2 -> V_16 -> V_37 & V_41 ) ) {
return V_127 ;
}
return V_104 ;
}
void F_94 ( void )
{
}
static
int F_95 ( struct V_128 * V_129 , int V_130 ,
void T_5 * V_131 , T_6 * V_132 , T_7 * V_133 )
{
int V_51 ;
V_51 = F_96 ( V_129 , V_130 , V_131 , V_132 , V_133 ) ;
if ( V_130 && * ( int * ) ( V_129 -> V_23 ) )
* ( int * ) ( V_129 -> V_23 ) = 1 ;
return V_51 ;
}
static int T_8 F_97 ( void )
{
int V_51 ;
V_51 = F_98 ( V_134 , F_99 ( V_134 ) ) ;
if ( V_51 < 0 )
return V_51 ;
#ifdef F_100
V_135 = F_101 ( & V_136 , L_1 , V_137 ) ;
if ( V_135 == NULL ) {
F_102 ( V_138
L_2 ) ;
F_103 ( V_134 , F_99 ( V_134 ) ) ;
return - V_139 ;
}
#endif
F_102 ( V_140 L_3 ) ;
return 0 ;
}
static void T_9 F_104 ( void )
{
F_103 ( V_134 , F_99 ( V_134 ) ) ;
#ifdef F_100
F_105 ( V_135 ) ;
#endif
}
