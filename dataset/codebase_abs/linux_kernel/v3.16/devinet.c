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
static void F_19 ( struct V_26 * V_27 )
{
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
F_5 () ;
V_37 = F_22 ( sizeof( * V_37 ) , V_28 ) ;
if ( ! V_37 )
goto V_38;
memcpy ( & V_37 -> V_39 , F_13 ( V_14 ) -> V_40 . V_41 ,
sizeof( V_37 -> V_39 ) ) ;
V_37 -> V_39 . V_42 = NULL ;
V_37 -> V_14 = V_14 ;
V_37 -> V_43 = F_37 ( V_14 , & V_44 ) ;
if ( ! V_37 -> V_43 )
goto V_45;
if ( F_38 ( V_37 -> V_39 , V_46 ) )
F_39 ( V_14 ) ;
F_17 ( V_14 ) ;
F_40 ( V_37 ) ;
F_19 ( V_37 ) ;
F_41 ( V_37 ) ;
if ( V_14 -> V_47 & V_48 )
F_42 ( V_37 ) ;
F_43 ( V_14 -> V_49 , V_37 ) ;
V_38:
return V_37 ;
V_45:
F_26 ( V_37 ) ;
V_37 = NULL ;
goto V_38;
}
static void F_44 ( struct V_29 * V_30 )
{
struct V_26 * V_27 = F_24 ( V_30 , struct V_26 , V_29 ) ;
F_25 ( V_27 ) ;
}
static void F_45 ( struct V_26 * V_37 )
{
struct V_6 * V_7 ;
struct V_11 * V_14 ;
F_5 () ;
V_14 = V_37 -> V_14 ;
V_37 -> V_36 = 1 ;
F_46 ( V_37 ) ;
while ( ( V_7 = V_37 -> V_31 ) != NULL ) {
F_47 ( V_37 , & V_37 -> V_31 , 0 ) ;
F_27 ( V_7 ) ;
}
F_48 ( V_14 -> V_49 , NULL ) ;
F_20 ( V_37 ) ;
F_49 ( & V_44 , V_37 -> V_43 ) ;
F_50 ( V_14 ) ;
F_28 ( & V_37 -> V_29 , F_44 ) ;
}
int F_51 ( struct V_26 * V_37 , T_2 V_50 , T_2 V_51 )
{
F_10 () ;
F_52 (in_dev) {
if ( F_53 ( V_50 , V_7 ) ) {
if ( ! V_51 || F_53 ( V_51 , V_7 ) ) {
F_18 () ;
return 1 ;
}
}
} F_54 ( V_37 ) ;
F_18 () ;
return 0 ;
}
static void F_55 ( struct V_26 * V_37 , struct V_6 * * V_52 ,
int V_53 , struct V_54 * V_55 , T_1 V_56 )
{
struct V_6 * V_57 = NULL ;
struct V_6 * V_7 , * V_58 = * V_52 ;
struct V_6 * V_59 = V_37 -> V_31 ;
struct V_6 * V_60 = NULL ;
int V_61 = F_56 ( V_37 ) ;
F_5 () ;
if ( ! ( V_58 -> V_62 & V_63 ) ) {
struct V_6 * * V_64 = & V_58 -> V_65 ;
while ( ( V_7 = * V_64 ) != NULL ) {
if ( ! ( V_7 -> V_62 & V_63 ) &&
V_58 -> V_66 <= V_7 -> V_66 )
V_59 = V_7 ;
if ( ! ( V_7 -> V_62 & V_63 ) ||
V_58 -> V_67 != V_7 -> V_67 ||
! F_53 ( V_58 -> V_68 , V_7 ) ) {
V_64 = & V_7 -> V_65 ;
V_60 = V_7 ;
continue;
}
if ( ! V_61 ) {
F_7 ( V_7 ) ;
* V_64 = V_7 -> V_65 ;
F_57 ( V_69 , V_7 , V_55 , V_56 ) ;
F_58 ( & V_70 ,
V_71 , V_7 ) ;
F_27 ( V_7 ) ;
} else {
V_57 = V_7 ;
break;
}
}
}
for ( V_7 = V_57 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_53 ( V_58 -> V_68 , V_7 ) )
F_59 ( V_7 , V_58 ) ;
}
* V_52 = V_58 -> V_65 ;
F_7 ( V_58 ) ;
F_57 ( V_69 , V_58 , V_55 , V_56 ) ;
F_58 ( & V_70 , V_71 , V_58 ) ;
if ( V_57 ) {
struct V_6 * V_72 = V_57 -> V_65 ;
if ( V_60 ) {
V_60 -> V_65 = V_57 -> V_65 ;
V_57 -> V_65 = V_59 -> V_65 ;
V_59 -> V_65 = V_57 ;
}
V_57 -> V_62 &= ~ V_63 ;
F_57 ( V_73 , V_57 , V_55 , V_56 ) ;
F_58 ( & V_70 ,
V_74 , V_57 ) ;
for ( V_7 = V_72 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( V_58 -> V_67 != V_7 -> V_67 ||
! F_53 ( V_58 -> V_68 , V_7 ) )
continue;
F_60 ( V_7 ) ;
}
}
if ( V_53 )
F_27 ( V_58 ) ;
}
static void F_47 ( struct V_26 * V_37 , struct V_6 * * V_52 ,
int V_53 )
{
F_55 ( V_37 , V_52 , V_53 , NULL , 0 ) ;
}
static int F_61 ( struct V_6 * V_7 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_58 , * * V_52 , * * V_75 ;
F_5 () ;
if ( ! V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return 0 ;
}
V_7 -> V_62 &= ~ V_63 ;
V_75 = & V_37 -> V_31 ;
for ( V_52 = & V_37 -> V_31 ; ( V_58 = * V_52 ) != NULL ;
V_52 = & V_58 -> V_65 ) {
if ( ! ( V_58 -> V_62 & V_63 ) &&
V_7 -> V_66 <= V_58 -> V_66 )
V_75 = & V_58 -> V_65 ;
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_53 ( V_58 -> V_68 , V_7 ) ) {
if ( V_58 -> V_9 == V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return - V_76 ;
}
if ( V_58 -> V_66 != V_7 -> V_66 ) {
F_27 ( V_7 ) ;
return - V_77 ;
}
V_7 -> V_62 |= V_63 ;
}
}
if ( ! ( V_7 -> V_62 & V_63 ) ) {
F_62 ( ( V_4 T_1 ) V_7 -> V_9 ) ;
V_52 = V_75 ;
}
V_7 -> V_65 = * V_52 ;
* V_52 = V_7 ;
F_4 ( F_13 ( V_37 -> V_14 ) , V_7 ) ;
F_63 ( & V_78 ) ;
F_64 ( V_79 , & V_78 , 0 ) ;
F_57 ( V_73 , V_7 , V_55 , V_56 ) ;
F_58 ( & V_70 , V_74 , V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_6 * V_7 )
{
return F_61 ( V_7 , NULL , 0 ) ;
}
static int F_66 ( struct V_11 * V_14 , struct V_6 * V_7 )
{
struct V_26 * V_37 = F_67 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
F_27 ( V_7 ) ;
return - V_80 ;
}
F_68 ( V_37 ) ;
F_69 ( V_37 -> V_43 ) ;
if ( V_7 -> V_15 != V_37 ) {
F_30 ( V_7 -> V_15 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
}
if ( F_70 ( V_7 -> V_9 ) )
V_7 -> V_66 = V_81 ;
return F_65 ( V_7 ) ;
}
struct V_26 * F_71 ( struct V_1 * V_1 , int V_82 )
{
struct V_11 * V_14 ;
struct V_26 * V_37 = NULL ;
F_10 () ;
V_14 = F_72 ( V_1 , V_82 ) ;
if ( V_14 )
V_37 = F_73 ( V_14 -> V_49 ) ;
F_18 () ;
return V_37 ;
}
struct V_6 * F_74 ( struct V_26 * V_37 , T_2 V_83 ,
T_2 V_84 )
{
F_5 () ;
F_52 (in_dev) {
if ( V_7 -> V_67 == V_84 && F_53 ( V_83 , V_7 ) )
return V_7 ;
} F_54 ( V_37 ) ;
return NULL ;
}
static int F_75 ( struct V_85 * V_86 , struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_86 -> V_87 ) ;
struct V_88 * V_89 [ V_90 + 1 ] ;
struct V_26 * V_37 ;
struct V_91 * V_92 ;
struct V_6 * V_7 , * * V_52 ;
int V_93 = - V_77 ;
F_5 () ;
V_93 = F_77 ( V_55 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_78 ( V_55 ) ;
V_37 = F_71 ( V_1 , V_92 -> V_96 ) ;
if ( V_37 == NULL ) {
V_93 = - V_97 ;
goto V_95;
}
for ( V_52 = & V_37 -> V_31 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 ) {
if ( V_89 [ V_98 ] &&
V_7 -> V_9 != F_79 ( V_89 [ V_98 ] ) )
continue;
if ( V_89 [ V_99 ] && F_80 ( V_89 [ V_99 ] , V_7 -> V_100 ) )
continue;
if ( V_89 [ V_101 ] &&
( V_92 -> V_102 != V_7 -> V_102 ||
! F_53 ( F_79 ( V_89 [ V_101 ] ) , V_7 ) ) )
continue;
F_55 ( V_37 , V_52 , 1 , V_55 , F_81 ( V_86 ) . V_56 ) ;
return 0 ;
}
V_93 = - V_103 ;
V_95:
return V_93 ;
}
static void F_82 ( struct V_104 * V_105 )
{
unsigned long V_106 , V_107 , V_72 , V_108 ;
struct V_6 * V_7 ;
struct V_109 * V_110 ;
int V_111 ;
V_106 = V_112 ;
V_107 = F_83 ( V_106 + V_113 ) ;
for ( V_111 = 0 ; V_111 < V_114 ; V_111 ++ ) {
bool V_115 = false ;
F_10 () ;
F_11 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_116 ;
if ( V_7 -> V_62 & V_117 )
continue;
V_116 = ( V_106 - V_7 -> V_118 +
V_119 ) / V_120 ;
if ( V_7 -> V_121 != V_122 &&
V_116 >= V_7 -> V_121 ) {
V_115 = true ;
} else if ( V_7 -> V_123 ==
V_122 ) {
continue;
} else if ( V_116 >= V_7 -> V_123 ) {
if ( F_84 ( V_7 -> V_118 +
V_7 -> V_121 * V_120 , V_107 ) )
V_107 = V_7 -> V_118 +
V_7 -> V_121 * V_120 ;
if ( ! ( V_7 -> V_62 & V_124 ) )
V_115 = true ;
} else if ( F_84 ( V_7 -> V_118 +
V_7 -> V_123 * V_120 ,
V_107 ) ) {
V_107 = V_7 -> V_118 +
V_7 -> V_123 * V_120 ;
}
}
F_18 () ;
if ( ! V_115 )
continue;
F_85 () ;
F_86 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_116 ;
if ( V_7 -> V_62 & V_117 )
continue;
V_116 = ( V_106 - V_7 -> V_118 +
V_119 ) / V_120 ;
if ( V_7 -> V_121 != V_122 &&
V_116 >= V_7 -> V_121 ) {
struct V_6 * * V_52 ;
for ( V_52 = & V_7 -> V_15 -> V_31 ;
* V_52 != NULL ; V_52 = & ( * V_52 ) -> V_65 ) {
if ( * V_52 == V_7 ) {
F_47 ( V_7 -> V_15 ,
V_52 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_123 !=
V_122 &&
V_116 >= V_7 -> V_123 &&
! ( V_7 -> V_62 & V_124 ) ) {
V_7 -> V_62 |= V_124 ;
F_57 ( V_73 , V_7 , NULL , 0 ) ;
}
}
F_87 () ;
}
V_72 = F_83 ( V_107 ) ;
V_108 = V_107 ;
if ( F_84 ( V_72 , V_107 + V_125 ) )
V_108 = V_72 ;
V_106 = V_112 ;
if ( F_84 ( V_108 , V_106 + V_126 ) )
V_108 = V_106 + V_126 ;
F_64 ( V_79 , & V_78 ,
V_108 - V_106 ) ;
}
static void F_88 ( struct V_6 * V_7 , T_3 V_127 ,
T_3 V_128 )
{
unsigned long V_129 ;
V_7 -> V_62 &= ~ ( V_117 | V_124 ) ;
V_129 = F_89 ( V_127 , V_120 ) ;
if ( F_90 ( V_129 ) )
V_7 -> V_121 = V_129 ;
else
V_7 -> V_62 |= V_117 ;
V_129 = F_89 ( V_128 , V_120 ) ;
if ( F_90 ( V_129 ) ) {
if ( V_129 == 0 )
V_7 -> V_62 |= V_124 ;
V_7 -> V_123 = V_129 ;
}
V_7 -> V_118 = V_112 ;
if ( ! V_7 -> V_130 )
V_7 -> V_130 = V_7 -> V_118 ;
}
static struct V_6 * F_91 ( struct V_1 * V_1 , struct V_54 * V_55 ,
T_3 * V_131 , T_3 * V_132 )
{
struct V_88 * V_89 [ V_90 + 1 ] ;
struct V_6 * V_7 ;
struct V_91 * V_92 ;
struct V_11 * V_14 ;
struct V_26 * V_37 ;
int V_93 ;
V_93 = F_77 ( V_55 , sizeof( * V_92 ) , V_89 , V_90 , V_94 ) ;
if ( V_93 < 0 )
goto V_95;
V_92 = F_78 ( V_55 ) ;
V_93 = - V_77 ;
if ( V_92 -> V_102 > 32 || V_89 [ V_98 ] == NULL )
goto V_95;
V_14 = F_92 ( V_1 , V_92 -> V_96 ) ;
V_93 = - V_97 ;
if ( V_14 == NULL )
goto V_95;
V_37 = F_67 ( V_14 ) ;
V_93 = - V_80 ;
if ( V_37 == NULL )
goto V_95;
V_7 = F_21 () ;
if ( V_7 == NULL )
goto V_95;
F_68 ( V_37 ) ;
F_69 ( V_37 -> V_43 ) ;
F_40 ( V_37 ) ;
if ( V_89 [ V_101 ] == NULL )
V_89 [ V_101 ] = V_89 [ V_98 ] ;
F_93 ( & V_7 -> V_8 ) ;
V_7 -> V_102 = V_92 -> V_102 ;
V_7 -> V_67 = F_94 ( V_92 -> V_102 ) ;
V_7 -> V_62 = V_89 [ V_133 ] ? F_95 ( V_89 [ V_133 ] ) :
V_92 -> V_62 ;
V_7 -> V_66 = V_92 -> V_66 ;
V_7 -> V_15 = V_37 ;
V_7 -> V_9 = F_79 ( V_89 [ V_98 ] ) ;
V_7 -> V_68 = F_79 ( V_89 [ V_101 ] ) ;
if ( V_89 [ V_134 ] )
V_7 -> V_135 = F_79 ( V_89 [ V_134 ] ) ;
if ( V_89 [ V_99 ] )
F_96 ( V_7 -> V_100 , V_89 [ V_99 ] , V_136 ) ;
else
memcpy ( V_7 -> V_100 , V_14 -> V_35 , V_136 ) ;
if ( V_89 [ V_137 ] ) {
struct V_138 * V_139 ;
V_139 = F_97 ( V_89 [ V_137 ] ) ;
if ( ! V_139 -> V_140 || V_139 -> V_141 > V_139 -> V_140 ) {
V_93 = - V_77 ;
goto V_142;
}
* V_131 = V_139 -> V_140 ;
* V_132 = V_139 -> V_141 ;
}
return V_7 ;
V_142:
F_27 ( V_7 ) ;
V_95:
return F_98 ( V_93 ) ;
}
static struct V_6 * F_99 ( struct V_6 * V_7 )
{
struct V_26 * V_37 = V_7 -> V_15 ;
struct V_6 * V_58 , * * V_52 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_52 = & V_37 -> V_31 ; ( V_58 = * V_52 ) != NULL ;
V_52 = & V_58 -> V_65 ) {
if ( V_58 -> V_67 == V_7 -> V_67 &&
F_53 ( V_58 -> V_68 , V_7 ) &&
V_58 -> V_9 == V_7 -> V_9 )
return V_58 ;
}
return NULL ;
}
static int F_100 ( struct V_85 * V_86 , struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_86 -> V_87 ) ;
struct V_6 * V_7 ;
struct V_6 * V_143 ;
T_3 V_127 = V_122 ;
T_3 V_128 = V_122 ;
F_5 () ;
V_7 = F_91 ( V_1 , V_55 , & V_127 , & V_128 ) ;
if ( F_101 ( V_7 ) )
return F_102 ( V_7 ) ;
V_143 = F_99 ( V_7 ) ;
if ( ! V_143 ) {
F_88 ( V_7 , V_127 , V_128 ) ;
return F_61 ( V_7 , V_55 , F_81 ( V_86 ) . V_56 ) ;
} else {
F_27 ( V_7 ) ;
if ( V_55 -> V_144 & V_145 ||
! ( V_55 -> V_144 & V_146 ) )
return - V_76 ;
V_7 = V_143 ;
F_88 ( V_7 , V_127 , V_128 ) ;
F_63 ( & V_78 ) ;
F_64 ( V_79 ,
& V_78 , 0 ) ;
F_57 ( V_73 , V_7 , V_55 , F_81 ( V_86 ) . V_56 ) ;
F_58 ( & V_70 , V_74 , V_7 ) ;
}
return 0 ;
}
static int F_103 ( T_2 V_2 )
{
int V_147 = - 1 ;
if ( F_104 ( V_2 ) )
V_147 = 0 ;
else {
T_3 V_148 = F_105 ( V_2 ) ;
if ( F_106 ( V_148 ) )
V_147 = 8 ;
else if ( F_107 ( V_148 ) )
V_147 = 16 ;
else if ( F_108 ( V_148 ) )
V_147 = 24 ;
}
return V_147 ;
}
int F_109 ( struct V_1 * V_1 , unsigned int V_149 , void T_4 * V_150 )
{
struct V_151 V_152 ;
struct V_153 V_154 ;
struct V_153 * sin = (struct V_153 * ) & V_152 . V_155 ;
struct V_26 * V_37 ;
struct V_6 * * V_52 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_11 * V_14 ;
char * V_156 ;
int V_157 = - V_158 ;
int V_159 = 0 ;
if ( F_110 ( & V_152 , V_150 , sizeof( struct V_151 ) ) )
goto V_38;
V_152 . V_160 [ V_136 - 1 ] = 0 ;
memcpy ( & V_154 , sin , sizeof( * sin ) ) ;
V_156 = strchr ( V_152 . V_160 , ':' ) ;
if ( V_156 )
* V_156 = 0 ;
F_111 ( V_1 , V_152 . V_160 ) ;
switch ( V_149 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_159 = ( V_154 . V_165 == V_166 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_165 = V_166 ;
break;
case V_167 :
V_157 = - V_168 ;
if ( ! F_112 ( V_1 -> V_169 , V_170 ) )
goto V_38;
break;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_157 = - V_168 ;
if ( ! F_112 ( V_1 -> V_169 , V_170 ) )
goto V_38;
V_157 = - V_77 ;
if ( sin -> V_165 != V_166 )
goto V_38;
break;
default:
V_157 = - V_77 ;
goto V_38;
}
F_85 () ;
V_157 = - V_97 ;
V_14 = F_113 ( V_1 , V_152 . V_160 ) ;
if ( ! V_14 )
goto V_175;
if ( V_156 )
* V_156 = ':' ;
V_37 = F_67 ( V_14 ) ;
if ( V_37 ) {
if ( V_159 ) {
for ( V_52 = & V_37 -> V_31 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 ) {
if ( ! strcmp ( V_152 . V_160 , V_7 -> V_100 ) &&
V_154 . V_176 . V_177 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_52 = & V_37 -> V_31 ; ( V_7 = * V_52 ) != NULL ;
V_52 = & V_7 -> V_65 )
if ( ! strcmp ( V_152 . V_160 , V_7 -> V_100 ) )
break;
}
}
V_157 = - V_103 ;
if ( ! V_7 && V_149 != V_171 && V_149 != V_167 )
goto V_175;
switch ( V_149 ) {
case V_161 :
sin -> V_176 . V_177 = V_7 -> V_9 ;
goto V_178;
case V_162 :
sin -> V_176 . V_177 = V_7 -> V_135 ;
goto V_178;
case V_163 :
sin -> V_176 . V_177 = V_7 -> V_68 ;
goto V_178;
case V_164 :
sin -> V_176 . V_177 = V_7 -> V_67 ;
goto V_178;
case V_167 :
if ( V_156 ) {
V_157 = - V_103 ;
if ( ! V_7 )
break;
V_157 = 0 ;
if ( ! ( V_152 . V_179 & V_48 ) )
F_47 ( V_37 , V_52 , 1 ) ;
break;
}
V_157 = F_114 ( V_14 , V_152 . V_179 ) ;
break;
case V_171 :
V_157 = - V_77 ;
if ( F_103 ( sin -> V_176 . V_177 ) < 0 )
break;
if ( ! V_7 ) {
V_157 = - V_80 ;
V_7 = F_21 () ;
if ( ! V_7 )
break;
F_93 ( & V_7 -> V_8 ) ;
if ( V_156 )
memcpy ( V_7 -> V_100 , V_152 . V_160 , V_136 ) ;
else
memcpy ( V_7 -> V_100 , V_14 -> V_35 , V_136 ) ;
} else {
V_157 = 0 ;
if ( V_7 -> V_9 == sin -> V_176 . V_177 )
break;
F_47 ( V_37 , V_52 , 0 ) ;
V_7 -> V_135 = 0 ;
V_7 -> V_66 = 0 ;
}
V_7 -> V_68 = V_7 -> V_9 = sin -> V_176 . V_177 ;
if ( ! ( V_14 -> V_47 & V_180 ) ) {
V_7 -> V_102 = F_103 ( V_7 -> V_68 ) ;
V_7 -> V_67 = F_94 ( V_7 -> V_102 ) ;
if ( ( V_14 -> V_47 & V_181 ) &&
V_7 -> V_102 < 31 )
V_7 -> V_135 = V_7 -> V_68 |
~ V_7 -> V_67 ;
} else {
V_7 -> V_102 = 32 ;
V_7 -> V_67 = F_94 ( 32 ) ;
}
F_88 ( V_7 , V_122 , V_122 ) ;
V_157 = F_66 ( V_14 , V_7 ) ;
break;
case V_172 :
V_157 = 0 ;
if ( V_7 -> V_135 != sin -> V_176 . V_177 ) {
F_47 ( V_37 , V_52 , 0 ) ;
V_7 -> V_135 = sin -> V_176 . V_177 ;
F_65 ( V_7 ) ;
}
break;
case V_173 :
V_157 = 0 ;
if ( V_7 -> V_68 == sin -> V_176 . V_177 )
break;
V_157 = - V_77 ;
if ( F_103 ( sin -> V_176 . V_177 ) < 0 )
break;
V_157 = 0 ;
F_47 ( V_37 , V_52 , 0 ) ;
V_7 -> V_68 = sin -> V_176 . V_177 ;
F_65 ( V_7 ) ;
break;
case V_174 :
V_157 = - V_77 ;
if ( F_115 ( sin -> V_176 . V_177 , 0 ) )
break;
V_157 = 0 ;
if ( V_7 -> V_67 != sin -> V_176 . V_177 ) {
T_2 V_182 = V_7 -> V_67 ;
F_47 ( V_37 , V_52 , 0 ) ;
V_7 -> V_67 = sin -> V_176 . V_177 ;
V_7 -> V_102 = F_116 ( V_7 -> V_67 ) ;
if ( ( V_14 -> V_47 & V_181 ) &&
( V_7 -> V_102 < 31 ) &&
( V_7 -> V_135 ==
( V_7 -> V_9 | ~ V_182 ) ) ) {
V_7 -> V_135 = ( V_7 -> V_9 |
~ sin -> V_176 . V_177 ) ;
}
F_65 ( V_7 ) ;
}
break;
}
V_175:
F_87 () ;
V_38:
return V_157 ;
V_178:
F_87 () ;
V_157 = F_117 ( V_150 , & V_152 , sizeof( struct V_151 ) ) ? - V_158 : 0 ;
goto V_38;
}
static int F_118 ( struct V_11 * V_14 , char T_4 * V_183 , int V_184 )
{
struct V_26 * V_37 = F_67 ( V_14 ) ;
struct V_6 * V_7 ;
struct V_151 V_152 ;
int V_175 = 0 ;
if ( ! V_37 )
goto V_38;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_65 ) {
if ( ! V_183 ) {
V_175 += sizeof( V_152 ) ;
continue;
}
if ( V_184 < ( int ) sizeof( V_152 ) )
break;
memset ( & V_152 , 0 , sizeof( struct V_151 ) ) ;
strcpy ( V_152 . V_160 , V_7 -> V_100 ) ;
( * (struct V_153 * ) & V_152 . V_155 ) . V_165 = V_166 ;
( * (struct V_153 * ) & V_152 . V_155 ) . V_176 . V_177 =
V_7 -> V_9 ;
if ( F_117 ( V_183 , & V_152 , sizeof( struct V_151 ) ) ) {
V_175 = - V_158 ;
break;
}
V_183 += sizeof( struct V_151 ) ;
V_184 -= sizeof( struct V_151 ) ;
V_175 += sizeof( struct V_151 ) ;
}
V_38:
return V_175 ;
}
T_2 F_119 ( const struct V_11 * V_14 , T_2 V_185 , int V_186 )
{
T_2 V_2 = 0 ;
struct V_26 * V_37 ;
struct V_1 * V_1 = F_13 ( V_14 ) ;
F_10 () ;
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
goto V_187;
F_52 (in_dev) {
if ( V_7 -> V_66 > V_186 )
continue;
if ( ! V_185 || F_53 ( V_185 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_54 ( V_37 ) ;
if ( V_2 )
goto V_188;
V_187:
F_121 (net, dev) {
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
continue;
F_52 (in_dev) {
if ( V_7 -> V_66 != V_189 &&
V_7 -> V_66 <= V_186 ) {
V_2 = V_7 -> V_9 ;
goto V_188;
}
} F_54 ( V_37 ) ;
}
V_188:
F_18 () ;
return V_2 ;
}
static T_2 F_122 ( struct V_26 * V_37 , T_2 V_185 ,
T_2 V_22 , int V_186 )
{
int V_190 = 0 ;
T_2 V_2 = 0 ;
F_123 (in_dev) {
if ( ! V_2 &&
( V_22 == V_7 -> V_9 || ! V_22 ) &&
V_7 -> V_66 <= V_186 ) {
V_2 = V_7 -> V_9 ;
if ( V_190 )
break;
}
if ( ! V_190 ) {
V_190 = ( ! V_22 || F_53 ( V_22 , V_7 ) ) &&
( ! V_185 || F_53 ( V_185 , V_7 ) ) ;
if ( V_190 && V_2 ) {
if ( V_22 || ! V_185 )
break;
if ( F_53 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_66 <= V_186 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_190 = 0 ;
}
}
} F_54 ( V_37 ) ;
return V_190 ? V_2 : 0 ;
}
T_2 F_124 ( struct V_1 * V_1 , struct V_26 * V_37 ,
T_2 V_185 , T_2 V_22 , int V_186 )
{
T_2 V_2 = 0 ;
struct V_11 * V_14 ;
if ( V_37 != NULL )
return F_122 ( V_37 , V_185 , V_22 , V_186 ) ;
F_10 () ;
F_121 (net, dev) {
V_37 = F_120 ( V_14 ) ;
if ( V_37 ) {
V_2 = F_122 ( V_37 , V_185 , V_22 , V_186 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_125 ( struct V_191 * V_192 )
{
return F_126 ( & V_70 , V_192 ) ;
}
int F_127 ( struct V_191 * V_192 )
{
return F_128 ( & V_70 , V_192 ) ;
}
static void F_129 ( struct V_11 * V_14 , struct V_26 * V_37 )
{
struct V_6 * V_7 ;
int V_193 = 0 ;
for ( V_7 = V_37 -> V_31 ; V_7 ; V_7 = V_7 -> V_65 ) {
char V_194 [ V_136 ] , * V_195 ;
memcpy ( V_194 , V_7 -> V_100 , V_136 ) ;
memcpy ( V_7 -> V_100 , V_14 -> V_35 , V_136 ) ;
if ( V_193 ++ == 0 )
goto V_196;
V_195 = strchr ( V_194 , ':' ) ;
if ( V_195 == NULL ) {
sprintf ( V_194 , L_4 , V_193 ) ;
V_195 = V_194 ;
}
if ( strlen ( V_195 ) + strlen ( V_14 -> V_35 ) < V_136 )
strcat ( V_7 -> V_100 , V_195 ) ;
else
strcpy ( V_7 -> V_100 + ( V_136 - strlen ( V_195 ) - 1 ) , V_195 ) ;
V_196:
F_57 ( V_73 , V_7 , NULL , 0 ) ;
}
}
static bool F_130 ( unsigned int V_197 )
{
return V_197 >= 68 ;
}
static void F_131 ( struct V_11 * V_14 ,
struct V_26 * V_37 )
{
struct V_6 * V_7 ;
for ( V_7 = V_37 -> V_31 ; V_7 ;
V_7 = V_7 -> V_65 ) {
F_132 ( V_198 , V_199 ,
V_7 -> V_9 , V_14 ,
V_7 -> V_9 , NULL ,
V_14 -> V_200 , NULL ) ;
}
}
static int F_133 ( struct V_191 * V_201 , unsigned long V_202 ,
void * V_203 )
{
struct V_11 * V_14 = F_134 ( V_203 ) ;
struct V_26 * V_37 = F_67 ( V_14 ) ;
F_5 () ;
if ( ! V_37 ) {
if ( V_202 == V_204 ) {
V_37 = F_36 ( V_14 ) ;
if ( ! V_37 )
return F_135 ( - V_205 ) ;
if ( V_14 -> V_47 & V_206 ) {
F_136 ( V_37 , V_207 , 1 ) ;
F_136 ( V_37 , V_208 , 1 ) ;
}
} else if ( V_202 == V_209 ) {
if ( F_130 ( V_14 -> V_197 ) )
V_37 = F_36 ( V_14 ) ;
}
goto V_38;
}
switch ( V_202 ) {
case V_204 :
F_33 ( L_5 , V_34 ) ;
F_48 ( V_14 -> V_49 , NULL ) ;
break;
case V_74 :
if ( ! F_130 ( V_14 -> V_197 ) )
break;
if ( V_14 -> V_47 & V_206 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_93 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_68 = F_137 ( V_210 ) ;
V_7 -> V_102 = 8 ;
V_7 -> V_67 = F_94 ( 8 ) ;
F_40 ( V_37 ) ;
V_7 -> V_15 = V_37 ;
V_7 -> V_66 = V_81 ;
memcpy ( V_7 -> V_100 , V_14 -> V_35 , V_136 ) ;
F_88 ( V_7 , V_122 ,
V_122 ) ;
F_68 ( V_37 ) ;
F_69 ( V_37 -> V_43 ) ;
F_65 ( V_7 ) ;
}
}
F_42 ( V_37 ) ;
case V_211 :
if ( ! F_138 ( V_37 ) )
break;
case V_212 :
F_131 ( V_14 , V_37 ) ;
break;
case V_71 :
F_139 ( V_37 ) ;
break;
case V_213 :
F_140 ( V_37 ) ;
break;
case V_214 :
F_141 ( V_37 ) ;
break;
case V_209 :
if ( F_130 ( V_14 -> V_197 ) )
break;
case V_215 :
F_45 ( V_37 ) ;
break;
case V_216 :
F_129 ( V_14 , V_37 ) ;
F_20 ( V_37 ) ;
F_19 ( V_37 ) ;
break;
}
V_38:
return V_217 ;
}
static T_5 F_142 ( void )
{
return F_143 ( sizeof( struct V_91 ) )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( 4 )
+ F_144 ( V_136 )
+ F_144 ( 4 )
+ F_144 ( sizeof( struct V_138 ) ) ;
}
static inline T_1 F_145 ( unsigned long V_218 )
{
return ( V_218 - V_219 ) * 100UL / V_120 ;
}
static int F_146 ( struct V_85 * V_86 , unsigned long V_218 ,
unsigned long V_220 , T_1 V_221 , T_1 V_222 )
{
struct V_138 V_139 ;
V_139 . V_218 = F_145 ( V_218 ) ;
V_139 . V_220 = F_145 ( V_220 ) ;
V_139 . V_141 = V_221 ;
V_139 . V_140 = V_222 ;
return F_147 ( V_86 , V_137 , sizeof( V_139 ) , & V_139 ) ;
}
static int F_148 ( struct V_85 * V_86 , struct V_6 * V_7 ,
T_1 V_56 , T_1 V_223 , int V_202 , unsigned int V_47 )
{
struct V_91 * V_92 ;
struct V_54 * V_55 ;
T_1 V_221 , V_222 ;
V_55 = F_149 ( V_86 , V_56 , V_223 , V_202 , sizeof( * V_92 ) , V_47 ) ;
if ( V_55 == NULL )
return - V_224 ;
V_92 = F_78 ( V_55 ) ;
V_92 -> V_225 = V_166 ;
V_92 -> V_102 = V_7 -> V_102 ;
V_92 -> V_62 = V_7 -> V_62 ;
V_92 -> V_66 = V_7 -> V_66 ;
V_92 -> V_96 = V_7 -> V_15 -> V_14 -> V_82 ;
if ( ! ( V_92 -> V_62 & V_117 ) ) {
V_221 = V_7 -> V_123 ;
V_222 = V_7 -> V_121 ;
if ( V_221 != V_122 ) {
long V_226 = ( V_112 - V_7 -> V_118 ) / V_120 ;
if ( V_221 > V_226 )
V_221 -= V_226 ;
else
V_221 = 0 ;
if ( V_222 != V_122 ) {
if ( V_222 > V_226 )
V_222 -= V_226 ;
else
V_222 = 0 ;
}
}
} else {
V_221 = V_122 ;
V_222 = V_122 ;
}
if ( ( V_7 -> V_68 &&
F_150 ( V_86 , V_101 , V_7 -> V_68 ) ) ||
( V_7 -> V_9 &&
F_150 ( V_86 , V_98 , V_7 -> V_9 ) ) ||
( V_7 -> V_135 &&
F_150 ( V_86 , V_134 , V_7 -> V_135 ) ) ||
( V_7 -> V_100 [ 0 ] &&
F_151 ( V_86 , V_99 , V_7 -> V_100 ) ) ||
F_152 ( V_86 , V_133 , V_7 -> V_62 ) ||
F_146 ( V_86 , V_7 -> V_130 , V_7 -> V_118 ,
V_221 , V_222 ) )
goto V_227;
return F_153 ( V_86 , V_55 ) ;
V_227:
F_154 ( V_86 , V_55 ) ;
return - V_224 ;
}
static int F_155 ( struct V_85 * V_86 , struct V_228 * V_229 )
{
struct V_1 * V_1 = F_76 ( V_86 -> V_87 ) ;
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
V_229 -> V_223 = F_156 ( & V_1 -> V_40 . V_239 ) ^
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
V_7 = V_7 -> V_65 , V_234 ++ ) {
if ( V_234 < V_235 )
continue;
if ( F_148 ( V_86 , V_7 ,
F_81 ( V_229 -> V_86 ) . V_56 ,
V_229 -> V_55 -> V_242 ,
V_73 , V_243 ) <= 0 ) {
F_18 () ;
goto V_175;
}
F_157 ( V_229 , F_158 ( V_86 ) ) ;
}
V_241:
V_232 ++ ;
}
F_18 () ;
}
V_175:
V_229 -> args [ 0 ] = V_230 ;
V_229 -> args [ 1 ] = V_232 ;
V_229 -> args [ 2 ] = V_234 ;
return V_86 -> V_184 ;
}
static void F_57 ( int V_202 , struct V_6 * V_7 , struct V_54 * V_55 ,
T_1 V_56 )
{
struct V_85 * V_86 ;
T_1 V_223 = V_55 ? V_55 -> V_242 : 0 ;
int V_93 = - V_80 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_15 -> V_14 ) ;
V_86 = F_159 ( F_142 () , V_28 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_148 ( V_86 , V_7 , V_56 , V_223 , V_202 , 0 ) ;
if ( V_93 < 0 ) {
F_30 ( V_93 == - V_224 ) ;
F_160 ( V_86 ) ;
goto V_95;
}
F_161 ( V_86 , V_1 , V_56 , V_244 , V_55 , V_28 ) ;
return;
V_95:
if ( V_93 < 0 )
F_162 ( V_1 , V_244 , V_93 ) ;
}
static T_5 F_163 ( const struct V_11 * V_14 )
{
struct V_26 * V_37 = F_73 ( V_14 -> V_49 ) ;
if ( ! V_37 )
return 0 ;
return F_144 ( V_245 * 4 ) ;
}
static int F_164 ( struct V_85 * V_86 , const struct V_11 * V_14 )
{
struct V_26 * V_37 = F_73 ( V_14 -> V_49 ) ;
struct V_88 * V_246 ;
int V_111 ;
if ( ! V_37 )
return - V_247 ;
V_246 = F_165 ( V_86 , V_248 , V_245 * 4 ) ;
if ( V_246 == NULL )
return - V_224 ;
for ( V_111 = 0 ; V_111 < V_245 ; V_111 ++ )
( ( T_1 * ) F_97 ( V_246 ) ) [ V_111 ] = V_37 -> V_39 . V_249 [ V_111 ] ;
return 0 ;
}
static int F_166 ( const struct V_11 * V_14 ,
const struct V_88 * V_246 )
{
struct V_88 * V_50 , * V_89 [ V_250 + 1 ] ;
int V_93 , V_251 ;
if ( V_14 && ! F_67 ( V_14 ) )
return - V_252 ;
V_93 = F_167 ( V_89 , V_250 , V_246 , V_253 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_89 [ V_248 ] ) {
F_168 (a, tb[IFLA_INET_CONF], rem) {
int V_254 = F_169 ( V_50 ) ;
if ( F_170 ( V_50 ) < 4 )
return - V_77 ;
if ( V_254 <= 0 || V_254 > V_245 )
return - V_77 ;
}
}
return 0 ;
}
static int F_171 ( struct V_11 * V_14 , const struct V_88 * V_246 )
{
struct V_26 * V_37 = F_67 ( V_14 ) ;
struct V_88 * V_50 , * V_89 [ V_250 + 1 ] ;
int V_251 ;
if ( ! V_37 )
return - V_252 ;
if ( F_167 ( V_89 , V_250 , V_246 , NULL ) < 0 )
F_172 () ;
if ( V_89 [ V_248 ] ) {
F_168 (a, tb[IFLA_INET_CONF], rem)
F_173 ( V_37 , F_169 ( V_50 ) , F_95 ( V_50 ) ) ;
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
static int F_175 ( struct V_85 * V_86 , int V_82 ,
struct V_261 * V_262 , T_1 V_56 ,
T_1 V_223 , int V_202 , unsigned int V_47 ,
int type )
{
struct V_54 * V_55 ;
struct V_256 * V_263 ;
V_55 = F_149 ( V_86 , V_56 , V_223 , V_202 , sizeof( struct V_256 ) ,
V_47 ) ;
if ( V_55 == NULL )
return - V_224 ;
V_263 = F_78 ( V_55 ) ;
V_263 -> V_264 = V_166 ;
if ( F_176 ( V_86 , V_265 , V_82 ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_257 ) &&
F_176 ( V_86 , V_257 ,
F_38 ( * V_262 , V_46 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_258 ) &&
F_176 ( V_86 , V_258 ,
F_38 ( * V_262 , V_266 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_259 ) &&
F_176 ( V_86 , V_259 ,
F_38 ( * V_262 , V_267 ) ) < 0 )
goto V_227;
if ( ( type == - 1 || type == V_260 ) &&
F_176 ( V_86 , V_260 ,
F_38 ( * V_262 , V_268 ) ) < 0 )
goto V_227;
return F_153 ( V_86 , V_55 ) ;
V_227:
F_154 ( V_86 , V_55 ) ;
return - V_224 ;
}
void F_177 ( struct V_1 * V_1 , int type , int V_82 ,
struct V_261 * V_262 )
{
struct V_85 * V_86 ;
int V_93 = - V_80 ;
V_86 = F_159 ( F_174 ( type ) , V_269 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_175 ( V_86 , V_82 , V_262 , 0 , 0 ,
V_270 , 0 , type ) ;
if ( V_93 < 0 ) {
F_30 ( V_93 == - V_224 ) ;
F_160 ( V_86 ) ;
goto V_95;
}
F_161 ( V_86 , V_1 , 0 , V_271 , NULL , V_269 ) ;
return;
V_95:
if ( V_93 < 0 )
F_162 ( V_1 , V_271 , V_93 ) ;
}
static int F_178 ( struct V_85 * V_272 ,
struct V_54 * V_55 )
{
struct V_1 * V_1 = F_76 ( V_272 -> V_87 ) ;
struct V_88 * V_89 [ V_273 + 1 ] ;
struct V_256 * V_263 ;
struct V_85 * V_86 ;
struct V_261 * V_262 ;
struct V_26 * V_37 ;
struct V_11 * V_14 ;
int V_82 ;
int V_93 ;
V_93 = F_77 ( V_55 , sizeof( * V_263 ) , V_89 , V_273 ,
V_274 ) ;
if ( V_93 < 0 )
goto V_95;
V_93 = V_77 ;
if ( ! V_89 [ V_265 ] )
goto V_95;
V_82 = F_179 ( V_89 [ V_265 ] ) ;
switch ( V_82 ) {
case V_275 :
V_262 = V_1 -> V_40 . V_276 ;
break;
case V_277 :
V_262 = V_1 -> V_40 . V_41 ;
break;
default:
V_14 = F_92 ( V_1 , V_82 ) ;
if ( V_14 == NULL )
goto V_95;
V_37 = F_67 ( V_14 ) ;
if ( V_37 == NULL )
goto V_95;
V_262 = & V_37 -> V_39 ;
break;
}
V_93 = - V_80 ;
V_86 = F_159 ( F_174 ( - 1 ) , V_269 ) ;
if ( V_86 == NULL )
goto V_95;
V_93 = F_175 ( V_86 , V_82 , V_262 ,
F_81 ( V_272 ) . V_56 ,
V_55 -> V_242 , V_270 , 0 ,
- 1 ) ;
if ( V_93 < 0 ) {
F_30 ( V_93 == - V_224 ) ;
F_160 ( V_86 ) ;
goto V_95;
}
V_93 = F_180 ( V_86 , V_1 , F_81 ( V_272 ) . V_56 ) ;
V_95:
return V_93 ;
}
static int F_181 ( struct V_85 * V_86 ,
struct V_228 * V_229 )
{
struct V_1 * V_1 = F_76 ( V_86 -> V_87 ) ;
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
V_229 -> V_223 = F_156 ( & V_1 -> V_40 . V_239 ) ^
V_1 -> V_240 ;
F_11 (dev, head, index_hlist) {
if ( V_232 < V_233 )
goto V_241;
V_37 = F_120 ( V_14 ) ;
if ( ! V_37 )
goto V_241;
if ( F_175 ( V_86 , V_14 -> V_82 ,
& V_37 -> V_39 ,
F_81 ( V_229 -> V_86 ) . V_56 ,
V_229 -> V_55 -> V_242 ,
V_270 ,
V_243 ,
- 1 ) <= 0 ) {
F_18 () ;
goto V_175;
}
F_157 ( V_229 , F_158 ( V_86 ) ) ;
V_241:
V_232 ++ ;
}
F_18 () ;
}
if ( V_230 == V_237 ) {
if ( F_175 ( V_86 , V_275 ,
V_1 -> V_40 . V_276 ,
F_81 ( V_229 -> V_86 ) . V_56 ,
V_229 -> V_55 -> V_242 ,
V_270 , V_243 ,
- 1 ) <= 0 )
goto V_175;
else
V_230 ++ ;
}
if ( V_230 == V_237 + 1 ) {
if ( F_175 ( V_86 , V_277 ,
V_1 -> V_40 . V_41 ,
F_81 ( V_229 -> V_86 ) . V_56 ,
V_229 -> V_55 -> V_242 ,
V_270 , V_243 ,
- 1 ) <= 0 )
goto V_175;
else
V_230 ++ ;
}
V_175:
V_229 -> args [ 0 ] = V_230 ;
V_229 -> args [ 1 ] = V_232 ;
return V_86 -> V_184 ;
}
static void F_182 ( struct V_1 * V_1 , int V_111 )
{
struct V_11 * V_14 ;
F_10 () ;
F_121 (net, dev) {
struct V_26 * V_37 ;
V_37 = F_120 ( V_14 ) ;
if ( V_37 && ! F_183 ( V_111 , V_37 -> V_39 . V_278 ) )
V_37 -> V_39 . V_249 [ V_111 ] = V_1 -> V_40 . V_41 -> V_249 [ V_111 ] ;
}
F_18 () ;
}
static void F_184 ( struct V_1 * V_1 )
{
struct V_11 * V_14 ;
int V_279 = F_185 ( V_1 , V_46 ) ;
F_185 ( V_1 , V_280 ) = ! V_279 ;
F_186 ( V_1 , V_46 ) = V_279 ;
F_177 ( V_1 , V_257 ,
V_275 ,
V_1 -> V_40 . V_276 ) ;
F_177 ( V_1 , V_257 ,
V_277 ,
V_1 -> V_40 . V_41 ) ;
F_187 (net, dev) {
struct V_26 * V_37 ;
if ( V_279 )
F_39 ( V_14 ) ;
F_10 () ;
V_37 = F_120 ( V_14 ) ;
if ( V_37 ) {
F_136 ( V_37 , V_46 , V_279 ) ;
F_177 ( V_1 , V_257 ,
V_14 -> V_82 , & V_37 -> V_39 ) ;
}
F_18 () ;
}
}
static int F_188 ( struct V_1 * V_1 , struct V_261 * V_39 )
{
if ( V_39 == V_1 -> V_40 . V_41 )
return V_277 ;
else if ( V_39 == V_1 -> V_40 . V_276 )
return V_275 ;
else {
struct V_26 * V_27
= F_24 ( V_39 , struct V_26 , V_39 ) ;
return V_27 -> V_14 -> V_82 ;
}
}
static int F_189 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int V_287 = * ( int * ) V_282 -> V_249 ;
int V_157 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
int V_288 = * ( int * ) V_282 -> V_249 ;
if ( V_283 ) {
struct V_261 * V_39 = V_282 -> V_289 ;
struct V_1 * V_1 = V_282 -> V_290 ;
int V_111 = ( int * ) V_282 -> V_249 - V_39 -> V_249 ;
int V_82 ;
F_191 ( V_111 , V_39 -> V_278 ) ;
if ( V_39 == V_1 -> V_40 . V_41 )
F_182 ( V_1 , V_111 ) ;
if ( V_111 == V_291 - 1 ||
V_111 == V_292 - 1 )
if ( ( V_288 == 0 ) && ( V_287 != 0 ) )
F_192 ( V_1 ) ;
if ( V_111 == V_293 - 1 &&
V_288 != V_287 ) {
V_82 = F_188 ( V_1 , V_39 ) ;
F_177 ( V_1 , V_258 ,
V_82 , V_39 ) ;
}
if ( V_111 == V_294 - 1 &&
V_288 != V_287 ) {
V_82 = F_188 ( V_1 , V_39 ) ;
F_177 ( V_1 , V_260 ,
V_82 , V_39 ) ;
}
}
return V_157 ;
}
static int F_193 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int * V_295 = V_282 -> V_249 ;
int V_3 = * V_295 ;
T_6 V_296 = * V_286 ;
int V_157 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
if ( V_283 && * V_295 != V_3 ) {
struct V_1 * V_1 = V_282 -> V_290 ;
if ( V_295 != & F_186 ( V_1 , V_46 ) ) {
if ( ! F_194 () ) {
* V_295 = V_3 ;
* V_286 = V_296 ;
return F_195 () ;
}
if ( V_295 == & F_185 ( V_1 , V_46 ) ) {
F_184 ( V_1 ) ;
} else {
struct V_261 * V_39 = V_282 -> V_289 ;
struct V_26 * V_27 =
F_24 ( V_39 , struct V_26 , V_39 ) ;
if ( * V_295 )
F_39 ( V_27 -> V_14 ) ;
F_177 ( V_1 ,
V_257 ,
V_27 -> V_14 -> V_82 ,
V_39 ) ;
}
F_87 () ;
F_192 ( V_1 ) ;
} else
F_177 ( V_1 , V_257 ,
V_277 ,
V_1 -> V_40 . V_41 ) ;
}
return V_157 ;
}
static int F_196 ( struct V_281 * V_282 , int V_283 ,
void T_4 * V_284 ,
T_5 * V_285 , T_6 * V_286 )
{
int * V_295 = V_282 -> V_249 ;
int V_3 = * V_295 ;
int V_157 = F_190 ( V_282 , V_283 , V_284 , V_285 , V_286 ) ;
struct V_1 * V_1 = V_282 -> V_290 ;
if ( V_283 && * V_295 != V_3 )
F_192 ( V_1 ) ;
return V_157 ;
}
static int F_197 ( struct V_1 * V_1 , char * V_297 ,
struct V_261 * V_298 )
{
int V_111 ;
struct V_299 * V_300 ;
char V_301 [ sizeof( L_6 ) + V_136 ] ;
V_300 = F_198 ( & V_302 , sizeof( * V_300 ) , V_28 ) ;
if ( ! V_300 )
goto V_38;
for ( V_111 = 0 ; V_111 < F_199 ( V_300 -> V_303 ) - 1 ; V_111 ++ ) {
V_300 -> V_303 [ V_111 ] . V_249 += ( char * ) V_298 - ( char * ) & V_261 ;
V_300 -> V_303 [ V_111 ] . V_289 = V_298 ;
V_300 -> V_303 [ V_111 ] . V_290 = V_1 ;
}
snprintf ( V_301 , sizeof( V_301 ) , L_7 , V_297 ) ;
V_300 -> V_304 = F_200 ( V_1 , V_301 , V_300 -> V_303 ) ;
if ( ! V_300 -> V_304 )
goto free;
V_298 -> V_42 = V_300 ;
return 0 ;
free:
F_26 ( V_300 ) ;
V_38:
return - V_80 ;
}
static void F_201 ( struct V_261 * V_39 )
{
struct V_299 * V_300 = V_39 -> V_42 ;
if ( V_300 == NULL )
return;
V_39 -> V_42 = NULL ;
F_202 ( V_300 -> V_304 ) ;
F_26 ( V_300 ) ;
}
static void F_19 ( struct V_26 * V_27 )
{
F_203 ( V_27 -> V_14 , V_27 -> V_43 , NULL ) ;
F_197 ( F_13 ( V_27 -> V_14 ) , V_27 -> V_14 -> V_35 ,
& V_27 -> V_39 ) ;
}
static void F_20 ( struct V_26 * V_27 )
{
F_201 ( & V_27 -> V_39 ) ;
F_204 ( V_27 -> V_43 ) ;
}
static T_7 int F_205 ( struct V_1 * V_1 )
{
int V_93 ;
struct V_261 * V_305 , * V_306 ;
#ifdef F_206
struct V_281 * V_307 = V_308 ;
struct V_309 * V_310 ;
#endif
V_93 = - V_205 ;
V_305 = & V_261 ;
V_306 = & V_311 ;
if ( ! F_12 ( V_1 , & V_312 ) ) {
V_305 = F_198 ( V_305 , sizeof( V_261 ) , V_28 ) ;
if ( V_305 == NULL )
goto V_313;
V_306 = F_198 ( V_306 , sizeof( V_311 ) , V_28 ) ;
if ( V_306 == NULL )
goto V_314;
#ifdef F_206
V_307 = F_198 ( V_307 , sizeof( V_308 ) , V_28 ) ;
if ( V_307 == NULL )
goto V_315;
V_307 [ 0 ] . V_249 = & V_305 -> V_249 [ V_316 - 1 ] ;
V_307 [ 0 ] . V_289 = V_305 ;
V_307 [ 0 ] . V_290 = V_1 ;
#endif
}
#ifdef F_206
V_93 = F_197 ( V_1 , L_8 , V_305 ) ;
if ( V_93 < 0 )
goto V_317;
V_93 = F_197 ( V_1 , L_9 , V_306 ) ;
if ( V_93 < 0 )
goto V_318;
V_93 = - V_205 ;
V_310 = F_200 ( V_1 , L_10 , V_307 ) ;
if ( V_310 == NULL )
goto V_319;
V_1 -> V_40 . V_310 = V_310 ;
#endif
V_1 -> V_40 . V_276 = V_305 ;
V_1 -> V_40 . V_41 = V_306 ;
return 0 ;
#ifdef F_206
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
return V_93 ;
}
static T_8 void F_207 ( struct V_1 * V_1 )
{
#ifdef F_206
struct V_281 * V_307 ;
V_307 = V_1 -> V_40 . V_310 -> V_320 ;
F_202 ( V_1 -> V_40 . V_310 ) ;
F_201 ( V_1 -> V_40 . V_41 ) ;
F_201 ( V_1 -> V_40 . V_276 ) ;
F_26 ( V_307 ) ;
#endif
F_26 ( V_1 -> V_40 . V_41 ) ;
F_26 ( V_1 -> V_40 . V_276 ) ;
}
void T_9 F_208 ( void )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_114 ; V_111 ++ )
F_209 ( & V_10 [ V_111 ] ) ;
F_210 ( & V_321 ) ;
F_211 ( V_322 , F_118 ) ;
F_212 ( & V_323 ) ;
F_64 ( V_79 , & V_78 , 0 ) ;
F_213 ( & V_324 ) ;
F_214 ( V_322 , V_73 , F_100 , NULL , NULL ) ;
F_214 ( V_322 , V_69 , F_75 , NULL , NULL ) ;
F_214 ( V_322 , V_325 , NULL , F_155 , NULL ) ;
F_214 ( V_322 , V_326 , F_178 ,
F_181 , NULL ) ;
}
