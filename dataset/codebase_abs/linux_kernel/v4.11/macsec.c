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
struct V_100 * * V_101 ,
int V_102 )
{
T_6 V_103 , V_104 , V_105 ;
struct V_98 * V_97 ;
void * V_106 ;
V_103 = sizeof( struct V_98 ) + F_60 ( V_19 ) ;
V_104 = V_103 ;
V_103 += V_107 ;
V_103 = F_61 ( V_103 , F_62 ( struct V_100 ) ) ;
V_105 = V_103 ;
V_103 += sizeof( struct V_100 ) * V_102 ;
V_106 = F_63 ( V_103 , V_108 ) ;
if ( ! V_106 )
return NULL ;
* V_69 = ( unsigned char * ) ( V_106 + V_104 ) ;
* V_101 = (struct V_100 * ) ( V_106 + V_105 ) ;
V_97 = V_106 ;
F_64 ( V_97 , V_19 ) ;
return V_97 ;
}
static struct V_22 * F_65 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
int V_86 ;
struct V_100 * V_101 ;
struct V_22 * V_109 ;
unsigned char * V_69 ;
struct V_110 * V_40 ;
struct V_36 * V_111 ;
T_6 V_112 ;
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
return F_67 ( - V_113 ) ;
}
if ( F_68 ( F_69 ( V_23 ) < V_114 ||
F_70 ( V_23 ) < V_115 ) ) {
struct V_22 * V_116 = F_71 ( V_23 ,
V_114 ,
V_115 ,
V_108 ) ;
if ( F_52 ( V_116 ) ) {
F_72 ( V_23 ) ;
V_23 = V_116 ;
} else {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_117 ) ;
}
} else {
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
F_22 ( V_71 ) ;
return F_67 ( - V_117 ) ;
}
}
V_112 = V_23 -> V_65 ;
V_40 = F_45 ( V_23 ) ;
V_38 = F_25 ( V_26 ) ;
V_111 = (struct V_36 * ) F_74 ( V_23 , F_30 ( V_38 ) ) ;
memmove ( V_111 , V_40 , 2 * V_35 ) ;
V_47 = F_39 ( V_71 , V_26 ) ;
if ( V_47 == 0 ) {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_118 ) ;
}
F_31 ( V_111 , V_26 , V_47 , V_38 ) ;
F_34 ( V_111 , V_112 - 2 * V_35 ) ;
F_75 ( V_23 , V_26 -> V_57 ) ;
if ( V_23 -> V_65 - V_45 > F_1 ( V_3 ) -> V_77 -> V_119 ) {
struct V_120 * V_121 = F_47 ( V_76 -> V_15 ) ;
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_122 ++ ;
F_50 ( & V_121 -> V_81 ) ;
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_113 ) ;
}
V_86 = F_76 ( V_23 , 0 , & V_109 ) ;
if ( F_68 ( V_86 < 0 ) ) {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( V_86 ) ;
}
V_97 = F_59 ( V_71 -> V_18 . V_19 , & V_69 , & V_101 , V_86 ) ;
if ( ! V_97 ) {
F_22 ( V_71 ) ;
F_66 ( V_23 ) ;
return F_67 ( - V_117 ) ;
}
F_36 ( V_69 , V_26 -> V_34 , V_47 ) ;
F_77 ( V_101 , V_86 ) ;
F_78 ( V_23 , V_101 , 0 , V_23 -> V_65 ) ;
if ( V_28 -> V_55 ) {
int V_65 = V_23 -> V_65 - F_29 ( V_38 ) -
V_26 -> V_57 ;
F_79 ( V_97 , V_101 , V_101 , V_65 , V_69 ) ;
F_80 ( V_97 , F_29 ( V_38 ) ) ;
} else {
F_79 ( V_97 , V_101 , V_101 , 0 , V_69 ) ;
F_80 ( V_97 , V_23 -> V_65 - V_26 -> V_57 ) ;
}
F_23 ( V_23 ) -> V_97 = V_97 ;
F_23 ( V_23 ) -> V_71 = V_71 ;
F_81 ( V_97 , 0 , F_53 , V_23 ) ;
F_82 ( V_23 -> V_3 ) ;
V_86 = F_83 ( V_97 ) ;
if ( V_86 == - V_123 ) {
return F_67 ( V_86 ) ;
} else if ( V_86 != 0 ) {
F_58 ( V_23 -> V_3 ) ;
F_66 ( V_23 ) ;
F_54 ( V_97 ) ;
F_22 ( V_71 ) ;
return F_67 ( - V_113 ) ;
}
F_58 ( V_23 -> V_3 ) ;
F_54 ( V_97 ) ;
F_22 ( V_71 ) ;
return V_23 ;
}
static bool F_84 ( struct V_22 * V_23 , struct V_25 * V_26 , T_5 V_47 )
{
struct V_6 * V_124 = F_23 ( V_23 ) -> V_124 ;
struct V_125 * V_126 = F_47 ( V_124 -> V_16 -> V_15 ) ;
struct V_36 * V_37 = F_37 ( V_23 ) ;
T_5 V_127 = 0 ;
F_85 ( & V_124 -> V_72 ) ;
if ( V_124 -> V_73 >= V_26 -> V_128 )
V_127 = V_124 -> V_73 - V_26 -> V_128 ;
if ( V_26 -> V_129 && V_47 < V_127 ) {
F_86 ( & V_124 -> V_72 ) ;
F_48 ( & V_126 -> V_81 ) ;
V_126 -> V_15 . V_130 ++ ;
F_50 ( & V_126 -> V_81 ) ;
return false ;
}
if ( V_26 -> V_131 != V_132 ) {
F_48 ( & V_126 -> V_81 ) ;
if ( V_37 -> V_48 & V_133 )
V_126 -> V_15 . V_134 += V_23 -> V_65 ;
else
V_126 -> V_15 . V_135 += V_23 -> V_65 ;
F_50 ( & V_126 -> V_81 ) ;
}
if ( ! F_23 ( V_23 ) -> V_136 ) {
F_86 ( & V_124 -> V_72 ) ;
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_131 == V_137 ) {
F_48 ( & V_126 -> V_81 ) ;
V_126 -> V_15 . V_138 ++ ;
F_50 ( & V_126 -> V_81 ) ;
return false ;
}
F_48 ( & V_126 -> V_81 ) ;
if ( V_26 -> V_131 == V_139 ) {
V_126 -> V_15 . V_140 ++ ;
F_49 ( V_124 -> V_15 -> V_140 ) ;
} else if ( V_47 < V_127 ) {
V_126 -> V_15 . V_141 ++ ;
} else {
V_126 -> V_15 . V_142 ++ ;
}
F_50 ( & V_126 -> V_81 ) ;
} else {
F_48 ( & V_126 -> V_81 ) ;
if ( V_47 < V_127 ) {
V_126 -> V_15 . V_141 ++ ;
} else {
V_126 -> V_15 . V_143 ++ ;
F_49 ( V_124 -> V_15 -> V_143 ) ;
}
F_50 ( & V_126 -> V_81 ) ;
if ( V_47 >= V_124 -> V_73 )
V_124 -> V_73 = V_47 + 1 ;
F_86 ( & V_124 -> V_72 ) ;
}
return true ;
}
static void F_87 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
V_23 -> V_144 = V_145 ;
V_23 -> V_78 = F_88 ( V_23 , V_3 ) ;
F_89 ( V_23 ) ;
if ( ! F_90 ( V_23 ) )
F_91 ( V_23 ) ;
F_92 ( V_23 ) ;
}
static void F_93 ( struct V_22 * V_23 , T_3 V_57 , T_3 V_146 )
{
memmove ( V_23 -> V_64 + V_146 , V_23 -> V_64 , 2 * V_35 ) ;
F_94 ( V_23 , V_146 ) ;
F_95 ( V_23 , V_23 -> V_65 - V_57 ) ;
}
static void F_96 ( struct V_2 * V_3 , int V_65 )
{
struct V_89 * V_15 = F_47 ( V_3 -> V_90 ) ;
F_48 ( & V_15 -> V_81 ) ;
V_15 -> V_147 ++ ;
V_15 -> V_148 += V_65 ;
F_50 ( & V_15 -> V_81 ) ;
}
static void F_97 ( struct V_94 * V_95 , int V_96 )
{
struct V_22 * V_23 = V_95 -> V_64 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_6 * V_124 = F_23 ( V_23 ) -> V_124 ;
struct V_13 * V_14 = V_124 -> V_16 ;
int V_65 , V_86 ;
T_5 V_47 ;
F_54 ( F_23 ( V_23 ) -> V_97 ) ;
if ( ! V_96 )
F_23 ( V_23 ) -> V_136 = true ;
F_55 () ;
V_47 = F_98 ( F_37 ( V_23 ) -> V_54 ) ;
if ( ! F_84 ( V_23 , & V_76 -> V_26 , V_47 ) ) {
F_57 () ;
F_66 ( V_23 ) ;
goto V_149;
}
F_93 ( V_23 , V_76 -> V_26 . V_57 ,
F_30 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_87 ( V_23 , V_76 -> V_26 . V_151 ) ;
V_65 = V_23 -> V_65 ;
V_86 = F_99 ( & V_76 -> V_152 , V_23 ) ;
if ( V_86 == V_153 )
F_96 ( V_3 , V_65 ) ;
else
V_76 -> V_26 . V_151 -> V_15 . V_154 ++ ;
F_57 () ;
V_149:
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
F_58 ( V_3 ) ;
}
static struct V_22 * F_100 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
struct V_6 * V_124 ,
T_2 V_34 ,
struct V_25 * V_26 )
{
int V_86 ;
struct V_100 * V_101 ;
struct V_22 * V_109 ;
unsigned char * V_69 ;
struct V_98 * V_97 ;
struct V_36 * V_37 ;
T_7 V_57 = V_26 -> V_57 ;
F_23 ( V_23 ) -> V_136 = false ;
V_23 = F_101 ( V_23 , V_108 ) ;
if ( ! V_23 )
return F_67 ( - V_117 ) ;
V_86 = F_76 ( V_23 , 0 , & V_109 ) ;
if ( F_68 ( V_86 < 0 ) ) {
F_66 ( V_23 ) ;
return F_67 ( V_86 ) ;
}
V_97 = F_59 ( V_124 -> V_18 . V_19 , & V_69 , & V_101 , V_86 ) ;
if ( ! V_97 ) {
F_66 ( V_23 ) ;
return F_67 ( - V_117 ) ;
}
V_37 = (struct V_36 * ) V_23 -> V_64 ;
F_36 ( V_69 , V_34 , F_98 ( V_37 -> V_54 ) ) ;
F_77 ( V_101 , V_86 ) ;
F_78 ( V_23 , V_101 , 0 , V_23 -> V_65 ) ;
if ( V_37 -> V_48 & V_133 ) {
int V_65 = V_23 -> V_65 - F_29 ( F_23 ( V_23 ) -> V_150 ) ;
F_79 ( V_97 , V_101 , V_101 , V_65 , V_69 ) ;
F_80 ( V_97 , F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
F_54 ( V_97 ) ;
return F_67 ( - V_117 ) ;
}
} else {
F_79 ( V_97 , V_101 , V_101 , V_57 , V_69 ) ;
F_80 ( V_97 , V_23 -> V_65 - V_57 ) ;
}
F_23 ( V_23 ) -> V_97 = V_97 ;
V_23 -> V_3 = V_3 ;
F_81 ( V_97 , 0 , F_97 , V_23 ) ;
F_82 ( V_3 ) ;
V_86 = F_102 ( V_97 ) ;
if ( V_86 == - V_123 ) {
return F_67 ( V_86 ) ;
} else if ( V_86 != 0 ) {
if ( V_86 != - V_155 ) {
F_66 ( V_23 ) ;
V_23 = F_67 ( V_86 ) ;
}
} else {
F_23 ( V_23 ) -> V_136 = true ;
}
F_58 ( V_3 ) ;
F_54 ( V_97 ) ;
return V_23 ;
}
static struct V_13 * F_103 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 ;
F_104 (secy, rx_sc) {
if ( V_14 -> V_34 == V_34 )
return V_14 ;
}
return NULL ;
}
static struct V_13 * F_105 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 ;
F_106 (secy, rx_sc) {
if ( V_14 -> V_34 == V_34 )
return V_14 ;
}
return NULL ;
}
static void F_107 ( struct V_22 * V_23 )
{
struct V_4 * V_156 ;
struct V_1 * V_76 ;
F_108 () ;
V_156 = F_3 ( V_23 -> V_3 ) ;
F_109 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
int V_86 ;
struct V_120 * V_121 = F_47 ( V_76 -> V_15 ) ;
if ( V_76 -> V_26 . V_131 == V_137 ) {
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_157 ++ ;
F_50 ( & V_121 -> V_81 ) ;
continue;
}
V_116 = F_110 ( V_23 , V_108 ) ;
if ( ! V_116 )
break;
V_116 -> V_3 = V_76 -> V_26 . V_151 ;
V_86 = F_111 ( V_116 ) ;
if ( V_86 == V_153 ) {
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_158 ++ ;
F_50 ( & V_121 -> V_81 ) ;
} else {
V_76 -> V_26 . V_151 -> V_15 . V_154 ++ ;
}
}
F_112 () ;
}
static T_8 F_113 ( struct V_22 * * V_159 )
{
struct V_22 * V_23 = * V_159 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_36 * V_37 ;
struct V_25 * V_26 = NULL ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
struct V_4 * V_156 ;
struct V_1 * V_76 ;
T_2 V_34 ;
T_5 V_47 ;
bool V_160 ;
struct V_125 * V_126 ;
struct V_120 * V_121 ;
bool V_161 ;
int V_86 ;
if ( F_69 ( V_23 ) < V_45 )
goto V_162;
V_37 = F_37 ( V_23 ) ;
if ( V_37 -> V_40 . V_49 != F_32 ( V_50 ) ) {
F_107 ( V_23 ) ;
return V_163 ;
}
V_23 = F_73 ( V_23 , V_108 ) ;
if ( ! V_23 ) {
* V_159 = NULL ;
return V_164 ;
}
V_161 = F_114 ( V_23 , F_30 ( true ) ) ;
if ( ! V_161 ) {
if ( ! F_114 ( V_23 , F_30 ( false ) ) )
goto V_162;
}
V_37 = F_37 ( V_23 ) ;
if ( ( V_37 -> V_48 & ( V_59 | V_133 ) ) == V_133 )
return V_163 ;
if ( V_37 -> V_48 & V_51 ) {
if ( ! V_161 )
goto V_162;
}
F_74 ( V_23 , V_45 ) ;
F_23 ( V_23 ) -> V_150 = ! ! ( V_37 -> V_48 & V_51 ) ;
F_23 ( V_23 ) -> V_165 = V_37 -> V_48 & V_166 ;
V_34 = F_27 ( V_37 , F_23 ( V_23 ) -> V_150 ) ;
F_108 () ;
V_156 = F_3 ( V_23 -> V_3 ) ;
F_109 (macsec, &rxd->secys, secys) {
struct V_13 * V_16 = F_103 ( & V_76 -> V_26 , V_34 ) ;
V_16 = V_16 ? F_13 ( V_16 ) : NULL ;
if ( V_16 ) {
V_26 = & V_76 -> V_26 ;
V_14 = V_16 ;
break;
}
}
if ( ! V_26 )
goto V_167;
V_3 = V_26 -> V_151 ;
V_76 = F_1 ( V_3 ) ;
V_121 = F_47 ( V_76 -> V_15 ) ;
V_126 = F_47 ( V_14 -> V_15 ) ;
if ( ! F_35 ( V_23 , V_26 -> V_57 ) ) {
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_168 ++ ;
F_50 ( & V_121 -> V_81 ) ;
goto V_169;
}
V_124 = F_7 ( V_14 -> V_8 [ F_23 ( V_23 ) -> V_165 ] ) ;
if ( ! V_124 ) {
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_131 == V_137 ) {
F_48 ( & V_126 -> V_81 ) ;
V_126 -> V_15 . V_170 ++ ;
F_50 ( & V_126 -> V_81 ) ;
goto V_169;
}
F_48 ( & V_126 -> V_81 ) ;
V_126 -> V_15 . V_171 ++ ;
F_50 ( & V_126 -> V_81 ) ;
goto V_172;
}
V_47 = F_98 ( V_37 -> V_54 ) ;
if ( V_26 -> V_129 ) {
bool V_173 ;
F_85 ( & V_124 -> V_72 ) ;
V_173 = V_124 -> V_73 >= V_26 -> V_128 &&
V_47 < ( V_124 -> V_73 - V_26 -> V_128 ) ;
F_86 ( & V_124 -> V_72 ) ;
if ( V_173 ) {
F_48 ( & V_126 -> V_81 ) ;
V_126 -> V_15 . V_130 ++ ;
F_50 ( & V_126 -> V_81 ) ;
goto V_174;
}
}
F_23 ( V_23 ) -> V_124 = V_124 ;
if ( V_37 -> V_48 & V_59 ||
V_26 -> V_131 != V_132 )
V_23 = F_100 ( V_23 , V_3 , V_124 , V_34 , V_26 ) ;
if ( F_115 ( V_23 ) ) {
if ( F_116 ( V_23 ) != - V_123 ) {
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
}
F_112 () ;
* V_159 = NULL ;
return V_164 ;
}
if ( ! F_84 ( V_23 , V_26 , V_47 ) )
goto V_174;
V_172:
F_93 ( V_23 , V_26 -> V_57 ,
F_30 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_87 ( V_23 , V_26 -> V_151 ) ;
if ( V_124 )
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
V_86 = F_99 ( & V_76 -> V_152 , V_23 ) ;
if ( V_86 == V_153 )
F_96 ( V_3 , V_23 -> V_65 ) ;
else
V_76 -> V_26 . V_151 -> V_15 . V_154 ++ ;
F_112 () ;
* V_159 = NULL ;
return V_164 ;
V_174:
F_19 ( V_124 ) ;
V_169:
F_14 ( V_14 ) ;
F_112 () ;
V_162:
F_66 ( V_23 ) ;
* V_159 = NULL ;
return V_164 ;
V_167:
V_160 = ! ! ( V_37 -> V_48 & V_59 ) ;
if ( ! V_160 )
F_93 ( V_23 , V_58 ,
F_30 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_109 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
V_121 = F_47 ( V_76 -> V_15 ) ;
if ( V_160 ||
V_76 -> V_26 . V_131 == V_137 ) {
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_175 ++ ;
F_50 ( & V_121 -> V_81 ) ;
continue;
}
V_116 = F_110 ( V_23 , V_108 ) ;
if ( ! V_116 )
break;
F_87 ( V_116 , V_76 -> V_26 . V_151 ) ;
V_86 = F_111 ( V_116 ) ;
if ( V_86 == V_153 ) {
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_176 ++ ;
F_50 ( & V_121 -> V_81 ) ;
} else {
V_76 -> V_26 . V_151 -> V_15 . V_154 ++ ;
}
}
F_112 () ;
* V_159 = V_23 ;
return V_163 ;
}
static struct V_99 * F_117 ( char * V_18 , int V_177 , int V_57 )
{
struct V_99 * V_19 ;
int V_86 ;
V_19 = F_118 ( L_2 , 0 , 0 ) ;
if ( F_115 ( V_19 ) )
return V_19 ;
V_86 = F_119 ( V_19 , V_18 , V_177 ) ;
if ( V_86 < 0 )
goto V_178;
V_86 = F_120 ( V_19 , V_57 ) ;
if ( V_86 < 0 )
goto V_178;
return V_19 ;
V_178:
F_18 ( V_19 ) ;
return F_67 ( V_86 ) ;
}
static int F_121 ( struct V_6 * V_124 , char * V_179 , int V_177 ,
int V_57 )
{
V_124 -> V_15 = F_122 ( struct V_180 ) ;
if ( ! V_124 -> V_15 )
return - V_117 ;
V_124 -> V_18 . V_19 = F_117 ( V_179 , V_177 , V_57 ) ;
if ( F_115 ( V_124 -> V_18 . V_19 ) ) {
F_11 ( V_124 -> V_15 ) ;
return F_116 ( V_124 -> V_18 . V_19 ) ;
}
V_124 -> V_9 = false ;
V_124 -> V_73 = 1 ;
F_123 ( & V_124 -> V_10 , 1 ) ;
F_124 ( & V_124 -> V_72 ) ;
return 0 ;
}
static void F_125 ( struct V_6 * V_124 )
{
V_124 -> V_9 = false ;
F_19 ( V_124 ) ;
}
static void F_126 ( struct V_13 * V_14 )
{
int V_181 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
struct V_6 * V_8 = F_6 ( V_14 -> V_8 [ V_181 ] ) ;
F_127 ( V_14 -> V_8 [ V_181 ] , NULL ) ;
if ( V_8 )
F_125 ( V_8 ) ;
}
F_14 ( V_14 ) ;
}
static struct V_13 * F_128 ( struct V_25 * V_26 , T_2 V_34 )
{
struct V_13 * V_14 , T_1 * * V_183 ;
for ( V_183 = & V_26 -> V_14 , V_14 = F_6 ( * V_183 ) ;
V_14 ;
V_183 = & V_14 -> V_184 , V_14 = F_6 ( * V_183 ) ) {
if ( V_14 -> V_34 == V_34 ) {
if ( V_14 -> V_9 )
V_26 -> V_29 -- ;
F_129 ( * V_183 , V_14 -> V_184 ) ;
return V_14 ;
}
}
return NULL ;
}
static struct V_13 * F_130 ( struct V_2 * V_3 , T_2 V_34 )
{
struct V_13 * V_14 ;
struct V_1 * V_76 ;
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
struct V_4 * V_156 = F_5 ( V_77 ) ;
struct V_25 * V_26 ;
F_131 (macsec, &rxd->secys, secys) {
if ( F_105 ( & V_76 -> V_26 , V_34 ) )
return F_67 ( - V_185 ) ;
}
V_14 = F_132 ( sizeof( * V_14 ) , V_186 ) ;
if ( ! V_14 )
return F_67 ( - V_117 ) ;
V_14 -> V_15 = F_133 ( struct V_125 ) ;
if ( ! V_14 -> V_15 ) {
F_12 ( V_14 ) ;
return F_67 ( - V_117 ) ;
}
V_14 -> V_34 = V_34 ;
V_14 -> V_9 = true ;
F_123 ( & V_14 -> V_10 , 1 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
F_129 ( V_14 -> V_184 , V_26 -> V_14 ) ;
F_129 ( V_26 -> V_14 , V_14 ) ;
if ( V_14 -> V_9 )
V_26 -> V_29 ++ ;
return V_14 ;
}
static int F_134 ( struct V_20 * V_71 , char * V_179 , int V_177 ,
int V_57 )
{
V_71 -> V_15 = F_122 ( struct V_187 ) ;
if ( ! V_71 -> V_15 )
return - V_117 ;
V_71 -> V_18 . V_19 = F_117 ( V_179 , V_177 , V_57 ) ;
if ( F_115 ( V_71 -> V_18 . V_19 ) ) {
F_11 ( V_71 -> V_15 ) ;
return F_116 ( V_71 -> V_18 . V_19 ) ;
}
V_71 -> V_9 = false ;
F_123 ( & V_71 -> V_10 , 1 ) ;
F_124 ( & V_71 -> V_72 ) ;
return 0 ;
}
static void F_135 ( struct V_20 * V_71 )
{
V_71 -> V_9 = false ;
F_22 ( V_71 ) ;
}
static struct V_2 * F_136 ( struct V_188 * V_188 ,
struct V_189 * * V_190 )
{
int V_191 = F_137 ( V_190 [ V_192 ] ) ;
struct V_2 * V_3 ;
V_3 = F_138 ( V_188 , V_191 ) ;
if ( ! V_3 )
return F_67 ( - V_193 ) ;
if ( ! F_139 ( V_3 ) )
return F_67 ( - V_193 ) ;
return V_3 ;
}
static T_2 F_140 ( const struct V_189 * V_194 )
{
return ( V_195 T_2 ) F_141 ( V_194 ) ;
}
static int F_142 ( struct V_22 * V_23 , int V_196 , T_2 V_197 ,
int V_198 )
{
return F_143 ( V_23 , V_196 , ( V_195 V_199 ) V_197 , V_198 ) ;
}
static struct V_20 * F_144 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_200 ,
struct V_2 * * V_201 ,
struct V_25 * * V_202 ,
struct V_27 * * V_203 ,
T_3 * V_165 )
{
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
if ( ! V_200 [ V_204 ] )
return F_67 ( - V_113 ) ;
* V_165 = F_145 ( V_200 [ V_204 ] ) ;
V_3 = F_136 ( V_188 , V_190 ) ;
if ( F_115 ( V_3 ) )
return F_146 ( V_3 ) ;
if ( * V_165 >= V_182 )
return F_67 ( - V_113 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
V_71 = F_6 ( V_28 -> V_8 [ * V_165 ] ) ;
if ( ! V_71 )
return F_67 ( - V_193 ) ;
* V_201 = V_3 ;
* V_203 = V_28 ;
* V_202 = V_26 ;
return V_71 ;
}
static struct V_13 * F_147 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_205 ,
struct V_2 * * V_201 ,
struct V_25 * * V_202 )
{
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
T_2 V_34 ;
V_3 = F_136 ( V_188 , V_190 ) ;
if ( F_115 ( V_3 ) )
return F_146 ( V_3 ) ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
if ( ! V_205 [ V_206 ] )
return F_67 ( - V_113 ) ;
V_34 = F_140 ( V_205 [ V_206 ] ) ;
V_14 = F_105 ( V_26 , V_34 ) ;
if ( ! V_14 )
return F_67 ( - V_193 ) ;
* V_202 = V_26 ;
* V_201 = V_3 ;
return V_14 ;
}
static struct V_6 * F_148 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_205 ,
struct V_189 * * V_200 ,
struct V_2 * * V_201 ,
struct V_25 * * V_202 ,
struct V_13 * * V_203 ,
T_3 * V_165 )
{
struct V_13 * V_14 ;
struct V_6 * V_124 ;
if ( ! V_200 [ V_204 ] )
return F_67 ( - V_113 ) ;
* V_165 = F_145 ( V_200 [ V_204 ] ) ;
if ( * V_165 >= V_182 )
return F_67 ( - V_113 ) ;
V_14 = F_147 ( V_188 , V_190 , V_205 , V_201 , V_202 ) ;
if ( F_115 ( V_14 ) )
return F_146 ( V_14 ) ;
V_124 = F_6 ( V_14 -> V_8 [ * V_165 ] ) ;
if ( ! V_124 )
return F_67 ( - V_193 ) ;
* V_203 = V_14 ;
return V_124 ;
}
static int F_149 ( struct V_189 * * V_190 , struct V_189 * * V_200 )
{
if ( ! V_190 [ V_207 ] )
return - V_113 ;
if ( F_150 ( V_200 , V_208 , V_190 [ V_207 ] ,
V_209 ) )
return - V_113 ;
return 0 ;
}
static int F_151 ( struct V_189 * * V_190 , struct V_189 * * V_205 )
{
if ( ! V_190 [ V_210 ] )
return - V_113 ;
if ( F_150 ( V_205 , V_211 , V_190 [ V_210 ] ,
V_212 ) )
return - V_113 ;
return 0 ;
}
static bool F_152 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
! V_190 [ V_213 ] ||
! V_190 [ V_214 ] )
return false ;
if ( F_145 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( V_190 [ V_215 ] && F_137 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_145 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
if ( F_153 ( V_190 [ V_214 ] ) != V_217 )
return false ;
return true ;
}
static int F_154 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
unsigned char V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
int V_96 ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_152 ( V_200 ) )
return - V_113 ;
F_155 () ;
V_14 = F_147 ( F_156 ( V_219 ) , V_190 , V_205 , & V_3 , & V_26 ) ;
if ( F_115 ( V_14 ) ) {
F_157 () ;
return F_116 ( V_14 ) ;
}
V_165 = F_145 ( V_200 [ V_204 ] ) ;
if ( F_153 ( V_200 [ V_213 ] ) != V_26 -> V_177 ) {
F_158 ( L_3 ,
F_153 ( V_200 [ V_213 ] ) , V_26 -> V_177 ) ;
F_157 () ;
return - V_113 ;
}
V_124 = F_6 ( V_14 -> V_8 [ V_165 ] ) ;
if ( V_124 ) {
F_157 () ;
return - V_220 ;
}
V_124 = F_63 ( sizeof( * V_124 ) , V_186 ) ;
if ( ! V_124 ) {
F_157 () ;
return - V_117 ;
}
V_96 = F_121 ( V_124 , F_159 ( V_200 [ V_213 ] ) ,
V_26 -> V_177 , V_26 -> V_57 ) ;
if ( V_96 < 0 ) {
F_12 ( V_124 ) ;
F_157 () ;
return V_96 ;
}
if ( V_200 [ V_215 ] ) {
F_40 ( & V_124 -> V_72 ) ;
V_124 -> V_73 = F_137 ( V_200 [ V_215 ] ) ;
F_42 ( & V_124 -> V_72 ) ;
}
if ( V_200 [ V_216 ] )
V_124 -> V_9 = ! ! F_145 ( V_200 [ V_216 ] ) ;
F_160 ( V_124 -> V_18 . V_221 , V_200 [ V_214 ] , V_217 ) ;
V_124 -> V_16 = V_14 ;
F_129 ( V_14 -> V_8 [ V_165 ] , V_124 ) ;
F_157 () ;
return 0 ;
}
static bool F_161 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_206 ] )
return false ;
if ( V_190 [ V_222 ] ) {
if ( F_145 ( V_190 [ V_222 ] ) > 1 )
return false ;
}
return true ;
}
static int F_162 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
T_2 V_34 = V_223 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_13 * V_14 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_161 ( V_205 ) )
return - V_113 ;
F_155 () ;
V_3 = F_136 ( F_156 ( V_219 ) , V_190 ) ;
if ( F_115 ( V_3 ) ) {
F_157 () ;
return F_116 ( V_3 ) ;
}
V_34 = F_140 ( V_205 [ V_206 ] ) ;
V_14 = F_130 ( V_3 , V_34 ) ;
if ( F_115 ( V_14 ) ) {
F_157 () ;
return F_116 ( V_14 ) ;
}
if ( V_205 [ V_222 ] )
V_14 -> V_9 = ! ! F_145 ( V_205 [ V_222 ] ) ;
F_157 () ;
return 0 ;
}
static bool F_163 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
! V_190 [ V_215 ] ||
! V_190 [ V_213 ] ||
! V_190 [ V_214 ] )
return false ;
if ( F_145 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( F_137 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_145 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
if ( F_153 ( V_190 [ V_214 ] ) != V_217 )
return false ;
return true ;
}
static int F_164 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
unsigned char V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
int V_96 ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_163 ( V_200 ) )
return - V_113 ;
F_155 () ;
V_3 = F_136 ( F_156 ( V_219 ) , V_190 ) ;
if ( F_115 ( V_3 ) ) {
F_157 () ;
return F_116 ( V_3 ) ;
}
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
V_165 = F_145 ( V_200 [ V_204 ] ) ;
if ( F_153 ( V_200 [ V_213 ] ) != V_26 -> V_177 ) {
F_158 ( L_4 ,
F_153 ( V_200 [ V_213 ] ) , V_26 -> V_177 ) ;
F_157 () ;
return - V_113 ;
}
V_71 = F_6 ( V_28 -> V_8 [ V_165 ] ) ;
if ( V_71 ) {
F_157 () ;
return - V_220 ;
}
V_71 = F_63 ( sizeof( * V_71 ) , V_186 ) ;
if ( ! V_71 ) {
F_157 () ;
return - V_117 ;
}
V_96 = F_134 ( V_71 , F_159 ( V_200 [ V_213 ] ) ,
V_26 -> V_177 , V_26 -> V_57 ) ;
if ( V_96 < 0 ) {
F_12 ( V_71 ) ;
F_157 () ;
return V_96 ;
}
F_160 ( V_71 -> V_18 . V_221 , V_200 [ V_214 ] , V_217 ) ;
F_40 ( & V_71 -> V_72 ) ;
V_71 -> V_73 = F_137 ( V_200 [ V_215 ] ) ;
F_42 ( & V_71 -> V_72 ) ;
if ( V_200 [ V_216 ] )
V_71 -> V_9 = ! ! F_145 ( V_200 [ V_216 ] ) ;
if ( V_165 == V_28 -> V_60 && V_71 -> V_9 )
V_26 -> V_75 = true ;
F_129 ( V_28 -> V_8 [ V_165 ] , V_71 ) ;
F_157 () ;
return 0 ;
}
static int F_165 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
F_155 () ;
V_124 = F_148 ( F_156 ( V_219 ) , V_190 , V_205 , V_200 ,
& V_3 , & V_26 , & V_14 , & V_165 ) ;
if ( F_115 ( V_124 ) ) {
F_157 () ;
return F_116 ( V_124 ) ;
}
if ( V_124 -> V_9 ) {
F_157 () ;
return - V_220 ;
}
F_127 ( V_14 -> V_8 [ V_165 ] , NULL ) ;
F_125 ( V_124 ) ;
F_157 () ;
return 0 ;
}
static int F_166 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
T_2 V_34 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! V_205 [ V_206 ] )
return - V_113 ;
F_155 () ;
V_3 = F_136 ( F_156 ( V_219 ) , V_219 -> V_190 ) ;
if ( F_115 ( V_3 ) ) {
F_157 () ;
return F_116 ( V_3 ) ;
}
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_34 = F_140 ( V_205 [ V_206 ] ) ;
V_14 = F_128 ( V_26 , V_34 ) ;
if ( ! V_14 ) {
F_157 () ;
return - V_193 ;
}
F_126 ( V_14 ) ;
F_157 () ;
return 0 ;
}
static int F_167 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
T_3 V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
F_155 () ;
V_71 = F_144 ( F_156 ( V_219 ) , V_190 , V_200 ,
& V_3 , & V_26 , & V_28 , & V_165 ) ;
if ( F_115 ( V_71 ) ) {
F_157 () ;
return F_116 ( V_71 ) ;
}
if ( V_71 -> V_9 ) {
F_157 () ;
return - V_220 ;
}
F_127 ( V_28 -> V_8 [ V_165 ] , NULL ) ;
F_135 ( V_71 ) ;
F_157 () ;
return 0 ;
}
static bool F_168 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
V_190 [ V_213 ] ||
V_190 [ V_214 ] )
return false ;
if ( F_145 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( V_190 [ V_215 ] && F_137 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_145 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
return true ;
}
static int F_169 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_20 * V_71 ;
T_3 V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_168 ( V_200 ) )
return - V_113 ;
F_155 () ;
V_71 = F_144 ( F_156 ( V_219 ) , V_190 , V_200 ,
& V_3 , & V_26 , & V_28 , & V_165 ) ;
if ( F_115 ( V_71 ) ) {
F_157 () ;
return F_116 ( V_71 ) ;
}
if ( V_200 [ V_215 ] ) {
F_40 ( & V_71 -> V_72 ) ;
V_71 -> V_73 = F_137 ( V_200 [ V_215 ] ) ;
F_42 ( & V_71 -> V_72 ) ;
}
if ( V_200 [ V_216 ] )
V_71 -> V_9 = F_145 ( V_200 [ V_216 ] ) ;
if ( V_165 == V_28 -> V_60 )
V_26 -> V_75 = V_71 -> V_9 ;
F_157 () ;
return 0 ;
}
static int F_170 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
if ( F_149 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_168 ( V_200 ) )
return - V_113 ;
F_155 () ;
V_124 = F_148 ( F_156 ( V_219 ) , V_190 , V_205 , V_200 ,
& V_3 , & V_26 , & V_14 , & V_165 ) ;
if ( F_115 ( V_124 ) ) {
F_157 () ;
return F_116 ( V_124 ) ;
}
if ( V_200 [ V_215 ] ) {
F_40 ( & V_124 -> V_72 ) ;
V_124 -> V_73 = F_137 ( V_200 [ V_215 ] ) ;
F_42 ( & V_124 -> V_72 ) ;
}
if ( V_200 [ V_216 ] )
V_124 -> V_9 = F_145 ( V_200 [ V_216 ] ) ;
F_157 () ;
return 0 ;
}
static int F_171 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_13 * V_14 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_151 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_161 ( V_205 ) )
return - V_113 ;
F_155 () ;
V_14 = F_147 ( F_156 ( V_219 ) , V_190 , V_205 , & V_3 , & V_26 ) ;
if ( F_115 ( V_14 ) ) {
F_157 () ;
return F_116 ( V_14 ) ;
}
if ( V_205 [ V_222 ] ) {
bool V_224 = ! ! F_145 ( V_205 [ V_222 ] ) ;
if ( V_14 -> V_9 != V_224 )
V_26 -> V_29 += V_224 ? 1 : - 1 ;
V_14 -> V_9 = V_224 ;
}
F_157 () ;
return 0 ;
}
static int F_172 ( struct V_22 * V_23 ,
struct V_187 T_9 * V_225 )
{
struct V_187 V_226 = { 0 , } ;
int V_227 ;
F_173 (cpu) {
const struct V_187 * V_15 = F_174 ( V_225 , V_227 ) ;
V_226 . V_85 += V_15 -> V_85 ;
V_226 . V_83 += V_15 -> V_83 ;
}
if ( F_175 ( V_23 , V_228 , V_226 . V_85 ) ||
F_175 ( V_23 , V_229 , V_226 . V_83 ) )
return - V_230 ;
return 0 ;
}
static int F_176 ( struct V_22 * V_23 ,
struct V_180 T_9 * V_225 )
{
struct V_180 V_226 = { 0 , } ;
int V_227 ;
F_173 (cpu) {
const struct V_180 * V_15 = F_174 ( V_225 , V_227 ) ;
V_226 . V_143 += V_15 -> V_143 ;
V_226 . V_140 += V_15 -> V_140 ;
V_226 . V_138 += V_15 -> V_138 ;
V_226 . V_170 += V_15 -> V_170 ;
V_226 . V_171 += V_15 -> V_171 ;
}
if ( F_175 ( V_23 , V_231 , V_226 . V_143 ) ||
F_175 ( V_23 , V_232 , V_226 . V_140 ) ||
F_175 ( V_23 , V_233 , V_226 . V_138 ) ||
F_175 ( V_23 , V_234 , V_226 . V_170 ) ||
F_175 ( V_23 , V_235 , V_226 . V_171 ) )
return - V_230 ;
return 0 ;
}
static int F_177 ( struct V_22 * V_23 ,
struct V_125 T_9 * V_225 )
{
struct V_236 V_226 = { 0 , } ;
int V_227 ;
F_173 (cpu) {
const struct V_125 * V_15 ;
struct V_236 V_106 ;
unsigned int V_237 ;
V_15 = F_174 ( V_225 , V_227 ) ;
do {
V_237 = F_178 ( & V_15 -> V_81 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_179 ( & V_15 -> V_81 , V_237 ) );
V_226 . V_135 += V_106 . V_135 ;
V_226 . V_134 += V_106 . V_134 ;
V_226 . V_142 += V_106 . V_142 ;
V_226 . V_141 += V_106 . V_141 ;
V_226 . V_143 += V_106 . V_143 ;
V_226 . V_140 += V_106 . V_140 ;
V_226 . V_130 += V_106 . V_130 ;
V_226 . V_138 += V_106 . V_138 ;
V_226 . V_170 += V_106 . V_170 ;
V_226 . V_171 += V_106 . V_171 ;
}
if ( F_143 ( V_23 , V_238 ,
V_226 . V_135 ,
V_239 ) ||
F_143 ( V_23 , V_240 ,
V_226 . V_134 ,
V_239 ) ||
F_143 ( V_23 , V_241 ,
V_226 . V_142 ,
V_239 ) ||
F_143 ( V_23 , V_242 ,
V_226 . V_141 ,
V_239 ) ||
F_143 ( V_23 , V_243 ,
V_226 . V_143 ,
V_239 ) ||
F_143 ( V_23 , V_244 ,
V_226 . V_140 ,
V_239 ) ||
F_143 ( V_23 , V_245 ,
V_226 . V_130 ,
V_239 ) ||
F_143 ( V_23 , V_246 ,
V_226 . V_138 ,
V_239 ) ||
F_143 ( V_23 , V_247 ,
V_226 . V_170 ,
V_239 ) ||
F_143 ( V_23 , V_248 ,
V_226 . V_171 ,
V_239 ) )
return - V_230 ;
return 0 ;
}
static int F_180 ( struct V_22 * V_23 ,
struct V_79 T_9 * V_225 )
{
struct V_249 V_226 = { 0 , } ;
int V_227 ;
F_173 (cpu) {
const struct V_79 * V_15 ;
struct V_249 V_106 ;
unsigned int V_237 ;
V_15 = F_174 ( V_225 , V_227 ) ;
do {
V_237 = F_178 ( & V_15 -> V_81 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_179 ( & V_15 -> V_81 , V_237 ) );
V_226 . V_85 += V_106 . V_85 ;
V_226 . V_83 += V_106 . V_83 ;
V_226 . V_84 += V_106 . V_84 ;
V_226 . V_82 += V_106 . V_82 ;
}
if ( F_143 ( V_23 , V_250 ,
V_226 . V_85 ,
V_251 ) ||
F_143 ( V_23 , V_252 ,
V_226 . V_83 ,
V_251 ) ||
F_143 ( V_23 , V_253 ,
V_226 . V_84 ,
V_251 ) ||
F_143 ( V_23 , V_254 ,
V_226 . V_82 ,
V_251 ) )
return - V_230 ;
return 0 ;
}
static int F_181 ( struct V_22 * V_23 ,
struct V_120 T_9 * V_225 )
{
struct V_255 V_226 = { 0 , } ;
int V_227 ;
F_173 (cpu) {
const struct V_120 * V_15 ;
struct V_255 V_106 ;
unsigned int V_237 ;
V_15 = F_174 ( V_225 , V_227 ) ;
do {
V_237 = F_178 ( & V_15 -> V_81 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_179 ( & V_15 -> V_81 , V_237 ) );
V_226 . V_256 += V_106 . V_256 ;
V_226 . V_158 += V_106 . V_158 ;
V_226 . V_122 += V_106 . V_122 ;
V_226 . V_157 += V_106 . V_157 ;
V_226 . V_168 += V_106 . V_168 ;
V_226 . V_176 += V_106 . V_176 ;
V_226 . V_175 += V_106 . V_175 ;
V_226 . V_257 += V_106 . V_257 ;
}
if ( F_143 ( V_23 , V_258 ,
V_226 . V_256 ,
V_259 ) ||
F_143 ( V_23 , V_260 ,
V_226 . V_158 ,
V_259 ) ||
F_143 ( V_23 , V_261 ,
V_226 . V_122 ,
V_259 ) ||
F_143 ( V_23 , V_262 ,
V_226 . V_157 ,
V_259 ) ||
F_143 ( V_23 , V_263 ,
V_226 . V_168 ,
V_259 ) ||
F_143 ( V_23 , V_264 ,
V_226 . V_176 ,
V_259 ) ||
F_143 ( V_23 , V_265 ,
V_226 . V_175 ,
V_259 ) ||
F_143 ( V_23 , V_266 ,
V_226 . V_257 ,
V_259 ) )
return - V_230 ;
return 0 ;
}
static int F_182 ( struct V_25 * V_26 , struct V_22 * V_23 )
{
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_189 * V_267 = F_183 ( V_23 , V_268 ) ;
if ( ! V_267 )
return 1 ;
if ( F_142 ( V_23 , V_269 , V_26 -> V_34 ,
V_270 ) ||
F_143 ( V_23 , V_271 ,
V_272 ,
V_270 ) ||
F_184 ( V_23 , V_273 , V_26 -> V_57 ) ||
F_184 ( V_23 , V_274 , V_26 -> V_75 ) ||
F_184 ( V_23 , V_275 , V_26 -> V_74 ) ||
F_184 ( V_23 , V_276 , V_26 -> V_129 ) ||
F_184 ( V_23 , V_277 , V_26 -> V_131 ) ||
F_184 ( V_23 , V_278 , V_28 -> V_55 ) ||
F_184 ( V_23 , V_279 , V_28 -> F_25 ) ||
F_184 ( V_23 , V_280 , V_28 -> V_30 ) ||
F_184 ( V_23 , V_281 , V_28 -> V_31 ) ||
F_184 ( V_23 , V_282 , V_28 -> V_60 ) )
goto V_283;
if ( V_26 -> V_129 ) {
if ( F_175 ( V_23 , V_284 , V_26 -> V_128 ) )
goto V_283;
}
F_185 ( V_23 , V_267 ) ;
return 0 ;
V_283:
F_186 ( V_23 , V_267 ) ;
return 1 ;
}
static int F_187 ( struct V_25 * V_26 , struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_285 * V_24 )
{
struct V_13 * V_14 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_189 * V_286 , * V_287 ;
int V_181 , V_288 ;
void * V_37 ;
struct V_189 * V_289 ;
V_37 = F_188 ( V_23 , F_189 ( V_24 -> V_23 ) . V_290 , V_24 -> V_291 -> V_292 ,
& V_293 , V_294 , V_295 ) ;
if ( ! V_37 )
return - V_230 ;
F_190 ( V_24 , V_37 , & V_293 ) ;
if ( F_175 ( V_23 , V_192 , V_3 -> V_191 ) )
goto V_296;
if ( F_182 ( V_26 , V_23 ) )
goto V_296;
V_289 = F_183 ( V_23 , V_297 ) ;
if ( ! V_289 )
goto V_296;
if ( F_180 ( V_23 , V_28 -> V_15 ) ) {
F_186 ( V_23 , V_289 ) ;
goto V_296;
}
F_185 ( V_23 , V_289 ) ;
V_289 = F_183 ( V_23 , V_298 ) ;
if ( ! V_289 )
goto V_296;
if ( F_181 ( V_23 , F_1 ( V_3 ) -> V_15 ) ) {
F_186 ( V_23 , V_289 ) ;
goto V_296;
}
F_185 ( V_23 , V_289 ) ;
V_286 = F_183 ( V_23 , V_299 ) ;
if ( ! V_286 )
goto V_296;
for ( V_181 = 0 , V_288 = 1 ; V_181 < V_182 ; V_181 ++ ) {
struct V_20 * V_71 = F_6 ( V_28 -> V_8 [ V_181 ] ) ;
struct V_189 * V_300 ;
if ( ! V_71 )
continue;
V_300 = F_183 ( V_23 , V_288 ++ ) ;
if ( ! V_300 ) {
F_186 ( V_23 , V_286 ) ;
goto V_296;
}
if ( F_184 ( V_23 , V_204 , V_181 ) ||
F_175 ( V_23 , V_215 , V_71 -> V_73 ) ||
F_191 ( V_23 , V_214 , V_217 , V_71 -> V_18 . V_221 ) ||
F_184 ( V_23 , V_216 , V_71 -> V_9 ) ) {
F_186 ( V_23 , V_300 ) ;
F_186 ( V_23 , V_286 ) ;
goto V_296;
}
V_289 = F_183 ( V_23 , V_301 ) ;
if ( ! V_289 ) {
F_186 ( V_23 , V_300 ) ;
F_186 ( V_23 , V_286 ) ;
goto V_296;
}
if ( F_172 ( V_23 , V_71 -> V_15 ) ) {
F_186 ( V_23 , V_289 ) ;
F_186 ( V_23 , V_300 ) ;
F_186 ( V_23 , V_286 ) ;
goto V_296;
}
F_185 ( V_23 , V_289 ) ;
F_185 ( V_23 , V_300 ) ;
}
F_185 ( V_23 , V_286 ) ;
V_287 = F_183 ( V_23 , V_302 ) ;
if ( ! V_287 )
goto V_296;
V_288 = 1 ;
F_106 (secy, rx_sc) {
int V_303 ;
struct V_189 * V_304 ;
struct V_189 * V_305 = F_183 ( V_23 , V_288 ++ ) ;
if ( ! V_305 ) {
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_184 ( V_23 , V_222 , V_14 -> V_9 ) ||
F_142 ( V_23 , V_206 , V_14 -> V_34 ,
V_306 ) ) {
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
V_289 = F_183 ( V_23 , V_307 ) ;
if ( ! V_289 ) {
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_177 ( V_23 , V_14 -> V_15 ) ) {
F_186 ( V_23 , V_289 ) ;
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
F_185 ( V_23 , V_289 ) ;
V_304 = F_183 ( V_23 , V_308 ) ;
if ( ! V_304 ) {
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
for ( V_181 = 0 , V_303 = 1 ; V_181 < V_182 ; V_181 ++ ) {
struct V_6 * V_124 = F_6 ( V_14 -> V_8 [ V_181 ] ) ;
struct V_189 * V_309 ;
if ( ! V_124 )
continue;
V_309 = F_183 ( V_23 , V_303 ++ ) ;
if ( ! V_309 ) {
F_186 ( V_23 , V_304 ) ;
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
V_289 = F_183 ( V_23 , V_301 ) ;
if ( ! V_289 ) {
F_186 ( V_23 , V_304 ) ;
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_176 ( V_23 , V_124 -> V_15 ) ) {
F_186 ( V_23 , V_289 ) ;
F_186 ( V_23 , V_304 ) ;
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
F_185 ( V_23 , V_289 ) ;
if ( F_184 ( V_23 , V_204 , V_181 ) ||
F_175 ( V_23 , V_215 , V_124 -> V_73 ) ||
F_191 ( V_23 , V_214 , V_217 , V_124 -> V_18 . V_221 ) ||
F_184 ( V_23 , V_216 , V_124 -> V_9 ) ) {
F_186 ( V_23 , V_309 ) ;
F_186 ( V_23 , V_305 ) ;
F_186 ( V_23 , V_287 ) ;
goto V_296;
}
F_185 ( V_23 , V_309 ) ;
}
F_185 ( V_23 , V_304 ) ;
F_185 ( V_23 , V_305 ) ;
}
F_185 ( V_23 , V_287 ) ;
F_192 ( V_23 , V_37 ) ;
return 0 ;
V_296:
F_193 ( V_23 , V_37 ) ;
return - V_230 ;
}
static int F_194 ( struct V_22 * V_23 , struct V_285 * V_24 )
{
struct V_188 * V_188 = F_195 ( V_23 -> V_310 ) ;
struct V_2 * V_3 ;
int V_311 , V_312 ;
V_311 = V_24 -> args [ 0 ] ;
V_312 = 0 ;
F_155 () ;
V_24 -> V_313 = V_314 ;
F_196 (net, dev) {
struct V_25 * V_26 ;
if ( V_312 < V_311 )
goto V_184;
if ( ! F_139 ( V_3 ) )
goto V_184;
V_26 = & F_1 ( V_3 ) -> V_26 ;
if ( F_187 ( V_26 , V_3 , V_23 , V_24 ) < 0 )
goto V_315;
V_184:
V_312 ++ ;
}
V_315:
F_157 () ;
V_24 -> args [ 0 ] = V_312 ;
return V_23 -> V_65 ;
}
static T_10 F_197 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_2 ( V_3 ) ;
struct V_25 * V_26 = & V_76 -> V_26 ;
struct V_120 * V_121 ;
int V_86 , V_65 ;
if ( ! V_26 -> V_74 ) {
V_121 = F_47 ( V_76 -> V_15 ) ;
F_48 ( & V_121 -> V_81 ) ;
V_121 -> V_15 . V_256 ++ ;
F_50 ( & V_121 -> V_81 ) ;
V_23 -> V_3 = V_76 -> V_77 ;
V_65 = V_23 -> V_65 ;
V_86 = F_56 ( V_23 ) ;
F_51 ( V_3 , V_86 , V_65 ) ;
return V_86 ;
}
if ( ! V_26 -> V_75 ) {
F_66 ( V_23 ) ;
V_3 -> V_15 . V_93 ++ ;
return V_316 ;
}
V_23 = F_65 ( V_23 , V_3 ) ;
if ( F_115 ( V_23 ) ) {
if ( F_116 ( V_23 ) != - V_123 )
V_3 -> V_15 . V_93 ++ ;
return V_316 ;
}
F_46 ( V_23 , & V_76 -> V_26 . V_28 , F_23 ( V_23 ) -> V_71 ) ;
F_43 ( V_23 , V_3 ) ;
V_65 = V_23 -> V_65 ;
V_86 = F_56 ( V_23 ) ;
F_51 ( V_3 , V_86 , V_65 ) ;
return V_86 ;
}
static int F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
int V_96 ;
V_3 -> V_90 = F_133 ( struct V_89 ) ;
if ( ! V_3 -> V_90 )
return - V_117 ;
V_96 = F_199 ( & V_76 -> V_152 , V_3 ) ;
if ( V_96 ) {
F_11 ( V_3 -> V_90 ) ;
return V_96 ;
}
V_3 -> V_317 = V_77 -> V_317 & V_318 ;
V_3 -> V_317 |= V_319 | V_320 ;
V_3 -> V_321 = V_77 -> V_321 +
V_114 ;
V_3 -> V_322 = V_77 -> V_322 +
V_115 ;
if ( F_200 ( V_3 -> V_323 ) )
F_201 ( V_3 , V_77 ) ;
if ( F_200 ( V_3 -> V_324 ) )
memcpy ( V_3 -> V_324 , V_77 -> V_324 , V_3 -> V_325 ) ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
F_203 ( & V_76 -> V_152 ) ;
F_11 ( V_3 -> V_90 ) ;
}
static T_11 F_204 ( struct V_2 * V_3 ,
T_11 V_317 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
V_317 &= ( V_77 -> V_317 & V_318 ) |
V_320 | V_326 ;
V_317 |= V_319 ;
return V_317 ;
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
int V_96 ;
if ( ! ( V_77 -> V_327 & V_328 ) )
return - V_329 ;
V_96 = F_206 ( V_77 , V_3 -> V_323 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_3 -> V_327 & V_330 ) {
V_96 = F_207 ( V_77 , 1 ) ;
if ( V_96 < 0 )
goto V_331;
}
if ( V_3 -> V_327 & V_332 ) {
V_96 = F_208 ( V_77 , 1 ) ;
if ( V_96 < 0 )
goto V_333;
}
if ( F_209 ( V_77 ) )
F_210 ( V_3 ) ;
return 0 ;
V_333:
if ( V_3 -> V_327 & V_330 )
F_207 ( V_77 , - 1 ) ;
V_331:
F_211 ( V_77 , V_3 -> V_323 ) ;
F_212 ( V_3 ) ;
return V_96 ;
}
static int F_213 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_212 ( V_3 ) ;
F_214 ( V_77 , V_3 ) ;
F_215 ( V_77 , V_3 ) ;
if ( V_3 -> V_327 & V_330 )
F_207 ( V_77 , - 1 ) ;
if ( V_3 -> V_327 & V_332 )
F_208 ( V_77 , - 1 ) ;
F_211 ( V_77 , V_3 -> V_323 ) ;
return 0 ;
}
static void F_216 ( struct V_2 * V_3 , int V_334 )
{
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
if ( ! ( V_3 -> V_327 & V_328 ) )
return;
if ( V_334 & V_330 )
F_207 ( V_77 , V_3 -> V_327 & V_330 ? 1 : - 1 ) ;
if ( V_334 & V_332 )
F_208 ( V_77 ,
V_3 -> V_327 & V_332 ? 1 : - 1 ) ;
}
static void F_217 ( struct V_2 * V_3 )
{
struct V_2 * V_77 = F_1 ( V_3 ) -> V_77 ;
F_218 ( V_77 , V_3 ) ;
F_219 ( V_77 , V_3 ) ;
}
static int F_220 ( struct V_2 * V_3 , void * V_335 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
struct V_336 * V_32 = V_335 ;
int V_96 ;
if ( ! F_221 ( V_32 -> V_337 ) )
return - V_338 ;
if ( ! ( V_3 -> V_327 & V_328 ) )
goto V_149;
V_96 = F_206 ( V_77 , V_32 -> V_337 ) ;
if ( V_96 < 0 )
return V_96 ;
F_211 ( V_77 , V_3 -> V_323 ) ;
V_149:
F_222 ( V_3 -> V_323 , V_32 -> V_337 ) ;
return 0 ;
}
static int F_223 ( struct V_2 * V_3 , int V_339 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
unsigned int V_340 = V_76 -> V_26 . V_57 + F_30 ( true ) ;
if ( V_76 -> V_77 -> V_119 - V_340 < V_339 )
return - V_341 ;
V_3 -> V_119 = V_339 ;
return 0 ;
}
static void F_224 ( struct V_2 * V_3 ,
struct V_342 * V_343 )
{
int V_227 ;
if ( ! V_3 -> V_90 )
return;
F_173 (cpu) {
struct V_89 * V_15 ;
struct V_89 V_106 ;
int V_237 ;
V_15 = F_174 ( V_3 -> V_90 , V_227 ) ;
do {
V_237 = F_178 ( & V_15 -> V_81 ) ;
V_106 . V_147 = V_15 -> V_147 ;
V_106 . V_148 = V_15 -> V_148 ;
V_106 . V_91 = V_15 -> V_91 ;
V_106 . V_92 = V_15 -> V_92 ;
} while ( F_179 ( & V_15 -> V_81 , V_237 ) );
V_343 -> V_147 += V_106 . V_147 ;
V_343 -> V_148 += V_106 . V_148 ;
V_343 -> V_91 += V_106 . V_91 ;
V_343 -> V_92 += V_106 . V_92 ;
}
V_343 -> V_154 = V_3 -> V_15 . V_154 ;
V_343 -> V_93 = V_3 -> V_15 . V_93 ;
}
static int F_225 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_77 -> V_191 ;
}
static int F_226 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_344 ;
}
static void F_227 ( struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_11 ( V_76 -> V_15 ) ;
F_11 ( V_76 -> V_26 . V_28 . V_15 ) ;
F_58 ( V_77 ) ;
F_228 ( V_3 ) ;
}
static void F_229 ( struct V_2 * V_3 )
{
F_230 ( V_3 ) ;
V_3 -> V_345 = 0 ;
V_3 -> V_346 = V_347 ;
V_3 -> V_348 |= V_349 ;
V_3 -> V_350 = & V_351 ;
V_3 -> V_352 = F_227 ;
F_231 ( V_3 , & V_353 ) ;
F_232 ( V_3 -> V_324 ) ;
}
static void F_233 ( struct V_2 * V_3 ,
struct V_189 * V_64 [] )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_26 = & F_1 ( V_3 ) -> V_26 ;
V_28 = & V_26 -> V_28 ;
if ( V_64 [ V_354 ] ) {
struct V_20 * V_71 ;
V_28 -> V_60 = F_145 ( V_64 [ V_354 ] ) ;
V_71 = F_6 ( V_28 -> V_8 [ V_28 -> V_60 ] ) ;
V_26 -> V_75 = V_71 && V_71 -> V_9 ;
}
if ( V_64 [ V_355 ] )
V_26 -> V_128 = F_137 ( V_64 [ V_355 ] ) ;
if ( V_64 [ V_356 ] )
V_28 -> V_55 = ! ! F_145 ( V_64 [ V_356 ] ) ;
if ( V_64 [ V_357 ] )
V_26 -> V_74 = ! ! F_145 ( V_64 [ V_357 ] ) ;
if ( V_64 [ V_358 ] )
V_28 -> F_25 = ! ! F_145 ( V_64 [ V_358 ] ) ;
if ( V_64 [ V_359 ] )
V_28 -> V_30 = ! ! F_145 ( V_64 [ V_359 ] ) ;
if ( V_64 [ V_360 ] )
V_28 -> V_31 = ! ! F_145 ( V_64 [ V_360 ] ) ;
if ( V_64 [ V_361 ] )
V_26 -> V_129 = ! ! F_145 ( V_64 [ V_361 ] ) ;
if ( V_64 [ V_362 ] )
V_26 -> V_131 = F_145 ( V_64 [ V_362 ] ) ;
}
static int F_234 ( struct V_2 * V_3 , struct V_189 * V_363 [] ,
struct V_189 * V_64 [] )
{
if ( ! V_64 )
return 0 ;
if ( V_64 [ V_364 ] ||
V_64 [ V_365 ] ||
V_64 [ V_366 ] ||
V_64 [ V_367 ] )
return - V_113 ;
F_233 ( V_3 , V_64 ) ;
return 0 ;
}
static void F_235 ( struct V_1 * V_76 )
{
int V_181 ;
while ( V_76 -> V_26 . V_14 ) {
struct V_13 * V_14 = F_6 ( V_76 -> V_26 . V_14 ) ;
F_129 ( V_76 -> V_26 . V_14 , V_14 -> V_184 ) ;
F_126 ( V_14 ) ;
}
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
struct V_20 * V_8 = F_6 ( V_76 -> V_26 . V_28 . V_8 [ V_181 ] ) ;
if ( V_8 ) {
F_127 ( V_76 -> V_26 . V_28 . V_8 [ V_181 ] , NULL ) ;
F_135 ( V_8 ) ;
}
}
}
static void F_236 ( struct V_2 * V_3 , struct V_368 * V_12 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
F_237 ( V_3 , V_12 ) ;
F_238 ( & V_76 -> V_369 ) ;
F_235 ( V_76 ) ;
F_239 ( V_77 , V_3 ) ;
V_314 ++ ;
}
static void F_240 ( struct V_2 * V_3 , struct V_368 * V_12 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 = V_76 -> V_77 ;
struct V_4 * V_156 = F_5 ( V_77 ) ;
F_236 ( V_3 , V_12 ) ;
if ( F_241 ( & V_156 -> V_369 ) ) {
F_242 ( V_77 ) ;
F_12 ( V_156 ) ;
}
}
static int F_243 ( struct V_2 * V_77 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_4 * V_156 = F_5 ( V_77 ) ;
if ( ! V_156 ) {
int V_96 ;
V_156 = F_63 ( sizeof( * V_156 ) , V_186 ) ;
if ( ! V_156 )
return - V_117 ;
F_244 ( & V_156 -> V_369 ) ;
V_96 = F_245 ( V_77 , F_113 ,
V_156 ) ;
if ( V_96 < 0 ) {
F_12 ( V_156 ) ;
return V_96 ;
}
}
F_246 ( & V_76 -> V_369 , & V_156 -> V_369 ) ;
return 0 ;
}
static bool F_247 ( struct V_2 * V_3 , T_2 V_34 )
{
struct V_4 * V_156 = F_5 ( V_3 ) ;
struct V_1 * V_76 ;
F_131 (macsec, &rxd->secys, secys) {
if ( V_76 -> V_26 . V_34 == V_34 )
return true ;
}
return false ;
}
static T_2 F_248 ( struct V_2 * V_3 , T_4 V_33 )
{
return F_26 ( V_3 -> V_323 , V_33 ) ;
}
static int F_249 ( struct V_2 * V_3 , T_2 V_34 , T_3 V_57 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_25 * V_26 = & V_76 -> V_26 ;
V_76 -> V_15 = F_133 ( struct V_120 ) ;
if ( ! V_76 -> V_15 )
return - V_117 ;
V_26 -> V_28 . V_15 = F_133 ( struct V_79 ) ;
if ( ! V_26 -> V_28 . V_15 ) {
F_11 ( V_76 -> V_15 ) ;
return - V_117 ;
}
if ( V_34 == V_223 )
V_34 = F_248 ( V_3 , V_42 ) ;
V_26 -> V_151 = V_3 ;
V_26 -> V_75 = true ;
V_26 -> V_177 = V_370 ;
V_26 -> V_57 = V_57 ;
V_26 -> V_131 = V_371 ;
V_26 -> V_74 = true ;
V_26 -> V_129 = false ;
V_26 -> V_34 = V_34 ;
V_26 -> V_28 . V_9 = true ;
V_26 -> V_28 . V_60 = V_372 ;
V_26 -> V_28 . V_55 = V_373 ;
V_26 -> V_28 . F_25 = V_374 ;
V_26 -> V_28 . V_30 = false ;
V_26 -> V_28 . V_31 = false ;
return 0 ;
}
static int F_250 ( struct V_188 * V_188 , struct V_2 * V_3 ,
struct V_189 * V_363 [] , struct V_189 * V_64 [] )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_2 * V_77 ;
int V_96 ;
T_2 V_34 ;
T_3 V_57 = V_58 ;
T_12 * V_375 ;
if ( ! V_363 [ V_376 ] )
return - V_113 ;
V_77 = F_138 ( V_188 , F_137 ( V_363 [ V_376 ] ) ) ;
if ( ! V_77 )
return - V_193 ;
V_3 -> V_348 |= V_377 ;
V_76 -> V_77 = V_77 ;
if ( V_64 && V_64 [ V_365 ] )
V_57 = F_145 ( V_64 [ V_365 ] ) ;
V_3 -> V_119 = V_77 -> V_119 - V_57 - F_30 ( true ) ;
V_375 = F_6 ( V_77 -> V_375 ) ;
if ( V_375 && V_375 != F_113 )
return - V_220 ;
V_96 = F_251 ( V_3 ) ;
if ( V_96 < 0 )
return V_96 ;
F_82 ( V_77 ) ;
V_76 -> V_344 = F_252 ( V_77 ) + 1 ;
F_253 ( V_3 ) ;
F_254 ( & V_3 -> V_378 ,
& V_379 ,
F_226 ( V_3 ) ) ;
V_96 = F_255 ( V_77 , V_3 ) ;
if ( V_96 < 0 )
goto V_380;
if ( V_64 && V_64 [ V_366 ] )
V_34 = F_140 ( V_64 [ V_366 ] ) ;
else if ( V_64 && V_64 [ V_367 ] )
V_34 = F_248 ( V_3 , F_256 ( V_64 [ V_367 ] ) ) ;
else
V_34 = F_248 ( V_3 , V_42 ) ;
if ( V_375 && F_247 ( V_77 , V_34 ) ) {
V_96 = - V_220 ;
goto V_381;
}
V_96 = F_249 ( V_3 , V_34 , V_57 ) ;
if ( V_96 )
goto V_381;
if ( V_64 )
F_233 ( V_3 , V_64 ) ;
V_96 = F_243 ( V_77 , V_3 ) ;
if ( V_96 < 0 )
goto V_382;
V_314 ++ ;
return 0 ;
V_382:
F_235 ( V_76 ) ;
V_381:
F_239 ( V_77 , V_3 ) ;
V_380:
F_257 ( V_3 ) ;
return V_96 ;
}
static int F_258 ( struct V_189 * V_363 [] , struct V_189 * V_64 [] )
{
V_199 V_383 = V_272 ;
T_3 V_57 = V_58 ;
int V_384 ;
bool V_385 , V_31 , V_34 ;
if ( ! V_64 )
return 0 ;
if ( V_64 [ V_364 ] )
V_383 = F_141 ( V_64 [ V_364 ] ) ;
if ( V_64 [ V_365 ] ) {
V_57 = F_145 ( V_64 [ V_365 ] ) ;
if ( V_57 != V_58 ) {
char V_386 [ V_370 ] = { 0 } ;
struct V_99 * V_387 ;
V_387 = F_117 ( V_386 ,
V_370 ,
V_57 ) ;
if ( F_115 ( V_387 ) )
return F_116 ( V_387 ) ;
F_18 ( V_387 ) ;
}
}
switch ( V_383 ) {
case V_272 :
case V_388 :
if ( V_57 < V_389 ||
V_57 > V_390 )
return - V_113 ;
break;
default:
return - V_113 ;
}
if ( V_64 [ V_354 ] ) {
if ( F_145 ( V_64 [ V_354 ] ) >= V_182 )
return - V_113 ;
}
for ( V_384 = V_354 + 1 ;
V_384 < V_362 ;
V_384 ++ ) {
if ( V_64 [ V_384 ] ) {
if ( F_145 ( V_64 [ V_384 ] ) > 1 )
return - V_113 ;
}
}
V_385 = V_64 [ V_359 ] ? F_145 ( V_64 [ V_359 ] ) : false ;
V_34 = V_64 [ V_358 ] ? F_145 ( V_64 [ V_358 ] ) : false ;
V_31 = V_64 [ V_360 ] ? F_145 ( V_64 [ V_360 ] ) : false ;
if ( ( V_34 && ( V_31 || V_385 ) ) || ( V_31 && V_385 ) )
return - V_113 ;
if ( V_64 [ V_362 ] &&
F_145 ( V_64 [ V_362 ] ) > V_391 )
return - V_113 ;
if ( ( V_64 [ V_361 ] &&
F_145 ( V_64 [ V_361 ] ) ) &&
! V_64 [ V_355 ] )
return - V_113 ;
return 0 ;
}
static struct V_188 * F_259 ( const struct V_2 * V_3 )
{
return F_260 ( F_1 ( V_3 ) -> V_77 ) ;
}
static T_6 F_261 ( const struct V_2 * V_3 )
{
return F_262 ( 8 ) +
F_263 ( 1 ) +
F_262 ( 8 ) +
F_263 ( 4 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
F_263 ( 1 ) +
0 ;
}
static int F_264 ( struct V_22 * V_23 ,
const struct V_2 * V_3 )
{
struct V_25 * V_26 = & F_1 ( V_3 ) -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
if ( F_142 ( V_23 , V_366 , V_26 -> V_34 ,
V_392 ) ||
F_184 ( V_23 , V_365 , V_26 -> V_57 ) ||
F_143 ( V_23 , V_364 ,
V_272 , V_392 ) ||
F_184 ( V_23 , V_354 , V_28 -> V_60 ) ||
F_184 ( V_23 , V_356 , V_28 -> V_55 ) ||
F_184 ( V_23 , V_357 , V_26 -> V_74 ) ||
F_184 ( V_23 , V_358 , V_28 -> F_25 ) ||
F_184 ( V_23 , V_359 , V_28 -> V_30 ) ||
F_184 ( V_23 , V_360 , V_28 -> V_31 ) ||
F_184 ( V_23 , V_361 , V_26 -> V_129 ) ||
F_184 ( V_23 , V_362 , V_26 -> V_131 ) ||
0 )
goto V_296;
if ( V_26 -> V_129 ) {
if ( F_175 ( V_23 , V_355 , V_26 -> V_128 ) )
goto V_296;
}
return 0 ;
V_296:
return - V_230 ;
}
static bool F_265 ( struct V_2 * V_3 )
{
return F_266 ( V_3 -> V_375 ) == F_113 ;
}
static int F_267 ( struct V_393 * V_394 , unsigned long V_395 ,
void * V_7 )
{
struct V_2 * V_77 = F_268 ( V_7 ) ;
F_269 ( V_12 ) ;
if ( ! F_265 ( V_77 ) )
return V_396 ;
switch ( V_395 ) {
case V_397 : {
struct V_1 * V_398 , * V_399 ;
struct V_4 * V_156 ;
V_156 = F_5 ( V_77 ) ;
F_270 (m, n, &rxd->secys, secys) {
F_236 ( V_398 -> V_26 . V_151 , & V_12 ) ;
}
F_242 ( V_77 ) ;
F_12 ( V_156 ) ;
F_271 ( & V_12 ) ;
break;
}
case V_400 : {
struct V_1 * V_398 ;
struct V_4 * V_156 ;
V_156 = F_5 ( V_77 ) ;
F_131 (m, &rxd->secys, secys) {
struct V_2 * V_3 = V_398 -> V_26 . V_151 ;
unsigned int V_119 = V_77 -> V_119 - ( V_398 -> V_26 . V_57 +
F_30 ( true ) ) ;
if ( V_3 -> V_119 > V_119 )
F_272 ( V_3 , V_119 ) ;
}
}
}
return V_401 ;
}
static int T_13 F_273 ( void )
{
int V_96 ;
F_274 ( L_5 ) ;
V_96 = F_275 ( & V_402 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_276 ( & V_403 ) ;
if ( V_96 )
goto V_404;
V_96 = F_277 ( & V_293 ) ;
if ( V_96 )
goto V_405;
return 0 ;
V_405:
F_278 ( & V_403 ) ;
V_404:
F_279 ( & V_402 ) ;
return V_96 ;
}
static void T_14 F_280 ( void )
{
F_281 ( & V_293 ) ;
F_278 ( & V_403 ) ;
F_279 ( & V_402 ) ;
F_282 () ;
}
