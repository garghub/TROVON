static inline
struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = V_2 + 1 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 + 1 ;
struct V_6 * V_8 ;
struct V_1 * V_9 ;
int V_10 ;
if ( V_2 >= V_4 -> V_11 ) {
V_9 = V_4 -> V_11 ;
V_10 = V_4 -> V_12 ;
V_8 = (struct V_6 * ) V_4 -> V_11 ;
} else {
V_9 = V_4 -> V_13 ;
V_10 = V_4 -> V_14 ;
V_8 = (struct V_6 * ) V_4 -> V_13 ;
}
if ( V_4 -> V_6 )
return (struct V_1 * ) ( ( V_7 >= ( V_8 + V_10 ) ) ?
V_8 : V_7 ) ;
else
return ( V_5 >= ( V_9 + V_10 ) ) ?
V_9 : V_5 ;
}
static inline
struct V_1 * F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = V_2 - 1 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 - 1 ;
struct V_6 * V_8 ;
struct V_1 * V_9 ;
int V_10 ;
if ( V_2 >= V_4 -> V_11 ) {
V_9 = V_4 -> V_11 ;
V_10 = V_4 -> V_12 ;
V_8 = (struct V_6 * ) V_4 -> V_11 ;
} else {
V_9 = V_4 -> V_13 ;
V_10 = V_4 -> V_14 ;
V_8 = (struct V_6 * ) V_4 -> V_13 ;
}
if ( V_4 -> V_6 )
return (struct V_1 * ) ( ( V_7 < V_8 ) ?
( V_7 + V_10 ) : V_7 ) ;
else
return ( V_5 < V_9 ) ? ( V_5 + V_10 ) : V_5 ;
}
static int F_3 ( struct V_1 * V_9 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( ( const char * ) V_2 - ( const char * ) V_9 ) / V_4 -> V_15 ;
}
static int F_4 ( struct V_3 * V_4 )
{
int V_16 ;
V_16 = ( ( const char * ) V_4 -> V_17 -
( const char * ) V_4 -> V_18 ) / V_4 -> V_15 - 1 ;
return V_16 > 0 ? V_16 : V_16 + V_4 -> V_12 ;
}
static void * F_5 ( void * V_19 , int V_20 )
{
int V_21 ;
unsigned int * V_22 = V_19 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_20 , 4 ) ; V_21 ++ , V_22 ++ )
* V_22 = F_7 ( * V_22 ) ;
return V_19 ;
}
static inline bool F_8 ( struct V_23 * V_24 )
{
return V_24 -> V_25 == F_9 ( V_26 ) && F_10 ( V_24 ) -> V_27 == 4 ;
}
static int
F_11 ( struct V_23 * V_24 , struct V_28 * V_29 )
{
if ( V_24 -> V_30 != V_31 )
return 0 ;
if ( F_12 ( F_13 ( V_24 , 0 ) ) )
return - 1 ;
if ( F_8 ( V_24 ) )
F_10 ( V_24 ) -> V_32 = 0 ;
* ( V_33 * ) ( V_24 -> V_34 + V_24 -> V_35 + V_24 -> V_36 ) = 0 ;
return 0 ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_1 * V_40 ;
V_40 = F_2 ( V_2 , V_4 ) ;
if ( ( V_38 -> V_41 & V_42 ) &&
! ( V_40 -> V_43 & V_44 ) ) {
V_4 -> V_45 . V_46 = true ;
F_16 ( & ( V_4 -> V_45 . V_45 ) ,
F_17 ( 1 ) ) ;
}
}
static int
F_18 ( struct V_23 * V_24 , struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_6 * V_47 ;
int V_48 = F_20 ( V_24 ) -> V_48 ;
int V_49 , V_50 ;
unsigned short V_51 ;
unsigned int V_52 = 0 ;
T_1 * V_53 ;
unsigned int V_54 ;
void * V_19 ;
int V_21 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_53 = & F_20 ( V_24 ) -> V_55 [ V_49 ] ;
V_2 = F_1 ( V_2 , V_4 ) ;
V_47 = (struct V_6 * ) V_2 ;
V_51 = V_2 -> V_43 ;
V_51 &= ~ V_56 ;
V_51 |= ( V_57 | V_44 ) ;
V_50 = F_20 ( V_24 ) -> V_55 [ V_49 ] . V_58 ;
if ( V_49 == V_48 - 1 ) {
V_51 |= ( V_59 | V_60 ) ;
if ( V_4 -> V_6 ) {
V_52 |= V_61 ;
if ( F_12 ( F_20 ( V_24 ) -> V_62 &
V_63 && V_4 -> V_64 ) )
V_52 |= V_65 ;
}
}
if ( V_4 -> V_6 ) {
if ( V_24 -> V_30 == V_31 )
V_52 |= V_66 | V_67 ;
V_47 -> V_68 = 0 ;
V_47 -> V_69 = V_52 ;
}
V_19 = F_21 ( V_53 -> V_70 . V_71 ) + V_53 -> V_72 ;
V_54 = F_3 ( V_4 -> V_11 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_19 ) & V_73 ||
V_38 -> V_41 & V_74 ) {
memcpy ( V_4 -> V_75 [ V_54 ] , V_19 , V_50 ) ;
V_19 = V_4 -> V_75 [ V_54 ] ;
if ( V_38 -> V_41 & V_74 )
F_5 ( V_19 , V_50 ) ;
}
V_2 -> V_76 = F_22 ( & V_4 -> V_39 -> V_77 , V_19 ,
V_50 , V_78 ) ;
if ( F_23 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ) ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_1 ) ;
goto F_23;
}
V_2 -> V_79 = V_50 ;
V_2 -> V_43 = V_51 ;
}
V_4 -> V_18 = V_2 ;
return 0 ;
F_23:
V_2 = V_4 -> V_18 ;
for ( V_21 = 0 ; V_21 < V_49 ; V_21 ++ ) {
V_2 = F_1 ( V_2 , V_4 ) ;
F_27 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ,
V_2 -> V_79 , V_78 ) ;
}
return V_80 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
int V_48 = F_20 ( V_24 ) -> V_48 ;
struct V_1 * V_2 , * V_81 ;
void * V_19 ;
unsigned short V_51 ;
unsigned short V_82 ;
unsigned int V_52 = 0 ;
unsigned int V_54 ;
int V_83 ;
int V_84 ;
V_83 = F_4 ( V_4 ) ;
if ( V_83 < V_85 + 1 ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_2 ) ;
return V_80 ;
}
if ( F_11 ( V_24 , V_29 ) ) {
F_24 ( V_24 ) ;
return V_80 ;
}
V_2 = V_4 -> V_18 ;
V_51 = V_2 -> V_43 ;
V_51 &= ~ V_56 ;
V_19 = V_24 -> V_86 ;
V_82 = F_29 ( V_24 ) ;
V_54 = F_3 ( V_4 -> V_11 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_19 ) & V_73 ||
V_38 -> V_41 & V_74 ) {
memcpy ( V_4 -> V_75 [ V_54 ] , V_24 -> V_86 , V_82 ) ;
V_19 = V_4 -> V_75 [ V_54 ] ;
if ( V_38 -> V_41 & V_74 )
F_5 ( V_19 , V_82 ) ;
}
V_2 -> V_76 = F_22 ( & V_4 -> V_39 -> V_77 , V_19 ,
V_82 , V_78 ) ;
if ( F_23 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ) ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_1 ) ;
return V_80 ;
}
if ( V_48 ) {
V_84 = F_18 ( V_24 , V_29 ) ;
if ( V_84 )
return V_84 ;
} else {
V_51 |= ( V_59 | V_60 ) ;
if ( V_4 -> V_6 ) {
V_52 = V_61 ;
if ( F_12 ( F_20 ( V_24 ) -> V_62 &
V_63 && V_4 -> V_64 ) )
V_52 |= V_65 ;
}
}
if ( V_4 -> V_6 ) {
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
if ( F_12 ( F_20 ( V_24 ) -> V_62 & V_63 &&
V_4 -> V_64 ) )
F_20 ( V_24 ) -> V_62 |= V_87 ;
if ( V_24 -> V_30 == V_31 )
V_52 |= V_66 | V_67 ;
V_47 -> V_68 = 0 ;
V_47 -> V_69 = V_52 ;
}
V_81 = V_4 -> V_18 ;
V_54 = F_3 ( V_4 -> V_11 , V_81 , V_4 ) ;
V_4 -> V_88 [ V_54 ] = V_24 ;
V_2 -> V_79 = V_82 ;
V_51 |= ( V_44 | V_57 ) ;
V_2 -> V_43 = V_51 ;
F_14 ( V_2 , V_4 ) ;
V_2 = F_1 ( V_81 , V_4 ) ;
F_30 ( V_24 ) ;
V_4 -> V_18 = V_2 ;
F_31 ( 0 , V_4 -> V_89 + V_90 ) ;
return 0 ;
}
static int
F_32 ( struct V_23 * V_24 , struct V_28 * V_29 ,
struct V_1 * V_2 , int V_54 , char * V_86 ,
int V_58 , bool V_91 , bool V_92 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
unsigned short V_51 ;
unsigned int V_52 = 0 ;
V_51 = V_2 -> V_43 ;
V_51 &= ~ V_56 ;
V_51 |= ( V_57 | V_44 ) ;
V_2 -> V_79 = V_58 ;
if ( ( ( unsigned long ) V_86 ) & V_73 ||
V_38 -> V_41 & V_74 ) {
memcpy ( V_4 -> V_75 [ V_54 ] , V_86 , V_58 ) ;
V_86 = V_4 -> V_75 [ V_54 ] ;
if ( V_38 -> V_41 & V_74 )
F_5 ( V_86 , V_58 ) ;
}
V_2 -> V_76 = F_22 ( & V_4 -> V_39 -> V_77 , V_86 ,
V_58 , V_78 ) ;
if ( F_23 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ) ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_1 ) ;
return V_93 ;
}
if ( V_4 -> V_6 ) {
if ( V_24 -> V_30 == V_31 )
V_52 |= V_66 | V_67 ;
V_47 -> V_68 = 0 ;
V_47 -> V_69 = V_52 ;
}
if ( V_91 )
V_51 |= ( V_60 | V_57 ) ;
if ( V_92 ) {
V_51 |= V_59 ;
if ( V_4 -> V_6 )
V_47 -> V_69 |= V_61 ;
}
V_2 -> V_43 = V_51 ;
return 0 ;
}
static int
F_33 ( struct V_23 * V_24 , struct V_28 * V_29 ,
struct V_1 * V_2 , int V_54 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
int V_94 = F_34 ( V_24 ) + F_35 ( V_24 ) ;
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
void * V_19 ;
unsigned long V_95 ;
unsigned short V_51 ;
unsigned int V_52 = 0 ;
V_51 = V_2 -> V_43 ;
V_51 &= ~ V_56 ;
V_51 |= ( V_57 | V_44 ) ;
V_19 = V_4 -> V_96 + V_54 * V_97 ;
V_95 = V_4 -> V_98 + V_54 * V_97 ;
if ( ( ( unsigned long ) V_19 ) & V_73 ||
V_38 -> V_41 & V_74 ) {
memcpy ( V_4 -> V_75 [ V_54 ] , V_24 -> V_86 , V_94 ) ;
V_19 = V_4 -> V_75 [ V_54 ] ;
if ( V_38 -> V_41 & V_74 )
F_5 ( V_19 , V_94 ) ;
V_95 = F_22 ( & V_4 -> V_39 -> V_77 , V_19 ,
V_94 , V_78 ) ;
if ( F_23 ( & V_4 -> V_39 -> V_77 , V_95 ) ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_1 ) ;
return V_93 ;
}
}
V_2 -> V_76 = V_95 ;
V_2 -> V_79 = V_94 ;
if ( V_4 -> V_6 ) {
if ( V_24 -> V_30 == V_31 )
V_52 |= V_66 | V_67 ;
V_47 -> V_68 = 0 ;
V_47 -> V_69 = V_52 ;
}
V_2 -> V_43 = V_51 ;
return 0 ;
}
static int F_36 ( struct V_23 * V_24 , struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
int V_94 = F_34 ( V_24 ) + F_35 ( V_24 ) ;
int V_99 , V_100 ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_101 V_102 ;
unsigned int V_54 = 0 ;
int V_84 ;
if ( F_37 ( V_24 ) >= F_4 ( V_4 ) ) {
F_24 ( V_24 ) ;
if ( F_25 () )
F_26 ( V_29 , L_3 ) ;
return V_80 ;
}
if ( F_11 ( V_24 , V_29 ) ) {
F_24 ( V_24 ) ;
return V_80 ;
}
F_38 ( V_24 , & V_102 ) ;
V_99 = V_24 -> V_20 - V_94 ;
while ( V_99 > 0 ) {
char * V_103 ;
V_54 = F_3 ( V_4 -> V_11 , V_2 , V_4 ) ;
V_100 = F_39 ( int , F_20 ( V_24 ) -> V_104 , V_99 ) ;
V_99 -= V_100 ;
V_103 = V_4 -> V_96 + V_54 * V_97 ;
F_40 ( V_24 , V_103 , & V_102 , V_100 , V_99 == 0 ) ;
V_84 = F_33 ( V_24 , V_29 , V_2 , V_54 ) ;
if ( V_84 )
goto V_105;
while ( V_100 > 0 ) {
int V_58 ;
V_58 = F_39 ( int , V_102 . V_58 , V_100 ) ;
V_2 = F_1 ( V_2 , V_4 ) ;
V_54 = F_3 ( V_4 -> V_11 , V_2 , V_4 ) ;
V_84 = F_32 ( V_24 , V_29 , V_2 , V_54 , V_102 . V_86 ,
V_58 , V_58 == V_100 ,
V_99 == 0 ) ;
if ( V_84 )
goto V_105;
V_100 -= V_58 ;
F_41 ( V_24 , & V_102 , V_58 ) ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_4 -> V_88 [ V_54 ] = V_24 ;
F_14 ( V_2 , V_4 ) ;
F_30 ( V_24 ) ;
V_4 -> V_18 = V_2 ;
F_31 ( 0 , V_4 -> V_89 + V_90 ) ;
return 0 ;
V_105:
return V_84 ;
}
static T_2
F_42 ( struct V_23 * V_24 , struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
int V_83 ;
int V_84 ;
if ( F_43 ( V_24 ) )
V_84 = F_36 ( V_24 , V_29 ) ;
else
V_84 = F_28 ( V_24 , V_29 ) ;
if ( V_84 )
return V_84 ;
V_83 = F_4 ( V_4 ) ;
if ( V_83 <= V_4 -> V_106 )
F_44 ( V_29 ) ;
return V_80 ;
}
static void F_45 ( struct V_28 * V_77 )
{
struct V_3 * V_4 = F_19 ( V_77 ) ;
struct V_1 * V_2 ;
unsigned int V_21 ;
V_2 = V_4 -> V_13 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_14 ; V_21 ++ ) {
if ( V_2 -> V_76 )
V_2 -> V_43 = V_107 ;
else
V_2 -> V_43 = 0 ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_43 |= V_108 ;
V_4 -> V_109 = V_4 -> V_13 ;
V_2 = V_4 -> V_11 ;
V_4 -> V_18 = V_2 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_12 ; V_21 ++ ) {
V_2 -> V_43 = 0 ;
if ( V_2 -> V_76 && V_4 -> V_88 [ V_21 ] ) {
F_24 ( V_4 -> V_88 [ V_21 ] ) ;
V_4 -> V_88 [ V_21 ] = NULL ;
}
V_2 -> V_76 = 0 ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_43 |= V_108 ;
V_4 -> V_17 = V_2 ;
}
static void
F_46 ( struct V_28 * V_29 , int V_110 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
int V_21 ;
T_3 V_111 ;
T_3 V_112 [ 2 ] ;
T_3 V_113 = V_114 | 0x04 ;
T_3 V_115 = 0x2 ;
if ( F_47 ( V_29 ) ) {
F_48 ( V_29 ) ;
F_49 ( & V_4 -> V_116 ) ;
F_44 ( V_29 ) ;
F_50 ( V_29 ) ;
}
F_31 ( 1 , V_4 -> V_89 + V_117 ) ;
F_51 ( 10 ) ;
if ( V_38 -> V_41 & V_118 ) {
memcpy ( & V_112 , V_29 -> V_119 , V_120 ) ;
F_31 ( F_7 ( V_112 [ 0 ] ) , V_4 -> V_89 + V_121 ) ;
F_31 ( F_7 ( V_112 [ 1 ] ) , V_4 -> V_89 + V_122 ) ;
}
F_31 ( 0xffc00000 , V_4 -> V_89 + V_123 ) ;
F_31 ( V_124 , V_4 -> V_89 + V_125 ) ;
F_45 ( V_29 ) ;
F_31 ( V_4 -> V_126 , V_4 -> V_89 + V_127 ) ;
if ( V_4 -> V_6 )
F_31 ( ( unsigned long ) V_4 -> V_126 + sizeof( struct V_6 )
* V_4 -> V_14 , V_4 -> V_89 + V_128 ) ;
else
F_31 ( ( unsigned long ) V_4 -> V_126 + sizeof( struct V_1 )
* V_4 -> V_14 , V_4 -> V_89 + V_128 ) ;
for ( V_21 = 0 ; V_21 <= V_129 ; V_21 ++ ) {
if ( V_4 -> V_88 [ V_21 ] ) {
F_24 ( V_4 -> V_88 [ V_21 ] ) ;
V_4 -> V_88 [ V_21 ] = NULL ;
}
}
if ( V_110 ) {
F_31 ( 0x04 , V_4 -> V_89 + V_130 ) ;
} else {
V_113 |= 0x02 ;
F_31 ( 0x0 , V_4 -> V_89 + V_130 ) ;
}
V_4 -> V_131 = V_110 ;
F_31 ( V_4 -> V_132 , V_4 -> V_89 + V_133 ) ;
#if ! F_52 ( V_134 )
V_111 = F_53 ( V_4 -> V_89 + V_135 ) ;
if ( V_4 -> V_136 & V_137 )
V_111 |= V_138 ;
else
V_111 &= ~ V_138 ;
F_31 ( V_111 , V_4 -> V_89 + V_135 ) ;
#endif
if ( V_38 -> V_41 & V_118 ) {
V_113 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_139 == V_140 )
V_113 |= ( 1 << 6 ) ;
else if ( V_4 -> V_139 == V_141 )
V_113 |= ( 1 << 8 ) ;
else
V_113 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_142 ) {
if ( V_4 -> V_142 -> V_143 == V_144 )
V_115 |= ( 1 << 5 ) ;
else if ( V_4 -> V_142 -> V_143 == V_145 )
V_113 &= ~ ( 1 << 9 ) ;
else
V_113 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_54
if ( V_38 -> V_41 & V_146 ) {
T_3 V_147 ;
F_31 ( 0 , V_4 -> V_89 + F_54 ) ;
while ( F_53 ( V_4 -> V_89 + F_54 ) & 4 )
F_51 ( 1 ) ;
V_147 = ( V_4 -> V_139 == V_141 )
? V_148 : V_149 ;
if ( V_4 -> V_142 && V_4 -> V_142 -> V_143 == V_150 )
V_147 |= V_151 ;
F_31 ( V_147 , V_4 -> V_89 + V_152 ) ;
F_31 ( 2 , V_4 -> V_89 + F_54 ) ;
}
#endif
}
#if ! F_52 ( V_134 )
if ( ( V_4 -> V_153 & V_154 ) ||
( ( V_4 -> V_153 & V_155 ) &&
V_4 -> V_142 && V_4 -> V_142 -> V_156 ) ) {
V_113 |= V_157 ;
F_31 ( V_158 , V_4 -> V_89 + V_159 ) ;
F_31 ( V_160 , V_4 -> V_89 + V_161 ) ;
F_31 ( V_162 , V_4 -> V_89 + V_163 ) ;
F_31 ( V_164 , V_4 -> V_89 + V_165 ) ;
F_31 ( V_166 , V_4 -> V_89 + V_167 ) ;
} else {
V_113 &= ~ V_157 ;
}
#endif
F_31 ( V_113 , V_4 -> V_89 + V_168 ) ;
F_55 ( V_29 ) ;
#ifndef V_134
F_31 ( 0 , V_4 -> V_89 + V_169 ) ;
F_31 ( 0 , V_4 -> V_89 + V_170 ) ;
#endif
if ( V_38 -> V_41 & V_118 ) {
V_115 |= ( 1 << 8 ) ;
F_31 ( 1 << 8 , V_4 -> V_89 + V_171 ) ;
}
if ( V_4 -> V_6 )
V_115 |= ( 1 << 4 ) ;
#ifndef V_134
F_31 ( 0 << 31 , V_4 -> V_89 + V_172 ) ;
#endif
F_31 ( V_115 , V_4 -> V_89 + V_117 ) ;
F_31 ( 0 , V_4 -> V_89 + V_173 ) ;
if ( V_4 -> V_6 )
F_56 ( V_29 ) ;
F_31 ( V_174 , V_4 -> V_89 + V_175 ) ;
if ( F_47 ( V_29 ) ) {
F_57 ( V_29 ) ;
F_58 ( V_29 ) ;
F_59 ( & V_4 -> V_116 ) ;
F_60 ( V_29 ) ;
}
}
static void
F_61 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
T_3 V_176 = F_53 ( V_4 -> V_89 + V_168 ) & ( 1 << 8 ) ;
if ( V_4 -> V_177 ) {
F_31 ( 1 , V_4 -> V_89 + V_130 ) ;
F_51 ( 10 ) ;
if ( ! ( F_53 ( V_4 -> V_89 + V_123 ) & V_178 ) )
F_26 ( V_29 , L_4 ) ;
}
F_31 ( 1 , V_4 -> V_89 + V_117 ) ;
F_51 ( 10 ) ;
F_31 ( V_4 -> V_132 , V_4 -> V_89 + V_133 ) ;
F_31 ( V_174 , V_4 -> V_89 + V_175 ) ;
if ( V_38 -> V_41 & V_118 ) {
F_31 ( 2 , V_4 -> V_89 + V_117 ) ;
F_31 ( V_176 , V_4 -> V_89 + V_168 ) ;
}
}
static void
F_62 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
V_29 -> V_179 . V_180 ++ ;
V_4 -> V_45 . V_181 = true ;
F_16 ( & ( V_4 -> V_45 . V_45 ) , 0 ) ;
}
static void F_63 ( struct V_182 * V_183 )
{
struct V_3 * V_4 =
F_64 ( V_183 ,
struct V_3 ,
V_45 . V_45 . V_183 ) ;
if ( V_4 -> V_45 . V_181 ) {
V_4 -> V_45 . V_181 = false ;
F_46 ( V_4 -> V_184 , V_4 -> V_131 ) ;
F_58 ( V_4 -> V_184 ) ;
}
if ( V_4 -> V_45 . V_46 ) {
V_4 -> V_45 . V_46 = false ;
F_31 ( 0 , V_4 -> V_89 + V_90 ) ;
}
}
static void
F_65 ( struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned short V_51 ;
struct V_23 * V_24 ;
int V_54 = 0 ;
int V_83 ;
V_4 = F_19 ( V_29 ) ;
V_2 = V_4 -> V_17 ;
V_2 = F_1 ( V_2 , V_4 ) ;
while ( ( ( V_51 = V_2 -> V_43 ) & V_44 ) == 0 ) {
if ( V_2 == V_4 -> V_18 )
break;
V_54 = F_3 ( V_4 -> V_11 , V_2 , V_4 ) ;
V_24 = V_4 -> V_88 [ V_54 ] ;
if ( ! F_66 ( V_4 , V_2 -> V_76 ) )
F_27 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ,
V_2 -> V_79 , V_78 ) ;
V_2 -> V_76 = 0 ;
if ( ! V_24 ) {
V_2 = F_1 ( V_2 , V_4 ) ;
continue;
}
if ( V_51 & ( V_185 | V_186 |
V_187 | V_188 |
V_189 ) ) {
V_29 -> V_179 . V_180 ++ ;
if ( V_51 & V_185 )
V_29 -> V_179 . V_190 ++ ;
if ( V_51 & V_186 )
V_29 -> V_179 . V_191 ++ ;
if ( V_51 & V_187 )
V_29 -> V_179 . V_192 ++ ;
if ( V_51 & V_188 )
V_29 -> V_179 . V_193 ++ ;
if ( V_51 & V_189 )
V_29 -> V_179 . V_194 ++ ;
} else {
V_29 -> V_179 . V_195 ++ ;
V_29 -> V_179 . V_196 += V_24 -> V_20 ;
}
if ( F_12 ( F_20 ( V_24 ) -> V_62 & V_87 ) &&
V_4 -> V_6 ) {
struct V_197 V_198 ;
unsigned long V_199 ;
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
F_67 ( & V_4 -> V_200 , V_199 ) ;
V_198 . V_201 = F_68 (
F_69 ( & V_4 -> V_202 , V_47 -> V_203 ) ) ;
F_70 ( & V_4 -> V_200 , V_199 ) ;
F_71 ( V_24 , & V_198 ) ;
}
if ( V_51 & V_44 )
F_26 ( V_29 , L_5 ) ;
if ( V_51 & V_204 )
V_29 -> V_179 . V_205 ++ ;
F_24 ( V_24 ) ;
V_4 -> V_88 [ V_54 ] = NULL ;
V_4 -> V_17 = V_2 ;
V_2 = F_1 ( V_2 , V_4 ) ;
if ( F_72 ( V_29 ) ) {
V_83 = F_4 ( V_4 ) ;
if ( V_83 >= V_4 -> V_206 )
F_58 ( V_29 ) ;
}
}
return;
}
static int
F_73 ( struct V_28 * V_29 , int V_207 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_1 * V_2 ;
unsigned short V_51 ;
struct V_23 * V_24 ;
T_4 V_208 ;
T_5 * V_86 ;
int V_209 = 0 ;
struct V_6 * V_47 = NULL ;
bool V_210 = false ;
T_6 V_211 ;
int V_54 = 0 ;
#ifdef F_74
F_75 () ;
#endif
V_2 = V_4 -> V_109 ;
while ( ! ( ( V_51 = V_2 -> V_43 ) & V_107 ) ) {
if ( V_209 >= V_207 )
break;
V_209 ++ ;
if ( ( V_51 & V_212 ) == 0 )
F_26 ( V_29 , L_6 ) ;
if ( ! V_4 -> V_213 )
goto V_214;
if ( V_51 & ( V_215 | V_216 | V_217 |
V_218 | V_219 ) ) {
V_29 -> V_179 . V_220 ++ ;
if ( V_51 & ( V_215 | V_216 ) ) {
V_29 -> V_179 . V_221 ++ ;
}
if ( V_51 & V_217 )
V_29 -> V_179 . V_222 ++ ;
if ( V_51 & V_218 )
V_29 -> V_179 . V_223 ++ ;
if ( V_51 & V_219 )
V_29 -> V_179 . V_224 ++ ;
}
if ( V_51 & V_225 ) {
V_29 -> V_179 . V_220 ++ ;
V_29 -> V_179 . V_222 ++ ;
goto V_214;
}
V_29 -> V_179 . V_226 ++ ;
V_208 = V_2 -> V_79 ;
V_29 -> V_179 . V_227 += V_208 ;
V_54 = F_3 ( V_4 -> V_13 , V_2 , V_4 ) ;
V_86 = V_4 -> V_228 [ V_54 ] -> V_86 ;
F_76 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ,
V_229 , V_230 ) ;
if ( V_38 -> V_41 & V_74 )
F_5 ( V_86 , V_208 ) ;
V_47 = NULL ;
if ( V_4 -> V_6 )
V_47 = (struct V_6 * ) V_2 ;
V_210 = false ;
if ( ( V_29 -> V_231 & V_232 ) &&
V_4 -> V_6 && ( V_47 -> V_69 & V_233 ) ) {
struct V_234 * V_235 =
(struct V_234 * ) ( V_86 + V_236 ) ;
V_211 = F_77 ( V_235 -> V_237 ) ;
V_208 -= V_238 ;
V_210 = true ;
}
V_24 = F_78 ( V_29 , V_208 - 4 + V_239 ) ;
if ( F_12 ( ! V_24 ) ) {
V_29 -> V_179 . V_240 ++ ;
} else {
int V_241 = ( 2 * V_120 ) ;
F_79 ( V_24 , V_239 ) ;
F_80 ( V_24 , V_208 - 4 ) ;
F_81 ( V_24 , V_86 , ( 2 * V_120 ) ) ;
if ( V_210 )
V_241 = ( 2 * V_120 ) + V_238 ;
F_82 ( V_24 , ( 2 * V_120 ) ,
V_86 + V_241 ,
V_208 - 4 - ( 2 * V_120 ) ) ;
V_24 -> V_25 = F_83 ( V_24 , V_29 ) ;
if ( V_4 -> V_242 && V_4 -> V_6 ) {
struct V_197 * V_198 =
F_84 ( V_24 ) ;
unsigned long V_199 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
F_67 ( & V_4 -> V_200 , V_199 ) ;
V_198 -> V_201 = F_68 (
F_69 ( & V_4 -> V_202 , V_47 -> V_203 ) ) ;
F_70 ( & V_4 -> V_200 , V_199 ) ;
}
if ( V_4 -> V_6 &&
( V_4 -> V_136 & V_137 ) ) {
if ( ! ( V_47 -> V_69 & V_243 ) ) {
V_24 -> V_30 = V_244 ;
} else {
F_85 ( V_24 ) ;
}
}
if ( V_210 )
F_86 ( V_24 ,
F_9 ( V_245 ) ,
V_211 ) ;
F_87 ( & V_4 -> V_116 , V_24 ) ;
}
F_88 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ,
V_229 , V_230 ) ;
V_214:
V_51 &= ~ V_246 ;
V_51 |= V_107 ;
V_2 -> V_43 = V_51 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
V_47 -> V_69 = V_247 ;
V_47 -> V_248 = 0 ;
V_47 -> V_68 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
F_31 ( 0 , V_4 -> V_89 + V_173 ) ;
}
V_4 -> V_109 = V_2 ;
return V_209 ;
}
static T_7
F_89 ( int V_249 , void * V_250 )
{
struct V_28 * V_29 = V_250 ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
T_8 V_251 ;
T_7 V_84 = V_252 ;
do {
V_251 = F_53 ( V_4 -> V_89 + V_123 ) ;
F_31 ( V_251 , V_4 -> V_89 + V_123 ) ;
if ( V_251 & ( V_253 | V_254 ) ) {
V_84 = V_255 ;
if ( F_90 ( & V_4 -> V_116 ) ) {
F_31 ( V_256 ,
V_4 -> V_89 + V_175 ) ;
F_91 ( & V_4 -> V_116 ) ;
}
}
if ( V_251 & V_257 ) {
V_84 = V_255 ;
F_92 ( & V_4 -> V_258 ) ;
}
} while ( V_251 );
return V_84 ;
}
static int F_93 ( struct V_259 * V_116 , int V_207 )
{
struct V_28 * V_29 = V_116 -> V_77 ;
int V_260 = F_73 ( V_29 , V_207 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
F_65 ( V_29 ) ;
if ( V_260 < V_207 ) {
F_94 ( V_116 ) ;
F_31 ( V_174 , V_4 -> V_89 + V_175 ) ;
}
return V_260 ;
}
static void F_95 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_261 * V_262 = F_96 ( & V_4 -> V_39 -> V_77 ) ;
unsigned char * V_263 , V_264 [ V_120 ] ;
V_263 = V_265 ;
if ( ! F_97 ( V_263 ) ) {
struct V_266 * V_267 = V_4 -> V_39 -> V_77 . V_268 ;
if ( V_267 ) {
const char * V_269 = F_98 ( V_267 ) ;
if ( V_269 )
V_263 = ( unsigned char * ) V_269 ;
}
}
if ( ! F_97 ( V_263 ) ) {
#ifdef V_134
if ( V_270 )
V_263 = ( unsigned char * ) V_270 ;
#else
if ( V_262 )
V_263 = ( unsigned char * ) & V_262 -> V_269 ;
#endif
}
if ( ! F_97 ( V_263 ) ) {
* ( ( V_271 * ) & V_264 [ 0 ] ) =
F_7 ( F_53 ( V_4 -> V_89 + V_121 ) ) ;
* ( ( V_272 * ) & V_264 [ 4 ] ) =
F_99 ( F_53 ( V_4 -> V_89 + V_122 ) >> 16 ) ;
V_263 = & V_264 [ 0 ] ;
}
if ( ! F_97 ( V_263 ) ) {
F_26 ( V_29 , L_7 , V_263 ) ;
F_100 ( V_29 ) ;
F_101 ( V_29 , L_8 ,
V_29 -> V_119 ) ;
return;
}
memcpy ( V_29 -> V_119 , V_263 , V_120 ) ;
if ( V_263 == V_265 )
V_29 -> V_119 [ V_120 - 1 ] = V_265 [ V_120 - 1 ] + V_4 -> V_250 ;
}
static void F_102 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_273 * V_142 = V_4 -> V_142 ;
int V_274 = 0 ;
if ( V_4 -> V_275 && V_142 -> V_276 == V_277 ) {
V_142 -> V_276 = V_278 ;
return;
}
if ( V_142 -> V_177 ) {
if ( ! V_4 -> V_177 ) {
V_4 -> V_177 = V_142 -> V_177 ;
V_274 = 1 ;
}
if ( V_4 -> V_131 != V_142 -> V_110 )
V_274 = 1 ;
if ( V_142 -> V_143 != V_4 -> V_143 ) {
V_4 -> V_143 = V_142 -> V_143 ;
V_274 = 1 ;
}
if ( V_274 )
F_46 ( V_29 , V_142 -> V_110 ) ;
} else {
if ( V_4 -> V_177 ) {
F_61 ( V_29 ) ;
V_4 -> V_177 = V_142 -> V_177 ;
V_274 = 1 ;
}
}
if ( V_274 )
F_103 ( V_142 ) ;
}
static int F_104 ( struct V_279 * V_280 , int V_281 , int V_282 )
{
struct V_3 * V_4 = V_280 -> V_283 ;
unsigned long V_284 ;
V_4 -> V_275 = 0 ;
F_105 ( & V_4 -> V_258 ) ;
F_31 ( V_285 | V_286 |
F_106 ( V_281 ) | F_107 ( V_282 ) |
V_287 , V_4 -> V_89 + V_288 ) ;
V_284 = F_108 ( & V_4 -> V_258 ,
F_109 ( V_289 ) ) ;
if ( V_284 == 0 ) {
V_4 -> V_275 = 1 ;
F_26 ( V_4 -> V_184 , L_9 ) ;
return - V_290 ;
}
return F_110 ( F_53 ( V_4 -> V_89 + V_288 ) ) ;
}
static int F_111 ( struct V_279 * V_280 , int V_281 , int V_282 ,
T_6 V_291 )
{
struct V_3 * V_4 = V_280 -> V_283 ;
unsigned long V_284 ;
V_4 -> V_275 = 0 ;
F_105 ( & V_4 -> V_258 ) ;
F_31 ( V_285 | V_292 |
F_106 ( V_281 ) | F_107 ( V_282 ) |
V_287 | F_110 ( V_291 ) ,
V_4 -> V_89 + V_288 ) ;
V_284 = F_108 ( & V_4 -> V_258 ,
F_109 ( V_289 ) ) ;
if ( V_284 == 0 ) {
V_4 -> V_275 = 1 ;
F_26 ( V_4 -> V_184 , L_10 ) ;
return - V_290 ;
}
return 0 ;
}
static int F_112 ( struct V_28 * V_29 , bool V_293 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
int V_84 ;
if ( V_293 ) {
V_84 = F_113 ( V_4 -> V_294 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_113 ( V_4 -> V_295 ) ;
if ( V_84 )
goto V_296;
if ( V_4 -> V_297 ) {
V_84 = F_113 ( V_4 -> V_297 ) ;
if ( V_84 )
goto V_298;
}
if ( V_4 -> V_299 ) {
V_84 = F_113 ( V_4 -> V_299 ) ;
if ( V_84 )
goto V_300;
}
} else {
F_114 ( V_4 -> V_294 ) ;
F_114 ( V_4 -> V_295 ) ;
if ( V_4 -> V_297 )
F_114 ( V_4 -> V_297 ) ;
if ( V_4 -> V_299 )
F_114 ( V_4 -> V_299 ) ;
}
return 0 ;
V_300:
if ( V_4 -> V_297 )
F_114 ( V_4 -> V_297 ) ;
V_298:
F_114 ( V_4 -> V_295 ) ;
V_296:
F_114 ( V_4 -> V_294 ) ;
return V_84 ;
}
static int F_115 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_273 * V_142 = NULL ;
char V_301 [ V_302 ] ;
char V_303 [ V_302 + 3 ] ;
int V_304 ;
int V_250 = V_4 -> V_250 ;
V_4 -> V_142 = NULL ;
for ( V_304 = 0 ; ( V_304 < V_305 ) ; V_304 ++ ) {
if ( ( V_4 -> V_279 -> V_306 & ( 1 << V_304 ) ) )
continue;
if ( V_4 -> V_279 -> V_307 [ V_304 ] == NULL )
continue;
if ( V_4 -> V_279 -> V_307 [ V_304 ] -> V_304 == 0 )
continue;
if ( V_250 -- )
continue;
strncpy ( V_301 , V_4 -> V_279 -> V_308 , V_302 ) ;
break;
}
if ( V_304 >= V_305 ) {
F_101 ( V_29 , L_11 ) ;
strncpy ( V_301 , L_12 , V_302 ) ;
V_304 = 0 ;
}
snprintf ( V_303 , sizeof( V_303 ) , V_309 , V_301 , V_304 ) ;
V_142 = F_116 ( V_29 , V_303 , & F_102 ,
V_4 -> V_139 ) ;
if ( F_117 ( V_142 ) ) {
F_26 ( V_29 , L_13 ) ;
return F_118 ( V_142 ) ;
}
if ( V_38 -> V_41 & V_310 ) {
V_142 -> V_311 &= V_312 ;
#if ! F_52 ( V_134 )
V_142 -> V_311 |= V_313 ;
#endif
}
else
V_142 -> V_311 &= V_314 ;
V_142 -> V_315 = V_142 -> V_311 ;
V_4 -> V_142 = V_142 ;
V_4 -> V_177 = 0 ;
V_4 -> V_131 = 0 ;
F_101 ( V_29 , L_14 ,
V_4 -> V_142 -> V_316 -> V_317 , F_119 ( & V_4 -> V_142 -> V_77 ) ,
V_4 -> V_142 -> V_249 ) ;
return 0 ;
}
static int F_120 ( struct V_318 * V_39 )
{
static struct V_279 * V_319 ;
struct V_28 * V_29 = F_121 ( V_39 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
int V_320 = - V_321 , V_21 ;
if ( ( V_38 -> V_41 & V_118 ) && V_4 -> V_250 > 0 ) {
if ( V_322 && V_319 ) {
V_4 -> V_279 = V_319 ;
V_322 ++ ;
return 0 ;
}
return - V_323 ;
}
V_4 -> V_275 = 0 ;
V_4 -> V_132 = F_6 ( F_122 ( V_4 -> V_295 ) , 5000000 ) ;
if ( V_38 -> V_41 & V_118 )
V_4 -> V_132 -- ;
V_4 -> V_132 <<= 1 ;
F_31 ( V_4 -> V_132 , V_4 -> V_89 + V_133 ) ;
V_4 -> V_279 = F_123 () ;
if ( V_4 -> V_279 == NULL ) {
V_320 = - V_324 ;
goto V_325;
}
V_4 -> V_279 -> V_317 = L_15 ;
V_4 -> V_279 -> V_326 = F_104 ;
V_4 -> V_279 -> V_327 = F_111 ;
snprintf ( V_4 -> V_279 -> V_308 , V_302 , L_16 ,
V_39 -> V_317 , V_4 -> V_250 + 1 ) ;
V_4 -> V_279 -> V_283 = V_4 ;
V_4 -> V_279 -> V_328 = & V_39 -> V_77 ;
V_4 -> V_279 -> V_249 = F_124 ( sizeof( int ) * V_305 , V_329 ) ;
if ( ! V_4 -> V_279 -> V_249 ) {
V_320 = - V_324 ;
goto V_330;
}
for ( V_21 = 0 ; V_21 < V_305 ; V_21 ++ )
V_4 -> V_279 -> V_249 [ V_21 ] = V_331 ;
if ( F_125 ( V_4 -> V_279 ) )
goto V_332;
V_322 ++ ;
if ( V_38 -> V_41 & V_118 )
V_319 = V_4 -> V_279 ;
return 0 ;
V_332:
F_126 ( V_4 -> V_279 -> V_249 ) ;
V_330:
F_127 ( V_4 -> V_279 ) ;
V_325:
return V_320 ;
}
static void F_128 ( struct V_3 * V_4 )
{
if ( -- V_322 == 0 ) {
F_129 ( V_4 -> V_279 ) ;
F_126 ( V_4 -> V_279 -> V_249 ) ;
F_127 ( V_4 -> V_279 ) ;
}
}
static int F_130 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_273 * V_335 = V_4 -> V_142 ;
if ( ! V_335 )
return - V_336 ;
return F_131 ( V_335 , V_334 ) ;
}
static int F_132 ( struct V_28 * V_29 ,
struct V_333 * V_334 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_273 * V_335 = V_4 -> V_142 ;
if ( ! V_335 )
return - V_336 ;
return F_133 ( V_335 , V_334 ) ;
}
static void F_134 ( struct V_28 * V_29 ,
struct V_337 * V_338 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
F_135 ( V_338 -> V_339 , V_4 -> V_39 -> V_77 . V_339 -> V_317 ,
sizeof( V_338 -> V_339 ) ) ;
F_135 ( V_338 -> V_27 , L_17 , sizeof( V_338 -> V_27 ) ) ;
F_135 ( V_338 -> V_340 , F_119 ( & V_29 -> V_77 ) , sizeof( V_338 -> V_340 ) ) ;
}
static int F_136 ( struct V_28 * V_29 ,
struct V_341 * V_338 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
if ( V_4 -> V_6 ) {
V_338 -> V_342 = V_343 |
V_344 |
V_345 |
V_346 |
V_347 |
V_348 ;
if ( V_4 -> V_349 )
V_338 -> V_350 = F_137 ( V_4 -> V_349 ) ;
else
V_338 -> V_350 = - 1 ;
V_338 -> V_351 = ( 1 << V_352 ) |
( 1 << V_353 ) ;
V_338 -> V_354 = ( 1 << V_355 ) |
( 1 << V_356 ) ;
return 0 ;
} else {
return F_138 ( V_29 , V_338 ) ;
}
}
static void F_139 ( struct V_28 * V_29 ,
struct V_357 * V_156 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
V_156 -> V_358 = ( V_4 -> V_153 & V_155 ) != 0 ;
V_156 -> V_359 = ( V_4 -> V_153 & V_154 ) != 0 ;
V_156 -> V_360 = V_156 -> V_359 ;
}
static int F_140 ( struct V_28 * V_29 ,
struct V_357 * V_156 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
if ( V_156 -> V_359 != V_156 -> V_360 ) {
F_101 ( V_29 ,
L_18 ) ;
return - V_361 ;
}
V_4 -> V_153 = 0 ;
V_4 -> V_153 |= V_156 -> V_360 ? V_154 : 0 ;
V_4 -> V_153 |= V_156 -> V_358 ? V_155 : 0 ;
if ( V_156 -> V_360 || V_156 -> V_358 ) {
V_4 -> V_142 -> V_311 |= V_362 ;
V_4 -> V_142 -> V_315 |= V_362 ;
} else {
V_4 -> V_142 -> V_311 &= ~ V_362 ;
V_4 -> V_142 -> V_315 &= ~ V_362 ;
}
if ( V_156 -> V_358 ) {
if ( F_47 ( V_29 ) )
F_61 ( V_29 ) ;
F_141 ( V_4 -> V_142 ) ;
}
if ( F_47 ( V_29 ) )
F_46 ( V_29 , 0 ) ;
return 0 ;
}
static void F_142 ( struct V_28 * V_77 ,
struct V_363 * V_179 , T_9 * V_86 )
{
struct V_3 * V_4 = F_19 ( V_77 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_143 ( V_364 ) ; V_21 ++ )
V_86 [ V_21 ] = F_53 ( V_4 -> V_89 + V_364 [ V_21 ] . V_365 ) ;
}
static void F_144 ( struct V_28 * V_184 ,
T_3 V_366 , T_10 * V_86 )
{
int V_21 ;
switch ( V_366 ) {
case V_367 :
for ( V_21 = 0 ; V_21 < F_143 ( V_364 ) ; V_21 ++ )
memcpy ( V_86 + V_21 * V_368 ,
V_364 [ V_21 ] . V_317 , V_368 ) ;
break;
}
}
static int F_145 ( struct V_28 * V_77 , int V_369 )
{
switch ( V_369 ) {
case V_367 :
return F_143 ( V_364 ) ;
default:
return - V_370 ;
}
}
static int F_146 ( struct V_28 * V_77 )
{
struct V_3 * V_4 = F_19 ( V_77 ) ;
struct V_273 * V_335 = V_4 -> V_142 ;
if ( ! V_335 )
return - V_336 ;
return F_147 ( V_335 ) ;
}
static int F_148 ( struct V_28 * V_29 , struct V_371 * V_372 , int V_334 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_273 * V_335 = V_4 -> V_142 ;
if ( ! F_47 ( V_29 ) )
return - V_361 ;
if ( ! V_335 )
return - V_336 ;
if ( V_4 -> V_6 ) {
if ( V_334 == V_373 )
return F_149 ( V_29 , V_372 ) ;
if ( V_334 == V_374 )
return F_150 ( V_29 , V_372 ) ;
}
return F_151 ( V_335 , V_372 , V_334 ) ;
}
static void F_152 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
unsigned int V_21 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
V_2 = V_4 -> V_13 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_14 ; V_21 ++ ) {
V_24 = V_4 -> V_228 [ V_21 ] ;
if ( V_2 -> V_76 )
F_27 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ,
V_229 , V_230 ) ;
if ( V_24 )
F_153 ( V_24 ) ;
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = V_4 -> V_11 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_12 ; V_21 ++ )
F_126 ( V_4 -> V_75 [ V_21 ] ) ;
}
static int F_154 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
unsigned int V_21 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
V_2 = V_4 -> V_13 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_14 ; V_21 ++ ) {
V_24 = F_78 ( V_29 , V_229 ) ;
if ( ! V_24 ) {
F_152 ( V_29 ) ;
return - V_324 ;
}
V_4 -> V_228 [ V_21 ] = V_24 ;
V_2 -> V_76 = F_22 ( & V_4 -> V_39 -> V_77 , V_24 -> V_86 ,
V_229 , V_230 ) ;
if ( F_23 ( & V_4 -> V_39 -> V_77 , V_2 -> V_76 ) ) {
F_152 ( V_29 ) ;
if ( F_25 () )
F_26 ( V_29 , L_19 ) ;
return - V_324 ;
}
V_2 -> V_43 = V_107 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
V_47 -> V_69 = V_247 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_43 |= V_108 ;
V_2 = V_4 -> V_11 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_12 ; V_21 ++ ) {
V_4 -> V_75 [ V_21 ] = F_124 ( V_375 , V_329 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_76 = 0 ;
if ( V_4 -> V_6 ) {
struct V_6 * V_47 = (struct V_6 * ) V_2 ;
V_47 -> V_69 = V_61 ;
}
V_2 = F_1 ( V_2 , V_4 ) ;
}
V_2 = F_2 ( V_2 , V_4 ) ;
V_2 -> V_43 |= V_108 ;
return 0 ;
}
static int
F_155 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
int V_84 ;
F_156 ( & V_4 -> V_39 -> V_77 ) ;
V_84 = F_112 ( V_29 , true ) ;
if ( V_84 )
return V_84 ;
V_84 = F_154 ( V_29 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_115 ( V_29 ) ;
if ( V_84 ) {
F_152 ( V_29 ) ;
return V_84 ;
}
F_59 ( & V_4 -> V_116 ) ;
F_157 ( V_4 -> V_142 ) ;
F_158 ( V_29 ) ;
V_4 -> V_213 = 1 ;
return 0 ;
}
static int
F_159 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
F_49 ( & V_4 -> V_116 ) ;
V_4 -> V_213 = 0 ;
F_44 ( V_29 ) ;
F_61 ( V_29 ) ;
if ( V_4 -> V_142 ) {
F_160 ( V_4 -> V_142 ) ;
F_161 ( V_4 -> V_142 ) ;
}
F_112 ( V_29 , false ) ;
F_162 ( & V_4 -> V_39 -> V_77 ) ;
F_152 ( V_29 ) ;
return 0 ;
}
static void F_55 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_376 * V_377 ;
unsigned int V_21 , V_378 , V_86 , V_379 , V_380 ;
unsigned char V_381 ;
if ( V_29 -> V_199 & V_382 ) {
V_380 = F_53 ( V_4 -> V_89 + V_168 ) ;
V_380 |= 0x8 ;
F_31 ( V_380 , V_4 -> V_89 + V_168 ) ;
return;
}
V_380 = F_53 ( V_4 -> V_89 + V_168 ) ;
V_380 &= ~ 0x8 ;
F_31 ( V_380 , V_4 -> V_89 + V_168 ) ;
if ( V_29 -> V_199 & V_383 ) {
F_31 ( 0xffffffff , V_4 -> V_89 + V_384 ) ;
F_31 ( 0xffffffff , V_4 -> V_89 + V_385 ) ;
return;
}
F_31 ( 0 , V_4 -> V_89 + V_384 ) ;
F_31 ( 0 , V_4 -> V_89 + V_385 ) ;
F_163 (ha, ndev) {
V_379 = 0xffffffff ;
for ( V_21 = 0 ; V_21 < V_29 -> V_386 ; V_21 ++ ) {
V_86 = V_377 -> V_387 [ V_21 ] ;
for ( V_378 = 0 ; V_378 < 8 ; V_378 ++ , V_86 >>= 1 ) {
V_379 = ( V_379 >> 1 ) ^
( ( ( V_379 ^ V_86 ) & 1 ) ? V_388 : 0 ) ;
}
}
V_381 = ( V_379 >> ( 32 - V_389 ) ) & 0x3f ;
if ( V_381 > 31 ) {
V_380 = F_53 ( V_4 -> V_89 + V_384 ) ;
V_380 |= 1 << ( V_381 - 32 ) ;
F_31 ( V_380 , V_4 -> V_89 + V_384 ) ;
} else {
V_380 = F_53 ( V_4 -> V_89 + V_385 ) ;
V_380 |= 1 << V_381 ;
F_31 ( V_380 , V_4 -> V_89 + V_385 ) ;
}
}
}
static int
F_164 ( struct V_28 * V_29 , void * V_71 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
struct V_390 * V_387 = V_71 ;
if ( V_387 ) {
if ( ! F_97 ( V_387 -> V_391 ) )
return - V_392 ;
memcpy ( V_29 -> V_119 , V_387 -> V_391 , V_29 -> V_386 ) ;
}
F_31 ( V_29 -> V_119 [ 3 ] | ( V_29 -> V_119 [ 2 ] << 8 ) |
( V_29 -> V_119 [ 1 ] << 16 ) | ( V_29 -> V_119 [ 0 ] << 24 ) ,
V_4 -> V_89 + V_121 ) ;
F_31 ( ( V_29 -> V_119 [ 5 ] << 16 ) | ( V_29 -> V_119 [ 4 ] << 24 ) ,
V_4 -> V_89 + V_122 ) ;
return 0 ;
}
static void F_165 ( struct V_28 * V_77 )
{
int V_21 ;
struct V_3 * V_4 = F_19 ( V_77 ) ;
for ( V_21 = 0 ; V_21 < V_393 ; V_21 ++ ) {
if ( V_4 -> V_249 [ V_21 ] > 0 ) {
F_166 ( V_4 -> V_249 [ V_21 ] ) ;
F_89 ( V_4 -> V_249 [ V_21 ] , V_77 ) ;
F_167 ( V_4 -> V_249 [ V_21 ] ) ;
}
}
}
static int F_168 ( struct V_28 * V_184 ,
T_11 V_231 )
{
struct V_3 * V_4 = F_19 ( V_184 ) ;
T_11 V_394 = V_231 ^ V_184 -> V_231 ;
V_184 -> V_231 = V_231 ;
if ( V_394 & V_395 ) {
if ( V_231 & V_395 )
V_4 -> V_136 |= V_137 ;
else
V_4 -> V_136 &= ~ V_137 ;
if ( F_47 ( V_184 ) ) {
F_61 ( V_184 ) ;
F_46 ( V_184 , V_4 -> V_142 -> V_110 ) ;
F_58 ( V_184 ) ;
} else {
F_46 ( V_184 , V_4 -> V_142 -> V_110 ) ;
}
}
return 0 ;
}
static int F_169 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
const struct V_37 * V_38 =
F_15 ( V_4 -> V_39 ) ;
struct V_1 * V_396 ;
int V_397 ;
V_4 -> V_12 = V_398 ;
V_4 -> V_14 = V_399 ;
V_4 -> V_106 = V_400 ;
V_4 -> V_206 = ( V_4 -> V_12 - V_4 -> V_106 ) / 2 ;
if ( V_4 -> V_6 )
V_4 -> V_15 = sizeof( struct V_6 ) ;
else
V_4 -> V_15 = sizeof( struct V_1 ) ;
V_397 = ( V_4 -> V_12 + V_4 -> V_14 ) *
V_4 -> V_15 ;
V_396 = F_170 ( NULL , V_397 , & V_4 -> V_126 ,
V_329 ) ;
if ( ! V_396 )
return - V_324 ;
V_4 -> V_96 = F_170 ( NULL , V_4 -> V_12 * V_97 ,
& V_4 -> V_98 , V_329 ) ;
if ( ! V_4 -> V_96 ) {
F_171 ( NULL , V_397 , V_396 , V_4 -> V_126 ) ;
return - V_324 ;
}
memset ( V_396 , 0 , V_401 ) ;
V_4 -> V_184 = V_29 ;
F_95 ( V_29 ) ;
F_164 ( V_29 , NULL ) ;
V_4 -> V_13 = V_396 ;
if ( V_4 -> V_6 )
V_4 -> V_11 = (struct V_1 * )
( ( (struct V_6 * ) V_396 ) + V_4 -> V_14 ) ;
else
V_4 -> V_11 = V_396 + V_4 -> V_14 ;
V_29 -> V_402 = V_403 ;
V_29 -> V_404 = & V_405 ;
V_29 -> V_406 = & V_407 ;
F_31 ( V_256 , V_4 -> V_89 + V_175 ) ;
F_172 ( V_29 , & V_4 -> V_116 , F_93 , V_408 ) ;
if ( V_38 -> V_41 & V_409 )
V_29 -> V_231 |= V_232 ;
if ( V_38 -> V_41 & V_410 ) {
V_29 -> V_411 = V_412 ;
V_29 -> V_231 |= ( V_413 | V_414
| V_395 | V_415 | V_416 ) ;
V_4 -> V_136 |= V_137 ;
}
V_29 -> V_417 = V_29 -> V_231 ;
F_46 ( V_29 , 0 ) ;
return 0 ;
}
static void F_173 ( struct V_318 * V_39 )
{
int V_320 , V_418 ;
int V_419 = 1 ;
struct V_266 * V_267 = V_39 -> V_77 . V_268 ;
if ( ! V_267 )
return;
F_174 ( V_267 , L_20 , & V_419 ) ;
if ( V_419 > 1000 )
V_419 = 1 ;
V_418 = F_175 ( V_267 , L_21 , 0 ) ;
if ( ! F_176 ( V_418 ) )
return;
V_320 = F_177 ( & V_39 -> V_77 , V_418 ,
V_420 , L_22 ) ;
if ( V_320 ) {
F_178 ( & V_39 -> V_77 , L_23 , V_320 ) ;
return;
}
F_179 ( V_419 ) ;
F_180 ( V_418 , 1 ) ;
}
static void F_173 ( struct V_318 * V_39 )
{
}
static int
F_181 ( struct V_318 * V_39 )
{
struct V_3 * V_4 ;
struct V_261 * V_262 ;
struct V_28 * V_29 ;
int V_21 , V_249 , V_84 = 0 ;
struct V_421 * V_422 ;
const struct V_423 * V_424 ;
static int V_250 ;
V_424 = F_182 ( V_425 , & V_39 -> V_77 ) ;
if ( V_424 )
V_39 -> V_38 = V_424 -> V_86 ;
V_29 = F_183 ( sizeof( struct V_3 ) ) ;
if ( ! V_29 )
return - V_324 ;
F_184 ( V_29 , & V_39 -> V_77 ) ;
V_4 = F_19 ( V_29 ) ;
#if ! F_52 ( V_134 )
if ( V_39 -> V_38 &&
( V_39 -> V_38 -> V_41 & V_310 ) )
V_4 -> V_153 |= V_155 ;
#endif
F_156 ( & V_39 -> V_77 ) ;
V_422 = F_185 ( V_39 , V_426 , 0 ) ;
V_4 -> V_89 = F_186 ( & V_39 -> V_77 , V_422 ) ;
if ( F_117 ( V_4 -> V_89 ) ) {
V_84 = F_118 ( V_4 -> V_89 ) ;
goto V_427;
}
V_4 -> V_39 = V_39 ;
V_4 -> V_250 = V_250 ++ ;
V_4 -> V_6 = 0 ;
F_187 ( V_39 , V_29 ) ;
V_84 = F_188 ( V_39 -> V_77 . V_268 ) ;
if ( V_84 < 0 ) {
V_262 = F_96 ( & V_39 -> V_77 ) ;
if ( V_262 )
V_4 -> V_139 = V_262 -> V_428 ;
else
V_4 -> V_139 = V_429 ;
} else {
V_4 -> V_139 = V_84 ;
}
V_4 -> V_295 = F_189 ( & V_39 -> V_77 , L_24 ) ;
if ( F_117 ( V_4 -> V_295 ) ) {
V_84 = F_118 ( V_4 -> V_295 ) ;
goto V_430;
}
V_4 -> V_294 = F_189 ( & V_39 -> V_77 , L_25 ) ;
if ( F_117 ( V_4 -> V_294 ) ) {
V_84 = F_118 ( V_4 -> V_294 ) ;
goto V_430;
}
V_4 -> V_297 = F_189 ( & V_39 -> V_77 , L_26 ) ;
if ( F_117 ( V_4 -> V_297 ) )
V_4 -> V_297 = NULL ;
V_4 -> V_299 = F_189 ( & V_39 -> V_77 , L_27 ) ;
V_4 -> V_6 =
V_39 -> V_38 -> V_41 & V_431 ;
if ( F_117 ( V_4 -> V_299 ) ) {
V_4 -> V_299 = NULL ;
V_4 -> V_6 = 0 ;
}
V_84 = F_112 ( V_29 , true ) ;
if ( V_84 )
goto V_430;
V_4 -> V_432 = F_190 ( & V_39 -> V_77 , L_28 ) ;
if ( ! F_117 ( V_4 -> V_432 ) ) {
V_84 = F_191 ( V_4 -> V_432 ) ;
if ( V_84 ) {
F_178 ( & V_39 -> V_77 ,
L_29 , V_84 ) ;
goto V_433;
}
} else {
V_4 -> V_432 = NULL ;
}
F_173 ( V_39 ) ;
if ( V_4 -> V_6 )
F_192 ( V_39 ) ;
V_84 = F_169 ( V_29 ) ;
if ( V_84 )
goto V_434;
for ( V_21 = 0 ; V_21 < V_393 ; V_21 ++ ) {
V_249 = F_193 ( V_39 , V_21 ) ;
if ( V_249 < 0 ) {
if ( V_21 )
break;
V_84 = V_249 ;
goto V_435;
}
V_84 = F_194 ( & V_39 -> V_77 , V_249 , F_89 ,
0 , V_39 -> V_317 , V_29 ) ;
if ( V_84 )
goto V_435;
}
V_84 = F_120 ( V_39 ) ;
if ( V_84 )
goto V_436;
F_195 ( V_29 ) ;
F_112 ( V_29 , false ) ;
F_162 ( & V_39 -> V_77 ) ;
V_84 = F_196 ( V_29 ) ;
if ( V_84 )
goto V_437;
if ( V_4 -> V_6 && V_4 -> V_349 )
F_101 ( V_29 , L_30 , V_4 -> V_250 ) ;
F_197 ( & ( V_4 -> V_45 . V_45 ) , F_63 ) ;
return 0 ;
V_437:
F_128 ( V_4 ) ;
V_436:
V_435:
V_434:
if ( V_4 -> V_432 )
F_198 ( V_4 -> V_432 ) ;
V_433:
F_112 ( V_29 , false ) ;
V_430:
V_427:
F_199 ( V_29 ) ;
return V_84 ;
}
static int
F_200 ( struct V_318 * V_39 )
{
struct V_28 * V_29 = F_121 ( V_39 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
F_201 ( & ( V_4 -> V_45 . V_45 ) ) ;
F_202 ( V_29 ) ;
F_128 ( V_4 ) ;
F_203 ( & V_4 -> V_438 ) ;
if ( V_4 -> V_432 )
F_198 ( V_4 -> V_432 ) ;
if ( V_4 -> V_349 )
F_204 ( V_4 -> V_349 ) ;
F_112 ( V_29 , false ) ;
F_199 ( V_29 ) ;
return 0 ;
}
static int
F_205 ( struct V_439 * V_77 )
{
struct V_28 * V_29 = F_206 ( V_77 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
if ( F_47 ( V_29 ) ) {
F_61 ( V_29 ) ;
F_48 ( V_29 ) ;
}
F_112 ( V_29 , false ) ;
F_162 ( & V_4 -> V_39 -> V_77 ) ;
if ( V_4 -> V_432 )
F_198 ( V_4 -> V_432 ) ;
return 0 ;
}
static int
F_207 ( struct V_439 * V_77 )
{
struct V_28 * V_29 = F_206 ( V_77 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
int V_84 ;
if ( V_4 -> V_432 ) {
V_84 = F_191 ( V_4 -> V_432 ) ;
if ( V_84 )
return V_84 ;
}
F_156 ( & V_4 -> V_39 -> V_77 ) ;
V_84 = F_112 ( V_29 , true ) ;
if ( V_84 )
goto V_430;
if ( F_47 ( V_29 ) ) {
F_46 ( V_29 , V_4 -> V_131 ) ;
F_60 ( V_29 ) ;
}
return 0 ;
V_430:
if ( V_4 -> V_432 )
F_198 ( V_4 -> V_432 ) ;
return V_84 ;
}
