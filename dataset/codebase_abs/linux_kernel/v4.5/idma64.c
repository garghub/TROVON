static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_1 ;
}
static void F_2 ( struct V_5 * V_5 )
{
unsigned short V_6 = 100 ;
F_3 ( V_5 , V_7 , 0 ) ;
F_4 ( V_5 , F_5 ( V_8 ) , V_5 -> V_9 ) ;
F_4 ( V_5 , F_5 ( V_10 ) , V_5 -> V_9 ) ;
F_4 ( V_5 , F_5 ( V_11 ) , V_5 -> V_9 ) ;
F_4 ( V_5 , F_5 ( V_12 ) , V_5 -> V_9 ) ;
F_4 ( V_5 , F_5 ( ERROR ) , V_5 -> V_9 ) ;
do {
F_6 () ;
} while ( F_7 ( V_5 , V_7 ) & V_13 && -- V_6 );
}
static void F_8 ( struct V_5 * V_5 )
{
F_3 ( V_5 , V_7 , V_13 ) ;
}
static void F_9 ( struct V_5 * V_5 , struct V_14 * V_15 )
{
T_1 V_16 = F_10 ( 1 ) | F_11 ( 0 ) ;
T_1 V_17 = 0 ;
V_17 |= V_18 | V_19 ;
F_12 ( V_15 , V_20 , V_17 ) ;
F_12 ( V_15 , V_21 , V_16 ) ;
F_13 ( V_5 , F_5 ( V_8 ) , V_15 -> V_22 ) ;
F_13 ( V_5 , F_5 ( ERROR ) , V_15 -> V_22 ) ;
F_8 ( V_5 ) ;
}
static void F_14 ( struct V_5 * V_5 , struct V_14 * V_15 )
{
F_4 ( V_5 , V_23 , V_15 -> V_22 ) ;
}
static void F_15 ( struct V_5 * V_5 , struct V_14 * V_15 )
{
struct V_24 * V_25 = V_15 -> V_25 ;
struct V_26 * V_27 = & V_25 -> V_27 [ 0 ] ;
F_16 ( V_15 , V_28 , 0 ) ;
F_16 ( V_15 , V_29 , 0 ) ;
F_12 ( V_15 , V_30 , F_17 ( ~ 0UL ) ) ;
F_12 ( V_15 , V_31 , V_32 | V_33 ) ;
F_16 ( V_15 , V_34 , V_27 -> V_35 ) ;
F_13 ( V_5 , V_23 , V_15 -> V_22 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_5 * V_5 = F_19 ( V_15 -> V_36 . V_3 . V_1 ) ;
F_14 ( V_5 , V_15 ) ;
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_5 * V_5 = F_19 ( V_15 -> V_36 . V_3 . V_1 ) ;
struct V_37 * V_38 ;
V_38 = F_21 ( & V_15 -> V_36 ) ;
if ( ! V_38 ) {
V_15 -> V_25 = NULL ;
return;
}
F_22 ( & V_38 -> V_39 ) ;
V_15 -> V_25 = F_23 ( V_38 ) ;
F_9 ( V_5 , V_15 ) ;
F_15 ( V_5 , V_15 ) ;
}
static void F_24 ( struct V_5 * V_5 , unsigned short V_40 ,
T_1 V_41 , T_1 V_42 )
{
struct V_14 * V_15 = & V_5 -> V_3 [ V_40 ] ;
struct V_24 * V_25 ;
unsigned long V_43 ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
V_25 = V_15 -> V_25 ;
if ( V_25 ) {
if ( V_41 & ( 1 << V_40 ) ) {
F_3 ( V_5 , F_26 ( ERROR ) , V_15 -> V_22 ) ;
V_25 -> V_45 = V_46 ;
} else if ( V_42 & ( 1 << V_40 ) ) {
F_3 ( V_5 , F_26 ( V_8 ) , V_15 -> V_22 ) ;
V_25 -> V_45 = V_47 ;
F_27 ( & V_25 -> V_38 ) ;
F_20 ( V_15 ) ;
}
if ( V_15 -> V_25 == NULL || V_25 -> V_45 == V_46 )
F_18 ( V_15 ) ;
}
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
}
static T_2 F_29 ( int V_48 , void * V_4 )
{
struct V_5 * V_5 = V_4 ;
T_1 V_45 = F_7 ( V_5 , V_49 ) ;
T_1 V_42 ;
T_1 V_41 ;
unsigned short V_50 ;
F_30 ( V_5 -> V_51 . V_4 , L_1 , V_52 , V_45 ) ;
if ( ! V_45 )
return V_53 ;
V_42 = F_7 ( V_5 , F_31 ( V_8 ) ) ;
V_41 = F_7 ( V_5 , F_31 ( ERROR ) ) ;
for ( V_50 = 0 ; V_50 < V_5 -> V_51 . V_54 ; V_50 ++ )
F_24 ( V_5 , V_50 , V_41 , V_42 ) ;
return V_55 ;
}
static struct V_24 * F_32 ( unsigned int V_56 )
{
struct V_24 * V_25 ;
V_25 = F_33 ( sizeof( * V_25 ) , V_57 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_27 = F_34 ( V_56 , sizeof( * V_25 -> V_27 ) , V_57 ) ;
if ( ! V_25 -> V_27 ) {
F_35 ( V_25 ) ;
return NULL ;
}
return V_25 ;
}
static void F_36 ( struct V_14 * V_15 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( V_25 -> V_56 ) {
unsigned int V_50 = V_25 -> V_56 ;
do {
V_27 = & V_25 -> V_27 [ -- V_50 ] ;
F_37 ( V_15 -> V_58 , V_27 -> V_59 , V_27 -> V_35 ) ;
} while ( V_50 );
}
F_35 ( V_25 -> V_27 ) ;
F_35 ( V_25 ) ;
}
static void F_38 ( struct V_37 * V_38 )
{
struct V_14 * V_15 = F_39 ( V_38 -> V_60 . V_3 ) ;
F_36 ( V_15 , F_23 ( V_38 ) ) ;
}
static void F_40 ( struct V_26 * V_27 ,
struct V_61 * V_62 ,
enum V_63 V_64 , T_3 V_35 )
{
struct V_65 * V_59 = V_27 -> V_59 ;
T_3 V_66 , V_67 ;
T_1 V_68 = F_17 ( V_27 -> V_69 ) ;
T_1 V_70 = V_32 | V_33 ;
T_1 V_71 , V_72 ;
if ( V_64 == V_73 ) {
V_66 = V_27 -> V_74 ;
V_67 = V_62 -> V_75 ;
V_70 |= V_76 | V_77 |
V_78 ;
V_71 = F_41 ( V_66 | V_27 -> V_69 | 4 ) ;
V_72 = F_41 ( V_62 -> V_79 ) ;
} else {
V_66 = V_62 -> V_80 ;
V_67 = V_27 -> V_74 ;
V_70 |= V_81 | V_82 |
V_83 ;
V_71 = F_41 ( V_62 -> V_84 ) ;
V_72 = F_41 ( V_67 | V_27 -> V_69 | 4 ) ;
}
V_59 -> V_66 = V_66 ;
V_59 -> V_67 = V_67 ;
V_59 -> V_68 = V_68 ;
V_59 -> V_70 = V_70 |
F_42 ( V_62 -> V_85 ) |
F_43 ( V_62 -> V_86 ) |
F_44 ( V_72 ) |
F_45 ( V_71 ) ;
V_59 -> V_35 = V_35 ;
}
static void F_46 ( struct V_14 * V_15 ,
struct V_24 * V_25 )
{
struct V_61 * V_62 = & V_15 -> V_62 ;
unsigned int V_50 = V_25 -> V_56 ;
struct V_26 * V_27 = & V_25 -> V_27 [ V_50 - 1 ] ;
struct V_65 * V_59 = V_27 -> V_59 ;
T_3 V_35 = 0 ;
do {
V_27 = & V_25 -> V_27 [ -- V_50 ] ;
F_40 ( V_27 , V_62 , V_25 -> V_64 , V_35 ) ;
V_35 = V_27 -> V_35 ;
V_25 -> V_87 += V_27 -> V_69 ;
} while ( V_50 );
V_59 -> V_70 |= V_88 ;
}
static struct V_89 * F_47 (
struct V_2 * V_3 , struct V_90 * V_91 ,
unsigned int V_92 , enum V_63 V_64 ,
unsigned long V_43 , void * V_93 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
struct V_24 * V_25 ;
struct V_90 * V_94 ;
unsigned int V_50 ;
V_25 = F_32 ( V_92 ) ;
if ( ! V_25 )
return NULL ;
F_48 (sgl, sg, sg_len, i) {
struct V_26 * V_27 = & V_25 -> V_27 [ V_50 ] ;
V_27 -> V_59 = F_49 ( V_15 -> V_58 , V_57 , & V_27 -> V_35 ) ;
if ( ! V_27 -> V_59 ) {
V_25 -> V_56 = V_50 ;
F_36 ( V_15 , V_25 ) ;
return NULL ;
}
V_27 -> V_74 = F_50 ( V_94 ) ;
V_27 -> V_69 = F_51 ( V_94 ) ;
}
V_25 -> V_56 = V_92 ;
V_25 -> V_64 = V_64 ;
V_25 -> V_45 = V_95 ;
F_46 ( V_15 , V_25 ) ;
return F_52 ( & V_15 -> V_36 , & V_25 -> V_38 , V_43 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_43 ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
if ( F_54 ( & V_15 -> V_36 ) && ! V_15 -> V_25 )
F_20 ( V_15 ) ;
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
}
static T_4 F_55 ( struct V_14 * V_15 )
{
struct V_24 * V_25 = V_15 -> V_25 ;
struct V_26 * V_27 ;
T_4 V_96 = V_25 -> V_87 ;
T_3 V_35 = F_56 ( V_15 , V_34 ) ;
T_1 V_68 = F_57 ( V_15 , V_30 ) ;
unsigned int V_50 = 0 ;
do {
V_27 = & V_25 -> V_27 [ V_50 ] ;
if ( V_27 -> V_35 == V_35 )
break;
V_96 -= V_27 -> V_69 ;
} while ( ++ V_50 < V_25 -> V_56 );
if ( ! V_50 )
return V_96 ;
V_96 += V_25 -> V_27 [ -- V_50 ] . V_69 ;
return V_96 - F_17 ( V_68 ) ;
}
static enum V_97 F_58 ( struct V_2 * V_3 ,
T_5 V_98 , struct V_99 * V_100 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
struct V_37 * V_38 ;
enum V_97 V_45 ;
T_4 V_96 ;
unsigned long V_43 ;
V_45 = F_59 ( V_3 , V_98 , V_100 ) ;
if ( V_45 == V_47 )
return V_45 ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
V_38 = F_60 ( & V_15 -> V_36 , V_98 ) ;
if ( V_15 -> V_25 && V_98 == V_15 -> V_25 -> V_38 . V_60 . V_98 ) {
V_96 = F_55 ( V_15 ) ;
F_61 ( V_100 , V_96 ) ;
V_45 = V_15 -> V_25 -> V_45 ;
} else if ( V_38 ) {
V_96 = F_23 ( V_38 ) -> V_87 ;
F_61 ( V_100 , V_96 ) ;
}
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
return V_45 ;
}
static void F_62 ( T_1 * V_101 )
{
if ( * V_101 )
* V_101 = F_63 ( * V_101 ) ;
else
* V_101 = 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
if ( ! F_65 ( V_62 -> V_64 ) )
return - V_102 ;
memcpy ( & V_15 -> V_62 , V_62 , sizeof( V_15 -> V_62 ) ) ;
F_62 ( & V_15 -> V_62 . V_85 ) ;
F_62 ( & V_15 -> V_62 . V_86 ) ;
return 0 ;
}
static void F_66 ( struct V_14 * V_15 , bool V_103 )
{
unsigned short V_6 = 100 ;
T_1 V_17 ;
V_17 = F_57 ( V_15 , V_20 ) ;
if ( V_103 )
V_17 |= V_104 ;
else
V_17 &= ~ V_104 ;
F_12 ( V_15 , V_20 , V_17 | V_105 ) ;
do {
F_67 ( 1 ) ;
V_17 = F_57 ( V_15 , V_20 ) ;
} while ( ! ( V_17 & V_106 ) && -- V_6 );
}
static void F_68 ( struct V_14 * V_15 )
{
T_1 V_17 ;
V_17 = F_57 ( V_15 , V_20 ) ;
F_12 ( V_15 , V_20 , V_17 & ~ V_105 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_43 ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
if ( V_15 -> V_25 && V_15 -> V_25 -> V_45 == V_95 ) {
F_66 ( V_15 , false ) ;
V_15 -> V_25 -> V_45 = V_107 ;
}
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_43 ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
if ( V_15 -> V_25 && V_15 -> V_25 -> V_45 == V_107 ) {
V_15 -> V_25 -> V_45 = V_95 ;
F_68 ( V_15 ) ;
}
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_43 ;
F_72 ( V_108 ) ;
F_25 ( & V_15 -> V_36 . V_44 , V_43 ) ;
F_66 ( V_15 , true ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_25 ) {
F_38 ( & V_15 -> V_25 -> V_38 ) ;
V_15 -> V_25 = NULL ;
}
F_73 ( & V_15 -> V_36 , & V_108 ) ;
F_28 ( & V_15 -> V_36 . V_44 , V_43 ) ;
F_74 ( & V_15 -> V_36 , & V_108 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
V_15 -> V_58 = F_76 ( F_77 ( F_1 ( V_3 ) ) ,
V_3 -> V_1 -> V_4 ,
sizeof( struct V_65 ) , 8 , 0 ) ;
if ( ! V_15 -> V_58 ) {
F_78 ( F_1 ( V_3 ) , L_2 ) ;
return - V_109 ;
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
F_80 ( F_81 ( V_3 ) ) ;
F_82 ( V_15 -> V_58 ) ;
V_15 -> V_58 = NULL ;
}
static int F_83 ( struct V_110 * V_111 )
{
struct V_5 * V_5 ;
unsigned short V_112 = V_113 ;
unsigned short V_50 ;
int V_114 ;
V_5 = F_84 ( V_111 -> V_4 , sizeof( * V_5 ) , V_115 ) ;
if ( ! V_5 )
return - V_109 ;
V_5 -> V_116 = V_111 -> V_116 ;
V_111 -> V_5 = V_5 ;
V_5 -> V_3 = F_85 ( V_111 -> V_4 , V_112 , sizeof( * V_5 -> V_3 ) ,
V_115 ) ;
if ( ! V_5 -> V_3 )
return - V_109 ;
V_5 -> V_9 = ( 1 << V_112 ) - 1 ;
F_2 ( V_5 ) ;
V_114 = F_86 ( V_111 -> V_4 , V_111 -> V_48 , F_29 , V_117 ,
F_77 ( V_111 -> V_4 ) , V_5 ) ;
if ( V_114 )
return V_114 ;
F_87 ( & V_5 -> V_51 . V_118 ) ;
for ( V_50 = 0 ; V_50 < V_112 ; V_50 ++ ) {
struct V_14 * V_15 = & V_5 -> V_3 [ V_50 ] ;
V_15 -> V_36 . V_119 = F_38 ;
F_88 ( & V_15 -> V_36 , & V_5 -> V_51 ) ;
V_15 -> V_116 = V_5 -> V_116 + V_50 * V_120 ;
V_15 -> V_22 = F_89 ( V_50 ) ;
}
F_90 ( V_121 , V_5 -> V_51 . V_122 ) ;
F_90 ( V_123 , V_5 -> V_51 . V_122 ) ;
V_5 -> V_51 . V_124 = F_75 ;
V_5 -> V_51 . V_125 = F_79 ;
V_5 -> V_51 . V_126 = F_47 ;
V_5 -> V_51 . V_127 = F_53 ;
V_5 -> V_51 . V_128 = F_58 ;
V_5 -> V_51 . V_129 = F_64 ;
V_5 -> V_51 . V_130 = F_69 ;
V_5 -> V_51 . V_131 = F_70 ;
V_5 -> V_51 . V_132 = F_71 ;
V_5 -> V_51 . V_133 = V_134 ;
V_5 -> V_51 . V_135 = V_134 ;
V_5 -> V_51 . V_136 = F_89 ( V_137 ) | F_89 ( V_73 ) ;
V_5 -> V_51 . V_138 = V_139 ;
V_5 -> V_51 . V_4 = V_111 -> V_4 ;
F_91 ( V_5 -> V_51 . V_4 , V_140 ) ;
V_114 = F_92 ( & V_5 -> V_51 ) ;
if ( V_114 )
return V_114 ;
F_93 ( V_111 -> V_4 , L_3 ) ;
return 0 ;
}
static int F_94 ( struct V_110 * V_111 )
{
struct V_5 * V_5 = V_111 -> V_5 ;
unsigned short V_50 ;
F_95 ( & V_5 -> V_51 ) ;
F_96 ( V_111 -> V_4 , V_111 -> V_48 , V_5 ) ;
for ( V_50 = 0 ; V_50 < V_5 -> V_51 . V_54 ; V_50 ++ ) {
struct V_14 * V_15 = & V_5 -> V_3 [ V_50 ] ;
F_97 ( & V_15 -> V_36 . V_141 ) ;
}
return 0 ;
}
static int F_98 ( struct V_142 * V_143 )
{
struct V_110 * V_111 ;
struct V_1 * V_4 = & V_143 -> V_4 ;
struct V_144 * V_145 ;
int V_114 ;
V_111 = F_84 ( V_4 , sizeof( * V_111 ) , V_115 ) ;
if ( ! V_111 )
return - V_109 ;
V_111 -> V_48 = F_99 ( V_143 , 0 ) ;
if ( V_111 -> V_48 < 0 )
return V_111 -> V_48 ;
V_145 = F_100 ( V_143 , V_146 , 0 ) ;
V_111 -> V_116 = F_101 ( V_4 , V_145 ) ;
if ( F_102 ( V_111 -> V_116 ) )
return F_103 ( V_111 -> V_116 ) ;
V_114 = F_104 ( & V_143 -> V_4 , F_105 ( 64 ) ) ;
if ( V_114 )
return V_114 ;
V_111 -> V_4 = V_4 ;
V_114 = F_83 ( V_111 ) ;
if ( V_114 )
return V_114 ;
F_106 ( V_143 , V_111 ) ;
return 0 ;
}
static int F_107 ( struct V_142 * V_143 )
{
struct V_110 * V_111 = F_108 ( V_143 ) ;
return F_94 ( V_111 ) ;
}
static int F_109 ( struct V_1 * V_4 )
{
struct V_142 * V_143 = F_110 ( V_4 ) ;
struct V_110 * V_111 = F_108 ( V_143 ) ;
F_2 ( V_111 -> V_5 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_4 )
{
struct V_142 * V_143 = F_110 ( V_4 ) ;
struct V_110 * V_111 = F_108 ( V_143 ) ;
F_8 ( V_111 -> V_5 ) ;
return 0 ;
}
