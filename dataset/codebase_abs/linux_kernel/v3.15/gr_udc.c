static const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
[ V_10 ] = L_7 ,
[ V_11 ] = L_8 ,
} ;
if ( V_2 < 0 || V_2 >= F_2 ( V_3 ) )
return L_9 ;
return V_3 [ V_2 ] ;
}
static void F_3 ( const char * V_12 , struct V_13 * V_14 ,
struct V_15 * V_16 )
{
int V_17 = V_14 -> V_18 ? V_16 -> V_16 . V_19 : V_16 -> V_16 . V_20 ;
int V_21 = 32 ;
int V_22 = F_4 ( V_21 , V_17 ) ;
F_5 ( V_14 -> V_23 -> V_23 , L_10 , V_12 , V_16 , V_17 ,
( V_17 > V_22 ? L_11 : L_12 ) ) ;
F_6 ( L_13 , V_24 ,
V_21 , 4 , V_16 -> V_16 . V_25 , V_22 , false ) ;
}
static void F_7 ( struct V_26 * V_23 , T_1 type , T_1 V_27 ,
T_2 V_28 , T_2 V_29 , T_2 V_19 )
{
F_8 ( V_23 -> V_23 , L_14 ,
type , V_27 , V_28 , V_29 , V_19 ) ;
}
static void F_3 ( const char * V_12 , struct V_13 * V_14 ,
struct V_15 * V_16 ) {}
static void F_7 ( struct V_26 * V_23 , T_1 type , T_1 V_27 ,
T_2 V_28 , T_2 V_29 , T_2 V_19 ) {}
static void F_9 ( struct V_30 * V_31 , struct V_13 * V_14 )
{
T_3 V_32 = F_10 ( & V_14 -> V_33 -> V_32 ) ;
T_3 V_34 = F_10 ( & V_14 -> V_33 -> V_34 ) ;
int V_35 = ( V_32 & V_36 ) >> V_37 ;
struct V_15 * V_16 ;
F_11 ( V_31 , L_15 , V_14 -> V_14 . V_38 ) ;
F_11 ( V_31 , L_16 , V_39 [ V_35 ] ) ;
F_11 ( V_31 , L_17 , ! ! ( V_32 & V_40 ) ) ;
F_11 ( V_31 , L_18 , ! ! ( V_32 & V_41 ) ) ;
F_11 ( V_31 , L_19 , ! ! ( V_32 & V_42 ) ) ;
F_11 ( V_31 , L_20 , V_14 -> V_43 ) ;
F_11 ( V_31 , L_21 , V_14 -> V_44 ) ;
F_11 ( V_31 , L_22 , V_14 -> V_45 ) ;
F_11 ( V_31 , L_23 , V_14 -> V_46 ) ;
F_11 ( V_31 , L_24 , V_14 -> V_14 . V_47 ) ;
F_11 ( V_31 , L_25 , V_14 -> V_48 ) ;
if ( V_35 == 1 || V_35 == 3 )
F_11 ( V_31 , L_26 ,
( V_32 & V_49 ) >> V_50 ) ;
F_11 ( V_31 , L_27 ,
V_34 & V_51 ? L_28 : L_29 ,
V_34 & V_52 ? L_30 : L_31 ,
( V_34 & V_53 ) >> V_54 ) ;
F_11 ( V_31 , L_32 ,
V_34 & V_55 ? L_28 : L_29 ,
V_34 & V_52 ? L_31 : L_30 ,
( V_34 & V_56 ) >> V_57 ) ;
if ( F_12 ( & V_14 -> V_58 ) ) {
F_13 ( V_31 , L_33 ) ;
return;
}
F_13 ( V_31 , L_34 ) ;
F_14 (req, &ep->queue, queue) {
struct V_59 * V_60 ;
struct V_59 * V_61 ;
F_11 ( V_31 , L_35 , V_16 ,
& V_16 -> V_16 . V_25 , V_16 -> V_16 . V_20 , V_16 -> V_16 . V_19 ) ;
V_61 = V_16 -> V_62 ;
do {
V_60 = V_61 ;
V_61 = V_60 -> V_63 ;
F_11 ( V_31 , L_36 ,
V_60 == V_16 -> V_64 ? 'c' : ' ' ,
V_60 , V_60 -> V_65 , V_60 -> V_66 , V_60 -> V_67 ) ;
} while ( V_60 != V_16 -> V_68 );
}
F_13 ( V_31 , L_37 ) ;
}
static int F_15 ( struct V_30 * V_31 , void * V_69 )
{
struct V_26 * V_23 = V_31 -> V_70 ;
T_3 V_71 = F_10 ( & V_23 -> V_33 -> V_71 ) ;
T_3 V_72 = F_10 ( & V_23 -> V_33 -> V_72 ) ;
struct V_13 * V_14 ;
F_11 ( V_31 , L_38 ,
F_16 ( V_23 -> V_73 . V_2 ) ) ;
F_11 ( V_31 , L_39 ,
( V_71 & V_74 ) >> V_75 ) ;
F_11 ( V_31 , L_40 , F_17 ( V_72 ) ) ;
F_11 ( V_31 , L_41 , F_1 ( V_23 -> V_76 ) ) ;
F_11 ( V_31 , L_42 , V_23 -> V_77 ) ;
F_11 ( V_31 , L_43 , V_23 -> V_78 ) ;
F_11 ( V_31 , L_44 , V_23 -> V_79 ) ;
F_13 ( V_31 , L_37 ) ;
F_14 (ep, &dev->ep_list, ep_list)
F_9 ( V_31 , V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_19 ( V_81 , F_15 , V_80 -> V_82 ) ;
}
static void F_20 ( struct V_26 * V_23 )
{
const char * V_38 = L_45 ;
V_23 -> V_83 = F_21 ( F_22 ( V_23 -> V_23 ) , NULL ) ;
V_23 -> V_84 = F_23 ( V_38 , 0444 , V_23 -> V_83 , V_23 ,
& V_85 ) ;
}
static void F_24 ( struct V_26 * V_23 )
{
F_25 ( V_23 -> V_84 ) ;
F_25 ( V_23 -> V_83 ) ;
}
static void F_20 ( struct V_26 * V_23 ) {}
static void F_24 ( struct V_26 * V_23 ) {}
static struct V_59 * F_26 ( struct V_13 * V_14 , T_4 V_86 )
{
T_5 V_65 ;
struct V_59 * V_87 ;
V_87 = F_27 ( V_14 -> V_23 -> V_88 , V_86 , & V_65 ) ;
if ( ! V_87 ) {
F_28 ( V_14 -> V_23 -> V_23 , L_46 ) ;
return NULL ;
}
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_65 = V_65 ;
return V_87 ;
}
static inline void F_29 ( struct V_26 * V_23 ,
struct V_59 * V_60 )
{
F_30 ( V_23 -> V_88 , V_60 , ( T_5 ) V_60 -> V_65 ) ;
}
static void F_31 ( struct V_26 * V_23 , struct V_15 * V_16 )
{
struct V_59 * V_60 ;
struct V_59 * V_61 ;
V_61 = V_16 -> V_62 ;
if ( ! V_61 )
return;
do {
V_60 = V_61 ;
V_61 = V_60 -> V_63 ;
F_29 ( V_23 , V_60 ) ;
} while ( V_60 != V_16 -> V_68 );
V_16 -> V_62 = NULL ;
V_16 -> V_64 = NULL ;
V_16 -> V_68 = NULL ;
}
static void F_32 ( struct V_13 * V_14 , struct V_15 * V_16 ,
int V_72 )
__releases( &dev->lock
static struct V_89 * F_33 ( struct V_90 * V_91 , T_4 V_86 )
{
struct V_15 * V_16 ;
V_16 = F_34 ( sizeof( * V_16 ) , V_86 ) ;
if ( ! V_16 )
return NULL ;
F_35 ( & V_16 -> V_58 ) ;
return & V_16 -> V_16 ;
}
static void F_36 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
T_3 V_92 ;
if ( F_12 ( & V_14 -> V_58 ) ) {
V_14 -> V_43 = 0 ;
return;
}
V_16 = F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) ;
F_38 ( ! V_16 -> V_64 ) ;
F_39 () ;
F_40 ( & V_14 -> V_33 -> V_93 , V_16 -> V_64 -> V_65 ) ;
V_92 = F_10 ( & V_14 -> V_33 -> V_92 ) ;
F_40 ( & V_14 -> V_33 -> V_92 , V_92 | V_94 ) ;
V_14 -> V_43 = 1 ;
}
static void F_41 ( struct V_13 * V_14 , int V_72 )
{
struct V_15 * V_16 ;
V_16 = F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) ;
F_32 ( V_14 , V_16 , V_72 ) ;
F_36 ( V_14 ) ;
}
static void F_42 ( struct V_13 * V_14 )
{
T_3 V_92 ;
V_92 = F_10 ( & V_14 -> V_33 -> V_92 ) ;
F_40 ( & V_14 -> V_33 -> V_92 , V_92 | V_95 ) ;
}
static int F_43 ( struct V_13 * V_14 , struct V_15 * V_16 ,
T_5 V_67 , unsigned V_96 , T_4 V_86 )
{
struct V_59 * V_60 ;
V_60 = F_26 ( V_14 , V_86 ) ;
if ( ! V_60 )
return - V_97 ;
V_60 -> V_67 = V_67 ;
if ( V_14 -> V_18 )
V_60 -> V_66 =
( V_98 & V_96 ) | V_99 ;
else
V_60 -> V_66 = V_100 ;
if ( ! V_16 -> V_62 ) {
V_16 -> V_62 = V_60 ;
V_16 -> V_64 = V_60 ;
} else {
V_16 -> V_68 -> V_63 = V_60 ;
V_16 -> V_68 -> V_61 = V_60 -> V_65 ;
V_16 -> V_68 -> V_66 |= V_101 ;
}
V_16 -> V_68 = V_60 ;
return 0 ;
}
static int F_44 ( struct V_13 * V_14 , struct V_15 * V_16 ,
T_4 V_86 )
{
T_2 V_102 ;
T_2 V_103 ;
int V_104 = 0 ;
V_16 -> V_62 = NULL ;
V_102 = V_16 -> V_16 . V_19 ;
V_103 = 0 ;
while ( V_102 > 0 ) {
T_5 V_105 = V_16 -> V_16 . V_106 + V_103 ;
T_2 V_96 = F_4 ( V_102 , V_14 -> V_48 ) ;
if ( V_96 < V_14 -> V_48 )
F_45 ( V_14 -> V_23 -> V_23 ,
L_47 ,
V_96 , V_14 -> V_48 ) ;
V_104 = F_43 ( V_14 , V_16 , V_105 , V_96 , V_86 ) ;
if ( V_104 )
goto V_107;
V_102 -= V_96 ;
V_103 += V_96 ;
}
V_16 -> V_62 -> V_66 |= V_108 ;
return 0 ;
V_107:
F_31 ( V_14 -> V_23 , V_16 ) ;
return V_104 ;
}
static int F_46 ( struct V_13 * V_14 , struct V_15 * V_16 ,
T_4 V_86 )
{
T_2 V_102 ;
T_2 V_103 ;
int V_104 = 0 ;
V_16 -> V_62 = NULL ;
V_102 = V_16 -> V_16 . V_19 ;
V_103 = 0 ;
do {
T_5 V_105 = V_16 -> V_16 . V_106 + V_103 ;
T_2 V_96 = F_4 ( V_102 , V_14 -> V_48 ) ;
V_104 = F_43 ( V_14 , V_16 , V_105 , V_96 , V_86 ) ;
if ( V_104 )
goto V_107;
V_102 -= V_96 ;
V_103 += V_96 ;
} while ( V_102 > 0 );
if ( V_16 -> V_16 . V_109 && ( V_16 -> V_16 . V_19 % V_14 -> V_14 . V_47 == 0 ) ) {
V_104 = F_43 ( V_14 , V_16 , 0 , 0 , V_86 ) ;
if ( V_104 )
goto V_107;
}
V_16 -> V_68 -> V_66 |= V_110 ;
return 0 ;
V_107:
F_31 ( V_14 -> V_23 , V_16 ) ;
return V_104 ;
}
static int F_47 ( struct V_13 * V_14 , struct V_15 * V_16 , T_4 V_86 )
{
struct V_26 * V_23 = V_14 -> V_23 ;
int V_104 ;
if ( F_48 ( ! V_14 -> V_14 . V_60 && V_14 -> V_111 != 0 ) ) {
F_28 ( V_23 -> V_23 , L_48 , V_14 -> V_14 . V_38 ) ;
return - V_112 ;
}
if ( F_48 ( ! V_16 -> V_16 . V_25 || ! F_12 ( & V_16 -> V_58 ) ) ) {
F_28 ( V_23 -> V_23 ,
L_49 ,
V_14 -> V_14 . V_38 , V_16 -> V_16 . V_25 , F_12 ( & V_16 -> V_58 ) ) ;
return - V_112 ;
}
if ( ! V_14 -> V_18 && ( V_16 -> V_16 . V_19 % V_14 -> V_14 . V_47 ) != 0 ) {
F_28 ( V_23 -> V_23 ,
L_50 ,
V_16 -> V_16 . V_19 ) ;
return - V_113 ;
}
if ( F_48 ( ! V_23 -> V_114 || V_23 -> V_73 . V_115 == V_116 ) ) {
F_28 ( V_23 -> V_23 , L_51 ) ;
return - V_117 ;
}
if ( V_23 -> V_76 == V_11 ) {
F_28 ( V_23 -> V_23 , L_52 ) ;
return - V_118 ;
}
V_104 = F_49 ( & V_23 -> V_73 , & V_16 -> V_16 , V_14 -> V_18 ) ;
if ( V_104 ) {
F_28 ( V_23 -> V_23 , L_53 ) ;
return V_104 ;
}
if ( V_14 -> V_18 )
V_104 = F_46 ( V_14 , V_16 , V_86 ) ;
else
V_104 = F_44 ( V_14 , V_16 , V_86 ) ;
if ( V_104 )
return V_104 ;
V_16 -> V_16 . V_72 = - V_119 ;
V_16 -> V_16 . V_20 = 0 ;
F_50 ( & V_16 -> V_58 , & V_14 -> V_58 ) ;
if ( ! V_14 -> V_43 && F_51 ( ! V_14 -> V_44 ) )
F_36 ( V_14 ) ;
return 0 ;
}
static inline int F_52 ( struct V_13 * V_14 , struct V_15 * V_16 ,
T_4 V_86 )
{
if ( V_14 -> V_18 )
F_3 ( L_54 , V_14 , V_16 ) ;
return F_47 ( V_14 , V_16 , V_86 ) ;
}
static void F_53 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_14 -> V_44 = 1 ;
V_14 -> V_43 = 0 ;
F_42 ( V_14 ) ;
while ( ! F_12 ( & V_14 -> V_58 ) ) {
V_16 = F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) ;
F_32 ( V_14 , V_16 , - V_117 ) ;
}
}
static void F_54 ( struct V_13 * V_14 )
{
F_40 ( & V_14 -> V_33 -> V_32 , 0 ) ;
F_40 ( & V_14 -> V_33 -> V_92 , 0 ) ;
V_14 -> V_14 . V_47 = V_120 ;
V_14 -> V_14 . V_60 = NULL ;
V_14 -> V_44 = 1 ;
V_14 -> V_43 = 0 ;
}
static void F_55 ( struct V_26 * V_23 )
{
T_3 V_32 ;
V_32 = F_10 ( & V_23 -> V_121 [ 0 ] . V_33 -> V_32 ) ;
F_40 ( & V_23 -> V_121 [ 0 ] . V_33 -> V_32 , V_32 | V_122 ) ;
V_32 = F_10 ( & V_23 -> V_123 [ 0 ] . V_33 -> V_32 ) ;
F_40 ( & V_23 -> V_123 [ 0 ] . V_33 -> V_32 , V_32 | V_122 ) ;
V_23 -> V_76 = V_10 ;
}
static int F_56 ( struct V_13 * V_14 , int V_124 , int V_125 , int V_126 )
{
T_3 V_32 ;
int V_127 = 0 ;
if ( V_14 -> V_111 && ! V_14 -> V_14 . V_60 )
return - V_112 ;
if ( V_14 -> V_111 && V_14 -> V_14 . V_60 -> V_128 == V_129 )
return - V_130 ;
if ( ! V_14 -> V_111 ) {
if ( V_124 && ! V_126 ) {
F_55 ( V_14 -> V_23 ) ;
F_5 ( V_14 -> V_23 -> V_23 , L_55 ) ;
return 0 ;
}
return - V_112 ;
}
F_5 ( V_14 -> V_23 -> V_23 , L_56 ,
( V_124 ? ( V_125 ? L_57 : L_58 ) : L_59 ) , V_14 -> V_14 . V_38 ) ;
V_32 = F_10 ( & V_14 -> V_33 -> V_32 ) ;
if ( V_124 ) {
F_40 ( & V_14 -> V_33 -> V_32 , V_32 | V_40 ) ;
V_14 -> V_44 = 1 ;
if ( V_125 )
V_14 -> V_45 = 1 ;
} else {
F_40 ( & V_14 -> V_33 -> V_32 , V_32 & ~ V_40 ) ;
V_14 -> V_44 = 0 ;
V_14 -> V_45 = 0 ;
if ( ! V_14 -> V_43 )
F_36 ( V_14 ) ;
}
return V_127 ;
}
static inline void F_57 ( struct V_26 * V_23 , enum V_1 V_28 )
{
if ( V_23 -> V_76 != V_28 )
F_8 ( V_23 -> V_23 , L_60 ,
F_1 ( V_28 ) ) ;
V_23 -> V_76 = V_28 ;
}
static void F_58 ( struct V_26 * V_23 )
{
F_40 ( & V_23 -> V_33 -> V_71 , 0 ) ;
F_39 () ;
V_23 -> V_77 = 0 ;
}
static void F_59 ( struct V_26 * V_23 )
{
struct V_13 * V_14 ;
F_14 (ep, &dev->ep_list, ep_list)
F_53 ( V_14 ) ;
F_58 ( V_23 ) ;
F_57 ( V_23 , V_4 ) ;
F_60 ( & V_23 -> V_73 , V_131 ) ;
}
static void F_61 ( struct V_90 * V_91 ,
struct V_89 * V_132 )
{
struct V_13 * V_14 ;
struct V_26 * V_23 ;
T_3 V_71 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
V_23 = V_14 -> V_23 ;
F_63 ( & V_23 -> V_133 ) ;
V_71 = F_10 ( & V_23 -> V_33 -> V_71 ) ;
V_71 |= V_134 | ( V_23 -> V_79 << V_135 ) ;
F_40 ( & V_23 -> V_33 -> V_71 , V_71 ) ;
F_64 ( & V_23 -> V_133 ) ;
}
static void F_65 ( struct V_90 * V_91 , struct V_89 * V_132 )
{
}
static int F_66 ( struct V_26 * V_23 , T_1 * V_25 , int V_19 ,
void (* F_67)( struct V_90 * V_14 ,
struct V_89 * V_16 ) )
{
T_1 * V_136 = V_23 -> V_137 -> V_16 . V_25 ;
int V_72 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < V_19 ; V_138 ++ )
V_136 [ V_138 ] = V_25 [ V_138 ] ;
V_23 -> V_137 -> V_16 . V_19 = V_19 ;
V_23 -> V_137 -> V_16 . F_67 = F_67 ;
V_72 = F_52 ( & V_23 -> V_123 [ 0 ] , V_23 -> V_137 , V_139 ) ;
if ( V_72 < 0 )
F_28 ( V_23 -> V_23 ,
L_61 , V_72 ) ;
return V_72 ;
}
static inline int F_68 ( struct V_26 * V_23 , T_2 V_140 )
{
T_6 V_141 = F_69 ( V_140 ) ;
return F_66 ( V_23 , ( T_1 * ) & V_141 , 2 ,
F_65 ) ;
}
static inline int F_70 ( struct V_26 * V_23 )
{
return F_66 ( V_23 , NULL , 0 , F_65 ) ;
}
static void F_71 ( struct V_26 * V_23 , T_1 V_142 )
{
T_3 V_71 ;
V_71 = F_10 ( & V_23 -> V_33 -> V_71 ) & ~ V_74 ;
V_71 |= ( V_142 << V_75 ) & V_74 ;
V_71 |= V_143 ;
F_40 ( & V_23 -> V_33 -> V_71 , V_71 ) ;
}
static int F_72 ( struct V_26 * V_23 , T_1 type , T_1 V_27 ,
T_2 V_28 , T_2 V_29 )
{
T_2 V_140 ;
T_1 V_144 ;
switch ( V_27 ) {
case V_145 :
F_5 ( V_23 -> V_23 , L_62 , V_28 & 0xff ) ;
F_71 ( V_23 , V_28 & 0xff ) ;
if ( V_28 )
F_60 ( & V_23 -> V_73 , V_146 ) ;
else
F_60 ( & V_23 -> V_73 , V_147 ) ;
return F_70 ( V_23 ) ;
case V_148 :
V_140 = 0x0001 | ( V_23 -> V_78 ? 0x0002 : 0 ) ;
return F_68 ( V_23 , V_140 ) ;
case V_149 :
switch ( V_28 ) {
case V_150 :
V_23 -> V_78 = 1 ;
return F_70 ( V_23 ) ;
case V_151 :
V_144 = V_29 >> 8 ;
if ( V_144 >= V_152 && V_144 <= V_153 ) {
V_23 -> V_79 = V_144 ;
return F_66 ( V_23 , NULL , 0 ,
F_61 ) ;
}
}
break;
case V_154 :
switch ( V_28 ) {
case V_150 :
V_23 -> V_78 = 0 ;
return F_70 ( V_23 ) ;
}
break;
}
return 1 ;
}
static int F_73 ( struct V_26 * V_23 , T_1 type , T_1 V_27 ,
T_2 V_28 , T_2 V_29 )
{
if ( V_23 -> V_73 . V_2 != V_155 )
return - 1 ;
switch ( V_27 ) {
case V_148 :
return F_68 ( V_23 , 0x0000 ) ;
case V_149 :
case V_154 :
break;
}
return 1 ;
}
static int F_74 ( struct V_26 * V_23 , T_1 type , T_1 V_27 ,
T_2 V_28 , T_2 V_29 )
{
struct V_13 * V_14 ;
int V_72 ;
int V_156 ;
T_1 V_157 = V_29 & V_158 ;
T_1 V_18 = V_29 & V_159 ;
if ( ( V_18 && V_157 >= V_23 -> V_160 ) || ( ! V_18 && V_157 >= V_23 -> V_161 ) )
return - 1 ;
if ( V_23 -> V_73 . V_2 != V_155 && V_157 != 0 )
return - 1 ;
V_14 = ( V_18 ? & V_23 -> V_123 [ V_157 ] : & V_23 -> V_121 [ V_157 ] ) ;
switch ( V_27 ) {
case V_148 :
V_156 = F_10 ( & V_14 -> V_33 -> V_32 ) & V_40 ;
return F_68 ( V_23 , V_156 ? 0x0001 : 0 ) ;
case V_149 :
switch ( V_28 ) {
case V_162 :
V_72 = F_56 ( V_14 , 1 , 0 , 1 ) ;
if ( V_72 >= 0 )
V_72 = F_70 ( V_23 ) ;
return V_72 ;
}
break;
case V_154 :
switch ( V_28 ) {
case V_162 :
if ( V_14 -> V_45 )
return - 1 ;
V_72 = F_56 ( V_14 , 0 , 0 , 1 ) ;
if ( V_72 >= 0 )
V_72 = F_70 ( V_23 ) ;
return V_72 ;
}
break;
}
return 1 ;
}
static void F_75 ( struct V_26 * V_23 )
{
int V_104 = F_52 ( & V_23 -> V_121 [ 0 ] , V_23 -> V_163 , V_139 ) ;
if ( V_104 )
F_28 ( V_23 -> V_23 , L_63 ,
V_104 ) ;
}
static void F_76 ( struct V_26 * V_23 , struct V_15 * V_16 )
__releases( &dev->lock
static void F_77 ( struct V_26 * V_23 , T_3 V_72 )
{
T_3 V_71 ;
V_23 -> V_73 . V_115 = F_78 ( V_72 ) ;
F_60 ( & V_23 -> V_73 , V_164 ) ;
V_71 = ( V_165 | V_166 | V_167 |
V_168 | V_169 ) ;
F_40 ( & V_23 -> V_33 -> V_71 , V_71 ) ;
}
static void F_79 ( struct V_26 * V_23 )
{
T_3 V_72 ;
V_23 -> V_77 = 1 ;
F_39 () ;
F_40 ( & V_23 -> V_33 -> V_71 , V_167 ) ;
V_72 = F_10 ( & V_23 -> V_33 -> V_72 ) ;
if ( V_72 & V_170 )
F_77 ( V_23 , V_72 ) ;
}
static void F_80 ( struct V_26 * V_23 )
{
F_59 ( V_23 ) ;
if ( V_23 -> V_114 && V_23 -> V_114 -> V_171 ) {
F_64 ( & V_23 -> V_133 ) ;
V_23 -> V_114 -> V_171 ( & V_23 -> V_73 ) ;
F_63 ( & V_23 -> V_133 ) ;
}
F_79 ( V_23 ) ;
}
static void F_81 ( struct V_26 * V_23 , T_3 V_72 )
{
F_71 ( V_23 , 0 ) ;
F_57 ( V_23 , V_5 ) ;
F_60 ( & V_23 -> V_73 , V_147 ) ;
V_23 -> V_73 . V_115 = F_78 ( V_72 ) ;
F_53 ( & V_23 -> V_121 [ 0 ] ) ;
F_53 ( & V_23 -> V_123 [ 0 ] ) ;
V_23 -> V_121 [ 0 ] . V_44 = 0 ;
V_23 -> V_123 [ 0 ] . V_44 = 0 ;
F_75 ( V_23 ) ;
}
static int F_82 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) ;
if ( ! V_16 -> V_68 )
return 0 ;
if ( F_83 ( V_16 -> V_68 -> V_66 ) & V_99 )
return 0 ;
if ( F_10 ( & V_14 -> V_33 -> V_34 ) & ( V_55 | V_51 ) )
return 0 ;
F_41 ( V_14 , 0 ) ;
return 1 ;
}
static int F_84 ( struct V_13 * V_14 )
{
T_3 V_172 ;
T_3 V_66 ;
T_2 V_173 ;
struct V_15 * V_16 ;
struct V_26 * V_23 = V_14 -> V_23 ;
V_16 = F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) ;
if ( ! V_16 -> V_64 )
return 0 ;
V_66 = F_83 ( V_16 -> V_64 -> V_66 ) ;
if ( V_66 & V_108 )
return 0 ;
V_173 = V_66 & V_174 ;
V_16 -> V_16 . V_20 += V_173 ;
if ( V_66 & V_175 )
V_16 -> V_176 = 1 ;
if ( V_173 < V_14 -> V_14 . V_47 || V_16 -> V_16 . V_20 == V_16 -> V_16 . V_19 ) {
if ( ( V_14 == & V_23 -> V_121 [ 0 ] ) && ( V_23 -> V_76 == V_9 ) ) {
F_70 ( V_23 ) ;
F_57 ( V_23 , V_5 ) ;
}
F_41 ( V_14 , 0 ) ;
} else {
V_16 -> V_64 = V_16 -> V_64 -> V_63 ;
V_16 -> V_64 -> V_66 |= V_108 ;
V_172 = F_10 ( & V_14 -> V_33 -> V_92 ) ;
F_40 ( & V_14 -> V_33 -> V_92 , V_172 | V_94 ) ;
}
return 1 ;
}
static int F_85 ( struct V_26 * V_23 )
{
T_3 V_72 = F_10 ( & V_23 -> V_33 -> V_72 ) ;
int V_177 = 0 ;
int V_178 = ! ( V_23 -> V_73 . V_2 == V_131 ||
V_23 -> V_73 . V_2 == V_179 ) ;
if ( ! V_178 && ( V_72 & V_170 ) ) {
F_5 ( V_23 -> V_23 , L_64 ) ;
F_77 ( V_23 , V_72 ) ;
V_177 = 1 ;
}
if ( V_178 && ! ( V_72 & V_170 ) ) {
F_5 ( V_23 -> V_23 , L_65 ) ;
F_80 ( V_23 ) ;
V_177 = 1 ;
}
if ( V_72 & V_180 ) {
F_5 ( V_23 -> V_23 , L_66 ,
F_17 ( V_72 ) ) ;
F_40 ( & V_23 -> V_33 -> V_72 , V_180 ) ;
F_81 ( V_23 , V_72 ) ;
V_177 = 1 ;
}
if ( V_23 -> V_73 . V_115 != F_78 ( V_72 ) ) {
F_5 ( V_23 -> V_23 , L_67 ,
F_17 ( V_72 ) ) ;
V_23 -> V_73 . V_115 = F_78 ( V_72 ) ;
V_177 = 1 ;
}
if ( ( V_23 -> V_76 != V_11 ) && ! ( V_72 & V_181 ) ) {
F_5 ( V_23 -> V_23 , L_68 ) ;
F_57 ( V_23 , V_11 ) ;
V_23 -> V_182 = V_23 -> V_73 . V_2 ;
F_60 ( & V_23 -> V_73 , V_183 ) ;
if ( ( V_23 -> V_73 . V_115 != V_116 ) &&
V_23 -> V_114 && V_23 -> V_114 -> V_184 ) {
F_64 ( & V_23 -> V_133 ) ;
V_23 -> V_114 -> V_184 ( & V_23 -> V_73 ) ;
F_63 ( & V_23 -> V_133 ) ;
}
V_177 = 1 ;
}
if ( ( V_23 -> V_76 == V_11 ) && ( V_72 & V_181 ) ) {
F_5 ( V_23 -> V_23 , L_69 ) ;
if ( V_23 -> V_182 == V_164 )
F_57 ( V_23 , V_4 ) ;
else
F_57 ( V_23 , V_5 ) ;
F_60 ( & V_23 -> V_73 , V_23 -> V_182 ) ;
if ( ( V_23 -> V_73 . V_115 != V_116 ) &&
V_23 -> V_114 && V_23 -> V_114 -> V_185 ) {
F_64 ( & V_23 -> V_133 ) ;
V_23 -> V_114 -> V_185 ( & V_23 -> V_73 ) ;
F_63 ( & V_23 -> V_133 ) ;
}
V_177 = 1 ;
}
return V_177 ;
}
static T_7 F_86 ( int V_186 , void * V_187 )
{
struct V_26 * V_23 = V_187 ;
struct V_13 * V_14 ;
int V_177 = 0 ;
int V_138 ;
unsigned long V_188 ;
F_87 ( & V_23 -> V_133 , V_188 ) ;
if ( ! V_23 -> V_77 )
goto V_189;
for ( V_138 = 0 ; V_138 < V_23 -> V_160 ; V_138 ++ ) {
V_14 = & V_23 -> V_123 [ V_138 ] ;
if ( ! V_14 -> V_44 && ! V_14 -> V_46 && ! F_12 ( & V_14 -> V_58 ) )
V_177 = F_82 ( V_14 ) || V_177 ;
}
for ( V_138 = 0 ; V_138 < V_23 -> V_161 ; V_138 ++ ) {
V_14 = & V_23 -> V_121 [ V_138 ] ;
if ( ! V_14 -> V_44 && ! V_14 -> V_46 && ! F_12 ( & V_14 -> V_58 ) )
V_177 = F_84 ( V_14 ) || V_177 ;
}
V_177 = F_85 ( V_23 ) || V_177 ;
if ( ! V_177 ) {
F_14 (ep, &dev->ep_list, ep_list) {
if ( F_10 ( & V_14 -> V_33 -> V_92 ) & V_190 ) {
F_28 ( V_23 -> V_23 ,
L_70 ,
V_14 -> V_14 . V_38 ) ;
V_177 = 1 ;
}
}
}
V_189:
F_88 ( & V_23 -> V_133 , V_188 ) ;
return V_177 ? V_191 : V_192 ;
}
static T_7 F_89 ( int V_186 , void * V_187 )
{
struct V_26 * V_23 = V_187 ;
if ( ! V_23 -> V_77 )
return V_192 ;
return V_193 ;
}
static int F_90 ( struct V_90 * V_91 ,
const struct V_194 * V_60 )
{
struct V_26 * V_23 ;
struct V_13 * V_14 ;
T_1 V_35 ;
T_1 V_195 ;
T_2 V_196 ;
T_2 V_197 = 0 ;
T_3 V_32 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
if ( ! V_91 || ! V_60 || V_60 -> V_198 != V_199 )
return - V_112 ;
V_23 = V_14 -> V_23 ;
if ( V_14 == & V_23 -> V_121 [ 0 ] || V_14 == & V_23 -> V_123 [ 0 ] )
return - V_112 ;
if ( ! V_23 -> V_114 || V_23 -> V_73 . V_115 == V_116 )
return - V_117 ;
V_32 = F_10 ( & V_14 -> V_33 -> V_32 ) ;
if ( V_32 & V_42 )
return - V_118 ;
if ( ! V_14 -> V_18 != ! F_91 ( V_60 ) )
return - V_112 ;
if ( ( ! V_14 -> V_18 && V_14 -> V_111 >= V_23 -> V_161 ) ||
( V_14 -> V_18 && V_14 -> V_111 >= V_23 -> V_160 ) )
return - V_112 ;
if ( F_92 ( V_60 ) ) {
V_35 = 0 ;
} else if ( F_93 ( V_60 ) ) {
V_35 = 1 ;
} else if ( F_94 ( V_60 ) ) {
V_35 = 2 ;
} else if ( F_95 ( V_60 ) ) {
V_35 = 3 ;
} else {
F_28 ( V_23 -> V_23 , L_71 ,
V_14 -> V_14 . V_38 ) ;
return - V_112 ;
}
V_196 = 0x7ff & F_96 ( V_60 ) ;
V_195 = 0x3 & ( F_96 ( V_60 ) >> 11 ) ;
V_197 = F_97 ( V_32 ) ;
if ( V_195 && ( V_35 == 0 || V_35 == 2 ) ) {
F_28 ( V_23 -> V_23 ,
L_72 ,
( V_35 == 2 ? L_73 : L_74 ) ) ;
return - V_112 ;
} else if ( V_195 == 0x11 ) {
F_28 ( V_23 -> V_23 , L_75 ) ;
return - V_112 ;
} else if ( ( V_195 + 1 ) * V_196 > V_197 ) {
F_28 ( V_23 -> V_23 , L_76 ,
V_197 , ( V_195 + 1 ) , V_196 ) ;
return - V_112 ;
} else if ( V_196 == 0 ) {
F_28 ( V_23 -> V_23 , L_77 ) ;
return - V_112 ;
}
F_63 ( & V_14 -> V_23 -> V_133 ) ;
if ( ! V_14 -> V_44 ) {
F_64 ( & V_14 -> V_23 -> V_133 ) ;
return - V_118 ;
}
V_14 -> V_44 = 0 ;
V_14 -> V_45 = 0 ;
V_14 -> V_14 . V_60 = V_60 ;
V_14 -> V_14 . V_47 = V_196 ;
V_14 -> V_43 = 0 ;
if ( V_195 ) {
V_14 -> V_48 = ( V_195 + 1 ) * V_196 ;
} else if ( V_14 -> V_18 ) {
V_14 -> V_48 = ( V_197 / V_196 ) * V_196 ;
} else {
V_14 -> V_48 = V_196 ;
}
V_32 = ( V_196 << V_200 )
| ( V_195 << V_50 )
| ( V_35 << V_37 )
| V_42 ;
if ( V_14 -> V_18 )
V_32 |= V_201 ;
F_40 ( & V_14 -> V_33 -> V_32 , V_32 ) ;
F_40 ( & V_14 -> V_33 -> V_92 , V_202 | V_203 ) ;
F_64 ( & V_14 -> V_23 -> V_133 ) ;
F_5 ( V_14 -> V_23 -> V_23 , L_78 ,
V_14 -> V_14 . V_38 , V_39 [ V_35 ] , V_14 -> V_48 ) ;
return 0 ;
}
static int F_98 ( struct V_90 * V_91 )
{
struct V_13 * V_14 ;
struct V_26 * V_23 ;
unsigned long V_188 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
if ( ! V_91 || ! V_14 -> V_14 . V_60 )
return - V_204 ;
V_23 = V_14 -> V_23 ;
if ( V_14 == & V_23 -> V_121 [ 0 ] || V_14 == & V_23 -> V_123 [ 0 ] )
return - V_112 ;
if ( V_23 -> V_76 == V_11 )
return - V_118 ;
F_5 ( V_14 -> V_23 -> V_23 , L_79 , V_14 -> V_14 . V_38 ) ;
F_87 ( & V_23 -> V_133 , V_188 ) ;
F_53 ( V_14 ) ;
F_54 ( V_14 ) ;
V_14 -> V_14 . V_60 = NULL ;
F_88 ( & V_23 -> V_133 , V_188 ) ;
return 0 ;
}
static void F_99 ( struct V_90 * V_91 , struct V_89 * V_132 )
{
struct V_15 * V_16 ;
if ( ! V_91 || ! V_132 )
return;
V_16 = F_62 ( V_132 , struct V_15 , V_16 ) ;
F_100 ( ! F_12 ( & V_16 -> V_58 ) ,
L_80 ) ;
F_101 ( V_16 ) ;
}
static int F_102 ( struct V_90 * V_91 , struct V_89 * V_132 ,
T_4 V_86 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_26 * V_23 ;
int V_104 ;
if ( F_48 ( ! V_91 || ! V_132 ) )
return - V_112 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
V_16 = F_62 ( V_132 , struct V_15 , V_16 ) ;
V_23 = V_14 -> V_23 ;
F_63 ( & V_14 -> V_23 -> V_133 ) ;
if ( ( V_14 == & V_23 -> V_123 [ 0 ] ) && ( V_23 -> V_76 == V_7 ) ) {
V_14 = & V_23 -> V_121 [ 0 ] ;
V_14 -> V_14 . V_205 = V_23 -> V_123 [ 0 ] . V_14 . V_205 ;
}
if ( V_14 -> V_18 )
F_3 ( L_81 , V_14 , V_16 ) ;
V_104 = F_47 ( V_14 , V_16 , V_86 ) ;
F_64 ( & V_14 -> V_23 -> V_133 ) ;
return V_104 ;
}
static int F_103 ( struct V_90 * V_91 , struct V_89 * V_132 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_26 * V_23 ;
int V_104 = 0 ;
unsigned long V_188 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
if ( ! V_91 || ! V_132 || ( ! V_14 -> V_14 . V_60 && V_14 -> V_111 != 0 ) )
return - V_112 ;
V_23 = V_14 -> V_23 ;
if ( ! V_23 -> V_114 )
return - V_117 ;
if ( V_23 -> V_76 == V_11 )
return - V_118 ;
F_87 ( & V_23 -> V_133 , V_188 ) ;
F_14 (req, &ep->queue, queue) {
if ( & V_16 -> V_16 == V_132 )
break;
}
if ( & V_16 -> V_16 != V_132 ) {
V_104 = - V_112 ;
goto V_189;
}
if ( F_37 ( & V_14 -> V_58 , struct V_15 , V_58 ) == V_16 ) {
F_42 ( V_14 ) ;
if ( V_14 -> V_44 )
F_32 ( V_14 , V_16 , - V_206 ) ;
else
F_41 ( V_14 , - V_206 ) ;
} else if ( ! F_12 ( & V_16 -> V_58 ) ) {
F_32 ( V_14 , V_16 , - V_206 ) ;
} else {
V_104 = - V_130 ;
}
V_189:
F_88 ( & V_23 -> V_133 , V_188 ) ;
return V_104 ;
}
static int F_104 ( struct V_90 * V_91 , int V_124 , int V_125 )
{
int V_104 ;
struct V_13 * V_14 ;
if ( ! V_91 )
return - V_204 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
F_63 ( & V_14 -> V_23 -> V_133 ) ;
if ( V_124 && V_14 -> V_18 && ! F_12 ( & V_14 -> V_58 ) ) {
V_104 = - V_207 ;
goto V_189;
}
V_104 = F_56 ( V_14 , V_124 , V_125 , 0 ) ;
V_189:
F_64 ( & V_14 -> V_23 -> V_133 ) ;
return V_104 ;
}
static int F_105 ( struct V_90 * V_91 , int V_124 )
{
return F_104 ( V_91 , V_124 , 0 ) ;
}
static int F_106 ( struct V_90 * V_91 )
{
return F_104 ( V_91 , 1 , 1 ) ;
}
static int F_107 ( struct V_90 * V_91 )
{
struct V_13 * V_14 ;
T_3 V_34 ;
T_3 V_208 = 0 ;
if ( ! V_91 )
return - V_204 ;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
V_34 = F_10 ( & V_14 -> V_33 -> V_34 ) ;
if ( V_34 & V_51 )
V_208 += ( V_34 & V_53 ) >> V_54 ;
if ( V_34 & V_55 )
V_208 += ( V_34 & V_56 ) >> V_57 ;
return V_208 ;
}
static void F_108 ( struct V_90 * V_91 )
{
struct V_13 * V_14 ;
T_3 V_32 ;
if ( ! V_91 )
return;
V_14 = F_62 ( V_91 , struct V_13 , V_14 ) ;
F_8 ( V_14 -> V_23 -> V_23 , L_82 , V_14 -> V_14 . V_38 ) ;
F_63 ( & V_14 -> V_23 -> V_133 ) ;
V_32 = F_10 ( & V_14 -> V_33 -> V_32 ) ;
V_32 |= V_209 ;
F_40 ( & V_14 -> V_33 -> V_32 , V_32 ) ;
F_64 ( & V_14 -> V_23 -> V_133 ) ;
}
static int F_109 ( struct V_210 * V_211 )
{
struct V_26 * V_23 ;
if ( ! V_211 )
return - V_204 ;
V_23 = F_62 ( V_211 , struct V_26 , V_73 ) ;
return F_10 ( & V_23 -> V_33 -> V_72 ) & V_212 ;
}
static int F_110 ( struct V_210 * V_211 )
{
struct V_26 * V_23 ;
if ( ! V_211 )
return - V_204 ;
V_23 = F_62 ( V_211 , struct V_26 , V_73 ) ;
if ( ! V_23 -> V_78 )
return - V_112 ;
F_63 ( & V_23 -> V_133 ) ;
F_40 ( & V_23 -> V_33 -> V_71 ,
F_10 ( & V_23 -> V_33 -> V_71 ) | V_213 ) ;
F_64 ( & V_23 -> V_133 ) ;
return 0 ;
}
static int F_111 ( struct V_210 * V_211 , int V_214 )
{
struct V_26 * V_23 ;
T_3 V_71 ;
if ( ! V_211 )
return - V_204 ;
V_23 = F_62 ( V_211 , struct V_26 , V_73 ) ;
F_63 ( & V_23 -> V_133 ) ;
V_71 = F_10 ( & V_23 -> V_33 -> V_71 ) ;
if ( V_214 )
V_71 |= V_169 ;
else
V_71 &= ~ V_169 ;
F_40 ( & V_23 -> V_33 -> V_71 , V_71 ) ;
F_64 ( & V_23 -> V_133 ) ;
return 0 ;
}
static int F_112 ( struct V_210 * V_73 ,
struct V_215 * V_114 )
{
struct V_26 * V_23 = F_113 ( V_73 ) ;
F_63 ( & V_23 -> V_133 ) ;
V_114 -> V_114 . V_216 = NULL ;
V_23 -> V_114 = V_114 ;
F_79 ( V_23 ) ;
F_64 ( & V_23 -> V_133 ) ;
F_114 ( V_23 -> V_23 , L_83 ,
V_114 -> V_114 . V_38 ) ;
return 0 ;
}
static int F_115 ( struct V_210 * V_73 ,
struct V_215 * V_114 )
{
struct V_26 * V_23 = F_113 ( V_73 ) ;
unsigned long V_188 ;
F_87 ( & V_23 -> V_133 , V_188 ) ;
V_23 -> V_114 = NULL ;
F_59 ( V_23 ) ;
F_88 ( & V_23 -> V_133 , V_188 ) ;
F_114 ( V_23 -> V_23 , L_84 ) ;
return 0 ;
}
static int F_116 ( struct V_26 * V_23 , int V_111 , int V_18 , T_3 V_217 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_89 * V_132 ;
void * V_25 ;
if ( V_18 ) {
V_14 = & V_23 -> V_123 [ V_111 ] ;
V_14 -> V_14 . V_38 = V_218 [ V_111 ] ;
V_14 -> V_33 = & V_23 -> V_33 -> V_123 [ V_111 ] ;
} else {
V_14 = & V_23 -> V_121 [ V_111 ] ;
V_14 -> V_14 . V_38 = V_219 [ V_111 ] ;
V_14 -> V_33 = & V_23 -> V_33 -> V_121 [ V_111 ] ;
}
F_54 ( V_14 ) ;
V_14 -> V_111 = V_111 ;
V_14 -> V_18 = V_18 ;
V_14 -> V_23 = V_23 ;
V_14 -> V_14 . V_220 = & V_221 ;
F_35 ( & V_14 -> V_58 ) ;
if ( V_111 == 0 ) {
V_132 = F_33 ( & V_14 -> V_14 , V_222 ) ;
V_25 = F_117 ( V_23 -> V_23 , V_223 , V_224 | V_222 ) ;
if ( ! V_132 || ! V_25 ) {
return - V_97 ;
}
V_16 = F_62 ( V_132 , struct V_15 , V_16 ) ;
V_16 -> V_16 . V_25 = V_25 ;
V_16 -> V_16 . V_19 = V_120 ;
if ( V_18 )
V_23 -> V_137 = V_16 ;
else
V_23 -> V_163 = V_16 ;
F_118 ( & V_14 -> V_14 , V_120 ) ;
V_14 -> V_48 = V_120 ;
} else {
F_118 ( & V_14 -> V_14 , ( T_2 ) V_217 ) ;
F_50 ( & V_14 -> V_14 . V_225 , & V_23 -> V_73 . V_225 ) ;
}
F_50 ( & V_14 -> V_225 , & V_23 -> V_225 ) ;
return 0 ;
}
static int F_119 ( struct V_26 * V_23 )
{
struct V_226 * V_227 = V_23 -> V_23 -> V_228 ;
T_3 V_229 ;
T_3 V_230 ;
int V_138 ;
int V_104 = 0 ;
T_3 * V_231 ;
T_3 V_232 ;
int V_173 ;
F_71 ( V_23 , 0 ) ;
F_35 ( & V_23 -> V_73 . V_225 ) ;
V_23 -> V_73 . V_115 = V_116 ;
V_23 -> V_73 . V_233 = & V_23 -> V_123 [ 0 ] . V_14 ;
F_35 ( & V_23 -> V_225 ) ;
F_57 ( V_23 , V_4 ) ;
V_231 = ( T_3 * ) F_120 ( V_227 , L_85 , & V_173 ) ;
V_173 /= sizeof( T_3 ) ;
for ( V_138 = 0 ; V_138 < V_23 -> V_161 ; V_138 ++ ) {
V_232 = ( V_231 && V_138 < V_173 ) ? V_231 [ V_138 ] : 1024 ;
V_104 = F_116 ( V_23 , V_138 , 0 , V_232 ) ;
if ( V_104 )
return V_104 ;
}
V_231 = ( T_3 * ) F_120 ( V_227 , L_86 , & V_173 ) ;
V_173 /= sizeof( T_3 ) ;
for ( V_138 = 0 ; V_138 < V_23 -> V_160 ; V_138 ++ ) {
V_232 = ( V_231 && V_138 < V_173 ) ? V_231 [ V_138 ] : 1024 ;
V_104 = F_116 ( V_23 , V_138 , 1 , V_232 ) ;
if ( V_104 )
return V_104 ;
}
V_23 -> V_78 = 0 ;
V_229 = ( V_120 << V_200 ) | V_42 ;
V_230 = V_202 | V_203 ;
F_40 ( & V_23 -> V_121 [ 0 ] . V_33 -> V_32 , V_229 ) ;
F_40 ( & V_23 -> V_123 [ 0 ] . V_33 -> V_32 , V_229 | V_201 ) ;
F_40 ( & V_23 -> V_121 [ 0 ] . V_33 -> V_92 , V_230 ) ;
F_40 ( & V_23 -> V_123 [ 0 ] . V_33 -> V_92 , V_230 ) ;
return 0 ;
}
static int F_121 ( struct V_234 * V_235 )
{
struct V_26 * V_23 = F_122 ( & V_235 -> V_23 ) ;
if ( V_23 -> V_236 )
F_123 ( & V_23 -> V_73 ) ;
if ( V_23 -> V_114 )
return - V_118 ;
F_24 ( V_23 ) ;
if ( V_23 -> V_88 )
F_124 ( V_23 -> V_88 ) ;
F_125 ( & V_235 -> V_23 , NULL ) ;
F_99 ( & V_23 -> V_123 [ 0 ] . V_14 , & V_23 -> V_137 -> V_16 ) ;
F_99 ( & V_23 -> V_121 [ 0 ] . V_14 , & V_23 -> V_163 -> V_16 ) ;
return 0 ;
}
static int F_126 ( struct V_26 * V_23 , int V_186 )
{
return F_127 ( V_23 -> V_23 , V_186 , F_89 , F_86 ,
V_237 , V_238 , V_23 ) ;
}
static int F_128 ( struct V_234 * V_235 )
{
struct V_26 * V_23 ;
struct V_239 * V_240 ;
struct V_241 T_8 * V_33 ;
int V_127 ;
T_3 V_72 ;
V_23 = F_117 ( & V_235 -> V_23 , sizeof( * V_23 ) , V_222 ) ;
if ( ! V_23 )
return - V_97 ;
V_23 -> V_23 = & V_235 -> V_23 ;
V_240 = F_129 ( V_235 , V_242 , 0 ) ;
V_33 = F_130 ( V_23 -> V_23 , V_240 ) ;
if ( F_131 ( V_33 ) )
return F_132 ( V_33 ) ;
V_23 -> V_186 = F_133 ( V_23 -> V_23 -> V_228 , 0 ) ;
if ( ! V_23 -> V_186 ) {
F_28 ( V_23 -> V_23 , L_87 ) ;
return - V_204 ;
}
V_23 -> V_243 = F_133 ( V_23 -> V_23 -> V_228 , 1 ) ;
if ( V_23 -> V_243 ) {
V_23 -> V_244 = F_133 ( V_23 -> V_23 -> V_228 , 2 ) ;
if ( ! V_23 -> V_244 ) {
F_28 ( V_23 -> V_23 , L_88 ) ;
return - V_204 ;
}
}
V_23 -> V_73 . V_38 = V_238 ;
V_23 -> V_73 . V_245 = V_246 ;
V_23 -> V_73 . V_220 = & V_247 ;
V_23 -> V_73 . V_248 = true ;
F_134 ( & V_23 -> V_133 ) ;
V_23 -> V_33 = V_33 ;
F_125 ( & V_235 -> V_23 , V_23 ) ;
V_72 = F_10 ( & V_23 -> V_33 -> V_72 ) ;
V_23 -> V_160 = ( ( V_72 & V_249 ) >> V_250 ) + 1 ;
V_23 -> V_161 = ( ( V_72 & V_251 ) >> V_252 ) + 1 ;
if ( ! ( V_72 & V_253 ) ) {
F_28 ( V_23 -> V_23 , L_89 ) ;
return - V_204 ;
}
V_23 -> V_88 = F_135 ( L_90 , V_23 -> V_23 ,
sizeof( struct V_59 ) , 4 , 0 ) ;
if ( ! V_23 -> V_88 ) {
F_28 ( V_23 -> V_23 , L_91 ) ;
return - V_97 ;
}
F_63 ( & V_23 -> V_133 ) ;
V_127 = F_136 ( V_23 -> V_23 , & V_23 -> V_73 ) ;
if ( V_127 ) {
F_28 ( V_23 -> V_23 , L_92 ) ;
goto V_189;
}
V_23 -> V_236 = 1 ;
V_127 = F_119 ( V_23 ) ;
if ( V_127 )
goto V_189;
F_20 ( V_23 ) ;
F_58 ( V_23 ) ;
V_127 = F_126 ( V_23 , V_23 -> V_186 ) ;
if ( V_127 ) {
F_28 ( V_23 -> V_23 , L_93 , V_23 -> V_186 ) ;
goto V_189;
}
if ( V_23 -> V_243 ) {
V_127 = F_126 ( V_23 , V_23 -> V_243 ) ;
if ( V_127 ) {
F_28 ( V_23 -> V_23 , L_94 ,
V_23 -> V_243 ) ;
goto V_189;
}
V_127 = F_126 ( V_23 , V_23 -> V_244 ) ;
if ( V_127 ) {
F_28 ( V_23 -> V_23 , L_95 ,
V_23 -> V_244 ) ;
goto V_189;
}
}
if ( V_23 -> V_243 )
F_114 ( V_23 -> V_23 , L_96 , V_23 -> V_33 ,
V_23 -> V_186 , V_23 -> V_243 , V_23 -> V_244 ) ;
else
F_114 ( V_23 -> V_23 , L_97 , V_23 -> V_33 , V_23 -> V_186 ) ;
V_189:
F_64 ( & V_23 -> V_133 ) ;
if ( V_127 )
F_121 ( V_235 ) ;
return V_127 ;
}
