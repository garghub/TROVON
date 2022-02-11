static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
unsigned int V_6 = sizeof( struct V_7 ) * ( V_5 + 1 ) ;
V_4 -> V_8 = F_2 ( & V_2 -> V_9 -> V_10 , V_6 ,
& V_4 -> V_11 , V_12 ) ;
if ( V_4 -> V_8 == NULL )
return - V_13 ;
V_4 -> V_5 = V_5 ;
memset ( V_4 -> V_8 , 0 , V_6 ) ;
V_4 -> V_14 = ( void V_15 * ) F_3 ( V_4 -> V_8 ) ;
V_4 -> V_16 = V_4 -> V_11 + ( unsigned long ) ( ( char * ) V_4 -> V_14 - ( char * ) V_4 -> V_8 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_8 ) {
unsigned int V_6 = sizeof( struct V_7 ) * ( V_4 -> V_5 + 1 ) ;
F_5 ( & V_2 -> V_9 -> V_10 , V_6 , V_4 -> V_8 , V_4 -> V_11 ) ;
}
}
unsigned int F_6 ( struct V_1 * V_2 , struct V_17 * V_4 , unsigned int V_18 )
{
int V_19 , V_20 , V_21 ;
V_20 = V_4 -> V_22 ;
if ( V_18 > V_2 -> V_23 [ 0 ] )
return 0 ;
V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_24 ; V_19 ++ , V_20 >>= 1 ) {
if ( ! ( V_20 & 1 ) ) continue;
V_21 = V_19 ;
if ( V_18 >= V_2 -> V_23 [ V_19 ] )
break;
}
return V_21 ;
}
static inline int F_7 ( int V_25 )
{
return ( V_25 == V_26 ) ?
V_27 : V_26 ;
}
static int F_8 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
return F_9 ( V_29 , F_10 ( V_31 ) ) ;
}
static int F_11 ( struct V_28 * V_29 )
{
F_12 ( V_29 ) ;
return 0 ;
}
static struct V_17 * F_13 ( struct V_1 * V_2 , int V_25 )
{
switch ( V_25 ) {
case V_26 :
return & V_2 -> V_32 ;
case V_27 :
return & V_2 -> V_33 ;
default:
F_14 () ;
return NULL ;
}
}
static inline void
F_15 ( struct V_17 * V_4 )
{
int V_34 = 50000 ;
while ( ( F_16 ( & V_4 -> V_35 -> V_36 ) & V_37 ) && V_34 -- > 0 )
F_17 ( 1 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_38 -> V_39 , V_2 -> V_40 | ( V_2 -> V_41 << 8 ) ) ;
F_19 ( & V_2 -> V_38 -> V_42 , V_2 -> V_43 == V_44 ? 1 : 0 ) ;
if ( V_2 -> V_45 )
V_2 -> V_45 ( V_2 ) ;
}
static inline void F_20 ( struct V_17 * V_4 )
{
F_19 ( & V_4 -> V_35 -> V_39 , ( V_37 | V_46 | V_47 | V_48 ) << 16 ) ;
F_15 ( V_4 ) ;
}
static inline void F_21 ( struct V_17 * V_4 , struct V_3 * V_49 )
{
F_19 ( & V_4 -> V_35 -> V_50 , V_49 -> V_16 ) ;
}
static inline void F_22 ( struct V_17 * V_4 , int V_36 )
{
F_19 ( & V_4 -> V_35 -> V_39 , V_36 | ( V_36 << 16 ) ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_17 * V_4 , struct V_28 * V_29 )
{
int V_19 ;
volatile struct V_7 V_15 * V_51 ;
struct V_52 * V_53 = V_29 -> V_53 ;
int V_41 ;
long V_54 ;
struct V_17 * V_55 ;
V_4 -> V_56 = F_24 ( V_29 ) ;
V_4 -> V_57 = F_25 ( V_29 ) ;
V_4 -> V_58 = V_4 -> V_56 / V_4 -> V_57 ;
V_4 -> V_59 = 0 ;
V_41 = F_6 ( V_2 , V_4 , V_53 -> V_18 ) ;
V_55 = F_13 ( V_2 , F_7 ( V_4 -> V_25 ) ) ;
if ( ! V_55 )
return - V_60 ;
V_55 -> V_22 = 1 << V_41 ;
V_55 -> V_61 = 1 << V_53 -> V_43 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_43 = V_53 -> V_43 ;
F_26 ( & V_2 -> V_62 ) ;
F_20 ( V_4 ) ;
F_27 ( & V_2 -> V_63 . V_14 -> V_64 , V_65 ) ;
F_21 ( V_4 , & V_2 -> V_63 ) ;
F_22 ( V_4 , V_37 ) ;
F_28 ( & V_2 -> V_62 ) ;
F_29 ( 5 ) ;
F_26 ( & V_2 -> V_62 ) ;
V_54 = V_53 -> V_66 ;
for ( V_19 = 0 , V_51 = V_4 -> V_49 . V_14 ; V_19 < V_4 -> V_58 ; V_19 ++ , V_51 ++ ) {
F_30 ( & V_51 -> V_67 , V_54 ) ;
F_27 ( & V_51 -> V_68 , V_4 -> V_57 ) ;
F_27 ( & V_51 -> V_69 , 0 ) ;
V_54 += V_4 -> V_57 ;
}
F_27 ( & V_51 -> V_64 , V_70 + V_71 ) ;
F_30 ( & V_51 -> V_72 , V_4 -> V_49 . V_16 ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 , & V_4 -> V_49 ) ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_17 * V_4 ,
struct V_28 * V_29 , int V_49 )
{
volatile struct V_7 V_15 * V_51 ;
int V_19 , V_64 ;
switch ( V_49 ) {
case V_73 :
case V_74 :
if ( V_4 -> V_75 )
return - V_76 ;
V_64 = ( V_29 -> V_25 == V_26 ?
V_77 : V_78 ) + V_79 ;
F_32 ( & V_2 -> V_62 ) ;
F_33 ( V_2 ) ;
F_18 ( V_2 ) ;
for ( V_19 = 0 , V_51 = V_4 -> V_49 . V_14 ; V_19 < V_4 -> V_58 ; V_19 ++ , V_51 ++ )
F_34 ( & V_51 -> V_64 , V_64 ) ;
F_21 ( V_4 , & V_4 -> V_49 ) ;
( void ) F_16 ( & V_4 -> V_35 -> V_36 ) ;
F_22 ( V_4 , V_37 | V_46 ) ;
V_4 -> V_75 = 1 ;
F_35 ( & V_2 -> V_62 ) ;
break;
case V_80 :
case V_81 :
F_32 ( & V_2 -> V_62 ) ;
V_4 -> V_75 = 0 ;
F_20 ( V_4 ) ;
for ( V_19 = 0 , V_51 = V_4 -> V_49 . V_14 ; V_19 < V_4 -> V_58 ; V_19 ++ , V_51 ++ )
F_34 ( & V_51 -> V_64 , V_65 ) ;
F_35 ( & V_2 -> V_62 ) ;
break;
default:
return - V_60 ;
}
return 0 ;
}
inline
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_17 * V_4 ,
struct V_28 * V_29 )
{
int V_82 = 0 ;
#if 1
int V_83 ;
volatile struct V_7 V_15 * V_51 = & V_4 -> V_49 . V_14 [ V_4 -> V_59 ] ;
V_83 = F_37 ( & V_51 -> V_69 ) ;
if ( V_83 & ( V_84 | V_85 ) ) {
V_82 = F_38 ( & V_51 -> V_86 ) ;
if ( V_82 )
V_82 = V_4 -> V_57 - V_82 ;
}
#endif
V_82 += V_4 -> V_59 * V_4 -> V_57 ;
return F_39 ( V_29 -> V_53 , V_82 ) ;
}
static int F_40 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_23 ( V_2 , & V_2 -> V_32 , V_29 ) ;
}
static int F_42 ( struct V_28 * V_29 ,
int V_49 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_31 ( V_2 , & V_2 -> V_32 , V_29 , V_49 ) ;
}
static T_1 F_43 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_36 ( V_2 , & V_2 -> V_32 , V_29 ) ;
}
static int F_44 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_23 ( V_2 , & V_2 -> V_33 , V_29 ) ;
}
static int F_45 ( struct V_28 * V_29 ,
int V_49 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_31 ( V_2 , & V_2 -> V_33 , V_29 , V_49 ) ;
}
static T_1 F_46 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_36 ( V_2 , & V_2 -> V_33 , V_29 ) ;
}
static inline void F_47 ( struct V_17 * V_4 ,
volatile struct V_7 V_15 * V_51 )
{
unsigned short V_87 , V_88 ;
unsigned int V_89 ;
( void ) F_16 ( & V_4 -> V_35 -> V_36 ) ;
F_19 ( & V_4 -> V_35 -> V_39 , ( V_37 | V_48 | V_47 | V_46 ) << 16 ) ;
if ( ! V_90 ) {
memcpy ( ( void * ) V_91 . V_14 , ( void * ) V_51 ,
sizeof( struct V_7 ) ) ;
V_90 = 1 ;
F_27 ( & V_51 -> V_69 , 0 ) ;
F_27 ( & V_51 -> V_68 , V_4 -> V_57 ) ;
V_51 = V_91 . V_14 ;
}
V_87 = F_37 ( & V_51 -> V_68 ) ;
V_88 = F_37 ( & V_51 -> V_86 ) ;
V_89 = F_48 ( & V_51 -> V_67 ) ;
V_89 += ( V_87 - V_88 ) ;
F_27 ( & V_51 -> V_68 , V_88 ) ;
F_27 ( & V_51 -> V_86 , 0 ) ;
F_27 ( & V_51 -> V_69 , 0 ) ;
F_30 ( & V_51 -> V_67 , V_89 ) ;
F_30 ( & V_51 -> V_72 , V_4 -> V_49 . V_16
+ sizeof( struct V_7 ) * ( ( V_4 -> V_59 + 1 ) % V_4 -> V_58 ) ) ;
F_27 ( & V_51 -> V_64 , V_77 | V_71 | V_79 ) ;
F_19 ( & V_4 -> V_35 -> V_50 , V_91 . V_16 ) ;
( void ) F_16 ( & V_4 -> V_35 -> V_36 ) ;
F_19 ( & V_4 -> V_35 -> V_39 , ( ( V_37 | V_46 ) << 16 ) + ( V_37 | V_46 ) ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_17 * V_4 )
{
volatile struct V_7 V_15 * V_51 ;
int V_92 ;
int V_83 ;
F_32 ( & V_2 -> V_62 ) ;
if ( V_4 -> V_75 ) {
for ( V_92 = 0 ; V_92 < V_4 -> V_58 ; V_92 ++ ) {
if ( V_90 )
V_51 = V_91 . V_14 ;
else
V_51 = & V_4 -> V_49 . V_14 [ V_4 -> V_59 ] ;
V_83 = F_37 ( & V_51 -> V_69 ) ;
if ( V_83 & V_85 ) {
F_47 ( V_4 , V_51 ) ;
break;
}
if ( V_90 )
V_90 = 0 ;
if ( ! ( V_83 & V_84 ) )
break;
F_27 ( & V_51 -> V_69 , 0 ) ;
F_27 ( & V_51 -> V_68 , V_4 -> V_57 ) ;
V_4 -> V_59 ++ ;
if ( V_4 -> V_59 >= V_4 -> V_58 ) {
V_4 -> V_59 = 0 ;
}
F_35 ( & V_2 -> V_62 ) ;
F_50 ( V_4 -> V_93 ) ;
F_32 ( & V_2 -> V_62 ) ;
}
}
F_35 ( & V_2 -> V_62 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_17 * V_4 ,
struct V_28 * V_29 )
{
struct V_52 * V_53 = V_29 -> V_53 ;
int V_19 ;
V_53 -> V_94 . V_95 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_24 ; V_19 ++ )
if ( V_2 -> V_96 & ( 1 << V_19 ) )
V_53 -> V_94 . V_95 |=
F_52 ( V_2 -> V_23 [ V_19 ] ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_24 ; V_19 ++ ) {
if ( V_2 -> V_96 & ( 1 << V_19 ) ) {
V_53 -> V_94 . V_97 = V_2 -> V_23 [ V_19 ] ;
break;
}
}
for ( V_19 = V_2 -> V_24 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( V_2 -> V_96 & ( 1 << V_19 ) ) {
V_53 -> V_94 . V_98 = V_2 -> V_23 [ V_19 ] ;
break;
}
}
V_53 -> V_94 . V_99 = V_2 -> V_100 ;
if ( V_2 -> V_101 ) {
if ( ! V_2 -> V_102 )
V_53 -> V_94 . V_103 |= V_104 ;
V_53 -> V_94 . V_103 |= V_105 ;
}
V_53 -> V_106 = V_4 ;
V_4 -> V_93 = V_29 ;
#if 0
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
snd_pmac_hw_rule_rate, chip, rec->stream, -1);
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_FORMAT,
snd_pmac_hw_rule_format, chip, rec->stream, -1);
#endif
V_53 -> V_94 . V_107 = V_4 -> V_49 . V_5 - 1 ;
F_53 ( V_53 , V_108 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_17 * V_4 ,
struct V_28 * V_29 )
{
struct V_17 * V_55 ;
F_20 ( V_4 ) ;
V_55 = F_13 ( V_2 , F_7 ( V_4 -> V_25 ) ) ;
if ( ! V_55 )
return - V_60 ;
V_55 -> V_22 = V_2 -> V_96 ;
V_55 -> V_61 = V_2 -> V_100 ;
return 0 ;
}
static int F_55 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
V_29 -> V_53 -> V_94 = V_109 ;
return F_51 ( V_2 , & V_2 -> V_32 , V_29 ) ;
}
static int F_56 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
V_29 -> V_53 -> V_94 = V_110 ;
return F_51 ( V_2 , & V_2 -> V_33 , V_29 ) ;
}
static int F_57 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_54 ( V_2 , & V_2 -> V_32 , V_29 ) ;
}
static int F_58 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
return F_54 ( V_2 , & V_2 -> V_33 , V_29 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
int V_113 ;
int V_114 = 1 ;
if ( ! V_2 -> V_101 )
V_114 = 0 ;
V_113 = F_60 ( V_2 -> V_115 , V_2 -> V_115 -> V_116 , 0 , 1 , V_114 , & V_112 ) ;
if ( V_113 < 0 )
return V_113 ;
F_61 ( V_112 , V_26 , & V_117 ) ;
if ( V_2 -> V_101 )
F_61 ( V_112 , V_27 , & V_118 ) ;
V_112 -> V_106 = V_2 ;
V_112 -> V_119 = V_105 ;
strcpy ( V_112 -> V_120 , V_2 -> V_115 -> V_121 ) ;
V_2 -> V_112 = V_112 ;
V_2 -> V_100 = V_122 ;
if ( V_2 -> V_123 )
V_2 -> V_100 |= V_124 ;
V_2 -> V_32 . V_61 = V_2 -> V_100 ;
V_2 -> V_33 . V_61 = V_2 -> V_100 ;
V_2 -> V_32 . V_22 = V_2 -> V_96 ;
V_2 -> V_33 . V_22 = V_2 -> V_96 ;
F_62 ( V_112 , V_125 ,
& V_2 -> V_9 -> V_10 ,
64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_32 . V_35 -> V_39 , ( V_37 | V_48 | V_47 | V_46 | V_85 ) << 16 ) ;
F_15 ( & V_2 -> V_32 ) ;
F_19 ( & V_2 -> V_33 . V_35 -> V_39 , ( V_37 | V_48 | V_47 | V_46 | V_85 ) << 16 ) ;
F_15 ( & V_2 -> V_33 ) ;
}
void F_64 ( struct V_1 * V_2 , int V_126 , unsigned long V_16 , int V_127 )
{
struct V_17 * V_4 = & V_2 -> V_32 ;
F_20 ( V_4 ) ;
F_27 ( & V_2 -> V_63 . V_14 -> V_68 , V_126 ) ;
F_27 ( & V_2 -> V_63 . V_14 -> V_69 , 0 ) ;
F_30 ( & V_2 -> V_63 . V_14 -> V_72 , V_2 -> V_63 . V_16 ) ;
F_30 ( & V_2 -> V_63 . V_14 -> V_67 , V_16 ) ;
F_27 ( & V_2 -> V_63 . V_14 -> V_64 , V_77 + V_71 ) ;
F_19 ( & V_2 -> V_38 -> V_39 ,
( F_16 ( & V_2 -> V_38 -> V_39 ) & ~ 0x1f00 )
| ( V_127 << 8 ) ) ;
F_19 ( & V_2 -> V_38 -> V_42 , 0 ) ;
F_21 ( V_4 , & V_2 -> V_63 ) ;
F_22 ( V_4 , V_37 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_32 ) ;
F_27 ( & V_2 -> V_63 . V_14 -> V_64 , V_65 ) ;
F_18 ( V_2 ) ;
}
static T_2
F_66 ( int V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
F_49 ( V_2 , & V_2 -> V_32 ) ;
return V_130 ;
}
static T_2
F_67 ( int V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
F_49 ( V_2 , & V_2 -> V_33 ) ;
return V_130 ;
}
static T_2
F_68 ( int V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
int V_131 = F_16 ( & V_2 -> V_38 -> V_39 ) ;
if ( V_131 & V_132 ) {
if ( V_2 -> V_133 )
V_2 -> V_133 ( V_2 , 1 ) ;
}
if ( V_131 & V_134 ) {
int V_113 = ( F_16 ( & V_2 -> V_38 -> V_135 ) & V_136 ) >> 16 ;
if ( V_113 && V_2 -> V_137 <= V_138 )
F_69 ( V_139 L_1 , V_113 ) ;
}
F_19 ( & V_2 -> V_38 -> V_39 , V_131 ) ;
return V_130 ;
}
static void F_70 ( struct V_1 * V_2 , int V_140 )
{
if ( V_141 . V_142 )
V_141 . V_142 ( V_143 , V_2 -> V_144 , 0 , V_140 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 ) {
F_63 ( V_2 ) ;
F_19 ( & V_2 -> V_38 -> V_39 , F_16 ( & V_2 -> V_38 -> V_39 ) & 0xfff ) ;
}
if ( V_2 -> V_144 )
F_70 ( V_2 , 0 ) ;
if ( V_2 -> V_146 )
V_2 -> V_146 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_128 >= 0 )
F_73 ( V_2 -> V_128 , ( void * ) V_2 ) ;
if ( V_2 -> V_147 >= 0 )
F_73 ( V_2 -> V_147 , ( void * ) V_2 ) ;
if ( V_2 -> V_148 >= 0 )
F_73 ( V_2 -> V_148 , ( void * ) V_2 ) ;
F_4 ( V_2 , & V_2 -> V_32 . V_49 ) ;
F_4 ( V_2 , & V_2 -> V_33 . V_49 ) ;
F_4 ( V_2 , & V_2 -> V_63 ) ;
F_4 ( V_2 , & V_91 ) ;
if ( V_2 -> V_149 )
F_74 ( V_2 -> V_149 ) ;
if ( V_2 -> V_150 )
F_74 ( V_2 -> V_150 ) ;
if ( V_2 -> V_38 )
F_74 ( V_2 -> V_38 ) ;
if ( V_2 -> V_32 . V_35 )
F_74 ( V_2 -> V_32 . V_35 ) ;
if ( V_2 -> V_33 . V_35 )
F_74 ( V_2 -> V_33 . V_35 ) ;
if ( V_2 -> V_144 ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( V_2 -> V_151 & ( 1 << V_19 ) )
F_75 ( V_2 -> V_152 [ V_19 ] . V_153 ,
F_76 ( & V_2 -> V_152 [ V_19 ] ) ) ;
}
}
if ( V_2 -> V_9 )
F_77 ( V_2 -> V_9 ) ;
F_78 ( V_2 -> V_144 ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_156 ;
return F_71 ( V_2 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
for ( V_158 = V_2 -> V_144 -> V_159 ; V_158 ; V_158 = V_158 -> V_159 ) {
if ( strcmp ( V_158 -> V_120 , L_2 ) == 0 ) {
if ( F_82 ( V_158 , L_3 ) )
V_2 -> V_123 = 0 ;
break;
}
}
if ( F_83 ( L_4 ) ||
F_83 ( L_5 ) )
V_2 -> V_123 = 0 ;
if ( F_83 ( L_5 ) )
V_2 -> V_102 = 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_157 * V_160 ;
struct V_157 * V_161 ;
const unsigned int * V_162 ;
unsigned int V_163 ;
struct V_164 * V_165 ;
if ( ! F_85 ( V_166 ) )
return - V_167 ;
V_2 -> V_168 = 0 ;
V_2 -> V_169 = 0 ;
V_2 -> V_96 = 0xff ;
V_2 -> V_137 = V_170 ;
V_2 -> V_123 = 1 ;
V_2 -> V_102 = 1 ;
V_2 -> V_101 = 1 ;
V_2 -> V_24 = F_86 ( V_171 ) ;
V_2 -> V_23 = V_171 ;
V_2 -> V_9 = NULL ;
V_2 -> V_40 = V_172 | V_173 | 0x11 ;
if ( F_83 ( L_6 )
|| F_83 ( L_7 ) )
V_2 -> V_174 = 1 ;
else if ( F_83 ( L_8 )
|| F_83 ( L_9 ) )
V_2 -> V_175 = 1 ;
V_2 -> V_144 = F_87 ( NULL , L_10 ) ;
V_160 = F_88 ( V_2 -> V_144 ) ;
if ( ! V_2 -> V_144 )
V_2 -> V_144 = F_87 ( NULL , L_11 ) ;
if ( ! V_2 -> V_144 ) {
V_2 -> V_144 = F_87 ( NULL , L_12 ) ;
if ( V_2 -> V_144 && V_2 -> V_144 -> V_159 &&
V_2 -> V_144 -> V_159 -> V_159 ) {
if ( F_82 ( V_2 -> V_144 -> V_159 -> V_159 ,
L_13 ) )
V_2 -> V_176 = 1 ;
}
}
if ( ! V_2 -> V_144 )
return - V_167 ;
if ( ! V_160 ) {
F_89 (sound, L_14 )
if ( V_160 -> V_159 == V_2 -> V_144 )
break;
}
if ( ! V_160 ) {
F_78 ( V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
return - V_167 ;
}
V_162 = F_90 ( V_160 , L_15 , NULL ) ;
if ( V_162 && * V_162 < 16 )
V_2 -> V_168 = * V_162 ;
V_162 = F_90 ( V_160 , L_16 , NULL ) ;
if ( V_162 ) {
F_91 ( V_177 L_17
L_18
L_19 ) ;
F_78 ( V_160 ) ;
F_78 ( V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
return - V_167 ;
}
if ( F_82 ( V_160 , L_20 ) ) {
V_2 -> V_137 = V_138 ;
}
if ( F_82 ( V_160 , L_21 ) ) {
V_2 -> V_137 = V_178 ;
V_2 -> V_40 = V_172 | 0x11 ;
}
if ( F_82 ( V_160 , L_22 ) ) {
V_2 -> V_137 = V_179 ;
V_2 -> V_101 = 0 ;
V_2 -> V_102 = 0 ;
V_2 -> V_40 = V_172 | 0x11 ;
}
if ( F_82 ( V_160 , L_23 ) ) {
V_2 -> V_137 = V_180 ;
V_2 -> V_101 = F_83 ( L_24 )
|| F_83 ( L_25 )
|| F_83 ( L_26 )
|| F_83 ( L_27 )
|| F_83 ( L_28 )
|| F_83 ( L_29 ) ;
V_2 -> V_102 = 0 ;
V_2 -> V_24 = F_86 ( V_181 ) ;
V_2 -> V_23 = V_181 ;
V_2 -> V_40 = V_172 | 0x11 ;
}
if ( F_82 ( V_160 , L_30 ) ) {
V_2 -> V_137 = V_182 ;
V_2 -> V_24 = F_86 ( V_181 ) ;
V_2 -> V_23 = V_181 ;
V_2 -> V_40 = V_172 | 0x11 ;
}
V_162 = F_90 ( V_160 , L_31 , NULL ) ;
if ( V_162 )
V_2 -> V_183 = * V_162 ;
V_161 = F_87 ( NULL , L_32 ) ;
V_2 -> V_184 = ( V_161 != NULL ) ;
F_78 ( V_161 ) ;
V_165 = F_92 ( V_2 -> V_144 , V_185 ) ;
if ( V_165 == NULL )
F_91 ( V_186 L_33 ) ;
else {
struct V_187 * V_9 = NULL ;
F_93 (pdev) {
struct V_157 * V_188 = F_94 ( V_9 ) ;
if ( V_188 && V_188 == V_165 -> V_189 ) {
V_2 -> V_9 = V_9 ;
break;
}
}
}
if ( V_2 -> V_9 == NULL )
F_91 ( V_186 L_34
L_35 ) ;
F_81 ( V_2 ) ;
V_162 = F_90 ( V_160 , L_36 , & V_163 ) ;
if ( ! V_162 )
V_162 = F_90 ( V_160 , L_37 , & V_163 ) ;
if ( V_162 ) {
int V_19 ;
V_2 -> V_96 = 0 ;
for ( V_163 /= sizeof( int ) ; V_163 > 0 ; -- V_163 ) {
unsigned int V_190 = * V_162 ++ ;
if ( V_190 >= 0x10000 )
V_190 >>= 16 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_24 ; ++ V_19 ) {
if ( V_190 == V_2 -> V_23 [ V_19 ] ) {
V_2 -> V_96 |= ( 1 << V_19 ) ;
break;
}
}
}
} else {
V_2 -> V_96 = 1 ;
}
F_78 ( V_160 ) ;
return 0 ;
}
static int F_95 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 = F_96 ( V_192 ) ;
V_194 -> V_195 . integer . V_195 [ 0 ] = V_2 -> V_196 ;
return 0 ;
}
static int F_97 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 = F_96 ( V_192 ) ;
if ( V_194 -> V_195 . integer . V_195 [ 0 ] != V_2 -> V_196 ) {
V_2 -> V_196 = ! ! V_194 -> V_195 . integer . V_195 [ 0 ] ;
if ( V_2 -> V_133 )
V_2 -> V_133 ( V_2 , 1 ) ;
return 1 ;
}
return 0 ;
}
static int F_98 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 = F_96 ( V_192 ) ;
if ( V_2 -> V_197 )
V_194 -> V_195 . integer . V_195 [ 0 ] = V_2 -> V_197 ( V_2 ) ;
else
V_194 -> V_195 . integer . V_195 [ 0 ] = 0 ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 )
{
int V_113 ;
V_2 -> V_196 = 1 ;
V_113 = F_100 ( V_2 -> V_115 , F_101 ( & V_198 [ 0 ] , V_2 ) ) ;
if ( V_113 < 0 ) {
F_91 ( V_199 L_38 ) ;
return V_113 ;
}
V_2 -> V_200 = F_101 ( & V_198 [ 1 ] , V_2 ) ;
return F_100 ( V_2 -> V_115 , V_2 -> V_200 ) ;
}
int F_102 ( struct V_201 * V_115 , struct V_1 * * V_202 )
{
struct V_1 * V_2 ;
struct V_157 * V_188 ;
int V_19 , V_113 ;
unsigned int V_128 ;
unsigned long V_203 , V_204 , V_205 ;
static struct V_206 V_207 = {
. V_208 = F_80 ,
} ;
* V_202 = NULL ;
V_2 = F_103 ( sizeof( * V_2 ) , V_12 ) ;
if ( V_2 == NULL )
return - V_13 ;
V_2 -> V_115 = V_115 ;
F_104 ( & V_2 -> V_62 ) ;
V_2 -> V_128 = V_2 -> V_147 = V_2 -> V_148 = - 1 ;
V_2 -> V_32 . V_25 = V_26 ;
V_2 -> V_33 . V_25 = V_27 ;
if ( ( V_113 = F_84 ( V_2 ) ) < 0 )
goto V_209;
if ( F_1 ( V_2 , & V_2 -> V_32 . V_49 , V_210 + 1 ) < 0 ||
F_1 ( V_2 , & V_2 -> V_33 . V_49 , V_210 + 1 ) < 0 ||
F_1 ( V_2 , & V_2 -> V_63 , 2 ) < 0 ||
F_1 ( V_2 , & V_91 , 2 ) < 0 ) {
V_113 = - V_13 ;
goto V_209;
}
V_188 = V_2 -> V_144 ;
V_2 -> V_151 = 0 ;
if ( V_2 -> V_176 ) {
static char * V_211 [] = {
L_39 , L_40 } ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
if ( F_105 ( V_188 -> V_159 , V_19 ,
& V_2 -> V_152 [ V_19 ] ) ) {
F_91 ( V_199 L_41
L_42 , V_19 , V_211 [ V_19 ] ) ;
V_113 = - V_167 ;
goto V_209;
}
if ( F_106 ( V_2 -> V_152 [ V_19 ] . V_153 ,
F_76 ( & V_2 -> V_152 [ V_19 ] ) ,
V_211 [ V_19 ] ) == NULL ) {
F_91 ( V_199 L_43
L_44 ,
V_19 , V_211 [ V_19 ] , & V_2 -> V_152 [ V_19 ] ) ;
V_113 = - V_167 ;
goto V_209;
}
V_2 -> V_151 |= ( 1 << V_19 ) ;
}
V_203 = V_2 -> V_152 [ 0 ] . V_153 ;
V_204 = V_2 -> V_152 [ 1 ] . V_153 ;
V_205 = V_204 + 0x100 ;
} else {
static char * V_211 [] = {
L_39 , L_45 , L_46 } ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( F_105 ( V_188 , V_19 ,
& V_2 -> V_152 [ V_19 ] ) ) {
F_91 ( V_199 L_41
L_42 , V_19 , V_211 [ V_19 ] ) ;
V_113 = - V_167 ;
goto V_209;
}
if ( F_106 ( V_2 -> V_152 [ V_19 ] . V_153 ,
F_76 ( & V_2 -> V_152 [ V_19 ] ) ,
V_211 [ V_19 ] ) == NULL ) {
F_91 ( V_199 L_43
L_44 ,
V_19 , V_211 [ V_19 ] , & V_2 -> V_152 [ V_19 ] ) ;
V_113 = - V_167 ;
goto V_209;
}
V_2 -> V_151 |= ( 1 << V_19 ) ;
}
V_203 = V_2 -> V_152 [ 0 ] . V_153 ;
V_204 = V_2 -> V_152 [ 1 ] . V_153 ;
V_205 = V_2 -> V_152 [ 2 ] . V_153 ;
}
V_2 -> V_38 = F_107 ( V_203 , 0x1000 ) ;
V_2 -> V_32 . V_35 = F_107 ( V_204 , 0x100 ) ;
V_2 -> V_33 . V_35 = F_107 ( V_205 , 0x100 ) ;
if ( V_2 -> V_137 <= V_178 ) {
V_128 = F_108 ( V_188 , 0 ) ;
if ( F_109 ( V_128 , F_68 , 0 ,
L_47 , ( void * ) V_2 ) ) {
F_69 ( V_199 L_48 ,
V_128 ) ;
V_113 = - V_76 ;
goto V_209;
}
V_2 -> V_128 = V_128 ;
}
V_128 = F_108 ( V_188 , 1 ) ;
if ( F_109 ( V_128 , F_66 , 0 , L_49 , ( void * ) V_2 ) ) {
F_69 ( V_199 L_48 , V_128 ) ;
V_113 = - V_76 ;
goto V_209;
}
V_2 -> V_147 = V_128 ;
V_128 = F_108 ( V_188 , 2 ) ;
if ( F_109 ( V_128 , F_67 , 0 , L_50 , ( void * ) V_2 ) ) {
F_69 ( V_199 L_48 , V_128 ) ;
V_113 = - V_76 ;
goto V_209;
}
V_2 -> V_148 = V_128 ;
F_70 ( V_2 , 1 ) ;
if ( V_2 -> V_137 <= V_178 )
F_19 ( & V_2 -> V_38 -> V_39 , V_2 -> V_40 ) ;
if ( V_2 -> V_174 ) {
V_2 -> V_150 = F_107 ( 0xf301a000 , 0x1000 ) ;
F_110 ( V_2 -> V_150 + 0x190 ) ;
} else if ( V_2 -> V_175 ) {
struct V_157 * V_158 ;
for ( V_158 = V_2 -> V_144 -> V_159 ; V_158 ; V_158 = V_158 -> V_159 ) {
if ( strcmp ( V_158 -> V_120 , L_2 ) == 0 ) {
struct V_212 V_190 ;
if ( F_105 ( V_158 , 0 , & V_190 ) == 0 )
V_2 -> V_149 =
F_107 ( V_190 . V_153 , 0x40 ) ;
break;
}
}
if ( V_2 -> V_149 )
F_111 ( V_2 -> V_149 + 0x37 , 3 ) ;
}
F_63 ( V_2 ) ;
if ( ( V_113 = F_112 ( V_115 , V_213 , V_2 , & V_207 ) ) < 0 )
goto V_209;
* V_202 = V_2 ;
return 0 ;
V_209:
F_71 ( V_2 ) ;
return V_113 ;
}
void F_113 ( struct V_1 * V_2 )
{
unsigned long V_214 ;
F_114 ( V_2 -> V_115 , V_215 ) ;
if ( V_2 -> V_216 )
V_2 -> V_216 ( V_2 ) ;
F_115 ( V_2 -> V_112 ) ;
F_116 ( & V_2 -> V_62 , V_214 ) ;
F_33 ( V_2 ) ;
F_117 ( & V_2 -> V_62 , V_214 ) ;
if ( V_2 -> V_128 >= 0 )
F_118 ( V_2 -> V_128 ) ;
if ( V_2 -> V_147 >= 0 )
F_118 ( V_2 -> V_147 ) ;
if ( V_2 -> V_148 >= 0 )
F_118 ( V_2 -> V_148 ) ;
F_70 ( V_2 , 0 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_70 ( V_2 , 1 ) ;
if ( V_2 -> V_217 )
V_2 -> V_217 ( V_2 ) ;
if ( V_2 -> V_149 && V_2 -> V_175 )
F_111 ( V_2 -> V_149 + 0x37 , 3 ) ;
else if ( V_2 -> V_174 )
F_110 ( V_2 -> V_150 + 0x190 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_128 >= 0 )
F_120 ( V_2 -> V_128 ) ;
if ( V_2 -> V_147 >= 0 )
F_120 ( V_2 -> V_147 ) ;
if ( V_2 -> V_148 >= 0 )
F_120 ( V_2 -> V_148 ) ;
F_114 ( V_2 -> V_115 , V_218 ) ;
}
