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
static int F_81 ( struct V_97 * V_98 , struct V_56 * V_57 ,
struct V_99 * V_100 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
struct V_101 * V_102 [ V_103 + 1 ] ;
struct V_26 * V_37 ;
struct V_104 * V_105 ;
struct V_6 * V_7 , * * V_54 ;
int V_38 = - V_80 ;
F_5 () ;
V_38 = F_83 ( V_57 , sizeof( * V_105 ) , V_102 , V_103 , V_106 ,
V_100 ) ;
if ( V_38 < 0 )
goto V_107;
V_105 = F_84 ( V_57 ) ;
V_37 = F_72 ( V_1 , V_105 -> V_108 ) ;
if ( ! V_37 ) {
V_38 = - V_109 ;
goto V_107;
}
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 ) {
if ( V_102 [ V_110 ] &&
V_7 -> V_9 != F_85 ( V_102 [ V_110 ] ) )
continue;
if ( V_102 [ V_111 ] && F_86 ( V_102 [ V_111 ] , V_7 -> V_112 ) )
continue;
if ( V_102 [ V_113 ] &&
( V_105 -> V_114 != V_7 -> V_114 ||
! F_54 ( F_85 ( V_102 [ V_113 ] ) , V_7 ) ) )
continue;
if ( F_87 ( V_7 -> V_71 ) )
F_76 ( V_1 -> V_42 . V_115 , false , V_7 ) ;
F_56 ( V_37 , V_54 , 1 , V_57 , F_88 ( V_98 ) . V_58 ) ;
return 0 ;
}
V_38 = - V_116 ;
V_107:
return V_38 ;
}
static void F_89 ( struct V_117 * V_118 )
{
unsigned long V_119 , V_120 , V_75 , V_121 ;
struct V_6 * V_7 ;
struct V_122 * V_123 ;
int V_124 ;
V_119 = V_125 ;
V_120 = F_90 ( V_119 + V_126 ) ;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
bool V_128 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_129 ;
if ( V_7 -> V_65 & V_130 )
continue;
V_129 = ( V_119 - V_7 -> V_131 +
V_132 ) / V_133 ;
if ( V_7 -> V_134 != V_135 &&
V_129 >= V_7 -> V_134 ) {
V_128 = true ;
} else if ( V_7 -> V_136 ==
V_135 ) {
continue;
} else if ( V_129 >= V_7 -> V_136 ) {
if ( F_91 ( V_7 -> V_131 +
V_7 -> V_134 * V_133 , V_120 ) )
V_120 = V_7 -> V_131 +
V_7 -> V_134 * V_133 ;
if ( ! ( V_7 -> V_65 & V_137 ) )
V_128 = true ;
} else if ( F_91 ( V_7 -> V_131 +
V_7 -> V_136 * V_133 ,
V_120 ) ) {
V_120 = V_7 -> V_131 +
V_7 -> V_136 * V_133 ;
}
}
F_18 () ;
if ( ! V_128 )
continue;
F_92 () ;
F_93 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_129 ;
if ( V_7 -> V_65 & V_130 )
continue;
V_129 = ( V_119 - V_7 -> V_131 +
V_132 ) / V_133 ;
if ( V_7 -> V_134 != V_135 &&
V_129 >= V_7 -> V_134 ) {
struct V_6 * * V_54 ;
for ( V_54 = & V_7 -> V_15 -> V_31 ;
* V_54 != NULL ; V_54 = & ( * V_54 ) -> V_68 ) {
if ( * V_54 == V_7 ) {
F_48 ( V_7 -> V_15 ,
V_54 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_136 !=
V_135 &&
V_129 >= V_7 -> V_136 &&
! ( V_7 -> V_65 & V_137 ) ) {
V_7 -> V_65 |= V_137 ;
F_58 ( V_76 , V_7 , NULL , 0 ) ;
}
}
F_94 () ;
}
V_75 = F_90 ( V_120 ) ;
V_121 = V_120 ;
if ( F_91 ( V_75 , V_120 + V_138 ) )
V_121 = V_75 ;
V_119 = V_125 ;
if ( F_91 ( V_121 , V_119 + V_139 ) )
V_121 = V_119 + V_139 ;
F_65 ( V_82 , & V_81 ,
V_121 - V_119 ) ;
}
static void F_95 ( struct V_6 * V_7 , T_3 V_140 ,
T_3 V_141 )
{
unsigned long V_142 ;
V_7 -> V_65 &= ~ ( V_130 | V_137 ) ;
V_142 = F_96 ( V_140 , V_133 ) ;
if ( F_97 ( V_142 ) )
V_7 -> V_134 = V_142 ;
else
V_7 -> V_65 |= V_130 ;
V_142 = F_96 ( V_141 , V_133 ) ;
if ( F_97 ( V_142 ) ) {
if ( V_142 == 0 )
V_7 -> V_65 |= V_137 ;
V_7 -> V_136 = V_142 ;
}
V_7 -> V_131 = V_125 ;
if ( ! V_7 -> V_143 )
V_7 -> V_143 = V_7 -> V_131 ;
}
static struct V_6 * F_98 ( struct V_1 * V_1 , struct V_56 * V_57 ,
T_3 * V_144 , T_3 * V_145 )
{
struct V_101 * V_102 [ V_103 + 1 ] ;
struct V_6 * V_7 ;
struct V_104 * V_105 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_105 ) , V_102 , V_103 , V_106 ,
NULL ) ;
if ( V_38 < 0 )
goto V_107;
V_105 = F_84 ( V_57 ) ;
V_38 = - V_80 ;
if ( V_105 -> V_114 > 32 || ! V_102 [ V_110 ] )
goto V_107;
V_14 = F_99 ( V_1 , V_105 -> V_108 ) ;
V_38 = - V_109 ;
if ( ! V_14 )
goto V_107;
V_37 = F_68 ( V_14 ) ;
V_38 = - V_83 ;
if ( ! V_37 )
goto V_107;
V_7 = F_21 () ;
if ( ! V_7 )
goto V_107;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_40 ( V_37 ) ;
if ( ! V_102 [ V_113 ] )
V_102 [ V_113 ] = V_102 [ V_110 ] ;
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_114 = V_105 -> V_114 ;
V_7 -> V_70 = F_101 ( V_105 -> V_114 ) ;
V_7 -> V_65 = V_102 [ V_146 ] ? F_102 ( V_102 [ V_146 ] ) :
V_105 -> V_65 ;
V_7 -> V_69 = V_105 -> V_69 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_85 ( V_102 [ V_110 ] ) ;
V_7 -> V_71 = F_85 ( V_102 [ V_113 ] ) ;
if ( V_102 [ V_147 ] )
V_7 -> V_148 = F_85 ( V_102 [ V_147 ] ) ;
if ( V_102 [ V_111 ] )
F_103 ( V_7 -> V_112 , V_102 [ V_111 ] , V_149 ) ;
else
memcpy ( V_7 -> V_112 , V_14 -> V_35 , V_149 ) ;
if ( V_102 [ V_150 ] ) {
struct V_151 * V_152 ;
V_152 = F_104 ( V_102 [ V_150 ] ) ;
if ( ! V_152 -> V_153 || V_152 -> V_154 > V_152 -> V_153 ) {
V_38 = - V_80 ;
goto V_155;
}
* V_144 = V_152 -> V_153 ;
* V_145 = V_152 -> V_154 ;
}
return V_7 ;
V_155:
F_27 ( V_7 ) ;
V_107:
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
static int F_106 ( struct V_97 * V_98 , struct V_56 * V_57 ,
struct V_99 * V_100 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
struct V_6 * V_7 ;
struct V_6 * V_156 ;
T_3 V_140 = V_135 ;
T_3 V_141 = V_135 ;
F_5 () ;
V_7 = F_98 ( V_1 , V_57 , & V_140 , & V_141 ) ;
if ( F_107 ( V_7 ) )
return F_108 ( V_7 ) ;
V_156 = F_105 ( V_7 ) ;
if ( ! V_156 ) {
F_95 ( V_7 , V_140 , V_141 ) ;
if ( V_7 -> V_65 & V_157 ) {
int V_96 = F_76 ( V_1 -> V_42 . V_115 ,
true , V_7 ) ;
if ( V_96 < 0 ) {
F_27 ( V_7 ) ;
return V_96 ;
}
}
return F_62 ( V_7 , V_57 , F_88 ( V_98 ) . V_58 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_57 -> V_158 & V_159 ||
! ( V_57 -> V_158 & V_160 ) )
return - V_79 ;
V_7 = V_156 ;
F_95 ( V_7 , V_140 , V_141 ) ;
F_64 ( & V_81 ) ;
F_65 ( V_82 ,
& V_81 , 0 ) ;
F_58 ( V_76 , V_7 , V_57 , F_88 ( V_98 ) . V_58 ) ;
}
return 0 ;
}
static int F_109 ( T_2 V_2 )
{
int V_161 = - 1 ;
if ( F_110 ( V_2 ) )
V_161 = 0 ;
else {
T_3 V_162 = F_111 ( V_2 ) ;
if ( F_112 ( V_162 ) )
V_161 = 8 ;
else if ( F_113 ( V_162 ) )
V_161 = 16 ;
else if ( F_114 ( V_162 ) )
V_161 = 24 ;
}
return V_161 ;
}
int F_115 ( struct V_1 * V_1 , unsigned int V_163 , void T_4 * V_164 )
{
struct V_165 V_166 ;
struct V_167 V_168 ;
struct V_167 * sin = (struct V_167 * ) & V_166 . V_169 ;
struct V_26 * V_37 ;
struct V_6 * * V_54 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_170 ;
int V_96 = - V_171 ;
int V_172 = 0 ;
if ( F_116 ( & V_166 , V_164 , sizeof( struct V_165 ) ) )
goto V_40;
V_166 . V_173 [ V_149 - 1 ] = 0 ;
memcpy ( & V_168 , sin , sizeof( * sin ) ) ;
V_170 = strchr ( V_166 . V_173 , ':' ) ;
if ( V_170 )
* V_170 = 0 ;
F_117 ( V_1 , V_166 . V_173 ) ;
switch ( V_163 ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_172 = ( V_168 . V_178 == V_179 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_178 = V_179 ;
break;
case V_180 :
V_96 = - V_181 ;
if ( ! F_118 ( V_1 -> V_182 , V_183 ) )
goto V_40;
break;
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_96 = - V_181 ;
if ( ! F_118 ( V_1 -> V_182 , V_183 ) )
goto V_40;
V_96 = - V_80 ;
if ( sin -> V_178 != V_179 )
goto V_40;
break;
default:
V_96 = - V_80 ;
goto V_40;
}
F_92 () ;
V_96 = - V_109 ;
V_14 = F_119 ( V_1 , V_166 . V_173 ) ;
if ( ! V_14 )
goto V_188;
if ( V_170 )
* V_170 = ':' ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
if ( V_172 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 ) {
if ( ! strcmp ( V_166 . V_173 , V_7 -> V_112 ) &&
V_168 . V_189 . V_94 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_68 )
if ( ! strcmp ( V_166 . V_173 , V_7 -> V_112 ) )
break;
}
}
V_96 = - V_116 ;
if ( ! V_7 && V_163 != V_184 && V_163 != V_180 )
goto V_188;
switch ( V_163 ) {
case V_174 :
sin -> V_189 . V_94 = V_7 -> V_9 ;
goto V_190;
case V_175 :
sin -> V_189 . V_94 = V_7 -> V_148 ;
goto V_190;
case V_176 :
sin -> V_189 . V_94 = V_7 -> V_71 ;
goto V_190;
case V_177 :
sin -> V_189 . V_94 = V_7 -> V_70 ;
goto V_190;
case V_180 :
if ( V_170 ) {
V_96 = - V_116 ;
if ( ! V_7 )
break;
V_96 = 0 ;
if ( ! ( V_166 . V_191 & V_50 ) )
F_48 ( V_37 , V_54 , 1 ) ;
break;
}
V_96 = F_120 ( V_14 , V_166 . V_191 ) ;
break;
case V_184 :
V_96 = - V_80 ;
if ( F_109 ( sin -> V_189 . V_94 ) < 0 )
break;
if ( ! V_7 ) {
V_96 = - V_83 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_100 ( & V_7 -> V_8 ) ;
if ( V_170 )
memcpy ( V_7 -> V_112 , V_166 . V_173 , V_149 ) ;
else
memcpy ( V_7 -> V_112 , V_14 -> V_35 , V_149 ) ;
} else {
V_96 = 0 ;
if ( V_7 -> V_9 == sin -> V_189 . V_94 )
break;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_148 = 0 ;
V_7 -> V_69 = 0 ;
}
V_7 -> V_71 = V_7 -> V_9 = sin -> V_189 . V_94 ;
if ( ! ( V_14 -> V_49 & V_192 ) ) {
V_7 -> V_114 = F_109 ( V_7 -> V_71 ) ;
V_7 -> V_70 = F_101 ( V_7 -> V_114 ) ;
if ( ( V_14 -> V_49 & V_193 ) &&
V_7 -> V_114 < 31 )
V_7 -> V_148 = V_7 -> V_71 |
~ V_7 -> V_70 ;
} else {
V_7 -> V_114 = 32 ;
V_7 -> V_70 = F_101 ( 32 ) ;
}
F_95 ( V_7 , V_135 , V_135 ) ;
V_96 = F_67 ( V_14 , V_7 ) ;
break;
case V_185 :
V_96 = 0 ;
if ( V_7 -> V_148 != sin -> V_189 . V_94 ) {
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_148 = sin -> V_189 . V_94 ;
F_66 ( V_7 ) ;
}
break;
case V_186 :
V_96 = 0 ;
if ( V_7 -> V_71 == sin -> V_189 . V_94 )
break;
V_96 = - V_80 ;
if ( F_109 ( sin -> V_189 . V_94 ) < 0 )
break;
V_96 = 0 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_71 = sin -> V_189 . V_94 ;
F_66 ( V_7 ) ;
break;
case V_187 :
V_96 = - V_80 ;
if ( F_121 ( sin -> V_189 . V_94 , 0 ) )
break;
V_96 = 0 ;
if ( V_7 -> V_70 != sin -> V_189 . V_94 ) {
T_2 V_194 = V_7 -> V_70 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_189 . V_94 ;
V_7 -> V_114 = F_122 ( V_7 -> V_70 ) ;
if ( ( V_14 -> V_49 & V_193 ) &&
( V_7 -> V_114 < 31 ) &&
( V_7 -> V_148 ==
( V_7 -> V_9 | ~ V_194 ) ) ) {
V_7 -> V_148 = ( V_7 -> V_9 |
~ sin -> V_189 . V_94 ) ;
}
F_66 ( V_7 ) ;
}
break;
}
V_188:
F_94 () ;
V_40:
return V_96 ;
V_190:
F_94 () ;
V_96 = F_123 ( V_164 , & V_166 , sizeof( struct V_165 ) ) ? - V_171 : 0 ;
goto V_40;
}
static int F_124 ( struct V_11 * V_14 , char T_4 * V_195 , int V_196 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_165 V_166 ;
int V_188 = 0 ;
if ( ! V_37 )
goto V_40;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_68 ) {
if ( ! V_195 ) {
V_188 += sizeof( V_166 ) ;
continue;
}
if ( V_196 < ( int ) sizeof( V_166 ) )
break;
memset ( & V_166 , 0 , sizeof( struct V_165 ) ) ;
strcpy ( V_166 . V_173 , V_7 -> V_112 ) ;
( * (struct V_167 * ) & V_166 . V_169 ) . V_178 = V_179 ;
( * (struct V_167 * ) & V_166 . V_169 ) . V_189 . V_94 =
V_7 -> V_9 ;
if ( F_123 ( V_195 , & V_166 , sizeof( struct V_165 ) ) ) {
V_188 = - V_171 ;
break;
}
V_195 += sizeof( struct V_165 ) ;
V_196 -= sizeof( struct V_165 ) ;
V_188 += sizeof( struct V_165 ) ;
}
V_40:
return V_188 ;
}
static T_2 F_125 ( const struct V_26 * V_37 ,
int V_197 )
{
F_53 (in_dev) {
if ( V_7 -> V_69 != V_198 &&
V_7 -> V_69 <= V_197 )
return V_7 -> V_9 ;
} F_55 ( V_37 ) ;
return 0 ;
}
T_2 F_126 ( const struct V_11 * V_14 , T_2 V_199 , int V_197 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
int V_200 ;
F_10 () ;
V_37 = F_127 ( V_14 ) ;
if ( ! V_37 )
goto V_201;
F_53 (in_dev) {
if ( V_7 -> V_69 > V_197 )
continue;
if ( ! V_199 || F_54 ( V_199 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_202;
V_201:
V_200 = F_128 ( V_14 ) ;
if ( V_200 &&
( V_14 = F_73 ( V_1 , V_200 ) ) &&
( V_37 = F_127 ( V_14 ) ) ) {
V_2 = F_125 ( V_37 , V_197 ) ;
if ( V_2 )
goto V_202;
}
F_129 (net, dev) {
if ( F_128 ( V_14 ) != V_200 )
continue;
V_37 = F_127 ( V_14 ) ;
if ( ! V_37 )
continue;
V_2 = F_125 ( V_37 , V_197 ) ;
if ( V_2 )
goto V_202;
}
V_202:
F_18 () ;
return V_2 ;
}
static T_2 F_130 ( struct V_26 * V_37 , T_2 V_199 ,
T_2 V_22 , int V_197 )
{
int V_203 = 0 ;
T_2 V_2 = 0 ;
F_131 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_69 <= V_197 ) {
V_2 = V_7 -> V_9 ;
if ( V_203 )
break;
}
if ( ! V_203 ) {
V_203 = ( ! V_22 || F_54 ( V_22 , V_7 ) ) &&
( ! V_199 || F_54 ( V_199 , V_7 ) ) ;
if ( V_203 && V_2 ) {
if ( V_22 || ! V_199 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_69 <= V_197 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_203 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_203 ? V_2 : 0 ;
}
T_2 F_132 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_199 , T_2 V_22 , int V_197 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 )
return F_130 ( V_37 , V_199 , V_22 , V_197 ) ;
F_10 () ;
F_129 (net, dev) {
V_37 = F_127 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_130 ( V_37 , V_199 , V_22 , V_197 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_133 ( struct V_204 * V_205 )
{
return F_134 ( & V_73 , V_205 ) ;
}
int F_135 ( struct V_204 * V_205 )
{
return F_136 ( & V_73 , V_205 ) ;
}
static void F_137 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_206 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_68 ) {
char V_207 [ V_149 ] , * V_208 ;
memcpy ( V_207 , V_7 -> V_112 , V_149 ) ;
memcpy ( V_7 -> V_112 , V_14 -> V_35 , V_149 ) ;
if ( V_206 ++ == 0 )
goto V_209;
V_208 = strchr ( V_207 , ':' ) ;
if ( ! V_208 ) {
sprintf ( V_207 , L_4 , V_206 ) ;
V_208 = V_207 ;
}
if ( strlen ( V_208 ) + strlen ( V_14 -> V_35 ) < V_149 )
strcat ( V_7 -> V_112 , V_208 ) ;
else
strcpy ( V_7 -> V_112 + ( V_149 - strlen ( V_208 ) - 1 ) , V_208 ) ;
V_209:
F_58 ( V_76 , V_7 , NULL , 0 ) ;
}
}
static bool F_138 ( unsigned int V_210 )
{
return V_210 >= 68 ;
}
static void F_139 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_68 ) {
F_140 ( V_211 , V_212 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_213 , NULL ) ;
}
}
static int F_141 ( struct V_204 * V_214 , unsigned long V_215 ,
void * V_216 )
{
struct V_11 * V_14 = F_142 ( V_216 ) ;
struct V_26 * V_37 = F_68 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_215 == V_217 ) {
V_37 = F_36 ( V_14 ) ;
if ( F_107 ( V_37 ) )
return F_143 ( F_108 ( V_37 ) ) ;
if ( V_14 -> V_49 & V_218 ) {
F_144 ( V_37 , V_219 , 1 ) ;
F_144 ( V_37 , V_220 , 1 ) ;
}
} else if ( V_215 == V_221 ) {
if ( F_138 ( V_14 -> V_210 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_40;
}
switch ( V_215 ) {
case V_217 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_14 -> V_51 , NULL ) ;
break;
case V_77 :
if ( ! F_138 ( V_14 -> V_210 ) )
break;
if ( V_14 -> V_49 & V_218 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_100 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_71 = F_145 ( V_222 ) ;
V_7 -> V_114 = 8 ;
V_7 -> V_70 = F_101 ( 8 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_69 = V_84 ;
memcpy ( V_7 -> V_112 , V_14 -> V_35 , V_149 ) ;
F_95 ( V_7 , V_135 ,
V_135 ) ;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_66 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_223 :
if ( ! F_146 ( V_37 ) )
break;
case V_224 :
F_139 ( V_14 , V_37 ) ;
break;
case V_74 :
F_147 ( V_37 ) ;
break;
case V_225 :
F_148 ( V_37 ) ;
break;
case V_226 :
F_149 ( V_37 ) ;
break;
case V_221 :
if ( F_138 ( V_14 -> V_210 ) )
break;
case V_227 :
F_46 ( V_37 ) ;
break;
case V_228 :
F_137 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_40:
return V_229 ;
}
static T_5 F_150 ( void )
{
return F_151 ( sizeof( struct V_104 ) )
+ F_152 ( 4 )
+ F_152 ( 4 )
+ F_152 ( 4 )
+ F_152 ( V_149 )
+ F_152 ( 4 )
+ F_152 ( sizeof( struct V_151 ) ) ;
}
static inline T_1 F_153 ( unsigned long V_230 )
{
return ( V_230 - V_231 ) * 100UL / V_133 ;
}
static int F_154 ( struct V_97 * V_98 , unsigned long V_230 ,
unsigned long V_232 , T_1 V_233 , T_1 V_234 )
{
struct V_151 V_152 ;
V_152 . V_230 = F_153 ( V_230 ) ;
V_152 . V_232 = F_153 ( V_232 ) ;
V_152 . V_154 = V_233 ;
V_152 . V_153 = V_234 ;
return F_155 ( V_98 , V_150 , sizeof( V_152 ) , & V_152 ) ;
}
static int F_156 ( struct V_97 * V_98 , struct V_6 * V_7 ,
T_1 V_58 , T_1 V_235 , int V_215 , unsigned int V_49 )
{
struct V_104 * V_105 ;
struct V_56 * V_57 ;
T_1 V_233 , V_234 ;
V_57 = F_157 ( V_98 , V_58 , V_235 , V_215 , sizeof( * V_105 ) , V_49 ) ;
if ( ! V_57 )
return - V_236 ;
V_105 = F_84 ( V_57 ) ;
V_105 -> V_237 = V_179 ;
V_105 -> V_114 = V_7 -> V_114 ;
V_105 -> V_65 = V_7 -> V_65 ;
V_105 -> V_69 = V_7 -> V_69 ;
V_105 -> V_108 = V_7 -> V_15 -> V_14 -> V_85 ;
if ( ! ( V_105 -> V_65 & V_130 ) ) {
V_233 = V_7 -> V_136 ;
V_234 = V_7 -> V_134 ;
if ( V_233 != V_135 ) {
long V_238 = ( V_125 - V_7 -> V_131 ) / V_133 ;
if ( V_233 > V_238 )
V_233 -= V_238 ;
else
V_233 = 0 ;
if ( V_234 != V_135 ) {
if ( V_234 > V_238 )
V_234 -= V_238 ;
else
V_234 = 0 ;
}
}
} else {
V_233 = V_135 ;
V_234 = V_135 ;
}
if ( ( V_7 -> V_71 &&
F_158 ( V_98 , V_113 , V_7 -> V_71 ) ) ||
( V_7 -> V_9 &&
F_158 ( V_98 , V_110 , V_7 -> V_9 ) ) ||
( V_7 -> V_148 &&
F_158 ( V_98 , V_147 , V_7 -> V_148 ) ) ||
( V_7 -> V_112 [ 0 ] &&
F_159 ( V_98 , V_111 , V_7 -> V_112 ) ) ||
F_160 ( V_98 , V_146 , V_7 -> V_65 ) ||
F_154 ( V_98 , V_7 -> V_143 , V_7 -> V_131 ,
V_233 , V_234 ) )
goto V_239;
F_161 ( V_98 , V_57 ) ;
return 0 ;
V_239:
F_162 ( V_98 , V_57 ) ;
return - V_236 ;
}
static int F_163 ( struct V_97 * V_98 , struct V_240 * V_241 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
int V_242 , V_243 ;
int V_244 , V_245 ;
int V_246 , V_247 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_6 * V_7 ;
struct V_248 * V_30 ;
V_243 = V_241 -> args [ 0 ] ;
V_245 = V_244 = V_241 -> args [ 1 ] ;
V_247 = V_246 = V_241 -> args [ 2 ] ;
for ( V_242 = V_243 ; V_242 < V_249 ; V_242 ++ , V_245 = 0 ) {
V_244 = 0 ;
V_30 = & V_1 -> V_250 [ V_242 ] ;
F_10 () ;
V_241 -> V_235 = F_164 ( & V_1 -> V_42 . V_251 ) ^
V_1 -> V_252 ;
F_11 (dev, head, index_hlist) {
if ( V_244 < V_245 )
goto V_253;
if ( V_242 > V_243 || V_244 > V_245 )
V_247 = 0 ;
V_37 = F_127 ( V_14 ) ;
if ( ! V_37 )
goto V_253;
for ( V_7 = V_37 -> V_31 , V_246 = 0 ; V_7 ;
V_7 = V_7 -> V_68 , V_246 ++ ) {
if ( V_246 < V_247 )
continue;
if ( F_156 ( V_98 , V_7 ,
F_88 ( V_241 -> V_98 ) . V_58 ,
V_241 -> V_57 -> V_254 ,
V_76 , V_255 ) < 0 ) {
F_18 () ;
goto V_188;
}
F_165 ( V_241 , F_166 ( V_98 ) ) ;
}
V_253:
V_244 ++ ;
}
F_18 () ;
}
V_188:
V_241 -> args [ 0 ] = V_242 ;
V_241 -> args [ 1 ] = V_244 ;
V_241 -> args [ 2 ] = V_246 ;
return V_98 -> V_196 ;
}
static void F_58 ( int V_215 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_97 * V_98 ;
T_1 V_235 = V_57 ? V_57 -> V_254 : 0 ;
int V_38 = - V_83 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_98 = F_167 ( F_150 () , V_28 ) ;
if ( ! V_98 )
goto V_107;
V_38 = F_156 ( V_98 , V_7 , V_58 , V_235 , V_215 , 0 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_236 ) ;
F_168 ( V_98 ) ;
goto V_107;
}
F_169 ( V_98 , V_1 , V_58 , V_256 , V_57 , V_28 ) ;
return;
V_107:
if ( V_38 < 0 )
F_170 ( V_1 , V_256 , V_38 ) ;
}
static T_5 F_171 ( const struct V_11 * V_14 ,
T_1 V_257 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
if ( ! V_37 )
return 0 ;
return F_152 ( V_258 * 4 ) ;
}
static int F_172 ( struct V_97 * V_98 , const struct V_11 * V_14 ,
T_1 V_257 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
struct V_101 * V_259 ;
int V_124 ;
if ( ! V_37 )
return - V_260 ;
V_259 = F_173 ( V_98 , V_261 , V_258 * 4 ) ;
if ( ! V_259 )
return - V_236 ;
for ( V_124 = 0 ; V_124 < V_258 ; V_124 ++ )
( ( T_1 * ) F_104 ( V_259 ) ) [ V_124 ] = V_37 -> V_41 . V_262 [ V_124 ] ;
return 0 ;
}
static int F_174 ( const struct V_11 * V_14 ,
const struct V_101 * V_259 )
{
struct V_101 * V_52 , * V_102 [ V_263 + 1 ] ;
int V_38 , V_264 ;
if ( V_14 && ! F_68 ( V_14 ) )
return - V_265 ;
V_38 = F_175 ( V_102 , V_263 , V_259 , V_266 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_102 [ V_261 ] ) {
F_176 (a, tb[IFLA_INET_CONF], rem) {
int V_267 = F_177 ( V_52 ) ;
if ( F_178 ( V_52 ) < 4 )
return - V_80 ;
if ( V_267 <= 0 || V_267 > V_258 )
return - V_80 ;
}
}
return 0 ;
}
static int F_179 ( struct V_11 * V_14 , const struct V_101 * V_259 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_101 * V_52 , * V_102 [ V_263 + 1 ] ;
int V_264 ;
if ( ! V_37 )
return - V_265 ;
if ( F_175 ( V_102 , V_263 , V_259 , NULL , NULL ) < 0 )
F_180 () ;
if ( V_102 [ V_261 ] ) {
F_176 (a, tb[IFLA_INET_CONF], rem)
F_181 ( V_37 , F_177 ( V_52 ) , F_102 ( V_52 ) ) ;
}
return 0 ;
}
static int F_182 ( int type )
{
int V_268 = F_151 ( sizeof( struct V_269 ) )
+ F_152 ( 4 ) ;
bool V_270 = false ;
if ( type == V_271 )
V_270 = true ;
if ( V_270 || type == V_272 )
V_268 += F_152 ( 4 ) ;
if ( V_270 || type == V_273 )
V_268 += F_152 ( 4 ) ;
if ( V_270 || type == V_274 )
V_268 += F_152 ( 4 ) ;
if ( V_270 || type == V_275 )
V_268 += F_152 ( 4 ) ;
if ( V_270 || type == V_276 )
V_268 += F_152 ( 4 ) ;
return V_268 ;
}
static int F_183 ( struct V_97 * V_98 , int V_85 ,
struct V_277 * V_278 , T_1 V_58 ,
T_1 V_235 , int V_215 , unsigned int V_49 ,
int type )
{
struct V_56 * V_57 ;
struct V_269 * V_279 ;
bool V_270 = false ;
V_57 = F_157 ( V_98 , V_58 , V_235 , V_215 , sizeof( struct V_269 ) ,
V_49 ) ;
if ( ! V_57 )
return - V_236 ;
if ( type == V_271 )
V_270 = true ;
V_279 = F_84 ( V_57 ) ;
V_279 -> V_280 = V_179 ;
if ( F_184 ( V_98 , V_281 , V_85 ) < 0 )
goto V_239;
if ( ! V_278 )
goto V_40;
if ( ( V_270 || type == V_272 ) &&
F_184 ( V_98 , V_272 ,
F_38 ( * V_278 , V_48 ) ) < 0 )
goto V_239;
if ( ( V_270 || type == V_273 ) &&
F_184 ( V_98 , V_273 ,
F_38 ( * V_278 , V_282 ) ) < 0 )
goto V_239;
if ( ( V_270 || type == V_274 ) &&
F_184 ( V_98 , V_274 ,
F_38 ( * V_278 , V_283 ) ) < 0 )
goto V_239;
if ( ( V_270 || type == V_275 ) &&
F_184 ( V_98 , V_275 ,
F_38 ( * V_278 , V_284 ) ) < 0 )
goto V_239;
if ( ( V_270 || type == V_276 ) &&
F_184 ( V_98 , V_276 ,
F_38 ( * V_278 , V_285 ) ) < 0 )
goto V_239;
V_40:
F_161 ( V_98 , V_57 ) ;
return 0 ;
V_239:
F_162 ( V_98 , V_57 ) ;
return - V_236 ;
}
void F_185 ( struct V_1 * V_1 , int V_215 , int type ,
int V_85 , struct V_277 * V_278 )
{
struct V_97 * V_98 ;
int V_38 = - V_83 ;
V_98 = F_167 ( F_182 ( type ) , V_28 ) ;
if ( ! V_98 )
goto V_107;
V_38 = F_183 ( V_98 , V_85 , V_278 , 0 , 0 ,
V_215 , 0 , type ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_236 ) ;
F_168 ( V_98 ) ;
goto V_107;
}
F_169 ( V_98 , V_1 , 0 , V_286 , NULL , V_28 ) ;
return;
V_107:
if ( V_38 < 0 )
F_170 ( V_1 , V_286 , V_38 ) ;
}
static int F_186 ( struct V_97 * V_287 ,
struct V_56 * V_57 ,
struct V_99 * V_100 )
{
struct V_1 * V_1 = F_82 ( V_287 -> V_89 ) ;
struct V_101 * V_102 [ V_288 + 1 ] ;
struct V_269 * V_279 ;
struct V_97 * V_98 ;
struct V_277 * V_278 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_85 ;
int V_38 ;
V_38 = F_83 ( V_57 , sizeof( * V_279 ) , V_102 , V_288 ,
V_289 , V_100 ) ;
if ( V_38 < 0 )
goto V_107;
V_38 = - V_80 ;
if ( ! V_102 [ V_281 ] )
goto V_107;
V_85 = F_187 ( V_102 [ V_281 ] ) ;
switch ( V_85 ) {
case V_290 :
V_278 = V_1 -> V_42 . V_291 ;
break;
case V_292 :
V_278 = V_1 -> V_42 . V_43 ;
break;
default:
V_14 = F_99 ( V_1 , V_85 ) ;
if ( ! V_14 )
goto V_107;
V_37 = F_68 ( V_14 ) ;
if ( ! V_37 )
goto V_107;
V_278 = & V_37 -> V_41 ;
break;
}
V_38 = - V_83 ;
V_98 = F_167 ( F_182 ( V_271 ) , V_28 ) ;
if ( ! V_98 )
goto V_107;
V_38 = F_183 ( V_98 , V_85 , V_278 ,
F_88 ( V_287 ) . V_58 ,
V_57 -> V_254 , V_293 , 0 ,
V_271 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_236 ) ;
F_168 ( V_98 ) ;
goto V_107;
}
V_38 = F_188 ( V_98 , V_1 , F_88 ( V_287 ) . V_58 ) ;
V_107:
return V_38 ;
}
static int F_189 ( struct V_97 * V_98 ,
struct V_240 * V_241 )
{
struct V_1 * V_1 = F_82 ( V_98 -> V_89 ) ;
int V_242 , V_243 ;
int V_244 , V_245 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_248 * V_30 ;
V_243 = V_241 -> args [ 0 ] ;
V_245 = V_244 = V_241 -> args [ 1 ] ;
for ( V_242 = V_243 ; V_242 < V_249 ; V_242 ++ , V_245 = 0 ) {
V_244 = 0 ;
V_30 = & V_1 -> V_250 [ V_242 ] ;
F_10 () ;
V_241 -> V_235 = F_164 ( & V_1 -> V_42 . V_251 ) ^
V_1 -> V_252 ;
F_11 (dev, head, index_hlist) {
if ( V_244 < V_245 )
goto V_253;
V_37 = F_127 ( V_14 ) ;
if ( ! V_37 )
goto V_253;
if ( F_183 ( V_98 , V_14 -> V_85 ,
& V_37 -> V_41 ,
F_88 ( V_241 -> V_98 ) . V_58 ,
V_241 -> V_57 -> V_254 ,
V_293 ,
V_255 ,
V_271 ) < 0 ) {
F_18 () ;
goto V_188;
}
F_165 ( V_241 , F_166 ( V_98 ) ) ;
V_253:
V_244 ++ ;
}
F_18 () ;
}
if ( V_242 == V_249 ) {
if ( F_183 ( V_98 , V_290 ,
V_1 -> V_42 . V_291 ,
F_88 ( V_241 -> V_98 ) . V_58 ,
V_241 -> V_57 -> V_254 ,
V_293 , V_255 ,
V_271 ) < 0 )
goto V_188;
else
V_242 ++ ;
}
if ( V_242 == V_249 + 1 ) {
if ( F_183 ( V_98 , V_292 ,
V_1 -> V_42 . V_43 ,
F_88 ( V_241 -> V_98 ) . V_58 ,
V_241 -> V_57 -> V_254 ,
V_293 , V_255 ,
V_271 ) < 0 )
goto V_188;
else
V_242 ++ ;
}
V_188:
V_241 -> args [ 0 ] = V_242 ;
V_241 -> args [ 1 ] = V_244 ;
return V_98 -> V_196 ;
}
static void F_190 ( struct V_1 * V_1 , int V_124 )
{
struct V_11 * V_14 ;
F_10 () ;
F_129 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_127 ( V_14 ) ;
if ( V_37 && ! F_191 ( V_124 , V_37 -> V_41 . V_294 ) )
V_37 -> V_41 . V_262 [ V_124 ] = V_1 -> V_42 . V_43 -> V_262 [ V_124 ] ;
}
F_18 () ;
}
static void F_192 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_295 = F_193 ( V_1 , V_48 ) ;
F_193 ( V_1 , V_296 ) = ! V_295 ;
F_194 ( V_1 , V_48 ) = V_295 ;
F_185 ( V_1 , V_293 ,
V_272 ,
V_290 ,
V_1 -> V_42 . V_291 ) ;
F_185 ( V_1 , V_293 ,
V_272 ,
V_292 ,
V_1 -> V_42 . V_43 ) ;
F_195 (net, dev) {
struct V_26 * V_37 ;
if ( V_295 )
F_39 ( V_14 ) ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
F_144 ( V_37 , V_48 , V_295 ) ;
F_185 ( V_1 , V_293 ,
V_272 ,
V_14 -> V_85 , & V_37 -> V_41 ) ;
}
}
}
static int F_196 ( struct V_1 * V_1 , struct V_277 * V_41 )
{
if ( V_41 == V_1 -> V_42 . V_43 )
return V_292 ;
else if ( V_41 == V_1 -> V_42 . V_291 )
return V_290 ;
else {
struct V_26 * V_27
= F_24 ( V_41 , struct V_26 , V_41 ) ;
return V_27 -> V_14 -> V_85 ;
}
}
static int F_197 ( struct V_297 * V_298 , int V_299 ,
void T_4 * V_300 ,
T_5 * V_301 , T_6 * V_302 )
{
int V_303 = * ( int * ) V_298 -> V_262 ;
int V_96 = F_198 ( V_298 , V_299 , V_300 , V_301 , V_302 ) ;
int V_304 = * ( int * ) V_298 -> V_262 ;
if ( V_299 ) {
struct V_277 * V_41 = V_298 -> V_305 ;
struct V_1 * V_1 = V_298 -> V_306 ;
int V_124 = ( int * ) V_298 -> V_262 - V_41 -> V_262 ;
int V_85 ;
F_199 ( V_124 , V_41 -> V_294 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_190 ( V_1 , V_124 ) ;
if ( V_124 == V_307 - 1 ||
V_124 == V_308 - 1 )
if ( ( V_304 == 0 ) && ( V_303 != 0 ) )
F_200 ( V_1 ) ;
if ( V_124 == V_309 - 1 &&
V_304 != V_303 ) {
V_85 = F_196 ( V_1 , V_41 ) ;
F_185 ( V_1 , V_293 ,
V_273 ,
V_85 , V_41 ) ;
}
if ( V_124 == V_310 - 1 &&
V_304 != V_303 ) {
V_85 = F_196 ( V_1 , V_41 ) ;
F_185 ( V_1 , V_293 ,
V_275 ,
V_85 , V_41 ) ;
}
if ( V_124 == V_311 - 1 &&
V_304 != V_303 ) {
V_85 = F_196 ( V_1 , V_41 ) ;
F_185 ( V_1 , V_293 ,
V_276 ,
V_85 , V_41 ) ;
}
}
return V_96 ;
}
static int F_201 ( struct V_297 * V_298 , int V_299 ,
void T_4 * V_300 ,
T_5 * V_301 , T_6 * V_302 )
{
int * V_312 = V_298 -> V_262 ;
int V_3 = * V_312 ;
T_6 V_313 = * V_302 ;
int V_96 = F_198 ( V_298 , V_299 , V_300 , V_301 , V_302 ) ;
if ( V_299 && * V_312 != V_3 ) {
struct V_1 * V_1 = V_298 -> V_306 ;
if ( V_312 != & F_194 ( V_1 , V_48 ) ) {
if ( ! F_202 () ) {
* V_312 = V_3 ;
* V_302 = V_313 ;
return F_203 () ;
}
if ( V_312 == & F_193 ( V_1 , V_48 ) ) {
F_192 ( V_1 ) ;
} else {
struct V_277 * V_41 = V_298 -> V_305 ;
struct V_26 * V_27 =
F_24 ( V_41 , struct V_26 , V_41 ) ;
if ( * V_312 )
F_39 ( V_27 -> V_14 ) ;
F_185 ( V_1 , V_293 ,
V_272 ,
V_27 -> V_14 -> V_85 ,
V_41 ) ;
}
F_94 () ;
F_200 ( V_1 ) ;
} else
F_185 ( V_1 , V_293 ,
V_272 ,
V_292 ,
V_1 -> V_42 . V_43 ) ;
}
return V_96 ;
}
static int F_204 ( struct V_297 * V_298 , int V_299 ,
void T_4 * V_300 ,
T_5 * V_301 , T_6 * V_302 )
{
int * V_312 = V_298 -> V_262 ;
int V_3 = * V_312 ;
int V_96 = F_198 ( V_298 , V_299 , V_300 , V_301 , V_302 ) ;
struct V_1 * V_1 = V_298 -> V_306 ;
if ( V_299 && * V_312 != V_3 )
F_200 ( V_1 ) ;
return V_96 ;
}
static int F_205 ( struct V_1 * V_1 , char * V_314 ,
int V_85 , struct V_277 * V_315 )
{
int V_124 ;
struct V_316 * V_317 ;
char V_318 [ sizeof( L_6 ) + V_149 ] ;
V_317 = F_206 ( & V_319 , sizeof( * V_317 ) , V_28 ) ;
if ( ! V_317 )
goto V_40;
for ( V_124 = 0 ; V_124 < F_207 ( V_317 -> V_320 ) - 1 ; V_124 ++ ) {
V_317 -> V_320 [ V_124 ] . V_262 += ( char * ) V_315 - ( char * ) & V_277 ;
V_317 -> V_320 [ V_124 ] . V_305 = V_315 ;
V_317 -> V_320 [ V_124 ] . V_306 = V_1 ;
}
snprintf ( V_318 , sizeof( V_318 ) , L_7 , V_314 ) ;
V_317 -> V_321 = F_208 ( V_1 , V_318 , V_317 -> V_320 ) ;
if ( ! V_317 -> V_321 )
goto free;
V_315 -> V_44 = V_317 ;
F_185 ( V_1 , V_293 , V_271 ,
V_85 , V_315 ) ;
return 0 ;
free:
F_26 ( V_317 ) ;
V_40:
return - V_83 ;
}
static void F_209 ( struct V_1 * V_1 ,
struct V_277 * V_41 , int V_85 )
{
struct V_316 * V_317 = V_41 -> V_44 ;
if ( V_317 ) {
V_41 -> V_44 = NULL ;
F_210 ( V_317 -> V_321 ) ;
F_26 ( V_317 ) ;
}
F_185 ( V_1 , V_322 , 0 , V_85 , NULL ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
int V_38 ;
if ( ! F_211 ( V_27 -> V_14 -> V_35 ) )
return - V_80 ;
V_38 = F_212 ( V_27 -> V_14 , V_27 -> V_45 , NULL ) ;
if ( V_38 )
return V_38 ;
V_38 = F_205 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
V_27 -> V_14 -> V_85 , & V_27 -> V_41 ) ;
if ( V_38 )
F_213 ( V_27 -> V_45 ) ;
return V_38 ;
}
static void F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_13 ( V_27 -> V_14 ) ;
F_209 ( V_1 , & V_27 -> V_41 , V_27 -> V_14 -> V_85 ) ;
F_213 ( V_27 -> V_45 ) ;
}
static T_7 int F_214 ( struct V_1 * V_1 )
{
int V_38 ;
struct V_277 * V_270 , * V_323 ;
#ifdef F_215
struct V_297 * V_324 = V_325 ;
struct V_326 * V_327 ;
#endif
V_38 = - V_39 ;
V_270 = & V_277 ;
V_323 = & V_328 ;
if ( ! F_12 ( V_1 , & V_329 ) ) {
V_270 = F_206 ( V_270 , sizeof( V_277 ) , V_28 ) ;
if ( ! V_270 )
goto V_330;
V_323 = F_206 ( V_323 , sizeof( V_328 ) , V_28 ) ;
if ( ! V_323 )
goto V_331;
#ifdef F_215
V_324 = F_206 ( V_324 , sizeof( V_325 ) , V_28 ) ;
if ( ! V_324 )
goto V_332;
V_324 [ 0 ] . V_262 = & V_270 -> V_262 [ V_333 - 1 ] ;
V_324 [ 0 ] . V_305 = V_270 ;
V_324 [ 0 ] . V_306 = V_1 ;
#endif
}
#ifdef F_215
V_38 = F_205 ( V_1 , L_8 , V_290 , V_270 ) ;
if ( V_38 < 0 )
goto V_334;
V_38 = F_205 ( V_1 , L_9 ,
V_292 , V_323 ) ;
if ( V_38 < 0 )
goto V_335;
V_38 = - V_39 ;
V_327 = F_208 ( V_1 , L_10 , V_324 ) ;
if ( ! V_327 )
goto V_336;
V_1 -> V_42 . V_327 = V_327 ;
#endif
V_1 -> V_42 . V_291 = V_270 ;
V_1 -> V_42 . V_43 = V_323 ;
return 0 ;
#ifdef F_215
V_336:
F_209 ( V_1 , V_323 , V_292 ) ;
V_335:
F_209 ( V_1 , V_270 , V_290 ) ;
V_334:
if ( V_324 != V_325 )
F_26 ( V_324 ) ;
V_332:
#endif
if ( V_323 != & V_328 )
F_26 ( V_323 ) ;
V_331:
if ( V_270 != & V_277 )
F_26 ( V_270 ) ;
V_330:
return V_38 ;
}
static T_8 void F_216 ( struct V_1 * V_1 )
{
#ifdef F_215
struct V_297 * V_324 ;
V_324 = V_1 -> V_42 . V_327 -> V_337 ;
F_210 ( V_1 -> V_42 . V_327 ) ;
F_209 ( V_1 , V_1 -> V_42 . V_43 ,
V_292 ) ;
F_209 ( V_1 , V_1 -> V_42 . V_291 ,
V_290 ) ;
F_26 ( V_324 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_291 ) ;
}
void T_9 F_217 ( void )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ )
F_218 ( & V_10 [ V_124 ] ) ;
F_219 ( & V_338 ) ;
F_220 ( V_339 , F_124 ) ;
F_221 ( & V_340 ) ;
F_65 ( V_82 , & V_81 , 0 ) ;
F_222 ( & V_341 ) ;
F_223 ( V_339 , V_76 , F_106 , NULL , NULL ) ;
F_223 ( V_339 , V_72 , F_81 , NULL , NULL ) ;
F_223 ( V_339 , V_342 , NULL , F_163 , NULL ) ;
F_223 ( V_339 , V_343 , F_186 ,
F_189 , NULL ) ;
}
