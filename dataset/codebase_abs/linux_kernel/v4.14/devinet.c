static T_1 F_1 ( const struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = ( V_4 T_1 ) V_2 ^ F_2 ( V_1 ) ;
return F_3 ( V_3 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
T_1 V_8 = F_1 ( V_1 , V_7 -> V_9 ) ;
F_5 () ;
F_6 ( & V_7 -> V_8 , & V_10 [ V_8 ] ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_5 () ;
F_8 ( & V_7 -> V_8 ) ;
}
struct V_11 * F_9 ( struct V_1 * V_1 , T_2 V_2 , bool V_12 )
{
T_1 V_8 = F_1 ( V_1 , V_2 ) ;
struct V_11 * V_13 = NULL ;
struct V_6 * V_7 ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[hash], hash) {
if ( V_7 -> V_9 == V_2 ) {
struct V_11 * V_14 = V_7 -> V_15 -> V_14 ;
if ( ! F_12 ( F_13 ( V_14 ) , V_1 ) )
continue;
V_13 = V_14 ;
break;
}
}
if ( ! V_13 ) {
struct V_16 V_17 = { . V_18 = V_2 } ;
struct V_19 V_20 = { 0 } ;
struct V_21 * V_22 ;
V_22 = F_14 ( V_1 , V_23 ) ;
if ( V_22 &&
! F_15 ( V_22 , & V_17 , & V_20 , V_24 ) &&
V_20 . type == V_25 )
V_13 = F_16 ( V_20 ) ;
}
if ( V_13 && V_12 )
F_17 ( V_13 ) ;
F_18 () ;
return V_13 ;
}
static int F_19 ( struct V_26 * V_27 )
{
return 0 ;
}
static void F_20 ( struct V_26 * V_27 )
{
}
static struct V_6 * F_21 ( void )
{
return F_22 ( sizeof( struct V_6 ) , V_28 ) ;
}
static void F_23 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_24 ( V_30 , struct V_6 , V_29 ) ;
if ( V_7 -> V_15 )
F_25 ( V_7 -> V_15 ) ;
F_26 ( V_7 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
F_28 ( & V_7 -> V_29 , F_23 ) ;
}
void F_29 ( struct V_26 * V_27 )
{
struct V_11 * V_14 = V_27 -> V_14 ;
F_30 ( V_27 -> V_31 ) ;
F_30 ( V_27 -> V_32 ) ;
F_26 ( F_31 ( V_27 -> V_33 , 1 ) ) ;
#ifdef F_32
F_33 ( L_1 , V_34 , V_27 , V_14 ? V_14 -> V_35 : L_2 ) ;
#endif
F_34 ( V_14 ) ;
if ( ! V_27 -> V_36 )
F_35 ( L_3 , V_27 ) ;
else
F_26 ( V_27 ) ;
}
static struct V_26 * F_36 ( struct V_11 * V_14 )
{
struct V_26 * V_37 ;
int V_38 = - V_39 ;
F_5 () ;
V_37 = F_22 ( sizeof( * V_37 ) , V_28 ) ;
if ( ! V_37 )
goto V_40;
memcpy ( & V_37 -> V_41 , F_13 ( V_14 ) -> V_42 . V_43 ,
sizeof( V_37 -> V_41 ) ) ;
V_37 -> V_41 . V_44 = NULL ;
V_37 -> V_14 = V_14 ;
V_37 -> V_45 = F_37 ( V_14 , & V_46 ) ;
if ( ! V_37 -> V_45 )
goto V_47;
if ( F_38 ( V_37 -> V_41 , V_48 ) )
F_39 ( V_14 ) ;
F_17 ( V_14 ) ;
F_40 ( & V_37 -> V_49 , 1 ) ;
V_38 = F_19 ( V_37 ) ;
if ( V_38 ) {
V_37 -> V_36 = 1 ;
F_25 ( V_37 ) ;
V_37 = NULL ;
goto V_40;
}
F_41 ( V_37 ) ;
if ( V_14 -> V_50 & V_51 )
F_42 ( V_37 ) ;
F_43 ( V_14 -> V_52 , V_37 ) ;
V_40:
return V_37 ? : F_44 ( V_38 ) ;
V_47:
F_26 ( V_37 ) ;
V_37 = NULL ;
goto V_40;
}
static void F_45 ( struct V_29 * V_30 )
{
struct V_26 * V_27 = F_24 ( V_30 , struct V_26 , V_29 ) ;
F_25 ( V_27 ) ;
}
static void F_46 ( struct V_26 * V_37 )
{
struct V_6 * V_7 ;
struct V_11 * V_14 ;
F_5 () ;
V_14 = V_37 -> V_14 ;
V_37 -> V_36 = 1 ;
F_47 ( V_37 ) ;
while ( ( V_7 = V_37 -> V_31 ) != NULL ) {
F_48 ( V_37 , & V_37 -> V_31 , 0 ) ;
F_27 ( V_7 ) ;
}
F_49 ( V_14 -> V_52 , NULL ) ;
F_20 ( V_37 ) ;
F_50 ( & V_46 , V_37 -> V_45 ) ;
F_51 ( V_14 ) ;
F_28 ( & V_37 -> V_29 , F_45 ) ;
}
int F_52 ( struct V_26 * V_37 , T_2 V_53 , T_2 V_54 )
{
F_10 () ;
F_53 (in_dev) {
if ( F_54 ( V_53 , V_7 ) ) {
if ( ! V_54 || F_54 ( V_54 , V_7 ) ) {
F_18 () ;
return 1 ;
}
}
} F_55 ( V_37 ) ;
F_18 () ;
return 0 ;
}
static void F_56 ( struct V_26 * V_37 , struct V_6 * * V_55 ,
int V_56 , struct V_57 * V_58 , T_1 V_59 )
{
struct V_6 * V_60 = NULL ;
struct V_6 * V_7 , * V_61 = * V_55 ;
struct V_6 * V_62 = V_37 -> V_31 ;
struct V_6 * V_63 = NULL ;
int V_64 = F_57 ( V_37 ) ;
F_5 () ;
if ( V_37 -> V_36 )
goto V_65;
if ( ! ( V_61 -> V_66 & V_67 ) ) {
struct V_6 * * V_68 = & V_61 -> V_69 ;
while ( ( V_7 = * V_68 ) != NULL ) {
if ( ! ( V_7 -> V_66 & V_67 ) &&
V_61 -> V_70 <= V_7 -> V_70 )
V_62 = V_7 ;
if ( ! ( V_7 -> V_66 & V_67 ) ||
V_61 -> V_71 != V_7 -> V_71 ||
! F_54 ( V_61 -> V_72 , V_7 ) ) {
V_68 = & V_7 -> V_69 ;
V_63 = V_7 ;
continue;
}
if ( ! V_64 ) {
F_7 ( V_7 ) ;
* V_68 = V_7 -> V_69 ;
F_58 ( V_73 , V_7 , V_58 , V_59 ) ;
F_59 ( & V_74 ,
V_75 , V_7 ) ;
F_27 ( V_7 ) ;
} else {
V_60 = V_7 ;
break;
}
}
}
for ( V_7 = V_60 ; V_7 ; V_7 = V_7 -> V_69 ) {
if ( V_61 -> V_71 == V_7 -> V_71 &&
F_54 ( V_61 -> V_72 , V_7 ) )
F_60 ( V_7 , V_61 ) ;
}
V_65:
* V_55 = V_61 -> V_69 ;
F_7 ( V_61 ) ;
F_58 ( V_73 , V_61 , V_58 , V_59 ) ;
F_59 ( & V_74 , V_75 , V_61 ) ;
if ( V_60 ) {
struct V_6 * V_76 = V_60 -> V_69 ;
if ( V_63 ) {
V_63 -> V_69 = V_60 -> V_69 ;
V_60 -> V_69 = V_62 -> V_69 ;
V_62 -> V_69 = V_60 ;
}
V_60 -> V_66 &= ~ V_67 ;
F_58 ( V_77 , V_60 , V_58 , V_59 ) ;
F_59 ( & V_74 ,
V_78 , V_60 ) ;
for ( V_7 = V_76 ; V_7 ; V_7 = V_7 -> V_69 ) {
if ( V_61 -> V_71 != V_7 -> V_71 ||
! F_54 ( V_61 -> V_72 , V_7 ) )
continue;
F_61 ( V_7 ) ;
}
}
if ( V_56 )
F_27 ( V_61 ) ;
}
static void F_48 ( struct V_26 * V_37 , struct V_6 * * V_55 ,
int V_56 )
{
F_56 ( V_37 , V_55 , V_56 , NULL , 0 ) ;
}
static int F_62 ( struct V_6 * V_7 , struct V_57 * V_58 ,
T_1 V_59 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_61 , * * V_55 , * * V_79 ;
struct V_80 V_81 ;
int V_82 ;
F_5 () ;
if ( ! V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return 0 ;
}
V_7 -> V_66 &= ~ V_67 ;
V_79 = & V_37 -> V_31 ;
for ( V_55 = & V_37 -> V_31 ; ( V_61 = * V_55 ) != NULL ;
V_55 = & V_61 -> V_69 ) {
if ( ! ( V_61 -> V_66 & V_67 ) &&
V_7 -> V_70 <= V_61 -> V_70 )
V_79 = & V_61 -> V_69 ;
if ( V_61 -> V_71 == V_7 -> V_71 &&
F_54 ( V_61 -> V_72 , V_7 ) ) {
if ( V_61 -> V_9 == V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return - V_83 ;
}
if ( V_61 -> V_70 != V_7 -> V_70 ) {
F_27 ( V_7 ) ;
return - V_84 ;
}
V_7 -> V_66 |= V_67 ;
}
}
V_81 . V_85 = V_7 -> V_72 ;
V_81 . V_86 = V_7 -> V_15 ;
V_82 = F_59 ( & V_87 ,
V_78 , & V_81 ) ;
V_82 = F_63 ( V_82 ) ;
if ( V_82 ) {
F_27 ( V_7 ) ;
return V_82 ;
}
if ( ! ( V_7 -> V_66 & V_67 ) ) {
F_64 ( ( V_4 T_1 ) V_7 -> V_9 ) ;
V_55 = V_79 ;
}
V_7 -> V_69 = * V_55 ;
* V_55 = V_7 ;
F_4 ( F_13 ( V_37 -> V_14 ) , V_7 ) ;
F_65 ( & V_88 ) ;
F_66 ( V_89 , & V_88 , 0 ) ;
F_58 ( V_77 , V_7 , V_58 , V_59 ) ;
F_59 ( & V_74 , V_78 , V_7 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_7 )
{
return F_62 ( V_7 , NULL , 0 ) ;
}
static int F_68 ( struct V_11 * V_14 , struct V_6 * V_7 )
{
struct V_26 * V_37 = F_69 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
F_27 ( V_7 ) ;
return - V_90 ;
}
F_70 ( V_37 ) ;
F_71 ( V_37 -> V_45 ) ;
if ( V_7 -> V_15 != V_37 ) {
F_30 ( V_7 -> V_15 ) ;
F_72 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
}
if ( F_73 ( V_7 -> V_9 ) )
V_7 -> V_70 = V_91 ;
return F_67 ( V_7 ) ;
}
struct V_26 * F_74 ( struct V_1 * V_1 , int V_92 )
{
struct V_11 * V_14 ;
struct V_26 * V_37 = NULL ;
F_10 () ;
V_14 = F_75 ( V_1 , V_92 ) ;
if ( V_14 )
V_37 = F_76 ( V_14 -> V_52 ) ;
F_18 () ;
return V_37 ;
}
struct V_6 * F_77 ( struct V_26 * V_37 , T_2 V_93 ,
T_2 V_94 )
{
F_5 () ;
F_53 (in_dev) {
if ( V_7 -> V_71 == V_94 && F_54 ( V_93 , V_7 ) )
return V_7 ;
} F_55 ( V_37 ) ;
return NULL ;
}
static int F_78 ( struct V_95 * V_96 , bool V_97 , const struct V_6 * V_7 )
{
struct V_98 V_99 = {
. V_100 . V_101 = V_7 -> V_72 ,
. V_102 = V_7 -> V_15 -> V_14 -> V_92 ,
} ;
int V_82 ;
F_5 () ;
F_79 ( V_96 ) ;
if ( V_97 )
V_82 = F_80 ( V_96 , & V_99 ) ;
else
V_82 = F_81 ( V_96 , & V_99 ) ;
F_82 ( V_96 ) ;
return V_82 ;
}
static int F_83 ( struct V_103 * V_104 , struct V_57 * V_58 ,
struct V_105 * V_106 )
{
struct V_1 * V_1 = F_84 ( V_104 -> V_96 ) ;
struct V_107 * V_108 [ V_109 + 1 ] ;
struct V_26 * V_37 ;
struct V_110 * V_111 ;
struct V_6 * V_7 , * * V_55 ;
int V_38 = - V_84 ;
F_5 () ;
V_38 = F_85 ( V_58 , sizeof( * V_111 ) , V_108 , V_109 , V_112 ,
V_106 ) ;
if ( V_38 < 0 )
goto V_113;
V_111 = F_86 ( V_58 ) ;
V_37 = F_74 ( V_1 , V_111 -> V_114 ) ;
if ( ! V_37 ) {
V_38 = - V_115 ;
goto V_113;
}
for ( V_55 = & V_37 -> V_31 ; ( V_7 = * V_55 ) != NULL ;
V_55 = & V_7 -> V_69 ) {
if ( V_108 [ V_116 ] &&
V_7 -> V_9 != F_87 ( V_108 [ V_116 ] ) )
continue;
if ( V_108 [ V_117 ] && F_88 ( V_108 [ V_117 ] , V_7 -> V_118 ) )
continue;
if ( V_108 [ V_119 ] &&
( V_111 -> V_120 != V_7 -> V_120 ||
! F_54 ( F_87 ( V_108 [ V_119 ] ) , V_7 ) ) )
continue;
if ( F_89 ( V_7 -> V_72 ) )
F_78 ( V_1 -> V_42 . V_121 , false , V_7 ) ;
F_56 ( V_37 , V_55 , 1 , V_58 , F_90 ( V_104 ) . V_59 ) ;
return 0 ;
}
V_38 = - V_122 ;
V_113:
return V_38 ;
}
static void F_91 ( struct V_123 * V_124 )
{
unsigned long V_125 , V_126 , V_76 , V_127 ;
struct V_6 * V_7 ;
struct V_128 * V_129 ;
int V_130 ;
V_125 = V_131 ;
V_126 = F_92 ( V_125 + V_132 ) ;
for ( V_130 = 0 ; V_130 < V_133 ; V_130 ++ ) {
bool V_134 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_135 ;
if ( V_7 -> V_66 & V_136 )
continue;
V_135 = ( V_125 - V_7 -> V_137 +
V_138 ) / V_139 ;
if ( V_7 -> V_140 != V_141 &&
V_135 >= V_7 -> V_140 ) {
V_134 = true ;
} else if ( V_7 -> V_142 ==
V_141 ) {
continue;
} else if ( V_135 >= V_7 -> V_142 ) {
if ( F_93 ( V_7 -> V_137 +
V_7 -> V_140 * V_139 , V_126 ) )
V_126 = V_7 -> V_137 +
V_7 -> V_140 * V_139 ;
if ( ! ( V_7 -> V_66 & V_143 ) )
V_134 = true ;
} else if ( F_93 ( V_7 -> V_137 +
V_7 -> V_142 * V_139 ,
V_126 ) ) {
V_126 = V_7 -> V_137 +
V_7 -> V_142 * V_139 ;
}
}
F_18 () ;
if ( ! V_134 )
continue;
F_94 () ;
F_95 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_135 ;
if ( V_7 -> V_66 & V_136 )
continue;
V_135 = ( V_125 - V_7 -> V_137 +
V_138 ) / V_139 ;
if ( V_7 -> V_140 != V_141 &&
V_135 >= V_7 -> V_140 ) {
struct V_6 * * V_55 ;
for ( V_55 = & V_7 -> V_15 -> V_31 ;
* V_55 != NULL ; V_55 = & ( * V_55 ) -> V_69 ) {
if ( * V_55 == V_7 ) {
F_48 ( V_7 -> V_15 ,
V_55 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_142 !=
V_141 &&
V_135 >= V_7 -> V_142 &&
! ( V_7 -> V_66 & V_143 ) ) {
V_7 -> V_66 |= V_143 ;
F_58 ( V_77 , V_7 , NULL , 0 ) ;
}
}
F_96 () ;
}
V_76 = F_92 ( V_126 ) ;
V_127 = V_126 ;
if ( F_93 ( V_76 , V_126 + V_144 ) )
V_127 = V_76 ;
V_125 = V_131 ;
if ( F_93 ( V_127 , V_125 + V_145 ) )
V_127 = V_125 + V_145 ;
F_66 ( V_89 , & V_88 ,
V_127 - V_125 ) ;
}
static void F_97 ( struct V_6 * V_7 , T_3 V_146 ,
T_3 V_147 )
{
unsigned long V_148 ;
V_7 -> V_66 &= ~ ( V_136 | V_143 ) ;
V_148 = F_98 ( V_146 , V_139 ) ;
if ( F_99 ( V_148 ) )
V_7 -> V_140 = V_148 ;
else
V_7 -> V_66 |= V_136 ;
V_148 = F_98 ( V_147 , V_139 ) ;
if ( F_99 ( V_148 ) ) {
if ( V_148 == 0 )
V_7 -> V_66 |= V_143 ;
V_7 -> V_142 = V_148 ;
}
V_7 -> V_137 = V_131 ;
if ( ! V_7 -> V_149 )
V_7 -> V_149 = V_7 -> V_137 ;
}
static struct V_6 * F_100 ( struct V_1 * V_1 , struct V_57 * V_58 ,
T_3 * V_150 , T_3 * V_151 )
{
struct V_107 * V_108 [ V_109 + 1 ] ;
struct V_6 * V_7 ;
struct V_110 * V_111 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_38 ;
V_38 = F_85 ( V_58 , sizeof( * V_111 ) , V_108 , V_109 , V_112 ,
NULL ) ;
if ( V_38 < 0 )
goto V_113;
V_111 = F_86 ( V_58 ) ;
V_38 = - V_84 ;
if ( V_111 -> V_120 > 32 || ! V_108 [ V_116 ] )
goto V_113;
V_14 = F_101 ( V_1 , V_111 -> V_114 ) ;
V_38 = - V_115 ;
if ( ! V_14 )
goto V_113;
V_37 = F_69 ( V_14 ) ;
V_38 = - V_90 ;
if ( ! V_37 )
goto V_113;
V_7 = F_21 () ;
if ( ! V_7 )
goto V_113;
F_70 ( V_37 ) ;
F_71 ( V_37 -> V_45 ) ;
F_72 ( V_37 ) ;
if ( ! V_108 [ V_119 ] )
V_108 [ V_119 ] = V_108 [ V_116 ] ;
F_102 ( & V_7 -> V_8 ) ;
V_7 -> V_120 = V_111 -> V_120 ;
V_7 -> V_71 = F_103 ( V_111 -> V_120 ) ;
V_7 -> V_66 = V_108 [ V_152 ] ? F_104 ( V_108 [ V_152 ] ) :
V_111 -> V_66 ;
V_7 -> V_70 = V_111 -> V_70 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_87 ( V_108 [ V_116 ] ) ;
V_7 -> V_72 = F_87 ( V_108 [ V_119 ] ) ;
if ( V_108 [ V_153 ] )
V_7 -> V_154 = F_87 ( V_108 [ V_153 ] ) ;
if ( V_108 [ V_117 ] )
F_105 ( V_7 -> V_118 , V_108 [ V_117 ] , V_155 ) ;
else
memcpy ( V_7 -> V_118 , V_14 -> V_35 , V_155 ) ;
if ( V_108 [ V_156 ] ) {
struct V_157 * V_158 ;
V_158 = F_106 ( V_108 [ V_156 ] ) ;
if ( ! V_158 -> V_159 || V_158 -> V_160 > V_158 -> V_159 ) {
V_38 = - V_84 ;
goto V_161;
}
* V_150 = V_158 -> V_159 ;
* V_151 = V_158 -> V_160 ;
}
return V_7 ;
V_161:
F_27 ( V_7 ) ;
V_113:
return F_44 ( V_38 ) ;
}
static struct V_6 * F_107 ( struct V_6 * V_7 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_61 , * * V_55 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_55 = & V_37 -> V_31 ; ( V_61 = * V_55 ) != NULL ;
V_55 = & V_61 -> V_69 ) {
if ( V_61 -> V_71 == V_7 -> V_71 &&
F_54 ( V_61 -> V_72 , V_7 ) &&
V_61 -> V_9 == V_7 -> V_9 )
return V_61 ;
}
return NULL ;
}
static int F_108 ( struct V_103 * V_104 , struct V_57 * V_58 ,
struct V_105 * V_106 )
{
struct V_1 * V_1 = F_84 ( V_104 -> V_96 ) ;
struct V_6 * V_7 ;
struct V_6 * V_162 ;
T_3 V_146 = V_141 ;
T_3 V_147 = V_141 ;
F_5 () ;
V_7 = F_100 ( V_1 , V_58 , & V_146 , & V_147 ) ;
if ( F_109 ( V_7 ) )
return F_110 ( V_7 ) ;
V_162 = F_107 ( V_7 ) ;
if ( ! V_162 ) {
F_97 ( V_7 , V_146 , V_147 ) ;
if ( V_7 -> V_66 & V_163 ) {
int V_82 = F_78 ( V_1 -> V_42 . V_121 ,
true , V_7 ) ;
if ( V_82 < 0 ) {
F_27 ( V_7 ) ;
return V_82 ;
}
}
return F_62 ( V_7 , V_58 , F_90 ( V_104 ) . V_59 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_58 -> V_164 & V_165 ||
! ( V_58 -> V_164 & V_166 ) )
return - V_83 ;
V_7 = V_162 ;
F_97 ( V_7 , V_146 , V_147 ) ;
F_65 ( & V_88 ) ;
F_66 ( V_89 ,
& V_88 , 0 ) ;
F_58 ( V_77 , V_7 , V_58 , F_90 ( V_104 ) . V_59 ) ;
}
return 0 ;
}
static int F_111 ( T_2 V_2 )
{
int V_167 = - 1 ;
if ( F_112 ( V_2 ) )
V_167 = 0 ;
else {
T_3 V_168 = F_113 ( V_2 ) ;
if ( F_114 ( V_168 ) )
V_167 = 8 ;
else if ( F_115 ( V_168 ) )
V_167 = 16 ;
else if ( F_116 ( V_168 ) )
V_167 = 24 ;
}
return V_167 ;
}
int F_117 ( struct V_1 * V_1 , unsigned int V_169 , void T_4 * V_170 )
{
struct V_171 V_172 ;
struct V_173 V_174 ;
struct V_173 * sin = (struct V_173 * ) & V_172 . V_175 ;
struct V_26 * V_37 ;
struct V_6 * * V_55 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_176 ;
int V_82 = - V_177 ;
int V_178 = 0 ;
if ( F_118 ( & V_172 , V_170 , sizeof( struct V_171 ) ) )
goto V_40;
V_172 . V_179 [ V_155 - 1 ] = 0 ;
memcpy ( & V_174 , sin , sizeof( * sin ) ) ;
V_176 = strchr ( V_172 . V_179 , ':' ) ;
if ( V_176 )
* V_176 = 0 ;
F_119 ( V_1 , V_172 . V_179 ) ;
switch ( V_169 ) {
case V_180 :
case V_181 :
case V_182 :
case V_183 :
V_178 = ( V_174 . V_184 == V_185 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_184 = V_185 ;
break;
case V_186 :
V_82 = - V_187 ;
if ( ! F_120 ( V_1 -> V_188 , V_189 ) )
goto V_40;
break;
case V_190 :
case V_191 :
case V_192 :
case V_193 :
V_82 = - V_187 ;
if ( ! F_120 ( V_1 -> V_188 , V_189 ) )
goto V_40;
V_82 = - V_84 ;
if ( sin -> V_184 != V_185 )
goto V_40;
break;
default:
V_82 = - V_84 ;
goto V_40;
}
F_94 () ;
V_82 = - V_115 ;
V_14 = F_121 ( V_1 , V_172 . V_179 ) ;
if ( ! V_14 )
goto V_194;
if ( V_176 )
* V_176 = ':' ;
V_37 = F_69 ( V_14 ) ;
if ( V_37 ) {
if ( V_178 ) {
for ( V_55 = & V_37 -> V_31 ; ( V_7 = * V_55 ) != NULL ;
V_55 = & V_7 -> V_69 ) {
if ( ! strcmp ( V_172 . V_179 , V_7 -> V_118 ) &&
V_174 . V_195 . V_101 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_55 = & V_37 -> V_31 ; ( V_7 = * V_55 ) != NULL ;
V_55 = & V_7 -> V_69 )
if ( ! strcmp ( V_172 . V_179 , V_7 -> V_118 ) )
break;
}
}
V_82 = - V_122 ;
if ( ! V_7 && V_169 != V_190 && V_169 != V_186 )
goto V_194;
switch ( V_169 ) {
case V_180 :
sin -> V_195 . V_101 = V_7 -> V_9 ;
goto V_196;
case V_181 :
sin -> V_195 . V_101 = V_7 -> V_154 ;
goto V_196;
case V_182 :
sin -> V_195 . V_101 = V_7 -> V_72 ;
goto V_196;
case V_183 :
sin -> V_195 . V_101 = V_7 -> V_71 ;
goto V_196;
case V_186 :
if ( V_176 ) {
V_82 = - V_122 ;
if ( ! V_7 )
break;
V_82 = 0 ;
if ( ! ( V_172 . V_197 & V_51 ) )
F_48 ( V_37 , V_55 , 1 ) ;
break;
}
V_82 = F_122 ( V_14 , V_172 . V_197 ) ;
break;
case V_190 :
V_82 = - V_84 ;
if ( F_111 ( sin -> V_195 . V_101 ) < 0 )
break;
if ( ! V_7 ) {
V_82 = - V_90 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_102 ( & V_7 -> V_8 ) ;
if ( V_176 )
memcpy ( V_7 -> V_118 , V_172 . V_179 , V_155 ) ;
else
memcpy ( V_7 -> V_118 , V_14 -> V_35 , V_155 ) ;
} else {
V_82 = 0 ;
if ( V_7 -> V_9 == sin -> V_195 . V_101 )
break;
F_48 ( V_37 , V_55 , 0 ) ;
V_7 -> V_154 = 0 ;
V_7 -> V_70 = 0 ;
}
V_7 -> V_72 = V_7 -> V_9 = sin -> V_195 . V_101 ;
if ( ! ( V_14 -> V_50 & V_198 ) ) {
V_7 -> V_120 = F_111 ( V_7 -> V_72 ) ;
V_7 -> V_71 = F_103 ( V_7 -> V_120 ) ;
if ( ( V_14 -> V_50 & V_199 ) &&
V_7 -> V_120 < 31 )
V_7 -> V_154 = V_7 -> V_72 |
~ V_7 -> V_71 ;
} else {
V_7 -> V_120 = 32 ;
V_7 -> V_71 = F_103 ( 32 ) ;
}
F_97 ( V_7 , V_141 , V_141 ) ;
V_82 = F_68 ( V_14 , V_7 ) ;
break;
case V_191 :
V_82 = 0 ;
if ( V_7 -> V_154 != sin -> V_195 . V_101 ) {
F_48 ( V_37 , V_55 , 0 ) ;
V_7 -> V_154 = sin -> V_195 . V_101 ;
F_67 ( V_7 ) ;
}
break;
case V_192 :
V_82 = 0 ;
if ( V_7 -> V_72 == sin -> V_195 . V_101 )
break;
V_82 = - V_84 ;
if ( F_111 ( sin -> V_195 . V_101 ) < 0 )
break;
V_82 = 0 ;
F_48 ( V_37 , V_55 , 0 ) ;
V_7 -> V_72 = sin -> V_195 . V_101 ;
F_67 ( V_7 ) ;
break;
case V_193 :
V_82 = - V_84 ;
if ( F_123 ( sin -> V_195 . V_101 , 0 ) )
break;
V_82 = 0 ;
if ( V_7 -> V_71 != sin -> V_195 . V_101 ) {
T_2 V_200 = V_7 -> V_71 ;
F_48 ( V_37 , V_55 , 0 ) ;
V_7 -> V_71 = sin -> V_195 . V_101 ;
V_7 -> V_120 = F_124 ( V_7 -> V_71 ) ;
if ( ( V_14 -> V_50 & V_199 ) &&
( V_7 -> V_120 < 31 ) &&
( V_7 -> V_154 ==
( V_7 -> V_9 | ~ V_200 ) ) ) {
V_7 -> V_154 = ( V_7 -> V_9 |
~ sin -> V_195 . V_101 ) ;
}
F_67 ( V_7 ) ;
}
break;
}
V_194:
F_96 () ;
V_40:
return V_82 ;
V_196:
F_96 () ;
V_82 = F_125 ( V_170 , & V_172 , sizeof( struct V_171 ) ) ? - V_177 : 0 ;
goto V_40;
}
static int F_126 ( struct V_11 * V_14 , char T_4 * V_201 , int V_202 )
{
struct V_26 * V_37 = F_69 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_171 V_172 ;
int V_194 = 0 ;
if ( ! V_37 )
goto V_40;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_69 ) {
if ( ! V_201 ) {
V_194 += sizeof( V_172 ) ;
continue;
}
if ( V_202 < ( int ) sizeof( V_172 ) )
break;
memset ( & V_172 , 0 , sizeof( struct V_171 ) ) ;
strcpy ( V_172 . V_179 , V_7 -> V_118 ) ;
( * (struct V_173 * ) & V_172 . V_175 ) . V_184 = V_185 ;
( * (struct V_173 * ) & V_172 . V_175 ) . V_195 . V_101 =
V_7 -> V_9 ;
if ( F_125 ( V_201 , & V_172 , sizeof( struct V_171 ) ) ) {
V_194 = - V_177 ;
break;
}
V_201 += sizeof( struct V_171 ) ;
V_202 -= sizeof( struct V_171 ) ;
V_194 += sizeof( struct V_171 ) ;
}
V_40:
return V_194 ;
}
static T_2 F_127 ( const struct V_26 * V_37 ,
int V_203 )
{
F_53 (in_dev) {
if ( V_7 -> V_70 != V_204 &&
V_7 -> V_70 <= V_203 )
return V_7 -> V_9 ;
} F_55 ( V_37 ) ;
return 0 ;
}
T_2 F_128 ( const struct V_11 * V_14 , T_2 V_205 , int V_203 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
int V_206 ;
F_10 () ;
V_37 = F_129 ( V_14 ) ;
if ( ! V_37 )
goto V_207;
F_53 (in_dev) {
if ( V_7 -> V_70 > V_203 )
continue;
if ( ! V_205 || F_54 ( V_205 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_208;
V_207:
V_206 = F_130 ( V_14 ) ;
if ( V_206 &&
( V_14 = F_75 ( V_1 , V_206 ) ) &&
( V_37 = F_129 ( V_14 ) ) ) {
V_2 = F_127 ( V_37 , V_203 ) ;
if ( V_2 )
goto V_208;
}
F_131 (net, dev) {
if ( F_130 ( V_14 ) != V_206 )
continue;
V_37 = F_129 ( V_14 ) ;
if ( ! V_37 )
continue;
V_2 = F_127 ( V_37 , V_203 ) ;
if ( V_2 )
goto V_208;
}
V_208:
F_18 () ;
return V_2 ;
}
static T_2 F_132 ( struct V_26 * V_37 , T_2 V_205 ,
T_2 V_22 , int V_203 )
{
int V_209 = 0 ;
T_2 V_2 = 0 ;
F_133 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_70 <= V_203 ) {
V_2 = V_7 -> V_9 ;
if ( V_209 )
break;
}
if ( ! V_209 ) {
V_209 = ( ! V_22 || F_54 ( V_22 , V_7 ) ) &&
( ! V_205 || F_54 ( V_205 , V_7 ) ) ;
if ( V_209 && V_2 ) {
if ( V_22 || ! V_205 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_70 <= V_203 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_209 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_209 ? V_2 : 0 ;
}
T_2 F_134 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_205 , T_2 V_22 , int V_203 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 )
return F_132 ( V_37 , V_205 , V_22 , V_203 ) ;
F_10 () ;
F_131 (net, dev) {
V_37 = F_129 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_132 ( V_37 , V_205 , V_22 , V_203 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_135 ( struct V_210 * V_211 )
{
return F_136 ( & V_74 , V_211 ) ;
}
int F_137 ( struct V_210 * V_211 )
{
return F_138 ( & V_74 , V_211 ) ;
}
int F_139 ( struct V_210 * V_211 )
{
return F_136 ( & V_87 , V_211 ) ;
}
int F_140 ( struct V_210 * V_211 )
{
return F_138 ( & V_87 ,
V_211 ) ;
}
static void F_141 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_212 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_69 ) {
char V_213 [ V_155 ] , * V_214 ;
memcpy ( V_213 , V_7 -> V_118 , V_155 ) ;
memcpy ( V_7 -> V_118 , V_14 -> V_35 , V_155 ) ;
if ( V_212 ++ == 0 )
goto V_215;
V_214 = strchr ( V_213 , ':' ) ;
if ( ! V_214 ) {
sprintf ( V_213 , L_4 , V_212 ) ;
V_214 = V_213 ;
}
if ( strlen ( V_214 ) + strlen ( V_14 -> V_35 ) < V_155 )
strcat ( V_7 -> V_118 , V_214 ) ;
else
strcpy ( V_7 -> V_118 + ( V_155 - strlen ( V_214 ) - 1 ) , V_214 ) ;
V_215:
F_58 ( V_77 , V_7 , NULL , 0 ) ;
}
}
static bool F_142 ( unsigned int V_216 )
{
return V_216 >= 68 ;
}
static void F_143 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_69 ) {
F_144 ( V_217 , V_218 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_219 , NULL ) ;
}
}
static int F_145 ( struct V_210 * V_220 , unsigned long V_221 ,
void * V_222 )
{
struct V_11 * V_14 = F_146 ( V_222 ) ;
struct V_26 * V_37 = F_69 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_221 == V_223 ) {
V_37 = F_36 ( V_14 ) ;
if ( F_109 ( V_37 ) )
return F_147 ( F_110 ( V_37 ) ) ;
if ( V_14 -> V_50 & V_224 ) {
F_148 ( V_37 , V_225 , 1 ) ;
F_148 ( V_37 , V_226 , 1 ) ;
}
} else if ( V_221 == V_227 ) {
if ( F_142 ( V_14 -> V_216 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_40;
}
switch ( V_221 ) {
case V_223 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_14 -> V_52 , NULL ) ;
break;
case V_78 :
if ( ! F_142 ( V_14 -> V_216 ) )
break;
if ( V_14 -> V_50 & V_224 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_102 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_72 = F_149 ( V_228 ) ;
V_7 -> V_120 = 8 ;
V_7 -> V_71 = F_103 ( 8 ) ;
F_72 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_70 = V_91 ;
memcpy ( V_7 -> V_118 , V_14 -> V_35 , V_155 ) ;
F_97 ( V_7 , V_141 ,
V_141 ) ;
F_70 ( V_37 ) ;
F_71 ( V_37 -> V_45 ) ;
F_67 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_229 :
if ( ! F_150 ( V_37 ) )
break;
case V_230 :
F_143 ( V_14 , V_37 ) ;
break;
case V_75 :
F_151 ( V_37 ) ;
break;
case V_231 :
F_152 ( V_37 ) ;
break;
case V_232 :
F_153 ( V_37 ) ;
break;
case V_227 :
if ( F_142 ( V_14 -> V_216 ) )
break;
case V_233 :
F_46 ( V_37 ) ;
break;
case V_234 :
F_141 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_40:
return V_235 ;
}
static T_5 F_154 ( void )
{
return F_155 ( sizeof( struct V_110 ) )
+ F_156 ( 4 )
+ F_156 ( 4 )
+ F_156 ( 4 )
+ F_156 ( V_155 )
+ F_156 ( 4 )
+ F_156 ( sizeof( struct V_157 ) ) ;
}
static inline T_1 F_157 ( unsigned long V_236 )
{
return ( V_236 - V_237 ) * 100UL / V_139 ;
}
static int F_158 ( struct V_103 * V_104 , unsigned long V_236 ,
unsigned long V_238 , T_1 V_239 , T_1 V_240 )
{
struct V_157 V_158 ;
V_158 . V_236 = F_157 ( V_236 ) ;
V_158 . V_238 = F_157 ( V_238 ) ;
V_158 . V_160 = V_239 ;
V_158 . V_159 = V_240 ;
return F_159 ( V_104 , V_156 , sizeof( V_158 ) , & V_158 ) ;
}
static int F_160 ( struct V_103 * V_104 , struct V_6 * V_7 ,
T_1 V_59 , T_1 V_241 , int V_221 , unsigned int V_50 )
{
struct V_110 * V_111 ;
struct V_57 * V_58 ;
T_1 V_239 , V_240 ;
V_58 = F_161 ( V_104 , V_59 , V_241 , V_221 , sizeof( * V_111 ) , V_50 ) ;
if ( ! V_58 )
return - V_242 ;
V_111 = F_86 ( V_58 ) ;
V_111 -> V_243 = V_185 ;
V_111 -> V_120 = V_7 -> V_120 ;
V_111 -> V_66 = V_7 -> V_66 ;
V_111 -> V_70 = V_7 -> V_70 ;
V_111 -> V_114 = V_7 -> V_15 -> V_14 -> V_92 ;
if ( ! ( V_111 -> V_66 & V_136 ) ) {
V_239 = V_7 -> V_142 ;
V_240 = V_7 -> V_140 ;
if ( V_239 != V_141 ) {
long V_244 = ( V_131 - V_7 -> V_137 ) / V_139 ;
if ( V_239 > V_244 )
V_239 -= V_244 ;
else
V_239 = 0 ;
if ( V_240 != V_141 ) {
if ( V_240 > V_244 )
V_240 -= V_244 ;
else
V_240 = 0 ;
}
}
} else {
V_239 = V_141 ;
V_240 = V_141 ;
}
if ( ( V_7 -> V_72 &&
F_162 ( V_104 , V_119 , V_7 -> V_72 ) ) ||
( V_7 -> V_9 &&
F_162 ( V_104 , V_116 , V_7 -> V_9 ) ) ||
( V_7 -> V_154 &&
F_162 ( V_104 , V_153 , V_7 -> V_154 ) ) ||
( V_7 -> V_118 [ 0 ] &&
F_163 ( V_104 , V_117 , V_7 -> V_118 ) ) ||
F_164 ( V_104 , V_152 , V_7 -> V_66 ) ||
F_158 ( V_104 , V_7 -> V_149 , V_7 -> V_137 ,
V_239 , V_240 ) )
goto V_245;
F_165 ( V_104 , V_58 ) ;
return 0 ;
V_245:
F_166 ( V_104 , V_58 ) ;
return - V_242 ;
}
static int F_167 ( struct V_103 * V_104 , struct V_246 * V_247 )
{
struct V_1 * V_1 = F_84 ( V_104 -> V_96 ) ;
int V_248 , V_249 ;
int V_250 , V_251 ;
int V_252 , V_253 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_6 * V_7 ;
struct V_254 * V_30 ;
V_249 = V_247 -> args [ 0 ] ;
V_251 = V_250 = V_247 -> args [ 1 ] ;
V_253 = V_252 = V_247 -> args [ 2 ] ;
for ( V_248 = V_249 ; V_248 < V_255 ; V_248 ++ , V_251 = 0 ) {
V_250 = 0 ;
V_30 = & V_1 -> V_256 [ V_248 ] ;
F_10 () ;
V_247 -> V_241 = F_168 ( & V_1 -> V_42 . V_257 ) ^
V_1 -> V_258 ;
F_11 (dev, head, index_hlist) {
if ( V_250 < V_251 )
goto V_259;
if ( V_248 > V_249 || V_250 > V_251 )
V_253 = 0 ;
V_37 = F_129 ( V_14 ) ;
if ( ! V_37 )
goto V_259;
for ( V_7 = V_37 -> V_31 , V_252 = 0 ; V_7 ;
V_7 = V_7 -> V_69 , V_252 ++ ) {
if ( V_252 < V_253 )
continue;
if ( F_160 ( V_104 , V_7 ,
F_90 ( V_247 -> V_104 ) . V_59 ,
V_247 -> V_58 -> V_260 ,
V_77 , V_261 ) < 0 ) {
F_18 () ;
goto V_194;
}
F_169 ( V_247 , F_170 ( V_104 ) ) ;
}
V_259:
V_250 ++ ;
}
F_18 () ;
}
V_194:
V_247 -> args [ 0 ] = V_248 ;
V_247 -> args [ 1 ] = V_250 ;
V_247 -> args [ 2 ] = V_252 ;
return V_104 -> V_202 ;
}
static void F_58 ( int V_221 , struct V_6 * V_7 , struct V_57 * V_58 ,
T_1 V_59 )
{
struct V_103 * V_104 ;
T_1 V_241 = V_58 ? V_58 -> V_260 : 0 ;
int V_38 = - V_90 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_104 = F_171 ( F_154 () , V_28 ) ;
if ( ! V_104 )
goto V_113;
V_38 = F_160 ( V_104 , V_7 , V_59 , V_241 , V_221 , 0 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_242 ) ;
F_172 ( V_104 ) ;
goto V_113;
}
F_173 ( V_104 , V_1 , V_59 , V_262 , V_58 , V_28 ) ;
return;
V_113:
if ( V_38 < 0 )
F_174 ( V_1 , V_262 , V_38 ) ;
}
static T_5 F_175 ( const struct V_11 * V_14 ,
T_1 V_263 )
{
struct V_26 * V_37 = F_76 ( V_14 -> V_52 ) ;
if ( ! V_37 )
return 0 ;
return F_156 ( V_264 * 4 ) ;
}
static int F_176 ( struct V_103 * V_104 , const struct V_11 * V_14 ,
T_1 V_263 )
{
struct V_26 * V_37 = F_76 ( V_14 -> V_52 ) ;
struct V_107 * V_265 ;
int V_130 ;
if ( ! V_37 )
return - V_266 ;
V_265 = F_177 ( V_104 , V_267 , V_264 * 4 ) ;
if ( ! V_265 )
return - V_242 ;
for ( V_130 = 0 ; V_130 < V_264 ; V_130 ++ )
( ( T_1 * ) F_106 ( V_265 ) ) [ V_130 ] = V_37 -> V_41 . V_268 [ V_130 ] ;
return 0 ;
}
static int F_178 ( const struct V_11 * V_14 ,
const struct V_107 * V_265 )
{
struct V_107 * V_53 , * V_108 [ V_269 + 1 ] ;
int V_38 , V_270 ;
if ( V_14 && ! F_69 ( V_14 ) )
return - V_271 ;
V_38 = F_179 ( V_108 , V_269 , V_265 , V_272 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_108 [ V_267 ] ) {
F_180 (a, tb[IFLA_INET_CONF], rem) {
int V_273 = F_181 ( V_53 ) ;
if ( F_182 ( V_53 ) < 4 )
return - V_84 ;
if ( V_273 <= 0 || V_273 > V_264 )
return - V_84 ;
}
}
return 0 ;
}
static int F_183 ( struct V_11 * V_14 , const struct V_107 * V_265 )
{
struct V_26 * V_37 = F_69 ( V_14 ) ;
struct V_107 * V_53 , * V_108 [ V_269 + 1 ] ;
int V_270 ;
if ( ! V_37 )
return - V_271 ;
if ( F_179 ( V_108 , V_269 , V_265 , NULL , NULL ) < 0 )
F_184 () ;
if ( V_108 [ V_267 ] ) {
F_180 (a, tb[IFLA_INET_CONF], rem)
F_185 ( V_37 , F_181 ( V_53 ) , F_104 ( V_53 ) ) ;
}
return 0 ;
}
static int F_186 ( int type )
{
int V_274 = F_155 ( sizeof( struct V_275 ) )
+ F_156 ( 4 ) ;
bool V_276 = false ;
if ( type == V_277 )
V_276 = true ;
if ( V_276 || type == V_278 )
V_274 += F_156 ( 4 ) ;
if ( V_276 || type == V_279 )
V_274 += F_156 ( 4 ) ;
if ( V_276 || type == V_280 )
V_274 += F_156 ( 4 ) ;
if ( V_276 || type == V_281 )
V_274 += F_156 ( 4 ) ;
if ( V_276 || type == V_282 )
V_274 += F_156 ( 4 ) ;
return V_274 ;
}
static int F_187 ( struct V_103 * V_104 , int V_92 ,
struct V_283 * V_284 , T_1 V_59 ,
T_1 V_241 , int V_221 , unsigned int V_50 ,
int type )
{
struct V_57 * V_58 ;
struct V_275 * V_285 ;
bool V_276 = false ;
V_58 = F_161 ( V_104 , V_59 , V_241 , V_221 , sizeof( struct V_275 ) ,
V_50 ) ;
if ( ! V_58 )
return - V_242 ;
if ( type == V_277 )
V_276 = true ;
V_285 = F_86 ( V_58 ) ;
V_285 -> V_286 = V_185 ;
if ( F_188 ( V_104 , V_287 , V_92 ) < 0 )
goto V_245;
if ( ! V_284 )
goto V_40;
if ( ( V_276 || type == V_278 ) &&
F_188 ( V_104 , V_278 ,
F_38 ( * V_284 , V_48 ) ) < 0 )
goto V_245;
if ( ( V_276 || type == V_279 ) &&
F_188 ( V_104 , V_279 ,
F_38 ( * V_284 , V_288 ) ) < 0 )
goto V_245;
if ( ( V_276 || type == V_280 ) &&
F_188 ( V_104 , V_280 ,
F_38 ( * V_284 , V_289 ) ) < 0 )
goto V_245;
if ( ( V_276 || type == V_281 ) &&
F_188 ( V_104 , V_281 ,
F_38 ( * V_284 , V_290 ) ) < 0 )
goto V_245;
if ( ( V_276 || type == V_282 ) &&
F_188 ( V_104 , V_282 ,
F_38 ( * V_284 , V_291 ) ) < 0 )
goto V_245;
V_40:
F_165 ( V_104 , V_58 ) ;
return 0 ;
V_245:
F_166 ( V_104 , V_58 ) ;
return - V_242 ;
}
void F_189 ( struct V_1 * V_1 , int V_221 , int type ,
int V_92 , struct V_283 * V_284 )
{
struct V_103 * V_104 ;
int V_38 = - V_90 ;
V_104 = F_171 ( F_186 ( type ) , V_28 ) ;
if ( ! V_104 )
goto V_113;
V_38 = F_187 ( V_104 , V_92 , V_284 , 0 , 0 ,
V_221 , 0 , type ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_242 ) ;
F_172 ( V_104 ) ;
goto V_113;
}
F_173 ( V_104 , V_1 , 0 , V_292 , NULL , V_28 ) ;
return;
V_113:
if ( V_38 < 0 )
F_174 ( V_1 , V_292 , V_38 ) ;
}
static int F_190 ( struct V_103 * V_293 ,
struct V_57 * V_58 ,
struct V_105 * V_106 )
{
struct V_1 * V_1 = F_84 ( V_293 -> V_96 ) ;
struct V_107 * V_108 [ V_294 + 1 ] ;
struct V_275 * V_285 ;
struct V_103 * V_104 ;
struct V_283 * V_284 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_92 ;
int V_38 ;
V_38 = F_85 ( V_58 , sizeof( * V_285 ) , V_108 , V_294 ,
V_295 , V_106 ) ;
if ( V_38 < 0 )
goto V_113;
V_38 = - V_84 ;
if ( ! V_108 [ V_287 ] )
goto V_113;
V_92 = F_191 ( V_108 [ V_287 ] ) ;
switch ( V_92 ) {
case V_296 :
V_284 = V_1 -> V_42 . V_297 ;
break;
case V_298 :
V_284 = V_1 -> V_42 . V_43 ;
break;
default:
V_14 = F_101 ( V_1 , V_92 ) ;
if ( ! V_14 )
goto V_113;
V_37 = F_69 ( V_14 ) ;
if ( ! V_37 )
goto V_113;
V_284 = & V_37 -> V_41 ;
break;
}
V_38 = - V_90 ;
V_104 = F_171 ( F_186 ( V_277 ) , V_28 ) ;
if ( ! V_104 )
goto V_113;
V_38 = F_187 ( V_104 , V_92 , V_284 ,
F_90 ( V_293 ) . V_59 ,
V_58 -> V_260 , V_299 , 0 ,
V_277 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_242 ) ;
F_172 ( V_104 ) ;
goto V_113;
}
V_38 = F_192 ( V_104 , V_1 , F_90 ( V_293 ) . V_59 ) ;
V_113:
return V_38 ;
}
static int F_193 ( struct V_103 * V_104 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_84 ( V_104 -> V_96 ) ;
int V_248 , V_249 ;
int V_250 , V_251 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_254 * V_30 ;
V_249 = V_247 -> args [ 0 ] ;
V_251 = V_250 = V_247 -> args [ 1 ] ;
for ( V_248 = V_249 ; V_248 < V_255 ; V_248 ++ , V_251 = 0 ) {
V_250 = 0 ;
V_30 = & V_1 -> V_256 [ V_248 ] ;
F_10 () ;
V_247 -> V_241 = F_168 ( & V_1 -> V_42 . V_257 ) ^
V_1 -> V_258 ;
F_11 (dev, head, index_hlist) {
if ( V_250 < V_251 )
goto V_259;
V_37 = F_129 ( V_14 ) ;
if ( ! V_37 )
goto V_259;
if ( F_187 ( V_104 , V_14 -> V_92 ,
& V_37 -> V_41 ,
F_90 ( V_247 -> V_104 ) . V_59 ,
V_247 -> V_58 -> V_260 ,
V_299 ,
V_261 ,
V_277 ) < 0 ) {
F_18 () ;
goto V_194;
}
F_169 ( V_247 , F_170 ( V_104 ) ) ;
V_259:
V_250 ++ ;
}
F_18 () ;
}
if ( V_248 == V_255 ) {
if ( F_187 ( V_104 , V_296 ,
V_1 -> V_42 . V_297 ,
F_90 ( V_247 -> V_104 ) . V_59 ,
V_247 -> V_58 -> V_260 ,
V_299 , V_261 ,
V_277 ) < 0 )
goto V_194;
else
V_248 ++ ;
}
if ( V_248 == V_255 + 1 ) {
if ( F_187 ( V_104 , V_298 ,
V_1 -> V_42 . V_43 ,
F_90 ( V_247 -> V_104 ) . V_59 ,
V_247 -> V_58 -> V_260 ,
V_299 , V_261 ,
V_277 ) < 0 )
goto V_194;
else
V_248 ++ ;
}
V_194:
V_247 -> args [ 0 ] = V_248 ;
V_247 -> args [ 1 ] = V_250 ;
return V_104 -> V_202 ;
}
static void F_194 ( struct V_1 * V_1 , int V_130 )
{
struct V_11 * V_14 ;
F_10 () ;
F_131 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_129 ( V_14 ) ;
if ( V_37 && ! F_195 ( V_130 , V_37 -> V_41 . V_300 ) )
V_37 -> V_41 . V_268 [ V_130 ] = V_1 -> V_42 . V_43 -> V_268 [ V_130 ] ;
}
F_18 () ;
}
static void F_196 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_301 = F_197 ( V_1 , V_48 ) ;
F_197 ( V_1 , V_302 ) = ! V_301 ;
F_198 ( V_1 , V_48 ) = V_301 ;
F_189 ( V_1 , V_299 ,
V_278 ,
V_296 ,
V_1 -> V_42 . V_297 ) ;
F_189 ( V_1 , V_299 ,
V_278 ,
V_298 ,
V_1 -> V_42 . V_43 ) ;
F_199 (net, dev) {
struct V_26 * V_37 ;
if ( V_301 )
F_39 ( V_14 ) ;
V_37 = F_69 ( V_14 ) ;
if ( V_37 ) {
F_148 ( V_37 , V_48 , V_301 ) ;
F_189 ( V_1 , V_299 ,
V_278 ,
V_14 -> V_92 , & V_37 -> V_41 ) ;
}
}
}
static int F_200 ( struct V_1 * V_1 , struct V_283 * V_41 )
{
if ( V_41 == V_1 -> V_42 . V_43 )
return V_298 ;
else if ( V_41 == V_1 -> V_42 . V_297 )
return V_296 ;
else {
struct V_26 * V_27
= F_24 ( V_41 , struct V_26 , V_41 ) ;
return V_27 -> V_14 -> V_92 ;
}
}
static int F_201 ( struct V_303 * V_304 , int V_305 ,
void T_4 * V_306 ,
T_5 * V_307 , T_6 * V_308 )
{
int V_309 = * ( int * ) V_304 -> V_268 ;
int V_82 = F_202 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
int V_310 = * ( int * ) V_304 -> V_268 ;
if ( V_305 ) {
struct V_283 * V_41 = V_304 -> V_311 ;
struct V_1 * V_1 = V_304 -> V_312 ;
int V_130 = ( int * ) V_304 -> V_268 - V_41 -> V_268 ;
int V_92 ;
F_203 ( V_130 , V_41 -> V_300 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_194 ( V_1 , V_130 ) ;
if ( V_130 == V_313 - 1 ||
V_130 == V_314 - 1 )
if ( ( V_310 == 0 ) && ( V_309 != 0 ) )
F_204 ( V_1 ) ;
if ( V_130 == V_315 - 1 &&
V_310 != V_309 ) {
V_92 = F_200 ( V_1 , V_41 ) ;
F_189 ( V_1 , V_299 ,
V_279 ,
V_92 , V_41 ) ;
}
if ( V_130 == V_316 - 1 &&
V_310 != V_309 ) {
V_92 = F_200 ( V_1 , V_41 ) ;
F_189 ( V_1 , V_299 ,
V_281 ,
V_92 , V_41 ) ;
}
if ( V_130 == V_317 - 1 &&
V_310 != V_309 ) {
V_92 = F_200 ( V_1 , V_41 ) ;
F_189 ( V_1 , V_299 ,
V_282 ,
V_92 , V_41 ) ;
}
}
return V_82 ;
}
static int F_205 ( struct V_303 * V_304 , int V_305 ,
void T_4 * V_306 ,
T_5 * V_307 , T_6 * V_308 )
{
int * V_318 = V_304 -> V_268 ;
int V_3 = * V_318 ;
T_6 V_319 = * V_308 ;
int V_82 = F_202 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
if ( V_305 && * V_318 != V_3 ) {
struct V_1 * V_1 = V_304 -> V_312 ;
if ( V_318 != & F_198 ( V_1 , V_48 ) ) {
if ( ! F_206 () ) {
* V_318 = V_3 ;
* V_308 = V_319 ;
return F_207 () ;
}
if ( V_318 == & F_197 ( V_1 , V_48 ) ) {
F_196 ( V_1 ) ;
} else {
struct V_283 * V_41 = V_304 -> V_311 ;
struct V_26 * V_27 =
F_24 ( V_41 , struct V_26 , V_41 ) ;
if ( * V_318 )
F_39 ( V_27 -> V_14 ) ;
F_189 ( V_1 , V_299 ,
V_278 ,
V_27 -> V_14 -> V_92 ,
V_41 ) ;
}
F_96 () ;
F_204 ( V_1 ) ;
} else
F_189 ( V_1 , V_299 ,
V_278 ,
V_298 ,
V_1 -> V_42 . V_43 ) ;
}
return V_82 ;
}
static int F_208 ( struct V_303 * V_304 , int V_305 ,
void T_4 * V_306 ,
T_5 * V_307 , T_6 * V_308 )
{
int * V_318 = V_304 -> V_268 ;
int V_3 = * V_318 ;
int V_82 = F_202 ( V_304 , V_305 , V_306 , V_307 , V_308 ) ;
struct V_1 * V_1 = V_304 -> V_312 ;
if ( V_305 && * V_318 != V_3 )
F_204 ( V_1 ) ;
return V_82 ;
}
static int F_209 ( struct V_1 * V_1 , char * V_320 ,
int V_92 , struct V_283 * V_321 )
{
int V_130 ;
struct V_322 * V_323 ;
char V_324 [ sizeof( L_6 ) + V_155 ] ;
V_323 = F_210 ( & V_325 , sizeof( * V_323 ) , V_28 ) ;
if ( ! V_323 )
goto V_40;
for ( V_130 = 0 ; V_130 < F_211 ( V_323 -> V_326 ) - 1 ; V_130 ++ ) {
V_323 -> V_326 [ V_130 ] . V_268 += ( char * ) V_321 - ( char * ) & V_283 ;
V_323 -> V_326 [ V_130 ] . V_311 = V_321 ;
V_323 -> V_326 [ V_130 ] . V_312 = V_1 ;
}
snprintf ( V_324 , sizeof( V_324 ) , L_7 , V_320 ) ;
V_323 -> V_327 = F_212 ( V_1 , V_324 , V_323 -> V_326 ) ;
if ( ! V_323 -> V_327 )
goto free;
V_321 -> V_44 = V_323 ;
F_189 ( V_1 , V_299 , V_277 ,
V_92 , V_321 ) ;
return 0 ;
free:
F_26 ( V_323 ) ;
V_40:
return - V_90 ;
}
static void F_213 ( struct V_1 * V_1 ,
struct V_283 * V_41 , int V_92 )
{
struct V_322 * V_323 = V_41 -> V_44 ;
if ( V_323 ) {
V_41 -> V_44 = NULL ;
F_214 ( V_323 -> V_327 ) ;
F_26 ( V_323 ) ;
}
F_189 ( V_1 , V_328 , 0 , V_92 , NULL ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
int V_38 ;
if ( ! F_215 ( V_27 -> V_14 -> V_35 ) )
return - V_84 ;
V_38 = F_216 ( V_27 -> V_14 , V_27 -> V_45 , NULL ) ;
if ( V_38 )
return V_38 ;
V_38 = F_209 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
V_27 -> V_14 -> V_92 , & V_27 -> V_41 ) ;
if ( V_38 )
F_217 ( V_27 -> V_45 ) ;
return V_38 ;
}
static void F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_13 ( V_27 -> V_14 ) ;
F_213 ( V_1 , & V_27 -> V_41 , V_27 -> V_14 -> V_92 ) ;
F_217 ( V_27 -> V_45 ) ;
}
static T_7 int F_218 ( struct V_1 * V_1 )
{
int V_38 ;
struct V_283 * V_276 , * V_329 ;
#ifdef F_219
struct V_303 * V_330 = V_331 ;
struct V_332 * V_333 ;
#endif
V_38 = - V_39 ;
V_276 = & V_283 ;
V_329 = & V_334 ;
if ( ! F_12 ( V_1 , & V_335 ) ) {
V_276 = F_210 ( V_276 , sizeof( V_283 ) , V_28 ) ;
if ( ! V_276 )
goto V_336;
V_329 = F_210 ( V_329 , sizeof( V_334 ) , V_28 ) ;
if ( ! V_329 )
goto V_337;
#ifdef F_219
V_330 = F_210 ( V_330 , sizeof( V_331 ) , V_28 ) ;
if ( ! V_330 )
goto V_338;
V_330 [ 0 ] . V_268 = & V_276 -> V_268 [ V_339 - 1 ] ;
V_330 [ 0 ] . V_311 = V_276 ;
V_330 [ 0 ] . V_312 = V_1 ;
#endif
}
#ifdef F_219
V_38 = F_209 ( V_1 , L_8 , V_296 , V_276 ) ;
if ( V_38 < 0 )
goto V_340;
V_38 = F_209 ( V_1 , L_9 ,
V_298 , V_329 ) ;
if ( V_38 < 0 )
goto V_341;
V_38 = - V_39 ;
V_333 = F_212 ( V_1 , L_10 , V_330 ) ;
if ( ! V_333 )
goto V_342;
V_1 -> V_42 . V_333 = V_333 ;
#endif
V_1 -> V_42 . V_297 = V_276 ;
V_1 -> V_42 . V_43 = V_329 ;
return 0 ;
#ifdef F_219
V_342:
F_213 ( V_1 , V_329 , V_298 ) ;
V_341:
F_213 ( V_1 , V_276 , V_296 ) ;
V_340:
if ( V_330 != V_331 )
F_26 ( V_330 ) ;
V_338:
#endif
if ( V_329 != & V_334 )
F_26 ( V_329 ) ;
V_337:
if ( V_276 != & V_283 )
F_26 ( V_276 ) ;
V_336:
return V_38 ;
}
static T_8 void F_220 ( struct V_1 * V_1 )
{
#ifdef F_219
struct V_303 * V_330 ;
V_330 = V_1 -> V_42 . V_333 -> V_343 ;
F_214 ( V_1 -> V_42 . V_333 ) ;
F_213 ( V_1 , V_1 -> V_42 . V_43 ,
V_298 ) ;
F_213 ( V_1 , V_1 -> V_42 . V_297 ,
V_296 ) ;
F_26 ( V_330 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_297 ) ;
}
void T_9 F_221 ( void )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_133 ; V_130 ++ )
F_222 ( & V_10 [ V_130 ] ) ;
F_223 ( & V_344 ) ;
F_224 ( V_345 , F_126 ) ;
F_225 ( & V_346 ) ;
F_66 ( V_89 , & V_88 , 0 ) ;
F_226 ( & V_347 ) ;
F_227 ( V_345 , V_77 , F_108 , NULL , 0 ) ;
F_227 ( V_345 , V_73 , F_83 , NULL , 0 ) ;
F_227 ( V_345 , V_348 , NULL , F_167 , 0 ) ;
F_227 ( V_345 , V_349 , F_190 ,
F_193 , 0 ) ;
}
