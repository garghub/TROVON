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
F_40 ( V_37 ) ;
V_38 = F_19 ( V_37 ) ;
if ( V_38 ) {
V_37 -> V_36 = 1 ;
F_25 ( V_37 ) ;
V_37 = NULL ;
goto V_40;
}
F_41 ( V_37 ) ;
if ( V_14 -> V_49 & V_50 )
F_42 ( V_37 ) ;
F_43 ( V_14 -> V_51 , V_37 ) ;
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
F_49 ( V_14 -> V_51 , NULL ) ;
F_20 ( V_37 ) ;
F_50 ( & V_46 , V_37 -> V_45 ) ;
F_51 ( V_14 ) ;
F_28 ( & V_37 -> V_29 , F_45 ) ;
}
int F_52 ( struct V_26 * V_37 , T_2 V_52 , T_2 V_53 )
{
F_10 () ;
F_53 (in_dev) {
if ( F_54 ( V_52 , V_7 ) ) {
if ( ! V_53 || F_54 ( V_53 , V_7 ) ) {
F_18 () ;
return 1 ;
}
}
} F_55 ( V_37 ) ;
F_18 () ;
return 0 ;
}
static void F_56 ( struct V_26 * V_37 , struct V_6 * * V_54 ,
int V_55 , struct V_56 * V_57 , T_1 V_58 )
{
struct V_6 * V_59 = NULL ;
struct V_6 * V_7 , * V_60 = * V_54 ;
struct V_6 * V_61 = V_37 -> V_31 ;
struct V_6 * V_62 = NULL ;
int V_63 = F_57 ( V_37 ) ;
F_5 () ;
if ( ! ( V_60 -> V_64 & V_65 ) ) {
struct V_6 * * V_66 = & V_60 -> V_67 ;
while ( ( V_7 = * V_66 ) != NULL ) {
if ( ! ( V_7 -> V_64 & V_65 ) &&
V_60 -> V_68 <= V_7 -> V_68 )
V_61 = V_7 ;
if ( ! ( V_7 -> V_64 & V_65 ) ||
V_60 -> V_69 != V_7 -> V_69 ||
! F_54 ( V_60 -> V_70 , V_7 ) ) {
V_66 = & V_7 -> V_67 ;
V_62 = V_7 ;
continue;
}
if ( ! V_63 ) {
F_7 ( V_7 ) ;
* V_66 = V_7 -> V_67 ;
F_58 ( V_71 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_72 ,
V_73 , V_7 ) ;
F_27 ( V_7 ) ;
} else {
V_59 = V_7 ;
break;
}
}
}
for ( V_7 = V_59 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_54 ( V_60 -> V_70 , V_7 ) )
F_60 ( V_7 , V_60 ) ;
}
* V_54 = V_60 -> V_67 ;
F_7 ( V_60 ) ;
F_58 ( V_71 , V_60 , V_57 , V_58 ) ;
F_59 ( & V_72 , V_73 , V_60 ) ;
if ( V_59 ) {
struct V_6 * V_74 = V_59 -> V_67 ;
if ( V_62 ) {
V_62 -> V_67 = V_59 -> V_67 ;
V_59 -> V_67 = V_61 -> V_67 ;
V_61 -> V_67 = V_59 ;
}
V_59 -> V_64 &= ~ V_65 ;
F_58 ( V_75 , V_59 , V_57 , V_58 ) ;
F_59 ( & V_72 ,
V_76 , V_59 ) ;
for ( V_7 = V_74 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 != V_7 -> V_69 ||
! F_54 ( V_60 -> V_70 , V_7 ) )
continue;
F_61 ( V_7 ) ;
}
}
if ( V_55 )
F_27 ( V_60 ) ;
}
static void F_48 ( struct V_26 * V_37 , struct V_6 * * V_54 ,
int V_55 )
{
F_56 ( V_37 , V_54 , V_55 , NULL , 0 ) ;
}
static int F_62 ( struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_60 , * * V_54 , * * V_77 ;
F_5 () ;
if ( ! V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return 0 ;
}
V_7 -> V_64 &= ~ V_65 ;
V_77 = & V_37 -> V_31 ;
for ( V_54 = & V_37 -> V_31 ; ( V_60 = * V_54 ) != NULL ;
V_54 = & V_60 -> V_67 ) {
if ( ! ( V_60 -> V_64 & V_65 ) &&
V_7 -> V_68 <= V_60 -> V_68 )
V_77 = & V_60 -> V_67 ;
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_54 ( V_60 -> V_70 , V_7 ) ) {
if ( V_60 -> V_9 == V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return - V_78 ;
}
if ( V_60 -> V_68 != V_7 -> V_68 ) {
F_27 ( V_7 ) ;
return - V_79 ;
}
V_7 -> V_64 |= V_65 ;
}
}
if ( ! ( V_7 -> V_64 & V_65 ) ) {
F_63 ( ( V_4 T_1 ) V_7 -> V_9 ) ;
V_54 = V_77 ;
}
V_7 -> V_67 = * V_54 ;
* V_54 = V_7 ;
F_4 ( F_13 ( V_37 -> V_14 ) , V_7 ) ;
F_64 ( & V_80 ) ;
F_65 ( V_81 , & V_80 , 0 ) ;
F_58 ( V_75 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_72 , V_76 , V_7 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
return F_62 ( V_7 , NULL , 0 ) ;
}
static int F_67 ( struct V_11 * V_14 , struct V_6 * V_7 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
F_27 ( V_7 ) ;
return - V_82 ;
}
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
if ( V_7 -> V_15 != V_37 ) {
F_30 ( V_7 -> V_15 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
}
if ( F_71 ( V_7 -> V_9 ) )
V_7 -> V_68 = V_83 ;
return F_66 ( V_7 ) ;
}
struct V_26 * F_72 ( struct V_1 * V_1 , int V_84 )
{
struct V_11 * V_14 ;
struct V_26 * V_37 = NULL ;
F_10 () ;
V_14 = F_73 ( V_1 , V_84 ) ;
if ( V_14 )
V_37 = F_74 ( V_14 -> V_51 ) ;
F_18 () ;
return V_37 ;
}
struct V_6 * F_75 ( struct V_26 * V_37 , T_2 V_85 ,
T_2 V_86 )
{
F_5 () ;
F_53 (in_dev) {
if ( V_7 -> V_69 == V_86 && F_54 ( V_85 , V_7 ) )
return V_7 ;
} F_55 ( V_37 ) ;
return NULL ;
}
static int F_76 ( struct V_87 * V_88 , bool V_89 , const struct V_6 * V_7 )
{
struct V_90 V_91 = {
. V_92 . V_93 = V_7 -> V_70 ,
. V_94 = V_7 -> V_15 -> V_14 -> V_84 ,
} ;
int V_95 ;
F_5 () ;
F_77 ( V_88 ) ;
if ( V_89 )
V_95 = F_78 ( V_88 , & V_91 ) ;
else
V_95 = F_79 ( V_88 , & V_91 ) ;
F_80 ( V_88 ) ;
return V_95 ;
}
static int F_81 ( struct V_96 * V_97 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_97 -> V_88 ) ;
struct V_98 * V_99 [ V_100 + 1 ] ;
struct V_26 * V_37 ;
struct V_101 * V_102 ;
struct V_6 * V_7 , * * V_54 ;
int V_38 = - V_79 ;
F_5 () ;
V_38 = F_83 ( V_57 , sizeof( * V_102 ) , V_99 , V_100 , V_103 ) ;
if ( V_38 < 0 )
goto V_104;
V_102 = F_84 ( V_57 ) ;
V_37 = F_72 ( V_1 , V_102 -> V_105 ) ;
if ( ! V_37 ) {
V_38 = - V_106 ;
goto V_104;
}
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( V_99 [ V_107 ] &&
V_7 -> V_9 != F_85 ( V_99 [ V_107 ] ) )
continue;
if ( V_99 [ V_108 ] && F_86 ( V_99 [ V_108 ] , V_7 -> V_109 ) )
continue;
if ( V_99 [ V_110 ] &&
( V_102 -> V_111 != V_7 -> V_111 ||
! F_54 ( F_85 ( V_99 [ V_110 ] ) , V_7 ) ) )
continue;
if ( F_87 ( V_7 -> V_70 ) )
F_76 ( V_1 -> V_42 . V_112 , false , V_7 ) ;
F_56 ( V_37 , V_54 , 1 , V_57 , F_88 ( V_97 ) . V_58 ) ;
return 0 ;
}
V_38 = - V_113 ;
V_104:
return V_38 ;
}
static void F_89 ( struct V_114 * V_115 )
{
unsigned long V_116 , V_117 , V_74 , V_118 ;
struct V_6 * V_7 ;
struct V_119 * V_120 ;
int V_121 ;
V_116 = V_122 ;
V_117 = F_90 ( V_116 + V_123 ) ;
for ( V_121 = 0 ; V_121 < V_124 ; V_121 ++ ) {
bool V_125 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_126 ;
if ( V_7 -> V_64 & V_127 )
continue;
V_126 = ( V_116 - V_7 -> V_128 +
V_129 ) / V_130 ;
if ( V_7 -> V_131 != V_132 &&
V_126 >= V_7 -> V_131 ) {
V_125 = true ;
} else if ( V_7 -> V_133 ==
V_132 ) {
continue;
} else if ( V_126 >= V_7 -> V_133 ) {
if ( F_91 ( V_7 -> V_128 +
V_7 -> V_131 * V_130 , V_117 ) )
V_117 = V_7 -> V_128 +
V_7 -> V_131 * V_130 ;
if ( ! ( V_7 -> V_64 & V_134 ) )
V_125 = true ;
} else if ( F_91 ( V_7 -> V_128 +
V_7 -> V_133 * V_130 ,
V_117 ) ) {
V_117 = V_7 -> V_128 +
V_7 -> V_133 * V_130 ;
}
}
F_18 () ;
if ( ! V_125 )
continue;
F_92 () ;
F_93 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_126 ;
if ( V_7 -> V_64 & V_127 )
continue;
V_126 = ( V_116 - V_7 -> V_128 +
V_129 ) / V_130 ;
if ( V_7 -> V_131 != V_132 &&
V_126 >= V_7 -> V_131 ) {
struct V_6 * * V_54 ;
for ( V_54 = & V_7 -> V_15 -> V_31 ;
* V_54 != NULL ; V_54 = & ( * V_54 ) -> V_67 ) {
if ( * V_54 == V_7 ) {
F_48 ( V_7 -> V_15 ,
V_54 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_133 !=
V_132 &&
V_126 >= V_7 -> V_133 &&
! ( V_7 -> V_64 & V_134 ) ) {
V_7 -> V_64 |= V_134 ;
F_58 ( V_75 , V_7 , NULL , 0 ) ;
}
}
F_94 () ;
}
V_74 = F_90 ( V_117 ) ;
V_118 = V_117 ;
if ( F_91 ( V_74 , V_117 + V_135 ) )
V_118 = V_74 ;
V_116 = V_122 ;
if ( F_91 ( V_118 , V_116 + V_136 ) )
V_118 = V_116 + V_136 ;
F_65 ( V_81 , & V_80 ,
V_118 - V_116 ) ;
}
static void F_95 ( struct V_6 * V_7 , T_3 V_137 ,
T_3 V_138 )
{
unsigned long V_139 ;
V_7 -> V_64 &= ~ ( V_127 | V_134 ) ;
V_139 = F_96 ( V_137 , V_130 ) ;
if ( F_97 ( V_139 ) )
V_7 -> V_131 = V_139 ;
else
V_7 -> V_64 |= V_127 ;
V_139 = F_96 ( V_138 , V_130 ) ;
if ( F_97 ( V_139 ) ) {
if ( V_139 == 0 )
V_7 -> V_64 |= V_134 ;
V_7 -> V_133 = V_139 ;
}
V_7 -> V_128 = V_122 ;
if ( ! V_7 -> V_140 )
V_7 -> V_140 = V_7 -> V_128 ;
}
static struct V_6 * F_98 ( struct V_1 * V_1 , struct V_56 * V_57 ,
T_3 * V_141 , T_3 * V_142 )
{
struct V_98 * V_99 [ V_100 + 1 ] ;
struct V_6 * V_7 ;
struct V_101 * V_102 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_102 ) , V_99 , V_100 , V_103 ) ;
if ( V_38 < 0 )
goto V_104;
V_102 = F_84 ( V_57 ) ;
V_38 = - V_79 ;
if ( V_102 -> V_111 > 32 || ! V_99 [ V_107 ] )
goto V_104;
V_14 = F_99 ( V_1 , V_102 -> V_105 ) ;
V_38 = - V_106 ;
if ( ! V_14 )
goto V_104;
V_37 = F_68 ( V_14 ) ;
V_38 = - V_82 ;
if ( ! V_37 )
goto V_104;
V_7 = F_21 () ;
if ( ! V_7 )
goto V_104;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_40 ( V_37 ) ;
if ( ! V_99 [ V_110 ] )
V_99 [ V_110 ] = V_99 [ V_107 ] ;
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_111 = V_102 -> V_111 ;
V_7 -> V_69 = F_101 ( V_102 -> V_111 ) ;
V_7 -> V_64 = V_99 [ V_143 ] ? F_102 ( V_99 [ V_143 ] ) :
V_102 -> V_64 ;
V_7 -> V_68 = V_102 -> V_68 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_85 ( V_99 [ V_107 ] ) ;
V_7 -> V_70 = F_85 ( V_99 [ V_110 ] ) ;
if ( V_99 [ V_144 ] )
V_7 -> V_145 = F_85 ( V_99 [ V_144 ] ) ;
if ( V_99 [ V_108 ] )
F_103 ( V_7 -> V_109 , V_99 [ V_108 ] , V_146 ) ;
else
memcpy ( V_7 -> V_109 , V_14 -> V_35 , V_146 ) ;
if ( V_99 [ V_147 ] ) {
struct V_148 * V_149 ;
V_149 = F_104 ( V_99 [ V_147 ] ) ;
if ( ! V_149 -> V_150 || V_149 -> V_151 > V_149 -> V_150 ) {
V_38 = - V_79 ;
goto V_152;
}
* V_141 = V_149 -> V_150 ;
* V_142 = V_149 -> V_151 ;
}
return V_7 ;
V_152:
F_27 ( V_7 ) ;
V_104:
return F_44 ( V_38 ) ;
}
static struct V_6 * F_105 ( struct V_6 * V_7 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_60 , * * V_54 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_54 = & V_37 -> V_31 ; ( V_60 = * V_54 ) != NULL ;
V_54 = & V_60 -> V_67 ) {
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_54 ( V_60 -> V_70 , V_7 ) &&
V_60 -> V_9 == V_7 -> V_9 )
return V_60 ;
}
return NULL ;
}
static int F_106 ( struct V_96 * V_97 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_97 -> V_88 ) ;
struct V_6 * V_7 ;
struct V_6 * V_153 ;
T_3 V_137 = V_132 ;
T_3 V_138 = V_132 ;
F_5 () ;
V_7 = F_98 ( V_1 , V_57 , & V_137 , & V_138 ) ;
if ( F_107 ( V_7 ) )
return F_108 ( V_7 ) ;
V_153 = F_105 ( V_7 ) ;
if ( ! V_153 ) {
F_95 ( V_7 , V_137 , V_138 ) ;
if ( V_7 -> V_64 & V_154 ) {
int V_95 = F_76 ( V_1 -> V_42 . V_112 ,
true , V_7 ) ;
if ( V_95 < 0 ) {
F_27 ( V_7 ) ;
return V_95 ;
}
}
return F_62 ( V_7 , V_57 , F_88 ( V_97 ) . V_58 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_57 -> V_155 & V_156 ||
! ( V_57 -> V_155 & V_157 ) )
return - V_78 ;
V_7 = V_153 ;
F_95 ( V_7 , V_137 , V_138 ) ;
F_64 ( & V_80 ) ;
F_65 ( V_81 ,
& V_80 , 0 ) ;
F_58 ( V_75 , V_7 , V_57 , F_88 ( V_97 ) . V_58 ) ;
}
return 0 ;
}
static int F_109 ( T_2 V_2 )
{
int V_158 = - 1 ;
if ( F_110 ( V_2 ) )
V_158 = 0 ;
else {
T_3 V_159 = F_111 ( V_2 ) ;
if ( F_112 ( V_159 ) )
V_158 = 8 ;
else if ( F_113 ( V_159 ) )
V_158 = 16 ;
else if ( F_114 ( V_159 ) )
V_158 = 24 ;
}
return V_158 ;
}
int F_115 ( struct V_1 * V_1 , unsigned int V_160 , void T_4 * V_161 )
{
struct V_162 V_163 ;
struct V_164 V_165 ;
struct V_164 * sin = (struct V_164 * ) & V_163 . V_166 ;
struct V_26 * V_37 ;
struct V_6 * * V_54 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_167 ;
int V_95 = - V_168 ;
int V_169 = 0 ;
if ( F_116 ( & V_163 , V_161 , sizeof( struct V_162 ) ) )
goto V_40;
V_163 . V_170 [ V_146 - 1 ] = 0 ;
memcpy ( & V_165 , sin , sizeof( * sin ) ) ;
V_167 = strchr ( V_163 . V_170 , ':' ) ;
if ( V_167 )
* V_167 = 0 ;
F_117 ( V_1 , V_163 . V_170 ) ;
switch ( V_160 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_169 = ( V_165 . V_175 == V_176 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_175 = V_176 ;
break;
case V_177 :
V_95 = - V_178 ;
if ( ! F_118 ( V_1 -> V_179 , V_180 ) )
goto V_40;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
V_95 = - V_178 ;
if ( ! F_118 ( V_1 -> V_179 , V_180 ) )
goto V_40;
V_95 = - V_79 ;
if ( sin -> V_175 != V_176 )
goto V_40;
break;
default:
V_95 = - V_79 ;
goto V_40;
}
F_92 () ;
V_95 = - V_106 ;
V_14 = F_119 ( V_1 , V_163 . V_170 ) ;
if ( ! V_14 )
goto V_185;
if ( V_167 )
* V_167 = ':' ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
if ( V_169 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( ! strcmp ( V_163 . V_170 , V_7 -> V_109 ) &&
V_165 . V_186 . V_93 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 )
if ( ! strcmp ( V_163 . V_170 , V_7 -> V_109 ) )
break;
}
}
V_95 = - V_113 ;
if ( ! V_7 && V_160 != V_181 && V_160 != V_177 )
goto V_185;
switch ( V_160 ) {
case V_171 :
sin -> V_186 . V_93 = V_7 -> V_9 ;
goto V_187;
case V_172 :
sin -> V_186 . V_93 = V_7 -> V_145 ;
goto V_187;
case V_173 :
sin -> V_186 . V_93 = V_7 -> V_70 ;
goto V_187;
case V_174 :
sin -> V_186 . V_93 = V_7 -> V_69 ;
goto V_187;
case V_177 :
if ( V_167 ) {
V_95 = - V_113 ;
if ( ! V_7 )
break;
V_95 = 0 ;
if ( ! ( V_163 . V_188 & V_50 ) )
F_48 ( V_37 , V_54 , 1 ) ;
break;
}
V_95 = F_120 ( V_14 , V_163 . V_188 ) ;
break;
case V_181 :
V_95 = - V_79 ;
if ( F_109 ( sin -> V_186 . V_93 ) < 0 )
break;
if ( ! V_7 ) {
V_95 = - V_82 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_100 ( & V_7 -> V_8 ) ;
if ( V_167 )
memcpy ( V_7 -> V_109 , V_163 . V_170 , V_146 ) ;
else
memcpy ( V_7 -> V_109 , V_14 -> V_35 , V_146 ) ;
} else {
V_95 = 0 ;
if ( V_7 -> V_9 == sin -> V_186 . V_93 )
break;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_145 = 0 ;
V_7 -> V_68 = 0 ;
}
V_7 -> V_70 = V_7 -> V_9 = sin -> V_186 . V_93 ;
if ( ! ( V_14 -> V_49 & V_189 ) ) {
V_7 -> V_111 = F_109 ( V_7 -> V_70 ) ;
V_7 -> V_69 = F_101 ( V_7 -> V_111 ) ;
if ( ( V_14 -> V_49 & V_190 ) &&
V_7 -> V_111 < 31 )
V_7 -> V_145 = V_7 -> V_70 |
~ V_7 -> V_69 ;
} else {
V_7 -> V_111 = 32 ;
V_7 -> V_69 = F_101 ( 32 ) ;
}
F_95 ( V_7 , V_132 , V_132 ) ;
V_95 = F_67 ( V_14 , V_7 ) ;
break;
case V_182 :
V_95 = 0 ;
if ( V_7 -> V_145 != sin -> V_186 . V_93 ) {
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_145 = sin -> V_186 . V_93 ;
F_66 ( V_7 ) ;
}
break;
case V_183 :
V_95 = 0 ;
if ( V_7 -> V_70 == sin -> V_186 . V_93 )
break;
V_95 = - V_79 ;
if ( F_109 ( sin -> V_186 . V_93 ) < 0 )
break;
V_95 = 0 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_186 . V_93 ;
F_66 ( V_7 ) ;
break;
case V_184 :
V_95 = - V_79 ;
if ( F_121 ( sin -> V_186 . V_93 , 0 ) )
break;
V_95 = 0 ;
if ( V_7 -> V_69 != sin -> V_186 . V_93 ) {
T_2 V_191 = V_7 -> V_69 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_69 = sin -> V_186 . V_93 ;
V_7 -> V_111 = F_122 ( V_7 -> V_69 ) ;
if ( ( V_14 -> V_49 & V_190 ) &&
( V_7 -> V_111 < 31 ) &&
( V_7 -> V_145 ==
( V_7 -> V_9 | ~ V_191 ) ) ) {
V_7 -> V_145 = ( V_7 -> V_9 |
~ sin -> V_186 . V_93 ) ;
}
F_66 ( V_7 ) ;
}
break;
}
V_185:
F_94 () ;
V_40:
return V_95 ;
V_187:
F_94 () ;
V_95 = F_123 ( V_161 , & V_163 , sizeof( struct V_162 ) ) ? - V_168 : 0 ;
goto V_40;
}
static int F_124 ( struct V_11 * V_14 , char T_4 * V_192 , int V_193 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_162 V_163 ;
int V_185 = 0 ;
if ( ! V_37 )
goto V_40;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( ! V_192 ) {
V_185 += sizeof( V_163 ) ;
continue;
}
if ( V_193 < ( int ) sizeof( V_163 ) )
break;
memset ( & V_163 , 0 , sizeof( struct V_162 ) ) ;
strcpy ( V_163 . V_170 , V_7 -> V_109 ) ;
( * (struct V_164 * ) & V_163 . V_166 ) . V_175 = V_176 ;
( * (struct V_164 * ) & V_163 . V_166 ) . V_186 . V_93 =
V_7 -> V_9 ;
if ( F_123 ( V_192 , & V_163 , sizeof( struct V_162 ) ) ) {
V_185 = - V_168 ;
break;
}
V_192 += sizeof( struct V_162 ) ;
V_193 -= sizeof( struct V_162 ) ;
V_185 += sizeof( struct V_162 ) ;
}
V_40:
return V_185 ;
}
T_2 F_125 ( const struct V_11 * V_14 , T_2 V_194 , int V_195 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
F_10 () ;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_196;
F_53 (in_dev) {
if ( V_7 -> V_68 > V_195 )
continue;
if ( ! V_194 || F_54 ( V_194 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_197;
V_196:
F_127 (net, dev) {
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
continue;
F_53 (in_dev) {
if ( V_7 -> V_68 != V_198 &&
V_7 -> V_68 <= V_195 ) {
V_2 = V_7 -> V_9 ;
goto V_197;
}
} F_55 ( V_37 ) ;
}
V_197:
F_18 () ;
return V_2 ;
}
static T_2 F_128 ( struct V_26 * V_37 , T_2 V_194 ,
T_2 V_22 , int V_195 )
{
int V_199 = 0 ;
T_2 V_2 = 0 ;
F_129 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_68 <= V_195 ) {
V_2 = V_7 -> V_9 ;
if ( V_199 )
break;
}
if ( ! V_199 ) {
V_199 = ( ! V_22 || F_54 ( V_22 , V_7 ) ) &&
( ! V_194 || F_54 ( V_194 , V_7 ) ) ;
if ( V_199 && V_2 ) {
if ( V_22 || ! V_194 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_68 <= V_195 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_199 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_199 ? V_2 : 0 ;
}
T_2 F_130 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_194 , T_2 V_22 , int V_195 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 )
return F_128 ( V_37 , V_194 , V_22 , V_195 ) ;
F_10 () ;
F_127 (net, dev) {
V_37 = F_126 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_128 ( V_37 , V_194 , V_22 , V_195 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_131 ( struct V_200 * V_201 )
{
return F_132 ( & V_72 , V_201 ) ;
}
int F_133 ( struct V_200 * V_201 )
{
return F_134 ( & V_72 , V_201 ) ;
}
static void F_135 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_202 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_67 ) {
char V_203 [ V_146 ] , * V_204 ;
memcpy ( V_203 , V_7 -> V_109 , V_146 ) ;
memcpy ( V_7 -> V_109 , V_14 -> V_35 , V_146 ) ;
if ( V_202 ++ == 0 )
goto V_205;
V_204 = strchr ( V_203 , ':' ) ;
if ( ! V_204 ) {
sprintf ( V_203 , L_4 , V_202 ) ;
V_204 = V_203 ;
}
if ( strlen ( V_204 ) + strlen ( V_14 -> V_35 ) < V_146 )
strcat ( V_7 -> V_109 , V_204 ) ;
else
strcpy ( V_7 -> V_109 + ( V_146 - strlen ( V_204 ) - 1 ) , V_204 ) ;
V_205:
F_58 ( V_75 , V_7 , NULL , 0 ) ;
}
}
static bool F_136 ( unsigned int V_206 )
{
return V_206 >= 68 ;
}
static void F_137 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_67 ) {
F_138 ( V_207 , V_208 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_209 , NULL ) ;
}
}
static int F_139 ( struct V_200 * V_210 , unsigned long V_211 ,
void * V_212 )
{
struct V_11 * V_14 = F_140 ( V_212 ) ;
struct V_26 * V_37 = F_68 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_211 == V_213 ) {
V_37 = F_36 ( V_14 ) ;
if ( F_107 ( V_37 ) )
return F_141 ( F_108 ( V_37 ) ) ;
if ( V_14 -> V_49 & V_214 ) {
F_142 ( V_37 , V_215 , 1 ) ;
F_142 ( V_37 , V_216 , 1 ) ;
}
} else if ( V_211 == V_217 ) {
if ( F_136 ( V_14 -> V_206 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_40;
}
switch ( V_211 ) {
case V_213 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_14 -> V_51 , NULL ) ;
break;
case V_76 :
if ( ! F_136 ( V_14 -> V_206 ) )
break;
if ( V_14 -> V_49 & V_214 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_70 = F_143 ( V_218 ) ;
V_7 -> V_111 = 8 ;
V_7 -> V_69 = F_101 ( 8 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_68 = V_83 ;
memcpy ( V_7 -> V_109 , V_14 -> V_35 , V_146 ) ;
F_95 ( V_7 , V_132 ,
V_132 ) ;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_66 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_219 :
if ( ! F_144 ( V_37 ) )
break;
case V_220 :
F_137 ( V_14 , V_37 ) ;
break;
case V_73 :
F_145 ( V_37 ) ;
break;
case V_221 :
F_146 ( V_37 ) ;
break;
case V_222 :
F_147 ( V_37 ) ;
break;
case V_217 :
if ( F_136 ( V_14 -> V_206 ) )
break;
case V_223 :
F_46 ( V_37 ) ;
break;
case V_224 :
F_135 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_40:
return V_225 ;
}
static T_5 F_148 ( void )
{
return F_149 ( sizeof( struct V_101 ) )
+ F_150 ( 4 )
+ F_150 ( 4 )
+ F_150 ( 4 )
+ F_150 ( V_146 )
+ F_150 ( 4 )
+ F_150 ( sizeof( struct V_148 ) ) ;
}
static inline T_1 F_151 ( unsigned long V_226 )
{
return ( V_226 - V_227 ) * 100UL / V_130 ;
}
static int F_152 ( struct V_96 * V_97 , unsigned long V_226 ,
unsigned long V_228 , T_1 V_229 , T_1 V_230 )
{
struct V_148 V_149 ;
V_149 . V_226 = F_151 ( V_226 ) ;
V_149 . V_228 = F_151 ( V_228 ) ;
V_149 . V_151 = V_229 ;
V_149 . V_150 = V_230 ;
return F_153 ( V_97 , V_147 , sizeof( V_149 ) , & V_149 ) ;
}
static int F_154 ( struct V_96 * V_97 , struct V_6 * V_7 ,
T_1 V_58 , T_1 V_231 , int V_211 , unsigned int V_49 )
{
struct V_101 * V_102 ;
struct V_56 * V_57 ;
T_1 V_229 , V_230 ;
V_57 = F_155 ( V_97 , V_58 , V_231 , V_211 , sizeof( * V_102 ) , V_49 ) ;
if ( ! V_57 )
return - V_232 ;
V_102 = F_84 ( V_57 ) ;
V_102 -> V_233 = V_176 ;
V_102 -> V_111 = V_7 -> V_111 ;
V_102 -> V_64 = V_7 -> V_64 ;
V_102 -> V_68 = V_7 -> V_68 ;
V_102 -> V_105 = V_7 -> V_15 -> V_14 -> V_84 ;
if ( ! ( V_102 -> V_64 & V_127 ) ) {
V_229 = V_7 -> V_133 ;
V_230 = V_7 -> V_131 ;
if ( V_229 != V_132 ) {
long V_234 = ( V_122 - V_7 -> V_128 ) / V_130 ;
if ( V_229 > V_234 )
V_229 -= V_234 ;
else
V_229 = 0 ;
if ( V_230 != V_132 ) {
if ( V_230 > V_234 )
V_230 -= V_234 ;
else
V_230 = 0 ;
}
}
} else {
V_229 = V_132 ;
V_230 = V_132 ;
}
if ( ( V_7 -> V_70 &&
F_156 ( V_97 , V_110 , V_7 -> V_70 ) ) ||
( V_7 -> V_9 &&
F_156 ( V_97 , V_107 , V_7 -> V_9 ) ) ||
( V_7 -> V_145 &&
F_156 ( V_97 , V_144 , V_7 -> V_145 ) ) ||
( V_7 -> V_109 [ 0 ] &&
F_157 ( V_97 , V_108 , V_7 -> V_109 ) ) ||
F_158 ( V_97 , V_143 , V_7 -> V_64 ) ||
F_152 ( V_97 , V_7 -> V_140 , V_7 -> V_128 ,
V_229 , V_230 ) )
goto V_235;
F_159 ( V_97 , V_57 ) ;
return 0 ;
V_235:
F_160 ( V_97 , V_57 ) ;
return - V_232 ;
}
static int F_161 ( struct V_96 * V_97 , struct V_236 * V_237 )
{
struct V_1 * V_1 = F_82 ( V_97 -> V_88 ) ;
int V_238 , V_239 ;
int V_240 , V_241 ;
int V_242 , V_243 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_6 * V_7 ;
struct V_244 * V_30 ;
V_239 = V_237 -> args [ 0 ] ;
V_241 = V_240 = V_237 -> args [ 1 ] ;
V_243 = V_242 = V_237 -> args [ 2 ] ;
for ( V_238 = V_239 ; V_238 < V_245 ; V_238 ++ , V_241 = 0 ) {
V_240 = 0 ;
V_30 = & V_1 -> V_246 [ V_238 ] ;
F_10 () ;
V_237 -> V_231 = F_162 ( & V_1 -> V_42 . V_247 ) ^
V_1 -> V_248 ;
F_11 (dev, head, index_hlist) {
if ( V_240 < V_241 )
goto V_249;
if ( V_238 > V_239 || V_240 > V_241 )
V_243 = 0 ;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_249;
for ( V_7 = V_37 -> V_31 , V_242 = 0 ; V_7 ;
V_7 = V_7 -> V_67 , V_242 ++ ) {
if ( V_242 < V_243 )
continue;
if ( F_154 ( V_97 , V_7 ,
F_88 ( V_237 -> V_97 ) . V_58 ,
V_237 -> V_57 -> V_250 ,
V_75 , V_251 ) < 0 ) {
F_18 () ;
goto V_185;
}
F_163 ( V_237 , F_164 ( V_97 ) ) ;
}
V_249:
V_240 ++ ;
}
F_18 () ;
}
V_185:
V_237 -> args [ 0 ] = V_238 ;
V_237 -> args [ 1 ] = V_240 ;
V_237 -> args [ 2 ] = V_242 ;
return V_97 -> V_193 ;
}
static void F_58 ( int V_211 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_96 * V_97 ;
T_1 V_231 = V_57 ? V_57 -> V_250 : 0 ;
int V_38 = - V_82 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_97 = F_165 ( F_148 () , V_28 ) ;
if ( ! V_97 )
goto V_104;
V_38 = F_154 ( V_97 , V_7 , V_58 , V_231 , V_211 , 0 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_232 ) ;
F_166 ( V_97 ) ;
goto V_104;
}
F_167 ( V_97 , V_1 , V_58 , V_252 , V_57 , V_28 ) ;
return;
V_104:
if ( V_38 < 0 )
F_168 ( V_1 , V_252 , V_38 ) ;
}
static T_5 F_169 ( const struct V_11 * V_14 ,
T_1 V_253 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
if ( ! V_37 )
return 0 ;
return F_150 ( V_254 * 4 ) ;
}
static int F_170 ( struct V_96 * V_97 , const struct V_11 * V_14 ,
T_1 V_253 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
struct V_98 * V_255 ;
int V_121 ;
if ( ! V_37 )
return - V_256 ;
V_255 = F_171 ( V_97 , V_257 , V_254 * 4 ) ;
if ( ! V_255 )
return - V_232 ;
for ( V_121 = 0 ; V_121 < V_254 ; V_121 ++ )
( ( T_1 * ) F_104 ( V_255 ) ) [ V_121 ] = V_37 -> V_41 . V_258 [ V_121 ] ;
return 0 ;
}
static int F_172 ( const struct V_11 * V_14 ,
const struct V_98 * V_255 )
{
struct V_98 * V_52 , * V_99 [ V_259 + 1 ] ;
int V_38 , V_260 ;
if ( V_14 && ! F_68 ( V_14 ) )
return - V_261 ;
V_38 = F_173 ( V_99 , V_259 , V_255 , V_262 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_99 [ V_257 ] ) {
F_174 (a, tb[IFLA_INET_CONF], rem) {
int V_263 = F_175 ( V_52 ) ;
if ( F_176 ( V_52 ) < 4 )
return - V_79 ;
if ( V_263 <= 0 || V_263 > V_254 )
return - V_79 ;
}
}
return 0 ;
}
static int F_177 ( struct V_11 * V_14 , const struct V_98 * V_255 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_98 * V_52 , * V_99 [ V_259 + 1 ] ;
int V_260 ;
if ( ! V_37 )
return - V_261 ;
if ( F_173 ( V_99 , V_259 , V_255 , NULL ) < 0 )
F_178 () ;
if ( V_99 [ V_257 ] ) {
F_174 (a, tb[IFLA_INET_CONF], rem)
F_179 ( V_37 , F_175 ( V_52 ) , F_102 ( V_52 ) ) ;
}
return 0 ;
}
static int F_180 ( int type )
{
int V_264 = F_149 ( sizeof( struct V_265 ) )
+ F_150 ( 4 ) ;
if ( type == - 1 || type == V_266 )
V_264 += F_150 ( 4 ) ;
if ( type == - 1 || type == V_267 )
V_264 += F_150 ( 4 ) ;
if ( type == - 1 || type == V_268 )
V_264 += F_150 ( 4 ) ;
if ( type == - 1 || type == V_269 )
V_264 += F_150 ( 4 ) ;
if ( type == - 1 || type == V_270 )
V_264 += F_150 ( 4 ) ;
return V_264 ;
}
static int F_181 ( struct V_96 * V_97 , int V_84 ,
struct V_271 * V_272 , T_1 V_58 ,
T_1 V_231 , int V_211 , unsigned int V_49 ,
int type )
{
struct V_56 * V_57 ;
struct V_265 * V_273 ;
V_57 = F_155 ( V_97 , V_58 , V_231 , V_211 , sizeof( struct V_265 ) ,
V_49 ) ;
if ( ! V_57 )
return - V_232 ;
V_273 = F_84 ( V_57 ) ;
V_273 -> V_274 = V_176 ;
if ( F_182 ( V_97 , V_275 , V_84 ) < 0 )
goto V_235;
if ( ( type == - 1 || type == V_266 ) &&
F_182 ( V_97 , V_266 ,
F_38 ( * V_272 , V_48 ) ) < 0 )
goto V_235;
if ( ( type == - 1 || type == V_267 ) &&
F_182 ( V_97 , V_267 ,
F_38 ( * V_272 , V_276 ) ) < 0 )
goto V_235;
if ( ( type == - 1 || type == V_268 ) &&
F_182 ( V_97 , V_268 ,
F_38 ( * V_272 , V_277 ) ) < 0 )
goto V_235;
if ( ( type == - 1 || type == V_269 ) &&
F_182 ( V_97 , V_269 ,
F_38 ( * V_272 , V_278 ) ) < 0 )
goto V_235;
if ( ( type == - 1 || type == V_270 ) &&
F_182 ( V_97 , V_270 ,
F_38 ( * V_272 , V_279 ) ) < 0 )
goto V_235;
F_159 ( V_97 , V_57 ) ;
return 0 ;
V_235:
F_160 ( V_97 , V_57 ) ;
return - V_232 ;
}
void F_183 ( struct V_1 * V_1 , int type , int V_84 ,
struct V_271 * V_272 )
{
struct V_96 * V_97 ;
int V_38 = - V_82 ;
V_97 = F_165 ( F_180 ( type ) , V_280 ) ;
if ( ! V_97 )
goto V_104;
V_38 = F_181 ( V_97 , V_84 , V_272 , 0 , 0 ,
V_281 , 0 , type ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_232 ) ;
F_166 ( V_97 ) ;
goto V_104;
}
F_167 ( V_97 , V_1 , 0 , V_282 , NULL , V_280 ) ;
return;
V_104:
if ( V_38 < 0 )
F_168 ( V_1 , V_282 , V_38 ) ;
}
static int F_184 ( struct V_96 * V_283 ,
struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_283 -> V_88 ) ;
struct V_98 * V_99 [ V_284 + 1 ] ;
struct V_265 * V_273 ;
struct V_96 * V_97 ;
struct V_271 * V_272 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_84 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_273 ) , V_99 , V_284 ,
V_285 ) ;
if ( V_38 < 0 )
goto V_104;
V_38 = - V_79 ;
if ( ! V_99 [ V_275 ] )
goto V_104;
V_84 = F_185 ( V_99 [ V_275 ] ) ;
switch ( V_84 ) {
case V_286 :
V_272 = V_1 -> V_42 . V_287 ;
break;
case V_288 :
V_272 = V_1 -> V_42 . V_43 ;
break;
default:
V_14 = F_99 ( V_1 , V_84 ) ;
if ( ! V_14 )
goto V_104;
V_37 = F_68 ( V_14 ) ;
if ( ! V_37 )
goto V_104;
V_272 = & V_37 -> V_41 ;
break;
}
V_38 = - V_82 ;
V_97 = F_165 ( F_180 ( - 1 ) , V_280 ) ;
if ( ! V_97 )
goto V_104;
V_38 = F_181 ( V_97 , V_84 , V_272 ,
F_88 ( V_283 ) . V_58 ,
V_57 -> V_250 , V_281 , 0 ,
- 1 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_232 ) ;
F_166 ( V_97 ) ;
goto V_104;
}
V_38 = F_186 ( V_97 , V_1 , F_88 ( V_283 ) . V_58 ) ;
V_104:
return V_38 ;
}
static int F_187 ( struct V_96 * V_97 ,
struct V_236 * V_237 )
{
struct V_1 * V_1 = F_82 ( V_97 -> V_88 ) ;
int V_238 , V_239 ;
int V_240 , V_241 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_244 * V_30 ;
V_239 = V_237 -> args [ 0 ] ;
V_241 = V_240 = V_237 -> args [ 1 ] ;
for ( V_238 = V_239 ; V_238 < V_245 ; V_238 ++ , V_241 = 0 ) {
V_240 = 0 ;
V_30 = & V_1 -> V_246 [ V_238 ] ;
F_10 () ;
V_237 -> V_231 = F_162 ( & V_1 -> V_42 . V_247 ) ^
V_1 -> V_248 ;
F_11 (dev, head, index_hlist) {
if ( V_240 < V_241 )
goto V_249;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_249;
if ( F_181 ( V_97 , V_14 -> V_84 ,
& V_37 -> V_41 ,
F_88 ( V_237 -> V_97 ) . V_58 ,
V_237 -> V_57 -> V_250 ,
V_281 ,
V_251 ,
- 1 ) < 0 ) {
F_18 () ;
goto V_185;
}
F_163 ( V_237 , F_164 ( V_97 ) ) ;
V_249:
V_240 ++ ;
}
F_18 () ;
}
if ( V_238 == V_245 ) {
if ( F_181 ( V_97 , V_286 ,
V_1 -> V_42 . V_287 ,
F_88 ( V_237 -> V_97 ) . V_58 ,
V_237 -> V_57 -> V_250 ,
V_281 , V_251 ,
- 1 ) < 0 )
goto V_185;
else
V_238 ++ ;
}
if ( V_238 == V_245 + 1 ) {
if ( F_181 ( V_97 , V_288 ,
V_1 -> V_42 . V_43 ,
F_88 ( V_237 -> V_97 ) . V_58 ,
V_237 -> V_57 -> V_250 ,
V_281 , V_251 ,
- 1 ) < 0 )
goto V_185;
else
V_238 ++ ;
}
V_185:
V_237 -> args [ 0 ] = V_238 ;
V_237 -> args [ 1 ] = V_240 ;
return V_97 -> V_193 ;
}
static void F_188 ( struct V_1 * V_1 , int V_121 )
{
struct V_11 * V_14 ;
F_10 () ;
F_127 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_126 ( V_14 ) ;
if ( V_37 && ! F_189 ( V_121 , V_37 -> V_41 . V_289 ) )
V_37 -> V_41 . V_258 [ V_121 ] = V_1 -> V_42 . V_43 -> V_258 [ V_121 ] ;
}
F_18 () ;
}
static void F_190 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_290 = F_191 ( V_1 , V_48 ) ;
F_191 ( V_1 , V_291 ) = ! V_290 ;
F_192 ( V_1 , V_48 ) = V_290 ;
F_183 ( V_1 , V_266 ,
V_286 ,
V_1 -> V_42 . V_287 ) ;
F_183 ( V_1 , V_266 ,
V_288 ,
V_1 -> V_42 . V_43 ) ;
F_193 (net, dev) {
struct V_26 * V_37 ;
if ( V_290 )
F_39 ( V_14 ) ;
F_10 () ;
V_37 = F_126 ( V_14 ) ;
if ( V_37 ) {
F_142 ( V_37 , V_48 , V_290 ) ;
F_183 ( V_1 , V_266 ,
V_14 -> V_84 , & V_37 -> V_41 ) ;
}
F_18 () ;
}
}
static int F_194 ( struct V_1 * V_1 , struct V_271 * V_41 )
{
if ( V_41 == V_1 -> V_42 . V_43 )
return V_288 ;
else if ( V_41 == V_1 -> V_42 . V_287 )
return V_286 ;
else {
struct V_26 * V_27
= F_24 ( V_41 , struct V_26 , V_41 ) ;
return V_27 -> V_14 -> V_84 ;
}
}
static int F_195 ( struct V_292 * V_293 , int V_294 ,
void T_4 * V_295 ,
T_5 * V_296 , T_6 * V_297 )
{
int V_298 = * ( int * ) V_293 -> V_258 ;
int V_95 = F_196 ( V_293 , V_294 , V_295 , V_296 , V_297 ) ;
int V_299 = * ( int * ) V_293 -> V_258 ;
if ( V_294 ) {
struct V_271 * V_41 = V_293 -> V_300 ;
struct V_1 * V_1 = V_293 -> V_301 ;
int V_121 = ( int * ) V_293 -> V_258 - V_41 -> V_258 ;
int V_84 ;
F_197 ( V_121 , V_41 -> V_289 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_188 ( V_1 , V_121 ) ;
if ( V_121 == V_302 - 1 ||
V_121 == V_303 - 1 )
if ( ( V_299 == 0 ) && ( V_298 != 0 ) )
F_198 ( V_1 ) ;
if ( V_121 == V_304 - 1 &&
V_299 != V_298 ) {
V_84 = F_194 ( V_1 , V_41 ) ;
F_183 ( V_1 , V_267 ,
V_84 , V_41 ) ;
}
if ( V_121 == V_305 - 1 &&
V_299 != V_298 ) {
V_84 = F_194 ( V_1 , V_41 ) ;
F_183 ( V_1 , V_269 ,
V_84 , V_41 ) ;
}
if ( V_121 == V_306 - 1 &&
V_299 != V_298 ) {
V_84 = F_194 ( V_1 , V_41 ) ;
F_183 ( V_1 , V_270 ,
V_84 , V_41 ) ;
}
}
return V_95 ;
}
static int F_199 ( struct V_292 * V_293 , int V_294 ,
void T_4 * V_295 ,
T_5 * V_296 , T_6 * V_297 )
{
int * V_307 = V_293 -> V_258 ;
int V_3 = * V_307 ;
T_6 V_308 = * V_297 ;
int V_95 = F_196 ( V_293 , V_294 , V_295 , V_296 , V_297 ) ;
if ( V_294 && * V_307 != V_3 ) {
struct V_1 * V_1 = V_293 -> V_301 ;
if ( V_307 != & F_192 ( V_1 , V_48 ) ) {
if ( ! F_200 () ) {
* V_307 = V_3 ;
* V_297 = V_308 ;
return F_201 () ;
}
if ( V_307 == & F_191 ( V_1 , V_48 ) ) {
F_190 ( V_1 ) ;
} else {
struct V_271 * V_41 = V_293 -> V_300 ;
struct V_26 * V_27 =
F_24 ( V_41 , struct V_26 , V_41 ) ;
if ( * V_307 )
F_39 ( V_27 -> V_14 ) ;
F_183 ( V_1 ,
V_266 ,
V_27 -> V_14 -> V_84 ,
V_41 ) ;
}
F_94 () ;
F_198 ( V_1 ) ;
} else
F_183 ( V_1 , V_266 ,
V_288 ,
V_1 -> V_42 . V_43 ) ;
}
return V_95 ;
}
static int F_202 ( struct V_292 * V_293 , int V_294 ,
void T_4 * V_295 ,
T_5 * V_296 , T_6 * V_297 )
{
int * V_307 = V_293 -> V_258 ;
int V_3 = * V_307 ;
int V_95 = F_196 ( V_293 , V_294 , V_295 , V_296 , V_297 ) ;
struct V_1 * V_1 = V_293 -> V_301 ;
if ( V_294 && * V_307 != V_3 )
F_198 ( V_1 ) ;
return V_95 ;
}
static int F_203 ( struct V_1 * V_1 , char * V_309 ,
struct V_271 * V_310 )
{
int V_121 ;
struct V_311 * V_312 ;
char V_313 [ sizeof( L_6 ) + V_146 ] ;
V_312 = F_204 ( & V_314 , sizeof( * V_312 ) , V_28 ) ;
if ( ! V_312 )
goto V_40;
for ( V_121 = 0 ; V_121 < F_205 ( V_312 -> V_315 ) - 1 ; V_121 ++ ) {
V_312 -> V_315 [ V_121 ] . V_258 += ( char * ) V_310 - ( char * ) & V_271 ;
V_312 -> V_315 [ V_121 ] . V_300 = V_310 ;
V_312 -> V_315 [ V_121 ] . V_301 = V_1 ;
}
snprintf ( V_313 , sizeof( V_313 ) , L_7 , V_309 ) ;
V_312 -> V_316 = F_206 ( V_1 , V_313 , V_312 -> V_315 ) ;
if ( ! V_312 -> V_316 )
goto free;
V_310 -> V_44 = V_312 ;
return 0 ;
free:
F_26 ( V_312 ) ;
V_40:
return - V_82 ;
}
static void F_207 ( struct V_271 * V_41 )
{
struct V_311 * V_312 = V_41 -> V_44 ;
if ( ! V_312 )
return;
V_41 -> V_44 = NULL ;
F_208 ( V_312 -> V_316 ) ;
F_26 ( V_312 ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
int V_38 ;
if ( ! F_209 ( V_27 -> V_14 -> V_35 ) )
return - V_79 ;
V_38 = F_210 ( V_27 -> V_14 , V_27 -> V_45 , NULL ) ;
if ( V_38 )
return V_38 ;
V_38 = F_203 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
& V_27 -> V_41 ) ;
if ( V_38 )
F_211 ( V_27 -> V_45 ) ;
return V_38 ;
}
static void F_20 ( struct V_26 * V_27 )
{
F_207 ( & V_27 -> V_41 ) ;
F_211 ( V_27 -> V_45 ) ;
}
static T_7 int F_212 ( struct V_1 * V_1 )
{
int V_38 ;
struct V_271 * V_317 , * V_318 ;
#ifdef F_213
struct V_292 * V_319 = V_320 ;
struct V_321 * V_322 ;
#endif
V_38 = - V_39 ;
V_317 = & V_271 ;
V_318 = & V_323 ;
if ( ! F_12 ( V_1 , & V_324 ) ) {
V_317 = F_204 ( V_317 , sizeof( V_271 ) , V_28 ) ;
if ( ! V_317 )
goto V_325;
V_318 = F_204 ( V_318 , sizeof( V_323 ) , V_28 ) ;
if ( ! V_318 )
goto V_326;
#ifdef F_213
V_319 = F_204 ( V_319 , sizeof( V_320 ) , V_28 ) ;
if ( ! V_319 )
goto V_327;
V_319 [ 0 ] . V_258 = & V_317 -> V_258 [ V_328 - 1 ] ;
V_319 [ 0 ] . V_300 = V_317 ;
V_319 [ 0 ] . V_301 = V_1 ;
#endif
}
#ifdef F_213
V_38 = F_203 ( V_1 , L_8 , V_317 ) ;
if ( V_38 < 0 )
goto V_329;
V_38 = F_203 ( V_1 , L_9 , V_318 ) ;
if ( V_38 < 0 )
goto V_330;
V_38 = - V_39 ;
V_322 = F_206 ( V_1 , L_10 , V_319 ) ;
if ( ! V_322 )
goto V_331;
V_1 -> V_42 . V_322 = V_322 ;
#endif
V_1 -> V_42 . V_287 = V_317 ;
V_1 -> V_42 . V_43 = V_318 ;
return 0 ;
#ifdef F_213
V_331:
F_207 ( V_318 ) ;
V_330:
F_207 ( V_317 ) ;
V_329:
if ( V_319 != V_320 )
F_26 ( V_319 ) ;
V_327:
#endif
if ( V_318 != & V_323 )
F_26 ( V_318 ) ;
V_326:
if ( V_317 != & V_271 )
F_26 ( V_317 ) ;
V_325:
return V_38 ;
}
static T_8 void F_214 ( struct V_1 * V_1 )
{
#ifdef F_213
struct V_292 * V_319 ;
V_319 = V_1 -> V_42 . V_322 -> V_332 ;
F_208 ( V_1 -> V_42 . V_322 ) ;
F_207 ( V_1 -> V_42 . V_43 ) ;
F_207 ( V_1 -> V_42 . V_287 ) ;
F_26 ( V_319 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_287 ) ;
}
void T_9 F_215 ( void )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_124 ; V_121 ++ )
F_216 ( & V_10 [ V_121 ] ) ;
F_217 ( & V_333 ) ;
F_218 ( V_334 , F_124 ) ;
F_219 ( & V_335 ) ;
F_65 ( V_81 , & V_80 , 0 ) ;
F_220 ( & V_336 ) ;
F_221 ( V_334 , V_75 , F_106 , NULL , NULL ) ;
F_221 ( V_334 , V_71 , F_81 , NULL , NULL ) ;
F_221 ( V_334 , V_337 , NULL , F_161 , NULL ) ;
F_221 ( V_334 , V_338 , F_184 ,
F_187 , NULL ) ;
}
