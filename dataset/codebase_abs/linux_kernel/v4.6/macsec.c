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
static struct V_22 * F_58 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
int V_87 ;
struct V_99 V_100 [ V_101 + 1 ] ;
unsigned char V_70 [ V_102 ] ;
struct V_103 * V_33 ;
struct V_29 * V_104 ;
T_6 V_105 ;
struct V_106 * V_98 ;
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
F_59 ( V_23 ) ;
return F_60 ( - V_107 ) ;
}
if ( F_61 ( F_62 ( V_23 ) < V_108 ||
F_63 ( V_23 ) < V_109 ) ) {
struct V_22 * V_110 = F_64 ( V_23 ,
V_108 ,
V_109 ,
V_111 ) ;
if ( F_51 ( V_110 ) ) {
F_65 ( V_23 ) ;
V_23 = V_110 ;
} else {
F_22 ( V_72 ) ;
F_59 ( V_23 ) ;
return F_60 ( - V_112 ) ;
}
} else {
V_23 = F_66 ( V_23 , V_111 ) ;
if ( ! V_23 ) {
F_22 ( V_72 ) ;
return F_60 ( - V_112 ) ;
}
}
V_105 = V_23 -> V_66 ;
V_33 = F_44 ( V_23 ) ;
V_104 = (struct V_29 * ) F_67 ( V_23 , F_29 ( V_44 -> V_46 ) ) ;
memmove ( V_104 , V_33 , 2 * V_28 ) ;
V_42 = F_38 ( V_72 , V_41 ) ;
if ( V_42 == 0 ) {
F_22 ( V_72 ) ;
F_59 ( V_23 ) ;
return F_60 ( - V_113 ) ;
}
F_30 ( V_104 , V_41 , V_42 ) ;
F_33 ( V_104 , V_105 - 2 * V_28 ) ;
F_35 ( V_70 , V_41 -> V_27 , V_42 ) ;
F_68 ( V_23 , V_41 -> V_58 ) ;
if ( V_23 -> V_66 - V_38 > F_1 ( V_3 ) -> V_78 -> V_114 ) {
struct V_115 * V_116 = F_46 ( V_77 -> V_15 ) ;
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_117 ++ ;
F_49 ( & V_116 -> V_82 ) ;
F_22 ( V_72 ) ;
F_59 ( V_23 ) ;
return F_60 ( - V_107 ) ;
}
V_98 = F_69 ( V_72 -> V_18 . V_19 , V_111 ) ;
if ( ! V_98 ) {
F_22 ( V_72 ) ;
F_59 ( V_23 ) ;
return F_60 ( - V_112 ) ;
}
F_70 ( V_100 , V_101 + 1 ) ;
F_71 ( V_23 , V_100 , 0 , V_23 -> V_66 ) ;
if ( V_44 -> V_56 ) {
int V_66 = V_23 -> V_66 - F_28 ( V_44 -> V_46 ) -
V_41 -> V_58 ;
F_72 ( V_98 , V_100 , V_100 , V_66 , V_70 ) ;
F_73 ( V_98 , F_28 ( V_44 -> V_46 ) ) ;
} else {
F_72 ( V_98 , V_100 , V_100 , 0 , V_70 ) ;
F_73 ( V_98 , V_23 -> V_66 - V_41 -> V_58 ) ;
}
F_23 ( V_23 ) -> V_98 = V_98 ;
F_23 ( V_23 ) -> V_72 = V_72 ;
F_74 ( V_98 , 0 , F_52 , V_23 ) ;
F_75 ( V_23 -> V_3 ) ;
V_87 = F_76 ( V_98 ) ;
if ( V_87 == - V_118 ) {
return F_60 ( V_87 ) ;
} else if ( V_87 != 0 ) {
F_57 ( V_23 -> V_3 ) ;
F_59 ( V_23 ) ;
F_53 ( V_98 ) ;
F_22 ( V_72 ) ;
return F_60 ( - V_107 ) ;
}
F_57 ( V_23 -> V_3 ) ;
F_53 ( V_98 ) ;
F_22 ( V_72 ) ;
return V_23 ;
}
static bool F_77 ( struct V_22 * V_23 , struct V_40 * V_41 , T_5 V_42 )
{
struct V_6 * V_119 = F_23 ( V_23 ) -> V_119 ;
struct V_120 * V_121 = F_46 ( V_119 -> V_16 -> V_15 ) ;
struct V_29 * V_30 = F_36 ( V_23 ) ;
T_5 V_122 = 0 ;
F_78 ( & V_119 -> V_73 ) ;
if ( V_119 -> V_74 >= V_41 -> V_123 )
V_122 = V_119 -> V_74 - V_41 -> V_123 ;
if ( V_41 -> V_124 && V_42 < V_122 ) {
F_79 ( & V_119 -> V_73 ) ;
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_125 ++ ;
F_49 ( & V_121 -> V_82 ) ;
return false ;
}
if ( V_41 -> V_126 != V_127 ) {
F_47 ( & V_121 -> V_82 ) ;
if ( V_30 -> V_45 & V_128 )
V_121 -> V_15 . V_129 += V_23 -> V_66 ;
else
V_121 -> V_15 . V_130 += V_23 -> V_66 ;
F_49 ( & V_121 -> V_82 ) ;
}
if ( ! F_23 ( V_23 ) -> V_131 ) {
F_79 ( & V_119 -> V_73 ) ;
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_126 == V_132 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_133 ++ ;
F_49 ( & V_121 -> V_82 ) ;
return false ;
}
F_47 ( & V_121 -> V_82 ) ;
if ( V_41 -> V_126 == V_134 ) {
V_121 -> V_15 . V_135 ++ ;
F_48 ( V_119 -> V_15 -> V_135 ) ;
} else if ( V_42 < V_122 ) {
V_121 -> V_15 . V_136 ++ ;
} else {
V_121 -> V_15 . V_137 ++ ;
}
F_49 ( & V_121 -> V_82 ) ;
} else {
F_47 ( & V_121 -> V_82 ) ;
if ( V_42 < V_122 ) {
V_121 -> V_15 . V_136 ++ ;
} else {
V_121 -> V_15 . V_138 ++ ;
F_48 ( V_119 -> V_15 -> V_138 ) ;
}
F_49 ( & V_121 -> V_82 ) ;
if ( V_42 >= V_119 -> V_74 )
V_119 -> V_74 = V_42 + 1 ;
F_79 ( & V_119 -> V_73 ) ;
}
return true ;
}
static void F_80 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
V_23 -> V_139 = V_140 ;
V_23 -> V_79 = F_81 ( V_23 , V_3 ) ;
F_82 ( V_23 ) ;
if ( ! F_83 ( V_23 ) )
F_84 ( V_23 ) ;
F_85 ( V_23 ) ;
}
static void F_86 ( struct V_22 * V_23 , T_3 V_58 , T_3 V_141 )
{
memmove ( V_23 -> V_65 + V_141 , V_23 -> V_65 , 2 * V_28 ) ;
F_87 ( V_23 , V_141 ) ;
F_88 ( V_23 , V_23 -> V_66 - V_58 ) ;
}
static void F_89 ( struct V_2 * V_3 , int V_66 )
{
struct V_90 * V_15 = F_46 ( V_3 -> V_91 ) ;
F_47 ( & V_15 -> V_82 ) ;
V_15 -> V_142 ++ ;
V_15 -> V_143 += V_66 ;
F_49 ( & V_15 -> V_82 ) ;
}
static void F_90 ( struct V_95 * V_96 , int V_97 )
{
struct V_22 * V_23 = V_96 -> V_65 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_6 * V_119 = F_23 ( V_23 ) -> V_119 ;
int V_66 , V_87 ;
T_5 V_42 ;
F_53 ( F_23 ( V_23 ) -> V_98 ) ;
F_54 () ;
V_42 = F_91 ( F_36 ( V_23 ) -> V_55 ) ;
if ( ! F_77 ( V_23 , & V_77 -> V_41 , V_42 ) ) {
F_56 () ;
F_59 ( V_23 ) ;
goto V_144;
}
F_86 ( V_23 , V_77 -> V_41 . V_58 ,
F_29 ( F_23 ( V_23 ) -> V_145 ) ) ;
F_80 ( V_23 , V_77 -> V_41 . V_146 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_92 ( V_23 ) ;
if ( V_87 == V_147 )
F_89 ( V_3 , V_66 ) ;
else
V_77 -> V_41 . V_146 -> V_15 . V_148 ++ ;
F_56 () ;
V_144:
F_19 ( V_119 ) ;
F_57 ( V_3 ) ;
return;
}
static struct V_22 * F_93 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
struct V_6 * V_119 ,
T_2 V_27 ,
struct V_40 * V_41 )
{
int V_87 ;
struct V_99 V_100 [ V_101 + 1 ] ;
unsigned char V_70 [ V_102 ] ;
struct V_106 * V_98 ;
struct V_29 * V_30 ;
T_7 V_58 = V_41 -> V_58 ;
F_23 ( V_23 ) -> V_131 = false ;
V_23 = F_94 ( V_23 , V_111 ) ;
if ( ! V_23 )
return F_60 ( - V_112 ) ;
V_98 = F_69 ( V_119 -> V_18 . V_19 , V_111 ) ;
if ( ! V_98 ) {
F_59 ( V_23 ) ;
return F_60 ( - V_112 ) ;
}
V_30 = (struct V_29 * ) V_23 -> V_65 ;
F_35 ( V_70 , V_27 , F_91 ( V_30 -> V_55 ) ) ;
F_70 ( V_100 , V_101 + 1 ) ;
F_71 ( V_23 , V_100 , 0 , V_23 -> V_66 ) ;
if ( V_30 -> V_45 & V_128 ) {
int V_66 = V_23 -> V_66 - F_28 ( F_23 ( V_23 ) -> V_145 ) ;
F_72 ( V_98 , V_100 , V_100 , V_66 , V_70 ) ;
F_73 ( V_98 , F_28 ( F_23 ( V_23 ) -> V_145 ) ) ;
V_23 = F_66 ( V_23 , V_111 ) ;
if ( ! V_23 ) {
F_53 ( V_98 ) ;
return F_60 ( - V_112 ) ;
}
} else {
F_72 ( V_98 , V_100 , V_100 , V_58 , V_70 ) ;
F_73 ( V_98 , V_23 -> V_66 - V_58 ) ;
}
F_23 ( V_23 ) -> V_98 = V_98 ;
F_23 ( V_23 ) -> V_119 = V_119 ;
V_23 -> V_3 = V_3 ;
F_74 ( V_98 , 0 , F_90 , V_23 ) ;
F_75 ( V_3 ) ;
V_87 = F_95 ( V_98 ) ;
if ( V_87 == - V_118 ) {
return F_60 ( V_87 ) ;
} else if ( V_87 != 0 ) {
if ( V_87 != - V_149 ) {
F_59 ( V_23 ) ;
V_23 = F_60 ( V_87 ) ;
}
} else {
F_23 ( V_23 ) -> V_131 = true ;
}
F_57 ( V_3 ) ;
F_53 ( V_98 ) ;
return V_23 ;
}
static struct V_13 * F_96 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 ;
F_97 (secy, rx_sc) {
if ( V_14 -> V_27 == V_27 )
return V_14 ;
}
return NULL ;
}
static struct V_13 * F_98 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 ;
F_99 (secy, rx_sc) {
if ( V_14 -> V_27 == V_27 )
return V_14 ;
}
return NULL ;
}
static void F_100 ( struct V_22 * V_23 )
{
struct V_4 * V_150 ;
struct V_1 * V_77 ;
F_101 () ;
V_150 = F_3 ( V_23 -> V_3 ) ;
F_102 (macsec, &rxd->secys, secys) {
struct V_22 * V_110 ;
int V_87 ;
struct V_115 * V_116 = F_46 ( V_77 -> V_15 ) ;
if ( V_77 -> V_41 . V_126 == V_132 ) {
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_151 ++ ;
F_49 ( & V_116 -> V_82 ) ;
continue;
}
V_110 = F_103 ( V_23 , V_111 ) ;
if ( ! V_110 )
break;
V_110 -> V_3 = V_77 -> V_41 . V_146 ;
V_87 = F_92 ( V_110 ) ;
if ( V_87 == V_147 ) {
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_152 ++ ;
F_49 ( & V_116 -> V_82 ) ;
} else {
V_77 -> V_41 . V_146 -> V_15 . V_148 ++ ;
}
}
F_104 () ;
}
static T_8 F_105 ( struct V_22 * * V_153 )
{
struct V_22 * V_23 = * V_153 ;
struct V_2 * V_3 = V_23 -> V_3 ;
struct V_29 * V_30 ;
struct V_40 * V_41 = NULL ;
struct V_13 * V_14 ;
struct V_6 * V_119 ;
struct V_4 * V_150 ;
struct V_1 * V_77 ;
T_2 V_27 ;
T_5 V_42 ;
bool V_154 ;
struct V_120 * V_121 ;
struct V_115 * V_116 ;
bool V_155 ;
if ( F_62 ( V_23 ) < V_38 )
goto V_156;
V_30 = F_36 ( V_23 ) ;
if ( V_30 -> V_33 . V_47 != F_31 ( V_48 ) ) {
F_100 ( V_23 ) ;
return V_157 ;
}
V_23 = F_66 ( V_23 , V_111 ) ;
if ( ! V_23 ) {
* V_153 = NULL ;
return V_158 ;
}
V_155 = F_106 ( V_23 , F_29 ( true ) ) ;
if ( ! V_155 ) {
if ( ! F_106 ( V_23 , F_29 ( false ) ) )
goto V_156;
}
V_30 = F_36 ( V_23 ) ;
if ( ( V_30 -> V_45 & ( V_60 | V_128 ) ) == V_128 )
return V_157 ;
if ( V_30 -> V_45 & V_52 ) {
if ( ! V_155 )
goto V_156;
}
F_67 ( V_23 , V_38 ) ;
F_23 ( V_23 ) -> V_145 = ! ! ( V_30 -> V_45 & V_52 ) ;
F_23 ( V_23 ) -> V_159 = V_30 -> V_45 & V_160 ;
V_27 = F_26 ( V_30 , F_23 ( V_23 ) -> V_145 ) ;
F_101 () ;
V_150 = F_3 ( V_23 -> V_3 ) ;
F_102 (macsec, &rxd->secys, secys) {
struct V_13 * V_16 = F_96 ( & V_77 -> V_41 , V_27 ) ;
if ( V_16 ) {
V_41 = & V_77 -> V_41 ;
V_14 = V_16 ;
break;
}
}
if ( ! V_41 )
goto V_161;
V_3 = V_41 -> V_146 ;
V_77 = F_1 ( V_3 ) ;
V_116 = F_46 ( V_77 -> V_15 ) ;
V_121 = F_46 ( V_14 -> V_15 ) ;
if ( ! F_34 ( V_23 , V_41 -> V_58 ) ) {
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_162 ++ ;
F_49 ( & V_116 -> V_82 ) ;
goto V_163;
}
V_119 = F_7 ( V_14 -> V_8 [ F_23 ( V_23 ) -> V_159 ] ) ;
if ( ! V_119 ) {
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_126 == V_132 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_164 ++ ;
F_49 ( & V_121 -> V_82 ) ;
goto V_163;
}
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_165 ++ ;
F_49 ( & V_121 -> V_82 ) ;
goto V_166;
}
V_42 = F_91 ( V_30 -> V_55 ) ;
if ( V_41 -> V_124 ) {
bool V_167 ;
F_78 ( & V_119 -> V_73 ) ;
V_167 = V_119 -> V_74 >= V_41 -> V_123 &&
V_42 < ( V_119 -> V_74 - V_41 -> V_123 ) ;
F_79 ( & V_119 -> V_73 ) ;
if ( V_167 ) {
F_47 ( & V_121 -> V_82 ) ;
V_121 -> V_15 . V_125 ++ ;
F_49 ( & V_121 -> V_82 ) ;
goto V_168;
}
}
if ( V_30 -> V_45 & V_60 ||
V_41 -> V_126 != V_127 )
V_23 = F_93 ( V_23 , V_3 , V_119 , V_27 , V_41 ) ;
if ( F_107 ( V_23 ) ) {
if ( F_108 ( V_23 ) != - V_118 )
F_19 ( V_119 ) ;
F_104 () ;
* V_153 = NULL ;
return V_158 ;
}
if ( ! F_77 ( V_23 , V_41 , V_42 ) )
goto V_168;
V_166:
F_86 ( V_23 , V_41 -> V_58 ,
F_29 ( F_23 ( V_23 ) -> V_145 ) ) ;
F_80 ( V_23 , V_41 -> V_146 ) ;
if ( V_119 )
F_19 ( V_119 ) ;
F_89 ( V_3 , V_23 -> V_66 ) ;
F_104 () ;
* V_153 = V_23 ;
return V_169 ;
V_168:
F_19 ( V_119 ) ;
V_163:
F_104 () ;
V_156:
F_59 ( V_23 ) ;
* V_153 = NULL ;
return V_158 ;
V_161:
V_154 = ! ! ( V_30 -> V_45 & V_60 ) ;
if ( ! V_154 )
F_86 ( V_23 , V_59 ,
F_29 ( F_23 ( V_23 ) -> V_145 ) ) ;
F_102 (macsec, &rxd->secys, secys) {
struct V_22 * V_110 ;
int V_87 ;
V_116 = F_46 ( V_77 -> V_15 ) ;
if ( V_154 ||
V_77 -> V_41 . V_126 == V_132 ) {
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_170 ++ ;
F_49 ( & V_116 -> V_82 ) ;
continue;
}
V_110 = F_103 ( V_23 , V_111 ) ;
if ( ! V_110 )
break;
F_80 ( V_110 , V_77 -> V_41 . V_146 ) ;
V_87 = F_92 ( V_110 ) ;
if ( V_87 == V_147 ) {
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_171 ++ ;
F_49 ( & V_116 -> V_82 ) ;
} else {
V_77 -> V_41 . V_146 -> V_15 . V_148 ++ ;
}
}
F_104 () ;
* V_153 = V_23 ;
return V_157 ;
}
static struct V_172 * F_109 ( char * V_18 , int V_173 , int V_58 )
{
struct V_172 * V_19 ;
int V_87 ;
V_19 = F_110 ( L_2 , 0 , V_174 ) ;
if ( ! V_19 || F_107 ( V_19 ) )
return NULL ;
V_87 = F_111 ( V_19 , V_18 , V_173 ) ;
if ( V_87 < 0 ) {
F_18 ( V_19 ) ;
return NULL ;
}
V_87 = F_112 ( V_19 , V_58 ) ;
if ( V_87 < 0 ) {
F_18 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static int F_113 ( struct V_6 * V_119 , char * V_175 , int V_173 ,
int V_58 )
{
V_119 -> V_15 = F_114 ( struct V_176 ) ;
if ( ! V_119 -> V_15 )
return - 1 ;
V_119 -> V_18 . V_19 = F_109 ( V_175 , V_173 , V_58 ) ;
if ( ! V_119 -> V_18 . V_19 ) {
F_11 ( V_119 -> V_15 ) ;
return - 1 ;
}
V_119 -> V_9 = false ;
V_119 -> V_74 = 1 ;
F_115 ( & V_119 -> V_10 , 1 ) ;
F_116 ( & V_119 -> V_73 ) ;
return 0 ;
}
static void F_117 ( struct V_6 * V_119 )
{
V_119 -> V_9 = false ;
F_19 ( V_119 ) ;
}
static void F_118 ( struct V_13 * V_14 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < V_178 ; V_177 ++ ) {
struct V_6 * V_8 = F_6 ( V_14 -> V_8 [ V_177 ] ) ;
F_119 ( V_14 -> V_8 [ V_177 ] , NULL ) ;
if ( V_8 )
F_117 ( V_8 ) ;
}
F_14 ( V_14 ) ;
}
static struct V_13 * F_120 ( struct V_40 * V_41 , T_2 V_27 )
{
struct V_13 * V_14 , T_1 * * V_179 ;
for ( V_179 = & V_41 -> V_14 , V_14 = F_6 ( * V_179 ) ;
V_14 ;
V_179 = & V_14 -> V_180 , V_14 = F_6 ( * V_179 ) ) {
if ( V_14 -> V_27 == V_27 ) {
if ( V_14 -> V_9 )
V_41 -> V_49 -- ;
F_121 ( * V_179 , V_14 -> V_180 ) ;
return V_14 ;
}
}
return NULL ;
}
static struct V_13 * F_122 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_13 * V_14 ;
struct V_1 * V_77 ;
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
struct V_4 * V_150 = F_5 ( V_78 ) ;
struct V_40 * V_41 ;
F_123 (macsec, &rxd->secys, secys) {
if ( F_98 ( & V_77 -> V_41 , V_27 ) )
return F_60 ( - V_181 ) ;
}
V_14 = F_124 ( sizeof( * V_14 ) , V_182 ) ;
if ( ! V_14 )
return F_60 ( - V_112 ) ;
V_14 -> V_15 = F_125 ( struct V_120 ) ;
if ( ! V_14 -> V_15 ) {
F_12 ( V_14 ) ;
return F_60 ( - V_112 ) ;
}
V_14 -> V_27 = V_27 ;
V_14 -> V_9 = true ;
F_115 ( & V_14 -> V_10 , 1 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
F_121 ( V_14 -> V_180 , V_41 -> V_14 ) ;
F_121 ( V_41 -> V_14 , V_14 ) ;
if ( V_14 -> V_9 )
V_41 -> V_49 ++ ;
return V_14 ;
}
static int F_126 ( struct V_20 * V_72 , char * V_175 , int V_173 ,
int V_58 )
{
V_72 -> V_15 = F_114 ( struct V_183 ) ;
if ( ! V_72 -> V_15 )
return - 1 ;
V_72 -> V_18 . V_19 = F_109 ( V_175 , V_173 , V_58 ) ;
if ( ! V_72 -> V_18 . V_19 ) {
F_11 ( V_72 -> V_15 ) ;
return - 1 ;
}
V_72 -> V_9 = false ;
F_115 ( & V_72 -> V_10 , 1 ) ;
F_116 ( & V_72 -> V_73 ) ;
return 0 ;
}
static void F_127 ( struct V_20 * V_72 )
{
V_72 -> V_9 = false ;
F_22 ( V_72 ) ;
}
static struct V_2 * F_128 ( struct V_184 * V_184 ,
struct V_185 * * V_186 )
{
int V_187 = F_129 ( V_186 [ V_188 ] ) ;
struct V_2 * V_3 ;
V_3 = F_130 ( V_184 , V_187 ) ;
if ( ! V_3 )
return F_60 ( - V_189 ) ;
if ( ! F_131 ( V_3 ) )
return F_60 ( - V_189 ) ;
return V_3 ;
}
static T_2 F_132 ( const struct V_185 * V_190 )
{
return ( V_191 T_2 ) F_133 ( V_190 ) ;
}
static int F_134 ( struct V_22 * V_23 , int V_192 , T_2 V_193 )
{
return F_135 ( V_23 , V_192 , ( V_191 V_194 ) V_193 ) ;
}
static struct V_20 * F_136 ( struct V_184 * V_184 ,
struct V_185 * * V_186 ,
struct V_185 * * V_195 ,
struct V_2 * * V_196 ,
struct V_40 * * V_197 ,
struct V_43 * * V_198 ,
T_3 * V_159 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
if ( ! V_195 [ V_199 ] )
return F_60 ( - V_107 ) ;
* V_159 = F_137 ( V_195 [ V_199 ] ) ;
V_3 = F_128 ( V_184 , V_186 ) ;
if ( F_107 ( V_3 ) )
return F_138 ( V_3 ) ;
if ( * V_159 >= V_178 )
return F_60 ( - V_107 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_72 = F_6 ( V_44 -> V_8 [ * V_159 ] ) ;
if ( ! V_72 )
return F_60 ( - V_189 ) ;
* V_196 = V_3 ;
* V_198 = V_44 ;
* V_197 = V_41 ;
return V_72 ;
}
static struct V_13 * F_139 ( struct V_184 * V_184 ,
struct V_185 * * V_186 ,
struct V_185 * * V_200 ,
struct V_2 * * V_196 ,
struct V_40 * * V_197 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
V_3 = F_128 ( V_184 , V_186 ) ;
if ( F_107 ( V_3 ) )
return F_138 ( V_3 ) ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( ! V_200 [ V_201 ] )
return F_60 ( - V_107 ) ;
V_27 = F_132 ( V_200 [ V_201 ] ) ;
V_14 = F_98 ( V_41 , V_27 ) ;
if ( ! V_14 )
return F_60 ( - V_189 ) ;
* V_197 = V_41 ;
* V_196 = V_3 ;
return V_14 ;
}
static struct V_6 * F_140 ( struct V_184 * V_184 ,
struct V_185 * * V_186 ,
struct V_185 * * V_200 ,
struct V_185 * * V_195 ,
struct V_2 * * V_196 ,
struct V_40 * * V_197 ,
struct V_13 * * V_198 ,
T_3 * V_159 )
{
struct V_13 * V_14 ;
struct V_6 * V_119 ;
if ( ! V_195 [ V_199 ] )
return F_60 ( - V_107 ) ;
* V_159 = F_137 ( V_195 [ V_199 ] ) ;
if ( * V_159 >= V_178 )
return F_60 ( - V_107 ) ;
V_14 = F_139 ( V_184 , V_186 , V_200 , V_196 , V_197 ) ;
if ( F_107 ( V_14 ) )
return F_138 ( V_14 ) ;
V_119 = F_6 ( V_14 -> V_8 [ * V_159 ] ) ;
if ( ! V_119 )
return F_60 ( - V_189 ) ;
* V_198 = V_14 ;
return V_119 ;
}
static int F_141 ( struct V_185 * * V_186 , struct V_185 * * V_195 )
{
if ( ! V_186 [ V_202 ] )
return - V_107 ;
if ( F_142 ( V_195 , V_203 , V_186 [ V_202 ] ,
V_204 ) )
return - V_107 ;
return 0 ;
}
static int F_143 ( struct V_185 * * V_186 , struct V_185 * * V_200 )
{
if ( ! V_186 [ V_205 ] )
return - V_107 ;
if ( F_142 ( V_200 , V_206 , V_186 [ V_205 ] ,
V_207 ) )
return - V_107 ;
return 0 ;
}
static bool F_144 ( struct V_185 * * V_186 )
{
if ( ! V_186 [ V_199 ] ||
! V_186 [ V_208 ] ||
! V_186 [ V_209 ] )
return false ;
if ( F_137 ( V_186 [ V_199 ] ) >= V_178 )
return false ;
if ( V_186 [ V_210 ] && F_129 ( V_186 [ V_210 ] ) == 0 )
return false ;
if ( V_186 [ V_211 ] ) {
if ( F_137 ( V_186 [ V_211 ] ) > 1 )
return false ;
}
if ( F_145 ( V_186 [ V_209 ] ) != V_212 )
return false ;
return true ;
}
static int F_146 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_2 * V_3 ;
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_119 ;
unsigned char V_159 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
if ( ! F_144 ( V_195 ) )
return - V_107 ;
F_147 () ;
V_14 = F_139 ( F_148 ( V_214 ) , V_186 , V_200 , & V_3 , & V_41 ) ;
if ( F_107 ( V_14 ) || ! F_13 ( V_14 ) ) {
F_149 () ;
return F_108 ( V_14 ) ;
}
V_159 = F_137 ( V_195 [ V_199 ] ) ;
if ( F_145 ( V_195 [ V_208 ] ) != V_41 -> V_173 ) {
F_150 ( L_3 ,
F_145 ( V_195 [ V_208 ] ) , V_41 -> V_173 ) ;
F_149 () ;
return - V_107 ;
}
V_119 = F_6 ( V_14 -> V_8 [ V_159 ] ) ;
if ( V_119 ) {
F_149 () ;
return - V_215 ;
}
V_119 = F_151 ( sizeof( * V_119 ) , V_182 ) ;
if ( ! V_119 || F_113 ( V_119 , F_152 ( V_195 [ V_208 ] ) ,
V_41 -> V_173 , V_41 -> V_58 ) ) {
F_12 ( V_119 ) ;
F_149 () ;
return - V_112 ;
}
if ( V_195 [ V_210 ] ) {
F_39 ( & V_119 -> V_73 ) ;
V_119 -> V_74 = F_129 ( V_195 [ V_210 ] ) ;
F_41 ( & V_119 -> V_73 ) ;
}
if ( V_195 [ V_211 ] )
V_119 -> V_9 = ! ! F_137 ( V_195 [ V_211 ] ) ;
F_153 ( V_119 -> V_18 . V_216 , V_195 [ V_208 ] , V_212 ) ;
V_119 -> V_16 = V_14 ;
F_121 ( V_14 -> V_8 [ V_159 ] , V_119 ) ;
F_149 () ;
return 0 ;
}
static bool F_154 ( struct V_185 * * V_186 )
{
if ( ! V_186 [ V_201 ] )
return false ;
if ( V_186 [ V_217 ] ) {
if ( F_137 ( V_186 [ V_217 ] ) > 1 )
return false ;
}
return true ;
}
static int F_155 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_2 * V_3 ;
T_2 V_27 = V_218 ;
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_13 * V_14 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
if ( ! F_154 ( V_200 ) )
return - V_107 ;
F_147 () ;
V_3 = F_128 ( F_148 ( V_214 ) , V_186 ) ;
if ( F_107 ( V_3 ) ) {
F_149 () ;
return F_108 ( V_3 ) ;
}
V_27 = F_132 ( V_200 [ V_201 ] ) ;
V_14 = F_122 ( V_3 , V_27 ) ;
if ( F_107 ( V_14 ) ) {
F_149 () ;
return F_108 ( V_14 ) ;
}
if ( V_200 [ V_217 ] )
V_14 -> V_9 = ! ! F_137 ( V_200 [ V_217 ] ) ;
F_149 () ;
return 0 ;
}
static bool F_156 ( struct V_185 * * V_186 )
{
if ( ! V_186 [ V_199 ] ||
! V_186 [ V_210 ] ||
! V_186 [ V_208 ] ||
! V_186 [ V_209 ] )
return false ;
if ( F_137 ( V_186 [ V_199 ] ) >= V_178 )
return false ;
if ( F_129 ( V_186 [ V_210 ] ) == 0 )
return false ;
if ( V_186 [ V_211 ] ) {
if ( F_137 ( V_186 [ V_211 ] ) > 1 )
return false ;
}
if ( F_145 ( V_186 [ V_209 ] ) != V_212 )
return false ;
return true ;
}
static int F_157 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_2 * V_3 ;
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
unsigned char V_159 ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
if ( ! F_156 ( V_195 ) )
return - V_107 ;
F_147 () ;
V_3 = F_128 ( F_148 ( V_214 ) , V_186 ) ;
if ( F_107 ( V_3 ) ) {
F_149 () ;
return F_108 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
V_159 = F_137 ( V_195 [ V_199 ] ) ;
if ( F_145 ( V_195 [ V_208 ] ) != V_41 -> V_173 ) {
F_150 ( L_4 ,
F_145 ( V_195 [ V_208 ] ) , V_41 -> V_173 ) ;
F_149 () ;
return - V_107 ;
}
V_72 = F_6 ( V_44 -> V_8 [ V_159 ] ) ;
if ( V_72 ) {
F_149 () ;
return - V_215 ;
}
V_72 = F_151 ( sizeof( * V_72 ) , V_182 ) ;
if ( ! V_72 || F_126 ( V_72 , F_152 ( V_195 [ V_208 ] ) ,
V_41 -> V_173 , V_41 -> V_58 ) ) {
F_12 ( V_72 ) ;
F_149 () ;
return - V_112 ;
}
F_153 ( V_72 -> V_18 . V_216 , V_195 [ V_208 ] , V_212 ) ;
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_129 ( V_195 [ V_210 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
if ( V_195 [ V_211 ] )
V_72 -> V_9 = ! ! F_137 ( V_195 [ V_211 ] ) ;
if ( V_159 == V_44 -> V_61 && V_72 -> V_9 )
V_41 -> V_76 = true ;
F_121 ( V_44 -> V_8 [ V_159 ] , V_72 ) ;
F_149 () ;
return 0 ;
}
static int F_158 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_119 ;
T_3 V_159 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
F_147 () ;
V_119 = F_140 ( F_148 ( V_214 ) , V_186 , V_200 , V_195 ,
& V_3 , & V_41 , & V_14 , & V_159 ) ;
if ( F_107 ( V_119 ) ) {
F_149 () ;
return F_108 ( V_119 ) ;
}
if ( V_119 -> V_9 ) {
F_149 () ;
return - V_215 ;
}
F_119 ( V_14 -> V_8 [ V_159 ] , NULL ) ;
F_117 ( V_119 ) ;
F_149 () ;
return 0 ;
}
static int F_159 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
T_2 V_27 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
if ( ! V_200 [ V_201 ] )
return - V_107 ;
F_147 () ;
V_3 = F_128 ( F_148 ( V_214 ) , V_214 -> V_186 ) ;
if ( F_107 ( V_3 ) ) {
F_149 () ;
return F_108 ( V_3 ) ;
}
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_27 = F_132 ( V_200 [ V_201 ] ) ;
V_14 = F_120 ( V_41 , V_27 ) ;
if ( ! V_14 ) {
F_149 () ;
return - V_189 ;
}
F_118 ( V_14 ) ;
F_149 () ;
return 0 ;
}
static int F_160 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_159 ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
F_147 () ;
V_72 = F_136 ( F_148 ( V_214 ) , V_186 , V_195 ,
& V_3 , & V_41 , & V_44 , & V_159 ) ;
if ( F_107 ( V_72 ) ) {
F_149 () ;
return F_108 ( V_72 ) ;
}
if ( V_72 -> V_9 ) {
F_149 () ;
return - V_215 ;
}
F_119 ( V_44 -> V_8 [ V_159 ] , NULL ) ;
F_127 ( V_72 ) ;
F_149 () ;
return 0 ;
}
static bool F_161 ( struct V_185 * * V_186 )
{
if ( ! V_186 [ V_199 ] ||
V_186 [ V_208 ] ||
V_186 [ V_209 ] )
return false ;
if ( F_137 ( V_186 [ V_199 ] ) >= V_178 )
return false ;
if ( V_186 [ V_210 ] && F_129 ( V_186 [ V_210 ] ) == 0 )
return false ;
if ( V_186 [ V_211 ] ) {
if ( F_137 ( V_186 [ V_211 ] ) > 1 )
return false ;
}
return true ;
}
static int F_162 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_43 * V_44 ;
struct V_20 * V_72 ;
T_3 V_159 ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
if ( ! F_161 ( V_195 ) )
return - V_107 ;
F_147 () ;
V_72 = F_136 ( F_148 ( V_214 ) , V_186 , V_195 ,
& V_3 , & V_41 , & V_44 , & V_159 ) ;
if ( F_107 ( V_72 ) ) {
F_149 () ;
return F_108 ( V_72 ) ;
}
if ( V_195 [ V_210 ] ) {
F_39 ( & V_72 -> V_73 ) ;
V_72 -> V_74 = F_129 ( V_195 [ V_210 ] ) ;
F_41 ( & V_72 -> V_73 ) ;
}
if ( V_195 [ V_211 ] )
V_72 -> V_9 = F_137 ( V_195 [ V_211 ] ) ;
if ( V_159 == V_44 -> V_61 )
V_41 -> V_76 = V_72 -> V_9 ;
F_149 () ;
return 0 ;
}
static int F_163 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_6 * V_119 ;
T_3 V_159 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
struct V_185 * V_195 [ V_203 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
if ( F_141 ( V_186 , V_195 ) )
return - V_107 ;
if ( ! F_161 ( V_195 ) )
return - V_107 ;
F_147 () ;
V_119 = F_140 ( F_148 ( V_214 ) , V_186 , V_200 , V_195 ,
& V_3 , & V_41 , & V_14 , & V_159 ) ;
if ( F_107 ( V_119 ) ) {
F_149 () ;
return F_108 ( V_119 ) ;
}
if ( V_195 [ V_210 ] ) {
F_39 ( & V_119 -> V_73 ) ;
V_119 -> V_74 = F_129 ( V_195 [ V_210 ] ) ;
F_41 ( & V_119 -> V_73 ) ;
}
if ( V_195 [ V_211 ] )
V_119 -> V_9 = F_137 ( V_195 [ V_211 ] ) ;
F_149 () ;
return 0 ;
}
static int F_164 ( struct V_22 * V_23 , struct V_213 * V_214 )
{
struct V_185 * * V_186 = V_214 -> V_186 ;
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
struct V_185 * V_200 [ V_206 + 1 ] ;
if ( ! V_186 [ V_188 ] )
return - V_107 ;
if ( F_143 ( V_186 , V_200 ) )
return - V_107 ;
if ( ! F_154 ( V_200 ) )
return - V_107 ;
F_147 () ;
V_14 = F_139 ( F_148 ( V_214 ) , V_186 , V_200 , & V_3 , & V_41 ) ;
if ( F_107 ( V_14 ) ) {
F_149 () ;
return F_108 ( V_14 ) ;
}
if ( V_200 [ V_217 ] ) {
bool V_219 = ! ! F_137 ( V_200 [ V_217 ] ) ;
if ( V_14 -> V_9 != V_219 )
V_41 -> V_49 += V_219 ? 1 : - 1 ;
V_14 -> V_9 = V_219 ;
}
F_149 () ;
return 0 ;
}
static int F_165 ( struct V_22 * V_23 ,
struct V_183 T_9 * V_220 )
{
struct V_183 V_221 = { 0 , } ;
int V_222 ;
F_166 (cpu) {
const struct V_183 * V_15 = F_167 ( V_220 , V_222 ) ;
V_221 . V_86 += V_15 -> V_86 ;
V_221 . V_84 += V_15 -> V_84 ;
}
if ( F_168 ( V_23 , V_223 , V_221 . V_86 ) ||
F_168 ( V_23 , V_224 , V_221 . V_84 ) )
return - V_225 ;
return 0 ;
}
static int F_169 ( struct V_22 * V_23 ,
struct V_176 T_9 * V_220 )
{
struct V_176 V_221 = { 0 , } ;
int V_222 ;
F_166 (cpu) {
const struct V_176 * V_15 = F_167 ( V_220 , V_222 ) ;
V_221 . V_138 += V_15 -> V_138 ;
V_221 . V_135 += V_15 -> V_135 ;
V_221 . V_133 += V_15 -> V_133 ;
V_221 . V_164 += V_15 -> V_164 ;
V_221 . V_165 += V_15 -> V_165 ;
}
if ( F_168 ( V_23 , V_226 , V_221 . V_138 ) ||
F_168 ( V_23 , V_227 , V_221 . V_135 ) ||
F_168 ( V_23 , V_228 , V_221 . V_133 ) ||
F_168 ( V_23 , V_229 , V_221 . V_164 ) ||
F_168 ( V_23 , V_230 , V_221 . V_165 ) )
return - V_225 ;
return 0 ;
}
static int F_170 ( struct V_22 * V_23 ,
struct V_120 T_9 * V_220 )
{
struct V_231 V_221 = { 0 , } ;
int V_222 ;
F_166 (cpu) {
const struct V_120 * V_15 ;
struct V_231 V_232 ;
unsigned int V_233 ;
V_15 = F_167 ( V_220 , V_222 ) ;
do {
V_233 = F_171 ( & V_15 -> V_82 ) ;
memcpy ( & V_232 , & V_15 -> V_15 , sizeof( V_232 ) ) ;
} while ( F_172 ( & V_15 -> V_82 , V_233 ) );
V_221 . V_130 += V_232 . V_130 ;
V_221 . V_129 += V_232 . V_129 ;
V_221 . V_137 += V_232 . V_137 ;
V_221 . V_136 += V_232 . V_136 ;
V_221 . V_138 += V_232 . V_138 ;
V_221 . V_135 += V_232 . V_135 ;
V_221 . V_125 += V_232 . V_125 ;
V_221 . V_133 += V_232 . V_133 ;
V_221 . V_164 += V_232 . V_164 ;
V_221 . V_165 += V_232 . V_165 ;
}
if ( F_135 ( V_23 , V_234 , V_221 . V_130 ) ||
F_135 ( V_23 , V_235 , V_221 . V_129 ) ||
F_135 ( V_23 , V_236 , V_221 . V_137 ) ||
F_135 ( V_23 , V_237 , V_221 . V_136 ) ||
F_135 ( V_23 , V_238 , V_221 . V_138 ) ||
F_135 ( V_23 , V_239 , V_221 . V_135 ) ||
F_135 ( V_23 , V_240 , V_221 . V_125 ) ||
F_135 ( V_23 , V_241 , V_221 . V_133 ) ||
F_135 ( V_23 , V_242 , V_221 . V_164 ) ||
F_135 ( V_23 , V_243 , V_221 . V_165 ) )
return - V_225 ;
return 0 ;
}
static int F_173 ( struct V_22 * V_23 ,
struct V_80 T_9 * V_220 )
{
struct V_244 V_221 = { 0 , } ;
int V_222 ;
F_166 (cpu) {
const struct V_80 * V_15 ;
struct V_244 V_232 ;
unsigned int V_233 ;
V_15 = F_167 ( V_220 , V_222 ) ;
do {
V_233 = F_171 ( & V_15 -> V_82 ) ;
memcpy ( & V_232 , & V_15 -> V_15 , sizeof( V_232 ) ) ;
} while ( F_172 ( & V_15 -> V_82 , V_233 ) );
V_221 . V_86 += V_232 . V_86 ;
V_221 . V_84 += V_232 . V_84 ;
V_221 . V_85 += V_232 . V_85 ;
V_221 . V_83 += V_232 . V_83 ;
}
if ( F_135 ( V_23 , V_245 , V_221 . V_86 ) ||
F_135 ( V_23 , V_246 , V_221 . V_84 ) ||
F_135 ( V_23 , V_247 , V_221 . V_85 ) ||
F_135 ( V_23 , V_248 , V_221 . V_83 ) )
return - V_225 ;
return 0 ;
}
static int F_174 ( struct V_22 * V_23 ,
struct V_115 T_9 * V_220 )
{
struct V_249 V_221 = { 0 , } ;
int V_222 ;
F_166 (cpu) {
const struct V_115 * V_15 ;
struct V_249 V_232 ;
unsigned int V_233 ;
V_15 = F_167 ( V_220 , V_222 ) ;
do {
V_233 = F_171 ( & V_15 -> V_82 ) ;
memcpy ( & V_232 , & V_15 -> V_15 , sizeof( V_232 ) ) ;
} while ( F_172 ( & V_15 -> V_82 , V_233 ) );
V_221 . V_250 += V_232 . V_250 ;
V_221 . V_152 += V_232 . V_152 ;
V_221 . V_117 += V_232 . V_117 ;
V_221 . V_151 += V_232 . V_151 ;
V_221 . V_162 += V_232 . V_162 ;
V_221 . V_171 += V_232 . V_171 ;
V_221 . V_170 += V_232 . V_170 ;
V_221 . V_251 += V_232 . V_251 ;
}
if ( F_135 ( V_23 , V_252 , V_221 . V_250 ) ||
F_135 ( V_23 , V_253 , V_221 . V_152 ) ||
F_135 ( V_23 , V_254 , V_221 . V_117 ) ||
F_135 ( V_23 , V_255 , V_221 . V_151 ) ||
F_135 ( V_23 , V_256 , V_221 . V_162 ) ||
F_135 ( V_23 , V_257 , V_221 . V_171 ) ||
F_135 ( V_23 , V_258 , V_221 . V_170 ) ||
F_135 ( V_23 , V_259 , V_221 . V_251 ) )
return - V_225 ;
return 0 ;
}
static int F_175 ( struct V_40 * V_41 , struct V_22 * V_23 )
{
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_185 * V_260 = F_176 ( V_23 , V_261 ) ;
if ( ! V_260 )
return 1 ;
if ( F_134 ( V_23 , V_262 , V_41 -> V_27 ) ||
F_135 ( V_23 , V_263 ,
V_264 ) ||
F_177 ( V_23 , V_265 , V_41 -> V_58 ) ||
F_177 ( V_23 , V_266 , V_41 -> V_76 ) ||
F_177 ( V_23 , V_267 , V_41 -> V_75 ) ||
F_177 ( V_23 , V_268 , V_41 -> V_124 ) ||
F_177 ( V_23 , V_269 , V_41 -> V_126 ) ||
F_177 ( V_23 , V_270 , V_44 -> V_56 ) ||
F_177 ( V_23 , V_271 , V_44 -> V_46 ) ||
F_177 ( V_23 , V_272 , V_44 -> V_50 ) ||
F_177 ( V_23 , V_273 , V_44 -> V_51 ) ||
F_177 ( V_23 , V_274 , V_44 -> V_61 ) )
goto V_275;
if ( V_41 -> V_124 ) {
if ( F_168 ( V_23 , V_276 , V_41 -> V_123 ) )
goto V_275;
}
F_178 ( V_23 , V_260 ) ;
return 0 ;
V_275:
F_179 ( V_23 , V_260 ) ;
return 1 ;
}
static int F_180 ( struct V_40 * V_41 , struct V_2 * V_3 ,
struct V_22 * V_23 , struct V_277 * V_24 )
{
struct V_13 * V_14 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
struct V_185 * V_278 , * V_279 ;
int V_177 , V_280 ;
void * V_30 ;
struct V_185 * V_281 ;
V_30 = F_181 ( V_23 , F_182 ( V_24 -> V_23 ) . V_282 , V_24 -> V_283 -> V_284 ,
& V_285 , V_286 , V_287 ) ;
if ( ! V_30 )
return - V_225 ;
F_183 ( V_24 , V_30 , & V_285 ) ;
if ( F_168 ( V_23 , V_188 , V_3 -> V_187 ) )
goto V_288;
if ( F_175 ( V_41 , V_23 ) )
goto V_288;
V_281 = F_176 ( V_23 , V_289 ) ;
if ( ! V_281 )
goto V_288;
if ( F_173 ( V_23 , V_44 -> V_15 ) ) {
F_179 ( V_23 , V_281 ) ;
goto V_288;
}
F_178 ( V_23 , V_281 ) ;
V_281 = F_176 ( V_23 , V_290 ) ;
if ( ! V_281 )
goto V_288;
if ( F_174 ( V_23 , F_1 ( V_3 ) -> V_15 ) ) {
F_179 ( V_23 , V_281 ) ;
goto V_288;
}
F_178 ( V_23 , V_281 ) ;
V_278 = F_176 ( V_23 , V_291 ) ;
if ( ! V_278 )
goto V_288;
for ( V_177 = 0 , V_280 = 1 ; V_177 < V_178 ; V_177 ++ ) {
struct V_20 * V_72 = F_6 ( V_44 -> V_8 [ V_177 ] ) ;
struct V_185 * V_292 ;
if ( ! V_72 )
continue;
V_292 = F_176 ( V_23 , V_280 ++ ) ;
if ( ! V_292 ) {
F_179 ( V_23 , V_278 ) ;
goto V_288;
}
if ( F_177 ( V_23 , V_199 , V_177 ) ||
F_168 ( V_23 , V_210 , V_72 -> V_74 ) ||
F_184 ( V_23 , V_209 , V_212 , V_72 -> V_18 . V_216 ) ||
F_177 ( V_23 , V_211 , V_72 -> V_9 ) ) {
F_179 ( V_23 , V_292 ) ;
F_179 ( V_23 , V_278 ) ;
goto V_288;
}
V_281 = F_176 ( V_23 , V_293 ) ;
if ( ! V_281 ) {
F_179 ( V_23 , V_292 ) ;
F_179 ( V_23 , V_278 ) ;
goto V_288;
}
if ( F_165 ( V_23 , V_72 -> V_15 ) ) {
F_179 ( V_23 , V_281 ) ;
F_179 ( V_23 , V_292 ) ;
F_179 ( V_23 , V_278 ) ;
goto V_288;
}
F_178 ( V_23 , V_281 ) ;
F_178 ( V_23 , V_292 ) ;
}
F_178 ( V_23 , V_278 ) ;
V_279 = F_176 ( V_23 , V_294 ) ;
if ( ! V_279 )
goto V_288;
V_280 = 1 ;
F_99 (secy, rx_sc) {
int V_295 ;
struct V_185 * V_296 ;
struct V_185 * V_297 = F_176 ( V_23 , V_280 ++ ) ;
if ( ! V_297 ) {
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
if ( F_177 ( V_23 , V_217 , V_14 -> V_9 ) ||
F_134 ( V_23 , V_201 , V_14 -> V_27 ) ) {
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
V_281 = F_176 ( V_23 , V_298 ) ;
if ( ! V_281 ) {
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
if ( F_170 ( V_23 , V_14 -> V_15 ) ) {
F_179 ( V_23 , V_281 ) ;
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
F_178 ( V_23 , V_281 ) ;
V_296 = F_176 ( V_23 , V_299 ) ;
if ( ! V_296 ) {
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
for ( V_177 = 0 , V_295 = 1 ; V_177 < V_178 ; V_177 ++ ) {
struct V_6 * V_119 = F_6 ( V_14 -> V_8 [ V_177 ] ) ;
struct V_185 * V_300 ;
if ( ! V_119 )
continue;
V_300 = F_176 ( V_23 , V_295 ++ ) ;
if ( ! V_300 ) {
F_179 ( V_23 , V_296 ) ;
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
V_281 = F_176 ( V_23 , V_293 ) ;
if ( ! V_281 ) {
F_179 ( V_23 , V_296 ) ;
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
if ( F_169 ( V_23 , V_119 -> V_15 ) ) {
F_179 ( V_23 , V_281 ) ;
F_179 ( V_23 , V_296 ) ;
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
F_178 ( V_23 , V_281 ) ;
if ( F_177 ( V_23 , V_199 , V_177 ) ||
F_168 ( V_23 , V_210 , V_119 -> V_74 ) ||
F_184 ( V_23 , V_209 , V_212 , V_119 -> V_18 . V_216 ) ||
F_177 ( V_23 , V_211 , V_119 -> V_9 ) ) {
F_179 ( V_23 , V_300 ) ;
F_179 ( V_23 , V_297 ) ;
F_179 ( V_23 , V_279 ) ;
goto V_288;
}
F_178 ( V_23 , V_300 ) ;
}
F_178 ( V_23 , V_296 ) ;
F_178 ( V_23 , V_297 ) ;
}
F_178 ( V_23 , V_279 ) ;
F_185 ( V_23 , V_30 ) ;
return 0 ;
V_288:
F_186 ( V_23 , V_30 ) ;
return - V_225 ;
}
static int F_187 ( struct V_22 * V_23 , struct V_277 * V_24 )
{
struct V_184 * V_184 = F_188 ( V_23 -> V_301 ) ;
struct V_2 * V_3 ;
int V_302 , V_303 ;
V_302 = V_24 -> args [ 0 ] ;
V_303 = 0 ;
F_147 () ;
V_24 -> V_304 = V_305 ;
F_189 (net, dev) {
struct V_40 * V_41 ;
if ( V_303 < V_302 )
goto V_180;
if ( ! F_131 ( V_3 ) )
goto V_180;
V_41 = & F_1 ( V_3 ) -> V_41 ;
if ( F_180 ( V_41 , V_3 , V_23 , V_24 ) < 0 )
goto V_306;
V_180:
V_303 ++ ;
}
V_306:
F_149 () ;
V_24 -> args [ 0 ] = V_303 ;
return V_23 -> V_66 ;
}
static T_10 F_190 ( struct V_22 * V_23 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_2 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
struct V_115 * V_116 ;
int V_87 , V_66 ;
if ( ! V_41 -> V_75 ) {
V_116 = F_46 ( V_77 -> V_15 ) ;
F_47 ( & V_116 -> V_82 ) ;
V_116 -> V_15 . V_250 ++ ;
F_49 ( & V_116 -> V_82 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
return V_87 ;
}
if ( ! V_41 -> V_76 ) {
F_59 ( V_23 ) ;
V_3 -> V_15 . V_94 ++ ;
return V_307 ;
}
V_23 = F_58 ( V_23 , V_3 ) ;
if ( F_107 ( V_23 ) ) {
if ( F_108 ( V_23 ) != - V_118 )
V_3 -> V_15 . V_94 ++ ;
return V_307 ;
}
F_45 ( V_23 , & V_77 -> V_41 . V_44 , F_23 ( V_23 ) -> V_72 ) ;
F_42 ( V_23 , V_3 ) ;
V_66 = V_23 -> V_66 ;
V_87 = F_55 ( V_23 ) ;
F_50 ( V_3 , V_87 , V_66 ) ;
return V_87 ;
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
V_3 -> V_91 = F_125 ( struct V_90 ) ;
if ( ! V_3 -> V_91 )
return - V_112 ;
V_3 -> V_308 = V_78 -> V_308 & V_309 ;
V_3 -> V_308 |= V_310 | V_311 ;
V_3 -> V_312 = V_78 -> V_312 +
V_108 ;
V_3 -> V_313 = V_78 -> V_313 +
V_109 ;
if ( F_192 ( V_3 -> V_314 ) )
F_193 ( V_3 , V_78 ) ;
if ( F_192 ( V_3 -> V_315 ) )
memcpy ( V_3 -> V_315 , V_78 -> V_315 , V_3 -> V_316 ) ;
return 0 ;
}
static void F_194 ( struct V_2 * V_3 )
{
F_11 ( V_3 -> V_91 ) ;
}
static T_11 F_195 ( struct V_2 * V_3 ,
T_11 V_308 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
V_308 &= V_78 -> V_308 & V_309 ;
V_308 |= V_310 | V_311 ;
return V_308 ;
}
static int F_196 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
int V_97 ;
if ( ! ( V_78 -> V_317 & V_318 ) )
return - V_319 ;
V_97 = F_197 ( V_78 , V_3 -> V_314 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_3 -> V_317 & V_320 ) {
V_97 = F_198 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_321;
}
if ( V_3 -> V_317 & V_322 ) {
V_97 = F_199 ( V_78 , 1 ) ;
if ( V_97 < 0 )
goto V_323;
}
if ( F_200 ( V_78 ) )
F_201 ( V_3 ) ;
return 0 ;
V_323:
if ( V_3 -> V_317 & V_320 )
F_198 ( V_78 , - 1 ) ;
V_321:
F_202 ( V_78 , V_3 -> V_314 ) ;
F_203 ( V_3 ) ;
return V_97 ;
}
static int F_204 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_203 ( V_3 ) ;
F_205 ( V_78 , V_3 ) ;
F_206 ( V_78 , V_3 ) ;
if ( V_3 -> V_317 & V_320 )
F_198 ( V_78 , - 1 ) ;
if ( V_3 -> V_317 & V_322 )
F_199 ( V_78 , - 1 ) ;
F_202 ( V_78 , V_3 -> V_314 ) ;
return 0 ;
}
static void F_207 ( struct V_2 * V_3 , int V_324 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
if ( ! ( V_3 -> V_317 & V_318 ) )
return;
if ( V_324 & V_320 )
F_198 ( V_78 , V_3 -> V_317 & V_320 ? 1 : - 1 ) ;
if ( V_324 & V_322 )
F_199 ( V_78 ,
V_3 -> V_317 & V_322 ? 1 : - 1 ) ;
}
static void F_208 ( struct V_2 * V_3 )
{
struct V_2 * V_78 = F_1 ( V_3 ) -> V_78 ;
F_209 ( V_78 , V_3 ) ;
F_210 ( V_78 , V_3 ) ;
}
static int F_211 ( struct V_2 * V_3 , void * V_325 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_326 * V_25 = V_325 ;
int V_97 ;
if ( ! F_212 ( V_25 -> V_327 ) )
return - V_328 ;
if ( ! ( V_3 -> V_317 & V_318 ) )
goto V_144;
V_97 = F_197 ( V_78 , V_25 -> V_327 ) ;
if ( V_97 < 0 )
return V_97 ;
F_202 ( V_78 , V_3 -> V_314 ) ;
V_144:
F_213 ( V_3 -> V_314 , V_25 -> V_327 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_3 , int V_329 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
unsigned int V_330 = V_77 -> V_41 . V_58 + F_29 ( true ) ;
if ( V_77 -> V_78 -> V_114 - V_330 < V_329 )
return - V_331 ;
V_3 -> V_114 = V_329 ;
return 0 ;
}
static struct V_332 * F_215 ( struct V_2 * V_3 ,
struct V_332 * V_333 )
{
int V_222 ;
if ( ! V_3 -> V_91 )
return V_333 ;
F_166 (cpu) {
struct V_90 * V_15 ;
struct V_90 V_232 ;
int V_233 ;
V_15 = F_167 ( V_3 -> V_91 , V_222 ) ;
do {
V_233 = F_171 ( & V_15 -> V_82 ) ;
V_232 . V_142 = V_15 -> V_142 ;
V_232 . V_143 = V_15 -> V_143 ;
V_232 . V_92 = V_15 -> V_92 ;
V_232 . V_93 = V_15 -> V_93 ;
} while ( F_172 ( & V_15 -> V_82 , V_233 ) );
V_333 -> V_142 += V_232 . V_142 ;
V_333 -> V_143 += V_232 . V_143 ;
V_333 -> V_92 += V_232 . V_92 ;
V_333 -> V_93 += V_232 . V_93 ;
}
V_333 -> V_148 = V_3 -> V_15 . V_148 ;
V_333 -> V_94 = V_3 -> V_15 . V_94 ;
return V_333 ;
}
static int F_216 ( const struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_78 -> V_187 ;
}
static void F_217 ( struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
F_11 ( V_77 -> V_15 ) ;
F_11 ( V_77 -> V_41 . V_44 . V_15 ) ;
F_57 ( V_78 ) ;
F_218 ( V_3 ) ;
}
static void F_219 ( struct V_2 * V_3 )
{
F_220 ( V_3 ) ;
V_3 -> V_334 = 0 ;
V_3 -> V_335 = & V_336 ;
V_3 -> V_337 = F_217 ;
F_221 ( V_3 -> V_315 ) ;
}
static void F_222 ( struct V_2 * V_3 ,
struct V_185 * V_65 [] )
{
struct V_40 * V_41 ;
struct V_43 * V_44 ;
V_41 = & F_1 ( V_3 ) -> V_41 ;
V_44 = & V_41 -> V_44 ;
if ( V_65 [ V_338 ] ) {
struct V_20 * V_72 ;
V_44 -> V_61 = F_137 ( V_65 [ V_338 ] ) ;
V_72 = F_6 ( V_44 -> V_8 [ V_44 -> V_61 ] ) ;
V_41 -> V_76 = V_72 && V_72 -> V_9 ;
}
if ( V_65 [ V_339 ] )
V_41 -> V_123 = F_129 ( V_65 [ V_339 ] ) ;
if ( V_65 [ V_340 ] )
V_44 -> V_56 = ! ! F_137 ( V_65 [ V_340 ] ) ;
if ( V_65 [ V_341 ] )
V_41 -> V_75 = ! ! F_137 ( V_65 [ V_341 ] ) ;
if ( V_65 [ V_342 ] )
V_44 -> V_46 = ! ! F_137 ( V_65 [ V_342 ] ) ;
if ( V_65 [ V_343 ] )
V_44 -> V_50 = ! ! F_137 ( V_65 [ V_343 ] ) ;
if ( V_65 [ V_344 ] )
V_44 -> V_51 = ! ! F_137 ( V_65 [ V_344 ] ) ;
if ( V_65 [ V_345 ] )
V_41 -> V_124 = ! ! F_137 ( V_65 [ V_345 ] ) ;
if ( V_65 [ V_346 ] )
V_41 -> V_126 = F_137 ( V_65 [ V_346 ] ) ;
}
static int F_223 ( struct V_2 * V_3 , struct V_185 * V_347 [] ,
struct V_185 * V_65 [] )
{
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_348 ] ||
V_65 [ V_349 ] ||
V_65 [ V_350 ] ||
V_65 [ V_351 ] )
return - V_107 ;
F_222 ( V_3 , V_65 ) ;
return 0 ;
}
static void F_224 ( struct V_1 * V_77 )
{
int V_177 ;
while ( V_77 -> V_41 . V_14 ) {
struct V_13 * V_14 = F_6 ( V_77 -> V_41 . V_14 ) ;
F_121 ( V_77 -> V_41 . V_14 , V_14 -> V_180 ) ;
F_118 ( V_14 ) ;
}
for ( V_177 = 0 ; V_177 < V_178 ; V_177 ++ ) {
struct V_20 * V_8 = F_6 ( V_77 -> V_41 . V_44 . V_8 [ V_177 ] ) ;
if ( V_8 ) {
F_119 ( V_77 -> V_41 . V_44 . V_8 [ V_177 ] , NULL ) ;
F_127 ( V_8 ) ;
}
}
}
static void F_225 ( struct V_2 * V_3 , struct V_352 * V_12 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 = V_77 -> V_78 ;
struct V_4 * V_150 = F_5 ( V_78 ) ;
V_305 ++ ;
F_226 ( V_3 , V_12 ) ;
F_227 ( & V_77 -> V_353 ) ;
if ( F_228 ( & V_150 -> V_353 ) ) {
F_229 ( V_78 ) ;
F_12 ( V_150 ) ;
}
F_224 ( V_77 ) ;
}
static int F_230 ( struct V_2 * V_78 ,
struct V_2 * V_3 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_4 * V_150 = F_5 ( V_78 ) ;
if ( ! V_150 ) {
int V_97 ;
V_150 = F_151 ( sizeof( * V_150 ) , V_182 ) ;
if ( ! V_150 )
return - V_112 ;
F_231 ( & V_150 -> V_353 ) ;
V_97 = F_232 ( V_78 , F_105 ,
V_150 ) ;
if ( V_97 < 0 ) {
F_12 ( V_150 ) ;
return V_97 ;
}
}
F_233 ( & V_77 -> V_353 , & V_150 -> V_353 ) ;
return 0 ;
}
static bool F_234 ( struct V_2 * V_3 , T_2 V_27 )
{
struct V_4 * V_150 = F_5 ( V_3 ) ;
struct V_1 * V_77 ;
F_123 (macsec, &rxd->secys, secys) {
if ( V_77 -> V_41 . V_27 == V_27 )
return true ;
}
return false ;
}
static T_2 F_235 ( struct V_2 * V_3 , T_4 V_26 )
{
return F_25 ( V_3 -> V_314 , V_26 ) ;
}
static int F_236 ( struct V_2 * V_3 , T_2 V_27 , T_3 V_58 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_40 * V_41 = & V_77 -> V_41 ;
V_77 -> V_15 = F_125 ( struct V_115 ) ;
if ( ! V_77 -> V_15 )
return - V_112 ;
V_41 -> V_44 . V_15 = F_125 ( struct V_80 ) ;
if ( ! V_41 -> V_44 . V_15 ) {
F_11 ( V_77 -> V_15 ) ;
return - V_112 ;
}
if ( V_27 == V_218 )
V_27 = F_235 ( V_3 , V_35 ) ;
V_41 -> V_146 = V_3 ;
V_41 -> V_76 = true ;
V_41 -> V_173 = V_354 ;
V_41 -> V_58 = V_58 ;
V_41 -> V_126 = V_355 ;
V_41 -> V_75 = true ;
V_41 -> V_124 = false ;
V_41 -> V_27 = V_27 ;
V_41 -> V_44 . V_9 = true ;
V_41 -> V_44 . V_61 = V_356 ;
V_41 -> V_44 . V_56 = V_357 ;
V_41 -> V_44 . V_46 = V_358 ;
V_41 -> V_44 . V_50 = false ;
V_41 -> V_44 . V_51 = false ;
return 0 ;
}
static int F_237 ( struct V_184 * V_184 , struct V_2 * V_3 ,
struct V_185 * V_347 [] , struct V_185 * V_65 [] )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_2 * V_78 ;
int V_97 ;
T_2 V_27 ;
T_3 V_58 = V_59 ;
T_12 * V_359 ;
if ( ! V_347 [ V_360 ] )
return - V_107 ;
V_78 = F_130 ( V_184 , F_129 ( V_347 [ V_360 ] ) ) ;
if ( ! V_78 )
return - V_189 ;
V_3 -> V_361 |= V_362 ;
V_77 -> V_78 = V_78 ;
if ( V_65 && V_65 [ V_349 ] )
V_58 = F_137 ( V_65 [ V_349 ] ) ;
V_3 -> V_114 = V_78 -> V_114 - V_58 - F_29 ( true ) ;
V_359 = F_6 ( V_78 -> V_359 ) ;
if ( V_359 && V_359 != F_105 )
return - V_215 ;
V_97 = F_238 ( V_3 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_65 && V_65 [ V_350 ] )
V_27 = F_132 ( V_65 [ V_350 ] ) ;
else if ( V_65 && V_65 [ V_351 ] )
V_27 = F_235 ( V_3 , F_239 ( V_65 [ V_351 ] ) ) ;
else
V_27 = F_235 ( V_3 , V_35 ) ;
if ( V_359 && F_234 ( V_78 , V_27 ) ) {
V_97 = - V_215 ;
goto V_363;
}
V_97 = F_236 ( V_3 , V_27 , V_58 ) ;
if ( V_97 )
goto V_363;
if ( V_65 )
F_222 ( V_3 , V_65 ) ;
V_97 = F_230 ( V_78 , V_3 ) ;
if ( V_97 < 0 )
goto V_364;
V_305 ++ ;
F_75 ( V_78 ) ;
return 0 ;
V_364:
F_224 ( V_77 ) ;
V_363:
F_240 ( V_3 ) ;
return V_97 ;
}
static int F_241 ( struct V_185 * V_347 [] , struct V_185 * V_65 [] )
{
V_194 V_365 = V_264 ;
T_3 V_58 = V_59 ;
int V_366 ;
bool V_367 , V_51 , V_27 ;
if ( ! V_65 )
return 0 ;
if ( V_65 [ V_348 ] )
V_365 = F_133 ( V_65 [ V_348 ] ) ;
if ( V_65 [ V_349 ] )
V_58 = F_137 ( V_65 [ V_349 ] ) ;
switch ( V_365 ) {
case V_264 :
case V_368 :
if ( V_58 < V_369 ||
V_58 > V_370 )
return - V_107 ;
break;
default:
return - V_107 ;
}
if ( V_65 [ V_338 ] ) {
if ( F_137 ( V_65 [ V_338 ] ) >= V_178 )
return - V_107 ;
}
for ( V_366 = V_338 + 1 ;
V_366 < V_346 ;
V_366 ++ ) {
if ( V_65 [ V_366 ] ) {
if ( F_137 ( V_65 [ V_366 ] ) > 1 )
return - V_107 ;
}
}
V_367 = V_65 [ V_343 ] ? F_137 ( V_65 [ V_343 ] ) : false ;
V_27 = V_65 [ V_342 ] ? F_137 ( V_65 [ V_342 ] ) : false ;
V_51 = V_65 [ V_344 ] ? F_137 ( V_65 [ V_344 ] ) : false ;
if ( ( V_27 && ( V_51 || V_367 ) ) || ( V_51 && V_367 ) )
return - V_107 ;
if ( V_65 [ V_346 ] &&
F_137 ( V_65 [ V_346 ] ) > V_371 )
return - V_107 ;
if ( ( V_65 [ V_345 ] &&
F_137 ( V_65 [ V_345 ] ) ) &&
! V_65 [ V_339 ] )
return - V_107 ;
return 0 ;
}
static struct V_184 * F_242 ( const struct V_2 * V_3 )
{
return F_243 ( F_1 ( V_3 ) -> V_78 ) ;
}
static T_6 F_244 ( const struct V_2 * V_3 )
{
return 0 +
F_245 ( 8 ) +
F_245 ( 1 ) +
F_245 ( 8 ) +
F_245 ( 4 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
F_245 ( 1 ) +
0 ;
}
static int F_246 ( struct V_22 * V_23 ,
const struct V_2 * V_3 )
{
struct V_40 * V_41 = & F_1 ( V_3 ) -> V_41 ;
struct V_43 * V_44 = & V_41 -> V_44 ;
if ( F_134 ( V_23 , V_350 , V_41 -> V_27 ) ||
F_177 ( V_23 , V_349 , V_41 -> V_58 ) ||
F_135 ( V_23 , V_348 ,
V_264 ) ||
F_177 ( V_23 , V_338 , V_44 -> V_61 ) ||
F_177 ( V_23 , V_340 , V_44 -> V_56 ) ||
F_177 ( V_23 , V_341 , V_41 -> V_75 ) ||
F_177 ( V_23 , V_342 , V_44 -> V_46 ) ||
F_177 ( V_23 , V_343 , V_44 -> V_50 ) ||
F_177 ( V_23 , V_344 , V_44 -> V_51 ) ||
F_177 ( V_23 , V_345 , V_41 -> V_124 ) ||
F_177 ( V_23 , V_346 , V_41 -> V_126 ) ||
0 )
goto V_288;
if ( V_41 -> V_124 ) {
if ( F_168 ( V_23 , V_339 , V_41 -> V_123 ) )
goto V_288;
}
return 0 ;
V_288:
return - V_225 ;
}
static bool F_247 ( struct V_2 * V_3 )
{
return F_248 ( V_3 -> V_359 ) == F_105 ;
}
static int F_249 ( struct V_372 * V_373 , unsigned long V_374 ,
void * V_7 )
{
struct V_2 * V_78 = F_250 ( V_7 ) ;
F_251 ( V_12 ) ;
if ( ! F_247 ( V_78 ) )
return V_375 ;
switch ( V_374 ) {
case V_376 : {
struct V_1 * V_377 , * V_378 ;
struct V_4 * V_150 ;
V_150 = F_5 ( V_78 ) ;
F_252 (m, n, &rxd->secys, secys) {
F_225 ( V_377 -> V_41 . V_146 , & V_12 ) ;
}
F_253 ( & V_12 ) ;
break;
}
case V_379 : {
struct V_1 * V_377 ;
struct V_4 * V_150 ;
V_150 = F_5 ( V_78 ) ;
F_123 (m, &rxd->secys, secys) {
struct V_2 * V_3 = V_377 -> V_41 . V_146 ;
unsigned int V_114 = V_78 -> V_114 - ( V_377 -> V_41 . V_58 +
F_29 ( true ) ) ;
if ( V_3 -> V_114 > V_114 )
F_254 ( V_3 , V_114 ) ;
}
}
}
return V_380 ;
}
static int T_13 F_255 ( void )
{
int V_97 ;
F_256 ( L_5 ) ;
V_97 = F_257 ( & V_381 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_258 ( & V_382 ) ;
if ( V_97 )
goto V_383;
V_97 = F_259 ( & V_285 , V_384 ) ;
if ( V_97 )
goto V_385;
return 0 ;
V_385:
F_260 ( & V_382 ) ;
V_383:
F_261 ( & V_381 ) ;
return V_97 ;
}
static void T_14 F_262 ( void )
{
F_263 ( & V_285 ) ;
F_260 ( & V_382 ) ;
F_261 ( & V_381 ) ;
}
