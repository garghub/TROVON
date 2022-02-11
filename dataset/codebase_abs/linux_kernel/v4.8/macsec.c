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
static T_2 F_25 ( T_3 * V_25 , T_4 V_26 )
{
T_2 V_27 ;
memcpy ( & V_27 , V_25 , V_28 ) ;
memcpy ( ( ( char * ) & V_27 ) + V_28 , & V_26 , sizeof( V_26 ) ) ;
return V_27 ;
}
static T_2 F_26 ( struct V_29 * V_30 , bool V_31 )
{
T_2 V_27 ;
if ( V_31 )
memcpy ( & V_27 , V_30 -> V_32 ,
sizeof( V_30 -> V_32 ) ) ;
else
V_27 = F_25 ( V_30 -> V_33 . V_34 , V_35 ) ;
return V_27 ;
}
static unsigned int F_27 ( bool V_31 )
{
return V_36 + ( V_31 ? V_37 : 0 ) ;
}
static unsigned int F_28 ( bool V_31 )
{
return F_27 ( V_31 ) + V_38 ;
}
static unsigned int F_29 ( bool V_31 )
{
return F_27 ( V_31 ) + sizeof( T_4 ) ;
}
static void F_30 ( struct V_29 * V_39 ,
const struct V_40 * V_41 , T_5 V_42 )
{
const struct V_43 * V_44 = & V_41 -> V_44 ;
memset ( & V_39 -> V_45 , 0 , F_27 ( V_44 -> V_46 ) ) ;
V_39 -> V_33 . V_47 = F_31 ( V_48 ) ;
if ( V_44 -> V_46 ||
( V_41 -> V_49 > 1 && ! V_44 -> V_50 && ! V_44 -> V_51 ) ) {
V_39 -> V_45 |= V_52 ;
memcpy ( & V_39 -> V_32 , & V_41 -> V_27 ,
sizeof( V_39 -> V_32 ) ) ;
} else {
if ( V_44 -> V_50 )
V_39 -> V_45 |= V_53 ;
if ( V_44 -> V_51 )
V_39 -> V_45 |= V_54 ;
}
V_39 -> V_55 = F_32 ( V_42 ) ;
if ( V_44 -> V_56 )
V_39 -> V_45 |= V_57 ;
else if ( V_41 -> V_58 != V_59 )
V_39 -> V_45 |= V_60 ;
V_39 -> V_45 |= V_44 -> V_61 ;
}
static void F_33 ( struct V_29 * V_39 , T_6 V_62 )
{
if ( V_62 < V_63 )
V_39 -> V_64 = V_62 ;
}
static bool F_34 ( struct V_22 * V_23 , T_7 V_58 )
{
struct V_29 * V_39 = (struct V_29 * ) V_23 -> V_65 ;
int V_66 = V_23 -> V_66 - 2 * V_28 ;
int V_67 = F_29 ( ! ! ( V_39 -> V_45 & V_52 ) ) + V_58 ;
if ( V_23 -> V_66 <= 16 )
return false ;
if ( V_39 -> V_45 & V_68 )
return false ;
if ( ( V_39 -> V_45 & V_53 || V_39 -> V_45 & V_54 ) &&
( V_39 -> V_45 & V_52 ) )
return false ;
if ( V_39 -> V_69 )
return false ;
if ( ! V_39 -> V_55 )
return false ;
if ( V_39 -> V_64 )
return V_66 == V_67 + V_39 -> V_64 ;
return V_66 >= V_67 + V_63 ;
}
static void F_35 ( unsigned char * V_70 , T_2 V_27 , T_5 V_42 )
{
struct V_71 * V_71 = (struct V_71 * ) V_70 ;
V_71 -> V_27 = V_27 ;
V_71 -> V_42 = F_32 ( V_42 ) ;
}
static struct V_29 * F_36 ( struct V_22 * V_23 )
{
return (struct V_29 * ) F_37 ( V_23 ) ;
}
static T_5 F_38 ( struct V_20 * V_72 , struct V_40 * V_41 )
{
T_5 V_42 ;
F_39 ( & V_72 -> V_73 ) ;
V_42 = V_72 -> V_74 ;
V_72 -> V_74 ++ ;
if ( V_72 -> V_74 == 0 ) {
F_40 ( L_1 ) ;
V_72 -> V_9 = false ;
if ( V_41 -> V_75 )
V_41 -> V_76 = false ;
}
F_41 ( & V_72 -> V_73 ) ;
return V_42 ;
}
static void F_42 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_1 * V_77 = F_2 ( V_3 ) ;
V_23 -> V_3 = V_77 -> V_78 ;
F_43 ( V_23 ) ;
V_23 -> V_79 = F_44 ( V_23 ) -> V_47 ;
}
static void F_45 ( struct V_22 * V_23 , struct V_43 * V_44 ,
struct V_20 * V_72 )
{
struct V_80 * V_81 = F_46 ( V_44 -> V_15 ) ;
F_47 ( & V_81 -> V_82 ) ;
if ( V_44 -> V_56 ) {
V_81 -> V_15 . V_83 += V_23 -> V_66 ;
V_81 -> V_15 . V_84 ++ ;
F_48 ( V_72 -> V_15 -> V_84 ) ;
} else {
V_81 -> V_15 . V_85 += V_23 -> V_66 ;
V_81 -> V_15 . V_86 ++ ;
F_48 ( V_72 -> V_15 -> V_86 ) ;
}
F_49 ( & V_81 -> V_82 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_87 , int V_66 )
{
if ( F_51 ( V_87 == V_88 || V_87 == V_89 ) ) {
struct V_90 * V_15 = F_46 ( V_3 -> V_91 ) ;
F_47 ( & V_15 -> V_82 ) ;
V_15 -> V_92 ++ ;
V_15 -> V_93 += V_66 ;
F_49 ( & V_15 -> V_82 ) ;
} else {
V_3 -> V_15 . V_94 ++ ;
}
}
static void F_52 ( struct V_95 * V_96 , int V_97 )
{
struct V_22 * V_23 = V_96 -> V_65 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_20 * V_8 = F_23 ( V_23 ) -> V_72 ;
int V_66 , V_87 ;
F_53 ( F_23 ( V_23 ) -> V_98 ) ;
F_54 () ;
F_42 ( V_23 , V_3 ) ;
F_45 ( V_23 , & V_77 -> V_41 . V_44 , F_23 ( V_23 ) -> V_72 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
F_56 () ;
F_22 ( V_8 ) ;
F_57 ( V_3 ) ;
}
static struct V_99 * F_58 ( struct V_100 * V_19 ,
unsigned char * * V_70 ,
struct V_101 * * V_102 )
{
T_6 V_103 , V_104 , V_105 ;
struct V_99 * V_98 ;
void * V_106 ;
V_103 = sizeof( struct V_99 ) + F_59 ( V_19 ) ;
V_104 = V_103 ;
V_103 += V_107 ;
V_103 = F_60 ( V_103 , F_61 ( struct V_101 ) ) ;
V_105 = V_103 ;
V_103 += sizeof( struct V_101 ) * ( V_108 + 1 ) ;
V_106 = F_62 ( V_103 , V_109 ) ;
if ( ! V_106 )
return NULL ;
* V_70 = ( unsigned char * ) ( V_106 + V_104 ) ;
* V_102 = (struct V_101 * ) ( V_106 + V_105 ) ;
V_98 = V_106 ;
F_63 ( V_98 , V_19 ) ;
return V_98 ;
}
static struct V_22 * F_64 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
int V_87 ;
struct V_101 * V_102 ;
unsigned char * V_70 ;
struct V_110 * V_33 ;
struct V_29 * V_111 ;
T_6 V_112 ;
struct V_99 * V_98 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
T_5 V_42 ;
V_41 = & V_77 -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_72 = F_20 ( V_44 -> V_8 [ V_44 -> V_61 ] ) ;
if ( ! V_72 ) {
V_41 -> V_76 = false ;
F_65 ( V_23 ) ;
return F_66 ( - V_113 ) ;
}
if ( F_67 ( F_68 ( V_23 ) < V_114 ||
F_69 ( V_23 ) < V_115 ) ) {
struct V_22 * V_116 = F_70 ( V_23 ,
V_114 ,
V_115 ,
V_109 ) ;
if ( F_51 ( V_116 ) ) {
F_71 ( V_23 ) ;
V_23 = V_116 ;
} else {
F_22 ( V_72 ) ;
F_65 ( V_23 ) ;
return F_66 ( - V_117 ) ;
}
} else {
V_23 = F_72 ( V_23 , V_109 ) ;
if ( ! V_23 ) {
F_22 ( V_72 ) ;
return F_66 ( - V_117 ) ;
}
}
V_112 = V_23 -> V_66 ;
V_33 = F_44 ( V_23 ) ;
V_111 = (struct V_29 * ) F_73 ( V_23 , F_29 ( V_44 -> V_46 ) ) ;
memmove ( V_111 , V_33 , 2 * V_28 ) ;
V_42 = F_38 ( V_72 , V_41 ) ;
if ( V_42 == 0 ) {
F_22 ( V_72 ) ;
F_65 ( V_23 ) ;
return F_66 ( - V_118 ) ;
}
F_30 ( V_111 , V_41 , V_42 ) ;
F_33 ( V_111 , V_112 - 2 * V_28 ) ;
F_74 ( V_23 , V_41 -> V_58 ) ;
if ( V_23 -> V_66 - V_38 > F_1 ( V_3 ) -> V_78 -> V_119 ) {
struct V_120 * V_121 = F_46 ( V_77 -> V_15 ) ;
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_122 ++ ;
F_49 ( & V_121 -> V_82 ) ;
F_22 ( V_72 ) ;
F_65 ( V_23 ) ;
return F_66 ( - V_113 ) ;
}
V_98 = F_58 ( V_72 -> V_18 . V_19 , & V_70 , & V_102 ) ;
if ( ! V_98 ) {
F_22 ( V_72 ) ;
F_65 ( V_23 ) ;
return F_66 ( - V_117 ) ;
}
F_35 ( V_70 , V_41 -> V_27 , V_42 ) ;
F_75 ( V_102 , V_108 + 1 ) ;
F_76 ( V_23 , V_102 , 0 , V_23 -> V_66 ) ;
if ( V_44 -> V_56 ) {
int V_66 = V_23 -> V_66 - F_28 ( V_44 -> V_46 ) -
V_41 -> V_58 ;
F_77 ( V_98 , V_102 , V_102 , V_66 , V_70 ) ;
F_78 ( V_98 , F_28 ( V_44 -> V_46 ) ) ;
} else {
F_77 ( V_98 , V_102 , V_102 , 0 , V_70 ) ;
F_78 ( V_98 , V_23 -> V_66 - V_41 -> V_58 ) ;
}
F_23 ( V_23 ) -> V_98 = V_98 ;
F_23 ( V_23 ) -> V_72 = V_72 ;
F_79 ( V_98 , 0 , F_52 , V_23 ) ;
F_80 ( V_23 -> V_3 ) ;
V_87 = F_81 ( V_98 ) ;
if ( V_87 == - V_123 ) {
return F_66 ( V_87 ) ;
} else if ( V_87 != 0 ) {
F_57 ( V_23 -> V_3 ) ;
F_65 ( V_23 ) ;
F_53 ( V_98 ) ;
F_22 ( V_72 ) ;
return F_66 ( - V_113 ) ;
}
F_57 ( V_23 -> V_3 ) ;
F_53 ( V_98 ) ;
F_22 ( V_72 ) ;
return V_23 ;
}
static bool F_82 ( struct V_22 * V_23 , struct V_40 * V_41 , T_5 V_42 )
{
struct V_6 * V_124 = F_23 ( V_23 ) -> V_124 ;
struct V_125 * V_126 = F_46 ( V_124 -> V_16 -> V_15 ) ;
struct V_29 * V_30 = F_36 ( V_23 ) ;
T_5 V_127 = 0 ;
F_83 ( & V_124 -> V_73 ) ;
if ( V_124 -> V_74 >= V_41 -> V_128 )
V_127 = V_124 -> V_74 - V_41 -> V_128 ;
if ( V_41 -> V_129 && V_42 < V_127 ) {
F_84 ( & V_124 -> V_73 ) ;
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_130 ++ ;
F_49 ( & V_126 -> V_82 ) ;
return false ;
}
if ( V_41 -> V_131 != V_132 ) {
F_47 ( & V_126 -> V_82 ) ;
if ( V_30 -> V_45 & V_133 )
V_126 -> V_15 . V_134 += V_23 -> V_66 ;
else
V_126 -> V_15 . V_135 += V_23 -> V_66 ;
F_49 ( & V_126 -> V_82 ) ;
}
if ( ! F_23 ( V_23 ) -> V_136 ) {
F_84 ( & V_124 -> V_73 ) ;
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_131 == V_137 ) {
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_138 ++ ;
F_49 ( & V_126 -> V_82 ) ;
return false ;
}
F_47 ( & V_126 -> V_82 ) ;
if ( V_41 -> V_131 == V_139 ) {
V_126 -> V_15 . V_140 ++ ;
F_48 ( V_124 -> V_15 -> V_140 ) ;
} else if ( V_42 < V_127 ) {
V_126 -> V_15 . V_141 ++ ;
} else {
V_126 -> V_15 . V_142 ++ ;
}
F_49 ( & V_126 -> V_82 ) ;
} else {
F_47 ( & V_126 -> V_82 ) ;
if ( V_42 < V_127 ) {
V_126 -> V_15 . V_141 ++ ;
} else {
V_126 -> V_15 . V_143 ++ ;
F_48 ( V_124 -> V_15 -> V_143 ) ;
}
F_49 ( & V_126 -> V_82 ) ;
if ( V_42 >= V_124 -> V_74 )
V_124 -> V_74 = V_42 + 1 ;
F_84 ( & V_124 -> V_73 ) ;
}
return true ;
}
static void F_85 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
V_23 -> V_144 = V_145 ;
V_23 -> V_79 = F_86 ( V_23 , V_3 ) ;
F_87 ( V_23 ) ;
if ( ! F_88 ( V_23 ) )
F_89 ( V_23 ) ;
F_90 ( V_23 ) ;
}
static void F_91 ( struct V_22 * V_23 , T_3 V_58 , T_3 V_146 )
{
memmove ( V_23 -> V_65 + V_146 , V_23 -> V_65 , 2 * V_28 ) ;
F_92 ( V_23 , V_146 ) ;
F_93 ( V_23 , V_23 -> V_66 - V_58 ) ;
}
static void F_94 ( struct V_2 * V_3 , int V_66 )
{
struct V_90 * V_15 = F_46 ( V_3 -> V_91 ) ;
F_47 ( & V_15 -> V_82 ) ;
V_15 -> V_147 ++ ;
V_15 -> V_148 += V_66 ;
F_49 ( & V_15 -> V_82 ) ;
}
static void F_95 ( struct V_95 * V_96 , int V_97 )
{
struct V_22 * V_23 = V_96 -> V_65 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_124 = F_23 ( V_23 ) -> V_124 ;
struct V_13 * V_14 = V_124 -> V_16 ;
int V_66 , V_87 ;
T_5 V_42 ;
F_53 ( F_23 ( V_23 ) -> V_98 ) ;
F_54 () ;
V_42 = F_96 ( F_36 ( V_23 ) -> V_55 ) ;
if ( ! F_82 ( V_23 , & V_77 -> V_41 , V_42 ) ) {
F_56 () ;
F_65 ( V_23 ) ;
goto V_149;
}
F_91 ( V_23 , V_77 -> V_41 . V_58 ,
F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_85 ( V_23 , V_77 -> V_41 . V_151 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_97 ( & V_77 -> V_152 , V_23 ) ;
if ( V_87 == V_153 )
F_94 ( V_3 , V_66 ) ;
else
V_77 -> V_41 . V_151 -> V_15 . V_154 ++ ;
F_56 () ;
V_149:
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
F_57 ( V_3 ) ;
}
static struct V_22 * F_98 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
struct V_6 * V_124 ,
T_2 V_27 ,
struct V_40 * V_41 )
{
int V_87 ;
struct V_101 * V_102 ;
unsigned char * V_70 ;
struct V_99 * V_98 ;
struct V_29 * V_30 ;
T_7 V_58 = V_41 -> V_58 ;
F_23 ( V_23 ) -> V_136 = false ;
V_23 = F_99 ( V_23 , V_109 ) ;
if ( ! V_23 )
return F_66 ( - V_117 ) ;
V_98 = F_58 ( V_124 -> V_18 . V_19 , & V_70 , & V_102 ) ;
if ( ! V_98 ) {
F_65 ( V_23 ) ;
return F_66 ( - V_117 ) ;
}
V_30 = (struct V_29 * ) V_23 -> V_65 ;
F_35 ( V_70 , V_27 , F_96 ( V_30 -> V_55 ) ) ;
F_75 ( V_102 , V_108 + 1 ) ;
F_76 ( V_23 , V_102 , 0 , V_23 -> V_66 ) ;
if ( V_30 -> V_45 & V_133 ) {
int V_66 = V_23 -> V_66 - F_28 ( F_23 ( V_23 ) -> V_150 ) ;
F_77 ( V_98 , V_102 , V_102 , V_66 , V_70 ) ;
F_78 ( V_98 , F_28 ( F_23 ( V_23 ) -> V_150 ) ) ;
V_23 = F_72 ( V_23 , V_109 ) ;
if ( ! V_23 ) {
F_53 ( V_98 ) ;
return F_66 ( - V_117 ) ;
}
} else {
F_77 ( V_98 , V_102 , V_102 , V_58 , V_70 ) ;
F_78 ( V_98 , V_23 -> V_66 - V_58 ) ;
}
F_23 ( V_23 ) -> V_98 = V_98 ;
V_23 -> V_3 = V_3 ;
F_79 ( V_98 , 0 , F_95 , V_23 ) ;
F_80 ( V_3 ) ;
V_87 = F_100 ( V_98 ) ;
if ( V_87 == - V_123 ) {
return F_66 ( V_87 ) ;
} else if ( V_87 != 0 ) {
if ( V_87 != - V_155 ) {
F_65 ( V_23 ) ;
V_23 = F_66 ( V_87 ) ;
}
} else {
F_23 ( V_23 ) -> V_136 = true ;
}
F_57 ( V_3 ) ;
F_53 ( V_98 ) ;
return V_23 ;
}
static struct V_13 * F_101 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 ;
F_102 (secy, rx_sc) {
if ( V_14 -> V_27 == V_27 )
return V_14 ;
}
return NULL ;
}
static struct V_13 * F_103 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 ;
F_104 (secy, rx_sc) {
if ( V_14 -> V_27 == V_27 )
return V_14 ;
}
return NULL ;
}
static void F_105 ( struct V_22 * V_23 )
{
struct V_4 * V_156 ;
struct V_1 * V_77 ;
F_106 () ;
V_156 = F_3 ( V_23 -> V_3 ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
int V_87 ;
struct V_120 * V_121 = F_46 ( V_77 -> V_15 ) ;
if ( V_77 -> V_41 . V_131 == V_137 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_157 ++ ;
F_49 ( & V_121 -> V_82 ) ;
continue;
}
V_116 = F_108 ( V_23 , V_109 ) ;
if ( ! V_116 )
break;
V_116 -> V_3 = V_77 -> V_41 . V_151 ;
V_87 = F_109 ( V_116 ) ;
if ( V_87 == V_153 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_158 ++ ;
F_49 ( & V_121 -> V_82 ) ;
} else {
V_77 -> V_41 . V_151 -> V_15 . V_154 ++ ;
}
}
F_110 () ;
}
static T_8 F_111 ( struct V_22 * * V_159 )
{
struct V_22 * V_23 = * V_159 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_29 * V_30 ;
struct V_40 * V_41 = NULL ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
struct V_4 * V_156 ;
struct V_1 * V_77 ;
T_2 V_27 ;
T_5 V_42 ;
bool V_160 ;
struct V_125 * V_126 ;
struct V_120 * V_121 ;
bool V_161 ;
int V_87 ;
if ( F_68 ( V_23 ) < V_38 )
goto V_162;
V_30 = F_36 ( V_23 ) ;
if ( V_30 -> V_33 . V_47 != F_31 ( V_48 ) ) {
F_105 ( V_23 ) ;
return V_163 ;
}
V_23 = F_72 ( V_23 , V_109 ) ;
if ( ! V_23 ) {
* V_159 = NULL ;
return V_164 ;
}
V_161 = F_112 ( V_23 , F_29 ( true ) ) ;
if ( ! V_161 ) {
if ( ! F_112 ( V_23 , F_29 ( false ) ) )
goto V_162;
}
V_30 = F_36 ( V_23 ) ;
if ( ( V_30 -> V_45 & ( V_60 | V_133 ) ) == V_133 )
return V_163 ;
if ( V_30 -> V_45 & V_52 ) {
if ( ! V_161 )
goto V_162;
}
F_73 ( V_23 , V_38 ) ;
F_23 ( V_23 ) -> V_150 = ! ! ( V_30 -> V_45 & V_52 ) ;
F_23 ( V_23 ) -> V_165 = V_30 -> V_45 & V_166 ;
V_27 = F_26 ( V_30 , F_23 ( V_23 ) -> V_150 ) ;
F_106 () ;
V_156 = F_3 ( V_23 -> V_3 ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_13 * V_16 = F_101 ( & V_77 -> V_41 , V_27 ) ;
V_16 = V_16 ? F_13 ( V_16 ) : NULL ;
if ( V_16 ) {
V_41 = & V_77 -> V_41 ;
V_14 = V_16 ;
break;
}
}
if ( ! V_41 )
goto V_167;
V_3 = V_41 -> V_151 ;
V_77 = F_1 ( V_3 ) ;
V_121 = F_46 ( V_77 -> V_15 ) ;
V_126 = F_46 ( V_14 -> V_15 ) ;
if ( ! F_34 ( V_23 , V_41 -> V_58 ) ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_168 ++ ;
F_49 ( & V_121 -> V_82 ) ;
goto V_169;
}
V_124 = F_7 ( V_14 -> V_8 [ F_23 ( V_23 ) -> V_165 ] ) ;
if ( ! V_124 ) {
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_131 == V_137 ) {
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_170 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_169;
}
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_171 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_172;
}
V_42 = F_96 ( V_30 -> V_55 ) ;
if ( V_41 -> V_129 ) {
bool V_173 ;
F_83 ( & V_124 -> V_73 ) ;
V_173 = V_124 -> V_74 >= V_41 -> V_128 &&
V_42 < ( V_124 -> V_74 - V_41 -> V_128 ) ;
F_84 ( & V_124 -> V_73 ) ;
if ( V_173 ) {
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_130 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_174;
}
}
F_23 ( V_23 ) -> V_124 = V_124 ;
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_131 != V_132 )
V_23 = F_98 ( V_23 , V_3 , V_124 , V_27 , V_41 ) ;
if ( F_113 ( V_23 ) ) {
if ( F_114 ( V_23 ) != - V_123 ) {
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
}
F_110 () ;
* V_159 = NULL ;
return V_164 ;
}
if ( ! F_82 ( V_23 , V_41 , V_42 ) )
goto V_174;
V_172:
F_91 ( V_23 , V_41 -> V_58 ,
F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_85 ( V_23 , V_41 -> V_151 ) ;
if ( V_124 )
F_19 ( V_124 ) ;
F_14 ( V_14 ) ;
V_87 = F_97 ( & V_77 -> V_152 , V_23 ) ;
if ( V_87 == V_153 )
F_94 ( V_3 , V_23 -> V_66 ) ;
else
V_77 -> V_41 . V_151 -> V_15 . V_154 ++ ;
F_110 () ;
* V_159 = NULL ;
return V_164 ;
V_174:
F_19 ( V_124 ) ;
V_169:
F_14 ( V_14 ) ;
F_110 () ;
V_162:
F_65 ( V_23 ) ;
* V_159 = NULL ;
return V_164 ;
V_167:
V_160 = ! ! ( V_30 -> V_45 & V_60 ) ;
if ( ! V_160 )
F_91 ( V_23 , V_59 ,
F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
V_121 = F_46 ( V_77 -> V_15 ) ;
if ( V_160 ||
V_77 -> V_41 . V_131 == V_137 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_175 ++ ;
F_49 ( & V_121 -> V_82 ) ;
continue;
}
V_116 = F_108 ( V_23 , V_109 ) ;
if ( ! V_116 )
break;
F_85 ( V_116 , V_77 -> V_41 . V_151 ) ;
V_87 = F_109 ( V_116 ) ;
if ( V_87 == V_153 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_176 ++ ;
F_49 ( & V_121 -> V_82 ) ;
} else {
V_77 -> V_41 . V_151 -> V_15 . V_154 ++ ;
}
}
F_110 () ;
* V_159 = V_23 ;
return V_163 ;
}
static struct V_100 * F_115 ( char * V_18 , int V_177 , int V_58 )
{
struct V_100 * V_19 ;
int V_87 ;
V_19 = F_116 ( L_2 , 0 , 0 ) ;
if ( F_113 ( V_19 ) )
return V_19 ;
V_87 = F_117 ( V_19 , V_18 , V_177 ) ;
if ( V_87 < 0 )
goto V_178;
V_87 = F_118 ( V_19 , V_58 ) ;
if ( V_87 < 0 )
goto V_178;
return V_19 ;
V_178:
F_18 ( V_19 ) ;
return F_66 ( V_87 ) ;
}
static int F_119 ( struct V_6 * V_124 , char * V_179 , int V_177 ,
int V_58 )
{
V_124 -> V_15 = F_120 ( struct V_180 ) ;
if ( ! V_124 -> V_15 )
return - V_117 ;
V_124 -> V_18 . V_19 = F_115 ( V_179 , V_177 , V_58 ) ;
if ( F_113 ( V_124 -> V_18 . V_19 ) ) {
F_11 ( V_124 -> V_15 ) ;
return F_114 ( V_124 -> V_18 . V_19 ) ;
}
V_124 -> V_9 = false ;
V_124 -> V_74 = 1 ;
F_121 ( & V_124 -> V_10 , 1 ) ;
F_122 ( & V_124 -> V_73 ) ;
return 0 ;
}
static void F_123 ( struct V_6 * V_124 )
{
V_124 -> V_9 = false ;
F_19 ( V_124 ) ;
}
static void F_124 ( struct V_13 * V_14 )
{
int V_181 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
struct V_6 * V_8 = F_6 ( V_14 -> V_8 [ V_181 ] ) ;
F_125 ( V_14 -> V_8 [ V_181 ] , NULL ) ;
if ( V_8 )
F_123 ( V_8 ) ;
}
F_14 ( V_14 ) ;
}
static struct V_13 * F_126 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 , T_1 * * V_183 ;
for ( V_183 = & V_41 -> V_14 , V_14 = F_6 ( * V_183 ) ;
V_14 ;
V_183 = & V_14 -> V_184 , V_14 = F_6 ( * V_183 ) ) {
if ( V_14 -> V_27 == V_27 ) {
if ( V_14 -> V_9 )
V_41 -> V_49 -- ;
F_127 ( * V_183 , V_14 -> V_184 ) ;
return V_14 ;
}
}
return NULL ;
}
static struct V_13 * F_128 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_13 * V_14 ;
struct V_1 * V_77 ;
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
struct V_4 * V_156 = F_5 ( V_78 ) ;
struct V_40 * V_41 ;
F_129 (macsec, &rxd->secys, secys) {
if ( F_103 ( & V_77 -> V_41 , V_27 ) )
return F_66 ( - V_185 ) ;
}
V_14 = F_130 ( sizeof( * V_14 ) , V_186 ) ;
if ( ! V_14 )
return F_66 ( - V_117 ) ;
V_14 -> V_15 = F_131 ( struct V_125 ) ;
if ( ! V_14 -> V_15 ) {
F_12 ( V_14 ) ;
return F_66 ( - V_117 ) ;
}
V_14 -> V_27 = V_27 ;
V_14 -> V_9 = true ;
F_121 ( & V_14 -> V_10 , 1 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
F_127 ( V_14 -> V_184 , V_41 -> V_14 ) ;
F_127 ( V_41 -> V_14 , V_14 ) ;
if ( V_14 -> V_9 )
V_41 -> V_49 ++ ;
return V_14 ;
}
static int F_132 ( struct V_20 * V_72 , char * V_179 , int V_177 ,
int V_58 )
{
V_72 -> V_15 = F_120 ( struct V_187 ) ;
if ( ! V_72 -> V_15 )
return - V_117 ;
V_72 -> V_18 . V_19 = F_115 ( V_179 , V_177 , V_58 ) ;
if ( F_113 ( V_72 -> V_18 . V_19 ) ) {
F_11 ( V_72 -> V_15 ) ;
return F_114 ( V_72 -> V_18 . V_19 ) ;
}
V_72 -> V_9 = false ;
F_121 ( & V_72 -> V_10 , 1 ) ;
F_122 ( & V_72 -> V_73 ) ;
return 0 ;
}
static void F_133 ( struct V_20 * V_72 )
{
V_72 -> V_9 = false ;
F_22 ( V_72 ) ;
}
static struct V_2 * F_134 ( struct V_188 * V_188 ,
struct V_189 * * V_190 )
{
int V_191 = F_135 ( V_190 [ V_192 ] ) ;
struct V_2 * V_3 ;
V_3 = F_136 ( V_188 , V_191 ) ;
if ( ! V_3 )
return F_66 ( - V_193 ) ;
if ( ! F_137 ( V_3 ) )
return F_66 ( - V_193 ) ;
return V_3 ;
}
static T_2 F_138 ( const struct V_189 * V_194 )
{
return ( V_195 T_2 ) F_139 ( V_194 ) ;
}
static int F_140 ( struct V_22 * V_23 , int V_196 , T_2 V_197 ,
int V_198 )
{
return F_141 ( V_23 , V_196 , ( V_195 V_199 ) V_197 , V_198 ) ;
}
static struct V_20 * F_142 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_200 ,
struct V_2 * * V_201 ,
struct V_40 * * V_202 ,
struct V_43 * * V_203 ,
T_3 * V_165 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
if ( ! V_200 [ V_204 ] )
return F_66 ( - V_113 ) ;
* V_165 = F_143 ( V_200 [ V_204 ] ) ;
V_3 = F_134 ( V_188 , V_190 ) ;
if ( F_113 ( V_3 ) )
return F_144 ( V_3 ) ;
if ( * V_165 >= V_182 )
return F_66 ( - V_113 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_72 = F_6 ( V_44 -> V_8 [ * V_165 ] ) ;
if ( ! V_72 )
return F_66 ( - V_193 ) ;
* V_201 = V_3 ;
* V_203 = V_44 ;
* V_202 = V_41 ;
return V_72 ;
}
static struct V_13 * F_145 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_205 ,
struct V_2 * * V_201 ,
struct V_40 * * V_202 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
V_3 = F_134 ( V_188 , V_190 ) ;
if ( F_113 ( V_3 ) )
return F_144 ( V_3 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( ! V_205 [ V_206 ] )
return F_66 ( - V_113 ) ;
V_27 = F_138 ( V_205 [ V_206 ] ) ;
V_14 = F_103 ( V_41 , V_27 ) ;
if ( ! V_14 )
return F_66 ( - V_193 ) ;
* V_202 = V_41 ;
* V_201 = V_3 ;
return V_14 ;
}
static struct V_6 * F_146 ( struct V_188 * V_188 ,
struct V_189 * * V_190 ,
struct V_189 * * V_205 ,
struct V_189 * * V_200 ,
struct V_2 * * V_201 ,
struct V_40 * * V_202 ,
struct V_13 * * V_203 ,
T_3 * V_165 )
{
struct V_13 * V_14 ;
struct V_6 * V_124 ;
if ( ! V_200 [ V_204 ] )
return F_66 ( - V_113 ) ;
* V_165 = F_143 ( V_200 [ V_204 ] ) ;
if ( * V_165 >= V_182 )
return F_66 ( - V_113 ) ;
V_14 = F_145 ( V_188 , V_190 , V_205 , V_201 , V_202 ) ;
if ( F_113 ( V_14 ) )
return F_144 ( V_14 ) ;
V_124 = F_6 ( V_14 -> V_8 [ * V_165 ] ) ;
if ( ! V_124 )
return F_66 ( - V_193 ) ;
* V_203 = V_14 ;
return V_124 ;
}
static int F_147 ( struct V_189 * * V_190 , struct V_189 * * V_200 )
{
if ( ! V_190 [ V_207 ] )
return - V_113 ;
if ( F_148 ( V_200 , V_208 , V_190 [ V_207 ] ,
V_209 ) )
return - V_113 ;
return 0 ;
}
static int F_149 ( struct V_189 * * V_190 , struct V_189 * * V_205 )
{
if ( ! V_190 [ V_210 ] )
return - V_113 ;
if ( F_148 ( V_205 , V_211 , V_190 [ V_210 ] ,
V_212 ) )
return - V_113 ;
return 0 ;
}
static bool F_150 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
! V_190 [ V_213 ] ||
! V_190 [ V_214 ] )
return false ;
if ( F_143 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( V_190 [ V_215 ] && F_135 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_143 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
if ( F_151 ( V_190 [ V_214 ] ) != V_217 )
return false ;
return true ;
}
static int F_152 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
unsigned char V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
int V_97 ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_150 ( V_200 ) )
return - V_113 ;
F_153 () ;
V_14 = F_145 ( F_154 ( V_219 ) , V_190 , V_205 , & V_3 , & V_41 ) ;
if ( F_113 ( V_14 ) ) {
F_155 () ;
return F_114 ( V_14 ) ;
}
V_165 = F_143 ( V_200 [ V_204 ] ) ;
if ( F_151 ( V_200 [ V_213 ] ) != V_41 -> V_177 ) {
F_156 ( L_3 ,
F_151 ( V_200 [ V_213 ] ) , V_41 -> V_177 ) ;
F_155 () ;
return - V_113 ;
}
V_124 = F_6 ( V_14 -> V_8 [ V_165 ] ) ;
if ( V_124 ) {
F_155 () ;
return - V_220 ;
}
V_124 = F_62 ( sizeof( * V_124 ) , V_186 ) ;
if ( ! V_124 ) {
F_155 () ;
return - V_117 ;
}
V_97 = F_119 ( V_124 , F_157 ( V_200 [ V_213 ] ) ,
V_41 -> V_177 , V_41 -> V_58 ) ;
if ( V_97 < 0 ) {
F_12 ( V_124 ) ;
F_155 () ;
return V_97 ;
}
if ( V_200 [ V_215 ] ) {
F_39 ( & V_124 -> V_73 ) ;
V_124 -> V_74 = F_135 ( V_200 [ V_215 ] ) ;
F_41 ( & V_124 -> V_73 ) ;
}
if ( V_200 [ V_216 ] )
V_124 -> V_9 = ! ! F_143 ( V_200 [ V_216 ] ) ;
F_158 ( V_124 -> V_18 . V_221 , V_200 [ V_214 ] , V_217 ) ;
V_124 -> V_16 = V_14 ;
F_127 ( V_14 -> V_8 [ V_165 ] , V_124 ) ;
F_155 () ;
return 0 ;
}
static bool F_159 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_206 ] )
return false ;
if ( V_190 [ V_222 ] ) {
if ( F_143 ( V_190 [ V_222 ] ) > 1 )
return false ;
}
return true ;
}
static int F_160 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
T_2 V_27 = V_223 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_13 * V_14 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_159 ( V_205 ) )
return - V_113 ;
F_153 () ;
V_3 = F_134 ( F_154 ( V_219 ) , V_190 ) ;
if ( F_113 ( V_3 ) ) {
F_155 () ;
return F_114 ( V_3 ) ;
}
V_27 = F_138 ( V_205 [ V_206 ] ) ;
V_14 = F_128 ( V_3 , V_27 ) ;
if ( F_113 ( V_14 ) ) {
F_155 () ;
return F_114 ( V_14 ) ;
}
if ( V_205 [ V_222 ] )
V_14 -> V_9 = ! ! F_143 ( V_205 [ V_222 ] ) ;
F_155 () ;
return 0 ;
}
static bool F_161 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
! V_190 [ V_215 ] ||
! V_190 [ V_213 ] ||
! V_190 [ V_214 ] )
return false ;
if ( F_143 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( F_135 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_143 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
if ( F_151 ( V_190 [ V_214 ] ) != V_217 )
return false ;
return true ;
}
static int F_162 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_2 * V_3 ;
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
unsigned char V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
int V_97 ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_161 ( V_200 ) )
return - V_113 ;
F_153 () ;
V_3 = F_134 ( F_154 ( V_219 ) , V_190 ) ;
if ( F_113 ( V_3 ) ) {
F_155 () ;
return F_114 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_165 = F_143 ( V_200 [ V_204 ] ) ;
if ( F_151 ( V_200 [ V_213 ] ) != V_41 -> V_177 ) {
F_156 ( L_4 ,
F_151 ( V_200 [ V_213 ] ) , V_41 -> V_177 ) ;
F_155 () ;
return - V_113 ;
}
V_72 = F_6 ( V_44 -> V_8 [ V_165 ] ) ;
if ( V_72 ) {
F_155 () ;
return - V_220 ;
}
V_72 = F_62 ( sizeof( * V_72 ) , V_186 ) ;
if ( ! V_72 ) {
F_155 () ;
return - V_117 ;
}
V_97 = F_132 ( V_72 , F_157 ( V_200 [ V_213 ] ) ,
V_41 -> V_177 , V_41 -> V_58 ) ;
if ( V_97 < 0 ) {
F_12 ( V_72 ) ;
F_155 () ;
return V_97 ;
}
F_158 ( V_72 -> V_18 . V_221 , V_200 [ V_214 ] , V_217 ) ;
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_135 ( V_200 [ V_215 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
if ( V_200 [ V_216 ] )
V_72 -> V_9 = ! ! F_143 ( V_200 [ V_216 ] ) ;
if ( V_165 == V_44 -> V_61 && V_72 -> V_9 )
V_41 -> V_76 = true ;
F_127 ( V_44 -> V_8 [ V_165 ] , V_72 ) ;
F_155 () ;
return 0 ;
}
static int F_163 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
F_153 () ;
V_124 = F_146 ( F_154 ( V_219 ) , V_190 , V_205 , V_200 ,
& V_3 , & V_41 , & V_14 , & V_165 ) ;
if ( F_113 ( V_124 ) ) {
F_155 () ;
return F_114 ( V_124 ) ;
}
if ( V_124 -> V_9 ) {
F_155 () ;
return - V_220 ;
}
F_125 ( V_14 -> V_8 [ V_165 ] , NULL ) ;
F_123 ( V_124 ) ;
F_155 () ;
return 0 ;
}
static int F_164 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! V_205 [ V_206 ] )
return - V_113 ;
F_153 () ;
V_3 = F_134 ( F_154 ( V_219 ) , V_219 -> V_190 ) ;
if ( F_113 ( V_3 ) ) {
F_155 () ;
return F_114 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_27 = F_138 ( V_205 [ V_206 ] ) ;
V_14 = F_126 ( V_41 , V_27 ) ;
if ( ! V_14 ) {
F_155 () ;
return - V_193 ;
}
F_124 ( V_14 ) ;
F_155 () ;
return 0 ;
}
static int F_165 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
F_153 () ;
V_72 = F_142 ( F_154 ( V_219 ) , V_190 , V_200 ,
& V_3 , & V_41 , & V_44 , & V_165 ) ;
if ( F_113 ( V_72 ) ) {
F_155 () ;
return F_114 ( V_72 ) ;
}
if ( V_72 -> V_9 ) {
F_155 () ;
return - V_220 ;
}
F_125 ( V_44 -> V_8 [ V_165 ] , NULL ) ;
F_133 ( V_72 ) ;
F_155 () ;
return 0 ;
}
static bool F_166 ( struct V_189 * * V_190 )
{
if ( ! V_190 [ V_204 ] ||
V_190 [ V_213 ] ||
V_190 [ V_214 ] )
return false ;
if ( F_143 ( V_190 [ V_204 ] ) >= V_182 )
return false ;
if ( V_190 [ V_215 ] && F_135 ( V_190 [ V_215 ] ) == 0 )
return false ;
if ( V_190 [ V_216 ] ) {
if ( F_143 ( V_190 [ V_216 ] ) > 1 )
return false ;
}
return true ;
}
static int F_167 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_165 ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_166 ( V_200 ) )
return - V_113 ;
F_153 () ;
V_72 = F_142 ( F_154 ( V_219 ) , V_190 , V_200 ,
& V_3 , & V_41 , & V_44 , & V_165 ) ;
if ( F_113 ( V_72 ) ) {
F_155 () ;
return F_114 ( V_72 ) ;
}
if ( V_200 [ V_215 ] ) {
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_135 ( V_200 [ V_215 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
}
if ( V_200 [ V_216 ] )
V_72 -> V_9 = F_143 ( V_200 [ V_216 ] ) ;
if ( V_165 == V_44 -> V_61 )
V_41 -> V_76 = V_72 -> V_9 ;
F_155 () ;
return 0 ;
}
static int F_168 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_165 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
struct V_189 * V_200 [ V_208 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
if ( F_147 ( V_190 , V_200 ) )
return - V_113 ;
if ( ! F_166 ( V_200 ) )
return - V_113 ;
F_153 () ;
V_124 = F_146 ( F_154 ( V_219 ) , V_190 , V_205 , V_200 ,
& V_3 , & V_41 , & V_14 , & V_165 ) ;
if ( F_113 ( V_124 ) ) {
F_155 () ;
return F_114 ( V_124 ) ;
}
if ( V_200 [ V_215 ] ) {
F_39 ( & V_124 -> V_73 ) ;
V_124 -> V_74 = F_135 ( V_200 [ V_215 ] ) ;
F_41 ( & V_124 -> V_73 ) ;
}
if ( V_200 [ V_216 ] )
V_124 -> V_9 = F_143 ( V_200 [ V_216 ] ) ;
F_155 () ;
return 0 ;
}
static int F_169 ( struct V_22 * V_23 , struct V_218 * V_219 )
{
struct V_189 * * V_190 = V_219 -> V_190 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_189 * V_205 [ V_211 + 1 ] ;
if ( ! V_190 [ V_192 ] )
return - V_113 ;
if ( F_149 ( V_190 , V_205 ) )
return - V_113 ;
if ( ! F_159 ( V_205 ) )
return - V_113 ;
F_153 () ;
V_14 = F_145 ( F_154 ( V_219 ) , V_190 , V_205 , & V_3 , & V_41 ) ;
if ( F_113 ( V_14 ) ) {
F_155 () ;
return F_114 ( V_14 ) ;
}
if ( V_205 [ V_222 ] ) {
bool V_224 = ! ! F_143 ( V_205 [ V_222 ] ) ;
if ( V_14 -> V_9 != V_224 )
V_41 -> V_49 += V_224 ? 1 : - 1 ;
V_14 -> V_9 = V_224 ;
}
F_155 () ;
return 0 ;
}
static int F_170 ( struct V_22 * V_23 ,
struct V_187 T_9 * V_225 )
{
struct V_187 V_226 = { 0 , } ;
int V_227 ;
F_171 (cpu) {
const struct V_187 * V_15 = F_172 ( V_225 , V_227 ) ;
V_226 . V_86 += V_15 -> V_86 ;
V_226 . V_84 += V_15 -> V_84 ;
}
if ( F_173 ( V_23 , V_228 , V_226 . V_86 ) ||
F_173 ( V_23 , V_229 , V_226 . V_84 ) )
return - V_230 ;
return 0 ;
}
static int F_174 ( struct V_22 * V_23 ,
struct V_180 T_9 * V_225 )
{
struct V_180 V_226 = { 0 , } ;
int V_227 ;
F_171 (cpu) {
const struct V_180 * V_15 = F_172 ( V_225 , V_227 ) ;
V_226 . V_143 += V_15 -> V_143 ;
V_226 . V_140 += V_15 -> V_140 ;
V_226 . V_138 += V_15 -> V_138 ;
V_226 . V_170 += V_15 -> V_170 ;
V_226 . V_171 += V_15 -> V_171 ;
}
if ( F_173 ( V_23 , V_231 , V_226 . V_143 ) ||
F_173 ( V_23 , V_232 , V_226 . V_140 ) ||
F_173 ( V_23 , V_233 , V_226 . V_138 ) ||
F_173 ( V_23 , V_234 , V_226 . V_170 ) ||
F_173 ( V_23 , V_235 , V_226 . V_171 ) )
return - V_230 ;
return 0 ;
}
static int F_175 ( struct V_22 * V_23 ,
struct V_125 T_9 * V_225 )
{
struct V_236 V_226 = { 0 , } ;
int V_227 ;
F_171 (cpu) {
const struct V_125 * V_15 ;
struct V_236 V_106 ;
unsigned int V_237 ;
V_15 = F_172 ( V_225 , V_227 ) ;
do {
V_237 = F_176 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_177 ( & V_15 -> V_82 , V_237 ) );
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
if ( F_141 ( V_23 , V_238 ,
V_226 . V_135 ,
V_239 ) ||
F_141 ( V_23 , V_240 ,
V_226 . V_134 ,
V_239 ) ||
F_141 ( V_23 , V_241 ,
V_226 . V_142 ,
V_239 ) ||
F_141 ( V_23 , V_242 ,
V_226 . V_141 ,
V_239 ) ||
F_141 ( V_23 , V_243 ,
V_226 . V_143 ,
V_239 ) ||
F_141 ( V_23 , V_244 ,
V_226 . V_140 ,
V_239 ) ||
F_141 ( V_23 , V_245 ,
V_226 . V_130 ,
V_239 ) ||
F_141 ( V_23 , V_246 ,
V_226 . V_138 ,
V_239 ) ||
F_141 ( V_23 , V_247 ,
V_226 . V_170 ,
V_239 ) ||
F_141 ( V_23 , V_248 ,
V_226 . V_171 ,
V_239 ) )
return - V_230 ;
return 0 ;
}
static int F_178 ( struct V_22 * V_23 ,
struct V_80 T_9 * V_225 )
{
struct V_249 V_226 = { 0 , } ;
int V_227 ;
F_171 (cpu) {
const struct V_80 * V_15 ;
struct V_249 V_106 ;
unsigned int V_237 ;
V_15 = F_172 ( V_225 , V_227 ) ;
do {
V_237 = F_176 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_177 ( & V_15 -> V_82 , V_237 ) );
V_226 . V_86 += V_106 . V_86 ;
V_226 . V_84 += V_106 . V_84 ;
V_226 . V_85 += V_106 . V_85 ;
V_226 . V_83 += V_106 . V_83 ;
}
if ( F_141 ( V_23 , V_250 ,
V_226 . V_86 ,
V_251 ) ||
F_141 ( V_23 , V_252 ,
V_226 . V_84 ,
V_251 ) ||
F_141 ( V_23 , V_253 ,
V_226 . V_85 ,
V_251 ) ||
F_141 ( V_23 , V_254 ,
V_226 . V_83 ,
V_251 ) )
return - V_230 ;
return 0 ;
}
static int F_179 ( struct V_22 * V_23 ,
struct V_120 T_9 * V_225 )
{
struct V_255 V_226 = { 0 , } ;
int V_227 ;
F_171 (cpu) {
const struct V_120 * V_15 ;
struct V_255 V_106 ;
unsigned int V_237 ;
V_15 = F_172 ( V_225 , V_227 ) ;
do {
V_237 = F_176 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_177 ( & V_15 -> V_82 , V_237 ) );
V_226 . V_256 += V_106 . V_256 ;
V_226 . V_158 += V_106 . V_158 ;
V_226 . V_122 += V_106 . V_122 ;
V_226 . V_157 += V_106 . V_157 ;
V_226 . V_168 += V_106 . V_168 ;
V_226 . V_176 += V_106 . V_176 ;
V_226 . V_175 += V_106 . V_175 ;
V_226 . V_257 += V_106 . V_257 ;
}
if ( F_141 ( V_23 , V_258 ,
V_226 . V_256 ,
V_259 ) ||
F_141 ( V_23 , V_260 ,
V_226 . V_158 ,
V_259 ) ||
F_141 ( V_23 , V_261 ,
V_226 . V_122 ,
V_259 ) ||
F_141 ( V_23 , V_262 ,
V_226 . V_157 ,
V_259 ) ||
F_141 ( V_23 , V_263 ,
V_226 . V_168 ,
V_259 ) ||
F_141 ( V_23 , V_264 ,
V_226 . V_176 ,
V_259 ) ||
F_141 ( V_23 , V_265 ,
V_226 . V_175 ,
V_259 ) ||
F_141 ( V_23 , V_266 ,
V_226 . V_257 ,
V_259 ) )
return - V_230 ;
return 0 ;
}
static int F_180 ( struct V_40 * V_41 , struct V_22 * V_23 )
{
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_189 * V_267 = F_181 ( V_23 , V_268 ) ;
if ( ! V_267 )
return 1 ;
if ( F_140 ( V_23 , V_269 , V_41 -> V_27 ,
V_270 ) ||
F_141 ( V_23 , V_271 ,
V_272 ,
V_270 ) ||
F_182 ( V_23 , V_273 , V_41 -> V_58 ) ||
F_182 ( V_23 , V_274 , V_41 -> V_76 ) ||
F_182 ( V_23 , V_275 , V_41 -> V_75 ) ||
F_182 ( V_23 , V_276 , V_41 -> V_129 ) ||
F_182 ( V_23 , V_277 , V_41 -> V_131 ) ||
F_182 ( V_23 , V_278 , V_44 -> V_56 ) ||
F_182 ( V_23 , V_279 , V_44 -> V_46 ) ||
F_182 ( V_23 , V_280 , V_44 -> V_50 ) ||
F_182 ( V_23 , V_281 , V_44 -> V_51 ) ||
F_182 ( V_23 , V_282 , V_44 -> V_61 ) )
goto V_283;
if ( V_41 -> V_129 ) {
if ( F_173 ( V_23 , V_284 , V_41 -> V_128 ) )
goto V_283;
}
F_183 ( V_23 , V_267 ) ;
return 0 ;
V_283:
F_184 ( V_23 , V_267 ) ;
return 1 ;
}
static int F_185 ( struct V_40 * V_41 , struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_285 * V_24 )
{
struct V_13 * V_14 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_189 * V_286 , * V_287 ;
int V_181 , V_288 ;
void * V_30 ;
struct V_189 * V_289 ;
V_30 = F_186 ( V_23 , F_187 ( V_24 -> V_23 ) . V_290 , V_24 -> V_291 -> V_292 ,
& V_293 , V_294 , V_295 ) ;
if ( ! V_30 )
return - V_230 ;
F_188 ( V_24 , V_30 , & V_293 ) ;
if ( F_173 ( V_23 , V_192 , V_3 -> V_191 ) )
goto V_296;
if ( F_180 ( V_41 , V_23 ) )
goto V_296;
V_289 = F_181 ( V_23 , V_297 ) ;
if ( ! V_289 )
goto V_296;
if ( F_178 ( V_23 , V_44 -> V_15 ) ) {
F_184 ( V_23 , V_289 ) ;
goto V_296;
}
F_183 ( V_23 , V_289 ) ;
V_289 = F_181 ( V_23 , V_298 ) ;
if ( ! V_289 )
goto V_296;
if ( F_179 ( V_23 , F_1 ( V_3 ) -> V_15 ) ) {
F_184 ( V_23 , V_289 ) ;
goto V_296;
}
F_183 ( V_23 , V_289 ) ;
V_286 = F_181 ( V_23 , V_299 ) ;
if ( ! V_286 )
goto V_296;
for ( V_181 = 0 , V_288 = 1 ; V_181 < V_182 ; V_181 ++ ) {
struct V_20 * V_72 = F_6 ( V_44 -> V_8 [ V_181 ] ) ;
struct V_189 * V_300 ;
if ( ! V_72 )
continue;
V_300 = F_181 ( V_23 , V_288 ++ ) ;
if ( ! V_300 ) {
F_184 ( V_23 , V_286 ) ;
goto V_296;
}
if ( F_182 ( V_23 , V_204 , V_181 ) ||
F_173 ( V_23 , V_215 , V_72 -> V_74 ) ||
F_189 ( V_23 , V_214 , V_217 , V_72 -> V_18 . V_221 ) ||
F_182 ( V_23 , V_216 , V_72 -> V_9 ) ) {
F_184 ( V_23 , V_300 ) ;
F_184 ( V_23 , V_286 ) ;
goto V_296;
}
V_289 = F_181 ( V_23 , V_301 ) ;
if ( ! V_289 ) {
F_184 ( V_23 , V_300 ) ;
F_184 ( V_23 , V_286 ) ;
goto V_296;
}
if ( F_170 ( V_23 , V_72 -> V_15 ) ) {
F_184 ( V_23 , V_289 ) ;
F_184 ( V_23 , V_300 ) ;
F_184 ( V_23 , V_286 ) ;
goto V_296;
}
F_183 ( V_23 , V_289 ) ;
F_183 ( V_23 , V_300 ) ;
}
F_183 ( V_23 , V_286 ) ;
V_287 = F_181 ( V_23 , V_302 ) ;
if ( ! V_287 )
goto V_296;
V_288 = 1 ;
F_104 (secy, rx_sc) {
int V_303 ;
struct V_189 * V_304 ;
struct V_189 * V_305 = F_181 ( V_23 , V_288 ++ ) ;
if ( ! V_305 ) {
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_182 ( V_23 , V_222 , V_14 -> V_9 ) ||
F_140 ( V_23 , V_206 , V_14 -> V_27 ,
V_306 ) ) {
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
V_289 = F_181 ( V_23 , V_307 ) ;
if ( ! V_289 ) {
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_175 ( V_23 , V_14 -> V_15 ) ) {
F_184 ( V_23 , V_289 ) ;
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
F_183 ( V_23 , V_289 ) ;
V_304 = F_181 ( V_23 , V_308 ) ;
if ( ! V_304 ) {
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
for ( V_181 = 0 , V_303 = 1 ; V_181 < V_182 ; V_181 ++ ) {
struct V_6 * V_124 = F_6 ( V_14 -> V_8 [ V_181 ] ) ;
struct V_189 * V_309 ;
if ( ! V_124 )
continue;
V_309 = F_181 ( V_23 , V_303 ++ ) ;
if ( ! V_309 ) {
F_184 ( V_23 , V_304 ) ;
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
V_289 = F_181 ( V_23 , V_301 ) ;
if ( ! V_289 ) {
F_184 ( V_23 , V_304 ) ;
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
if ( F_174 ( V_23 , V_124 -> V_15 ) ) {
F_184 ( V_23 , V_289 ) ;
F_184 ( V_23 , V_304 ) ;
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
F_183 ( V_23 , V_289 ) ;
if ( F_182 ( V_23 , V_204 , V_181 ) ||
F_173 ( V_23 , V_215 , V_124 -> V_74 ) ||
F_189 ( V_23 , V_214 , V_217 , V_124 -> V_18 . V_221 ) ||
F_182 ( V_23 , V_216 , V_124 -> V_9 ) ) {
F_184 ( V_23 , V_309 ) ;
F_184 ( V_23 , V_305 ) ;
F_184 ( V_23 , V_287 ) ;
goto V_296;
}
F_183 ( V_23 , V_309 ) ;
}
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_305 ) ;
}
F_183 ( V_23 , V_287 ) ;
F_190 ( V_23 , V_30 ) ;
return 0 ;
V_296:
F_191 ( V_23 , V_30 ) ;
return - V_230 ;
}
static int F_192 ( struct V_22 * V_23 , struct V_285 * V_24 )
{
struct V_188 * V_188 = F_193 ( V_23 -> V_310 ) ;
struct V_2 * V_3 ;
int V_311 , V_312 ;
V_311 = V_24 -> args [ 0 ] ;
V_312 = 0 ;
F_153 () ;
V_24 -> V_313 = V_314 ;
F_194 (net, dev) {
struct V_40 * V_41 ;
if ( V_312 < V_311 )
goto V_184;
if ( ! F_137 ( V_3 ) )
goto V_184;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( F_185 ( V_41 , V_3 , V_23 , V_24 ) < 0 )
goto V_315;
V_184:
V_312 ++ ;
}
V_315:
F_155 () ;
V_24 -> args [ 0 ] = V_312 ;
return V_23 -> V_66 ;
}
static T_10 F_195 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_2 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
struct V_120 * V_121 ;
int V_87 , V_66 ;
if ( ! V_41 -> V_75 ) {
V_121 = F_46 ( V_77 -> V_15 ) ;
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_256 ++ ;
F_49 ( & V_121 -> V_82 ) ;
V_23 -> V_3 = V_77 -> V_78 ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
return V_87 ;
}
if ( ! V_41 -> V_76 ) {
F_65 ( V_23 ) ;
V_3 -> V_15 . V_94 ++ ;
return V_316 ;
}
V_23 = F_64 ( V_23 , V_3 ) ;
if ( F_113 ( V_23 ) ) {
if ( F_114 ( V_23 ) != - V_123 )
V_3 -> V_15 . V_94 ++ ;
return V_316 ;
}
F_45 ( V_23 , & V_77 -> V_41 . V_44 , F_23 ( V_23 ) -> V_72 ) ;
F_42 ( V_23 , V_3 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
return V_87 ;
}
static int F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
int V_97 ;
V_3 -> V_91 = F_131 ( struct V_90 ) ;
if ( ! V_3 -> V_91 )
return - V_117 ;
V_97 = F_197 ( & V_77 -> V_152 , V_3 ) ;
if ( V_97 ) {
F_11 ( V_3 -> V_91 ) ;
return V_97 ;
}
V_3 -> V_317 = V_78 -> V_317 & V_318 ;
V_3 -> V_317 |= V_319 | V_320 ;
V_3 -> V_321 = V_78 -> V_321 +
V_114 ;
V_3 -> V_322 = V_78 -> V_322 +
V_115 ;
if ( F_198 ( V_3 -> V_323 ) )
F_199 ( V_3 , V_78 ) ;
if ( F_198 ( V_3 -> V_324 ) )
memcpy ( V_3 -> V_324 , V_78 -> V_324 , V_3 -> V_325 ) ;
return 0 ;
}
static void F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
F_201 ( & V_77 -> V_152 ) ;
F_11 ( V_3 -> V_91 ) ;
}
static T_11 F_202 ( struct V_2 * V_3 ,
T_11 V_317 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
V_317 &= ( V_78 -> V_317 & V_318 ) |
V_320 | V_326 ;
V_317 |= V_319 ;
return V_317 ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
int V_97 ;
if ( ! ( V_78 -> V_327 & V_328 ) )
return - V_329 ;
V_97 = F_204 ( V_78 , V_3 -> V_323 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_3 -> V_327 & V_330 ) {
V_97 = F_205 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_331;
}
if ( V_3 -> V_327 & V_332 ) {
V_97 = F_206 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_333;
}
if ( F_207 ( V_78 ) )
F_208 ( V_3 ) ;
return 0 ;
V_333:
if ( V_3 -> V_327 & V_330 )
F_205 ( V_78 , - 1 ) ;
V_331:
F_209 ( V_78 , V_3 -> V_323 ) ;
F_210 ( V_3 ) ;
return V_97 ;
}
static int F_211 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_210 ( V_3 ) ;
F_212 ( V_78 , V_3 ) ;
F_213 ( V_78 , V_3 ) ;
if ( V_3 -> V_327 & V_330 )
F_205 ( V_78 , - 1 ) ;
if ( V_3 -> V_327 & V_332 )
F_206 ( V_78 , - 1 ) ;
F_209 ( V_78 , V_3 -> V_323 ) ;
return 0 ;
}
static void F_214 ( struct V_2 * V_3 , int V_334 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
if ( ! ( V_3 -> V_327 & V_328 ) )
return;
if ( V_334 & V_330 )
F_205 ( V_78 , V_3 -> V_327 & V_330 ? 1 : - 1 ) ;
if ( V_334 & V_332 )
F_206 ( V_78 ,
V_3 -> V_327 & V_332 ? 1 : - 1 ) ;
}
static void F_215 ( struct V_2 * V_3 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
F_216 ( V_78 , V_3 ) ;
F_217 ( V_78 , V_3 ) ;
}
static int F_218 ( struct V_2 * V_3 , void * V_335 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_336 * V_25 = V_335 ;
int V_97 ;
if ( ! F_219 ( V_25 -> V_337 ) )
return - V_338 ;
if ( ! ( V_3 -> V_327 & V_328 ) )
goto V_149;
V_97 = F_204 ( V_78 , V_25 -> V_337 ) ;
if ( V_97 < 0 )
return V_97 ;
F_209 ( V_78 , V_3 -> V_323 ) ;
V_149:
F_220 ( V_3 -> V_323 , V_25 -> V_337 ) ;
return 0 ;
}
static int F_221 ( struct V_2 * V_3 , int V_339 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
unsigned int V_340 = V_77 -> V_41 . V_58 + F_29 ( true ) ;
if ( V_77 -> V_78 -> V_119 - V_340 < V_339 )
return - V_341 ;
V_3 -> V_119 = V_339 ;
return 0 ;
}
static struct V_342 * F_222 ( struct V_2 * V_3 ,
struct V_342 * V_343 )
{
int V_227 ;
if ( ! V_3 -> V_91 )
return V_343 ;
F_171 (cpu) {
struct V_90 * V_15 ;
struct V_90 V_106 ;
int V_237 ;
V_15 = F_172 ( V_3 -> V_91 , V_227 ) ;
do {
V_237 = F_176 ( & V_15 -> V_82 ) ;
V_106 . V_147 = V_15 -> V_147 ;
V_106 . V_148 = V_15 -> V_148 ;
V_106 . V_92 = V_15 -> V_92 ;
V_106 . V_93 = V_15 -> V_93 ;
} while ( F_177 ( & V_15 -> V_82 , V_237 ) );
V_343 -> V_147 += V_106 . V_147 ;
V_343 -> V_148 += V_106 . V_148 ;
V_343 -> V_92 += V_106 . V_92 ;
V_343 -> V_93 += V_106 . V_93 ;
}
V_343 -> V_154 = V_3 -> V_15 . V_154 ;
V_343 -> V_94 = V_3 -> V_15 . V_94 ;
return V_343 ;
}
static int F_223 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_78 -> V_191 ;
}
static int F_224 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_344 ;
}
static void F_225 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_11 ( V_77 -> V_15 ) ;
F_11 ( V_77 -> V_41 . V_44 . V_15 ) ;
F_57 ( V_78 ) ;
F_226 ( V_3 ) ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_228 ( V_3 ) ;
V_3 -> V_345 |= V_346 ;
V_3 -> V_347 = & V_348 ;
V_3 -> V_349 = F_225 ;
F_229 ( V_3 -> V_324 ) ;
}
static void F_230 ( struct V_2 * V_3 ,
struct V_189 * V_65 [] )
{
struct V_40 * V_41 ;
struct V_43 * V_44 ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
if ( V_65 [ V_350 ] ) {
struct V_20 * V_72 ;
V_44 -> V_61 = F_143 ( V_65 [ V_350 ] ) ;
V_72 = F_6 ( V_44 -> V_8 [ V_44 -> V_61 ] ) ;
V_41 -> V_76 = V_72 && V_72 -> V_9 ;
}
if ( V_65 [ V_351 ] )
V_41 -> V_128 = F_135 ( V_65 [ V_351 ] ) ;
if ( V_65 [ V_352 ] )
V_44 -> V_56 = ! ! F_143 ( V_65 [ V_352 ] ) ;
if ( V_65 [ V_353 ] )
V_41 -> V_75 = ! ! F_143 ( V_65 [ V_353 ] ) ;
if ( V_65 [ V_354 ] )
V_44 -> V_46 = ! ! F_143 ( V_65 [ V_354 ] ) ;
if ( V_65 [ V_355 ] )
V_44 -> V_50 = ! ! F_143 ( V_65 [ V_355 ] ) ;
if ( V_65 [ V_356 ] )
V_44 -> V_51 = ! ! F_143 ( V_65 [ V_356 ] ) ;
if ( V_65 [ V_357 ] )
V_41 -> V_129 = ! ! F_143 ( V_65 [ V_357 ] ) ;
if ( V_65 [ V_358 ] )
V_41 -> V_131 = F_143 ( V_65 [ V_358 ] ) ;
}
static int F_231 ( struct V_2 * V_3 , struct V_189 * V_359 [] ,
struct V_189 * V_65 [] )
{
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_360 ] ||
V_65 [ V_361 ] ||
V_65 [ V_362 ] ||
V_65 [ V_363 ] )
return - V_113 ;
F_230 ( V_3 , V_65 ) ;
return 0 ;
}
static void F_232 ( struct V_1 * V_77 )
{
int V_181 ;
while ( V_77 -> V_41 . V_14 ) {
struct V_13 * V_14 = F_6 ( V_77 -> V_41 . V_14 ) ;
F_127 ( V_77 -> V_41 . V_14 , V_14 -> V_184 ) ;
F_124 ( V_14 ) ;
}
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
struct V_20 * V_8 = F_6 ( V_77 -> V_41 . V_44 . V_8 [ V_181 ] ) ;
if ( V_8 ) {
F_125 ( V_77 -> V_41 . V_44 . V_8 [ V_181 ] , NULL ) ;
F_133 ( V_8 ) ;
}
}
}
static void F_233 ( struct V_2 * V_3 , struct V_364 * V_12 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_234 ( V_3 , V_12 ) ;
F_235 ( & V_77 -> V_365 ) ;
F_232 ( V_77 ) ;
F_236 ( V_78 , V_3 ) ;
V_314 ++ ;
}
static void F_237 ( struct V_2 * V_3 , struct V_364 * V_12 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_4 * V_156 = F_5 ( V_78 ) ;
F_233 ( V_3 , V_12 ) ;
if ( F_238 ( & V_156 -> V_365 ) ) {
F_239 ( V_78 ) ;
F_12 ( V_156 ) ;
}
}
static int F_240 ( struct V_2 * V_78 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_4 * V_156 = F_5 ( V_78 ) ;
if ( ! V_156 ) {
int V_97 ;
V_156 = F_62 ( sizeof( * V_156 ) , V_186 ) ;
if ( ! V_156 )
return - V_117 ;
F_241 ( & V_156 -> V_365 ) ;
V_97 = F_242 ( V_78 , F_111 ,
V_156 ) ;
if ( V_97 < 0 ) {
F_12 ( V_156 ) ;
return V_97 ;
}
}
F_243 ( & V_77 -> V_365 , & V_156 -> V_365 ) ;
return 0 ;
}
static bool F_244 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_4 * V_156 = F_5 ( V_3 ) ;
struct V_1 * V_77 ;
F_129 (macsec, &rxd->secys, secys) {
if ( V_77 -> V_41 . V_27 == V_27 )
return true ;
}
return false ;
}
static T_2 F_245 ( struct V_2 * V_3 , T_4 V_26 )
{
return F_25 ( V_3 -> V_323 , V_26 ) ;
}
static int F_246 ( struct V_2 * V_3 , T_2 V_27 , T_3 V_58 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
V_77 -> V_15 = F_131 ( struct V_120 ) ;
if ( ! V_77 -> V_15 )
return - V_117 ;
V_41 -> V_44 . V_15 = F_131 ( struct V_80 ) ;
if ( ! V_41 -> V_44 . V_15 ) {
F_11 ( V_77 -> V_15 ) ;
return - V_117 ;
}
if ( V_27 == V_223 )
V_27 = F_245 ( V_3 , V_35 ) ;
V_41 -> V_151 = V_3 ;
V_41 -> V_76 = true ;
V_41 -> V_177 = V_366 ;
V_41 -> V_58 = V_58 ;
V_41 -> V_131 = V_367 ;
V_41 -> V_75 = true ;
V_41 -> V_129 = false ;
V_41 -> V_27 = V_27 ;
V_41 -> V_44 . V_9 = true ;
V_41 -> V_44 . V_61 = V_368 ;
V_41 -> V_44 . V_56 = V_369 ;
V_41 -> V_44 . V_46 = V_370 ;
V_41 -> V_44 . V_50 = false ;
V_41 -> V_44 . V_51 = false ;
return 0 ;
}
static int F_247 ( struct V_188 * V_188 , struct V_2 * V_3 ,
struct V_189 * V_359 [] , struct V_189 * V_65 [] )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 ;
int V_97 ;
T_2 V_27 ;
T_3 V_58 = V_59 ;
T_12 * V_371 ;
if ( ! V_359 [ V_372 ] )
return - V_113 ;
V_78 = F_136 ( V_188 , F_135 ( V_359 [ V_372 ] ) ) ;
if ( ! V_78 )
return - V_193 ;
V_3 -> V_345 |= V_373 ;
V_77 -> V_78 = V_78 ;
if ( V_65 && V_65 [ V_361 ] )
V_58 = F_143 ( V_65 [ V_361 ] ) ;
V_3 -> V_119 = V_78 -> V_119 - V_58 - F_29 ( true ) ;
V_371 = F_6 ( V_78 -> V_371 ) ;
if ( V_371 && V_371 != F_111 )
return - V_220 ;
V_97 = F_248 ( V_3 ) ;
if ( V_97 < 0 )
return V_97 ;
F_80 ( V_78 ) ;
V_77 -> V_344 = F_249 ( V_78 ) + 1 ;
F_250 ( V_3 ) ;
F_251 ( & V_3 -> V_374 ,
& V_375 ,
F_224 ( V_3 ) ) ;
V_97 = F_252 ( V_78 , V_3 ) ;
if ( V_97 < 0 )
goto V_376;
if ( V_65 && V_65 [ V_362 ] )
V_27 = F_138 ( V_65 [ V_362 ] ) ;
else if ( V_65 && V_65 [ V_363 ] )
V_27 = F_245 ( V_3 , F_253 ( V_65 [ V_363 ] ) ) ;
else
V_27 = F_245 ( V_3 , V_35 ) ;
if ( V_371 && F_244 ( V_78 , V_27 ) ) {
V_97 = - V_220 ;
goto V_377;
}
V_97 = F_246 ( V_3 , V_27 , V_58 ) ;
if ( V_97 )
goto V_377;
if ( V_65 )
F_230 ( V_3 , V_65 ) ;
V_97 = F_240 ( V_78 , V_3 ) ;
if ( V_97 < 0 )
goto V_378;
V_314 ++ ;
return 0 ;
V_378:
F_232 ( V_77 ) ;
V_377:
F_236 ( V_78 , V_3 ) ;
V_376:
F_254 ( V_3 ) ;
return V_97 ;
}
static int F_255 ( struct V_189 * V_359 [] , struct V_189 * V_65 [] )
{
V_199 V_379 = V_272 ;
T_3 V_58 = V_59 ;
int V_380 ;
bool V_381 , V_51 , V_27 ;
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_360 ] )
V_379 = F_139 ( V_65 [ V_360 ] ) ;
if ( V_65 [ V_361 ] ) {
V_58 = F_143 ( V_65 [ V_361 ] ) ;
if ( V_58 != V_59 ) {
char V_382 [ V_366 ] = { 0 } ;
struct V_100 * V_383 ;
V_383 = F_115 ( V_382 ,
V_366 ,
V_58 ) ;
if ( F_113 ( V_383 ) )
return F_114 ( V_383 ) ;
F_18 ( V_383 ) ;
}
}
switch ( V_379 ) {
case V_272 :
case V_384 :
if ( V_58 < V_385 ||
V_58 > V_386 )
return - V_113 ;
break;
default:
return - V_113 ;
}
if ( V_65 [ V_350 ] ) {
if ( F_143 ( V_65 [ V_350 ] ) >= V_182 )
return - V_113 ;
}
for ( V_380 = V_350 + 1 ;
V_380 < V_358 ;
V_380 ++ ) {
if ( V_65 [ V_380 ] ) {
if ( F_143 ( V_65 [ V_380 ] ) > 1 )
return - V_113 ;
}
}
V_381 = V_65 [ V_355 ] ? F_143 ( V_65 [ V_355 ] ) : false ;
V_27 = V_65 [ V_354 ] ? F_143 ( V_65 [ V_354 ] ) : false ;
V_51 = V_65 [ V_356 ] ? F_143 ( V_65 [ V_356 ] ) : false ;
if ( ( V_27 && ( V_51 || V_381 ) ) || ( V_51 && V_381 ) )
return - V_113 ;
if ( V_65 [ V_358 ] &&
F_143 ( V_65 [ V_358 ] ) > V_387 )
return - V_113 ;
if ( ( V_65 [ V_357 ] &&
F_143 ( V_65 [ V_357 ] ) ) &&
! V_65 [ V_351 ] )
return - V_113 ;
return 0 ;
}
static struct V_188 * F_256 ( const struct V_2 * V_3 )
{
return F_257 ( F_1 ( V_3 ) -> V_78 ) ;
}
static T_6 F_258 ( const struct V_2 * V_3 )
{
return 0 +
F_259 ( 8 ) +
F_260 ( 1 ) +
F_259 ( 8 ) +
F_260 ( 4 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
F_260 ( 1 ) +
0 ;
}
static int F_261 ( struct V_22 * V_23 ,
const struct V_2 * V_3 )
{
struct V_40 * V_41 = & F_1 ( V_3 ) -> V_41 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
if ( F_140 ( V_23 , V_362 , V_41 -> V_27 ,
V_388 ) ||
F_182 ( V_23 , V_361 , V_41 -> V_58 ) ||
F_141 ( V_23 , V_360 ,
V_272 , V_388 ) ||
F_182 ( V_23 , V_350 , V_44 -> V_61 ) ||
F_182 ( V_23 , V_352 , V_44 -> V_56 ) ||
F_182 ( V_23 , V_353 , V_41 -> V_75 ) ||
F_182 ( V_23 , V_354 , V_44 -> V_46 ) ||
F_182 ( V_23 , V_355 , V_44 -> V_50 ) ||
F_182 ( V_23 , V_356 , V_44 -> V_51 ) ||
F_182 ( V_23 , V_357 , V_41 -> V_129 ) ||
F_182 ( V_23 , V_358 , V_41 -> V_131 ) ||
0 )
goto V_296;
if ( V_41 -> V_129 ) {
if ( F_173 ( V_23 , V_351 , V_41 -> V_128 ) )
goto V_296;
}
return 0 ;
V_296:
return - V_230 ;
}
static bool F_262 ( struct V_2 * V_3 )
{
return F_263 ( V_3 -> V_371 ) == F_111 ;
}
static int F_264 ( struct V_389 * V_390 , unsigned long V_391 ,
void * V_7 )
{
struct V_2 * V_78 = F_265 ( V_7 ) ;
F_266 ( V_12 ) ;
if ( ! F_262 ( V_78 ) )
return V_392 ;
switch ( V_391 ) {
case V_393 : {
struct V_1 * V_394 , * V_395 ;
struct V_4 * V_156 ;
V_156 = F_5 ( V_78 ) ;
F_267 (m, n, &rxd->secys, secys) {
F_233 ( V_394 -> V_41 . V_151 , & V_12 ) ;
}
F_239 ( V_78 ) ;
F_12 ( V_156 ) ;
F_268 ( & V_12 ) ;
break;
}
case V_396 : {
struct V_1 * V_394 ;
struct V_4 * V_156 ;
V_156 = F_5 ( V_78 ) ;
F_129 (m, &rxd->secys, secys) {
struct V_2 * V_3 = V_394 -> V_41 . V_151 ;
unsigned int V_119 = V_78 -> V_119 - ( V_394 -> V_41 . V_58 +
F_29 ( true ) ) ;
if ( V_3 -> V_119 > V_119 )
F_269 ( V_3 , V_119 ) ;
}
}
}
return V_397 ;
}
static int T_13 F_270 ( void )
{
int V_97 ;
F_271 ( L_5 ) ;
V_97 = F_272 ( & V_398 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_273 ( & V_399 ) ;
if ( V_97 )
goto V_400;
V_97 = F_274 ( & V_293 , V_401 ) ;
if ( V_97 )
goto V_402;
return 0 ;
V_402:
F_275 ( & V_399 ) ;
V_400:
F_276 ( & V_398 ) ;
return V_97 ;
}
static void T_14 F_277 ( void )
{
F_278 ( & V_293 ) ;
F_275 ( & V_399 ) ;
F_276 ( & V_398 ) ;
F_279 () ;
}
