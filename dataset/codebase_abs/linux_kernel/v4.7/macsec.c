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
F_14 ( V_8 -> V_16 ) ;
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
V_87 = F_97 ( V_23 ) ;
if ( V_87 == V_152 )
F_94 ( V_3 , V_66 ) ;
else
V_77 -> V_41 . V_151 -> V_15 . V_153 ++ ;
F_56 () ;
V_149:
F_19 ( V_124 ) ;
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
F_23 ( V_23 ) -> V_124 = V_124 ;
V_23 -> V_3 = V_3 ;
F_79 ( V_98 , 0 , F_95 , V_23 ) ;
F_80 ( V_3 ) ;
V_87 = F_100 ( V_98 ) ;
if ( V_87 == - V_123 ) {
return F_66 ( V_87 ) ;
} else if ( V_87 != 0 ) {
if ( V_87 != - V_154 ) {
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
struct V_4 * V_155 ;
struct V_1 * V_77 ;
F_106 () ;
V_155 = F_3 ( V_23 -> V_3 ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
int V_87 ;
struct V_120 * V_121 = F_46 ( V_77 -> V_15 ) ;
if ( V_77 -> V_41 . V_131 == V_137 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_156 ++ ;
F_49 ( & V_121 -> V_82 ) ;
continue;
}
V_116 = F_108 ( V_23 , V_109 ) ;
if ( ! V_116 )
break;
V_116 -> V_3 = V_77 -> V_41 . V_151 ;
V_87 = F_97 ( V_116 ) ;
if ( V_87 == V_152 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_157 ++ ;
F_49 ( & V_121 -> V_82 ) ;
} else {
V_77 -> V_41 . V_151 -> V_15 . V_153 ++ ;
}
}
F_109 () ;
}
static T_8 F_110 ( struct V_22 * * V_158 )
{
struct V_22 * V_23 = * V_158 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_29 * V_30 ;
struct V_40 * V_41 = NULL ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
struct V_4 * V_155 ;
struct V_1 * V_77 ;
T_2 V_27 ;
T_5 V_42 ;
bool V_159 ;
struct V_125 * V_126 ;
struct V_120 * V_121 ;
bool V_160 ;
if ( F_68 ( V_23 ) < V_38 )
goto V_161;
V_30 = F_36 ( V_23 ) ;
if ( V_30 -> V_33 . V_47 != F_31 ( V_48 ) ) {
F_105 ( V_23 ) ;
return V_162 ;
}
V_23 = F_72 ( V_23 , V_109 ) ;
if ( ! V_23 ) {
* V_158 = NULL ;
return V_163 ;
}
V_160 = F_111 ( V_23 , F_29 ( true ) ) ;
if ( ! V_160 ) {
if ( ! F_111 ( V_23 , F_29 ( false ) ) )
goto V_161;
}
V_30 = F_36 ( V_23 ) ;
if ( ( V_30 -> V_45 & ( V_60 | V_133 ) ) == V_133 )
return V_162 ;
if ( V_30 -> V_45 & V_52 ) {
if ( ! V_160 )
goto V_161;
}
F_73 ( V_23 , V_38 ) ;
F_23 ( V_23 ) -> V_150 = ! ! ( V_30 -> V_45 & V_52 ) ;
F_23 ( V_23 ) -> V_164 = V_30 -> V_45 & V_165 ;
V_27 = F_26 ( V_30 , F_23 ( V_23 ) -> V_150 ) ;
F_106 () ;
V_155 = F_3 ( V_23 -> V_3 ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_13 * V_16 = F_101 ( & V_77 -> V_41 , V_27 ) ;
if ( V_16 ) {
V_41 = & V_77 -> V_41 ;
V_14 = V_16 ;
break;
}
}
if ( ! V_41 )
goto V_166;
V_3 = V_41 -> V_151 ;
V_77 = F_1 ( V_3 ) ;
V_121 = F_46 ( V_77 -> V_15 ) ;
V_126 = F_46 ( V_14 -> V_15 ) ;
if ( ! F_34 ( V_23 , V_41 -> V_58 ) ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_167 ++ ;
F_49 ( & V_121 -> V_82 ) ;
goto V_168;
}
V_124 = F_7 ( V_14 -> V_8 [ F_23 ( V_23 ) -> V_164 ] ) ;
if ( ! V_124 ) {
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_131 == V_137 ) {
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_169 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_168;
}
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_170 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_171;
}
V_42 = F_96 ( V_30 -> V_55 ) ;
if ( V_41 -> V_129 ) {
bool V_172 ;
F_83 ( & V_124 -> V_73 ) ;
V_172 = V_124 -> V_74 >= V_41 -> V_128 &&
V_42 < ( V_124 -> V_74 - V_41 -> V_128 ) ;
F_84 ( & V_124 -> V_73 ) ;
if ( V_172 ) {
F_47 ( & V_126 -> V_82 ) ;
V_126 -> V_15 . V_130 ++ ;
F_49 ( & V_126 -> V_82 ) ;
goto V_173;
}
}
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_131 != V_132 )
V_23 = F_98 ( V_23 , V_3 , V_124 , V_27 , V_41 ) ;
if ( F_112 ( V_23 ) ) {
if ( F_113 ( V_23 ) != - V_123 )
F_19 ( V_124 ) ;
F_109 () ;
* V_158 = NULL ;
return V_163 ;
}
if ( ! F_82 ( V_23 , V_41 , V_42 ) )
goto V_173;
V_171:
F_91 ( V_23 , V_41 -> V_58 ,
F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_85 ( V_23 , V_41 -> V_151 ) ;
if ( V_124 )
F_19 ( V_124 ) ;
F_94 ( V_3 , V_23 -> V_66 ) ;
F_109 () ;
* V_158 = V_23 ;
return V_174 ;
V_173:
F_19 ( V_124 ) ;
V_168:
F_109 () ;
V_161:
F_65 ( V_23 ) ;
* V_158 = NULL ;
return V_163 ;
V_166:
V_159 = ! ! ( V_30 -> V_45 & V_60 ) ;
if ( ! V_159 )
F_91 ( V_23 , V_59 ,
F_29 ( F_23 ( V_23 ) -> V_150 ) ) ;
F_107 (macsec, &rxd->secys, secys) {
struct V_22 * V_116 ;
int V_87 ;
V_121 = F_46 ( V_77 -> V_15 ) ;
if ( V_159 ||
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
V_87 = F_97 ( V_116 ) ;
if ( V_87 == V_152 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_176 ++ ;
F_49 ( & V_121 -> V_82 ) ;
} else {
V_77 -> V_41 . V_151 -> V_15 . V_153 ++ ;
}
}
F_109 () ;
* V_158 = V_23 ;
return V_162 ;
}
static struct V_100 * F_114 ( char * V_18 , int V_177 , int V_58 )
{
struct V_100 * V_19 ;
int V_87 ;
V_19 = F_115 ( L_2 , 0 , 0 ) ;
if ( ! V_19 || F_112 ( V_19 ) )
return NULL ;
V_87 = F_116 ( V_19 , V_18 , V_177 ) ;
if ( V_87 < 0 ) {
F_18 ( V_19 ) ;
return NULL ;
}
V_87 = F_117 ( V_19 , V_58 ) ;
if ( V_87 < 0 ) {
F_18 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static int F_118 ( struct V_6 * V_124 , char * V_178 , int V_177 ,
int V_58 )
{
V_124 -> V_15 = F_119 ( struct V_179 ) ;
if ( ! V_124 -> V_15 )
return - 1 ;
V_124 -> V_18 . V_19 = F_114 ( V_178 , V_177 , V_58 ) ;
if ( ! V_124 -> V_18 . V_19 ) {
F_11 ( V_124 -> V_15 ) ;
return - 1 ;
}
V_124 -> V_9 = false ;
V_124 -> V_74 = 1 ;
F_120 ( & V_124 -> V_10 , 1 ) ;
F_121 ( & V_124 -> V_73 ) ;
return 0 ;
}
static void F_122 ( struct V_6 * V_124 )
{
V_124 -> V_9 = false ;
F_19 ( V_124 ) ;
}
static void F_123 ( struct V_13 * V_14 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
struct V_6 * V_8 = F_6 ( V_14 -> V_8 [ V_180 ] ) ;
F_124 ( V_14 -> V_8 [ V_180 ] , NULL ) ;
if ( V_8 )
F_122 ( V_8 ) ;
}
F_14 ( V_14 ) ;
}
static struct V_13 * F_125 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 , T_1 * * V_182 ;
for ( V_182 = & V_41 -> V_14 , V_14 = F_6 ( * V_182 ) ;
V_14 ;
V_182 = & V_14 -> V_183 , V_14 = F_6 ( * V_182 ) ) {
if ( V_14 -> V_27 == V_27 ) {
if ( V_14 -> V_9 )
V_41 -> V_49 -- ;
F_126 ( * V_182 , V_14 -> V_183 ) ;
return V_14 ;
}
}
return NULL ;
}
static struct V_13 * F_127 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_13 * V_14 ;
struct V_1 * V_77 ;
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
struct V_4 * V_155 = F_5 ( V_78 ) ;
struct V_40 * V_41 ;
F_128 (macsec, &rxd->secys, secys) {
if ( F_103 ( & V_77 -> V_41 , V_27 ) )
return F_66 ( - V_184 ) ;
}
V_14 = F_129 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return F_66 ( - V_117 ) ;
V_14 -> V_15 = F_130 ( struct V_125 ) ;
if ( ! V_14 -> V_15 ) {
F_12 ( V_14 ) ;
return F_66 ( - V_117 ) ;
}
V_14 -> V_27 = V_27 ;
V_14 -> V_9 = true ;
F_120 ( & V_14 -> V_10 , 1 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
F_126 ( V_14 -> V_183 , V_41 -> V_14 ) ;
F_126 ( V_41 -> V_14 , V_14 ) ;
if ( V_14 -> V_9 )
V_41 -> V_49 ++ ;
return V_14 ;
}
static int F_131 ( struct V_20 * V_72 , char * V_178 , int V_177 ,
int V_58 )
{
V_72 -> V_15 = F_119 ( struct V_186 ) ;
if ( ! V_72 -> V_15 )
return - 1 ;
V_72 -> V_18 . V_19 = F_114 ( V_178 , V_177 , V_58 ) ;
if ( ! V_72 -> V_18 . V_19 ) {
F_11 ( V_72 -> V_15 ) ;
return - 1 ;
}
V_72 -> V_9 = false ;
F_120 ( & V_72 -> V_10 , 1 ) ;
F_121 ( & V_72 -> V_73 ) ;
return 0 ;
}
static void F_132 ( struct V_20 * V_72 )
{
V_72 -> V_9 = false ;
F_22 ( V_72 ) ;
}
static struct V_2 * F_133 ( struct V_187 * V_187 ,
struct V_188 * * V_189 )
{
int V_190 = F_134 ( V_189 [ V_191 ] ) ;
struct V_2 * V_3 ;
V_3 = F_135 ( V_187 , V_190 ) ;
if ( ! V_3 )
return F_66 ( - V_192 ) ;
if ( ! F_136 ( V_3 ) )
return F_66 ( - V_192 ) ;
return V_3 ;
}
static T_2 F_137 ( const struct V_188 * V_193 )
{
return ( V_194 T_2 ) F_138 ( V_193 ) ;
}
static int F_139 ( struct V_22 * V_23 , int V_195 , T_2 V_196 ,
int V_197 )
{
return F_140 ( V_23 , V_195 , ( V_194 V_198 ) V_196 , V_197 ) ;
}
static struct V_20 * F_141 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_199 ,
struct V_2 * * V_200 ,
struct V_40 * * V_201 ,
struct V_43 * * V_202 ,
T_3 * V_164 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
if ( ! V_199 [ V_203 ] )
return F_66 ( - V_113 ) ;
* V_164 = F_142 ( V_199 [ V_203 ] ) ;
V_3 = F_133 ( V_187 , V_189 ) ;
if ( F_112 ( V_3 ) )
return F_143 ( V_3 ) ;
if ( * V_164 >= V_181 )
return F_66 ( - V_113 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_72 = F_6 ( V_44 -> V_8 [ * V_164 ] ) ;
if ( ! V_72 )
return F_66 ( - V_192 ) ;
* V_200 = V_3 ;
* V_202 = V_44 ;
* V_201 = V_41 ;
return V_72 ;
}
static struct V_13 * F_144 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_204 ,
struct V_2 * * V_200 ,
struct V_40 * * V_201 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
V_3 = F_133 ( V_187 , V_189 ) ;
if ( F_112 ( V_3 ) )
return F_143 ( V_3 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( ! V_204 [ V_205 ] )
return F_66 ( - V_113 ) ;
V_27 = F_137 ( V_204 [ V_205 ] ) ;
V_14 = F_103 ( V_41 , V_27 ) ;
if ( ! V_14 )
return F_66 ( - V_192 ) ;
* V_201 = V_41 ;
* V_200 = V_3 ;
return V_14 ;
}
static struct V_6 * F_145 ( struct V_187 * V_187 ,
struct V_188 * * V_189 ,
struct V_188 * * V_204 ,
struct V_188 * * V_199 ,
struct V_2 * * V_200 ,
struct V_40 * * V_201 ,
struct V_13 * * V_202 ,
T_3 * V_164 )
{
struct V_13 * V_14 ;
struct V_6 * V_124 ;
if ( ! V_199 [ V_203 ] )
return F_66 ( - V_113 ) ;
* V_164 = F_142 ( V_199 [ V_203 ] ) ;
if ( * V_164 >= V_181 )
return F_66 ( - V_113 ) ;
V_14 = F_144 ( V_187 , V_189 , V_204 , V_200 , V_201 ) ;
if ( F_112 ( V_14 ) )
return F_143 ( V_14 ) ;
V_124 = F_6 ( V_14 -> V_8 [ * V_164 ] ) ;
if ( ! V_124 )
return F_66 ( - V_192 ) ;
* V_202 = V_14 ;
return V_124 ;
}
static int F_146 ( struct V_188 * * V_189 , struct V_188 * * V_199 )
{
if ( ! V_189 [ V_206 ] )
return - V_113 ;
if ( F_147 ( V_199 , V_207 , V_189 [ V_206 ] ,
V_208 ) )
return - V_113 ;
return 0 ;
}
static int F_148 ( struct V_188 * * V_189 , struct V_188 * * V_204 )
{
if ( ! V_189 [ V_209 ] )
return - V_113 ;
if ( F_147 ( V_204 , V_210 , V_189 [ V_209 ] ,
V_211 ) )
return - V_113 ;
return 0 ;
}
static bool F_149 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
! V_189 [ V_212 ] ||
! V_189 [ V_213 ] )
return false ;
if ( F_142 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( V_189 [ V_214 ] && F_134 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_142 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
if ( F_150 ( V_189 [ V_213 ] ) != V_216 )
return false ;
return true ;
}
static int F_151 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
unsigned char V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
if ( ! F_149 ( V_199 ) )
return - V_113 ;
F_152 () ;
V_14 = F_144 ( F_153 ( V_218 ) , V_189 , V_204 , & V_3 , & V_41 ) ;
if ( F_112 ( V_14 ) || ! F_13 ( V_14 ) ) {
F_154 () ;
return F_113 ( V_14 ) ;
}
V_164 = F_142 ( V_199 [ V_203 ] ) ;
if ( F_150 ( V_199 [ V_212 ] ) != V_41 -> V_177 ) {
F_155 ( L_3 ,
F_150 ( V_199 [ V_212 ] ) , V_41 -> V_177 ) ;
F_154 () ;
return - V_113 ;
}
V_124 = F_6 ( V_14 -> V_8 [ V_164 ] ) ;
if ( V_124 ) {
F_154 () ;
return - V_219 ;
}
V_124 = F_62 ( sizeof( * V_124 ) , V_185 ) ;
if ( ! V_124 || F_118 ( V_124 , F_156 ( V_199 [ V_212 ] ) ,
V_41 -> V_177 , V_41 -> V_58 ) ) {
F_12 ( V_124 ) ;
F_154 () ;
return - V_117 ;
}
if ( V_199 [ V_214 ] ) {
F_39 ( & V_124 -> V_73 ) ;
V_124 -> V_74 = F_134 ( V_199 [ V_214 ] ) ;
F_41 ( & V_124 -> V_73 ) ;
}
if ( V_199 [ V_215 ] )
V_124 -> V_9 = ! ! F_142 ( V_199 [ V_215 ] ) ;
F_157 ( V_124 -> V_18 . V_220 , V_199 [ V_213 ] , V_216 ) ;
V_124 -> V_16 = V_14 ;
F_126 ( V_14 -> V_8 [ V_164 ] , V_124 ) ;
F_154 () ;
return 0 ;
}
static bool F_158 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_205 ] )
return false ;
if ( V_189 [ V_221 ] ) {
if ( F_142 ( V_189 [ V_221 ] ) > 1 )
return false ;
}
return true ;
}
static int F_159 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
T_2 V_27 = V_222 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_13 * V_14 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
if ( ! F_158 ( V_204 ) )
return - V_113 ;
F_152 () ;
V_3 = F_133 ( F_153 ( V_218 ) , V_189 ) ;
if ( F_112 ( V_3 ) ) {
F_154 () ;
return F_113 ( V_3 ) ;
}
V_27 = F_137 ( V_204 [ V_205 ] ) ;
V_14 = F_127 ( V_3 , V_27 ) ;
if ( F_112 ( V_14 ) ) {
F_154 () ;
return F_113 ( V_14 ) ;
}
if ( V_204 [ V_221 ] )
V_14 -> V_9 = ! ! F_142 ( V_204 [ V_221 ] ) ;
F_154 () ;
return 0 ;
}
static bool F_160 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
! V_189 [ V_214 ] ||
! V_189 [ V_212 ] ||
! V_189 [ V_213 ] )
return false ;
if ( F_142 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( F_134 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_142 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
if ( F_150 ( V_189 [ V_213 ] ) != V_216 )
return false ;
return true ;
}
static int F_161 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_2 * V_3 ;
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
unsigned char V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
if ( ! F_160 ( V_199 ) )
return - V_113 ;
F_152 () ;
V_3 = F_133 ( F_153 ( V_218 ) , V_189 ) ;
if ( F_112 ( V_3 ) ) {
F_154 () ;
return F_113 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_164 = F_142 ( V_199 [ V_203 ] ) ;
if ( F_150 ( V_199 [ V_212 ] ) != V_41 -> V_177 ) {
F_155 ( L_4 ,
F_150 ( V_199 [ V_212 ] ) , V_41 -> V_177 ) ;
F_154 () ;
return - V_113 ;
}
V_72 = F_6 ( V_44 -> V_8 [ V_164 ] ) ;
if ( V_72 ) {
F_154 () ;
return - V_219 ;
}
V_72 = F_62 ( sizeof( * V_72 ) , V_185 ) ;
if ( ! V_72 || F_131 ( V_72 , F_156 ( V_199 [ V_212 ] ) ,
V_41 -> V_177 , V_41 -> V_58 ) ) {
F_12 ( V_72 ) ;
F_154 () ;
return - V_117 ;
}
F_157 ( V_72 -> V_18 . V_220 , V_199 [ V_213 ] , V_216 ) ;
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_134 ( V_199 [ V_214 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
if ( V_199 [ V_215 ] )
V_72 -> V_9 = ! ! F_142 ( V_199 [ V_215 ] ) ;
if ( V_164 == V_44 -> V_61 && V_72 -> V_9 )
V_41 -> V_76 = true ;
F_126 ( V_44 -> V_8 [ V_164 ] , V_72 ) ;
F_154 () ;
return 0 ;
}
static int F_162 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
F_152 () ;
V_124 = F_145 ( F_153 ( V_218 ) , V_189 , V_204 , V_199 ,
& V_3 , & V_41 , & V_14 , & V_164 ) ;
if ( F_112 ( V_124 ) ) {
F_154 () ;
return F_113 ( V_124 ) ;
}
if ( V_124 -> V_9 ) {
F_154 () ;
return - V_219 ;
}
F_124 ( V_14 -> V_8 [ V_164 ] , NULL ) ;
F_122 ( V_124 ) ;
F_154 () ;
return 0 ;
}
static int F_163 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
if ( ! V_204 [ V_205 ] )
return - V_113 ;
F_152 () ;
V_3 = F_133 ( F_153 ( V_218 ) , V_218 -> V_189 ) ;
if ( F_112 ( V_3 ) ) {
F_154 () ;
return F_113 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_27 = F_137 ( V_204 [ V_205 ] ) ;
V_14 = F_125 ( V_41 , V_27 ) ;
if ( ! V_14 ) {
F_154 () ;
return - V_192 ;
}
F_123 ( V_14 ) ;
F_154 () ;
return 0 ;
}
static int F_164 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
F_152 () ;
V_72 = F_141 ( F_153 ( V_218 ) , V_189 , V_199 ,
& V_3 , & V_41 , & V_44 , & V_164 ) ;
if ( F_112 ( V_72 ) ) {
F_154 () ;
return F_113 ( V_72 ) ;
}
if ( V_72 -> V_9 ) {
F_154 () ;
return - V_219 ;
}
F_124 ( V_44 -> V_8 [ V_164 ] , NULL ) ;
F_132 ( V_72 ) ;
F_154 () ;
return 0 ;
}
static bool F_165 ( struct V_188 * * V_189 )
{
if ( ! V_189 [ V_203 ] ||
V_189 [ V_212 ] ||
V_189 [ V_213 ] )
return false ;
if ( F_142 ( V_189 [ V_203 ] ) >= V_181 )
return false ;
if ( V_189 [ V_214 ] && F_134 ( V_189 [ V_214 ] ) == 0 )
return false ;
if ( V_189 [ V_215 ] ) {
if ( F_142 ( V_189 [ V_215 ] ) > 1 )
return false ;
}
return true ;
}
static int F_166 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_164 ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
if ( ! F_165 ( V_199 ) )
return - V_113 ;
F_152 () ;
V_72 = F_141 ( F_153 ( V_218 ) , V_189 , V_199 ,
& V_3 , & V_41 , & V_44 , & V_164 ) ;
if ( F_112 ( V_72 ) ) {
F_154 () ;
return F_113 ( V_72 ) ;
}
if ( V_199 [ V_214 ] ) {
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_134 ( V_199 [ V_214 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
}
if ( V_199 [ V_215 ] )
V_72 -> V_9 = F_142 ( V_199 [ V_215 ] ) ;
if ( V_164 == V_44 -> V_61 )
V_41 -> V_76 = V_72 -> V_9 ;
F_154 () ;
return 0 ;
}
static int F_167 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_124 ;
T_3 V_164 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
struct V_188 * V_199 [ V_207 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
if ( F_146 ( V_189 , V_199 ) )
return - V_113 ;
if ( ! F_165 ( V_199 ) )
return - V_113 ;
F_152 () ;
V_124 = F_145 ( F_153 ( V_218 ) , V_189 , V_204 , V_199 ,
& V_3 , & V_41 , & V_14 , & V_164 ) ;
if ( F_112 ( V_124 ) ) {
F_154 () ;
return F_113 ( V_124 ) ;
}
if ( V_199 [ V_214 ] ) {
F_39 ( & V_124 -> V_73 ) ;
V_124 -> V_74 = F_134 ( V_199 [ V_214 ] ) ;
F_41 ( & V_124 -> V_73 ) ;
}
if ( V_199 [ V_215 ] )
V_124 -> V_9 = F_142 ( V_199 [ V_215 ] ) ;
F_154 () ;
return 0 ;
}
static int F_168 ( struct V_22 * V_23 , struct V_217 * V_218 )
{
struct V_188 * * V_189 = V_218 -> V_189 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_188 * V_204 [ V_210 + 1 ] ;
if ( ! V_189 [ V_191 ] )
return - V_113 ;
if ( F_148 ( V_189 , V_204 ) )
return - V_113 ;
if ( ! F_158 ( V_204 ) )
return - V_113 ;
F_152 () ;
V_14 = F_144 ( F_153 ( V_218 ) , V_189 , V_204 , & V_3 , & V_41 ) ;
if ( F_112 ( V_14 ) ) {
F_154 () ;
return F_113 ( V_14 ) ;
}
if ( V_204 [ V_221 ] ) {
bool V_223 = ! ! F_142 ( V_204 [ V_221 ] ) ;
if ( V_14 -> V_9 != V_223 )
V_41 -> V_49 += V_223 ? 1 : - 1 ;
V_14 -> V_9 = V_223 ;
}
F_154 () ;
return 0 ;
}
static int F_169 ( struct V_22 * V_23 ,
struct V_186 T_9 * V_224 )
{
struct V_186 V_225 = { 0 , } ;
int V_226 ;
F_170 (cpu) {
const struct V_186 * V_15 = F_171 ( V_224 , V_226 ) ;
V_225 . V_86 += V_15 -> V_86 ;
V_225 . V_84 += V_15 -> V_84 ;
}
if ( F_172 ( V_23 , V_227 , V_225 . V_86 ) ||
F_172 ( V_23 , V_228 , V_225 . V_84 ) )
return - V_229 ;
return 0 ;
}
static int F_173 ( struct V_22 * V_23 ,
struct V_179 T_9 * V_224 )
{
struct V_179 V_225 = { 0 , } ;
int V_226 ;
F_170 (cpu) {
const struct V_179 * V_15 = F_171 ( V_224 , V_226 ) ;
V_225 . V_143 += V_15 -> V_143 ;
V_225 . V_140 += V_15 -> V_140 ;
V_225 . V_138 += V_15 -> V_138 ;
V_225 . V_169 += V_15 -> V_169 ;
V_225 . V_170 += V_15 -> V_170 ;
}
if ( F_172 ( V_23 , V_230 , V_225 . V_143 ) ||
F_172 ( V_23 , V_231 , V_225 . V_140 ) ||
F_172 ( V_23 , V_232 , V_225 . V_138 ) ||
F_172 ( V_23 , V_233 , V_225 . V_169 ) ||
F_172 ( V_23 , V_234 , V_225 . V_170 ) )
return - V_229 ;
return 0 ;
}
static int F_174 ( struct V_22 * V_23 ,
struct V_125 T_9 * V_224 )
{
struct V_235 V_225 = { 0 , } ;
int V_226 ;
F_170 (cpu) {
const struct V_125 * V_15 ;
struct V_235 V_106 ;
unsigned int V_236 ;
V_15 = F_171 ( V_224 , V_226 ) ;
do {
V_236 = F_175 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_176 ( & V_15 -> V_82 , V_236 ) );
V_225 . V_135 += V_106 . V_135 ;
V_225 . V_134 += V_106 . V_134 ;
V_225 . V_142 += V_106 . V_142 ;
V_225 . V_141 += V_106 . V_141 ;
V_225 . V_143 += V_106 . V_143 ;
V_225 . V_140 += V_106 . V_140 ;
V_225 . V_130 += V_106 . V_130 ;
V_225 . V_138 += V_106 . V_138 ;
V_225 . V_169 += V_106 . V_169 ;
V_225 . V_170 += V_106 . V_170 ;
}
if ( F_140 ( V_23 , V_237 ,
V_225 . V_135 ,
V_238 ) ||
F_140 ( V_23 , V_239 ,
V_225 . V_134 ,
V_238 ) ||
F_140 ( V_23 , V_240 ,
V_225 . V_142 ,
V_238 ) ||
F_140 ( V_23 , V_241 ,
V_225 . V_141 ,
V_238 ) ||
F_140 ( V_23 , V_242 ,
V_225 . V_143 ,
V_238 ) ||
F_140 ( V_23 , V_243 ,
V_225 . V_140 ,
V_238 ) ||
F_140 ( V_23 , V_244 ,
V_225 . V_130 ,
V_238 ) ||
F_140 ( V_23 , V_245 ,
V_225 . V_138 ,
V_238 ) ||
F_140 ( V_23 , V_246 ,
V_225 . V_169 ,
V_238 ) ||
F_140 ( V_23 , V_247 ,
V_225 . V_170 ,
V_238 ) )
return - V_229 ;
return 0 ;
}
static int F_177 ( struct V_22 * V_23 ,
struct V_80 T_9 * V_224 )
{
struct V_248 V_225 = { 0 , } ;
int V_226 ;
F_170 (cpu) {
const struct V_80 * V_15 ;
struct V_248 V_106 ;
unsigned int V_236 ;
V_15 = F_171 ( V_224 , V_226 ) ;
do {
V_236 = F_175 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_176 ( & V_15 -> V_82 , V_236 ) );
V_225 . V_86 += V_106 . V_86 ;
V_225 . V_84 += V_106 . V_84 ;
V_225 . V_85 += V_106 . V_85 ;
V_225 . V_83 += V_106 . V_83 ;
}
if ( F_140 ( V_23 , V_249 ,
V_225 . V_86 ,
V_250 ) ||
F_140 ( V_23 , V_251 ,
V_225 . V_84 ,
V_250 ) ||
F_140 ( V_23 , V_252 ,
V_225 . V_85 ,
V_250 ) ||
F_140 ( V_23 , V_253 ,
V_225 . V_83 ,
V_250 ) )
return - V_229 ;
return 0 ;
}
static int F_178 ( struct V_22 * V_23 ,
struct V_120 T_9 * V_224 )
{
struct V_254 V_225 = { 0 , } ;
int V_226 ;
F_170 (cpu) {
const struct V_120 * V_15 ;
struct V_254 V_106 ;
unsigned int V_236 ;
V_15 = F_171 ( V_224 , V_226 ) ;
do {
V_236 = F_175 ( & V_15 -> V_82 ) ;
memcpy ( & V_106 , & V_15 -> V_15 , sizeof( V_106 ) ) ;
} while ( F_176 ( & V_15 -> V_82 , V_236 ) );
V_225 . V_255 += V_106 . V_255 ;
V_225 . V_157 += V_106 . V_157 ;
V_225 . V_122 += V_106 . V_122 ;
V_225 . V_156 += V_106 . V_156 ;
V_225 . V_167 += V_106 . V_167 ;
V_225 . V_176 += V_106 . V_176 ;
V_225 . V_175 += V_106 . V_175 ;
V_225 . V_256 += V_106 . V_256 ;
}
if ( F_140 ( V_23 , V_257 ,
V_225 . V_255 ,
V_258 ) ||
F_140 ( V_23 , V_259 ,
V_225 . V_157 ,
V_258 ) ||
F_140 ( V_23 , V_260 ,
V_225 . V_122 ,
V_258 ) ||
F_140 ( V_23 , V_261 ,
V_225 . V_156 ,
V_258 ) ||
F_140 ( V_23 , V_262 ,
V_225 . V_167 ,
V_258 ) ||
F_140 ( V_23 , V_263 ,
V_225 . V_176 ,
V_258 ) ||
F_140 ( V_23 , V_264 ,
V_225 . V_175 ,
V_258 ) ||
F_140 ( V_23 , V_265 ,
V_225 . V_256 ,
V_258 ) )
return - V_229 ;
return 0 ;
}
static int F_179 ( struct V_40 * V_41 , struct V_22 * V_23 )
{
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_188 * V_266 = F_180 ( V_23 , V_267 ) ;
if ( ! V_266 )
return 1 ;
if ( F_139 ( V_23 , V_268 , V_41 -> V_27 ,
V_269 ) ||
F_140 ( V_23 , V_270 ,
V_271 ,
V_269 ) ||
F_181 ( V_23 , V_272 , V_41 -> V_58 ) ||
F_181 ( V_23 , V_273 , V_41 -> V_76 ) ||
F_181 ( V_23 , V_274 , V_41 -> V_75 ) ||
F_181 ( V_23 , V_275 , V_41 -> V_129 ) ||
F_181 ( V_23 , V_276 , V_41 -> V_131 ) ||
F_181 ( V_23 , V_277 , V_44 -> V_56 ) ||
F_181 ( V_23 , V_278 , V_44 -> V_46 ) ||
F_181 ( V_23 , V_279 , V_44 -> V_50 ) ||
F_181 ( V_23 , V_280 , V_44 -> V_51 ) ||
F_181 ( V_23 , V_281 , V_44 -> V_61 ) )
goto V_282;
if ( V_41 -> V_129 ) {
if ( F_172 ( V_23 , V_283 , V_41 -> V_128 ) )
goto V_282;
}
F_182 ( V_23 , V_266 ) ;
return 0 ;
V_282:
F_183 ( V_23 , V_266 ) ;
return 1 ;
}
static int F_184 ( struct V_40 * V_41 , struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_284 * V_24 )
{
struct V_13 * V_14 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_188 * V_285 , * V_286 ;
int V_180 , V_287 ;
void * V_30 ;
struct V_188 * V_288 ;
V_30 = F_185 ( V_23 , F_186 ( V_24 -> V_23 ) . V_289 , V_24 -> V_290 -> V_291 ,
& V_292 , V_293 , V_294 ) ;
if ( ! V_30 )
return - V_229 ;
F_187 ( V_24 , V_30 , & V_292 ) ;
if ( F_172 ( V_23 , V_191 , V_3 -> V_190 ) )
goto V_295;
if ( F_179 ( V_41 , V_23 ) )
goto V_295;
V_288 = F_180 ( V_23 , V_296 ) ;
if ( ! V_288 )
goto V_295;
if ( F_177 ( V_23 , V_44 -> V_15 ) ) {
F_183 ( V_23 , V_288 ) ;
goto V_295;
}
F_182 ( V_23 , V_288 ) ;
V_288 = F_180 ( V_23 , V_297 ) ;
if ( ! V_288 )
goto V_295;
if ( F_178 ( V_23 , F_1 ( V_3 ) -> V_15 ) ) {
F_183 ( V_23 , V_288 ) ;
goto V_295;
}
F_182 ( V_23 , V_288 ) ;
V_285 = F_180 ( V_23 , V_298 ) ;
if ( ! V_285 )
goto V_295;
for ( V_180 = 0 , V_287 = 1 ; V_180 < V_181 ; V_180 ++ ) {
struct V_20 * V_72 = F_6 ( V_44 -> V_8 [ V_180 ] ) ;
struct V_188 * V_299 ;
if ( ! V_72 )
continue;
V_299 = F_180 ( V_23 , V_287 ++ ) ;
if ( ! V_299 ) {
F_183 ( V_23 , V_285 ) ;
goto V_295;
}
if ( F_181 ( V_23 , V_203 , V_180 ) ||
F_172 ( V_23 , V_214 , V_72 -> V_74 ) ||
F_188 ( V_23 , V_213 , V_216 , V_72 -> V_18 . V_220 ) ||
F_181 ( V_23 , V_215 , V_72 -> V_9 ) ) {
F_183 ( V_23 , V_299 ) ;
F_183 ( V_23 , V_285 ) ;
goto V_295;
}
V_288 = F_180 ( V_23 , V_300 ) ;
if ( ! V_288 ) {
F_183 ( V_23 , V_299 ) ;
F_183 ( V_23 , V_285 ) ;
goto V_295;
}
if ( F_169 ( V_23 , V_72 -> V_15 ) ) {
F_183 ( V_23 , V_288 ) ;
F_183 ( V_23 , V_299 ) ;
F_183 ( V_23 , V_285 ) ;
goto V_295;
}
F_182 ( V_23 , V_288 ) ;
F_182 ( V_23 , V_299 ) ;
}
F_182 ( V_23 , V_285 ) ;
V_286 = F_180 ( V_23 , V_301 ) ;
if ( ! V_286 )
goto V_295;
V_287 = 1 ;
F_104 (secy, rx_sc) {
int V_302 ;
struct V_188 * V_303 ;
struct V_188 * V_304 = F_180 ( V_23 , V_287 ++ ) ;
if ( ! V_304 ) {
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_181 ( V_23 , V_221 , V_14 -> V_9 ) ||
F_139 ( V_23 , V_205 , V_14 -> V_27 ,
V_305 ) ) {
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
V_288 = F_180 ( V_23 , V_306 ) ;
if ( ! V_288 ) {
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_174 ( V_23 , V_14 -> V_15 ) ) {
F_183 ( V_23 , V_288 ) ;
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
F_182 ( V_23 , V_288 ) ;
V_303 = F_180 ( V_23 , V_307 ) ;
if ( ! V_303 ) {
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
for ( V_180 = 0 , V_302 = 1 ; V_180 < V_181 ; V_180 ++ ) {
struct V_6 * V_124 = F_6 ( V_14 -> V_8 [ V_180 ] ) ;
struct V_188 * V_308 ;
if ( ! V_124 )
continue;
V_308 = F_180 ( V_23 , V_302 ++ ) ;
if ( ! V_308 ) {
F_183 ( V_23 , V_303 ) ;
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
V_288 = F_180 ( V_23 , V_300 ) ;
if ( ! V_288 ) {
F_183 ( V_23 , V_303 ) ;
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
if ( F_173 ( V_23 , V_124 -> V_15 ) ) {
F_183 ( V_23 , V_288 ) ;
F_183 ( V_23 , V_303 ) ;
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
F_182 ( V_23 , V_288 ) ;
if ( F_181 ( V_23 , V_203 , V_180 ) ||
F_172 ( V_23 , V_214 , V_124 -> V_74 ) ||
F_188 ( V_23 , V_213 , V_216 , V_124 -> V_18 . V_220 ) ||
F_181 ( V_23 , V_215 , V_124 -> V_9 ) ) {
F_183 ( V_23 , V_308 ) ;
F_183 ( V_23 , V_304 ) ;
F_183 ( V_23 , V_286 ) ;
goto V_295;
}
F_182 ( V_23 , V_308 ) ;
}
F_182 ( V_23 , V_303 ) ;
F_182 ( V_23 , V_304 ) ;
}
F_182 ( V_23 , V_286 ) ;
F_189 ( V_23 , V_30 ) ;
return 0 ;
V_295:
F_190 ( V_23 , V_30 ) ;
return - V_229 ;
}
static int F_191 ( struct V_22 * V_23 , struct V_284 * V_24 )
{
struct V_187 * V_187 = F_192 ( V_23 -> V_309 ) ;
struct V_2 * V_3 ;
int V_310 , V_311 ;
V_310 = V_24 -> args [ 0 ] ;
V_311 = 0 ;
F_152 () ;
V_24 -> V_312 = V_313 ;
F_193 (net, dev) {
struct V_40 * V_41 ;
if ( V_311 < V_310 )
goto V_183;
if ( ! F_136 ( V_3 ) )
goto V_183;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( F_184 ( V_41 , V_3 , V_23 , V_24 ) < 0 )
goto V_314;
V_183:
V_311 ++ ;
}
V_314:
F_154 () ;
V_24 -> args [ 0 ] = V_311 ;
return V_23 -> V_66 ;
}
static T_10 F_194 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_2 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
struct V_120 * V_121 ;
int V_87 , V_66 ;
if ( ! V_41 -> V_75 ) {
V_121 = F_46 ( V_77 -> V_15 ) ;
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_255 ++ ;
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
return V_315 ;
}
V_23 = F_64 ( V_23 , V_3 ) ;
if ( F_112 ( V_23 ) ) {
if ( F_113 ( V_23 ) != - V_123 )
V_3 -> V_15 . V_94 ++ ;
return V_315 ;
}
F_45 ( V_23 , & V_77 -> V_41 . V_44 , F_23 ( V_23 ) -> V_72 ) ;
F_42 ( V_23 , V_3 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
return V_87 ;
}
static int F_195 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
V_3 -> V_91 = F_130 ( struct V_90 ) ;
if ( ! V_3 -> V_91 )
return - V_117 ;
V_3 -> V_316 = V_78 -> V_316 & V_317 ;
V_3 -> V_316 |= V_318 | V_319 ;
V_3 -> V_320 = V_78 -> V_320 +
V_114 ;
V_3 -> V_321 = V_78 -> V_321 +
V_115 ;
if ( F_196 ( V_3 -> V_322 ) )
F_197 ( V_3 , V_78 ) ;
if ( F_196 ( V_3 -> V_323 ) )
memcpy ( V_3 -> V_323 , V_78 -> V_323 , V_3 -> V_324 ) ;
return 0 ;
}
static void F_198 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_91 ) ;
}
static T_11 F_199 ( struct V_2 * V_3 ,
T_11 V_316 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
V_316 &= V_78 -> V_316 & V_317 ;
V_316 |= V_318 | V_319 ;
return V_316 ;
}
static int F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
int V_97 ;
if ( ! ( V_78 -> V_325 & V_326 ) )
return - V_327 ;
V_97 = F_201 ( V_78 , V_3 -> V_322 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_3 -> V_325 & V_328 ) {
V_97 = F_202 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_329;
}
if ( V_3 -> V_325 & V_330 ) {
V_97 = F_203 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_331;
}
if ( F_204 ( V_78 ) )
F_205 ( V_3 ) ;
return 0 ;
V_331:
if ( V_3 -> V_325 & V_328 )
F_202 ( V_78 , - 1 ) ;
V_329:
F_206 ( V_78 , V_3 -> V_322 ) ;
F_207 ( V_3 ) ;
return V_97 ;
}
static int F_208 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_207 ( V_3 ) ;
F_209 ( V_78 , V_3 ) ;
F_210 ( V_78 , V_3 ) ;
if ( V_3 -> V_325 & V_328 )
F_202 ( V_78 , - 1 ) ;
if ( V_3 -> V_325 & V_330 )
F_203 ( V_78 , - 1 ) ;
F_206 ( V_78 , V_3 -> V_322 ) ;
return 0 ;
}
static void F_211 ( struct V_2 * V_3 , int V_332 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
if ( ! ( V_3 -> V_325 & V_326 ) )
return;
if ( V_332 & V_328 )
F_202 ( V_78 , V_3 -> V_325 & V_328 ? 1 : - 1 ) ;
if ( V_332 & V_330 )
F_203 ( V_78 ,
V_3 -> V_325 & V_330 ? 1 : - 1 ) ;
}
static void F_212 ( struct V_2 * V_3 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
F_213 ( V_78 , V_3 ) ;
F_214 ( V_78 , V_3 ) ;
}
static int F_215 ( struct V_2 * V_3 , void * V_333 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_334 * V_25 = V_333 ;
int V_97 ;
if ( ! F_216 ( V_25 -> V_335 ) )
return - V_336 ;
if ( ! ( V_3 -> V_325 & V_326 ) )
goto V_149;
V_97 = F_201 ( V_78 , V_25 -> V_335 ) ;
if ( V_97 < 0 )
return V_97 ;
F_206 ( V_78 , V_3 -> V_322 ) ;
V_149:
F_217 ( V_3 -> V_322 , V_25 -> V_335 ) ;
return 0 ;
}
static int F_218 ( struct V_2 * V_3 , int V_337 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
unsigned int V_338 = V_77 -> V_41 . V_58 + F_29 ( true ) ;
if ( V_77 -> V_78 -> V_119 - V_338 < V_337 )
return - V_339 ;
V_3 -> V_119 = V_337 ;
return 0 ;
}
static struct V_340 * F_219 ( struct V_2 * V_3 ,
struct V_340 * V_341 )
{
int V_226 ;
if ( ! V_3 -> V_91 )
return V_341 ;
F_170 (cpu) {
struct V_90 * V_15 ;
struct V_90 V_106 ;
int V_236 ;
V_15 = F_171 ( V_3 -> V_91 , V_226 ) ;
do {
V_236 = F_175 ( & V_15 -> V_82 ) ;
V_106 . V_147 = V_15 -> V_147 ;
V_106 . V_148 = V_15 -> V_148 ;
V_106 . V_92 = V_15 -> V_92 ;
V_106 . V_93 = V_15 -> V_93 ;
} while ( F_176 ( & V_15 -> V_82 , V_236 ) );
V_341 -> V_147 += V_106 . V_147 ;
V_341 -> V_148 += V_106 . V_148 ;
V_341 -> V_92 += V_106 . V_92 ;
V_341 -> V_93 += V_106 . V_93 ;
}
V_341 -> V_153 = V_3 -> V_15 . V_153 ;
V_341 -> V_94 = V_3 -> V_15 . V_94 ;
return V_341 ;
}
static int F_220 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_78 -> V_190 ;
}
static void F_221 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_11 ( V_77 -> V_15 ) ;
F_11 ( V_77 -> V_41 . V_44 . V_15 ) ;
F_57 ( V_78 ) ;
F_222 ( V_3 ) ;
}
static void F_223 ( struct V_2 * V_3 )
{
F_224 ( V_3 ) ;
V_3 -> V_342 |= V_343 ;
V_3 -> V_344 = & V_345 ;
V_3 -> V_346 = F_221 ;
F_225 ( V_3 -> V_323 ) ;
}
static void F_226 ( struct V_2 * V_3 ,
struct V_188 * V_65 [] )
{
struct V_40 * V_41 ;
struct V_43 * V_44 ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
if ( V_65 [ V_347 ] ) {
struct V_20 * V_72 ;
V_44 -> V_61 = F_142 ( V_65 [ V_347 ] ) ;
V_72 = F_6 ( V_44 -> V_8 [ V_44 -> V_61 ] ) ;
V_41 -> V_76 = V_72 && V_72 -> V_9 ;
}
if ( V_65 [ V_348 ] )
V_41 -> V_128 = F_134 ( V_65 [ V_348 ] ) ;
if ( V_65 [ V_349 ] )
V_44 -> V_56 = ! ! F_142 ( V_65 [ V_349 ] ) ;
if ( V_65 [ V_350 ] )
V_41 -> V_75 = ! ! F_142 ( V_65 [ V_350 ] ) ;
if ( V_65 [ V_351 ] )
V_44 -> V_46 = ! ! F_142 ( V_65 [ V_351 ] ) ;
if ( V_65 [ V_352 ] )
V_44 -> V_50 = ! ! F_142 ( V_65 [ V_352 ] ) ;
if ( V_65 [ V_353 ] )
V_44 -> V_51 = ! ! F_142 ( V_65 [ V_353 ] ) ;
if ( V_65 [ V_354 ] )
V_41 -> V_129 = ! ! F_142 ( V_65 [ V_354 ] ) ;
if ( V_65 [ V_355 ] )
V_41 -> V_131 = F_142 ( V_65 [ V_355 ] ) ;
}
static int F_227 ( struct V_2 * V_3 , struct V_188 * V_356 [] ,
struct V_188 * V_65 [] )
{
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_357 ] ||
V_65 [ V_358 ] ||
V_65 [ V_359 ] ||
V_65 [ V_360 ] )
return - V_113 ;
F_226 ( V_3 , V_65 ) ;
return 0 ;
}
static void F_228 ( struct V_1 * V_77 )
{
int V_180 ;
while ( V_77 -> V_41 . V_14 ) {
struct V_13 * V_14 = F_6 ( V_77 -> V_41 . V_14 ) ;
F_126 ( V_77 -> V_41 . V_14 , V_14 -> V_183 ) ;
F_123 ( V_14 ) ;
}
for ( V_180 = 0 ; V_180 < V_181 ; V_180 ++ ) {
struct V_20 * V_8 = F_6 ( V_77 -> V_41 . V_44 . V_8 [ V_180 ] ) ;
if ( V_8 ) {
F_124 ( V_77 -> V_41 . V_44 . V_8 [ V_180 ] , NULL ) ;
F_132 ( V_8 ) ;
}
}
}
static void F_229 ( struct V_2 * V_3 , struct V_361 * V_12 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_4 * V_155 = F_5 ( V_78 ) ;
V_313 ++ ;
F_230 ( V_3 , V_12 ) ;
F_231 ( & V_77 -> V_362 ) ;
if ( F_232 ( & V_155 -> V_362 ) ) {
F_233 ( V_78 ) ;
F_12 ( V_155 ) ;
}
F_228 ( V_77 ) ;
}
static int F_234 ( struct V_2 * V_78 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_4 * V_155 = F_5 ( V_78 ) ;
if ( ! V_155 ) {
int V_97 ;
V_155 = F_62 ( sizeof( * V_155 ) , V_185 ) ;
if ( ! V_155 )
return - V_117 ;
F_235 ( & V_155 -> V_362 ) ;
V_97 = F_236 ( V_78 , F_110 ,
V_155 ) ;
if ( V_97 < 0 ) {
F_12 ( V_155 ) ;
return V_97 ;
}
}
F_237 ( & V_77 -> V_362 , & V_155 -> V_362 ) ;
return 0 ;
}
static bool F_238 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_4 * V_155 = F_5 ( V_3 ) ;
struct V_1 * V_77 ;
F_128 (macsec, &rxd->secys, secys) {
if ( V_77 -> V_41 . V_27 == V_27 )
return true ;
}
return false ;
}
static T_2 F_239 ( struct V_2 * V_3 , T_4 V_26 )
{
return F_25 ( V_3 -> V_322 , V_26 ) ;
}
static int F_240 ( struct V_2 * V_3 , T_2 V_27 , T_3 V_58 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
V_77 -> V_15 = F_130 ( struct V_120 ) ;
if ( ! V_77 -> V_15 )
return - V_117 ;
V_41 -> V_44 . V_15 = F_130 ( struct V_80 ) ;
if ( ! V_41 -> V_44 . V_15 ) {
F_11 ( V_77 -> V_15 ) ;
return - V_117 ;
}
if ( V_27 == V_222 )
V_27 = F_239 ( V_3 , V_35 ) ;
V_41 -> V_151 = V_3 ;
V_41 -> V_76 = true ;
V_41 -> V_177 = V_363 ;
V_41 -> V_58 = V_58 ;
V_41 -> V_131 = V_364 ;
V_41 -> V_75 = true ;
V_41 -> V_129 = false ;
V_41 -> V_27 = V_27 ;
V_41 -> V_44 . V_9 = true ;
V_41 -> V_44 . V_61 = V_365 ;
V_41 -> V_44 . V_56 = V_366 ;
V_41 -> V_44 . V_46 = V_367 ;
V_41 -> V_44 . V_50 = false ;
V_41 -> V_44 . V_51 = false ;
return 0 ;
}
static int F_241 ( struct V_187 * V_187 , struct V_2 * V_3 ,
struct V_188 * V_356 [] , struct V_188 * V_65 [] )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 ;
int V_97 ;
T_2 V_27 ;
T_3 V_58 = V_59 ;
T_12 * V_368 ;
if ( ! V_356 [ V_369 ] )
return - V_113 ;
V_78 = F_135 ( V_187 , F_134 ( V_356 [ V_369 ] ) ) ;
if ( ! V_78 )
return - V_192 ;
V_3 -> V_342 |= V_370 ;
V_77 -> V_78 = V_78 ;
if ( V_65 && V_65 [ V_358 ] )
V_58 = F_142 ( V_65 [ V_358 ] ) ;
V_3 -> V_119 = V_78 -> V_119 - V_58 - F_29 ( true ) ;
V_368 = F_6 ( V_78 -> V_368 ) ;
if ( V_368 && V_368 != F_110 )
return - V_219 ;
V_97 = F_242 ( V_3 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_65 && V_65 [ V_359 ] )
V_27 = F_137 ( V_65 [ V_359 ] ) ;
else if ( V_65 && V_65 [ V_360 ] )
V_27 = F_239 ( V_3 , F_243 ( V_65 [ V_360 ] ) ) ;
else
V_27 = F_239 ( V_3 , V_35 ) ;
if ( V_368 && F_238 ( V_78 , V_27 ) ) {
V_97 = - V_219 ;
goto V_371;
}
V_97 = F_240 ( V_3 , V_27 , V_58 ) ;
if ( V_97 )
goto V_371;
if ( V_65 )
F_226 ( V_3 , V_65 ) ;
V_97 = F_234 ( V_78 , V_3 ) ;
if ( V_97 < 0 )
goto V_372;
V_313 ++ ;
F_80 ( V_78 ) ;
return 0 ;
V_372:
F_228 ( V_77 ) ;
V_371:
F_244 ( V_3 ) ;
return V_97 ;
}
static int F_245 ( struct V_188 * V_356 [] , struct V_188 * V_65 [] )
{
V_198 V_373 = V_271 ;
T_3 V_58 = V_59 ;
int V_374 ;
bool V_375 , V_51 , V_27 ;
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_357 ] )
V_373 = F_138 ( V_65 [ V_357 ] ) ;
if ( V_65 [ V_358 ] )
V_58 = F_142 ( V_65 [ V_358 ] ) ;
switch ( V_373 ) {
case V_271 :
case V_376 :
if ( V_58 < V_377 ||
V_58 > V_378 )
return - V_113 ;
break;
default:
return - V_113 ;
}
if ( V_65 [ V_347 ] ) {
if ( F_142 ( V_65 [ V_347 ] ) >= V_181 )
return - V_113 ;
}
for ( V_374 = V_347 + 1 ;
V_374 < V_355 ;
V_374 ++ ) {
if ( V_65 [ V_374 ] ) {
if ( F_142 ( V_65 [ V_374 ] ) > 1 )
return - V_113 ;
}
}
V_375 = V_65 [ V_352 ] ? F_142 ( V_65 [ V_352 ] ) : false ;
V_27 = V_65 [ V_351 ] ? F_142 ( V_65 [ V_351 ] ) : false ;
V_51 = V_65 [ V_353 ] ? F_142 ( V_65 [ V_353 ] ) : false ;
if ( ( V_27 && ( V_51 || V_375 ) ) || ( V_51 && V_375 ) )
return - V_113 ;
if ( V_65 [ V_355 ] &&
F_142 ( V_65 [ V_355 ] ) > V_379 )
return - V_113 ;
if ( ( V_65 [ V_354 ] &&
F_142 ( V_65 [ V_354 ] ) ) &&
! V_65 [ V_348 ] )
return - V_113 ;
return 0 ;
}
static struct V_187 * F_246 ( const struct V_2 * V_3 )
{
return F_247 ( F_1 ( V_3 ) -> V_78 ) ;
}
static T_6 F_248 ( const struct V_2 * V_3 )
{
return 0 +
F_249 ( 8 ) +
F_250 ( 1 ) +
F_249 ( 8 ) +
F_250 ( 4 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
F_250 ( 1 ) +
0 ;
}
static int F_251 ( struct V_22 * V_23 ,
const struct V_2 * V_3 )
{
struct V_40 * V_41 = & F_1 ( V_3 ) -> V_41 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
if ( F_139 ( V_23 , V_359 , V_41 -> V_27 ,
V_380 ) ||
F_181 ( V_23 , V_358 , V_41 -> V_58 ) ||
F_140 ( V_23 , V_357 ,
V_271 , V_380 ) ||
F_181 ( V_23 , V_347 , V_44 -> V_61 ) ||
F_181 ( V_23 , V_349 , V_44 -> V_56 ) ||
F_181 ( V_23 , V_350 , V_41 -> V_75 ) ||
F_181 ( V_23 , V_351 , V_44 -> V_46 ) ||
F_181 ( V_23 , V_352 , V_44 -> V_50 ) ||
F_181 ( V_23 , V_353 , V_44 -> V_51 ) ||
F_181 ( V_23 , V_354 , V_41 -> V_129 ) ||
F_181 ( V_23 , V_355 , V_41 -> V_131 ) ||
0 )
goto V_295;
if ( V_41 -> V_129 ) {
if ( F_172 ( V_23 , V_348 , V_41 -> V_128 ) )
goto V_295;
}
return 0 ;
V_295:
return - V_229 ;
}
static bool F_252 ( struct V_2 * V_3 )
{
return F_253 ( V_3 -> V_368 ) == F_110 ;
}
static int F_254 ( struct V_381 * V_382 , unsigned long V_383 ,
void * V_7 )
{
struct V_2 * V_78 = F_255 ( V_7 ) ;
F_256 ( V_12 ) ;
if ( ! F_252 ( V_78 ) )
return V_384 ;
switch ( V_383 ) {
case V_385 : {
struct V_1 * V_386 , * V_387 ;
struct V_4 * V_155 ;
V_155 = F_5 ( V_78 ) ;
F_257 (m, n, &rxd->secys, secys) {
F_229 ( V_386 -> V_41 . V_151 , & V_12 ) ;
}
F_258 ( & V_12 ) ;
break;
}
case V_388 : {
struct V_1 * V_386 ;
struct V_4 * V_155 ;
V_155 = F_5 ( V_78 ) ;
F_128 (m, &rxd->secys, secys) {
struct V_2 * V_3 = V_386 -> V_41 . V_151 ;
unsigned int V_119 = V_78 -> V_119 - ( V_386 -> V_41 . V_58 +
F_29 ( true ) ) ;
if ( V_3 -> V_119 > V_119 )
F_259 ( V_3 , V_119 ) ;
}
}
}
return V_389 ;
}
static int T_13 F_260 ( void )
{
int V_97 ;
F_261 ( L_5 ) ;
V_97 = F_262 ( & V_390 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_263 ( & V_391 ) ;
if ( V_97 )
goto V_392;
V_97 = F_264 ( & V_292 , V_393 ) ;
if ( V_97 )
goto V_394;
return 0 ;
V_394:
F_265 ( & V_391 ) ;
V_392:
F_266 ( & V_390 ) ;
return V_97 ;
}
static void T_14 F_267 ( void )
{
F_268 ( & V_292 ) ;
F_265 ( & V_391 ) ;
F_266 ( & V_390 ) ;
F_269 () ;
}
