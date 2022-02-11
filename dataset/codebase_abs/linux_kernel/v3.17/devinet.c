static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
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
static int F_76 ( struct V_87 * V_88 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_77 ( V_88 -> V_89 ) ;
struct V_90 * V_91 [ V_92 + 1 ] ;
struct V_26 * V_37 ;
struct V_93 * V_94 ;
struct V_6 * V_7 , * * V_54 ;
int V_38 = - V_79 ;
F_5 () ;
V_38 = F_78 ( V_57 , sizeof( * V_94 ) , V_91 , V_92 , V_95 ) ;
if ( V_38 < 0 )
goto V_96;
V_94 = F_79 ( V_57 ) ;
V_37 = F_72 ( V_1 , V_94 -> V_97 ) ;
if ( V_37 == NULL ) {
V_38 = - V_98 ;
goto V_96;
}
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( V_91 [ V_99 ] &&
V_7 -> V_9 != F_80 ( V_91 [ V_99 ] ) )
continue;
if ( V_91 [ V_100 ] && F_81 ( V_91 [ V_100 ] , V_7 -> V_101 ) )
continue;
if ( V_91 [ V_102 ] &&
( V_94 -> V_103 != V_7 -> V_103 ||
! F_54 ( F_80 ( V_91 [ V_102 ] ) , V_7 ) ) )
continue;
F_56 ( V_37 , V_54 , 1 , V_57 , F_82 ( V_88 ) . V_58 ) ;
return 0 ;
}
V_38 = - V_104 ;
V_96:
return V_38 ;
}
static void F_83 ( struct V_105 * V_106 )
{
unsigned long V_107 , V_108 , V_74 , V_109 ;
struct V_6 * V_7 ;
struct V_110 * V_111 ;
int V_112 ;
V_107 = V_113 ;
V_108 = F_84 ( V_107 + V_114 ) ;
for ( V_112 = 0 ; V_112 < V_115 ; V_112 ++ ) {
bool V_116 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_117 ;
if ( V_7 -> V_64 & V_118 )
continue;
V_117 = ( V_107 - V_7 -> V_119 +
V_120 ) / V_121 ;
if ( V_7 -> V_122 != V_123 &&
V_117 >= V_7 -> V_122 ) {
V_116 = true ;
} else if ( V_7 -> V_124 ==
V_123 ) {
continue;
} else if ( V_117 >= V_7 -> V_124 ) {
if ( F_85 ( V_7 -> V_119 +
V_7 -> V_122 * V_121 , V_108 ) )
V_108 = V_7 -> V_119 +
V_7 -> V_122 * V_121 ;
if ( ! ( V_7 -> V_64 & V_125 ) )
V_116 = true ;
} else if ( F_85 ( V_7 -> V_119 +
V_7 -> V_124 * V_121 ,
V_108 ) ) {
V_108 = V_7 -> V_119 +
V_7 -> V_124 * V_121 ;
}
}
F_18 () ;
if ( ! V_116 )
continue;
F_86 () ;
F_87 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_117 ;
if ( V_7 -> V_64 & V_118 )
continue;
V_117 = ( V_107 - V_7 -> V_119 +
V_120 ) / V_121 ;
if ( V_7 -> V_122 != V_123 &&
V_117 >= V_7 -> V_122 ) {
struct V_6 * * V_54 ;
for ( V_54 = & V_7 -> V_15 -> V_31 ;
* V_54 != NULL ; V_54 = & ( * V_54 ) -> V_67 ) {
if ( * V_54 == V_7 ) {
F_48 ( V_7 -> V_15 ,
V_54 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_124 !=
V_123 &&
V_117 >= V_7 -> V_124 &&
! ( V_7 -> V_64 & V_125 ) ) {
V_7 -> V_64 |= V_125 ;
F_58 ( V_75 , V_7 , NULL , 0 ) ;
}
}
F_88 () ;
}
V_74 = F_84 ( V_108 ) ;
V_109 = V_108 ;
if ( F_85 ( V_74 , V_108 + V_126 ) )
V_109 = V_74 ;
V_107 = V_113 ;
if ( F_85 ( V_109 , V_107 + V_127 ) )
V_109 = V_107 + V_127 ;
F_65 ( V_81 , & V_80 ,
V_109 - V_107 ) ;
}
static void F_89 ( struct V_6 * V_7 , T_3 V_128 ,
T_3 V_129 )
{
unsigned long V_130 ;
V_7 -> V_64 &= ~ ( V_118 | V_125 ) ;
V_130 = F_90 ( V_128 , V_121 ) ;
if ( F_91 ( V_130 ) )
V_7 -> V_122 = V_130 ;
else
V_7 -> V_64 |= V_118 ;
V_130 = F_90 ( V_129 , V_121 ) ;
if ( F_91 ( V_130 ) ) {
if ( V_130 == 0 )
V_7 -> V_64 |= V_125 ;
V_7 -> V_124 = V_130 ;
}
V_7 -> V_119 = V_113 ;
if ( ! V_7 -> V_131 )
V_7 -> V_131 = V_7 -> V_119 ;
}
static struct V_6 * F_92 ( struct V_1 * V_1 , struct V_56 * V_57 ,
T_3 * V_132 , T_3 * V_133 )
{
struct V_90 * V_91 [ V_92 + 1 ] ;
struct V_6 * V_7 ;
struct V_93 * V_94 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_38 ;
V_38 = F_78 ( V_57 , sizeof( * V_94 ) , V_91 , V_92 , V_95 ) ;
if ( V_38 < 0 )
goto V_96;
V_94 = F_79 ( V_57 ) ;
V_38 = - V_79 ;
if ( V_94 -> V_103 > 32 || V_91 [ V_99 ] == NULL )
goto V_96;
V_14 = F_93 ( V_1 , V_94 -> V_97 ) ;
V_38 = - V_98 ;
if ( V_14 == NULL )
goto V_96;
V_37 = F_68 ( V_14 ) ;
V_38 = - V_82 ;
if ( V_37 == NULL )
goto V_96;
V_7 = F_21 () ;
if ( V_7 == NULL )
goto V_96;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_40 ( V_37 ) ;
if ( V_91 [ V_102 ] == NULL )
V_91 [ V_102 ] = V_91 [ V_99 ] ;
F_94 ( & V_7 -> V_8 ) ;
V_7 -> V_103 = V_94 -> V_103 ;
V_7 -> V_69 = F_95 ( V_94 -> V_103 ) ;
V_7 -> V_64 = V_91 [ V_134 ] ? F_96 ( V_91 [ V_134 ] ) :
V_94 -> V_64 ;
V_7 -> V_68 = V_94 -> V_68 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_80 ( V_91 [ V_99 ] ) ;
V_7 -> V_70 = F_80 ( V_91 [ V_102 ] ) ;
if ( V_91 [ V_135 ] )
V_7 -> V_136 = F_80 ( V_91 [ V_135 ] ) ;
if ( V_91 [ V_100 ] )
F_97 ( V_7 -> V_101 , V_91 [ V_100 ] , V_137 ) ;
else
memcpy ( V_7 -> V_101 , V_14 -> V_35 , V_137 ) ;
if ( V_91 [ V_138 ] ) {
struct V_139 * V_140 ;
V_140 = F_98 ( V_91 [ V_138 ] ) ;
if ( ! V_140 -> V_141 || V_140 -> V_142 > V_140 -> V_141 ) {
V_38 = - V_79 ;
goto V_143;
}
* V_132 = V_140 -> V_141 ;
* V_133 = V_140 -> V_142 ;
}
return V_7 ;
V_143:
F_27 ( V_7 ) ;
V_96:
return F_44 ( V_38 ) ;
}
static struct V_6 * F_99 ( struct V_6 * V_7 )
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
static int F_100 ( struct V_87 * V_88 , struct V_56 * V_57 )
{
struct V_1 * V_1 = F_77 ( V_88 -> V_89 ) ;
struct V_6 * V_7 ;
struct V_6 * V_144 ;
T_3 V_128 = V_123 ;
T_3 V_129 = V_123 ;
F_5 () ;
V_7 = F_92 ( V_1 , V_57 , & V_128 , & V_129 ) ;
if ( F_101 ( V_7 ) )
return F_102 ( V_7 ) ;
V_144 = F_99 ( V_7 ) ;
if ( ! V_144 ) {
F_89 ( V_7 , V_128 , V_129 ) ;
return F_62 ( V_7 , V_57 , F_82 ( V_88 ) . V_58 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_57 -> V_145 & V_146 ||
! ( V_57 -> V_145 & V_147 ) )
return - V_78 ;
V_7 = V_144 ;
F_89 ( V_7 , V_128 , V_129 ) ;
F_64 ( & V_80 ) ;
F_65 ( V_81 ,
& V_80 , 0 ) ;
F_58 ( V_75 , V_7 , V_57 , F_82 ( V_88 ) . V_58 ) ;
F_59 ( & V_72 , V_76 , V_7 ) ;
}
return 0 ;
}
static int F_103 ( T_2 V_2 )
{
int V_148 = - 1 ;
if ( F_104 ( V_2 ) )
V_148 = 0 ;
else {
T_3 V_149 = F_105 ( V_2 ) ;
if ( F_106 ( V_149 ) )
V_148 = 8 ;
else if ( F_107 ( V_149 ) )
V_148 = 16 ;
else if ( F_108 ( V_149 ) )
V_148 = 24 ;
}
return V_148 ;
}
int F_109 ( struct V_1 * V_1 , unsigned int V_150 , void T_4 * V_151 )
{
struct V_152 V_153 ;
struct V_154 V_155 ;
struct V_154 * sin = (struct V_154 * ) & V_153 . V_156 ;
struct V_26 * V_37 ;
struct V_6 * * V_54 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_157 ;
int V_158 = - V_159 ;
int V_160 = 0 ;
if ( F_110 ( & V_153 , V_151 , sizeof( struct V_152 ) ) )
goto V_40;
V_153 . V_161 [ V_137 - 1 ] = 0 ;
memcpy ( & V_155 , sin , sizeof( * sin ) ) ;
V_157 = strchr ( V_153 . V_161 , ':' ) ;
if ( V_157 )
* V_157 = 0 ;
F_111 ( V_1 , V_153 . V_161 ) ;
switch ( V_150 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_160 = ( V_155 . V_166 == V_167 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_166 = V_167 ;
break;
case V_168 :
V_158 = - V_169 ;
if ( ! F_112 ( V_1 -> V_170 , V_171 ) )
goto V_40;
break;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_158 = - V_169 ;
if ( ! F_112 ( V_1 -> V_170 , V_171 ) )
goto V_40;
V_158 = - V_79 ;
if ( sin -> V_166 != V_167 )
goto V_40;
break;
default:
V_158 = - V_79 ;
goto V_40;
}
F_86 () ;
V_158 = - V_98 ;
V_14 = F_113 ( V_1 , V_153 . V_161 ) ;
if ( ! V_14 )
goto V_176;
if ( V_157 )
* V_157 = ':' ;
V_37 = F_68 ( V_14 ) ;
if ( V_37 ) {
if ( V_160 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( ! strcmp ( V_153 . V_161 , V_7 -> V_101 ) &&
V_155 . V_177 . V_178 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_54 = & V_37 -> V_31 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 )
if ( ! strcmp ( V_153 . V_161 , V_7 -> V_101 ) )
break;
}
}
V_158 = - V_104 ;
if ( ! V_7 && V_150 != V_172 && V_150 != V_168 )
goto V_176;
switch ( V_150 ) {
case V_162 :
sin -> V_177 . V_178 = V_7 -> V_9 ;
goto V_179;
case V_163 :
sin -> V_177 . V_178 = V_7 -> V_136 ;
goto V_179;
case V_164 :
sin -> V_177 . V_178 = V_7 -> V_70 ;
goto V_179;
case V_165 :
sin -> V_177 . V_178 = V_7 -> V_69 ;
goto V_179;
case V_168 :
if ( V_157 ) {
V_158 = - V_104 ;
if ( ! V_7 )
break;
V_158 = 0 ;
if ( ! ( V_153 . V_180 & V_50 ) )
F_48 ( V_37 , V_54 , 1 ) ;
break;
}
V_158 = F_114 ( V_14 , V_153 . V_180 ) ;
break;
case V_172 :
V_158 = - V_79 ;
if ( F_103 ( sin -> V_177 . V_178 ) < 0 )
break;
if ( ! V_7 ) {
V_158 = - V_82 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_94 ( & V_7 -> V_8 ) ;
if ( V_157 )
memcpy ( V_7 -> V_101 , V_153 . V_161 , V_137 ) ;
else
memcpy ( V_7 -> V_101 , V_14 -> V_35 , V_137 ) ;
} else {
V_158 = 0 ;
if ( V_7 -> V_9 == sin -> V_177 . V_178 )
break;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_136 = 0 ;
V_7 -> V_68 = 0 ;
}
V_7 -> V_70 = V_7 -> V_9 = sin -> V_177 . V_178 ;
if ( ! ( V_14 -> V_49 & V_181 ) ) {
V_7 -> V_103 = F_103 ( V_7 -> V_70 ) ;
V_7 -> V_69 = F_95 ( V_7 -> V_103 ) ;
if ( ( V_14 -> V_49 & V_182 ) &&
V_7 -> V_103 < 31 )
V_7 -> V_136 = V_7 -> V_70 |
~ V_7 -> V_69 ;
} else {
V_7 -> V_103 = 32 ;
V_7 -> V_69 = F_95 ( 32 ) ;
}
F_89 ( V_7 , V_123 , V_123 ) ;
V_158 = F_67 ( V_14 , V_7 ) ;
break;
case V_173 :
V_158 = 0 ;
if ( V_7 -> V_136 != sin -> V_177 . V_178 ) {
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_136 = sin -> V_177 . V_178 ;
F_66 ( V_7 ) ;
}
break;
case V_174 :
V_158 = 0 ;
if ( V_7 -> V_70 == sin -> V_177 . V_178 )
break;
V_158 = - V_79 ;
if ( F_103 ( sin -> V_177 . V_178 ) < 0 )
break;
V_158 = 0 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_177 . V_178 ;
F_66 ( V_7 ) ;
break;
case V_175 :
V_158 = - V_79 ;
if ( F_115 ( sin -> V_177 . V_178 , 0 ) )
break;
V_158 = 0 ;
if ( V_7 -> V_69 != sin -> V_177 . V_178 ) {
T_2 V_183 = V_7 -> V_69 ;
F_48 ( V_37 , V_54 , 0 ) ;
V_7 -> V_69 = sin -> V_177 . V_178 ;
V_7 -> V_103 = F_116 ( V_7 -> V_69 ) ;
if ( ( V_14 -> V_49 & V_182 ) &&
( V_7 -> V_103 < 31 ) &&
( V_7 -> V_136 ==
( V_7 -> V_9 | ~ V_183 ) ) ) {
V_7 -> V_136 = ( V_7 -> V_9 |
~ sin -> V_177 . V_178 ) ;
}
F_66 ( V_7 ) ;
}
break;
}
V_176:
F_88 () ;
V_40:
return V_158 ;
V_179:
F_88 () ;
V_158 = F_117 ( V_151 , & V_153 , sizeof( struct V_152 ) ) ? - V_159 : 0 ;
goto V_40;
}
static int F_118 ( struct V_11 * V_14 , char T_4 * V_184 , int V_185 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_152 V_153 ;
int V_176 = 0 ;
if ( ! V_37 )
goto V_40;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( ! V_184 ) {
V_176 += sizeof( V_153 ) ;
continue;
}
if ( V_185 < ( int ) sizeof( V_153 ) )
break;
memset ( & V_153 , 0 , sizeof( struct V_152 ) ) ;
strcpy ( V_153 . V_161 , V_7 -> V_101 ) ;
( * (struct V_154 * ) & V_153 . V_156 ) . V_166 = V_167 ;
( * (struct V_154 * ) & V_153 . V_156 ) . V_177 . V_178 =
V_7 -> V_9 ;
if ( F_117 ( V_184 , & V_153 , sizeof( struct V_152 ) ) ) {
V_176 = - V_159 ;
break;
}
V_184 += sizeof( struct V_152 ) ;
V_185 -= sizeof( struct V_152 ) ;
V_176 += sizeof( struct V_152 ) ;
}
V_40:
return V_176 ;
}
T_2 F_119 ( const struct V_11 * V_14 , T_2 V_186 , int V_187 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
F_10 () ;
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
goto V_188;
F_53 (in_dev) {
if ( V_7 -> V_68 > V_187 )
continue;
if ( ! V_186 || F_54 ( V_186 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_37 ) ;
if ( V_2 )
goto V_189;
V_188:
F_121 (net, dev) {
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
continue;
F_53 (in_dev) {
if ( V_7 -> V_68 != V_190 &&
V_7 -> V_68 <= V_187 ) {
V_2 = V_7 -> V_9 ;
goto V_189;
}
} F_55 ( V_37 ) ;
}
V_189:
F_18 () ;
return V_2 ;
}
static T_2 F_122 ( struct V_26 * V_37 , T_2 V_186 ,
T_2 V_22 , int V_187 )
{
int V_191 = 0 ;
T_2 V_2 = 0 ;
F_123 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_68 <= V_187 ) {
V_2 = V_7 -> V_9 ;
if ( V_191 )
break;
}
if ( ! V_191 ) {
V_191 = ( ! V_22 || F_54 ( V_22 , V_7 ) ) &&
( ! V_186 || F_54 ( V_186 , V_7 ) ) ;
if ( V_191 && V_2 ) {
if ( V_22 || ! V_186 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_68 <= V_187 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_191 = 0 ;
}
}
} F_55 ( V_37 ) ;
return V_191 ? V_2 : 0 ;
}
T_2 F_124 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_186 , T_2 V_22 , int V_187 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 != NULL )
return F_122 ( V_37 , V_186 , V_22 , V_187 ) ;
F_10 () ;
F_121 (net, dev) {
V_37 = F_120 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_122 ( V_37 , V_186 , V_22 , V_187 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_125 ( struct V_192 * V_193 )
{
return F_126 ( & V_72 , V_193 ) ;
}
int F_127 ( struct V_192 * V_193 )
{
return F_128 ( & V_72 , V_193 ) ;
}
static void F_129 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_194 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_67 ) {
char V_195 [ V_137 ] , * V_196 ;
memcpy ( V_195 , V_7 -> V_101 , V_137 ) ;
memcpy ( V_7 -> V_101 , V_14 -> V_35 , V_137 ) ;
if ( V_194 ++ == 0 )
goto V_197;
V_196 = strchr ( V_195 , ':' ) ;
if ( V_196 == NULL ) {
sprintf ( V_195 , L_4 , V_194 ) ;
V_196 = V_195 ;
}
if ( strlen ( V_196 ) + strlen ( V_14 -> V_35 ) < V_137 )
strcat ( V_7 -> V_101 , V_196 ) ;
else
strcpy ( V_7 -> V_101 + ( V_137 - strlen ( V_196 ) - 1 ) , V_196 ) ;
V_197:
F_58 ( V_75 , V_7 , NULL , 0 ) ;
}
}
static bool F_130 ( unsigned int V_198 )
{
return V_198 >= 68 ;
}
static void F_131 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_67 ) {
F_132 ( V_199 , V_200 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_201 , NULL ) ;
}
}
static int F_133 ( struct V_192 * V_202 , unsigned long V_203 ,
void * V_204 )
{
struct V_11 * V_14 = F_134 ( V_204 ) ;
struct V_26 * V_37 = F_68 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_203 == V_205 ) {
V_37 = F_36 ( V_14 ) ;
if ( F_101 ( V_37 ) )
return F_135 ( F_102 ( V_37 ) ) ;
if ( V_14 -> V_49 & V_206 ) {
F_136 ( V_37 , V_207 , 1 ) ;
F_136 ( V_37 , V_208 , 1 ) ;
}
} else if ( V_203 == V_209 ) {
if ( F_130 ( V_14 -> V_198 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_40;
}
switch ( V_203 ) {
case V_205 :
F_33 ( L_5 , V_34 ) ;
F_49 ( V_14 -> V_51 , NULL ) ;
break;
case V_76 :
if ( ! F_130 ( V_14 -> V_198 ) )
break;
if ( V_14 -> V_49 & V_206 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_94 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_70 = F_137 ( V_210 ) ;
V_7 -> V_103 = 8 ;
V_7 -> V_69 = F_95 ( 8 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_68 = V_83 ;
memcpy ( V_7 -> V_101 , V_14 -> V_35 , V_137 ) ;
F_89 ( V_7 , V_123 ,
V_123 ) ;
F_69 ( V_37 ) ;
F_70 ( V_37 -> V_45 ) ;
F_66 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_211 :
if ( ! F_138 ( V_37 ) )
break;
case V_212 :
F_131 ( V_14 , V_37 ) ;
break;
case V_73 :
F_139 ( V_37 ) ;
break;
case V_213 :
F_140 ( V_37 ) ;
break;
case V_214 :
F_141 ( V_37 ) ;
break;
case V_209 :
if ( F_130 ( V_14 -> V_198 ) )
break;
case V_215 :
F_46 ( V_37 ) ;
break;
case V_216 :
F_129 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_40:
return V_217 ;
}
static T_5 F_142 ( void )
{
return F_143 ( sizeof( struct V_93 ) )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( V_137 )
+ F_144 ( 4 )
+ F_144 ( sizeof( struct V_139 ) ) ;
}
static inline T_1 F_145 ( unsigned long V_218 )
{
return ( V_218 - V_219 ) * 100UL / V_121 ;
}
static int F_146 ( struct V_87 * V_88 , unsigned long V_218 ,
unsigned long V_220 , T_1 V_221 , T_1 V_222 )
{
struct V_139 V_140 ;
V_140 . V_218 = F_145 ( V_218 ) ;
V_140 . V_220 = F_145 ( V_220 ) ;
V_140 . V_142 = V_221 ;
V_140 . V_141 = V_222 ;
return F_147 ( V_88 , V_138 , sizeof( V_140 ) , & V_140 ) ;
}
static int F_148 ( struct V_87 * V_88 , struct V_6 * V_7 ,
T_1 V_58 , T_1 V_223 , int V_203 , unsigned int V_49 )
{
struct V_93 * V_94 ;
struct V_56 * V_57 ;
T_1 V_221 , V_222 ;
V_57 = F_149 ( V_88 , V_58 , V_223 , V_203 , sizeof( * V_94 ) , V_49 ) ;
if ( V_57 == NULL )
return - V_224 ;
V_94 = F_79 ( V_57 ) ;
V_94 -> V_225 = V_167 ;
V_94 -> V_103 = V_7 -> V_103 ;
V_94 -> V_64 = V_7 -> V_64 ;
V_94 -> V_68 = V_7 -> V_68 ;
V_94 -> V_97 = V_7 -> V_15 -> V_14 -> V_84 ;
if ( ! ( V_94 -> V_64 & V_118 ) ) {
V_221 = V_7 -> V_124 ;
V_222 = V_7 -> V_122 ;
if ( V_221 != V_123 ) {
long V_226 = ( V_113 - V_7 -> V_119 ) / V_121 ;
if ( V_221 > V_226 )
V_221 -= V_226 ;
else
V_221 = 0 ;
if ( V_222 != V_123 ) {
if ( V_222 > V_226 )
V_222 -= V_226 ;
else
V_222 = 0 ;
}
}
} else {
V_221 = V_123 ;
V_222 = V_123 ;
}
if ( ( V_7 -> V_70 &&
F_150 ( V_88 , V_102 , V_7 -> V_70 ) ) ||
( V_7 -> V_9 &&
F_150 ( V_88 , V_99 , V_7 -> V_9 ) ) ||
( V_7 -> V_136 &&
F_150 ( V_88 , V_135 , V_7 -> V_136 ) ) ||
( V_7 -> V_101 [ 0 ] &&
F_151 ( V_88 , V_100 , V_7 -> V_101 ) ) ||
F_152 ( V_88 , V_134 , V_7 -> V_64 ) ||
F_146 ( V_88 , V_7 -> V_131 , V_7 -> V_119 ,
V_221 , V_222 ) )
goto V_227;
return F_153 ( V_88 , V_57 ) ;
V_227:
F_154 ( V_88 , V_57 ) ;
return - V_224 ;
}
static int F_155 ( struct V_87 * V_88 , struct V_228 * V_229 )
{
struct V_1 * V_1 = F_77 ( V_88 -> V_89 ) ;
int V_230 , V_231 ;
int V_232 , V_233 ;
int V_234 , V_235 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_6 * V_7 ;
struct V_236 * V_30 ;
V_231 = V_229 -> args [ 0 ] ;
V_233 = V_232 = V_229 -> args [ 1 ] ;
V_235 = V_234 = V_229 -> args [ 2 ] ;
for ( V_230 = V_231 ; V_230 < V_237 ; V_230 ++ , V_233 = 0 ) {
V_232 = 0 ;
V_30 = & V_1 -> V_238 [ V_230 ] ;
F_10 () ;
V_229 -> V_223 = F_156 ( & V_1 -> V_42 . V_239 ) ^
V_1 -> V_240 ;
F_11 (dev, head, index_hlist) {
if ( V_232 < V_233 )
goto V_241;
if ( V_230 > V_231 || V_232 > V_233 )
V_235 = 0 ;
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
goto V_241;
for ( V_7 = V_37 -> V_31 , V_234 = 0 ; V_7 ;
V_7 = V_7 -> V_67 , V_234 ++ ) {
if ( V_234 < V_235 )
continue;
if ( F_148 ( V_88 , V_7 ,
F_82 ( V_229 -> V_88 ) . V_58 ,
V_229 -> V_57 -> V_242 ,
V_75 , V_243 ) <= 0 ) {
F_18 () ;
goto V_176;
}
F_157 ( V_229 , F_158 ( V_88 ) ) ;
}
V_241:
V_232 ++ ;
}
F_18 () ;
}
V_176:
V_229 -> args [ 0 ] = V_230 ;
V_229 -> args [ 1 ] = V_232 ;
V_229 -> args [ 2 ] = V_234 ;
return V_88 -> V_185 ;
}
static void F_58 ( int V_203 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_87 * V_88 ;
T_1 V_223 = V_57 ? V_57 -> V_242 : 0 ;
int V_38 = - V_82 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_88 = F_159 ( F_142 () , V_28 ) ;
if ( V_88 == NULL )
goto V_96;
V_38 = F_148 ( V_88 , V_7 , V_58 , V_223 , V_203 , 0 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_224 ) ;
F_160 ( V_88 ) ;
goto V_96;
}
F_161 ( V_88 , V_1 , V_58 , V_244 , V_57 , V_28 ) ;
return;
V_96:
if ( V_38 < 0 )
F_162 ( V_1 , V_244 , V_38 ) ;
}
static T_5 F_163 ( const struct V_11 * V_14 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
if ( ! V_37 )
return 0 ;
return F_144 ( V_245 * 4 ) ;
}
static int F_164 ( struct V_87 * V_88 , const struct V_11 * V_14 )
{
struct V_26 * V_37 = F_74 ( V_14 -> V_51 ) ;
struct V_90 * V_246 ;
int V_112 ;
if ( ! V_37 )
return - V_247 ;
V_246 = F_165 ( V_88 , V_248 , V_245 * 4 ) ;
if ( V_246 == NULL )
return - V_224 ;
for ( V_112 = 0 ; V_112 < V_245 ; V_112 ++ )
( ( T_1 * ) F_98 ( V_246 ) ) [ V_112 ] = V_37 -> V_41 . V_249 [ V_112 ] ;
return 0 ;
}
static int F_166 ( const struct V_11 * V_14 ,
const struct V_90 * V_246 )
{
struct V_90 * V_52 , * V_91 [ V_250 + 1 ] ;
int V_38 , V_251 ;
if ( V_14 && ! F_68 ( V_14 ) )
return - V_252 ;
V_38 = F_167 ( V_91 , V_250 , V_246 , V_253 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_91 [ V_248 ] ) {
F_168 (a, tb[IFLA_INET_CONF], rem) {
int V_254 = F_169 ( V_52 ) ;
if ( F_170 ( V_52 ) < 4 )
return - V_79 ;
if ( V_254 <= 0 || V_254 > V_245 )
return - V_79 ;
}
}
return 0 ;
}
static int F_171 ( struct V_11 * V_14 , const struct V_90 * V_246 )
{
struct V_26 * V_37 = F_68 ( V_14 ) ;
struct V_90 * V_52 , * V_91 [ V_250 + 1 ] ;
int V_251 ;
if ( ! V_37 )
return - V_252 ;
if ( F_167 ( V_91 , V_250 , V_246 , NULL ) < 0 )
F_172 () ;
if ( V_91 [ V_248 ] ) {
F_168 (a, tb[IFLA_INET_CONF], rem)
F_173 ( V_37 , F_169 ( V_52 ) , F_96 ( V_52 ) ) ;
}
return 0 ;
}
static int F_174 ( int type )
{
int V_255 = F_143 ( sizeof( struct V_256 ) )
+ F_144 ( 4 ) ;
if ( type == - 1 || type == V_257 )
V_255 += F_144 ( 4 ) ;
if ( type == - 1 || type == V_258 )
V_255 += F_144 ( 4 ) ;
if ( type == - 1 || type == V_259 )
V_255 += F_144 ( 4 ) ;
if ( type == - 1 || type == V_260 )
V_255 += F_144 ( 4 ) ;
return V_255 ;
}
static int F_175 ( struct V_87 * V_88 , int V_84 ,
struct V_261 * V_262 , T_1 V_58 ,
T_1 V_223 , int V_203 , unsigned int V_49 ,
int type )
{
struct V_56 * V_57 ;
struct V_256 * V_263 ;
V_57 = F_149 ( V_88 , V_58 , V_223 , V_203 , sizeof( struct V_256 ) ,
V_49 ) ;
if ( V_57 == NULL )
return - V_224 ;
V_263 = F_79 ( V_57 ) ;
V_263 -> V_264 = V_167 ;
if ( F_176 ( V_88 , V_265 , V_84 ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_257 ) &&
F_176 ( V_88 , V_257 ,
F_38 ( * V_262 , V_48 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_258 ) &&
F_176 ( V_88 , V_258 ,
F_38 ( * V_262 , V_266 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_259 ) &&
F_176 ( V_88 , V_259 ,
F_38 ( * V_262 , V_267 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_260 ) &&
F_176 ( V_88 , V_260 ,
F_38 ( * V_262 , V_268 ) ) < 0 )
goto V_227;
return F_153 ( V_88 , V_57 ) ;
V_227:
F_154 ( V_88 , V_57 ) ;
return - V_224 ;
}
void F_177 ( struct V_1 * V_1 , int type , int V_84 ,
struct V_261 * V_262 )
{
struct V_87 * V_88 ;
int V_38 = - V_82 ;
V_88 = F_159 ( F_174 ( type ) , V_269 ) ;
if ( V_88 == NULL )
goto V_96;
V_38 = F_175 ( V_88 , V_84 , V_262 , 0 , 0 ,
V_270 , 0 , type ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_224 ) ;
F_160 ( V_88 ) ;
goto V_96;
}
F_161 ( V_88 , V_1 , 0 , V_271 , NULL , V_269 ) ;
return;
V_96:
if ( V_38 < 0 )
F_162 ( V_1 , V_271 , V_38 ) ;
}
static int F_178 ( struct V_87 * V_272 ,
struct V_56 * V_57 )
{
struct V_1 * V_1 = F_77 ( V_272 -> V_89 ) ;
struct V_90 * V_91 [ V_273 + 1 ] ;
struct V_256 * V_263 ;
struct V_87 * V_88 ;
struct V_261 * V_262 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_84 ;
int V_38 ;
V_38 = F_78 ( V_57 , sizeof( * V_263 ) , V_91 , V_273 ,
V_274 ) ;
if ( V_38 < 0 )
goto V_96;
V_38 = V_79 ;
if ( ! V_91 [ V_265 ] )
goto V_96;
V_84 = F_179 ( V_91 [ V_265 ] ) ;
switch ( V_84 ) {
case V_275 :
V_262 = V_1 -> V_42 . V_276 ;
break;
case V_277 :
V_262 = V_1 -> V_42 . V_43 ;
break;
default:
V_14 = F_93 ( V_1 , V_84 ) ;
if ( V_14 == NULL )
goto V_96;
V_37 = F_68 ( V_14 ) ;
if ( V_37 == NULL )
goto V_96;
V_262 = & V_37 -> V_41 ;
break;
}
V_38 = - V_82 ;
V_88 = F_159 ( F_174 ( - 1 ) , V_269 ) ;
if ( V_88 == NULL )
goto V_96;
V_38 = F_175 ( V_88 , V_84 , V_262 ,
F_82 ( V_272 ) . V_58 ,
V_57 -> V_242 , V_270 , 0 ,
- 1 ) ;
if ( V_38 < 0 ) {
F_30 ( V_38 == - V_224 ) ;
F_160 ( V_88 ) ;
goto V_96;
}
V_38 = F_180 ( V_88 , V_1 , F_82 ( V_272 ) . V_58 ) ;
V_96:
return V_38 ;
}
static int F_181 ( struct V_87 * V_88 ,
struct V_228 * V_229 )
{
struct V_1 * V_1 = F_77 ( V_88 -> V_89 ) ;
int V_230 , V_231 ;
int V_232 , V_233 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
struct V_236 * V_30 ;
V_231 = V_229 -> args [ 0 ] ;
V_233 = V_232 = V_229 -> args [ 1 ] ;
for ( V_230 = V_231 ; V_230 < V_237 ; V_230 ++ , V_233 = 0 ) {
V_232 = 0 ;
V_30 = & V_1 -> V_238 [ V_230 ] ;
F_10 () ;
V_229 -> V_223 = F_156 ( & V_1 -> V_42 . V_239 ) ^
V_1 -> V_240 ;
F_11 (dev, head, index_hlist) {
if ( V_232 < V_233 )
goto V_241;
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
goto V_241;
if ( F_175 ( V_88 , V_14 -> V_84 ,
& V_37 -> V_41 ,
F_82 ( V_229 -> V_88 ) . V_58 ,
V_229 -> V_57 -> V_242 ,
V_270 ,
V_243 ,
- 1 ) <= 0 ) {
F_18 () ;
goto V_176;
}
F_157 ( V_229 , F_158 ( V_88 ) ) ;
V_241:
V_232 ++ ;
}
F_18 () ;
}
if ( V_230 == V_237 ) {
if ( F_175 ( V_88 , V_275 ,
V_1 -> V_42 . V_276 ,
F_82 ( V_229 -> V_88 ) . V_58 ,
V_229 -> V_57 -> V_242 ,
V_270 , V_243 ,
- 1 ) <= 0 )
goto V_176;
else
V_230 ++ ;
}
if ( V_230 == V_237 + 1 ) {
if ( F_175 ( V_88 , V_277 ,
V_1 -> V_42 . V_43 ,
F_82 ( V_229 -> V_88 ) . V_58 ,
V_229 -> V_57 -> V_242 ,
V_270 , V_243 ,
- 1 ) <= 0 )
goto V_176;
else
V_230 ++ ;
}
V_176:
V_229 -> args [ 0 ] = V_230 ;
V_229 -> args [ 1 ] = V_232 ;
return V_88 -> V_185 ;
}
static void F_182 ( struct V_1 * V_1 , int V_112 )
{
struct V_11 * V_14 ;
F_10 () ;
F_121 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_120 ( V_14 ) ;
if ( V_37 && ! F_183 ( V_112 , V_37 -> V_41 . V_278 ) )
V_37 -> V_41 . V_249 [ V_112 ] = V_1 -> V_42 . V_43 -> V_249 [ V_112 ] ;
}
F_18 () ;
}
static void F_184 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_279 = F_185 ( V_1 , V_48 ) ;
F_185 ( V_1 , V_280 ) = ! V_279 ;
F_186 ( V_1 , V_48 ) = V_279 ;
F_177 ( V_1 , V_257 ,
V_275 ,
V_1 -> V_42 . V_276 ) ;
F_177 ( V_1 , V_257 ,
V_277 ,
V_1 -> V_42 . V_43 ) ;
F_187 (net, dev) {
struct V_26 * V_37 ;
if ( V_279 )
F_39 ( V_14 ) ;
F_10 () ;
V_37 = F_120 ( V_14 ) ;
if ( V_37 ) {
F_136 ( V_37 , V_48 , V_279 ) ;
F_177 ( V_1 , V_257 ,
V_14 -> V_84 , & V_37 -> V_41 ) ;
}
F_18 () ;
}
}
static int F_188 ( struct V_1 * V_1 , struct V_261 * V_41 )
{
if ( V_41 == V_1 -> V_42 . V_43 )
return V_277 ;
else if ( V_41 == V_1 -> V_42 . V_276 )
return V_275 ;
else {
struct V_26 * V_27
= F_24 ( V_41 , struct V_26 , V_41 ) ;
return V_27 -> V_14 -> V_84 ;
}
}
static int F_189 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int V_287 = * ( int * ) V_282 -> V_249 ;
int V_158 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
int V_288 = * ( int * ) V_282 -> V_249 ;
if ( V_283 ) {
struct V_261 * V_41 = V_282 -> V_289 ;
struct V_1 * V_1 = V_282 -> V_290 ;
int V_112 = ( int * ) V_282 -> V_249 - V_41 -> V_249 ;
int V_84 ;
F_191 ( V_112 , V_41 -> V_278 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_182 ( V_1 , V_112 ) ;
if ( V_112 == V_291 - 1 ||
V_112 == V_292 - 1 )
if ( ( V_288 == 0 ) && ( V_287 != 0 ) )
F_192 ( V_1 ) ;
if ( V_112 == V_293 - 1 &&
V_288 != V_287 ) {
V_84 = F_188 ( V_1 , V_41 ) ;
F_177 ( V_1 , V_258 ,
V_84 , V_41 ) ;
}
if ( V_112 == V_294 - 1 &&
V_288 != V_287 ) {
V_84 = F_188 ( V_1 , V_41 ) ;
F_177 ( V_1 , V_260 ,
V_84 , V_41 ) ;
}
}
return V_158 ;
}
static int F_193 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int * V_295 = V_282 -> V_249 ;
int V_3 = * V_295 ;
T_6 V_296 = * V_286 ;
int V_158 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
if ( V_283 && * V_295 != V_3 ) {
struct V_1 * V_1 = V_282 -> V_290 ;
if ( V_295 != & F_186 ( V_1 , V_48 ) ) {
if ( ! F_194 () ) {
* V_295 = V_3 ;
* V_286 = V_296 ;
return F_195 () ;
}
if ( V_295 == & F_185 ( V_1 , V_48 ) ) {
F_184 ( V_1 ) ;
} else {
struct V_261 * V_41 = V_282 -> V_289 ;
struct V_26 * V_27 =
F_24 ( V_41 , struct V_26 , V_41 ) ;
if ( * V_295 )
F_39 ( V_27 -> V_14 ) ;
F_177 ( V_1 ,
V_257 ,
V_27 -> V_14 -> V_84 ,
V_41 ) ;
}
F_88 () ;
F_192 ( V_1 ) ;
} else
F_177 ( V_1 , V_257 ,
V_277 ,
V_1 -> V_42 . V_43 ) ;
}
return V_158 ;
}
static int F_196 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int * V_295 = V_282 -> V_249 ;
int V_3 = * V_295 ;
int V_158 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
struct V_1 * V_1 = V_282 -> V_290 ;
if ( V_283 && * V_295 != V_3 )
F_192 ( V_1 ) ;
return V_158 ;
}
static int F_197 ( struct V_1 * V_1 , char * V_297 ,
struct V_261 * V_298 )
{
int V_112 ;
struct V_299 * V_300 ;
char V_301 [ sizeof( L_6 ) + V_137 ] ;
V_300 = F_198 ( & V_302 , sizeof( * V_300 ) , V_28 ) ;
if ( ! V_300 )
goto V_40;
for ( V_112 = 0 ; V_112 < F_199 ( V_300 -> V_303 ) - 1 ; V_112 ++ ) {
V_300 -> V_303 [ V_112 ] . V_249 += ( char * ) V_298 - ( char * ) & V_261 ;
V_300 -> V_303 [ V_112 ] . V_289 = V_298 ;
V_300 -> V_303 [ V_112 ] . V_290 = V_1 ;
}
snprintf ( V_301 , sizeof( V_301 ) , L_7 , V_297 ) ;
V_300 -> V_304 = F_200 ( V_1 , V_301 , V_300 -> V_303 ) ;
if ( ! V_300 -> V_304 )
goto free;
V_298 -> V_44 = V_300 ;
return 0 ;
free:
F_26 ( V_300 ) ;
V_40:
return - V_82 ;
}
static void F_201 ( struct V_261 * V_41 )
{
struct V_299 * V_300 = V_41 -> V_44 ;
if ( V_300 == NULL )
return;
V_41 -> V_44 = NULL ;
F_202 ( V_300 -> V_304 ) ;
F_26 ( V_300 ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
int V_38 ;
if ( ! F_203 ( V_27 -> V_14 -> V_35 ) )
return - V_79 ;
V_38 = F_204 ( V_27 -> V_14 , V_27 -> V_45 , NULL ) ;
if ( V_38 )
return V_38 ;
V_38 = F_197 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
& V_27 -> V_41 ) ;
if ( V_38 )
F_205 ( V_27 -> V_45 ) ;
return V_38 ;
}
static void F_20 ( struct V_26 * V_27 )
{
F_201 ( & V_27 -> V_41 ) ;
F_205 ( V_27 -> V_45 ) ;
}
static T_7 int F_206 ( struct V_1 * V_1 )
{
int V_38 ;
struct V_261 * V_305 , * V_306 ;
#ifdef F_207
struct V_281 * V_307 = V_308 ;
struct V_309 * V_310 ;
#endif
V_38 = - V_39 ;
V_305 = & V_261 ;
V_306 = & V_311 ;
if ( ! F_12 ( V_1 , & V_312 ) ) {
V_305 = F_198 ( V_305 , sizeof( V_261 ) , V_28 ) ;
if ( V_305 == NULL )
goto V_313;
V_306 = F_198 ( V_306 , sizeof( V_311 ) , V_28 ) ;
if ( V_306 == NULL )
goto V_314;
#ifdef F_207
V_307 = F_198 ( V_307 , sizeof( V_308 ) , V_28 ) ;
if ( V_307 == NULL )
goto V_315;
V_307 [ 0 ] . V_249 = & V_305 -> V_249 [ V_316 - 1 ] ;
V_307 [ 0 ] . V_289 = V_305 ;
V_307 [ 0 ] . V_290 = V_1 ;
#endif
}
#ifdef F_207
V_38 = F_197 ( V_1 , L_8 , V_305 ) ;
if ( V_38 < 0 )
goto V_317;
V_38 = F_197 ( V_1 , L_9 , V_306 ) ;
if ( V_38 < 0 )
goto V_318;
V_38 = - V_39 ;
V_310 = F_200 ( V_1 , L_10 , V_307 ) ;
if ( V_310 == NULL )
goto V_319;
V_1 -> V_42 . V_310 = V_310 ;
#endif
V_1 -> V_42 . V_276 = V_305 ;
V_1 -> V_42 . V_43 = V_306 ;
return 0 ;
#ifdef F_207
V_319:
F_201 ( V_306 ) ;
V_318:
F_201 ( V_305 ) ;
V_317:
if ( V_307 != V_308 )
F_26 ( V_307 ) ;
V_315:
#endif
if ( V_306 != & V_311 )
F_26 ( V_306 ) ;
V_314:
if ( V_305 != & V_261 )
F_26 ( V_305 ) ;
V_313:
return V_38 ;
}
static T_8 void F_208 ( struct V_1 * V_1 )
{
#ifdef F_207
struct V_281 * V_307 ;
V_307 = V_1 -> V_42 . V_310 -> V_320 ;
F_202 ( V_1 -> V_42 . V_310 ) ;
F_201 ( V_1 -> V_42 . V_43 ) ;
F_201 ( V_1 -> V_42 . V_276 ) ;
F_26 ( V_307 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_276 ) ;
}
void T_9 F_209 ( void )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < V_115 ; V_112 ++ )
F_210 ( & V_10 [ V_112 ] ) ;
F_211 ( & V_321 ) ;
F_212 ( V_322 , F_118 ) ;
F_213 ( & V_323 ) ;
F_65 ( V_81 , & V_80 , 0 ) ;
F_214 ( & V_324 ) ;
F_215 ( V_322 , V_75 , F_100 , NULL , NULL ) ;
F_215 ( V_322 , V_71 , F_76 , NULL , NULL ) ;
F_215 ( V_322 , V_325 , NULL , F_155 , NULL ) ;
F_215 ( V_322 , V_326 , F_178 ,
F_181 , NULL ) ;
}
