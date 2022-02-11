static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) ;
}
static struct V_4 * F_3 ( const struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_5 ) ;
}
static struct V_4 * F_5 ( const struct V_2 * V_3 )
{
return F_6 ( V_3 -> V_5 ) ;
}
static struct V_6 * F_7 ( struct V_6 T_1 * V_7 )
{
struct V_6 * V_8 = F_4 ( V_7 ) ;
if ( ! V_8 || ! V_8 -> V_9 )
return NULL ;
if ( ! F_8 ( & V_8 -> V_10 ) )
return NULL ;
return V_8 ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_12 , struct V_13 , V_11 ) ;
F_11 ( V_14 -> V_15 ) ;
F_12 ( V_14 ) ;
}
static struct V_13 * F_13 ( struct V_13 * V_16 )
{
return F_8 ( & V_16 -> V_10 ) ? V_16 : NULL ;
}
static void F_14 ( struct V_13 * V_16 )
{
if ( F_15 ( & V_16 -> V_10 ) )
F_16 ( & V_16 -> V_11 , F_9 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_6 * V_8 = F_10 ( V_12 , struct V_6 , V_17 ) ;
F_18 ( V_8 -> V_18 . V_19 ) ;
F_11 ( V_8 -> V_15 ) ;
F_12 ( V_8 ) ;
}
static void F_19 ( struct V_6 * V_8 )
{
if ( F_15 ( & V_8 -> V_10 ) )
F_16 ( & V_8 -> V_17 , F_17 ) ;
}
static struct V_20 * F_20 ( struct V_20 T_1 * V_7 )
{
struct V_20 * V_8 = F_4 ( V_7 ) ;
if ( ! V_8 || ! V_8 -> V_9 )
return NULL ;
if ( ! F_8 ( & V_8 -> V_10 ) )
return NULL ;
return V_8 ;
}
static void F_21 ( struct V_11 * V_12 )
{
struct V_20 * V_8 = F_10 ( V_12 , struct V_20 , V_17 ) ;
F_18 ( V_8 -> V_18 . V_19 ) ;
F_11 ( V_8 -> V_15 ) ;
F_12 ( V_8 ) ;
}
static void F_22 ( struct V_20 * V_8 )
{
if ( F_15 ( & V_8 -> V_10 ) )
F_16 ( & V_8 -> V_17 , F_21 ) ;
}
static struct V_21 * F_23 ( struct V_22 * V_23 )
{
F_24 ( sizeof( struct V_21 ) > sizeof( V_23 -> V_24 ) ) ;
return (struct V_21 * ) V_23 -> V_24 ;
}
static bool F_25 ( const struct V_25 * V_26 )
{
const struct V_27 * V_28 = & V_26 -> V_28 ;
return V_28 -> F_25 ||
( V_26 -> V_29 > 1 && ! V_28 -> V_30 && ! V_28 -> V_31 ) ;
}
static T_2 F_26 ( T_3 * V_32 , T_4 V_33 )
{
T_2 V_34 ;
memcpy ( & V_34 , V_32 , V_35 ) ;
memcpy ( ( ( char * ) & V_34 ) + V_35 , & V_33 , sizeof( V_33 ) ) ;
return V_34 ;
}
static T_2 F_27 ( struct V_36 * V_37 , bool V_38 )
{
T_2 V_34 ;
if ( V_38 )
memcpy ( & V_34 , V_37 -> V_39 ,
sizeof( V_37 -> V_39 ) ) ;
else
V_34 = F_26 ( V_37 -> V_40 . V_41 , V_42 ) ;
return V_34 ;
}
static unsigned int F_28 ( bool V_38 )
{
return V_43 + ( V_38 ? V_44 : 0 ) ;
}
static unsigned int F_29 ( bool V_38 )
{
return F_28 ( V_38 ) + V_45 ;
}
static unsigned int F_30 ( bool V_38 )
{
return F_28 ( V_38 ) + sizeof( T_4 ) ;
}
static void F_31 ( struct V_36 * V_46 ,
const struct V_25 * V_26 , T_5 V_47 ,
bool V_38 )
{
const struct V_27 * V_28 = & V_26 -> V_28 ;
memset ( & V_46 -> V_48 , 0 , F_28 ( V_38 ) ) ;
V_46 -> V_40 . V_49 = F_32 ( V_50 ) ;
if ( V_38 ) {
V_46 -> V_48 |= V_51 ;
memcpy ( & V_46 -> V_39 , & V_26 -> V_34 ,
sizeof( V_46 -> V_39 ) ) ;
} else {
if ( V_28 -> V_30 )
V_46 -> V_48 |= V_52 ;
if ( V_28 -> V_31 )
V_46 -> V_48 |= V_53 ;
}
V_46 -> V_54 = F_33 ( V_47 ) ;
if ( V_28 -> V_55 )
V_46 -> V_48 |= V_56 ;
else if ( V_26 -> V_57 != V_58 )
V_46 -> V_48 |= V_59 ;
V_46 -> V_48 |= V_28 -> V_60 ;
}
static void F_34 ( struct V_36 * V_46 , T_6 V_61 )
{
if ( V_61 < V_62 )
V_46 -> V_63 = V_61 ;
}
static bool F_35 ( struct V_22 * V_23 , T_7 V_57 )
{
struct V_36 * V_46 = (struct V_36 * ) V_23 -> V_64 ;
int V_65 = V_23 -> V_65 - 2 * V_35 ;
int V_66 = F_30 ( ! ! ( V_46 -> V_48 & V_51 ) ) + V_57 ;
if ( V_23 -> V_65 <= 16 )
return false ;
if ( V_46 -> V_48 & V_67 )
return false ;
if ( ( V_46 -> V_48 & V_52 || V_46 -> V_48 & V_53 ) &&
( V_46 -> V_48 & V_51 ) )
return false ;
if ( V_46 -> V_68 )
return false ;
if ( ! V_46 -> V_54 )
return false ;
if ( V_46 -> V_63 )
return V_65 == V_66 + V_46 -> V_63 ;
return V_65 >= V_66 + V_62 ;
}
static void F_36 ( unsigned char * V_69 , T_2 V_34 , T_5 V_47 )
{
struct V_70 * V_70 = (struct V_70 * ) V_69 ;
V_70 -> V_34 = V_34 ;
V_70 -> V_47 = F_33 ( V_47 ) ;
}
static struct V_36 * F_37 ( struct V_22 * V_23 )
{
return (struct V_36 * ) F_38 ( V_23 ) ;
}
static T_5 F_39 ( struct V_20 * V_71 , struct V_25 * V_26 )
{
T_5 V_47 ;
F_40 ( & V_71 -> V_72 ) ;
V_47 = V_71 -> V_73 ;
V_71 -> V_73 ++ ;
if ( V_71 -> V_73 == 0 ) {
F_41 ( L_1 ) ;
V_71 -> V_9 = false ;
if ( V_26 -> V_74 )
V_26 -> V_75 = false ;
}
F_42 ( & V_71 -> V_72 ) ;
return V_47 ;
}
static void F_43 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_1 * V_76 = F_2 ( V_3 ) ;
V_23 -> V_3 = V_76 -> V_77 ;
F_44 ( V_23 ) ;
V_23 -> V_78 = F_45 ( V_23 ) -> V_49 ;
}
static void F_46 ( struct V_22 * V_23 , struct V_27 * V_28 ,
struct V_20 * V_71 )
{
struct V_79 * V_80 = F_47 ( V_28 -> V_15 ) ;
F_48 ( & V_80 -> V_81 ) ;
if ( V_28 -> V_55 ) {
V_80 -> V_15 . V_82 += V_23 -> V_65 ;
V_80 -> V_15 . V_83 ++ ;
F_49 ( V_71 -> V_15 -> V_83 ) ;
} else {
V_80 -> V_15 . V_84 += V_23 -> V_65 ;
V_80 -> V_15 . V_85 ++ ;
F_49 ( V_71 -> V_15 -> V_85 ) ;
}
F_50 ( & V_80 -> V_81 ) ;
}
static void F_51 ( struct V_2 * V_3 , int V_86 , int V_65 )
{
if ( F_52 ( V_86 == V_87 || V_86 == V_88 ) ) {
struct V_89 * V_15 = F_47 ( V_3 -> V_90 ) ;
F_48 ( & V_15 -> V_81 ) ;
V_15 -> V_91 ++ ;
V_15 -> V_92 += V_65 ;
F_50 ( & V_15 -> V_81 ) ;
} else {
V_3 -> V_15 . V_93 ++ ;
}
}
static void F_53 ( struct V_94 * V_95 , int V_96 )
{
struct V_22 * V_23 = V_95 -> V_64 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_20 * V_8 = F_23 ( V_23 ) -> V_71 ;
int V_65 , V_86 ;
F_54 ( F_23 ( V_23 ) -> V_97 ) ;
F_55 () ;
F_43 ( V_23 , V_3 ) ;
F_46 ( V_23 , & V_76 -> V_26 . V_28 , F_23 ( V_23 ) -> V_71 ) ;
V_65 = V_23 -> V_65 ;
V_86 = F_56 ( V_23 ) ;
F_51 ( V_3 , V_86 , V_65 ) ;
F_57 () ;
F_22 ( V_8 ) ;
F_58 ( V_3 ) ;
}
static struct V_98 * F_59 ( struct V_99 * V_19 ,
unsigned char * * V_69 ,
struct V_100 * * V_101 )
{
T_6 V_102 , V_103 , V_104 ;
struct V_98 * V_97 ;
void * V_105 ;
V_102 = sizeof( struct V_98 ) + F_60 ( V_19 ) ;
V_103 = V_102 ;
V_102 += V_106 ;
V_102 = F_61 ( V_102 , F_62 ( struct V_100 ) ) ;
V_104 = V_102 ;
V_102 += sizeof( struct V_100 ) * ( V_107 + 1 ) ;
V_105 = F_63 ( V_102 , V_108 ) ;
if ( ! V_105 )
return NULL ;
* V_69 = ( unsigned char * ) ( V_105 + V_103 ) ;
* V_101 = (struct V_100 * ) ( V_105 + V_104 ) ;
V_97 = V_105 ;
F_64 ( V_97 , V_19 ) ;
return V_97 ;
}
static struct V_22 * F_65 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
int V_86 ;
struct V_100 * V_101 ;
unsigned char * V_69 ;
struct V_109 * V_40 ;
struct V_36 * V_110 ;
T_6 V_111 ;
struct V_98 * V_97 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
bool V_38 ;
T_5 V_47 ;
V_26 = & V_76 -> V_26 ;
V_28 = & V_26 -> V_28 ;
V_71 = F_20 ( V_28 -> V_8 [ V_28 -> V_60 ] ) ;
if ( ! V_71 ) {
V_26 -> V_75 = false ;
F_66 ( V_23 ) ;
return F_67 ( - V_112 ) ;
}
if ( F_68 ( F_69 ( V_23 ) < V_113 ||
F_70 ( V_23 ) < V_114 ) ) {
struct V_22 * V_115 = F_71 ( V_23 ,
V_113 ,
V_114 ,
V_108 ) ;
if ( F_52 ( V_115 ) ) {
F_72 ( V_23 ) ;
V_23 = V_115 ;
} else {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_116 ) ;
}
} else {
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
F_22 ( V_71 ) ;
return F_67 ( - V_116 ) ;
}
}
V_111 = V_23 -> V_65 ;
V_40 = F_45 ( V_23 ) ;
V_38 = F_25 ( V_26 ) ;
V_110 = (struct V_36 * ) F_74 ( V_23 , F_30 ( V_38 ) ) ;
memmove ( V_110 , V_40 , 2 * V_35 ) ;
V_47 = F_39 ( V_71 , V_26 ) ;
if ( V_47 == 0 ) {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_117 ) ;
}
F_31 ( V_110 , V_26 , V_47 , V_38 ) ;
F_34 ( V_110 , V_111 - 2 * V_35 ) ;
F_75 ( V_23 , V_26 -> V_57 ) ;
if ( V_23 -> V_65 - V_45 > F_1 ( V_3 ) -> V_77 -> V_118 ) {
struct V_119 * V_120 = F_47 ( V_76 -> V_15 ) ;
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_121 ++ ;
F_50 ( & V_120 -> V_81 ) ;
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_112 ) ;
}
V_97 = F_59 ( V_71 -> V_18 . V_19 , & V_69 , & V_101 ) ;
if ( ! V_97 ) {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_116 ) ;
}
F_36 ( V_69 , V_26 -> V_34 , V_47 ) ;
F_76 ( V_101 , V_107 + 1 ) ;
F_77 ( V_23 , V_101 , 0 , V_23 -> V_65 ) ;
if ( V_28 -> V_55 ) {
int V_65 = V_23 -> V_65 - F_29 ( V_38 ) -
V_26 -> V_57 ;
F_78 ( V_97 , V_101 , V_101 , V_65 , V_69 ) ;
F_79 ( V_97 , F_29 ( V_38 ) ) ;
} else {
F_78 ( V_97 , V_101 , V_101 , 0 , V_69 ) ;
F_79 ( V_97 , V_23 -> V_65 - V_26 -> V_57 ) ;
}
F_23 ( V_23 ) -> V_97 = V_97 ;
F_23 ( V_23 ) -> V_71 = V_71 ;
F_80 ( V_97 , 0 , F_53 , V_23 ) ;
F_81 ( V_23 -> V_3 ) ;
V_86 = F_82 ( V_97 ) ;
if ( V_86 == - V_122 ) {
return F_67 ( V_86 ) ;
} else if ( V_86 != 0 ) {
F_58 ( V_23 -> V_3 ) ;
F_66 ( V_23 ) ;
F_54 ( V_97 ) ;
F_22 ( V_71 ) ;
return F_67 ( - V_112 ) ;
}
F_58 ( V_23 -> V_3 ) ;
F_54 ( V_97 ) ;
F_22 ( V_71 ) ;
return V_23 ;
}
static bool F_83 ( struct V_22 * V_23 , struct V_25 * V_26 , T_5 V_47 )
{
struct V_6 * V_123 = F_23 ( V_23 ) -> V_123 ;
struct V_124 * V_125 = F_47 ( V_123 -> V_16 -> V_15 ) ;
struct V_36 * V_37 = F_37 ( V_23 ) ;
T_5 V_126 = 0 ;
F_84 ( & V_123 -> V_72 ) ;
if ( V_123 -> V_73 >= V_26 -> V_127 )
V_126 = V_123 -> V_73 - V_26 -> V_127 ;
if ( V_26 -> V_128 && V_47 < V_126 ) {
F_85 ( & V_123 -> V_72 ) ;
F_48 ( & V_125 -> V_81 ) ;
V_125 -> V_15 . V_129 ++ ;
F_50 ( & V_125 -> V_81 ) ;
return false ;
}
if ( V_26 -> V_130 != V_131 ) {
F_48 ( & V_125 -> V_81 ) ;
if ( V_37 -> V_48 & V_132 )
V_125 -> V_15 . V_133 += V_23 -> V_65 ;
else
V_125 -> V_15 . V_134 += V_23 -> V_65 ;
F_50 ( & V_125 -> V_81 ) ;
}
if ( ! F_23 ( V_23 ) -> V_135 ) {
F_85 ( & V_123 -> V_72 ) ;
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_130 == V_136 ) {
F_48 ( & V_125 -> V_81 ) ;
V_125 -> V_15 . V_137 ++ ;
F_50 ( & V_125 -> V_81 ) ;
return false ;
}
F_48 ( & V_125 -> V_81 ) ;
if ( V_26 -> V_130 == V_138 ) {
V_125 -> V_15 . V_139 ++ ;
F_49 ( V_123 -> V_15 -> V_139 ) ;
} else if ( V_47 < V_126 ) {
V_125 -> V_15 . V_140 ++ ;
} else {
V_125 -> V_15 . V_141 ++ ;
}
F_50 ( & V_125 -> V_81 ) ;
} else {
F_48 ( & V_125 -> V_81 ) ;
if ( V_47 < V_126 ) {
V_125 -> V_15 . V_140 ++ ;
} else {
V_125 -> V_15 . V_142 ++ ;
F_49 ( V_123 -> V_15 -> V_142 ) ;
}
F_50 ( & V_125 -> V_81 ) ;
if ( V_47 >= V_123 -> V_73 )
V_123 -> V_73 = V_47 + 1 ;
F_85 ( & V_123 -> V_72 ) ;
}
return true ;
}
static void F_86 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
V_23 -> V_143 = V_144 ;
V_23 -> V_78 = F_87 ( V_23 , V_3 ) ;
F_88 ( V_23 ) ;
if ( ! F_89 ( V_23 ) )
F_90 ( V_23 ) ;
F_91 ( V_23 ) ;
}
static void F_92 ( struct V_22 * V_23 , T_3 V_57 , T_3 V_145 )
{
memmove ( V_23 -> V_64 + V_145 , V_23 -> V_64 , 2 * V_35 ) ;
F_93 ( V_23 , V_145 ) ;
F_94 ( V_23 , V_23 -> V_65 - V_57 ) ;
}
static void F_95 ( struct V_2 * V_3 , int V_65 )
{
struct V_89 * V_15 = F_47 ( V_3 -> V_90 ) ;
F_48 ( & V_15 -> V_81 ) ;
V_15 -> V_146 ++ ;
V_15 -> V_147 += V_65 ;
F_50 ( & V_15 -> V_81 ) ;
}
static void F_96 ( struct V_94 * V_95 , int V_96 )
{
struct V_22 * V_23 = V_95 -> V_64 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_6 * V_123 = F_23 ( V_23 ) -> V_123 ;
struct V_13 * V_14 = V_123 -> V_16 ;
int V_65 , V_86 ;
T_5 V_47 ;
F_54 ( F_23 ( V_23 ) -> V_97 ) ;
F_55 () ;
V_47 = F_97 ( F_37 ( V_23 ) -> V_54 ) ;
if ( ! F_83 ( V_23 , & V_76 -> V_26 , V_47 ) ) {
F_57 () ;
F_66 ( V_23 ) ;
goto V_148;
}
F_92 ( V_23 , V_76 -> V_26 . V_57 ,
F_30 ( F_23 ( V_23 ) -> V_149 ) ) ;
F_86 ( V_23 , V_76 -> V_26 . V_150 ) ;
V_65 = V_23 -> V_65 ;
V_86 = F_98 ( & V_76 -> V_151 , V_23 ) ;
if ( V_86 == V_152 )
F_95 ( V_3 , V_65 ) ;
else
V_76 -> V_26 . V_150 -> V_15 . V_153 ++ ;
F_57 () ;
V_148:
F_19 ( V_123 ) ;
F_14 ( V_14 ) ;
F_58 ( V_3 ) ;
}
static struct V_22 * F_99 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
struct V_6 * V_123 ,
T_2 V_34 ,
struct V_25 * V_26 )
{
int V_86 ;
struct V_100 * V_101 ;
unsigned char * V_69 ;
struct V_98 * V_97 ;
struct V_36 * V_37 ;
T_7 V_57 = V_26 -> V_57 ;
F_23 ( V_23 ) -> V_135 = false ;
V_23 = F_100 ( V_23 , V_108 ) ;
if ( ! V_23 )
return F_67 ( - V_116 ) ;
V_97 = F_59 ( V_123 -> V_18 . V_19 , & V_69 , & V_101 ) ;
if ( ! V_97 ) {
F_66 ( V_23 ) ;
return F_67 ( - V_116 ) ;
}
V_37 = (struct V_36 * ) V_23 -> V_64 ;
F_36 ( V_69 , V_34 , F_97 ( V_37 -> V_54 ) ) ;
F_76 ( V_101 , V_107 + 1 ) ;
F_77 ( V_23 , V_101 , 0 , V_23 -> V_65 ) ;
if ( V_37 -> V_48 & V_132 ) {
int V_65 = V_23 -> V_65 - F_29 ( F_23 ( V_23 ) -> V_149 ) ;
F_78 ( V_97 , V_101 , V_101 , V_65 , V_69 ) ;
F_79 ( V_97 , F_29 ( F_23 ( V_23 ) -> V_149 ) ) ;
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
F_54 ( V_97 ) ;
return F_67 ( - V_116 ) ;
}
} else {
F_78 ( V_97 , V_101 , V_101 , V_57 , V_69 ) ;
F_79 ( V_97 , V_23 -> V_65 - V_57 ) ;
}
F_23 ( V_23 ) -> V_97 = V_97 ;
V_23 -> V_3 = V_3 ;
F_80 ( V_97 , 0 , F_96 , V_23 ) ;
F_81 ( V_3 ) ;
V_86 = F_101 ( V_97 ) ;
if ( V_86 == - V_122 ) {
return F_67 ( V_86 ) ;
} else if ( V_86 != 0 ) {
if ( V_86 != - V_154 ) {
F_66 ( V_23 ) ;
V_23 = F_67 ( V_86 ) ;
}
} else {
F_23 ( V_23 ) -> V_135 = true ;
}
F_58 ( V_3 ) ;
F_54 ( V_97 ) ;
return V_23 ;
}
static struct V_13 * F_102 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 ;
F_103 (secy, rx_sc) {
if ( V_14 -> V_34 == V_34 )
return V_14 ;
}
return NULL ;
}
static struct V_13 * F_104 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 ;
F_105 (secy, rx_sc) {
if ( V_14 -> V_34 == V_34 )
return V_14 ;
}
return NULL ;
}
static void F_106 ( struct V_22 * V_23 )
{
struct V_4 * V_155 ;
struct V_1 * V_76 ;
F_107 () ;
V_155 = F_3 ( V_23 -> V_3 ) ;
F_108 (macsec, &rxd->secys, secys) {
struct V_22 * V_115 ;
int V_86 ;
struct V_119 * V_120 = F_47 ( V_76 -> V_15 ) ;
if ( V_76 -> V_26 . V_130 == V_136 ) {
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_156 ++ ;
F_50 ( & V_120 -> V_81 ) ;
continue;
}
V_115 = F_109 ( V_23 , V_108 ) ;
if ( ! V_115 )
break;
V_115 -> V_3 = V_76 -> V_26 . V_150 ;
V_86 = F_110 ( V_115 ) ;
if ( V_86 == V_152 ) {
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_157 ++ ;
F_50 ( & V_120 -> V_81 ) ;
} else {
V_76 -> V_26 . V_150 -> V_15 . V_153 ++ ;
}
}
F_111 () ;
}
static T_8 F_112 ( struct V_22 * * V_158 )
{
struct V_22 * V_23 = * V_158 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_36 * V_37 ;
struct V_25 * V_26 = NULL ;
struct V_13 * V_14 ;
struct V_6 * V_123 ;
struct V_4 * V_155 ;
struct V_1 * V_76 ;
T_2 V_34 ;
T_5 V_47 ;
bool V_159 ;
struct V_124 * V_125 ;
struct V_119 * V_120 ;
bool V_160 ;
int V_86 ;
if ( F_69 ( V_23 ) < V_45 )
goto V_161;
V_37 = F_37 ( V_23 ) ;
if ( V_37 -> V_40 . V_49 != F_32 ( V_50 ) ) {
F_106 ( V_23 ) ;
return V_162 ;
}
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
* V_158 = NULL ;
return V_163 ;
}
V_160 = F_113 ( V_23 , F_30 ( true ) ) ;
if ( ! V_160 ) {
if ( ! F_113 ( V_23 , F_30 ( false ) ) )
goto V_161;
}
V_37 = F_37 ( V_23 ) ;
if ( ( V_37 -> V_48 & ( V_59 | V_132 ) ) == V_132 )
return V_162 ;
if ( V_37 -> V_48 & V_51 ) {
if ( ! V_160 )
goto V_161;
}
F_74 ( V_23 , V_45 ) ;
F_23 ( V_23 ) -> V_149 = ! ! ( V_37 -> V_48 & V_51 ) ;
F_23 ( V_23 ) -> V_164 = V_37 -> V_48 & V_165 ;
V_34 = F_27 ( V_37 , F_23 ( V_23 ) -> V_149 ) ;
F_107 () ;
V_155 = F_3 ( V_23 -> V_3 ) ;
F_108 (macsec, &rxd->secys, secys) {
struct V_13 * V_16 = F_102 ( & V_76 -> V_26 , V_34 ) ;
V_16 = V_16 ? F_13 ( V_16 ) : NULL ;
if ( V_16 ) {
V_26 = & V_76 -> V_26 ;
V_14 = V_16 ;
break;
}
}
if ( ! V_26 )
goto V_166;
V_3 = V_26 -> V_150 ;
V_76 = F_1 ( V_3 ) ;
V_120 = F_47 ( V_76 -> V_15 ) ;
V_125 = F_47 ( V_14 -> V_15 ) ;
if ( ! F_35 ( V_23 , V_26 -> V_57 ) ) {
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_167 ++ ;
F_50 ( & V_120 -> V_81 ) ;
goto V_168;
}
V_123 = F_7 ( V_14 -> V_8 [ F_23 ( V_23 ) -> V_164 ] ) ;
if ( ! V_123 ) {
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_130 == V_136 ) {
F_48 ( & V_125 -> V_81 ) ;
V_125 -> V_15 . V_169 ++ ;
F_50 ( & V_125 -> V_81 ) ;
goto V_168;
}
F_48 ( & V_125 -> V_81 ) ;
V_125 -> V_15 . V_170 ++ ;
F_50 ( & V_125 -> V_81 ) ;
goto V_171;
}
V_47 = F_97 ( V_37 -> V_54 ) ;
if ( V_26 -> V_128 ) {
bool V_172 ;
F_84 ( & V_123 -> V_72 ) ;
V_172 = V_123 -> V_73 >= V_26 -> V_127 &&
V_47 < ( V_123 -> V_73 - V_26 -> V_127 ) ;
F_85 ( & V_123 -> V_72 ) ;
if ( V_172 ) {
F_48 ( & V_125 -> V_81 ) ;
V_125 -> V_15 . V_129 ++ ;
F_50 ( & V_125 -> V_81 ) ;
goto V_173;
}
}
F_23 ( V_23 ) -> V_123 = V_123 ;
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_130 != V_131 )
V_23 = F_99 ( V_23 , V_3 , V_123 , V_34 , V_26 ) ;
if ( F_114 ( V_23 ) ) {
if ( F_115 ( V_23 ) != - V_122 ) {
F_19 ( V_123 ) ;
F_14 ( V_14 ) ;
}
F_111 () ;
* V_158 = NULL ;
return V_163 ;
}
if ( ! F_83 ( V_23 , V_26 , V_47 ) )
goto V_173;
V_171:
F_92 ( V_23 , V_26 -> V_57 ,
F_30 ( F_23 ( V_23 ) -> V_149 ) ) ;
F_86 ( V_23 , V_26 -> V_150 ) ;
if ( V_123 )
F_19 ( V_123 ) ;
F_14 ( V_14 ) ;
V_86 = F_98 ( & V_76 -> V_151 , V_23 ) ;
if ( V_86 == V_152 )
F_95 ( V_3 , V_23 -> V_65 ) ;
else
V_76 -> V_26 . V_150 -> V_15 . V_153 ++ ;
F_111 () ;
* V_158 = NULL ;
return V_163 ;
V_173:
F_19 ( V_123 ) ;
V_168:
F_14 ( V_14 ) ;
F_111 () ;
V_161:
F_66 ( V_23 ) ;
* V_158 = NULL ;
return V_163 ;
V_166:
V_159 = ! ! ( V_37 -> V_48 & V_59 ) ;
if ( ! V_159 )
F_92 ( V_23 , V_58 ,
F_30 ( F_23 ( V_23 ) -> V_149 ) ) ;
F_108 (macsec, &rxd->secys, secys) {
struct V_22 * V_115 ;
V_120 = F_47 ( V_76 -> V_15 ) ;
if ( V_159 ||
V_76 -> V_26 . V_130 == V_136 ) {
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_174 ++ ;
F_50 ( & V_120 -> V_81 ) ;
continue;
}
V_115 = F_109 ( V_23 , V_108 ) ;
if ( ! V_115 )
break;
F_86 ( V_115 , V_76 -> V_26 . V_150 ) ;
V_86 = F_110 ( V_115 ) ;
if ( V_86 == V_152 ) {
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_175 ++ ;
F_50 ( & V_120 -> V_81 ) ;
} else {
V_76 -> V_26 . V_150 -> V_15 . V_153 ++ ;
}
}
F_111 () ;
* V_158 = V_23 ;
return V_162 ;
}
static struct V_99 * F_116 ( char * V_18 , int V_176 , int V_57 )
{
struct V_99 * V_19 ;
int V_86 ;
V_19 = F_117 ( L_2 , 0 , 0 ) ;
if ( F_114 ( V_19 ) )
return V_19 ;
V_86 = F_118 ( V_19 , V_18 , V_176 ) ;
if ( V_86 < 0 )
goto V_177;
V_86 = F_119 ( V_19 , V_57 ) ;
if ( V_86 < 0 )
goto V_177;
return V_19 ;
V_177:
F_18 ( V_19 ) ;
return F_67 ( V_86 ) ;
}
static int F_120 ( struct V_6 * V_123 , char * V_178 , int V_176 ,
int V_57 )
{
V_123 -> V_15 = F_121 ( struct V_179 ) ;
if ( ! V_123 -> V_15 )
return - V_116 ;
V_123 -> V_18 . V_19 = F_116 ( V_178 , V_176 , V_57 ) ;
if ( F_114 ( V_123 -> V_18 . V_19 ) ) {
F_11 ( V_123 -> V_15 ) ;
return F_115 ( V_123 -> V_18 . V_19 ) ;
}
V_123 -> V_9 = false ;
V_123 -> V_73 = 1 ;
F_122 ( & V_123 -> V_10 , 1 ) ;
F_123 ( & V_123 -> V_72 ) ;
return 0 ;
}
static void F_124 ( struct V_6 * V_123 )
{
V_123 -> V_9 = false ;
F_19 ( V_123 ) ;
}
static void F_125 ( struct V_13 * V_14 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
struct V_6 * V_8 = F_6 ( V_14 -> V_8 [ V_180 ] ) ;
F_126 ( V_14 -> V_8 [ V_180 ] , NULL ) ;
if ( V_8 )
F_124 ( V_8 ) ;
}
F_14 ( V_14 ) ;
}
static struct V_13 * F_127 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 , T_1 * * V_182 ;
for ( V_182 = & V_26 -> V_14 , V_14 = F_6 ( * V_182 ) ;
V_14 ;
V_182 = & V_14 -> V_183 , V_14 = F_6 ( * V_182 ) ) {
if ( V_14 -> V_34 == V_34 ) {
if ( V_14 -> V_9 )
V_26 -> V_29 -- ;
F_128 ( * V_182 , V_14 -> V_183 ) ;
return V_14 ;
}
}
return NULL ;
}
static struct V_13 * F_129 ( struct V_2 * V_3 , T_2 V_34 )
{
struct V_13 * V_14 ;
struct V_1 * V_76 ;
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
struct V_4 * V_155 = F_5 ( V_77 ) ;
struct V_25 * V_26 ;
F_130 (macsec, &rxd->secys, secys) {
if ( F_104 ( & V_76 -> V_26 , V_34 ) )
return F_67 ( - V_184 ) ;
}
V_14 = F_131 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return F_67 ( - V_116 ) ;
V_14 -> V_15 = F_132 ( struct V_124 ) ;
if ( ! V_14 -> V_15 ) {
F_12 ( V_14 ) ;
return F_67 ( - V_116 ) ;
}
V_14 -> V_34 = V_34 ;
V_14 -> V_9 = true ;
F_122 ( & V_14 -> V_10 , 1 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
F_128 ( V_14 -> V_183 , V_26 -> V_14 ) ;
F_128 ( V_26 -> V_14 , V_14 ) ;
if ( V_14 -> V_9 )
V_26 -> V_29 ++ ;
return V_14 ;
}
static int F_133 ( struct V_20 * V_71 , char * V_178 , int V_176 ,
int V_57 )
{
V_71 -> V_15 = F_121 ( struct V_186 ) ;
if ( ! V_71 -> V_15 )
return - V_116 ;
V_71 -> V_18 . V_19 = F_116 ( V_178 , V_176 , V_57 ) ;
if ( F_114 ( V_71 -> V_18 . V_19 ) ) {
F_11 ( V_71 -> V_15 ) ;
return F_115 ( V_71 -> V_18 . V_19 ) ;
}
V_71 -> V_9 = false ;
F_122 ( & V_71 -> V_10 , 1 ) ;
F_123 ( & V_71 -> V_72 ) ;
return 0 ;
}
static void F_134 ( struct V_20 * V_71 )
{
V_71 -> V_9 = false ;
F_22 ( V_71 ) ;
}
static struct V_2 * F_135 ( struct V_187 * V_187 ,
struct V_188 * * V_189 )
{
int V_190 = F_136 ( V_189 [ V_191 ] ) ;
struct V_2 * V_3 ;
V_3 = F_137 ( V_187 , V_190 ) ;
if ( ! V_3 )
return F_67 ( - V_192 ) ;
if ( ! F_138 ( V_3 ) )
return F_67 ( - V_192 ) ;
return V_3 ;
}
static T_2 F_139 ( const struct V_188 * V_193 )
{
return ( V_194 T_2 ) F_140 ( V_193 ) ;
}
static int F_141 ( struct V_22 * V_23 , int V_195 , T_2 V_196 ,
int V_197 )
{
return F_142 ( V_23 , V_195 , ( V_194 V_198 ) V_196 , V_197 ) ;
}
static struct V_20 * F_143 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_199 ,
struct V_2 * * V_200 ,
struct V_25 * * V_201 ,
struct V_27 * * V_202 ,
T_3 * V_164 )
{
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
if ( ! V_199 [ V_203 ] )
return F_67 ( - V_112 ) ;
* V_164 = F_144 ( V_199 [ V_203 ] ) ;
V_3 = F_135 ( V_187 , V_189 ) ;
if ( F_114 ( V_3 ) )
return F_145 ( V_3 ) ;
if ( * V_164 >= V_181 )
return F_67 ( - V_112 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
V_71 = F_6 ( V_28 -> V_8 [ * V_164 ] ) ;
if ( ! V_71 )
return F_67 ( - V_192 ) ;
* V_200 = V_3 ;
* V_202 = V_28 ;
* V_201 = V_26 ;
return V_71 ;
}
static struct V_13 * F_146 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_204 ,
struct V_2 * * V_200 ,
struct V_25 * * V_201 )
{
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
T_2 V_34 ;
V_3 = F_135 ( V_187 , V_189 ) ;
if ( F_114 ( V_3 ) )
return F_145 ( V_3 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
if ( ! V_204 [ V_205 ] )
return F_67 ( - V_112 ) ;
V_34 = F_139 ( V_204 [ V_205 ] ) ;
V_14 = F_104 ( V_26 , V_34 ) ;
if ( ! V_14 )
return F_67 ( - V_192 ) ;
* V_201 = V_26 ;
* V_200 = V_3 ;
return V_14 ;
}
static struct V_6 * F_147 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_204 ,
struct V_188 * * V_199 ,
struct V_2 * * V_200 ,
struct V_25 * * V_201 ,
struct V_13 * * V_202 ,
T_3 * V_164 )
{
struct V_13 * V_14 ;
struct V_6 * V_123 ;
if ( ! V_199 [ V_203 ] )
return F_67 ( - V_112 ) ;
* V_164 = F_144 ( V_199 [ V_203 ] ) ;
if ( * V_164 >= V_181 )
return F_67 ( - V_112 ) ;
V_14 = F_146 ( V_187 , V_189 , V_204 , V_200 , V_201 ) ;
if ( F_114 ( V_14 ) )
return F_145 ( V_14 ) ;
V_123 = F_6 ( V_14 -> V_8 [ * V_164 ] ) ;
if ( ! V_123 )
return F_67 ( - V_192 ) ;
* V_202 = V_14 ;
return V_123 ;
}
static int F_148 ( struct V_188 * * V_189 , struct V_188 * * V_199 )
{
if ( ! V_189 [ V_206 ] )
return - V_112 ;
if ( F_149 ( V_199 , V_207 , V_189 [ V_206 ] ,
V_208 ) )
return - V_112 ;
return 0 ;
}
static int F_150 ( struct V_188 * * V_189 , struct V_188 * * V_204 )
{
if ( ! V_189 [ V_209 ] )
return - V_112 ;
if ( F_149 ( V_204 , V_210 , V_189 [ V_209 ] ,
V_211 ) )
return - V_112 ;
return 0 ;
}
static bool F_151 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
! V_189 [ V_212 ] ||
! V_189 [ V_213 ] )
return false ;
if ( F_144 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( V_189 [ V_214 ] && F_136 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_144 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
if ( F_152 ( V_189 [ V_213 ] ) != V_216 )
return false ;
return true ;
}
static int F_153 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_123 ;
unsigned char V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
int V_96 ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
if ( ! F_151 ( V_199 ) )
return - V_112 ;
F_154 () ;
V_14 = F_146 ( F_155 ( V_218 ) , V_189 , V_204 , & V_3 , & V_26 ) ;
if ( F_114 ( V_14 ) ) {
F_156 () ;
return F_115 ( V_14 ) ;
}
V_164 = F_144 ( V_199 [ V_203 ] ) ;
if ( F_152 ( V_199 [ V_212 ] ) != V_26 -> V_176 ) {
F_157 ( L_3 ,
F_152 ( V_199 [ V_212 ] ) , V_26 -> V_176 ) ;
F_156 () ;
return - V_112 ;
}
V_123 = F_6 ( V_14 -> V_8 [ V_164 ] ) ;
if ( V_123 ) {
F_156 () ;
return - V_219 ;
}
V_123 = F_63 ( sizeof( * V_123 ) , V_185 ) ;
if ( ! V_123 ) {
F_156 () ;
return - V_116 ;
}
V_96 = F_120 ( V_123 , F_158 ( V_199 [ V_212 ] ) ,
V_26 -> V_176 , V_26 -> V_57 ) ;
if ( V_96 < 0 ) {
F_12 ( V_123 ) ;
F_156 () ;
return V_96 ;
}
if ( V_199 [ V_214 ] ) {
F_40 ( & V_123 -> V_72 ) ;
V_123 -> V_73 = F_136 ( V_199 [ V_214 ] ) ;
F_42 ( & V_123 -> V_72 ) ;
}
if ( V_199 [ V_215 ] )
V_123 -> V_9 = ! ! F_144 ( V_199 [ V_215 ] ) ;
F_159 ( V_123 -> V_18 . V_220 , V_199 [ V_213 ] , V_216 ) ;
V_123 -> V_16 = V_14 ;
F_128 ( V_14 -> V_8 [ V_164 ] , V_123 ) ;
F_156 () ;
return 0 ;
}
static bool F_160 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_205 ] )
return false ;
if ( V_189 [ V_221 ] ) {
if ( F_144 ( V_189 [ V_221 ] ) > 1 )
return false ;
}
return true ;
}
static int F_161 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
T_2 V_34 = V_222 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_13 * V_14 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
if ( ! F_160 ( V_204 ) )
return - V_112 ;
F_154 () ;
V_3 = F_135 ( F_155 ( V_218 ) , V_189 ) ;
if ( F_114 ( V_3 ) ) {
F_156 () ;
return F_115 ( V_3 ) ;
}
V_34 = F_139 ( V_204 [ V_205 ] ) ;
V_14 = F_129 ( V_3 , V_34 ) ;
if ( F_114 ( V_14 ) ) {
F_156 () ;
return F_115 ( V_14 ) ;
}
if ( V_204 [ V_221 ] )
V_14 -> V_9 = ! ! F_144 ( V_204 [ V_221 ] ) ;
F_156 () ;
return 0 ;
}
static bool F_162 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
! V_189 [ V_214 ] ||
! V_189 [ V_212 ] ||
! V_189 [ V_213 ] )
return false ;
if ( F_144 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( F_136 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_144 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
if ( F_152 ( V_189 [ V_213 ] ) != V_216 )
return false ;
return true ;
}
static int F_163 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
unsigned char V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
int V_96 ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
if ( ! F_162 ( V_199 ) )
return - V_112 ;
F_154 () ;
V_3 = F_135 ( F_155 ( V_218 ) , V_189 ) ;
if ( F_114 ( V_3 ) ) {
F_156 () ;
return F_115 ( V_3 ) ;
}
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
V_164 = F_144 ( V_199 [ V_203 ] ) ;
if ( F_152 ( V_199 [ V_212 ] ) != V_26 -> V_176 ) {
F_157 ( L_4 ,
F_152 ( V_199 [ V_212 ] ) , V_26 -> V_176 ) ;
F_156 () ;
return - V_112 ;
}
V_71 = F_6 ( V_28 -> V_8 [ V_164 ] ) ;
if ( V_71 ) {
F_156 () ;
return - V_219 ;
}
V_71 = F_63 ( sizeof( * V_71 ) , V_185 ) ;
if ( ! V_71 ) {
F_156 () ;
return - V_116 ;
}
V_96 = F_133 ( V_71 , F_158 ( V_199 [ V_212 ] ) ,
V_26 -> V_176 , V_26 -> V_57 ) ;
if ( V_96 < 0 ) {
F_12 ( V_71 ) ;
F_156 () ;
return V_96 ;
}
F_159 ( V_71 -> V_18 . V_220 , V_199 [ V_213 ] , V_216 ) ;
F_40 ( & V_71 -> V_72 ) ;
V_71 -> V_73 = F_136 ( V_199 [ V_214 ] ) ;
F_42 ( & V_71 -> V_72 ) ;
if ( V_199 [ V_215 ] )
V_71 -> V_9 = ! ! F_144 ( V_199 [ V_215 ] ) ;
if ( V_164 == V_28 -> V_60 && V_71 -> V_9 )
V_26 -> V_75 = true ;
F_128 ( V_28 -> V_8 [ V_164 ] , V_71 ) ;
F_156 () ;
return 0 ;
}
static int F_164 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_123 ;
T_3 V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
F_154 () ;
V_123 = F_147 ( F_155 ( V_218 ) , V_189 , V_204 , V_199 ,
& V_3 , & V_26 , & V_14 , & V_164 ) ;
if ( F_114 ( V_123 ) ) {
F_156 () ;
return F_115 ( V_123 ) ;
}
if ( V_123 -> V_9 ) {
F_156 () ;
return - V_219 ;
}
F_126 ( V_14 -> V_8 [ V_164 ] , NULL ) ;
F_124 ( V_123 ) ;
F_156 () ;
return 0 ;
}
static int F_165 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
T_2 V_34 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
if ( ! V_204 [ V_205 ] )
return - V_112 ;
F_154 () ;
V_3 = F_135 ( F_155 ( V_218 ) , V_218 -> V_189 ) ;
if ( F_114 ( V_3 ) ) {
F_156 () ;
return F_115 ( V_3 ) ;
}
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_34 = F_139 ( V_204 [ V_205 ] ) ;
V_14 = F_127 ( V_26 , V_34 ) ;
if ( ! V_14 ) {
F_156 () ;
return - V_192 ;
}
F_125 ( V_14 ) ;
F_156 () ;
return 0 ;
}
static int F_166 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
T_3 V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
F_154 () ;
V_71 = F_143 ( F_155 ( V_218 ) , V_189 , V_199 ,
& V_3 , & V_26 , & V_28 , & V_164 ) ;
if ( F_114 ( V_71 ) ) {
F_156 () ;
return F_115 ( V_71 ) ;
}
if ( V_71 -> V_9 ) {
F_156 () ;
return - V_219 ;
}
F_126 ( V_28 -> V_8 [ V_164 ] , NULL ) ;
F_134 ( V_71 ) ;
F_156 () ;
return 0 ;
}
static bool F_167 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
V_189 [ V_212 ] ||
V_189 [ V_213 ] )
return false ;
if ( F_144 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( V_189 [ V_214 ] && F_136 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_144 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
return true ;
}
static int F_168 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
T_3 V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
if ( ! F_167 ( V_199 ) )
return - V_112 ;
F_154 () ;
V_71 = F_143 ( F_155 ( V_218 ) , V_189 , V_199 ,
& V_3 , & V_26 , & V_28 , & V_164 ) ;
if ( F_114 ( V_71 ) ) {
F_156 () ;
return F_115 ( V_71 ) ;
}
if ( V_199 [ V_214 ] ) {
F_40 ( & V_71 -> V_72 ) ;
V_71 -> V_73 = F_136 ( V_199 [ V_214 ] ) ;
F_42 ( & V_71 -> V_72 ) ;
}
if ( V_199 [ V_215 ] )
V_71 -> V_9 = F_144 ( V_199 [ V_215 ] ) ;
if ( V_164 == V_28 -> V_60 )
V_26 -> V_75 = V_71 -> V_9 ;
F_156 () ;
return 0 ;
}
static int F_169 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_123 ;
T_3 V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
if ( F_148 ( V_189 , V_199 ) )
return - V_112 ;
if ( ! F_167 ( V_199 ) )
return - V_112 ;
F_154 () ;
V_123 = F_147 ( F_155 ( V_218 ) , V_189 , V_204 , V_199 ,
& V_3 , & V_26 , & V_14 , & V_164 ) ;
if ( F_114 ( V_123 ) ) {
F_156 () ;
return F_115 ( V_123 ) ;
}
if ( V_199 [ V_214 ] ) {
F_40 ( & V_123 -> V_72 ) ;
V_123 -> V_73 = F_136 ( V_199 [ V_214 ] ) ;
F_42 ( & V_123 -> V_72 ) ;
}
if ( V_199 [ V_215 ] )
V_123 -> V_9 = F_144 ( V_199 [ V_215 ] ) ;
F_156 () ;
return 0 ;
}
static int F_170 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_112 ;
if ( F_150 ( V_189 , V_204 ) )
return - V_112 ;
if ( ! F_160 ( V_204 ) )
return - V_112 ;
F_154 () ;
V_14 = F_146 ( F_155 ( V_218 ) , V_189 , V_204 , & V_3 , & V_26 ) ;
if ( F_114 ( V_14 ) ) {
F_156 () ;
return F_115 ( V_14 ) ;
}
if ( V_204 [ V_221 ] ) {
bool V_223 = ! ! F_144 ( V_204 [ V_221 ] ) ;
if ( V_14 -> V_9 != V_223 )
V_26 -> V_29 += V_223 ? 1 : - 1 ;
V_14 -> V_9 = V_223 ;
}
F_156 () ;
return 0 ;
}
static int F_171 ( struct V_22 * V_23 ,
struct V_186 T_9 * V_224 )
{
struct V_186 V_225 = { 0 , } ;
int V_226 ;
F_172 (cpu) {
const struct V_186 * V_15 = F_173 ( V_224 , V_226 ) ;
V_225 . V_85 += V_15 -> V_85 ;
V_225 . V_83 += V_15 -> V_83 ;
}
if ( F_174 ( V_23 , V_227 , V_225 . V_85 ) ||
F_174 ( V_23 , V_228 , V_225 . V_83 ) )
return - V_229 ;
return 0 ;
}
static int F_175 ( struct V_22 * V_23 ,
struct V_179 T_9 * V_224 )
{
struct V_179 V_225 = { 0 , } ;
int V_226 ;
F_172 (cpu) {
const struct V_179 * V_15 = F_173 ( V_224 , V_226 ) ;
V_225 . V_142 += V_15 -> V_142 ;
V_225 . V_139 += V_15 -> V_139 ;
V_225 . V_137 += V_15 -> V_137 ;
V_225 . V_169 += V_15 -> V_169 ;
V_225 . V_170 += V_15 -> V_170 ;
}
if ( F_174 ( V_23 , V_230 , V_225 . V_142 ) ||
F_174 ( V_23 , V_231 , V_225 . V_139 ) ||
F_174 ( V_23 , V_232 , V_225 . V_137 ) ||
F_174 ( V_23 , V_233 , V_225 . V_169 ) ||
F_174 ( V_23 , V_234 , V_225 . V_170 ) )
return - V_229 ;
return 0 ;
}
static int F_176 ( struct V_22 * V_23 ,
struct V_124 T_9 * V_224 )
{
struct V_235 V_225 = { 0 , } ;
int V_226 ;
F_172 (cpu) {
const struct V_124 * V_15 ;
struct V_235 V_105 ;
unsigned int V_236 ;
V_15 = F_173 ( V_224 , V_226 ) ;
do {
V_236 = F_177 ( & V_15 -> V_81 ) ;
memcpy ( & V_105 , & V_15 -> V_15 , sizeof( V_105 ) ) ;
} while ( F_178 ( & V_15 -> V_81 , V_236 ) );
V_225 . V_134 += V_105 . V_134 ;
V_225 . V_133 += V_105 . V_133 ;
V_225 . V_141 += V_105 . V_141 ;
V_225 . V_140 += V_105 . V_140 ;
V_225 . V_142 += V_105 . V_142 ;
V_225 . V_139 += V_105 . V_139 ;
V_225 . V_129 += V_105 . V_129 ;
V_225 . V_137 += V_105 . V_137 ;
V_225 . V_169 += V_105 . V_169 ;
V_225 . V_170 += V_105 . V_170 ;
}
if ( F_142 ( V_23 , V_237 ,
V_225 . V_134 ,
V_238 ) ||
F_142 ( V_23 , V_239 ,
V_225 . V_133 ,
V_238 ) ||
F_142 ( V_23 , V_240 ,
V_225 . V_141 ,
V_238 ) ||
F_142 ( V_23 , V_241 ,
V_225 . V_140 ,
V_238 ) ||
F_142 ( V_23 , V_242 ,
V_225 . V_142 ,
V_238 ) ||
F_142 ( V_23 , V_243 ,
V_225 . V_139 ,
V_238 ) ||
F_142 ( V_23 , V_244 ,
V_225 . V_129 ,
V_238 ) ||
F_142 ( V_23 , V_245 ,
V_225 . V_137 ,
V_238 ) ||
F_142 ( V_23 , V_246 ,
V_225 . V_169 ,
V_238 ) ||
F_142 ( V_23 , V_247 ,
V_225 . V_170 ,
V_238 ) )
return - V_229 ;
return 0 ;
}
static int F_179 ( struct V_22 * V_23 ,
struct V_79 T_9 * V_224 )
{
struct V_248 V_225 = { 0 , } ;
int V_226 ;
F_172 (cpu) {
const struct V_79 * V_15 ;
struct V_248 V_105 ;
unsigned int V_236 ;
V_15 = F_173 ( V_224 , V_226 ) ;
do {
V_236 = F_177 ( & V_15 -> V_81 ) ;
memcpy ( & V_105 , & V_15 -> V_15 , sizeof( V_105 ) ) ;
} while ( F_178 ( & V_15 -> V_81 , V_236 ) );
V_225 . V_85 += V_105 . V_85 ;
V_225 . V_83 += V_105 . V_83 ;
V_225 . V_84 += V_105 . V_84 ;
V_225 . V_82 += V_105 . V_82 ;
}
if ( F_142 ( V_23 , V_249 ,
V_225 . V_85 ,
V_250 ) ||
F_142 ( V_23 , V_251 ,
V_225 . V_83 ,
V_250 ) ||
F_142 ( V_23 , V_252 ,
V_225 . V_84 ,
V_250 ) ||
F_142 ( V_23 , V_253 ,
V_225 . V_82 ,
V_250 ) )
return - V_229 ;
return 0 ;
}
static int F_180 ( struct V_22 * V_23 ,
struct V_119 T_9 * V_224 )
{
struct V_254 V_225 = { 0 , } ;
int V_226 ;
F_172 (cpu) {
const struct V_119 * V_15 ;
struct V_254 V_105 ;
unsigned int V_236 ;
V_15 = F_173 ( V_224 , V_226 ) ;
do {
V_236 = F_177 ( & V_15 -> V_81 ) ;
memcpy ( & V_105 , & V_15 -> V_15 , sizeof( V_105 ) ) ;
} while ( F_178 ( & V_15 -> V_81 , V_236 ) );
V_225 . V_255 += V_105 . V_255 ;
V_225 . V_157 += V_105 . V_157 ;
V_225 . V_121 += V_105 . V_121 ;
V_225 . V_156 += V_105 . V_156 ;
V_225 . V_167 += V_105 . V_167 ;
V_225 . V_175 += V_105 . V_175 ;
V_225 . V_174 += V_105 . V_174 ;
V_225 . V_256 += V_105 . V_256 ;
}
if ( F_142 ( V_23 , V_257 ,
V_225 . V_255 ,
V_258 ) ||
F_142 ( V_23 , V_259 ,
V_225 . V_157 ,
V_258 ) ||
F_142 ( V_23 , V_260 ,
V_225 . V_121 ,
V_258 ) ||
F_142 ( V_23 , V_261 ,
V_225 . V_156 ,
V_258 ) ||
F_142 ( V_23 , V_262 ,
V_225 . V_167 ,
V_258 ) ||
F_142 ( V_23 , V_263 ,
V_225 . V_175 ,
V_258 ) ||
F_142 ( V_23 , V_264 ,
V_225 . V_174 ,
V_258 ) ||
F_142 ( V_23 , V_265 ,
V_225 . V_256 ,
V_258 ) )
return - V_229 ;
return 0 ;
}
static int F_181 ( struct V_25 * V_26 , struct V_22 * V_23 )
{
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_188 * V_266 = F_182 ( V_23 , V_267 ) ;
if ( ! V_266 )
return 1 ;
if ( F_141 ( V_23 , V_268 , V_26 -> V_34 ,
V_269 ) ||
F_142 ( V_23 , V_270 ,
V_271 ,
V_269 ) ||
F_183 ( V_23 , V_272 , V_26 -> V_57 ) ||
F_183 ( V_23 , V_273 , V_26 -> V_75 ) ||
F_183 ( V_23 , V_274 , V_26 -> V_74 ) ||
F_183 ( V_23 , V_275 , V_26 -> V_128 ) ||
F_183 ( V_23 , V_276 , V_26 -> V_130 ) ||
F_183 ( V_23 , V_277 , V_28 -> V_55 ) ||
F_183 ( V_23 , V_278 , V_28 -> F_25 ) ||
F_183 ( V_23 , V_279 , V_28 -> V_30 ) ||
F_183 ( V_23 , V_280 , V_28 -> V_31 ) ||
F_183 ( V_23 , V_281 , V_28 -> V_60 ) )
goto V_282;
if ( V_26 -> V_128 ) {
if ( F_174 ( V_23 , V_283 , V_26 -> V_127 ) )
goto V_282;
}
F_184 ( V_23 , V_266 ) ;
return 0 ;
V_282:
F_185 ( V_23 , V_266 ) ;
return 1 ;
}
static int F_186 ( struct V_25 * V_26 , struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_284 * V_24 )
{
struct V_13 * V_14 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_188 * V_285 , * V_286 ;
int V_180 , V_287 ;
void * V_37 ;
struct V_188 * V_288 ;
V_37 = F_187 ( V_23 , F_188 ( V_24 -> V_23 ) . V_289 , V_24 -> V_290 -> V_291 ,
& V_292 , V_293 , V_294 ) ;
if ( ! V_37 )
return - V_229 ;
F_189 ( V_24 , V_37 , & V_292 ) ;
if ( F_174 ( V_23 , V_191 , V_3 -> V_190 ) )
goto V_295;
if ( F_181 ( V_26 , V_23 ) )
goto V_295;
V_288 = F_182 ( V_23 , V_296 ) ;
if ( ! V_288 )
goto V_295;
if ( F_179 ( V_23 , V_28 -> V_15 ) ) {
F_185 ( V_23 , V_288 ) ;
goto V_295;
}
F_184 ( V_23 , V_288 ) ;
V_288 = F_182 ( V_23 , V_297 ) ;
if ( ! V_288 )
goto V_295;
if ( F_180 ( V_23 , F_1 ( V_3 ) -> V_15 ) ) {
F_185 ( V_23 , V_288 ) ;
goto V_295;
}
F_184 ( V_23 , V_288 ) ;
V_285 = F_182 ( V_23 , V_298 ) ;
if ( ! V_285 )
goto V_295;
for ( V_180 = 0 , V_287 = 1 ; V_180 < V_181 ; V_180 ++ ) {
struct V_20 * V_71 = F_6 ( V_28 -> V_8 [ V_180 ] ) ;
struct V_188 * V_299 ;
if ( ! V_71 )
continue;
V_299 = F_182 ( V_23 , V_287 ++ ) ;
if ( ! V_299 ) {
F_185 ( V_23 , V_285 ) ;
goto V_295;
}
if ( F_183 ( V_23 , V_203 , V_180 ) ||
F_174 ( V_23 , V_214 , V_71 -> V_73 ) ||
F_190 ( V_23 , V_213 , V_216 , V_71 -> V_18 . V_220 ) ||
F_183 ( V_23 , V_215 , V_71 -> V_9 ) ) {
F_185 ( V_23 , V_299 ) ;
F_185 ( V_23 , V_285 ) ;
goto V_295;
}
V_288 = F_182 ( V_23 , V_300 ) ;
if ( ! V_288 ) {
F_185 ( V_23 , V_299 ) ;
F_185 ( V_23 , V_285 ) ;
goto V_295;
}
if ( F_171 ( V_23 , V_71 -> V_15 ) ) {
F_185 ( V_23 , V_288 ) ;
F_185 ( V_23 , V_299 ) ;
F_185 ( V_23 , V_285 ) ;
goto V_295;
}
F_184 ( V_23 , V_288 ) ;
F_184 ( V_23 , V_299 ) ;
}
F_184 ( V_23 , V_285 ) ;
V_286 = F_182 ( V_23 , V_301 ) ;
if ( ! V_286 )
goto V_295;
V_287 = 1 ;
F_105 (secy, rx_sc) {
int V_302 ;
struct V_188 * V_303 ;
struct V_188 * V_304 = F_182 ( V_23 , V_287 ++ ) ;
if ( ! V_304 ) {
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_183 ( V_23 , V_221 , V_14 -> V_9 ) ||
F_141 ( V_23 , V_205 , V_14 -> V_34 ,
V_305 ) ) {
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
V_288 = F_182 ( V_23 , V_306 ) ;
if ( ! V_288 ) {
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_176 ( V_23 , V_14 -> V_15 ) ) {
F_185 ( V_23 , V_288 ) ;
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
F_184 ( V_23 , V_288 ) ;
V_303 = F_182 ( V_23 , V_307 ) ;
if ( ! V_303 ) {
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
for ( V_180 = 0 , V_302 = 1 ; V_180 < V_181 ; V_180 ++ ) {
struct V_6 * V_123 = F_6 ( V_14 -> V_8 [ V_180 ] ) ;
struct V_188 * V_308 ;
if ( ! V_123 )
continue;
V_308 = F_182 ( V_23 , V_302 ++ ) ;
if ( ! V_308 ) {
F_185 ( V_23 , V_303 ) ;
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
V_288 = F_182 ( V_23 , V_300 ) ;
if ( ! V_288 ) {
F_185 ( V_23 , V_303 ) ;
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_175 ( V_23 , V_123 -> V_15 ) ) {
F_185 ( V_23 , V_288 ) ;
F_185 ( V_23 , V_303 ) ;
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
F_184 ( V_23 , V_288 ) ;
if ( F_183 ( V_23 , V_203 , V_180 ) ||
F_174 ( V_23 , V_214 , V_123 -> V_73 ) ||
F_190 ( V_23 , V_213 , V_216 , V_123 -> V_18 . V_220 ) ||
F_183 ( V_23 , V_215 , V_123 -> V_9 ) ) {
F_185 ( V_23 , V_308 ) ;
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_286 ) ;
goto V_295;
}
F_184 ( V_23 , V_308 ) ;
}
F_184 ( V_23 , V_303 ) ;
F_184 ( V_23 , V_304 ) ;
}
F_184 ( V_23 , V_286 ) ;
F_191 ( V_23 , V_37 ) ;
return 0 ;
V_295:
F_192 ( V_23 , V_37 ) ;
return - V_229 ;
}
static int F_193 ( struct V_22 * V_23 , struct V_284 * V_24 )
{
struct V_187 * V_187 = F_194 ( V_23 -> V_309 ) ;
struct V_2 * V_3 ;
int V_310 , V_311 ;
V_310 = V_24 -> args [ 0 ] ;
V_311 = 0 ;
F_154 () ;
V_24 -> V_312 = V_313 ;
F_195 (net, dev) {
struct V_25 * V_26 ;
if ( V_311 < V_310 )
goto V_183;
if ( ! F_138 ( V_3 ) )
goto V_183;
V_26 = & F_1 ( V_3 ) -> V_26 ;
if ( F_186 ( V_26 , V_3 , V_23 , V_24 ) < 0 )
goto V_314;
V_183:
V_311 ++ ;
}
V_314:
F_156 () ;
V_24 -> args [ 0 ] = V_311 ;
return V_23 -> V_65 ;
}
static T_10 F_196 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_2 ( V_3 ) ;
struct V_25 * V_26 = & V_76 -> V_26 ;
struct V_119 * V_120 ;
int V_86 , V_65 ;
if ( ! V_26 -> V_74 ) {
V_120 = F_47 ( V_76 -> V_15 ) ;
F_48 ( & V_120 -> V_81 ) ;
V_120 -> V_15 . V_255 ++ ;
F_50 ( & V_120 -> V_81 ) ;
V_23 -> V_3 = V_76 -> V_77 ;
V_65 = V_23 -> V_65 ;
V_86 = F_56 ( V_23 ) ;
F_51 ( V_3 , V_86 , V_65 ) ;
return V_86 ;
}
if ( ! V_26 -> V_75 ) {
F_66 ( V_23 ) ;
V_3 -> V_15 . V_93 ++ ;
return V_315 ;
}
V_23 = F_65 ( V_23 , V_3 ) ;
if ( F_114 ( V_23 ) ) {
if ( F_115 ( V_23 ) != - V_122 )
V_3 -> V_15 . V_93 ++ ;
return V_315 ;
}
F_46 ( V_23 , & V_76 -> V_26 . V_28 , F_23 ( V_23 ) -> V_71 ) ;
F_43 ( V_23 , V_3 ) ;
V_65 = V_23 -> V_65 ;
V_86 = F_56 ( V_23 ) ;
F_51 ( V_3 , V_86 , V_65 ) ;
return V_86 ;
}
static int F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
int V_96 ;
V_3 -> V_90 = F_132 ( struct V_89 ) ;
if ( ! V_3 -> V_90 )
return - V_116 ;
V_96 = F_198 ( & V_76 -> V_151 , V_3 ) ;
if ( V_96 ) {
F_11 ( V_3 -> V_90 ) ;
return V_96 ;
}
V_3 -> V_316 = V_77 -> V_316 & V_317 ;
V_3 -> V_316 |= V_318 | V_319 ;
V_3 -> V_320 = V_77 -> V_320 +
V_113 ;
V_3 -> V_321 = V_77 -> V_321 +
V_114 ;
if ( F_199 ( V_3 -> V_322 ) )
F_200 ( V_3 , V_77 ) ;
if ( F_199 ( V_3 -> V_323 ) )
memcpy ( V_3 -> V_323 , V_77 -> V_323 , V_3 -> V_324 ) ;
return 0 ;
}
static void F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
F_202 ( & V_76 -> V_151 ) ;
F_11 ( V_3 -> V_90 ) ;
}
static T_11 F_203 ( struct V_2 * V_3 ,
T_11 V_316 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
V_316 &= ( V_77 -> V_316 & V_317 ) |
V_319 | V_325 ;
V_316 |= V_318 ;
return V_316 ;
}
static int F_204 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
int V_96 ;
if ( ! ( V_77 -> V_326 & V_327 ) )
return - V_328 ;
V_96 = F_205 ( V_77 , V_3 -> V_322 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_3 -> V_326 & V_329 ) {
V_96 = F_206 ( V_77 , 1 ) ;
if ( V_96 < 0 )
goto V_330;
}
if ( V_3 -> V_326 & V_331 ) {
V_96 = F_207 ( V_77 , 1 ) ;
if ( V_96 < 0 )
goto V_332;
}
if ( F_208 ( V_77 ) )
F_209 ( V_3 ) ;
return 0 ;
V_332:
if ( V_3 -> V_326 & V_329 )
F_206 ( V_77 , - 1 ) ;
V_330:
F_210 ( V_77 , V_3 -> V_322 ) ;
F_211 ( V_3 ) ;
return V_96 ;
}
static int F_212 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_211 ( V_3 ) ;
F_213 ( V_77 , V_3 ) ;
F_214 ( V_77 , V_3 ) ;
if ( V_3 -> V_326 & V_329 )
F_206 ( V_77 , - 1 ) ;
if ( V_3 -> V_326 & V_331 )
F_207 ( V_77 , - 1 ) ;
F_210 ( V_77 , V_3 -> V_322 ) ;
return 0 ;
}
static void F_215 ( struct V_2 * V_3 , int V_333 )
{
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
if ( ! ( V_3 -> V_326 & V_327 ) )
return;
if ( V_333 & V_329 )
F_206 ( V_77 , V_3 -> V_326 & V_329 ? 1 : - 1 ) ;
if ( V_333 & V_331 )
F_207 ( V_77 ,
V_3 -> V_326 & V_331 ? 1 : - 1 ) ;
}
static void F_216 ( struct V_2 * V_3 )
{
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
F_217 ( V_77 , V_3 ) ;
F_218 ( V_77 , V_3 ) ;
}
static int F_219 ( struct V_2 * V_3 , void * V_334 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
struct V_335 * V_32 = V_334 ;
int V_96 ;
if ( ! F_220 ( V_32 -> V_336 ) )
return - V_337 ;
if ( ! ( V_3 -> V_326 & V_327 ) )
goto V_148;
V_96 = F_205 ( V_77 , V_32 -> V_336 ) ;
if ( V_96 < 0 )
return V_96 ;
F_210 ( V_77 , V_3 -> V_322 ) ;
V_148:
F_221 ( V_3 -> V_322 , V_32 -> V_336 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_3 , int V_338 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
unsigned int V_339 = V_76 -> V_26 . V_57 + F_30 ( true ) ;
if ( V_76 -> V_77 -> V_118 - V_339 < V_338 )
return - V_340 ;
V_3 -> V_118 = V_338 ;
return 0 ;
}
static struct V_341 * F_223 ( struct V_2 * V_3 ,
struct V_341 * V_342 )
{
int V_226 ;
if ( ! V_3 -> V_90 )
return V_342 ;
F_172 (cpu) {
struct V_89 * V_15 ;
struct V_89 V_105 ;
int V_236 ;
V_15 = F_173 ( V_3 -> V_90 , V_226 ) ;
do {
V_236 = F_177 ( & V_15 -> V_81 ) ;
V_105 . V_146 = V_15 -> V_146 ;
V_105 . V_147 = V_15 -> V_147 ;
V_105 . V_91 = V_15 -> V_91 ;
V_105 . V_92 = V_15 -> V_92 ;
} while ( F_178 ( & V_15 -> V_81 , V_236 ) );
V_342 -> V_146 += V_105 . V_146 ;
V_342 -> V_147 += V_105 . V_147 ;
V_342 -> V_91 += V_105 . V_91 ;
V_342 -> V_92 += V_105 . V_92 ;
}
V_342 -> V_153 = V_3 -> V_15 . V_153 ;
V_342 -> V_93 = V_3 -> V_15 . V_93 ;
return V_342 ;
}
static int F_224 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_77 -> V_190 ;
}
static int F_225 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_343 ;
}
static void F_226 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_11 ( V_76 -> V_15 ) ;
F_11 ( V_76 -> V_26 . V_28 . V_15 ) ;
F_58 ( V_77 ) ;
F_227 ( V_3 ) ;
}
static void F_228 ( struct V_2 * V_3 )
{
F_229 ( V_3 ) ;
V_3 -> V_344 |= V_345 ;
V_3 -> V_346 = & V_347 ;
V_3 -> V_348 = F_226 ;
F_230 ( V_3 , & V_349 ) ;
F_231 ( V_3 -> V_323 ) ;
}
static void F_232 ( struct V_2 * V_3 ,
struct V_188 * V_64 [] )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
if ( V_64 [ V_350 ] ) {
struct V_20 * V_71 ;
V_28 -> V_60 = F_144 ( V_64 [ V_350 ] ) ;
V_71 = F_6 ( V_28 -> V_8 [ V_28 -> V_60 ] ) ;
V_26 -> V_75 = V_71 && V_71 -> V_9 ;
}
if ( V_64 [ V_351 ] )
V_26 -> V_127 = F_136 ( V_64 [ V_351 ] ) ;
if ( V_64 [ V_352 ] )
V_28 -> V_55 = ! ! F_144 ( V_64 [ V_352 ] ) ;
if ( V_64 [ V_353 ] )
V_26 -> V_74 = ! ! F_144 ( V_64 [ V_353 ] ) ;
if ( V_64 [ V_354 ] )
V_28 -> F_25 = ! ! F_144 ( V_64 [ V_354 ] ) ;
if ( V_64 [ V_355 ] )
V_28 -> V_30 = ! ! F_144 ( V_64 [ V_355 ] ) ;
if ( V_64 [ V_356 ] )
V_28 -> V_31 = ! ! F_144 ( V_64 [ V_356 ] ) ;
if ( V_64 [ V_357 ] )
V_26 -> V_128 = ! ! F_144 ( V_64 [ V_357 ] ) ;
if ( V_64 [ V_358 ] )
V_26 -> V_130 = F_144 ( V_64 [ V_358 ] ) ;
}
static int F_233 ( struct V_2 * V_3 , struct V_188 * V_359 [] ,
struct V_188 * V_64 [] )
{
if ( ! V_64 )
return 0 ;
if ( V_64 [ V_360 ] ||
V_64 [ V_361 ] ||
V_64 [ V_362 ] ||
V_64 [ V_363 ] )
return - V_112 ;
F_232 ( V_3 , V_64 ) ;
return 0 ;
}
static void F_234 ( struct V_1 * V_76 )
{
int V_180 ;
while ( V_76 -> V_26 . V_14 ) {
struct V_13 * V_14 = F_6 ( V_76 -> V_26 . V_14 ) ;
F_128 ( V_76 -> V_26 . V_14 , V_14 -> V_183 ) ;
F_125 ( V_14 ) ;
}
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
struct V_20 * V_8 = F_6 ( V_76 -> V_26 . V_28 . V_8 [ V_180 ] ) ;
if ( V_8 ) {
F_126 ( V_76 -> V_26 . V_28 . V_8 [ V_180 ] , NULL ) ;
F_134 ( V_8 ) ;
}
}
}
static void F_235 ( struct V_2 * V_3 , struct V_364 * V_12 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_236 ( V_3 , V_12 ) ;
F_237 ( & V_76 -> V_365 ) ;
F_234 ( V_76 ) ;
F_238 ( V_77 , V_3 ) ;
V_313 ++ ;
}
static void F_239 ( struct V_2 * V_3 , struct V_364 * V_12 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
struct V_4 * V_155 = F_5 ( V_77 ) ;
F_235 ( V_3 , V_12 ) ;
if ( F_240 ( & V_155 -> V_365 ) ) {
F_241 ( V_77 ) ;
F_12 ( V_155 ) ;
}
}
static int F_242 ( struct V_2 * V_77 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_4 * V_155 = F_5 ( V_77 ) ;
if ( ! V_155 ) {
int V_96 ;
V_155 = F_63 ( sizeof( * V_155 ) , V_185 ) ;
if ( ! V_155 )
return - V_116 ;
F_243 ( & V_155 -> V_365 ) ;
V_96 = F_244 ( V_77 , F_112 ,
V_155 ) ;
if ( V_96 < 0 ) {
F_12 ( V_155 ) ;
return V_96 ;
}
}
F_245 ( & V_76 -> V_365 , & V_155 -> V_365 ) ;
return 0 ;
}
static bool F_246 ( struct V_2 * V_3 , T_2 V_34 )
{
struct V_4 * V_155 = F_5 ( V_3 ) ;
struct V_1 * V_76 ;
F_130 (macsec, &rxd->secys, secys) {
if ( V_76 -> V_26 . V_34 == V_34 )
return true ;
}
return false ;
}
static T_2 F_247 ( struct V_2 * V_3 , T_4 V_33 )
{
return F_26 ( V_3 -> V_322 , V_33 ) ;
}
static int F_248 ( struct V_2 * V_3 , T_2 V_34 , T_3 V_57 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_25 * V_26 = & V_76 -> V_26 ;
V_76 -> V_15 = F_132 ( struct V_119 ) ;
if ( ! V_76 -> V_15 )
return - V_116 ;
V_26 -> V_28 . V_15 = F_132 ( struct V_79 ) ;
if ( ! V_26 -> V_28 . V_15 ) {
F_11 ( V_76 -> V_15 ) ;
return - V_116 ;
}
if ( V_34 == V_222 )
V_34 = F_247 ( V_3 , V_42 ) ;
V_26 -> V_150 = V_3 ;
V_26 -> V_75 = true ;
V_26 -> V_176 = V_366 ;
V_26 -> V_57 = V_57 ;
V_26 -> V_130 = V_367 ;
V_26 -> V_74 = true ;
V_26 -> V_128 = false ;
V_26 -> V_34 = V_34 ;
V_26 -> V_28 . V_9 = true ;
V_26 -> V_28 . V_60 = V_368 ;
V_26 -> V_28 . V_55 = V_369 ;
V_26 -> V_28 . F_25 = V_370 ;
V_26 -> V_28 . V_30 = false ;
V_26 -> V_28 . V_31 = false ;
return 0 ;
}
static int F_249 ( struct V_187 * V_187 , struct V_2 * V_3 ,
struct V_188 * V_359 [] , struct V_188 * V_64 [] )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 ;
int V_96 ;
T_2 V_34 ;
T_3 V_57 = V_58 ;
T_12 * V_371 ;
if ( ! V_359 [ V_372 ] )
return - V_112 ;
V_77 = F_137 ( V_187 , F_136 ( V_359 [ V_372 ] ) ) ;
if ( ! V_77 )
return - V_192 ;
V_3 -> V_344 |= V_373 ;
V_76 -> V_77 = V_77 ;
if ( V_64 && V_64 [ V_361 ] )
V_57 = F_144 ( V_64 [ V_361 ] ) ;
V_3 -> V_118 = V_77 -> V_118 - V_57 - F_30 ( true ) ;
V_371 = F_6 ( V_77 -> V_371 ) ;
if ( V_371 && V_371 != F_112 )
return - V_219 ;
V_96 = F_250 ( V_3 ) ;
if ( V_96 < 0 )
return V_96 ;
F_81 ( V_77 ) ;
V_76 -> V_343 = F_251 ( V_77 ) + 1 ;
F_252 ( V_3 ) ;
F_253 ( & V_3 -> V_374 ,
& V_375 ,
F_225 ( V_3 ) ) ;
V_96 = F_254 ( V_77 , V_3 ) ;
if ( V_96 < 0 )
goto V_376;
if ( V_64 && V_64 [ V_362 ] )
V_34 = F_139 ( V_64 [ V_362 ] ) ;
else if ( V_64 && V_64 [ V_363 ] )
V_34 = F_247 ( V_3 , F_255 ( V_64 [ V_363 ] ) ) ;
else
V_34 = F_247 ( V_3 , V_42 ) ;
if ( V_371 && F_246 ( V_77 , V_34 ) ) {
V_96 = - V_219 ;
goto V_377;
}
V_96 = F_248 ( V_3 , V_34 , V_57 ) ;
if ( V_96 )
goto V_377;
if ( V_64 )
F_232 ( V_3 , V_64 ) ;
V_96 = F_242 ( V_77 , V_3 ) ;
if ( V_96 < 0 )
goto V_378;
V_313 ++ ;
return 0 ;
V_378:
F_234 ( V_76 ) ;
V_377:
F_238 ( V_77 , V_3 ) ;
V_376:
F_256 ( V_3 ) ;
return V_96 ;
}
static int F_257 ( struct V_188 * V_359 [] , struct V_188 * V_64 [] )
{
V_198 V_379 = V_271 ;
T_3 V_57 = V_58 ;
int V_380 ;
bool V_381 , V_31 , V_34 ;
if ( ! V_64 )
return 0 ;
if ( V_64 [ V_360 ] )
V_379 = F_140 ( V_64 [ V_360 ] ) ;
if ( V_64 [ V_361 ] ) {
V_57 = F_144 ( V_64 [ V_361 ] ) ;
if ( V_57 != V_58 ) {
char V_382 [ V_366 ] = { 0 } ;
struct V_99 * V_383 ;
V_383 = F_116 ( V_382 ,
V_366 ,
V_57 ) ;
if ( F_114 ( V_383 ) )
return F_115 ( V_383 ) ;
F_18 ( V_383 ) ;
}
}
switch ( V_379 ) {
case V_271 :
case V_384 :
if ( V_57 < V_385 ||
V_57 > V_386 )
return - V_112 ;
break;
default:
return - V_112 ;
}
if ( V_64 [ V_350 ] ) {
if ( F_144 ( V_64 [ V_350 ] ) >= V_181 )
return - V_112 ;
}
for ( V_380 = V_350 + 1 ;
V_380 < V_358 ;
V_380 ++ ) {
if ( V_64 [ V_380 ] ) {
if ( F_144 ( V_64 [ V_380 ] ) > 1 )
return - V_112 ;
}
}
V_381 = V_64 [ V_355 ] ? F_144 ( V_64 [ V_355 ] ) : false ;
V_34 = V_64 [ V_354 ] ? F_144 ( V_64 [ V_354 ] ) : false ;
V_31 = V_64 [ V_356 ] ? F_144 ( V_64 [ V_356 ] ) : false ;
if ( ( V_34 && ( V_31 || V_381 ) ) || ( V_31 && V_381 ) )
return - V_112 ;
if ( V_64 [ V_358 ] &&
F_144 ( V_64 [ V_358 ] ) > V_387 )
return - V_112 ;
if ( ( V_64 [ V_357 ] &&
F_144 ( V_64 [ V_357 ] ) ) &&
! V_64 [ V_351 ] )
return - V_112 ;
return 0 ;
}
static struct V_187 * F_258 ( const struct V_2 * V_3 )
{
return F_259 ( F_1 ( V_3 ) -> V_77 ) ;
}
static T_6 F_260 ( const struct V_2 * V_3 )
{
return 0 +
F_261 ( 8 ) +
F_262 ( 1 ) +
F_261 ( 8 ) +
F_262 ( 4 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
F_262 ( 1 ) +
0 ;
}
static int F_263 ( struct V_22 * V_23 ,
const struct V_2 * V_3 )
{
struct V_25 * V_26 = & F_1 ( V_3 ) -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
if ( F_141 ( V_23 , V_362 , V_26 -> V_34 ,
V_388 ) ||
F_183 ( V_23 , V_361 , V_26 -> V_57 ) ||
F_142 ( V_23 , V_360 ,
V_271 , V_388 ) ||
F_183 ( V_23 , V_350 , V_28 -> V_60 ) ||
F_183 ( V_23 , V_352 , V_28 -> V_55 ) ||
F_183 ( V_23 , V_353 , V_26 -> V_74 ) ||
F_183 ( V_23 , V_354 , V_28 -> F_25 ) ||
F_183 ( V_23 , V_355 , V_28 -> V_30 ) ||
F_183 ( V_23 , V_356 , V_28 -> V_31 ) ||
F_183 ( V_23 , V_357 , V_26 -> V_128 ) ||
F_183 ( V_23 , V_358 , V_26 -> V_130 ) ||
0 )
goto V_295;
if ( V_26 -> V_128 ) {
if ( F_174 ( V_23 , V_351 , V_26 -> V_127 ) )
goto V_295;
}
return 0 ;
V_295:
return - V_229 ;
}
static bool F_264 ( struct V_2 * V_3 )
{
return F_265 ( V_3 -> V_371 ) == F_112 ;
}
static int F_266 ( struct V_389 * V_390 , unsigned long V_391 ,
void * V_7 )
{
struct V_2 * V_77 = F_267 ( V_7 ) ;
F_268 ( V_12 ) ;
if ( ! F_264 ( V_77 ) )
return V_392 ;
switch ( V_391 ) {
case V_393 : {
struct V_1 * V_394 , * V_395 ;
struct V_4 * V_155 ;
V_155 = F_5 ( V_77 ) ;
F_269 (m, n, &rxd->secys, secys) {
F_235 ( V_394 -> V_26 . V_150 , & V_12 ) ;
}
F_241 ( V_77 ) ;
F_12 ( V_155 ) ;
F_270 ( & V_12 ) ;
break;
}
case V_396 : {
struct V_1 * V_394 ;
struct V_4 * V_155 ;
V_155 = F_5 ( V_77 ) ;
F_130 (m, &rxd->secys, secys) {
struct V_2 * V_3 = V_394 -> V_26 . V_150 ;
unsigned int V_118 = V_77 -> V_118 - ( V_394 -> V_26 . V_57 +
F_30 ( true ) ) ;
if ( V_3 -> V_118 > V_118 )
F_271 ( V_3 , V_118 ) ;
}
}
}
return V_397 ;
}
static int T_13 F_272 ( void )
{
int V_96 ;
F_273 ( L_5 ) ;
V_96 = F_274 ( & V_398 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_275 ( & V_399 ) ;
if ( V_96 )
goto V_400;
V_96 = F_276 ( & V_292 , V_401 ) ;
if ( V_96 )
goto V_402;
return 0 ;
V_402:
F_277 ( & V_399 ) ;
V_400:
F_278 ( & V_398 ) ;
return V_96 ;
}
static void T_14 F_279 ( void )
{
F_280 ( & V_292 ) ;
F_277 ( & V_399 ) ;
F_278 ( & V_398 ) ;
F_281 () ;
}
