static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = ( V_4 T_1 ) V_2 ^ F_2 ( V_1 ) ;
return F_3 ( V_3 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
T_1 V_8 = F_1 ( V_1 , V_7 -> V_9 ) ;
F_5 ( & V_10 ) ;
F_6 ( & V_7 -> V_8 , & V_11 [ V_8 ] ) ;
F_7 ( & V_10 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_5 ( & V_10 ) ;
F_9 ( & V_7 -> V_8 ) ;
F_7 ( & V_10 ) ;
}
struct V_12 * F_10 ( struct V_1 * V_1 , T_2 V_2 , bool V_13 )
{
T_1 V_8 = F_1 ( V_1 , V_2 ) ;
struct V_12 * V_14 = NULL ;
struct V_6 * V_7 ;
F_11 () ;
F_12 (ifa, &inet_addr_lst[hash], hash) {
if ( V_7 -> V_9 == V_2 ) {
struct V_12 * V_15 = V_7 -> V_16 -> V_15 ;
if ( ! F_13 ( F_14 ( V_15 ) , V_1 ) )
continue;
V_14 = V_15 ;
break;
}
}
if ( ! V_14 ) {
struct V_17 V_18 = { . V_19 = V_2 } ;
struct V_20 V_21 = { 0 } ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_1 , V_24 ) ;
if ( V_23 &&
! F_16 ( V_23 , & V_18 , & V_21 , V_25 ) &&
V_21 . type == V_26 )
V_14 = F_17 ( V_21 ) ;
}
if ( V_14 && V_13 )
F_18 ( V_14 ) ;
F_19 () ;
return V_14 ;
}
static void F_20 ( struct V_27 * V_28 )
{
}
static void F_21 ( struct V_27 * V_28 )
{
}
static struct V_6 * F_22 ( void )
{
return F_23 ( sizeof( struct V_6 ) , V_29 ) ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_25 ( V_31 , struct V_6 , V_30 ) ;
if ( V_7 -> V_16 )
F_26 ( V_7 -> V_16 ) ;
F_27 ( V_7 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
F_29 ( & V_7 -> V_30 , F_24 ) ;
}
void F_30 ( struct V_27 * V_28 )
{
struct V_12 * V_15 = V_28 -> V_15 ;
F_31 ( V_28 -> V_32 ) ;
F_31 ( V_28 -> V_33 ) ;
F_27 ( F_32 ( V_28 -> V_34 , 1 ) ) ;
#ifdef F_33
F_34 ( L_1 , V_35 , V_28 , V_15 ? V_15 -> V_36 : L_2 ) ;
#endif
F_35 ( V_15 ) ;
if ( ! V_28 -> V_37 )
F_36 ( L_3 , V_28 ) ;
else
F_27 ( V_28 ) ;
}
static struct V_27 * F_37 ( struct V_12 * V_15 )
{
struct V_27 * V_38 ;
F_38 () ;
V_38 = F_23 ( sizeof( * V_38 ) , V_29 ) ;
if ( ! V_38 )
goto V_39;
memcpy ( & V_38 -> V_40 , F_14 ( V_15 ) -> V_41 . V_42 ,
sizeof( V_38 -> V_40 ) ) ;
V_38 -> V_40 . V_43 = NULL ;
V_38 -> V_15 = V_15 ;
V_38 -> V_44 = F_39 ( V_15 , & V_45 ) ;
if ( ! V_38 -> V_44 )
goto V_46;
if ( F_40 ( V_38 -> V_40 , V_47 ) )
F_41 ( V_15 ) ;
F_18 ( V_15 ) ;
F_42 ( V_38 ) ;
F_20 ( V_38 ) ;
F_43 ( V_38 ) ;
if ( V_15 -> V_48 & V_49 )
F_44 ( V_38 ) ;
F_45 ( V_15 -> V_50 , V_38 ) ;
V_39:
return V_38 ;
V_46:
F_27 ( V_38 ) ;
V_38 = NULL ;
goto V_39;
}
static void F_46 ( struct V_30 * V_31 )
{
struct V_27 * V_28 = F_25 ( V_31 , struct V_27 , V_30 ) ;
F_26 ( V_28 ) ;
}
static void F_47 ( struct V_27 * V_38 )
{
struct V_6 * V_7 ;
struct V_12 * V_15 ;
F_38 () ;
V_15 = V_38 -> V_15 ;
V_38 -> V_37 = 1 ;
F_48 ( V_38 ) ;
while ( ( V_7 = V_38 -> V_32 ) != NULL ) {
F_49 ( V_38 , & V_38 -> V_32 , 0 ) ;
F_28 ( V_7 ) ;
}
F_50 ( V_15 -> V_50 , NULL ) ;
F_21 ( V_38 ) ;
F_51 ( & V_45 , V_38 -> V_44 ) ;
F_52 ( V_15 ) ;
F_29 ( & V_38 -> V_30 , F_46 ) ;
}
int F_53 ( struct V_27 * V_38 , T_2 V_51 , T_2 V_52 )
{
F_11 () ;
F_54 (in_dev) {
if ( F_55 ( V_51 , V_7 ) ) {
if ( ! V_52 || F_55 ( V_52 , V_7 ) ) {
F_19 () ;
return 1 ;
}
}
} F_56 ( V_38 ) ;
F_19 () ;
return 0 ;
}
static void F_57 ( struct V_27 * V_38 , struct V_6 * * V_53 ,
int V_54 , struct V_55 * V_56 , T_1 V_57 )
{
struct V_6 * V_58 = NULL ;
struct V_6 * V_7 , * V_59 = * V_53 ;
struct V_6 * V_60 = V_38 -> V_32 ;
struct V_6 * V_61 = NULL ;
int V_62 = F_58 ( V_38 ) ;
F_38 () ;
if ( ! ( V_59 -> V_63 & V_64 ) ) {
struct V_6 * * V_65 = & V_59 -> V_66 ;
while ( ( V_7 = * V_65 ) != NULL ) {
if ( ! ( V_7 -> V_63 & V_64 ) &&
V_59 -> V_67 <= V_7 -> V_67 )
V_60 = V_7 ;
if ( ! ( V_7 -> V_63 & V_64 ) ||
V_59 -> V_68 != V_7 -> V_68 ||
! F_55 ( V_59 -> V_69 , V_7 ) ) {
V_65 = & V_7 -> V_66 ;
V_61 = V_7 ;
continue;
}
if ( ! V_62 ) {
F_8 ( V_7 ) ;
* V_65 = V_7 -> V_66 ;
F_59 ( V_70 , V_7 , V_56 , V_57 ) ;
F_60 ( & V_71 ,
V_72 , V_7 ) ;
F_28 ( V_7 ) ;
} else {
V_58 = V_7 ;
break;
}
}
}
for ( V_7 = V_58 ; V_7 ; V_7 = V_7 -> V_66 ) {
if ( V_59 -> V_68 == V_7 -> V_68 &&
F_55 ( V_59 -> V_69 , V_7 ) )
F_61 ( V_7 , V_59 ) ;
}
* V_53 = V_59 -> V_66 ;
F_8 ( V_59 ) ;
F_59 ( V_70 , V_59 , V_56 , V_57 ) ;
F_60 ( & V_71 , V_72 , V_59 ) ;
if ( V_58 ) {
struct V_6 * V_73 = V_58 -> V_66 ;
if ( V_61 ) {
V_61 -> V_66 = V_58 -> V_66 ;
V_58 -> V_66 = V_60 -> V_66 ;
V_60 -> V_66 = V_58 ;
}
V_58 -> V_63 &= ~ V_64 ;
F_59 ( V_74 , V_58 , V_56 , V_57 ) ;
F_60 ( & V_71 ,
V_75 , V_58 ) ;
for ( V_7 = V_73 ; V_7 ; V_7 = V_7 -> V_66 ) {
if ( V_59 -> V_68 != V_7 -> V_68 ||
! F_55 ( V_59 -> V_69 , V_7 ) )
continue;
F_62 ( V_7 ) ;
}
}
if ( V_54 )
F_28 ( V_59 ) ;
}
static void F_49 ( struct V_27 * V_38 , struct V_6 * * V_53 ,
int V_54 )
{
F_57 ( V_38 , V_53 , V_54 , NULL , 0 ) ;
}
static int F_63 ( struct V_6 * V_7 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_27 * V_38 = V_7 -> V_16 ;
struct V_6 * V_59 , * * V_53 , * * V_76 ;
F_38 () ;
if ( ! V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return 0 ;
}
V_7 -> V_63 &= ~ V_64 ;
V_76 = & V_38 -> V_32 ;
for ( V_53 = & V_38 -> V_32 ; ( V_59 = * V_53 ) != NULL ;
V_53 = & V_59 -> V_66 ) {
if ( ! ( V_59 -> V_63 & V_64 ) &&
V_7 -> V_67 <= V_59 -> V_67 )
V_76 = & V_59 -> V_66 ;
if ( V_59 -> V_68 == V_7 -> V_68 &&
F_55 ( V_59 -> V_69 , V_7 ) ) {
if ( V_59 -> V_9 == V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return - V_77 ;
}
if ( V_59 -> V_67 != V_7 -> V_67 ) {
F_28 ( V_7 ) ;
return - V_78 ;
}
V_7 -> V_63 |= V_64 ;
}
}
if ( ! ( V_7 -> V_63 & V_64 ) ) {
F_64 ( ( V_4 T_1 ) V_7 -> V_9 ) ;
V_53 = V_76 ;
}
V_7 -> V_66 = * V_53 ;
* V_53 = V_7 ;
F_4 ( F_14 ( V_38 -> V_15 ) , V_7 ) ;
F_65 ( & V_79 ) ;
F_66 ( V_80 , & V_79 , 0 ) ;
F_59 ( V_74 , V_7 , V_56 , V_57 ) ;
F_60 ( & V_71 , V_75 , V_7 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_7 )
{
return F_63 ( V_7 , NULL , 0 ) ;
}
static int F_68 ( struct V_12 * V_15 , struct V_6 * V_7 )
{
struct V_27 * V_38 = F_69 ( V_15 ) ;
F_38 () ;
if ( ! V_38 ) {
F_28 ( V_7 ) ;
return - V_81 ;
}
F_70 ( V_38 ) ;
F_71 ( V_38 -> V_44 ) ;
if ( V_7 -> V_16 != V_38 ) {
F_31 ( V_7 -> V_16 ) ;
F_42 ( V_38 ) ;
V_7 -> V_16 = V_38 ;
}
if ( F_72 ( V_7 -> V_9 ) )
V_7 -> V_67 = V_82 ;
return F_67 ( V_7 ) ;
}
struct V_27 * F_73 ( struct V_1 * V_1 , int V_83 )
{
struct V_12 * V_15 ;
struct V_27 * V_38 = NULL ;
F_11 () ;
V_15 = F_74 ( V_1 , V_83 ) ;
if ( V_15 )
V_38 = F_75 ( V_15 -> V_50 ) ;
F_19 () ;
return V_38 ;
}
struct V_6 * F_76 ( struct V_27 * V_38 , T_2 V_84 ,
T_2 V_85 )
{
F_38 () ;
F_54 (in_dev) {
if ( V_7 -> V_68 == V_85 && F_55 ( V_84 , V_7 ) )
return V_7 ;
} F_56 ( V_38 ) ;
return NULL ;
}
static int F_77 ( struct V_86 * V_87 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_78 ( V_87 -> V_88 ) ;
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_27 * V_38 ;
struct V_92 * V_93 ;
struct V_6 * V_7 , * * V_53 ;
int V_94 = - V_78 ;
F_38 () ;
V_94 = F_79 ( V_56 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_80 ( V_56 ) ;
V_38 = F_73 ( V_1 , V_93 -> V_97 ) ;
if ( V_38 == NULL ) {
V_94 = - V_98 ;
goto V_96;
}
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 ) {
if ( V_90 [ V_99 ] &&
V_7 -> V_9 != F_81 ( V_90 [ V_99 ] ) )
continue;
if ( V_90 [ V_100 ] && F_82 ( V_90 [ V_100 ] , V_7 -> V_101 ) )
continue;
if ( V_90 [ V_102 ] &&
( V_93 -> V_103 != V_7 -> V_103 ||
! F_55 ( F_81 ( V_90 [ V_102 ] ) , V_7 ) ) )
continue;
F_57 ( V_38 , V_53 , 1 , V_56 , F_83 ( V_87 ) . V_57 ) ;
return 0 ;
}
V_94 = - V_104 ;
V_96:
return V_94 ;
}
static void F_84 ( struct V_105 * V_106 )
{
unsigned long V_107 , V_108 , V_73 , V_109 ;
struct V_6 * V_7 ;
struct V_110 * V_111 ;
int V_112 ;
V_107 = V_113 ;
V_108 = F_85 ( V_107 + V_114 ) ;
for ( V_112 = 0 ; V_112 < V_115 ; V_112 ++ ) {
bool V_116 = false ;
F_11 () ;
F_12 (ifa, &inet_addr_lst[i], hash) {
unsigned long V_117 ;
if ( V_7 -> V_63 & V_118 )
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
if ( F_86 ( V_7 -> V_119 +
V_7 -> V_122 * V_121 , V_108 ) )
V_108 = V_7 -> V_119 +
V_7 -> V_122 * V_121 ;
if ( ! ( V_7 -> V_63 & V_125 ) )
V_116 = true ;
} else if ( F_86 ( V_7 -> V_119 +
V_7 -> V_124 * V_121 ,
V_108 ) ) {
V_108 = V_7 -> V_119 +
V_7 -> V_124 * V_121 ;
}
}
F_19 () ;
if ( ! V_116 )
continue;
F_87 () ;
F_88 (ifa, n, &inet_addr_lst[i], hash) {
unsigned long V_117 ;
if ( V_7 -> V_63 & V_118 )
continue;
V_117 = ( V_107 - V_7 -> V_119 +
V_120 ) / V_121 ;
if ( V_7 -> V_122 != V_123 &&
V_117 >= V_7 -> V_122 ) {
struct V_6 * * V_53 ;
for ( V_53 = & V_7 -> V_16 -> V_32 ;
* V_53 != NULL ; V_53 = & ( * V_53 ) -> V_66 ) {
if ( * V_53 == V_7 ) {
F_49 ( V_7 -> V_16 ,
V_53 , 1 ) ;
break;
}
}
} else if ( V_7 -> V_124 !=
V_123 &&
V_117 >= V_7 -> V_124 &&
! ( V_7 -> V_63 & V_125 ) ) {
V_7 -> V_63 |= V_125 ;
F_59 ( V_74 , V_7 , NULL , 0 ) ;
}
}
F_89 () ;
}
V_73 = F_85 ( V_108 ) ;
V_109 = V_108 ;
if ( F_86 ( V_73 , V_108 + V_126 ) )
V_109 = V_73 ;
V_107 = V_113 ;
if ( F_86 ( V_109 , V_107 + V_127 ) )
V_109 = V_107 + V_127 ;
F_66 ( V_80 , & V_79 ,
V_109 - V_107 ) ;
}
static void F_90 ( struct V_6 * V_7 , T_3 V_128 ,
T_3 V_129 )
{
unsigned long V_130 ;
V_7 -> V_63 &= ~ ( V_118 | V_125 ) ;
V_130 = F_91 ( V_128 , V_121 ) ;
if ( F_92 ( V_130 ) )
V_7 -> V_122 = V_130 ;
else
V_7 -> V_63 |= V_118 ;
V_130 = F_91 ( V_129 , V_121 ) ;
if ( F_92 ( V_130 ) ) {
if ( V_130 == 0 )
V_7 -> V_63 |= V_125 ;
V_7 -> V_124 = V_130 ;
}
V_7 -> V_119 = V_113 ;
if ( ! V_7 -> V_131 )
V_7 -> V_131 = V_7 -> V_119 ;
}
static struct V_6 * F_93 ( struct V_1 * V_1 , struct V_55 * V_56 ,
T_3 * V_132 , T_3 * V_133 )
{
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_6 * V_7 ;
struct V_92 * V_93 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
int V_94 ;
V_94 = F_79 ( V_56 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_80 ( V_56 ) ;
V_94 = - V_78 ;
if ( V_93 -> V_103 > 32 || V_90 [ V_99 ] == NULL )
goto V_96;
V_15 = F_94 ( V_1 , V_93 -> V_97 ) ;
V_94 = - V_98 ;
if ( V_15 == NULL )
goto V_96;
V_38 = F_69 ( V_15 ) ;
V_94 = - V_81 ;
if ( V_38 == NULL )
goto V_96;
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_96;
F_70 ( V_38 ) ;
F_71 ( V_38 -> V_44 ) ;
F_42 ( V_38 ) ;
if ( V_90 [ V_102 ] == NULL )
V_90 [ V_102 ] = V_90 [ V_99 ] ;
F_95 ( & V_7 -> V_8 ) ;
V_7 -> V_103 = V_93 -> V_103 ;
V_7 -> V_68 = F_96 ( V_93 -> V_103 ) ;
V_7 -> V_63 = V_90 [ V_134 ] ? F_97 ( V_90 [ V_134 ] ) :
V_93 -> V_63 ;
V_7 -> V_67 = V_93 -> V_67 ;
V_7 -> V_16 = V_38 ;
V_7 -> V_9 = F_81 ( V_90 [ V_99 ] ) ;
V_7 -> V_69 = F_81 ( V_90 [ V_102 ] ) ;
if ( V_90 [ V_135 ] )
V_7 -> V_136 = F_81 ( V_90 [ V_135 ] ) ;
if ( V_90 [ V_100 ] )
F_98 ( V_7 -> V_101 , V_90 [ V_100 ] , V_137 ) ;
else
memcpy ( V_7 -> V_101 , V_15 -> V_36 , V_137 ) ;
if ( V_90 [ V_138 ] ) {
struct V_139 * V_140 ;
V_140 = F_99 ( V_90 [ V_138 ] ) ;
if ( ! V_140 -> V_141 || V_140 -> V_142 > V_140 -> V_141 ) {
V_94 = - V_78 ;
goto V_143;
}
* V_132 = V_140 -> V_141 ;
* V_133 = V_140 -> V_142 ;
}
return V_7 ;
V_143:
F_28 ( V_7 ) ;
V_96:
return F_100 ( V_94 ) ;
}
static struct V_6 * F_101 ( struct V_6 * V_7 )
{
struct V_27 * V_38 = V_7 -> V_16 ;
struct V_6 * V_59 , * * V_53 ;
if ( ! V_7 -> V_9 )
return NULL ;
for ( V_53 = & V_38 -> V_32 ; ( V_59 = * V_53 ) != NULL ;
V_53 = & V_59 -> V_66 ) {
if ( V_59 -> V_68 == V_7 -> V_68 &&
F_55 ( V_59 -> V_69 , V_7 ) &&
V_59 -> V_9 == V_7 -> V_9 )
return V_59 ;
}
return NULL ;
}
static int F_102 ( struct V_86 * V_87 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_78 ( V_87 -> V_88 ) ;
struct V_6 * V_7 ;
struct V_6 * V_144 ;
T_3 V_128 = V_123 ;
T_3 V_129 = V_123 ;
F_38 () ;
V_7 = F_93 ( V_1 , V_56 , & V_128 , & V_129 ) ;
if ( F_103 ( V_7 ) )
return F_104 ( V_7 ) ;
V_144 = F_101 ( V_7 ) ;
if ( ! V_144 ) {
F_90 ( V_7 , V_128 , V_129 ) ;
return F_63 ( V_7 , V_56 , F_83 ( V_87 ) . V_57 ) ;
} else {
F_28 ( V_7 ) ;
if ( V_56 -> V_145 & V_146 ||
! ( V_56 -> V_145 & V_147 ) )
return - V_77 ;
V_7 = V_144 ;
F_90 ( V_7 , V_128 , V_129 ) ;
F_65 ( & V_79 ) ;
F_66 ( V_80 ,
& V_79 , 0 ) ;
F_59 ( V_74 , V_7 , V_56 , F_83 ( V_87 ) . V_57 ) ;
F_60 ( & V_71 , V_75 , V_7 ) ;
}
return 0 ;
}
static int F_105 ( T_2 V_2 )
{
int V_148 = - 1 ;
if ( F_106 ( V_2 ) )
V_148 = 0 ;
else {
T_3 V_149 = F_107 ( V_2 ) ;
if ( F_108 ( V_149 ) )
V_148 = 8 ;
else if ( F_109 ( V_149 ) )
V_148 = 16 ;
else if ( F_110 ( V_149 ) )
V_148 = 24 ;
}
return V_148 ;
}
int F_111 ( struct V_1 * V_1 , unsigned int V_150 , void T_4 * V_151 )
{
struct V_152 V_153 ;
struct V_154 V_155 ;
struct V_154 * sin = (struct V_154 * ) & V_153 . V_156 ;
struct V_27 * V_38 ;
struct V_6 * * V_53 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_12 * V_15 ;
char * V_157 ;
int V_158 = - V_159 ;
int V_160 = 0 ;
if ( F_112 ( & V_153 , V_151 , sizeof( struct V_152 ) ) )
goto V_39;
V_153 . V_161 [ V_137 - 1 ] = 0 ;
memcpy ( & V_155 , sin , sizeof( * sin ) ) ;
V_157 = strchr ( V_153 . V_161 , ':' ) ;
if ( V_157 )
* V_157 = 0 ;
F_113 ( V_1 , V_153 . V_161 ) ;
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
if ( ! F_114 ( V_1 -> V_170 , V_171 ) )
goto V_39;
break;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_158 = - V_169 ;
if ( ! F_114 ( V_1 -> V_170 , V_171 ) )
goto V_39;
V_158 = - V_78 ;
if ( sin -> V_166 != V_167 )
goto V_39;
break;
default:
V_158 = - V_78 ;
goto V_39;
}
F_87 () ;
V_158 = - V_98 ;
V_15 = F_115 ( V_1 , V_153 . V_161 ) ;
if ( ! V_15 )
goto V_176;
if ( V_157 )
* V_157 = ':' ;
V_38 = F_69 ( V_15 ) ;
if ( V_38 ) {
if ( V_160 ) {
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 ) {
if ( ! strcmp ( V_153 . V_161 , V_7 -> V_101 ) &&
V_155 . V_177 . V_178 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_53 = & V_38 -> V_32 ; ( V_7 = * V_53 ) != NULL ;
V_53 = & V_7 -> V_66 )
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
sin -> V_177 . V_178 = V_7 -> V_69 ;
goto V_179;
case V_165 :
sin -> V_177 . V_178 = V_7 -> V_68 ;
goto V_179;
case V_168 :
if ( V_157 ) {
V_158 = - V_104 ;
if ( ! V_7 )
break;
V_158 = 0 ;
if ( ! ( V_153 . V_180 & V_49 ) )
F_49 ( V_38 , V_53 , 1 ) ;
break;
}
V_158 = F_116 ( V_15 , V_153 . V_180 ) ;
break;
case V_172 :
V_158 = - V_78 ;
if ( F_105 ( sin -> V_177 . V_178 ) < 0 )
break;
if ( ! V_7 ) {
V_158 = - V_81 ;
V_7 = F_22 () ;
if ( ! V_7 )
break;
F_95 ( & V_7 -> V_8 ) ;
if ( V_157 )
memcpy ( V_7 -> V_101 , V_153 . V_161 , V_137 ) ;
else
memcpy ( V_7 -> V_101 , V_15 -> V_36 , V_137 ) ;
} else {
V_158 = 0 ;
if ( V_7 -> V_9 == sin -> V_177 . V_178 )
break;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_136 = 0 ;
V_7 -> V_67 = 0 ;
}
V_7 -> V_69 = V_7 -> V_9 = sin -> V_177 . V_178 ;
if ( ! ( V_15 -> V_48 & V_181 ) ) {
V_7 -> V_103 = F_105 ( V_7 -> V_69 ) ;
V_7 -> V_68 = F_96 ( V_7 -> V_103 ) ;
if ( ( V_15 -> V_48 & V_182 ) &&
V_7 -> V_103 < 31 )
V_7 -> V_136 = V_7 -> V_69 |
~ V_7 -> V_68 ;
} else {
V_7 -> V_103 = 32 ;
V_7 -> V_68 = F_96 ( 32 ) ;
}
F_90 ( V_7 , V_123 , V_123 ) ;
V_158 = F_68 ( V_15 , V_7 ) ;
break;
case V_173 :
V_158 = 0 ;
if ( V_7 -> V_136 != sin -> V_177 . V_178 ) {
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_136 = sin -> V_177 . V_178 ;
F_67 ( V_7 ) ;
}
break;
case V_174 :
V_158 = 0 ;
if ( V_7 -> V_69 == sin -> V_177 . V_178 )
break;
V_158 = - V_78 ;
if ( F_105 ( sin -> V_177 . V_178 ) < 0 )
break;
V_158 = 0 ;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_69 = sin -> V_177 . V_178 ;
F_67 ( V_7 ) ;
break;
case V_175 :
V_158 = - V_78 ;
if ( F_117 ( sin -> V_177 . V_178 , 0 ) )
break;
V_158 = 0 ;
if ( V_7 -> V_68 != sin -> V_177 . V_178 ) {
T_2 V_183 = V_7 -> V_68 ;
F_49 ( V_38 , V_53 , 0 ) ;
V_7 -> V_68 = sin -> V_177 . V_178 ;
V_7 -> V_103 = F_118 ( V_7 -> V_68 ) ;
if ( ( V_15 -> V_48 & V_182 ) &&
( V_7 -> V_103 < 31 ) &&
( V_7 -> V_136 ==
( V_7 -> V_9 | ~ V_183 ) ) ) {
V_7 -> V_136 = ( V_7 -> V_9 |
~ sin -> V_177 . V_178 ) ;
}
F_67 ( V_7 ) ;
}
break;
}
V_176:
F_89 () ;
V_39:
return V_158 ;
V_179:
F_89 () ;
V_158 = F_119 ( V_151 , & V_153 , sizeof( struct V_152 ) ) ? - V_159 : 0 ;
goto V_39;
}
static int F_120 ( struct V_12 * V_15 , char T_4 * V_184 , int V_185 )
{
struct V_27 * V_38 = F_69 ( V_15 ) ;
struct V_6 * V_7 ;
struct V_152 V_153 ;
int V_176 = 0 ;
if ( ! V_38 )
goto V_39;
for ( V_7 = V_38 -> V_32 ; V_7 ; V_7 = V_7 -> V_66 ) {
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
if ( F_119 ( V_184 , & V_153 , sizeof( struct V_152 ) ) ) {
V_176 = - V_159 ;
break;
}
V_184 += sizeof( struct V_152 ) ;
V_185 -= sizeof( struct V_152 ) ;
V_176 += sizeof( struct V_152 ) ;
}
V_39:
return V_176 ;
}
T_2 F_121 ( const struct V_12 * V_15 , T_2 V_186 , int V_187 )
{
T_2 V_2 = 0 ;
struct V_27 * V_38 ;
struct V_1 * V_1 = F_14 ( V_15 ) ;
F_11 () ;
V_38 = F_122 ( V_15 ) ;
if ( ! V_38 )
goto V_188;
F_54 (in_dev) {
if ( V_7 -> V_67 > V_187 )
continue;
if ( ! V_186 || F_55 ( V_186 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_56 ( V_38 ) ;
if ( V_2 )
goto V_189;
V_188:
F_123 (net, dev) {
V_38 = F_122 ( V_15 ) ;
if ( ! V_38 )
continue;
F_54 (in_dev) {
if ( V_7 -> V_67 != V_190 &&
V_7 -> V_67 <= V_187 ) {
V_2 = V_7 -> V_9 ;
goto V_189;
}
} F_56 ( V_38 ) ;
}
V_189:
F_19 () ;
return V_2 ;
}
static T_2 F_124 ( struct V_27 * V_38 , T_2 V_186 ,
T_2 V_23 , int V_187 )
{
int V_191 = 0 ;
T_2 V_2 = 0 ;
F_125 (in_dev) {
if ( ! V_2 &&
( V_23 == V_7 -> V_9 || ! V_23 ) &&
V_7 -> V_67 <= V_187 ) {
V_2 = V_7 -> V_9 ;
if ( V_191 )
break;
}
if ( ! V_191 ) {
V_191 = ( ! V_23 || F_55 ( V_23 , V_7 ) ) &&
( ! V_186 || F_55 ( V_186 , V_7 ) ) ;
if ( V_191 && V_2 ) {
if ( V_23 || ! V_186 )
break;
if ( F_55 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_67 <= V_187 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_191 = 0 ;
}
}
} F_56 ( V_38 ) ;
return V_191 ? V_2 : 0 ;
}
T_2 F_126 ( struct V_1 * V_1 , struct V_27 * V_38 ,
T_2 V_186 , T_2 V_23 , int V_187 )
{
T_2 V_2 = 0 ;
struct V_12 * V_15 ;
if ( V_38 != NULL )
return F_124 ( V_38 , V_186 , V_23 , V_187 ) ;
F_11 () ;
F_123 (net, dev) {
V_38 = F_122 ( V_15 ) ;
if ( V_38 ) {
V_2 = F_124 ( V_38 , V_186 , V_23 , V_187 ) ;
if ( V_2 )
break;
}
}
F_19 () ;
return V_2 ;
}
int F_127 ( struct V_192 * V_193 )
{
return F_128 ( & V_71 , V_193 ) ;
}
int F_129 ( struct V_192 * V_193 )
{
return F_130 ( & V_71 , V_193 ) ;
}
static void F_131 ( struct V_12 * V_15 , struct V_27 * V_38 )
{
struct V_6 * V_7 ;
int V_194 = 0 ;
for ( V_7 = V_38 -> V_32 ; V_7 ; V_7 = V_7 -> V_66 ) {
char V_195 [ V_137 ] , * V_196 ;
memcpy ( V_195 , V_7 -> V_101 , V_137 ) ;
memcpy ( V_7 -> V_101 , V_15 -> V_36 , V_137 ) ;
if ( V_194 ++ == 0 )
goto V_197;
V_196 = strchr ( V_195 , ':' ) ;
if ( V_196 == NULL ) {
sprintf ( V_195 , L_4 , V_194 ) ;
V_196 = V_195 ;
}
if ( strlen ( V_196 ) + strlen ( V_15 -> V_36 ) < V_137 )
strcat ( V_7 -> V_101 , V_196 ) ;
else
strcpy ( V_7 -> V_101 + ( V_137 - strlen ( V_196 ) - 1 ) , V_196 ) ;
V_197:
F_59 ( V_74 , V_7 , NULL , 0 ) ;
}
}
static bool F_132 ( unsigned int V_198 )
{
return V_198 >= 68 ;
}
static void F_133 ( struct V_12 * V_15 ,
struct V_27 * V_38 )
{
struct V_6 * V_7 ;
for ( V_7 = V_38 -> V_32 ; V_7 ;
V_7 = V_7 -> V_66 ) {
F_134 ( V_199 , V_200 ,
V_7 -> V_9 , V_15 ,
V_7 -> V_9 , NULL ,
V_15 -> V_201 , NULL ) ;
}
}
static int F_135 ( struct V_192 * V_202 , unsigned long V_203 ,
void * V_204 )
{
struct V_12 * V_15 = F_136 ( V_204 ) ;
struct V_27 * V_38 = F_69 ( V_15 ) ;
F_38 () ;
if ( ! V_38 ) {
if ( V_203 == V_205 ) {
V_38 = F_37 ( V_15 ) ;
if ( ! V_38 )
return F_137 ( - V_206 ) ;
if ( V_15 -> V_48 & V_207 ) {
F_138 ( V_38 , V_208 , 1 ) ;
F_138 ( V_38 , V_209 , 1 ) ;
}
} else if ( V_203 == V_210 ) {
if ( F_132 ( V_15 -> V_198 ) )
V_38 = F_37 ( V_15 ) ;
}
goto V_39;
}
switch ( V_203 ) {
case V_205 :
F_34 ( L_5 , V_35 ) ;
F_50 ( V_15 -> V_50 , NULL ) ;
break;
case V_75 :
if ( ! F_132 ( V_15 -> V_198 ) )
break;
if ( V_15 -> V_48 & V_207 ) {
struct V_6 * V_7 = F_22 () ;
if ( V_7 ) {
F_95 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_69 = F_139 ( V_211 ) ;
V_7 -> V_103 = 8 ;
V_7 -> V_68 = F_96 ( 8 ) ;
F_42 ( V_38 ) ;
V_7 -> V_16 = V_38 ;
V_7 -> V_67 = V_82 ;
memcpy ( V_7 -> V_101 , V_15 -> V_36 , V_137 ) ;
F_90 ( V_7 , V_123 ,
V_123 ) ;
F_70 ( V_38 ) ;
F_71 ( V_38 -> V_44 ) ;
F_67 ( V_7 ) ;
}
}
F_44 ( V_38 ) ;
case V_212 :
if ( ! F_140 ( V_38 ) )
break;
case V_213 :
F_133 ( V_15 , V_38 ) ;
break;
case V_72 :
F_141 ( V_38 ) ;
break;
case V_214 :
F_142 ( V_38 ) ;
break;
case V_215 :
F_143 ( V_38 ) ;
break;
case V_210 :
if ( F_132 ( V_15 -> V_198 ) )
break;
case V_216 :
F_47 ( V_38 ) ;
break;
case V_217 :
F_131 ( V_15 , V_38 ) ;
F_21 ( V_38 ) ;
F_20 ( V_38 ) ;
break;
}
V_39:
return V_218 ;
}
static T_5 F_144 ( void )
{
return F_145 ( sizeof( struct V_92 ) )
+ F_146 ( 4 )
+ F_146 ( 4 )
+ F_146 ( 4 )
+ F_146 ( V_137 )
+ F_146 ( 4 )
+ F_146 ( sizeof( struct V_139 ) ) ;
}
static inline T_1 F_147 ( unsigned long V_219 )
{
return ( V_219 - V_220 ) * 100UL / V_121 ;
}
static int F_148 ( struct V_86 * V_87 , unsigned long V_219 ,
unsigned long V_221 , T_1 V_222 , T_1 V_223 )
{
struct V_139 V_140 ;
V_140 . V_219 = F_147 ( V_219 ) ;
V_140 . V_221 = F_147 ( V_221 ) ;
V_140 . V_142 = V_222 ;
V_140 . V_141 = V_223 ;
return F_149 ( V_87 , V_138 , sizeof( V_140 ) , & V_140 ) ;
}
static int F_150 ( struct V_86 * V_87 , struct V_6 * V_7 ,
T_1 V_57 , T_1 V_224 , int V_203 , unsigned int V_48 )
{
struct V_92 * V_93 ;
struct V_55 * V_56 ;
T_1 V_222 , V_223 ;
V_56 = F_151 ( V_87 , V_57 , V_224 , V_203 , sizeof( * V_93 ) , V_48 ) ;
if ( V_56 == NULL )
return - V_225 ;
V_93 = F_80 ( V_56 ) ;
V_93 -> V_226 = V_167 ;
V_93 -> V_103 = V_7 -> V_103 ;
V_93 -> V_63 = V_7 -> V_63 ;
V_93 -> V_67 = V_7 -> V_67 ;
V_93 -> V_97 = V_7 -> V_16 -> V_15 -> V_83 ;
if ( ! ( V_93 -> V_63 & V_118 ) ) {
V_222 = V_7 -> V_124 ;
V_223 = V_7 -> V_122 ;
if ( V_222 != V_123 ) {
long V_227 = ( V_113 - V_7 -> V_119 ) / V_121 ;
if ( V_222 > V_227 )
V_222 -= V_227 ;
else
V_222 = 0 ;
if ( V_223 != V_123 ) {
if ( V_223 > V_227 )
V_223 -= V_227 ;
else
V_223 = 0 ;
}
}
} else {
V_222 = V_123 ;
V_223 = V_123 ;
}
if ( ( V_7 -> V_69 &&
F_152 ( V_87 , V_102 , V_7 -> V_69 ) ) ||
( V_7 -> V_9 &&
F_152 ( V_87 , V_99 , V_7 -> V_9 ) ) ||
( V_7 -> V_136 &&
F_152 ( V_87 , V_135 , V_7 -> V_136 ) ) ||
( V_7 -> V_101 [ 0 ] &&
F_153 ( V_87 , V_100 , V_7 -> V_101 ) ) ||
F_154 ( V_87 , V_134 , V_7 -> V_63 ) ||
F_148 ( V_87 , V_7 -> V_131 , V_7 -> V_119 ,
V_222 , V_223 ) )
goto V_228;
return F_155 ( V_87 , V_56 ) ;
V_228:
F_156 ( V_87 , V_56 ) ;
return - V_225 ;
}
static int F_157 ( struct V_86 * V_87 , struct V_229 * V_230 )
{
struct V_1 * V_1 = F_78 ( V_87 -> V_88 ) ;
int V_231 , V_232 ;
int V_233 , V_234 ;
int V_235 , V_236 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
struct V_6 * V_7 ;
struct V_237 * V_31 ;
V_232 = V_230 -> args [ 0 ] ;
V_234 = V_233 = V_230 -> args [ 1 ] ;
V_236 = V_235 = V_230 -> args [ 2 ] ;
for ( V_231 = V_232 ; V_231 < V_238 ; V_231 ++ , V_234 = 0 ) {
V_233 = 0 ;
V_31 = & V_1 -> V_239 [ V_231 ] ;
F_11 () ;
V_230 -> V_224 = F_158 ( & V_1 -> V_41 . V_240 ) ^
V_1 -> V_241 ;
F_12 (dev, head, index_hlist) {
if ( V_233 < V_234 )
goto V_242;
if ( V_231 > V_232 || V_233 > V_234 )
V_236 = 0 ;
V_38 = F_122 ( V_15 ) ;
if ( ! V_38 )
goto V_242;
for ( V_7 = V_38 -> V_32 , V_235 = 0 ; V_7 ;
V_7 = V_7 -> V_66 , V_235 ++ ) {
if ( V_235 < V_236 )
continue;
if ( F_150 ( V_87 , V_7 ,
F_83 ( V_230 -> V_87 ) . V_57 ,
V_230 -> V_56 -> V_243 ,
V_74 , V_244 ) <= 0 ) {
F_19 () ;
goto V_176;
}
F_159 ( V_230 , F_160 ( V_87 ) ) ;
}
V_242:
V_233 ++ ;
}
F_19 () ;
}
V_176:
V_230 -> args [ 0 ] = V_231 ;
V_230 -> args [ 1 ] = V_233 ;
V_230 -> args [ 2 ] = V_235 ;
return V_87 -> V_185 ;
}
static void F_59 ( int V_203 , struct V_6 * V_7 , struct V_55 * V_56 ,
T_1 V_57 )
{
struct V_86 * V_87 ;
T_1 V_224 = V_56 ? V_56 -> V_243 : 0 ;
int V_94 = - V_81 ;
struct V_1 * V_1 ;
V_1 = F_14 ( V_7 -> V_16 -> V_15 ) ;
V_87 = F_161 ( F_144 () , V_29 ) ;
if ( V_87 == NULL )
goto V_96;
V_94 = F_150 ( V_87 , V_7 , V_57 , V_224 , V_203 , 0 ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_225 ) ;
F_162 ( V_87 ) ;
goto V_96;
}
F_163 ( V_87 , V_1 , V_57 , V_245 , V_56 , V_29 ) ;
return;
V_96:
if ( V_94 < 0 )
F_164 ( V_1 , V_245 , V_94 ) ;
}
static T_5 F_165 ( const struct V_12 * V_15 )
{
struct V_27 * V_38 = F_75 ( V_15 -> V_50 ) ;
if ( ! V_38 )
return 0 ;
return F_146 ( V_246 * 4 ) ;
}
static int F_166 ( struct V_86 * V_87 , const struct V_12 * V_15 )
{
struct V_27 * V_38 = F_75 ( V_15 -> V_50 ) ;
struct V_89 * V_247 ;
int V_112 ;
if ( ! V_38 )
return - V_248 ;
V_247 = F_167 ( V_87 , V_249 , V_246 * 4 ) ;
if ( V_247 == NULL )
return - V_225 ;
for ( V_112 = 0 ; V_112 < V_246 ; V_112 ++ )
( ( T_1 * ) F_99 ( V_247 ) ) [ V_112 ] = V_38 -> V_40 . V_250 [ V_112 ] ;
return 0 ;
}
static int F_168 ( const struct V_12 * V_15 ,
const struct V_89 * V_247 )
{
struct V_89 * V_51 , * V_90 [ V_251 + 1 ] ;
int V_94 , V_252 ;
if ( V_15 && ! F_69 ( V_15 ) )
return - V_253 ;
V_94 = F_169 ( V_90 , V_251 , V_247 , V_254 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_90 [ V_249 ] ) {
F_170 (a, tb[IFLA_INET_CONF], rem) {
int V_255 = F_171 ( V_51 ) ;
if ( F_172 ( V_51 ) < 4 )
return - V_78 ;
if ( V_255 <= 0 || V_255 > V_246 )
return - V_78 ;
}
}
return 0 ;
}
static int F_173 ( struct V_12 * V_15 , const struct V_89 * V_247 )
{
struct V_27 * V_38 = F_69 ( V_15 ) ;
struct V_89 * V_51 , * V_90 [ V_251 + 1 ] ;
int V_252 ;
if ( ! V_38 )
return - V_253 ;
if ( F_169 ( V_90 , V_251 , V_247 , NULL ) < 0 )
F_174 () ;
if ( V_90 [ V_249 ] ) {
F_170 (a, tb[IFLA_INET_CONF], rem)
F_175 ( V_38 , F_171 ( V_51 ) , F_97 ( V_51 ) ) ;
}
return 0 ;
}
static int F_176 ( int type )
{
int V_256 = F_145 ( sizeof( struct V_257 ) )
+ F_146 ( 4 ) ;
if ( type == - 1 || type == V_258 )
V_256 += F_146 ( 4 ) ;
if ( type == - 1 || type == V_259 )
V_256 += F_146 ( 4 ) ;
if ( type == - 1 || type == V_260 )
V_256 += F_146 ( 4 ) ;
if ( type == - 1 || type == V_261 )
V_256 += F_146 ( 4 ) ;
return V_256 ;
}
static int F_177 ( struct V_86 * V_87 , int V_83 ,
struct V_262 * V_263 , T_1 V_57 ,
T_1 V_224 , int V_203 , unsigned int V_48 ,
int type )
{
struct V_55 * V_56 ;
struct V_257 * V_264 ;
V_56 = F_151 ( V_87 , V_57 , V_224 , V_203 , sizeof( struct V_257 ) ,
V_48 ) ;
if ( V_56 == NULL )
return - V_225 ;
V_264 = F_80 ( V_56 ) ;
V_264 -> V_265 = V_167 ;
if ( F_178 ( V_87 , V_266 , V_83 ) < 0 )
goto V_228;
if ( ( type == - 1 || type == V_258 ) &&
F_178 ( V_87 , V_258 ,
F_40 ( * V_263 , V_47 ) ) < 0 )
goto V_228;
if ( ( type == - 1 || type == V_259 ) &&
F_178 ( V_87 , V_259 ,
F_40 ( * V_263 , V_267 ) ) < 0 )
goto V_228;
if ( ( type == - 1 || type == V_260 ) &&
F_178 ( V_87 , V_260 ,
F_40 ( * V_263 , V_268 ) ) < 0 )
goto V_228;
if ( ( type == - 1 || type == V_261 ) &&
F_178 ( V_87 , V_261 ,
F_40 ( * V_263 , V_269 ) ) < 0 )
goto V_228;
return F_155 ( V_87 , V_56 ) ;
V_228:
F_156 ( V_87 , V_56 ) ;
return - V_225 ;
}
void F_179 ( struct V_1 * V_1 , int type , int V_83 ,
struct V_262 * V_263 )
{
struct V_86 * V_87 ;
int V_94 = - V_81 ;
V_87 = F_161 ( F_176 ( type ) , V_270 ) ;
if ( V_87 == NULL )
goto V_96;
V_94 = F_177 ( V_87 , V_83 , V_263 , 0 , 0 ,
V_271 , 0 , type ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_225 ) ;
F_162 ( V_87 ) ;
goto V_96;
}
F_163 ( V_87 , V_1 , 0 , V_272 , NULL , V_270 ) ;
return;
V_96:
if ( V_94 < 0 )
F_164 ( V_1 , V_272 , V_94 ) ;
}
static int F_180 ( struct V_86 * V_273 ,
struct V_55 * V_56 )
{
struct V_1 * V_1 = F_78 ( V_273 -> V_88 ) ;
struct V_89 * V_90 [ V_274 + 1 ] ;
struct V_257 * V_264 ;
struct V_86 * V_87 ;
struct V_262 * V_263 ;
struct V_27 * V_38 ;
struct V_12 * V_15 ;
int V_83 ;
int V_94 ;
V_94 = F_79 ( V_56 , sizeof( * V_264 ) , V_90 , V_274 ,
V_275 ) ;
if ( V_94 < 0 )
goto V_96;
V_94 = V_78 ;
if ( ! V_90 [ V_266 ] )
goto V_96;
V_83 = F_181 ( V_90 [ V_266 ] ) ;
switch ( V_83 ) {
case V_276 :
V_263 = V_1 -> V_41 . V_277 ;
break;
case V_278 :
V_263 = V_1 -> V_41 . V_42 ;
break;
default:
V_15 = F_94 ( V_1 , V_83 ) ;
if ( V_15 == NULL )
goto V_96;
V_38 = F_69 ( V_15 ) ;
if ( V_38 == NULL )
goto V_96;
V_263 = & V_38 -> V_40 ;
break;
}
V_94 = - V_81 ;
V_87 = F_161 ( F_176 ( - 1 ) , V_270 ) ;
if ( V_87 == NULL )
goto V_96;
V_94 = F_177 ( V_87 , V_83 , V_263 ,
F_83 ( V_273 ) . V_57 ,
V_56 -> V_243 , V_271 , 0 ,
- 1 ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_225 ) ;
F_162 ( V_87 ) ;
goto V_96;
}
V_94 = F_182 ( V_87 , V_1 , F_83 ( V_273 ) . V_57 ) ;
V_96:
return V_94 ;
}
static int F_183 ( struct V_86 * V_87 ,
struct V_229 * V_230 )
{
struct V_1 * V_1 = F_78 ( V_87 -> V_88 ) ;
int V_231 , V_232 ;
int V_233 , V_234 ;
struct V_12 * V_15 ;
struct V_27 * V_38 ;
struct V_237 * V_31 ;
V_232 = V_230 -> args [ 0 ] ;
V_234 = V_233 = V_230 -> args [ 1 ] ;
for ( V_231 = V_232 ; V_231 < V_238 ; V_231 ++ , V_234 = 0 ) {
V_233 = 0 ;
V_31 = & V_1 -> V_239 [ V_231 ] ;
F_11 () ;
V_230 -> V_224 = F_158 ( & V_1 -> V_41 . V_240 ) ^
V_1 -> V_241 ;
F_12 (dev, head, index_hlist) {
if ( V_233 < V_234 )
goto V_242;
V_38 = F_122 ( V_15 ) ;
if ( ! V_38 )
goto V_242;
if ( F_177 ( V_87 , V_15 -> V_83 ,
& V_38 -> V_40 ,
F_83 ( V_230 -> V_87 ) . V_57 ,
V_230 -> V_56 -> V_243 ,
V_271 ,
V_244 ,
- 1 ) <= 0 ) {
F_19 () ;
goto V_176;
}
F_159 ( V_230 , F_160 ( V_87 ) ) ;
V_242:
V_233 ++ ;
}
F_19 () ;
}
if ( V_231 == V_238 ) {
if ( F_177 ( V_87 , V_276 ,
V_1 -> V_41 . V_277 ,
F_83 ( V_230 -> V_87 ) . V_57 ,
V_230 -> V_56 -> V_243 ,
V_271 , V_244 ,
- 1 ) <= 0 )
goto V_176;
else
V_231 ++ ;
}
if ( V_231 == V_238 + 1 ) {
if ( F_177 ( V_87 , V_278 ,
V_1 -> V_41 . V_42 ,
F_83 ( V_230 -> V_87 ) . V_57 ,
V_230 -> V_56 -> V_243 ,
V_271 , V_244 ,
- 1 ) <= 0 )
goto V_176;
else
V_231 ++ ;
}
V_176:
V_230 -> args [ 0 ] = V_231 ;
V_230 -> args [ 1 ] = V_233 ;
return V_87 -> V_185 ;
}
static void F_184 ( struct V_1 * V_1 , int V_112 )
{
struct V_12 * V_15 ;
F_11 () ;
F_123 (net, dev) {
struct V_27 * V_38 ;
V_38 = F_122 ( V_15 ) ;
if ( V_38 && ! F_185 ( V_112 , V_38 -> V_40 . V_279 ) )
V_38 -> V_40 . V_250 [ V_112 ] = V_1 -> V_41 . V_42 -> V_250 [ V_112 ] ;
}
F_19 () ;
}
static void F_186 ( struct V_1 * V_1 )
{
struct V_12 * V_15 ;
int V_280 = F_187 ( V_1 , V_47 ) ;
F_187 ( V_1 , V_281 ) = ! V_280 ;
F_188 ( V_1 , V_47 ) = V_280 ;
F_179 ( V_1 , V_258 ,
V_276 ,
V_1 -> V_41 . V_277 ) ;
F_179 ( V_1 , V_258 ,
V_278 ,
V_1 -> V_41 . V_42 ) ;
F_189 (net, dev) {
struct V_27 * V_38 ;
if ( V_280 )
F_41 ( V_15 ) ;
F_11 () ;
V_38 = F_122 ( V_15 ) ;
if ( V_38 ) {
F_138 ( V_38 , V_47 , V_280 ) ;
F_179 ( V_1 , V_258 ,
V_15 -> V_83 , & V_38 -> V_40 ) ;
}
F_19 () ;
}
}
static int F_190 ( struct V_1 * V_1 , struct V_262 * V_40 )
{
if ( V_40 == V_1 -> V_41 . V_42 )
return V_278 ;
else if ( V_40 == V_1 -> V_41 . V_277 )
return V_276 ;
else {
struct V_27 * V_28
= F_25 ( V_40 , struct V_27 , V_40 ) ;
return V_28 -> V_15 -> V_83 ;
}
}
static int F_191 ( struct V_282 * V_283 , int V_284 ,
void T_4 * V_285 ,
T_5 * V_286 , T_6 * V_287 )
{
int V_288 = * ( int * ) V_283 -> V_250 ;
int V_158 = F_192 ( V_283 , V_284 , V_285 , V_286 , V_287 ) ;
int V_289 = * ( int * ) V_283 -> V_250 ;
if ( V_284 ) {
struct V_262 * V_40 = V_283 -> V_290 ;
struct V_1 * V_1 = V_283 -> V_291 ;
int V_112 = ( int * ) V_283 -> V_250 - V_40 -> V_250 ;
int V_83 ;
F_193 ( V_112 , V_40 -> V_279 ) ;
if ( V_40 == V_1 -> V_41 . V_42 )
F_184 ( V_1 , V_112 ) ;
if ( V_112 == V_292 - 1 ||
V_112 == V_293 - 1 )
if ( ( V_289 == 0 ) && ( V_288 != 0 ) )
F_194 ( V_1 ) ;
if ( V_112 == V_294 - 1 &&
V_289 != V_288 ) {
V_83 = F_190 ( V_1 , V_40 ) ;
F_179 ( V_1 , V_259 ,
V_83 , V_40 ) ;
}
if ( V_112 == V_295 - 1 &&
V_289 != V_288 ) {
V_83 = F_190 ( V_1 , V_40 ) ;
F_179 ( V_1 , V_261 ,
V_83 , V_40 ) ;
}
}
return V_158 ;
}
static int F_195 ( struct V_282 * V_283 , int V_284 ,
void T_4 * V_285 ,
T_5 * V_286 , T_6 * V_287 )
{
int * V_296 = V_283 -> V_250 ;
int V_3 = * V_296 ;
T_6 V_297 = * V_287 ;
int V_158 = F_192 ( V_283 , V_284 , V_285 , V_286 , V_287 ) ;
if ( V_284 && * V_296 != V_3 ) {
struct V_1 * V_1 = V_283 -> V_291 ;
if ( V_296 != & F_188 ( V_1 , V_47 ) ) {
if ( ! F_196 () ) {
* V_296 = V_3 ;
* V_287 = V_297 ;
return F_197 () ;
}
if ( V_296 == & F_187 ( V_1 , V_47 ) ) {
F_186 ( V_1 ) ;
} else {
struct V_262 * V_40 = V_283 -> V_290 ;
struct V_27 * V_28 =
F_25 ( V_40 , struct V_27 , V_40 ) ;
if ( * V_296 )
F_41 ( V_28 -> V_15 ) ;
F_179 ( V_1 ,
V_258 ,
V_28 -> V_15 -> V_83 ,
V_40 ) ;
}
F_89 () ;
F_194 ( V_1 ) ;
} else
F_179 ( V_1 , V_258 ,
V_278 ,
V_1 -> V_41 . V_42 ) ;
}
return V_158 ;
}
static int F_198 ( struct V_282 * V_283 , int V_284 ,
void T_4 * V_285 ,
T_5 * V_286 , T_6 * V_287 )
{
int * V_296 = V_283 -> V_250 ;
int V_3 = * V_296 ;
int V_158 = F_192 ( V_283 , V_284 , V_285 , V_286 , V_287 ) ;
struct V_1 * V_1 = V_283 -> V_291 ;
if ( V_284 && * V_296 != V_3 )
F_194 ( V_1 ) ;
return V_158 ;
}
static int F_199 ( struct V_1 * V_1 , char * V_298 ,
struct V_262 * V_299 )
{
int V_112 ;
struct V_300 * V_301 ;
char V_302 [ sizeof( L_6 ) + V_137 ] ;
V_301 = F_200 ( & V_303 , sizeof( * V_301 ) , V_29 ) ;
if ( ! V_301 )
goto V_39;
for ( V_112 = 0 ; V_112 < F_201 ( V_301 -> V_304 ) - 1 ; V_112 ++ ) {
V_301 -> V_304 [ V_112 ] . V_250 += ( char * ) V_299 - ( char * ) & V_262 ;
V_301 -> V_304 [ V_112 ] . V_290 = V_299 ;
V_301 -> V_304 [ V_112 ] . V_291 = V_1 ;
}
snprintf ( V_302 , sizeof( V_302 ) , L_7 , V_298 ) ;
V_301 -> V_305 = F_202 ( V_1 , V_302 , V_301 -> V_304 ) ;
if ( ! V_301 -> V_305 )
goto free;
V_299 -> V_43 = V_301 ;
return 0 ;
free:
F_27 ( V_301 ) ;
V_39:
return - V_81 ;
}
static void F_203 ( struct V_262 * V_40 )
{
struct V_300 * V_301 = V_40 -> V_43 ;
if ( V_301 == NULL )
return;
V_40 -> V_43 = NULL ;
F_204 ( V_301 -> V_305 ) ;
F_27 ( V_301 ) ;
}
static void F_20 ( struct V_27 * V_28 )
{
F_205 ( V_28 -> V_15 , V_28 -> V_44 , NULL ) ;
F_199 ( F_14 ( V_28 -> V_15 ) , V_28 -> V_15 -> V_36 ,
& V_28 -> V_40 ) ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_203 ( & V_28 -> V_40 ) ;
F_206 ( V_28 -> V_44 ) ;
}
static T_7 int F_207 ( struct V_1 * V_1 )
{
int V_94 ;
struct V_262 * V_306 , * V_307 ;
#ifdef F_208
struct V_282 * V_308 = V_309 ;
struct V_310 * V_311 ;
#endif
V_94 = - V_206 ;
V_306 = & V_262 ;
V_307 = & V_312 ;
if ( ! F_13 ( V_1 , & V_313 ) ) {
V_306 = F_200 ( V_306 , sizeof( V_262 ) , V_29 ) ;
if ( V_306 == NULL )
goto V_314;
V_307 = F_200 ( V_307 , sizeof( V_312 ) , V_29 ) ;
if ( V_307 == NULL )
goto V_315;
#ifdef F_208
V_308 = F_200 ( V_308 , sizeof( V_309 ) , V_29 ) ;
if ( V_308 == NULL )
goto V_316;
V_308 [ 0 ] . V_250 = & V_306 -> V_250 [ V_317 - 1 ] ;
V_308 [ 0 ] . V_290 = V_306 ;
V_308 [ 0 ] . V_291 = V_1 ;
#endif
}
#ifdef F_208
V_94 = F_199 ( V_1 , L_8 , V_306 ) ;
if ( V_94 < 0 )
goto V_318;
V_94 = F_199 ( V_1 , L_9 , V_307 ) ;
if ( V_94 < 0 )
goto V_319;
V_94 = - V_206 ;
V_311 = F_202 ( V_1 , L_10 , V_308 ) ;
if ( V_311 == NULL )
goto V_320;
V_1 -> V_41 . V_311 = V_311 ;
#endif
V_1 -> V_41 . V_277 = V_306 ;
V_1 -> V_41 . V_42 = V_307 ;
return 0 ;
#ifdef F_208
V_320:
F_203 ( V_307 ) ;
V_319:
F_203 ( V_306 ) ;
V_318:
if ( V_308 != V_309 )
F_27 ( V_308 ) ;
V_316:
#endif
if ( V_307 != & V_312 )
F_27 ( V_307 ) ;
V_315:
if ( V_306 != & V_262 )
F_27 ( V_306 ) ;
V_314:
return V_94 ;
}
static T_8 void F_209 ( struct V_1 * V_1 )
{
#ifdef F_208
struct V_282 * V_308 ;
V_308 = V_1 -> V_41 . V_311 -> V_321 ;
F_204 ( V_1 -> V_41 . V_311 ) ;
F_203 ( V_1 -> V_41 . V_42 ) ;
F_203 ( V_1 -> V_41 . V_277 ) ;
F_27 ( V_308 ) ;
#endif
F_27 ( V_1 -> V_41 . V_42 ) ;
F_27 ( V_1 -> V_41 . V_277 ) ;
}
void T_9 F_210 ( void )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < V_115 ; V_112 ++ )
F_211 ( & V_11 [ V_112 ] ) ;
F_212 ( & V_322 ) ;
F_213 ( V_323 , F_120 ) ;
F_214 ( & V_324 ) ;
F_66 ( V_80 , & V_79 , 0 ) ;
F_215 ( & V_325 ) ;
F_216 ( V_323 , V_74 , F_102 , NULL , NULL ) ;
F_216 ( V_323 , V_70 , F_77 , NULL , NULL ) ;
F_216 ( V_323 , V_326 , NULL , F_157 , NULL ) ;
F_216 ( V_323 , V_327 , F_180 ,
F_183 , NULL ) ;
}
