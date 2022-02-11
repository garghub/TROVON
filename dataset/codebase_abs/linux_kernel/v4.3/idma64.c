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
V_17 |= V_18 ;
V_17 |= V_19 | V_20 ;
F_12 ( V_15 , V_21 , V_17 ) ;
F_12 ( V_15 , V_22 , V_16 ) ;
F_13 ( V_5 , F_5 ( V_8 ) , V_15 -> V_23 ) ;
F_13 ( V_5 , F_5 ( ERROR ) , V_15 -> V_23 ) ;
F_8 ( V_5 ) ;
}
static void F_14 ( struct V_5 * V_5 , struct V_14 * V_15 )
{
F_4 ( V_5 , V_24 , V_15 -> V_23 ) ;
}
static void F_15 ( struct V_5 * V_5 , struct V_14 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 [ 0 ] ;
F_16 ( V_15 , V_29 , 0 ) ;
F_16 ( V_15 , V_30 , 0 ) ;
F_12 ( V_15 , V_31 , F_17 ( ~ 0UL ) ) ;
F_12 ( V_15 , V_32 , V_33 | V_34 ) ;
F_16 ( V_15 , V_35 , V_28 -> V_36 ) ;
F_13 ( V_5 , V_24 , V_15 -> V_23 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_5 * V_5 = F_19 ( V_15 -> V_37 . V_3 . V_1 ) ;
F_14 ( V_5 , V_15 ) ;
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_5 * V_5 = F_19 ( V_15 -> V_37 . V_3 . V_1 ) ;
struct V_38 * V_39 ;
V_39 = F_21 ( & V_15 -> V_37 ) ;
if ( ! V_39 ) {
V_15 -> V_26 = NULL ;
return;
}
F_22 ( & V_39 -> V_40 ) ;
V_15 -> V_26 = F_23 ( V_39 ) ;
F_9 ( V_5 , V_15 ) ;
F_15 ( V_5 , V_15 ) ;
}
static void F_24 ( struct V_5 * V_5 , unsigned short V_41 ,
T_1 V_42 , T_1 V_43 )
{
struct V_14 * V_15 = & V_5 -> V_3 [ V_41 ] ;
struct V_25 * V_26 ;
unsigned long V_44 ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
V_26 = V_15 -> V_26 ;
if ( V_26 ) {
if ( V_42 & ( 1 << V_41 ) ) {
F_3 ( V_5 , F_26 ( ERROR ) , V_15 -> V_23 ) ;
V_26 -> V_46 = V_47 ;
} else if ( V_43 & ( 1 << V_41 ) ) {
F_3 ( V_5 , F_26 ( V_8 ) , V_15 -> V_23 ) ;
V_26 -> V_46 = V_48 ;
F_27 ( & V_26 -> V_39 ) ;
F_20 ( V_15 ) ;
}
if ( V_15 -> V_26 == NULL || V_26 -> V_46 == V_47 )
F_18 ( V_15 ) ;
}
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
}
static T_2 F_29 ( int V_49 , void * V_4 )
{
struct V_5 * V_5 = V_4 ;
T_1 V_46 = F_7 ( V_5 , V_50 ) ;
T_1 V_43 ;
T_1 V_42 ;
unsigned short V_51 ;
F_30 ( V_5 -> V_52 . V_4 , L_1 , V_53 , V_46 ) ;
if ( ! V_46 )
return V_54 ;
F_4 ( V_5 , F_5 ( V_8 ) , V_5 -> V_9 ) ;
F_4 ( V_5 , F_5 ( ERROR ) , V_5 -> V_9 ) ;
V_43 = F_7 ( V_5 , F_31 ( V_8 ) ) ;
V_42 = F_7 ( V_5 , F_31 ( ERROR ) ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_52 . V_55 ; V_51 ++ )
F_24 ( V_5 , V_51 , V_42 , V_43 ) ;
F_13 ( V_5 , F_5 ( V_8 ) , V_5 -> V_9 ) ;
F_13 ( V_5 , F_5 ( ERROR ) , V_5 -> V_9 ) ;
return V_56 ;
}
static struct V_25 * F_32 ( unsigned int V_57 )
{
struct V_25 * V_26 ;
V_26 = F_33 ( sizeof( * V_26 ) , V_58 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_28 = F_34 ( V_57 , sizeof( * V_26 -> V_28 ) , V_58 ) ;
if ( ! V_26 -> V_28 ) {
F_35 ( V_26 ) ;
return NULL ;
}
return V_26 ;
}
static void F_36 ( struct V_14 * V_15 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 ;
if ( V_26 -> V_57 ) {
unsigned int V_51 = V_26 -> V_57 ;
do {
V_28 = & V_26 -> V_28 [ -- V_51 ] ;
F_37 ( V_15 -> V_59 , V_28 -> V_60 , V_28 -> V_36 ) ;
} while ( V_51 );
}
F_35 ( V_26 -> V_28 ) ;
F_35 ( V_26 ) ;
}
static void F_38 ( struct V_38 * V_39 )
{
struct V_14 * V_15 = F_39 ( V_39 -> V_61 . V_3 ) ;
F_36 ( V_15 , F_23 ( V_39 ) ) ;
}
static T_3 F_40 ( struct V_27 * V_28 ,
struct V_62 * V_63 ,
enum V_64 V_65 , T_3 V_36 )
{
struct V_66 * V_60 = V_28 -> V_60 ;
T_3 V_67 , V_68 ;
T_1 V_69 = F_17 ( V_28 -> V_70 ) ;
T_1 V_71 = V_33 | V_34 ;
T_1 V_72 , V_73 ;
if ( V_65 == V_74 ) {
V_67 = V_28 -> V_75 ;
V_68 = V_63 -> V_76 ;
V_71 |= V_77 | V_78 |
V_79 ;
V_72 = F_41 ( T_1 , 2 , F_42 ( V_67 | V_28 -> V_70 ) ) ;
V_73 = F_42 ( V_63 -> V_80 ) ;
} else {
V_67 = V_63 -> V_81 ;
V_68 = V_28 -> V_75 ;
V_71 |= V_82 | V_83 |
V_84 ;
V_72 = F_42 ( V_63 -> V_85 ) ;
V_73 = F_41 ( T_1 , 2 , F_42 ( V_68 | V_28 -> V_70 ) ) ;
}
V_60 -> V_67 = V_67 ;
V_60 -> V_68 = V_68 ;
V_60 -> V_69 = V_69 ;
V_60 -> V_71 = V_71 |
F_43 ( V_63 -> V_86 ) |
F_44 ( V_63 -> V_87 ) |
F_45 ( V_73 ) |
F_46 ( V_72 ) ;
V_60 -> V_36 = V_36 ;
return V_28 -> V_36 ;
}
static void F_47 ( struct V_14 * V_15 ,
struct V_25 * V_26 )
{
struct V_62 * V_63 = & V_15 -> V_63 ;
struct V_27 * V_28 = & V_26 -> V_28 [ V_26 -> V_57 - 1 ] ;
struct V_66 * V_60 = V_28 -> V_60 ;
T_3 V_36 = 0 ;
unsigned int V_51 = V_26 -> V_57 ;
do {
V_28 = & V_26 -> V_28 [ -- V_51 ] ;
V_36 = F_40 ( V_28 , V_63 , V_26 -> V_65 , V_36 ) ;
V_26 -> V_88 += V_28 -> V_70 ;
} while ( V_51 );
V_60 -> V_71 |= V_89 ;
}
static struct V_90 * F_48 (
struct V_2 * V_3 , struct V_91 * V_92 ,
unsigned int V_93 , enum V_64 V_65 ,
unsigned long V_44 , void * V_94 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
struct V_25 * V_26 ;
struct V_91 * V_95 ;
unsigned int V_51 ;
V_26 = F_32 ( V_93 ) ;
if ( ! V_26 )
return NULL ;
F_49 (sgl, sg, sg_len, i) {
struct V_27 * V_28 = & V_26 -> V_28 [ V_51 ] ;
V_28 -> V_60 = F_50 ( V_15 -> V_59 , V_58 , & V_28 -> V_36 ) ;
if ( ! V_28 -> V_60 ) {
V_26 -> V_57 = V_51 ;
F_36 ( V_15 , V_26 ) ;
return NULL ;
}
V_28 -> V_75 = F_51 ( V_95 ) ;
V_28 -> V_70 = F_52 ( V_95 ) ;
}
V_26 -> V_57 = V_93 ;
V_26 -> V_65 = V_65 ;
V_26 -> V_46 = V_96 ;
F_47 ( V_15 , V_26 ) ;
return F_53 ( & V_15 -> V_37 , & V_26 -> V_39 , V_44 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_44 ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
if ( F_55 ( & V_15 -> V_37 ) && ! V_15 -> V_26 )
F_20 ( V_15 ) ;
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
}
static T_4 F_56 ( struct V_14 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_26 ;
struct V_27 * V_28 ;
T_4 V_97 = V_26 -> V_88 ;
T_3 V_36 = F_57 ( V_15 , V_35 ) ;
T_1 V_69 = F_58 ( V_15 , V_31 ) ;
unsigned int V_51 = 0 ;
do {
V_28 = & V_26 -> V_28 [ V_51 ] ;
if ( V_28 -> V_36 == V_36 )
break;
V_97 -= V_28 -> V_70 ;
} while ( ++ V_51 < V_26 -> V_57 );
if ( ! V_51 )
return V_97 ;
V_97 += V_26 -> V_28 [ -- V_51 ] . V_70 ;
return V_97 - F_17 ( V_69 ) ;
}
static enum V_98 F_59 ( struct V_2 * V_3 ,
T_5 V_99 , struct V_100 * V_101 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
struct V_38 * V_39 ;
enum V_98 V_46 ;
T_4 V_97 ;
unsigned long V_44 ;
V_46 = F_60 ( V_3 , V_99 , V_101 ) ;
if ( V_46 == V_48 )
return V_46 ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
V_39 = F_61 ( & V_15 -> V_37 , V_99 ) ;
if ( V_15 -> V_26 && V_99 == V_15 -> V_26 -> V_39 . V_61 . V_99 ) {
V_97 = F_56 ( V_15 ) ;
F_62 ( V_101 , V_97 ) ;
V_46 = V_15 -> V_26 -> V_46 ;
} else if ( V_39 ) {
V_97 = F_23 ( V_39 ) -> V_88 ;
F_62 ( V_101 , V_97 ) ;
}
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
return V_46 ;
}
static void F_63 ( T_1 * V_102 )
{
if ( * V_102 )
* V_102 = F_42 ( * V_102 ) ;
else
* V_102 = 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
if ( ! F_65 ( V_63 -> V_65 ) )
return - V_103 ;
memcpy ( & V_15 -> V_63 , V_63 , sizeof( V_15 -> V_63 ) ) ;
F_63 ( & V_15 -> V_63 . V_86 ) ;
F_63 ( & V_15 -> V_63 . V_87 ) ;
return 0 ;
}
static void F_66 ( struct V_14 * V_15 )
{
unsigned short V_6 = 100 ;
T_1 V_17 ;
V_17 = F_58 ( V_15 , V_21 ) ;
F_12 ( V_15 , V_21 , V_17 | V_104 ) ;
do {
F_67 ( 1 ) ;
V_17 = F_58 ( V_15 , V_21 ) ;
} while ( ! ( V_17 & V_105 ) && -- V_6 );
}
static void F_68 ( struct V_14 * V_15 )
{
T_1 V_17 ;
V_17 = F_58 ( V_15 , V_21 ) ;
F_12 ( V_15 , V_21 , V_17 & ~ V_104 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_44 ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
if ( V_15 -> V_26 && V_15 -> V_26 -> V_46 == V_96 ) {
F_66 ( V_15 ) ;
V_15 -> V_26 -> V_46 = V_106 ;
}
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_44 ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
if ( V_15 -> V_26 && V_15 -> V_26 -> V_46 == V_106 ) {
V_15 -> V_26 -> V_46 = V_96 ;
F_68 ( V_15 ) ;
}
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
unsigned long V_44 ;
F_72 ( V_107 ) ;
F_25 ( & V_15 -> V_37 . V_45 , V_44 ) ;
F_66 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_26 ) {
F_38 ( & V_15 -> V_26 -> V_39 ) ;
V_15 -> V_26 = NULL ;
}
F_73 ( & V_15 -> V_37 , & V_107 ) ;
F_28 ( & V_15 -> V_37 . V_45 , V_44 ) ;
F_74 ( & V_15 -> V_37 , & V_107 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
V_15 -> V_59 = F_76 ( F_77 ( F_1 ( V_3 ) ) ,
V_3 -> V_1 -> V_4 ,
sizeof( struct V_66 ) , 8 , 0 ) ;
if ( ! V_15 -> V_59 ) {
F_78 ( F_1 ( V_3 ) , L_2 ) ;
return - V_108 ;
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_39 ( V_3 ) ;
F_80 ( F_81 ( V_3 ) ) ;
F_82 ( V_15 -> V_59 ) ;
V_15 -> V_59 = NULL ;
}
static int F_83 ( struct V_109 * V_110 )
{
struct V_5 * V_5 ;
unsigned short V_111 = V_112 ;
unsigned short V_51 ;
int V_113 ;
V_5 = F_84 ( V_110 -> V_4 , sizeof( * V_5 ) , V_114 ) ;
if ( ! V_5 )
return - V_108 ;
V_5 -> V_115 = V_110 -> V_115 ;
V_110 -> V_5 = V_5 ;
V_5 -> V_3 = F_85 ( V_110 -> V_4 , V_111 , sizeof( * V_5 -> V_3 ) ,
V_114 ) ;
if ( ! V_5 -> V_3 )
return - V_108 ;
V_5 -> V_9 = ( 1 << V_111 ) - 1 ;
F_2 ( V_5 ) ;
V_113 = F_86 ( V_110 -> V_4 , V_110 -> V_49 , F_29 , V_116 ,
F_77 ( V_110 -> V_4 ) , V_5 ) ;
if ( V_113 )
return V_113 ;
F_87 ( & V_5 -> V_52 . V_117 ) ;
for ( V_51 = 0 ; V_51 < V_111 ; V_51 ++ ) {
struct V_14 * V_15 = & V_5 -> V_3 [ V_51 ] ;
V_15 -> V_37 . V_118 = F_38 ;
F_88 ( & V_15 -> V_37 , & V_5 -> V_52 ) ;
V_15 -> V_115 = V_5 -> V_115 + V_51 * V_119 ;
V_15 -> V_23 = F_89 ( V_51 ) ;
}
F_90 ( V_120 , V_5 -> V_52 . V_121 ) ;
F_90 ( V_122 , V_5 -> V_52 . V_121 ) ;
V_5 -> V_52 . V_123 = F_75 ;
V_5 -> V_52 . V_124 = F_79 ;
V_5 -> V_52 . V_125 = F_48 ;
V_5 -> V_52 . V_126 = F_54 ;
V_5 -> V_52 . V_127 = F_59 ;
V_5 -> V_52 . V_128 = F_64 ;
V_5 -> V_52 . V_129 = F_69 ;
V_5 -> V_52 . V_130 = F_70 ;
V_5 -> V_52 . V_131 = F_71 ;
V_5 -> V_52 . V_132 = V_133 ;
V_5 -> V_52 . V_134 = V_133 ;
V_5 -> V_52 . V_135 = F_89 ( V_136 ) | F_89 ( V_74 ) ;
V_5 -> V_52 . V_137 = V_138 ;
V_5 -> V_52 . V_4 = V_110 -> V_4 ;
V_113 = F_91 ( & V_5 -> V_52 ) ;
if ( V_113 )
return V_113 ;
F_92 ( V_110 -> V_4 , L_3 ) ;
return 0 ;
}
static int F_93 ( struct V_109 * V_110 )
{
struct V_5 * V_5 = V_110 -> V_5 ;
unsigned short V_51 ;
F_94 ( & V_5 -> V_52 ) ;
F_95 ( V_110 -> V_4 , V_110 -> V_49 , V_5 ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_52 . V_55 ; V_51 ++ ) {
struct V_14 * V_15 = & V_5 -> V_3 [ V_51 ] ;
F_96 ( & V_15 -> V_37 . V_139 ) ;
}
return 0 ;
}
static int F_97 ( struct V_140 * V_141 )
{
struct V_109 * V_110 ;
struct V_1 * V_4 = & V_141 -> V_4 ;
struct V_142 * V_143 ;
int V_113 ;
V_110 = F_84 ( V_4 , sizeof( * V_110 ) , V_114 ) ;
if ( ! V_110 )
return - V_108 ;
V_110 -> V_49 = F_98 ( V_141 , 0 ) ;
if ( V_110 -> V_49 < 0 )
return V_110 -> V_49 ;
V_143 = F_99 ( V_141 , V_144 , 0 ) ;
V_110 -> V_115 = F_100 ( V_4 , V_143 ) ;
if ( F_101 ( V_110 -> V_115 ) )
return F_102 ( V_110 -> V_115 ) ;
V_113 = F_103 ( & V_141 -> V_4 , F_104 ( 64 ) ) ;
if ( V_113 )
return V_113 ;
V_110 -> V_4 = V_4 ;
V_113 = F_83 ( V_110 ) ;
if ( V_113 )
return V_113 ;
F_105 ( V_141 , V_110 ) ;
return 0 ;
}
static int F_106 ( struct V_140 * V_141 )
{
struct V_109 * V_110 = F_107 ( V_141 ) ;
return F_93 ( V_110 ) ;
}
static int F_108 ( struct V_1 * V_4 )
{
struct V_140 * V_141 = F_109 ( V_4 ) ;
struct V_109 * V_110 = F_107 ( V_141 ) ;
F_2 ( V_110 -> V_5 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_4 )
{
struct V_140 * V_141 = F_109 ( V_4 ) ;
struct V_109 * V_110 = F_107 ( V_141 ) ;
F_8 ( V_110 -> V_5 ) ;
return 0 ;
}
