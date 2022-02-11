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
if ( V_37 -> V_36 )
goto V_64;
if ( ! ( V_60 -> V_65 & V_66 ) ) {
struct V_6 * * V_67 = & V_60 -> V_68 ;
while ( ( V_7 = * V_67 ) != NULL ) {
if ( ! ( V_7 -> V_65 & V_66 ) &&
V_60 -> V_69 <= V_7 -> V_69 )
V_61 = V_7 ;
if ( ! ( V_7 -> V_65 & V_66 ) ||
V_60 -> V_70 != V_7 -> V_70 ||
! F_54 ( V_60 -> V_71 , V_7 ) ) {
V_67 = & V_7 -> V_68 ;
V_62 = V_7 ;
continue;
}
if ( ! V_63 ) {
F_7 ( V_7 ) ;
* V_67 = V_7 -> V_68 ;
F_58 ( V_72 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_73 ,
V_74 , V_7 ) ;
F_27 ( V_7 ) ;
} else {
V_59 = V_7 ;
break;
}
}
}
for ( V_7 = V_59 ; V_7 ; V_7 = V_7 -> V_68 ) {
if ( V_60 -> V_70 == V_7 -> V_70 &&
F_54 ( V_60 -> V_71 , V_7 ) )
F_60 ( V_7 , V_60 ) ;
}
V_64:
* V_54 = V_60 -> V_68 ;
F_7 ( V_60 ) ;
F_58 ( V_72 , V_60 , V_57 , V_58 ) ;
F_59 ( & V_73 , V_74 , V_60 ) ;
if ( V_59 ) {
struct V_6 * V_75 = V_59 -> V_68 ;
if ( V_62 ) {
V_62 -> V_68 = V_59 -> V_68 ;
V_59 -> V_68 = V_61 -> V_68 ;
V_61 -> V_68 = V_59 ;
}
V_59 -> V_65 &= ~ V_66 ;
F_58 ( V_76 , V_59 , V_57 , V_58 ) ;
F_59 ( & V_73 ,
V_77 , V_59 ) ;
for ( V_7 = V_75 ; V_7 ; V_7 = V_7 -> V_68 ) {
if ( V_60 -> V_70 != V_7 -> V_70 ||
! F_54 ( V_60 -> V_71 , V_7 ) )
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
struct V_6 * V_60 , * * V_54 , * * V_78 ;
F_5 () ;
if ( ! V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return 0 ;
}
V_7 -> V_65 &= ~ V_66 ;
V_78 = & V_37 -> V_31 ;
for ( V_54 = & V_37 -> V_31 ; ( V_60 = * V_54 ) != NULL ;
V_54 = & V_60 -> V_68 ) {
if ( ! ( V_60 -> V_65 & V_66 ) &&
V_7 -> V_69 <= V_60 -> V_69 )
V_78 = & V_60 -> V_68 ;
if ( V_60 -> V_70 == V_7 -> V_70 &&
F_54 ( V_60 -> V_71 , V_7 ) ) {
if ( V_60 -> V_9 == V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return - V_79 ;
}
if ( V_60 -> V_69 != V_7 -> V_69 ) {
F_27 ( V_7 ) ;
return - V_80 ;
}
V_7 -> V_65 |= V_66 ;
}
}
if ( ! ( V_7 -> V_65 & V_66 ) ) {
F_63 ( ( V_4 T_1 ) V_7 -> V_9 ) ;
V_54 = V_78 ;
}
V_7 -> V_68 = * V_54 ;
* V_54 = V_7 ;
F_4 ( F_13 ( V_37 -> V_14 ) , V_7 ) ;
F_64 ( & V_81 ) ;
F_65 ( V_82 , & V_81 , 0 ) ;
F_58 ( V_76 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_73 , V_77 , V_7 ) ;
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
return - V_83 ;
}
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
if ( V_7 -> V_15 != V_37 ) {
F_30 ( V_7 -> V_15 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
}
if ( F_71 ( V_7 -> V_9 ) )
V_7 -> V_69 = V_84 ;
return F_66 ( V_7 ) ;
}
struct V_26 * F_72 ( struct V_1 * V_1 , int V_85 )
{
struct V_11 * V_14 ;
struct V_26 * V_37 = NULL ;
F_10 () ;
V_14 = F_73 ( V_1 , V_85 ) ;
if ( V_14 )
V_37 = F_74 ( V_14 -> V_51 ) ;
F_18 () ;
return V_37 ;
}
struct V_6 * F_75 ( struct V_26 * V_37 , T_2 V_86 ,
T_2 V_87 )
{
F_5 () ;
F_53 (in_dev) {
if ( V_7 -> V_70 == V_87 && F_54 ( V_86 , V_7 ) )
return V_7 ;
} F_55 ( V_37 ) ;
return NULL ;
}
static int F_76 ( struct V_88 * V_89 , bool V_90 , const struct V_6 * V_7 )
{
struct V_91 V_92 = {
. V_93 . V_94 = V_7 -> V_71 ,
. V_95 = V_7 -> V_15 -> V_14 -> V_85 ,
} ;
int V_96 ;
F_5 () ;
F_77 ( V_89 ) ;
if ( V_90 )
V_96 = F_78 ( V_89 , & V_92 ) ;
else
V_96 = F_79 ( V_89 , & V_92 ) ;
F_80 ( V_89 ) ;
return V_96 ;
}
static int F_81 ( struct V_97 * V_98 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
struct V_99 * V_100 [ V_101 + 1 ] ;
struct V_26 * V_37 ;
struct V_102 * V_103 ;
struct V_6 * V_7 , * * V_54 ;
int V_38 = - V_80 ;
F_5 () ;
V_38 = F_83 ( V_57 , sizeof( * V_103 ) , V_100 , V_101 , V_104 ) ;
if ( V_38 < 0 )
goto V_105;
V_103 = F_84 ( V_57 ) ;
V_37 = F_72 ( V_1 , V_103 -> V_106 ) ;
if ( ! V_37 ) {
V_38 = - V_107 ;
goto V_105;
}
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 ) {
if ( V_100 [ V_108 ] &&
V_7 -> V_9 != F_85 ( V_100 [ V_108 ] ) )
continue;
if ( V_100 [ V_109 ] && F_86 ( V_100 [ V_109 ] , V_7 -> V_110 ) )
continue;
if ( V_100 [ V_111 ] &&
( V_103 -> V_112 != V_7 -> V_112 ||
! F_54 ( F_85 ( V_100 [ V_111 ] ) , V_7 ) ) )
continue;
if ( F_87 ( V_7 -> V_71 ) )
F_76 ( V_1 -> V_42 . V_113 , false , V_7 ) ;
F_56 ( V_37 , V_54 , 1 , V_57 , F_88 ( V_98 ) . V_58 ) ;
return 0 ;
}
V_38 = - V_114 ;
V_105:
return V_38 ;
}
static void F_89 ( struct V_115 * V_116 )
{
unsigned long V_117 , V_118 , V_75 , V_119 ;
struct V_6 * V_7 ;
struct V_120 * V_121 ;
int V_122 ;
V_117 = V_123 ;
V_118 = F_90 ( V_117 + V_124 ) ;
for ( V_122 = 0 ; V_122 < V_125 ; V_122 ++ ) {
bool V_126 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_127 ;
if ( V_7 -> V_65 & V_128 )
continue;
V_127 = ( V_117 - V_7 -> V_129 +
V_130 ) / V_131 ;
if ( V_7 -> V_132 != V_133 &&
V_127 >= V_7 -> V_132 ) {
V_126 = true ;
} else if ( V_7 -> V_134 ==
V_133 ) {
continue;
} else if ( V_127 >= V_7 -> V_134 ) {
if ( F_91 ( V_7 -> V_129 +
V_7 -> V_132 * V_131 , V_118 ) )
V_118 = V_7 -> V_129 +
V_7 -> V_132 * V_131 ;
if ( ! ( V_7 -> V_65 & V_135 ) )
V_126 = true ;
} else if ( F_91 ( V_7 -> V_129 +
V_7 -> V_134 * V_131 ,
V_118 ) ) {
V_118 = V_7 -> V_129 +
V_7 -> V_134 * V_131 ;
}
}
F_18 () ;
if ( ! V_126 )
continue;
F_92 () ;
F_93 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_127 ;
if ( V_7 -> V_65 & V_128 )
continue;
V_127 = ( V_117 - V_7 -> V_129 +
V_130 ) / V_131 ;
if ( V_7 -> V_132 != V_133 &&
V_127 >= V_7 -> V_132 ) {
struct V_6 * * V_54 ;
for ( V_54 = & V_7 -> V_15 -> V_31 ;
* V_54 != NULL ; V_54 = & ( * V_54 ) -> V_68 ) {
if ( * V_54 == V_7 ) {
F_48 ( V_7 -> V_15 ,
V_54 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_134 !=
V_133 &&
V_127 >= V_7 -> V_134 &&
! ( V_7 -> V_65 & V_135 ) ) {
V_7 -> V_65 |= V_135 ;
F_58 ( V_76 , V_7 , NULL , 0 ) ;
}
}
F_94 () ;
}
V_75 = F_90 ( V_118 ) ;
V_119 = V_118 ;
if ( F_91 ( V_75 , V_118 + V_136 ) )
V_119 = V_75 ;
V_117 = V_123 ;
if ( F_91 ( V_119 , V_117 + V_137 ) )
V_119 = V_117 + V_137 ;
F_65 ( V_82 , & V_81 ,
V_119 - V_117 ) ;
}
static void F_95 ( struct V_6 * V_7 , T_3 V_138 ,
T_3 V_139 )
{
unsigned long V_140 ;
V_7 -> V_65 &= ~ ( V_128 | V_135 ) ;
V_140 = F_96 ( V_138 , V_131 ) ;
if ( F_97 ( V_140 ) )
V_7 -> V_132 = V_140 ;
else
V_7 -> V_65 |= V_128 ;
V_140 = F_96 ( V_139 , V_131 ) ;
if ( F_97 ( V_140 ) ) {
if ( V_140 == 0 )
V_7 -> V_65 |= V_135 ;
V_7 -> V_134 = V_140 ;
}
V_7 -> V_129 = V_123 ;
if ( ! V_7 -> V_141 )
V_7 -> V_141 = V_7 -> V_129 ;
}
static struct V_6 * F_98 ( struct V_1 * V_1 , struct V_56 * V_57 ,
T_3 * V_142 , T_3 * V_143 )
{
struct V_99 * V_100 [ V_101 + 1 ] ;
struct V_6 * V_7 ;
struct V_102 * V_103 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_103 ) , V_100 , V_101 , V_104 ) ;
if ( V_38 < 0 )
goto V_105;
V_103 = F_84 ( V_57 ) ;
V_38 = - V_80 ;
if ( V_103 -> V_112 > 32 || ! V_100 [ V_108 ] )
goto V_105;
V_14 = F_99 ( V_1 , V_103 -> V_106 ) ;
V_38 = - V_107 ;
if ( ! V_14 )
goto V_105;
V_37 = F_68 ( V_14 ) ;
V_38 = - V_83 ;
if ( ! V_37 )
goto V_105;
V_7 = F_21 () ;
if ( ! V_7 )
goto V_105;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_40 ( V_37 ) ;
if ( ! V_100 [ V_111 ] )
V_100 [ V_111 ] = V_100 [ V_108 ] ;
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_112 = V_103 -> V_112 ;
V_7 -> V_70 = F_101 ( V_103 -> V_112 ) ;
V_7 -> V_65 = V_100 [ V_144 ] ? F_102 ( V_100 [ V_144 ] ) :
V_103 -> V_65 ;
V_7 -> V_69 = V_103 -> V_69 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_85 ( V_100 [ V_108 ] ) ;
V_7 -> V_71 = F_85 ( V_100 [ V_111 ] ) ;
if ( V_100 [ V_145 ] )
V_7 -> V_146 = F_85 ( V_100 [ V_145 ] ) ;
if ( V_100 [ V_109 ] )
F_103 ( V_7 -> V_110 , V_100 [ V_109 ] , V_147 ) ;
else
memcpy ( V_7 -> V_110 , V_14 -> V_35 , V_147 ) ;
if ( V_100 [ V_148 ] ) {
struct V_149 * V_150 ;
V_150 = F_104 ( V_100 [ V_148 ] ) ;
if ( ! V_150 -> V_151 || V_150 -> V_152 > V_150 -> V_151 ) {
V_38 = - V_80 ;
goto V_153;
}
* V_142 = V_150 -> V_151 ;
* V_143 = V_150 -> V_152 ;
}
return V_7 ;
V_153:
F_27 ( V_7 ) ;
V_105:
return F_44 ( V_38 ) ;
}
static struct V_6 * F_105 ( struct V_6 * V_7 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_60 , * * V_54 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_54 = & V_37 -> V_31 ; ( V_60 = * V_54 ) != NULL ;
V_54 = & V_60 -> V_68 ) {
if ( V_60 -> V_70 == V_7 -> V_70 &&
F_54 ( V_60 -> V_71 , V_7 ) &&
V_60 -> V_9 == V_7 -> V_9 )
return V_60 ;
}
return NULL ;
}
static int F_106 ( struct V_97 * V_98 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
struct V_6 * V_7 ;
struct V_6 * V_154 ;
T_3 V_138 = V_133 ;
T_3 V_139 = V_133 ;
F_5 () ;
V_7 = F_98 ( V_1 , V_57 , & V_138 , & V_139 ) ;
if ( F_107 ( V_7 ) )
return F_108 ( V_7 ) ;
V_154 = F_105 ( V_7 ) ;
if ( ! V_154 ) {
F_95 ( V_7 , V_138 , V_139 ) ;
if ( V_7 -> V_65 & V_155 ) {
int V_96 = F_76 ( V_1 -> V_42 . V_113 ,
true , V_7 ) ;
if ( V_96 < 0 ) {
F_27 ( V_7 ) ;
return V_96 ;
}
}
return F_62 ( V_7 , V_57 , F_88 ( V_98 ) . V_58 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_57 -> V_156 & V_157 ||
! ( V_57 -> V_156 & V_158 ) )
return - V_79 ;
V_7 = V_154 ;
F_95 ( V_7 , V_138 , V_139 ) ;
F_64 ( & V_81 ) ;
F_65 ( V_82 ,
& V_81 , 0 ) ;
F_58 ( V_76 , V_7 , V_57 , F_88 ( V_98 ) . V_58 ) ;
}
return 0 ;
}
static int F_109 ( T_2 V_2 )
{
int V_159 = - 1 ;
if ( F_110 ( V_2 ) )
V_159 = 0 ;
else {
T_3 V_160 = F_111 ( V_2 ) ;
if ( F_112 ( V_160 ) )
V_159 = 8 ;
else if ( F_113 ( V_160 ) )
V_159 = 16 ;
else if ( F_114 ( V_160 ) )
V_159 = 24 ;
}
return V_159 ;
}
int F_115 ( struct V_1 * V_1 , unsigned int V_161 , void T_4 * V_162 )
{
struct V_163 V_164 ;
struct V_165 V_166 ;
struct V_165 * sin = (struct V_165 * ) & V_164 . V_167 ;
struct V_26 * V_37 ;
struct V_6 * * V_54 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_168 ;
int V_96 = - V_169 ;
int V_170 = 0 ;
if ( F_116 ( & V_164 , V_162 , sizeof( struct V_163 ) ) )
goto V_40;
V_164 . V_171 [ V_147 - 1 ] = 0 ;
memcpy ( & V_166 , sin , sizeof( * sin ) ) ;
V_168 = strchr ( V_164 . V_171 , ':' ) ;
if ( V_168 )
* V_168 = 0 ;
F_117 ( V_1 , V_164 . V_171 ) ;
switch ( V_161 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_170 = ( V_166 . V_176 == V_177 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_176 = V_177 ;
break;
case V_178 :
V_96 = - V_179 ;
if ( ! F_118 ( V_1 -> V_180 , V_181 ) )
goto V_40;
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
V_96 = - V_179 ;
if ( ! F_118 ( V_1 -> V_180 , V_181 ) )
goto V_40;
V_96 = - V_80 ;
if ( sin -> V_176 != V_177 )
goto V_40;
break;
default:
V_96 = - V_80 ;
goto V_40;
}
F_92 () ;
V_96 = - V_107 ;
V_14 = F_119 ( V_1 , V_164 . V_171 ) ;
if ( ! V_14 )
goto V_186;
if ( V_168 )
* V_168 = ':' ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
if ( V_170 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 ) {
if ( ! strcmp ( V_164 . V_171 , V_7 -> V_110 ) &&
V_166 . V_187 . V_94 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 )
if ( ! strcmp ( V_164 . V_171 , V_7 -> V_110 ) )
break;
}
}
V_96 = - V_114 ;
if ( ! V_7 && V_161 != V_182 && V_161 != V_178 )
goto V_186;
switch ( V_161 ) {
case V_172 :
sin -> V_187 . V_94 = V_7 -> V_9 ;
goto V_188;
case V_173 :
sin -> V_187 . V_94 = V_7 -> V_146 ;
goto V_188;
case V_174 :
sin -> V_187 . V_94 = V_7 -> V_71 ;
goto V_188;
case V_175 :
sin -> V_187 . V_94 = V_7 -> V_70 ;
goto V_188;
case V_178 :
if ( V_168 ) {
V_96 = - V_114 ;
if ( ! V_7 )
break;
V_96 = 0 ;
if ( ! ( V_164 . V_189 & V_50 ) )
F_48 ( V_37 , V_54 , 1 ) ;
break;
}
V_96 = F_120 ( V_14 , V_164 . V_189 ) ;
break;
case V_182 :
V_96 = - V_80 ;
if ( F_109 ( sin -> V_187 . V_94 ) < 0 )
break;
if ( ! V_7 ) {
V_96 = - V_83 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_100 ( & V_7 -> V_8 ) ;
if ( V_168 )
memcpy ( V_7 -> V_110 , V_164 . V_171 , V_147 ) ;
else
memcpy ( V_7 -> V_110 , V_14 -> V_35 , V_147 ) ;
} else {
V_96 = 0 ;
if ( V_7 -> V_9 == sin -> V_187 . V_94 )
break;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_146 = 0 ;
V_7 -> V_69 = 0 ;
}
V_7 -> V_71 = V_7 -> V_9 = sin -> V_187 . V_94 ;
if ( ! ( V_14 -> V_49 & V_190 ) ) {
V_7 -> V_112 = F_109 ( V_7 -> V_71 ) ;
V_7 -> V_70 = F_101 ( V_7 -> V_112 ) ;
if ( ( V_14 -> V_49 & V_191 ) &&
V_7 -> V_112 < 31 )
V_7 -> V_146 = V_7 -> V_71 |
~ V_7 -> V_70 ;
} else {
V_7 -> V_112 = 32 ;
V_7 -> V_70 = F_101 ( 32 ) ;
}
F_95 ( V_7 , V_133 , V_133 ) ;
V_96 = F_67 ( V_14 , V_7 ) ;
break;
case V_183 :
V_96 = 0 ;
if ( V_7 -> V_146 != sin -> V_187 . V_94 ) {
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_146 = sin -> V_187 . V_94 ;
F_66 ( V_7 ) ;
}
break;
case V_184 :
V_96 = 0 ;
if ( V_7 -> V_71 == sin -> V_187 . V_94 )
break;
V_96 = - V_80 ;
if ( F_109 ( sin -> V_187 . V_94 ) < 0 )
break;
V_96 = 0 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_71 = sin -> V_187 . V_94 ;
F_66 ( V_7 ) ;
break;
case V_185 :
V_96 = - V_80 ;
if ( F_121 ( sin -> V_187 . V_94 , 0 ) )
break;
V_96 = 0 ;
if ( V_7 -> V_70 != sin -> V_187 . V_94 ) {
T_2 V_192 = V_7 -> V_70 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_187 . V_94 ;
V_7 -> V_112 = F_122 ( V_7 -> V_70 ) ;
if ( ( V_14 -> V_49 & V_191 ) &&
( V_7 -> V_112 < 31 ) &&
( V_7 -> V_146 ==
( V_7 -> V_9 | ~ V_192 ) ) ) {
V_7 -> V_146 = ( V_7 -> V_9 |
~ sin -> V_187 . V_94 ) ;
}
F_66 ( V_7 ) ;
}
break;
}
V_186:
F_94 () ;
V_40:
return V_96 ;
V_188:
F_94 () ;
V_96 = F_123 ( V_162 , & V_164 , sizeof( struct V_163 ) ) ? - V_169 : 0 ;
goto V_40;
}
static int F_124 ( struct V_11 * V_14 , char T_4 * V_193 , int V_194 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_163 V_164 ;
int V_186 = 0 ;
if ( ! V_37 )
goto V_40;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_68 ) {
if ( ! V_193 ) {
V_186 += sizeof( V_164 ) ;
continue;
}
if ( V_194 < ( int ) sizeof( V_164 ) )
break;
memset ( & V_164 , 0 , sizeof( struct V_163 ) ) ;
strcpy ( V_164 . V_171 , V_7 -> V_110 ) ;
( * (struct V_165 * ) & V_164 . V_167 ) . V_176 = V_177 ;
( * (struct V_165 * ) & V_164 . V_167 ) . V_187 . V_94 =
V_7 -> V_9 ;
if ( F_123 ( V_193 , & V_164 , sizeof( struct V_163 ) ) ) {
V_186 = - V_169 ;
break;
}
V_193 += sizeof( struct V_163 ) ;
V_194 -= sizeof( struct V_163 ) ;
V_186 += sizeof( struct V_163 ) ;
}
V_40:
return V_186 ;
}
T_2 F_125 ( const struct V_11 * V_14 , T_2 V_195 , int V_196 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
int V_197 ;
F_10 () ;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_198;
F_53 (in_dev) {
if ( V_7 -> V_69 > V_196 )
continue;
if ( ! V_195 || F_54 ( V_195 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_199;
V_198:
V_197 = F_127 ( V_14 ) ;
if ( V_197 &&
( V_14 = F_73 ( V_1 , V_197 ) ) &&
( V_37 = F_126 ( V_14 ) ) ) {
F_53 (in_dev) {
if ( V_7 -> V_69 != V_200 &&
V_7 -> V_69 <= V_196 ) {
V_2 = V_7 -> V_9 ;
goto V_199;
}
} F_55 ( V_37 ) ;
}
F_128 (net, dev) {
if ( F_127 ( V_14 ) != V_197 )
continue;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
continue;
F_53 (in_dev) {
if ( V_7 -> V_69 != V_200 &&
V_7 -> V_69 <= V_196 ) {
V_2 = V_7 -> V_9 ;
goto V_199;
}
} F_55 ( V_37 ) ;
}
V_199:
F_18 () ;
return V_2 ;
}
static T_2 F_129 ( struct V_26 * V_37 , T_2 V_195 ,
T_2 V_22 , int V_196 )
{
int V_201 = 0 ;
T_2 V_2 = 0 ;
F_130 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_69 <= V_196 ) {
V_2 = V_7 -> V_9 ;
if ( V_201 )
break;
}
if ( ! V_201 ) {
V_201 = ( ! V_22 || F_54 ( V_22 , V_7 ) ) &&
( ! V_195 || F_54 ( V_195 , V_7 ) ) ;
if ( V_201 && V_2 ) {
if ( V_22 || ! V_195 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_69 <= V_196 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_201 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_201 ? V_2 : 0 ;
}
T_2 F_131 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_195 , T_2 V_22 , int V_196 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 )
return F_129 ( V_37 , V_195 , V_22 , V_196 ) ;
F_10 () ;
F_128 (net, dev) {
V_37 = F_126 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_129 ( V_37 , V_195 , V_22 , V_196 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_132 ( struct V_202 * V_203 )
{
return F_133 ( & V_73 , V_203 ) ;
}
int F_134 ( struct V_202 * V_203 )
{
return F_135 ( & V_73 , V_203 ) ;
}
static void F_136 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_204 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_68 ) {
char V_205 [ V_147 ] , * V_206 ;
memcpy ( V_205 , V_7 -> V_110 , V_147 ) ;
memcpy ( V_7 -> V_110 , V_14 -> V_35 , V_147 ) ;
if ( V_204 ++ == 0 )
goto V_207;
V_206 = strchr ( V_205 , ':' ) ;
if ( ! V_206 ) {
sprintf ( V_205 , L_4 , V_204 ) ;
V_206 = V_205 ;
}
if ( strlen ( V_206 ) + strlen ( V_14 -> V_35 ) < V_147 )
strcat ( V_7 -> V_110 , V_206 ) ;
else
strcpy ( V_7 -> V_110 + ( V_147 - strlen ( V_206 ) - 1 ) , V_206 ) ;
V_207:
F_58 ( V_76 , V_7 , NULL , 0 ) ;
}
}
static bool F_137 ( unsigned int V_208 )
{
return V_208 >= 68 ;
}
static void F_138 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_68 ) {
F_139 ( V_209 , V_210 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_211 , NULL ) ;
}
}
static int F_140 ( struct V_202 * V_212 , unsigned long V_213 ,
void * V_214 )
{
struct V_11 * V_14 = F_141 ( V_214 ) ;
struct V_26 * V_37 = F_68 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_213 == V_215 ) {
V_37 = F_36 ( V_14 ) ;
if ( F_107 ( V_37 ) )
return F_142 ( F_108 ( V_37 ) ) ;
if ( V_14 -> V_49 & V_216 ) {
F_143 ( V_37 , V_217 , 1 ) ;
F_143 ( V_37 , V_218 , 1 ) ;
}
} else if ( V_213 == V_219 ) {
if ( F_137 ( V_14 -> V_208 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_40;
}
switch ( V_213 ) {
case V_215 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_14 -> V_51 , NULL ) ;
break;
case V_77 :
if ( ! F_137 ( V_14 -> V_208 ) )
break;
if ( V_14 -> V_49 & V_216 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_71 = F_144 ( V_220 ) ;
V_7 -> V_112 = 8 ;
V_7 -> V_70 = F_101 ( 8 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_69 = V_84 ;
memcpy ( V_7 -> V_110 , V_14 -> V_35 , V_147 ) ;
F_95 ( V_7 , V_133 ,
V_133 ) ;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_66 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_221 :
if ( ! F_145 ( V_37 ) )
break;
case V_222 :
F_138 ( V_14 , V_37 ) ;
break;
case V_74 :
F_146 ( V_37 ) ;
break;
case V_223 :
F_147 ( V_37 ) ;
break;
case V_224 :
F_148 ( V_37 ) ;
break;
case V_219 :
if ( F_137 ( V_14 -> V_208 ) )
break;
case V_225 :
F_46 ( V_37 ) ;
break;
case V_226 :
F_136 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_40:
return V_227 ;
}
static T_5 F_149 ( void )
{
return F_150 ( sizeof( struct V_102 ) )
+ F_151 ( 4 )
+ F_151 ( 4 )
+ F_151 ( 4 )
+ F_151 ( V_147 )
+ F_151 ( 4 )
+ F_151 ( sizeof( struct V_149 ) ) ;
}
static inline T_1 F_152 ( unsigned long V_228 )
{
return ( V_228 - V_229 ) * 100UL / V_131 ;
}
static int F_153 ( struct V_97 * V_98 , unsigned long V_228 ,
unsigned long V_230 , T_1 V_231 , T_1 V_232 )
{
struct V_149 V_150 ;
V_150 . V_228 = F_152 ( V_228 ) ;
V_150 . V_230 = F_152 ( V_230 ) ;
V_150 . V_152 = V_231 ;
V_150 . V_151 = V_232 ;
return F_154 ( V_98 , V_148 , sizeof( V_150 ) , & V_150 ) ;
}
static int F_155 ( struct V_97 * V_98 , struct V_6 * V_7 ,
T_1 V_58 , T_1 V_233 , int V_213 , unsigned int V_49 )
{
struct V_102 * V_103 ;
struct V_56 * V_57 ;
T_1 V_231 , V_232 ;
V_57 = F_156 ( V_98 , V_58 , V_233 , V_213 , sizeof( * V_103 ) , V_49 ) ;
if ( ! V_57 )
return - V_234 ;
V_103 = F_84 ( V_57 ) ;
V_103 -> V_235 = V_177 ;
V_103 -> V_112 = V_7 -> V_112 ;
V_103 -> V_65 = V_7 -> V_65 ;
V_103 -> V_69 = V_7 -> V_69 ;
V_103 -> V_106 = V_7 -> V_15 -> V_14 -> V_85 ;
if ( ! ( V_103 -> V_65 & V_128 ) ) {
V_231 = V_7 -> V_134 ;
V_232 = V_7 -> V_132 ;
if ( V_231 != V_133 ) {
long V_236 = ( V_123 - V_7 -> V_129 ) / V_131 ;
if ( V_231 > V_236 )
V_231 -= V_236 ;
else
V_231 = 0 ;
if ( V_232 != V_133 ) {
if ( V_232 > V_236 )
V_232 -= V_236 ;
else
V_232 = 0 ;
}
}
} else {
V_231 = V_133 ;
V_232 = V_133 ;
}
if ( ( V_7 -> V_71 &&
F_157 ( V_98 , V_111 , V_7 -> V_71 ) ) ||
( V_7 -> V_9 &&
F_157 ( V_98 , V_108 , V_7 -> V_9 ) ) ||
( V_7 -> V_146 &&
F_157 ( V_98 , V_145 , V_7 -> V_146 ) ) ||
( V_7 -> V_110 [ 0 ] &&
F_158 ( V_98 , V_109 , V_7 -> V_110 ) ) ||
F_159 ( V_98 , V_144 , V_7 -> V_65 ) ||
F_153 ( V_98 , V_7 -> V_141 , V_7 -> V_129 ,
V_231 , V_232 ) )
goto V_237;
F_160 ( V_98 , V_57 ) ;
return 0 ;
V_237:
F_161 ( V_98 , V_57 ) ;
return - V_234 ;
}
static int F_162 ( struct V_97 * V_98 , struct V_238 * V_239 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
int V_240 , V_241 ;
int V_242 , V_243 ;
int V_244 , V_245 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_6 * V_7 ;
struct V_246 * V_30 ;
V_241 = V_239 -> args [ 0 ] ;
V_243 = V_242 = V_239 -> args [ 1 ] ;
V_245 = V_244 = V_239 -> args [ 2 ] ;
for ( V_240 = V_241 ; V_240 < V_247 ; V_240 ++ , V_243 = 0 ) {
V_242 = 0 ;
V_30 = & V_1 -> V_248 [ V_240 ] ;
F_10 () ;
V_239 -> V_233 = F_163 ( & V_1 -> V_42 . V_249 ) ^
V_1 -> V_250 ;
F_11 (dev, head, index_hlist) {
if ( V_242 < V_243 )
goto V_251;
if ( V_240 > V_241 || V_242 > V_243 )
V_245 = 0 ;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_251;
for ( V_7 = V_37 -> V_31 , V_244 = 0 ; V_7 ;
V_7 = V_7 -> V_68 , V_244 ++ ) {
if ( V_244 < V_245 )
continue;
if ( F_155 ( V_98 , V_7 ,
F_88 ( V_239 -> V_98 ) . V_58 ,
V_239 -> V_57 -> V_252 ,
V_76 , V_253 ) < 0 ) {
F_18 () ;
goto V_186;
}
F_164 ( V_239 , F_165 ( V_98 ) ) ;
}
V_251:
V_242 ++ ;
}
F_18 () ;
}
V_186:
V_239 -> args [ 0 ] = V_240 ;
V_239 -> args [ 1 ] = V_242 ;
V_239 -> args [ 2 ] = V_244 ;
return V_98 -> V_194 ;
}
static void F_58 ( int V_213 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_97 * V_98 ;
T_1 V_233 = V_57 ? V_57 -> V_252 : 0 ;
int V_38 = - V_83 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_98 = F_166 ( F_149 () , V_28 ) ;
if ( ! V_98 )
goto V_105;
V_38 = F_155 ( V_98 , V_7 , V_58 , V_233 , V_213 , 0 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_234 ) ;
F_167 ( V_98 ) ;
goto V_105;
}
F_168 ( V_98 , V_1 , V_58 , V_254 , V_57 , V_28 ) ;
return;
V_105:
if ( V_38 < 0 )
F_169 ( V_1 , V_254 , V_38 ) ;
}
static T_5 F_170 ( const struct V_11 * V_14 ,
T_1 V_255 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
if ( ! V_37 )
return 0 ;
return F_151 ( V_256 * 4 ) ;
}
static int F_171 ( struct V_97 * V_98 , const struct V_11 * V_14 ,
T_1 V_255 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
struct V_99 * V_257 ;
int V_122 ;
if ( ! V_37 )
return - V_258 ;
V_257 = F_172 ( V_98 , V_259 , V_256 * 4 ) ;
if ( ! V_257 )
return - V_234 ;
for ( V_122 = 0 ; V_122 < V_256 ; V_122 ++ )
( ( T_1 * ) F_104 ( V_257 ) ) [ V_122 ] = V_37 -> V_41 . V_260 [ V_122 ] ;
return 0 ;
}
static int F_173 ( const struct V_11 * V_14 ,
const struct V_99 * V_257 )
{
struct V_99 * V_52 , * V_100 [ V_261 + 1 ] ;
int V_38 , V_262 ;
if ( V_14 && ! F_68 ( V_14 ) )
return - V_263 ;
V_38 = F_174 ( V_100 , V_261 , V_257 , V_264 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_100 [ V_259 ] ) {
F_175 (a, tb[IFLA_INET_CONF], rem) {
int V_265 = F_176 ( V_52 ) ;
if ( F_177 ( V_52 ) < 4 )
return - V_80 ;
if ( V_265 <= 0 || V_265 > V_256 )
return - V_80 ;
}
}
return 0 ;
}
static int F_178 ( struct V_11 * V_14 , const struct V_99 * V_257 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_99 * V_52 , * V_100 [ V_261 + 1 ] ;
int V_262 ;
if ( ! V_37 )
return - V_263 ;
if ( F_174 ( V_100 , V_261 , V_257 , NULL ) < 0 )
F_179 () ;
if ( V_100 [ V_259 ] ) {
F_175 (a, tb[IFLA_INET_CONF], rem)
F_180 ( V_37 , F_176 ( V_52 ) , F_102 ( V_52 ) ) ;
}
return 0 ;
}
static int F_181 ( int type )
{
int V_266 = F_150 ( sizeof( struct V_267 ) )
+ F_151 ( 4 ) ;
bool V_268 = false ;
if ( type == V_269 )
V_268 = true ;
if ( V_268 || type == V_270 )
V_266 += F_151 ( 4 ) ;
if ( V_268 || type == V_271 )
V_266 += F_151 ( 4 ) ;
if ( V_268 || type == V_272 )
V_266 += F_151 ( 4 ) ;
if ( V_268 || type == V_273 )
V_266 += F_151 ( 4 ) ;
if ( V_268 || type == V_274 )
V_266 += F_151 ( 4 ) ;
return V_266 ;
}
static int F_182 ( struct V_97 * V_98 , int V_85 ,
struct V_275 * V_276 , T_1 V_58 ,
T_1 V_233 , int V_213 , unsigned int V_49 ,
int type )
{
struct V_56 * V_57 ;
struct V_267 * V_277 ;
bool V_268 = false ;
V_57 = F_156 ( V_98 , V_58 , V_233 , V_213 , sizeof( struct V_267 ) ,
V_49 ) ;
if ( ! V_57 )
return - V_234 ;
if ( type == V_269 )
V_268 = true ;
V_277 = F_84 ( V_57 ) ;
V_277 -> V_278 = V_177 ;
if ( F_183 ( V_98 , V_279 , V_85 ) < 0 )
goto V_237;
if ( ( V_268 || type == V_270 ) &&
F_183 ( V_98 , V_270 ,
F_38 ( * V_276 , V_48 ) ) < 0 )
goto V_237;
if ( ( V_268 || type == V_271 ) &&
F_183 ( V_98 , V_271 ,
F_38 ( * V_276 , V_280 ) ) < 0 )
goto V_237;
if ( ( V_268 || type == V_272 ) &&
F_183 ( V_98 , V_272 ,
F_38 ( * V_276 , V_281 ) ) < 0 )
goto V_237;
if ( ( V_268 || type == V_273 ) &&
F_183 ( V_98 , V_273 ,
F_38 ( * V_276 , V_282 ) ) < 0 )
goto V_237;
if ( ( V_268 || type == V_274 ) &&
F_183 ( V_98 , V_274 ,
F_38 ( * V_276 , V_283 ) ) < 0 )
goto V_237;
F_160 ( V_98 , V_57 ) ;
return 0 ;
V_237:
F_161 ( V_98 , V_57 ) ;
return - V_234 ;
}
void F_184 ( struct V_1 * V_1 , int type , int V_85 ,
struct V_275 * V_276 )
{
struct V_97 * V_98 ;
int V_38 = - V_83 ;
V_98 = F_166 ( F_181 ( type ) , V_28 ) ;
if ( ! V_98 )
goto V_105;
V_38 = F_182 ( V_98 , V_85 , V_276 , 0 , 0 ,
V_284 , 0 , type ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_234 ) ;
F_167 ( V_98 ) ;
goto V_105;
}
F_168 ( V_98 , V_1 , 0 , V_285 , NULL , V_28 ) ;
return;
V_105:
if ( V_38 < 0 )
F_169 ( V_1 , V_285 , V_38 ) ;
}
static int F_185 ( struct V_97 * V_286 ,
struct V_56 * V_57 )
{
struct V_1 * V_1 = F_82 ( V_286 -> V_89 ) ;
struct V_99 * V_100 [ V_287 + 1 ] ;
struct V_267 * V_277 ;
struct V_97 * V_98 ;
struct V_275 * V_276 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_85 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_277 ) , V_100 , V_287 ,
V_288 ) ;
if ( V_38 < 0 )
goto V_105;
V_38 = - V_80 ;
if ( ! V_100 [ V_279 ] )
goto V_105;
V_85 = F_186 ( V_100 [ V_279 ] ) ;
switch ( V_85 ) {
case V_289 :
V_276 = V_1 -> V_42 . V_290 ;
break;
case V_291 :
V_276 = V_1 -> V_42 . V_43 ;
break;
default:
V_14 = F_99 ( V_1 , V_85 ) ;
if ( ! V_14 )
goto V_105;
V_37 = F_68 ( V_14 ) ;
if ( ! V_37 )
goto V_105;
V_276 = & V_37 -> V_41 ;
break;
}
V_38 = - V_83 ;
V_98 = F_166 ( F_181 ( V_269 ) , V_28 ) ;
if ( ! V_98 )
goto V_105;
V_38 = F_182 ( V_98 , V_85 , V_276 ,
F_88 ( V_286 ) . V_58 ,
V_57 -> V_252 , V_284 , 0 ,
V_269 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_234 ) ;
F_167 ( V_98 ) ;
goto V_105;
}
V_38 = F_187 ( V_98 , V_1 , F_88 ( V_286 ) . V_58 ) ;
V_105:
return V_38 ;
}
static int F_188 ( struct V_97 * V_98 ,
struct V_238 * V_239 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
int V_240 , V_241 ;
int V_242 , V_243 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_246 * V_30 ;
V_241 = V_239 -> args [ 0 ] ;
V_243 = V_242 = V_239 -> args [ 1 ] ;
for ( V_240 = V_241 ; V_240 < V_247 ; V_240 ++ , V_243 = 0 ) {
V_242 = 0 ;
V_30 = & V_1 -> V_248 [ V_240 ] ;
F_10 () ;
V_239 -> V_233 = F_163 ( & V_1 -> V_42 . V_249 ) ^
V_1 -> V_250 ;
F_11 (dev, head, index_hlist) {
if ( V_242 < V_243 )
goto V_251;
V_37 = F_126 ( V_14 ) ;
if ( ! V_37 )
goto V_251;
if ( F_182 ( V_98 , V_14 -> V_85 ,
& V_37 -> V_41 ,
F_88 ( V_239 -> V_98 ) . V_58 ,
V_239 -> V_57 -> V_252 ,
V_284 ,
V_253 ,
V_269 ) < 0 ) {
F_18 () ;
goto V_186;
}
F_164 ( V_239 , F_165 ( V_98 ) ) ;
V_251:
V_242 ++ ;
}
F_18 () ;
}
if ( V_240 == V_247 ) {
if ( F_182 ( V_98 , V_289 ,
V_1 -> V_42 . V_290 ,
F_88 ( V_239 -> V_98 ) . V_58 ,
V_239 -> V_57 -> V_252 ,
V_284 , V_253 ,
V_269 ) < 0 )
goto V_186;
else
V_240 ++ ;
}
if ( V_240 == V_247 + 1 ) {
if ( F_182 ( V_98 , V_291 ,
V_1 -> V_42 . V_43 ,
F_88 ( V_239 -> V_98 ) . V_58 ,
V_239 -> V_57 -> V_252 ,
V_284 , V_253 ,
V_269 ) < 0 )
goto V_186;
else
V_240 ++ ;
}
V_186:
V_239 -> args [ 0 ] = V_240 ;
V_239 -> args [ 1 ] = V_242 ;
return V_98 -> V_194 ;
}
static void F_189 ( struct V_1 * V_1 , int V_122 )
{
struct V_11 * V_14 ;
F_10 () ;
F_128 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_126 ( V_14 ) ;
if ( V_37 && ! F_190 ( V_122 , V_37 -> V_41 . V_292 ) )
V_37 -> V_41 . V_260 [ V_122 ] = V_1 -> V_42 . V_43 -> V_260 [ V_122 ] ;
}
F_18 () ;
}
static void F_191 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_293 = F_192 ( V_1 , V_48 ) ;
F_192 ( V_1 , V_294 ) = ! V_293 ;
F_193 ( V_1 , V_48 ) = V_293 ;
F_184 ( V_1 , V_270 ,
V_289 ,
V_1 -> V_42 . V_290 ) ;
F_184 ( V_1 , V_270 ,
V_291 ,
V_1 -> V_42 . V_43 ) ;
F_194 (net, dev) {
struct V_26 * V_37 ;
if ( V_293 )
F_39 ( V_14 ) ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
F_143 ( V_37 , V_48 , V_293 ) ;
F_184 ( V_1 , V_270 ,
V_14 -> V_85 , & V_37 -> V_41 ) ;
}
}
}
static int F_195 ( struct V_1 * V_1 , struct V_275 * V_41 )
{
if ( V_41 == V_1 -> V_42 . V_43 )
return V_291 ;
else if ( V_41 == V_1 -> V_42 . V_290 )
return V_289 ;
else {
struct V_26 * V_27
= F_24 ( V_41 , struct V_26 , V_41 ) ;
return V_27 -> V_14 -> V_85 ;
}
}
static int F_196 ( struct V_295 * V_296 , int V_297 ,
void T_4 * V_298 ,
T_5 * V_299 , T_6 * V_300 )
{
int V_301 = * ( int * ) V_296 -> V_260 ;
int V_96 = F_197 ( V_296 , V_297 , V_298 , V_299 , V_300 ) ;
int V_302 = * ( int * ) V_296 -> V_260 ;
if ( V_297 ) {
struct V_275 * V_41 = V_296 -> V_303 ;
struct V_1 * V_1 = V_296 -> V_304 ;
int V_122 = ( int * ) V_296 -> V_260 - V_41 -> V_260 ;
int V_85 ;
F_198 ( V_122 , V_41 -> V_292 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_189 ( V_1 , V_122 ) ;
if ( V_122 == V_305 - 1 ||
V_122 == V_306 - 1 )
if ( ( V_302 == 0 ) && ( V_301 != 0 ) )
F_199 ( V_1 ) ;
if ( V_122 == V_307 - 1 &&
V_302 != V_301 ) {
V_85 = F_195 ( V_1 , V_41 ) ;
F_184 ( V_1 , V_271 ,
V_85 , V_41 ) ;
}
if ( V_122 == V_308 - 1 &&
V_302 != V_301 ) {
V_85 = F_195 ( V_1 , V_41 ) ;
F_184 ( V_1 , V_273 ,
V_85 , V_41 ) ;
}
if ( V_122 == V_309 - 1 &&
V_302 != V_301 ) {
V_85 = F_195 ( V_1 , V_41 ) ;
F_184 ( V_1 , V_274 ,
V_85 , V_41 ) ;
}
}
return V_96 ;
}
static int F_200 ( struct V_295 * V_296 , int V_297 ,
void T_4 * V_298 ,
T_5 * V_299 , T_6 * V_300 )
{
int * V_310 = V_296 -> V_260 ;
int V_3 = * V_310 ;
T_6 V_311 = * V_300 ;
int V_96 = F_197 ( V_296 , V_297 , V_298 , V_299 , V_300 ) ;
if ( V_297 && * V_310 != V_3 ) {
struct V_1 * V_1 = V_296 -> V_304 ;
if ( V_310 != & F_193 ( V_1 , V_48 ) ) {
if ( ! F_201 () ) {
* V_310 = V_3 ;
* V_300 = V_311 ;
return F_202 () ;
}
if ( V_310 == & F_192 ( V_1 , V_48 ) ) {
F_191 ( V_1 ) ;
} else {
struct V_275 * V_41 = V_296 -> V_303 ;
struct V_26 * V_27 =
F_24 ( V_41 , struct V_26 , V_41 ) ;
if ( * V_310 )
F_39 ( V_27 -> V_14 ) ;
F_184 ( V_1 ,
V_270 ,
V_27 -> V_14 -> V_85 ,
V_41 ) ;
}
F_94 () ;
F_199 ( V_1 ) ;
} else
F_184 ( V_1 , V_270 ,
V_291 ,
V_1 -> V_42 . V_43 ) ;
}
return V_96 ;
}
static int F_203 ( struct V_295 * V_296 , int V_297 ,
void T_4 * V_298 ,
T_5 * V_299 , T_6 * V_300 )
{
int * V_310 = V_296 -> V_260 ;
int V_3 = * V_310 ;
int V_96 = F_197 ( V_296 , V_297 , V_298 , V_299 , V_300 ) ;
struct V_1 * V_1 = V_296 -> V_304 ;
if ( V_297 && * V_310 != V_3 )
F_199 ( V_1 ) ;
return V_96 ;
}
static int F_204 ( struct V_1 * V_1 , char * V_312 ,
int V_85 , struct V_275 * V_313 )
{
int V_122 ;
struct V_314 * V_315 ;
char V_316 [ sizeof( L_6 ) + V_147 ] ;
V_315 = F_205 ( & V_317 , sizeof( * V_315 ) , V_28 ) ;
if ( ! V_315 )
goto V_40;
for ( V_122 = 0 ; V_122 < F_206 ( V_315 -> V_318 ) - 1 ; V_122 ++ ) {
V_315 -> V_318 [ V_122 ] . V_260 += ( char * ) V_313 - ( char * ) & V_275 ;
V_315 -> V_318 [ V_122 ] . V_303 = V_313 ;
V_315 -> V_318 [ V_122 ] . V_304 = V_1 ;
}
snprintf ( V_316 , sizeof( V_316 ) , L_7 , V_312 ) ;
V_315 -> V_319 = F_207 ( V_1 , V_316 , V_315 -> V_318 ) ;
if ( ! V_315 -> V_319 )
goto free;
V_313 -> V_44 = V_315 ;
F_184 ( V_1 , V_269 , V_85 , V_313 ) ;
return 0 ;
free:
F_26 ( V_315 ) ;
V_40:
return - V_83 ;
}
static void F_208 ( struct V_275 * V_41 )
{
struct V_314 * V_315 = V_41 -> V_44 ;
if ( ! V_315 )
return;
V_41 -> V_44 = NULL ;
F_209 ( V_315 -> V_319 ) ;
F_26 ( V_315 ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
int V_38 ;
if ( ! F_210 ( V_27 -> V_14 -> V_35 ) )
return - V_80 ;
V_38 = F_211 ( V_27 -> V_14 , V_27 -> V_45 , NULL ) ;
if ( V_38 )
return V_38 ;
V_38 = F_204 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
V_27 -> V_14 -> V_85 , & V_27 -> V_41 ) ;
if ( V_38 )
F_212 ( V_27 -> V_45 ) ;
return V_38 ;
}
static void F_20 ( struct V_26 * V_27 )
{
F_208 ( & V_27 -> V_41 ) ;
F_212 ( V_27 -> V_45 ) ;
}
static T_7 int F_213 ( struct V_1 * V_1 )
{
int V_38 ;
struct V_275 * V_268 , * V_320 ;
#ifdef F_214
struct V_295 * V_321 = V_322 ;
struct V_323 * V_324 ;
#endif
V_38 = - V_39 ;
V_268 = & V_275 ;
V_320 = & V_325 ;
if ( ! F_12 ( V_1 , & V_326 ) ) {
V_268 = F_205 ( V_268 , sizeof( V_275 ) , V_28 ) ;
if ( ! V_268 )
goto V_327;
V_320 = F_205 ( V_320 , sizeof( V_325 ) , V_28 ) ;
if ( ! V_320 )
goto V_328;
#ifdef F_214
V_321 = F_205 ( V_321 , sizeof( V_322 ) , V_28 ) ;
if ( ! V_321 )
goto V_329;
V_321 [ 0 ] . V_260 = & V_268 -> V_260 [ V_330 - 1 ] ;
V_321 [ 0 ] . V_303 = V_268 ;
V_321 [ 0 ] . V_304 = V_1 ;
#endif
}
#ifdef F_214
V_38 = F_204 ( V_1 , L_8 , V_289 , V_268 ) ;
if ( V_38 < 0 )
goto V_331;
V_38 = F_204 ( V_1 , L_9 ,
V_291 , V_320 ) ;
if ( V_38 < 0 )
goto V_332;
V_38 = - V_39 ;
V_324 = F_207 ( V_1 , L_10 , V_321 ) ;
if ( ! V_324 )
goto V_333;
V_1 -> V_42 . V_324 = V_324 ;
#endif
V_1 -> V_42 . V_290 = V_268 ;
V_1 -> V_42 . V_43 = V_320 ;
return 0 ;
#ifdef F_214
V_333:
F_208 ( V_320 ) ;
V_332:
F_208 ( V_268 ) ;
V_331:
if ( V_321 != V_322 )
F_26 ( V_321 ) ;
V_329:
#endif
if ( V_320 != & V_325 )
F_26 ( V_320 ) ;
V_328:
if ( V_268 != & V_275 )
F_26 ( V_268 ) ;
V_327:
return V_38 ;
}
static T_8 void F_215 ( struct V_1 * V_1 )
{
#ifdef F_214
struct V_295 * V_321 ;
V_321 = V_1 -> V_42 . V_324 -> V_334 ;
F_209 ( V_1 -> V_42 . V_324 ) ;
F_208 ( V_1 -> V_42 . V_43 ) ;
F_208 ( V_1 -> V_42 . V_290 ) ;
F_26 ( V_321 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_290 ) ;
}
void T_9 F_216 ( void )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_125 ; V_122 ++ )
F_217 ( & V_10 [ V_122 ] ) ;
F_218 ( & V_335 ) ;
F_219 ( V_336 , F_124 ) ;
F_220 ( & V_337 ) ;
F_65 ( V_82 , & V_81 , 0 ) ;
F_221 ( & V_338 ) ;
F_222 ( V_336 , V_76 , F_106 , NULL , NULL ) ;
F_222 ( V_336 , V_72 , F_81 , NULL , NULL ) ;
F_222 ( V_336 , V_339 , NULL , F_162 , NULL ) ;
F_222 ( V_336 , V_340 , F_185 ,
F_188 , NULL ) ;
}
